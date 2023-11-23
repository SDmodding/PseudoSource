// File Line: 31
// RVA: 0x12F6520
void __fastcall hkaiNewFaceCutterUtil::Input::calcExtents(
        hkVector4f *u,
        hkVector4f *v,
        hkArrayBase<hkVector4f> *points,
        hkVector4f *extentsOut)
{
  __m128 m_quad; // xmm5
  __m128 v5; // xmm2
  __int64 m_size; // rcx
  __m128 v7; // xmm3
  __m128 v8; // xmm2
  __m128 v9; // xmm3
  __m128 v10; // xmm0
  __m128 v11; // xmm6
  __m128 v12; // xmm4
  __m128 v13; // xmm6
  __m128 v14; // xmm5
  __m128 v15; // xmm3
  hkVector4f *v16; // rax
  __int64 v17; // rcx
  __m128 v18; // xmm1

  m_quad = u->m_quad;
  v5 = u->m_quad;
  m_size = points->m_size;
  v7 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
  v8 = _mm_xor_ps(v5, v7);
  v9 = _mm_xor_ps(v7, v->m_quad);
  v10 = _mm_shuffle_ps(v->m_quad, v9, 68);
  v11 = _mm_shuffle_ps(m_quad, v8, 68);
  v12 = _mm_shuffle_ps(v11, v10, 221);
  v13 = _mm_shuffle_ps(v11, v10, 136);
  v14 = _mm_shuffle_ps(_mm_shuffle_ps(m_quad, v8, 238), _mm_shuffle_ps(v->m_quad, v9, 238), 136);
  v15 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(points->m_data->m_quad, points->m_data->m_quad, 85), v12),
            _mm_mul_ps(_mm_shuffle_ps(points->m_data->m_quad, points->m_data->m_quad, 0), v13)),
          _mm_mul_ps(_mm_shuffle_ps(points->m_data->m_quad, points->m_data->m_quad, 170), v14));
  if ( m_size > 1 )
  {
    v16 = points->m_data + 1;
    v17 = m_size - 1;
    do
    {
      v18 = v16->m_quad;
      ++v16;
      v15 = _mm_min_ps(
              v15,
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v18, v18, 85), v12), _mm_mul_ps(_mm_shuffle_ps(v18, v18, 0), v13)),
                _mm_mul_ps(_mm_shuffle_ps(v18, v18, 170), v14)));
      --v17;
    }
    while ( v17 );
  }
  extentsOut->m_quad = _mm_mul_ps(v15, (__m128)xmmword_141A71320);
}

// File Line: 54
// RVA: 0x12F5F10
bool __fastcall hkaiNewFaceCutterUtil::Input::isSimplePolygon(hkArrayBase<hkaiNewFaceCutterUtil::Vec2> *iv)
{
  __int64 m_size; // r9
  signed int v3; // r9d
  unsigned int v4; // ecx
  hkaiNewFaceCutterUtil::Vec2 *m_data; // rbx
  unsigned int m_xy; // eax
  hkaiNewFaceCutterUtil::Vec2 *v7; // rdx
  __int64 v8; // r8
  unsigned int v9; // eax
  __int64 v10; // r10
  __int64 v11; // rdi
  unsigned int v12; // edx
  int v13; // r8d

  m_size = iv->m_size;
  if ( (int)m_size <= 2 )
    return 1;
  if ( (_DWORD)m_size == 3 )
  {
    v3 = iv->m_data[1].m_xy - iv->m_data->m_xy + 2 * ((LOWORD(iv->m_data[1].m_xy) - iv->m_data->m_xy) & 0x8000);
    v4 = iv->m_data[2].m_xy - iv->m_data->m_xy;
    return (__int16)(v4 + 2 * (v4 & 0x8000)) * (v3 >> 16) - (__int16)v3 * ((int)(v4 + 2 * (v4 & 0x8000)) >> 16) >= 0;
  }
  else
  {
    m_data = iv->m_data;
    m_xy = iv->m_data->m_xy;
    v7 = m_data + 1;
    v8 = m_size - 1;
    do
    {
      v9 = v7->m_xy + m_xy;
      ++v7;
      m_xy = (v9 >> 1) & 0x3FFF3FFF;
      --v8;
    }
    while ( v8 );
    v10 = 0i64;
    v11 = (int)m_size - 1;
    while ( 1 )
    {
      v12 = m_data[v11].m_xy;
      v11 = v10;
      v13 = m_data[v10].m_xy - m_xy + 2 * ((LOWORD(m_data[v10].m_xy) - (_WORD)m_xy) & 0x8000);
      if ( (__int16)v13 * ((int)(v12 - m_xy + 2 * (((_WORD)v12 - (_WORD)m_xy) & 0x8000)) >> 16)
         - (__int16)(v12 - m_xy + 2 * ((v12 - m_xy) & 0x8000)) * (v13 >> 16) < 0 )
        break;
      if ( ++v10 >= m_size )
        return 1;
    }
    return 0;
  }
}

// File Line: 100
// RVA: 0x12F7030
void __fastcall hkaiNewFaceCutterUtil::Input::rotateArray<hkaiNewFaceCutterUtil::Vec2>(
        hkaiNewFaceCutterUtil::Vec2 *data,
        int n,
        int offset)
{
  __int64 v3; // rsi
  __int64 v4; // rdi
  hkLifoAllocator *Value; // rax
  char *m_cur; // rbx
  int v8; // r14d
  char *v9; // rcx
  int v10; // edi
  hkLifoAllocator *v11; // rax
  int v12; // r8d

  if ( offset )
  {
    v3 = offset;
    v4 = n;
    if ( offset != n )
    {
      Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      m_cur = (char *)Value->m_cur;
      v8 = (4 * v4 + 127) & 0xFFFFFF80;
      v9 = &m_cur[v8];
      if ( v8 > Value->m_slabSize || v9 > Value->m_end )
        m_cur = (char *)hkLifoAllocator::allocateFromNewSlab(Value, v8);
      else
        Value->m_cur = v9;
      if ( (int)v4 > 0 )
        memmove(m_cur, data, 4 * v4);
      if ( (int)v3 > 0 )
        memmove(data, &m_cur[4 * (v4 - v3)], 4 * v3);
      v10 = v4 - v3;
      if ( v10 > 0 )
        memmove(&data[v3], m_cur, 4i64 * v10);
      v11 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v12 = (v8 + 15) & 0xFFFFFFF0;
      if ( v8 > v11->m_slabSize || &m_cur[v12] != v11->m_cur || v11->m_firstNonLifoEnd == m_cur )
        hkLifoAllocator::slowBlockFree(v11, m_cur, v12);
      else
        v11->m_cur = m_cur;
    }
  }
}

