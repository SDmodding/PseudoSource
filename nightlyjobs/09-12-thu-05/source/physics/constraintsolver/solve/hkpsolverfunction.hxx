// File Line: 85
// RVA: 0xDE2350
void __fastcall hkpAtomSolverFunctions::solve1dLinLimits<hkpVelocityAccumulator,hkpSolverInfo,hkSolverStepTemp>(
        hkpSolverInfo *info,
        hkSolverStepTemp *temp,
        hkpJacobian1dLinearLimitsSchema *schema,
        hkpVelocityAccumulator *mA,
        hkpVelocityAccumulator *mB,
        hkpSolverElemTemp *temps)
{
  __m128 m_quad; // xmm5
  hkVector4f v7; // xmm6
  float v8; // xmm8_4
  hkVector4f v9; // xmm10
  __m128 v10; // xmm0
  __m128 v11; // xmm7
  hkVector4f v12; // xmm11
  __m128 v13; // xmm2
  __m128 v14; // xmm4
  __m128 v15; // xmm3
  hkVector4f v16; // xmm1
  hkVector4f v17; // xmm2
  __m128 v18; // xmm1
  __m128 v19; // xmm2
  __m128 v20; // xmm0
  __m128 v21; // xmm4
  __m128 v22; // xmm2
  __m128 v23; // xmm3
  __m128 v24; // xmm0

  m_quad = schema->m_jac.m_angular[1].m_quad;
  v7.m_quad = (__m128)schema->m_jac.m_linear0;
  v8 = _mm_shuffle_ps((__m128)LODWORD(temps->m_impulseApplied), (__m128)LODWORD(temps->m_impulseApplied), 0).m128_f32[0];
  v9.m_quad = (__m128)mB->m_linearVel;
  v10 = schema->m_jac.m_angular[0].m_quad;
  v11 = _mm_shuffle_ps(v10, v10, 255);
  v12.m_quad = (__m128)mA->m_linearVel;
  v13 = _mm_add_ps(
          _mm_add_ps(_mm_mul_ps(m_quad, mB->m_angularVel.m_quad), _mm_mul_ps(v10, mA->m_angularVel.m_quad)),
          _mm_mul_ps(_mm_sub_ps(v12.m_quad, v9.m_quad), schema->m_jac.m_linear0.m_quad));
  v14 = _mm_sub_ps(
          _mm_shuffle_ps(v7.m_quad, v7.m_quad, 255),
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)),
            _mm_shuffle_ps(v13, v13, 170)));
  v15 = _mm_mul_ps(
          _mm_sub_ps(v14, _mm_shuffle_ps((__m128)LODWORD(schema->m_minRhs), (__m128)LODWORD(schema->m_minRhs), 0)),
          v11);
  if ( v15.m128_f32[0] > (float)(0.0 - v8) )
  {
    v16.m_quad = (__m128)mA->m_invMasses;
    v17.m_quad = (__m128)mB->m_invMasses;
    temps->m_impulseApplied = v8 + v15.m128_f32[0];
    v18 = _mm_mul_ps(v16.m_quad, v15);
    v19 = _mm_mul_ps(v17.m_quad, v15);
    mA->m_linearVel.m_quad = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v18, v18, 255), v7.m_quad), v12.m_quad);
    v20 = _mm_mul_ps(schema->m_jac.m_angular[0].m_quad, v18);
    mB->m_linearVel.m_quad = _mm_sub_ps(v9.m_quad, _mm_mul_ps(_mm_shuffle_ps(v19, v19, 255), v7.m_quad));
    mA->m_angularVel.m_quad = _mm_add_ps(v20, mA->m_angularVel.m_quad);
    mB->m_angularVel.m_quad = _mm_add_ps(_mm_mul_ps(m_quad, v19), mB->m_angularVel.m_quad);
  }
  v21 = _mm_mul_ps(
          _mm_sub_ps(v14, _mm_shuffle_ps((__m128)LODWORD(schema->m_maxRhs), (__m128)LODWORD(schema->m_maxRhs), 0)),
          v11);
  if ( v21.m128_f32[0] < (float)(0.0 - v8) )
  {
    v22 = _mm_mul_ps(mA->m_invMasses.m_quad, v21);
    v23 = _mm_mul_ps(mB->m_invMasses.m_quad, v21);
    mA->m_linearVel.m_quad = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v22, v22, 255), v7.m_quad), mA->m_linearVel.m_quad);
    mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, _mm_mul_ps(_mm_shuffle_ps(v23, v23, 255), v7.m_quad));
    v24 = _mm_mul_ps(schema->m_jac.m_angular[0].m_quad, v22);
    mB->m_angularVel.m_quad = _mm_add_ps(_mm_mul_ps(m_quad, v23), mB->m_angularVel.m_quad);
    mA->m_angularVel.m_quad = _mm_add_ps(v24, mA->m_angularVel.m_quad);
    temps->m_impulseApplied = _mm_shuffle_ps(
                                (__m128)LODWORD(temps->m_impulseApplied),
                                (__m128)LODWORD(temps->m_impulseApplied),
                                0).m128_f32[0]
                            + v21.m128_f32[0];
  }
}

// File Line: 154
// RVA: 0xDDEF00
void __fastcall hkpAtomSolverFunctions::computeAngularInverseMass(
        hkVector4f *invIA,
        hkVector4f *invIB,
        hkMatrix3f *UA,
        hkMatrix3f *UB,
        hkMatrix3f *K)
{
  hkVector4f v5; // xmm3
  hkVector4f v6; // xmm1
  hkVector4f v7; // xmm4
  hkVector4f v8; // xmm8
  __m128 v9; // xmm11
  __m128 v10; // xmm5
  __m128 v11; // xmm10
  __m128 v12; // xmm9
  __m128 v13; // xmm2
  __m128 v14; // xmm8
  __m128 v15; // xmm0
  __m128 v16; // xmm4
  __m128 v17; // xmm3
  __m128 v18; // xmm0
  __m128 v19; // xmm9
  __m128 v20; // xmm2
  hkVector4f v21; // xmm11
  hkVector4f v22; // xmm9
  hkVector4f v23; // xmm1

  v5.m_quad = (__m128)UB->m_col1;
  v6.m_quad = (__m128)UA->m_col1;
  v7.m_quad = (__m128)UB->m_col2;
  v8.m_quad = (__m128)UA->m_col2;
  v9 = _mm_add_ps(
         _mm_mul_ps(_mm_mul_ps(UA->m_col0.m_quad, UA->m_col0.m_quad), invIA->m_quad),
         _mm_mul_ps(_mm_mul_ps(UB->m_col0.m_quad, UB->m_col0.m_quad), invIB->m_quad));
  v10 = _mm_add_ps(
          _mm_mul_ps(_mm_mul_ps(UA->m_col0.m_quad, v6.m_quad), invIA->m_quad),
          _mm_mul_ps(_mm_mul_ps(UB->m_col0.m_quad, v5.m_quad), invIB->m_quad));
  v11 = _mm_add_ps(
          _mm_mul_ps(_mm_mul_ps(UA->m_col0.m_quad, v8.m_quad), invIA->m_quad),
          _mm_mul_ps(_mm_mul_ps(UB->m_col0.m_quad, v7.m_quad), invIB->m_quad));
  v12 = _mm_add_ps(
          _mm_mul_ps(_mm_mul_ps(v6.m_quad, v6.m_quad), invIA->m_quad),
          _mm_mul_ps(_mm_mul_ps(v5.m_quad, v5.m_quad), invIB->m_quad));
  v13 = _mm_add_ps(
          _mm_mul_ps(_mm_mul_ps(v8.m_quad, v6.m_quad), invIA->m_quad),
          _mm_mul_ps(_mm_mul_ps(v7.m_quad, v5.m_quad), invIB->m_quad));
  v14 = _mm_add_ps(
          _mm_mul_ps(_mm_mul_ps(v8.m_quad, v8.m_quad), invIA->m_quad),
          _mm_mul_ps(_mm_mul_ps(v7.m_quad, v7.m_quad), invIB->m_quad));
  v15 = _mm_unpacklo_ps(v9, v10);
  v16 = _mm_movelh_ps(v15, v11);
  v17 = _mm_movehl_ps(v16, v15);
  v18 = _mm_unpacklo_ps(v12, v13);
  v19 = _mm_unpackhi_ps(v12, v13);
  v20 = _mm_movelh_ps(v18, v14);
  v21.m_quad = _mm_add_ps(
                 _mm_shuffle_ps(_mm_unpackhi_ps(v9, v10), v11, 228),
                 _mm_add_ps(v16, _mm_shuffle_ps(v17, v11, 212)));
  K->m_col0 = (hkVector4f)v21.m_quad;
  v22.m_quad = _mm_add_ps(
                 _mm_shuffle_ps(v19, v14, 228),
                 _mm_add_ps(v20, _mm_shuffle_ps(_mm_movehl_ps(v20, v18), v14, 212)));
  v23.m_quad = _mm_unpacklo_ps(v22.m_quad, v22.m_quad);
  v23.m_quad.m128_f32[0] = _mm_shuffle_ps(v21.m_quad, v21.m_quad, 85).m128_f32[0];
  v22.m_quad.m128_f32[0] = _mm_shuffle_ps(v21.m_quad, v21.m_quad, 170).m128_f32[0];
  K->m_col2 = (hkVector4f)v22.m_quad;
  K->m_col1 = (hkVector4f)v23.m_quad;
}

// File Line: 231
// RVA: 0xDE1360
void __fastcall hkpAtomSolverFunctions::computeInverseVirtualMass3D<hkpVelocityAccumulator>(
        hkMatrix3f *axes,
        hkSimdFloat32 *fA,
        hkSimdFloat32 *fB,
        hkQuaternionf *rotA,
        hkQuaternionf *rotB,
        hkVector4f *localArmDirA,
        hkVector4f *localArmDirB,
        hkpVelocityAccumulator *mA,
        hkpVelocityAccumulator *mB,
        hkMatrix3f *outK,
        hkMatrix3f *UA,
        hkMatrix3f *UB)
{
  __m128 m_quad; // xmm3
  __m128 v13; // xmm4
  hkVector4f v14; // xmm14
  hkVector4f v15; // xmm15
  __m128 v16; // xmm14
  __m128 v17; // xmm1
  __m128 v18; // xmm3
  __m128 v19; // xmm9
  __m128 v20; // xmm15
  __m128 v21; // xmm7
  __m128 v22; // xmm8
  __m128 v23; // xmm1
  __m128 v24; // xmm4
  __m128 v25; // xmm10
  __m128 v26; // xmm12
  __m128 v27; // xmm13
  __m128 v28; // xmm5
  __m128 v29; // xmm11
  __m128 v30; // xmm5
  __m128 v31; // xmm1
  __m128 v32; // xmm6
  __m128 v33; // xmm4
  __m128 v34; // xmm3
  __m128 v35; // xmm2
  __m128 v36; // xmm1
  __m128 v37; // xmm2
  __m128 v38; // xmm3
  __m128 v39; // xmm2
  __m128 v40; // xmm1
  __m128 v41; // xmm2
  __m128 v42; // xmm3
  __m128 v43; // xmm2
  __m128 v44; // xmm4
  __m128 v45; // xmm1
  __m128 v46; // xmm5
  __m128 v47; // xmm2
  __m128 v48; // xmm2
  __m128 v49; // xmm8
  __m128 v50; // xmm1
  __m128 v51; // xmm8
  __m128 v52; // xmm3
  hkVector4f v53; // xmm8
  __m128 v54; // xmm2
  __m128 v55; // xmm1
  __m128 v56; // xmm2
  __m128 v57; // xmm3
  __m128 v58; // xmm2
  hkVector4f v59; // xmm3
  hkVector4f v60; // xmm2
  hkVector4f v61; // xmm7
  __m128 v62; // xmm9
  __m128 v63; // xmm5
  __m128 v64; // xmm6
  __m128 v65; // xmm8
  __m128 v66; // xmm1
  __m128 v67; // xmm7
  __m128 v68; // xmm0
  __m128 v69; // xmm4
  __m128 v70; // xmm3
  __m128 v71; // xmm0
  __m128 v72; // xmm2
  __m128 v73; // xmm9
  __m128 v74; // xmm8
  __m128 v75; // xmm3
  __m128 v76; // [rsp+0h] [rbp-B8h]

  m_quad = localArmDirA->m_quad;
  v13 = localArmDirB->m_quad;
  v14.m_quad = (__m128)mA->m_invMasses;
  v15.m_quad = (__m128)mB->m_invMasses;
  v76 = _mm_add_ps(_mm_shuffle_ps(v15.m_quad, v15.m_quad, 255), _mm_shuffle_ps(v14.m_quad, v14.m_quad, 255));
  v16 = _mm_mul_ps(v14.m_quad, _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 255), fA->m_real));
  v17 = _mm_shuffle_ps(m_quad, m_quad, 201);
  v18 = _mm_shuffle_ps(m_quad, m_quad, 210);
  v19 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(axes->m_col2.m_quad, axes->m_col2.m_quad, 210), v17),
          _mm_mul_ps(_mm_shuffle_ps(axes->m_col2.m_quad, axes->m_col2.m_quad, 201), v18));
  v20 = _mm_mul_ps(v15.m_quad, _mm_mul_ps(_mm_shuffle_ps(v13, v13, 255), fB->m_real));
  v21 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(axes->m_col0.m_quad, axes->m_col0.m_quad, 210), v17),
          _mm_mul_ps(_mm_shuffle_ps(axes->m_col0.m_quad, axes->m_col0.m_quad, 201), v18));
  v22 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(axes->m_col1.m_quad, axes->m_col1.m_quad, 210), v17),
          _mm_mul_ps(_mm_shuffle_ps(axes->m_col1.m_quad, axes->m_col1.m_quad, 201), v18));
  v23 = _mm_shuffle_ps(v13, v13, 201);
  v24 = _mm_shuffle_ps(v13, v13, 210);
  v25 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(axes->m_col0.m_quad, axes->m_col0.m_quad, 210), v23),
          _mm_mul_ps(_mm_shuffle_ps(axes->m_col0.m_quad, axes->m_col0.m_quad, 201), v24));
  v26 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(axes->m_col1.m_quad, axes->m_col1.m_quad, 210), v23),
          _mm_mul_ps(_mm_shuffle_ps(axes->m_col1.m_quad, axes->m_col1.m_quad, 201), v24));
  v27 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(axes->m_col2.m_quad, axes->m_col2.m_quad, 210), v23),
          _mm_mul_ps(_mm_shuffle_ps(axes->m_col2.m_quad, axes->m_col2.m_quad, 201), v24));
  v28 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64);
  v29 = _mm_xor_ps(v28, rotB->m_vec.m_quad);
  v30 = _mm_xor_ps(v28, rotA->m_vec.m_quad);
  v31 = _mm_mul_ps(v30, v21);
  v32 = _mm_shuffle_ps(v30, v30, 255);
  v33 = _mm_shuffle_ps(v30, v30, 201);
  v34 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v21, v21, 201), v30), _mm_mul_ps(v33, v21));
  v35 = _mm_mul_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v31, v31, 85), _mm_shuffle_ps(v31, v31, 0)),
            _mm_shuffle_ps(v31, v31, 170)),
          v30);
  v36 = _mm_mul_ps(v30, v22);
  v37 = _mm_add_ps(
          _mm_add_ps(v35, _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v32, v32), (__m128)xmmword_141A711B0), v21)),
          _mm_mul_ps(_mm_shuffle_ps(v34, v34, 201), v32));
  UA->m_col0.m_quad = _mm_add_ps(v37, v37);
  v38 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v22, v22, 201), v30), _mm_mul_ps(v33, v22));
  v39 = _mm_mul_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v36, v36, 85), _mm_shuffle_ps(v36, v36, 0)),
            _mm_shuffle_ps(v36, v36, 170)),
          v30);
  v40 = _mm_mul_ps(v30, v19);
  v41 = _mm_add_ps(
          _mm_add_ps(v39, _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v32, v32), (__m128)xmmword_141A711B0), v22)),
          _mm_mul_ps(_mm_shuffle_ps(v38, v38, 201), v32));
  UA->m_col1.m_quad = _mm_add_ps(v41, v41);
  v42 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v19, v19, 201), v30), _mm_mul_ps(v33, v19));
  v43 = _mm_mul_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v40, v40, 85), _mm_shuffle_ps(v40, v40, 0)),
            _mm_shuffle_ps(v40, v40, 170)),
          v30);
  v44 = _mm_shuffle_ps(v29, v29, 201);
  v45 = _mm_mul_ps(v29, v25);
  v46 = _mm_shuffle_ps(v29, v29, 255);
  v47 = _mm_add_ps(
          _mm_add_ps(v43, _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v32, v32), (__m128)xmmword_141A711B0), v19)),
          _mm_mul_ps(_mm_shuffle_ps(v42, v42, 201), v32));
  UA->m_col2.m_quad = _mm_add_ps(v47, v47);
  v48 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v25, v25, 201), v29), _mm_mul_ps(v44, v25));
  v49 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v45, v45, 85), _mm_shuffle_ps(v45, v45, 0)), _mm_shuffle_ps(v45, v45, 170));
  v50 = _mm_mul_ps(v29, v26);
  v51 = _mm_add_ps(
          _mm_add_ps(_mm_mul_ps(v49, v29), _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v46, v46), (__m128)xmmword_141A711B0), v25)),
          _mm_mul_ps(_mm_shuffle_ps(v48, v48, 201), v46));
  v52 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v26, v26, 201), v29), _mm_mul_ps(v44, v26));
  v53.m_quad = _mm_add_ps(v51, v51);
  UB->m_col0 = (hkVector4f)v53.m_quad;
  v54 = _mm_mul_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v50, v50, 85), _mm_shuffle_ps(v50, v50, 0)),
            _mm_shuffle_ps(v50, v50, 170)),
          v29);
  v55 = _mm_mul_ps(v29, v27);
  v56 = _mm_add_ps(
          _mm_add_ps(v54, _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v46, v46), (__m128)xmmword_141A711B0), v26)),
          _mm_mul_ps(_mm_shuffle_ps(v52, v52, 201), v46));
  UB->m_col1.m_quad = _mm_add_ps(v56, v56);
  v57 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v27, v27, 201), v29), _mm_mul_ps(v44, v27));
  v58 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v55, v55, 85), _mm_shuffle_ps(v55, v55, 0)),
                _mm_shuffle_ps(v55, v55, 170)),
              v29),
            _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v46, v46), (__m128)xmmword_141A711B0), v27)),
          _mm_mul_ps(_mm_shuffle_ps(v57, v57, 201), v46));
  UB->m_col2.m_quad = _mm_add_ps(v58, v58);
  v59.m_quad = (__m128)UB->m_col1;
  v60.m_quad = (__m128)UA->m_col1;
  v61.m_quad = (__m128)UA->m_col2;
  v62 = _mm_add_ps(
          _mm_mul_ps(_mm_mul_ps(v53.m_quad, v53.m_quad), v20),
          _mm_mul_ps(_mm_mul_ps(UA->m_col0.m_quad, UA->m_col0.m_quad), v16));
  v63 = _mm_add_ps(
          _mm_mul_ps(_mm_mul_ps(v59.m_quad, v53.m_quad), v20),
          _mm_mul_ps(_mm_mul_ps(UA->m_col0.m_quad, v60.m_quad), v16));
  v64 = _mm_add_ps(
          _mm_mul_ps(_mm_mul_ps(UB->m_col2.m_quad, v53.m_quad), v20),
          _mm_mul_ps(_mm_mul_ps(UA->m_col0.m_quad, v61.m_quad), v16));
  v65 = _mm_add_ps(
          _mm_mul_ps(_mm_mul_ps(v60.m_quad, v60.m_quad), v16),
          _mm_mul_ps(_mm_mul_ps(v59.m_quad, v59.m_quad), v20));
  v66 = _mm_add_ps(
          _mm_mul_ps(_mm_mul_ps(v61.m_quad, v60.m_quad), v16),
          _mm_mul_ps(_mm_mul_ps(UB->m_col2.m_quad, v59.m_quad), v20));
  v67 = _mm_add_ps(
          _mm_mul_ps(_mm_mul_ps(v61.m_quad, v61.m_quad), v16),
          _mm_mul_ps(_mm_mul_ps(UB->m_col2.m_quad, UB->m_col2.m_quad), v20));
  v68 = _mm_unpacklo_ps(v62, v63);
  v69 = _mm_movelh_ps(v68, v64);
  v70 = _mm_movehl_ps(v69, v68);
  v71 = _mm_unpacklo_ps(v65, v66);
  v72 = _mm_movelh_ps(v71, v67);
  v73 = _mm_add_ps(_mm_shuffle_ps(_mm_unpackhi_ps(v62, v63), v64, 228), _mm_add_ps(v69, _mm_shuffle_ps(v70, v64, 212)));
  v74 = _mm_add_ps(
          _mm_shuffle_ps(_mm_unpackhi_ps(v65, v66), v67, 228),
          _mm_add_ps(v72, _mm_shuffle_ps(_mm_movehl_ps(v72, v71), v67, 212)));
  v75 = _mm_unpacklo_ps(v74, v74);
  v75.m128_f32[0] = _mm_shuffle_ps(v73, v73, 85).m128_f32[0];
  v74.m128_f32[0] = _mm_shuffle_ps(v73, v73, 170).m128_f32[0];
  outK->m_col2.m_quad = _mm_add_ps(v74, _mm_mul_ps(v76, stru_141A71280.m_quad));
  outK->m_col0.m_quad = _mm_add_ps(_mm_mul_ps(v76, transform.m_quad), v73);
  outK->m_col1.m_quad = _mm_add_ps(v75, _mm_mul_ps(v76, direction.m_quad));
}

