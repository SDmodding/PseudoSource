// File Line: 48
// RVA: 0x132AA20
void __fastcall hkPoweredChainBuildJacobian(hkpPoweredChainBuildJacobianParams *params, hkpConstraintQueryIn *in, hkpConstraintQueryOut *out)
{
  __int64 v3; // rdi
  hkp3dAngularMotorSolverInfo *v4; // r9
  float v5; // xmm2_4
  float v6; // xmm1_4
  hkpVelocityAccumulatorOffset *v7; // r10
  hkpJacobianSchema *v8; // rbx
  hkpPoweredChainBuildJacobianParams *v9; // rsi
  hkpConstraintQueryOut *v10; // r14
  float v11; // xmm0_4
  unsigned __int64 v12; // rdx
  __int64 v13; // rcx
  unsigned int v14; // eax
  signed __int64 v15; // rcx
  __int64 v16; // rdx
  int v17; // eax
  __int64 v18; // rdx

  v3 = (unsigned int)params->m_numConstraints;
  v4 = params->m_motorsState;
  v5 = params->m_chainDamping;
  v6 = params->m_chainTau;
  v7 = params->m_accumulators;
  v8 = out->m_jacobianSchemas.m_storage;
  v9 = params;
  *(_QWORD *)&v8[8] = params->m_childConstraintStatusWriteBackBuffer;
  v10 = out;
  v11 = *(float *)v8;
  *(float *)&v8[24] = v6;
  *(float *)&v8[28] = v5;
  *(_WORD *)&v8[4] = v3;
  *(float *)v8 = v11 + 0.00000011920929;
  *v8 = (hkpJacobianSchema)42;
  *(_DWORD *)&v8[16] = (240 * (unsigned __int16)v3 + 1092 * (unsigned __int16)v3 + 83) & 0xFFFFFFF0;
  if ( (signed int)v3 + 1 > 0 )
  {
    v12 = &v8[1024 * (unsigned __int64)(unsigned __int16)v3 + 64 + 240 * (unsigned __int16)v3] - (hkpJacobianSchema *)v7;
    v13 = (unsigned int)(v3 + 1);
    do
    {
      v14 = v7->m_offset;
      ++v7;
      *(unsigned int *)((char *)&v7[-1].m_offset + v12) = v14;
      --v13;
    }
    while ( v13 );
  }
  v15 = (signed __int64)&v8[1028 * *(unsigned __int16 *)&v8[4] + 68 + 240 * *(unsigned __int16 *)&v8[4]];
  if ( (signed int)v3 > 0 )
  {
    v16 = v3;
    do
    {
      v17 = *(_DWORD *)&v4->m_broken;
      v15 += 64i64;
      ++v4;
      *(_DWORD *)(v15 - 64) = v17;
      *(float *)(v15 - 60) = v4[-1].m_motorInfos[0].m_maxImpulsePerSubstep;
      *(float *)(v15 - 56) = v4[-1].m_motorInfos[0].m_minImpulsePerSubstep;
      *(float *)(v15 - 52) = v4[-1].m_motorInfos[0].m_velocity;
      *(float *)(v15 - 48) = v4[-1].m_motorInfos[0].m_tau;
      *(float *)(v15 - 44) = v4[-1].m_motorInfos[0].m_damping;
      *(float *)(v15 - 40) = v4[-1].m_motorInfos[1].m_maxImpulsePerSubstep;
      *(float *)(v15 - 36) = v4[-1].m_motorInfos[1].m_minImpulsePerSubstep;
      *(float *)(v15 - 32) = v4[-1].m_motorInfos[1].m_velocity;
      *(float *)(v15 - 28) = v4[-1].m_motorInfos[1].m_tau;
      *(float *)(v15 - 24) = v4[-1].m_motorInfos[1].m_damping;
      *(float *)(v15 - 20) = v4[-1].m_motorInfos[2].m_maxImpulsePerSubstep;
      *(float *)(v15 - 16) = v4[-1].m_motorInfos[2].m_minImpulsePerSubstep;
      *(float *)(v15 - 12) = v4[-1].m_motorInfos[2].m_velocity;
      *(float *)(v15 - 8) = v4[-1].m_motorInfos[2].m_tau;
      *(float *)(v15 - 4) = v4[-1].m_motorInfos[2].m_damping;
      --v16;
    }
    while ( v16 );
  }
  v18 = *(unsigned __int16 *)&v8[4];
  *(float *)&v8[20] = v9->m_maxTorqueHysterisys;
  *(_QWORD *)&v8[8] = v9->m_childConstraintStatusWriteBackBuffer;
  hkPoweredChain_BuildConstraintMatrixAndLuDecomposition(
    v9->m_numConstraints,
    &v9->m_cfm,
    v9->m_motorsState,
    (hkp1Lin2AngJacobian *)&out->m_jacobianSchemas.m_storage[32],
    (hkp2AngJacobian *)&out->m_jacobianSchemas.m_storage[144 * (_DWORD)v3 + 32],
    (hkpVelocityAccumulatorOffset *)&v8[1024 * v18 + 64 + 240 * (signed int)v18],
    v9->m_accumsBase,
    (hkpConstraintChainMatrix6Triple *)&v8[240 * (_DWORD)v18 + 32],
    960 * v3);
  v10->m_jacobianSchemas.m_storage += *(unsigned int *)&v8[16];
}

