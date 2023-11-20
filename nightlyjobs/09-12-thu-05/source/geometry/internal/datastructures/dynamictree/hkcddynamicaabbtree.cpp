// File Line: 17
// RVA: 0xC8F680
void __fastcall hkcdDynamicAabbTree::hkcdDynamicAabbTree(hkcdDynamicAabbTree *this)
{
  hkcdDynamicAabbTree *v1; // rbx
  _QWORD **v2; // rax
  hkcdDynamicTree::DefaultTree48Storage *v3; // rax
  void *v4; // rax

  v1 = this;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkcdDynamicAabbTree::`vftable';
  v2 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkcdDynamicTree::DefaultTree48Storage *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v2[11] + 8i64))(
                                                  v2[11],
                                                  40i64);
  if ( v3 )
  {
    EdgeGeomRaycastAabbTree::EdgeGeomRaycastAabbTree(v3);
    v1->m_treePtr = v4;
  }
  else
  {
    v1->m_treePtr = 0i64;
  }
  v1->m_shouldDeleteTree.m_bool = 1;
}

// File Line: 24
// RVA: 0xC8F6F0
void __fastcall hkcdDynamicAabbTree::hkcdDynamicAabbTree(hkcdDynamicAabbTree *this, hkFinishLoadedObjectFlag f)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkcdDynamicAabbTree::`vftable';
  if ( f.m_finishing )
    this->m_shouldDeleteTree.m_bool = this->m_memSizeAndFlags != 0;
}

// File Line: 32
// RVA: 0xC8F720
void __fastcall hkcdDynamicAabbTree::~hkcdDynamicAabbTree(hkcdDynamicAabbTree *this)
{
  hkcdDynamicAabbTree *v1; // rbx
  hkcdDynamicTree::DefaultTree48Storage *v2; // rcx

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkcdDynamicAabbTree::`vftable';
  v2 = (hkcdDynamicTree::DefaultTree48Storage *)this->m_treePtr;
  if ( v2 && v1->m_shouldDeleteTree.m_bool )
    hkcdDynamicTree::DefaultTree48Storage::`scalar deleting destructor'(v2, 1);
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
}

// File Line: 40
// RVA: 0xC8F770
hkResult *__fastcall hkcdDynamicAabbTree::reserveLeaves(hkcdDynamicAabbTree *this, hkResult *result, int numLeaves)
{
  hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint> *v3; // rcx
  hkResult *v4; // rbx
  hkResult *v5; // rax

  v3 = (hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint> *)this->m_treePtr;
  v4 = result;
  if ( v3 )
  {
    hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint>::reserveNodes(
      v3,
      result,
      2 * numLeaves);
    v5 = v4;
  }
  else
  {
    result->m_enum = 1;
    v5 = result;
  }
  return v5;
}