// File Line: 295
// RVA: 0xDDF080
void __fastcall hkpAtomSolverFunctions::computeInverseVirtualMass3D(
        hkQuaternionf *rotA,
        hkQuaternionf *rotB,
        hkVector4f *vWorldArmA,
        hkVector4f *vWorldArmB,
        hkVector4f *invInertiaA,
        hkVector4f *invInertiaB,
        hkSymmetricMatrix3Impl<float> *outK,
        hkMatrix3f *UA,
        hkMatrix3f *UB)
{
  __m128 v9; // xmm10
  __m128 m_quad; // xmm2
  __m128 v11; // xmm11
  __m128 v12; // xmm10
  __m128 v13; // xmm1
  __m128 v14; // xmm3
  float v15; // xmm0_4
  __m128 v16; // xmm10
  __m128 v17; // xmm3
  __m128 v18; // xmm1
  __m128 v19; // xmm10
  __m128 v20; // xmm9
  __m128 v21; // xmm10
  __m128 v22; // xmm3
  __m128 v23; // xmm10
  float v24; // xmm0_4
  __m128 v25; // xmm7
  __m128 v26; // xmm2
  __m128 v27; // xmm3
  __m128 v28; // xmm11
  __m128 v29; // xmm8
  __m128 v30; // xmm11
  __m128 v31; // xmm11
  __m128 v32; // xmm5
  __m128 v33; // xmm2
  __m128 v34; // xmm4
  __m128 v35; // xmm3
  __m128 v36; // xmm2
  __m128 v37; // xmm2
  __m128 v38; // xmm3
  __m128 v39; // xmm4
  __m128 v40; // xmm2
  hkVector4f v41; // xmm9
  hkVector4f v42; // xmm7
  hkVector4f v43; // xmm10
  __m128 v44; // xmm5
  __m128 v45; // xmm4
  __m128 v46; // xmm8
  __m128 v47; // xmm0
  __m128 v48; // xmm2
  __m128 v49; // xmm3
  __m128 v50; // xmm1
  __m128 v51; // xmm9
  __m128 v52; // xmm13
  __m128 v53; // xmm8
  __m128 v54; // xmm7
  __m128 v55; // xmm13
  __m128 v56; // xmm1
  __m128 v57; // xmm9
  hkVector4f v58; // xmm7
  __m128 v59; // xmm12
  __m128 v60; // xmm13
  __m128 v61; // xmm12
  __m128 v62; // xmm4
  __m128 v63; // xmm8
  __m128 v64; // xmm5
  __m128 v65; // xmm0
  __m128 v66; // xmm2
  __m128 v67; // xmm8
  __m128 v68; // xmm3
  __m128 v69; // xmm7
  __m128 v70; // xmm1
  __m128 v71; // xmm3
  __m128 v72; // xmm9
  __m128 v73; // xmm0
  __m128 v74; // xmm1
  __m128 v75; // xmm10
  __m128 v76; // xmm1
  __m128 v77; // xmm9
  __m128 v78; // xmm2

  v9 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64);
  m_quad = transform.m_quad;
  v11 = _mm_xor_ps(v9, rotB->m_vec.m_quad);
  v12 = _mm_xor_ps(v9, rotA->m_vec.m_quad);
  v13 = _mm_add_ps(v12, v12);
  v14 = _mm_mul_ps(_mm_shuffle_ps(v12, v12, 65), _mm_shuffle_ps(v13, v13, 165));
  v15 = v12.m128_f32[0] * v13.m128_f32[0];
  m_quad.m128_f32[0] = (float)(1.0 - (float)(v12.m128_f32[0] * v13.m128_f32[0])) - v14.m128_f32[0];
  v16 = _mm_mul_ps(_mm_shuffle_ps(v12, v12, 254), _mm_shuffle_ps(v13, v13, 26));
  v17 = _mm_xor_ps(v14, (__m128)`hkVector4UtilImpl<float>::convertQuaternionToRotation::`2::negateMask0);
  v18 = _mm_add_ps(v11, v11);
  v19 = _mm_xor_ps(v16, (__m128)`hkVector4UtilImpl<float>::convertQuaternionToRotation::`2::negateMask1);
  v19.m128_f32[0] = v19.m128_f32[0] + 1.0;
  v20 = _mm_sub_ps(v19, v17);
  v17.m128_f32[0] = v15;
  v21 = _mm_sub_ps(
          _mm_xor_ps(v19, (__m128)`hkVector4UtilImpl<float>::convertQuaternionToRotation::`2::negateMask0),
          v17);
  v22 = _mm_mul_ps(_mm_shuffle_ps(v11, v11, 65), _mm_shuffle_ps(v18, v18, 165));
  v23 = _mm_shuffle_ps(v21, v21, 177);
  v24 = v11.m128_f32[0] * v18.m128_f32[0];
  v25 = _mm_shuffle_ps(_mm_movehl_ps(v20, v23), m_quad, 141);
  v26 = transform.m_quad;
  v26.m128_f32[0] = (float)(1.0 - (float)(v11.m128_f32[0] * v18.m128_f32[0])) - v22.m128_f32[0];
  v27 = _mm_xor_ps(v22, (__m128)`hkVector4UtilImpl<float>::convertQuaternionToRotation::`2::negateMask0);
  v28 = _mm_xor_ps(
          _mm_mul_ps(_mm_shuffle_ps(v11, v11, 254), _mm_shuffle_ps(v18, v18, 26)),
          (__m128)`hkVector4UtilImpl<float>::convertQuaternionToRotation::`2::negateMask1);
  v28.m128_f32[0] = v28.m128_f32[0] + 1.0;
  v29 = _mm_sub_ps(v28, v27);
  v27.m128_f32[0] = v24;
  v30 = _mm_sub_ps(
          _mm_xor_ps(v28, (__m128)`hkVector4UtilImpl<float>::convertQuaternionToRotation::`2::negateMask0),
          v27);
  v31 = _mm_shuffle_ps(v30, v30, 177);
  v32 = _mm_shuffle_ps(_mm_movehl_ps(v29, v31), v26, 141);
  v33 = vWorldArmA->m_quad;
  v34 = _mm_shuffle_ps(v33, v33, 0);
  v35 = _mm_shuffle_ps(vWorldArmA->m_quad, vWorldArmA->m_quad, 85);
  v36 = _mm_shuffle_ps(v33, v33, 170);
  UA->m_col0.m_quad = _mm_sub_ps(_mm_mul_ps(v36, v23), _mm_mul_ps(v25, v35));
  UA->m_col1.m_quad = _mm_sub_ps(_mm_mul_ps(v25, v34), _mm_mul_ps(v36, v20));
  UA->m_col2.m_quad = _mm_sub_ps(_mm_mul_ps(v35, v20), _mm_mul_ps(v34, v23));
  v37 = vWorldArmB->m_quad;
  v38 = _mm_shuffle_ps(vWorldArmB->m_quad, vWorldArmB->m_quad, 85);
  v39 = _mm_shuffle_ps(v37, v37, 0);
  v40 = _mm_shuffle_ps(v37, v37, 170);
  UB->m_col0.m_quad = _mm_sub_ps(_mm_mul_ps(v40, v31), _mm_mul_ps(v32, v38));
  UB->m_col2.m_quad = _mm_sub_ps(_mm_mul_ps(v38, v29), _mm_mul_ps(v39, v31));
  UB->m_col1.m_quad = _mm_sub_ps(_mm_mul_ps(v32, v39), _mm_mul_ps(v40, v29));
  v41.m_quad = (__m128)UA->m_col1;
  v42.m_quad = (__m128)UA->m_col2;
  v43.m_quad = (__m128)UB->m_col1;
  v44 = _mm_mul_ps(v41.m_quad, invInertiaA->m_quad);
  v45 = _mm_mul_ps(UA->m_col0.m_quad, invInertiaA->m_quad);
  v46 = _mm_mul_ps(v42.m_quad, invInertiaA->m_quad);
  v47 = _mm_mul_ps(v44, v41.m_quad);
  v48 = _mm_mul_ps(v46, v42.m_quad);
  v49 = _mm_mul_ps(v45, UA->m_col0.m_quad);
  v50 = _mm_unpacklo_ps(v49, v47);
  v51 = _mm_mul_ps(v41.m_quad, v45);
  v52 = _mm_movelh_ps(v50, v48);
  v53 = _mm_mul_ps(v46, UA->m_col0.m_quad);
  v54 = _mm_mul_ps(v42.m_quad, v44);
  v55 = _mm_add_ps(v52, _mm_shuffle_ps(_mm_movehl_ps(v52, v50), v48, 212));
  v56 = _mm_unpacklo_ps(v51, v54);
  v57 = _mm_unpackhi_ps(v51, v54);
  v58.m_quad = (__m128)UB->m_col2;
  v59 = _mm_movelh_ps(v56, v53);
  v60 = _mm_add_ps(v55, _mm_shuffle_ps(_mm_unpackhi_ps(v49, v47), v48, 228));
  v61 = _mm_add_ps(_mm_add_ps(v59, _mm_shuffle_ps(_mm_movehl_ps(v59, v56), v53, 212)), _mm_shuffle_ps(v57, v53, 228));
  v62 = _mm_mul_ps(UB->m_col0.m_quad, invInertiaB->m_quad);
  v63 = _mm_mul_ps(v58.m_quad, invInertiaB->m_quad);
  v64 = _mm_mul_ps(v43.m_quad, invInertiaB->m_quad);
  v65 = _mm_mul_ps(v64, v43.m_quad);
  v66 = _mm_mul_ps(v63, v58.m_quad);
  v67 = _mm_mul_ps(v63, UB->m_col0.m_quad);
  v68 = _mm_mul_ps(v62, UB->m_col0.m_quad);
  v69 = _mm_mul_ps(v58.m_quad, v64);
  v70 = _mm_unpacklo_ps(v68, v65);
  v71 = _mm_unpackhi_ps(v68, v65);
  v72 = _mm_movelh_ps(v70, v66);
  v73 = _mm_shuffle_ps(_mm_movehl_ps(v72, v70), v66, 212);
  v74 = _mm_mul_ps(v43.m_quad, v62);
  v75 = _mm_unpackhi_ps(v74, v69);
  v76 = _mm_unpacklo_ps(v74, v69);
  v77 = _mm_add_ps(_mm_add_ps(_mm_add_ps(v72, v73), _mm_shuffle_ps(v71, v66, 228)), v60);
  v78 = _mm_movelh_ps(v76, v67);
  outK->m_diag.m_quad = _mm_add_ps(
                          _mm_add_ps(
                            _mm_shuffle_ps(invInertiaB->m_quad, invInertiaB->m_quad, 255),
                            _mm_shuffle_ps(invInertiaA->m_quad, invInertiaA->m_quad, 255)),
                          v77);
  outK->m_offDiag.m_quad = _mm_add_ps(
                             _mm_add_ps(
                               _mm_add_ps(v78, _mm_shuffle_ps(_mm_movehl_ps(v78, v76), v67, 212)),
                               _mm_shuffle_ps(v75, v67, 228)),
                             v61);
}

// File Line: 325
// RVA: 0xDE3D40
void __fastcall hkpAtomSolverFunctions::solveLinear3D<hkpVelocityAccumulator restrict *>(
        hkMatrix3f *axes,
        hkSimdFloat32 *fA,
        hkSimdFloat32 *fB,
        hkVector4f *armDirA,
        hkVector4f *armDirB,
        hkVector4f *bias,
        hkSimdFloat32 *maxLinearImpulse,
        hkSimdFloat32 *maxAngularImpulse,
        hkQuaternionf *rotA,
        hkQuaternionf *rotB,
        hkpVelocityAccumulator **regA,
        hkpVelocityAccumulator **regB,
        hkpSolverElemTemp *temps)
{
  __m128 v16; // xmm0
  __m128 v17; // xmm6
  __m128 v18; // xmm0
  __m128 v19; // xmm2
  __m128 v20; // xmm6
  __m128 v21; // xmm6
  __m128 v22; // xmm5
  __m128 v23; // xmm4
  __m128 v24; // xmm7
  __m128 v25; // xmm5
  __m128 v26; // xmm3
  __m128 v27; // xmm1
  __m128 v28; // xmm4
  __m128 v29; // xmm0
  __m128 v30; // xmm5
  __m128 v31; // xmm12
  __m128 v32; // xmm7
  __m128 v33; // xmm3
  __m128 v34; // xmm2
  __m128 v35; // xmm4
  __m128 v36; // xmm1
  __m128 v37; // xmm0
  __m128 v38; // xmm4
  __m128 v39; // xmm2
  __m128 v40; // xmm0
  __m128 v41; // xmm2
  __m128 v42; // xmm5
  __m128 v43; // xmm4
  __m128 v44; // xmm5
  __m128 v45; // xmm1
  hkpVelocityAccumulator *v46; // rax
  hkpVelocityAccumulator *v47; // rcx
  __m128 v48; // xmm3
  __m128 v49; // xmm1
  __m128 v50; // xmm0
  __m128 v51; // xmm3
  __m128 v52; // xmm6
  __m128 v53; // xmm2
  __m128 v54; // xmm7
  __m128 v55; // xmm3
  __m128 v56; // xmm6
  __m128 v57; // xmm4
  __m128 v58; // xmm5
  __m128 v59; // xmm2
  __m128 v60; // xmm4
  __m128 v61; // xmm5
  __m128 v62; // xmm4
  __m128 v63; // xmm1
  hkSimdFloat32 scale; // [rsp+60h] [rbp-118h] BYREF
  hkMatrix3f outK; // [rsp+70h] [rbp-108h] BYREF
  hkMatrix3f UA; // [rsp+A0h] [rbp-D8h] BYREF
  hkMatrix3f UB; // [rsp+D0h] [rbp-A8h] BYREF

  hkpAtomSolverFunctions::computeInverseVirtualMass3D<hkpVelocityAccumulator>(
    axes,
    fA,
    fB,
    rotA,
    rotB,
    armDirA,
    armDirB,
    *regA,
    *regB,
    &outK,
    &UA,
    &UB);
  v16 = _mm_shuffle_ps(outK.m_col0.m_quad, outK.m_col0.m_quad, 0);
  scale.m_real = _mm_min_ps(
                   _mm_max_ps(_mm_andnot_ps(_mm_cmpeq_ps((__m128)0i64, v16), _mm_rcp_ps(v16)), query.m_quad),
                   (__m128)xmmword_141A712B0);
  hkMatrix3f::mul(&outK, &scale);
  v17 = _mm_shuffle_ps(outK.m_col2.m_quad, outK.m_col2.m_quad, 201);
  v18 = _mm_shuffle_ps(outK.m_col1.m_quad, outK.m_col1.m_quad, 201);
  v19 = _mm_mul_ps(v17, outK.m_col0.m_quad);
  v20 = _mm_sub_ps(_mm_mul_ps(v17, outK.m_col1.m_quad), _mm_mul_ps(v18, outK.m_col2.m_quad));
  v21 = _mm_shuffle_ps(v20, v20, 201);
  v22 = _mm_shuffle_ps(outK.m_col0.m_quad, outK.m_col0.m_quad, 201);
  v23 = _mm_mul_ps(outK.m_col0.m_quad, v21);
  v24 = _mm_sub_ps(_mm_mul_ps(v18, outK.m_col0.m_quad), _mm_mul_ps(v22, outK.m_col1.m_quad));
  v25 = _mm_sub_ps(_mm_mul_ps(v22, outK.m_col2.m_quad), v19);
  v26 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v23, v23, 85), _mm_shuffle_ps(v23, v23, 0)), _mm_shuffle_ps(v23, v23, 170));
  v27 = _mm_rcp_ps(v26);
  v28 = _mm_and_ps(
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v27, v26)), v27),
          _mm_cmplt_ps(*(__m128 *)&epsilon, v26));
  v29 = _mm_mul_ps(v28, _mm_shuffle_ps(v25, v25, 201));
  v30 = _mm_max_ps(maxLinearImpulse->m_real, *(__m128 *)&epsilon);
  v31 = _mm_mul_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(bias->m_quad, bias->m_quad, 85), v29),
              _mm_mul_ps(_mm_shuffle_ps(bias->m_quad, bias->m_quad, 0), _mm_mul_ps(v28, v21))),
            _mm_mul_ps(_mm_shuffle_ps(bias->m_quad, bias->m_quad, 170), _mm_mul_ps(v28, _mm_shuffle_ps(v24, v24, 201)))),
          scale.m_real);
  v32 = _mm_mul_ps(v31, v31);
  v33 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v32, v32, 85), _mm_shuffle_ps(v32, v32, 0)), _mm_shuffle_ps(v32, v32, 170));
  v34 = _mm_rsqrt_ps(v33);
  v35 = _mm_andnot_ps(
          _mm_cmple_ps(v33, (__m128)0i64),
          _mm_mul_ps(
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v34, v33), v34)),
              _mm_mul_ps(*(__m128 *)_xmm, v34)),
            v33));
  v36 = _mm_rcp_ps(v35);
  v37 = _mm_mul_ps(v36, v35);
  v38 = _mm_cmple_ps(v35, v30);
  v39 = _mm_sub_ps((__m128)_xmm, v37);
  v40 = _mm_and_ps(v31, v38);
  v41 = _mm_mul_ps(_mm_mul_ps(v39, v36), v30);
  v42 = v38;
  v43 = _mm_max_ps(maxAngularImpulse->m_real, *(__m128 *)&epsilon);
  v44 = _mm_or_ps(_mm_andnot_ps(v42, _mm_mul_ps(v41, v31)), v40);
  v45 = _mm_rsqrt_ps(v33);
  v46 = *regA;
  v47 = *regB;
  v48 = _mm_andnot_ps(
          _mm_cmple_ps(v33, (__m128)0i64),
          _mm_mul_ps(
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v45, v33), v45)),
              _mm_mul_ps(*(__m128 *)_xmm, v45)),
            v33));
  v49 = _mm_rcp_ps(v48);
  v50 = _mm_mul_ps(v49, v48);
  v51 = _mm_cmple_ps(v48, v43);
  v52 = _mm_or_ps(
          _mm_andnot_ps(v51, _mm_mul_ps(_mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, v50), v49), v43), v31)),
          _mm_and_ps(v31, v51));
  v53 = _mm_shuffle_ps(v52, v52, 0);
  v54 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v44, v44, 85), axes->m_col1.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v44, v44, 0), axes->m_col0.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v44, v44, 170), axes->m_col2.m_quad));
  v55 = _mm_shuffle_ps(v52, v52, 85);
  v56 = _mm_shuffle_ps(v52, v52, 170);
  v57 = _mm_add_ps(_mm_mul_ps(UB.m_col0.m_quad, v53), _mm_mul_ps(UB.m_col1.m_quad, v55));
  v58 = _mm_mul_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(UA.m_col0.m_quad, v53), _mm_mul_ps(UA.m_col1.m_quad, v55)),
            _mm_mul_ps(UA.m_col2.m_quad, v56)),
          fA->m_real);
  v59 = _mm_add_ps(
          _mm_movelh_ps(
            (__m128)*(unsigned __int64 *)&temps->m_impulseApplied,
            (__m128)LODWORD(temps[2].m_impulseApplied)),
          v31);
  v60 = _mm_mul_ps(_mm_add_ps(v57, _mm_mul_ps(UB.m_col2.m_quad, v56)), fB->m_real);
  v61 = _mm_add_ps(_mm_mul_ps(v58, (*regA)->m_invMasses.m_quad), (*regA)->m_angularVel.m_quad);
  *(_QWORD *)&temps->m_impulseApplied = v59.m128_u64[0];
  v62 = _mm_mul_ps(v60, v47->m_invMasses.m_quad);
  LODWORD(temps[2].m_impulseApplied) = _mm_movehl_ps(v59, v59).m128_u32[0];
  v46->m_angularVel.m_quad = v61;
  v47->m_angularVel.m_quad = _mm_sub_ps(v47->m_angularVel.m_quad, v62);
  v63 = _mm_mul_ps(_mm_shuffle_ps(v47->m_invMasses.m_quad, v47->m_invMasses.m_quad, 255), v54);
  v46->m_linearVel.m_quad = _mm_add_ps(
                              _mm_mul_ps(_mm_shuffle_ps(v46->m_invMasses.m_quad, v46->m_invMasses.m_quad, 255), v54),
                              v46->m_linearVel.m_quad);
  v47->m_linearVel.m_quad = _mm_sub_ps(v47->m_linearVel.m_quad, v63);
}

