#
# Autogenerated by Thrift
#
# DO NOT EDIT
#  @generated
#

from __future__ import annotations

import folly.iobuf as _fbthrift_iobuf

from abc import ABCMeta as _fbthrift_ABCMeta
import test.fixtures.python_capi.serialized_dep.thrift_abstract_types as _fbthrift_abstract_types
import thrift.python.types as _fbthrift_python_types
import thrift.python.exceptions as _fbthrift_python_exceptions



class SerializedStruct(metaclass=_fbthrift_python_types.StructMeta):
    _fbthrift_SPEC = (
        _fbthrift_python_types.FieldInfo(
            1,  # id
            _fbthrift_python_types.FieldQualifier.Unqualified, # qualifier
            "s",  # name
            "s",  # python name (from @python.Name annotation)
            _fbthrift_python_types.typeinfo_string,  # typeinfo
            None,  # default value
            None,  # adapter info
            False, # field type is primitive
            8, # IDL type (see BaseTypeEnum)
        ),
        _fbthrift_python_types.FieldInfo(
            2,  # id
            _fbthrift_python_types.FieldQualifier.Unqualified, # qualifier
            "i",  # name
            "i",  # python name (from @python.Name annotation)
            _fbthrift_python_types.typeinfo_i32,  # typeinfo
            None,  # default value
            None,  # adapter info
            True, # field type is primitive
            4, # IDL type (see BaseTypeEnum)
        ),
        _fbthrift_python_types.FieldInfo(
            3,  # id
            _fbthrift_python_types.FieldQualifier.Optional, # qualifier
            "os",  # name
            "os",  # python name (from @python.Name annotation)
            _fbthrift_python_types.typeinfo_string,  # typeinfo
            None,  # default value
            None,  # adapter info
            False, # field type is primitive
            8, # IDL type (see BaseTypeEnum)
        ),
        _fbthrift_python_types.FieldInfo(
            4,  # id
            _fbthrift_python_types.FieldQualifier.Unqualified, # qualifier
            "rs",  # name
            "rs",  # python name (from @python.Name annotation)
            _fbthrift_python_types.typeinfo_string,  # typeinfo
            None,  # default value
            None,  # adapter info
            False, # field type is primitive
            8, # IDL type (see BaseTypeEnum)
        ),
    )

    @staticmethod
    def __get_thrift_name__() -> str:
        return "serialized_dep.SerializedStruct"

    @staticmethod
    def __get_thrift_uri__():
        return "test.dev/fixtures/python_capi/SerializedStruct"

    @classmethod
    def _fbthrift_auto_migrate_enabled(cls):
        return False

    @staticmethod
    def __get_metadata__():
        return _fbthrift_metadata__struct_SerializedStruct()

    def _to_python(self):
        return self

    def _to_mutable_python(self):
        from thrift.python import mutable_converter
        import importlib
        mutable_types = importlib.import_module("test.fixtures.python_capi.serialized_dep.thrift_mutable_types")
        return mutable_converter.to_mutable_python_struct_or_union(mutable_types.SerializedStruct, self)

    def _to_py3(self):
        import importlib
        py3_types = importlib.import_module("test.fixtures.python_capi.serialized_dep.types")
        from thrift.py3 import converter
        return converter.to_py3_struct(py3_types.SerializedStruct, self)

    def _to_py_deprecated(self):
        import importlib
        from thrift.util import converter
        try:
            py_deprecated_types = importlib.import_module("serialized_dep.ttypes")
            return converter.to_py_struct(py_deprecated_types.SerializedStruct, self)
        except ModuleNotFoundError:
            py_asyncio_types = importlib.import_module("serialized_dep.ttypes")
            return converter.to_py_struct(py_asyncio_types.SerializedStruct, self)

_fbthrift_ABCMeta.register(_fbthrift_abstract_types.SerializedStruct, SerializedStruct)
_fbthrift_SerializedStruct = SerializedStruct