// File Line: 114
// RVA: 0x12F6050
void __fastcall hkaiNewFaceCutterUtil::Input::makeConvexHull(hkArrayBase<hkaiNewFaceCutterUtil::Vec2> *vertices)
{
  __int64 m_size; // rdi
  int v2; // r12d
  int v3; // r14d
  hkArrayBase<hkaiNewFaceCutterUtil::Vec2> *v4; // r13
  int v5; // r11d
  int v6; // r9d
  __int64 v7; // r8
  __int64 v8; // rdx
  __int64 v9; // rcx
  unsigned int m_xy; // eax
  hkaiNewFaceCutterUtil::Vec2 *v11; // rdx
  __int64 v12; // rdx
  __int64 v13; // rcx
  unsigned int v14; // r9d
  hkaiNewFaceCutterUtil::Vec2 *m_data; // rax
  __int64 v16; // rdx
  unsigned int v17; // ecx
  hkaiNewFaceCutterUtil::Vec2 *v18; // rdi
  int v19; // r14d
  unsigned int v20; // eax
  int v21; // r9d
  __int64 v22; // r11
  int v23; // r10d
  int v24; // esi
  int v25; // r10d
  int v26; // edx
  int v27; // ebp
  int v28; // edx
  bool v29; // sf
  bool v30; // of
  int v31; // ebx
  __int64 v32; // rsi
  __int64 i; // rcx
  unsigned int v34; // edx
  __int64 v35; // r11
  int v36; // r8d
  int v38; // [rsp+80h] [rbp+18h]
  __int64 v39; // [rsp+88h] [rbp+20h]

  m_size = vertices->m_size;
  v2 = 0;
  v3 = 1;
  v4 = vertices;
  v5 = 0;
  v38 = 1;
  v6 = 1;
  v7 = 1i64;
  if ( m_size > 1 )
  {
    v8 = 0i64;
    do
    {
      if ( vertices->m_data[v7].m_xy < vertices->m_data[v8].m_xy )
      {
        v5 = v6;
        v8 = v7;
      }
      ++v7;
      ++v6;
    }
    while ( v7 < m_size );
  }
  hkaiNewFaceCutterUtil::Input::rotateArray<hkaiNewFaceCutterUtil::Vec2>(vertices->m_data, m_size, m_size - v5);
  v9 = 1i64;
  m_xy = v4->m_data->m_xy;
  if ( m_size > 1 )
  {
    v11 = v4->m_data + 1;
    do
    {
      if ( v11->m_xy == m_xy )
        break;
      ++v9;
      ++v3;
      ++v11;
    }
    while ( v9 < m_size );
    v38 = v3;
  }
  v12 = v3 + 1;
  if ( v12 < m_size )
  {
    v13 = v3;
    do
    {
      v14 = v4->m_data[v12].m_xy;
      if ( v14 != m_xy )
      {
        v4->m_data[v13].m_xy = v14;
        ++v3;
        ++v13;
      }
      ++v12;
    }
    while ( v12 < m_size );
    v38 = v3;
  }
  m_data = v4->m_data;
  v4->m_size = v3;
  v16 = 0i64;
  v17 = m_data->m_xy;
  v18 = m_data + 1;
  v39 = 0i64;
  if ( v3 - 1 > 0 )
  {
    v19 = v3 - 1;
    do
    {
      v20 = v18[v16].m_xy;
      v21 = v2;
      v22 = v16;
      if ( v2 > 0 )
      {
        do
        {
          v23 = v20 - v17 + 2 * (((_WORD)v20 - (_WORD)v17) & 0x8000);
          v24 = (__int16)v23;
          v25 = v23 >> 16;
          v26 = v18[v22 - 1].m_xy - v17 + 2 * ((LOWORD(v18[v22 - 1].m_xy) - (_WORD)v17) & 0x8000);
          v27 = (__int16)v26;
          v28 = v26 >> 16;
          v30 = __OFSUB__(v24 * v28, v25 * v27);
          v29 = v24 * v28 - v25 * v27 < 0;
          if ( v24 * v28 == v25 * v27 )
          {
            v30 = __OFSUB__(v25, v28);
            v29 = v25 - v28 < 0;
            if ( v25 == v28 )
            {
              v30 = __OFSUB__(v24, v27);
              v29 = v24 - v27 < 0;
            }
          }
          if ( v29 == v30 )
            break;
          --v21;
          v18[v22] = v18[v22 - 1];
          --v22;
        }
        while ( v21 > 0 );
        v16 = v39;
      }
      ++v16;
      ++v2;
      v18[v22].m_xy = v20;
      v39 = v16;
    }
    while ( v2 < v19 );
    v3 = v38;
    v4 = vertices;
  }
  v31 = 2;
  v32 = 2i64;
  for ( i = 2i64; v32 < v3; ++v32 )
  {
    v34 = v4->m_data[v32].m_xy;
    if ( v34 != v4->m_data[i - 1].m_xy )
    {
      v4->m_data[i++].m_xy = v34;
      ++v31;
      if ( i > 3 )
      {
        v35 = 4 * i - 8;
        do
        {
          v36 = *(unsigned int *)((char *)&v4->m_data[1].m_xy + v35)
              - *(unsigned int *)((char *)&v4->m_data[-1].m_xy + v35)
              + 2
              * ((*(_WORD *)((char *)&v4->m_data[1].m_xy + v35) - *(_WORD *)((char *)&v4->m_data[-1].m_xy + v35)) & 0x8000);
          if ( (__int16)v36
             * ((signed int)(*(unsigned int *)((char *)&v4->m_data->m_xy + v35)
                           - *(unsigned int *)((char *)&v4->m_data[-1].m_xy + v35)
                           + 2
                           * ((*(_WORD *)((char *)&v4->m_data->m_xy + v35)
                             - *(_WORD *)((char *)&v4->m_data[-1].m_xy + v35)) & 0x8000)) >> 16)
             - (__int16)(*(_WORD *)((char *)&v4->m_data->m_xy + v35)
                       - *(_WORD *)((char *)&v4->m_data[-1].m_xy + v35)
                       + 2
                       * ((*(_WORD *)((char *)&v4->m_data->m_xy + v35) - *(_WORD *)((char *)&v4->m_data[-1].m_xy + v35)) & 0x8000))
             * (v36 >> 16) >= 0 )
            break;
          --i;
          *(unsigned int *)((char *)&v4->m_data->m_xy + v35) = *(unsigned int *)((char *)&v4->m_data[1].m_xy + v35);
          --v31;
          v35 -= 4i64;
        }
        while ( i > 3 );
      }
    }
  }
  v4->m_size = v31;
}

// File Line: 188
// RVA: 0x12F6600
void __fastcall hkaiNewFaceCutterUtil::Input::ensureSimple(hkArrayBase<hkaiNewFaceCutterUtil::Vec2> *vertices)
{
  if ( !hkaiNewFaceCutterUtil::Input::isSimplePolygon(vertices) )
    hkaiNewFaceCutterUtil::Input::makeConvexHull(vertices);
}

// File Line: 207
// RVA: 0x12F6630
__int64 __fastcall hkaiNewFaceCutterUtil::Input::getSideMask_reference(hkaiNewFaceCutterUtil::Vec2 v)
{
  return (HIWORD(v.m_xy) == 0) | (2 * (LOWORD(v.m_xy) == 0)) | (4 * (HIWORD(v.m_xy) == 0x3FFF)) | (8
                                                                                                 * (unsigned int)(LOWORD(v.m_xy) == 0x3FFF));
}

// File Line: 216
// RVA: 0x12F6680
__int64 __fastcall hkaiNewFaceCutterUtil::Input::getSideMask(hkaiNewFaceCutterUtil::Vec2 v)
{
  return ((v.m_xy + 65537) & 0x4000 | ((~((v.m_xy | 0x40004000) - 65537) & 0x4000 | (((~((v.m_xy | 0x40004000) - 65537) >> 2) & 0x10000000 | (v.m_xy + 65537) & 0x40000000) >> 15)) >> 2)) >> 11;
}

// File Line: 239
// RVA: 0x12F5DC0
void __fastcall hkaiNewFaceCutterUtil::Input::addBoundaryPoints(
        hkaiNewFaceCutterUtil::Vec2 a,
        hkaiNewFaceCutterUtil::Vec2 b,
        hkArrayBase<hkaiNewFaceCutterUtil::Vec2> *iv)
{
  unsigned int SideMask; // edi
  unsigned int v6; // eax
  unsigned int v7; // ebx
  unsigned int v8; // eax
  hkErrStream v9; // [rsp+20h] [rbp-228h] BYREF
  char buf[512]; // [rsp+40h] [rbp-208h] BYREF

  SideMask = hkaiNewFaceCutterUtil::Input::getSideMask(a);
  v6 = hkaiNewFaceCutterUtil::Input::getSideMask(b);
  v7 = v6;
  if ( SideMask && v6 && (v6 & SideMask) == 0 )
  {
    do
    {
      switch ( SideMask )
      {
        case 1u:
        case 9u:
          SideMask = 3;
          goto LABEL_12;
        case 2u:
        case 3u:
          v8 = 1073676288;
          SideMask = 6;
          break;
        case 4u:
        case 6u:
          v8 = 1073692671;
          SideMask = 12;
          break;
        case 8u:
        case 0xCu:
          v8 = 0x3FFF;
          SideMask = 9;
          break;
        default:
          hkErrStream::hkErrStream(&v9, buf, 512);
          hkOstream::operator<<(&v9, "unexpected side mask");
          if ( (unsigned int)hkError::messageError(0xFDB72FF4, buf, "NewFaceCutter\\hkaiNewFaceCutterInput.cpp", 287) )
            __debugbreak();
          hkOstream::~hkOstream(&v9);
LABEL_12:
          v8 = 0;
          break;
      }
      iv->m_data[iv->m_size++].m_xy = v8;
    }
    while ( (v7 & SideMask) == 0 );
  }
}

