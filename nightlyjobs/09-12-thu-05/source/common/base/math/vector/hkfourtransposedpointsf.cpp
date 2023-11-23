// File Line: 17
// RVA: 0x12FC870
void __fastcall hkFourTransposedPointsf::setTransformedInverseDir(
        hkFourTransposedPointsf *this,
        hkMatrix3f *m,
        hkFourTransposedPointsf *v)
{
  hkVector4f v3; // xmm1
  __m128 m_quad; // xmm0
  __m128 v5; // xmm4
  hkVector4f v6; // xmm6
  __m128 v7; // xmm7
  __m128 v8; // xmm2
  __m128 v9; // xmm8
  __m128 v10; // xmm0

  v3.m_quad = (__m128)m->m_col0;
  m_quad = v->m_vertices[1].m_quad;
  v5 = v->m_vertices[2].m_quad;
  v6.m_quad = (__m128)m->m_col2;
  v7 = _mm_add_ps(
         _mm_mul_ps(_mm_shuffle_ps(v6.m_quad, v6.m_quad, 0), v->m_vertices[0].m_quad),
         _mm_mul_ps(_mm_shuffle_ps(v6.m_quad, v6.m_quad, 85), m_quad));
  v8 = _mm_mul_ps(_mm_shuffle_ps(v3.m_quad, v3.m_quad, 85), m_quad);
  v9 = _mm_add_ps(
         _mm_add_ps(
           _mm_mul_ps(_mm_shuffle_ps(m->m_col1.m_quad, m->m_col1.m_quad, 85), m_quad),
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
void __fastcall hkFourTransposedPointsf::setTransformedInversePos(
        hkFourTransposedPointsf *this,
        hkTransformf *m,
        hkFourTransposedPointsf *v)
{
  hkVector4f v3; // xmm2
  hkFourTransposedPointsf va; // [rsp+20h] [rbp-38h] BYREF

  v3.m_quad = (__m128)m->m_translation;
  va.m_vertices[0].m_quad = _mm_sub_ps(v->m_vertices[0].m_quad, _mm_shuffle_ps(v3.m_quad, v3.m_quad, 0));
  va.m_vertices[1].m_quad = _mm_sub_ps(v->m_vertices[1].m_quad, _mm_shuffle_ps(v3.m_quad, v3.m_quad, 85));
  va.m_vertices[2].m_quad = _mm_sub_ps(v->m_vertices[2].m_quad, _mm_shuffle_ps(v3.m_quad, v3.m_quad, 170));
  hkFourTransposedPointsf::setTransformedInverseDir(this, &m->m_rotation, &va);
}

// File Line: 33
// RVA: 0x12FC9B0
void __fastcall hkFourTransposedPointsf::setRotatedDir(
        hkFourTransposedPointsf *this,
        hkMatrix3f *m,
        hkFourTransposedPointsf *v)
{
  hkVector4f v3; // xmm5
  __m128 m_quad; // xmm4
  __m128 v5; // xmm3
  hkVector4f v6; // xmm7
  hkVector4f v7; // xmm9
  __m128 v8; // xmm8
  __m128 v9; // xmm1
  __m128 v10; // xmm7
  __m128 v11; // xmm0

  v3.m_quad = (__m128)m->m_col0;
  m_quad = v->m_vertices[0].m_quad;
  v5 = v->m_vertices[1].m_quad;
  v6.m_quad = (__m128)m->m_col2;
  v7.m_quad = (__m128)m->m_col1;
  v8 = _mm_add_ps(
         _mm_add_ps(
           _mm_mul_ps(_mm_shuffle_ps(v7.m_quad, v7.m_quad, 85), v5),
           _mm_mul_ps(_mm_shuffle_ps(v3.m_quad, v3.m_quad, 85), v->m_vertices[0].m_quad)),
         _mm_mul_ps(_mm_shuffle_ps(v6.m_quad, v6.m_quad, 85), v->m_vertices[2].m_quad));
  v9 = _mm_mul_ps(_mm_shuffle_ps(v6.m_quad, v6.m_quad, 170), v->m_vertices[2].m_quad);
  v10 = _mm_mul_ps(_mm_shuffle_ps(v6.m_quad, v6.m_quad, 0), v->m_vertices[2].m_quad);
  v11 = _mm_mul_ps(_mm_shuffle_ps(m->m_col0.m_quad, m->m_col0.m_quad, 170), v->m_vertices[0].m_quad);
  this->m_vertices[1].m_quad = v8;
  this->m_vertices[2].m_quad = _mm_add_ps(
                                 _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v7.m_quad, v7.m_quad, 170), v5), v11),
                                 v9);
  this->m_vertices[0].m_quad = _mm_add_ps(
                                 _mm_add_ps(
                                   _mm_mul_ps(_mm_shuffle_ps(v7.m_quad, v7.m_quad, 0), v5),
                                   _mm_mul_ps(_mm_shuffle_ps(v3.m_quad, v3.m_quad, 0), m_quad)),
                                 v10);
}

