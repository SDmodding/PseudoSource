// File Line: 14
// RVA: 0xE35C30
void __fastcall hkxScene::hkxScene(hkxScene *this)
{
  hkxScene *v1; // rbx

  v1 = this;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkxScene::`vftable';
  hkStringPtr::hkStringPtr(&this->m_modeller);
  hkStringPtr::hkStringPtr(&v1->m_asset);
  *(_QWORD *)&v1->m_sceneLength = 0i64;
  v1->m_rootNode.m_pntr = 0i64;
  v1->m_selectionSets.m_data = 0i64;
  v1->m_selectionSets.m_size = 0;
  v1->m_selectionSets.m_capacityAndFlags = 2147483648;
  v1->m_cameras.m_data = 0i64;
  v1->m_cameras.m_size = 0;
  v1->m_cameras.m_capacityAndFlags = 2147483648;
  v1->m_lights.m_data = 0i64;
  v1->m_lights.m_size = 0;
  v1->m_lights.m_capacityAndFlags = 2147483648;
  v1->m_meshes.m_data = 0i64;
  v1->m_meshes.m_size = 0;
  v1->m_meshes.m_capacityAndFlags = 2147483648;
  v1->m_materials.m_data = 0i64;
  v1->m_materials.m_size = 0;
  v1->m_materials.m_capacityAndFlags = 2147483648;
  v1->m_inplaceTextures.m_data = 0i64;
  v1->m_inplaceTextures.m_size = 0;
  v1->m_inplaceTextures.m_capacityAndFlags = 2147483648;
  v1->m_externalTextures.m_data = 0i64;
  v1->m_externalTextures.m_size = 0;
  v1->m_externalTextures.m_capacityAndFlags = 2147483648;
  v1->m_skinBindings.m_data = 0i64;
  v1->m_skinBindings.m_size = 0;
  v1->m_skinBindings.m_capacityAndFlags = 2147483648;
  v1->m_splines.m_data = 0i64;
  v1->m_splines.m_size = 0;
  v1->m_splines.m_capacityAndFlags = 2147483648;
  v1->m_appliedTransform.m_col0 = (hkVector4f)transform.m_quad;
  v1->m_appliedTransform.m_col1 = (hkVector4f)direction.m_quad;
  v1->m_appliedTransform.m_col2 = (hkVector4f)stru_141A71280.m_quad;
}

// File Line: 19
// RVA: 0xE35D50
void __fastcall hkxScene::~hkxScene(hkxScene *this)
{
  hkxScene *v1; // rbx
  hkRefPtr<hkxSpline> *v2; // rsi
  int v3; // eax
  __int64 i; // rdi
  hkReferencedObject *v5; // rcx
  int v6; // er8
  hkRefPtr<hkxSkinBinding> *v7; // rsi
  int v8; // eax
  __int64 j; // rdi
  hkReferencedObject *v10; // rcx
  int v11; // er8
  hkRefPtr<hkxTextureFile> *v12; // rsi
  int v13; // eax
  __int64 k; // rdi
  hkReferencedObject *v15; // rcx
  int v16; // er8
  hkRefPtr<hkxTextureInplace> *v17; // rsi
  int v18; // eax
  __int64 l; // rdi
  hkReferencedObject *v20; // rcx
  int v21; // er8
  hkRefPtr<hkxMaterial> *v22; // rsi
  int v23; // eax
  __int64 m; // rdi
  hkReferencedObject *v25; // rcx
  int v26; // er8
  hkRefPtr<hkxMesh> *v27; // rsi
  int v28; // eax
  __int64 n; // rdi
  hkReferencedObject *v30; // rcx
  int v31; // er8
  hkRefPtr<hkxLight> *v32; // rsi
  int v33; // eax
  __int64 ii; // rdi
  hkReferencedObject *v35; // rcx
  int v36; // er8
  hkRefPtr<hkxCamera> *v37; // rsi
  int v38; // eax
  __int64 jj; // rdi
  hkReferencedObject *v40; // rcx
  int v41; // er8
  hkRefPtr<hkxNodeSelectionSet> *v42; // rsi
  int v43; // eax
  __int64 kk; // rdi
  hkReferencedObject *v45; // rcx
  int v46; // er8
  hkReferencedObject *v47; // rcx

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkxScene::`vftable';
  v2 = this->m_splines.m_data;
  v3 = this->m_splines.m_size - 1;
  for ( i = v3; i >= 0; v2[i--].m_pntr = 0i64 )
  {
    v5 = (hkReferencedObject *)&v2[i].m_pntr->vfptr;
    if ( v5 )
      hkReferencedObject::removeReference(v5);
  }
  v6 = v1->m_splines.m_capacityAndFlags;
  v1->m_splines.m_size = 0;
  if ( v6 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_splines.m_data,
      8 * v6);
  v1->m_splines.m_data = 0i64;
  v1->m_splines.m_capacityAndFlags = 2147483648;
  v7 = v1->m_skinBindings.m_data;
  v8 = v1->m_skinBindings.m_size - 1;
  for ( j = v8; j >= 0; v7[j--].m_pntr = 0i64 )
  {
    v10 = (hkReferencedObject *)&v7[j].m_pntr->vfptr;
    if ( v10 )
      hkReferencedObject::removeReference(v10);
  }
  v11 = v1->m_skinBindings.m_capacityAndFlags;
  v1->m_skinBindings.m_size = 0;
  if ( v11 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_skinBindings.m_data,
      8 * v11);
  v1->m_skinBindings.m_data = 0i64;
  v1->m_skinBindings.m_capacityAndFlags = 2147483648;
  v12 = v1->m_externalTextures.m_data;
  v13 = v1->m_externalTextures.m_size - 1;
  for ( k = v13; k >= 0; v12[k--].m_pntr = 0i64 )
  {
    v15 = (hkReferencedObject *)&v12[k].m_pntr->vfptr;
    if ( v15 )
      hkReferencedObject::removeReference(v15);
  }
  v16 = v1->m_externalTextures.m_capacityAndFlags;
  v1->m_externalTextures.m_size = 0;
  if ( v16 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_externalTextures.m_data,
      8 * v16);
  v1->m_externalTextures.m_data = 0i64;
  v1->m_externalTextures.m_capacityAndFlags = 2147483648;
  v17 = v1->m_inplaceTextures.m_data;
  v18 = v1->m_inplaceTextures.m_size - 1;
  for ( l = v18; l >= 0; v17[l--].m_pntr = 0i64 )
  {
    v20 = (hkReferencedObject *)&v17[l].m_pntr->vfptr;
    if ( v20 )
      hkReferencedObject::removeReference(v20);
  }
  v21 = v1->m_inplaceTextures.m_capacityAndFlags;
  v1->m_inplaceTextures.m_size = 0;
  if ( v21 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_inplaceTextures.m_data,
      8 * v21);
  v1->m_inplaceTextures.m_data = 0i64;
  v1->m_inplaceTextures.m_capacityAndFlags = 2147483648;
  v22 = v1->m_materials.m_data;
  v23 = v1->m_materials.m_size - 1;
  for ( m = v23; m >= 0; v22[m--].m_pntr = 0i64 )
  {
    v25 = (hkReferencedObject *)&v22[m].m_pntr->vfptr;
    if ( v25 )
      hkReferencedObject::removeReference(v25);
  }
  v26 = v1->m_materials.m_capacityAndFlags;
  v1->m_materials.m_size = 0;
  if ( v26 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_materials.m_data,
      8 * v26);
  v1->m_materials.m_data = 0i64;
  v1->m_materials.m_capacityAndFlags = 2147483648;
  v27 = v1->m_meshes.m_data;
  v28 = v1->m_meshes.m_size - 1;
  for ( n = v28; n >= 0; v27[n--].m_pntr = 0i64 )
  {
    v30 = (hkReferencedObject *)&v27[n].m_pntr->vfptr;
    if ( v30 )
      hkReferencedObject::removeReference(v30);
  }
  v31 = v1->m_meshes.m_capacityAndFlags;
  v1->m_meshes.m_size = 0;
  if ( v31 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_meshes.m_data,
      8 * v31);
  v1->m_meshes.m_data = 0i64;
  v1->m_meshes.m_capacityAndFlags = 2147483648;
  v32 = v1->m_lights.m_data;
  v33 = v1->m_lights.m_size - 1;
  for ( ii = v33; ii >= 0; v32[ii--].m_pntr = 0i64 )
  {
    v35 = (hkReferencedObject *)&v32[ii].m_pntr->vfptr;
    if ( v35 )
      hkReferencedObject::removeReference(v35);
  }
  v36 = v1->m_lights.m_capacityAndFlags;
  v1->m_lights.m_size = 0;
  if ( v36 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_lights.m_data,
      8 * v36);
  v1->m_lights.m_data = 0i64;
  v1->m_lights.m_capacityAndFlags = 2147483648;
  v37 = v1->m_cameras.m_data;
  v38 = v1->m_cameras.m_size - 1;
  for ( jj = v38; jj >= 0; v37[jj--].m_pntr = 0i64 )
  {
    v40 = (hkReferencedObject *)&v37[jj].m_pntr->vfptr;
    if ( v40 )
      hkReferencedObject::removeReference(v40);
  }
  v41 = v1->m_cameras.m_capacityAndFlags;
  v1->m_cameras.m_size = 0;
  if ( v41 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_cameras.m_data,
      8 * v41);
  v1->m_cameras.m_data = 0i64;
  v1->m_cameras.m_capacityAndFlags = 2147483648;
  v42 = v1->m_selectionSets.m_data;
  v43 = v1->m_selectionSets.m_size - 1;
  for ( kk = v43; kk >= 0; v42[kk--].m_pntr = 0i64 )
  {
    v45 = (hkReferencedObject *)&v42[kk].m_pntr->vfptr;
    if ( v45 )
      hkReferencedObject::removeReference(v45);
  }
  v46 = v1->m_selectionSets.m_capacityAndFlags;
  v1->m_selectionSets.m_size = 0;
  if ( v46 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_selectionSets.m_data,
      8 * v46);
  v1->m_selectionSets.m_data = 0i64;
  v1->m_selectionSets.m_capacityAndFlags = 2147483648;
  v47 = (hkReferencedObject *)&v1->m_rootNode.m_pntr->vfptr;
  if ( v47 )
    hkReferencedObject::removeReference(v47);
  v1->m_rootNode.m_pntr = 0i64;
  hkStringPtr::~hkStringPtr(&v1->m_asset);
  hkStringPtr::~hkStringPtr(&v1->m_modeller);
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
}