// File Line: 299
// RVA: 0x12F6320
char __fastcall hkaiNewFaceCutterUtil::Input::isConvexHull(hkArrayBase<hkaiNewFaceCutterUtil::Vec2> *vertices)
{
  int m_size; // r9d
  char v2; // si
  __int64 v3; // r8
  hkaiNewFaceCutterUtil::Vec2 *m_data; // r15
  __int64 v5; // rdi
  __int64 v6; // rax
  unsigned int v7; // ecx
  unsigned int v8; // eax
  __int64 v9; // r14
  int v10; // r11d

  m_size = vertices->m_size;
  v2 = 0;
  v3 = 0i64;
  if ( m_size <= 0 )
    return 1;
  m_data = vertices->m_data;
  v5 = 4i64 * (m_size - 1);
  v6 = 4i64 * (m_size - 2);
  while ( 1 )
  {
    v7 = *(unsigned int *)((char *)&m_data->m_xy + v6);
    v8 = *(unsigned int *)((char *)&m_data->m_xy + v5);
    v9 = 4 * v3;
    v10 = m_data[v3].m_xy - v7 + 2 * ((LOWORD(m_data[v3].m_xy) - (_WORD)v7) & 0x8000);
    if ( (__int16)v10 * ((int)(v8 - v7 + 2 * ((*(_WORD *)((char *)&m_data->m_xy + v5) - (_WORD)v7) & 0x8000)) >> 16)
       - (__int16)(*(_WORD *)((char *)&m_data->m_xy + v5)
                 - v7
                 + 2 * ((*(_WORD *)((char *)&m_data->m_xy + v5) - v7) & 0x8000))
       * (v10 >> 16) < 0
      || v7 == v8 )
    {
      break;
    }
    if ( v8 < v7 && v8 < m_data[v3].m_xy )
    {
      if ( v2 )
        return 0;
      v2 = 1;
    }
    ++v3;
    v6 = v5;
    v5 = v9;
    if ( v3 >= m_size )
      return 1;
  }
  return 0;
}

// File Line: 334
// RVA: 0x12F6420
void __fastcall hkaiNewFaceCutterUtil::Input::findMaximalCaliper(
        hkArrayBase<hkaiNewFaceCutterUtil::Vec2> *iv,
        int *iOut,
        int *jOut)
{
  int v3; // esi
  int v5; // edx
  int v6; // ebp
  int v7; // edi
  int v8; // ebx
  __int64 m_size; // r13
  hkaiNewFaceCutterUtil::Vec2 *m_data; // r15
  __int64 v11; // r14
  unsigned int m_xy; // eax
  int v13; // r12d
  int v14; // r9d
  hkaiNewFaceCutterUtil::Vec2 *v15; // r10
  __int64 v16; // r11
  int v17; // edx
  int v18; // r8d
  int v19; // [rsp+40h] [rbp+8h]

  v3 = 0;
  v5 = iv->m_size - 1;
  v6 = 0;
  v7 = 0;
  v8 = 0;
  m_size = iv->m_size;
  v19 = v5;
  if ( v5 <= 0 )
  {
    *iOut = 0;
    *jOut = 0;
  }
  else
  {
    m_data = iv->m_data;
    v11 = 1i64;
    do
    {
      m_xy = m_data->m_xy;
      v13 = v8 + 1;
      v14 = v8 + 1;
      if ( v11 < m_size )
      {
        v15 = m_data + 1;
        v16 = m_size - v11;
        do
        {
          v17 = v15->m_xy - m_xy + 2 * ((LOWORD(v15->m_xy) - (_WORD)m_xy) & 0x8000);
          v18 = (__int16)(LOWORD(v15->m_xy) - m_xy + 2 * ((LOWORD(v15->m_xy) - m_xy) & 0x8000));
          if ( v18 * v18 + (v17 >> 16) * (v17 >> 16) > v7 )
          {
            v3 = v8;
            v6 = v14;
            v7 = v18 * v18 + (v17 >> 16) * (v17 >> 16);
          }
          ++v14;
          ++v15;
          --v16;
        }
        while ( v16 );
        v5 = v19;
      }
      ++m_data;
      ++v11;
      ++v8;
    }
    while ( v13 < v5 );
    *iOut = v3;
    *jOut = v6;
  }
}

// File Line: 361
// RVA: 0x12F66D0
void __fastcall hkaiNewFaceCutterUtil::Input::makeUniqueWithMapping(
        hkArrayBase<hkaiNewFaceCutterUtil::Vec2> *vertices,
        hkArrayBase<short> *uniqueMapping)
{
  int m_size; // esi
  int v3; // r9d
  unsigned int m_xy; // r8d
  int v6; // edx
  __int64 v7; // rbx
  __int64 v8; // rdi
  unsigned int v9; // eax

  m_size = vertices->m_size;
  v3 = 1;
  uniqueMapping->m_data[uniqueMapping->m_size++] = 0;
  m_xy = vertices->m_data->m_xy;
  v6 = 1;
  if ( m_size > 1 )
  {
    v7 = 1i64;
    v8 = 1i64;
    do
    {
      v9 = vertices->m_data[v8].m_xy;
      if ( v9 != m_xy )
      {
        ++uniqueMapping->m_size;
        ++v3;
        vertices->m_data[v7++].m_xy = v9;
        m_xy = v9;
      }
      ++v8;
      uniqueMapping->m_data[uniqueMapping->m_size - 1] = v6++;
    }
    while ( v6 < m_size );
    if ( v3 >= 2 && vertices->m_data->m_xy == vertices->m_data[v3 - 1].m_xy )
    {
      --uniqueMapping->m_size;
      --v3;
    }
  }
  vertices->m_size = v3;
}

