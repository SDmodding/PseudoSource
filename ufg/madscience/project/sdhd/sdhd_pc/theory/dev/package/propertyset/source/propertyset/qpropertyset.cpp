// File Line: 48
// RVA: 0x146BC90
void dynamic_initializer_for__UFG::qTransQuat::msIdentity__()
{
  UFG::qTransQuat::qTransQuat(&UFG::qTransQuat::msIdentity, &UFG::qVector3::msZero, &UFG::qQuaternion::msUnity);
}

// File Line: 51
// RVA: 0x1EE0E0
void __fastcall UFG::qTransQuat::qTransQuat(UFG::qTransQuat *this)
{
  Assembly::GetRCX(this);
}

// File Line: 57
// RVA: 0x1EDFB0
void __fastcall UFG::qTransQuat::qTransQuat(UFG::qTransQuat *this, UFG::qVector3 *rot, UFG::qQuaternion *trans)
{
  float v3; // [rsp+20h] [rbp-48h]
  float v4; // [rsp+28h] [rbp-40h]
  float z; // [rsp+2Ch] [rbp-3Ch]
  hkSeekableStreamReader *RCX; // [rsp+30h] [rbp-38h]
  float y; // [rsp+38h] [rbp-30h]
  UFG::qVector4 v; // [rsp+4Ch] [rbp-1Ch] BYREF

  y = rot->y;
  z = rot->z;
  v.x = rot->x;
  v.y = y;
  v.z = z;
  LODWORD(v.w) = (_DWORD)FLOAT_1_0;
  UFG::qQuaternion::qQuaternion(&this->mRot, (UFG::qQuaternion *)&v);
  RCX = Assembly::GetRCX(trans);
  v3 = *((float *)&RCX->vfptr + 1);
  v4 = *(float *)&RCX->m_memSizeAndFlags;
  this->mTrans.x = *(float *)&RCX->vfptr;
  this->mTrans.y = v3;
  this->mTrans.z = v4;
}

// File Line: 85
// RVA: 0x1F66E0
UFG::qPropertyType *__fastcall UFG::qPropertyType::Get(unsigned int type_name_uid)
{
  if ( (_S1_25 & 1) == 0 )
  {
    _S1_25 |= 1u;
    types[12].mElementTypeUID = 8;
    types[12].mNumElements = 1;
    types[13].mName = "rangedFloat";
    types[13].mXMLTag = "FloatRanged";
    types[13].mNameUID = 13;
    types[13].Alignment = 4;
    types[13].mByteSize = 8;
    types[13].mElementTypeUID = 10;
    types[13].mNumElements = 2;
    types[14].mName = "rangedInt32";
    types[14].mXMLTag = "UInt32Ranged";
    types[14].mNameUID = 14;
    types[14].Alignment = 4;
    types[14].mByteSize = 8;
    types[14].mElementTypeUID = 7;
    types[14].mNumElements = 2;
    types[15].mName = "rangedInt32";
    types[15].mXMLTag = "Int32Ranged";
    types[15].mNameUID = 15;
    types[15].Alignment = 4;
    types[15].mByteSize = 8;
    types[15].mElementTypeUID = 2;
    types[15].mNumElements = 2;
    types[16].mName = "weightedList";
    types[16].mXMLTag = "WeightedListXX";
    types[16].mNameUID = 16;
    types[16].Alignment = 8;
    types[16].mByteSize = 8;
    types[16].mElementTypeUID = 8;
    types[16].mNumElements = 1;
    types[17].mName = "qVector2";
    types[17].mXMLTag = "Vector2";
    types[17].mNameUID = 17;
    types[17].Alignment = 4;
    types[17].mByteSize = 8;
    types[17].mElementTypeUID = 10;
    types[17].mNumElements = 2;
    types[18].mName = "qVector3";
    types[18].mXMLTag = "Vector3";
    types[18].mNameUID = 18;
    types[18].Alignment = 4;
    types[18].mByteSize = 12;
    types[18].mElementTypeUID = 10;
    types[18].mNumElements = 3;
    types[19].mName = "qVector4";
    types[19].mXMLTag = "Vector4";
    types[19].mNameUID = 19;
    types[19].Alignment = 4;
    types[19].mByteSize = 16;
    types[19].mElementTypeUID = 10;
    types[19].mNumElements = 4;
    types[20].mName = "qMatrix44";
    types[20].mXMLTag = "TransRotation";
    types[20].mNameUID = 20;
    types[20].Alignment = 4;
    types[20].mByteSize = 64;
    types[20].mElementTypeUID = 10;
    types[20].mNumElements = 16;
    types[21].mName = "qResHandle";
    types[21].mXMLTag = "Resource";
    types[21].mNameUID = 21;
    types[21].Alignment = 4;
    types[21].mByteSize = 40;
    types[21].mElementTypeUID = 7;
    types[21].mNumElements = 5;
    types[22].mName = "qSymbol";
    types[22].mXMLTag = "Symbol";
    types[22].mNameUID = 22;
    types[22].Alignment = 4;
    types[22].mByteSize = 4;
    types[22].mElementTypeUID = 7;
    types[22].mNumElements = 1;
    types[23].mName = "qSymbolUC";
    types[23].mXMLTag = "SymbolUC";
    types[23].mNameUID = 23;
    types[23].Alignment = 4;
    types[23].mByteSize = 4;
    types[23].mElementTypeUID = 7;
    types[23].mNumElements = 1;
    types[24].mName = "WwiseID";
    types[24].mXMLTag = "WwiseID";
    types[24].mNameUID = 24;
    types[24].Alignment = 4;
    types[24].mByteSize = 4;
    types[24].mElementTypeUID = 7;
    types[24].mNumElements = 1;
    types[25].mName = "List";
    types[25].mXMLTag = "List";
    types[25].mNameUID = 25;
    types[25].Alignment = 8;
    types[25].mByteSize = 8;
    types[25].mElementTypeUID = 8;
    types[25].mNumElements = 1;
    types[26].mName = "PropertySet";
    types[26].mXMLTag = "PropSet";
    types[26].mNameUID = 26;
    types[26].Alignment = 8;
    types[26].mByteSize = 8;
    types[26].mElementTypeUID = 8;
    types[26].mNumElements = 1;
    types[27].mName = "Transrotation";
    types[27].mXMLTag = "TransRotation";
    types[27].mNameUID = 27;
    types[27].Alignment = 4;
    types[27].mByteSize = 64;
    types[27].mElementTypeUID = 10;
    types[27].mNumElements = 16;
    types[28].mName = "TransQuat";
    types[28].mXMLTag = "TransQuat";
    types[28].mNameUID = 28;
    types[28].Alignment = 4;
    types[28].mByteSize = 28;
    types[28].mElementTypeUID = 10;
    types[28].mNumElements = 7;
    types[29].mName = "List";
    types[29].mXMLTag = "WeightedList";
    types[29].mNameUID = 25;
    types[29].Alignment = 8;
    types[29].mByteSize = 8;
    types[29].mElementTypeUID = 8;
    types[29].mNumElements = 1;
  }
  return &types[type_name_uid];
}

// File Line: 206
// RVA: 0x1F9A90
_BOOL8 __fastcall UFG::qPropertyType::IsPtrType(unsigned int type_uid)
{
  return type_uid == 26 || type_uid == 25 || type_uid == 12;
}

// File Line: 218
// RVA: 0x1FF7C0
UFG::allocator::free_link *__fastcall UFG::qPropertySet_Allocate(
        unsigned int byte_count,
        const char *dbg_tag,
        unsigned int flags)
{
  return UFG::qMemoryPool::Allocate(&gPropertySetMemoryPool, byte_count, dbg_tag, flags, 1u);
}

// File Line: 227
// RVA: 0x1FF800
void __fastcall UFG::qPropertySet_Free(char *buffer)
{
  UFG::qMemoryPool::Free(&gPropertySetMemoryPool, buffer);
}

// File Line: 242
// RVA: 0x1F6680
UFG::qResourceData *__fastcall UFG::qPropertySetHandle::Get(UFG::qPropertySetHandle *this)
{
  if ( !CAkVPLSrcNode::MustRelocateAnalysisDataOnMediaRelocation((CAkVPLSrcNode *)this) )
    return 0i64;
  if ( this->mNext )
    return (UFG::qResourceData *)UFG::qPropertySetResource::GetPropertySet((UFG::qPropertySetResource *)this->mData);
  return this->mData;
}

// File Line: 269
// RVA: 0x1F25A0
void __fastcall UFG::qPropertySetHandle::Close(UFG::qPropertySetHandle *this)
{
  UFG::qResourceInventory *v1; // rax

  if ( this->mNext )
  {
    v1 = UFG::qGetResourceInventory<UFG::qPropertySetResource>(0x54606C31u);
    UFG::qResourceHandle::Close(this, v1);
  }
  else
  {
    this->mData = 0i64;
  }
}

// File Line: 281
// RVA: 0x1F3380
void __fastcall UFG::qPropertySetHandle::CopyFrom(UFG::qPropertySetHandle *this, UFG::qPropertySetHandle *other)
{
  if ( other->mNext )
  {
    UFG::qPropertySetHandle::Init(this, other->mNameUID);
  }
  else
  {
    this->mNext = 0i64;
    this->mPrev = 0i64;
    this->mData = other->mData;
    this->mNameUID = other->mNameUID;
  }
}

// File Line: 296
// RVA: 0x1F96C0
void __fastcall UFG::qPropertySetHandle::Init(UFG::qPropertySetHandle *this)
{
  UFG::qResourceInventory *v1; // rax

  v1 = UFG::qGetResourceInventory<UFG::qPropertySetResource>(0x54606C31u);
  UFG::qResourceHandle::Init(this, 0x54606C31u, this->mNameUID, v1);
}

// File Line: 303
// RVA: 0x1F9680
void __fastcall UFG::qPropertySetHandle::Init(UFG::qPropertySetHandle *this, unsigned int resource_uid)
{
  UFG::qResourceInventory *v2; // rax

  v2 = UFG::qGetResourceInventory<UFG::qPropertySetResource>(0x54606C31u);
  UFG::qResourceHandle::Init(this, 0x54606C31u, resource_uid, v2);
}

// File Line: 310
// RVA: 0x1F9700
void __fastcall UFG::qPropertySetHandle::InitTempNonResourcePropSet(
        UFG::qPropertySetHandle *this,
        UFG::qResourceData *parent)
{
  UFG::qArray<unsigned long,0> *Name; // rax

  this->mNext = 0i64;
  this->mPrev = 0i64;
  this->mData = parent;
  Name = (UFG::qArray<unsigned long,0> *)UFG::qPropertySet::GetName((UFG::qPropertySet *)parent);
  this->mNameUID = UFG::qSymbolUC::as_uint32(Name);
}

// File Line: 344
// RVA: 0x1ED340
void __fastcall UFG::qPropertyCollection::qPropertyCollection(UFG::qPropertyCollection *this)
{
  this->mPad0 = 0;
  this->mOwner.mOffset = 0i64;
}

// File Line: 349
// RVA: 0x1ED330
void __fastcall UFG::qPropertyCollection::qPropertyCollection(
        UFG::qPropertyCollection *this,
        MemImageLoadFlag __formal)
{
  ;
}

// File Line: 353
// RVA: 0x1FE280
void __fastcall UFG::qPropertyCollection::SetOwner(UFG::qPropertyCollection *this, UFG::qPropertySet *owningSet)
{
  UFG::qOffset64<UFG::qPropertyCollection *> *p_mOwner; // [rsp+0h] [rbp-18h]
  char *v3; // [rsp+8h] [rbp-10h]

  p_mOwner = &this->mOwner;
  if ( owningSet )
    v3 = (char *)((char *)owningSet - (char *)p_mOwner);
  else
    v3 = 0i64;
  p_mOwner->mOffset = (__int64)v3;
  this->mFlags &= ~0x20u;
  this->mFlags |= 0x10u;
}

// File Line: 360
// RVA: 0x1FE200
void __fastcall UFG::qPropertyCollection::SetOwner(UFG::qPropertyCollection *this, UFG::qPropertyList *owningList)
{
  UFG::qOffset64<UFG::qPropertyCollection *> *p_mOwner; // [rsp+0h] [rbp-18h]
  char *v3; // [rsp+8h] [rbp-10h]

  p_mOwner = &this->mOwner;
  if ( owningList )
    v3 = (char *)((char *)owningList - (char *)p_mOwner);
  else
    v3 = 0i64;
  p_mOwner->mOffset = (__int64)v3;
  this->mFlags &= ~0x10u;
  this->mFlags |= 0x20u;
}

// File Line: 371
// RVA: 0x146BE70
__int64 UFG::_dynamic_initializer_for__gPropertySetInventory__()
{
  UFG::qPropertySetInventory::qPropertySetInventory(&UFG::gPropertySetInventory);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gPropertySetInventory__);
}

