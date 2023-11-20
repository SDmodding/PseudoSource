// File Line: 17
// RVA: 0x12FC870
void __fastcall hkFourTransposedPointsf::setTransformedInverseDir(hkFourTransposedPointsf *this, hkMatrix3f *m, hkFourTransposedPointsf *v)
{
  hkVector4f v3; // xmm1
  __m128 v4; // xmm0
  __m128 v5; // xmm4
  hkVector4f v6; // xmm6
  __m128 v7; // xmm7
  __m128 v8; // xmm2
  __m128 v9; // xmm8
  __m128 v10; // xmm0

  v3.m_quad = (__m128)m->m_col0;
  v4 = v->m_vertices[1].m_quad;
  v5 = v->m_vertices[2].m_quad;
  v6.m_quad = (__m128)m->m_col2;
  v7 = _mm_add_ps(
         _mm_mul_ps(_mm_shuffle_ps(m->m_col2.m_quad, v6.m_quad, 0), v->m_vertices[0].m_quad),
         _mm_mul_ps(_mm_shuffle_ps(v6.m_quad, v6.m_quad, 85), v4));
  v8 = _mm_mul_ps(_mm_shuffle_ps(v3.m_quad, v3.m_quad, 85), v4);
  v9 = _mm_add_ps(
         _mm_add_ps(
           _mm_mul_ps(_mm_shuffle_ps(m->m_col1.m_quad, m->m_col1.m_quad, 85), v4),
           _mm_mul_ps(_mm_shuffle_ps(m->m_col1.m_quad, m->m_col1.m_quad, 0), v->m_vertices[0].m_quad)),
         _mm_mul_ps(_mm_shuffle_ps(m->m_col1.m_quad, m->m_col1.m_quad, 170), v5));
  v10 = _mm_mul_ps(_mm_shuffle_ps(m->m_col0.m_quad, m->m_col0.m_quad, 0), v->m_vertices[0].m_quad);
  this->m_vertices[1].m_quad = v9;
  this->m_vertices[2].m_quad = _mm_add_ps(v7, _mm_mul_ps(_mm_shuffle_ps(v6.m_quad, v6.m_quad, 170), v5));
  this->m_vertices[0].m_quad = _mm_add_ps(
                                 _mm_add_ps(v8, v10),
                                 _mm_mul_ps(_mm_shuffle_ps(v3.m_quad, v3.m_quad, 170), v5));
}

// File Line: 25
// RVA: 0x12FC950
void __fastcall hkFourTransposedPointsf::setTransformedInversePos(hkFourTransposedPointsf *this, hkTransformf *m, hkFourTransposedPointsf *v)
{
  hkVector4f v3; // xmm2
  __m128 v4; // xmm1
  hkFourTransposedPointsf va; // [rsp+20h] [rbp-38h]

  v3.m_quad = (__m128)m->m_translation;
  v4 = _mm_shuffle_ps(m->m_translation.m_quad, v3.m_quad, 85);
  va.m_vertices[0].m_quad = _mm_sub_ps(v->m_vertices[0].m_quad, _mm_shuffle_ps(v3.m_quad, v3.m_quad, 0));
  va.m_vertices[1].m_quad = _mm_sub_ps(v->m_vertices[1].m_quad, v4);
  va.m_vertices[2].m_quad = _mm_sub_ps(v->m_vertices[2].m_quad, _mm_shuffle_ps(v3.m_quad, v3.m_quad, 170));
  hkFourTransposedPointsf::setTransformedInverseDir(this, (hkMatrix3f *)&m->m_rotation.m_col0, &va);
}

