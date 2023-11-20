// File Line: 86
// RVA: 0xA1E50
float __usercall UFG::ClipTriangle@<xmm0>(hkVector4f *centroid@<rcx>, hkVector4f *p@<rdx>, hkVector4f *v1@<r8>, hkVector4f *v2@<r9>, __m128 a5@<xmm5>, __m128 a6@<xmm10>, hkVector4f *v3, float d1, float d2, float d3)
{
  __m128 v10; // xmm6
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
  hkVector4f v21; // xmm9
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
  hkVector4f v44; // xmm9
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

  v10 = v1->m_quad;
  v11 = (__m128)LODWORD(d1);
  v11.m128_f32[0] = d1 / (float)(d1 - d2);
  v12 = v2->m_quad;
  v13 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v11, v11, 0), _mm_sub_ps(v2->m_quad, v1->m_quad)), v1->m_quad);
  if ( d1 < 0.0 )
  {
    if ( d3 < 0.0 )
    {
      v14 = _mm_sub_ps(v10, v13);
      a6.m128_f32[0] = d2 / (float)(d2 - d3);
      v15 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(a6, a6, 0), _mm_sub_ps(v3->m_quad, v12)), v12);
      v16 = _mm_sub_ps(v15, v13);
      v17 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v16, v16, 201), v14), _mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v16));
      v18 = _mm_mul_ps(_mm_shuffle_ps(v17, v17, 201), _mm_sub_ps(p->m_quad, v13));
      v19 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)),
              _mm_shuffle_ps(v18, v18, 170));
      v19.m128_f32[0] = v19.m128_f32[0] * 0.16666667;
      v20 = v19;
      v20.m128_f32[0] = v19.m128_f32[0] * 0.25;
      v21.m_quad = _mm_add_ps(
                     _mm_mul_ps(
                       _mm_add_ps(_mm_add_ps(_mm_add_ps(p->m_quad, v13), v15), v10),
                       _mm_shuffle_ps(v20, v20, 0)),
                     centroid->m_quad);
      *centroid = (hkVector4f)v21.m_quad;
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
                           v21.m_quad);
      return result;
    }
    v29 = _mm_sub_ps(v10, v13);
    a5.m128_f32[0] = d1 / (float)(d1 - d3);
    v30 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(a5, a5, 0), _mm_sub_ps(v3->m_quad, v10)), v10);
    v31 = _mm_sub_ps(v30, v13);
    v32 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v31, v31, 201), v29), _mm_mul_ps(_mm_shuffle_ps(v29, v29, 201), v31));
    v33 = p->m_quad;
    v34 = _mm_add_ps(_mm_add_ps(_mm_add_ps(p->m_quad, v13), v30), v10);
    goto LABEL_8;
  }
  if ( d3 >= 0.0 )
  {
    v51 = _mm_sub_ps(v12, v13);
    a5.m128_f32[0] = d2 / (float)(d2 - d3);
    v52 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(a5, a5, 0), _mm_sub_ps(v3->m_quad, v12)), v12);
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
  a6.m128_f32[0] = d1 / (float)(d1 - d3);
  v36 = _mm_sub_ps(v12, v13);
  v37 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(a6, a6, 0), _mm_sub_ps(v3->m_quad, v10)), v10);
  v38 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v36, v36, 201), v35), _mm_mul_ps(_mm_shuffle_ps(v35, v35, 201), v36));
  v39 = _mm_mul_ps(_mm_shuffle_ps(v38, v38, 201), _mm_sub_ps(p->m_quad, v13));
  v40 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v39, v39, 85), _mm_shuffle_ps(v39, v39, 0)), _mm_shuffle_ps(v39, v39, 170));
  v40.m128_f32[0] = v40.m128_f32[0] * 0.16666667;
  v41 = v40;
  v41.m128_f32[0] = v40.m128_f32[0] * 0.25;
  v42 = _mm_mul_ps(_mm_add_ps(_mm_add_ps(_mm_add_ps(p->m_quad, v13), v12), v3->m_quad), _mm_shuffle_ps(v41, v41, 0));
  v43 = _mm_sub_ps(v37, v13);
  v44.m_quad = _mm_add_ps(v42, centroid->m_quad);
  *centroid = (hkVector4f)v44.m_quad;
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
                 v44.m_quad);
