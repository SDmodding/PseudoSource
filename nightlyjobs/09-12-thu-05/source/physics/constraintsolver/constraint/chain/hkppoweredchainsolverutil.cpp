// File Line: 48
// RVA: 0x132AA20
void __fastcall hkPoweredChainBuildJacobian(
        hkpPoweredChainBuildJacobianParams *params,
        hkpConstraintQueryIn *in,
        hkpConstraintQueryOut *out)
{
  __int64 m_numConstraints; // rdi
  hkp3dAngularMotorSolverInfo *m_motorsState; // r9
  float m_chainDamping; // xmm2_4
  float m_chainTau; // xmm1_4
  hkpVelocityAccumulatorOffset *m_accumulators; // r10
  hkpJacobianSchema *m_storage; // rbx
  float v11; // xmm0_4
  signed __int64 v12; // rdx
  __int64 v13; // rcx
  unsigned int m_offset; // eax
  __int64 v15; // rcx
  __int64 v16; // rdx
  int v17; // eax
  __int64 v18; // rdx

  m_numConstraints = (unsigned int)params->m_numConstraints;
  m_motorsState = params->m_motorsState;
  m_chainDamping = params->m_chainDamping;
  m_chainTau = params->m_chainTau;
  m_accumulators = params->m_accumulators;
  m_storage = out->m_jacobianSchemas.m_storage;
  *(_QWORD *)&m_storage[8] = params->m_childConstraintStatusWriteBackBuffer;
  v11 = *(float *)m_storage;
  *(float *)&m_storage[24] = m_chainTau;
  *(float *)&m_storage[28] = m_chainDamping;
  *(_WORD *)&m_storage[4] = m_numConstraints;
  *(float *)m_storage = v11 + 0.00000011920929;
  *m_storage = (hkpJacobianSchema)42;
  *(_DWORD *)&m_storage[16] = (240 * (unsigned __int16)m_numConstraints + 1092 * (unsigned __int16)m_numConstraints + 83) & 0xFFFFFFF0;
  if ( (int)m_numConstraints + 1 > 0 )
  {
    v12 = &m_storage[1024 * (unsigned __int64)(unsigned __int16)m_numConstraints
                   + 64
                   + 240 * (unsigned __int16)m_numConstraints]
        - (hkpJacobianSchema *)m_accumulators;
    v13 = (unsigned int)(m_numConstraints + 1);
    do
    {
      m_offset = m_accumulators->m_offset;
      ++m_accumulators;
      *(unsigned int *)((char *)&m_accumulators[-1].m_offset + v12) = m_offset;
      --v13;
    }
    while ( v13 );
  }
  v15 = (__int64)&m_storage[1028 * *(unsigned __int16 *)&m_storage[4] + 68 + 240 * *(unsigned __int16 *)&m_storage[4]];
  if ( (int)m_numConstraints > 0 )
  {
    v16 = m_numConstraints;
    do
    {
      v17 = *(_DWORD *)&m_motorsState->m_broken;
      v15 += 64i64;
      ++m_motorsState;
      *(_DWORD *)(v15 - 64) = v17;
      *(float *)(v15 - 60) = m_motorsState[-1].m_motorInfos[0].m_maxImpulsePerSubstep;
      *(float *)(v15 - 56) = m_motorsState[-1].m_motorInfos[0].m_minImpulsePerSubstep;
      *(float *)(v15 - 52) = m_motorsState[-1].m_motorInfos[0].m_velocity;
      *(float *)(v15 - 48) = m_motorsState[-1].m_motorInfos[0].m_tau;
      *(float *)(v15 - 44) = m_motorsState[-1].m_motorInfos[0].m_damping;
      *(float *)(v15 - 40) = m_motorsState[-1].m_motorInfos[1].m_maxImpulsePerSubstep;
      *(float *)(v15 - 36) = m_motorsState[-1].m_motorInfos[1].m_minImpulsePerSubstep;
      *(float *)(v15 - 32) = m_motorsState[-1].m_motorInfos[1].m_velocity;
      *(float *)(v15 - 28) = m_motorsState[-1].m_motorInfos[1].m_tau;
      *(float *)(v15 - 24) = m_motorsState[-1].m_motorInfos[1].m_damping;
      *(float *)(v15 - 20) = m_motorsState[-1].m_motorInfos[2].m_maxImpulsePerSubstep;
      *(float *)(v15 - 16) = m_motorsState[-1].m_motorInfos[2].m_minImpulsePerSubstep;
      *(float *)(v15 - 12) = m_motorsState[-1].m_motorInfos[2].m_velocity;
      *(float *)(v15 - 8) = m_motorsState[-1].m_motorInfos[2].m_tau;
      *(float *)(v15 - 4) = m_motorsState[-1].m_motorInfos[2].m_damping;
      --v16;
    }
    while ( v16 );
  }
  v18 = *(unsigned __int16 *)&m_storage[4];
  *(float *)&m_storage[20] = params->m_maxTorqueHysterisys;
  *(_QWORD *)&m_storage[8] = params->m_childConstraintStatusWriteBackBuffer;
  hkPoweredChain_BuildConstraintMatrixAndLuDecomposition(
    params->m_numConstraints,
    &params->m_cfm,
    params->m_motorsState,
    (hkp1Lin2AngJacobian *)&out->m_jacobianSchemas.m_storage[32],
    (hkp2AngJacobian *)&out->m_jacobianSchemas.m_storage[144 * (_DWORD)m_numConstraints + 32],
    (hkpVelocityAccumulatorOffset *)&m_storage[1024 * v18 + 64 + 240 * (int)v18],
    params->m_accumsBase,
    (hkpConstraintChainMatrix6Triple *)&m_storage[240 * (_DWORD)v18 + 32],
    960 * m_numConstraints);
  out->m_jacobianSchemas.m_storage += *(unsigned int *)&m_storage[16];
}

