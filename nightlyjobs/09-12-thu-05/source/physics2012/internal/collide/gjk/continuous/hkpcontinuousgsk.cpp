// File Line: 62
// RVA: 0xDBFE60
void __fastcall hk4dGskCollideInitMatrices(hkp4dGskVertexCollidePointsInput *input, hkSimdFloat32 *Rt, hk4dGskCollideMatrices *out)
{
  hkStepInfo *v3; // rax
  hkp4dGskVertexCollidePointsInput *v4; // rsi
  __m128 v5; // xmm6
  hk4dGskCollideMatrices *v6; // rdi
  hkSweptTransformf *v7; // rcx
  signed __int64 v8; // rcx
  signed __int64 v9; // rax
  __m128 v10; // xmm2
  __m128 v11; // xmm1
  __m128 v12; // xmm3
  __m128 v13; // xmm5
  __m128 v14; // xmm4
  __m128 v15; // xmm1
  hkSimdFloat32 tAddOn; // [rsp+20h] [rbp-38h]
  hkSimdFloat32 t; // [rsp+30h] [rbp-28h]

  v3 = input->m_stepInfo.m_storage;
  v4 = input;
  v5 = (__m128)LODWORD(input->m_radiusSum.m_storage);
  v6 = out;
  v7 = &input->m_motionA.m_storage->m_sweptTransform;
  tAddOn.m_real = _mm_mul_ps(
                    _mm_shuffle_ps(
                      (__m128)LODWORD(v3->m_deltaTime.m_storage),
                      (__m128)LODWORD(v3->m_deltaTime.m_storage),
                      0),
                    Rt->m_real);
  t.m_real = _mm_shuffle_ps((__m128)LODWORD(v3->m_startTime.m_storage), (__m128)LODWORD(v3->m_startTime.m_storage), 0);
  hkSweptTransformUtil::lerp2Ha(v7, &t, &tAddOn, &out->m_wTa);
  hkSweptTransformUtil::lerp2Ha(&v4->m_motionB.m_storage->m_sweptTransform, &t, &tAddOn, &v6->m_wTb);
  hkTransformf::setMulInverseMul(&v6->m_aTb, &v6->m_wTa, &v6->m_wTb);
  hkVector4f::setRotatedDir(&v6->m_plane, (hkMatrix3f *)&v6->m_aTb.m_rotation.m_col0, &v4->m_planeB);
  hkVector4f::setTransformedPos(&v6->m_pointOnPlane, &v6->m_aTb, &v4->m_pointOnPlaneB);
  v8 = 2i64;
  v6->m_plane.m_quad = _mm_shuffle_ps(
                         v6->m_plane.m_quad,
                         _mm_unpackhi_ps(v6->m_plane.m_quad, _mm_sub_ps((__m128)0i64, _mm_shuffle_ps(v5, v5, 0))),
                         196);
  v9 = (signed __int64)v6->m_angularVel;
  v6->m_massCenterAinA = v4->m_motionA.m_storage->m_sweptTransform.m_centerOfMassLocal;
  v10 = v6->m_wTa.m_rotation.m_col2.m_quad;
  v11 = _mm_unpacklo_ps(v6->m_wTa.m_rotation.m_col0.m_quad, v6->m_wTa.m_rotation.m_col1.m_quad);
  v12 = _mm_shuffle_ps(
          _mm_unpackhi_ps(v6->m_wTa.m_rotation.m_col0.m_quad, v6->m_wTa.m_rotation.m_col1.m_quad),
          v10,
          228);
  v13 = _mm_movelh_ps(v11, v10);
  v14 = _mm_shuffle_ps(_mm_movehl_ps(v13, v11), v10, 212);
  do
  {
    v15 = *(__m128 *)((char *)v4 - (char *)v6 + v9 - 128);
    v9 += 16i64;
    *(__m128 *)(v9 - 16) = _mm_add_ps(
                             _mm_add_ps(
                               _mm_mul_ps(_mm_shuffle_ps(v15, v15, 85), v14),
                               _mm_mul_ps(_mm_shuffle_ps(v15, v15, 0), v13)),
                             _mm_mul_ps(_mm_shuffle_ps(v15, v15, 170), v12));
    --v8;
  }
  while ( v8 );
  hkVector4f::setTransformedPos(
    &v6->m_massCenterBinA,
    &v6->m_aTb,
    &v4->m_motionB.m_storage->m_sweptTransform.m_centerOfMassLocal);
  hkVector4f::setRotatedInverseDir(&v6->m_linearVel, (hkMatrix3f *)&v6->m_wTa.m_rotation.m_col0, &v4->m_linearTimInfo);
}

// File Line: 350
// RVA: 0xDC0020
void __fastcall hk4dGskCollidePointWithPlaneFinal(hkp4dGskVertexCollidePointsInput *input, hkp4dGskTolerances *tol, hkVector4f *vertexA, hkSimdFloat32 *startRtIn, hkSimdFloat32 *endRtIn, hkSimdFloat32 *distance0In, hkSimdFloat32 *distance1In, hkSimdFloat32 *velocity, hkp4dGskVertexCollidePointsOutput *out, hkSimdFloat32 *toiOut)
{
  hkVector4f *v10; // rdi
  hkp4dGskVertexCollidePointsInput *v11; // rsi
  signed int v12; // ebx
  __m128 v13; // xmm9
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
  hkSimdFloat32 Rt; // [rsp+20h] [rbp-1B8h]
  hk4dGskCollideMatrices v31; // [rsp+30h] [rbp-1A8h]

  v10 = vertexA;
  v11 = input;
  v12 = 0;
  v13 = startRtIn->m_real;
  v14 = _mm_shuffle_ps(
          (__m128)LODWORD(tol->m_toiSeparation.m_storage),
          (__m128)LODWORD(tol->m_toiSeparation.m_storage),
          0);
  v15 = COERCE_FLOAT(
          _mm_shuffle_ps(
            (__m128)LODWORD(tol->m_toiAccuracy.m_storage),
            (__m128)LODWORD(tol->m_toiAccuracy.m_storage),
            0))
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
    if ( !(v12 & 1) )
    {
      v22 = _mm_shuffle_ps((__m128)0x3F666666u, (__m128)0x3F666666u, 0);
      v23 = _mm_cmpltps(v21, v22);
      v21 = _mm_max_ps(
              _mm_shuffle_ps((__m128)0x3DCCCCCDu, (__m128)0x3DCCCCCDu, 0),
              _mm_or_ps(_mm_andnot_ps(v23, v22), _mm_and_ps(v21, v23)));
    }
    v17 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v16, v13), v21), v13);
    Rt.m_real = v17;
    hk4dGskCollideInitMatrices(v11, &Rt, &v31);
    v24 = _mm_mul_ps(_mm_sub_ps(v10->m_quad, v31.m_pointOnPlane.m_quad), v31.m_plane.m_quad);
    v25 = _mm_shuffle_ps(v24, _mm_unpackhi_ps(v24, v31.m_plane.m_quad), 196);
    v26 = _mm_add_ps(_mm_shuffle_ps(v25, v25, 78), v25);
    v27 = _mm_add_ps(_mm_shuffle_ps(v26, v26, 177), v26);
    if ( COERCE_FLOAT((unsigned int)(2 * COERCE_SIGNED_INT(v27.m128_f32[0] - v14.m128_f32[0])) >> 1) < v15 )
      break;
    ++v12;
    v28 = _mm_cmpltps(v27, v14);
    v13 = _mm_or_ps(_mm_andnot_ps(v28, v17), _mm_and_ps(v13, v28));
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
    out->m_collidingPoint = (hkVector4f)v10->m_quad;
    *toiOut = (hkSimdFloat32)v17;
  }
}

// File Line: 460
// RVA: 0xDBE450
void __fastcall hk4dGskCollidePointsWithPlane(hkp4dGskVertexCollidePointsInput *input, hkp4dGskTolerances *tol, hkp4dGskVertexCollidePointsOutput *out)
{
  int v3; // er15
  hkp4dGskVertexCollidePointsOutput *v4; // rsi
  hkp4dGskTolerances *v5; // r12
  hkp4dGskVertexCollidePointsInput *v6; // r13
  __m128 v7; // xmm7
  __m128 v8; // xmm12
  __m128 v9; // xmm13
  __m128 v10; // xmm15
  __m128 v11; // xmm14
  __m128 v12; // xmm6
  hkVector4f *v13; // rbx
  int v14; // er14
  __m128 v15; // xmm8
  float v16; // xmm9_4
  int v17; // er14
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
  hkSimdFloat32 Rt; // [rsp+50h] [rbp-88h]
  hkSimdFloat32 distance0In; // [rsp+60h] [rbp-78h]
  hkSimdFloat32 startRtIn; // [rsp+70h] [rbp-68h]
  hk4dGskCollideMatrices outa; // [rsp+88h] [rbp-50h]
  unsigned int v47; // [rsp+288h] [rbp+1B0h]

  v3 = input->m_numVertices.m_storage;
  v4 = out;
  v5 = tol;
  v6 = input;
  v7 = query.m_quad;
  v8 = _mm_shuffle_ps(
         (__m128)LODWORD(tol->m_toiSeparation.m_storage),
         (__m128)LODWORD(tol->m_toiSeparation.m_storage),
         0);
  v9 = _mm_shuffle_ps(
         (__m128)LODWORD(input->m_invMaxAccel.m_storage),
         (__m128)LODWORD(input->m_invMaxAccel.m_storage),
         0);
  distance0In.m_real = query.m_quad;
  v10 = _mm_shuffle_ps((__m128)LODWORD(input->m_startRt.m_storage), (__m128)LODWORD(input->m_startRt.m_storage), 0);
  v11 = _mm_shuffle_ps(
          (__m128)LODWORD(tol->m_minSeparation.m_storage),
          (__m128)LODWORD(tol->m_minSeparation.m_storage),
          0);
  v12 = v10;
  _mm_store_si128((__m128i *)&startRtIn, (__m128i)v10);
  for ( Rt.m_real = v10; v3; Rt.m_real = v15 )
  {
    hk4dGskCollideInitMatrices(v6, &Rt, &outa);
    v13 = v6->m_verticesA.m_storage;
    v14 = v3;
    v15 = v7;
    v16 = v7.m128_f32[0] - v12.m128_f32[0];
    v3 = 0;
    v17 = v14 - 1;
    v18 = v6->m_verticesA.m_storage;
    v19 = COERCE_FLOAT(
            _mm_shuffle_ps(
              (__m128)LODWORD(v6->m_worstCaseApproachingDelta.m_storage),
              (__m128)LODWORD(v6->m_worstCaseApproachingDelta.m_storage),
              0))
        * (float)(v7.m128_f32[0] - v12.m128_f32[0]);
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
        *(hkSimdFloat32 *)((char *)&Rt + 8) = (hkSimdFloat32)v25;
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
          v47 = LODWORD(v6->m_maxAccel.m_storage);
          if ( (float)((float)(v25.m128_f32[0] - v8.m128_f32[0]) + (float)(v31.m128_f32[0] * v16)) <= (float)((float)((float)(v16 * 0.5) * v16) * COERCE_FLOAT(_mm_shuffle_ps((__m128)v47, (__m128)v47, 0))) )
          {
            if ( v25.m128_f32[0] >= v8.m128_f32[0] )
            {
              v32 = v13->m_quad;
              v33.m_quad = v18->m_quad;
              ++v18;
              ++v3;
              *v13 = (hkVector4f)v33.m_quad;
              v34 = _mm_unpackhi_ps(v32, v25);
              v35 = _mm_mul_ps(_mm_sub_ps(v25, v11), v9);
              v18[-1].m_quad = _mm_shuffle_ps(v32, v34, 196);
              v36 = _mm_add_ps(v35, v35);
              if ( v36.m128_f32[0] <= (float)(v16 * v16) )
              {
                v37 = _mm_sqrt_ps(v36);
                v38 = _mm_cmpleps((__m128)0i64, v31);
                v39 = _mm_mul_ps(v31, v9);
                v40 = _mm_mul_ps(_mm_sub_ps(v8, v11), v9);
                v41 = _mm_add_ps(v40, v40);
                v42 = _mm_or_ps(
                        _mm_andnot_ps(v38, _mm_max_ps(_mm_sub_ps((__m128)0i64, v39), v37)),
                        _mm_and_ps(_mm_add_ps(_mm_add_ps(v39, v39), v37), v38));
                if ( v42.m128_f32[0] <= v16 )
                {
                  v47 = LODWORD(v5->m_minSafeDeltaRt.m_storage);
                  v15 = _mm_min_ps(
                          v15,
                          _mm_add_ps(
                            _mm_max_ps(_mm_add_ps(_mm_sqrt_ps(v41), v42), _mm_shuffle_ps((__m128)v47, (__m128)v47, 0)),
                            v12));
                }
              }
            }
            else if ( v12.m128_f32[0] == v10.m128_f32[0] )
            {
              LODWORD(v4->m_Rtoi.m_storage) = v12.m128_i32[0];
              v7 = v12;
              v4->m_collidingPoint = (hkVector4f)v13->m_quad;
              distance0In.m_real = v12;
            }
            else
            {
              *(hkSimdFloat32 *)((char *)&distance0In + 8) = (hkSimdFloat32)_mm_shuffle_ps(v21, v21, 255);
              hk4dGskCollidePointWithPlaneFinal(
                v6,
                v5,
                v13,
                &startRtIn,
                &Rt,
                (hkSimdFloat32 *)((char *)&distance0In + 8),
                (hkSimdFloat32 *)((char *)&Rt + 8),
                (hkSimdFloat32 *)((char *)&startRtIn + 8),
                v4,
                &distance0In);
              v7 = distance0In.m_real;
            }
          }
        }
        ++v13;
        --v17;
      }
      while ( v17 >= 0 );
    }
    if ( v12.m128_f32[0] > v7.m128_f32[0] || v12.m128_f32[0] == v15.m128_f32[0] && v12.m128_f32[0] >= v7.m128_f32[0] )
      break;
    startRtIn.m_real = v12;
    v12 = v15;
  }
}

