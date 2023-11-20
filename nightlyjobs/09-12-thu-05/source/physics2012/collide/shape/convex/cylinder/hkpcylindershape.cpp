// File Line: 25
// RVA: 0xD0B510
void __fastcall hkpCylinderShape::hkpCylinderShape(hkpCylinderShape *this, hkVector4f *vertexA, hkVector4f *vertexB, float cylinderRadius, float paddingRadius)
{
  float v5; // xmm1_4
  hkpCylinderShape *v6; // rbx

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  *(_DWORD *)&this->m_type.m_storage = 1025;
  this->m_userData = 0i64;
  this->m_radius = paddingRadius;
  v5 = 0.0;
  this->vfptr = (hkBaseObjectVtbl *)&hkpCylinderShape::`vftable';
  v6 = this;
  if ( hkpCylinderShape::s_intRoundUpThreshold < 0.0 )
  {
    while ( !(signed int)v5 )
    {
      v5 = v5 + 0.0099999998;
      if ( v5 >= 1.1 )
      {
        hkpCylinderShape::s_intRoundUpThreshold = 0.0;
        goto LABEL_6;
      }
    }
    hkpCylinderShape::s_intRoundUpThreshold = 1.0 - v5;
  }
LABEL_6:
  this->m_vertexA = (hkVector4f)vertexA->m_quad;
  this->m_vertexB = (hkVector4f)vertexB->m_quad;
  hkpCylinderShape::setCylinderRadius(this, cylinderRadius);
  hkpCylinderShape::presetPerpendicularVector(v6);
  v6->m_cylBaseRadiusFactorForHeightFieldCollisions = 0.80000001;
}

// File Line: 44
// RVA: 0xD0B5E0
void __fastcall hkpCylinderShape::hkpCylinderShape(hkpCylinderShape *this, hkFinishLoadedObjectFlag flag)
{
  hkpCylinderShape *v2; // rbx
  float v3; // xmm1_4
  int v4; // [rsp+38h] [rbp+10h]

  v4 = flag.m_finishing;
  v2 = this;
  hkpConvexShape::hkpConvexShape((hkpConvexShape *)&this->vfptr, flag);
  v2->vfptr = (hkBaseObjectVtbl *)&hkpCylinderShape::`vftable';
  if ( v4 )
  {
    v3 = 0.0;
    if ( hkpCylinderShape::s_intRoundUpThreshold < 0.0 )
    {
      while ( !(signed int)v3 )
      {
        v3 = v3 + 0.0099999998;
        if ( v3 >= 1.1 )
        {
          hkpCylinderShape::s_intRoundUpThreshold = 0.0;
          v2->m_type.m_storage = 1;
          return;
        }
      }
      hkpCylinderShape::s_intRoundUpThreshold = 1.0 - v3;
    }
  }
  v2->m_type.m_storage = 1;
}

// File Line: 55
// RVA: 0xD0C6B0
void __fastcall assertRoundUpThreshold(float intRoundUpThreshold)
{
  ;
}

// File Line: 67
// RVA: 0xD0C650
void __fastcall hkpCylinderShape::setNumberOfVirtualSideSegments(int numSegments)
{
  hkpCylinderShape::s_virtualTesselationParameter = (float)((float)(numSegments / 8) - 0.1) * 1.4144272;
  hkpCylinderShape::s_virtualTesselationParameterInv = 1.0
                                                     / (float)((float)((float)(numSegments / 8) - 0.1) * 1.4144272);
}

// File Line: 79
// RVA: 0xD0C4C0
void __fastcall hkpCylinderShape::presetPerpendicularVector(hkpCylinderShape *this)
{
  __m128 v1; // xmm10
  __m128 v2; // xmm1
  __m128 v3; // xmm3
  __m128 v4; // xmm2
  __m128 v5; // xmm10
  __m128 v6; // xmm6
  __m128 v7; // xmm5
  __m128 v8; // xmm6
  __m128 v9; // xmm1
  __m128 v10; // xmm4
  __m128 v11; // xmm2
  __m128 v12; // xmm4
  __m128 v13; // xmm1
  __m128 v14; // xmm2
  __m128 v15; // xmm1
  hkVector4f v16; // xmm3
  __m128 v17; // xmm3

  v1 = _mm_sub_ps(this->m_vertexB.m_quad, this->m_vertexA.m_quad);
  v2 = _mm_mul_ps(v1, v1);
  v3 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v2, v2, 85), _mm_shuffle_ps(v2, v2, 0)), _mm_shuffle_ps(v2, v2, 170));
  v4 = _mm_rsqrt_ps(v3);
  v5 = _mm_mul_ps(
         v1,
         _mm_andnot_ps(
           _mm_cmpleps(v3, (__m128)0i64),
           _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v4, v3), v4)), _mm_mul_ps(*(__m128 *)_xmm, v4))));
  v6 = _mm_shuffle_ps(v5, _mm_unpackhi_ps(v5, (__m128)0i64), 196);
  v7 = _mm_shuffle_ps(v6, v6, 241);
  v8 = _mm_shuffle_ps(v6, v6, 206);
  v9 = _mm_mul_ps(v8, v8);
  v10 = _mm_mul_ps(v7, v7);
  v11 = _mm_cmpltps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)),
            _mm_shuffle_ps(v10, v10, 170)),
          _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)), _mm_shuffle_ps(v9, v9, 170)));
  v12 = _mm_xor_ps(
          _mm_or_ps(_mm_andnot_ps(v11, v7), _mm_and_ps(v8, v11)),
          (__m128)_mm_insert_epi16((__m128i)0i64, 0x8000u, 1));
  v13 = _mm_mul_ps(v12, v12);
  v14 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)), _mm_shuffle_ps(v13, v13, 170));
  v15 = _mm_rsqrt_ps(v14);
  v16.m_quad = _mm_mul_ps(
                 _mm_andnot_ps(
                   _mm_cmpleps(v14, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v15, v14), v15)),
                     _mm_mul_ps(*(__m128 *)_xmm, v15))),
                 v12);
  this->m_perpendicular1 = (hkVector4f)v16.m_quad;
  v17 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v16.m_quad, v16.m_quad, 201), v5),
          _mm_mul_ps(_mm_shuffle_ps(v5, v5, 201), v16.m_quad));
  this->m_perpendicular2.m_quad = _mm_shuffle_ps(v17, v17, 201);
}