// File Line: 211
// RVA: 0x132AC30
void __fastcall hkPoweredChain_BuildConstraintMatrixAndLuDecomposition(
        int numConstraints,
        hkpCfmParam *cfm,
        hkp3dAngularMotorSolverInfo *motorsState,
        hkp1Lin2AngJacobian *j,
        hkp2AngJacobian *jAng,
        hkpVelocityAccumulatorOffset *va,
        hkpVelocityAccumulator *accumsBase,
        hkpConstraintChainMatrix6Triple *triples,
        int bufferSize)
{
  int v9; // eax
  hkVector4f v10; // xmm8
  hkp3dAngularMotorSolverInfo *v11; // rbp
  hkVector4f *v12; // r10
  __m128 *p_m_quad; // r13
  hkVector4f *p_m_col2; // rsi
  hkVector4f *v15; // r14
  __m128 *v16; // rdi
  __int64 m_offset; // r15
  __int64 v18; // rbx
  __int64 v19; // rbp
  __m128 *v20; // r9
  __int64 v21; // r12
  __m128 v22; // xmm5
  __m128 v23; // xmm6
  __m128 v24; // xmm7
  hkVector4f *v25; // rcx
  __m128 *v26; // rdx
  hkVector4f *v27; // r8
  __m128 *v28; // rax
  __int64 v29; // r10
  __m128 v30; // xmm9
  __m128 v31; // xmm10
  __m128 v32; // xmm1
  __m128 v33; // xmm1
  __m128 v34; // xmm4
  __m128 v35; // xmm2
  __m128 v36; // xmm0
  __m128 v37; // xmm2
  __m128 m_quad; // xmm3
  hkpCfmParam *v39; // rax
  hkVector4f *v40; // rcx
  __int64 v41; // rdx
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
  __m128 v66; // xmm4
  __m128 v67; // xmm2
  __m128 v68; // xmm1
  __m128 v69; // xmm14
  __m128 v70; // xmm7
  hkVector4f *v71; // rcx
  __m128 *v72; // rax
  __int64 v73; // rdx
  __m128 v74; // xmm15
  __m128 v75; // xmm12
  __m128 v76; // xmm13
  __m128 v77; // xmm8
  __m128 v78; // xmm3
  __m128 v79; // xmm1
  __m128 v80; // xmm5
  __m128 v81; // xmm2
  __m128 v82; // xmm6
  __m128 v83; // xmm4
  __m128 v84; // xmm5
  __m128 *v85; // rax
  hkVector4f *v86; // rcx
  __int64 v87; // r8
  __m128 *v88; // rdx
  __m128 v89; // xmm0
  __m128 v90; // xmm1
  __m128 v91; // xmm4
  __m128 v92; // xmm2
  __m128 v93; // xmm1
  __m128 v94; // xmm2
  __m128 v95; // xmm4
  hkVector4f *v96; // rcx
  __int64 v97; // rdx
  __m128 v98; // xmm0
  __m128 v99; // xmm1
  __m128 v100; // xmm4
  __m128 v101; // xmm2
  __m128 v102; // xmm1
  __m128 v103; // xmm2
  __m128 v104; // xmm4
  hkVector4f *v105; // rax
  __m128 *v106; // rcx
  __int64 v107; // rdx
  __m128 v108; // xmm0
  __m128 v109; // xmm1
  __m128 v110; // xmm4
  __m128 v111; // xmm2
  __m128 v112; // xmm1
  __m128 v113; // xmm2
  __m128 v114; // xmm4
  hkpConstraintChainMatrix6Triple *v115; // rsi
  int v116; // ebx
  __int64 v117; // rdi
  int v118; // [rsp+30h] [rbp-1C8h]
  int v119; // [rsp+34h] [rbp-1C4h]
  hkVector4f *v120; // [rsp+38h] [rbp-1C0h]
  hkVector4f *m_angular; // [rsp+40h] [rbp-1B8h]
  hkMatrix6f *triplePrevUpper; // [rsp+50h] [rbp-1A8h] BYREF
  hkMatrix6f mtxPrevOffdiag; // [rsp+60h] [rbp-198h] BYREF

  v9 = numConstraints;
  v10.m_quad = 0i64;
  memset(&mtxPrevOffdiag, 0, sizeof(mtxPrevOffdiag));
  v11 = motorsState;
  v118 = 0;
  triplePrevUpper = &mtxPrevOffdiag;
  if ( numConstraints > 0 )
  {
    v12 = &jAng[1].m_angular[1];
    p_m_quad = &j[1].m_angular[1].m_quad;
    v119 = numConstraints - 1;
    v120 = &jAng[1].m_angular[1];
    m_angular = j[3].m_angular;
    p_m_col2 = &triples->m_mtxDiag.m_m[1][1].m_col2;
    do
    {
      v15 = p_m_col2 - 11;
      v16 = &v12[-3].m_quad;
      m_offset = va->m_offset;
      v18 = va[1].m_offset;
      v19 = 0i64;
      ++va;
      v20 = p_m_quad - 4;
      v21 = 3i64;
      do
      {
        if ( v19 < 3 )
        {
          v22 = v20[-1];
          v23 = v20[1];
          v24 = *v20;
          v25 = v15 + 9;
          v26 = v16;
          v27 = v15;
          v28 = v20;
          v29 = 3 - v19;
          v30 = v16[1];
          v31 = *v16;
          do
          {
            v32 = v28[-1];
            v25 = (hkVector4f *)((char *)v25 + 4);
            v28 += 3;
            v26 += 2;
            ++v27;
            v33 = _mm_mul_ps(v32, v22);
            v34 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_shuffle_ps(
                          *(__m128 *)((char *)&accumsBase->m_invMasses.m_quad + m_offset),
                          *(__m128 *)((char *)&accumsBase->m_invMasses.m_quad + m_offset),
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
                      _mm_mul_ps(
                        _mm_mul_ps(v24, v28[-3]),
                        *(__m128 *)((char *)&accumsBase->m_invMasses.m_quad + m_offset))));
            v35 = _mm_mul_ps(v26[-1], v30);
            v33.m128_f32[0] = (float)(_mm_shuffle_ps(v34, v34, 85).m128_f32[0] + _mm_shuffle_ps(v34, v34, 0).m128_f32[0])
                            + _mm_shuffle_ps(v34, v34, 170).m128_f32[0];
            v36 = _mm_mul_ps(v31, v26[-2]);
            v27[-1].m_quad.m128_i32[0] = v33.m128_i32[0];
            v25[-10].m_quad.m128_i32[3] = v33.m128_i32[0];
            v37 = _mm_add_ps(
                    _mm_mul_ps(v35, *(__m128 *)((char *)&accumsBase->m_invMasses.m_quad + v18)),
                    _mm_mul_ps(v36, *(__m128 *)((char *)&accumsBase->m_invMasses.m_quad + m_offset)));
            v33.m128_f32[0] = (float)(_mm_shuffle_ps(v37, v37, 85).m128_f32[0] + _mm_shuffle_ps(v37, v37, 0).m128_f32[0])
                            + _mm_shuffle_ps(v37, v37, 170).m128_f32[0];
            v27[8].m_quad.m128_i32[0] = v33.m128_i32[0];
            v25[-1].m_quad.m128_i32[3] = v33.m128_i32[0];
            --v29;
          }
          while ( v29 );
        }
        ++v19;
        v16 += 2;
        v20 += 3;
        v15 = (hkVector4f *)((char *)v15 + 20);
        --v21;
      }
      while ( v21 );
      m_quad = p_m_col2[-11].m_quad;
      v39 = cfm;
      v40 = p_m_col2 - 5;
      v41 = 3i64;
      v42 = v120[2].m_quad;
      v43 = v120[1].m_quad;
      v44 = v120->m_quad;
      v45 = v120[-1].m_quad;
      v46 = v120[-2].m_quad;
      v47 = v120[-3].m_quad;
      v48 = _mm_add_ps(
              _mm_mul_ps(
                _mm_or_ps(
                  _mm_andnot_ps(
                    (__m128)xmmword_141C20FD0,
                    _mm_or_ps(
                      _mm_and_ps((__m128)xmmword_141C20FB0, p_m_col2[-10].m_quad),
                      _mm_andnot_ps((__m128)xmmword_141C20FB0, m_quad))),
                  _mm_and_ps((__m128)xmmword_141C20FD0, p_m_col2[-9].m_quad)),
                _mm_shuffle_ps((__m128)LODWORD(cfm->m_linMul), (__m128)LODWORD(cfm->m_linMul), 0)),
              _mm_shuffle_ps((__m128)LODWORD(cfm->m_linAdd), (__m128)LODWORD(cfm->m_linAdd), 0));
      m_quad.m128_f32[0] = v48.m128_f32[0];
      p_m_col2[-11] = (hkVector4f)m_quad;
      v49 = _mm_or_ps(
              _mm_and_ps((__m128)xmmword_141C20FD0, v48),
              _mm_andnot_ps((__m128)xmmword_141C20FD0, p_m_col2[-9].m_quad));
      p_m_col2[-10].m_quad = _mm_or_ps(
                               _mm_and_ps((__m128)xmmword_141C20FB0, v48),
                               _mm_andnot_ps((__m128)xmmword_141C20FB0, p_m_col2[-10].m_quad));
      p_m_col2[-9] = (hkVector4f)v49;
      v50 = p_m_col2[-2].m_quad;
      v51 = _mm_shuffle_ps((__m128)LODWORD(v39->m_angAdd), (__m128)LODWORD(v39->m_angAdd), 0);
      v52 = _mm_mul_ps(
              _mm_or_ps(
                _mm_andnot_ps(
                  (__m128)xmmword_141C20FD0,
                  _mm_or_ps(
                    _mm_andnot_ps((__m128)xmmword_141C20FB0, v50),
                    _mm_and_ps((__m128)xmmword_141C20FB0, p_m_col2[-1].m_quad))),
                _mm_and_ps(p_m_col2->m_quad, (__m128)xmmword_141C20FD0)),
              _mm_shuffle_ps((__m128)LODWORD(v39->m_angMul), (__m128)LODWORD(v39->m_angMul), 0));
      v53 = &m_angular[-9].m_quad;
      v54 = _mm_add_ps(v52, v51);
      v50.m128_f32[0] = v54.m128_f32[0];
      p_m_col2[-2] = (hkVector4f)v50;
      v55 = _mm_or_ps(
              _mm_and_ps((__m128)xmmword_141C20FD0, v54),
              _mm_andnot_ps((__m128)xmmword_141C20FD0, p_m_col2->m_quad));
      p_m_col2[-1].m_quad = _mm_or_ps(
                              _mm_and_ps((__m128)xmmword_141C20FB0, v54),
                              _mm_andnot_ps((__m128)xmmword_141C20FB0, p_m_col2[-1].m_quad));
      *p_m_col2 = (hkVector4f)v55;
      do
      {
        v56 = *v53;
        v57 = *(__m128 *)((char *)&accumsBase->m_invMasses.m_quad + m_offset);
        v58 = v53[1];
        ++v40;
        v53 += 3;
        v59 = *(__m128 *)((char *)&accumsBase->m_invMasses.m_quad + v18);
        v60 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v43, v56), v57), _mm_mul_ps(_mm_mul_ps(v42, v58), v59));
        v61 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v58, v44), v59), _mm_mul_ps(_mm_mul_ps(v45, v56), v57));
        v62 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v47, v56), v57), _mm_mul_ps(_mm_mul_ps(v46, v58), v59));
        v40[-1].m_quad = _mm_movelh_ps(
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
      v63 = p_m_col2[-3].m_quad;
      v64 = v118;
      v65 = p_m_col2[-5].m_quad;
      v66 = _mm_unpackhi_ps(v65, p_m_col2[-4].m_quad);
      v67 = _mm_unpacklo_ps(v65, p_m_col2[-4].m_quad);
      p_m_col2[-6].m_quad = _mm_shuffle_ps(v66, v63, 228);
      v68 = _mm_movelh_ps(v67, v63);
      p_m_col2[-8] = (hkVector4f)v68;
      p_m_col2[-7].m_quad = _mm_shuffle_ps(_mm_movehl_ps(v68, v67), v63, 212);
      if ( v118 >= v119 )
      {
        p_m_col2[1] = (hkVector4f)v10.m_quad;
        p_m_col2[2] = (hkVector4f)v10.m_quad;
        p_m_col2[3] = (hkVector4f)v10.m_quad;
        p_m_col2[4] = (hkVector4f)v10.m_quad;
        p_m_col2[5] = (hkVector4f)v10.m_quad;
        p_m_col2[6] = (hkVector4f)v10.m_quad;
        p_m_col2[7] = (hkVector4f)v10.m_quad;
        p_m_col2[8] = (hkVector4f)v10.m_quad;
        p_m_col2[9] = (hkVector4f)v10.m_quad;
        p_m_col2[10] = (hkVector4f)v10.m_quad;
        p_m_col2[11] = (hkVector4f)v10.m_quad;
        p_m_col2[12] = (hkVector4f)v10.m_quad;
      }
      else
      {
        v69 = p_m_quad[1];
        v70 = p_m_quad[3];
        v71 = p_m_col2 + 1;
        v72 = p_m_quad + 4;
        v73 = 3i64;
        v74 = p_m_quad[-2];
        v75 = *p_m_quad;
        v76 = p_m_quad[-3];
        v77 = p_m_quad[-5];
        do
        {
          v78 = *(__m128 *)((char *)&accumsBase->m_invMasses.m_quad + v18);
          v79 = *v72;
          v80 = v72[1];
          ++v71;
          v72 += 3;
          v81 = _mm_shuffle_ps(v78, v78, 255);
          v82 = _mm_sub_ps(_mm_mul_ps(_mm_mul_ps(v80, v70), v78), _mm_mul_ps(_mm_mul_ps(v79, v69), v81));
          v83 = _mm_sub_ps(_mm_mul_ps(_mm_mul_ps(v80, v75), v78), _mm_mul_ps(_mm_mul_ps(v79, v74), v81));
          v84 = _mm_sub_ps(_mm_mul_ps(_mm_mul_ps(v80, v76), v78), _mm_mul_ps(_mm_mul_ps(v77, v79), v81));
          v71[-1].m_quad = _mm_movelh_ps(
                             _mm_unpacklo_ps(
                               _mm_add_ps(
                                 _mm_add_ps(_mm_shuffle_ps(v84, v84, 85), _mm_shuffle_ps(v84, v84, 0)),
                                 _mm_shuffle_ps(v84, v84, 170)),
                               _mm_add_ps(
                                 _mm_add_ps(_mm_shuffle_ps(v83, v83, 85), _mm_shuffle_ps(v83, v83, 0)),
                                 _mm_shuffle_ps(v83, v83, 170))),
                             _mm_unpacklo_ps(
                               _mm_add_ps(
                                 _mm_add_ps(_mm_shuffle_ps(v82, v82, 85), _mm_shuffle_ps(v82, v82, 0)),
                                 _mm_shuffle_ps(v82, v82, 170)),
                               aabbOut.m_quad));
          --v73;
        }
        while ( v73 );
        v85 = &v120[3].m_quad;
        v86 = p_m_col2 + 10;
        v87 = 3i64;
        v88 = &v120[3].m_quad;
        v10.m_quad = 0i64;
        do
        {
          v89 = *(__m128 *)((char *)&accumsBase->m_invMasses.m_quad + v18);
          v90 = *v88;
          ++v86;
          v88 += 2;
          v91 = v90;
          v92 = v90;
          v93 = _mm_mul_ps(_mm_mul_ps(v90, v46), v89);
          v94 = _mm_mul_ps(_mm_mul_ps(v92, v44), v89);
          v95 = _mm_mul_ps(_mm_mul_ps(v91, v42), v89);
          v86[-1].m_quad = _mm_movelh_ps(
                             _mm_unpacklo_ps(
                               _mm_add_ps(
                                 _mm_add_ps(_mm_shuffle_ps(v93, v93, 85), _mm_shuffle_ps(v93, v93, 0)),
                                 _mm_shuffle_ps(v93, v93, 170)),
                               _mm_add_ps(
                                 _mm_add_ps(_mm_shuffle_ps(v94, v94, 85), _mm_shuffle_ps(v94, v94, 0)),
                                 _mm_shuffle_ps(v94, v94, 170))),
                             _mm_unpacklo_ps(
                               _mm_add_ps(
                                 _mm_add_ps(_mm_shuffle_ps(v95, v95, 85), _mm_shuffle_ps(v95, v95, 0)),
                                 _mm_shuffle_ps(v95, v95, 170)),
                               aabbOut.m_quad));
          --v87;
        }
        while ( v87 );
        v96 = p_m_col2 + 4;
        v97 = 3i64;
        do
        {
          v98 = *(__m128 *)((char *)&accumsBase->m_invMasses.m_quad + v18);
          v99 = *v85;
          ++v96;
          v85 += 2;
          v100 = v99;
          v101 = v99;
          v102 = _mm_mul_ps(_mm_mul_ps(v99, v76), v98);
          v103 = _mm_mul_ps(_mm_mul_ps(v101, v75), v98);
          v104 = _mm_mul_ps(_mm_mul_ps(v100, v70), v98);
          v96[-1].m_quad = _mm_movelh_ps(
                             _mm_unpacklo_ps(
                               _mm_add_ps(
                                 _mm_add_ps(_mm_shuffle_ps(v102, v102, 85), _mm_shuffle_ps(v102, v102, 0)),
                                 _mm_shuffle_ps(v102, v102, 170)),
                               _mm_add_ps(
                                 _mm_add_ps(_mm_shuffle_ps(v103, v103, 85), _mm_shuffle_ps(v103, v103, 0)),
                                 _mm_shuffle_ps(v103, v103, 170))),
                             _mm_unpacklo_ps(
                               _mm_add_ps(
                                 _mm_add_ps(_mm_shuffle_ps(v104, v104, 85), _mm_shuffle_ps(v104, v104, 0)),
                                 _mm_shuffle_ps(v104, v104, 170)),
                               aabbOut.m_quad));
          --v97;
        }
        while ( v97 );
        v105 = p_m_col2 + 7;
        v106 = &m_angular->m_quad;
        v107 = 3i64;
        do
        {
          v108 = *(__m128 *)((char *)&accumsBase->m_invMasses.m_quad + v18);
          v109 = *v106;
          ++v105;
          v106 += 3;
          v110 = v109;
          v111 = v109;
          v112 = _mm_mul_ps(_mm_mul_ps(v109, v46), v108);
          v113 = _mm_mul_ps(_mm_mul_ps(v111, v44), v108);
          v114 = _mm_mul_ps(_mm_mul_ps(v110, v42), v108);
          v105[-1].m_quad = _mm_movelh_ps(
                              _mm_unpacklo_ps(
                                _mm_add_ps(
                                  _mm_add_ps(_mm_shuffle_ps(v112, v112, 85), _mm_shuffle_ps(v112, v112, 0)),
                                  _mm_shuffle_ps(v112, v112, 170)),
                                _mm_add_ps(
                                  _mm_add_ps(_mm_shuffle_ps(v113, v113, 85), _mm_shuffle_ps(v113, v113, 0)),
                                  _mm_shuffle_ps(v113, v113, 170))),
                              _mm_unpacklo_ps(
                                _mm_add_ps(
                                  _mm_add_ps(_mm_shuffle_ps(v114, v114, 85), _mm_shuffle_ps(v114, v114, 0)),
                                  _mm_shuffle_ps(v114, v114, 170)),
                                aabbOut.m_quad));
          --v107;
        }
        while ( v107 );
      }
      v9 = numConstraints;
      v12 = v120 + 6;
      p_m_quad += 9;
      p_m_col2 += 60;
      ++v118;
      v120 += 6;
      m_angular += 9;
    }
    while ( v64 + 1 < numConstraints );
    v11 = motorsState;
  }
  if ( v9 > 0 )
  {
    v115 = triples;
    v116 = v9 - 1;
    v117 = (unsigned int)v9;
    do
    {
      hkPoweredChain_ComputeConstraintMatrixLuDecomposition_ForOneRow(
        (hkBool)(v116-- != 0),
        v115++,
        v11++,
        &mtxPrevOffdiag,
        &triplePrevUpper);
      --v117;
    }
    while ( v117 );
  }
}

