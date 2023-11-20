// File Line: 85
// RVA: 0xDE2350
void __fastcall hkpAtomSolverFunctions::solve1dLinLimits<hkpVelocityAccumulator,hkpSolverInfo,hkSolverStepTemp>(hkpSolverInfo *info, hkSolverStepTemp *temp, hkpJacobian1dLinearLimitsSchema *schema, hkpVelocityAccumulator *mA, hkpVelocityAccumulator *mB, hkpSolverElemTemp *temps)
{
  __m128 v6; // xmm5
  hkVector4f v7; // xmm6
  __m128 v8; // xmm7
  float v9; // xmm8_4
  hkVector4f v10; // xmm10
  __m128 v11; // xmm0
  __m128 v12; // xmm7
  hkVector4f v13; // xmm11
  __m128 v14; // xmm2
  __m128 v15; // xmm4
  __m128 v16; // xmm3
  hkVector4f v17; // xmm1
  hkVector4f v18; // xmm2
  __m128 v19; // xmm1
  __m128 v20; // xmm2
  __m128 v21; // xmm0
  __m128 v22; // xmm4
  __m128 v23; // xmm2
  __m128 v24; // xmm3
  __m128 v25; // xmm0

  v6 = schema->m_jac.m_angular[1].m_quad;
  v7.m_quad = (__m128)schema->m_jac.m_linear0;
  v8 = schema->m_jac.m_angular[0].m_quad;
  LODWORD(v9) = (unsigned __int128)_mm_shuffle_ps(
                                     (__m128)LODWORD(temps->m_impulseApplied),
                                     (__m128)LODWORD(temps->m_impulseApplied),
                                     0);
  v10.m_quad = (__m128)mB->m_linearVel;
  v11 = v8;
  v12 = _mm_shuffle_ps(v8, v8, 255);
  v13.m_quad = (__m128)mA->m_linearVel;
  v14 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(schema->m_jac.m_angular[1].m_quad, mB->m_angularVel.m_quad),
            _mm_mul_ps(v11, mA->m_angularVel.m_quad)),
          _mm_mul_ps(_mm_sub_ps(mA->m_linearVel.m_quad, v10.m_quad), schema->m_jac.m_linear0.m_quad));
  v15 = _mm_sub_ps(
          _mm_shuffle_ps(v7.m_quad, v7.m_quad, 255),
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)),
            _mm_shuffle_ps(v14, v14, 170)));
  v16 = _mm_mul_ps(
          _mm_sub_ps(v15, _mm_shuffle_ps((__m128)LODWORD(schema->m_minRhs), (__m128)LODWORD(schema->m_minRhs), 0)),
          v12);
  if ( v16.m128_f32[0] > (float)(0.0 - v9) )
  {
    v17.m_quad = (__m128)mA->m_invMasses;
    v18.m_quad = (__m128)mB->m_invMasses;
    temps->m_impulseApplied = v9 + v16.m128_f32[0];
    v19 = _mm_mul_ps(v17.m_quad, v16);
    v20 = _mm_mul_ps(v18.m_quad, v16);
    mA->m_linearVel.m_quad = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v19, v19, 255), v7.m_quad), v13.m_quad);
    v21 = _mm_mul_ps(schema->m_jac.m_angular[0].m_quad, v19);
    mB->m_linearVel.m_quad = _mm_sub_ps(v10.m_quad, _mm_mul_ps(_mm_shuffle_ps(v20, v20, 255), v7.m_quad));
    mA->m_angularVel.m_quad = _mm_add_ps(v21, mA->m_angularVel.m_quad);
    mB->m_angularVel.m_quad = _mm_add_ps(_mm_mul_ps(v6, v20), mB->m_angularVel.m_quad);
  }
  v22 = _mm_mul_ps(
          _mm_sub_ps(v15, _mm_shuffle_ps((__m128)LODWORD(schema->m_maxRhs), (__m128)LODWORD(schema->m_maxRhs), 0)),
          v12);
  if ( v22.m128_f32[0] < (float)(0.0 - v9) )
  {
    v23 = _mm_mul_ps(mA->m_invMasses.m_quad, v22);
    v24 = _mm_mul_ps(mB->m_invMasses.m_quad, v22);
    mA->m_linearVel.m_quad = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v23, v23, 255), v7.m_quad), mA->m_linearVel.m_quad);
    mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, _mm_mul_ps(_mm_shuffle_ps(v24, v24, 255), v7.m_quad));
    v25 = _mm_mul_ps(schema->m_jac.m_angular[0].m_quad, v23);
    mB->m_angularVel.m_quad = _mm_add_ps(_mm_mul_ps(v6, v24), mB->m_angularVel.m_quad);
    mA->m_angularVel.m_quad = _mm_add_ps(v25, mA->m_angularVel.m_quad);
    temps->m_impulseApplied = COERCE_FLOAT(
                                _mm_shuffle_ps(
                                  (__m128)LODWORD(temps->m_impulseApplied),
                                  (__m128)LODWORD(temps->m_impulseApplied),
                                  0))
                            + v22.m128_f32[0];
  }
}

// File Line: 154
// RVA: 0xDDEF00
void __fastcall hkpAtomSolverFunctions::computeAngularInverseMass(hkVector4f *invIA, hkVector4f *invIB, hkMatrix3f *UA, hkMatrix3f *UB, hkMatrix3f *K)
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
          _mm_mul_ps(_mm_mul_ps(UB->m_col1.m_quad, v5.m_quad), invIB->m_quad));
  v13 = _mm_add_ps(
          _mm_mul_ps(_mm_mul_ps(UA->m_col2.m_quad, v6.m_quad), invIA->m_quad),
          _mm_mul_ps(_mm_mul_ps(UB->m_col2.m_quad, v5.m_quad), invIB->m_quad));
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
  v23.m_quad.m128_f32[0] = COERCE_FLOAT(_mm_shuffle_ps(v21.m_quad, v21.m_quad, 85));
  v22.m_quad.m128_f32[0] = COERCE_FLOAT(_mm_shuffle_ps(v21.m_quad, v21.m_quad, 170));
  K->m_col2 = (hkVector4f)v22.m_quad;
  K->m_col1 = (hkVector4f)v23.m_quad;
}

// File Line: 231
// RVA: 0xDE1360
void __fastcall hkpAtomSolverFunctions::computeInverseVirtualMass3D<hkpVelocityAccumulator>(hkMatrix3f *axes, hkSimdFloat32 *fA, hkSimdFloat32 *fB, hkQuaternionf *rotA, hkQuaternionf *rotB, hkVector4f *localArmDirA, hkVector4f *localArmDirB, hkpVelocityAccumulator *mA, hkpVelocityAccumulator *mB, hkMatrix3f *outK, hkMatrix3f *UA, hkMatrix3f *UB)
{
  __m128 v12; // xmm3
  __m128 v13; // xmm4
  hkVector4f v14; // xmm14
  hkVector4f v15; // xmm15
  __m128 v16; // ST00_16
  __m128 v17; // xmm14
  __m128 v18; // xmm1
  __m128 v19; // xmm3
  __m128 v20; // xmm9
  __m128 v21; // xmm15
  __m128 v22; // xmm7
  __m128 v23; // xmm8
  __m128 v24; // xmm1
  __m128 v25; // xmm4
  __m128 v26; // xmm10
  __m128 v27; // xmm12
  __m128 v28; // xmm13
  __m128 v29; // xmm11
  __m128 v30; // xmm5
  __m128 v31; // xmm11
  __m128 v32; // xmm5
  __m128 v33; // xmm1
  __m128 v34; // xmm6
  __m128 v35; // xmm4
  __m128 v36; // xmm3
  __m128 v37; // xmm2
  __m128 v38; // xmm1
  __m128 v39; // xmm2
  __m128 v40; // xmm3
  __m128 v41; // xmm2
  __m128 v42; // xmm1
  __m128 v43; // xmm2
  __m128 v44; // xmm3
  __m128 v45; // xmm2
  __m128 v46; // xmm4
  __m128 v47; // xmm1
  __m128 v48; // xmm5
  __m128 v49; // xmm2
  __m128 v50; // xmm2
  __m128 v51; // xmm8
  __m128 v52; // xmm1
  __m128 v53; // xmm8
  __m128 v54; // xmm3
  hkVector4f v55; // xmm8
  __m128 v56; // xmm2
  __m128 v57; // xmm1
  __m128 v58; // xmm2
  __m128 v59; // xmm3
  __m128 v60; // xmm2
  hkVector4f v61; // xmm3
  hkVector4f v62; // xmm2
  hkVector4f v63; // xmm7
  __m128 v64; // xmm9
  __m128 v65; // xmm5
  __m128 v66; // xmm6
  __m128 v67; // xmm8
  __m128 v68; // xmm1
  __m128 v69; // xmm7
  __m128 v70; // xmm0
  __m128 v71; // xmm4
  __m128 v72; // xmm3
  __m128 v73; // xmm0
  __m128 v74; // xmm2
  __m128 v75; // xmm9
  __m128 v76; // xmm8
  __m128 v77; // xmm3

  v12 = localArmDirA->m_quad;
  v13 = localArmDirB->m_quad;
  v14.m_quad = (__m128)mA->m_invMasses;
  v15.m_quad = (__m128)mB->m_invMasses;
  v16 = _mm_add_ps(_mm_shuffle_ps(v15.m_quad, v15.m_quad, 255), _mm_shuffle_ps(v14.m_quad, v14.m_quad, 255));
  v17 = _mm_mul_ps(v14.m_quad, _mm_mul_ps(_mm_shuffle_ps(v12, v12, 255), fA->m_real));
  v18 = _mm_shuffle_ps(v12, v12, 201);
  v19 = _mm_shuffle_ps(v12, v12, 210);
  v20 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(axes->m_col2.m_quad, axes->m_col2.m_quad, 210), v18),
          _mm_mul_ps(_mm_shuffle_ps(axes->m_col2.m_quad, axes->m_col2.m_quad, 201), v19));
  v21 = _mm_mul_ps(v15.m_quad, _mm_mul_ps(_mm_shuffle_ps(v13, v13, 255), fB->m_real));
  v22 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(axes->m_col0.m_quad, axes->m_col0.m_quad, 210), v18),
          _mm_mul_ps(_mm_shuffle_ps(axes->m_col0.m_quad, axes->m_col0.m_quad, 201), v19));
  v23 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(axes->m_col1.m_quad, axes->m_col1.m_quad, 210), v18),
          _mm_mul_ps(_mm_shuffle_ps(axes->m_col1.m_quad, axes->m_col1.m_quad, 201), v19));
  v24 = _mm_shuffle_ps(v13, v13, 201);
  v25 = _mm_shuffle_ps(v13, v13, 210);
  v26 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(axes->m_col0.m_quad, axes->m_col0.m_quad, 210), v24),
          _mm_mul_ps(_mm_shuffle_ps(axes->m_col0.m_quad, axes->m_col0.m_quad, 201), v25));
  v27 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(axes->m_col1.m_quad, axes->m_col1.m_quad, 210), v24),
          _mm_mul_ps(_mm_shuffle_ps(axes->m_col1.m_quad, axes->m_col1.m_quad, 201), v25));
  v28 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(axes->m_col2.m_quad, axes->m_col2.m_quad, 210), v24),
          _mm_mul_ps(_mm_shuffle_ps(axes->m_col2.m_quad, axes->m_col2.m_quad, 201), v25));
  v29 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64);
  v30 = v29;
  v31 = _mm_xor_ps(v29, rotB->m_vec.m_quad);
  v32 = _mm_xor_ps(v30, rotA->m_vec.m_quad);
  v33 = _mm_mul_ps(v32, v22);
  v34 = _mm_shuffle_ps(v32, v32, 255);
  v35 = _mm_shuffle_ps(v32, v32, 201);
  v36 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v22, v22, 201), v32), _mm_mul_ps(v35, v22));
  v37 = _mm_mul_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v33, v33, 85), _mm_shuffle_ps(v33, v33, 0)),
            _mm_shuffle_ps(v33, v33, 170)),
          v32);
  v38 = _mm_mul_ps(v32, v23);
  v39 = _mm_add_ps(
          _mm_add_ps(v37, _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v34, v34), (__m128)xmmword_141A711B0), v22)),
          _mm_mul_ps(_mm_shuffle_ps(v36, v36, 201), v34));
  UA->m_col0.m_quad = _mm_add_ps(v39, v39);
  v40 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v23, v23, 201), v32), _mm_mul_ps(v35, v23));
  v41 = _mm_mul_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v38, v38, 85), _mm_shuffle_ps(v38, v38, 0)),
            _mm_shuffle_ps(v38, v38, 170)),
          v32);
  v42 = _mm_mul_ps(v32, v20);
  v43 = _mm_add_ps(
          _mm_add_ps(v41, _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v34, v34), (__m128)xmmword_141A711B0), v23)),
          _mm_mul_ps(_mm_shuffle_ps(v40, v40, 201), v34));
  UA->m_col1.m_quad = _mm_add_ps(v43, v43);
  v44 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v20, v20, 201), v32), _mm_mul_ps(v35, v20));
  v45 = _mm_mul_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v42, v42, 85), _mm_shuffle_ps(v42, v42, 0)),
            _mm_shuffle_ps(v42, v42, 170)),
          v32);
  v46 = _mm_shuffle_ps(v31, v31, 201);
  v47 = _mm_mul_ps(v31, v26);
  v48 = _mm_shuffle_ps(v31, v31, 255);
  v49 = _mm_add_ps(
          _mm_add_ps(v45, _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v34, v34), (__m128)xmmword_141A711B0), v20)),
          _mm_mul_ps(_mm_shuffle_ps(v44, v44, 201), v34));
  UA->m_col2.m_quad = _mm_add_ps(v49, v49);
  v50 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v26, v26, 201), v31), _mm_mul_ps(v46, v26));
  v51 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v47, v47, 85), _mm_shuffle_ps(v47, v47, 0)), _mm_shuffle_ps(v47, v47, 170));
  v52 = _mm_mul_ps(v31, v27);
  v53 = _mm_add_ps(
          _mm_add_ps(_mm_mul_ps(v51, v31), _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v48, v48), (__m128)xmmword_141A711B0), v26)),
          _mm_mul_ps(_mm_shuffle_ps(v50, v50, 201), v48));
  v54 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v27, v27, 201), v31), _mm_mul_ps(v46, v27));
  v55.m_quad = _mm_add_ps(v53, v53);
  UB->m_col0 = (hkVector4f)v55.m_quad;
  v56 = _mm_mul_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v52, v52, 85), _mm_shuffle_ps(v52, v52, 0)),
            _mm_shuffle_ps(v52, v52, 170)),
          v31);
  v57 = _mm_mul_ps(v31, v28);
  v58 = _mm_add_ps(
          _mm_add_ps(v56, _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v48, v48), (__m128)xmmword_141A711B0), v27)),
          _mm_mul_ps(_mm_shuffle_ps(v54, v54, 201), v48));
  UB->m_col1.m_quad = _mm_add_ps(v58, v58);
  v59 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v28, v28, 201), v31), _mm_mul_ps(v46, v28));
  v60 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v57, v57, 85), _mm_shuffle_ps(v57, v57, 0)),
                _mm_shuffle_ps(v57, v57, 170)),
              v31),
            _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v48, v48), (__m128)xmmword_141A711B0), v28)),
          _mm_mul_ps(_mm_shuffle_ps(v59, v59, 201), v48));
  UB->m_col2.m_quad = _mm_add_ps(v60, v60);
  v61.m_quad = (__m128)UB->m_col1;
  v62.m_quad = (__m128)UA->m_col1;
  v63.m_quad = (__m128)UA->m_col2;
  v64 = _mm_add_ps(
          _mm_mul_ps(_mm_mul_ps(v55.m_quad, v55.m_quad), v21),
          _mm_mul_ps(_mm_mul_ps(UA->m_col0.m_quad, UA->m_col0.m_quad), v17));
  v65 = _mm_add_ps(
          _mm_mul_ps(_mm_mul_ps(v61.m_quad, v55.m_quad), v21),
          _mm_mul_ps(_mm_mul_ps(UA->m_col0.m_quad, v62.m_quad), v17));
  v66 = _mm_add_ps(
          _mm_mul_ps(_mm_mul_ps(UB->m_col2.m_quad, v55.m_quad), v21),
          _mm_mul_ps(_mm_mul_ps(UA->m_col0.m_quad, v63.m_quad), v17));
  v67 = _mm_add_ps(
          _mm_mul_ps(_mm_mul_ps(v62.m_quad, v62.m_quad), v17),
          _mm_mul_ps(_mm_mul_ps(v61.m_quad, v61.m_quad), v21));
  v68 = _mm_add_ps(
          _mm_mul_ps(_mm_mul_ps(UA->m_col2.m_quad, v62.m_quad), v17),
          _mm_mul_ps(_mm_mul_ps(UB->m_col2.m_quad, v61.m_quad), v21));
  v69 = _mm_add_ps(
          _mm_mul_ps(_mm_mul_ps(v63.m_quad, v63.m_quad), v17),
          _mm_mul_ps(_mm_mul_ps(UB->m_col2.m_quad, UB->m_col2.m_quad), v21));
  v70 = _mm_unpacklo_ps(v64, v65);
  v71 = _mm_movelh_ps(v70, v66);
  v72 = _mm_movehl_ps(v71, v70);
  v73 = _mm_unpacklo_ps(v67, v68);
  v74 = _mm_movelh_ps(v73, v69);
  v75 = _mm_add_ps(_mm_shuffle_ps(_mm_unpackhi_ps(v64, v65), v66, 228), _mm_add_ps(v71, _mm_shuffle_ps(v72, v66, 212)));
  v76 = _mm_add_ps(
          _mm_shuffle_ps(_mm_unpackhi_ps(v67, v68), v69, 228),
          _mm_add_ps(v74, _mm_shuffle_ps(_mm_movehl_ps(v74, v73), v69, 212)));
  v77 = _mm_unpacklo_ps(v76, v76);
  v77.m128_f32[0] = COERCE_FLOAT(_mm_shuffle_ps(v75, v75, 85));
  v76.m128_f32[0] = COERCE_FLOAT(_mm_shuffle_ps(v75, v75, 170));
  outK->m_col2.m_quad = _mm_add_ps(v76, _mm_mul_ps(v16, stru_141A71280.m_quad));
  outK->m_col0.m_quad = _mm_add_ps(_mm_mul_ps(v16, transform.m_quad), v75);
  outK->m_col1.m_quad = _mm_add_ps(v77, _mm_mul_ps(v16, direction.m_quad));
}