// File Line: 381
// RVA: 0xDE18E0
void __fastcall hkpAtomSolverFunctions::getFuturePositions<hkpVelocityAccumulator,hkpSolverInfo>(
        hkpSolverInfo *solverInfo,
        hkpVelocityAccumulator *mA,
        hkVector4f *comAInWorld,
        hkQuaternionf *coreQworldA,
        hkpVelocityAccumulator *mB,
        hkVector4f *comBInWorld,
        hkQuaternionf *coreQworldB,
        hkQTransformf *futurePosOutA,
        hkQTransformf *futurePosOutB)
{
  __m128 v9; // xmm2
  __m128 v10; // xmm3
  __m128 v11; // xmm0
  __m128 v12; // xmm1
  __m128 v13; // xmm2
  hkVector4f v14; // xmm1
  __m128 v16; // xmm5
  __m128 v17; // xmm7
  __m128 v18; // xmm5
  __m128 v19; // xmm7
  __m128 v20; // xmm7
  __m128 v21; // xmm1
  __m128 v22; // xmm2
  __m128 v23; // xmm8
  __m128 v24; // xmm0
  __m128 v25; // xmm8
  __m128 v26; // xmm1
  __m128 v27; // xmm2
  __m128 v28; // xmm6
  __m128 v29; // xmm0
  __m128 v30; // xmm6
  __m128 v31; // xmm0
  __m128 v32; // xmm1
  __m128 v33; // xmm2
  __m128 v34; // xmm3
  __m128 v35; // xmm0
  __m128 v36; // xmm2
  __m128 v37; // xmm1
  __m128 v38; // xmm2

  v9 = _mm_shuffle_ps((__m128)LODWORD(solverInfo->m_deltaTime), (__m128)LODWORD(solverInfo->m_deltaTime), 0);
  v10 = _mm_sub_ps(solverInfo->m_invIntegrateVelocityFactor.m_quad, query.m_quad);
  v11 = _mm_mul_ps(_mm_add_ps(_mm_mul_ps(mA->m_scratch0.m_quad, v10), mA->m_linearVel.m_quad), v9);
  v12 = _mm_mul_ps(_mm_add_ps(_mm_mul_ps(mB->m_scratch0.m_quad, v10), mB->m_linearVel.m_quad), v9);
  v13 = _mm_mul_ps(v9, (__m128)xmmword_141A711B0);
  v14.m_quad = _mm_add_ps(v12, comBInWorld->m_quad);
  v16 = _mm_mul_ps(_mm_add_ps(_mm_mul_ps(mA->m_scratch1.m_quad, v10), mA->m_angularVel.m_quad), v13);
  v17 = _mm_mul_ps(mB->m_scratch1.m_quad, v10);
  futurePosOutA->m_translation.m_quad = _mm_add_ps(v11, comAInWorld->m_quad);
  futurePosOutB->m_translation = (hkVector4f)v14.m_quad;
  v18 = _mm_shuffle_ps(v16, _mm_unpackhi_ps(v16, query.m_quad), 196);
  v19 = _mm_mul_ps(_mm_add_ps(v17, mB->m_angularVel.m_quad), v13);
  v20 = _mm_shuffle_ps(v19, _mm_unpackhi_ps(v19, query.m_quad), 196);
  v21 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(coreQworldA->m_vec.m_quad, coreQworldA->m_vec.m_quad, 201), v18),
          _mm_mul_ps(_mm_shuffle_ps(v18, v18, 201), coreQworldA->m_vec.m_quad));
  v22 = _mm_mul_ps(coreQworldA->m_vec.m_quad, v18);
  v23 = _mm_sub_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(coreQworldA->m_vec.m_quad, coreQworldA->m_vec.m_quad, 255), v18),
            _mm_shuffle_ps(v21, v21, 201)),
          _mm_mul_ps(_mm_shuffle_ps(v18, v18, 255), coreQworldA->m_vec.m_quad));
  v24 = _mm_add_ps(_mm_shuffle_ps(v22, v22, 78), v22);
  v25 = _mm_shuffle_ps(v23, _mm_unpackhi_ps(v23, _mm_add_ps(_mm_shuffle_ps(v24, v24, 177), v24)), 196);
  v26 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(coreQworldB->m_vec.m_quad, coreQworldB->m_vec.m_quad, 201), v20),
          _mm_mul_ps(_mm_shuffle_ps(v20, v20, 201), coreQworldB->m_vec.m_quad));
  v27 = _mm_mul_ps(coreQworldB->m_vec.m_quad, v20);
  v28 = _mm_sub_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(coreQworldB->m_vec.m_quad, coreQworldB->m_vec.m_quad, 255), v20),
            _mm_shuffle_ps(v26, v26, 201)),
          _mm_mul_ps(_mm_shuffle_ps(v20, v20, 255), coreQworldB->m_vec.m_quad));
  v29 = _mm_add_ps(_mm_shuffle_ps(v27, v27, 78), v27);
  v30 = _mm_shuffle_ps(v28, _mm_unpackhi_ps(v28, _mm_add_ps(_mm_shuffle_ps(v29, v29, 177), v29)), 196);
  v31 = _mm_mul_ps(v25, v25);
  v32 = _mm_add_ps(_mm_shuffle_ps(v31, v31, 78), v31);
  v33 = _mm_add_ps(_mm_shuffle_ps(v32, v32, 177), v32);
  v34 = _mm_rsqrt_ps(v33);
  v35 = _mm_mul_ps(v30, v30);
  futurePosOutA->m_rotation.m_vec.m_quad = _mm_mul_ps(
                                             v25,
                                             _mm_mul_ps(
                                               _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v34, v33), v34)),
                                               _mm_mul_ps(*(__m128 *)_xmm, v34)));
  v36 = _mm_add_ps(_mm_shuffle_ps(v35, v35, 78), v35);
  v37 = _mm_add_ps(_mm_shuffle_ps(v36, v36, 177), v36);
  v38 = _mm_rsqrt_ps(v37);
  futurePosOutB->m_rotation.m_vec.m_quad = _mm_mul_ps(
                                             v30,
                                             _mm_mul_ps(
                                               _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v38, v37), v38)),
                                               _mm_mul_ps(*(__m128 *)_xmm, v38)));
}

// File Line: 438
// RVA: 0xDE4C30
void __fastcall hkpAtomSolverFunctions::solveStableBallSocket<hkpVelocityAccumulator,hkpSolverInfo,hkSolverStepTemp>(
        hkpSolverInfo *solverInfo,
        hkSolverStepTemp *temp,
        hkpStableBallSocketSchema *schema,
        hkpVelocityAccumulator *mA,
        hkpVelocityAccumulator *mB)
{
  hkVector4f v6; // xmm9
  hkVector4f v7; // xmm7
  __m128 v8; // xmm1
  __m128 v9; // xmm3
  __m128 v10; // xmm4
  __m128 v11; // xmm8
  __m128 v12; // xmm0
  __m128 v13; // xmm1
  __m128 v14; // xmm9
  __m128 v15; // xmm8
  __m128 v16; // xmm8
  __m128 v17; // xmm4
  __m128 v18; // xmm3
  __m128 v19; // xmm6
  __m128 v20; // xmm6
  hkVector4f v21; // xmm3
  __m128 v22; // xmm7
  __m128 v23; // xmm0
  hkSimdFloat32 fB; // [rsp+70h] [rbp-88h] BYREF
  __int64 v25; // [rsp+80h] [rbp-78h]
  hkSimdFloat32 maxLinearImpulse; // [rsp+88h] [rbp-70h] BYREF
  hkSimdFloat32 fA; // [rsp+98h] [rbp-60h] BYREF
  hkVector4f armDirB; // [rsp+A8h] [rbp-50h] BYREF
  hkQTransformf futurePosOutB; // [rsp+B8h] [rbp-40h] BYREF
  hkVector4f bias; // [rsp+D8h] [rbp-20h] BYREF
  hkQTransformf futurePosOutA; // [rsp+E8h] [rbp-10h] BYREF
  hkSimdFloat32 maxAngularImpulse; // [rsp+108h] [rbp+10h] BYREF
  hkMatrix3f axes; // [rsp+118h] [rbp+20h] BYREF
  hkpVelocityAccumulator *regA; // [rsp+1B0h] [rbp+B8h] BYREF
  hkpVelocityAccumulator *regB; // [rsp+1B8h] [rbp+C0h] BYREF

  regB = mA;
  hkpAtomSolverFunctions::getFuturePositions<hkpVelocityAccumulator,hkpSolverInfo>(
    solverInfo,
    mA,
    &mA->m_scratch3,
    (hkQuaternionf *)&mA->m_scratch2,
    mA,
    &mA->m_scratch3,
    (hkQuaternionf *)&mA->m_scratch2,
    &futurePosOutA,
    (hkQTransformf *)&futurePosOutB.m_rotation.m_vec.m_quad.m128_u16[4]);
  v6.m_quad = (__m128)schema->m_armDirA;
  v7.m_quad = (__m128)schema->m_armDirB;
  v8 = _mm_mul_ps(v6.m_quad, futurePosOutA.m_rotation.m_vec.m_quad);
  v9 = _mm_sub_ps(
         _mm_mul_ps(_mm_shuffle_ps(v6.m_quad, v6.m_quad, 201), futurePosOutA.m_rotation.m_vec.m_quad),
         _mm_mul_ps(
           _mm_shuffle_ps(futurePosOutA.m_rotation.m_vec.m_quad, futurePosOutA.m_rotation.m_vec.m_quad, 201),
           v6.m_quad));
  v10 = _mm_shuffle_ps(futurePosOutA.m_rotation.m_vec.m_quad, futurePosOutA.m_rotation.m_vec.m_quad, 255);
  v11 = _mm_mul_ps(
          _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)), _mm_shuffle_ps(v8, v8, 170)),
          futurePosOutA.m_rotation.m_vec.m_quad);
  v12 = _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v10, v10), (__m128)xmmword_141A711B0), v6.m_quad);
  v13 = _mm_mul_ps(v7.m_quad, futurePosOutB.m_rotation.m_vec.m_quad);
  v14 = _mm_shuffle_ps(v6.m_quad, v6.m_quad, 255);
  v15 = _mm_add_ps(_mm_add_ps(v11, v12), _mm_mul_ps(_mm_shuffle_ps(v9, v9, 201), v10));
  v16 = _mm_add_ps(v15, v15);
  v17 = _mm_shuffle_ps(futurePosOutB.m_rotation.m_vec.m_quad, futurePosOutB.m_rotation.m_vec.m_quad, 255);
  v18 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v7.m_quad, v7.m_quad, 201), futurePosOutB.m_rotation.m_vec.m_quad),
          _mm_mul_ps(
            _mm_shuffle_ps(futurePosOutB.m_rotation.m_vec.m_quad, futurePosOutB.m_rotation.m_vec.m_quad, 201),
            v7.m_quad));
  v19 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)),
                _mm_shuffle_ps(v13, v13, 170)),
              futurePosOutB.m_rotation.m_vec.m_quad),
            _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v17, v17), (__m128)xmmword_141A711B0), v7.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v18, v18, 201), v17));
  v20 = _mm_add_ps(v19, v19);
  v21.m_quad = (__m128)schema->m_data1;
  v22 = _mm_shuffle_ps(v7.m_quad, v7.m_quad, 255);
  axes.m_col1 = (hkVector4f)direction.m_quad;
  bias.m_quad = _mm_mul_ps(
                  _mm_add_ps(
                    _mm_sub_ps(_mm_mul_ps(v20, v22), _mm_mul_ps(v16, v14)),
                    _mm_sub_ps(futurePosOutB.m_translation.m_quad, futurePosOutA.m_translation.m_quad)),
                  _mm_shuffle_ps(v21.m_quad, v21.m_quad, 0));
  axes.m_col0 = (hkVector4f)transform.m_quad;
  fA.m_real = _mm_shuffle_ps(v21.m_quad, v21.m_quad, 170);
  axes.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  v25 = *(unsigned __int128 *)&_mm_shuffle_ps(v21.m_quad, v21.m_quad, 255) >> 64;
  maxAngularImpulse.m_real = _mm_shuffle_ps(v21.m_quad, v21.m_quad, 85);
  fB.m_real = _mm_shuffle_ps(v16, _mm_unpackhi_ps(v16, v14), 196);
  v23 = _mm_shuffle_ps(schema->m_data0.m_quad, schema->m_data0.m_quad, 170);
  armDirB.m_quad = _mm_shuffle_ps(v20, _mm_unpackhi_ps(v20, v22), 196);
  maxLinearImpulse.m_real = v23;
  hkpAtomSolverFunctions::solveLinear3D<hkpVelocityAccumulator restrict *>(
    &axes,
    &fA,
    (hkSimdFloat32 *)&fB.m_real.m128_u16[4],
    (hkVector4f *)&fB,
    &armDirB,
    &bias,
    &maxLinearImpulse,
    &maxAngularImpulse,
    &futurePosOutA.m_rotation,
    &futurePosOutB.m_rotation,
    &regA,
    &regB,
    (hkpSolverElemTemp *)mB);
}

// File Line: 495
// RVA: 0xDE4EC0
void __fastcall hkpAtomSolverFunctions::solveStableStiffSpring<hkpVelocityAccumulator,hkpSolverInfo,hkSolverStepTemp,hkpStableStiffSpringSchema>(
        hkpSolverInfo *info,
        hkSolverStepTemp *temp,
        hkpStableStiffSpringSchema *schema,
        hkpVelocityAccumulator *regA,
        hkpVelocityAccumulator *regB,
        hkpSolverElemTemp *temps)
{
  hkVector4f v8; // xmm6
  hkVector4f v9; // xmm8
  __m128 v10; // xmm3
  __m128 v11; // xmm1
  __m128 v12; // xmm14
  __m128 v13; // xmm15
  __m128 v14; // xmm2
  __m128 v15; // xmm1
  __m128 v16; // xmm2
  __m128 v17; // xmm3
  __m128 v18; // xmm6
  hkVector4f v19; // xmm11
  __m128 v20; // xmm2
  __m128 v21; // xmm8
  __m128 v22; // xmm3
  __m128 v23; // xmm1
  __m128 v24; // xmm4
  __m128 v25; // xmm1
  __m128 v26; // xmm5
  __m128 v27; // xmm2
  __m128 v28; // xmm0
  __m128 v29; // xmm1
  __m128 v30; // xmm2
  __m128 v31; // xmm13
  __m128 v32; // xmm5
  __m128 v33; // xmm4
  __m128 v34; // xmm13
  __m128 v35; // xmm12
  __m128 v36; // xmm1
  __m128 v37; // xmm0
  __m128 v38; // xmm12
  hkVector4f v39; // xmm5
  __m128 v40; // xmm7
  __m128 v41; // xmm0
  __m128 v42; // xmm3
  hkVector4f v43; // xmm6
  __m128 v44; // xmm3
  __m128 v45; // xmm3
  __m128 v46; // xmm7
  __m128 v47; // xmm7
  __m128 v48; // xmm2
  __m128 v49; // xmm2
  __m128 v50; // xmm0
  __m128 v51; // xmm1
  __m128 v52; // xmm0
  __m128 v53; // xmm11
  __m128 v54; // xmm3
  __m128 v55; // xmm7
  __m128 v56; // xmm13
  __m128 v57; // xmm1
  __m128 v58; // xmm2
  __m128 v59; // xmm4
  __m128 v60; // xmm1
  __m128 v61; // xmm4
  __m128 v62; // xmm2
  __m128 v63; // xmm3
  __m128 v64; // xmm3
  hkVector4f v65; // xmm0
  __m128 v66; // [rsp+50h] [rbp-108h]
  __m128 v67; // [rsp+60h] [rbp-F8h]
  hkQTransformf futurePosOutB; // [rsp+70h] [rbp-E8h] BYREF
  hkQTransformf futurePosOutA; // [rsp+90h] [rbp-C8h] BYREF

  hkpAtomSolverFunctions::getFuturePositions<hkpVelocityAccumulator,hkpSolverInfo>(
    info,
    regA,
    &regA->m_scratch3,
    (hkQuaternionf *)&regA->m_scratch2,
    regB,
    &regB->m_scratch3,
    (hkQuaternionf *)&regB->m_scratch2,
    &futurePosOutA,
    &futurePosOutB);
  v8.m_quad = (__m128)schema->m_armVecA;
  v9.m_quad = (__m128)schema->m_armVecB;
  v66 = _mm_shuffle_ps(futurePosOutA.m_rotation.m_vec.m_quad, futurePosOutA.m_rotation.m_vec.m_quad, 201);
  v10 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v8.m_quad, v8.m_quad, 201), futurePosOutA.m_rotation.m_vec.m_quad),
          _mm_mul_ps(v66, v8.m_quad));
  v11 = _mm_mul_ps(futurePosOutA.m_rotation.m_vec.m_quad, v8.m_quad);
  v12 = _mm_shuffle_ps(futurePosOutA.m_rotation.m_vec.m_quad, futurePosOutA.m_rotation.m_vec.m_quad, 255);
  v13 = _mm_shuffle_ps(futurePosOutB.m_rotation.m_vec.m_quad, futurePosOutB.m_rotation.m_vec.m_quad, 255);
  v14 = _mm_mul_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)),
            _mm_shuffle_ps(v11, v11, 170)),
          futurePosOutA.m_rotation.m_vec.m_quad);
  v15 = _mm_mul_ps(futurePosOutB.m_rotation.m_vec.m_quad, v9.m_quad);
  v16 = _mm_add_ps(
          _mm_add_ps(v14, _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v12, v12), (__m128)xmmword_141A711B0), v8.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), v12));
  v67 = _mm_shuffle_ps(futurePosOutB.m_rotation.m_vec.m_quad, futurePosOutB.m_rotation.m_vec.m_quad, 201);
  v17 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v9.m_quad, v9.m_quad, 201), futurePosOutB.m_rotation.m_vec.m_quad),
          _mm_mul_ps(v67, v9.m_quad));
  v18 = _mm_mul_ps(_mm_shuffle_ps(v8.m_quad, v8.m_quad, 255), _mm_add_ps(v16, v16));
  v19.m_quad = (__m128)schema->m_data0;
  v20 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)),
                _mm_shuffle_ps(v15, v15, 170)),
              futurePosOutB.m_rotation.m_vec.m_quad),
            _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v13, v13), (__m128)xmmword_141A711B0), v9.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v17, v17, 201), v13));
  v21 = _mm_mul_ps(_mm_shuffle_ps(v9.m_quad, v9.m_quad, 255), _mm_add_ps(v20, v20));
  v22 = _mm_sub_ps(
          _mm_add_ps(futurePosOutA.m_translation.m_quad, v18),
          _mm_add_ps(futurePosOutB.m_translation.m_quad, v21));
  v23 = _mm_mul_ps(v22, v22);
  v24 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v23, v23, 85), _mm_shuffle_ps(v23, v23, 0)), _mm_shuffle_ps(v23, v23, 170));
  v25 = _mm_rsqrt_ps(v24);
  v26 = _mm_cmplt_ps(v24, (__m128)xmmword_141A712D0);
  v27 = _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v25, v24), v25));
  v28 = _mm_mul_ps(*(__m128 *)_xmm, v25);
  v29 = _mm_and_ps(v26, transform.m_quad);
  v30 = _mm_mul_ps(v27, v28);
  v31 = _mm_andnot_ps(v26, _mm_mul_ps(v30, v22));
  v32 = _mm_andnot_ps(v26, _mm_mul_ps(v30, v24));
  v33 = _mm_shuffle_ps(v19.m_quad, v19.m_quad, 85);
  v34 = _mm_or_ps(v31, v29);
  v35 = _mm_cmplt_ps(v32, v33);
  v36 = _mm_shuffle_ps(v19.m_quad, v19.m_quad, 170);
  v37 = _mm_cmplt_ps(v36, v32);
  v38 = _mm_sub_ps(
          _mm_or_ps(_mm_andnot_ps(v35, _mm_or_ps(_mm_and_ps(v37, v36), _mm_andnot_ps(v37, v32))), _mm_and_ps(v35, v33)),
          v32);
  if ( v38.m128_f32[0] != 0.0 )
  {
    v39.m_quad = (__m128)regA->m_invMasses;
    v40 = _mm_shuffle_ps(v34, v34, 201);
    v41 = _mm_shuffle_ps(v18, v18, 201);
    v42 = _mm_mul_ps(v40, v18);
    v43.m_quad = (__m128)regB->m_invMasses;
    v44 = _mm_sub_ps(v42, _mm_mul_ps(v41, v34));
    v45 = _mm_shuffle_ps(v44, v44, 201);
    v46 = _mm_sub_ps(_mm_mul_ps(v40, v21), _mm_mul_ps(_mm_shuffle_ps(v21, v21, 201), v34));
    v47 = _mm_shuffle_ps(v46, v46, 201);
    v48 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v45, v45), v39.m_quad), _mm_mul_ps(_mm_mul_ps(v47, v47), v43.m_quad));
    v49 = _mm_shuffle_ps(
            v48,
            _mm_unpackhi_ps(v48, _mm_max_ps(_mm_add_ps(v39.m_quad, v43.m_quad), (__m128)xmmword_141A712D0)),
            196);
    v50 = _mm_add_ps(_mm_shuffle_ps(v49, v49, 78), v49);
    v51 = _mm_add_ps(_mm_shuffle_ps(v50, v50, 177), v50);
    v52 = _mm_rcp_ps(v51);
    v53 = _mm_mul_ps(
            _mm_mul_ps(_mm_shuffle_ps(v19.m_quad, v19.m_quad, 255), v38),
            _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v51, v52)), v52));
    v54 = _mm_mul_ps(v45, v53);
    v55 = _mm_mul_ps(v47, v53);
    v56 = _mm_mul_ps(v34, v53);
    v57 = _mm_mul_ps(futurePosOutA.m_rotation.m_vec.m_quad, v54);
    v58 = _mm_sub_ps(
            _mm_mul_ps(v54, v66),
            _mm_mul_ps(_mm_shuffle_ps(v54, v54, 201), futurePosOutA.m_rotation.m_vec.m_quad));
    v59 = _mm_mul_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v57, v57, 85), _mm_shuffle_ps(v57, v57, 0)),
              _mm_shuffle_ps(v57, v57, 170)),
            futurePosOutA.m_rotation.m_vec.m_quad);
    v60 = _mm_mul_ps(futurePosOutB.m_rotation.m_vec.m_quad, v55);
    v61 = _mm_add_ps(
            _mm_add_ps(v59, _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v12, v12), (__m128)xmmword_141A711B0), v54)),
            _mm_mul_ps(_mm_shuffle_ps(v58, v58, 201), v12));
    v62 = _mm_sub_ps(
            _mm_mul_ps(v55, v67),
            _mm_mul_ps(_mm_shuffle_ps(v55, v55, 201), futurePosOutB.m_rotation.m_vec.m_quad));
    v63 = _mm_mul_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v60, v60, 85), _mm_shuffle_ps(v60, v60, 0)),
              _mm_shuffle_ps(v60, v60, 170)),
            futurePosOutB.m_rotation.m_vec.m_quad);
    regA->m_angularVel.m_quad = _mm_add_ps(_mm_mul_ps(_mm_add_ps(v61, v61), v39.m_quad), regA->m_angularVel.m_quad);
    v64 = _mm_add_ps(
            _mm_add_ps(v63, _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v13, v13), (__m128)xmmword_141A711B0), v55)),
            _mm_mul_ps(_mm_shuffle_ps(v62, v62, 201), v13));
    v65.m_quad = _mm_sub_ps(regB->m_angularVel.m_quad, _mm_mul_ps(_mm_add_ps(v64, v64), v43.m_quad));
    regA->m_linearVel.m_quad = _mm_add_ps(
                                 _mm_mul_ps(
                                   _mm_shuffle_ps(regA->m_invMasses.m_quad, regA->m_invMasses.m_quad, 255),
                                   v56),
                                 regA->m_linearVel.m_quad);
    regB->m_angularVel = (hkVector4f)v65.m_quad;
    regB->m_linearVel.m_quad = _mm_sub_ps(
                                 regB->m_linearVel.m_quad,
                                 _mm_mul_ps(
                                   _mm_shuffle_ps(regB->m_invMasses.m_quad, regB->m_invMasses.m_quad, 255),
                                   v56));
    temps->m_impulseApplied = _mm_shuffle_ps(
                                (__m128)LODWORD(temps->m_impulseApplied),
                                (__m128)LODWORD(temps->m_impulseApplied),
                                0).m128_f32[0]
                            + v53.m128_f32[0];
  }
}