// File Line: 246
// RVA: 0x132B550
void __fastcall hkPoweredChain_UpdateLuDecomposition(
        int firstConstraintToProcess,
        int numConstraints,
        hkp3dAngularMotorSolverInfo *motorsState,
        hkpConstraintChainMatrix6Triple *triples)
{
  int v4; // r10d
  __int64 v5; // rcx
  hkMatrix6f *p_m_upper; // rax
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
  unsigned int v21; // esi
  __int64 v22; // r14
  hkMatrix6f *triplePrevUpper; // [rsp+30h] [rbp-79h] BYREF
  hkMatrix6f mtxPrevOffdiag; // [rsp+40h] [rbp-69h] BYREF

  v4 = firstConstraintToProcess - 1;
  if ( firstConstraintToProcess - 1 < 0 )
    v4 = 0;
  if ( v4 )
  {
    v5 = v4 - 1;
    p_m_upper = &triples[v5].m_upper;
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
    p_m_upper = &mtxPrevOffdiag;
    memset(&mtxPrevOffdiag, 0, 160);
    mtxPrevOffdiag.m_m[1][1].m_col2 = 0i64;
  }
  triplePrevUpper = p_m_upper;
  mtxPrevOffdiag.m_m[1][1].m_col1 = (hkVector4f)v17.m_quad;
  if ( v4 < numConstraints )
  {
    v18 = &motorsState[(__int64)v4];
    v19 = &triples[v4];
    v20 = numConstraints - v4;
    v21 = v20 - 1;
    v22 = v20;
    do
    {
      hkPoweredChain_ComputeConstraintMatrixLuDecomposition_ForOneRow(
        (hkBool)(v21-- != 0),
        v19++,
        v18++,
        &mtxPrevOffdiag,
        &triplePrevUpper);
      --v22;
    }
    while ( v22 );
  }
}

