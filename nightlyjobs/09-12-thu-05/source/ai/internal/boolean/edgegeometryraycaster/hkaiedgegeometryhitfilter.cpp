// File Line: 16
// RVA: 0xBA5970
void __fastcall hkaiPositionHitFilter::hkaiPositionHitFilter(hkaiPositionHitFilter *this, float epsilon)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkaiPositionHitFilter::`vftable';
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_lowerEpsilon.m_real = _mm_shuffle_ps(
                                  (__m128)COERCE_UNSIGNED_INT(epsilon * 0.94999999),
                                  (__m128)COERCE_UNSIGNED_INT(epsilon * 0.94999999),
                                  0);
  this->m_upperEpsilon.m_real = _mm_shuffle_ps(
                                  (__m128)COERCE_UNSIGNED_INT(epsilon * 1.05),
                                  (__m128)COERCE_UNSIGNED_INT(epsilon * 1.05),
                                  0);
}

// File Line: 24
// RVA: 0xBA59D0
bool __fastcall hkaiPositionHitFilter::ignoreHit(hkaiPositionHitFilter *this, int cuttingFaceId, hkVector4f *start, hkVector4f *end, hkSimdFloat32 *hitFraction, hkVector4f *facePlane)
{
  __m128 v6; // xmm4
  __m128 v7; // xmm1
  __m128 v8; // xmm1
  __m128 v9; // xmm3
  __m128 v10; // xmm1
  float v11; // xmm5_4
  __m128 v12; // xmm4
  bool result; // al

  v6 = _mm_sub_ps(end->m_quad, start->m_quad);
  v7 = _mm_sub_ps(start->m_quad, _mm_add_ps(_mm_mul_ps(hitFraction->m_real, v6), start->m_quad));
  v8 = _mm_mul_ps(v7, v7);
  v9 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)), _mm_shuffle_ps(v8, v8, 170));
  v10 = _mm_rsqrt_ps(v9);
  LODWORD(v11) = (unsigned __int128)_mm_andnot_ps(
                                      _mm_cmpleps(v9, (__m128)0i64),
                                      _mm_mul_ps(
                                        _mm_mul_ps(
                                          _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v9, v10), v10)),
                                          _mm_mul_ps(*(__m128 *)_xmm, v10)),
                                        v9));
  result = 1;
  if ( v11 >= this->m_lowerEpsilon.m_real.m128_f32[0] )
  {
    if ( v11 >= this->m_upperEpsilon.m_real.m128_f32[0]
      || (v12 = _mm_mul_ps(v6, facePlane->m_quad),
          (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 0)))
                + COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 170))) >= 0.0) )
    {
      result = 0;
    }
  }
  return result;
}

// File Line: 55
// RVA: 0xBA5A90
void __fastcall hkaiRemoveUnreachableHitFilter::hkaiRemoveUnreachableHitFilter(hkaiRemoveUnreachableHitFilter *this, hkArrayBase<hkVector4f> *vertices, hkaiEdgeGeometry *walkableGeom, hkArrayBase<int> *originalFaceIndices, hkArrayBase<int> *trianglesPerFace, hkArrayBase<int> *tris, hkBitField *trisToRemove, float epsilon)
{
  hkArrayBase<int> *v8; // rbp
  hkaiEdgeGeometry *v9; // rsi
  hkArrayBase<hkVector4f> *v10; // rbx
  hkaiRemoveUnreachableHitFilter *v11; // rdi

  v8 = originalFaceIndices;
  v9 = walkableGeom;
  v10 = vertices;
  v11 = this;
  hkaiPositionHitFilter::hkaiPositionHitFilter((hkaiPositionHitFilter *)&this->vfptr, epsilon);
  v11->m_trianglesVertices = v10;
  v11->vfptr = (hkBaseObjectVtbl *)&hkaiRemoveUnreachableHitFilter::`vftable';
  if ( v9 )
    hkReferencedObject::addReference((hkReferencedObject *)&v9->vfptr);
  v11->m_walkableGeom.m_pntr = v9;
  v11->m_trianglesPerFace = trianglesPerFace;
  v11->m_tris = tris;
  v11->m_originalFaceIndices = v8;
  v11->m_trisToRemove = trisToRemove;
  v11->m_mapStorage.m_data = 0i64;
  v11->m_mapStorage.m_size = 0;
  v11->m_mapStorage.m_capacityAndFlags = 2147483648;
  v11->m_origToWalkableFaceMap.m_map.m_elem = 0i64;
  v11->m_origToWalkableFaceMap.m_map.m_numElems = 0;
  v11->m_origToWalkableFaceMap.m_map.m_hashMod = -1;
  v11->m_triOffsets.m_data = 0i64;
  v11->m_triOffsets.m_size = 0;
  v11->m_triOffsets.m_capacityAndFlags = 2147483648;
}

