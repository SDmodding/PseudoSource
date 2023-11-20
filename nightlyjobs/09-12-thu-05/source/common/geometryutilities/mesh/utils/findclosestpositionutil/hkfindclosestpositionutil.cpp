// File Line: 25
// RVA: 0xC9C650
void __fastcall hkFindClosestPositionUtil::hkFindClosestPositionUtil(hkFindClosestPositionUtil *this)
{
  hkFindClosestPositionUtil *v1; // rbx

  v1 = this;
  this->m_positions.m_capacityAndFlags = 2147483648;
  this->m_positions.m_data = 0i64;
  this->m_positions.m_size = 0;
  hkFreeList::hkFreeList(&this->m_boxFreeList, 0x38ui64, 8ui64, 0x1000ui64, 0i64, 0i64);
  v1->m_hashMap.m_map.m_elem = 0i64;
  v1->m_hashMap.m_map.m_numElems = 0;
  v1->m_hashMap.m_map.m_hashMod = -1;
}

// File Line: 58
// RVA: 0xC9C6C0
void __fastcall hkFindClosestPositionUtil::start(hkFindClosestPositionUtil *this, hkAabb *aabbIn, float threshold)
{
  hkFindClosestPositionUtil *v3; // rbx
  __m128 *v4; // rcx
  __m128 v5; // xmm0
  __m128 v6; // xmm6
  __m128 v7; // xmm5
  __m128 v8; // xmm2
  __m128 v9; // xmm4
  __m128 v10; // xmm4
  __m128 v11; // xmm1
  __m128 v12; // xmm0
  __m128 v13; // xmm2

  v3 = this;
  v4 = (__m128 *)&this->m_boxFreeList;
  v5 = _mm_shuffle_ps((__m128)LODWORD(threshold), (__m128)LODWORD(threshold), 0);
  v4[10] = v5;
  v6 = _mm_mul_ps(v5, (__m128)xmmword_141A710E0);
  v7 = _mm_sub_ps(aabbIn->m_max.m_quad, aabbIn->m_min.m_quad);
  v8 = _mm_sub_ps(aabbIn->m_min.m_quad, v6);
  v9 = _mm_add_ps(aabbIn->m_max.m_quad, v6);
  v4[8] = v8;
  v4[9] = v9;
  v10 = _mm_sub_ps(v9, v8);
  v11 = _mm_rcp_ps(v6);
  v4[11] = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v8);
  v12 = _mm_rcp_ps(v10);
  v13 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v10, v12)), v12);
  v4[12] = v13;
  v4[12] = _mm_mul_ps(
             _mm_shuffle_ps(v13, _mm_unpackhi_ps(v13, query.m_quad), 196),
             _mm_mul_ps(
               _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v11, v6)), v11),
               _mm_max_ps(
                 _mm_shuffle_ps(v7, v7, 170),
                 _mm_max_ps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps(v7, v7, 0)))));
  v4[-1].m128_i32[2] = 0;
  hkFreeList::freeAllMemory((hkFreeList *)v4);
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::clear((hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v3->m_hashMap.m_map.m_elem);
}

