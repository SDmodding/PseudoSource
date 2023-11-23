// File Line: 62
// RVA: 0xDBFE60
void __fastcall hk4dGskCollideInitMatrices(
        hkp4dGskVertexCollidePointsInput *input,
        hkSimdFloat32 *Rt,
        hk4dGskCollideMatrices *out)
{
  hkStepInfo *m_storage; // rax
  __m128 m_storage_low; // xmm6
  hkSweptTransformf *p_m_sweptTransform; // rcx
  __int64 v8; // rcx
  hkVector4f *m_angularVel; // rax
  hkVector4f v10; // xmm2
  __m128 v11; // xmm1
  __m128 v12; // xmm3
  __m128 v13; // xmm5
  __m128 v14; // xmm4
  __m128 v15; // xmm1
  hkSimdFloat32 tAddOn; // [rsp+20h] [rbp-38h] BYREF
  hkSimdFloat32 t; // [rsp+30h] [rbp-28h] BYREF

  m_storage = input->m_stepInfo.m_storage;
  m_storage_low = (__m128)LODWORD(input->m_radiusSum.m_storage);
  p_m_sweptTransform = &input->m_motionA.m_storage->m_sweptTransform;
  tAddOn.m_real = _mm_mul_ps(
                    _mm_shuffle_ps(
                      (__m128)LODWORD(m_storage->m_deltaTime.m_storage),
                      (__m128)LODWORD(m_storage->m_deltaTime.m_storage),
                      0),
                    Rt->m_real);
  t.m_real = _mm_shuffle_ps(
               (__m128)LODWORD(m_storage->m_startTime.m_storage),
               (__m128)LODWORD(m_storage->m_startTime.m_storage),
               0);
  hkSweptTransformUtil::lerp2Ha(p_m_sweptTransform, &t, &tAddOn, &out->m_wTa);
  hkSweptTransformUtil::lerp2Ha(&input->m_motionB.m_storage->m_sweptTransform, &t, &tAddOn, &out->m_wTb);
  hkTransformf::setMulInverseMul(&out->m_aTb, &out->m_wTa, &out->m_wTb);
  hkVector4f::setRotatedDir(&out->m_plane, &out->m_aTb.m_rotation, &input->m_planeB);
  hkVector4f::setTransformedPos(&out->m_pointOnPlane, &out->m_aTb, &input->m_pointOnPlaneB);
  v8 = 2i64;
  out->m_plane.m_quad = _mm_shuffle_ps(
                          out->m_plane.m_quad,
                          _mm_unpackhi_ps(
                            out->m_plane.m_quad,
                            _mm_sub_ps((__m128)0i64, _mm_shuffle_ps(m_storage_low, m_storage_low, 0))),
                          196);
  m_angularVel = out->m_angularVel;
  out->m_massCenterAinA = input->m_motionA.m_storage->m_sweptTransform.m_centerOfMassLocal;
  v10.m_quad = (__m128)out->m_wTa.m_rotation.m_col2;
  v11 = _mm_unpacklo_ps(out->m_wTa.m_rotation.m_col0.m_quad, out->m_wTa.m_rotation.m_col1.m_quad);
  v12 = _mm_shuffle_ps(
          _mm_unpackhi_ps(out->m_wTa.m_rotation.m_col0.m_quad, out->m_wTa.m_rotation.m_col1.m_quad),
          v10.m_quad,
          228);
  v13 = _mm_movelh_ps(v11, v10.m_quad);
  v14 = _mm_shuffle_ps(_mm_movehl_ps(v13, v11), v10.m_quad, 212);
  do
  {
    v15 = *(__m128 *)((char *)&m_angularVel[-8].m_quad + (char *)input - (char *)out);
    ++m_angularVel;
    m_angularVel[-1].m_quad = _mm_add_ps(
                                _mm_add_ps(
                                  _mm_mul_ps(_mm_shuffle_ps(v15, v15, 85), v14),
                                  _mm_mul_ps(_mm_shuffle_ps(v15, v15, 0), v13)),
                                _mm_mul_ps(_mm_shuffle_ps(v15, v15, 170), v12));
    --v8;
  }
  while ( v8 );
  hkVector4f::setTransformedPos(
    &out->m_massCenterBinA,
    &out->m_aTb,
    &input->m_motionB.m_storage->m_sweptTransform.m_centerOfMassLocal);
  hkVector4f::setRotatedInverseDir(&out->m_linearVel, &out->m_wTa.m_rotation, &input->m_linearTimInfo);
}

// File Line: 350
// RVA: 0xDC0020
void __fastcall hk4dGskCollidePointWithPlaneFinal(
        hkp4dGskVertexCollidePointsInput *input,
        hkp4dGskTolerances *tol,
        hkVector4f *vertexA,
        hkSimdFloat32 *startRtIn,
        hkSimdFloat32 *endRtIn,
        hkSimdFloat32 *distance0In,
        hkSimdFloat32 *distance1In,
        hkSimdFloat32 *velocity,
        hkp4dGskVertexCollidePointsOutput *out,
        hkSimdFloat32 *toiOut)
{
  int v12; // ebx
  __m128 m_real; // xmm9
  __m128 v14; // xmm7
  float v15; // xmm11_4
  __m128 v16; // xmm12
  __m128 v17; // xmm8
  __m128 v18; // xmm6
  __m128 v19; // xmm10
  __m128 v20; // xmm1
  __m128 v21; // xmm3
  __m128 v22; // xmm1
  __m128 v23; // xmm0
  __m128 v24; // xmm2
  __m128 v25; // xmm2
  __m128 v26; // xmm0
  __m128 v27; // xmm3
  __m128 v28; // xmm2
  hkSimdFloat32 v29; // xmm0
  hkSimdFloat32 Rt; // [rsp+20h] [rbp-1B8h] BYREF
  hk4dGskCollideMatrices v31; // [rsp+30h] [rbp-1A8h] BYREF

  v12 = 0;
  m_real = startRtIn->m_real;
  v14 = _mm_shuffle_ps(
          (__m128)LODWORD(tol->m_toiSeparation.m_storage),
          (__m128)LODWORD(tol->m_toiSeparation.m_storage),
          0);
  v15 = _mm_shuffle_ps((__m128)LODWORD(tol->m_toiAccuracy.m_storage), (__m128)LODWORD(tol->m_toiAccuracy.m_storage), 0).m128_f32[0]
      * 0.25;
  v16 = endRtIn->m_real;
  v17 = startRtIn->m_real;
  v18 = distance0In->m_real;
  v19 = distance1In->m_real;
  do
  {
    if ( v18.m128_f32[0] <= v14.m128_f32[0] )
      break;
    v20 = _mm_sub_ps(v19, v18);
    if ( v20.m128_f32[0] > (float)(0.0 - v15) )
      break;
    v21 = _mm_div_ps(_mm_sub_ps(v14, v18), v20);
    if ( (v12 & 1) == 0 )
    {
      v22 = _mm_shuffle_ps((__m128)0x3F666666u, (__m128)0x3F666666u, 0);
      v23 = _mm_cmplt_ps(v21, v22);
      v21 = _mm_max_ps(
              _mm_shuffle_ps((__m128)0x3DCCCCCDu, (__m128)0x3DCCCCCDu, 0),
              _mm_or_ps(_mm_andnot_ps(v23, v22), _mm_and_ps(v21, v23)));
    }
    v17 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v16, m_real), v21), m_real);
    Rt.m_real = v17;
    hk4dGskCollideInitMatrices(input, &Rt, &v31);
    v24 = _mm_mul_ps(_mm_sub_ps(vertexA->m_quad, v31.m_pointOnPlane.m_quad), v31.m_plane.m_quad);
    v25 = _mm_shuffle_ps(v24, _mm_unpackhi_ps(v24, v31.m_plane.m_quad), 196);
    v26 = _mm_add_ps(_mm_shuffle_ps(v25, v25, 78), v25);
    v27 = _mm_add_ps(_mm_shuffle_ps(v26, v26, 177), v26);
    if ( COERCE_FLOAT((unsigned int)(2 * COERCE_INT(v27.m128_f32[0] - v14.m128_f32[0])) >> 1) < v15 )
      break;
    ++v12;
    v28 = _mm_cmplt_ps(v27, v14);
    m_real = _mm_or_ps(_mm_andnot_ps(v28, v17), _mm_and_ps(m_real, v28));
    v16 = _mm_or_ps(_mm_andnot_ps(v28, v16), _mm_and_ps(v17, v28));
    v19 = _mm_or_ps(_mm_and_ps(v27, v28), _mm_andnot_ps(v28, v19));
    v18 = _mm_or_ps(_mm_andnot_ps(v28, v27), _mm_and_ps(v28, v18));
  }
  while ( v12 < 10 );
  v29.m_real = _mm_shuffle_ps((__m128)LODWORD(out->m_Rtoi.m_storage), (__m128)LODWORD(out->m_Rtoi.m_storage), 0);
  if ( v17.m128_f32[0] >= v29.m_real.m128_f32[0] )
  {
    *toiOut = (hkSimdFloat32)v29.m_real;
  }
  else
  {
    LODWORD(out->m_Rtoi.m_storage) = v17.m128_i32[0];
    out->m_collidingPoint = (hkVector4f)vertexA->m_quad;
    *toiOut = (hkSimdFloat32)v17;
  }
}

// File Line: 460
// RVA: 0xDBE450
void __fastcall hk4dGskCollidePointsWithPlane(
        hkp4dGskVertexCollidePointsInput *input,
        hkp4dGskTolerances *tol,
        hkp4dGskVertexCollidePointsOutput *out)
{
  int m_storage; // r15d
  __m128 m_quad; // xmm7
  __m128 v8; // xmm12
  __m128 v9; // xmm13
  __m128 v10; // xmm15
  __m128 v11; // xmm14
  __m128 v12; // xmm6
  hkVector4f *v13; // rbx
  int v14; // r14d
  __m128 v15; // xmm8
  float v16; // xmm9_4
  int v17; // r14d
  hkVector4f *v18; // rdi
  float v19; // xmm11_4
  float v20; // xmm11_4
  __m128 v21; // xmm5
  __m128 v22; // xmm1
  __m128 v23; // xmm1
  __m128 v24; // xmm0
  __m128 v25; // xmm4
  __m128 v26; // xmm3
  __m128 v27; // xmm2
  __m128 v28; // xmm3
  __m128 v29; // xmm2
  __m128 v30; // xmm3
  __m128 v31; // xmm10
  __m128 v32; // xmm2
  hkVector4f v33; // xmm0
  __m128 v34; // xmm1
  __m128 v35; // xmm4
  __m128 v36; // xmm4
  __m128 v37; // xmm2
  __m128 v38; // xmm1
  __m128 v39; // xmm3
  __m128 v40; // xmm5
  __m128 v41; // xmm5
  __m128 v42; // xmm4
  _BYTE Rt[48]; // [rsp+50h] [rbp-88h] BYREF
  hk4dGskCollideMatrices outa; // [rsp+88h] [rbp-50h] BYREF
  float v45; // [rsp+288h] [rbp+1B0h]

  m_storage = input->m_numVertices.m_storage;
  m_quad = query.m_quad;
  v8 = _mm_shuffle_ps(
         (__m128)LODWORD(tol->m_toiSeparation.m_storage),
         (__m128)LODWORD(tol->m_toiSeparation.m_storage),
         0);
  v9 = _mm_shuffle_ps(
         (__m128)LODWORD(input->m_invMaxAccel.m_storage),
         (__m128)LODWORD(input->m_invMaxAccel.m_storage),
         0);
  *(hkVector4f *)&Rt[16] = (hkVector4f)query.m_quad;
  v10 = _mm_shuffle_ps((__m128)LODWORD(input->m_startRt.m_storage), (__m128)LODWORD(input->m_startRt.m_storage), 0);
  v11 = _mm_shuffle_ps(
          (__m128)LODWORD(tol->m_minSeparation.m_storage),
          (__m128)LODWORD(tol->m_minSeparation.m_storage),
          0);
  v12 = v10;
  *(__m128 *)&Rt[32] = v10;
  for ( *(__m128 *)Rt = v10; m_storage; *(__m128 *)Rt = v15 )
  {
    hk4dGskCollideInitMatrices(input, (hkSimdFloat32 *)Rt, &outa);
    v13 = input->m_verticesA.m_storage;
    v14 = m_storage;
    v15 = m_quad;
    v16 = m_quad.m128_f32[0] - v12.m128_f32[0];
    m_storage = 0;
    v17 = v14 - 1;
    v18 = v13;
    v19 = _mm_shuffle_ps(
            (__m128)LODWORD(input->m_worstCaseApproachingDelta.m_storage),
            (__m128)LODWORD(input->m_worstCaseApproachingDelta.m_storage),
            0).m128_f32[0]
        * (float)(m_quad.m128_f32[0] - v12.m128_f32[0]);
    if ( v17 >= 0 )
    {
      v20 = v19 + v8.m128_f32[0];
      do
      {
        v21 = v13->m_quad;
        v22 = _mm_mul_ps(_mm_sub_ps(v13->m_quad, outa.m_pointOnPlane.m_quad), outa.m_plane.m_quad);
        v23 = _mm_shuffle_ps(v22, _mm_unpackhi_ps(v22, outa.m_plane.m_quad), 196);
        v24 = _mm_add_ps(_mm_shuffle_ps(v23, v23, 78), v23);
        v25 = _mm_add_ps(_mm_shuffle_ps(v24, v24, 177), v24);
        *(__m128 *)&Rt[8] = v25;
        if ( v25.m128_f32[0] <= v20 )
        {
          v26 = _mm_sub_ps(v21, outa.m_massCenterAinA.m_quad);
          v27 = _mm_sub_ps(v21, outa.m_massCenterBinA.m_quad);
          v28 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v26, v26, 201), outa.m_angularVel[0].m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(outa.m_angularVel[0].m_quad, outa.m_angularVel[0].m_quad, 201), v26));
          v29 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v27, v27, 201), outa.m_angularVel[1].m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(outa.m_angularVel[1].m_quad, outa.m_angularVel[1].m_quad, 201), v27));
          v30 = _mm_mul_ps(
                  _mm_sub_ps(
                    _mm_sub_ps(_mm_shuffle_ps(v28, v28, 201), outa.m_linearVel.m_quad),
                    _mm_shuffle_ps(v29, v29, 201)),
                  outa.m_plane.m_quad);
          v31 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v30, v30, 85), _mm_shuffle_ps(v30, v30, 0)),
                  _mm_shuffle_ps(v30, v30, 170));
          v45 = input->m_maxAccel.m_storage;
          if ( (float)((float)(v25.m128_f32[0] - v8.m128_f32[0]) + (float)(v31.m128_f32[0] * v16)) <= (float)((float)((float)(v16 * 0.5) * v16) * _mm_shuffle_ps((__m128)LODWORD(v45), (__m128)LODWORD(v45), 0).m128_f32[0]) )
          {
            if ( v25.m128_f32[0] >= v8.m128_f32[0] )
            {
              v32 = v13->m_quad;
              v33.m_quad = v18->m_quad;
              ++v18;
              ++m_storage;
              *v13 = (hkVector4f)v33.m_quad;
              v34 = _mm_unpackhi_ps(v32, v25);
              v35 = _mm_mul_ps(_mm_sub_ps(v25, v11), v9);
              v18[-1].m_quad = _mm_shuffle_ps(v32, v34, 196);
              v36 = _mm_add_ps(v35, v35);
              if ( v36.m128_f32[0] <= (float)(v16 * v16) )
              {
                v37 = _mm_sqrt_ps(v36);
                v38 = _mm_cmple_ps((__m128)0i64, v31);
                v39 = _mm_mul_ps(v31, v9);
                v40 = _mm_mul_ps(_mm_sub_ps(v8, v11), v9);
                v41 = _mm_add_ps(v40, v40);
                v42 = _mm_or_ps(
                        _mm_andnot_ps(v38, _mm_max_ps(_mm_sub_ps((__m128)0i64, v39), v37)),
                        _mm_and_ps(_mm_add_ps(_mm_add_ps(v39, v39), v37), v38));
                if ( v42.m128_f32[0] <= v16 )
                {
                  v45 = tol->m_minSafeDeltaRt.m_storage;
                  v15 = _mm_min_ps(
                          v15,
                          _mm_add_ps(
                            _mm_max_ps(
                              _mm_add_ps(_mm_sqrt_ps(v41), v42),
                              _mm_shuffle_ps((__m128)LODWORD(v45), (__m128)LODWORD(v45), 0)),
                            v12));
                }
              }
            }
            else if ( v12.m128_f32[0] == v10.m128_f32[0] )
            {
              LODWORD(out->m_Rtoi.m_storage) = v12.m128_i32[0];
              m_quad = v12;
              out->m_collidingPoint = (hkVector4f)v13->m_quad;
              *(__m128 *)&Rt[16] = v12;
            }
            else
            {
              *(__m128 *)&Rt[24] = _mm_shuffle_ps(v21, v21, 255);
              hk4dGskCollidePointWithPlaneFinal(
                input,
                tol,
                v13,
                (hkSimdFloat32 *)&Rt[32],
                (hkSimdFloat32 *)Rt,
                (hkSimdFloat32 *)&Rt[24],
                (hkSimdFloat32 *)&Rt[8],
                (hkSimdFloat32 *)&Rt[40],
                out,
                (hkSimdFloat32 *)&Rt[16]);
              m_quad = *(__m128 *)&Rt[16];
            }
          }
        }
        ++v13;
        --v17;
      }
      while ( v17 >= 0 );
    }
    if ( v12.m128_f32[0] > m_quad.m128_f32[0]
      || v12.m128_f32[0] == v15.m128_f32[0] && v12.m128_f32[0] >= m_quad.m128_f32[0] )
    {
      break;
    }
    *(__m128 *)&Rt[32] = v12;
    v12 = v15;
  }
}

