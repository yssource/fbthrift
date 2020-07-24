/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

package test.fixtures.complex_struct;

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
@ThriftStruct(value="MyStructMapFloatThrowExp", builder=MyStructMapFloatThrowExp.Builder.class)
public final class MyStructMapFloatThrowExp {
    private BitSet __isset_bit_vector = new BitSet();
    
    @ThriftConstructor
    public MyStructMapFloatThrowExp(
        @ThriftField(value=1, name="myLongField", requiredness=Requiredness.NONE) final long myLongField,
        @ThriftField(value=2, name="mapListOfFloats", requiredness=Requiredness.NONE) final Map<Integer, List<List<Float>>> mapListOfFloats
    ) {
        this.myLongField = myLongField;
        this.mapListOfFloats = mapListOfFloats;
    }
    
    @ThriftConstructor
    protected MyStructMapFloatThrowExp() {
      this.myLongField = 0L;
      this.mapListOfFloats = null;
    }
    
    public static class Builder {
        private final BitSet __optional_isset = new BitSet();
    
        private long myLongField = 0L;
        private Map<Integer, List<List<Float>>> mapListOfFloats = null;
    
        @ThriftField(value=1, name="myLongField", requiredness=Requiredness.NONE)
        public Builder setMyLongField(long myLongField) {
            this.myLongField = myLongField;
            return this;
        }
    
        public long getMyLongField() { return myLongField; }
    
            @ThriftField(value=2, name="mapListOfFloats", requiredness=Requiredness.NONE)
        public Builder setMapListOfFloats(Map<Integer, List<List<Float>>> mapListOfFloats) {
            this.mapListOfFloats = mapListOfFloats;
            return this;
        }
    
        public Map<Integer, List<List<Float>>> getMapListOfFloats() { return mapListOfFloats; }
    
        public Builder() { }
        public Builder(MyStructMapFloatThrowExp other) {
            this.myLongField = other.myLongField;
            this.mapListOfFloats = other.mapListOfFloats;
        }
    
        @ThriftConstructor
        public MyStructMapFloatThrowExp build() {
            MyStructMapFloatThrowExp result = new MyStructMapFloatThrowExp (
                this.myLongField,
                this.mapListOfFloats
            );
            result.__isset_bit_vector.or(__optional_isset);
            return result;
        }
    }
    
    public static final Map<String, Integer> NAMES_TO_IDS = new HashMap();
    public static final Map<Integer, Object> FIELD_METADATA = new HashMap<>();
    private static final TStruct STRUCT_DESC = new TStruct("MyStructMapFloatThrowExp");
    private final long myLongField;
    public static final int _MYLONGFIELD = 1;
    private static final TField MY_LONG_FIELD_FIELD_DESC = new TField("myLongField", TType.I64, (short)1);
        private final Map<Integer, List<List<Float>>> mapListOfFloats;
    public static final int _MAPLISTOFFLOATS = 2;
    private static final TField MAP_LIST_OF_FLOATS_FIELD_DESC = new TField("mapListOfFloats", TType.MAP, (short)2);
    static {
      NAMES_TO_IDS.put("myLongField", 1);
      FIELD_METADATA.put(1, MY_LONG_FIELD_FIELD_DESC);
      NAMES_TO_IDS.put("mapListOfFloats", 2);
      FIELD_METADATA.put(2, MAP_LIST_OF_FLOATS_FIELD_DESC);
    }
    
    @ThriftField(value=1, name="myLongField", requiredness=Requiredness.NONE)
    public long getMyLongField() { return myLongField; }
        
    /** don't use this method for new code, it's here to make migrating to swift easier */
    @Deprecated
    public boolean fieldIsSetMyLongField() {
        return __isset_bit_vector.get(_MYLONGFIELD);
    }
    
    
    @ThriftField(value=2, name="mapListOfFloats", requiredness=Requiredness.NONE)
    public Map<Integer, List<List<Float>>> getMapListOfFloats() { return mapListOfFloats; }
        
    /** don't use this method for new code, it's here to make migrating to swift easier */
    @Deprecated
    public boolean fieldIsSetMapListOfFloats() {
        return this.mapListOfFloats != null;
    }
    
