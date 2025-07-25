/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

package test.fixtures.adapter;

import com.facebook.swift.codec.*;
import com.facebook.swift.codec.ThriftField.Requiredness;
import com.facebook.swift.codec.ThriftField.Recursiveness;
import com.google.common.collect.*;
import java.util.*;
import javax.annotation.Nullable;
import org.apache.thrift.*;
import org.apache.thrift.TException;
import org.apache.thrift.transport.*;
import org.apache.thrift.protocol.*;
import org.apache.thrift.protocol.TProtocol;
import static com.google.common.base.MoreObjects.toStringHelper;
import static com.google.common.base.MoreObjects.ToStringHelper;

@SwiftGenerated
@com.facebook.swift.codec.ThriftStruct(value="CircularAdaptee", builder=CircularAdaptee.Builder.class)
public final class CircularAdaptee implements com.facebook.thrift.payload.ThriftSerializable {
    @ThriftConstructor
    public CircularAdaptee(
        @com.facebook.swift.codec.ThriftField(value=1, name="field", requiredness=Requiredness.NONE) final test.fixtures.adapter.CircularStruct field
    ) {
        this.field = field;
    }
    
    @ThriftConstructor
    protected CircularAdaptee() {
      this.field = null;
    }

    public static Builder builder() {
      return new Builder();
    }

    public static Builder builder(CircularAdaptee other) {
      return new Builder(other);
    }

    public static class Builder {
        private test.fixtures.adapter.CircularStruct field = null;
    
        @com.facebook.swift.codec.ThriftField(value=1, name="field", requiredness=Requiredness.NONE)    public Builder setField(test.fixtures.adapter.CircularStruct field) {
            this.field = field;
            return this;
        }
    
        public test.fixtures.adapter.CircularStruct getField() { return field; }
    
        public Builder() { }
        public Builder(CircularAdaptee other) {
            this.field = other.field;
        }
    
        @ThriftConstructor
        public CircularAdaptee build() {
            CircularAdaptee result = new CircularAdaptee (
                this.field
            );
            return result;
        }
    }
    
    public static final Map<String, Integer> NAMES_TO_IDS = new HashMap<>();
    public static final Map<String, Integer> THRIFT_NAMES_TO_IDS = new HashMap<>();
    public static final Map<Integer, TField> FIELD_METADATA = new HashMap<>();
    private static final TStruct STRUCT_DESC = new TStruct("CircularAdaptee");
    private final test.fixtures.adapter.CircularStruct field;
    public static final int _FIELD = 1;
    private static final TField FIELD_FIELD_DESC = new TField("field", TType.STRUCT, (short)1);
    static {
      NAMES_TO_IDS.put("field", 1);
      THRIFT_NAMES_TO_IDS.put("field", 1);
      FIELD_METADATA.put(1, FIELD_FIELD_DESC);
      com.facebook.thrift.type.TypeRegistry.add(new com.facebook.thrift.type.Type(
        new com.facebook.thrift.type.UniversalName("facebook.com/thrift/test/CircularAdaptee"),
        CircularAdaptee.class, CircularAdaptee::read0));
    }
    
    @Nullable
    @com.facebook.swift.codec.ThriftField(value=1, name="field", requiredness=Requiredness.NONE)
    public test.fixtures.adapter.CircularStruct getField() { return field; }

    @java.lang.Override
    public String toString() {
        ToStringHelper helper = toStringHelper(this);
        helper.add("field", field);
        return helper.toString();
    }

    @java.lang.Override
    public boolean equals(java.lang.Object o) {
        if (this == o) {
            return true;
        }
        if (o == null || getClass() != o.getClass()) {
            return false;
        }
    
        CircularAdaptee other = (CircularAdaptee)o;
    
        return
            Objects.equals(field, other.field) &&
            true;
    }

    @java.lang.Override
    public int hashCode() {
        return Arrays.deepHashCode(new java.lang.Object[] {
            field
        });
    }

    
    public static com.facebook.thrift.payload.Reader<CircularAdaptee> asReader() {
      return CircularAdaptee::read0;
    }
    
    public static CircularAdaptee read0(TProtocol oprot) throws TException {
      TField __field;
      oprot.readStructBegin(CircularAdaptee.NAMES_TO_IDS, CircularAdaptee.THRIFT_NAMES_TO_IDS, CircularAdaptee.FIELD_METADATA);
      CircularAdaptee.Builder builder = new CircularAdaptee.Builder();
      while (true) {
        __field = oprot.readFieldBegin();
        if (__field.type == TType.STOP) { break; }
        switch (__field.id) {
        case _FIELD:
          if (__field.type == TType.STRUCT) {
            test.fixtures.adapter.CircularStruct field = test.fixtures.adapter.CircularStruct.read0(oprot);
            builder.setField(field);
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
      if (field != null) {
        oprot.writeFieldBegin(FIELD_FIELD_DESC);
        this.field.write0(oprot);
        oprot.writeFieldEnd();
      }
      oprot.writeFieldStop();
      oprot.writeStructEnd();
    }

    private static class _CircularAdapteeLazy {
        private static final CircularAdaptee _DEFAULT = new CircularAdaptee.Builder().build();
    }
    
    public static CircularAdaptee defaultInstance() {
        return  _CircularAdapteeLazy._DEFAULT;
    }
}
