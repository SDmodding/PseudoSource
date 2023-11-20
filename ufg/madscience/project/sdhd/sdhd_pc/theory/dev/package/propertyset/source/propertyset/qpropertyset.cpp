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
  float v3; // ST38_4
  float v4; // ST2C_4
  hkSeekableStreamReader *v5; // ST30_8
  signed __int64 v6; // ST40_8
  int v7; // ST20_4
  int v8; // ST28_4
  UFG::qVector4 v; // [rsp+4Ch] [rbp-1Ch]
  UFG::qTransQuat *v10; // [rsp+70h] [rbp+8h]
  UFG::qQuaternion *v11; // [rsp+80h] [rbp+18h]

  v11 = trans;
  v10 = this;
  v3 = rot->y;
  v4 = rot->z;
  v.x = rot->x;
  v.y = v3;
  v.z = v4;
  LODWORD(v.w) = (_DWORD)FLOAT_1_0;
  UFG::qQuaternion::qQuaternion(&this->mRot, &v);
  v5 = Assembly::GetRCX(v11);
  v6 = (signed __int64)&v10->mTrans;
  v7 = HIDWORD(v5->vfptr);
  v8 = *(_DWORD *)&v5->m_memSizeAndFlags;
  v10->mTrans.x = *(float *)&v5->vfptr;
  *(_DWORD *)(v6 + 4) = v7;
  *(_DWORD *)(v6 + 8) = v8;
}

// File Line: 85
// RVA: 0x1F66E0
UFG::qPropertyType *__fastcall UFG::qPropertyType::Get(unsigned int type_name_uid)
{
  if ( !(_S1_25 & 1) )
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
}29]

// File Line: 206
// RVA: 0x1F9A90
_BOOL8 __fastcall UFG::qPropertyType::IsPtrType(unsigned int type_uid)
{
  return type_uid == 26 || type_uid == 25 || type_uid == 12;
}

// File Line: 218
// RVA: 0x1FF7C0
UFG::allocator::free_link *__fastcall UFG::qPropertySet_Allocate(unsigned int byte_count, const char *dbg_tag, unsigned int flags)
{
  return UFG::qMemoryPool::Allocate(&gPropertySetMemoryPool, byte_count, dbg_tag, flags, 1u);
}

// File Line: 227
// RVA: 0x1FF800
void __fastcall UFG::qPropertySet_Free(void *buffer)
{
  UFG::qMemoryPool::Free(&gPropertySetMemoryPool, buffer);
}

// File Line: 242
// RVA: 0x1F6680
UFG::qResourceData *__fastcall UFG::qPropertySetHandle::Get(UFG::qPropertySetHandle *this)
{
  UFG::qPropertySetHandle *v2; // [rsp+40h] [rbp+8h]

  v2 = this;
  if ( !(unsigned __int8)CAkVPLSrcNode::MustRelocateAnalysisDataOnMediaRelocation((CAkVPLSrcNode *)this) )
    return 0i64;
  if ( v2->mNext )
    return (UFG::qResourceData *)UFG::qPropertySetResource::GetPropertySet((UFG::qPropertySetResource *)v2->mData);
  return v2->mData;
}

// File Line: 269
// RVA: 0x1F25A0
void __fastcall UFG::qPropertySetHandle::Close(UFG::qPropertySetHandle *this)
{
  UFG::qResourceInventory *v1; // rax
  UFG::qPropertySetHandle *v2; // [rsp+30h] [rbp+8h]

  v2 = this;
  if ( this->mNext )
  {
    v1 = UFG::qGetResourceInventory<UFG::qPropertySetResource>(0x54606C31u);
    UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v2->mPrev, v1);
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
    this->0 = 0ui64;
    this->mData = other->mData;
    this->mNameUID = other->mNameUID;
  }
}

// File Line: 296
// RVA: 0x1F96C0
void __fastcall UFG::qPropertySetHandle::Init(UFG::qPropertySetHandle *this)
{
  UFG::qResourceInventory *v1; // rax
  UFG::qPropertySetHandle *v2; // [rsp+30h] [rbp+8h]

  v2 = this;
  v1 = UFG::qGetResourceInventory<UFG::qPropertySetResource>(0x54606C31u);
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v2->mPrev, 0x54606C31u, v2->mNameUID, v1);
}

// File Line: 303
// RVA: 0x1F9680
void __fastcall UFG::qPropertySetHandle::Init(UFG::qPropertySetHandle *this, unsigned int resource_uid)
{
  UFG::qResourceInventory *v2; // rax
  UFG::qPropertySetHandle *v3; // [rsp+30h] [rbp+8h]
  unsigned int name_uid; // [rsp+38h] [rbp+10h]

  name_uid = resource_uid;
  v3 = this;
  v2 = UFG::qGetResourceInventory<UFG::qPropertySetResource>(0x54606C31u);
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v3->mPrev, 0x54606C31u, name_uid, v2);
}

// File Line: 310
// RVA: 0x1F9700
void __fastcall UFG::qPropertySetHandle::InitTempNonResourcePropSet(UFG::qPropertySetHandle *this, UFG::qPropertySet *parent)
{
  UFG::qArray<unsigned long,0> *v2; // rax
  UFG::qPropertySetHandle *v3; // [rsp+30h] [rbp+8h]

  v3 = this;
  this->mNext = 0i64;
  this->mPrev = 0i64;
  this->mData = (UFG::qResourceData *)parent;
  v2 = (UFG::qArray<unsigned long,0> *)UFG::qPropertySet::GetName(parent);
  v3->mNameUID = UFG::qSymbolUC::as_uint32(v2);
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
void __fastcall UFG::qPropertyCollection::qPropertyCollection(UFG::qPropertyCollection *this, MemImageLoadFlag __formal)
{
  ;
}

// File Line: 353
// RVA: 0x1FE280
void __fastcall UFG::qPropertyCollection::SetOwner(UFG::qPropertyCollection *this, UFG::qPropertySet *owningSet)
{
  UFG::qOffset64<UFG::qPropertyCollection *> *v2; // [rsp+0h] [rbp-18h]
  char *v3; // [rsp+8h] [rbp-10h]

  v2 = &this->mOwner;
  if ( owningSet )
    v3 = (char *)((char *)owningSet - (char *)v2);
  else
    v3 = 0i64;
  v2->mOffset = (__int64)v3;
  this->mFlags &= 0xFFFFFFDF;
  this->mFlags |= 0x10u;
}

// File Line: 360
// RVA: 0x1FE200
void __fastcall UFG::qPropertyCollection::SetOwner(UFG::qPropertyCollection *this, UFG::qPropertyList *owningList)
{
  UFG::qOffset64<UFG::qPropertyCollection *> *v2; // [rsp+0h] [rbp-18h]
  char *v3; // [rsp+8h] [rbp-10h]

  v2 = &this->mOwner;
  if ( owningList )
    v3 = (char *)((char *)owningList - (char *)v2);
  else
    v3 = 0i64;
  v2->mOffset = (__int64)v3;
  this->mFlags &= 0xFFFFFFEF;
  this->mFlags |= 0x20u;
}

// File Line: 371
// RVA: 0x146BE70
__int64 UFG::_dynamic_initializer_for__gPropertySetInventory__()
{
  UFG::qPropertySetInventory::qPropertySetInventory(&UFG::gPropertySetInventory);
  return atexit(UFG::_dynamic_atexit_destructor_for__gPropertySetInventory__);
}

// File Line: 375
// RVA: 0x1EDDA0
void __fastcall UFG::qPropertySetInventory::qPropertySetInventory(UFG::qPropertySetInventory *this)
{
  UFG::qArray<unsigned long,0> *v1; // ST30_8
  UFG::qPropertySetInventory *v2; // [rsp+50h] [rbp+8h]

  v2 = this;
  UFG::qResourceInventory::qResourceInventory(
    (UFG::qResourceInventory *)&this->vfptr,
    "qPropertySetInventory",
    0x54606C31u,
    0x5B9BF81Eu,
    0,
    0);
  v2->vfptr = (UFG::qResourceInventoryVtbl *)&UFG::qPropertySetInventory::`vftable';
  v1 = &v2->mPurgedResources;
  v2->mPurgedResources.p = 0i64;
  v1->size = 0;
  v1->capacity = 0;
}

// File Line: 399
// RVA: 0x1EFAB0
void __fastcall UFG::qPropertySetInventory::Add(UFG::qPropertySetInventory *this, UFG::qResourceData *resource_data)
{
  UFG::qPropertySet *v2; // rax
  unsigned int i; // [rsp+20h] [rbp-48h]
  UFG::qPropertySetResource *v4; // [rsp+28h] [rbp-40h]
  signed int v5; // [rsp+30h] [rbp-38h]
  int v6; // [rsp+34h] [rbp-34h]
  UFG::qPropertySetResource *v7; // [rsp+48h] [rbp-20h]
  UFG::qPropertySetInventory *v8; // [rsp+70h] [rbp+8h]
  BasicArrayImplementation<hkDataObjectImpl *> *v9; // [rsp+78h] [rbp+10h]

  v9 = (BasicArrayImplementation<hkDataObjectImpl *> *)resource_data;
  v8 = this;
  v4 = (UFG::qPropertySetResource *)resource_data;
  if ( !(unsigned __int8)UFG::qPropertySetResource::IsMemImaged((UFG::qPropertySetResource *)resource_data) )
    goto LABEL_16;
  v6 = BasicArrayImplementation<hkDataArrayImpl *>::getSize(v9);
  for ( i = 0; i < v8->mPurgedResources.size; ++i )
  {
    if ( v6 == v8->mPurgedResources.p[i] )
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
    if ( UFG::qPropertySetResource::GetFlags(v4, 1) )
    {
      v7 = (UFG::qPropertySetResource *)UFG::qPropertyList::operator new((hkObjectCopier *)0xC0, (hkClass *)v4);
      if ( v7 )
        UFG::qPropertySetResource::qPropertySetResource(v7);
    }
    UFG::qPropertySetResource::SetFlags(v4, 2);
    UFG::qResourceInventory::Add((UFG::qResourceInventory *)&v8->vfptr, (UFG::qResourceData *)v9);
    if ( UFG::qPropertySetResource::GetFlags(v4, 1) )
    {
      v2 = UFG::qPropertySetResource::GetPropertySet(v4);
      UFG::PostLoadSchemaCreateCheck(v2, 0i64, 0i64);
    }
  }
}

// File Line: 430
// RVA: 0x1FB780
void __fastcall UFG::qPropertySetInventory::Remove(UFG::qPropertySetInventory *this, UFG::qResourceData *resource_data)
{
  UFG::qPropertySetInventory *v2; // [rsp+40h] [rbp+8h]
  UFG::qPropertySetResource *data; // [rsp+48h] [rbp+10h]

  data = (UFG::qPropertySetResource *)resource_data;
  v2 = this;
  if ( (unsigned int)UFG::qPropertySetResource::GetFlags((UFG::qPropertySetResource *)resource_data, 2) )
  {
    UFG::qResourceInventory::Remove((UFG::qResourceInventory *)&v2->vfptr, (UFG::qResourceData *)&data->mNode);
    UFG::qPropertySetResource::ClearFlags(data, 2);
    if ( (unsigned int)UFG::qPropertySetResource::GetFlags(data, 1) )
      UFG::qPropertySetResource::~qPropertySetResource(data);
  }
}

// File Line: 576
// RVA: 0x1EDE70
void __fastcall UFG::qPropertySetResource::qPropertySetResource(UFG::qPropertySetResource *this, const char *set_name)
{
  unsigned int v2; // eax
  UFG::qSymbol result; // [rsp+20h] [rbp-38h]
  __int128 v4; // [rsp+28h] [rbp-30h]
  UFG::qSymbol *v5; // [rsp+38h] [rbp-20h]
  UFG::qSymbol *name; // [rsp+40h] [rbp-18h]
  __int64 v7; // [rsp+48h] [rbp-10h]
  UFG::qPropertySetResource *v8; // [rsp+60h] [rbp+8h]
  char *str; // [rsp+68h] [rbp+10h]

  str = (char *)set_name;
  v8 = this;
  v7 = -2i64;
  v2 = UFG::qStringHash32(set_name, 0xFFFFFFFF);
  UFG::qResourceData::qResourceData((UFG::qResourceData *)&v8->mNode, 0x54606C31u, v2, str);
  v5 = UFG::qSymbol::create_from_string(&result, str);
  name = v5;
  UFG::qPropertySet::qPropertySet(&v8->mData, v5);
  _((AMD_HD3D *)&result);
  v8->mFlags = 0;
  v8->mSourceCRC = -1;
  v4 = (unsigned __int64)&v8->mNameString;
  *(_QWORD *)v4 = 0i64;
  UFG::qPropertyCollection::SetFlags((UFG::qPropertyCollection *)&v8->mData.mFlags, 0x10000);
  UFG::qPropertySet::SetType(&v8->mData, F5_1Pt2_512);
  UFG::qPropertySetResource::SetName(v8, str);
}

// File Line: 588
// RVA: 0x1EDE30
void __fastcall UFG::qPropertySetResource::qPropertySetResource(UFG::qPropertySetResource *this)
{
  UFG::qPropertySetResource *v1; // [rsp+40h] [rbp+8h]

  v1 = this;
  UFG::qResourceData::qResourceData((UFG::qResourceData *)&this->mNode);
  UFG::qPropertySet::qPropertySet(&v1->mData);
}

// File Line: 594
// RVA: 0x1EEBE0
void __fastcall UFG::qPropertySetResource::~qPropertySetResource(UFG::qPropertySetResource *this)
{
  UFG::qPropertySetResource *v1; // [rsp+40h] [rbp+8h]

  v1 = this;
  if ( !UFG::qPropertySetResource::GetFlags(this, 1) )
    UFG::qPropertySetResource::SetName(v1, 0i64);
  UFG::qPropertySet::~qPropertySet(&v1->mData);
  UFG::qResourceData::~qResourceData((UFG::qResourceData *)&v1->mNode);
}

// File Line: 602
// RVA: 0x1FE060
void __fastcall UFG::qPropertySetResource::SetName(UFG::qPropertySetResource *this, const char *set_name)
{
  int v2; // ST30_4
  char *dest; // [rsp+38h] [rbp-40h]
  signed __int64 v4; // [rsp+40h] [rbp-38h]
  UFG::qOffset64<char const *> *v5; // [rsp+58h] [rbp-20h]
  signed __int64 v6; // [rsp+68h] [rbp-10h]
  UFG::qPropertySetResource *v7; // [rsp+80h] [rbp+8h]
  char *text; // [rsp+88h] [rbp+10h]

  text = (char *)set_name;
  v7 = this;
  if ( !(unsigned int)UFG::qPropertySetResource::GetFlags(this, 1) )
  {
    if ( v7->mNameString.mOffset )
      v4 = (signed __int64)&v7->mNameString + v7->mNameString.mOffset;
    else
      v4 = 0i64;
    if ( v4 )
    {
      if ( v7->mNameString.mOffset )
        UFG::qPropertySet_Free((char *)&v7->mNameString + v7->mNameString.mOffset);
      else
        UFG::qPropertySet_Free(0i64);
      v7->mNameString.mOffset = 0i64;
    }
    if ( text )
    {
      v2 = UFG::qStringLength(text);
      dest = (char *)UFG::qPropertySet_Allocate(v2 + 1, "qPropertySetResource name", 0);
      UFG::qStringCopy(dest, text);
      v5 = &v7->mNameString;
      if ( dest )
        v6 = dest - (char *)v5;
      else
        v6 = 0i64;
      v5->mOffset = v6;
    }
  }
}

// File Line: 622
// RVA: 0x1FC850
void __fastcall UFG::qPropertySetResource::Rename(UFG::qPropertySetResource *this, const char *nameString)
{
  bool v2; // [rsp+20h] [rbp-28h]
  UFG::qSymbol result; // [rsp+24h] [rbp-24h]
  unsigned int uid; // [rsp+28h] [rbp-20h]
  __int64 v5; // [rsp+30h] [rbp-18h]
  UFG::qPropertySetResource *pPropResource; // [rsp+50h] [rbp+8h]
  char *pszSymbolString; // [rsp+58h] [rbp+10h]

  pszSymbolString = (char *)nameString;
  pPropResource = this;
  v5 = -2i64;
  v2 = UFG::PropertySetCache::Contains(this);
  if ( v2 )
    UFG::PropertySetCache::Remove(pPropResource);
  UFG::qSymbol::create_from_string(&result, pszSymbolString);
  UFG::qPropertySetResource::SetName(pPropResource, pszSymbolString);
  uid = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)&result);
  UFG::qBaseNodeRB::SetUID(&pPropResource->mNode, uid);
  UFG::qResourceData::SetDebugName((UFG::qResourceData *)&pPropResource->mNode, pszSymbolString);
  UFG::qPropertySet::SetName(&pPropResource->mData, &result);
  if ( v2 )
    UFG::PropertySetCache::Add(pPropResource);
  _((AMD_HD3D *)&result);
}

// File Line: 651
// RVA: 0x1EDB90
void __fastcall UFG::qPropertySet::qPropertySet(UFG::qPropertySet *this, UFG::qSymbol *name)
{
  UFG::qPropertySet *v2; // [rsp+80h] [rbp+8h]
  UFG::qSymbol *source; // [rsp+88h] [rbp+10h]

  source = name;
  v2 = this;
  UFG::qPropertyCollection::qPropertyCollection((UFG::qPropertyCollection *)&this->mFlags);
  v2->mPrev = (UFG::qNode<UFG::qPropertySet,UFG::qPropertySet> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qPropertySet,UFG::qPropertySet> *)&v2->mPrev;
  UFG::qSymbol::qSymbol(&v2->mName, source);
  BackInfo::BackInfo(&v2->mSchemaName);
  v2->mParents.mOffset = 0i64;
  v2->mProperties.mOffset = 0i64;
  v2->mValues.mOffset = 0i64;
  v2->mDefaultBits.mOffset = 0i64;
  v2->mNumDataBytes = 0;
  v2->mRefCount = 0;
  v2->mNumProperties = 0;
  v2->mNumParents = 0;
  v2->mFlags = 2;
  v2->mPropertyMask = -1;
  v2->mParentMask = -1;
  UFG::qSymbol::set_null(&v2->mSchemaName);
}

// File Line: 671
// RVA: 0x1F4140
UFG::qPropertySet *__fastcall UFG::qPropertySet::CreateContainedSet(UFG::qSymbol *name, const char *dbg_tag)
{
  __int64 v2; // rax
  UFG::qPropertySet *v4; // [rsp+20h] [rbp-38h]
  UFG::qSymbol *v6; // [rsp+60h] [rbp+8h]

  v6 = name;
  v4 = (UFG::qPropertySet *)UFG::qPropertySet::operator new(0x58ui64, dbg_tag);
  if ( !v4 )
    return 0i64;
  UFG::qPropertySet::qPropertySet(v4, v6);
  return (UFG::qPropertySet *)v2;
}

// File Line: 677
// RVA: 0x1F46E0
UFG::qPropertySet *__fastcall UFG::qPropertySet::CreateResourceSet(UFG::qSymbol *name, const char *dbg_tag)
{
  char *v2; // rax
  UFG::qPropertySetResource *v3; // rax
  UFG::qPropertySetResource *v5; // [rsp+20h] [rbp-38h]
  UFG::qPropertySetResource *v6; // [rsp+28h] [rbp-30h]
  UFG::qSymbolUC *v7; // [rsp+60h] [rbp+8h]

  v7 = (UFG::qSymbolUC *)name;
  v5 = (UFG::qPropertySetResource *)UFG::qPropertySet::operator new(0xC0ui64, dbg_tag);
  if ( v5 )
  {
    v2 = UFG::qSymbol::as_cstr_dbg(v7);
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
  UFG::qSymbol *v1; // rax
  UFG::qPropertySet *v2; // rax
  UFG::qPropertySet *v4; // [rsp+20h] [rbp-38h]
  UFG::qPropertySet *v5; // [rsp+28h] [rbp-30h]
  UFG::qPropertySet *source_set; // [rsp+60h] [rbp+8h]

  source_set = this;
  v4 = (UFG::qPropertySet *)UFG::qPropertySet::operator new(0x58ui64);
  if ( v4 )
  {
    v1 = UFG::qPropertySet::GetName(source_set);
    UFG::qPropertySet::qPropertySet(v4, v1);
    v5 = v2;
  }
  else
  {
    v5 = 0i64;
  }
  UFG::qPropertySet::CopyFrom(v5, source_set, 1);
  return v5;
}

// File Line: 691
// RVA: 0x1F50F0
void __fastcall UFG::qPropertySet::Destroy(UFG::qPropertySet *this)
{
  UFG::qPropertySetResource *v1; // [rsp+20h] [rbp-48h]
  UFG::qPropertySet *v2; // [rsp+70h] [rbp+8h]

  v2 = this;
  if ( !UFG::qPropertyCollection::IsMemImaged((UFG::qPropertyCollection *)&this->mFlags) )
  {
    if ( (unsigned __int8)UFG::qPropertySet::IsResourceSet(v2) )
    {
      v1 = UFG::qPropertySet::GetResource(v2);
      if ( v1 )
      {
        UFG::qPropertySetResource::~qPropertySetResource(v1);
        UFG::qPropertySet::operator delete(v1, 0xC0ui64);
      }
    }
    else if ( v2 )
    {
      UFG::qPropertySet::`scalar deleting destructor'(v2, 1);
    }
  }
}