// File Line: 41
// RVA: 0x12FCA80
void __fastcall hkFourTransposedPointsf::copyVertexData(
        hkVector4f *src,
        const int numVerts,
        hkArray<hkFourTransposedPointsf,hkContainerHeapAllocator> *pointsOut)
{
  __int64 m_size; // r15
  int v4; // eax
  int v5; // ebx
  int v6; // r14d
  int v8; // r9d
  int v11; // eax
  hkFourTransposedPointsf *v12; // rbx
  hkVector4f *v13; // rax
  hkVector4f *v14; // rcx
  __int64 v15; // rdx
  __m128 m_quad; // xmm6
  __m128 v17; // xmm5
  __m128 v18; // xmm2
  __m128 v19; // xmm1
  int v20; // esi
  __int64 v21; // rdi
  hkVector4f *v22; // rsi
  __int64 v23; // rax
  __m128 v24; // xmm3
  __m128 v25; // xmm1
  __m128 Dst; // [rsp+30h] [rbp-68h] BYREF
  __m128 v27; // [rsp+40h] [rbp-58h]
  __m128 v28; // [rsp+50h] [rbp-48h]
  __m128 v29; // [rsp+60h] [rbp-38h]
  hkResult v30; // [rsp+A8h] [rbp+10h] BYREF

  m_size = pointsOut->m_size;
  v4 = pointsOut->m_capacityAndFlags & 0x3FFFFFFF;
  v5 = (numVerts + 3) >> 2;
  v6 = numVerts >> 2;
  v8 = m_size + v5;
  if ( v4 < (int)m_size + v5 )
  {
    v11 = 2 * v4;
    if ( v8 < v11 )
      v8 = v11;
    hkArrayUtil::_reserve(&v30, &hkContainerHeapAllocator::s_alloc, (const void **)&pointsOut->m_data, v8, 48);
  }
  pointsOut->m_size += v5;
  v12 = &pointsOut->m_data[m_size];
  if ( v6 > 0 )
  {
    v13 = src + 2;
    v14 = &v12->m_vertices[2];
    v15 = v6;
    do
    {
      m_quad = src->m_quad;
      v17 = v13->m_quad;
      src += 4;
      v14 += 3;
      v13 += 4;
      v18 = _mm_shuffle_ps(m_quad, v13[-5].m_quad, 68);
      v19 = _mm_shuffle_ps(v17, v13[-3].m_quad, 68);
      v14[-3].m_quad = _mm_shuffle_ps(
                         _mm_shuffle_ps(m_quad, v13[-5].m_quad, 238),
                         _mm_shuffle_ps(v17, v13[-3].m_quad, 238),
                         136);
      v14[-5].m_quad = _mm_shuffle_ps(v18, v19, 136);
      v14[-4].m_quad = _mm_shuffle_ps(v18, v19, 221);
      --v15;
    }
    while ( v15 );
  }
  v20 = numVerts - 4 * v6;
  if ( v20 )
  {
    v21 = v20;
    if ( v20 > 0 )
      memmove(&Dst, src, 16i64 * v20);
    if ( v20 < 4i64 )
    {
      v22 = (hkVector4f *)(&Dst + v20);
      *v22 = src[v21 - 1];
      qmemcpy(&v22[1], v22, 16 * (3 - v21));
    }
    v23 = v6;
    v24 = _mm_shuffle_ps(Dst, v27, 68);
    v25 = _mm_shuffle_ps(v28, v29, 68);
    v12[v23].m_vertices[2].m_quad = _mm_shuffle_ps(_mm_shuffle_ps(Dst, v27, 238), _mm_shuffle_ps(v28, v29, 238), 136);
    v12[v23].m_vertices[0].m_quad = _mm_shuffle_ps(v24, v25, 136);
    v12[v23].m_vertices[1].m_quad = _mm_shuffle_ps(v24, v25, 221);
  }
}

