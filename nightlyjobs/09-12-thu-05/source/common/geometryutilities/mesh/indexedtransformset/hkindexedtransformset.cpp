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
void __fastcall hkIndexedTransformSet::hkIndexedTransformSet(hkIndexedTransformSet *this, hkFinishLoadedObjectFlag flag)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkIndexedTransformSet::`vftable';
}

// File Line: 36
// RVA: 0x131A170
void __fastcall hkIndexedTransformSet::hkIndexedTransformSet(hkIndexedTransformSet *this, hkIndexedTransformSetCinfo *info)
{
  int v2; // ebx
  hkArray<hkMatrix4f,hkContainerHeapAllocator> *v3; // rdi
  hkArray<hkMatrix4f,hkContainerHeapAllocator> *v4; // rsi
  hkArray<hkStringPtr,hkContainerHeapAllocator> *v5; // rbp
  hkArray<hkMeshBoneIndexMapping,hkContainerHeapAllocator> *v6; // r12
  hkIndexedTransformSetCinfo *v7; // r14
  hkIndexedTransformSet *v8; // r13
  __int64 v9; // r15
  __m128 *v10; // r9
  __int64 v11; // rcx
  __int64 v12; // rdx
  hkMatrix4f *v13; // rax
  __m128 *v14; // r10
  signed int v15; // er11
  signed __int64 v16; // rdi
  int v17; // edx
  int v18; // er8
  int v19; // eax
  __m128 *v20; // r10
  __m128 *v21; // r9
  int i; // er11
  int v23; // edx
  int v24; // er8
  int v25; // eax
  __int16 *v26; // rcx
  int v27; // edi
  hkStringPtr *v28; // rsi
  unsigned int v29; // edx
  hkStringPtr *v30; // rdi
  __int64 v31; // rsi
  __int64 v32; // rdi
  __int64 v33; // rsi
  int v34; // er9
  __int64 v35; // rbp
  int v36; // eax
  __int64 v37; // rsi
  int *v38; // rdi
  int v39; // er8
  signed __int64 v40; // rax
  int v41; // ecx
  signed __int64 v42; // rdx
  __int64 v43; // rax
  signed __int64 v44; // rdx
  hkIndexedTransformSet *v45; // [rsp+70h] [rbp+8h]
  hkResult result; // [rsp+78h] [rbp+10h]

  v45 = this;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  v2 = 0;
  v3 = &this->m_matrices;
  v4 = &this->m_inverseMatrices;
  v5 = &this->m_matricesNames;
  v6 = &this->m_indexMappings;
  v7 = info;
  v8 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkIndexedTransformSet::`vftable';
  v3->m_data = 0i64;
  v3->m_size = 0;
  v3->m_capacityAndFlags = 2147483648;
  v4->m_data = 0i64;
  v4->m_size = 0;
  v4->m_capacityAndFlags = 2147483648;
  this->m_matricesOrder.m_data = 0i64;
  this->m_matricesOrder.m_size = 0;
  this->m_matricesOrder.m_capacityAndFlags = 2147483648;
  v5->m_data = 0i64;
  v5->m_size = 0;
  v5->m_capacityAndFlags = 2147483648;
  v6->m_data = 0i64;
  v6->m_size = 0;
  v6->m_capacityAndFlags = 2147483648;
  v9 = (unsigned int)info->m_numMatrices;
  if ( (this->m_matrices.m_capacityAndFlags & 0x3FFFFFFF) < (signed int)v9 )
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, v9, 64);
  v8->m_matrices.m_size = v9;
  v10 = &v7->m_matrices->m_col0.m_quad;
  if ( v10 )
  {
    v14 = &v3->m_data->m_col0.m_quad;
    v15 = 0;
    v16 = 4i64 * (signed int)v9 & 0xFFFFFFFFFFFFFFFi64;
    if ( 4 * (signed int)v9 > 0 )
    {
      do
      {
        v17 = v10->m128_u64[1];
        v18 = HIDWORD(v10->m128_u64[1]);
        v19 = v10->m128_u64[0];
        ++v15;
        HIDWORD(v14->m128_u64[0]) = HIDWORD(v10->m128_u64[0]);
        LODWORD(v14->m128_u64[1]) = v17;
        HIDWORD(v14->m128_u64[1]) = v18;
        LODWORD(v14->m128_u64[0]) = v19;
        ++v14;
        ++v10;
      }
      while ( v15 < (signed int)v16 );
    }
  }
  else if ( (signed int)v9 > 0 )
  {
    v11 = 0i64;
    v12 = (signed int)v9;
    do
    {
      v13 = v3->m_data;
      ++v11;
      v13[v11 - 1].m_col0 = (hkVector4f)transform.m_quad;
      *((hkVector4f *)&v13[v11] - 3) = (hkVector4f)direction.m_quad;
      *((hkVector4f *)&v13[v11] - 2) = (hkVector4f)stru_141A71280.m_quad;
      *((hkQuaternionf *)&v13[v11] - 1) = (hkQuaternionf)qi.m_vec.m_quad;
      --v12;
    }
    while ( v12 );
  }
  if ( v7->m_inverseMatrices )
  {
    if ( (v4->m_capacityAndFlags & 0x3FFFFFFF) < (signed int)v9 )
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, v9, 64);
    v20 = &v4->m_data->m_col0.m_quad;
    v45->m_inverseMatrices.m_size = v9;
    v21 = &v7->m_inverseMatrices->m_col0.m_quad;
    for ( i = 0; i < 4 * (signed int)v9; ++v21 )
    {
      v23 = v21->m128_u64[1];
      v24 = HIDWORD(v21->m128_u64[1]);
      v25 = v21->m128_u64[0];
      ++i;
      HIDWORD(v20->m128_u64[0]) = HIDWORD(v21->m128_u64[0]);
      LODWORD(v20->m128_u64[1]) = v23;
      HIDWORD(v20->m128_u64[1]) = v24;
      LODWORD(v20->m128_u64[0]) = v25;
      ++v20;
    }
  }
  v45->m_allMatricesAreAffine.m_bool = v7->m_allTransformsAreAffine.m_bool;
  if ( v7->m_matricesOrder )
  {
    if ( (v45->m_matricesOrder.m_capacityAndFlags & 0x3FFFFFFF) < (signed int)v9 )
      hkArrayUtil::_reserve(
        &result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v45->m_matricesOrder,
        v9,
        2);
    v26 = v45->m_matricesOrder.m_data;
    v45->m_matricesOrder.m_size = v9;
    hkString::memCpy(v26, v7->m_matricesOrder, 2 * v9);
  }
  if ( v7->m_matricesNames )
  {
    if ( (v5->m_capacityAndFlags & 0x3FFFFFFF) < (signed int)v9 )
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v5, v9, 8);
    v27 = v5->m_size - v9 - 1;
    if ( v27 >= 0 )
    {
      v28 = &v5->m_data[(signed int)v9 + v27];
      do
      {
        hkStringPtr::~hkStringPtr(v28);
        --v28;
        --v27;
      }
      while ( v27 >= 0 );
    }
    v29 = v9 - v5->m_size;
    v30 = &v5->m_data[v5->m_size];
    if ( (signed int)v29 > 0 )
    {
      v31 = v29;
      do
      {
        if ( v30 )
          hkStringPtr::hkStringPtr(v30);
        ++v30;
        --v31;
      }
      while ( v31 );
    }
    v5->m_size = v9;
    if ( (signed int)v9 > 0 )
    {
      v32 = 0i64;
      v33 = v9;
      do
      {
        hkStringPtr::operator=(&v5->m_data[v32], &v7->m_matricesNames[v32]);
        ++v32;
        --v33;
      }
      while ( v33 );
    }
  }
  if ( v7->m_indexMappings )
  {
    v34 = v7->m_numIndexMappings;
    if ( (v6->m_capacityAndFlags & 0x3FFFFFFF) < v34 )
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v6, v34, 16);
    v35 = v7->m_numIndexMappings;
    v36 = v6->m_size - v35 - 1;
    v37 = v36;
    if ( v36 >= 0 )
    {
      v38 = &v6->m_data[v35].m_mapping.m_capacityAndFlags + 4 * v36;
      do
      {
        v39 = *v38;
        *(v38 - 1) = 0;
        if ( v39 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            *(void **)(v38 - 3),
            2 * (v39 & 0x3FFFFFFF));
        *(_QWORD *)(v38 - 3) = 0i64;
        *v38 = 2147483648;
        v38 -= 4;
        --v37;
      }
      while ( v37 >= 0 );
    }
    v40 = v6->m_size;
    v41 = v35 - v40;
    v42 = v40;
    v43 = (signed int)v35 - (signed int)v40;
    v44 = (signed __int64)&v6->m_data[v42];
    if ( v41 > 0 )
    {
      do
      {
        if ( v44 )
        {
          *(_QWORD *)v44 = 0i64;
          *(_DWORD *)(v44 + 8) = 0;
          *(_DWORD *)(v44 + 12) = 2147483648;
        }
        v44 += 16i64;
        --v43;
      }
      while ( v43 );
    }
    v6->m_size = v35;
    if ( v7->m_numIndexMappings > 0 )
    {
      do
      {
        hkMeshBoneIndexMapping::operator=(&v6->m_data[v2], &v7->m_indexMappings[v2]);
        ++v2;
      }
      while ( v2 < v7->m_numIndexMappings );
    }
  }
}

