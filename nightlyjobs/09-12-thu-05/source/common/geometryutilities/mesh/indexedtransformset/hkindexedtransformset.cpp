// File Line: 22
// RVA: 0x131A140
void __fastcall hkIndexedTransformSetCinfo::hkIndexedTransformSetCinfo(hkIndexedTransformSetCinfo *this)
{
  this->m_inverseMatrices = 0i64;
  this->m_matrices = 0i64;
  this->m_matricesOrder = 0i64;
  this->m_matricesNames = 0i64;
  this->m_numMatrices = 0;
  this->m_allTransformsAreAffine.m_bool = 1;
  this->m_indexMappings = 0i64;
  this->m_numIndexMappings = 0;
}

// File Line: 32
// RVA: 0x131B5C0
void __fastcall hkIndexedTransformSet::hkIndexedTransformSet(
        hkIndexedTransformSet *this,
        hkFinishLoadedObjectFlag flag)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkIndexedTransformSet::`vftable;
}

// File Line: 36
// RVA: 0x131A170
void __fastcall hkIndexedTransformSet::hkIndexedTransformSet(
        hkIndexedTransformSet *this,
        hkIndexedTransformSetCinfo *info)
{
  int v2; // ebx
  hkArray<hkMatrix4f,hkContainerHeapAllocator> *p_m_matrices; // rdi
  hkArray<hkMatrix4f,hkContainerHeapAllocator> *p_m_inverseMatrices; // rsi
  hkArray<hkStringPtr,hkContainerHeapAllocator> *p_m_matricesNames; // rbp
  hkArray<hkMeshBoneIndexMapping,hkContainerHeapAllocator> *p_m_indexMappings; // r12
  __int64 m_numMatrices; // r15
  hkMatrix4f *m_matrices; // r9
  __int64 v11; // rcx
  __int64 v12; // rdx
  hkMatrix4f *m_data; // rax
  __m128 *p_m_quad; // r10
  int i; // r11d
  int v16; // edx
  int v17; // r8d
  int v18; // eax
  __m128 *v19; // r10
  hkMatrix4f *m_inverseMatrices; // r9
  int j; // r11d
  int v22; // edx
  int v23; // r8d
  int v24; // eax
  __int16 *v25; // rcx
  int v26; // edi
  hkStringPtr *v27; // rsi
  int v28; // edx
  hkStringPtr *v29; // rdi
  __int64 v30; // rsi
  __int64 v31; // rdi
  __int64 v32; // rsi
  int m_numIndexMappings; // r9d
  __int64 v34; // rbp
  int v35; // eax
  __int64 v36; // rsi
  int *v37; // rdi
  int v38; // r8d
  __int64 m_size; // rdx
  int v40; // ecx
  __int64 v41; // rax
  __int64 v42; // rdx
  hkResult result; // [rsp+78h] [rbp+10h] BYREF

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  v2 = 0;
  p_m_matrices = &this->m_matrices;
  p_m_inverseMatrices = &this->m_inverseMatrices;
  p_m_matricesNames = &this->m_matricesNames;
  p_m_indexMappings = &this->m_indexMappings;
  this->vfptr = (hkBaseObjectVtbl *)&hkIndexedTransformSet::`vftable;
  this->m_matrices.m_data = 0i64;
  this->m_matrices.m_size = 0;
  this->m_matrices.m_capacityAndFlags = 0x80000000;
  this->m_inverseMatrices.m_data = 0i64;
  this->m_inverseMatrices.m_size = 0;
  this->m_inverseMatrices.m_capacityAndFlags = 0x80000000;
  this->m_matricesOrder.m_data = 0i64;
  this->m_matricesOrder.m_size = 0;
  this->m_matricesOrder.m_capacityAndFlags = 0x80000000;
  this->m_matricesNames.m_data = 0i64;
  this->m_matricesNames.m_size = 0;
  this->m_matricesNames.m_capacityAndFlags = 0x80000000;
  this->m_indexMappings.m_data = 0i64;
  this->m_indexMappings.m_size = 0;
  this->m_indexMappings.m_capacityAndFlags = 0x80000000;
  m_numMatrices = (unsigned int)info->m_numMatrices;
  if ( (this->m_matrices.m_capacityAndFlags & 0x3FFFFFFF) < (int)m_numMatrices )
    hkArrayUtil::_reserve(
      &result,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&p_m_matrices->m_data,
      m_numMatrices,
      64);
  this->m_matrices.m_size = m_numMatrices;
  m_matrices = info->m_matrices;
  if ( m_matrices )
  {
    p_m_quad = &p_m_matrices->m_data->m_col0.m_quad;
    for ( i = 0; i < 4 * (int)m_numMatrices; m_matrices = (hkMatrix4f *)((char *)m_matrices + 16) )
    {
      v16 = m_matrices->m_col0.m_quad.m128_i32[2];
      v17 = m_matrices->m_col0.m_quad.m128_i32[3];
      v18 = m_matrices->m_col0.m_quad.m128_i32[0];
      ++i;
      p_m_quad->m128_i32[1] = m_matrices->m_col0.m_quad.m128_i32[1];
      p_m_quad->m128_i32[2] = v16;
      p_m_quad->m128_i32[3] = v17;
      p_m_quad->m128_i32[0] = v18;
      ++p_m_quad;
    }
  }
  else if ( (int)m_numMatrices > 0 )
  {
    v11 = 0i64;
    v12 = (int)m_numMatrices;
    do
    {
      m_data = p_m_matrices->m_data;
      m_data[v11++].m_col0 = (hkVector4f)transform.m_quad;
      m_data[v11 - 1].m_col1 = (hkVector4f)direction.m_quad;
      m_data[v11 - 1].m_col2 = (hkVector4f)stru_141A71280.m_quad;
      m_data[v11 - 1].m_col3 = (hkVector4f)qi.m_vec.m_quad;
      --v12;
    }
    while ( v12 );
  }
  if ( info->m_inverseMatrices )
  {
    if ( (p_m_inverseMatrices->m_capacityAndFlags & 0x3FFFFFFF) < (int)m_numMatrices )
      hkArrayUtil::_reserve(
        &result,
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&p_m_inverseMatrices->m_data,
        m_numMatrices,
        64);
    v19 = &p_m_inverseMatrices->m_data->m_col0.m_quad;
    this->m_inverseMatrices.m_size = m_numMatrices;
    m_inverseMatrices = info->m_inverseMatrices;
    for ( j = 0; j < 4 * (int)m_numMatrices; m_inverseMatrices = (hkMatrix4f *)((char *)m_inverseMatrices + 16) )
    {
      v22 = m_inverseMatrices->m_col0.m_quad.m128_i32[2];
      v23 = m_inverseMatrices->m_col0.m_quad.m128_i32[3];
      v24 = m_inverseMatrices->m_col0.m_quad.m128_i32[0];
      ++j;
      v19->m128_i32[1] = m_inverseMatrices->m_col0.m_quad.m128_i32[1];
      v19->m128_i32[2] = v22;
      v19->m128_i32[3] = v23;
      v19->m128_i32[0] = v24;
      ++v19;
    }
  }
  this->m_allMatricesAreAffine.m_bool = info->m_allTransformsAreAffine.m_bool;
  if ( info->m_matricesOrder )
  {
    if ( (this->m_matricesOrder.m_capacityAndFlags & 0x3FFFFFFF) < (int)m_numMatrices )
      hkArrayUtil::_reserve(
        &result,
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&this->m_matricesOrder.m_data,
        m_numMatrices,
        2);
    v25 = this->m_matricesOrder.m_data;
    this->m_matricesOrder.m_size = m_numMatrices;
    hkString::memCpy(v25, info->m_matricesOrder, 2 * m_numMatrices);
  }
  if ( info->m_matricesNames )
  {
    if ( (p_m_matricesNames->m_capacityAndFlags & 0x3FFFFFFF) < (int)m_numMatrices )
      hkArrayUtil::_reserve(
        &result,
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&p_m_matricesNames->m_data,
        m_numMatrices,
        8);
    v26 = p_m_matricesNames->m_size - m_numMatrices - 1;
    if ( v26 >= 0 )
    {
      v27 = &p_m_matricesNames->m_data[(int)m_numMatrices + v26];
      do
      {
        hkStringPtr::~hkStringPtr(v27--);
        --v26;
      }
      while ( v26 >= 0 );
    }
    v28 = m_numMatrices - p_m_matricesNames->m_size;
    v29 = &p_m_matricesNames->m_data[p_m_matricesNames->m_size];
    if ( v28 > 0 )
    {
      v30 = (unsigned int)v28;
      do
      {
        if ( v29 )
          hkStringPtr::hkStringPtr(v29);
        ++v29;
        --v30;
      }
      while ( v30 );
    }
    p_m_matricesNames->m_size = m_numMatrices;
    if ( (int)m_numMatrices > 0 )
    {
      v31 = 0i64;
      v32 = m_numMatrices;
      do
      {
        hkStringPtr::operator=(&p_m_matricesNames->m_data[v31], &info->m_matricesNames[v31]);
        ++v31;
        --v32;
      }
      while ( v32 );
    }
  }
  if ( info->m_indexMappings )
  {
    m_numIndexMappings = info->m_numIndexMappings;
    if ( (p_m_indexMappings->m_capacityAndFlags & 0x3FFFFFFF) < m_numIndexMappings )
      hkArrayUtil::_reserve(
        &result,
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&p_m_indexMappings->m_data,
        m_numIndexMappings,
        16);
    v34 = info->m_numIndexMappings;
    v35 = p_m_indexMappings->m_size - v34 - 1;
    v36 = v35;
    if ( v35 >= 0 )
    {
      v37 = &p_m_indexMappings->m_data[v34].m_mapping.m_capacityAndFlags + 4 * v35;
      do
      {
        v38 = *v37;
        *(v37 - 1) = 0;
        if ( v38 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            *(void **)(v37 - 3),
            2 * (v38 & 0x3FFFFFFF));
        *(_QWORD *)(v37 - 3) = 0i64;
        *v37 = 0x80000000;
        v37 -= 4;
        --v36;
      }
      while ( v36 >= 0 );
    }
    m_size = p_m_indexMappings->m_size;
    v40 = v34 - m_size;
    v41 = (int)v34 - (int)m_size;
    v42 = (__int64)&p_m_indexMappings->m_data[m_size];
    if ( v40 > 0 )
    {
      do
      {
        if ( v42 )
        {
          *(_QWORD *)v42 = 0i64;
          *(_DWORD *)(v42 + 8) = 0;
          *(_DWORD *)(v42 + 12) = 0x80000000;
        }
        v42 += 16i64;
        --v41;
      }
      while ( v41 );
    }
    p_m_indexMappings->m_size = v34;
    if ( info->m_numIndexMappings > 0 )
    {
      do
      {
        hkMeshBoneIndexMapping::operator=(&p_m_indexMappings->m_data[v2], &info->m_indexMappings[v2]);
        ++v2;
      }
      while ( v2 < info->m_numIndexMappings );
    }
  }
}exMappings->m_data[v2], &info->m_indexMappings[v2]);
        ++v2;
      }
      while ( v2 < info->m_numIndexMappings );
    }
  }
}