// File Line: 632
// RVA: 0xDE4270
void __fastcall hkpAtomSolverFunctions::solveQuatAngular3D<hkpVelocityAccumulator>(
        hkSimdFloat32 *erp,
        hkSimdFloat32 *maxImpulse,
        hkQuaternionf *lA,
        hkQuaternionf *lB,
        hkQuaternionf *qA,
        hkQuaternionf *qB,
        hkpVelocityAccumulator *regA,
        hkpVelocityAccumulator *regB,
        hkpSolverElemTemp *temps)
{
  __m128 v10; // xmm4
  __m128 v11; // xmm5
  __m128 v12; // xmm3
  __m128 v13; // xmm7
  __m128 m_quad; // xmm8
  __m128 v15; // xmm7
  __m128 v16; // xmm4
  __m128 v17; // xmm5
  __m128 v18; // xmm7
  __m128 v19; // xmm4
  __m128 v20; // xmm6
  __m128 v21; // xmm3
  __m128 v22; // xmm6
  __m128 v23; // xmm6
  __m128 v24; // xmm2
  __m128 v25; // xmm1
  __m128 v26; // xmm0
  __m128 v27; // xmm6
  __m128 v28; // xmm2
  __m128 v29; // xmm0
  __m128 v30; // xmm2
  __m128 v31; // xmm13
  __m128 v32; // xmm14
  __m128 v33; // xmm2
  __m128 v34; // xmm12
  __m128 v35; // xmm8
  __m128 v36; // xmm1
  __m128 v37; // xmm3
  __m128 v38; // xmm3
  __m128 v39; // xmm8
  __m128 v40; // xmm9
  __m128 v41; // xmm8
  __m128 v42; // xmm10
  __m128 v43; // xmm0
  __m128 v44; // xmm2
  __m128 v45; // xmm3
  __m128 v46; // xmm1
  __m128 v47; // xmm8
  __m128 v48; // xmm5
  __m128 v49; // xmm0
  __m128 v50; // xmm10
  __m128 v51; // xmm5
  __m128 v52; // xmm7
  __m128 v53; // xmm6
  __m128 v54; // xmm1
  __m128 v55; // xmm4
  __m128 v56; // xmm0
  __m128 v57; // xmm4
  __m128 v58; // xmm1
  __m128 v59; // xmm9
  __m128 v60; // xmm1
  __m128 v61; // xmm2
  __m128 v62; // xmm0
  __m128 v63; // xmm8
  __m128 v64; // xmm9
  __m128 v65; // xmm14
  __m128 v66; // xmm1
  __m128 v67; // xmm2
  __m128 v68; // xmm3
  __m128 v69; // xmm3
  __m128 v70; // xmm14
  __m128 v71; // xmm12
  __m128 v72; // xmm14
  __m128 v73; // xmm13
  __m128 v74; // xmm11
  __m128 v75; // xmm14
  __m128 v76; // xmm0
  __m128 v77; // xmm7
  __m128 v78; // xmm1
  __m128 v79; // xmm13
  __m128 v80; // xmm8
  __m128 v81; // xmm6
  __m128 v82; // xmm5
  __m128 v83; // xmm0
  __m128 v84; // xmm9
  __m128 v85; // xmm1
  __m128 v86; // xmm11
  __m128 v87; // xmm4
  __m128 v88; // xmm12
  __m128 v89; // xmm7
  __m128 v90; // xmm14
  __m128 v91; // xmm0
  __m128 v92; // xmm2
  hkVector4f v93; // xmm3
  __m128 v94; // xmm2
  __m128 v95; // xmm0
  __m128 v96; // xmm12
  __m128 v97; // xmm13
  __m128 v98; // xmm11
  hkVector4f v99; // xmm4
  __m128 m_real; // xmm10
  __m128 v101; // xmm2
  __m128 v102; // xmm6
  __m128 v103; // xmm7
  __m128 v104; // xmm1
  __m128 v105; // xmm5
  __m128 v106; // xmm0
  __m128 v107; // xmm8
  __m128 v108; // xmm0
  __m128 v109; // xmm4
  __m128 v110; // xmm3
  __m128 v111; // xmm0
  __m128 v112; // xmm2
  hkVector4f v113; // xmm7
  hkVector4f v114; // xmm1
  __m128 v115; // xmm8
  __m128 v116; // xmm3
  __m128 v117; // xmm2
  __m128 v118; // xmm7
  __m128 v119; // xmm1
  __m128 v120; // xmm7
  __m128 v121; // xmm5
  __m128 v122; // xmm8
  __m128 v123; // xmm6
  __m128 v124; // xmm3
  __m128 v125; // xmm1
  __m128 v126; // xmm0
  __m128 v127; // xmm4
  __m128 v128; // xmm6
  __m128 v129; // xmm7
  __m128 v130; // xmm1
  __m128 v131; // xmm3
  __m128 v132; // xmm1
  __m128 v133; // xmm4
  __m128 v134; // xmm1
  __m128 v135; // xmm0
  __m128 v136; // xmm4
  __m128 v137; // xmm3
  __m128 v138; // xmm0
  __m128 v139; // xmm1
  __m128 v140; // xmm2
  __m128 v141; // xmm13
  __m128 v142; // xmm4
  __m128 v143; // xmm12
  __m128 v144; // xmm10
  hkVector4f v145; // xmm0
  __m128 v146; // xmm1
  hkVector4f v147; // xmm0
  __m128 v148; // [rsp+20h] [rbp-128h]
  __m128 v149; // [rsp+20h] [rbp-128h]
  __m128 v150; // [rsp+30h] [rbp-118h]
  __m128 v151; // [rsp+30h] [rbp-118h]
  __m128 v152; // [rsp+40h] [rbp-108h]
  __m128 v153; // [rsp+40h] [rbp-108h]
  hkSimdFloat32 scale; // [rsp+50h] [rbp-F8h] BYREF
  __m128 v155; // [rsp+60h] [rbp-E8h]
  hkMatrix3f v156; // [rsp+70h] [rbp-D8h] BYREF

  v10 = _mm_shuffle_ps(lA->m_vec.m_quad, lA->m_vec.m_quad, 255);
  v11 = _mm_mul_ps(qA->m_vec.m_quad, lA->m_vec.m_quad);
  v12 = _mm_shuffle_ps(qA->m_vec.m_quad, qA->m_vec.m_quad, 255);
  v13 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(lA->m_vec.m_quad, lA->m_vec.m_quad, 201), qA->m_vec.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(qA->m_vec.m_quad, qA->m_vec.m_quad, 201), lA->m_vec.m_quad));
  m_quad = lB->m_vec.m_quad;
  v15 = _mm_add_ps(
          _mm_add_ps(_mm_shuffle_ps(v13, v13, 201), _mm_mul_ps(lA->m_vec.m_quad, v12)),
          _mm_mul_ps(qA->m_vec.m_quad, v10));
  v16 = _mm_sub_ps(
          _mm_mul_ps(v10, v12),
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)),
            _mm_shuffle_ps(v11, v11, 170)));
  v17 = _mm_shuffle_ps(lB->m_vec.m_quad, lB->m_vec.m_quad, 255);
  v18 = _mm_shuffle_ps(v15, _mm_unpackhi_ps(v15, v16), 196);
  v19 = _mm_shuffle_ps(qB->m_vec.m_quad, qB->m_vec.m_quad, 255);
  v20 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(lB->m_vec.m_quad, lB->m_vec.m_quad, 201), qB->m_vec.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(qB->m_vec.m_quad, qB->m_vec.m_quad, 201), lB->m_vec.m_quad));
  v21 = _mm_mul_ps(lB->m_vec.m_quad, qB->m_vec.m_quad);
  v22 = _mm_add_ps(
          _mm_add_ps(_mm_shuffle_ps(v20, v20, 201), _mm_mul_ps(lB->m_vec.m_quad, v19)),
          _mm_mul_ps(qB->m_vec.m_quad, v17));
  v23 = _mm_shuffle_ps(
          v22,
          _mm_unpackhi_ps(
            v22,
            _mm_sub_ps(
              _mm_mul_ps(v17, v19),
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)),
                _mm_shuffle_ps(v21, v21, 170)))),
          196);
  v24 = _mm_mul_ps(_mm_shuffle_ps(v18, v18, 255), v23);
  v25 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v18, v18, 201), v23), _mm_mul_ps(_mm_shuffle_ps(v23, v23, 201), v18));
  v26 = _mm_shuffle_ps(v23, v23, 255);
  v27 = _mm_mul_ps(v23, v18);
  v28 = _mm_sub_ps(_mm_add_ps(v24, _mm_shuffle_ps(v25, v25, 201)), _mm_mul_ps(v26, v18));
  v29 = _mm_add_ps(_mm_shuffle_ps(v27, v27, 78), v27);
  v30 = _mm_shuffle_ps(v28, _mm_unpackhi_ps(v28, _mm_add_ps(_mm_shuffle_ps(v29, v29, 177), v29)), 196);
  v155 = _mm_mul_ps(_mm_sub_ps((__m128)0i64, erp->m_real), v30);
  v150 = _mm_xor_ps(
           (__m128)_mm_slli_epi32(_mm_srli_epi32((__m128i)xmmword_141A9E9C0, 0x1Fu), 0x1Fu),
           _mm_shuffle_ps(v30, v30, 27));
  v31 = _mm_xor_ps(
          (__m128)_mm_slli_epi32(_mm_srli_epi32((__m128i)xmmword_141A9E9E0, 0x1Fu), 0x1Fu),
          _mm_shuffle_ps(v30, v30, 78));
  v32 = _mm_xor_ps(
          (__m128)_mm_slli_epi32(_mm_srli_epi32((__m128i)xmmword_141A9E9B0, 0x1Fu), 0x1Fu),
          _mm_shuffle_ps(v30, v30, 177));
  v33 = transform.m_quad;
  v34 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64);
  v35 = _mm_xor_ps(m_quad, v34);
  v36 = _mm_add_ps(v35, v35);
  v37 = _mm_mul_ps(_mm_shuffle_ps(v35, v35, 65), _mm_shuffle_ps(v36, v36, 165));
  v29.m128_f32[0] = v35.m128_f32[0] * v36.m128_f32[0];
  v33.m128_f32[0] = (float)(1.0 - (float)(v35.m128_f32[0] * v36.m128_f32[0])) - v37.m128_f32[0];
  v38 = _mm_xor_ps(v37, (__m128)`hkVector4UtilImpl<float>::convertQuaternionToRotation::`2::negateMask0);
  v39 = _mm_xor_ps(
          _mm_mul_ps(_mm_shuffle_ps(v35, v35, 254), _mm_shuffle_ps(v36, v36, 26)),
          (__m128)`hkVector4UtilImpl<float>::convertQuaternionToRotation::`2::negateMask1);
  v39.m128_f32[0] = v39.m128_f32[0] + 1.0;
  v40 = _mm_sub_ps(v39, v38);
  v38.m128_f32[0] = v29.m128_f32[0];
  v41 = _mm_sub_ps(
          _mm_xor_ps(v39, (__m128)`hkVector4UtilImpl<float>::convertQuaternionToRotation::`2::negateMask0),
          v38);
  scale.m_real = _mm_shuffle_ps(v41, v41, 177);
  v42 = _mm_shuffle_ps(_mm_movehl_ps(v40, scale.m_real), v33, 141);
  v43 = _mm_mul_ps(v150, scale.m_real);
  v44 = _mm_mul_ps(v150, v40);
  v45 = _mm_mul_ps(v31, v40);
  v46 = _mm_unpacklo_ps(v44, v43);
  v47 = _mm_mul_ps(v42, v150);
  v48 = v42;
  v148 = _mm_unpackhi_ps(v44, v43);
  v49 = _mm_mul_ps(v31, scale.m_real);
  v50 = _mm_mul_ps(v42, v32);
  v51 = _mm_mul_ps(v48, v31);
  v52 = _mm_movelh_ps(v46, v47);
  v53 = _mm_movehl_ps(v52, v46);
  v54 = _mm_unpacklo_ps(v45, v49);
  v152 = _mm_unpackhi_ps(v45, v49);
  v55 = _mm_movelh_ps(v54, v51);
  v56 = _mm_mul_ps(v32, scale.m_real);
  v57 = _mm_add_ps(v55, _mm_shuffle_ps(_mm_movehl_ps(v55, v54), v51, 212));
  v58 = _mm_mul_ps(v32, v40);
  v59 = _mm_unpackhi_ps(v58, v56);
  v60 = _mm_unpacklo_ps(v58, v56);
  v61 = _mm_movelh_ps(v60, v50);
  scale.m_real = _mm_mul_ps(
                   _mm_add_ps(
                     _mm_shuffle_ps(v59, v50, 228),
                     _mm_add_ps(v61, _mm_shuffle_ps(_mm_movehl_ps(v61, v60), v50, 212))),
                   (__m128)xmmword_141A711B0);
  v149 = _mm_mul_ps(
           _mm_add_ps(_mm_shuffle_ps(v148, v47, 228), _mm_add_ps(v52, _mm_shuffle_ps(v53, v47, 212))),
           (__m128)xmmword_141A711B0);
  v153 = _mm_mul_ps(_mm_add_ps(_mm_shuffle_ps(v152, v51, 228), v57), (__m128)xmmword_141A711B0);
  v62 = _mm_unpacklo_ps(v150, v31);
  v63 = _mm_movelh_ps(v62, v32);
  v151 = _mm_shuffle_ps(_mm_unpackhi_ps(v150, v31), v32, 228);
  v64 = _mm_shuffle_ps(_mm_movehl_ps(v63, v62), v32, 212);
  v65 = _mm_xor_ps(lA->m_vec.m_quad, v34);
  v66 = _mm_add_ps(v65, v65);
  v67 = transform.m_quad;
  v68 = _mm_mul_ps(_mm_shuffle_ps(v66, v66, 165), _mm_shuffle_ps(v65, v65, 65));
  v62.m128_f32[0] = v65.m128_f32[0] * v66.m128_f32[0];
  v67.m128_f32[0] = (float)(1.0 - (float)(v65.m128_f32[0] * v66.m128_f32[0])) - v68.m128_f32[0];
  v69 = _mm_xor_ps(v68, (__m128)`hkVector4UtilImpl<float>::convertQuaternionToRotation::`2::negateMask0);
  v70 = _mm_xor_ps(
          _mm_mul_ps(_mm_shuffle_ps(v65, v65, 254), _mm_shuffle_ps(v66, v66, 26)),
          (__m128)`hkVector4UtilImpl<float>::convertQuaternionToRotation::`2::negateMask1);
  v70.m128_f32[0] = v70.m128_f32[0] + 1.0;
  v71 = _mm_sub_ps(v70, v69);
  v69.m128_f32[0] = v62.m128_f32[0];
  v72 = _mm_sub_ps(
          _mm_xor_ps(v70, (__m128)`hkVector4UtilImpl<float>::convertQuaternionToRotation::`2::negateMask0),
          v69);
  v73 = _mm_mul_ps(v71, v63);
  v74 = _mm_mul_ps(v71, v64);
  v75 = _mm_shuffle_ps(v72, v72, 177);
  v76 = _mm_mul_ps(v75, v63);
  v77 = _mm_shuffle_ps(_mm_movehl_ps(v71, v75), v67, 141);
  v78 = _mm_unpacklo_ps(v73, v76);
  v79 = _mm_unpackhi_ps(v73, v76);
  v80 = _mm_mul_ps(v63, v77);
  v81 = _mm_movelh_ps(v78, v80);
  v82 = _mm_movehl_ps(v81, v78);
  v83 = _mm_mul_ps(v75, v64);
  v84 = _mm_mul_ps(v64, v77);
  v85 = _mm_unpacklo_ps(v74, v83);
  v86 = _mm_unpackhi_ps(v74, v83);
  v87 = _mm_movelh_ps(v85, v84);
  v88 = _mm_mul_ps(v71, v151);
  v89 = _mm_mul_ps(v77, v151);
  v90 = _mm_mul_ps(v75, v151);
  v91 = _mm_unpacklo_ps(v88, v90);
  v92 = _mm_movelh_ps(v91, v89);
  v93.m_quad = (__m128)regA->m_invMasses;
  v94 = _mm_add_ps(v92, _mm_shuffle_ps(_mm_movehl_ps(v92, v91), v89, 212));
  v95 = _mm_sub_ps((__m128)0i64, (__m128)xmmword_141A711B0);
  v96 = _mm_mul_ps(_mm_add_ps(_mm_shuffle_ps(_mm_unpackhi_ps(v88, v90), v89, 228), v94), v95);
  v97 = _mm_mul_ps(_mm_add_ps(_mm_shuffle_ps(v79, v80, 228), _mm_add_ps(v81, _mm_shuffle_ps(v82, v80, 212))), v95);
  v98 = _mm_mul_ps(
          _mm_add_ps(_mm_shuffle_ps(v86, v84, 228), _mm_add_ps(v87, _mm_shuffle_ps(_mm_movehl_ps(v87, v85), v84, 212))),
          v95);
  v99.m_quad = (__m128)regB->m_invMasses;
  m_real = scale.m_real;
  v101 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v98, v97), v93.m_quad), _mm_mul_ps(_mm_mul_ps(v153, v149), v99.m_quad));
  v102 = _mm_add_ps(
           _mm_mul_ps(_mm_mul_ps(v96, v97), v93.m_quad),
           _mm_mul_ps(_mm_mul_ps(scale.m_real, v149), v99.m_quad));
  v103 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v98, v98), v93.m_quad), _mm_mul_ps(_mm_mul_ps(v153, v153), v99.m_quad));
  v104 = _mm_add_ps(
           _mm_mul_ps(_mm_mul_ps(v96, v98), v93.m_quad),
           _mm_mul_ps(_mm_mul_ps(scale.m_real, v153), v99.m_quad));
  v105 = _mm_add_ps(
           _mm_mul_ps(_mm_mul_ps(v96, v96), v93.m_quad),
           _mm_mul_ps(_mm_mul_ps(scale.m_real, scale.m_real), v99.m_quad));
  v106 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v97, v97), v93.m_quad), _mm_mul_ps(_mm_mul_ps(v149, v149), v99.m_quad));
  v107 = _mm_unpackhi_ps(v106, v101);
  v108 = _mm_unpacklo_ps(v106, v101);
  v109 = _mm_movelh_ps(v108, v102);
  v110 = _mm_movehl_ps(v109, v108);
  v111 = _mm_unpacklo_ps(v103, v104);
  v112 = _mm_movelh_ps(v111, v105);
  v156.m_col0.m_quad = _mm_add_ps(_mm_shuffle_ps(v107, v102, 228), _mm_add_ps(v109, _mm_shuffle_ps(v110, v102, 212)));
  v113.m_quad = _mm_add_ps(
                  _mm_shuffle_ps(_mm_unpackhi_ps(v103, v104), v105, 228),
                  _mm_add_ps(v112, _mm_shuffle_ps(_mm_movehl_ps(v112, v111), v105, 212)));
  v114.m_quad = _mm_unpacklo_ps(v113.m_quad, v113.m_quad);
  v114.m_quad.m128_f32[0] = _mm_shuffle_ps(v156.m_col0.m_quad, v156.m_col0.m_quad, 85).m128_f32[0];
  v156.m_col1 = (hkVector4f)v114.m_quad;
  v115 = _mm_shuffle_ps(v156.m_col0.m_quad, v156.m_col0.m_quad, 0);
  v113.m_quad.m128_f32[0] = _mm_shuffle_ps(v156.m_col0.m_quad, v156.m_col0.m_quad, 170).m128_f32[0];
  v156.m_col2 = (hkVector4f)v113.m_quad;
  scale.m_real = _mm_min_ps(
                   _mm_max_ps(_mm_andnot_ps(_mm_cmpeq_ps((__m128)0i64, v115), _mm_rcp_ps(v115)), query.m_quad),
                   (__m128)xmmword_141A712B0);
  hkMatrix3f::mul(&v156, &scale);
  v116 = _mm_shuffle_ps(v156.m_col1.m_quad, v156.m_col1.m_quad, 201);
  v117 = _mm_shuffle_ps(v156.m_col2.m_quad, v156.m_col2.m_quad, 201);
  v118 = _mm_sub_ps(_mm_mul_ps(v156.m_col1.m_quad, v117), _mm_mul_ps(v156.m_col2.m_quad, v116));
  v119 = _mm_shuffle_ps(v156.m_col0.m_quad, v156.m_col0.m_quad, 201);
  v120 = _mm_shuffle_ps(v118, v118, 201);
  v121 = _mm_mul_ps(v156.m_col0.m_quad, v120);
  v122 = _mm_sub_ps(_mm_mul_ps(v156.m_col2.m_quad, v119), _mm_mul_ps(v156.m_col0.m_quad, v117));
  v123 = _mm_sub_ps(_mm_mul_ps(v156.m_col0.m_quad, v116), _mm_mul_ps(v156.m_col1.m_quad, v119));
  v124 = _mm_add_ps(
           _mm_add_ps(_mm_shuffle_ps(v121, v121, 85), _mm_shuffle_ps(v121, v121, 0)),
           _mm_shuffle_ps(v121, v121, 170));
  v125 = _mm_rcp_ps(v124);
  v126 = _mm_and_ps(
           _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v125, v124)), v125),
           _mm_cmplt_ps(*(__m128 *)&epsilon, v124));
  v127 = _mm_mul_ps(v126, _mm_shuffle_ps(v123, v123, 201));
  v128 = _mm_max_ps(maxImpulse->m_real, *(__m128 *)&epsilon);
  v129 = _mm_mul_ps(
           _mm_add_ps(
             _mm_add_ps(
               _mm_mul_ps(_mm_shuffle_ps(v155, v155, 85), _mm_mul_ps(v126, _mm_shuffle_ps(v122, v122, 201))),
               _mm_mul_ps(_mm_shuffle_ps(v155, v155, 0), _mm_mul_ps(v126, v120))),
             _mm_mul_ps(_mm_shuffle_ps(v155, v155, 170), v127)),
           scale.m_real);
  v130 = _mm_mul_ps(v129, v129);
  v131 = _mm_add_ps(
           _mm_add_ps(_mm_shuffle_ps(v130, v130, 85), _mm_shuffle_ps(v130, v130, 0)),
           _mm_shuffle_ps(v130, v130, 170));
  v132 = _mm_rsqrt_ps(v131);
  v133 = _mm_andnot_ps(
           _mm_cmple_ps(v131, (__m128)0i64),
           _mm_mul_ps(
             _mm_mul_ps(
               _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v132, v131), v132)),
               _mm_mul_ps(*(__m128 *)_xmm, v132)),
             v131));
  v134 = _mm_rcp_ps(v133);
  v135 = _mm_mul_ps(v134, v133);
  v136 = _mm_cmple_ps(v133, v128);
  v137 = _mm_or_ps(
           _mm_andnot_ps(v136, _mm_mul_ps(_mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, v135), v134), v128), v129)),
           _mm_and_ps(v129, v136));
  v138 = _mm_shuffle_ps(v137, v137, 0);
  v139 = _mm_shuffle_ps(v137, v137, 170);
  v140 = _mm_shuffle_ps(v137, v137, 85);
  v141 = _mm_mul_ps(v97, v138);
  v142 = _mm_mul_ps(v149, v138);
  v143 = _mm_mul_ps(v96, v139);
  v144 = _mm_mul_ps(m_real, v139);
  v145.m_quad = (__m128)regB->m_invMasses;
  v146 = _mm_add_ps(
           _mm_movelh_ps(
             (__m128)*(unsigned __int64 *)&temps->m_impulseApplied,
             (__m128)LODWORD(temps[2].m_impulseApplied)),
           v137);
  *(_QWORD *)&temps->m_impulseApplied = v146.m128_u64[0];
  LODWORD(temps[2].m_impulseApplied) = _mm_movehl_ps(v146, v146).m128_u32[0];
  v147.m_quad = _mm_add_ps(
                  _mm_mul_ps(v145.m_quad, _mm_add_ps(_mm_add_ps(v142, _mm_mul_ps(v153, v140)), v144)),
                  regB->m_angularVel.m_quad);
  regA->m_angularVel.m_quad = _mm_add_ps(
                                _mm_mul_ps(
                                  _mm_add_ps(_mm_add_ps(v141, _mm_mul_ps(v98, v140)), v143),
                                  regA->m_invMasses.m_quad),
                                regA->m_angularVel.m_quad);
  regB->m_angularVel = (hkVector4f)v147.m_quad;
}