// File Line: 650
// RVA: 0xDC0270
void __fastcall hk4dGskCalcSeparatingNormal(
        hkTransformf *tA,
        hkTransformf *tB,
        hkpConvexShape *shapeA,
        hkpConvexShape *shapeB,
        hkpGsk *gsk,
        hkVector4f *separatingNormalOut,
        hkVector4f *pointOnBInB)
{
  __m128 m_quad; // xmm3
  hkVector4f v11; // xmm6
  __m128 v12; // xmm5
  __m128 v13; // xmm1
  __m128 v14; // xmm2
  __m128 v15; // xmm6
  unsigned int v16; // xmm0_4
  hkVector4f v17; // [rsp+30h] [rbp-68h] BYREF
  hkTransformf aTb; // [rsp+40h] [rbp-58h] BYREF

  hkTransformf::setMulInverseMul(&aTb, tA, tB);
  hkpGsk::getClosestFeature(gsk, shapeA, shapeB, &aTb, &v17);
  m_quad = v17.m_quad;
  separatingNormalOut->m_quad = _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_mul_ps(_mm_shuffle_ps(v17.m_quad, v17.m_quad, 85), tA->m_rotation.m_col1.m_quad),
                                    _mm_mul_ps(_mm_shuffle_ps(v17.m_quad, v17.m_quad, 0), tA->m_rotation.m_col0.m_quad)),
                                  _mm_mul_ps(_mm_shuffle_ps(v17.m_quad, v17.m_quad, 170), tA->m_rotation.m_col2.m_quad));
  if ( gsk->m_dimA.m_storage == 1 )
  {
    v11.m_quad = (__m128)gsk->m_verticesA[0];
  }
  else if ( gsk->m_dimB.m_storage == 1 )
  {
    v11.m_quad = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 255), m_quad), gsk->m_verticesBinA[0].m_quad);
  }
  else
  {
    v11.m_quad = (__m128)gsk->m_closestLineLineResult.m_closestPointA;
  }
  v12 = _mm_shuffle_ps(m_quad, m_quad, 255);
  v13 = _mm_unpacklo_ps(aTb.m_rotation.m_col0.m_quad, aTb.m_rotation.m_col1.m_quad);
  v14 = _mm_movelh_ps(v13, aTb.m_rotation.m_col2.m_quad);
  v15 = _mm_sub_ps(_mm_sub_ps(v11.m_quad, _mm_mul_ps(v12, m_quad)), aTb.m_translation.m_quad);
  pointOnBInB->m_quad = _mm_add_ps(
                          _mm_add_ps(
                            _mm_mul_ps(
                              _mm_shuffle_ps(v15, v15, 85),
                              _mm_shuffle_ps(_mm_movehl_ps(v14, v13), aTb.m_rotation.m_col2.m_quad, 212)),
                            _mm_mul_ps(_mm_shuffle_ps(v15, v15, 0), v14)),
                          _mm_mul_ps(
                            _mm_shuffle_ps(
                              _mm_unpackhi_ps(aTb.m_rotation.m_col0.m_quad, aTb.m_rotation.m_col1.m_quad),
                              aTb.m_rotation.m_col2.m_quad,
                              228),
                            _mm_shuffle_ps(v15, v15, 170)));
  *(float *)&v16 = shapeA->m_radius + shapeB->m_radius;
  separatingNormalOut->m_quad = _mm_shuffle_ps(
                                  separatingNormalOut->m_quad,
                                  _mm_unpackhi_ps(
                                    separatingNormalOut->m_quad,
                                    _mm_sub_ps(v12, _mm_shuffle_ps((__m128)v16, (__m128)v16, 0))),
                                  196);
}

// File Line: 673
// RVA: 0xDC03F0
void __fastcall hk4dGskCalcWorstCaseProjectedVelocity(
        hkMotionState *msA,
        hkMotionState *msB,
        hkVector4f *separatingNormal,
        hkVector4f *linearTimInfo,
        hkVector4f *deltaAngles,
        hkSimdFloat32 *realProjectedLinearDelta,
        hkSimdFloat32 *projectedAngularDelta)
{
  __m128 v7; // xmm2
  __m128 v8; // xmm3
  __m128 v9; // xmm3
  __m128 v10; // xmm3
  __m128 v11; // xmm8
  __m128 v12; // xmm8
  __m128 v13; // xmm4
  __m128 v14; // xmm8
  __m128 v15; // xmm2
  __m128 v16; // xmm3
  __m128 v17; // xmm1
  __m128 v18; // xmm2

  v7 = _mm_shuffle_ps(separatingNormal->m_quad, separatingNormal->m_quad, 201);
  v8 = _mm_sub_ps(
         _mm_mul_ps(deltaAngles->m_quad, v7),
         _mm_mul_ps(_mm_shuffle_ps(deltaAngles->m_quad, deltaAngles->m_quad, 201), separatingNormal->m_quad));
  v9 = _mm_shuffle_ps(v8, v8, 201);
  v10 = _mm_mul_ps(v9, v9);
  v11 = _mm_sub_ps(
          _mm_mul_ps(deltaAngles[1].m_quad, v7),
          _mm_mul_ps(_mm_shuffle_ps(deltaAngles[1].m_quad, deltaAngles[1].m_quad, 201), separatingNormal->m_quad));
  v12 = _mm_shuffle_ps(v11, v11, 201);
  v13 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)), _mm_shuffle_ps(v10, v10, 170));
  v14 = _mm_mul_ps(v12, v12);
  v15 = _mm_rsqrt_ps(v13);
  v16 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)), _mm_shuffle_ps(v14, v14, 170));
  v17 = _mm_rsqrt_ps(v16);
  projectedAngularDelta->m_real = _mm_add_ps(
                                    _mm_mul_ps(
                                      _mm_andnot_ps(
                                        _mm_cmple_ps(v16, (__m128)0i64),
                                        _mm_mul_ps(
                                          _mm_mul_ps(
                                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v17, v16), v17)),
                                            _mm_mul_ps(*(__m128 *)_xmm, v17)),
                                          v16)),
                                      _mm_shuffle_ps(
                                        (__m128)LODWORD(msB->m_objectRadius),
                                        (__m128)LODWORD(msB->m_objectRadius),
                                        0)),
                                    _mm_mul_ps(
                                      _mm_shuffle_ps(
                                        (__m128)LODWORD(msA->m_objectRadius),
                                        (__m128)LODWORD(msA->m_objectRadius),
                                        0),
                                      _mm_andnot_ps(
                                        _mm_cmple_ps(v13, (__m128)0i64),
                                        _mm_mul_ps(
                                          _mm_mul_ps(
                                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v15, v13), v15)),
                                            _mm_mul_ps(*(__m128 *)_xmm, v15)),
                                          v13))));
  v18 = _mm_mul_ps(separatingNormal->m_quad, linearTimInfo->m_quad);
  realProjectedLinearDelta->m_real = _mm_add_ps(
                                       _mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)),
                                       _mm_shuffle_ps(v18, v18, 170));
}

// File Line: 690
// RVA: 0xDC0560
void __fastcall hk4dGskCalcPointVelocity(
        hkMotionState *msA,
        hkMotionState *msB,
        hkVector4f *separatingPoint,
        hkVector4f *separatingNormal,
        hkVector4f *linearTimInfo,
        hkVector4f *deltaAngles,
        hkSimdFloat32 *t,
        hkSimdFloat32 *separatingVelocity)
{
  __m128 v8; // xmm1
  __m128 v9; // xmm3
  __m128 v10; // xmm5
  __m128 v11; // xmm1
  __m128 v12; // xmm2

  v8 = _mm_sub_ps(
         separatingPoint->m_quad,
         _mm_add_ps(
           _mm_mul_ps(
             _mm_mul_ps(
               _mm_sub_ps(
                 t->m_real,
                 _mm_shuffle_ps(
                   msA->m_sweptTransform.m_centerOfMass0.m_quad,
                   msA->m_sweptTransform.m_centerOfMass0.m_quad,
                   255)),
               _mm_shuffle_ps(
                 msA->m_sweptTransform.m_centerOfMass1.m_quad,
                 msA->m_sweptTransform.m_centerOfMass1.m_quad,
                 255)),
             _mm_sub_ps(msA->m_sweptTransform.m_centerOfMass1.m_quad, msA->m_sweptTransform.m_centerOfMass0.m_quad)),
           msA->m_sweptTransform.m_centerOfMass0.m_quad));
  v9 = _mm_sub_ps(
         _mm_mul_ps(_mm_shuffle_ps(v8, v8, 201), deltaAngles->m_quad),
         _mm_mul_ps(_mm_shuffle_ps(deltaAngles->m_quad, deltaAngles->m_quad, 201), v8));
  v10 = _mm_sub_ps(
          separatingPoint->m_quad,
          _mm_add_ps(
            _mm_mul_ps(
              _mm_mul_ps(
                _mm_sub_ps(
                  t->m_real,
                  _mm_shuffle_ps(
                    msB->m_sweptTransform.m_centerOfMass0.m_quad,
                    msB->m_sweptTransform.m_centerOfMass0.m_quad,
                    255)),
                _mm_shuffle_ps(
                  msB->m_sweptTransform.m_centerOfMass1.m_quad,
                  msB->m_sweptTransform.m_centerOfMass1.m_quad,
                  255)),
              _mm_sub_ps(msB->m_sweptTransform.m_centerOfMass1.m_quad, msB->m_sweptTransform.m_centerOfMass0.m_quad)),
            msB->m_sweptTransform.m_centerOfMass0.m_quad));
  v11 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), deltaAngles[1].m_quad),
          _mm_mul_ps(_mm_shuffle_ps(deltaAngles[1].m_quad, deltaAngles[1].m_quad, 201), v10));
  v12 = _mm_mul_ps(
          _mm_sub_ps(
            _mm_add_ps(
              _mm_xor_ps(
                (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                linearTimInfo->m_quad),
              _mm_shuffle_ps(v9, v9, 201)),
            _mm_shuffle_ps(v11, v11, 201)),
          separatingNormal->m_quad);
  separatingVelocity->m_real = _mm_add_ps(
                                 _mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)),
                                 _mm_shuffle_ps(v12, v12, 170));
}

// File Line: 714
// RVA: 0xDC0650
void __fastcall hk4dGskCalcPointVelocityAssumingAngularVelError(
        hkMotionState *msA,
        hkMotionState *msB,
        hkVector4f *separatingPoint,
        hkVector4f *separatingNormal,
        hkVector4f *linearTimInfo,
        hkVector4f *deltaAngles,
        hkSimdFloat32 *t,
        hkSimdFloat32 *separatingVelocity)
{
  __m128 v8; // xmm7
  __m128 v9; // xmm1
  __m128 v10; // xmm6
  __m128 v11; // xmm1
  __m128 v12; // xmm3
  __m128 v13; // xmm3
  __m128 v14; // xmm2
  __m128 v15; // xmm0
  __m128 v16; // xmm4
  __m128 v17; // xmm1
  __m128 v18; // xmm2
  __m128 v19; // xmm2
  __m128 v20; // xmm1
  __m128 v21; // xmm5

  v8 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_1_2), (__m128)LODWORD(FLOAT_1_2), 0);
  v9 = _mm_mul_ps(
         _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), linearTimInfo->m_quad),
         separatingNormal->m_quad);
  v10 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)), _mm_shuffle_ps(v9, v9, 170));
  *separatingVelocity = (hkSimdFloat32)v10;
  v11 = _mm_sub_ps(
          separatingPoint->m_quad,
          _mm_add_ps(
            _mm_mul_ps(
              _mm_mul_ps(
                _mm_sub_ps(
                  t->m_real,
                  _mm_shuffle_ps(
                    msA->m_sweptTransform.m_centerOfMass0.m_quad,
                    msA->m_sweptTransform.m_centerOfMass0.m_quad,
                    255)),
                _mm_shuffle_ps(
                  msA->m_sweptTransform.m_centerOfMass1.m_quad,
                  msA->m_sweptTransform.m_centerOfMass1.m_quad,
                  255)),
              _mm_sub_ps(msA->m_sweptTransform.m_centerOfMass1.m_quad, msA->m_sweptTransform.m_centerOfMass0.m_quad)),
            msA->m_sweptTransform.m_centerOfMass0.m_quad));
  v12 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v11, v11, 201), deltaAngles->m_quad),
          _mm_mul_ps(_mm_shuffle_ps(deltaAngles->m_quad, deltaAngles->m_quad, 201), v11));
  v13 = _mm_mul_ps(_mm_shuffle_ps(v12, v12, 201), separatingNormal->m_quad);
  v14 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)), _mm_shuffle_ps(v13, v13, 170));
  v15 = _mm_cmple_ps(v14, (__m128)0i64);
  v16 = _mm_add_ps(_mm_or_ps(_mm_and_ps(_mm_mul_ps(v8, v14), v15), _mm_andnot_ps(v15, _mm_div_ps(v14, v8))), v10);
  *separatingVelocity = (hkSimdFloat32)v16;
  v17 = _mm_sub_ps(
          separatingPoint->m_quad,
          _mm_add_ps(
            _mm_mul_ps(
              _mm_mul_ps(
                _mm_sub_ps(
                  t->m_real,
                  _mm_shuffle_ps(
                    msB->m_sweptTransform.m_centerOfMass0.m_quad,
                    msB->m_sweptTransform.m_centerOfMass0.m_quad,
                    255)),
                _mm_shuffle_ps(
                  msB->m_sweptTransform.m_centerOfMass1.m_quad,
                  msB->m_sweptTransform.m_centerOfMass1.m_quad,
                  255)),
              _mm_sub_ps(msB->m_sweptTransform.m_centerOfMass1.m_quad, msB->m_sweptTransform.m_centerOfMass0.m_quad)),
            msB->m_sweptTransform.m_centerOfMass0.m_quad));
  v18 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v17, v17, 201), deltaAngles[1].m_quad),
          _mm_mul_ps(_mm_shuffle_ps(deltaAngles[1].m_quad, deltaAngles[1].m_quad, 201), v17));
  v19 = _mm_mul_ps(_mm_shuffle_ps(v18, v18, 201), separatingNormal->m_quad);
  v20 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)), _mm_shuffle_ps(v19, v19, 170));
  v21 = _mm_cmple_ps((__m128)0i64, v20);
  separatingVelocity->m_real = _mm_sub_ps(
                                 v16,
                                 _mm_or_ps(
                                   _mm_and_ps(_mm_mul_ps(v8, v20), v21),
                                   _mm_andnot_ps(v21, _mm_div_ps(v20, v8))));
}

