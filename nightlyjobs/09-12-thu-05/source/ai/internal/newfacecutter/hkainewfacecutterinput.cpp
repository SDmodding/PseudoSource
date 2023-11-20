// File Line: 31
// RVA: 0x12F6520
void __fastcall hkaiNewFaceCutterUtil::Input::calcExtents(hkVector4f *u, hkVector4f *v, hkArrayBase<hkVector4f> *points, hkVector4f *extentsOut)
{
  __m128 v4; // xmm5
  __m128 v5; // xmm2
  signed __int64 v6; // rcx
  __m128 v7; // xmm3
  __m128 v8; // xmm2
  __m128 v9; // xmm3
  __m128 v10; // xmm0
  __m128 v11; // xmm4
  __m128 v12; // xmm6
  __m128 v13; // xmm4
  __m128 v14; // xmm6
  __m128 v15; // xmm5
  __m128 v16; // xmm3
  hkVector4f *v17; // rax
  signed __int64 v18; // rcx
  __m128 v19; // xmm1

  v4 = u->m_quad;
  v5 = u->m_quad;
  v6 = points->m_size;
  v7 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
  v8 = _mm_xor_ps(v5, v7);
  v9 = _mm_xor_ps(v7, v->m_quad);
  v10 = _mm_shuffle_ps(v->m_quad, v9, 68);
  v11 = _mm_shuffle_ps(v4, v8, 68);
  v12 = v11;
  v13 = _mm_shuffle_ps(v11, v10, 221);
  v14 = _mm_shuffle_ps(v12, v10, 136);
  v15 = _mm_shuffle_ps(_mm_shuffle_ps(v4, v8, 238), _mm_shuffle_ps(v->m_quad, v9, 238), 136);
  v16 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(points->m_data->m_quad, points->m_data->m_quad, 85), v13),
            _mm_mul_ps(_mm_shuffle_ps(points->m_data->m_quad, points->m_data->m_quad, 0), v14)),
          _mm_mul_ps(_mm_shuffle_ps(points->m_data->m_quad, points->m_data->m_quad, 170), v15));
  if ( v6 > 1 )
  {
    v17 = points->m_data + 1;
    v18 = v6 - 1;
    do
    {
      v19 = v17->m_quad;
      ++v17;
      v16 = _mm_min_ps(
              v16,
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v19, v19, 85), v13), _mm_mul_ps(_mm_shuffle_ps(v19, v19, 0), v14)),
                _mm_mul_ps(_mm_shuffle_ps(v19, v19, 170), v15)));
      --v18;
    }
    while ( v18 );
  }
  extentsOut->m_quad = _mm_mul_ps(v16, (__m128)xmmword_141A71320);
}

// File Line: 54
// RVA: 0x12F5F10
bool __fastcall hkaiNewFaceCutterUtil::Input::isSimplePolygon(hkArrayBase<hkaiNewFaceCutterUtil::Vec2> *iv)
{
  signed __int64 v1; // r9
  bool result; // al
  signed int v3; // er9
  unsigned int v4; // ecx
  hkaiNewFaceCutterUtil::Vec2 *v5; // rbx
  unsigned int v6; // eax
  hkaiNewFaceCutterUtil::Vec2 *v7; // rdx
  signed __int64 v8; // r8
  unsigned int v9; // eax
  signed __int64 v10; // r10
  signed __int64 v11; // rdi
  unsigned int v12; // edx
  int v13; // er8

  v1 = iv->m_size;
  if ( (signed int)v1 <= 2 )
    return 1;
  if ( (_DWORD)v1 == 3 )
  {
    v3 = iv->m_data[1].m_xy - iv->m_data->m_xy + 2 * ((LOWORD(iv->m_data[1].m_xy) - LOWORD(iv->m_data->m_xy)) & 0x8000);
    v4 = iv->m_data[2].m_xy - iv->m_data->m_xy;
    result = (signed __int16)(v4 + 2 * (v4 & 0x8000)) * (v3 >> 16)
           - (signed __int16)v3 * ((signed int)(v4 + 2 * (v4 & 0x8000)) >> 16) >= 0;
  }
  else
  {
    v5 = iv->m_data;
    v6 = iv->m_data->m_xy;
    if ( (signed int)v1 > 1 )
    {
      v7 = v5 + 1;
      v8 = v1 - 1;
      do
      {
        v9 = v7->m_xy + v6;
        ++v7;
        v6 = (v9 >> 1) & 0x3FFF3FFF;
        --v8;
      }
      while ( v8 );
    }
    v10 = 0i64;
    if ( (signed int)v1 <= 0 )
    {
LABEL_12:
      result = 1;
    }
    else
    {
      v11 = (signed int)v1 - 1;
      while ( 1 )
      {
        v12 = v5[v11].m_xy;
        v11 = v10;
        v13 = v5[v10].m_xy - v6 + 2 * ((LOWORD(v5[v10].m_xy) - (_WORD)v6) & 0x8000);
        if ( (signed __int16)v13 * ((signed int)(v12 - v6 + 2 * (((_WORD)v12 - (_WORD)v6) & 0x8000)) >> 16)
           - (signed __int16)(v12 - v6 + 2 * ((v12 - v6) & 0x8000)) * (v13 >> 16) < 0 )
          break;
        if ( ++v10 >= v1 )
          goto LABEL_12;
      }
      result = 0;
    }
  }
  return result;
}

// File Line: 100
// RVA: 0x12F7030
void __fastcall hkaiNewFaceCutterUtil::Input::rotateArray<hkaiNewFaceCutterUtil::Vec2>(hkaiNewFaceCutterUtil::Vec2 *data, int n, int offset)
{
  __int64 v3; // rsi
  __int64 v4; // rdi
  hkaiNewFaceCutterUtil::Vec2 *v5; // r12
  hkLifoAllocator *v6; // rax
  char *v7; // rbx
  int v8; // er14
  char *v9; // rcx
  int v10; // edi
  hkLifoAllocator *v11; // rax
  int v12; // er8

  if ( offset )
  {
    v3 = offset;
    v4 = n;
    v5 = data;
    if ( offset != n )
    {
      v6 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v7 = (char *)v6->m_cur;
      v8 = (4 * v4 + 127) & 0xFFFFFF80;
      v9 = &v7[v8];
      if ( v8 > v6->m_slabSize || v9 > v6->m_end )
        v7 = (char *)hkLifoAllocator::allocateFromNewSlab(v6, v8);
      else
        v6->m_cur = v9;
      if ( (signed int)v4 > 0 )
        memmove(v7, v5, 4 * v4);
      if ( (signed int)v3 > 0 )
        memmove(v5, &v7[4 * (v4 - v3)], 4 * v3);
      v10 = v4 - v3;
      if ( v10 > 0 )
        memmove(&v5[v3], v7, 4i64 * v10);
      v11 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v12 = (v8 + 15) & 0xFFFFFFF0;
      if ( v8 > v11->m_slabSize || &v7[v12] != v11->m_cur || v11->m_firstNonLifoEnd == v7 )
        hkLifoAllocator::slowBlockFree(v11, v7, v12);
      else
        v11->m_cur = v7;
    }
  }
}