// File Line: 100
// RVA: 0x131A5C0
void __fastcall hkIndexedTransformSet::setMatrices(
        hkIndexedTransformSet *this,
        int startIndex,
        hkMatrix4f *matrices,
        int numMatrices)
{
  hkMatrix4f *v4; // rax
  unsigned __int64 *v5; // r10
  __int64 v6; // r11
  int v7; // r8d
  int v8; // r9d
  int v9; // ecx

  if ( numMatrices > 0 )
  {
    v4 = &this->m_matrices.m_data[(__int64)startIndex];
    if ( 4 * numMatrices > 0 )
    {
      v5 = &matrices->m_col0.m_quad.m128_u64[1];
      v6 = (unsigned int)(4 * numMatrices);
      do
      {
        v7 = *(_DWORD *)v5;
        v8 = *((_DWORD *)v5 + 1);
        v9 = *((_DWORD *)v5 - 2);
        v4->m_col0.m_quad.m128_i32[1] = *((_DWORD *)v5 - 1);
        v4->m_col0.m_quad.m128_i32[2] = v7;
        v4->m_col0.m_quad.m128_i32[3] = v8;
        v4->m_col0.m_quad.m128_i32[0] = v9;
        v4 = (hkMatrix4f *)((char *)v4 + 16);
        v5 += 2;
        --v6;
      }
      while ( v6 );
    }
  }
}