// File Line: 100
// RVA: 0x131A5C0
void __fastcall hkIndexedTransformSet::setMatrices(hkIndexedTransformSet *this, int startIndex, hkMatrix4f *matrices, int numMatrices)
{
  hkMatrix4f *v4; // rax
  int *v5; // r10
  __int64 v6; // r11
  int v7; // er8
  int v8; // er9
  int v9; // ecx

  if ( numMatrices > 0 )
  {
    v4 = &this->m_matrices.m_data[(signed __int64)startIndex];
    if ( 4 * numMatrices > 0 )
    {
      v5 = &matrices->m_col0.m_quad.m128_i32[2];
      v6 = (unsigned int)(4 * numMatrices);
      do
      {
        v7 = *v5;
        v8 = v5[1];
        v9 = *(v5 - 2);
        v4->m_col0.m_quad.m128_i32[1] = *(v5 - 1);
        v4->m_col0.m_quad.m128_i32[2] = v7;
        v4->m_col0.m_quad.m128_i32[3] = v8;
        v4->m_col0.m_quad.m128_i32[0] = v9;
        v4 = (hkMatrix4f *)((char *)v4 + 16);
        v5 += 4;
        --v6;
      }
      while ( v6 );
    }
  }
}

// File Line: 111
// RVA: 0x131A7B0
void __fastcall hkIndexedTransformSet::calculateMatrices(hkIndexedTransformSet *this, hkArray<hkMatrix4f,hkContainerHeapAllocator> *matricesOut)
{
  __int64 v2; // rbx
  unsigned __int128 v3; // di
  int v4; // eax
  int v5; // eax
  int v6; // er9
  __int64 v7; // rcx
  __int64 v8; // rax
  __int64 v9; // r9
  __int64 v10; // rcx
  signed __int64 v11; // r8
  signed __int64 v12; // rdx
  __m128 v13; // xmm2
  __m128 v14; // xmm7
  __m128 v15; // xmm6
  __m128 *v16; // rax
  __m128 v17; // xmm8
  __m128 v18; // xmm9
  __m128 v19; // xmm10
  __m128 v20; // xmm2
  __m128 v21; // xmm5
  __m128 v22; // xmm2
  __m128 v23; // xmm4
  __m128 v24; // xmm2
  _DWORD *v25; // r10
  unsigned int v26; // ebx
  int *v27; // rax
  __int64 v28; // r11
  int v29; // er8
  int v30; // er9
  int v31; // ecx
  hkResult result; // [rsp+90h] [rbp+8h]

  v2 = this->m_matrices.m_size;
  v3 = __PAIR__((unsigned __int64)this, (unsigned __int64)matricesOut);
  v4 = matricesOut->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v4 < (signed int)v2 )
  {
    v5 = 2 * v4;
    v6 = this->m_matrices.m_size;
    if ( (signed int)v2 < v5 )
      v6 = v5;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, matricesOut, v6, 64);
  }
  *(_DWORD *)(v3 + 8) = v2;
  v7 = *(_QWORD *)(*((_QWORD *)&v3 + 1) + 16i64);
  if ( *(_DWORD *)(*((_QWORD *)&v3 + 1) + 40i64) <= 0 )
  {
    v25 = *(_DWORD **)v3;
    v26 = 4 * v2;
    if ( (signed int)v26 > 0 )
    {
      v27 = (int *)(v7 + 8);
      v28 = v26;
      do
      {
        v29 = *v27;
        v30 = v27[1];
        v31 = *(v27 - 2);
        v25[1] = *(v27 - 1);
        v25[2] = v29;
        v25[3] = v30;
        *v25 = v31;
        v25 += 4;
        v27 += 4;
        --v28;
      }
      while ( v28 );
    }
  }
  else
  {
    v8 = *(_QWORD *)(*((_QWORD *)&v3 + 1) + 32i64);
    v9 = v2;
    if ( (signed int)v2 > 0 )
    {
      v10 = v7 - v8;
      v11 = v8 + 32;
      v12 = -32 - v8;
      do
      {
        v13 = *(__m128 *)(v11 - 16);
        v14 = *(__m128 *)(v10 + v11 - 16);
        v15 = *(__m128 *)(v10 + v11 - 32);
        v16 = (__m128 *)(*(_QWORD *)v3 + v12 + v11);
        v17 = *(__m128 *)(v10 + v11);
        v18 = *(__m128 *)(v10 + v11 + 16);
        v11 += 64i64;
        v19 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v13, v13, 0), v15),
                    _mm_mul_ps(_mm_shuffle_ps(v13, v13, 85), v14)),
                  _mm_mul_ps(_mm_shuffle_ps(v13, v13, 170), v17)),
                _mm_mul_ps(_mm_shuffle_ps(v13, v13, 255), v18));
        v20 = *(__m128 *)(v11 - 64);
        v21 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v20, v20, 0), v15),
                    _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)(v11 - 64), v20, 85), v14)),
                  _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)(v11 - 64), v20, 170), v17)),
                _mm_mul_ps(_mm_shuffle_ps(v20, v20, 255), v18));
        v22 = *(__m128 *)(v11 - 48);
        v23 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v22, v22, 0), v15),
                    _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)(v11 - 48), v22, 85), v14)),
                  _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)(v11 - 48), v22, 170), v17)),
                _mm_mul_ps(_mm_shuffle_ps(v22, v22, 255), v18));
        v24 = *(__m128 *)(v11 - 96);
        v16[1] = v19;
        v16[2] = v21;
        v16[3] = v23;
        *v16 = _mm_add_ps(
                 _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v24, v24, 0), v15),
                     _mm_mul_ps(_mm_shuffle_ps(v24, v24, 85), v14)),
                   _mm_mul_ps(_mm_shuffle_ps(v24, v24, 170), v17)),
                 _mm_mul_ps(_mm_shuffle_ps(v24, v24, 255), v18));
        --v9;
      }
      while ( v9 );
    }
  }
}