// File Line: 114
// RVA: 0x12F6050
void __fastcall hkaiNewFaceCutterUtil::Input::makeConvexHull(hkArrayBase<hkaiNewFaceCutterUtil::Vec2> *vertices)
{
  signed __int64 v1; // rdi
  int v2; // er12
  signed __int64 v3; // r14
  hkArrayBase<hkaiNewFaceCutterUtil::Vec2> *v4; // r13
  signed int v5; // er11
  signed int v6; // er9
  signed __int64 v7; // r8
  signed __int64 v8; // rdx
  signed __int64 v9; // rcx
  unsigned int v10; // eax
  hkaiNewFaceCutterUtil::Vec2 *v11; // rdx
  signed __int64 v12; // rdx
  signed __int64 v13; // rcx
  unsigned int v14; // er9
  hkaiNewFaceCutterUtil::Vec2 *v15; // rax
  __int64 v16; // rdx
  unsigned int v17; // ecx
  signed __int64 v18; // rdi
  int v19; // er14
  int v20; // eax
  int v21; // er9
  __int64 v22; // r11
  int v23; // er8
  int v24; // esi
  int v25; // er10
  int v26; // er8
  int v27; // ebp
  int v28; // edx
  int v29; // ebx
  int v30; // er8
  bool v31; // sf
  unsigned __int8 v32; // of
  signed int v33; // ebx
  signed __int64 v34; // rsi
  signed __int64 i; // rcx
  unsigned int v36; // edx
  signed __int64 v37; // r11
  int v38; // er8
  hkArrayBase<hkaiNewFaceCutterUtil::Vec2> *v39; // [rsp+70h] [rbp+8h]
  signed __int64 v40; // [rsp+80h] [rbp+18h]
  __int64 v41; // [rsp+88h] [rbp+20h]

  v39 = vertices;
  v1 = vertices->m_size;
  v2 = 0;
  v3 = 1i64;
  v4 = vertices;
  v5 = 0;
  v40 = 1i64;
  v6 = 1;
  v7 = 1i64;
  if ( v1 > 1 )
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
    while ( v7 < v1 );
  }
  hkaiNewFaceCutterUtil::Input::rotateArray<hkaiNewFaceCutterUtil::Vec2>(vertices->m_data, v1, v1 - v5);
  v9 = 1i64;
  v10 = v4->m_data->m_xy;
  if ( v1 > 1 )
  {
    v11 = v4->m_data + 1;
    do
    {
      if ( v11->m_xy == v10 )
        break;
      ++v9;
      v3 = (unsigned int)(v3 + 1);
      ++v11;
    }
    while ( v9 < v1 );
    v40 = v3;
  }
  v12 = (signed int)v3 + 1;
  if ( v12 < v1 )
  {
    v13 = (signed int)v3;
    do
    {
      v14 = v4->m_data[v12].m_xy;
      if ( v14 != v10 )
      {
        v4->m_data[v13].m_xy = v14;
        v3 = (unsigned int)(v3 + 1);
        ++v13;
      }
      ++v12;
    }
    while ( v12 < v1 );
    v40 = v3;
  }
  v15 = v4->m_data;
  v4->m_size = v3;
  v16 = 0i64;
  v17 = v15->m_xy;
  v18 = (signed __int64)&v15[1];
  v41 = 0i64;
  if ( (signed int)v3 - 1 > 0 )
  {
    v19 = v3 - 1;
    do
    {
      v20 = *(_DWORD *)(v18 + 4 * v16);
      v21 = v2;
      v22 = v16;
      if ( v2 > 0 )
      {
        do
        {
          v23 = v20 - v17 + 2 * (((_WORD)v20 - (_WORD)v17) & 0x8000);
          v24 = (signed __int16)v23;
          v25 = v23 >> 16;
          v26 = *(_DWORD *)(v18 + 4 * v22 - 4) - v17 + 2 * ((*(_WORD *)(v18 + 4 * v22 - 4) - (_WORD)v17) & 0x8000);
          v27 = (signed __int16)v26;
          v28 = v26 >> 16;
          v29 = v25 * (signed __int16)v26;
          v30 = v24 * (v26 >> 16);
          v32 = __OFSUB__(v30, v29);
          v31 = v30 - v29 < 0;
          if ( v30 == v29 )
          {
            v32 = __OFSUB__(v25, v28);
            v31 = v25 - v28 < 0;
            if ( v25 == v28 )
            {
              v32 = __OFSUB__(v24, v27);
              v31 = v24 - v27 < 0;
            }
          }
          if ( !(v31 ^ v32) )
            break;
          --v21;
          *(_DWORD *)(v18 + 4 * v22) = *(_DWORD *)(v18 + 4 * v22 - 4);
          --v22;
        }
        while ( v21 > 0 );
        v16 = v41;
      }
      ++v16;
      ++v2;
      *(_DWORD *)(v18 + 4 * v22) = v20;
      v41 = v16;
    }
    while ( v2 < v19 );
    LODWORD(v3) = v40;
    v4 = v39;
  }
  v33 = 2;
  v34 = 2i64;
  for ( i = 2i64; v34 < (signed int)v3; ++v34 )
  {
    v36 = v4->m_data[v34].m_xy;
    if ( v36 != v4->m_data[i - 1].m_xy )
    {
      v4->m_data[i++].m_xy = v36;
      ++v33;
      if ( i > 3 )
      {
        v37 = 4 * i - 8;
        do
        {
          v38 = *(unsigned int *)((char *)&v4->m_data[1].m_xy + v37)
              - *(unsigned int *)((char *)&v4->m_data[-1].m_xy + v37)
              + 2
              * ((*(_WORD *)((char *)&v4->m_data[1].m_xy + v37) - *(_WORD *)((char *)&v4->m_data[-1].m_xy + v37)) & 0x8000);
          if ( (signed __int16)v38
             * ((signed int)(*(unsigned int *)((char *)&v4->m_data->m_xy + v37)
                           - *(unsigned int *)((char *)&v4->m_data[-1].m_xy + v37)
                           + 2
                           * ((*(_WORD *)((char *)&v4->m_data->m_xy + v37)
                             - *(_WORD *)((char *)&v4->m_data[-1].m_xy + v37)) & 0x8000)) >> 16)
             - (signed __int16)(*(_WORD *)((char *)&v4->m_data->m_xy + v37)
                              - *(_WORD *)((char *)&v4->m_data[-1].m_xy + v37)
                              + 2
                              * ((*(_WORD *)((char *)&v4->m_data->m_xy + v37)
                                - *(_WORD *)((char *)&v4->m_data[-1].m_xy + v37)) & 0x8000))
             * (v38 >> 16) >= 0 )
            break;
          --i;
          *(unsigned int *)((char *)&v4->m_data->m_xy + v37) = *(unsigned int *)((char *)&v4->m_data[1].m_xy + v37);
          --v33;
          v37 -= 4i64;
        }
        while ( i > 3 );
      }
    }
  }
  v4->m_size = v33;
}

// File Line: 188
// RVA: 0x12F6600
void __fastcall hkaiNewFaceCutterUtil::Input::ensureSimple(hkArrayBase<hkaiNewFaceCutterUtil::Vec2> *vertices)
{
  hkArrayBase<hkaiNewFaceCutterUtil::Vec2> *v1; // rbx

  v1 = vertices;
  if ( !hkaiNewFaceCutterUtil::Input::isSimplePolygon(vertices) )
    hkaiNewFaceCutterUtil::Input::makeConvexHull(v1);
}

// File Line: 207
// RVA: 0x12F6630
__int64 __fastcall hkaiNewFaceCutterUtil::Input::getSideMask_reference(hkaiNewFaceCutterUtil::Vec2 v)
{
  return (HIWORD(v.m_xy) == 0) | 2 * (LOWORD(v.m_xy) == 0) | 4 * (HIWORD(v.m_xy) == 0x3FFF) | 8
                                                                                            * (unsigned int)(LOWORD(v.m_xy) == 0x3FFF);
}

// File Line: 216
// RVA: 0x12F6680
__int64 __fastcall hkaiNewFaceCutterUtil::Input::getSideMask(hkaiNewFaceCutterUtil::Vec2 v)
{
  return ((v.m_xy + 65537) & 0x4000 | ((~((v.m_xy | 0x40004000) - 65537) & 0x4000 | (((~((v.m_xy | 0x40004000) - 65537) >> 2) & 0x10000000 | (v.m_xy + 65537) & 0x40000000) >> 15)) >> 2)) >> 11;
}