// File Line: 110
// RVA: 0xC9CDB0
void __fastcall hkFindClosestPositionUtil::end(hkFindClosestPositionUtil *this)
{
  hkFindClosestPositionUtil *v1; // rbx

  v1 = this;
  this->m_positions.m_size = 0;
  hkFreeList::freeAllMemory(&this->m_boxFreeList);
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::clear((hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v1->m_hashMap.m_map.m_elem);
}

// File Line: 117
// RVA: 0xC9CEE0
void __fastcall hkFindClosestPositionUtil::_findClosest(hkFindClosestPositionUtil *this, hkFindClosestPositionUtil::IntCoord *coord, hkVector4f *point, hkSimdFloat32 *closestDistInOut, int *closestIndexInOut)
{
  hkFindClosestPositionUtil::IntCoord *v5; // rdi
  __m128 v6; // xmm6
  int v7; // ebx
  hkFindClosestPositionUtil *v8; // r14
  hkSimdFloat32 *v9; // r15
  hkVector4f *v10; // rbp
  int v11; // eax
  unsigned __int64 i; // r8
  __int64 v13; // r9
  __int64 v14; // rax
  int *v15; // rdx
  __m128 v16; // xmm1
  __m128 v17; // xmm1
  __m128 v18; // xmm2

  v5 = coord;
  v6 = closestDistInOut->m_real;
  v7 = *closestIndexInOut;
  v8 = this;
  v9 = closestDistInOut;
  v10 = point;
  v11 = (unsigned __int64)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                            (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&this->m_hashMap.m_map.m_elem,
                            (coord->m_x ^ (coord->m_z << 8) ^ ((coord->m_y << 16) + ((unsigned int)coord->m_y >> 16))) & 0xFFFFFFFE);
  if ( v11 <= v8->m_hashMap.m_map.m_hashMod )
  {
    for ( i = v8->m_hashMap.m_map.m_elem[v11].val; i; i = *(_QWORD *)(i + 48) )
    {
      if ( *(_DWORD *)i == v5->m_x && *(_DWORD *)(i + 4) == v5->m_y && *(_DWORD *)(i + 8) == v5->m_z )
      {
        v13 = *(signed int *)(i + 44);
        v14 = 0i64;
        if ( v13 > 0 )
        {
          v15 = (int *)(i + 12);
          do
          {
            v16 = _mm_sub_ps(v8->m_positions.m_data[*v15].m_quad, v10->m_quad);
            v17 = _mm_mul_ps(v16, v16);
            v18 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
                    _mm_shuffle_ps(v17, v17, 170));
            if ( v18.m128_f32[0] < v6.m128_f32[0] )
            {
              v7 = *v15;
              v6 = v18;
              if ( v18.m128_f32[0] <= 0.0 )
                break;
            }
            ++v14;
            ++v15;
          }
          while ( v14 < v13 );
        }
      }
    }
    *v9 = (hkSimdFloat32)v6;
    *closestIndexInOut = v7;
  }
}