// File Line: 650
// RVA: 0xDC0270
void __fastcall hk4dGskCalcSeparatingNormal(hkTransformf *tA, hkTransformf *tB, hkpConvexShape *shapeA, hkpConvexShape *shapeB, hkpGsk *gsk, hkVector4f *separatingNormalOut, hkVector4f *pointOnBInB)
{
  hkpConvexShape *v7; // rbp
  hkTransformf *v8; // rbx
  hkpConvexShape *v9; // rsi
  __m128 v10; // xmm3
  hkVector4f v11; // xmm6
  __m128 v12; // xmm5
  __m128 v13; // xmm1
  __m128 v14; // xmm2
  __m128 v15; // xmm6
  unsigned int v16; // xmm0_4
  hkVector4f v17; // [rsp+30h] [rbp-68h]
  hkTransformf aTb; // [rsp+40h] [rbp-58h]

  v7 = shapeA;
  v8 = tA;
  v9 = shapeB;
  hkTransformf::setMulInverseMul(&aTb, tA, tB);
  hkpGsk::getClosestFeature(gsk, v7, v9, &aTb, &v17);
  v10 = v17.m_quad;
  separatingNormalOut->m_quad = _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_mul_ps(_mm_shuffle_ps(v17.m_quad, v17.m_quad, 85), v8->m_rotation.m_col1.m_quad),
                                    _mm_mul_ps(_mm_shuffle_ps(v17.m_quad, v17.m_quad, 0), v8->m_rotation.m_col0.m_quad)),
                                  _mm_mul_ps(_mm_shuffle_ps(v17.m_quad, v17.m_quad, 170), v8->m_rotation.m_col2.m_quad));
  if ( gsk->m_dimA.m_storage == 1 )
  {
    v11.m_quad = (__m128)gsk->m_verticesA[0];
  }
  else if ( gsk->m_dimB.m_storage == 1 )
  {
    v11.m_quad = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v10, v10, 255), v10), gsk->m_verticesBinA[0].m_quad);
  }
  else
  {
    v11.m_quad = (__m128)gsk->m_closestLineLineResult.m_closestPointA;
  }
  v12 = _mm_shuffle_ps(v10, v10, 255);
  v13 = _mm_unpacklo_ps(aTb.m_rotation.m_col0.m_quad, aTb.m_rotation.m_col1.m_quad);
  v14 = _mm_movelh_ps(v13, aTb.m_rotation.m_col2.m_quad);
  v15 = _mm_sub_ps(_mm_sub_ps(v11.m_quad, _mm_mul_ps(v12, v10)), aTb.m_translation.m_quad);
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
  *(float *)&v16 = v7->m_radius + v9->m_radius;
  separatingNormalOut->m_quad = _mm_shuffle_ps(
                                  separatingNormalOut->m_quad,
                                  _mm_unpackhi_ps(
                                    separatingNormalOut->m_quad,
                                    _mm_sub_ps(v12, _mm_shuffle_ps((__m128)v16, (__m128)v16, 0))),
                                  196);
}

// File Line: 673
// RVA: 0xDC03F0
void __fastcall hk4dGskCalcWorstCaseProjectedVelocity(hkMotionState *msA, hkMotionState *msB, hkVector4f *separatingNormal, hkVector4f *linearTimInfo, hkVector4f *deltaAngles, hkSimdFloat32 *realProjectedLinearDelta, hkSimdFloat32 *projectedAngularDelta)
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
                                        _mm_cmpleps(v16, (__m128)0i64),
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
                                        _mm_cmpleps(v13, (__m128)0i64),
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
void __fastcall hk4dGskCalcPointVelocity(hkMotionState *msA, hkMotionState *msB, hkVector4f *separatingPoint, hkVector4f *separatingNormal, hkVector4f *linearTimInfo, hkVector4f *deltaAngles, hkSimdFloat32 *t, hkSimdFloat32 *separatingVelocity)
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
void __fastcall hk4dGskCalcPointVelocityAssumingAngularVelError(hkMotionState *msA, hkMotionState *msB, hkVector4f *separatingPoint, hkVector4f *separatingNormal, hkVector4f *linearTimInfo, hkVector4f *deltaAngles, hkSimdFloat32 *t, hkSimdFloat32 *separatingVelocity)
{
  __m128 v8; // xmm7
  __m128 v9; // xmm1
  hkSimdFloat32 v10; // xmm6
  __m128 v11; // xmm1
  __m128 v12; // xmm3
  __m128 v13; // xmm3
  __m128 v14; // xmm2
  __m128 v15; // xmm0
  hkSimdFloat32 v16; // xmm4
  __m128 v17; // xmm1
  __m128 v18; // xmm2
  __m128 v19; // xmm2
  __m128 v20; // xmm1
  __m128 v21; // xmm5

  v8 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_1_2), (__m128)LODWORD(FLOAT_1_2), 0);
  v9 = _mm_mul_ps(
         _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), linearTimInfo->m_quad),
         separatingNormal->m_quad);
  v10.m_real = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)),
                 _mm_shuffle_ps(v9, v9, 170));
  *separatingVelocity = (hkSimdFloat32)v10.m_real;
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
  v15 = _mm_cmpleps(v14, (__m128)0i64);
  v16.m_real = _mm_add_ps(
                 _mm_or_ps(_mm_and_ps(_mm_mul_ps(v8, v14), v15), _mm_andnot_ps(v15, _mm_div_ps(v14, v8))),
                 v10.m_real);
  *separatingVelocity = (hkSimdFloat32)v16.m_real;
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
  v21 = _mm_cmpleps((__m128)0i64, v20);
  separatingVelocity->m_real = _mm_sub_ps(
                                 v16.m_real,
                                 _mm_or_ps(
                                   _mm_and_ps(_mm_mul_ps(v8, v20), v21),
                                   _mm_andnot_ps(v21, _mm_div_ps(v20, v8))));
}

// File Line: 765
// RVA: 0xDC07F0
void __fastcall hk4dGskCollPInputInitialize(hkpAgent3ProcessInput *in3, hkp4dGskVertexCollidePointsInput *collPInput)
{
  hkpCdBody *v2; // rax
  hkp4dGskVertexCollidePointsInput *v3; // rdi
  hkpShape *v4; // r9
  hkMotionState *v5; // r14
  float *v6; // rsi
  hkMotionState *v7; // rbp
  int v8; // eax
  int v9; // ebx
  hkLifoAllocator *v10; // rax
  hkVector4f *v11; // rdx
  int v12; // ebx
  char *v13; // rcx
  float v14; // xmm2_4
  float v15; // xmm1_4
  float v16; // xmm2_4

  v2 = in3->m_bodyB.m_storage;
  v3 = collPInput;
  v4 = v2->m_shape;
  v5 = (hkMotionState *)v2->m_motion;
  v6 = (float *)in3->m_bodyA.m_storage->m_shape;
  v7 = (hkMotionState *)in3->m_bodyA.m_storage->m_motion;
  collPInput->m_motionB.m_storage = v5;
  collPInput->m_motionA.m_storage = v7;
  collPInput->m_radiusSum.m_storage = *(float *)&v4[1].vfptr + v6[8];
  collPInput->m_linearTimInfo = in3->m_linearTimInfo;
  collPInput->m_stepInfo.m_storage = &in3->m_input.m_storage->m_stepInfo;
  v8 = (*(__int64 (__fastcall **)(float *))(*(_QWORD *)v6 + 88i64))(v6);
  v3->m_allocatedNumVertices.m_storage = v8;
  v3->m_numVertices.m_storage = v8;
  v9 = v8;
  v10 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v11 = (hkVector4f *)v10->m_cur;
  v12 = (16 * v9 + 127) & 0xFFFFFF80;
  v13 = (char *)v11 + v12;
  if ( v12 > v10->m_slabSize || v13 > v10->m_end )
    v11 = (hkVector4f *)hkLifoAllocator::allocateFromNewSlab(v10, v12);
  else
    v10->m_cur = v13;
  v3->m_verticesA.m_storage = v11;
  (*(void (__fastcall **)(float *))(*(_QWORD *)v6 + 96i64))(v6);
  LODWORD(v14) = (unsigned __int128)_mm_shuffle_ps(v3->m_deltaAngles[1].m_quad, v3->m_deltaAngles[1].m_quad, 255);
  LODWORD(v15) = (unsigned __int128)_mm_shuffle_ps(v3->m_deltaAngles[0].m_quad, v3->m_deltaAngles[0].m_quad, 255);
  v16 = (float)((float)(v14 * v14)
              * COERCE_FLOAT(_mm_shuffle_ps((__m128)LODWORD(v5->m_objectRadius), (__m128)LODWORD(v5->m_objectRadius), 0)))
      + (float)((float)(v15 * v15)
              * COERCE_FLOAT(_mm_shuffle_ps((__m128)LODWORD(v7->m_objectRadius), (__m128)LODWORD(v7->m_objectRadius), 0)));
  v3->m_maxAccel.m_storage = v16;
  v3->m_invMaxAccel.m_storage = 1.0 / (float)(v16 + 1.4210855e-14);
}