// File Line: 239
// RVA: 0x12F5DC0
void __fastcall hkaiNewFaceCutterUtil::Input::addBoundaryPoints(hkaiNewFaceCutterUtil::Vec2 a, hkaiNewFaceCutterUtil::Vec2 b, hkArrayBase<hkaiNewFaceCutterUtil::Vec2> *iv)
{
  hkArrayBase<hkaiNewFaceCutterUtil::Vec2> *v3; // rsi
  unsigned int v4; // ebx
  unsigned int v5; // edi
  unsigned int v6; // eax
  unsigned int v7; // ebx
  signed int v8; // eax
  hkErrStream v9; // [rsp+20h] [rbp-228h]
  char buf; // [rsp+40h] [rbp-208h]

  v3 = iv;
  v4 = b.m_xy;
  v5 = hkaiNewFaceCutterUtil::Input::getSideMask(a);
  v6 = hkaiNewFaceCutterUtil::Input::getSideMask((hkaiNewFaceCutterUtil::Vec2)v4);
  v7 = v6;
  if ( v5 && v6 && !(v6 & v5) )
  {
    do
    {
      switch ( v5 )
      {
        case 1u:
        case 9u:
          v5 = 3;
          goto LABEL_12;
        case 2u:
        case 3u:
          v8 = 1073676288;
          v5 = 6;
          break;
        case 4u:
        case 6u:
          v8 = 1073692671;
          v5 = 12;
          break;
        case 8u:
        case 0xCu:
          v8 = 0x3FFF;
          v5 = 9;
          break;
        default:
          hkErrStream::hkErrStream(&v9, &buf, 512);
          hkOstream::operator<<((hkOstream *)&v9.vfptr, "unexpected side mask");
          if ( (unsigned int)hkError::messageError(-38326284, &buf, "NewFaceCutter\\hkaiNewFaceCutterInput.cpp", 287) )
            __debugbreak();
          hkOstream::~hkOstream((hkOstream *)&v9.vfptr);
LABEL_12:
          v8 = 0;
          break;
      }
      v3->m_data[v3->m_size++].m_xy = v8;
    }
    while ( !(v7 & v5) );
  }
}

// File Line: 299
// RVA: 0x12F6320
char __fastcall hkaiNewFaceCutterUtil::Input::isConvexHull(hkArrayBase<hkaiNewFaceCutterUtil::Vec2> *vertices)
{
  int v1; // er9
  char v2; // si
  __int64 v3; // r8
  __int64 v4; // rbp
  hkaiNewFaceCutterUtil::Vec2 *v5; // r15
  signed __int64 v6; // rdi
  signed __int64 v7; // rax
  unsigned int v8; // ecx
  unsigned int v9; // eax
  signed __int64 v10; // r14
  int v11; // er11

  v1 = vertices->m_size;
  v2 = 0;
  v3 = 0i64;
  v4 = vertices->m_size;
  if ( v1 <= 0 )
    return 1;
  v5 = vertices->m_data;
  v6 = 4i64 * (v1 - 1);
  v7 = 4i64 * (v1 - 2);
  while ( 1 )
  {
    v8 = *(unsigned int *)((char *)&v5->m_xy + v7);
    v9 = *(unsigned int *)((char *)&v5->m_xy + v6);
    v10 = 4 * v3;
    v11 = v5[v3].m_xy - v8 + 2 * ((LOWORD(v5[v3].m_xy) - (_WORD)v8) & 0x8000);
    if ( (signed __int16)v11
       * ((signed int)(*(unsigned int *)((char *)&v5->m_xy + v6)
                     - v8
                     + 2 * ((*(_WORD *)((char *)&v5->m_xy + v6) - (_WORD)v8) & 0x8000)) >> 16)
       - (signed __int16)(*(_WORD *)((char *)&v5->m_xy + v6)
                        - v8
                        + 2 * ((*(_WORD *)((char *)&v5->m_xy + v6) - v8) & 0x8000))
       * (v11 >> 16) < 0
      || v8 == v9 )
    {
      break;
    }
    if ( v9 < v8 && v9 < v5[v3].m_xy )
    {
      if ( v2 )
        return 0;
      v2 = 1;
    }
    ++v3;
    v7 = v6;
    v6 = v10;
    if ( v3 >= v4 )
      return 1;
  }
  return 0;
}

// File Line: 334
// RVA: 0x12F6420
void __fastcall hkaiNewFaceCutterUtil::Input::findMaximalCaliper(hkArrayBase<hkaiNewFaceCutterUtil::Vec2> *iv, int *iOut, int *jOut)
{
  int v3; // eax
  int v4; // esi
  int *v5; // r9
  int v6; // edx
  int v7; // ebp
  int v8; // edi
  int v9; // ebx
  signed __int64 v10; // r13
  hkaiNewFaceCutterUtil::Vec2 *v11; // r15
  signed __int64 v12; // r14
  unsigned int v13; // eax
  int v14; // er12
  int v15; // er9
  hkaiNewFaceCutterUtil::Vec2 *v16; // r10
  signed __int64 v17; // r11
  int v18; // edx
  int v19; // er8
  int v20; // [rsp+40h] [rbp+8h]
  int *v21; // [rsp+48h] [rbp+10h]
  int *v22; // [rsp+50h] [rbp+18h]

  v22 = jOut;
  v21 = iOut;
  v3 = iv->m_size;
  v4 = 0;
  v5 = iOut;
  v6 = v3 - 1;
  v7 = 0;
  v8 = 0;
  v9 = 0;
  v10 = iv->m_size;
  v20 = v3 - 1;
  if ( v3 - 1 <= 0 )
  {
    *v5 = 0;
    *jOut = 0;
  }
  else
  {
    v11 = iv->m_data;
    v12 = 1i64;
    do
    {
      v13 = v11->m_xy;
      v14 = v9 + 1;
      v15 = v9 + 1;
      if ( v12 < v10 )
      {
        v16 = v11 + 1;
        v17 = v10 - v12;
        do
        {
          v18 = v16->m_xy - v13 + 2 * ((LOWORD(v16->m_xy) - (_WORD)v13) & 0x8000);
          v19 = (signed __int16)(LOWORD(v16->m_xy) - v13 + 2 * ((LOWORD(v16->m_xy) - v13) & 0x8000));
          if ( v19 * v19 + (v18 >> 16) * (v18 >> 16) > v8 )
          {
            v4 = v9;
            v7 = v15;
            v8 = v19 * v19 + (v18 >> 16) * (v18 >> 16);
          }
          ++v15;
          ++v16;
          --v17;
        }
        while ( v17 );
        v6 = v20;
      }
      ++v11;
      ++v12;
      ++v9;
    }
    while ( v14 < v6 );
    *v21 = v4;
    *v22 = v7;
  }
}

// File Line: 361
// RVA: 0x12F66D0
void __fastcall hkaiNewFaceCutterUtil::Input::makeUniqueWithMapping(hkArrayBase<hkaiNewFaceCutterUtil::Vec2> *vertices, hkArrayBase<short> *uniqueMapping)
{
  int v2; // esi
  int v3; // er9
  unsigned int v4; // er8
  hkArrayBase<short> *v5; // r10
  signed int v6; // edx
  signed __int64 v7; // rbx
  signed __int64 v8; // rdi
  unsigned int v9; // eax

  v2 = vertices->m_size;
  v3 = 1;
  uniqueMapping->m_data[uniqueMapping->m_size++] = 0;
  v4 = vertices->m_data->m_xy;
  v5 = uniqueMapping;
  v6 = 1;
  if ( v2 > 1 )
  {
    v7 = 1i64;
    v8 = 1i64;
    do
    {
      v9 = vertices->m_data[v8].m_xy;
      if ( v9 != v4 )
      {
        ++v5->m_size;
        ++v3;
        vertices->m_data[v7].m_xy = v9;
        ++v7;
        v4 = v9;
      }
      ++v8;
      v5->m_data[v5->m_size - 1] = v6++;
    }
    while ( v6 < v2 );
    if ( v3 >= 2 && vertices->m_data->m_xy == vertices->m_data[v3 - 1].m_xy )
    {
      --v5->m_size;
      --v3;
    }
  }
  vertices->m_size = v3;
}

