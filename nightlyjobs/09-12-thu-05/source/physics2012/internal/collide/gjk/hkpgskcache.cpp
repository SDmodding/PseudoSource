// File Line: 23
// RVA: 0xDC7A30
void __fastcall hkpGskCache::initTriangle(
        hkpGskCache *this,
        hkpConvexShape *shapeA,
        hkpTriangleShape *shapeB,
        hkTransformf *btoa)
{
  __int64 v6; // rdx
  hkVector4f v7; // xmm3
  hkVector4f v8; // xmm4
  hkVector4f v9; // xmm5
  hkVector4f *p_m_vertexC; // rax
  hkVector4f v11; // xmm6
  __m128 m_quad; // xmm1
  hkBaseObjectVtbl *vfptr; // rax
  __m128 v14; // xmm1
  __m128 v15; // xmm2
  __m128 v16; // xmm0
  hkBaseObjectVtbl *v17; // rax
  __m128 v18; // xmm1
  unsigned __int16 v19; // ax
  int v20; // eax
  char v21; // dl
  __m128 v22; // [rsp+20h] [rbp-78h] BYREF
  __m128 v23; // [rsp+30h] [rbp-68h] BYREF
  char v24[12]; // [rsp+40h] [rbp-58h] BYREF
  unsigned __int16 v25; // [rsp+4Ch] [rbp-4Ch]
  __m128 v26; // [rsp+50h] [rbp-48h]
  __m128 v27; // [rsp+60h] [rbp-38h]
  __m128 v28; // [rsp+70h] [rbp-28h] BYREF

  if ( shapeB->m_isExtruded )
  {
    hkpGskCache::init(this, shapeA, shapeB, btoa);
  }
  else
  {
    *(_DWORD *)&this->m_vertices[1] = 0x10000;
    v6 = 2i64;
    this->m_vertices[3] = 2;
    v7.m_quad = (__m128)btoa->m_rotation.m_col0;
    v8.m_quad = (__m128)btoa->m_rotation.m_col1;
    v9.m_quad = (__m128)btoa->m_rotation.m_col2;
    p_m_vertexC = &shapeB->m_vertexC;
    v11.m_quad = (__m128)btoa->m_translation;
    do
    {
      m_quad = p_m_vertexC->m_quad;
      --p_m_vertexC;
      --v6;
      *(__m128 *)((char *)&p_m_vertexC[-4].m_quad + (char *)&v28 - (char *)shapeB) = _mm_add_ps(
                                                                                       _mm_add_ps(
                                                                                         _mm_add_ps(
                                                                                           _mm_mul_ps(
                                                                                             _mm_shuffle_ps(
                                                                                               m_quad,
                                                                                               m_quad,
                                                                                               85),
                                                                                             v8.m_quad),
                                                                                           _mm_mul_ps(
                                                                                             _mm_shuffle_ps(
                                                                                               m_quad,
                                                                                               m_quad,
                                                                                               0),
                                                                                             v7.m_quad)),
                                                                                         _mm_mul_ps(
                                                                                           _mm_shuffle_ps(
                                                                                             m_quad,
                                                                                             m_quad,
                                                                                             170),
                                                                                           v9.m_quad)),
                                                                                       v11.m_quad);
    }
    while ( v6 >= 0 );
    vfptr = shapeA->vfptr;
    v14 = _mm_sub_ps(v28, v27);
    v15 = _mm_sub_ps(v27, v26);
    v16 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v15), _mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), v14));
    v22 = _mm_shuffle_ps(v16, v16, 201);
    ((void (__fastcall *)(hkpConvexShape *, unsigned __int16 *, __int64, __m128 *))vfptr[4].__first_virtual_table_function__)(
      shapeA,
      &this->m_vertices[1],
      1i64,
      &v23);
    v17 = shapeA->vfptr;
    v18 = _mm_mul_ps(_mm_sub_ps(v23, v26), v22);
    v22 = _mm_xor_ps(
            (__m128)_mm_slli_epi32(
                      _mm_srli_epi32(
                        (__m128i)_mm_add_ps(
                                   _mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)),
                                   _mm_shuffle_ps(v18, v18, 170)),
                        0x1Fu),
                      0x1Fu),
            v22);
    ((void (__fastcall *)(hkpConvexShape *, __m128 *, char *))v17[4].__vecDelDtor)(shapeA, &v22, v24);
    v19 = v25;
    *(_WORD *)&this->m_dimA = 769;
    this->m_vertices[0] = v19;
    v20 = ((__int64 (__fastcall *)(hkpConvexShape *))shapeA->vfptr[5].__first_virtual_table_function__)(shapeA);
    v21 = 15;
    this->m_gskFlags = 0;
    if ( v20 <= 3 )
      v21 = v20;
    *((_BYTE *)this + 10) = v21 & 0xF | 0x30;
  }
}

