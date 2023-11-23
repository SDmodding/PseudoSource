// File Line: 17
// RVA: 0xC8F680
void __fastcall hkcdDynamicAabbTree::hkcdDynamicAabbTree(hkcdDynamicAabbTree *this)
{
  _QWORD **Value; // rax
  hkcdDynamicTree::DefaultTree48Storage *v3; // rax
  void *v4; // rax

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkcdDynamicAabbTree::`vftable;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkcdDynamicTree::DefaultTree48Storage *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                                  Value[11],
                                                  40i64);
  if ( v3 )
  {
    EdgeGeomRaycastAabbTree::EdgeGeomRaycastAabbTree(v3);
    this->m_treePtr = v4;
  }
  else
  {
    this->m_treePtr = 0i64;
  }
  this->m_shouldDeleteTree.m_bool = 1;
}

// File Line: 24
// RVA: 0xC8F6F0
void __fastcall hkcdDynamicAabbTree::hkcdDynamicAabbTree(hkcdDynamicAabbTree *this, hkFinishLoadedObjectFlag f)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkcdDynamicAabbTree::`vftable;
  if ( f.m_finishing )
    this->m_shouldDeleteTree.m_bool = this->m_memSizeAndFlags != 0;
}

// File Line: 32
// RVA: 0xC8F720
void __fastcall hkcdDynamicAabbTree::~hkcdDynamicAabbTree(hkcdDynamicAabbTree *this)
{
  hkcdDynamicTree::DefaultTree48Storage *m_treePtr; // rcx

  this->vfptr = (hkBaseObjectVtbl *)&hkcdDynamicAabbTree::`vftable;
  m_treePtr = (hkcdDynamicTree::DefaultTree48Storage *)this->m_treePtr;
  if ( m_treePtr && this->m_shouldDeleteTree.m_bool )
    hkcdDynamicTree::DefaultTree48Storage::`scalar deleting destructor(m_treePtr, 1);
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 40
// RVA: 0xC8F770
hkResult *__fastcall hkcdDynamicAabbTree::reserveLeaves(hkcdDynamicAabbTree *this, hkResult *result, int numLeaves)
{
  hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint> *m_treePtr; // rcx

  m_treePtr = (hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint> *)this->m_treePtr;
  if ( m_treePtr )
  {
    hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint>::reserveNodes(
      m_treePtr,
      result,
      2 * numLeaves);
    return result;
  }
  else
  {
    result->m_enum = HK_FAILURE;
    return result;
  }
}

// File Line: 51
// RVA: 0xC8F7B0
__int64 __fastcall hkcdDynamicAabbTree::insert(hkcdDynamicAabbTree *this, hkAabb *aabb, unsigned int key)
{
  hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint> *m_treePtr; // rbx
  __int64 m_firstFree; // rdi
  hkcdDynamicTree::CodecRawUint *m_data; // rdx
  __int64 v8; // rsi
  __int64 v9; // rbp
  hkcdDynamicTree::CodecRawUint *v10; // rcx
  __int64 m_size; // r14
  __m128 m_quad; // xmm7
  __m128 v13; // xmm8
  __int64 v14; // rdx
  __m128 *p_m_quad; // r9
  __int64 v16; // r11
  __int64 v17; // rax
  __m128 v18; // xmm10
  __m128 v19; // xmm9
  __int64 v20; // r8
  __m128 v21; // xmm0
  __m128 v22; // xmm1
  __int64 v23; // rdx
  __m128 *v24; // rdx
  __m128 v25; // xmm2
  __m128 v26; // xmm3
  __m128 v27; // xmm2
  __m128 v28; // xmm2
  __m128 v29; // xmm6
  __m128 v30; // xmm5
  __m128 v31; // xmm5
  hkcdDynamicTree::CodecRawUint *v32; // r14
  __int64 v33; // r10
  unsigned int v34; // eax
  __int64 v35; // rcx
  __m128 v36; // xmm1
  __int64 v38[2]; // [rsp+20h] [rbp-78h]
  hkResult result; // [rsp+B0h] [rbp+18h] BYREF

  m_treePtr = (hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint> *)this->m_treePtr;
  if ( !m_treePtr->m_firstFree )
    hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint>::reserveNodes(
      (hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint> *)this->m_treePtr,
      &result,
      1);
  m_firstFree = m_treePtr->m_firstFree;
  m_data = m_treePtr->m_nodes.m_data;
  v8 = 0i64;
  v9 = m_firstFree;
  m_treePtr->m_firstFree = m_treePtr->m_nodes.m_data[(int)m_firstFree].m_aabb.m_min.m_quad.m128_u32[0];
  m_data[v9].m_children[0] = 0;
  m_data[v9].m_children[1] = key;
  m_data[v9].m_aabb.m_min = aabb->m_min;
  m_data[v9].m_aabb.m_max = aabb->m_max;
  v10 = m_treePtr->m_nodes.m_data;
  m_size = (unsigned int)m_treePtr[1].m_nodes.m_size;
  m_quad = m_treePtr->m_nodes.m_data[m_firstFree].m_aabb.m_min.m_quad;
  v13 = m_treePtr->m_nodes.m_data[m_firstFree].m_aabb.m_max.m_quad;
  if ( (_DWORD)m_size )
  {
    if ( !m_treePtr->m_firstFree )
      hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint>::reserveNodes(
        m_treePtr,
        &result,
        1);
    v14 = m_treePtr->m_firstFree;
    p_m_quad = &m_treePtr->m_nodes.m_data[m_size].m_aabb.m_min.m_quad;
    v16 = (__int64)&m_treePtr->m_nodes.m_data[v14];
    m_treePtr->m_firstFree = m_treePtr->m_nodes.m_data[(int)v14].m_aabb.m_min.m_quad.m128_u32[0];
    v17 = p_m_quad[2].m128_u32[1];
    if ( (_DWORD)v17 )
    {
      v18 = _mm_sub_ps(v13, m_quad);
      v19 = _mm_add_ps(v13, m_quad);
      do
      {
        v21 = _mm_min_ps(*p_m_quad, m_quad);
        v22 = _mm_max_ps(p_m_quad[1], v13);
        v23 = p_m_quad[2].m128_u32[2];
        v38[0] = (__int64)&m_treePtr->m_nodes.m_data[v17];
        v20 = v38[0];
        v24 = &m_treePtr->m_nodes.m_data[v23].m_aabb.m_min.m_quad;
        v38[1] = (__int64)v24;
        *p_m_quad = v21;
        p_m_quad[1] = v22;
        v25 = *(__m128 *)(v20 + 16);
        v26 = _mm_add_ps(_mm_sub_ps(v25, *(__m128 *)v20), v18);
        v27 = _mm_sub_ps(_mm_add_ps(v25, *(__m128 *)v20), v19);
        v28 = _mm_mul_ps(v27, v27);
        v29 = _mm_add_ps(_mm_sub_ps(v24[1], *v24), v18);
        v30 = _mm_sub_ps(_mm_add_ps(v24[1], *v24), v19);
        v31 = _mm_mul_ps(v30, v30);
        p_m_quad = (__m128 *)v38[(float)((float)((float)(_mm_shuffle_ps(v28, v28, 85).m128_f32[0]
                                                       + _mm_shuffle_ps(v28, v28, 0).m128_f32[0])
                                               + _mm_shuffle_ps(v28, v28, 170).m128_f32[0])
                                       * (float)((float)(_mm_shuffle_ps(v26, v26, 85).m128_f32[0]
                                                       + _mm_shuffle_ps(v26, v26, 0).m128_f32[0])
                                               + _mm_shuffle_ps(v26, v26, 170).m128_f32[0])) > (float)((float)((float)(_mm_shuffle_ps(v31, v31, 85).m128_f32[0] + _mm_shuffle_ps(v31, v31, 0).m128_f32[0]) + _mm_shuffle_ps(v31, v31, 170).m128_f32[0]) * (float)((float)(_mm_shuffle_ps(v29, v29, 85).m128_f32[0] + _mm_shuffle_ps(v29, v29, 0).m128_f32[0]) + _mm_shuffle_ps(v29, v29, 170).m128_f32[0]))];
        v17 = p_m_quad[2].m128_u32[1];
      }
      while ( (_DWORD)v17 );
    }
    v32 = m_treePtr->m_nodes.m_data;
    v33 = (signed __int64)(v16 - (unsigned __int64)m_treePtr->m_nodes.m_data) / 48;
    v34 = p_m_quad[2].m128_u32[0];
    if ( v34 )
    {
      LOBYTE(v8) = v32[v34].m_children[1] == (unsigned int)(((char *)p_m_quad - (char *)v32) / 48);
      v32[v34].m_children[v8] = v33;
    }
    else
    {
      m_treePtr[1].m_nodes.m_size = v33;
    }
    *(_DWORD *)(v16 + 32) = p_m_quad[2].m128_i32[0];
    v35 = (char *)p_m_quad - (char *)m_treePtr->m_nodes.m_data;
    *(_DWORD *)(v16 + 40) = m_firstFree;
    *(_DWORD *)(v16 + 36) = v35 / 48;
    p_m_quad[2].m128_i32[0] = v33;
    m_treePtr->m_nodes.m_data[m_firstFree].m_parent = v33;
    v36 = _mm_max_ps(p_m_quad[1], v13);
    *(__m128 *)v16 = _mm_min_ps(*p_m_quad, m_quad);
    *(__m128 *)(v16 + 16) = v36;
  }
  else
  {
    m_treePtr[1].m_nodes.m_size = m_firstFree;
    v10[m_firstFree].m_parent = 0;
  }
  ++LODWORD(m_treePtr[1].m_nodes.m_data);
  return (unsigned int)m_firstFree;
}

// File Line: 57
// RVA: 0xC8FAC0
__int64 __fastcall hkcdDynamicAabbTree::insertPoint(hkcdDynamicAabbTree *this, hkVector4f *point, unsigned int key)
{
  hkAabb aabb; // [rsp+20h] [rbp-28h] BYREF

  aabb.m_min = (hkVector4f)point->m_quad;
  aabb.m_max = aabb.m_min;
  return hkcdDynamicAabbTree::insert(this, &aabb, key);
}

// File Line: 63
// RVA: 0xC8FAF0
__int64 __fastcall hkcdDynamicAabbTree::tryInsert(
        hkcdDynamicAabbTree *this,
        hkAabb *aabb,
        unsigned int key,
        hkResult *res)
{
  hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint> *m_treePtr; // rbx
  __int64 m_firstFree; // rdi
  __int64 v10; // rsi
  hkcdDynamicTree::CodecRawUint *m_data; // rax
  __int64 v12; // r14
  hkcdDynamicTree::CodecRawUint *v13; // rcx
  __int64 m_size; // rbp
  __m128 m_quad; // xmm7
  __m128 v16; // xmm8
  __int64 v17; // rdx
  __m128 *p_m_quad; // r9
  __int64 v19; // r11
  __int64 v20; // rax
  __m128 v21; // xmm10
  __m128 v22; // xmm9
  __int64 v23; // r8
  __m128 v24; // xmm0
  __m128 v25; // xmm1
  __int64 v26; // rdx
  __m128 *v27; // rdx
  __m128 v28; // xmm2
  __m128 v29; // xmm3
  __m128 v30; // xmm2
  __m128 v31; // xmm2
  __m128 v32; // xmm6
  __m128 v33; // xmm5
  __m128 v34; // xmm5
  hkcdDynamicTree::CodecRawUint *v35; // rbp
  __int64 v36; // r10
  unsigned int v37; // eax
  __int64 v38; // rcx
  __m128 v39; // xmm1
  hkResult v40; // [rsp+20h] [rbp-88h] BYREF
  __int64 v41[3]; // [rsp+28h] [rbp-80h]
  hkResult result; // [rsp+B0h] [rbp+8h] BYREF

  m_treePtr = (hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint> *)this->m_treePtr;
  if ( m_treePtr )
  {
    if ( m_treePtr->m_firstFree
      || hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint>::reserveNodes(
           m_treePtr,
           &result,
           1)->m_enum == HK_SUCCESS )
    {
      m_firstFree = m_treePtr->m_firstFree;
      v10 = 0i64;
      m_treePtr->m_firstFree = m_treePtr->m_nodes.m_data[(int)m_firstFree].m_aabb.m_min.m_quad.m128_u32[0];
      res->m_enum = HK_SUCCESS;
      m_data = m_treePtr->m_nodes.m_data;
      v12 = m_firstFree;
      m_data[v12].m_children[0] = 0;
      m_data[v12].m_children[1] = key;
      m_data[v12].m_aabb.m_min = aabb->m_min;
      m_data[v12].m_aabb.m_max = aabb->m_max;
      v13 = m_treePtr->m_nodes.m_data;
      m_size = (unsigned int)m_treePtr[1].m_nodes.m_size;
      m_quad = m_treePtr->m_nodes.m_data[m_firstFree].m_aabb.m_min.m_quad;
      v16 = m_treePtr->m_nodes.m_data[m_firstFree].m_aabb.m_max.m_quad;
      if ( (_DWORD)m_size )
      {
        if ( !m_treePtr->m_firstFree )
          hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint>::reserveNodes(
            m_treePtr,
            &v40,
            1);
        v17 = m_treePtr->m_firstFree;
        p_m_quad = &m_treePtr->m_nodes.m_data[m_size].m_aabb.m_min.m_quad;
        v19 = (__int64)&m_treePtr->m_nodes.m_data[v17];
        m_treePtr->m_firstFree = m_treePtr->m_nodes.m_data[(int)v17].m_aabb.m_min.m_quad.m128_u32[0];
        v20 = p_m_quad[2].m128_u32[1];
        if ( (_DWORD)v20 )
        {
          v21 = _mm_sub_ps(v16, m_quad);
          v22 = _mm_add_ps(v16, m_quad);
          do
          {
            v24 = _mm_min_ps(*p_m_quad, m_quad);
            v25 = _mm_max_ps(p_m_quad[1], v16);
            v26 = p_m_quad[2].m128_u32[2];
            v41[0] = (__int64)&m_treePtr->m_nodes.m_data[v20];
            v23 = v41[0];
            v27 = &m_treePtr->m_nodes.m_data[v26].m_aabb.m_min.m_quad;
            v41[1] = (__int64)v27;
            *p_m_quad = v24;
            p_m_quad[1] = v25;
            v28 = *(__m128 *)(v23 + 16);
            v29 = _mm_add_ps(_mm_sub_ps(v28, *(__m128 *)v23), v21);
            v30 = _mm_sub_ps(_mm_add_ps(v28, *(__m128 *)v23), v22);
            v31 = _mm_mul_ps(v30, v30);
            v32 = _mm_add_ps(_mm_sub_ps(v27[1], *v27), v21);
            v33 = _mm_sub_ps(_mm_add_ps(v27[1], *v27), v22);
            v34 = _mm_mul_ps(v33, v33);
            p_m_quad = (__m128 *)v41[(float)((float)((float)(_mm_shuffle_ps(v31, v31, 85).m128_f32[0]
                                                           + _mm_shuffle_ps(v31, v31, 0).m128_f32[0])
                                                   + _mm_shuffle_ps(v31, v31, 170).m128_f32[0])
                                           * (float)((float)(_mm_shuffle_ps(v29, v29, 85).m128_f32[0]
                                                           + _mm_shuffle_ps(v29, v29, 0).m128_f32[0])
                                                   + _mm_shuffle_ps(v29, v29, 170).m128_f32[0])) > (float)((float)((float)(_mm_shuffle_ps(v34, v34, 85).m128_f32[0] + _mm_shuffle_ps(v34, v34, 0).m128_f32[0]) + _mm_shuffle_ps(v34, v34, 170).m128_f32[0]) * (float)((float)(_mm_shuffle_ps(v32, v32, 85).m128_f32[0] + _mm_shuffle_ps(v32, v32, 0).m128_f32[0]) + _mm_shuffle_ps(v32, v32, 170).m128_f32[0]))];
            v20 = p_m_quad[2].m128_u32[1];
          }
          while ( (_DWORD)v20 );
        }
        v35 = m_treePtr->m_nodes.m_data;
        v36 = (signed __int64)(v19 - (unsigned __int64)m_treePtr->m_nodes.m_data) / 48;
        v37 = p_m_quad[2].m128_u32[0];
        if ( v37 )
        {
          LOBYTE(v10) = v35[v37].m_children[1] == (unsigned int)(((char *)p_m_quad - (char *)v35) / 48);
          v35[v37].m_children[v10] = v36;
        }
        else
        {
          m_treePtr[1].m_nodes.m_size = v36;
        }
        *(_DWORD *)(v19 + 32) = p_m_quad[2].m128_i32[0];
        v38 = (char *)p_m_quad - (char *)m_treePtr->m_nodes.m_data;
        *(_DWORD *)(v19 + 40) = m_firstFree;
        *(_DWORD *)(v19 + 36) = v38 / 48;
        p_m_quad[2].m128_i32[0] = v36;
        m_treePtr->m_nodes.m_data[m_firstFree].m_parent = v36;
        v39 = _mm_max_ps(p_m_quad[1], v16);
        *(__m128 *)v19 = _mm_min_ps(*p_m_quad, m_quad);
        *(__m128 *)(v19 + 16) = v39;
      }
      else
      {
        m_treePtr[1].m_nodes.m_size = m_firstFree;
        v13[m_firstFree].m_parent = 0;
      }
      ++LODWORD(m_treePtr[1].m_nodes.m_data);
    }
    else
    {
      res->m_enum = HK_FAILURE;
      LODWORD(m_firstFree) = -1;
    }
    return (unsigned int)m_firstFree;
  }
  else
  {
    res->m_enum = HK_FAILURE;
    return 0i64;
  }
}

// File Line: 74
// RVA: 0xC8FE50
__int64 __fastcall hkcdDynamicAabbTree::tryInsertPoint(
        hkcdDynamicAabbTree *this,
        hkVector4f *point,
        unsigned int key,
        hkResult *res)
{
  hkAabb aabb; // [rsp+20h] [rbp-28h] BYREF

  aabb.m_min = (hkVector4f)point->m_quad;
  aabb.m_max = aabb.m_min;
  return hkcdDynamicAabbTree::tryInsert(this, &aabb, key, res);
}

// File Line: 80
// RVA: 0xC8FE80
void __fastcall hkcdDynamicAabbTree::update(hkcdDynamicAabbTree *this, int handle, hkAabb *aabb)
{
  hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint> *m_treePtr; // rbx
  hkcdDynamicTree::CodecRawUint *m_data; // rbp
  __int64 m_size; // r9
  __int64 v7; // rsi
  __int64 v8; // rdi
  __m128 m_quad; // xmm3
  __m128 v11; // xmm4
  hkcdDynamicTree::CodecRawUint *v12; // rdx
  unsigned int m_parent; // eax
  hkcdDynamicTree::CodecRawUint *v14; // r8
  unsigned int *p_m_parent; // r11
  __int64 v16; // r8
  hkcdDynamicTree::CodecRawUint *v17; // r8
  __int64 v18; // rcx
  __int64 v19; // r9
  __m128 *p_m_quad; // rdx
  __m128 v21; // xmm2
  __m128 v22; // xmm1
  signed __int64 v23; // rcx
  hkcdDynamicTree::CodecRawUint *v24; // rax
  hkcdDynamicTree::CodecRawUint *v25; // rcx
  __int64 v26; // rbp
  __m128 v27; // xmm7
  __m128 v28; // xmm8
  __int64 m_firstFree; // rdx
  __m128 *v30; // r9
  __int64 v31; // r11
  __int64 v32; // rax
  __m128 v33; // xmm10
  __m128 v34; // xmm9
  __int64 v35; // r8
  __m128 v36; // xmm0
  __m128 v37; // xmm1
  __int64 v38; // rdx
  __m128 *v39; // rdx
  __m128 v40; // xmm3
  __m128 v41; // xmm2
  __m128 v42; // xmm6
  __m128 v43; // xmm3
  __m128 v44; // xmm3
  __m128 v45; // xmm5
  __m128 v46; // xmm5
  hkcdDynamicTree::CodecRawUint *v47; // rbp
  __int64 v48; // r10
  unsigned int v49; // eax
  signed __int64 v50; // rcx
  __m128 v51; // xmm1
  __int64 v52[2]; // [rsp+20h] [rbp-88h]
  hkResult result; // [rsp+B8h] [rbp+10h] BYREF

  m_treePtr = (hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint> *)this->m_treePtr;
  m_data = m_treePtr->m_nodes.m_data;
  m_size = m_treePtr[1].m_nodes.m_size;
  v7 = (unsigned int)handle;
  v8 = 0i64;
  m_quad = m_treePtr->m_nodes.m_data[handle].m_aabb.m_min.m_quad;
  v11 = m_treePtr->m_nodes.m_data[handle].m_aabb.m_max.m_quad;
  if ( handle == (_DWORD)m_size )
  {
    m_treePtr[1].m_nodes.m_size = 0;
  }
  else
  {
    v12 = &m_data[m_data[handle].m_parent];
    m_parent = v12->m_parent;
    v14 = &m_data[v12->m_aabb.m_min.m_quad.m128_u32[10i64 - (v12->m_children[1] == handle)]];
    if ( m_parent )
    {
      v14->m_parent = m_parent;
      p_m_parent = &v14->m_parent;
      m_treePtr->m_nodes.m_data[v12->m_parent].m_children[m_treePtr->m_nodes.m_data[v12->m_parent].m_children[1] == m_data[v7].m_parent] = ((int)v14 - LODWORD(m_treePtr->m_nodes.m_data)) / 48;
      v16 = (int)m_data[v7].m_parent;
      m_treePtr->m_nodes.m_data[v16].m_aabb.m_min.m_quad.m128_i32[0] = m_treePtr->m_firstFree;
      m_treePtr->m_firstFree = v16;
      v17 = m_treePtr->m_nodes.m_data;
      v18 = (__int64)&m_treePtr->m_nodes.m_data[*p_m_parent];
      do
      {
        v19 = *(unsigned int *)(v18 + 32);
        p_m_quad = &v17[((int)v18 - (int)v17) / 48].m_aabb.m_min.m_quad;
        v21 = _mm_min_ps(
                v17[p_m_quad[2].m128_u32[1]].m_aabb.m_min.m_quad,
                v17[p_m_quad[2].m128_u32[2]].m_aabb.m_min.m_quad);
        v22 = _mm_max_ps(
                v17[p_m_quad[2].m128_u32[1]].m_aabb.m_max.m_quad,
                v17[p_m_quad[2].m128_u32[2]].m_aabb.m_max.m_quad);
        *p_m_quad = v21;
        p_m_quad[1] = v22;
        if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v11, v22), _mm_cmple_ps(v21, m_quad))) & 7) == 7 )
          break;
        if ( !(_DWORD)v19 )
          break;
        v17 = m_treePtr->m_nodes.m_data;
        v18 = (__int64)&m_treePtr->m_nodes.m_data[v19];
      }
      while ( v18 );
    }
    else
    {
      m_data[m_size].m_aabb.m_min.m_quad.m128_i32[0] = m_treePtr->m_firstFree;
      v23 = (char *)v14 - (char *)m_treePtr->m_nodes.m_data;
      m_treePtr->m_firstFree = m_size;
      m_treePtr[1].m_nodes.m_size = v23 / 48;
      v14->m_parent = 0;
    }
  }
  v24 = m_treePtr->m_nodes.m_data;
  v24[v7].m_aabb.m_min = aabb->m_min;
  v24[v7].m_aabb.m_max = aabb->m_max;
  v25 = m_treePtr->m_nodes.m_data;
  v26 = (unsigned int)m_treePtr[1].m_nodes.m_size;
  v27 = m_treePtr->m_nodes.m_data[v7].m_aabb.m_min.m_quad;
  v28 = m_treePtr->m_nodes.m_data[v7].m_aabb.m_max.m_quad;
  if ( (_DWORD)v26 )
  {
    if ( !m_treePtr->m_firstFree )
      hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUint>::reserveNodes(
        m_treePtr,
        &result,
        1);
    m_firstFree = m_treePtr->m_firstFree;
    v30 = &m_treePtr->m_nodes.m_data[v26].m_aabb.m_min.m_quad;
    v31 = (__int64)&m_treePtr->m_nodes.m_data[m_firstFree];
    m_treePtr->m_firstFree = m_treePtr->m_nodes.m_data[(int)m_firstFree].m_aabb.m_min.m_quad.m128_u32[0];
    v32 = v30[2].m128_u32[1];
    if ( (_DWORD)v32 )
    {
      v33 = _mm_sub_ps(v28, v27);
      v34 = _mm_add_ps(v28, v27);
      do
      {
        v36 = _mm_min_ps(*v30, v27);
        v37 = _mm_max_ps(v30[1], v28);
        v38 = v30[2].m128_u32[2];
        v52[0] = (__int64)&m_treePtr->m_nodes.m_data[v32];
        v35 = v52[0];
        v39 = &m_treePtr->m_nodes.m_data[v38].m_aabb.m_min.m_quad;
        v52[1] = (__int64)v39;
        *v30 = v36;
        v30[1] = v37;
        v40 = *(__m128 *)(v35 + 16);
        v41 = _mm_add_ps(_mm_sub_ps(v40, *(__m128 *)v35), v33);
        v42 = _mm_add_ps(_mm_sub_ps(v39[1], *v39), v33);
        v43 = _mm_sub_ps(_mm_add_ps(v40, *(__m128 *)v35), v34);
        v44 = _mm_mul_ps(v43, v43);
        v45 = _mm_sub_ps(_mm_add_ps(v39[1], *v39), v34);
        v46 = _mm_mul_ps(v45, v45);
        v30 = (__m128 *)v52[(float)((float)((float)(_mm_shuffle_ps(v41, v41, 85).m128_f32[0]
                                                  + _mm_shuffle_ps(v41, v41, 0).m128_f32[0])
                                          + _mm_shuffle_ps(v41, v41, 170).m128_f32[0])
                                  * (float)((float)(_mm_shuffle_ps(v44, v44, 85).m128_f32[0]
                                                  + _mm_shuffle_ps(v44, v44, 0).m128_f32[0])
                                          + _mm_shuffle_ps(v44, v44, 170).m128_f32[0])) > (float)((float)((float)(_mm_shuffle_ps(v46, v46, 85).m128_f32[0] + _mm_shuffle_ps(v46, v46, 0).m128_f32[0]) + _mm_shuffle_ps(v46, v46, 170).m128_f32[0])
                                                                                                * (float)((float)(_mm_shuffle_ps(v42, v42, 85).m128_f32[0] + _mm_shuffle_ps(v42, v42, 0).m128_f32[0]) + _mm_shuffle_ps(v42, v42, 170).m128_f32[0]))];
        v32 = v30[2].m128_u32[1];
      }
      while ( (_DWORD)v32 );
    }
    v47 = m_treePtr->m_nodes.m_data;
    v48 = (signed __int64)(v31 - (unsigned __int64)m_treePtr->m_nodes.m_data) / 48;
    v49 = v30[2].m128_u32[0];
    if ( v49 )
    {
      LOBYTE(v8) = v47[v49].m_children[1] == (unsigned int)(((char *)v30 - (char *)v47) / 48);
      v47[v49].m_children[v8] = v48;
    }
    else
    {
      m_treePtr[1].m_nodes.m_size = v48;
    }
    *(_DWORD *)(v31 + 32) = v30[2].m128_i32[0];
    v50 = (char *)v30 - (char *)m_treePtr->m_nodes.m_data;
    *(_DWORD *)(v31 + 40) = handle;
    *(_DWORD *)(v31 + 36) = v50 / 48;
    v30[2].m128_i32[0] = v48;
    m_treePtr->m_nodes.m_data[v7].m_parent = v48;
    v51 = _mm_max_ps(v30[1], v28);
    *(__m128 *)v31 = _mm_min_ps(*v30, v27);
    *(__m128 *)(v31 + 16) = v51;
  }
  else
  {
    m_treePtr[1].m_nodes.m_size = handle;
    v25[v7].m_parent = 0;
  }
}