// File Line: 765
// RVA: 0xDC07F0
void __fastcall hk4dGskCollPInputInitialize(hkpAgent3ProcessInput *in3, hkp4dGskVertexCollidePointsInput *collPInput)
{
  hkpCdBody *m_storage; // rax
  hkpShape *m_shape; // r9
  hkMotionState *m_motion; // r14
  float *v6; // rsi
  hkMotionState *v7; // rbp
  int v8; // eax
  int v9; // ebx
  hkLifoAllocator *Value; // rax
  hkVector4f *m_cur; // rdx
  int v12; // ebx
  char *v13; // rcx
  float v14; // xmm2_4
  float v15; // xmm1_4
  float v16; // xmm2_4

  m_storage = in3->m_bodyB.m_storage;
  m_shape = m_storage->m_shape;
  m_motion = (hkMotionState *)m_storage->m_motion;
  v6 = (float *)in3->m_bodyA.m_storage->m_shape;
  v7 = (hkMotionState *)in3->m_bodyA.m_storage->m_motion;
  collPInput->m_motionB.m_storage = m_motion;
  collPInput->m_motionA.m_storage = v7;
  collPInput->m_radiusSum.m_storage = *(float *)&m_shape[1].vfptr + v6[8];
  collPInput->m_linearTimInfo = in3->m_linearTimInfo;
  collPInput->m_stepInfo.m_storage = &in3->m_input.m_storage->m_stepInfo;
  v8 = (*(__int64 (__fastcall **)(float *))(*(_QWORD *)v6 + 88i64))(v6);
  collPInput->m_allocatedNumVertices.m_storage = v8;
  collPInput->m_numVertices.m_storage = v8;
  v9 = v8;
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (hkVector4f *)Value->m_cur;
  v12 = (16 * v9 + 127) & 0xFFFFFF80;
  v13 = (char *)m_cur + v12;
  if ( v12 > Value->m_slabSize || v13 > Value->m_end )
    m_cur = (hkVector4f *)hkLifoAllocator::allocateFromNewSlab(Value, v12);
  else
    Value->m_cur = v13;
  collPInput->m_verticesA.m_storage = m_cur;
  (*(void (__fastcall **)(float *))(*(_QWORD *)v6 + 96i64))(v6);
  v14 = _mm_shuffle_ps(collPInput->m_deltaAngles[1].m_quad, collPInput->m_deltaAngles[1].m_quad, 255).m128_f32[0];
  v15 = _mm_shuffle_ps(collPInput->m_deltaAngles[0].m_quad, collPInput->m_deltaAngles[0].m_quad, 255).m128_f32[0];
  v16 = (float)((float)(v14 * v14)
              * _mm_shuffle_ps((__m128)LODWORD(m_motion->m_objectRadius), (__m128)LODWORD(m_motion->m_objectRadius), 0).m128_f32[0])
      + (float)((float)(v15 * v15)
              * _mm_shuffle_ps((__m128)LODWORD(v7->m_objectRadius), (__m128)LODWORD(v7->m_objectRadius), 0).m128_f32[0]);
  collPInput->m_maxAccel.m_storage = v16;
  collPInput->m_invMaxAccel.m_storage = 1.0 / (float)(v16 + 1.4210855e-14);
}

// File Line: 815
// RVA: 0xDC0930
void __fastcall hk4dGskCalcToiFinal(
        hkpAgent3ProcessInput *in3,
        hkp4dGskTolerances *tol,
        hkpGsk *gsk,
        int featureChange,
        hkVector4f *oldMasterNormal,
        hkVector4f *deltaAngles,
        hkSimdFloat32 *startRtIn,
        hkSimdFloat32 *endRtIn,
        hkSimdFloat32 *distance0In,
        hkSimdFloat32 *distance1In,
        hkpProcessCollisionOutput *out)
{
  hkVector4f *v11; // rbx
  int v16; // r14d
  __m128 v17; // xmm3
  __m128 v18; // xmm13
  __m128 v19; // xmm12
  __m128 v20; // xmm9
  __m128 v21; // xmm11
  __m128 m_quad; // xmm10
  __m128 v23; // xmm15
  __m128 v24; // xmm14
  __m128 v25; // xmm15
  __m128 v26; // xmm1
  __m128 v27; // xmm2
  __m128 v28; // xmm8
  __m128 v29; // xmm7
  __m128 v30; // xmm3
  char v31; // bl
  __m128 v32; // xmm1
  __m128 v33; // xmm4
  __m128 v34; // xmm0
  hkpProcessCollisionInput *m_storage; // rax
  __m128 m_storage_low; // xmm0
  hkpCdBody *v37; // rax
  __m128 v38; // xmm5
  __m128 v39; // xmm4
  hkVector4f v40; // xmm3
  hkVector4f v41; // xmm4
  __int64 v42; // rdx
  hkVector4f v43; // xmm5
  hkVector4f v44; // xmm6
  hkcdVertex *v45; // rcx
  __m128 v46; // xmm1
  int v47; // r9d
  int v48; // r8d
  __m128 v49; // xmm1
  __m128 v50; // xmm2
  __m128 v51; // xmm6
  __m128 v52; // xmm2
  unsigned int *v53; // r15
  hkVector4f *v54; // r14
  float v55; // xmm15_4
  __m128 v56; // xmm2
  __m128 v57; // xmm10
  hkpCdBody *v58; // rax
  hkpCdBody *v59; // r8
  hkpShape *m_shape; // r11
  int v61; // edx
  __m128 v62; // xmm9
  __m128 v63; // xmm8
  __m128 v64; // xmm9
  hkpShape *v65; // r10
  unsigned __int8 v66; // cl
  __int16 v67; // ax
  __int16 v68; // dx
  hkBaseObjectVtbl *vfptr; // rax
  int v70; // eax
  unsigned __int8 v71; // cl
  __int16 v72; // ax
  __int16 v73; // dx
  hkBaseObjectVtbl *v74; // r10
  __m128 v75; // xmm6
  hkpCdBody *v76; // r8
  hkpCdBody *v77; // r9
  hkMotionState *m_motion; // rbx
  hkMotionState *v79; // r12
  hkVector4f *p_m_linearTimInfo; // rax
  __m128 v81; // xmm5
  __m128 v82; // xmm13
  __m128 v83; // xmm4
  __m128 v84; // xmm4
  __m128 v85; // xmm6
  __m128 v86; // xmm8
  __m128 v87; // xmm8
  __m128 v88; // xmm1
  __m128 v89; // xmm11
  hkpProcessCollisionInput *v90; // rcx
  __m128 v91; // xmm2
  __m128 v92; // xmm1
  __m128 v93; // xmm5
  __m128 v94; // xmm1
  __m128 v95; // xmm0
  __m128 v96; // xmm1
  __m128 v97; // xmm9
  __m128 v98; // xmm2
  __m128 v99; // xmm1
  __m128 v100; // xmm2
  __m128 v101; // xmm6
  __m128 v102; // xmm2
  __m128 v103; // xmm3
  __m128 v104; // xmm7
  __m128 v105; // xmm4
  float *v106; // rdx
  hkpShape *v107; // rax
  hkLifoAllocator *Value; // rax
  hkVector4f *m_cur; // rdx
  int v110; // r8d
  char *v111; // rcx
  float v112; // xmm0_4
  float v113; // xmm1_4
  float v114; // xmm2_4
  float v115; // xmm0_4
  __m128 v116; // xmm1
  float v117; // xmm0_4
  __m128 v118; // xmm2
  hkVector4f *v119; // r12
  signed int v120; // ebx
  hkLifoAllocator *v121; // rax
  int v122; // r8d
  unsigned int v123; // xmm0_4
  hkpContactMgr *v124; // rcx
  hkpProcessCollisionInput *v125; // r9
  int v126; // eax
  int v127; // xmm6_4
  hkVector4f v128; // xmm0
  hkVector4f v129; // xmm1
  __int128 v130; // xmm0
  __int128 v131; // xmm1
  __int128 v132; // xmm0
  __int128 v133; // xmm1
  hkVector4f v134; // xmm0
  _BYTE tAddOn[56]; // [rsp+50h] [rbp-88h] BYREF
  hkVector4f pointA; // [rsp+88h] [rbp-50h] BYREF
  hkp4dGskVertexCollidePointsOutput v137; // [rsp+98h] [rbp-40h] BYREF
  hkTransformf transformOut; // [rsp+B8h] [rbp-20h] BYREF
  __int128 v139; // [rsp+F8h] [rbp+20h] BYREF
  __int128 v140; // [rsp+108h] [rbp+30h]
  __int128 v141; // [rsp+118h] [rbp+40h]
  __int128 v142; // [rsp+128h] [rbp+50h]
  hkp4dGskVertexCollidePointsInput input; // [rsp+138h] [rbp+60h] BYREF
  hkSimdFloat32 v144; // [rsp+1D8h] [rbp+100h] BYREF
  hkTransformf bTc; // [rsp+1E8h] [rbp+110h] BYREF
  hkTransformf aTb; // [rsp+228h] [rbp+150h] BYREF
  hkp4dGskTolerances *tola; // [rsp+340h] [rbp+268h] BYREF
  __m128 *retaddr; // [rsp+358h] [rbp+280h]
  hkVector4f *v149; // [rsp+360h] [rbp+288h]
  hkp4dGskTolerances *v150; // [rsp+368h] [rbp+290h] BYREF
  __m128 *v151; // [rsp+370h] [rbp+298h] BYREF
  __m128 *v152; // [rsp+378h] [rbp+2A0h]

  v150 = tol;
  v16 = 0;
  v17 = *v151;
  v18 = _mm_shuffle_ps((__m128)LODWORD(tol->m_toiAccuracy.m_storage), (__m128)LODWORD(tol->m_toiAccuracy.m_storage), 0);
  v19 = _mm_shuffle_ps(
          (__m128)LODWORD(tol->m_toiSeparation.m_storage),
          (__m128)LODWORD(tol->m_toiSeparation.m_storage),
          0);
  v20 = *(__m128 *)&tol->m_toiSeparation.m_storage;
  v149 = v11;
  v21 = *v152;
  m_quad = oldMasterNormal->m_quad;
  v23 = _mm_sub_ps(oldMasterNormal->m_quad, *v152);
  *(float *)&v151 = *(float *)&in3->m_bodyA.m_storage->m_shape[1].vfptr
                  + *(float *)&in3->m_bodyB.m_storage->m_shape[1].vfptr;
  v24 = _mm_shuffle_ps((__m128)(unsigned int)v151, (__m128)(unsigned int)v151, 0);
  *(__m128 *)&v137.m_Rtoi.m_storage = _mm_div_ps(v23, _mm_sub_ps(v17, v20));
  v25 = _mm_sub_ps((__m128)0i64, v18);
  do
  {
    v26 = _mm_sub_ps(m_quad, v21);
    v27 = _mm_cmplt_ps(v25, v26);
    v28 = _mm_or_ps(_mm_and_ps(v20, v27), _mm_andnot_ps(v27, v17));
    v29 = v28;
    v30 = _mm_or_ps(_mm_andnot_ps(v27, v26), _mm_and_ps(v27, (__m128)xmmword_141A711B0));
    if ( COERCE_FLOAT((unsigned int)(2 * COERCE_INT(m_quad.m128_f32[0] - v19.m128_f32[0])) >> 1) >= v18.m128_f32[0] )
    {
      LODWORD(v151) = 1063675494;
      LODWORD(v150) = 1036831949;
      v31 = 0;
      v32 = _mm_shuffle_ps((__m128)0x3F666666u, (__m128)0x3F666666u, 0);
      v33 = _mm_div_ps(_mm_sub_ps(v19, v21), v30);
      v34 = _mm_cmplt_ps(v33, v32);
      v29 = _mm_add_ps(
              _mm_mul_ps(
                _mm_sub_ps(v28, v20),
                _mm_max_ps(
                  _mm_shuffle_ps((__m128)0x3DCCCCCDu, (__m128)0x3DCCCCCDu, 0),
                  _mm_or_ps(_mm_andnot_ps(v34, v32), _mm_and_ps(v33, v34)))),
              v20);
    }
    else
    {
      v31 = 1;
      featureChange = 0;
    }
    m_storage = in3->m_input.m_storage;
    *(__m128 *)tAddOn = _mm_mul_ps(
                          _mm_shuffle_ps(
                            (__m128)LODWORD(m_storage->m_stepInfo.m_deltaTime.m_storage),
                            (__m128)LODWORD(m_storage->m_stepInfo.m_deltaTime.m_storage),
                            0),
                          v29);
    m_storage_low = (__m128)LODWORD(m_storage->m_stepInfo.m_startTime.m_storage);
    v37 = in3->m_bodyA.m_storage;
    *(__m128 *)&tAddOn[16] = _mm_shuffle_ps(m_storage_low, m_storage_low, 0);
    hkSweptTransformUtil::lerp2Ha(
      (hkSweptTransformf *)((char *)v37->m_motion + 64),
      (hkSimdFloat32 *)&tAddOn[16],
      (hkSimdFloat32 *)tAddOn,
      &transformOut);
    hkSweptTransformUtil::lerp2Ha(
      (hkSweptTransformf *)((char *)in3->m_bodyB.m_storage->m_motion + 64),
      (hkSimdFloat32 *)&tAddOn[16],
      (hkSimdFloat32 *)tAddOn,
      &bTc);
    hkTransformf::setMulInverseMul(&aTb, &transformOut, &bTc);
    if ( !featureChange )
    {
      v40.m_quad = (__m128)aTb.m_translation;
      v41.m_quad = (__m128)aTb.m_rotation.m_col2;
      v42 = gsk->m_dimB.m_storage - 1;
      v43.m_quad = (__m128)aTb.m_rotation.m_col1;
      v44.m_quad = (__m128)aTb.m_rotation.m_col0;
      v45 = &gsk->m_verticesBinB[v42];
      do
      {
        v46 = v45->m_quad;
        --v45;
        --v42;
        v45[-3].m_quad = _mm_add_ps(
                           _mm_add_ps(
                             _mm_add_ps(
                               _mm_mul_ps(_mm_shuffle_ps(v46, v46, 85), v43.m_quad),
                               _mm_mul_ps(_mm_shuffle_ps(v46, v46, 0), v44.m_quad)),
                             _mm_mul_ps(_mm_shuffle_ps(v46, v46, 170), v41.m_quad)),
                           v40.m_quad);
      }
      while ( v42 >= 0 );
      v47 = gsk->m_dimB.m_storage;
      v48 = gsk->m_dimA.m_storage;
      v49 = _mm_unpacklo_ps(transformOut.m_rotation.m_col0.m_quad, transformOut.m_rotation.m_col1.m_quad);
      v50 = _mm_movelh_ps(v49, transformOut.m_rotation.m_col2.m_quad);
      *(__m128 *)&tAddOn[40] = _mm_add_ps(
                                 _mm_add_ps(
                                   _mm_mul_ps(
                                     _mm_shuffle_ps(_mm_movehl_ps(v50, v49), transformOut.m_rotation.m_col2.m_quad, 212),
                                     _mm_shuffle_ps(*retaddr, *retaddr, 85)),
                                   _mm_mul_ps(_mm_shuffle_ps(*retaddr, *retaddr, 0), v50)),
                                 _mm_mul_ps(
                                   _mm_shuffle_ps(*retaddr, *retaddr, 170),
                                   _mm_shuffle_ps(
                                     _mm_unpackhi_ps(
                                       transformOut.m_rotation.m_col0.m_quad,
                                       transformOut.m_rotation.m_col1.m_quad),
                                     transformOut.m_rotation.m_col2.m_quad,
                                     228)));
      hkGskRecalcContactInternal(
        &gsk->m_verticesA[0],
        gsk->m_verticesBinA,
        v48,
        v47,
        (hkVector4f *)&tAddOn[40],
        &pointA,
        (hkVector4f *)&tAddOn[24]);
      v38 = pointA.m_quad;
      goto LABEL_15;
    }
    hkpGsk::getClosestFeature(
      gsk,
      (hkpConvexShape *)in3->m_bodyA.m_storage->m_shape,
      (hkpConvexShape *)in3->m_bodyB.m_storage->m_shape,
      &aTb,
      (hkVector4f *)&tAddOn[24]);
    if ( gsk->m_dimA.m_storage == 1 )
    {
      v38 = gsk->m_verticesA[0].m_quad;
      pointA.m_quad = v38;
LABEL_15:
      v39 = *(__m128 *)&tAddOn[24];
      goto LABEL_16;
    }
    v39 = *(__m128 *)&tAddOn[24];
    if ( gsk->m_dimB.m_storage == 1 )
      v38 = _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&tAddOn[24], *(__m128 *)&tAddOn[24], 255), *(__m128 *)&tAddOn[24]),
              gsk->m_verticesBinA[0].m_quad);
    else
      v38 = gsk->m_closestLineLineResult.m_closestPointA.m_quad;
    pointA.m_quad = v38;