// File Line: 295
// RVA: 0xDDF080
void __fastcall hkpAtomSolverFunctions::computeInverseVirtualMass3D(hkQuaternionf *rotA, hkQuaternionf *rotB, hkVector4f *vWorldArmA, hkVector4f *vWorldArmB, hkVector4f *invInertiaA, hkVector4f *invInertiaB, hkSymmetricMatrix3Impl<float> *outK, hkMatrix3f *UA, hkMatrix3f *UB)
{
  __m128 v9; // xmm11
  __m128 v10; // xmm10
  __m128 v11; // xmm2
  __m128 v12; // xmm11
  __m128 v13; // xmm10
  __m128 v14; // xmm1
  __m128 v15; // xmm3
  float v16; // xmm0_4
  __m128 v17; // xmm10
  __m128 v18; // xmm3
  __m128 v19; // xmm1
  __m128 v20; // xmm10
  __m128 v21; // xmm9
  __m128 v22; // xmm10
  __m128 v23; // xmm3
  __m128 v24; // xmm10
  float v25; // xmm0_4
  __m128 v26; // xmm7
  __m128 v27; // xmm2
  __m128 v28; // xmm3
  __m128 v29; // xmm11
  __m128 v30; // xmm8
  __m128 v31; // xmm11
  __m128 v32; // xmm11
  __m128 v33; // xmm5
  __m128 v34; // xmm2
  __m128 v35; // xmm4
  __m128 v36; // xmm3
  __m128 v37; // xmm2
  __m128 v38; // xmm2
  __m128 v39; // xmm3
  __m128 v40; // xmm4
  __m128 v41; // xmm2
  hkVector4f v42; // xmm9
  hkVector4f v43; // xmm7
  hkVector4f v44; // xmm10
  __m128 v45; // xmm5
  __m128 v46; // xmm4
  __m128 v47; // xmm8
  __m128 v48; // xmm0
  __m128 v49; // xmm2
  __m128 v50; // xmm3
  __m128 v51; // xmm1
  __m128 v52; // xmm9
  __m128 v53; // xmm13
  __m128 v54; // xmm8
  __m128 v55; // xmm7
  __m128 v56; // xmm13
  __m128 v57; // xmm1
  __m128 v58; // xmm9
  hkVector4f v59; // xmm7
  __m128 v60; // xmm12
  __m128 v61; // xmm13
  __m128 v62; // xmm12
  __m128 v63; // xmm4
  __m128 v64; // xmm8
  __m128 v65; // xmm5
  __m128 v66; // xmm0
  __m128 v67; // xmm2
  __m128 v68; // xmm8
  __m128 v69; // xmm3
  __m128 v70; // xmm10
  __m128 v71; // xmm7
  __m128 v72; // xmm1
  __m128 v73; // xmm3
  __m128 v74; // xmm9
  __m128 v75; // xmm0
  __m128 v76; // xmm1
  __m128 v77; // xmm9
  __m128 v78; // xmm2

  v9 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64);
  v10 = v9;
  v11 = transform.m_quad;
  v12 = _mm_xor_ps(v9, rotB->m_vec.m_quad);
  v13 = _mm_xor_ps(v10, rotA->m_vec.m_quad);
  v14 = _mm_add_ps(v13, v13);
  v15 = _mm_mul_ps(_mm_shuffle_ps(v13, v13, 65), _mm_shuffle_ps(v14, v14, 165));
  v16 = v13.m128_f32[0] * v14.m128_f32[0];
  v11.m128_f32[0] = (float)(1.0 - (float)(v13.m128_f32[0] * v14.m128_f32[0])) - v15.m128_f32[0];
  v17 = _mm_mul_ps(_mm_shuffle_ps(v13, v13, 254), _mm_shuffle_ps(v14, v14, 26));
  v18 = _mm_xor_ps(v15, (__m128)`hkVector4UtilImpl<float>::convertQuaternionToRotation'::`2'::negateMask0);
  v19 = _mm_add_ps(v12, v12);
  v20 = _mm_xor_ps(v17, (__m128)`hkVector4UtilImpl<float>::convertQuaternionToRotation'::`2'::negateMask1);
  v20.m128_f32[0] = v20.m128_f32[0] + 1.0;
  v21 = _mm_sub_ps(v20, v18);
  v18.m128_f32[0] = v16;
  v22 = _mm_sub_ps(
          _mm_xor_ps(v20, (__m128)`hkVector4UtilImpl<float>::convertQuaternionToRotation'::`2'::negateMask0),
          v18);
  v23 = _mm_mul_ps(_mm_shuffle_ps(v12, v12, 65), _mm_shuffle_ps(v19, v19, 165));
  v24 = _mm_shuffle_ps(v22, v22, 177);
  v25 = v12.m128_f32[0] * v19.m128_f32[0];
  v26 = _mm_shuffle_ps(_mm_movehl_ps(v21, v24), v11, 141);
  v27 = transform.m_quad;
  v27.m128_f32[0] = (float)(1.0 - (float)(v12.m128_f32[0] * v19.m128_f32[0])) - v23.m128_f32[0];
  v28 = _mm_xor_ps(v23, (__m128)`hkVector4UtilImpl<float>::convertQuaternionToRotation'::`2'::negateMask0);
  v29 = _mm_xor_ps(
          _mm_mul_ps(_mm_shuffle_ps(v12, v12, 254), _mm_shuffle_ps(v19, v19, 26)),
          (__m128)`hkVector4UtilImpl<float>::convertQuaternionToRotation'::`2'::negateMask1);
  v29.m128_f32[0] = v29.m128_f32[0] + 1.0;
  v30 = _mm_sub_ps(v29, v28);
  v28.m128_f32[0] = v25;
  v31 = _mm_sub_ps(
          _mm_xor_ps(v29, (__m128)`hkVector4UtilImpl<float>::convertQuaternionToRotation'::`2'::negateMask0),
          v28);
  v32 = _mm_shuffle_ps(v31, v31, 177);
  v33 = _mm_shuffle_ps(_mm_movehl_ps(v30, v32), v27, 141);
  v34 = vWorldArmA->m_quad;
  v35 = _mm_shuffle_ps(v34, v34, 0);
  v36 = _mm_shuffle_ps(vWorldArmA->m_quad, vWorldArmA->m_quad, 85);
  v37 = _mm_shuffle_ps(v34, v34, 170);
  UA->m_col0.m_quad = _mm_sub_ps(_mm_mul_ps(v37, v24), _mm_mul_ps(v26, v36));
  UA->m_col1.m_quad = _mm_sub_ps(_mm_mul_ps(v26, v35), _mm_mul_ps(v37, v21));
  UA->m_col2.m_quad = _mm_sub_ps(_mm_mul_ps(v36, v21), _mm_mul_ps(v35, v24));
  v38 = vWorldArmB->m_quad;
  v39 = _mm_shuffle_ps(vWorldArmB->m_quad, vWorldArmB->m_quad, 85);
  v40 = _mm_shuffle_ps(v38, v38, 0);
  v41 = _mm_shuffle_ps(v38, v38, 170);
  UB->m_col0.m_quad = _mm_sub_ps(_mm_mul_ps(v41, v32), _mm_mul_ps(v33, v39));
  UB->m_col2.m_quad = _mm_sub_ps(_mm_mul_ps(v39, v30), _mm_mul_ps(v40, v32));
  UB->m_col1.m_quad = _mm_sub_ps(_mm_mul_ps(v33, v40), _mm_mul_ps(v41, v30));
  v42.m_quad = (__m128)UA->m_col1;
  v43.m_quad = (__m128)UA->m_col2;
  v44.m_quad = (__m128)UB->m_col1;
  v45 = _mm_mul_ps(UA->m_col1.m_quad, invInertiaA->m_quad);
  v46 = _mm_mul_ps(UA->m_col0.m_quad, invInertiaA->m_quad);
  v47 = _mm_mul_ps(UA->m_col2.m_quad, invInertiaA->m_quad);
  v48 = _mm_mul_ps(v45, v42.m_quad);
  v49 = _mm_mul_ps(v47, v43.m_quad);
  v50 = _mm_mul_ps(v46, UA->m_col0.m_quad);
  v51 = _mm_unpacklo_ps(v50, v48);
  v52 = _mm_mul_ps(v42.m_quad, v46);
  v53 = _mm_movelh_ps(v51, v49);
  v54 = _mm_mul_ps(v47, UA->m_col0.m_quad);
  v55 = _mm_mul_ps(v43.m_quad, v45);
  v56 = _mm_add_ps(v53, _mm_shuffle_ps(_mm_movehl_ps(v53, v51), v49, 212));
  v57 = _mm_unpacklo_ps(v52, v55);
  v58 = _mm_unpackhi_ps(v52, v55);
  v59.m_quad = (__m128)UB->m_col2;
  v60 = _mm_movelh_ps(v57, v54);
  v61 = _mm_add_ps(v56, _mm_shuffle_ps(_mm_unpackhi_ps(v50, v48), v49, 228));
  v62 = _mm_add_ps(_mm_add_ps(v60, _mm_shuffle_ps(_mm_movehl_ps(v60, v57), v54, 212)), _mm_shuffle_ps(v58, v54, 228));
  v63 = _mm_mul_ps(UB->m_col0.m_quad, invInertiaB->m_quad);
  v64 = _mm_mul_ps(UB->m_col2.m_quad, invInertiaB->m_quad);
  v65 = _mm_mul_ps(UB->m_col1.m_quad, invInertiaB->m_quad);
  v66 = _mm_mul_ps(v65, v44.m_quad);
  v67 = _mm_mul_ps(v64, v59.m_quad);
  v68 = _mm_mul_ps(v64, UB->m_col0.m_quad);
  v69 = _mm_mul_ps(v63, UB->m_col0.m_quad);
  v70 = _mm_mul_ps(v44.m_quad, v63);
  v71 = _mm_mul_ps(v59.m_quad, v65);
  v72 = _mm_unpacklo_ps(v69, v66);
  v73 = _mm_unpackhi_ps(v69, v66);
  v74 = _mm_movelh_ps(v72, v67);
  v75 = _mm_shuffle_ps(_mm_movehl_ps(v74, v72), v67, 212);
  v76 = _mm_unpacklo_ps(v70, v71);
  v77 = _mm_add_ps(_mm_add_ps(_mm_add_ps(v74, v75), _mm_shuffle_ps(v73, v67, 228)), v61);
  v78 = _mm_movelh_ps(v76, v68);
  outK->m_diag.m_quad = _mm_add_ps(
                          _mm_add_ps(
                            _mm_shuffle_ps(invInertiaB->m_quad, invInertiaB->m_quad, 255),
                            _mm_shuffle_ps(invInertiaA->m_quad, invInertiaA->m_quad, 255)),
                          v77);
  outK->m_offDiag.m_quad = _mm_add_ps(
                             _mm_add_ps(
                               _mm_add_ps(v78, _mm_shuffle_ps(_mm_movehl_ps(v78, v76), v68, 212)),
                               _mm_shuffle_ps(_mm_unpackhi_ps(v70, v71), v68, 228)),
                             v62);
}

// File Line: 325
// RVA: 0xDE3D40
void __fastcall hkpAtomSolverFunctions::solveLinear3D<hkpVelocityAccumulator restrict *>(hkMatrix3f *axes, hkSimdFloat32 *fA, hkSimdFloat32 *fB, hkVector4f *armDirA, hkVector4f *armDirB, hkVector4f *bias, hkSimdFloat32 *maxLinearImpulse, hkSimdFloat32 *maxAngularImpulse, hkQuaternionf *rotA, hkQuaternionf *rotB, hkpVelocityAccumulator **regA, hkpVelocityAccumulator **regB, hkpSolverElemTemp *temps)
{
  hkSimdFloat32 *v13; // rsi
  hkSimdFloat32 *v14; // rdi
  hkMatrix3f *v15; // rbx
  __m128 v16; // xmm0
  __m128 v17; // xmm7
  __m128 v18; // xmm2
  __m128 v19; // xmm6
  __m128 v20; // xmm0
  __m128 v21; // xmm6
  __m128 v22; // xmm4
  __m128 v23; // xmm7
  __m128 v24; // xmm5
  __m128 v25; // xmm3
  __m128 v26; // xmm1
  __m128 v27; // xmm4
  __m128 v28; // xmm0
  __m128 v29; // xmm5
  __m128 v30; // xmm12
  __m128 v31; // xmm7
  __m128 v32; // xmm3
  __m128 v33; // xmm2
  __m128 v34; // xmm4
  __m128 v35; // xmm1
  __m128 v36; // xmm0
  __m128 v37; // xmm4
  __m128 v38; // xmm2
  __m128 v39; // xmm0
  __m128 v40; // xmm2
  __m128 v41; // xmm5
  __m128 v42; // xmm4
  __m128 v43; // xmm5
  __m128 v44; // xmm2
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
  hkSimdFloat32 scale; // [rsp+60h] [rbp-118h]
  hkMatrix3f outK; // [rsp+70h] [rbp-108h]
  hkMatrix3f UA; // [rsp+A0h] [rbp-D8h]
  __m128 UB; // [rsp+D0h] [rbp-A8h]
  __m128 v68; // [rsp+E0h] [rbp-98h]
  __m128 v69; // [rsp+F0h] [rbp-88h]

  v13 = fB;
  v14 = fA;
  v15 = axes;
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
    (hkMatrix3f *)&UB);
  v16 = _mm_shuffle_ps(outK.m_col0.m_quad, outK.m_col0.m_quad, 0);
  scale.m_real = _mm_min_ps(
                   _mm_max_ps(_mm_andnot_ps(_mm_cmpeqps((__m128)0i64, v16), _mm_rcp_ps(v16)), query.m_quad),
                   (__m128)xmmword_141A712B0);
  hkMatrix3f::mul(&outK, &scale);
  v17 = _mm_shuffle_ps(outK.m_col1.m_quad, outK.m_col1.m_quad, 201);
  v18 = _mm_shuffle_ps(outK.m_col2.m_quad, outK.m_col2.m_quad, 201);
  v19 = _mm_sub_ps(_mm_mul_ps(v18, outK.m_col1.m_quad), _mm_mul_ps(v17, outK.m_col2.m_quad));
  v20 = _mm_shuffle_ps(outK.m_col0.m_quad, outK.m_col0.m_quad, 201);
  v21 = _mm_shuffle_ps(v19, v19, 201);
  v22 = _mm_mul_ps(outK.m_col0.m_quad, v21);
  v23 = _mm_sub_ps(_mm_mul_ps(v17, outK.m_col0.m_quad), _mm_mul_ps(v20, outK.m_col1.m_quad));
  v24 = _mm_sub_ps(_mm_mul_ps(v20, outK.m_col2.m_quad), _mm_mul_ps(v18, outK.m_col0.m_quad));
  v25 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)), _mm_shuffle_ps(v22, v22, 170));
  v26 = _mm_rcp_ps(v25);
  v27 = _mm_and_ps(
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v26, v25)), v26),
          _mm_cmpltps(*(__m128 *)&epsilon, v25));
  v28 = _mm_mul_ps(v27, _mm_shuffle_ps(v24, v24, 201));
  v29 = _mm_max_ps(maxLinearImpulse->m_real, *(__m128 *)&epsilon);
  v30 = _mm_mul_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(bias->m_quad, bias->m_quad, 85), v28),
              _mm_mul_ps(_mm_shuffle_ps(bias->m_quad, bias->m_quad, 0), _mm_mul_ps(v27, v21))),
            _mm_mul_ps(_mm_shuffle_ps(bias->m_quad, bias->m_quad, 170), _mm_mul_ps(v27, _mm_shuffle_ps(v23, v23, 201)))),
          scale.m_real);
  v31 = _mm_mul_ps(v30, v30);
  v32 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v31, v31, 85), _mm_shuffle_ps(v31, v31, 0)), _mm_shuffle_ps(v31, v31, 170));
  v33 = _mm_rsqrt_ps(v32);
  v34 = _mm_andnot_ps(
          _mm_cmpleps(v32, (__m128)0i64),
          _mm_mul_ps(
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v33, v32), v33)),
              _mm_mul_ps(*(__m128 *)_xmm, v33)),
            v32));
  v35 = _mm_rcp_ps(v34);
  v36 = _mm_mul_ps(v35, v34);
  v37 = _mm_cmpleps(v34, v29);
  v38 = _mm_sub_ps((__m128)_xmm, v36);
  v39 = _mm_and_ps(v30, v37);
  v40 = _mm_mul_ps(_mm_mul_ps(v38, v35), v29);
  v41 = v37;
  v42 = _mm_max_ps(maxAngularImpulse->m_real, *(__m128 *)&epsilon);
  v43 = _mm_or_ps(_mm_andnot_ps(v41, _mm_mul_ps(v40, v30)), v39);
  v44 = v32;
  v45 = _mm_rsqrt_ps(v44);
  v46 = *regA;
  v47 = *regB;
  v48 = _mm_andnot_ps(
          _mm_cmpleps(v44, (__m128)0i64),
          _mm_mul_ps(
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v45, v44), v45)),
              _mm_mul_ps(*(__m128 *)_xmm, v45)),
            v44));
  v49 = _mm_rcp_ps(v48);
  v50 = _mm_mul_ps(v49, v48);
  v51 = _mm_cmpleps(v48, v42);
  v52 = _mm_or_ps(
          _mm_andnot_ps(v51, _mm_mul_ps(_mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, v50), v49), v42), v30)),
          _mm_and_ps(v30, v51));
  v53 = _mm_shuffle_ps(v52, v52, 0);
  v54 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v43, v43, 85), v15->m_col1.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v43, v43, 0), v15->m_col0.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v43, v43, 170), v15->m_col2.m_quad));
  v55 = _mm_shuffle_ps(v52, v52, 85);
  v56 = _mm_shuffle_ps(v52, v52, 170);
  v57 = _mm_add_ps(_mm_mul_ps(UB, v53), _mm_mul_ps(v68, v55));
  v58 = _mm_mul_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(UA.m_col0.m_quad, v53), _mm_mul_ps(UA.m_col1.m_quad, v55)),
            _mm_mul_ps(UA.m_col2.m_quad, v56)),
          v14->m_real);
  v59 = _mm_add_ps(
          _mm_movelh_ps(
            (__m128)*(unsigned __int64 *)&temps->m_impulseApplied,
            (__m128)LODWORD(temps[2].m_impulseApplied)),
          v30);
  v60 = _mm_mul_ps(_mm_add_ps(v57, _mm_mul_ps(v69, v56)), v13->m_real);
  v61 = _mm_add_ps(_mm_mul_ps(v58, (*regA)->m_invMasses.m_quad), (*regA)->m_angularVel.m_quad);
  *(_QWORD *)&temps->m_impulseApplied = v59.m128_u64[0];
  v62 = _mm_mul_ps(v60, v47->m_invMasses.m_quad);
  LODWORD(temps[2].m_impulseApplied) = (unsigned __int128)_mm_movehl_ps(v59, v59);
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
void __fastcall hkpAtomSolverFunctions::getFuturePositions<hkpVelocityAccumulator,hkpSolverInfo>(hkpSolverInfo *solverInfo, hkpVelocityAccumulator *mA, hkVector4f *comAInWorld, hkQuaternionf *coreQworldA, hkpVelocityAccumulator *mB, hkVector4f *comBInWorld, hkQuaternionf *coreQworldB, hkQTransformf *futurePosOutA, hkQTransformf *futurePosOutB)
{
  __m128 v9; // xmm2
  __m128 v10; // xmm3
  __m128 v11; // xmm0
  __m128 v12; // xmm1
  __m128 v13; // xmm2
  hkVector4f v14; // xmm1
  hkQuaternionf *v15; // rax
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
  v15 = coreQworldB;
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
          _mm_mul_ps(_mm_shuffle_ps(v15->m_vec.m_quad, v15->m_vec.m_quad, 201), v20),
          _mm_mul_ps(_mm_shuffle_ps(v20, v20, 201), coreQworldB->m_vec.m_quad));
  v27 = _mm_mul_ps(coreQworldB->m_vec.m_quad, v20);
  v28 = _mm_sub_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v15->m_vec.m_quad, v15->m_vec.m_quad, 255), v20),
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
void __fastcall hkpAtomSolverFunctions::solveStableBallSocket<hkpVelocityAccumulator,hkpSolverInfo,hkSolverStepTemp>(hkpSolverInfo *solverInfo, hkSolverStepTemp *temp, hkpStableBallSocketSchema *schema, hkpVelocityAccumulator *mA, hkpVelocityAccumulator *mB)
{
  hkpStableBallSocketSchema *v5; // rbx
  __m128 v6; // xmm9
  __m128 v7; // xmm7
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
  __m128 v21; // xmm3
  __m128 v22; // xmm7
  __m128 v23; // xmm0
  char fB[24]; // [rsp+70h] [rbp-88h]
  hkSimdFloat32 maxLinearImpulse; // [rsp+88h] [rbp-70h]
  hkSimdFloat32 fA; // [rsp+98h] [rbp-60h]
  hkVector4f armDirB; // [rsp+A8h] [rbp-50h]
  hkQTransformf futurePosOutB; // [rsp+B8h] [rbp-40h]
  hkVector4f bias; // [rsp+D8h] [rbp-20h]
  hkQTransformf futurePosOutA; // [rsp+E8h] [rbp-10h]
  hkSimdFloat32 maxAngularImpulse; // [rsp+108h] [rbp+10h]
  hkMatrix3f axes; // [rsp+118h] [rbp+20h]
  hkpVelocityAccumulator *regA; // [rsp+1B0h] [rbp+B8h]
  hkpVelocityAccumulator *regB; // [rsp+1B8h] [rbp+C0h]

  regB = mA;
  v5 = schema;
  hkpAtomSolverFunctions::getFuturePositions<hkpVelocityAccumulator,hkpSolverInfo>(
    solverInfo,
    mA,
    &mA->m_scratch3,
    (hkQuaternionf *)&mA->m_scratch2,
    mA,
    &mA->m_scratch3,
    (hkQuaternionf *)&mA->m_scratch2,
    &futurePosOutA,
    (hkQTransformf *)((char *)&futurePosOutB + 8));
  v6 = v5->m_armDirA.m_quad;
  v7 = v5->m_armDirB.m_quad;
  v8 = _mm_mul_ps(v5->m_armDirA.m_quad, futurePosOutA.m_rotation.m_vec.m_quad);
  v9 = _mm_sub_ps(
         _mm_mul_ps(_mm_shuffle_ps(v6, v6, 201), futurePosOutA.m_rotation.m_vec.m_quad),
         _mm_mul_ps(
           _mm_shuffle_ps(futurePosOutA.m_rotation.m_vec.m_quad, futurePosOutA.m_rotation.m_vec.m_quad, 201),
           v6));
  v10 = _mm_shuffle_ps(futurePosOutA.m_rotation.m_vec.m_quad, futurePosOutA.m_rotation.m_vec.m_quad, 255);
  v11 = _mm_mul_ps(
          _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)), _mm_shuffle_ps(v8, v8, 170)),
          futurePosOutA.m_rotation.m_vec.m_quad);
  v12 = _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v10, v10), (__m128)xmmword_141A711B0), v6);
  v13 = _mm_mul_ps(v5->m_armDirB.m_quad, futurePosOutB.m_rotation.m_vec.m_quad);
  v14 = _mm_shuffle_ps(v6, v6, 255);
  v15 = _mm_add_ps(_mm_add_ps(v11, v12), _mm_mul_ps(_mm_shuffle_ps(v9, v9, 201), v10));
  v16 = _mm_add_ps(v15, v15);
  v17 = _mm_shuffle_ps(futurePosOutB.m_rotation.m_vec.m_quad, futurePosOutB.m_rotation.m_vec.m_quad, 255);
  v18 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v7, v7, 201), futurePosOutB.m_rotation.m_vec.m_quad),
          _mm_mul_ps(
            _mm_shuffle_ps(futurePosOutB.m_rotation.m_vec.m_quad, futurePosOutB.m_rotation.m_vec.m_quad, 201),
            v7));
  v19 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)),
                _mm_shuffle_ps(v13, v13, 170)),
              futurePosOutB.m_rotation.m_vec.m_quad),
            _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v17, v17), (__m128)xmmword_141A711B0), v7)),
          _mm_mul_ps(_mm_shuffle_ps(v18, v18, 201), v17));
  v20 = _mm_add_ps(v19, v19);
  v21 = v5->m_data1.m_quad;
  v22 = _mm_shuffle_ps(v7, v7, 255);
  axes.m_col1 = (hkVector4f)direction.m_quad;
  bias.m_quad = _mm_mul_ps(
                  _mm_add_ps(
                    _mm_sub_ps(_mm_mul_ps(v20, v22), _mm_mul_ps(v16, v14)),
                    _mm_sub_ps(futurePosOutB.m_translation.m_quad, futurePosOutA.m_translation.m_quad)),
                  _mm_shuffle_ps(v21, v21, 0));
  axes.m_col0 = (hkVector4f)transform.m_quad;
  fA.m_real = _mm_shuffle_ps(v21, v21, 170);
  axes.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  *(__m128 *)&fB[8] = _mm_shuffle_ps(v21, v21, 255);
  maxAngularImpulse.m_real = _mm_shuffle_ps(v21, v21, 85);
  *(__m128 *)fB = _mm_shuffle_ps(v16, _mm_unpackhi_ps(v16, v14), 196);
  v23 = _mm_shuffle_ps(v5->m_data0.m_quad, v5->m_data0.m_quad, 170);
  armDirB.m_quad = _mm_shuffle_ps(v20, _mm_unpackhi_ps(v20, v22), 196);
  maxLinearImpulse.m_real = v23;
  hkpAtomSolverFunctions::solveLinear3D<hkpVelocityAccumulator restrict *>(
    &axes,
    &fA,
    (hkSimdFloat32 *)&fB[8],
    (hkVector4f *)fB,
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
void __fastcall hkpAtomSolverFunctions::solveStableStiffSpring<hkpVelocityAccumulator,hkpSolverInfo,hkSolverStepTemp,hkpStableStiffSpringSchema>(hkpSolverInfo *info, hkSolverStepTemp *temp, hkpStableStiffSpringSchema *schema, hkpVelocityAccumulator *regA, hkpVelocityAccumulator *regB, hkpSolverElemTemp *temps)
{
  hkpVelocityAccumulator *v6; // rdi
  hkpStableStiffSpringSchema *v7; // rbx
  __m128 v8; // xmm6
  __m128 v9; // xmm8
  __m128 v10; // xmm3
  __m128 v11; // xmm1
  __m128 v12; // xmm14
  __m128 v13; // xmm15
  __m128 v14; // xmm2
  __m128 v15; // xmm1
  __m128 v16; // xmm2
  __m128 v17; // xmm3
  __m128 v18; // xmm6
  __m128 v19; // xmm11
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
  __m128 v34; // xmm3
  __m128 v35; // xmm13
  __m128 v36; // xmm1
  __m128 v37; // xmm2
  __m128 v38; // xmm12
  __m128 v39; // xmm5
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
  hkQTransformf futurePosOutB; // [rsp+70h] [rbp-E8h]
  hkQTransformf futurePosOutA; // [rsp+90h] [rbp-C8h]

  v6 = regA;
  v7 = schema;
  hkpAtomSolverFunctions::getFuturePositions<hkpVelocityAccumulator,hkpSolverInfo>(
    info,
    v6,
    &v6->m_scratch3,
    (hkQuaternionf *)&regA->m_scratch2,
    regB,
    &regB->m_scratch3,
    (hkQuaternionf *)&regB->m_scratch2,
    &futurePosOutA,
    &futurePosOutB);
  v8 = v7->m_armVecA.m_quad;
  v9 = v7->m_armVecB.m_quad;
  v66 = _mm_shuffle_ps(futurePosOutA.m_rotation.m_vec.m_quad, futurePosOutA.m_rotation.m_vec.m_quad, 201);
  v10 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v8, v8, 201), futurePosOutA.m_rotation.m_vec.m_quad), _mm_mul_ps(v66, v8));
  v11 = _mm_mul_ps(futurePosOutA.m_rotation.m_vec.m_quad, v8);
  v12 = _mm_shuffle_ps(futurePosOutA.m_rotation.m_vec.m_quad, futurePosOutA.m_rotation.m_vec.m_quad, 255);
  v13 = _mm_shuffle_ps(futurePosOutB.m_rotation.m_vec.m_quad, futurePosOutB.m_rotation.m_vec.m_quad, 255);
  v14 = _mm_mul_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)),
            _mm_shuffle_ps(v11, v11, 170)),
          futurePosOutA.m_rotation.m_vec.m_quad);
  v15 = _mm_mul_ps(futurePosOutB.m_rotation.m_vec.m_quad, v9);
  v16 = _mm_add_ps(
          _mm_add_ps(v14, _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v12, v12), (__m128)xmmword_141A711B0), v8)),
          _mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), v12));
  v67 = _mm_shuffle_ps(futurePosOutB.m_rotation.m_vec.m_quad, futurePosOutB.m_rotation.m_vec.m_quad, 201);
  v17 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v9, v9, 201), futurePosOutB.m_rotation.m_vec.m_quad), _mm_mul_ps(v67, v9));
  v18 = _mm_mul_ps(_mm_shuffle_ps(v8, v8, 255), _mm_add_ps(v16, v16));
  v19 = v7->m_data0.m_quad;
  v20 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)),
                _mm_shuffle_ps(v15, v15, 170)),
              futurePosOutB.m_rotation.m_vec.m_quad),
            _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v13, v13), (__m128)xmmword_141A711B0), v9)),
          _mm_mul_ps(_mm_shuffle_ps(v17, v17, 201), v13));
  v21 = _mm_mul_ps(_mm_shuffle_ps(v9, v9, 255), _mm_add_ps(v20, v20));
  v22 = _mm_sub_ps(
          _mm_add_ps(futurePosOutA.m_translation.m_quad, v18),
          _mm_add_ps(futurePosOutB.m_translation.m_quad, v21));
  v23 = _mm_mul_ps(v22, v22);
  v24 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v23, v23, 85), _mm_shuffle_ps(v23, v23, 0)), _mm_shuffle_ps(v23, v23, 170));
  v25 = _mm_rsqrt_ps(v24);
  v26 = _mm_cmpltps(v24, (__m128)xmmword_141A712D0);
  v27 = _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v25, v24), v25));
  v28 = _mm_mul_ps(*(__m128 *)_xmm, v25);
  v29 = _mm_and_ps(v26, transform.m_quad);
  v30 = _mm_mul_ps(v27, v28);
  v31 = _mm_andnot_ps(v26, _mm_mul_ps(v30, v22));
  v32 = _mm_andnot_ps(v26, _mm_mul_ps(v30, v24));
  v33 = _mm_shuffle_ps(v19, v19, 85);
  v34 = _mm_cmpltps(v32, v33);
  v35 = _mm_or_ps(v31, v29);
  v36 = _mm_shuffle_ps(v19, v19, 170);
  v37 = _mm_cmpltps(v36, v32);
  v38 = _mm_sub_ps(
          _mm_or_ps(_mm_andnot_ps(v34, _mm_or_ps(_mm_and_ps(v37, v36), _mm_andnot_ps(v37, v32))), _mm_and_ps(v34, v33)),
          v32);
  if ( v38.m128_f32[0] != 0.0 )
  {
    v39 = v6->m_invMasses.m_quad;
    v40 = _mm_shuffle_ps(v35, v35, 201);
    v41 = _mm_shuffle_ps(v18, v18, 201);
    v42 = _mm_mul_ps(v40, v18);
    v43.m_quad = (__m128)regB->m_invMasses;
    v44 = _mm_sub_ps(v42, _mm_mul_ps(v41, v35));
    v45 = _mm_shuffle_ps(v44, v44, 201);
    v46 = _mm_sub_ps(_mm_mul_ps(v40, v21), _mm_mul_ps(_mm_shuffle_ps(v21, v21, 201), v35));
    v47 = _mm_shuffle_ps(v46, v46, 201);
    v48 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v45, v45), v39), _mm_mul_ps(_mm_mul_ps(v47, v47), v43.m_quad));
    v49 = _mm_shuffle_ps(
            v48,
            _mm_unpackhi_ps(v48, _mm_max_ps(_mm_add_ps(v39, v43.m_quad), (__m128)xmmword_141A712D0)),
            196);
    v50 = _mm_add_ps(_mm_shuffle_ps(v49, v49, 78), v49);
    v51 = _mm_add_ps(_mm_shuffle_ps(v50, v50, 177), v50);
    v52 = _mm_rcp_ps(v51);
    v53 = _mm_mul_ps(
            _mm_mul_ps(_mm_shuffle_ps(v19, v19, 255), v38),
            _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v51, v52)), v52));
    v54 = _mm_mul_ps(v45, v53);
    v55 = _mm_mul_ps(v47, v53);
    v56 = _mm_mul_ps(v35, v53);
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
    v6->m_angularVel.m_quad = _mm_add_ps(_mm_mul_ps(_mm_add_ps(v61, v61), v39), v6->m_angularVel.m_quad);
    v64 = _mm_add_ps(
            _mm_add_ps(v63, _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v13, v13), (__m128)xmmword_141A711B0), v55)),
            _mm_mul_ps(_mm_shuffle_ps(v62, v62, 201), v13));
    v65.m_quad = _mm_sub_ps(regB->m_angularVel.m_quad, _mm_mul_ps(_mm_add_ps(v64, v64), v43.m_quad));
    v6->m_linearVel.m_quad = _mm_add_ps(
                               _mm_mul_ps(_mm_shuffle_ps(v6->m_invMasses.m_quad, v6->m_invMasses.m_quad, 255), v56),
                               v6->m_linearVel.m_quad);
    regB->m_angularVel = (hkVector4f)v65.m_quad;
    regB->m_linearVel.m_quad = _mm_sub_ps(
                                 regB->m_linearVel.m_quad,
                                 _mm_mul_ps(
                                   _mm_shuffle_ps(regB->m_invMasses.m_quad, regB->m_invMasses.m_quad, 255),
                                   v56));
    temps->m_impulseApplied = COERCE_FLOAT(
                                _mm_shuffle_ps(
                                  (__m128)LODWORD(temps->m_impulseApplied),
                                  (__m128)LODWORD(temps->m_impulseApplied),
                                  0))
                            + v53.m128_f32[0];
  }
}