// File Line: 51
// RVA: 0xC8F7B0
__int64 __fastcall hkcdDynamicAabbTree::insert(hkcdDynamicAabbTree *this, hkAabb *aabb, unsigned int key)
{
  hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint> *v3; // rbx
  unsigned int v4; // er15
  hkAabb *v5; // r14
  __int64 v6; // rdi
  hkcdDynamicTree::CodecRawUint *v7; // rdx
  __int64 v8; // rsi
  signed __int64 v9; // rbp
  hkcdDynamicTree::CodecRawUint *v10; // rcx
  __int64 v11; // r14
  __m128 v12; // xmm7
  __m128 v13; // xmm8
  __int64 v14; // rdx
  __m128 *v15; // r9
  signed __int64 v16; // r11
  __int64 v17; // rax
  __m128 v18; // xmm10
  __m128 v19; // xmm9
  __int64 v20; // r8
  __m128 v21; // xmm0
  __m128 v22; // xmm1
  signed __int64 v23; // rdx
  __m128 *v24; // rdx
  __m128 v25; // xmm3
  __m128 v26; // xmm2
  __m128 v27; // xmm3
  __m128 v28; // xmm2
  __m128 v29; // xmm2
  __m128 v30; // xmm6
  __m128 v31; // xmm5
  __m128 v32; // xmm5
  hkcdDynamicTree::CodecRawUint *v33; // r14
  unsigned __int64 v34; // rdx
  unsigned __int64 v35; // r10
  float v36; // eax
  signed __int64 v37; // rcx
  __m128 v38; // xmm1
  hkcdDynamicTree::CodecRawUint *v40; // [rsp+20h] [rbp-78h]
  __m128 *v41; // [rsp+28h] [rbp-70h]
  hkResult result; // [rsp+B0h] [rbp+18h]

  v3 = (hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint> *)this->m_treePtr;
  v4 = key;
  v5 = aabb;
  if ( !v3->m_firstFree )
    hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint>::reserveNodes(
      (hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint> *)this->m_treePtr,
      &result,
      1);
  v6 = v3->m_firstFree;
  v7 = v3->m_nodes.m_data;
  v8 = 0i64;
  v9 = v6;
  v3->m_firstFree = v3->m_nodes.m_data[(signed int)v6].m_aabb.m_min.m_quad.m128_u32[0];
  v7[v9].m_children[0] = 0;
  v7[v9].m_children[1] = v4;
  v7[v9].m_aabb.m_min = v5->m_min;
  v7[v9].m_aabb.m_max = v5->m_max;
  v10 = v3->m_nodes.m_data;
  v11 = (unsigned int)v3[1].m_nodes.m_size;
  v12 = v3->m_nodes.m_data[v6].m_aabb.m_min.m_quad;
  v13 = v3->m_nodes.m_data[v6].m_aabb.m_max.m_quad;
  if ( (_DWORD)v11 )
  {
    if ( !v3->m_firstFree )
      hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint>::reserveNodes(
        v3,
        &result,
        1);
    v14 = v3->m_firstFree;
    v15 = &v3->m_nodes.m_data[v11].m_aabb.m_min.m_quad;
    v16 = (signed __int64)&v3->m_nodes.m_data[v14];
    v3->m_firstFree = v3->m_nodes.m_data[(signed int)v14].m_aabb.m_min.m_quad.m128_u32[0];
    v17 = v15[2].m128_u32[1];
    if ( (_DWORD)v17 )
    {
      v18 = _mm_sub_ps(v13, v12);
      v19 = _mm_add_ps(v13, v12);
      do
      {
        v21 = _mm_min_ps(*v15, v12);
        v22 = _mm_max_ps(v15[1], v13);
        v23 = v15[2].m128_u32[2];
        v40 = &v3->m_nodes.m_data[v17];
        v20 = (__int64)v40;
        v24 = &v3->m_nodes.m_data[v23].m_aabb.m_min.m_quad;
        v41 = v24;
        *v15 = v21;
        v15[1] = v22;
        v25 = *(__m128 *)(v20 + 16);
        v26 = v25;
        v27 = _mm_add_ps(_mm_sub_ps(v25, *(__m128 *)v20), v18);
        v28 = _mm_sub_ps(_mm_add_ps(v26, *(__m128 *)v20), v19);
        v29 = _mm_mul_ps(v28, v28);
        v30 = _mm_add_ps(_mm_sub_ps(v24[1], *v24), v18);
        v31 = _mm_sub_ps(_mm_add_ps(v24[1], *v24), v19);
        v32 = _mm_mul_ps(v31, v31);
        v15 = (__m128 *)*(&v40
                        + ((float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v29, v29, 85))
                                                 + COERCE_FLOAT(_mm_shuffle_ps(v29, v29, 0)))
                                         + COERCE_FLOAT(_mm_shuffle_ps(v29, v29, 170)))
                                 * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v27, v27, 85))
                                                 + COERCE_FLOAT(_mm_shuffle_ps(v27, v27, 0)))
                                         + COERCE_FLOAT(_mm_shuffle_ps(v27, v27, 170)))) > (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v32, v32, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v32, v32, 0))) + COERCE_FLOAT(_mm_shuffle_ps(v32, v32, 170)))
                                                                                                 * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v30, v30, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v30, v30, 0))) + COERCE_FLOAT(_mm_shuffle_ps(v30, v30, 170))))));
        v17 = v15[2].m128_u32[1];
      }
      while ( (_DWORD)v17 );
    }
    v33 = v3->m_nodes.m_data;
    v34 = (unsigned __int128)((v16 - (unsigned __int64)v3->m_nodes.m_data) * (signed __int128)3074457345618258603i64) >> 64;
    v35 = (v34 >> 63) + ((signed __int64)v34 >> 3);
    v36 = v15[2].m128_f32[0];
    if ( v36 == 0.0 )
    {
      v3[1].m_nodes.m_size = v35;
    }
    else
    {
      LOBYTE(v8) = v33[LODWORD(v36)].m_children[1] == ((unsigned __int64)((unsigned __int128)(((char *)v15 - (char *)v33)
                                                                                            * (signed __int128)3074457345618258603i64) >> 64) >> 63)
                                                    + (unsigned int)((signed __int64)((unsigned __int128)(((char *)v15 - (char *)v33) * (signed __int128)3074457345618258603i64) >> 64) >> 3);
      v33->m_children[v8 + 12i64 * LODWORD(v36)] = v35;
    }
    *(float *)(v16 + 32) = v15[2].m128_f32[0];
    v37 = (char *)v15 - (char *)v3->m_nodes.m_data;
    *(_DWORD *)(v16 + 40) = v6;
    *(_DWORD *)(v16 + 36) = ((unsigned __int64)((unsigned __int128)(v37 * (signed __int128)3074457345618258603i64) >> 64) >> 63)
                          + ((signed __int64)((unsigned __int128)(v37 * (signed __int128)3074457345618258603i64) >> 64) >> 3);
    v15[2].m128_i32[0] = v35;
    v3->m_nodes.m_data[v6].m_parent = v35;
    v38 = _mm_max_ps(v15[1], v13);
    *(__m128 *)v16 = _mm_min_ps(*v15, v12);
    *(__m128 *)(v16 + 16) = v38;
  }
  else
  {
    v3[1].m_nodes.m_size = v6;
    v10[v6].m_parent = 0;
  }
  ++LODWORD(v3[1].m_nodes.m_data);
  return (unsigned int)v6;
}