// File Line: 743
// RVA: 0xDE4B40
void __fastcall hkpAtomSolverFunctions::solveStableAngularConstraint3d<hkpVelocityAccumulator,hkpSolverInfo,hkSolverStepTemp>(
        hkpSolverInfo *solverInfo,
        hkSolverStepTemp *temp,
        hkpStableAngularSchema3d *schema,
        hkpVelocityAccumulator *mA,
        hkpVelocityAccumulator *mB,
        hkpSolverElemTemp *temps)
{
  hkVector4f v8; // xmm2
  hkQuaternionf qB; // [rsp+50h] [rbp-68h] BYREF
  hkQuaternionf qA; // [rsp+60h] [rbp-58h] BYREF
  hkQTransformf maxImpulse; // [rsp+70h] [rbp-48h] BYREF
  hkQTransformf erp; // [rsp+90h] [rbp-28h] BYREF

  hkpAtomSolverFunctions::getFuturePositions<hkpVelocityAccumulator,hkpSolverInfo>(
    solverInfo,
    mA,
    &mA->m_scratch3,
    (hkQuaternionf *)&mA->m_scratch2,
    mB,
    &mB->m_scratch3,
    (hkQuaternionf *)&mB->m_scratch2,
    &erp,
    &maxImpulse);
  v8.m_quad = (__m128)schema->m_data;
  qA.m_vec.m_quad = (__m128)erp.m_rotation;
  qB.m_vec.m_quad = (__m128)maxImpulse.m_rotation;
  erp.m_rotation.m_vec.m_quad = _mm_shuffle_ps(v8.m_quad, v8.m_quad, 85);
  maxImpulse.m_rotation.m_vec.m_quad = _mm_shuffle_ps(v8.m_quad, v8.m_quad, 170);
  hkpAtomSolverFunctions::solveQuatAngular3D<hkpVelocityAccumulator>(
    (hkSimdFloat32 *)&erp,
    (hkSimdFloat32 *)&maxImpulse,
    &schema->m_pivotA,
    &schema->m_pivotB,
    &qA,
    &qB,
    mA,
    mB,
    temps);
}

// File Line: 765
// RVA: 0xDE3580
void __fastcall hkpAtomSolverFunctions::solveDeformableLinConstraint<hkpVelocityAccumulator>(
        hkQTransformf *coreToWorldA,
        hkQTransformf *coreToWorldB,
        hkpDeformableLinSchema *schema,
        hkpVelocityAccumulator *mA,
        hkpVelocityAccumulator *mB,
        hkpSolverElemTemp *temps)
{
  __m128 m_quad; // xmm4
  hkVector4f v7; // xmm2
  __m128 v12; // xmm7
  __m128 v13; // xmm1
  __m128 v14; // xmm14
  __m128 v15; // xmm3
  __m128 v16; // xmm13
  __m128 v17; // xmm0
  hkVector4f v18; // xmm2
  __m128 v19; // xmm6
  __m128 v20; // xmm1
  __m128 v21; // xmm6
  __m128 v22; // xmm3
  hkVector4f *p_m_invMasses; // r12
  __m128 v24; // xmm8
  __m128 v25; // xmm8
  hkVector4f *v26; // r15
  hkVector4f v27; // xmm11
  hkVector4f v28; // xmm12
  hkVector4f v29; // xmm5
  __m128 v30; // xmm1
  __m128 v31; // xmm3
  __m128 v32; // xmm2
  __m128 v33; // xmm0
  __m128 v34; // xmm4
  __m128 v35; // xmm9
  __m128 v36; // xmm4
  __m128 v37; // xmm1
  __m128 v38; // xmm7
  __m128i v39; // xmm6
  __m128 v40; // xmm1
  __m128 v41; // xmm6
  __m128i v42; // xmm7
  hkVector4f v43; // xmm10
  __m128 v44; // xmm2
  __m128 v45; // xmm1
  __m128 v46; // xmm3
  __m128 v47; // xmm1
  __m128 v48; // xmm4
  __m128 v49; // xmm2
  __m128 v50; // xmm5
  __m128 v51; // xmm1
  __m128 v52; // xmm5
  __m128 v53; // xmm2
  __m128 v54; // xmm3
  __m128 v55; // xmm11
  __m128 v56; // xmm2
  __m128 v57; // xmm2
  __m128 v58; // xmm8
  __m128 v59; // xmm4
  __m128 v60; // xmm2
  __m128 v61; // xmm0
  __m128 v62; // xmm1
  __m128 v63; // xmm3
  __m128 v64; // xmm5
  __m128 v65; // xmm7
  __m128 v66; // xmm3
  __m128 v67; // xmm0
  __m128 v68; // xmm6
  __m128 v69; // xmm5
  __m128i v70; // xmm5
  __m128 v71; // xmm1
  __m128 v72; // xmm1
  __m128 v73; // xmm4
  __m128 v74; // xmm0
  __m128 v75; // xmm8
  __m128 v76; // xmm1
  __m128 v77; // xmm8
  int v78; // eax
  __m128 v79; // xmm3
  __m128 v80; // xmm12
  __m128 v81; // xmm0
  __m128 v82; // xmm5
  __m128 v83; // xmm3
  __m128 v84; // xmm4
  __m128 v85; // xmm2
  __m128 v86; // xmm1
  __m128 v87; // xmm0
  hkVector4f v88; // xmm0
  hkVector4f v89; // xmm0
  __m128 v90; // xmm1
  hkVector4f v91; // xmm0
  hkQuaternionf rotA; // [rsp+50h] [rbp-1B8h] BYREF
  hkQuaternionf rotB; // [rsp+60h] [rbp-1A8h] BYREF
  __m128 v94; // [rsp+70h] [rbp-198h]
  __m128 v95; // [rsp+80h] [rbp-188h]
  __m128 v96; // [rsp+90h] [rbp-178h]
  __m128 v97; // [rsp+A0h] [rbp-168h]
  hkVector4f vWorldArmA; // [rsp+B0h] [rbp-158h] BYREF
  hkVector4f vWorldArmB; // [rsp+C0h] [rbp-148h] BYREF
  hkSymmetricMatrix3Impl<float> outK; // [rsp+D0h] [rbp-138h] BYREF
  hkMatrix3f UA; // [rsp+F0h] [rbp-118h] BYREF
  hkMatrix3f UB; // [rsp+120h] [rbp-E8h] BYREF

  m_quad = coreToWorldA->m_rotation.m_vec.m_quad;
  v7.m_quad = (__m128)schema->m_pivotA;
  v12 = coreToWorldB->m_rotation.m_vec.m_quad;
  v13 = _mm_mul_ps(v7.m_quad, coreToWorldA->m_rotation.m_vec.m_quad);
  v14 = _mm_shuffle_ps(m_quad, m_quad, 201);
  v97 = coreToWorldA->m_rotation.m_vec.m_quad;
  v95 = v12;
  v15 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v7.m_quad, v7.m_quad, 201), m_quad), _mm_mul_ps(v14, v7.m_quad));
  rotA.m_vec.m_quad = m_quad;
  rotB.m_vec.m_quad = v12;
  v94 = _mm_shuffle_ps(v97, m_quad, 255);
  v16 = _mm_shuffle_ps(v12, v12, 201);
  v96 = _mm_shuffle_ps(v12, v12, 255);
  v17 = _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v94, v94), (__m128)xmmword_141A711B0), v7.m_quad);
  v18.m_quad = (__m128)schema->m_pivotB;
  v19 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)),
                _mm_shuffle_ps(v13, v13, 170)),
              m_quad),
            v17),
          _mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), v94));
  v20 = _mm_mul_ps(v18.m_quad, v12);
  v21 = _mm_add_ps(v19, v19);
  vWorldArmA.m_quad = v21;
  v22 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v18.m_quad, v18.m_quad, 201), v12), _mm_mul_ps(v16, v18.m_quad));
  p_m_invMasses = &mA->m_invMasses;
  v24 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)),
                _mm_shuffle_ps(v20, v20, 170)),
              v12),
            _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v96, v96), (__m128)xmmword_141A711B0), v18.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v22, v22, 201), v96));
  v25 = _mm_add_ps(v24, v24);
  v26 = &mB->m_invMasses;
  vWorldArmB.m_quad = v25;
  hkpAtomSolverFunctions::computeInverseVirtualMass3D(
    &rotA,
    &rotB,
    &vWorldArmA,
    &vWorldArmB,
    &mA->m_invMasses,
    &mB->m_invMasses,
    &outK,
    &UA,
    &UB);
  v27.m_quad = (__m128)schema->m_offsetA;
  v28.m_quad = (__m128)schema->m_ultimateStrengthOffDiag;
  v29.m_quad = (__m128)schema->m_ultimateStrengthDiag;
  rotA.m_vec.m_quad = _mm_sub_ps(
                        _mm_add_ps(_mm_sub_ps(v25, v21), coreToWorldB->m_translation.m_quad),
                        coreToWorldA->m_translation.m_quad);
  v30 = _mm_mul_ps(rotA.m_vec.m_quad, rotA.m_vec.m_quad);
  v31 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v30, v30, 85), _mm_shuffle_ps(v30, v30, 0)), _mm_shuffle_ps(v30, v30, 170));
  v32 = _mm_rsqrt_ps(v31);
  v33 = _mm_cmplt_ps((__m128)xmmword_141A712D0, v31);
  v34 = _mm_andnot_ps(
          _mm_cmple_ps(v31, (__m128)0i64),
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v32, v31), v32)), _mm_mul_ps(*(__m128 *)_xmm, v32)));
  v35 = _mm_mul_ps(v34, v31);
  v36 = _mm_or_ps(_mm_and_ps(_mm_mul_ps(v34, rotA.m_vec.m_quad), v33), _mm_andnot_ps(v33, transform.m_quad));
  v37 = _mm_mul_ps(schema->m_yieldStrengthOffDiag.m_quad, v36);
  v38 = _mm_shuffle_ps(v36, v36, 201);
  v39 = _mm_slli_epi32(
          (__m128i)_mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(v38, schema->m_yieldStrengthOffDiag.m_quad),
                       _mm_mul_ps(schema->m_yieldStrengthDiag.m_quad, v36)),
                     _mm_shuffle_ps(v37, v37, 210)),
          1u);
  v40 = _mm_mul_ps(v28.m_quad, v36);
  v41 = (__m128)_mm_srli_epi32(v39, 1u);
  v42 = (__m128i)_mm_add_ps(
                   _mm_add_ps(_mm_mul_ps(v38, v28.m_quad), _mm_mul_ps(v29.m_quad, v36)),
                   _mm_shuffle_ps(v40, v40, 210));
  v43.m_quad = (__m128)schema->m_offsetB;
  v44 = _mm_shuffle_ps(v43.m_quad, v43.m_quad, 255);
  v45 = _mm_rcp_ps(v44);
  v46 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v45, v44)), v45);
  v47 = _mm_mul_ps(v27.m_quad, v97);
  v48 = _mm_and_ps(
          _mm_max_ps(
            _mm_sub_ps(
              _mm_andnot_ps(_mm_cmpeq_ps((__m128)0i64, v44), _mm_mul_ps(v46, v35)),
              _mm_shuffle_ps(v29.m_quad, v29.m_quad, 255)),
            aabbOut.m_quad),
          _mm_cmplt_ps((__m128)0i64, _mm_sub_ps(v35, _mm_shuffle_ps(v27.m_quad, v27.m_quad, 255))));
  v49 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v27.m_quad, v27.m_quad, 201), v97), _mm_mul_ps(v27.m_quad, v14));
  rotB.m_vec.m_quad = _mm_add_ps(
                        _mm_mul_ps(v48, _mm_sub_ps((__m128)_mm_srli_epi32(_mm_slli_epi32(v42, 1u), 1u), v41)),
                        v41);
  v50 = _mm_mul_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v47, v47, 85), _mm_shuffle_ps(v47, v47, 0)),
            _mm_shuffle_ps(v47, v47, 170)),
          v97);
  v51 = _mm_mul_ps(v43.m_quad, v95);
  v52 = _mm_add_ps(
          _mm_add_ps(v50, _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v94, v94), (__m128)xmmword_141A711B0), v27.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v49, v49, 201), v94));
  v53 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v43.m_quad, v43.m_quad, 201), v95), _mm_mul_ps(v43.m_quad, v16));
  v54 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v51, v51, 85), _mm_shuffle_ps(v51, v51, 0)),
                _mm_shuffle_ps(v51, v51, 170)),
              v95),
            _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v96, v96), (__m128)xmmword_141A711B0), v43.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v53, v53, 201), v96));
  v55 = _mm_mul_ps(
          _mm_sub_ps(_mm_sub_ps(rotA.m_vec.m_quad, _mm_add_ps(v52, v52)), _mm_add_ps(v54, v54)),
          _mm_shuffle_ps(v28.m_quad, v28.m_quad, 255));
  v56 = _mm_max_ps(
          (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)outK.m_diag.m_quad, 1u), 1u),
          (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)outK.m_offDiag.m_quad, 1u), 1u));
  v57 = _mm_max_ps(_mm_shuffle_ps(v56, v56, 170), _mm_max_ps(_mm_shuffle_ps(v56, v56, 85), _mm_shuffle_ps(v56, v56, 0)));
  v58 = _mm_andnot_ps(_mm_cmpeq_ps(v57, (__m128)0i64), _mm_div_ps(query.m_quad, v57));
  v59 = _mm_mul_ps(outK.m_diag.m_quad, v58);
  v60 = _mm_mul_ps(outK.m_offDiag.m_quad, v58);
  v61 = _mm_shuffle_ps(v60, v60, 201);
  v62 = _mm_shuffle_ps(v59, v59, 210);
  v63 = _mm_mul_ps(v61, v61);
  v64 = _mm_mul_ps(_mm_shuffle_ps(v59, v59, 201), v62);
  v65 = _mm_sub_ps(v64, v63);
  v66 = _mm_mul_ps(v63, v59);
  v67 = _mm_mul_ps(_mm_shuffle_ps(v60, v60, 210), v61);
  v68 = _mm_sub_ps(v67, _mm_mul_ps(v62, v60));
  v69 = _mm_add_ps(_mm_mul_ps(v64, v59), _mm_mul_ps(_mm_mul_ps(v67, v60), (__m128)xmmword_141A710D0));
  v70 = (__m128i)_mm_sub_ps(
                   _mm_shuffle_ps(v69, v69, 0),
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v66, v66, 85), _mm_shuffle_ps(v66, v66, 0)),
                     _mm_shuffle_ps(v66, v66, 170)));
  v71 = _mm_rcp_ps((__m128)v70);
  v72 = _mm_mul_ps(
          _mm_and_ps(
            _mm_cmplt_ps(*(__m128 *)&epsilon, (__m128)_mm_srli_epi32(_mm_slli_epi32(v70, 1u), 1u)),
            _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v71, (__m128)v70)), v71)),
          v58);
  v73 = _mm_mul_ps(v72, v68);
  v74 = _mm_mul_ps(v73, v55);
  v75 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v55, v55, 201), v73), _mm_mul_ps(_mm_mul_ps(v72, v65), v55));
  v76 = _mm_rcp_ps(outK.m_diag.m_quad);
  v77 = _mm_add_ps(v75, _mm_shuffle_ps(v74, v74, 210));
  v78 = 3;
  v79 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64), rotB.m_vec.m_quad);
  v80 = _mm_andnot_ps(
          _mm_cmpeq_ps((__m128)0i64, outK.m_diag.m_quad),
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v76, outK.m_diag.m_quad)), v76));
  do
  {
    --v78;
    v81 = _mm_mul_ps(outK.m_offDiag.m_quad, v77);
    v77 = _mm_max_ps(
            _mm_min_ps(
              _mm_mul_ps(
                _mm_sub_ps(
                  v55,
                  _mm_add_ps(
                    _mm_shuffle_ps(v81, v81, 210),
                    _mm_mul_ps(_mm_shuffle_ps(v77, v77, 201), outK.m_offDiag.m_quad))),
                v80),
              rotB.m_vec.m_quad),
            v79);
  }
  while ( v78 >= 0 );
  v82 = _mm_shuffle_ps(v77, v77, 85);
  v83 = _mm_shuffle_ps(v77, v77, 0);
  v84 = _mm_shuffle_ps(v77, v77, 170);
  v85 = _mm_add_ps(
          _mm_movelh_ps(
            (__m128)*(unsigned __int64 *)&temps->m_impulseApplied,
            (__m128)LODWORD(temps[2].m_impulseApplied)),
          v77);
  v86 = _mm_mul_ps(
          v26->m_quad,
          _mm_mul_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(UB.m_col0.m_quad, v83), _mm_mul_ps(UB.m_col1.m_quad, v82)),
              _mm_mul_ps(UB.m_col2.m_quad, v84)),
            _mm_shuffle_ps(schema->m_pivotB.m_quad, schema->m_pivotB.m_quad, 255)));
  v87 = _mm_mul_ps(
          p_m_invMasses->m_quad,
          _mm_mul_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(UA.m_col0.m_quad, v83), _mm_mul_ps(UA.m_col1.m_quad, v82)),
              _mm_mul_ps(UA.m_col2.m_quad, v84)),
            _mm_shuffle_ps(schema->m_pivotA.m_quad, schema->m_pivotA.m_quad, 255)));
  *(_QWORD *)&temps->m_impulseApplied = v85.m128_u64[0];
  mA->m_angularVel.m_quad = _mm_add_ps(v87, mA->m_angularVel.m_quad);
  v88.m_quad = (__m128)mB->m_angularVel;
  LODWORD(temps[2].m_impulseApplied) = _mm_movehl_ps(v85, v85).m128_u32[0];
  v89.m_quad = _mm_sub_ps(v88.m_quad, v86);
  v90 = p_m_invMasses->m_quad;
  mB->m_angularVel = (hkVector4f)v89.m_quad;
  v91.m_quad = (__m128)mB->m_linearVel;
  mA->m_linearVel.m_quad = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v90, v90, 255), v77), mA->m_linearVel.m_quad);
  mB->m_linearVel.m_quad = _mm_sub_ps(v91.m_quad, _mm_mul_ps(_mm_shuffle_ps(v26->m_quad, v26->m_quad, 255), v77));
}