// File Line: 91
// RVA: 0xD0C480
float __fastcall hkpCylinderShape::getCylinderRadius(hkpCylinderShape *this)
{
  return this->m_cylRadius;
}

// File Line: 96
// RVA: 0xD0C490
void __fastcall hkpCylinderShape::setCylinderRadius(hkpCylinderShape *this, const float radius)
{
  this->m_cylRadius = radius;
  this->m_vertexA.m_quad.m128_f32[3] = radius + this->m_radius;
  this->m_vertexB.m_quad.m128_f32[3] = radius + this->m_radius;
}

// File Line: 155
// RVA: 0xD0B690
void __fastcall hkpCylinderShape::getSupportingVertex(hkpCylinderShape *this, hkVector4f *direction, hkcdVertex *supportingVertexOut)
{
  hkVector4f v3; // xmm4
  hkpCylinderShape *v4; // r9
  hkVector4f v5; // xmm8
  __m128 v6; // xmm7
  __m128 v7; // xmm1
  __m128 v8; // xmm6
  __m128 v9; // xmm1
  __m128 v10; // xmm5
  __m128 v11; // xmm2
  __m128 v12; // xmm1
  __m128 v13; // xmm2
  __m128i v14; // xmm5
  __m128 v15; // xmm6
  __m128 v16; // xmm9
  __m128 v17; // xmm2
  __m128 v18; // xmm1
  __m128 v19; // xmm3
  int v20; // xmm0_4
  float v21; // xmm0_4
  int v22; // eax
  int v23; // er10
  unsigned int v24; // ecx
  __m128 v25; // xmm3
  __m128 v26; // xmm3
  __m128 v27; // xmm10
  __m128 v28; // xmm1
  __m128 v29; // xmm5
  __m128 v30; // xmm1
  float v31; // [rsp+60h] [rbp+8h]

  v3.m_quad = (__m128)this->m_perpendicular2;
  v4 = this;
  v5.m_quad = (__m128)this->m_perpendicular1;
  v6 = _mm_sub_ps(this->m_vertexB.m_quad, this->m_vertexA.m_quad);
  v7 = _mm_mul_ps(direction->m_quad, v5.m_quad);
  v8 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps(v7, v7, 0)), _mm_shuffle_ps(v7, v7, 170));
  v9 = _mm_mul_ps(this->m_perpendicular2.m_quad, direction->m_quad);
  v10 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)), _mm_shuffle_ps(v9, v9, 170));
  v11 = _mm_add_ps(_mm_mul_ps(v10, v10), _mm_mul_ps(v8, v8));
  if ( v11.m128_f32[0] < 1.4210855e-14 )
  {
    v14 = 0i64;
    v15 = query.m_quad;
  }
  else
  {
    v12 = _mm_rsqrt_ps(v11);
    v13 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v12, v11), v12)), _mm_mul_ps(*(__m128 *)_xmm, v12));
    v14 = (__m128i)_mm_mul_ps(v10, v13);
    v15 = _mm_mul_ps(v8, v13);
  }
  v16 = _mm_mul_ps(direction->m_quad, v6);
  v17 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v14, 1u), 1u);
  v18 = (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)v15, 1u), 1u);
  v19 = _mm_cmpleps(v17, v18);
  v20 = (unsigned __int128)_mm_andnot_ps(v19, v18);
  v18.m128_i32[0] = (unsigned __int128)_mm_shuffle_ps(v16, v16, 85);
  v31 = (float)((float)(COERCE_FLOAT(v20 | v17.m128_i32[0] & v19.m128_i32[0])
                      * hkpCylinderShape::s_virtualTesselationParameter)
              - hkpCylinderShape::s_intRoundUpThreshold)
      + 0.050000001;
  LODWORD(v21) = (unsigned __int128)_mm_shuffle_ps(v16, v16, 0);
  v16.m128_i32[0] = (unsigned __int128)_mm_shuffle_ps(v16, v16, 170);
  v22 = _mm_movemask_ps(v19);
  v23 = (signed int)v31
      + 16
      * ((v22 != 0)
       + 2
       * ((v15.m128_f32[0] >= 0.0)
        + 2
        * ((*(float *)v14.m128i_i32 >= 0.0) + 2 * ((float)((float)(v18.m128_f32[0] + v21) + v16.m128_f32[0]) <= 0.0))));
  v24 = (unsigned __int16)((signed int)v31
                         + 16
                         * ((v22 != 0)
                          + 2
                          * ((v15.m128_f32[0] >= 0.0)
                           + 2
                           * ((*(float *)v14.m128i_i32 >= 0.0)
                            + 2 * ((float)((float)(v18.m128_f32[0] + v21) + v16.m128_f32[0]) <= 0.0)))));
  v25 = (__m128)COERCE_UNSIGNED_INT((float)(((unsigned __int8)(signed int)v31
                                           + 16
                                           * ((v22 != 0)
                                            + 2
                                            * ((v15.m128_f32[0] >= 0.0)
                                             + 2
                                             * ((*(float *)v14.m128i_i32 >= 0.0)
                                              + 2 * ((float)((float)(v18.m128_f32[0] + v21) + v16.m128_f32[0]) <= 0.0))))) & 0xF));
  v26 = _mm_mul_ps(
          _mm_add_ps(_mm_shuffle_ps(v25, v25, 0), (__m128)xmmword_141A711B0),
          _mm_shuffle_ps(
            (__m128)LODWORD(hkpCylinderShape::s_virtualTesselationParameterInv),
            (__m128)LODWORD(hkpCylinderShape::s_virtualTesselationParameterInv),
            0));
  v27 = _mm_sub_ps(query.m_quad, _mm_mul_ps(v26, v26));
  v28 = _mm_rsqrt_ps(v27);
  v29 = _mm_andnot_ps(
          _mm_cmpleps(v27, (__m128)0i64),
          _mm_mul_ps(
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v28, v27), v28)),
              _mm_mul_ps(*(__m128 *)_xmm, v28)),
            v27));
  if ( (v24 >> 4) & 1 )
  {
    v30 = v29;
  }
  else
  {
    v30 = v26;
    v26 = v29;
  }
  if ( !((v24 >> 6) & 1) )
    v26 = _mm_sub_ps((__m128)0i64, v26);
  if ( !((v24 >> 5) & 1) )
    v30 = _mm_sub_ps((__m128)0i64, v30);
  supportingVertexOut->m_quad = _mm_add_ps(
                                  _mm_mul_ps(
                                    _mm_add_ps(_mm_mul_ps(v3.m_quad, v26), _mm_mul_ps(v5.m_quad, v30)),
                                    _mm_shuffle_ps(
                                      (__m128)LODWORD(v4->m_cylRadius),
                                      (__m128)LODWORD(v4->m_cylRadius),
                                      0)),
                                  *(__m128 *)&(&v4->vfptr)[2 * ((signed int)(1 - ((v24 >> 7) & 1)) + 3i64)]);
  supportingVertexOut->m_quad.m128_i32[3] = v23 | 0x3F000000;
}

