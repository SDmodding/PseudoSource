// File Line: 25
// RVA: 0xD0B510
void __fastcall hkpCylinderShape::hkpCylinderShape(
        hkpCylinderShape *this,
        hkVector4f *vertexA,
        hkVector4f *vertexB,
        float cylinderRadius,
        float paddingRadius)
{
  float v5; // xmm1_4

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  *(_DWORD *)&this->m_type.m_storage = 1025;
  this->m_userData = 0i64;
  this->m_radius = paddingRadius;
  v5 = 0.0;
  this->vfptr = (hkBaseObjectVtbl *)&hkpCylinderShape::`vftable;
  if ( hkpCylinderShape::s_intRoundUpThreshold < 0.0 )
  {
    while ( !(int)v5 )
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
  hkpCylinderShape::presetPerpendicularVector(this);
  this->m_cylBaseRadiusFactorForHeightFieldCollisions = 0.80000001;
}

// File Line: 44
// RVA: 0xD0B5E0
void __fastcall hkpCylinderShape::hkpCylinderShape(hkpCylinderShape *this, hkFinishLoadedObjectFlag flag)
{
  float v3; // xmm1_4

  hkpConvexShape::hkpConvexShape(this, flag);
  this->vfptr = (hkBaseObjectVtbl *)&hkpCylinderShape::`vftable;
  if ( flag.m_finishing )
  {
    v3 = 0.0;
    if ( hkpCylinderShape::s_intRoundUpThreshold < 0.0 )
    {
      while ( !(int)v3 )
      {
        v3 = v3 + 0.0099999998;
        if ( v3 >= 1.1 )
        {
          hkpCylinderShape::s_intRoundUpThreshold = 0.0;
          this->m_type.m_storage = 1;
          return;
        }
      }
      hkpCylinderShape::s_intRoundUpThreshold = 1.0 - v3;
    }
  }
  this->m_type.m_storage = 1;
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
  hkpCylinderShape::s_virtualTesselationParameterInv = 1.0 / hkpCylinderShape::s_virtualTesselationParameter;
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
           _mm_cmple_ps(v3, (__m128)0i64),
           _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v4, v3), v4)), _mm_mul_ps(*(__m128 *)_xmm, v4))));
  v6 = _mm_shuffle_ps(v5, _mm_unpackhi_ps(v5, (__m128)0i64), 196);
  v7 = _mm_shuffle_ps(v6, v6, 241);
  v8 = _mm_shuffle_ps(v6, v6, 206);
  v9 = _mm_mul_ps(v8, v8);
  v10 = _mm_mul_ps(v7, v7);
  v11 = _mm_cmplt_ps(
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
                   _mm_cmple_ps(v14, (__m128)0i64),
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
void __fastcall hkpCylinderShape::setCylinderRadius(hkpCylinderShape *this, float radius)
{
  this->m_cylRadius = radius;
  this->m_vertexA.m_quad.m128_f32[3] = radius + this->m_radius;
  this->m_vertexB.m_quad.m128_f32[3] = radius + this->m_radius;
}

// File Line: 155
// RVA: 0xD0B690
void __fastcall hkpCylinderShape::getSupportingVertex(
        hkpCylinderShape *this,
        hkVector4f *direction,
        hkcdVertex *supportingVertexOut)
{
  hkVector4f v3; // xmm4
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
  __m128 m_quad; // xmm6
  __m128 v16; // xmm9
  __m128 v17; // xmm2
  __m128 v18; // xmm1
  __m128 v19; // xmm3
  float v20; // xmm0_4
  float v21; // xmm0_4
  int v22; // eax
  int v23; // r10d
  unsigned int v24; // ecx
  __m128 v25; // xmm3
  __m128 v26; // xmm3
  __m128 v27; // xmm10
  __m128 v28; // xmm1
  __m128 v29; // xmm5
  __m128 v30; // xmm1
  float v31; // [rsp+60h] [rbp+8h]

  v3.m_quad = (__m128)this->m_perpendicular2;
  v5.m_quad = (__m128)this->m_perpendicular1;
  v6 = _mm_sub_ps(this->m_vertexB.m_quad, this->m_vertexA.m_quad);
  v7 = _mm_mul_ps(direction->m_quad, v5.m_quad);
  v8 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps(v7, v7, 0)), _mm_shuffle_ps(v7, v7, 170));
  v9 = _mm_mul_ps(v3.m_quad, direction->m_quad);
  v10 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)), _mm_shuffle_ps(v9, v9, 170));
  v11 = _mm_add_ps(_mm_mul_ps(v10, v10), _mm_mul_ps(v8, v8));
  if ( v11.m128_f32[0] < 1.4210855e-14 )
  {
    v14 = 0i64;
    m_quad = query.m_quad;
  }
  else
  {
    v12 = _mm_rsqrt_ps(v11);
    v13 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v12, v11), v12)), _mm_mul_ps(*(__m128 *)_xmm, v12));
    v14 = (__m128i)_mm_mul_ps(v10, v13);
    m_quad = _mm_mul_ps(v8, v13);
  }
  v16 = _mm_mul_ps(direction->m_quad, v6);
  v17 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v14, 1u), 1u);
  v18 = (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)m_quad, 1u), 1u);
  v19 = _mm_cmple_ps(v17, v18);
  v20 = _mm_andnot_ps(v19, v18).m128_f32[0];
  v18.m128_f32[0] = _mm_shuffle_ps(v16, v16, 85).m128_f32[0];
  v31 = (float)((float)(COERCE_FLOAT(LODWORD(v20) | v17.m128_i32[0] & v19.m128_i32[0])
                      * hkpCylinderShape::s_virtualTesselationParameter)
              - hkpCylinderShape::s_intRoundUpThreshold)
      + 0.050000001;
  v21 = _mm_shuffle_ps(v16, v16, 0).m128_f32[0];
  v16.m128_f32[0] = _mm_shuffle_ps(v16, v16, 170).m128_f32[0];
  v22 = _mm_movemask_ps(v19);
  v23 = (int)v31
      + 16
      * ((v22 != 0)
       + 2
       * ((m_quad.m128_f32[0] >= 0.0)
        + 2
        * ((*(float *)v14.m128i_i32 >= 0.0) + 2 * ((float)((float)(v18.m128_f32[0] + v21) + v16.m128_f32[0]) <= 0.0))));
  v24 = (unsigned __int16)((int)v31
                         + 16
                         * ((v22 != 0)
                          + 2
                          * ((m_quad.m128_f32[0] >= 0.0)
                           + 2
                           * ((*(float *)v14.m128i_i32 >= 0.0)
                            + 2 * ((float)((float)(v18.m128_f32[0] + v21) + v16.m128_f32[0]) <= 0.0)))));
  v25 = (__m128)COERCE_UNSIGNED_INT((float)(((unsigned __int8)(int)v31
                                           + 16
                                           * ((v22 != 0)
                                            + 2
                                            * ((m_quad.m128_f32[0] >= 0.0)
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
          _mm_cmple_ps(v27, (__m128)0i64),
          _mm_mul_ps(
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v28, v27), v28)),
              _mm_mul_ps(*(__m128 *)_xmm, v28)),
            v27));
  if ( ((v24 >> 4) & 1) != 0 )
  {
    v30 = v29;
  }
  else
  {
    v30 = v26;
    v26 = v29;
  }
  if ( ((v24 >> 6) & 1) == 0 )
    v26 = _mm_sub_ps((__m128)0i64, v26);
  if ( ((v24 >> 5) & 1) == 0 )
    v30 = _mm_sub_ps((__m128)0i64, v30);
  supportingVertexOut->m_quad = _mm_add_ps(
                                  _mm_mul_ps(
                                    _mm_add_ps(_mm_mul_ps(v3.m_quad, v26), _mm_mul_ps(v5.m_quad, v30)),
                                    _mm_shuffle_ps(
                                      (__m128)LODWORD(this->m_cylRadius),
                                      (__m128)LODWORD(this->m_cylRadius),
                                      0)),
                                  *(&this->m_vertexA.m_quad + (int)(1 - ((v24 >> 7) & 1))));
  supportingVertexOut->m_quad.m128_i32[3] = v23 | 0x3F000000;
}