// File Line: 822
// RVA: 0xDE2920
void __fastcall hkpAtomSolverFunctions::solveDeformableAngConstraint<hkpVelocityAccumulator>(
        hkQTransformf *coreToWorldA,
        hkQTransformf *coreToWorldB,
        hkpDeformableAngSchema *schema,
        hkpVelocityAccumulator *mA,
        hkpVelocityAccumulator *mB,
        hkpSolverElemTemp *temps)
{
  hkQuaternionf v6; // xmm3
  __m128 v7; // xmm4
  __m128 v8; // xmm6
  __m128 v9; // xmm0
  __m128 v10; // xmm3
  __m128 v11; // xmm6
  __m128 v12; // xmm2
  hkQuaternionf v13; // xmm3
  __m128 v14; // xmm14
  __m128 v15; // xmm6
  __m128 v16; // xmm4
  __m128 v17; // xmm5
  __m128 v18; // xmm0
  __m128 v19; // xmm3
  __m128 v20; // xmm5
  __m128 v21; // xmm5
  hkVector4f v22; // xmm12
  hkVector4f v23; // xmm3
  __m128 v24; // xmm8
  __m128 v25; // xmm13
  __m128 v26; // xmm1
  __m128 v27; // xmm0
  __m128 v28; // xmm5
  __m128 v29; // xmm13
  __m128 v30; // xmm0
  __m128 v31; // xmm13
  __m128 v32; // xmm1
  __m128 v33; // xmm11
  __m128 v34; // xmm1
  __m128 v35; // xmm0
  hkVector4f v36; // xmm2
  __m128 v37; // xmm9
  __m128 v38; // xmm1
  __m128 v39; // xmm7
  __m128 v40; // xmm4
  __m128 v41; // xmm6
  __m128 v42; // xmm0
  __m128 v43; // xmm7
  __m128 v44; // xmm1
  hkQuaternionf v45; // xmm2
  __m128 v46; // xmm3
  __m128 v47; // xmm5
  __m128 v48; // xmm1
  __m128 v49; // xmm4
  __m128 v50; // xmm3
  __m128 v51; // xmm13
  __m128 v52; // xmm4
  hkQuaternionf v53; // xmm2
  __m128 v54; // xmm4
  __m128 v55; // xmm15
  __m128 v56; // xmm1
  __m128 v57; // xmm3
  __m128 v58; // xmm0
  __m128 v59; // xmm4
  __m128 v60; // xmm3
  __m128 v61; // xmm0
  hkQuaternionf v62; // xmm2
  __m128 v63; // xmm3
  __m128 v64; // xmm11
  __m128 v65; // xmm13
  hkQuaternionf v66; // xmm3
  __m128 v67; // xmm1
  __m128 v68; // xmm4
  __m128 v69; // xmm0
  __m128 v70; // xmm3
  __m128 v71; // xmm4
  __m128 v72; // xmm4
  __m128 v73; // xmm10
  __m128 m_quad; // xmm2
  __m128 v75; // xmm1
  __m128 v76; // xmm3
  __m128 v77; // xmm3
  __m128 v78; // xmm10
  __m128 v79; // xmm1
  __m128 v80; // xmm10
  __m128 v81; // xmm10
  __m128 v82; // xmm0
  __m128 v83; // xmm9
  __m128 v84; // xmm2
  __m128 v85; // xmm1
  __m128 v86; // xmm3
  __m128 v87; // xmm1
  __m128 v88; // xmm8
  __m128 v89; // xmm0
  __m128 v90; // xmm10
  __m128 v91; // xmm7
  __m128 v92; // xmm6
  __m128 v93; // xmm1
  __m128 v94; // xmm3
  __m128 v95; // xmm1
  __m128 v96; // xmm2
  __m128 v97; // xmm0
  __m128 v98; // xmm5
  __m128 v99; // xmm9
  __m128 v100; // xmm4
  __m128 v101; // xmm2
  __m128 v102; // xmm3
  __m128 v103; // xmm0
  hkQuaternionf v104; // xmm2
  hkQuaternionf v105; // xmm3
  __m128 v106; // xmm5
  __m128 v107; // xmm1
  __m128 v108; // xmm11
  __m128 v109; // xmm0
  __m128 v110; // xmm4
  __m128 v111; // xmm3
  __m128 v112; // xmm4
  __m128 v113; // xmm4
  __m128 v114; // xmm10
  __m128 v115; // xmm2
  __m128 v116; // xmm1
  __m128 v117; // xmm3
  __m128 v118; // xmm3
  __m128 v119; // xmm10
  __m128 v120; // xmm15
  __m128 v121; // xmm10
  __m128 v122; // xmm12
  __m128 v123; // xmm10
  __m128 v124; // xmm0
  __m128 v125; // xmm9
  __m128 v126; // xmm8
  __m128 v127; // xmm1
  __m128 v128; // xmm7
  __m128 v129; // xmm14
  __m128 v130; // xmm12
  __m128 v131; // xmm0
  __m128 v132; // xmm5
  __m128 v133; // xmm1
  __m128 v134; // xmm14
  __m128 v135; // xmm4
  __m128 v136; // xmm15
  __m128 v137; // xmm9
  __m128 v138; // xmm10
  __m128 v139; // xmm0
  __m128 v140; // xmm2
  __m128 v141; // xmm4
  __m128 v142; // xmm1
  __m128 v143; // xmm0
  __m128 v144; // xmm12
  __m128 v145; // xmm14
  __m128 v146; // xmm15
  hkVector4f v147; // xmm0
  __m128 v148; // xmm4
  __m128 v149; // xmm5
  __m128 v150; // xmm6
  __m128 v151; // xmm1
  __m128 v152; // xmm0
  __m128 v153; // xmm2
  __m128 v154; // xmm3
  __m128 v155; // xmm1
  __m128 v156; // xmm3
  __m128 v157; // xmm8
  __m128 v158; // xmm8
  __m128 v159; // xmm2
  __m128 v160; // xmm8
  __m128 v161; // xmm0
  __m128 v162; // xmm1
  __m128 v163; // xmm3
  __m128 v164; // xmm1
  __m128 v165; // xmm7
  __m128 v166; // xmm7
  hkVector4f v167; // xmm0
  __m128 v168; // xmm4
  __m128 v169; // xmm5
  __m128 v170; // xmm6
  __m128 v171; // xmm3
  __m128 v172; // xmm0
  __m128 v173; // xmm2
  __m128 v174; // xmm1
  __m128 v175; // xmm3
  __m128 v176; // xmm9
  __m128 v177; // xmm9
  __m128 v178; // xmm2
  __m128 v179; // xmm0
  __m128i v180; // xmm9
  __m128 v181; // xmm1
  __m128 v182; // xmm3
  __m128 v183; // xmm1
  __m128 v184; // xmm10
  __m128i v185; // xmm10
  __m128 v186; // xmm2
  __m128 v187; // xmm2
  __m128 v188; // xmm8
  __m128 v189; // xmm4
  __m128 v190; // xmm2
  __m128 v191; // xmm1
  __m128 v192; // xmm0
  __m128 v193; // xmm7
  __m128 v194; // xmm5
  int v195; // eax
  __m128 v196; // xmm3
  __m128 v197; // xmm7
  __m128 v198; // xmm3
  __m128 v199; // xmm0
  __m128 v200; // xmm6
  __m128 v201; // xmm5
  __m128i v202; // xmm5
  __m128 v203; // xmm1
  __m128 v204; // xmm13
  __m128 v205; // xmm1
  __m128 v206; // xmm4
  __m128 v207; // xmm0
  __m128 v208; // xmm6
  __m128 v209; // xmm1
  __m128 v210; // xmm6
  __m128 v211; // xmm11
  __m128 v212; // xmm0
  __m128 v213; // xmm4
  __m128 v214; // xmm0
  __m128 v215; // xmm1
  __m128 v216; // xmm5
  __m128 v217; // xmm4
  __m128 m_impulseApplied_low; // xmm0
  __m128 v219; // xmm4
  __m128 v220; // xmm1
  hkVector4f v221; // xmm4
  __m128 v222; // [rsp+0h] [rbp-128h]
  __m128 v223; // [rsp+0h] [rbp-128h]
  __m128 v224; // [rsp+10h] [rbp-118h]
  __m128 v225; // [rsp+20h] [rbp-108h]
  __m128 v226; // [rsp+20h] [rbp-108h]
  __m128 v227; // [rsp+30h] [rbp-F8h]
  __m128 v228; // [rsp+30h] [rbp-F8h]
  __m128 v229; // [rsp+40h] [rbp-E8h]
  __m128 v230; // [rsp+50h] [rbp-D8h]
  __m128 v231; // [rsp+60h] [rbp-C8h]
  __m128 v232; // [rsp+70h] [rbp-B8h]

  v6.m_vec.m_quad = (__m128)schema->m_coreFromPivotA;
  v7 = _mm_shuffle_ps(coreToWorldA->m_rotation.m_vec.m_quad, coreToWorldA->m_rotation.m_vec.m_quad, 255);
  v229 = _mm_shuffle_ps(v6.m_vec.m_quad, v6.m_vec.m_quad, 255);
  v8 = _mm_sub_ps(
         _mm_mul_ps(_mm_shuffle_ps(v6.m_vec.m_quad, v6.m_vec.m_quad, 201), coreToWorldA->m_rotation.m_vec.m_quad),
         _mm_mul_ps(
           _mm_shuffle_ps(coreToWorldA->m_rotation.m_vec.m_quad, coreToWorldA->m_rotation.m_vec.m_quad, 201),
           v6.m_vec.m_quad));
  v9 = _mm_mul_ps(v6.m_vec.m_quad, v7);
  v10 = _mm_mul_ps(v6.m_vec.m_quad, coreToWorldA->m_rotation.m_vec.m_quad);
  v11 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 201), v9), _mm_mul_ps(coreToWorldA->m_rotation.m_vec.m_quad, v229));
  v12 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)), _mm_shuffle_ps(v10, v10, 170));
  v13.m_vec.m_quad = (__m128)schema->m_coreFromPivotB;
  v14 = _mm_shuffle_ps(v13.m_vec.m_quad, v13.m_vec.m_quad, 255);
  v15 = _mm_shuffle_ps(v11, _mm_unpackhi_ps(v11, _mm_sub_ps(_mm_mul_ps(v229, v7), v12)), 196);
  v16 = _mm_shuffle_ps(coreToWorldB->m_rotation.m_vec.m_quad, coreToWorldB->m_rotation.m_vec.m_quad, 255);
  v17 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v13.m_vec.m_quad, v13.m_vec.m_quad, 201), coreToWorldB->m_rotation.m_vec.m_quad),
          _mm_mul_ps(
            _mm_shuffle_ps(coreToWorldB->m_rotation.m_vec.m_quad, coreToWorldB->m_rotation.m_vec.m_quad, 201),
            v13.m_vec.m_quad));
  v18 = _mm_mul_ps(v16, v13.m_vec.m_quad);
  v19 = _mm_mul_ps(v13.m_vec.m_quad, coreToWorldB->m_rotation.m_vec.m_quad);
  v20 = _mm_add_ps(
          _mm_add_ps(_mm_shuffle_ps(v17, v17, 201), v18),
          _mm_mul_ps(v14, coreToWorldB->m_rotation.m_vec.m_quad));
  v21 = _mm_shuffle_ps(
          v20,
          _mm_unpackhi_ps(
            v20,
            _mm_sub_ps(
              _mm_mul_ps(v14, v16),
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)),
                _mm_shuffle_ps(v19, v19, 170)))),
          196);
  v22.m_quad = (__m128)schema->m_yieldStrengthOffDiag;
  v23.m_quad = (__m128)schema->m_ultimateStrengthDiag;
  v24 = _mm_shuffle_ps(v23.m_quad, v23.m_quad, 255);
  v25 = _mm_mul_ps(_mm_shuffle_ps(v15, v15, 255), v21);
  v26 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), v21), _mm_mul_ps(_mm_shuffle_ps(v21, v21, 201), v15));
  v27 = _mm_shuffle_ps(v21, v21, 255);
  v28 = _mm_mul_ps(v21, v15);
  v29 = _mm_sub_ps(_mm_add_ps(v25, _mm_shuffle_ps(v26, v26, 201)), _mm_mul_ps(v27, v15));
  v30 = _mm_add_ps(_mm_shuffle_ps(v28, v28, 78), v28);
  v31 = _mm_shuffle_ps(v29, _mm_unpackhi_ps(v29, _mm_add_ps(_mm_shuffle_ps(v30, v30, 177), v30)), 196);
  v32 = _mm_mul_ps(v31, v31);
  v33 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v32, v32, 85), _mm_shuffle_ps(v32, v32, 0)), _mm_shuffle_ps(v32, v32, 170));
  v34 = _mm_rsqrt_ps(v33);
  v35 = _mm_cmplt_ps((__m128)xmmword_141A712D0, v33);
  v36.m_quad = (__m128)schema->m_ultimateStrengthOffDiag;
  v37 = _mm_or_ps(
          _mm_and_ps(
            _mm_mul_ps(
              _mm_andnot_ps(
                _mm_cmple_ps(v33, (__m128)0i64),
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v34, v33), v34)),
                  _mm_mul_ps(*(__m128 *)_xmm, v34))),
              v31),
            v35),
          _mm_andnot_ps(v35, transform.m_quad));
  v38 = _mm_mul_ps(v22.m_quad, v37);
  v39 = _mm_shuffle_ps(v37, v37, 201);
  v40 = _mm_mul_ps(_mm_sub_ps(query.m_quad, _mm_shuffle_ps(v36.m_quad, v36.m_quad, 255)), (__m128)xmmword_141A711B0);
  v41 = (__m128)_mm_srli_epi32(
                  _mm_slli_epi32(
                    (__m128i)_mm_add_ps(
                               _mm_add_ps(
                                 _mm_mul_ps(v39, v22.m_quad),
                                 _mm_mul_ps(schema->m_yieldStrengthDiag.m_quad, v37)),
                               _mm_shuffle_ps(v38, v38, 210)),
                    1u),
                  1u);
  v42 = _mm_mul_ps(v36.m_quad, v37);
  v43 = _mm_add_ps(_mm_mul_ps(v39, v36.m_quad), _mm_mul_ps(v23.m_quad, v37));
  v44 = _mm_rcp_ps(v40);
  v45.m_vec.m_quad = (__m128)schema->m_pivotFromOffsetB;
  v46 = _mm_max_ps(
          _mm_sub_ps(
            _mm_andnot_ps(
              _mm_cmpeq_ps(v40, (__m128)0i64),
              _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v44, v40)), v44), v33)),
            _mm_shuffle_ps(schema->m_yieldStrengthDiag.m_quad, schema->m_yieldStrengthDiag.m_quad, 255)),
          aabbOut.m_quad);
  v47 = _mm_shuffle_ps(v45.m_vec.m_quad, v45.m_vec.m_quad, 255);
  v48 = _mm_mul_ps(v47, v31);
  v49 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v45.m_vec.m_quad, v45.m_vec.m_quad, 201), v31),
          _mm_mul_ps(_mm_shuffle_ps(v31, v31, 201), v45.m_vec.m_quad));
  v232 = _mm_add_ps(
           _mm_mul_ps(
             _mm_and_ps(v46, _mm_cmplt_ps(_mm_sub_ps(query.m_quad, _mm_add_ps(v33, v33)), v24)),
             _mm_sub_ps(
               (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_add_ps(v43, _mm_shuffle_ps(v42, v42, 210)), 1u), 1u),
               v41)),
           v41);
  v50 = _mm_shuffle_ps(v31, v31, 255);
  v51 = _mm_mul_ps(v31, v45.m_vec.m_quad);
  v52 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v49, v49, 201), _mm_mul_ps(v50, v45.m_vec.m_quad)), v48);
  v53.m_vec.m_quad = (__m128)schema->m_pivotFromOffsetA;
  v54 = _mm_shuffle_ps(
          v52,
          _mm_unpackhi_ps(
            v52,
            _mm_sub_ps(
              _mm_mul_ps(v47, v50),
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v51, v51, 85), _mm_shuffle_ps(v51, v51, 0)),
                _mm_shuffle_ps(v51, v51, 170)))),
          196);
  v55 = _mm_shuffle_ps(v53.m_vec.m_quad, v53.m_vec.m_quad, 255);
  v56 = _mm_mul_ps(_mm_shuffle_ps(v54, v54, 255), v53.m_vec.m_quad);
  v57 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v53.m_vec.m_quad, v53.m_vec.m_quad, 201), v54),
          _mm_mul_ps(_mm_shuffle_ps(v54, v54, 201), v53.m_vec.m_quad));
  v58 = _mm_mul_ps(v55, v54);
  v59 = _mm_mul_ps(v54, v53.m_vec.m_quad);
  v60 = _mm_sub_ps(_mm_add_ps(_mm_shuffle_ps(v57, v57, 201), v58), v56);
  v61 = _mm_add_ps(_mm_shuffle_ps(v59, v59, 78), v59);
  v62.m_vec.m_quad = (__m128)schema->m_pivotFromOffsetB;
  v63 = _mm_shuffle_ps(v60, _mm_unpackhi_ps(v60, _mm_add_ps(_mm_shuffle_ps(v61, v61, 177), v61)), 196);
  v231 = _mm_mul_ps(_mm_sub_ps((__m128)0i64, _mm_shuffle_ps(v22.m_quad, v22.m_quad, 255)), v63);
  v225 = _mm_xor_ps(
           (__m128)_mm_slli_epi32(_mm_srli_epi32((__m128i)xmmword_141A9E9C0, 0x1Fu), 0x1Fu),
           _mm_shuffle_ps(v63, v63, 27));
  v64 = _mm_xor_ps(
          (__m128)_mm_slli_epi32(_mm_srli_epi32((__m128i)xmmword_141A9E9E0, 0x1Fu), 0x1Fu),
          _mm_shuffle_ps(v63, v63, 78));
  v65 = _mm_xor_ps(
          (__m128)_mm_slli_epi32(_mm_srli_epi32((__m128i)xmmword_141A9E9B0, 0x1Fu), 0x1Fu),
          _mm_shuffle_ps(v63, v63, 177));
  v66.m_vec.m_quad = (__m128)schema->m_coreFromPivotB;
  v67 = _mm_mul_ps(v47, v66.m_vec.m_quad);
  v68 = _mm_mul_ps(_mm_shuffle_ps(v62.m_vec.m_quad, v62.m_vec.m_quad, 201), v66.m_vec.m_quad);
  v69 = _mm_mul_ps(_mm_shuffle_ps(v66.m_vec.m_quad, v66.m_vec.m_quad, 201), v62.m_vec.m_quad);
  v70 = _mm_mul_ps(v66.m_vec.m_quad, v62.m_vec.m_quad);
  v71 = _mm_sub_ps(v68, v69);
  v72 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v71, v71, 201), _mm_mul_ps(v14, v62.m_vec.m_quad)), v67);
  v230 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64);
  v73 = _mm_xor_ps(
          v230,
          _mm_shuffle_ps(
            v72,
            _mm_unpackhi_ps(
              v72,
              _mm_sub_ps(
                _mm_mul_ps(v47, v14),
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v70, v70, 85), _mm_shuffle_ps(v70, v70, 0)),
                  _mm_shuffle_ps(v70, v70, 170)))),
            196));
  m_quad = transform.m_quad;
  v75 = _mm_add_ps(v73, v73);
  v76 = _mm_mul_ps(_mm_shuffle_ps(v75, v75, 165), _mm_shuffle_ps(v73, v73, 65));
  v69.m128_f32[0] = v73.m128_f32[0] * v75.m128_f32[0];
  m_quad.m128_f32[0] = (float)(1.0 - (float)(v73.m128_f32[0] * v75.m128_f32[0])) - v76.m128_f32[0];
  v77 = _mm_xor_ps(v76, (__m128)`hkVector4UtilImpl<float>::convertQuaternionToRotation::`2::negateMask0);
  v78 = _mm_xor_ps(
          _mm_mul_ps(_mm_shuffle_ps(v73, v73, 254), _mm_shuffle_ps(v75, v75, 26)),
          (__m128)`hkVector4UtilImpl<float>::convertQuaternionToRotation::`2::negateMask1);
  v78.m128_f32[0] = v78.m128_f32[0] + 1.0;
  v79 = _mm_sub_ps(v78, v77);
  v77.m128_f32[0] = v69.m128_f32[0];
  v80 = _mm_sub_ps(
          _mm_xor_ps(v78, (__m128)`hkVector4UtilImpl<float>::convertQuaternionToRotation::`2::negateMask0),
          v77);
  v81 = _mm_shuffle_ps(v80, v80, 177);
  v82 = _mm_mul_ps(v81, v225);
  v83 = _mm_shuffle_ps(_mm_movehl_ps(v79, v81), m_quad, 141);
  v84 = v79;
  v85 = _mm_mul_ps(v79, v225);
  v86 = _mm_unpackhi_ps(v85, v82);
  v87 = _mm_unpacklo_ps(v85, v82);
  v88 = _mm_mul_ps(v83, v225);
  v227 = v86;
  v89 = _mm_mul_ps(v81, v64);
  v90 = _mm_mul_ps(v81, v65);
  v91 = _mm_movelh_ps(v87, v88);
  v92 = _mm_movehl_ps(v91, v87);
  v93 = _mm_mul_ps(v84, v64);
  v94 = _mm_unpackhi_ps(v93, v89);
  v95 = _mm_unpacklo_ps(v93, v89);
  v96 = _mm_mul_ps(v84, v65);
  v97 = _mm_unpacklo_ps(v96, v90);
  v222 = _mm_unpackhi_ps(v96, v90);
  v98 = _mm_mul_ps(v83, v64);
  v99 = _mm_mul_ps(v83, v65);
  v100 = _mm_movelh_ps(v95, v98);
  v101 = _mm_movelh_ps(v97, v99);
  v228 = _mm_mul_ps(
           _mm_add_ps(_mm_shuffle_ps(v227, v88, 228), _mm_add_ps(v91, _mm_shuffle_ps(v92, v88, 212))),
           (__m128)xmmword_141A711B0);
  v224 = _mm_mul_ps(
           _mm_add_ps(
             _mm_shuffle_ps(v94, v98, 228),
             _mm_add_ps(v100, _mm_shuffle_ps(_mm_movehl_ps(v100, v95), v98, 212))),
           (__m128)xmmword_141A711B0);
  v102 = _mm_mul_ps(
           _mm_add_ps(
             _mm_shuffle_ps(v222, v99, 228),
             _mm_add_ps(v101, _mm_shuffle_ps(_mm_movehl_ps(v101, v97), v99, 212))),
           (__m128)xmmword_141A711B0);
  v103 = _mm_unpacklo_ps(v225, v64);
  v223 = v102;
  v104.m_vec.m_quad = (__m128)schema->m_pivotFromOffsetA;
  v105.m_vec.m_quad = (__m128)schema->m_coreFromPivotA;
  v226 = _mm_shuffle_ps(_mm_unpackhi_ps(v225, v64), v65, 228);
  v106 = _mm_movelh_ps(v103, v65);
  v107 = _mm_mul_ps(v55, v105.m_vec.m_quad);
  v108 = _mm_shuffle_ps(_mm_movehl_ps(v106, v103), v65, 212);
  v109 = _mm_shuffle_ps(v105.m_vec.m_quad, v105.m_vec.m_quad, 201);
  v110 = _mm_mul_ps(_mm_shuffle_ps(v104.m_vec.m_quad, v104.m_vec.m_quad, 201), v105.m_vec.m_quad);
  v111 = _mm_mul_ps(v105.m_vec.m_quad, v104.m_vec.m_quad);
  v112 = _mm_sub_ps(v110, _mm_mul_ps(v109, v104.m_vec.m_quad));
  v113 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v112, v112, 201), _mm_mul_ps(v229, v104.m_vec.m_quad)), v107);
  v114 = _mm_xor_ps(
           v230,
           _mm_shuffle_ps(
             v113,
             _mm_unpackhi_ps(
               v113,
               _mm_sub_ps(
                 _mm_mul_ps(v55, v229),
                 _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v111, v111, 85), _mm_shuffle_ps(v111, v111, 0)),
                   _mm_shuffle_ps(v111, v111, 170)))),
             196));
  v115 = transform.m_quad;
  v116 = _mm_add_ps(v114, v114);
  v117 = _mm_mul_ps(_mm_shuffle_ps(v116, v116, 165), _mm_shuffle_ps(v114, v114, 65));
  v109.m128_f32[0] = v114.m128_f32[0] * v116.m128_f32[0];
  v115.m128_f32[0] = (float)(1.0 - (float)(v114.m128_f32[0] * v116.m128_f32[0])) - v117.m128_f32[0];
  v118 = _mm_xor_ps(v117, (__m128)`hkVector4UtilImpl<float>::convertQuaternionToRotation::`2::negateMask0);
  v119 = _mm_xor_ps(
           _mm_mul_ps(_mm_shuffle_ps(v114, v114, 254), _mm_shuffle_ps(v116, v116, 26)),
           (__m128)`hkVector4UtilImpl<float>::convertQuaternionToRotation::`2::negateMask1);
  v119.m128_f32[0] = v119.m128_f32[0] + 1.0;
  v120 = _mm_sub_ps(v119, v118);
  v118.m128_f32[0] = v109.m128_f32[0];
  v121 = _mm_sub_ps(
           _mm_xor_ps(v119, (__m128)`hkVector4UtilImpl<float>::convertQuaternionToRotation::`2::negateMask0),
           v118);
  v122 = _mm_mul_ps(v120, v106);
  v123 = _mm_shuffle_ps(v121, v121, 177);
  v124 = _mm_mul_ps(v123, v106);
  v125 = _mm_shuffle_ps(_mm_movehl_ps(v120, v123), v115, 141);
  v126 = _mm_mul_ps(v125, v106);
  v127 = _mm_unpacklo_ps(v122, v124);
  v128 = _mm_movelh_ps(v127, v126);
  v129 = _mm_mul_ps(v120, v108);
  v130 = _mm_add_ps(
           _mm_shuffle_ps(_mm_unpackhi_ps(v122, v124), v126, 228),
           _mm_add_ps(v128, _mm_shuffle_ps(_mm_movehl_ps(v128, v127), v126, 212)));
  v131 = _mm_mul_ps(v123, v108);
  v132 = _mm_mul_ps(v125, v108);
  v133 = _mm_unpacklo_ps(v129, v131);
  v134 = _mm_unpackhi_ps(v129, v131);
  v135 = _mm_movelh_ps(v133, v132);
  v136 = _mm_mul_ps(v120, v226);
  v137 = _mm_mul_ps(v125, v226);
  v138 = _mm_mul_ps(v123, v226);
  v139 = _mm_unpacklo_ps(v136, v138);
  v140 = _mm_movelh_ps(v139, v137);
  v141 = _mm_add_ps(v135, _mm_shuffle_ps(_mm_movehl_ps(v135, v133), v132, 212));
  v142 = _mm_shuffle_ps(_mm_movehl_ps(v140, v139), v137, 212);
  v143 = _mm_sub_ps((__m128)0i64, (__m128)xmmword_141A711B0);
  v144 = _mm_mul_ps(v130, v143);
  v145 = _mm_mul_ps(_mm_add_ps(_mm_shuffle_ps(v134, v132, 228), v141), v143);
  v146 = _mm_mul_ps(_mm_add_ps(_mm_shuffle_ps(_mm_unpackhi_ps(v136, v138), v137, 228), _mm_add_ps(v140, v142)), v143);
  v147.m_quad = (__m128)mA->m_invMasses;
  v148 = _mm_mul_ps(v144, v147.m_quad);
  v149 = _mm_mul_ps(v145, v147.m_quad);
  v150 = _mm_mul_ps(v146, v147.m_quad);
  v151 = _mm_mul_ps(v144, v148);
  v152 = _mm_mul_ps(v145, v149);
  v153 = _mm_mul_ps(v146, v150);
  v154 = _mm_unpackhi_ps(v151, v152);
  v155 = _mm_unpacklo_ps(v151, v152);
  v156 = _mm_shuffle_ps(v154, v153, 228);
  v157 = _mm_movelh_ps(v155, v153);
  v158 = _mm_add_ps(v157, _mm_shuffle_ps(_mm_movehl_ps(v157, v155), v153, 212));
  v159 = _mm_mul_ps(v144, v150);
  v160 = _mm_add_ps(v158, v156);
  v161 = _mm_mul_ps(v146, v149);
  v162 = _mm_mul_ps(v145, v148);
  v163 = _mm_unpackhi_ps(v162, v161);
  v164 = _mm_unpacklo_ps(v162, v161);
  v165 = _mm_movelh_ps(v164, v159);
  v166 = _mm_add_ps(
           _mm_add_ps(v165, _mm_shuffle_ps(_mm_movehl_ps(v165, v164), v159, 212)),
           _mm_shuffle_ps(v163, v159, 228));
  v167.m_quad = (__m128)mB->m_invMasses;
  v168 = _mm_mul_ps(v228, v167.m_quad);
  v169 = _mm_mul_ps(v224, v167.m_quad);
  v170 = _mm_mul_ps(v223, v167.m_quad);
  v171 = _mm_mul_ps(v228, v168);
  v172 = _mm_mul_ps(v224, v169);
  v173 = _mm_mul_ps(v223, v170);
  v174 = _mm_unpacklo_ps(v171, v172);
  v175 = _mm_shuffle_ps(_mm_unpackhi_ps(v171, v172), v173, 228);
  v176 = _mm_movelh_ps(v174, v173);
  v177 = _mm_add_ps(v176, _mm_shuffle_ps(_mm_movehl_ps(v176, v174), v173, 212));
  v178 = _mm_mul_ps(v228, v170);
  v179 = _mm_mul_ps(v223, v169);
  v180 = (__m128i)_mm_add_ps(_mm_add_ps(v177, v175), v160);
  v181 = _mm_mul_ps(v224, v168);
  v182 = _mm_unpackhi_ps(v181, v179);
  v183 = _mm_unpacklo_ps(v181, v179);
  v184 = _mm_movelh_ps(v183, v178);
  v185 = (__m128i)_mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(v184, _mm_shuffle_ps(_mm_movehl_ps(v184, v183), v178, 212)),
                      _mm_shuffle_ps(v182, v178, 228)),
                    v166);
  v186 = _mm_max_ps(
           (__m128)_mm_srli_epi32(_mm_slli_epi32(v180, 1u), 1u),
           (__m128)_mm_srli_epi32(_mm_slli_epi32(v185, 1u), 1u));
  v187 = _mm_max_ps(
           _mm_shuffle_ps(v186, v186, 170),
           _mm_max_ps(_mm_shuffle_ps(v186, v186, 85), _mm_shuffle_ps(v186, v186, 0)));
  v188 = _mm_andnot_ps(_mm_cmpeq_ps(v187, (__m128)0i64), _mm_div_ps(query.m_quad, v187));
  v189 = _mm_mul_ps((__m128)v180, v188);
  v190 = _mm_mul_ps((__m128)v185, v188);
  v191 = _mm_shuffle_ps(v189, v189, 210);
  v192 = _mm_shuffle_ps(v190, v190, 201);
  v193 = _mm_mul_ps(_mm_shuffle_ps(v189, v189, 201), v191);
  v194 = _mm_mul_ps(v193, v189);
  v195 = 3;
  v196 = _mm_mul_ps(v192, v192);
  v197 = _mm_sub_ps(v193, v196);
  v198 = _mm_mul_ps(v196, v189);
  v199 = _mm_mul_ps(_mm_shuffle_ps(v190, v190, 210), v192);
  v200 = _mm_sub_ps(v199, _mm_mul_ps(v191, v190));
  v201 = _mm_add_ps(v194, _mm_mul_ps(_mm_mul_ps(v199, v190), (__m128)xmmword_141A710D0));
  v202 = (__m128i)_mm_sub_ps(
                    _mm_shuffle_ps(v201, v201, 0),
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v198, v198, 85), _mm_shuffle_ps(v198, v198, 0)),
                      _mm_shuffle_ps(v198, v198, 170)));
  v203 = _mm_rcp_ps((__m128)v202);
  v204 = _mm_xor_ps(v230, v232);
  v205 = _mm_mul_ps(
           _mm_and_ps(
             _mm_cmplt_ps(*(__m128 *)&epsilon, (__m128)_mm_srli_epi32(_mm_slli_epi32(v202, 1u), 1u)),
             _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v203, (__m128)v202)), v203)),
           v188);
  v206 = _mm_mul_ps(v205, v200);
  v207 = _mm_mul_ps(v206, v231);
  v208 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v231, v231, 201), v206), _mm_mul_ps(_mm_mul_ps(v205, v197), v231));
  v209 = _mm_rcp_ps((__m128)v180);
  v210 = _mm_add_ps(v208, _mm_shuffle_ps(v207, v207, 210));
  v211 = _mm_andnot_ps(
           _mm_cmpeq_ps((__m128)0i64, (__m128)v180),
           _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v209, (__m128)v180)), v209));
  do
  {
    --v195;
    v212 = _mm_mul_ps((__m128)v185, v210);
    v210 = _mm_max_ps(
             _mm_min_ps(
               _mm_mul_ps(
                 _mm_sub_ps(
                   v231,
                   _mm_add_ps(
                     _mm_shuffle_ps(v212, v212, 210),
                     _mm_mul_ps(_mm_shuffle_ps(v210, v210, 201), (__m128)v185))),
                 v211),
               v232),
             v204);
  }
  while ( v195 >= 0 );
  v213 = _mm_shuffle_ps(v210, v210, 0);
  v214 = _mm_shuffle_ps(v210, v210, 85);
  v215 = _mm_shuffle_ps(v210, v210, 170);
  v216 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v213, v228), _mm_mul_ps(v214, v224)), _mm_mul_ps(v215, v223));
  v217 = _mm_add_ps(_mm_mul_ps(v213, v144), _mm_mul_ps(v214, v145));
  m_impulseApplied_low = (__m128)LODWORD(temps[2].m_impulseApplied);
  mB->m_angularVel.m_quad = _mm_add_ps(_mm_mul_ps(v216, mB->m_invMasses.m_quad), mB->m_angularVel.m_quad);
  v219 = _mm_add_ps(v217, _mm_mul_ps(v215, v146));
  v220 = _mm_add_ps(_mm_movelh_ps((__m128)*(unsigned __int64 *)&temps->m_impulseApplied, m_impulseApplied_low), v210);
  v221.m_quad = _mm_add_ps(_mm_mul_ps(v219, mA->m_invMasses.m_quad), mA->m_angularVel.m_quad);
  *(_QWORD *)&temps->m_impulseApplied = v220.m128_u64[0];
  LODWORD(temps[2].m_impulseApplied) = _mm_movehl_ps(v220, v220).m128_u32[0];
  mA->m_angularVel = (hkVector4f)v221.m_quad;
}Applied_low = (__m128)LODWORD(temps[2].m_impulseApplied);
  mB->m_angularVel.m_quad = _mm_add_ps(_mm_mul_ps(v216, mB->m_invMasses.m_quad), mB->m_angularVel.m_quad);