// File Line: 166
// RVA: 0xC9C7C0
__int64 __fastcall hkFindClosestPositionUtil::findClosest(hkFindClosestPositionUtil *this, hkVector4f *point)
{
  __m128 v2; // xmm5
  hkVector4f v3; // xmm2
  hkVector4f v4; // xmm3
  unsigned int v5; // ebx
  hkVector4f *v6; // r15
  hkFindClosestPositionUtil *v7; // r14
  hkSimdFloat32 v8; // xmm6
  __m128 v9; // xmm0
  __m128 v10; // xmm5
  __m128 v11; // xmm6
  __m128 v12; // xmm5
  __m128 v13; // xmm0
  __m128i v14; // xmm1
  int v15; // er13
  int v16; // ecx
  int v17; // er12
  __m128i v18; // xmm4
  int v19; // eax
  int v20; // edx
  int v21; // edi
  bool v22; // zf
  bool v23; // sf
  unsigned __int8 v24; // of
  int v25; // esi
  int v26; // ebx
  hkFindClosestPositionUtil::IntCoord coord; // [rsp+8h] [rbp-29h]
  __int64 v29; // [rsp+18h] [rbp-19h]
  int *closestIndexInOut; // [rsp+20h] [rbp-11h]
  __int128 v31; // [rsp+28h] [rbp-9h]
  hkSimdFloat32 closestDistInOut; // [rsp+38h] [rbp+7h]
  int v33; // [rsp+98h] [rbp+67h]

  v2 = point->m_quad;
  v3.m_quad = (__m128)this->m_offset;
  v4.m_quad = (__m128)this->m_scale;
  v5 = -1;
  v6 = point;
  v7 = this;
  v33 = -1;
  v8.m_real = (__m128)this->m_threshold;
  v9 = _mm_sub_ps(v2, v8.m_real);
  v10 = _mm_add_ps(_mm_add_ps(v2, v8.m_real), v3.m_quad);
  v11 = _mm_mul_ps(v8.m_real, v8.m_real);
  v12 = _mm_mul_ps(v10, v4.m_quad);
  closestDistInOut.m_real = v11;
  v13 = _mm_mul_ps(_mm_add_ps(v9, v3.m_quad), v4.m_quad);
  v14 = _mm_xor_si128(
          (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31, v13),
          _mm_cvttps_epi32(v13));
  *((_QWORD *)&v31 + 1) = v14.m128i_i64[0];
  v15 = coord.m_x;
  v16 = coord.m_y;
  coord.m_z = (unsigned __int128)_mm_shuffle_epi32(v14, 170);
  v17 = coord.m_z;
  v18 = _mm_xor_si128(
          (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31, v12),
          _mm_cvttps_epi32(v12));
  closestDistInOut.m_real.m128_u64[1] = v18.m128i_i64[0];
  v19 = HIDWORD(v29);
  v20 = v29;
  LODWORD(closestIndexInOut) = (unsigned __int128)_mm_shuffle_epi32(v18, 170);
  v21 = (signed int)closestIndexInOut;
  v24 = __OFSUB__(coord.m_x, (_DWORD)v29);
  v22 = coord.m_x == (_DWORD)v29;
  v23 = coord.m_x - (signed int)v29 < 0;
  if ( coord.m_x == (_DWORD)v29 )
  {
    if ( coord.m_y == HIDWORD(v29) && coord.m_z == (_DWORD)closestIndexInOut )
    {
      hkFindClosestPositionUtil::_findClosest(v7, &coord, v6, &closestDistInOut, &v33);
      v11.m128_i32[0] = closestDistInOut.m_real.m128_i32[0];
LABEL_17:
      if ( v11.m128_f32[0] < (float)(v7->m_threshold.m_real.m128_f32[0] * v7->m_threshold.m_real.m128_f32[0]) )
        v5 = v33;
      return v5;
    }
    v24 = __OFSUB__(coord.m_x, (_DWORD)v29);
    v22 = coord.m_x == (_DWORD)v29;
    v23 = coord.m_x - (signed int)v29 < 0;
  }
  if ( !((unsigned __int8)(v23 ^ v24) | v22) )
    goto LABEL_17;
  while ( 1 )
  {
    v25 = v16;
    if ( v16 <= v19 )
      break;
LABEL_15:
    if ( ++v15 > v20 )
    {
      v5 = -1;
      goto LABEL_17;
    }
  }
  while ( 1 )
  {
    v26 = v17;
    if ( v17 <= v21 )
      break;
LABEL_13:
    if ( ++v25 > v19 )
    {
      v16 = coord.m_y;
      v20 = v29;
      goto LABEL_15;
    }
  }
  *(_QWORD *)&v31 = __PAIR__(v25, v15);
  while ( 1 )
  {
    DWORD2(v31) = v26;
    hkFindClosestPositionUtil::_findClosest(
      v7,
      (hkFindClosestPositionUtil::IntCoord *)&v31,
      v6,
      &closestDistInOut,
      &v33);
    v11.m128_i32[0] = closestDistInOut.m_real.m128_i32[0];
    if ( closestDistInOut.m_real.m128_f32[0] <= 0.0 )
      return (unsigned int)v33;
    if ( ++v26 > v21 )
    {
      v19 = HIDWORD(v29);
      goto LABEL_13;
    }
  }
}