// File Line: 632
// RVA: 0xDE4270
void __fastcall hkpAtomSolverFunctions::solveQuatAngular3D<hkpVelocityAccumulator>(hkSimdFloat32 *erp, hkSimdFloat32 *maxImpulse, hkQuaternionf *lA, hkQuaternionf *lB, hkQuaternionf *qA, hkQuaternionf *qB, hkpVelocityAccumulator *regA, hkpVelocityAccumulator *regB, hkpSolverElemTemp *temps)
{
  hkSimdFloat32 *v9; // rsi
  __m128 v10; // xmm4
  __m128 v11; // xmm5
  __m128 v12; // xmm3
  __m128 v13; // xmm7
  __m128 v14; // xmm8
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
  __m128 v31; // ST30_16
  __m128 v32; // xmm13
  __m128 v33; // xmm14
  __m128 v34; // xmm2
  __m128 v35; // xmm12
  __m128 v36; // xmm8
  __m128 v37; // xmm1
  __m128 v38; // xmm3
  __m128 v39; // xmm3
  __m128 v40; // xmm8
  __m128 v41; // xmm9
  __m128 v42; // xmm8
  __m128 v43; // xmm10
  __m128 v44; // xmm0
  __m128 v45; // xmm2
  __m128 v46; // xmm3
  __m128 v47; // xmm1
  __m128 v48; // xmm8
  __m128 v49; // xmm5
  __m128 v50; // ST20_16
  __m128 v51; // xmm0
  __m128 v52; // xmm10
  __m128 v53; // xmm5
  __m128 v54; // xmm7
  __m128 v55; // xmm6
  __m128 v56; // xmm1
  __m128 v57; // ST40_16
  __m128 v58; // xmm4
  __m128 v59; // xmm9
  __m128 v60; // xmm0
  __m128 v61; // xmm4
  __m128 v62; // xmm1
  __m128 v63; // xmm2
  __m128 v64; // ST20_16
  __m128 v65; // ST40_16
  __m128 v66; // xmm0
  __m128 v67; // xmm8
  __m128 v68; // ST30_16
  __m128 v69; // xmm9
  __m128 v70; // xmm14
  __m128 v71; // xmm1
  __m128 v72; // xmm2
  __m128 v73; // xmm3
  __m128 v74; // xmm3
  __m128 v75; // xmm14
  __m128 v76; // xmm12
  __m128 v77; // xmm14
  __m128 v78; // xmm13
  __m128 v79; // xmm11
  __m128 v80; // xmm14
  __m128 v81; // xmm0
  __m128 v82; // xmm7
  __m128 v83; // xmm1
  __m128 v84; // xmm13
  __m128 v85; // xmm8
  __m128 v86; // xmm6
  __m128 v87; // xmm5
  __m128 v88; // xmm0
  __m128 v89; // xmm9
  __m128 v90; // xmm1
  __m128 v91; // xmm11
  __m128 v92; // xmm4
  __m128 v93; // xmm12
  __m128 v94; // xmm7
  __m128 v95; // xmm14
  __m128 v96; // xmm0
  __m128 v97; // xmm2
  hkVector4f v98; // xmm3
  __m128 v99; // xmm2
  __m128 v100; // xmm0
  __m128 v101; // xmm12
  __m128 v102; // xmm13
  __m128 v103; // xmm11
  hkVector4f v104; // xmm4
  __m128 v105; // xmm10
  __m128 v106; // xmm8
  __m128 v107; // xmm2
  __m128 v108; // xmm6
  __m128 v109; // xmm7
  __m128 v110; // xmm1
  __m128 v111; // xmm5
  __m128 v112; // xmm0
  __m128 v113; // xmm8
  __m128 v114; // xmm4
  __m128 v115; // xmm3
  __m128 v116; // xmm0
  __m128 v117; // xmm2
  hkVector4f v118; // xmm7
  hkVector4f v119; // xmm1
  __m128 v120; // xmm8
  __m128 v121; // xmm3
  __m128 v122; // xmm2
  __m128 v123; // xmm7
  __m128 v124; // xmm1
  __m128 v125; // xmm7
  __m128 v126; // xmm5
  __m128 v127; // xmm8
  __m128 v128; // xmm6
  __m128 v129; // xmm3
  __m128 v130; // xmm1
  __m128 v131; // xmm0
  __m128 v132; // xmm4
  __m128 v133; // xmm6
  __m128 v134; // xmm7
  __m128 v135; // xmm1
  __m128 v136; // xmm3
  __m128 v137; // xmm1
  __m128 v138; // xmm4
  __m128 v139; // xmm1
  __m128 v140; // xmm0
  __m128 v141; // xmm4
  __m128 v142; // xmm3
  __m128 v143; // xmm0
  __m128 v144; // xmm1
  __m128 v145; // xmm2
  __m128 v146; // xmm13
  __m128 v147; // xmm4
  __m128 v148; // xmm12
  __m128 v149; // xmm10
  hkVector4f v150; // xmm0
  __m128 v151; // xmm1
  hkVector4f v152; // xmm0
  hkSimdFloat32 scale; // [rsp+50h] [rbp-F8h]
  __m128 v154; // [rsp+60h] [rbp-E8h]
  hkMatrix3f v155; // [rsp+70h] [rbp-D8h]

  v9 = maxImpulse;
  v10 = _mm_shuffle_ps(lA->m_vec.m_quad, lA->m_vec.m_quad, 255);
  v11 = _mm_mul_ps(qA->m_vec.m_quad, lA->m_vec.m_quad);
  v12 = _mm_shuffle_ps(qA->m_vec.m_quad, qA->m_vec.m_quad, 255);
  v13 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(lA->m_vec.m_quad, lA->m_vec.m_quad, 201), qA->m_vec.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(qA->m_vec.m_quad, qA->m_vec.m_quad, 201), lA->m_vec.m_quad));
  v14 = lB->m_vec.m_quad;
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
  v154 = _mm_mul_ps(_mm_sub_ps((__m128)0i64, erp->m_real), v30);
  v31 = _mm_xor_ps(
          (__m128)_mm_slli_epi32(_mm_srli_epi32((__m128i)xmmword_141A9E9C0, 0x1Fu), 0x1Fu),
          _mm_shuffle_ps(v30, v30, 27));
  v32 = _mm_xor_ps(
          (__m128)_mm_slli_epi32(_mm_srli_epi32((__m128i)xmmword_141A9E9E0, 0x1Fu), 0x1Fu),
          _mm_shuffle_ps(v30, v30, 78));
  v33 = _mm_xor_ps(
          (__m128)_mm_slli_epi32(_mm_srli_epi32((__m128i)xmmword_141A9E9B0, 0x1Fu), 0x1Fu),
          _mm_shuffle_ps(v30, v30, 177));
  v34 = transform.m_quad;
  v35 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64);
  v36 = _mm_xor_ps(v14, v35);
  v37 = _mm_add_ps(v36, v36);
  v38 = _mm_mul_ps(_mm_shuffle_ps(v36, v36, 65), _mm_shuffle_ps(v37, v37, 165));
  v29.m128_f32[0] = v36.m128_f32[0] * v37.m128_f32[0];
  v34.m128_f32[0] = (float)(1.0 - (float)(v36.m128_f32[0] * v37.m128_f32[0])) - v38.m128_f32[0];
  v39 = _mm_xor_ps(v38, (__m128)`hkVector4UtilImpl<float>::convertQuaternionToRotation'::`2'::negateMask0);
  v40 = _mm_xor_ps(
          _mm_mul_ps(_mm_shuffle_ps(v36, v36, 254), _mm_shuffle_ps(v37, v37, 26)),
          (__m128)`hkVector4UtilImpl<float>::convertQuaternionToRotation'::`2'::negateMask1);
  v40.m128_f32[0] = v40.m128_f32[0] + 1.0;
  v41 = _mm_sub_ps(v40, v39);
  v39.m128_f32[0] = v29.m128_f32[0];
  v42 = _mm_sub_ps(
          _mm_xor_ps(v40, (__m128)`hkVector4UtilImpl<float>::convertQuaternionToRotation'::`2'::negateMask0),
          v39);
  scale.m_real = _mm_shuffle_ps(v42, v42, 177);
  v43 = _mm_shuffle_ps(_mm_movehl_ps(v41, scale.m_real), v34, 141);
  v44 = _mm_mul_ps(v31, scale.m_real);
  v45 = _mm_mul_ps(v31, v41);
  v46 = _mm_mul_ps(v32, v41);
  v47 = _mm_unpacklo_ps(v45, v44);
  v48 = _mm_mul_ps(v43, v31);
  v49 = v43;
  v50 = _mm_unpackhi_ps(v45, v44);
  v51 = _mm_mul_ps(v32, scale.m_real);
  v52 = _mm_mul_ps(v43, v33);
  v53 = _mm_mul_ps(v49, v32);
  v54 = _mm_movelh_ps(v47, v48);
  v55 = _mm_movehl_ps(v54, v47);
  v56 = _mm_unpacklo_ps(v46, v51);
  v57 = _mm_unpackhi_ps(v46, v51);
  v58 = _mm_movelh_ps(v56, v53);
  v59 = _mm_mul_ps(v33, v41);
  v60 = _mm_mul_ps(v33, scale.m_real);
  v61 = _mm_add_ps(v58, _mm_shuffle_ps(_mm_movehl_ps(v58, v56), v53, 212));
  v62 = _mm_unpacklo_ps(v59, v60);
  v63 = _mm_movelh_ps(v62, v52);
  scale.m_real = _mm_mul_ps(
                   _mm_add_ps(
                     _mm_shuffle_ps(_mm_unpackhi_ps(v59, v60), v52, 228),
                     _mm_add_ps(v63, _mm_shuffle_ps(_mm_movehl_ps(v63, v62), v52, 212))),
                   (__m128)xmmword_141A711B0);
  v64 = _mm_mul_ps(
          _mm_add_ps(_mm_shuffle_ps(v50, v48, 228), _mm_add_ps(v54, _mm_shuffle_ps(v55, v48, 212))),
          (__m128)xmmword_141A711B0);
  v65 = _mm_mul_ps(_mm_add_ps(_mm_shuffle_ps(v57, v53, 228), v61), (__m128)xmmword_141A711B0);
  v66 = _mm_unpacklo_ps(v31, v32);
  v67 = _mm_movelh_ps(v66, v33);
  v68 = _mm_shuffle_ps(_mm_unpackhi_ps(v31, v32), v33, 228);
  v69 = _mm_shuffle_ps(_mm_movehl_ps(v67, v66), v33, 212);
  v70 = _mm_xor_ps(lA->m_vec.m_quad, v35);
  v71 = _mm_add_ps(v70, v70);
  v72 = transform.m_quad;
  v73 = _mm_mul_ps(_mm_shuffle_ps(v71, v71, 165), _mm_shuffle_ps(v70, v70, 65));
  v66.m128_f32[0] = v70.m128_f32[0] * v71.m128_f32[0];
  v72.m128_f32[0] = (float)(1.0 - (float)(v70.m128_f32[0] * v71.m128_f32[0])) - v73.m128_f32[0];
  v74 = _mm_xor_ps(v73, (__m128)`hkVector4UtilImpl<float>::convertQuaternionToRotation'::`2'::negateMask0);
  v75 = _mm_xor_ps(
          _mm_mul_ps(_mm_shuffle_ps(v70, v70, 254), _mm_shuffle_ps(v71, v71, 26)),
          (__m128)`hkVector4UtilImpl<float>::convertQuaternionToRotation'::`2'::negateMask1);
  v75.m128_f32[0] = v75.m128_f32[0] + 1.0;
  v76 = _mm_sub_ps(v75, v74);
  v74.m128_f32[0] = v66.m128_f32[0];
  v77 = _mm_sub_ps(
          _mm_xor_ps(v75, (__m128)`hkVector4UtilImpl<float>::convertQuaternionToRotation'::`2'::negateMask0),
          v74);
  v78 = _mm_mul_ps(v76, v67);
  v79 = _mm_mul_ps(v76, v69);
  v80 = _mm_shuffle_ps(v77, v77, 177);
  v81 = _mm_mul_ps(v80, v67);
  v82 = _mm_shuffle_ps(_mm_movehl_ps(v76, v80), v72, 141);
  v83 = _mm_unpacklo_ps(v78, v81);
  v84 = _mm_unpackhi_ps(v78, v81);
  v85 = _mm_mul_ps(v67, v82);
  v86 = _mm_movelh_ps(v83, v85);
  v87 = _mm_movehl_ps(v86, v83);
  v88 = _mm_mul_ps(v80, v69);
  v89 = _mm_mul_ps(v69, v82);
  v90 = _mm_unpacklo_ps(v79, v88);
  v91 = _mm_unpackhi_ps(v79, v88);
  v92 = _mm_movelh_ps(v90, v89);
  v93 = _mm_mul_ps(v76, v68);
  v94 = _mm_mul_ps(v82, v68);
  v95 = _mm_mul_ps(v80, v68);
  v96 = _mm_unpacklo_ps(v93, v95);
  v97 = _mm_movelh_ps(v96, v94);
  v98.m_quad = (__m128)regA->m_invMasses;
  v99 = _mm_add_ps(v97, _mm_shuffle_ps(_mm_movehl_ps(v97, v96), v94, 212));
  v100 = _mm_sub_ps((__m128)0i64, (__m128)xmmword_141A711B0);
  v101 = _mm_mul_ps(_mm_add_ps(_mm_shuffle_ps(_mm_unpackhi_ps(v93, v95), v94, 228), v99), v100);
  v102 = _mm_mul_ps(_mm_add_ps(_mm_shuffle_ps(v84, v85, 228), _mm_add_ps(v86, _mm_shuffle_ps(v87, v85, 212))), v100);
  v103 = _mm_mul_ps(
           _mm_add_ps(_mm_shuffle_ps(v91, v89, 228), _mm_add_ps(v92, _mm_shuffle_ps(_mm_movehl_ps(v92, v90), v89, 212))),
           v100);
  v104.m_quad = (__m128)regB->m_invMasses;
  v105 = scale.m_real;
  v106 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v102, v102), v98.m_quad), _mm_mul_ps(_mm_mul_ps(v64, v64), v104.m_quad));
  v107 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v103, v102), v98.m_quad), _mm_mul_ps(_mm_mul_ps(v65, v64), v104.m_quad));
  v108 = _mm_add_ps(
           _mm_mul_ps(_mm_mul_ps(v101, v102), v98.m_quad),
           _mm_mul_ps(_mm_mul_ps(scale.m_real, v64), v104.m_quad));
  v109 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v103, v103), v98.m_quad), _mm_mul_ps(_mm_mul_ps(v65, v65), v104.m_quad));
  v110 = _mm_add_ps(
           _mm_mul_ps(_mm_mul_ps(v101, v103), v98.m_quad),
           _mm_mul_ps(_mm_mul_ps(scale.m_real, v65), v104.m_quad));
  v111 = _mm_add_ps(
           _mm_mul_ps(_mm_mul_ps(v101, v101), v98.m_quad),
           _mm_mul_ps(_mm_mul_ps(scale.m_real, scale.m_real), v104.m_quad));
  v112 = _mm_unpacklo_ps(v106, v107);
  v113 = _mm_shuffle_ps(_mm_unpackhi_ps(v106, v107), v108, 228);
  v114 = _mm_movelh_ps(v112, v108);
  v115 = _mm_movehl_ps(v114, v112);
  v116 = _mm_unpacklo_ps(v109, v110);
  v117 = _mm_movelh_ps(v116, v111);
  v155.m_col0.m_quad = _mm_add_ps(v113, _mm_add_ps(v114, _mm_shuffle_ps(v115, v108, 212)));
  v118.m_quad = _mm_add_ps(
                  _mm_shuffle_ps(_mm_unpackhi_ps(v109, v110), v111, 228),
                  _mm_add_ps(v117, _mm_shuffle_ps(_mm_movehl_ps(v117, v116), v111, 212)));
  v119.m_quad = _mm_unpacklo_ps(v118.m_quad, v118.m_quad);
  v119.m_quad.m128_f32[0] = COERCE_FLOAT(_mm_shuffle_ps(v155.m_col0.m_quad, v155.m_col0.m_quad, 85));
  v155.m_col1 = (hkVector4f)v119.m_quad;
  v120 = _mm_shuffle_ps(v155.m_col0.m_quad, v155.m_col0.m_quad, 0);
  v118.m_quad.m128_f32[0] = COERCE_FLOAT(_mm_shuffle_ps(v155.m_col0.m_quad, v155.m_col0.m_quad, 170));
  v155.m_col2 = (hkVector4f)v118.m_quad;
  scale.m_real = _mm_min_ps(
                   _mm_max_ps(_mm_andnot_ps(_mm_cmpeqps((__m128)0i64, v120), _mm_rcp_ps(v120)), query.m_quad),
                   (__m128)xmmword_141A712B0);
  hkMatrix3f::mul(&v155, &scale);
  v121 = _mm_shuffle_ps(v155.m_col1.m_quad, v155.m_col1.m_quad, 201);
  v122 = _mm_shuffle_ps(v155.m_col2.m_quad, v155.m_col2.m_quad, 201);
  v123 = _mm_sub_ps(_mm_mul_ps(v155.m_col1.m_quad, v122), _mm_mul_ps(v155.m_col2.m_quad, v121));
  v124 = _mm_shuffle_ps(v155.m_col0.m_quad, v155.m_col0.m_quad, 201);
  v125 = _mm_shuffle_ps(v123, v123, 201);
  v126 = _mm_mul_ps(v155.m_col0.m_quad, v125);
  v127 = _mm_sub_ps(_mm_mul_ps(v155.m_col2.m_quad, v124), _mm_mul_ps(v155.m_col0.m_quad, v122));
  v128 = _mm_sub_ps(_mm_mul_ps(v155.m_col0.m_quad, v121), _mm_mul_ps(v155.m_col1.m_quad, v124));
  v129 = _mm_add_ps(
           _mm_add_ps(_mm_shuffle_ps(v126, v126, 85), _mm_shuffle_ps(v126, v126, 0)),
           _mm_shuffle_ps(v126, v126, 170));
  v130 = _mm_rcp_ps(v129);
  v131 = _mm_and_ps(
           _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v130, v129)), v130),
           _mm_cmpltps(*(__m128 *)&epsilon, v129));
  v132 = _mm_mul_ps(v131, _mm_shuffle_ps(v128, v128, 201));
  v133 = _mm_max_ps(v9->m_real, *(__m128 *)&epsilon);
  v134 = _mm_mul_ps(
           _mm_add_ps(
             _mm_add_ps(
               _mm_mul_ps(_mm_shuffle_ps(v154, v154, 85), _mm_mul_ps(v131, _mm_shuffle_ps(v127, v127, 201))),
               _mm_mul_ps(_mm_shuffle_ps(v154, v154, 0), _mm_mul_ps(v131, v125))),
             _mm_mul_ps(_mm_shuffle_ps(v154, v154, 170), v132)),
           scale.m_real);
  v135 = _mm_mul_ps(v134, v134);
  v136 = _mm_add_ps(
           _mm_add_ps(_mm_shuffle_ps(v135, v135, 85), _mm_shuffle_ps(v135, v135, 0)),
           _mm_shuffle_ps(v135, v135, 170));
  v137 = _mm_rsqrt_ps(v136);
  v138 = _mm_andnot_ps(
           _mm_cmpleps(v136, (__m128)0i64),
           _mm_mul_ps(
             _mm_mul_ps(
               _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v137, v136), v137)),
               _mm_mul_ps(*(__m128 *)_xmm, v137)),
             v136));
  v139 = _mm_rcp_ps(v138);
  v140 = _mm_mul_ps(v139, v138);
  v141 = _mm_cmpleps(v138, v133);
  v142 = _mm_or_ps(
           _mm_andnot_ps(v141, _mm_mul_ps(_mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, v140), v139), v133), v134)),
           _mm_and_ps(v134, v141));
  v143 = _mm_shuffle_ps(v142, v142, 0);
  v144 = _mm_shuffle_ps(v142, v142, 170);
  v145 = _mm_shuffle_ps(v142, v142, 85);
  v146 = _mm_mul_ps(v102, v143);
  v147 = _mm_mul_ps(v64, v143);
  v148 = _mm_mul_ps(v101, v144);
  v149 = _mm_mul_ps(v105, v144);
  v150.m_quad = (__m128)regB->m_invMasses;
  v151 = _mm_add_ps(
           _mm_movelh_ps(
             (__m128)*(unsigned __int64 *)&temps->m_impulseApplied,
             (__m128)LODWORD(temps[2].m_impulseApplied)),
           v142);
  *(_QWORD *)&temps->m_impulseApplied = v151.m128_u64[0];
  LODWORD(temps[2].m_impulseApplied) = (unsigned __int128)_mm_movehl_ps(v151, v151);
  v152.m_quad = _mm_add_ps(
                  _mm_mul_ps(v150.m_quad, _mm_add_ps(_mm_add_ps(v147, _mm_mul_ps(v65, v145)), v149)),
                  regB->m_angularVel.m_quad);
  regA->m_angularVel.m_quad = _mm_add_ps(
                                _mm_mul_ps(
                                  _mm_add_ps(_mm_add_ps(v146, _mm_mul_ps(v103, v145)), v148),
                                  regA->m_invMasses.m_quad),
                                regA->m_angularVel.m_quad);
  regB->m_angularVel = (hkVector4f)v152.m_quad;
}