// File Line: 59
// RVA: 0xBA5B50
hkResult *__fastcall hkaiRemoveUnreachableHitFilter::init(hkaiRemoveUnreachableHitFilter *this, hkResult *result)
{
  hkaiEdgeGeometry *v2; // rax
  hkResult *v3; // r15
  hkaiRemoveUnreachableHitFilter *v4; // rbx
  int v5; // ebp
  int v6; // eax
  signed int v7; // esi
  int v8; // ecx
  int v9; // er14
  int v10; // ecx
  int v11; // er9
  signed __int64 v12; // r13
  signed __int64 v13; // rdi
  int v14; // er14
  signed __int64 v15; // rbp
  hkaiEdgeGeometry *v16; // rax
  int v17; // ecx
  int v18; // ebp
  signed __int64 v19; // rdi
  int v20; // eax
  int v21; // eax
  int v22; // er9
  hkArrayBase<int> *v23; // rcx
  int v24; // ecx
  hkResult resulta; // [rsp+60h] [rbp+8h]

  v2 = this->m_walkableGeom.m_pntr;
  v3 = result;
  v4 = this;
  if ( v2 )
    v5 = v2->m_faces.m_size;
  else
    v5 = this->m_originalFaceIndices->m_size;
  v6 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getSizeInBytesFor(v5);
  v7 = 1;
  v8 = v4->m_mapStorage.m_capacityAndFlags & 0x3FFFFFFF;
  v9 = v6;
  if ( v8 >= v6 )
  {
    resulta.m_enum = 0;
    goto LABEL_10;
  }
  v10 = 2 * v8;
  v11 = v6;
  if ( v6 < v10 )
    v11 = v10;
  hkArrayUtil::_reserve(
    &resulta,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
    &v4->m_mapStorage,
    v11,
    1);
  if ( resulta.m_enum == HK_SUCCESS )
  {
LABEL_10:
    v4->m_mapStorage.m_size = v9;
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::init(
      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v4->m_origToWalkableFaceMap.m_map.m_elem,
      v4->m_mapStorage.m_data,
      v9);
    v12 = v5;
    v13 = 1i64;
    if ( v5 > 1i64 )
    {
      v14 = 0;
      v15 = 1i64;
      do
      {
        v16 = v4->m_walkableGeom.m_pntr;
        if ( v16 )
          v17 = v16->m_faces.m_data[v15].m_faceIndex;
        else
          v17 = v4->m_originalFaceIndices->m_data[v13];
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
          (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v4->m_origToWalkableFaceMap.m_map.m_elem,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          v17,
          v14);
        ++v13;
        ++v14;
        ++v15;
      }
      while ( v13 < v12 );
    }
    v18 = v4->m_trianglesPerFace->m_size;
    if ( v18 )
    {
      v19 = 1i64;
      v20 = v4->m_triOffsets.m_capacityAndFlags & 0x3FFFFFFF;
      if ( v20 >= v18 )
      {
        resulta.m_enum = 0;
      }
      else
      {
        v21 = 2 * v20;
        v22 = v4->m_trianglesPerFace->m_size;
        if ( v18 < v21 )
          v22 = v21;
        hkArrayUtil::_reserve(
          &resulta,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          &v4->m_triOffsets,
          v22,
          4);
        if ( resulta.m_enum )
        {
          v3->m_enum = 1;
          return v3;
        }
      }
      v4->m_triOffsets.m_size = v18;
      *v4->m_triOffsets.m_data = 0;
      v23 = v4->m_trianglesPerFace;
      if ( v23->m_size > 1 )
      {
        do
        {
          ++v7;
          v24 = v23->m_data[v19 - 1];
          ++v19;
          v4->m_triOffsets.m_data[v19 - 1] = v4->m_triOffsets.m_data[v19 - 2] + v24;
          v23 = v4->m_trianglesPerFace;
        }
        while ( v7 < v23->m_size );
      }
    }
    v3->m_enum = 0;
    return v3;
  }
  v3->m_enum = 1;
  return v3;
}