// File Line: 86
// RVA: 0xC90300
void __fastcall hkcdDynamicAabbTree::remove(hkcdDynamicAabbTree *this, int handle)
{
  int *m_treePtr; // r11
  __int64 v3; // rsi
  __int64 v4; // rdi
  __int64 v5; // rdx
  __int64 v6; // r8
  __int64 v7; // rbp
  __m128 v8; // xmm3
  __m128 v9; // xmm4
  __int64 v10; // r14
  int v11; // eax
  __int64 v12; // rbx
  __int64 v13; // r8
  __int64 v14; // r8
  __int64 v15; // r8
  __int64 v16; // rcx
  __int64 v17; // r9
  __m128 *v18; // rdx
  __m128 v19; // xmm2
  __m128 v20; // xmm1
  __int64 v21; // rcx

  m_treePtr = (int *)this->m_treePtr;
  v3 = handle;
  v4 = 0i64;
  v5 = *(_QWORD *)m_treePtr;
  v6 = m_treePtr[8];
  v7 = *(_QWORD *)m_treePtr + 48i64 * (unsigned int)v3;
  v8 = *(__m128 *)v7;
  v9 = *(__m128 *)(v7 + 16);
  if ( (_DWORD)v3 == (_DWORD)v6 )
  {
    m_treePtr[8] = 0;
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
      LOBYTE(v4) = *(_DWORD *)(*(_QWORD *)m_treePtr + 48 * v13 + 40) == *(_DWORD *)(v7 + 32);
      *(_DWORD *)(*(_QWORD *)m_treePtr + 4 * (v4 + 12 * v13) + 36) = ((int)v12 - *m_treePtr) / 48;
      v14 = *(int *)(v7 + 32);
      *(_DWORD *)(*(_QWORD *)m_treePtr + 48 * v14) = m_treePtr[4];
      m_treePtr[4] = v14;
      v15 = *(_QWORD *)m_treePtr;
      v16 = *(_QWORD *)m_treePtr + 48i64 * *(unsigned int *)(v12 + 32);
      do
      {
        v17 = *(unsigned int *)(v16 + 32);
        v18 = (__m128 *)(v15 + 48i64 * (unsigned int)(((int)v16 - (int)v15) / 48));
        v19 = _mm_min_ps(*(__m128 *)(v15 + 48i64 * v18[2].m128_u32[1]), *(__m128 *)(v15 + 48i64 * v18[2].m128_u32[2]));
        v20 = _mm_max_ps(
                *(__m128 *)(v15 + 48i64 * v18[2].m128_u32[1] + 16),
                *(__m128 *)(v15 + 48i64 * v18[2].m128_u32[2] + 16));
        *v18 = v19;
        v18[1] = v20;
        if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v9, v20), _mm_cmple_ps(v19, v8))) & 7) == 7 )
          break;
        if ( !(_DWORD)v17 )
          break;
        v15 = *(_QWORD *)m_treePtr;
        v16 = *(_QWORD *)m_treePtr + 48 * v17;
      }
      while ( v16 );
    }
    else
    {
      *(_DWORD *)(v5 + 48 * v6) = m_treePtr[4];
      v21 = v12 - *(_QWORD *)m_treePtr;
      m_treePtr[4] = v6;
      m_treePtr[8] = v21 / 48;
      *(_DWORD *)(v12 + 32) = 0;
    }
  }
  *(_DWORD *)(*(_QWORD *)m_treePtr + 48 * v3) = m_treePtr[4];
  --m_treePtr[6];
  m_treePtr[4] = v3;
}