// File Line: 211
// RVA: 0x132AC30
void __fastcall hkPoweredChain_BuildConstraintMatrixAndLuDecomposition(int numConstraints, hkpCfmParam *cfm, hkp3dAngularMotorSolverInfo *motorsState, hkp1Lin2AngJacobian *j, hkp2AngJacobian *jAng, hkpVelocityAccumulatorOffset *va, hkpVelocityAccumulator *accumsBase, hkpConstraintChainMatrix6Triple *triples, int bufferSize)
{
  int v9; // eax
  hkVector4f v10; // xmm8
  hkp3dAngularMotorSolverInfo *v11; // rbp
  hkVector4f *v12; // r10
  __m128 *v13; // r13
  hkVector4f *v14; // rsi
  signed __int64 v15; // r14
  __m128 *v16; // rdi
  __int64 v17; // r15
  __int64 v18; // rbx
  signed __int64 v19; // rbp
  __m128 *v20; // r9
  signed __int64 v21; // r12
  __m128 v22; // xmm5
  __m128 v23; // xmm6
  __m128 v24; // xmm7
  signed __int64 v25; // rcx
  __m128 *v26; // rdx
  signed __int64 v27; // r8
  __m128 *v28; // rax
  signed __int64 v29; // r10
  __m128 v30; // xmm9
  __m128 v31; // xmm10
  __m128 v32; // xmm1
  __m128 v33; // xmm1
  __m128 v34; // xmm4
  __m128 v35; // xmm2
  __m128 v36; // xmm0
  __m128 v37; // xmm2
  __m128 v38; // xmm3
  hkpCfmParam *v39; // rax
  signed __int64 v40; // rcx
  signed __int64 v41; // rdx
  __m128 v42; // xmm9
  __m128 v43; // xmm12
  __m128 v44; // xmm10
  __m128 v45; // xmm13
  __m128 v46; // xmm11
  __m128 v47; // xmm14
  __m128 v48; // xmm4
  __m128 v49; // xmm1
  __m128 v50; // xmm3
  __m128 v51; // xmm0
  __m128 v52; // xmm4
  __m128 *v53; // rax
  __m128 v54; // xmm4
  __m128 v55; // xmm1
  __m128 v56; // xmm2
  __m128 v57; // xmm3
  __m128 v58; // xmm4
  __m128 v59; // xmm5
  __m128 v60; // xmm7
  __m128 v61; // xmm6
  __m128 v62; // xmm1
  __m128 v63; // xmm3
  int v64; // edi
  __m128 v65; // xmm2
  __m128 v66; // xmm1
  __m128 v67; // xmm14
  __m128 v68; // xmm7
  signed __int64 v69; // rcx
  __m128 *v70; // rax
  signed __int64 v71; // rdx
  __m128 v72; // xmm15
  __m128 v73; // xmm12
  __m128 v74; // xmm13
  __m128 v75; // xmm8
  __m128 v76; // xmm3
  __m128 v77; // xmm1
  __m128 v78; // xmm5
  __m128 v79; // xmm2
  __m128 v80; // xmm6
  __m128 v81; // xmm4
  __m128 v82; // xmm5
  __m128 *v83; // rax
  signed __int64 v84; // rcx
  signed __int64 v85; // r8
  __m128 *v86; // rdx
  __m128 v87; // xmm0
  __m128 v88; // xmm1
  __m128 v89; // xmm4
  __m128 v90; // xmm2
  __m128 v91; // xmm1
  __m128 v92; // xmm2
  __m128 v93; // xmm4
  signed __int64 v94; // rcx
  signed __int64 v95; // rdx
  __m128 v96; // xmm0
  __m128 v97; // xmm1
  __m128 v98; // xmm4
  __m128 v99; // xmm2
  __m128 v100; // xmm1
  __m128 v101; // xmm2
  __m128 v102; // xmm4
  signed __int64 v103; // rax
  __m128 *v104; // rcx
  signed __int64 v105; // rdx
  __m128 v106; // xmm0
  __m128 v107; // xmm1
  __m128 v108; // xmm4
  __m128 v109; // xmm2
  __m128 v110; // xmm1
  __m128 v111; // xmm2
  __m128 v112; // xmm4
  hkpConstraintChainMatrix6Triple *v113; // rsi
  int v114; // ebx
  __int64 v115; // rdi
  int v116; // [rsp+30h] [rbp-1C8h]
  int v117; // [rsp+34h] [rbp-1C4h]
  hkVector4f *v118; // [rsp+38h] [rbp-1C0h]
  hkVector4f *v119; // [rsp+40h] [rbp-1B8h]
  hkMatrix6f *triplePrevUpper; // [rsp+50h] [rbp-1A8h]
  hkMatrix6f mtxPrevOffdiag; // [rsp+60h] [rbp-198h]
  int v122; // [rsp+200h] [rbp+8h]
  hkpCfmParam *v123; // [rsp+208h] [rbp+10h]
  hkp3dAngularMotorSolverInfo *v124; // [rsp+210h] [rbp+18h]

  v124 = motorsState;
  v123 = cfm;
  v122 = numConstraints;
  v9 = numConstraints;
  v10.m_quad = 0i64;
  mtxPrevOffdiag.m_m[0][0].m_col0 = 0i64;
  mtxPrevOffdiag.m_m[0][0].m_col1 = 0i64;
  v11 = motorsState;
  v116 = 0;
  triplePrevUpper = &mtxPrevOffdiag;
  mtxPrevOffdiag.m_m[0][0].m_col2 = 0i64;
  mtxPrevOffdiag.m_m[0][1].m_col0 = 0i64;
  mtxPrevOffdiag.m_m[0][1].m_col1 = 0i64;
  mtxPrevOffdiag.m_m[0][1].m_col2 = 0i64;
  mtxPrevOffdiag.m_m[1][0].m_col0 = 0i64;
  mtxPrevOffdiag.m_m[1][0].m_col1 = 0i64;
  mtxPrevOffdiag.m_m[1][0].m_col2 = 0i64;
  mtxPrevOffdiag.m_m[1][1].m_col0 = 0i64;
  mtxPrevOffdiag.m_m[1][1].m_col1 = 0i64;
  mtxPrevOffdiag.m_m[1][1].m_col2 = 0i64;
  if ( numConstraints > 0 )
  {
    v12 = &jAng[1].m_angular[1];
    v13 = &j[1].m_angular[1].m_quad;
    v117 = numConstraints - 1;
    v118 = &jAng[1].m_angular[1];
    v119 = j[3].m_angular;
    v14 = &triples->m_mtxDiag.m_m[1][1].m_col2;
    do
    {
      v15 = (signed __int64)&v14[-11];
      v16 = &v12[-3].m_quad;
      v17 = va->m_offset;
      v18 = va[1].m_offset;
      v19 = 0i64;
      ++va;
      v20 = v13 - 4;
      v21 = 3i64;
      do
      {
        if ( v19 < 3 )
        {
          v22 = v20[-1];
          v23 = v20[1];
          v24 = *v20;
          v25 = v15 + 144;
          v26 = v16;
          v27 = v15;
          v28 = v20;
          v29 = 3 - v19;
          v30 = v16[1];
          v31 = *v16;
          do
          {
            v32 = v28[-1];
            v25 += 4i64;
            v28 += 3;
            v26 += 2;
            v27 += 16i64;
            v33 = _mm_mul_ps(v32, v22);
            v34 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_shuffle_ps(
                          *(__m128 *)((char *)&accumsBase->m_invMasses.m_quad + v17),
                          *(__m128 *)((char *)&accumsBase->m_invMasses.m_quad + v17),
                          255),
                        v33),
                      _mm_mul_ps(
                        _mm_shuffle_ps(
                          *(__m128 *)((char *)&accumsBase->m_invMasses.m_quad + v18),
                          *(__m128 *)((char *)&accumsBase->m_invMasses.m_quad + v18),
                          255),
                        v33)),
                    _mm_add_ps(
                      _mm_mul_ps(_mm_mul_ps(v28[-2], v23), *(__m128 *)((char *)&accumsBase->m_invMasses.m_quad + v18)),
                      _mm_mul_ps(_mm_mul_ps(v24, v28[-3]), *(__m128 *)((char *)&accumsBase->m_invMasses.m_quad + v17))));
            v35 = _mm_mul_ps(v26[-1], v30);
            v33.m128_f32[0] = (float)(COERCE_FLOAT(_mm_shuffle_ps(v34, v34, 85))
                                    + COERCE_FLOAT(_mm_shuffle_ps(v34, v34, 0)))
                            + COERCE_FLOAT(_mm_shuffle_ps(v34, v34, 170));
            v36 = _mm_mul_ps(v31, v26[-2]);
            *(_DWORD *)(v27 - 16) = v33.m128_i32[0];
            *(_DWORD *)(v25 - 148) = v33.m128_i32[0];
            v37 = _mm_add_ps(
                    _mm_mul_ps(v35, *(__m128 *)((char *)&accumsBase->m_invMasses.m_quad + v18)),
                    _mm_mul_ps(v36, *(__m128 *)((char *)&accumsBase->m_invMasses.m_quad + v17)));
            v33.m128_f32[0] = (float)(COERCE_FLOAT(_mm_shuffle_ps(v37, v37, 85))
                                    + COERCE_FLOAT(_mm_shuffle_ps(v37, v37, 0)))
                            + COERCE_FLOAT(_mm_shuffle_ps(v37, v37, 170));
            *(_DWORD *)(v27 + 128) = v33.m128_i32[0];
            *(_DWORD *)(v25 - 4) = v33.m128_i32[0];
            --v29;
          }
          while ( v29 );
        }
        ++v19;
        v16 += 2;
        v20 += 3;
        v15 += 20i64;
        --v21;
      }
      while ( v21 );
      v38 = v14[-11].m_quad;
      v39 = v123;
      v40 = (signed __int64)&v14[-5];
      v41 = 3i64;
      v42 = v118[2].m_quad;
      v43 = v118[1].m_quad;
      v44 = v118->m_quad;
      v45 = v118[-1].m_quad;
      v46 = v118[-2].m_quad;
      v47 = v118[-3].m_quad;
      v48 = _mm_add_ps(
              _mm_mul_ps(
                _mm_or_ps(
                  _mm_andnot_ps(
                    (__m128)xmmword_141C20FD0,
                    _mm_or_ps(
                      _mm_and_ps((__m128)xmmword_141C20FB0, v14[-10].m_quad),
                      _mm_andnot_ps((__m128)xmmword_141C20FB0, v38))),
                  _mm_and_ps((__m128)xmmword_141C20FD0, v14[-9].m_quad)),
                _mm_shuffle_ps((__m128)LODWORD(v123->m_linMul), (__m128)LODWORD(v123->m_linMul), 0)),
              _mm_shuffle_ps((__m128)LODWORD(v123->m_linAdd), (__m128)LODWORD(v123->m_linAdd), 0));
      v38.m128_f32[0] = v48.m128_f32[0];
      v14[-11] = (hkVector4f)v38;
      v49 = _mm_or_ps(
              _mm_and_ps((__m128)xmmword_141C20FD0, v48),
              _mm_andnot_ps((__m128)xmmword_141C20FD0, v14[-9].m_quad));
      v14[-10].m_quad = _mm_or_ps(
                          _mm_and_ps((__m128)xmmword_141C20FB0, v48),
                          _mm_andnot_ps((__m128)xmmword_141C20FB0, v14[-10].m_quad));
      v14[-9] = (hkVector4f)v49;
      v50 = v14[-2].m_quad;
      v51 = _mm_shuffle_ps((__m128)LODWORD(v39->m_angAdd), (__m128)LODWORD(v39->m_angAdd), 0);
      v52 = _mm_mul_ps(
              _mm_or_ps(
                _mm_andnot_ps(
                  (__m128)xmmword_141C20FD0,
                  _mm_or_ps(
                    _mm_andnot_ps((__m128)xmmword_141C20FB0, v50),
                    _mm_and_ps((__m128)xmmword_141C20FB0, v14[-1].m_quad))),
                _mm_and_ps(v14->m_quad, (__m128)xmmword_141C20FD0)),
              _mm_shuffle_ps((__m128)LODWORD(v39->m_angMul), (__m128)LODWORD(v39->m_angMul), 0));
      v53 = &v119[-9].m_quad;
      v54 = _mm_add_ps(v52, v51);
      v50.m128_f32[0] = v54.m128_f32[0];
      v14[-2] = (hkVector4f)v50;
      v55 = _mm_or_ps(_mm_and_ps((__m128)xmmword_141C20FD0, v54), _mm_andnot_ps((__m128)xmmword_141C20FD0, v14->m_quad));
      v14[-1].m_quad = _mm_or_ps(
                         _mm_and_ps((__m128)xmmword_141C20FB0, v54),
                         _mm_andnot_ps((__m128)xmmword_141C20FB0, v14[-1].m_quad));
      *v14 = (hkVector4f)v55;
      do
      {
        v56 = *v53;
        v57 = *(__m128 *)((char *)&accumsBase->m_invMasses.m_quad + v17);
        v58 = v53[1];
        v40 += 16i64;
        v53 += 3;
        v59 = *(__m128 *)((char *)&accumsBase->m_invMasses.m_quad + v18);
        v60 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v43, v56), v57), _mm_mul_ps(_mm_mul_ps(v42, v58), v59));
        v61 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v58, v44), v59), _mm_mul_ps(_mm_mul_ps(v45, v56), v57));
        v62 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v47, v56), v57), _mm_mul_ps(_mm_mul_ps(v46, v58), v59));
        *(__m128 *)(v40 - 16) = _mm_movelh_ps(
                                  _mm_unpacklo_ps(
                                    _mm_add_ps(
                                      _mm_add_ps(_mm_shuffle_ps(v62, v62, 85), _mm_shuffle_ps(v62, v62, 0)),
                                      _mm_shuffle_ps(v62, v62, 170)),
                                    _mm_add_ps(
                                      _mm_add_ps(_mm_shuffle_ps(v61, v61, 85), _mm_shuffle_ps(v61, v61, 0)),
                                      _mm_shuffle_ps(v61, v61, 170))),
                                  _mm_unpacklo_ps(
                                    _mm_add_ps(
                                      _mm_add_ps(_mm_shuffle_ps(v60, v60, 85), _mm_shuffle_ps(v60, v60, 0)),
                                      _mm_shuffle_ps(v60, v60, 170)),
                                    aabbOut.m_quad));
        --v41;
      }
      while ( v41 );
      v63 = v14[-3].m_quad;
      v64 = v116;
      v65 = _mm_unpacklo_ps(v14[-5].m_quad, v14[-4].m_quad);
      v14[-6].m_quad = _mm_shuffle_ps(_mm_unpackhi_ps(v14[-5].m_quad, v14[-4].m_quad), v63, 228);
      v66 = _mm_movelh_ps(v65, v63);
      v14[-8] = (hkVector4f)v66;
      v14[-7].m_quad = _mm_shuffle_ps(_mm_movehl_ps(v66, v65), v63, 212);
      if ( v116 >= v117 )
      {
        v14[1] = (hkVector4f)v10.m_quad;
        v14[2] = (hkVector4f)v10.m_quad;
        v14[3] = (hkVector4f)v10.m_quad;
        v14[4] = (hkVector4f)v10.m_quad;
        v14[5] = (hkVector4f)v10.m_quad;
        v14[6] = (hkVector4f)v10.m_quad;
        v14[7] = (hkVector4f)v10.m_quad;
        v14[8] = (hkVector4f)v10.m_quad;
        v14[9] = (hkVector4f)v10.m_quad;
        v14[10] = (hkVector4f)v10.m_quad;
        v14[11] = (hkVector4f)v10.m_quad;
        v14[12] = (hkVector4f)v10.m_quad;
      }
      else
      {
        v67 = v13[1];
        v68 = v13[3];
        v69 = (signed __int64)&v14[1];
        v70 = v13 + 4;
        v71 = 3i64;
        v72 = v13[-2];
        v73 = *v13;
        v74 = v13[-3];
        v75 = v13[-5];
        do
        {
          v76 = *(__m128 *)((char *)&accumsBase->m_invMasses.m_quad + v18);
          v77 = *v70;
          v78 = v70[1];
          v69 += 16i64;
          v70 += 3;
          v79 = _mm_shuffle_ps(v76, v76, 255);
          v80 = _mm_sub_ps(_mm_mul_ps(_mm_mul_ps(v78, v68), v76), _mm_mul_ps(_mm_mul_ps(v77, v67), v79));
          v81 = _mm_sub_ps(_mm_mul_ps(_mm_mul_ps(v78, v73), v76), _mm_mul_ps(_mm_mul_ps(v77, v72), v79));
          v82 = _mm_sub_ps(_mm_mul_ps(_mm_mul_ps(v78, v74), v76), _mm_mul_ps(_mm_mul_ps(v75, v77), v79));
          *(__m128 *)(v69 - 16) = _mm_movelh_ps(
                                    _mm_unpacklo_ps(
                                      _mm_add_ps(
                                        _mm_add_ps(_mm_shuffle_ps(v82, v82, 85), _mm_shuffle_ps(v82, v82, 0)),
                                        _mm_shuffle_ps(v82, v82, 170)),
                                      _mm_add_ps(
                                        _mm_add_ps(_mm_shuffle_ps(v81, v81, 85), _mm_shuffle_ps(v81, v81, 0)),
                                        _mm_shuffle_ps(v81, v81, 170))),
                                    _mm_unpacklo_ps(
                                      _mm_add_ps(
                                        _mm_add_ps(_mm_shuffle_ps(v80, v80, 85), _mm_shuffle_ps(v80, v80, 0)),
                                        _mm_shuffle_ps(v80, v80, 170)),
                                      aabbOut.m_quad));
          --v71;
        }
        while ( v71 );
        v83 = &v118[3].m_quad;
        v84 = (signed __int64)&v14[10];
        v85 = 3i64;
        v86 = &v118[3].m_quad;
        v10.m_quad = 0i64;
        do
        {
          v87 = *(__m128 *)((char *)&accumsBase->m_invMasses.m_quad + v18);
          v88 = *v86;
          v84 += 16i64;
          v86 += 2;
          v89 = v88;
          v90 = v88;
          v91 = _mm_mul_ps(_mm_mul_ps(v88, v46), v87);
          v92 = _mm_mul_ps(_mm_mul_ps(v90, v44), v87);
          v93 = _mm_mul_ps(_mm_mul_ps(v89, v42), v87);
          *(__m128 *)(v84 - 16) = _mm_movelh_ps(
                                    _mm_unpacklo_ps(
                                      _mm_add_ps(
                                        _mm_add_ps(_mm_shuffle_ps(v91, v91, 85), _mm_shuffle_ps(v91, v91, 0)),
                                        _mm_shuffle_ps(v91, v91, 170)),
                                      _mm_add_ps(
                                        _mm_add_ps(_mm_shuffle_ps(v92, v92, 85), _mm_shuffle_ps(v92, v92, 0)),
                                        _mm_shuffle_ps(v92, v92, 170))),
                                    _mm_unpacklo_ps(
                                      _mm_add_ps(
                                        _mm_add_ps(_mm_shuffle_ps(v93, v93, 85), _mm_shuffle_ps(v93, v93, 0)),
                                        _mm_shuffle_ps(v93, v93, 170)),
                                      aabbOut.m_quad));
          --v85;
        }
        while ( v85 );
        v94 = (signed __int64)&v14[4];
        v95 = 3i64;
        do
        {
          v96 = *(__m128 *)((char *)&accumsBase->m_invMasses.m_quad + v18);
          v97 = *v83;
          v94 += 16i64;
          v83 += 2;
          v98 = v97;
          v99 = v97;
          v100 = _mm_mul_ps(_mm_mul_ps(v97, v74), v96);
          v101 = _mm_mul_ps(_mm_mul_ps(v99, v73), v96);
          v102 = _mm_mul_ps(_mm_mul_ps(v98, v68), v96);
          *(__m128 *)(v94 - 16) = _mm_movelh_ps(
                                    _mm_unpacklo_ps(
                                      _mm_add_ps(
                                        _mm_add_ps(_mm_shuffle_ps(v100, v100, 85), _mm_shuffle_ps(v100, v100, 0)),
                                        _mm_shuffle_ps(v100, v100, 170)),
                                      _mm_add_ps(
                                        _mm_add_ps(_mm_shuffle_ps(v101, v101, 85), _mm_shuffle_ps(v101, v101, 0)),
                                        _mm_shuffle_ps(v101, v101, 170))),
                                    _mm_unpacklo_ps(
                                      _mm_add_ps(
                                        _mm_add_ps(_mm_shuffle_ps(v102, v102, 85), _mm_shuffle_ps(v102, v102, 0)),
                                        _mm_shuffle_ps(v102, v102, 170)),
                                      aabbOut.m_quad));
          --v95;
        }
        while ( v95 );
        v103 = (signed __int64)&v14[7];
        v104 = &v119->m_quad;
        v105 = 3i64;
        do
        {
          v106 = *(__m128 *)((char *)&accumsBase->m_invMasses.m_quad + v18);
          v107 = *v104;
          v103 += 16i64;
          v104 += 3;
          v108 = v107;
          v109 = v107;
          v110 = _mm_mul_ps(_mm_mul_ps(v107, v46), v106);
          v111 = _mm_mul_ps(_mm_mul_ps(v109, v44), v106);
          v112 = _mm_mul_ps(_mm_mul_ps(v108, v42), v106);
          *(__m128 *)(v103 - 16) = _mm_movelh_ps(
                                     _mm_unpacklo_ps(
                                       _mm_add_ps(
                                         _mm_add_ps(_mm_shuffle_ps(v110, v110, 85), _mm_shuffle_ps(v110, v110, 0)),
                                         _mm_shuffle_ps(v110, v110, 170)),
                                       _mm_add_ps(
                                         _mm_add_ps(_mm_shuffle_ps(v111, v111, 85), _mm_shuffle_ps(v111, v111, 0)),
                                         _mm_shuffle_ps(v111, v111, 170))),
                                     _mm_unpacklo_ps(
                                       _mm_add_ps(
                                         _mm_add_ps(_mm_shuffle_ps(v112, v112, 85), _mm_shuffle_ps(v112, v112, 0)),
                                         _mm_shuffle_ps(v112, v112, 170)),
                                       aabbOut.m_quad));
          --v105;
        }
        while ( v105 );
      }
      v9 = v122;
      v12 = v118 + 6;
      v13 += 9;
      v14 += 60;
      ++v116;
      v118 += 6;
      v119 += 9;
    }
    while ( v64 + 1 < v122 );
    v11 = v124;
  }
  if ( v9 > 0 )
  {
    v113 = triples;
    v114 = v9 - 1;
    v115 = (unsigned int)v9;
    do
    {
      hkPoweredChain_ComputeConstraintMatrixLuDecomposition_ForOneRow(
        (hkBool)(v114-- != 0),
        v113,
        v11,
        &mtxPrevOffdiag,
        &triplePrevUpper);
      ++v11;
      ++v113;
      --v115;
    }
    while ( v115 );
  }
}