// File Line: 911
// RVA: 0xDE3CA0
void __fastcall hkpAtomSolverFunctions::solveDeformableLinConstraintStub<hkpVelocityAccumulator,hkpSolverInfo,hkSolverStepTemp>(
        hkpSolverInfo *solverInfo,
        hkSolverStepTemp *temp,
        hkpDeformableLinSchema *schema,
        hkpVelocityAccumulator *mA,
        hkpVelocityAccumulator *mB,
        hkpSolverElemTemp *temps)
{
  hkQTransformf coreToWorldB; // [rsp+50h] [rbp-48h] BYREF
  hkQTransformf coreToWorldA; // [rsp+70h] [rbp-28h] BYREF

  hkpAtomSolverFunctions::getFuturePositions<hkpVelocityAccumulator,hkpSolverInfo>(
    solverInfo,
    mA,
    &mA->m_scratch3,
    (hkQuaternionf *)&mA->m_scratch2,
    mB,
    &mB->m_scratch3,
    (hkQuaternionf *)&mB->m_scratch2,
    &coreToWorldA,
    &coreToWorldB);
  hkpAtomSolverFunctions::solveDeformableLinConstraint<hkpVelocityAccumulator>(
    &coreToWorldA,
    &coreToWorldB,
    schema,
    mA,
    mB,
    temps);
}

// File Line: 931
// RVA: 0xDE34E0
void __fastcall hkpAtomSolverFunctions::solveDeformableAngConstraintStub<hkpVelocityAccumulator,hkpSolverInfo,hkSolverStepTemp>(
        hkpSolverInfo *solverInfo,
        hkSolverStepTemp *temp,
        hkpDeformableAngSchema *schema,
        hkpVelocityAccumulator *mA,
        hkpVelocityAccumulator *mB,
        hkpSolverElemTemp *temps)
{
  hkQTransformf coreToWorldB; // [rsp+50h] [rbp-48h] BYREF
  hkQTransformf coreToWorldA; // [rsp+70h] [rbp-28h] BYREF

  hkpAtomSolverFunctions::getFuturePositions<hkpVelocityAccumulator,hkpSolverInfo>(
    solverInfo,
    mA,
    &mA->m_scratch3,
    (hkQuaternionf *)&mA->m_scratch2,
    mB,
    &mB->m_scratch3,
    (hkQuaternionf *)&mB->m_scratch2,
    &coreToWorldA,
    &coreToWorldB);
  hkpAtomSolverFunctions::solveDeformableAngConstraint<hkpVelocityAccumulator>(
    &coreToWorldA,
    &coreToWorldB,
    schema,
    mA,
    mB,
    temps);
}