// File Line: 390
// RVA: 0x12F6780
void __fastcall hkaiNewFaceCutterUtil::Input::makeFacePolygonSimple(hkArrayBase<hkaiNewFaceCutterUtil::Vec2> *iv)
{
  int m_size; // ebx
  hkArrayBase<hkaiNewFaceCutterUtil::Vec2> *v2; // rbp
  __int64 v3; // rsi
  unsigned int m_xy; // r8d
  __int64 v5; // r15
  unsigned int v6; // r14d
  int v7; // r11d
  int v8; // edi
  int v9; // eax
  unsigned int v10; // r9d
  int v11; // edx
  unsigned int v12; // ebx
  unsigned int v13; // r10d
  int v14; // ecx
  int v15; // r12d
  int v16; // ebx
  int v17; // r14d
  int v18; // r11d
  int v19; // eax
  __int64 v20; // rdx
  __int128 v21; // rtt
  __int64 v22; // rdx
  int v23; // r10d
  int v24; // r11d
  int v25; // eax
  int v26; // eax
  int v27; // ebx
  unsigned int v28; // r8d
  unsigned int v29; // r9d
  __int64 v30; // r13
  int v31; // r12d
  unsigned int v32; // r8d
  unsigned int v33; // ecx
  int v34; // ebp
  int v35; // edx
  unsigned int v36; // r10d
  __int64 v37; // r14
  int v38; // edi
  int v39; // r10d
  int v40; // ebx
  int v41; // r8d
  int v42; // eax
  __int64 v43; // rdx
  __int128 v44; // rtt
  __int64 v45; // rdx
  int v46; // ecx
  int v47; // r11d
  int v48; // eax
  int v49; // eax
  int v50; // edx
  int v51; // [rsp+20h] [rbp-88h]
  unsigned int v52; // [rsp+20h] [rbp-88h]
  int v53; // [rsp+24h] [rbp-84h]
  int v54; // [rsp+28h] [rbp-80h]
  int iOut; // [rsp+2Ch] [rbp-7Ch] BYREF
  unsigned int v56; // [rsp+30h] [rbp-78h]
  int v57; // [rsp+34h] [rbp-74h]
  int v58; // [rsp+38h] [rbp-70h]
  unsigned int v59; // [rsp+3Ch] [rbp-6Ch]
  unsigned int v60; // [rsp+40h] [rbp-68h]
  hkaiNewFaceCutterUtil::Vec2 *v61; // [rsp+48h] [rbp-60h]
  int jOut; // [rsp+B8h] [rbp+10h] BYREF
  int v64; // [rsp+C0h] [rbp+18h]
  unsigned int v65; // [rsp+C8h] [rbp+20h]

  m_size = iv->m_size;
  v2 = iv;
  hkaiNewFaceCutterUtil::Input::findMaximalCaliper(iv, &iOut, &jOut);
  v3 = jOut;
  m_xy = v2->m_data[iOut].m_xy;
  v5 = iOut;
  v59 = v2->m_data[jOut].m_xy;
  v6 = HIWORD(v59);
  v7 = (unsigned __int16)m_xy;
  v8 = iOut;
  v65 = HIWORD(v59);
  v64 = (unsigned __int16)m_xy;
  v53 = (int)(v59 - m_xy + 2 * (((_WORD)v59 - (_WORD)m_xy) & 0x8000)) >> 16;
  v54 = (__int16)(v59 - m_xy + 2 * ((v59 - m_xy) & 0x8000));
  v9 = m_size - 1;
  jOut = (unsigned __int16)v59;
  v10 = HIWORD(m_xy);
  v11 = (unsigned __int16)v59 - (unsigned __int16)m_xy;
  v12 = HIWORD(v59) - HIWORD(m_xy);
  v57 = v9;
  v56 = HIWORD(m_xy);
  v60 = v12;
  v51 = v11;
  do
  {
    if ( v8 == v9 )
    {
      v8 = 0;
      v5 = 0i64;
    }
    else
    {
      ++v8;
      ++v5;
    }
    v13 = v2->m_data[v5].m_xy;
    v61 = &v2->m_data[v5];
    v58 = (unsigned __int16)v13;
    v14 = v12 * ((unsigned __int16)v13 - v7) - v11 * (HIWORD(v13) - v10);
    if ( v14 > 0 )
    {
      v16 = v10 - v6;
      v15 = v7 - jOut;
      v17 = jOut - v7;
      v18 = v16 * v16 + v15 * v15;
      v19 = v18;
      v20 = v14 * (__int64)v17;
      if ( v20 < 0 )
      {
        v20 = -v20;
        v19 = -v18;
      }
      v21 = v20 + ((__int64)(v19 ^ (unsigned __int64)((__int64)v19 >> 30)) >> 1);
      v22 = v14 * (__int64)v16;
      v23 = v21 / v19 + HIWORD(v13);
      if ( v22 < 0 )
      {
        v22 = -v22;
        v18 = -v18;
      }
      v24 = v58 + (v22 + ((__int64)(v18 ^ (unsigned __int64)((__int64)v18 >> 30)) >> 1)) / v18;
      if ( (int)(v16 * (v24 - jOut) - v15 * (v23 - v65)) < 0 )
      {
        if ( (int)abs32(v17) <= (int)abs32(v16) )
        {
          v26 = -1;
          if ( v16 > 0 )
            v26 = 1;
          v24 += v26;
        }
        else
        {
          v25 = -1;
          if ( v17 > 0 )
            v25 = 1;
          v23 += v25;
        }
      }
      v6 = v65;
      v12 = v60;
      v13 = v24 | (v23 << 16);
      v7 = v64;
    }
    v2 = iv;
    v11 = v51;
    if ( v54 * (__int16)(v13 - m_xy + 2 * ((v13 - m_xy) & 0x8000))
       + v53 * ((int)(v13 - m_xy + 2 * (((_WORD)v13 - (_WORD)m_xy) & 0x8000)) >> 16) < 0 )
      v13 = m_xy;
    v61->m_xy = v13;
    v9 = v57;
    m_xy = v13;
  }
  while ( v8 != (_DWORD)v3 );
  v27 = jOut;
  v28 = v10;
  v29 = v59;
  v30 = v3;
  v31 = v7 - jOut;
  v32 = v28 - v6;
  v52 = v32;
  do
  {
    if ( (_DWORD)v3 == v57 )
    {
      LODWORD(v3) = 0;
      v30 = 0i64;
    }
    else
    {
      LODWORD(v3) = v3 + 1;
      ++v30;
    }
    v33 = iv->m_data[v30].m_xy;
    v34 = (unsigned __int16)v33;
    v35 = v32 * ((unsigned __int16)v33 - v27) - v31 * (HIWORD(v33) - v6);
    if ( v35 > 0 )
    {
      v36 = v6;
      v37 = v35;
      v38 = v27 - v64;
      v39 = v36 - v56;
      v40 = v64 - v27;
      v41 = v39 * v39 + v38 * v38;
      v42 = v41;
      v43 = v35 * (__int64)v40;
      if ( v43 < 0 )
      {
        v43 = -v43;
        v42 = -v41;
      }
      v44 = v43 + ((__int64)(v42 ^ (unsigned __int64)((__int64)v42 >> 30)) >> 1);
      v45 = v37 * v39;
      v46 = HIWORD(v33) + v44 / v42;
      if ( v45 < 0 )
      {
        v45 = -v45;
        v41 = -v41;
      }
      v47 = (v45 + ((__int64)(v41 ^ (unsigned __int64)((__int64)v41 >> 30)) >> 1)) / v41 + v34;
      if ( (int)(v39 * (v47 - v64) - v38 * (v46 - v56)) < 0 )
      {
        if ( (int)abs32(v40) <= (int)abs32(v39) )
        {
          v49 = -1;
          if ( v39 > 0 )
            v49 = 1;
          v47 += v49;
        }
        else
        {
          v48 = -1;
          if ( v40 > 0 )
            v48 = 1;
          v46 += v48;
        }
      }
      v6 = v65;
      v27 = jOut;
      v33 = v47 | (v46 << 16);
    }
    v50 = v33 - v29 + 2 * (((_WORD)v33 - (_WORD)v29) & 0x8000);
    v32 = v52;
    if ( v54 * (__int16)v50 + v53 * (v50 >> 16) > 0 )
      v33 = v29;
    v29 = v33;
    iv->m_data[v30].m_xy = v33;
  }
  while ( (_DWORD)v3 != iOut );
}