// File Line: 246
// RVA: 0x132B550
void __fastcall hkPoweredChain_UpdateLuDecomposition(int firstConstraintToProcess, int numConstraints, hkp3dAngularMotorSolverInfo *motorsState, hkpConstraintChainMatrix6Triple *triples)
{
  int v4; // er10
  __int64 v5; // rcx
  hkMatrix6f *v6; // rax
  hkVector4f v7; // xmm0
  hkVector4f v8; // xmm1
  hkVector4f v9; // xmm0
  hkVector4f v10; // xmm1
  hkVector4f v11; // xmm0
  hkVector4f v12; // xmm1
  hkVector4f v13; // xmm0
  hkVector4f v14; // xmm1
  hkVector4f v15; // xmm0
  hkVector4f v16; // xmm1
  hkVector4f v17; // xmm0
  hkp3dAngularMotorSolverInfo *v18; // rbx
  hkpConstraintChainMatrix6Triple *v19; // rdi
  unsigned int v20; // edx
  int v21; // esi
  __int64 v22; // r14
  hkMatrix6f *triplePrevUpper; // [rsp+30h] [rbp-79h]
  hkMatrix6f mtxPrevOffdiag; // [rsp+40h] [rbp-69h]

  v4 = firstConstraintToProcess - 1;
  if ( firstConstraintToProcess - 1 < 0 )
    v4 = 0;
  if ( v4 )
  {
    v5 = v4 - 1;
    v6 = &triples[v5].m_upper;
    v7.m_quad = (__m128)triples[v5].m_mtxNextOffdiag.m_m[0][0].m_col0;
    mtxPrevOffdiag.m_m[0][0].m_col1 = triples[v5].m_mtxNextOffdiag.m_m[0][0].m_col1;
    v8.m_quad = (__m128)triples[v5].m_mtxNextOffdiag.m_m[0][1].m_col0;
    mtxPrevOffdiag.m_m[0][0].m_col0 = (hkVector4f)v7.m_quad;
    v9.m_quad = (__m128)triples[v5].m_mtxNextOffdiag.m_m[0][0].m_col2;
    mtxPrevOffdiag.m_m[0][1].m_col0 = (hkVector4f)v8.m_quad;
    v10.m_quad = (__m128)triples[v5].m_mtxNextOffdiag.m_m[0][1].m_col2;
    mtxPrevOffdiag.m_m[0][0].m_col2 = (hkVector4f)v9.m_quad;
    v11.m_quad = (__m128)triples[v5].m_mtxNextOffdiag.m_m[0][1].m_col1;
    mtxPrevOffdiag.m_m[0][1].m_col2 = (hkVector4f)v10.m_quad;
    v12.m_quad = (__m128)triples[v5].m_mtxNextOffdiag.m_m[1][0].m_col1;
    mtxPrevOffdiag.m_m[0][1].m_col1 = (hkVector4f)v11.m_quad;
    v13.m_quad = (__m128)triples[v5].m_mtxNextOffdiag.m_m[1][0].m_col0;
    mtxPrevOffdiag.m_m[1][0].m_col1 = (hkVector4f)v12.m_quad;
    v14.m_quad = (__m128)triples[v5].m_mtxNextOffdiag.m_m[1][1].m_col0;
    mtxPrevOffdiag.m_m[1][0].m_col0 = (hkVector4f)v13.m_quad;
    v15.m_quad = (__m128)triples[v5].m_mtxNextOffdiag.m_m[1][0].m_col2;
    mtxPrevOffdiag.m_m[1][1].m_col0 = (hkVector4f)v14.m_quad;
    v16.m_quad = (__m128)triples[v5].m_mtxNextOffdiag.m_m[1][1].m_col2;
    mtxPrevOffdiag.m_m[1][0].m_col2 = (hkVector4f)v15.m_quad;
    v17.m_quad = (__m128)triples[v5].m_mtxNextOffdiag.m_m[1][1].m_col1;
    mtxPrevOffdiag.m_m[1][1].m_col2 = (hkVector4f)v16.m_quad;
  }
  else
  {
    v17.m_quad = 0i64;
    v6 = &mtxPrevOffdiag;
    mtxPrevOffdiag.m_m[0][0].m_col0 = 0i64;
    mtxPrevOffdiag.m_m[0][0].m_col1 = 0i64;
    mtxPrevOffdiag.m_m[0][0].m_col2 = 0i64;
    mtxPrevOffdiag.m_m[0][1].m_col0 = 0i64;
    mtxPrevOffdiag.m_m[0][1].m_col1 = 0i64;
    mtxPrevOffdiag.m_m[0][1].m_col2 = 0i64;
    mtxPrevOffdiag.m_m[1][0].m_col0 = 0i64;
    mtxPrevOffdiag.m_m[1][0].m_col1 = 0i64;
    mtxPrevOffdiag.m_m[1][0].m_col2 = 0i64;
    mtxPrevOffdiag.m_m[1][1].m_col0 = 0i64;
    mtxPrevOffdiag.m_m[1][1].m_col2 = 0i64;
  }
  triplePrevUpper = v6;
  mtxPrevOffdiag.m_m[1][1].m_col1 = (hkVector4f)v17.m_quad;
  if ( v4 < numConstraints )
  {
    v18 = &motorsState[(signed __int64)v4];
    v19 = &triples[v4];
    v20 = numConstraints - v4;
    v21 = v20 - 1;
    v22 = v20;
    do
    {
      hkPoweredChain_ComputeConstraintMatrixLuDecomposition_ForOneRow(
        (hkBool)(v21-- != 0),
        v19,
        v18,
        &mtxPrevOffdiag,
        &triplePrevUpper);
      ++v18;
      ++v19;
      --v22;
    }
    while ( v22 );
  }
}