// File Line: 375
// RVA: 0x1EDDA0
void __fastcall UFG::qPropertySetInventory::qPropertySetInventory(UFG::qPropertySetInventory *this)
{
  UFG::qResourceInventory::qResourceInventory(this, "qPropertySetInventory", 0x54606C31u, 0x5B9BF81Eu, 0, 0);
  this->vfptr = (UFG::qResourceInventoryVtbl *)&UFG::qPropertySetInventory::`vftable;
  this->mPurgedResources.p = 0i64;
  this->mPurgedResources.size = 0;
  this->mPurgedResources.capacity = 0;
}

// File Line: 399
// RVA: 0x1EFAB0
void __fastcall UFG::qPropertySetInventory::Add(
        UFG::qPropertySetInventory *this,
        UFG::qPropertySetResource *resource_data)
{
  UFG::qPropertySet *PropertySet; // rax
  unsigned int i; // [rsp+20h] [rbp-48h]
  int v5; // [rsp+30h] [rbp-38h]
  int Size; // [rsp+34h] [rbp-34h]
  UFG::qPropertySetResource *v7; // [rsp+48h] [rbp-20h]

  if ( !(unsigned __int8)UFG::qPropertySetResource::IsMemImaged(resource_data) )
    goto LABEL_16;
  Size = BasicArrayImplementation<hkDataArrayImpl *>::getSize((BasicArrayImplementation<hkDataObjectImpl *> *)resource_data);
  for ( i = 0; i < this->mPurgedResources.size; ++i )
  {
    if ( Size == this->mPurgedResources.p[i] )
    {
      v5 = i;
      goto LABEL_8;
    }
  }
  v5 = -1;
LABEL_8:
  if ( v5 == -1 )
  {
LABEL_16:
    if ( UFG::qPropertySetResource::GetFlags(resource_data, 1) )
    {
      v7 = (UFG::qPropertySetResource *)UFG::qPropertyList::operator new(
                                          (hkObjectCopier *)0xC0,
                                          (hkClass *)resource_data);
      if ( v7 )
        UFG::qPropertySetResource::qPropertySetResource(v7);
    }
    UFG::qPropertySetResource::SetFlags(resource_data, 2);
    UFG::qResourceInventory::Add(this, resource_data);
    if ( UFG::qPropertySetResource::GetFlags(resource_data, 1) )
    {
      PropertySet = UFG::qPropertySetResource::GetPropertySet(resource_data);
      UFG::PostLoadSchemaCreateCheck(PropertySet, 0i64, 0i64);
    }
  }
}

// File Line: 430
// RVA: 0x1FB780
void __fastcall UFG::qPropertySetInventory::Remove(
        UFG::qPropertySetInventory *this,
        UFG::qPropertySetResource *resource_data)
{
  if ( (unsigned int)UFG::qPropertySetResource::GetFlags(resource_data, 2) )
  {
    UFG::qResourceInventory::Remove(this, resource_data);
    UFG::qPropertySetResource::ClearFlags(resource_data, 2);
    if ( (unsigned int)UFG::qPropertySetResource::GetFlags(resource_data, 1) )
      UFG::qPropertySetResource::~qPropertySetResource(resource_data);
  }
}

// File Line: 576
// RVA: 0x1EDE70
void __fastcall UFG::qPropertySetResource::qPropertySetResource(UFG::qPropertySetResource *this, const char *set_name)
{
  unsigned int v2; // eax
  AMD_HD3D result; // [rsp+20h] [rbp-38h] BYREF
  UFG::qSymbol *name; // [rsp+40h] [rbp-18h]
  __int64 v5; // [rsp+48h] [rbp-10h]

  v5 = -2i64;
  v2 = UFG::qStringHash32(set_name, 0xFFFFFFFF);
  UFG::qResourceData::qResourceData(this, 0x54606C31u, v2, set_name);
  result.mExtension = (IAmdDxExt *)UFG::qSymbol::create_from_string((UFG::qSymbol *)&result, set_name);
  name = (UFG::qSymbol *)result.mExtension;
  UFG::qPropertySet::qPropertySet(&this->mData, (UFG::qSymbol *)result.mExtension);
  _(&result);
  this->mFlags = 0;
  this->mSourceCRC = -1;
  *(_QWORD *)&result.mWidth = &this->mNameString;
  result.mStereo = 0i64;
  this->mNameString.mOffset = 0i64;
  UFG::qPropertyCollection::SetFlags(&this->mData, 0x10000);
  UFG::qPropertySet::SetType(&this->mData, F5_1Pt2_512);
  UFG::qPropertySetResource::SetName(this, set_name);
}

// File Line: 588
// RVA: 0x1EDE30
void __fastcall UFG::qPropertySetResource::qPropertySetResource(UFG::qPropertySetResource *this)
{
  UFG::qResourceData::qResourceData(this);
  UFG::qPropertySet::qPropertySet(&this->mData);
}

// File Line: 594
// RVA: 0x1EEBE0
void __fastcall UFG::qPropertySetResource::~qPropertySetResource(UFG::qPropertySetResource *this)
{
  if ( !UFG::qPropertySetResource::GetFlags(this, 1) )
    UFG::qPropertySetResource::SetName(this, 0i64);
  UFG::qPropertySet::~qPropertySet(&this->mData);
  UFG::qResourceData::~qResourceData(this);
}

// File Line: 602
// RVA: 0x1FE060
void __fastcall UFG::qPropertySetResource::SetName(UFG::qPropertySetResource *this, const char *set_name)
{
  int v2; // [rsp+30h] [rbp-48h]
  char *dest; // [rsp+38h] [rbp-40h]
  char *v4; // [rsp+40h] [rbp-38h]
  UFG::qOffset64<char const *> *p_mNameString; // [rsp+58h] [rbp-20h]
  __int64 v6; // [rsp+68h] [rbp-10h]

  if ( !(unsigned int)UFG::qPropertySetResource::GetFlags(this, 1) )
  {
    if ( this->mNameString.mOffset )
      v4 = (char *)&this->mNameString + this->mNameString.mOffset;
    else
      v4 = 0i64;
    if ( v4 )
    {
      if ( this->mNameString.mOffset )
        UFG::qPropertySet_Free((char *)&this->mNameString + this->mNameString.mOffset);
      else
        UFG::qPropertySet_Free(0i64);
      this->mNameString.mOffset = 0i64;
    }
    if ( set_name )
    {
      v2 = UFG::qStringLength(set_name);
      dest = (char *)UFG::qPropertySet_Allocate(v2 + 1, "qPropertySetResource name", 0);
      UFG::qStringCopy(dest, set_name);
      p_mNameString = &this->mNameString;
      if ( dest )
        v6 = dest - (char *)p_mNameString;
      else
        v6 = 0i64;
      p_mNameString->mOffset = v6;
    }
  }
}

// File Line: 622
// RVA: 0x1FC850
void __fastcall UFG::qPropertySetResource::Rename(UFG::qPropertySetResource *this, const char *nameString)
{
  bool v2; // [rsp+20h] [rbp-28h]
  AMD_HD3D result; // [rsp+24h] [rbp-24h] BYREF

  *(_QWORD *)&result.mHeight = -2i64;
  v2 = UFG::PropertySetCache::Contains(this);
  if ( v2 )
    UFG::PropertySetCache::Remove(this);
  UFG::qSymbol::create_from_string((UFG::qSymbol *)&result, nameString);
  UFG::qPropertySetResource::SetName(this, nameString);
  result.mLineOffset = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)&result);
  UFG::qBaseNodeRB::SetUID(&this->mNode, result.mLineOffset);
  UFG::qResourceData::SetDebugName(this, nameString);
  UFG::qPropertySet::SetName(&this->mData, (UFG::qSymbol *)&result);
  if ( v2 )
    UFG::PropertySetCache::Add(this);
  _(&result);
}

// File Line: 651
// RVA: 0x1EDB90
void __fastcall UFG::qPropertySet::qPropertySet(UFG::qPropertySet *this, UFG::qSymbol *name)
{
  UFG::qPropertyCollection::qPropertyCollection(this);
  this->mPrev = &this->UFG::qNode<UFG::qPropertySet,UFG::qPropertySet>;
  this->mNext = &this->UFG::qNode<UFG::qPropertySet,UFG::qPropertySet>;
  UFG::qSymbol::qSymbol(&this->mName, name);
  BackInfo::BackInfo(&this->mSchemaName);
  this->mParents.mOffset = 0i64;
  this->mProperties.mOffset = 0i64;
  this->mValues.mOffset = 0i64;
  this->mDefaultBits.mOffset = 0i64;
  this->mNumDataBytes = 0;
  this->mRefCount = 0;
  this->mNumProperties = 0;
  this->mNumParents = 0;
  this->mFlags = 2;
  this->mPropertyMask = -1;
  this->mParentMask = -1;
  UFG::qSymbol::set_null(&this->mSchemaName);
}

// File Line: 671
// RVA: 0x1F4140
UFG::qPropertySet *__fastcall UFG::qPropertySet::CreateContainedSet(UFG::qSymbol *name, const char *dbg_tag)
{
  __int64 v2; // rax
  UFG::qPropertySet *v4; // [rsp+20h] [rbp-38h]

  v4 = (UFG::qPropertySet *)UFG::qPropertySet::operator new(0x58ui64, dbg_tag);
  if ( !v4 )
    return 0i64;
  UFG::qPropertySet::qPropertySet(v4, name);
  return (UFG::qPropertySet *)v2;
}

// File Line: 677
// RVA: 0x1F46E0
UFG::qPropertySet *__fastcall UFG::qPropertySet::CreateResourceSet(UFG::qSymbolUC *name, const char *dbg_tag)
{
  char *v2; // rax
  UFG::qPropertySetResource *v3; // rax
  UFG::qPropertySetResource *v5; // [rsp+20h] [rbp-38h]
  UFG::qPropertySetResource *v6; // [rsp+28h] [rbp-30h]

  v5 = (UFG::qPropertySetResource *)UFG::qPropertySet::operator new(0xC0ui64, dbg_tag);
  if ( v5 )
  {
    v2 = UFG::qSymbol::as_cstr_dbg(name);
    UFG::qPropertySetResource::qPropertySetResource(v5, v2);
    v6 = v3;
  }
  else
  {
    v6 = 0i64;
  }
  return UFG::qPropertySetResource::GetPropertySet(v6);
}

// File Line: 684
// RVA: 0x1F2520
UFG::qPropertySet *__fastcall UFG::qPropertySet::Clone(UFG::qPropertySet *this)
{
  UFG::qSymbol *Name; // rax
  UFG::qPropertySet *v2; // rax
  UFG::qPropertySet *v4; // [rsp+20h] [rbp-38h]
  UFG::qPropertySet *v5; // [rsp+28h] [rbp-30h]

  v4 = (UFG::qPropertySet *)UFG::qPropertySet::operator new(0x58ui64);
  if ( v4 )
  {
    Name = UFG::qPropertySet::GetName(this);
    UFG::qPropertySet::qPropertySet(v4, Name);
    v5 = v2;
  }
  else
  {
    v5 = 0i64;
  }
  UFG::qPropertySet::CopyFrom(v5, this, 1);
  return v5;
}

// File Line: 691
// RVA: 0x1F50F0
void __fastcall UFG::qPropertySet::Destroy(UFG::qPropertySet *this)
{
  UFG::qPropertySetResource *Resource; // [rsp+20h] [rbp-48h]

  if ( !UFG::qPropertyCollection::IsMemImaged(this) )
  {
    if ( (unsigned __int8)UFG::qPropertySet::IsResourceSet(this) )
    {
      Resource = UFG::qPropertySet::GetResource(this);
      if ( Resource )
      {
        UFG::qPropertySetResource::~qPropertySetResource(Resource);
        UFG::qPropertySet::operator delete((char *)Resource, 0xC0ui64);
      }
    }
    else if ( this )
    {
      UFG::qPropertySet::`scalar deleting destructor(this, 1);
    }
  }
}

// File Line: 709
// RVA: 0x1FB1A0
UFG::qSymbol *__fastcall UFG::RecursiveSchemaGet(UFG::qPropertySet *propertySet)
{
  unsigned int parent_index; // [rsp+20h] [rbp-28h]
  unsigned int v3; // [rsp+24h] [rbp-24h]
  UFG::qSymbol *SchemaName; // [rsp+28h] [rbp-20h]
  UFG::qSymbol *v5; // [rsp+30h] [rbp-18h]
  UFG::qPropertySet *propertySeta; // [rsp+38h] [rbp-10h]

  SchemaName = UFG::qPropertySet::GetSchemaName(propertySet);
  if ( UFG::qSymbol::operator!=(SchemaName, &UFG::gNullQSymbol) )
    return SchemaName;
  if ( (unsigned int)UFG::qPropertyCollection::GetFlags(propertySet, 0x80000) )
  {
    v3 = UFG::qPropertySet::NumParents(propertySet);
    if ( v3 )
    {
      for ( parent_index = 0; parent_index < v3; ++parent_index )
      {
        propertySeta = (UFG::qPropertySet *)UFG::qPropertySet::GetParentFromIdx(propertySet, parent_index);
        v5 = UFG::RecursiveSchemaGet(propertySeta);
        if ( UFG::qSymbol::operator!=(v5, &UFG::gNullQSymbol) )
          return v5;
      }
    }
  }
  return &UFG::gNullQSymbol;
}

// File Line: 744
// RVA: 0x1ED4E0
void __fastcall UFG::qPropertySet::qPropertySet(UFG::qPropertySet *this)
{
  MemImageLoadFlag *v1; // rax
  UFG::qSymbol *v2; // rax
  __int64 v3; // rax
  __int64 v4; // rax
  unsigned int i; // [rsp+20h] [rbp-178h]
  unsigned int j; // [rsp+24h] [rbp-174h]
  UFG::qPropertySet *v7; // [rsp+30h] [rbp-168h]
  UFG::qProperty *v8; // [rsp+40h] [rbp-158h]
  __int64 v9; // [rsp+58h] [rbp-140h]
  unsigned int mNumParents; // [rsp+60h] [rbp-138h]
  UFG::qResourceHandle *v11; // [rsp+80h] [rbp-118h]
  char *v12; // [rsp+88h] [rbp-110h]
  unsigned int mNumProperties; // [rsp+90h] [rbp-108h]
  char *v14; // [rsp+98h] [rbp-100h]
  __int64 v15; // [rsp+A8h] [rbp-F0h]
  char *v16; // [rsp+B8h] [rbp-E0h]
  __int64 v17; // [rsp+C0h] [rbp-D8h]
  char *v18; // [rsp+C8h] [rbp-D0h]
  UFG::qNode<UFG::qPropertySet,UFG::qPropertySet> *mPrev; // [rsp+D0h] [rbp-C8h]
  hkClass *v20; // [rsp+D8h] [rbp-C0h]
  UFG::qOffset64<UFG::qProperty *> *p_mProperties; // [rsp+E0h] [rbp-B8h]
  UFG::qPropertySet *v22; // [rsp+E8h] [rbp-B0h]
  __int64 v23; // [rsp+F0h] [rbp-A8h]
  char *v24; // [rsp+F8h] [rbp-A0h]
  __int64 v25; // [rsp+100h] [rbp-98h]
  hkClass *v26; // [rsp+108h] [rbp-90h]
  UFG::SchemaDef *Schema; // [rsp+110h] [rbp-88h]
  UFG::qPropertyList *v28; // [rsp+118h] [rbp-80h]
  MemImageLoadFlag v29; // [rsp+120h] [rbp-78h] BYREF
  hkClass *v30; // [rsp+128h] [rbp-70h]
  hkClass *v31; // [rsp+130h] [rbp-68h]
  MemImageLoadFlag v32; // [rsp+138h] [rbp-60h] BYREF
  char *v33; // [rsp+140h] [rbp-58h]
  MemImageLoadFlag v34; // [rsp+148h] [rbp-50h] BYREF
  UFG::qNode<UFG::qPropertySet,UFG::qPropertySet> *v35; // [rsp+150h] [rbp-48h]
  UFG::qSymbol *name; // [rsp+158h] [rbp-40h]
  __int64 v37; // [rsp+160h] [rbp-38h]
  __int64 v38; // [rsp+168h] [rbp-30h]
  __int64 v39; // [rsp+170h] [rbp-28h]
  __int64 v40; // [rsp+178h] [rbp-20h]
  __int64 v41; // [rsp+180h] [rbp-18h]

  v37 = -2i64;
  UFG::PersistentData::Float::Float(&v29);
  UFG::qPropertyCollection::qPropertyCollection(this, (MemImageLoadFlag)v1->flag);
  this->mPrev = &this->UFG::qNode<UFG::qPropertySet,UFG::qPropertySet>;
  this->mNext = &this->UFG::qNode<UFG::qPropertySet,UFG::qPropertySet>;
  UFG::PersistentData::Float::Float(&v34);
  Assembly::GetRCX(&this->mName);
  UFG::PersistentData::Float::Float(&v32);
  Assembly::GetRCX(&this->mSchemaName);
  mNumParents = this->mNumParents;
  for ( i = 0; i < mNumParents; ++i )
  {
    if ( this->mParents.mOffset )
      v24 = (char *)&this->mParents + this->mParents.mOffset;
    else
      v24 = 0i64;
    v11 = (UFG::qResourceHandle *)UFG::qPropertyList::operator new((hkObjectCopier *)0x20, (hkClass *)&v24[32 * i]);
    if ( v11 )
    {
      UFG::qResourceHandle::qResourceHandle(v11);
      v23 = (__int64)v11;
    }
    else
    {
      v23 = 0i64;
    }
    v40 = v23;
    UFG::qPropertySetHandle::Init((UFG::qPropertySetHandle *)&v24[32 * i]);
  }
  if ( (unsigned int)UFG::qPropertyCollection::GetFlags(this, 0x80000) )
  {
    name = UFG::RecursiveSchemaGet(this);
    UFG::qPropertySet::SetSchemaName(this, name);
  }
  if ( UFG::qSymbol::operator!=(&this->mSchemaName, &UFG::gNullQSymbol) )
  {
    v2 = UFG::qPropertySet::GetName(this);
    if ( UFG::qSymbol::operator!=(&this->mSchemaName, v2) )
    {
      Schema = UFG::PropertySetManager::GetSchema(&this->mSchemaName);
      v38 = 16i64;
      v35 = &this->UFG::qNode<UFG::qPropertySet,UFG::qPropertySet>;
      mPrev = Schema->mPropertySetInstances.mNode.mPrev;
      mPrev->mNext = &this->UFG::qNode<UFG::qPropertySet,UFG::qPropertySet>;
      this->mPrev = mPrev;
      this->mNext = &Schema->mPropertySetInstances.mNode;
      Schema->mPropertySetInstances.mNode.mPrev = &this->UFG::qNode<UFG::qPropertySet,UFG::qPropertySet>;
      v7 = UFG::qPropertySetHandle::Get(&Schema->mPropertySet);
      p_mProperties = &this->mProperties;
      if ( v7->mProperties.mOffset )
        v9 = (__int64)&v7->mProperties + v7->mProperties.mOffset;
      else
        v9 = 0i64;
      if ( v9 )
        v25 = v9 - (_QWORD)p_mProperties;
      else
        v25 = 0i64;
      p_mProperties->mOffset = v25;
      this->mNumDataBytes = v7->mNumDataBytes;
      this->mNumProperties = v7->mNumProperties;
      this->mPropertyMask = v7->mPropertyMask;
    }
  }
  if ( (this->mFlags & 0x400000) != 0 )
  {
    if ( this->mProperties.mOffset )
      v16 = (char *)&this->mProperties + this->mProperties.mOffset;
    else
      v16 = 0i64;
    v33 = v16;
    if ( this->mValues.mOffset )
      v18 = (char *)&this->mValues + this->mValues.mOffset;
    else
      v18 = 0i64;
    mNumProperties = this->mNumProperties;
    for ( j = 0; j < mNumProperties; ++j )
    {
      v8 = (UFG::qProperty *)&v33[8 * j];
      if ( (unsigned int)UFG::qProperty::GetTypeUID(v8) == 26 )
      {
        v12 = &v18[(unsigned int)UFG::qProperty::GetDataOffset(v8)];
        if ( *(_QWORD *)v12 )
          v20 = (hkClass *)&v12[*(_QWORD *)v12];
        else
          v20 = 0i64;
        v30 = v20;
        v22 = (UFG::qPropertySet *)UFG::qPropertyList::operator new((hkObjectCopier *)0x58, v20);
        if ( v22 )
        {
          UFG::qPropertySet::qPropertySet(v22);
          v15 = v3;
        }
        else
        {
          v15 = 0i64;
        }
        v39 = v15;
      }
      else if ( (unsigned int)UFG::qProperty::GetTypeUID(v8) == 25 )
      {
        v14 = &v18[(unsigned int)UFG::qProperty::GetDataOffset(v8)];
        if ( *(_QWORD *)v14 )
          v26 = (hkClass *)&v14[*(_QWORD *)v14];
        else
          v26 = 0i64;
        v31 = v26;
        v28 = (UFG::qPropertyList *)UFG::qPropertyList::operator new((hkObjectCopier *)0x30, v26);
        if ( v28 )
        {
          UFG::qPropertyList::qPropertyList(v28);
          v17 = v4;
        }
        else
        {
          v17 = 0i64;
        }
        v41 = v17;
      }
    }
  }
}

// File Line: 818
// RVA: 0x1EE800
void __fastcall UFG::qPropertySet::~qPropertySet(UFG::qPropertySet *this)
{
  unsigned int j; // [rsp+20h] [rbp-B8h]
  unsigned int i; // [rsp+24h] [rbp-B4h]
  UFG::qProperty *v3; // [rsp+28h] [rbp-B0h]
  unsigned int mNumProperties; // [rsp+40h] [rbp-98h]
  char *v5; // [rsp+48h] [rbp-90h]
  char *v6; // [rsp+58h] [rbp-80h]
  char *v7; // [rsp+60h] [rbp-78h]
  char *v8; // [rsp+78h] [rbp-60h]
  UFG::qPropertySet *v9; // [rsp+90h] [rbp-48h]
  char *v10; // [rsp+98h] [rbp-40h]
  UFG::qPropertyList *v11; // [rsp+A0h] [rbp-38h]

  if ( this->mParents.mOffset )
    v10 = (char *)&this->mParents + this->mParents.mOffset;
  else
    v10 = 0i64;
  for ( i = 0; i < this->mNumParents; ++i )
    UFG::qPropertySetHandle::Close((UFG::qPropertySetHandle *)&v10[32 * i]);
  if ( (unsigned int)UFG::qPropertyCollection::GetFlags(this, 1) )
  {
    if ( (this->mFlags & 0x400000) != 0 )
    {
      if ( this->mProperties.mOffset )
        v7 = (char *)&this->mProperties + this->mProperties.mOffset;
      else
        v7 = 0i64;
      if ( this->mValues.mOffset )
        v8 = (char *)&this->mValues + this->mValues.mOffset;
      else
        v8 = 0i64;
      mNumProperties = this->mNumProperties;
      for ( j = 0; j < mNumProperties; ++j )
      {
        v3 = (UFG::qProperty *)&v7[8 * j];
        if ( (unsigned int)UFG::qProperty::GetTypeUID(v3) == 26 )
        {
          v5 = &v8[(unsigned int)UFG::qProperty::GetDataOffset(v3)];
          if ( *(_QWORD *)v5 )
            v9 = (UFG::qPropertySet *)&v5[*(_QWORD *)v5];
          else
            v9 = 0i64;
          UFG::qPropertySet::`scalar deleting destructor(v9, 0);
        }
        else if ( (unsigned int)UFG::qProperty::GetTypeUID(v3) == 25 )
        {
          v6 = &v8[(unsigned int)UFG::qProperty::GetDataOffset(v3)];
          if ( *(_QWORD *)v6 )
            v11 = (UFG::qPropertyList *)&v6[*(_QWORD *)v6];
          else
            v11 = 0i64;
          UFG::qPropertyList::`scalar deleting destructor(v11, 0);
        }
      }
    }
  }
  else
  {
    UFG::qPropertySet::RemovePropertiesAllLocal(this);
    UFG::qPropertySet_Free(v10);
    this->mParents.mOffset = 0i64;
    this->mNumParents = 0;
  }
  UFG::qPropertyCollection::SetFlags(this, 8);
  _((AMD_HD3D *)&this->mSchemaName);
  _((AMD_HD3D *)&this->mName);
  UFG::qNode<UFG::qPropertySet,UFG::qPropertySet>::~qNode<UFG::qPropertySet,UFG::qPropertySet>(&this->UFG::qNode<UFG::qPropertySet,UFG::qPropertySet>);
}