class SerializedUnion(metaclass=_fbthrift_python_types.UnionMeta):
    _fbthrift_SPEC = (
        _fbthrift_python_types.FieldInfo(
            1,  # id
            _fbthrift_python_types.FieldQualifier.Unqualified, # qualifier
            "s",  # name
            "s",  # python name (from @python.Name annotation)
            _fbthrift_python_types.typeinfo_string,  # typeinfo
            None,  # default value
            None,  # adapter info
            False, # field type is primitive
            8, # IDL type (see BaseTypeEnum)
        ),
        _fbthrift_python_types.FieldInfo(
            2,  # id
            _fbthrift_python_types.FieldQualifier.Unqualified, # qualifier
            "i",  # name
            "i",  # python name (from @python.Name annotation)
            _fbthrift_python_types.typeinfo_i32,  # typeinfo
            None,  # default value
            None,  # adapter info
            True, # field type is primitive
            4, # IDL type (see BaseTypeEnum)
        ),
    )

    _fbthrift_abstract_base_class = _fbthrift_abstract_types.SerializedUnion


    @staticmethod
    def __get_thrift_name__() -> str:
        return "serialized_dep.SerializedUnion"

    @staticmethod
    def __get_thrift_uri__():
        return "test.dev/fixtures/python_capi/SerializedUnion"

    @classmethod
    def _fbthrift_auto_migrate_enabled(cls):
        return False

    @staticmethod
    def __get_metadata__():
        return _fbthrift_metadata__struct_SerializedUnion()

    def _to_python(self):
        return self

    def _to_mutable_python(self):
        from thrift.python import mutable_converter
        import importlib
        mutable_types = importlib.import_module("test.fixtures.python_capi.serialized_dep.thrift_mutable_types")
        return mutable_converter.to_mutable_python_struct_or_union(mutable_types.SerializedUnion, self)

    def _to_py3(self):
        import importlib
        py3_types = importlib.import_module("test.fixtures.python_capi.serialized_dep.types")
        from thrift.py3 import converter
        return converter.to_py3_struct(py3_types.SerializedUnion, self)

    def _to_py_deprecated(self):
        import importlib
        from thrift.util import converter
        try:
            py_deprecated_types = importlib.import_module("serialized_dep.ttypes")
            return converter.to_py_struct(py_deprecated_types.SerializedUnion, self)
        except ModuleNotFoundError:
            py_asyncio_types = importlib.import_module("serialized_dep.ttypes")
            return converter.to_py_struct(py_asyncio_types.SerializedUnion, self)

_fbthrift_ABCMeta.register(_fbthrift_abstract_types.SerializedUnion, SerializedUnion)
_fbthrift_SerializedUnion = SerializedUnion

class SerializedError(metaclass=_fbthrift_python_exceptions.GeneratedErrorMeta):
    _fbthrift_SPEC = (
        _fbthrift_python_types.FieldInfo(
            1,  # id
            _fbthrift_python_types.FieldQualifier.Unqualified, # qualifier
            "msg",  # name
            "msg",  # python name (from @python.Name annotation)
            _fbthrift_python_types.typeinfo_string,  # typeinfo
            None,  # default value
            None,  # adapter info
            False, # field type is primitive
            8, # IDL type (see BaseTypeEnum)
        ),
        _fbthrift_python_types.FieldInfo(
            2,  # id
            _fbthrift_python_types.FieldQualifier.Optional, # qualifier
            "os",  # name
            "os",  # python name (from @python.Name annotation)
            _fbthrift_python_types.typeinfo_string,  # typeinfo
            None,  # default value
            None,  # adapter info
            False, # field type is primitive
            8, # IDL type (see BaseTypeEnum)
        ),
        _fbthrift_python_types.FieldInfo(
            3,  # id
            _fbthrift_python_types.FieldQualifier.Unqualified, # qualifier
            "rs",  # name
            "rs",  # python name (from @python.Name annotation)
            _fbthrift_python_types.typeinfo_string,  # typeinfo
            None,  # default value
            None,  # adapter info
            False, # field type is primitive
            8, # IDL type (see BaseTypeEnum)
        ),
    )

    _fbthrift_abstract_base_class = _fbthrift_abstract_types.SerializedError


    @staticmethod
    def __get_thrift_name__() -> str:
        return "serialized_dep.SerializedError"

    @staticmethod
    def __get_thrift_uri__():
        return "test.dev/fixtures/python_capi/SerializedError"

    @classmethod
    def _fbthrift_auto_migrate_enabled(cls):
        return False

    @staticmethod
    def __get_metadata__():
        return _fbthrift_metadata__exception_SerializedError()

    def _to_python(self):
        return self

    def _to_mutable_python(self):
        from thrift.python import mutable_converter
        import importlib
        mutable_types = importlib.import_module("test.fixtures.python_capi.serialized_dep.thrift_mutable_types")
        return mutable_converter.to_mutable_python_struct_or_union(mutable_types.SerializedError, self)

    def _to_py3(self):
        import importlib
        py3_types = importlib.import_module("test.fixtures.python_capi.serialized_dep.types")
        from thrift.py3 import converter
        return converter.to_py3_struct(py3_types.SerializedError, self)

    def _to_py_deprecated(self):
        import importlib
        from thrift.util import converter
        try:
            py_deprecated_types = importlib.import_module("serialized_dep.ttypes")
            return converter.to_py_struct(py_deprecated_types.SerializedError, self)
        except ModuleNotFoundError:
            py_asyncio_types = importlib.import_module("serialized_dep.ttypes")
            return converter.to_py_struct(py_asyncio_types.SerializedError, self)