// File Line: 281
// RVA: 0x132B710
void __fastcall hkPoweredChain_ComputeConstraintMatrixLuDecomposition_ForOneRow(hkBool isNotLastRow, hkpConstraintChainMatrix6Triple *triple, hkp3dAngularMotorSolverInfo *motorsState, hkMatrix6f *mtxPrevOffdiag, hkMatrix6f **triplePrevUpper)
{
  hkpConstraintChainMatrix6Triple *v5; // r15
  hkMatrix6f *v6; // rdx
  char v7; // bl
  __int128 *v8; // rcx
  hkMatrix6f *v9; // r12
  hkp3dAngularMotorSolverInfo *v10; // rsi
  signed __int64 v11; // rdi
  signed __int64 v12; // rax
  __int128 v13; // xmm0
  __int128 v14; // xmm1
  __int128 v15; // xmm0
  __int128 v16; // xmm1
  __int128 v17; // xmm0
  __int128 v18; // xmm1
  __int128 v19; // xmm0
  __int128 v20; // xmm1
  __int128 v21; // xmm1
  __int128 v22; // xmm0
  __int128 v23; // xmm1
  hkMatrix6f *v24; // rcx
  hkMatrix6f *v25; // rdx
  hkVector4f v26; // xmm0
  hkVector4f v27; // xmm1
  hkVector4f v28; // xmm0
  hkVector4f v29; // xmm1
  hkVector4f v30; // xmm0
  hkVector4f v31; // xmm1
  hkVector4f v32; // xmm0
  hkVector4f v33; // xmm1
  hkVector4f v34; // xmm1
  hkVector4f v35; // xmm0
  hkVector4f v36; // xmm1
  hkMatrix6f *v37; // rdi
  __int128 v38; // xmm1
  __int128 v39; // xmm0
  __int128 v40; // xmm1
  __int128 v41; // xmm0
  __int128 v42; // xmm1
  __int128 v43; // xmm0
  __int128 v44; // xmm1
  __int128 v45; // xmm0
  __int128 v46; // xmm1
  __int128 v47; // xmm0
  __int128 v48; // xmm1
  hkVector4f v49; // xmm2
  __m128 v50; // xmm3
  __m128 v51; // xmm1
  __m128 v52; // xmm2
  __m128 v53; // xmm3
  __m128 v54; // xmm1
  hkVector4f v55; // xmm1
  hkVector4f v56; // xmm0
  hkVector4f v57; // xmm1
  hkVector4f v58; // xmm0
  hkVector4f v59; // xmm1
  hkVector4f v60; // xmm0
  hkVector4f v61; // xmm1
  hkVector4f v62; // xmm0
  hkVector4f v63; // xmm1
  hkVector4f v64; // xmm0
  hkVector4f v65; // xmm1
  hkVector4f Dst; // [rsp+20h] [rbp-E0h]
  __int128 v67; // [rsp+30h] [rbp-D0h]
  __int128 v68; // [rsp+40h] [rbp-C0h]
  __int128 v69; // [rsp+50h] [rbp-B0h]
  __int128 v70; // [rsp+60h] [rbp-A0h]
  __int128 v71; // [rsp+70h] [rbp-90h]
  __int128 v72; // [rsp+80h] [rbp-80h]
  __int128 v73; // [rsp+90h] [rbp-70h]
  __int128 v74; // [rsp+A0h] [rbp-60h]
  __int128 v75; // [rsp+B0h] [rbp-50h]
  __int128 v76; // [rsp+C0h] [rbp-40h]
  __int128 v77; // [rsp+D0h] [rbp-30h]
  hkMatrix6f in; // [rsp+E0h] [rbp-20h]
  hkMatrix6f mtxNextOffdiag; // [rsp+1A0h] [rbp+A0h]
  hkMatrix6f out; // [rsp+260h] [rbp+160h]

  v5 = triple;
  v6 = &triple->m_mtxDiag;
  v7 = isNotLastRow.m_bool;
  v8 = (__int128 *)&Dst;
  v9 = mtxPrevOffdiag;
  v10 = motorsState;
  v11 = 1i64;
  if ( ((unsigned __int8)&Dst | (unsigned __int8)v6) & 0xF )
  {
    memmove(&Dst, v6, 0xC0ui64);
  }
  else
  {
    v12 = 1i64;
    do
    {
      v13 = (__int128)v6->m_m[0][0].m_col0;
      v14 = (__int128)v6->m_m[0][0].m_col1;
      v8 += 8;
      v6 = (hkMatrix6f *)((char *)v6 + 128);
      *(v8 - 8) = v13;
      v15 = (__int128)v6[-1].m_m[1][0].m_col0;
      *(v8 - 7) = v14;
      v16 = (__int128)v6[-1].m_m[1][0].m_col1;
      *(v8 - 6) = v15;
      v17 = (__int128)v6[-1].m_m[1][0].m_col2;
      *(v8 - 5) = v16;
      v18 = (__int128)v6[-1].m_m[1][1].m_col0;
      *(v8 - 4) = v17;
      v19 = (__int128)v6[-1].m_m[1][1].m_col1;
      *(v8 - 3) = v18;
      v20 = (__int128)v6[-1].m_m[1][1].m_col2;
      *(v8 - 2) = v19;
      *(v8 - 1) = v20;
      --v12;
    }
    while ( v12 );
    v21 = (__int128)v6->m_m[0][0].m_col1;
    *v8 = (__int128)v6->m_m[0][0].m_col0;
    v22 = (__int128)v6->m_m[0][0].m_col2;
    v8[1] = v21;
    v23 = (__int128)v6->m_m[0][1].m_col0;
    v8[2] = v22;
    v8[3] = v23;
  }
  v24 = &mtxNextOffdiag;
  v25 = &v5->m_mtxNextOffdiag;
  if ( ((unsigned __int8)&mtxNextOffdiag | (unsigned __int8)v5) & 0xF )
  {
    memmove(&mtxNextOffdiag, v25, 0xC0ui64);
  }
  else
  {
    do
    {
      v26.m_quad = (__m128)v25->m_m[0][0].m_col0;
      v27.m_quad = (__m128)v25->m_m[0][0].m_col1;
      v24 = (hkMatrix6f *)((char *)v24 + 128);
      v25 = (hkMatrix6f *)((char *)v25 + 128);
      v24[-1].m_m[0][1].m_col1 = (hkVector4f)v26.m_quad;
      v28.m_quad = (__m128)v25[-1].m_m[1][0].m_col0;
      v24[-1].m_m[0][1].m_col2 = (hkVector4f)v27.m_quad;
      v29.m_quad = (__m128)v25[-1].m_m[1][0].m_col1;
      v24[-1].m_m[1][0].m_col0 = (hkVector4f)v28.m_quad;
      v30.m_quad = (__m128)v25[-1].m_m[1][0].m_col2;
      v24[-1].m_m[1][0].m_col1 = (hkVector4f)v29.m_quad;
      v31.m_quad = (__m128)v25[-1].m_m[1][1].m_col0;
      v24[-1].m_m[1][0].m_col2 = (hkVector4f)v30.m_quad;
      v32.m_quad = (__m128)v25[-1].m_m[1][1].m_col1;
      v24[-1].m_m[1][1].m_col0 = (hkVector4f)v31.m_quad;
      v33.m_quad = (__m128)v25[-1].m_m[1][1].m_col2;
      v24[-1].m_m[1][1].m_col1 = (hkVector4f)v32.m_quad;
      v24[-1].m_m[1][1].m_col2 = (hkVector4f)v33.m_quad;
      --v11;
    }
    while ( v11 );
    v34.m_quad = (__m128)v25->m_m[0][0].m_col1;
    v24->m_m[0][0].m_col0 = v25->m_m[0][0].m_col0;
    v35.m_quad = (__m128)v25->m_m[0][0].m_col2;
    v24->m_m[0][0].m_col1 = (hkVector4f)v34.m_quad;
    v36.m_quad = (__m128)v25->m_m[0][1].m_col0;
    v24->m_m[0][0].m_col2 = (hkVector4f)v35.m_quad;
    v24->m_m[0][1].m_col0 = (hkVector4f)v36.m_quad;
  }
  hkPoweredChain_DisableMotorInMatrixRow_ThisConstraint(v10, (hkBool)v7, (hkMatrix6f *)&Dst, &mtxNextOffdiag);
  hkPoweredChain_DisableMotorInMatrixRow_NextConstraint(v10, v9);
  hkMatrix6fSetTranspose(&v5->m_lower, v9);
  hkMatrix6fSetMul(&out, &v5->m_lower, *triplePrevUpper);
  v37 = &v5->m_diagonalInv;
  v38 = v67;
  v37->m_m[0][0].m_col0 = (hkVector4f)Dst.m_quad;
  v39 = v68;
  v37->m_m[0][0].m_col1 = (hkVector4f)v38;
  v40 = v69;
  v37->m_m[0][0].m_col2 = (hkVector4f)v39;
  v41 = v70;
  v37->m_m[0][1].m_col0 = (hkVector4f)v40;
  v42 = v71;
  v37->m_m[0][1].m_col1 = (hkVector4f)v41;
  v43 = v72;
  v37->m_m[0][1].m_col2 = (hkVector4f)v42;
  v44 = v73;
  v37->m_m[1][0].m_col0 = (hkVector4f)v43;
  v45 = v74;
  v37->m_m[1][0].m_col1 = (hkVector4f)v44;
  v46 = v75;
  v37->m_m[1][0].m_col2 = (hkVector4f)v45;
  v47 = v76;
  v37->m_m[1][1].m_col0 = (hkVector4f)v46;
  v48 = v77;
  v37->m_m[1][1].m_col1 = (hkVector4f)v47;
  v37->m_m[1][1].m_col2 = (hkVector4f)v48;
  hkMatrix6fSub(&v5->m_diagonalInv, &out);
  v49.m_quad = (__m128)v5->m_diagonalInv.m_m[0][0].m_col0;
  v50 = _mm_max_ps(
          _mm_or_ps(
            _mm_andnot_ps(
              (__m128)xmmword_141C20FD0,
              _mm_or_ps(
                _mm_and_ps(v5->m_diagonalInv.m_m[0][0].m_col1.m_quad, (__m128)xmmword_141C20FB0),
                _mm_andnot_ps((__m128)xmmword_141C20FB0, v5->m_diagonalInv.m_m[0][0].m_col0.m_quad))),
            _mm_and_ps((__m128)xmmword_141C20FD0, v5->m_diagonalInv.m_m[0][0].m_col2.m_quad)),
          *(__m128 *)&epsilon);
  v49.m_quad.m128_f32[0] = v50.m128_f32[0];
  v37->m_m[0][0].m_col0 = (hkVector4f)v49.m_quad;
  v51 = _mm_or_ps(
          _mm_and_ps((__m128)xmmword_141C20FD0, v50),
          _mm_andnot_ps((__m128)xmmword_141C20FD0, v5->m_diagonalInv.m_m[0][0].m_col2.m_quad));
  v5->m_diagonalInv.m_m[0][0].m_col1.m_quad = _mm_or_ps(
                                                _mm_and_ps((__m128)xmmword_141C20FB0, v50),
                                                _mm_andnot_ps(
                                                  (__m128)xmmword_141C20FB0,
                                                  v5->m_diagonalInv.m_m[0][0].m_col1.m_quad));
  v5->m_diagonalInv.m_m[0][0].m_col2.m_quad = v51;
  v52 = v5->m_diagonalInv.m_m[1][1].m_col0.m_quad;
  v53 = _mm_max_ps(
          _mm_or_ps(
            _mm_andnot_ps(
              (__m128)xmmword_141C20FD0,
              _mm_or_ps(
                _mm_and_ps(v5->m_diagonalInv.m_m[1][1].m_col1.m_quad, (__m128)xmmword_141C20FB0),
                _mm_andnot_ps((__m128)xmmword_141C20FB0, v52))),
            _mm_and_ps((__m128)xmmword_141C20FD0, v5->m_diagonalInv.m_m[1][1].m_col2.m_quad)),
          *(__m128 *)&epsilon);
  v52.m128_f32[0] = v53.m128_f32[0];
  v5->m_diagonalInv.m_m[1][1].m_col0.m_quad = v52;
  v54 = _mm_or_ps(
          _mm_andnot_ps((__m128)xmmword_141C20FD0, v5->m_diagonalInv.m_m[1][1].m_col2.m_quad),
          _mm_and_ps((__m128)xmmword_141C20FD0, v53));
  v5->m_diagonalInv.m_m[1][1].m_col1.m_quad = _mm_or_ps(
                                                _mm_andnot_ps(
                                                  (__m128)xmmword_141C20FB0,
                                                  v5->m_diagonalInv.m_m[1][1].m_col1.m_quad),
                                                _mm_and_ps((__m128)xmmword_141C20FB0, v53));
  v5->m_diagonalInv.m_m[1][1].m_col2.m_quad = v54;
  v55.m_quad = (__m128)v5->m_diagonalInv.m_m[0][0].m_col1;
  in.m_m[0][0].m_col0 = v5->m_diagonalInv.m_m[0][0].m_col0;
  v56.m_quad = (__m128)v5->m_diagonalInv.m_m[0][0].m_col2;
  in.m_m[0][0].m_col1 = (hkVector4f)v55.m_quad;
  v57.m_quad = (__m128)v5->m_diagonalInv.m_m[0][1].m_col0;
  in.m_m[0][0].m_col2 = (hkVector4f)v56.m_quad;
  v58.m_quad = (__m128)v5->m_diagonalInv.m_m[0][1].m_col1;
  in.m_m[0][1].m_col0 = (hkVector4f)v57.m_quad;
  v59.m_quad = (__m128)v5->m_diagonalInv.m_m[0][1].m_col2;
  in.m_m[0][1].m_col1 = (hkVector4f)v58.m_quad;
  v60.m_quad = (__m128)v5->m_diagonalInv.m_m[1][0].m_col0;
  in.m_m[0][1].m_col2 = (hkVector4f)v59.m_quad;
  v61.m_quad = (__m128)v5->m_diagonalInv.m_m[1][0].m_col1;
  in.m_m[1][0].m_col0 = (hkVector4f)v60.m_quad;
  v62.m_quad = (__m128)v5->m_diagonalInv.m_m[1][0].m_col2;
  in.m_m[1][0].m_col1 = (hkVector4f)v61.m_quad;
  v63.m_quad = (__m128)v5->m_diagonalInv.m_m[1][1].m_col0;
  in.m_m[1][0].m_col2 = (hkVector4f)v62.m_quad;
  v64.m_quad = (__m128)v5->m_diagonalInv.m_m[1][1].m_col1;
  in.m_m[1][1].m_col0 = (hkVector4f)v63.m_quad;
  v65.m_quad = (__m128)v5->m_diagonalInv.m_m[1][1].m_col2;
  in.m_m[1][1].m_col1 = (hkVector4f)v64.m_quad;
  in.m_m[1][1].m_col2 = (hkVector4f)v65.m_quad;
  hkMatrix6fSetInvert(&v5->m_diagonalInv, &in);
  hkMatrix6fSetMul(&v5->m_upper, &v5->m_diagonalInv, &mtxNextOffdiag);
  v9->m_m[0][0].m_col0 = v5->m_mtxNextOffdiag.m_m[0][0].m_col0;
  v9->m_m[0][0].m_col1 = v5->m_mtxNextOffdiag.m_m[0][0].m_col1;
  v9->m_m[0][0].m_col2 = v5->m_mtxNextOffdiag.m_m[0][0].m_col2;
  v9->m_m[0][1].m_col0 = v5->m_mtxNextOffdiag.m_m[0][1].m_col0;
  v9->m_m[0][1].m_col1 = v5->m_mtxNextOffdiag.m_m[0][1].m_col1;
  v9->m_m[0][1].m_col2 = v5->m_mtxNextOffdiag.m_m[0][1].m_col2;
  v9->m_m[1][0].m_col0 = v5->m_mtxNextOffdiag.m_m[1][0].m_col0;
  v9->m_m[1][0].m_col1 = v5->m_mtxNextOffdiag.m_m[1][0].m_col1;
  v9->m_m[1][0].m_col2 = v5->m_mtxNextOffdiag.m_m[1][0].m_col2;
  v9->m_m[1][1].m_col0 = v5->m_mtxNextOffdiag.m_m[1][1].m_col0;
  v9->m_m[1][1].m_col1 = v5->m_mtxNextOffdiag.m_m[1][1].m_col1;
  v9->m_m[1][1].m_col2 = v5->m_mtxNextOffdiag.m_m[1][1].m_col2;
  *triplePrevUpper = &v5->m_upper;
}