// File Line: 281
// RVA: 0x132B710
void __fastcall hkPoweredChain_ComputeConstraintMatrixLuDecomposition_ForOneRow(
        hkBool isNotLastRow,
        hkpConstraintChainMatrix6Triple *triple,
        hkp3dAngularMotorSolverInfo *motorsState,
        hkMatrix6f *mtxPrevOffdiag,
        hkMatrix6f **triplePrevUpper)
{
  hkMatrix6f *p_m_mtxDiag; // rdx
  hkMatrix6f *p_Dst; // rcx
  __int64 v11; // rdi
  __int64 v12; // rax
  hkVector4f v13; // xmm0
  hkVector4f v14; // xmm1
  hkVector4f v15; // xmm0
  hkVector4f v16; // xmm1
  hkVector4f v17; // xmm0
  hkVector4f v18; // xmm1
  hkVector4f v19; // xmm0
  hkVector4f v20; // xmm1
  hkVector4f v21; // xmm1
  hkVector4f v22; // xmm0
  hkVector4f v23; // xmm1
  hkMatrix6f *p_mtxNextOffdiag; // rcx
  hkMatrix6f *p_m_mtxNextOffdiag; // rdx
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
  hkVector4f v37; // xmm1
  hkVector4f v38; // xmm0
  hkVector4f v39; // xmm1
  hkVector4f v40; // xmm0
  hkVector4f v41; // xmm1
  hkVector4f v42; // xmm0
  hkVector4f v43; // xmm1
  hkVector4f v44; // xmm0
  hkVector4f v45; // xmm1
  hkVector4f v46; // xmm0
  hkVector4f v47; // xmm1
  __m128 m_quad; // xmm2
  __m128 v49; // xmm3
  hkVector4f v50; // xmm1
  __m128 v51; // xmm2
  __m128 v52; // xmm3
  hkVector4f v53; // xmm1
  hkVector4f v54; // xmm1
  hkVector4f v55; // xmm0
  hkVector4f v56; // xmm1
  hkVector4f v57; // xmm0
  hkVector4f v58; // xmm1
  hkVector4f v59; // xmm0
  hkVector4f v60; // xmm1
  hkVector4f v61; // xmm0
  hkVector4f v62; // xmm1
  hkVector4f v63; // xmm0
  hkVector4f v64; // xmm1
  hkMatrix6f Dst; // [rsp+20h] [rbp-E0h] BYREF
  hkMatrix6f in; // [rsp+E0h] [rbp-20h] BYREF
  hkMatrix6f mtxNextOffdiag; // [rsp+1A0h] [rbp+A0h] BYREF
  hkMatrix6f out; // [rsp+260h] [rbp+160h] BYREF

  p_m_mtxDiag = &triple->m_mtxDiag;
  p_Dst = &Dst;
  v11 = 1i64;
  if ( (((unsigned __int8)&Dst | (unsigned __int8)p_m_mtxDiag) & 0xF) != 0 )
  {
    memmove(&Dst, p_m_mtxDiag, 0xC0ui64);
  }
  else
  {
    v12 = 1i64;
    do
    {
      v13.m_quad = (__m128)p_m_mtxDiag->m_m[0][0].m_col0;
      v14.m_quad = (__m128)p_m_mtxDiag->m_m[0][0].m_col1;
      p_Dst = (hkMatrix6f *)((char *)p_Dst + 128);
      p_m_mtxDiag = (hkMatrix6f *)((char *)p_m_mtxDiag + 128);
      p_Dst[-1].m_m[0][1].m_col1 = (hkVector4f)v13.m_quad;
      v15.m_quad = (__m128)p_m_mtxDiag[-1].m_m[1][0].m_col0;
      p_Dst[-1].m_m[0][1].m_col2 = (hkVector4f)v14.m_quad;
      v16.m_quad = (__m128)p_m_mtxDiag[-1].m_m[1][0].m_col1;
      p_Dst[-1].m_m[1][0].m_col0 = (hkVector4f)v15.m_quad;
      v17.m_quad = (__m128)p_m_mtxDiag[-1].m_m[1][0].m_col2;
      p_Dst[-1].m_m[1][0].m_col1 = (hkVector4f)v16.m_quad;
      v18.m_quad = (__m128)p_m_mtxDiag[-1].m_m[1][1].m_col0;
      p_Dst[-1].m_m[1][0].m_col2 = (hkVector4f)v17.m_quad;
      v19.m_quad = (__m128)p_m_mtxDiag[-1].m_m[1][1].m_col1;
      p_Dst[-1].m_m[1][1].m_col0 = (hkVector4f)v18.m_quad;
      v20.m_quad = (__m128)p_m_mtxDiag[-1].m_m[1][1].m_col2;
      p_Dst[-1].m_m[1][1].m_col1 = (hkVector4f)v19.m_quad;
      p_Dst[-1].m_m[1][1].m_col2 = (hkVector4f)v20.m_quad;
      --v12;
    }
    while ( v12 );
    v21.m_quad = (__m128)p_m_mtxDiag->m_m[0][0].m_col1;
    p_Dst->m_m[0][0].m_col0 = p_m_mtxDiag->m_m[0][0].m_col0;
    v22.m_quad = (__m128)p_m_mtxDiag->m_m[0][0].m_col2;
    p_Dst->m_m[0][0].m_col1 = (hkVector4f)v21.m_quad;
    v23.m_quad = (__m128)p_m_mtxDiag->m_m[0][1].m_col0;
    p_Dst->m_m[0][0].m_col2 = (hkVector4f)v22.m_quad;
    p_Dst->m_m[0][1].m_col0 = (hkVector4f)v23.m_quad;
  }
  p_mtxNextOffdiag = &mtxNextOffdiag;
  p_m_mtxNextOffdiag = &triple->m_mtxNextOffdiag;
  if ( (((unsigned __int8)&mtxNextOffdiag | (unsigned __int8)triple) & 0xF) != 0 )
  {
    memmove(&mtxNextOffdiag, p_m_mtxNextOffdiag, 0xC0ui64);
  }
  else
  {
    do
    {
      v26.m_quad = (__m128)p_m_mtxNextOffdiag->m_m[0][0].m_col0;
      v27.m_quad = (__m128)p_m_mtxNextOffdiag->m_m[0][0].m_col1;
      p_mtxNextOffdiag = (hkMatrix6f *)((char *)p_mtxNextOffdiag + 128);
      p_m_mtxNextOffdiag = (hkMatrix6f *)((char *)p_m_mtxNextOffdiag + 128);
      p_mtxNextOffdiag[-1].m_m[0][1].m_col1 = (hkVector4f)v26.m_quad;
      v28.m_quad = (__m128)p_m_mtxNextOffdiag[-1].m_m[1][0].m_col0;
      p_mtxNextOffdiag[-1].m_m[0][1].m_col2 = (hkVector4f)v27.m_quad;
      v29.m_quad = (__m128)p_m_mtxNextOffdiag[-1].m_m[1][0].m_col1;
      p_mtxNextOffdiag[-1].m_m[1][0].m_col0 = (hkVector4f)v28.m_quad;
      v30.m_quad = (__m128)p_m_mtxNextOffdiag[-1].m_m[1][0].m_col2;
      p_mtxNextOffdiag[-1].m_m[1][0].m_col1 = (hkVector4f)v29.m_quad;
      v31.m_quad = (__m128)p_m_mtxNextOffdiag[-1].m_m[1][1].m_col0;
      p_mtxNextOffdiag[-1].m_m[1][0].m_col2 = (hkVector4f)v30.m_quad;
      v32.m_quad = (__m128)p_m_mtxNextOffdiag[-1].m_m[1][1].m_col1;
      p_mtxNextOffdiag[-1].m_m[1][1].m_col0 = (hkVector4f)v31.m_quad;
      v33.m_quad = (__m128)p_m_mtxNextOffdiag[-1].m_m[1][1].m_col2;
      p_mtxNextOffdiag[-1].m_m[1][1].m_col1 = (hkVector4f)v32.m_quad;
      p_mtxNextOffdiag[-1].m_m[1][1].m_col2 = (hkVector4f)v33.m_quad;
      --v11;
    }
    while ( v11 );
    v34.m_quad = (__m128)p_m_mtxNextOffdiag->m_m[0][0].m_col1;
    p_mtxNextOffdiag->m_m[0][0].m_col0 = p_m_mtxNextOffdiag->m_m[0][0].m_col0;
    v35.m_quad = (__m128)p_m_mtxNextOffdiag->m_m[0][0].m_col2;
    p_mtxNextOffdiag->m_m[0][0].m_col1 = (hkVector4f)v34.m_quad;
    v36.m_quad = (__m128)p_m_mtxNextOffdiag->m_m[0][1].m_col0;
    p_mtxNextOffdiag->m_m[0][0].m_col2 = (hkVector4f)v35.m_quad;
    p_mtxNextOffdiag->m_m[0][1].m_col0 = (hkVector4f)v36.m_quad;
  }
  hkPoweredChain_DisableMotorInMatrixRow_ThisConstraint(motorsState, isNotLastRow, &Dst, &mtxNextOffdiag);
  hkPoweredChain_DisableMotorInMatrixRow_NextConstraint(motorsState, mtxPrevOffdiag);
  hkMatrix6fSetTranspose(&triple->m_lower, mtxPrevOffdiag);
  hkMatrix6fSetMul(&out, &triple->m_lower, *triplePrevUpper);
  v37.m_quad = (__m128)Dst.m_m[0][0].m_col1;
  triple->m_diagonalInv.m_m[0][0].m_col0 = Dst.m_m[0][0].m_col0;
  v38.m_quad = (__m128)Dst.m_m[0][0].m_col2;
  triple->m_diagonalInv.m_m[0][0].m_col1 = (hkVector4f)v37.m_quad;
  v39.m_quad = (__m128)Dst.m_m[0][1].m_col0;
  triple->m_diagonalInv.m_m[0][0].m_col2 = (hkVector4f)v38.m_quad;
  v40.m_quad = (__m128)Dst.m_m[0][1].m_col1;
  triple->m_diagonalInv.m_m[0][1].m_col0 = (hkVector4f)v39.m_quad;
  v41.m_quad = (__m128)Dst.m_m[0][1].m_col2;
  triple->m_diagonalInv.m_m[0][1].m_col1 = (hkVector4f)v40.m_quad;
  v42.m_quad = (__m128)Dst.m_m[1][0].m_col0;
  triple->m_diagonalInv.m_m[0][1].m_col2 = (hkVector4f)v41.m_quad;
  v43.m_quad = (__m128)Dst.m_m[1][0].m_col1;
  triple->m_diagonalInv.m_m[1][0].m_col0 = (hkVector4f)v42.m_quad;
  v44.m_quad = (__m128)Dst.m_m[1][0].m_col2;
  triple->m_diagonalInv.m_m[1][0].m_col1 = (hkVector4f)v43.m_quad;
  v45.m_quad = (__m128)Dst.m_m[1][1].m_col0;
  triple->m_diagonalInv.m_m[1][0].m_col2 = (hkVector4f)v44.m_quad;
  v46.m_quad = (__m128)Dst.m_m[1][1].m_col1;
  triple->m_diagonalInv.m_m[1][1].m_col0 = (hkVector4f)v45.m_quad;
  v47.m_quad = (__m128)Dst.m_m[1][1].m_col2;
  triple->m_diagonalInv.m_m[1][1].m_col1 = (hkVector4f)v46.m_quad;
  triple->m_diagonalInv.m_m[1][1].m_col2 = (hkVector4f)v47.m_quad;
  hkMatrix6fSub(&triple->m_diagonalInv, &out);
  m_quad = triple->m_diagonalInv.m_m[0][0].m_col0.m_quad;
  v49 = _mm_max_ps(
          _mm_or_ps(
            _mm_andnot_ps(
              (__m128)xmmword_141C20FD0,
              _mm_or_ps(
                _mm_and_ps(triple->m_diagonalInv.m_m[0][0].m_col1.m_quad, (__m128)xmmword_141C20FB0),
                _mm_andnot_ps((__m128)xmmword_141C20FB0, m_quad))),
            _mm_and_ps((__m128)xmmword_141C20FD0, triple->m_diagonalInv.m_m[0][0].m_col2.m_quad)),
          *(__m128 *)&epsilon);
  m_quad.m128_f32[0] = v49.m128_f32[0];
  triple->m_diagonalInv.m_m[0][0].m_col0.m_quad = m_quad;
  v50.m_quad = _mm_or_ps(
                 _mm_and_ps((__m128)xmmword_141C20FD0, v49),
                 _mm_andnot_ps((__m128)xmmword_141C20FD0, triple->m_diagonalInv.m_m[0][0].m_col2.m_quad));
  triple->m_diagonalInv.m_m[0][0].m_col1.m_quad = _mm_or_ps(
                                                    _mm_and_ps((__m128)xmmword_141C20FB0, v49),
                                                    _mm_andnot_ps(
                                                      (__m128)xmmword_141C20FB0,
                                                      triple->m_diagonalInv.m_m[0][0].m_col1.m_quad));
  triple->m_diagonalInv.m_m[0][0].m_col2 = (hkVector4f)v50.m_quad;
  v51 = triple->m_diagonalInv.m_m[1][1].m_col0.m_quad;
  v52 = _mm_max_ps(
          _mm_or_ps(
            _mm_andnot_ps(
              (__m128)xmmword_141C20FD0,
              _mm_or_ps(
                _mm_and_ps(triple->m_diagonalInv.m_m[1][1].m_col1.m_quad, (__m128)xmmword_141C20FB0),
                _mm_andnot_ps((__m128)xmmword_141C20FB0, v51))),
            _mm_and_ps((__m128)xmmword_141C20FD0, triple->m_diagonalInv.m_m[1][1].m_col2.m_quad)),
          *(__m128 *)&epsilon);
  v51.m128_f32[0] = v52.m128_f32[0];
  triple->m_diagonalInv.m_m[1][1].m_col0.m_quad = v51;
  v53.m_quad = _mm_or_ps(
                 _mm_andnot_ps((__m128)xmmword_141C20FD0, triple->m_diagonalInv.m_m[1][1].m_col2.m_quad),
                 _mm_and_ps((__m128)xmmword_141C20FD0, v52));
  triple->m_diagonalInv.m_m[1][1].m_col1.m_quad = _mm_or_ps(
                                                    _mm_andnot_ps(
                                                      (__m128)xmmword_141C20FB0,
                                                      triple->m_diagonalInv.m_m[1][1].m_col1.m_quad),
                                                    _mm_and_ps((__m128)xmmword_141C20FB0, v52));
  triple->m_diagonalInv.m_m[1][1].m_col2 = (hkVector4f)v53.m_quad;
  v54.m_quad = (__m128)triple->m_diagonalInv.m_m[0][0].m_col1;
  in.m_m[0][0].m_col0 = triple->m_diagonalInv.m_m[0][0].m_col0;
  v55.m_quad = (__m128)triple->m_diagonalInv.m_m[0][0].m_col2;
  in.m_m[0][0].m_col1 = (hkVector4f)v54.m_quad;
  v56.m_quad = (__m128)triple->m_diagonalInv.m_m[0][1].m_col0;
  in.m_m[0][0].m_col2 = (hkVector4f)v55.m_quad;
  v57.m_quad = (__m128)triple->m_diagonalInv.m_m[0][1].m_col1;
  in.m_m[0][1].m_col0 = (hkVector4f)v56.m_quad;
  v58.m_quad = (__m128)triple->m_diagonalInv.m_m[0][1].m_col2;
  in.m_m[0][1].m_col1 = (hkVector4f)v57.m_quad;
  v59.m_quad = (__m128)triple->m_diagonalInv.m_m[1][0].m_col0;
  in.m_m[0][1].m_col2 = (hkVector4f)v58.m_quad;
  v60.m_quad = (__m128)triple->m_diagonalInv.m_m[1][0].m_col1;
  in.m_m[1][0].m_col0 = (hkVector4f)v59.m_quad;
  v61.m_quad = (__m128)triple->m_diagonalInv.m_m[1][0].m_col2;
  in.m_m[1][0].m_col1 = (hkVector4f)v60.m_quad;
  v62.m_quad = (__m128)triple->m_diagonalInv.m_m[1][1].m_col0;
  in.m_m[1][0].m_col2 = (hkVector4f)v61.m_quad;
  v63.m_quad = (__m128)triple->m_diagonalInv.m_m[1][1].m_col1;
  in.m_m[1][1].m_col0 = (hkVector4f)v62.m_quad;
  v64.m_quad = (__m128)triple->m_diagonalInv.m_m[1][1].m_col2;
  in.m_m[1][1].m_col1 = (hkVector4f)v63.m_quad;
  in.m_m[1][1].m_col2 = (hkVector4f)v64.m_quad;
  hkMatrix6fSetInvert(&triple->m_diagonalInv, &in);
  hkMatrix6fSetMul(&triple->m_upper, &triple->m_diagonalInv, &mtxNextOffdiag);
  mtxPrevOffdiag->m_m[0][0].m_col0 = triple->m_mtxNextOffdiag.m_m[0][0].m_col0;
  mtxPrevOffdiag->m_m[0][0].m_col1 = triple->m_mtxNextOffdiag.m_m[0][0].m_col1;
  mtxPrevOffdiag->m_m[0][0].m_col2 = triple->m_mtxNextOffdiag.m_m[0][0].m_col2;
  mtxPrevOffdiag->m_m[0][1].m_col0 = triple->m_mtxNextOffdiag.m_m[0][1].m_col0;
  mtxPrevOffdiag->m_m[0][1].m_col1 = triple->m_mtxNextOffdiag.m_m[0][1].m_col1;
  mtxPrevOffdiag->m_m[0][1].m_col2 = triple->m_mtxNextOffdiag.m_m[0][1].m_col2;
  mtxPrevOffdiag->m_m[1][0].m_col0 = triple->m_mtxNextOffdiag.m_m[1][0].m_col0;
  mtxPrevOffdiag->m_m[1][0].m_col1 = triple->m_mtxNextOffdiag.m_m[1][0].m_col1;
  mtxPrevOffdiag->m_m[1][0].m_col2 = triple->m_mtxNextOffdiag.m_m[1][0].m_col2;
  mtxPrevOffdiag->m_m[1][1].m_col0 = triple->m_mtxNextOffdiag.m_m[1][1].m_col0;
  mtxPrevOffdiag->m_m[1][1].m_col1 = triple->m_mtxNextOffdiag.m_m[1][1].m_col1;
  mtxPrevOffdiag->m_m[1][1].m_col2 = triple->m_mtxNextOffdiag.m_m[1][1].m_col2;
  *triplePrevUpper = &triple->m_upper;
}

