// File Line: 52
// RVA: 0x1475540
__int64 UFG::_dynamic_initializer_for__sCircleCombat__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("CircleCombat", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&sCircleCombat, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sCircleCombat__);
}

// File Line: 53
// RVA: 0x1475580
__int64 UFG::_dynamic_initializer_for__sSimObjChildren___0()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("SimObjChildren", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&sSimObjChildren_0, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sSimObjChildren___0);
}

// File Line: 80
// RVA: 0x1475440
__int64 UFG::_dynamic_initializer_for__gSceneLayerInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    (UFG::qResourceInventory *)&UFG::gSceneLayerInventory.vfptr,
    "SceneLayerInventory",
    0xE0F4D9CC,
    0xE7F23AEE,
    0,
    0);
  UFG::gSceneLayerInventory.vfptr = (UFG::qResourceInventoryVtbl *)&UFG::SceneLayerInventory::`vftable';
  UFG::gSceneLayerInventory.mPurgedScriptUIDs.p = 0i64;
  *(_QWORD *)&UFG::gSceneLayerInventory.mPurgedScriptUIDs.size = 0i64;
  return atexit(UFG::_dynamic_atexit_destructor_for__gSceneLayerInventory__);
}

// File Line: 88
// RVA: 0x243900
void __fastcall UFG::SceneLayerInventory::PrintContents(UFG::SceneLayerInventory *this)
{
  UFG::SceneLayerInventory *v1; // rdi
  UFG::qBaseTreeRB *i; // rbx

  v1 = this;
  UFG::qPrintf("Contents of Inventory '%.64s' %d items\n", this->mName, this->mNumResourceData);
  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v1->mResourceDatas);
        i;
        i = UFG::qBaseTreeRB::GetNext(&v1->mResourceDatas.mTree, &i->mRoot) )
  {
    UFG::qPrintf(
      "  - Resource TypeUID:0x%08x DataUID:0x%08x Memory:0x%08x Name:'%.36s'\n",
      LODWORD(i->mNULL.mChild[1]),
      i->mRoot.mUID,
      i,
      (char *)&i->mNULL.mChild[1] + 4);
  }
}

// File Line: 102
// RVA: 0x239C30
void __fastcall UFG::SceneLayerInventory::Add(UFG::SceneLayerInventory *this, UFG::qResourceData *resource_data)
{
  UFG::SceneLayerResource *v2; // rbx
  UFG::SceneLayerInventory *v3; // rdi
  char v4; // r10
  int v5; // er9
  __int64 v6; // r8
  unsigned int v7; // edx
  unsigned int *v8; // rcx
  void (__fastcall *v9)(UFG::SceneLayerResource *); // rax

  v2 = (UFG::SceneLayerResource *)resource_data;
  v3 = this;
  v4 = (_QWORD)resource_data[1].mNode.mChild[1] & 1;
  if ( !v4 )
    goto LABEL_8;
  v5 = (int)resource_data[1].mResourceHandles.mNode.mNext;
  v6 = 0i64;
  v7 = this->mPurgedScriptUIDs.size;
  if ( !v7 )
    goto LABEL_8;
  v8 = this->mPurgedScriptUIDs.p;
  while ( v5 != v8[v6] )
  {
    v6 = (unsigned int)(v6 + 1);
    if ( (unsigned int)v6 >= v7 )
      goto LABEL_8;
  }
  if ( (_DWORD)v6 == -1 )
  {
LABEL_8:
    if ( v4 )
      UFG::SceneLayerResource::SceneLayerResource(v2);
    UFG::qResourceInventory::Add((UFG::qResourceInventory *)&v3->vfptr, (UFG::qResourceData *)&v2->mNode);
    v2->mFlags |= 2u;
    v9 = v3->m_onSceneLayerResourceLoadedCallback;
    if ( v9 )
      v9(v2);
  }
}

// File Line: 125
// RVA: 0x245020
void __fastcall UFG::SceneLayerInventory::Remove(UFG::SceneLayerInventory *this, UFG::qResourceData *resource_data)
{
  UFG::SceneLayerResource *v2; // rbx
  UFG::SceneLayerInventory *v3; // rdi
  void (__fastcall *v4)(UFG::SceneLayerResource *); // rax

  v2 = (UFG::SceneLayerResource *)resource_data;
  v3 = this;
  if ( (_QWORD)resource_data[1].mNode.mChild[1] & 2 )
  {
    UFG::qResourceInventory::Remove((UFG::qResourceInventory *)&this->vfptr, resource_data);
    v2->mFlags &= 0xFFFFFFFD;
    v4 = v3->m_onSceneLayerResourceUnloadedCallback;
    if ( v4 )
      v4(v2);
    if ( v2->mFlags & 1 )
      UFG::SceneLayerResource::~SceneLayerResource(v2);
  }
}

// File Line: 189
// RVA: 0x237900
void __fastcall UFG::SceneLayerResource::SceneLayerResource(UFG::SceneLayerResource *this)
{
  UFG::SceneLayerResource *v1; // rsi
  UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource> *v2; // rax
  UFG::qPropertySet *v3; // rbx
  unsigned int v4; // edi
  __int64 v5; // rax
  signed __int64 v6; // rcx
  _QWORD *v7; // rdx
  UFG::qPropertySet *v8; // rcx
  __int64 v9; // rax
  __int64 v10; // rax
  UFG::qList<UFG::SceneObjectProperties,UFG::SceneObjectProperties,0,0> *v11; // [rsp+58h] [rbp+10h]

  v1 = this;
  UFG::qResourceData::qResourceData((UFG::qResourceData *)&this->mNode);
  v2 = (UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource> *)&v1->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  v11 = &v1->mObjects;
  v11->mNode.mPrev = &v11->mNode;
  v11->mNode.mNext = &v11->mNode;
  v3 = 0i64;
  v4 = 0;
  if ( v1->mPropertySetCount )
  {
    do
    {
      v5 = v1->mPropertySets.mOffset;
      if ( v5 )
        v6 = (signed __int64)&v1->mPropertySets + v5;
      else
        v6 = 0i64;
      v7 = (_QWORD *)(v6 + 8i64 * v4);
      if ( *v7 )
        v8 = (UFG::qPropertySet *)((char *)v7 + *v7);
      else
        v8 = 0i64;
      if ( v8 )
        UFG::qPropertySet::qPropertySet(v8);
      ++v4;
    }
    while ( v4 < v1->mPropertySetCount );
  }
  v9 = v1->mGeoInfoPropSet.mOffset;
  if ( v9 && (UFG::qOffset64<UFG::qPropertySet *> *)((char *)&v1->mGeoInfoPropSet + v9) )
  {
    v10 = v1->mGeoInfoPropSet.mOffset;
    if ( v10 )
      v3 = (UFG::qPropertySet *)((char *)&v1->mGeoInfoPropSet + v10);
    if ( v3 )
      UFG::qPropertySet::qPropertySet(v3);
  }
}

// File Line: 208
// RVA: 0x2379E0
void __fastcall UFG::SceneLayerResource::SceneLayerResource(UFG::SceneLayerResource *this, const char *layer_name)
{
  const char *v2; // rdi
  UFG::SceneLayerResource *v3; // rsi
  unsigned int v4; // eax
  UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource> *v5; // rax
  UFG::qList<UFG::SceneObjectProperties,UFG::SceneObjectProperties,0,0> *v6; // rax
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  unsigned int v11; // edx
  UFG::qSymbol *v12; // rax
  UFG::qPropertySet *v13; // rbx
  UFG::qList<UFG::SceneObjectProperties,UFG::SceneObjectProperties,0,0> *result; // [rsp+60h] [rbp+18h]
  UFG::qSymbol v15; // [rsp+68h] [rbp+20h]

  v2 = layer_name;
  v3 = this;
  v4 = UFG::qStringHash32(layer_name, 0xFFFFFFFF);
  UFG::qResourceData::qResourceData((UFG::qResourceData *)&v3->mNode, 0xE0F4D9CC, v4, v2);
  v5 = (UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource> *)&v3->mPrev;
  v5->mPrev = v5;
  v5->mNext = v5;
  v6 = &v3->mObjects;
  result = v6;
  v6->mNode.mPrev = &v6->mNode;
  v6->mNode.mNext = &v6->mNode;
  *(_QWORD *)&v3->mFlags = 0i64;
  v3->mPropertySets.mOffset = 0i64;
  v3->mGeoInfoPropSet.mOffset = 0i64;
  v7 = UFG::qVector3::msZero.y;
  v8 = UFG::qVector3::msZero.z;
  v3->mAABBMin.x = UFG::qVector3::msZero.x;
  v3->mAABBMin.y = v7;
  v3->mAABBMin.z = v8;
  v9 = UFG::qVector3::msZero.y;
  v10 = UFG::qVector3::msZero.z;
  v3->mAABBMax.x = UFG::qVector3::msZero.x;
  v3->mAABBMax.y = v9;
  v3->mAABBMax.z = v10;
  v3->mpRuntimeSceneLayer = 0i64;
  v11 = v3->mNode.mUID;
  v3->mScriptUID = v11;
  v3->mSourceCRC = -1;
  v12 = (UFG::qSymbol *)UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&result, v11);
  v13 = UFG::qPropertySet::CreateContainedSet(v12, "geo_info_prop_set");
  v13->mSchemaName = (UFG::qSymbol)UFG::qSymbol::create_from_string(&v15, "default-schema-scenelayer")->mUID;
  UFG::PropertySetManager::SetupSchemaSet(v13, &v13->mSchemaName);
  UFG::SceneLayerResource::SetGeoInfoPropertySet(v3, v13);
  _((AMD_HD3D *)v3->mNode.mUID);
}

// File Line: 231
// RVA: 0x238480
void __fastcall UFG::SceneLayerResource::~SceneLayerResource(UFG::SceneLayerResource *this)
{
  UFG::SceneLayerResource *v1; // rdi
  UFG::qPropertySet *v2; // rbx
  unsigned int v3; // esi
  __int64 v4; // rax
  signed __int64 v5; // rcx
  _QWORD *v6; // rdx
  UFG::qPropertySet *v7; // rcx
  __int64 v8; // rax
  __int64 v9; // rax
  unsigned int v10; // esi
  __int64 v11; // rax
  signed __int64 v12; // rcx
  _QWORD *v13; // rdx
  UFG::qPropertySet *v14; // rcx
  __int64 v15; // rax
  __int64 v16; // rax
  char *v17; // rdx
  __int64 v18; // rax
  __int64 v19; // rax
  UFG::qPropertySet *v20; // rcx
  AMD_HD3D *v21; // rcx
  UFG::qList<UFG::SceneObjectProperties,UFG::SceneObjectProperties,0,0> *v22; // r8
  signed __int64 i; // rax
  _QWORD *v24; // rdx
  __int64 v25; // rcx
  _QWORD *v26; // rax
  UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties> *v27; // rcx
  UFG::qNode<UFG::SceneObjectProperties,UFG::SceneObjectProperties> *v28; // rax
  UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource> *v29; // rdx
  UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource> *v30; // rcx
  UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource> *v31; // rax
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *v32; // rdi
  UFG::qResourceHandle *j; // rbx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v34; // rdx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v35; // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v36; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v37; // rax

  v1 = this;
  if ( this->mFlags & 1 )
  {
    v2 = 0i64;
    v3 = 0;
    if ( this->mPropertySetCount )
    {
      do
      {
        v4 = v1->mPropertySets.mOffset;
        if ( v4 )
          v5 = (signed __int64)&v1->mPropertySets + v4;
        else
          v5 = 0i64;
        v6 = (_QWORD *)(v5 + 8i64 * v3);
        v7 = (UFG::qPropertySet *)((char *)v6 + *v6);
        if ( !*v6 )
          v7 = 0i64;
        UFG::qPropertySet::~qPropertySet(v7);
        ++v3;
      }
      while ( v3 < v1->mPropertySetCount );
    }
    v8 = v1->mGeoInfoPropSet.mOffset;
    if ( v8 && (UFG::qOffset64<UFG::qPropertySet *> *)((char *)&v1->mGeoInfoPropSet + v8) )
    {
      v9 = v1->mGeoInfoPropSet.mOffset;
      if ( v9 )
        v2 = (UFG::qPropertySet *)((char *)&v1->mGeoInfoPropSet + v9);
      UFG::qPropertySet::~qPropertySet(v2);
    }
  }
  else
  {
    UFG::SceneLayerInventory::Remove(&UFG::gSceneLayerInventory, (UFG::qResourceData *)&this->mNode);
    v10 = 0;
    if ( v1->mPropertySetCount )
    {
      do
      {
        v11 = v1->mPropertySets.mOffset;
        if ( v11 )
          v12 = (signed __int64)&v1->mPropertySets + v11;
        else
          v12 = 0i64;
        v13 = (_QWORD *)(v12 + 8i64 * v10);
        v14 = (UFG::qPropertySet *)((char *)v13 + *v13);
        if ( !*v13 )
          v14 = 0i64;
        UFG::qPropertySet::ReleaseRef(v14);
        ++v10;
      }
      while ( v10 < v1->mPropertySetCount );
    }
    v15 = v1->mPropertySets.mOffset;
    if ( v15 && (UFG::qOffset64<UFG::qOffset64<UFG::qPropertySet *> *> *)((char *)&v1->mPropertySets + v15) )
    {
      v16 = v1->mPropertySets.mOffset;
      if ( v16 )
        v17 = (char *)&v1->mPropertySets + v16;
      else
        v17 = 0i64;
      UFG::qMemoryPool::Free(&gPropertySetMemoryPool, v17);
      v1->mPropertySets.mOffset = 0i64;
    }
    v18 = v1->mGeoInfoPropSet.mOffset;
    if ( v18 && (UFG::qOffset64<UFG::qPropertySet *> *)((char *)&v1->mGeoInfoPropSet + v18) )
    {
      v19 = v1->mGeoInfoPropSet.mOffset;
      if ( v19 )
        v20 = (UFG::qPropertySet *)((char *)&v1->mGeoInfoPropSet + v19);
      else
        v20 = 0i64;
      UFG::qPropertySet::ReleaseRef(v20);
      v1->mGeoInfoPropSet.mOffset = 0i64;
    }
    v21 = (AMD_HD3D *)v1->mNode.mUID;
    if ( (_DWORD)v21 != -275271401 )
      _(v21);
  }
  v22 = &v1->mObjects;
  for ( i = (signed __int64)&v1->mObjects.mNode.mNext[-4];
        (char *)i != &v1->mDebugName[28];
        i = (signed __int64)&v1->mObjects.mNode.mNext[-4] )
  {
    v24 = (_QWORD *)(i + 64);
    v25 = *(_QWORD *)(i + 64);
    v26 = *(_QWORD **)(i + 72);
    *(_QWORD *)(v25 + 8) = v26;
    *v26 = v25;
    *v24 = v24;
    v24[1] = v24;
  }
  v27 = v22->mNode.mPrev;
  v28 = v1->mObjects.mNode.mNext;
  v27->mNext = v28;
  v28->mPrev = v27;
  v22->mNode.mPrev = &v22->mNode;
  v1->mObjects.mNode.mNext = &v1->mObjects.mNode;
  v29 = (UFG::qNode<UFG::SceneLayerResource,UFG::SceneLayerResource> *)&v1->mPrev;
  v30 = v1->mPrev;
  v31 = v1->mNext;
  v30->mNext = v31;
  v31->mPrev = v30;
  v29->mPrev = v29;
  v29->mNext = v29;
  v32 = &v1->mResourceHandles;
  for ( j = (UFG::qResourceHandle *)v32->mNode.mNext;
        j != (UFG::qResourceHandle *)v32;
        j = (UFG::qResourceHandle *)v32->mNode.mNext )
  {
    v34 = j->mPrev;
    v35 = j->mNext;
    v34->mNext = v35;
    v35->mPrev = v34;
    j->mPrev = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)&j->mPrev;
    j->mNext = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)&j->mPrev;
    UFG::qResourceHandle::~qResourceHandle(j);
    operator delete[](j);
  }
  v36 = v32->mNode.mPrev;
  v37 = v32->mNode.mNext;
  v36->mNext = v37;
  v37->mPrev = v36;
  v32->mNode.mPrev = &v32->mNode;
  v32->mNode.mNext = &v32->mNode;
}

// File Line: 282
// RVA: 0x23EE30
bool __fastcall UFG::SceneLayerResource::IsGeoInFrustrum(UFG::SceneLayerResource *this)
{
  UFG::SceneLayerResource *v1; // r14
  UFG::BaseCameraComponent *v2; // rdx
  UFG::Camera *v3; // rdi
  UFG::qMatrix44 *v4; // rbx
  UFG::qMatrix44 *v5; // rax
  int v6; // xmm6_4
  float v7; // xmm12_4
  float v8; // ST3C_4
  float v9; // ST40_4
  float v10; // xmm11_4
  float v11; // xmm10_4
  float v12; // xmm13_4
  float v13; // xmm14_4
  float v14; // xmm15_4
  float v15; // ST24_4
  float v16; // ST30_4
  float v17; // ST2C_4
  float v18; // xmm0_4
  float v19; // xmm0_4
  float v20; // xmm0_4
  __m128 v21; // xmm2
  float v22; // xmm0_4
  __m128 v23; // xmm2
  float v24; // xmm0_4
  float v25; // xmm5_4
  __m128 v26; // xmm2
  float v27; // xmm0_4
  UFG::qMatrix44 result; // [rsp+50h] [rbp-88h]
  float v30; // [rsp+90h] [rbp-48h]
  float v31; // [rsp+94h] [rbp-44h]
  float v32; // [rsp+98h] [rbp-40h]
  float v33; // [rsp+9Ch] [rbp-3Ch]
  float v34; // [rsp+A0h] [rbp-38h]
  float v35; // [rsp+A4h] [rbp-34h]
  float v36; // [rsp+A8h] [rbp-30h]
  float v37; // [rsp+ACh] [rbp-2Ch]
  float v38; // [rsp+B0h] [rbp-28h]
  float v39; // [rsp+B4h] [rbp-24h]
  float v40; // [rsp+B8h] [rbp-20h]
  float v41; // [rsp+BCh] [rbp-1Ch]
  float v42; // [rsp+C0h] [rbp-18h]
  float v43; // [rsp+C4h] [rbp-14h]
  float centre_distance_to_nearplan; // [rsp+198h] [rbp+C0h]
  float v45; // [rsp+1A0h] [rbp+C8h]
  float v46; // [rsp+1A8h] [rbp+D0h]
  float vars0; // [rsp+1B0h] [rbp+D8h]

  v1 = this;
  v2 = UFG::Director::Get()->mCurrentCamera;
  v3 = &v2->mCamera;
  if ( !v2 )
    v3 = 0i64;
  v4 = UFG::Camera::GetViewProjection(v3);
  v5 = UFG::Camera::GetWorldView(v3);
  UFG::qMatrix44::operator*(v5, &result, v4);
  v6 = LODWORD(result.v1.z) ^ _xmm[0];
  LODWORD(v7) = COERCE_UNSIGNED_INT(result.v0.x + result.v0.w) ^ _xmm[0];
  LODWORD(v8) = COERCE_UNSIGNED_INT(result.v2.w - result.v2.y) ^ _xmm[0];
  LODWORD(v9) = COERCE_UNSIGNED_INT(result.v1.w - result.v1.y) ^ _xmm[0];
  LODWORD(v10) = COERCE_UNSIGNED_INT(result.v1.x + result.v1.w) ^ _xmm[0];
  LODWORD(v11) = COERCE_UNSIGNED_INT(result.v2.x + result.v2.w) ^ _xmm[0];
  LODWORD(v45) = COERCE_UNSIGNED_INT(result.v0.y + result.v0.w) ^ _xmm[0];
  LODWORD(centre_distance_to_nearplan) = COERCE_UNSIGNED_INT(result.v1.y + result.v1.w) ^ _xmm[0];
  LODWORD(v12) = COERCE_UNSIGNED_INT(result.v0.w - result.v0.x) ^ _xmm[0];
  LODWORD(v13) = COERCE_UNSIGNED_INT(result.v1.w - result.v1.x) ^ _xmm[0];
  LODWORD(v46) = COERCE_UNSIGNED_INT(result.v2.y + result.v2.w) ^ _xmm[0];
  LODWORD(v14) = COERCE_UNSIGNED_INT(result.v2.w - result.v2.x) ^ _xmm[0];
  LODWORD(vars0) = COERCE_UNSIGNED_INT(result.v0.w + result.v1.y) ^ _xmm[0];
  LODWORD(v15) = COERCE_UNSIGNED_INT(result.v0.w - result.v0.y) ^ _xmm[0];
  LODWORD(v16) = COERCE_UNSIGNED_INT(result.v1.w - result.v1.z) ^ _xmm[0];
  LODWORD(v17) = COERCE_UNSIGNED_INT(result.v2.w - result.v2.z) ^ _xmm[0];
  v18 = fsqrt(
          (float)((float)(*(float *)&v6 * *(float *)&v6)
                + (float)(COERCE_FLOAT(LODWORD(result.v0.z) ^ _xmm[0]) * COERCE_FLOAT(LODWORD(result.v0.z) ^ _xmm[0])))
        + (float)(COERCE_FLOAT(LODWORD(result.v2.z) ^ _xmm[0]) * COERCE_FLOAT(LODWORD(result.v2.z) ^ _xmm[0])));
  result.v2.y = (float)(1.0 / v18) * COERCE_FLOAT(LODWORD(result.v1.x) ^ _xmm[0]);
  result.v1.z = (float)(1.0 / v18) * COERCE_FLOAT(LODWORD(result.v0.z) ^ _xmm[0]);
  result.v2.x = (float)(1.0 / v18) * COERCE_FLOAT(LODWORD(result.v2.z) ^ _xmm[0]);
  result.v1.w = (float)(1.0 / v18) * *(float *)&v6;
  v19 = fsqrt((float)((float)(v10 * v10) + (float)(v7 * v7)) + (float)(v11 * v11));
  result.v2.z = (float)(1.0 / v19) * v7;
  result.v2.w = (float)(1.0 / v19) * v10;
  result.v3.y = (float)(1.0 / v19) * COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v0.z + result.v1.y) ^ _xmm[0]);
  result.v3.x = (float)(1.0 / v19) * v11;
  v20 = fsqrt((float)((float)(v13 * v13) + (float)(v12 * v12)) + (float)(v14 * v14));
  v31 = (float)(1.0 / v20) * COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v1.y - result.v0.z) ^ _xmm[0]);
  result.v3.z = (float)(1.0 / v20) * v12;
  v30 = (float)(1.0 / v20) * v14;
  result.v3.w = (float)(1.0 / v20) * v13;
  v21 = (__m128)LODWORD(centre_distance_to_nearplan);
  v21.m128_f32[0] = (float)((float)(v21.m128_f32[0] * v21.m128_f32[0]) + (float)(v45 * v45)) + (float)(v46 * v46);
  LODWORD(v22) = (unsigned __int128)_mm_sqrt_ps(v21);
  v32 = (float)(1.0 / v22) * v45;
  v34 = (float)(1.0 / v22) * v46;
  v33 = (float)(1.0 / v22) * centre_distance_to_nearplan;
  v23 = (__m128)LODWORD(v9);
  v35 = (float)(1.0 / v22) * vars0;
  v23.m128_f32[0] = (float)((float)(v23.m128_f32[0] * v23.m128_f32[0]) + (float)(v15 * v15)) + (float)(v8 * v8);
  v24 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v23));
  v39 = v24 * COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v1.y - result.v0.w) ^ _xmm[0]);
  v36 = v24 * v15;
  v37 = v24 * v9;
  v38 = v24 * v8;
  LODWORD(v25) = COERCE_UNSIGNED_INT(result.v0.w - result.v0.z) ^ _xmm[0];
  v26 = (__m128)LODWORD(v16);
  v26.m128_f32[0] = (float)((float)(v26.m128_f32[0] * v26.m128_f32[0]) + (float)(v25 * v25)) + (float)(v17 * v17);
  v27 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v26));
  v43 = v27 * COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v1.y - result.v1.x) ^ _xmm[0]);
  v42 = v27 * v17;
  v40 = v27 * v25;
  v41 = v27 * v16;
  centre_distance_to_nearplan = 0.0;
  return (unsigned int)IntersectAABBFrustum(
                         (UFG::qVector4 *)((char *)&result.v1 + 8),
                         &v1->mAABBMin,
                         &v1->mAABBMax,
                         &centre_distance_to_nearplan) <= 1;
}

// File Line: 304
// RVA: 0x23EDB0
bool __fastcall UFG::SceneLayerResource::IsGeoClose(UFG::SceneLayerResource *this, UFG::qVector3 *testPoint, float maxDistanceSq)
{
  float v3; // xmm1_4
  float v4; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v9; // [rsp+20h] [rbp-38h]
  float v10; // [rsp+24h] [rbp-34h]
  float v11; // [rsp+28h] [rbp-30h]
  float v12; // [rsp+2Ch] [rbp-2Ch]
  float v13; // [rsp+30h] [rbp-28h]
  float v14; // [rsp+34h] [rbp-24h]

  v3 = this->mAABBMin.y;
  v9 = this->mAABBMin.x;
  v4 = this->mAABBMin.z;
  v10 = v3;
  v5 = this->mAABBMax.x;
  v11 = v4;
  v6 = this->mAABBMax.y;
  v12 = v5;
  v7 = this->mAABBMax.z;
  v13 = v6;
  v14 = v7;
  return maxDistanceSq > UFG::qBox::DistanceSqrPoint((UFG::qBox *)&v9, testPoint);
}

// File Line: 346
// RVA: 0x23BBE0
UFG::qPropertySet *__fastcall UFG::FindObjectPropertySetRecurse(UFG::qPropertySet *propertySet, UFG::qSymbol *objectName)
{
  UFG::qSymbol *v2; // rbp
  UFG::qPropertySet *result; // rax
  UFG::qPropertyList *v4; // rax
  UFG::qPropertyList *v5; // rsi
  unsigned int v6; // edi
  unsigned int v7; // ebx
  char *v8; // rax
  UFG::qPropertySet *v9; // rcx

  v2 = objectName;
  if ( propertySet->mName.mUID == objectName->mUID )
    return propertySet;
  v4 = UFG::qPropertySet::Get<UFG::qPropertyList>(propertySet, (UFG::qSymbol *)&sSimObjChildren_0.mUID, DEPTH_RECURSE);
  v5 = v4;
  if ( !v4 )
    return 0i64;
  v6 = v4->mNumElements;
  v7 = 0;
  if ( !v6 )
    return 0i64;
  while ( 1 )
  {
    v8 = UFG::qPropertyList::GetValuePtr(v5, 0x1Au, v7);
    if ( v8 && *(_QWORD *)v8 )
      v9 = (UFG::qPropertySet *)&v8[*(_QWORD *)v8];
    else
      v9 = 0i64;
    result = UFG::FindObjectPropertySetRecurse(v9, v2);
    if ( result )
      break;
    if ( ++v7 >= v6 )
      return 0i64;
  }
  return result;
}

// File Line: 370
// RVA: 0x23BB60
UFG::qPropertySet *__fastcall UFG::SceneLayerResource::FindObjectPropertySet(UFG::SceneLayerResource *this, UFG::qSymbol *objectName)
{
  __int64 v2; // rax
  UFG::qSymbol *v3; // rbp
  UFG::SceneLayerResource *v4; // rdi
  char *v5; // rsi
  __int64 v6; // rbx
  __int64 v7; // rax
  UFG::qPropertySet *v8; // rcx
  UFG::qPropertySet *result; // rax

  v2 = this->mPropertySets.mOffset;
  v3 = objectName;
  v4 = this;
  if ( !v2 )
    return 0i64;
  v5 = (char *)&this->mPropertySets + v2;
  if ( !v5 )
    return 0i64;
  v6 = 0i64;
  if ( !this->mPropertySetCount )
    return 0i64;
  while ( 1 )
  {
    v7 = *(_QWORD *)&v5[8 * v6];
    v8 = (UFG::qPropertySet *)(v7 ? &v5[8 * v6 + v7] : 0i64);
    result = UFG::FindObjectPropertySetRecurse(v8, v3);
    if ( result )
      break;
    v6 = (unsigned int)(v6 + 1);
    if ( (unsigned int)v6 >= v4->mPropertySetCount )
      return 0i64;
  }
  return result;
}

// File Line: 387
// RVA: 0x239CD0
void __fastcall UFG::SceneLayerResource::AddPropertySet(UFG::SceneLayerResource *this, UFG::qPropertySet *property_set)
{
  __int64 v2; // r10
  UFG::qOffset64<UFG::qOffset64<UFG::qPropertySet *> *> *v3; // r14
  UFG::qPropertySet *v4; // rbx
  UFG::SceneLayerResource *v5; // r13
  char *v6; // r9
  unsigned int v7; // edx
  __int64 v8; // r8
  UFG::qPropertySet *v9; // rax
  __int64 v10; // rsi
  __int64 *v11; // rbp
  UFG::allocator::free_link *v12; // rax
  UFG::allocator::free_link *v13; // rdi
  __int64 *v14; // rcx
  __int64 v15; // r9
  signed __int64 v16; // r8
  __int64 v17; // rdx
  signed __int64 v18; // rax
  char *v19; // rdx
  signed __int64 v20; // rax

  v2 = this->mPropertySets.mOffset;
  v3 = &this->mPropertySets;
  v4 = property_set;
  v5 = this;
  if ( !v2 )
    goto LABEL_10;
  v6 = (char *)v3 + v2;
  if ( !(UFG::qOffset64<UFG::qOffset64<UFG::qPropertySet *> *> *)((char *)v3 + v2) )
    goto LABEL_10;
  v7 = this->mPropertySetCount;
  v8 = 0i64;
  if ( !v7 )
    goto LABEL_10;
  while ( 1 )
  {
    v9 = *(UFG::qPropertySet **)&v6[8 * v8];
    if ( v9 )
      v9 = (UFG::qPropertySet *)&v6[8 * v8 + (_QWORD)v9];
    if ( v9 == v4 )
      break;
    v8 = (unsigned int)(v8 + 1);
    if ( (unsigned int)v8 >= v7 )
      goto LABEL_10;
  }
  if ( (_DWORD)v8 == -1 )
  {
LABEL_10:
    v10 = this->mPropertySetCount;
    if ( v2 )
      v11 = (__int64 *)((char *)&v3->mOffset + v2);
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
      v14 = v11;
      v15 = v10;
      v16 = (char *)v12 - (char *)v11;
      do
      {
        v17 = *v14;
        if ( *v14 && (__int64 *)((char *)v14 + v17) )
          v18 = v17 - v16;
        else
          v18 = 0i64;
        *(__int64 *)((char *)v14 + v16) = v18;
        ++v14;
        --v15;
      }
      while ( v15 );
    }
    v19 = (char *)&v13[(unsigned int)v10];
    if ( v4 )
      v20 = (char *)v4 - v19;
    else
      v20 = 0i64;
    *(_QWORD *)v19 = v20;
    if ( v11 )
      UFG::qMemoryPool::Free(&gPropertySetMemoryPool, v11);
    if ( v13 )
      v13 = (UFG::allocator::free_link *)((char *)v13 - (signed __int64)v3);
    v3->mOffset = (__int64)v13;
    v5->mPropertySetCount = v10 + 1;
    v4->mFlags &= 0xFFFFFFFu;
    v4->mFlags |= 0x20000000u;
    UFG::qPropertySet::AddRef(v4);
  }
}

// File Line: 426
// RVA: 0x2450F0
char __fastcall UFG::SceneLayerResource::RemovePropertySet(UFG::SceneLayerResource *this, UFG::qPropertySet *property_set)
{
  __int64 v2; // rax
  UFG::qOffset64<UFG::qOffset64<UFG::qPropertySet *> *> *v3; // r15
  UFG::qPropertySet *v4; // r14
  UFG::SceneLayerResource *v5; // r13
  char *v6; // rdi
  signed __int64 v7; // rsi
  __int64 v8; // rbx
  UFG::qPropertySet *v9; // rax
  UFG::allocator::free_link *v11; // rax
  __int64 v12; // r9
  UFG::allocator::free_link *v13; // rbp
  __int64 *v14; // rcx
  signed __int64 v15; // r8
  __int64 v16; // rdx
  signed __int64 v17; // rax
  int v18; // eax
  char *v19; // rcx
  signed __int64 v20; // r8
  signed __int64 v21; // rdx
  signed __int64 v22; // rax

  v2 = this->mPropertySets.mOffset;
  v3 = &this->mPropertySets;
  v4 = property_set;
  v5 = this;
  if ( !v2 )
    return 0;
  v6 = (char *)v3 + v2;
  if ( !(UFG::qOffset64<UFG::qOffset64<UFG::qPropertySet *> *> *)((char *)v3 + v2) )
    return 0;
  v7 = (signed int)this->mPropertySetCount;
  v8 = 0i64;
  if ( !(_DWORD)v7 )
    return 0;
  while ( 1 )
  {
    v9 = *(UFG::qPropertySet **)&v6[8 * v8];
    if ( v9 )
      v9 = (UFG::qPropertySet *)&v6[8 * v8 + (_QWORD)v9];
    if ( v9 == property_set )
      break;
    v8 = (unsigned int)(v8 + 1);
    if ( (unsigned int)v8 >= (unsigned int)v7 )
      return 0;
  }
  if ( (_DWORD)v8 == -1 )
    return 0;
  v11 = UFG::qMemoryPool::Allocate(&gPropertySetMemoryPool, (unsigned int)(8 * (v7 - 1)), "PropertySetList", 0i64, 1u);
  v12 = (signed int)v8;
  v13 = v11;
  if ( (signed int)v8 > 0 )
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
      *(__int64 *)((char *)v14 + v15) = v17;
      ++v14;
      --v12;
    }
    while ( v12 );
  }
  v18 = v8 + 1;
  if ( (signed int)v8 + 1 < v7 )
  {
    v19 = &v6[8 * v18];
    v20 = (char *)v13 - v6 - 8;
    v21 = v7 - v18;
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
    v13 = (UFG::allocator::free_link *)((char *)v13 - (signed __int64)v3);
  v3->mOffset = (__int64)v13;
  v5->mPropertySetCount = v7 - 1;
  v4->mFlags &= 0xFFFFFFFu;
  UFG::qPropertySet::ReleaseRef(v4);
  return 1;
}

// File Line: 477
// RVA: 0x2454D0
void __fastcall UFG::SceneLayerResource::SetGeoInfoPropertySet(UFG::SceneLayerResource *this, UFG::qPropertySet *property_set)
{
  __int64 v2; // rax
  UFG::qOffset64<UFG::qPropertySet *> *v3; // rsi
  signed __int64 v4; // rdi
  UFG::qPropertySet *v5; // rcx
  UFG::qPropertySet *v6; // rbx

  v2 = this->mGeoInfoPropSet.mOffset;
  v3 = &this->mGeoInfoPropSet;
  v4 = 0i64;
  v5 = (UFG::qPropertySet *)((char *)&this->mGeoInfoPropSet + v2);
  v6 = property_set;
  if ( !v2 )
    v5 = 0i64;
  if ( property_set != v5 )
  {
    if ( v5 )
    {
      v5->mFlags &= 0xFFFFFFFu;
      UFG::qPropertySet::ReleaseRef(v5);
    }
    if ( v6 )
      v4 = (char *)v6 - (char *)v3;
    v3->mOffset = v4;
    UFG::qPropertySet::AddRef(v6);
    v6->mFlags = v6->mFlags & 0xFFFFFFF | 0x30000000;
  }
}

// File Line: 853
// RVA: 0x23D970
UFG::qPropertySet *__fastcall UFG::SceneLayerResource::GetNamedPropertySet(UFG::SceneLayerResource *this, UFG::qSymbol *name)
{
  __int64 v2; // rax
  __int64 *v3; // rax
  unsigned int v4; // er9
  unsigned int v5; // er8
  unsigned int v6; // edx
  __int64 v7; // rcx

  v2 = this->mPropertySets.mOffset;
  if ( !v2 )
    return 0i64;
  v3 = (__int64 *)((char *)&this->mPropertySets.mOffset + v2);
  if ( !v3 )
    return 0i64;
  v4 = this->mPropertySetCount;
  v5 = 0;
  if ( !v4 )
    return 0i64;
  v6 = name->mUID;
  while ( 1 )
  {
    v7 = *v3;
    if ( *v3 )
      v7 += (__int64)v3;
    if ( *(_DWORD *)(v7 + 64) == v6 )
      break;
    ++v5;
    ++v3;
    if ( v5 >= v4 )
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
  return atexit(UFG::_dynamic_atexit_destructor_for__symComponentRegion__);
}

// File Line: 871
// RVA: 0x1475920
__int64 UFG::_dynamic_initializer_for__symXformLocal__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("XformLocal", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symXformLocal, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__symXformLocal__);
}

// File Line: 872
// RVA: 0x1475960
__int64 UFG::_dynamic_initializer_for__symXformLocalQuat__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("XformLocalQuat", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symXformLocalQuat, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__symXformLocalQuat__);
}

// File Line: 873
// RVA: 0x14758A0
__int64 UFG::_dynamic_initializer_for__symType__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Type", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symType, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__symType__);
}

// File Line: 874
// RVA: 0x1475820
__int64 UFG::_dynamic_initializer_for__symMin__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Min", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symMin, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__symMin__);
}

// File Line: 875
// RVA: 0x14757E0
__int64 UFG::_dynamic_initializer_for__symMax__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Max", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symMax, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__symMax__);
}

// File Line: 876
// RVA: 0x1475860
__int64 UFG::_dynamic_initializer_for__symRadius__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Radius", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symRadius, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__symRadius__);
}

// File Line: 877
// RVA: 0x1475760
__int64 UFG::_dynamic_initializer_for__symExtentAbove__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("ExtentAbove", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symExtentAbove, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__symExtentAbove__);
}

// File Line: 878
// RVA: 0x14757A0
__int64 UFG::_dynamic_initializer_for__symExtentBelow__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("ExtentBelow", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symExtentBelow, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__symExtentBelow__);
}

// File Line: 879
// RVA: 0x14758E0
__int64 UFG::_dynamic_initializer_for__symVertexes__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Vertexes", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symVertexes, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__symVertexes__);
}

// File Line: 882
// RVA: 0x2393A0
void __fastcall UFG::SceneLayerResource::AccumulateBounds(UFG::SceneLayerResource *this, UFG::qBox *box)
{
  unsigned int v2; // eax
  UFG::qBox *v3; // rdi
  UFG::SceneLayerResource *v4; // r13
  __int64 v5; // r12
  __int64 v6; // r15
  __int64 v7; // rax
  signed __int64 v8; // rcx
  signed __int64 v9; // rax
  __int64 v10; // rcx
  UFG::qPropertySet *v11; // rbx
  UFG::qPropertySet *v12; // rsi
  UFG::qMatrix44 *v13; // rax
  int v14; // xmm1_4
  float v15; // xmm6_4
  float v16; // xmm7_4
  float v17; // xmm8_4
  float v18; // xmm9_4
  int v19; // xmm0_4
  int v20; // xmm1_4
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
  unsigned int v37; // esi
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
  signed __int64 v60; // rdx
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
  UFG::qVector3 pos; // [rsp+8h] [rbp-79h]
  float v74; // [rsp+14h] [rbp-6Dh]
  float v75; // [rsp+18h] [rbp-69h]
  float v76; // [rsp+1Ch] [rbp-65h]
  UFG::qVector3 *v77; // [rsp+20h] [rbp-61h]
  UFG::qVector3 *v78; // [rsp+28h] [rbp-59h]
  float v79; // [rsp+38h] [rbp-49h]
  float v80; // [rsp+3Ch] [rbp-45h]
  int v81; // [rsp+40h] [rbp-41h]
  int v82; // [rsp+44h] [rbp-3Dh]
  int v83; // [rsp+48h] [rbp-39h]
  float v84; // [rsp+4Ch] [rbp-35h]
  int v85; // [rsp+50h] [rbp-31h]
  int v86; // [rsp+54h] [rbp-2Dh]
  int v87; // [rsp+58h] [rbp-29h]
  float v88; // [rsp+5Ch] [rbp-25h]
  int v89; // [rsp+60h] [rbp-21h]
  int v90; // [rsp+64h] [rbp-1Dh]
  UFG::qVector3 v91; // [rsp+68h] [rbp-19h]
  int v92; // [rsp+74h] [rbp-Dh]

  v2 = this->mPropertySetCount;
  v3 = box;
  v4 = this;
  if ( v2 )
  {
    v5 = v2;
    v6 = 0i64;
    while ( 1 )
    {
      v7 = v4->mPropertySets.mOffset;
      v8 = (signed __int64)(v7 ? (UFG::qOffset64<UFG::qOffset64<UFG::qPropertySet *> *> *)((char *)&v4->mPropertySets
                                                                                         + v7) : 0i64);
      v9 = v8 + v6;
      v10 = *(_QWORD *)(v8 + v6);
      v11 = (UFG::qPropertySet *)(v10 ? v10 + v9 : 0i64);
      v12 = UFG::qPropertySet::Get<UFG::qPropertySet>(v11, (UFG::qSymbol *)&UFG::symComponentRegion.mUID, DEPTH_RECURSE);
      v13 = UFG::qPropertySet::Get<UFG::qMatrix44>(v11, (UFG::qSymbol *)&UFG::symXformLocal.mUID, DEPTH_RECURSE);
      v14 = LODWORD(v13->v0.z);
      v15 = v13->v0.x;
      v16 = v13->v3.x;
      v17 = v13->v3.y;
      v18 = v13->v3.z;
      v80 = v13->v0.y;
      v19 = LODWORD(v13->v0.w);
      v81 = v14;
      v20 = LODWORD(v13->v1.x);
      v82 = v19;
      v84 = v13->v1.y;
      v21 = LODWORD(v13->v1.w);
      v83 = v20;
      v22 = LODWORD(v13->v1.z);
      v86 = v21;
      v88 = v13->v2.y;
      v23 = LODWORD(v13->v2.w);
      v85 = v22;
      v24 = LODWORD(v13->v2.x);
      v90 = v23;
      v25 = LODWORD(v13->v3.w);
      v87 = v24;
      v26 = LODWORD(v13->v2.z);
      v92 = v25;
      v79 = v15;
      v89 = v26;
      v91.x = v16;
      v91.y = v17;
      v91.z = v18;
      if ( !v12 )
        break;
      v27 = UFG::qPropertySet::Get<unsigned long>(v12, (UFG::qSymbol *)&UFG::symType.mUID, DEPTH_RECURSE);
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
                v31 = UFG::qPropertySet::Get<float>(v12, (UFG::qSymbol *)&UFG::symExtentAbove.mUID, DEPTH_RECURSE);
                v32 = UFG::qPropertySet::Get<float>(v12, (UFG::qSymbol *)&UFG::symExtentBelow.mUID, DEPTH_RECURSE);
                v33 = *v31;
                v34 = *v32;
                v35 = UFG::qPropertySet::Get<UFG::qPropertyList>(
                        v12,
                        (UFG::qSymbol *)&UFG::symVertexes.mUID,
                        DEPTH_RECURSE);
                v36 = 0;
                v37 = v35->mNumElements;
                v38 = v35;
                if ( v37 )
                {
                  do
                  {
                    v39 = UFG::qPropertyList::Get<UFG::qVector3>(v38, v36);
                    v40 = v3->mMin.x;
                    v41 = v39->x * v15;
                    v42 = v39->y * v15;
                    v43 = (float)(v33 + v39->z) * v15;
                    if ( v3->mMin.x >= v41 )
                      v40 = v39->x * v15;
                    v3->mMin.x = v40;
                    v44 = v3->mMin.y;
                    if ( v44 >= v42 )
                      v44 = v42;
                    v3->mMin.y = v44;
                    v45 = v3->mMin.z;
                    if ( v45 >= v43 )
                      v45 = v43;
                    v3->mMin.z = v45;
                    v46 = v3->mMax.x;
                    if ( v46 <= v41 )
                      v46 = v41;
                    v3->mMax.x = v46;
                    v47 = v3->mMax.y;
                    if ( v47 <= v42 )
                      v47 = v42;
                    v3->mMax.y = v47;
                    v48 = v3->mMax.z;
                    if ( v48 <= v43 )
                      v48 = v43;
                    v3->mMax.z = v48;
                    v49 = v3->mMin.x;
                    v50 = v39->x * v15;
                    v51 = v39->y * v15;
                    v52 = (float)(v34 + v39->z) * v15;
                    if ( v3->mMin.x >= v50 )
                      v49 = v39->x * v15;
                    v3->mMin.x = v49;
                    v53 = v3->mMin.y;
                    if ( v53 >= v51 )
                      v53 = v51;
                    v3->mMin.y = v53;
                    v54 = v3->mMin.z;
                    if ( v54 >= v52 )
                      v54 = v52;
                    v3->mMin.z = v54;
                    v55 = v3->mMax.x;
                    if ( v55 <= v50 )
                      v55 = v50;
                    v3->mMax.x = v55;
                    v56 = v3->mMax.y;
                    if ( v56 <= v51 )
                      v56 = v51;
                    v3->mMax.y = v56;
                    v57 = v3->mMax.z;
                    if ( v57 <= v52 )
                      v57 = v52;
                    ++v36;
                    v3->mMax.z = v57;
                  }
                  while ( v36 < v37 );
                }
              }
            }
            else
            {
              UFG::qPropertySet::Get<float>(v12, (UFG::qSymbol *)&UFG::symRadius.mUID, DEPTH_RECURSE);
              UFG::qPropertySet::Get<float>(v12, (UFG::qSymbol *)&UFG::symExtentAbove.mUID, DEPTH_RECURSE);
              UFG::qPropertySet::Get<float>(v12, (UFG::qSymbol *)&UFG::symExtentBelow.mUID, DEPTH_RECURSE);
            }
          }
          else
          {
            v77 = UFG::qPropertySet::Get<UFG::qVector3>(v12, (UFG::qSymbol *)&UFG::symMin.mUID, DEPTH_RECURSE);
            v58 = UFG::qPropertySet::Get<UFG::qVector3>(v12, (UFG::qSymbol *)&UFG::symMax.mUID, DEPTH_RECURSE);
            v59 = 0i64;
            v78 = v58;
            v60 = 8i64;
            do
            {
              v61 = v16 + (float)((*(&v77 + (v59 & 1)))->x * v15);
              v62 = v17 + (float)((*(&v77 + ((v59 >> 1) & 1)))->y * v15);
              v63 = v3->mMin.x;
              v64 = v18 + (float)((*(&v77 + ((v59 >> 2) & 1)))->z * v15);
              if ( v3->mMin.x >= v61 )
                v63 = v16 + (float)((*(&v77 + (v59 & 1)))->x * v15);
              v3->mMin.x = v63;
              v65 = v3->mMin.y;
              if ( v65 >= v62 )
                v65 = v62;
              v3->mMin.y = v65;
              v66 = v3->mMin.z;
              if ( v66 >= v64 )
                v66 = v64;
              v3->mMin.z = v66;
              v67 = v3->mMax.x;
              if ( v67 <= v61 )
                v67 = v61;
              v3->mMax.x = v67;
              v68 = v3->mMax.y;
              if ( v68 <= v62 )
                v68 = v62;
              v3->mMax.y = v68;
              v69 = v3->mMax.z;
              if ( v69 <= v64 )
                v69 = v64;
              ++v59;
              v3->mMax.z = v69;
              --v60;
            }
            while ( v60 );
          }
          goto LABEL_62;
        }
        v70 = UFG::qPropertySet::Get<float>(v12, (UFG::qSymbol *)&UFG::symRadius.mUID, DEPTH_RECURSE);
        if ( v70 )
        {
          v71 = *v70;
          UFG::qBox::Enclose(v3, &pos);
          v72 = (UFG::qVector3 *)&v74;
          v74 = v16 + v71;
          v75 = v17 + v71;
          v76 = v18 + v71;
LABEL_61:
          UFG::qBox::Enclose(v3, v72);
          goto LABEL_62;
        }
      }
LABEL_62:
      v6 += 8i64;
      if ( !--v5 )
        return;
    }
    v72 = &v91;
    goto LABEL_61;
  }
}