LABEL_16:
    v51 = _mm_sub_ps(_mm_shuffle_ps(v39, v39, 255), v24);
    if ( COERCE_FLOAT((unsigned int)(2 * COERCE_INT(v51.m128_f32[0] - v19.m128_f32[0])) >> 1) < v18.m128_f32[0] )
      break;
    if ( v31 )
      break;
    if ( v20.m128_f32[0] == v28.m128_f32[0] )
      break;
    ++v16;
    v52 = _mm_cmplt_ps(v51, v19);
    v17 = _mm_or_ps(_mm_and_ps(v52, v29), _mm_andnot_ps(v52, v28));
    v20 = _mm_or_ps(_mm_andnot_ps(v52, v29), _mm_and_ps(v52, v20));
    v21 = _mm_or_ps(_mm_andnot_ps(v52, v51), _mm_and_ps(v52, v21));
    m_quad = _mm_or_ps(_mm_and_ps(v52, v51), _mm_andnot_ps(v52, m_quad));
  }
  while ( v16 < 10 );
  v53 = (unsigned int *)in3->m_input.m_storage;
  v54 = deltaAngles;
  v55 = v137.m_Rtoi.m_storage;
  v56 = _mm_shuffle_ps(
          (__m128)LODWORD(tol->m_minToiDeltaTime.m_storage),
          (__m128)LODWORD(tol->m_minToiDeltaTime.m_storage),
          0);
  LODWORD(v151) = v53[26];
  v57 = _mm_add_ps(
          _mm_max_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)(unsigned int)v151, (__m128)(unsigned int)v151, 0), v29), v56),
          _mm_shuffle_ps((__m128)v53[24], (__m128)v53[24], 0));
  LODWORD(v151) = deltaAngles[771].m_quad.m128_i32[0];
  v144.m_real = v57;
  if ( v57.m128_f32[0] < _mm_shuffle_ps((__m128)(unsigned int)v151, (__m128)(unsigned int)v151, 0).m128_f32[0] )
  {
    LODWORD(v151) = v53[25];
    if ( v57.m128_f32[0] < (float)(_mm_shuffle_ps((__m128)(unsigned int)v151, (__m128)(unsigned int)v151, 0).m128_f32[0]
                                 - v56.m128_f32[0]) )
    {
      v58 = in3->m_bodyA.m_storage;
      v59 = in3->m_bodyB.m_storage;
      m_shape = in3->m_bodyA.m_storage->m_shape;
      v61 = 2;
      v62 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v39, v39, 85), transformOut.m_rotation.m_col1.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v39, v39, 0), transformOut.m_rotation.m_col0.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v39, v39, 170), transformOut.m_rotation.m_col2.m_quad));
      v63 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v38, v38, 85), transformOut.m_rotation.m_col1.m_quad),
                    _mm_mul_ps(_mm_shuffle_ps(v38, v38, 0), transformOut.m_rotation.m_col0.m_quad)),
                  _mm_mul_ps(_mm_shuffle_ps(v38, v38, 170), transformOut.m_rotation.m_col2.m_quad)),
                transformOut.m_translation.m_quad),
              _mm_mul_ps(
                _mm_sub_ps(
                  _mm_sub_ps(
                    (__m128)0i64,
                    _mm_shuffle_ps((__m128)LODWORD(m_shape[1].vfptr), (__m128)LODWORD(m_shape[1].vfptr), 0)),
                  v51),
                v62));
      v64 = _mm_shuffle_ps(v62, _mm_unpackhi_ps(v62, v51), 196);
      *(__m128 *)&tAddOn[32] = v63;
      *(_QWORD *)&tAddOn[16] = v64.m128_u64[1];
      *(__m128 *)tAddOn = v64;
      v65 = v59->m_shape;
      if ( v59->m_shape->m_type.m_storage == 2 )
      {
        v66 = gsk->m_dimB.m_storage;
        LOWORD(v150) = gsk->m_verticesBinB[0].m_quad.m128_i16[6];
        v67 = -1;
        v68 = -1;
        LOBYTE(v151) = v66;
        if ( v66 >= 2u )
          v68 = gsk->m_verticesBinB[1].m_quad.m128_i16[6];
        WORD1(v150) = v68;
        if ( v66 >= 3u )
          v67 = gsk->m_verticesBinB[2].m_quad.m128_i16[6];
        WORD2(v150) = v67;
        vfptr = v65->vfptr;
        *(__m128 *)&tAddOn[16] = v63;
        v70 = ((__int64 (__fastcall *)(hkpShape *, hkp4dGskTolerances **, __m128 **, _BYTE *, hkTransformf *, hkpShape *, hkTransformf *, _BYTE *))vfptr[6].__first_virtual_table_function__)(
                v65,
                &v150,
                &v151,
                &tAddOn[16],
                &bTc,
                m_shape,
                &transformOut,
                tAddOn);
        v63 = *(__m128 *)&tAddOn[16];
        v64 = *(__m128 *)tAddOn;
        *(_OWORD *)&tAddOn[32] = *(_OWORD *)&tAddOn[16];
        goto LABEL_34;
      }
      if ( v58->m_shape->m_type.m_storage != 2 )
        goto LABEL_36;
      v71 = gsk->m_dimA.m_storage;
      LOWORD(v150) = gsk->m_verticesA[0].m_quad.m128_i16[6];
      v72 = -1;
      v73 = -1;
      LOBYTE(v151) = v71;
      if ( v71 >= 2u )
        v73 = gsk->m_verticesA[1].m_quad.m128_i16[6];
      WORD1(v150) = v73;
      if ( v71 >= 3u )
        v72 = gsk->m_verticesA[2].m_quad.m128_i16[6];
      v74 = m_shape->vfptr;
      WORD2(v150) = v72;
      *(__m128 *)&v137.m_Rtoi.m_storage = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v64, v64, 255), v64), v63);
      v75 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64);
      *(__m128 *)tAddOn = _mm_xor_ps(v64, v75);
      v70 = ((__int64 (__fastcall *)(hkpShape *, hkp4dGskTolerances **, __m128 **, hkp4dGskVertexCollidePointsOutput *, hkTransformf *, hkpShape *, hkTransformf *, _BYTE *))v74[6].__first_virtual_table_function__)(
              m_shape,
              &v150,
              &v151,
              &v137,
              &transformOut,
              v59->m_shape,
              &bTc,
              tAddOn);
      v63 = *(__m128 *)&tAddOn[32];
      v64 = _mm_xor_ps(*(__m128 *)tAddOn, v75);
      *(__m128 *)tAddOn = v64;
LABEL_34:
      *(__m128 *)&tAddOn[8] = v64;
      v61 = v70;
      if ( v70 || !in3->m_input.m_storage->m_collisionQualityInfo.m_storage->m_enableToiWeldRejection.m_bool )
      {
LABEL_36:
        v76 = in3->m_bodyA.m_storage;
        v77 = in3->m_bodyB.m_storage;
        m_motion = (hkMotionState *)in3->m_bodyA.m_storage->m_motion;
        v79 = (hkMotionState *)v77->m_motion;
        p_m_linearTimInfo = &in3->m_linearTimInfo;
        v81 = m_motion->m_sweptTransform.m_centerOfMass1.m_quad;
        v82 = in3->m_linearTimInfo.m_quad;
        v83 = _mm_sub_ps(
                v63,
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_sub_ps(
                        v57,
                        _mm_shuffle_ps(
                          m_motion->m_sweptTransform.m_centerOfMass0.m_quad,
                          m_motion->m_sweptTransform.m_centerOfMass0.m_quad,
                          255)),
                      _mm_shuffle_ps(v81, v81, 255)),
                    _mm_sub_ps(v81, m_motion->m_sweptTransform.m_centerOfMass0.m_quad)),
                  m_motion->m_sweptTransform.m_centerOfMass0.m_quad));
        v84 = _mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(v83, v83, 201), v149->m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v149->m_quad, v149->m_quad, 201), v83));
        v85 = v79->m_sweptTransform.m_centerOfMass1.m_quad;
        v86 = _mm_sub_ps(
                v63,
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_sub_ps(
                        v57,
                        _mm_shuffle_ps(
                          v79->m_sweptTransform.m_centerOfMass0.m_quad,
                          v79->m_sweptTransform.m_centerOfMass0.m_quad,
                          255)),
                      _mm_shuffle_ps(v85, v85, 255)),
                    _mm_sub_ps(v85, v79->m_sweptTransform.m_centerOfMass0.m_quad)),
                  v79->m_sweptTransform.m_centerOfMass0.m_quad));
        v87 = _mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(v86, v86, 201), v149[1].m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v149[1].m_quad, v149[1].m_quad, 201), v86));
        v88 = _mm_mul_ps(
                _mm_sub_ps(
                  _mm_add_ps(
                    _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v82),
                    _mm_shuffle_ps(v84, v84, 201)),
                  _mm_shuffle_ps(v87, v87, 201)),
                v64);
        v89 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v88, v88, 85), _mm_shuffle_ps(v88, v88, 0)),
                _mm_shuffle_ps(v88, v88, 170));
        *(__m128 *)&tAddOn[16] = v89;
        if ( v61 == 1 && v89.m128_f32[0] > (float)(0.0 - 0.00000011920929) )
        {
          v90 = in3->m_input.m_storage;
          LODWORD(input.m_startRt.m_storage) = v29.m128_i32[0];
          v91 = _mm_shuffle_ps(v64, v64, 201);
          *(float *)&v151 = v90->m_stepInfo.m_deltaTime.m_storage;
          v92 = _mm_shuffle_ps((__m128)(unsigned int)v151, (__m128)(unsigned int)v151, 0);
          v93 = _mm_mul_ps(_mm_mul_ps(_mm_shuffle_ps(v81, v81, 255), v92), m_motion->m_deltaAngle.m_quad);
          input.m_deltaAngles[1].m_quad = _mm_mul_ps(
                                            _mm_mul_ps(_mm_shuffle_ps(v85, v85, 255), v92),
                                            v79->m_deltaAngle.m_quad);
          input.m_deltaAngles[0].m_quad = v93;
          v94 = _mm_sub_ps(_mm_mul_ps(v91, v93), _mm_mul_ps(_mm_shuffle_ps(v93, v93, 201), v64));
          v95 = _mm_mul_ps(_mm_shuffle_ps(input.m_deltaAngles[1].m_quad, input.m_deltaAngles[1].m_quad, 201), v64);
          v96 = _mm_shuffle_ps(v94, v94, 201);
          v97 = _mm_mul_ps(v64, v82);
          v98 = _mm_sub_ps(_mm_mul_ps(v91, input.m_deltaAngles[1].m_quad), v95);
          v99 = _mm_mul_ps(v96, v96);
          v100 = _mm_shuffle_ps(v98, v98, 201);
          v101 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v99, v99, 85), _mm_shuffle_ps(v99, v99, 0)),
                   _mm_shuffle_ps(v99, v99, 170));
          v102 = _mm_mul_ps(v100, v100);
          v103 = _mm_rsqrt_ps(v101);
          v104 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v102, v102, 85), _mm_shuffle_ps(v102, v102, 0)),
                   _mm_shuffle_ps(v102, v102, 170));
          v105 = _mm_rsqrt_ps(v104);
          input.m_worstCaseApproachingDelta.m_storage = (float)((float)(_mm_andnot_ps(
                                                                          _mm_cmple_ps(v101, (__m128)0i64),
                                                                          _mm_mul_ps(
                                                                            _mm_mul_ps(
                                                                              _mm_sub_ps(
                                                                                (__m128)_xmm,
                                                                                _mm_mul_ps(_mm_mul_ps(v103, v101), v103)),
                                                                              _mm_mul_ps(v103, *(__m128 *)_xmm)),
                                                                            v101)).m128_f32[0]
                                                                      * _mm_shuffle_ps(
                                                                          (__m128)LODWORD(m_motion->m_objectRadius),
                                                                          (__m128)LODWORD(m_motion->m_objectRadius),
                                                                          0).m128_f32[0])
                                                              + (float)(_mm_andnot_ps(
                                                                          _mm_cmple_ps(v104, (__m128)0i64),
                                                                          _mm_mul_ps(
                                                                            _mm_mul_ps(
                                                                              _mm_sub_ps(
                                                                                (__m128)_xmm,
                                                                                _mm_mul_ps(_mm_mul_ps(v105, v104), v105)),
                                                                              _mm_mul_ps(v105, *(__m128 *)_xmm)),
                                                                            v104)).m128_f32[0]
                                                                      * _mm_shuffle_ps(
                                                                          (__m128)LODWORD(v79->m_objectRadius),
                                                                          (__m128)LODWORD(v79->m_objectRadius),
                                                                          0).m128_f32[0]))
                                                      + (float)((float)(_mm_shuffle_ps(v97, v97, 85).m128_f32[0]
                                                                      + _mm_shuffle_ps(v97, v97, 0).m128_f32[0])
                                                              + _mm_shuffle_ps(v97, v97, 170).m128_f32[0]);
          v106 = (float *)v76->m_shape;
          v107 = v77->m_shape;
          input.m_motionA.m_storage = m_motion;
          input.m_motionB.m_storage = v79;
          v150 = (hkp4dGskTolerances *)v106;
          v95.m128_f32[0] = *(float *)&v107[1].vfptr + v106[8];
          input.m_linearTimInfo.m_quad = v82;
          input.m_stepInfo.m_storage = &v90->m_stepInfo;
          LODWORD(input.m_radiusSum.m_storage) = v95.m128_i32[0];
          LODWORD(v151) = (*(__int64 (__fastcall **)(float *))(*(_QWORD *)v106 + 88i64))(v106);
          input.m_allocatedNumVertices.m_storage = (int)v151;
          input.m_numVertices.m_storage = (int)v151;
          Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          m_cur = (hkVector4f *)Value->m_cur;
          v110 = (16 * (_DWORD)v151 + 127) & 0xFFFFFF80;
          v111 = (char *)m_cur + v110;
          if ( v110 > Value->m_slabSize || v111 > Value->m_end )
            m_cur = (hkVector4f *)hkLifoAllocator::allocateFromNewSlab(Value, v110);
          else
            Value->m_cur = v111;
          input.m_verticesA.m_storage = m_cur;
          (*(void (__fastcall **)(hkp4dGskTolerances *))(*(_QWORD *)&v150->m_toiSeparation.m_storage + 96i64))(v150);
          v112 = _mm_shuffle_ps(input.m_deltaAngles[0].m_quad, input.m_deltaAngles[0].m_quad, 255).m128_f32[0];
          v113 = _mm_shuffle_ps(input.m_deltaAngles[1].m_quad, input.m_deltaAngles[1].m_quad, 255).m128_f32[0];
          v114 = _mm_shuffle_ps((__m128)LODWORD(m_motion->m_objectRadius), (__m128)LODWORD(m_motion->m_objectRadius), 0).m128_f32[0]
               * (float)(v112 * v112);
          v115 = _mm_shuffle_ps((__m128)LODWORD(v79->m_objectRadius), (__m128)LODWORD(v79->m_objectRadius), 0).m128_f32[0]
               * (float)(v113 * v113);
          v116 = _mm_unpacklo_ps(bTc.m_rotation.m_col0.m_quad, bTc.m_rotation.m_col1.m_quad);
          input.m_maxAccel.m_storage = v114 + v115;
          v117 = 1.0 / (float)((float)(v114 + v115) + 1.4210855e-14);
          v118 = _mm_movelh_ps(v116, bTc.m_rotation.m_col2.m_quad);
          input.m_invMaxAccel.m_storage = v117;
          input.m_pointOnPlaneB = (hkVector4f)gsk->m_verticesBinB[0];
          input.m_planeB.m_quad = _mm_add_ps(
                                    _mm_add_ps(
                                      _mm_mul_ps(
                                        _mm_shuffle_ps(_mm_movehl_ps(v118, v116), bTc.m_rotation.m_col2.m_quad, 212),
                                        _mm_shuffle_ps(*(__m128 *)&tAddOn[8], *(__m128 *)&tAddOn[8], 85)),
                                      _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&tAddOn[8], *(__m128 *)&tAddOn[8], 0), v118)),
                                    _mm_mul_ps(
                                      _mm_shuffle_ps(*(__m128 *)&tAddOn[8], *(__m128 *)&tAddOn[8], 170),
                                      _mm_shuffle_ps(
                                        _mm_unpackhi_ps(bTc.m_rotation.m_col0.m_quad, bTc.m_rotation.m_col1.m_quad),
                                        bTc.m_rotation.m_col2.m_quad,
                                        228)));
          if ( input.m_verticesA.m_storage )
          {
            v137.m_Rtoi.m_storage = 1.0;
            hk4dGskCollidePointsWithPlane(&input, tola, &v137);
            v119 = input.m_verticesA.m_storage;
            v120 = (16 * input.m_allocatedNumVertices.m_storage + 127) & 0xFFFFFF80;
            v121 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
            v122 = (v120 + 15) & 0xFFFFFFF0;
            if ( v120 > v121->m_slabSize || (char *)v119 + v122 != v121->m_cur || v121->m_firstNonLifoEnd == v119 )
              hkLifoAllocator::slowBlockFree(v121, (char *)v119, v122);
            else
              v121->m_cur = v119;
            p_m_linearTimInfo = &in3->m_linearTimInfo;
            if ( v137.m_Rtoi.m_storage < 1.0 )
              *(__m128 *)&tAddOn[32] = _mm_add_ps(
                                         _mm_add_ps(
                                           _mm_add_ps(
                                             _mm_mul_ps(
                                               _mm_shuffle_ps(
                                                 v137.m_collidingPoint.m_quad,
                                                 v137.m_collidingPoint.m_quad,
                                                 85),
                                               transformOut.m_rotation.m_col1.m_quad),
                                             _mm_mul_ps(
                                               _mm_shuffle_ps(
                                                 v137.m_collidingPoint.m_quad,
                                                 v137.m_collidingPoint.m_quad,
                                                 0),
                                               transformOut.m_rotation.m_col0.m_quad)),
                                           _mm_mul_ps(
                                             _mm_shuffle_ps(
                                               v137.m_collidingPoint.m_quad,
                                               v137.m_collidingPoint.m_quad,
                                               170),
                                             transformOut.m_rotation.m_col2.m_quad)),
                                         transformOut.m_translation.m_quad);
          }
          else
          {
            p_m_linearTimInfo = &in3->m_linearTimInfo;
          }
        }
        if ( v55 < v89.m128_f32[0] )
        {
          *(float *)&tola = FLOAT_1_2;
          if ( v55 <= (float)(_mm_shuffle_ps((__m128)LODWORD(FLOAT_1_2), (__m128)LODWORD(FLOAT_1_2), 0).m128_f32[0]
                            * v89.m128_f32[0]) )
          {
            hk4dGskCalcPointVelocityAssumingAngularVelError(
              (hkMotionState *)in3->m_bodyA.m_storage->m_motion,
              (hkMotionState *)in3->m_bodyB.m_storage->m_motion,
              (hkVector4f *)&tAddOn[32],
              (hkVector4f *)&tAddOn[8],
              p_m_linearTimInfo,
              v149,
              &v144,
              (hkSimdFloat32 *)&tAddOn[16]);
            v89.m128_f32[0] = fmin(0.0, *(float *)&tAddOn[16]);
          }
          else
          {
            v89.m128_f32[0] = v55;
          }
        }
        v123 = v53[27];
        v140 = 0i64;
        LODWORD(tola) = v123;
        v139 = 0i64;
        v141 = 0i64;
        v142 = 0i64;
        *((float *)&v140 + 2) = FLOAT_321_0;
        hkpGsk::exitAndExportCacheImpl(gsk, (hkpGskCache *)&tAddOn[40]);
        v124 = in3->m_contactMgr.m_storage;
        v125 = in3->m_input.m_storage;
        *(float *)&tola = v89.m128_f32[0] * _mm_shuffle_ps((__m128)v123, (__m128)v123, 0).m128_f32[0];
        v126 = ((__int64 (__fastcall *)(hkpContactMgr *, hkpCdBody *, hkpCdBody *, hkpProcessCollisionInput *, hkVector4f *, int, _BYTE *, _BYTE *, hkp4dGskTolerances **, __int128 *))v124->vfptr[3].__first_virtual_table_function__)(
                 v124,
                 in3->m_bodyA.m_storage,
                 in3->m_bodyB.m_storage,
                 v125,
                 v54,
                 v57.m128_i32[0],
                 &tAddOn[32],
                 &tAddOn[40],
                 &tola,
                 &v139);
        v127 = (int)tola;
        if ( !v126 )
        {
          if ( 3.40282e38 != v54[771].m_quad.m128_f32[0] )
            ((void (__fastcall *)(hkpContactMgr *, unsigned __int64, hkVector4f *))in3->m_contactMgr.m_storage->vfptr[4].__vecDelDtor)(
              in3->m_contactMgr.m_storage,
              v54->m_quad.m128_u64[1],
              &v54[773]);
          v128.m_quad = *(__m128 *)&tAddOn[32];
          v129.m_quad = *(__m128 *)&tAddOn[8];
          v54[771].m_quad.m128_i32[1] = v127;
          v54[769] = (hkVector4f)v128.m_quad;
          v130 = v139;
          v54[770] = (hkVector4f)v129.m_quad;
          v54[771].m_quad.m128_i32[0] = v57.m128_i32[0];
          v131 = v140;
          v54[773] = (hkVector4f)v130;
          v132 = v141;
          v54[774] = (hkVector4f)v131;
          v133 = v142;
          v54[775] = (hkVector4f)v132;
          v134.m_quad = *(__m128 *)&tAddOn[40];
          v54[776] = (hkVector4f)v133;
          v54[772] = (hkVector4f)v134.m_quad;
        }
      }
    }
  }
}