// File Line: 111
// RVA: 0x131A7B0
void __fastcall hkIndexedTransformSet::calculateMatrices(
        hkIndexedTransformSet *this,
        hkArray<hkMatrix4f,hkContainerHeapAllocator> *matricesOut)
{
  __int64 m_size; // rbx
  int v4; // eax
  int v6; // eax
  int v7; // r9d
  hkMatrix4f *m_data; // rcx
  hkMatrix4f *v9; // rax
  __int64 v10; // r9
  signed __int64 v11; // rcx
  hkVector4f *p_m_col2; // r8
  __int64 v13; // rdx
  __m128 m_quad; // xmm2
  __m128 v15; // xmm7
  __m128 v16; // xmm6
  __m128 *v17; // rax
  __m128 v18; // xmm8
  __m128 v19; // xmm9
  __m128 v20; // xmm10
  __m128 v21; // xmm2
  __m128 v22; // xmm5
  __m128 v23; // xmm2
  __m128 v24; // xmm4
  __m128 v25; // xmm2
  hkMatrix4f *v26; // r10
  int v27; // ebx
  int *v28; // rax
  __int64 v29; // r11
  int v30; // r8d
  int v31; // r9d
  int v32; // ecx
  hkResult result; // [rsp+90h] [rbp+8h] BYREF

  m_size = this->m_matrices.m_size;
  v4 = matricesOut->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v4 < (int)m_size )
  {
    v6 = 2 * v4;
    v7 = this->m_matrices.m_size;
    if ( (int)m_size < v6 )
      v7 = v6;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&matricesOut->m_data, v7, 64);
  }
  matricesOut->m_size = m_size;
  m_data = this->m_matrices.m_data;
  if ( this->m_inverseMatrices.m_size <= 0 )
  {
    v26 = matricesOut->m_data;
    v27 = 4 * m_size;
    if ( v27 > 0 )
    {
      v28 = &m_data->m_col0.m_quad.m128_i32[2];
      v29 = (unsigned int)v27;
      do
      {
        v30 = *v28;
        v31 = v28[1];
        v32 = *(v28 - 2);
        v26->m_col0.m_quad.m128_i32[1] = *(v28 - 1);
        v26->m_col0.m_quad.m128_i32[2] = v30;
        v26->m_col0.m_quad.m128_i32[3] = v31;
        v26->m_col0.m_quad.m128_i32[0] = v32;
        v26 = (hkMatrix4f *)((char *)v26 + 16);
        v28 += 4;
        --v29;
      }
      while ( v29 );
    }
  }
  else
  {
    v9 = this->m_inverseMatrices.m_data;
    v10 = m_size;
    if ( (int)m_size > 0 )
    {
      v11 = (char *)m_data - (char *)v9;
      p_m_col2 = &v9->m_col2;
      v13 = -32i64 - (_QWORD)v9;
      do
      {
        m_quad = p_m_col2[-1].m_quad;
        v15 = *(__m128 *)((char *)&p_m_col2[-1].m_quad + v11);
        v16 = *(__m128 *)((char *)&p_m_col2[-2].m_quad + v11);
        v17 = (__m128 *)((char *)&matricesOut->m_data->m_col0.m_quad + (unsigned __int64)p_m_col2 + v13);
        v18 = *(__m128 *)((char *)&p_m_col2->m_quad + v11);
        v19 = *(__m128 *)((char *)&p_m_col2[1].m_quad + v11);
        p_m_col2 += 4;
        v20 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 0), v16),
                    _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 85), v15)),
                  _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 170), v18)),
                _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 255), v19));
        v21 = p_m_col2[-4].m_quad;
        v22 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v21, v21, 0), v16),
                    _mm_mul_ps(_mm_shuffle_ps(v21, v21, 85), v15)),
                  _mm_mul_ps(_mm_shuffle_ps(v21, v21, 170), v18)),
                _mm_mul_ps(_mm_shuffle_ps(v21, v21, 255), v19));
        v23 = p_m_col2[-3].m_quad;
        v24 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v23, v23, 0), v16),
                    _mm_mul_ps(_mm_shuffle_ps(v23, v23, 85), v15)),
                  _mm_mul_ps(_mm_shuffle_ps(v23, v23, 170), v18)),
                _mm_mul_ps(_mm_shuffle_ps(v23, v23, 255), v19));
        v25 = p_m_col2[-6].m_quad;
        v17[1] = v20;
        v17[2] = v22;
        v17[3] = v24;
        *v17 = _mm_add_ps(
                 _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v25, v25, 0), v16),
                     _mm_mul_ps(_mm_shuffle_ps(v25, v25, 85), v15)),
                   _mm_mul_ps(_mm_shuffle_ps(v25, v25, 170), v18)),
                 _mm_mul_ps(_mm_shuffle_ps(v25, v25, 255), v19));
        --v10;
      }
      while ( v10 );
    }
  }
}