// File Line: 743
// RVA: 0xDE4B40
void __fastcall hkpAtomSolverFunctions::solveStableAngularConstraint3d<hkpVelocityAccumulator,hkpSolverInfo,hkSolverStepTemp>(hkpSolverInfo *solverInfo, hkSolverStepTemp *temp, hkpStableAngularSchema3d *schema, hkpVelocityAccumulator *mA, hkpVelocityAccumulator *mB, hkpSolverElemTemp *temps)
{
  hkpVelocityAccumulator *v6; // rsi
  hkpStableAngularSchema3d *v7; // rdi
  __m128 v8; // xmm2
  __m128 v9; // xmm1
  hkQuaternionf qB; // [rsp+50h] [rbp-68h]
  hkQuaternionf qA; // [rsp+60h] [rbp-58h]
  hkSimdFloat32 maxImpulse; // [rsp+70h] [rbp-48h]
  hkSimdFloat32 erp; // [rsp+90h] [rbp-28h]

  v6 = mA;
  v7 = schema;
  hkpAtomSolverFunctions::getFuturePositions<hkpVelocityAccumulator,hkpSolverInfo>(
    solverInfo,
    mA,
    &mA->m_scratch3,
    (hkQuaternionf *)&mA->m_scratch2,
    mB,
    &mB->m_scratch3,
    (hkQuaternionf *)&mB->m_scratch2,
    (hkQTransformf *)&erp,
    (hkQTransformf *)&maxImpulse);
  v8 = v7->m_data.m_quad;
  v9 = maxImpulse.m_real;
  _mm_store_si128((__m128i *)&qA, (__m128i)erp.m_real);
  _mm_store_si128((__m128i *)&qB, (__m128i)v9);
  erp.m_real = _mm_shuffle_ps(v8, v8, 85);
  maxImpulse.m_real = _mm_shuffle_ps(v8, v8, 170);
  hkpAtomSolverFunctions::solveQuatAngular3D<hkpVelocityAccumulator>(
    &erp,
    &maxImpulse,
    &v7->m_pivotA,
    &v7->m_pivotB,
    &qA,
    &qB,
    v6,
    mB,
    temps);
}

