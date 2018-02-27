// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: lm.helloworld.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "lm.helloworld.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace lm {
class helloworldDefaultTypeInternal : public ::google::protobuf::internal::ExplicitlyConstructed<helloworld> {
} _helloworld_default_instance_;

namespace protobuf_lm_2ehelloworld_2eproto {


namespace {

::google::protobuf::Metadata file_level_metadata[1];

}  // namespace

const ::google::protobuf::uint32 TableStruct::offsets[] = {
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(helloworld, _has_bits_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(helloworld, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(helloworld, id_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(helloworld, str_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(helloworld, opt_),
  1,
  0,
  2,
};

static const ::google::protobuf::internal::MigrationSchema schemas[] = {
  { 0, 7, sizeof(helloworld)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&_helloworld_default_instance_),
};

namespace {

void protobuf_AssignDescriptors() {
  AddDescriptors();
  ::google::protobuf::MessageFactory* factory = NULL;
  AssignDescriptors(
      "lm.helloworld.proto", schemas, file_default_instances, TableStruct::offsets, factory,
      file_level_metadata, NULL, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 1);
}

}  // namespace

void TableStruct::Shutdown() {
  _helloworld_default_instance_.Shutdown();
  delete file_level_metadata[0].reflection;
}

void TableStruct::InitDefaultsImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::internal::InitProtobufDefaults();
  _helloworld_default_instance_.DefaultConstruct();
}

void InitDefaults() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &TableStruct::InitDefaultsImpl);
}
void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] = {
      "\n\023lm.helloworld.proto\022\002lm\"2\n\nhelloworld\022"
      "\n\n\002id\030\001 \002(\005\022\013\n\003str\030\002 \002(\t\022\013\n\003opt\030\003 \001(\005"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 77);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "lm.helloworld.proto", &protobuf_RegisterTypes);
  ::google::protobuf::internal::OnShutdown(&TableStruct::Shutdown);
}

void AddDescriptors() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;

}  // namespace protobuf_lm_2ehelloworld_2eproto


// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int helloworld::kIdFieldNumber;
const int helloworld::kStrFieldNumber;
const int helloworld::kOptFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

helloworld::helloworld()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    protobuf_lm_2ehelloworld_2eproto::InitDefaults();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:lm.helloworld)
}
helloworld::helloworld(const helloworld& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _has_bits_(from._has_bits_),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  str_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.has_str()) {
    str_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.str_);
  }
  ::memcpy(&id_, &from.id_,
    reinterpret_cast<char*>(&opt_) -
    reinterpret_cast<char*>(&id_) + sizeof(opt_));
  // @@protoc_insertion_point(copy_constructor:lm.helloworld)
}

void helloworld::SharedCtor() {
  _cached_size_ = 0;
  str_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(&id_, 0, reinterpret_cast<char*>(&opt_) -
    reinterpret_cast<char*>(&id_) + sizeof(opt_));
}

helloworld::~helloworld() {
  // @@protoc_insertion_point(destructor:lm.helloworld)
  SharedDtor();
}

void helloworld::SharedDtor() {
  str_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void helloworld::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* helloworld::descriptor() {
  protobuf_lm_2ehelloworld_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_lm_2ehelloworld_2eproto::file_level_metadata[0].descriptor;
}

const helloworld& helloworld::default_instance() {
  protobuf_lm_2ehelloworld_2eproto::InitDefaults();
  return *internal_default_instance();
}

helloworld* helloworld::New(::google::protobuf::Arena* arena) const {
  helloworld* n = new helloworld;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void helloworld::Clear() {
// @@protoc_insertion_point(message_clear_start:lm.helloworld)
  if (has_str()) {
    GOOGLE_DCHECK(!str_.IsDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited()));
    (*str_.UnsafeRawStringPointer())->clear();
  }
  if (_has_bits_[0 / 32] & 6u) {
    ::memset(&id_, 0, reinterpret_cast<char*>(&opt_) -
      reinterpret_cast<char*>(&id_) + sizeof(opt_));
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

bool helloworld::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:lm.helloworld)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required int32 id = 1;
      case 1: {
        if (tag == 8u) {
          set_has_id();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &id_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // required string str = 2;
      case 2: {
        if (tag == 18u) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_str()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->str().data(), this->str().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "lm.helloworld.str");
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional int32 opt = 3;
      case 3: {
        if (tag == 24u) {
          set_has_opt();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &opt_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:lm.helloworld)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:lm.helloworld)
  return false;
#undef DO_
}

void helloworld::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:lm.helloworld)
  // required int32 id = 1;
  if (has_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->id(), output);
  }

  // required string str = 2;
  if (has_str()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->str().data(), this->str().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "lm.helloworld.str");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->str(), output);
  }

  // optional int32 opt = 3;
  if (has_opt()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(3, this->opt(), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:lm.helloworld)
}

::google::protobuf::uint8* helloworld::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic;  // Unused
  // @@protoc_insertion_point(serialize_to_array_start:lm.helloworld)
  // required int32 id = 1;
  if (has_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->id(), target);
  }

  // required string str = 2;
  if (has_str()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->str().data(), this->str().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "lm.helloworld.str");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->str(), target);
  }

  // optional int32 opt = 3;
  if (has_opt()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, this->opt(), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:lm.helloworld)
  return target;
}

