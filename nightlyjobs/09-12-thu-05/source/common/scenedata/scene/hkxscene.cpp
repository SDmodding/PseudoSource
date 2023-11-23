// File Line: 14
// RVA: 0xE35C30
void __fastcall hkxScene::hkxScene(hkxScene *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkxScene::`vftable;
  hkStringPtr::hkStringPtr(&this->m_modeller);
  hkStringPtr::hkStringPtr(&this->m_asset);
  *(_QWORD *)&this->m_sceneLength = 0i64;
  this->m_rootNode.m_pntr = 0i64;
  this->m_selectionSets.m_data = 0i64;
  this->m_selectionSets.m_size = 0;
  this->m_selectionSets.m_capacityAndFlags = 0x80000000;
  this->m_cameras.m_data = 0i64;
  this->m_cameras.m_size = 0;
  this->m_cameras.m_capacityAndFlags = 0x80000000;
  this->m_lights.m_data = 0i64;
  this->m_lights.m_size = 0;
  this->m_lights.m_capacityAndFlags = 0x80000000;
  this->m_meshes.m_data = 0i64;
  this->m_meshes.m_size = 0;
  this->m_meshes.m_capacityAndFlags = 0x80000000;
  this->m_materials.m_data = 0i64;
  this->m_materials.m_size = 0;
  this->m_materials.m_capacityAndFlags = 0x80000000;
  this->m_inplaceTextures.m_data = 0i64;
  this->m_inplaceTextures.m_size = 0;
  this->m_inplaceTextures.m_capacityAndFlags = 0x80000000;
  this->m_externalTextures.m_data = 0i64;
  this->m_externalTextures.m_size = 0;
  this->m_externalTextures.m_capacityAndFlags = 0x80000000;
  this->m_skinBindings.m_data = 0i64;
  this->m_skinBindings.m_size = 0;
  this->m_skinBindings.m_capacityAndFlags = 0x80000000;
  this->m_splines.m_data = 0i64;
  this->m_splines.m_size = 0;
  this->m_splines.m_capacityAndFlags = 0x80000000;
  this->m_appliedTransform.m_col0 = (hkVector4f)transform.m_quad;
  this->m_appliedTransform.m_col1 = (hkVector4f)direction.m_quad;
  this->m_appliedTransform.m_col2 = (hkVector4f)stru_141A71280.m_quad;
}

// File Line: 19
// RVA: 0xE35D50
void __fastcall hkxScene::~hkxScene(hkxScene *this)
{
  hkRefPtr<hkxSpline> *m_data; // rsi
  int v3; // eax
  __int64 i; // rdi
  hkReferencedObject *m_pntr; // rcx
  int m_capacityAndFlags; // r8d
  hkRefPtr<hkxSkinBinding> *v7; // rsi
  int v8; // eax
  __int64 j; // rdi
  hkReferencedObject *v10; // rcx
  int v11; // r8d
  hkRefPtr<hkxTextureFile> *v12; // rsi
  int v13; // eax
  __int64 k; // rdi
  hkReferencedObject *v15; // rcx
  int v16; // r8d
  hkRefPtr<hkxTextureInplace> *v17; // rsi
  int v18; // eax
  __int64 m; // rdi
  hkReferencedObject *v20; // rcx
  int v21; // r8d
  hkRefPtr<hkxMaterial> *v22; // rsi
  int v23; // eax
  __int64 n; // rdi
  hkReferencedObject *v25; // rcx
  int v26; // r8d
  hkRefPtr<hkxMesh> *v27; // rsi
  int v28; // eax
  __int64 ii; // rdi
  hkReferencedObject *v30; // rcx
  int v31; // r8d
  hkRefPtr<hkxLight> *v32; // rsi
  int v33; // eax
  __int64 jj; // rdi
  hkReferencedObject *v35; // rcx
  int v36; // r8d
  hkRefPtr<hkxCamera> *v37; // rsi
  int v38; // eax
  __int64 kk; // rdi
  hkReferencedObject *v40; // rcx
  int v41; // r8d
  hkRefPtr<hkxNodeSelectionSet> *v42; // rsi
  int v43; // eax
  __int64 mm; // rdi
  hkReferencedObject *v45; // rcx
  int v46; // r8d
  hkxNode *v47; // rcx

  this->vfptr = (hkBaseObjectVtbl *)&hkxScene::`vftable;
  m_data = this->m_splines.m_data;
  v3 = this->m_splines.m_size - 1;
  for ( i = v3; i >= 0; m_data[i--].m_pntr = 0i64 )
  {
    m_pntr = m_data[i].m_pntr;
    if ( m_pntr )
      hkReferencedObject::removeReference(m_pntr);
  }
  m_capacityAndFlags = this->m_splines.m_capacityAndFlags;
  this->m_splines.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_splines.m_data,
      8 * m_capacityAndFlags);
  this->m_splines.m_data = 0i64;
  this->m_splines.m_capacityAndFlags = 0x80000000;
  v7 = this->m_skinBindings.m_data;
  v8 = this->m_skinBindings.m_size - 1;
  for ( j = v8; j >= 0; v7[j--].m_pntr = 0i64 )
  {
    v10 = v7[j].m_pntr;
    if ( v10 )
      hkReferencedObject::removeReference(v10);
  }
  v11 = this->m_skinBindings.m_capacityAndFlags;
  this->m_skinBindings.m_size = 0;
  if ( v11 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_skinBindings.m_data,
      8 * v11);
  this->m_skinBindings.m_data = 0i64;
  this->m_skinBindings.m_capacityAndFlags = 0x80000000;
  v12 = this->m_externalTextures.m_data;
  v13 = this->m_externalTextures.m_size - 1;
  for ( k = v13; k >= 0; v12[k--].m_pntr = 0i64 )
  {
    v15 = v12[k].m_pntr;
    if ( v15 )
      hkReferencedObject::removeReference(v15);
  }
  v16 = this->m_externalTextures.m_capacityAndFlags;
  this->m_externalTextures.m_size = 0;
  if ( v16 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_externalTextures.m_data,
      8 * v16);
  this->m_externalTextures.m_data = 0i64;
  this->m_externalTextures.m_capacityAndFlags = 0x80000000;
  v17 = this->m_inplaceTextures.m_data;
  v18 = this->m_inplaceTextures.m_size - 1;
  for ( m = v18; m >= 0; v17[m--].m_pntr = 0i64 )
  {
    v20 = v17[m].m_pntr;
    if ( v20 )
      hkReferencedObject::removeReference(v20);
  }
  v21 = this->m_inplaceTextures.m_capacityAndFlags;
  this->m_inplaceTextures.m_size = 0;
  if ( v21 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_inplaceTextures.m_data,
      8 * v21);
  this->m_inplaceTextures.m_data = 0i64;
  this->m_inplaceTextures.m_capacityAndFlags = 0x80000000;
  v22 = this->m_materials.m_data;
  v23 = this->m_materials.m_size - 1;
  for ( n = v23; n >= 0; v22[n--].m_pntr = 0i64 )
  {
    v25 = v22[n].m_pntr;
    if ( v25 )
      hkReferencedObject::removeReference(v25);
  }
  v26 = this->m_materials.m_capacityAndFlags;
  this->m_materials.m_size = 0;
  if ( v26 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_materials.m_data,
      8 * v26);
  this->m_materials.m_data = 0i64;
  this->m_materials.m_capacityAndFlags = 0x80000000;
  v27 = this->m_meshes.m_data;
  v28 = this->m_meshes.m_size - 1;
  for ( ii = v28; ii >= 0; v27[ii--].m_pntr = 0i64 )
  {
    v30 = v27[ii].m_pntr;
    if ( v30 )
      hkReferencedObject::removeReference(v30);
  }
  v31 = this->m_meshes.m_capacityAndFlags;
  this->m_meshes.m_size = 0;
  if ( v31 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, this->m_meshes.m_data, 8 * v31);
  this->m_meshes.m_data = 0i64;
  this->m_meshes.m_capacityAndFlags = 0x80000000;
  v32 = this->m_lights.m_data;
  v33 = this->m_lights.m_size - 1;
  for ( jj = v33; jj >= 0; v32[jj--].m_pntr = 0i64 )
  {
    v35 = v32[jj].m_pntr;
    if ( v35 )
      hkReferencedObject::removeReference(v35);
  }
  v36 = this->m_lights.m_capacityAndFlags;
  this->m_lights.m_size = 0;
  if ( v36 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, this->m_lights.m_data, 8 * v36);
  this->m_lights.m_data = 0i64;
  this->m_lights.m_capacityAndFlags = 0x80000000;
  v37 = this->m_cameras.m_data;
  v38 = this->m_cameras.m_size - 1;
  for ( kk = v38; kk >= 0; v37[kk--].m_pntr = 0i64 )
  {
    v40 = v37[kk].m_pntr;
    if ( v40 )
      hkReferencedObject::removeReference(v40);
  }
  v41 = this->m_cameras.m_capacityAndFlags;
  this->m_cameras.m_size = 0;
  if ( v41 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_cameras.m_data,
      8 * v41);
  this->m_cameras.m_data = 0i64;
  this->m_cameras.m_capacityAndFlags = 0x80000000;
  v42 = this->m_selectionSets.m_data;
  v43 = this->m_selectionSets.m_size - 1;
  for ( mm = v43; mm >= 0; v42[mm--].m_pntr = 0i64 )
  {
    v45 = v42[mm].m_pntr;
    if ( v45 )
      hkReferencedObject::removeReference(v45);
  }
  v46 = this->m_selectionSets.m_capacityAndFlags;
  this->m_selectionSets.m_size = 0;
  if ( v46 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_selectionSets.m_data,
      8 * v46);
  this->m_selectionSets.m_data = 0i64;
  this->m_selectionSets.m_capacityAndFlags = 0x80000000;
  v47 = this->m_rootNode.m_pntr;
  if ( v47 )
    hkReferencedObject::removeReference(v47);
  this->m_rootNode.m_pntr = 0i64;
  hkStringPtr::~hkStringPtr(&this->m_asset);
  hkStringPtr::~hkStringPtr(&this->m_modeller);
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 24
// RVA: 0xE36170
hkxNode *__fastcall hkxScene::findNodeByName(hkxScene *this, char *name)
{
  hkxNode *m_pntr; // rcx
  const char *v5; // rcx

  if ( !name )
    return 0i64;
  m_pntr = this->m_rootNode.m_pntr;
  if ( !m_pntr )
    return 0i64;
  v5 = (const char *)((unsigned __int64)m_pntr->m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64);
  if ( !v5 || (unsigned int)hkString::strCasecmp(v5, name) )
    return hkxNode::findDescendantByName(this->m_rootNode.m_pntr, name);
  else
    return this->m_rootNode.m_pntr;
}