// File Line: 92
// RVA: 0xC90570
void __fastcall hkcdDynamicAabbTree::clear(hkcdDynamicAabbTree *this)
{
  char *m_treePtr; // rbx
  int v2; // eax

  m_treePtr = (char *)this->m_treePtr;
  v2 = *((_DWORD *)m_treePtr + 3);
  *((_DWORD *)m_treePtr + 2) = 0;
  if ( v2 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      *(void **)m_treePtr,
      48 * (v2 & 0x3FFFFFFF));
  *(_QWORD *)m_treePtr = 0i64;
  *((_DWORD *)m_treePtr + 3) = 0x80000000;
  *((_DWORD *)m_treePtr + 4) = 0;
  *(_QWORD *)(m_treePtr + 28) = 0i64;
  *((_DWORD *)m_treePtr + 6) = 0;
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
unsigned int __fastcall hkcdDynamicAabbTree::castRay(
        hkcdDynamicAabbTree *this,
        hkVector4f *start,
        hkVector4f *end,
        hkcdAabbTreeQueries::RaycastCollector *collector)
{
  return hkcdAabbTree_castRay<hkcdDynamicTree::DefaultTree48Storage>(this->m_treePtr, start, end, collector);
}

// File Line: 131
// RVA: 0xC90600
void __fastcall hkcdDynamicAabbTree::queryAabb(
        hkcdDynamicAabbTree *this,
        hkAabb *aabb,
        hkcdAabbTreeQueries::AabbCollector *collector)
{
  hkcdAabbTree_queryAabb<hkcdDynamicTree::DefaultTree48Storage>(this->m_treePtr, aabb, collector);
}

// File Line: 136
// RVA: 0xC90610
hkResult *__fastcall hkcdDynamicAabbTree::queryAabb(
        hkcdDynamicAabbTree *this,
        hkResult *result,
        hkAabb *aabb,
        hkArray<unsigned int,hkContainerTempAllocator> *hits)
{
  void *m_treePtr; // rdx

  m_treePtr = this->m_treePtr;
  if ( m_treePtr )
    hkcdAabbTree_queryAabbHits<hkcdDynamicTree::DefaultTree48Storage>(result, m_treePtr, aabb, hits);
  else
    result->m_enum = HK_FAILURE;
  return result;
}

// File Line: 146
// RVA: 0xC90650
unsigned int __fastcall hkcdDynamicAabbTree::getClosestPoint(
        hkcdDynamicAabbTree *this,
        hkVector4f *point,
        hkSimdFloat32 *maxDistance,
        hkcdAabbTreeQueries::ClosestPointCollector *collector,
        hkVector4f *closestPointOut)
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
unsigned int __fastcall hkcdDynamicAabbTree::getClosestPoint(
        hkcdDynamicAabbTree *this,
        hkVector4f *point,
        hkSimdFloat32 *maxDistance,
        hkVector4f *closestPointOut)
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
void __fastcall hkcdDynamicAabbTree::getAllPairs(
        hkcdDynamicAabbTree *this,
        hkcdAabbTreeQueries::AllPairsCollector *collector)
{
  hkcdAabbTree_getAllPairs<hkcdDynamicTree::DefaultTree48Storage>(this->m_treePtr, collector);
}

// File Line: 161
// RVA: 0xC90690
void __fastcall hkcdDynamicAabbTree::getAllPairs(
        hkcdDynamicAabbTree *this,
        hkcdDynamicAabbTree *otherTree,
        hkcdAabbTreeQueries::AllPairsCollector *collector)
{
  hkcdAabbTree_getAllPairs<hkcdDynamicTree::DefaultTree48Storage>(this->m_treePtr, otherTree->m_treePtr, collector);
}

// File Line: 166
// RVA: 0xC906B0
__int64 __fastcall hkcdDynamicAabbTree::getMemoryFootPrint(hkcdDynamicAabbTree *this)
{
  return 48i64 * (unsigned int)(2 * *((_DWORD *)this->m_treePtr + 6) - 1) + 40;
}

// File Line: 172
// RVA: 0xC906E0
__int64 __fastcall hkcdDynamicAabbTree::getNumLeaves(hkcdDynamicAabbTree *this)
{
  return (unsigned int)((*((_DWORD *)this->m_treePtr + 2) + 1) / 2);
}

