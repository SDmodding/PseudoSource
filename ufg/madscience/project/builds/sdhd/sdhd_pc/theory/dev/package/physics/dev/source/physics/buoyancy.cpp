// File Line: 86
// RVA: 0xA1E50
float __fastcall UFG::ClipTriangle(
        hkVector4f *centroid,
        hkVector4f *p,
        hkVector4f *v1,
        hkVector4f *v2,
        hkVector4f *v3,
        float d1,
        float d2,
        float d3)
{
  __m128 v8; // xmm5
  __m128 v9; // xmm10
  __m128 m_quad; // xmm6
  __m128 v11; // xmm11
  __m128 v12; // xmm12
  __m128 v13; // xmm11
  __m128 v14; // xmm1
  __m128 v15; // xmm10
  __m128 v16; // xmm2
  __m128 v17; // xmm2
  __m128 v18; // xmm2
  __m128 v19; // xmm8
  __m128 v20; // xmm1
  __m128 v21; // xmm9
  __m128 v22; // xmm2
  __m128 v23; // xmm1
  __m128 v24; // xmm2
  __m128 v25; // xmm2
  __m128 v26; // xmm3
  __m128 v27; // xmm2
  float result; // xmm0_4
  __m128 v29; // xmm1
  __m128 v30; // xmm5
  __m128 v31; // xmm2
  __m128 v32; // xmm2
  __m128 v33; // xmm0
  __m128 v34; // xmm4
  __m128 v35; // xmm1
  __m128 v36; // xmm2
  __m128 v37; // xmm10
  __m128 v38; // xmm2
  __m128 v39; // xmm2
  __m128 v40; // xmm8
  __m128 v41; // xmm1
  __m128 v42; // xmm9
  __m128 v43; // xmm1
  __m128 v44; // xmm9
  __m128 v45; // xmm2
  __m128 v46; // xmm2
  __m128 v47; // xmm2
  __m128 v48; // xmm3
  __m128 v49; // xmm2
  hkVector4f v50; // xmm4
  __m128 v51; // xmm2
  __m128 v52; // xmm5
  __m128 v53; // xmm1
  __m128 v54; // xmm2
  __m128 v55; // xmm3
  __m128 v56; // xmm2

  m_quad = v1->m_quad;
  v11 = (__m128)LODWORD(d1);
  v11.m128_f32[0] = d1 / (float)(d1 - d2);
  v12 = v2->m_quad;
  v13 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v11, v11, 0), _mm_sub_ps(v2->m_quad, v1->m_quad)), v1->m_quad);
  if ( d1 < 0.0 )
  {
    if ( d3 < 0.0 )
    {
      v14 = _mm_sub_ps(m_quad, v13);
      v9.m128_f32[0] = d2 / (float)(d2 - d3);
      v15 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v9, v9, 0), _mm_sub_ps(v3->m_quad, v12)), v12);
      v16 = _mm_sub_ps(v15, v13);
      v17 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v16, v16, 201), v14), _mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v16));
      v18 = _mm_mul_ps(_mm_shuffle_ps(v17, v17, 201), _mm_sub_ps(p->m_quad, v13));
      v19 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)),
              _mm_shuffle_ps(v18, v18, 170));
      v19.m128_f32[0] = v19.m128_f32[0] * 0.16666667;
      v20 = v19;
      v20.m128_f32[0] = v19.m128_f32[0] * 0.25;
      v21 = _mm_add_ps(
              _mm_mul_ps(_mm_add_ps(_mm_add_ps(_mm_add_ps(p->m_quad, v13), v15), m_quad), _mm_shuffle_ps(v20, v20, 0)),
              centroid->m_quad);
      *centroid = (hkVector4f)v21;
      v22 = _mm_sub_ps(v3->m_quad, v15);
      v23 = _mm_sub_ps(v1->m_quad, v15);
      v24 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v22, v22, 201), v23), _mm_mul_ps(_mm_shuffle_ps(v23, v23, 201), v22));
      v25 = _mm_mul_ps(_mm_shuffle_ps(v24, v24, 201), _mm_sub_ps(p->m_quad, v15));
      v26 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)),
              _mm_shuffle_ps(v25, v25, 170));
      v26.m128_f32[0] = v26.m128_f32[0] * 0.16666667;
      v27 = v26;
      v27.m128_f32[0] = v26.m128_f32[0] * 0.25;
      result = v19.m128_f32[0] + v26.m128_f32[0];
      centroid->m_quad = _mm_add_ps(
                           _mm_mul_ps(
                             _mm_add_ps(_mm_add_ps(_mm_add_ps(v15, p->m_quad), v3->m_quad), v1->m_quad),
                             _mm_shuffle_ps(v27, v27, 0)),
                           v21);
      return result;
    }
    v29 = _mm_sub_ps(m_quad, v13);
    v8.m128_f32[0] = d1 / (float)(d1 - d3);
    v30 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v8, v8, 0), _mm_sub_ps(v3->m_quad, m_quad)), m_quad);
    v31 = _mm_sub_ps(v30, v13);
    v32 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v31, v31, 201), v29), _mm_mul_ps(_mm_shuffle_ps(v29, v29, 201), v31));
    v33 = p->m_quad;
    v34 = _mm_add_ps(_mm_add_ps(_mm_add_ps(p->m_quad, v13), v30), m_quad);
    goto LABEL_8;
  }
  if ( d3 >= 0.0 )
  {
    v51 = _mm_sub_ps(v12, v13);
    v8.m128_f32[0] = d2 / (float)(d2 - d3);
    v52 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v8, v8, 0), _mm_sub_ps(v3->m_quad, v12)), v12);
    v53 = _mm_sub_ps(v52, v13);
    v32 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v51, v51, 201), v53), _mm_mul_ps(_mm_shuffle_ps(v53, v53, 201), v51));
    v33 = p->m_quad;
    v34 = _mm_add_ps(_mm_add_ps(_mm_add_ps(p->m_quad, v13), v12), v52);