// File Line: 815
// RVA: 0xDC0930
void __usercall hk4dGskCalcToiFinal(hkpAgent3ProcessInput *in3@<rcx>, hkp4dGskTolerances *tol@<rdx>, hkpGsk *gsk@<r8>, int featureChange@<r9d>, hkVector4f *a5@<rbx>, hkVector4f *oldMasterNormal, hkVector4f *deltaAngles, hkSimdFloat32 *startRtIn, hkSimdFloat32 *endRtIn, hkSimdFloat32 *distance0In, hkSimdFloat32 *distance1In, hkpProcessCollisionOutput *out)
{
  hkp4dGskTolerances *v12; // r13
  hkpAgent3ProcessInput *v13; // rsi
  int v14; // er15
  hkpGsk *v15; // rdi
  signed int v16; // er14
  __m128 v17; // xmm3
  __m128 v18; // xmm13
  __m128 v19; // xmm12
  __m128 v20; // xmm9
  __m128 v21; // xmm11
  __m128 v22; // xmm10
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
  hkpProcessCollisionInput *v35; // rax
  __m128 v36; // xmm0
  hkpConvexShape **v37; // rax
  __m128 v38; // xmm5
  __m128 v39; // xmm4
  hkVector4f v40; // xmm3
  hkVector4f v41; // xmm4
  __int64 v42; // rdx
  hkVector4f v43; // xmm5
  hkVector4f v44; // xmm6
  __m128 *v45; // rcx
  __m128 v46; // xmm1
  int v47; // er9
  int v48; // er8
  __m128 v49; // xmm1
  __m128 v50; // xmm2
  __m128 v51; // xmm6
  __m128 v52; // xmm2
  unsigned int *v53; // r15
  hkVector4f *v54; // r14
  float v55; // xmm15_4
  __m128 v56; // xmm2
  __m128 v57; // xmm10
  hkpConvexShape **v58; // rax
  hkpCdBody *v59; // r8
  hkpShape *v60; // r11
  signed int v61; // edx
  __m128 v62; // xmm9
  __m128 v63; // xmm8
  __m128i v64; // xmm9
  hkpShape *v65; // r10
  unsigned __int8 v66; // cl
  signed __int16 v67; // ax
  signed __int16 v68; // dx
  hkBaseObjectVtbl *v69; // rax
  signed int v70; // eax
  unsigned __int8 v71; // cl
  signed __int16 v72; // ax
  signed __int16 v73; // dx
  hkBaseObjectVtbl *v74; // r10
  __m128 v75; // xmm6
  hkpConvexShape **v76; // r8
  hkpCdBody *v77; // r9
  hkMotionState *v78; // rbx
  hkMotionState *v79; // r12
  hkVector4f *v80; // rax
  __m128 v81; // xmm5
  hkVector4f v82; // xmm13
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
  int v108; // eax
  hkLifoAllocator *v109; // rax
  hkVector4f *v110; // rdx
  int v111; // er8
  char *v112; // rcx
  float v113; // xmm0_4
  float v114; // xmm1_4
  float v115; // xmm2_4
  float v116; // xmm0_4
  __m128 v117; // xmm1
  float v118; // xmm2_4
  float v119; // xmm0_4
  __m128 v120; // xmm2
  hkVector4f *v121; // r12
  signed int v122; // ebx
  hkLifoAllocator *v123; // rax
  int v124; // er8
  unsigned int v125; // xmm0_4
  hkpContactMgr *v126; // rcx
  hkpProcessCollisionInput *v127; // r9
  int v128; // eax
  int v129; // xmm6_4
  hkVector4f v130; // xmm0
  hkVector4f v131; // xmm1
  __int128 v132; // xmm0
  __int128 v133; // xmm1
  __int128 v134; // xmm0
  __int128 v135; // xmm1
  __m128i v136; // xmm0
  hkVector4f *pointA; // [rsp+28h] [rbp-B0h]
  hkSimdFloat32 tAddOn; // [rsp+50h] [rbp-88h]
  hkSimdFloat32 t; // [rsp+60h] [rbp-78h]
  char masterNormal[24]; // [rsp+70h] [rbp-68h]
  hkVector4f v141; // [rsp+88h] [rbp-50h]
  hkp4dGskVertexCollidePointsOutput v142; // [rsp+98h] [rbp-40h]
  hkTransformf transformOut; // [rsp+B8h] [rbp-20h]
  __int128 v144; // [rsp+F8h] [rbp+20h]
  __int128 v145; // [rsp+108h] [rbp+30h]
  __int128 v146; // [rsp+118h] [rbp+40h]
  __int128 v147; // [rsp+128h] [rbp+50h]
  hkp4dGskVertexCollidePointsInput input; // [rsp+138h] [rbp+60h]
  hkSimdFloat32 v149; // [rsp+1D8h] [rbp+100h]
  hkTransformf bTc; // [rsp+1E8h] [rbp+110h]
  hkTransformf aTb; // [rsp+228h] [rbp+150h]
  hkp4dGskTolerances *tola; // [rsp+340h] [rbp+268h]
  __m128 *retaddr; // [rsp+358h] [rbp+280h]
  hkVector4f *v154; // [rsp+360h] [rbp+288h]
  hkp4dGskTolerances *v155; // [rsp+368h] [rbp+290h]
  __m128 *v156; // [rsp+370h] [rbp+298h]
  __m128 *v157; // [rsp+378h] [rbp+2A0h]

  v155 = tol;
  v12 = tol;
  v13 = in3;
  v14 = featureChange;
  v15 = gsk;
  v16 = 0;
  v17 = *v156;
  v18 = _mm_shuffle_ps((__m128)LODWORD(tol->m_toiAccuracy.m_storage), (__m128)LODWORD(tol->m_toiAccuracy.m_storage), 0);
  v19 = _mm_shuffle_ps(
          (__m128)LODWORD(tol->m_toiSeparation.m_storage),
          (__m128)LODWORD(tol->m_toiSeparation.m_storage),
          0);
  v20 = *(__m128 *)&tol->m_toiSeparation.m_storage;
  v154 = a5;
  v21 = *v157;
  v22 = oldMasterNormal->m_quad;
  v23 = _mm_sub_ps(oldMasterNormal->m_quad, *v157);
  *(float *)&v156 = *(float *)&in3->m_bodyA.m_storage->m_shape[1].vfptr
                  + *(float *)&in3->m_bodyB.m_storage->m_shape[1].vfptr;
  v24 = _mm_shuffle_ps((__m128)(unsigned int)v156, (__m128)(unsigned int)v156, 0);
  *(__m128 *)&v142.m_Rtoi.m_storage = _mm_div_ps(v23, _mm_sub_ps(v17, v20));
  v25 = _mm_sub_ps((__m128)0i64, v18);
  do
  {
    v26 = _mm_sub_ps(v22, v21);
    v27 = _mm_cmpltps(v25, v26);
    v28 = _mm_or_ps(_mm_and_ps(v20, v27), _mm_andnot_ps(v27, v17));
    v29 = v28;
    v30 = _mm_or_ps(_mm_andnot_ps(v27, v26), _mm_and_ps(v27, (__m128)xmmword_141A711B0));
    if ( COERCE_FLOAT((unsigned int)(2 * COERCE_SIGNED_INT(v22.m128_f32[0] - v19.m128_f32[0])) >> 1) >= v18.m128_f32[0] )
    {
      LODWORD(v156) = 1063675494;
      LODWORD(v155) = 1036831949;
      v31 = 0;
      v32 = _mm_shuffle_ps((__m128)0x3F666666u, (__m128)0x3F666666u, 0);
      v33 = _mm_div_ps(_mm_sub_ps(v19, v21), v30);
      v34 = _mm_cmpltps(v33, v32);
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
      v14 = 0;
    }
    v35 = v13->m_input.m_storage;
    tAddOn.m_real = _mm_mul_ps(
                      _mm_shuffle_ps(
                        (__m128)LODWORD(v35->m_stepInfo.m_deltaTime.m_storage),
                        (__m128)LODWORD(v35->m_stepInfo.m_deltaTime.m_storage),
                        0),
                      v29);
    v36 = (__m128)LODWORD(v35->m_stepInfo.m_startTime.m_storage);
    v37 = (hkpConvexShape **)v13->m_bodyA.m_storage;
    t.m_real = _mm_shuffle_ps(v36, v36, 0);
    hkSweptTransformUtil::lerp2Ha((hkSweptTransformf *)&v37[2][1].m_userData, &t, &tAddOn, &transformOut);
    hkSweptTransformUtil::lerp2Ha(
      (hkSweptTransformf *)((char *)v13->m_bodyB.m_storage->m_motion + 64),
      &t,
      &tAddOn,
      &bTc);
    hkTransformf::setMulInverseMul(&aTb, &transformOut, &bTc);
    if ( !v14 )
    {
      v40.m_quad = (__m128)aTb.m_translation;
      v41.m_quad = (__m128)aTb.m_rotation.m_col2;
      v42 = v15->m_dimB.m_storage - 1;
      v43.m_quad = (__m128)aTb.m_rotation.m_col1;
      v44.m_quad = (__m128)aTb.m_rotation.m_col0;
      v45 = (__m128 *)((char *)v15 + 16 * (v42 + 14));
      do
      {
        v46 = *v45;
        --v45;
        --v42;
        v45[-3] = _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v46, v46, 85), v43.m_quad),
                        _mm_mul_ps(_mm_shuffle_ps(v46, v46, 0), v44.m_quad)),
                      _mm_mul_ps(_mm_shuffle_ps(v46, v46, 170), v41.m_quad)),
                    v40.m_quad);
      }
      while ( v42 >= 0 );
      v47 = v15->m_dimB.m_storage;
      v48 = v15->m_dimA.m_storage;
      v49 = _mm_unpacklo_ps(transformOut.m_rotation.m_col0.m_quad, transformOut.m_rotation.m_col1.m_quad);
      v50 = _mm_movelh_ps(v49, transformOut.m_rotation.m_col2.m_quad);
      *(__m128 *)&masterNormal[8] = _mm_add_ps(
                                      _mm_add_ps(
                                        _mm_mul_ps(
                                          _mm_shuffle_ps(
                                            _mm_movehl_ps(v50, v49),
                                            transformOut.m_rotation.m_col2.m_quad,
                                            212),
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
        (hkVector4f *)v15->m_verticesA,
        v15->m_verticesBinA,
        v48,
        v47,
        (hkVector4f *)&masterNormal[8],
        &v141,
        (hkVector4f *)&t.m_real.m128_u16[4]);
      v38 = v141.m_quad;
      goto LABEL_14;
    }
    hkpGsk::getClosestFeature(
      v15,
      (hkpConvexShape *)v13->m_bodyA.m_storage->m_shape,
      (hkpConvexShape *)v13->m_bodyB.m_storage->m_shape,
      &aTb,
      (hkVector4f *)&t.m_real.m128_u16[4]);
    if ( v15->m_dimA.m_storage == 1 )
    {
      v38 = v15->m_verticesA[0].m_quad;
      v141.m_quad = (__m128)v15->m_verticesA[0];
LABEL_14:
      v39 = *(__m128 *)((char *)&t + 8);
      goto LABEL_15;
    }
    v39 = *(__m128 *)((char *)&t + 8);
    if ( v15->m_dimB.m_storage == 1 )
    {
      v38 = _mm_add_ps(
              _mm_mul_ps(
                _mm_shuffle_ps(*(__m128 *)((char *)&t.m_real + 8), *(__m128 *)((char *)&t.m_real + 8), 255),
                *(__m128 *)((char *)&t.m_real + 8)),
              v15->m_verticesBinA[0].m_quad);
      v141.m_quad = v38;
    }
    else
    {
      v38 = v15->m_closestLineLineResult.m_closestPointA.m_quad;
      v141.m_quad = (__m128)v15->m_closestLineLineResult.m_closestPointA;
    }
LABEL_15:
    v51 = _mm_sub_ps(_mm_shuffle_ps(v39, v39, 255), v24);
    if ( COERCE_FLOAT((unsigned int)(2 * COERCE_SIGNED_INT(v51.m128_f32[0] - v19.m128_f32[0])) >> 1) < v18.m128_f32[0] )
      break;
    if ( v31 )
      break;
    if ( v20.m128_f32[0] == v28.m128_f32[0] )
      break;
    ++v16;
    v52 = _mm_cmpltps(v51, v19);
    v17 = _mm_or_ps(_mm_and_ps(v52, v29), _mm_andnot_ps(v52, v28));
    v20 = _mm_or_ps(_mm_andnot_ps(v52, v29), _mm_and_ps(v52, v20));
    v21 = _mm_or_ps(_mm_andnot_ps(v52, v51), _mm_and_ps(v52, v21));
    v22 = _mm_or_ps(_mm_and_ps(v52, v51), _mm_andnot_ps(v52, v22));
  }
  while ( v16 < 10 );
  v53 = (unsigned int *)v13->m_input.m_storage;
  v54 = deltaAngles;
  v55 = v142.m_Rtoi.m_storage;
  v56 = _mm_shuffle_ps(
          (__m128)LODWORD(v12->m_minToiDeltaTime.m_storage),
          (__m128)LODWORD(v12->m_minToiDeltaTime.m_storage),
          0);
  LODWORD(v156) = v53[26];
  v57 = _mm_add_ps(
          _mm_max_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)(unsigned int)v156, (__m128)(unsigned int)v156, 0), v29), v56),
          _mm_shuffle_ps((__m128)v53[24], (__m128)v53[24], 0));
  *(float *)&v156 = deltaAngles[771].m_quad.m128_f32[0];
  v149.m_real = v57;
  if ( v57.m128_f32[0] < COERCE_FLOAT(_mm_shuffle_ps((__m128)(unsigned int)v156, (__m128)(unsigned int)v156, 0)) )
  {
    LODWORD(v156) = v53[25];
    if ( v57.m128_f32[0] < (float)(COERCE_FLOAT(_mm_shuffle_ps((__m128)(unsigned int)v156, (__m128)(unsigned int)v156, 0))
                                 - v56.m128_f32[0]) )
    {
      v58 = (hkpConvexShape **)v13->m_bodyA.m_storage;
      v59 = v13->m_bodyB.m_storage;
      v60 = v13->m_bodyA.m_storage->m_shape;
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
                    _mm_shuffle_ps((__m128)LODWORD(v60[1].vfptr), (__m128)LODWORD(v60[1].vfptr), 0)),
                  v51),
                v62));
      v64 = (__m128i)_mm_shuffle_ps(v62, _mm_unpackhi_ps(v62, v51), 196);
      *(__m128 *)masterNormal = v63;
      *(hkSimdFloat32 *)((char *)&tAddOn + 8) = (hkSimdFloat32)v64;
      _mm_store_si128((__m128i *)&tAddOn, v64);
      v65 = v59->m_shape;
      if ( v59->m_shape->m_type.m_storage == 2 )
      {
        v66 = v15->m_dimB.m_storage;
        LOWORD(v155) = v15->m_verticesBinB[0].m_quad.m128_i16[6];
        v67 = -1;
        v68 = -1;
        LOBYTE(v156) = v66;
        if ( v66 >= 2u )
          v68 = v15->m_verticesBinB[1].m_quad.m128_i16[6];
        WORD1(v155) = v68;
        if ( v66 >= 3u )
          v67 = v15->m_verticesBinB[2].m_quad.m128_i16[6];
        WORD2(v155) = v67;
        v69 = v65->vfptr;
        t.m_real = v63;
        v70 = ((__int64 (__fastcall *)(hkpShape *, hkp4dGskTolerances **, __m128 **, hkSimdFloat32 *, hkTransformf *, hkpShape *, hkTransformf *, hkSimdFloat32 *))v69[6].__first_virtual_table_function__)(
                v65,
                &v155,
                &v156,
                &t,
                &bTc,
                v60,
                &transformOut,
                &tAddOn);
        v63 = t.m_real;
        v64 = (__m128i)tAddOn.m_real;
        *(hkSimdFloat32 *)masterNormal = (hkSimdFloat32)t.m_real;
        goto LABEL_33;
      }
      if ( (*v58)->m_type.m_storage != 2 )
        goto LABEL_60;
      v71 = v15->m_dimA.m_storage;
      LOWORD(v155) = v15->m_verticesA[0].m_quad.m128_i16[6];
      v72 = -1;
      v73 = -1;
      LOBYTE(v156) = v71;
      if ( v71 >= 2u )
        v73 = v15->m_verticesA[1].m_quad.m128_i16[6];
      WORD1(v155) = v73;
      if ( v71 >= 3u )
        v72 = v15->m_verticesA[2].m_quad.m128_i16[6];
      v74 = v60->vfptr;
      WORD2(v155) = v72;
      *(__m128 *)&v142.m_Rtoi.m_storage = _mm_add_ps(
                                            _mm_mul_ps(_mm_shuffle_ps((__m128)v64, (__m128)v64, 255), (__m128)v64),
                                            v63);
      v75 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64);
      tAddOn.m_real = _mm_xor_ps((__m128)v64, v75);
      v70 = ((__int64 (__fastcall *)(hkpShape *, hkp4dGskTolerances **, __m128 **, hkp4dGskVertexCollidePointsOutput *, hkTransformf *, hkpShape *, hkTransformf *, hkSimdFloat32 *))v74[6].__first_virtual_table_function__)(
              v60,
              &v155,
              &v156,
              &v142,
              &transformOut,
              v59->m_shape,
              &bTc,
              &tAddOn);
      v63 = *(__m128 *)masterNormal;
      v64 = (__m128i)_mm_xor_ps(tAddOn.m_real, v75);
      tAddOn.m_real = (__m128)v64;
