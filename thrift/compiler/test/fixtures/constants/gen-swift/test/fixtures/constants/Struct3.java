/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

package test.fixtures.constants;

import com.facebook.swift.codec.*;
import com.facebook.swift.codec.ThriftField.Requiredness;
import com.facebook.swift.codec.ThriftField.Recursiveness;
import com.google.common.collect.*;
import java.util.*;
import org.apache.thrift.*;
import org.apache.thrift.async.*;
import org.apache.thrift.meta_data.*;
import org.apache.thrift.server.*;
import org.apache.thrift.transport.*;
import org.apache.thrift.protocol.*;
import org.apache.thrift.meta_data.FieldMetaData;
import org.apache.thrift.meta_data.FieldValueMetaData;
import static com.google.common.base.MoreObjects.toStringHelper;
import static com.google.common.base.MoreObjects.ToStringHelper;

@SwiftGenerated
@ThriftStruct(value="struct3", builder=Struct3.Builder.class)
public final class Struct3 {
    private BitSet __isset_bit_vector = new BitSet();
    
    @ThriftConstructor
    public Struct3(
        @ThriftField(value=1, name="a", requiredness=Requiredness.NONE) final String a,
        @ThriftField(value=2, name="b", requiredness=Requiredness.NONE) final int b,
        @ThriftField(value=3, name="c", requiredness=Requiredness.NONE) final test.fixtures.constants.Struct2 c
    ) {
        this.a = a;
        this.b = b;
        this.c = c;
    }
    
    @ThriftConstructor
    protected Struct3() {
      this.a = null;
      this.b = 0;
      this.c = null;
    }
    
    public static class Builder {
        private final BitSet __optional_isset = new BitSet();
    
        private String a = null;
        private int b = 0;
        private test.fixtures.constants.Struct2 c = null;
    
        @ThriftField(value=1, name="a", requiredness=Requiredness.NONE)
        public Builder setA(String a) {
            this.a = a;
            return this;
        }
    
        public String getA() { return a; }
    
            @ThriftField(value=2, name="b", requiredness=Requiredness.NONE)
        public Builder setB(int b) {
            this.b = b;
            return this;
        }
    
        public int getB() { return b; }
    
            @ThriftField(value=3, name="c", requiredness=Requiredness.NONE)
        public Builder setC(test.fixtures.constants.Struct2 c) {
            this.c = c;
            return this;
        }
    
        public test.fixtures.constants.Struct2 getC() { return c; }
    
        public Builder() { }
        public Builder(Struct3 other) {
            this.a = other.a;
            this.b = other.b;
            this.c = other.c;
        }
    
        @ThriftConstructor
        public Struct3 build() {
            Struct3 result = new Struct3 (
                this.a,
                this.b,
                this.c
            );
            result.__isset_bit_vector.or(__optional_isset);
            return result;
        }
    }
    
    public static final Map<String, Integer> NAMES_TO_IDS = new HashMap();
    public static final Map<Integer, Object> FIELD_METADATA = new HashMap<>();
    private static final TStruct STRUCT_DESC = new TStruct("struct3");
    private final String a;
    public static final int _A = 1;
    private static final TField A_FIELD_DESC = new TField("a", TType.STRING, (short)1);
        private final int b;
    public static final int _B = 2;
    private static final TField B_FIELD_DESC = new TField("b", TType.I32, (short)2);
        private final test.fixtures.constants.Struct2 c;
    public static final int _C = 3;
    private static final TField C_FIELD_DESC = new TField("c", TType.STRUCT, (short)3);
    static {
      NAMES_TO_IDS.put("a", 1);
      FIELD_METADATA.put(1, A_FIELD_DESC);
      NAMES_TO_IDS.put("b", 2);
      FIELD_METADATA.put(2, B_FIELD_DESC);
      NAMES_TO_IDS.put("c", 3);
      FIELD_METADATA.put(3, C_FIELD_DESC);
    }
    
    @ThriftField(value=1, name="a", requiredness=Requiredness.NONE)
    public String getA() { return a; }
        
    /** don't use this method for new code, it's here to make migrating to swift easier */
    @Deprecated
    public boolean fieldIsSetA() {
        return this.a != null;
    }
    
    
    @ThriftField(value=2, name="b", requiredness=Requiredness.NONE)
    public int getB() { return b; }
        
    /** don't use this method for new code, it's here to make migrating to swift easier */
    @Deprecated
    public boolean fieldIsSetB() {
        return __isset_bit_vector.get(_B);
    }
    
    
    @ThriftField(value=3, name="c", requiredness=Requiredness.NONE)
    public test.fixtures.constants.Struct2 getC() { return c; }
        
    /** don't use this method for new code, it's here to make migrating to swift easier */
    @Deprecated
    public boolean fieldIsSetC() {
        return this.c != null;
    }
    
    @Override
    public String toString() {
        ToStringHelper helper = toStringHelper(this);
        helper.add("a", a);
        helper.add("b", b);
        helper.add("c", c);
        return helper.toString();
    }
    
    @Override
    public boolean equals(Object o) {
        if (this == o) {
            return true;
        }
        if (o == null || getClass() != o.getClass()) {
            return false;
        }
    
        Struct3 other = (Struct3)o;
    
        return
            Objects.equals(a, other.a) &&
            Objects.equals(b, other.b) &&
            Objects.equals(c, other.c) &&
            true;
    }
    
    @Override
    public int hashCode() {
        return Arrays.deepHashCode(new Object[] {
            a,
            b,
            c
        });
    }
    
    
      // Currently, the read0 method cannot read metadatamap for JSON styled serialization.
      // Perhaps, it will be implemented in the future!
    public static Struct3 read0(TProtocol oprot) throws TException {
      TField __field;
      oprot.readStructBegin();
      Struct3.Builder builder = new Struct3.Builder();
      while (true) {
        __field = oprot.readFieldBegin();
        if (__field.type == TType.STOP) { break; }
        switch (__field.id) {
        case _A:
          if (__field.type == TType.STRING) {
            String a = oprot.readString();
            builder.setA(a);
          } else {
            TProtocolUtil.skip(oprot, __field.type);
          }
          break;
        case _B:
          if (__field.type == TType.I32) {
            int b = oprot.readI32();
            builder.setB(b);
          } else {
            TProtocolUtil.skip(oprot, __field.type);
          }
          break;
        case _C:
          if (__field.type == TType.STRUCT) {
            test.fixtures.constants.Struct2 c = test.fixtures.constants.Struct2.read0(oprot);
            builder.setC(c);
          } else {
            TProtocolUtil.skip(oprot, __field.type);
          }
          break;
        default:
          TProtocolUtil.skip(oprot, __field.type);
          break;
        }
        oprot.readFieldEnd();
      }
      oprot.readStructEnd();
      return builder.build();
    }
    
    public void write0(TProtocol oprot) throws TException {
      oprot.writeStructBegin(STRUCT_DESC);
      if (this.a != null) {
        oprot.writeFieldBegin(A_FIELD_DESC);
        oprot.writeString(this.a);
        oprot.writeFieldEnd();
      }
      oprot.writeFieldBegin(B_FIELD_DESC);
      oprot.writeI32(this.b);
      oprot.writeFieldEnd();
      if (this.c != null) {
        oprot.writeFieldBegin(C_FIELD_DESC);
        this.c.write0(oprot);
        oprot.writeFieldEnd();
      }
      oprot.writeFieldStop();
      oprot.writeStructEnd();
    }
    
}
