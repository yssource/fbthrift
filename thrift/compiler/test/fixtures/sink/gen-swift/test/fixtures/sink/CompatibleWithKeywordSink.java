/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

package test.fixtures.sink;

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
@ThriftStruct(value="CompatibleWithKeywordSink", builder=CompatibleWithKeywordSink.Builder.class)
public final class CompatibleWithKeywordSink {
    private BitSet __isset_bit_vector = new BitSet();
    
    @ThriftConstructor
    public CompatibleWithKeywordSink(
        @ThriftField(value=1, name="sink", requiredness=Requiredness.NONE) final String sink
    ) {
        this.sink = sink;
    }
    
    @ThriftConstructor
    protected CompatibleWithKeywordSink() {
      this.sink = null;
    }
    
    public static class Builder {
        private final BitSet __optional_isset = new BitSet();
    
        private String sink = null;
    
        @ThriftField(value=1, name="sink", requiredness=Requiredness.NONE)
        public Builder setSink(String sink) {
            this.sink = sink;
            return this;
        }
    
        public String getSink() { return sink; }
    
        public Builder() { }
        public Builder(CompatibleWithKeywordSink other) {
            this.sink = other.sink;
        }
    
        @ThriftConstructor
        public CompatibleWithKeywordSink build() {
            CompatibleWithKeywordSink result = new CompatibleWithKeywordSink (
                this.sink
            );
            result.__isset_bit_vector.or(__optional_isset);
            return result;
        }
    }
    
    public static final Map<String, Integer> NAMES_TO_IDS = new HashMap();
    public static final Map<Integer, Object> FIELD_METADATA = new HashMap<>();
    private static final TStruct STRUCT_DESC = new TStruct("CompatibleWithKeywordSink");
    private final String sink;
    public static final int _SINK = 1;
    private static final TField SINK_FIELD_DESC = new TField("sink", TType.STRING, (short)1);
    static {
      NAMES_TO_IDS.put("sink", 1);
      FIELD_METADATA.put(1, SINK_FIELD_DESC);
    }
    
    @ThriftField(value=1, name="sink", requiredness=Requiredness.NONE)
    public String getSink() { return sink; }
        
    /** don't use this method for new code, it's here to make migrating to swift easier */
    @Deprecated
    public boolean fieldIsSetSink() {
        return this.sink != null;
    }
    
    @Override
    public String toString() {
        ToStringHelper helper = toStringHelper(this);
        helper.add("sink", sink);
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
    
        CompatibleWithKeywordSink other = (CompatibleWithKeywordSink)o;
    
        return
            Objects.equals(sink, other.sink) &&
            true;
    }
    
    @Override
    public int hashCode() {
        return Arrays.deepHashCode(new Object[] {
            sink
        });
    }
    
    
      // Currently, the read0 method cannot read metadatamap for JSON styled serialization.
      // Perhaps, it will be implemented in the future!
    public static CompatibleWithKeywordSink read0(TProtocol oprot) throws TException {
      TField __field;
      oprot.readStructBegin();
      CompatibleWithKeywordSink.Builder builder = new CompatibleWithKeywordSink.Builder();
      while (true) {
        __field = oprot.readFieldBegin();
        if (__field.type == TType.STOP) { break; }
        switch (__field.id) {
        case _SINK:
          if (__field.type == TType.STRING) {
            String sink = oprot.readString();
            builder.setSink(sink);
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
      if (this.sink != null) {
        oprot.writeFieldBegin(SINK_FIELD_DESC);
        oprot.writeString(this.sink);
        oprot.writeFieldEnd();
      }
      oprot.writeFieldStop();
      oprot.writeStructEnd();
    }
    
}
