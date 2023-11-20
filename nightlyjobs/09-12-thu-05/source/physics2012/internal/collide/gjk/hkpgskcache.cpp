// File Line: 23
// RVA: 0xDC7A30
void __fastcall hkpGskCache::initTriangle(hkpGskCache *this, hkpConvexShape *shapeA, hkpTriangleShape *shapeB, hkTransformf *btoa)
{
  hkpConvexShape *v4; // rdi
  hkpGskCache *v5; // rbx
  signed __int64 v6; // rdx
  hkVector4f v7; // xmm3
  hkVector4f v8; // xmm4
  hkVector4f v9; // xmm5
  __m128 *v10; // rax
  hkVector4f v11; // xmm6
  __m128 v12; // xmm1
  hkBaseObjectVtbl *v13; // rax
  __m128 v14; // xmm1
  __m128 v15; // xmm2
  __m128 v16; // xmm0
  hkBaseObjectVtbl *v17; // rax
  __m128 v18; // xmm1
  __int16 v19; // ax
  signed int v20; // eax
  char v21; // dl
  __m128 v22; // [rsp+20h] [rbp-78h]
  __m128 v23; // [rsp+30h] [rbp-68h]
  char v24; // [rsp+40h] [rbp-58h]
  __int16 v25; // [rsp+4Ch] [rbp-4Ch]
  __m128 v26; // [rsp+50h] [rbp-48h]
  __m128 v27; // [rsp+60h] [rbp-38h]
  __m128 v28; // [rsp+70h] [rbp-28h]

  v4 = shapeA;
  v5 = this;
  if ( shapeB->m_isExtruded )
  {
    hkpGskCache::init(this, shapeA, (hkpConvexShape *)&shapeB->vfptr, btoa);
  }
  else
  {
    *(_DWORD *)&this->m_vertices[1] = 0x10000;
    v6 = 2i64;
    this->m_vertices[3] = 2;
    v7.m_quad = (__m128)btoa->m_rotation.m_col0;
    v8.m_quad = (__m128)btoa->m_rotation.m_col1;
    v9.m_quad = (__m128)btoa->m_rotation.m_col2;
    v10 = &shapeB->m_vertexC.m_quad;
    v11.m_quad = (__m128)btoa->m_translation;
    do
    {
      v12 = *v10;
      --v10;
      --v6;
      *(__m128 *)((char *)v10 + (char *)&v28 - (char *)shapeB - 64) = _mm_add_ps(
                                                                        _mm_add_ps(
                                                                          _mm_add_ps(
                                                                            _mm_mul_ps(
                                                                              _mm_shuffle_ps(v12, v12, 85),
                                                                              v8.m_quad),
                                                                            _mm_mul_ps(
                                                                              _mm_shuffle_ps(v12, v12, 0),
                                                                              v7.m_quad)),
                                                                          _mm_mul_ps(
                                                                            _mm_shuffle_ps(v12, v12, 170),
                                                                            v9.m_quad)),
                                                                        v11.m_quad);
    }
    while ( v6 >= 0 );
    v13 = v4->vfptr;
    v14 = _mm_sub_ps(v28, v27);
    v15 = _mm_sub_ps(v27, v26);
    v16 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v15), _mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), v14));
    v22 = _mm_shuffle_ps(v16, v16, 201);
    ((void (__fastcall *)(hkpConvexShape *, unsigned __int16 *, signed __int64, __m128 *))v13[4].__first_virtual_table_function__)(
      v4,
      &this->m_vertices[1],
      1i64,
      &v23);
    v17 = v4->vfptr;
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
    ((void (__fastcall *)(hkpConvexShape *, __m128 *, char *))v17[4].__vecDelDtor)(v4, &v22, &v24);
    v19 = v25;
    *(_WORD *)&v5->m_dimA = 769;
    v5->m_vertices[0] = v19;
    v20 = ((__int64 (__fastcall *)(hkpConvexShape *))v4->vfptr[5].__first_virtual_table_function__)(v4);
    v21 = 15;
    v5->m_gskFlags = 0;
    if ( v20 <= 3 )
      v21 = v20;
    *((_BYTE *)v5 + 10) = v21 & 0xF | 0x30;
  }
}