// File Line: 390
// RVA: 0x12F6780
void __fastcall hkaiNewFaceCutterUtil::Input::makeFacePolygonSimple(hkArrayBase<hkaiNewFaceCutterUtil::Vec2> *iv)
{
  int v1; // ebx
  hkArrayBase<hkaiNewFaceCutterUtil::Vec2> *v2; // rbp
  __int64 v3; // rsi
  unsigned int v4; // er8
  __int64 v5; // r15
  unsigned int v6; // er14
  int v7; // er11
  int v8; // edi
  int v9; // eax
  unsigned int v10; // er9
  int v11; // edx
  unsigned int v12; // ebx
  unsigned int v13; // er10
  int v14; // ecx
  int v15; // er12
  int v16; // ebx
  int v17; // er11
  int v18; // er14
  int v19; // er11
  int v20; // eax
  signed __int64 v21; // rdx
  __int128 v22; // tt
  signed __int64 v23; // rdx
  int v24; // er10
  int v25; // er11
  signed int v26; // eax
  signed int v27; // eax
  int v28; // ebx
  unsigned int v29; // er8
  unsigned int v30; // er9
  __int64 v31; // r13
  int v32; // er12
  int v33; // er8
  unsigned int v34; // ecx
  int v35; // ebp
  int v36; // edx
  unsigned int v37; // er10
  __int64 v38; // r14
  int v39; // edi
  int v40; // er10
  int v41; // ebx
  int v42; // er8
  int v43; // eax
  signed __int64 v44; // rdx
  __int128 v45; // tt
  __int64 v46; // rdx
  int v47; // ecx
  int v48; // er11
  signed int v49; // eax
  signed int v50; // eax
  int v51; // er8
  int v52; // edx
  int v53; // eax
  int v54; // [rsp+20h] [rbp-88h]
  int v55; // [rsp+20h] [rbp-88h]
  int v56; // [rsp+24h] [rbp-84h]
  int v57; // [rsp+28h] [rbp-80h]
  int iOut; // [rsp+2Ch] [rbp-7Ch]
  unsigned int v59; // [rsp+30h] [rbp-78h]
  int v60; // [rsp+34h] [rbp-74h]
  int v61; // [rsp+38h] [rbp-70h]
  unsigned int v62; // [rsp+3Ch] [rbp-6Ch]
  unsigned int v63; // [rsp+40h] [rbp-68h]
  hkaiNewFaceCutterUtil::Vec2 *v64; // [rsp+48h] [rbp-60h]
  hkArrayBase<hkaiNewFaceCutterUtil::Vec2> *v65; // [rsp+B0h] [rbp+8h]
  int jOut; // [rsp+B8h] [rbp+10h]
  int v67; // [rsp+C0h] [rbp+18h]
  unsigned int v68; // [rsp+C8h] [rbp+20h]

  v65 = iv;
  v1 = iv->m_size;
  v2 = iv;
  hkaiNewFaceCutterUtil::Input::findMaximalCaliper(iv, &iOut, &jOut);
  v3 = jOut;
  v4 = v2->m_data[iOut].m_xy;
  v5 = iOut;
  v62 = v2->m_data[jOut].m_xy;
  v6 = v62 >> 16;
  v7 = (unsigned __int16)v4;
  v8 = iOut;
  v68 = v62 >> 16;
  v67 = (unsigned __int16)v4;
  v56 = (signed int)(v62 - v4 + 2 * (((_WORD)v62 - (_WORD)v4) & 0x8000)) >> 16;
  v57 = (signed __int16)(v62 - v4 + 2 * ((v62 - v4) & 0x8000));
  v9 = v1 - 1;
  jOut = (unsigned __int16)v62;
  v10 = v4 >> 16;
  v11 = (unsigned __int16)v62 - (unsigned __int16)v4;
  v12 = (v62 >> 16) - (v4 >> 16);
  v60 = v9;
  v59 = v4 >> 16;
  v63 = (v62 >> 16) - (v4 >> 16);
  v54 = (unsigned __int16)v62 - (unsigned __int16)v4;
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
    v64 = &v2->m_data[v5];
    v61 = (unsigned __int16)v13;
    v14 = v12 * ((unsigned __int16)v13 - v7) - v11 * ((v13 >> 16) - v10);
    if ( v14 > 0 )
    {
      v16 = v10 - v6;
      v17 = v7 - jOut;
      v15 = v17;
      v18 = -v17;
      v19 = v16 * v16 + v17 * v17;
      v20 = v19;
      v21 = v14 * (signed __int64)v18;
      if ( v21 < 0 )
      {
        v21 = -v21;
        v20 = -v19;
      }
      v22 = v21 + ((signed __int64)(v20 ^ (unsigned __int64)((signed __int64)v20 >> 30)) >> 1);
      v23 = v14 * (signed __int64)v16;
      v24 = (unsigned __int128)(v22 / v20) + (v13 >> 16);
      if ( v23 < 0 )
      {
        v23 = -v23;
        v19 = -v19;
      }
      v25 = v61
          + (unsigned __int64)((v23 + ((signed __int64)(v19 ^ (unsigned __int64)((signed __int64)v19 >> 30)) >> 1)) / v19);
      if ( (signed int)(v16 * (v25 - jOut) - v15 * (v24 - v68)) < 0 )
      {
        if ( abs(v18) <= abs(v16) )
        {
          v27 = -1;
          if ( v16 > 0 )
            v27 = 1;
          v25 += v27;
        }
        else
        {
          v26 = -1;
          if ( v18 > 0 )
            v26 = 1;
          v24 += v26;
        }
      }
      v6 = v68;
      v12 = v63;
      v13 = v25 | (v24 << 16);
      v7 = v67;
    }
    v2 = v65;
    v11 = v54;
    if ( v57 * (signed __int16)(v13 - v4 + 2 * ((v13 - v4) & 0x8000))
       + v56 * ((signed int)(v13 - v4 + 2 * (((_WORD)v13 - (_WORD)v4) & 0x8000)) >> 16) < 0 )
      v13 = v4;
    v64->m_xy = v13;
    v9 = v60;
    v4 = v13;
  }
  while ( v8 != (_DWORD)v3 );
  v28 = jOut;
  v29 = v10;
  v30 = v62;
  v31 = v3;
  v32 = v7 - jOut;
  v33 = v29 - v6;
  v55 = v33;
  do
  {
    if ( (_DWORD)v3 == v60 )
    {
      LODWORD(v3) = 0;
      v31 = 0i64;
    }
    else
    {
      LODWORD(v3) = v3 + 1;
      ++v31;
    }
    v34 = v65->m_data[v31].m_xy;
    v35 = (unsigned __int16)v34;
    v36 = v33 * ((unsigned __int16)v34 - v28) - v32 * ((v34 >> 16) - v6);
    if ( v36 > 0 )
    {
      v37 = v6;
      v38 = v36;
      v39 = v28 - v67;
      v40 = v37 - v59;
      v41 = v67 - v28;
      v42 = v40 * v40 + v39 * v39;
      v43 = v40 * v40 + v39 * v39;
      v44 = v36 * (signed __int64)v41;
      if ( v44 < 0 )
      {
        v44 = -v44;
        v43 = -v43;
      }
      v45 = v44 + ((signed __int64)(v43 ^ (unsigned __int64)((signed __int64)v43 >> 30)) >> 1);
      v46 = v38 * v40;
      v47 = (v34 >> 16) + (unsigned __int128)(v45 / v43);
      if ( v46 < 0 )
      {
        v46 = -v46;
        v42 = -v42;
      }
      v48 = (unsigned __int64)((v46 + ((signed __int64)(v42 ^ (unsigned __int64)((signed __int64)v42 >> 30)) >> 1)) / v42)
          + v35;
      if ( (signed int)(v40 * (v48 - v67) - v39 * (v47 - v59)) < 0 )
      {
        if ( abs(v41) <= abs(v40) )
        {
          v50 = -1;
          if ( v40 > 0 )
            v50 = 1;
          v48 += v50;
        }
        else
        {
          v49 = -1;
          if ( v41 > 0 )
            v49 = 1;
          v47 += v49;
        }
      }
      v6 = v68;
      v28 = jOut;
      v34 = v48 | (v47 << 16);
    }
    v51 = v34 - v30 + 2 * (((_WORD)v34 - (_WORD)v30) & 0x8000);
    v52 = v51;
    v53 = (signed __int16)v51;
    v33 = v55;
    if ( v57 * v53 + v56 * (v52 >> 16) > 0 )
      v34 = v30;
    v30 = v34;
    v65->m_data[v31].m_xy = v34;
  }
  while ( (_DWORD)v3 != iOut );
}