// File Line: 334
// RVA: 0x132BBB0
void __fastcall hkPoweredChain_DisableMotorInMatrixRow_ThisConstraint(hkp3dAngularMotorSolverInfo *motorsState, hkBool isNotLastRow, hkMatrix6f *mtxDiag, hkMatrix6f *mtxNextOffdiag)
{
  unsigned __int8 v4; // r10
  hkMatrix6f *v5; // r11
  hkVector4f v6; // xmm3
  hkVector4f v7; // xmm4
  hkVector4f v8; // xmm5
  __m128 v9; // xmm2
  __m128 v10; // xmm1
  __m128 v11; // xmm0
  hkVector4f v12; // xmm3
  hkVector4f v13; // xmm0
  signed int v14; // er9
  __int64 v15; // rax
  __m128 v16; // xmm2
  __int128 v17; // xmm0
  __m128 v18; // xmm2
  __m128 v19; // xmm5
  __m128 v20; // xmm3
  __m128 v21; // xmm1
  __m128 v22; // xmm0
  __m128 v23; // xmm2
  __m128 v24; // xmm3
  __m128 v25; // xmm1
  __m128 v26; // [rsp+0h] [rbp-68h]
  __m128 v27; // [rsp+10h] [rbp-58h]
  __m128 v28; // [rsp+20h] [rbp-48h]
  __m128 v29; // [rsp+30h] [rbp-38h]
  __m128 v30; // [rsp+40h] [rbp-28h]
  __m128 v31; // [rsp+50h] [rbp-18h]

  v4 = motorsState->m_broken;
  v5 = mtxNextOffdiag;
  if ( motorsState->m_broken )
  {
    v6.m_quad = (__m128)mtxNextOffdiag->m_m[1][0].m_col2;
    v7.m_quad = (__m128)mtxNextOffdiag->m_m[1][0].m_col0;
    v8.m_quad = (__m128)mtxNextOffdiag->m_m[1][1].m_col0;
    v9 = _mm_unpacklo_ps(v7.m_quad, mtxNextOffdiag->m_m[1][0].m_col1.m_quad);
    v31 = _mm_shuffle_ps(_mm_unpackhi_ps(v7.m_quad, mtxNextOffdiag->m_m[1][0].m_col1.m_quad), v6.m_quad, 228);
    v10 = _mm_movelh_ps(v9, v6.m_quad);
    v11 = _mm_shuffle_ps(_mm_movehl_ps(v10, v9), v6.m_quad, 212);
    v12.m_quad = (__m128)mtxNextOffdiag->m_m[1][1].m_col2;
    v30 = v11;
    v13.m_quad = (__m128)mtxNextOffdiag->m_m[1][1].m_col1;
    v14 = 0;
    v15 = 0i64;
    v16 = _mm_unpacklo_ps(v8.m_quad, v13.m_quad);
    v29 = v10;
    v26 = _mm_movelh_ps(v16, v12.m_quad);
    v27 = _mm_shuffle_ps(_mm_movehl_ps(v26, v16), v12.m_quad, 212);
    v28 = _mm_shuffle_ps(_mm_unpackhi_ps(v8.m_quad, v13.m_quad), v12.m_quad, 228);
    do
    {
      if ( (v4 >> v14) & 3 )
      {
        v17 = 0i64;
        *(__m128 *)((char *)&v29 + v15) = 0i64;
        if ( !isNotLastRow.m_bool )
          v17 = *(__int128 *)((char *)&transform + v15);
        *(__m128 *)((char *)&v26 + v15) = (__m128)v17;
      }
      v14 += 2;
      v15 += 16i64;
    }
    while ( v14 < 6 );
    v18 = v31;
    v19 = v26;
    v20 = _mm_unpacklo_ps(v29, v30);
    v5->m_m[1][0].m_col2.m_quad = _mm_shuffle_ps(_mm_unpackhi_ps(v29, v30), v31, 228);
    v21 = _mm_movelh_ps(v20, v18);
    v5->m_m[1][0].m_col0.m_quad = v21;
    v22 = _mm_shuffle_ps(_mm_movehl_ps(v21, v20), v18, 212);
    v23 = v28;
    v5->m_m[1][0].m_col1.m_quad = v22;
    v24 = _mm_unpacklo_ps(v19, v27);
    v25 = _mm_movelh_ps(v24, v23);
    v5->m_m[1][1].m_col2.m_quad = _mm_shuffle_ps(_mm_unpackhi_ps(v19, v27), v23, 228);
    v5->m_m[1][1].m_col0.m_quad = v25;
    v5->m_m[1][1].m_col1.m_quad = _mm_shuffle_ps(_mm_movehl_ps(v25, v24), v23, 212);
  }
}