// File Line: 1328
// RVA: 0xDBE850
void __fastcall hk4dGskCollideCalcToi(
        hkpAgent3ProcessInput *in3,
        hkSimdFloat32 *allowedPenetrationDepth,
        hkSimdFloat32 *minSeparation,
        hkpGskCache *toiSeparation,
        __m128 *gskCache,
        hkVector4f *separatingNormal,
        hkpProcessCollisionOutput *out)
{
  hkpProcessCollisionInput *m_storage; // r10
  __m128 v8; // xmm1
  __m128 v9; // xmm1
  hkpCdBody *v12; // rcx
  __int64 m_dimA; // r8
  hkpConvexShape *m_shape; // r15
  char v15; // bl
  char v16; // si
  unsigned int *v17; // rax
  __m128 v18; // xmm15
  __m128 v19; // xmm6
  __m128 v20; // xmm2
  __m128 v21; // xmm15
  __m128 v22; // xmm6
  hkpCdBody *v23; // rax
  __m128 *m_motion; // rdx
  hkpConvexShape *v25; // r12
  unsigned __int64 v26; // rax
  __m128 v27; // xmm0
  __m128 v28; // xmm15
  __m128 v29; // xmm2
  __m128 v30; // xmm1
  __m128 v31; // xmm1
  hkBaseObjectVtbl *vfptr; // rax
  __m128 *v33; // r13
  __m128 v34; // xmm13
  __m128 v35; // xmm9
  int v36; // r14d
  __m128 v37; // xmm11
  __m128 v38; // xmm7
  __m128 v39; // xmm10
  __m128 v40; // xmm10
  __m128 v41; // xmm8
  __m128 *v42; // rcx
  __m128 v43; // xmm1
  __m128 v44; // xmm2
  __m128 v45; // xmm2
  __m128 v46; // xmm2
  __m128 v47; // xmm3
  __m128 v48; // xmm3
  __m128 v49; // xmm3
  __m128 v50; // xmm6
  __m128 v51; // xmm2
  __m128 v52; // xmm7
  __m128 v53; // xmm4
  __m128 m_quad; // xmm5
  __m128 v55; // xmm11
  __m128 v56; // xmm1
  __m128 v57; // xmm8
  __m128 v58; // xmm3
  __m128 v59; // xmm6
  __m128 v60; // xmm8
  hkpCdBody *v61; // rax
  hkpShape *v62; // rdx
  hkMotionState *v63; // r12
  float *v64; // r14
  hkMotionState *v65; // r15
  hkpProcessCollisionInput *v66; // rax
  float v67; // xmm0_4
  int v68; // ebx
  hkLifoAllocator *Value; // rax
  hkVector4f *m_cur; // rdx
  int v71; // ebx
  char *v72; // rcx
  float v73; // xmm0_4
  float v74; // xmm1_4
  float v75; // xmm0_4
  __m128 v76; // xmm1
  hkpProcessCollisionInput *v77; // rax
  hkpConvexShape *v78; // r12
  hkpConvexShape *v79; // r15
  bool v80; // zf
  __m128 v81; // xmm2
  __m128 v82; // xmm7
  hkVector4f v83; // xmm8
  hkSimdFloat32 *v84; // rax
  __m128 v85; // xmm1
  __m128 v86; // xmm6
  __m128 v87; // xmm8
  __m128 v88; // xmm2
  __m128 v89; // xmm8
  __m128 v90; // xmm1
  __m128 v91; // xmm5
  __m128 v92; // xmm2
  __m128 v93; // xmm7
  __m128 v94; // xmm4
  __m128 v95; // xmm4
  __m128 v96; // xmm0
  hkVector4f v97; // xmm4
  int v98; // esi
  __m128 v99; // xmm15
  __m128 v100; // xmm14
  __m128 v101; // xmm3
  __m128 v102; // xmm2
  __m128 v103; // xmm12
  __m128 v104; // xmm1
  __m128 v105; // xmm4
  __m128 v106; // xmm12
  __m128 v107; // xmm4
  __m128 v108; // xmm8
  char v109; // bl
  __m128 v110; // xmm1
  __m128 v111; // xmm3
  __m128 v112; // xmm0
  hkpProcessCollisionInput *v113; // rax
  __m128 m_storage_low; // xmm0
  hkpCdBody *v115; // rax
  __m128 v116; // xmm5
  __m128 v117; // xmm4
  hkVector4f v118; // xmm3
  hkVector4f v119; // xmm4
  __int64 v120; // rdx
  hkVector4f v121; // xmm5
  hkVector4f v122; // xmm6
  hkcdVertex *v123; // rcx
  __m128 v124; // xmm1
  __m128 v125; // xmm1
  __m128 v126; // xmm2
  __m128 v127; // xmm6
  __m128 v128; // xmm2
  unsigned int *v129; // r14
  hkVector4f *v130; // rsi
  __m128 v131; // xmm2
  __m128 v132; // xmm10
  hkpCdBody *v133; // rax
  hkpCdBody *v134; // r8
  hkpShape *v135; // r11
  int v136; // edx
  __m128 v137; // xmm9
  __m128 m_real; // xmm7
  hkVector4f v139; // xmm9
  hkpShape *v140; // r10
  __int16 v141; // ax
  __int16 v142; // dx
  hkBaseObjectVtbl *v143; // rax
  int v144; // eax
  __int16 v145; // ax
  __int16 v146; // dx
  hkBaseObjectVtbl *v147; // r10
  __m128 v148; // xmm6
  hkpCdBody *v149; // r13
  hkpCdBody *v150; // rax
  hkMotionState *v151; // rbx
  hkMotionState *v152; // r15
  __m128 v153; // xmm14
  __m128 v154; // xmm5
  __m128 v155; // xmm4
  __m128 v156; // xmm4
  __m128 v157; // xmm13
  __m128 v158; // xmm7
  __m128 v159; // xmm7
  __m128 v160; // xmm1
  __m128 v161; // xmm11
  hkpProcessCollisionInput *v162; // rcx
  __m128 v163; // xmm1
  __m128 v164; // xmm5
  __m128 v165; // xmm13
  __m128 v166; // xmm1
  __m128 v167; // xmm5
  __m128 v168; // xmm0
  __m128 v169; // xmm5
  __m128 v170; // xmm9
  __m128 v171; // xmm13
  __m128 v172; // xmm5
  __m128 v173; // xmm13
  __m128 v174; // xmm6
  __m128 v175; // xmm13
  __m128 v176; // xmm3
  __m128 v177; // xmm7
  __m128 v178; // xmm4
  hkpShape *v179; // rax
  float *v180; // r13
  hkLifoAllocator *v181; // rax
  hkVector4f *v182; // rdx
  int v183; // r8d
  char *v184; // rcx
  float v185; // xmm2_4
  float v186; // xmm1_4
  float v187; // xmm2_4
  __m128 v188; // xmm1
  float v189; // xmm0_4
  __m128 v190; // xmm2
  hkVector4f *v191; // r15
  signed int v192; // ebx
  hkLifoAllocator *v193; // rax
  int v194; // r8d
  unsigned int v195; // xmm0_4
  hkpContactMgr *v196; // rcx
  hkpProcessCollisionInput *v197; // r9
  int v198; // eax
  int v199; // xmm6_4
  hkVector4f v200; // xmm0
  hkVector4f v201; // xmm1
  hkVector4f v202; // xmm0
  hkVector4f v203; // xmm1
  hkVector4f v204; // xmm0
  hkVector4f v205; // xmm1
  hkVector4f v206; // xmm0
  hkVector4f *v207; // rdi
  signed int v208; // ebx
  hkLifoAllocator *v209; // rax
  int v210; // r8d
  hkSimdFloat32 t; // [rsp+50h] [rbp-A8h] BYREF
  hkpConvexShape *shapeA[2]; // [rsp+60h] [rbp-98h] BYREF
  hkp4dGskTolerances tol; // [rsp+70h] [rbp-88h] BYREF
  unsigned int v214; // [rsp+84h] [rbp-74h]
  unsigned int v215; // [rsp+88h] [rbp-70h]
  hkp4dGskVertexCollidePointsOutput v216; // [rsp+98h] [rbp-60h] BYREF
  hkVector4f pointA; // [rsp+B8h] [rbp-40h] BYREF
  hkpConvexShape *shapeB[2]; // [rsp+C8h] [rbp-30h] BYREF
  hkVector4f separatingNormalOut; // [rsp+D8h] [rbp-20h] BYREF
  hkp4dGskVertexCollidePointsOutput masterNormal; // [rsp+E8h] [rbp-10h] BYREF
  hkTransformf bTa; // [rsp+108h] [rbp+10h] BYREF
  hkTransformf bTc; // [rsp+148h] [rbp+50h] BYREF
  hkTransformf aTb; // [rsp+188h] [rbp+90h] BYREF
  hkp4dGskVertexCollidePointsInput input; // [rsp+1C8h] [rbp+D0h] BYREF
  hkTransformf transformOut; // [rsp+268h] [rbp+170h] BYREF
  hkp4dGskVertexCollidePointsInput v226; // [rsp+2A8h] [rbp+1B0h] BYREF
  __m128 v227; // [rsp+348h] [rbp+250h]
  hkpGsk v228; // [rsp+358h] [rbp+260h] BYREF
  void *retaddr; // [rsp+5E8h] [rbp+4F0h]
  __m128 *v230; // [rsp+5F0h] [rbp+4F8h]
  __m128 *v231; // [rsp+5F8h] [rbp+500h] BYREF
  hkSimdFloat32 *v232; // [rsp+600h] [rbp+508h] BYREF
  hkpGskCache *cache; // [rsp+608h] [rbp+510h]

  cache = toiSeparation;
  v232 = minSeparation;
  m_storage = in3->m_input.m_storage;
  v8 = *(__m128 *)toiSeparation->m_vertices;
  LODWORD(tol.m_minToiDeltaTime.m_storage) = *(hkSimdFloat32 *)minSeparation->m_real.m128_f32;
  LODWORD(tol.m_minSafeDeltaRt.m_storage) = v8.m128_i32[0];
  v9 = _mm_shuffle_ps(
         (__m128)LODWORD(m_storage->m_stepInfo.m_invDeltaTime.m_storage),
         (__m128)LODWORD(m_storage->m_stepInfo.m_invDeltaTime.m_storage),
         0);
  v12 = in3->m_bodyA.m_storage;
  m_dimA = (unsigned __int8)toiSeparation->m_dimA;
  m_shape = (hkpConvexShape *)v12->m_shape;
  v15 = 0;
  v16 = 0;
  *(_QWORD *)&v228.m_doNotHandlePenetration.m_storage = 0i64;
  v228.m_dimA.m_storage = m_dimA;
  shapeA[0] = m_shape;
  v17 = (unsigned int *)m_storage->m_collisionQualityInfo.m_storage;
  v18 = _mm_shuffle_ps((__m128)v17[8], (__m128)v17[8], 0);
  v19 = _mm_shuffle_ps((__m128)v17[12], (__m128)v17[12], 0);
  v20 = (__m128)v17[9];
  v214 = v17[14];
  v21 = _mm_mul_ps(v18, allowedPenetrationDepth->m_real);
  v22 = _mm_mul_ps(v19, allowedPenetrationDepth->m_real);
  v23 = in3->m_bodyB.m_storage;
  m_motion = (__m128 *)v12->m_motion;
  LODWORD(v12) = *((unsigned __int8 *)toiSeparation + 10);
  v25 = (hkpConvexShape *)v23->m_shape;
  v26 = (unsigned __int64)v23->m_motion;
  input.m_verticesA.m_storage = 0i64;
  *(__m128 *)&masterNormal.m_Rtoi.m_storage = v22;
  v215 = v22.m128_i32[0];
  *(float *)&retaddr = m_storage->m_stepInfo.m_deltaTime.m_storage;
  v27 = m_motion[5];
  pointA.m_quad.m128_u64[0] = v26;
  shapeB[0] = v25;
  v230 = m_motion;
  v28 = _mm_mul_ps(_mm_max_ps(v21, _mm_shuffle_ps(v20, v20, 0)), v9);
  v29 = _mm_shuffle_ps((__m128)(unsigned int)retaddr, (__m128)(unsigned int)retaddr, 0);
  v30 = *(__m128 *)(v26 + 80);
  LODWORD(tol.m_toiAccuracy.m_storage) = v28.m128_i32[0];
  v31 = _mm_mul_ps(_mm_mul_ps(_mm_shuffle_ps(v30, v30, 255), v29), *(__m128 *)(v26 + 144));
  LODWORD(v26) = (unsigned __int8)toiSeparation->m_dimB;
  input.m_deltaAngles[0].m_quad = _mm_mul_ps(_mm_mul_ps(_mm_shuffle_ps(v27, v27, 255), v29), m_motion[9]);
  v228.m_dimB.m_storage = v26;
  v228.m_maxDimA.m_storage = (unsigned __int8)v12 & 0xF;
  input.m_deltaAngles[1].m_quad = v31;
  vfptr = m_shape->vfptr;
  *(_QWORD *)&v228.m_maxDimB.m_storage = (unsigned int)v12 >> 4;
  ((void (__fastcall *)(hkpConvexShape *, hkpGskCache *, __int64, hkcdVertex *))vfptr[4].__first_virtual_table_function__)(
    m_shape,
    toiSeparation,
    m_dimA,
    v228.m_verticesA);
  ((void (__fastcall *)(hkpConvexShape *, unsigned __int16 *, _QWORD, hkcdVertex *))v25->vfptr[4].__first_virtual_table_function__)(
    v25,
    &toiSeparation->m_vertices[v228.m_dimA.m_storage],
    (unsigned int)v228.m_dimB.m_storage,
    v228.m_verticesBinB);
  v33 = gskCache;
  v34 = 0i64;
  v35 = 0i64;
  v36 = 1;
  v37 = _mm_shuffle_ps(*gskCache, *gskCache, 255);
  v38 = v37;
  v39 = 0i64;
  if ( v37.m128_f32[0] > (float)(v22.m128_f32[0] + v232->m_real.m128_f32[0]) )
  {
    do
    {
      v40 = _mm_sub_ps(query.m_quad, v35);
      if ( v40.m128_f32[0] <= 0.0 )
        goto LABEL_81;
      v41 = *v33;
      v42 = v230;
      v43 = _mm_shuffle_ps(v41, v41, 201);
      v44 = _mm_sub_ps(
              _mm_mul_ps(input.m_deltaAngles[0].m_quad, v43),
              _mm_mul_ps(_mm_shuffle_ps(input.m_deltaAngles[0].m_quad, input.m_deltaAngles[0].m_quad, 201), *v33));
      v45 = _mm_shuffle_ps(v44, v44, 201);
      v46 = _mm_mul_ps(v45, v45);
      v47 = _mm_sub_ps(
              _mm_mul_ps(input.m_deltaAngles[1].m_quad, v43),
              _mm_mul_ps(_mm_shuffle_ps(input.m_deltaAngles[1].m_quad, input.m_deltaAngles[1].m_quad, 201), *v33));
      v48 = _mm_shuffle_ps(v47, v47, 201);
      v49 = _mm_mul_ps(v48, v48);
      v50 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v46, v46, 85), _mm_shuffle_ps(v46, v46, 0)),
              _mm_shuffle_ps(v46, v46, 170));
      v51 = _mm_rsqrt_ps(v50);
      v52 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v49, v49, 85), _mm_shuffle_ps(v49, v49, 0)),
              _mm_shuffle_ps(v49, v49, 170));
      v53 = _mm_rsqrt_ps(v52);
      m_quad = in3->m_linearTimInfo.m_quad;
      v55 = _mm_add_ps(
              _mm_mul_ps(
                _mm_andnot_ps(
                  _mm_cmple_ps(v50, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v51, v50), v51)),
                      _mm_mul_ps(v51, *(__m128 *)_xmm)),
                    v50)),
                _mm_shuffle_ps((__m128)v230[10].m128_u32[0], (__m128)v230[10].m128_u32[0], 0)),
              _mm_mul_ps(
                _mm_andnot_ps(
                  _mm_cmple_ps(v52, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v53, v52), v53)),
                      _mm_mul_ps(v53, *(__m128 *)_xmm)),
                    v52)),
                _mm_shuffle_ps(
                  (__m128)*(unsigned int *)(pointA.m_quad.m128_u64[0] + 160),
                  (__m128)*(unsigned int *)(pointA.m_quad.m128_u64[0] + 160),
                  0)));
      v56 = _mm_mul_ps(m_quad, *v33);
      v57 = _mm_shuffle_ps(v41, v41, 255);
      v58 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v56, v56, 85), _mm_shuffle_ps(v56, v56, 0)),
              _mm_shuffle_ps(v56, v56, 170));
      v59 = _mm_add_ps(v58, v55);
      if ( _mm_movemask_ps(_mm_or_ps(_mm_cmplt_ps(*v231, _mm_sub_ps(v57, _mm_mul_ps(v40, v59))), _mm_cmple_ps(v59, (__m128)0i64))) )
        goto LABEL_81;
      v60 = _mm_div_ps(_mm_sub_ps(v57, *v231), v59);
      if ( v60.m128_f32[0] < 0.2 && !v16 && v15 && v58.m128_f32[0] < v55.m128_f32[0] )
      {
        if ( input.m_verticesA.m_storage )
          goto LABEL_15;
        v61 = in3->m_bodyB.m_storage;
        v62 = v61->m_shape;
        v63 = (hkMotionState *)v61->m_motion;
        v64 = (float *)in3->m_bodyA.m_storage->m_shape;
        v65 = (hkMotionState *)in3->m_bodyA.m_storage->m_motion;
        v66 = in3->m_input.m_storage;
        input.m_motionB.m_storage = v63;
        input.m_motionA.m_storage = v65;
        v67 = *(float *)&v62[1].vfptr + v64[8];
        input.m_stepInfo.m_storage = &v66->m_stepInfo;
        input.m_linearTimInfo.m_quad = m_quad;
        input.m_radiusSum.m_storage = v67;
        v68 = (*(__int64 (__fastcall **)(float *))(*(_QWORD *)v64 + 88i64))(v64);
        input.m_allocatedNumVertices.m_storage = v68;
        input.m_numVertices.m_storage = v68;
        Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        m_cur = (hkVector4f *)Value->m_cur;
        v71 = (16 * v68 + 127) & 0xFFFFFF80;
        v72 = (char *)m_cur + v71;
        if ( v71 > Value->m_slabSize || v72 > Value->m_end )
          m_cur = (hkVector4f *)hkLifoAllocator::allocateFromNewSlab(Value, v71);
        else
          Value->m_cur = v72;
        input.m_verticesA.m_storage = m_cur;
        (*(void (__fastcall **)(float *))(*(_QWORD *)v64 + 96i64))(v64);
        v73 = _mm_shuffle_ps(input.m_deltaAngles[1].m_quad, input.m_deltaAngles[1].m_quad, 255).m128_f32[0];
        v74 = _mm_shuffle_ps(input.m_deltaAngles[0].m_quad, input.m_deltaAngles[0].m_quad, 255).m128_f32[0];
        input.m_maxAccel.m_storage = (float)(_mm_shuffle_ps(
                                               (__m128)LODWORD(v63->m_objectRadius),
                                               (__m128)LODWORD(v63->m_objectRadius),
                                               0).m128_f32[0]
                                           * (float)(v73 * v73))
                                   + (float)(_mm_shuffle_ps(
                                               (__m128)LODWORD(v65->m_objectRadius),
                                               (__m128)LODWORD(v65->m_objectRadius),
                                               0).m128_f32[0]
                                           * (float)(v74 * v74));
        input.m_invMaxAccel.m_storage = 1.0 / (float)(input.m_maxAccel.m_storage + 1.4210855e-14);
        if ( input.m_verticesA.m_storage )
        {
LABEL_15:
          LODWORD(input.m_startRt.m_storage) = v35.m128_i32[0];
          LODWORD(input.m_worstCaseApproachingDelta.m_storage) = v59.m128_i32[0];
          v216.m_Rtoi.m_storage = 1.0;
          hk4dGskCollidePointsWithPlane(&input, (hkp4dGskTolerances *)&tol.m_minSafeDeltaRt, &v216);
          v16 = 0;
          v75 = v60.m128_f32[0] + v60.m128_f32[0];
          v76 = _mm_sub_ps(
                  _mm_shuffle_ps((__m128)LODWORD(v216.m_Rtoi.m_storage), (__m128)LODWORD(v216.m_Rtoi.m_storage), 0),
                  v35);
          v60 = _mm_max_ps(v60, v76);
          if ( v76.m128_f32[0] < v75 )
            v16 = 1;
        }
        else
        {
          v16 = 1;
        }
        v42 = v230;
      }
      if ( (float)(v60.m128_f32[0] + v35.m128_f32[0]) >= 1.0 )
        goto LABEL_81;
      v77 = in3->m_input.m_storage;
      v34 = *v33;
      v39 = v35;
      v37 = _mm_shuffle_ps(v34, v34, 255);
      v35 = _mm_min_ps(_mm_add_ps(v35, _mm_max_ps(v28, v60)), query.m_quad);
      *(__m128 *)&tol.m_toiSeparation.m_storage = _mm_mul_ps(
                                                    _mm_shuffle_ps(
                                                      (__m128)LODWORD(v77->m_stepInfo.m_deltaTime.m_storage),
                                                      (__m128)LODWORD(v77->m_stepInfo.m_deltaTime.m_storage),
                                                      0),
                                                    v35);
      t.m_real = _mm_shuffle_ps(
                   (__m128)LODWORD(v77->m_stepInfo.m_startTime.m_storage),
                   (__m128)LODWORD(v77->m_stepInfo.m_startTime.m_storage),
                   0);
      hkSweptTransformUtil::lerp2Ha((hkSweptTransformf *)&v42[4], &t, (hkSimdFloat32 *)&tol, &transformOut);
      hkSweptTransformUtil::lerp2Ha(
        (hkSweptTransformf *)(pointA.m_quad.m128_u64[0] + 64),
        &t,
        (hkSimdFloat32 *)&tol,
        &bTc);
      hkTransformf::setMulInverseMul(&aTb, &transformOut, &bTc);
      v78 = shapeB[0];
      v79 = shapeA[0];
      hkpGsk::getClosestFeature(&v228, shapeA[0], shapeB[0], &aTb, &separatingNormalOut);
      v80 = v228.m_dimA.m_storage == 1;
      v81 = separatingNormalOut.m_quad;
      v82 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_shuffle_ps(separatingNormalOut.m_quad, separatingNormalOut.m_quad, 85),
                  transformOut.m_rotation.m_col1.m_quad),
                _mm_mul_ps(
                  _mm_shuffle_ps(separatingNormalOut.m_quad, separatingNormalOut.m_quad, 0),
                  transformOut.m_rotation.m_col0.m_quad)),
              _mm_mul_ps(
                _mm_shuffle_ps(separatingNormalOut.m_quad, separatingNormalOut.m_quad, 170),
                transformOut.m_rotation.m_col2.m_quad));
      *v33 = v82;
      if ( v80 )
      {
        v83.m_quad = (__m128)v228.m_verticesA[0];
      }
      else if ( v228.m_dimB.m_storage == 1 )
      {
        v83.m_quad = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v81, v81, 255), v81), v228.m_verticesBinA[0].m_quad);
      }
      else
      {
        v83.m_quad = (__m128)v228.m_closestLineLineResult.m_closestPointA;
      }
      v84 = v232;
      v36 = v228.m_featureChange.m_storage;
      v15 = 1;
      v85 = _mm_unpacklo_ps(aTb.m_rotation.m_col0.m_quad, aTb.m_rotation.m_col1.m_quad);
      v86 = _mm_shuffle_ps(v81, v81, 255);
      v87 = _mm_sub_ps(v83.m_quad, _mm_mul_ps(v81, v86));
      v88 = _mm_movelh_ps(v85, aTb.m_rotation.m_col2.m_quad);
      v89 = _mm_sub_ps(v87, aTb.m_translation.m_quad);
      input.m_pointOnPlaneB.m_quad = _mm_add_ps(
                                       _mm_add_ps(
                                         _mm_mul_ps(
                                           _mm_shuffle_ps(_mm_movehl_ps(v88, v85), aTb.m_rotation.m_col2.m_quad, 212),
                                           _mm_shuffle_ps(v89, v89, 85)),
                                         _mm_mul_ps(_mm_shuffle_ps(v89, v89, 0), v88)),
                                       _mm_mul_ps(
                                         _mm_shuffle_ps(v89, v89, 170),
                                         _mm_shuffle_ps(
                                           _mm_unpackhi_ps(aTb.m_rotation.m_col0.m_quad, aTb.m_rotation.m_col1.m_quad),
                                           aTb.m_rotation.m_col2.m_quad,
                                           228)));
      *(float *)&gskCache = v78->m_radius + v79->m_radius;
      v90 = _mm_unpacklo_ps(bTc.m_rotation.m_col0.m_quad, bTc.m_rotation.m_col1.m_quad);
      v91 = _mm_shuffle_ps(
              _mm_unpackhi_ps(bTc.m_rotation.m_col0.m_quad, bTc.m_rotation.m_col1.m_quad),
              bTc.m_rotation.m_col2.m_quad,
              228);
      v92 = _mm_movelh_ps(v90, bTc.m_rotation.m_col2.m_quad);
      v93 = _mm_shuffle_ps(
              v82,
              _mm_unpackhi_ps(
                v82,
                _mm_sub_ps(v86, _mm_shuffle_ps((__m128)(unsigned int)gskCache, (__m128)(unsigned int)gskCache, 0))),
              196);
      v94 = _mm_shuffle_ps(_mm_movehl_ps(v92, v90), bTc.m_rotation.m_col2.m_quad, 212);
      *v33 = v93;
      v95 = _mm_add_ps(_mm_mul_ps(v94, _mm_shuffle_ps(v93, v93, 85)), _mm_mul_ps(_mm_shuffle_ps(v93, v93, 0), v92));
      v96 = _mm_shuffle_ps(v93, v93, 170);
      v38 = _mm_shuffle_ps(v93, v93, 255);
      v97.m_quad = _mm_add_ps(v95, _mm_mul_ps(v96, v91));
      v96.m128_f32[0] = masterNormal.m_Rtoi.m_storage + v84->m_real.m128_f32[0];
      input.m_planeB = (hkVector4f)v97.m_quad;
    }
    while ( v38.m128_f32[0] > v96.m128_f32[0] );
  }
  v98 = 0;
  v99 = _mm_shuffle_ps((__m128)v215, (__m128)v215, 0);
  v100 = _mm_shuffle_ps(
           (__m128)LODWORD(tol.m_minSafeDeltaRt.m_storage),
           (__m128)LODWORD(tol.m_minSafeDeltaRt.m_storage),
           0);
  *(float *)&v232 = *(float *)&in3->m_bodyA.m_storage->m_shape[1].vfptr
                  + *(float *)&in3->m_bodyB.m_storage->m_shape[1].vfptr;
  separatingNormalOut.m_quad = _mm_shuffle_ps((__m128)(unsigned int)v232, (__m128)(unsigned int)v232, 0);
  v101 = _mm_sub_ps((__m128)0i64, v99);
  *(__m128 *)shapeA = v101;
  v227 = _mm_div_ps(_mm_sub_ps(v38, v37), _mm_sub_ps(v35, v39));
  do
  {
    v102 = _mm_sub_ps(v38, v37);
    v103 = _mm_cmplt_ps(v101, v102);
    v104 = _mm_andnot_ps(v103, v102);
    v105 = _mm_and_ps(v103, (__m128)xmmword_141A711B0);
    v106 = _mm_or_ps(_mm_andnot_ps(v103, v35), _mm_and_ps(v103, v39));
    v107 = _mm_or_ps(v105, v104);
    v108 = v106;
    if ( COERCE_FLOAT((unsigned int)(2 * COERCE_INT(v38.m128_f32[0] - v100.m128_f32[0])) >> 1) >= v99.m128_f32[0] )
    {
      LODWORD(v232) = 1063675494;
      LODWORD(v231) = 1036831949;
      v109 = 0;
      v110 = _mm_shuffle_ps((__m128)0x3F666666u, (__m128)0x3F666666u, 0);
      v111 = _mm_div_ps(_mm_sub_ps(v100, v37), v107);
      v112 = _mm_cmplt_ps(v111, v110);
      v108 = _mm_add_ps(
               _mm_mul_ps(
                 _mm_sub_ps(v106, v39),
                 _mm_max_ps(
                   _mm_shuffle_ps((__m128)0x3DCCCCCDu, (__m128)0x3DCCCCCDu, 0),
                   _mm_or_ps(_mm_and_ps(v111, v112), _mm_andnot_ps(v112, v110)))),
               v39);
    }
    else
    {
      v109 = 1;
      v36 = 0;
    }
    v113 = in3->m_input.m_storage;
    t.m_real = _mm_mul_ps(
                 _mm_shuffle_ps(
                   (__m128)LODWORD(v113->m_stepInfo.m_deltaTime.m_storage),
                   (__m128)LODWORD(v113->m_stepInfo.m_deltaTime.m_storage),
                   0),
                 v108);
    m_storage_low = (__m128)LODWORD(v113->m_stepInfo.m_startTime.m_storage);
    v115 = in3->m_bodyA.m_storage;
    *(__m128 *)&tol.m_toiSeparation.m_storage = _mm_shuffle_ps(m_storage_low, m_storage_low, 0);
    hkSweptTransformUtil::lerp2Ha((hkSweptTransformf *)((char *)v115->m_motion + 64), (hkSimdFloat32 *)&tol, &t, &bTa);
    hkSweptTransformUtil::lerp2Ha(
      (hkSweptTransformf *)((char *)in3->m_bodyB.m_storage->m_motion + 64),
      (hkSimdFloat32 *)&tol,
      &t,
      &aTb);
    hkTransformf::setMulInverseMul(&transformOut, &bTa, &aTb);
    if ( !v36 )
    {
      v118.m_quad = (__m128)transformOut.m_translation;
      v119.m_quad = (__m128)transformOut.m_rotation.m_col2;
      v120 = v228.m_dimB.m_storage - 1;
      v121.m_quad = (__m128)transformOut.m_rotation.m_col1;
      v122.m_quad = (__m128)transformOut.m_rotation.m_col0;
      v123 = &v228.m_verticesBinB[v120];
      do
      {
        v124 = v123->m_quad;
        --v123;
        --v120;
        v123[-3].m_quad = _mm_add_ps(
                            _mm_add_ps(
                              _mm_add_ps(
                                _mm_mul_ps(_mm_shuffle_ps(v124, v124, 85), v121.m_quad),
                                _mm_mul_ps(_mm_shuffle_ps(v124, v124, 0), v122.m_quad)),
                              _mm_mul_ps(_mm_shuffle_ps(v124, v124, 170), v119.m_quad)),
                            v118.m_quad);
      }
      while ( v120 >= 0 );
      v125 = _mm_unpacklo_ps(bTa.m_rotation.m_col0.m_quad, bTa.m_rotation.m_col1.m_quad);
      v126 = _mm_movelh_ps(v125, bTa.m_rotation.m_col2.m_quad);
      *(__m128 *)&masterNormal.m_Rtoi.m_storage = _mm_add_ps(
                                                    _mm_add_ps(
                                                      _mm_mul_ps(
                                                        _mm_shuffle_ps(
                                                          _mm_movehl_ps(v126, v125),
                                                          bTa.m_rotation.m_col2.m_quad,
                                                          212),
                                                        _mm_shuffle_ps(v34, v34, 85)),
                                                      _mm_mul_ps(_mm_shuffle_ps(v34, v34, 0), v126)),
                                                    _mm_mul_ps(
                                                      _mm_shuffle_ps(
                                                        _mm_unpackhi_ps(
                                                          bTa.m_rotation.m_col0.m_quad,
                                                          bTa.m_rotation.m_col1.m_quad),
                                                        bTa.m_rotation.m_col2.m_quad,
                                                        228),
                                                      _mm_shuffle_ps(v34, v34, 170)));
      hkGskRecalcContactInternal(
        &v228.m_verticesA[0],
        v228.m_verticesBinA,
        v228.m_dimA.m_storage,
        v228.m_dimB.m_storage,
        (hkVector4f *)&masterNormal,
        &pointA,
        (hkVector4f *)shapeB);
      v116 = pointA.m_quad;
      goto LABEL_38;
    }
    hkpGsk::getClosestFeature(
      &v228,
      (hkpConvexShape *)in3->m_bodyA.m_storage->m_shape,
      (hkpConvexShape *)in3->m_bodyB.m_storage->m_shape,
      &transformOut,
      (hkVector4f *)shapeB);
    if ( v228.m_dimA.m_storage == 1 )
    {
      v116 = v228.m_verticesA[0].m_quad;
      pointA.m_quad = (__m128)v228.m_verticesA[0];
LABEL_38:
      v117 = *(__m128 *)shapeB;
      goto LABEL_39;
    }
    v117 = *(__m128 *)shapeB;
    if ( v228.m_dimB.m_storage == 1 )
    {
      v116 = _mm_add_ps(
               _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)shapeB, *(__m128 *)shapeB, 255), *(__m128 *)shapeB),
               v228.m_verticesBinA[0].m_quad);
      pointA.m_quad = v116;
    }
    else
    {
      v116 = v228.m_closestLineLineResult.m_closestPointA.m_quad;
      pointA.m_quad = (__m128)v228.m_closestLineLineResult.m_closestPointA;
    }