// File Line: 98
// RVA: 0xBA5D20
bool __fastcall hkaiRemoveUnreachableHitFilter::ignoreHit(hkaiRemoveUnreachableHitFilter *this, int cuttingFaceId, hkVector4f *start, hkVector4f *end, hkSimdFloat32 *hitFraction, hkVector4f *facePlane)
{
  unsigned __int64 v6; // rsi
  hkVector4f *v7; // rdi
  hkVector4f *v8; // r12
  hkaiRemoveUnreachableHitFilter *v9; // rbx
  int v10; // eax
  __m128 v11; // xmm5
  __m128 v12; // xmm1
  __m128 v13; // xmm3
  __m128 v14; // xmm2
  int v15; // eax
  __int64 v16; // r15
  int v17; // ebp
  __int64 v18; // rdi
  signed __int64 v19; // r14
  signed __int64 v20; // rsi
  int *v21; // rcx
  hkVector4f *v22; // rdx
  signed __int64 v23; // r9
  hkVector4f *v24; // rax
  signed __int64 v25; // r8
  hkSimdFloat32 distOut; // [rsp+30h] [rbp-48h]
  hkVector4f dir; // [rsp+40h] [rbp-38h]

  v6 = cuttingFaceId;
  v7 = end;
  v8 = start;
  v9 = this;
  if ( hkaiPositionHitFilter::ignoreHit(
         (hkaiPositionHitFilter *)&this->vfptr,
         cuttingFaceId,
         start,
         end,
         hitFraction,
         facePlane) )
  {
    LOBYTE(v10) = 1;
  }
  else
  {
    v11 = _mm_sub_ps(v7->m_quad, v8->m_quad);
    v12 = _mm_mul_ps(v11, v11);
    v13 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)),
            _mm_shuffle_ps(v12, v12, 170));
    v14 = _mm_rsqrt_ps(v13);
    dir.m_quad = _mm_mul_ps(
                   v11,
                   _mm_andnot_ps(
                     _mm_cmpleps(v13, (__m128)0i64),
                     _mm_mul_ps(
                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v14, v13), v14)),
                       _mm_mul_ps(*(__m128 *)_xmm, v14))));
    v15 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
            (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v9->m_origToWalkableFaceMap.m_map.m_elem,
            v6,
            0xFFFFFFFFFFFFFFFFui64);
    if ( v15 == -1 || (v16 = v15, v17 = 0, v18 = v9->m_triOffsets.m_data[v15], v9->m_trianglesPerFace->m_data[v15] <= 0) )
    {
LABEL_10:
      LOBYTE(v10) = 0;
    }
    else
    {
      v19 = 3 * v18;
      v20 = 12 * v18 + 8;
      while ( 1 )
      {
        v21 = v9->m_tris->m_data;
        v22 = v9->m_trianglesVertices->m_data;
        v23 = *(int *)((char *)v21 + v20 - 4);
        v24 = &v22[v21[v19]];
        v25 = *(int *)((char *)v21 + v20);
        distOut.m_real = 0i64;
        if ( hkaiNavMeshGenerationUtils::_rayTriangleIntersect(v8, &dir, &v22[v25], &v22[v23], v24, &distOut)
          && distOut.m_real.m128_f32[0] < v9->m_upperEpsilon.m_real.m128_f32[0]
          && distOut.m_real.m128_f32[0] >= 0.0 )
        {
          break;
        }
        ++v17;
        LODWORD(v18) = v18 + 1;
        v19 += 3i64;
        v20 += 12i64;
        if ( v17 >= v9->m_trianglesPerFace->m_data[v16] )
          goto LABEL_10;
      }
      v10 = (v9->m_trisToRemove->m_storage.m_words.m_data[(signed __int64)(signed int)v18 >> 5] >> (v18 & 0x1F)) & 1;
    }
  }
  return v10;
}