// File Line: 33
// RVA: 0x12FC9B0
void __fastcall hkFourTransposedPointsf::setRotatedDir(hkFourTransposedPointsf *this, hkMatrix3f *m, hkFourTransposedPointsf *v)
{
  hkVector4f v3; // xmm5
  __m128 v4; // xmm4
  __m128 v5; // xmm3
  hkVector4f v6; // xmm7
  hkVector4f v7; // xmm9
  __m128 v8; // xmm2
  __m128 v9; // xmm8
  __m128 v10; // xmm1
  __m128 v11; // xmm7
  __m128 v12; // xmm0

  v3.m_quad = (__m128)m->m_col0;
  v4 = v->m_vertices[0].m_quad;
  v5 = v->m_vertices[1].m_quad;
  v6.m_quad = (__m128)m->m_col2;
  v7.m_quad = (__m128)m->m_col1;
  v8 = _mm_shuffle_ps(m->m_col1.m_quad, v7.m_quad, 170);
  v9 = _mm_add_ps(
         _mm_add_ps(
           _mm_mul_ps(_mm_shuffle_ps(v7.m_quad, v7.m_quad, 85), v5),
           _mm_mul_ps(_mm_shuffle_ps(v3.m_quad, v3.m_quad, 85), v->m_vertices[0].m_quad)),
         _mm_mul_ps(_mm_shuffle_ps(v6.m_quad, v6.m_quad, 85), v->m_vertices[2].m_quad));
  v10 = _mm_mul_ps(_mm_shuffle_ps(m->m_col2.m_quad, v6.m_quad, 170), v->m_vertices[2].m_quad);
  v11 = _mm_mul_ps(_mm_shuffle_ps(v6.m_quad, v6.m_quad, 0), v->m_vertices[2].m_quad);
  v12 = _mm_mul_ps(_mm_shuffle_ps(m->m_col0.m_quad, m->m_col0.m_quad, 170), v->m_vertices[0].m_quad);
  this->m_vertices[1].m_quad = v9;
  this->m_vertices[2].m_quad = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v8, v5), v12), v10);
  this->m_vertices[0].m_quad = _mm_add_ps(
                                 _mm_add_ps(
                                   _mm_mul_ps(_mm_shuffle_ps(v7.m_quad, v7.m_quad, 0), v5),
                                   _mm_mul_ps(_mm_shuffle_ps(v3.m_quad, v3.m_quad, 0), v4)),
                                 v11);
}

// File Line: 41
// RVA: 0x12FCA80
void __fastcall hkFourTransposedPointsf::copyVertexData(hkVector4f *src, const int numVerts, hkArray<hkFourTransposedPointsf,hkContainerHeapAllocator> *pointsOut)
{
  __int64 v3; // r15
  int v4; // eax
  int v5; // ebx
  int v6; // er14
  hkArray<hkFourTransposedPointsf,hkContainerHeapAllocator> *v7; // rdi
  int v8; // er9
  int v9; // esi
  hkVector4f *v10; // rbp
  int v11; // eax
  signed __int64 v12; // rbx
  __m128 *v13; // rax
  signed __int64 v14; // rcx
  __int64 v15; // rdx
  __m128 v16; // xmm6
  __m128 v17; // xmm5
  __m128 v18; // xmm2
  __m128 v19; // xmm1
  int v20; // esi
  __int64 v21; // rdi
  __int128 *v22; // rsi
  signed __int64 v23; // rax
  __m128 v24; // xmm3
  __m128 v25; // xmm1
  __m128 Dst; // [rsp+30h] [rbp-68h]
  __m128 v27; // [rsp+40h] [rbp-58h]
  __m128 v28; // [rsp+50h] [rbp-48h]
  __m128 v29; // [rsp+60h] [rbp-38h]
  __int64 v30; // [rsp+A8h] [rbp+10h]

  v3 = pointsOut->m_size;
  v4 = pointsOut->m_capacityAndFlags & 0x3FFFFFFF;
  v5 = (numVerts + 3) >> 2;
  v6 = numVerts >> 2;
  v7 = pointsOut;
  v8 = v3 + v5;
  v9 = numVerts;
  v10 = src;
  if ( v4 < (signed int)v3 + v5 )
  {
    v11 = 2 * v4;
    if ( v8 < v11 )
      v8 = v11;
    hkArrayUtil::_reserve(
      (hkResult *)&v30,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      pointsOut,
      v8,
      48);
  }
  v7->m_size += v5;
  v12 = (signed __int64)&v7->m_data[v3];
  if ( v6 > 0 )
  {
    v13 = &v10[2].m_quad;
    v14 = v12 + 32;
    v15 = v6;
    do
    {
      v16 = v10->m_quad;
      v17 = *v13;
      v10 += 4;
      v14 += 48i64;
      v13 += 4;
      v18 = _mm_shuffle_ps(v16, v13[-5], 68);
      v19 = _mm_shuffle_ps(v17, v13[-3], 68);
      *(__m128 *)(v14 - 48) = _mm_shuffle_ps(_mm_shuffle_ps(v16, v13[-5], 238), _mm_shuffle_ps(v17, v13[-3], 238), 136);
      *(__m128 *)(v14 - 80) = _mm_shuffle_ps(v18, v19, 136);
      *(__m128 *)(v14 - 64) = _mm_shuffle_ps(v18, v19, 221);
      --v15;
    }
    while ( v15 );
  }
  v20 = v9 - 4 * v6;
  if ( v20 )
  {
    v21 = v20;
    if ( v20 > 0 )
      memmove(&Dst, v10, 16i64 * v20);
    if ( v20 < 4i64 )
    {
      v22 = (__int128 *)(&Dst + v20);
      *v22 = (__int128)v10[v21 - 1];
      qmemcpy(v22 + 1, v22, 16 * (3 - v21));
    }
    v23 = 6i64 * v6;
    v24 = _mm_shuffle_ps(Dst, v27, 68);
    v25 = _mm_shuffle_ps(v28, v29, 68);
    *(__m128 *)(v12 + 8 * v23 + 32) = _mm_shuffle_ps(_mm_shuffle_ps(Dst, v27, 238), _mm_shuffle_ps(v28, v29, 238), 136);
    *(__m128 *)(v12 + 8 * v23) = _mm_shuffle_ps(v24, v25, 136);
    *(__m128 *)(v12 + 8 * v23 + 16) = _mm_shuffle_ps(v24, v25, 221);
  }
}