// File Line: 24
// RVA: 0xE36170
hkxNode *__fastcall hkxScene::findNodeByName(hkxScene *this, const char *name)
{
  const char *v2; // rdi
  hkxScene *v3; // rbx
  hkxNode *v4; // rcx
  const char *v5; // rcx
  hkxNode *result; // rax

  v2 = name;
  v3 = this;
  if ( !name )
    return 0i64;
  v4 = this->m_rootNode.m_pntr;
  if ( !v4 )
    return 0i64;
  v5 = (const char *)((_QWORD)v4->m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64);
  if ( !v5 || (unsigned int)hkString::strCasecmp(v5, name) )
    result = hkxNode::findDescendantByName(v3->m_rootNode.m_pntr, v2);
  else
    result = v3->m_rootNode.m_pntr;
  return result;
}

// File Line: 40
// RVA: 0xE361E0
hkResult *__fastcall hkxScene::getFullPathToNode(hkxScene *this, hkResult *result, hkxNode *theNode, hkArray<hkxNode const *,hkContainerHeapAllocator> *pathOut)
{
  hkResult *v4; // rbx

  v4 = result;
  hkxNode::getPathToNode(this->m_rootNode.m_pntr, result, theNode, pathOut);
  return v4;
}

// File Line: 45
// RVA: 0xE36210
hkResult *__fastcall hkxScene::getWorldFromNodeTransform(hkxScene *this, hkResult *result, hkxNode *theNode, hkMatrix4f *worldFromNodeOut, int key)
{
  hkQuaternionf *v5; // rbx
  hkResult *v6; // rdi
  int v7; // er8
  hkxNode **v8; // rdx
  int v9; // eax
  hkxNode **v10; // r9
  hkxNode **v11; // r8
  __int64 v12; // r10
  __m128 v13; // xmm9
  __m128 v14; // xmm8
  __m128 v15; // xmm10
  hkxNode *v16; // rdx
  int v17; // eax
  int v18; // eax
  __m128 v19; // xmm6
  signed __int64 v20; // rax
  __m128 v21; // xmm2
  __m128 v22; // xmm5
  __m128 v23; // xmm2
  __m128 v24; // xmm4
  __m128 v25; // xmm2
  __m128 v26; // xmm0
  __m128 v27; // xmm1
  hkResult resulta; // [rsp+20h] [rbp-188h]
  hkArray<hkxNode const *,hkContainerHeapAllocator> pathOut; // [rsp+40h] [rbp-168h]
  char v31; // [rsp+50h] [rbp-158h]

  v5 = (hkQuaternionf *)worldFromNodeOut;
  v6 = result;
  pathOut.m_data = (hkxNode **)&v31;
  pathOut.m_capacityAndFlags = -2147483616;
  pathOut.m_size = 0;
  hkxScene::getFullPathToNode(this, &resulta, theNode, &pathOut);
  if ( resulta.m_enum )
  {
    v7 = pathOut.m_capacityAndFlags;
    v6->m_enum = 1;
    pathOut.m_size = 0;
    if ( v7 >= 0 )
    {
      v8 = pathOut.m_data;
LABEL_12:
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v8,
        8 * v7);
      return v6;
    }
  }
  else
  {
    v9 = pathOut.m_size;
    v10 = pathOut.m_data;
    v5->m_vec = (hkVector4f)transform.m_quad;
    v5[1].m_vec = (hkVector4f)direction.m_quad;
    v5[2].m_vec = (hkVector4f)stru_141A71280.m_quad;
    v5[3] = (hkQuaternionf)qi.m_vec.m_quad;
    if ( v9 > 0 )
    {
      v11 = v10;
      v12 = (unsigned int)v9;
      v13 = v5[1].m_vec.m_quad;
      v14 = qi.m_vec.m_quad;
      v15 = stru_141A71280.m_quad;
      do
      {
        v16 = *v11;
        v17 = (*v11)->m_keyFrames.m_size;
        if ( key >= v17 )
          v18 = v17 - 1;
        else
          v18 = key;
        v19 = v5->m_vec.m_quad;
        ++v11;
        v20 = (signed __int64)&v16->m_keyFrames.m_data[(signed __int64)v18];
        v21 = *(__m128 *)(v20 + 16);
        v22 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v21, v21, 85), v13),
                    _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)(v20 + 16), v21, 0), v5->m_vec.m_quad)),
                  _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)(v20 + 16), v21, 170), v15)),
                _mm_mul_ps(_mm_shuffle_ps(v21, v21, 255), v14));
        v23 = *(__m128 *)(v20 + 32);
        v24 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v23, v23, 85), v13),
                    _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)(v20 + 32), v23, 0), v5->m_vec.m_quad)),
                  _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)(v20 + 32), v23, 170), v15)),
                _mm_mul_ps(_mm_shuffle_ps(v23, v23, 255), v14));
        v25 = *(__m128 *)(v20 + 48);
        v5->m_vec.m_quad = _mm_add_ps(
                             _mm_add_ps(
                               _mm_add_ps(
                                 _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)v20, *(__m128 *)v20, 0), v5->m_vec.m_quad),
                                 _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)v20, *(__m128 *)v20, 85), v13)),
                               _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)v20, *(__m128 *)v20, 170), v15)),
                             _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)v20, *(__m128 *)v20, 255), v14));
        v5[1] = (hkQuaternionf)v22;
        v5[2] = (hkQuaternionf)v24;
        v26 = _mm_mul_ps(_mm_shuffle_ps(v25, v25, 85), v13);
        v27 = _mm_mul_ps(_mm_shuffle_ps(v25, v25, 170), v15);
        v13 = v22;
        v15 = v24;
        v14 = _mm_add_ps(
                _mm_mul_ps(v14, _mm_shuffle_ps(v25, v25, 255)),
                _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v25, v25, 0), v19), v26), v27));
        v5[3] = (hkQuaternionf)v14;
        --v12;
      }
      while ( v12 );
    }
    v7 = pathOut.m_capacityAndFlags;
    v6->m_enum = 0;
    pathOut.m_size = 0;
    if ( v7 >= 0 )
    {
      v8 = v10;
      goto LABEL_12;
    }
  }
  return v6;
}