// File Line: 460
// RVA: 0x12F6B90
void __fastcall hkaiNewFaceCutterUtil::Input::createSegmentsAndEventsForPolygon(
        hkaiNewFaceCutterUtil::State *state,
        hkArrayBase<hkaiNewFaceCutterUtil::Vec2> *vertices,
        hkaiNewFaceCutterUtil::Difference inwardDifference,
        hkArrayBase<short> *originalEdgeIndices)
{
  __int16 m_size; // r11
  int m_data_low; // eax
  __int64 v8; // r8
  hkArrayBase<hkaiNewFaceCutterUtil::Vec2> *v9; // r15
  hkaiNewFaceCutterUtil::State *v10; // r10
  hkArray<hkaiNewFaceCutterUtil::Segment,hkContainerHeapAllocator> *p_m_segments; // r14
  unsigned int v12; // ebp
  unsigned int m_xy; // esi
  unsigned int v14; // ebx
  __int16 *m_data; // rax
  bool v16; // r12
  __int16 v17; // r15
  __int64 v18; // rax
  __int16 v19; // di
  __int64 v20; // rcx
  __int64 v21; // r13
  bool v22; // si
  __int16 v23; // r12
  hkaiNewFaceCutterUtil::Vec2 *v24; // rax
  __int16 v25; // r15
  hkaiNewFaceCutterUtil::Vec2 v26; // edi
  int m_capacityAndFlags; // eax
  __int64 v28; // rax
  hkaiNewFaceCutterUtil::Segment *v29; // rax
  __int64 v30; // rcx
  bool v31; // [rsp+20h] [rbp-58h]
  bool v32; // [rsp+22h] [rbp-56h]
  __int16 v33; // [rsp+24h] [rbp-54h]
  __int16 v34; // [rsp+26h] [rbp-52h]
  __int64 v35; // [rsp+28h] [rbp-50h]
  hkArrayBase<short> *v39; // [rsp+98h] [rbp+20h]

  v39 = originalEdgeIndices;
  m_size = state->m_segments.m_size;
  m_data_low = LOWORD(inwardDifference.m_data);
  v8 = vertices->m_size;
  v9 = vertices;
  v10 = state;
  v35 = v8;
  p_m_segments = &state->m_segments;
  v12 = m_data_low | -(inwardDifference.m_data & 0xFFFF0000);
  v33 = m_size;
  m_xy = vertices->m_data[v8 - 1].m_xy;
  v14 = vertices->m_data->m_xy;
  m_data = originalEdgeIndices->m_data;
  v16 = m_xy < v14;
  v32 = m_xy < v14;
  if ( m_xy >= v14 )
  {
    v19 = m_data[v8 - 1];
    if ( state->m_segments.m_size == (state->m_segments.m_capacityAndFlags & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_segments->m_data, 28);
      v10 = state;
      m_size = v33;
      originalEdgeIndices = v39;
      v8 = v35;
    }
    ++p_m_segments->m_size;
    v18 = (__int64)&p_m_segments->m_data[m_size];
    *(_DWORD *)v18 = v14;
    *(_DWORD *)(v18 + 4) = m_xy;
    *(_DWORD *)(v18 + 8) = v12;
    *(_WORD *)(v18 + 12) = v19;
  }
  else
  {
    v17 = m_data[v8 - 1];
    if ( state->m_segments.m_size == (state->m_segments.m_capacityAndFlags & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_segments->m_data, 28);
      v10 = state;
      m_size = v33;
      originalEdgeIndices = v39;
      v8 = v35;
    }
    ++p_m_segments->m_size;
    v18 = (__int64)&p_m_segments->m_data[m_size];
    *(_WORD *)(v18 + 12) = v17;
    v9 = vertices;
    *(_DWORD *)v18 = m_xy;
    *(_DWORD *)(v18 + 4) = v14;
    *(hkaiNewFaceCutterUtil::Difference *)(v18 + 8) = inwardDifference;
  }
  v20 = 0i64;
  v21 = 1i64;
  *(_WORD *)(v18 + 16) = -1;
  v22 = m_xy < v14;
  v31 = v16;
  *(_WORD *)(v18 + 14) = 0;
  v23 = m_size;
  *(_WORD *)(v18 + 22) = -1;
  if ( v8 > 1 )
  {
    while ( 1 )
    {
      v24 = v9->m_data;
      v25 = v10->m_segments.m_size;
      v26.m_xy = v14;
      v14 = v24[v21].m_xy;
      v34 = originalEdgeIndices->m_data[v20];
      m_capacityAndFlags = p_m_segments->m_capacityAndFlags;
      if ( v26.m_xy >= v14 )
        break;
      if ( p_m_segments->m_size == (m_capacityAndFlags & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_segments->m_data, 28);
        v10 = state;
        v8 = v35;
      }
      ++p_m_segments->m_size;
      v28 = (__int64)&p_m_segments->m_data[v25];
      *(_WORD *)(v28 + 12) = v34;
      *(hkaiNewFaceCutterUtil::Vec2 *)v28 = v26;
      *(_DWORD *)(v28 + 4) = v14;
      *(hkaiNewFaceCutterUtil::Difference *)(v28 + 8) = inwardDifference;
      *(_WORD *)(v28 + 22) = -1;
      *(_WORD *)(v28 + 14) = 0;
      *(_WORD *)(v28 + 16) = -1;
      if ( !v31 )
      {
        hkaiNewFaceCutterUtil::enqueueStartSegmentsEventNoHeapify(v10, v25, v23, v26);
LABEL_19:
        v8 = v35;
        goto LABEL_20;
      }
      p_m_segments->m_data[v23].m_followingSegment = v25;
LABEL_20:
      v22 = v26.m_xy < v14;
      v10 = state;
      originalEdgeIndices = v39;
      v20 = v21++;
      v23 = v25;
      v9 = vertices;
      v31 = v26.m_xy < v14;
      if ( v21 >= v8 )
      {
        m_size = v33;
        goto LABEL_22;
      }
    }
    if ( p_m_segments->m_size == (m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_segments->m_data, 28);
    ++p_m_segments->m_size;
    v29 = p_m_segments->m_data;
    v30 = v25;
    v29[v30].m_originalEdgeIndex = v34;
    v29[v30].m_a.m_xy = v14;
    v29[v30].m_b = v26;
    v29[v30].m_difference.m_data = v12;
    v29[v30].m_generation = 0;
    v29[v30].m_aboveRegion = -1;
    v29[v30].m_followingSegment = -1;
    if ( !v22 )
      p_m_segments->m_data[v30].m_followingSegment = v23;
    goto LABEL_19;
  }
LABEL_22:
  if ( v32 )
  {
    if ( v22 )
      p_m_segments->m_data[v23].m_followingSegment = m_size;
    else
      hkaiNewFaceCutterUtil::enqueueStartSegmentsEventNoHeapify(state, m_size, v23, (hkaiNewFaceCutterUtil::Vec2)v14);
  }
  else if ( !v22 )
  {
    p_m_segments->m_data[m_size].m_followingSegment = v23;
  }
}

// File Line: 557
// RVA: 0x12F6F10
char __fastcall hkaiNewFaceCutterUtil::Input::domainOriginInConvexPolygon(
        hkaiNewFaceCutterUtil::State *state,
        hkArrayBase<hkVector4f> *vertices)
{
  __int64 m_size; // r8
  hkVector4f *m_data; // r9
  hkVector4f v4; // xmm7
  __int64 v5; // rax
  hkVector4f v6; // xmm8
  __m128 m_quad; // xmm1
  hkVector4f v8; // xmm9
  hkVector4f v9; // xmm10
  __m128 v10; // xmm4
  __m128 v11; // xmm3

  m_size = vertices->m_size;
  m_data = vertices->m_data;
  v4.m_quad = (__m128)state->m_externalToInternal.m_col0;
  v5 = 0i64;
  v6.m_quad = (__m128)state->m_externalToInternal.m_col3;
  m_quad = vertices->m_data[(int)m_size - 1].m_quad;
  v8.m_quad = (__m128)state->m_externalToInternal.m_col1;
  v9.m_quad = (__m128)state->m_externalToInternal.m_col2;
  v10 = _mm_sub_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 0), v4.m_quad), v6.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 85), v8.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 170), v9.m_quad)),
          (__m128)_xmm);
  if ( (int)m_size <= 0 )
    return 1;
  while ( 1 )
  {
    v11 = _mm_sub_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(m_data->m_quad, m_data->m_quad, 0), v4.m_quad), v6.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(m_data->m_quad, m_data->m_quad, 85), v8.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(m_data->m_quad, m_data->m_quad, 170), v9.m_quad)),
            (__m128)_xmm);
    if ( (float)((float)(_mm_shuffle_ps(v11, v11, 85).m128_f32[0] * _mm_shuffle_ps(v10, v10, 0).m128_f32[0])
               - (float)(_mm_shuffle_ps(v11, v11, 0).m128_f32[0] * _mm_shuffle_ps(v10, v10, 85).m128_f32[0])) < 0.0 )
      break;
    ++v5;
    ++m_data;
    v10 = v11;
    if ( v5 >= m_size )
      return 1;
  }
  return 0;
}