// File Line: 57
// RVA: 0xC8FAC0
__int64 __fastcall hkcdDynamicAabbTree::insertPoint(hkcdDynamicAabbTree *this, hkVector4f *point, unsigned int key)
{
  hkAabb aabb; // [rsp+20h] [rbp-28h]

  aabb.m_min = (hkVector4f)point->m_quad;
  aabb.m_max = aabb.m_min;
  return hkcdDynamicAabbTree::insert(this, &aabb, key);
}

// File Line: 63
// RVA: 0xC8FAF0
__int64 __fastcall hkcdDynamicAabbTree::tryInsert(hkcdDynamicAabbTree *this, hkAabb *aabb, unsigned int key, hkResult *res)
{
  hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint> *v4; // rbx
  hkResult *v5; // r14
  unsigned int v6; // er15
  hkAabb *v7; // rbp
  __int64 v8; // rax
  __int64 v9; // rdi
  __int64 v10; // rsi
  hkcdDynamicTree::CodecRawUint *v11; // rax
  signed __int64 v12; // r14
  hkcdDynamicTree::CodecRawUint *v13; // rcx
  __int64 v14; // rbp
  __m128 v15; // xmm7
  __m128 v16; // xmm8
  __int64 v17; // rdx
  __m128 *v18; // r9
  signed __int64 v19; // r11
  __int64 v20; // rax
  __m128 v21; // xmm10
  __m128 v22; // xmm9
  __int64 v23; // r8
  __m128 v24; // xmm0
  __m128 v25; // xmm1
  signed __int64 v26; // rdx
  __m128 *v27; // rdx
  __m128 v28; // xmm3
  __m128 v29; // xmm2
  __m128 v30; // xmm3
  __m128 v31; // xmm2
  __m128 v32; // xmm2
  __m128 v33; // xmm6
  __m128 v34; // xmm5
  __m128 v35; // xmm5
  hkcdDynamicTree::CodecRawUint *v36; // rbp
  unsigned __int64 v37; // rdx
  unsigned __int64 v38; // r10
  float v39; // eax
  signed __int64 v40; // rcx
  __m128 v41; // xmm1
  hkResult v42; // [rsp+20h] [rbp-88h]
  hkcdDynamicTree::CodecRawUint *v43; // [rsp+28h] [rbp-80h]
  __m128 *v44; // [rsp+30h] [rbp-78h]
  hkResult result; // [rsp+B0h] [rbp+8h]

  v4 = (hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint> *)this->m_treePtr;
  v5 = res;
  v6 = key;
  v7 = aabb;
  if ( v4 )
  {
    if ( v4->m_firstFree
      || hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint>::reserveNodes(
           v4,
           &result,
           1)->m_enum == HK_SUCCESS )
    {
      v9 = v4->m_firstFree;
      v10 = 0i64;
      v4->m_firstFree = v4->m_nodes.m_data[(signed int)v9].m_aabb.m_min.m_quad.m128_u32[0];
      v5->m_enum = 0;
      v11 = v4->m_nodes.m_data;
      v12 = v9;
      v11[v12].m_children[0] = 0;
      v11[v12].m_children[1] = v6;
      v11[v12].m_aabb.m_min = v7->m_min;
      v11[v12].m_aabb.m_max = v7->m_max;
      v13 = v4->m_nodes.m_data;
      v14 = (unsigned int)v4[1].m_nodes.m_size;
      v15 = v4->m_nodes.m_data[v9].m_aabb.m_min.m_quad;
      v16 = v4->m_nodes.m_data[v9].m_aabb.m_max.m_quad;
      if ( (_DWORD)v14 )
      {
        if ( !v4->m_firstFree )
          hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint>::reserveNodes(
            v4,
            &v42,
            1);
        v17 = v4->m_firstFree;
        v18 = &v4->m_nodes.m_data[v14].m_aabb.m_min.m_quad;
        v19 = (signed __int64)&v4->m_nodes.m_data[v17];
        v4->m_firstFree = v4->m_nodes.m_data[(signed int)v17].m_aabb.m_min.m_quad.m128_u32[0];
        v20 = v18[2].m128_u32[1];
        if ( (_DWORD)v20 )
        {
          v21 = _mm_sub_ps(v16, v15);
          v22 = _mm_add_ps(v16, v15);
          do
          {
            v24 = _mm_min_ps(*v18, v15);
            v25 = _mm_max_ps(v18[1], v16);
            v26 = v18[2].m128_u32[2];
            v43 = &v4->m_nodes.m_data[v20];
            v23 = (__int64)v43;
            v27 = &v4->m_nodes.m_data[v26].m_aabb.m_min.m_quad;
            v44 = v27;
            *v18 = v24;
            v18[1] = v25;
            v28 = *(__m128 *)(v23 + 16);
            v29 = v28;
            v30 = _mm_add_ps(_mm_sub_ps(v28, *(__m128 *)v23), v21);
            v31 = _mm_sub_ps(_mm_add_ps(v29, *(__m128 *)v23), v22);
            v32 = _mm_mul_ps(v31, v31);
            v33 = _mm_add_ps(_mm_sub_ps(v27[1], *v27), v21);
            v34 = _mm_sub_ps(_mm_add_ps(v27[1], *v27), v22);
            v35 = _mm_mul_ps(v34, v34);
            v18 = (__m128 *)*(&v43
                            + ((float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v32, v32, 85))
                                                     + COERCE_FLOAT(_mm_shuffle_ps(v32, v32, 0)))
                                             + COERCE_FLOAT(_mm_shuffle_ps(v32, v32, 170)))
                                     * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v30, v30, 85))
                                                     + COERCE_FLOAT(_mm_shuffle_ps(v30, v30, 0)))
                                             + COERCE_FLOAT(_mm_shuffle_ps(v30, v30, 170)))) > (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v35, v35, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v35, v35, 0))) + COERCE_FLOAT(_mm_shuffle_ps(v35, v35, 170))) * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v33, v33, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v33, v33, 0))) + COERCE_FLOAT(_mm_shuffle_ps(v33, v33, 170))))));
            v20 = v18[2].m128_u32[1];
          }
          while ( (_DWORD)v20 );
        }
        v36 = v4->m_nodes.m_data;
        v37 = (unsigned __int128)((v19 - (unsigned __int64)v4->m_nodes.m_data) * (signed __int128)3074457345618258603i64) >> 64;
        v38 = (v37 >> 63) + ((signed __int64)v37 >> 3);
        v39 = v18[2].m128_f32[0];
        if ( v39 == 0.0 )
        {
          v4[1].m_nodes.m_size = v38;
        }
        else
        {
          LOBYTE(v10) = v36[LODWORD(v39)].m_children[1] == ((unsigned __int64)((unsigned __int128)(((char *)v18
                                                                                                  - (char *)v36)
                                                                                                 * (signed __int128)3074457345618258603i64) >> 64) >> 63)
                                                         + (unsigned int)((signed __int64)((unsigned __int128)(((char *)v18 - (char *)v36) * (signed __int128)3074457345618258603i64) >> 64) >> 3);
          v36->m_children[v10 + 12i64 * LODWORD(v39)] = v38;
        }
        *(float *)(v19 + 32) = v18[2].m128_f32[0];
        v40 = (char *)v18 - (char *)v4->m_nodes.m_data;
        *(_DWORD *)(v19 + 40) = v9;
        *(_DWORD *)(v19 + 36) = ((unsigned __int64)((unsigned __int128)(v40 * (signed __int128)3074457345618258603i64) >> 64) >> 63)
                              + ((signed __int64)((unsigned __int128)(v40 * (signed __int128)3074457345618258603i64) >> 64) >> 3);
        v18[2].m128_i32[0] = v38;
        v4->m_nodes.m_data[v9].m_parent = v38;
        v41 = _mm_max_ps(v18[1], v16);
        *(__m128 *)v19 = _mm_min_ps(*v18, v15);
        *(__m128 *)(v19 + 16) = v41;
      }
      else
      {
        v4[1].m_nodes.m_size = v9;
        v13[v9].m_parent = 0;
      }
      ++LODWORD(v4[1].m_nodes.m_data);
    }
    else
    {
      v5->m_enum = 1;
      LODWORD(v9) = -1;
    }
    v8 = (unsigned int)v9;
  }
  else
  {
    res->m_enum = 1;
    v8 = 0i64;
  }
  return v8;
}