LABEL_33:
      *(hkSimdFloat32 *)((char *)&tAddOn + 8) = (hkSimdFloat32)v64;
      v61 = v70;
      if ( v70
        || v13->m_input.m_storage->m_collisionQualityInfo.m_storage->m_enableToiWeldRejection.m_bool == (_BYTE)v70 )
      {
LABEL_60:
        v76 = (hkpConvexShape **)v13->m_bodyA.m_storage;
        v77 = v13->m_bodyB.m_storage;
        v78 = (hkMotionState *)v13->m_bodyA.m_storage->m_motion;
        v79 = (hkMotionState *)v77->m_motion;
        v80 = &v13->m_linearTimInfo;
        v81 = v78->m_sweptTransform.m_centerOfMass1.m_quad;
        v82.m_quad = (__m128)v13->m_linearTimInfo;
        v83 = _mm_sub_ps(
                v63,
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_sub_ps(
                        v57,
                        _mm_shuffle_ps(
                          v78->m_sweptTransform.m_centerOfMass0.m_quad,
                          v78->m_sweptTransform.m_centerOfMass0.m_quad,
                          255)),
                      _mm_shuffle_ps(v81, v81, 255)),
                    _mm_sub_ps(v81, v78->m_sweptTransform.m_centerOfMass0.m_quad)),
                  v78->m_sweptTransform.m_centerOfMass0.m_quad));
        v84 = _mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(v83, v83, 201), v154->m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v154->m_quad, v154->m_quad, 201), v83));
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
                _mm_mul_ps(_mm_shuffle_ps(v86, v86, 201), v154[1].m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v154[1].m_quad, v154[1].m_quad, 201), v86));
        v88 = _mm_mul_ps(
                _mm_sub_ps(
                  _mm_add_ps(
                    _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v82.m_quad),
                    _mm_shuffle_ps(v84, v84, 201)),
                  _mm_shuffle_ps(v87, v87, 201)),
                (__m128)v64);
        v89 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v88, v88, 85), _mm_shuffle_ps(v88, v88, 0)),
                _mm_shuffle_ps(v88, v88, 170));
        t.m_real = v89;
        if ( v61 == 1 && v89.m128_f32[0] > (float)(0.0 - 0.00000011920929) )
        {
          v90 = v13->m_input.m_storage;
          LODWORD(input.m_startRt.m_storage) = v29.m128_i32[0];
          v91 = _mm_shuffle_ps((__m128)v64, (__m128)v64, 201);
          *(float *)&v156 = v90->m_stepInfo.m_deltaTime.m_storage;
          v92 = _mm_shuffle_ps((__m128)(unsigned int)v156, (__m128)(unsigned int)v156, 0);
          v93 = _mm_mul_ps(_mm_mul_ps(_mm_shuffle_ps(v81, v81, 255), v92), v78->m_deltaAngle.m_quad);
          input.m_deltaAngles[1].m_quad = _mm_mul_ps(
                                            _mm_mul_ps(_mm_shuffle_ps(v85, v85, 255), v92),
                                            v79->m_deltaAngle.m_quad);
          input.m_deltaAngles[0].m_quad = v93;
          v94 = _mm_sub_ps(_mm_mul_ps(v91, v93), _mm_mul_ps(_mm_shuffle_ps(v93, v93, 201), (__m128)v64));
          v95 = _mm_mul_ps(
                  _mm_shuffle_ps(input.m_deltaAngles[1].m_quad, input.m_deltaAngles[1].m_quad, 201),
                  (__m128)v64);
          v96 = _mm_shuffle_ps(v94, v94, 201);
          v97 = _mm_mul_ps((__m128)v64, v82.m_quad);
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
          input.m_worstCaseApproachingDelta.m_storage = (float)((float)(COERCE_FLOAT(
                                                                          _mm_andnot_ps(
                                                                            _mm_cmpleps(v101, (__m128)0i64),
                                                                            _mm_mul_ps(
                                                                              _mm_mul_ps(
                                                                                _mm_sub_ps(
                                                                                  (__m128)_xmm,
                                                                                  _mm_mul_ps(
                                                                                    _mm_mul_ps(v103, v101),
                                                                                    v103)),
                                                                                _mm_mul_ps(v103, *(__m128 *)_xmm)),
                                                                              v101)))
                                                                      * COERCE_FLOAT(
                                                                          _mm_shuffle_ps(
                                                                            (__m128)LODWORD(v78->m_objectRadius),
                                                                            (__m128)LODWORD(v78->m_objectRadius),
                                                                            0)))
                                                              + (float)(COERCE_FLOAT(
                                                                          _mm_andnot_ps(
                                                                            _mm_cmpleps(v104, (__m128)0i64),
                                                                            _mm_mul_ps(
                                                                              _mm_mul_ps(
                                                                                _mm_sub_ps(
                                                                                  (__m128)_xmm,
                                                                                  _mm_mul_ps(
                                                                                    _mm_mul_ps(v105, v104),
                                                                                    v105)),
                                                                                _mm_mul_ps(v105, *(__m128 *)_xmm)),
                                                                              v104)))
                                                                      * COERCE_FLOAT(
                                                                          _mm_shuffle_ps(
                                                                            (__m128)LODWORD(v79->m_objectRadius),
                                                                            (__m128)LODWORD(v79->m_objectRadius),
                                                                            0))))
                                                      + (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v97, v97, 85))
                                                                      + COERCE_FLOAT(_mm_shuffle_ps(v97, v97, 0)))
                                                              + COERCE_FLOAT(_mm_shuffle_ps(v97, v97, 170)));
          v106 = (float *)*v76;
          v107 = v77->m_shape;
          input.m_motionA.m_storage = v78;
          input.m_motionB.m_storage = v79;
          v155 = (hkp4dGskTolerances *)v106;
          v95.m128_f32[0] = *(float *)&v107[1].vfptr + v106[8];
          input.m_linearTimInfo = (hkVector4f)v82.m_quad;
          input.m_stepInfo.m_storage = &v90->m_stepInfo;
          LODWORD(input.m_radiusSum.m_storage) = v95.m128_i32[0];
          v108 = (*(__int64 (__fastcall **)(float *))(*(_QWORD *)v106 + 88i64))(v106);
          LODWORD(v156) = v108;
          input.m_allocatedNumVertices.m_storage = v108;
          input.m_numVertices.m_storage = v108;
          v109 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v110 = (hkVector4f *)v109->m_cur;
          v111 = (16 * (_DWORD)v156 + 127) & 0xFFFFFF80;
          v112 = (char *)v110 + v111;
          if ( v111 > v109->m_slabSize || v112 > v109->m_end )
            v110 = (hkVector4f *)hkLifoAllocator::allocateFromNewSlab(v109, v111);
          else
            v109->m_cur = v112;
          input.m_verticesA.m_storage = v110;
          (*(void (**)(void))(*(_QWORD *)&v155->m_toiSeparation.m_storage + 96i64))();
          LODWORD(v113) = (unsigned __int128)_mm_shuffle_ps(
                                               input.m_deltaAngles[0].m_quad,
                                               input.m_deltaAngles[0].m_quad,
                                               255);
          LODWORD(v114) = (unsigned __int128)_mm_shuffle_ps(
                                               input.m_deltaAngles[1].m_quad,
                                               input.m_deltaAngles[1].m_quad,
                                               255);
          v115 = COERCE_FLOAT(_mm_shuffle_ps((__m128)LODWORD(v78->m_objectRadius), (__m128)LODWORD(v78->m_objectRadius), 0))
               * (float)(v113 * v113);
          v116 = COERCE_FLOAT(_mm_shuffle_ps((__m128)LODWORD(v79->m_objectRadius), (__m128)LODWORD(v79->m_objectRadius), 0))
               * (float)(v114 * v114);
          v117 = _mm_unpacklo_ps(bTc.m_rotation.m_col0.m_quad, bTc.m_rotation.m_col1.m_quad);
          v118 = v115 + v116;
          input.m_maxAccel.m_storage = v118;
          v119 = 1.0 / (float)(v118 + 1.4210855e-14);
          v120 = _mm_movelh_ps(v117, bTc.m_rotation.m_col2.m_quad);
          input.m_invMaxAccel.m_storage = v119;
          input.m_pointOnPlaneB = (hkVector4f)v15->m_verticesBinB[0];
          input.m_planeB.m_quad = _mm_add_ps(
                                    _mm_add_ps(
                                      _mm_mul_ps(
                                        _mm_shuffle_ps(_mm_movehl_ps(v120, v117), bTc.m_rotation.m_col2.m_quad, 212),
                                        _mm_shuffle_ps(
                                          *(__m128 *)((char *)&tAddOn.m_real + 8),
                                          *(__m128 *)((char *)&tAddOn.m_real + 8),
                                          85)),
                                      _mm_mul_ps(
                                        _mm_shuffle_ps(
                                          *(__m128 *)((char *)&tAddOn.m_real + 8),
                                          *(__m128 *)((char *)&tAddOn.m_real + 8),
                                          0),
                                        v120)),
                                    _mm_mul_ps(
                                      _mm_shuffle_ps(
                                        *(__m128 *)((char *)&tAddOn.m_real + 8),
                                        *(__m128 *)((char *)&tAddOn.m_real + 8),
                                        170),
                                      _mm_shuffle_ps(
                                        _mm_unpackhi_ps(bTc.m_rotation.m_col0.m_quad, bTc.m_rotation.m_col1.m_quad),
                                        bTc.m_rotation.m_col2.m_quad,
                                        228)));
          if ( input.m_verticesA.m_storage )
          {
            v142.m_Rtoi.m_storage = 1.0;
            hk4dGskCollidePointsWithPlane(&input, tola, &v142);
            v121 = input.m_verticesA.m_storage;
            v122 = (16 * input.m_allocatedNumVertices.m_storage + 127) & 0xFFFFFF80;
            v123 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
            v124 = (v122 + 15) & 0xFFFFFFF0;
            if ( v122 > v123->m_slabSize || (char *)v121 + v124 != v123->m_cur || v123->m_firstNonLifoEnd == v121 )
              hkLifoAllocator::slowBlockFree(v123, v121, v124);
            else
              v123->m_cur = v121;
            v80 = &v13->m_linearTimInfo;
            if ( v142.m_Rtoi.m_storage < 1.0 )
              *(__m128 *)masterNormal = _mm_add_ps(
                                          _mm_add_ps(
                                            _mm_add_ps(
                                              _mm_mul_ps(
                                                _mm_shuffle_ps(
                                                  v142.m_collidingPoint.m_quad,
                                                  v142.m_collidingPoint.m_quad,
                                                  85),
                                                transformOut.m_rotation.m_col1.m_quad),
                                              _mm_mul_ps(
                                                _mm_shuffle_ps(
                                                  v142.m_collidingPoint.m_quad,
                                                  v142.m_collidingPoint.m_quad,
                                                  0),
                                                transformOut.m_rotation.m_col0.m_quad)),
                                            _mm_mul_ps(
                                              _mm_shuffle_ps(
                                                v142.m_collidingPoint.m_quad,
                                                v142.m_collidingPoint.m_quad,
                                                170),
                                              transformOut.m_rotation.m_col2.m_quad)),
                                          transformOut.m_translation.m_quad);
          }
          else
          {
            v80 = &v13->m_linearTimInfo;
          }
        }
        if ( v55 < v89.m128_f32[0] )
        {
          *(float *)&tola = FLOAT_1_2;
          if ( v55 <= (float)(COERCE_FLOAT(_mm_shuffle_ps((__m128)LODWORD(FLOAT_1_2), (__m128)LODWORD(FLOAT_1_2), 0))
                            * v89.m128_f32[0]) )
          {
            hk4dGskCalcPointVelocityAssumingAngularVelError(
              (hkMotionState *)v13->m_bodyA.m_storage->m_motion,
              (hkMotionState *)v13->m_bodyB.m_storage->m_motion,
              (hkVector4f *)masterNormal,
              (hkVector4f *)&tAddOn.m_real.m128_u16[4],
              v80,
              v154,
              &v149,
              &t);
            v89.m128_f32[0] = fmin(0.0, t.m_real.m128_f32[0]);
          }
          else
          {
            v89.m128_f32[0] = v55;
          }
        }
        v125 = v53[27];
        v145 = 0i64;
        LODWORD(tola) = v125;
        v144 = 0i64;
        v146 = 0i64;
        v147 = 0i64;
        *((float *)&v145 + 2) = FLOAT_321_0;
        hkpGsk::exitAndExportCacheImpl(v15, (hkpGskCache *)&masterNormal[8]);
        v126 = v13->m_contactMgr.m_storage;
        v127 = v13->m_input.m_storage;
        *(float *)&tola = v89.m128_f32[0] * COERCE_FLOAT(_mm_shuffle_ps((__m128)v125, (__m128)v125, 0));
        LODWORD(pointA) = v57.m128_i32[0];
        v128 = ((__int64 (__fastcall *)(hkpContactMgr *, hkpCdBody *, hkpCdBody *, hkpProcessCollisionInput *, hkVector4f *, hkVector4f *, char *, char *, hkp4dGskTolerances **, __int128 *))v126->vfptr[3].__first_virtual_table_function__)(
                 v126,
                 v13->m_bodyA.m_storage,
                 v13->m_bodyB.m_storage,
                 v127,
                 v54,
                 pointA,
                 masterNormal,
                 &masterNormal[8],
                 &tola,
                 &v144);
        v129 = (signed int)tola;
        if ( !v128 )
        {
          if ( 3.40282e38 != v54[771].m_quad.m128_f32[0] )
            ((void (__fastcall *)(hkpContactMgr *, unsigned __int64, hkVector4f *))v13->m_contactMgr.m_storage->vfptr[4].__vecDelDtor)(
              v13->m_contactMgr.m_storage,
              v54->m_quad.m128_u64[1],
              &v54[773]);
          v130.m_quad = *(__m128 *)masterNormal;
          v131.m_quad = *(__m128 *)((char *)&tAddOn + 8);
          v54[771].m_quad.m128_i32[1] = v129;
          v54[769] = (hkVector4f)v130.m_quad;
          v132 = v144;
          v54[770] = (hkVector4f)v131.m_quad;
          v54[771].m_quad.m128_i32[0] = v57.m128_i32[0];
          v133 = v145;
          v54[773] = (hkVector4f)v132;
          v134 = v146;
          v54[774] = (hkVector4f)v133;
          v135 = v147;
          v54[775] = (hkVector4f)v134;
          v136 = *(__m128i *)&masterNormal[8];
          v54[776] = (hkVector4f)v135;
          _mm_store_si128((__m128i *)&v54[772], v136);
        }
      }
    }
  }
}