// File Line: 132
// RVA: 0x131A9F0
void __fastcall hkIndexedTransformSet::calculateMatrices(
        hkIndexedTransformSet *this,
        hkMatrix4f *parentToWorld,
        hkArray<hkMatrix4f,hkContainerHeapAllocator> *matricesOut)
{
  __int64 m_size; // rsi
  int v4; // eax
  int v8; // eax
  int v9; // r9d
  hkMatrix4f *m_data; // rcx
  hkVector4f v11; // xmm2
  hkVector4f v12; // xmm1
  hkMatrix4f *v13; // r10
  __int64 v14; // rdx
  hkMatrix4f *v15; // r8
  signed __int64 v16; // r10
  hkVector4f *p_m_col2; // rax
  signed __int64 v18; // rcx
  __m128 m_quad; // xmm2
  __m128 v20; // xmm7
  __m128 v21; // xmm6
  __m128 v22; // xmm8
  __m128 v23; // xmm9
  __m128 v24; // xmm10
  __m128 v25; // xmm2
  __m128 v26; // xmm5
  __m128 v27; // xmm2
  __m128 v28; // xmm4
  __m128 v29; // xmm2
  int v30; // esi
  int *v31; // r9
  signed __int64 v32; // r10
  __int64 v33; // r11
  int v34; // edx
  int v35; // r8d
  int v36; // eax
  char *v37; // rax
  hkVector4f *v38; // r8
  signed __int64 v39; // rcx
  __m128 v40; // xmm2
  hkVector4f v41; // xmm5
  hkVector4f v42; // xmm6
  hkVector4f v43; // xmm4
  __m128 v44; // xmm9
  __m128 v45; // xmm11
  __m128 v46; // xmm7
  __m128 v47; // xmm2
  __m128 v48; // xmm15
  __m128 v49; // xmm14
  __m128 v50; // xmm2
  __m128 v51; // xmm13
  __m128 v52; // xmm2
  __m128 v53; // xmm4
  __m128 v54; // xmm2
  hkVector4f *v55; // rax
  signed __int64 v56; // rcx
  __m128 v57; // xmm2
  hkVector4f v58; // xmm7
  hkVector4f v59; // xmm6
  hkVector4f v60; // xmm8
  hkVector4f v61; // xmm9
  __m128 v62; // xmm10
  __m128 v63; // xmm2
  __m128 v64; // xmm5
  __m128 v65; // xmm2
  __m128 v66; // xmm4
  __m128 v67; // xmm2
  hkResult v68; // [rsp+F0h] [rbp+8h] BYREF

  m_size = this->m_matrices.m_size;
  v4 = matricesOut->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v4 < (int)m_size )
  {
    v8 = 2 * v4;
    v9 = this->m_matrices.m_size;
    if ( (int)m_size < v8 )
      v9 = v8;
    hkArrayUtil::_reserve(&v68, &hkContainerHeapAllocator::s_alloc, (const void **)&matricesOut->m_data, v9, 64);
  }
  m_data = matricesOut->m_data;
  matricesOut->m_size = m_size;
  v11.m_quad = (__m128)parentToWorld->m_col0;
  v12.m_quad = (__m128)parentToWorld->m_col2;
  v13 = this->m_matrices.m_data;
  v68.m_enum = LODWORD(FLOAT_0_0000099999997);
  v14 = m_size;
  if ( _mm_movemask_ps(
         _mm_cmple_ps(
           _mm_max_ps(
             _mm_max_ps(
               (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(v11.m_quad, transform.m_quad), 1u), 1u),
               (__m128)_mm_srli_epi32(
                         _mm_slli_epi32((__m128i)_mm_sub_ps(parentToWorld->m_col1.m_quad, direction.m_quad), 1u),
                         1u)),
             _mm_max_ps(
               (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(v12.m_quad, stru_141A71280.m_quad), 1u), 1u),
               (__m128)_mm_srli_epi32(
                         _mm_slli_epi32((__m128i)_mm_sub_ps(parentToWorld->m_col3.m_quad, qi.m_vec.m_quad), 1u),
                         1u))),
           _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_0000099999997), (__m128)LODWORD(FLOAT_0_0000099999997), 0))) == 15 )
  {
    if ( this->m_inverseMatrices.m_size <= 0 )
    {
      v30 = 4 * m_size;
      if ( v30 > 0 )
      {
        v31 = &m_data->m_col0.m_quad.m128_i32[2];
        v32 = (char *)v13 - (char *)m_data;
        v33 = (unsigned int)v30;
        do
        {
          v34 = *(int *)((char *)v31 + v32);
          v35 = *(int *)((char *)v31 + v32 + 4);
          v36 = *(int *)((char *)v31 + v32 - 8);
          *(v31 - 1) = *(int *)((char *)v31 + v32 - 4);
          *v31 = v34;
          v31[1] = v35;
          *(v31 - 2) = v36;
          v31 += 4;
          --v33;
        }
        while ( v33 );
      }
    }
    else
    {
      v15 = this->m_inverseMatrices.m_data;
      if ( (int)m_size > 0 )
      {
        v16 = (char *)v13 - (char *)v15;
        p_m_col2 = &v15->m_col2;
        v18 = (char *)m_data - (char *)v15;
        do
        {
          m_quad = p_m_col2[-1].m_quad;
          v20 = *(__m128 *)((char *)&p_m_col2[-1].m_quad + v16);
          v21 = *(__m128 *)((char *)&p_m_col2[-2].m_quad + v16);
          v22 = *(__m128 *)((char *)&p_m_col2->m_quad + v16);
          v23 = *(__m128 *)((char *)&p_m_col2[1].m_quad + v16);
          p_m_col2 += 4;
          v24 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 0), v21),
                      _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 85), v20)),
                    _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 170), v22)),
                  _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 255), v23));
          v25 = p_m_col2[-4].m_quad;
          v26 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v25, v25, 0), v21),
                      _mm_mul_ps(_mm_shuffle_ps(v25, v25, 85), v20)),
                    _mm_mul_ps(_mm_shuffle_ps(v25, v25, 170), v22)),
                  _mm_mul_ps(_mm_shuffle_ps(v25, v25, 255), v23));
          v27 = p_m_col2[-3].m_quad;
          v28 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v27, v27, 0), v21),
                      _mm_mul_ps(_mm_shuffle_ps(v27, v27, 85), v20)),
                    _mm_mul_ps(_mm_shuffle_ps(v27, v27, 170), v22)),
                  _mm_mul_ps(_mm_shuffle_ps(v27, v27, 255), v23));
          v29 = p_m_col2[-6].m_quad;
          *(__m128 *)((char *)p_m_col2 + v18 - 80) = v24;
          *(__m128 *)((char *)p_m_col2 + v18 - 64) = v26;
          *(__m128 *)((char *)p_m_col2 + v18 - 48) = v28;
          *(__m128 *)((char *)&p_m_col2[-6].m_quad + v18) = _mm_add_ps(
                                                              _mm_add_ps(
                                                                _mm_add_ps(
                                                                  _mm_mul_ps(_mm_shuffle_ps(v29, v29, 0), v21),
                                                                  _mm_mul_ps(_mm_shuffle_ps(v29, v29, 85), v20)),
                                                                _mm_mul_ps(_mm_shuffle_ps(v29, v29, 170), v22)),
                                                              _mm_mul_ps(_mm_shuffle_ps(v29, v29, 255), v23));
          --v14;
        }
        while ( v14 );
      }
    }
  }
  else if ( this->m_inverseMatrices.m_size <= 0 )
  {
    if ( (int)m_size > 0 )
    {
      v55 = &v13->m_col2;
      v56 = (char *)m_data - (char *)v13;
      do
      {
        v57 = v55[-1].m_quad;
        v58.m_quad = (__m128)parentToWorld->m_col1;
        v59.m_quad = (__m128)parentToWorld->m_col0;
        v55 += 4;
        v60.m_quad = (__m128)parentToWorld->m_col2;
        v61.m_quad = (__m128)parentToWorld->m_col3;
        v62 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v57, v57, 0), parentToWorld->m_col0.m_quad),
                    _mm_mul_ps(_mm_shuffle_ps(v57, v57, 85), v58.m_quad)),
                  _mm_mul_ps(_mm_shuffle_ps(v57, v57, 170), v60.m_quad)),
                _mm_mul_ps(_mm_shuffle_ps(v57, v57, 255), v61.m_quad));
        v63 = v55[-4].m_quad;
        v64 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v63, v63, 0), parentToWorld->m_col0.m_quad),
                    _mm_mul_ps(_mm_shuffle_ps(v63, v63, 85), v58.m_quad)),
                  _mm_mul_ps(_mm_shuffle_ps(v63, v63, 170), v60.m_quad)),
                _mm_mul_ps(_mm_shuffle_ps(v63, v63, 255), v61.m_quad));
        v65 = v55[-3].m_quad;
        v66 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v65, v65, 0), parentToWorld->m_col0.m_quad),
                    _mm_mul_ps(_mm_shuffle_ps(v65, v65, 85), v58.m_quad)),
                  _mm_mul_ps(_mm_shuffle_ps(v65, v65, 170), v60.m_quad)),
                _mm_mul_ps(_mm_shuffle_ps(v65, v65, 255), v61.m_quad));
        v67 = v55[-6].m_quad;
        *(__m128 *)((char *)v55 + v56 - 80) = v62;
        *(__m128 *)((char *)v55 + v56 - 64) = v64;
        *(__m128 *)((char *)v55 + v56 - 48) = v66;
        *(__m128 *)((char *)&v55[-6].m_quad + v56) = _mm_add_ps(
                                                       _mm_add_ps(
                                                         _mm_add_ps(
                                                           _mm_mul_ps(_mm_shuffle_ps(v67, v67, 0), v59.m_quad),
                                                           _mm_mul_ps(_mm_shuffle_ps(v67, v67, 85), v58.m_quad)),
                                                         _mm_mul_ps(_mm_shuffle_ps(v67, v67, 170), v60.m_quad)),
                                                       _mm_mul_ps(_mm_shuffle_ps(v67, v67, 255), v61.m_quad));
        --v14;
      }
      while ( v14 );
    }
  }
  else if ( (int)m_size > 0 )
  {
    v37 = (char *)((char *)this->m_inverseMatrices.m_data - (char *)v13);
    v38 = &v13->m_col2;
    v39 = (char *)m_data - (char *)v13;
    do
    {
      v40 = v38[-2].m_quad;
      v41.m_quad = (__m128)parentToWorld->m_col2;
      v42.m_quad = (__m128)parentToWorld->m_col3;
      v43.m_quad = (__m128)parentToWorld->m_col1;
      v44 = *(__m128 *)((char *)&v38[-1].m_quad + (_QWORD)v37);
      v45 = *(__m128 *)((char *)&v38[1].m_quad + (_QWORD)v37);
      v46 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v40, v40, 0), parentToWorld->m_col0.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(v40, v40, 85), v43.m_quad)),
                _mm_mul_ps(_mm_shuffle_ps(v40, v40, 170), v41.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v40, v40, 255), v42.m_quad));
      v47 = v38[-1].m_quad;
      v48 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v47, v47, 0), parentToWorld->m_col0.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(v47, v47, 85), v43.m_quad)),
                _mm_mul_ps(_mm_shuffle_ps(v47, v47, 170), v41.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v47, v47, 255), v42.m_quad));
      v49 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v38->m_quad, v38->m_quad, 0), parentToWorld->m_col0.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(v38->m_quad, v38->m_quad, 85), v43.m_quad)),
                _mm_mul_ps(_mm_shuffle_ps(v38->m_quad, v38->m_quad, 170), v41.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v38->m_quad, v38->m_quad, 255), v42.m_quad));
      v50 = v38[1].m_quad;
      v51 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v50, v50, 0), parentToWorld->m_col0.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(v50, v50, 85), v43.m_quad)),
                _mm_mul_ps(_mm_shuffle_ps(v50, v50, 170), v41.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v50, v50, 255), v42.m_quad));
      v52 = *(__m128 *)((char *)&v38->m_quad + (_QWORD)v37);
      v38 += 4;
      v53 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v52, v52, 85), v48), _mm_mul_ps(_mm_shuffle_ps(v52, v52, 0), v46)),
                _mm_mul_ps(_mm_shuffle_ps(v52, v52, 170), v49)),
              _mm_mul_ps(_mm_shuffle_ps(v52, v52, 255), v51));
      v54 = *(__m128 *)((char *)&v38[-6].m_quad + (_QWORD)v37);
      *(__m128 *)((char *)v38 + v39 - 64) = v53;
      *(__m128 *)((char *)&v38[-6].m_quad + v39) = _mm_add_ps(
                                                     _mm_add_ps(
                                                       _mm_add_ps(
                                                         _mm_mul_ps(_mm_shuffle_ps(v54, v54, 85), v48),
                                                         _mm_mul_ps(_mm_shuffle_ps(v54, v54, 0), v46)),
                                                       _mm_mul_ps(_mm_shuffle_ps(v54, v54, 170), v49)),
                                                     _mm_mul_ps(_mm_shuffle_ps(v54, v54, 255), v51));
      *(__m128 *)((char *)&v38[-5].m_quad + v39) = _mm_add_ps(
                                                     _mm_add_ps(
                                                       _mm_add_ps(
                                                         _mm_mul_ps(_mm_shuffle_ps(v44, v44, 0), v46),
                                                         _mm_mul_ps(_mm_shuffle_ps(v44, v44, 85), v48)),
                                                       _mm_mul_ps(_mm_shuffle_ps(v44, v44, 170), v49)),
                                                     _mm_mul_ps(_mm_shuffle_ps(v44, v44, 255), v51));
      *(__m128 *)((char *)&v38[-3].m_quad + v39) = _mm_add_ps(
                                                     _mm_add_ps(
                                                       _mm_add_ps(
                                                         _mm_mul_ps(_mm_shuffle_ps(v45, v45, 0), v46),
                                                         _mm_mul_ps(_mm_shuffle_ps(v45, v45, 85), v48)),
                                                       _mm_mul_ps(_mm_shuffle_ps(v45, v45, 170), v49)),
                                                     _mm_mul_ps(_mm_shuffle_ps(v45, v45, 255), v51));
      --v14;
    }
    while ( v14 );
  }
}