// File Line: 74
// RVA: 0xC8FE50
__int64 __fastcall hkcdDynamicAabbTree::tryInsertPoint(hkcdDynamicAabbTree *this, hkVector4f *point, unsigned int key, hkResult *res)
{
  hkAabb aabb; // [rsp+20h] [rbp-28h]

  aabb.m_min = (hkVector4f)point->m_quad;
  aabb.m_max = aabb.m_min;
  return hkcdDynamicAabbTree::tryInsert(this, &aabb, key, res);
}

// File Line: 80
// RVA: 0xC8FE80
void __fastcall hkcdDynamicAabbTree::update(hkcdDynamicAabbTree *this, unsigned int handle, hkAabb *aabb)
{
  hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint> *v3; // rbx
  unsigned int v4; // er14
  hkcdDynamicTree::CodecRawUint *v5; // rbp
  __int64 v6; // r9
  signed __int64 v7; // rsi
  __int64 v8; // rdi
  hkAabb *v9; // r15
  __m128 v10; // xmm3
  __m128 v11; // xmm4
  signed __int64 v12; // rdx
  int v13; // eax
  signed __int64 v14; // r8
  __int64 v15; // r9
  unsigned int *v16; // r11
  unsigned __int64 v17; // rdx
  __int64 v18; // r8
  hkcdDynamicTree::CodecRawUint *v19; // r8
  signed __int64 v20; // rcx
  __int64 v21; // r9
  unsigned __int64 v22; // rdx
  __m128 v23; // xmm2
  __m128 v24; // xmm1
  signed __int64 v25; // rcx
  hkcdDynamicTree::CodecRawUint *v26; // rax
  hkcdDynamicTree::CodecRawUint *v27; // rcx
  __int64 v28; // rbp
  __m128 v29; // xmm7
  __m128 v30; // xmm8
  __int64 v31; // rdx
  __m128 *v32; // r9
  signed __int64 v33; // r11
  __int64 v34; // rax
  __m128 v35; // xmm10
  __m128 v36; // xmm9
  __int64 v37; // r8
  __m128 v38; // xmm0
  __m128 v39; // xmm1
  signed __int64 v40; // rdx
  __m128 *v41; // rdx
  __m128 v42; // xmm2
  __m128 v43; // xmm3
  __m128 v44; // xmm2
  __m128 v45; // xmm6
  __m128 v46; // xmm3
  __m128 v47; // xmm3
  __m128 v48; // xmm5
  __m128 v49; // xmm5
  hkcdDynamicTree::CodecRawUint *v50; // rbp
  unsigned __int64 v51; // rdx
  unsigned __int64 v52; // r10
  float v53; // eax
  signed __int64 v54; // rcx
  __m128 v55; // xmm1
  hkcdDynamicTree::CodecRawUint *v56; // [rsp+20h] [rbp-88h]
  __m128 *v57; // [rsp+28h] [rbp-80h]
  hkResult result; // [rsp+B8h] [rbp+10h]

  v3 = (hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint> *)this->m_treePtr;
  v4 = handle;
  v5 = v3->m_nodes.m_data;
  v6 = v3[1].m_nodes.m_size;
  v7 = handle;
  v8 = 0i64;
  v9 = aabb;
  v10 = v3->m_nodes.m_data[handle].m_aabb.m_min.m_quad;
  v11 = v3->m_nodes.m_data[handle].m_aabb.m_max.m_quad;
  if ( handle == (_DWORD)v6 )
  {
    v3[1].m_nodes.m_size = 0;
  }
  else
  {
    v12 = (signed __int64)&v5[v5[handle].m_parent];
    v13 = *(_DWORD *)(v12 + 32);
    v14 = (signed __int64)&v5[*(unsigned int *)(v12 + 4 * (10i64 - (*(_DWORD *)(v12 + 40) == v4)))];
    if ( v13 )
    {
      *(_DWORD *)(v14 + 32) = v13;
      v15 = *(unsigned int *)(v12 + 32);
      v16 = (unsigned int *)(v14 + 32);
      v17 = (signed __int64)((unsigned __int128)((v14 - (unsigned __int64)v3->m_nodes.m_data)
                                               * (signed __int128)3074457345618258603i64) >> 64) >> 3;
      v3->m_nodes.m_data->m_children[(v3->m_nodes.m_data[v15].m_children[1] == v5[v7].m_parent) + 12 * v15] = (v17 >> 63) + v17;
      v18 = (signed int)v5[v7].m_parent;
      v3->m_nodes.m_data[v18].m_aabb.m_min.m_quad.m128_i32[0] = v3->m_firstFree;
      v3->m_firstFree = v18;
      v19 = v3->m_nodes.m_data;
      v20 = (signed __int64)&v3->m_nodes.m_data[*v16];
      do
      {
        v21 = *(unsigned int *)(v20 + 32);
        v22 = (unsigned __int64)&v19[(unsigned int)((signed __int64)((unsigned __int128)((v20 - (signed __int64)v19)
                                                                                       * (signed __int128)3074457345618258603i64) >> 64) >> 3)
                                   + ((unsigned __int64)((unsigned __int128)((v20 - (signed __int64)v19)
                                                                           * (signed __int128)3074457345618258603i64) >> 64) >> 63)];
        v23 = _mm_min_ps(
                v19[*(unsigned int *)(v22 + 36)].m_aabb.m_min.m_quad,
                v19[*(unsigned int *)(v22 + 40)].m_aabb.m_min.m_quad);
        v24 = _mm_max_ps(
                v19[*(unsigned int *)(v22 + 36)].m_aabb.m_max.m_quad,
                v19[*(unsigned int *)(v22 + 40)].m_aabb.m_max.m_quad);
        *(__m128 *)v22 = v23;
        *(__m128 *)(v22 + 16) = v24;
        if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmpleps(v11, v24), _mm_cmpleps(v23, v10))) & 7) == 7 )
          break;
        if ( !(_DWORD)v21 )
          break;
        v19 = v3->m_nodes.m_data;
        v20 = (signed __int64)&v3->m_nodes.m_data[v21];
      }
      while ( v20 );
    }
    else
    {
      v5[v6].m_aabb.m_min.m_quad.m128_i32[0] = v3->m_firstFree;
      v25 = v14 - (unsigned __int64)v3->m_nodes.m_data;
      v3->m_firstFree = v6;
      v3[1].m_nodes.m_size = ((unsigned __int64)((unsigned __int128)(v25 * (signed __int128)3074457345618258603i64) >> 64) >> 63)
                           + ((signed __int64)((unsigned __int128)(v25 * (signed __int128)3074457345618258603i64) >> 64) >> 3);
      *(_DWORD *)(v14 + 32) = 0;
    }
  }
  v26 = v3->m_nodes.m_data;
  v26[v7].m_aabb.m_min = v9->m_min;
  v26[v7].m_aabb.m_max = v9->m_max;
  v27 = v3->m_nodes.m_data;
  v28 = (unsigned int)v3[1].m_nodes.m_size;
  v29 = v3->m_nodes.m_data[v7].m_aabb.m_min.m_quad;
  v30 = v3->m_nodes.m_data[v7].m_aabb.m_max.m_quad;
  if ( (_DWORD)v28 )
  {
    if ( !v3->m_firstFree )
      hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint>::reserveNodes(
        v3,
        &result,
        1);
    v31 = v3->m_firstFree;
    v32 = &v3->m_nodes.m_data[v28].m_aabb.m_min.m_quad;
    v33 = (signed __int64)&v3->m_nodes.m_data[v31];
    v3->m_firstFree = v3->m_nodes.m_data[(signed int)v31].m_aabb.m_min.m_quad.m128_u32[0];
    v34 = v32[2].m128_u32[1];
    if ( (_DWORD)v34 )
    {
      v35 = _mm_sub_ps(v30, v29);
      v36 = _mm_add_ps(v30, v29);
      do
      {
        v38 = _mm_min_ps(*v32, v29);
        v39 = _mm_max_ps(v32[1], v30);
        v40 = v32[2].m128_u32[2];
        v56 = &v3->m_nodes.m_data[v34];
        v37 = (__int64)v56;
        v41 = &v3->m_nodes.m_data[v40].m_aabb.m_min.m_quad;
        v57 = v41;
        *v32 = v38;
        v32[1] = v39;
        v42 = *(__m128 *)(v37 + 16);
        v43 = v42;
        v44 = _mm_add_ps(_mm_sub_ps(v42, *(__m128 *)v37), v35);
        v45 = _mm_add_ps(_mm_sub_ps(v41[1], *v41), v35);
        v46 = _mm_sub_ps(_mm_add_ps(v43, *(__m128 *)v37), v36);
        v47 = _mm_mul_ps(v46, v46);
        v48 = _mm_sub_ps(_mm_add_ps(v41[1], *v41), v36);
        v49 = _mm_mul_ps(v48, v48);
        v32 = (__m128 *)*(&v56
                        + ((float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v44, v44, 85))
                                                 + COERCE_FLOAT(_mm_shuffle_ps(v44, v44, 0)))
                                         + COERCE_FLOAT(_mm_shuffle_ps(v44, v44, 170)))
                                 * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v47, v47, 85))
                                                 + COERCE_FLOAT(_mm_shuffle_ps(v47, v47, 0)))
                                         + COERCE_FLOAT(_mm_shuffle_ps(v47, v47, 170)))) > (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v49, v49, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v49, v49, 0))) + COERCE_FLOAT(_mm_shuffle_ps(v49, v49, 170)))
                                                                                                 * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v45, v45, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v45, v45, 0))) + COERCE_FLOAT(_mm_shuffle_ps(v45, v45, 170))))));
        v34 = v32[2].m128_u32[1];
      }
      while ( (_DWORD)v34 );
    }
    v50 = v3->m_nodes.m_data;
    v51 = (unsigned __int128)((v33 - (unsigned __int64)v3->m_nodes.m_data) * (signed __int128)3074457345618258603i64) >> 64;
    v52 = (v51 >> 63) + ((signed __int64)v51 >> 3);
    v53 = v32[2].m128_f32[0];
    if ( v53 == 0.0 )
    {
      v3[1].m_nodes.m_size = v52;
    }
    else
    {
      LOBYTE(v8) = v50[LODWORD(v53)].m_children[1] == ((unsigned __int64)((unsigned __int128)(((char *)v32 - (char *)v50)
                                                                                            * (signed __int128)3074457345618258603i64) >> 64) >> 63)
                                                    + (unsigned int)((signed __int64)((unsigned __int128)(((char *)v32 - (char *)v50) * (signed __int128)3074457345618258603i64) >> 64) >> 3);
      v50->m_children[v8 + 12i64 * LODWORD(v53)] = v52;
    }
    *(float *)(v33 + 32) = v32[2].m128_f32[0];
    v54 = (char *)v32 - (char *)v3->m_nodes.m_data;
    *(_DWORD *)(v33 + 40) = v4;
    *(_DWORD *)(v33 + 36) = ((unsigned __int64)((unsigned __int128)(v54 * (signed __int128)3074457345618258603i64) >> 64) >> 63)
                          + ((signed __int64)((unsigned __int128)(v54 * (signed __int128)3074457345618258603i64) >> 64) >> 3);
    v32[2].m128_i32[0] = v52;
    v3->m_nodes.m_data[v7].m_parent = v52;
    v55 = _mm_max_ps(v32[1], v30);
    *(__m128 *)v33 = _mm_min_ps(*v32, v29);
    *(__m128 *)(v33 + 16) = v55;
  }
  else
  {
    v3[1].m_nodes.m_size = v4;
    v27[v7].m_parent = 0;
  }
}

