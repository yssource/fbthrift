/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
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

#pragma once

#include <thrift/compiler/generate/t_generator.h>
#include <thrift/compiler/whisker/object.h>
#include <thrift/compiler/whisker/render.h>

#include <thrift/compiler/ast/t_const.h>
#include <thrift/compiler/ast/t_const_value.h>
#include <thrift/compiler/ast/t_container.h>
#include <thrift/compiler/ast/t_enum.h>
#include <thrift/compiler/ast/t_enum_value.h>
#include <thrift/compiler/ast/t_exception.h>
#include <thrift/compiler/ast/t_field.h>
#include <thrift/compiler/ast/t_function.h>
#include <thrift/compiler/ast/t_include.h>
#include <thrift/compiler/ast/t_interaction.h>
#include <thrift/compiler/ast/t_interface.h>
#include <thrift/compiler/ast/t_list.h>
#include <thrift/compiler/ast/t_map.h>
#include <thrift/compiler/ast/t_named.h>
#include <thrift/compiler/ast/t_node.h>
#include <thrift/compiler/ast/t_package.h>
#include <thrift/compiler/ast/t_paramlist.h>
#include <thrift/compiler/ast/t_primitive_type.h>
#include <thrift/compiler/ast/t_program.h>
#include <thrift/compiler/ast/t_service.h>
#include <thrift/compiler/ast/t_set.h>
#include <thrift/compiler/ast/t_sink.h>
#include <thrift/compiler/ast/t_stream.h>
#include <thrift/compiler/ast/t_struct.h>
#include <thrift/compiler/ast/t_structured.h>
#include <thrift/compiler/ast/t_throws.h>
#include <thrift/compiler/ast/t_type.h>
#include <thrift/compiler/ast/t_typedef.h>
#include <thrift/compiler/ast/t_union.h>
#include <thrift/compiler/whisker/dsl.h>

#include <filesystem>
#include <functional>
#include <map>
#include <string>
#include <string_view>

namespace apache::thrift::compiler {

/**
 * A template-based code generator that uses Whisker as the templating engine.
 */
class t_whisker_generator : public t_generator {
 public:
  using t_generator::t_generator;

 protected:
  /**
   * The subdirectory within templates/ where the Whisker source files reside.
   * This is primarily used to resolve partial application within template
   * files.
   */
  virtual std::string template_prefix() const = 0;

  /**
   * The global context used for whisker rendering. This function can be used,
   * for example, to add globally available helper functions.
   */
  virtual whisker::map::raw globals() const { return {}; }

  // See whisker::render_options
  struct strictness_options {
    bool boolean_conditional = true;
    bool printable_types = true;
    bool undefined_variables = true;
  };
  /**
   * The strictness levels for various levels of diagnostics that Whisker's
   * render provides. The default values are the strictest settings (highly
   * recommended).
   */
  virtual strictness_options strictness() const { return strictness_options(); }

  using templates_map = std::map<std::string, std::string, std::less<>>;
  /**
   * Creates a mapping from Whisker source file paths within templates/ to
   * their text (source) content.
   *
   * This mapping is used to resolve the source code for the root Whisker
   * source file used by this renderer, as well as any partial applications
   * seen during rendering.
   */
  static templates_map create_templates_by_path();

  /**
   * Returns the rendered output of a Whisker template source file evaluated
   * with the provided context object.
   *
   * Throws:
   *   - std::runtime_error if rendering fails
   */
  std::string render(
      std::string_view template_file, const whisker::object& context);

  /**
   * Writes some text output at the provided file path, and then records it as
   * a generated output artifact.
   *
   * A newline character is automatically appended to the end of the file if
   * the provided text does not already do so.
   *
   * Throws:
   *   - std::runtime_error if IO fails
   */
  void write_to_file(
      const std::filesystem::path& output_file, std::string_view data);

  /**
   * Writes the rendered output of a Whisker template source file evaluated
   * with the provided context object. The output path is recorded as a
   * generated artifact.
   *
   * Throws:
   *   - std::runtime_error if rendering fails
   */
  void render_to_file(
      const std::filesystem::path& output_file,
      std::string_view template_file,
      const whisker::object& context);