// File Line: 709
// RVA: 0x1FB1A0
UFG::qSymbol *__fastcall UFG::RecursiveSchemaGet(UFG::qPropertySet *propertySet)
{
  UFG::qPropertySet *v2; // ST38_8
  unsigned int parent_index; // [rsp+20h] [rbp-28h]
  unsigned int v4; // [rsp+24h] [rbp-24h]
  UFG::qSymbol *v5; // [rsp+28h] [rbp-20h]
  UFG::qSymbol *v6; // [rsp+30h] [rbp-18h]
  UFG::qPropertySet *v7; // [rsp+50h] [rbp+8h]

  v7 = propertySet;
  v5 = UFG::qPropertySet::GetSchemaName(propertySet);
  if ( UFG::qSymbol::operator!=(v5, &UFG::gNullQSymbol) )
    return v5;
  if ( (unsigned int)UFG::qPropertyCollection::GetFlags((UFG::qPropertyCollection *)&v7->mFlags, 0x80000) )
  {
    v4 = UFG::qPropertySet::NumParents(v7);
    if ( v4 )
    {
      for ( parent_index = 0; parent_index < v4; ++parent_index )
      {
        v2 = (UFG::qPropertySet *)UFG::qPropertySet::GetParentFromIdx(v7, parent_index);
        v6 = UFG::RecursiveSchemaGet(v2);
        if ( UFG::qSymbol::operator!=(v6, &UFG::gNullQSymbol) )
          return v6;
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
  unsigned int *v2; // rax
  __int64 v3; // rdx
  unsigned int *v4; // rax
  __int64 v5; // rdx
  UFG::qSymbol *v6; // rax
  UFG::SchemaDef *v7; // rax
  UFG::qNode<UFG::qPropertySet,UFG::qPropertySet> *v8; // ST38_8
  UFG::qNode<UFG::qPropertySet,UFG::qPropertySet> *v9; // STD0_8
  __int64 v10; // rax
  __int64 v11; // rax
  unsigned int i; // [rsp+20h] [rbp-178h]
  unsigned int j; // [rsp+24h] [rbp-174h]
  UFG::qPropertySet *v14; // [rsp+30h] [rbp-168h]
  UFG::qProperty *v15; // [rsp+40h] [rbp-158h]
  signed __int64 v16; // [rsp+58h] [rbp-140h]
  unsigned int v17; // [rsp+60h] [rbp-138h]
  UFG::qResourceHandle *v18; // [rsp+80h] [rbp-118h]
  _QWORD *v19; // [rsp+88h] [rbp-110h]
  unsigned int v20; // [rsp+90h] [rbp-108h]
  _QWORD *v21; // [rsp+98h] [rbp-100h]
  __int64 v22; // [rsp+A8h] [rbp-F0h]
  signed __int64 v23; // [rsp+B8h] [rbp-E0h]
  __int64 v24; // [rsp+C0h] [rbp-D8h]
  signed __int64 v25; // [rsp+C8h] [rbp-D0h]
  hkClass *v26; // [rsp+D8h] [rbp-C0h]
  UFG::qOffset64<UFG::qProperty *> *v27; // [rsp+E0h] [rbp-B8h]
  UFG::qPropertySet *v28; // [rsp+E8h] [rbp-B0h]
  __int64 v29; // [rsp+F0h] [rbp-A8h]
  signed __int64 v30; // [rsp+F8h] [rbp-A0h]
  signed __int64 v31; // [rsp+100h] [rbp-98h]
  hkClass *v32; // [rsp+108h] [rbp-90h]
  UFG::qPropertyList *v33; // [rsp+118h] [rbp-80h]
  MemImageLoadFlag v34; // [rsp+120h] [rbp-78h]
  hkClass *v35; // [rsp+128h] [rbp-70h]
  hkClass *v36; // [rsp+130h] [rbp-68h]
  MemImageLoadFlag v37; // [rsp+138h] [rbp-60h]
  __int64 v38; // [rsp+140h] [rbp-58h]
  MemImageLoadFlag v39; // [rsp+148h] [rbp-50h]
  UFG::qNode<UFG::qPropertySet,UFG::qPropertySet> *v40; // [rsp+150h] [rbp-48h]
  UFG::qSymbol *name; // [rsp+158h] [rbp-40h]
  __int64 v42; // [rsp+160h] [rbp-38h]
  __int64 v43; // [rsp+168h] [rbp-30h]
  __int64 v44; // [rsp+170h] [rbp-28h]
  __int64 v45; // [rsp+178h] [rbp-20h]
  __int64 v46; // [rsp+180h] [rbp-18h]
  UFG::qPropertySet *v47; // [rsp+1A0h] [rbp+8h]

  v47 = this;
  v42 = -2i64;
  UFG::PersistentData::Float::Float(&v34);
  UFG::qPropertyCollection::qPropertyCollection((UFG::qPropertyCollection *)&v47->mFlags, (MemImageLoadFlag)v1->flag);
  v47->mPrev = (UFG::qNode<UFG::qPropertySet,UFG::qPropertySet> *)&v47->mPrev;
  v47->mNext = (UFG::qNode<UFG::qPropertySet,UFG::qPropertySet> *)&v47->mPrev;
  UFG::PersistentData::Float::Float(&v39);
  v3 = *v2;
  Assembly::GetRCX(&v47->mName);
  UFG::PersistentData::Float::Float(&v37);
  v5 = *v4;
  Assembly::GetRCX(&v47->mSchemaName);
  v17 = v47->mNumParents;
  for ( i = 0; i < v17; ++i )
  {
    if ( v47->mParents.mOffset )
      v30 = (signed __int64)&v47->mParents + v47->mParents.mOffset;
    else
      v30 = 0i64;
    v18 = (UFG::qResourceHandle *)UFG::qPropertyList::operator new((hkObjectCopier *)0x20, (hkClass *)(32i64 * i + v30));
    if ( v18 )
    {
      UFG::qResourceHandle::qResourceHandle(v18);
      v29 = (__int64)v18;
    }
    else
    {
      v29 = 0i64;
    }
    v45 = v29;
    UFG::qPropertySetHandle::Init((UFG::qPropertySetHandle *)(32i64 * i + v30));
  }
  if ( (unsigned int)UFG::qPropertyCollection::GetFlags((UFG::qPropertyCollection *)&v47->mFlags, 0x80000) )
  {
    name = UFG::RecursiveSchemaGet(v47);
    UFG::qPropertySet::SetSchemaName(v47, name);
  }
  if ( UFG::qSymbol::operator!=(&v47->mSchemaName, &UFG::gNullQSymbol) )
  {
    v6 = UFG::qPropertySet::GetName(v47);
    if ( UFG::qSymbol::operator!=(&v47->mSchemaName, v6) )
    {
      v7 = UFG::PropertySetManager::GetSchema(&v47->mSchemaName);
      v43 = 16i64;
      v40 = (UFG::qNode<UFG::qPropertySet,UFG::qPropertySet> *)&v47->mPrev;
      v8 = (UFG::qNode<UFG::qPropertySet,UFG::qPropertySet> *)&v47->mPrev;
      v9 = v7->mPropertySetInstances.mNode.mPrev;
      v9->mNext = (UFG::qNode<UFG::qPropertySet,UFG::qPropertySet> *)&v47->mPrev;
      v8->mPrev = v9;
      v8->mNext = &v7->mPropertySetInstances.mNode;
      v7->mPropertySetInstances.mNode.mPrev = (UFG::qNode<UFG::qPropertySet,UFG::qPropertySet> *)&v47->mPrev;
      v14 = UFG::qPropertySetHandle::Get(&v7->mPropertySet);
      v27 = &v47->mProperties;
      if ( v14->mProperties.mOffset )
        v16 = (signed __int64)&v14->mProperties + v14->mProperties.mOffset;
      else
        v16 = 0i64;
      if ( v16 )
        v31 = v16 - (_QWORD)v27;
      else
        v31 = 0i64;
      v27->mOffset = v31;
      v47->mNumDataBytes = v14->mNumDataBytes;
      v47->mNumProperties = v14->mNumProperties;
      v47->mPropertyMask = v14->mPropertyMask;
    }
  }
  if ( v47->mFlags & 0x400000 )
  {
    if ( v47->mProperties.mOffset )
      v23 = (signed __int64)&v47->mProperties + v47->mProperties.mOffset;
    else
      v23 = 0i64;
    v38 = v23;
    if ( v47->mValues.mOffset )
      v25 = (signed __int64)&v47->mValues + v47->mValues.mOffset;
    else
      v25 = 0i64;
    v20 = v47->mNumProperties;
    for ( j = 0; j < v20; ++j )
    {
      v15 = (UFG::qProperty *)(v38 + 8i64 * j);
      if ( (unsigned int)UFG::qProperty::GetTypeUID((UFG::qProperty *)(v38 + 8i64 * j)) == 26 )
      {
        v19 = (_QWORD *)((unsigned int)UFG::qProperty::GetDataOffset(v15) + v25);
        if ( *v19 )
          v26 = (hkClass *)((char *)v19 + *v19);
        else
          v26 = 0i64;
        v35 = v26;
        v28 = (UFG::qPropertySet *)UFG::qPropertyList::operator new((hkObjectCopier *)0x58, v26);
        if ( v28 )
        {
          UFG::qPropertySet::qPropertySet(v28);
          v22 = v10;
        }
        else
        {
          v22 = 0i64;
        }
        v44 = v22;
      }
      else if ( (unsigned int)UFG::qProperty::GetTypeUID(v15) == 25 )
      {
        v21 = (_QWORD *)((unsigned int)UFG::qProperty::GetDataOffset(v15) + v25);
        if ( *v21 )
          v32 = (hkClass *)((char *)v21 + *v21);
        else
          v32 = 0i64;
        v36 = v32;
        v33 = (UFG::qPropertyList *)UFG::qPropertyList::operator new((hkObjectCopier *)0x30, v32);
        if ( v33 )
        {
          UFG::qPropertyList::qPropertyList(v33);
          v24 = v11;
        }
        else
        {
          v24 = 0i64;
        }
        v46 = v24;
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
  unsigned int v4; // [rsp+40h] [rbp-98h]
  _QWORD *v5; // [rsp+48h] [rbp-90h]
  _QWORD *v6; // [rsp+58h] [rbp-80h]
  signed __int64 v7; // [rsp+60h] [rbp-78h]
  signed __int64 v8; // [rsp+78h] [rbp-60h]
  UFG::qPropertySet *v9; // [rsp+90h] [rbp-48h]
  char *v10; // [rsp+98h] [rbp-40h]
  UFG::qPropertyList *v11; // [rsp+A0h] [rbp-38h]
  UFG::qPropertySet *v12; // [rsp+E0h] [rbp+8h]

  v12 = this;
  if ( this->mParents.mOffset )
    v10 = (char *)&this->mParents + this->mParents.mOffset;
  else
    v10 = 0i64;
  for ( i = 0; i < v12->mNumParents; ++i )
    UFG::qPropertySetHandle::Close((UFG::qPropertySetHandle *)&v10[32 * i]);
  if ( (unsigned int)UFG::qPropertyCollection::GetFlags((UFG::qPropertyCollection *)&v12->mFlags, 1) )
  {
    if ( v12->mFlags & 0x400000 )
    {
      if ( v12->mProperties.mOffset )
        v7 = (signed __int64)&v12->mProperties + v12->mProperties.mOffset;
      else
        v7 = 0i64;
      if ( v12->mValues.mOffset )
        v8 = (signed __int64)&v12->mValues + v12->mValues.mOffset;
      else
        v8 = 0i64;
      v4 = v12->mNumProperties;
      for ( j = 0; j < v4; ++j )
      {
        v3 = (UFG::qProperty *)(v7 + 8i64 * j);
        if ( (unsigned int)UFG::qProperty::GetTypeUID((UFG::qProperty *)(v7 + 8i64 * j)) == 26 )
        {
          v5 = (_QWORD *)((unsigned int)UFG::qProperty::GetDataOffset(v3) + v8);
          if ( *v5 )
            v9 = (UFG::qPropertySet *)((char *)v5 + *v5);
          else
            v9 = 0i64;
          UFG::qPropertySet::`scalar deleting destructor'(v9, 0);
        }
        else if ( (unsigned int)UFG::qProperty::GetTypeUID(v3) == 25 )
        {
          v6 = (_QWORD *)((unsigned int)UFG::qProperty::GetDataOffset(v3) + v8);
          if ( *v6 )
            v11 = (UFG::qPropertyList *)((char *)v6 + *v6);
          else
            v11 = 0i64;
          UFG::qPropertyList::`scalar deleting destructor'(v11, 0);
        }
      }
    }
  }
  else
  {
    UFG::qPropertySet::RemovePropertiesAllLocal(v12);
    UFG::qPropertySet_Free(v10);
    v12->mParents.mOffset = 0i64;
    v12->mNumParents = 0;
  }
  UFG::qPropertyCollection::SetFlags((UFG::qPropertyCollection *)&v12->mFlags, 8);
  _((AMD_HD3D *)&v12->mSchemaName);
  _((AMD_HD3D *)&v12->mName);
  UFG::qNode<UFG::qPropertySet,UFG::qPropertySet>::~qNode<UFG::qPropertySet,UFG::qPropertySet>((UFG::qNode<UFG::qPropertySet,UFG::qPropertySet> *)&v12->mPrev);
}

// File Line: 874
// RVA: 0x1F29A0
void __fastcall UFG::qPropertySet::CopyFrom(UFG::qPropertySet *this, UFG::qPropertySet *source_set, bool copyParents)
{
  UFG::qPropertySet::Type v3; // eax
  UFG::qSymbol *v4; // rax
  int v5; // ST58_4
  int numProperties; // [rsp+20h] [rbp-1C8h]
  unsigned int i; // [rsp+24h] [rbp-1C4h]
  unsigned int j; // [rsp+28h] [rbp-1C0h]
  UFG::qProperty *v9; // [rsp+30h] [rbp-1B8h]
  unsigned int v10; // [rsp+38h] [rbp-1B0h]
  unsigned int count; // [rsp+3Ch] [rbp-1ACh]
  char *v12; // [rsp+40h] [rbp-1A8h]
  UFG::qProperty *dest; // [rsp+50h] [rbp-198h]
  UFG::qPropertySet *v14; // [rsp+60h] [rbp-188h]
  unsigned int *defaults; // [rsp+68h] [rbp-180h]
  UFG::qPropertyList *v16; // [rsp+78h] [rbp-170h]
  UFG::qResourceHandle *v17; // [rsp+98h] [rbp-150h]
  char *v18; // [rsp+A0h] [rbp-148h]
  unsigned int v19; // [rsp+A8h] [rbp-140h]
  char *v20; // [rsp+B0h] [rbp-138h]
  UFG::qPropertySetHandle *v21; // [rsp+B8h] [rbp-130h]
  char *v22; // [rsp+C0h] [rbp-128h]
  void *v23; // [rsp+D0h] [rbp-118h]
  UFG::qOffset64<UFG::qPropertySetHandle *> *v24; // [rsp+D8h] [rbp-110h]
  signed __int64 v25; // [rsp+E0h] [rbp-108h]
  signed __int64 v26; // [rsp+F8h] [rbp-F0h]
  UFG::qPropertyList *v27; // [rsp+100h] [rbp-E8h]
  char *v28; // [rsp+108h] [rbp-E0h]
  char *v29; // [rsp+110h] [rbp-D8h]
  UFG::qOffset64<UFG::qProperty *> *v30; // [rsp+118h] [rbp-D0h]
  signed __int64 v31; // [rsp+120h] [rbp-C8h]
  UFG::qOffset64<unsigned long *> *v32; // [rsp+128h] [rbp-C0h]
  const char *v33; // [rsp+130h] [rbp-B8h]
  char *v34; // [rsp+138h] [rbp-B0h]
  signed __int64 v35; // [rsp+148h] [rbp-A0h]
  signed __int64 *v36; // [rsp+150h] [rbp-98h]
  char *v37; // [rsp+158h] [rbp-90h]
  signed __int64 v38; // [rsp+160h] [rbp-88h]
  signed __int64 v39; // [rsp+168h] [rbp-80h]
  UFG::qOffset64<unsigned char *> *v40; // [rsp+170h] [rbp-78h]
  UFG::qPropertySet *v41; // [rsp+178h] [rbp-70h]
  signed __int64 v42; // [rsp+180h] [rbp-68h]
  signed __int64 v43; // [rsp+190h] [rbp-58h]
  char *v44; // [rsp+198h] [rbp-50h]
  UFG::qPropertySet *owningSet; // [rsp+1F0h] [rbp+8h]
  UFG::qPropertySet *v46; // [rsp+1F8h] [rbp+10h]
  bool v47; // [rsp+200h] [rbp+18h]

  v47 = copyParents;
  v46 = source_set;
  owningSet = this;
  UFG::qPropertySet::RemovePropertiesAllLocal(this);
  if ( v47 )
  {
    UFG::qPropertySet::RemoveParentsAll(owningSet);
    v10 = v46->mNumParents;
    if ( v46->mParents.mOffset )
      v26 = (signed __int64)&v46->mParents + v46->mParents.mOffset;
    else
      v26 = 0i64;
    v21 = (UFG::qPropertySetHandle *)UFG::qPropertySet_Allocate(32 * v10, "qPropertySetHandle", 0);
    for ( i = 0; i < v10; ++i )
    {
      v17 = (UFG::qResourceHandle *)UFG::qPropertyList::operator new((hkObjectCopier *)0x20, (hkClass *)&v21[i]);
      if ( v17 )
        UFG::qResourceHandle::qResourceHandle(v17);
      UFG::qPropertySetHandle::CopyFrom(&v21[i], (UFG::qPropertySetHandle *)(32i64 * i + v26));
    }
    v24 = &owningSet->mParents;
    if ( v21 )
      v39 = (char *)v21 - (char *)v24;
    else
      v39 = 0i64;
    v24->mOffset = v39;
    owningSet->mNumParents = v10;
    owningSet->mParentMask = -1;
  }
  v3 = (unsigned int)UFG::qPropertySet::GetType(v46);
  UFG::qPropertySet::SetType(owningSet, v3);
  UFG::qSymbol::qSymbol(&owningSet->mSchemaName, &v46->mSchemaName);
  numProperties = v46->mNumProperties;
  if ( v46->mProperties.mOffset )
    v28 = (char *)&v46->mProperties + v46->mProperties.mOffset;
  else
    v28 = 0i64;
  dest = (UFG::qProperty *)UFG::qPropertySet_Allocate(
                             (8 * numProperties + 15) & 0xFFFFFFF0,
                             "PropertySetProps",
                             0x1000u);
  if ( v46->mDefaultBits.mOffset )
    v44 = (char *)&v46->mDefaultBits + v46->mDefaultBits.mOffset;
  else
    v44 = 0i64;
  defaults = (unsigned int *)UFG::qPropertySet_Allocate(4 * ((numProperties + 31) / 0x20u), "PropertySetProps", 0);
  UFG::qMemCopy(dest, v28, 8 * numProperties);
  UFG::qMemCopy(defaults, v44, 4 * ((numProperties + 31) / 0x20u));
  if ( v46->mFlags & 1 )
    UFG::qPropertySet::SortForDynamic(defaults, dest, numProperties);
  v30 = &owningSet->mProperties;
  if ( dest )
    v43 = (char *)dest - (char *)v30;
  else
    v43 = 0i64;
  v30->mOffset = v43;
  v32 = &owningSet->mDefaultBits;
  if ( defaults )
    v42 = (char *)defaults - (char *)v32;
  else
    v42 = 0i64;
  v32->mOffset = v42;
  owningSet->mNumProperties = numProperties;
  owningSet->mPropertyMask = -1;
  count = v46->mNumDataBytes;
  if ( v46->mValues.mOffset )
    v34 = (char *)&v46->mValues + v46->mValues.mOffset;
  else
    v34 = 0i64;
  v12 = (char *)UFG::qPropertySet_Allocate((count + 15) & 0xFFFFFFF0, "PropertyData", 0x1000u);
  UFG::qMemCopy(v12, v34, count);
  v40 = &owningSet->mValues;
  if ( v12 )
    v35 = v12 - (char *)v40;
  else
    v35 = 0i64;
  v40->mOffset = v35;
  owningSet->mNumDataBytes = count;
  v19 = owningSet->mNumProperties;
  for ( j = 0; j < v19; ++j )
  {
    v9 = &dest[j];
    if ( (unsigned int)UFG::qProperty::GetTypeUID(&dest[j]) == 26 )
    {
      v18 = &v34[(unsigned int)UFG::qProperty::GetDataOffset(v9)];
      if ( *(_QWORD *)v18 )
        v41 = (UFG::qPropertySet *)&v18[*(_QWORD *)v18];
      else
        v41 = 0i64;
      v4 = UFG::qPropertySet::GetName(v41);
      v14 = UFG::qPropertySet::CreateContainedSet(v4, "qPropertySet");
      v37 = &v12[(unsigned int)UFG::qProperty::GetDataOffset(v9)];
      if ( v14 )
        v25 = (char *)v14 - v37;
      else
        v25 = 0i64;
      *(_QWORD *)v37 = v25;
      UFG::qPropertyCollection::SetOwner((UFG::qPropertyCollection *)&v14->mFlags, owningSet);
      UFG::qPropertySet::AddRef(v14);
      UFG::qPropertySet::CopyFrom(v14, v41, 1);
    }
    else if ( (unsigned int)UFG::qProperty::GetTypeUID(v9) == 25 )
    {
      v20 = &v34[(unsigned int)UFG::qProperty::GetDataOffset(v9)];
      if ( *(_QWORD *)v20 )
        v27 = (UFG::qPropertyList *)&v20[*(_QWORD *)v20];
      else
        v27 = 0i64;
      v16 = UFG::qPropertyList::Create("qPropertyList");
      v29 = &v12[(unsigned int)UFG::qProperty::GetDataOffset(v9)];
      if ( v16 )
        v31 = (char *)v16 - v29;
      else
        v31 = 0i64;
      *(_QWORD *)v29 = v31;
      UFG::qPropertyCollection::SetOwner((UFG::qPropertyCollection *)&v16->mFlags, owningSet);
      UFG::qPropertyList::CopyFrom(v16, v27);
    }
    else if ( (unsigned int)UFG::qProperty::GetTypeUID(v9) == 12 )
    {
      v22 = &v34[(unsigned int)UFG::qProperty::GetDataOffset(v9)];
      if ( *(_QWORD *)v22 )
        v33 = &v22[*(_QWORD *)v22];
      else
        v33 = 0i64;
      v5 = UFG::qStringLength(v33);
      v23 = UFG::qPropertySet_Allocate(v5 + 1, "PropertyString", 0);
      UFG::qMemCopy(v23, v33, v5 + 1);
      v36 = (signed __int64 *)&v12[(unsigned int)UFG::qProperty::GetDataOffset(v9)];
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
  unsigned int i; // [rsp+0h] [rbp-28h]
  unsigned int v2; // [rsp+4h] [rbp-24h]
  char *v3; // [rsp+10h] [rbp-18h]

  if ( this->mDefaultBits.mOffset )
    v3 = (char *)&this->mDefaultBits + this->mDefaultBits.mOffset;
  else
    v3 = 0i64;
  v2 = (this->mNumProperties + 31) / 32;
  for ( i = 0; i < v2; ++i )
    *(_DWORD *)&v3[4 * i] = -1;
}

// File Line: 1028
// RVA: 0x1FE520
void __fastcall UFG::qPropertySet::SetPropertyDefaultLocalIdx(UFG::qPropertySet *this, unsigned int index, bool isDefault)
{
  int v3; // eax
  unsigned int v4; // [rsp+0h] [rbp-38h]
  signed int v5; // [rsp+4h] [rbp-34h]
  char *v6; // [rsp+20h] [rbp-18h]

  if ( this->mDefaultBits.mOffset )
    v6 = (char *)&this->mDefaultBits + this->mDefaultBits.mOffset;
  else
    v6 = 0i64;
  v4 = index / 0x20;
  v5 = 1 << index % 0x20;
  if ( isDefault )
    v3 = v5 | *(_DWORD *)&v6[4 * v4];
  else
    v3 = ~v5 & *(_DWORD *)&v6[4 * v4];
  *(_DWORD *)&v6[4 * v4] = v3;
}

// File Line: 1048
// RVA: 0x1FE450
char __fastcall UFG::qPropertySet::SetPropertyDefaultLocal(UFG::qPropertySet *this, UFG::qSymbol *propertyName, bool isDefault)
{
  unsigned int index; // [rsp+20h] [rbp-38h]
  int v5; // [rsp+28h] [rbp-30h]
  signed __int64 v6; // [rsp+38h] [rbp-20h]
  UFG::qPropertySet *v7; // [rsp+60h] [rbp+8h]
  bool v8; // [rsp+70h] [rbp+18h]

  v8 = isDefault;
  v7 = this;
  v5 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)propertyName);
  if ( v7->mProperties.mOffset )
    v6 = (signed __int64)&v7->mProperties + v7->mProperties.mOffset;
  else
    v6 = 0i64;
  for ( index = 0; index < v7->mNumProperties; ++index )
  {
    if ( *(_DWORD *)(v6 + 8i64 * index + 4) == v5 )
    {
      UFG::qPropertySet::SetPropertyDefaultLocalIdx(v7, index, v8);
      return 1;
    }
  }
  return 0;
}

// File Line: 1065
// RVA: 0x1F80C0
UFG::qPropertySetResource *__fastcall UFG::qPropertySet::GetResource(UFG::qPropertySet *this)
{
  UFG::qPropertySetResource *result; // rax
  UFG::qPropertySet *v2; // [rsp+40h] [rbp+8h]

  v2 = this;
  if ( this && (unsigned __int8)UFG::qPropertySet::IsResourceSet(this) )
    result = (UFG::qPropertySetResource *)&v2[-2].mParentMask;
  else
    result = 0i64;
  return result;
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
  UFG::qPropertySet *v2; // [rsp+70h] [rbp+8h]

  v2 = this;
  if ( (signed int)this->mRefCount > 0 )
    --this->mRefCount;
  if ( !this->mRefCount
    && !(unsigned __int8)UFG::qPropertyCollection::IsMemImaged((UFG::qPropertyCollection *)&this->mFlags) )
  {
    if ( (unsigned __int8)UFG::qPropertySet::IsResourceSet(v2) == 1 )
    {
      pPropResource = UFG::qPropertySet::GetResource(v2);
      if ( !(unsigned __int8)UFG::PropertySetCache::Contains(pPropResource) )
      {
        if ( pPropResource )
        {
          UFG::qPropertySetResource::~qPropertySetResource(pPropResource);
          UFG::qPropertySet::operator delete(pPropResource, 0xC0ui64);
        }
      }
    }
    else if ( v2 )
    {
      UFG::qPropertySet::`scalar deleting destructor'(v2, 1);
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
UFG::qPropertySet *__fastcall UFG::qPropertySet::GetParentFromName(UFG::qPropertySet *this, UFG::qSymbol *propertySetName, UFG::qPropertyDepth depth)
{
  int v3; // ST3C_4
  int v4; // ST40_4
  unsigned int i; // [rsp+20h] [rbp-48h]
  UFG::qPropertySet *v7; // [rsp+30h] [rbp-38h]
  unsigned int v8; // [rsp+38h] [rbp-30h]
  signed __int64 v9; // [rsp+48h] [rbp-20h]
  UFG::qPropertySet *v10; // [rsp+58h] [rbp-10h]
  UFG::qPropertySet *v11; // [rsp+70h] [rbp+8h]
  UFG::qArray<unsigned long,0> *v12; // [rsp+78h] [rbp+10h]
  UFG::qPropertyDepth v13; // [rsp+80h] [rbp+18h]

  v13 = depth;
  v12 = (UFG::qArray<unsigned long,0> *)propertySetName;
  v11 = this;
  ++_total_parent_calls;
  v3 = this->mParentMask & (unsigned __int64)UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)propertySetName);
  if ( v3 == (unsigned int)UFG::qSymbolUC::as_uint32(v12) )
  {
    v8 = v11->mNumParents;
    if ( v11->mParents.mOffset )
      v9 = (signed __int64)&v11->mParents + v11->mParents.mOffset;
    else
      v9 = 0i64;
    for ( i = 0; i < v8; ++i )
    {
      v7 = (UFG::qPropertySet *)UFG::qPropertySetHandle::Get((UFG::qPropertySetHandle *)(32i64 * i + v9));
      v4 = BasicArrayImplementation<hkDataArrayImpl *>::getSize((BasicArrayImplementation<hkDataObjectImpl *> *)(32i64 * i + v9));
      if ( v4 == (unsigned int)UFG::qSymbolUC::as_uint32(v12) )
        return v7;
      if ( v13 == 1 )
      {
        if ( v7 )
        {
          v10 = UFG::qPropertySet::GetParentFromName(v7, (UFG::qSymbol *)v12, DEPTH_RECURSE);
          if ( v10 )
            return v10;
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
  int v3; // [rsp+24h] [rbp-84h]
  unsigned int j; // [rsp+28h] [rbp-80h]
  unsigned int v5; // [rsp+2Ch] [rbp-7Ch]
  UFG::qPropertySetHandle *v6; // [rsp+38h] [rbp-70h]
  UFG::qResourceHandle *v7; // [rsp+40h] [rbp-68h]
  UFG::qOffset64<UFG::qPropertySetHandle *> *v8; // [rsp+50h] [rbp-58h]
  signed __int64 v9; // [rsp+58h] [rbp-50h]
  char *v10; // [rsp+60h] [rbp-48h]
  UFG::qPropertySet *v11; // [rsp+B0h] [rbp+8h]

  v11 = this;
  v5 = this->mNumParents;
  v3 = v5 + 1;
  if ( this->mParents.mOffset )
    v10 = (char *)&this->mParents + this->mParents.mOffset;
  else
    v10 = 0i64;
  v6 = (UFG::qPropertySetHandle *)UFG::qPropertySet_Allocate(32 * v3, "qPropertySetHandle", 0);
  for ( i = 0; i < v5; ++i )
  {
    v7 = (UFG::qResourceHandle *)UFG::qPropertyList::operator new((hkObjectCopier *)0x20, (hkClass *)&v6[i]);
    if ( v7 )
      UFG::qResourceHandle::qResourceHandle(v7);
    UFG::qPropertySetHandle::CopyFrom(&v6[i], (UFG::qPropertySetHandle *)&v10[32 * i]);
  }
  for ( j = 0; j < v5; ++j )
    UFG::qPropertySetHandle::Close((UFG::qPropertySetHandle *)&v10[32 * j]);
  if ( v10 )
    UFG::qPropertySet_Free(v10);
  v8 = &v11->mParents;
  if ( v6 )
    v9 = (char *)v6 - (char *)v8;
  else
    v9 = 0i64;
  v8->mOffset = v9;
  v11->mNumParents = v3;
  return &v6[v5];
}

// File Line: 1251
// RVA: 0x1F1A10
signed __int64 __fastcall UFG::qPropertySet::AddNonResourceBasedParentSet(UFG::qPropertySet *this, UFG::qPropertySet *parent_set)
{
  UFG::qSymbol *v2; // rax
  UFG::qPropertySetHandle *v3; // ST20_8
  UFG::qPropertySet *v5; // [rsp+40h] [rbp+8h]
  UFG::qPropertySet *parent; // [rsp+48h] [rbp+10h]

  parent = parent_set;
  v5 = this;
  v2 = UFG::qPropertySet::GetName(parent_set);
  if ( UFG::qPropertySet::GetParentIdx(v5, v2) != -1 )
    return 0xFFFFFFFFi64;
  v3 = UFG::qPropertySet::InternalAddParent(v5);
  UFG::qPropertySetHandle::InitTempNonResourcePropSet(v3, parent);
  return v5->mNumParents;
}

// File Line: 1264
// RVA: 0x1F1B30
signed __int64 __fastcall UFG::qPropertySet::AddParent(UFG::qPropertySet *this, UFG::qPropertySet *parent)
{
  UFG::qSymbol *v2; // rax
  UFG::qPropertySet *v4; // [rsp+30h] [rbp+8h]

  v4 = this;
  v2 = UFG::qPropertySet::GetName(parent);
  return UFG::qPropertySet::AddParent(v4, v2);
}

// File Line: 1269
// RVA: 0x1F1A70
signed __int64 __fastcall UFG::qPropertySet::AddParent(UFG::qPropertySet *this, UFG::qSymbol *parent_name)
{
  unsigned int resource_uid; // [rsp+20h] [rbp-38h]
  UFG::qResourceHandle *v4; // [rsp+28h] [rbp-30h]
  hkClass *klass; // [rsp+38h] [rbp-20h]
  UFG::qPropertySet *v6; // [rsp+60h] [rbp+8h]
  UFG::qSymbol *v7; // [rsp+68h] [rbp+10h]

  v7 = parent_name;
  v6 = this;
  resource_uid = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)parent_name);
  if ( UFG::qPropertySet::GetParentIdx(v6, v7) != -1 )
    return 0xFFFFFFFFi64;
  Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat((hkgpIndexedMesh::EdgeBarrier *)v6, 0i64);
  klass = (hkClass *)UFG::qPropertySet::InternalAddParent(v6);
  v4 = (UFG::qResourceHandle *)UFG::qPropertyList::operator new((hkObjectCopier *)0x20, klass);
  if ( v4 )
    UFG::qResourceHandle::qResourceHandle(v4);
  UFG::qPropertySetHandle::Init((UFG::qPropertySetHandle *)klass, resource_uid);
  return v6->mNumParents;
}

// File Line: 1312
// RVA: 0x1FB9A0
void __fastcall UFG::qPropertySet::RemoveParent(UFG::qPropertySet *this, UFG::qSymbol *parent_name)
{
  int v2; // [rsp+20h] [rbp-C8h]
  int v3; // [rsp+24h] [rbp-C4h]
  unsigned int k; // [rsp+28h] [rbp-C0h]
  unsigned int j; // [rsp+2Ch] [rbp-BCh]
  unsigned int i; // [rsp+30h] [rbp-B8h]
  unsigned int v7; // [rsp+34h] [rbp-B4h]
  unsigned int v8; // [rsp+38h] [rbp-B0h]
  UFG::qResourceHandle *v9; // [rsp+50h] [rbp-98h]
  UFG::qResourceHandle *v10; // [rsp+60h] [rbp-88h]
  UFG::qOffset64<UFG::qPropertySetHandle *> *v11; // [rsp+70h] [rbp-78h]
  UFG::qPropertySetHandle *v12; // [rsp+78h] [rbp-70h]
  signed __int64 v13; // [rsp+80h] [rbp-68h]
  UFG::qPropertySetHandle *v14; // [rsp+A0h] [rbp-48h]
  UFG::qPropertySet *v15; // [rsp+F0h] [rbp+8h]

  v15 = this;
  v7 = UFG::qPropertySet::GetParentIdx(this, parent_name);
  if ( v7 != -1 )
  {
    Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat((hkgpIndexedMesh::EdgeBarrier *)v15, 0i64);
    v8 = v15->mNumParents;
    v3 = v8 - 1;
    if ( v15->mParents.mOffset )
      v12 = (UFG::qPropertySetHandle *)((char *)&v15->mParents + v15->mParents.mOffset);
    else
      v12 = 0i64;
    if ( v8 == 1 )
      v14 = 0i64;
    else
      v14 = (UFG::qPropertySetHandle *)UFG::qPropertySet_Allocate(32 * v3, "qPropertySetHandle", 0);
    v2 = 0;
    for ( i = 0; i < v7; ++i )
    {
      v10 = (UFG::qResourceHandle *)UFG::qPropertyList::operator new((hkObjectCopier *)0x20, (hkClass *)&v14[v2]);
      if ( v10 )
        UFG::qResourceHandle::qResourceHandle(v10);
      UFG::qPropertySetHandle::CopyFrom(&v14[v2++], &v12[i]);
    }
    for ( j = v7 + 1; j < v8; ++j )
    {
      v9 = (UFG::qResourceHandle *)UFG::qPropertyList::operator new((hkObjectCopier *)0x20, (hkClass *)&v14[v2]);
      if ( v9 )
        UFG::qResourceHandle::qResourceHandle(v9);
      UFG::qPropertySetHandle::CopyFrom(&v14[v2++], &v12[j]);
    }
    for ( k = 0; k < v8; ++k )
      UFG::qPropertySetHandle::Close(&v12[k]);
    UFG::qPropertySet_Free(v12);
    if ( v14 )
    {
      v11 = &v15->mParents;
      if ( v14 )
        v13 = (char *)v14 - (char *)v11;
      else
        v13 = 0i64;
      v11->mOffset = v13;
    }
    else
    {
      v15->mParents.mOffset = 0i64;
    }
    v15->mNumParents = v3;
  }
}

// File Line: 1376
// RVA: 0x1FBD40
void __fastcall UFG::qPropertySet::RemoveParentsAll(UFG::qPropertySet *this)
{
  unsigned int i; // [rsp+20h] [rbp-38h]
  unsigned int v2; // [rsp+24h] [rbp-34h]
  UFG::qPropertySetHandle *v3; // [rsp+30h] [rbp-28h]
  UFG::qPropertySet *v4; // [rsp+60h] [rbp+8h]

  v4 = this;
  Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat((hkgpIndexedMesh::EdgeBarrier *)this, 0i64);
  v2 = v4->mNumParents;
  if ( v4->mParents.mOffset )
    v3 = (UFG::qPropertySetHandle *)((char *)&v4->mParents + v4->mParents.mOffset);
  else
    v3 = 0i64;
  for ( i = 0; i < v2; ++i )
    UFG::qPropertySetHandle::Close(&v3[i]);
  UFG::qPropertySet_Free(v3);
  v4->mParents.mOffset = 0i64;
  v4->mNumParents = 0;
}

// File Line: 1398
// RVA: 0x1F71B0
signed __int64 __fastcall UFG::qPropertySet::GetParentIdx(UFG::qPropertySet *this, UFG::qSymbol *parent_name)
{
  unsigned int i; // [rsp+20h] [rbp-38h]
  unsigned int v4; // [rsp+24h] [rbp-34h]
  int v5; // [rsp+28h] [rbp-30h]
  signed __int64 v6; // [rsp+38h] [rbp-20h]
  UFG::qPropertySet *v7; // [rsp+60h] [rbp+8h]

  v7 = this;
  v5 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)parent_name);
  if ( v7->mParents.mOffset )
    v6 = (signed __int64)&v7->mParents + v7->mParents.mOffset;
  else
    v6 = 0i64;
  v4 = v7->mNumParents;
  for ( i = 0; i < v4; ++i )
  {
    if ( (unsigned int)BasicArrayImplementation<hkDataArrayImpl *>::getSize((BasicArrayImplementation<hkDataObjectImpl *> *)(32i64 * i + v6)) == v5 )
      return i;
  }
  return 0xFFFFFFFFi64;
}

// File Line: 1419
// RVA: 0x1F7630
signed __int64 __fastcall UFG::qPropertySet::GetPropertyIdxLocal(UFG::qPropertySet *this, unsigned int type_uid, unsigned int name_uid)
{
  unsigned int i; // [rsp+20h] [rbp-48h]
  int v5; // [rsp+24h] [rbp-44h]
  int v6; // [rsp+28h] [rbp-40h]
  int v7; // [rsp+2Ch] [rbp-3Ch]
  int v8; // [rsp+30h] [rbp-38h]
  UFG::qProperty *v9; // [rsp+38h] [rbp-30h]
  char *v10; // [rsp+50h] [rbp-18h]
  unsigned int v11; // [rsp+78h] [rbp+10h]
  unsigned int v12; // [rsp+80h] [rbp+18h]

  v12 = name_uid;
  v11 = type_uid;
  if ( this->mProperties.mOffset )
    v10 = (char *)&this->mProperties + this->mProperties.mOffset;
  else
    v10 = 0i64;
  v8 = this->mNumProperties;
  if ( this->mFlags & 1 )
  {
    v7 = 0;
    v6 = this->mNumProperties;
    while ( v7 <= v6 )
    {
      v5 = (v6 + v7) / 2;
      v9 = (UFG::qProperty *)&v10[8 * v5];
      if ( v12 <= *(_DWORD *)&v10[8 * v5 + 4] )
      {
        if ( v12 >= v9->mNameUID )
        {
          if ( (unsigned int)UFG::qProperty::GetTypeUID(v9) == v11 )
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
    for ( i = 0; (signed int)i < v8; ++i )
    {
      if ( *(_DWORD *)&v10[8 * i + 4] == v12
        && (unsigned int)UFG::qProperty::GetTypeUID((UFG::qProperty *)&v10[8 * i]) == v11 )
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
  char *v2; // [rsp+8h] [rbp-10h]

  if ( this->mValues.mOffset )
    v2 = (char *)&this->mValues + this->mValues.mOffset;
  else
    v2 = 0i64;
  return v2;
}

// File Line: 1564
// RVA: 0x1F8990
void *__fastcall UFG::qPropertySet::GetValuePtr(UFG::qPropertySet *this, unsigned int type_uid, unsigned int name_uid, UFG::qPropertyDepth depth, UFG::qPropertySet **owningSet)
{
  void *result; // rax
  unsigned int i; // [rsp+30h] [rbp-B8h]
  unsigned int j; // [rsp+34h] [rbp-B4h]
  int v8; // [rsp+38h] [rbp-B0h]
  int v9; // [rsp+3Ch] [rbp-ACh]
  UFG::qProperty *v10; // [rsp+40h] [rbp-A8h]
  int v11; // [rsp+48h] [rbp-A0h]
  unsigned int v12; // [rsp+4Ch] [rbp-9Ch]
  UFG::qProperty *v13; // [rsp+50h] [rbp-98h]
  UFG::qPropertySetHandle *v14; // [rsp+60h] [rbp-88h]
  unsigned int v15; // [rsp+98h] [rbp-50h]
  UFG::qProperty *v16; // [rsp+A0h] [rbp-48h]
  signed __int64 v17; // [rsp+A8h] [rbp-40h]
  signed __int64 v18; // [rsp+B0h] [rbp-38h]
  UFG::qPropertySetHandle *v19; // [rsp+B8h] [rbp-30h]
  signed __int64 v20; // [rsp+C0h] [rbp-28h]
  UFG::qPropertySet *v21; // [rsp+C8h] [rbp-20h]
  signed __int64 v22; // [rsp+D0h] [rbp-18h]
  void *v23; // [rsp+D8h] [rbp-10h]
  UFG::qPropertySet *v24; // [rsp+F0h] [rbp+8h]
  unsigned int type_uida; // [rsp+F8h] [rbp+10h]
  unsigned int name_uida; // [rsp+100h] [rbp+18h]

  name_uida = name_uid;
  type_uida = type_uid;
  v24 = this;
  if ( this->mProperties.mOffset )
    v16 = (UFG::qProperty *)((char *)&this->mProperties + this->mProperties.mOffset);
  else
    v16 = 0i64;
  v10 = v16;
  v12 = this->mNumProperties;
  ++_total_calls;
  if ( (this->mPropertyMask & name_uid) == name_uid )
  {
    if ( this->mFlags & 1 )
    {
      v11 = 0;
      v9 = v12 - 1;
      while ( v11 <= v9 )
      {
        v8 = (v9 + v11) / 2;
        v13 = &v16[v8];
        if ( name_uid <= v16[v8].mNameUID )
        {
          if ( name_uid >= v13->mNameUID )
          {
            if ( (unsigned int)UFG::qProperty::GetTypeUID(v13) == type_uid )
            {
              if ( owningSet )
                *owningSet = v24;
              if ( v24->mValues.mOffset )
                v18 = (signed __int64)&v24->mValues + v24->mValues.mOffset;
              else
                v18 = 0i64;
              result = (void *)((unsigned int)UFG::qProperty::GetDataOffset(v13) + v18);
            }
            else
            {
              if ( v24->mValues.mOffset )
                v22 = (signed __int64)&v24->mValues + v24->mValues.mOffset;
              else
                v22 = 0i64;
              result = (void *)((unsigned int)UFG::qProperty::GetDataOffset(v13) + v22);
            }
            return result;
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
      for ( i = 0; i < v12; ++i )
      {
        if ( v10->mNameUID == name_uid )
        {
          if ( (unsigned int)UFG::qProperty::GetTypeUID(v10) == type_uid )
          {
            if ( owningSet )
              *owningSet = v24;
            if ( v24->mValues.mOffset )
              v20 = (signed __int64)&v24->mValues + v24->mValues.mOffset;
            else
              v20 = 0i64;
            result = (void *)((unsigned int)UFG::qProperty::GetDataOffset(v10) + v20);
          }
          else
          {
            if ( v24->mValues.mOffset )
              v17 = (signed __int64)&v24->mValues + v24->mValues.mOffset;
            else
              v17 = 0i64;
            result = (void *)((unsigned int)UFG::qProperty::GetDataOffset(v10) + v17);
          }
          return result;
        }
        ++v10;
      }
    }
  }
  else
  {
    ++_early_outs;
  }
  if ( depth == 1 )
  {
    if ( this->mParents.mOffset )
      v19 = (UFG::qPropertySetHandle *)((char *)&this->mParents + this->mParents.mOffset);
    else
      v19 = 0i64;
    v14 = v19;
    v15 = this->mNumParents;
    for ( j = 0; j < v15; ++j )
    {
      v21 = (UFG::qPropertySet *)UFG::qPropertySetHandle::Get(v14);
      if ( v21 )
      {
        v23 = UFG::qPropertySet::GetValuePtr(v21, type_uida, name_uida, DEPTH_RECURSE, owningSet);
        if ( v23 )
          return v23;
      }
      ++v14;
    }
  }
  return 0i64;
}me_uida, DEPTH_RECURSE, owningSet);
        if ( v23 )
          return 

// File Line: 1671
// RVA: 0x1F84F0
void *__fastcall UFG::qPropertySet::GetValuePtr2(UFG::qPropertySet *this, unsigned int name_uid, UFG::qPropertyDepth depth, UFG::qPropertySet **owningSet, unsigned int *type_uid)
{
  unsigned int i; // [rsp+30h] [rbp-98h]
  unsigned int j; // [rsp+34h] [rbp-94h]
  int v8; // [rsp+38h] [rbp-90h]
  int v9; // [rsp+3Ch] [rbp-8Ch]
  int v10; // [rsp+40h] [rbp-88h]
  UFG::qProperty *v11; // [rsp+48h] [rbp-80h]
  unsigned int v12; // [rsp+50h] [rbp-78h]
  UFG::qProperty *v13; // [rsp+58h] [rbp-70h]
  unsigned int v14; // [rsp+70h] [rbp-58h]
  UFG::qPropertySetHandle *v15; // [rsp+88h] [rbp-40h]
  UFG::qProperty *v16; // [rsp+90h] [rbp-38h]
  UFG::qPropertySetHandle *v17; // [rsp+98h] [rbp-30h]
  signed __int64 v18; // [rsp+A0h] [rbp-28h]
  UFG::qPropertySet *v19; // [rsp+A8h] [rbp-20h]
  signed __int64 v20; // [rsp+B0h] [rbp-18h]
  void *v21; // [rsp+B8h] [rbp-10h]
  UFG::qPropertySet *v22; // [rsp+D0h] [rbp+8h]
  unsigned int name_uida; // [rsp+D8h] [rbp+10h]
  UFG::qPropertySet **owningSeta; // [rsp+E8h] [rbp+20h]

  owningSeta = owningSet;
  name_uida = name_uid;
  v22 = this;
  if ( this->mProperties.mOffset )
    v16 = (UFG::qProperty *)((char *)&this->mProperties + this->mProperties.mOffset);
  else
    v16 = 0i64;
  v11 = v16;
  v12 = this->mNumProperties;
  ++_total_calls;
  if ( (this->mPropertyMask & name_uid) == name_uid )
  {
    if ( this->mFlags & 1 )
    {
      v10 = 0;
      v9 = v12 - 1;
      while ( v10 <= v9 )
      {
        v8 = (v9 + v10) / 2;
        v13 = &v16[v8];
        if ( name_uid <= v16[v8].mNameUID )
        {
          if ( name_uid >= v13->mNameUID )
          {
            if ( type_uid )
              *type_uid = UFG::qProperty::GetTypeUID(v13);
            if ( owningSeta )
              *owningSeta = v22;
            if ( v22->mValues.mOffset )
              v18 = (signed __int64)&v22->mValues + v22->mValues.mOffset;
            else
              v18 = 0i64;
            return (void *)((unsigned int)UFG::qProperty::GetDataOffset(v13) + v18);
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
      for ( i = 0; i < v12; ++i )
      {
        if ( v11->mNameUID == name_uid )
        {
          if ( type_uid )
            *type_uid = UFG::qProperty::GetTypeUID(v11);
          if ( owningSeta )
            *owningSeta = v22;
          if ( v22->mValues.mOffset )
            v20 = (signed __int64)&v22->mValues + v22->mValues.mOffset;
          else
            v20 = 0i64;
          return (void *)((unsigned int)UFG::qProperty::GetDataOffset(v11) + v20);
        }
        ++v11;
      }
    }
  }
  else
  {
    ++_early_outs;
  }
  if ( depth == 1 )
  {
    if ( this->mParents.mOffset )
      v17 = (UFG::qPropertySetHandle *)((char *)&this->mParents + this->mParents.mOffset);
    else
      v17 = 0i64;
    v15 = v17;
    v14 = this->mNumParents;
    for ( j = 0; j < v14; ++j )
    {
      v19 = (UFG::qPropertySet *)UFG::qPropertySetHandle::Get(v15);
      if ( v19 )
      {
        v21 = UFG::qPropertySet::GetValuePtr2(v19, name_uida, DEPTH_RECURSE, owningSeta, type_uid);
        if ( v21 )
          return v21;
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
  UFG::qPropertySet *v2; // [rsp+30h] [rbp+8h]

  v2 = this;
  UFG::qSymbol::qSymbol(&this->mName, name);
  Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat((hkgpIndexedMesh::EdgeBarrier *)v2, 0i64);
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
signed __int64 __fastcall UFG::qPropertySet::GetPropertyIndexFromName(UFG::qPropertySet *this, UFG::qSymbol *name)
{
  signed int i; // [rsp+20h] [rbp-38h]
  int v4; // [rsp+28h] [rbp-30h]
  signed __int64 v5; // [rsp+38h] [rbp-20h]
  UFG::qPropertySet *v6; // [rsp+60h] [rbp+8h]

  v6 = this;
  v4 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)name);
  for ( i = 0; i < v6->mNumProperties; ++i )
  {
    if ( v6->mProperties.mOffset )
      v5 = (signed __int64)&v6->mProperties + v6->mProperties.mOffset;
    else
      v5 = 0i64;
    if ( *(_DWORD *)(v5 + 8i64 * i + 4) == v4 )
      return (unsigned int)i;
  }
  return 0xFFFFFFFFi64;
}

// File Line: 1839
// RVA: 0x1FA740
UFG::qPropertySet *__fastcall UFG::qPropertySet::PropertyExists(UFG::qPropertySet *this, UFG::qSymbol *name, UFG::qPropertyDepth depth)
{
  unsigned int i; // [rsp+20h] [rbp-48h]
  unsigned int parent_index; // [rsp+24h] [rbp-44h]
  unsigned int v6; // [rsp+28h] [rbp-40h]
  int v7; // [rsp+30h] [rbp-38h]
  signed __int64 v8; // [rsp+40h] [rbp-28h]
  UFG::qPropertySet *v9; // [rsp+48h] [rbp-20h]
  UFG::qPropertySet *v10; // [rsp+50h] [rbp-18h]
  UFG::qPropertySet *v11; // [rsp+70h] [rbp+8h]
  UFG::qSymbol *v12; // [rsp+78h] [rbp+10h]
  UFG::qPropertyDepth deptha; // [rsp+80h] [rbp+18h]

  deptha = depth;
  v12 = name;
  v11 = this;
  v7 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)name);
  for ( i = 0; i < v11->mNumProperties; ++i )
  {
    if ( v11->mProperties.mOffset )
      v8 = (signed __int64)&v11->mProperties + v11->mProperties.mOffset;
    else
      v8 = 0i64;
    if ( *(_DWORD *)(v8 + 8i64 * i + 4) == v7 )
      return v11;
  }
  if ( deptha == 1 )
  {
    v6 = v11->mNumParents;
    for ( parent_index = 0; parent_index < v6; ++parent_index )
    {
      v10 = (UFG::qPropertySet *)UFG::qPropertySet::GetParentFromIdx(v11, parent_index);
      if ( v10 )
      {
        v9 = UFG::qPropertySet::PropertyExists(v10, v12, DEPTH_RECURSE);
        if ( v9 )
          return v9;
      }
    }
  }
  return 0i64;
}

// File Line: 1874
// RVA: 0x1FA880
bool __fastcall UFG::qPropertySet::PropertyIsDefaultByName(UFG::qPropertySet *this, UFG::qSymbol *propertyName)
{
  bool result; // al
  signed int property_index; // [rsp+20h] [rbp-18h]
  UFG::qPropertySet *v4; // [rsp+40h] [rbp+8h]

  v4 = this;
  property_index = UFG::qPropertySet::GetPropertyIndexFromName(this, propertyName);
  if ( property_index < 0 )
    result = 1;
  else
    result = UFG::qPropertySet::PropertyIsDefaultIdx(v4, property_index);
  return result;
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
void __fastcall UFG::RecalcPropertySetPtrOffsets(void *old_data, void *new_data, UFG::qProperty *properties, unsigned int property_count)
{
  unsigned int v4; // eax
  unsigned int i; // [rsp+20h] [rbp-28h]
  _QWORD *v6; // [rsp+28h] [rbp-20h]
  _BYTE *v7; // [rsp+50h] [rbp+8h]
  _BYTE *v8; // [rsp+58h] [rbp+10h]
  UFG::qProperty *v9; // [rsp+60h] [rbp+18h]
  unsigned int v10; // [rsp+68h] [rbp+20h]

  v10 = property_count;
  v9 = properties;
  v8 = new_data;
  v7 = old_data;
  for ( i = 0; i < v10; ++i )
  {
    v4 = UFG::qProperty::GetTypeUID(&v9[i]);
    if ( (unsigned __int8)UFG::qPropertyType::IsPtrType(v4) )
    {
      v6 = &v8[(unsigned int)UFG::qProperty::GetDataOffset(&v9[i])];
      if ( *v6 )
        *v6 -= v8 - v7;
    }
  }
}

// File Line: 1919
// RVA: 0x1F2120
__int64 __fastcall UFG::CalculateTotalSize(unsigned int current_end_offset, UFG::qProperty *properties, unsigned int num_properties)
{
  unsigned int v3; // eax
  UFG::qPropertyType *v4; // ST30_8
  unsigned int v6; // [rsp+20h] [rbp-28h]
  unsigned int i; // [rsp+24h] [rbp-24h]
  UFG::qProperty *v8; // [rsp+58h] [rbp+10h]
  unsigned int v9; // [rsp+60h] [rbp+18h]

  v9 = num_properties;
  v8 = properties;
  v6 = current_end_offset;
  for ( i = 0; i < v9; ++i )
  {
    v3 = UFG::qProperty::GetTypeUID(&v8[i]);
    v4 = UFG::qPropertyType::Get(v3);
    v6 = v4->mByteSize + (~(v4->Alignment - 1) & (v6 + v4->Alignment - 1));
  }
  return v6;
}

// File Line: 1933
// RVA: 0x1FC220
void __fastcall UFG::qPropertySet::RemovePropertyIdx(UFG::qPropertySet *this, unsigned int property_index)
{
  unsigned int v2; // eax
  unsigned int v3; // eax
  bool v4; // al
  unsigned int v5; // eax
  UFG::qPropertyType *v6; // STE8_8
  int v7; // eax
  unsigned int v8; // eax
  unsigned int dataOffset; // [rsp+20h] [rbp-118h]
  unsigned int dataOffseta; // [rsp+20h] [rbp-118h]
  unsigned int property_indexa; // [rsp+28h] [rbp-110h]
  unsigned int i; // [rsp+2Ch] [rbp-10Ch]
  unsigned int property_count; // [rsp+30h] [rbp-108h]
  char *new_data; // [rsp+38h] [rbp-100h]
  UFG::qProperty *dest; // [rsp+40h] [rbp-F8h]
  int v16; // [rsp+48h] [rbp-F0h]
  unsigned int count; // [rsp+4Ch] [rbp-ECh]
  UFG::qProperty *_property; // [rsp+50h] [rbp-E8h]
  unsigned int v19; // [rsp+58h] [rbp-E0h]
  UFG::qProperty *v20; // [rsp+60h] [rbp-D8h]
  int v21; // [rsp+68h] [rbp-D0h]
  char *v22; // [rsp+B8h] [rbp-80h]
  UFG::qOffset64<UFG::qProperty *> *v23; // [rsp+C0h] [rbp-78h]
  UFG::qProperty *v24; // [rsp+C8h] [rbp-70h]
  signed __int64 v25; // [rsp+D0h] [rbp-68h]
  char *v26; // [rsp+D8h] [rbp-60h]
  UFG::qOffset64<unsigned char *> *v27; // [rsp+E0h] [rbp-58h]
  signed __int64 v28; // [rsp+F0h] [rbp-48h]
  UFG::qPropertyType *v29; // [rsp+F8h] [rbp-40h]
  char *v30; // [rsp+108h] [rbp-30h]
  UFG::qPropertySet *v31; // [rsp+140h] [rbp+8h]
  unsigned int v32; // [rsp+148h] [rbp+10h]

  v32 = property_index;
  v31 = this;
  if ( this->mProperties.mOffset )
    v26 = (char *)&this->mProperties + this->mProperties.mOffset;
  else
    v26 = 0i64;
  _property = (UFG::qProperty *)&v26[8 * property_index];
  Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
    (hkgpIndexedMesh::EdgeBarrier *)this,
    (hkgpIndexedMeshDefinitions::Edge *)*(unsigned int *)&v26[8 * property_index + 4]);
  if ( v32 )
    v24 = _property - 1;
  else
    v24 = 0i64;
  if ( v24 )
  {
    v2 = UFG::qProperty::GetTypeUID(v24);
    v29 = UFG::qPropertyType::Get(v2);
  }
  else
  {
    v29 = 0i64;
  }
  v16 = v31->mNumProperties;
  property_count = v16 - 1;
  if ( v24 )
    v19 = v29->mByteSize + (unsigned __int64)UFG::qProperty::GetDataOffset(v24);
  else
    v19 = 0;
  v3 = UFG::qProperty::GetTypeUID(_property);
  UFG::qPropertyType::Get(v3);
  v21 = UFG::CalculateTotalSize(v19, _property + 1, v16 - 1 - v32);
  if ( v31->mProperties.mOffset )
    v22 = (char *)&v31->mProperties + v31->mProperties.mOffset;
  else
    v22 = 0i64;
  dest = (UFG::qProperty *)UFG::qPropertySet_Allocate(
                             16 * (unsigned int)((8i64 * (v31->mNumProperties - 1) + 15) / 0x10ui64),
                             "PropertySetProps",
                             0);
  UFG::qMemCopy(dest, v22, 8 * v32);
  UFG::qMemCopy(&dest[v32], &v22[8 * v32 + 8], 8 * (v16 - 1 - v32));
  if ( v31->mValues.mOffset )
    v30 = (char *)&v31->mValues + v31->mValues.mOffset;
  else
    v30 = 0i64;
  new_data = (char *)UFG::qPropertySet_Allocate(16 * ((v21 + 15) / 0x10u), "PropertyData", 0x1000u);
  UFG::qPropertySet::FreePropertyPtrData(v31, v30, _property);
  UFG::qMemCopy(new_data, v30, v19);
  dataOffset = v19;
  for ( property_indexa = v32 + 1; property_indexa < property_count; ++property_indexa )
  {
    v4 = UFG::qPropertySet::PropertyIsDefaultIdx(v31, property_indexa);
    UFG::qPropertySet::SetPropertyDefaultLocalIdx(v31, property_indexa - 1, v4);
  }
  for ( i = v32; i < property_count; ++i )
  {
    v20 = &dest[i];
    v5 = UFG::qProperty::GetTypeUID(&dest[i]);
    v6 = UFG::qPropertyType::Get(v5);
    count = v6->mByteSize;
    dataOffseta = ~(v6->Alignment - 1) & (dataOffset + v6->Alignment - 1);
    v7 = UFG::qProperty::GetDataOffset(v20);
    UFG::qMemCopy(&new_data[dataOffseta], &v30[v7], count);
    v8 = UFG::qProperty::GetTypeUID(v20);
    if ( (unsigned __int8)UFG::qPropertyType::IsPtrType(v8) )
      *(_DWORD *)&new_data[dataOffseta] -= dataOffseta - (unsigned __int64)UFG::qProperty::GetDataOffset(v20);
    UFG::qProperty::SetDataOffset(v20, dataOffseta);
    dataOffset = count + dataOffseta;
  }
  UFG::RecalcPropertySetPtrOffsets(v30, new_data, dest, property_count);
  v23 = &v31->mProperties;
  if ( dest )
    v25 = (char *)dest - (char *)v23;
  else
    v25 = 0i64;
  v23->mOffset = v25;
  UFG::qPropertySet_Free(v22);
  v27 = &v31->mValues;
  if ( new_data )
    v28 = new_data - (char *)v27;
  else
    v28 = 0i64;
  v27->mOffset = v28;
  UFG::qPropertySet_Free(v30);
  v31->mNumProperties = property_count;
  v31->mNumDataBytes = v21;
}

// File Line: 2023
// RVA: 0x1F5760
void __fastcall UFG::qPropertySet::FreePropertyPtrData(UFG::qPropertySet *this, char *values, UFG::qProperty *_property)
{
  char *v3; // [rsp+20h] [rbp-58h]
  char *v4; // [rsp+28h] [rbp-50h]
  char *v5; // [rsp+30h] [rbp-48h]
  char *v6; // [rsp+48h] [rbp-30h]
  UFG::qPropertyList *v7; // [rsp+50h] [rbp-28h]
  UFG::qPropertySet *v8; // [rsp+60h] [rbp-18h]
  char *v9; // [rsp+88h] [rbp+10h]
  UFG::qProperty *v10; // [rsp+90h] [rbp+18h]

  v10 = _property;
  v9 = values;
  if ( (unsigned int)UFG::qProperty::GetTypeUID(_property) == 26 )
  {
    v4 = &v9[(unsigned int)UFG::qProperty::GetDataOffset(v10)];
    if ( *(_QWORD *)v4 )
      v8 = (UFG::qPropertySet *)&v4[*(_QWORD *)v4];
    else
      v8 = 0i64;
    if ( v8 )
      UFG::qPropertySet::ReleaseRef(v8);
  }
  else if ( (unsigned int)UFG::qProperty::GetTypeUID(v10) == 25 )
  {
    v5 = &v9[(unsigned int)UFG::qProperty::GetDataOffset(v10)];
    if ( *(_QWORD *)v5 )
      v7 = (UFG::qPropertyList *)&v5[*(_QWORD *)v5];
    else
      v7 = 0i64;
    if ( v7 )
      UFG::qPropertyList::ReleaseRef(v7);
  }
  else if ( (unsigned int)UFG::qProperty::GetTypeUID(v10) == 12 )
  {
    v3 = &v9[(unsigned int)UFG::qProperty::GetDataOffset(v10)];
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
  unsigned int v2; // [rsp+48h] [rbp-90h]
  char *v3; // [rsp+68h] [rbp-70h]
  char *v4; // [rsp+78h] [rbp-60h]
  UFG::qPropertySet *v5; // [rsp+E0h] [rbp+8h]

  v5 = this;
  if ( this->mProperties.mOffset )
    v4 = (char *)&this->mProperties + this->mProperties.mOffset;
  else
    v4 = 0i64;
  v2 = this->mNumProperties;
  if ( this->mValues.mOffset )
    v3 = (char *)&this->mValues + this->mValues.mOffset;
  else
    v3 = 0i64;
  for ( i = 0; i < v2; ++i )
    UFG::qPropertySet::FreePropertyPtrData(v5, v3, (UFG::qProperty *)&v4[8 * i]);
  if ( v5->mProperties.mOffset )
    UFG::qPropertySet_Free((char *)&v5->mProperties + v5->mProperties.mOffset);
  else
    UFG::qPropertySet_Free(0i64);
  v5->mProperties.mOffset = 0i64;
  v5->mNumProperties = 0;
  if ( v5->mValues.mOffset )
    UFG::qPropertySet_Free((char *)&v5->mValues + v5->mValues.mOffset);
  else
    UFG::qPropertySet_Free(0i64);
  v5->mValues.mOffset = 0i64;
  if ( v5->mDefaultBits.mOffset )
    UFG::qPropertySet_Free((char *)&v5->mDefaultBits + v5->mDefaultBits.mOffset);
  else
    UFG::qPropertySet_Free(0i64);
  v5->mDefaultBits.mOffset = 0i64;
  v5->mNumDataBytes = 0;
  v5->mPropertyMask = -1;
}

// File Line: 2096
// RVA: 0x1FC160
void __fastcall UFG::qPropertySet::RemovePropertyByName(UFG::qPropertySet *this, UFG::qSymbol *name)
{
  unsigned int property_index; // [rsp+20h] [rbp-28h]
  unsigned int v3; // [rsp+24h] [rbp-24h]
  signed __int64 v4; // [rsp+30h] [rbp-18h]
  UFG::qPropertySet *v5; // [rsp+50h] [rbp+8h]
  UFG::qArray<unsigned long,0> *v6; // [rsp+58h] [rbp+10h]

  v6 = (UFG::qArray<unsigned long,0> *)name;
  v5 = this;
  v3 = this->mNumProperties;
  for ( property_index = 0; property_index < v3; ++property_index )
  {
    if ( v5->mProperties.mOffset )
      v4 = (signed __int64)&v5->mProperties + v5->mProperties.mOffset;
    else
      v4 = 0i64;
    if ( *(_DWORD *)(v4 + 8i64 * property_index + 4) == (unsigned int)UFG::qSymbolUC::as_uint32(v6) )
    {
      UFG::qPropertySet::RemovePropertyIdx(v5, property_index);
      return;
    }
  }
}

// File Line: 2112
// RVA: 0x1FD610
void *__fastcall UFG::qPropertySet::SetInternal(UFG::qPropertySet *this, unsigned int type_uid, unsigned int name_uid, const void *v)
{
  void *result; // rax
  void *dest; // ST138_8
  unsigned int v6; // eax
  signed int count; // [rsp+20h] [rbp-178h]
  unsigned int v8; // [rsp+24h] [rbp-174h]
  unsigned int dataOffset; // [rsp+28h] [rbp-170h]
  unsigned int index; // [rsp+2Ch] [rbp-16Ch]
  int v11; // [rsp+30h] [rbp-168h]
  UFG::qProperty *v12; // [rsp+38h] [rbp-160h]
  unsigned int v13; // [rsp+40h] [rbp-158h]
  char *new_data; // [rsp+48h] [rbp-150h]
  unsigned int byte_count; // [rsp+50h] [rbp-148h]
  int v16; // [rsp+54h] [rbp-144h]
  int v17; // [rsp+58h] [rbp-140h]
  char *v18; // [rsp+60h] [rbp-138h]
  UFG::qPropertyType *v19; // [rsp+68h] [rbp-130h]
  void *v20; // [rsp+70h] [rbp-128h]
  UFG::qOffset64<UFG::qProperty *> *v21; // [rsp+D8h] [rbp-C0h]
  signed __int64 v22; // [rsp+E0h] [rbp-B8h]
  signed __int64 v23; // [rsp+E8h] [rbp-B0h]
  signed __int64 v24; // [rsp+F0h] [rbp-A8h]
  char *v25; // [rsp+F8h] [rbp-A0h]
  signed __int64 v26; // [rsp+108h] [rbp-90h]
  char *v27; // [rsp+110h] [rbp-88h]
  UFG::qOffset64<unsigned char *> *v28; // [rsp+120h] [rbp-78h]
  signed __int64 v29; // [rsp+130h] [rbp-68h]
  signed __int64 v30; // [rsp+148h] [rbp-50h]
  signed __int64 v31; // [rsp+150h] [rbp-48h]
  UFG::qOffset64<unsigned long *> *v32; // [rsp+158h] [rbp-40h]
  signed __int64 v33; // [rsp+160h] [rbp-38h]
  char *v34; // [rsp+168h] [rbp-30h]
  UFG::qPropertySet *v35; // [rsp+1A0h] [rbp+8h]
  unsigned int type_name_uid; // [rsp+1A8h] [rbp+10h]
  unsigned int name_uida; // [rsp+1B0h] [rbp+18h]
  void *source; // [rsp+1B8h] [rbp+20h]

  source = (void *)v;
  name_uida = name_uid;
  type_name_uid = type_uid;
  v35 = this;
  Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
    (hkgpIndexedMesh::EdgeBarrier *)this,
    (hkgpIndexedMeshDefinitions::Edge *)name_uid);
  if ( (unsigned int)UFG::qPropertyCollection::GetFlags((UFG::qPropertyCollection *)&v35->mFlags, 1) )
    return 0i64;
  if ( !type_name_uid || !name_uida || !source )
    return 0i64;
  v19 = UFG::qPropertyType::Get(type_name_uid);
  if ( v19 )
  {
    index = UFG::qPropertySet::GetPropertyIdxLocal(v35, type_name_uid, name_uida);
    if ( index == -1 )
    {
      byte_count = 16 * ((8i64 * (v35->mNumProperties + 1) + 15) / 0x10ui64);
      if ( v35->mProperties.mOffset )
        v25 = (char *)&v35->mProperties + v35->mProperties.mOffset;
      else
        v25 = 0i64;
      if ( byte_count == 16 * (unsigned int)((8 * (unsigned __int64)v35->mNumProperties + 15) / 0x10) )
      {
        UFG::qMemSet(&v25[8 * v35->mNumProperties], 0, 8u);
      }
      else
      {
        v18 = (char *)UFG::qPropertySet_Allocate(byte_count, "PropertySetProps", 0);
        UFG::qMemCopy(v18, v25, 8 * v35->mNumProperties);
        UFG::qMemSet(&v18[8 * v35->mNumProperties], 0, 8u);
        if ( v35->mProperties.mOffset )
          UFG::qPropertySet_Free((char *)&v35->mProperties + v35->mProperties.mOffset);
        else
          UFG::qPropertySet_Free(0i64);
        v21 = &v35->mProperties;
        if ( v18 )
          v30 = v18 - (char *)v21;
        else
          v30 = 0i64;
        v21->mOffset = v30;
      }
      v16 = (v35->mNumProperties + 31) / 32;
      v11 = (v35->mNumProperties + 32) / 32;
      if ( v16 != v11 )
      {
        if ( v35->mDefaultBits.mOffset )
          v34 = (char *)&v35->mDefaultBits + v35->mDefaultBits.mOffset;
        else
          v34 = 0i64;
        v20 = UFG::qPropertySet_Allocate(4 * v11, "PropertySetDefaults", 0);
        UFG::qMemCopy(v20, v34, 4 * v16);
        *((_DWORD *)v20 + (unsigned int)(v11 - 1)) = 0;
        UFG::qPropertySet_Free(v34);
        v32 = &v35->mDefaultBits;
        if ( v20 )
          v22 = (_BYTE *)v20 - (_BYTE *)v32;
        else
          v22 = 0i64;
        v32->mOffset = v22;
      }
      ++v35->mNumProperties;
      if ( v35->mProperties.mOffset )
        v24 = (signed __int64)&v35->mProperties + v35->mProperties.mOffset;
      else
        v24 = 0i64;
      v12 = (UFG::qProperty *)(v24 + 8i64 * (v35->mNumProperties - 1));
      UFG::qProperty::SetTypeUID((UFG::qProperty *)(v24 + 8i64 * (v35->mNumProperties - 1)), type_name_uid);
      v12->mNameUID = name_uida;
      UFG::qProperty::SetDataOffset(v12, v35->mNumDataBytes);
      UFG::qPropertySet::SetPropertyDefaultLocalIdx(v35, v35->mNumProperties - 1, 0);
      v8 = v19->mByteSize;
      dataOffset = ~(v19->Alignment - 1) & (unsigned __int16)(v35->mNumDataBytes + v19->Alignment - 1);
      v17 = v8 + dataOffset;
      count = v35->mNumDataBytes;
      if ( v35->mValues.mOffset )
        v27 = (char *)&v35->mValues + v35->mValues.mOffset;
      else
        v27 = 0i64;
      v13 = 16 * ((v17 + 15) / 0x10u);
      if ( v13 == 16 * ((count + 15) / 0x10u) )
      {
        if ( v8 + dataOffset > 16 * ((count + 15) / 0x10u) )
          UFG::qPrintf(&customWorldMapCaption, (v17 + 15) % 0x10u);
        UFG::qMemSet(&v27[count], 0, v8 + dataOffset - count);
      }
      else
      {
        new_data = (char *)UFG::qPropertySet_Allocate(v13, "PropertySetData", 0x1000u);
        UFG::qMemCopy(new_data, v27, count);
        UFG::qMemSet(&new_data[count], 0, v8 + dataOffset - count);
        v28 = &v35->mValues;
        if ( new_data )
          v29 = new_data - (char *)v28;
        else
          v29 = 0i64;
        v28->mOffset = v29;
        if ( v35->mProperties.mOffset )
          UFG::RecalcPropertySetPtrOffsets(
            v27,
            new_data,
            (UFG::qProperty *)((char *)&v35->mProperties + v35->mProperties.mOffset),
            v35->mNumProperties);
        else
          UFG::RecalcPropertySetPtrOffsets(v27, new_data, 0i64, v35->mNumProperties);
        UFG::qPropertySet_Free(v27);
      }
      v35->mNumDataBytes = v17;
      UFG::qProperty::SetDataOffset(v12, dataOffset);
      if ( v35->mValues.mOffset )
        v31 = (signed __int64)&v35->mValues + v35->mValues.mOffset;
      else
        v31 = 0i64;
      v6 = UFG::qProperty::GetDataOffset(v12);
      UFG::qMemCopy((void *)(v6 + v31), source, v8);
      if ( v35->mValues.mOffset )
        v33 = (signed __int64)&v35->mValues + v35->mValues.mOffset;
      else
        v33 = 0i64;
      result = (void *)((unsigned int)UFG::qProperty::GetDataOffset(v12) + v33);
    }
    else
    {
      if ( v35->mProperties.mOffset )
        v26 = (signed __int64)&v35->mProperties + v35->mProperties.mOffset;
      else
        v26 = 0i64;
      if ( v35->mValues.mOffset )
        v23 = (signed __int64)&v35->mValues + v35->mValues.mOffset;
      else
        v23 = 0i64;
      dest = (void *)((unsigned int)UFG::qProperty::GetDataOffset((UFG::qProperty *)(v26 + 8i64 * index)) + v23);
      UFG::qMemCopy(dest, source, v19->mByteSize);
      UFG::qPropertySet::SetPropertyDefaultLocalIdx(v35, index, 0);
      result = dest;
    }
  }
  else
  {
    UFG::qPrintf("[qPropertySetResource] ERROR: Could not find qPropertyType 0x%08x!\n", type_name_uid);
    result = 0i64;
  }
  return result;
}

// File Line: 2264
// RVA: 0x1EB360
void __fastcall UFG::qPropertySet::SetPtr<char>(UFG::qPropertySet *this, unsigned int property_type_uid, unsigned int name_uid, char *property_set_data)
{
  int v4; // ST20_4
  char *v5; // [rsp+28h] [rbp-40h]
  char *dest; // [rsp+30h] [rbp-38h]
  char *v7; // [rsp+38h] [rbp-30h]
  signed __int64 v8; // [rsp+40h] [rbp-28h]
  __int64 v; // [rsp+48h] [rbp-20h]
  char *v10; // [rsp+50h] [rbp-18h]
  void *buffer; // [rsp+58h] [rbp-10h]
  UFG::qPropertySet *v12; // [rsp+70h] [rbp+8h]
  unsigned int type_uid; // [rsp+78h] [rbp+10h]
  unsigned int name_uida; // [rsp+80h] [rbp+18h]
  const char *text; // [rsp+88h] [rbp+20h]

  text = property_set_data;
  name_uida = name_uid;
  type_uid = property_type_uid;
  v12 = this;
  Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
    (hkgpIndexedMesh::EdgeBarrier *)this,
    (hkgpIndexedMeshDefinitions::Edge *)name_uid);
  v = 0i64;
  v10 = (char *)UFG::qPropertySet::SetInternal(v12, type_uid, name_uida, &v);
  v5 = v10;
  if ( *(_QWORD *)v10 )
  {
    if ( *(_QWORD *)v10 )
      v7 = &v10[*(_QWORD *)v10];
    else
      v7 = 0i64;
    buffer = v7;
    UFG::qPropertySet_Free(v7);
    *(_QWORD *)v5 = 0i64;
  }
  v4 = UFG::qStringLength(text);
  dest = (char *)UFG::qPropertySet_Allocate(v4 + 1, "PropertyString", 0);
  UFG::qStringCopy(dest, text);
  if ( dest )
    v8 = dest - v5;
  else
    v8 = 0i64;
  *(_QWORD *)v5 = v8;
}

// File Line: 2294
// RVA: 0x1EB8B0
void __fastcall UFG::qPropertySet::SetPtr<UFG::qPropertySet>(UFG::qPropertySet *this, unsigned int type_uid, unsigned int name_uid, UFG::qPropertySet *property_set_data)
{
  char *v4; // [rsp+20h] [rbp-48h]
  UFG::qPropertySet *v5; // [rsp+30h] [rbp-38h]
  signed __int64 v6; // [rsp+38h] [rbp-30h]
  __int64 v7; // [rsp+40h] [rbp-28h]
  __int64 v; // [rsp+48h] [rbp-20h]
  __int64 *v9; // [rsp+50h] [rbp-18h]
  UFG::qPropertySet *owningSet; // [rsp+70h] [rbp+8h]
  unsigned int type_uida; // [rsp+78h] [rbp+10h]
  unsigned int name_uida; // [rsp+80h] [rbp+18h]
  UFG::qPropertySet *v13; // [rsp+88h] [rbp+20h]

  v13 = property_set_data;
  name_uida = name_uid;
  type_uida = type_uid;
  owningSet = this;
  Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
    (hkgpIndexedMesh::EdgeBarrier *)this,
    (hkgpIndexedMeshDefinitions::Edge *)name_uid);
  v = 0i64;
  v9 = (__int64 *)UFG::qPropertySet::SetInternal(owningSet, type_uida, name_uida, &v);
  v4 = (char *)v9;
  if ( *v9 )
    v5 = (UFG::qPropertySet *)((char *)v9 + *v9);
  else
    v5 = 0i64;
  if ( v5 )
  {
    if ( v5 != v13 )
    {
      UFG::qPropertySet::ReleaseRef(v5);
      UFG::qPropertyCollection::SetOwner((UFG::qPropertyCollection *)&v5->mFlags, 0i64);
      if ( v13 )
        v6 = (char *)v13 - v4;
      else
        v6 = 0i64;
      *(_QWORD *)v4 = v6;
      UFG::qPropertySet::AddRef(v13);
      UFG::qPropertyCollection::SetOwner((UFG::qPropertyCollection *)&v13->mFlags, owningSet);
    }
  }
  else
  {
    if ( v13 )
      v7 = (char *)v13 - (char *)v9;
    else
      v7 = 0i64;
    *v9 = v7;
    UFG::qPropertySet::AddRef(v13);
    UFG::qPropertyCollection::SetOwner((UFG::qPropertyCollection *)&v13->mFlags, owningSet);
  }
}

// File Line: 2326
// RVA: 0x1F9170
char __fastcall UFG::qPropertySet::GetVariant(UFG::qPropertySet *this, UFG::qSymbol *name, qPropertySetVariant *value, UFG::qPropertyDepth depth)
{
  unsigned int v4; // eax
  ePropertyType eType; // [rsp+30h] [rbp-28h]
  __int128 dataPtr; // [rsp+38h] [rbp-20h]
  UFG::qPropertySet *v8; // [rsp+60h] [rbp+8h]
  qPropertySetVariant *v9; // [rsp+70h] [rbp+18h]
  UFG::qPropertyDepth deptha; // [rsp+78h] [rbp+20h]

  deptha = depth;
  v9 = value;
  v8 = this;
  *((_QWORD *)&dataPtr + 1) = 0i64;
  eType = 29;
  v4 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)name);
  dataPtr = (unsigned __int64)UFG::qPropertySet::GetValuePtr2(
                                v8,
                                v4,
                                deptha,
                                (UFG::qPropertySet **)&dataPtr + 1,
                                (unsigned int *)&eType);
  if ( !(_QWORD)dataPtr )
    return 0;
  qPropertySetVariant::Set(v9, (const void *)dataPtr, eType);
  return 1;
}

// File Line: 2344
// RVA: 0x1E9B30
char *__fastcall UFG::qPropertySet::Get<char const *>(UFG::qPropertySet *this, UFG::qSymbol *name, UFG::qPropertyDepth depth)
{
  unsigned int v3; // eax
  _QWORD *v5; // [rsp+38h] [rbp-20h]
  char *v6; // [rsp+40h] [rbp-18h]
  UFG::qPropertySet *v7; // [rsp+60h] [rbp+8h]
  UFG::qPropertyDepth deptha; // [rsp+70h] [rbp+18h]

  deptha = depth;
  v7 = this;
  v3 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)name);
  v5 = UFG::qPropertySet::GetValuePtr(v7, 0xCu, v3, deptha, 0i64);
  if ( !v5 )
    return 0i64;
  if ( *v5 )
    v6 = (char *)v5 + *v5;
  else
    v6 = 0i64;
  return v6;
}

// File Line: 2359
// RVA: 0x1E9EF0
UFG::qPropertySet *__fastcall UFG::qPropertySet::Get<UFG::qPropertySet>(UFG::qPropertySet *this, UFG::qSymbol *name, UFG::qPropertyDepth depth)
{
  unsigned int v3; // eax
  _QWORD *v5; // [rsp+38h] [rbp-20h]
  char *v6; // [rsp+40h] [rbp-18h]
  UFG::qPropertySet *v7; // [rsp+60h] [rbp+8h]
  UFG::qPropertyDepth deptha; // [rsp+70h] [rbp+18h]

  deptha = depth;
  v7 = this;
  v3 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)name);
  v5 = UFG::qPropertySet::GetValuePtr(v7, 0x1Au, v3, deptha, 0i64);
  if ( !v5 )
    return 0i64;
  if ( *v5 )
    v6 = (char *)v5 + *v5;
  else
    v6 = 0i64;
  return (UFG::qPropertySet *)v6;
}

// File Line: 2373
// RVA: 0x1E9E60
UFG::qPropertyList *__fastcall UFG::qPropertySet::Get<UFG::qPropertyList>(UFG::qPropertySet *this, UFG::qSymbol *name, UFG::qPropertyDepth depth)
{
  unsigned int v3; // eax
  _QWORD *v5; // [rsp+38h] [rbp-20h]
  char *v6; // [rsp+40h] [rbp-18h]
  UFG::qPropertySet *v7; // [rsp+60h] [rbp+8h]
  UFG::qPropertyDepth deptha; // [rsp+70h] [rbp+18h]

  deptha = depth;
  v7 = this;
  v3 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)name);
  v5 = UFG::qPropertySet::GetValuePtr(v7, 0x19u, v3, deptha, 0i64);
  if ( !v5 )
    return 0i64;
  if ( *v5 )
    v6 = (char *)v5 + *v5;
  else
    v6 = 0i64;
  return (UFG::qPropertyList *)v6;
}

// File Line: 2390
// RVA: 0x1EA610
bool *__fastcall UFG::qPropertySet::Get<bool>(UFG::qPropertySet *this, UFG::qSymbol *name, UFG::qPropertyDepth depth)
{
  unsigned int v3; // eax
  _BYTE *v5; // [rsp+30h] [rbp-18h]
  bool *v6; // [rsp+38h] [rbp-10h]
  UFG::qPropertySet *v7; // [rsp+50h] [rbp+8h]
  UFG::qPropertyDepth deptha; // [rsp+60h] [rbp+18h]

  deptha = depth;
  v7 = this;
  v3 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)name);
  v5 = UFG::qPropertySet::GetValuePtr(v7, 9u, v3, deptha, 0i64);
  if ( !v5 )
    return 0i64;
  if ( *v5 )
    v6 = &qPropertySet_True;
  else
    v6 = &qPropertySet_False;
  return v6;
}

// File Line: 2401
// RVA: 0x1E95F0
char *__fastcall UFG::qPropertySet::Get<signed char>(UFG::qPropertySet *this, UFG::qSymbol *name, UFG::qPropertyDepth depth)
{
  unsigned int v3; // eax
  UFG::qPropertySet *v5; // [rsp+40h] [rbp+8h]
  UFG::qPropertyDepth deptha; // [rsp+50h] [rbp+18h]

  deptha = depth;
  v5 = this;
  v3 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)name);
  return (char *)UFG::qPropertySet::GetValuePtr(v5, 0, v3, deptha, 0i64);
}

// File Line: 2402
// RVA: 0x1E9760
__int16 *__fastcall UFG::qPropertySet::Get<short>(UFG::qPropertySet *this, UFG::qSymbol *name, UFG::qPropertyDepth depth)
{
  unsigned int v3; // eax
  UFG::qPropertySet *v5; // [rsp+40h] [rbp+8h]
  UFG::qPropertyDepth deptha; // [rsp+50h] [rbp+18h]

  deptha = depth;
  v5 = this;
  v3 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)name);
  return (__int16 *)UFG::qPropertySet::GetValuePtr(v5, 1u, v3, deptha, 0i64);
}

// File Line: 2403
// RVA: 0x1E98E0
int *__fastcall UFG::qPropertySet::Get<long>(UFG::qPropertySet *this, UFG::qSymbol *name, UFG::qPropertyDepth depth)
{
  unsigned int v3; // eax
  UFG::qPropertySet *v5; // [rsp+40h] [rbp+8h]
  UFG::qPropertyDepth deptha; // [rsp+50h] [rbp+18h]

  deptha = depth;
  v5 = this;
  v3 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)name);
  return (int *)UFG::qPropertySet::GetValuePtr(v5, 2u, v3, deptha, 0i64);
}

// File Line: 2404
// RVA: 0x1EA470
__int64 *__fastcall UFG::qPropertySet::Get<__int64>(UFG::qPropertySet *this, UFG::qSymbol *name, UFG::qPropertyDepth depth)
{
  unsigned int v3; // eax
  UFG::qPropertySet *v5; // [rsp+40h] [rbp+8h]
  UFG::qPropertyDepth deptha; // [rsp+50h] [rbp+18h]

  deptha = depth;
  v5 = this;
  v3 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)name);
  return (__int64 *)UFG::qPropertySet::GetValuePtr(v5, 3u, v3, deptha, 0i64);
}

// File Line: 2405
// RVA: 0x1E96A0
char *__fastcall UFG::qPropertySet::Get<unsigned char>(UFG::qPropertySet *this, UFG::qSymbol *name, UFG::qPropertyDepth depth)
{
  unsigned int v3; // eax
  UFG::qPropertySet *v5; // [rsp+40h] [rbp+8h]
  UFG::qPropertyDepth deptha; // [rsp+50h] [rbp+18h]

  deptha = depth;
  v5 = this;
  v3 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)name);
  return (char *)UFG::qPropertySet::GetValuePtr(v5, 5u, v3, deptha, 0i64);
}

// File Line: 2406
// RVA: 0x1E9820
unsigned __int16 *__fastcall UFG::qPropertySet::Get<unsigned short>(UFG::qPropertySet *this, UFG::qSymbol *name, UFG::qPropertyDepth depth)
{
  unsigned int v3; // eax
  UFG::qPropertySet *v5; // [rsp+40h] [rbp+8h]
  UFG::qPropertyDepth deptha; // [rsp+50h] [rbp+18h]

  deptha = depth;
  v5 = this;
  v3 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)name);
  return (unsigned __int16 *)UFG::qPropertySet::GetValuePtr(v5, 6u, v3, deptha, 0i64);
}

// File Line: 2407
// RVA: 0x1E99A0
unsigned int *__fastcall UFG::qPropertySet::Get<unsigned long>(UFG::qPropertySet *this, UFG::qSymbol *name, UFG::qPropertyDepth depth)
{
  unsigned int v3; // eax
  UFG::qPropertySet *v5; // [rsp+40h] [rbp+8h]
  UFG::qPropertyDepth deptha; // [rsp+50h] [rbp+18h]

  deptha = depth;
  v5 = this;
  v3 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)name);
  return (unsigned int *)UFG::qPropertySet::GetValuePtr(v5, 7u, v3, deptha, 0i64);
}

// File Line: 2408
// RVA: 0x1EA530
unsigned __int64 *__fastcall UFG::qPropertySet::Get<unsigned __int64>(UFG::qPropertySet *this, UFG::qSymbol *name, UFG::qPropertyDepth depth)
{
  unsigned int v3; // eax
  UFG::qPropertySet *v5; // [rsp+40h] [rbp+8h]
  UFG::qPropertyDepth deptha; // [rsp+50h] [rbp+18h]

  deptha = depth;
  v5 = this;
  v3 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)name);
  return (unsigned __int64 *)UFG::qPropertySet::GetValuePtr(v5, 8u, v3, deptha, 0i64);
}

// File Line: 2409
// RVA: 0x1E9A60
float *__fastcall UFG::qPropertySet::Get<float>(UFG::qPropertySet *this, UFG::qSymbol *name, UFG::qPropertyDepth depth)
{
  unsigned int v3; // eax
  UFG::qPropertySet *v5; // [rsp+40h] [rbp+8h]
  UFG::qPropertyDepth deptha; // [rsp+50h] [rbp+18h]

  deptha = depth;
  v5 = this;
  v3 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)name);
  return (float *)UFG::qPropertySet::GetValuePtr(v5, 0xAu, v3, deptha, 0i64);
}

// File Line: 2411
// RVA: 0x1E9FF0
UFG::qSymbol *__fastcall UFG::qPropertySet::Get<UFG::qSymbol>(UFG::qPropertySet *this, UFG::qSymbol *name, UFG::qPropertyDepth depth)
{
  unsigned int v3; // eax
  UFG::qPropertySet *v5; // [rsp+40h] [rbp+8h]
  UFG::qPropertyDepth deptha; // [rsp+50h] [rbp+18h]

  deptha = depth;
  v5 = this;
  v3 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)name);
  return (UFG::qSymbol *)UFG::qPropertySet::GetValuePtr(v5, 0x16u, v3, deptha, 0i64);
}

// File Line: 2412
// RVA: 0x1EA0B0
UFG::qSymbolUC *__fastcall UFG::qPropertySet::Get<UFG::qSymbolUC>(UFG::qPropertySet *this, UFG::qSymbol *name, UFG::qPropertyDepth depth)
{
  unsigned int v3; // eax
  UFG::qPropertySet *v5; // [rsp+40h] [rbp+8h]
  UFG::qPropertyDepth deptha; // [rsp+50h] [rbp+18h]

  deptha = depth;
  v5 = this;
  v3 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)name);
  return (UFG::qSymbolUC *)UFG::qPropertySet::GetValuePtr(v5, 0x17u, v3, deptha, 0i64);
}

// File Line: 2413
// RVA: 0x1EA3B0
UFG::qWiseSymbol *__fastcall UFG::qPropertySet::Get<UFG::qWiseSymbol>(UFG::qPropertySet *this, UFG::qSymbol *name, UFG::qPropertyDepth depth)
{
  unsigned int v3; // eax
  UFG::qPropertySet *v5; // [rsp+40h] [rbp+8h]
  UFG::qPropertyDepth deptha; // [rsp+50h] [rbp+18h]

  deptha = depth;
  v5 = this;
  v3 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)name);
  return (UFG::qWiseSymbol *)UFG::qPropertySet::GetValuePtr(v5, 0x18u, v3, deptha, 0i64);
}

// File Line: 2414
// RVA: 0x1EA170
UFG::qVector2 *__fastcall UFG::qPropertySet::Get<UFG::qVector2>(UFG::qPropertySet *this, UFG::qSymbol *name, UFG::qPropertyDepth depth)
{
  unsigned int v3; // eax
  UFG::qPropertySet *v5; // [rsp+40h] [rbp+8h]
  UFG::qPropertyDepth deptha; // [rsp+50h] [rbp+18h]

  deptha = depth;
  v5 = this;
  v3 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)name);
  return (UFG::qVector2 *)UFG::qPropertySet::GetValuePtr(v5, 0x11u, v3, deptha, 0i64);
}

// File Line: 2415
// RVA: 0x1EA230
UFG::qVector3 *__fastcall UFG::qPropertySet::Get<UFG::qVector3>(UFG::qPropertySet *this, UFG::qSymbol *name, UFG::qPropertyDepth depth)
{
  unsigned int v3; // eax
  UFG::qPropertySet *v5; // [rsp+40h] [rbp+8h]
  UFG::qPropertyDepth deptha; // [rsp+50h] [rbp+18h]

  deptha = depth;
  v5 = this;
  v3 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)name);
  return (UFG::qVector3 *)UFG::qPropertySet::GetValuePtr(v5, 0x12u, v3, deptha, 0i64);
}

// File Line: 2416
// RVA: 0x1EA2F0
UFG::qVector4 *__fastcall UFG::qPropertySet::Get<UFG::qVector4>(UFG::qPropertySet *this, UFG::qSymbol *name, UFG::qPropertyDepth depth)
{
  unsigned int v3; // eax
  UFG::qPropertySet *v5; // [rsp+40h] [rbp+8h]
  UFG::qPropertyDepth deptha; // [rsp+50h] [rbp+18h]

  deptha = depth;
  v5 = this;
  v3 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)name);
  return (UFG::qVector4 *)UFG::qPropertySet::GetValuePtr(v5, 0x13u, v3, deptha, 0i64);
}

// File Line: 2417
// RVA: 0x1E9D90
UFG::qMatrix44 *__fastcall UFG::qPropertySet::Get<UFG::qMatrix44>(UFG::qPropertySet *this, UFG::qSymbol *name, UFG::qPropertyDepth depth)
{
  unsigned int v3; // eax
  UFG::qPropertySet *v5; // [rsp+40h] [rbp+8h]
  UFG::qPropertyDepth deptha; // [rsp+50h] [rbp+18h]

  deptha = depth;
  v5 = this;
  v3 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)name);
  return (UFG::qMatrix44 *)UFG::qPropertySet::GetValuePtr(v5, 0x14u, v3, deptha, 0i64);
}

// File Line: 2418
// RVA: 0x1E9CD0
UFG::qTransQuat *__fastcall UFG::qPropertySet::Get<UFG::qTransQuat>(UFG::qPropertySet *this, UFG::qSymbol *name, UFG::qPropertyDepth depth)
{
  unsigned int v3; // eax
  UFG::qPropertySet *v5; // [rsp+40h] [rbp+8h]
  UFG::qPropertyDepth deptha; // [rsp+50h] [rbp+18h]

  deptha = depth;
  v5 = this;
  v3 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)name);
  return (UFG::qTransQuat *)UFG::qPropertySet::GetValuePtr(v5, 0x1Cu, v3, deptha, 0i64);
}

// File Line: 2421
// RVA: 0x1E9C80
UFG::qRangedValue<float> *__fastcall UFG::qPropertySet::Get<UFG::qRangedValue<float>>(UFG::qPropertySet *this, UFG::qSymbol *name, UFG::qPropertyDepth depth)
{
  unsigned int v3; // eax
  UFG::qPropertySet *v5; // [rsp+40h] [rbp+8h]
  UFG::qPropertyDepth deptha; // [rsp+50h] [rbp+18h]

  deptha = depth;
  v5 = this;
  v3 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)name);
  return (UFG::qRangedValue<float> *)UFG::qPropertySet::GetValuePtr(v5, 0xDu, v3, deptha, 0i64);
}

// File Line: 2422
// RVA: 0x1E9C30
UFG::qRangedValue<long> *__fastcall UFG::qPropertySet::Get<UFG::qRangedValue<long>>(UFG::qPropertySet *this, UFG::qSymbol *name, UFG::qPropertyDepth depth)
{
  unsigned int v3; // eax
  UFG::qPropertySet *v5; // [rsp+40h] [rbp+8h]
  UFG::qPropertyDepth deptha; // [rsp+50h] [rbp+18h]

  deptha = depth;
  v5 = this;
  v3 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)name);
  return (UFG::qRangedValue<long> *)UFG::qPropertySet::GetValuePtr(v5, 0xFu, v3, deptha, 0i64);
}

// File Line: 2425
// RVA: 0x1EB270
void __fastcall UFG::qPropertySet::Set<bool>(UFG::qPropertySet *this, UFG::qSymbol *name, bool v)
{
  unsigned int v3; // eax
  bool va; // [rsp+20h] [rbp-18h]
  BOOL v5; // [rsp+24h] [rbp-14h]
  UFG::qPropertySet *v6; // [rsp+40h] [rbp+8h]

  v6 = this;
  v5 = v != 0;
  va = v != 0;
  v3 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)name);
  UFG::qPropertySet::SetInternal(v6, 9u, v3, &va);
}

// File Line: 2426
// RVA: 0x1EACD0
void __fastcall UFG::qPropertySet::Set<signed char>(UFG::qPropertySet *this, UFG::qSymbol *name, char v)
{
  unsigned int v3; // eax
  UFG::qPropertySet *v4; // [rsp+30h] [rbp+8h]
  char va; // [rsp+40h] [rbp+18h]

  va = v;
  v4 = this;
  v3 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)name);
  UFG::qPropertySet::SetInternal(v4, 0, v3, &va);
}

// File Line: 2427
// RVA: 0x1EAD50
void __fastcall UFG::qPropertySet::Set<short>(UFG::qPropertySet *this, UFG::qSymbol *name, __int16 v)
{
  unsigned int v3; // eax
  UFG::qPropertySet *v4; // [rsp+30h] [rbp+8h]
  __int16 va; // [rsp+40h] [rbp+18h]

  va = v;
  v4 = this;
  v3 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)name);
  UFG::qPropertySet::SetInternal(v4, 1u, v3, &va);
}

// File Line: 2428
// RVA: 0x1EADD0
void __fastcall UFG::qPropertySet::Set<long>(UFG::qPropertySet *this, UFG::qSymbol *name, int v)
{
  unsigned int v3; // eax
  UFG::qPropertySet *v4; // [rsp+30h] [rbp+8h]
  int va; // [rsp+40h] [rbp+18h]

  va = v;
  v4 = this;
  v3 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)name);
  UFG::qPropertySet::SetInternal(v4, 2u, v3, &va);
}

// File Line: 2429
// RVA: 0x1EB1F0
void __fastcall UFG::qPropertySet::Set<__int64>(UFG::qPropertySet *this, UFG::qSymbol *name, __int64 v)
{
  unsigned int v3; // eax
  UFG::qPropertySet *v4; // [rsp+30h] [rbp+8h]
  __int64 va; // [rsp+40h] [rbp+18h]

  va = v;
  v4 = this;
  v3 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)name);
  UFG::qPropertySet::SetInternal(v4, 3u, v3, &va);
}

// File Line: 2430
// RVA: 0x1EAED0
void __fastcall UFG::qPropertySet::Set<__m128>(UFG::qPropertySet *this, UFG::qSymbol *name, __m128 *v)
{
  unsigned int v3; // eax
  UFG::qPropertySet *v4; // [rsp+30h] [rbp+8h]
  __m128 *va; // [rsp+40h] [rbp+18h]

  va = v;
  v4 = this;
  v3 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)name);
  UFG::qPropertySet::SetInternal(v4, 4u, v3, va);
}

// File Line: 2431
// RVA: 0x1EAD10
void __fastcall UFG::qPropertySet::Set<unsigned char>(UFG::qPropertySet *this, UFG::qSymbol *name, char v)
{
  unsigned int v3; // eax
  UFG::qPropertySet *v4; // [rsp+30h] [rbp+8h]
  char va; // [rsp+40h] [rbp+18h]

  va = v;
  v4 = this;
  v3 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)name);
  UFG::qPropertySet::SetInternal(v4, 5u, v3, &va);
}

// File Line: 2432
// RVA: 0x1EAD90
void __fastcall UFG::qPropertySet::Set<unsigned short>(UFG::qPropertySet *this, UFG::qSymbol *name, unsigned __int16 v)
{
  unsigned int v3; // eax
  UFG::qPropertySet *v4; // [rsp+30h] [rbp+8h]
  unsigned __int16 va; // [rsp+40h] [rbp+18h]

  va = v;
  v4 = this;
  v3 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)name);
  UFG::qPropertySet::SetInternal(v4, 6u, v3, &va);
}

// File Line: 2433
// RVA: 0x1EAE10
void __fastcall UFG::qPropertySet::Set<unsigned long>(UFG::qPropertySet *this, UFG::qSymbol *name, unsigned int v)
{
  unsigned int v3; // eax
  UFG::qPropertySet *v4; // [rsp+30h] [rbp+8h]
  unsigned int va; // [rsp+40h] [rbp+18h]

  va = v;
  v4 = this;
  v3 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)name);
  UFG::qPropertySet::SetInternal(v4, 7u, v3, &va);
}

// File Line: 2434
// RVA: 0x1EB230
void __fastcall UFG::qPropertySet::Set<unsigned __int64>(UFG::qPropertySet *this, UFG::qSymbol *name, unsigned __int64 v)
{
  unsigned int v3; // eax
  UFG::qPropertySet *v4; // [rsp+30h] [rbp+8h]
  unsigned __int64 va; // [rsp+40h] [rbp+18h]

  va = v;
  v4 = this;
  v3 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)name);
  UFG::qPropertySet::SetInternal(v4, 8u, v3, &va);
}

// File Line: 2435
// RVA: 0x1EAE50
void __fastcall UFG::qPropertySet::Set<float>(UFG::qPropertySet *this, UFG::qSymbol *name, float v)
{
  unsigned int v3; // eax
  UFG::qPropertySet *v4; // [rsp+30h] [rbp+8h]
  float va; // [rsp+40h] [rbp+18h]

  va = v;
  v4 = this;
  v3 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)name);
  UFG::qPropertySet::SetInternal(v4, 0xAu, v3, &va);
}

// File Line: 2438
// RVA: 0x1EB070
void __fastcall UFG::qPropertySet::Set<UFG::qSymbol>(UFG::qPropertySet *this, UFG::qSymbol *name, UFG::qSymbol *v)
{
  unsigned int v3; // eax
  UFG::qPropertySet *v4; // [rsp+30h] [rbp+8h]
  UFG::qSymbol *va; // [rsp+40h] [rbp+18h]

  va = v;
  v4 = this;
  v3 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)name);
  UFG::qPropertySet::SetInternal(v4, 0x16u, v3, va);
}

// File Line: 2439
// RVA: 0x1EB0B0
void __fastcall UFG::qPropertySet::Set<UFG::qSymbolUC>(UFG::qPropertySet *this, UFG::qSymbol *name, UFG::qSymbolUC *v)
{
  unsigned int v3; // eax
  UFG::qPropertySet *v4; // [rsp+30h] [rbp+8h]
  UFG::qSymbolUC *va; // [rsp+40h] [rbp+18h]

  va = v;
  v4 = this;
  v3 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)name);
  UFG::qPropertySet::SetInternal(v4, 0x17u, v3, va);
}

// File Line: 2440
// RVA: 0x1EB1B0
void __fastcall UFG::qPropertySet::Set<UFG::qWiseSymbol>(UFG::qPropertySet *this, UFG::qSymbol *name, UFG::qWiseSymbol *v)
{
  unsigned int v3; // eax
  UFG::qPropertySet *v4; // [rsp+30h] [rbp+8h]
  UFG::qWiseSymbol *va; // [rsp+40h] [rbp+18h]

  va = v;
  v4 = this;
  v3 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)name);
  UFG::qPropertySet::SetInternal(v4, 0x18u, v3, va);
}

// File Line: 2442
// RVA: 0x1EB0F0
void __fastcall UFG::qPropertySet::Set<UFG::qVector2>(UFG::qPropertySet *this, UFG::qSymbol *name, UFG::qVector2 *v)
{
  unsigned int v3; // eax
  UFG::qPropertySet *v4; // [rsp+30h] [rbp+8h]
  UFG::qVector2 *va; // [rsp+40h] [rbp+18h]

  va = v;
  v4 = this;
  v3 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)name);
  UFG::qPropertySet::SetInternal(v4, 0x11u, v3, va);
}

// File Line: 2443
// RVA: 0x1EB130
void __fastcall UFG::qPropertySet::Set<UFG::qVector3>(UFG::qPropertySet *this, UFG::qSymbol *name, UFG::qVector3 *v)
{
  unsigned int v3; // eax
  UFG::qPropertySet *v4; // [rsp+30h] [rbp+8h]
  UFG::qVector3 *va; // [rsp+40h] [rbp+18h]

  va = v;
  v4 = this;
  v3 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)name);
  UFG::qPropertySet::SetInternal(v4, 0x12u, v3, va);
}

// File Line: 2444
// RVA: 0x1EB170
void __fastcall UFG::qPropertySet::Set<UFG::qVector4>(UFG::qPropertySet *this, UFG::qSymbol *name, UFG::qVector4 *v)
{
  unsigned int v3; // eax
  UFG::qPropertySet *v4; // [rsp+30h] [rbp+8h]
  UFG::qVector4 *va; // [rsp+40h] [rbp+18h]

  va = v;
  v4 = this;
  v3 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)name);
  UFG::qPropertySet::SetInternal(v4, 0x13u, v3, va);
}

// File Line: 2445
// RVA: 0x1EAF90
void __fastcall UFG::qPropertySet::Set<UFG::qMatrix44>(UFG::qPropertySet *this, UFG::qSymbol *name, UFG::qMatrix44 *v)
{
  unsigned int v3; // eax
  UFG::qPropertySet *v4; // [rsp+30h] [rbp+8h]
  UFG::qMatrix44 *va; // [rsp+40h] [rbp+18h]

  va = v;
  v4 = this;
  v3 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)name);
  UFG::qPropertySet::SetInternal(v4, 0x14u, v3, va);
}

// File Line: 2446
// RVA: 0x1EAF50
void __fastcall UFG::qPropertySet::Set<UFG::qTransQuat>(UFG::qPropertySet *this, UFG::qSymbol *name, UFG::qTransQuat *v)
{
  unsigned int v3; // eax
  UFG::qPropertySet *v4; // [rsp+30h] [rbp+8h]
  UFG::qTransQuat *va; // [rsp+40h] [rbp+18h]

  va = v;
  v4 = this;
  v3 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)name);
  UFG::qPropertySet::SetInternal(v4, 0x1Cu, v3, va);
}

// File Line: 2448
// RVA: 0x1EB030
void __fastcall UFG::qPropertySet::Set<UFG::qPropertySet>(UFG::qPropertySet *this, UFG::qSymbol *name, UFG::qPropertySet *v)
{
  unsigned int v3; // eax
  UFG::qPropertySet *v4; // [rsp+30h] [rbp+8h]
  UFG::qPropertySet *property_set_data; // [rsp+40h] [rbp+18h]

  property_set_data = v;
  v4 = this;
  v3 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)name);
  UFG::qPropertySet::SetPtr<UFG::qPropertySet>(v4, 0x1Au, v3, property_set_data);
}

// File Line: 2449
// RVA: 0x1EAFE0
void __fastcall UFG::qPropertySet::Set<UFG::qPropertyList>(UFG::qPropertySet *this, UFG::qSymbol *name, UFG::qPropertyList *v)
{
  unsigned int v3; // eax
  UFG::qPropertySet *v4; // [rsp+30h] [rbp+8h]
  UFG::qPropertyList *property_set_data; // [rsp+40h] [rbp+18h]

  property_set_data = v;
  v4 = this;
  v3 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)name);
  UFG::qPropertySet::SetPtr<UFG::qPropertyList>(v4, 0x19u, v3, property_set_data);
}

// File Line: 2452
// RVA: 0x1EAF10
void __fastcall UFG::qPropertySet::Set<UFG::qRangedValue<long>>(UFG::qPropertySet *this, UFG::qSymbol *name, UFG::qRangedValue<long> *v)
{
  unsigned int v3; // eax
  UFG::qPropertySet *v4; // [rsp+30h] [rbp+8h]
  UFG::qRangedValue<long> *va; // [rsp+40h] [rbp+18h]

  va = v;
  v4 = this;
  v3 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)name);
  UFG::qPropertySet::SetInternal(v4, 0xFu, v3, va);
}

// File Line: 2456
// RVA: 0x1EAE90
void __fastcall UFG::qPropertySet::Set<char const *>(UFG::qPropertySet *this, UFG::qSymbol *name, const char *v)
{
  unsigned int v3; // eax
  UFG::qPropertySet *v4; // [rsp+30h] [rbp+8h]
  char *property_set_data; // [rsp+40h] [rbp+18h]

  property_set_data = (char *)v;
  v4 = this;
  v3 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)name);
  UFG::qPropertySet::SetPtr<char>(v4, 0xCu, v3, property_set_data);
}

// File Line: 2460
// RVA: 0x1FE910
char __fastcall UFG::qPropertySet::SetVariant(UFG::qPropertySet *this, UFG::qSymbol *name, qPropertySetVariant *value)
{
  const char *v3; // rax
  $9C4F4E44B7DEC05B9F65CCD36F88E8FF v5; // [rsp+30h] [rbp-18h]
  UFG::qPropertySet *v6; // [rsp+50h] [rbp+8h]
  UFG::qSymbol *namea; // [rsp+58h] [rbp+10h]

  namea = name;
  v6 = this;
  switch ( value->meType )
  {
    case 0:
      UFG::qPropertySet::Set<signed char>(this, name, value->mValueI8);
      break;
    case 1:
      UFG::qPropertySet::Set<short>(this, name, value->mValueI16);
      break;
    case 2:
      UFG::qPropertySet::Set<long>(this, name, value->mValueI32);
      break;
    case 3:
      UFG::qPropertySet::Set<__int64>(this, name, value->mValueI64);
      break;
    case 4:
      v5 = value->16;
      UFG::qPropertySet::Set<__m128>(this, name, (__m128 *)&v5);
      break;
    case 5:
      UFG::qPropertySet::Set<unsigned char>(this, name, value->mValueI8);
      break;
    case 6:
      UFG::qPropertySet::Set<unsigned short>(this, name, value->mValueI128.m128_u16[0]);
      break;
    case 7:
      UFG::qPropertySet::Set<unsigned long>(this, name, value->mValueI128.m128_u32[0]);
      break;
    case 8:
      UFG::qPropertySet::Set<unsigned __int64>(this, name, value->mValueI128.m128_u64[0]);
      break;
    case 9:
      UFG::qPropertySet::Set<bool>(this, name, value->mValueI8);
      break;
    case 0xA:
      UFG::qPropertySet::Set<float>(this, name, *(float *)&value->mValueI32);
      break;
    case 0xB:
    case 0xC:
      v3 = (const char *)Scaleform::SysAllocPagedMalloc::GetUsedSpace((hkMemoryResourceContainer *)&value->mValueString);
      UFG::qPropertySet::Set<char const *>(v6, namea, v3);
      break;
    case 0x11:
      UFG::qPropertySet::Set<UFG::qVector2>(this, name, &value->mValueVector2);
      break;
    case 0x12:
      UFG::qPropertySet::Set<UFG::qVector3>(this, name, &value->mValueVector3);
      break;
    case 0x13:
      UFG::qPropertySet::Set<UFG::qVector4>(this, name, &value->mValueVector4);
      break;
    case 0x16:
      UFG::qPropertySet::Set<UFG::qSymbol>(this, name, &value->mValueSymbol);
      break;
    case 0x17:
      UFG::qPropertySet::Set<UFG::qSymbolUC>(this, name, &value->mValueSymbolUC);
      break;
    case 0x18:
      UFG::qPropertySet::Set<UFG::qWiseSymbol>(this, name, &value->mValueWiseSymbol);
      break;
    default:
      return 1;
  }
  return 1;
}

// File Line: 2527
// RVA: 0x1EA870
char *__fastcall UFG::qPropertySet::GetWithSchema<char const *>(UFG::qPropertySet *this, UFG::qSymbol *name, UFG::qPropertyDepth depth)
{
  UFG::SchemaDef *v4; // [rsp+20h] [rbp-28h]
  UFG::qPropertySet *v5; // [rsp+28h] [rbp-20h]
  char *v6; // [rsp+30h] [rbp-18h]
  UFG::qPropertySet *propertySet; // [rsp+50h] [rbp+8h]
  UFG::qSymbol *propertyName; // [rsp+58h] [rbp+10h]
  UFG::qPropertyDepth deptha; // [rsp+60h] [rbp+18h]

  deptha = depth;
  propertyName = name;
  propertySet = this;
  v4 = UFG::PropertySetManager::GetSchemaForProperty(this, name);
  if ( !v4 )
    return UFG::qPropertySet::Get<char const *>(propertySet, propertyName, deptha);
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(propertySet, &v4->mPropertyName, deptha);
  if ( v5 )
    v6 = UFG::qPropertySet::Get<char const *>(v5, propertyName, deptha);
  else
    v6 = 0i64;
  return v6;
}

// File Line: 2528
// RVA: 0x1EAC30
bool *__fastcall UFG::qPropertySet::GetWithSchema<bool>(UFG::qPropertySet *this, UFG::qSymbol *name, UFG::qPropertyDepth depth)
{
  UFG::SchemaDef *v4; // [rsp+20h] [rbp-28h]
  UFG::qPropertySet *v5; // [rsp+28h] [rbp-20h]
  bool *v6; // [rsp+30h] [rbp-18h]
  UFG::qPropertySet *propertySet; // [rsp+50h] [rbp+8h]
  UFG::qSymbol *propertyName; // [rsp+58h] [rbp+10h]
  UFG::qPropertyDepth deptha; // [rsp+60h] [rbp+18h]

  deptha = depth;
  propertyName = name;
  propertySet = this;
  v4 = UFG::PropertySetManager::GetSchemaForProperty(this, name);
  if ( !v4 )
    return UFG::qPropertySet::Get<bool>(propertySet, propertyName, deptha);
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(propertySet, &v4->mPropertyName, deptha);
  if ( v5 )
    v6 = UFG::qPropertySet::Get<bool>(v5, propertyName, deptha);
  else
    v6 = 0i64;
  return v6;
}

// File Line: 2529
// RVA: 0x1EA730
unsigned int *__fastcall UFG::qPropertySet::GetWithSchema<unsigned long>(UFG::qPropertySet *this, UFG::qSymbol *name, UFG::qPropertyDepth depth)
{
  UFG::SchemaDef *v4; // [rsp+20h] [rbp-28h]
  UFG::qPropertySet *v5; // [rsp+28h] [rbp-20h]
  unsigned int *v6; // [rsp+30h] [rbp-18h]
  UFG::qPropertySet *propertySet; // [rsp+50h] [rbp+8h]
  UFG::qSymbol *propertyName; // [rsp+58h] [rbp+10h]
  UFG::qPropertyDepth deptha; // [rsp+60h] [rbp+18h]

  deptha = depth;
  propertyName = name;
  propertySet = this;
  v4 = UFG::PropertySetManager::GetSchemaForProperty(this, name);
  if ( !v4 )
    return UFG::qPropertySet::Get<unsigned long>(propertySet, propertyName, deptha);
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(propertySet, &v4->mPropertyName, deptha);
  if ( v5 )
    v6 = UFG::qPropertySet::Get<unsigned long>(v5, propertyName, deptha);
  else
    v6 = 0i64;
  return v6;
}

// File Line: 2530
// RVA: 0x1EA690
int *__fastcall UFG::qPropertySet::GetWithSchema<long>(UFG::qPropertySet *this, UFG::qSymbol *name, UFG::qPropertyDepth depth)
{
  UFG::SchemaDef *v4; // [rsp+20h] [rbp-28h]
  UFG::qPropertySet *v5; // [rsp+28h] [rbp-20h]
  int *v6; // [rsp+30h] [rbp-18h]
  UFG::qPropertySet *propertySet; // [rsp+50h] [rbp+8h]
  UFG::qSymbol *propertyName; // [rsp+58h] [rbp+10h]
  UFG::qPropertyDepth deptha; // [rsp+60h] [rbp+18h]

  deptha = depth;
  propertyName = name;
  propertySet = this;
  v4 = UFG::PropertySetManager::GetSchemaForProperty(this, name);
  if ( !v4 )
    return UFG::qPropertySet::Get<long>(propertySet, propertyName, deptha);
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(propertySet, &v4->mPropertyName, deptha);
  if ( v5 )
    v6 = UFG::qPropertySet::Get<long>(v5, propertyName, deptha);
  else
    v6 = 0i64;
  return v6;
}

// File Line: 2533
// RVA: 0x1EA7D0
float *__fastcall UFG::qPropertySet::GetWithSchema<float>(UFG::qPropertySet *this, UFG::qSymbol *name, UFG::qPropertyDepth depth)
{
  UFG::SchemaDef *v4; // [rsp+20h] [rbp-28h]
  UFG::qPropertySet *v5; // [rsp+28h] [rbp-20h]
  float *v6; // [rsp+30h] [rbp-18h]
  UFG::qPropertySet *propertySet; // [rsp+50h] [rbp+8h]
  UFG::qSymbol *propertyName; // [rsp+58h] [rbp+10h]
  UFG::qPropertyDepth deptha; // [rsp+60h] [rbp+18h]

  deptha = depth;
  propertyName = name;
  propertySet = this;
  v4 = UFG::PropertySetManager::GetSchemaForProperty(this, name);
  if ( !v4 )
    return UFG::qPropertySet::Get<float>(propertySet, propertyName, deptha);
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(propertySet, &v4->mPropertyName, deptha);
  if ( v5 )
    v6 = UFG::qPropertySet::Get<float>(v5, propertyName, deptha);
  else
    v6 = 0i64;
  return v6;
}

// File Line: 2535
// RVA: 0x1EAAF0
UFG::qVector3 *__fastcall UFG::qPropertySet::GetWithSchema<UFG::qVector3>(UFG::qPropertySet *this, UFG::qSymbol *name, UFG::qPropertyDepth depth)
{
  UFG::SchemaDef *v4; // [rsp+20h] [rbp-28h]
  UFG::qPropertySet *v5; // [rsp+28h] [rbp-20h]
  UFG::qVector3 *v6; // [rsp+30h] [rbp-18h]
  UFG::qPropertySet *propertySet; // [rsp+50h] [rbp+8h]
  UFG::qSymbol *propertyName; // [rsp+58h] [rbp+10h]
  UFG::qPropertyDepth deptha; // [rsp+60h] [rbp+18h]

  deptha = depth;
  propertyName = name;
  propertySet = this;
  v4 = UFG::PropertySetManager::GetSchemaForProperty(this, name);
  if ( !v4 )
    return UFG::qPropertySet::Get<UFG::qVector3>(propertySet, propertyName, deptha);
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(propertySet, &v4->mPropertyName, deptha);
  if ( v5 )
    v6 = UFG::qPropertySet::Get<UFG::qVector3>(v5, propertyName, deptha);
  else
    v6 = 0i64;
  return v6;
}

// File Line: 2536
// RVA: 0x1EAB90
UFG::qVector4 *__fastcall UFG::qPropertySet::GetWithSchema<UFG::qVector4>(UFG::qPropertySet *this, UFG::qSymbol *name, UFG::qPropertyDepth depth)
{
  UFG::SchemaDef *v4; // [rsp+20h] [rbp-28h]
  UFG::qPropertySet *v5; // [rsp+28h] [rbp-20h]
  UFG::qVector4 *v6; // [rsp+30h] [rbp-18h]
  UFG::qPropertySet *propertySet; // [rsp+50h] [rbp+8h]
  UFG::qSymbol *propertyName; // [rsp+58h] [rbp+10h]
  UFG::qPropertyDepth deptha; // [rsp+60h] [rbp+18h]

  deptha = depth;
  propertyName = name;
  propertySet = this;
  v4 = UFG::PropertySetManager::GetSchemaForProperty(this, name);
  if ( !v4 )
    return UFG::qPropertySet::Get<UFG::qVector4>(propertySet, propertyName, deptha);
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(propertySet, &v4->mPropertyName, deptha);
  if ( v5 )
    v6 = UFG::qPropertySet::Get<UFG::qVector4>(v5, propertyName, deptha);
  else
    v6 = 0i64;
  return v6;
}

// File Line: 2538
// RVA: 0x1EAA50
UFG::qSymbol *__fastcall UFG::qPropertySet::GetWithSchema<UFG::qSymbol>(UFG::qPropertySet *this, UFG::qSymbol *name, UFG::qPropertyDepth depth)
{
  UFG::SchemaDef *v4; // [rsp+20h] [rbp-28h]
  UFG::qPropertySet *v5; // [rsp+28h] [rbp-20h]
  UFG::qSymbol *v6; // [rsp+30h] [rbp-18h]
  UFG::qPropertySet *propertySet; // [rsp+50h] [rbp+8h]
  UFG::qSymbol *propertyName; // [rsp+58h] [rbp+10h]
  UFG::qPropertyDepth deptha; // [rsp+60h] [rbp+18h]

  deptha = depth;
  propertyName = name;
  propertySet = this;
  v4 = UFG::PropertySetManager::GetSchemaForProperty(this, name);
  if ( !v4 )
    return UFG::qPropertySet::Get<UFG::qSymbol>(propertySet, propertyName, deptha);
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(propertySet, &v4->mPropertyName, deptha);
  if ( v5 )
    v6 = UFG::qPropertySet::Get<UFG::qSymbol>(v5, propertyName, deptha);
  else
    v6 = 0i64;
  return v6;
}

// File Line: 2540
// RVA: 0x1EA9B0
UFG::qPropertySet *__fastcall UFG::qPropertySet::GetWithSchema<UFG::qPropertySet>(UFG::qPropertySet *this, UFG::qSymbol *name, UFG::qPropertyDepth depth)
{
  UFG::SchemaDef *v4; // [rsp+20h] [rbp-28h]
  UFG::qPropertySet *v5; // [rsp+28h] [rbp-20h]
  UFG::qPropertySet *v6; // [rsp+30h] [rbp-18h]
  UFG::qPropertySet *propertySet; // [rsp+50h] [rbp+8h]
  UFG::qSymbol *propertyName; // [rsp+58h] [rbp+10h]
  UFG::qPropertyDepth deptha; // [rsp+60h] [rbp+18h]

  deptha = depth;
  propertyName = name;
  propertySet = this;
  v4 = UFG::PropertySetManager::GetSchemaForProperty(this, name);
  if ( !v4 )
    return UFG::qPropertySet::Get<UFG::qPropertySet>(propertySet, propertyName, deptha);
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(propertySet, &v4->mPropertyName, deptha);
  if ( v5 )
    v6 = UFG::qPropertySet::Get<UFG::qPropertySet>(v5, propertyName, deptha);
  else
    v6 = 0i64;
  return v6;
}

// File Line: 2541
// RVA: 0x1EA910
UFG::qPropertyList *__fastcall UFG::qPropertySet::GetWithSchema<UFG::qPropertyList>(UFG::qPropertySet *this, UFG::qSymbol *name, UFG::qPropertyDepth depth)
{
  UFG::SchemaDef *v4; // [rsp+20h] [rbp-28h]
  UFG::qPropertySet *v5; // [rsp+28h] [rbp-20h]
  UFG::qPropertyList *v6; // [rsp+30h] [rbp-18h]
  UFG::qPropertySet *propertySet; // [rsp+50h] [rbp+8h]
  UFG::qSymbol *propertyName; // [rsp+58h] [rbp+10h]
  UFG::qPropertyDepth deptha; // [rsp+60h] [rbp+18h]

  deptha = depth;
  propertyName = name;
  propertySet = this;
  v4 = UFG::PropertySetManager::GetSchemaForProperty(this, name);
  if ( !v4 )
    return UFG::qPropertySet::Get<UFG::qPropertyList>(propertySet, propertyName, deptha);
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(propertySet, &v4->mPropertyName, deptha);
  if ( v5 )
    v6 = UFG::qPropertySet::Get<UFG::qPropertyList>(v5, propertyName, deptha);
  else
    v6 = 0i64;
  return v6;
}

// File Line: 2567
// RVA: 0x1EBA30
void __fastcall UFG::qPropertySet::SetWithSchema<UFG::qSymbol>(UFG::qPropertySet *this, UFG::qSymbol *name, UFG::qSymbol *v)
{
  UFG::SchemaDef *component_schema; // [rsp+20h] [rbp-18h]
  UFG::qPropertySet *v4; // [rsp+28h] [rbp-10h]
  UFG::qPropertySet *propertySet; // [rsp+40h] [rbp+8h]
  UFG::qSymbol *propertyName; // [rsp+48h] [rbp+10h]
  UFG::qSymbol *va; // [rsp+50h] [rbp+18h]

  va = v;
  propertyName = name;
  propertySet = this;
  component_schema = UFG::PropertySetManager::GetSchemaForProperty(this, name);
  if ( component_schema )
  {
    v4 = UFG::PropertySetManager::AddComponentPropertySet(propertySet, component_schema, 0i64);
    if ( v4 )
      UFG::qPropertySet::Set<UFG::qSymbol>(v4, propertyName, va);
  }
  else
  {
    UFG::qPropertySet::Set<UFG::qSymbol>(propertySet, propertyName, va);
  }
}

// File Line: 2573
// RVA: 0x1F1B60
void __fastcall UFG::qPropertySet::AddProperty(UFG::qPropertySet *this, UFG::qSymbol *name, ePropertyType type_uid)
{
  unsigned int v3; // eax
  char *v4; // rax
  UFG::qPropertyList *v5; // rax
  char *v6; // rax
  UFG::qPropertySet *v7; // rax
  unsigned int v8; // eax
  char dest; // [rsp+30h] [rbp-48h]
  UFG::qPropertySet *v10; // [rsp+80h] [rbp+8h]
  UFG::qSymbol *v11; // [rsp+88h] [rbp+10h]
  ePropertyType type_uida; // [rsp+90h] [rbp+18h]

  type_uida = type_uid;
  v11 = name;
  v10 = this;
  if ( (signed int)type_uid < 22 )
    goto LABEL_12;
  if ( (signed int)type_uid <= 23 )
  {
    v3 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)name);
    UFG::qPropertySet::SetInternal(v10, type_uida, v3, &UFG::gNullQSymbol);
    return;
  }
  if ( type_uid == 25 )
  {
    v4 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)name);
    v5 = UFG::qPropertyList::Create(v4);
    UFG::qPropertySet::Set<UFG::qPropertyList>(v10, v11, v5);
    return;
  }
  if ( type_uid == 26 )
  {
    v6 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)name);
    v7 = UFG::qPropertySet::CreateContainedSet(v11, v6);
    UFG::qPropertySet::Set<UFG::qPropertySet>(v10, v11, v7);
  }
  else
  {
LABEL_12:
    UFG::qMemSet(&dest, 0, 0x40u);
    v8 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)v11);
    UFG::qPropertySet::SetInternal(v10, type_uida, v8, &dest);
  }
}

// File Line: 2609
// RVA: 0x1FF820
_BOOL8 __fastcall UFG::qSortPropertyByOffset(UFG::qProperty *a, UFG::qProperty *b)
{
  unsigned int v2; // ST24_4
  UFG::qProperty *v4; // [rsp+48h] [rbp+10h]

  v4 = b;
  v2 = UFG::qProperty::GetDataOffset(a);
  return v2 < (unsigned int)UFG::qProperty::GetDataOffset(v4);
}

// File Line: 2614
// RVA: 0x1FEFA0
void __fastcall UFG::StorePropertyDefaultsInLUT(unsigned int *defaults, UFG::qProperty *properties, int numProperties)
{
  unsigned int v3; // eax
  unsigned int i; // [rsp+4h] [rbp-24h]

  for ( i = 0; i < numProperties; ++i )
  {
    if ( ((1 << (i & 0xDF)) & defaults[i / 0x20]) != 0 )
      v3 = properties[i].mTypeUIDOffsetChanged | 0x80000000;
    else
      v3 = properties[i].mTypeUIDOffsetChanged & 0x7FFFFFFF;
    properties[i].mTypeUIDOffsetChanged = v3;
  }
}

// File Line: 2634
// RVA: 0x1FC910
void __fastcall UFG::RestorePropertyDefaultsInLUT(unsigned int *defaults, UFG::qProperty *properties, int numProperties)
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
    properties[i].mTypeUIDOffsetChanged &= 0x7FFFFFFFu;
  }
}

// File Line: 2666
// RVA: 0x1FEEB0
void __fastcall UFG::qPropertySet::SortForDynamic(unsigned int *defaults, UFG::qProperty *properties, int numProperties)
{
  unsigned int *defaultsa; // [rsp+30h] [rbp+8h]
  UFG::qProperty *propertiesa; // [rsp+38h] [rbp+10h]
  int numPropertiesa; // [rsp+40h] [rbp+18h]

  numPropertiesa = numProperties;
  propertiesa = properties;
  defaultsa = defaults;
  UFG::StorePropertyDefaultsInLUT(defaults, properties, numProperties);
  UFG::qSort<UFG::qProperty,bool (*)(UFG::qProperty const &,UFG::qProperty const &)>(
    propertiesa,
    numPropertiesa,
    UFG::qSortPropertyByOffset);
  UFG::RestorePropertyDefaultsInLUT(defaultsa, propertiesa, numPropertiesa);
}

// File Line: 2675
// RVA: 0x1F7C70
unsigned int __fastcall UFG::qPropertySet::GetPropertyTypeFromName(UFG::qPropertySet *this, UFG::qSymbol *propName, UFG::qPropertyDepth depth)
{
  unsigned int result; // eax
  unsigned int j; // [rsp+20h] [rbp-78h]
  unsigned int i; // [rsp+24h] [rbp-74h]
  unsigned int v6; // [rsp+28h] [rbp-70h]
  unsigned int v7; // [rsp+38h] [rbp-60h]
  int v8; // [rsp+48h] [rbp-50h]
  UFG::qPropertySet *v9; // [rsp+58h] [rbp-40h]
  UFG::SchemaDef *v10; // [rsp+60h] [rbp-38h]
  signed __int64 v11; // [rsp+68h] [rbp-30h]
  UFG::qPropertySet *v12; // [rsp+70h] [rbp-28h]
  signed __int64 v13; // [rsp+78h] [rbp-20h]
  UFG::qPropertySet *propertySet; // [rsp+A0h] [rbp+8h]
  UFG::qSymbol *v15; // [rsp+A8h] [rbp+10h]
  UFG::qPropertyDepth deptha; // [rsp+B0h] [rbp+18h]

  deptha = depth;
  v15 = propName;
  propertySet = this;
  v8 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)propName);
  for ( i = 0; i < propertySet->mNumProperties; ++i )
  {
    if ( propertySet->mProperties.mOffset )
      v13 = (signed __int64)&propertySet->mProperties + propertySet->mProperties.mOffset;
    else
      v13 = 0i64;
    if ( *(_DWORD *)(v13 + 8i64 * i + 4) == v8 )
      return UFG::qProperty::GetTypeUID((UFG::qProperty *)(v13 + 8i64 * i));
  }
  if ( deptha == 1 )
  {
    if ( propertySet->mParents.mOffset )
      v11 = (signed __int64)&propertySet->mParents + propertySet->mParents.mOffset;
    else
      v11 = 0i64;
    v7 = propertySet->mNumParents;
    for ( j = 0; j < v7; ++j )
    {
      v9 = (UFG::qPropertySet *)UFG::qPropertySetHandle::Get((UFG::qPropertySetHandle *)(32i64 * j + v11));
      if ( v9 )
      {
        v6 = UFG::qPropertySet::GetPropertyTypeFromName(v9, v15, DEPTH_RECURSE);
        if ( v6 != 29 )
          return v6;
      }
    }
  }
  v10 = UFG::PropertySetManager::GetSchemaForProperty(propertySet, v15);
  if ( v10 && (v12 = UFG::qPropertySet::Get<UFG::qPropertySet>(propertySet, &v10->mPropertyName, deptha)) != 0i64 )
    result = UFG::qPropertySet::GetPropertyTypeFromName(v12, v15, deptha);
  else
    result = 29;
  return result;
}