// File Line: 460
// RVA: 0x12F6B90
void __fastcall hkaiNewFaceCutterUtil::Input::createSegmentsAndEventsForPolygon(hkaiNewFaceCutterUtil::State *state, hkArrayBase<hkaiNewFaceCutterUtil::Vec2> *vertices, hkaiNewFaceCutterUtil::Difference inwardDifference, hkArrayBase<short> *originalEdgeIndices)
{
  __int16 v4; // r11
  int v5; // eax
  unsigned int v6; // ebp
  unsigned int v7; // edi
  signed __int64 v8; // r8
  hkArrayBase<hkaiNewFaceCutterUtil::Vec2> *v9; // r15
  hkaiNewFaceCutterUtil::State *v10; // r10
  hkArray<hkaiNewFaceCutterUtil::Segment,hkContainerHeapAllocator> *v11; // r14
  unsigned int v12; // ebp
  unsigned int v13; // esi
  unsigned int v14; // ebx
  __int16 *v15; // rax
  bool v16; // r12
  __int16 v17; // r15
  signed __int64 v18; // rax
  __int16 v19; // di
  signed __int64 v20; // rcx
  signed __int64 v21; // r13
  bool v22; // si
  __int16 v23; // r12
  hkaiNewFaceCutterUtil::Vec2 *v24; // rax
  __int16 v25; // r15
  hkaiNewFaceCutterUtil::Vec2 v26; // edi
  int v27; // eax
  signed __int64 v28; // rax
  hkaiNewFaceCutterUtil::Segment *v29; // rax
  signed __int64 v30; // rcx
  bool v31; // [rsp+20h] [rbp-58h]
  bool v32; // [rsp+22h] [rbp-56h]
  __int16 v33; // [rsp+24h] [rbp-54h]
  __int16 v34; // [rsp+26h] [rbp-52h]
  signed __int64 v35; // [rsp+28h] [rbp-50h]
  hkaiNewFaceCutterUtil::State *statea; // [rsp+80h] [rbp+8h]
  hkArrayBase<hkaiNewFaceCutterUtil::Vec2> *v37; // [rsp+88h] [rbp+10h]
  unsigned int v38; // [rsp+90h] [rbp+18h]
  hkArrayBase<short> *v39; // [rsp+98h] [rbp+20h]

  v39 = originalEdgeIndices;
  v38 = inwardDifference.m_data;
  v37 = vertices;
  statea = state;
  v4 = state->m_segments.m_size;
  v5 = LOWORD(inwardDifference.m_data);
  v6 = inwardDifference.m_data;
  v7 = inwardDifference.m_data;
  v8 = vertices->m_size;
  v9 = vertices;
  v10 = state;
  v35 = v8;
  v11 = &state->m_segments;
  v12 = v5 | -(v6 & 0xFFFF0000);
  v33 = state->m_segments.m_size;
  v13 = vertices->m_data[v8 - 1].m_xy;
  v14 = vertices->m_data->m_xy;
  v15 = originalEdgeIndices->m_data;
  v16 = v13 < v14;
  v32 = v13 < v14;
  if ( v13 >= v14 )
  {
    v19 = v15[v8 - 1];
    if ( state->m_segments.m_size == (state->m_segments.m_capacityAndFlags & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v11, 28);
      v10 = statea;
      v4 = v33;
      originalEdgeIndices = v39;
      v8 = v35;
    }
    ++v11->m_size;
    v18 = (signed __int64)&v11->m_data[v4];
    *(_DWORD *)v18 = v14;
    *(_DWORD *)(v18 + 4) = v13;
    *(_DWORD *)(v18 + 8) = v12;
    *(_WORD *)(v18 + 12) = v19;
  }
  else
  {
    v17 = v15[v8 - 1];
    if ( state->m_segments.m_size == (state->m_segments.m_capacityAndFlags & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v11, 28);
      v10 = statea;
      v4 = v33;
      originalEdgeIndices = v39;
      v8 = v35;
    }
    ++v11->m_size;
    v18 = (signed __int64)&v11->m_data[v4];
    *(_WORD *)(v18 + 12) = v17;
    v9 = v37;
    *(_DWORD *)v18 = v13;
    *(_DWORD *)(v18 + 4) = v14;
    *(_DWORD *)(v18 + 8) = v7;
  }
  v20 = 0i64;
  v21 = 1i64;
  *(_WORD *)(v18 + 16) = -1;
  v22 = v13 < v14;
  v31 = v16;
  *(_WORD *)(v18 + 14) = 0;
  v23 = v4;
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
      v27 = v11->m_capacityAndFlags;
      if ( v26.m_xy >= v14 )
        break;
      if ( v11->m_size == (v27 & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v11, 28);
        v10 = statea;
        v8 = v35;
      }
      ++v11->m_size;
      v28 = (signed __int64)&v11->m_data[v25];
      *(_WORD *)(v28 + 12) = v34;
      *(hkaiNewFaceCutterUtil::Vec2 *)v28 = v26;
      *(_DWORD *)(v28 + 4) = v14;
      *(_DWORD *)(v28 + 8) = v38;
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
      v11->m_data[v23].m_followingSegment = v25;
LABEL_20:
      v22 = v26.m_xy < v14;
      v10 = statea;
      originalEdgeIndices = v39;
      v20 = v21++;
      v23 = v25;
      v9 = v37;
      v31 = v26.m_xy < v14;
      if ( v21 >= v8 )
      {
        v4 = v33;
        goto LABEL_22;
      }
    }
    if ( v11->m_size == (v27 & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v11, 28);
    ++v11->m_size;
    v29 = v11->m_data;
    v30 = v25;
    v29[v30].m_originalEdgeIndex = v34;
    v29[v30].m_a.m_xy = v14;
    v29[v30].m_b = v26;
    v29[v30].m_difference.m_data = v12;
    v29[v30].m_generation = 0;
    v29[v30].m_aboveRegion = -1;
    v29[v30].m_followingSegment = -1;
    if ( !v22 )
      v11->m_data[v30].m_followingSegment = v23;
    goto LABEL_19;
  }
LABEL_22:
  if ( v32 )
  {
    if ( v22 )
      v11->m_data[v23].m_followingSegment = v4;
    else
      hkaiNewFaceCutterUtil::enqueueStartSegmentsEventNoHeapify(statea, v4, v23, (hkaiNewFaceCutterUtil::Vec2)v14);
  }
  else if ( !v22 )
  {
    v11->m_data[v4].m_followingSegment = v23;
  }
}

// File Line: 557
// RVA: 0x12F6F10
char __fastcall hkaiNewFaceCutterUtil::Input::domainOriginInConvexPolygon(hkaiNewFaceCutterUtil::State *state, hkArrayBase<hkVector4f> *vertices)
{
  __int64 v2; // r8
  hkVector4f *v3; // r9
  hkVector4f v4; // xmm7
  __int64 v5; // rax
  hkVector4f v6; // xmm8
  __m128 v7; // xmm1
  hkVector4f v8; // xmm9
  hkVector4f v9; // xmm10
  __m128 v10; // xmm4
  __m128 v11; // xmm3

  v2 = vertices->m_size;
  v3 = vertices->m_data;
  v4.m_quad = (__m128)state->m_externalToInternal.m_col0;
  v5 = 0i64;
  v6.m_quad = (__m128)state->m_externalToInternal.m_col3;
  v7 = vertices->m_data[(signed int)v2 - 1].m_quad;
  v8.m_quad = (__m128)state->m_externalToInternal.m_col1;
  v9.m_quad = (__m128)state->m_externalToInternal.m_col2;
  v10 = _mm_sub_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v7, v7, 0), v4.m_quad), v6.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(vertices->m_data[(signed int)v2 - 1].m_quad, v7, 85), v8.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v7, v7, 170), v9.m_quad)),
          (__m128)_xmm);
  if ( (signed int)v2 <= 0 )
    return 1;
  while ( 1 )
  {
    v11 = _mm_sub_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v3->m_quad, v3->m_quad, 0), v4.m_quad), v6.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v3->m_quad, v3->m_quad, 85), v8.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v3->m_quad, v3->m_quad, 170), v9.m_quad)),
            (__m128)_xmm);
    if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 85)) * COERCE_FLOAT(_mm_shuffle_ps(v10, v10, 0)))
               - (float)(COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 0)) * COERCE_FLOAT(_mm_shuffle_ps(v10, v10, 85)))) < 0.0 )
      break;
    ++v5;
    ++v3;
    v10 = v11;
    if ( v5 >= v2 )
      return 1;
  }
  return 0;
}