  // Whisker-based code generators are designed to work directly against the
  // Thrift AST node types (t_<node_type> classes). This is different from the
  // mstch-based code generators which have an additional conversion layer from
  // the AST node types → mstch::node.
  //
  // In Whisker, passing around the AST nodes (C++ objects) is achieved using
  // whisker::native_handle. Whisker templates cannot directly interact with
  // native_handle objects.
  //
  // The make_prototype_for_<node_type>() family of functions allow
  // prototype-based programming by associating a prototype with AST nodes. When
  // a property access happens in Whisker templates, and the target is a
  // whisker::native_handle, the lookup is forwarded to its prototype.
  //
  // This is modeled after JavaScript's prototype chains:
  //   https://developer.mozilla.org/en-US/docs/Learn_web_development/Extensions/Advanced_JavaScript_objects/Object_prototypes
  //
  // For example:
  //
  //   make_prototype_for_named() may expose a property, `name`, which
  //   corresponds to `const std::string& t_named::name()` member function in
  //   C++.
  //
  //   In Whisker code, this property can be accessed like so:
  //     {{ program_node.name }}
  //     {{ struct_node.name }}
  //     {{ <any node deriving from t_named in C++>.name }}
  //
  // By default, this generator will provide the basic functions defined in the
  // AST node classes. Derived generators may override any overload of
  // make_prototype_for_<node_type>(...) to add new functions to its
  // library.

 protected:
  template <typename T = void>
  using prototype = whisker::prototype<T>;
  template <typename T = void>
  using prototype_ptr = whisker::prototype_ptr<T>;
  using prototype_database = whisker::prototype_database;

  /**
   * Registers the `make_prototype_for_*` functions with the prototype database.
   *
   * A derived generator may override the `define_additional_prototype` function
   * to add new prototypes.
   */
  void define_prototypes(prototype_database&) const;
  virtual void define_additional_prototypes(prototype_database&) const {}

  // WARNING: the order of the functions below match the order in which they are
  // called — base classes first, derived classes last.
  //
  // When defining the prototype for a type, the proto of a type that is later
  // in the order will not be available.

  virtual prototype<t_node>::ptr make_prototype_for_node(
      const prototype_database&) const;

  virtual prototype<t_named>::ptr make_prototype_for_named(
      const prototype_database&) const;

  virtual prototype<t_type>::ptr make_prototype_for_type(
      const prototype_database&) const;

  virtual prototype<t_typedef>::ptr make_prototype_for_typedef(
      const prototype_database&) const;

  virtual prototype<t_structured>::ptr make_prototype_for_structured(
      const prototype_database&) const;

  virtual prototype<t_struct>::ptr make_prototype_for_struct(
      const prototype_database&) const;

  virtual prototype<t_paramlist>::ptr make_prototype_for_paramlist(
      const prototype_database&) const;

  virtual prototype<t_throws>::ptr make_prototype_for_throws(
      const prototype_database&) const;

  virtual prototype<t_union>::ptr make_prototype_for_union(
      const prototype_database&) const;

  virtual prototype<t_exception>::ptr make_prototype_for_exception(
      const prototype_database&) const;

  virtual prototype<t_primitive_type>::ptr make_prototype_for_primitive_type(
      const prototype_database&) const;

  virtual prototype<t_field>::ptr make_prototype_for_field(
      const prototype_database&) const;

  virtual prototype<t_enum>::ptr make_prototype_for_enum(
      const prototype_database&) const;

  virtual prototype<t_enum_value>::ptr make_prototype_for_enum_value(
      const prototype_database&) const;

  virtual prototype<t_const>::ptr make_prototype_for_const(
      const prototype_database&) const;

  virtual prototype<t_const_value>::ptr make_prototype_for_const_value(
      const prototype_database&) const;

  virtual prototype<t_container>::ptr make_prototype_for_container(
      const prototype_database&) const;

  virtual prototype<t_map>::ptr make_prototype_for_map(
      const prototype_database&) const;

  virtual prototype<t_set>::ptr make_prototype_for_set(
      const prototype_database&) const;