    @Override
    public String toString() {
        ToStringHelper helper = toStringHelper(this);
        helper.add("myLongField", myLongField);
        helper.add("mapListOfFloats", mapListOfFloats);
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
    
        MyStructMapFloatThrowExp other = (MyStructMapFloatThrowExp)o;
    
        return
            Objects.equals(myLongField, other.myLongField) &&
            Objects.equals(mapListOfFloats, other.mapListOfFloats) &&
            true;
    }
    
    @Override
    public int hashCode() {
        return Arrays.deepHashCode(new Object[] {
            myLongField,
            mapListOfFloats
        });
    }
    
    
      // Currently, the read0 method cannot read metadatamap for JSON styled serialization.
      // Perhaps, it will be implemented in the future!
    public static MyStructMapFloatThrowExp read0(TProtocol oprot) throws TException {
      TField __field;
      oprot.readStructBegin();
      MyStructMapFloatThrowExp.Builder builder = new MyStructMapFloatThrowExp.Builder();
      while (true) {
        __field = oprot.readFieldBegin();
        if (__field.type == TType.STOP) { break; }
        switch (__field.id) {
        case _MYLONGFIELD:
          if (__field.type == TType.I64) {
            long myLongField = oprot.readI64();
            builder.setMyLongField(myLongField);
          } else {
            TProtocolUtil.skip(oprot, __field.type);
          }
          break;
        case _MAPLISTOFFLOATS:
          if (__field.type == TType.MAP) {
            Map<Integer, List<List<Float>>> mapListOfFloats;
            {
            TMap _map = oprot.readMapBegin();
            if (_map.size < 0) {
                throw new TException("Using an unsupported Map, size is less than zero.");
            }
            mapListOfFloats = new HashMap<Integer, List<List<Float>>>(_map.size);
            for (int _i = 0; _i < _map.size; _i++) {
                
                int _key1 = oprot.readI32();

                List<List<Float>> _value1;
                            {
                            TList _list1 = oprot.readListBegin();
                            if (_list1.size < 0) {
                                throw new TException("Using an unsupported Map, size is less than zero.");
                            }
                            _value1 = new ArrayList<List<Float>>(_list1.size);
                            for (int _i1 = 0; _i1 < _list1.size; _i1++) {
                                
                                List<Float> _value2;
            {
            TList _list2 = oprot.readListBegin();
            if (_list2.size < 0) {
                throw new TException("Using an unsupported Map, size is less than zero.");
            }
            _value2 = new ArrayList<Float>(_list2.size);
            for (int _i2 = 0; _i2 < _list2.size; _i2++) {
                
                
                float _value3 = oprot.readFloat();
                
                
                _value2.add(_value3);
                
            }
            oprot.readListEnd();
            }

                                
                                _value1.add(_value2);
                                
                            }
                            oprot.readListEnd();
                            }
                                mapListOfFloats.put(_key1, _value1);
            }
            }
            oprot.readMapEnd();
            builder.setMapListOfFloats(mapListOfFloats);
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
      oprot.writeFieldBegin(MY_LONG_FIELD_FIELD_DESC);
      oprot.writeI64(this.myLongField);
      oprot.writeFieldEnd();
      if (this.mapListOfFloats != null) {
        oprot.writeFieldBegin(MAP_LIST_OF_FLOATS_FIELD_DESC);
        Map<Integer, List<List<Float>>> _iter0 = this.mapListOfFloats;
        oprot.writeMapBegin(new TMap(TType.I32, TType.LIST, _iter0.size()));
        for (Map.Entry<Integer, List<List<Float>>> _iter1 : _iter0.entrySet()) {
          oprot.writeI32(_iter1.getKey());
          
          oprot.writeListBegin(new TList(TType.LIST, _iter1.getValue().size()));
        for (List<Float> _iter2 : _iter1.getValue()) {
          oprot.writeListBegin(new TList(TType.FLOAT, _iter2.size()));
        for (float _iter3 : _iter2) {
          oprot.writeFloat(_iter3);
        }
        oprot.writeListEnd();
        }
        oprot.writeListEnd();
        }
        oprot.writeMapEnd();
        oprot.writeFieldEnd();
      }
      oprot.writeFieldStop();
      oprot.writeStructEnd();
    }
    
}