// File Line: 1328
// RVA: 0xDBE850
void __fastcall hk4dGskCollideCalcToi(hkpAgent3ProcessInput *in3, hkSimdFloat32 *allowedPenetrationDepth, hkSimdFloat32 *minSeparation, hkSimdFloat32 *toiSeparation, hkpGskCache *gskCache, hkVector4f *separatingNormal, hkpProcessCollisionOutput *out)
{
  hkpProcessCollisionInput *v7; // r10
  __m128 v8; // xmm1
  __m128 v9; // xmm1
  hkSimdFloat32 *v10; // r14
  hkpAgent3ProcessInput *v11; // rdi
  hkpCdBody *v12; // rcx
  __int64 v13; // r8
  hkpConvexShape *v14; // r15
  char v15; // bl
  char v16; // si
  unsigned int *v17; // rax
  __m128 v18; // xmm15
  __m128 v19; // xmm6
  __m128 v20; // xmm2
  __m128 v21; // xmm15
  __m128 v22; // xmm6
  hkpCdBody *v23; // rax
  __m128 *v24; // rdx
  hkpConvexShape *v25; // r12
  unsigned __int64 v26; // rax
  __m128 v27; // xmm0
  __m128 v28; // xmm15
  __m128 v29; // xmm2
  __m128 v30; // xmm1
  __m128 v31; // xmm1
  hkBaseObjectVtbl *v32; // rax
  __m128 *v33; // r13
  __m128 v34; // xmm13
  __m128 v35; // xmm9
  int v36; // er14
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
  hkVector4f v54; // xmm5
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
  hkStepInfo *v66; // rax
  float v67; // xmm0_4
  int v68; // eax
  int v69; // ebx
  hkLifoAllocator *v70; // rax
  hkVector4f *v71; // rdx
  int v72; // ebx
  char *v73; // rcx
  float v74; // xmm0_4
  float v75; // xmm1_4
  float v76; // xmm2_4
  float v77; // xmm0_4
  __m128 v78; // xmm1
  hkpProcessCollisionInput *v79; // rax
  hkpConvexShape *v80; // r12
  hkpConvexShape *v81; // r15
  bool v82; // zf
  __m128 v83; // xmm2
  __m128 v84; // xmm7
  hkVector4f v85; // xmm8
  hkSimdFloat32 *v86; // rax
  __m128 v87; // xmm1
  __m128 v88; // xmm6
  __m128 v89; // xmm8
  __m128 v90; // xmm2
  __m128 v91; // xmm8
  __m128 v92; // xmm1
  __m128 v93; // xmm5
  __m128 v94; // xmm2
  __m128 v95; // xmm7
  __m128 v96; // xmm4
  __m128 v97; // xmm4
  __m128 v98; // xmm0
  hkVector4f v99; // xmm4
  signed int v100; // esi
  __m128 v101; // xmm15
  __m128 v102; // xmm14
  __m128 v103; // xmm3
  __m128 v104; // xmm2
  __m128 v105; // xmm12
  __m128 v106; // xmm1
  __m128 v107; // xmm4
  __m128 v108; // xmm12
  __m128 v109; // xmm4
  __m128 v110; // xmm8
  char v111; // bl
  __m128 v112; // xmm1
  __m128 v113; // xmm3
  __m128 v114; // xmm0
  hkpProcessCollisionInput *v115; // rax
  __m128 v116; // xmm0
  hkpCdBody *v117; // rax
  __m128 v118; // xmm5
  __m128 v119; // xmm4
  hkVector4f v120; // xmm3
  hkVector4f v121; // xmm4
  __int64 v122; // rdx
  hkVector4f v123; // xmm5
  hkVector4f v124; // xmm6
  __m128 *v125; // rcx
  __m128 v126; // xmm1
  __m128 v127; // xmm1
  __m128 v128; // xmm2
  __m128 v129; // xmm6
  __m128 v130; // xmm2
  unsigned int *v131; // r14
  hkVector4f *v132; // rsi
  __m128 v133; // xmm2
  __m128 v134; // xmm10
  hkpConvexShape **v135; // rax
  hkpCdBody *v136; // r8
  hkpShape *v137; // r11
  signed int v138; // edx
  __m128 v139; // xmm9
  __m128 v140; // xmm7
  hkVector4f v141; // xmm9
  hkpShape *v142; // r10
  __int16 v143; // ax
  __int16 v144; // dx
  hkBaseObjectVtbl *v145; // rax
  signed int v146; // eax
  __int16 v147; // ax
  __int16 v148; // dx
  hkBaseObjectVtbl *v149; // r10
  __m128 v150; // xmm6
  hkpConvexShape **v151; // r13
  hkpCdBody *v152; // rax
  hkMotionState *v153; // rbx
  hkMotionState *v154; // r15
  hkVector4f v155; // xmm14
  __m128 v156; // xmm5
  __m128 v157; // xmm4
  __m128 v158; // xmm4
  __m128 v159; // xmm13
  __m128 v160; // xmm7
  __m128 v161; // xmm7
  __m128 v162; // xmm1
  __m128 v163; // xmm11
  hkpProcessCollisionInput *v164; // rcx
  __m128 v165; // xmm1
  __m128 v166; // xmm5
  __m128 v167; // xmm13
  __m128 v168; // xmm1
  __m128 v169; // xmm5
  __m128 v170; // xmm0
  __m128 v171; // xmm5
  __m128 v172; // xmm9
  __m128 v173; // xmm13
  __m128 v174; // xmm5
  __m128 v175; // xmm13
  __m128 v176; // xmm6
  __m128 v177; // xmm13
  __m128 v178; // xmm3
  __m128 v179; // xmm7
  __m128 v180; // xmm4
  hkpShape *v181; // rax
  float *v182; // r13
  int v183; // eax
  hkLifoAllocator *v184; // rax
  hkVector4f *v185; // rdx
  int v186; // er8
  char *v187; // rcx
  float v188; // xmm2_4
  float v189; // xmm1_4
  float v190; // xmm2_4
  __m128 v191; // xmm1
  float v192; // xmm0_4
  __m128 v193; // xmm2
  hkVector4f *v194; // r15
  signed int v195; // ebx
  hkLifoAllocator *v196; // rax
  int v197; // er8
  unsigned int v198; // xmm0_4
  hkpContactMgr *v199; // rcx
  hkpProcessCollisionInput *v200; // r9
  int v201; // eax
  int v202; // xmm6_4
  hkVector4f v203; // xmm0
  hkVector4f v204; // xmm1
  hkVector4f v205; // xmm0
  hkVector4f v206; // xmm1
  hkVector4f v207; // xmm0
  hkVector4f v208; // xmm1
  __m128i v209; // xmm0
  hkVector4f *v210; // rdi
  signed int v211; // ebx
  hkLifoAllocator *v212; // rax
  int v213; // er8
  hkVector4f *pointA; // [rsp+28h] [rbp-D0h]
  hkSimdFloat32 t; // [rsp+50h] [rbp-A8h]
  hkpConvexShape *shapeA[2]; // [rsp+60h] [rbp-98h]
  hkp4dGskTolerances tol; // [rsp+70h] [rbp-88h]
  unsigned int v218; // [rsp+84h] [rbp-74h]
  unsigned int v219; // [rsp+88h] [rbp-70h]
  hkp4dGskVertexCollidePointsOutput v220; // [rsp+98h] [rbp-60h]
  hkVector4f v221; // [rsp+B8h] [rbp-40h]
  hkpConvexShape *shapeB[2]; // [rsp+C8h] [rbp-30h]
  hkVector4f separatingNormalOut; // [rsp+D8h] [rbp-20h]
  hkVector4f masterNormal; // [rsp+E8h] [rbp-10h]
  __m128 v225; // [rsp+F8h] [rbp+0h]
  hkTransformf bTa; // [rsp+108h] [rbp+10h]
  hkTransformf bTc; // [rsp+148h] [rbp+50h]
  hkTransformf aTb; // [rsp+188h] [rbp+90h]
  hkp4dGskVertexCollidePointsInput input; // [rsp+1C8h] [rbp+D0h]
  hkTransformf transformOut; // [rsp+268h] [rbp+170h]
  hkp4dGskVertexCollidePointsInput v231; // [rsp+2A8h] [rbp+1B0h]
  __m128 v232; // [rsp+348h] [rbp+250h]
  hkpGsk v233; // [rsp+358h] [rbp+260h]
  float retaddr; // [rsp+5E8h] [rbp+4F0h]
  __m128 *v235; // [rsp+5F0h] [rbp+4F8h]
  __m128 *v236; // [rsp+5F8h] [rbp+500h]
  hkSimdFloat32 *v237; // [rsp+600h] [rbp+508h]
  hkpGskCache *cache; // [rsp+608h] [rbp+510h]

  cache = (hkpGskCache *)toiSeparation;
  v237 = minSeparation;
  v7 = in3->m_input.m_storage;
  v8 = toiSeparation->m_real;
  LODWORD(tol.m_minToiDeltaTime.m_storage) = *minSeparation;
  LODWORD(tol.m_minSafeDeltaRt.m_storage) = v8.m128_i32[0];
  v9 = _mm_shuffle_ps(
         (__m128)LODWORD(v7->m_stepInfo.m_invDeltaTime.m_storage),
         (__m128)LODWORD(v7->m_stepInfo.m_invDeltaTime.m_storage),
         0);
  v10 = toiSeparation;
  v11 = in3;
  v12 = in3->m_bodyA.m_storage;
  v13 = (unsigned __int8)toiSeparation->m_real.m128_i8[8];
  v14 = (hkpConvexShape *)v12->m_shape;
  v15 = 0;
  v16 = 0;
  *(_QWORD *)&v233.m_doNotHandlePenetration.m_storage = 0i64;
  v233.m_dimA.m_storage = v13;
  shapeA[0] = v14;
  v17 = (unsigned int *)v7->m_collisionQualityInfo.m_storage;
  v18 = _mm_shuffle_ps((__m128)v17[8], (__m128)v17[8], 0);
  v19 = _mm_shuffle_ps((__m128)v17[12], (__m128)v17[12], 0);
  v20 = (__m128)v17[9];
  v218 = v17[14];
  v21 = _mm_mul_ps(v18, allowedPenetrationDepth->m_real);
  v22 = _mm_mul_ps(v19, allowedPenetrationDepth->m_real);
  v23 = v11->m_bodyB.m_storage;
  v24 = (__m128 *)v12->m_motion;
  LODWORD(v12) = (unsigned __int8)toiSeparation->m_real.m128_i8[10];
  v25 = (hkpConvexShape *)v23->m_shape;
  v26 = (unsigned __int64)v23->m_motion;
  input.m_verticesA.m_storage = 0i64;
  masterNormal.m_quad = v22;
  v219 = v22.m128_i32[0];
  retaddr = v7->m_stepInfo.m_deltaTime.m_storage;
  v27 = v24[5];
  v221.m_quad.m128_u64[0] = v26;
  shapeB[0] = v25;
  v235 = v24;
  v28 = _mm_mul_ps(_mm_max_ps(v21, _mm_shuffle_ps(v20, v20, 0)), v9);
  v29 = _mm_shuffle_ps((__m128)LODWORD(retaddr), (__m128)LODWORD(retaddr), 0);
  v30 = *(__m128 *)(v26 + 80);
  LODWORD(tol.m_toiAccuracy.m_storage) = v28.m128_i32[0];
  v31 = _mm_mul_ps(_mm_mul_ps(_mm_shuffle_ps(v30, v30, 255), v29), *(__m128 *)(v26 + 144));
  LODWORD(v26) = (unsigned __int8)toiSeparation->m_real.m128_i8[9];
  input.m_deltaAngles[0].m_quad = _mm_mul_ps(_mm_mul_ps(_mm_shuffle_ps(v27, v27, 255), v29), v24[9]);
  v233.m_dimB.m_storage = v26;
  v233.m_maxDimA.m_storage = (unsigned __int8)v12 & 0xF;
  input.m_deltaAngles[1].m_quad = v31;
  v32 = v14->vfptr;
  *(_QWORD *)&v233.m_maxDimB.m_storage = (unsigned int)v12 >> 4;
  ((void (__fastcall *)(hkpConvexShape *, hkSimdFloat32 *, __int64, hkcdVertex *))v32[4].__first_virtual_table_function__)(
    v14,
    toiSeparation,
    v13,
    v233.m_verticesA);
  ((void (__fastcall *)(hkpConvexShape *, signed __int64, _QWORD, hkcdVertex *))v25->vfptr[4].__first_virtual_table_function__)(
    v25,
    (signed __int64)v10 + 2 * v233.m_dimA.m_storage,
    (unsigned int)v233.m_dimB.m_storage,
    v233.m_verticesBinB);
  v33 = (__m128 *)gskCache;
  v34 = 0i64;
  v35 = 0i64;
  v36 = 1;
  v37 = _mm_shuffle_ps(*(__m128 *)gskCache->m_vertices, *(__m128 *)gskCache->m_vertices, 255);
  v38 = v37;
  v39 = 0i64;
  if ( v37.m128_f32[0] > (float)(v22.m128_f32[0] + v237->m_real.m128_f32[0]) )
  {
    do
    {
      v40 = _mm_sub_ps(query.m_quad, v35);
      if ( v40.m128_f32[0] <= 0.0 )
        goto LABEL_81;
      v41 = *v33;
      v42 = v235;
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
      v54.m_quad = (__m128)v11->m_linearTimInfo;
      v55 = _mm_add_ps(
              _mm_mul_ps(
                _mm_andnot_ps(
                  _mm_cmpleps(v50, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v51, v50), v51)),
                      _mm_mul_ps(v51, *(__m128 *)_xmm)),
                    v50)),
                _mm_shuffle_ps((__m128)v235[10].m128_u32[0], (__m128)v235[10].m128_u32[0], 0)),
              _mm_mul_ps(
                _mm_andnot_ps(
                  _mm_cmpleps(v52, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v53, v52), v53)),
                      _mm_mul_ps(v53, *(__m128 *)_xmm)),
                    v52)),
                _mm_shuffle_ps(
                  (__m128)*(unsigned int *)(v221.m_quad.m128_u64[0] + 160),
                  (__m128)*(unsigned int *)(v221.m_quad.m128_u64[0] + 160),
                  0)));
      v56 = _mm_mul_ps(v11->m_linearTimInfo.m_quad, *v33);
      v57 = _mm_shuffle_ps(v41, v41, 255);
      v58 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v56, v56, 85), _mm_shuffle_ps(v56, v56, 0)),
              _mm_shuffle_ps(v56, v56, 170));
      v59 = _mm_add_ps(v58, v55);
      if ( _mm_movemask_ps(_mm_or_ps(_mm_cmpltps(*v236, _mm_sub_ps(v57, _mm_mul_ps(v40, v59))), _mm_cmpleps(v59, (__m128)0i64))) )
        goto LABEL_81;
      v60 = _mm_div_ps(_mm_sub_ps(v57, *v236), v59);
      if ( v60.m128_f32[0] < 0.2 && !v16 && v15 && v58.m128_f32[0] < v55.m128_f32[0] )
      {
        if ( input.m_verticesA.m_storage )
          goto LABEL_91;
        v61 = v11->m_bodyB.m_storage;
        v62 = v61->m_shape;
        v63 = (hkMotionState *)v61->m_motion;
        v64 = (float *)v11->m_bodyA.m_storage->m_shape;
        v65 = (hkMotionState *)v11->m_bodyA.m_storage->m_motion;
        v66 = (hkStepInfo *)v11->m_input.m_storage;
        input.m_motionB.m_storage = v63;
        input.m_motionA.m_storage = v65;
        v67 = *(float *)&v62[1].vfptr + v64[8];
        input.m_stepInfo.m_storage = v66 + 6;
        input.m_linearTimInfo = (hkVector4f)v54.m_quad;
        input.m_radiusSum.m_storage = v67;
        v68 = (*(__int64 (__fastcall **)(float *))(*(_QWORD *)v64 + 88i64))(v64);
        v69 = v68;
        input.m_allocatedNumVertices.m_storage = v68;
        input.m_numVertices.m_storage = v68;
        v70 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v71 = (hkVector4f *)v70->m_cur;
        v72 = (16 * v69 + 127) & 0xFFFFFF80;
        v73 = (char *)v71 + v72;
        if ( v72 > v70->m_slabSize || v73 > v70->m_end )
          v71 = (hkVector4f *)hkLifoAllocator::allocateFromNewSlab(v70, v72);
        else
          v70->m_cur = v73;
        input.m_verticesA.m_storage = v71;
        (*(void (__fastcall **)(float *))(*(_QWORD *)v64 + 96i64))(v64);
        LODWORD(v74) = (unsigned __int128)_mm_shuffle_ps(
                                            input.m_deltaAngles[1].m_quad,
                                            input.m_deltaAngles[1].m_quad,
                                            255);
        LODWORD(v75) = (unsigned __int128)_mm_shuffle_ps(
                                            input.m_deltaAngles[0].m_quad,
                                            input.m_deltaAngles[0].m_quad,
                                            255);
        v76 = (float)(COERCE_FLOAT(_mm_shuffle_ps((__m128)LODWORD(v63->m_objectRadius), (__m128)LODWORD(v63->m_objectRadius), 0))
                    * (float)(v74 * v74))
            + (float)(COERCE_FLOAT(_mm_shuffle_ps((__m128)LODWORD(v65->m_objectRadius), (__m128)LODWORD(v65->m_objectRadius), 0))
                    * (float)(v75 * v75));
        input.m_maxAccel.m_storage = v76;
        input.m_invMaxAccel.m_storage = 1.0 / (float)(v76 + 1.4210855e-14);
        if ( input.m_verticesA.m_storage )
        {
LABEL_91:
          LODWORD(input.m_startRt.m_storage) = v35.m128_i32[0];
          LODWORD(input.m_worstCaseApproachingDelta.m_storage) = v59.m128_i32[0];
          v220.m_Rtoi.m_storage = 1.0;
          hk4dGskCollidePointsWithPlane(&input, (hkp4dGskTolerances *)((char *)&tol + 8), &v220);
          v16 = 0;
          v77 = v60.m128_f32[0] + v60.m128_f32[0];
          v78 = _mm_sub_ps(
                  _mm_shuffle_ps((__m128)LODWORD(v220.m_Rtoi.m_storage), (__m128)LODWORD(v220.m_Rtoi.m_storage), 0),
                  v35);
          v60 = _mm_max_ps(v60, v78);
          if ( v78.m128_f32[0] < v77 )
            v16 = 1;
        }
        else
        {
          v16 = 1;
        }
        v42 = v235;
      }
      if ( (float)(v60.m128_f32[0] + v35.m128_f32[0]) >= 1.0 )
        goto LABEL_81;
      v79 = v11->m_input.m_storage;
      v34 = *v33;
      v39 = v35;
      v37 = _mm_shuffle_ps(v34, v34, 255);
      v35 = _mm_min_ps(_mm_add_ps(v35, _mm_max_ps(v28, v60)), query.m_quad);
      *(__m128 *)&tol.m_toiSeparation.m_storage = _mm_mul_ps(
                                                    _mm_shuffle_ps(
                                                      (__m128)LODWORD(v79->m_stepInfo.m_deltaTime.m_storage),
                                                      (__m128)LODWORD(v79->m_stepInfo.m_deltaTime.m_storage),
                                                      0),
                                                    v35);
      t.m_real = _mm_shuffle_ps(
                   (__m128)LODWORD(v79->m_stepInfo.m_startTime.m_storage),
                   (__m128)LODWORD(v79->m_stepInfo.m_startTime.m_storage),
                   0);
      hkSweptTransformUtil::lerp2Ha((hkSweptTransformf *)&v42[4], &t, (hkSimdFloat32 *)&tol, &transformOut);
      hkSweptTransformUtil::lerp2Ha(
        (hkSweptTransformf *)(v221.m_quad.m128_u64[0] + 64),
        &t,
        (hkSimdFloat32 *)&tol,
        &bTc);
      hkTransformf::setMulInverseMul(&aTb, &transformOut, &bTc);
      v80 = shapeB[0];
      v81 = shapeA[0];
      hkpGsk::getClosestFeature(&v233, shapeA[0], shapeB[0], &aTb, &separatingNormalOut);
      v82 = v233.m_dimA.m_storage == 1;
      v83 = separatingNormalOut.m_quad;
      v84 = _mm_add_ps(
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
      *v33 = v84;
      if ( v82 )
      {
        v85.m_quad = (__m128)v233.m_verticesA[0];
      }
      else if ( v233.m_dimB.m_storage == 1 )
      {
        v85.m_quad = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v83, v83, 255), v83), v233.m_verticesBinA[0].m_quad);
      }
      else
      {
        v85.m_quad = (__m128)v233.m_closestLineLineResult.m_closestPointA;
      }
      v86 = v237;
      v36 = v233.m_featureChange.m_storage;
      v15 = 1;
      v87 = _mm_unpacklo_ps(aTb.m_rotation.m_col0.m_quad, aTb.m_rotation.m_col1.m_quad);
      v88 = _mm_shuffle_ps(v83, v83, 255);
      v89 = _mm_sub_ps(v85.m_quad, _mm_mul_ps(v83, v88));
      v90 = _mm_movelh_ps(v87, aTb.m_rotation.m_col2.m_quad);
      v91 = _mm_sub_ps(v89, aTb.m_translation.m_quad);
      input.m_pointOnPlaneB.m_quad = _mm_add_ps(
                                       _mm_add_ps(
                                         _mm_mul_ps(
                                           _mm_shuffle_ps(_mm_movehl_ps(v90, v87), aTb.m_rotation.m_col2.m_quad, 212),
                                           _mm_shuffle_ps(v91, v91, 85)),
                                         _mm_mul_ps(_mm_shuffle_ps(v91, v91, 0), v90)),
                                       _mm_mul_ps(
                                         _mm_shuffle_ps(v91, v91, 170),
                                         _mm_shuffle_ps(
                                           _mm_unpackhi_ps(aTb.m_rotation.m_col0.m_quad, aTb.m_rotation.m_col1.m_quad),
                                           aTb.m_rotation.m_col2.m_quad,
                                           228)));
      *(float *)&gskCache = v80->m_radius + v81->m_radius;
      v92 = _mm_unpacklo_ps(bTc.m_rotation.m_col0.m_quad, bTc.m_rotation.m_col1.m_quad);
      v93 = _mm_shuffle_ps(
              _mm_unpackhi_ps(bTc.m_rotation.m_col0.m_quad, bTc.m_rotation.m_col1.m_quad),
              bTc.m_rotation.m_col2.m_quad,
              228);
      v94 = _mm_movelh_ps(v92, bTc.m_rotation.m_col2.m_quad);
      v95 = _mm_shuffle_ps(
              v84,
              _mm_unpackhi_ps(
                v84,
                _mm_sub_ps(v88, _mm_shuffle_ps((__m128)(unsigned int)gskCache, (__m128)(unsigned int)gskCache, 0))),
              196);
      v96 = _mm_shuffle_ps(_mm_movehl_ps(v94, v92), bTc.m_rotation.m_col2.m_quad, 212);
      *v33 = v95;
      v97 = _mm_add_ps(_mm_mul_ps(v96, _mm_shuffle_ps(v95, v95, 85)), _mm_mul_ps(_mm_shuffle_ps(v95, v95, 0), v94));
      v98 = _mm_shuffle_ps(v95, v95, 170);
      v38 = _mm_shuffle_ps(v95, v95, 255);
      v99.m_quad = _mm_add_ps(v97, _mm_mul_ps(v98, v93));
      v98.m128_f32[0] = masterNormal.m_quad.m128_f32[0] + v86->m_real.m128_f32[0];
      input.m_planeB = (hkVector4f)v99.m_quad;
    }
    while ( v38.m128_f32[0] > v98.m128_f32[0] );
  }
  v100 = 0;
  v101 = _mm_shuffle_ps((__m128)v219, (__m128)v219, 0);
  v102 = _mm_shuffle_ps(
           (__m128)LODWORD(tol.m_minSafeDeltaRt.m_storage),
           (__m128)LODWORD(tol.m_minSafeDeltaRt.m_storage),
           0);
  *(float *)&v237 = *(float *)&v11->m_bodyA.m_storage->m_shape[1].vfptr
                  + *(float *)&v11->m_bodyB.m_storage->m_shape[1].vfptr;
  separatingNormalOut.m_quad = _mm_shuffle_ps((__m128)(unsigned int)v237, (__m128)(unsigned int)v237, 0);
  v103 = _mm_sub_ps((__m128)0i64, v101);
  *(__m128 *)shapeA = v103;
  v232 = _mm_div_ps(_mm_sub_ps(v38, v37), _mm_sub_ps(v35, v39));
  do
  {
    v104 = _mm_sub_ps(v38, v37);
    v105 = _mm_cmpltps(v103, v104);
    v106 = _mm_andnot_ps(v105, v104);
    v107 = _mm_and_ps(v105, (__m128)xmmword_141A711B0);
    v108 = _mm_or_ps(_mm_andnot_ps(v105, v35), _mm_and_ps(v105, v39));
    v109 = _mm_or_ps(v107, v106);
    v110 = v108;
    if ( COERCE_FLOAT((unsigned int)(2 * COERCE_SIGNED_INT(v38.m128_f32[0] - v102.m128_f32[0])) >> 1) >= v101.m128_f32[0] )
    {
      LODWORD(v237) = 1063675494;
      LODWORD(v236) = 1036831949;
      v111 = 0;
      v112 = _mm_shuffle_ps((__m128)0x3F666666u, (__m128)0x3F666666u, 0);
      v113 = _mm_div_ps(_mm_sub_ps(v102, v37), v109);
      v114 = _mm_cmpltps(v113, v112);
      v110 = _mm_add_ps(
               _mm_mul_ps(
                 _mm_sub_ps(v108, v39),
                 _mm_max_ps(
                   _mm_shuffle_ps((__m128)0x3DCCCCCDu, (__m128)0x3DCCCCCDu, 0),
                   _mm_or_ps(_mm_and_ps(v113, v114), _mm_andnot_ps(v114, v112)))),
               v39);
    }
    else
    {
      v111 = 1;
      v36 = 0;
    }
    v115 = v11->m_input.m_storage;
    t.m_real = _mm_mul_ps(
                 _mm_shuffle_ps(
                   (__m128)LODWORD(v115->m_stepInfo.m_deltaTime.m_storage),
                   (__m128)LODWORD(v115->m_stepInfo.m_deltaTime.m_storage),
                   0),
                 v110);
    v116 = (__m128)LODWORD(v115->m_stepInfo.m_startTime.m_storage);
    v117 = v11->m_bodyA.m_storage;
    *(__m128 *)&tol.m_toiSeparation.m_storage = _mm_shuffle_ps(v116, v116, 0);
    hkSweptTransformUtil::lerp2Ha((hkSweptTransformf *)((char *)v117->m_motion + 64), (hkSimdFloat32 *)&tol, &t, &bTa);
    hkSweptTransformUtil::lerp2Ha(
      (hkSweptTransformf *)((char *)v11->m_bodyB.m_storage->m_motion + 64),
      (hkSimdFloat32 *)&tol,
      &t,
      &aTb);
    hkTransformf::setMulInverseMul(&transformOut, &bTa, &aTb);
    if ( !v36 )
    {
      v120.m_quad = (__m128)transformOut.m_translation;
      v121.m_quad = (__m128)transformOut.m_rotation.m_col2;
      v122 = v233.m_dimB.m_storage - 1;
      v123.m_quad = (__m128)transformOut.m_rotation.m_col1;
      v124.m_quad = (__m128)transformOut.m_rotation.m_col0;
      v125 = &v233.m_verticesBinB[v122].m_quad;
      do
      {
        v126 = *v125;
        --v125;
        --v122;
        v125[-3] = _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v126, v126, 85), v123.m_quad),
                         _mm_mul_ps(_mm_shuffle_ps(v126, v126, 0), v124.m_quad)),
                       _mm_mul_ps(_mm_shuffle_ps(v126, v126, 170), v121.m_quad)),
                     v120.m_quad);
      }
      while ( v122 >= 0 );
      v127 = _mm_unpacklo_ps(bTa.m_rotation.m_col0.m_quad, bTa.m_rotation.m_col1.m_quad);
      v128 = _mm_movelh_ps(v127, bTa.m_rotation.m_col2.m_quad);
      masterNormal.m_quad = _mm_add_ps(
                              _mm_add_ps(
                                _mm_mul_ps(
                                  _mm_shuffle_ps(_mm_movehl_ps(v128, v127), bTa.m_rotation.m_col2.m_quad, 212),
                                  _mm_shuffle_ps(v34, v34, 85)),
                                _mm_mul_ps(_mm_shuffle_ps(v34, v34, 0), v128)),
                              _mm_mul_ps(
                                _mm_shuffle_ps(
                                  _mm_unpackhi_ps(bTa.m_rotation.m_col0.m_quad, bTa.m_rotation.m_col1.m_quad),
                                  bTa.m_rotation.m_col2.m_quad,
                                  228),
                                _mm_shuffle_ps(v34, v34, 170)));
      hkGskRecalcContactInternal(
        (hkVector4f *)v233.m_verticesA,
        v233.m_verticesBinA,
        v233.m_dimA.m_storage,
        v233.m_dimB.m_storage,
        &masterNormal,
        &v221,
        (hkVector4f *)shapeB);
      v118 = v221.m_quad;
      goto LABEL_38;
    }
    hkpGsk::getClosestFeature(
      &v233,
      (hkpConvexShape *)v11->m_bodyA.m_storage->m_shape,
      (hkpConvexShape *)v11->m_bodyB.m_storage->m_shape,
      &transformOut,
      (hkVector4f *)shapeB);
    if ( v233.m_dimA.m_storage == 1 )
    {
      v118 = v233.m_verticesA[0].m_quad;
      v221.m_quad = (__m128)v233.m_verticesA[0];
LABEL_38:
      v119 = *(__m128 *)shapeB;
      goto LABEL_39;
    }
    v119 = *(__m128 *)shapeB;
    if ( v233.m_dimB.m_storage == 1 )
    {
      v118 = _mm_add_ps(
               _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)shapeB, *(__m128 *)shapeB, 255), *(__m128 *)shapeB),
               v233.m_verticesBinA[0].m_quad);
      v221.m_quad = v118;
    }
    else
    {
      v118 = v233.m_closestLineLineResult.m_closestPointA.m_quad;
      v221.m_quad = (__m128)v233.m_closestLineLineResult.m_closestPointA;
    }