// File Line: 228
// RVA: 0xD0B940
void __fastcall hkpCylinderShape::convertVertexIdsToVertices(hkpCylinderShape *this, const unsigned __int16 *ids, int numIds, hkcdVertex *verticesOut)
{
  int v4; // er8
  const unsigned __int16 *i; // r11
  unsigned int v6; // edx
  __m128 v7; // xmm4
  __m128 v8; // xmm4
  __m128 v9; // xmm3
  __m128 v10; // xmm1
  __m128 v11; // xmm5
  __m128 v12; // xmm3

  v4 = numIds - 1;
  for ( i = ids; v4 >= 0; verticesOut[-1].m_quad.m128_i32[3] = v6 | 0x3F000000 )
  {
    v6 = *i;
    v7 = (__m128)COERCE_UNSIGNED_INT((float)(*i & 0xF));
    v8 = _mm_mul_ps(
           _mm_add_ps(_mm_shuffle_ps(v7, v7, 0), (__m128)xmmword_141A711B0),
           _mm_shuffle_ps(
             (__m128)LODWORD(hkpCylinderShape::s_virtualTesselationParameterInv),
             (__m128)LODWORD(hkpCylinderShape::s_virtualTesselationParameterInv),
             0));
    v9 = _mm_sub_ps(query.m_quad, _mm_mul_ps(v8, v8));
    v10 = _mm_rsqrt_ps(v9);
    v11 = _mm_andnot_ps(
            _mm_cmpleps(v9, (__m128)0i64),
            _mm_mul_ps(
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v10, v9), v10)),
                _mm_mul_ps(*(__m128 *)_xmm, v10)),
              v9));
    if ( (v6 >> 4) & 1 )
    {
      v12 = v11;
    }
    else
    {
      v12 = v8;
      v8 = v11;
    }
    if ( !(((unsigned int)*i >> 6) & 1) )
      v8 = _mm_sub_ps((__m128)0i64, v8);
    if ( !(((unsigned int)*i >> 5) & 1) )
      v12 = _mm_sub_ps((__m128)0i64, v12);
    ++verticesOut;
    ++i;
    --v4;
    verticesOut[-1].m_quad = _mm_add_ps(
                               _mm_mul_ps(
                                 _mm_add_ps(
                                   _mm_mul_ps(this->m_perpendicular1.m_quad, v12),
                                   _mm_mul_ps(this->m_perpendicular2.m_quad, v8)),
                                 _mm_shuffle_ps(
                                   (__m128)LODWORD(this->m_cylRadius),
                                   (__m128)LODWORD(this->m_cylRadius),
                                   0)),
                               *(__m128 *)&(&this->vfptr)[2 * (4i64 - ((v6 >> 7) & 1))]);
  }
}