_fbthrift_SerializedError = SerializedError

class MarshalStruct(metaclass=_fbthrift_python_types.StructMeta):
    _fbthrift_SPEC = (
        _fbthrift_python_types.FieldInfo(
            1,  # id
            _fbthrift_python_types.FieldQualifier.Unqualified, # qualifier
            "s",  # name
            "s",  # python name (from @python.Name annotation)
            _fbthrift_python_types.typeinfo_string,  # typeinfo
            None,  # default value
            None,  # adapter info
            False, # field type is primitive
            8, # IDL type (see BaseTypeEnum)
        ),
        _fbthrift_python_types.FieldInfo(
            2,  # id
            _fbthrift_python_types.FieldQualifier.Unqualified, # qualifier
            "i",  # name
            "i",  # python name (from @python.Name annotation)
            _fbthrift_python_types.typeinfo_i32,  # typeinfo
            None,  # default value
            None,  # adapter info
            True, # field type is primitive
            4, # IDL type (see BaseTypeEnum)
        ),
        _fbthrift_python_types.FieldInfo(
            3,  # id
            _fbthrift_python_types.FieldQualifier.Optional, # qualifier
            "os",  # name
            "os",  # python name (from @python.Name annotation)
            _fbthrift_python_types.typeinfo_string,  # typeinfo
            None,  # default value
            None,  # adapter info
            False, # field type is primitive
            8, # IDL type (see BaseTypeEnum)
        ),
        _fbthrift_python_types.FieldInfo(
            4,  # id
            _fbthrift_python_types.FieldQualifier.Unqualified, # qualifier
            "rs",  # name
            "rs",  # python name (from @python.Name annotation)
            _fbthrift_python_types.typeinfo_string,  # typeinfo
            None,  # default value
            None,  # adapter info
            False, # field type is primitive
            8, # IDL type (see BaseTypeEnum)
        ),
    )

    @staticmethod
    def __get_thrift_name__() -> str:
        return "serialized_dep.MarshalStruct"

    @staticmethod
    def __get_thrift_uri__():
        return "test.dev/fixtures/python_capi/MarshalStruct"

    @classmethod
    def _fbthrift_auto_migrate_enabled(cls):
        return False

    @staticmethod
    def __get_metadata__():
        return _fbthrift_metadata__struct_MarshalStruct()

    def _to_python(self):
        return self

    def _to_mutable_python(self):
        from thrift.python import mutable_converter
        import importlib
        mutable_types = importlib.import_module("test.fixtures.python_capi.serialized_dep.thrift_mutable_types")
        return mutable_converter.to_mutable_python_struct_or_union(mutable_types.MarshalStruct, self)

    def _to_py3(self):
        import importlib
        py3_types = importlib.import_module("test.fixtures.python_capi.serialized_dep.types")
        from thrift.py3 import converter
        return converter.to_py3_struct(py3_types.MarshalStruct, self)

    def _to_py_deprecated(self):
        import importlib
        from thrift.util import converter
        try:
            py_deprecated_types = importlib.import_module("serialized_dep.ttypes")
            return converter.to_py_struct(py_deprecated_types.MarshalStruct, self)
        except ModuleNotFoundError:
            py_asyncio_types = importlib.import_module("serialized_dep.ttypes")
            return converter.to_py_struct(py_asyncio_types.MarshalStruct, self)