  virtual prototype<t_list>::ptr make_prototype_for_list(
      const prototype_database&) const;

  virtual prototype<t_program>::ptr make_prototype_for_program(
      const prototype_database&) const;

  virtual prototype<t_package>::ptr make_prototype_for_package(
      const prototype_database&) const;

  virtual prototype<t_include>::ptr make_prototype_for_include(
      const prototype_database&) const;

  virtual prototype<t_sink>::ptr make_prototype_for_sink(
      const prototype_database&) const;

  virtual prototype<t_stream>::ptr make_prototype_for_stream(
      const prototype_database&) const;

  virtual prototype<t_function>::ptr make_prototype_for_function(
      const prototype_database&) const;

  virtual prototype<t_interface>::ptr make_prototype_for_interface(
      const prototype_database&) const;

  virtual prototype<t_service>::ptr make_prototype_for_service(
      const prototype_database&) const;

  virtual prototype<t_interaction>::ptr make_prototype_for_interaction(
      const prototype_database&) const;

  // This list represents the polymorphic class hierarchy of the Thrift's AST.
  // It does not need to be a complete representation but the subset that is
  // specified here must be a correct hierarchy (enforced by the compiler).
  //
  // Each `t_{node_type}` has a corresponding `h_{node}` alias which a
  // polymorphic_native_handle describing its polymorphic hierarchy
  // (subclasses).
  template <typename... Cases>
  using make_handle = whisker::dsl::make_polymorphic_native_handle<Cases...>;

  using h_interaction = make_handle<t_interaction>;
  using h_service = make_handle<t_service>;
  using h_interface = make_handle<t_interface, h_interaction, h_service>;

  using h_function = make_handle<t_function>;
  using h_stream = make_handle<t_stream>;
  using h_sink = make_handle<t_sink>;
  using h_include = make_handle<t_include>;
  using h_package = make_handle<t_package>;

  using h_program = make_handle<t_program>;

  using h_list = make_handle<t_list>;
  using h_set = make_handle<t_set>;
  using h_map = make_handle<t_map>;
  using h_container = make_handle<t_container, h_set, h_list, h_map>;

  using h_const = make_handle<t_const>;
  using h_const_value = whisker::native_handle<t_const_value>;
  using h_enum = make_handle<t_enum>;
  using h_enum_value = make_handle<t_enum_value>;
  using h_field = make_handle<t_field>;
  using h_primitive_type = make_handle<t_primitive_type>;

  using h_exception = make_handle<t_exception>;
  using h_union = make_handle<t_union>;
  using h_throws = make_handle<t_throws>;
  using h_paramlist = make_handle<t_paramlist>;
  using h_struct = make_handle<t_struct>;
  using h_structured = make_handle<
      t_structured,
      h_exception,
      h_paramlist,
      h_struct,
      h_throws,
      h_union>;
  using h_typedef = make_handle<t_typedef>;
  using h_type = make_handle<
      t_type,
      h_primitive_type,
      h_enum,
      h_container,
      h_structured,
      h_typedef,
      h_interface>;

  using h_named = make_handle<
      t_named,
      h_const,
      h_enum_value,
      h_field,
      h_function,
      h_type,
      h_program>;
  using h_node = make_handle<t_node, h_named>;

  // The `mem_fn` family of functions below are intended to create properties in
  // `dsl::make_prototype`. These helpers make it easy to map member functions
  // of `t_*` AST nodes to a property returning whisker::object.

  /**
   * Marshals any whisker-compatible object directly.
   */
  template <
      typename R,
      typename Self,
      std::enable_if_t<whisker::is_any_object_type<std::decay_t<R>>>* = nullptr>
  static auto mem_fn(R (Self::*function)() const) {
    return [function](const Self& self) -> whisker::object {
      return whisker::object(std::decay_t<R>((self.*function)()));
    };
  }
  // Special case for std::string_view, which is *not* a whisker-compatible
  // object but we can copy it into std::string.
  template <typename Self>
  static auto mem_fn(std::string_view (Self::*function)() const) {
    return [function](const Self& self) -> whisker::object {
      return whisker::object(whisker::string((self.*function)()));
    };
  }