// File Line: 874
// RVA: 0x1F29A0
void __fastcall UFG::qPropertySet::CopyFrom(UFG::qPropertySet *this, UFG::qPropertySet *source_set, bool copyParents)
{
  UFG::qPropertySet::Type Type; // eax
  UFG::qSymbol *Name; // rax
  int numProperties; // [rsp+20h] [rbp-1C8h]
  unsigned int i; // [rsp+24h] [rbp-1C4h]
  unsigned int j; // [rsp+28h] [rbp-1C0h]
  UFG::qProperty *v8; // [rsp+30h] [rbp-1B8h]
  unsigned int mNumParents; // [rsp+38h] [rbp-1B0h]
  unsigned int count; // [rsp+3Ch] [rbp-1ACh]
  char *v11; // [rsp+40h] [rbp-1A8h]
  UFG::qProperty *dest; // [rsp+50h] [rbp-198h]
  int v13; // [rsp+58h] [rbp-190h]
  UFG::qPropertySet *ContainedSet; // [rsp+60h] [rbp-188h]
  unsigned int *defaults; // [rsp+68h] [rbp-180h]
  UFG::qPropertyList *v16; // [rsp+78h] [rbp-170h]
  UFG::qResourceHandle *v17; // [rsp+98h] [rbp-150h]
  char *v18; // [rsp+A0h] [rbp-148h]
  unsigned int mNumProperties; // [rsp+A8h] [rbp-140h]
  char *v20; // [rsp+B0h] [rbp-138h]
  UFG::qPropertySetHandle *v21; // [rsp+B8h] [rbp-130h]
  char *v22; // [rsp+C0h] [rbp-128h]
  void *v23; // [rsp+D0h] [rbp-118h]
  UFG::qOffset64<UFG::qPropertySetHandle *> *p_mParents; // [rsp+D8h] [rbp-110h]
  signed __int64 v25; // [rsp+E0h] [rbp-108h]
  char *v26; // [rsp+F8h] [rbp-F0h]
  UFG::qPropertyList *v27; // [rsp+100h] [rbp-E8h]
  char *v28; // [rsp+108h] [rbp-E0h]
  char *v29; // [rsp+110h] [rbp-D8h]
  UFG::qOffset64<UFG::qProperty *> *p_mProperties; // [rsp+118h] [rbp-D0h]
  signed __int64 v31; // [rsp+120h] [rbp-C8h]
  UFG::qOffset64<unsigned long *> *p_mDefaultBits; // [rsp+128h] [rbp-C0h]
  const char *v33; // [rsp+130h] [rbp-B8h]
  char *v34; // [rsp+138h] [rbp-B0h]
  __int64 v35; // [rsp+148h] [rbp-A0h]
  signed __int64 *v36; // [rsp+150h] [rbp-98h]
  char *v37; // [rsp+158h] [rbp-90h]
  signed __int64 v38; // [rsp+160h] [rbp-88h]
  __int64 v39; // [rsp+168h] [rbp-80h]
  UFG::qOffset64<unsigned char *> *p_mValues; // [rsp+170h] [rbp-78h]
  UFG::qPropertySet *v41; // [rsp+178h] [rbp-70h]
  __int64 v42; // [rsp+180h] [rbp-68h]
  __int64 v43; // [rsp+190h] [rbp-58h]
  char *v44; // [rsp+198h] [rbp-50h]

  UFG::qPropertySet::RemovePropertiesAllLocal(this);
  if ( copyParents )
  {
    UFG::qPropertySet::RemoveParentsAll(this);
    mNumParents = source_set->mNumParents;
    if ( source_set->mParents.mOffset )
      v26 = (char *)&source_set->mParents + source_set->mParents.mOffset;
    else
      v26 = 0i64;
    v21 = (UFG::qPropertySetHandle *)UFG::qPropertySet_Allocate(32 * mNumParents, "qPropertySetHandle", 0);
    for ( i = 0; i < mNumParents; ++i )
    {
      v17 = (UFG::qResourceHandle *)UFG::qPropertyList::operator new((hkObjectCopier *)0x20, (hkClass *)&v21[i]);
      if ( v17 )
        UFG::qResourceHandle::qResourceHandle(v17);
      UFG::qPropertySetHandle::CopyFrom(&v21[i], (UFG::qPropertySetHandle *)&v26[32 * i]);
    }
    p_mParents = &this->mParents;
    if ( v21 )
      v39 = (char *)v21 - (char *)p_mParents;
    else
      v39 = 0i64;
    p_mParents->mOffset = v39;
    this->mNumParents = mNumParents;
    this->mParentMask = -1;
  }
  Type = (unsigned int)UFG::qPropertySet::GetType(source_set);
  UFG::qPropertySet::SetType(this, Type);
  UFG::qSymbol::qSymbol(&this->mSchemaName, &source_set->mSchemaName);
  numProperties = source_set->mNumProperties;
  if ( source_set->mProperties.mOffset )
    v28 = (char *)&source_set->mProperties + source_set->mProperties.mOffset;
  else
    v28 = 0i64;
  dest = (UFG::qProperty *)UFG::qPropertySet_Allocate(
                             (8 * numProperties + 15) & 0xFFFFFFF0,
                             "PropertySetProps",
                             0x1000u);
  if ( source_set->mDefaultBits.mOffset )
    v44 = (char *)&source_set->mDefaultBits + source_set->mDefaultBits.mOffset;
  else
    v44 = 0i64;
  defaults = (unsigned int *)UFG::qPropertySet_Allocate(4 * ((numProperties + 31) / 0x20u), "PropertySetProps", 0);
  UFG::qMemCopy(dest, v28, 8 * numProperties);
  UFG::qMemCopy(defaults, v44, 4 * ((numProperties + 31) / 0x20u));
  if ( (source_set->mFlags & 1) != 0 )
    UFG::qPropertySet::SortForDynamic(defaults, dest, numProperties);
  p_mProperties = &this->mProperties;
  if ( dest )
    v43 = (char *)dest - (char *)p_mProperties;
  else
    v43 = 0i64;
  p_mProperties->mOffset = v43;
  p_mDefaultBits = &this->mDefaultBits;
  if ( defaults )
    v42 = (char *)defaults - (char *)p_mDefaultBits;
  else
    v42 = 0i64;
  p_mDefaultBits->mOffset = v42;
  this->mNumProperties = numProperties;
  this->mPropertyMask = -1;
  count = source_set->mNumDataBytes;
  if ( source_set->mValues.mOffset )
    v34 = (char *)&source_set->mValues + source_set->mValues.mOffset;
  else
    v34 = 0i64;
  v11 = (char *)UFG::qPropertySet_Allocate((count + 15) & 0xFFFFFFF0, "PropertyData", 0x1000u);
  UFG::qMemCopy(v11, v34, count);
  p_mValues = &this->mValues;
  if ( v11 )
    v35 = v11 - (char *)p_mValues;
  else
    v35 = 0i64;
  p_mValues->mOffset = v35;
  this->mNumDataBytes = count;
  mNumProperties = this->mNumProperties;
  for ( j = 0; j < mNumProperties; ++j )
  {
    v8 = &dest[j];
    if ( (unsigned int)UFG::qProperty::GetTypeUID(v8) == 26 )
    {
      v18 = &v34[(unsigned int)UFG::qProperty::GetDataOffset(v8)];
      if ( *(_QWORD *)v18 )
        v41 = (UFG::qPropertySet *)&v18[*(_QWORD *)v18];
      else
        v41 = 0i64;
      Name = UFG::qPropertySet::GetName(v41);
      ContainedSet = UFG::qPropertySet::CreateContainedSet(Name, "qPropertySet");
      v37 = &v11[(unsigned int)UFG::qProperty::GetDataOffset(v8)];
      if ( ContainedSet )
        v25 = (char *)ContainedSet - v37;
      else
        v25 = 0i64;
      *(_QWORD *)v37 = v25;
      UFG::qPropertyCollection::SetOwner(ContainedSet, this);
      UFG::qPropertySet::AddRef(ContainedSet);
      UFG::qPropertySet::CopyFrom(ContainedSet, v41, 1);
    }
    else if ( (unsigned int)UFG::qProperty::GetTypeUID(v8) == 25 )
    {
      v20 = &v34[(unsigned int)UFG::qProperty::GetDataOffset(v8)];
      if ( *(_QWORD *)v20 )
        v27 = (UFG::qPropertyList *)&v20[*(_QWORD *)v20];
      else
        v27 = 0i64;
      v16 = UFG::qPropertyList::Create("qPropertyList");
      v29 = &v11[(unsigned int)UFG::qProperty::GetDataOffset(v8)];
      if ( v16 )
        v31 = (char *)v16 - v29;
      else
        v31 = 0i64;
      *(_QWORD *)v29 = v31;
      UFG::qPropertyCollection::SetOwner(v16, this);
      UFG::qPropertyList::CopyFrom(v16, v27);
    }
    else if ( (unsigned int)UFG::qProperty::GetTypeUID(v8) == 12 )
    {
      v22 = &v34[(unsigned int)UFG::qProperty::GetDataOffset(v8)];
      if ( *(_QWORD *)v22 )
        v33 = &v22[*(_QWORD *)v22];
      else
        v33 = 0i64;
      v13 = UFG::qStringLength(v33);
      v23 = UFG::qPropertySet_Allocate(v13 + 1, "PropertyString", 0);
      UFG::qMemCopy(v23, v33, v13 + 1);
      v36 = (signed __int64 *)&v11[(unsigned int)UFG::qProperty::GetDataOffset(v8)];
      if ( v23 )
        v38 = (_BYTE *)v23 - (_BYTE *)v36;
      else
        v38 = 0i64;
      *v36 = v38;
    }
  }
}

// File Line: 1016
// RVA: 0x1FCFC0
void __fastcall UFG::qPropertySet::SetAllPropertiesToDefault(UFG::qPropertySet *this)
{
  __int64 v1; // kr00_8
  unsigned int i; // [rsp+0h] [rbp-28h]
  char *v3; // [rsp+10h] [rbp-18h]

  if ( this->mDefaultBits.mOffset )
    v3 = (char *)&this->mDefaultBits + this->mDefaultBits.mOffset;
  else
    v3 = 0i64;
  v1 = this->mNumProperties + 31;
  for ( i = 0; i < ((BYTE4(v1) & 0x1F) + (int)v1) >> 5; ++i )
    *(_DWORD *)&v3[4 * i] = -1;
}

// File Line: 1028
// RVA: 0x1FE520
void __fastcall UFG::qPropertySet::SetPropertyDefaultLocalIdx(
        UFG::qPropertySet *this,
        unsigned int index,
        bool isDefault)
{
  int v3; // eax
  unsigned int v4; // [rsp+0h] [rbp-38h]
  int v5; // [rsp+4h] [rbp-34h]
  char *v6; // [rsp+20h] [rbp-18h]

  if ( this->mDefaultBits.mOffset )
    v6 = (char *)&this->mDefaultBits + this->mDefaultBits.mOffset;
  else
    v6 = 0i64;
  v4 = index / 0x20;
  v5 = 1 << (index % 0x20);
  if ( isDefault )
    v3 = v5 | *(_DWORD *)&v6[4 * v4];
  else
    v3 = ~v5 & *(_DWORD *)&v6[4 * v4];
  *(_DWORD *)&v6[4 * v4] = v3;
}

// File Line: 1048
// RVA: 0x1FE450
char __fastcall UFG::qPropertySet::SetPropertyDefaultLocal(
        UFG::qPropertySet *this,
        UFG::qArray<unsigned long,0> *propertyName,
        bool isDefault)
{
  unsigned int index; // [rsp+20h] [rbp-38h]
  int v5; // [rsp+28h] [rbp-30h]
  char *v6; // [rsp+38h] [rbp-20h]

  v5 = UFG::qSymbolUC::as_uint32(propertyName);
  if ( this->mProperties.mOffset )
    v6 = (char *)&this->mProperties + this->mProperties.mOffset;
  else
    v6 = 0i64;
  for ( index = 0; index < this->mNumProperties; ++index )
  {
    if ( *(_DWORD *)&v6[8 * index + 4] == v5 )
    {
      UFG::qPropertySet::SetPropertyDefaultLocalIdx(this, index, isDefault);
      return 1;
    }
  }
  return 0;
}

// File Line: 1065
// RVA: 0x1F80C0
UFG::qPropertySetResource *__fastcall UFG::qPropertySet::GetResource(UFG::qPropertySet *this)
{
  if ( this && (unsigned __int8)UFG::qPropertySet::IsResourceSet(this) )
    return (UFG::qPropertySetResource *)&this[-2].mParentMask;
  else
    return 0i64;
}

// File Line: 1088
// RVA: 0x1F1C80
void __fastcall UFG::qPropertySet::AddRef(UFG::qPropertySet *this)
{
  ++this->mRefCount;
}

