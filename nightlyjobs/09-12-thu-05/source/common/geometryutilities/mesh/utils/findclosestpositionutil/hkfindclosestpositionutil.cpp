// File Line: 25
// RVA: 0xC9C650
void __fastcall hkFindClosestPositionUtil::hkFindClosestPositionUtil(hkFindClosestPositionUtil *this)
{
  this->m_positions.m_capacityAndFlags = 0x80000000;
  this->m_positions.m_data = 0i64;
  this->m_positions.m_size = 0;
  hkFreeList::hkFreeList(&this->m_boxFreeList, 0x38ui64, 8ui64, 0x1000ui64, 0i64, 0i64);
  this->m_hashMap.m_map.m_elem = 0i64;
  this->m_hashMap.m_map.m_numElems = 0;
  this->m_hashMap.m_map.m_hashMod = -1;
}

// File Line: 58
// RVA: 0xC9C6C0
void __fastcall hkFindClosestPositionUtil::start(hkFindClosestPositionUtil *this, hkAabb *aabbIn, float threshold)
{
  hkFreeList *p_m_boxFreeList; // rcx
  __m128 v5; // xmm0
  __m128 v6; // xmm6
  __m128 v7; // xmm5
  __m128 v8; // xmm2
  __m128 v9; // xmm4
  __m128 v10; // xmm4
  __m128 v11; // xmm1
  __m128 v12; // xmm0
  __m128 v13; // xmm2

  p_m_boxFreeList = &this->m_boxFreeList;
  v5 = _mm_shuffle_ps((__m128)LODWORD(threshold), (__m128)LODWORD(threshold), 0);
  *(__m128 *)&p_m_boxFreeList[1].m_align = v5;
  v6 = _mm_mul_ps(v5, (__m128)xmmword_141A710E0);
  v7 = _mm_sub_ps(aabbIn->m_max.m_quad, aabbIn->m_min.m_quad);
  v8 = _mm_sub_ps(aabbIn->m_min.m_quad, v6);
  v9 = _mm_add_ps(aabbIn->m_max.m_quad, v6);
  *(__m128 *)&p_m_boxFreeList[1].m_lastIncrementalBlock = v8;
  *(__m128 *)&p_m_boxFreeList[1].m_freeBlocks = v9;
  v10 = _mm_sub_ps(v9, v8);
  v11 = _mm_rcp_ps(v6);
  *(__m128 *)&p_m_boxFreeList[1].m_top = _mm_xor_ps(
                                           (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                                           v8);
  v12 = _mm_rcp_ps(v10);
  v13 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v10, v12)), v12);
  *(__m128 *)&p_m_boxFreeList[1].m_elementAllocator = v13;
  *(__m128 *)&p_m_boxFreeList[1].m_elementAllocator = _mm_mul_ps(
                                                        _mm_shuffle_ps(v13, _mm_unpackhi_ps(v13, query.m_quad), 196),
                                                        _mm_mul_ps(
                                                          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v11, v6)), v11),
                                                          _mm_max_ps(
                                                            _mm_shuffle_ps(v7, v7, 170),
                                                            _mm_max_ps(
                                                              _mm_shuffle_ps(v7, v7, 85),
                                                              _mm_shuffle_ps(v7, v7, 0)))));
  LODWORD(p_m_boxFreeList[-1].m_numFreeElements) = 0;
  hkFreeList::freeAllMemory(p_m_boxFreeList);
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::clear(&this->m_hashMap.m_map);
}

// File Line: 110
// RVA: 0xC9CDB0
void __fastcall hkFindClosestPositionUtil::end(hkFindClosestPositionUtil *this)
{
  this->m_positions.m_size = 0;
  hkFreeList::freeAllMemory(&this->m_boxFreeList);
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::clear(&this->m_hashMap.m_map);
}