LABEL_8:
    v54 = _mm_mul_ps(_mm_shuffle_ps(v32, v32, 201), _mm_sub_ps(v33, v13));
    v55 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v54, v54, 85), _mm_shuffle_ps(v54, v54, 0)),
            _mm_shuffle_ps(v54, v54, 170));
    v55.m128_f32[0] = v55.m128_f32[0] * 0.16666667;
    v56 = v55;
    result = v55.m128_f32[0];
    v56.m128_f32[0] = v55.m128_f32[0] * 0.25;
    v50.m_quad = _mm_add_ps(_mm_mul_ps(v34, _mm_shuffle_ps(v56, v56, 0)), centroid->m_quad);
    goto LABEL_9;
  }
  v35 = _mm_sub_ps(v3->m_quad, v13);
  v9.m128_f32[0] = d1 / (float)(d1 - d3);
  v36 = _mm_sub_ps(v12, v13);
  v37 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v9, v9, 0), _mm_sub_ps(v3->m_quad, m_quad)), m_quad);
  v38 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v36, v36, 201), v35), _mm_mul_ps(_mm_shuffle_ps(v35, v35, 201), v36));
  v39 = _mm_mul_ps(_mm_shuffle_ps(v38, v38, 201), _mm_sub_ps(p->m_quad, v13));
  v40 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v39, v39, 85), _mm_shuffle_ps(v39, v39, 0)), _mm_shuffle_ps(v39, v39, 170));
  v40.m128_f32[0] = v40.m128_f32[0] * 0.16666667;
  v41 = v40;
  v41.m128_f32[0] = v40.m128_f32[0] * 0.25;
  v42 = _mm_mul_ps(_mm_add_ps(_mm_add_ps(_mm_add_ps(p->m_quad, v13), v12), v3->m_quad), _mm_shuffle_ps(v41, v41, 0));
  v43 = _mm_sub_ps(v37, v13);
  v44 = _mm_add_ps(v42, centroid->m_quad);
  *centroid = (hkVector4f)v44;
  v45 = _mm_sub_ps(v3->m_quad, v13);
  v46 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v45, v45, 201), v43), _mm_mul_ps(_mm_shuffle_ps(v43, v43, 201), v45));
  v47 = _mm_mul_ps(_mm_shuffle_ps(v46, v46, 201), _mm_sub_ps(p->m_quad, v13));
  v48 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v47, v47, 85), _mm_shuffle_ps(v47, v47, 0)), _mm_shuffle_ps(v47, v47, 170));
  v48.m128_f32[0] = v48.m128_f32[0] * 0.16666667;
  v49 = v48;
  v49.m128_f32[0] = v48.m128_f32[0] * 0.25;
  result = v40.m128_f32[0] + v48.m128_f32[0];
  v50.m_quad = _mm_add_ps(
                 _mm_mul_ps(
                   _mm_add_ps(_mm_add_ps(_mm_add_ps(p->m_quad, v13), v3->m_quad), v37),
                   _mm_shuffle_ps(v49, v49, 0)),
                 v44);