LABEL_39:
    v127 = _mm_sub_ps(_mm_shuffle_ps(v117, v117, 255), separatingNormalOut.m_quad);
    if ( COERCE_FLOAT((unsigned int)(2 * COERCE_INT(v127.m128_f32[0] - v100.m128_f32[0])) >> 1) < v99.m128_f32[0] )
      break;
    if ( v109 )
      break;
    if ( v39.m128_f32[0] == v106.m128_f32[0] )
      break;
    v101 = *(__m128 *)shapeA;
    ++v98;
    v128 = _mm_cmplt_ps(v127, v100);
    v35 = _mm_or_ps(_mm_andnot_ps(v128, v106), _mm_and_ps(v108, v128));
    v39 = _mm_or_ps(_mm_andnot_ps(v128, v108), _mm_and_ps(v39, v128));
    v37 = _mm_or_ps(_mm_andnot_ps(v128, v127), _mm_and_ps(v37, v128));
    v38 = _mm_or_ps(_mm_andnot_ps(v128, v38), _mm_and_ps(v127, v128));
  }
  while ( v98 < 10 );
  v129 = (unsigned int *)in3->m_input.m_storage;
  v130 = separatingNormal;
  v131 = _mm_shuffle_ps((__m128)v214, (__m128)v214, 0);
  LODWORD(v232) = v129[26];
  v132 = _mm_add_ps(
           _mm_max_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)(unsigned int)v232, (__m128)(unsigned int)v232, 0), v108), v131),
           _mm_shuffle_ps((__m128)v129[24], (__m128)v129[24], 0));
  LODWORD(v232) = separatingNormal[771].m_quad.m128_i32[0];
  separatingNormalOut.m_quad = v132;
  if ( v132.m128_f32[0] < _mm_shuffle_ps((__m128)(unsigned int)v232, (__m128)(unsigned int)v232, 0).m128_f32[0] )
  {
    LODWORD(v232) = v129[25];
    if ( v132.m128_f32[0] < (float)(_mm_shuffle_ps((__m128)(unsigned int)v232, (__m128)(unsigned int)v232, 0).m128_f32[0]
                                  - v131.m128_f32[0]) )
    {
      v133 = in3->m_bodyA.m_storage;
      v134 = in3->m_bodyB.m_storage;
      v135 = in3->m_bodyA.m_storage->m_shape;
      v136 = 2;
      v137 = _mm_add_ps(
               _mm_add_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v117, v117, 85), bTa.m_rotation.m_col1.m_quad),
                 _mm_mul_ps(_mm_shuffle_ps(v117, v117, 0), bTa.m_rotation.m_col0.m_quad)),
               _mm_mul_ps(_mm_shuffle_ps(v117, v117, 170), bTa.m_rotation.m_col2.m_quad));
      m_real = _mm_add_ps(
                 _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v116, v116, 85), bTa.m_rotation.m_col1.m_quad),
                       _mm_mul_ps(_mm_shuffle_ps(v116, v116, 0), bTa.m_rotation.m_col0.m_quad)),
                     _mm_mul_ps(_mm_shuffle_ps(v116, v116, 170), bTa.m_rotation.m_col2.m_quad)),
                   bTa.m_translation.m_quad),
                 _mm_mul_ps(
                   _mm_sub_ps(
                     _mm_sub_ps(
                       (__m128)0i64,
                       _mm_shuffle_ps((__m128)LODWORD(v135[1].vfptr), (__m128)LODWORD(v135[1].vfptr), 0)),
                     v127),
                   v137));
      v139.m_quad = _mm_shuffle_ps(v137, _mm_unpackhi_ps(v137, v127), 196);
      *(__m128 *)&v216.m_Rtoi.m_storage = m_real;
      v216.m_collidingPoint = (hkVector4f)v139.m_quad;
      *(hkVector4f *)shapeA = (hkVector4f)v139.m_quad;
      v140 = v134->m_shape;
      if ( v134->m_shape->m_type.m_storage == 2 )
      {
        LOWORD(v231) = v228.m_verticesBinB[0].m_quad.m128_i16[6];
        v141 = -1;
        v142 = -1;
        LOBYTE(v232) = v228.m_dimB.m_storage;
        if ( LOBYTE(v228.m_dimB.m_storage) >= 2u )
          v142 = v228.m_verticesBinB[1].m_quad.m128_i16[6];
        WORD1(v231) = v142;
        if ( LOBYTE(v228.m_dimB.m_storage) >= 3u )
          v141 = v228.m_verticesBinB[2].m_quad.m128_i16[6];
        WORD2(v231) = v141;
        v143 = v140->vfptr;
        t.m_real = m_real;
        v144 = ((__int64 (__fastcall *)(hkpShape *, __m128 **, hkSimdFloat32 **, hkSimdFloat32 *, hkTransformf *, hkpShape *, hkTransformf *, hkpConvexShape **))v143[6].__first_virtual_table_function__)(
                 v140,
                 &v231,
                 &v232,
                 &t,
                 &aTb,
                 v135,
                 &bTa,
                 shapeA);
        m_real = t.m_real;
        v139.m_quad = *(__m128 *)shapeA;
        *(hkSimdFloat32 *)&v216.m_Rtoi.m_storage = (hkSimdFloat32)t.m_real;
        goto LABEL_57;
      }
      if ( v133->m_shape->m_type.m_storage != 2 )
        goto LABEL_59;
      LOWORD(v231) = v228.m_verticesA[0].m_quad.m128_i16[6];
      v145 = -1;
      v146 = -1;
      LOBYTE(v232) = v228.m_dimA.m_storage;
      if ( LOBYTE(v228.m_dimA.m_storage) >= 2u )
        v146 = v228.m_verticesA[1].m_quad.m128_i16[6];
      WORD1(v231) = v146;
      if ( LOBYTE(v228.m_dimA.m_storage) >= 3u )
        v145 = v228.m_verticesA[2].m_quad.m128_i16[6];
      v147 = v135->vfptr;
      WORD2(v231) = v145;
      *(__m128 *)&masterNormal.m_Rtoi.m_storage = _mm_add_ps(
                                                    _mm_mul_ps(
                                                      _mm_shuffle_ps(v139.m_quad, v139.m_quad, 255),
                                                      v139.m_quad),
                                                    m_real);
      v148 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64);
      *(__m128 *)shapeA = _mm_xor_ps(v139.m_quad, v148);
      v144 = ((__int64 (__fastcall *)(hkpShape *, __m128 **, hkSimdFloat32 **, hkp4dGskVertexCollidePointsOutput *, hkTransformf *, hkpShape *, hkTransformf *, hkpConvexShape **))v147[6].__first_virtual_table_function__)(
               v135,
               &v231,
               &v232,
               &masterNormal,
               &bTa,
               v134->m_shape,
               &aTb,
               shapeA);
      m_real = *(__m128 *)&v216.m_Rtoi.m_storage;
      v139.m_quad = _mm_xor_ps(*(__m128 *)shapeA, v148);
      *(hkVector4f *)shapeA = (hkVector4f)v139.m_quad;