// File Line: 334
// RVA: 0x132BBB0
void __fastcall hkPoweredChain_DisableMotorInMatrixRow_ThisConstraint(
        hkp3dAngularMotorSolverInfo *motorsState,
        hkBool isNotLastRow,
        hkMatrix6f *mtxDiag,
        hkMatrix6f *mtxNextOffdiag)
{
  unsigned __int8 m_broken; // r10
  hkVector4f v6; // xmm3
  hkVector4f v7; // xmm4
  hkVector4f v8; // xmm5
  __m128 v9; // xmm2
  __m128 v10; // xmm1
  __m128 v11; // xmm0
  hkVector4f v12; // xmm3
  hkVector4f v13; // xmm0
  int v14; // r9d
  __int64 v15; // rax
  __m128 v16; // xmm2
  __m128 v17; // xmm0
  __m128 v18; // xmm2
  __m128 v19; // xmm5
  __m128 v20; // xmm3
  hkVector4f v21; // xmm1
  hkVector4f v22; // xmm0
  __m128 v23; // xmm2
  __m128 v24; // xmm3
  hkVector4f v25; // xmm1
  __m128 v26; // [rsp+0h] [rbp-68h]
  __m128 v27; // [rsp+10h] [rbp-58h]
  __m128 v28; // [rsp+20h] [rbp-48h]
  __m128 v29; // [rsp+30h] [rbp-38h]
  __m128 v30; // [rsp+40h] [rbp-28h]
  __m128 v31; // [rsp+50h] [rbp-18h]

  m_broken = motorsState->m_broken;
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
      if ( ((m_broken >> v14) & 3) != 0 )
      {
        v17 = 0i64;
        *(__m128 *)((char *)&v29 + v15) = 0i64;
        if ( !isNotLastRow.m_bool )
          v17 = *(__m128 *)((char *)&transform.m_quad + v15);
        *(__m128 *)((char *)&v26 + v15) = v17;
      }
      v14 += 2;
      v15 += 16i64;
    }
    while ( v14 < 6 );
    v18 = v31;
    v19 = v26;
    v20 = _mm_unpacklo_ps(v29, v30);
    mtxNextOffdiag->m_m[1][0].m_col2.m_quad = _mm_shuffle_ps(_mm_unpackhi_ps(v29, v30), v31, 228);
    v21.m_quad = _mm_movelh_ps(v20, v18);
    mtxNextOffdiag->m_m[1][0].m_col0 = (hkVector4f)v21.m_quad;
    v22.m_quad = _mm_shuffle_ps(_mm_movehl_ps(v21.m_quad, v20), v18, 212);
    v23 = v28;
    mtxNextOffdiag->m_m[1][0].m_col1 = (hkVector4f)v22.m_quad;
    v24 = _mm_unpacklo_ps(v19, v27);
    v25.m_quad = _mm_movelh_ps(v24, v23);
    mtxNextOffdiag->m_m[1][1].m_col2.m_quad = _mm_shuffle_ps(_mm_unpackhi_ps(v19, v27), v23, 228);
    mtxNextOffdiag->m_m[1][1].m_col0 = (hkVector4f)v25.m_quad;
    mtxNextOffdiag->m_m[1][1].m_col1.m_quad = _mm_shuffle_ps(_mm_movehl_ps(v25.m_quad, v24), v23, 212);
  }
}