// File Line: 221
// RVA: 0xC9C980
__int64 __fastcall hkFindClosestPositionUtil::addPoint(hkFindClosestPositionUtil *this, hkVector4f *point, hkResult *resultOut)
{
  hkVector4f v3; // xmm0
  hkFindClosestPositionUtil *v4; // rbx
  hkResult *v5; // r12
  __m128 v6; // xmm0
  __m128i v7; // xmm1
  int v8; // esi
  int v9; // eax
  unsigned int v10; // er14
  int v11; // er15
  unsigned __int64 v12; // r15
  unsigned __int64 v13; // rax
  char *v14; // rdx
  unsigned __int64 v15; // rcx
  hkResultEnum v16; // eax
  char *v17; // r9
  unsigned __int64 v18; // rcx
  unsigned __int64 v19; // r8
  hkResult res; // [rsp+80h] [rbp+8h]
  hkVector4f *v22; // [rsp+88h] [rbp+10h]
  unsigned __int64 key; // [rsp+98h] [rbp+20h]

  v22 = point;
  v3.m_quad = (__m128)this->m_offset;
  v4 = this;
  res.m_enum = 0;
  v5 = resultOut;
  v6 = _mm_mul_ps(_mm_add_ps(v3.m_quad, point->m_quad), this->m_scale.m_quad);
  v7 = _mm_xor_si128(
         (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31, v6),
         _mm_cvttps_epi32(v6));
  v8 = (unsigned __int128)_mm_shuffle_epi32(v7, 170);
  key = (v7.m128i_i32[0] ^ (v8 << 8) ^ ((v7.m128i_i32[1] << 16) + ((unsigned int)v7.m128i_i32[1] >> 16))) & 0xFFFFFFFE;
  v9 = (unsigned __int64)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                           (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&this->m_hashMap.m_map.m_elem,
                           key);
  v10 = v4->m_positions.m_size;
  v11 = v9;
  if ( v10 == (v4->m_positions.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, 16);
  v4->m_positions.m_data[v4->m_positions.m_size++] = (hkVector4f)v22->m_quad;
  if ( v11 > v4->m_hashMap.m_map.m_hashMod )
  {
    v17 = (char *)v4->m_boxFreeList.m_free;
    if ( v17 )
    {
      --v4->m_boxFreeList.m_numFreeElements;
      v4->m_boxFreeList.m_free = *(hkFreeList::Element **)v17;
    }
    else
    {
      v17 = v4->m_boxFreeList.m_top;
      if ( v17 < v4->m_boxFreeList.m_blockEnd )
      {
        v18 = v4->m_boxFreeList.m_elementSize;
        --v4->m_boxFreeList.m_numFreeElements;
        v4->m_boxFreeList.m_top = &v17[v18];
      }
      else
      {
        v17 = hkFreeList::addSpace(&v4->m_boxFreeList);
      }
    }
    v16 = 1;
    if ( !v17 )
      goto LABEL_26;
    v19 = key;
    *(_DWORD *)v17 = v7.m128i_i32[0];
    *((_DWORD *)v17 + 1) = v7.m128i_i32[1];
    *((_DWORD *)v17 + 2) = v8;
    *((_DWORD *)v17 + 3) = v10;
    *((_DWORD *)v17 + 11) = 1;
    *((_QWORD *)v17 + 6) = 0i64;
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::tryInsert(
      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v4->m_hashMap.m_map.m_elem,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      v19,
      (unsigned __int64)v17,
      &res);
    goto LABEL_25;
  }
  v12 = v4->m_hashMap.m_map.m_elem[v11].val;
  v13 = v12;
  if ( !v12 )
  {
LABEL_9:
    v14 = (char *)v4->m_boxFreeList.m_free;
    if ( v14 )
    {
      --v4->m_boxFreeList.m_numFreeElements;
      v4->m_boxFreeList.m_free = *(hkFreeList::Element **)v14;
    }
    else
    {
      v14 = v4->m_boxFreeList.m_top;
      if ( v14 < v4->m_boxFreeList.m_blockEnd )
      {
        v15 = v4->m_boxFreeList.m_elementSize;
        --v4->m_boxFreeList.m_numFreeElements;
        v4->m_boxFreeList.m_top = &v14[v15];
      }
      else
      {
        v14 = hkFreeList::addSpace(&v4->m_boxFreeList);
      }
    }
    v16 = 1;
    if ( !v14 )
      goto LABEL_26;
    *(_DWORD *)v14 = v7.m128i_i32[0];
    *((_DWORD *)v14 + 1) = v7.m128i_i32[1];
    *((_DWORD *)v14 + 2) = v8;
    *((_DWORD *)v14 + 3) = v10;
    *((_DWORD *)v14 + 11) = 1;
    *((_QWORD *)v14 + 6) = *(_QWORD *)(v12 + 48);
    *(_QWORD *)(v12 + 48) = v14;
LABEL_25:
    v16 = res.m_enum;
LABEL_26:
    if ( v5 )
      v5->m_enum = v16;
    return v10;
  }
  while ( *(_QWORD *)v13 != __PAIR__(v7.m128i_u32[1], v7.m128i_u32[0])
       || *(_DWORD *)(v13 + 8) != v8
       || *(_DWORD *)(v13 + 44) >= 8 )
  {
    v13 = *(_QWORD *)(v13 + 48);
    if ( !v13 )
      goto LABEL_9;
  }
  *(_DWORD *)(v13 + 4i64 * (signed int)(*(_DWORD *)(v13 + 44))++ + 12) = v10;
  if ( v5 )
    v5->m_enum = res.m_enum;
  return v10;
}

// File Line: 301
// RVA: 0xC9D030
hkResult *__fastcall hkFindClosestPositionUtil::_findEntry(hkFindClosestPositionUtil *this, hkResult *result, hkVector4f *point, hkFindClosestPositionUtil::Box **boxOut, int *indexOut, int *boxIndexOut)
{
  hkResult *v6; // rsi
  hkFindClosestPositionUtil *v7; // r15
  hkFindClosestPositionUtil::Box **v8; // r13
  hkVector4f *v9; // r12
  __m128 v10; // xmm0
  __m128i v11; // xmm1
  int v12; // er14
  int v13; // eax
  hkFindClosestPositionUtil::Box *v14; // r8
  __int64 v15; // r10
  int v16; // er9
  __int64 v17; // rax
  int *v18; // rdx
  int v19; // er11
  __m128 v20; // xmm2
  __m128 v21; // xmm2

  v6 = result;
  v7 = this;
  v8 = boxOut;
  v9 = point;
  v10 = _mm_mul_ps(_mm_add_ps(this->m_offset.m_quad, point->m_quad), this->m_scale.m_quad);
  v11 = _mm_xor_si128(
          (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31, v10),
          _mm_cvttps_epi32(v10));
  v12 = (unsigned __int128)_mm_shuffle_epi32(v11, 170);
  v13 = (unsigned __int64)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                            (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&this->m_hashMap.m_map.m_elem,
                            (v11.m128i_i64[0] ^ (unsigned int)(v12 << 8) ^ (unsigned __int64)(((unsigned int)v11.m128i_i32[1] >> 16)
                                                                                            + (v11.m128i_i32[1] << 16))) & 0xFFFFFFFE);
  if ( v13 <= v7->m_hashMap.m_map.m_hashMod
    && (v14 = (hkFindClosestPositionUtil::Box *)v7->m_hashMap.m_map.m_elem[v13].val) != 0i64 )
  {
    while ( 1 )
    {
      if ( *(_QWORD *)&v14->m_coord.m_x == __PAIR__(v11.m128i_u32[1], v11.m128i_u32[0]) && v14->m_coord.m_z == v12 )
      {
        v15 = v14->m_numIndices;
        v16 = 0;
        v17 = 0i64;
        if ( v15 > 0 )
          break;
      }
LABEL_9:
      v14 = v14->m_next;
      if ( !v14 )
        goto LABEL_10;
    }
    v18 = v14->m_indices;
    while ( 1 )
    {
      v19 = *v18;
      v20 = _mm_sub_ps(v9->m_quad, v7->m_positions.m_data[*v18].m_quad);
      v21 = _mm_mul_ps(v20, v20);
      if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v21, v21, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v21, v21, 0)))
                 + COERCE_FLOAT(_mm_shuffle_ps(v21, v21, 170))) < 0.00000011920929 )
        break;
      ++v17;
      ++v16;
      ++v18;
      if ( v17 >= v15 )
        goto LABEL_9;
    }
    v6->m_enum = 0;
    *indexOut = v19;
    *v8 = v14;
    *boxIndexOut = v16;
  }
  else
  {
LABEL_10:
    v6->m_enum = 1;
  }
  return v6;
}