// File Line: 765
// RVA: 0xDE3580
void __fastcall hkpAtomSolverFunctions::solveDeformableLinConstraint<hkpVelocityAccumulator>(hkQTransformf *coreToWorldA, hkQTransformf *coreToWorldB, hkpDeformableLinSchema *schema, hkpVelocityAccumulator *mA, hkpVelocityAccumulator *mB, hkpSolverElemTemp *temps)
{
  __m128 v6; // xmm4
  hkVector4f v7; // xmm2
  hkpVelocityAccumulator *v8; // rsi
  hkpDeformableLinSchema *v9; // r14
  hkQTransformf *v10; // rbx
  hkQTransformf *v11; // rdi
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
  __m128 v23; // xmm3
  __m128 *v24; // r12
  __m128 v25; // xmm8
  __m128 v26; // xmm8
  __m128 *v27; // r15
  __m128 v28; // xmm11
  __m128 v29; // xmm12
  __m128 v30; // xmm5
  __m128 v31; // xmm8
  __m128 v32; // xmm1
  __m128 v33; // xmm3
  __m128 v34; // xmm2
  __m128 v35; // xmm9
  __m128 v36; // xmm0
  __m128 v37; // xmm4
  __m128 v38; // xmm9
  __m128 v39; // xmm4
  __m128 v40; // xmm1
  __m128 v41; // xmm7
  __m128i v42; // xmm6
  __m128 v43; // xmm1
  __m128 v44; // xmm6
  __m128i v45; // xmm7
  __m128 v46; // xmm10
  __m128 v47; // xmm2
  __m128 v48; // xmm1
  __m128 v49; // xmm3
  __m128 v50; // xmm1
  __m128 v51; // xmm4
  __m128 v52; // xmm2
  __m128 v53; // xmm5
  __m128 v54; // xmm1
  __m128 v55; // xmm5
  __m128 v56; // xmm2
  __m128 v57; // xmm3
  __m128 v58; // xmm11
  __m128 v59; // xmm2
  __m128 v60; // xmm2
  __m128 v61; // xmm8
  __m128 v62; // xmm4
  __m128 v63; // xmm2
  __m128 v64; // xmm0
  __m128 v65; // xmm1
  __m128 v66; // xmm3
  __m128 v67; // xmm7
  __m128 v68; // xmm5
  __m128 v69; // xmm7
  __m128 v70; // xmm3
  __m128 v71; // xmm6
  __m128 v72; // xmm0
  __m128 v73; // xmm6
  __m128 v74; // xmm5
  __m128i v75; // xmm5
  __m128 v76; // xmm1
  __m128 v77; // xmm4
  __m128 v78; // xmm1
  __m128 v79; // xmm4
  __m128 v80; // xmm0
  __m128 v81; // xmm8
  __m128 v82; // xmm1
  __m128 v83; // xmm8
  signed int v84; // eax
  __m128 v85; // xmm3
  __m128 v86; // xmm12
  __m128 v87; // xmm0
  __m128 v88; // xmm5
  __m128 v89; // xmm3
  __m128 v90; // xmm4
  __m128 v91; // xmm2
  __m128 v92; // xmm1
  __m128 v93; // xmm0
  hkVector4f v94; // xmm0
  hkVector4f v95; // xmm0
  __m128 v96; // xmm1
  hkVector4f v97; // xmm0
  hkQuaternionf rotA; // [rsp+50h] [rbp-1B8h]
  hkQuaternionf rotB; // [rsp+60h] [rbp-1A8h]
  __m128 v100; // [rsp+70h] [rbp-198h]
  __m128 v101; // [rsp+80h] [rbp-188h]
  __m128 v102; // [rsp+90h] [rbp-178h]
  hkQuaternionf v103; // [rsp+A0h] [rbp-168h]
  hkVector4f vWorldArmA; // [rsp+B0h] [rbp-158h]
  hkVector4f vWorldArmB; // [rsp+C0h] [rbp-148h]
  hkSymmetricMatrix3Impl<float> outK; // [rsp+D0h] [rbp-138h]
  hkMatrix3f UA; // [rsp+F0h] [rbp-118h]
  __m128 UB; // [rsp+120h] [rbp-E8h]
  __m128 v109; // [rsp+130h] [rbp-D8h]
  __m128 v110; // [rsp+140h] [rbp-C8h]

  v6 = coreToWorldA->m_rotation.m_vec.m_quad;
  v7.m_quad = (__m128)schema->m_pivotA;
  v8 = mA;
  v9 = schema;
  v10 = coreToWorldB;
  v11 = coreToWorldA;
  v12 = coreToWorldB->m_rotation.m_vec.m_quad;
  v13 = _mm_mul_ps(schema->m_pivotA.m_quad, coreToWorldA->m_rotation.m_vec.m_quad);
  v14 = _mm_shuffle_ps(v6, v6, 201);
  v103.m_vec.m_quad = (__m128)coreToWorldA->m_rotation;
  v101 = v12;
  v15 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v7.m_quad, v7.m_quad, 201), v6), _mm_mul_ps(v14, v7.m_quad));
  rotA.m_vec.m_quad = v6;
  rotB.m_vec.m_quad = v12;
  v100 = _mm_shuffle_ps(v103.m_vec.m_quad, v6, 255);
  v16 = _mm_shuffle_ps(v12, v12, 201);
  v102 = _mm_shuffle_ps(v12, v12, 255);
  v17 = _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v100, v100), (__m128)xmmword_141A711B0), v7.m_quad);
  v18.m_quad = (__m128)schema->m_pivotB;
  v19 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)),
                _mm_shuffle_ps(v13, v13, 170)),
              v6),
            v17),
          _mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), v100));
  v20 = _mm_mul_ps(schema->m_pivotB.m_quad, v12);
  v21 = _mm_add_ps(v19, v19);
  v22 = _mm_shuffle_ps(schema->m_pivotB.m_quad, v18.m_quad, 201);
  vWorldArmA.m_quad = v21;
  v23 = _mm_sub_ps(_mm_mul_ps(v22, v12), _mm_mul_ps(v16, v18.m_quad));
  v24 = &mA->m_invMasses.m_quad;
  v25 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)),
                _mm_shuffle_ps(v20, v20, 170)),
              v12),
            _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v102, v102), (__m128)xmmword_141A711B0), v18.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v23, v23, 201), v102));
  v26 = _mm_add_ps(v25, v25);
  v27 = &mB->m_invMasses.m_quad;
  vWorldArmB.m_quad = v26;
  hkpAtomSolverFunctions::computeInverseVirtualMass3D(
    &rotA,
    &rotB,
    &vWorldArmA,
    &vWorldArmB,
    &mA->m_invMasses,
    &mB->m_invMasses,
    &outK,
    &UA,
    (hkMatrix3f *)&UB);
  v28 = v9->m_offsetA.m_quad;
  v29 = v9->m_ultimateStrengthOffDiag.m_quad;
  v30 = v9->m_ultimateStrengthDiag.m_quad;
  v31 = _mm_sub_ps(_mm_add_ps(_mm_sub_ps(v26, v21), v10->m_translation.m_quad), v11->m_translation.m_quad);
  rotA.m_vec.m_quad = v31;
  v32 = _mm_mul_ps(v31, v31);
  v33 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v32, v32, 85), _mm_shuffle_ps(v32, v32, 0)), _mm_shuffle_ps(v32, v32, 170));
  v34 = _mm_rsqrt_ps(v33);
  v35 = _mm_andnot_ps(
          _mm_cmpleps(v33, (__m128)0i64),
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v34, v33), v34)), _mm_mul_ps(*(__m128 *)_xmm, v34)));
  v36 = _mm_cmpltps((__m128)xmmword_141A712D0, v33);
  v37 = v35;
  v38 = _mm_mul_ps(v35, v33);
  v39 = _mm_or_ps(_mm_and_ps(_mm_mul_ps(v37, v31), v36), _mm_andnot_ps(v36, transform.m_quad));
  v40 = _mm_mul_ps(v9->m_yieldStrengthOffDiag.m_quad, v39);
  v41 = _mm_shuffle_ps(v39, v39, 201);
  v42 = _mm_slli_epi32(
          (__m128i)_mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(v41, v9->m_yieldStrengthOffDiag.m_quad),
                       _mm_mul_ps(v9->m_yieldStrengthDiag.m_quad, v39)),
                     _mm_shuffle_ps(v40, v40, 210)),
          1u);
  v43 = _mm_mul_ps(v29, v39);
  v44 = (__m128)_mm_srli_epi32(v42, 1u);
  v45 = (__m128i)_mm_add_ps(_mm_add_ps(_mm_mul_ps(v41, v29), _mm_mul_ps(v30, v39)), _mm_shuffle_ps(v43, v43, 210));
  v46 = v9->m_offsetB.m_quad;
  v47 = _mm_shuffle_ps(v46, v46, 255);
  v48 = _mm_rcp_ps(v47);
  v49 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v48, v47)), v48);
  v50 = _mm_mul_ps(v28, v103.m_vec.m_quad);
  v51 = _mm_and_ps(
          _mm_max_ps(
            _mm_sub_ps(
              _mm_andnot_ps(_mm_cmpeqps((__m128)0i64, v47), _mm_mul_ps(v49, v38)),
              _mm_shuffle_ps(v30, v30, 255)),
            aabbOut.m_quad),
          _mm_cmpltps((__m128)0i64, _mm_sub_ps(v38, _mm_shuffle_ps(v28, v28, 255))));
  v52 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v28, v28, 201), v103.m_vec.m_quad), _mm_mul_ps(v28, v14));
  rotB.m_vec.m_quad = _mm_add_ps(
                        _mm_mul_ps(v51, _mm_sub_ps((__m128)_mm_srli_epi32(_mm_slli_epi32(v45, 1u), 1u), v44)),
                        v44);
  v53 = _mm_mul_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v50, v50, 85), _mm_shuffle_ps(v50, v50, 0)),
            _mm_shuffle_ps(v50, v50, 170)),
          v103.m_vec.m_quad);
  v54 = _mm_mul_ps(v46, v101);
  v55 = _mm_add_ps(
          _mm_add_ps(v53, _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v100, v100), (__m128)xmmword_141A711B0), v28)),
          _mm_mul_ps(_mm_shuffle_ps(v52, v52, 201), v100));
  v56 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v46, v46, 201), v101), _mm_mul_ps(v46, v16));
  v57 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v54, v54, 85), _mm_shuffle_ps(v54, v54, 0)),
                _mm_shuffle_ps(v54, v54, 170)),
              v101),
            _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v102, v102), (__m128)xmmword_141A711B0), v46)),
          _mm_mul_ps(_mm_shuffle_ps(v56, v56, 201), v102));
  v58 = _mm_mul_ps(
          _mm_sub_ps(_mm_sub_ps(v31, _mm_add_ps(v55, v55)), _mm_add_ps(v57, v57)),
          _mm_shuffle_ps(v29, v29, 255));
  v59 = _mm_max_ps(
          (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)outK.m_diag.m_quad, 1u), 1u),
          (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)outK.m_offDiag.m_quad, 1u), 1u));
  v60 = _mm_max_ps(_mm_shuffle_ps(v59, v59, 170), _mm_max_ps(_mm_shuffle_ps(v59, v59, 85), _mm_shuffle_ps(v59, v59, 0)));
  v61 = _mm_andnot_ps(_mm_cmpeqps(v60, (__m128)0i64), _mm_div_ps(query.m_quad, v60));
  v62 = _mm_mul_ps(outK.m_diag.m_quad, v61);
  v63 = _mm_mul_ps(outK.m_offDiag.m_quad, v61);
  v64 = _mm_shuffle_ps(v63, v63, 201);
  v65 = _mm_shuffle_ps(v62, v62, 210);
  v66 = _mm_mul_ps(v64, v64);
  v67 = _mm_mul_ps(_mm_shuffle_ps(v62, v62, 201), v65);
  v68 = v67;
  v69 = _mm_sub_ps(v67, v66);
  v70 = _mm_mul_ps(v66, v62);
  v71 = _mm_mul_ps(_mm_shuffle_ps(v63, v63, 210), v64);
  v72 = v71;
  v73 = _mm_sub_ps(v71, _mm_mul_ps(v65, v63));
  v74 = _mm_add_ps(_mm_mul_ps(v68, v62), _mm_mul_ps(_mm_mul_ps(v72, v63), (__m128)xmmword_141A710D0));
  v75 = (__m128i)_mm_sub_ps(
                   _mm_shuffle_ps(v74, v74, 0),
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v70, v70, 85), _mm_shuffle_ps(v70, v70, 0)),
                     _mm_shuffle_ps(v70, v70, 170)));
  v76 = _mm_rcp_ps((__m128)v75);
  v77 = _mm_mul_ps(
          _mm_and_ps(
            _mm_cmpltps(*(__m128 *)&epsilon, (__m128)_mm_srli_epi32(_mm_slli_epi32(v75, 1u), 1u)),
            _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v76, (__m128)v75)), v76)),
          v61);
  v78 = v77;
  v79 = _mm_mul_ps(v77, v73);
  v80 = _mm_mul_ps(v79, v58);
  v81 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v58, v58, 201), v79), _mm_mul_ps(_mm_mul_ps(v78, v69), v58));
  v82 = _mm_rcp_ps(outK.m_diag.m_quad);
  v83 = _mm_add_ps(v81, _mm_shuffle_ps(v80, v80, 210));
  v84 = 3;
  v85 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64), rotB.m_vec.m_quad);
  v86 = _mm_andnot_ps(
          _mm_cmpeqps((__m128)0i64, outK.m_diag.m_quad),
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v82, outK.m_diag.m_quad)), v82));
  do
  {
    --v84;
    v87 = _mm_mul_ps(outK.m_offDiag.m_quad, v83);
    v83 = _mm_max_ps(
            _mm_min_ps(
              _mm_mul_ps(
                _mm_sub_ps(
                  v58,
                  _mm_add_ps(
                    _mm_shuffle_ps(v87, v87, 210),
                    _mm_mul_ps(_mm_shuffle_ps(v83, v83, 201), outK.m_offDiag.m_quad))),
                v86),
              rotB.m_vec.m_quad),
            v85);
  }
  while ( v84 >= 0 );
  v88 = _mm_shuffle_ps(v83, v83, 85);
  v89 = _mm_shuffle_ps(v83, v83, 0);
  v90 = _mm_shuffle_ps(v83, v83, 170);
  v91 = _mm_add_ps(
          _mm_movelh_ps(
            (__m128)*(unsigned __int64 *)&temps->m_impulseApplied,
            (__m128)LODWORD(temps[2].m_impulseApplied)),
          v83);
  v92 = _mm_mul_ps(
          *v27,
          _mm_mul_ps(
            _mm_add_ps(_mm_add_ps(_mm_mul_ps(UB, v89), _mm_mul_ps(v109, v88)), _mm_mul_ps(v110, v90)),
            _mm_shuffle_ps(v9->m_pivotB.m_quad, v9->m_pivotB.m_quad, 255)));
  v93 = _mm_mul_ps(
          *v24,
          _mm_mul_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(UA.m_col0.m_quad, v89), _mm_mul_ps(UA.m_col1.m_quad, v88)),
              _mm_mul_ps(UA.m_col2.m_quad, v90)),
            _mm_shuffle_ps(v9->m_pivotA.m_quad, v9->m_pivotA.m_quad, 255)));
  *(_QWORD *)&temps->m_impulseApplied = v91.m128_u64[0];
  v8->m_angularVel.m_quad = _mm_add_ps(v93, v8->m_angularVel.m_quad);
  v94.m_quad = (__m128)mB->m_angularVel;
  LODWORD(temps[2].m_impulseApplied) = (unsigned __int128)_mm_movehl_ps(v91, v91);
  v95.m_quad = _mm_sub_ps(v94.m_quad, v92);
  v96 = *v24;
  mB->m_angularVel = (hkVector4f)v95.m_quad;
  v97.m_quad = (__m128)mB->m_linearVel;
  v8->m_linearVel.m_quad = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v96, v96, 255), v83), v8->m_linearVel.m_quad);
  mB->m_linearVel.m_quad = _mm_sub_ps(v97.m_quad, _mm_mul_ps(_mm_shuffle_ps(*v27, *v27, 255), v83));
} v96 = 