// File Line: 366
// RVA: 0x132BD30
void __fastcall hkPoweredChain_DisableMotorInMatrixRow_NextConstraint(
        hkp3dAngularMotorSolverInfo *motorsState,
        hkMatrix6f *mtxNextOffdiag)
{
  int v2; // eax
  hkMatrix3f *v3; // r8

  if ( motorsState->m_broken )
  {
    v2 = 0;
    v3 = &mtxNextOffdiag->m_m[1][1];
    do
    {
      if ( (((unsigned __int8)motorsState->m_broken >> v2) & 3) != 0 )
      {
        v3[-2].m_col0 = 0i64;
        v3->m_col0 = 0i64;
      }
      v2 += 2;
      v3 = (hkMatrix3f *)((char *)v3 + 16);
    }
    while ( v2 < 6 );
  }
}

// File Line: 407
// RVA: 0x132BD70
void __fastcall hkPoweredChain_CalculateVelocities(
        hkSolverStepTemp *temp,
        hkpChainSolverInfo *info,
        const __m128i *velocities)
{
  hkp1Lin2AngJacobian *m_storage; // rdi
  int v4; // r11d
  hkVector4f *v8; // rsi
  __int64 v9; // rbx
  hkpVelocityAccumulatorOffset *v10; // rax
  __m128 *v11; // rdx
  __m128 *v12; // r8
  float *p_m_damping; // rcx
  __m128 v14; // xmm11
  __m128 v15; // xmm12
  __m128 v16; // xmm13
  __m128 v17; // xmm9
  __m128 v18; // xmm0
  __m128 v19; // xmm8
  __m128 v20; // xmm11
  const __m128i *v21; // rdx
  __m128 v22; // xmm10
  __int64 v23; // r8
  __m128 v24; // xmm8
  __m128 v25; // xmm9
  __m128 v26; // xmm10
  __m128 m_quad; // xmm7
  __m128 v28; // xmm5
  __m128 v29; // xmm5
  __m128 v30; // xmm4
  __m128 v31; // xmm5
  __m128 v32; // xmm6
  __m128i si128; // xmm0

  m_storage = info->m_j.m_storage;
  v4 = 0;
  if ( info->m_numConstraints.m_storage > 0 )
  {
    v8 = &info->m_jAng.m_storage->m_angular[1];
    v9 = 0i64;
    do
    {
      v10 = info->m_va.m_storage;
      v11 = (__m128 *)(&info->m_accumsBase.m_storage->m_type.m_storage + v10[++v9].m_offset);
      v12 = (__m128 *)(&info->m_accumsBase.m_storage->m_type.m_storage + v10[v9 - 1].m_offset);
      p_m_damping = &info->m_motorsState.m_storage[(__int64)v4].m_motorInfos[0].m_damping;
      v14 = v12[4];
      v15 = v12[5];
      v16 = v11[5];
      v17 = v11[2];
      v18 = _mm_sub_ps(v11[1], v11[4]);
      v19 = _mm_sub_ps(v12[1], v14);
      v20 = _mm_sub_ps(v14, v11[4]);
      v21 = velocities;
      v22 = v12[2];
      v23 = 3i64;
      v24 = _mm_sub_ps(v19, v18);
      v25 = _mm_sub_ps(v17, v16);
      v26 = _mm_sub_ps(v22, v15);
      do
      {
        m_quad = m_storage->m_linear0.m_quad;
        v28 = m_storage->m_angular[1].m_quad;
        v21 = (const __m128i *)((char *)v21 + 4);
        p_m_damping += 5;
        ++m_storage;
        v8 += 2;
        v29 = _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_mul_ps(v28, v16), _mm_mul_ps(v15, m_storage[-1].m_angular[0].m_quad)),
                    _mm_mul_ps(v20, m_quad)),
                  _mm_mul_ps(
                    _mm_shuffle_ps(
                      info->m_solverInfo->m_invIntegrateVelocityFactor.m_quad,
                      info->m_solverInfo->m_invIntegrateVelocityFactor.m_quad,
                      0),
                    info->m_schemaTau.m_real)),
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(v25, m_storage[-1].m_angular[1].m_quad),
                      _mm_mul_ps(v26, m_storage[-1].m_angular[0].m_quad)),
                    _mm_mul_ps(v24, m_quad)),
                  info->m_schemaDamping.m_real));
        *(float *)&v21[-1].m128i_i32[3] = (float)(_mm_shuffle_ps(m_quad, m_quad, 255).m128_f32[0]
                                                * COERCE_FLOAT(*(_OWORD *)&info->m_schemaTau))
                                        - (float)((float)(_mm_shuffle_ps(v29, v29, 85).m128_f32[0]
                                                        + _mm_shuffle_ps(v29, v29, 0).m128_f32[0])
                                                + _mm_shuffle_ps(v29, v29, 170).m128_f32[0]);
        v30 = v8[-2].m_quad;
        v31 = _mm_shuffle_ps((__m128)*((unsigned int *)p_m_damping - 6), (__m128)*((unsigned int *)p_m_damping - 6), 0);
        v32 = _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(_mm_mul_ps(v8[-3].m_quad, v15), _mm_mul_ps(v30, v16)),
                  _mm_mul_ps(
                    _mm_shuffle_ps(
                      info->m_solverInfo->m_invIntegrateVelocityFactor.m_quad,
                      info->m_solverInfo->m_invIntegrateVelocityFactor.m_quad,
                      0),
                    v31)),
                _mm_mul_ps(
                  _mm_add_ps(_mm_mul_ps(v26, v8[-3].m_quad), _mm_mul_ps(v25, v30)),
                  _mm_shuffle_ps(
                    (__m128)*((unsigned int *)p_m_damping - 5),
                    (__m128)*((unsigned int *)p_m_damping - 5),
                    0)));
        *(float *)&v21->m128i_i32[3] = (float)((float)((float)(_mm_shuffle_ps(
                                                                 (__m128)*((unsigned int *)p_m_damping - 7),
                                                                 (__m128)*((unsigned int *)p_m_damping - 7),
                                                                 0).m128_f32[0]
                                                             * temp->m_intregratePositionFactor.m_real.m128_f32[0])
                                                     + _mm_shuffle_ps(v30, v30, 255).m128_f32[0])
                                             * v31.m128_f32[0])
                                     - (float)((float)(_mm_shuffle_ps(v32, v32, 85).m128_f32[0]
                                                     + _mm_shuffle_ps(v32, v32, 0).m128_f32[0])
                                             + _mm_shuffle_ps(v32, v32, 170).m128_f32[0]);
        --v23;
      }
      while ( v23 );
      si128 = _mm_load_si128(velocities);
      ++v4;
      velocities += 2;
      velocities[-2] = _mm_srli_si128(_mm_slli_si128(si128, 4), 4);
      velocities[-1] = _mm_srli_si128(_mm_slli_si128(_mm_load_si128(velocities - 1), 4), 4);
    }
    while ( v4 < info->m_numConstraints.m_storage );
  }
}