LABEL_57:
      v216.m_collidingPoint = (hkVector4f)v139.m_quad;
      v136 = v144;
      if ( v144 || !in3->m_input.m_storage->m_collisionQualityInfo.m_storage->m_enableToiWeldRejection.m_bool )
      {
LABEL_59:
        v149 = in3->m_bodyA.m_storage;
        v150 = in3->m_bodyB.m_storage;
        v151 = (hkMotionState *)in3->m_bodyA.m_storage->m_motion;
        v152 = (hkMotionState *)v150->m_motion;
        v153 = in3->m_linearTimInfo.m_quad;
        v154 = v151->m_sweptTransform.m_centerOfMass1.m_quad;
        v155 = _mm_sub_ps(
                 m_real,
                 _mm_add_ps(
                   _mm_mul_ps(
                     _mm_mul_ps(
                       _mm_sub_ps(
                         v132,
                         _mm_shuffle_ps(
                           v151->m_sweptTransform.m_centerOfMass0.m_quad,
                           v151->m_sweptTransform.m_centerOfMass0.m_quad,
                           255)),
                       _mm_shuffle_ps(v154, v154, 255)),
                     _mm_sub_ps(v154, v151->m_sweptTransform.m_centerOfMass0.m_quad)),
                   v151->m_sweptTransform.m_centerOfMass0.m_quad));
        v156 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v155, v155, 201), input.m_deltaAngles[0].m_quad),
                 _mm_mul_ps(_mm_shuffle_ps(input.m_deltaAngles[0].m_quad, input.m_deltaAngles[0].m_quad, 201), v155));
        v157 = v152->m_sweptTransform.m_centerOfMass1.m_quad;
        v158 = _mm_sub_ps(
                 m_real,
                 _mm_add_ps(
                   _mm_mul_ps(
                     _mm_mul_ps(
                       _mm_sub_ps(
                         v132,
                         _mm_shuffle_ps(
                           v152->m_sweptTransform.m_centerOfMass0.m_quad,
                           v152->m_sweptTransform.m_centerOfMass0.m_quad,
                           255)),
                       _mm_shuffle_ps(v157, v157, 255)),
                     _mm_sub_ps(v157, v152->m_sweptTransform.m_centerOfMass0.m_quad)),
                   v152->m_sweptTransform.m_centerOfMass0.m_quad));
        v159 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v158, v158, 201), input.m_deltaAngles[1].m_quad),
                 _mm_mul_ps(_mm_shuffle_ps(input.m_deltaAngles[1].m_quad, input.m_deltaAngles[1].m_quad, 201), v158));
        v160 = _mm_mul_ps(
                 _mm_sub_ps(
                   _mm_add_ps(
                     _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v153),
                     _mm_shuffle_ps(v156, v156, 201)),
                   _mm_shuffle_ps(v159, v159, 201)),
                 v139.m_quad);
        v161 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v160, v160, 85), _mm_shuffle_ps(v160, v160, 0)),
                 _mm_shuffle_ps(v160, v160, 170));
        t.m_real = v161;
        if ( v136 == 1 && v161.m128_f32[0] > (float)(0.0 - 0.00000011920929) )
        {
          v162 = in3->m_input.m_storage;
          LODWORD(v226.m_startRt.m_storage) = v108.m128_i32[0];
          *(float *)&v232 = v162->m_stepInfo.m_deltaTime.m_storage;
          v163 = _mm_shuffle_ps((__m128)(unsigned int)v232, (__m128)(unsigned int)v232, 0);
          v164 = _mm_mul_ps(_mm_mul_ps(_mm_shuffle_ps(v154, v154, 255), v163), v151->m_deltaAngle.m_quad);
          v165 = _mm_mul_ps(_mm_mul_ps(_mm_shuffle_ps(v157, v157, 255), v163), v152->m_deltaAngle.m_quad);
          v166 = _mm_shuffle_ps(v139.m_quad, v139.m_quad, 201);
          v226.m_deltaAngles[0].m_quad = v164;
          v226.m_deltaAngles[1].m_quad = v165;
          v167 = _mm_sub_ps(_mm_mul_ps(v164, v166), _mm_mul_ps(_mm_shuffle_ps(v164, v164, 201), v139.m_quad));
          v168 = _mm_mul_ps(_mm_shuffle_ps(v165, v165, 201), v139.m_quad);
          v169 = _mm_shuffle_ps(v167, v167, 201);
          v170 = _mm_mul_ps(v139.m_quad, v153);
          v171 = _mm_sub_ps(_mm_mul_ps(v165, v166), v168);
          v172 = _mm_mul_ps(v169, v169);
          v173 = _mm_shuffle_ps(v171, v171, 201);
          v174 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v172, v172, 85), _mm_shuffle_ps(v172, v172, 0)),
                   _mm_shuffle_ps(v172, v172, 170));
          v175 = _mm_mul_ps(v173, v173);
          v176 = _mm_rsqrt_ps(v174);
          v177 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v175, v175, 85), _mm_shuffle_ps(v175, v175, 0)),
                   _mm_shuffle_ps(v175, v175, 170));
          v178 = _mm_rsqrt_ps(v177);
          v226.m_worstCaseApproachingDelta.m_storage = (float)((float)(_mm_andnot_ps(
                                                                         _mm_cmple_ps(v174, (__m128)0i64),
                                                                         _mm_mul_ps(
                                                                           _mm_mul_ps(
                                                                             _mm_sub_ps(
                                                                               (__m128)_xmm,
                                                                               _mm_mul_ps(_mm_mul_ps(v176, v174), v176)),
                                                                             _mm_mul_ps(v176, *(__m128 *)_xmm)),
                                                                           v174)).m128_f32[0]
                                                                     * _mm_shuffle_ps(
                                                                         (__m128)LODWORD(v151->m_objectRadius),
                                                                         (__m128)LODWORD(v151->m_objectRadius),
                                                                         0).m128_f32[0])
                                                             + (float)(_mm_andnot_ps(
                                                                         _mm_cmple_ps(v177, (__m128)0i64),
                                                                         _mm_mul_ps(
                                                                           _mm_mul_ps(
                                                                             _mm_sub_ps(
                                                                               (__m128)_xmm,
                                                                               _mm_mul_ps(_mm_mul_ps(v178, v177), v178)),
                                                                             _mm_mul_ps(v178, *(__m128 *)_xmm)),
                                                                           v177)).m128_f32[0]
                                                                     * _mm_shuffle_ps(
                                                                         (__m128)LODWORD(v152->m_objectRadius),
                                                                         (__m128)LODWORD(v152->m_objectRadius),
                                                                         0).m128_f32[0]))
                                                     + (float)((float)(_mm_shuffle_ps(v170, v170, 85).m128_f32[0]
                                                                     + _mm_shuffle_ps(v170, v170, 0).m128_f32[0])
                                                             + _mm_shuffle_ps(v170, v170, 170).m128_f32[0]);
          v179 = v150->m_shape;
          v180 = (float *)v149->m_shape;
          v226.m_motionA.m_storage = v151;
          v226.m_motionB.m_storage = v152;
          v168.m128_f32[0] = *(float *)&v179[1].vfptr + v180[8];
          v226.m_stepInfo.m_storage = &v162->m_stepInfo;
          v226.m_linearTimInfo.m_quad = v153;
          LODWORD(v226.m_radiusSum.m_storage) = v168.m128_i32[0];
          LODWORD(v232) = (*(__int64 (__fastcall **)(float *))(*(_QWORD *)v180 + 88i64))(v180);
          v226.m_allocatedNumVertices.m_storage = (int)v232;
          v226.m_numVertices.m_storage = (int)v232;
          v181 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v182 = (hkVector4f *)v181->m_cur;
          v183 = (16 * (_DWORD)v232 + 127) & 0xFFFFFF80;
          v184 = (char *)v182 + v183;
          if ( v183 > v181->m_slabSize || v184 > v181->m_end )
            v182 = (hkVector4f *)hkLifoAllocator::allocateFromNewSlab(v181, v183);
          else
            v181->m_cur = v184;
          v226.m_verticesA.m_storage = v182;
          (*(void (__fastcall **)(float *))(*(_QWORD *)v180 + 96i64))(v180);
          v185 = _mm_shuffle_ps(v226.m_deltaAngles[1].m_quad, v226.m_deltaAngles[1].m_quad, 255).m128_f32[0];
          v186 = _mm_shuffle_ps(v226.m_deltaAngles[0].m_quad, v226.m_deltaAngles[0].m_quad, 255).m128_f32[0];
          v187 = (float)((float)(v185 * v185)
                       * _mm_shuffle_ps((__m128)LODWORD(v152->m_objectRadius), (__m128)LODWORD(v152->m_objectRadius), 0).m128_f32[0])
               + (float)((float)(v186 * v186)
                       * _mm_shuffle_ps((__m128)LODWORD(v151->m_objectRadius), (__m128)LODWORD(v151->m_objectRadius), 0).m128_f32[0]);
          v188 = _mm_unpacklo_ps(aTb.m_rotation.m_col0.m_quad, aTb.m_rotation.m_col1.m_quad);
          v226.m_maxAccel.m_storage = v187;
          v189 = 1.0 / (float)(v187 + 1.4210855e-14);
          v190 = _mm_movelh_ps(v188, aTb.m_rotation.m_col2.m_quad);
          v226.m_invMaxAccel.m_storage = v189;
          v226.m_pointOnPlaneB = (hkVector4f)v228.m_verticesBinB[0];
          v226.m_planeB.m_quad = _mm_add_ps(
                                   _mm_add_ps(
                                     _mm_mul_ps(
                                       _mm_shuffle_ps(_mm_movehl_ps(v190, v188), aTb.m_rotation.m_col2.m_quad, 212),
                                       _mm_shuffle_ps(v216.m_collidingPoint.m_quad, v216.m_collidingPoint.m_quad, 85)),
                                     _mm_mul_ps(
                                       _mm_shuffle_ps(v216.m_collidingPoint.m_quad, v216.m_collidingPoint.m_quad, 0),
                                       v190)),
                                   _mm_mul_ps(
                                     _mm_shuffle_ps(v216.m_collidingPoint.m_quad, v216.m_collidingPoint.m_quad, 170),
                                     _mm_shuffle_ps(
                                       _mm_unpackhi_ps(aTb.m_rotation.m_col0.m_quad, aTb.m_rotation.m_col1.m_quad),
                                       aTb.m_rotation.m_col2.m_quad,
                                       228)));
          if ( v226.m_verticesA.m_storage )
          {
            masterNormal.m_Rtoi.m_storage = 1.0;
            hk4dGskCollidePointsWithPlane(&v226, (hkp4dGskTolerances *)&tol.m_minSafeDeltaRt, &masterNormal);
            v191 = v226.m_verticesA.m_storage;
            v192 = (16 * v226.m_allocatedNumVertices.m_storage + 127) & 0xFFFFFF80;
            v193 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
            v194 = (v192 + 15) & 0xFFFFFFF0;
            if ( v192 > v193->m_slabSize || (char *)v191 + v194 != v193->m_cur || v193->m_firstNonLifoEnd == v191 )
              hkLifoAllocator::slowBlockFree(v193, (char *)v191, v194);
            else
              v193->m_cur = v191;
            if ( masterNormal.m_Rtoi.m_storage < 1.0 )
              *(__m128 *)&v216.m_Rtoi.m_storage = _mm_add_ps(
                                                    _mm_add_ps(
                                                      _mm_add_ps(
                                                        _mm_mul_ps(
                                                          _mm_shuffle_ps(
                                                            masterNormal.m_collidingPoint.m_quad,
                                                            masterNormal.m_collidingPoint.m_quad,
                                                            85),
                                                          bTa.m_rotation.m_col1.m_quad),
                                                        _mm_mul_ps(
                                                          _mm_shuffle_ps(
                                                            masterNormal.m_collidingPoint.m_quad,
                                                            masterNormal.m_collidingPoint.m_quad,
                                                            0),
                                                          bTa.m_rotation.m_col0.m_quad)),
                                                      _mm_mul_ps(
                                                        _mm_shuffle_ps(
                                                          masterNormal.m_collidingPoint.m_quad,
                                                          masterNormal.m_collidingPoint.m_quad,
                                                          170),
                                                        bTa.m_rotation.m_col2.m_quad)),
                                                    bTa.m_translation.m_quad);
          }
        }
        if ( v227.m128_f32[0] < v161.m128_f32[0] )
        {
          *(float *)&v232 = FLOAT_1_2;
          if ( v227.m128_f32[0] <= (float)(_mm_shuffle_ps((__m128)LODWORD(FLOAT_1_2), (__m128)LODWORD(FLOAT_1_2), 0).m128_f32[0]
                                         * v161.m128_f32[0]) )
          {
            hk4dGskCalcPointVelocityAssumingAngularVelError(
              (hkMotionState *)in3->m_bodyA.m_storage->m_motion,
              (hkMotionState *)in3->m_bodyB.m_storage->m_motion,
              (hkVector4f *)&v216,
              &v216.m_collidingPoint,
              &in3->m_linearTimInfo,
              input.m_deltaAngles,
              (hkSimdFloat32 *)&separatingNormalOut,
              &t);
            v161.m128_f32[0] = fmin(0.0, t.m_real.m128_f32[0]);
          }
          else
          {
            v161.m128_i32[0] = v227.m128_i32[0];
          }
        }
        LODWORD(v232) = v129[27];
        v195 = (unsigned int)v232;
        memset(&bTc, 0, sizeof(bTc));
        bTc.m_rotation.m_col1.m_quad.m128_f32[2] = FLOAT_321_0;
        hkpGsk::exitAndExportCacheImpl(&v228, (hkpGskCache *)&tol);
        v196 = in3->m_contactMgr.m_storage;
        v197 = in3->m_input.m_storage;
        *(float *)&v232 = v161.m128_f32[0] * _mm_shuffle_ps((__m128)v195, (__m128)v195, 0).m128_f32[0];
        v198 = ((__int64 (__fastcall *)(hkpContactMgr *, hkpCdBody *, hkpCdBody *, hkpProcessCollisionInput *, hkVector4f *, int, hkp4dGskVertexCollidePointsOutput *, hkp4dGskTolerances *, hkSimdFloat32 **, hkTransformf *))v196->vfptr[3].__first_virtual_table_function__)(
                 v196,
                 in3->m_bodyA.m_storage,
                 in3->m_bodyB.m_storage,
                 v197,
                 v130,
                 v132.m128_i32[0],
                 &v216,
                 &tol,
                 &v232,
                 &bTc);
        v199 = (int)v232;
        if ( !v198 )
        {
          if ( 3.40282e38 != v130[771].m_quad.m128_f32[0] )
            ((void (__fastcall *)(hkpContactMgr *, unsigned __int64, hkVector4f *))in3->m_contactMgr.m_storage->vfptr[4].__vecDelDtor)(
              in3->m_contactMgr.m_storage,
              v130->m_quad.m128_u64[1],
              &v130[773]);
          v200.m_quad = *(__m128 *)&v216.m_Rtoi.m_storage;
          v201.m_quad = (__m128)v216.m_collidingPoint;
          v130[771].m_quad.m128_i32[1] = v199;
          v130[769] = (hkVector4f)v200.m_quad;
          v202.m_quad = (__m128)bTc.m_rotation.m_col0;
          v130[770] = (hkVector4f)v201.m_quad;
          v130[771].m_quad.m128_i32[0] = v132.m128_i32[0];
          v203.m_quad = (__m128)bTc.m_rotation.m_col1;
          v130[773] = (hkVector4f)v202.m_quad;
          v204.m_quad = (__m128)bTc.m_rotation.m_col2;
          v130[774] = (hkVector4f)v203.m_quad;
          v205.m_quad = (__m128)bTc.m_translation;
          v130[775] = (hkVector4f)v204.m_quad;
          v206.m_quad = *(__m128 *)&tol.m_toiSeparation.m_storage;
          v130[776] = (hkVector4f)v205.m_quad;
          v130[772] = (hkVector4f)v206.m_quad;
        }
      }
    }
  }