// File Line: 86
// RVA: 0xC90300
void __fastcall hkcdDynamicAabbTree::remove(hkcdDynamicAabbTree *this, unsigned int handle)
{
  signed int *v2; // r11
  __int64 v3; // rsi
  __int64 v4; // rdi
  __int64 v5; // rdx
  __int64 v6; // r8
  signed __int64 v7; // rbp
  __m128 v8; // xmm3
  __m128 v9; // xmm4
  signed __int64 v10; // r14
  int v11; // eax
  signed __int64 v12; // rbx
  __int64 v13; // r8
  __int64 v14; // r8
  __int64 v15; // r8
  signed __int64 v16; // rcx
  __int64 v17; // r9
  unsigned __int64 v18; // rdx
  __m128 v19; // xmm2
  __m128 v20; // xmm1
  signed __int64 v21; // rcx

  v2 = (signed int *)this->m_treePtr;
  v3 = (signed int)handle;
  v4 = 0i64;
  v5 = *(_QWORD *)v2;
  v6 = v2[8];
  v7 = *(_QWORD *)v2 + 48i64 * (unsigned int)v3;
  v8 = *(__m128 *)v7;
  v9 = *(__m128 *)(v7 + 16);
  if ( (_DWORD)v3 == (_DWORD)v6 )
  {
    v2[8] = 0;
  }
  else
  {
    v10 = v5 + 48i64 * *(unsigned int *)(v7 + 32);
    v11 = *(_DWORD *)(v10 + 32);
    v12 = v5 + 48i64 * *(unsigned int *)(v10 + 4 * (10i64 - (*(_DWORD *)(v10 + 40) == (_DWORD)v3)));
    if ( v11 )
    {
      *(_DWORD *)(v12 + 32) = v11;
      v13 = *(unsigned int *)(v10 + 32);
      LOBYTE(v4) = *(_DWORD *)(*(_QWORD *)v2 + 48 * v13 + 40) == *(_DWORD *)(v7 + 32);
      *(_DWORD *)(*(_QWORD *)v2 + 4 * (v4 + 12 * v13) + 36) = ((unsigned __int64)((unsigned __int128)((v12 - *(_QWORD *)v2) * (signed __int128)3074457345618258603i64) >> 64) >> 63)
                                                            + ((signed __int64)((unsigned __int128)((v12 - *(_QWORD *)v2)
                                                                                                  * (signed __int128)3074457345618258603i64) >> 64) >> 3);
      v14 = *(signed int *)(v7 + 32);
      *(_DWORD *)(*(_QWORD *)v2 + 48 * v14) = v2[4];
      v2[4] = v14;
      v15 = *(_QWORD *)v2;
      v16 = *(_QWORD *)v2 + 48i64 * *(unsigned int *)(v12 + 32);
      do
      {
        v17 = *(unsigned int *)(v16 + 32);
        v18 = v15
            + 48
            * ((unsigned int)((signed __int64)((unsigned __int128)((v16 - v15) * (signed __int128)3074457345618258603i64) >> 64) >> 3)
             + ((unsigned __int64)((unsigned __int128)((v16 - v15) * (signed __int128)3074457345618258603i64) >> 64) >> 63));
        v19 = _mm_min_ps(
                *(__m128 *)(v15 + 48i64 * *(unsigned int *)(v18 + 36)),
                *(__m128 *)(v15 + 48i64 * *(unsigned int *)(v18 + 40)));
        v20 = _mm_max_ps(
                *(__m128 *)(v15 + 48i64 * *(unsigned int *)(v18 + 36) + 16),
                *(__m128 *)(v15 + 48i64 * *(unsigned int *)(v18 + 40) + 16));
        *(__m128 *)v18 = v19;
        *(__m128 *)(v18 + 16) = v20;
        if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmpleps(v9, v20), _mm_cmpleps(v19, v8))) & 7) == 7 )
          break;
        if ( !(_DWORD)v17 )
          break;
        v15 = *(_QWORD *)v2;
        v16 = *(_QWORD *)v2 + 48 * v17;
      }
      while ( v16 );
    }
    else
    {
      *(_DWORD *)(v5 + 48 * v6) = v2[4];
      v21 = v12 - *(_QWORD *)v2;
      v2[4] = v6;
      v2[8] = ((unsigned __int64)((unsigned __int128)(v21 * (signed __int128)3074457345618258603i64) >> 64) >> 63)
            + ((signed __int64)((unsigned __int128)(v21 * (signed __int128)3074457345618258603i64) >> 64) >> 3);
      *(_DWORD *)(v12 + 32) = 0;
    }
  }
  *(_DWORD *)(*(_QWORD *)v2 + 48 * v3) = v2[4];
  --v2[6];
  v2[4] = v3;
}