// File Line: 228
// RVA: 0xD0B940
void __fastcall hkpCylinderShape::convertVertexIdsToVertices(
        hkpCylinderShape *this,
        const unsigned __int16 *ids,
        int numIds,
        hkcdVertex *verticesOut)
{
  int i; // r8d
  unsigned int v6; // edx
  __m128 v7; // xmm4
  __m128 v8; // xmm4
  __m128 v9; // xmm3
  __m128 v10; // xmm1
  __m128 v11; // xmm5
  __m128 v12; // xmm3

  for ( i = numIds - 1; i >= 0; verticesOut[-1].m_quad.m128_i32[3] = v6 | 0x3F000000 )
  {
    v6 = *ids;
    v7 = (__m128)COERCE_UNSIGNED_INT((float)(*ids & 0xF));
    v8 = _mm_mul_ps(
           _mm_add_ps(_mm_shuffle_ps(v7, v7, 0), (__m128)xmmword_141A711B0),
           _mm_shuffle_ps(
             (__m128)LODWORD(hkpCylinderShape::s_virtualTesselationParameterInv),
             (__m128)LODWORD(hkpCylinderShape::s_virtualTesselationParameterInv),
             0));
    v9 = _mm_sub_ps(query.m_quad, _mm_mul_ps(v8, v8));
    v10 = _mm_rsqrt_ps(v9);
    v11 = _mm_andnot_ps(
            _mm_cmple_ps(v9, (__m128)0i64),
            _mm_mul_ps(
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v10, v9), v10)),
                _mm_mul_ps(*(__m128 *)_xmm, v10)),
              v9));
    if ( ((v6 >> 4) & 1) != 0 )
    {
      v12 = v11;
    }
    else
    {
      v12 = v8;
      v8 = v11;
    }
    if ( ((v6 >> 6) & 1) == 0 )
      v8 = _mm_sub_ps((__m128)0i64, v8);
    if ( ((v6 >> 5) & 1) == 0 )
      v12 = _mm_sub_ps((__m128)0i64, v12);
    ++verticesOut;
    ++ids;
    --i;
    verticesOut[-1].m_quad = _mm_add_ps(
                               _mm_mul_ps(
                                 _mm_add_ps(
                                   _mm_mul_ps(this->m_perpendicular1.m_quad, v12),
                                   _mm_mul_ps(this->m_perpendicular2.m_quad, v8)),
                                 _mm_shuffle_ps(
                                   (__m128)LODWORD(this->m_cylRadius),
                                   (__m128)LODWORD(this->m_cylRadius),
                                   0)),
                               *((__m128 *)&this->hkReferencedObject + 4i64 - ((v6 >> 7) & 1)));
  }
}