LABEL_39:
    v129 = _mm_sub_ps(_mm_shuffle_ps(v119, v119, 255), separatingNormalOut.m_quad);
    if ( COERCE_FLOAT((unsigned int)(2 * COERCE_SIGNED_INT(v129.m128_f32[0] - v102.m128_f32[0])) >> 1) < v101.m128_f32[0] )
      break;
    if ( v111 )
      break;
    if ( v39.m128_f32[0] == v108.m128_f32[0] )
      break;
    v103 = *(__m128 *)shapeA;
    ++v100;
    v130 = _mm_cmpltps(v129, v102);
    v35 = _mm_or_ps(_mm_andnot_ps(v130, v108), _mm_and_ps(v110, v130));
    v39 = _mm_or_ps(_mm_andnot_ps(v130, v110), _mm_and_ps(v39, v130));
    v37 = _mm_or_ps(_mm_andnot_ps(v130, v129), _mm_and_ps(v37, v130));
    v38 = _mm_or_ps(_mm_andnot_ps(v130, v38), _mm_and_ps(v129, v130));
  }
  while ( v100 < 10 );
  v131 = (unsigned int *)v11->m_input.m_storage;
  v132 = separatingNormal;
  v133 = _mm_shuffle_ps((__m128)v218, (__m128)v218, 0);
  LODWORD(v237) = v131[26];
  v134 = _mm_add_ps(
           _mm_max_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)(unsigned int)v237, (__m128)(unsigned int)v237, 0), v110), v133),
           _mm_shuffle_ps((__m128)v131[24], (__m128)v131[24], 0));
  *(float *)&v237 = separatingNormal[771].m_quad.m128_f32[0];
  separatingNormalOut.m_quad = v134;
  if ( v134.m128_f32[0] < COERCE_FLOAT(_mm_shuffle_ps((__m128)(unsigned int)v237, (__m128)(unsigned int)v237, 0)) )
  {
    LODWORD(v237) = v131[25];
    if ( v134.m128_f32[0] < (float)(COERCE_FLOAT(_mm_shuffle_ps((__m128)(unsigned int)v237, (__m128)(unsigned int)v237, 0))
                                  - v133.m128_f32[0]) )
    {
      v135 = (hkpConvexShape **)v11->m_bodyA.m_storage;
      v136 = v11->m_bodyB.m_storage;
      v137 = v11->m_bodyA.m_storage->m_shape;
      v138 = 2;
      v139 = _mm_add_ps(
               _mm_add_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v119, v119, 85), bTa.m_rotation.m_col1.m_quad),
                 _mm_mul_ps(_mm_shuffle_ps(v119, v119, 0), bTa.m_rotation.m_col0.m_quad)),
               _mm_mul_ps(_mm_shuffle_ps(v119, v119, 170), bTa.m_rotation.m_col2.m_quad));
      v140 = _mm_add_ps(
               _mm_add_ps(
                 _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v118, v118, 85), bTa.m_rotation.m_col1.m_quad),
                     _mm_mul_ps(_mm_shuffle_ps(v118, v118, 0), bTa.m_rotation.m_col0.m_quad)),
                   _mm_mul_ps(_mm_shuffle_ps(v118, v118, 170), bTa.m_rotation.m_col2.m_quad)),
                 bTa.m_translation.m_quad),
               _mm_mul_ps(
                 _mm_sub_ps(
                   _mm_sub_ps(
                     (__m128)0i64,
                     _mm_shuffle_ps((__m128)LODWORD(v137[1].vfptr), (__m128)LODWORD(v137[1].vfptr), 0)),
                   v129),
                 v139));
      v141.m_quad = _mm_shuffle_ps(v139, _mm_unpackhi_ps(v139, v129), 196);
      *(__m128 *)&v220.m_Rtoi.m_storage = v140;
      v220.m_collidingPoint = (hkVector4f)v141.m_quad;
      _mm_store_si128((__m128i *)shapeA, (__m128i)v141.m_quad);
      v142 = v136->m_shape;
      if ( v136->m_shape->m_type.m_storage == 2 )
      {
        LOWORD(v236) = v233.m_verticesBinB[0].m_quad.m128_i16[6];
        v143 = -1;
        v144 = -1;
        LOBYTE(v237) = v233.m_dimB.m_storage;
        if ( LOBYTE(v233.m_dimB.m_storage) >= 2u )
          v144 = v233.m_verticesBinB[1].m_quad.m128_i16[6];
        WORD1(v236) = v144;
        if ( LOBYTE(v233.m_dimB.m_storage) >= 3u )
          v143 = v233.m_verticesBinB[2].m_quad.m128_i16[6];
        WORD2(v236) = v143;
        v145 = v142->vfptr;
        t.m_real = v140;
        v146 = ((__int64 (__fastcall *)(hkpShape *, __m128 **, hkSimdFloat32 **, hkSimdFloat32 *, hkTransformf *, hkpShape *, hkTransformf *, hkpConvexShape **))v145[6].__first_virtual_table_function__)(
                 v142,
                 &v236,
                 &v237,
                 &t,
                 &aTb,
                 v137,
                 &bTa,
                 shapeA);
        v140 = t.m_real;
        v141.m_quad = *(__m128 *)shapeA;
        *(hkSimdFloat32 *)&v220.m_Rtoi.m_storage = (hkSimdFloat32)t.m_real;
        goto LABEL_57;
      }
      if ( (*v135)->m_type.m_storage != 2 )
        goto LABEL_92;
      LOWORD(v236) = v233.m_verticesA[0].m_quad.m128_i16[6];
      v147 = -1;
      v148 = -1;
      LOBYTE(v237) = v233.m_dimA.m_storage;
      if ( LOBYTE(v233.m_dimA.m_storage) >= 2u )
        v148 = v233.m_verticesA[1].m_quad.m128_i16[6];
      WORD1(v236) = v148;
      if ( LOBYTE(v233.m_dimA.m_storage) >= 3u )
        v147 = v233.m_verticesA[2].m_quad.m128_i16[6];
      v149 = v137->vfptr;
      WORD2(v236) = v147;
      masterNormal.m_quad = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v141.m_quad, v141.m_quad, 255), v141.m_quad), v140);
      v150 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64);
      *(__m128 *)shapeA = _mm_xor_ps(v141.m_quad, v150);
      v146 = ((__int64 (__fastcall *)(hkpShape *, __m128 **, hkSimdFloat32 **, hkVector4f *, hkTransformf *, hkpShape *, hkTransformf *, hkpConvexShape **))v149[6].__first_virtual_table_function__)(
               v137,
               &v236,
               &v237,
               &masterNormal,
               &bTa,
               v136->m_shape,
               &aTb,
               shapeA);
      v140 = *(__m128 *)&v220.m_Rtoi.m_storage;
      v141.m_quad = _mm_xor_ps(*(__m128 *)shapeA, v150);
      *(hkVector4f *)shapeA = (hkVector4f)v141.m_quad;