// File Line: 183
// RVA: 0x131B070
void __fastcall hkIndexedTransformSet::calculateMatrix(hkIndexedTransformSet *this, int index, hkMatrix4f *matrixOut)
{
  hkMatrix4f *m_data; // r9
  hkMatrix4f *v4; // rax
  __int64 v5; // rdx
  __m128 v6; // xmm2
  __m128 v7; // xmm7
  __m128 v8; // xmm6
  __m128 v9; // xmm8
  __m128 v10; // xmm9
  hkVector4f v11; // xmm10
  __m128 v12; // xmm2
  hkVector4f v13; // xmm5
  __m128 v14; // xmm2
  hkVector4f v15; // xmm4
  __m128 v16; // xmm2

  m_data = this->m_matrices.m_data;
  if ( this->m_inverseMatrices.m_size <= 0 )
  {
    *matrixOut = m_data[(__int64)index];
  }
  else
  {
    v4 = this->m_inverseMatrices.m_data;
    v5 = (__int64)index << 6;
    v6 = *(__m128 *)((char *)&v4->m_col1.m_quad + v5);
    v7 = *(__m128 *)((char *)&m_data->m_col1.m_quad + v5);
    v8 = *(__m128 *)((char *)&m_data->m_col0.m_quad + v5);
    v9 = *(__m128 *)((char *)&m_data->m_col2.m_quad + v5);
    v10 = *(__m128 *)((char *)&m_data->m_col3.m_quad + v5);
    v11.m_quad = _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v6, v6, 0), v8), _mm_mul_ps(_mm_shuffle_ps(v6, v6, 85), v7)),
                     _mm_mul_ps(_mm_shuffle_ps(v6, v6, 170), v9)),
                   _mm_mul_ps(_mm_shuffle_ps(v6, v6, 255), v10));
    v12 = *(__m128 *)((char *)&v4->m_col2.m_quad + v5);
    v13.m_quad = _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v12, v12, 0), v8),
                       _mm_mul_ps(_mm_shuffle_ps(v12, v12, 85), v7)),
                     _mm_mul_ps(_mm_shuffle_ps(v12, v12, 170), v9)),
                   _mm_mul_ps(_mm_shuffle_ps(v12, v12, 255), v10));
    v14 = *(__m128 *)((char *)&v4->m_col3.m_quad + v5);
    v15.m_quad = _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v14, v14, 0), v8),
                       _mm_mul_ps(_mm_shuffle_ps(v14, v14, 85), v7)),
                     _mm_mul_ps(_mm_shuffle_ps(v14, v14, 170), v9)),
                   _mm_mul_ps(_mm_shuffle_ps(v14, v14, 255), v10));
    v16 = *(__m128 *)((char *)&v4->m_col0.m_quad + v5);
    matrixOut->m_col1 = (hkVector4f)v11.m_quad;
    matrixOut->m_col2 = (hkVector4f)v13.m_quad;
    matrixOut->m_col3 = (hkVector4f)v15.m_quad;
    matrixOut->m_col0.m_quad = _mm_add_ps(
                                 _mm_add_ps(
                                   _mm_add_ps(
                                     _mm_mul_ps(_mm_shuffle_ps(v16, v16, 0), v8),
                                     _mm_mul_ps(_mm_shuffle_ps(v16, v16, 85), v7)),
                                   _mm_mul_ps(_mm_shuffle_ps(v16, v16, 170), v9)),
                                 _mm_mul_ps(_mm_shuffle_ps(v16, v16, 255), v10));
  }
}