size_t helloworld::RequiredFieldsByteSizeFallback() const {
// @@protoc_insertion_point(required_fields_byte_size_fallback_start:lm.helloworld)
  size_t total_size = 0;

  if (has_str()) {
    // required string str = 2;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->str());
  }

  if (has_id()) {
    // required int32 id = 1;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->id());
  }

  return total_size;
}
size_t helloworld::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:lm.helloworld)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  if (((_has_bits_[0] & 0x00000003) ^ 0x00000003) == 0) {  // All required fields are present.
    // required string str = 2;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->str());

    // required int32 id = 1;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->id());

  } else {
    total_size += RequiredFieldsByteSizeFallback();
  }
  // optional int32 opt = 3;
  if (has_opt()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->opt());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void helloworld::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:lm.helloworld)
  GOOGLE_DCHECK_NE(&from, this);
  const helloworld* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const helloworld>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:lm.helloworld)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:lm.helloworld)
    MergeFrom(*source);
  }
}

void helloworld::MergeFrom(const helloworld& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:lm.helloworld)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  if (from._has_bits_[0 / 32] & 7u) {
    if (from.has_str()) {
      set_has_str();
      str_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.str_);
    }
    if (from.has_id()) {
      set_id(from.id());
    }
    if (from.has_opt()) {
      set_opt(from.opt());
    }
  }
}

void helloworld::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:lm.helloworld)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void helloworld::CopyFrom(const helloworld& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:lm.helloworld)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool helloworld::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;
  return true;
}

void helloworld::Swap(helloworld* other) {
  if (other == this) return;
  InternalSwap(other);
}
void helloworld::InternalSwap(helloworld* other) {
  str_.Swap(&other->str_);
  std::swap(id_, other->id_);
  std::swap(opt_, other->opt_);
  std::swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata helloworld::GetMetadata() const {
  protobuf_lm_2ehelloworld_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_lm_2ehelloworld_2eproto::file_level_metadata[0];
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// helloworld

// required int32 id = 1;
bool helloworld::has_id() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
void helloworld::set_has_id() {
  _has_bits_[0] |= 0x00000002u;
}
void helloworld::clear_has_id() {
  _has_bits_[0] &= ~0x00000002u;
}
void helloworld::clear_id() {
  id_ = 0;
  clear_has_id();
}
::google::protobuf::int32 helloworld::id() const {
  // @@protoc_insertion_point(field_get:lm.helloworld.id)
  return id_;
}
void helloworld::set_id(::google::protobuf::int32 value) {
  set_has_id();
  id_ = value;
  // @@protoc_insertion_point(field_set:lm.helloworld.id)
}

// required string str = 2;
bool helloworld::has_str() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
void helloworld::set_has_str() {
  _has_bits_[0] |= 0x00000001u;
}
void helloworld::clear_has_str() {
  _has_bits_[0] &= ~0x00000001u;
}
void helloworld::clear_str() {
  str_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_str();
}
const ::std::string& helloworld::str() const {
  // @@protoc_insertion_point(field_get:lm.helloworld.str)
  return str_.GetNoArena();
}
void helloworld::set_str(const ::std::string& value) {
  set_has_str();
  str_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:lm.helloworld.str)
}
#if LANG_CXX11
void helloworld::set_str(::std::string&& value) {
  set_has_str();
  str_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:lm.helloworld.str)
}
#endif
void helloworld::set_str(const char* value) {
  set_has_str();
  str_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:lm.helloworld.str)
}
void helloworld::set_str(const char* value, size_t size) {
  set_has_str();
  str_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:lm.helloworld.str)
}
::std::string* helloworld::mutable_str() {
  set_has_str();
  // @@protoc_insertion_point(field_mutable:lm.helloworld.str)
  return str_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
::std::string* helloworld::release_str() {
  // @@protoc_insertion_point(field_release:lm.helloworld.str)
  clear_has_str();
  return str_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
void helloworld::set_allocated_str(::std::string* str) {
  if (str != NULL) {
    set_has_str();
  } else {
    clear_has_str();
  }
  str_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), str);
  // @@protoc_insertion_point(field_set_allocated:lm.helloworld.str)
}

// optional int32 opt = 3;
bool helloworld::has_opt() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
void helloworld::set_has_opt() {
  _has_bits_[0] |= 0x00000004u;
}
void helloworld::clear_has_opt() {
  _has_bits_[0] &= ~0x00000004u;
}
void helloworld::clear_opt() {
  opt_ = 0;
  clear_has_opt();
}
::google::protobuf::int32 helloworld::opt() const {
  // @@protoc_insertion_point(field_get:lm.helloworld.opt)
  return opt_;
}
void helloworld::set_opt(::google::protobuf::int32 value) {
  set_has_opt();
  opt_ = value;
  // @@protoc_insertion_point(field_set:lm.helloworld.opt)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace lm

// @@protoc_insertion_point(global_scope)
