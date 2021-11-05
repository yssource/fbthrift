/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <folly/Range.h>
#include <folly/portability/GTest.h>
#include <thrift/lib/cpp2/hash/DeterministicHash.h>
#include <thrift/lib/cpp2/protocol/test/gen-cpp2/Module_types_custom_protocol.h>
#include <thrift/lib/cpp2/test/DebugHasher.h>

namespace apache {
namespace thrift {
namespace hash {

namespace {

constexpr folly::StringPiece kOneOfEachExpected =
    // struct OneOfEach {
    "["
    // 5: i64 myI64 = 5000000017;
    "[10,5,5000000017],"
    // 11: SubStruct myStruct;
    "[12,11,[[10,3,17],[11,12,6foobar]]],"
    // 12: SubUnion myUnion = kSubUnion;
    "[12,12,[[11,209,8glorious]]],"
    // 8: map<string, i64> myMap = {"foo": 13, "bar": 17, "baz": 19};
    "[13,8,11,10,3,[[3bar,17],[3baz,19],[3foo,13]]],"
    // 10: set<string> mySet = ["foo", "bar", "baz"];
    "[14,10,11,3,[[3bar],[3baz],[3foo]]],"
    // 9: list<string> myList = ["foo", "bar", "baz"];
    "[15,9,11,3,3foo,3bar,3baz],"
    // 7: float myFloat = 5.25;
    "[19,7,5.25],"
    // 1: bool myBool = 1;
    "[2,1,1],"
    // 2: byte myByte = 17;
    "[3,2,17],"
    // 6: double myDouble = 5.25;
    "[4,6,5.25],"
    // 3: i16 myI16 = 1017;
    "[6,3,1017],"
    // 4: i32 myI32 = 100017;
    "[8,4,100017]"
    "]"; // }

} // namespace

template <typename Mode>
class DeterministicProtocolTest : public ::testing::Test {
 public:
  template <typename Struct>
  auto hash(const Struct& input) {
    return Mode::hash(input);
  }
};

struct HasherMode {
  template <typename Struct>
  static auto hash(const Struct& input) {
    return deterministic_hash<DebugHasher>(input).getResult();
  }
};

struct GeneratorMode {
  template <typename Struct>
  static auto hash(const Struct& input) {
    auto generator = [] { return DebugHasher{}; };
    return deterministic_hash(input, generator).getResult();
  }
};

using Modes = ::testing::Types<HasherMode, GeneratorMode>;

TYPED_TEST_CASE(DeterministicProtocolTest, Modes);

TYPED_TEST(DeterministicProtocolTest, checkOneOfEach) {
  const test::OneOfEach input;
  const auto result = this->hash(input);
  EXPECT_EQ(result, kOneOfEachExpected);
}

TYPED_TEST(DeterministicProtocolTest, checkOptional) {
  test::OptionalFields input;
  const auto result = this->hash(input);
  input.f1_ref() = {};
  EXPECT_NE(result, this->hash(input));
  input.f1_ref().reset();
  EXPECT_EQ(result, this->hash(input));
  input.f2_ref() = {};
  EXPECT_NE(result, this->hash(input));
  input.f2_ref().reset();
  EXPECT_EQ(result, this->hash(input));
  input.f3_ref() = {};
  EXPECT_NE(result, this->hash(input));
  input.f3_ref().reset();
  EXPECT_EQ(result, this->hash(input));
}

TYPED_TEST(DeterministicProtocolTest, checkOrderDeterminism) {
  const test::OrderedFields orderedFields;
  const auto orderedResult = this->hash(orderedFields);
  const test::UnorderedFields unorderedFields;
  const auto unorderedResult = this->hash(unorderedFields);
  EXPECT_EQ(orderedResult, unorderedResult);
}

} // namespace hash
} // namespace thrift
} // namespace apache