// File Line: 593
// RVA: 0x12F51E0
void __fastcall hkaiNewFaceCutterUtil::setupDomain(
        hkaiNewFaceCutterUtil::State *state,
        hkVector4f *facePlaneIn,
        hkArrayBase<hkVector4f> *vertices)
{
  __m128i m_up; // xmm8
  __m128 m_quad; // xmm7
  __m128 v6; // xmm6
  __m128 v7; // xmm6
  __m128 v8; // xmm5
  __m128 v9; // xmm6
  __m128 v10; // xmm1
  __m128 v11; // xmm3
  __m128 v12; // xmm1
  __m128 v13; // xmm2
  __m128 v14; // xmm4
  __m128 v15; // xmm3
  __m128 v16; // xmm1
  __m128 v17; // xmm7
  __m128 v18; // xmm6
  __m128 v19; // xmm2
  __m128 v20; // xmm3
  __m128 v21; // xmm2
  __m128 v22; // xmm4
  __m128 v23; // xmm1
  __m128 v24; // xmm0
  __m128 v25; // xmm2
  hkVector4f v26; // xmm0
  hkVector4f v27; // xmm3
  hkVector4f v28; // xmm6
  hkVector4f v; // [rsp+20h] [rbp-68h] BYREF
  hkVector4f u; // [rsp+30h] [rbp-58h] BYREF
  hkVector4f extentsOut; // [rsp+40h] [rbp-48h] BYREF
  hkVector4f *result; // [rsp+98h] [rbp+10h] BYREF

  result = facePlaneIn;
  m_up = (__m128i)state->m_up;
  if ( (_mm_movemask_ps(_mm_cmpeq_ps(state->m_up.m_quad, stru_141A71280.m_quad)) & 7) == 7 )
  {
    m_quad = transform.m_quad;
    v6 = direction.m_quad;
  }
  else
  {
    v7 = _mm_shuffle_ps((__m128)m_up, _mm_unpackhi_ps((__m128)m_up, (__m128)0i64), 196);
    v8 = _mm_shuffle_ps(v7, v7, 241);
    v9 = _mm_shuffle_ps(v7, v7, 206);
    v10 = _mm_mul_ps(v8, v8);
    v11 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)),
            _mm_shuffle_ps(v10, v10, 170));
    v12 = _mm_mul_ps(v9, v9);
    v13 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)),
            _mm_shuffle_ps(v12, v12, 170));
    v14 = _mm_max_ps(v11, v13);
    v15 = _mm_cmplt_ps(v11, v13);
    v16 = _mm_rsqrt_ps(v14);
    v17 = _mm_xor_ps(
            _mm_or_ps(_mm_andnot_ps(v15, v8), _mm_and_ps(v9, v15)),
            (__m128)_mm_insert_epi16((__m128i)0i64, 0x8000u, 1));
    v18 = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(v17, v17, 201), (__m128)m_up),
            _mm_mul_ps(_mm_shuffle_ps((__m128)m_up, (__m128)m_up, 201), v17));
    v19 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v14, v16), v16)), _mm_mul_ps(*(__m128 *)_xmm, v16));
    m_quad = _mm_mul_ps(v17, v19);
    v6 = _mm_mul_ps(_mm_shuffle_ps(v18, v18, 201), v19);
  }
  v.m_quad = v6;
  u.m_quad = m_quad;
  hkaiNewFaceCutterUtil::Input::calcExtents(&u, &v, vertices, &extentsOut);
  v20 = extentsOut.m_quad;
  *(float *)&result = FLOAT_0_000061038882;
  v21 = extentsOut.m_quad;
  state->m_internalToExternal.m_col2 = (hkVector4f)m_up;
  v22 = _mm_shuffle_ps(v21, v21, 0);
  v23 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_000061038882), (__m128)LODWORD(FLOAT_0_000061038882), 0);
  v24 = _mm_shuffle_ps(v21, v20, 85);
  v25 = _mm_shuffle_ps(v21, v20, 170);
  v26.m_quad = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps(v24, v22), v23), m_quad);
  v27.m_quad = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps(_mm_shuffle_ps(v20, v20, 255), v25), v23), v6);
  state->m_internalToExternal.m_col0 = (hkVector4f)v26.m_quad;
  state->m_internalToExternal.m_col1 = (hkVector4f)v27.m_quad;
  state->m_internalToExternal.m_col0 = (hkVector4f)_mm_srli_si128(_mm_slli_si128((__m128i)v26.m_quad, 4), 4);
  v28.m_quad = _mm_add_ps(_mm_mul_ps(v6, v25), _mm_mul_ps(m_quad, v22));
  state->m_internalToExternal.m_col2 = (hkVector4f)_mm_srli_si128(_mm_slli_si128(m_up, 4), 4);
  state->m_internalToExternal.m_col1 = (hkVector4f)_mm_srli_si128(_mm_slli_si128((__m128i)v27.m_quad, 4), 4);
  state->m_internalToExternal.m_col3 = (hkVector4f)v28.m_quad;
  state->m_internalToExternal.m_col3.m_quad = _mm_shuffle_ps(v28.m_quad, _mm_unpackhi_ps(v28.m_quad, query.m_quad), 196);
  extentsOut.m_quad = aabbOut.m_quad;
  __hkMatrix4UtilAlgo::setInverse(
    (hkResult *)&result,
    &state->m_internalToExternal,
    &state->m_externalToInternal,
    (hkSimdFloat32 *)&extentsOut);
}

// File Line: 640
// RVA: 0x12F5410
void __fastcall hkaiNewFaceCutterUtil::createFacePolygon(
        hkaiNewFaceCutterUtil::State *state,
        hkArrayBase<hkVector4f> *vertices)
{
  __int64 m_size; // rdi
  __int16 *v3; // rbx
  hkLifoAllocator *Value; // rax
  hkaiNewFaceCutterUtil::Vec2 *m_cur; // rdx
  int v8; // r8d
  char *v9; // rcx
  __int64 v10; // r9
  __m128i si128; // xmm5
  __int64 v12; // r10
  __m128 m_quad; // xmm1
  __m128 v14; // xmm4
  __m128i v15; // xmm0
  __m128i v16; // xmm0
  __m128i v17; // xmm1
  __m128i v18; // xmm2
  hkLifoAllocator *v19; // rax
  int v20; // edx
  char *v21; // rcx
  signed int v22; // ebx
  hkLifoAllocator *v23; // rax
  int v24; // r8d
  signed int v25; // ebx
  hkLifoAllocator *v26; // rax
  int v27; // r8d
  hkArrayBase<hkaiNewFaceCutterUtil::Vec2> iv; // [rsp+20h] [rbp-60h] BYREF
  void *v29; // [rsp+30h] [rbp-50h]
  int v30; // [rsp+38h] [rbp-48h]
  hkArrayBase<short> uniqueMapping; // [rsp+40h] [rbp-40h] BYREF
  void *p; // [rsp+50h] [rbp-30h]
  int v33; // [rsp+58h] [rbp-28h]

  m_size = vertices->m_size;
  v3 = 0i64;
  v30 = m_size;
  if ( (_DWORD)m_size )
  {
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (hkaiNewFaceCutterUtil::Vec2 *)Value->m_cur;
    v8 = (4 * m_size + 127) & 0xFFFFFF80;
    v9 = (char *)m_cur + v8;
    if ( v8 > Value->m_slabSize || v9 > Value->m_end )
    {
      m_cur = (hkaiNewFaceCutterUtil::Vec2 *)hkLifoAllocator::allocateFromNewSlab(Value, v8);
      iv.m_data = m_cur;
    }
    else
    {
      Value->m_cur = v9;
      iv.m_data = m_cur;
    }
  }
  else
  {
    m_cur = 0i64;
    iv.m_data = 0i64;
  }
  v29 = m_cur;
  iv.m_size = m_size;
  v10 = 0i64;
  iv.m_capacityAndFlags = m_size | 0x80000000;
  if ( (int)m_size > 0 )
  {
    si128 = _mm_load_si128((const __m128i *)&_xmm);
    v12 = 0i64;
    do
    {
      ++v10;
      m_quad = vertices->m_data[v12++].m_quad;
      v14 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 0), state->m_externalToInternal.m_col0.m_quad),
                    state->m_externalToInternal.m_col3.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 85), state->m_externalToInternal.m_col1.m_quad)),
                _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 170), state->m_externalToInternal.m_col2.m_quad)),
              (__m128)xmmword_141A711B0);
      v15 = (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v14);
      v16 = _mm_or_si128(
              _mm_add_epi32(
                _mm_cvttps_epi32(
                  _mm_max_ps(
                    _mm_sub_ps(v14, _mm_and_ps((__m128)v15, *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31)),
                    (__m128)0i64)),
                _mm_slli_epi32(v15, 0x1Fu)),
              (__m128i)_mm_cmple_ps(
                         _mm_add_ps(
                           *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31,
                           *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31),
                         v14));
      v17 = _mm_cmpgt_epi32(v16, si128);
      v18 = _mm_or_si128(_mm_andnot_si128(v17, v16), _mm_and_si128(si128, v17));
      m_cur[v10 - 1].m_xy = (_mm_cvtsi128_si32(v18) << 16) | _mm_cvtsi128_si32(_mm_shuffle_epi32(v18, 85));
    }
    while ( v10 < m_size );
  }
  if ( !hkaiNewFaceCutterUtil::Input::isSimplePolygon(&iv) )
    hkaiNewFaceCutterUtil::Input::makeFacePolygonSimple(&iv);
  uniqueMapping.m_size = 0;
  v33 = m_size;
  if ( (_DWORD)m_size )
  {
    v19 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v3 = (__int16 *)v19->m_cur;
    v20 = (2 * m_size + 127) & 0xFFFFFF80;
    v21 = (char *)v3 + v20;
    if ( v20 > v19->m_slabSize || v21 > v19->m_end )
      v3 = (__int16 *)hkLifoAllocator::allocateFromNewSlab(v19, v20);
    else
      v19->m_cur = v21;
  }
  uniqueMapping.m_data = v3;
  uniqueMapping.m_capacityAndFlags = m_size | 0x80000000;
  p = v3;
  hkaiNewFaceCutterUtil::Input::makeUniqueWithMapping(&iv, &uniqueMapping);
  hkaiNewFaceCutterUtil::Input::createSegmentsAndEventsForPolygon(
    state,
    &iv,
    (hkaiNewFaceCutterUtil::Difference)1,
    &uniqueMapping);
  v22 = (2 * v33 + 127) & 0xFFFFFF80;
  v23 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v24 = (v22 + 15) & 0xFFFFFFF0;
  if ( v22 > v23->m_slabSize || (char *)p + v24 != v23->m_cur || v23->m_firstNonLifoEnd == p )
    hkLifoAllocator::slowBlockFree(v23, (char *)p, v24);
  else
    v23->m_cur = p;
  if ( uniqueMapping.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      uniqueMapping.m_data,
      2 * (uniqueMapping.m_capacityAndFlags & 0x3FFFFFFF));
  v25 = (4 * v30 + 127) & 0xFFFFFF80;
  v26 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v27 = (v25 + 15) & 0xFFFFFFF0;
  if ( v25 > v26->m_slabSize || (char *)v29 + v27 != v26->m_cur || v26->m_firstNonLifoEnd == v29 )
    hkLifoAllocator::slowBlockFree(v26, (char *)v29, v27);
  else
    v26->m_cur = v29;
  if ( iv.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      iv.m_data,
      4 * iv.m_capacityAndFlags);
}