// File Line: 40
// RVA: 0xE361E0
hkResult *__fastcall hkxScene::getFullPathToNode(
        hkxScene *this,
        hkResult *result,
        hkxNode *theNode,
        hkArray<hkxNode const *,hkContainerHeapAllocator> *pathOut)
{
  hkxNode::getPathToNode(this->m_rootNode.m_pntr, result, theNode, pathOut);
  return result;
}

// File Line: 45
// RVA: 0xE36210
hkResult *__fastcall hkxScene::getWorldFromNodeTransform(
        hkxScene *this,
        hkResult *result,
        hkxNode *theNode,
        hkMatrix4f *worldFromNodeOut,
        int key)
{
  int m_capacityAndFlags; // r8d
  hkxNode **m_data; // rdx
  int m_size; // eax
  hkxNode **v10; // r9
  hkxNode **v11; // r8
  __int64 v12; // r10
  hkVector4f v13; // xmm9
  __m128 m_quad; // xmm8
  __m128 v15; // xmm10
  hkxNode *v16; // rdx
  int v17; // eax
  int v18; // eax
  hkVector4f v19; // xmm6
  __int64 v20; // rax
  __m128 v21; // xmm2
  hkVector4f v22; // xmm5
  __m128 v23; // xmm2
  hkVector4f v24; // xmm4
  __m128 v25; // xmm2
  __m128 v26; // xmm0
  __m128 v27; // xmm1
  hkResult resulta; // [rsp+20h] [rbp-188h] BYREF
  hkArray<hkxNode const *,hkContainerHeapAllocator> pathOut; // [rsp+40h] [rbp-168h] BYREF
  char v31; // [rsp+50h] [rbp-158h] BYREF

  pathOut.m_data = (hkxNode **)&v31;
  pathOut.m_capacityAndFlags = -2147483616;
  pathOut.m_size = 0;
  hkxScene::getFullPathToNode(this, &resulta, theNode, &pathOut);
  if ( resulta.m_enum )
  {
    m_capacityAndFlags = pathOut.m_capacityAndFlags;
    result->m_enum = HK_FAILURE;
    pathOut.m_size = 0;
    if ( m_capacityAndFlags >= 0 )
    {
      m_data = pathOut.m_data;
LABEL_12:
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        m_data,
        8 * m_capacityAndFlags);
    }
  }
  else
  {
    m_size = pathOut.m_size;
    v10 = pathOut.m_data;
    worldFromNodeOut->m_col0 = (hkVector4f)transform.m_quad;
    worldFromNodeOut->m_col1 = (hkVector4f)direction.m_quad;
    worldFromNodeOut->m_col2 = (hkVector4f)stru_141A71280.m_quad;
    worldFromNodeOut->m_col3 = (hkVector4f)qi.m_vec.m_quad;
    if ( m_size > 0 )
    {
      v11 = v10;
      v12 = (unsigned int)m_size;
      v13.m_quad = (__m128)worldFromNodeOut->m_col1;
      m_quad = qi.m_vec.m_quad;
      v15 = stru_141A71280.m_quad;
      do
      {
        v16 = *v11;
        v17 = (*v11)->m_keyFrames.m_size;
        if ( key >= v17 )
          v18 = v17 - 1;
        else
          v18 = key;
        v19.m_quad = (__m128)worldFromNodeOut->m_col0;
        ++v11;
        v20 = (__int64)&v16->m_keyFrames.m_data[(__int64)v18];
        v21 = *(__m128 *)(v20 + 16);
        v22.m_quad = _mm_add_ps(
                       _mm_add_ps(
                         _mm_add_ps(
                           _mm_mul_ps(_mm_shuffle_ps(v21, v21, 85), v13.m_quad),
                           _mm_mul_ps(_mm_shuffle_ps(v21, v21, 0), worldFromNodeOut->m_col0.m_quad)),
                         _mm_mul_ps(_mm_shuffle_ps(v21, v21, 170), v15)),
                       _mm_mul_ps(_mm_shuffle_ps(v21, v21, 255), m_quad));
        v23 = *(__m128 *)(v20 + 32);
        v24.m_quad = _mm_add_ps(
                       _mm_add_ps(
                         _mm_add_ps(
                           _mm_mul_ps(_mm_shuffle_ps(v23, v23, 85), v13.m_quad),
                           _mm_mul_ps(_mm_shuffle_ps(v23, v23, 0), worldFromNodeOut->m_col0.m_quad)),
                         _mm_mul_ps(_mm_shuffle_ps(v23, v23, 170), v15)),
                       _mm_mul_ps(_mm_shuffle_ps(v23, v23, 255), m_quad));
        v25 = *(__m128 *)(v20 + 48);
        worldFromNodeOut->m_col0.m_quad = _mm_add_ps(
                                            _mm_add_ps(
                                              _mm_add_ps(
                                                _mm_mul_ps(
                                                  _mm_shuffle_ps(*(__m128 *)v20, *(__m128 *)v20, 0),
                                                  worldFromNodeOut->m_col0.m_quad),
                                                _mm_mul_ps(
                                                  _mm_shuffle_ps(*(__m128 *)v20, *(__m128 *)v20, 85),
                                                  v13.m_quad)),
                                              _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)v20, *(__m128 *)v20, 170), v15)),
                                            _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)v20, *(__m128 *)v20, 255), m_quad));
        worldFromNodeOut->m_col1 = (hkVector4f)v22.m_quad;
        worldFromNodeOut->m_col2 = (hkVector4f)v24.m_quad;
        v26 = _mm_mul_ps(_mm_shuffle_ps(v25, v25, 85), v13.m_quad);
        v27 = _mm_mul_ps(_mm_shuffle_ps(v25, v25, 170), v15);
        v13.m_quad = v22.m_quad;
        v15 = v24.m_quad;
        m_quad = _mm_add_ps(
                   _mm_mul_ps(m_quad, _mm_shuffle_ps(v25, v25, 255)),
                   _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v25, v25, 0), v19.m_quad), v26), v27));
        worldFromNodeOut->m_col3.m_quad = m_quad;
        --v12;
      }
      while ( v12 );
    }
    m_capacityAndFlags = pathOut.m_capacityAndFlags;
    result->m_enum = HK_SUCCESS;
    pathOut.m_size = 0;
    if ( m_capacityAndFlags >= 0 )
    {
      m_data = v10;
      goto LABEL_12;
    }
  }
  return result;
}

