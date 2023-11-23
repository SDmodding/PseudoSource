// File Line: 83
// RVA: 0x1F6D10
__int64 __fastcall UFG::qProperty::GetDataOffset(UFG::qProperty *this)
{
  return this->mTypeUIDOffsetChanged & 0xFFFFFF;
}

// File Line: 84
// RVA: 0x1F84E0
__int64 __fastcall UFG::qProperty::GetTypeUID(UFG::qProperty *this)
{
  return HIBYTE(this->mTypeUIDOffsetChanged);
}

// File Line: 87
// RVA: 0x1FD070
void __fastcall UFG::qProperty::SetDataOffset(UFG::qProperty *this, unsigned int dataOffset)
{
  this->mTypeUIDOffsetChanged &= 0xFF000000;
  this->mTypeUIDOffsetChanged |= dataOffset;
}

// File Line: 92
// RVA: 0x1FE640
void __fastcall UFG::qProperty::SetTypeUID(UFG::qProperty *this, unsigned int typeUID)
{
  this->mTypeUIDOffsetChanged &= 0xFFFFFFu;
  this->mTypeUIDOffsetChanged |= typeUID << 24;
}

// File Line: 263
// RVA: 0xD8AC0
__int64 __fastcall UFG::qPropertyCollection::GetFlags(UFG::qPropertyCollection *this, int flags)
{
  return flags & this->mFlags;
}

// File Line: 264
// RVA: 0x1FD080
void __fastcall UFG::qPropertyCollection::SetFlags(UFG::qPropertyCollection *this, int flags)
{
  this->mFlags |= flags;
}

// File Line: 267
// RVA: 0x1F9A80
__int64 __fastcall UFG::qPropertyCollection::IsPropertySet(UFG::qPropertyCollection *this)
{
  return (this->mFlags >> 1) & 1;
}

// File Line: 268
// RVA: 0x1F9A70
__int64 __fastcall UFG::qPropertyCollection::IsPropertyList(UFG::qPropertyCollection *this)
{
  return (this->mFlags >> 2) & 1;
}

// File Line: 269
// RVA: 0x1F9A50
__int64 __fastcall UFG::qPropertyCollection::IsMemImaged(UFG::qPropertyCollection *this)
{
  return this->mFlags & 1;
}

// File Line: 278
// RVA: 0x1F6F90
UFG::qPropertySet *__fastcall UFG::qPropertyCollection::GetOwningSet(UFG::qPropertyCollection *this)
{
  if ( (this->mFlags & 0x10) != 0 )
    return (UFG::qPropertySet *)UFG::qOffset64<char const *>::Get((UFG::qOffset64<char const *> *)&this->mOwner, 0i64);
  else
    return 0i64;
}

// File Line: 280
// RVA: 0x1F6F70
UFG::qPropertyList *__fastcall UFG::qPropertyCollection::GetOwningList(UFG::qPropertyCollection *this)
{
  if ( (this->mFlags & 0x20) != 0 )
    return (UFG::qPropertyList *)UFG::qOffset64<char const *>::Get((UFG::qOffset64<char const *> *)&this->mOwner, 0i64);
  else
    return 0i64;
}

// File Line: 308
// RVA: 0x1EEC40
UFG::allocator::free_link *__fastcall UFG::qPropertySet::operator new(unsigned __int64 size)
{
  return UFG::qMemoryPool::Allocate(&gPropertySetMemoryPool, size, "qPropertySet", 0i64, 1u);
}

// File Line: 389
// RVA: 0x1F8E80
// attributes: thunk
char *__fastcall UFG::qPropertySet::GetValuePtr(
        UFG::qPropertySet *this,
        unsigned int type_uid,
        unsigned int name_uid,
        UFG::qPropertyDepth depth,
        UFG::qPropertySet **owningSet)
{
  return ?GetValuePtr@qPropertySet@UFG@@QEAAPEAXKKW4qPropertyDepth@2@PEAPEBV12@@Z(
           this,
           type_uid,
           name_uid,
           depth,
           owningSet);
}

// File Line: 473
// RVA: 0x1F6F60
char *__fastcall UFG::qPropertySet::GetNameStringDBG(UFG::qPropertySet *this)
{
  return UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->mName);
}

// File Line: 474
// RVA: 0x5B170
void __fastcall UFG::qPropertySet::SetSchemaName(UFG::qPropertySet *this, UFG::qSymbol *name)
{
  this->mSchemaName = (UFG::qSymbol)name->mUID;
}

// File Line: 475
// RVA: 0x1F8450
UFG::qSymbol *__fastcall UFG::qPropertySet::GetSchemaName(UFG::qPropertySet *this)
{
  return &this->mSchemaName;
}

// File Line: 476
// RVA: 0x1FA4C0
__int64 __fastcall UFG::qPropertySet::NumProperties(UFG::qPropertySet *this)
{
  return this->mNumProperties;
}

// File Line: 477
// RVA: 0x1F9AD0
__int64 __fastcall UFG::qPropertySet::IsResourceSet(UFG::qPropertySet *this)
{
  return HIWORD(this->mFlags) & 1;
}

// File Line: 479
// RVA: 0x1F84D0
__int64 __fastcall UFG::qPropertySet::GetType(UFG::qPropertySet *this)
{
  return this->mFlags >> 28;
}

// File Line: 480
// RVA: 0x5B180
void __fastcall UFG::qPropertySet::SetType(UFG::qPropertySet *this, UFG::qPropertySet::Type type)
{
  this->mFlags &= 0xFFFFFFFu;
  this->mFlags |= type << 28;
}

// File Line: 602
// RVA: 0x1F6E90
__int64 __fastcall UFG::qPropertySetResource::GetFlags(UFG::qPropertySetResource *this, int flags)
{
  return flags & this->mFlags;
}

// File Line: 603
// RVA: 0x1FD090
void __fastcall UFG::qPropertySetResource::SetFlags(UFG::qPropertySetResource *this, int flags)
{
  this->mFlags |= flags;
}

// File Line: 604
// RVA: 0x1F2450
void __fastcall UFG::qPropertySetResource::ClearFlags(UFG::qPropertySetResource *this, int flags)
{
  this->mFlags &= ~flags;
}

// File Line: 607
// RVA: 0x1FE630
void __fastcall UFG::qPropertySetResource::SetSourceCRC(UFG::qPropertySetResource *this, unsigned int sourceCRC)
{
  this->mSourceCRC = sourceCRC;
}

// File Line: 609
// RVA: 0x1F6F50
const char *__fastcall UFG::qPropertySetResource::GetNameString(UFG::qPropertySetResource *this)
{
  return UFG::qOffset64<char const *>::Get(&this->mNameString, 0i64);
}

// File Line: 611
// RVA: 0x1F7B60
UFG::qPropertySet *__fastcall UFG::qPropertySetResource::GetPropertySet(UFG::qPropertySetResource *this)
{
  return &this->mData;
}

// File Line: 614
// RVA: 0x1F9A60
__int64 __fastcall UFG::qPropertySetResource::IsMemImaged(UFG::qPropertySetResource *this)
{
  return this->mFlags & 1;
}