// File Line: 238
// RVA: 0xD0BAD0
void __fastcall hkpCylinderShape::getCentre(hkpCylinderShape *this, hkVector4f *centreOut)
{
  hkVector4f v2; // xmm0

  v2.m_quad = _mm_add_ps(this->m_vertexB.m_quad, this->m_vertexA.m_quad);
  *centreOut = (hkVector4f)v2.m_quad;
  centreOut->m_quad = _mm_mul_ps(v2.m_quad, (__m128)xmmword_141A711B0);
}

// File Line: 246
// RVA: 0xD0C6A0
void __fastcall hkpCylinderShape::getFirstVertex(hkpCylinderShape *this, hkVector4f *v)
{
  *v = this->m_vertexB;
}

// File Line: 253
// RVA: 0xD0BAF0
hkSphere *__fastcall hkpCylinderShape::getCollisionSpheres(hkpCylinderShape *this, hkSphere *sphereBuffer)
{
  float v2; // xmm3_4
  hkSphere *v3; // r9
  hkpCylinderShape *v4; // r8
  __m128 v5; // xmm2
  float v6; // xmm8_4
  __m128 v7; // xmm2
  unsigned int v8; // xmm3_4
  hkVector4f v9; // xmm1
  hkVector4f v10; // xmm2
  float v11; // xmm7_4
  hkSphere *v12; // rax
  __m128i *v13; // rcx
  signed __int64 v14; // rdx
  __m128 v15; // xmm4
  __m128 v16; // xmm3
  __m128 v17; // xmm4
  __m128 v18; // xmm6
  __m128 v19; // xmm3
  __m128 v20; // xmm5
  __m128i v21; // xmm0
  __m128 v22; // xmm2
  __m128 v23; // xmm1
  float v24; // xmm7_4
  hkSphere *result; // rax
  __m128 v26; // xmm2
  __m128 v27; // xmm2
  __m128 v28; // [rsp+0h] [rbp-48h]
  float v29; // [rsp+50h] [rbp+8h]
  float v30; // [rsp+58h] [rbp+10h]
  float v31; // [rsp+60h] [rbp+18h]

  v3 = sphereBuffer;
  v4 = this;
  v29 = this->m_cylRadius;
  v2 = this->m_cylRadius;
  v5 = _mm_sub_ps(this->m_vertexB.m_quad, this->m_vertexA.m_quad);
  v6 = 0.0;
  v30 = 0.0;
  v7 = _mm_mul_ps(v5, v5);
  if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v7, v7, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v7, v7, 0)))
             + COERCE_FLOAT(_mm_shuffle_ps(v7, v7, 170))) >= (float)((float)(v2 * 4.0) * v2) )
  {
    v6 = this->m_cylRadius;
    v2 = v29 * this->m_cylBaseRadiusFactorForHeightFieldCollisions;
    v30 = this->m_cylRadius;
    v29 = v29 * this->m_cylBaseRadiusFactorForHeightFieldCollisions;
  }
  *(float *)&v8 = v2 * 0.70710677;
  v9.m_quad = (__m128)this->m_perpendicular2;
  v10.m_quad = (__m128)this->m_perpendicular1;
  v11 = this->m_radius;
  v12 = sphereBuffer + 2;
  v13 = (__m128i *)&this->m_vertexA;
  v14 = 2i64;
  v31 = *(float *)&v8;
  v15 = _mm_shuffle_ps((__m128)v8, (__m128)v8, 0);
  v16 = (__m128)LODWORD(v29);
  v17 = (__m128)_mm_srli_si128(_mm_slli_si128((__m128i)_mm_mul_ps(v15, _mm_add_ps(v9.m_quad, v10.m_quad)), 4), 4);
  v18 = (__m128)_mm_srli_si128(_mm_slli_si128((__m128i)_mm_mul_ps(_mm_shuffle_ps(v16, v16, 0), v10.m_quad), 4), 4);
  v19 = (__m128)_mm_srli_si128(_mm_slli_si128((__m128i)_mm_mul_ps(_mm_shuffle_ps(v16, v16, 0), v9.m_quad), 4), 4);
  v20 = (__m128)_mm_srli_si128(
                  _mm_slli_si128(
                    (__m128i)_mm_mul_ps(
                               _mm_shuffle_ps((__m128)LODWORD(v31), (__m128)LODWORD(v31), 0),
                               _mm_sub_ps(v10.m_quad, v9.m_quad)),
                    4),
                  4);
  do
  {
    v21 = *v13;
    v12 += 8;
    ++v13;
    _mm_store_si128((__m128i *)&v28, v21);
    v28.m128_f32[3] = v11;
    v22 = v28;
    v23 = _mm_add_ps(v28, v17);
    v12[-10].m_pos.m_quad = _mm_add_ps(v28, v18);
    v12[-9] = (hkSphere)v23;
    v12[-8].m_pos.m_quad = _mm_add_ps(v22, v19);
    v12[-7].m_pos.m_quad = _mm_sub_ps(v22, v20);
    v12[-6].m_pos.m_quad = _mm_sub_ps(v22, v18);
    v12[-5].m_pos.m_quad = _mm_sub_ps(v22, v17);
    v12[-4].m_pos.m_quad = _mm_sub_ps(v22, v19);
    v12[-3].m_pos.m_quad = _mm_add_ps(v22, v20);
    --v14;
  }
  while ( v14 );
  v24 = v11 + v6;
  result = v3;
  v26 = _mm_sub_ps(
          _mm_mul_ps(
            _mm_shuffle_ps(v4->m_perpendicular2.m_quad, v4->m_perpendicular2.m_quad, 201),
            v4->m_perpendicular1.m_quad),
          _mm_mul_ps(
            _mm_shuffle_ps(v4->m_perpendicular1.m_quad, v4->m_perpendicular1.m_quad, 201),
            v4->m_perpendicular2.m_quad));
  v27 = _mm_shuffle_ps(v26, v26, 201);
  v3[16].m_pos.m_quad = _mm_add_ps(
                          _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(v30), (__m128)LODWORD(v30), 0), v27),
                          v4->m_vertexA.m_quad);
  v3[17].m_pos.m_quad = _mm_add_ps(
                          _mm_mul_ps(
                            _mm_shuffle_ps(
                              (__m128)(unsigned int)(LODWORD(v6) ^ _xmm[0]),
                              (__m128)(unsigned int)(LODWORD(v6) ^ _xmm[0]),
                              0),
                            v27),
                          v4->m_vertexB.m_quad);
  v3[16].m_pos.m_quad.m128_f32[3] = v24;
  v3[17].m_pos.m_quad.m128_f32[3] = v24;
  return result;
}