// File Line: 238
// RVA: 0xD0BAD0
void __fastcall hkpCylinderShape::getCentre(hkpCylinderShape *this, hkVector4f *centreOut)
{
  __m128 v2; // xmm0

  v2 = _mm_add_ps(this->m_vertexB.m_quad, this->m_vertexA.m_quad);
  *centreOut = (hkVector4f)v2;
  centreOut->m_quad = _mm_mul_ps(v2, (__m128)xmmword_141A711B0);
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
  __m128 v5; // xmm2
  float v6; // xmm8_4
  __m128 v7; // xmm2
  hkVector4f v8; // xmm1
  hkVector4f v9; // xmm2
  float m_radius; // xmm7_4
  hkSphere *v11; // rax
  hkVector4f *p_m_vertexA; // rcx
  __int64 v13; // rdx
  __m128 v14; // xmm4
  __m128 v15; // xmm5
  __m128 v16; // xmm3
  __m128 v17; // xmm4
  __m128 v18; // xmm6
  __m128 v19; // xmm3
  __m128 v20; // xmm5
  __m128 m_quad; // xmm0
  float v22; // xmm7_4
  hkSphere *result; // rax
  __m128 v24; // xmm2
  __m128 v25; // xmm2
  __m128 v26; // [rsp+0h] [rbp-48h]
  float m_cylRadius; // [rsp+50h] [rbp+8h]
  float v28; // [rsp+58h] [rbp+10h]

  m_cylRadius = this->m_cylRadius;
  v2 = m_cylRadius;
  v5 = _mm_sub_ps(this->m_vertexB.m_quad, this->m_vertexA.m_quad);
  v6 = 0.0;
  v28 = 0.0;
  v7 = _mm_mul_ps(v5, v5);
  if ( (float)((float)(_mm_shuffle_ps(v7, v7, 85).m128_f32[0] + _mm_shuffle_ps(v7, v7, 0).m128_f32[0])
             + _mm_shuffle_ps(v7, v7, 170).m128_f32[0]) >= (float)((float)(v2 * 4.0) * v2) )
  {
    v6 = this->m_cylRadius;
    v2 = m_cylRadius * this->m_cylBaseRadiusFactorForHeightFieldCollisions;
    v28 = v6;
    m_cylRadius = v2;
  }
  v8.m_quad = (__m128)this->m_perpendicular2;
  v9.m_quad = (__m128)this->m_perpendicular1;
  m_radius = this->m_radius;
  v11 = sphereBuffer + 2;
  p_m_vertexA = &this->m_vertexA;
  v13 = 2i64;
  v14 = _mm_shuffle_ps((__m128)COERCE_UNSIGNED_INT(v2 * 0.70710677), (__m128)COERCE_UNSIGNED_INT(v2 * 0.70710677), 0);
  v15 = v14;
  v16 = _mm_shuffle_ps((__m128)LODWORD(m_cylRadius), (__m128)LODWORD(m_cylRadius), 0);
  v17 = (__m128)_mm_srli_si128(_mm_slli_si128((__m128i)_mm_mul_ps(v14, _mm_add_ps(v8.m_quad, v9.m_quad)), 4), 4);
  v18 = (__m128)_mm_srli_si128(_mm_slli_si128((__m128i)_mm_mul_ps(v16, v9.m_quad), 4), 4);
  v19 = (__m128)_mm_srli_si128(_mm_slli_si128((__m128i)_mm_mul_ps(v16, v8.m_quad), 4), 4);
  v20 = (__m128)_mm_srli_si128(_mm_slli_si128((__m128i)_mm_mul_ps(v15, _mm_sub_ps(v9.m_quad, v8.m_quad)), 4), 4);
  do
  {
    m_quad = p_m_vertexA->m_quad;
    v11 += 8;
    ++p_m_vertexA;
    v26 = m_quad;
    v26.m128_f32[3] = m_radius;
    v11[-10].m_pos.m_quad = _mm_add_ps(v26, v18);
    v11[-9].m_pos.m_quad = _mm_add_ps(v26, v17);
    v11[-8].m_pos.m_quad = _mm_add_ps(v26, v19);
    v11[-7].m_pos.m_quad = _mm_sub_ps(v26, v20);
    v11[-6].m_pos.m_quad = _mm_sub_ps(v26, v18);
    v11[-5].m_pos.m_quad = _mm_sub_ps(v26, v17);
    v11[-4].m_pos.m_quad = _mm_sub_ps(v26, v19);
    v11[-3].m_pos.m_quad = _mm_add_ps(v26, v20);
    --v13;
  }
  while ( v13 );
  v22 = m_radius + v6;
  result = sphereBuffer;
  v24 = _mm_sub_ps(
          _mm_mul_ps(
            _mm_shuffle_ps(this->m_perpendicular2.m_quad, this->m_perpendicular2.m_quad, 201),
            this->m_perpendicular1.m_quad),
          _mm_mul_ps(
            _mm_shuffle_ps(this->m_perpendicular1.m_quad, this->m_perpendicular1.m_quad, 201),
            this->m_perpendicular2.m_quad));
  v25 = _mm_shuffle_ps(v24, v24, 201);
  sphereBuffer[16].m_pos.m_quad = _mm_add_ps(
                                    _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(v28), (__m128)LODWORD(v28), 0), v25),
                                    this->m_vertexA.m_quad);
  sphereBuffer[17].m_pos.m_quad = _mm_add_ps(
                                    _mm_mul_ps(
                                      _mm_shuffle_ps(
                                        (__m128)(unsigned int)(LODWORD(v6) ^ _xmm[0]),
                                        (__m128)(unsigned int)(LODWORD(v6) ^ _xmm[0]),
                                        0),
                                      v25),
                                    this->m_vertexB.m_quad);
  sphereBuffer[16].m_pos.m_quad.m128_f32[3] = v22;
  sphereBuffer[17].m_pos.m_quad.m128_f32[3] = v22;
  return result;
}