// File Line: 672
// RVA: 0x12F5730
void __fastcall hkaiNewFaceCutterUtil::createNonFacePolygon(
        hkaiNewFaceCutterUtil::State *state,
        hkArrayBase<hkVector4f> *vertices,
        hkaiNewFaceCutterUtil::Difference inwardDifference)
{
  __int64 m_size; // r15
  int v4; // esi
  int v6; // edi
  hkLifoAllocator *Value; // rax
  hkaiNewFaceCutterUtil::Vec2 *m_cur; // r14
  int v9; // edx
  char *v10; // rcx
  __int64 v11; // rax
  int m_capacityAndFlags; // edi
  char *v13; // rbx
  __int64 v14; // r12
  __m128 v15; // xmm7
  __int64 v16; // rcx
  __int64 v17; // r15
  __m128 v18; // xmm10
  __m128 v19; // xmm10
  __m128 v20; // xmm1
  __m128 v21; // xmm9
  __m128 m_quad; // xmm1
  __m128 v23; // xmm3
  __m128 v24; // xmm2
  __m128 v25; // xmm6
  __m128 v26; // xmm0
  __m128 v27; // xmm1
  __m128 v28; // xmm4
  __m128 v29; // xmm3
  __m128 v30; // xmm3
  __m128 v31; // xmm0
  __m128 v32; // xmm1
  __m128 v33; // xmm0
  __m128 v34; // xmm2
  __m128 v35; // xmm3
  __m128 v36; // xmm2
  __m128 v37; // xmm1
  __m128 v38; // xmm1
  __m128 v39; // xmm4
  __m128 v40; // xmm4
  __m128i v41; // xmm0
  __m128i v42; // xmm3
  __m128i v43; // xmm1
  __m128i v44; // xmm3
  int v45; // edi
  int v46; // ebx
  int v47; // edi
  int v48; // r9d
  hkaiNewFaceCutterUtil::Vec2 v49; // eax
  int v50; // ebx
  int v51; // edi
  hkLifoAllocator *v52; // rax
  __int16 *v53; // rdx
  int v54; // ecx
  char *v55; // rdi
  __int64 v56; // rax
  int v57; // r9d
  __int16 *v58; // rdi
  __int64 v59; // rcx
  int v60; // eax
  char *v61; // rbx
  signed int v62; // edi
  hkLifoAllocator *v63; // rax
  int v64; // r8d
  signed int v65; // edi
  hkLifoAllocator *v66; // rax
  int v67; // r8d
  hkArrayBase<hkaiNewFaceCutterUtil::Vec2> iv; // [rsp+28h] [rbp-69h] BYREF
  void *v69; // [rsp+38h] [rbp-59h]
  int v70; // [rsp+40h] [rbp-51h]
  hkArrayBase<short> array; // [rsp+48h] [rbp-49h] BYREF
  void *p; // [rsp+58h] [rbp-39h]
  int v73; // [rsp+60h] [rbp-31h]
  hkArrayBase<hkVector4f> *verticesa; // [rsp+100h] [rbp+6Fh] BYREF
  hkArrayBase<hkVector4f> *inwardDifferencea; // [rsp+108h] [rbp+77h]
  unsigned int m_data; // [rsp+110h] [rbp+7Fh]

  m_data = inwardDifference.m_data;
  inwardDifferencea = vertices;
  m_size = vertices->m_size;
  v4 = 0;
  iv.m_data = 0i64;
  v6 = 5 * (m_size + 1);
  iv.m_size = 0;
  iv.m_capacityAndFlags = 0x80000000;
  v70 = v6;
  if ( v6 )
  {
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (hkaiNewFaceCutterUtil::Vec2 *)Value->m_cur;
    v9 = (20 * (m_size + 1) + 127) & 0xFFFFFF80;
    v10 = (char *)m_cur + v9;
    if ( v9 > Value->m_slabSize || v10 > Value->m_end )
    {
      v11 = hkLifoAllocator::allocateFromNewSlab(Value, v9);
      v4 = iv.m_size;
      vertices = verticesa;
      m_cur = (hkaiNewFaceCutterUtil::Vec2 *)v11;
    }
    else
    {
      vertices = verticesa;
      Value->m_cur = v10;
      v4 = iv.m_size;
    }
  }
  else
  {
    m_cur = 0i64;
  }
  m_capacityAndFlags = v6 | 0x80000000;
  v13 = (char *)m_cur;
  iv.m_data = m_cur;
  v14 = m_size;
  iv.m_capacityAndFlags = m_capacityAndFlags;
  v69 = m_cur;
  if ( (int)m_size > 0 )
  {
    v15 = *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31;
    v16 = 16i64 * ((int)m_size - 1);
    v17 = 0i64;
    v18 = 0i64;
    v18.m128_f32[0] = (float)0x3FFF;
    v19 = _mm_shuffle_ps(v18, v18, 0);
    do
    {
      v20 = *(__m128 *)((char *)&vertices->m_data->m_quad + v16);
      v21 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v20, v20, 0), state->m_externalToInternal.m_col0.m_quad),
                  state->m_externalToInternal.m_col3.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v20, v20, 85), state->m_externalToInternal.m_col1.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v20, v20, 170), state->m_externalToInternal.m_col2.m_quad));
      m_quad = vertices->m_data[v17].m_quad;
      v23 = _mm_shuffle_ps(v21, v21, 0);
      v24 = _mm_shuffle_ps(v21, v21, 85);
      v25 = _mm_sub_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 0), state->m_externalToInternal.m_col0.m_quad),
                    state->m_externalToInternal.m_col3.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 85), state->m_externalToInternal.m_col1.m_quad)),
                _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 170), state->m_externalToInternal.m_col2.m_quad)),
              v21);
      v26 = _mm_shuffle_ps(v25, v25, 0);
      v27 = _mm_shuffle_ps(v25, v25, 85);
      v28 = _mm_movelh_ps(
              _mm_unpacklo_ps(_mm_sub_ps((__m128)0i64, v26), v26),
              _mm_unpacklo_ps(_mm_sub_ps((__m128)0i64, v27), v27));
      v29 = _mm_movelh_ps(_mm_unpacklo_ps(v23, _mm_sub_ps(v19, v23)), _mm_unpacklo_ps(v24, _mm_sub_ps(v19, v24)));
      if ( !_mm_movemask_ps(_mm_and_ps(_mm_cmplt_ps(v29, (__m128)0i64), _mm_cmpeq_ps((__m128)0i64, v28))) )
      {
        v30 = _mm_div_ps(v29, v28);
        v31 = _mm_cmplt_ps(v28, (__m128)0i64);
        v32 = _mm_or_ps(_mm_and_ps(v30, v31), _mm_andnot_ps(v31, aabbOut.m_quad));
        v33 = _mm_cmplt_ps((__m128)0i64, v28);
        v34 = _mm_max_ps(_mm_shuffle_ps(v32, v32, 78), v32);
        v35 = _mm_or_ps(_mm_and_ps(v30, v33), _mm_andnot_ps(v33, query.m_quad));
        v36 = _mm_max_ps(v34, _mm_shuffle_ps(v34, v34, 177));
        v37 = _mm_min_ps(_mm_shuffle_ps(v35, v35, 78), v35);
        v38 = _mm_min_ps(v37, _mm_shuffle_ps(v37, v37, 177));
        if ( v36.m128_f32[0] < v38.m128_f32[0] )
        {
          v39 = _mm_shuffle_ps(_mm_add_ps(_mm_mul_ps(v25, v36), v21), _mm_add_ps(_mm_mul_ps(v25, v38), v21), 68);
          v40 = _mm_add_ps(_mm_shuffle_ps(v39, v39, 228), (__m128)xmmword_141A711B0);
          v41 = (__m128i)_mm_cmple_ps(v15, v40);
          v42 = _mm_or_si128(
                  _mm_add_epi32(
                    _mm_cvttps_epi32(_mm_max_ps(_mm_sub_ps(v40, _mm_and_ps((__m128)v41, v15)), (__m128)0i64)),
                    _mm_slli_epi32(v41, 0x1Fu)),
                  (__m128i)_mm_cmple_ps(_mm_add_ps(v15, v15), v40));
          v43 = _mm_cmpgt_epi32(_mm_load_si128((const __m128i *)&_xmm), v42);
          v44 = _mm_or_si128(_mm_and_si128(v42, v43), _mm_andnot_si128(v43, (__m128i)_xmm));
          v45 = (_mm_cvtsi128_si32(v44) << 16) | _mm_cvtsi128_si32(_mm_shuffle_epi32(v44, 85));
          v46 = _mm_cvtsi128_si32(_mm_shuffle_epi32(v44, 255)) | (_mm_cvtsi128_si32(_mm_shuffle_epi32(v44, 170)) << 16);
          if ( v45 != v46 )
          {
            if ( !v4
              || (hkaiNewFaceCutterUtil::Input::addBoundaryPoints(m_cur[v4 - 1], (hkaiNewFaceCutterUtil::Vec2)v45, &iv),
                  v4 = iv.m_size,
                  m_cur = iv.m_data,
                  !iv.m_size)
              || iv.m_data[iv.m_size - 1].m_xy != v45 )
            {
              m_cur[v4].m_xy = v45;
              m_cur = iv.m_data;
              v4 = ++iv.m_size;
            }
            vertices = verticesa;
            m_cur[v4].m_xy = v46;
            m_cur = iv.m_data;
            v15 = *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31;
            v4 = ++iv.m_size;
          }
        }
      }
      v16 = v17 * 16;
      ++v17;
      --v14;
    }
    while ( v14 );
    v13 = (char *)v69;
    m_capacityAndFlags = iv.m_capacityAndFlags;
  }
  if ( v4 >= 2 )
  {
    v49.m_xy = m_cur[v4 - 1].m_xy;
    if ( m_cur->m_xy == v49.m_xy )
      iv.m_size = v4 - 1;
    else
      hkaiNewFaceCutterUtil::Input::addBoundaryPoints(v49, (hkaiNewFaceCutterUtil::Vec2)m_cur->m_xy, &iv);
    hkaiNewFaceCutterUtil::Input::ensureSimple(&iv);
  }
  else
  {
    if ( !hkaiNewFaceCutterUtil::Input::domainOriginInConvexPolygon(state, vertices) )
      goto LABEL_53;
    v47 = m_capacityAndFlags & 0x3FFFFFFF;
    if ( v47 < 4 )
    {
      v48 = 4;
      if ( 2 * v47 > 4 )
        v48 = 2 * v47;
      hkArrayUtil::_reserve(
        (hkResult *)&verticesa,
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&iv.m_data,
        v48,
        4);
      m_cur = iv.m_data;
    }
    iv.m_size = 4;
    m_cur->m_xy = 0;
    iv.m_data[1].m_xy = 1073676288;
    iv.m_data[2].m_xy = 1073692671;
    iv.m_data[3].m_xy = 0x3FFF;
  }
  v50 = iv.m_size;
  array.m_data = 0i64;
  v51 = 0;
  array.m_size = 0;
  array.m_capacityAndFlags = 0x80000000;
  v73 = iv.m_size;
  if ( iv.m_size )
  {
    v52 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v53 = (__int16 *)v52->m_cur;
    v54 = (2 * v50 + 127) & 0xFFFFFF80;
    v55 = (char *)v53 + v54;
    if ( v54 > v52->m_slabSize || v55 > v52->m_end )
    {
      v56 = hkLifoAllocator::allocateFromNewSlab(v52, v54);
      v51 = array.m_size;
      v53 = (__int16 *)v56;
    }
    else
    {
      v52->m_cur = v55;
      v51 = array.m_size;
    }
  }
  else
  {
    v53 = 0i64;
  }
  array.m_data = v53;
  p = v53;
  array.m_capacityAndFlags = v50 | 0x80000000;
  if ( (v50 & 0x3FFFFFFF) < v50 )
  {
    v57 = v50;
    if ( v50 < 2 * (v50 & 0x3FFFFFFF) )
      v57 = 2 * (v50 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(
      (hkResult *)&verticesa,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&array.m_data,
      v57,
      2);
    v51 = array.m_size;
    v53 = array.m_data;
  }
  LODWORD(v59) = v50 - v51;
  v58 = &v53[v51];
  v59 = (int)v59;
  if ( (int)v59 > 0 )
  {
    while ( v59 )
    {
      *v58++ = -1;
      --v59;
    }
  }
  array.m_size = v50;
  hkaiNewFaceCutterUtil::Input::createSegmentsAndEventsForPolygon(
    state,
    &iv,
    (hkaiNewFaceCutterUtil::Difference)inwardDifferencea,
    &array);
  v60 = array.m_size;
  v61 = (char *)p;
  if ( p == array.m_data )
    v60 = 0;
  array.m_size = v60;
  v62 = (2 * v73 + 127) & 0xFFFFFF80;
  v63 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v64 = (v62 + 15) & 0xFFFFFFF0;
  if ( v62 > v63->m_slabSize || &v61[v64] != v63->m_cur || v63->m_firstNonLifoEnd == v61 )
    hkLifoAllocator::slowBlockFree(v63, v61, v64);
  else
    v63->m_cur = v61;
  array.m_size = 0;
  if ( array.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      array.m_data,
      2 * (array.m_capacityAndFlags & 0x3FFFFFFF));
  v13 = (char *)v69;
  v4 = iv.m_size;
  m_cur = iv.m_data;
  array.m_data = 0i64;
  array.m_capacityAndFlags = 0x80000000;
LABEL_53:
  if ( v13 == (char *)m_cur )
    v4 = 0;
  v65 = (4 * v70 + 127) & 0xFFFFFF80;
  iv.m_size = v4;
  v66 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v67 = (v65 + 15) & 0xFFFFFFF0;
  if ( v65 > v66->m_slabSize || &v13[v67] != v66->m_cur || v66->m_firstNonLifoEnd == v13 )
    hkLifoAllocator::slowBlockFree(v66, v13, v67);
  else
    v66->m_cur = v13;
  iv.m_size = 0;
  if ( iv.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      iv.m_data,
      4 * iv.m_capacityAndFlags);
}