// File Line: 318
// RVA: 0xD0BD10
void __fastcall hkpCylinderShape::getAabb(hkpCylinderShape *this, hkTransformf *localToWorld, float tolerance, hkAabb *out)
{
  hkVector4f v4; // xmm3
  hkVector4f v5; // xmm4
  hkVector4f v6; // xmm5
  __m128 *v7; // rax
  hkVector4f v8; // xmm6
  signed __int64 v9; // rdx
  float v10; // xmm7_4
  __m128 v11; // xmm1
  __m128 v12; // xmm4
  __m128 v13; // xmm1
  __m128 v14; // xmm2
  __m128 v15; // xmm1
  __m128 v16; // xmm0
  __m128 v17; // xmm4
  __m128 v18; // xmm0
  __m128 v19; // xmm3
  __m128 v20; // xmm1
  __m128 v21; // xmm1
  hkVector4f v22; // xmm0
  __m128 v23; // [rsp+0h] [rbp-48h]
  __m128 v24; // [rsp+10h] [rbp-38h]

  v4.m_quad = (__m128)localToWorld->m_rotation.m_col0;
  v5.m_quad = (__m128)localToWorld->m_rotation.m_col1;
  v6.m_quad = (__m128)localToWorld->m_rotation.m_col2;
  v7 = &this->m_vertexB.m_quad;
  v8.m_quad = (__m128)localToWorld->m_translation;
  v9 = 1i64;
  v10 = tolerance;
  do
  {
    v11 = *v7;
    --v7;
    --v9;
    *(__m128 *)((char *)v7 + (char *)&v24 - (char *)this - 48) = _mm_add_ps(
                                                                   _mm_add_ps(
                                                                     _mm_add_ps(
                                                                       _mm_mul_ps(
                                                                         _mm_shuffle_ps(v11, v11, 85),
                                                                         v5.m_quad),
                                                                       _mm_mul_ps(
                                                                         _mm_shuffle_ps(v11, v11, 0),
                                                                         v4.m_quad)),
                                                                     _mm_mul_ps(
                                                                       _mm_shuffle_ps(v11, v11, 170),
                                                                       v6.m_quad)),
                                                                   v8.m_quad);
  }
  while ( v9 >= 0 );
  v12 = _mm_sub_ps(v24, v23);
  v13 = _mm_mul_ps(v12, v12);
  v14 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)), _mm_shuffle_ps(v13, v13, 170));
  v15 = _mm_rcp_ps(v14);
  v16 = _mm_shuffle_ps(v12, v12, 201);
  v17 = _mm_shuffle_ps(v12, v12, 210);
  v18 = _mm_mul_ps(
          _mm_add_ps(_mm_mul_ps(v16, v16), _mm_mul_ps(v17, v17)),
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v15, v14)), v15));
  v19 = _mm_andnot_ps(_mm_cmpltps(v18, *(__m128 *)&epsilon), v18);
  v20 = _mm_rsqrt_ps(v19);
  v21 = _mm_add_ps(
          _mm_mul_ps(
            _mm_shuffle_ps((__m128)LODWORD(this->m_cylRadius), (__m128)LODWORD(this->m_cylRadius), 0),
            _mm_andnot_ps(
              _mm_cmpleps(v19, (__m128)0i64),
              _mm_mul_ps(
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v19, v20), v20)),
                  _mm_mul_ps(*(__m128 *)_xmm, v20)),
                v19))),
          _mm_shuffle_ps(
            (__m128)COERCE_UNSIGNED_INT(v10 + this->m_radius),
            (__m128)COERCE_UNSIGNED_INT(v10 + this->m_radius),
            0));
  v22.m_quad = _mm_sub_ps(_mm_min_ps(v23, v24), v21);
  out->m_max.m_quad = _mm_add_ps(_mm_max_ps(v23, v24), v21);
  out->m_min = (hkVector4f)v22.m_quad;
}