_fbthrift_ABCMeta.register(_fbthrift_abstract_types.MarshalStruct, MarshalStruct)
_fbthrift_MarshalStruct = MarshalStruct

class MarshalUnion(metaclass=_fbthrift_python_types.UnionMeta):
    _fbthrift_SPEC = (
        _fbthrift_python_types.FieldInfo(
            1,  # id
            _fbthrift_python_types.FieldQualifier.Unqualified, # qualifier
            "s",  # name
            "s",  # python name (from @python.Name annotation)
            _fbthrift_python_types.typeinfo_string,  # typeinfo
            None,  # default value
            None,  # adapter info
            False, # field type is primitive
            8, # IDL type (see BaseTypeEnum)
        ),
        _fbthrift_python_types.FieldInfo(
            2,  # id
            _fbthrift_python_types.FieldQualifier.Unqualified, # qualifier
            "i",  # name
            "i",  # python name (from @python.Name annotation)
            _fbthrift_python_types.typeinfo_i32,  # typeinfo
            None,  # default value
            None,  # adapter info
            True, # field type is primitive
            4, # IDL type (see BaseTypeEnum)
        ),
    )

    _fbthrift_abstract_base_class = _fbthrift_abstract_types.MarshalUnion


    @staticmethod
    def __get_thrift_name__() -> str:
        return "serialized_dep.MarshalUnion"

    @staticmethod
    def __get_thrift_uri__():
        return "test.dev/fixtures/python_capi/MarshalUnion"

    @classmethod
    def _fbthrift_auto_migrate_enabled(cls):
        return False

    @staticmethod
    def __get_metadata__():
        return _fbthrift_metadata__struct_MarshalUnion()

    def _to_python(self):
        return self

    def _to_mutable_python(self):
        from thrift.python import mutable_converter
        import importlib
        mutable_types = importlib.import_module("test.fixtures.python_capi.serialized_dep.thrift_mutable_types")
        return mutable_converter.to_mutable_python_struct_or_union(mutable_types.MarshalUnion, self)

    def _to_py3(self):
        import importlib
        py3_types = importlib.import_module("test.fixtures.python_capi.serialized_dep.types")
        from thrift.py3 import converter
        return converter.to_py3_struct(py3_types.MarshalUnion, self)

    def _to_py_deprecated(self):
        import importlib
        from thrift.util import converter
        try:
            py_deprecated_types = importlib.import_module("serialized_dep.ttypes")
            return converter.to_py_struct(py_deprecated_types.MarshalUnion, self)
        except ModuleNotFoundError:
            py_asyncio_types = importlib.import_module("serialized_dep.ttypes")
            return converter.to_py_struct(py_asyncio_types.MarshalUnion, self)

_fbthrift_ABCMeta.register(_fbthrift_abstract_types.MarshalUnion, MarshalUnion)
_fbthrift_MarshalUnion = MarshalUnion