// File Line: 1093
// RVA: 0x1FB2B0
void __fastcall UFG::qPropertySet::ReleaseRef(UFG::qPropertySet *this)
{
  UFG::qPropertySetResource *pPropResource; // [rsp+28h] [rbp-40h]

  if ( this->mRefCount )
    --this->mRefCount;
  if ( !this->mRefCount && !(unsigned __int8)UFG::qPropertyCollection::IsMemImaged(this) )
  {
    if ( (unsigned __int8)UFG::qPropertySet::IsResourceSet(this) == 1 )
    {
      pPropResource = UFG::qPropertySet::GetResource(this);
      if ( !UFG::PropertySetCache::Contains(pPropResource) )
      {
        if ( pPropResource )
        {
          UFG::qPropertySetResource::~qPropertySetResource(pPropResource);
          UFG::qPropertySet::operator delete((char *)pPropResource, 0xC0ui64);
        }
      }
    }
    else if ( this )
    {
      UFG::qPropertySet::`scalar deleting destructor(this, 1);
    }
  }
}

// File Line: 1129
// RVA: 0x1FA4B0
__int64 __fastcall UFG::qPropertySet::NumParents(UFG::qPropertySet *this)
{
  return this->mNumParents;
}

// File Line: 1152
// RVA: 0x1F6FB0
UFG::qResourceData *__fastcall UFG::qPropertySet::GetParentFromIdx(UFG::qPropertySet *this, unsigned int parent_index)
{
  char *v3; // [rsp+28h] [rbp-20h]

  if ( this->mParents.mOffset )
    v3 = (char *)&this->mParents + this->mParents.mOffset;
  else
    v3 = 0i64;
  return UFG::qPropertySetHandle::Get((UFG::qPropertySetHandle *)&v3[32 * parent_index]);
}

// File Line: 1168
// RVA: 0x1F7030
UFG::qPropertySet *__fastcall UFG::qPropertySet::GetParentFromName(
        UFG::qPropertySet *this,
        UFG::qArray<unsigned long,0> *propertySetName,
        UFG::qPropertyDepth depth)
{
  unsigned int i; // [rsp+20h] [rbp-48h]
  UFG::qPropertySet *v5; // [rsp+30h] [rbp-38h]
  unsigned int mNumParents; // [rsp+38h] [rbp-30h]
  int v7; // [rsp+3Ch] [rbp-2Ch]
  int Size; // [rsp+40h] [rbp-28h]
  char *v9; // [rsp+48h] [rbp-20h]
  UFG::qPropertySet *ParentFromName; // [rsp+58h] [rbp-10h]

  ++_total_parent_calls;
  v7 = this->mParentMask & UFG::qSymbolUC::as_uint32(propertySetName);
  if ( v7 == (unsigned int)UFG::qSymbolUC::as_uint32(propertySetName) )
  {
    mNumParents = this->mNumParents;
    if ( this->mParents.mOffset )
      v9 = (char *)&this->mParents + this->mParents.mOffset;
    else
      v9 = 0i64;
    for ( i = 0; i < mNumParents; ++i )
    {
      v5 = (UFG::qPropertySet *)UFG::qPropertySetHandle::Get((UFG::qPropertySetHandle *)&v9[32 * i]);
      Size = BasicArrayImplementation<hkDataArrayImpl *>::getSize((BasicArrayImplementation<hkDataObjectImpl *> *)&v9[32 * i]);
      if ( Size == (unsigned int)UFG::qSymbolUC::as_uint32(propertySetName) )
        return v5;
      if ( depth == DEPTH_RECURSE )
      {
        if ( v5 )
        {
          ParentFromName = UFG::qPropertySet::GetParentFromName(v5, (UFG::qSymbol *)propertySetName, DEPTH_RECURSE);
          if ( ParentFromName )
            return ParentFromName;
        }
      }
    }
  }
  else
  {
    ++_parent_early_outs;
  }
  return 0i64;
}

// File Line: 1205
// RVA: 0x1F9760
UFG::qPropertySetHandle *__fastcall UFG::qPropertySet::InternalAddParent(UFG::qPropertySet *this)
{
  unsigned int i; // [rsp+20h] [rbp-88h]
  unsigned int v3; // [rsp+24h] [rbp-84h]
  unsigned int j; // [rsp+28h] [rbp-80h]
  unsigned int mNumParents; // [rsp+2Ch] [rbp-7Ch]
  UFG::qPropertySetHandle *v6; // [rsp+38h] [rbp-70h]
  UFG::qResourceHandle *v7; // [rsp+40h] [rbp-68h]
  UFG::qOffset64<UFG::qPropertySetHandle *> *p_mParents; // [rsp+50h] [rbp-58h]
  __int64 v9; // [rsp+58h] [rbp-50h]
  char *v10; // [rsp+60h] [rbp-48h]

  mNumParents = this->mNumParents;
  v3 = mNumParents + 1;
  if ( this->mParents.mOffset )
    v10 = (char *)&this->mParents + this->mParents.mOffset;
  else
    v10 = 0i64;
  v6 = (UFG::qPropertySetHandle *)UFG::qPropertySet_Allocate(32 * v3, "qPropertySetHandle", 0);
  for ( i = 0; i < mNumParents; ++i )
  {
    v7 = (UFG::qResourceHandle *)UFG::qPropertyList::operator new((hkObjectCopier *)0x20, (hkClass *)&v6[i]);
    if ( v7 )
      UFG::qResourceHandle::qResourceHandle(v7);
    UFG::qPropertySetHandle::CopyFrom(&v6[i], (UFG::qPropertySetHandle *)&v10[32 * i]);
  }
  for ( j = 0; j < mNumParents; ++j )
    UFG::qPropertySetHandle::Close((UFG::qPropertySetHandle *)&v10[32 * j]);
  if ( v10 )
    UFG::qPropertySet_Free(v10);
  p_mParents = &this->mParents;
  if ( v6 )
    v9 = (char *)v6 - (char *)p_mParents;
  else
    v9 = 0i64;
  p_mParents->mOffset = v9;
  this->mNumParents = v3;
  return &v6[mNumParents];
}

// File Line: 1251
// RVA: 0x1F1A10
__int64 __fastcall UFG::qPropertySet::AddNonResourceBasedParentSet(
        UFG::qPropertySet *this,
        UFG::qPropertySet *parent_set)
{
  UFG::qSymbol *Name; // rax
  UFG::qPropertySetHandle *v4; // [rsp+20h] [rbp-18h]

  Name = UFG::qPropertySet::GetName(parent_set);
  if ( UFG::qPropertySet::GetParentIdx(this, Name) != -1 )
    return 0xFFFFFFFFi64;
  v4 = UFG::qPropertySet::InternalAddParent(this);
  UFG::qPropertySetHandle::InitTempNonResourcePropSet(v4, parent_set);
  return this->mNumParents;
}

// File Line: 1264
// RVA: 0x1F1B30
__int64 __fastcall UFG::qPropertySet::AddParent(UFG::qPropertySet *this, UFG::qPropertySet *parent)
{
  UFG::qArray<unsigned long,0> *Name; // rax

  Name = (UFG::qArray<unsigned long,0> *)UFG::qPropertySet::GetName(parent);
  return UFG::qPropertySet::AddParent(this, Name);
}

// File Line: 1269
// RVA: 0x1F1A70
__int64 __fastcall UFG::qPropertySet::AddParent(UFG::qPropertySet *this, UFG::qArray<unsigned long,0> *parent_name)
{
  unsigned int resource_uid; // [rsp+20h] [rbp-38h]
  UFG::qResourceHandle *v4; // [rsp+28h] [rbp-30h]
  hkClass *klass; // [rsp+38h] [rbp-20h]

  resource_uid = UFG::qSymbolUC::as_uint32(parent_name);
  if ( UFG::qPropertySet::GetParentIdx(this, (UFG::qSymbol *)parent_name) != -1 )
    return 0xFFFFFFFFi64;
  Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat((hkgpIndexedMesh::EdgeBarrier *)this, 0i64);
  klass = (hkClass *)UFG::qPropertySet::InternalAddParent(this);
  v4 = (UFG::qResourceHandle *)UFG::qPropertyList::operator new((hkObjectCopier *)0x20, klass);
  if ( v4 )
    UFG::qResourceHandle::qResourceHandle(v4);
  UFG::qPropertySetHandle::Init((UFG::qPropertySetHandle *)klass, resource_uid);
  return this->mNumParents;
}

// File Line: 1312
// RVA: 0x1FB9A0
void __fastcall UFG::qPropertySet::RemoveParent(UFG::qPropertySet *this, UFG::qArray<unsigned long,0> *parent_name)
{
  int v2; // [rsp+20h] [rbp-C8h]
  unsigned int v3; // [rsp+24h] [rbp-C4h]
  unsigned int k; // [rsp+28h] [rbp-C0h]
  unsigned int j; // [rsp+2Ch] [rbp-BCh]
  unsigned int i; // [rsp+30h] [rbp-B8h]
  unsigned int ParentIdx; // [rsp+34h] [rbp-B4h]
  unsigned int mNumParents; // [rsp+38h] [rbp-B0h]
  UFG::qResourceHandle *v9; // [rsp+50h] [rbp-98h]
  UFG::qResourceHandle *v10; // [rsp+60h] [rbp-88h]
  char *v11; // [rsp+78h] [rbp-70h]
  UFG::qPropertySetHandle *v12; // [rsp+A0h] [rbp-48h]

  ParentIdx = UFG::qPropertySet::GetParentIdx(this, parent_name);
  if ( ParentIdx != -1 )
  {
    Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat((hkgpIndexedMesh::EdgeBarrier *)this, 0i64);
    mNumParents = this->mNumParents;
    v3 = mNumParents - 1;
    if ( this->mParents.mOffset )
      v11 = (char *)&this->mParents + this->mParents.mOffset;
    else
      v11 = 0i64;
    if ( mNumParents == 1 )
      v12 = 0i64;
    else
      v12 = (UFG::qPropertySetHandle *)UFG::qPropertySet_Allocate(32 * v3, "qPropertySetHandle", 0);
    v2 = 0;
    for ( i = 0; i < ParentIdx; ++i )
    {
      v10 = (UFG::qResourceHandle *)UFG::qPropertyList::operator new((hkObjectCopier *)0x20, (hkClass *)&v12[v2]);
      if ( v10 )
        UFG::qResourceHandle::qResourceHandle(v10);
      UFG::qPropertySetHandle::CopyFrom(&v12[v2++], (UFG::qPropertySetHandle *)&v11[32 * i]);
    }
    for ( j = ParentIdx + 1; j < mNumParents; ++j )
    {
      v9 = (UFG::qResourceHandle *)UFG::qPropertyList::operator new((hkObjectCopier *)0x20, (hkClass *)&v12[v2]);
      if ( v9 )
        UFG::qResourceHandle::qResourceHandle(v9);
      UFG::qPropertySetHandle::CopyFrom(&v12[v2++], (UFG::qPropertySetHandle *)&v11[32 * j]);
    }
    for ( k = 0; k < mNumParents; ++k )
      UFG::qPropertySetHandle::Close((UFG::qPropertySetHandle *)&v11[32 * k]);
    UFG::qPropertySet_Free(v11);
    if ( v12 )
      this->mParents.mOffset = (char *)v12 - (char *)&this->mParents;
    else
      this->mParents.mOffset = 0i64;
    this->mNumParents = v3;
  }
}

// File Line: 1376
// RVA: 0x1FBD40
void __fastcall UFG::qPropertySet::RemoveParentsAll(UFG::qPropertySet *this)
{
  unsigned int i; // [rsp+20h] [rbp-38h]
  unsigned int mNumParents; // [rsp+24h] [rbp-34h]
  char *v3; // [rsp+30h] [rbp-28h]

  Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat((hkgpIndexedMesh::EdgeBarrier *)this, 0i64);
  mNumParents = this->mNumParents;
  if ( this->mParents.mOffset )
    v3 = (char *)&this->mParents + this->mParents.mOffset;
  else
    v3 = 0i64;
  for ( i = 0; i < mNumParents; ++i )
    UFG::qPropertySetHandle::Close((UFG::qPropertySetHandle *)&v3[32 * i]);
  UFG::qPropertySet_Free(v3);
  this->mParents.mOffset = 0i64;
  this->mNumParents = 0;
}

// File Line: 1398
// RVA: 0x1F71B0
__int64 __fastcall UFG::qPropertySet::GetParentIdx(UFG::qPropertySet *this, UFG::qArray<unsigned long,0> *parent_name)
{
  unsigned int i; // [rsp+20h] [rbp-38h]
  unsigned int mNumParents; // [rsp+24h] [rbp-34h]
  int v5; // [rsp+28h] [rbp-30h]
  char *v6; // [rsp+38h] [rbp-20h]

  v5 = UFG::qSymbolUC::as_uint32(parent_name);
  if ( this->mParents.mOffset )
    v6 = (char *)&this->mParents + this->mParents.mOffset;
  else
    v6 = 0i64;
  mNumParents = this->mNumParents;
  for ( i = 0; i < mNumParents; ++i )
  {
    if ( (unsigned int)BasicArrayImplementation<hkDataArrayImpl *>::getSize((BasicArrayImplementation<hkDataObjectImpl *> *)&v6[32 * i]) == v5 )
      return i;
  }
  return 0xFFFFFFFFi64;
}

// File Line: 1419
// RVA: 0x1F7630
signed __int64 __fastcall UFG::qPropertySet::GetPropertyIdxLocal(
        UFG::qPropertySet *this,
        unsigned int type_uid,
        unsigned int name_uid)
{
  unsigned int i; // [rsp+20h] [rbp-48h]
  int v5; // [rsp+24h] [rbp-44h]
  int v6; // [rsp+28h] [rbp-40h]
  int v7; // [rsp+2Ch] [rbp-3Ch]
  int mNumProperties; // [rsp+30h] [rbp-38h]
  UFG::qProperty *v9; // [rsp+38h] [rbp-30h]
  char *v10; // [rsp+50h] [rbp-18h]

  if ( this->mProperties.mOffset )
    v10 = (char *)&this->mProperties + this->mProperties.mOffset;
  else
    v10 = 0i64;
  mNumProperties = this->mNumProperties;
  if ( (this->mFlags & 1) != 0 )
  {
    v7 = 0;
    v6 = this->mNumProperties;
    while ( v7 <= v6 )
    {
      v5 = (v6 + v7) / 2;
      v9 = (UFG::qProperty *)&v10[8 * v5];
      if ( name_uid <= v9->mNameUID )
      {
        if ( name_uid >= v9->mNameUID )
        {
          if ( (unsigned int)UFG::qProperty::GetTypeUID(v9) == type_uid )
            return (unsigned int)v5;
          v7 = v6;
        }
        else
        {
          v6 = v5 - 1;
        }
      }
      else
      {
        v7 = v5 + 1;
      }
    }
  }
  else
  {
    for ( i = 0; (int)i < mNumProperties; ++i )
    {
      if ( *(_DWORD *)&v10[8 * i + 4] == name_uid
        && (unsigned int)UFG::qProperty::GetTypeUID((UFG::qProperty *)&v10[8 * i]) == type_uid )
      {
        return i;
      }
    }
  }
  return 0xFFFFFFFFi64;
}

// File Line: 1537
// RVA: 0x1F6F00
char *__fastcall UFG::qPropertySet::GetMemImagePtr(UFG::qPropertySet *this)
{
  if ( this->mValues.mOffset )
    return (char *)&this->mValues + this->mValues.mOffset;
  else
    return 0i64;
}

// File Line: 1564
// RVA: 0x1F8990
char *__fastcall UFG::qPropertySet::GetValuePtr(
        UFG::qPropertySet *this,
        unsigned int type_uid,
        unsigned int name_uid,
        UFG::qPropertyDepth depth,
        UFG::qPropertySet **owningSet)
{
  unsigned int i; // [rsp+30h] [rbp-B8h]
  unsigned int j; // [rsp+34h] [rbp-B4h]
  int v8; // [rsp+38h] [rbp-B0h]
  int v9; // [rsp+3Ch] [rbp-ACh]
  UFG::qProperty *v10; // [rsp+40h] [rbp-A8h]
  int v11; // [rsp+48h] [rbp-A0h]
  unsigned int mNumProperties; // [rsp+4Ch] [rbp-9Ch]
  UFG::qProperty *v13; // [rsp+50h] [rbp-98h]
  UFG::qPropertySetHandle *v14; // [rsp+60h] [rbp-88h]
  unsigned int mNumParents; // [rsp+98h] [rbp-50h]
  UFG::qProperty *v16; // [rsp+A0h] [rbp-48h]
  char *v17; // [rsp+A8h] [rbp-40h]
  char *v18; // [rsp+B0h] [rbp-38h]
  UFG::qPropertySetHandle *v19; // [rsp+B8h] [rbp-30h]
  char *v20; // [rsp+C0h] [rbp-28h]
  UFG::qPropertySet *v21; // [rsp+C8h] [rbp-20h]
  char *v22; // [rsp+D0h] [rbp-18h]
  void *ValuePtr; // [rsp+D8h] [rbp-10h]

  if ( this->mProperties.mOffset )
    v16 = (UFG::qProperty *)((char *)&this->mProperties + this->mProperties.mOffset);
  else
    v16 = 0i64;
  v10 = v16;
  mNumProperties = this->mNumProperties;
  ++_total_calls;
  if ( (this->mPropertyMask & name_uid) == name_uid )
  {
    if ( (this->mFlags & 1) != 0 )
    {
      v11 = 0;
      v9 = mNumProperties - 1;
      while ( v11 <= v9 )
      {
        v8 = (v9 + v11) / 2;
        v13 = &v16[v8];
        if ( name_uid <= v13->mNameUID )
        {
          if ( name_uid >= v13->mNameUID )
          {
            if ( (unsigned int)UFG::qProperty::GetTypeUID(v13) == type_uid )
            {
              if ( owningSet )
                *owningSet = this;
              if ( this->mValues.mOffset )
                v18 = (char *)&this->mValues + this->mValues.mOffset;
              else
                v18 = 0i64;
              return &v18[(unsigned int)UFG::qProperty::GetDataOffset(v13)];
            }
            else
            {
              if ( this->mValues.mOffset )
                v22 = (char *)&this->mValues + this->mValues.mOffset;
              else
                v22 = 0i64;
              return &v22[(unsigned int)UFG::qProperty::GetDataOffset(v13)];
            }
          }
          v9 = v8 - 1;
        }
        else
        {
          v11 = v8 + 1;
        }
      }
    }
    else
    {
      for ( i = 0; i < mNumProperties; ++i )
      {
        if ( v10->mNameUID == name_uid )
        {
          if ( (unsigned int)UFG::qProperty::GetTypeUID(v10) == type_uid )
          {
            if ( owningSet )
              *owningSet = this;
            if ( this->mValues.mOffset )
              v20 = (char *)&this->mValues + this->mValues.mOffset;
            else
              v20 = 0i64;
            return &v20[(unsigned int)UFG::qProperty::GetDataOffset(v10)];
          }
          else
          {
            if ( this->mValues.mOffset )
              v17 = (char *)&this->mValues + this->mValues.mOffset;
            else
              v17 = 0i64;
            return &v17[(unsigned int)UFG::qProperty::GetDataOffset(v10)];
          }
        }
        ++v10;
      }
    }
  }
  else
  {
    ++_early_outs;
  }
  if ( depth == DEPTH_RECURSE )
  {
    if ( this->mParents.mOffset )
      v19 = (UFG::qPropertySetHandle *)((char *)&this->mParents + this->mParents.mOffset);
    else
      v19 = 0i64;
    v14 = v19;
    mNumParents = this->mNumParents;
    for ( j = 0; j < mNumParents; ++j )
    {
      v21 = (UFG::qPropertySet *)UFG::qPropertySetHandle::Get(v14);
      if ( v21 )
      {
        ValuePtr = UFG::qPropertySet::GetValuePtr(v21, type_uid, name_uid, DEPTH_RECURSE, owningSet);
        if ( ValuePtr )
          return (char *)ValuePtr;
      }
      ++v14;
    }
  }
  return 0i64;
}

// File Line: 1671
// RVA: 0x1F84F0
char *__fastcall UFG::qPropertySet::GetValuePtr2(
        UFG::qPropertySet *this,
        unsigned int name_uid,
        UFG::qPropertyDepth depth,
        UFG::qPropertySet **owningSet,
        unsigned int *type_uid)
{
  unsigned int i; // [rsp+30h] [rbp-98h]
  unsigned int j; // [rsp+34h] [rbp-94h]
  int v8; // [rsp+38h] [rbp-90h]
  int v9; // [rsp+3Ch] [rbp-8Ch]
  int v10; // [rsp+40h] [rbp-88h]
  UFG::qProperty *v11; // [rsp+48h] [rbp-80h]
  unsigned int mNumProperties; // [rsp+50h] [rbp-78h]
  UFG::qProperty *v13; // [rsp+58h] [rbp-70h]
  unsigned int mNumParents; // [rsp+70h] [rbp-58h]
  UFG::qPropertySetHandle *v15; // [rsp+88h] [rbp-40h]
  UFG::qProperty *v16; // [rsp+90h] [rbp-38h]
  UFG::qPropertySetHandle *v17; // [rsp+98h] [rbp-30h]
  char *v18; // [rsp+A0h] [rbp-28h]
  UFG::qPropertySet *v19; // [rsp+A8h] [rbp-20h]
  char *v20; // [rsp+B0h] [rbp-18h]
  void *ValuePtr2; // [rsp+B8h] [rbp-10h]

  if ( this->mProperties.mOffset )
    v16 = (UFG::qProperty *)((char *)&this->mProperties + this->mProperties.mOffset);
  else
    v16 = 0i64;
  v11 = v16;
  mNumProperties = this->mNumProperties;
  ++_total_calls;
  if ( (this->mPropertyMask & name_uid) == name_uid )
  {
    if ( (this->mFlags & 1) != 0 )
    {
      v10 = 0;
      v9 = mNumProperties - 1;
      while ( v10 <= v9 )
      {
        v8 = (v9 + v10) / 2;
        v13 = &v16[v8];
        if ( name_uid <= v13->mNameUID )
        {
          if ( name_uid >= v13->mNameUID )
          {
            if ( type_uid )
              *type_uid = UFG::qProperty::GetTypeUID(v13);
            if ( owningSet )
              *owningSet = this;
            if ( this->mValues.mOffset )
              v18 = (char *)&this->mValues + this->mValues.mOffset;
            else
              v18 = 0i64;
            return &v18[(unsigned int)UFG::qProperty::GetDataOffset(v13)];
          }
          v9 = v8 - 1;
        }
        else
        {
          v10 = v8 + 1;
        }
      }
    }
    else
    {
      for ( i = 0; i < mNumProperties; ++i )
      {
        if ( v11->mNameUID == name_uid )
        {
          if ( type_uid )
            *type_uid = UFG::qProperty::GetTypeUID(v11);
          if ( owningSet )
            *owningSet = this;
          if ( this->mValues.mOffset )
            v20 = (char *)&this->mValues + this->mValues.mOffset;
          else
            v20 = 0i64;
          return &v20[(unsigned int)UFG::qProperty::GetDataOffset(v11)];
        }
        ++v11;
      }
    }
  }
  else
  {
    ++_early_outs;
  }
  if ( depth == DEPTH_RECURSE )
  {
    if ( this->mParents.mOffset )
      v17 = (UFG::qPropertySetHandle *)((char *)&this->mParents + this->mParents.mOffset);
    else
      v17 = 0i64;
    v15 = v17;
    mNumParents = this->mNumParents;
    for ( j = 0; j < mNumParents; ++j )
    {
      v19 = (UFG::qPropertySet *)UFG::qPropertySetHandle::Get(v15);
      if ( v19 )
      {
        ValuePtr2 = UFG::qPropertySet::GetValuePtr2(v19, name_uid, DEPTH_RECURSE, owningSet, type_uid);
        if ( ValuePtr2 )
          return (char *)ValuePtr2;
      }
      ++v15;
    }
  }
  return 0i64;
}

// File Line: 1765
// RVA: 0x1FE020
void __fastcall UFG::qPropertySet::SetName(UFG::qPropertySet *this, UFG::qSymbol *name)
{
  UFG::qSymbol::qSymbol(&this->mName, name);
  Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat((hkgpIndexedMesh::EdgeBarrier *)this, 0i64);
}

// File Line: 1771
// RVA: 0x1F7BF0
__int64 __fastcall UFG::qPropertySet::GetPropertyTypeFromIndex(UFG::qPropertySet *this, unsigned int index)
{
  char *v3; // [rsp+28h] [rbp-10h]

  if ( index >= this->mNumProperties )
    return 29i64;
  if ( this->mProperties.mOffset )
    v3 = (char *)&this->mProperties + this->mProperties.mOffset;
  else
    v3 = 0i64;
  return UFG::qProperty::GetTypeUID((UFG::qProperty *)&v3[8 * index]);
}

// File Line: 1813
// RVA: 0x1F7AC0
UFG::qSymbol *__fastcall UFG::qPropertySet::GetPropertyNameFromIndex(UFG::qPropertySet *this, unsigned int index)
{
  char *v3; // [rsp+8h] [rbp-10h]

  if ( index >= this->mNumProperties )
    return &UFG::gNullQSymbol;
  if ( this->mProperties.mOffset )
    v3 = (char *)&this->mProperties + this->mProperties.mOffset;
  else
    v3 = 0i64;
  return (UFG::qSymbol *)&v3[8 * index + 4];
}

// File Line: 1822
// RVA: 0x1F7870
__int64 __fastcall UFG::qPropertySet::GetPropertyIndexFromName(
        UFG::qPropertySet *this,
        UFG::qArray<unsigned long,0> *name)
{
  int i; // [rsp+20h] [rbp-38h]
  int v4; // [rsp+28h] [rbp-30h]
  char *v5; // [rsp+38h] [rbp-20h]

  v4 = UFG::qSymbolUC::as_uint32(name);
  for ( i = 0; i < this->mNumProperties; ++i )
  {
    if ( this->mProperties.mOffset )
      v5 = (char *)&this->mProperties + this->mProperties.mOffset;
    else
      v5 = 0i64;
    if ( *(_DWORD *)&v5[8 * i + 4] == v4 )
      return (unsigned int)i;
  }
  return 0xFFFFFFFFi64;
}

// File Line: 1839
// RVA: 0x1FA740
UFG::qPropertySet *__fastcall UFG::qPropertySet::PropertyExists(
        UFG::qPropertySet *this,
        UFG::qArray<unsigned long,0> *name,
        UFG::qPropertyDepth depth)
{
  unsigned int i; // [rsp+20h] [rbp-48h]
  unsigned int parent_index; // [rsp+24h] [rbp-44h]
  unsigned int mNumParents; // [rsp+28h] [rbp-40h]
  int v7; // [rsp+30h] [rbp-38h]
  char *v8; // [rsp+40h] [rbp-28h]
  UFG::qPropertySet *v9; // [rsp+48h] [rbp-20h]
  UFG::qPropertySet *ParentFromIdx; // [rsp+50h] [rbp-18h]

  v7 = UFG::qSymbolUC::as_uint32(name);
  for ( i = 0; i < this->mNumProperties; ++i )
  {
    if ( this->mProperties.mOffset )
      v8 = (char *)&this->mProperties + this->mProperties.mOffset;
    else
      v8 = 0i64;
    if ( *(_DWORD *)&v8[8 * i + 4] == v7 )
      return this;
  }
  if ( depth == DEPTH_RECURSE )
  {
    mNumParents = this->mNumParents;
    for ( parent_index = 0; parent_index < mNumParents; ++parent_index )
    {
      ParentFromIdx = (UFG::qPropertySet *)UFG::qPropertySet::GetParentFromIdx(this, parent_index);
      if ( ParentFromIdx )
      {
        v9 = UFG::qPropertySet::PropertyExists(ParentFromIdx, (UFG::qSymbol *)name, DEPTH_RECURSE);
        if ( v9 )
          return v9;
      }
    }
  }
  return 0i64;
}

// File Line: 1874
// RVA: 0x1FA880
bool __fastcall UFG::qPropertySet::PropertyIsDefaultByName(
        UFG::qPropertySet *this,
        UFG::qArray<unsigned long,0> *propertyName)
{
  int property_index; // [rsp+20h] [rbp-18h]

  property_index = UFG::qPropertySet::GetPropertyIndexFromName(this, propertyName);
  return property_index < 0 || UFG::qPropertySet::PropertyIsDefaultIdx(this, property_index);
}

// File Line: 1886
// RVA: 0x1FA8C0
_BOOL8 __fastcall UFG::qPropertySet::PropertyIsDefaultIdx(UFG::qPropertySet *this, unsigned int property_index)
{
  char *v3; // [rsp+20h] [rbp-18h]

  if ( this->mDefaultBits.mOffset )
    v3 = (char *)&this->mDefaultBits + this->mDefaultBits.mOffset;
  else
    v3 = 0i64;
  return ((1 << (property_index & 0xDF)) & *(_DWORD *)&v3[4 * (property_index / 0x20)]) != 0;
}

// File Line: 1898
// RVA: 0x1FB0D0
void __fastcall UFG::RecalcPropertySetPtrOffsets(
        _BYTE *old_data,
        _BYTE *new_data,
        UFG::qProperty *properties,
        unsigned int property_count)
{
  unsigned int TypeUID; // eax
  unsigned int i; // [rsp+20h] [rbp-28h]
  _QWORD *v6; // [rsp+28h] [rbp-20h]

  for ( i = 0; i < property_count; ++i )
  {
    TypeUID = UFG::qProperty::GetTypeUID(&properties[i]);
    if ( UFG::qPropertyType::IsPtrType(TypeUID) )
    {
      v6 = &new_data[(unsigned int)UFG::qProperty::GetDataOffset(&properties[i])];
      if ( *v6 )
        *v6 -= new_data - old_data;
    }
  }
}

// File Line: 1919
// RVA: 0x1F2120
__int64 __fastcall UFG::CalculateTotalSize(
        unsigned int current_end_offset,
        UFG::qProperty *properties,
        unsigned int num_properties)
{
  unsigned int TypeUID; // eax
  unsigned int i; // [rsp+24h] [rbp-24h]
  UFG::qPropertyType *v7; // [rsp+30h] [rbp-18h]

  for ( i = 0; i < num_properties; ++i )
  {
    TypeUID = UFG::qProperty::GetTypeUID(&properties[i]);
    v7 = UFG::qPropertyType::Get(TypeUID);
    current_end_offset = v7->mByteSize + (~(v7->Alignment - 1) & (current_end_offset + v7->Alignment - 1));
  }
  return current_end_offset;
}

// File Line: 1933
// RVA: 0x1FC220
void __fastcall UFG::qPropertySet::RemovePropertyIdx(UFG::qPropertySet *this, unsigned int property_index)
{
  unsigned int TypeUID; // eax
  unsigned int v3; // eax
  unsigned int v4; // eax
  int v5; // eax
  unsigned int v6; // eax
  unsigned int dataOffset; // [rsp+20h] [rbp-118h]
  unsigned int dataOffseta; // [rsp+20h] [rbp-118h]
  bool IsDefaultIdx; // [rsp+24h] [rbp-114h]
  unsigned int property_indexa; // [rsp+28h] [rbp-110h]
  unsigned int i; // [rsp+2Ch] [rbp-10Ch]
  unsigned int property_count; // [rsp+30h] [rbp-108h]
  char *new_data; // [rsp+38h] [rbp-100h]
  UFG::qProperty *dest; // [rsp+40h] [rbp-F8h]
  int mNumProperties; // [rsp+48h] [rbp-F0h]
  unsigned int count; // [rsp+4Ch] [rbp-ECh]
  UFG::qProperty *_property; // [rsp+50h] [rbp-E8h]
  unsigned int v18; // [rsp+58h] [rbp-E0h]
  UFG::qProperty *v19; // [rsp+60h] [rbp-D8h]
  int v20; // [rsp+68h] [rbp-D0h]
  char *v21; // [rsp+B8h] [rbp-80h]
  UFG::qOffset64<UFG::qProperty *> *p_mProperties; // [rsp+C0h] [rbp-78h]
  UFG::qProperty *v23; // [rsp+C8h] [rbp-70h]
  __int64 v24; // [rsp+D0h] [rbp-68h]
  char *v25; // [rsp+D8h] [rbp-60h]
  UFG::qOffset64<unsigned char *> *p_mValues; // [rsp+E0h] [rbp-58h]
  UFG::qPropertyType *v27; // [rsp+E8h] [rbp-50h]
  __int64 v28; // [rsp+F0h] [rbp-48h]
  UFG::qPropertyType *v29; // [rsp+F8h] [rbp-40h]
  char *v30; // [rsp+108h] [rbp-30h]

  if ( this->mProperties.mOffset )
    v25 = (char *)&this->mProperties + this->mProperties.mOffset;
  else
    v25 = 0i64;
  _property = (UFG::qProperty *)&v25[8 * property_index];
  Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
    (hkgpIndexedMesh::EdgeBarrier *)this,
    (hkgpIndexedMeshDefinitions::Edge *)_property->mNameUID);
  if ( property_index )
    v23 = _property - 1;
  else
    v23 = 0i64;
  if ( v23 )
  {
    TypeUID = UFG::qProperty::GetTypeUID(v23);
    v29 = UFG::qPropertyType::Get(TypeUID);
  }
  else
  {
    v29 = 0i64;
  }
  mNumProperties = this->mNumProperties;
  property_count = mNumProperties - 1;
  if ( v23 )
    v18 = v29->mByteSize + UFG::qProperty::GetDataOffset(v23);
  else
    v18 = 0;
  v3 = UFG::qProperty::GetTypeUID(_property);
  UFG::qPropertyType::Get(v3);
  v20 = UFG::CalculateTotalSize(v18, _property + 1, mNumProperties - 1 - property_index);
  if ( this->mProperties.mOffset )
    v21 = (char *)&this->mProperties + this->mProperties.mOffset;
  else
    v21 = 0i64;
  dest = (UFG::qProperty *)UFG::qPropertySet_Allocate(
                             16 * (unsigned int)((8i64 * (this->mNumProperties - 1) + 15) / 0x10ui64),
                             "PropertySetProps",
                             0);
  UFG::qMemCopy(dest, v21, 8 * property_index);
  UFG::qMemCopy(&dest[property_index], &v21[8 * property_index + 8], 8 * (mNumProperties - 1 - property_index));
  if ( this->mValues.mOffset )
    v30 = (char *)&this->mValues + this->mValues.mOffset;
  else
    v30 = 0i64;
  new_data = (char *)UFG::qPropertySet_Allocate(16 * ((v20 + 15) / 0x10u), "PropertyData", 0x1000u);
  UFG::qPropertySet::FreePropertyPtrData(this, v30, _property);
  UFG::qMemCopy(new_data, v30, v18);
  dataOffset = v18;
  for ( property_indexa = property_index + 1; property_indexa < property_count; ++property_indexa )
  {
    IsDefaultIdx = UFG::qPropertySet::PropertyIsDefaultIdx(this, property_indexa);
    UFG::qPropertySet::SetPropertyDefaultLocalIdx(this, property_indexa - 1, IsDefaultIdx);
  }
  for ( i = property_index; i < property_count; ++i )
  {
    v19 = &dest[i];
    v4 = UFG::qProperty::GetTypeUID(v19);
    v27 = UFG::qPropertyType::Get(v4);
    count = v27->mByteSize;
    dataOffseta = ~(v27->Alignment - 1) & (dataOffset + v27->Alignment - 1);
    v5 = UFG::qProperty::GetDataOffset(v19);
    UFG::qMemCopy(&new_data[dataOffseta], &v30[v5], count);
    v6 = UFG::qProperty::GetTypeUID(v19);
    if ( UFG::qPropertyType::IsPtrType(v6) )
      *(_DWORD *)&new_data[dataOffseta] -= dataOffseta - UFG::qProperty::GetDataOffset(v19);
    UFG::qProperty::SetDataOffset(v19, dataOffseta);
    dataOffset = count + dataOffseta;
  }
  UFG::RecalcPropertySetPtrOffsets(v30, new_data, dest, property_count);
  p_mProperties = &this->mProperties;
  if ( dest )
    v24 = (char *)dest - (char *)p_mProperties;
  else
    v24 = 0i64;
  p_mProperties->mOffset = v24;
  UFG::qPropertySet_Free(v21);
  p_mValues = &this->mValues;
  if ( new_data )
    v28 = new_data - (char *)p_mValues;
  else
    v28 = 0i64;
  p_mValues->mOffset = v28;
  UFG::qPropertySet_Free(v30);
  this->mNumProperties = property_count;
  this->mNumDataBytes = v20;
}

// File Line: 2023
// RVA: 0x1F5760
void __fastcall UFG::qPropertySet::FreePropertyPtrData(
        UFG::qPropertySet *this,
        char *values,
        UFG::qProperty *_property)
{
  char *v3; // [rsp+20h] [rbp-58h]
  char *v4; // [rsp+28h] [rbp-50h]
  char *v5; // [rsp+30h] [rbp-48h]
  char *v6; // [rsp+48h] [rbp-30h]
  UFG::qPropertyList *v7; // [rsp+50h] [rbp-28h]
  UFG::qPropertySet *v8; // [rsp+60h] [rbp-18h]

  if ( (unsigned int)UFG::qProperty::GetTypeUID(_property) == 26 )
  {
    v4 = &values[(unsigned int)UFG::qProperty::GetDataOffset(_property)];
    if ( *(_QWORD *)v4 )
      v8 = (UFG::qPropertySet *)&v4[*(_QWORD *)v4];
    else
      v8 = 0i64;
    if ( v8 )
      UFG::qPropertySet::ReleaseRef(v8);
  }
  else if ( (unsigned int)UFG::qProperty::GetTypeUID(_property) == 25 )
  {
    v5 = &values[(unsigned int)UFG::qProperty::GetDataOffset(_property)];
    if ( *(_QWORD *)v5 )
      v7 = (UFG::qPropertyList *)&v5[*(_QWORD *)v5];
    else
      v7 = 0i64;
    if ( v7 )
      UFG::qPropertyList::ReleaseRef(v7);
  }
  else if ( (unsigned int)UFG::qProperty::GetTypeUID(_property) == 12 )
  {
    v3 = &values[(unsigned int)UFG::qProperty::GetDataOffset(_property)];
    v6 = *(_QWORD *)v3 ? &v3[*(_QWORD *)v3] : 0i64;
    if ( v6 )
    {
      UFG::qPropertySet_Free(v6);
      *(_QWORD *)v3 = 0i64;
    }
  }
}

// File Line: 2065
// RVA: 0x1FBE40
void __fastcall UFG::qPropertySet::RemovePropertiesAllLocal(UFG::qPropertySet *this)
{
  unsigned int i; // [rsp+20h] [rbp-B8h]
  unsigned int mNumProperties; // [rsp+48h] [rbp-90h]
  char *v3; // [rsp+68h] [rbp-70h]
  char *v4; // [rsp+78h] [rbp-60h]

  if ( this->mProperties.mOffset )
    v4 = (char *)&this->mProperties + this->mProperties.mOffset;
  else
    v4 = 0i64;
  mNumProperties = this->mNumProperties;
  if ( this->mValues.mOffset )
    v3 = (char *)&this->mValues + this->mValues.mOffset;
  else
    v3 = 0i64;
  for ( i = 0; i < mNumProperties; ++i )
    UFG::qPropertySet::FreePropertyPtrData(this, v3, (UFG::qProperty *)&v4[8 * i]);
  if ( this->mProperties.mOffset )
    UFG::qPropertySet_Free((char *)&this->mProperties + this->mProperties.mOffset);
  else
    UFG::qPropertySet_Free(0i64);
  this->mProperties.mOffset = 0i64;
  this->mNumProperties = 0;
  if ( this->mValues.mOffset )
    UFG::qPropertySet_Free((char *)&this->mValues + this->mValues.mOffset);
  else
    UFG::qPropertySet_Free(0i64);
  this->mValues.mOffset = 0i64;
  if ( this->mDefaultBits.mOffset )
    UFG::qPropertySet_Free((char *)&this->mDefaultBits + this->mDefaultBits.mOffset);
  else
    UFG::qPropertySet_Free(0i64);
  this->mDefaultBits.mOffset = 0i64;
  this->mNumDataBytes = 0;
  this->mPropertyMask = -1;
}

// File Line: 2096
// RVA: 0x1FC160
void __fastcall UFG::qPropertySet::RemovePropertyByName(UFG::qPropertySet *this, UFG::qArray<unsigned long,0> *name)
{
  unsigned int property_index; // [rsp+20h] [rbp-28h]
  unsigned int mNumProperties; // [rsp+24h] [rbp-24h]
  char *v4; // [rsp+30h] [rbp-18h]

  mNumProperties = this->mNumProperties;
  for ( property_index = 0; property_index < mNumProperties; ++property_index )
  {
    if ( this->mProperties.mOffset )
      v4 = (char *)&this->mProperties + this->mProperties.mOffset;
    else
      v4 = 0i64;
    if ( *(_DWORD *)&v4[8 * property_index + 4] == (unsigned int)UFG::qSymbolUC::as_uint32(name) )
    {
      UFG::qPropertySet::RemovePropertyIdx(this, property_index);
      return;
    }
  }
}

// File Line: 2112
// RVA: 0x1FD610
char *__fastcall UFG::qPropertySet::SetInternal(
        UFG::qPropertySet *this,
        unsigned int type_uid,
        unsigned int name_uid,
        const void *v)
{
  int v5; // eax
  signed int count; // [rsp+20h] [rbp-178h]
  unsigned int mByteSize; // [rsp+24h] [rbp-174h]
  unsigned int dataOffset; // [rsp+28h] [rbp-170h]
  unsigned int index; // [rsp+2Ch] [rbp-16Ch]
  int v10; // [rsp+30h] [rbp-168h]
  UFG::qProperty *v11; // [rsp+38h] [rbp-160h]
  unsigned int v12; // [rsp+40h] [rbp-158h]
  char *new_data; // [rsp+48h] [rbp-150h]
  unsigned int byte_count; // [rsp+50h] [rbp-148h]
  int v15; // [rsp+54h] [rbp-144h]
  unsigned int v16; // [rsp+58h] [rbp-140h]
  char *v17; // [rsp+60h] [rbp-138h]
  UFG::qPropertyType *v18; // [rsp+68h] [rbp-130h]
  void *v19; // [rsp+70h] [rbp-128h]
  UFG::qOffset64<UFG::qProperty *> *p_mProperties; // [rsp+D8h] [rbp-C0h]
  __int64 v21; // [rsp+E0h] [rbp-B8h]
  char *v22; // [rsp+E8h] [rbp-B0h]
  char *v23; // [rsp+F0h] [rbp-A8h]
  char *v24; // [rsp+F8h] [rbp-A0h]
  char *v25; // [rsp+108h] [rbp-90h]
  char *v26; // [rsp+110h] [rbp-88h]
  UFG::qOffset64<unsigned char *> *p_mValues; // [rsp+120h] [rbp-78h]
  __int64 v28; // [rsp+130h] [rbp-68h]
  char *dest; // [rsp+138h] [rbp-60h]
  __int64 v30; // [rsp+148h] [rbp-50h]
  char *v31; // [rsp+150h] [rbp-48h]
  UFG::qOffset64<unsigned long *> *p_mDefaultBits; // [rsp+158h] [rbp-40h]
  char *v33; // [rsp+160h] [rbp-38h]
  char *v34; // [rsp+168h] [rbp-30h]

  Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
    (hkgpIndexedMesh::EdgeBarrier *)this,
    (hkgpIndexedMeshDefinitions::Edge *)name_uid);
  if ( (unsigned int)UFG::qPropertyCollection::GetFlags(this, 1) )
    return 0i64;
  if ( !type_uid || !name_uid || !v )
    return 0i64;
  v18 = UFG::qPropertyType::Get(type_uid);
  if ( v18 )
  {
    index = UFG::qPropertySet::GetPropertyIdxLocal(this, type_uid, name_uid);
    if ( index == -1 )
    {
      byte_count = 16 * ((8i64 * (this->mNumProperties + 1) + 15) / 0x10ui64);
      if ( this->mProperties.mOffset )
        v24 = (char *)&this->mProperties + this->mProperties.mOffset;
      else
        v24 = 0i64;
      if ( byte_count == 16 * (unsigned int)((8 * (unsigned __int64)this->mNumProperties + 15) / 0x10) )
      {
        UFG::qMemSet(&v24[8 * this->mNumProperties], 0, 8u);
      }
      else
      {
        v17 = (char *)UFG::qPropertySet_Allocate(byte_count, "PropertySetProps", 0);
        UFG::qMemCopy(v17, v24, 8 * this->mNumProperties);
        UFG::qMemSet(&v17[8 * this->mNumProperties], 0, 8u);
        if ( this->mProperties.mOffset )
          UFG::qPropertySet_Free((char *)&this->mProperties + this->mProperties.mOffset);
        else
          UFG::qPropertySet_Free(0i64);
        p_mProperties = &this->mProperties;
        if ( v17 )
          v30 = v17 - (char *)p_mProperties;
        else
          v30 = 0i64;
        p_mProperties->mOffset = v30;
      }
      v15 = (this->mNumProperties + 31) / 32;
      v10 = (this->mNumProperties + 32) / 32;
      if ( v15 != v10 )
      {
        if ( this->mDefaultBits.mOffset )
          v34 = (char *)&this->mDefaultBits + this->mDefaultBits.mOffset;
        else
          v34 = 0i64;
        v19 = UFG::qPropertySet_Allocate(4 * v10, "PropertySetDefaults", 0);
        UFG::qMemCopy(v19, v34, 4 * v15);
        *((_DWORD *)v19 + (unsigned int)(v10 - 1)) = 0;
        UFG::qPropertySet_Free(v34);
        p_mDefaultBits = &this->mDefaultBits;
        if ( v19 )
          v21 = (_BYTE *)v19 - (_BYTE *)p_mDefaultBits;
        else
          v21 = 0i64;
        p_mDefaultBits->mOffset = v21;
      }
      ++this->mNumProperties;
      if ( this->mProperties.mOffset )
        v23 = (char *)&this->mProperties + this->mProperties.mOffset;
      else
        v23 = 0i64;
      v11 = (UFG::qProperty *)&v23[8 * this->mNumProperties - 8];
      UFG::qProperty::SetTypeUID(v11, type_uid);
      v11->mNameUID = name_uid;
      UFG::qProperty::SetDataOffset(v11, this->mNumDataBytes);
      UFG::qPropertySet::SetPropertyDefaultLocalIdx(this, this->mNumProperties - 1, 0);
      mByteSize = v18->mByteSize;
      dataOffset = (unsigned __int16)(~(v18->Alignment - 1) & (this->mNumDataBytes + v18->Alignment - 1));
      v16 = mByteSize + dataOffset;
      count = this->mNumDataBytes;
      if ( this->mValues.mOffset )
        v26 = (char *)&this->mValues + this->mValues.mOffset;
      else
        v26 = 0i64;
      v12 = 16 * ((v16 + 15) / 0x10);
      if ( v12 == 16 * ((count + 15) / 0x10u) )
      {
        if ( mByteSize + dataOffset > 16 * ((count + 15) / 0x10u) )
          UFG::qPrintf(&customCaption, (v16 + 15) % 0x10);
        UFG::qMemSet(&v26[count], 0, mByteSize + dataOffset - count);
      }
      else
      {
        new_data = (char *)UFG::qPropertySet_Allocate(v12, "PropertySetData", 0x1000u);
        UFG::qMemCopy(new_data, v26, count);
        UFG::qMemSet(&new_data[count], 0, mByteSize + dataOffset - count);
        p_mValues = &this->mValues;
        if ( new_data )
          v28 = new_data - (char *)p_mValues;
        else
          v28 = 0i64;
        p_mValues->mOffset = v28;
        if ( this->mProperties.mOffset )
          UFG::RecalcPropertySetPtrOffsets(
            v26,
            new_data,
            (UFG::qProperty *)((char *)&this->mProperties + this->mProperties.mOffset),
            this->mNumProperties);
        else
          UFG::RecalcPropertySetPtrOffsets(v26, new_data, 0i64, this->mNumProperties);
        UFG::qPropertySet_Free(v26);
      }
      this->mNumDataBytes = v16;
      UFG::qProperty::SetDataOffset(v11, dataOffset);
      if ( this->mValues.mOffset )
        v31 = (char *)&this->mValues + this->mValues.mOffset;
      else
        v31 = 0i64;
      v5 = UFG::qProperty::GetDataOffset(v11);
      UFG::qMemCopy(&v31[v5], v, mByteSize);
      if ( this->mValues.mOffset )
        v33 = (char *)&this->mValues + this->mValues.mOffset;
      else
        v33 = 0i64;
      return &v33[(unsigned int)UFG::qProperty::GetDataOffset(v11)];
    }
    else
    {
      if ( this->mProperties.mOffset )
        v25 = (char *)&this->mProperties + this->mProperties.mOffset;
      else
        v25 = 0i64;
      if ( this->mValues.mOffset )
        v22 = (char *)&this->mValues + this->mValues.mOffset;
      else
        v22 = 0i64;
      dest = &v22[(unsigned int)UFG::qProperty::GetDataOffset((UFG::qProperty *)&v25[8 * index])];
      UFG::qMemCopy(dest, v, v18->mByteSize);
      UFG::qPropertySet::SetPropertyDefaultLocalIdx(this, index, 0);
      return dest;
    }
  }
  else
  {
    UFG::qPrintf("[qPropertySetResource] ERROR: Could not find qPropertyType 0x%08x!\n", type_uid);
    return 0i64;
  }
}

// File Line: 2264
// RVA: 0x1EB360
void __fastcall UFG::qPropertySet::SetPtr<char>(
        UFG::qPropertySet *this,
        unsigned int property_type_uid,
        unsigned int name_uid,
        char *property_set_data)
{
  int v4; // [rsp+20h] [rbp-48h]
  char *v5; // [rsp+28h] [rbp-40h]
  char *dest; // [rsp+30h] [rbp-38h]
  signed __int64 v7; // [rsp+40h] [rbp-28h]
  __int64 v; // [rsp+48h] [rbp-20h] BYREF
  char *v9; // [rsp+50h] [rbp-18h]
  void *buffer; // [rsp+58h] [rbp-10h]

  Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
    (hkgpIndexedMesh::EdgeBarrier *)this,
    (hkgpIndexedMeshDefinitions::Edge *)name_uid);
  v = 0i64;
  v9 = (char *)UFG::qPropertySet::SetInternal(this, property_type_uid, name_uid, &v);
  v5 = v9;
  if ( *(_QWORD *)v9 )
  {
    buffer = &v9[*(_QWORD *)v9];
    UFG::qPropertySet_Free(buffer);
    *(_QWORD *)v5 = 0i64;
  }
  v4 = UFG::qStringLength(property_set_data);
  dest = (char *)UFG::qPropertySet_Allocate(v4 + 1, "PropertyString", 0);
  UFG::qStringCopy(dest, property_set_data);
  if ( dest )
    v7 = dest - v5;
  else
    v7 = 0i64;
  *(_QWORD *)v5 = v7;
}

// File Line: 2294
// RVA: 0x1EB8B0
void __fastcall UFG::qPropertySet::SetPtr<UFG::qPropertySet>(
        UFG::qPropertySet *this,
        unsigned int type_uid,
        unsigned int name_uid,
        UFG::qPropertySet *property_set_data)
{
  char *v4; // [rsp+20h] [rbp-48h]
  UFG::qPropertySet *v5; // [rsp+30h] [rbp-38h]
  char *v6; // [rsp+38h] [rbp-30h]
  char *v7; // [rsp+40h] [rbp-28h]
  __int64 v; // [rsp+48h] [rbp-20h] BYREF
  char *v9; // [rsp+50h] [rbp-18h]

  Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
    (hkgpIndexedMesh::EdgeBarrier *)this,
    (hkgpIndexedMeshDefinitions::Edge *)name_uid);
  v = 0i64;
  v9 = (char *)UFG::qPropertySet::SetInternal(this, type_uid, name_uid, &v);
  v4 = v9;
  if ( *(_QWORD *)v9 )
    v5 = (UFG::qPropertySet *)&v9[*(_QWORD *)v9];
  else
    v5 = 0i64;
  if ( v5 )
  {
    if ( v5 != property_set_data )
    {
      UFG::qPropertySet::ReleaseRef(v5);
      UFG::qPropertyCollection::SetOwner(v5, 0i64);
      if ( property_set_data )
        v6 = (char *)((char *)property_set_data - v4);
      else
        v6 = 0i64;
      *(_QWORD *)v4 = v6;
      UFG::qPropertySet::AddRef(property_set_data);
      UFG::qPropertyCollection::SetOwner(property_set_data, this);
    }
  }
  else
  {
    if ( property_set_data )
      v7 = (char *)((char *)property_set_data - v9);
    else
      v7 = 0i64;
    *(_QWORD *)v9 = v7;
    UFG::qPropertySet::AddRef(property_set_data);
    UFG::qPropertyCollection::SetOwner(property_set_data, this);
  }
}

// File Line: 2326
// RVA: 0x1F9170
char __fastcall UFG::qPropertySet::GetVariant(
        UFG::qPropertySet *this,
        UFG::qArray<unsigned long,0> *name,
        qPropertySetVariant *value,
        UFG::qPropertyDepth depth)
{
  unsigned int v4; // eax
  ePropertyType eType; // [rsp+30h] [rbp-28h] BYREF
  void *dataPtr; // [rsp+38h] [rbp-20h]
  UFG::qPropertySet *owningSet; // [rsp+40h] [rbp-18h] BYREF

  owningSet = 0i64;
  eType = UID_Invalid;
  v4 = UFG::qSymbolUC::as_uint32(name);
  dataPtr = UFG::qPropertySet::GetValuePtr2(this, v4, depth, &owningSet, (unsigned int *)&eType);
  if ( !dataPtr )
    return 0;
  qPropertySetVariant::Set(value, dataPtr, eType);
  return 1;
}

// File Line: 2344
// RVA: 0x1E9B30
char *__fastcall UFG::qPropertySet::Get<char const *>(
        UFG::qPropertySet *this,
        UFG::qArray<unsigned long,0> *name,
        UFG::qPropertyDepth depth)
{
  unsigned int v3; // eax
  _QWORD *ValuePtr; // [rsp+38h] [rbp-20h]

  v3 = UFG::qSymbolUC::as_uint32(name);
  ValuePtr = UFG::qPropertySet::GetValuePtr(this, 0xCu, v3, depth, 0i64);
  if ( !ValuePtr )
    return 0i64;
  if ( *ValuePtr )
    return (char *)ValuePtr + *ValuePtr;
  else
    return 0i64;
}

// File Line: 2359
// RVA: 0x1E9EF0
UFG::qPropertySet *__fastcall UFG::qPropertySet::Get<UFG::qPropertySet>(
        UFG::qPropertySet *this,
        UFG::qArray<unsigned long,0> *name,
        UFG::qPropertyDepth depth)
{
  unsigned int v3; // eax
  _QWORD *ValuePtr; // [rsp+38h] [rbp-20h]

  v3 = UFG::qSymbolUC::as_uint32(name);
  ValuePtr = UFG::qPropertySet::GetValuePtr(this, 0x1Au, v3, depth, 0i64);
  if ( !ValuePtr )
    return 0i64;
  if ( *ValuePtr )
    return (UFG::qPropertySet *)((char *)ValuePtr + *ValuePtr);
  else
    return 0i64;
}

// File Line: 2373
// RVA: 0x1E9E60
UFG::qPropertyList *__fastcall UFG::qPropertySet::Get<UFG::qPropertyList>(
        UFG::qPropertySet *this,
        UFG::qArray<unsigned long,0> *name,
        UFG::qPropertyDepth depth)
{
  unsigned int v3; // eax
  _QWORD *ValuePtr; // [rsp+38h] [rbp-20h]

  v3 = UFG::qSymbolUC::as_uint32(name);
  ValuePtr = UFG::qPropertySet::GetValuePtr(this, 0x19u, v3, depth, 0i64);
  if ( !ValuePtr )
    return 0i64;
  if ( *ValuePtr )
    return (UFG::qPropertyList *)((char *)ValuePtr + *ValuePtr);
  else
    return 0i64;
}

// File Line: 2390
// RVA: 0x1EA610
bool *__fastcall UFG::qPropertySet::Get<bool>(
        UFG::qPropertySet *this,
        UFG::qArray<unsigned long,0> *name,
        UFG::qPropertyDepth depth)
{
  unsigned int v3; // eax
  _BYTE *ValuePtr; // [rsp+30h] [rbp-18h]

  v3 = UFG::qSymbolUC::as_uint32(name);
  ValuePtr = UFG::qPropertySet::GetValuePtr(this, 9u, v3, depth, 0i64);
  if ( !ValuePtr )
    return 0i64;
  if ( *ValuePtr )
    return &qPropertySet_True;
  else
    return &qPropertySet_False;
}

// File Line: 2401
// RVA: 0x1E95F0
char *__fastcall UFG::qPropertySet::Get<signed char>(
        UFG::qPropertySet *this,
        UFG::qArray<unsigned long,0> *name,
        UFG::qPropertyDepth depth)
{
  unsigned int v3; // eax

  v3 = UFG::qSymbolUC::as_uint32(name);
  return (char *)UFG::qPropertySet::GetValuePtr(this, 0, v3, depth, 0i64);
}

// File Line: 2402
// RVA: 0x1E9760
__int16 *__fastcall UFG::qPropertySet::Get<short>(
        UFG::qPropertySet *this,
        UFG::qArray<unsigned long,0> *name,
        UFG::qPropertyDepth depth)
{
  unsigned int v3; // eax

  v3 = UFG::qSymbolUC::as_uint32(name);
  return (__int16 *)UFG::qPropertySet::GetValuePtr(this, 1u, v3, depth, 0i64);
}

// File Line: 2403
// RVA: 0x1E98E0
int *__fastcall UFG::qPropertySet::Get<long>(
        UFG::qPropertySet *this,
        UFG::qArray<unsigned long,0> *name,
        UFG::qPropertyDepth depth)
{
  unsigned int v3; // eax

  v3 = UFG::qSymbolUC::as_uint32(name);
  return (int *)UFG::qPropertySet::GetValuePtr(this, 2u, v3, depth, 0i64);
}

// File Line: 2404
// RVA: 0x1EA470
__int64 *__fastcall UFG::qPropertySet::Get<__int64>(
        UFG::qPropertySet *this,
        UFG::qArray<unsigned long,0> *name,
        UFG::qPropertyDepth depth)
{
  unsigned int v3; // eax

  v3 = UFG::qSymbolUC::as_uint32(name);
  return (__int64 *)UFG::qPropertySet::GetValuePtr(this, 3u, v3, depth, 0i64);
}

// File Line: 2405
// RVA: 0x1E96A0
char *__fastcall UFG::qPropertySet::Get<unsigned char>(
        UFG::qPropertySet *this,
        UFG::qArray<unsigned long,0> *name,
        UFG::qPropertyDepth depth)
{
  unsigned int v3; // eax

  v3 = UFG::qSymbolUC::as_uint32(name);
  return (char *)UFG::qPropertySet::GetValuePtr(this, 5u, v3, depth, 0i64);
}

// File Line: 2406
// RVA: 0x1E9820
unsigned __int16 *__fastcall UFG::qPropertySet::Get<unsigned short>(
        UFG::qPropertySet *this,
        UFG::qArray<unsigned long,0> *name,
        UFG::qPropertyDepth depth)
{
  unsigned int v3; // eax

  v3 = UFG::qSymbolUC::as_uint32(name);
  return (unsigned __int16 *)UFG::qPropertySet::GetValuePtr(this, 6u, v3, depth, 0i64);
}

// File Line: 2407
// RVA: 0x1E99A0
unsigned int *__fastcall UFG::qPropertySet::Get<unsigned long>(
        UFG::qPropertySet *this,
        UFG::qArray<unsigned long,0> *name,
        UFG::qPropertyDepth depth)
{
  unsigned int v3; // eax

  v3 = UFG::qSymbolUC::as_uint32(name);
  return (unsigned int *)UFG::qPropertySet::GetValuePtr(this, 7u, v3, depth, 0i64);
}

// File Line: 2408
// RVA: 0x1EA530
unsigned __int64 *__fastcall UFG::qPropertySet::Get<unsigned __int64>(
        UFG::qPropertySet *this,
        UFG::qArray<unsigned long,0> *name,
        UFG::qPropertyDepth depth)
{
  unsigned int v3; // eax

  v3 = UFG::qSymbolUC::as_uint32(name);
  return (unsigned __int64 *)UFG::qPropertySet::GetValuePtr(this, 8u, v3, depth, 0i64);
}

// File Line: 2409
// RVA: 0x1E9A60
float *__fastcall UFG::qPropertySet::Get<float>(
        UFG::qPropertySet *this,
        UFG::qArray<unsigned long,0> *name,
        UFG::qPropertyDepth depth)
{
  unsigned int v3; // eax

  v3 = UFG::qSymbolUC::as_uint32(name);
  return (float *)UFG::qPropertySet::GetValuePtr(this, 0xAu, v3, depth, 0i64);
}

// File Line: 2411
// RVA: 0x1E9FF0
UFG::qSymbol *__fastcall UFG::qPropertySet::Get<UFG::qSymbol>(
        UFG::qPropertySet *this,
        UFG::qArray<unsigned long,0> *name,
        UFG::qPropertyDepth depth)
{
  unsigned int v3; // eax

  v3 = UFG::qSymbolUC::as_uint32(name);
  return (UFG::qSymbol *)UFG::qPropertySet::GetValuePtr(this, 0x16u, v3, depth, 0i64);
}

// File Line: 2412
// RVA: 0x1EA0B0
UFG::qSymbolUC *__fastcall UFG::qPropertySet::Get<UFG::qSymbolUC>(
        UFG::qPropertySet *this,
        UFG::qArray<unsigned long,0> *name,
        UFG::qPropertyDepth depth)
{
  unsigned int v3; // eax

  v3 = UFG::qSymbolUC::as_uint32(name);
  return (UFG::qSymbolUC *)UFG::qPropertySet::GetValuePtr(this, 0x17u, v3, depth, 0i64);
}

// File Line: 2413
// RVA: 0x1EA3B0
UFG::qWiseSymbol *__fastcall UFG::qPropertySet::Get<UFG::qWiseSymbol>(
        UFG::qPropertySet *this,
        UFG::qArray<unsigned long,0> *name,
        UFG::qPropertyDepth depth)
{
  unsigned int v3; // eax

  v3 = UFG::qSymbolUC::as_uint32(name);
  return (UFG::qWiseSymbol *)UFG::qPropertySet::GetValuePtr(this, 0x18u, v3, depth, 0i64);
}

// File Line: 2414
// RVA: 0x1EA170
UFG::qVector2 *__fastcall UFG::qPropertySet::Get<UFG::qVector2>(
        UFG::qPropertySet *this,
        UFG::qArray<unsigned long,0> *name,
        UFG::qPropertyDepth depth)
{
  unsigned int v3; // eax

  v3 = UFG::qSymbolUC::as_uint32(name);
  return (UFG::qVector2 *)UFG::qPropertySet::GetValuePtr(this, 0x11u, v3, depth, 0i64);
}

// File Line: 2415
// RVA: 0x1EA230
UFG::qVector3 *__fastcall UFG::qPropertySet::Get<UFG::qVector3>(
        UFG::qPropertySet *this,
        UFG::qArray<unsigned long,0> *name,
        UFG::qPropertyDepth depth)
{
  unsigned int v3; // eax

  v3 = UFG::qSymbolUC::as_uint32(name);
  return (UFG::qVector3 *)UFG::qPropertySet::GetValuePtr(this, 0x12u, v3, depth, 0i64);
}

// File Line: 2416
// RVA: 0x1EA2F0
UFG::qVector4 *__fastcall UFG::qPropertySet::Get<UFG::qVector4>(
        UFG::qPropertySet *this,
        UFG::qArray<unsigned long,0> *name,
        UFG::qPropertyDepth depth)
{
  unsigned int v3; // eax

  v3 = UFG::qSymbolUC::as_uint32(name);
  return (UFG::qVector4 *)UFG::qPropertySet::GetValuePtr(this, 0x13u, v3, depth, 0i64);
}

// File Line: 2417
// RVA: 0x1E9D90
UFG::qMatrix44 *__fastcall UFG::qPropertySet::Get<UFG::qMatrix44>(
        UFG::qPropertySet *this,
        UFG::qArray<unsigned long,0> *name,
        UFG::qPropertyDepth depth)
{
  unsigned int v3; // eax

  v3 = UFG::qSymbolUC::as_uint32(name);
  return (UFG::qMatrix44 *)UFG::qPropertySet::GetValuePtr(this, 0x14u, v3, depth, 0i64);
}

// File Line: 2418
// RVA: 0x1E9CD0
UFG::qTransQuat *__fastcall UFG::qPropertySet::Get<UFG::qTransQuat>(
        UFG::qPropertySet *this,
        UFG::qArray<unsigned long,0> *name,
        UFG::qPropertyDepth depth)
{
  unsigned int v3; // eax

  v3 = UFG::qSymbolUC::as_uint32(name);
  return (UFG::qTransQuat *)UFG::qPropertySet::GetValuePtr(this, 0x1Cu, v3, depth, 0i64);
}

// File Line: 2421
// RVA: 0x1E9C80
UFG::qRangedValue<float> *__fastcall UFG::qPropertySet::Get<UFG::qRangedValue<float>>(
        UFG::qPropertySet *this,
        UFG::qArray<unsigned long,0> *name,
        UFG::qPropertyDepth depth)
{
  unsigned int v3; // eax

  v3 = UFG::qSymbolUC::as_uint32(name);
  return (UFG::qRangedValue<float> *)UFG::qPropertySet::GetValuePtr(this, 0xDu, v3, depth, 0i64);
}

// File Line: 2422
// RVA: 0x1E9C30
UFG::qRangedValue<long> *__fastcall UFG::qPropertySet::Get<UFG::qRangedValue<long>>(
        UFG::qPropertySet *this,
        UFG::qArray<unsigned long,0> *name,
        UFG::qPropertyDepth depth)
{
  unsigned int v3; // eax

  v3 = UFG::qSymbolUC::as_uint32(name);
  return (UFG::qRangedValue<long> *)UFG::qPropertySet::GetValuePtr(this, 0xFu, v3, depth, 0i64);
}

// File Line: 2425
// RVA: 0x1EB270
void __fastcall UFG::qPropertySet::Set<bool>(UFG::qPropertySet *this, UFG::qArray<unsigned long,0> *name, bool v)
{
  unsigned int v3; // eax
  char va[4]; // [rsp+20h] [rbp-18h] BYREF
  BOOL v5; // [rsp+24h] [rbp-14h]

  v5 = v;
  va[0] = v;
  v3 = UFG::qSymbolUC::as_uint32(name);
  UFG::qPropertySet::SetInternal(this, 9u, v3, va);
}

// File Line: 2426
// RVA: 0x1EACD0
void __fastcall UFG::qPropertySet::Set<signed char>(
        UFG::qPropertySet *this,
        UFG::qArray<unsigned long,0> *name,
        char v)
{
  unsigned int v3; // eax
  char va; // [rsp+40h] [rbp+18h] BYREF

  va = v;
  v3 = UFG::qSymbolUC::as_uint32(name);
  UFG::qPropertySet::SetInternal(this, 0, v3, &va);
}

// File Line: 2427
// RVA: 0x1EAD50
void __fastcall UFG::qPropertySet::Set<short>(UFG::qPropertySet *this, UFG::qArray<unsigned long,0> *name, __int16 v)
{
  unsigned int v3; // eax
  __int16 va; // [rsp+40h] [rbp+18h] BYREF

  va = v;
  v3 = UFG::qSymbolUC::as_uint32(name);
  UFG::qPropertySet::SetInternal(this, 1u, v3, &va);
}

// File Line: 2428
// RVA: 0x1EADD0
void __fastcall UFG::qPropertySet::Set<long>(UFG::qPropertySet *this, UFG::qArray<unsigned long,0> *name, int v)
{
  unsigned int v3; // eax
  int va; // [rsp+40h] [rbp+18h] BYREF

  va = v;
  v3 = UFG::qSymbolUC::as_uint32(name);
  UFG::qPropertySet::SetInternal(this, 2u, v3, &va);
}

// File Line: 2429
// RVA: 0x1EB1F0
void __fastcall UFG::qPropertySet::Set<__int64>(UFG::qPropertySet *this, UFG::qArray<unsigned long,0> *name, __int64 v)
{
  unsigned int v3; // eax
  __int64 va; // [rsp+40h] [rbp+18h] BYREF

  va = v;
  v3 = UFG::qSymbolUC::as_uint32(name);
  UFG::qPropertySet::SetInternal(this, 3u, v3, &va);
}

// File Line: 2430
// RVA: 0x1EAED0
void __fastcall UFG::qPropertySet::Set<__m128>(UFG::qPropertySet *this, UFG::qArray<unsigned long,0> *name, __m128 *v)
{
  unsigned int v3; // eax

  v3 = UFG::qSymbolUC::as_uint32(name);
  UFG::qPropertySet::SetInternal(this, 4u, v3, v);
}

// File Line: 2431
// RVA: 0x1EAD10
void __fastcall UFG::qPropertySet::Set<unsigned char>(
        UFG::qPropertySet *this,
        UFG::qArray<unsigned long,0> *name,
        char v)
{
  unsigned int v3; // eax
  char va; // [rsp+40h] [rbp+18h] BYREF

  va = v;
  v3 = UFG::qSymbolUC::as_uint32(name);
  UFG::qPropertySet::SetInternal(this, 5u, v3, &va);
}

// File Line: 2432
// RVA: 0x1EAD90
void __fastcall UFG::qPropertySet::Set<unsigned short>(
        UFG::qPropertySet *this,
        UFG::qArray<unsigned long,0> *name,
        unsigned __int16 v)
{
  unsigned int v3; // eax
  unsigned __int16 va; // [rsp+40h] [rbp+18h] BYREF

  va = v;
  v3 = UFG::qSymbolUC::as_uint32(name);
  UFG::qPropertySet::SetInternal(this, 6u, v3, &va);
}

// File Line: 2433
// RVA: 0x1EAE10
void __fastcall UFG::qPropertySet::Set<unsigned long>(
        UFG::qPropertySet *this,
        UFG::qArray<unsigned long,0> *name,
        unsigned int v)
{
  unsigned int v3; // eax
  unsigned int va; // [rsp+40h] [rbp+18h] BYREF

  va = v;
  v3 = UFG::qSymbolUC::as_uint32(name);
  UFG::qPropertySet::SetInternal(this, 7u, v3, &va);
}

// File Line: 2434
// RVA: 0x1EB230
void __fastcall UFG::qPropertySet::Set<unsigned __int64>(
        UFG::qPropertySet *this,
        UFG::qArray<unsigned long,0> *name,
        __int64 v)
{
  unsigned int v3; // eax
  __int64 va; // [rsp+40h] [rbp+18h] BYREF

  va = v;
  v3 = UFG::qSymbolUC::as_uint32(name);
  UFG::qPropertySet::SetInternal(this, 8u, v3, &va);
}

// File Line: 2435
// RVA: 0x1EAE50
void __fastcall UFG::qPropertySet::Set<float>(UFG::qPropertySet *this, UFG::qArray<unsigned long,0> *name, float v)
{
  unsigned int v3; // eax
  float va; // [rsp+40h] [rbp+18h] BYREF

  va = v;
  v3 = UFG::qSymbolUC::as_uint32(name);
  UFG::qPropertySet::SetInternal(this, 0xAu, v3, &va);
}

// File Line: 2438
// RVA: 0x1EB070
void __fastcall UFG::qPropertySet::Set<UFG::qSymbol>(
        UFG::qPropertySet *this,
        UFG::qArray<unsigned long,0> *name,
        UFG::qSymbol *v)
{
  unsigned int v3; // eax

  v3 = UFG::qSymbolUC::as_uint32(name);
  UFG::qPropertySet::SetInternal(this, 0x16u, v3, v);
}

// File Line: 2439
// RVA: 0x1EB0B0
void __fastcall UFG::qPropertySet::Set<UFG::qSymbolUC>(
        UFG::qPropertySet *this,
        UFG::qArray<unsigned long,0> *name,
        UFG::qSymbolUC *v)
{
  unsigned int v3; // eax

  v3 = UFG::qSymbolUC::as_uint32(name);
  UFG::qPropertySet::SetInternal(this, 0x17u, v3, v);
}

// File Line: 2440
// RVA: 0x1EB1B0
void __fastcall UFG::qPropertySet::Set<UFG::qWiseSymbol>(
        UFG::qPropertySet *this,
        UFG::qArray<unsigned long,0> *name,
        UFG::qWiseSymbol *v)
{
  unsigned int v3; // eax

  v3 = UFG::qSymbolUC::as_uint32(name);
  UFG::qPropertySet::SetInternal(this, 0x18u, v3, v);
}

// File Line: 2442
// RVA: 0x1EB0F0
void __fastcall UFG::qPropertySet::Set<UFG::qVector2>(
        UFG::qPropertySet *this,
        UFG::qArray<unsigned long,0> *name,
        UFG::qVector2 *v)
{
  unsigned int v3; // eax

  v3 = UFG::qSymbolUC::as_uint32(name);
  UFG::qPropertySet::SetInternal(this, 0x11u, v3, v);
}

// File Line: 2443
// RVA: 0x1EB130
void __fastcall UFG::qPropertySet::Set<UFG::qVector3>(
        UFG::qPropertySet *this,
        UFG::qArray<unsigned long,0> *name,
        UFG::qVector3 *v)
{
  unsigned int v3; // eax

  v3 = UFG::qSymbolUC::as_uint32(name);
  UFG::qPropertySet::SetInternal(this, 0x12u, v3, v);
}

// File Line: 2444
// RVA: 0x1EB170
void __fastcall UFG::qPropertySet::Set<UFG::qVector4>(
        UFG::qPropertySet *this,
        UFG::qArray<unsigned long,0> *name,
        UFG::qVector4 *v)
{
  unsigned int v3; // eax

  v3 = UFG::qSymbolUC::as_uint32(name);
  UFG::qPropertySet::SetInternal(this, 0x13u, v3, v);
}

// File Line: 2445
// RVA: 0x1EAF90
void __fastcall UFG::qPropertySet::Set<UFG::qMatrix44>(
        UFG::qPropertySet *this,
        UFG::qArray<unsigned long,0> *name,
        UFG::qMatrix44 *v)
{
  unsigned int v3; // eax

  v3 = UFG::qSymbolUC::as_uint32(name);
  UFG::qPropertySet::SetInternal(this, 0x14u, v3, v);
}

// File Line: 2446
// RVA: 0x1EAF50
void __fastcall UFG::qPropertySet::Set<UFG::qTransQuat>(
        UFG::qPropertySet *this,
        UFG::qArray<unsigned long,0> *name,
        UFG::qTransQuat *v)
{
  unsigned int v3; // eax

  v3 = UFG::qSymbolUC::as_uint32(name);
  UFG::qPropertySet::SetInternal(this, 0x1Cu, v3, v);
}

// File Line: 2448
// RVA: 0x1EB030
void __fastcall UFG::qPropertySet::Set<UFG::qPropertySet>(
        UFG::qPropertySet *this,
        UFG::qArray<unsigned long,0> *name,
        UFG::qPropertySet *v)
{
  unsigned int v3; // eax

  v3 = UFG::qSymbolUC::as_uint32(name);
  UFG::qPropertySet::SetPtr<UFG::qPropertySet>(this, 0x1Au, v3, v);
}

// File Line: 2449
// RVA: 0x1EAFE0
void __fastcall UFG::qPropertySet::Set<UFG::qPropertyList>(
        UFG::qPropertySet *this,
        UFG::qArray<unsigned long,0> *name,
        UFG::qPropertyList *v)
{
  unsigned int v3; // eax

  v3 = UFG::qSymbolUC::as_uint32(name);
  UFG::qPropertySet::SetPtr<UFG::qPropertyList>(this, 0x19u, v3, v);
}

// File Line: 2452
// RVA: 0x1EAF10
void __fastcall UFG::qPropertySet::Set<UFG::qRangedValue<long>>(
        UFG::qPropertySet *this,
        UFG::qArray<unsigned long,0> *name,
        UFG::qRangedValue<long> *v)
{
  unsigned int v3; // eax

  v3 = UFG::qSymbolUC::as_uint32(name);
  UFG::qPropertySet::SetInternal(this, 0xFu, v3, v);
}

// File Line: 2456
// RVA: 0x1EAE90
void __fastcall UFG::qPropertySet::Set<char const *>(
        UFG::qPropertySet *this,
        UFG::qArray<unsigned long,0> *name,
        char *v)
{
  unsigned int v3; // eax

  v3 = UFG::qSymbolUC::as_uint32(name);
  UFG::qPropertySet::SetPtr<char>(this, 0xCu, v3, v);
}

// File Line: 2460
// RVA: 0x1FE910
char __fastcall UFG::qPropertySet::SetVariant(
        UFG::qPropertySet *this,
        UFG::qArray<unsigned long,0> *name,
        qPropertySetVariant *value)
{
  char *UsedSpace; // rax
  __m128 mValueI128; // [rsp+30h] [rbp-18h] BYREF

  switch ( value->meType )
  {
    case UID_int8:
      UFG::qPropertySet::Set<signed char>(this, name, value->mValueI8);
      break;
    case UID_int16:
      UFG::qPropertySet::Set<short>(this, name, value->mValueI16);
      break;
    case UID_int32:
      UFG::qPropertySet::Set<long>(this, name, value->mValueI32);
      break;
    case UID_int64:
      UFG::qPropertySet::Set<__int64>(this, name, value->mValueI64);
      break;
    case UID_int128:
      mValueI128 = value->mValueI128;
      UFG::qPropertySet::Set<__m128>(this, name, &mValueI128);
      break;
    case UID_uint8:
      UFG::qPropertySet::Set<unsigned char>(this, name, value->mValueI8);
      break;
    case UID_uint16:
      UFG::qPropertySet::Set<unsigned short>(this, name, value->mValueI128.m128_u16[0]);
      break;
    case UID_uint32:
      UFG::qPropertySet::Set<unsigned long>(this, name, value->mValueI128.m128_u32[0]);
      break;
    case UID_uint64:
      UFG::qPropertySet::Set<unsigned __int64>(this, name, value->mValueI64);
      break;
    case UID_bool:
      UFG::qPropertySet::Set<bool>(this, name, value->mValueI8);
      break;
    case UID_float:
      UFG::qPropertySet::Set<float>(this, name, value->mValueI128.m128_f32[0]);
      break;
    case UID_double:
    case UID_string:
      UsedSpace = (char *)Scaleform::SysAllocPagedMalloc::GetUsedSpace((hkMemoryResourceContainer *)&value->mValueString);
      UFG::qPropertySet::Set<char const *>(this, name, UsedSpace);
      break;
    case UID_qVector2:
      UFG::qPropertySet::Set<UFG::qVector2>(this, name, &value->mValueVector2);
      break;
    case UID_qVector3:
      UFG::qPropertySet::Set<UFG::qVector3>(this, name, &value->mValueVector3);
      break;
    case UID_qVector4:
      UFG::qPropertySet::Set<UFG::qVector4>(this, name, &value->mValueVector4);
      break;
    case UID_qSymbol:
      UFG::qPropertySet::Set<UFG::qSymbol>(this, name, &value->mValueSymbol);
      break;
    case UID_qSymbolUC:
      UFG::qPropertySet::Set<UFG::qSymbolUC>(this, name, &value->mValueSymbolUC);
      break;
    case UID_qWiseSymbol:
      UFG::qPropertySet::Set<UFG::qWiseSymbol>(this, name, &value->mValueWiseSymbol);
      break;
    default:
      return 1;
  }
  return 1;
}

// File Line: 2527
// RVA: 0x1EA870
char *__fastcall UFG::qPropertySet::GetWithSchema<char const *>(
        UFG::qPropertySet *this,
        UFG::qSymbol *name,
        UFG::qPropertyDepth depth)
{
  UFG::qArray<unsigned long,0> *SchemaForProperty; // [rsp+20h] [rbp-28h]
  UFG::qPropertySet *v5; // [rsp+28h] [rbp-20h]

  SchemaForProperty = (UFG::qArray<unsigned long,0> *)UFG::PropertySetManager::GetSchemaForProperty(this, name);
  if ( !SchemaForProperty )
    return UFG::qPropertySet::Get<char const *>(this, (UFG::qArray<unsigned long,0> *)name, depth);
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(this, SchemaForProperty + 9, depth);
  if ( v5 )
    return UFG::qPropertySet::Get<char const *>(v5, (UFG::qArray<unsigned long,0> *)name, depth);
  else
    return 0i64;
}

// File Line: 2528
// RVA: 0x1EAC30
bool *__fastcall UFG::qPropertySet::GetWithSchema<bool>(
        UFG::qPropertySet *this,
        UFG::qSymbol *name,
        UFG::qPropertyDepth depth)
{
  UFG::qArray<unsigned long,0> *SchemaForProperty; // [rsp+20h] [rbp-28h]
  UFG::qPropertySet *v5; // [rsp+28h] [rbp-20h]

  SchemaForProperty = (UFG::qArray<unsigned long,0> *)UFG::PropertySetManager::GetSchemaForProperty(this, name);
  if ( !SchemaForProperty )
    return UFG::qPropertySet::Get<bool>(this, (UFG::qArray<unsigned long,0> *)name, depth);
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(this, SchemaForProperty + 9, depth);
  if ( v5 )
    return UFG::qPropertySet::Get<bool>(v5, (UFG::qArray<unsigned long,0> *)name, depth);
  else
    return 0i64;
}

// File Line: 2529
// RVA: 0x1EA730
unsigned int *__fastcall UFG::qPropertySet::GetWithSchema<unsigned long>(
        UFG::qPropertySet *this,
        UFG::qSymbol *name,
        UFG::qPropertyDepth depth)
{
  UFG::qArray<unsigned long,0> *SchemaForProperty; // [rsp+20h] [rbp-28h]
  UFG::qPropertySet *v5; // [rsp+28h] [rbp-20h]

  SchemaForProperty = (UFG::qArray<unsigned long,0> *)UFG::PropertySetManager::GetSchemaForProperty(this, name);
  if ( !SchemaForProperty )
    return UFG::qPropertySet::Get<unsigned long>(this, (UFG::qArray<unsigned long,0> *)name, depth);
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(this, SchemaForProperty + 9, depth);
  if ( v5 )
    return UFG::qPropertySet::Get<unsigned long>(v5, (UFG::qArray<unsigned long,0> *)name, depth);
  else
    return 0i64;
}

// File Line: 2530
// RVA: 0x1EA690
int *__fastcall UFG::qPropertySet::GetWithSchema<long>(
        UFG::qPropertySet *this,
        UFG::qSymbol *name,
        UFG::qPropertyDepth depth)
{
  UFG::qArray<unsigned long,0> *SchemaForProperty; // [rsp+20h] [rbp-28h]
  UFG::qPropertySet *v5; // [rsp+28h] [rbp-20h]

  SchemaForProperty = (UFG::qArray<unsigned long,0> *)UFG::PropertySetManager::GetSchemaForProperty(this, name);
  if ( !SchemaForProperty )
    return UFG::qPropertySet::Get<long>(this, (UFG::qArray<unsigned long,0> *)name, depth);
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(this, SchemaForProperty + 9, depth);
  if ( v5 )
    return UFG::qPropertySet::Get<long>(v5, (UFG::qArray<unsigned long,0> *)name, depth);
  else
    return 0i64;
}

// File Line: 2533
// RVA: 0x1EA7D0
float *__fastcall UFG::qPropertySet::GetWithSchema<float>(
        UFG::qPropertySet *this,
        UFG::qSymbol *name,
        UFG::qPropertyDepth depth)
{
  UFG::qArray<unsigned long,0> *SchemaForProperty; // [rsp+20h] [rbp-28h]
  UFG::qPropertySet *v5; // [rsp+28h] [rbp-20h]

  SchemaForProperty = (UFG::qArray<unsigned long,0> *)UFG::PropertySetManager::GetSchemaForProperty(this, name);
  if ( !SchemaForProperty )
    return UFG::qPropertySet::Get<float>(this, (UFG::qArray<unsigned long,0> *)name, depth);
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(this, SchemaForProperty + 9, depth);
  if ( v5 )
    return UFG::qPropertySet::Get<float>(v5, (UFG::qArray<unsigned long,0> *)name, depth);
  else
    return 0i64;
}

// File Line: 2535
// RVA: 0x1EAAF0
UFG::qVector3 *__fastcall UFG::qPropertySet::GetWithSchema<UFG::qVector3>(
        UFG::qPropertySet *this,
        UFG::qSymbol *name,
        UFG::qPropertyDepth depth)
{
  UFG::qArray<unsigned long,0> *SchemaForProperty; // [rsp+20h] [rbp-28h]
  UFG::qPropertySet *v5; // [rsp+28h] [rbp-20h]

  SchemaForProperty = (UFG::qArray<unsigned long,0> *)UFG::PropertySetManager::GetSchemaForProperty(this, name);
  if ( !SchemaForProperty )
    return UFG::qPropertySet::Get<UFG::qVector3>(this, (UFG::qArray<unsigned long,0> *)name, depth);
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(this, SchemaForProperty + 9, depth);
  if ( v5 )
    return UFG::qPropertySet::Get<UFG::qVector3>(v5, (UFG::qArray<unsigned long,0> *)name, depth);
  else
    return 0i64;
}

// File Line: 2536
// RVA: 0x1EAB90
UFG::qVector4 *__fastcall UFG::qPropertySet::GetWithSchema<UFG::qVector4>(
        UFG::qPropertySet *this,
        UFG::qSymbol *name,
        UFG::qPropertyDepth depth)
{
  UFG::qArray<unsigned long,0> *SchemaForProperty; // [rsp+20h] [rbp-28h]
  UFG::qPropertySet *v5; // [rsp+28h] [rbp-20h]

  SchemaForProperty = (UFG::qArray<unsigned long,0> *)UFG::PropertySetManager::GetSchemaForProperty(this, name);
  if ( !SchemaForProperty )
    return UFG::qPropertySet::Get<UFG::qVector4>(this, (UFG::qArray<unsigned long,0> *)name, depth);
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(this, SchemaForProperty + 9, depth);
  if ( v5 )
    return UFG::qPropertySet::Get<UFG::qVector4>(v5, (UFG::qArray<unsigned long,0> *)name, depth);
  else
    return 0i64;
}

// File Line: 2538
// RVA: 0x1EAA50
UFG::qSymbol *__fastcall UFG::qPropertySet::GetWithSchema<UFG::qSymbol>(
        UFG::qPropertySet *this,
        UFG::qSymbol *name,
        UFG::qPropertyDepth depth)
{
  UFG::qArray<unsigned long,0> *SchemaForProperty; // [rsp+20h] [rbp-28h]
  UFG::qPropertySet *v5; // [rsp+28h] [rbp-20h]

  SchemaForProperty = (UFG::qArray<unsigned long,0> *)UFG::PropertySetManager::GetSchemaForProperty(this, name);
  if ( !SchemaForProperty )
    return UFG::qPropertySet::Get<UFG::qSymbol>(this, (UFG::qArray<unsigned long,0> *)name, depth);
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(this, SchemaForProperty + 9, depth);
  if ( v5 )
    return UFG::qPropertySet::Get<UFG::qSymbol>(v5, (UFG::qArray<unsigned long,0> *)name, depth);
  else
    return 0i64;
}

// File Line: 2540
// RVA: 0x1EA9B0
UFG::qPropertySet *__fastcall UFG::qPropertySet::GetWithSchema<UFG::qPropertySet>(
        UFG::qPropertySet *this,
        UFG::qSymbol *name,
        UFG::qPropertyDepth depth)
{
  UFG::qArray<unsigned long,0> *SchemaForProperty; // [rsp+20h] [rbp-28h]
  UFG::qPropertySet *v5; // [rsp+28h] [rbp-20h]

  SchemaForProperty = (UFG::qArray<unsigned long,0> *)UFG::PropertySetManager::GetSchemaForProperty(this, name);
  if ( !SchemaForProperty )
    return UFG::qPropertySet::Get<UFG::qPropertySet>(this, (UFG::qArray<unsigned long,0> *)name, depth);
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(this, SchemaForProperty + 9, depth);
  if ( v5 )
    return UFG::qPropertySet::Get<UFG::qPropertySet>(v5, (UFG::qArray<unsigned long,0> *)name, depth);
  else
    return 0i64;
}

// File Line: 2541
// RVA: 0x1EA910
UFG::qPropertyList *__fastcall UFG::qPropertySet::GetWithSchema<UFG::qPropertyList>(
        UFG::qPropertySet *this,
        UFG::qSymbol *name,
        UFG::qPropertyDepth depth)
{
  UFG::qArray<unsigned long,0> *SchemaForProperty; // [rsp+20h] [rbp-28h]
  UFG::qPropertySet *v5; // [rsp+28h] [rbp-20h]

  SchemaForProperty = (UFG::qArray<unsigned long,0> *)UFG::PropertySetManager::GetSchemaForProperty(this, name);
  if ( !SchemaForProperty )
    return UFG::qPropertySet::Get<UFG::qPropertyList>(this, (UFG::qArray<unsigned long,0> *)name, depth);
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(this, SchemaForProperty + 9, depth);
  if ( v5 )
    return UFG::qPropertySet::Get<UFG::qPropertyList>(v5, (UFG::qArray<unsigned long,0> *)name, depth);
  else
    return 0i64;
}

// File Line: 2567
// RVA: 0x1EBA30
void __fastcall UFG::qPropertySet::SetWithSchema<UFG::qSymbol>(
        UFG::qPropertySet *this,
        UFG::qSymbol *name,
        UFG::qSymbol *v)
{
  UFG::SchemaDef *component_schema; // [rsp+20h] [rbp-18h]
  UFG::qPropertySet *v4; // [rsp+28h] [rbp-10h]

  component_schema = UFG::PropertySetManager::GetSchemaForProperty(this, name);
  if ( component_schema )
  {
    v4 = UFG::PropertySetManager::AddComponentPropertySet(this, component_schema, 0i64);
    if ( v4 )
      UFG::qPropertySet::Set<UFG::qSymbol>(v4, (UFG::qArray<unsigned long,0> *)name, v);
  }
  else
  {
    UFG::qPropertySet::Set<UFG::qSymbol>(this, (UFG::qArray<unsigned long,0> *)name, v);
  }
}

// File Line: 2573
// RVA: 0x1F1B60
void __fastcall UFG::qPropertySet::AddProperty(
        UFG::qPropertySet *this,
        UFG::qArray<unsigned long,0> *name,
        signed int type_uid)
{
  unsigned int v3; // eax
  char *v4; // rax
  UFG::qPropertyList *v5; // rax
  char *v6; // rax
  UFG::qPropertySet *ContainedSet; // rax
  unsigned int v8; // eax
  char dest[72]; // [rsp+30h] [rbp-48h] BYREF

  if ( type_uid < 22 )
    goto LABEL_9;
  if ( type_uid <= 23 )
  {
    v3 = UFG::qSymbolUC::as_uint32(name);
    UFG::qPropertySet::SetInternal(this, type_uid, v3, &UFG::gNullQSymbol);
    return;
  }
  if ( type_uid == 25 )
  {
    v4 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)name);
    v5 = UFG::qPropertyList::Create(v4);
    UFG::qPropertySet::Set<UFG::qPropertyList>(this, name, v5);
    return;
  }
  if ( type_uid == 26 )
  {
    v6 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)name);
    ContainedSet = UFG::qPropertySet::CreateContainedSet((UFG::qSymbol *)name, v6);
    UFG::qPropertySet::Set<UFG::qPropertySet>(this, name, ContainedSet);
  }
  else
  {
LABEL_9:
    UFG::qMemSet(dest, 0, 0x40u);
    v8 = UFG::qSymbolUC::as_uint32(name);
    UFG::qPropertySet::SetInternal(this, type_uid, v8, dest);
  }
}

// File Line: 2609
// RVA: 0x1FF820
_BOOL8 __fastcall UFG::qSortPropertyByOffset(UFG::qProperty *a, UFG::qProperty *b)
{
  unsigned int DataOffset; // [rsp+24h] [rbp-14h]

  DataOffset = UFG::qProperty::GetDataOffset(a);
  return DataOffset < (unsigned int)UFG::qProperty::GetDataOffset(b);
}

// File Line: 2614
// RVA: 0x1FEFA0
void __fastcall UFG::StorePropertyDefaultsInLUT(
        unsigned int *defaults,
        UFG::qProperty *properties,
        unsigned int numProperties)
{
  unsigned int i; // [rsp+4h] [rbp-24h]

  for ( i = 0; i < numProperties; ++i )
  {
    if ( ((1 << (i & 0xDF)) & defaults[i / 0x20]) != 0 )
      properties[i].mTypeUIDOffsetChanged |= 0x80000000;
    else
      properties[i].mTypeUIDOffsetChanged &= ~0x80000000;
  }
}

// File Line: 2634
// RVA: 0x1FC910
void __fastcall UFG::RestorePropertyDefaultsInLUT(
        unsigned int *defaults,
        UFG::qProperty *properties,
        unsigned int numProperties)
{
  unsigned int v3; // eax
  unsigned int i; // [rsp+4h] [rbp-24h]
  unsigned int v5; // [rsp+8h] [rbp-20h]
  char v6; // [rsp+10h] [rbp-18h]

  for ( i = 0; i < numProperties; ++i )
  {
    v5 = i / 0x20;
    v6 = i & 0xDF;
    if ( (properties[i].mTypeUIDOffsetChanged & 0x80000000) == 0 )
      v3 = ~(1 << v6) & defaults[v5];
    else
      v3 = (1 << v6) | defaults[v5];
    defaults[v5] = v3;
    properties[i].mTypeUIDOffsetChanged &= ~0x80000000;
  }
}

// File Line: 2666
// RVA: 0x1FEEB0
void __fastcall UFG::qPropertySet::SortForDynamic(
        unsigned int *defaults,
        UFG::qProperty *properties,
        unsigned int numProperties)
{
  UFG::StorePropertyDefaultsInLUT(defaults, properties, numProperties);
  UFG::qSort<UFG::qProperty,bool (*)(UFG::qProperty const &,UFG::qProperty const &)>(
    properties,
    numProperties,
    UFG::qSortPropertyByOffset);
  UFG::RestorePropertyDefaultsInLUT(defaults, properties, numProperties);
}

// File Line: 2675
// RVA: 0x1F7C70
unsigned int __fastcall UFG::qPropertySet::GetPropertyTypeFromName(
        UFG::qPropertySet *this,
        UFG::qArray<unsigned long,0> *propName,
        UFG::qPropertyDepth depth)
{
  unsigned int j; // [rsp+20h] [rbp-78h]
  unsigned int i; // [rsp+24h] [rbp-74h]
  unsigned int PropertyTypeFromName; // [rsp+28h] [rbp-70h]
  unsigned int mNumParents; // [rsp+38h] [rbp-60h]
  int v8; // [rsp+48h] [rbp-50h]
  UFG::qPropertySet *v9; // [rsp+58h] [rbp-40h]
  UFG::qArray<unsigned long,0> *SchemaForProperty; // [rsp+60h] [rbp-38h]
  char *v11; // [rsp+68h] [rbp-30h]
  UFG::qPropertySet *v12; // [rsp+70h] [rbp-28h]
  char *v13; // [rsp+78h] [rbp-20h]

  v8 = UFG::qSymbolUC::as_uint32(propName);
  for ( i = 0; i < this->mNumProperties; ++i )
  {
    if ( this->mProperties.mOffset )
      v13 = (char *)&this->mProperties + this->mProperties.mOffset;
    else
      v13 = 0i64;
    if ( *(_DWORD *)&v13[8 * i + 4] == v8 )
      return UFG::qProperty::GetTypeUID((UFG::qProperty *)&v13[8 * i]);
  }
  if ( depth == DEPTH_RECURSE )
  {
    if ( this->mParents.mOffset )
      v11 = (char *)&this->mParents + this->mParents.mOffset;
    else
      v11 = 0i64;
    mNumParents = this->mNumParents;
    for ( j = 0; j < mNumParents; ++j )
    {
      v9 = (UFG::qPropertySet *)UFG::qPropertySetHandle::Get((UFG::qPropertySetHandle *)&v11[32 * j]);
      if ( v9 )
      {
        PropertyTypeFromName = UFG::qPropertySet::GetPropertyTypeFromName(v9, (UFG::qSymbol *)propName, DEPTH_RECURSE);
        if ( PropertyTypeFromName != 29 )
          return PropertyTypeFromName;
      }
    }
  }
  SchemaForProperty = (UFG::qArray<unsigned long,0> *)UFG::PropertySetManager::GetSchemaForProperty(
                                                        this,
                                                        (UFG::qSymbol *)propName);
  if ( SchemaForProperty
    && (v12 = UFG::qPropertySet::Get<UFG::qPropertySet>(this, SchemaForProperty + 9, depth)) != 0i64 )
  {
    return UFG::qPropertySet::GetPropertyTypeFromName(v12, (UFG::qSymbol *)propName, depth);
  }
  else
  {
    return 29;
  }
}