// File Line: 74
// RVA: 0x12FCC50
void __fastcall hkFourTransposedPointsf::getOriginalVertices(hkFourTransposedPointsf *verts4in, int numVertices, hkcdVertex *verticesOut)
{
  __m128i v3; // xmm5
  unsigned int v4; // er9
  hkcdVertex *v5; // r10
  __int64 v6; // r8
  __m128i v7; // xmm6
  signed __int64 v8; // rax
  hkVector4f *v9; // rcx
  hkVector4f v10; // xmm0
  hkVector4f v11; // xmm1
  hkVector4f v12; // xmm0
  __m128 v13; // xmm4
  __m128 v14; // xmm3
  __m128 v15; // xmm4
  __m128 v16; // xmm3
  __m128 v17; // xmm1
  __m128 v18; // xmm2
  signed __int64 v19; // rcx
  signed __int64 v20; // rax
  signed __int64 v21; // rcx

  v3 = (__m128i)xmmword_141A720C0;
  v4 = (unsigned int)(numVertices + 3) >> 2;
  v5 = verticesOut;
  v6 = v4;
  v7 = _mm_load_si128((const __m128i *)&_xmm);
  if ( (signed int)v4 > 0 )
  {
    v8 = (signed __int64)&v5[2];
    v9 = &verts4in->m_vertices[2];
    do
    {
      v10.m_quad = (__m128)v9[-2];
      v11.m_quad = (__m128)v9[-1];
      v8 += 64i64;
      v9 += 3;
      *(hkVector4f *)(v8 - 96) = (hkVector4f)v10.m_quad;
      v12.m_quad = (__m128)v9[-3];
      *(hkVector4f *)(v8 - 80) = (hkVector4f)v11.m_quad;
      *(hkVector4f *)(v8 - 64) = (hkVector4f)v12.m_quad;
      *(__m128i *)(v8 - 48) = v3;
      v13 = *(__m128 *)(v8 - 96);
      v14 = v13;
      v15 = _mm_shuffle_ps(v13, *(__m128 *)(v8 - 80), 238);
      v16 = _mm_shuffle_ps(v14, *(__m128 *)(v8 - 80), 68);
      v17 = _mm_shuffle_ps(*(__m128 *)(v8 - 64), (__m128)v3, 68);
      v18 = _mm_shuffle_ps(*(__m128 *)(v8 - 64), (__m128)v3, 238);
      v3 = _mm_add_epi32(v3, v7);
      *(__m128 *)(v8 - 96) = _mm_shuffle_ps(v16, v17, 136);
      *(__m128 *)(v8 - 80) = _mm_shuffle_ps(v16, v17, 221);
      *(__m128 *)(v8 - 64) = _mm_shuffle_ps(v15, v18, 136);
      *(__m128 *)(v8 - 48) = _mm_shuffle_ps(v15, v18, 221);
      --v6;
    }
    while ( v6 );
  }
  v19 = (signed int)(4 * v4);
  if ( numVertices < v19 )
  {
    v20 = (signed __int64)&v5[numVertices];
    v21 = v19 - numVertices;
    do
    {
      v20 += 16i64;
      *(hkcdVertex *)(v20 - 16) = v5[numVertices - 1];
      --v21;
    }
    while ( v21 );
  }
}