LABEL_57:
      v220.m_collidingPoint = (hkVector4f)v141.m_quad;
      v138 = v146;
      if ( v146
        || v11->m_input.m_storage->m_collisionQualityInfo.m_storage->m_enableToiWeldRejection.m_bool == (_BYTE)v146 )
      {
LABEL_92:
        v151 = (hkpConvexShape **)v11->m_bodyA.m_storage;
        v152 = v11->m_bodyB.m_storage;
        v153 = (hkMotionState *)v11->m_bodyA.m_storage->m_motion;
        v154 = (hkMotionState *)v152->m_motion;
        v155.m_quad = (__m128)v11->m_linearTimInfo;
        v156 = v153->m_sweptTransform.m_centerOfMass1.m_quad;
        v157 = _mm_sub_ps(
                 v140,
                 _mm_add_ps(
                   _mm_mul_ps(
                     _mm_mul_ps(
                       _mm_sub_ps(
                         v134,
                         _mm_shuffle_ps(
                           v153->m_sweptTransform.m_centerOfMass0.m_quad,
                           v153->m_sweptTransform.m_centerOfMass0.m_quad,
                           255)),
                       _mm_shuffle_ps(v156, v156, 255)),
                     _mm_sub_ps(v156, v153->m_sweptTransform.m_centerOfMass0.m_quad)),
                   v153->m_sweptTransform.m_centerOfMass0.m_quad));
        v158 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v157, v157, 201), input.m_deltaAngles[0].m_quad),
                 _mm_mul_ps(_mm_shuffle_ps(input.m_deltaAngles[0].m_quad, input.m_deltaAngles[0].m_quad, 201), v157));
        v159 = v154->m_sweptTransform.m_centerOfMass1.m_quad;
        v160 = _mm_sub_ps(
                 v140,
                 _mm_add_ps(
                   _mm_mul_ps(
                     _mm_mul_ps(
                       _mm_sub_ps(
                         v134,
                         _mm_shuffle_ps(
                           v154->m_sweptTransform.m_centerOfMass0.m_quad,
                           v154->m_sweptTransform.m_centerOfMass0.m_quad,
                           255)),
                       _mm_shuffle_ps(v159, v159, 255)),
                     _mm_sub_ps(v159, v154->m_sweptTransform.m_centerOfMass0.m_quad)),
                   v154->m_sweptTransform.m_centerOfMass0.m_quad));
        v161 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v160, v160, 201), input.m_deltaAngles[1].m_quad),
                 _mm_mul_ps(_mm_shuffle_ps(input.m_deltaAngles[1].m_quad, input.m_deltaAngles[1].m_quad, 201), v160));
        v162 = _mm_mul_ps(
                 _mm_sub_ps(
                   _mm_add_ps(
                     _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v155.m_quad),
                     _mm_shuffle_ps(v158, v158, 201)),
                   _mm_shuffle_ps(v161, v161, 201)),
                 v141.m_quad);
        v163 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v162, v162, 85), _mm_shuffle_ps(v162, v162, 0)),
                 _mm_shuffle_ps(v162, v162, 170));
        t.m_real = v163;
        if ( v138 == 1 && v163.m128_f32[0] > (float)(0.0 - 0.00000011920929) )
        {
          v164 = v11->m_input.m_storage;
          LODWORD(v231.m_startRt.m_storage) = v110.m128_i32[0];
          *(float *)&v237 = v164->m_stepInfo.m_deltaTime.m_storage;
          v165 = _mm_shuffle_ps((__m128)(unsigned int)v237, (__m128)(unsigned int)v237, 0);
          v166 = _mm_mul_ps(_mm_mul_ps(_mm_shuffle_ps(v156, v156, 255), v165), v153->m_deltaAngle.m_quad);
          v167 = _mm_mul_ps(_mm_mul_ps(_mm_shuffle_ps(v159, v159, 255), v165), v154->m_deltaAngle.m_quad);
          v168 = _mm_shuffle_ps(v141.m_quad, v141.m_quad, 201);
          v231.m_deltaAngles[0].m_quad = v166;
          v231.m_deltaAngles[1].m_quad = v167;
          v169 = _mm_sub_ps(_mm_mul_ps(v166, v168), _mm_mul_ps(_mm_shuffle_ps(v166, v166, 201), v141.m_quad));
          v170 = _mm_mul_ps(_mm_shuffle_ps(v167, v167, 201), v141.m_quad);
          v171 = _mm_shuffle_ps(v169, v169, 201);
          v172 = _mm_mul_ps(v141.m_quad, v155.m_quad);
          v173 = _mm_sub_ps(_mm_mul_ps(v167, v168), v170);
          v174 = _mm_mul_ps(v171, v171);
          v175 = _mm_shuffle_ps(v173, v173, 201);
          v176 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v174, v174, 85), _mm_shuffle_ps(v174, v174, 0)),
                   _mm_shuffle_ps(v174, v174, 170));
          v177 = _mm_mul_ps(v175, v175);
          v178 = _mm_rsqrt_ps(v176);
          v179 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v177, v177, 85), _mm_shuffle_ps(v177, v177, 0)),
                   _mm_shuffle_ps(v177, v177, 170));
          v180 = _mm_rsqrt_ps(v179);
          v231.m_worstCaseApproachingDelta.m_storage = (float)((float)(COERCE_FLOAT(
                                                                         _mm_andnot_ps(
                                                                           _mm_cmpleps(v176, (__m128)0i64),
                                                                           _mm_mul_ps(
                                                                             _mm_mul_ps(
                                                                               _mm_sub_ps(
                                                                                 (__m128)_xmm,
                                                                                 _mm_mul_ps(
                                                                                   _mm_mul_ps(v178, v176),
                                                                                   v178)),
                                                                               _mm_mul_ps(v178, *(__m128 *)_xmm)),
                                                                             v176)))
                                                                     * COERCE_FLOAT(
                                                                         _mm_shuffle_ps(
                                                                           (__m128)LODWORD(v153->m_objectRadius),
                                                                           (__m128)LODWORD(v153->m_objectRadius),
                                                                           0)))
                                                             + (float)(COERCE_FLOAT(
                                                                         _mm_andnot_ps(
                                                                           _mm_cmpleps(v179, (__m128)0i64),
                                                                           _mm_mul_ps(
                                                                             _mm_mul_ps(
                                                                               _mm_sub_ps(
                                                                                 (__m128)_xmm,
                                                                                 _mm_mul_ps(
                                                                                   _mm_mul_ps(v180, v179),
                                                                                   v180)),
                                                                               _mm_mul_ps(v180, *(__m128 *)_xmm)),
                                                                             v179)))
                                                                     * COERCE_FLOAT(
                                                                         _mm_shuffle_ps(
                                                                           (__m128)LODWORD(v154->m_objectRadius),
                                                                           (__m128)LODWORD(v154->m_objectRadius),
                                                                           0))))
                                                     + (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v172, v172, 85))
                                                                     + COERCE_FLOAT(_mm_shuffle_ps(v172, v172, 0)))
                                                             + COERCE_FLOAT(_mm_shuffle_ps(v172, v172, 170)));
          v181 = v152->m_shape;
          v182 = (float *)*v151;
          v231.m_motionA.m_storage = v153;
          v231.m_motionB.m_storage = v154;
          v170.m128_f32[0] = *(float *)&v181[1].vfptr + v182[8];
          v231.m_stepInfo.m_storage = &v164->m_stepInfo;
          v231.m_linearTimInfo = (hkVector4f)v155.m_quad;
          LODWORD(v231.m_radiusSum.m_storage) = v170.m128_i32[0];
          v183 = (*(__int64 (__fastcall **)(float *))(*(_QWORD *)v182 + 88i64))(v182);
          LODWORD(v237) = v183;
          v231.m_allocatedNumVertices.m_storage = v183;
          v231.m_numVertices.m_storage = v183;
          v184 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v185 = (hkVector4f *)v184->m_cur;
          v186 = (16 * (_DWORD)v237 + 127) & 0xFFFFFF80;
          v187 = (char *)v185 + v186;
          if ( v186 > v184->m_slabSize || v187 > v184->m_end )
            v185 = (hkVector4f *)hkLifoAllocator::allocateFromNewSlab(v184, v186);
          else
            v184->m_cur = v187;
          v231.m_verticesA.m_storage = v185;
          (*(void (__fastcall **)(float *))(*(_QWORD *)v182 + 96i64))(v182);
          LODWORD(v188) = (unsigned __int128)_mm_shuffle_ps(
                                               v231.m_deltaAngles[1].m_quad,
                                               v231.m_deltaAngles[1].m_quad,
                                               255);
          LODWORD(v189) = (unsigned __int128)_mm_shuffle_ps(
                                               v231.m_deltaAngles[0].m_quad,
                                               v231.m_deltaAngles[0].m_quad,
                                               255);
          v190 = (float)((float)(v188 * v188)
                       * COERCE_FLOAT(
                           _mm_shuffle_ps(
                             (__m128)LODWORD(v154->m_objectRadius),
                             (__m128)LODWORD(v154->m_objectRadius),
                             0)))
               + (float)((float)(v189 * v189)
                       * COERCE_FLOAT(
                           _mm_shuffle_ps(
                             (__m128)LODWORD(v153->m_objectRadius),
                             (__m128)LODWORD(v153->m_objectRadius),
                             0)));
          v191 = _mm_unpacklo_ps(aTb.m_rotation.m_col0.m_quad, aTb.m_rotation.m_col1.m_quad);
          v231.m_maxAccel.m_storage = v190;
          v192 = 1.0 / (float)(v190 + 1.4210855e-14);
          v193 = _mm_movelh_ps(v191, aTb.m_rotation.m_col2.m_quad);
          v231.m_invMaxAccel.m_storage = v192;
          v231.m_pointOnPlaneB = (hkVector4f)v233.m_verticesBinB[0];
          v231.m_planeB.m_quad = _mm_add_ps(
                                   _mm_add_ps(
                                     _mm_mul_ps(
                                       _mm_shuffle_ps(_mm_movehl_ps(v193, v191), aTb.m_rotation.m_col2.m_quad, 212),
                                       _mm_shuffle_ps(v220.m_collidingPoint.m_quad, v220.m_collidingPoint.m_quad, 85)),
                                     _mm_mul_ps(
                                       _mm_shuffle_ps(v220.m_collidingPoint.m_quad, v220.m_collidingPoint.m_quad, 0),
                                       v193)),
                                   _mm_mul_ps(
                                     _mm_shuffle_ps(v220.m_collidingPoint.m_quad, v220.m_collidingPoint.m_quad, 170),
                                     _mm_shuffle_ps(
                                       _mm_unpackhi_ps(aTb.m_rotation.m_col0.m_quad, aTb.m_rotation.m_col1.m_quad),
                                       aTb.m_rotation.m_col2.m_quad,
                                       228)));
          if ( v231.m_verticesA.m_storage )
          {
            masterNormal.m_quad.m128_i32[0] = 1065353216;
            hk4dGskCollidePointsWithPlane(
              &v231,
              (hkp4dGskTolerances *)((char *)&tol + 8),
              (hkp4dGskVertexCollidePointsOutput *)&masterNormal);
            v194 = v231.m_verticesA.m_storage;
            v195 = (16 * v231.m_allocatedNumVertices.m_storage + 127) & 0xFFFFFF80;
            v196 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
            v197 = (v195 + 15) & 0xFFFFFFF0;
            if ( v195 > v196->m_slabSize || (char *)v194 + v197 != v196->m_cur || v196->m_firstNonLifoEnd == v194 )
              hkLifoAllocator::slowBlockFree(v196, v194, v197);
            else
              v196->m_cur = v194;
            if ( masterNormal.m_quad.m128_f32[0] < 1.0 )
              *(__m128 *)&v220.m_Rtoi.m_storage = _mm_add_ps(
                                                    _mm_add_ps(
                                                      _mm_add_ps(
                                                        _mm_mul_ps(
                                                          _mm_shuffle_ps(v225, v225, 85),
                                                          bTa.m_rotation.m_col1.m_quad),
                                                        _mm_mul_ps(
                                                          _mm_shuffle_ps(v225, v225, 0),
                                                          bTa.m_rotation.m_col0.m_quad)),
                                                      _mm_mul_ps(
                                                        _mm_shuffle_ps(v225, v225, 170),
                                                        bTa.m_rotation.m_col2.m_quad)),
                                                    bTa.m_translation.m_quad);
          }
        }
        if ( v232.m128_f32[0] < v163.m128_f32[0] )
        {
          *(float *)&v237 = FLOAT_1_2;
          if ( v232.m128_f32[0] <= (float)(COERCE_FLOAT(_mm_shuffle_ps((__m128)LODWORD(FLOAT_1_2), (__m128)LODWORD(FLOAT_1_2), 0))
                                         * v163.m128_f32[0]) )
          {
            hk4dGskCalcPointVelocityAssumingAngularVelError(
              (hkMotionState *)v11->m_bodyA.m_storage->m_motion,
              (hkMotionState *)v11->m_bodyB.m_storage->m_motion,
              (hkVector4f *)&v220,
              &v220.m_collidingPoint,
              &v11->m_linearTimInfo,
              input.m_deltaAngles,
              (hkSimdFloat32 *)&separatingNormalOut,
              &t);
            v163.m128_f32[0] = fmin(0.0, t.m_real.m128_f32[0]);
          }
          else
          {
            v163.m128_i32[0] = v232.m128_i32[0];
          }
        }
        v198 = v131[27];
        bTc.m_rotation.m_col1 = 0i64;
        LODWORD(v237) = v198;
        bTc.m_rotation.m_col0 = 0i64;
        bTc.m_rotation.m_col2 = 0i64;
        bTc.m_translation = 0i64;
        bTc.m_rotation.m_col1.m_quad.m128_f32[2] = FLOAT_321_0;
        hkpGsk::exitAndExportCacheImpl(&v233, (hkpGskCache *)&tol);
        v199 = v11->m_contactMgr.m_storage;
        v200 = v11->m_input.m_storage;
        *(float *)&v237 = v163.m128_f32[0] * COERCE_FLOAT(_mm_shuffle_ps((__m128)v198, (__m128)v198, 0));
        LODWORD(pointA) = v134.m128_i32[0];
        v201 = ((__int64 (__fastcall *)(hkpContactMgr *, hkpCdBody *, hkpCdBody *, hkpProcessCollisionInput *, hkVector4f *, hkVector4f *, hkp4dGskVertexCollidePointsOutput *, hkp4dGskTolerances *, hkSimdFloat32 **, hkTransformf *, unsigned __int64, unsigned __int64))v199->vfptr[3].__first_virtual_table_function__)(
                 v199,
                 v11->m_bodyA.m_storage,
                 v11->m_bodyB.m_storage,
                 v200,
                 v132,
                 pointA,
                 &v220,
                 &tol,
                 &v237,
                 &bTc,
                 t.m_real.m128_u64[0],
                 t.m_real.m128_u64[1]);
        v202 = (signed int)v237;
        if ( !v201 )
        {
          if ( 3.40282e38 != v132[771].m_quad.m128_f32[0] )
            ((void (__fastcall *)(hkpContactMgr *, unsigned __int64, hkVector4f *))v11->m_contactMgr.m_storage->vfptr[4].__vecDelDtor)(
              v11->m_contactMgr.m_storage,
              v132->m_quad.m128_u64[1],
              &v132[773]);
          v203.m_quad = *(__m128 *)&v220.m_Rtoi.m_storage;
          v204.m_quad = (__m128)v220.m_collidingPoint;
          v132[771].m_quad.m128_i32[1] = v202;
          v132[769] = (hkVector4f)v203.m_quad;
          v205.m_quad = (__m128)bTc.m_rotation.m_col0;
          v132[770] = (hkVector4f)v204.m_quad;
          v132[771].m_quad.m128_i32[0] = v134.m128_i32[0];
          v206.m_quad = (__m128)bTc.m_rotation.m_col1;
          v132[773] = (hkVector4f)v205.m_quad;
          v207.m_quad = (__m128)bTc.m_rotation.m_col2;
          v132[774] = (hkVector4f)v206.m_quad;
          v208.m_quad = (__m128)bTc.m_translation;
          v132[775] = (hkVector4f)v207.m_quad;
          v209 = *(__m128i *)&tol.m_toiSeparation.m_storage;
          v132[776] = (hkVector4f)v208.m_quad;
          _mm_store_si128((__m128i *)&v132[772], v209);
        }
      }
    }
  }