// File Line: 132
// RVA: 0x131A9F0
void __fastcall hkIndexedTransformSet::calculateMatrices(hkIndexedTransformSet *this, hkMatrix4f *parentToWorld, hkArray<hkMatrix4f,hkContainerHeapAllocator> *matricesOut)
{
  __int64 v3; // rsi
  int v4; // eax
  hkArray<hkMatrix4f,hkContainerHeapAllocator> *v5; // r14
  hkMatrix4f *v6; // rbx
  hkIndexedTransformSet *v7; // rdi
  int v8; // eax
  int v9; // er9
  hkMatrix4f *v10; // rcx
  __m128 v11; // xmm2
  __m128 v12; // xmm1
  hkMatrix4f *v13; // r10
  __int64 v14; // rdx
  hkMatrix4f *v15; // r8
  signed __int64 v16; // r10
  signed __int64 v17; // rax
  signed __int64 v18; // rcx
  __m128 v19; // xmm2
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
  unsigned int v30; // esi
  int *v31; // r9
  signed __int64 v32; // r10
  __int64 v33; // r11
  int v34; // edx
  int v35; // er8
  int v36; // eax
  char *v37; // rax
  __m128 *v38; // r8
  signed __int64 v39; // rcx
  __m128 v40; // xmm2
  __m128 v41; // xmm5
  __m128 v42; // xmm6
  __m128 v43; // xmm4
  __m128 v44; // xmm9
  __m128 v45; // xmm11
  __m128 v46; // xmm7
  __m128 v47; // xmm2
  __m128 v48; // xmm12
  __m128 v49; // xmm15
  __m128 v50; // xmm14
  __m128 v51; // xmm2
  __m128 v52; // xmm13
  __m128 v53; // xmm2
  __m128 v54; // xmm4
  __m128 v55; // xmm1
  __m128 v56; // xmm4
  __m128 v57; // xmm2
  __m128 v58; // xmm0
  __m128 v59; // xmm1
  signed __int64 v60; // rax
  signed __int64 v61; // rcx
  __m128 v62; // xmm2
  __m128 v63; // xmm7
  __m128 v64; // xmm6
  __m128 v65; // xmm8
  __m128 v66; // xmm9
  __m128 v67; // xmm10
  __m128 v68; // xmm2
  __m128 v69; // xmm5
  __m128 v70; // xmm2
  __m128 v71; // xmm4
  __m128 v72; // xmm2
  float v73; // [rsp+F0h] [rbp+8h]

  v3 = this->m_matrices.m_size;
  v4 = matricesOut->m_capacityAndFlags & 0x3FFFFFFF;
  v5 = matricesOut;
  v6 = parentToWorld;
  v7 = this;
  if ( v4 < (signed int)v3 )
  {
    v8 = 2 * v4;
    v9 = this->m_matrices.m_size;
    if ( (signed int)v3 < v8 )
      v9 = v8;
    hkArrayUtil::_reserve(
      (hkResult *)&v73,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      matricesOut,
      v9,
      64);
  }
  v10 = v5->m_data;
  v5->m_size = v3;
  v11 = v6->m_col0.m_quad;
  v12 = v6->m_col2.m_quad;
  v13 = v7->m_matrices.m_data;
  v73 = FLOAT_0_0000099999997;
  v14 = v3;
  if ( _mm_movemask_ps(
         _mm_cmpleps(
           _mm_max_ps(
             _mm_max_ps(
               (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(v11, transform.m_quad), 1u), 1u),
               (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(v6->m_col1.m_quad, direction.m_quad), 1u), 1u)),
             _mm_max_ps(
               (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(v12, stru_141A71280.m_quad), 1u), 1u),
               (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(v6->m_col3.m_quad, qi.m_vec.m_quad), 1u), 1u))),
           _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_0000099999997), (__m128)LODWORD(FLOAT_0_0000099999997), 0))) == 15 )
  {
    if ( v7->m_inverseMatrices.m_size <= 0 )
    {
      v30 = 4 * v3;
      if ( (signed int)v30 > 0 )
      {
        v31 = &v10->m_col0.m_quad.m128_i32[2];
        v32 = (char *)v13 - (char *)v10;
        v33 = v30;
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
      v15 = v7->m_inverseMatrices.m_data;
      if ( (signed int)v3 > 0 )
      {
        v16 = (char *)v13 - (char *)v15;
        v17 = (signed __int64)&v15->m_col2;
        v18 = (char *)v10 - (char *)v15;
        do
        {
          v19 = *(__m128 *)(v17 - 16);
          v20 = *(__m128 *)(v16 + v17 - 16);
          v21 = *(__m128 *)(v16 + v17 - 32);
          v22 = *(__m128 *)(v16 + v17);
          v23 = *(__m128 *)(v16 + v17 + 16);
          v17 += 64i64;
          v24 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v19, v19, 0), v21),
                      _mm_mul_ps(_mm_shuffle_ps(v19, v19, 85), v20)),
                    _mm_mul_ps(_mm_shuffle_ps(v19, v19, 170), v22)),
                  _mm_mul_ps(_mm_shuffle_ps(v19, v19, 255), v23));
          v25 = *(__m128 *)(v17 - 64);
          v26 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v25, v25, 0), v21),
                      _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)(v17 - 64), v25, 85), v20)),
                    _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)(v17 - 64), v25, 170), v22)),
                  _mm_mul_ps(_mm_shuffle_ps(v25, v25, 255), v23));
          v27 = *(__m128 *)(v17 - 48);
          v28 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v27, v27, 0), v21),
                      _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)(v17 - 48), v27, 85), v20)),
                    _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)(v17 - 48), v27, 170), v22)),
                  _mm_mul_ps(_mm_shuffle_ps(v27, v27, 255), v23));
          v29 = *(__m128 *)(v17 - 96);
          *(__m128 *)(v18 + v17 - 80) = v24;
          *(__m128 *)(v18 + v17 - 64) = v26;
          *(__m128 *)(v18 + v17 - 48) = v28;
          *(__m128 *)(v18 + v17 - 96) = _mm_add_ps(
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
  else if ( v7->m_inverseMatrices.m_size <= 0 )
  {
    if ( (signed int)v3 > 0 )
    {
      v60 = (signed __int64)&v13->m_col2;
      v61 = (char *)v10 - (char *)v13;
      do
      {
        v62 = *(__m128 *)(v60 - 16);
        v63 = v6->m_col1.m_quad;
        v64 = v6->m_col0.m_quad;
        v60 += 64i64;
        v65 = v6->m_col2.m_quad;
        v66 = v6->m_col3.m_quad;
        v67 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v62, v62, 0), v6->m_col0.m_quad),
                    _mm_mul_ps(_mm_shuffle_ps(v62, v62, 85), v63)),
                  _mm_mul_ps(_mm_shuffle_ps(v62, v62, 170), v65)),
                _mm_mul_ps(_mm_shuffle_ps(v62, v62, 255), v66));
        v68 = *(__m128 *)(v60 - 64);
        v69 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v68, v68, 0), v6->m_col0.m_quad),
                    _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)(v60 - 64), v68, 85), v63)),
                  _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)(v60 - 64), v68, 170), v65)),
                _mm_mul_ps(_mm_shuffle_ps(v68, v68, 255), v66));
        v70 = *(__m128 *)(v60 - 48);
        v71 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v70, v70, 0), v6->m_col0.m_quad),
                    _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)(v60 - 48), v70, 85), v63)),
                  _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)(v60 - 48), v70, 170), v65)),
                _mm_mul_ps(_mm_shuffle_ps(v70, v70, 255), v66));
        v72 = *(__m128 *)(v60 - 96);
        *(__m128 *)(v61 + v60 - 80) = v67;
        *(__m128 *)(v60 + v61 - 64) = v69;
        *(__m128 *)(v61 + v60 - 48) = v71;
        *(__m128 *)(v61 + v60 - 96) = _mm_add_ps(
                                        _mm_add_ps(
                                          _mm_add_ps(
                                            _mm_mul_ps(_mm_shuffle_ps(v72, v72, 0), v64),
                                            _mm_mul_ps(_mm_shuffle_ps(v72, v72, 85), v63)),
                                          _mm_mul_ps(_mm_shuffle_ps(v72, v72, 170), v65)),
                                        _mm_mul_ps(_mm_shuffle_ps(v72, v72, 255), v66));
        --v14;
      }
      while ( v14 );
    }
  }
  else if ( (signed int)v3 > 0 )
  {
    v37 = (char *)((char *)v7->m_inverseMatrices.m_data - (char *)v13);
    v38 = &v13->m_col2.m_quad;
    v39 = (char *)v10 - (char *)v13;
    do
    {
      v40 = v38[-2];
      v41 = v6->m_col2.m_quad;
      v42 = v6->m_col3.m_quad;
      v43 = v6->m_col1.m_quad;
      v44 = *(__m128 *)((char *)v38 + (_QWORD)v37 - 16);
      v45 = *(__m128 *)((char *)v38 + (_QWORD)v37 + 16);
      v46 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v40, v40, 0), v6->m_col0.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(v38[-2], v40, 85), v43)),
                _mm_mul_ps(_mm_shuffle_ps(v38[-2], v40, 170), v41)),
              _mm_mul_ps(_mm_shuffle_ps(v40, v40, 255), v42));
      v47 = v38[-1];
      v48 = _mm_shuffle_ps(*(__m128 *)((char *)v38 + (_QWORD)v37 + 16), v45, 0);
      v49 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v47, v47, 0), v6->m_col0.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(v38[-1], v47, 85), v43)),
                _mm_mul_ps(_mm_shuffle_ps(v38[-1], v47, 170), v41)),
              _mm_mul_ps(_mm_shuffle_ps(v47, v47, 255), v42));
      v50 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(*v38, *v38, 0), v6->m_col0.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(*v38, *v38, 85), v43)),
                _mm_mul_ps(_mm_shuffle_ps(*v38, *v38, 170), v41)),
              _mm_mul_ps(_mm_shuffle_ps(*v38, *v38, 255), v42));
      v51 = v38[1];
      v52 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v51, v51, 0), v6->m_col0.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(v38[1], v51, 85), v43)),
                _mm_mul_ps(_mm_shuffle_ps(v38[1], v51, 170), v41)),
              _mm_mul_ps(_mm_shuffle_ps(v51, v51, 255), v42));
      v53 = *(__m128 *)((char *)v38 + (_QWORD)v37);
      v54 = *(__m128 *)((char *)v38 + (_QWORD)v37);
      v55 = *(__m128 *)((char *)v38 + (_QWORD)v37);
      v38 += 4;
      v56 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v54, v53, 85), v49), _mm_mul_ps(_mm_shuffle_ps(v53, v53, 0), v46)),
                _mm_mul_ps(_mm_shuffle_ps(v55, v53, 170), v50)),
              _mm_mul_ps(_mm_shuffle_ps(v53, v53, 255), v52));
      v57 = *(__m128 *)((char *)v38 + (_QWORD)v37 - 96);
      v58 = _mm_shuffle_ps(*(__m128 *)((char *)v38 + (_QWORD)v37 - 96), v57, 0);
      v59 = _mm_shuffle_ps(*(__m128 *)((char *)v38 + (_QWORD)v37 - 96), v57, 170);
      *(__m128 *)((char *)v38 + v39 - 64) = v56;
      *(__m128 *)((char *)v38 + v39 - 96) = _mm_add_ps(
                                              _mm_add_ps(
                                                _mm_add_ps(
                                                  _mm_mul_ps(_mm_shuffle_ps(v57, v57, 85), v49),
                                                  _mm_mul_ps(v58, v46)),
                                                _mm_mul_ps(v59, v50)),
                                              _mm_mul_ps(_mm_shuffle_ps(v57, v57, 255), v52));
      *(__m128 *)((char *)v38 + v39 - 80) = _mm_add_ps(
                                              _mm_add_ps(
                                                _mm_add_ps(
                                                  _mm_mul_ps(_mm_shuffle_ps(v44, v44, 0), v46),
                                                  _mm_mul_ps(_mm_shuffle_ps(v44, v44, 85), v49)),
                                                _mm_mul_ps(_mm_shuffle_ps(v44, v44, 170), v50)),
                                              _mm_mul_ps(_mm_shuffle_ps(v44, v44, 255), v52));
      *(__m128 *)((char *)v38 + v39 - 48) = _mm_add_ps(
                                              _mm_add_ps(
                                                _mm_add_ps(
                                                  _mm_mul_ps(v48, v46),
                                                  _mm_mul_ps(_mm_shuffle_ps(v45, v45, 85), v49)),
                                                _mm_mul_ps(_mm_shuffle_ps(v45, v45, 170), v50)),
                                              _mm_mul_ps(_mm_shuffle_ps(v45, v45, 255), v52));
      --v14;
    }
    while ( v14 );
  }
}