// File Line: 593
// RVA: 0x12F51E0
void __fastcall hkaiNewFaceCutterUtil::setupDomain(hkaiNewFaceCutterUtil::State *state, hkVector4f *facePlaneIn, hkArrayBase<hkVector4f> *vertices)
{
  hkaiNewFaceCutterUtil::State *v3; // rbx
  hkVector4f v4; // xmm8
  __m128 v5; // xmm7
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
  __m128i *v20; // rdx
  __m128 v21; // xmm3
  __m128 v22; // xmm2
  __m128 v23; // xmm4
  __m128 v24; // xmm1
  __m128 v25; // xmm0
  __m128 v26; // xmm2
  __m128i v27; // xmm0
  __m128i v28; // xmm3
  __m128 v29; // xmm6
  hkVector4f v; // [rsp+20h] [rbp-68h]
  hkVector4f u; // [rsp+30h] [rbp-58h]
  hkVector4f extentsOut; // [rsp+40h] [rbp-48h]
  hkVector4f *result; // [rsp+98h] [rbp+10h]

  result = facePlaneIn;
  v3 = state;
  v4.m_quad = (__m128)state->m_up;
  if ( (_mm_movemask_ps(_mm_cmpeqps(state->m_up.m_quad, stru_141A71280.m_quad)) & 7) == 7 )
  {
    v5 = transform.m_quad;
    v6 = direction.m_quad;
  }
  else
  {
    v7 = _mm_shuffle_ps(v4.m_quad, _mm_unpackhi_ps(v4.m_quad, (__m128)0i64), 196);
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
    v15 = _mm_cmpltps(v11, v13);
    v16 = _mm_rsqrt_ps(v14);
    v17 = _mm_xor_ps(
            _mm_or_ps(_mm_andnot_ps(v15, v8), _mm_and_ps(v9, v15)),
            (__m128)_mm_insert_epi16((__m128i)0i64, 0x8000u, 1));
    v18 = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(v17, v17, 201), v4.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v4.m_quad, v4.m_quad, 201), v17));
    v19 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v14, v16), v16)), _mm_mul_ps(*(__m128 *)_xmm, v16));
    v5 = _mm_mul_ps(v17, v19);
    v6 = _mm_mul_ps(_mm_shuffle_ps(v18, v18, 201), v19);
  }
  v.m_quad = v6;
  u.m_quad = v5;
  hkaiNewFaceCutterUtil::Input::calcExtents(&u, &v, vertices, &extentsOut);
  v20 = (__m128i *)&v3->m_internalToExternal;
  v21 = extentsOut.m_quad;
  *(float *)&result = FLOAT_0_000061038882;
  v22 = extentsOut.m_quad;
  v20[2] = (__m128i)v4.m_quad;
  v23 = _mm_shuffle_ps(v22, v22, 0);
  v24 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_000061038882), (__m128)LODWORD(FLOAT_0_000061038882), 0);
  v25 = _mm_shuffle_ps(v22, v21, 85);
  v26 = _mm_shuffle_ps(v22, v21, 170);
  v27 = (__m128i)_mm_mul_ps(_mm_mul_ps(_mm_sub_ps(v25, v23), v24), v5);
  v28 = (__m128i)_mm_mul_ps(_mm_mul_ps(_mm_sub_ps(_mm_shuffle_ps(v21, v21, 255), v26), v24), v6);
  *v20 = v27;
  v20[1] = v28;
  _mm_store_si128((__m128i *)&v3->m_internalToExternal, _mm_srli_si128(_mm_slli_si128(v27, 4), 4));
  v29 = _mm_add_ps(_mm_mul_ps(v6, v26), _mm_mul_ps(v5, v23));
  _mm_store_si128((__m128i *)&v3->m_internalToExternal.m_col2, _mm_srli_si128(_mm_slli_si128((__m128i)v4.m_quad, 4), 4));
  _mm_store_si128((__m128i *)&v3->m_internalToExternal.m_col1, _mm_srli_si128(_mm_slli_si128(v28, 4), 4));
  v20[3] = (__m128i)v29;
  v20[3] = (__m128i)_mm_shuffle_ps(v29, _mm_unpackhi_ps(v29, query.m_quad), 196);
  extentsOut.m_quad = aabbOut.m_quad;
  __hkMatrix4UtilAlgo::setInverse(
    (hkResult *)&result,
    &v3->m_internalToExternal,
    &v3->m_externalToInternal,
    (hkSimdFloat32 *)&extentsOut);
}

// File Line: 640
// RVA: 0x12F5410
void __fastcall hkaiNewFaceCutterUtil::createFacePolygon(hkaiNewFaceCutterUtil::State *state, hkArrayBase<hkVector4f> *vertices)
{
  __int64 v2; // rdi
  __int16 *v3; // rbx
  hkaiNewFaceCutterUtil::State *v4; // r14
  hkArrayBase<hkVector4f> *v5; // r15
  hkLifoAllocator *v6; // rax
  hkaiNewFaceCutterUtil::Vec2 *v7; // rdx
  int v8; // er8
  char *v9; // rcx
  __int64 v10; // r9
  __m128i v11; // xmm5
  __int64 v12; // r10
  __m128 v13; // xmm1
  __m128 v14; // xmm4
  __m128i v15; // xmm2
  __m128i v16; // xmm0
  __m128i v17; // xmm1
  __m128i v18; // xmm2
  hkLifoAllocator *v19; // rax
  int v20; // edx
  char *v21; // rcx
  signed int v22; // ebx
  hkLifoAllocator *v23; // rax
  int v24; // er8
  signed int v25; // ebx
  hkLifoAllocator *v26; // rax
  int v27; // er8
  hkArrayBase<hkaiNewFaceCutterUtil::Vec2> iv; // [rsp+20h] [rbp-60h]
  void *v29; // [rsp+30h] [rbp-50h]
  int v30; // [rsp+38h] [rbp-48h]
  hkArrayBase<short> uniqueMapping; // [rsp+40h] [rbp-40h]
  void *p; // [rsp+50h] [rbp-30h]
  int v33; // [rsp+58h] [rbp-28h]

  v2 = vertices->m_size;
  v3 = 0i64;
  v4 = state;
  v5 = vertices;
  v30 = v2;
  if ( (_DWORD)v2 )
  {
    v6 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v7 = (hkaiNewFaceCutterUtil::Vec2 *)v6->m_cur;
    v8 = (4 * v2 + 127) & 0xFFFFFF80;
    v9 = (char *)v7 + v8;
    if ( v8 > v6->m_slabSize || v9 > v6->m_end )
    {
      v7 = (hkaiNewFaceCutterUtil::Vec2 *)hkLifoAllocator::allocateFromNewSlab(v6, v8);
      iv.m_data = v7;
    }
    else
    {
      v6->m_cur = v9;
      iv.m_data = v7;
    }
  }
  else
  {
    v7 = 0i64;
    iv.m_data = 0i64;
  }
  v29 = v7;
  iv.m_size = v2;
  v10 = 0i64;
  iv.m_capacityAndFlags = v2 | 0x80000000;
  if ( (signed int)v2 > 0 )
  {
    v11 = _mm_load_si128((const __m128i *)&_xmm);
    v12 = 0i64;
    do
    {
      ++v10;
      ++v12;
      v13 = v5->m_data[v12 - 1].m_quad;
      v14 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v13, v13, 0), v4->m_externalToInternal.m_col0.m_quad),
                    v4->m_externalToInternal.m_col3.m_quad),
                  _mm_mul_ps(
                    _mm_shuffle_ps(v5->m_data[v12 - 1].m_quad, v13, 85),
                    v4->m_externalToInternal.m_col1.m_quad)),
                _mm_mul_ps(_mm_shuffle_ps(v13, v13, 170), v4->m_externalToInternal.m_col2.m_quad)),
              (__m128)xmmword_141A711B0);
      v15 = (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31, v14);
      v16 = _mm_or_si128(
              _mm_add_epi32(
                _mm_cvttps_epi32(
                  _mm_max_ps(
                    _mm_sub_ps(v14, _mm_and_ps((__m128)v15, *(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31)),
                    (__m128)0i64)),
                _mm_slli_epi32(v15, 0x1Fu)),
              (__m128i)_mm_cmpleps(
                         _mm_add_ps(
                           *(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31,
                           *(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31),
                         v14));
      v17 = _mm_cmpgt_epi32(v16, v11);
      v18 = _mm_or_si128(_mm_andnot_si128(v17, v16), _mm_and_si128(v11, v17));
      v7[v10 - 1].m_xy = (_mm_cvtsi128_si32(v18) << 16) | _mm_cvtsi128_si32(_mm_shuffle_epi32(v18, 85));
    }
    while ( v10 < v2 );
  }
  if ( !hkaiNewFaceCutterUtil::Input::isSimplePolygon(&iv) )
    hkaiNewFaceCutterUtil::Input::makeFacePolygonSimple(&iv);
  uniqueMapping.m_size = 0;
  v33 = v2;
  if ( (_DWORD)v2 )
  {
    v19 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v3 = (__int16 *)v19->m_cur;
    v20 = (2 * v2 + 127) & 0xFFFFFF80;
    v21 = (char *)v3 + v20;
    if ( v20 > v19->m_slabSize || v21 > v19->m_end )
      v3 = (__int16 *)hkLifoAllocator::allocateFromNewSlab(v19, v20);
    else
      v19->m_cur = v21;
  }
  uniqueMapping.m_data = v3;
  uniqueMapping.m_capacityAndFlags = v2 | 0x80000000;
  p = v3;
  hkaiNewFaceCutterUtil::Input::makeUniqueWithMapping(&iv, &uniqueMapping);
  hkaiNewFaceCutterUtil::Input::createSegmentsAndEventsForPolygon(
    v4,
    &iv,
    (hkaiNewFaceCutterUtil::Difference)1,
    &uniqueMapping);
  v22 = (2 * v33 + 127) & 0xFFFFFF80;
  v23 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v24 = (v22 + 15) & 0xFFFFFFF0;
  if ( v22 > v23->m_slabSize || (char *)p + v24 != v23->m_cur || v23->m_firstNonLifoEnd == p )
    hkLifoAllocator::slowBlockFree(v23, p, v24);
  else
    v23->m_cur = p;
  if ( uniqueMapping.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      uniqueMapping.m_data,
      2 * (uniqueMapping.m_capacityAndFlags & 0x3FFFFFFF));
  v25 = (4 * v30 + 127) & 0xFFFFFF80;
  v26 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v27 = (v25 + 15) & 0xFFFFFFF0;
  if ( v25 > v26->m_slabSize || (char *)v29 + v27 != v26->m_cur || v26->m_firstNonLifoEnd == v29 )
    hkLifoAllocator::slowBlockFree(v26, v29, v27);
  else
    v26->m_cur = v29;
  if ( iv.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      iv.m_data,
      4 * iv.m_capacityAndFlags);
}