// File Line: 362
// RVA: 0xD0BE80
hkBool *__fastcall hkpCylinderShape::castRay(hkpCylinderShape *this, hkBool *result, hkpShapeRayCastInput *input, hkpShapeRayCastOutput *results)
{
  hkpCylinderShape *v4; // rsi
  hkpShapeRayCastOutput *v5; // rdi
  hkpShapeRayCastInput *v6; // rbp
  hkBool *v7; // rbx
  _QWORD *v8; // r9
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  signed __int64 v11; // rcx
  __m128 v12; // xmm10
  __m128 v13; // xmm6
  __m128 v14; // xmm9
  __m128 v15; // xmm5
  __m128 v16; // xmm8
  __m128 v17; // xmm1
  __m128 v18; // xmm8
  __m128 v19; // xmm3
  __m128 v20; // xmm2
  __m128 v21; // xmm5
  __m128 v22; // xmm14
  __m128 v23; // xmm10
  __m128 v24; // xmm15
  __m128 v25; // xmm7
  __m128 v26; // xmm1
  __m128 v27; // xmm3
  __m128 v28; // xmm2
  __m128 v29; // xmm15
  __m128 v30; // xmm0
  __m128 v31; // xmm6
  __m128 v32; // xmm3
  __m128 v33; // xmm1
  __m128 v34; // xmm14
  __m128 v35; // xmm2
  __m128 v36; // xmm6
  __m128i v37; // xmm3
  __m128i v38; // xmm4
  __m128i v39; // xmm6
  __m128 v40; // xmm5
  __m128 v41; // xmm1
  __m128 v42; // xmm6
  __m128 v43; // xmm12
  __m128 v44; // xmm1
  __m128 v45; // xmm10
  __m128i v46; // xmm12
  __m128 v47; // xmm3
  __m128 v48; // xmm0
  __m128 v49; // xmm7
  __m128 v50; // xmm9
  __m128 v51; // xmm0
  __m128 v52; // xmm5
  __m128 v53; // xmm2
  __m128 v54; // xmm4
  __m128 v55; // xmm3
  __m128 v56; // xmm1
  __m128 v57; // xmm6
  __m128 v58; // xmm5
  __m128 v59; // xmm1
  __m128 v60; // xmm2
  __m128 v61; // xmm11
  __m128 v62; // xmm5
  __m128 v63; // xmm2
  __m128 v64; // xmm2
  __m128 v65; // xmm4
  __m128 v66; // xmm4
  __m128 v67; // xmm2
  __m128 v68; // xmm3
  __m128 v69; // xmm1
  __m128 v70; // xmm0
  __m128 v71; // xmm2
  __m128 v72; // xmm3
  __m128 v73; // xmm4
  __m128 v74; // xmm8
  __m128 v75; // xmm1
  __m128 v76; // xmm8
  __m128 v77; // xmm1
  __m128 v78; // xmm2
  __m128 v79; // xmm1
  __m128 v80; // xmm0
  __m128 v81; // xmm10
  __m128 v82; // xmm1
  float v83; // xmm2_4
  __int64 v84; // rax
  _QWORD *v85; // r8
  unsigned __int64 v86; // rcx
  unsigned __int64 v87; // rax
  _QWORD *v88; // r8
  unsigned __int64 v89; // rcx
  unsigned __int64 v90; // rax
  __m128 v92; // [rsp+20h] [rbp-E8h]
  __m128 v93; // [rsp+30h] [rbp-D8h]
  __m128 v94; // [rsp+40h] [rbp-C8h]
  __m128 v95; // [rsp+50h] [rbp-B8h]

  v4 = this;
  v5 = results;
  v6 = input;
  v7 = result;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v8[1];
  if ( (unsigned __int64)v9 < v8[3] )
  {
    *v9 = "TtrcCylinder";
    v10 = __rdtsc();
    v11 = (signed __int64)(v9 + 2);
    *(_DWORD *)(v11 - 8) = v10;
    v8[1] = v11;
  }
  v12 = v4->m_vertexA.m_quad;
  v13 = _mm_shuffle_ps((__m128)LODWORD(v4->m_radius), (__m128)LODWORD(v4->m_radius), 0);
  v14 = _mm_add_ps(_mm_shuffle_ps((__m128)LODWORD(v4->m_cylRadius), (__m128)LODWORD(v4->m_cylRadius), 0), v13);
  v15 = _mm_sub_ps(v4->m_vertexB.m_quad, v12);
  v16 = _mm_sub_ps(v6->m_to.m_quad, v6->m_from.m_quad);
  v17 = _mm_mul_ps(v15, v15);
  v18 = _mm_shuffle_ps(v16, _mm_unpackhi_ps(v16, query.m_quad), 196);
  v19 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)), _mm_shuffle_ps(v17, v17, 170));
  v20 = _mm_rsqrt_ps(v19);
  v95 = _mm_shuffle_ps((__m128)LODWORD(v5->m_hitFraction), (__m128)LODWORD(v5->m_hitFraction), 0);
  v21 = _mm_mul_ps(
          _mm_mul_ps(
            v15,
            _mm_andnot_ps(
              _mm_cmpleps(v19, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v20, v19), v20)),
                _mm_mul_ps(v20, *(__m128 *)_xmm)))),
          v13);
  v22 = _mm_add_ps(v4->m_vertexB.m_quad, v21);
  v23 = _mm_sub_ps(v12, v21);
  v92 = v23;
  v93 = v22;
  v24 = _mm_sub_ps(v22, v23);
  v25 = _mm_sub_ps(v6->m_from.m_quad, v23);
  v26 = _mm_mul_ps(v24, v24);
  v27 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v26, v26, 85), _mm_shuffle_ps(v26, v26, 0)), _mm_shuffle_ps(v26, v26, 170));
  v28 = _mm_rsqrt_ps(v27);
  v29 = _mm_mul_ps(
          v24,
          _mm_andnot_ps(
            _mm_cmpleps(v27, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v28, v27), v28)),
              _mm_mul_ps(v28, *(__m128 *)_xmm))));
  v30 = _mm_mul_ps(_mm_sub_ps(v6->m_from.m_quad, v22), v29);
  v31 = _mm_mul_ps(v29, v25);
  v32 = _mm_mul_ps(v29, v18);
  v33 = _mm_unpacklo_ps(v31, v30);
  v34 = (__m128)xmmword_141A712A0;
  v35 = _mm_movelh_ps(v33, v32);
  v36 = _mm_add_ps(
          _mm_shuffle_ps(_mm_unpackhi_ps(v31, v30), v32, 228),
          _mm_add_ps(v35, _mm_shuffle_ps(_mm_movehl_ps(v35, v33), v32, 212)));
  v37 = (__m128i)_mm_shuffle_ps(v36, v36, 0);
  v38 = (__m128i)_mm_shuffle_ps(v36, v36, 85);
  v39 = (__m128i)_mm_shuffle_ps(v36, v36, 170);
  v40 = _mm_cmpeqps((__m128)v39, (__m128)0i64);
  v41 = _mm_rcp_ps((__m128)v39);
  v42 = _mm_or_ps(
          _mm_and_ps(_mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v39, 0x1Fu), 0x1Fu), (__m128)_xmm), v40),
          _mm_andnot_ps(v40, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v41, (__m128)v39)), v41)));
  v43 = _mm_or_ps(
          _mm_and_ps(
            _mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v37, 0x1Fu), 0x1Fu), (__m128)xmmword_141A712A0),
            v40),
          _mm_andnot_ps(v40, _mm_mul_ps(_mm_sub_ps((__m128)0i64, (__m128)v37), v42)));
  v44 = _mm_or_ps(
          _mm_and_ps(
            _mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v38, 0x1Fu), 0x1Fu), (__m128)xmmword_141A712A0),
            v40),
          _mm_andnot_ps(v40, _mm_mul_ps(_mm_sub_ps((__m128)0i64, (__m128)v38), v42)));
  v45 = _mm_min_ps(v43, v44);
  v94 = _mm_max_ps(v43, v44);
  if ( v45.m128_f32[0] == v94.m128_f32[0] )
    goto LABEL_13;
  v46 = (__m128i)_mm_cmpltps(v43, v44);
  v47 = v25;
  v48 = v25;
  v49 = _mm_mul_ps(v25, v25);
  v50 = _mm_mul_ps(v14, v14);
  v51 = _mm_mul_ps(v48, v29);
  v52 = _mm_mul_ps(v18, v18);
  v53 = _mm_mul_ps(v29, v18);
  v54 = _mm_shuffle_ps(v52, v53, 68);
  v55 = _mm_mul_ps(v47, v18);
  v56 = _mm_shuffle_ps(v55, v51, 68);
  v57 = _mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v46, 0x1Fu), 0x1Fu), v29);
  v58 = _mm_add_ps(
          _mm_shuffle_ps(_mm_shuffle_ps(v52, v53, 238), _mm_shuffle_ps(v55, v51, 238), 136),
          _mm_add_ps(_mm_shuffle_ps(v54, v56, 221), _mm_shuffle_ps(v54, v56, 136)));
  v59 = _mm_shuffle_ps(v58, v58, 85);
  v60 = _mm_shuffle_ps(v58, v58, 255);
  v61 = _mm_sub_ps(_mm_shuffle_ps(v58, v58, 0), _mm_mul_ps(v59, v59));
  v62 = _mm_sub_ps(_mm_shuffle_ps(v58, v58, 170), _mm_mul_ps(v60, v59));
  if ( v61.m128_f32[0] >= 0.00000011920929 )
  {
    v66 = _mm_sub_ps(
            _mm_mul_ps(v62, v62),
            _mm_mul_ps(
              _mm_sub_ps(
                _mm_sub_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v49, v49, 85), _mm_shuffle_ps(v49, v49, 0)),
                    _mm_shuffle_ps(v49, v49, 170)),
                  _mm_mul_ps(v60, v60)),
                v50),
              v61));
    if ( v66.m128_f32[0] < 0.0 )
      goto LABEL_13;
    v67 = _mm_rsqrt_ps(v66);
    v68 = _mm_andnot_ps(
            _mm_cmpleps(v66, (__m128)0i64),
            _mm_mul_ps(
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v67, v66), v67)),
                _mm_mul_ps(v67, *(__m128 *)_xmm)),
              v66));
    v69 = _mm_rcp_ps(v61);
    v70 = v68;
    v71 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v69, v61)), v69);
    v72 = _mm_mul_ps(_mm_sub_ps(v68, v62), v71);
    v73 = _mm_mul_ps(_mm_sub_ps((__m128)0i64, _mm_add_ps(v70, v62)), v71);
    v34 = _mm_max_ps(v73, v72);
    v65 = _mm_min_ps(v73, v72);
    v74 = _mm_sub_ps(_mm_add_ps(_mm_mul_ps(v18, v65), v6->m_from.m_quad), v92);
    v75 = _mm_mul_ps(v29, v74);
    v76 = _mm_sub_ps(
            v74,
            _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v75, v75, 85), _mm_shuffle_ps(v75, v75, 0)),
                _mm_shuffle_ps(v75, v75, 170)),
              v29));
    v77 = _mm_mul_ps(v76, v76);
    v78 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v77, v77, 85), _mm_shuffle_ps(v77, v77, 0)),
            _mm_shuffle_ps(v77, v77, 170));
    v79 = _mm_rsqrt_ps(v78);
    v80 = _mm_cmpltps(v65, v45);
    v57 = _mm_or_ps(
            _mm_andnot_ps(
              v80,
              _mm_mul_ps(
                _mm_andnot_ps(
                  _mm_cmpleps(v78, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v79, v78), v79)),
                    _mm_mul_ps(v79, *(__m128 *)_xmm))),
                v76)),
            _mm_and_ps(v80, v57));
  }
  else
  {
    v63 = _mm_sub_ps(
            _mm_add_ps(_mm_mul_ps(v45, v18), v6->m_from.m_quad),
            _mm_or_ps(_mm_andnot_ps((__m128)v46, v93), _mm_and_ps((__m128)v46, v92)));
    v64 = _mm_mul_ps(v63, v63);
    if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v64, v64, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v64, v64, 0)))
               + COERCE_FLOAT(_mm_shuffle_ps(v64, v64, 170))) > v50.m128_f32[0] )
      goto LABEL_13;
    v65 = (__m128)xmmword_141A712F0;
  }
  v81 = _mm_max_ps(v45, v65);
  v82 = _mm_and_ps(
          _mm_and_ps(_mm_cmpleps(v81, _mm_min_ps(v94, v34)), _mm_cmpleps((__m128)0i64, v81)),
          _mm_cmpltps(v81, v95));
  LODWORD(v83) = *(unsigned __int128 *)&_mm_andnot_ps(v82, v95) | v82.m128_i32[0] & v81.m128_i32[0];
  if ( _mm_movemask_ps(v82) )
  {
    v84 = v5->m_shapeKeyIndex;
    v5->m_hitFraction = v83;
    v5->m_normal.m_quad = v57;
    v5->m_shapeKeys[v84] = -1;
    v85 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v86 = v85[1];
    if ( v86 < v85[3] )
    {
      *(_QWORD *)v86 = "Et";
      v87 = __rdtsc();
      *(_DWORD *)(v86 + 8) = v87;
      v85[1] = v86 + 16;
    }
    v7->m_bool = 1;
    return v7;
  }
LABEL_13:
  v88 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v89 = v88[1];
  if ( v89 < v88[3] )
  {
    *(_QWORD *)v89 = "Et";
    v90 = __rdtsc();
    *(_DWORD *)(v89 + 8) = v90;
    v88[1] = v89 + 16;
  }
  v7->m_bool = 0;
  return v7;
}