// File Line: 117
// RVA: 0xC9CEE0
void __fastcall hkFindClosestPositionUtil::_findClosest(
        hkFindClosestPositionUtil *this,
        hkFindClosestPositionUtil::IntCoord *coord,
        hkVector4f *point,
        hkSimdFloat32 *closestDistInOut,
        int *closestIndexInOut)
{
  __m128 m_real; // xmm6
  int v7; // ebx
  int Key; // eax
  unsigned __int64 i; // r8
  __int64 v13; // r9
  __int64 v14; // rax
  int *v15; // rdx
  __m128 v16; // xmm1
  __m128 v17; // xmm1
  __m128 v18; // xmm2

  m_real = closestDistInOut->m_real;
  v7 = *closestIndexInOut;
  Key = (unsigned int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                        &this->m_hashMap.m_map,
                        (coord->m_x ^ (coord->m_z << 8) ^ ((coord->m_y << 16) + HIWORD(coord->m_y))) & 0xFFFFFFFE);
  if ( Key <= this->m_hashMap.m_map.m_hashMod )
  {
    for ( i = this->m_hashMap.m_map.m_elem[Key].val; i; i = *(_QWORD *)(i + 48) )
    {
      if ( *(_DWORD *)i == coord->m_x && *(_DWORD *)(i + 4) == coord->m_y && *(_DWORD *)(i + 8) == coord->m_z )
      {
        v13 = *(int *)(i + 44);
        v14 = 0i64;
        if ( v13 > 0 )
        {
          v15 = (int *)(i + 12);
          do
          {
            v16 = _mm_sub_ps(this->m_positions.m_data[*v15].m_quad, point->m_quad);
            v17 = _mm_mul_ps(v16, v16);
            v18 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
                    _mm_shuffle_ps(v17, v17, 170));
            if ( v18.m128_f32[0] < m_real.m128_f32[0] )
            {
              v7 = *v15;
              m_real = v18;
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
    *closestDistInOut = (hkSimdFloat32)m_real;
    *closestIndexInOut = v7;
  }
}

// File Line: 166
// RVA: 0xC9C7C0
__int64 __fastcall hkFindClosestPositionUtil::findClosest(hkFindClosestPositionUtil *this, hkVector4f *point)
{
  __m128 m_quad; // xmm5
  hkVector4f v3; // xmm2
  hkVector4f v4; // xmm3
  unsigned int v5; // ebx
  hkSimdFloat32 v8; // xmm6
  __m128 v9; // xmm0
  __m128 v10; // xmm5
  __m128 v11; // xmm6
  __m128 v12; // xmm5
  __m128 v13; // xmm0
  __m128i v14; // xmm1
  int v15; // r13d
  int m_y; // ecx
  int m_z; // r12d
  __m128i v18; // xmm4
  int v19; // edx
  int v20; // eax
  int v21; // edi
  bool v22; // cc
  int v23; // esi
  int v24; // ebx
  hkFindClosestPositionUtil::IntCoord coord; // [rsp+8h] [rbp-29h] BYREF
  __int64 v27; // [rsp+18h] [rbp-19h]
  int *closestIndexInOut; // [rsp+20h] [rbp-11h]
  hkFindClosestPositionUtil::IntCoord v29; // [rsp+28h] [rbp-9h] BYREF
  hkSimdFloat32 closestDistInOut; // [rsp+38h] [rbp+7h] BYREF
  int v31[6]; // [rsp+98h] [rbp+67h] BYREF

  m_quad = point->m_quad;
  v3.m_quad = (__m128)this->m_offset;
  v4.m_quad = (__m128)this->m_scale;
  v5 = -1;
  v31[0] = -1;
  v8.m_real = (__m128)this->m_threshold;
  v9 = _mm_sub_ps(m_quad, v8.m_real);
  v10 = _mm_add_ps(_mm_add_ps(m_quad, v8.m_real), v3.m_quad);
  v11 = _mm_mul_ps(v8.m_real, v8.m_real);
  v12 = _mm_mul_ps(v10, v4.m_quad);
  closestDistInOut.m_real = v11;
  v13 = _mm_mul_ps(_mm_add_ps(v9, v3.m_quad), v4.m_quad);
  v14 = _mm_xor_si128(
          (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v13),
          _mm_cvttps_epi32(v13));
  *(_QWORD *)&coord.m_x = v14.m128i_i64[0];
  v15 = v14.m128i_i32[0];
  m_y = v14.m128i_i32[1];
  coord.m_z = _mm_shuffle_epi32(v14, 170).m128i_u32[0];
  m_z = coord.m_z;
  v18 = _mm_xor_si128(
          (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v12),
          _mm_cvttps_epi32(v12));
  v27 = v18.m128i_i64[0];
  v19 = v18.m128i_i32[0];
  v20 = v18.m128i_i32[1];
  LODWORD(closestIndexInOut) = _mm_shuffle_epi32(v18, 170).m128i_u32[0];
  v21 = (int)closestIndexInOut;
  v22 = v14.m128i_i32[0] <= v18.m128i_i32[0];
  if ( v14.m128i_i32[0] == v18.m128i_i32[0] )
  {
    if ( v14.m128i_i32[1] == v18.m128i_i32[1] && coord.m_z == (_DWORD)closestIndexInOut )
    {
      hkFindClosestPositionUtil::_findClosest(this, &coord, point, &closestDistInOut, v31);
      v11.m128_i32[0] = closestDistInOut.m_real.m128_i32[0];
LABEL_17:
      if ( v11.m128_f32[0] < (float)(this->m_threshold.m_real.m128_f32[0] * this->m_threshold.m_real.m128_f32[0]) )
        return (unsigned int)v31[0];
      return v5;
    }
    v22 = v14.m128i_i32[0] <= v18.m128i_i32[0];
  }
  if ( !v22 )
    goto LABEL_17;
  while ( 1 )
  {
    v23 = m_y;
    if ( m_y <= v20 )
      break;
LABEL_15:
    if ( ++v15 > v19 )
    {
      v5 = -1;
      goto LABEL_17;
    }
  }
  while ( 1 )
  {
    v24 = m_z;
    if ( m_z <= v21 )
      break;
LABEL_13:
    if ( ++v23 > v20 )
    {
      m_y = coord.m_y;
      v19 = v27;
      goto LABEL_15;
    }
  }
  v29.m_x = v15;
  v29.m_y = v23;
  while ( 1 )
  {
    v29.m_z = v24;
    hkFindClosestPositionUtil::_findClosest(this, &v29, point, &closestDistInOut, v31);
    v11.m128_i32[0] = closestDistInOut.m_real.m128_i32[0];
    if ( closestDistInOut.m_real.m128_f32[0] <= 0.0 )
      return (unsigned int)v31[0];
    if ( ++v24 > v21 )
    {
      v20 = HIDWORD(v27);
      goto LABEL_13;
    }
  }
}

// File Line: 221
// RVA: 0xC9C980
__int64 __fastcall hkFindClosestPositionUtil::addPoint(
        hkFindClosestPositionUtil *this,
        hkVector4f *point,
        hkResult *resultOut)
{
  hkVector4f v3; // xmm0
  __m128 v6; // xmm0
  __m128i v7; // xmm1
  unsigned int v8; // esi
  unsigned int v9; // eax
  unsigned int m_size; // r14d
  int v11; // r15d
  unsigned __int64 val; // r15
  unsigned __int64 v13; // rax
  hkFreeList::Element **m_top; // rdx
  unsigned __int64 v15; // rcx
  hkResultEnum m_enum; // eax
  hkFreeList::Element **p_m_next; // r9
  unsigned __int64 m_elementSize; // rcx
  unsigned __int64 v19; // r8
  hkResult res; // [rsp+80h] [rbp+8h] BYREF
  hkVector4f *v22; // [rsp+88h] [rbp+10h]
  unsigned __int64 key; // [rsp+98h] [rbp+20h]

  v22 = point;
  v3.m_quad = (__m128)this->m_offset;
  res.m_enum = HK_SUCCESS;
  v6 = _mm_mul_ps(_mm_add_ps(v3.m_quad, point->m_quad), this->m_scale.m_quad);
  v7 = _mm_xor_si128(
         (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v6),
         _mm_cvttps_epi32(v6));
  v8 = _mm_shuffle_epi32(v7, 170).m128i_u32[0];
  key = (v7.m128i_i32[0] ^ (v8 << 8) ^ ((v7.m128i_i32[1] << 16) + HIWORD(v7.m128i_i32[1]))) & 0xFFFFFFFE;
  v9 = (unsigned int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                       &this->m_hashMap.m_map,
                       key);
  m_size = this->m_positions.m_size;
  v11 = v9;
  if ( m_size == (this->m_positions.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_positions.m_data, 16);
  this->m_positions.m_data[this->m_positions.m_size++] = (hkVector4f)v22->m_quad;
  if ( v11 > this->m_hashMap.m_map.m_hashMod )
  {
    p_m_next = &this->m_boxFreeList.m_free->m_next;
    if ( p_m_next )
    {
      --this->m_boxFreeList.m_numFreeElements;
      this->m_boxFreeList.m_free = *p_m_next;
    }
    else
    {
      p_m_next = (hkFreeList::Element **)this->m_boxFreeList.m_top;
      if ( (char *)p_m_next < this->m_boxFreeList.m_blockEnd )
      {
        m_elementSize = this->m_boxFreeList.m_elementSize;
        --this->m_boxFreeList.m_numFreeElements;
        this->m_boxFreeList.m_top = (char *)p_m_next + m_elementSize;
      }
      else
      {
        p_m_next = (hkFreeList::Element **)hkFreeList::addSpace(&this->m_boxFreeList);
      }
    }
    m_enum = HK_FAILURE;
    if ( !p_m_next )
      goto LABEL_26;
    v19 = key;
    *(_DWORD *)p_m_next = v7.m128i_i32[0];
    *((_DWORD *)p_m_next + 1) = v7.m128i_i32[1];
    *((_DWORD *)p_m_next + 2) = v8;
    *((_DWORD *)p_m_next + 3) = m_size;
    *((_DWORD *)p_m_next + 11) = 1;
    p_m_next[6] = 0i64;
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::tryInsert(
      &this->m_hashMap.m_map,
      &hkContainerHeapAllocator::s_alloc,
      v19,
      (unsigned __int64)p_m_next,
      &res);
    goto LABEL_25;
  }
  val = this->m_hashMap.m_map.m_elem[v11].val;
  v13 = val;
  if ( !val )
  {
LABEL_9:
    m_top = &this->m_boxFreeList.m_free->m_next;
    if ( m_top )
    {
      --this->m_boxFreeList.m_numFreeElements;
      this->m_boxFreeList.m_free = *m_top;
    }
    else
    {
      m_top = (hkFreeList::Element **)this->m_boxFreeList.m_top;
      if ( (char *)m_top < this->m_boxFreeList.m_blockEnd )
      {
        v15 = this->m_boxFreeList.m_elementSize;
        --this->m_boxFreeList.m_numFreeElements;
        this->m_boxFreeList.m_top = (char *)m_top + v15;
      }
      else
      {
        m_top = (hkFreeList::Element **)hkFreeList::addSpace(&this->m_boxFreeList);
      }
    }
    m_enum = HK_FAILURE;
    if ( !m_top )
      goto LABEL_26;
    *(_DWORD *)m_top = v7.m128i_i32[0];
    *((_DWORD *)m_top + 1) = v7.m128i_i32[1];
    *((_DWORD *)m_top + 2) = v8;
    *((_DWORD *)m_top + 3) = m_size;
    *((_DWORD *)m_top + 11) = 1;
    m_top[6] = *(hkFreeList::Element **)(val + 48);
    *(_QWORD *)(val + 48) = m_top;
LABEL_25:
    m_enum = res.m_enum;
LABEL_26:
    if ( resultOut )
      resultOut->m_enum = m_enum;
    return m_size;
  }
  while ( *(_DWORD *)v13 != v7.m128i_i32[0]
       || *(_QWORD *)(v13 + 4) != __PAIR64__(v8, v7.m128i_u32[1])
       || *(int *)(v13 + 44) >= 8 )
  {
    v13 = *(_QWORD *)(v13 + 48);
    if ( !v13 )
      goto LABEL_9;
  }
  *(_DWORD *)(v13 + 4i64 * (int)(*(_DWORD *)(v13 + 44))++ + 12) = m_size;
  if ( resultOut )
    resultOut->m_enum = res.m_enum;
  return m_size;
}

// File Line: 301
// RVA: 0xC9D030
hkResult *__fastcall hkFindClosestPositionUtil::_findEntry(
        hkFindClosestPositionUtil *this,
        hkResult *result,
        hkVector4f *point,
        hkFindClosestPositionUtil::Box **boxOut,
        int *indexOut,
        int *boxIndexOut)
{
  __m128 v10; // xmm0
  __m128i v11; // xmm1
  unsigned int v12; // r14d
  int Key; // eax
  unsigned __int64 val; // r8
  __int64 v15; // r10
  int v16; // r9d
  __int64 v17; // rax
  int *v18; // rdx
  int v19; // r11d
  __m128 v20; // xmm2
  __m128 v21; // xmm2

  v10 = _mm_mul_ps(_mm_add_ps(this->m_offset.m_quad, point->m_quad), this->m_scale.m_quad);
  v11 = _mm_xor_si128(
          (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v10),
          _mm_cvttps_epi32(v10));
  v12 = _mm_shuffle_epi32(v11, 170).m128i_u32[0];
  Key = (unsigned int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                        &this->m_hashMap.m_map,
                        (v11.m128i_i64[0] ^ (v12 << 8) ^ (unsigned __int64)(HIWORD(v11.m128i_i32[1])
                                                                          + (v11.m128i_i32[1] << 16))) & 0xFFFFFFFE);
  if ( Key <= this->m_hashMap.m_map.m_hashMod && (val = this->m_hashMap.m_map.m_elem[Key].val) != 0 )
  {
    while ( 1 )
    {
      if ( *(_DWORD *)val == v11.m128i_i32[0] && *(_QWORD *)(val + 4) == __PAIR64__(v12, v11.m128i_u32[1]) )
      {
        v15 = *(int *)(val + 44);
        v16 = 0;
        v17 = 0i64;
        if ( v15 > 0 )
          break;
      }
LABEL_9:
      val = *(_QWORD *)(val + 48);
      if ( !val )
        goto LABEL_10;
    }
    v18 = (int *)(val + 12);
    while ( 1 )
    {
      v19 = *v18;
      v20 = _mm_sub_ps(point->m_quad, this->m_positions.m_data[*v18].m_quad);
      v21 = _mm_mul_ps(v20, v20);
      if ( (float)((float)(_mm_shuffle_ps(v21, v21, 85).m128_f32[0] + _mm_shuffle_ps(v21, v21, 0).m128_f32[0])
                 + _mm_shuffle_ps(v21, v21, 170).m128_f32[0]) < 0.00000011920929 )
        break;
      ++v17;
      ++v16;
      ++v18;
      if ( v17 >= v15 )
        goto LABEL_9;
    }
    result->m_enum = HK_SUCCESS;
    *indexOut = v19;
    *boxOut = (hkFindClosestPositionUtil::Box *)val;
    *boxIndexOut = v16;
  }
  else
  {
LABEL_10:
    result->m_enum = HK_FAILURE;
  }
  return result;
}

// File Line: 335
// RVA: 0xC9CC80
void __fastcall hkFindClosestPositionUtil::removePoint(hkFindClosestPositionUtil *this, hkVector4f *point)
{
  hkFindClosestPositionUtil::Box *v3; // rdx
  __int64 v4; // rdi
  __int64 m_size; // rcx
  hkVector4f *m_data; // rax
  __int64 v7; // rdx
  hkVector4f *v8; // rax
  char *v9; // r8
  unsigned __int64 v10; // rcx
  hkResult result; // [rsp+30h] [rbp-28h] BYREF
  hkFindClosestPositionUtil::Box *boxOut; // [rsp+38h] [rbp-20h] BYREF
  hkVector4f pointa; // [rsp+40h] [rbp-18h] BYREF
  int boxIndexOut; // [rsp+70h] [rbp+18h] BYREF
  int indexOut; // [rsp+78h] [rbp+20h] BYREF

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
    m_size = this->m_positions.m_size;
    if ( (_DWORD)m_size - 1 != (_DWORD)v4 )
    {
      m_data = this->m_positions.m_data;
      boxOut = 0i64;
      pointa.m_quad = (__m128)m_data[m_size - 1];
      boxIndexOut = -1;
      hkFindClosestPositionUtil::_findEntry(this, &result, &pointa, &boxOut, &indexOut, &boxIndexOut);
      boxOut->m_indices[boxIndexOut] = v4;
    }
    if ( --this->m_positions.m_size != (_DWORD)v4 )
    {
      v7 = 2i64;
      v8 = &this->m_positions.m_data[v4];
      v9 = (char *)((char *)&this->m_positions.m_data[this->m_positions.m_size] - (char *)v8);
      do
      {
        v10 = *(unsigned __int64 *)((char *)v8->m_quad.m128_u64 + (_QWORD)v9);
        v8 = (hkVector4f *)((char *)v8 + 8);
        v8[-1].m_quad.m128_u64[1] = v10;
        --v7;
      }
      while ( v7 );
    }
  }
}

// File Line: 369
// RVA: 0xC9CBF0
void __fastcall hkFindClosestPositionUtil::addPoints(
        hkFindClosestPositionUtil *this,
        hkVector4f *points,
        int numPoints)
{
  hkVector4f *v3; // rbx
  hkVector4f *v5; // rdi

  v3 = points;
  v5 = &points[numPoints];
  if ( points != v5 )
  {
    do
      hkFindClosestPositionUtil::addPoint(this, v3++, 0i64);
    while ( v3 != v5 );
  }
}

// File Line: 379
// RVA: 0xC9CDE0
__int64 __fastcall hkFindClosestPositionUtil::findClosestLinearly(hkFindClosestPositionUtil *this, hkVector4f *p)
{
  hkVector4f *m_data; // r8
  __m128 v3; // xmm4
  __m128i si128; // xmm5
  hkVector4f *v5; // rax
  __m128i v6; // xmm8
  __m128 m_quad; // xmm1
  __m128 v8; // xmm1
  __m128 v9; // xmm1
  __m128 v10; // xmm2
  __m128i v11; // xmm3
  __m128i v12; // xmm0

  m_data = this->m_positions.m_data;
  v3 = (__m128)xmmword_141A712A0;
  si128 = _mm_load_si128((const __m128i *)&_xmm_ffffffffffffffffffffffffffffffff);
  v5 = &this->m_positions.m_data[this->m_positions.m_size];
  v6 = 0i64;
  if ( this->m_positions.m_data != v5 )
  {
    do
    {
      m_quad = m_data->m_quad;
      ++m_data;
      v8 = _mm_sub_ps(m_quad, p->m_quad);
      v9 = _mm_mul_ps(v8, v8);
      v10 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)), _mm_shuffle_ps(v9, v9, 170));
      v11 = (__m128i)_mm_cmplt_ps(v10, v3);
      v3 = _mm_or_ps(_mm_and_ps((__m128)v11, v10), _mm_andnot_ps((__m128)v11, v3));
      si128 = _mm_or_si128(_mm_andnot_si128(v11, si128), _mm_and_si128(v11, v6));
      v6 = _mm_add_epi32((__m128i)xmmword_141A72090, v6);
    }
    while ( m_data != v5 );
  }
  v12 = (__m128i)_mm_cmplt_ps(v3, _mm_mul_ps(this->m_threshold.m_real, this->m_threshold.m_real));
  return (unsigned int)_mm_cvtsi128_si32(
                         _mm_or_si128(
                           _mm_and_si128(v12, si128),
                           _mm_andnot_si128(v12, (__m128i)_xmm_ffffffffffffffffffffffffffffffff)));
}

// File Line: 516
// RVA: 0xC9CC50
__int64 __fastcall hkFindClosestPositionUtil::getSizeInBytesFor(unsigned int numPoints)
{
  return 16i64 * numPoints;
}

// File Line: 522
// RVA: 0xC9CC60
void __fastcall hkFindClosestPositionUtil::setBuffer(
        hkFindClosestPositionUtil *this,
        hkVector4f *buffer,
        int numPoints)
{
  this->m_positions.m_data = buffer;
  this->m_positions.m_size = 0;
  this->m_positions.m_capacityAndFlags = numPoints | 0x80000000;
}