// File Line: 318
// RVA: 0xD0BD10
void __fastcall hkpCylinderShape::getAabb(
        hkpCylinderShape *this,
        hkTransformf *localToWorld,
        float tolerance,
        hkAabb *out)
{
  hkVector4f v4; // xmm3
  hkVector4f v5; // xmm4
  hkVector4f v6; // xmm5
  hkVector4f *p_m_vertexB; // rax
  hkVector4f v8; // xmm6
  __int64 i; // rdx
  __m128 m_quad; // xmm1
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
  __m128 v24; // [rsp+10h] [rbp-38h] BYREF

  v4.m_quad = (__m128)localToWorld->m_rotation.m_col0;
  v5.m_quad = (__m128)localToWorld->m_rotation.m_col1;
  v6.m_quad = (__m128)localToWorld->m_rotation.m_col2;
  p_m_vertexB = &this->m_vertexB;
  v8.m_quad = (__m128)localToWorld->m_translation;
  for ( i = 1i64; i >= 0; --i )
  {
    m_quad = p_m_vertexB->m_quad;
    --p_m_vertexB;
    *(__m128 *)((char *)&p_m_vertexB[-3].m_quad + (char *)&v24 - (char *)this) = _mm_add_ps(
                                                                                   _mm_add_ps(
                                                                                     _mm_add_ps(
                                                                                       _mm_mul_ps(
                                                                                         _mm_shuffle_ps(
                                                                                           m_quad,
                                                                                           m_quad,
                                                                                           85),
                                                                                         v5.m_quad),
                                                                                       _mm_mul_ps(
                                                                                         _mm_shuffle_ps(
                                                                                           m_quad,
                                                                                           m_quad,
                                                                                           0),
                                                                                         v4.m_quad)),
                                                                                     _mm_mul_ps(
                                                                                       _mm_shuffle_ps(
                                                                                         m_quad,
                                                                                         m_quad,
                                                                                         170),
                                                                                       v6.m_quad)),
                                                                                   v8.m_quad);
  }
  v12 = _mm_sub_ps(v24, v23);
  v13 = _mm_mul_ps(v12, v12);
  v14 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)), _mm_shuffle_ps(v13, v13, 170));
  v15 = _mm_rcp_ps(v14);
  v16 = _mm_shuffle_ps(v12, v12, 201);
  v17 = _mm_shuffle_ps(v12, v12, 210);
  v18 = _mm_mul_ps(
          _mm_add_ps(_mm_mul_ps(v16, v16), _mm_mul_ps(v17, v17)),
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v15, v14)), v15));
  v19 = _mm_andnot_ps(_mm_cmplt_ps(v18, *(__m128 *)&epsilon), v18);
  v20 = _mm_rsqrt_ps(v19);
  v21 = _mm_add_ps(
          _mm_mul_ps(
            _mm_shuffle_ps((__m128)LODWORD(this->m_cylRadius), (__m128)LODWORD(this->m_cylRadius), 0),
            _mm_andnot_ps(
              _mm_cmple_ps(v19, (__m128)0i64),
              _mm_mul_ps(
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v19, v20), v20)),
                  _mm_mul_ps(*(__m128 *)_xmm, v20)),
                v19))),
          _mm_shuffle_ps(
            (__m128)COERCE_UNSIGNED_INT(tolerance + this->m_radius),
            (__m128)COERCE_UNSIGNED_INT(tolerance + this->m_radius),
            0));
  v22.m_quad = _mm_sub_ps(_mm_min_ps(v23, v24), v21);
  out->m_max.m_quad = _mm_add_ps(_mm_max_ps(v23, v24), v21);
  out->m_min = (hkVector4f)v22.m_quad;
}