LABEL_81:
  v210 = input.m_verticesA.m_storage;
  if ( input.m_verticesA.m_storage )
  {
    v211 = (16 * input.m_allocatedNumVertices.m_storage + 127) & 0xFFFFFF80;
    v212 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v213 = (v211 + 15) & 0xFFFFFFF0;
    if ( v211 > v212->m_slabSize || (char *)v210 + v213 != v212->m_cur || v212->m_firstNonLifoEnd == v210 )
      hkLifoAllocator::slowBlockFree(v212, v210, v213);
    else
      v212->m_cur = v210;
  }
  if ( v233.m_featureChange.m_storage )
    hkpGsk::exitAndExportCacheImpl(&v233, cache);
}d = (__m128)bTc.m_rotation.m_col1;
          v132[773] = (hkVector4f)v205.m_quad;
          v207.m_quad = (__m128)bTc.m_rotation.m_col2;
          v132[774] = (hkVector4f)v206.m_quad;
          v208.m_quad = (__m128)bTc.m_translation;
          v132[775] = (hkVector4f)v207.m_quad;
          v209 = *(__m128i *)&tol.m_toiSeparation.m_storage;
          v132[776] = (hkVector4f)v208.m_quad;
          _mm_store_si128((__m128i *)&v132[772], v209);
        }
      }
    }
  }
LABEL_81:
  v210 = input.m_verticesA.m_storage;
  if ( input.m_verticesA.m_