// File Line: 74
// RVA: 0x12FCC50
void __fastcall hkFourTransposedPointsf::getOriginalVertices(
        hkFourTransposedPointsf *verts4in,
        int numVertices,
        hkcdVertex *verticesOut)
{
  __m128i v3; // xmm5
  unsigned int v4; // r9d
  __int64 v6; // r8
  __m128i si128; // xmm6
  hkcdVertex *v8; // rax
  hkVector4f *v9; // rcx
  hkVector4f v10; // xmm0
  hkVector4f v11; // xmm1
  hkVector4f v12; // xmm0
  __m128 m_quad; // xmm3
  __m128 v14; // xmm4
  __m128 v15; // xmm3
  __m128 v16; // xmm1
  __m128 v17; // xmm2
  __int64 v18; // rcx
  hkcdVertex *v19; // rax
  __int64 v20; // rcx

  v3 = (__m128i)xmmword_141A720C0;
  v4 = (unsigned int)(numVertices + 3) >> 2;
  v6 = v4;
  si128 = _mm_load_si128((const __m128i *)&_xmm);
  if ( v4 )
  {
    v8 = verticesOut + 2;
    v9 = &verts4in->m_vertices[2];
    do
    {
      v10.m_quad = (__m128)v9[-2];
      v11.m_quad = (__m128)v9[-1];
      v8 += 4;
      v9 += 3;
      v8[-6] = (hkcdVertex)v10.m_quad;
      v12.m_quad = (__m128)v9[-3];
      v8[-5] = (hkcdVertex)v11.m_quad;
      v8[-4] = (hkcdVertex)v12.m_quad;
      v8[-3] = (hkcdVertex)v3;
      m_quad = v8[-6].m_quad;
      v14 = _mm_shuffle_ps(m_quad, v8[-5].m_quad, 238);
      v15 = _mm_shuffle_ps(m_quad, v8[-5].m_quad, 68);
      v16 = _mm_shuffle_ps(v8[-4].m_quad, (__m128)v3, 68);
      v17 = _mm_shuffle_ps(v8[-4].m_quad, (__m128)v3, 238);
      v3 = _mm_add_epi32(v3, si128);
      v8[-6].m_quad = _mm_shuffle_ps(v15, v16, 136);
      v8[-5].m_quad = _mm_shuffle_ps(v15, v16, 221);
      v8[-4].m_quad = _mm_shuffle_ps(v14, v17, 136);
      v8[-3].m_quad = _mm_shuffle_ps(v14, v17, 221);
      --v6;
    }
    while ( v6 );
  }
  v18 = (int)(4 * v4);
  if ( numVertices < v18 )
  {
    v19 = &verticesOut[numVertices];
    v20 = v18 - numVertices;
    do
    {
      ++v19;
      v19[-1] = verticesOut[numVertices - 1];
      --v20;
    }
    while ( v20 );
  }
}