// File Line: 362
// RVA: 0xD0BE80
hkBool *__fastcall hkpCylinderShape::castRay(
        hkpCylinderShape *this,
        hkBool *result,
        hkpShapeRayCastInput *input,
        hkpShapeRayCastOutput *results)
{
  _QWORD *Value; // r9
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  _QWORD *v11; // rcx
  hkVector4f v12; // xmm10
  __m128 v13; // xmm6
  __m128 v14; // xmm9
  __m128 v15; // xmm5
  __m128 v16; // xmm8
  __m128 v17; // xmm1
  __m128 v18; // xmm8
  __m128 v19; // xmm3
  __m128 v20; // xmm2
  __m128 v21; // xmm5
  __m128 v22; // xmm15
  __m128 v23; // xmm7
  __m128 v24; // xmm1
  __m128 v25; // xmm3
  __m128 v26; // xmm2
  __m128 v27; // xmm15
  __m128 v28; // xmm0
  __m128 v29; // xmm6
  __m128 v30; // xmm3
  __m128 v31; // xmm1
  __m128 v32; // xmm14
  __m128 v33; // xmm2
  __m128 v34; // xmm6
  __m128i v35; // xmm3
  __m128i v36; // xmm4
  __m128i v37; // xmm6
  __m128 v38; // xmm5
  __m128 v39; // xmm1
  __m128 v40; // xmm6
  __m128 v41; // xmm12
  __m128 v42; // xmm1
  __m128 v43; // xmm10
  __m128i v44; // xmm12
  __m128 v45; // xmm3
  __m128 v46; // xmm0
  __m128 v47; // xmm7
  __m128 v48; // xmm9
  __m128 v49; // xmm0
  __m128 v50; // xmm2
  __m128 v51; // xmm4
  __m128 v52; // xmm5
  __m128 v53; // xmm4
  __m128 v54; // xmm3
  __m128 v55; // xmm1
  hkVector4f v56; // xmm6
  __m128 v57; // xmm5
  __m128 v58; // xmm1
  __m128 v59; // xmm2
  __m128 v60; // xmm11
  __m128 v61; // xmm5
  __m128 v62; // xmm2
  __m128 v63; // xmm2
  __m128 v64; // xmm4
  __m128 v65; // xmm4
  __m128 v66; // xmm2
  __m128 v67; // xmm1
  __m128 v68; // xmm0
  __m128 v69; // xmm2
  __m128 v70; // xmm3
  __m128 v71; // xmm4
  __m128 v72; // xmm8
  __m128 v73; // xmm1
  __m128 v74; // xmm8
  __m128 v75; // xmm1
  __m128 v76; // xmm2
  __m128 v77; // xmm1
  __m128 v78; // xmm7
  __m128 v79; // xmm1
  __m128 v80; // xmm10
  __m128 v81; // xmm1
  float v82; // xmm2_4
  __int64 m_shapeKeyIndex; // rax
  _QWORD *v84; // r8
  unsigned __int64 v85; // rcx
  unsigned __int64 v86; // rax
  _QWORD *v87; // r8
  unsigned __int64 v88; // rcx
  unsigned __int64 v89; // rax
  __m128 v91; // [rsp+20h] [rbp-E8h]
  __m128 v92; // [rsp+30h] [rbp-D8h]
  __m128 v93; // [rsp+40h] [rbp-C8h]
  __m128 v94; // [rsp+50h] [rbp-B8h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v9 < Value[3] )
  {
    *v9 = "TtrcCylinder";
    v10 = __rdtsc();
    v11 = v9 + 2;
    *((_DWORD *)v11 - 2) = v10;
    Value[1] = v11;
  }
  v12.m_quad = (__m128)this->m_vertexA;
  v13 = _mm_shuffle_ps((__m128)LODWORD(this->m_radius), (__m128)LODWORD(this->m_radius), 0);
  v14 = _mm_add_ps(_mm_shuffle_ps((__m128)LODWORD(this->m_cylRadius), (__m128)LODWORD(this->m_cylRadius), 0), v13);
  v15 = _mm_sub_ps(this->m_vertexB.m_quad, v12.m_quad);
  v16 = _mm_sub_ps(input->m_to.m_quad, input->m_from.m_quad);
  v17 = _mm_mul_ps(v15, v15);
  v18 = _mm_shuffle_ps(v16, _mm_unpackhi_ps(v16, query.m_quad), 196);
  v19 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)), _mm_shuffle_ps(v17, v17, 170));
  v20 = _mm_rsqrt_ps(v19);
  v94 = _mm_shuffle_ps((__m128)LODWORD(results->m_hitFraction), (__m128)LODWORD(results->m_hitFraction), 0);
  v21 = _mm_mul_ps(
          _mm_mul_ps(
            v15,
            _mm_andnot_ps(
              _mm_cmple_ps(v19, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v20, v19), v20)),
                _mm_mul_ps(v20, *(__m128 *)_xmm)))),
          v13);
  v91 = _mm_sub_ps(v12.m_quad, v21);
  v92 = _mm_add_ps(this->m_vertexB.m_quad, v21);
  v22 = _mm_sub_ps(v92, v91);
  v23 = _mm_sub_ps(input->m_from.m_quad, v91);
  v24 = _mm_mul_ps(v22, v22);
  v25 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)), _mm_shuffle_ps(v24, v24, 170));
  v26 = _mm_rsqrt_ps(v25);
  v27 = _mm_mul_ps(
          v22,
          _mm_andnot_ps(
            _mm_cmple_ps(v25, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v26, v25), v26)),
              _mm_mul_ps(v26, *(__m128 *)_xmm))));
  v28 = _mm_mul_ps(_mm_sub_ps(input->m_from.m_quad, v92), v27);
  v29 = _mm_mul_ps(v27, v23);
  v30 = _mm_mul_ps(v27, v18);
  v31 = _mm_unpacklo_ps(v29, v28);
  v32 = (__m128)xmmword_141A712A0;
  v33 = _mm_movelh_ps(v31, v30);
  v34 = _mm_add_ps(
          _mm_shuffle_ps(_mm_unpackhi_ps(v29, v28), v30, 228),
          _mm_add_ps(v33, _mm_shuffle_ps(_mm_movehl_ps(v33, v31), v30, 212)));
  v35 = (__m128i)_mm_shuffle_ps(v34, v34, 0);
  v36 = (__m128i)_mm_shuffle_ps(v34, v34, 85);
  v37 = (__m128i)_mm_shuffle_ps(v34, v34, 170);
  v38 = _mm_cmpeq_ps((__m128)v37, (__m128)0i64);
  v39 = _mm_rcp_ps((__m128)v37);
  v40 = _mm_or_ps(
          _mm_and_ps(_mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v37, 0x1Fu), 0x1Fu), (__m128)_xmm), v38),
          _mm_andnot_ps(v38, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v39, (__m128)v37)), v39)));
  v41 = _mm_or_ps(
          _mm_and_ps(
            _mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v35, 0x1Fu), 0x1Fu), (__m128)xmmword_141A712A0),
            v38),
          _mm_andnot_ps(v38, _mm_mul_ps(_mm_sub_ps((__m128)0i64, (__m128)v35), v40)));
  v42 = _mm_or_ps(
          _mm_and_ps(
            _mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v36, 0x1Fu), 0x1Fu), (__m128)xmmword_141A712A0),
            v38),
          _mm_andnot_ps(v38, _mm_mul_ps(_mm_sub_ps((__m128)0i64, (__m128)v36), v40)));
  v43 = _mm_min_ps(v41, v42);
  v93 = _mm_max_ps(v41, v42);
  if ( v43.m128_f32[0] == v93.m128_f32[0] )
    goto LABEL_13;
  v44 = (__m128i)_mm_cmplt_ps(v41, v42);
  v45 = v23;
  v46 = v23;
  v47 = _mm_mul_ps(v23, v23);
  v48 = _mm_mul_ps(v14, v14);
  v49 = _mm_mul_ps(v46, v27);
  v50 = _mm_mul_ps(v27, v18);
  v51 = _mm_mul_ps(v18, v18);
  v52 = _mm_shuffle_ps(v51, v50, 238);
  v53 = _mm_shuffle_ps(v51, v50, 68);
  v54 = _mm_mul_ps(v45, v18);
  v55 = _mm_shuffle_ps(v54, v49, 68);
  v56.m_quad = _mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v44, 0x1Fu), 0x1Fu), v27);
  v57 = _mm_add_ps(
          _mm_shuffle_ps(v52, _mm_shuffle_ps(v54, v49, 238), 136),
          _mm_add_ps(_mm_shuffle_ps(v53, v55, 221), _mm_shuffle_ps(v53, v55, 136)));
  v58 = _mm_shuffle_ps(v57, v57, 85);
  v59 = _mm_shuffle_ps(v57, v57, 255);
  v60 = _mm_sub_ps(_mm_shuffle_ps(v57, v57, 0), _mm_mul_ps(v58, v58));
  v61 = _mm_sub_ps(_mm_shuffle_ps(v57, v57, 170), _mm_mul_ps(v59, v58));
  if ( v60.m128_f32[0] >= 0.00000011920929 )
  {
    v65 = _mm_sub_ps(
            _mm_mul_ps(v61, v61),
            _mm_mul_ps(
              _mm_sub_ps(
                _mm_sub_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v47, v47, 85), _mm_shuffle_ps(v47, v47, 0)),
                    _mm_shuffle_ps(v47, v47, 170)),
                  _mm_mul_ps(v59, v59)),
                v48),
              v60));
    if ( v65.m128_f32[0] < 0.0 )
      goto LABEL_13;
    v66 = _mm_rsqrt_ps(v65);
    v67 = _mm_rcp_ps(v60);
    v68 = _mm_andnot_ps(
            _mm_cmple_ps(v65, (__m128)0i64),
            _mm_mul_ps(
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v66, v65), v66)),
                _mm_mul_ps(v66, *(__m128 *)_xmm)),
              v65));
    v69 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v67, v60)), v67);
    v70 = _mm_mul_ps(_mm_sub_ps(v68, v61), v69);
    v71 = _mm_mul_ps(_mm_sub_ps((__m128)0i64, _mm_add_ps(v68, v61)), v69);
    v32 = _mm_max_ps(v71, v70);
    v64 = _mm_min_ps(v71, v70);
    v72 = _mm_sub_ps(_mm_add_ps(_mm_mul_ps(v18, v64), input->m_from.m_quad), v91);
    v73 = _mm_mul_ps(v27, v72);
    v74 = _mm_sub_ps(
            v72,
            _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v73, v73, 85), _mm_shuffle_ps(v73, v73, 0)),
                _mm_shuffle_ps(v73, v73, 170)),
              v27));
    v75 = _mm_mul_ps(v74, v74);
    v76 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v75, v75, 85), _mm_shuffle_ps(v75, v75, 0)),
            _mm_shuffle_ps(v75, v75, 170));
    v77 = _mm_rsqrt_ps(v76);
    v78 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v77, v76), v77)), _mm_mul_ps(v77, *(__m128 *)_xmm));
    v79 = _mm_cmplt_ps(v64, v43);
    v56.m_quad = _mm_or_ps(
                   _mm_andnot_ps(v79, _mm_mul_ps(_mm_andnot_ps(_mm_cmple_ps(v76, (__m128)0i64), v78), v74)),
                   _mm_and_ps(v79, v56.m_quad));
  }
  else
  {
    v62 = _mm_sub_ps(
            _mm_add_ps(_mm_mul_ps(v43, v18), input->m_from.m_quad),
            _mm_or_ps(_mm_andnot_ps((__m128)v44, v92), _mm_and_ps((__m128)v44, v91)));
    v63 = _mm_mul_ps(v62, v62);
    if ( (float)((float)(_mm_shuffle_ps(v63, v63, 85).m128_f32[0] + _mm_shuffle_ps(v63, v63, 0).m128_f32[0])
               + _mm_shuffle_ps(v63, v63, 170).m128_f32[0]) > v48.m128_f32[0] )
      goto LABEL_13;
    v64 = (__m128)xmmword_141A712F0;
  }
  v80 = _mm_max_ps(v43, v64);
  v81 = _mm_and_ps(
          _mm_and_ps(_mm_cmple_ps(v80, _mm_min_ps(v93, v32)), _mm_cmple_ps((__m128)0i64, v80)),
          _mm_cmplt_ps(v80, v94));
  LODWORD(v82) = _mm_andnot_ps(v81, v94).m128_u32[0] | v81.m128_i32[0] & v80.m128_i32[0];
  if ( _mm_movemask_ps(v81) )
  {
    m_shapeKeyIndex = results->m_shapeKeyIndex;
    results->m_hitFraction = v82;
    results->m_normal = (hkVector4f)v56.m_quad;
    results->m_shapeKeys[m_shapeKeyIndex] = -1;
    v84 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v85 = v84[1];
    if ( v85 < v84[3] )
    {
      *(_QWORD *)v85 = "Et";
      v86 = __rdtsc();
      *(_DWORD *)(v85 + 8) = v86;
      v84[1] = v85 + 16;
    }
    result->m_bool = 1;
    return result;
  }
LABEL_13:
  v87 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v88 = v87[1];
  if ( v88 < v87[3] )
  {
    *(_QWORD *)v88 = "Et";
    v89 = __rdtsc();
    *(_DWORD *)(v88 + 8) = v89;
    v87[1] = v88 + 16;
  }
  result->m_bool = 0;
  return result;
}