// File Line: 672
// RVA: 0x12F5730
void __fastcall hkaiNewFaceCutterUtil::createNonFacePolygon(hkaiNewFaceCutterUtil::State *state, hkArrayBase<hkVector4f> *vertices, hkaiNewFaceCutterUtil::Difference inwardDifference)
{
  __int64 v3; // r15
  int v4; // esi
  hkaiNewFaceCutterUtil::State *v5; // r13
  int v6; // edi
  hkLifoAllocator *v7; // rax
  hkaiNewFaceCutterUtil::Vec2 *v8; // r14
  int v9; // edx
  char *v10; // rcx
  hkaiNewFaceCutterUtil::Vec2 *v11; // rax
  int v12; // edi
  hkaiNewFaceCutterUtil::Vec2 *v13; // rbx
  __int64 v14; // r12
  __m128 v15; // xmm7
  signed __int64 v16; // rcx
  __int64 v17; // r15
  __m128 v18; // xmm10
  __m128 v19; // xmm10
  __m128 v20; // xmm1
  __m128 v21; // xmm9
  __m128 v22; // xmm1
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
  __m128i v41; // xmm2
  __m128i v42; // xmm3
  __m128i v43; // xmm1
  __m128i v44; // xmm3
  int v45; // edi
  int v46; // ebx
  int v47; // edi
  int v48; // er9
  hkaiNewFaceCutterUtil::Vec2 v49; // eax
  int v50; // ebx
  int v51; // edi
  hkLifoAllocator *v52; // rax
  char *v53; // rdx
  int v54; // ecx
  char *v55; // rdi
  char *v56; // rax
  signed int v57; // eax
  int v58; // eax
  int v59; // er9
  char *v60; // rdi
  __int64 v61; // rcx
  int v62; // eax
  char *v63; // rbx
  signed int v64; // edi
  hkLifoAllocator *v65; // rax
  int v66; // er8
  signed int v67; // edi
  hkLifoAllocator *v68; // rax
  int v69; // er8
  hkArrayBase<hkaiNewFaceCutterUtil::Vec2> iv; // [rsp+28h] [rbp-69h]
  void *v71; // [rsp+38h] [rbp-59h]
  int v72; // [rsp+40h] [rbp-51h]
  char *array; // [rsp+48h] [rbp-49h]
  int v74; // [rsp+50h] [rbp-41h]
  int v75; // [rsp+54h] [rbp-3Dh]
  void *p; // [rsp+58h] [rbp-39h]
  int v77; // [rsp+60h] [rbp-31h]
  hkArrayBase<hkVector4f> *verticesa; // [rsp+100h] [rbp+6Fh]
  hkArrayBase<hkVector4f> *inwardDifferencea; // [rsp+108h] [rbp+77h]
  unsigned int v80; // [rsp+110h] [rbp+7Fh]

  v80 = inwardDifference.m_data;
  inwardDifferencea = vertices;
  v3 = vertices->m_size;
  v4 = 0;
  v5 = state;
  iv.m_data = 0i64;
  v6 = 5 * (v3 + 1);
  iv.m_size = 0;
  iv.m_capacityAndFlags = 2147483648;
  v72 = v6;
  if ( v6 )
  {
    v7 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v8 = (hkaiNewFaceCutterUtil::Vec2 *)v7->m_cur;
    v9 = (20 * (v3 + 1) + 127) & 0xFFFFFF80;
    v10 = (char *)v8 + v9;
    if ( v9 > v7->m_slabSize || v10 > v7->m_end )
    {
      v11 = (hkaiNewFaceCutterUtil::Vec2 *)hkLifoAllocator::allocateFromNewSlab(v7, v9);
      v4 = iv.m_size;
      vertices = verticesa;
      v8 = v11;
    }
    else
    {
      vertices = verticesa;
      v7->m_cur = v10;
      v4 = iv.m_size;
    }
  }
  else
  {
    v8 = 0i64;
  }
  v12 = v6 | 0x80000000;
  v13 = v8;
  iv.m_data = v8;
  v14 = v3;
  iv.m_capacityAndFlags = v12;
  v71 = v8;
  if ( (signed int)v3 > 0 )
  {
    v15 = *(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31;
    v16 = 16i64 * ((signed int)v3 - 1);
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
                  _mm_mul_ps(_mm_shuffle_ps(v20, v20, 0), v5->m_externalToInternal.m_col0.m_quad),
                  v5->m_externalToInternal.m_col3.m_quad),
                _mm_mul_ps(
                  _mm_shuffle_ps(*(__m128 *)((char *)&vertices->m_data->m_quad + v16), v20, 85),
                  v5->m_externalToInternal.m_col1.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v20, v20, 170), v5->m_externalToInternal.m_col2.m_quad));
      v22 = vertices->m_data[v17].m_quad;
      v23 = _mm_shuffle_ps(v21, v21, 0);
      v24 = _mm_shuffle_ps(v21, v21, 85);
      v25 = _mm_sub_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v22, v22, 0), v5->m_externalToInternal.m_col0.m_quad),
                    v5->m_externalToInternal.m_col3.m_quad),
                  _mm_mul_ps(
                    _mm_shuffle_ps(vertices->m_data[v17].m_quad, v22, 85),
                    v5->m_externalToInternal.m_col1.m_quad)),
                _mm_mul_ps(_mm_shuffle_ps(v22, v22, 170), v5->m_externalToInternal.m_col2.m_quad)),
              v21);
      v26 = _mm_shuffle_ps(v25, v25, 0);
      v27 = _mm_shuffle_ps(v25, v25, 85);
      v28 = _mm_movelh_ps(
              _mm_unpacklo_ps(_mm_sub_ps((__m128)0i64, v26), v26),
              _mm_unpacklo_ps(_mm_sub_ps((__m128)0i64, v27), v27));
      v29 = _mm_movelh_ps(_mm_unpacklo_ps(v23, _mm_sub_ps(v19, v23)), _mm_unpacklo_ps(v24, _mm_sub_ps(v19, v24)));
      if ( !_mm_movemask_ps(_mm_and_ps(_mm_cmpltps(v29, (__m128)0i64), _mm_cmpeqps((__m128)0i64, v28))) )
      {
        v30 = _mm_div_ps(v29, v28);
        v31 = _mm_cmpltps(v28, (__m128)0i64);
        v32 = _mm_or_ps(_mm_and_ps(v30, v31), _mm_andnot_ps(v31, aabbOut.m_quad));
        v33 = _mm_cmpltps((__m128)0i64, v28);
        v34 = _mm_max_ps(_mm_shuffle_ps(v32, v32, 78), v32);
        v35 = _mm_or_ps(_mm_and_ps(v30, v33), _mm_andnot_ps(v33, query.m_quad));
        v36 = _mm_max_ps(v34, _mm_shuffle_ps(v34, v34, 177));
        v37 = _mm_min_ps(_mm_shuffle_ps(v35, v35, 78), v35);
        v38 = _mm_min_ps(v37, _mm_shuffle_ps(v37, v37, 177));
        if ( v36.m128_f32[0] < v38.m128_f32[0] )
        {
          v39 = _mm_shuffle_ps(_mm_add_ps(_mm_mul_ps(v25, v36), v21), _mm_add_ps(_mm_mul_ps(v25, v38), v21), 68);
          v40 = _mm_add_ps(_mm_shuffle_ps(v39, v39, 228), (__m128)xmmword_141A711B0);
          v41 = (__m128i)_mm_cmpleps(v15, v40);
          v42 = _mm_or_si128(
                  _mm_add_epi32(
                    _mm_cvttps_epi32(_mm_max_ps(_mm_sub_ps(v40, _mm_and_ps((__m128)v41, v15)), (__m128)0i64)),
                    _mm_slli_epi32(v41, 0x1Fu)),
                  (__m128i)_mm_cmpleps(_mm_add_ps(v15, v15), v40));
          v43 = _mm_cmpgt_epi32(_mm_load_si128((const __m128i *)&_xmm), v42);
          v44 = _mm_or_si128(_mm_and_si128(v42, v43), _mm_andnot_si128(v43, (__m128i)_xmm));
          v45 = (_mm_cvtsi128_si32(v44) << 16) | _mm_cvtsi128_si32(_mm_shuffle_epi32(v44, 85));
          v46 = _mm_cvtsi128_si32(_mm_shuffle_epi32(v44, 255)) | (_mm_cvtsi128_si32(_mm_shuffle_epi32(v44, 170)) << 16);
          if ( v45 != v46 )
          {
            if ( !v4
              || (hkaiNewFaceCutterUtil::Input::addBoundaryPoints(v8[v4 - 1], (hkaiNewFaceCutterUtil::Vec2)v45, &iv),
                  v4 = iv.m_size,
                  v8 = iv.m_data,
                  !iv.m_size)
              || iv.m_data[iv.m_size - 1].m_xy != v45 )
            {
              v8[v4].m_xy = v45;
              v8 = iv.m_data;
              v4 = iv.m_size++ + 1;
            }
            vertices = verticesa;
            v8[v4].m_xy = v46;
            v8 = iv.m_data;
            v15 = *(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31;
            v4 = iv.m_size++ + 1;
          }
        }
      }
      v16 = v17 * 16;
      ++v17;
      --v14;
    }
    while ( v14 );
    v13 = (hkaiNewFaceCutterUtil::Vec2 *)v71;
    v12 = iv.m_capacityAndFlags;
  }
  if ( v4 >= 2 )
  {
    v49.m_xy = v8[v4 - 1].m_xy;
    if ( v8->m_xy == v49.m_xy )
      iv.m_size = v4 - 1;
    else
      hkaiNewFaceCutterUtil::Input::addBoundaryPoints(v49, (hkaiNewFaceCutterUtil::Vec2)v8->m_xy, &iv);
    hkaiNewFaceCutterUtil::Input::ensureSimple(&iv);
  }
  else
  {
    if ( !hkaiNewFaceCutterUtil::Input::domainOriginInConvexPolygon(v5, vertices) )
      goto LABEL_53;
    v47 = v12 & 0x3FFFFFFF;
    if ( v47 < 4 )
    {
      v48 = 4;
      if ( 2 * v47 > 4 )
        v48 = 2 * v47;
      hkArrayUtil::_reserve(
        (hkResult *)&verticesa,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &iv,
        v48,
        4);
      v8 = iv.m_data;
    }
    iv.m_size = 4;
    v8->m_xy = 0;
    iv.m_data[1].m_xy = 1073676288;
    iv.m_data[2].m_xy = 1073692671;
    iv.m_data[3].m_xy = 0x3FFF;
  }
  v50 = iv.m_size;
  array = 0i64;
  v51 = 0;
  v74 = 0;
  v75 = 2147483648;
  v77 = iv.m_size;
  if ( iv.m_size )
  {
    v52 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v53 = (char *)v52->m_cur;
    v54 = (2 * v50 + 127) & 0xFFFFFF80;
    v55 = &v53[v54];
    if ( v54 > v52->m_slabSize || v55 > v52->m_end )
    {
      v56 = (char *)hkLifoAllocator::allocateFromNewSlab(v52, v54);
      v51 = v74;
      v53 = v56;
    }
    else
    {
      v52->m_cur = v55;
      v51 = v74;
    }
  }
  else
  {
    v53 = 0i64;
  }
  array = v53;
  p = v53;
  v75 = v50 | 0x80000000;
  v57 = (v50 | 0x80000000) & 0x3FFFFFFF;
  if ( v57 < v50 )
  {
    v58 = 2 * v57;
    v59 = v50;
    if ( v50 < v58 )
      v59 = v58;
    hkArrayUtil::_reserve(
      (hkResult *)&verticesa,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &array,
      v59,
      2);
    v51 = v74;
    v53 = array;
  }
  LODWORD(v61) = v50 - v51;
  v60 = &v53[2 * v51];
  v61 = (signed int)v61;
  if ( (signed int)v61 > 0i64 )
  {
    while ( v61 )
    {
      *(_WORD *)v60 = -1;
      v60 += 2;
      --v61;
    }
  }
  v74 = v50;
  hkaiNewFaceCutterUtil::Input::createSegmentsAndEventsForPolygon(
    v5,
    &iv,
    (hkaiNewFaceCutterUtil::Difference)inwardDifferencea,
    (hkArrayBase<short> *)&array);
  v62 = v74;
  v63 = (char *)p;
  if ( p == array )
    v62 = 0;
  v74 = v62;
  v64 = (2 * v77 + 127) & 0xFFFFFF80;
  v65 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v66 = (v64 + 15) & 0xFFFFFFF0;
  if ( v64 > v65->m_slabSize || &v63[v66] != v65->m_cur || v65->m_firstNonLifoEnd == v63 )
    hkLifoAllocator::slowBlockFree(v65, v63, v66);
  else
    v65->m_cur = v63;
  v74 = 0;
  if ( v75 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      2 * (v75 & 0x3FFFFFFF));
  v13 = (hkaiNewFaceCutterUtil::Vec2 *)v71;
  v4 = iv.m_size;
  v8 = iv.m_data;
  array = 0i64;
  v75 = 2147483648;
LABEL_53:
  if ( v13 == v8 )
    v4 = 0;
  v67 = (4 * v72 + 127) & 0xFFFFFF80;
  iv.m_size = v4;
  v68 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v69 = (v67 + 15) & 0xFFFFFFF0;
  if ( v67 > v68->m_slabSize || (char *)v13 + v69 != v68->m_cur || v68->m_firstNonLifoEnd == v13 )
    hkLifoAllocator::slowBlockFree(v68, v13, v69);
  else
    v68->m_cur = v13;
  iv.m_size = 0;
  if ( iv.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      iv.m_data,
      4 * iv.m_capacityAndFlags);
}