// File Line: 366
// RVA: 0x132BD30
void __fastcall hkPoweredChain_DisableMotorInMatrixRow_NextConstraint(hkp3dAngularMotorSolverInfo *motorsState, hkMatrix6f *mtxNextOffdiag)
{
  signed int v2; // eax
  _OWORD *v3; // r8

  if ( motorsState->m_broken )
  {
    v2 = 0;
    v3 = (_OWORD *)mtxNextOffdiag->m_m[1][1].m_col0.m_quad.m128_f32;
    do
    {
      if ( ((unsigned __int8)motorsState->m_broken >> v2) & 3 )
      {
        *(v3 - 6) = 0i64;
        *v3 = 0i64;
      }
      v2 += 2;
      ++v3;
    }
    while ( v2 < 6 );
  }
}

// File Line: 407
// RVA: 0x132BD70
void __fastcall hkPoweredChain_CalculateVelocities(hkSolverStepTemp *temp, hkpChainSolverInfo *info, hkVector8f *velocities)
{
  hkp1Lin2AngJacobian *v3; // rdi
  int v4; // er11
  hkVector8f *v5; // r9
  hkpChainSolverInfo *v6; // r10
  hkSolverStepTemp *v7; // rbp
  hkVector4f *v8; // rsi
  __int64 v9; // rbx
  hkpVelocityAccumulatorOffset *v10; // rax
  __m128 *v11; // rdx
  __m128 *v12; // r8
  signed __int64 v13; // rcx
  __m128 v14; // xmm11
  __m128 v15; // xmm12
  __m128 v16; // xmm13
  __m128 v17; // xmm9
  __m128 v18; // xmm0
  __m128 v19; // xmm8
  __m128 v20; // xmm11
  hkVector8f *v21; // rdx
  __m128 v22; // xmm10
  signed __int64 v23; // r8
  __m128 v24; // xmm8
  __m128 v25; // xmm9
  __m128 v26; // xmm10
  __m128 v27; // xmm7
  __m128 v28; // xmm5
  hkSimdFloat32 v29; // t1
  __m128 v30; // xmm5
  __m128 v31; // xmm4
  __m128 v32; // xmm5
  __m128 v33; // xmm6
  __m128i v34; // xmm0

  v3 = info->m_j.m_storage;
  v4 = 0;
  v5 = velocities;
  v6 = info;
  v7 = temp;
  if ( info->m_numConstraints.m_storage > 0 )
  {
    v8 = &info->m_jAng.m_storage->m_angular[1];
    v9 = 0i64;
    do
    {
      v10 = v6->m_va.m_storage;
      ++v9;
      v11 = (__m128 *)(&v6->m_accumsBase.m_storage->m_type.m_storage + v10[v9].m_offset);
      v12 = (__m128 *)(&v6->m_accumsBase.m_storage->m_type.m_storage + v10[v9 - 1].m_offset);
      v13 = (signed __int64)&v6->m_motorsState.m_storage[(signed __int64)v4].m_motorInfos[0].m_damping;
      v14 = v12[4];
      v15 = v12[5];
      v16 = v11[5];
      v17 = v11[2];
      v18 = _mm_sub_ps(v11[1], v11[4]);
      v19 = _mm_sub_ps(v12[1], v14);
      v20 = _mm_sub_ps(v14, v11[4]);
      v21 = v5;
      v22 = v12[2];
      v23 = 3i64;
      v24 = _mm_sub_ps(v19, v18);
      v25 = _mm_sub_ps(v17, v16);
      v26 = _mm_sub_ps(v22, v15);
      do
      {
        v27 = v3->m_linear0.m_quad;
        v28 = v3->m_angular[1].m_quad;
        v21 = (hkVector8f *)((char *)v21 + 4);
        v13 += 20i64;
        ++v3;
        v8 += 2;
        v29.m_real = (__m128)v6->m_schemaTau;
        v30 = _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_mul_ps(v28, v16), _mm_mul_ps(v15, v3[-1].m_angular[0].m_quad)),
                    _mm_mul_ps(v20, v27)),
                  _mm_mul_ps(
                    _mm_shuffle_ps(
                      v6->m_solverInfo->m_invIntegrateVelocityFactor.m_quad,
                      v6->m_solverInfo->m_invIntegrateVelocityFactor.m_quad,
                      0),
                    v6->m_schemaTau.m_real)),
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_mul_ps(v25, v3[-1].m_angular[1].m_quad), _mm_mul_ps(v26, v3[-1].m_angular[0].m_quad)),
                    _mm_mul_ps(v24, v27)),
                  v6->m_schemaDamping.m_real));
        v21[-1].m_ang.m_quad.m128_f32[3] = (float)(COERCE_FLOAT(_mm_shuffle_ps(v27, v27, 255)) * v29.m_real.m128_f32[0])
                                         - (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v30, v30, 85))
                                                         + COERCE_FLOAT(_mm_shuffle_ps(v30, v30, 0)))
                                                 + COERCE_FLOAT(_mm_shuffle_ps(v30, v30, 170)));
        v31 = v8[-2].m_quad;
        v32 = _mm_shuffle_ps((__m128)*(unsigned int *)(v13 - 24), (__m128)*(unsigned int *)(v13 - 24), 0);
        v33 = _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(_mm_mul_ps(v8[-3].m_quad, v15), _mm_mul_ps(v8[-2].m_quad, v16)),
                  _mm_mul_ps(
                    _mm_shuffle_ps(
                      v6->m_solverInfo->m_invIntegrateVelocityFactor.m_quad,
                      v6->m_solverInfo->m_invIntegrateVelocityFactor.m_quad,
                      0),
                    v32)),
                _mm_mul_ps(
                  _mm_add_ps(_mm_mul_ps(v26, v8[-3].m_quad), _mm_mul_ps(v25, v31)),
                  _mm_shuffle_ps((__m128)*(unsigned int *)(v13 - 20), (__m128)*(unsigned int *)(v13 - 20), 0)));
        v21->m_lin.m_quad.m128_f32[3] = (float)((float)((float)(COERCE_FLOAT(
                                                                  _mm_shuffle_ps(
                                                                    (__m128)*(unsigned int *)(v13 - 28),
                                                                    (__m128)*(unsigned int *)(v13 - 28),
                                                                    0))
                                                              * v7->m_intregratePositionFactor.m_real.m128_f32[0])
                                                      + COERCE_FLOAT(_mm_shuffle_ps(v31, v31, 255)))
                                              * v32.m128_f32[0])
                                      - (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v33, v33, 85))
                                                      + COERCE_FLOAT(_mm_shuffle_ps(v33, v33, 0)))
                                              + COERCE_FLOAT(_mm_shuffle_ps(v33, v33, 170)));
        --v23;
      }
      while ( v23 );
      v34 = _mm_load_si128((const __m128i *)v5);
      ++v4;
      ++v5;
      _mm_store_si128((__m128i *)&v5[-1], _mm_srli_si128(_mm_slli_si128(v34, 4), 4));
      _mm_store_si128(
        (__m128i *)&v5[-1].m_ang,
        _mm_srli_si128(_mm_slli_si128(_mm_load_si128((const __m128i *)&v5[-1].m_ang), 4), 4));
    }
    while ( v4 < v6->m_numConstraints.m_storage );
  }
}