// File Line: 60
// RVA: 0xDC7880
void __fastcall hkpGskCache::init(hkpGskCache *this, hkpConvexShape *shapeA, hkpConvexShape *shapeB, hkTransformf *aTb)
{
  hkBaseObjectVtbl *vfptr; // rax
  hkBaseObjectVtbl *v9; // rax
  __m128 v10; // xmm6
  hkVector4f v11; // xmm3
  hkVector4f v12; // xmm1
  __m128 v13; // xmm4
  __m128 v14; // xmm1
  __m128 v15; // xmm2
  hkBaseObjectVtbl *v16; // rax
  __int16 v17; // ax
  int v18; // ebx
  int v19; // eax
  char v20; // r8
  char v21; // dl
  char v22; // dl
  __m128 v23; // [rsp+20h] [rbp-88h] BYREF
  __m128 v24; // [rsp+30h] [rbp-78h] BYREF
  __m128 v25; // [rsp+40h] [rbp-68h] BYREF
  __m128 v26; // [rsp+50h] [rbp-58h] BYREF
  __m128 v27; // [rsp+60h] [rbp-48h] BYREF
  char v28[12]; // [rsp+70h] [rbp-38h] BYREF
  unsigned __int16 v29; // [rsp+7Ch] [rbp-2Ch]
  __int16 v30; // [rsp+B0h] [rbp+8h] BYREF

  vfptr = shapeA->vfptr;
  v30 = 0;
  ((void (__fastcall *)(hkpConvexShape *, __int16 *, __int64, __m128 *))vfptr[4].__first_virtual_table_function__)(
    shapeA,
    &v30,
    1i64,
    &v26);
  ((void (__fastcall *)(hkpConvexShape *, __int16 *, __int64, __m128 *))shapeB->vfptr[4].__first_virtual_table_function__)(
    shapeB,
    &v30,
    1i64,
    &v25);
  v9 = shapeA->vfptr;
  v10 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v25, v25, 0), aTb->m_rotation.m_col0.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v25, v25, 85), aTb->m_rotation.m_col1.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v25, v25, 170), aTb->m_rotation.m_col2.m_quad)),
          aTb->m_translation.m_quad);
  v23 = _mm_sub_ps(v10, v26);
  ((void (__fastcall *)(hkpConvexShape *, __m128 *, __m128 *))v9[4].__vecDelDtor)(shapeA, &v23, &v24);
  v11.m_quad = (__m128)aTb->m_rotation.m_col2;
  v12.m_quad = (__m128)aTb->m_rotation.m_col0;
  v23 = _mm_sub_ps(v10, v24);
  v13 = _mm_unpackhi_ps(v12.m_quad, aTb->m_rotation.m_col1.m_quad);
  v14 = _mm_unpacklo_ps(v12.m_quad, aTb->m_rotation.m_col1.m_quad);
  v15 = _mm_movelh_ps(v14, v11.m_quad);
  v16 = shapeB->vfptr;
  v27 = _mm_xor_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v23, v23, 85), _mm_shuffle_ps(_mm_movehl_ps(v15, v14), v11.m_quad, 212)),
              _mm_mul_ps(_mm_shuffle_ps(v23, v23, 0), v15)),
            _mm_mul_ps(_mm_shuffle_ps(v23, v23, 170), _mm_shuffle_ps(v13, v11.m_quad, 228))),
          (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0));
  ((void (__fastcall *)(hkpConvexShape *, __m128 *, char *))v16[4].__vecDelDtor)(shapeB, &v27, v28);
  this->m_vertices[1] = v29;
  v17 = v24.m128_i16[6];
  *(_DWORD *)&this->m_vertices[2] = 0;
  *(_WORD *)&this->m_dimA = 257;
  this->m_vertices[0] = v17;
  v18 = ((__int64 (__fastcall *)(hkpConvexShape *))shapeA->vfptr[5].__first_virtual_table_function__)(shapeA);
  v19 = ((__int64 (__fastcall *)(hkpConvexShape *))shapeB->vfptr[5].__first_virtual_table_function__)(shapeB);
  v20 = 15;
  v21 = 15;
  this->m_gskFlags = 0;
  if ( v19 <= 3 )
    v21 = v19;
  v22 = 16 * v21;
  if ( v18 <= 3 )
    v20 = v18;
  *((_BYTE *)this + 10) = v20 & 0xF | v22;
}