  /**
   * Marshals any `t_*` AST node with the provided prototype.
   */
  template <
      typename R,
      typename Self,
      std::enable_if_t<std::is_base_of_v<t_node, R>>* = nullptr>
  static auto mem_fn(
      R* (Self::*function)() const, prototype_ptr<std::decay_t<R>> prototype) {
    return [function,
            proto = std::move(prototype)](const Self& self) -> whisker::object {
      const std::decay_t<R>* ptr = (self.*function)();
      return ptr == nullptr
          ? whisker::make::null
          : whisker::object(whisker::native_handle<std::decay_t<R>>(
                whisker::manage_as_static(*ptr), proto));
    };
  }
  template <
      typename R,
      typename Self,
      std::enable_if_t<std::is_base_of_v<t_node, R>>* = nullptr>
  static auto mem_fn(
      R& (Self::*function)() const, prototype_ptr<std::decay_t<R>> prototype) {
    return [function, proto = std::move(prototype)](const Self& self) {
      return whisker::native_handle<std::decay_t<R>>(
          whisker::manage_as_static((self.*function)()), proto);
    };
  }

  /**
   * Marshals a member function returning node_list_view<T> to a property that
   * produces whisker::array.
   *
   * The provided prototype is attached to each node in the list.
   */
  template <typename T, typename Self>
  static auto mem_fn(
      node_list_view<const T> (Self::*function)() const,
      prototype_ptr<T> prototype) {
    return [function, proto = std::move(prototype)](const Self& self) {
      node_list_view<const T> nodes = (self.*function)();
      whisker::array::raw refs;
      refs.reserve(nodes.size());
      for (const T& ref : nodes) {
        refs.emplace_back(whisker::make::native_handle(
            whisker::manage_as_static(ref), proto));
      }
      return whisker::make::array(refs);
    };
  }

  /**
   * Marshals a member function returning std::vector<T*> to a property that
   * produces whisker::array.
   *
   * The provided prototype is attached to each node in the list.
   *
   * The node_list_view<T> variant should be preferred where possible. However,
   * some existing nodes still use this legacy approach.
   */
  template <typename T, typename Self>
  static auto mem_fn(
      const std::vector<T*>& (Self::*function)() const,
      prototype_ptr<T> prototype) {
    return [function, proto = std::move(prototype)](const Self& self) {
      const std::vector<T*>& nodes = (self.*function)();
      whisker::array::raw refs;
      refs.reserve(nodes.size());
      for (const T* ref : nodes) {
        refs.emplace_back(whisker::make::native_handle(
            whisker::manage_as_static(*ref), proto));
      }
      return whisker::make::array(std::move(refs));
    };
  }

  bool has_compiler_option(std::string_view name) const {
    return compiler_options_.find(name) != compiler_options_.end();
  }
  std::optional<std::string_view> get_compiler_option(
      std::string_view name) const {
    if (auto option = compiler_options_.find(name);
        option != compiler_options_.end()) {
      return std::string_view{option->second};
    }
    return std::nullopt;
  }

  void process_options(
      const std::map<std::string, std::string>& options) override {
    compiler_options_ = {options.begin(), options.end()};
  }

  using compiler_options_map = std::map<std::string, std::string, std::less<>>;
  const compiler_options_map& compiler_options() const {
    return compiler_options_;
  }

  /**
   * Returns the source manager associated with parsing the Thrift AST.
   */
  const source_manager& source_mgr() const noexcept { return source_mgr_; }
  /**
   * Sets the output directory (`gen-*`).
   */
  void set_output_base_directory(std::string directory) noexcept {
    out_dir_base_ = std::move(directory);
  }

  struct cached_render_state {
    whisker::diagnostics_engine diagnostic_engine;
    std::shared_ptr<whisker::source_resolver> source_resolver;
    whisker::render_options render_options;
    std::unique_ptr<prototype_database> prototypes;
  };
  cached_render_state& render_state();

 private:
  std::optional<cached_render_state> cached_render_state_;
  compiler_options_map compiler_options_;

  // whisker::source_resolver implementation
  class whisker_source_parser;
};

} // namespace apache::thrift::compiler