LABEL_9:
  *centroid = (hkVector4f)v50.m_quad;
  return result;
}

// File Line: 140
// RVA: 0xA36A0
float __fastcall UFG::BuoyancyVolume::ComputeBuoyancy(
        UFG::BuoyancyVolume *this,
        hkTransformf *transform,
        hkVector4f *centreOfBuoyancy,
        float waterElevation)
{
  __m128 d1; // xmm2
  float v8; // xmm6_4
  __m128 m_quad; // xmm9
  unsigned __int16 v10; // di
  unsigned __int16 v11; // dx
  __m128 v12; // xmm3
  __int64 v13; // rcx
  __m128 v14; // xmm2
  float v15; // xmm1_4
  float v16; // xmm0_4
  __int64 v17; // rdx
  float d2; // xmm3_4
  float v19; // xmm1_4
  __m128 v20; // xmm4
  __m128 v21; // xmm5
  __m128 v22; // xmm8
  float v23; // xmm0_4
  __m128 v24; // xmm3
  __m128 v25; // xmm1
  __m128 v26; // xmm3
  __m128 v27; // xmm3
  __m128 v28; // xmm1
  hkVector4f b; // [rsp+38h] [rbp-59h] BYREF
  hkVector4f v31; // [rsp+48h] [rbp-49h] BYREF
  hkVector4f v3; // [rsp+58h] [rbp-39h] BYREF
  hkVector4f v2; // [rsp+68h] [rbp-29h] BYREF
  hkVector4f v1; // [rsp+78h] [rbp-19h] BYREF

  b.m_quad = (__m128)transform->m_translation;
  b.m_quad.m128_f32[2] = waterElevation;
  hkVector4f::setTransformedInversePos(
    (hkVector4f *)&b.m_quad.m128_u16[4],
    transform,
    (hkVector4f *)&b.m_quad.m128_u16[4]);
  *centreOfBuoyancy = 0i64;
  v8 = 0.0;
  v31.m_quad = _xmm;
  hkVector4f::setRotatedInverseDir(&v31, &transform->m_rotation, &v31);
  m_quad = b.m_quad;
  v10 = 0;
  v11 = 0;
  if ( this->mNumVertices )
  {
    v12 = v31.m_quad;
    do
    {
      v13 = v11++;
      v14 = _mm_mul_ps(_mm_sub_ps(this->mLocalVertices[(unsigned int)v13].m_quad, m_quad), v12);
      v15 = _mm_shuffle_ps(v14, v14, 85).m128_f32[0];
      v16 = _mm_shuffle_ps(v14, v14, 0).m128_f32[0];
      d1 = _mm_shuffle_ps(v14, v14, 170);
      this->mDepths[v13] = (float)(v15 + v16) + d1.m128_f32[0];
    }
    while ( v11 < this->mNumVertices );
  }
  if ( this->mNumIndices )
  {
    do
    {
      v17 = this->mIndices[v10 + 2];
      d2 = this->mDepths[this->mIndices[v10 + 1]];
      d1 = (__m128)LODWORD(this->mDepths[this->mIndices[v10]]);
      v19 = this->mDepths[v17];
      v20 = this->mLocalVertices[this->mIndices[v10]].m_quad;
      v21 = this->mLocalVertices[this->mIndices[v10 + 1]].m_quad;
      v3.m_quad = v20;
      v22 = this->mLocalVertices[(unsigned int)v17].m_quad;
      v1.m_quad = v21;
      v2.m_quad = v22;
      if ( (float)(d2 * d1.m128_f32[0]) >= 0.0 )
      {
        if ( (float)(v19 * d1.m128_f32[0]) >= 0.0 )
        {
          if ( (float)(v19 * d2) >= 0.0 )
          {
            if ( d1.m128_f32[0] < 0.0 || d2 < 0.0 || v19 < 0.0 )
            {
              v24 = _mm_sub_ps(v21, v20);
              v25 = _mm_sub_ps(v22, v20);
              v26 = _mm_sub_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v24, v24, 201), v25),
                      _mm_mul_ps(_mm_shuffle_ps(v25, v25, 201), v24));
              v27 = _mm_mul_ps(_mm_shuffle_ps(v26, v26, 201), _mm_sub_ps(m_quad, v20));
              d1 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)),
                     _mm_shuffle_ps(v27, v27, 170));
              d1.m128_f32[0] = d1.m128_f32[0] * 0.16666667;
              v28 = d1;
              v8 = v8 + d1.m128_f32[0];
              v28.m128_f32[0] = d1.m128_f32[0] * 0.25;
              centreOfBuoyancy->m_quad = _mm_add_ps(
                                           _mm_mul_ps(
                                             _mm_add_ps(_mm_add_ps(_mm_add_ps(v20, m_quad), v21), v22),
                                             _mm_shuffle_ps(v28, v28, 0)),
                                           centreOfBuoyancy->m_quad);
            }
            goto LABEL_16;
          }
          v23 = UFG::ClipTriangle(centreOfBuoyancy, &b, &v1, &v2, &v3, d2, v19, d1.m128_f32[0]);
        }
        else
        {
          v23 = UFG::ClipTriangle(centreOfBuoyancy, &b, &v2, &v3, &v1, v19, d1.m128_f32[0], d2);
        }
      }
      else
      {
        v23 = UFG::ClipTriangle(centreOfBuoyancy, &b, &v3, &v1, &v2, d1.m128_f32[0], d2, v19);
      }
      v8 = v8 + v23;