// File Line: 433
// RVA: 0x132C020
void __fastcall hkPoweredChain_OverwriteVelocityWithExplicitImpulse(int modifiedConstraintIndex, int modifiedCoordinateIndex, hkp3dAngularMotorSolverInfo *motorsState, hkVector8f *velocities)
{
  hkp3dAngularMotorSolverInfo *v4; // r10
  int v5; // xmm0_4

  v4 = &motorsState[(signed __int64)modifiedConstraintIndex];
  if ( (((unsigned __int8)v4->m_broken >> 2 * modifiedCoordinateIndex) & 3) == 1 )
    v5 = LODWORD(v4->m_motorInfos[modifiedCoordinateIndex].m_maxImpulsePerSubstep);
  else
    v5 = LODWORD(v4->m_motorInfos[modifiedCoordinateIndex].m_minImpulsePerSubstep);
  velocities[modifiedConstraintIndex].m_ang.m_quad.m128_i32[modifiedCoordinateIndex] = v5;
}

// File Line: 445
// RVA: 0x132C070
void __fastcall hkPoweredChain_RestoreVelocityValue(int modifiedConstraintIndex, int modifiedCoordinateIndex, hkpChainSolverInfo *info, hkVector8f *velocities)
{
  hkpVelocityAccumulatorOffset *v4; // rax
  hkVector8f *v5; // rsi
  __m128 *v6; // rbx
  __m128 *v7; // r11
  __int64 v8; // r9
  hkp3dAngularMotorSolverInfo *v9; // r10
  __m128 v10; // xmm4
  __m128 v11; // xmm6
  __m128 v12; // xmm6
  hkp2AngJacobian *v13; // rdx
  __m128 v14; // xmm5

  v4 = info->m_va.m_storage;
  v5 = velocities;
  v6 = (__m128 *)(&info->m_accumsBase.m_storage->m_type.m_storage + v4[modifiedConstraintIndex].m_offset);
  v7 = (__m128 *)(&info->m_accumsBase.m_storage->m_type.m_storage + v4[modifiedConstraintIndex + 1].m_offset);
  v8 = modifiedCoordinateIndex;
  v9 = &info->m_motorsState.m_storage[(signed __int64)modifiedConstraintIndex];
  v10 = (__m128)LODWORD(v9->m_motorInfos[modifiedCoordinateIndex].m_damping);
  v11 = (__m128)LODWORD(v9->m_motorInfos[modifiedCoordinateIndex].m_tau);
  v12 = _mm_shuffle_ps(v11, v11, 0);
  v13 = &info->m_jAng.m_storage[modifiedCoordinateIndex + 2 * modifiedConstraintIndex + modifiedConstraintIndex];
  v14 = _mm_add_ps(
          _mm_mul_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_sub_ps(v7[2], v7[5]), v13->m_angular[1].m_quad),
              _mm_mul_ps(_mm_sub_ps(v6[2], v6[5]), v13->m_angular[0].m_quad)),
            _mm_shuffle_ps(v10, v10, 0)),
          _mm_mul_ps(
            _mm_add_ps(_mm_mul_ps(v13->m_angular[0].m_quad, v6[5]), _mm_mul_ps(v13->m_angular[1].m_quad, v7[5])),
            _mm_mul_ps(
              _mm_shuffle_ps(
                info->m_solverInfo->m_invIntegrateVelocityFactor.m_quad,
                info->m_solverInfo->m_invIntegrateVelocityFactor.m_quad,
                0),
              v12)));
  v5->m_ang.m_quad.m128_f32[v8 + 8i64 * modifiedConstraintIndex] = (float)(COERCE_FLOAT(
                                                                             _mm_shuffle_ps(
                                                                               v13->m_angular[1].m_quad,
                                                                               v13->m_angular[1].m_quad,
                                                                               255))
                                                                         * v12.m128_f32[0])
                                                                 - (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v14, v14, 85))
                                                                                 + COERCE_FLOAT(_mm_shuffle_ps(v14, v14, 0)))
                                                                         + COERCE_FLOAT(_mm_shuffle_ps(v14, v14, 170)));
}

// File Line: 461
// RVA: 0x132C170
void __fastcall hkPoweredChain_SolveConstraintMatrix_ComputeVectorG(hkpChainSolverInfo *info, hkVector8f *tempBufferG)
{
  hkVector8f *v2; // r15
  int v3; // ebp
  hkpChainSolverInfo *v4; // r14
  __int64 v5; // r12
  hkVector8f *v6; // rbx
  signed __int64 v7; // rdi
  signed __int64 v8; // rdx
  hkVector8f out; // [rsp+20h] [rbp-38h]

  v2 = tempBufferG + 1;
  v3 = 0;
  v4 = info;
  v2[-1].m_lin = 0i64;
  v2[-1].m_ang = 0i64;
  if ( info->m_numConstraints.m_storage > 0 )
  {
    v5 = 0i64;
    do
    {
      v6 = v4->m_velocitiesBuffer.m_storage;
      v7 = v3;
      hkMatrix6fSetMulV(&out, &v4->m_triples.m_storage[v7].m_lower, &v2[v3 - 1]);
      v8 = (signed __int64)&v4->m_triples.m_storage->m_diagonalInv;
      out.m_lin.m_quad = _mm_sub_ps(v6[v5].m_lin.m_quad, out.m_lin.m_quad);
      out.m_ang.m_quad = _mm_sub_ps(v6[v5].m_ang.m_quad, out.m_ang.m_quad);
      hkMatrix6fSetMulV(&v2[v3++], (hkMatrix6f *)(v7 * 960 + v8), &out);
      ++v5;
    }
    while ( v3 < v4->m_numConstraints.m_storage );
  }
}

// File Line: 483
// RVA: 0x132C250
void __fastcall hkPoweredChain_ScanAndDisableMotors(hkpChainSolverInfo *info, int *modifiedConstraintIndex, int *modifiedCoordinateIndex, float *impulse, hkp3dAngularMotorSolverInfo *motorsState)
{
  signed int v5; // esi
  hkVector8f *v6; // rax
  int v7; // ebx
  float v8; // xmm6_4
  float *v9; // r12
  hkpChainSolverInfo *v10; // rbp
  signed int v11; // er14
  __m128 *v12; // r15
  signed __int64 v13; // rdi
  signed __int64 v14; // r13
  signed int v15; // er8
  signed int v16; // edx
  signed __int64 v17; // r9
  float *v18; // r11
  hkp3dAngularMotorSolverInfo *v19; // r10
  float v20; // xmm2_4
  hkp3dAngularMotorSolverInfo *v21; // r9
  signed __int64 v22; // r10
  char v23; // dl
  hkVector8f b; // [rsp+30h] [rbp-98h]
  hkVector8f out; // [rsp+50h] [rbp-78h]
  int *v26; // [rsp+D8h] [rbp+10h]
  int *v27; // [rsp+E0h] [rbp+18h]

  v27 = modifiedCoordinateIndex;
  v26 = modifiedConstraintIndex;
  v5 = -1;
  v6 = info->m_gTempBuffer.m_storage + 1;
  v7 = info->m_numConstraints.m_storage - 1;
  v8 = 0.0;
  b.m_lin = 0i64;
  b.m_ang = 0i64;
  v9 = impulse;
  v10 = info;
  v11 = -1;
  if ( v7 >= 0 )
  {
    v12 = &v6[v7].m_lin.m_quad;
    v13 = (signed __int64)v7 << 6;
    v14 = v7;
    do
    {
      hkMatrix6fSetMulV(&out, &v10->m_triples.m_storage[v14].m_upper, &b);
      v15 = 0;
      v16 = 0;
      v17 = v13;
      v18 = b.m_ang.m_quad.m128_f32;
      b.m_lin.m_quad = _mm_sub_ps(*v12, out.m_lin.m_quad);
      b.m_ang.m_quad = _mm_sub_ps(v12[1], out.m_ang.m_quad);
      do
      {
        v19 = v10->m_motorsState.m_storage;
        if ( !(((unsigned __int8)*(&v19->m_broken + v13) >> v16) & 3) )
        {
          v20 = fmaxf(
                  *v18 - (float)(*(float *)((char *)&v19->m_motorInfos[0].m_maxImpulsePerSubstep + v17) * 1.05),
                  (float)(*(float *)((char *)&v19->m_motorInfos[0].m_minImpulsePerSubstep + v17) * 1.05) - *v18);
          if ( v20 > v8 )
          {
            *v9 = *v18;
            v8 = v20;
            v5 = v7;
            v11 = v15;
          }
        }
        v16 += 2;
        ++v15;
        ++v18;
        v17 += 20i64;
      }
      while ( v16 < 6 );
      --v14;
      v12 -= 2;
      v13 -= 64i64;
      --v7;
    }
    while ( v7 >= 0 );
    if ( v5 >= 0 )
    {
      v21 = v10->m_motorsState.m_storage;
      v22 = (signed __int64)v5 << 6;
      v23 = 3;
      if ( *(float *)((char *)&v21->m_motorInfos[v11].m_maxImpulsePerSubstep + v22) < *v9 )
        v23 = 1;
      v21[(signed __int64)v5].m_broken = ((v23 & 3) << 2 * v11) | v21[(signed __int64)v5].m_broken & ~(3 << 2 * v11);
      *v26 = v5;
      *v27 = v11;
    }
  }
}