// File Line: 183
// RVA: 0x131B070
void __fastcall hkIndexedTransformSet::calculateMatrix(hkIndexedTransformSet *this, int index, hkMatrix4f *matrixOut)
{
  hkMatrix4f *v3; // r9
  hkMatrix4f *v4; // rax
  signed __int64 v5; // rdx
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
  signed __int64 v17; // rax

  v3 = this->m_matrices.m_data;
  if ( this->m_inverseMatrices.m_size <= 0 )
  {
    v17 = (signed __int64)index << 6;
    matrixOut->m_col0 = *(hkVector4f *)((char *)&v3->m_col0 + v17);
    matrixOut->m_col1 = *(hkVector4f *)((char *)&v3->m_col1 + v17);
    matrixOut->m_col2 = *(hkVector4f *)((char *)&v3->m_col2 + v17);
    matrixOut->m_col3 = *(hkVector4f *)((char *)&v3->m_col3 + v17);
  }
  else
  {
    v4 = this->m_inverseMatrices.m_data;
    v5 = (signed __int64)index << 6;
    v6 = *(__m128 *)((char *)&v4->m_col1.m_quad + v5);
    v7 = *(__m128 *)((char *)&v3->m_col1.m_quad + v5);
    v8 = *(__m128 *)((char *)&v3->m_col0.m_quad + v5);
    v9 = *(__m128 *)((char *)&v3->m_col2.m_quad + v5);
    v10 = *(__m128 *)((char *)&v3->m_col3.m_quad + v5);
    v11.m_quad = _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v6, v6, 0), v8),
                       _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)((char *)&v4->m_col1.m_quad + v5), v6, 85), v7)),
                     _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)((char *)&v4->m_col1.m_quad + v5), v6, 170), v9)),
                   _mm_mul_ps(_mm_shuffle_ps(v6, v6, 255), v10));
    v12 = *(__m128 *)((char *)&v4->m_col2.m_quad + v5);
    v13.m_quad = _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v12, v12, 0), v8),
                       _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)((char *)&v4->m_col2.m_quad + v5), v12, 85), v7)),
                     _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)((char *)&v4->m_col2.m_quad + v5), v12, 170), v9)),
                   _mm_mul_ps(_mm_shuffle_ps(v12, v12, 255), v10));
    v14 = *(__m128 *)((char *)&v4->m_col3.m_quad + v5);
    v15.m_quad = _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v14, v14, 0), v8),
                       _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)((char *)&v4->m_col3.m_quad + v5), v14, 85), v7)),
                     _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)((char *)&v4->m_col3.m_quad + v5), v14, 170), v9)),
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
void __fastcall hkIndexedTransformSet::calculateMatrix(hkIndexedTransformSet *this, hkMatrix4f *parentToWorld, int index, hkMatrix4f *matrixOut)
{
  hkMatrix4f *v4; // r10
  hkVector4f v5; // xmm4
  hkVector4f v6; // xmm5
  signed __int64 v7; // r8
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
  __m128 v23; // xmm0
  __m128 v24; // xmm1
  __m128 v25; // xmm3
  __m128 v26; // xmm1
  __m128 v27; // xmm2
  hkVector4f v28; // xmm7
  hkVector4f v29; // xmm6
  hkVector4f v30; // xmm8
  signed __int64 v31; // rax
  __m128 v32; // xmm2
  hkVector4f v33; // xmm9
  hkVector4f v34; // xmm10
  __m128 v35; // xmm2
  hkVector4f v36; // xmm5
  __m128 v37; // xmm2
  hkVector4f v38; // xmm4
  __m128 v39; // xmm2

  v4 = this->m_matrices.m_data;
  if ( this->m_inverseMatrices.m_size <= 0 )
  {
    v28.m_quad = (__m128)parentToWorld->m_col1;
    v29.m_quad = (__m128)parentToWorld->m_col0;
    v30.m_quad = (__m128)parentToWorld->m_col2;
    v31 = (signed __int64)index << 6;
    v32 = *(__m128 *)((char *)&v4->m_col1.m_quad + v31);
    v33.m_quad = (__m128)parentToWorld->m_col3;
    v34.m_quad = _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v32, v32, 0), parentToWorld->m_col0.m_quad),
                       _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)((char *)&v4->m_col1.m_quad + v31), v32, 85), v28.m_quad)),
                     _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)((char *)&v4->m_col1.m_quad + v31), v32, 170), v30.m_quad)),
                   _mm_mul_ps(_mm_shuffle_ps(v32, v32, 255), v33.m_quad));
    v35 = *(__m128 *)((char *)&v4->m_col2.m_quad + v31);
    v36.m_quad = _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v35, v35, 0), parentToWorld->m_col0.m_quad),
                       _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)((char *)&v4->m_col2.m_quad + v31), v35, 85), v28.m_quad)),
                     _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)((char *)&v4->m_col2.m_quad + v31), v35, 170), v30.m_quad)),
                   _mm_mul_ps(_mm_shuffle_ps(v35, v35, 255), v33.m_quad));
    v37 = *(__m128 *)((char *)&v4->m_col3.m_quad + v31);
    v38.m_quad = _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v37, v37, 0), parentToWorld->m_col0.m_quad),
                       _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)((char *)&v4->m_col3.m_quad + v31), v37, 85), v28.m_quad)),
                     _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)((char *)&v4->m_col3.m_quad + v31), v37, 170), v30.m_quad)),
                   _mm_mul_ps(_mm_shuffle_ps(v37, v37, 255), v33.m_quad));
    v39 = *(__m128 *)((char *)&v4->m_col0.m_quad + v31);
    matrixOut->m_col1 = (hkVector4f)v34.m_quad;
    matrixOut->m_col2 = (hkVector4f)v36.m_quad;
    matrixOut->m_col3 = (hkVector4f)v38.m_quad;
    v25 = _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v39, v39, 0), v29.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v39, v39, 85), v28.m_quad));
    v26 = _mm_mul_ps(_mm_shuffle_ps(v39, v39, 170), v30.m_quad);
    v27 = _mm_mul_ps(_mm_shuffle_ps(v39, v39, 255), v33.m_quad);
  }
  else
  {
    v5.m_quad = (__m128)parentToWorld->m_col1;
    v6.m_quad = (__m128)parentToWorld->m_col2;
    v7 = (signed __int64)index << 6;
    v8 = *(__m128 *)((char *)&v4->m_col0.m_quad + v7);
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
    v14 = *(__m128 *)((char *)&v4->m_col1.m_quad + v7);
    v15 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v14, v14, 0), parentToWorld->m_col0.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)((char *)&v4->m_col1.m_quad + v7), v14, 85), v5.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)((char *)&v4->m_col1.m_quad + v7), v14, 170), v6.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v14, v14, 255), v9.m_quad));
    v16 = *(__m128 *)((char *)&v4->m_col2.m_quad + v7);
    v17 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v16, v16, 0), parentToWorld->m_col0.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)((char *)&v4->m_col2.m_quad + v7), v16, 85), v5.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)((char *)&v4->m_col2.m_quad + v7), v16, 170), v6.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v16, v16, 255), v9.m_quad));
    v18 = *(__m128 *)((char *)&v4->m_col3.m_quad + v7);
    v19 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v18, v18, 0), parentToWorld->m_col0.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)((char *)&v4->m_col3.m_quad + v7), v18, 85), v5.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)((char *)&v4->m_col3.m_quad + v7), v18, 170), v6.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v18, v18, 255), v9.m_quad));
    v20 = *(__m128 *)((char *)&v10->m_col2.m_quad + v7);
    v21.m_quad = _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)((char *)&v10->m_col2.m_quad + v7), v20, 85), v15),
                       _mm_mul_ps(_mm_shuffle_ps(v20, v20, 0), v13)),
                     _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)((char *)&v10->m_col2.m_quad + v7), v20, 170), v17)),
                   _mm_mul_ps(_mm_shuffle_ps(v20, v20, 255), v19));
    v22 = *(__m128 *)((char *)&v10->m_col0.m_quad + v7);
    v23 = _mm_shuffle_ps(*(__m128 *)((char *)&v10->m_col0.m_quad + v7), v22, 0);
    v24 = _mm_shuffle_ps(*(__m128 *)((char *)&v10->m_col0.m_quad + v7), v22, 170);
    matrixOut->m_col2 = (hkVector4f)v21.m_quad;
    v25 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v22, v22, 85), v15), _mm_mul_ps(v23, v13));
    v26 = _mm_mul_ps(v24, v17);
    v27 = _mm_mul_ps(_mm_shuffle_ps(v22, v22, 255), v19);
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
  matrixOut->m_col0.m_quad = _mm_add_ps(_mm_add_ps(v25, v26), v27);
}

