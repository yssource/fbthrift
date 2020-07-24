/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

package test.fixtures.annotation;

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
@ThriftStruct("MyMutableStruct") @com.foo.Enabled 
public final class MyMutableStruct {
    private BitSet __isset_bit_vector = new BitSet();
    
    @ThriftConstructor
    public MyMutableStruct() {
      this.intField = 0L;
      this.stringField = null;
    }
    
    public static class Builder {
        private final BitSet __optional_isset = new BitSet();
    
        private long intField = 0L;
        private String stringField = null;
    
        @ThriftField(value=1, name="intField", requiredness=Requiredness.NONE)
        public Builder setIntField(long intField) {
            this.intField = intField;
            return this;
        }
    
        public long getIntField() { return intField; }
    
            @ThriftField(value=2, name="stringField", requiredness=Requiredness.NONE)
        public Builder setStringField(String stringField) {
            this.stringField = stringField;
            return this;
        }
    
        public String getStringField() { return stringField; }
    
        public Builder() { }
        public Builder(MyMutableStruct other) {
            this.intField = other.intField;
            this.stringField = other.stringField;
        }
    
        @ThriftConstructor
        public MyMutableStruct build() {
            MyMutableStruct result = new MyMutableStruct();
            result.intField = this.intField;
            result.stringField = this.stringField;
            result.__isset_bit_vector.or(__optional_isset);
            return result;
        }
    }
    
    public static final Map<String, Integer> NAMES_TO_IDS = new HashMap();
    public static final Map<Integer, Object> FIELD_METADATA = new HashMap<>();
    private static final TStruct STRUCT_DESC = new TStruct("MyMutableStruct");
    private long intField;
    public static final int _INTFIELD = 1;
    private static final TField INT_FIELD_FIELD_DESC = new TField("intField", TType.I64, (short)1);
    private String stringField;
    public static final int _STRINGFIELD = 2;
    private static final TField STRING_FIELD_FIELD_DESC = new TField("stringField", TType.STRING, (short)2);
static {
      NAMES_TO_IDS.put("intField", 1);
      FIELD_METADATA.put(1, INT_FIELD_FIELD_DESC);
      NAMES_TO_IDS.put("stringField", 2);
      FIELD_METADATA.put(2, STRING_FIELD_FIELD_DESC);
    }
    
    @ThriftField(value=1, name="intField", requiredness=Requiredness.NONE)
    public long getIntField() { return intField; }
    
    @ThriftField
    public MyMutableStruct setIntField(long intField) {
        this.intField = intField;
        return this;
    }
        
    /** don't use this method for new code, it's here to make migrating to swift easier */
    @Deprecated
    public boolean fieldIsSetIntField() {
        return __isset_bit_vector.get(_INTFIELD);
    }
    /** don't use this method for new code, it's here to make migrating to swift easier */
    @Deprecated
    public void unsetIntField() {
        __isset_bit_vector.clear(_INTFIELD);
    }
    
    @ThriftField(value=2, name="stringField", requiredness=Requiredness.NONE)
    public String getStringField() { return stringField; }
    
    @ThriftField
    public MyMutableStruct setStringField(String stringField) {
        this.stringField = stringField;
        return this;
    }
        
    /** don't use this method for new code, it's here to make migrating to swift easier */
    @Deprecated
    public boolean fieldIsSetStringField() {
        return this.stringField != null;
    }
    /** don't use this method for new code, it's here to make migrating to swift easier */
    @Deprecated
    public void unsetStringField() {
        this.stringField = null;
    }
    @Override
    public String toString() {
        ToStringHelper helper = toStringHelper(this);
        helper.add("intField", intField);
        helper.add("stringField", stringField);
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
    
        MyMutableStruct other = (MyMutableStruct)o;
    
        return
            Objects.equals(intField, other.intField) &&
            Objects.equals(stringField, other.stringField) &&
            true;
    }
    
    @Override
    public int hashCode() {
        return Arrays.deepHashCode(new Object[] {
            intField,
            stringField
        });
    }
    
    
      // Currently, the read0 method cannot read metadatamap for JSON styled serialization.
      // Perhaps, it will be implemented in the future!
    public static MyMutableStruct read0(TProtocol oprot) throws TException {
      TField __field;
      oprot.readStructBegin();
      MyMutableStruct.Builder builder = new MyMutableStruct.Builder();
      while (true) {
        __field = oprot.readFieldBegin();
        if (__field.type == TType.STOP) { break; }
        switch (__field.id) {
        case _INTFIELD:
          if (__field.type == TType.I64) {
            long intField = oprot.readI64();
            builder.setIntField(intField);
          } else {
            TProtocolUtil.skip(oprot, __field.type);
          }
          break;
        case _STRINGFIELD:
          if (__field.type == TType.STRING) {
            String stringField = oprot.readString();
            builder.setStringField(stringField);
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
      oprot.writeFieldBegin(INT_FIELD_FIELD_DESC);
      oprot.writeI64(this.intField);
      oprot.writeFieldEnd();
      if (this.stringField != null) {
        oprot.writeFieldBegin(STRING_FIELD_FIELD_DESC);
        oprot.writeString(this.stringField);
        oprot.writeFieldEnd();
      }
      oprot.writeFieldStop();
      oprot.writeStructEnd();
    }
    
}
