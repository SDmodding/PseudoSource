// File Line: 52
// RVA: 0x1475540
__int64 UFG::_dynamic_initializer_for__sCircleCombat__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("CircleCombat", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&sCircleCombat, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sCircleCombat__);
}

// File Line: 53
// RVA: 0x1475580
__int64 UFG::_dynamic_initializer_for__sSimObjChildren___0()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("SimObjChildren", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&sSimObjChildren_0, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sSimObjChildren___0);
}

// File Line: 80
// RVA: 0x1475440
__int64 UFG::_dynamic_initializer_for__gSceneLayerInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    &UFG::gSceneLayerInventory,
    "SceneLayerInventory",
    0xE0F4D9CC,
    0xE7F23AEE,
    0,
    0);
  UFG::gSceneLayerInventory.vfptr = (UFG::qResourceInventoryVtbl *)&UFG::SceneLayerInventory::`vftable;
  UFG::gSceneLayerInventory.mPurgedScriptUIDs.p = 0i64;
  *(_QWORD *)&UFG::gSceneLayerInventory.mPurgedScriptUIDs.size = 0i64;
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gSceneLayerInventory__);
}

// File Line: 88
// RVA: 0x243900
void __fastcall UFG::SceneLayerInventory::PrintContents(UFG::SceneLayerInventory *this)
{
  UFG::qBaseTreeRB *i; // rbx

  UFG::qPrintf("Contents of Inventory %.64s %d items\n", this->mName, this->mNumResourceData);
  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mResourceDatas);
        i;
        i = UFG::qBaseTreeRB::GetNext(&this->mResourceDatas.mTree, &i->mRoot) )
  {
    UFG::qPrintf(
      "  - Resource TypeUID:0x%08x DataUID:0x%08x Memory:0x%08x Name:%.36s\n",
      LODWORD(i->mNULL.mChild[1]),
      i->mRoot.mUID,
      i,
      (const char *)&i->mNULL.mChild[1] + 4);
  }
}

// File Line: 102
// RVA: 0x239C30
void __fastcall UFG::SceneLayerInventory::Add(UFG::SceneLayerInventory *this, UFG::SceneLayerResource *resource_data)
{
  char v4; // r10
  unsigned int mScriptUID; // r9d
  __int64 v6; // r8
  unsigned int size; // edx
  unsigned int *p; // rcx
  void (__fastcall *m_onSceneLayerResourceLoadedCallback)(UFG::SceneLayerResource *); // rax

  v4 = resource_data->mFlags & 1;
  if ( !v4 )
    goto LABEL_8;
  mScriptUID = resource_data->mScriptUID;
  v6 = 0i64;
  size = this->mPurgedScriptUIDs.size;
  if ( !size )
    goto LABEL_8;
  p = this->mPurgedScriptUIDs.p;
  while ( mScriptUID != p[v6] )
  {
    v6 = (unsigned int)(v6 + 1);
    if ( (unsigned int)v6 >= size )
      goto LABEL_8;
  }
  if ( (_DWORD)v6 == -1 )
  {
LABEL_8:
    if ( v4 )
      UFG::SceneLayerResource::SceneLayerResource(resource_data);
    UFG::qResourceInventory::Add(this, resource_data);
    resource_data->mFlags |= 2u;
    m_onSceneLayerResourceLoadedCallback = this->m_onSceneLayerResourceLoadedCallback;
    if ( m_onSceneLayerResourceLoadedCallback )
      m_onSceneLayerResourceLoadedCallback(resource_data);
  }
}

// File Line: 125
// RVA: 0x245020
void __fastcall UFG::SceneLayerInventory::Remove(
        UFG::SceneLayerInventory *this,
        UFG::SceneLayerResource *resource_data)
{
  void (__fastcall *m_onSceneLayerResourceUnloadedCallback)(UFG::SceneLayerResource *); // rax

  if ( (resource_data->mFlags & 2) != 0 )
  {
    UFG::qResourceInventory::Remove(this, resource_data);
    resource_data->mFlags &= ~2u;
    m_onSceneLayerResourceUnloadedCallback = this->m_onSceneLayerResourceUnloadedCallback;
    if ( m_onSceneLayerResourceUnloadedCallback )
      m_onSceneLayerResourceUnloadedCallback(resource_data);
    if ( (resource_data->mFlags & 1) != 0 )
      UFG::SceneLayerResource::~SceneLayerResource(resource_data);
  }
}

// File Line: 189
// RVA: 0x237900
void __fastcall UFG::SceneLayerResource::SceneLayerResource(UFG::SceneLayerResource *this)
{
  UFG::qPropertySet *v2; // rbx
  unsigned int i; // edi
  __int64 mOffset; // rax
  char *v5; // rcx
  char *v6; // rdx
  UFG::qPropertySet *v7; // rcx
  __int64 v8; // rax
  __int64 v9; // rax

  UFG::qResourceData::qResourceData(this);
  this->mPrev = &this->UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource>;
  this->mNext = &this->UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource>;
  this->mObjects.mNode.mPrev = &this->mObjects.mNode;
  this->mObjects.mNode.mNext = &this->mObjects.mNode;
  v2 = 0i64;
  for ( i = 0; i < this->mPropertySetCount; ++i )
  {
    mOffset = this->mPropertySets.mOffset;
    if ( mOffset )
      v5 = (char *)&this->mPropertySets + mOffset;
    else
      v5 = 0i64;
    v6 = &v5[8 * i];
    if ( *(_QWORD *)v6 )
      v7 = (UFG::qPropertySet *)&v6[*(_QWORD *)v6];
    else
      v7 = 0i64;
    if ( v7 )
      UFG::qPropertySet::qPropertySet(v7);
  }
  v8 = this->mGeoInfoPropSet.mOffset;
  if ( v8 && (UFG::qOffset64<UFG::qPropertySet *> *)((char *)&this->mGeoInfoPropSet + v8) )
  {
    v9 = this->mGeoInfoPropSet.mOffset;
    if ( v9 )
      v2 = (UFG::qPropertySet *)((char *)&this->mGeoInfoPropSet + v9);
    if ( v2 )
      UFG::qPropertySet::qPropertySet(v2);
  }
}

// File Line: 208
// RVA: 0x2379E0
void __fastcall UFG::SceneLayerResource::SceneLayerResource(UFG::SceneLayerResource *this, const char *layer_name)
{
  unsigned int v4; // eax
  float y; // xmm1_4
  float z; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  unsigned int mUID; // edx
  UFG::qSymbol *v10; // rax
  UFG::qPropertySet *ContainedSet; // rbx
  UFG::qList<UFG::SceneObjectProperties,UFG::SceneObjectProperties,0,0> *result; // [rsp+60h] [rbp+18h] BYREF
  UFG::qSymbol v13; // [rsp+68h] [rbp+20h] BYREF

  v4 = UFG::qStringHash32(layer_name, 0xFFFFFFFF);
  UFG::qResourceData::qResourceData(this, 0xE0F4D9CC, v4, layer_name);
  this->mPrev = &this->UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource>;
  this->mNext = &this->UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource>;
  result = &this->mObjects;
  this->mObjects.mNode.mPrev = &this->mObjects.mNode;
  this->mObjects.mNode.mNext = &this->mObjects.mNode;
  *(_QWORD *)&this->mFlags = 0i64;
  this->mPropertySets.mOffset = 0i64;
  this->mGeoInfoPropSet.mOffset = 0i64;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->mAABBMin.x = UFG::qVector3::msZero.x;
  this->mAABBMin.y = y;
  this->mAABBMin.z = z;
  v7 = UFG::qVector3::msZero.y;
  v8 = UFG::qVector3::msZero.z;
  this->mAABBMax.x = UFG::qVector3::msZero.x;
  this->mAABBMax.y = v7;
  this->mAABBMax.z = v8;
  this->mpRuntimeSceneLayer = 0i64;
  mUID = this->mNode.mUID;
  this->mScriptUID = mUID;
  this->mSourceCRC = -1;
  v10 = (UFG::qSymbol *)UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&result, mUID);
  ContainedSet = UFG::qPropertySet::CreateContainedSet(v10, "geo_info_prop_set");
  ContainedSet->mSchemaName = (UFG::qSymbol)UFG::qSymbol::create_from_string(&v13, "default-schema-scenelayer")->mUID;
  UFG::PropertySetManager::SetupSchemaSet(ContainedSet, (UFG::qArray<unsigned long,0> *)&ContainedSet->mSchemaName);
  UFG::SceneLayerResource::SetGeoInfoPropertySet(this, ContainedSet);
  _((AMD_HD3D *)this->mNode.mUID);
}

// File Line: 231
// RVA: 0x238480
void __fastcall UFG::SceneLayerResource::~SceneLayerResource(UFG::SceneLayerResource *this)
{
  UFG::qPropertySet *v2; // rbx
  unsigned int i; // esi
  __int64 mOffset; // rax
  char *v5; // rcx
  char *v6; // rdx
  UFG::qPropertySet *v7; // rcx
  __int64 v8; // rax
  __int64 v9; // rax
  unsigned int j; // esi
  __int64 v11; // rax
  char *v12; // rcx
  char *v13; // rdx
  UFG::qPropertySet *v14; // rcx
  __int64 v15; // rax
  __int64 v16; // rax
  char *v17; // rdx
  __int64 v18; // rax
  __int64 v19; // rax
  UFG::qPropertySet *v20; // rcx
  AMD_HD3D *mUID; // rcx
  UFG::qList<UFG::SceneObjectProperties,UFG::SceneObjectProperties,0,0> *p_mObjects; // r8
  UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties> *k; // rax
  UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties> *v24; // rdx
  UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties> *mPrev; // rcx
  UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties> *mNext; // rax
  UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties> *v27; // rcx
  UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties> *v28; // rax
  UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource> *v29; // rcx
  UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource> *v30; // rax
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *p_mResourceHandles; // rdi
  UFG::qResourceHandle *m; // rbx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v33; // rdx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v34; // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v35; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v36; // rax

  if ( (this->mFlags & 1) != 0 )
  {
    v2 = 0i64;
    for ( i = 0; i < this->mPropertySetCount; ++i )
    {
      mOffset = this->mPropertySets.mOffset;
      if ( mOffset )
        v5 = (char *)&this->mPropertySets + mOffset;
      else
        v5 = 0i64;
      v6 = &v5[8 * i];
      v7 = (UFG::qPropertySet *)&v6[*(_QWORD *)v6];
      if ( !*(_QWORD *)v6 )
        v7 = 0i64;
      UFG::qPropertySet::~qPropertySet(v7);
    }
    v8 = this->mGeoInfoPropSet.mOffset;
    if ( v8 && (UFG::qOffset64<UFG::qPropertySet *> *)((char *)&this->mGeoInfoPropSet + v8) )
    {
      v9 = this->mGeoInfoPropSet.mOffset;
      if ( v9 )
        v2 = (UFG::qPropertySet *)((char *)&this->mGeoInfoPropSet + v9);
      UFG::qPropertySet::~qPropertySet(v2);
    }
  }
  else
  {
    UFG::SceneLayerInventory::Remove(&UFG::gSceneLayerInventory, this);
    for ( j = 0; j < this->mPropertySetCount; ++j )
    {
      v11 = this->mPropertySets.mOffset;
      if ( v11 )
        v12 = (char *)&this->mPropertySets + v11;
      else
        v12 = 0i64;
      v13 = &v12[8 * j];
      v14 = (UFG::qPropertySet *)&v13[*(_QWORD *)v13];
      if ( !*(_QWORD *)v13 )
        v14 = 0i64;
      UFG::qPropertySet::ReleaseRef(v14);
    }
    v15 = this->mPropertySets.mOffset;
    if ( v15 && (UFG::qOffset64<UFG::qOffset64<UFG::qPropertySet *> *> *)((char *)&this->mPropertySets + v15) )
    {
      v16 = this->mPropertySets.mOffset;
      if ( v16 )
        v17 = (char *)&this->mPropertySets + v16;
      else
        v17 = 0i64;
      UFG::qMemoryPool::Free(&gPropertySetMemoryPool, v17);
      this->mPropertySets.mOffset = 0i64;
    }
    v18 = this->mGeoInfoPropSet.mOffset;
    if ( v18 && (UFG::qOffset64<UFG::qPropertySet *> *)((char *)&this->mGeoInfoPropSet + v18) )
    {
      v19 = this->mGeoInfoPropSet.mOffset;
      if ( v19 )
        v20 = (UFG::qPropertySet *)((char *)&this->mGeoInfoPropSet + v19);
      else
        v20 = 0i64;
      UFG::qPropertySet::ReleaseRef(v20);
      this->mGeoInfoPropSet.mOffset = 0i64;
    }
    mUID = (AMD_HD3D *)this->mNode.mUID;
    if ( (_DWORD)mUID != -275271401 )
      _(mUID);
  }
  p_mObjects = &this->mObjects;
  for ( k = this->mObjects.mNode.mNext - 4;
        k != (UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties> *)&this->mDebugName[28];
        k = this->mObjects.mNode.mNext - 4 )
  {
    v24 = k + 4;
    mPrev = k[4].mPrev;
    mNext = k[4].mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    v24->mPrev = v24;
    v24->mNext = v24;
  }
  v27 = p_mObjects->mNode.mPrev;
  v28 = this->mObjects.mNode.mNext;
  v27->mNext = v28;
  v28->mPrev = v27;
  p_mObjects->mNode.mPrev = &p_mObjects->mNode;
  this->mObjects.mNode.mNext = &this->mObjects.mNode;
  v29 = this->mPrev;
  v30 = this->mNext;
  v29->mNext = v30;
  v30->mPrev = v29;
  this->mPrev = &this->UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource>;
  this->mNext = &this->UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource>;
  p_mResourceHandles = &this->mResourceHandles;
  for ( m = (UFG::qResourceHandle *)p_mResourceHandles->mNode.mNext;
        m != (UFG::qResourceHandle *)p_mResourceHandles;
        m = (UFG::qResourceHandle *)p_mResourceHandles->mNode.mNext )
  {
    v33 = m->mPrev;
    v34 = m->mNext;
    v33->mNext = v34;
    v34->mPrev = v33;
    m->mPrev = m;
    m->mNext = m;
    UFG::qResourceHandle::~qResourceHandle(m);
    operator delete[](m);
  }
  v35 = p_mResourceHandles->mNode.mPrev;
  v36 = p_mResourceHandles->mNode.mNext;
  v35->mNext = v36;
  v36->mPrev = v35;
  p_mResourceHandles->mNode.mPrev = &p_mResourceHandles->mNode;
  p_mResourceHandles->mNode.mNext = &p_mResourceHandles->mNode;
}

// File Line: 282
// RVA: 0x23EE30
bool __fastcall UFG::SceneLayerResource::IsGeoInFrustrum(UFG::SceneLayerResource *this)
{
  UFG::BaseCameraComponent *mCurrentCamera; // rdx
  UFG::Camera *p_mCamera; // rdi
  UFG::qMatrix44 *ViewProjection; // rbx
  UFG::qMatrix44 *WorldView; // rax
  float v6; // xmm12_4
  float v7; // xmm11_4
  float v8; // xmm10_4
  float v9; // xmm13_4
  float v10; // xmm14_4
  float v11; // xmm15_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm2_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm0_4
  __m128 v19; // xmm2
  float v20; // xmm0_4
  float v21; // xmm4_4
  __m128 v22; // xmm2
  float v23; // xmm0_4
  __m128 v24; // xmm2
  float v25; // xmm1_4
  float v27; // [rsp+28h] [rbp-B0h]
  float v28; // [rsp+2Ch] [rbp-ACh]
  float v29; // [rsp+30h] [rbp-A8h]
  float v30; // [rsp+3Ch] [rbp-9Ch]
  float v31; // [rsp+40h] [rbp-98h]
  UFG::qMatrix44 result; // [rsp+50h] [rbp-88h] BYREF
  float v33; // [rsp+90h] [rbp-48h]
  float v34; // [rsp+94h] [rbp-44h]
  float v35; // [rsp+98h] [rbp-40h]
  float v36; // [rsp+9Ch] [rbp-3Ch]
  float v37; // [rsp+A0h] [rbp-38h]
  float v38; // [rsp+A4h] [rbp-34h]
  float v39; // [rsp+A8h] [rbp-30h]
  float v40; // [rsp+ACh] [rbp-2Ch]
  float v41; // [rsp+B0h] [rbp-28h]
  float v42; // [rsp+B4h] [rbp-24h]
  float v43; // [rsp+B8h] [rbp-20h]
  float v44; // [rsp+BCh] [rbp-1Ch]
  float v45; // [rsp+C0h] [rbp-18h]
  float v46; // [rsp+C4h] [rbp-14h]
  float centre_distance_to_nearplan; // [rsp+198h] [rbp+C0h] BYREF
  float v48; // [rsp+1A0h] [rbp+C8h]
  float v49; // [rsp+1A8h] [rbp+D0h]
  float vars0; // [rsp+1B0h] [rbp+D8h]

  mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
  p_mCamera = &mCurrentCamera->mCamera;
  if ( !mCurrentCamera )
    p_mCamera = 0i64;
  ViewProjection = UFG::Camera::GetViewProjection(p_mCamera);
  WorldView = UFG::Camera::GetWorldView(p_mCamera);
  UFG::qMatrix44::operator*(WorldView, &result, ViewProjection);
  LODWORD(v6) = COERCE_UNSIGNED_INT(result.v0.x + result.v0.w) ^ _xmm[0];
  LODWORD(v30) = COERCE_UNSIGNED_INT(result.v2.w - result.v2.y) ^ _xmm[0];
  LODWORD(v31) = COERCE_UNSIGNED_INT(result.v1.w - result.v1.y) ^ _xmm[0];
  LODWORD(v7) = COERCE_UNSIGNED_INT(result.v1.x + result.v1.w) ^ _xmm[0];
  LODWORD(v8) = COERCE_UNSIGNED_INT(result.v2.x + result.v2.w) ^ _xmm[0];
  LODWORD(v48) = COERCE_UNSIGNED_INT(result.v0.y + result.v0.w) ^ _xmm[0];
  LODWORD(centre_distance_to_nearplan) = COERCE_UNSIGNED_INT(result.v1.y + result.v1.w) ^ _xmm[0];
  LODWORD(v9) = COERCE_UNSIGNED_INT(result.v0.w - result.v0.x) ^ _xmm[0];
  LODWORD(v10) = COERCE_UNSIGNED_INT(result.v1.w - result.v1.x) ^ _xmm[0];
  LODWORD(v49) = COERCE_UNSIGNED_INT(result.v2.y + result.v2.w) ^ _xmm[0];
  LODWORD(v11) = COERCE_UNSIGNED_INT(result.v2.w - result.v2.x) ^ _xmm[0];
  LODWORD(vars0) = COERCE_UNSIGNED_INT(result.v0.w + result.v1.y) ^ _xmm[0];
  LODWORD(v27) = COERCE_UNSIGNED_INT(result.v0.w - result.v0.z) ^ _xmm[0];
  LODWORD(v29) = COERCE_UNSIGNED_INT(result.v1.w - result.v1.z) ^ _xmm[0];
  LODWORD(v28) = COERCE_UNSIGNED_INT(result.v2.w - result.v2.z) ^ _xmm[0];
  v12 = fsqrt(
          (float)((float)(COERCE_FLOAT(LODWORD(result.v1.z) ^ _xmm[0]) * COERCE_FLOAT(LODWORD(result.v1.z) ^ _xmm[0]))
                + (float)(COERCE_FLOAT(LODWORD(result.v0.z) ^ _xmm[0]) * COERCE_FLOAT(LODWORD(result.v0.z) ^ _xmm[0])))
        + (float)(COERCE_FLOAT(LODWORD(result.v2.z) ^ _xmm[0]) * COERCE_FLOAT(LODWORD(result.v2.z) ^ _xmm[0])));
  v13 = (float)(1.0 / v12) * COERCE_FLOAT(LODWORD(result.v1.z) ^ _xmm[0]);
  result.v2.y = (float)(1.0 / v12) * COERCE_FLOAT(LODWORD(result.v1.x) ^ _xmm[0]);
  result.v1.z = (float)(1.0 / v12) * COERCE_FLOAT(LODWORD(result.v0.z) ^ _xmm[0]);
  result.v2.x = (float)(1.0 / v12) * COERCE_FLOAT(LODWORD(result.v2.z) ^ _xmm[0]);
  result.v1.w = v13;
  v14 = fsqrt((float)((float)(v7 * v7) + (float)(v6 * v6)) + (float)(v8 * v8));
  v15 = (float)(1.0 / v14) * v6;
  v16 = (float)(1.0 / v14) * v7;
  v17 = 1.0 / v14;
  result.v2.z = v15;
  result.v2.w = v16;
  result.v3.y = v17 * COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v0.z + result.v1.y) ^ _xmm[0]);
  result.v3.x = v17 * v8;
  v18 = fsqrt((float)((float)(v10 * v10) + (float)(v9 * v9)) + (float)(v11 * v11));
  v34 = (float)(1.0 / v18) * COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v1.y - result.v0.z) ^ _xmm[0]);
  result.v3.z = (float)(1.0 / v18) * v9;
  v33 = (float)(1.0 / v18) * v11;
  result.v3.w = (float)(1.0 / v18) * v10;
  v19 = (__m128)LODWORD(centre_distance_to_nearplan);
  v19.m128_f32[0] = (float)((float)(v19.m128_f32[0] * v19.m128_f32[0]) + (float)(v48 * v48)) + (float)(v49 * v49);
  v20 = _mm_sqrt_ps(v19).m128_f32[0];
  LODWORD(v21) = COERCE_UNSIGNED_INT(result.v0.w - result.v0.y) ^ _xmm[0];
  v35 = (float)(1.0 / v20) * v48;
  v37 = (float)(1.0 / v20) * v49;
  v36 = (float)(1.0 / v20) * centre_distance_to_nearplan;
  v22 = (__m128)LODWORD(v31);
  v38 = (float)(1.0 / v20) * vars0;
  v22.m128_f32[0] = (float)((float)(v22.m128_f32[0] * v22.m128_f32[0]) + (float)(v21 * v21)) + (float)(v30 * v30);
  v23 = 1.0 / _mm_sqrt_ps(v22).m128_f32[0];
  v42 = v23 * COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v1.y - result.v0.w) ^ _xmm[0]);
  v39 = v23 * v21;
  v40 = v23 * v31;
  v41 = v23 * v30;
  v24 = (__m128)LODWORD(v29);
  v24.m128_f32[0] = (float)((float)(v24.m128_f32[0] * v24.m128_f32[0]) + (float)(v27 * v27)) + (float)(v28 * v28);
  v25 = 1.0 / _mm_sqrt_ps(v24).m128_f32[0];
  v46 = v25 * COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v1.y - result.v1.x) ^ _xmm[0]);
  v45 = v25 * v28;
  v43 = v25 * v27;
  v44 = v25 * v29;
  centre_distance_to_nearplan = 0.0;
  return (unsigned int)IntersectAABBFrustum(
                         (UFG::qVector4 *)&result.v1.z,
                         &this->mAABBMin,
                         &this->mAABBMax,
                         &centre_distance_to_nearplan) <= 1;
}

// File Line: 304
// RVA: 0x23EDB0
bool __fastcall UFG::SceneLayerResource::IsGeoClose(
        UFG::SceneLayerResource *this,
        UFG::qVector3 *testPoint,
        float maxDistanceSq)
{
  float y; // xmm1_4
  float z; // xmm0_4
  float x; // xmm1_4
  float v6; // xmm0_4
  float v7; // xmm1_4
  UFG::qBox v9; // [rsp+20h] [rbp-38h] BYREF

  y = this->mAABBMin.y;
  v9.mMin.x = this->mAABBMin.x;
  z = this->mAABBMin.z;
  v9.mMin.y = y;
  x = this->mAABBMax.x;
  v9.mMin.z = z;
  v6 = this->mAABBMax.y;
  v9.mMax.x = x;
  v7 = this->mAABBMax.z;
  v9.mMax.y = v6;
  v9.mMax.z = v7;
  return maxDistanceSq > UFG::qBox::DistanceSqrPoint(&v9, testPoint);
}

// File Line: 346
// RVA: 0x23BBE0
UFG::qPropertySet *__fastcall UFG::FindObjectPropertySetRecurse(
        UFG::qPropertySet *propertySet,
        UFG::qSymbol *objectName)
{
  UFG::qPropertySet *result; // rax
  UFG::qPropertyList *v4; // rax
  UFG::qPropertyList *v5; // rsi
  unsigned int mNumElements; // edi
  unsigned int v7; // ebx
  char *ValuePtr; // rax
  UFG::qPropertySet *v9; // rcx

  if ( propertySet->mName.mUID == objectName->mUID )
    return propertySet;
  v4 = UFG::qPropertySet::Get<UFG::qPropertyList>(
         propertySet,
         (UFG::qArray<unsigned long,0> *)&sSimObjChildren_0,
         DEPTH_RECURSE);
  v5 = v4;
  if ( !v4 )
    return 0i64;
  mNumElements = v4->mNumElements;
  v7 = 0;
  if ( !mNumElements )
    return 0i64;
  while ( 1 )
  {
    ValuePtr = UFG::qPropertyList::GetValuePtr(v5, 0x1Au, v7);
    if ( ValuePtr && *(_QWORD *)ValuePtr )
      v9 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr];
    else
      v9 = 0i64;
    result = UFG::FindObjectPropertySetRecurse(v9, objectName);
    if ( result )
      break;
    if ( ++v7 >= mNumElements )
      return 0i64;
  }
  return result;
}

// File Line: 370
// RVA: 0x23BB60
UFG::qPropertySet *__fastcall UFG::SceneLayerResource::FindObjectPropertySet(
        UFG::SceneLayerResource *this,
        UFG::qSymbol *objectName)
{
  __int64 mOffset; // rax
  char *v5; // rsi
  __int64 v6; // rbx
  __int64 v7; // rax
  UFG::qPropertySet *v8; // rcx
  UFG::qPropertySet *result; // rax

  mOffset = this->mPropertySets.mOffset;
  if ( !mOffset )
    return 0i64;
  v5 = (char *)&this->mPropertySets + mOffset;
  if ( !v5 )
    return 0i64;
  v6 = 0i64;
  if ( !this->mPropertySetCount )
    return 0i64;
  while ( 1 )
  {
    v7 = *(_QWORD *)&v5[8 * v6];
    v8 = v7 ? (UFG::qPropertySet *)&v5[8 * v6 + v7] : 0i64;
    result = UFG::FindObjectPropertySetRecurse(v8, objectName);
    if ( result )
      break;
    v6 = (unsigned int)(v6 + 1);
    if ( (unsigned int)v6 >= this->mPropertySetCount )
      return 0i64;
  }
  return result;
}

// File Line: 387
// RVA: 0x239CD0
void __fastcall UFG::SceneLayerResource::AddPropertySet(UFG::SceneLayerResource *this, UFG::qPropertySet *property_set)
{
  __int64 mOffset; // r10
  UFG::qOffset64<UFG::qOffset64<UFG::qPropertySet *> *> *p_mPropertySets; // r14
  char *v6; // r9
  unsigned int mPropertySetCount; // edx
  __int64 v8; // r8
  UFG::qPropertySet *v9; // rax
  __int64 v10; // rsi
  char *v11; // rbp
  UFG::allocator::free_link *v12; // rax
  UFG::allocator::free_link *v13; // rdi
  __int64 *v14; // rcx
  __int64 v15; // r9
  signed __int64 v16; // r8
  __int64 v17; // rdx
  __int64 v18; // rax
  char *v19; // rdx
  char *v20; // rax

  mOffset = this->mPropertySets.mOffset;
  p_mPropertySets = &this->mPropertySets;
  if ( !mOffset )
    goto LABEL_10;
  v6 = (char *)p_mPropertySets + mOffset;
  if ( !(UFG::qOffset64<UFG::qOffset64<UFG::qPropertySet *> *> *)((char *)p_mPropertySets + mOffset) )
    goto LABEL_10;
  mPropertySetCount = this->mPropertySetCount;
  v8 = 0i64;
  if ( !mPropertySetCount )
    goto LABEL_10;
  while ( 1 )
  {
    v9 = *(UFG::qPropertySet **)&v6[8 * v8];
    if ( v9 )
      v9 = (UFG::qPropertySet *)&v6[8 * v8 + (_QWORD)v9];
    if ( v9 == property_set )
      break;
    v8 = (unsigned int)(v8 + 1);
    if ( (unsigned int)v8 >= mPropertySetCount )
      goto LABEL_10;
  }
  if ( (_DWORD)v8 == -1 )
  {
LABEL_10:
    v10 = this->mPropertySetCount;
    if ( mOffset )
      v11 = (char *)p_mPropertySets + mOffset;
    else
      v11 = 0i64;
    v12 = UFG::qMemoryPool::Allocate(
            &gPropertySetMemoryPool,
            (unsigned int)(8 * (v10 + 1)),
            "SceneLayerResource::mPropertySets",
            0i64,
            1u);
    v13 = v12;
    if ( (_DWORD)v10 )
    {
      v14 = (__int64 *)v11;
      v15 = v10;
      v16 = (char *)v12 - v11;
      do
      {
        v17 = *v14;
        if ( *v14 && (__int64 *)((char *)v14 + v17) )
          v18 = v17 - v16;
        else
          v18 = 0i64;
        *(__int64 *)((char *)v14++ + v16) = v18;
        --v15;
      }
      while ( v15 );
    }
    v19 = (char *)&v13[(unsigned int)v10];
    if ( property_set )
      v20 = (char *)((char *)property_set - v19);
    else
      v20 = 0i64;
    *(_QWORD *)v19 = v20;
    if ( v11 )
      UFG::qMemoryPool::Free(&gPropertySetMemoryPool, v11);
    if ( v13 )
      v13 = (UFG::allocator::free_link *)((char *)v13 - (__int64)p_mPropertySets);
    p_mPropertySets->mOffset = (__int64)v13;
    this->mPropertySetCount = v10 + 1;
    property_set->mFlags &= 0xFFFFFFFu;
    property_set->mFlags |= 0x20000000u;
    UFG::qPropertySet::AddRef(property_set);
  }
}

// File Line: 426
// RVA: 0x2450F0
char __fastcall UFG::SceneLayerResource::RemovePropertySet(
        UFG::SceneLayerResource *this,
        UFG::qPropertySet *property_set)
{
  __int64 mOffset; // rax
  UFG::qOffset64<UFG::qOffset64<UFG::qPropertySet *> *> *p_mPropertySets; // r15
  char *v6; // rdi
  __int64 mPropertySetCount; // rsi
  __int64 v8; // rbx
  UFG::qPropertySet *v9; // rax
  UFG::allocator::free_link *v11; // rax
  __int64 v12; // r9
  UFG::allocator::free_link *v13; // rbp
  __int64 *v14; // rcx
  signed __int64 v15; // r8
  __int64 v16; // rdx
  __int64 v17; // rax
  int v18; // eax
  char *v19; // rcx
  __int64 v20; // r8
  __int64 v21; // rdx
  __int64 v22; // rax

  mOffset = this->mPropertySets.mOffset;
  p_mPropertySets = &this->mPropertySets;
  if ( !mOffset )
    return 0;
  v6 = (char *)p_mPropertySets + mOffset;
  if ( !(UFG::qOffset64<UFG::qOffset64<UFG::qPropertySet *> *> *)((char *)p_mPropertySets + mOffset) )
    return 0;
  mPropertySetCount = (int)this->mPropertySetCount;
  v8 = 0i64;
  if ( !(_DWORD)mPropertySetCount )
    return 0;
  while ( 1 )
  {
    v9 = *(UFG::qPropertySet **)&v6[8 * v8];
    if ( v9 )
      v9 = (UFG::qPropertySet *)&v6[8 * v8 + (_QWORD)v9];
    if ( v9 == property_set )
      break;
    v8 = (unsigned int)(v8 + 1);
    if ( (unsigned int)v8 >= (unsigned int)mPropertySetCount )
      return 0;
  }
  if ( (_DWORD)v8 == -1 )
    return 0;
  v11 = UFG::qMemoryPool::Allocate(
          &gPropertySetMemoryPool,
          (unsigned int)(8 * (mPropertySetCount - 1)),
          "PropertySetList",
          0i64,
          1u);
  v12 = (int)v8;
  v13 = v11;
  if ( (int)v8 > 0 )
  {
    v14 = (__int64 *)v6;
    v15 = (char *)v11 - v6;
    do
    {
      v16 = *v14;
      if ( *v14 && (__int64 *)((char *)v14 + v16) )
        v17 = v16 - v15;
      else
        v17 = 0i64;
      *(__int64 *)((char *)v14++ + v15) = v17;
      --v12;
    }
    while ( v12 );
  }
  v18 = v8 + 1;
  if ( (int)v8 + 1 < mPropertySetCount )
  {
    v19 = &v6[8 * v18];
    v20 = (char *)v13 - v6 - 8;
    v21 = mPropertySetCount - v18;
    do
    {
      if ( *(_QWORD *)v19 && &v19[*(_QWORD *)v19] )
        v22 = *(_QWORD *)v19 - v20;
      else
        v22 = 0i64;
      *(_QWORD *)&v19[v20] = v22;
      v19 += 8;
      --v21;
    }
    while ( v21 );
  }
  if ( v6 )
    UFG::qMemoryPool::Free(&gPropertySetMemoryPool, v6);
  if ( v13 )
    v13 = (UFG::allocator::free_link *)((char *)v13 - (__int64)p_mPropertySets);
  p_mPropertySets->mOffset = (__int64)v13;
  this->mPropertySetCount = mPropertySetCount - 1;
  property_set->mFlags &= 0xFFFFFFFu;
  UFG::qPropertySet::ReleaseRef(property_set);
  return 1;
}

// File Line: 477
// RVA: 0x2454D0
void __fastcall UFG::SceneLayerResource::SetGeoInfoPropertySet(
        UFG::SceneLayerResource *this,
        UFG::qPropertySet *property_set)
{
  __int64 mOffset; // rax
  UFG::qOffset64<UFG::qPropertySet *> *p_mGeoInfoPropSet; // rsi
  char *v4; // rdi
  UFG::qPropertySet *v5; // rcx

  mOffset = this->mGeoInfoPropSet.mOffset;
  p_mGeoInfoPropSet = &this->mGeoInfoPropSet;
  v4 = 0i64;
  v5 = (UFG::qPropertySet *)((char *)&this->mGeoInfoPropSet + mOffset);
  if ( !mOffset )
    v5 = 0i64;
  if ( property_set != v5 )
  {
    if ( v5 )
    {
      v5->mFlags &= 0xFFFFFFFu;
      UFG::qPropertySet::ReleaseRef(v5);
    }
    if ( property_set )
      v4 = (char *)((char *)property_set - (char *)p_mGeoInfoPropSet);
    p_mGeoInfoPropSet->mOffset = (__int64)v4;
    UFG::qPropertySet::AddRef(property_set);
    property_set->mFlags = property_set->mFlags & 0xFFFFFFF | 0x30000000;
  }
}

// File Line: 853
// RVA: 0x23D970
UFG::qPropertySet *__fastcall UFG::SceneLayerResource::GetNamedPropertySet(
        UFG::SceneLayerResource *this,
        UFG::qSymbol *name)
{
  __int64 mOffset; // rax
  __int64 *v3; // rax
  unsigned int mPropertySetCount; // r9d
  unsigned int v5; // r8d
  unsigned int mUID; // edx
  __int64 v7; // rcx

  mOffset = this->mPropertySets.mOffset;
  if ( !mOffset )
    return 0i64;
  v3 = (__int64 *)((char *)&this->mPropertySets.mOffset + mOffset);
  if ( !v3 )
    return 0i64;
  mPropertySetCount = this->mPropertySetCount;
  v5 = 0;
  if ( !mPropertySetCount )
    return 0i64;
  mUID = name->mUID;
  while ( 1 )
  {
    v7 = *v3;
    if ( *v3 )
      v7 += (__int64)v3;
    if ( *(_DWORD *)(v7 + 64) == mUID )
      break;
    ++v5;
    ++v3;
    if ( v5 >= mPropertySetCount )
      return 0i64;
  }
  return (UFG::qPropertySet *)v7;
}

// File Line: 870
// RVA: 0x1475720
__int64 UFG::_dynamic_initializer_for__symComponentRegion__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("default-component-Region", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symComponentRegion, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__symComponentRegion__);
}

// File Line: 871
// RVA: 0x1475920
__int64 UFG::_dynamic_initializer_for__symXformLocal__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("XformLocal", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symXformLocal, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__symXformLocal__);
}

// File Line: 872
// RVA: 0x1475960
__int64 UFG::_dynamic_initializer_for__symXformLocalQuat__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("XformLocalQuat", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symXformLocalQuat, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__symXformLocalQuat__);
}

// File Line: 873
// RVA: 0x14758A0
__int64 UFG::_dynamic_initializer_for__symType__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Type", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symType, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__symType__);
}

// File Line: 874
// RVA: 0x1475820
__int64 UFG::_dynamic_initializer_for__symMin__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Min", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symMin, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__symMin__);
}

// File Line: 875
// RVA: 0x14757E0
__int64 UFG::_dynamic_initializer_for__symMax__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Max", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symMax, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__symMax__);
}

// File Line: 876
// RVA: 0x1475860
__int64 UFG::_dynamic_initializer_for__symRadius__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Radius", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symRadius, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__symRadius__);
}

// File Line: 877
// RVA: 0x1475760
__int64 UFG::_dynamic_initializer_for__symExtentAbove__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("ExtentAbove", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symExtentAbove, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__symExtentAbove__);
}

// File Line: 878
// RVA: 0x14757A0
__int64 UFG::_dynamic_initializer_for__symExtentBelow__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("ExtentBelow", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symExtentBelow, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__symExtentBelow__);
}

// File Line: 879
// RVA: 0x14758E0
__int64 UFG::_dynamic_initializer_for__symVertexes__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Vertexes", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symVertexes, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__symVertexes__);
}

// File Line: 882
// RVA: 0x2393A0
void __fastcall UFG::SceneLayerResource::AccumulateBounds(UFG::SceneLayerResource *this, UFG::qBox *box)
{
  unsigned int mPropertySetCount; // eax
  __int64 v5; // r12
  __int64 i; // r15
  __int64 mOffset; // rax
  char *v8; // rcx
  char *v9; // rax
  __int64 v10; // rcx
  UFG::qPropertySet *v11; // rbx
  UFG::qPropertySet *v12; // rsi
  UFG::qMatrix44 *v13; // rax
  int z_low; // xmm1_4
  float x; // xmm6_4
  float v16; // xmm7_4
  float y; // xmm8_4
  float z; // xmm9_4
  int w_low; // xmm0_4
  int x_low; // xmm1_4
  int v21; // xmm0_4
  int v22; // xmm1_4
  int v23; // xmm0_4
  int v24; // xmm1_4
  int v25; // xmm0_4
  int v26; // xmm1_4
  unsigned int *v27; // rax
  int v28; // eax
  int v29; // eax
  int v30; // eax
  float *v31; // rbx
  float *v32; // rax
  float v33; // xmm8_4
  float v34; // xmm7_4
  UFG::qPropertyList *v35; // rax
  unsigned int v36; // ebx
  unsigned int mNumElements; // esi
  UFG::qPropertyList *v38; // r14
  UFG::qVector3 *v39; // rax
  float v40; // xmm1_4
  float v41; // xmm4_4
  float v42; // xmm2_4
  float v43; // xmm0_4
  float v44; // xmm1_4
  float v45; // xmm3_4
  float v46; // xmm1_4
  float v47; // xmm1_4
  float v48; // xmm2_4
  float v49; // xmm3_4
  float v50; // xmm2_4
  float v51; // xmm1_4
  float v52; // xmm0_4
  float v53; // xmm3_4
  float v54; // xmm4_4
  float v55; // xmm3_4
  float v56; // xmm2_4
  float v57; // xmm1_4
  UFG::qVector3 *v58; // rax
  unsigned __int64 v59; // rcx
  __int64 v60; // rdx
  float v61; // xmm4_4
  float v62; // xmm3_4
  float v63; // xmm1_4
  float v64; // xmm2_4
  float v65; // xmm0_4
  float v66; // xmm1_4
  float v67; // xmm0_4
  float v68; // xmm0_4
  float v69; // xmm0_4
  float *v70; // rax
  float v71; // xmm6_4
  UFG::qVector3 *v72; // rdx
  UFG::qVector3 pos; // [rsp+8h] [rbp-79h] BYREF
  int v74[3]; // [rsp+14h] [rbp-6Dh] BYREF
  __int64 v75[3]; // [rsp+20h] [rbp-61h]
  float v76; // [rsp+38h] [rbp-49h]
  float v77; // [rsp+3Ch] [rbp-45h]
  int v78; // [rsp+40h] [rbp-41h]
  int v79; // [rsp+44h] [rbp-3Dh]
  int v80; // [rsp+48h] [rbp-39h]
  float v81; // [rsp+4Ch] [rbp-35h]
  int v82; // [rsp+50h] [rbp-31h]
  int v83; // [rsp+54h] [rbp-2Dh]
  int v84; // [rsp+58h] [rbp-29h]
  float v85; // [rsp+5Ch] [rbp-25h]
  int v86; // [rsp+60h] [rbp-21h]
  int v87; // [rsp+64h] [rbp-1Dh]
  UFG::qVector3 v88; // [rsp+68h] [rbp-19h] BYREF
  int v89; // [rsp+74h] [rbp-Dh]

  mPropertySetCount = this->mPropertySetCount;
  if ( mPropertySetCount )
  {
    v5 = mPropertySetCount;
    for ( i = 0i64; ; i += 8i64 )
    {
      mOffset = this->mPropertySets.mOffset;
      v8 = mOffset ? (char *)&this->mPropertySets + mOffset : 0i64;
      v9 = &v8[i];
      v10 = *(_QWORD *)&v8[i];
      v11 = v10 ? (UFG::qPropertySet *)&v9[v10] : 0i64;
      v12 = UFG::qPropertySet::Get<UFG::qPropertySet>(
              v11,
              (UFG::qArray<unsigned long,0> *)&UFG::symComponentRegion,
              DEPTH_RECURSE);
      v13 = UFG::qPropertySet::Get<UFG::qMatrix44>(
              v11,
              (UFG::qArray<unsigned long,0> *)&UFG::symXformLocal,
              DEPTH_RECURSE);
      z_low = LODWORD(v13->v0.z);
      x = v13->v0.x;
      v16 = v13->v3.x;
      y = v13->v3.y;
      z = v13->v3.z;
      v77 = v13->v0.y;
      w_low = LODWORD(v13->v0.w);
      v78 = z_low;
      x_low = LODWORD(v13->v1.x);
      v79 = w_low;
      v81 = v13->v1.y;
      v21 = LODWORD(v13->v1.w);
      v80 = x_low;
      v22 = LODWORD(v13->v1.z);
      v83 = v21;
      v85 = v13->v2.y;
      v23 = LODWORD(v13->v2.w);
      v82 = v22;
      v24 = LODWORD(v13->v2.x);
      v87 = v23;
      v25 = LODWORD(v13->v3.w);
      v84 = v24;
      v26 = LODWORD(v13->v2.z);
      v89 = v25;
      v76 = x;
      v86 = v26;
      v88.x = v16;
      v88.y = y;
      v88.z = z;
      if ( !v12 )
        break;
      v27 = UFG::qPropertySet::Get<unsigned long>(v12, (UFG::qArray<unsigned long,0> *)&UFG::symType, DEPTH_RECURSE);
      if ( v27 )
      {
        v28 = *v27 - 2;
        if ( v28 )
        {
          v29 = v28 - 1;
          if ( v29 )
          {
            v30 = v29 - 3;
            if ( v30 )
            {
              if ( v30 == 2 )
              {
                v31 = UFG::qPropertySet::Get<float>(
                        v12,
                        (UFG::qArray<unsigned long,0> *)&UFG::symExtentAbove,
                        DEPTH_RECURSE);
                v32 = UFG::qPropertySet::Get<float>(
                        v12,
                        (UFG::qArray<unsigned long,0> *)&UFG::symExtentBelow,
                        DEPTH_RECURSE);
                v33 = *v31;
                v34 = *v32;
                v35 = UFG::qPropertySet::Get<UFG::qPropertyList>(
                        v12,
                        (UFG::qArray<unsigned long,0> *)&UFG::symVertexes,
                        DEPTH_RECURSE);
                v36 = 0;
                mNumElements = v35->mNumElements;
                v38 = v35;
                if ( mNumElements )
                {
                  do
                  {
                    v39 = UFG::qPropertyList::Get<UFG::qVector3>(v38, v36);
                    v40 = box->mMin.x;
                    v41 = v39->x * x;
                    v42 = v39->y * x;
                    v43 = (float)(v33 + v39->z) * x;
                    if ( box->mMin.x >= v41 )
                      v40 = v39->x * x;
                    box->mMin.x = v40;
                    v44 = box->mMin.y;
                    if ( v44 >= v42 )
                      v44 = v42;
                    box->mMin.y = v44;
                    v45 = box->mMin.z;
                    if ( v45 >= v43 )
                      v45 = v43;
                    box->mMin.z = v45;
                    v46 = box->mMax.x;
                    if ( v46 <= v41 )
                      v46 = v41;
                    box->mMax.x = v46;
                    v47 = box->mMax.y;
                    if ( v47 <= v42 )
                      v47 = v42;
                    box->mMax.y = v47;
                    v48 = box->mMax.z;
                    if ( v48 <= v43 )
                      v48 = v43;
                    box->mMax.z = v48;
                    v49 = box->mMin.x;
                    v50 = v39->x * x;
                    v51 = v39->y * x;
                    v52 = (float)(v34 + v39->z) * x;
                    if ( box->mMin.x >= v50 )
                      v49 = v39->x * x;
                    box->mMin.x = v49;
                    v53 = box->mMin.y;
                    if ( v53 >= v51 )
                      v53 = v51;
                    box->mMin.y = v53;
                    v54 = box->mMin.z;
                    if ( v54 >= v52 )
                      v54 = v52;
                    box->mMin.z = v54;
                    v55 = box->mMax.x;
                    if ( v55 <= v50 )
                      v55 = v50;
                    box->mMax.x = v55;
                    v56 = box->mMax.y;
                    if ( v56 <= v51 )
                      v56 = v51;
                    box->mMax.y = v56;
                    v57 = box->mMax.z;
                    if ( v57 <= v52 )
                      v57 = v52;
                    ++v36;
                    box->mMax.z = v57;
                  }
                  while ( v36 < mNumElements );
                }
              }
            }
            else
            {
              UFG::qPropertySet::Get<float>(v12, (UFG::qArray<unsigned long,0> *)&UFG::symRadius, DEPTH_RECURSE);
              UFG::qPropertySet::Get<float>(v12, (UFG::qArray<unsigned long,0> *)&UFG::symExtentAbove, DEPTH_RECURSE);
              UFG::qPropertySet::Get<float>(v12, (UFG::qArray<unsigned long,0> *)&UFG::symExtentBelow, DEPTH_RECURSE);
            }
          }
          else
          {
            v75[0] = (__int64)UFG::qPropertySet::Get<UFG::qVector3>(
                                v12,
                                (UFG::qArray<unsigned long,0> *)&UFG::symMin,
                                DEPTH_RECURSE);
            v58 = UFG::qPropertySet::Get<UFG::qVector3>(
                    v12,
                    (UFG::qArray<unsigned long,0> *)&UFG::symMax,
                    DEPTH_RECURSE);
            v59 = 0i64;
            v75[1] = (__int64)v58;
            v60 = 8i64;
            do
            {
              v61 = v16 + (float)(*(float *)v75[v59 & 1] * x);
              v62 = y + (float)(*(float *)(v75[(v59 >> 1) & 1] + 4) * x);
              v63 = box->mMin.x;
              v64 = z + (float)(*(float *)(v75[(v59 >> 2) & 1] + 8) * x);
              if ( box->mMin.x >= v61 )
                v63 = v16 + (float)(*(float *)v75[v59 & 1] * x);
              box->mMin.x = v63;
              v65 = box->mMin.y;
              if ( v65 >= v62 )
                v65 = v62;
              box->mMin.y = v65;
              v66 = box->mMin.z;
              if ( v66 >= v64 )
                v66 = v64;
              box->mMin.z = v66;
              v67 = box->mMax.x;
              if ( v67 <= v61 )
                v67 = v61;
              box->mMax.x = v67;
              v68 = box->mMax.y;
              if ( v68 <= v62 )
                v68 = v62;
              box->mMax.y = v68;
              v69 = box->mMax.z;
              if ( v69 <= v64 )
                v69 = v64;
              ++v59;
              box->mMax.z = v69;
              --v60;
            }
            while ( v60 );
          }
          goto LABEL_62;
        }
        v70 = UFG::qPropertySet::Get<float>(v12, (UFG::qArray<unsigned long,0> *)&UFG::symRadius, DEPTH_RECURSE);
        if ( v70 )
        {
          v71 = *v70;
          UFG::qBox::Enclose(box, &pos);
          v72 = (UFG::qVector3 *)v74;
          *(float *)v74 = v16 + v71;
          *(float *)&v74[1] = y + v71;
          *(float *)&v74[2] = z + v71;
LABEL_61:
          UFG::qBox::Enclose(box, v72);
        }
      }
LABEL_62:
      if ( !--v5 )
        return;
    }
    v72 = &v88;
    goto LABEL_61;
  }
}