// File Line: 214
// RVA: 0x131A6A0
void __fastcall hkIndexedTransformSet::getMatrices(hkIndexedTransformSet *this, int startIndex, hkMatrix4f *matrices, int numMatrices)
{
  hkMatrix4f *v4; // rax
  int *v5; // r10
  __int64 v6; // r11
  float v7; // er8
  float v8; // er9
  int v9; // ecx

  if ( numMatrices > 0 )
  {
    v4 = &this->m_matrices.m_data[(signed __int64)startIndex];
    if ( 4 * numMatrices > 0 )
    {
      v5 = &matrices->m_col0.m_quad.m128_i32[2];
      v6 = (unsigned int)(4 * numMatrices);
      do
      {
        v7 = v4->m_col0.m_quad.m128_f32[2];
        v8 = v4->m_col0.m_quad.m128_f32[3];
        v9 = v4->m_col0.m_quad.m128_i32[0];
        *(v5 - 1) = v4->m_col0.m_quad.m128_i32[1];
        *(float *)v5 = v7;
        *((float *)v5 + 1) = v8;
        *(v5 - 2) = v9;
        v5 += 4;
        v4 = (hkMatrix4f *)((char *)v4 + 16);
        --v6;
      }
      while ( v6 );
    }
  }
}

// File Line: 226
// RVA: 0x131A700
void __fastcall hkIndexedTransformSet::getInverseMatrices(hkIndexedTransformSet *this, int startIndex, hkMatrix4f *matrices, int numMatrices)
{
  unsigned int v4; // eax
  hkMatrix4f *v5; // r10
  int *v6; // r9
  __int64 v7; // r11
  float v8; // edx
  float v9; // er8
  int v10; // eax
  __int64 v11; // rcx
  hkQuaternionf *v12; // rax

  if ( this->m_inverseMatrices.m_size <= 0 )
  {
    v11 = numMatrices;
    if ( numMatrices > 0 )
    {
      v12 = (hkQuaternionf *)&matrices->m_col2;
      do
      {
        v12 += 4;
        v12[-6].m_vec = (hkVector4f)transform.m_quad;
        v12[-5].m_vec = (hkVector4f)direction.m_quad;
        v12[-4].m_vec = (hkVector4f)stru_141A71280.m_quad;
        v12[-3] = (hkQuaternionf)qi.m_vec.m_quad;
        --v11;
      }
      while ( v11 );
    }
  }
  else if ( numMatrices > 0 )
  {
    v4 = 4 * numMatrices;
    v5 = &this->m_inverseMatrices.m_data[(signed __int64)startIndex];
    if ( 4 * numMatrices > 0 )
    {
      v6 = &matrices->m_col0.m_quad.m128_i32[2];
      v7 = v4;
      do
      {
        v8 = v5->m_col0.m_quad.m128_f32[2];
        v9 = v5->m_col0.m_quad.m128_f32[3];
        v10 = v5->m_col0.m_quad.m128_i32[0];
        *(v6 - 1) = v5->m_col0.m_quad.m128_i32[1];
        *(float *)v6 = v8;
        *((float *)v6 + 1) = v9;
        *(v6 - 2) = v10;
        v6 += 4;
        v5 = (hkMatrix4f *)((char *)v5 + 16);
        --v7;
      }
      while ( v7 );
    }
  }
}