// File Line: 535
// RVA: 0x132C450
void __fastcall hkPoweredChain_ScanAndEnableMotors(hkpChainSolverInfo *info, int *modifiedConstraintIndex, int *modifiedCoordinateIndex, float *impulse, hkp3dAngularMotorSolverInfo *motorsState)
{
  hkVector8f *v5; // rbx
  hkpChainSolverInfo *v6; // rsi
  hkpConstraintChainMatrix6Triple *v7; // rdx
  int v8; // eax
  float v9; // xmm10_4
  signed int v10; // er13
  signed __int64 v11; // rbx
  int v12; // er14
  signed __int64 v13; // rax
  __m128 v14; // xmm2
  __m128 v15; // xmm3
  int v16; // er15
  signed __int64 v17; // rdi
  __m128 *v18; // r12
  hkMatrix6f *v19; // rbx
  __m128 *v20; // rcx
  signed int v21; // er11
  __int64 v22; // rbx
  hkVector4f v23; // xmm11
  signed int v24; // er10
  __int64 v25; // rsi
  unsigned int v26; // er12
  __m128 *v27; // rdi
  int v28; // eax
  __m128 *v29; // rcx
  __int64 v30; // r8
  __int64 v31; // r9
  char *v32; // rcx
  __m128 *v33; // r9
  __m128 *v34; // r8
  __m128 v35; // xmm8
  __m128 *v36; // rdx
  __m128 v37; // xmm7
  __m128 v38; // xmm0
  float v39; // xmm2_4
  __m128 v40; // xmm1
  float v41; // xmm0_4
  signed int v42; // er8
  float v43; // xmm0_4
  __m128 *v44; // rdx
  signed int v45; // [rsp+20h] [rbp-B0h]
  int v46; // [rsp+24h] [rbp-ACh]
  signed __int64 v47; // [rsp+28h] [rbp-A8h]
  signed __int64 v48; // [rsp+30h] [rbp-A0h]
  signed __int64 v49; // [rsp+38h] [rbp-98h]
  hkVector8f b; // [rsp+40h] [rbp-90h]
  hkVector8f out; // [rsp+60h] [rbp-70h]
  hkVector8f v52; // [rsp+80h] [rbp-50h]
  hkVector8f v53; // [rsp+A0h] [rbp-30h]
  hkMatrix6f a; // [rsp+C0h] [rbp-10h]
  __m128 **v55; // [rsp+220h] [rbp+150h]
  signed int *v56; // [rsp+228h] [rbp+158h]
  signed int *v57; // [rsp+230h] [rbp+160h]

  v5 = info->m_gTempBuffer.m_storage;
  v6 = info;
  v7 = info->m_triples.m_storage;
  v8 = info->m_numConstraints.m_storage - 1;
  v9 = 0.0;
  v53.m_lin = 0i64;
  v53.m_ang = 0i64;
  v10 = -1;
  v52.m_lin = 0i64;
  v52.m_ang = 0i64;
  b.m_lin = 0i64;
  v11 = (signed __int64)&v5[1];
  v45 = -1;
  b.m_ang = 0i64;
  hkMatrix6fSetMulV((hkVector8f *)((char *)&out + 16), &v7[v8].m_upper, &b);
  v12 = v6->m_numConstraints.m_storage - 1;
  v13 = 32i64 * v12;
  v14 = _mm_sub_ps(*(__m128 *)(v13 + v11), out.m_ang.m_quad);
  b.m_lin.m_quad = v14;
  v15 = _mm_sub_ps(*(__m128 *)(v13 + v11 + 16), b.m_ang.m_quad);
  b.m_ang.m_quad = v15;
  if ( v12 < 0 )
    return;
  v16 = v12 - 1;
  v48 = 3i64 * v12;
  v17 = (signed __int64)v12 << 6;
  v49 = 4i64 * v12;
  out.m_lin.m_quad.m128_u64[0] = (signed __int64)v12 << 6;
  v46 = v12 - 1;
  v18 = (__m128 *)(v11 + 32i64 * (v12 - 1));
  v47 = (signed __int64)v12 << 6;
  out.m_lin.m_quad.m128_u64[1] = v11 + 32i64 * (v12 - 1);
  while ( 2 )
  {
    v53 = v52;
    v52.m_lin.m_quad = v14;
    v19 = &v6->m_triples.m_storage[(signed __int16)v16].m_lower;
    v52.m_ang.m_quad = v15;
    if ( v16 < 0 )
    {
      b.m_lin = 0i64;
      b.m_ang = 0i64;
    }
    else
    {
      hkMatrix6fSetMulV((hkVector8f *)((char *)&out + 16), v19 + 2, &b);
      b.m_lin.m_quad = _mm_sub_ps(*v18, out.m_ang.m_quad);
      b.m_ang.m_quad = _mm_sub_ps(v18[1], b.m_ang.m_quad);
    }
    if ( v16 < 0 )
    {
      a.m_m[0][0].m_col0 = (hkVector4f)transform.m_quad;
      a.m_m[0][0].m_col1 = (hkVector4f)direction.m_quad;
      a.m_m[0][0].m_col2 = (hkVector4f)stru_141A71280.m_quad;
      a.m_m[1][1].m_col0 = (hkVector4f)transform.m_quad;
      a.m_m[1][1].m_col1 = (hkVector4f)direction.m_quad;
      a.m_m[1][1].m_col2 = (hkVector4f)stru_141A71280.m_quad;
      a.m_m[0][1].m_col0 = 0i64;
      a.m_m[0][1].m_col1 = 0i64;
      a.m_m[0][1].m_col2 = 0i64;
      a.m_m[1][0].m_col0 = 0i64;
      a.m_m[1][0].m_col1 = 0i64;
      a.m_m[1][0].m_col2 = 0i64;
    }
    else
    {
      hkMatrix6fSetTranspose(&a, v19 + 4);
    }
    hkMatrix6fSetMulV(&out, &a, &b);
    hkMatrix6fSetMulV((hkVector8f *)((char *)&out + 16), v19 + 8, &v52);
    out.m_lin.m_quad = _mm_add_ps(out.m_lin.m_quad, out.m_ang.m_quad);
    out.m_ang.m_quad = _mm_add_ps(out.m_ang.m_quad, b.m_ang.m_quad);
    hkMatrix6fSetMulV((hkVector8f *)((char *)&out + 16), v19 + 9, &v53);
    v20 = v55[11];
    v21 = 0;
    v22 = 0i64;
    v23.m_quad = _mm_add_ps(out.m_ang.m_quad, b.m_ang.m_quad);
    v24 = 0;
    v25 = 0i64;
    out.m_lin.m_quad = _mm_add_ps(out.m_lin.m_quad, out.m_ang.m_quad);
    out.m_ang = (hkVector4f)v23.m_quad;
    v26 = *((unsigned __int8 *)v20->m128_u64 + v17);
    v27 = (__m128 *)`hkVector4f::getComponent'::`2'::indexToMask;
    do
    {
      v28 = (v26 >> v24) & 3;
      if ( (v28 - 1) & 0xFFFFFFFD )
      {
LABEL_13:
        v42 = v45;
        goto LABEL_14;
      }
      v29 = v55[8];
      v30 = *(unsigned int *)((char *)v29->m128_u64 + v49);
      v31 = *(unsigned int *)((char *)v29->m128_u64 + v49 + 4);
      v32 = (char *)v55[11] + v47;
      v33 = (__m128 *)((char *)v55[9] + v31);
      v34 = (__m128 *)((char *)v55[9] + v30);
      v35 = _mm_shuffle_ps((__m128)*(unsigned int *)&v32[v25 + 16], (__m128)*(unsigned int *)&v32[v25 + 16], 0);
      v36 = &v55[7][2 * (v22 + v48)];
      v37 = _mm_add_ps(
              _mm_mul_ps(
                _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v34[2], v34[5]), *v36), _mm_mul_ps(_mm_sub_ps(v33[2], v33[5]), v36[1])),
                _mm_shuffle_ps((__m128)*(unsigned int *)&v32[v25 + 20], (__m128)*(unsigned int *)&v32[v25 + 20], 0)),
              _mm_mul_ps(
                _mm_add_ps(_mm_mul_ps(v34[5], *v36), _mm_mul_ps(v33[5], v36[1])),
                _mm_mul_ps(_mm_shuffle_ps((*v55)[4], (*v55)[4], 0), v35)));
      v38 = _mm_and_ps(v23.m_quad, *v27);
      v39 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v36[1], v36[1], 255)) * v35.m128_f32[0])
          - (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v37, v37, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v37, v37, 0)))
                  + COERCE_FLOAT(_mm_shuffle_ps(v37, v37, 170)));
      v40 = _mm_or_ps(_mm_shuffle_ps(v38, v38, 78), v38);
      LODWORD(v41) = *(unsigned __int128 *)&_mm_shuffle_ps(v40, v40, 177) | v40.m128_i32[0];
      if ( v28 == 3 )
      {
        if ( v41 > v39 )
          goto LABEL_13;
      }
      else if ( v28 != 1 || v41 < v39 )
      {
        goto LABEL_13;
      }
      LODWORD(v43) = (unsigned int)(2 * COERCE_SIGNED_INT(v41 - v39)) >> 1;
      if ( v43 <= v9 )
        goto LABEL_13;
      v9 = v43;
      v10 = v12;
      v42 = v21;
      v45 = v21;
LABEL_14:
      v24 += 2;
      ++v21;
      v25 += 20i64;
      ++v22;
      ++v27;
    }
    while ( v24 < 6 );
    v47 -= 64i64;
    v49 -= 4i64;
    v48 -= 3i64;
    v16 = v46 - 1;
    v18 = (__m128 *)(out.m_lin.m_quad.m128_u64[1] - 32);
    v17 = out.m_lin.m_quad.m128_u64[0] - 64;
    --v12;
    --v46;
    out.m_lin.m_quad.m128_u64[1] -= 32i64;
    out.m_lin.m_quad.m128_u64[0] -= 64i64;
    if ( v12 >= 0 )
    {
      v15 = b.m_ang.m_quad;
      v14 = b.m_lin.m_quad;
      v6 = (hkpChainSolverInfo *)v55;
      continue;
    }
    break;
  }
  if ( v10 >= 0 )
  {
    v44 = &v55[11][4 * (signed __int64)v10];
    LOBYTE(v44->m128_u64[0]) &= ~(3 << 2 * v42);
    *v56 = v10;
    *v57 = v42;
  }
}