// File Line: 92
// RVA: 0xC90570
void __fastcall hkcdDynamicAabbTree::clear(hkcdDynamicAabbTree *this)
{
  char *v1; // rbx
  int v2; // eax

  v1 = (char *)this->m_treePtr;
  v2 = *((_DWORD *)v1 + 3);
  *((_DWORD *)v1 + 2) = 0;
  if ( v2 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      *(void **)v1,
      48 * (v2 & 0x3FFFFFFF));
  *(_QWORD *)v1 = 0i64;
  *((_DWORD *)v1 + 3) = 2147483648;
  *((_DWORD *)v1 + 4) = 0;
  *(_QWORD *)(v1 + 28) = 0i64;
  *((_DWORD *)v1 + 6) = 0;
}

// File Line: 98
// RVA: 0xC905D0
__int64 __fastcall hkcdDynamicAabbTree::getLeafData(hkcdDynamicAabbTree *this, unsigned int handle)
{
  return *(unsigned int *)(*(_QWORD *)this->m_treePtr + 48i64 * handle + 40);
}

// File Line: 104
// RVA: 0xC90510
void __fastcall hkcdDynamicAabbTree::rebuild(hkcdDynamicAabbTree *this)
{
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32>::rebuildBranchSAH(
    (hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32> *)this->m_treePtr,
    *((_DWORD *)this->m_treePtr + 8),
    (hkBool)1,
    32,
    16);
}