LABEL_81:
  v207 = input.m_verticesA.m_storage;
  if ( input.m_verticesA.m_storage )
  {
    v208 = (16 * input.m_allocatedNumVertices.m_storage + 127) & 0xFFFFFF80;
    v209 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v210 = (v208 + 15) & 0xFFFFFFF0;
    if ( v208 > v209->m_slabSize || (char *)v207 + v210 != v209->m_cur || v209->m_firstNonLifoEnd == v207 )
      hkLifoAllocator::slowBlockFree(v209, (char *)v207, v210);
    else
      v209->m_cur = v207;
  }
  if ( v228.m_featureChange.m_storage )
    hkpGsk::exitAndExportCacheImpl(&v228, cache);
}on.m_col1;
          v130[773] = (hkVector4f)v202.m_quad;
          v204.m_quad = (__m128)bTc.m_rotation.m_col2;
          v130[774] = (hkVector4f)v203.m_quad;
          v205.m_quad = (__m128)bTc.m_translation;
          v130[775] = (hkVector4f)v204.m_quad;
          v206.m_quad = *(__m128 *)&tol.m_toiSeparation.m_storage;
          v130[776] = (hkVector4f)v205.m_quad;
          v130[772] = (hkVector4f)v206.m_quad;
        }
      }
    }
  }
LABEL_81:
  v207 = input.m_verticesA.m_storage;
  if ( input.m_vertic