// File Line: 197
// RVA: 0x131B210
void __fastcall hkIndexedTransformSet::calculateMatrix(
        hkIndexedTransformSet *this,
        hkMatrix4f *parentToWorld,
        int index,
        hkMatrix4f *matrixOut)
{
  hkMatrix4f *m_data; // r10
  hkVector4f v5; // xmm4
  hkVector4f v6; // xmm5
  __int64 v7; // r8
  __m128 v8; // xmm2
  hkVector4f v9; // xmm6
  hkMatrix4f *v10; // rax
  __m128 v11; // xmm11
  __m128 v12; // xmm12
  __m128 v13; // xmm7
  __m128 v14; // xmm2
  __m128 v15; // xmm15
  __m128 v16; // xmm2
  __m128 v17; // xmm14
  __m128 v18; // xmm2
  __m128 v19; // xmm13
  __m128 v20; // xmm2
  hkVector4f v21; // xmm4
  __m128 v22; // xmm2
  __m128 v23; // xmm3
  __m128 v24; // xmm1
  __m128 v25; // xmm2
  hkVector4f v26; // xmm7
  hkVector4f v27; // xmm6
  hkVector4f v28; // xmm8
  __int64 v29; // rax
  __m128 v30; // xmm2
  hkVector4f v31; // xmm9
  hkVector4f v32; // xmm10
  __m128 v33; // xmm2
  hkVector4f v34; // xmm5
  __m128 v35; // xmm2
  hkVector4f v36; // xmm4
  __m128 v37; // xmm2

  m_data = this->m_matrices.m_data;
  if ( this->m_inverseMatrices.m_size <= 0 )
  {
    v26.m_quad = (__m128)parentToWorld->m_col1;
    v27.m_quad = (__m128)parentToWorld->m_col0;
    v28.m_quad = (__m128)parentToWorld->m_col2;
    v29 = (__int64)index << 6;
    v30 = *(__m128 *)((char *)&m_data->m_col1.m_quad + v29);
    v31.m_quad = (__m128)parentToWorld->m_col3;
    v32.m_quad = _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v30, v30, 0), parentToWorld->m_col0.m_quad),
                       _mm_mul_ps(_mm_shuffle_ps(v30, v30, 85), v26.m_quad)),
                     _mm_mul_ps(_mm_shuffle_ps(v30, v30, 170), v28.m_quad)),
                   _mm_mul_ps(_mm_shuffle_ps(v30, v30, 255), v31.m_quad));
    v33 = *(__m128 *)((char *)&m_data->m_col2.m_quad + v29);
    v34.m_quad = _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v33, v33, 0), parentToWorld->m_col0.m_quad),
                       _mm_mul_ps(_mm_shuffle_ps(v33, v33, 85), v26.m_quad)),
                     _mm_mul_ps(_mm_shuffle_ps(v33, v33, 170), v28.m_quad)),
                   _mm_mul_ps(_mm_shuffle_ps(v33, v33, 255), v31.m_quad));
    v35 = *(__m128 *)((char *)&m_data->m_col3.m_quad + v29);
    v36.m_quad = _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v35, v35, 0), parentToWorld->m_col0.m_quad),
                       _mm_mul_ps(_mm_shuffle_ps(v35, v35, 85), v26.m_quad)),
                     _mm_mul_ps(_mm_shuffle_ps(v35, v35, 170), v28.m_quad)),
                   _mm_mul_ps(_mm_shuffle_ps(v35, v35, 255), v31.m_quad));
    v37 = *(__m128 *)((char *)&m_data->m_col0.m_quad + v29);
    matrixOut->m_col1 = (hkVector4f)v32.m_quad;
    matrixOut->m_col2 = (hkVector4f)v34.m_quad;
    matrixOut->m_col3 = (hkVector4f)v36.m_quad;
    v23 = _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v37, v37, 0), v27.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v37, v37, 85), v26.m_quad));
    v24 = _mm_mul_ps(_mm_shuffle_ps(v37, v37, 170), v28.m_quad);
    v25 = _mm_mul_ps(_mm_shuffle_ps(v37, v37, 255), v31.m_quad);
  }
  else
  {
    v5.m_quad = (__m128)parentToWorld->m_col1;
    v6.m_quad = (__m128)parentToWorld->m_col2;
    v7 = (__int64)index << 6;
    v8 = *(__m128 *)((char *)&m_data->m_col0.m_quad + v7);
    v9.m_quad = (__m128)parentToWorld->m_col3;
    v10 = this->m_inverseMatrices.m_data;
    v11 = *(__m128 *)((char *)&v10->m_col1.m_quad + v7);
    v12 = *(__m128 *)((char *)&v10->m_col3.m_quad + v7);
    v13 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v8, v8, 0), parentToWorld->m_col0.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v8, v8, 85), v5.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v8, v8, 170), v6.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v8, v8, 255), v9.m_quad));
    v14 = *(__m128 *)((char *)&m_data->m_col1.m_quad + v7);
    v15 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v14, v14, 0), parentToWorld->m_col0.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v14, v14, 85), v5.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v14, v14, 170), v6.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v14, v14, 255), v9.m_quad));
    v16 = *(__m128 *)((char *)&m_data->m_col2.m_quad + v7);
    v17 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v16, v16, 0), parentToWorld->m_col0.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v16, v16, 85), v5.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v16, v16, 170), v6.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v16, v16, 255), v9.m_quad));
    v18 = *(__m128 *)((char *)&m_data->m_col3.m_quad + v7);
    v19 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v18, v18, 0), parentToWorld->m_col0.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v18, v18, 85), v5.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v18, v18, 170), v6.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v18, v18, 255), v9.m_quad));
    v20 = *(__m128 *)((char *)&v10->m_col2.m_quad + v7);
    v21.m_quad = _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v20, v20, 85), v15),
                       _mm_mul_ps(_mm_shuffle_ps(v20, v20, 0), v13)),
                     _mm_mul_ps(_mm_shuffle_ps(v20, v20, 170), v17)),
                   _mm_mul_ps(_mm_shuffle_ps(v20, v20, 255), v19));
    v22 = *(__m128 *)((char *)&v10->m_col0.m_quad + v7);
    matrixOut->m_col2 = (hkVector4f)v21.m_quad;
    v23 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v22, v22, 85), v15), _mm_mul_ps(_mm_shuffle_ps(v22, v22, 0), v13));
    v24 = _mm_mul_ps(_mm_shuffle_ps(v22, v22, 170), v17);
    v25 = _mm_mul_ps(_mm_shuffle_ps(v22, v22, 255), v19);
    matrixOut->m_col3.m_quad = _mm_add_ps(
                                 _mm_add_ps(
                                   _mm_add_ps(
                                     _mm_mul_ps(v13, _mm_shuffle_ps(v12, v12, 0)),
                                     _mm_mul_ps(_mm_shuffle_ps(v12, v12, 85), v15)),
                                   _mm_mul_ps(_mm_shuffle_ps(v12, v12, 170), v17)),
                                 _mm_mul_ps(_mm_shuffle_ps(v12, v12, 255), v19));
    matrixOut->m_col1.m_quad = _mm_add_ps(
                                 _mm_add_ps(
                                   _mm_add_ps(
                                     _mm_mul_ps(v13, _mm_shuffle_ps(v11, v11, 0)),
                                     _mm_mul_ps(_mm_shuffle_ps(v11, v11, 85), v15)),
                                   _mm_mul_ps(_mm_shuffle_ps(v11, v11, 170), v17)),
                                 _mm_mul_ps(_mm_shuffle_ps(v11, v11, 255), v19));
  }
  matrixOut->m_col0.m_quad = _mm_add_ps(_mm_add_ps(v23, v24), v25);
}