// File Line: 112
// RVA: 0xC90540
void __fastcall hkcdDynamicAabbTree::rebuildFast(hkcdDynamicAabbTree *this, int numPasses)
{
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32>::optimizeIncremental(
    (hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32> *)this->m_treePtr,
    numPasses * *((_DWORD *)this->m_treePtr + 6),
    2);
}

// File Line: 119
// RVA: 0xC90560
void __fastcall hkcdDynamicAabbTree::optimizeIncremental(hkcdDynamicAabbTree *this, int passes, int lookahead)
{
  hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32>::optimizeIncremental(
    (hkcdDynamicTree::Tree<hkcdDynamicTree::DynamicStorage32> *)this->m_treePtr,
    passes,
    lookahead);
}

// File Line: 126
// RVA: 0xC905F0
unsigned int __fastcall hkcdDynamicAabbTree::castRay(hkcdDynamicAabbTree *this, hkVector4f *start, hkVector4f *end, hkcdAabbTreeQueries::RaycastCollector *collector)
{
  return hkcdAabbTree_castRay<hkcdDynamicTree::DefaultTree48Storage>(this->m_treePtr, start, end, collector);
}

// File Line: 131
// RVA: 0xC90600
void __fastcall hkcdDynamicAabbTree::queryAabb(hkcdDynamicAabbTree *this, hkAabb *aabb, hkcdAabbTreeQueries::AabbCollector *collector)
{
  hkcdAabbTree_queryAabb<hkcdDynamicTree::DefaultTree48Storage>(this->m_treePtr, aabb, collector);
}