// File Line: 433
// RVA: 0x132C020
void __fastcall hkPoweredChain_OverwriteVelocityWithExplicitImpulse(
        int modifiedConstraintIndex,
        int modifiedCoordinateIndex,
        hkp3dAngularMotorSolverInfo *motorsState,
        hkVector8f *velocities)
{
  hkp3dAngularMotorSolverInfo *v4; // r10
  int m_maxImpulsePerSubstep_low; // xmm0_4

  v4 = &motorsState[(__int64)modifiedConstraintIndex];
  if ( (((unsigned __int8)v4->m_broken >> (2 * modifiedCoordinateIndex)) & 3) == 1 )
    m_maxImpulsePerSubstep_low = LODWORD(v4->m_motorInfos[modifiedCoordinateIndex].m_maxImpulsePerSubstep);
  else
    m_maxImpulsePerSubstep_low = LODWORD(v4->m_motorInfos[modifiedCoordinateIndex].m_minImpulsePerSubstep);
  velocities[modifiedConstraintIndex].m_ang.m_quad.m128_i32[modifiedCoordinateIndex] = m_maxImpulsePerSubstep_low;
}

// File Line: 445
// RVA: 0x132C070
void __fastcall hkPoweredChain_RestoreVelocityValue(
        int modifiedConstraintIndex,
        int modifiedCoordinateIndex,
        hkpChainSolverInfo *info,
        hkVector8f *velocities)
{
  hkpVelocityAccumulatorOffset *m_storage; // rax
  __m128 *v6; // rbx
  __m128 *v7; // r11
  __int64 v8; // r9
  hkp3dAngularMotorSolverInfo *v9; // r10
  __m128 m_damping_low; // xmm4
  __m128 m_tau_low; // xmm6
  __m128 v12; // xmm6
  hkp2AngJacobian *v13; // rdx
  __m128 v14; // xmm5

  m_storage = info->m_va.m_storage;
  v6 = (__m128 *)(&info->m_accumsBase.m_storage->m_type.m_storage + m_storage[modifiedConstraintIndex].m_offset);
  v7 = (__m128 *)(&info->m_accumsBase.m_storage->m_type.m_storage + m_storage[modifiedConstraintIndex + 1].m_offset);
  v8 = modifiedCoordinateIndex;
  v9 = &info->m_motorsState.m_storage[(__int64)modifiedConstraintIndex];
  m_damping_low = (__m128)LODWORD(v9->m_motorInfos[modifiedCoordinateIndex].m_damping);
  m_tau_low = (__m128)LODWORD(v9->m_motorInfos[modifiedCoordinateIndex].m_tau);
  v12 = _mm_shuffle_ps(m_tau_low, m_tau_low, 0);
  v13 = &info->m_jAng.m_storage[2 * modifiedConstraintIndex + modifiedCoordinateIndex + modifiedConstraintIndex];
  v14 = _mm_add_ps(
          _mm_mul_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_sub_ps(v7[2], v7[5]), v13->m_angular[1].m_quad),
              _mm_mul_ps(_mm_sub_ps(v6[2], v6[5]), v13->m_angular[0].m_quad)),
            _mm_shuffle_ps(m_damping_low, m_damping_low, 0)),
          _mm_mul_ps(
            _mm_add_ps(_mm_mul_ps(v13->m_angular[0].m_quad, v6[5]), _mm_mul_ps(v13->m_angular[1].m_quad, v7[5])),
            _mm_mul_ps(
              _mm_shuffle_ps(
                info->m_solverInfo->m_invIntegrateVelocityFactor.m_quad,
                info->m_solverInfo->m_invIntegrateVelocityFactor.m_quad,
                0),
              v12)));
  velocities[modifiedConstraintIndex].m_ang.m_quad.m128_f32[v8] = (float)(_mm_shuffle_ps(
                                                                            v13->m_angular[1].m_quad,
                                                                            v13->m_angular[1].m_quad,
                                                                            255).m128_f32[0]
                                                                        * v12.m128_f32[0])
                                                                - (float)((float)(_mm_shuffle_ps(v14, v14, 85).m128_f32[0]
                                                                                + _mm_shuffle_ps(v14, v14, 0).m128_f32[0])
                                                                        + _mm_shuffle_ps(v14, v14, 170).m128_f32[0]);
}

// File Line: 461
// RVA: 0x132C170
void __fastcall hkPoweredChain_SolveConstraintMatrix_ComputeVectorG(hkpChainSolverInfo *info, hkVector8f *tempBufferG)
{
  hkVector8f *v2; // r15
  int v3; // ebp
  __int64 v5; // r12
  hkVector8f *m_storage; // rbx
  unsigned __int64 v7; // rdi
  hkMatrix6f *p_m_diagonalInv; // rdx
  hkVector8f out; // [rsp+20h] [rbp-38h] BYREF

  v2 = tempBufferG + 1;
  v3 = 0;
  tempBufferG->m_lin = 0i64;
  tempBufferG->m_ang = 0i64;
  if ( info->m_numConstraints.m_storage > 0 )
  {
    v5 = 0i64;
    do
    {
      m_storage = info->m_velocitiesBuffer.m_storage;
      v7 = 5i64 * v3;
      hkMatrix6fSetMulV(&out, &info->m_triples.m_storage[v7 / 5].m_lower, &v2[v3 - 1]);
      p_m_diagonalInv = &info->m_triples.m_storage->m_diagonalInv;
      out.m_lin.m_quad = _mm_sub_ps(m_storage[v5].m_lin.m_quad, out.m_lin.m_quad);
      out.m_ang.m_quad = _mm_sub_ps(m_storage[v5].m_ang.m_quad, out.m_ang.m_quad);
      hkMatrix6fSetMulV(&v2[v3++], &p_m_diagonalInv[v7], &out);
      ++v5;
    }
    while ( v3 < info->m_numConstraints.m_storage );
  }
}

// File Line: 483
// RVA: 0x132C250
void __fastcall hkPoweredChain_ScanAndDisableMotors(
        hkpChainSolverInfo *info,
        int *modifiedConstraintIndex,
        int *modifiedCoordinateIndex,
        float *impulse,
        hkp3dAngularMotorSolverInfo *motorsState)
{
  int v5; // esi
  hkVector8f *v6; // rax
  int v7; // ebx
  float v8; // xmm6_4
  int v11; // r14d
  __m128 *p_m_quad; // r15
  __int64 v13; // rdi
  __int64 v14; // r13
  int v15; // r8d
  int v16; // edx
  __int64 v17; // r9
  hkVector4f *p_m_ang; // r11
  hkp3dAngularMotorSolverInfo *m_storage; // r10
  float v20; // xmm2_4
  hkp3dAngularMotorSolverInfo *v21; // r9
  __int64 v22; // r10
  char v23; // dl
  hkVector8f b; // [rsp+30h] [rbp-98h] BYREF
  hkVector8f out; // [rsp+50h] [rbp-78h] BYREF

  v5 = -1;
  v6 = info->m_gTempBuffer.m_storage + 1;
  v7 = info->m_numConstraints.m_storage - 1;
  v8 = 0.0;
  memset(&b, 0, sizeof(b));
  v11 = -1;
  if ( v7 >= 0 )
  {
    p_m_quad = &v6[v7].m_lin.m_quad;
    v13 = (__int64)v7 << 6;
    v14 = v7;
    do
    {
      hkMatrix6fSetMulV(&out, &info->m_triples.m_storage[v14].m_upper, &b);
      v15 = 0;
      v16 = 0;
      v17 = v13;
      p_m_ang = &b.m_ang;
      b.m_lin.m_quad = _mm_sub_ps(*p_m_quad, out.m_lin.m_quad);
      b.m_ang.m_quad = _mm_sub_ps(p_m_quad[1], out.m_ang.m_quad);
      do
      {
        m_storage = info->m_motorsState.m_storage;
        if ( (((unsigned __int8)*(&m_storage->m_broken + v13) >> v16) & 3) == 0 )
        {
          v20 = fmaxf(
                  p_m_ang->m_quad.m128_f32[0]
                - (float)(*(float *)((char *)&m_storage->m_motorInfos[0].m_maxImpulsePerSubstep + v17) * 1.05),
                  (float)(*(float *)((char *)&m_storage->m_motorInfos[0].m_minImpulsePerSubstep + v17) * 1.05)
                - p_m_ang->m_quad.m128_f32[0]);
          if ( v20 > v8 )
          {
            *impulse = p_m_ang->m_quad.m128_f32[0];
            v8 = v20;
            v5 = v7;
            v11 = v15;
          }
        }
        v16 += 2;
        ++v15;
        p_m_ang = (hkVector4f *)((char *)p_m_ang + 4);
        v17 += 20i64;
      }
      while ( v16 < 6 );
      --v14;
      p_m_quad -= 2;
      v13 -= 64i64;
      --v7;
    }
    while ( v7 >= 0 );
    if ( v5 >= 0 )
    {
      v21 = info->m_motorsState.m_storage;
      v22 = (__int64)v5 << 6;
      v23 = 3;
      if ( *(float *)((char *)&v21->m_motorInfos[v11].m_maxImpulsePerSubstep + v22) < *impulse )
        v23 = 1;
      *(&v21->m_broken + v22) = ((v23 & 3) << (2 * v11)) | *(&v21->m_broken + v22) & ~(3 << (2 * v11));
      *modifiedConstraintIndex = v5;
      *modifiedCoordinateIndex = v11;
    }
  }
}