// File Line: 214
// RVA: 0x131A6A0
void __fastcall hkIndexedTransformSet::getMatrices(
        hkIndexedTransformSet *this,
        int startIndex,
        hkMatrix4f *matrices,
        int numMatrices)
{
  hkMatrix4f *v4; // rax
  unsigned __int64 *v5; // r10
  __int64 v6; // r11
  int v7; // r8d
  int v8; // r9d
  int v9; // ecx

  if ( numMatrices > 0 )
  {
    v4 = &this->m_matrices.m_data[(__int64)startIndex];
    if ( 4 * numMatrices > 0 )
    {
      v5 = &matrices->m_col0.m_quad.m128_u64[1];
      v6 = (unsigned int)(4 * numMatrices);
      do
      {
        v7 = v4->m_col0.m_quad.m128_i32[2];
        v8 = v4->m_col0.m_quad.m128_i32[3];
        v9 = v4->m_col0.m_quad.m128_i32[0];
        *((_DWORD *)v5 - 1) = v4->m_col0.m_quad.m128_i32[1];
        *(_DWORD *)v5 = v7;
        *((_DWORD *)v5 + 1) = v8;
        *((_DWORD *)v5 - 2) = v9;
        v5 += 2;
        v4 = (hkMatrix4f *)((char *)v4 + 16);
        --v6;
      }
      while ( v6 );
    }
  }
}