// File Line: 1056
// RVA: 0xDE2240
void __fastcall hkpAtomSolverFunctions::solve1dBilateralWithImpulseLimit<hkpVelocityAccumulator,hkpSolverInfo,hkSolverStepTemp>(
        hkpSolverInfo *info,
        hkSolverStepTemp *temp,
        hkpJacobian1dBilateralSchema *schema,
        hkpVelocityAccumulator *mA,
        hkpVelocityAccumulator *mB,
        hkpSolverElemTemp *temps)
{
  hkVector4f v6; // xmm5
  __m128 m_quad; // xmm3
  __m128 v8; // xmm6
  hkVector4f v9; // xmm7
  __m128 v10; // xmm0
  __m128 v11; // xmm8
  __m128 v12; // xmm2
  __m128 v13; // xmm8
  __m128 v14; // xmm2
  __m128 v15; // xmm1
  __m128 v16; // xmm0
  __m128 v17; // xmm2
  hkVector4f v18; // xmm7
  __m128 v19; // xmm0
  hkVector4f v20; // xmm0

  v6.m_quad = (__m128)schema->m_jac.m_linear0;
  m_quad = schema->m_jac.m_angular[0].m_quad;
  v8 = _mm_shuffle_ps((__m128)LODWORD(temps->m_impulseApplied), (__m128)LODWORD(temps->m_impulseApplied), 0);
  v9.m_quad = (__m128)mB->m_linearVel;
  v10 = schema->m_jac.m_angular[1].m_quad;
  v11 = _mm_shuffle_ps(v10, v10, 255);
  v12 = _mm_add_ps(
          _mm_add_ps(_mm_mul_ps(mA->m_angularVel.m_quad, m_quad), _mm_mul_ps(v10, mB->m_angularVel.m_quad)),
          _mm_mul_ps(_mm_sub_ps(mA->m_linearVel.m_quad, v9.m_quad), schema->m_jac.m_linear0.m_quad));
  v13 = _mm_min_ps(
          _mm_sub_ps(v11, v8),
          _mm_max_ps(
            _mm_sub_ps(_mm_sub_ps((__m128)0i64, v11), v8),
            _mm_mul_ps(
              _mm_sub_ps(
                _mm_shuffle_ps(v6.m_quad, v6.m_quad, 255),
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)),
                  _mm_shuffle_ps(v12, v12, 170))),
              _mm_shuffle_ps(m_quad, m_quad, 255))));
  v14 = _mm_mul_ps(mB->m_invMasses.m_quad, v13);
  v15 = _mm_mul_ps(mA->m_invMasses.m_quad, v13);
  temps->m_impulseApplied = v8.m128_f32[0] + v13.m128_f32[0];
  mA->m_linearVel.m_quad = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v15, v15, 255), v6.m_quad), mA->m_linearVel.m_quad);
  v16 = _mm_shuffle_ps(v14, v14, 255);
  v17 = _mm_mul_ps(v14, schema->m_jac.m_angular[1].m_quad);
  v18.m_quad = _mm_sub_ps(v9.m_quad, _mm_mul_ps(v16, v6.m_quad));
  v19 = _mm_mul_ps(schema->m_jac.m_angular[0].m_quad, v15);
  mB->m_linearVel = (hkVector4f)v18.m_quad;
  v20.m_quad = _mm_add_ps(v19, mA->m_angularVel.m_quad);
  mB->m_angularVel.m_quad = _mm_add_ps(v17, mB->m_angularVel.m_quad);
  mA->m_angularVel = (hkVector4f)v20.m_quad;
}

// File Line: 1075
// RVA: 0xDE20C0
void __fastcall hkpAtomSolverFunctions::solve1dBilateralUserTau<hkpVelocityAccumulator,hkpSolverInfo,hkSolverStepTemp>(
        hkpSolverInfo *info,
        hkSolverStepTemp *temp,
        hkpJacobian1dBilateralUserTauSchema *schema,
        hkpVelocityAccumulator *mA,
        hkpVelocityAccumulator *mB,
        hkpSolverElemTemp *temps)
{
  __m128 m_quad; // xmm5
  hkVector4f v7; // xmm8
  __m128 v8; // xmm6
  hkVector4f v9; // xmm9
  __m128 v10; // xmm10
  __m128 v11; // xmm4
  __m128 v12; // xmm3
  __m128 v13; // xmm2
  __m128 v14; // xmm1

  m_quad = schema->m_jac.m_angular[0].m_quad;
  v7.m_quad = (__m128)schema->m_jac.m_linear0;
  v8 = _mm_shuffle_ps((__m128)LODWORD(schema->m_tau), (__m128)LODWORD(schema->m_tau), 0);
  v9.m_quad = (__m128)mB->m_linearVel;
  v10 = schema->m_jac.m_angular[1].m_quad;
  v11 = _mm_add_ps(
          _mm_mul_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_sub_ps(mA->m_angularVel.m_quad, mA->m_scratch1.m_quad), m_quad),
                _mm_mul_ps(_mm_sub_ps(mB->m_angularVel.m_quad, mB->m_scratch1.m_quad), v10)),
              _mm_mul_ps(
                _mm_sub_ps(
                  _mm_sub_ps(mA->m_linearVel.m_quad, mA->m_scratch0.m_quad),
                  _mm_sub_ps(v9.m_quad, mB->m_scratch0.m_quad)),
                schema->m_jac.m_linear0.m_quad)),
            _mm_shuffle_ps((__m128)LODWORD(schema->m_damping), (__m128)LODWORD(schema->m_damping), 0)),
          _mm_mul_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(v10, mB->m_scratch1.m_quad), _mm_mul_ps(m_quad, mA->m_scratch1.m_quad)),
              _mm_mul_ps(_mm_sub_ps(mA->m_scratch0.m_quad, mB->m_scratch0.m_quad), schema->m_jac.m_linear0.m_quad)),
            _mm_mul_ps(
              _mm_shuffle_ps(info->m_invIntegrateVelocityFactor.m_quad, info->m_invIntegrateVelocityFactor.m_quad, 0),
              v8)));
  v12 = _mm_mul_ps(
          _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(v7.m_quad, v7.m_quad, 255), v8),
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)),
              _mm_shuffle_ps(v11, v11, 170))),
          _mm_shuffle_ps(m_quad, m_quad, 255));
  v13 = _mm_mul_ps(mA->m_invMasses.m_quad, v12);
  v14 = _mm_mul_ps(mB->m_invMasses.m_quad, v12);
  mA->m_linearVel.m_quad = _mm_add_ps(
                             _mm_mul_ps(_mm_shuffle_ps(v13, v13, 255), schema->m_jac.m_linear0.m_quad),
                             mA->m_linearVel.m_quad);
  mA->m_angularVel.m_quad = _mm_add_ps(_mm_mul_ps(v13, m_quad), mA->m_angularVel.m_quad);
  mB->m_linearVel.m_quad = _mm_sub_ps(v9.m_quad, _mm_mul_ps(_mm_shuffle_ps(v14, v14, 255), v7.m_quad));
  mB->m_angularVel.m_quad = _mm_add_ps(_mm_mul_ps(v10, v14), mB->m_angularVel.m_quad);
  temps->m_impulseApplied = _mm_shuffle_ps(
                              (__m128)LODWORD(temps->m_impulseApplied),
                              (__m128)LODWORD(temps->m_impulseApplied),
                              0).m128_f32[0]
                          + v12.m128_f32[0];
}

// File Line: 1140
// RVA: 0xDE4170
void __fastcall hkpAtomSolverFunctions::solvePulley<hkpVelocityAccumulator,hkpSolverInfo,hkSolverStepTemp>(
        hkpSolverInfo *info,
        hkSolverStepTemp *solverTemp,
        hkpJacobian1dPulleySchema *schema,
        hkpVelocityAccumulator *mA,
        hkpVelocityAccumulator *mB,
        hkpSolverElemTemp *temps)
{
  __m128 m_quad; // xmm3
  hkVector4f v7; // xmm8
  __m128 v8; // xmm2
  __m128 v9; // xmm4
  __m128 v10; // xmm1
  __m128 v11; // xmm2
  __m128 v12; // xmm9
  __m128 v13; // xmm0
  hkVector4f v14; // xmm0

  m_quad = schema->m_jac.m_angular[0].m_quad;
  v7.m_quad = (__m128)mB->m_linearVel;
  v8 = _mm_add_ps(
         _mm_add_ps(
           _mm_mul_ps(mA->m_angularVel.m_quad, m_quad),
           _mm_mul_ps(schema->m_jac.m_angular[1].m_quad, mB->m_angularVel.m_quad)),
         _mm_sub_ps(
           _mm_mul_ps(schema->m_jac.m_linear[0].m_quad, mA->m_linearVel.m_quad),
           _mm_mul_ps(schema->m_jac.m_linear[1].m_quad, v7.m_quad)));
  v9 = _mm_mul_ps(
         _mm_sub_ps(
           _mm_shuffle_ps(schema->m_jac.m_linear[0].m_quad, schema->m_jac.m_linear[0].m_quad, 255),
           _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)), _mm_shuffle_ps(v8, v8, 170))),
         _mm_shuffle_ps(m_quad, m_quad, 255));
  v10 = _mm_mul_ps(mA->m_invMasses.m_quad, v9);
  v11 = _mm_mul_ps(mB->m_invMasses.m_quad, v9);
  v12 = _mm_mul_ps(schema->m_jac.m_angular[1].m_quad, v11);
  mA->m_linearVel.m_quad = _mm_add_ps(
                             _mm_mul_ps(_mm_shuffle_ps(v10, v10, 255), schema->m_jac.m_linear[0].m_quad),
                             mA->m_linearVel.m_quad);
  v13 = _mm_mul_ps(schema->m_jac.m_angular[0].m_quad, v10);
  mB->m_linearVel.m_quad = _mm_sub_ps(
                             v7.m_quad,
                             _mm_mul_ps(_mm_shuffle_ps(v11, v11, 255), schema->m_jac.m_linear[1].m_quad));
  v14.m_quad = _mm_add_ps(v13, mA->m_angularVel.m_quad);
  mB->m_angularVel.m_quad = _mm_add_ps(v12, mB->m_angularVel.m_quad);
  mA->m_angularVel = (hkVector4f)v14.m_quad;
  temps->m_impulseApplied = _mm_shuffle_ps(
                              (__m128)LODWORD(temps->m_impulseApplied),
                              (__m128)LODWORD(temps->m_impulseApplied),
                              0).m128_f32[0]
                          + v9.m128_f32[0];
}

// File Line: 1447
// RVA: 0xDE2740
void __fastcall hkpAtomSolverFunctions::solve2dRollingFriction<hkpVelocityAccumulator,hkpSolverInfo,hkSolverStepTemp>(
        hkpSolverInfo *info,
        hkSolverStepTemp *temp,
        hkpJacobian2dRollingFrictionSchema *schema,
        hkpVelocityAccumulator *mA,
        hkpVelocityAccumulator *mB,
        hkpSolverElemTemp *temps)
{
  __m128 v6; // xmm6
  __m128 m_quad; // xmm8
  __m128 v8; // xmm0
  __m128 v9; // xmm11
  __m128 v10; // xmm12
  __m128 v11; // xmm2
  __m128 v12; // xmm3
  __m128 v13; // xmm7
  __m128 v14; // xmm5
  __m128 v15; // xmm1
  __m128 v16; // xmm4
  __m128 v17; // xmm2
  __m128 v18; // xmm3
  __m128 v19; // xmm1
  __m128 v20; // xmm6
  __m128 v21; // xmm2
  __m128 v22; // xmm3
  hkVector4f v23; // xmm2
  hkVector4f v24; // xmm3
  __m128 v25; // xmm0
  __m128 v26; // xmm1

  v6 = _mm_shuffle_ps((__m128)LODWORD(schema->m_maxImpulse), (__m128)LODWORD(schema->m_maxImpulse), 0);
  m_quad = schema->m_jac0.m_angular[0].m_quad;
  v8 = schema->m_jac0.m_angular[1].m_quad;
  v9 = schema->m_jac1.m_angular[0].m_quad;
  v10 = schema->m_jac1.m_angular[1].m_quad;
  v11 = _mm_add_ps(
          _mm_mul_ps(schema->m_jac0.m_angular[0].m_quad, mA->m_angularVel.m_quad),
          _mm_mul_ps(v8, mB->m_angularVel.m_quad));
  v12 = _mm_add_ps(_mm_mul_ps(v9, mA->m_angularVel.m_quad), _mm_mul_ps(v10, mB->m_angularVel.m_quad));
  v13 = _mm_mul_ps(
          _mm_sub_ps(
            _mm_shuffle_ps(v8, v8, 255),
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)),
              _mm_shuffle_ps(v11, v11, 170))),
          _mm_shuffle_ps(m_quad, m_quad, 255));
  v14 = _mm_mul_ps(
          _mm_sub_ps(
            _mm_shuffle_ps(v10, v10, 255),
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)),
              _mm_shuffle_ps(v12, v12, 170))),
          _mm_shuffle_ps(v9, v9, 255));
  v15 = _mm_add_ps(_mm_mul_ps(v14, v14), _mm_mul_ps(v13, v13));
  v16 = _mm_cmplt_ps(_mm_mul_ps(v6, v6), v15);
  v17 = _mm_rsqrt_ps(v15);
  v18 = _mm_mul_ps(
          _mm_andnot_ps(
            _mm_cmple_ps(v15, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v17, v15), v17)),
              _mm_mul_ps(*(__m128 *)_xmm, v17))),
          v6);
  v19 = _mm_or_ps(_mm_and_ps(_mm_mul_ps(v18, v13), v16), _mm_andnot_ps(v16, v13));
  v20 = _mm_or_ps(_mm_and_ps(_mm_mul_ps(v18, v14), v16), _mm_andnot_ps(v16, v14));
  v21 = _mm_mul_ps(mB->m_invMasses.m_quad, v19);
  LODWORD(temps[2].m_impulseApplied) = v18.m128_i32[0] & v16.m128_i32[0] | _mm_andnot_ps(v16, query.m_quad).m128_u32[0];
  v22 = _mm_mul_ps(mA->m_invMasses.m_quad, v19);
  v23.m_quad = _mm_add_ps(_mm_mul_ps(v21, schema->m_jac0.m_angular[1].m_quad), mB->m_angularVel.m_quad);
  temps->m_impulseApplied = _mm_shuffle_ps(
                              (__m128)LODWORD(temps->m_impulseApplied),
                              (__m128)LODWORD(temps->m_impulseApplied),
                              0).m128_f32[0]
                          + v19.m128_f32[0];
  mB->m_angularVel = (hkVector4f)v23.m_quad;
  v24.m_quad = _mm_add_ps(_mm_mul_ps(v22, m_quad), mA->m_angularVel.m_quad);
  v25 = _mm_mul_ps(_mm_mul_ps(mB->m_invMasses.m_quad, v20), v10);
  mA->m_angularVel = (hkVector4f)v24.m_quad;
  v26 = _mm_mul_ps(_mm_mul_ps(mA->m_invMasses.m_quad, v20), v9);
  mB->m_angularVel.m_quad = _mm_add_ps(v25, v23.m_quad);
  v25.m128_f32[0] = _mm_shuffle_ps(
                      (__m128)LODWORD(temps[1].m_impulseApplied),
                      (__m128)LODWORD(temps[1].m_impulseApplied),
                      0).m128_f32[0]
                  + v20.m128_f32[0];
  mA->m_angularVel.m_quad = _mm_add_ps(v26, v24.m_quad);
  temps[1].m_impulseApplied = v25.m128_f32[0];
}

// File Line: 1624
// RVA: 0xDE2510
void __fastcall hkpAtomSolverFunctions::solve1dLinearMotor<hkpVelocityAccumulator,hkpSolverInfo,hkSolverStepTemp>(
        hknpSimulationThreadContext *tl,
        hkpSolverInfo *info,
        hkSolverStepTemp *temp,
        hkpJacobian1dLinearMotorSchema *schema,
        hkpVelocityAccumulator *mA,
        hkpVelocityAccumulator *mB,
        hkpSolverElemTemp *temps)
{
  __m128 v8; // xmm7
  __m128 m_quad; // xmm9
  hkVector4f v10; // xmm11
  hkVector4f v11; // xmm12
  __m128 v12; // xmm6
  __m128 v13; // xmm1
  __m128 v14; // xmm6
  __m128 v15; // xmm8
  __m128 v16; // xmm7
  __m128 v17; // xmm8
  __m128 v18; // xmm1
  __m128 v19; // xmm5
  __m128 v20; // xmm4
  hkVector4f v21; // xmm2
  __m128 v22; // xmm0
  __m128 v23; // xmm7
  __m128 v24; // xmm1
  __m128 v25; // xmm2
  __m128 v26; // xmm0
  __m128 v27; // xmm1
  __m128 v28; // xmm0
  __m128 v29; // xmm2
  hkVector4f v30; // xmm12

  v8 = _mm_shuffle_ps(
         (__m128)LODWORD(schema->m_motorSolverInfo.m_tau),
         (__m128)LODWORD(schema->m_motorSolverInfo.m_tau),
         0);
  m_quad = schema->m_jac.m_angular[0].m_quad;
  v10.m_quad = (__m128)schema->m_jac.m_linear0;
  v11.m_quad = (__m128)mB->m_linearVel;
  v12 = _mm_add_ps(
          _mm_mul_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_sub_ps(mB->m_angularVel.m_quad, mB->m_scratch1.m_quad),
                  schema->m_jac.m_angular[1].m_quad),
                _mm_mul_ps(_mm_sub_ps(mA->m_angularVel.m_quad, mA->m_scratch1.m_quad), m_quad)),
              _mm_mul_ps(
                _mm_sub_ps(
                  _mm_sub_ps(mA->m_linearVel.m_quad, mA->m_scratch0.m_quad),
                  _mm_sub_ps(v11.m_quad, mB->m_scratch0.m_quad)),
                schema->m_jac.m_linear0.m_quad)),
            _mm_shuffle_ps(
              (__m128)LODWORD(schema->m_motorSolverInfo.m_damping),
              (__m128)LODWORD(schema->m_motorSolverInfo.m_damping),
              0)),
          _mm_mul_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(mB->m_scratch1.m_quad, schema->m_jac.m_angular[1].m_quad),
                _mm_mul_ps(mA->m_scratch1.m_quad, m_quad)),
              _mm_mul_ps(_mm_sub_ps(mA->m_scratch0.m_quad, mB->m_scratch0.m_quad), schema->m_jac.m_linear0.m_quad)),
            _mm_mul_ps(
              _mm_shuffle_ps(info->m_invIntegrateVelocityFactor.m_quad, info->m_invIntegrateVelocityFactor.m_quad, 0),
              v8)));
  v13 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)), _mm_shuffle_ps(v12, v12, 170));
  v14 = _mm_shuffle_ps(
          (__m128)LODWORD(schema->m_motorSolverInfo.m_maxImpulsePerSubstep),
          (__m128)LODWORD(schema->m_motorSolverInfo.m_maxImpulsePerSubstep),
          0);
  v15 = _mm_sub_ps(
          _mm_mul_ps(
            _mm_add_ps(
              _mm_mul_ps(
                _mm_shuffle_ps(
                  (__m128)LODWORD(schema->m_motorSolverInfo.m_velocity),
                  (__m128)LODWORD(schema->m_motorSolverInfo.m_velocity),
                  0),
                temp->m_intregratePositionFactor.m_real),
              _mm_shuffle_ps(v10.m_quad, v10.m_quad, 255)),
            v8),
          v13);
  v16 = _mm_shuffle_ps(
          (__m128)LODWORD(schema->m_motorSolverInfo.m_minImpulsePerSubstep),
          (__m128)LODWORD(schema->m_motorSolverInfo.m_minImpulsePerSubstep),
          0);
  v17 = _mm_mul_ps(v15, _mm_shuffle_ps(m_quad, m_quad, 255));
  v18 = _mm_rcp_ps(v17);
  v19 = _mm_cmplt_ps(v14, v17);
  v20 = _mm_cmplt_ps(v17, v16);
  v21.m_quad = (__m128)mB->m_invMasses;
  LODWORD(temps[1].m_impulseApplied) = _mm_andnot_ps(
                                         v19,
                                         _mm_or_ps(
                                           _mm_and_ps(
                                             _mm_mul_ps(
                                               _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v18, v17)), v18),
                                               v16),
                                             v20),
                                           _mm_andnot_ps(v20, query.m_quad))).m128_u32[0] | COERCE_UNSIGNED_INT(
                                                                                              (float)((float)(2.0 - (float)(v18.m128_f32[0] * v17.m128_f32[0])) * v18.m128_f32[0])
                                                                                            * v14.m128_f32[0]) & v19.m128_i32[0];
  v22 = _mm_cmplt_ps(v17, v14);
  v23 = _mm_max_ps(v16, _mm_or_ps(_mm_and_ps(v22, v17), _mm_andnot_ps(v22, v14)));
  v24 = _mm_mul_ps(mA->m_invMasses.m_quad, v23);
  v25 = _mm_mul_ps(v21.m_quad, v23);
  v26 = _mm_shuffle_ps(v24, v24, 255);
  v27 = _mm_mul_ps(v24, schema->m_jac.m_angular[0].m_quad);
  mA->m_linearVel.m_quad = _mm_add_ps(_mm_mul_ps(v26, v10.m_quad), mA->m_linearVel.m_quad);
  v28 = _mm_shuffle_ps(v25, v25, 255);
  v29 = _mm_mul_ps(v25, schema->m_jac.m_angular[1].m_quad);
  mA->m_angularVel.m_quad = _mm_add_ps(v27, mA->m_angularVel.m_quad);
  v30.m_quad = _mm_sub_ps(v11.m_quad, _mm_mul_ps(v28, v10.m_quad));
  v28.m128_f32[0] = _mm_shuffle_ps(
                      (__m128)LODWORD(temps->m_impulseApplied),
                      (__m128)LODWORD(temps->m_impulseApplied),
                      0).m128_f32[0];
  mB->m_linearVel = (hkVector4f)v30.m_quad;
  mB->m_angularVel.m_quad = _mm_add_ps(v29, mB->m_angularVel.m_quad);
  temps->m_impulseApplied = v28.m128_f32[0] + v23.m128_f32[0];
}