// File Line: 822
// RVA: 0xDE2920
void __fastcall hkpAtomSolverFunctions::solveDeformableAngConstraint<hkpVelocityAccumulator>(hkQTransformf *coreToWorldA, hkQTransformf *coreToWorldB, hkpDeformableAngSchema *schema, hkpVelocityAccumulator *mA, hkpVelocityAccumulator *mB, hkpSolverElemTemp *temps)
{
  hkQuaternionf v6; // xmm3
  __m128 v7; // xmm4
  __m128 v8; // ST40_16
  __m128 v9; // xmm6
  __m128 v10; // xmm0
  __m128 v11; // xmm3
  __m128 v12; // xmm6
  __m128 v13; // xmm2
  hkQuaternionf v14; // xmm3
  __m128 v15; // xmm14
  __m128 v16; // xmm6
  __m128 v17; // xmm4
  __m128 v18; // xmm5
  __m128 v19; // xmm0
  __m128 v20; // xmm3
  __m128 v21; // xmm5
  __m128 v22; // xmm5
  hkVector4f v23; // xmm12
  hkVector4f v24; // xmm3
  __m128 v25; // xmm8
  __m128 v26; // xmm13
  __m128 v27; // xmm1
  __m128 v28; // xmm0
  __m128 v29; // xmm5
  __m128 v30; // xmm13
  __m128 v31; // xmm0
  __m128 v32; // xmm13
  __m128 v33; // xmm1
  __m128 v34; // xmm11
  __m128 v35; // xmm1
  __m128 v36; // xmm0
  hkVector4f v37; // xmm2
  __m128 v38; // xmm9
  __m128 v39; // xmm1
  __m128 v40; // xmm7
  __m128 v41; // xmm4
  __m128 v42; // xmm6
  __m128 v43; // xmm0
  __m128 v44; // xmm7
  __m128 v45; // xmm1
  hkQuaternionf v46; // xmm2
  __m128 v47; // xmm3
  __m128 v48; // xmm5
  __m128 v49; // xmm1
  __m128 v50; // xmm4
  __m128 v51; // xmm3
  __m128 v52; // xmm13
  __m128 v53; // xmm4
  hkQuaternionf v54; // xmm2
  __m128 v55; // xmm4
  __m128 v56; // xmm15
  __m128 v57; // xmm1
  __m128 v58; // xmm3
  __m128 v59; // xmm0
  __m128 v60; // xmm4
  __m128 v61; // xmm3
  __m128 v62; // xmm0
  hkQuaternionf v63; // xmm2
  __m128 v64; // xmm3
  __m128 v65; // xmm6
  __m128 v66; // ST20_16
  __m128 v67; // xmm11
  __m128 v68; // xmm13
  hkQuaternionf v69; // xmm3
  __m128 v70; // xmm1
  __m128 v71; // xmm4
  __m128 v72; // xmm0
  __m128 v73; // xmm3
  __m128 v74; // xmm4
  __m128 v75; // xmm4
  __m128 v76; // xmm10
  __m128 v77; // ST50_16
  __m128 v78; // xmm10
  __m128 v79; // xmm2
  __m128 v80; // xmm1
  __m128 v81; // xmm3
  __m128 v82; // xmm3
  __m128 v83; // xmm10
  __m128 v84; // xmm1
  __m128 v85; // xmm10
  __m128 v86; // xmm10
  __m128 v87; // xmm3
  __m128 v88; // xmm0
  __m128 v89; // xmm9
  __m128 v90; // xmm2
  __m128 v91; // xmm1
  __m128 v92; // xmm8
  __m128 v93; // ST30_16
  __m128 v94; // xmm3
  __m128 v95; // xmm0
  __m128 v96; // xmm10
  __m128 v97; // xmm7
  __m128 v98; // xmm6
  __m128 v99; // xmm1
  __m128 v100; // xmm3
  __m128 v101; // xmm1
  __m128 v102; // xmm2
  __m128 v103; // xmm0
  __m128 v104; // ST00_16
  __m128 v105; // xmm5
  __m128 v106; // xmm9
  __m128 v107; // xmm4
  __m128 v108; // xmm2
  __m128 v109; // xmm3
  __m128 v110; // xmm0
  hkQuaternionf v111; // xmm2
  hkQuaternionf v112; // xmm3
  __m128 v113; // ST20_16
  __m128 v114; // xmm5
  __m128 v115; // xmm1
  __m128 v116; // xmm11
  __m128 v117; // xmm0
  __m128 v118; // xmm4
  __m128 v119; // xmm3
  __m128 v120; // xmm4
  __m128 v121; // xmm4
  __m128 v122; // xmm10
  __m128 v123; // xmm2
  __m128 v124; // xmm1
  __m128 v125; // xmm3
  __m128 v126; // xmm3
  __m128 v127; // xmm10
  __m128 v128; // xmm15
  __m128 v129; // xmm10
  __m128 v130; // xmm12
  __m128 v131; // xmm10
  __m128 v132; // xmm0
  __m128 v133; // xmm9
  __m128 v134; // xmm8
  __m128 v135; // xmm1
  __m128 v136; // xmm7
  __m128 v137; // xmm14
  __m128 v138; // xmm12
  __m128 v139; // xmm0
  __m128 v140; // xmm5
  __m128 v141; // xmm1
  __m128 v142; // xmm14
  __m128 v143; // xmm4
  __m128 v144; // xmm15
  __m128 v145; // xmm9
  __m128 v146; // xmm10
  __m128 v147; // xmm0
  __m128 v148; // xmm2
  __m128 v149; // xmm4
  __m128 v150; // xmm1
  __m128 v151; // xmm0
  __m128 v152; // xmm12
  __m128 v153; // xmm14
  __m128 v154; // xmm15
  hkVector4f v155; // xmm0
  __m128 v156; // xmm4
  __m128 v157; // xmm5
  __m128 v158; // xmm6
  __m128 v159; // xmm3
  __m128 v160; // xmm0
  __m128 v161; // xmm2
  __m128 v162; // xmm1
  __m128 v163; // xmm3
  __m128 v164; // xmm8
  __m128 v165; // xmm8
  __m128 v166; // xmm2
  __m128 v167; // xmm8
  __m128 v168; // xmm0
  __m128 v169; // xmm3
  __m128 v170; // xmm1
  __m128 v171; // xmm7
  __m128 v172; // xmm7
  hkVector4f v173; // xmm0
  __m128 v174; // xmm4
  __m128 v175; // xmm5
  __m128 v176; // xmm6
  __m128 v177; // xmm3
  __m128 v178; // xmm0
  __m128 v179; // xmm2
  __m128 v180; // xmm1
  __m128 v181; // xmm3
  __m128 v182; // xmm9
  __m128 v183; // xmm9
  __m128 v184; // xmm2
  __m128 v185; // xmm0
  __m128i v186; // xmm9
  __m128 v187; // xmm3
  __m128 v188; // xmm1
  __m128 v189; // xmm10
  __m128i v190; // xmm10
  __m128 v191; // xmm2
  __m128 v192; // xmm2
  __m128 v193; // xmm8
  __m128 v194; // xmm4
  __m128 v195; // xmm2
  __m128 v196; // xmm1
  __m128 v197; // xmm0
  __m128 v198; // xmm7
  __m128 v199; // xmm5
  signed int v200; // eax
  __m128 v201; // xmm3
  __m128 v202; // xmm7
  __m128 v203; // xmm6
  __m128 v204; // xmm3
  __m128 v205; // xmm0
  __m128 v206; // xmm6
  __m128 v207; // xmm5
  __m128i v208; // xmm5
  __m128 v209; // xmm1
  __m128 v210; // xmm4
  __m128 v211; // xmm13
  __m128 v212; // xmm1
  __m128 v213; // xmm4
  __m128 v214; // xmm0
  __m128 v215; // xmm6
  __m128 v216; // xmm1
  __m128 v217; // xmm6
  __m128 v218; // xmm11
  __m128 v219; // xmm0
  __m128 v220; // xmm3
  __m128 v221; // xmm5
  __m128 v222; // xmm2
  __m128 v223; // xmm0
  __m128 v224; // xmm1
  hkVector4f v225; // xmm4
  __m128 v226; // [rsp+0h] [rbp-128h]
  __m128 v227; // [rsp+10h] [rbp-118h]
  __m128 v228; // [rsp+30h] [rbp-F8h]
  __m128 v229; // [rsp+60h] [rbp-C8h]
  __m128 v230; // [rsp+70h] [rbp-B8h]

  v6.m_vec.m_quad = (__m128)schema->m_coreFromPivotA;
  v7 = _mm_shuffle_ps(coreToWorldA->m_rotation.m_vec.m_quad, coreToWorldA->m_rotation.m_vec.m_quad, 255);
  v8 = _mm_shuffle_ps(schema->m_coreFromPivotA.m_vec.m_quad, schema->m_coreFromPivotA.m_vec.m_quad, 255);
  v9 = _mm_sub_ps(
         _mm_mul_ps(_mm_shuffle_ps(v6.m_vec.m_quad, v6.m_vec.m_quad, 201), coreToWorldA->m_rotation.m_vec.m_quad),
         _mm_mul_ps(
           _mm_shuffle_ps(coreToWorldA->m_rotation.m_vec.m_quad, coreToWorldA->m_rotation.m_vec.m_quad, 201),
           v6.m_vec.m_quad));
  v10 = _mm_mul_ps(v6.m_vec.m_quad, v7);
  v11 = _mm_mul_ps(v6.m_vec.m_quad, coreToWorldA->m_rotation.m_vec.m_quad);
  v12 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v9, v9, 201), v10), _mm_mul_ps(coreToWorldA->m_rotation.m_vec.m_quad, v8));
  v13 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)), _mm_shuffle_ps(v11, v11, 170));
  v14.m_vec.m_quad = (__m128)schema->m_coreFromPivotB;
  v15 = _mm_shuffle_ps(schema->m_coreFromPivotB.m_vec.m_quad, schema->m_coreFromPivotB.m_vec.m_quad, 255);
  v16 = _mm_shuffle_ps(v12, _mm_unpackhi_ps(v12, _mm_sub_ps(_mm_mul_ps(v8, v7), v13)), 196);
  v17 = _mm_shuffle_ps(coreToWorldB->m_rotation.m_vec.m_quad, coreToWorldB->m_rotation.m_vec.m_quad, 255);
  v18 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v14.m_vec.m_quad, v14.m_vec.m_quad, 201), coreToWorldB->m_rotation.m_vec.m_quad),
          _mm_mul_ps(
            _mm_shuffle_ps(coreToWorldB->m_rotation.m_vec.m_quad, coreToWorldB->m_rotation.m_vec.m_quad, 201),
            v14.m_vec.m_quad));
  v19 = _mm_mul_ps(v17, v14.m_vec.m_quad);
  v20 = _mm_mul_ps(v14.m_vec.m_quad, coreToWorldB->m_rotation.m_vec.m_quad);
  v21 = _mm_add_ps(
          _mm_add_ps(_mm_shuffle_ps(v18, v18, 201), v19),
          _mm_mul_ps(v15, coreToWorldB->m_rotation.m_vec.m_quad));
  v22 = _mm_shuffle_ps(
          v21,
          _mm_unpackhi_ps(
            v21,
            _mm_sub_ps(
              _mm_mul_ps(v15, v17),
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)),
                _mm_shuffle_ps(v20, v20, 170)))),
          196);
  v23.m_quad = (__m128)schema->m_yieldStrengthOffDiag;
  v24.m_quad = (__m128)schema->m_ultimateStrengthDiag;
  v25 = _mm_shuffle_ps(v24.m_quad, v24.m_quad, 255);
  v26 = _mm_mul_ps(_mm_shuffle_ps(v16, v16, 255), v22);
  v27 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v16, v16, 201), v22), _mm_mul_ps(_mm_shuffle_ps(v22, v22, 201), v16));
  v28 = _mm_shuffle_ps(v22, v22, 255);
  v29 = _mm_mul_ps(v22, v16);
  v30 = _mm_sub_ps(_mm_add_ps(v26, _mm_shuffle_ps(v27, v27, 201)), _mm_mul_ps(v28, v16));
  v31 = _mm_add_ps(_mm_shuffle_ps(v29, v29, 78), v29);
  v32 = _mm_shuffle_ps(v30, _mm_unpackhi_ps(v30, _mm_add_ps(_mm_shuffle_ps(v31, v31, 177), v31)), 196);
  v33 = _mm_mul_ps(v32, v32);
  v34 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v33, v33, 85), _mm_shuffle_ps(v33, v33, 0)), _mm_shuffle_ps(v33, v33, 170));
  v35 = _mm_rsqrt_ps(v34);
  v36 = _mm_cmpltps((__m128)xmmword_141A712D0, v34);
  v37.m_quad = (__m128)schema->m_ultimateStrengthOffDiag;
  v38 = _mm_or_ps(
          _mm_and_ps(
            _mm_mul_ps(
              _mm_andnot_ps(
                _mm_cmpleps(v34, (__m128)0i64),
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v35, v34), v35)),
                  _mm_mul_ps(*(__m128 *)_xmm, v35))),
              v32),
            v36),
          _mm_andnot_ps(v36, transform.m_quad));
  v39 = _mm_mul_ps(schema->m_yieldStrengthOffDiag.m_quad, v38);
  v40 = _mm_shuffle_ps(v38, v38, 201);
  v41 = _mm_mul_ps(_mm_sub_ps(query.m_quad, _mm_shuffle_ps(v37.m_quad, v37.m_quad, 255)), (__m128)xmmword_141A711B0);
  v42 = (__m128)_mm_srli_epi32(
                  _mm_slli_epi32(
                    (__m128i)_mm_add_ps(
                               _mm_add_ps(
                                 _mm_mul_ps(v40, v23.m_quad),
                                 _mm_mul_ps(schema->m_yieldStrengthDiag.m_quad, v38)),
                               _mm_shuffle_ps(v39, v39, 210)),
                    1u),
                  1u);
  v43 = _mm_mul_ps(schema->m_ultimateStrengthOffDiag.m_quad, v38);
  v44 = _mm_add_ps(_mm_mul_ps(v40, v37.m_quad), _mm_mul_ps(v24.m_quad, v38));
  v45 = _mm_rcp_ps(v41);
  v46.m_vec.m_quad = (__m128)schema->m_pivotFromOffsetB;
  v47 = _mm_max_ps(
          _mm_sub_ps(
            _mm_andnot_ps(
              _mm_cmpeqps(v41, (__m128)0i64),
              _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v45, v41)), v45), v34)),
            _mm_shuffle_ps(schema->m_yieldStrengthDiag.m_quad, schema->m_yieldStrengthDiag.m_quad, 255)),
          aabbOut.m_quad);
  v48 = _mm_shuffle_ps(schema->m_pivotFromOffsetB.m_vec.m_quad, schema->m_pivotFromOffsetB.m_vec.m_quad, 255);
  v49 = _mm_mul_ps(v48, v32);
  v50 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v46.m_vec.m_quad, v46.m_vec.m_quad, 201), v32),
          _mm_mul_ps(_mm_shuffle_ps(v32, v32, 201), v46.m_vec.m_quad));
  v230 = _mm_add_ps(
           _mm_mul_ps(
             _mm_and_ps(v47, _mm_cmpltps(_mm_sub_ps(query.m_quad, _mm_add_ps(v34, v34)), v25)),
             _mm_sub_ps(
               (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_add_ps(v44, _mm_shuffle_ps(v43, v43, 210)), 1u), 1u),
               v42)),
           v42);
  v51 = _mm_shuffle_ps(v32, v32, 255);
  v52 = _mm_mul_ps(v32, v46.m_vec.m_quad);
  v53 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v50, v50, 201), _mm_mul_ps(v51, v46.m_vec.m_quad)), v49);
  v54.m_vec.m_quad = (__m128)schema->m_pivotFromOffsetA;
  v55 = _mm_shuffle_ps(
          v53,
          _mm_unpackhi_ps(
            v53,
            _mm_sub_ps(
              _mm_mul_ps(v48, v51),
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v52, v52, 85), _mm_shuffle_ps(v52, v52, 0)),
                _mm_shuffle_ps(v52, v52, 170)))),
          196);
  v56 = _mm_shuffle_ps(schema->m_pivotFromOffsetA.m_vec.m_quad, schema->m_pivotFromOffsetA.m_vec.m_quad, 255);
  v57 = _mm_mul_ps(_mm_shuffle_ps(v55, v55, 255), v54.m_vec.m_quad);
  v58 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v54.m_vec.m_quad, v54.m_vec.m_quad, 201), v55),
          _mm_mul_ps(_mm_shuffle_ps(v55, v55, 201), v54.m_vec.m_quad));
  v59 = _mm_mul_ps(v56, v55);
  v60 = _mm_mul_ps(v55, v54.m_vec.m_quad);
  v61 = _mm_sub_ps(_mm_add_ps(_mm_shuffle_ps(v58, v58, 201), v59), v57);
  v62 = _mm_add_ps(_mm_shuffle_ps(v60, v60, 78), v60);
  v63.m_vec.m_quad = (__m128)schema->m_pivotFromOffsetB;
  v64 = _mm_shuffle_ps(v61, _mm_unpackhi_ps(v61, _mm_add_ps(_mm_shuffle_ps(v62, v62, 177), v62)), 196);
  v229 = _mm_mul_ps(_mm_sub_ps((__m128)0i64, _mm_shuffle_ps(v23.m_quad, v23.m_quad, 255)), v64);
  v65 = _mm_xor_ps(
          (__m128)_mm_slli_epi32(_mm_srli_epi32((__m128i)xmmword_141A9E9C0, 0x1Fu), 0x1Fu),
          _mm_shuffle_ps(v64, v64, 27));
  v66 = v65;
  v67 = _mm_xor_ps(
          (__m128)_mm_slli_epi32(_mm_srli_epi32((__m128i)xmmword_141A9E9E0, 0x1Fu), 0x1Fu),
          _mm_shuffle_ps(v64, v64, 78));
  v68 = _mm_xor_ps(
          (__m128)_mm_slli_epi32(_mm_srli_epi32((__m128i)xmmword_141A9E9B0, 0x1Fu), 0x1Fu),
          _mm_shuffle_ps(v64, v64, 177));
  v69.m_vec.m_quad = (__m128)schema->m_coreFromPivotB;
  v70 = _mm_mul_ps(v48, v69.m_vec.m_quad);
  v71 = _mm_mul_ps(_mm_shuffle_ps(v63.m_vec.m_quad, v63.m_vec.m_quad, 201), v69.m_vec.m_quad);
  v72 = _mm_mul_ps(_mm_shuffle_ps(v69.m_vec.m_quad, v69.m_vec.m_quad, 201), v63.m_vec.m_quad);
  v73 = _mm_mul_ps(v69.m_vec.m_quad, v63.m_vec.m_quad);
  v74 = _mm_sub_ps(v71, v72);
  v75 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v74, v74, 201), _mm_mul_ps(v15, v63.m_vec.m_quad)), v70);
  v76 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64);
  v77 = v76;
  v78 = _mm_xor_ps(
          v76,
          _mm_shuffle_ps(
            v75,
            _mm_unpackhi_ps(
              v75,
              _mm_sub_ps(
                _mm_mul_ps(v48, v15),
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v73, v73, 85), _mm_shuffle_ps(v73, v73, 0)),
                  _mm_shuffle_ps(v73, v73, 170)))),
            196));
  v79 = transform.m_quad;
  v80 = _mm_add_ps(v78, v78);
  v81 = _mm_mul_ps(_mm_shuffle_ps(v80, v80, 165), _mm_shuffle_ps(v78, v78, 65));
  v72.m128_f32[0] = v78.m128_f32[0] * v80.m128_f32[0];
  v79.m128_f32[0] = (float)(1.0 - (float)(v78.m128_f32[0] * v80.m128_f32[0])) - v81.m128_f32[0];
  v82 = _mm_xor_ps(v81, (__m128)`hkVector4UtilImpl<float>::convertQuaternionToRotation'::`2'::negateMask0);
  v83 = _mm_xor_ps(
          _mm_mul_ps(_mm_shuffle_ps(v78, v78, 254), _mm_shuffle_ps(v80, v80, 26)),
          (__m128)`hkVector4UtilImpl<float>::convertQuaternionToRotation'::`2'::negateMask1);
  v83.m128_f32[0] = v83.m128_f32[0] + 1.0;
  v84 = _mm_sub_ps(v83, v82);
  v82.m128_f32[0] = v72.m128_f32[0];
  v85 = _mm_sub_ps(
          _mm_xor_ps(v83, (__m128)`hkVector4UtilImpl<float>::convertQuaternionToRotation'::`2'::negateMask0),
          v82);
  v86 = _mm_shuffle_ps(v85, v85, 177);
  v87 = _mm_mul_ps(v84, v65);
  v88 = _mm_mul_ps(v86, v65);
  v89 = _mm_shuffle_ps(_mm_movehl_ps(v84, v86), v79, 141);
  v90 = v84;
  v91 = _mm_unpacklo_ps(v87, v88);
  v92 = _mm_mul_ps(v89, v65);
  v93 = _mm_unpackhi_ps(v87, v88);
  v94 = _mm_mul_ps(v90, v67);
  v95 = _mm_mul_ps(v86, v67);
  v96 = _mm_mul_ps(v86, v68);
  v97 = _mm_movelh_ps(v91, v92);
  v98 = _mm_movehl_ps(v97, v91);
  v99 = v94;
  v100 = _mm_unpackhi_ps(v94, v95);
  v101 = _mm_unpacklo_ps(v99, v95);
  v102 = _mm_mul_ps(v90, v68);
  v103 = _mm_unpacklo_ps(v102, v96);
  v104 = _mm_unpackhi_ps(v102, v96);
  v105 = _mm_mul_ps(v89, v67);
  v106 = _mm_mul_ps(v89, v68);
  v107 = _mm_movelh_ps(v101, v105);
  v108 = _mm_movelh_ps(v103, v106);
  v228 = _mm_mul_ps(
           _mm_add_ps(_mm_shuffle_ps(v93, v92, 228), _mm_add_ps(v97, _mm_shuffle_ps(v98, v92, 212))),
           (__m128)xmmword_141A711B0);
  v227 = _mm_mul_ps(
           _mm_add_ps(
             _mm_shuffle_ps(v100, v105, 228),
             _mm_add_ps(v107, _mm_shuffle_ps(_mm_movehl_ps(v107, v101), v105, 212))),
           (__m128)xmmword_141A711B0);
  v109 = _mm_mul_ps(
           _mm_add_ps(
             _mm_shuffle_ps(v104, v106, 228),
             _mm_add_ps(v108, _mm_shuffle_ps(_mm_movehl_ps(v108, v103), v106, 212))),
           (__m128)xmmword_141A711B0);
  v110 = _mm_unpacklo_ps(v66, v67);
  v226 = v109;
  v111.m_vec.m_quad = (__m128)schema->m_pivotFromOffsetA;
  v112.m_vec.m_quad = (__m128)schema->m_coreFromPivotA;
  v113 = _mm_shuffle_ps(_mm_unpackhi_ps(v66, v67), v68, 228);
  v114 = _mm_movelh_ps(v110, v68);
  v115 = _mm_mul_ps(v56, v112.m_vec.m_quad);
  v116 = _mm_shuffle_ps(_mm_movehl_ps(v114, v110), v68, 212);
  v117 = _mm_shuffle_ps(v112.m_vec.m_quad, v112.m_vec.m_quad, 201);
  v118 = _mm_mul_ps(_mm_shuffle_ps(v111.m_vec.m_quad, v111.m_vec.m_quad, 201), v112.m_vec.m_quad);
  v119 = _mm_mul_ps(v112.m_vec.m_quad, v111.m_vec.m_quad);
  v120 = _mm_sub_ps(v118, _mm_mul_ps(v117, v111.m_vec.m_quad));
  v121 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v120, v120, 201), _mm_mul_ps(v8, v111.m_vec.m_quad)), v115);
  v122 = _mm_xor_ps(
           v77,
           _mm_shuffle_ps(
             v121,
             _mm_unpackhi_ps(
               v121,
               _mm_sub_ps(
                 _mm_mul_ps(v56, v8),
                 _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v119, v119, 85), _mm_shuffle_ps(v119, v119, 0)),
                   _mm_shuffle_ps(v119, v119, 170)))),
             196));
  v123 = transform.m_quad;
  v124 = _mm_add_ps(v122, v122);
  v125 = _mm_mul_ps(_mm_shuffle_ps(v124, v124, 165), _mm_shuffle_ps(v122, v122, 65));
  v117.m128_f32[0] = v122.m128_f32[0] * v124.m128_f32[0];
  v123.m128_f32[0] = (float)(1.0 - (float)(v122.m128_f32[0] * v124.m128_f32[0])) - v125.m128_f32[0];
  v126 = _mm_xor_ps(v125, (__m128)`hkVector4UtilImpl<float>::convertQuaternionToRotation'::`2'::negateMask0);
  v127 = _mm_xor_ps(
           _mm_mul_ps(_mm_shuffle_ps(v122, v122, 254), _mm_shuffle_ps(v124, v124, 26)),
           (__m128)`hkVector4UtilImpl<float>::convertQuaternionToRotation'::`2'::negateMask1);
  v127.m128_f32[0] = v127.m128_f32[0] + 1.0;
  v128 = _mm_sub_ps(v127, v126);
  v126.m128_f32[0] = v117.m128_f32[0];
  v129 = _mm_sub_ps(
           _mm_xor_ps(v127, (__m128)`hkVector4UtilImpl<float>::convertQuaternionToRotation'::`2'::negateMask0),
           v126);
  v130 = _mm_mul_ps(v128, v114);
  v131 = _mm_shuffle_ps(v129, v129, 177);
  v132 = _mm_mul_ps(v131, v114);
  v133 = _mm_shuffle_ps(_mm_movehl_ps(v128, v131), v123, 141);
  v134 = _mm_mul_ps(v133, v114);
  v135 = _mm_unpacklo_ps(v130, v132);
  v136 = _mm_movelh_ps(v135, v134);
  v137 = _mm_mul_ps(v128, v116);
  v138 = _mm_add_ps(
           _mm_shuffle_ps(_mm_unpackhi_ps(v130, v132), v134, 228),
           _mm_add_ps(v136, _mm_shuffle_ps(_mm_movehl_ps(v136, v135), v134, 212)));
  v139 = _mm_mul_ps(v131, v116);
  v140 = _mm_mul_ps(v133, v116);
  v141 = _mm_unpacklo_ps(v137, v139);
  v142 = _mm_unpackhi_ps(v137, v139);
  v143 = _mm_movelh_ps(v141, v140);
  v144 = _mm_mul_ps(v128, v113);
  v145 = _mm_mul_ps(v133, v113);
  v146 = _mm_mul_ps(v131, v113);
  v147 = _mm_unpacklo_ps(v144, v146);
  v148 = _mm_movelh_ps(v147, v145);
  v149 = _mm_add_ps(v143, _mm_shuffle_ps(_mm_movehl_ps(v143, v141), v140, 212));
  v150 = _mm_shuffle_ps(_mm_movehl_ps(v148, v147), v145, 212);
  v151 = _mm_sub_ps((__m128)0i64, (__m128)xmmword_141A711B0);
  v152 = _mm_mul_ps(v138, v151);
  v153 = _mm_mul_ps(_mm_add_ps(_mm_shuffle_ps(v142, v140, 228), v149), v151);
  v154 = _mm_mul_ps(_mm_add_ps(_mm_shuffle_ps(_mm_unpackhi_ps(v144, v146), v145, 228), _mm_add_ps(v148, v150)), v151);
  v155.m_quad = (__m128)mA->m_invMasses;
  v156 = _mm_mul_ps(v152, v155.m_quad);
  v157 = _mm_mul_ps(v153, v155.m_quad);
  v158 = _mm_mul_ps(v154, v155.m_quad);
  v159 = _mm_mul_ps(v152, v156);
  v160 = _mm_mul_ps(v153, v157);
  v161 = _mm_mul_ps(v154, v158);
  v162 = _mm_unpacklo_ps(v159, v160);
  v163 = _mm_shuffle_ps(_mm_unpackhi_ps(v159, v160), v161, 228);
  v164 = _mm_movelh_ps(v162, v161);
  v165 = _mm_add_ps(v164, _mm_shuffle_ps(_mm_movehl_ps(v164, v162), v161, 212));
  v166 = _mm_mul_ps(v152, v158);
  v167 = _mm_add_ps(v165, v163);
  v168 = _mm_mul_ps(v154, v157);
  v169 = _mm_mul_ps(v153, v156);
  v170 = _mm_unpacklo_ps(v169, v168);
  v171 = _mm_movelh_ps(v170, v166);
  v172 = _mm_add_ps(
           _mm_add_ps(v171, _mm_shuffle_ps(_mm_movehl_ps(v171, v170), v166, 212)),
           _mm_shuffle_ps(_mm_unpackhi_ps(v169, v168), v166, 228));
  v173.m_quad = (__m128)mB->m_invMasses;
  v174 = _mm_mul_ps(v228, v173.m_quad);
  v175 = _mm_mul_ps(v227, v173.m_quad);
  v176 = _mm_mul_ps(v226, v173.m_quad);
  v177 = _mm_mul_ps(v228, v174);
  v178 = _mm_mul_ps(v227, v175);
  v179 = _mm_mul_ps(v226, v176);
  v180 = _mm_unpacklo_ps(v177, v178);
  v181 = _mm_shuffle_ps(_mm_unpackhi_ps(v177, v178), v179, 228);
  v182 = _mm_movelh_ps(v180, v179);
  v183 = _mm_add_ps(v182, _mm_shuffle_ps(_mm_movehl_ps(v182, v180), v179, 212));
  v184 = _mm_mul_ps(v228, v176);
  v185 = _mm_mul_ps(v226, v175);
  v186 = (__m128i)_mm_add_ps(_mm_add_ps(v183, v181), v167);
  v187 = _mm_mul_ps(v227, v174);
  v188 = _mm_unpacklo_ps(v187, v185);
  v189 = _mm_movelh_ps(v188, v184);
  v190 = (__m128i)_mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(v189, _mm_shuffle_ps(_mm_movehl_ps(v189, v188), v184, 212)),
                      _mm_shuffle_ps(_mm_unpackhi_ps(v187, v185), v184, 228)),
                    v172);
  v191 = _mm_max_ps(
           (__m128)_mm_srli_epi32(_mm_slli_epi32(v186, 1u), 1u),
           (__m128)_mm_srli_epi32(_mm_slli_epi32(v190, 1u), 1u));
  v192 = _mm_max_ps(
           _mm_shuffle_ps(v191, v191, 170),
           _mm_max_ps(_mm_shuffle_ps(v191, v191, 85), _mm_shuffle_ps(v191, v191, 0)));
  v193 = _mm_andnot_ps(_mm_cmpeqps(v192, (__m128)0i64), _mm_div_ps(query.m_quad, v192));
  v194 = _mm_mul_ps((__m128)v186, v193);
  v195 = _mm_mul_ps((__m128)v190, v193);
  v196 = _mm_shuffle_ps(v194, v194, 210);
  v197 = _mm_shuffle_ps(v195, v195, 201);
  v198 = _mm_mul_ps(_mm_shuffle_ps(v194, v194, 201), v196);
  v199 = _mm_mul_ps(v198, v194);
  v200 = 3;
  v201 = _mm_mul_ps(v197, v197);
  v202 = _mm_sub_ps(v198, v201);
  v203 = _mm_mul_ps(_mm_shuffle_ps(v195, v195, 210), v197);
  v204 = _mm_mul_ps(v201, v194);
  v205 = v203;
  v206 = _mm_sub_ps(v203, _mm_mul_ps(v196, v195));
  v207 = _mm_add_ps(v199, _mm_mul_ps(_mm_mul_ps(v205, v195), (__m128)xmmword_141A710D0));
  v208 = (__m128i)_mm_sub_ps(
                    _mm_shuffle_ps(v207, v207, 0),
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v204, v204, 85), _mm_shuffle_ps(v204, v204, 0)),
                      _mm_shuffle_ps(v204, v204, 170)));
  v209 = _mm_rcp_ps((__m128)v208);
  v210 = _mm_mul_ps(
           _mm_and_ps(
             _mm_cmpltps(*(__m128 *)&epsilon, (__m128)_mm_srli_epi32(_mm_slli_epi32(v208, 1u), 1u)),
             _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v209, (__m128)v208)), v209)),
           v193);
  v211 = _mm_xor_ps(v77, v230);
  v212 = v210;
  v213 = _mm_mul_ps(v210, v206);
  v214 = _mm_mul_ps(v213, v229);
  v215 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v229, v229, 201), v213), _mm_mul_ps(_mm_mul_ps(v212, v202), v229));
  v216 = _mm_rcp_ps((__m128)v186);
  v217 = _mm_add_ps(v215, _mm_shuffle_ps(v214, v214, 210));
  v218 = _mm_andnot_ps(
           _mm_cmpeqps((__m128)0i64, (__m128)v186),
           _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v216, (__m128)v186)), v216));
  do
  {
    --v200;
    v219 = _mm_mul_ps((__m128)v190, v217);
    v217 = _mm_max_ps(
             _mm_min_ps(
               _mm_mul_ps(
                 _mm_sub_ps(
                   v229,
                   _mm_add_ps(
                     _mm_shuffle_ps(v219, v219, 210),
                     _mm_mul_ps(_mm_shuffle_ps(v217, v217, 201), (__m128)v190))),
                 v218),
               v230),
             v211);
  }
  while ( v200 >= 0 );
  v220 = _mm_shuffle_ps(v217, v217, 85);
  v221 = _mm_shuffle_ps(v217, v217, 0);
  v222 = _mm_shuffle_ps(v217, v217, 170);
  v223 = (__m128)LODWORD(temps[2].m_impulseApplied);
  mB->m_angularVel.m_quad = _mm_add_ps(
                              _mm_mul_ps(
                                _mm_add_ps(
                                  _mm_add_ps(_mm_mul_ps(v221, v228), _mm_mul_ps(v220, v227)),
                                  _mm_mul_ps(v222, v226)),
                                mB->m_invMasses.m_quad),
                              mB->m_angularVel.m_quad);
  v224 = _mm_add_ps(_mm_movelh_ps((__m128)*(unsigned __int64 *)&temps->m_impulseApplied, v223), v217);
  v225.m_quad = _mm_add_ps(
                  _mm_mul_ps(
                    _mm_add_ps(_mm_add_ps(_mm_mul_ps(v221, v152), _mm_mul_ps(v220, v153)), _mm_mul_ps(v222, v154)),
                    mA->m_invMasses.m_quad),
                  mA->m_angularVel.m_quad);
  *(_QWORD *)&temps->m_impulseApplied = v224.m128_u64[0];
  LODWORD(temps[2].m_impulseApplied) = (unsigned __int128)_mm_movehl_ps(v224, v224);
  mA->m_angularVel = (hkVector4f)v225.m_quad;
}