LABEL_9:
  *centroid = (hkVector4f)v50.m_quad;
  return result;
}

// File Line: 140
// RVA: 0xA36A0
float __usercall UFG::BuoyancyVolume::ComputeBuoyancy@<xmm0>(UFG::BuoyancyVolume *this@<rcx>, hkTransformf *transform@<rdx>, hkVector4f *centreOfBuoyancy@<r8>, float waterElevation@<xmm3>, __m128 d1@<xmm2>)
{
  hkVector4f *v5; // rsi
  UFG::BuoyancyVolume *v6; // rbx
  hkTransformf *v7; // r14
  float v8; // xmm6_4
  __m128 v9; // xmm9
  unsigned __int16 v10; // di
  unsigned __int16 v11; // dx
  __m128 v12; // xmm3
  __int64 v13; // rcx
  __m128 v14; // xmm2
  float v15; // xmm1_4
  float v16; // xmm0_4
  __m128 *v17; // xmm10_8
  __int64 v18; // rdx
  float d2; // xmm3_4
  float v20; // xmm1_4
  __m128 v21; // xmm4
  __m128 v22; // xmm5
  __m128 v23; // xmm8
  float v24; // xmm0_4
  __m128 v25; // xmm3
  __m128 v26; // xmm1
  __m128 v27; // xmm3
  __m128 v28; // xmm3
  __m128 v29; // xmm1
  hkVector4f b; // [rsp+38h] [rbp-59h]
  hkVector4f v32; // [rsp+48h] [rbp-49h]
  hkVector4f v3; // [rsp+58h] [rbp-39h]
  hkVector4f v2; // [rsp+68h] [rbp-29h]
  hkVector4f v1; // [rsp+78h] [rbp-19h]

  v5 = centreOfBuoyancy;
  v6 = this;
  v7 = transform;
  b.m_quad = (__m128)transform->m_translation;
  b.m_quad.m128_f32[2] = waterElevation;
  hkVector4f::setTransformedInversePos((hkVector4f *)((char *)&b + 8), transform, (hkVector4f *)((char *)&b + 8));
  *v5 = 0i64;
  v8 = 0.0;
  v32.m_quad = _xmm;
  hkVector4f::setRotatedInverseDir(&v32, (hkMatrix3f *)&v7->m_rotation.m_col0, &v32);
  v9 = b.m_quad;
  v10 = 0;
  v11 = 0;
  if ( v6->mNumVertices > 0u )
  {
    v12 = v32.m_quad;
    do
    {
      v13 = v11++;
      v14 = _mm_mul_ps(_mm_sub_ps(v6->mLocalVertices[(unsigned int)v13].m_quad, v9), v12);
      LODWORD(v15) = (unsigned __int128)_mm_shuffle_ps(v14, v14, 85);
      LODWORD(v16) = (unsigned __int128)_mm_shuffle_ps(v14, v14, 0);
      d1 = _mm_shuffle_ps(v14, v14, 170);
      v6->mDepths[v13] = (float)(v15 + v16) + d1.m128_f32[0];
    }
    while ( v11 < v6->mNumVertices );
  }
  if ( v6->mNumIndices > 0u )
  {
    v17 = (__m128 *)LODWORD(FLOAT_0_16666667);
    do
    {
      v18 = v6->mIndices[v10 + 2];
      d2 = v6->mDepths[v6->mIndices[v10 + 1]];
      d1 = (__m128)LODWORD(v6->mDepths[v6->mIndices[v10]]);
      v20 = v6->mDepths[v18];
      v21 = v6->mLocalVertices[v6->mIndices[v10]].m_quad;
      v22 = v6->mLocalVertices[v6->mIndices[v10 + 1]].m_quad;
      v3.m_quad = (__m128)v6->mLocalVertices[v6->mIndices[v10]];
      v23 = v6->mLocalVertices[(unsigned int)v18].m_quad;
      v1.m_quad = v22;
      v2.m_quad = v23;
      if ( (float)(d2 * d1.m128_f32[0]) >= 0.0 )
      {
        if ( (float)(v20 * d1.m128_f32[0]) >= 0.0 )
        {
          if ( (float)(v20 * d2) >= 0.0 )
          {
            if ( d1.m128_f32[0] < 0.0 || d2 < 0.0 || v20 < 0.0 )
            {
              v25 = _mm_sub_ps(v22, v21);
              v26 = _mm_sub_ps(v23, v21);
              v27 = _mm_sub_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v25, v25, 201), v26),
                      _mm_mul_ps(_mm_shuffle_ps(v26, v26, 201), v25));
              v28 = _mm_mul_ps(_mm_shuffle_ps(v27, v27, 201), _mm_sub_ps(v9, v21));
              d1 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v28, v28, 85), _mm_shuffle_ps(v28, v28, 0)),
                     _mm_shuffle_ps(v28, v28, 170));
              d1.m128_f32[0] = d1.m128_f32[0] * *(float *)&v17;
              v29 = d1;
              v8 = v8 + d1.m128_f32[0];
              v29.m128_f32[0] = d1.m128_f32[0] * 0.25;
              v5->m_quad = _mm_add_ps(
                             _mm_mul_ps(
                               _mm_add_ps(_mm_add_ps(_mm_add_ps(v21, v9), v22), v23),
                               _mm_shuffle_ps(v29, v29, 0)),
                             v5->m_quad);
            }
            goto LABEL_17;
          }
          v24 = UFG::ClipTriangle(v5, &b, &v1, &v2, (__m128 *)v22.m128_u64[0], v17, &v3, d2, v20, d1.m128_f32[0]);
        }
        else
        {
          v24 = UFG::ClipTriangle(v5, &b, &v2, &v3, (__m128 *)v22.m128_u64[0], v17, &v1, v20, d1.m128_f32[0], d2);
        }
      }
      else
      {
        v24 = UFG::ClipTriangle(v5, &b, &v3, &v1, (__m128 *)v22.m128_u64[0], v17, &v2, d1.m128_f32[0], d2, v20);
      }
      v8 = v8 + v24;