// File Line: 226
// RVA: 0x131A700
void __fastcall hkIndexedTransformSet::getInverseMatrices(
        hkIndexedTransformSet *this,
        int startIndex,
        hkMatrix4f *matrices,
        int numMatrices)
{
  unsigned int v4; // eax
  hkMatrix4f *v5; // r10
  unsigned __int64 *v6; // r9
  __int64 v7; // r11
  int v8; // edx
  int v9; // r8d
  int v10; // eax
  __int64 v11; // rcx
  hkVector4f *p_m_col2; // rax

  if ( this->m_inverseMatrices.m_size <= 0 )
  {
    v11 = numMatrices;
    if ( numMatrices > 0 )
    {
      p_m_col2 = &matrices->m_col2;
      do
      {
        p_m_col2 += 4;
        p_m_col2[-6] = (hkVector4f)transform.m_quad;
        p_m_col2[-5] = (hkVector4f)direction.m_quad;
        p_m_col2[-4] = (hkVector4f)stru_141A71280.m_quad;
        p_m_col2[-3] = (hkVector4f)qi.m_vec.m_quad;
        --v11;
      }
      while ( v11 );
    }
  }
  else if ( numMatrices > 0 )
  {
    v4 = 4 * numMatrices;
    v5 = &this->m_inverseMatrices.m_data[(__int64)startIndex];
    if ( 4 * numMatrices > 0 )
    {
      v6 = &matrices->m_col0.m_quad.m128_u64[1];
      v7 = v4;
      do
      {
        v8 = v5->m_col0.m_quad.m128_i32[2];
        v9 = v5->m_col0.m_quad.m128_i32[3];
        v10 = v5->m_col0.m_quad.m128_i32[0];
        *((_DWORD *)v6 - 1) = v5->m_col0.m_quad.m128_i32[1];
        *(_DWORD *)v6 = v8;
        *((_DWORD *)v6 + 1) = v9;
        *((_DWORD *)v6 - 2) = v10;
        v6 += 2;
        v5 = (hkMatrix4f *)((char *)v5 + 16);
        --v7;
      }
      while ( v7 );
    }
  }
}

// File Line: 247
// RVA: 0x131A630
void __fastcall hkIndexedTransformSet::setInverseMatrices(
        hkIndexedTransformSet *this,
        int startIndex,
        hkMatrix4f *matrices,
        int numMatrices)
{
  int v4; // r9d
  hkMatrix4f *v5; // rax
  unsigned __int64 *v6; // r10
  __int64 v7; // r11
  int v8; // r8d
  int v9; // r9d
  int v10; // ecx

  if ( this->m_inverseMatrices.m_size > 0 && numMatrices > 0 )
  {
    v4 = 4 * numMatrices;
    v5 = &this->m_inverseMatrices.m_data[(__int64)startIndex];
    if ( v4 > 0 )
    {
      v6 = &matrices->m_col0.m_quad.m128_u64[1];
      v7 = (unsigned int)v4;
      do
      {
        v8 = *(_DWORD *)v6;
        v9 = *((_DWORD *)v6 + 1);
        v10 = *((_DWORD *)v6 - 2);
        v5->m_col0.m_quad.m128_i32[1] = *((_DWORD *)v6 - 1);
        v5->m_col0.m_quad.m128_i32[2] = v8;
        v5->m_col0.m_quad.m128_i32[3] = v9;
        v5->m_col0.m_quad.m128_i32[0] = v10;
        v5 = (hkMatrix4f *)((char *)v5 + 16);
        v6 += 2;
        --v7;
      }
      while ( v7 );
    }
  }
}