// File Line: 60
// RVA: 0xDC7880
void __fastcall hkpGskCache::init(hkpGskCache *this, hkpConvexShape *shapeA, hkpConvexShape *shapeB, hkTransformf *aTb)
{
  hkBaseObjectVtbl *v4; // rax
  hkpConvexShape *v5; // rdi
  hkTransformf *v6; // rbx
  hkpConvexShape *v7; // rsi
  hkpGskCache *v8; // r14
  hkBaseObjectVtbl *v9; // rax
  __m128 v10; // xmm6
  __m128 v11; // xmm3
  __m128 v12; // xmm4
  __m128 v13; // xmm1
  __m128 v14; // xmm1
  __m128 v15; // xmm2
  hkBaseObjectVtbl *v16; // rax
  __int16 v17; // ax
  signed int v18; // ebx
  signed int v19; // eax
  char v20; // r8
  char v21; // dl
  char v22; // dl
  __m128 v23; // [rsp+20h] [rbp-88h]
  __m128 v24; // [rsp+30h] [rbp-78h]
  __m128 v25; // [rsp+40h] [rbp-68h]
  __m128 v26; // [rsp+50h] [rbp-58h]
  __m128 v27; // [rsp+60h] [rbp-48h]
  char v28; // [rsp+70h] [rbp-38h]
  unsigned __int16 v29; // [rsp+7Ch] [rbp-2Ch]
  __int16 v30; // [rsp+B0h] [rbp+8h]

  v4 = shapeA->vfptr;
  v5 = shapeA;
  v6 = aTb;
  v7 = shapeB;
  v8 = this;
  v30 = 0;
  ((void (__fastcall *)(hkpConvexShape *, __int16 *, signed __int64, __m128 *))v4[4].__first_virtual_table_function__)(
    shapeA,
    &v30,
    1i64,
    &v26);
  ((void (__fastcall *)(hkpConvexShape *, __int16 *, signed __int64, __m128 *))v7->vfptr[4].__first_virtual_table_function__)(
    v7,
    &v30,
    1i64,
    &v25);
  v9 = v5->vfptr;
  v10 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v25, v25, 0), v6->m_rotation.m_col0.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v25, v25, 85), v6->m_rotation.m_col1.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v25, v25, 170), v6->m_rotation.m_col2.m_quad)),
          v6->m_translation.m_quad);
  v23 = _mm_sub_ps(v10, v26);
  ((void (__fastcall *)(hkpConvexShape *, __m128 *, __m128 *))v9[4].__vecDelDtor)(v5, &v23, &v24);
  v11 = v6->m_rotation.m_col2.m_quad;
  v12 = v6->m_rotation.m_col0.m_quad;
  v13 = v6->m_rotation.m_col0.m_quad;
  v23 = _mm_sub_ps(v10, v24);
  v14 = _mm_unpacklo_ps(v13, v6->m_rotation.m_col1.m_quad);
  v15 = _mm_movelh_ps(v14, v11);
  v16 = v7->vfptr;
  v27 = _mm_xor_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v23, v23, 85), _mm_shuffle_ps(_mm_movehl_ps(v15, v14), v11, 212)),
              _mm_mul_ps(_mm_shuffle_ps(v23, v23, 0), v15)),
            _mm_mul_ps(
              _mm_shuffle_ps(v23, v23, 170),
              _mm_shuffle_ps(_mm_unpackhi_ps(v12, v6->m_rotation.m_col1.m_quad), v11, 228))),
          (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0));
  ((void (__fastcall *)(hkpConvexShape *, __m128 *, char *))v16[4].__vecDelDtor)(v7, &v27, &v28);
  v8->m_vertices[1] = v29;
  v17 = v24.m128_i16[6];
  *(_DWORD *)&v8->m_vertices[2] = 0;
  *(_WORD *)&v8->m_dimA = 257;
  v8->m_vertices[0] = v17;
  v18 = ((__int64 (__fastcall *)(hkpConvexShape *))v5->vfptr[5].__first_virtual_table_function__)(v5);
  v19 = ((__int64 (__fastcall *)(hkpConvexShape *))v7->vfptr[5].__first_virtual_table_function__)(v7);
  v20 = 15;
  v21 = 15;
  v8->m_gskFlags = 0;
  if ( v19 <= 3 )
    v21 = v19;
  v22 = 16 * v21;
  if ( v18 <= 3 )
    v20 = v18;
  *((_BYTE *)v8 + 10) = v20 & 0xF | v22;
}