LABEL_16:
      v10 += 3;
    }
    while ( v10 < this->mNumIndices );
  }
  d1.m128_f32[0] = 1.0 / v8;
  centreOfBuoyancy->m_quad = _mm_mul_ps(_mm_shuffle_ps(d1, d1, 0), centreOfBuoyancy->m_quad);
  hkVector4f::setTransformedPos(centreOfBuoyancy, transform, centreOfBuoyancy);
  return v8;
}

// File Line: 219
// RVA: 0x97000
void __fastcall UFG::BuoyancyAction::BuoyancyAction(
        UFG::BuoyancyAction *this,
        hkpRigidBody *body,
        float waterElevation,
        float buoyancyFactor,
        float linearDaming,
        float angularDamping,
        float buoyancyDecayRate)
{
  hkpShape *m_shape; // rcx
  __int64 v10; // r8
  __m128 v11; // xmm4
  __m128 v12; // xmm7
  __m128 v13; // xmm8
  __m128 v14; // xmm6
  __m128 v15; // xmm5
  __m128 v16; // xmm4
  __m128 v17; // xmm1
  __m128 v18; // [rsp+30h] [rbp-A8h] BYREF
  __m128 v19; // [rsp+40h] [rbp-98h]
  __int128 v20[8]; // [rsp+50h] [rbp-88h] BYREF

  hkpUnaryAction::hkpUnaryAction(this, body, 0i64);
  this->vfptr = (hkBaseObjectVtbl *)&UFG::BuoyancyAction::`vftable;
  this->mWaterElevation = waterElevation;
  this->mBuoyancyFactor = buoyancyFactor;
  this->mBuoyancyDecayRate = buoyancyDecayRate;
  this->mLinearDamping = linearDaming;
  this->mAngularDamping = angularDamping;
  m_shape = body->m_collidable.m_shape;
  v20[0] = (__int128)transform.m_quad;
  v20[1] = (__int128)direction.m_quad;
  v20[2] = (__int128)stru_141A71280.m_quad;
  v20[3] = 0i64;
  ((void (__fastcall *)(hkpShape *, __int128 *, __int64, __m128 *, __int64))m_shape->vfptr[2].__vecDelDtor)(
    m_shape,
    v20,
    v10,
    &v18,
    -2i64);
  *(_DWORD *)&this->mBuoyancyVolume.mNumVertices = 2359304;
  v11 = (__m128)v19.m128_u32[2];
  v12 = (__m128)v18.m128_u32[1];
  v13 = (__m128)v18.m128_u32[0];
  this->mBuoyancyVolume.mLocalVertices[0].m_quad = _mm_unpacklo_ps(
                                                     _mm_unpacklo_ps((__m128)v18.m128_u32[0], (__m128)v19.m128_u32[2]),
                                                     _mm_unpacklo_ps(
                                                       (__m128)v18.m128_u32[1],
                                                       (__m128)(unsigned int)FLOAT_1_0));
  v14 = (__m128)v19.m128_u32[0];
  this->mBuoyancyVolume.mLocalVertices[1].m_quad = _mm_unpacklo_ps(
                                                     _mm_unpacklo_ps((__m128)v19.m128_u32[0], v11),
                                                     _mm_unpacklo_ps(v12, (__m128)(unsigned int)FLOAT_1_0));
  v15 = (__m128)v19.m128_u32[1];
  this->mBuoyancyVolume.mLocalVertices[2].m_quad = _mm_unpacklo_ps(
                                                     _mm_unpacklo_ps(v14, v11),
                                                     _mm_unpacklo_ps(
                                                       (__m128)v19.m128_u32[1],
                                                       (__m128)(unsigned int)FLOAT_1_0));
  this->mBuoyancyVolume.mLocalVertices[3].m_quad = _mm_unpacklo_ps(
                                                     _mm_unpacklo_ps(v13, v11),
                                                     _mm_unpacklo_ps(v15, (__m128)(unsigned int)FLOAT_1_0));
  v16 = (__m128)v18.m128_u32[2];
  this->mBuoyancyVolume.mLocalVertices[4].m_quad = _mm_unpacklo_ps(
                                                     _mm_unpacklo_ps(v13, (__m128)v18.m128_u32[2]),
                                                     _mm_unpacklo_ps(v12, (__m128)(unsigned int)FLOAT_1_0));
  this->mBuoyancyVolume.mLocalVertices[5].m_quad = _mm_unpacklo_ps(
                                                     _mm_unpacklo_ps(v14, v16),
                                                     _mm_unpacklo_ps(v12, (__m128)(unsigned int)FLOAT_1_0));
  this->mBuoyancyVolume.mLocalVertices[6].m_quad = _mm_unpacklo_ps(
                                                     _mm_unpacklo_ps(v14, v16),
                                                     _mm_unpacklo_ps(v15, (__m128)(unsigned int)FLOAT_1_0));
  this->mBuoyancyVolume.mLocalVertices[7].m_quad = _mm_unpacklo_ps(
                                                     _mm_unpacklo_ps(v13, v16),
                                                     _mm_unpacklo_ps(v15, (__m128)(unsigned int)FLOAT_1_0));
  *(_DWORD *)this->mBuoyancyVolume.mIndices = 0x10000;
  *(_DWORD *)&this->mBuoyancyVolume.mIndices[2] = 2;
  *(_DWORD *)&this->mBuoyancyVolume.mIndices[4] = 196610;
  *(_DWORD *)&this->mBuoyancyVolume.mIndices[6] = 131078;
  *(_DWORD *)&this->mBuoyancyVolume.mIndices[8] = 393217;
  *(_DWORD *)&this->mBuoyancyVolume.mIndices[10] = 327681;
  *(_DWORD *)&this->mBuoyancyVolume.mIndices[12] = 458758;
  *(_DWORD *)&this->mBuoyancyVolume.mIndices[14] = 393219;
  *(_DWORD *)&this->mBuoyancyVolume.mIndices[16] = 131075;
  *(_DWORD *)&this->mBuoyancyVolume.mIndices[18] = 196608;
  *(_DWORD *)&this->mBuoyancyVolume.mIndices[20] = 7;
  *(_DWORD *)&this->mBuoyancyVolume.mIndices[22] = 262151;
  *(_DWORD *)&this->mBuoyancyVolume.mIndices[24] = 327684;
  *(_DWORD *)&this->mBuoyancyVolume.mIndices[26] = 262145;
  *(_DWORD *)&this->mBuoyancyVolume.mIndices[28] = 1;
  *(_DWORD *)&this->mBuoyancyVolume.mIndices[30] = 393220;
  *(_DWORD *)&this->mBuoyancyVolume.mIndices[32] = 262149;
  *(_DWORD *)&this->mBuoyancyVolume.mIndices[34] = 393223;
  v17 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps(v19, v18), (__m128)xmmword_141A711B0), (__m128)_xmm);
  this->mAabbVolume = (float)(v17.m128_f32[0] * _mm_shuffle_ps(v17, v17, 85).m128_f32[0])
                    * _mm_shuffle_ps(v17, v17, 170).m128_f32[0];
  this->mSubmergedPercent = 0.0;
}

// File Line: 288
// RVA: 0xB6190
void __fastcall UFG::BuoyancyAction::applyAction(UFG::BuoyancyAction *this, hkStepInfo *stepInfo)
{
  __m128 mBuoyancyDecayRate_low; // xmm0
  float v4; // xmm1_4
  hkpEntity *m_entity; // rsi
  float v6; // xmm7_4
  __m128 v7; // xmm2
  __int64 v8; // rdx
  __m128 v9; // xmm0
  __int64 v10; // rdx
  __m128 m_quad; // [rsp+20h] [rbp-68h] BYREF
  hkVector4f v12; // [rsp+30h] [rbp-58h] BYREF
  __m128 v13; // [rsp+40h] [rbp-48h] BYREF
  __m128 v14; // [rsp+50h] [rbp-38h] BYREF

  mBuoyancyDecayRate_low = (__m128)LODWORD(this->mBuoyancyDecayRate);
  v4 = this->mBuoyancyFactor
     - (float)((float)(mBuoyancyDecayRate_low.m128_f32[0] * stepInfo->m_deltaTime.m_storage) * this->mBuoyancyFactor);
  this->mBuoyancyFactor = v4;
  if ( v4 <= 0.0 )
  {
    this->mBuoyancyFactor = 0.0;
  }
  else
  {
    m_entity = this->m_entity;
    mBuoyancyDecayRate_low.m128_f32[0] = UFG::BuoyancyVolume::ComputeBuoyancy(
                                           &this->mBuoyancyVolume,
                                           &m_entity->m_motion.m_motionState.m_transform,
                                           &v12,
                                           this->mWaterElevation);
    v6 = mBuoyancyDecayRate_low.m128_f32[0];
    if ( mBuoyancyDecayRate_low.m128_f32[0] <= 0.0 )
    {
      this->mSubmergedPercent = 0.0;
    }
    else
    {
      v7 = mBuoyancyDecayRate_low;
      this->mSubmergedPercent = mBuoyancyDecayRate_low.m128_f32[0] / this->mAabbVolume;
      v7.m128_f32[0] = (float)((float)(mBuoyancyDecayRate_low.m128_f32[0] * 9.8000002) * 1000.0) * this->mBuoyancyFactor;
      v13 = _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)0i64, v7), (__m128)0i64);
      hkpEntity::activate(m_entity);
      ((void (__fastcall *)(hkpMaxSizeMotion *, __int64, __m128 *, hkVector4f *))m_entity->m_motion.vfptr[12].__first_virtual_table_function__)(
        &m_entity->m_motion,
        v8,
        &v13,
        &v12);
      v14 = _mm_mul_ps((__m128)_xmm, m_entity->m_motion.m_linearVelocity.m_quad);
      hkpEntity::activate(m_entity);
      m_entity->m_motion.vfptr[9].__vecDelDtor(&m_entity->m_motion, (unsigned int)&v14);
      m_quad = m_entity->m_motion.m_angularVelocity.m_quad;
      v9 = m_quad;
      v9.m128_i32[0] = COERCE_UNSIGNED_INT((float)(v6 * this->mAngularDamping) * hkpMotion::getMass(&m_entity->m_motion)) ^ _xmm[0];
      m_quad = _mm_mul_ps(m_quad, _mm_shuffle_ps(v9, v9, 0));
      hkpEntity::activate(m_entity);
      ((void (__fastcall *)(hkpMaxSizeMotion *, __int64, __m128 *))m_entity->m_motion.vfptr[13].__first_virtual_table_function__)(
        &m_entity->m_motion,
        v10,
        &m_quad);
    }
  }
}