// File Line: 911
// RVA: 0xDE3CA0
void __fastcall hkpAtomSolverFunctions::solveDeformableLinConstraintStub<hkpVelocityAccumulator,hkpSolverInfo,hkSolverStepTemp>(hkpSolverInfo *solverInfo, hkSolverStepTemp *temp, hkpDeformableLinSchema *schema, hkpVelocityAccumulator *mA, hkpVelocityAccumulator *mB, hkpSolverElemTemp *temps)
{
  hkpVelocityAccumulator *v6; // rdi
  hkpDeformableLinSchema *v7; // rsi
  hkQTransformf coreToWorldB; // [rsp+50h] [rbp-48h]
  hkQTransformf coreToWorldA; // [rsp+70h] [rbp-28h]

  v6 = mA;
  v7 = schema;
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
    v7,
    v6,
    mB,
    temps);
}

// File Line: 931
// RVA: 0xDE34E0
void __fastcall hkpAtomSolverFunctions::solveDeformableAngConstraintStub<hkpVelocityAccumulator,hkpSolverInfo,hkSolverStepTemp>(hkpSolverInfo *solverInfo, hkSolverStepTemp *temp, hkpDeformableAngSchema *schema, hkpVelocityAccumulator *mA, hkpVelocityAccumulator *mB, hkpSolverElemTemp *temps)
{
  hkpVelocityAccumulator *v6; // rdi
  hkpDeformableAngSchema *v7; // rsi
  hkQTransformf coreToWorldB; // [rsp+50h] [rbp-48h]
  hkQTransformf coreToWorldA; // [rsp+70h] [rbp-28h]

  v6 = mA;
  v7 = schema;
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
    v7,
    v6,
    mB,
    temps);
}