// File Line: 136
// RVA: 0xC90610
hkResult *__fastcall hkcdDynamicAabbTree::queryAabb(hkcdDynamicAabbTree *this, hkResult *result, hkAabb *aabb, hkArray<unsigned int,hkContainerTempAllocator> *hits)
{
  hkResult *v4; // rbx
  void *v5; // rdx

  v4 = result;
  v5 = this->m_treePtr;
  if ( v5 )
    hkcdAabbTree_queryAabbHits<hkcdDynamicTree::DefaultTree48Storage>(v4, v5, aabb, hits);
  else
    v4->m_enum = 1;
  return v4;
}

// File Line: 146
// RVA: 0xC90650
unsigned int __fastcall hkcdDynamicAabbTree::getClosestPoint(hkcdDynamicAabbTree *this, hkVector4f *point, hkSimdFloat32 *maxDistance, hkcdAabbTreeQueries::ClosestPointCollector *collector, hkVector4f *closestPointOut)
{
  return hkcdAabbTree_getClosestPoint<hkcdDynamicTree::DefaultTree48Storage>(
           this->m_treePtr,
           point,
           maxDistance,
           collector,
           closestPointOut);
}

// File Line: 151
// RVA: 0xC90660
unsigned int __fastcall hkcdDynamicAabbTree::getClosestPoint(hkcdDynamicAabbTree *this, hkVector4f *point, hkSimdFloat32 *maxDistance, hkVector4f *closestPointOut)
{
  return hkcdAabbTree_getClosestPoint<hkcdDynamicTree::DefaultTree48Storage>(
           this->m_treePtr,
           point,
           maxDistance,
           0i64,
           closestPointOut);
}

// File Line: 156
// RVA: 0xC90680
void __fastcall hkcdDynamicAabbTree::getAllPairs(hkcdDynamicAabbTree *this, hkcdAabbTreeQueries::AllPairsCollector *collector)
{
  hkcdAabbTree_getAllPairs<hkcdDynamicTree::DefaultTree48Storage>(this->m_treePtr, collector);
}

// File Line: 161
// RVA: 0xC90690
void __fastcall hkcdDynamicAabbTree::getAllPairs(hkcdDynamicAabbTree *this, hkcdDynamicAabbTree *otherTree, hkcdAabbTreeQueries::AllPairsCollector *collector)
{
  hkcdAabbTree_getAllPairs<hkcdDynamicTree::DefaultTree48Storage>(this->m_treePtr, otherTree->m_treePtr, collector);
}

// File Line: 166
// RVA: 0xC906B0
signed __int64 __fastcall hkcdDynamicAabbTree::getMemoryFootPrint(hkcdDynamicAabbTree *this)
{
  return 48i64 * (unsigned int)(2 * *((_DWORD *)this->m_treePtr + 6) - 1) + 40;
}

// File Line: 172
// RVA: 0xC906E0
__int64 __fastcall hkcdDynamicAabbTree::getNumLeaves(hkcdDynamicAabbTree *this)
{
  return (*((_DWORD *)this->m_treePtr + 2) + 1) / 2;
}