// File Line: 535
// RVA: 0x132C450
void __fastcall hkPoweredChain_ScanAndEnableMotors(
        __m128 **info,
        int *modifiedConstraintIndex,
        int *modifiedCoordinateIndex,
        float *impulse,
        hkp3dAngularMotorSolverInfo *motorsState)
{
  hkVector8f *v5; // rbx
  __m128 **v6; // rsi
  hkpConstraintChainMatrix6Triple *v7; // rdx
  int v8; // eax
  float v9; // xmm10_4
  int v10; // r13d
  hkVector8f *v11; // rbx
  int v12; // r14d
  __int64 v13; // rax
  __m128 v14; // xmm2
  __m128 m_quad; // xmm3
  int v16; // r15d
  __int64 v17; // rdi
  __m128 *p_m_quad; // r12
  hkMatrix6f *v19; // rbx
  __m128 *v20; // rcx
  int v21; // r11d
  __int64 v22; // rbx
  hkVector4f v23; // xmm11
  int v24; // r10d
  __int64 v25; // rsi
  unsigned int v26; // r12d
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
  int v42; // r8d
  float v43; // xmm0_4
  __m128 *v44; // rdx
  int v45; // [rsp+20h] [rbp-B0h]
  int v46; // [rsp+24h] [rbp-ACh]
  __int64 v47; // [rsp+28h] [rbp-A8h]
  __int64 v48; // [rsp+30h] [rbp-A0h]
  __int64 v49; // [rsp+38h] [rbp-98h]
  hkVector8f b; // [rsp+40h] [rbp-90h] BYREF
  hkVector8f out; // [rsp+60h] [rbp-70h] BYREF
  hkVector8f v52; // [rsp+80h] [rbp-50h] BYREF
  hkVector8f v53; // [rsp+A0h] [rbp-30h] BYREF
  hkMatrix6f a; // [rsp+C0h] [rbp-10h] BYREF
  __m128 **v55; // [rsp+220h] [rbp+150h]
  int *v56; // [rsp+228h] [rbp+158h]
  int *v57; // [rsp+230h] [rbp+160h]

  v5 = (hkVector8f *)info[12];
  v6 = info;
  v7 = (hkpConstraintChainMatrix6Triple *)info[10];
  v8 = *((_DWORD *)info + 2) - 1;
  v9 = 0.0;
  memset(&v53, 0, sizeof(v53));
  v10 = -1;
  memset(&v52, 0, sizeof(v52));
  memset(&b, 0, sizeof(b));
  v11 = v5 + 1;
  v45 = -1;
  hkMatrix6fSetMulV((hkVector8f *)&out.m_ang, &v7[v8].m_upper, &b);
  v12 = *((_DWORD *)v6 + 2) - 1;
  v13 = v12;
  v14 = _mm_sub_ps(v11[v13].m_lin.m_quad, out.m_ang.m_quad);
  b.m_lin.m_quad = v14;
  m_quad = _mm_sub_ps(v11[v13].m_ang.m_quad, b.m_ang.m_quad);
  b.m_ang.m_quad = m_quad;
  if ( v12 < 0 )
    return;
  v16 = v12 - 1;
  v48 = 3i64 * v12;
  v17 = (__int64)v12 << 6;
  v49 = v12;
  out.m_lin.m_quad.m128_u64[0] = v17;
  v46 = v12 - 1;
  p_m_quad = &v11[v12 - 1].m_lin.m_quad;
  v47 = v17;
  out.m_lin.m_quad.m128_u64[1] = (unsigned __int64)p_m_quad;
  while ( 2 )
  {
    v53 = v52;
    v52.m_lin.m_quad = v14;
    v19 = (hkMatrix6f *)&v6[10][60 * (__int16)v16];
    v52.m_ang.m_quad = m_quad;
    if ( v16 < 0 )
    {
      memset(&b, 0, sizeof(b));
    }
    else
    {
      hkMatrix6fSetMulV((hkVector8f *)&out.m_ang, v19 + 2, &b);
      b.m_lin.m_quad = _mm_sub_ps(*p_m_quad, out.m_ang.m_quad);
      b.m_ang.m_quad = _mm_sub_ps(p_m_quad[1], b.m_ang.m_quad);
    }
    if ( v16 < 0 )
    {
      a.m_m[0][0].m_col0 = (hkVector4f)transform.m_quad;
      a.m_m[0][0].m_col1 = (hkVector4f)direction.m_quad;
      a.m_m[0][0].m_col2 = (hkVector4f)stru_141A71280.m_quad;
      a.m_m[1][1].m_col0 = (hkVector4f)transform.m_quad;
      a.m_m[1][1].m_col1 = (hkVector4f)direction.m_quad;
      a.m_m[1][1].m_col2 = (hkVector4f)stru_141A71280.m_quad;
      memset(&a.m_m[0][1], 0, 96);
    }
    else
    {
      hkMatrix6fSetTranspose(&a, v19 + 4);
    }
    hkMatrix6fSetMulV(&out, &a, &b);
    hkMatrix6fSetMulV((hkVector8f *)&out.m_ang, v19 + 8, &v52);
    out.m_lin.m_quad = _mm_add_ps(out.m_lin.m_quad, out.m_ang.m_quad);
    out.m_ang.m_quad = _mm_add_ps(out.m_ang.m_quad, b.m_ang.m_quad);
    hkMatrix6fSetMulV((hkVector8f *)&out.m_ang, v19 + 9, &v53);
    v20 = v55[11];
    v21 = 0;
    v22 = 0i64;
    v23.m_quad = _mm_add_ps(out.m_ang.m_quad, b.m_ang.m_quad);
    v24 = 0;
    v25 = 0i64;
    out.m_lin.m_quad = _mm_add_ps(out.m_lin.m_quad, out.m_ang.m_quad);
    out.m_ang = (hkVector4f)v23.m_quad;
    v26 = (unsigned __int8)v20->m128_i8[v17];
    v27 = (__m128 *)`hkVector4f::getComponent::`2::indexToMask;
    do
    {
      v28 = (v26 >> v24) & 3;
      if ( ((v28 - 1) & 0xFFFFFFFD) != 0 )
      {
LABEL_13:
        v42 = v45;
        goto LABEL_14;
      }
      v29 = v55[8];
      v30 = v29->m128_u32[v49];
      v31 = v29->m128_u32[v49 + 1];
      v32 = (char *)v55[11] + v47;
      v33 = (__m128 *)((char *)v55[9] + v31);
      v34 = (__m128 *)((char *)v55[9] + v30);
      v35 = _mm_shuffle_ps((__m128)*(unsigned int *)&v32[v25 + 16], (__m128)*(unsigned int *)&v32[v25 + 16], 0);
      v36 = &v55[7][2 * v22 + 2 * v48];
      v37 = _mm_add_ps(
              _mm_mul_ps(
                _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v34[2], v34[5]), *v36), _mm_mul_ps(_mm_sub_ps(v33[2], v33[5]), v36[1])),
                _mm_shuffle_ps((__m128)*(unsigned int *)&v32[v25 + 20], (__m128)*(unsigned int *)&v32[v25 + 20], 0)),
              _mm_mul_ps(
                _mm_add_ps(_mm_mul_ps(v34[5], *v36), _mm_mul_ps(v33[5], v36[1])),
                _mm_mul_ps(_mm_shuffle_ps((*v55)[4], (*v55)[4], 0), v35)));
      v38 = _mm_and_ps(v23.m_quad, *v27);
      v39 = (float)(_mm_shuffle_ps(v36[1], v36[1], 255).m128_f32[0] * v35.m128_f32[0])
          - (float)((float)(_mm_shuffle_ps(v37, v37, 85).m128_f32[0] + _mm_shuffle_ps(v37, v37, 0).m128_f32[0])
                  + _mm_shuffle_ps(v37, v37, 170).m128_f32[0]);
      v40 = _mm_or_ps(_mm_shuffle_ps(v38, v38, 78), v38);
      LODWORD(v41) = _mm_shuffle_ps(v40, v40, 177).m128_u32[0] | v40.m128_i32[0];
      if ( v28 == 3 )
      {
        if ( v41 > v39 )
          goto LABEL_13;
      }
      else if ( v28 != 1 || v41 < v39 )
      {
        goto LABEL_13;
      }
      LODWORD(v43) = (unsigned int)(2 * COERCE_INT(v41 - v39)) >> 1;
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
    --v49;
    v48 -= 3i64;
    v16 = v46 - 1;
    p_m_quad = (__m128 *)(out.m_lin.m_quad.m128_u64[1] - 32);
    v17 = out.m_lin.m_quad.m128_u64[0] - 64;
    --v12;
    --v46;
    out.m_lin.m_quad.m128_u64[1] -= 32i64;
    out.m_lin.m_quad.m128_u64[0] -= 64i64;
    if ( v12 >= 0 )
    {
      m_quad = b.m_ang.m_quad;
      v14 = b.m_lin.m_quad;
      v6 = v55;
      continue;
    }
    break;
  }
  if ( v10 >= 0 )
  {
    v44 = &v55[11][4 * (__int64)v10];
    v44->m128_i8[0] &= ~(3 << (2 * v42));
    *v56 = v10;
    *v57 = v42;
  }
}