LABEL_17:
      v10 += 3;
    }
    while ( v10 < v6->mNumIndices );
  }
  d1.m128_f32[0] = 1.0 / v8;
  v5->m_quad = _mm_mul_ps(_mm_shuffle_ps(d1, d1, 0), v5->m_quad);
  hkVector4f::setTransformedPos(v5, v7, v5);
  return v8;
}

// File Line: 219
// RVA: 0x97000
void __fastcall UFG::BuoyancyAction::BuoyancyAction(UFG::BuoyancyAction *this, hkpRigidBody *body, float waterElevation, float buoyancyFactor, float linearDaming, float angularDamping, float buoyancyDecayRate)
{
  hkpRigidBody *v7; // rbx
  __m128 *v8; // rdi
  hkpShape *v9; // rcx
  __int64 v10; // r8
  __m128 v11; // xmm4
  __m128 v12; // xmm7
  __m128 v13; // xmm8
  __m128 v14; // xmm6
  __m128 v15; // xmm5
  __m128 v16; // xmm4
  __m128 v17; // xmm1
  __m128 v18; // [rsp+30h] [rbp-A8h]
  __m128 v19; // [rsp+40h] [rbp-98h]
  __m128 v20; // [rsp+50h] [rbp-88h]
  __m128 v21; // [rsp+60h] [rbp-78h]
  __m128 v22; // [rsp+70h] [rbp-68h]
  __int128 v23; // [rsp+80h] [rbp-58h]

  v7 = body;
  v8 = (__m128 *)this;
  hkpUnaryAction::hkpUnaryAction((hkpUnaryAction *)&this->vfptr, (hkpEntity *)&body->vfptr, 0i64);
  v8->m128_u64[0] = (unsigned __int64)&UFG::BuoyancyAction::`vftable';
  v8[19].m128_f32[0] = waterElevation;
  v8[19].m128_f32[1] = buoyancyFactor;
  v8[19].m128_f32[2] = buoyancyDecayRate;
  v8[19].m128_f32[3] = linearDaming;
  v8[20].m128_f32[0] = angularDamping;
  v9 = v7->m_collidable.m_shape;
  v20 = transform.m_quad;
  v21 = direction.m_quad;
  v22 = stru_141A71280.m_quad;
  v23 = 0i64;
  ((void (__fastcall *)(hkpShape *, __m128 *, __int64, __m128 *, signed __int64))v9->vfptr[2].__vecDelDtor)(
    v9,
    &v20,
    v10,
    &v18,
    -2i64);
  v8[18].m128_i32[2] = 2359304;
  v11 = (__m128)v19.m128_u32[2];
  v12 = (__m128)v18.m128_u32[1];
  v13 = (__m128)v18.m128_u32[0];
  v8[4] = _mm_unpacklo_ps(
            _mm_unpacklo_ps((__m128)v18.m128_u32[0], (__m128)v19.m128_u32[2]),
            _mm_unpacklo_ps((__m128)v18.m128_u32[1], (__m128)(unsigned int)FLOAT_1_0));
  v14 = (__m128)v19.m128_u32[0];
  v8[5] = _mm_unpacklo_ps(
            _mm_unpacklo_ps((__m128)v19.m128_u32[0], v11),
            _mm_unpacklo_ps(v12, (__m128)(unsigned int)FLOAT_1_0));
  v15 = (__m128)v19.m128_u32[1];
  v8[6] = _mm_unpacklo_ps(
            _mm_unpacklo_ps(v14, v11),
            _mm_unpacklo_ps((__m128)v19.m128_u32[1], (__m128)(unsigned int)FLOAT_1_0));
  v8[7] = _mm_unpacklo_ps(_mm_unpacklo_ps(v13, v11), _mm_unpacklo_ps(v15, (__m128)(unsigned int)FLOAT_1_0));
  v16 = (__m128)v18.m128_u32[2];
  v8[8] = _mm_unpacklo_ps(
            _mm_unpacklo_ps(v13, (__m128)v18.m128_u32[2]),
            _mm_unpacklo_ps(v12, (__m128)(unsigned int)FLOAT_1_0));
  v8[9] = _mm_unpacklo_ps(_mm_unpacklo_ps(v14, v16), _mm_unpacklo_ps(v12, (__m128)(unsigned int)FLOAT_1_0));
  v8[10] = _mm_unpacklo_ps(_mm_unpacklo_ps(v14, v16), _mm_unpacklo_ps(v15, (__m128)(unsigned int)FLOAT_1_0));
  v8[11] = _mm_unpacklo_ps(_mm_unpacklo_ps(v13, v16), _mm_unpacklo_ps(v15, (__m128)(unsigned int)FLOAT_1_0));
  v8[12].m128_i32[0] = 0x10000;
  v8[12].m128_i32[1] = 2;
  v8[12].m128_i32[2] = 196610;
  v8[12].m128_i32[3] = 131078;
  v8[13].m128_i32[0] = 393217;
  v8[13].m128_i32[1] = 327681;
  v8[13].m128_i32[2] = 458758;
  v8[13].m128_i32[3] = 393219;
  v8[14].m128_i32[0] = 131075;
  v8[14].m128_i32[1] = 196608;
  v8[14].m128_i32[2] = 7;
  v8[14].m128_i32[3] = 262151;
  v8[15].m128_i32[0] = 327684;
  v8[15].m128_i32[1] = 262145;
  v8[15].m128_i32[2] = 1;
  v8[15].m128_i32[3] = 393220;
  v8[16].m128_i32[0] = 262149;
  v8[16].m128_i32[1] = 393223;
  v17 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps(v19, v18), (__m128)xmmword_141A711B0), (__m128)_xmm);
  v8[20].m128_f32[1] = (float)(v17.m128_f32[0] * COERCE_FLOAT(_mm_shuffle_ps(v17, v17, 85)))
                     * COERCE_FLOAT(_mm_shuffle_ps(v17, v17, 170));
  v8[20].m128_i32[2] = 0;
}

// File Line: 288
// RVA: 0xB6190
void __fastcall UFG::BuoyancyAction::applyAction(UFG::BuoyancyAction *this, hkStepInfo *stepInfo, double a3)
{
  __m128 v3; // xmm0
  hkStepInfo *v4; // rbp
  UFG::BuoyancyAction *v5; // rdi
  float v6; // xmm1_4
  hkpEntity *v7; // rsi
  float v8; // xmm7_4
  __m128 v9; // xmm2
  __int128 v10; // xmm6
  __int64 v11; // rdx
  __m128 v12; // xmm0
  __int128 v13; // xmm6
  __int64 v14; // rdx
  __m128 v15; // [rsp+20h] [rbp-68h]
  hkVector4f v16; // [rsp+30h] [rbp-58h]
  __m128 v17; // [rsp+40h] [rbp-48h]
  __m128 v18; // [rsp+50h] [rbp-38h]

  v3 = (__m128)LODWORD(this->mBuoyancyDecayRate);
  v4 = stepInfo;
  v5 = this;
  v6 = this->mBuoyancyFactor
     - (float)((float)(v3.m128_f32[0] * stepInfo->m_deltaTime.m_storage) * this->mBuoyancyFactor);
  this->mBuoyancyFactor = v6;
  if ( v6 <= 0.0 )
  {
    this->mBuoyancyFactor = 0.0;
  }
  else
  {
    v7 = this->m_entity;
    v3.m128_f32[0] = UFG::BuoyancyVolume::ComputeBuoyancy(
                       &this->mBuoyancyVolume,
                       &v7->m_motion.m_motionState.m_transform,
                       &v16,
                       this->mWaterElevation,
                       a3);
    v8 = v3.m128_f32[0];
    if ( v3.m128_f32[0] <= 0.0 )
    {
      v5->mSubmergedPercent = 0.0;
    }
    else
    {
      v9 = v3;
      v5->mSubmergedPercent = v3.m128_f32[0] / v5->mAabbVolume;
      v10 = LODWORD(v4->m_deltaTime.m_storage);
      v9.m128_f32[0] = (float)((float)(v3.m128_f32[0] * 9.8000002) * 1000.0) * v5->mBuoyancyFactor;
      v17 = _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)0i64, v9), (__m128)0i64);
      hkpEntity::activate(v7);
      ((void (__fastcall *)(hkpMaxSizeMotion *, __int64, __m128 *, hkVector4f *))v7->m_motion.vfptr[12].__first_virtual_table_function__)(
        &v7->m_motion,
        v11,
        &v17,
        &v16);
      v18 = _mm_mul_ps((__m128)_xmm, v7->m_motion.m_linearVelocity.m_quad);
      hkpEntity::activate(v7);
      v7->m_motion.vfptr[9].__vecDelDtor((hkBaseObject *)&v7->m_motion.vfptr, (unsigned int)&v18);
      v12 = v7->m_motion.m_angularVelocity.m_quad;
      v15 = v7->m_motion.m_angularVelocity.m_quad;
      v12.m128_f32[0] = hkpMotion::getMass((hkpMotion *)&v7->m_motion.vfptr);
      v13 = LODWORD(v4->m_deltaTime.m_storage);
      v12.m128_f32[0] = COERCE_FLOAT(COERCE_UNSIGNED_INT((float)(v8 * v5->mAngularDamping) * v12.m128_f32[0]) ^ _xmm[0]);
      v15 = _mm_mul_ps(v15, _mm_shuffle_ps(v12, v12, 0));
      hkpEntity::activate(v7);
      ((void (__fastcall *)(hkpMaxSizeMotion *, __int64, __m128 *))v7->m_motion.vfptr[13].__first_virtual_table_function__)(
        &v7->m_motion,
        v14,
        &v15);
    }
  }
}