// File Line: 247
// RVA: 0x131A630
void __fastcall hkIndexedTransformSet::setInverseMatrices(hkIndexedTransformSet *this, int startIndex, hkMatrix4f *matrices, int numMatrices)
{
  int v4; // er9
  hkMatrix4f *v5; // rax
  int *v6; // r10
  __int64 v7; // r11
  int v8; // er8
  int v9; // er9
  int v10; // ecx

  if ( this->m_inverseMatrices.m_size > 0 && numMatrices > 0 )
  {
    v4 = 4 * numMatrices;
    v5 = &this->m_inverseMatrices.m_data[(signed __int64)startIndex];
    if ( v4 > 0 )
    {
      v6 = &matrices->m_col0.m_quad.m128_i32[2];
      v7 = (unsigned int)v4;
      do
      {
        v8 = *v6;
        v9 = v6[1];
        v10 = *(v6 - 2);
        v5->m_col0.m_quad.m128_i32[1] = *(v6 - 1);
        v5->m_col0.m_quad.m128_i32[2] = v8;
        v5->m_col0.m_quad.m128_i32[3] = v9;
        v5->m_col0.m_quad.m128_i32[0] = v10;
        v5 = (hkMatrix4f *)((char *)v5 + 16);
        v6 += 4;
        --v7;
      }
      while ( v7 );
    }
  }
}