// File Line: 335
// RVA: 0xC9CC80
void __fastcall hkFindClosestPositionUtil::removePoint(hkFindClosestPositionUtil *this, hkVector4f *point)
{
  hkFindClosestPositionUtil *v2; // rbx
  hkFindClosestPositionUtil::Box *v3; // rdx
  __int64 v4; // rdi
  __int64 v5; // rcx
  hkVector4f *v6; // rax
  signed __int64 v7; // rdx
  signed __int64 v8; // rax
  signed __int64 v9; // r8
  __int64 v10; // rcx
  hkResult result; // [rsp+30h] [rbp-28h]
  hkFindClosestPositionUtil::Box *boxOut; // [rsp+38h] [rbp-20h]
  hkVector4f pointa; // [rsp+40h] [rbp-18h]
  int boxIndexOut; // [rsp+70h] [rbp+18h]
  int indexOut; // [rsp+78h] [rbp+20h]

  v2 = this;
  boxOut = 0i64;
  indexOut = -1;
  boxIndexOut = -1;
  hkFindClosestPositionUtil::_findEntry(this, &result, point, &boxOut, &indexOut, &boxIndexOut);
  if ( result.m_enum == HK_SUCCESS )
  {
    v3 = boxOut;
    v4 = indexOut;
    boxOut->m_indices[boxIndexOut] = *(&boxOut->m_coord.m_z + boxOut->m_numIndices);
    --v3->m_numIndices;
    v5 = v2->m_positions.m_size;
    if ( (_DWORD)v5 - 1 != (_DWORD)v4 )
    {
      v6 = v2->m_positions.m_data;
      boxOut = 0i64;
      _mm_store_si128((__m128i *)&pointa, (__m128i)v6[v5 - 1].m_quad);
      boxIndexOut = -1;
      hkFindClosestPositionUtil::_findEntry(v2, &result, &pointa, &boxOut, &indexOut, &boxIndexOut);
      boxOut->m_indices[boxIndexOut] = v4;
    }
    if ( --v2->m_positions.m_size != (_DWORD)v4 )
    {
      v7 = 2i64;
      v8 = (signed __int64)&v2->m_positions.m_data[v4];
      v9 = (signed __int64)&v2->m_positions.m_data[v2->m_positions.m_size] - v8;
      do
      {
        v10 = *(_QWORD *)(v9 + v8);
        v8 += 8i64;
        *(_QWORD *)(v8 - 8) = v10;
        --v7;
      }
      while ( v7 );
    }
  }
}