// File Line: 1056
// RVA: 0xDE2240
void __fastcall hkpAtomSolverFunctions::solve1dBilateralWithImpulseLimit<hkpVelocityAccumulator,hkpSolverInfo,hkSolverStepTemp>(hkpSolverInfo *info, hkSolverStepTemp *temp, hkpJacobian1dBilateralSchema *schema, hkpVelocityAccumulator *mA, hkpVelocityAccumulator *mB, hkpSolverElemTemp *temps)
{
  hkVector4f v6; // xmm5
  __m128 v7; // xmm3
  __m128 v8; // xmm6
  hkVector4f v9; // xmm7
  __m128 v10; // xmm8
  __m128 v11; // xmm0
  __m128 v12; // xmm8
  __m128 v13; // xmm2
  __m128 v14; // xmm8
  __m128 v15; // xmm2
  __m128 v16; // xmm1
  __m128 v17; // xmm0
  __m128 v18; // xmm2
  hkVector4f v19; // xmm7
  __m128 v20; // xmm0
  hkVector4f v21; // xmm0

  v6.m_quad = (__m128)schema->m_jac.m_linear0;
  v7 = schema->m_jac.m_angular[0].m_quad;
  v8 = _mm_shuffle_ps((__m128)LODWORD(temps->m_impulseApplied), (__m128)LODWORD(temps->m_impulseApplied), 0);
  v9.m_quad = (__m128)mB->m_linearVel;
  v10 = schema->m_jac.m_angular[1].m_quad;
  v11 = v10;
  v12 = _mm_shuffle_ps(v10, v10, 255);
  v13 = _mm_add_ps(
          _mm_add_ps(_mm_mul_ps(mA->m_angularVel.m_quad, v7), _mm_mul_ps(v11, mB->m_angularVel.m_quad)),
          _mm_mul_ps(_mm_sub_ps(mA->m_linearVel.m_quad, v9.m_quad), schema->m_jac.m_linear0.m_quad));
  v14 = _mm_min_ps(
          _mm_sub_ps(v12, v8),
          _mm_max_ps(
            _mm_sub_ps(_mm_sub_ps((__m128)0i64, v12), v8),
            _mm_mul_ps(
              _mm_sub_ps(
                _mm_shuffle_ps(v6.m_quad, v6.m_quad, 255),
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)),
                  _mm_shuffle_ps(v13, v13, 170))),
              _mm_shuffle_ps(v7, v7, 255))));
  v15 = _mm_mul_ps(mB->m_invMasses.m_quad, v14);
  v16 = _mm_mul_ps(mA->m_invMasses.m_quad, v14);
  temps->m_impulseApplied = v8.m128_f32[0] + v14.m128_f32[0];
  mA->m_linearVel.m_quad = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v16, v16, 255), v6.m_quad), mA->m_linearVel.m_quad);
  v17 = _mm_shuffle_ps(v15, v15, 255);
  v18 = _mm_mul_ps(v15, schema->m_jac.m_angular[1].m_quad);
  v19.m_quad = _mm_sub_ps(v9.m_quad, _mm_mul_ps(v17, v6.m_quad));
  v20 = _mm_mul_ps(schema->m_jac.m_angular[0].m_quad, v16);
  mB->m_linearVel = (hkVector4f)v19.m_quad;
  v21.m_quad = _mm_add_ps(v20, mA->m_angularVel.m_quad);
  mB->m_angularVel.m_quad = _mm_add_ps(v18, mB->m_angularVel.m_quad);
  mA->m_angularVel = (hkVector4f)v21.m_quad;
}

// File Line: 1075
// RVA: 0xDE20C0
void __fastcall hkpAtomSolverFunctions::solve1dBilateralUserTau<hkpVelocityAccumulator,hkpSolverInfo,hkSolverStepTemp>(hkpSolverInfo *info, hkSolverStepTemp *temp, hkpJacobian1dBilateralUserTauSchema *schema, hkpVelocityAccumulator *mA, hkpVelocityAccumulator *mB, hkpSolverElemTemp *temps)
{
  __m128 v6; // xmm5
  hkVector4f v7; // xmm8
  __m128 v8; // xmm6
  hkVector4f v9; // xmm9
  __m128 v10; // xmm10
  __m128 v11; // xmm4
  __m128 v12; // xmm3
  __m128 v13; // xmm2
  __m128 v14; // xmm1
  __m128 v15; // xmm0
  __m128 v16; // xmm2

  v6 = schema->m_jac.m_angular[0].m_quad;
  v7.m_quad = (__m128)schema->m_jac.m_linear0;
  v8 = _mm_shuffle_ps((__m128)LODWORD(schema->m_tau), (__m128)LODWORD(schema->m_tau), 0);
  v9.m_quad = (__m128)mB->m_linearVel;
  v10 = schema->m_jac.m_angular[1].m_quad;
  v11 = _mm_add_ps(
          _mm_mul_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_sub_ps(mA->m_angularVel.m_quad, mA->m_scratch1.m_quad), v6),
                _mm_mul_ps(_mm_sub_ps(mB->m_angularVel.m_quad, mB->m_scratch1.m_quad), v10)),
              _mm_mul_ps(
                _mm_sub_ps(
                  _mm_sub_ps(mA->m_linearVel.m_quad, mA->m_scratch0.m_quad),
                  _mm_sub_ps(mB->m_linearVel.m_quad, mB->m_scratch0.m_quad)),
                schema->m_jac.m_linear0.m_quad)),
            _mm_shuffle_ps((__m128)LODWORD(schema->m_damping), (__m128)LODWORD(schema->m_damping), 0)),
          _mm_mul_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(schema->m_jac.m_angular[1].m_quad, mB->m_scratch1.m_quad),
                _mm_mul_ps(schema->m_jac.m_angular[0].m_quad, mA->m_scratch1.m_quad)),
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
          _mm_shuffle_ps(v6, v6, 255));
  v13 = _mm_mul_ps(mA->m_invMasses.m_quad, v12);
  v14 = _mm_mul_ps(mB->m_invMasses.m_quad, v12);
  v15 = _mm_shuffle_ps(v13, v13, 255);
  v16 = _mm_mul_ps(v13, schema->m_jac.m_angular[0].m_quad);
  mA->m_linearVel.m_quad = _mm_add_ps(_mm_mul_ps(v15, schema->m_jac.m_linear0.m_quad), mA->m_linearVel.m_quad);
  mA->m_angularVel.m_quad = _mm_add_ps(v16, mA->m_angularVel.m_quad);
  mB->m_linearVel.m_quad = _mm_sub_ps(v9.m_quad, _mm_mul_ps(_mm_shuffle_ps(v14, v14, 255), v7.m_quad));
  mB->m_angularVel.m_quad = _mm_add_ps(_mm_mul_ps(v10, v14), mB->m_angularVel.m_quad);
  temps->m_impulseApplied = COERCE_FLOAT(
                              _mm_shuffle_ps(
                                (__m128)LODWORD(temps->m_impulseApplied),
                                (__m128)LODWORD(temps->m_impulseApplied),
                                0))
                          + v12.m128_f32[0];
}

// File Line: 1140
// RVA: 0xDE4170
void __fastcall hkpAtomSolverFunctions::solvePulley<hkpVelocityAccumulator,hkpSolverInfo,hkSolverStepTemp>(hkpSolverInfo *info, hkSolverStepTemp *solverTemp, hkpJacobian1dPulleySchema *schema, hkpVelocityAccumulator *mA, hkpVelocityAccumulator *mB, hkpSolverElemTemp *temps)
{
  __m128 v6; // xmm3
  hkVector4f v7; // xmm8
  __m128 v8; // xmm2
  __m128 v9; // xmm4
  __m128 v10; // xmm1
  __m128 v11; // xmm2
  __m128 v12; // xmm9
  __m128 v13; // xmm0
  hkVector4f v14; // xmm0

  v6 = schema->m_jac.m_angular[0].m_quad;
  v7.m_quad = (__m128)mB->m_linearVel;
  v8 = _mm_add_ps(
         _mm_add_ps(
           _mm_mul_ps(mA->m_angularVel.m_quad, v6),
           _mm_mul_ps(schema->m_jac.m_angular[1].m_quad, mB->m_angularVel.m_quad)),
         _mm_sub_ps(
           _mm_mul_ps(schema->m_jac.m_linear[0].m_quad, mA->m_linearVel.m_quad),
           _mm_mul_ps(schema->m_jac.m_linear[1].m_quad, v7.m_quad)));
  v9 = _mm_mul_ps(
         _mm_sub_ps(
           _mm_shuffle_ps(schema->m_jac.m_linear[0].m_quad, schema->m_jac.m_linear[0].m_quad, 255),
           _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)), _mm_shuffle_ps(v8, v8, 170))),
         _mm_shuffle_ps(v6, v6, 255));
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
  temps->m_impulseApplied = COERCE_FLOAT(
                              _mm_shuffle_ps(
                                (__m128)LODWORD(temps->m_impulseApplied),
                                (__m128)LODWORD(temps->m_impulseApplied),
                                0))
                          + v9.m128_f32[0];
}

// File Line: 1447
// RVA: 0xDE2740
void __fastcall hkpAtomSolverFunctions::solve2dRollingFriction<hkpVelocityAccumulator,hkpSolverInfo,hkSolverStepTemp>(hkpSolverInfo *info, hkSolverStepTemp *temp, hkpJacobian2dRollingFrictionSchema *schema, hkpVelocityAccumulator *mA, hkpVelocityAccumulator *mB, hkpSolverElemTemp *temps)
{
  __m128 v6; // xmm6
  __m128 v7; // xmm8
  __m128 v8; // xmm11
  __m128 v9; // xmm12
  __m128 v10; // xmm2
  __m128 v11; // xmm3
  __m128 v12; // xmm7
  __m128 v13; // xmm5
  __m128 v14; // xmm1
  __m128 v15; // xmm4
  __m128 v16; // xmm2
  __m128 v17; // xmm3
  __m128 v18; // xmm1
  __m128 v19; // xmm6
  hkpSolverElemTemp *v20; // rax
  __m128 v21; // xmm2
  __m128 v22; // xmm3
  hkVector4f v23; // xmm2
  hkVector4f v24; // xmm3
  __m128 v25; // xmm0
  __m128 v26; // xmm1

  v6 = _mm_shuffle_ps((__m128)LODWORD(schema->m_maxImpulse), (__m128)LODWORD(schema->m_maxImpulse), 0);
  v7 = schema->m_jac0.m_angular[0].m_quad;
  v8 = schema->m_jac1.m_angular[0].m_quad;
  v9 = schema->m_jac1.m_angular[1].m_quad;
  v10 = _mm_add_ps(
          _mm_mul_ps(schema->m_jac0.m_angular[0].m_quad, mA->m_angularVel.m_quad),
          _mm_mul_ps(schema->m_jac0.m_angular[1].m_quad, mB->m_angularVel.m_quad));
  v11 = _mm_add_ps(
          _mm_mul_ps(schema->m_jac1.m_angular[0].m_quad, mA->m_angularVel.m_quad),
          _mm_mul_ps(v9, mB->m_angularVel.m_quad));
  v12 = _mm_mul_ps(
          _mm_sub_ps(
            _mm_shuffle_ps(schema->m_jac0.m_angular[1].m_quad, schema->m_jac0.m_angular[1].m_quad, 255),
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)),
              _mm_shuffle_ps(v10, v10, 170))),
          _mm_shuffle_ps(v7, v7, 255));
  v13 = _mm_mul_ps(
          _mm_sub_ps(
            _mm_shuffle_ps(schema->m_jac1.m_angular[1].m_quad, v9, 255),
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)),
              _mm_shuffle_ps(v11, v11, 170))),
          _mm_shuffle_ps(v8, v8, 255));
  v14 = _mm_add_ps(_mm_mul_ps(v13, v13), _mm_mul_ps(v12, v12));
  v15 = _mm_cmpltps(_mm_mul_ps(v6, v6), v14);
  v16 = _mm_rsqrt_ps(v14);
  v17 = _mm_mul_ps(
          _mm_andnot_ps(
            _mm_cmpleps(v14, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v16, v14), v16)),
              _mm_mul_ps(*(__m128 *)_xmm, v16))),
          v6);
  v18 = _mm_or_ps(_mm_and_ps(_mm_mul_ps(v17, v12), v15), _mm_andnot_ps(v15, v12));
  v19 = _mm_or_ps(_mm_and_ps(_mm_mul_ps(v17, v13), v15), _mm_andnot_ps(v15, v13));
  v20 = temps;
  v21 = _mm_mul_ps(mB->m_invMasses.m_quad, v18);
  LODWORD(temps[2].m_impulseApplied) = v17.m128_i32[0] & v15.m128_i32[0] | *(unsigned __int128 *)&_mm_andnot_ps(
                                                                                                    v15,
                                                                                                    query.m_quad);
  v22 = _mm_mul_ps(mA->m_invMasses.m_quad, v18);
  v23.m_quad = _mm_add_ps(_mm_mul_ps(v21, schema->m_jac0.m_angular[1].m_quad), mB->m_angularVel.m_quad);
  v20->m_impulseApplied = COERCE_FLOAT(
                            _mm_shuffle_ps(
                              (__m128)LODWORD(v20->m_impulseApplied),
                              (__m128)LODWORD(v20->m_impulseApplied),
                              0))
                        + v18.m128_f32[0];
  mB->m_angularVel = (hkVector4f)v23.m_quad;
  v24.m_quad = _mm_add_ps(_mm_mul_ps(v22, v7), mA->m_angularVel.m_quad);
  v25 = _mm_mul_ps(_mm_mul_ps(mB->m_invMasses.m_quad, v19), v9);
  mA->m_angularVel = (hkVector4f)v24.m_quad;
  v26 = _mm_mul_ps(_mm_mul_ps(mA->m_invMasses.m_quad, v19), v8);
  mB->m_angularVel.m_quad = _mm_add_ps(v25, v23.m_quad);
  v25.m128_f32[0] = COERCE_FLOAT(
                      _mm_shuffle_ps(
                        (__m128)LODWORD(v20[1].m_impulseApplied),
                        (__m128)LODWORD(v20[1].m_impulseApplied),
                        0))
                  + v19.m128_f32[0];
  mA->m_angularVel.m_quad = _mm_add_ps(v26, v24.m_quad);
  temps[1].m_impulseApplied = v25.m128_f32[0];
}

// File Line: 1624
// RVA: 0xDE2510
void __fastcall hkpAtomSolverFunctions::solve1dLinearMotor<hkpVelocityAccumulator,hkpSolverInfo,hkSolverStepTemp>(hknpSimulationThreadContext *tl, hkpSolverInfo *info, hkSolverStepTemp *temp, hkpJacobian1dLinearMotorSchema *schema, hkpVelocityAccumulator *mA, hkpVelocityAccumulator *mB, hkpSolverElemTemp *temps)
{
  __m128 *v7; // r10
  __m128 v8; // xmm7
  __m128 v9; // xmm9
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
  unsigned int v21; // xmm3_4
  __m128 v22; // xmm2
  __m128 v23; // xmm1
  int v24; // xmm0_4
  hkVector4f v25; // xmm2
  __m128 v26; // xmm7
  __m128 v27; // xmm1
  __m128 v28; // xmm2
  __m128 v29; // xmm0
  __m128 v30; // xmm1
  __m128 v31; // xmm0
  __m128 v32; // xmm2
  hkVector4f v33; // xmm12

  v7 = (__m128 *)schema;
  v8 = _mm_shuffle_ps(
         (__m128)LODWORD(schema->m_motorSolverInfo.m_tau),
         (__m128)LODWORD(schema->m_motorSolverInfo.m_tau),
         0);
  v9 = schema->m_jac.m_angular[0].m_quad;
  v10.m_quad = (__m128)schema->m_jac.m_linear0;
  v11.m_quad = (__m128)mB->m_linearVel;
  v12 = _mm_add_ps(
          _mm_mul_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_sub_ps(mB->m_angularVel.m_quad, mB->m_scratch1.m_quad),
                  schema->m_jac.m_angular[1].m_quad),
                _mm_mul_ps(_mm_sub_ps(mA->m_angularVel.m_quad, mA->m_scratch1.m_quad), v9)),
              _mm_mul_ps(
                _mm_sub_ps(
                  _mm_sub_ps(mA->m_linearVel.m_quad, mA->m_scratch0.m_quad),
                  _mm_sub_ps(mB->m_linearVel.m_quad, mB->m_scratch0.m_quad)),
                *v7)),
            _mm_shuffle_ps((__m128)v7[4].m128_u32[0], (__m128)v7[4].m128_u32[0], 0)),
          _mm_mul_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(mB->m_scratch1.m_quad, schema->m_jac.m_angular[1].m_quad),
                _mm_mul_ps(mA->m_scratch1.m_quad, v9)),
              _mm_mul_ps(_mm_sub_ps(mA->m_scratch0.m_quad, mB->m_scratch0.m_quad), *v7)),
            _mm_mul_ps(
              _mm_shuffle_ps(info->m_invIntegrateVelocityFactor.m_quad, info->m_invIntegrateVelocityFactor.m_quad, 0),
              v8)));
  v13 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)), _mm_shuffle_ps(v12, v12, 170));
  v14 = _mm_shuffle_ps((__m128)v7[3].m128_u32[0], (__m128)v7[3].m128_u32[0], 0);
  v15 = _mm_sub_ps(
          _mm_mul_ps(
            _mm_add_ps(
              _mm_mul_ps(
                _mm_shuffle_ps((__m128)v7[3].m128_u32[2], (__m128)v7[3].m128_u32[2], 0),
                temp->m_intregratePositionFactor.m_real),
              _mm_shuffle_ps(v10.m_quad, v10.m_quad, 255)),
            v8),
          v13);
  v16 = _mm_shuffle_ps((__m128)v7[3].m128_u32[1], (__m128)v7[3].m128_u32[1], 0);
  v17 = _mm_mul_ps(v15, _mm_shuffle_ps(v9, v9, 255));
  v18 = _mm_rcp_ps(v17);
  v19 = _mm_cmpltps(v14, v17);
  v20 = _mm_cmpltps(v17, v16);
  v21 = COERCE_UNSIGNED_INT((float)((float)(2.0 - (float)(v18.m128_f32[0] * v17.m128_f32[0])) * v18.m128_f32[0]) * v14.m128_f32[0]) & v19.m128_i32[0];
  v22 = _mm_and_ps(_mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v18, v17)), v18), v16), v20);
  v23 = _mm_cmpltps(v17, v14);
  v24 = (unsigned __int128)_mm_andnot_ps(v19, _mm_or_ps(v22, _mm_andnot_ps(v20, query.m_quad)));
  v25.m_quad = (__m128)mB->m_invMasses;
  LODWORD(temps[1].m_impulseApplied) = v24 | v21;
  v26 = _mm_max_ps(v16, _mm_or_ps(_mm_and_ps(v23, v17), _mm_andnot_ps(v23, v14)));
  v27 = _mm_mul_ps(mA->m_invMasses.m_quad, v26);
  v28 = _mm_mul_ps(v25.m_quad, v26);
  v29 = _mm_shuffle_ps(v27, v27, 255);
  v30 = _mm_mul_ps(v27, schema->m_jac.m_angular[0].m_quad);
  mA->m_linearVel.m_quad = _mm_add_ps(_mm_mul_ps(v29, v10.m_quad), mA->m_linearVel.m_quad);
  v31 = _mm_shuffle_ps(v28, v28, 255);
  v32 = _mm_mul_ps(v28, schema->m_jac.m_angular[1].m_quad);
  mA->m_angularVel.m_quad = _mm_add_ps(v30, mA->m_angularVel.m_quad);
  v33.m_quad = _mm_sub_ps(v11.m_quad, _mm_mul_ps(v31, v10.m_quad));
  v31.m128_i32[0] = (unsigned __int128)_mm_shuffle_ps(
                                         (__m128)LODWORD(temps->m_impulseApplied),
                                         (__m128)LODWORD(temps->m_impulseApplied),
                                         0);
  mB->m_linearVel = (hkVector4f)v33.m_quad;
  mB->m_angularVel.m_quad = _mm_add_ps(v32, mB->m_angularVel.m_quad);
  temps->m_impulseApplied = v31.m128_f32[0] + v26.m128_f32[0];
}