class MarshalError(metaclass=_fbthrift_python_exceptions.GeneratedErrorMeta):
    _fbthrift_SPEC = (
        _fbthrift_python_types.FieldInfo(
            1,  # id
            _fbthrift_python_types.FieldQualifier.Unqualified, # qualifier
            "msg",  # name
            "msg",  # python name (from @python.Name annotation)
            _fbthrift_python_types.typeinfo_string,  # typeinfo
            None,  # default value
            None,  # adapter info
            False, # field type is primitive
            8, # IDL type (see BaseTypeEnum)
        ),
        _fbthrift_python_types.FieldInfo(
            2,  # id
            _fbthrift_python_types.FieldQualifier.Optional, # qualifier
            "os",  # name
            "os",  # python name (from @python.Name annotation)
            _fbthrift_python_types.typeinfo_string,  # typeinfo
            None,  # default value
            None,  # adapter info
            False, # field type is primitive
            8, # IDL type (see BaseTypeEnum)
        ),
        _fbthrift_python_types.FieldInfo(
            3,  # id
            _fbthrift_python_types.FieldQualifier.Unqualified, # qualifier
            "rs",  # name
            "rs",  # python name (from @python.Name annotation)
            _fbthrift_python_types.typeinfo_string,  # typeinfo
            None,  # default value
            None,  # adapter info
            False, # field type is primitive
            8, # IDL type (see BaseTypeEnum)
        ),
    )

    _fbthrift_abstract_base_class = _fbthrift_abstract_types.MarshalError


    @staticmethod
    def __get_thrift_name__() -> str:
        return "serialized_dep.MarshalError"

    @staticmethod
    def __get_thrift_uri__():
        return "test.dev/fixtures/python_capi/MarshalError"

    @classmethod
    def _fbthrift_auto_migrate_enabled(cls):
        return False

    @staticmethod
    def __get_metadata__():
        return _fbthrift_metadata__exception_MarshalError()

    def _to_python(self):
        return self

    def _to_mutable_python(self):
        from thrift.python import mutable_converter
        import importlib
        mutable_types = importlib.import_module("test.fixtures.python_capi.serialized_dep.thrift_mutable_types")
        return mutable_converter.to_mutable_python_struct_or_union(mutable_types.MarshalError, self)

    def _to_py3(self):
        import importlib
        py3_types = importlib.import_module("test.fixtures.python_capi.serialized_dep.types")
        from thrift.py3 import converter
        return converter.to_py3_struct(py3_types.MarshalError, self)

    def _to_py_deprecated(self):
        import importlib
        from thrift.util import converter
        try:
            py_deprecated_types = importlib.import_module("serialized_dep.ttypes")
            return converter.to_py_struct(py_deprecated_types.MarshalError, self)
        except ModuleNotFoundError:
            py_asyncio_types = importlib.import_module("serialized_dep.ttypes")
            return converter.to_py_struct(py_asyncio_types.MarshalError, self)
_fbthrift_MarshalError = MarshalError

# This unfortunately has to be down here to prevent circular imports
import test.fixtures.python_capi.serialized_dep.thrift_metadata as _fbthrift__test__fixtures__python_capi__serialized_dep__thrift_metadata

_fbthrift_all_enums = [
]


def _fbthrift_metadata__struct_SerializedStruct():
    return _fbthrift__test__fixtures__python_capi__serialized_dep__thrift_metadata.gen_metadata_struct_SerializedStruct()


def _fbthrift_metadata__struct_SerializedUnion():
    return _fbthrift__test__fixtures__python_capi__serialized_dep__thrift_metadata.gen_metadata_struct_SerializedUnion()


def _fbthrift_metadata__exception_SerializedError():
    return _fbthrift__test__fixtures__python_capi__serialized_dep__thrift_metadata.gen_metadata_exception_SerializedError()


def _fbthrift_metadata__struct_MarshalStruct():
    return _fbthrift__test__fixtures__python_capi__serialized_dep__thrift_metadata.gen_metadata_struct_MarshalStruct()


def _fbthrift_metadata__struct_MarshalUnion():
    return _fbthrift__test__fixtures__python_capi__serialized_dep__thrift_metadata.gen_metadata_struct_MarshalUnion()


def _fbthrift_metadata__exception_MarshalError():
    return _fbthrift__test__fixtures__python_capi__serialized_dep__thrift_metadata.gen_metadata_exception_MarshalError()


_fbthrift_all_structs = [
    SerializedStruct,
    SerializedUnion,
    SerializedError,
    MarshalStruct,
    MarshalUnion,
    MarshalError,
]
_fbthrift_python_types.fill_specs(*_fbthrift_all_structs)