// File Line: 369
// RVA: 0xC9CBF0
void __fastcall hkFindClosestPositionUtil::addPoints(hkFindClosestPositionUtil *this, hkVector4f *points, int numPoints)
{
  hkVector4f *v3; // rbx
  hkFindClosestPositionUtil *v4; // rsi
  hkVector4f *v5; // rdi

  v3 = points;
  v4 = this;
  v5 = &points[numPoints];
  if ( points != v5 )
  {
    do
    {
      hkFindClosestPositionUtil::addPoint(v4, v3, 0i64);
      ++v3;
    }
    while ( v3 != v5 );
  }
}

// File Line: 379
// RVA: 0xC9CDE0
__int64 __fastcall hkFindClosestPositionUtil::findClosestLinearly(hkFindClosestPositionUtil *this, hkVector4f *p)
{
  hkVector4f *v2; // r8
  __m128 v3; // xmm4
  __m128i v4; // xmm5
  hkVector4f *v5; // rax
  __m128i v6; // xmm8
  __m128 v7; // xmm1
  __m128 v8; // xmm1
  __m128 v9; // xmm1
  __m128 v10; // xmm2
  __m128i v11; // xmm3
  __m128i v12; // xmm4

  v2 = this->m_positions.m_data;
  v3 = (__m128)xmmword_141A712A0;
  v4 = _mm_load_si128((const __m128i *)&_xmm_ffffffffffffffffffffffffffffffff);
  v5 = &this->m_positions.m_data[this->m_positions.m_size];
  v6 = 0i64;
  if ( this->m_positions.m_data != v5 )
  {
    do
    {
      v7 = v2->m_quad;
      ++v2;
      v8 = _mm_sub_ps(v7, p->m_quad);
      v9 = _mm_mul_ps(v8, v8);
      v10 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)), _mm_shuffle_ps(v9, v9, 170));
      v11 = (__m128i)_mm_cmpltps(v10, v3);
      v3 = _mm_or_ps(_mm_and_ps((__m128)v11, v10), _mm_andnot_ps((__m128)v11, v3));
      v4 = _mm_or_si128(_mm_andnot_si128(v11, v4), _mm_and_si128(v11, v6));
      v6 = _mm_add_epi32((__m128i)xmmword_141A72090, v6);
    }
    while ( v2 != v5 );
  }
  v12 = (__m128i)_mm_cmpltps(v3, _mm_mul_ps(this->m_threshold.m_real, this->m_threshold.m_real));
  return (unsigned int)_mm_cvtsi128_si32(
                         _mm_or_si128(
                           _mm_and_si128(v12, v4),
                           _mm_andnot_si128(v12, (__m128i)_xmm_ffffffffffffffffffffffffffffffff)));
}

// File Line: 516
// RVA: 0xC9CC50
signed __int64 __fastcall hkFindClosestPositionUtil::getSizeInBytesFor(int numPoints)
{
  return 16i64 * (unsigned int)numPoints;
}

// File Line: 522
// RVA: 0xC9CC60
void __fastcall hkFindClosestPositionUtil::setBuffer(hkFindClosestPositionUtil *this, void *buffer, int numPoints)
{
  this->m_positions.m_data = (hkVector4f *)buffer;
  this->m_positions.m_size = 0;
  this->m_positions.m_capacityAndFlags = numPoints | 0x80000000;
}

