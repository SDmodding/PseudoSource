// File Line: 183
// RVA: 0xDDF410
void __fastcall hkDebugPrintfAccumulators(
        int step,
        hkpSolverInfo *info,
        hkpVelocityAccumulator *accumulators,
        hkpVelocityAccumulator *accumulatorsEnd)
{
  ;
}

// File Line: 188
// RVA: 0xDDF420
void __fastcall hkSolver_solveStiffSpringChain(
        hkpSolverInfo *info,
        hkSolverStepTemp *temp,
        hkpVelocityAccumulator *accums,
        hkpJacobianStiffSpringChainSchema *chain,
        hkpSolverElemTemp *sr)
{
  __int64 m_numConstraints; // rdx
  hkpJacobianStiffSpringChainSchema *v6; // r10
  unsigned __int16 *p_m_numConstraints; // r11
  float *v10; // rbx
  unsigned __int16 *v11; // rsi
  float *v12; // r14
  __m128 m_tau_low; // xmm9
  __m128 m_damping_low; // xmm10
  __int64 v15; // r9
  __m128 v16; // xmm9
  __m128 v17; // xmm10
  float *v18; // r15
  __m128 *v19; // rbp
  signed __int64 v20; // r8
  __m128 v21; // xmm8
  __m128 v22; // xmm3
  __int64 v23; // rax
  __m128 *v24; // rcx
  __m128 *v25; // rax
  __m128 v26; // xmm7
  int v27; // r9d
  float v28; // xmm6_4
  float *v29; // r8
  __m128 *v30; // rdx
  hkpSolverElemTemp *v31; // r10
  float *v32; // rbx
  signed __int64 v33; // r11
  float v34; // xmm0_4
  float v35; // xmm6_4
  __m128 *v36; // rax
  __m128 *v37; // rcx
  float v38; // xmm0_4
  __m128 v39; // xmm5
  __m128 v40; // xmm3
  __m128 v41; // xmm4
  __m128 v42; // xmm1
  __m128 v43; // xmm0
  __m128 v44; // xmm1
  __m128 v45; // xmm0

  m_numConstraints = chain->m_numConstraints;
  v6 = chain + 1;
  p_m_numConstraints = &chain[2 * m_numConstraints + 1].m_numConstraints;
  v10 = &chain[1].m_typeBuffer + 12 * m_numConstraints;
  v11 = &chain[1].m_numConstraints + 30 * m_numConstraints;
  v12 = (float *)(v11 - 2);
  *((_DWORD *)v11 - 1) = 0;
  m_tau_low = (__m128)LODWORD(chain->m_tau);
  m_damping_low = (__m128)LODWORD(chain->m_damping);
  v15 = (int)m_numConstraints;
  v16 = _mm_shuffle_ps(m_tau_low, m_tau_low, 0);
  v17 = _mm_shuffle_ps(m_damping_low, m_damping_low, 0);
  if ( (int)m_numConstraints > 0 )
  {
    v18 = v10;
    v19 = (__m128 *)v6;
    v20 = (char *)p_m_numConstraints - (char *)v11;
    do
    {
      v21 = *v19;
      v22 = v19[2];
      v23 = *(unsigned int *)((char *)v12 + v20 + 8);
      v24 = (__m128 *)(&accums->m_type.m_storage + *(unsigned int *)((char *)v12++ + v20 + 4));
      v25 = (__m128 *)(&accums->m_type.m_storage + v23);
      v19 += 3;
      v18 += 3;
      v26 = _mm_add_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_sub_ps(v25[2], v25[5]), v22),
                    _mm_mul_ps(_mm_sub_ps(v24[2], v24[5]), v19[-2])),
                  _mm_mul_ps(_mm_sub_ps(_mm_sub_ps(v24[1], v24[4]), _mm_sub_ps(v25[1], v25[4])), v21)),
                v17),
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_mul_ps(v24[5], v19[-2]), _mm_mul_ps(v22, v25[5])),
                  _mm_mul_ps(_mm_sub_ps(v24[4], v25[4]), v21)),
                _mm_mul_ps(
                  _mm_shuffle_ps(
                    info->m_invIntegrateVelocityFactor.m_quad,
                    info->m_invIntegrateVelocityFactor.m_quad,
                    0),
                  v16)));
      *v12 = (float)((float)((float)(_mm_shuffle_ps(v21, v21, 255).m128_f32[0] * v16.m128_f32[0])
                           - (float)((float)(_mm_shuffle_ps(v26, v26, 85).m128_f32[0]
                                           + _mm_shuffle_ps(v26, v26, 0).m128_f32[0])
                                   + _mm_shuffle_ps(v26, v26, 170).m128_f32[0]))
                   - (float)(*(v12 - 1) * *(v18 - 3)))
           / *(v18 - 2);
      --v15;
    }
    while ( v15 );
  }
  v27 = m_numConstraints - 1;
  v28 = 0.0;
  if ( (int)m_numConstraints - 1 >= 0 )
  {
    v29 = (float *)&v11[2 * v27];
    v30 = (__m128 *)v6 + 3 * v27;
    v31 = &sr[v27];
    v32 = &v10[3 * v27 + 2];
    v33 = (char *)p_m_numConstraints - (char *)v11;
    do
    {
      v34 = v28;
      v35 = *v29;
      v36 = (__m128 *)(&accums->m_type.m_storage + *(unsigned int *)((char *)v29 + v33));
      v37 = (__m128 *)(&accums->m_type.m_storage + *(unsigned int *)((char *)v29 + v33 + 4));
      v38 = v34 * *v32;
      --v31;
      v32 -= 3;
      --v29;
      v28 = v35 - v38;
      v30 -= 3;
      --v27;
      v39 = _mm_shuffle_ps((__m128)LODWORD(v28), (__m128)LODWORD(v28), 0);
      v40 = _mm_mul_ps(v36[3], v39);
      v41 = _mm_mul_ps(v37[3], v39);
      v42 = _mm_mul_ps(_mm_shuffle_ps(v41, v41, 255), v30[3]);
      v36[1] = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v40, v40, 255), v30[3]), v36[1]);
      v43 = _mm_sub_ps(v37[1], v42);
      v44 = v30[5];
      v37[1] = v43;
      v45 = _mm_add_ps(_mm_mul_ps(v30[4], v40), v36[2]);
      v37[2] = _mm_add_ps(_mm_mul_ps(v44, v41), v37[2]);
      v36[2] = v45;
      v31[1].m_impulseApplied = _mm_shuffle_ps(
                                  (__m128)LODWORD(v31[1].m_impulseApplied),
                                  (__m128)LODWORD(v31[1].m_impulseApplied),
                                  0).m128_f32[0]
                              + v39.m128_f32[0];
    }
    while ( v27 >= 0 );
  }
}

// File Line: 233
// RVA: 0xDDF6E0
void __fastcall hkSolver_solveBallAndSocketChain(
        hkpSolverInfo *info,
        hkSolverStepTemp *temp,
        hkpVelocityAccumulator *accums,
        hkpJacobianBallSocketChainSchema *chain,
        hkpSolverElemTemp *sr)
{
  __int64 m_numConstraints; // rbx
  __m128 v7; // xmm5
  __int64 v8; // r10
  hkpJacobianBallSocketChainSchema *v9; // r15
  __int64 v10; // r11
  __int64 v11; // r13
  char *v12; // rbp
  char *v13; // rdx
  char *v14; // r8
  __m128 *v15; // rdi
  __m128 *v16; // r10
  __m128 *p_m_damping; // rsi
  char *v18; // r12
  __m128 v19; // xmm13
  __m128 v20; // xmm7
  __m128 *v21; // rax
  __m128 *v22; // rcx
  __m128 v23; // xmm15
  __m128 v24; // xmm12
  __m128 v25; // xmm14
  __m128 v26; // xmm2
  __m128 v27; // xmm4
  __m128 v28; // xmm5
  __m128 v29; // xmm10
  __m128 v30; // xmm9
  __m128 v31; // xmm3
  __m128 v32; // xmm8
  __m128 v33; // xmm14
  __m128 v34; // xmm6
  __m128 v35; // xmm4
  __m128 v36; // xmm11
  __m128 v37; // xmm11
  int v38; // r10d
  char *v39; // rdi
  char *v40; // rbx
  __m128 v41; // xmm6
  __m128 v42; // xmm7
  __m128 v43; // xmm5
  hkpSolverElemTemp *v44; // rsi
  __m128 *v45; // r11
  __int64 v46; // rdx
  hkpSolverElemTemp *v47; // rbp
  __m128 *v48; // rbx
  hkpSolverElemTemp *v49; // r8
  __m128 *v50; // rax
  __m128 *v51; // rcx
  __m128 *v52; // rdx
  __m128 v53; // xmm5
  __m128 v54; // xmm4
  __m128 v55; // xmm3
  __m128 v56; // xmm1
  __m128 v57; // xmm0
  __m128 v58; // xmm1
  __m128 v59; // xmm0
  __m128 v60; // xmm4
  __m128 v61; // xmm3
  __m128 v62; // xmm1
  __m128 v63; // xmm4
  __m128 v64; // xmm1
  __m128 v65; // xmm0
  __m128 v66; // xmm3
  __m128 v67; // xmm4
  __m128 v68; // xmm1
  __m128 v69; // xmm0

  m_numConstraints = chain->m_numConstraints;
  v7 = 0i64;
  v8 = 3 * (int)m_numConstraints;
  v9 = chain + 1;
  v10 = m_numConstraints + v8 + 2 * m_numConstraints;
  v11 = 0i64;
  v12 = (char *)chain + 48 * v8;
  v13 = (char *)(&chain[1].m_damping + 12 * v10);
  v14 = (char *)(&chain[1].m_damping + 12 * v10 + 4 * (int)m_numConstraints);
  v15 = (__m128 *)&chain[1];
  v16 = (__m128 *)(v13 - 16);
  *((_OWORD *)v13 - 1) = 0i64;
  if ( (int)m_numConstraints > 0 )
  {
    p_m_damping = (__m128 *)&chain[4].m_damping;
    v18 = v12 + 112;
    do
    {
      v19 = p_m_damping[-1];
      v20 = p_m_damping[-4];
      v21 = (__m128 *)(&accums->m_type.m_storage + *(unsigned int *)&v14[4 * v11]);
      v22 = (__m128 *)(&accums->m_type.m_storage + *(unsigned int *)&v14[4 * v11 + 4]);
      v23 = _mm_shuffle_ps((__m128)LODWORD(chain->m_tau), (__m128)LODWORD(chain->m_tau), 0);
      v24 = _mm_shuffle_ps((__m128)LODWORD(chain->m_damping), (__m128)LODWORD(chain->m_damping), 0);
      v25 = v22[5];
      v26 = v21[5];
      v27 = v21[4];
      v28 = _mm_mul_ps(
              _mm_shuffle_ps(info->m_invIntegrateVelocityFactor.m_quad, info->m_invIntegrateVelocityFactor.m_quad, 0),
              v23);
      v29 = _mm_sub_ps(v21[2], v26);
      v30 = _mm_sub_ps(v22[2], v25);
      v31 = *v16;
      v32 = _mm_sub_ps(_mm_sub_ps(v21[1], v27), _mm_sub_ps(v22[1], v22[4]));
      v33 = _mm_add_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_mul_ps(v25, p_m_damping[1]), _mm_mul_ps(v26, *p_m_damping)),
                  _mm_mul_ps(_mm_sub_ps(v27, v22[4]), v19)),
                v28),
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_mul_ps(v30, p_m_damping[1]), _mm_mul_ps(v29, *p_m_damping)),
                  _mm_mul_ps(v32, v19)),
                v24));
      v34 = _mm_add_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_mul_ps(v22[5], p_m_damping[-2]), _mm_mul_ps(v26, p_m_damping[-3])),
                  _mm_mul_ps(_mm_sub_ps(v27, v22[4]), v20)),
                v28),
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_mul_ps(v29, p_m_damping[-3]), _mm_mul_ps(v30, p_m_damping[-2])),
                  _mm_mul_ps(v32, v20)),
                v24));
      v35 = _mm_add_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_mul_ps(v26, p_m_damping[-6]), _mm_mul_ps(v22[5], p_m_damping[-5])),
                  _mm_mul_ps(_mm_sub_ps(v27, v22[4]), *v15)),
                v28),
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_mul_ps(v29, p_m_damping[-6]), _mm_mul_ps(v30, p_m_damping[-5])),
                  _mm_mul_ps(v32, *v15)),
                v24));
      v36 = _mm_mul_ps(_mm_shuffle_ps(*v15, *v15, 255), v23);
      ++v11;
      ++v16;
      v15 += 9;
      p_m_damping += 9;
      v18 += 144;
      v37 = _mm_sub_ps(
              _mm_movelh_ps(
                _mm_unpacklo_ps(
                  _mm_sub_ps(
                    v36,
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v35, v35, 85), _mm_shuffle_ps(v35, v35, 0)),
                      _mm_shuffle_ps(v35, v35, 170))),
                  _mm_sub_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v20, v20, 255), v23),
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v34, v34, 85), _mm_shuffle_ps(v34, v34, 0)),
                      _mm_shuffle_ps(v34, v34, 170)))),
                _mm_unpacklo_ps(
                  _mm_sub_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v19, v19, 255), v23),
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v33, v33, 85), _mm_shuffle_ps(v33, v33, 0)),
                      _mm_shuffle_ps(v33, v33, 170))),
                  aabbOut.m_quad)),
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v31, v31, 85), *((__m128 *)v18 - 13)),
                  _mm_mul_ps(_mm_shuffle_ps(v31, v31, 0), *((__m128 *)v18 - 14))),
                _mm_mul_ps(_mm_shuffle_ps(v31, v31, 170), *((__m128 *)v18 - 12))));
      *v16 = _mm_add_ps(
               _mm_add_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v37, v37, 85), *((__m128 *)v18 - 10)),
                 _mm_mul_ps(_mm_shuffle_ps(v37, v37, 0), *((__m128 *)v18 - 11))),
               _mm_mul_ps(_mm_shuffle_ps(v37, v37, 170), *((__m128 *)v18 - 9)));
    }
    while ( v11 < (int)m_numConstraints );
    v9 = chain + 1;
    v7 = 0i64;
  }
  v38 = m_numConstraints - 1;
  if ( (int)m_numConstraints - 1 >= 0 )
  {
    v39 = &v14[4 * v38];
    v40 = v12 + 160;
    v41 = _mm_shuffle_ps(v7, v7, 85);
    v42 = _mm_shuffle_ps(v7, v7, 0);
    v43 = _mm_shuffle_ps(v7, v7, 170);
    v44 = &sr[3 * v38];
    v45 = (__m128 *)&v13[16 * v38];
    v46 = 144i64 * v38;
    v47 = &sr[3 * v38 + 2];
    v48 = (__m128 *)&v40[v46];
    v49 = &sr[3 * v38 + 1];
    v50 = (__m128 *)((char *)&v9[2].m_damping + v46);
    do
    {
      v51 = (__m128 *)(&accums->m_type.m_storage + *(unsigned int *)v39);
      v52 = (__m128 *)(&accums->m_type.m_storage + *((unsigned int *)v39 + 1));
      v53 = _mm_sub_ps(
              *v45,
              _mm_add_ps(_mm_add_ps(_mm_mul_ps(v48[-2], v42), _mm_mul_ps(v48[-1], v41)), _mm_mul_ps(*v48, v43)));
      v42 = _mm_shuffle_ps(v53, v53, 0);
      v41 = _mm_shuffle_ps(v53, v53, 85);
      v43 = _mm_shuffle_ps(v53, v53, 170);
      v54 = _mm_mul_ps(v42, v52[3]);
      v55 = _mm_mul_ps(v42, v51[3]);
      v56 = _mm_mul_ps(_mm_shuffle_ps(v54, v54, 255), v50[-5]);
      v51[1] = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v55, v55, 255), v50[-5]), v51[1]);
      v57 = _mm_sub_ps(v52[1], v56);
      v58 = v50[-3];
      v52[1] = v57;
      v59 = _mm_add_ps(_mm_mul_ps(v50[-4], v55), v51[2]);
      v52[2] = _mm_add_ps(_mm_mul_ps(v58, v54), v52[2]);
      v60 = _mm_mul_ps(v41, v52[3]);
      v51[2] = v59;
      v61 = _mm_mul_ps(v41, v51[3]);
      v62 = _mm_shuffle_ps(v60, v60, 255);
      v44->m_impulseApplied = _mm_shuffle_ps(
                                (__m128)LODWORD(v44->m_impulseApplied),
                                (__m128)LODWORD(v44->m_impulseApplied),
                                0).m128_f32[0]
                            + v42.m128_f32[0];
      v63 = _mm_mul_ps(v60, *v50);
      v64 = _mm_mul_ps(v62, v50[-2]);
      v51[1] = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v61, v61, 255), v50[-2]), v51[1]);
      v52[1] = _mm_sub_ps(v52[1], v64);
      v65 = _mm_mul_ps(v50[-1], v61);
      v52[2] = _mm_add_ps(v63, v52[2]);
      v51[2] = _mm_add_ps(v65, v51[2]);
      v66 = _mm_mul_ps(v43, v51[3]);
      v67 = _mm_mul_ps(v43, v52[3]);
      v49->m_impulseApplied = _mm_shuffle_ps(
                                (__m128)LODWORD(v49->m_impulseApplied),
                                (__m128)LODWORD(v49->m_impulseApplied),
                                0).m128_f32[0]
                            + v41.m128_f32[0];
      v51[1] = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v66, v66, 255), v50[1]), v51[1]);
      v47 -= 3;
      v44 -= 3;
      v49 -= 3;
      v39 -= 4;
      v50 -= 9;
      v48 -= 9;
      --v45;
      --v38;
      v68 = _mm_mul_ps(v50[12], v67);
      v52[1] = _mm_sub_ps(v52[1], _mm_mul_ps(_mm_shuffle_ps(v67, v67, 255), v50[10]));
      v69 = _mm_add_ps(_mm_mul_ps(v50[11], v66), v51[2]);
      v52[2] = _mm_add_ps(v68, v52[2]);
      v51[2] = v69;
      v47[3].m_impulseApplied = _mm_shuffle_ps(
                                  (__m128)LODWORD(v47[3].m_impulseApplied),
                                  (__m128)LODWORD(v47[3].m_impulseApplied),
                                  0).m128_f32[0]
                              + v43.m128_f32[0];
    }
    while ( v38 >= 0 );
  }
}

// File Line: 298
// RVA: 0xDDFCB0
void __fastcall hkSolver_solvePoweredChain(
        hkpSolverInfo *solverInfo,
        hkSolverStepTemp *temp,
        hkpVelocityAccumulator *accums,
        hkpJacobianPoweredChainSchema *chain,
        hkpSolverElemTemp *sr)
{
  __int64 m_numConstraints; // r10
  __m128 m_tau_low; // xmm0
  __m128 m_damping_low; // xmm1
  __int64 v9; // r8
  int v10; // r14d
  __int64 v11; // r12
  __int64 v12; // r15
  int v13; // esi
  __int64 v14; // rdi
  int i; // ebx
  char v16; // dl
  int j; // eax
  int k; // eax
  __m128 v19; // xmm6
  int v20; // r9d
  __int64 v21; // rsi
  __int64 v22; // rdi
  __m128 v23; // xmm9
  hkVector8f *v24; // rbx
  __int64 v25; // r11
  __m128 v26; // xmm8
  __m128 v27; // xmm7
  __m128 v28; // xmm11
  hkpSolverElemTemp *v29; // r14
  __int64 v30; // r10
  __m128 v31; // xmm10
  hkpSolverElemTemp *v32; // r12
  hkpSolverElemTemp *v33; // r15
  hkpSolverElemTemp *v34; // r8
  __m128 v35; // xmm3
  __m128 v36; // xmm7
  hkp1Lin2AngJacobian *m_storage; // rax
  __m128 *v38; // rcx
  __m128 *v39; // rdx
  __m128 v40; // xmm4
  __m128 v41; // xmm6
  __m128 v42; // xmm3
  __m128 v43; // xmm1
  __m128 v44; // xmm0
  __m128 v45; // xmm1
  __m128 v46; // xmm0
  __m128 v47; // xmm4
  __m128 v48; // xmm3
  hkp1Lin2AngJacobian *v49; // rax
  __m128 v50; // xmm1
  __m128 v51; // xmm0
  __m128 v52; // xmm1
  __m128 v53; // xmm0
  __m128 v54; // xmm4
  __m128 v55; // xmm3
  hkp1Lin2AngJacobian *v56; // rax
  __m128 v57; // xmm1
  __m128 v58; // xmm0
  __m128 v59; // xmm1
  __m128 v60; // xmm0
  __m128 v61; // xmm1
  __m128 v62; // xmm1
  __m128 v63; // xmm1
  __m128 v64; // xmm1
  hkpSolverElemTemp *v65; // rax
  __m128 v66; // xmm1
  __m128 v67; // xmm0
  __m128 v68; // xmm1
  hkpSolverElemTemp *v69; // rax
  __m128 v70; // xmm1
  hkpChainSolverInfo info; // [rsp+30h] [rbp-B1h] BYREF
  hkpSolverElemTemp *modifiedConstraintIndex; // [rsp+140h] [rbp+5Fh] BYREF
  hkpSolverElemTemp *modifiedCoordinateIndex; // [rsp+150h] [rbp+6Fh] BYREF
  float impulse; // [rsp+158h] [rbp+77h] BYREF

  m_numConstraints = chain->m_numConstraints;
  m_tau_low = (__m128)LODWORD(chain->m_tau);
  m_damping_low = (__m128)LODWORD(chain->m_damping);
  info.m_solverInfo = solverInfo;
  info.m_j.m_storage = (hkp1Lin2AngJacobian *)&chain[1];
  info.m_schemaTau.m_real = _mm_shuffle_ps(m_tau_low, m_tau_low, 0);
  info.m_schemaDamping.m_real = _mm_shuffle_ps(m_damping_low, m_damping_low, 0);
  v9 = 3 * (int)m_numConstraints;
  info.m_numConstraints.m_storage = m_numConstraints;
  info.m_accumsBase.m_storage = accums;
  info.m_jAng.m_storage = (hkp2AngJacobian *)((char *)&chain[1] + 48 * v9);
  info.m_va.m_storage = (hkpVelocityAccumulatorOffset *)&chain[32 * (unsigned __int64)(unsigned int)m_numConstraints + 2]
                      + 20 * v9;
  info.m_triples.m_storage = (hkpConstraintChainMatrix6Triple *)((char *)&chain[1] + 80 * v9);
  info.m_motorsState.m_storage = (hkp3dAngularMotorSolverInfo *)(&chain[2].m_numConstraints
                                                               + 514 * (unsigned int)m_numConstraints
                                                               + 40 * v9);
  info.m_velocitiesBuffer.m_storage = (hkVector8f *)((char *)&chain[31 * m_numConstraints + 2] + 80 * v9);
  info.m_gTempBuffer.m_storage = (hkVector8f *)((char *)&chain[30 * m_numConstraints + 1] + 80 * v9);
  hkPoweredChain_CalculateVelocities(temp, &info, info.m_velocitiesBuffer.m_storage);
  v10 = 0;
  if ( info.m_numConstraints.m_storage > 0 )
  {
    v11 = 0i64;
    v12 = 4i64;
    do
    {
      v13 = 0;
      v14 = 0i64;
      for ( i = 0; i < 6; i += 2 )
      {
        v16 = ((unsigned __int8)info.m_motorsState.m_storage[v11].m_broken >> i) & 3;
        if ( v16 == 2 )
        {
          info.m_velocitiesBuffer.m_storage->m_lin.m_quad.m128_i32[v12 + v14] = 0;
        }
        else if ( v16 )
        {
          hkPoweredChain_OverwriteVelocityWithExplicitImpulse(
            v10,
            v13,
            info.m_motorsState.m_storage,
            info.m_velocitiesBuffer.m_storage);
        }
        ++v13;
        ++v14;
      }
      ++v10;
      ++v11;
      v12 += 8i64;
    }
    while ( v10 < info.m_numConstraints.m_storage );
  }
  hkPoweredChain_SolveConstraintMatrix_ComputeVectorG(&info, info.m_gTempBuffer.m_storage);
  LODWORD(modifiedConstraintIndex) = -1;
  LODWORD(modifiedCoordinateIndex) = -1;
  impulse = 0.0;
  hkPoweredChain_ScanAndEnableMotors(
    &info,
    (int *)&modifiedConstraintIndex,
    (int *)&modifiedCoordinateIndex,
    &impulse,
    info.m_motorsState.m_storage);
  for ( j = (int)modifiedConstraintIndex; (int)modifiedConstraintIndex >= 0; j = (int)modifiedConstraintIndex )
  {
    hkPoweredChain_UpdateLuDecomposition(
      j,
      info.m_numConstraints.m_storage,
      info.m_motorsState.m_storage,
      info.m_triples.m_storage);
    hkPoweredChain_RestoreVelocityValue(
      (int)modifiedConstraintIndex,
      (int)modifiedCoordinateIndex,
      &info,
      info.m_velocitiesBuffer.m_storage);
    hkPoweredChain_SolveConstraintMatrix_ComputeVectorG(&info, info.m_gTempBuffer.m_storage);
    LODWORD(modifiedConstraintIndex) = -1;
    LODWORD(modifiedCoordinateIndex) = -1;
    impulse = 0.0;
    hkPoweredChain_ScanAndEnableMotors(
      &info,
      (int *)&modifiedConstraintIndex,
      (int *)&modifiedCoordinateIndex,
      &impulse,
      info.m_motorsState.m_storage);
  }
  hkPoweredChain_SolveConstraintMatrix_ComputeVectorG(&info, info.m_gTempBuffer.m_storage);
  LODWORD(modifiedConstraintIndex) = -1;
  LODWORD(modifiedCoordinateIndex) = -1;
  impulse = 0.0;
  hkPoweredChain_ScanAndDisableMotors(
    &info,
    (int *)&modifiedConstraintIndex,
    (int *)&modifiedCoordinateIndex,
    &impulse,
    info.m_motorsState.m_storage);
  for ( k = (int)modifiedConstraintIndex; (int)modifiedConstraintIndex >= 0; k = (int)modifiedConstraintIndex )
  {
    hkPoweredChain_UpdateLuDecomposition(
      k,
      info.m_numConstraints.m_storage,
      info.m_motorsState.m_storage,
      info.m_triples.m_storage);
    hkPoweredChain_OverwriteVelocityWithExplicitImpulse(
      (int)modifiedConstraintIndex,
      (int)modifiedCoordinateIndex,
      info.m_motorsState.m_storage,
      info.m_velocitiesBuffer.m_storage);
    hkPoweredChain_SolveConstraintMatrix_ComputeVectorG(&info, info.m_gTempBuffer.m_storage);
    LODWORD(modifiedConstraintIndex) = -1;
    LODWORD(modifiedCoordinateIndex) = -1;
    impulse = 0.0;
    hkPoweredChain_ScanAndDisableMotors(
      &info,
      (int *)&modifiedConstraintIndex,
      (int *)&modifiedCoordinateIndex,
      &impulse,
      info.m_motorsState.m_storage);
  }
  v19 = 0i64;
  v20 = info.m_numConstraints.m_storage - 1;
  if ( info.m_numConstraints.m_storage - 1 >= 0 )
  {
    v21 = v20;
    v22 = v20;
    v23 = _mm_shuffle_ps((__m128)0i64, (__m128)0i64, 85);
    v24 = &info.m_gTempBuffer.m_storage[v20 + 1];
    v25 = 96i64 * v20 + 64;
    v26 = _mm_shuffle_ps((__m128)0i64, (__m128)0i64, 0);
    v27 = _mm_shuffle_ps((__m128)0i64, (__m128)0i64, 170);
    v28 = v23;
    v29 = &sr[6 * v20];
    v30 = 144i64 * v20 + 96;
    v31 = v26;
    modifiedCoordinateIndex = &sr[6 * v20 + 5];
    modifiedConstraintIndex = &sr[6 * v20 + 4];
    v32 = &sr[6 * v20 + 3];
    v33 = &sr[6 * v20 + 2];
    v34 = &sr[6 * v20 + 1];
    do
    {
      v35 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(info.m_triples.m_storage[v22].m_upper.m_m[1][0].m_col1.m_quad, v23),
                _mm_mul_ps(v26, info.m_triples.m_storage[v22].m_upper.m_m[1][0].m_col0.m_quad)),
              _mm_mul_ps(info.m_triples.m_storage[v22].m_upper.m_m[1][0].m_col2.m_quad, v27));
      v36 = _mm_sub_ps(
              v24->m_lin.m_quad,
              _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(info.m_triples.m_storage[v22].m_upper.m_m[0][1].m_col1.m_quad, v28),
                    _mm_mul_ps(info.m_triples.m_storage[v22].m_upper.m_m[0][1].m_col0.m_quad, v31)),
                  _mm_mul_ps(info.m_triples.m_storage[v22].m_upper.m_m[0][1].m_col2.m_quad, v19)),
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(info.m_triples.m_storage[v22].m_upper.m_m[0][0].m_col1.m_quad, v23),
                    _mm_mul_ps(v26, info.m_triples.m_storage[v22].m_upper.m_m[0][0].m_col0.m_quad)),
                  _mm_mul_ps(info.m_triples.m_storage[v22].m_upper.m_m[0][0].m_col2.m_quad, v27))));
      m_storage = info.m_j.m_storage;
      v38 = (__m128 *)(&accums->m_type.m_storage + info.m_va.m_storage[v21].m_offset);
      v39 = (__m128 *)(&accums->m_type.m_storage + info.m_va.m_storage[v21 + 1].m_offset);
      v26 = _mm_shuffle_ps(v36, v36, 0);
      v23 = _mm_shuffle_ps(v36, v36, 85);
      v40 = _mm_mul_ps(v26, v39[3]);
      v41 = _mm_sub_ps(
              v24->m_ang.m_quad,
              _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(info.m_triples.m_storage[v22].m_upper.m_m[1][1].m_col1.m_quad, v28),
                    _mm_mul_ps(info.m_triples.m_storage[v22].m_upper.m_m[1][1].m_col0.m_quad, v31)),
                  _mm_mul_ps(info.m_triples.m_storage[v22].m_upper.m_m[1][1].m_col2.m_quad, v19)),
                v35));
      v42 = _mm_mul_ps(v26, v38[3]);
      v43 = _mm_mul_ps(
              _mm_shuffle_ps(v40, v40, 255),
              *(__m128 *)((char *)&info.m_j.m_storage[-2].m_linear0.m_quad + v30));
      v38[1] = _mm_add_ps(
                 _mm_mul_ps(
                   _mm_shuffle_ps(v42, v42, 255),
                   *(__m128 *)((char *)&info.m_j.m_storage[-2].m_linear0.m_quad + v30)),
                 v38[1]);
      v44 = _mm_sub_ps(v39[1], v43);
      v45 = *(__m128 *)((char *)&m_storage[-1] + v30 - 16);
      v39[1] = v44;
      v46 = _mm_add_ps(_mm_mul_ps(*(__m128 *)((char *)&m_storage[-1] + v30 - 32), v42), v38[2]);
      v39[2] = _mm_add_ps(_mm_mul_ps(v45, v40), v39[2]);
      v47 = _mm_mul_ps(v23, v39[3]);
      v38[2] = v46;
      v48 = _mm_mul_ps(v23, v38[3]);
      v29->m_impulseApplied = _mm_shuffle_ps(
                                (__m128)LODWORD(v29->m_impulseApplied),
                                (__m128)LODWORD(v29->m_impulseApplied),
                                0).m128_f32[0]
                            + v26.m128_f32[0];
      v49 = info.m_j.m_storage;
      v27 = _mm_shuffle_ps(v36, v36, 170);
      v31 = _mm_shuffle_ps(v41, v41, 0);
      v50 = _mm_mul_ps(
              _mm_shuffle_ps(v47, v47, 255),
              *(__m128 *)((char *)&info.m_j.m_storage[-1].m_linear0.m_quad + v30));
      v28 = _mm_shuffle_ps(v41, v41, 85);
      v38[1] = _mm_add_ps(
                 _mm_mul_ps(
                   _mm_shuffle_ps(v48, v48, 255),
                   *(__m128 *)((char *)&info.m_j.m_storage[-1].m_linear0.m_quad + v30)),
                 v38[1]);
      v51 = _mm_sub_ps(v39[1], v50);
      v52 = _mm_mul_ps(*(__m128 *)((char *)&v49->m_linear0.m_quad + v30 - 16), v47);
      v39[1] = v51;
      v53 = _mm_add_ps(_mm_mul_ps(*(__m128 *)((char *)&v49->m_linear0.m_quad + v30 - 32), v48), v38[2]);
      v39[2] = _mm_add_ps(v52, v39[2]);
      v54 = _mm_mul_ps(v27, v39[3]);
      v38[2] = v53;
      v55 = _mm_mul_ps(v27, v38[3]);
      v34->m_impulseApplied = _mm_shuffle_ps(
                                (__m128)LODWORD(v34->m_impulseApplied),
                                (__m128)LODWORD(v34->m_impulseApplied),
                                0).m128_f32[0]
                            + v23.m128_f32[0];
      v56 = info.m_j.m_storage;
      v57 = _mm_mul_ps(_mm_shuffle_ps(v54, v54, 255), *(__m128 *)((char *)&info.m_j.m_storage->m_linear0.m_quad + v30));
      v38[1] = _mm_add_ps(
                 _mm_mul_ps(
                   _mm_shuffle_ps(v55, v55, 255),
                   *(__m128 *)((char *)&info.m_j.m_storage->m_linear0.m_quad + v30)),
                 v38[1]);
      v58 = _mm_sub_ps(v39[1], v57);
      v59 = *(__m128 *)((char *)&v56->m_angular[1].m_quad + v30);
      v39[1] = v58;
      v60 = _mm_add_ps(_mm_mul_ps(*(__m128 *)((char *)&v56->m_angular[0].m_quad + v30), v55), v38[2]);
      v39[2] = _mm_add_ps(_mm_mul_ps(v59, v54), v39[2]);
      v61 = _mm_mul_ps(v31, v39[3]);
      v38[2] = v60;
      v33->m_impulseApplied = _mm_shuffle_ps(
                                (__m128)LODWORD(v33->m_impulseApplied),
                                (__m128)LODWORD(v33->m_impulseApplied),
                                0).m128_f32[0]
                            + v27.m128_f32[0];
      v62 = _mm_add_ps(_mm_mul_ps(v61, *(__m128 *)((char *)&info.m_jAng.m_storage[-1] + v25 - 16)), v39[2]);
      v38[2] = _mm_add_ps(
                 _mm_mul_ps(
                   _mm_mul_ps(v31, v38[3]),
                   *(__m128 *)((char *)&info.m_jAng.m_storage[-2].m_angular[0].m_quad + v25)),
                 v38[2]);
      v39[2] = v62;
      v63 = _mm_mul_ps(v28, v39[3]);
      v32->m_impulseApplied = _mm_shuffle_ps(
                                (__m128)LODWORD(v32->m_impulseApplied),
                                (__m128)LODWORD(v32->m_impulseApplied),
                                0).m128_f32[0]
                            + v31.m128_f32[0];
      v64 = _mm_add_ps(_mm_mul_ps(v63, *(__m128 *)((char *)&info.m_jAng.m_storage->m_angular[-1].m_quad + v25)), v39[2]);
      v38[2] = _mm_add_ps(
                 _mm_mul_ps(
                   _mm_mul_ps(v28, v38[3]),
                   *(__m128 *)((char *)&info.m_jAng.m_storage[-1].m_angular[0].m_quad + v25)),
                 v38[2]);
      v39[2] = v64;
      v65 = modifiedConstraintIndex;
      modifiedConstraintIndex -= 6;
      v19 = _mm_shuffle_ps(v41, v41, 170);
      v29 -= 6;
      v34 -= 6;
      v33 -= 6;
      v32 -= 6;
      v30 -= 144i64;
      v25 -= 96i64;
      v66 = _mm_mul_ps(v19, v39[3]);
      --v22;
      --v24;
      --v21;
      v65->m_impulseApplied = _mm_shuffle_ps(
                                (__m128)LODWORD(v65->m_impulseApplied),
                                (__m128)LODWORD(v65->m_impulseApplied),
                                0).m128_f32[0]
                            + v28.m128_f32[0];
      v67 = _mm_mul_ps(
              _mm_mul_ps(v19, v38[3]),
              *(__m128 *)((char *)&info.m_jAng.m_storage[3].m_angular[0].m_quad + v25));
      v68 = _mm_mul_ps(v66, *(__m128 *)((char *)&info.m_jAng.m_storage[3].m_angular[1].m_quad + v25));
      --v20;
      modifiedCoordinateIndex -= 6;
      v69 = modifiedCoordinateIndex;
      v70 = _mm_add_ps(v68, v39[2]);
      v38[2] = _mm_add_ps(v67, v38[2]);
      v39[2] = v70;
      v69[6].m_impulseApplied = _mm_shuffle_ps(
                                  (__m128)LODWORD(v69[6].m_impulseApplied),
                                  (__m128)LODWORD(v69[6].m_impulseApplied),
                                  0).m128_f32[0]
                              + v19.m128_f32[0];
    }
    while ( v20 >= 0 );
  }
}

// File Line: 460
// RVA: 0xDE0480
void __fastcall hkSolver_buildStableJacobiansForBallSocketChain(
        hkpSolverInfo *solverInfo,
        hkpStableBallSocketSchema *schema,
        hkpVelocityAccumulator *regA,
        hkpVelocityAccumulator *regB,
        hkSimdFloat32 *virtMassFactor,
        hkp1Lin2AngJacobian *jacobiansOut)
{
  hkVector4f v6; // xmm0
  __m128 v7; // xmm2
  __m128 v8; // xmm7
  __m128 v9; // xmm12
  __m128 v10; // xmm2
  __m128 v11; // xmm3
  __m128 v12; // xmm4
  hkVector4f v13; // xmm2
  __m128 v14; // xmm3
  __m128 v15; // xmm4
  __m128 v16; // xmm1
  __m128 v17; // xmm0
  __m128 v18; // xmm2
  __m128 v19; // xmm8
  __m128 v20; // xmm0
  hkVector4f v21; // xmm2
  __m128 v22; // xmm8
  __m128 v23; // xmm1
  __m128 v24; // xmm0
  __m128 v25; // xmm2
  __m128 v26; // xmm9
  hkVector4f v27; // xmm10
  __m128 v28; // xmm0
  hkVector4f v29; // xmm11
  __m128 v30; // xmm9
  __m128 v31; // xmm0
  __m128 v32; // xmm1
  __m128 v33; // xmm2
  __m128 v34; // xmm3
  __m128 v35; // xmm0
  __m128 v36; // xmm8
  __m128 v37; // xmm2
  __m128 v38; // xmm13
  __m128 v39; // xmm15
  __m128 v40; // xmm1
  __m128 v41; // xmm2
  __m128 v42; // xmm0
  __m128 v43; // xmm1
  __m128 v44; // xmm9
  __m128 v45; // xmm14
  __m128 v46; // xmm2
  __m128 v47; // xmm4
  __m128 v48; // xmm1
  __m128 v49; // xmm4
  __m128 v51; // xmm12
  __m128 v52; // xmm7
  __int64 v53; // rcx
  __m128 v54; // xmm2
  __m128 v55; // xmm10
  __m128 v56; // xmm3
  hkVector4f v57; // xmm1
  __m128 v58; // xmm3
  __m128 v59; // xmm4
  __m128 v60; // xmm11
  __m128 v61; // xmm6
  __m128 v62; // xmm12
  hkVector4f v63; // xmm2
  __m128 v64; // xmm1
  __m128 v65; // xmm3
  __m128 v66; // xmm3
  __m128 v67; // xmm5
  __m128 v68; // xmm1
  __m128 v69; // xmm5
  __m128 v70; // xmm2
  __m128 v71; // xmm6
  __m128 v72; // xmm1
  __m128 v73; // xmm6
  __m128 v74; // xmm6
  __m128 v75; // xmm2
  __m128 v76; // xmm4
  __m128 v77; // xmm4
  hkVector4f v78; // xmm2
  __m128 v79; // xmm3
  __m128 v80; // xmm3
  __m128 v81; // xmm0
  __m128 v82; // xmm2
  __m128 v83; // xmm1
  __m128 v84; // xmm0
  __m128 v85; // xmm2
  __m128 v86; // [rsp+10h] [rbp-118h]
  __m128 v87; // [rsp+20h] [rbp-108h]
  __m128 v88; // [rsp+30h] [rbp-F8h]
  __m128 v89; // [rsp+40h] [rbp-E8h]
  __int128 v90[13]; // [rsp+50h] [rbp-D8h]

  v6.m_quad = (__m128)solverInfo->m_invIntegrateVelocityFactor;
  v7 = _mm_shuffle_ps((__m128)LODWORD(solverInfo->m_deltaTime), (__m128)LODWORD(solverInfo->m_deltaTime), 0);
  v8 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(regA->m_scratch0.m_quad, v6.m_quad), v7), regA->m_scratch3.m_quad);
  v9 = _mm_mul_ps(_mm_mul_ps(regB->m_scratch0.m_quad, v6.m_quad), v7);
  v10 = _mm_mul_ps(v7, (__m128)xmmword_141A711B0);
  v11 = _mm_mul_ps(_mm_mul_ps(regA->m_scratch1.m_quad, v6.m_quad), v10);
  v12 = _mm_mul_ps(_mm_mul_ps(regB->m_scratch1.m_quad, v6.m_quad), v10);
  v13.m_quad = (__m128)regA->m_scratch2;
  v14 = _mm_shuffle_ps(v11, _mm_unpackhi_ps(v11, query.m_quad), 196);
  v15 = _mm_shuffle_ps(v12, _mm_unpackhi_ps(v12, query.m_quad), 196);
  v16 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v13.m_quad, v13.m_quad, 201), v14),
          _mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v13.m_quad));
  v17 = _mm_mul_ps(_mm_shuffle_ps(v14, v14, 255), v13.m_quad);
  v18 = _mm_mul_ps(v13.m_quad, v14);
  v19 = _mm_sub_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(regA->m_scratch2.m_quad, regA->m_scratch2.m_quad, 255), v14),
            _mm_shuffle_ps(v16, v16, 201)),
          v17);
  v20 = _mm_add_ps(_mm_shuffle_ps(v18, v18, 78), v18);
  v21.m_quad = (__m128)regB->m_scratch2;
  v22 = _mm_shuffle_ps(v19, _mm_unpackhi_ps(v19, _mm_add_ps(_mm_shuffle_ps(v20, v20, 177), v20)), 196);
  v23 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v21.m_quad, v21.m_quad, 201), v15),
          _mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), v21.m_quad));
  v24 = _mm_mul_ps(_mm_shuffle_ps(v15, v15, 255), v21.m_quad);
  v25 = _mm_mul_ps(v21.m_quad, v15);
  v26 = _mm_sub_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(regB->m_scratch2.m_quad, regB->m_scratch2.m_quad, 255), v15),
            _mm_shuffle_ps(v23, v23, 201)),
          v24);
  v27.m_quad = (__m128)schema->m_armDirA;
  v28 = _mm_add_ps(_mm_shuffle_ps(v25, v25, 78), v25);
  v29.m_quad = (__m128)schema->m_armDirB;
  v30 = _mm_shuffle_ps(v26, _mm_unpackhi_ps(v26, _mm_add_ps(_mm_shuffle_ps(v28, v28, 177), v28)), 196);
  v31 = _mm_mul_ps(v22, v22);
  v32 = _mm_add_ps(_mm_shuffle_ps(v31, v31, 78), v31);
  v33 = _mm_add_ps(_mm_shuffle_ps(v32, v32, 177), v32);
  v34 = _mm_rsqrt_ps(v33);
  v35 = _mm_mul_ps(v30, v30);
  v36 = _mm_mul_ps(
          v22,
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v34, v33), v34)), _mm_mul_ps(v34, *(__m128 *)_xmm)));
  v37 = _mm_add_ps(_mm_shuffle_ps(v35, v35, 78), v35);
  v38 = _mm_shuffle_ps(v36, v36, 255);
  v39 = _mm_shuffle_ps(v36, v36, 201);
  v40 = _mm_add_ps(_mm_shuffle_ps(v37, v37, 177), v37);
  v41 = _mm_rsqrt_ps(v40);
  v42 = _mm_mul_ps(_mm_mul_ps(v41, v40), v41);
  v43 = _mm_mul_ps(v36, v27.m_quad);
  v44 = _mm_mul_ps(v30, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, v42), _mm_mul_ps(v41, *(__m128 *)_xmm)));
  v45 = _mm_shuffle_ps(v44, v44, 255);
  v46 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v27.m_quad, v27.m_quad, 201), v36), _mm_mul_ps(v39, v27.m_quad));
  v47 = _mm_mul_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v43, v43, 85), _mm_shuffle_ps(v43, v43, 0)),
            _mm_shuffle_ps(v43, v43, 170)),
          v36);
  v48 = _mm_mul_ps(v44, v29.m_quad);
  v49 = _mm_add_ps(
          _mm_add_ps(v47, _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v38, v38), (__m128)xmmword_141A711B0), v27.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v46, v46, 201), v38));
  v51 = _mm_sub_ps(_mm_add_ps(v9, regB->m_scratch3.m_quad), v8);
  v52 = _mm_shuffle_ps(v44, v44, 201);
  v53 = 0i64;
  v54 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v29.m_quad, v29.m_quad, 201), v44), _mm_mul_ps(v52, v29.m_quad));
  v55 = _mm_mul_ps(_mm_shuffle_ps(v27.m_quad, v27.m_quad, 255), _mm_add_ps(v49, v49));
  v56 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v48, v48, 85), _mm_shuffle_ps(v48, v48, 0)), _mm_shuffle_ps(v48, v48, 170));
  v57.m_quad = (__m128)schema->m_data1;
  v58 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(v56, v44),
            _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v45, v45), (__m128)xmmword_141A711B0), v29.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v54, v54, 201), v45));
  v59 = _mm_shuffle_ps(v55, v55, 201);
  v88 = v59;
  v60 = _mm_mul_ps(_mm_shuffle_ps(v29.m_quad, v29.m_quad, 255), _mm_add_ps(v58, v58));
  v61 = _mm_shuffle_ps(v60, v60, 201);
  v89 = v61;
  v90[0] = (__int128)transform.m_quad;
  v62 = _mm_mul_ps(_mm_add_ps(v51, _mm_sub_ps(v60, v55)), _mm_shuffle_ps(v57.m_quad, v57.m_quad, 0));
  v90[2] = (__int128)stru_141A71280.m_quad;
  v86 = _mm_mul_ps(v38, v38);
  v90[1] = (__int128)direction.m_quad;
  v87 = _mm_mul_ps(v45, v45);
  do
  {
    v63.m_quad = (__m128)v90[v53];
    jacobiansOut->m_linear0 = (hkVector4f)v63.m_quad;
    v64 = _mm_shuffle_ps(v63.m_quad, v63.m_quad, 201);
    v65 = _mm_sub_ps(_mm_mul_ps(v55, v64), _mm_mul_ps(v63.m_quad, v59));
    v66 = _mm_shuffle_ps(v65, v65, 201);
    v67 = _mm_sub_ps(_mm_mul_ps(v63.m_quad, v61), _mm_mul_ps(v60, v64));
    v68 = _mm_mul_ps(v36, v66);
    v69 = _mm_shuffle_ps(v67, v67, 201);
    v70 = _mm_sub_ps(_mm_mul_ps(v66, v39), _mm_mul_ps(_mm_shuffle_ps(v66, v66, 201), v36));
    v71 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v68, v68, 85), _mm_shuffle_ps(v68, v68, 0)),
            _mm_shuffle_ps(v68, v68, 170));
    v72 = _mm_mul_ps(v44, v69);
    v73 = _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(v71, v36), _mm_mul_ps(_mm_sub_ps(v86, (__m128)xmmword_141A711B0), v66)),
            _mm_mul_ps(_mm_shuffle_ps(v70, v70, 201), v38));
    v74 = _mm_add_ps(v73, v73);
    jacobiansOut->m_angular[0].m_quad = v74;
    v75 = _mm_sub_ps(_mm_mul_ps(v69, v52), _mm_mul_ps(_mm_shuffle_ps(v69, v69, 201), v44));
    v76 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v72, v72, 85), _mm_shuffle_ps(v72, v72, 0)),
                  _mm_shuffle_ps(v72, v72, 170)),
                v44),
              _mm_mul_ps(_mm_sub_ps(v87, (__m128)xmmword_141A711B0), v69)),
            _mm_mul_ps(_mm_shuffle_ps(v75, v75, 201), v45));
    v77 = _mm_add_ps(v76, v76);
    jacobiansOut->m_angular[1].m_quad = v77;
    v78.m_quad = (__m128)regB->m_invMasses;
    v79 = _mm_add_ps(
            _mm_mul_ps(_mm_mul_ps(v77, v77), v78.m_quad),
            _mm_mul_ps(_mm_mul_ps(v74, v74), regA->m_invMasses.m_quad));
    v80 = _mm_shuffle_ps(
            v79,
            _mm_unpackhi_ps(
              v79,
              _mm_max_ps(_mm_add_ps(v78.m_quad, regA->m_invMasses.m_quad), (__m128)xmmword_141A712D0)),
            196);
    v81 = _mm_add_ps(_mm_shuffle_ps(v80, v80, 78), v80);
    ++v53;
    ++jacobiansOut;
    v82 = _mm_add_ps(_mm_shuffle_ps(v81, v81, 177), v81);
    v83 = _mm_rcp_ps(v82);
    jacobiansOut[-1].m_angular[1].m_quad = _mm_shuffle_ps(v77, _mm_unpackhi_ps(v77, v82), 196);
    v59 = v88;
    jacobiansOut[-1].m_angular[0].m_quad = _mm_shuffle_ps(
                                             v74,
                                             _mm_unpackhi_ps(
                                               v74,
                                               _mm_mul_ps(
                                                 _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v83, v82)), v83),
                                                 virtMassFactor->m_real)),
                                             196);
    v84 = _mm_and_ps((__m128)`hkVector4f::getComponent::`2::indexToMask[v53 - 1], v62);
    v61 = v89;
    v85 = _mm_or_ps(_mm_shuffle_ps(v84, v84, 78), v84);
    jacobiansOut[-1].m_linear0.m_quad = _mm_shuffle_ps(
                                          jacobiansOut[-1].m_linear0.m_quad,
                                          _mm_unpackhi_ps(
                                            jacobiansOut[-1].m_linear0.m_quad,
                                            _mm_or_ps(_mm_shuffle_ps(v85, v85, 177), v85)),
                                          196);
  }
  while ( v53 < 3 );
}

// File Line: 577
// RVA: 0xDE0A10
void __fastcall hkSolver_solveStabilizedBallAndSocketChain(
        hkpSolverInfo *info,
        hkSolverStepTemp *temp,
        hkpVelocityAccumulator *accumBase,
        hkpJacobianStabilizedBallSocketChainSchema *chain,
        hkpSolverElemTemp *sr)
{
  hkpVelocityAccumulator *v5; // rbx
  __int64 m_numConstraints; // rsi
  int v7; // r13d
  int v8; // ebx
  hkpVelocityAccumulator *v10; // r12
  hkLifoAllocator *Value; // rax
  hkp1Lin2AngJacobian *m_cur; // rdi
  int v13; // edx
  char *v14; // rcx
  int v15; // eax
  int v16; // r15d
  int v17; // ebx
  int v18; // r9d
  __int64 v19; // rdx
  __int64 v20; // rbx
  hkpJacobianStabilizedBallSocketChainSchema *v21; // r10
  hkpVelocityAccumulatorOffset *v22; // r15
  int v23; // r12d
  __int64 m_offset; // r9
  hkpVelocityAccumulator *v25; // r8
  hkLifoAllocator *v26; // rax
  hkpConstraintChainMatrixTriple *v27; // rbx
  int v28; // edx
  char *v29; // rcx
  int v30; // r9d
  float m_cfm; // xmm1_4
  __m128 v32; // xmm10
  __int64 v33; // r11
  float *p_m_damping; // r9
  __m128 *v35; // r8
  __m128 v36; // xmm11
  __m128 v37; // xmm12
  __m128 *p_m_quad; // rdi
  hkVector4f *p_m_col2; // r10
  __m128 *v40; // rcx
  __m128 *v41; // rax
  __m128 v42; // xmm4
  __m128 v43; // xmm1
  __m128 v44; // xmm3
  __m128 v45; // xmm7
  __m128 v46; // xmm5
  __m128 v47; // xmm0
  __m128 v48; // xmm3
  __m128 v49; // xmm2
  __m128 v50; // xmm1
  __m128 v51; // xmm9
  __m128 v52; // xmm9
  int v53; // esi
  hkpVelocityAccumulatorOffset *v54; // rdi
  __m128 v55; // xmm6
  __m128 v56; // xmm7
  __m128 *v57; // r10
  float *v58; // r14
  __m128 *v59; // rbx
  __m128 *v60; // r11
  __int64 v61; // r15
  float *v62; // rdx
  __m128 *v63; // rax
  __m128 *v64; // rcx
  __m128 v65; // xmm5
  __m128 v66; // xmm3
  __m128 v67; // xmm4
  __m128 v68; // xmm1
  __m128 v69; // xmm0
  __m128 v70; // xmm1
  __m128 v71; // xmm0
  __m128 v72; // xmm4
  __m128 v73; // xmm3
  __m128 v74; // xmm1
  __m128 v75; // xmm0
  __m128 v76; // xmm1
  __m128 v77; // xmm0
  __m128 v78; // xmm4
  __m128 v79; // xmm3
  __m128 v80; // xmm1
  __m128 v81; // xmm0
  int v82; // eax
  char *v83; // rdi
  signed int v84; // ebx
  hkLifoAllocator *v85; // rax
  int v86; // r8d
  int v87; // eax
  char *v88; // rdi
  signed int v89; // ebx
  hkLifoAllocator *v90; // rax
  int v91; // r8d
  hkResult result[2]; // [rsp+40h] [rbp-B8h] BYREF
  hkSimdFloat32 virtMassFactor; // [rsp+50h] [rbp-A8h] BYREF
  hkp1Lin2AngJacobian *array; // [rsp+60h] [rbp-98h] BYREF
  int v95; // [rsp+68h] [rbp-90h]
  int v96; // [rsp+6Ch] [rbp-8Ch]
  void *v97; // [rsp+70h] [rbp-88h]
  hkpConstraintChainMatrixTriple *v98; // [rsp+78h] [rbp-80h] BYREF
  int v99; // [rsp+80h] [rbp-78h]
  int v100; // [rsp+84h] [rbp-74h]
  void *p; // [rsp+88h] [rbp-70h]
  int v102; // [rsp+90h] [rbp-68h]
  hkpSolverInfo *retaddr; // [rsp+148h] [rbp+50h]
  hkpVelocityAccumulator *v104; // [rsp+158h] [rbp+60h]
  hkpVelocityAccumulator *v105; // [rsp+160h] [rbp+68h] BYREF
  __int64 v106; // [rsp+168h] [rbp+70h]

  v105 = accumBase;
  v104 = v5;
  m_numConstraints = chain->m_numConstraints;
  v7 = 0;
  v8 = 3 * m_numConstraints;
  v10 = accumBase;
  LODWORD(v105) = chain->m_numConstraints;
  array = 0i64;
  v95 = 0;
  v96 = 0x80000000;
  LODWORD(v98) = 3 * m_numConstraints;
  if ( 3 * (_DWORD)m_numConstraints )
  {
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (hkp1Lin2AngJacobian *)Value->m_cur;
    v13 = (144 * m_numConstraints + 127) & 0xFFFFFF80;
    v14 = (char *)m_cur + v13;
    if ( v13 > Value->m_slabSize || v14 > Value->m_end )
    {
      m_cur = (hkp1Lin2AngJacobian *)hkLifoAllocator::allocateFromNewSlab(Value, v13);
      array = m_cur;
    }
    else
    {
      Value->m_cur = v14;
      array = m_cur;
    }
  }
  else
  {
    m_cur = 0i64;
    array = 0i64;
  }
  v15 = chain->m_numConstraints;
  v97 = m_cur;
  v16 = 3 * v15;
  v96 = v8 | 0x80000000;
  v17 = v8 & 0x3FFFFFFF;
  if ( v17 < 3 * v15 )
  {
    v18 = 3 * v15;
    if ( v16 < 2 * v17 )
      v18 = 2 * v17;
    hkArrayUtil::_reserve(result, &hkContainerHeapAllocator::s_alloc, (const void **)&array, v18, 48);
    m_cur = array;
  }
  v19 = chain->m_numConstraints;
  v95 = v16;
  v20 = 0i64;
  v21 = chain + 1;
  *(_QWORD *)&result[0].m_enum = m_numConstraints;
  v22 = (hkpVelocityAccumulatorOffset *)(&chain[2 * v19 + 1].m_damping + 4 * (int)v19);
  if ( (int)m_numConstraints > 0 )
  {
    v23 = 0;
    while ( 1 )
    {
      m_offset = v22[v20 + 1].m_offset;
      v25 = (hkpVelocityAccumulator *)((char *)v104 + v22[v20].m_offset);
      virtMassFactor.m_real = _mm_shuffle_ps(
                                (__m128)LODWORD(chain->m_virtualMassFactor),
                                (__m128)LODWORD(chain->m_virtualMassFactor),
                                0);
      hkSolver_buildStableJacobiansForBallSocketChain(
        retaddr,
        (hkpStableBallSocketSchema *)&v21[2 * (__int64)v7],
        v25,
        (hkpVelocityAccumulator *)((char *)v104 + m_offset),
        &virtMassFactor,
        &m_cur[v23]);
      m_cur = array;
      ++v20;
      ++v7;
      v23 += 3;
      if ( v20 >= *(__int64 *)&result[0].m_enum )
        break;
      v21 = chain + 1;
    }
    LODWORD(m_numConstraints) = (_DWORD)v105;
    v10 = v104;
  }
  v100 = 0x80000000;
  v102 = m_numConstraints;
  v98 = 0i64;
  v99 = 0;
  if ( (_DWORD)m_numConstraints )
  {
    v26 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v27 = (hkpConstraintChainMatrixTriple *)v26->m_cur;
    v28 = (144 * m_numConstraints + 127) & 0xFFFFFF80;
    v29 = (char *)v27 + v28;
    if ( v28 > v26->m_slabSize || v29 > v26->m_end )
      v27 = (hkpConstraintChainMatrixTriple *)hkLifoAllocator::allocateFromNewSlab(v26, v28);
    else
      v26->m_cur = v29;
  }
  else
  {
    v27 = 0i64;
  }
  v98 = v27;
  p = v27;
  v100 = m_numConstraints | 0x80000000;
  if ( (m_numConstraints & 0x3FFFFFFF) < (int)m_numConstraints )
  {
    v30 = m_numConstraints;
    if ( (int)m_numConstraints < (int)(2 * (m_numConstraints & 0x3FFFFFFF)) )
      v30 = 2 * (m_numConstraints & 0x3FFFFFFF);
    hkArrayUtil::_reserve((hkResult *)&v105, &hkContainerHeapAllocator::s_alloc, (const void **)&v98, v30, 144);
    v27 = v98;
  }
  m_cfm = chain->m_cfm;
  v99 = m_numConstraints;
  buildConstraintMatrixLuDecompositionForBallAndSocketChain_outOfLine(
    m_numConstraints,
    m_cfm,
    m_cur,
    v22,
    v10,
    v27,
    144 * m_numConstraints);
  v32 = 0i64;
  v33 = 0i64;
  p_m_damping = &chain[2 * (unsigned __int64)chain->m_numConstraints + 1].m_damping;
  v35 = (__m128 *)(p_m_damping - 4);
  *((_OWORD *)p_m_damping - 1) = 0i64;
  v36 = _mm_shuffle_ps((__m128)LODWORD(chain->m_tau), (__m128)LODWORD(chain->m_tau), 0);
  v37 = _mm_shuffle_ps((__m128)LODWORD(chain->m_damping), (__m128)LODWORD(chain->m_damping), 0);
  if ( (int)m_numConstraints > 0 )
  {
    p_m_quad = &m_cur[2].m_angular[0].m_quad;
    p_m_col2 = &v27->m_diagonalInv.m_col2;
    do
    {
      v40 = (__m128 *)(&v10->m_type.m_storage + v22[v33].m_offset);
      v41 = (__m128 *)(&v10->m_type.m_storage + v22[v33 + 1].m_offset);
      v42 = _mm_sub_ps(v41[2], v41[5]);
      v43 = _mm_sub_ps(v40[2], v40[5]);
      v44 = _mm_sub_ps(_mm_sub_ps(v40[1], v40[4]), _mm_sub_ps(v41[1], v41[4]));
      v45 = _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(p_m_quad[1], v42), _mm_mul_ps(*p_m_quad, v43)),
                _mm_mul_ps(p_m_quad[-1], v44)),
              v37);
      v46 = _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(p_m_quad[-3], v43), _mm_mul_ps(p_m_quad[-2], v42)),
                _mm_mul_ps(p_m_quad[-4], v44)),
              v37);
      v47 = _mm_mul_ps(p_m_quad[-7], v44);
      v48 = *v35;
      v49 = _mm_mul_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(p_m_quad[-6], v43), _mm_mul_ps(p_m_quad[-5], v42)), v47), v37);
      v50 = _mm_mul_ps(_mm_shuffle_ps(*v35, *v35, 85), p_m_col2[-4].m_quad);
      v51 = _mm_movelh_ps(
              _mm_unpacklo_ps(
                _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(p_m_quad[-7], p_m_quad[-7], 255), v36),
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v49, v49, 85), _mm_shuffle_ps(v49, v49, 0)),
                    _mm_shuffle_ps(v49, v49, 170))),
                _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(p_m_quad[-4], p_m_quad[-4], 255), v36),
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v46, v46, 85), _mm_shuffle_ps(v46, v46, 0)),
                    _mm_shuffle_ps(v46, v46, 170)))),
              _mm_unpacklo_ps(
                _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(p_m_quad[-1], p_m_quad[-1], 255), v36),
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v45, v45, 85), _mm_shuffle_ps(v45, v45, 0)),
                    _mm_shuffle_ps(v45, v45, 170))),
                aabbOut.m_quad));
      ++v33;
      ++v35;
      p_m_quad += 9;
      p_m_col2 += 9;
      v52 = _mm_sub_ps(
              v51,
              _mm_add_ps(
                _mm_add_ps(v50, _mm_mul_ps(_mm_shuffle_ps(v48, v48, 0), p_m_col2[-14].m_quad)),
                _mm_mul_ps(_mm_shuffle_ps(v48, v48, 170), p_m_col2[-12].m_quad)));
      *v35 = _mm_add_ps(
               _mm_add_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v52, v52, 85), p_m_col2[-10].m_quad),
                 _mm_mul_ps(_mm_shuffle_ps(v52, v52, 0), p_m_col2[-11].m_quad)),
               _mm_mul_ps(_mm_shuffle_ps(v52, v52, 170), p_m_col2[-9].m_quad));
    }
    while ( v33 < (int)m_numConstraints );
  }
  v53 = m_numConstraints - 1;
  if ( v53 >= 0 )
  {
    v54 = &v22[v53];
    v55 = _mm_shuffle_ps((__m128)0i64, (__m128)0i64, 85);
    v56 = _mm_shuffle_ps((__m128)0i64, (__m128)0i64, 0);
    v57 = (__m128 *)&p_m_damping[4 * v53];
    v58 = (float *)(v106 + 12i64 * v53);
    v59 = &v27[v53].m_upper.m_col2.m_quad;
    v60 = &array[3 * v53 + 1].m_angular[1].m_quad;
    v61 = v106 + 4i64 * (3 * v53 + 2);
    v62 = (float *)(v106 + 4i64 * (3 * v53 + 1));
    do
    {
      v63 = (__m128 *)(&v10->m_type.m_storage + v54->m_offset);
      v64 = (__m128 *)(&v10->m_type.m_storage + v54[1].m_offset);
      v65 = _mm_sub_ps(
              *v57,
              _mm_add_ps(_mm_add_ps(_mm_mul_ps(v59[-2], v56), _mm_mul_ps(v59[-1], v55)), _mm_mul_ps(v32, *v59)));
      v56 = _mm_shuffle_ps(v65, v65, 0);
      v55 = _mm_shuffle_ps(v65, v65, 85);
      v32 = _mm_shuffle_ps(v65, v65, 170);
      v66 = _mm_mul_ps(v56, v63[3]);
      v67 = _mm_mul_ps(v56, v64[3]);
      v68 = _mm_mul_ps(_mm_shuffle_ps(v67, v67, 255), v60[-5]);
      v63[1] = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v66, v66, 255), v60[-5]), v63[1]);
      v69 = _mm_sub_ps(v64[1], v68);
      v70 = v60[-3];
      v64[1] = v69;
      v71 = _mm_add_ps(_mm_mul_ps(v60[-4], v66), v63[2]);
      v64[2] = _mm_add_ps(_mm_mul_ps(v70, v67), v64[2]);
      v72 = _mm_mul_ps(v55, v64[3]);
      v63[2] = v71;
      v73 = _mm_mul_ps(v55, v63[3]);
      *v58 = _mm_shuffle_ps((__m128)*(unsigned int *)v58, (__m128)*(unsigned int *)v58, 0).m128_f32[0] + v56.m128_f32[0];
      v74 = _mm_mul_ps(_mm_shuffle_ps(v72, v72, 255), v60[-2]);
      v63[1] = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v73, v73, 255), v60[-2]), v63[1]);
      v75 = _mm_sub_ps(v64[1], v74);
      v76 = *v60;
      v64[1] = v75;
      v77 = _mm_add_ps(_mm_mul_ps(v60[-1], v73), v63[2]);
      v64[2] = _mm_add_ps(_mm_mul_ps(v76, v72), v64[2]);
      v78 = _mm_mul_ps(v32, v64[3]);
      v63[2] = v77;
      v79 = _mm_mul_ps(v32, v63[3]);
      *v62 = _mm_shuffle_ps((__m128)*(unsigned int *)v62, (__m128)*(unsigned int *)v62, 0).m128_f32[0] + v55.m128_f32[0];
      v63[1] = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v79, v79, 255), v60[1]), v63[1]);
      v61 -= 12i64;
      v58 -= 3;
      v62 -= 3;
      --v54;
      v60 -= 9;
      v59 -= 9;
      --v57;
      --v53;
      v80 = _mm_mul_ps(v60[12], v78);
      v64[1] = _mm_sub_ps(v64[1], _mm_mul_ps(_mm_shuffle_ps(v78, v78, 255), v60[10]));
      v81 = _mm_add_ps(_mm_mul_ps(v60[11], v79), v63[2]);
      v64[2] = _mm_add_ps(v80, v64[2]);
      v63[2] = v81;
      *(float *)(v61 + 12) = _mm_shuffle_ps((__m128)*(unsigned int *)(v61 + 12), (__m128)*(unsigned int *)(v61 + 12), 0).m128_f32[0]
                           + v32.m128_f32[0];
    }
    while ( v53 >= 0 );
  }
  v82 = v99;
  v83 = (char *)p;
  if ( p == v98 )
    v82 = 0;
  v99 = v82;
  v84 = (144 * v102 + 127) & 0xFFFFFF80;
  v85 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v86 = (v84 + 15) & 0xFFFFFFF0;
  if ( v84 > v85->m_slabSize || &v83[v86] != v85->m_cur || v85->m_firstNonLifoEnd == v83 )
    hkLifoAllocator::slowBlockFree(v85, v83, v86);
  else
    v85->m_cur = v83;
  v99 = 0;
  if ( v100 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v98, 144 * (v100 & 0x3FFFFFFF));
  v87 = v95;
  v88 = (char *)v97;
  v98 = 0i64;
  v100 = 0x80000000;
  if ( v97 == array )
    v87 = 0;
  v95 = v87;
  v89 = (48 * (_DWORD)v98 + 127) & 0xFFFFFF80;
  v90 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v91 = (v89 + 15) & 0xFFFFFFF0;
  if ( v89 > v90->m_slabSize || &v88[v91] != v90->m_cur || v90->m_firstNonLifoEnd == v88 )
    hkLifoAllocator::slowBlockFree(v90, v88, v91);
  else
    v90->m_cur = v88;
  v95 = 0;
  if ( v96 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 48 * (v96 & 0x3FFFFFFF));
}

// File Line: 1146
// RVA: 0xDE1300
void __fastcall updateSumVelocities_0_(
        hkpSolverInfo *info,
        hkVector4f *velocityField,
        hkSimdFloat32 *sumVelFactor,
        hkpVelocityAccumulator *m)
{
  __m128 v4; // xmm3
  __m128 v5; // xmm4
  hkVector4f v6; // xmm1
  hkVector4f v7; // xmm2
  hkVector4f v8; // xmm1
  __m128 m_gravityFactor_low; // xmm0

  v4 = _mm_sub_ps(m->m_linearVel.m_quad, m->m_scratch0.m_quad);
  v5 = _mm_sub_ps(m->m_angularVel.m_quad, m->m_scratch1.m_quad);
  v6.m_quad = (__m128)info->m_integrateVelocityFactor;
  v7.m_quad = _mm_add_ps(_mm_mul_ps(v6.m_quad, v5), m->m_scratch1.m_quad);
  v8.m_quad = _mm_add_ps(_mm_mul_ps(v6.m_quad, v4), m->m_scratch0.m_quad);
  m->m_scratch1 = (hkVector4f)v7.m_quad;
  m->m_scratch0 = (hkVector4f)v8.m_quad;
  m_gravityFactor_low = (__m128)LODWORD(m->m_gravityFactor);
  m->m_angularVel.m_quad = _mm_add_ps(v7.m_quad, v5);
  m->m_linearVel.m_quad = _mm_add_ps(
                            _mm_mul_ps(
                              _mm_shuffle_ps(m_gravityFactor_low, m_gravityFactor_low, 0),
                              velocityField->m_quad),
                            _mm_add_ps(v8.m_quad, v4));
}

// File Line: 1175
// RVA: 0xDE1DD0
void __fastcall hkSolver::integrateVelocities<0>(
        hkpSolverInfo *info,
        hkVector4f *velocityField,
        hkSimdFloat32 *sumVelFactor,
        hkpVelocityAccumulator *acc,
        hkpVelocityAccumulator *accEnd)
{
  unsigned __int64 v5; // r8
  __int64 m_deactivationClass; // rdx
  __m128i si128; // xmm4
  __m128i v9; // xmm1
  __m128 v10; // xmm3
  __m128 v11; // xmm2
  __m128 v12; // xmm4
  __m128 v13; // xmm1
  __m128 v14; // xmm5
  hkVector4f v15; // xmm0
  __m128 v16; // xmm0
  hkVector4f v17; // xmm1
  hkVector4f v18; // xmm4
  hkVector4f v19; // xmm3
  __m128 v20; // xmm4
  __m128 v21; // xmm3
  __m128 v22; // xmm4
  hkVector4f v23; // xmm1
  __m128 v24; // xmm0
  __int64 v25; // rdx
  __m128i v26; // xmm1
  __m128i v27; // xmm3
  __m128 v28; // xmm4
  __m128 v29; // xmm2
  __m128 v30; // xmm3
  __m128 v31; // xmm1
  __m128 v32; // xmm5
  hkVector4f v33; // xmm0
  __m128 v34; // xmm0
  hkVector4f v35; // xmm1
  hkVector4f v36; // xmm4
  hkVector4f v37; // xmm3
  __m128 v38; // xmm4
  __m128 v39; // xmm3
  __m128 v40; // xmm4
  hkVector4f v41; // xmm1
  __m128 v42; // xmm0

  v5 = (unsigned __int64)accEnd;
  if ( !accEnd )
    v5 = -1i64;
  while ( (unsigned __int64)acc < v5 )
  {
    if ( acc->m_type.m_storage )
    {
      if ( acc->m_type.m_storage != 1 )
      {
        if ( acc->m_type.m_storage != 2 )
        {
          if ( acc->m_type.m_storage == 3 )
            return;
          continue;
        }
        m_deactivationClass = acc->m_deactivationClass;
        si128 = _mm_load_si128((const __m128i *)&acc->m_linearVel);
        v9 = _mm_load_si128((const __m128i *)&acc->m_angularVel);
        v10 = _mm_cmpeq_ps((__m128)si128, (__m128)si128);
        v11 = _mm_cmpeq_ps((__m128)v9, (__m128)v9);
        v12 = (__m128)_mm_srli_epi32(_mm_slli_epi32(si128, 1u), 1u);
        v13 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v9, 1u), 1u);
        v14 = _mm_add_ps(
                _mm_mul_ps(
                  _mm_shuffle_ps(
                    (__m128)LODWORD(info->m_deactivationInfo[m_deactivationClass].m_angularVelocityThresholdInv),
                    (__m128)LODWORD(info->m_deactivationInfo[m_deactivationClass].m_angularVelocityThresholdInv),
                    0),
                  v13),
                _mm_mul_ps(
                  _mm_shuffle_ps(
                    (__m128)LODWORD(info->m_deactivationInfo[m_deactivationClass].m_linearVelocityThresholdInv),
                    (__m128)LODWORD(info->m_deactivationInfo[m_deactivationClass].m_linearVelocityThresholdInv),
                    0),
                  v12));
        if ( (_mm_movemask_ps(
                _mm_and_ps(
                  _mm_and_ps(
                    _mm_and_ps(_mm_cmplt_ps(v12, *(__m128 *)maxVelf), _mm_cmplt_ps(v13, *(__m128 *)maxVelf)),
                    v10),
                  v11)) & 7) != 7 )
        {
          acc->m_linearVel = (hkVector4f)transform.m_quad;
          acc->m_angularVel = (hkVector4f)transform.m_quad;
        }
        if ( (_mm_movemask_ps(_mm_cmple_ps(v14, query.m_quad)) & 7) == 7 )
        {
          if ( (_mm_movemask_ps(
                  _mm_cmple_ps(
                    v14,
                    _mm_shuffle_ps(
                      (__m128)LODWORD(info->m_deactivationInfo[m_deactivationClass].m_relativeSleepVelocityThreshold),
                      (__m128)LODWORD(info->m_deactivationInfo[m_deactivationClass].m_relativeSleepVelocityThreshold),
                      0))) & 7) == 7 )
          {
            v15.m_quad = 0i64;
            acc->m_linearVel = 0i64;
          }
          else
          {
            v16 = _mm_shuffle_ps(
                    (__m128)LODWORD(info->m_deactivationInfo[m_deactivationClass].m_slowObjectVelocityMultiplier),
                    (__m128)LODWORD(info->m_deactivationInfo[m_deactivationClass].m_slowObjectVelocityMultiplier),
                    0);
            v17.m_quad = _mm_mul_ps(v16, acc->m_linearVel.m_quad);
            v15.m_quad = _mm_mul_ps(v16, acc->m_angularVel.m_quad);
            acc->m_linearVel = (hkVector4f)v17.m_quad;
          }
          acc->m_angularVel = (hkVector4f)v15.m_quad;
        }
      }
      v18.m_quad = (__m128)acc->m_linearVel;
      v19.m_quad = (__m128)acc->m_angularVel;
      ++acc;
      v20 = _mm_sub_ps(v18.m_quad, acc[-1].m_scratch0.m_quad);
      v21 = _mm_sub_ps(v19.m_quad, acc[-1].m_scratch1.m_quad);
      acc[-1].m_scratch0.m_quad = _mm_add_ps(
                                    _mm_mul_ps(v20, info->m_integrateVelocityFactor.m_quad),
                                    acc[-1].m_scratch0.m_quad);
      v22 = _mm_add_ps(v20, acc[-1].m_scratch0.m_quad);
      v23.m_quad = _mm_add_ps(_mm_mul_ps(v21, info->m_integrateVelocityFactor.m_quad), acc[-1].m_scratch1.m_quad);
      acc[-1].m_scratch1 = (hkVector4f)v23.m_quad;
      v24 = _mm_mul_ps(
              _mm_shuffle_ps((__m128)LODWORD(acc[-1].m_gravityFactor), (__m128)LODWORD(acc[-1].m_gravityFactor), 0),
              aabbOut.m_quad);
      acc[-1].m_angularVel.m_quad = _mm_add_ps(v21, v23.m_quad);
      acc[-1].m_linearVel.m_quad = _mm_add_ps(v24, v22);
    }
    else
    {
      while ( 1 )
      {
        v25 = acc->m_deactivationClass;
        v26 = _mm_load_si128((const __m128i *)&acc->m_linearVel);
        v27 = _mm_load_si128((const __m128i *)&acc->m_angularVel);
        v28 = _mm_cmpeq_ps((__m128)v26, (__m128)v26);
        v29 = _mm_cmpeq_ps((__m128)v27, (__m128)v27);
        v30 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v27, 1u), 1u);
        v31 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v26, 1u), 1u);
        v32 = _mm_add_ps(
                _mm_mul_ps(
                  _mm_shuffle_ps(
                    (__m128)LODWORD(info->m_deactivationInfo[v25].m_linearVelocityThresholdInv),
                    (__m128)LODWORD(info->m_deactivationInfo[v25].m_linearVelocityThresholdInv),
                    0),
                  v31),
                _mm_mul_ps(
                  _mm_shuffle_ps(
                    (__m128)LODWORD(info->m_deactivationInfo[v25].m_angularVelocityThresholdInv),
                    (__m128)LODWORD(info->m_deactivationInfo[v25].m_angularVelocityThresholdInv),
                    0),
                  v30));
        if ( (_mm_movemask_ps(
                _mm_and_ps(
                  _mm_and_ps(
                    _mm_and_ps(_mm_cmplt_ps(v30, *(__m128 *)maxVelf), _mm_cmplt_ps(v31, *(__m128 *)maxVelf)),
                    v28),
                  v29)) & 7) != 7 )
        {
          acc->m_linearVel = (hkVector4f)transform.m_quad;
          acc->m_angularVel = (hkVector4f)transform.m_quad;
        }
        if ( (_mm_movemask_ps(_mm_cmple_ps(v32, query.m_quad)) & 7) == 7 )
        {
          if ( (_mm_movemask_ps(
                  _mm_cmple_ps(
                    v32,
                    _mm_shuffle_ps(
                      (__m128)LODWORD(info->m_deactivationInfo[v25].m_relativeSleepVelocityThreshold),
                      (__m128)LODWORD(info->m_deactivationInfo[v25].m_relativeSleepVelocityThreshold),
                      0))) & 7) == 7 )
          {
            v33.m_quad = 0i64;
            acc->m_linearVel = 0i64;
          }
          else
          {
            v34 = _mm_shuffle_ps(
                    (__m128)LODWORD(info->m_deactivationInfo[v25].m_slowObjectVelocityMultiplier),
                    (__m128)LODWORD(info->m_deactivationInfo[v25].m_slowObjectVelocityMultiplier),
                    0);
            v35.m_quad = _mm_mul_ps(v34, acc->m_linearVel.m_quad);
            v33.m_quad = _mm_mul_ps(v34, acc->m_angularVel.m_quad);
            acc->m_linearVel = (hkVector4f)v35.m_quad;
          }
          acc->m_angularVel = (hkVector4f)v33.m_quad;
        }
        v36.m_quad = (__m128)acc->m_linearVel;
        v37.m_quad = (__m128)acc->m_angularVel;
        ++acc;
        v38 = _mm_sub_ps(v36.m_quad, acc[-1].m_scratch0.m_quad);
        v39 = _mm_sub_ps(v37.m_quad, acc[-1].m_scratch1.m_quad);
        acc[-1].m_scratch0.m_quad = _mm_add_ps(
                                      _mm_mul_ps(v38, info->m_integrateVelocityFactor.m_quad),
                                      acc[-1].m_scratch0.m_quad);
        v40 = _mm_add_ps(v38, acc[-1].m_scratch0.m_quad);
        v41.m_quad = _mm_add_ps(_mm_mul_ps(v39, info->m_integrateVelocityFactor.m_quad), acc[-1].m_scratch1.m_quad);
        acc[-1].m_scratch1 = (hkVector4f)v41.m_quad;
        v42 = _mm_mul_ps(
                _mm_shuffle_ps((__m128)LODWORD(acc[-1].m_gravityFactor), (__m128)LODWORD(acc[-1].m_gravityFactor), 0),
                velocityField->m_quad);
        acc[-1].m_angularVel.m_quad = _mm_add_ps(v39, v41.m_quad);
        acc[-1].m_linearVel.m_quad = _mm_add_ps(v42, v40);
        if ( acc->m_type.m_storage )
          break;
        if ( (unsigned __int64)acc >= v5 )
          return;
      }
    }
  }
}

// File Line: 1705
// RVA: 0xDDCF90
void __fastcall hkSolveStepJacobians(
        hkpSolverInfo *info,
        hkpJacobianSchema *schemas,
        hkpVelocityAccumulator *accumulators,
        hkpSolverElemTemp *tmp)
{
  int v4; // eax
  hkpJacobianSchema *v7; // rbx
  hkpVelocityAccumulator *v9; // r14
  hkpVelocityAccumulator *mB; // rdi
  __m128 v11; // xmm6
  __m128 v12; // xmm4
  __m128 v13; // xmm3
  __m128 v14; // xmm5
  __m128 v15; // xmm3
  __m128 v16; // xmm4
  __m128 v17; // xmm4
  float v18; // xmm2_4
  __m128 v19; // xmm5
  __m128 v20; // xmm4
  __m128 v21; // xmm7
  __m128 v22; // xmm3
  __m128 v23; // xmm0
  __m128 v24; // xmm7
  __m128 v25; // xmm3
  __m128 v26; // xmm4
  __m128 v27; // xmm4
  __m128 v28; // xmm5
  __m128 v29; // xmm2
  __m128 v30; // xmm9
  __m128 v31; // xmm2
  __m128 v32; // xmm3
  __m128 v33; // xmm1
  __m128 v34; // xmm6
  __m128 v35; // xmm5
  __m128 v36; // xmm7
  __m128 v37; // xmm8
  float v38; // xmm2_4
  __m128 v39; // xmm4
  __m128 v40; // xmm3
  __m128 v41; // xmm2
  __m128 v42; // xmm3
  float v43; // xmm0_4
  __m128 v44; // xmm4
  __m128 v45; // xmm3
  __m128 v46; // xmm2
  __m128 v47; // xmm3
  float v48; // xmm5_4
  __m128 v49; // xmm5
  __m128 v50; // xmm8
  __m128 v51; // xmm4
  __m128 v52; // xmm3
  __m128 v53; // xmm2
  __m128 v54; // xmm3
  __m128 v55; // xmm4
  __m128 v56; // xmm3
  __m128 v57; // xmm2
  __m128 v58; // xmm3
  float v59; // xmm1_4
  __m128 v60; // xmm4
  __m128 m_quad; // xmm0
  __m128 v62; // xmm2
  __m128 v63; // xmm9
  __m128 v64; // xmm5
  __m128 v65; // xmm2
  __m128 v66; // xmm1
  __m128 v67; // xmm8
  __m128 v68; // xmm5
  __m128 v69; // xmm6
  float v70; // xmm7_4
  __m128 v71; // xmm3
  __m128 v72; // xmm4
  __m128 v73; // xmm2
  __m128 v74; // xmm4
  __m128 v75; // xmm4
  __m128 v76; // xmm3
  __m128 v77; // xmm2
  __m128 v78; // xmm3
  float v79; // xmm0_4
  __m128 v80; // xmm5
  __m128 v81; // xmm6
  __m128 v82; // xmm4
  __m128 v83; // xmm3
  __m128 v84; // xmm2
  __m128 v85; // xmm3
  float v86; // xmm0_4
  __m128 v87; // xmm4
  __m128 v88; // xmm3
  __m128 v89; // xmm2
  __m128 v90; // xmm3
  float v91; // xmm0_4
  __m128 v92; // xmm5
  __m128 v93; // xmm6
  __m128 v94; // xmm3
  __m128 v95; // xmm2
  __m128 v96; // xmm9
  __m128 v97; // xmm2
  __m128 v98; // xmm7
  __m128 v99; // xmm2
  __m128 v100; // xmm10
  __m128 v101; // xmm1
  __m128 v102; // xmm4
  __m128 v103; // xmm5
  __m128 v104; // xmm3
  __m128 v105; // xmm8
  __m128 v106; // xmm1
  __m128 v107; // xmm3
  __m128 v108; // xmm6
  __m128 v109; // xmm5
  __m128 v110; // xmm4
  __m128 v111; // xmm7
  __m128 v112; // xmm3
  __m128 v113; // xmm2
  __m128 v114; // xmm3
  __m128 v115; // xmm3
  __m128 v116; // xmm4
  __m128 v117; // xmm2
  __m128 v118; // xmm3
  __m128 v119; // xmm4
  __m128 m_impulseApplied_low; // xmm1
  float v121; // xmm0_4
  __m128 v122; // xmm1
  __int64 v123; // r9
  __int64 v124; // r8
  float v125; // xmm9_4
  float v126; // xmm8_4
  float v127; // xmm10_4
  __m128 v128; // xmm4
  __m128 v129; // xmm0
  __m128 v130; // xmm2
  float v131; // xmm7_4
  __m128 v132; // xmm5
  float v133; // xmm1_4
  float v134; // xmm5_4
  float v135; // xmm6_4
  float v136; // xmm4_4
  float v137; // xmm7_4
  float v138; // xmm4_4
  float v139; // xmm2_4
  float v140; // xmm3_4
  float v141; // xmm5_4
  float v142; // xmm3_4
  float v143; // xmm3_4
  hkVector4f v144; // xmm7
  float v145; // xmm0_4
  __m128 v146; // xmm5
  __m128 v147; // xmm6
  __m128 v148; // xmm4
  __m128 v149; // xmm3
  __m128 v150; // xmm2
  __m128 v151; // xmm3
  float v152; // xmm1_4
  __m128 v153; // xmm4
  __m128 v154; // xmm3
  __m128 v155; // xmm2
  __m128 v156; // xmm4
  float v157; // xmm1_4
  __int64 v158; // rcx
  int v159; // edx
  __int64 v160; // rcx
  float v161; // xmm2_4
  int v162; // eax
  float v163; // xmm1_4
  __int64 v164; // rax
  int v165; // eax
  __m128 v166; // xmm4
  __m128 v167; // xmm6
  __m128 v168; // xmm0
  __m128 v169; // xmm2
  __m128 v170; // xmm7
  __m128 v171; // xmm5
  __m128 v172; // xmm0
  __m128 v173; // xmm5
  __m128 v174; // xmm2
  __m128 v175; // xmm1
  __m128 v176; // xmm5
  __m128 v177; // xmm4
  __m128 v178; // xmm3
  __m128 v179; // xmm1
  __m128 v180; // xmm8
  __m128 v181; // xmm3
  __m128 v182; // xmm6
  __m128 v183; // xmm5
  __m128 v184; // xmm4
  __m128 v185; // xmm3
  __m128 v186; // xmm2
  __m128 v187; // xmm3
  __m128 v188; // xmm4
  __m128 v189; // xmm3
  __m128 v190; // xmm2
  __m128 v191; // xmm3
  __m128 v192; // xmm6
  __m128 v193; // xmm3
  __m128 v194; // xmm4
  __m128 v195; // xmm4
  __m128 v196; // xmm2
  __m128i v197; // xmm1
  __m128i v198; // xmm6
  __m128 v199; // xmm1
  __m128 v200; // xmm5
  __m128 v201; // xmm0
  __m128 v202; // xmm6
  __m128 v203; // xmm2
  __m128 v204; // xmm3
  __m128 v205; // xmm7
  __m128 v206; // xmm6
  __m128 v207; // xmm8
  __m128 v208; // xmm4
  __m128 v209; // xmm2
  __m128 v210; // xmm1
  float v211; // xmm2_4
  __m128 v212; // xmm6
  __m128 v213; // xmm3
  __m128 v214; // xmm0
  __m128 v215; // xmm6
  __m128 v216; // xmm0
  __int64 v217; // rax
  __m128 v218; // xmm4
  __m128 v219; // xmm5
  __m128 v220; // xmm2
  __m128 v221; // xmm7
  __m128 v222; // xmm2
  __m128 v223; // xmm6
  __m128 v224; // xmm8
  __m128 v225; // xmm5
  __m128 v226; // xmm0
  __m128 v227; // xmm1
  __m128 v228; // xmm2
  __m128 v229; // xmm5
  __m128 v230; // xmm4
  __m128 v231; // xmm2
  __m128 v232; // xmm1
  float v233; // xmm0_4
  __m128 v234; // xmm3
  __m128 v235; // xmm5
  __m128 v236; // xmm7
  __m128 v237; // xmm3
  __m128 v238; // xmm7
  __m128 v239; // xmm3
  __m128 v240; // xmm4
  __m128 v241; // xmm4
  float v242; // xmm2_4
  __int64 v243; // rax
  __int64 v244; // rax
  __m128 v245; // xmm6
  __m128 v246; // xmm4
  __m128 v247; // xmm3
  __m128i v248; // xmm2
  __m128 v249; // xmm0
  __m128 v250; // xmm1
  __m128 v251; // xmm5
  __m128 v252; // xmm6
  __m128 v253; // xmm4
  __m128 v254; // xmm3
  __m128 v255; // xmm2
  __m128 v256; // xmm3
  __int64 v257; // rax
  __int64 v258; // rax
  __m128 v259; // xmm3
  __m128 *v260; // rcx
  __m128 v261; // xmm2
  __m128 v262; // xmm1
  __m128 v263; // xmm10
  __m128 v264; // xmm1
  __m128 v265; // xmm9
  __m128 v266; // xmm1
  __m128 v267; // xmm3
  __m128 v268; // xmm1
  __m128 v269; // xmm2
  __int64 v270; // rcx
  hkSolverStepTemp temp; // [rsp+40h] [rbp-98h] BYREF
  __int64 v272; // [rsp+60h] [rbp-78h]
  __int64 v273; // [rsp+68h] [rbp-70h]
  hkpVelocityAccumulator mA; // [rsp+70h] [rbp-68h] BYREF
  __int64 v275; // [rsp+F0h] [rbp+18h]
  __int64 v276; // [rsp+F8h] [rbp+20h]
  __int64 v277; // [rsp+100h] [rbp+28h]
  __int64 v278; // [rsp+108h] [rbp+30h]
  __int64 v279; // [rsp+110h] [rbp+38h]
  __int64 v280; // [rsp+118h] [rbp+40h]
  __int64 v281; // [rsp+120h] [rbp+48h]
  __int64 v282; // [rsp+128h] [rbp+50h]
  __int64 v283; // [rsp+130h] [rbp+58h]
  __int64 v284; // [rsp+138h] [rbp+60h]
  __int64 v285; // [rsp+140h] [rbp+68h]
  __m128 v286; // [rsp+148h] [rbp+70h]
  __m128 v287; // [rsp+158h] [rbp+80h]
  __m128 v288; // [rsp+168h] [rbp+90h]
  __m128 v289; // [rsp+178h] [rbp+A0h]
  __int128 v290; // [rsp+188h] [rbp+B0h]
  __m128 v291; // [rsp+198h] [rbp+C0h]
  __m128 v292; // [rsp+1A8h] [rbp+D0h]
  __m128 v293; // [rsp+1B8h] [rbp+E0h]
  __m128 v294; // [rsp+1C8h] [rbp+F0h]
  __m128 v295; // [rsp+1D8h] [rbp+100h]
  __m128 v296; // [rsp+1E8h] [rbp+110h]
  __m128 v297; // [rsp+1F8h] [rbp+120h]
  float v298; // [rsp+2C0h] [rbp+1E8h]
  float vars0; // [rsp+2D0h] [rbp+1F8h]

  v4 = (int)*schemas;
  v7 = schemas;
  temp.m_intregratePositionFactor = 0i64;
  temp.m_currentStep.m_storage = 0;
  if ( v4 )
  {
    if ( v4 != 2 )
      goto LABEL_4;
    v9 = (hkpVelocityAccumulator *)&mA.m_scratch1.m_quad.m128_u16[4];
    mB = &mA;
    mA.m_scratch1.m_quad.m128_u64[1] = __PAIR64__(
                                         _mm_cvtsi128_si32(_mm_srli_si128((__m128i)0i64, 4)),
                                         _mm_cvtsi128_si32((__m128i)0i64));
    mA.m_scratch2.m_quad.m128_u64[1] = mA.m_scratch1.m_quad.m128_u64[1];
    mA.m_scratch3.m_quad.m128_u64[1] = mA.m_scratch1.m_quad.m128_u64[1];
    v290 = 0i64;
    mA.m_scratch2.m_quad.m128_u64[0] = __PAIR64__(
                                         _mm_cvtsi128_si32(_mm_srli_si128((__m128i)0i64, 12)),
                                         _mm_cvtsi128_si32(_mm_srli_si128((__m128i)0i64, 8)));
    mA.m_scratch3.m_quad.m128_u64[0] = mA.m_scratch2.m_quad.m128_u64[0];
    v275 = mA.m_scratch2.m_quad.m128_i64[0];
    v276 = mA.m_scratch1.m_quad.m128_i64[1];
    v277 = mA.m_scratch2.m_quad.m128_i64[0];
    v278 = mA.m_scratch1.m_quad.m128_i64[1];
    v279 = mA.m_scratch2.m_quad.m128_i64[0];
    v280 = mA.m_scratch1.m_quad.m128_i64[1];
    v281 = mA.m_scratch2.m_quad.m128_i64[0];
    v282 = mA.m_scratch1.m_quad.m128_i64[1];
    v283 = mA.m_scratch2.m_quad.m128_i64[0];
    v284 = mA.m_scratch1.m_quad.m128_i64[1];
    v285 = mA.m_scratch2.m_quad.m128_i64[0];
    *((_DWORD *)&mA.m_gravityFactor + 1) = mA.m_scratch2.m_quad.m128_i32[1];
    temp.m_intregratePositionFactor.m_real.m128_u64[1] = mA.m_scratch1.m_quad.m128_u64[1];
    v272 = mA.m_scratch2.m_quad.m128_i64[0];
    v273 = mA.m_scratch1.m_quad.m128_i64[1];
    *(_QWORD *)&mA.m_type.m_storage = mA.m_scratch2.m_quad.m128_u64[0];
    LODWORD(mA.m_gravityFactor) = mA.m_scratch1.m_quad.m128_i32[2];
    mA.m_linearVel.m_quad.m128_u64[0] = mA.m_scratch2.m_quad.m128_u64[0];
    mA.m_linearVel.m_quad.m128_u64[1] = mA.m_scratch1.m_quad.m128_u64[1];
    mA.m_angularVel.m_quad.m128_u64[0] = mA.m_scratch2.m_quad.m128_u64[0];
    mA.m_angularVel.m_quad.m128_u64[1] = mA.m_scratch1.m_quad.m128_u64[1];
    mA.m_invMasses.m_quad.m128_u64[0] = mA.m_scratch2.m_quad.m128_u64[0];
    mA.m_invMasses.m_quad.m128_u64[1] = mA.m_scratch1.m_quad.m128_u64[1];
    mA.m_scratch0.m_quad.m128_u64[0] = mA.m_scratch2.m_quad.m128_u64[0];
    mA.m_scratch0.m_quad.m128_u64[1] = mA.m_scratch1.m_quad.m128_u64[1];
    mA.m_scratch1.m_quad.m128_u64[0] = mA.m_scratch2.m_quad.m128_u64[0];
    while ( 1 )
    {
      switch ( (unsigned __int8)*v7 )
      {
        case 0u:
          return;
        case 1u:
          goto LABEL_4;
        case 2u:
          v7 += *(_QWORD *)&v7[8];
          continue;
        case 3u:
          v7 += 16;
          continue;
        case 5u:
          do
          {
            v235 = *(__m128 *)v7;
            v236 = *(__m128 *)&v7[16];
            v7 += 48;
            v237 = _mm_add_ps(
                     _mm_mul_ps(v235, _mm_sub_ps(v9->m_linearVel.m_quad, mB->m_linearVel.m_quad)),
                     _mm_add_ps(
                       _mm_mul_ps(mB->m_angularVel.m_quad, *(__m128 *)&v7[-16]),
                       _mm_mul_ps(v236, v9->m_angularVel.m_quad)));
            v238 = _mm_mul_ps(
                     _mm_shuffle_ps(v236, v236, 255),
                     _mm_sub_ps(
                       _mm_shuffle_ps(v235, v235, 255),
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v237, v237, 85), _mm_shuffle_ps(v237, v237, 0)),
                         _mm_shuffle_ps(v237, v237, 170))));
            v239 = _mm_mul_ps(v9->m_invMasses.m_quad, v238);
            v240 = _mm_mul_ps(mB->m_invMasses.m_quad, v238);
            v9->m_linearVel.m_quad = _mm_add_ps(
                                       _mm_mul_ps(_mm_shuffle_ps(v239, v239, 255), v235),
                                       v9->m_linearVel.m_quad);
            mB->m_linearVel.m_quad = _mm_sub_ps(
                                       mB->m_linearVel.m_quad,
                                       _mm_mul_ps(_mm_shuffle_ps(v240, v240, 255), v235));
            v241 = _mm_mul_ps(v240, *(__m128 *)&v7[-16]);
            v242 = _mm_shuffle_ps((__m128)LODWORD(tmp->m_impulseApplied), (__m128)LODWORD(tmp->m_impulseApplied), 0).m128_f32[0]
                 + v238.m128_f32[0];
            v9->m_angularVel.m_quad = _mm_add_ps(v9->m_angularVel.m_quad, _mm_mul_ps(v239, *(__m128 *)&v7[-32]));
            mB->m_angularVel.m_quad = _mm_add_ps(mB->m_angularVel.m_quad, v241);
            tmp->m_impulseApplied = v242;
            tmp += (unsigned __int8)hkpJacobianSchema::s_schemaNumSolverElemTemps[*(_BYTE *)&v7[-48]];
          }
          while ( *v7 == 5 );
          continue;
        case 6u:
          do
          {
            hkpAtomSolverFunctions::solve1dBilateralWithImpulseLimit<hkpVelocityAccumulator,hkpSolverInfo,hkSolverStepTemp>(
              info,
              &temp,
              (hkpJacobian1dBilateralSchema *)v7,
              v9,
              mB,
              tmp);
            v243 = (__int64)*v7;
            v7 += 48;
            tmp += (unsigned __int8)hkpJacobianSchema::s_schemaNumSolverElemTemps[v243];
          }
          while ( *v7 == 6 );
          continue;
        case 7u:
          do
          {
            hkpAtomSolverFunctions::solve1dBilateralUserTau<hkpVelocityAccumulator,hkpSolverInfo,hkSolverStepTemp>(
              info,
              &temp,
              (hkpJacobian1dBilateralUserTauSchema *)v7,
              v9,
              mB,
              tmp);
            v244 = (__int64)*v7;
            v7 += 64;
            tmp += (unsigned __int8)hkpJacobianSchema::s_schemaNumSolverElemTemps[v244];
          }
          while ( *v7 == 7 );
          continue;
        case 8u:
          do
          {
            hkpAtomSolverFunctions::solve1dLinLimits<hkpVelocityAccumulator,hkpSolverInfo,hkSolverStepTemp>(
              info,
              &temp,
              (hkpJacobian1dLinearLimitsSchema *)v7,
              v9,
              mB,
              tmp);
            v257 = (__int64)*v7;
            v7 += 64;
            tmp += (unsigned __int8)hkpJacobianSchema::s_schemaNumSolverElemTemps[v257];
          }
          while ( *v7 == 8 );
          continue;
        case 9u:
          do
          {
            v245 = *(__m128 *)&v7[16];
            v246 = *(__m128 *)v7;
            v7 += 64;
            v247 = _mm_add_ps(
                     _mm_mul_ps(v246, _mm_sub_ps(v9->m_linearVel.m_quad, mB->m_linearVel.m_quad)),
                     _mm_add_ps(
                       _mm_mul_ps(mB->m_angularVel.m_quad, *(__m128 *)&v7[-32]),
                       _mm_mul_ps(v245, v9->m_angularVel.m_quad)));
            v248 = (__m128i)_mm_mul_ps(
                              _mm_shuffle_ps(v245, v245, 255),
                              _mm_sub_ps(
                                _mm_shuffle_ps(v246, v246, 255),
                                _mm_add_ps(
                                  _mm_add_ps(_mm_shuffle_ps(v247, v247, 85), _mm_shuffle_ps(v247, v247, 0)),
                                  _mm_shuffle_ps(v247, v247, 170))));
            v289 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v248, 1u), 1u);
            v249 = _mm_rcp_ps(v289);
            v250 = _mm_shuffle_ps((__m128)*(_DWORD *)&v7[-16], (__m128)*(_DWORD *)&v7[-16], 0);
            v251 = _mm_cmplt_ps(v250, v289);
            v252 = _mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v248, 0x1Fu), 0x1Fu), _mm_min_ps(v289, v250));
            v291 = _mm_or_ps(
                     _mm_andnot_ps(v251, query.m_quad),
                     _mm_and_ps(
                       _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v289, v249)), v249), v250),
                       v251));
            tmp[1].m_impulseApplied = v291.m128_f32[0];
            v253 = _mm_mul_ps(v9->m_invMasses.m_quad, v252);
            v254 = _mm_mul_ps(mB->m_invMasses.m_quad, v252);
            v255 = _mm_mul_ps(_mm_shuffle_ps(v254, v254, 255), *(__m128 *)&v7[-64]);
            v9->m_linearVel.m_quad = _mm_add_ps(
                                       v9->m_linearVel.m_quad,
                                       _mm_mul_ps(_mm_shuffle_ps(v253, v253, 255), *(__m128 *)&v7[-64]));
            mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, v255);
            v256 = _mm_mul_ps(v254, *(__m128 *)&v7[-32]);
            v249.m128_f32[0] = _mm_shuffle_ps(
                                 (__m128)LODWORD(tmp->m_impulseApplied),
                                 (__m128)LODWORD(tmp->m_impulseApplied),
                                 0).m128_f32[0];
            v9->m_angularVel.m_quad = _mm_add_ps(_mm_mul_ps(v253, *(__m128 *)&v7[-48]), v9->m_angularVel.m_quad);
            mB->m_angularVel.m_quad = _mm_add_ps(v256, mB->m_angularVel.m_quad);
            tmp->m_impulseApplied = v249.m128_f32[0] + v252.m128_f32[0];
            tmp += (unsigned __int8)hkpJacobianSchema::s_schemaNumSolverElemTemps[*(_BYTE *)&v7[-64]];
          }
          while ( *v7 == 9 );
          continue;
        case 0xAu:
          do
          {
            hkpAtomSolverFunctions::solve1dLinearMotor<hkpVelocityAccumulator,hkpSolverInfo,hkSolverStepTemp>(
              0i64,
              info,
              &temp,
              (hkpJacobian1dLinearMotorSchema *)v7,
              v9,
              mB,
              tmp,
              0i64);
            v258 = (__int64)*v7;
            v7 += 80;
            tmp += (unsigned __int8)hkpJacobianSchema::s_schemaNumSolverElemTemps[v258];
          }
          while ( *v7 == 10 );
          continue;
        case 0xBu:
          hkpAtomSolverFunctions::solvePulley<hkpVelocityAccumulator,hkpSolverInfo,hkSolverStepTemp>(
            info,
            &temp,
            (hkpJacobian1dPulleySchema *)v7,
            v9,
            mB,
            tmp++);
          v7 += 64;
          continue;
        case 0xCu:
          do
          {
            v229 = *(__m128 *)v7;
            v230 = *(__m128 *)&v7[16];
            v7 += 32;
            v231 = _mm_add_ps(_mm_mul_ps(v229, v9->m_angularVel.m_quad), _mm_mul_ps(v230, mB->m_angularVel.m_quad));
            v232 = _mm_mul_ps(
                     _mm_shuffle_ps(v229, v229, 255),
                     _mm_sub_ps(
                       _mm_shuffle_ps(v230, v230, 255),
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v231, v231, 85), _mm_shuffle_ps(v231, v231, 0)),
                         _mm_shuffle_ps(v231, v231, 170))));
            v233 = _mm_shuffle_ps((__m128)LODWORD(tmp->m_impulseApplied), (__m128)LODWORD(tmp->m_impulseApplied), 0).m128_f32[0]
                 + v232.m128_f32[0];
            v234 = _mm_mul_ps(_mm_mul_ps(v232, mB->m_invMasses.m_quad), v230);
            v9->m_angularVel.m_quad = _mm_add_ps(
                                        _mm_mul_ps(_mm_mul_ps(v232, v9->m_invMasses.m_quad), v229),
                                        v9->m_angularVel.m_quad);
            mB->m_angularVel.m_quad = _mm_add_ps(v234, mB->m_angularVel.m_quad);
            tmp->m_impulseApplied = v233;
            tmp += (unsigned __int8)hkpJacobianSchema::s_schemaNumSolverElemTemps[*(_BYTE *)&v7[-32]];
          }
          while ( *v7 == 12 );
          continue;
        case 0xDu:
          do
          {
            v204 = *(__m128 *)&v7[16];
            v205 = *(__m128 *)v7;
            v206 = _mm_shuffle_ps((__m128)*(_DWORD *)&v7[40], (__m128)*(_DWORD *)&v7[40], 0);
            v207 = v204;
            v208 = _mm_shuffle_ps(v205, v205, 255);
            v209 = _mm_add_ps(
                     _mm_mul_ps(
                       _mm_mul_ps(
                         _mm_shuffle_ps(
                           info->m_invIntegrateVelocityFactor.m_quad,
                           info->m_invIntegrateVelocityFactor.m_quad,
                           0),
                         v206),
                       _mm_add_ps(
                         _mm_mul_ps(v204, mB->m_scratch1.m_quad),
                         _mm_mul_ps(*(__m128 *)v7, v9->m_scratch1.m_quad))),
                     _mm_mul_ps(
                       _mm_add_ps(
                         _mm_mul_ps(v204, _mm_sub_ps(mB->m_angularVel.m_quad, mB->m_scratch1.m_quad)),
                         _mm_mul_ps(*(__m128 *)v7, _mm_sub_ps(v9->m_angularVel.m_quad, v9->m_scratch1.m_quad))),
                       _mm_shuffle_ps((__m128)LODWORD(info->m_damping), (__m128)LODWORD(info->m_damping), 0)));
            v210 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v209, v209, 85), _mm_shuffle_ps(v209, v209, 0)),
                     _mm_shuffle_ps(v209, v209, 170));
            v211 = _mm_shuffle_ps((__m128)LODWORD(tmp->m_impulseApplied), (__m128)LODWORD(tmp->m_impulseApplied), 0).m128_f32[0];
            v212 = _mm_sub_ps(_mm_mul_ps(v206, _mm_shuffle_ps(v204, v204, 255)), v210);
            v213 = _mm_mul_ps(
                     _mm_sub_ps(v212, _mm_shuffle_ps((__m128)*(_DWORD *)&v7[32], (__m128)*(_DWORD *)&v7[32], 0)),
                     v208);
            if ( v213.m128_f32[0] <= (float)(0.0 - v211) )
            {
              v215 = _mm_mul_ps(
                       _mm_sub_ps(v212, _mm_shuffle_ps((__m128)*(_DWORD *)&v7[36], (__m128)*(_DWORD *)&v7[36], 0)),
                       v208);
              if ( v215.m128_f32[0] < (float)(0.0 - v211) )
              {
                v216 = _mm_mul_ps(mB->m_invMasses.m_quad, v215);
                v9->m_angularVel.m_quad = _mm_add_ps(
                                            _mm_mul_ps(_mm_mul_ps(v9->m_invMasses.m_quad, v215), v205),
                                            v9->m_angularVel.m_quad);
                mB->m_angularVel.m_quad = _mm_add_ps(_mm_mul_ps(v216, v207), mB->m_angularVel.m_quad);
                tmp->m_impulseApplied = v215.m128_f32[0] + v211;
              }
            }
            else
            {
              v214 = _mm_mul_ps(_mm_mul_ps(mB->m_invMasses.m_quad, v213), v207);
              v9->m_angularVel.m_quad = _mm_add_ps(
                                          _mm_mul_ps(_mm_mul_ps(v9->m_invMasses.m_quad, v213), v205),
                                          v9->m_angularVel.m_quad);
              mB->m_angularVel.m_quad = _mm_add_ps(v214, mB->m_angularVel.m_quad);
              tmp->m_impulseApplied = v211 + v213.m128_f32[0];
            }
            v217 = (__int64)*v7;
            v7 += 48;
            tmp += (unsigned __int8)hkpJacobianSchema::s_schemaNumSolverElemTemps[v217];
          }
          while ( *v7 == 13 );
          continue;
        case 0xEu:
          do
          {
            v192 = *(__m128 *)v7;
            v193 = *(__m128 *)&v7[16];
            v194 = (__m128)*(unsigned int *)&v7[32];
            v7 += 48;
            v195 = _mm_shuffle_ps(v194, v194, 0);
            v196 = _mm_add_ps(_mm_mul_ps(v192, v9->m_angularVel.m_quad), _mm_mul_ps(v193, mB->m_angularVel.m_quad));
            v197 = (__m128i)_mm_mul_ps(
                              _mm_shuffle_ps(v192, v192, 255),
                              _mm_sub_ps(
                                _mm_shuffle_ps(v193, v193, 255),
                                _mm_add_ps(
                                  _mm_add_ps(_mm_shuffle_ps(v196, v196, 85), _mm_shuffle_ps(v196, v196, 0)),
                                  _mm_shuffle_ps(v196, v196, 170))));
            v198 = _mm_srli_epi32(v197, 0x1Fu);
            v199 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v197, 1u), 1u);
            v200 = _mm_cmplt_ps(v195, v199);
            v287 = v199;
            v201 = _mm_rcp_ps(v199);
            v202 = _mm_xor_ps((__m128)_mm_slli_epi32(v198, 0x1Fu), _mm_min_ps(v199, v195));
            v294 = _mm_or_ps(
                     _mm_andnot_ps(v200, query.m_quad),
                     _mm_and_ps(
                       _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v199, v201)), v201), v195),
                       v200));
            tmp[1].m_impulseApplied = v294.m128_f32[0];
            v199.m128_f32[0] = _mm_shuffle_ps(
                                 (__m128)LODWORD(tmp->m_impulseApplied),
                                 (__m128)LODWORD(tmp->m_impulseApplied),
                                 0).m128_f32[0]
                             + v202.m128_f32[0];
            v203 = _mm_mul_ps(_mm_mul_ps(mB->m_invMasses.m_quad, v202), *(__m128 *)&v7[-32]);
            v9->m_angularVel.m_quad = _mm_add_ps(
                                        _mm_mul_ps(_mm_mul_ps(v9->m_invMasses.m_quad, v202), *(__m128 *)&v7[-48]),
                                        v9->m_angularVel.m_quad);
            mB->m_angularVel.m_quad = _mm_add_ps(v203, mB->m_angularVel.m_quad);
            tmp->m_impulseApplied = v199.m128_f32[0];
            tmp += (unsigned __int8)hkpJacobianSchema::s_schemaNumSolverElemTemps[*(_BYTE *)&v7[-48]];
          }
          while ( *v7 == 14 );
          continue;
        case 0xFu:
          do
          {
            v218 = *(__m128 *)&v7[16];
            v219 = _mm_shuffle_ps((__m128)*(_DWORD *)&v7[44], (__m128)*(_DWORD *)&v7[44], 0);
            v220 = _mm_add_ps(
                     _mm_mul_ps(
                       _mm_mul_ps(
                         _mm_shuffle_ps(
                           info->m_invIntegrateVelocityFactor.m_quad,
                           info->m_invIntegrateVelocityFactor.m_quad,
                           0),
                         v219),
                       _mm_add_ps(
                         _mm_mul_ps(v218, mB->m_scratch1.m_quad),
                         _mm_mul_ps(*(__m128 *)v7, v9->m_scratch1.m_quad))),
                     _mm_mul_ps(
                       _mm_add_ps(
                         _mm_mul_ps(v218, _mm_sub_ps(mB->m_angularVel.m_quad, mB->m_scratch1.m_quad)),
                         _mm_mul_ps(*(__m128 *)v7, _mm_sub_ps(v9->m_angularVel.m_quad, v9->m_scratch1.m_quad))),
                       _mm_shuffle_ps((__m128)*(_DWORD *)&v7[48], (__m128)*(_DWORD *)&v7[48], 0)));
            v221 = _mm_mul_ps(
                     _mm_shuffle_ps(*(__m128 *)v7, *(__m128 *)v7, 255),
                     _mm_sub_ps(
                       _mm_mul_ps(
                         _mm_add_ps(
                           _mm_shuffle_ps(v218, v218, 255),
                           _mm_mul_ps(
                             _mm_shuffle_ps((__m128)*(_DWORD *)&v7[40], (__m128)*(_DWORD *)&v7[40], 0),
                             temp.m_intregratePositionFactor.m_real)),
                         v219),
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v220, v220, 85), _mm_shuffle_ps(v220, v220, 0)),
                         _mm_shuffle_ps(v220, v220, 170))));
            v222 = _mm_rcp_ps(v221);
            v286 = v221;
            v223 = _mm_shuffle_ps((__m128)*(_DWORD *)&v7[32], (__m128)*(_DWORD *)&v7[32], 0);
            v224 = _mm_shuffle_ps((__m128)*(_DWORD *)&v7[36], (__m128)*(_DWORD *)&v7[36], 0);
            v225 = _mm_cmplt_ps(v223, v221);
            v226 = _mm_cmplt_ps(v221, v224);
            v292 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v222, v221)), v222), v223);
            v288 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v222, v221)), v222), v224);
            LODWORD(tmp[1].m_impulseApplied) = _mm_andnot_ps(
                                                 v225,
                                                 _mm_or_ps(_mm_and_ps(v226, v288), _mm_andnot_ps(v226, query.m_quad))).m128_u32[0] | v225.m128_i32[0] & v292.m128_i32[0];
            v227 = _mm_cmplt_ps(v286, v223);
            v7 += 64;
            v286 = _mm_max_ps(v224, _mm_or_ps(_mm_andnot_ps(v227, v223), _mm_and_ps(v227, v286)));
            v227.m128_f32[0] = _mm_shuffle_ps(
                                 (__m128)LODWORD(tmp->m_impulseApplied),
                                 (__m128)LODWORD(tmp->m_impulseApplied),
                                 0).m128_f32[0]
                             + v286.m128_f32[0];
            v228 = _mm_mul_ps(_mm_mul_ps(mB->m_invMasses.m_quad, v286), *(__m128 *)&v7[-48]);
            v9->m_angularVel.m_quad = _mm_add_ps(
                                        _mm_mul_ps(_mm_mul_ps(v9->m_invMasses.m_quad, v286), *(__m128 *)&v7[-64]),
                                        v9->m_angularVel.m_quad);
            mB->m_angularVel.m_quad = _mm_add_ps(v228, mB->m_angularVel.m_quad);
            tmp->m_impulseApplied = v227.m128_f32[0];
            tmp += (unsigned __int8)hkpJacobianSchema::s_schemaNumSolverElemTemps[*(_BYTE *)&v7[-64]];
          }
          while ( *v7 == 15 );
          continue;
        case 0x10u:
          hkpAtomSolverFunctions::solveStableBallSocket<hkpVelocityAccumulator,hkpSolverInfo,hkSolverStepTemp>(
            info,
            &temp,
            (hkpStableBallSocketSchema *)v7,
            v9,
            mB,
            tmp);
          v7 += 64;
          tmp += 3;
          continue;
        case 0x12u:
          hkpAtomSolverFunctions::solveStableStiffSpring<hkpVelocityAccumulator,hkpSolverInfo,hkSolverStepTemp,hkpStableStiffSpringSchema>(
            info,
            &temp,
            (hkpStableStiffSpringSchema *)v7,
            v9,
            mB,
            tmp);
          v7 += 48;
          ++tmp;
          continue;
        case 0x14u:
        case 0x15u:
          do
          {
            v11 = *(__m128 *)v7;
            v12 = *(__m128 *)&v7[16];
            v7 += 48;
            v13 = _mm_add_ps(
                    _mm_mul_ps(v11, _mm_sub_ps(v9->m_linearVel.m_quad, mB->m_linearVel.m_quad)),
                    _mm_add_ps(
                      _mm_mul_ps(mB->m_angularVel.m_quad, *(__m128 *)&v7[-16]),
                      _mm_mul_ps(v12, v9->m_angularVel.m_quad)));
            v14 = _mm_max_ps(
                    _mm_sub_ps(
                      (__m128)0i64,
                      _mm_shuffle_ps((__m128)LODWORD(tmp->m_impulseApplied), (__m128)LODWORD(tmp->m_impulseApplied), 0)),
                    _mm_mul_ps(
                      _mm_shuffle_ps(v12, v12, 255),
                      _mm_sub_ps(
                        _mm_shuffle_ps(v11, v11, 255),
                        _mm_add_ps(
                          _mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)),
                          _mm_shuffle_ps(v13, v13, 170)))));
            v15 = _mm_mul_ps(v9->m_invMasses.m_quad, v14);
            v16 = _mm_mul_ps(mB->m_invMasses.m_quad, v14);
            v9->m_linearVel.m_quad = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v15, v15, 255), v11), v9->m_linearVel.m_quad);
            mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, _mm_mul_ps(_mm_shuffle_ps(v16, v16, 255), v11));
            v17 = _mm_mul_ps(v16, *(__m128 *)&v7[-16]);
            v18 = _mm_shuffle_ps((__m128)LODWORD(tmp->m_impulseApplied), (__m128)LODWORD(tmp->m_impulseApplied), 0).m128_f32[0]
                + v14.m128_f32[0];
            v9->m_angularVel.m_quad = _mm_add_ps(v9->m_angularVel.m_quad, _mm_mul_ps(v15, *(__m128 *)&v7[-32]));
            mB->m_angularVel.m_quad = _mm_add_ps(mB->m_angularVel.m_quad, v17);
            tmp->m_impulseApplied = v18;
            tmp += (unsigned __int8)hkpJacobianSchema::s_schemaNumSolverElemTemps[*(_BYTE *)&v7[-48]];
          }
          while ( *v7 == 20 );
          continue;
        case 0x16u:
        case 0x17u:
          do
          {
            v19 = *(__m128 *)v7;
            v20 = *(__m128 *)&v7[16];
            v21 = *(__m128 *)&v7[32];
            v7 += 48;
            v22 = _mm_add_ps(
                    _mm_mul_ps(v19, _mm_sub_ps(v9->m_linearVel.m_quad, mB->m_linearVel.m_quad)),
                    _mm_add_ps(_mm_mul_ps(v21, mB->m_angularVel.m_quad), _mm_mul_ps(v20, v9->m_angularVel.m_quad)));
            v23 = _mm_shuffle_ps((__m128)LODWORD(tmp->m_impulseApplied), (__m128)LODWORD(tmp->m_impulseApplied), 0);
            v24 = _mm_min_ps(
                    _mm_sub_ps(_mm_shuffle_ps(v21, v21, 255), v23),
                    _mm_max_ps(
                      _mm_sub_ps((__m128)0i64, v23),
                      _mm_mul_ps(
                        _mm_shuffle_ps(v20, v20, 255),
                        _mm_sub_ps(
                          _mm_shuffle_ps(v19, v19, 255),
                          _mm_add_ps(
                            _mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)),
                            _mm_shuffle_ps(v22, v22, 170))))));
            v25 = _mm_mul_ps(v9->m_invMasses.m_quad, v24);
            v26 = _mm_mul_ps(mB->m_invMasses.m_quad, v24);
            v9->m_linearVel.m_quad = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v25, v25, 255), v19), v9->m_linearVel.m_quad);
            mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, _mm_mul_ps(_mm_shuffle_ps(v26, v26, 255), v19));
            v27 = _mm_mul_ps(v26, *(__m128 *)&v7[-16]);
            v24.m128_f32[0] = v24.m128_f32[0]
                            + _mm_shuffle_ps(
                                (__m128)LODWORD(tmp->m_impulseApplied),
                                (__m128)LODWORD(tmp->m_impulseApplied),
                                0).m128_f32[0];
            v9->m_angularVel.m_quad = _mm_add_ps(v9->m_angularVel.m_quad, _mm_mul_ps(v25, *(__m128 *)&v7[-32]));
            mB->m_angularVel.m_quad = _mm_add_ps(mB->m_angularVel.m_quad, v27);
            tmp->m_impulseApplied = v24.m128_f32[0];
            tmp += (unsigned __int8)hkpJacobianSchema::s_schemaNumSolverElemTemps[*(_BYTE *)&v7[-48]];
          }
          while ( *v7 == 22 );
          continue;
        case 0x18u:
        case 0x19u:
          v28 = _mm_sub_ps(v9->m_linearVel.m_quad, mB->m_linearVel.m_quad);
          v29 = _mm_add_ps(
                  _mm_mul_ps(*(__m128 *)v7, v28),
                  _mm_add_ps(
                    _mm_mul_ps(mB->m_angularVel.m_quad, *(__m128 *)&v7[32]),
                    _mm_mul_ps(*(__m128 *)&v7[16], v9->m_angularVel.m_quad)));
          v30 = _mm_sub_ps(
                  _mm_shuffle_ps(*(__m128 *)v7, *(__m128 *)v7, 255),
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v29, v29, 85), _mm_shuffle_ps(v29, v29, 0)),
                    _mm_shuffle_ps(v29, v29, 170)));
          v31 = _mm_add_ps(
                  _mm_mul_ps(*(__m128 *)&v7[48], v28),
                  _mm_add_ps(
                    _mm_mul_ps(mB->m_angularVel.m_quad, *(__m128 *)&v7[80]),
                    _mm_mul_ps(*(__m128 *)&v7[64], v9->m_angularVel.m_quad)));
          v32 = _mm_sub_ps(
                  _mm_shuffle_ps(*(__m128 *)&v7[48], *(__m128 *)&v7[48], 255),
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v31, v31, 85), _mm_shuffle_ps(v31, v31, 0)),
                    _mm_shuffle_ps(v31, v31, 170)));
          v33 = _mm_shuffle_ps((__m128)*(_DWORD *)&v7[96], (__m128)*(_DWORD *)&v7[96], 0);
          v34 = _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v7[32], *(__m128 *)&v7[32], 255), v30),
                  _mm_mul_ps(v33, v32));
          v35 = _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v7[80], *(__m128 *)&v7[80], 255), v32),
                  _mm_mul_ps(v33, v30));
          v36 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 80);
          v293 = _mm_xor_ps(v36, (__m128)*(unsigned __int64 *)&tmp->m_impulseApplied);
          v37 = _mm_shuffle_ps(v293, v293, 0);
          LODWORD(v38) = _mm_shuffle_ps(v293, v293, 85).m128_u32[0];
          if ( v34.m128_f32[0] <= v37.m128_f32[0] )
          {
            v49 = _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v7[64], *(__m128 *)&v7[64], 255), v32);
            if ( v49.m128_f32[0] > v38 )
            {
              v55 = _mm_mul_ps(v9->m_invMasses.m_quad, v49);
              v56 = _mm_mul_ps(mB->m_invMasses.m_quad, v49);
              v57 = _mm_mul_ps(_mm_shuffle_ps(v56, v56, 255), *(__m128 *)&v7[48]);
              v9->m_linearVel.m_quad = _mm_add_ps(
                                         v9->m_linearVel.m_quad,
                                         _mm_mul_ps(_mm_shuffle_ps(v55, v55, 255), *(__m128 *)&v7[48]));
              mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, v57);
              v58 = _mm_mul_ps(v56, *(__m128 *)&v7[80]);
              v59 = _mm_shuffle_ps(
                      (__m128)LODWORD(tmp[1].m_impulseApplied),
                      (__m128)LODWORD(tmp[1].m_impulseApplied),
                      0).m128_f32[0]
                  + v49.m128_f32[0];
              v9->m_angularVel.m_quad = _mm_add_ps(_mm_mul_ps(v55, *(__m128 *)&v7[64]), v9->m_angularVel.m_quad);
              mB->m_angularVel.m_quad = _mm_add_ps(mB->m_angularVel.m_quad, v58);
              tmp[1].m_impulseApplied = v59;
              goto LABEL_18;
            }
LABEL_16:
            v50 = _mm_max_ps(v37, _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v7[16], *(__m128 *)&v7[16], 255), v30));
            v51 = _mm_mul_ps(v9->m_invMasses.m_quad, v50);
            v52 = _mm_mul_ps(mB->m_invMasses.m_quad, v50);
            v53 = _mm_mul_ps(_mm_shuffle_ps(v52, v52, 255), *(__m128 *)v7);
            v9->m_linearVel.m_quad = _mm_add_ps(
                                       v9->m_linearVel.m_quad,
                                       _mm_mul_ps(_mm_shuffle_ps(v51, v51, 255), *(__m128 *)v7));
            mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, v53);
            v54 = _mm_mul_ps(v52, *(__m128 *)&v7[32]);
            v53.m128_f32[0] = _mm_shuffle_ps(
                                (__m128)LODWORD(tmp->m_impulseApplied),
                                (__m128)LODWORD(tmp->m_impulseApplied),
                                0).m128_f32[0]
                            + v50.m128_f32[0];
            v9->m_angularVel.m_quad = _mm_add_ps(v9->m_angularVel.m_quad, _mm_mul_ps(v51, *(__m128 *)&v7[16]));
            mB->m_angularVel.m_quad = _mm_add_ps(mB->m_angularVel.m_quad, v54);
            tmp->m_impulseApplied = v53.m128_f32[0];
            goto LABEL_18;
          }
          if ( v35.m128_f32[0] <= v38 )
            goto LABEL_16;
          v39 = _mm_mul_ps(v34, v9->m_invMasses.m_quad);
          v40 = _mm_mul_ps(v34, mB->m_invMasses.m_quad);
          v41 = _mm_mul_ps(_mm_shuffle_ps(v40, v40, 255), *(__m128 *)v7);
          v9->m_linearVel.m_quad = _mm_add_ps(
                                     v9->m_linearVel.m_quad,
                                     _mm_mul_ps(_mm_shuffle_ps(v39, v39, 255), *(__m128 *)v7));
          mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, v41);
          v42 = _mm_mul_ps(v40, *(__m128 *)&v7[32]);
          v43 = _mm_shuffle_ps((__m128)LODWORD(tmp->m_impulseApplied), (__m128)LODWORD(tmp->m_impulseApplied), 0).m128_f32[0];
          v9->m_angularVel.m_quad = _mm_add_ps(_mm_mul_ps(v39, *(__m128 *)&v7[16]), v9->m_angularVel.m_quad);
          mB->m_angularVel.m_quad = _mm_add_ps(v42, mB->m_angularVel.m_quad);
          tmp->m_impulseApplied = v34.m128_f32[0] + v43;
          v44 = _mm_mul_ps(v35, v9->m_invMasses.m_quad);
          v45 = _mm_mul_ps(v35, mB->m_invMasses.m_quad);
          v46 = _mm_mul_ps(_mm_shuffle_ps(v45, v45, 255), *(__m128 *)&v7[48]);
          v9->m_linearVel.m_quad = _mm_add_ps(
                                     v9->m_linearVel.m_quad,
                                     _mm_mul_ps(_mm_shuffle_ps(v44, v44, 255), *(__m128 *)&v7[48]));
          mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, v46);
          v47 = _mm_mul_ps(v45, *(__m128 *)&v7[80]);
          v48 = v35.m128_f32[0]
              + _mm_shuffle_ps((__m128)LODWORD(tmp[1].m_impulseApplied), (__m128)LODWORD(tmp[1].m_impulseApplied), 0).m128_f32[0];
          v9->m_angularVel.m_quad = _mm_add_ps(_mm_mul_ps(v44, *(__m128 *)&v7[64]), v9->m_angularVel.m_quad);
          mB->m_angularVel.m_quad = _mm_add_ps(mB->m_angularVel.m_quad, v47);
          tmp[1].m_impulseApplied = v48;
LABEL_18:
          v7 += 112;
          tmp += 2;
          if ( *v7 == 24 )
          {
            v60 = _mm_sub_ps(v9->m_linearVel.m_quad, mB->m_linearVel.m_quad);
            m_quad = mB->m_angularVel.m_quad;
            v62 = _mm_add_ps(
                    _mm_mul_ps(*(__m128 *)v7, v60),
                    _mm_add_ps(
                      _mm_mul_ps(m_quad, *(__m128 *)&v7[32]),
                      _mm_mul_ps(*(__m128 *)&v7[16], v9->m_angularVel.m_quad)));
            v63 = _mm_sub_ps(
                    _mm_shuffle_ps(*(__m128 *)v7, *(__m128 *)v7, 255),
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v62, v62, 85), _mm_shuffle_ps(v62, v62, 0)),
                      _mm_shuffle_ps(v62, v62, 170)));
            v64 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(m_quad, *(__m128 *)&v7[80]),
                      _mm_mul_ps(*(__m128 *)&v7[64], v9->m_angularVel.m_quad)),
                    _mm_mul_ps(*(__m128 *)&v7[48], v60));
            v65 = _mm_sub_ps(
                    _mm_shuffle_ps(*(__m128 *)&v7[48], *(__m128 *)&v7[48], 255),
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v64, v64, 85), _mm_shuffle_ps(v64, v64, 0)),
                      _mm_shuffle_ps(v64, v64, 170)));
            v66 = _mm_shuffle_ps((__m128)*(_DWORD *)&v7[96], (__m128)*(_DWORD *)&v7[96], 0);
            v67 = _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v7[32], *(__m128 *)&v7[32], 255), v63),
                    _mm_mul_ps(v66, v65));
            v68 = _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v7[80], *(__m128 *)&v7[80], 255), v65),
                    _mm_mul_ps(v66, v63));
            v295 = _mm_xor_ps(v36, (__m128)*(unsigned __int64 *)&tmp->m_impulseApplied);
            v69 = _mm_shuffle_ps(v295, v295, 0);
            LODWORD(v70) = _mm_shuffle_ps(v295, v295, 85).m128_u32[0];
            if ( v67.m128_f32[0] <= v69.m128_f32[0] )
            {
              v80 = _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v7[64], *(__m128 *)&v7[64], 255), v65);
              if ( v80.m128_f32[0] > v70 )
              {
                v87 = _mm_mul_ps(v9->m_invMasses.m_quad, v80);
                v88 = _mm_mul_ps(mB->m_invMasses.m_quad, v80);
                v89 = _mm_mul_ps(_mm_shuffle_ps(v88, v88, 255), *(__m128 *)&v7[48]);
                v9->m_linearVel.m_quad = _mm_add_ps(
                                           v9->m_linearVel.m_quad,
                                           _mm_mul_ps(_mm_shuffle_ps(v87, v87, 255), *(__m128 *)&v7[48]));
                mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, v89);
                v90 = _mm_mul_ps(v88, *(__m128 *)&v7[80]);
                v91 = _mm_shuffle_ps(
                        (__m128)LODWORD(tmp[1].m_impulseApplied),
                        (__m128)LODWORD(tmp[1].m_impulseApplied),
                        0).m128_f32[0];
                v9->m_angularVel.m_quad = _mm_add_ps(_mm_mul_ps(v87, *(__m128 *)&v7[64]), v9->m_angularVel.m_quad);
                mB->m_angularVel.m_quad = _mm_add_ps(v90, mB->m_angularVel.m_quad);
                tmp[1].m_impulseApplied = v80.m128_f32[0] + v91;
                goto LABEL_25;
              }
LABEL_23:
              v81 = _mm_max_ps(v69, _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v7[16], *(__m128 *)&v7[16], 255), v63));
              v82 = _mm_mul_ps(v9->m_invMasses.m_quad, v81);
              v83 = _mm_mul_ps(mB->m_invMasses.m_quad, v81);
              v84 = _mm_mul_ps(_mm_shuffle_ps(v83, v83, 255), *(__m128 *)v7);
              v9->m_linearVel.m_quad = _mm_add_ps(
                                         v9->m_linearVel.m_quad,
                                         _mm_mul_ps(_mm_shuffle_ps(v82, v82, 255), *(__m128 *)v7));
              mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, v84);
              v85 = _mm_mul_ps(v83, *(__m128 *)&v7[32]);
              v86 = _mm_shuffle_ps((__m128)LODWORD(tmp->m_impulseApplied), (__m128)LODWORD(tmp->m_impulseApplied), 0).m128_f32[0];
              v9->m_angularVel.m_quad = _mm_add_ps(_mm_mul_ps(v82, *(__m128 *)&v7[16]), v9->m_angularVel.m_quad);
              mB->m_angularVel.m_quad = _mm_add_ps(v85, mB->m_angularVel.m_quad);
              tmp->m_impulseApplied = v81.m128_f32[0] + v86;
              goto LABEL_25;
            }
            if ( v68.m128_f32[0] <= v70 )
              goto LABEL_23;
            v71 = _mm_mul_ps(v9->m_invMasses.m_quad, v67);
            v72 = _mm_mul_ps(mB->m_invMasses.m_quad, v67);
            v73 = _mm_mul_ps(_mm_shuffle_ps(v72, v72, 255), *(__m128 *)v7);
            v9->m_linearVel.m_quad = _mm_add_ps(
                                       v9->m_linearVel.m_quad,
                                       _mm_mul_ps(_mm_shuffle_ps(v71, v71, 255), *(__m128 *)v7));
            mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, v73);
            v74 = _mm_mul_ps(v72, *(__m128 *)&v7[32]);
            v73.m128_f32[0] = _mm_shuffle_ps(
                                (__m128)LODWORD(tmp->m_impulseApplied),
                                (__m128)LODWORD(tmp->m_impulseApplied),
                                0).m128_f32[0];
            v9->m_angularVel.m_quad = _mm_add_ps(v9->m_angularVel.m_quad, _mm_mul_ps(v71, *(__m128 *)&v7[16]));
            mB->m_angularVel.m_quad = _mm_add_ps(mB->m_angularVel.m_quad, v74);
            tmp->m_impulseApplied = v73.m128_f32[0] + v67.m128_f32[0];
            v75 = _mm_mul_ps(v9->m_invMasses.m_quad, v68);
            v76 = _mm_mul_ps(mB->m_invMasses.m_quad, v68);
            v77 = _mm_mul_ps(_mm_shuffle_ps(v76, v76, 255), *(__m128 *)&v7[48]);
            v9->m_linearVel.m_quad = _mm_add_ps(
                                       v9->m_linearVel.m_quad,
                                       _mm_mul_ps(_mm_shuffle_ps(v75, v75, 255), *(__m128 *)&v7[48]));
            mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, v77);
            v78 = _mm_mul_ps(v76, *(__m128 *)&v7[80]);
            v79 = _mm_shuffle_ps((__m128)LODWORD(tmp[1].m_impulseApplied), (__m128)LODWORD(tmp[1].m_impulseApplied), 0).m128_f32[0];
            v9->m_angularVel.m_quad = _mm_add_ps(_mm_mul_ps(v75, *(__m128 *)&v7[64]), v9->m_angularVel.m_quad);
            mB->m_angularVel.m_quad = _mm_add_ps(v78, mB->m_angularVel.m_quad);
            tmp[1].m_impulseApplied = v79 + v68.m128_f32[0];
LABEL_25:
            v7 += 112;
            tmp += 2;
            if ( *v7 == 27 )
            {
LABEL_26:
              v92 = v9->m_angularVel.m_quad;
              v93 = _mm_shuffle_ps((__m128)*(_DWORD *)&v7[132], (__m128)*(_DWORD *)&v7[132], 0);
              v94 = _mm_sub_ps(v9->m_linearVel.m_quad, mB->m_linearVel.m_quad);
              v95 = _mm_add_ps(
                      _mm_mul_ps(*(__m128 *)v7, v94),
                      _mm_add_ps(
                        _mm_mul_ps(mB->m_angularVel.m_quad, *(__m128 *)&v7[32]),
                        _mm_mul_ps(*(__m128 *)&v7[16], v92)));
              v96 = _mm_sub_ps(
                      _mm_shuffle_ps(*(__m128 *)v7, *(__m128 *)v7, 255),
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v95, v95, 85), _mm_shuffle_ps(v95, v95, 0)),
                        _mm_shuffle_ps(v95, v95, 170)));
              v97 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(mB->m_angularVel.m_quad, *(__m128 *)&v7[80]),
                        _mm_mul_ps(*(__m128 *)&v7[64], v92)),
                      _mm_mul_ps(*(__m128 *)&v7[48], v94));
              v98 = _mm_sub_ps(
                      _mm_shuffle_ps(*(__m128 *)&v7[48], *(__m128 *)&v7[48], 255),
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v97, v97, 85), _mm_shuffle_ps(v97, v97, 0)),
                        _mm_shuffle_ps(v97, v97, 170)));
              v99 = _mm_add_ps(
                      _mm_mul_ps(*(__m128 *)&v7[96], v92),
                      _mm_mul_ps(*(__m128 *)&v7[112], mB->m_angularVel.m_quad));
              v100 = _mm_mul_ps(
                       _mm_shuffle_ps(*(__m128 *)&v7[96], *(__m128 *)&v7[96], 255),
                       _mm_sub_ps(
                         _mm_shuffle_ps(*(__m128 *)&v7[112], *(__m128 *)&v7[112], 255),
                         _mm_add_ps(
                           _mm_add_ps(_mm_shuffle_ps(v99, v99, 85), _mm_shuffle_ps(v99, v99, 0)),
                           _mm_shuffle_ps(v99, v99, 170))));
              v101 = _mm_shuffle_ps((__m128)*(_DWORD *)&v7[128], (__m128)*(_DWORD *)&v7[128], 0);
              v102 = _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v7[80], *(__m128 *)&v7[80], 255), v98),
                       _mm_mul_ps(v101, v96));
              v103 = _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v7[32], *(__m128 *)&v7[32], 255), v96),
                       _mm_mul_ps(v101, v98));
              v104 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v102, v102), _mm_mul_ps(v103, v103)), _mm_mul_ps(v100, v100));
              v105 = _mm_cmplt_ps(_mm_mul_ps(v93, v93), v104);
              v297 = v104;
              v106 = _mm_rsqrt_ps(v104);
              v107 = _mm_mul_ps(
                       _mm_mul_ps(
                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v106, v104), v106)),
                         _mm_mul_ps(*(__m128 *)_xmm, v106)),
                       v93);
              v108 = _mm_or_ps(_mm_and_ps(_mm_mul_ps(v107, v103), v105), _mm_andnot_ps(v105, v103));
              v109 = _mm_or_ps(_mm_and_ps(_mm_mul_ps(v107, v102), v105), _mm_andnot_ps(v105, v102));
              LODWORD(tmp[3].m_impulseApplied) = v107.m128_i32[0] & v105.m128_i32[0] | _mm_andnot_ps(v105, query.m_quad).m128_u32[0];
              v110 = _mm_mul_ps(v9->m_invMasses.m_quad, v108);
              v111 = _mm_mul_ps(
                       _mm_or_ps(_mm_and_ps(_mm_mul_ps(v107, v100), v105), _mm_andnot_ps(v105, v100)),
                       _mm_shuffle_ps((__m128)*(_DWORD *)&v7[136], (__m128)*(_DWORD *)&v7[136], 0));
              v112 = _mm_mul_ps(mB->m_invMasses.m_quad, v108);
              v113 = _mm_mul_ps(_mm_shuffle_ps(v112, v112, 255), *(__m128 *)v7);
              v9->m_linearVel.m_quad = _mm_add_ps(
                                         v9->m_linearVel.m_quad,
                                         _mm_mul_ps(_mm_shuffle_ps(v110, v110, 255), *(__m128 *)v7));
              mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, v113);
              v114 = _mm_mul_ps(v112, *(__m128 *)&v7[32]);
              v106.m128_f32[0] = _mm_shuffle_ps(
                                   (__m128)LODWORD(tmp->m_impulseApplied),
                                   (__m128)LODWORD(tmp->m_impulseApplied),
                                   0).m128_f32[0];
              v9->m_angularVel.m_quad = _mm_add_ps(_mm_mul_ps(v110, *(__m128 *)&v7[16]), v9->m_angularVel.m_quad);
              mB->m_angularVel.m_quad = _mm_add_ps(mB->m_angularVel.m_quad, v114);
              tmp->m_impulseApplied = v106.m128_f32[0] + v108.m128_f32[0];
              v115 = _mm_mul_ps(v9->m_invMasses.m_quad, v109);
              v116 = _mm_mul_ps(mB->m_invMasses.m_quad, v109);
              v117 = _mm_mul_ps(_mm_shuffle_ps(v116, v116, 255), *(__m128 *)&v7[48]);
              v9->m_linearVel.m_quad = _mm_add_ps(
                                         v9->m_linearVel.m_quad,
                                         _mm_mul_ps(_mm_shuffle_ps(v115, v115, 255), *(__m128 *)&v7[48]));
              mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, v117);
              v118 = _mm_mul_ps(v115, *(__m128 *)&v7[64]);
              v119 = _mm_mul_ps(v116, *(__m128 *)&v7[80]);
              m_impulseApplied_low = (__m128)LODWORD(tmp[1].m_impulseApplied);
              v7 += 160;
              tmp += 4;
              v9->m_angularVel.m_quad = _mm_add_ps(v9->m_angularVel.m_quad, v118);
              mB->m_angularVel.m_quad = _mm_add_ps(v119, mB->m_angularVel.m_quad);
              tmp[-3].m_impulseApplied = _mm_shuffle_ps(m_impulseApplied_low, m_impulseApplied_low, 0).m128_f32[0]
                                       + v109.m128_f32[0];
              v121 = _mm_shuffle_ps(
                       (__m128)LODWORD(tmp[-2].m_impulseApplied),
                       (__m128)LODWORD(tmp[-2].m_impulseApplied),
                       0).m128_f32[0]
                   + v111.m128_f32[0];
              v122 = _mm_mul_ps(_mm_mul_ps(mB->m_invMasses.m_quad, v111), *(__m128 *)&v7[-48]);
              v9->m_angularVel.m_quad = _mm_add_ps(
                                          _mm_mul_ps(_mm_mul_ps(v9->m_invMasses.m_quad, v111), *(__m128 *)&v7[-64]),
                                          v9->m_angularVel.m_quad);
              mB->m_angularVel.m_quad = _mm_add_ps(v122, mB->m_angularVel.m_quad);
              tmp[-2].m_impulseApplied = v121;
              if ( *v7 == 1 )
              {
LABEL_4:
                v9 = &accumulators[(unsigned __int64)*(_WORD *)&v7[4]];
                mB = &accumulators[(unsigned __int64)*(_WORD *)&v7[6]];
LABEL_5:
                v7 += 32;
              }
            }
          }
          break;
        case 0x1Au:
          goto LABEL_50;
        case 0x1Bu:
          goto LABEL_26;
        case 0x1Cu:
          hkpAtomSolverFunctions::solve2dRollingFriction<hkpVelocityAccumulator,hkpSolverInfo,hkSolverStepTemp>(
            info,
            &temp,
            (hkpJacobian2dRollingFrictionSchema *)v7,
            v9,
            mB,
            tmp);
          v164 = (__int64)*v7;
          v7 += 96;
          tmp += (unsigned __int8)hkpJacobianSchema::s_schemaNumSolverElemTemps[v164];
          v165 = (int)*v7;
          if ( v165 == 27 )
            goto LABEL_26;
          if ( v165 != 26 )
            continue;
LABEL_50:
          v166 = _mm_sub_ps(v9->m_linearVel.m_quad, mB->m_linearVel.m_quad);
          v167 = _mm_shuffle_ps((__m128)*(_DWORD *)&v7[100], (__m128)*(_DWORD *)&v7[100], 0);
          v168 = mB->m_angularVel.m_quad;
          v169 = _mm_add_ps(
                   _mm_mul_ps(*(__m128 *)v7, v166),
                   _mm_add_ps(
                     _mm_mul_ps(v168, *(__m128 *)&v7[32]),
                     _mm_mul_ps(*(__m128 *)&v7[16], v9->m_angularVel.m_quad)));
          v170 = _mm_sub_ps(
                   _mm_shuffle_ps(*(__m128 *)v7, *(__m128 *)v7, 255),
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v169, v169, 85), _mm_shuffle_ps(v169, v169, 0)),
                     _mm_shuffle_ps(v169, v169, 170)));
          v171 = _mm_add_ps(
                   _mm_mul_ps(v168, *(__m128 *)&v7[80]),
                   _mm_mul_ps(*(__m128 *)&v7[64], v9->m_angularVel.m_quad));
          v172 = *(__m128 *)&v7[48];
          v173 = _mm_add_ps(v171, _mm_mul_ps(v172, v166));
          v174 = _mm_sub_ps(
                   _mm_shuffle_ps(v172, v172, 255),
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v173, v173, 85), _mm_shuffle_ps(v173, v173, 0)),
                     _mm_shuffle_ps(v173, v173, 170)));
          v175 = _mm_shuffle_ps((__m128)*(_DWORD *)&v7[96], (__m128)*(_DWORD *)&v7[96], 0);
          v176 = _mm_add_ps(
                   _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v7[32], *(__m128 *)&v7[32], 255), v170),
                   _mm_mul_ps(v175, v174));
          v177 = _mm_add_ps(
                   _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v7[80], *(__m128 *)&v7[80], 255), v174),
                   _mm_mul_ps(v175, v170));
          v178 = _mm_add_ps(_mm_mul_ps(v177, v177), _mm_mul_ps(v176, v176));
          v179 = _mm_rsqrt_ps(v178);
          v180 = _mm_cmplt_ps(_mm_mul_ps(v167, v167), v178);
          v296 = v178;
          v181 = _mm_mul_ps(
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v179, v178), v179)),
                     _mm_mul_ps(*(__m128 *)_xmm, v179)),
                   v167);
          v182 = _mm_or_ps(_mm_and_ps(_mm_mul_ps(v181, v176), v180), _mm_andnot_ps(v180, v176));
          v7 += 112;
          tmp += 3;
          LODWORD(tmp[-1].m_impulseApplied) = v181.m128_i32[0] & v180.m128_i32[0] | _mm_andnot_ps(v180, query.m_quad).m128_u32[0];
          v183 = _mm_or_ps(_mm_and_ps(_mm_mul_ps(v181, v177), v180), _mm_andnot_ps(v180, v177));
          v184 = _mm_mul_ps(v9->m_invMasses.m_quad, v182);
          v185 = _mm_mul_ps(mB->m_invMasses.m_quad, v182);
          v186 = _mm_mul_ps(_mm_shuffle_ps(v185, v185, 255), *(__m128 *)&v7[-112]);
          v9->m_linearVel.m_quad = _mm_add_ps(
                                     v9->m_linearVel.m_quad,
                                     _mm_mul_ps(_mm_shuffle_ps(v184, v184, 255), *(__m128 *)&v7[-112]));
          mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, v186);
          v187 = _mm_mul_ps(v185, *(__m128 *)&v7[-80]);
          v186.m128_f32[0] = _mm_shuffle_ps(
                               (__m128)LODWORD(tmp[-3].m_impulseApplied),
                               (__m128)LODWORD(tmp[-3].m_impulseApplied),
                               0).m128_f32[0];
          v9->m_angularVel.m_quad = _mm_add_ps(v9->m_angularVel.m_quad, _mm_mul_ps(v184, *(__m128 *)&v7[-96]));
          mB->m_angularVel.m_quad = _mm_add_ps(mB->m_angularVel.m_quad, v187);
          tmp[-3].m_impulseApplied = v186.m128_f32[0] + v182.m128_f32[0];
          v188 = _mm_mul_ps(v9->m_invMasses.m_quad, v183);
          v189 = _mm_mul_ps(mB->m_invMasses.m_quad, v183);
          v190 = _mm_mul_ps(_mm_shuffle_ps(v189, v189, 255), *(__m128 *)&v7[-64]);
          v9->m_linearVel.m_quad = _mm_add_ps(
                                     v9->m_linearVel.m_quad,
                                     _mm_mul_ps(_mm_shuffle_ps(v188, v188, 255), *(__m128 *)&v7[-64]));
          mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, v190);
          v191 = _mm_mul_ps(v189, *(__m128 *)&v7[-32]);
          v172.m128_f32[0] = _mm_shuffle_ps(
                               (__m128)LODWORD(tmp[-2].m_impulseApplied),
                               (__m128)LODWORD(tmp[-2].m_impulseApplied),
                               0).m128_f32[0];
          v9->m_angularVel.m_quad = _mm_add_ps(_mm_mul_ps(v188, *(__m128 *)&v7[-48]), v9->m_angularVel.m_quad);
          mB->m_angularVel.m_quad = _mm_add_ps(v191, mB->m_angularVel.m_quad);
          tmp[-2].m_impulseApplied = v172.m128_f32[0] + v183.m128_f32[0];
          if ( *v7 == 1 )
            goto LABEL_4;
          continue;
        case 0x1Du:
          v9->m_invMasses = *(hkVector4f *)v7;
          mB->m_invMasses = *(hkVector4f *)&v7[16];
          v9->m_invMasses.m_quad.m128_i8[0] = 0;
          goto LABEL_5;
        case 0x1Eu:
          v259 = 0i64;
          v259.m128_f32[0] = (float)temp.m_currentStep.m_storage;
          v260 = (__m128 *)((unsigned __int64)v9 ^ -*(_DWORD *)&v7[16] & ((unsigned __int64)v9 ^ (unsigned __int64)mB));
          v261 = _mm_mul_ps(
                   *(__m128 *)v7,
                   _mm_mul_ps(
                     _mm_shuffle_ps(v259, v259, 0),
                     _mm_shuffle_ps(info->m_integrateVelocityFactor.m_quad, info->m_integrateVelocityFactor.m_quad, 0)));
          v260[1] = _mm_add_ps(v261, _mm_add_ps(*(__m128 *)v7, v260[1]));
          v260[4] = _mm_add_ps(v261, v260[4]);
          goto LABEL_5;
        case 0x1Fu:
          v262 = v9->m_angularVel.m_quad;
          v7 += 96;
          v263 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v262, v262, 85), *(__m128 *)&v7[-80]),
                     _mm_mul_ps(_mm_shuffle_ps(v262, v262, 0), *(__m128 *)&v7[-96])),
                   _mm_mul_ps(_mm_shuffle_ps(v262, v262, 170), *(__m128 *)&v7[-64]));
          v264 = mB->m_angularVel.m_quad;
          v265 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v264, v264, 85), *(__m128 *)&v7[-32]),
                     _mm_mul_ps(_mm_shuffle_ps(v264, v264, 0), *(__m128 *)&v7[-48])),
                   _mm_mul_ps(_mm_shuffle_ps(v264, v264, 170), *(__m128 *)&v7[-16]));
          v266 = v9->m_scratch1.m_quad;
          v267 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v266, v266, 85), *(__m128 *)&v7[-80]),
                     _mm_mul_ps(_mm_shuffle_ps(v266, v266, 0), *(__m128 *)&v7[-96])),
                   _mm_mul_ps(_mm_shuffle_ps(v266, v266, 170), *(__m128 *)&v7[-64]));
          v268 = mB->m_scratch1.m_quad;
          v269 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v268, v268, 85), *(__m128 *)&v7[-32]),
                     _mm_mul_ps(_mm_shuffle_ps(v268, v268, 0), *(__m128 *)&v7[-48])),
                   _mm_mul_ps(_mm_shuffle_ps(v268, v268, 170), *(__m128 *)&v7[-16]));
          v9->m_linearVel.m_quad = _mm_add_ps(v9->m_linearVel.m_quad, v263);
          v9->m_scratch0.m_quad = _mm_add_ps(v267, v9->m_scratch0.m_quad);
          mB->m_linearVel.m_quad = _mm_add_ps(v265, mB->m_linearVel.m_quad);
          mB->m_scratch0.m_quad = _mm_add_ps(v269, mB->m_scratch0.m_quad);
          continue;
        case 0x20u:
          hkpAtomSolverFunctions::solveStableAngularConstraint3d<hkpVelocityAccumulator,hkpSolverInfo,hkSolverStepTemp>(
            info,
            &temp,
            (hkpStableAngularSchema3d *)v7,
            v9,
            mB,
            tmp);
          v7 += 48;
          tmp += 3;
          continue;
        case 0x22u:
          hkpAtomSolverFunctions::solveDeformableLinConstraintStub<hkpVelocityAccumulator,hkpSolverInfo,hkSolverStepTemp>(
            info,
            &temp,
            (hkpDeformableLinSchema *)v7,
            v9,
            mB,
            tmp);
          v7 += 128;
          tmp += 3;
          continue;
        case 0x23u:
          hkpAtomSolverFunctions::solveDeformableAngConstraintStub<hkpVelocityAccumulator,hkpSolverInfo,hkSolverStepTemp>(
            info,
            &temp,
            (hkpDeformableAngSchema *)v7,
            v9,
            mB,
            tmp);
          v7 += 128;
          tmp += 3;
          continue;
        case 0x27u:
          hkSolver_solveStiffSpringChain(info, &temp, accumulators, (hkpJacobianStiffSpringChainSchema *)v7, tmp);
          tmp += *(unsigned __int16 *)&v7[4];
          v7 += *(unsigned int *)&v7[8];
          continue;
        case 0x28u:
          hkSolver_solveBallAndSocketChain(info, &temp, accumulators, (hkpJacobianBallSocketChainSchema *)v7, tmp);
          goto LABEL_88;
        case 0x29u:
          hkSolver_solveStabilizedBallAndSocketChain(
            info,
            &temp,
            accumulators,
            (hkpJacobianStabilizedBallSocketChainSchema *)v7,
            tmp);
LABEL_88:
          v270 = 3 * *(unsigned __int16 *)&v7[4];
          v7 += *(unsigned int *)&v7[8];
          tmp += v270;
          continue;
        case 0x2Au:
          hkSolver_solvePoweredChain(info, &temp, accumulators, (hkpJacobianPoweredChainSchema *)v7, tmp);
          tmp += 6 * *(unsigned __int16 *)&v7[4];
          v7 += *(unsigned int *)&v7[16];
          continue;
        case 0x2Bu:
          v123 = *(_QWORD *)&v7[104];
          v124 = *(_QWORD *)(v123 + 40);
          if ( *(_BYTE *)(v124 + 36) )
          {
            v125 = 0.0;
            *(_DWORD *)v124 = 0;
          }
          else
          {
            v125 = *(float *)(v124 + 20);
            *(float *)v124 = (float)(info->m_invNumMicroSteps
                                   * (float)(info->m_deltaTime * (float)(*(float *)(v123 + 12) * v125)))
                           + *(float *)v124;
          }
          v126 = *(float *)&v7[44];
          v127 = *(float *)&v7[96];
          v128 = _mm_sub_ps(v9->m_linearVel.m_quad, mB->m_linearVel.m_quad);
          v129 = mB->m_angularVel.m_quad;
          v130 = _mm_add_ps(
                   _mm_mul_ps(*(__m128 *)v7, v128),
                   _mm_add_ps(
                     _mm_mul_ps(v129, *(__m128 *)&v7[32]),
                     _mm_mul_ps(*(__m128 *)&v7[16], v9->m_angularVel.m_quad)));
          LODWORD(v131) = COERCE_UNSIGNED_INT(
                            _mm_shuffle_ps(*(__m128 *)v7, *(__m128 *)v7, 255).m128_f32[0]
                          - (float)((float)(_mm_shuffle_ps(v130, v130, 85).m128_f32[0]
                                          + _mm_shuffle_ps(v130, v130, 0).m128_f32[0])
                                  + _mm_shuffle_ps(v130, v130, 170).m128_f32[0])) ^ _xmm[0];
          v132 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(v129, *(__m128 *)&v7[80]),
                     _mm_mul_ps(*(__m128 *)&v7[64], v9->m_angularVel.m_quad)),
                   _mm_mul_ps(*(__m128 *)&v7[48], v128));
          v133 = (float)(_mm_shuffle_ps(v132, v132, 85).m128_f32[0] + _mm_shuffle_ps(v132, v132, 0).m128_f32[0])
               + _mm_shuffle_ps(v132, v132, 170).m128_f32[0];
          v134 = *(float *)&v7[92];
          LODWORD(v135) = COERCE_UNSIGNED_INT(_mm_shuffle_ps(*(__m128 *)&v7[48], *(__m128 *)&v7[48], 255).m128_f32[0] - v133) ^ _xmm[0];
          if ( v125 == 0.0 )
          {
            v136 = (float)(*(float *)(v123 + 16) * *(float *)v124) - v131;
            v137 = v127 * v135;
            v138 = (float)(v136 * v126) - (float)(v127 * v135);
          }
          else
          {
            v139 = (float)(*(float *)(v123 + 16) * *(float *)v124) - v131;
            v137 = v127 * v135;
            v138 = (float)((float)(*(float *)(v124 + 24) * (float)(v139 - (float)((float)(v127 * v135) / v126))) * v126)
                 / (float)((float)(v126 * *(float *)(v123 + 16)) + *(float *)(v124 + 24));
          }
          vars0 = v138;
          v298 = COERCE_FLOAT(COERCE_UNSIGNED_INT(v134 * v135) ^ _xmm[0])
               - (float)((float)((float)(v138 + v137) / v126) * v127);
          *(float *)&v273 = (float)(v298 * v298) + (float)(v138 * v138);
          v140 = *(float *)&v7[100];
          v141 = fsqrt(*(float *)&v273);
          if ( v141 <= v140 )
          {
            *(float *)(v123 + 20) = v138 + *(float *)(v123 + 20);
            *(float *)(v123 + 24) = v298 + *(float *)(v123 + 24);
          }
          else
          {
            v142 = v140 / v141;
            *(float *)(v123 + 20) = (float)(v142 * v138) + *(float *)(v123 + 20);
            *(float *)(v123 + 28) = (float)(vars0 - (float)(v142 * v138)) + *(float *)(v123 + 28);
            vars0 = v142 * v138;
            v143 = v142 * v298;
            *(float *)(v123 + 24) = v143 + *(float *)(v123 + 24);
            *(float *)(v123 + 32) = (float)(v298 - v143) + *(float *)(v123 + 32);
            v298 = v143;
          }
          v144.m_quad = (__m128)mB->m_invMasses;
          if ( v141 != 0.0 )
          {
            v145 = *(float *)(v124 + 28) * v141;
            if ( v145 > *(float *)(v124 + 32) )
              v145 = *(float *)(v124 + 32);
            *(float *)&v272 = v145 / v141;
            mB->m_invMasses.m_quad = _mm_mul_ps(
                                       mB->m_invMasses.m_quad,
                                       _mm_shuffle_ps(
                                         (__m128)COERCE_UNSIGNED_INT(v145 / v141),
                                         (__m128)COERCE_UNSIGNED_INT(v145 / v141),
                                         0));
          }
          v146 = _mm_shuffle_ps((__m128)LODWORD(vars0), (__m128)LODWORD(vars0), 0);
          v147 = _mm_shuffle_ps((__m128)LODWORD(v298), (__m128)LODWORD(v298), 0);
          v148 = _mm_mul_ps(v9->m_invMasses.m_quad, v146);
          v149 = _mm_mul_ps(mB->m_invMasses.m_quad, v146);
          v150 = _mm_mul_ps(_mm_shuffle_ps(v149, v149, 255), *(__m128 *)v7);
          v9->m_linearVel.m_quad = _mm_add_ps(
                                     v9->m_linearVel.m_quad,
                                     _mm_mul_ps(_mm_shuffle_ps(v148, v148, 255), *(__m128 *)v7));
          mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, v150);
          v151 = _mm_mul_ps(v149, *(__m128 *)&v7[32]);
          v152 = _mm_shuffle_ps((__m128)LODWORD(tmp->m_impulseApplied), (__m128)LODWORD(tmp->m_impulseApplied), 0).m128_f32[0];
          v9->m_angularVel.m_quad = _mm_add_ps(_mm_mul_ps(v148, *(__m128 *)&v7[16]), v9->m_angularVel.m_quad);
          mB->m_angularVel.m_quad = _mm_add_ps(mB->m_angularVel.m_quad, v151);
          tmp->m_impulseApplied = v152 + v146.m128_f32[0];
          v153 = _mm_mul_ps(mB->m_invMasses.m_quad, v147);
          v154 = _mm_mul_ps(v9->m_invMasses.m_quad, v147);
          v155 = _mm_mul_ps(_mm_shuffle_ps(v153, v153, 255), *(__m128 *)&v7[48]);
          v9->m_linearVel.m_quad = _mm_add_ps(
                                     v9->m_linearVel.m_quad,
                                     _mm_mul_ps(_mm_shuffle_ps(v154, v154, 255), *(__m128 *)&v7[48]));
          mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, v155);
          v156 = _mm_mul_ps(v153, *(__m128 *)&v7[80]);
          v157 = _mm_shuffle_ps((__m128)LODWORD(tmp[1].m_impulseApplied), (__m128)LODWORD(tmp[1].m_impulseApplied), 0).m128_f32[0];
          v9->m_angularVel.m_quad = _mm_add_ps(v9->m_angularVel.m_quad, _mm_mul_ps(v154, *(__m128 *)&v7[64]));
          mB->m_angularVel.m_quad = _mm_add_ps(v156, mB->m_angularVel.m_quad);
          tmp[1].m_impulseApplied = v157 + v147.m128_f32[0];
          *(float *)v124 = *(float *)v124 - (float)(vars0 * v125);
          mB->m_invMasses = (hkVector4f)v144.m_quad;
          v158 = *(_QWORD *)(v123 + 40);
          v159 = *(_DWORD *)(v158 + 12) + 1;
          *(_DWORD *)(v158 + 12) = v159;
          v160 = *(_QWORD *)(v123 + 40);
          if ( v159 == *(_DWORD *)(v160 + 40) * info->m_numMicroSteps )
          {
            v161 = *(float *)v124 - *(float *)(v124 + 4);
            v162 = *(_DWORD *)(v160 + 16) + 1;
            *(_DWORD *)(v160 + 16) = v162;
            if ( v162 == info->m_numSteps )
            {
              *(float *)v124 = v161;
              *(_DWORD *)(v124 + 4) = 0;
              *(_DWORD *)(v124 + 16) = 0;
            }
            else
            {
              v163 = *(float *)(v124 + 4) + (float)(v161 * info->m_integrateVelocityFactor.m_quad.m128_f32[0]);
              *(float *)(v124 + 4) = v163;
              *(float *)v124 = v161 + v163;
            }
            *(_DWORD *)(v124 + 12) = 0;
          }
          v7 += 112;
          tmp += 2;
          if ( *v7 != 1 )
            continue;
          goto LABEL_4;
        default:
          __debugbreak();
          return;
      }
    }
  }
}

// File Line: 1738
// RVA: 0xDD86E0
hkSolveConstraints

// File Line: 1777
// RVA: 0xDDAB50
void __fastcall hkSolveApplyGravityByTheSteps(
        hkpSolverInfo *info,
        hkpVelocityAccumulator *accumulators,
        hkpVelocityAccumulator *accumulatorsEnd)
{
  unsigned __int64 v3; // rbx
  hkVector4f v4; // xmm9
  hkpVelocityAccumulator *v5; // r11
  float v6; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm3_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm3_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  __int64 v14; // r10
  __int64 v15; // r8
  __int64 v16; // r9
  float v17; // xmm0_4
  __m128 m_gravityFactor_low; // xmm4
  float v19; // xmm2_4
  float v20; // xmm1_4
  float v21; // xmm3_4
  __m128 v22; // xmm4
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm3_4
  float v26; // xmm0_4
  float v27; // xmm0_4
  __int64 v28; // r10
  __int64 v29; // r8
  __int64 v30; // r9
  float v31; // xmm0_4
  int v32; // [rsp+0h] [rbp-39h]
  __int64 v33; // [rsp+4h] [rbp-35h]
  int v34; // [rsp+10h] [rbp-29h]
  __int64 v35; // [rsp+14h] [rbp-25h]
  hkVector4f v36; // [rsp+20h] [rbp-19h]
  hkVector4f v37; // [rsp+30h] [rbp-9h]

  v3 = (unsigned __int64)accumulatorsEnd;
  if ( !accumulatorsEnd )
    v3 = -1i64;
  v4.m_quad = (__m128)info->m_globalAccelerationPerSubStep;
  v5 = accumulators;
  while ( (unsigned __int64)v5 < v3 )
  {
    _mm_prefetch(&v5[2].m_type.m_storage, 0);
    if ( v5->m_type.m_storage )
    {
      if ( (unsigned __int8)v5->m_type.m_storage <= 2u )
      {
        v5->m_context.m_storage = 1;
        v6 = v5->m_scratch0.m_quad.m128_f32[0];
        v7 = v5->m_scratch1.m_quad.m128_f32[1];
        v8 = v5->m_scratch2.m_quad.m128_f32[2];
        v9 = (float)(v6 + v7) + v8;
        if ( v9 <= 0.0 )
        {
          v32 = 1;
          v33 = 2i64;
          v14 = v7 > v6;
          if ( v8 > v5->m_scratch0.m_quad.m128_f32[5 * v14] )
            v14 = 2i64;
          v15 = *(&v32 + v14);
          v16 = *(&v32 + v15);
          v17 = fsqrt(
                  (float)(v5->m_scratch0.m_quad.m128_f32[5 * v14]
                        - (float)(v5->m_scratch0.m_quad.m128_f32[5 * v16] + v5->m_scratch0.m_quad.m128_f32[5 * v15]))
                + 1.0);
          v36.m_quad.m128_f32[v14] = v17 * 0.5;
          v36.m_quad.m128_f32[3] = (float)(v5->m_scratch0.m_quad.m128_f32[4 * v15 + v16]
                                         - v5->m_scratch0.m_quad.m128_f32[4 * v16 + v15])
                                 * (float)(0.5 / v17);
          v36.m_quad.m128_f32[v15] = (float)(v5->m_scratch0.m_quad.m128_f32[4 * v14 + v15]
                                           + v5->m_scratch0.m_quad.m128_f32[4 * v15 + v14])
                                   * (float)(0.5 / v17);
          v36.m_quad.m128_f32[v16] = (float)(v5->m_scratch0.m_quad.m128_f32[4 * v14 + v16]
                                           + v5->m_scratch0.m_quad.m128_f32[4 * v16 + v14])
                                   * (float)(0.5 / v17);
        }
        else
        {
          v10 = v5->m_scratch2.m_quad.m128_f32[0] - v5->m_scratch0.m_quad.m128_f32[2];
          v11 = fsqrt(v9 + 1.0);
          v12 = v5->m_scratch1.m_quad.m128_f32[2] - v5->m_scratch2.m_quad.m128_f32[1];
          v36.m_quad.m128_f32[3] = v11 * 0.5;
          v36.m_quad.m128_f32[0] = v12 * (float)(0.5 / v11);
          v13 = v5->m_scratch0.m_quad.m128_f32[1];
          v36.m_quad.m128_f32[1] = v10 * (float)(0.5 / v11);
          v36.m_quad.m128_f32[2] = (float)(v13 - v5->m_scratch1.m_quad.m128_f32[0]) * (float)(0.5 / v11);
        }
        ++v5;
        v5[-1].m_scratch2 = (hkVector4f)v36.m_quad;
        v5[-1].m_scratch0 = 0i64;
        v5[-1].m_scratch1 = 0i64;
      }
      else
      {
        if ( v5->m_type.m_storage == 3 )
          return;
        __debugbreak();
      }
    }
    else
    {
      while ( 1 )
      {
        m_gravityFactor_low = (__m128)LODWORD(v5->m_gravityFactor);
        v5->m_context.m_storage = 1;
        v19 = v5->m_scratch0.m_quad.m128_f32[0];
        v20 = v5->m_scratch1.m_quad.m128_f32[1];
        v21 = v5->m_scratch2.m_quad.m128_f32[2];
        v22 = _mm_shuffle_ps(m_gravityFactor_low, m_gravityFactor_low, 0);
        v23 = (float)(v19 + v20) + v21;
        if ( v23 <= 0.0 )
        {
          v34 = 1;
          v35 = 2i64;
          v28 = v20 > v19;
          if ( v21 > v5->m_scratch0.m_quad.m128_f32[5 * v28] )
            v28 = 2i64;
          v29 = *(&v34 + v28);
          v30 = *(&v34 + v29);
          v31 = fsqrt(
                  (float)(v5->m_scratch0.m_quad.m128_f32[5 * v28]
                        - (float)(v5->m_scratch0.m_quad.m128_f32[5 * v30] + v5->m_scratch0.m_quad.m128_f32[5 * v29]))
                + 1.0);
          v37.m_quad.m128_f32[v28] = v31 * 0.5;
          v37.m_quad.m128_f32[3] = (float)(v5->m_scratch0.m_quad.m128_f32[4 * v29 + v30]
                                         - v5->m_scratch0.m_quad.m128_f32[4 * v30 + v29])
                                 * (float)(0.5 / v31);
          v37.m_quad.m128_f32[v29] = (float)(v5->m_scratch0.m_quad.m128_f32[4 * v29 + v28]
                                           + v5->m_scratch0.m_quad.m128_f32[4 * v28 + v29])
                                   * (float)(0.5 / v31);
          v37.m_quad.m128_f32[v30] = (float)(v5->m_scratch0.m_quad.m128_f32[4 * v30 + v28]
                                           + v5->m_scratch0.m_quad.m128_f32[4 * v28 + v30])
                                   * (float)(0.5 / v31);
        }
        else
        {
          v24 = v5->m_scratch2.m_quad.m128_f32[0] - v5->m_scratch0.m_quad.m128_f32[2];
          v25 = fsqrt(v23 + 1.0);
          v26 = v5->m_scratch1.m_quad.m128_f32[2] - v5->m_scratch2.m_quad.m128_f32[1];
          v37.m_quad.m128_f32[3] = v25 * 0.5;
          v37.m_quad.m128_f32[0] = v26 * (float)(0.5 / v25);
          v27 = v5->m_scratch0.m_quad.m128_f32[1];
          v37.m_quad.m128_f32[1] = v24 * (float)(0.5 / v25);
          v37.m_quad.m128_f32[2] = (float)(v27 - v5->m_scratch1.m_quad.m128_f32[0]) * (float)(0.5 / v25);
        }
        ++v5;
        v5[-1].m_scratch2 = (hkVector4f)v37.m_quad;
        v5[-1].m_scratch0 = 0i64;
        v5[-1].m_scratch1 = 0i64;
        v5[-1].m_linearVel.m_quad = _mm_add_ps(_mm_mul_ps(v4.m_quad, v22), v5[-1].m_linearVel.m_quad);
        if ( v5->m_type.m_storage )
          break;
        if ( (unsigned __int64)v5 >= v3 )
          return;
      }
    }
  }
}

// File Line: 1789
// RVA: 0xDDAF60
char __fastcall hkSolveConstraintsByTheSteps(
        hkpSolverInfo *info,
        int currentSolverStep,
        int currentSolverMicroStep,
        hkpJacobian1dBilateralSchema *schemas,
        hkpVelocityAccumulator *accumulators,
        hkpSolverElemTemp *elemTemp)
{
  __m128 v11; // xmm0
  int v12; // eax
  hkpVelocityAccumulator *p_mA; // r14
  hkpVelocityAccumulator *mB; // rdi
  __m128 v15; // xmm6
  __m128 v16; // xmm4
  __m128 v17; // xmm0
  __m128 v18; // xmm3
  __m128 v19; // xmm5
  __m128 v20; // xmm3
  __m128 v21; // xmm2
  __m128 v22; // xmm2
  float v23; // xmm1_4
  __m128 v24; // xmm5
  __m128 v25; // xmm4
  __m128 v26; // xmm7
  __m128 v27; // xmm3
  __m128 v28; // xmm0
  __m128 v29; // xmm7
  __m128 v30; // xmm3
  __m128 v31; // xmm2
  __m128 v32; // xmm2
  __m128 v33; // xmm5
  __m128 v34; // xmm4
  __m128 v35; // xmm2
  __m128 v36; // xmm9
  __m128 v37; // xmm0
  __m128 v38; // xmm5
  __m128 v39; // xmm3
  __m128 v40; // xmm1
  __m128 v41; // xmm6
  __m128 v42; // xmm5
  __m128 v43; // xmm7
  __m128 v44; // xmm8
  float v45; // xmm2_4
  __m128 v46; // xmm4
  __m128 v47; // xmm3
  __m128 v48; // xmm2
  __m128 v49; // xmm4
  float v50; // xmm1_4
  __m128 v51; // xmm3
  __m128 v52; // xmm4
  __m128 v53; // xmm2
  __m128 v54; // xmm4
  float v55; // xmm0_4
  __m128 v56; // xmm5
  __m128 v57; // xmm8
  __m128 v58; // xmm4
  __m128 v59; // xmm3
  __m128 v60; // xmm2
  __m128 v61; // xmm3
  float v62; // xmm1_4
  __m128 v63; // xmm4
  __m128 v64; // xmm3
  __m128 v65; // xmm2
  __m128 v66; // xmm3
  float v67; // xmm0_4
  __m128 v68; // xmm5
  __m128 v69; // xmm4
  __m128 v70; // xmm2
  __m128 v71; // xmm9
  __m128 v72; // xmm0
  __m128 v73; // xmm5
  __m128 v74; // xmm2
  __m128 v75; // xmm1
  __m128 v76; // xmm8
  __m128 v77; // xmm5
  __m128 v78; // xmm6
  float v79; // xmm7_4
  __m128 v80; // xmm4
  __m128 v81; // xmm3
  __m128 v82; // xmm2
  __m128 v83; // xmm3
  float v84; // xmm1_4
  __m128 v85; // xmm4
  __m128 v86; // xmm3
  __m128 v87; // xmm2
  __m128 v88; // xmm4
  float v89; // xmm1_4
  __m128 v90; // xmm5
  __m128 v91; // xmm6
  __m128 v92; // xmm4
  __m128 v93; // xmm3
  __m128 v94; // xmm2
  __m128 v95; // xmm3
  float v96; // xmm0_4
  __m128 v97; // xmm4
  __m128 v98; // xmm3
  __m128 v99; // xmm2
  __m128 v100; // xmm4
  float v101; // xmm5_4
  __m128 v102; // xmm5
  __m128 v103; // xmm4
  __m128 v104; // xmm6
  __m128 v105; // xmm3
  __m128 v106; // xmm2
  __m128 v107; // xmm9
  __m128 v108; // xmm0
  __m128 v109; // xmm2
  __m128 v110; // xmm7
  __m128 v111; // xmm2
  __m128 v112; // xmm10
  __m128 v113; // xmm1
  __m128 v114; // xmm4
  __m128 v115; // xmm5
  __m128 v116; // xmm3
  __m128 v117; // xmm8
  __m128 v118; // xmm1
  __m128 v119; // xmm3
  __m128 v120; // xmm6
  __m128 v121; // xmm5
  __m128 v122; // xmm7
  __m128 v123; // xmm4
  __m128 v124; // xmm3
  __m128 v125; // xmm2
  __m128 v126; // xmm3
  __m128 v127; // xmm3
  __m128 v128; // xmm4
  __m128 v129; // xmm2
  __m128 v130; // xmm3
  __m128 m_impulseApplied_low; // xmm2
  __m128 v132; // xmm4
  __m128 v133; // xmm1
  unsigned __int64 v134; // r9
  __int64 v135; // r8
  float v136; // xmm9_4
  __m128 v137; // xmm5
  float v138; // xmm8_4
  float v139; // xmm10_4
  __m128 v140; // xmm4
  __m128 v141; // xmm2
  float v142; // xmm7_4
  __m128 v143; // xmm5
  float v144; // xmm6_4
  float v145; // xmm4_4
  float v146; // xmm7_4
  float v147; // xmm4_4
  float v148; // xmm2_4
  float v149; // xmm3_4
  float v150; // xmm5_4
  float v151; // xmm3_4
  float v152; // xmm3_4
  hkVector4f v153; // xmm7
  float v154; // xmm0_4
  __m128 v155; // xmm5
  __m128 v156; // xmm6
  __m128 v157; // xmm4
  __m128 v158; // xmm3
  __m128 v159; // xmm2
  __m128 v160; // xmm3
  float v161; // xmm0_4
  __m128 v162; // xmm3
  __m128 v163; // xmm4
  __m128 v164; // xmm2
  __m128 v165; // xmm4
  __int64 v166; // rcx
  int v167; // edx
  __int64 v168; // rcx
  float v169; // xmm1_4
  int v170; // eax
  float v171; // xmm0_4
  __int64 v172; // rax
  int v173; // eax
  __m128 v174; // xmm5
  __m128 v175; // xmm4
  __m128 v176; // xmm6
  __m128 v177; // xmm2
  __m128 v178; // xmm7
  __m128 v179; // xmm0
  __m128 v180; // xmm5
  __m128 v181; // xmm2
  __m128 v182; // xmm1
  __m128 v183; // xmm5
  __m128 v184; // xmm4
  __m128 v185; // xmm3
  __m128 v186; // xmm1
  __m128 v187; // xmm8
  __m128 v188; // xmm3
  __m128 v189; // xmm6
  __m128 v190; // xmm5
  __m128 v191; // xmm4
  __m128 v192; // xmm3
  __m128 v193; // xmm2
  __m128 v194; // xmm3
  __m128 v195; // xmm4
  __m128 v196; // xmm3
  __m128 v197; // xmm2
  __m128 v198; // xmm4
  __m128 v199; // xmm6
  __m128 v200; // xmm3
  __m128 v201; // xmm4
  __m128 v202; // xmm4
  __m128 v203; // xmm2
  __m128i v204; // xmm1
  __m128i v205; // xmm6
  __m128 v206; // xmm1
  __m128 v207; // xmm5
  __m128 v208; // xmm0
  __m128 v209; // xmm6
  __m128 v210; // xmm2
  __m128 v211; // xmm3
  __m128 v212; // xmm7
  __m128 v213; // xmm6
  __m128 v214; // xmm8
  __m128 v215; // xmm4
  __m128 v216; // xmm2
  __m128 v217; // xmm1
  float v218; // xmm2_4
  __m128 v219; // xmm6
  __m128 v220; // xmm3
  __m128 v221; // xmm0
  __m128 v222; // xmm6
  __m128 v223; // xmm0
  __int64 v224; // rax
  __m128 v225; // xmm4
  __m128 v226; // xmm5
  __m128 v227; // xmm2
  __m128 v228; // xmm7
  __m128 v229; // xmm2
  __m128 v230; // xmm6
  __m128 v231; // xmm8
  __m128 v232; // xmm5
  __m128 v233; // xmm0
  __m128 v234; // xmm1
  __m128 v235; // xmm3
  __m128 v236; // xmm5
  __m128 v237; // xmm4
  __m128 v238; // xmm2
  __m128 v239; // xmm1
  float v240; // xmm0_4
  __m128 v241; // xmm3
  __m128 m_quad; // xmm4
  __m128 v243; // xmm6
  __m128 v244; // xmm2
  __m128 v245; // xmm2
  __m128 v246; // xmm6
  __m128 v247; // xmm3
  __m128 v248; // xmm2
  __m128 v249; // xmm2
  float v250; // xmm1_4
  __int64 v251; // rax
  __int64 v252; // rax
  __m128 v253; // xmm6
  __m128 v254; // xmm3
  __m128 v255; // xmm2
  __m128 v256; // xmm2
  __m128i v257; // xmm2
  __m128 v258; // xmm0
  __m128 v259; // xmm1
  __m128 v260; // xmm5
  __m128 v261; // xmm6
  __m128 v262; // xmm4
  __m128 v263; // xmm3
  __m128 v264; // xmm2
  __m128 v265; // xmm3
  __int64 v266; // rax
  __int64 v267; // rax
  __m128 v268; // xmm3
  __m128 *v269; // rcx
  __m128 v270; // xmm2
  __m128 v271; // xmm1
  __m128 v272; // xmm10
  __m128 v273; // xmm1
  __m128 v274; // xmm9
  __m128 v275; // xmm1
  __m128 v276; // xmm3
  __m128 v277; // xmm1
  __m128 v278; // xmm2
  __int64 v279; // rcx
  float v280; // [rsp+40h] [rbp-C0h]
  float v281; // [rsp+44h] [rbp-BCh]
  hkSolverStepTemp temp; // [rsp+50h] [rbp-B0h] BYREF
  float v283; // [rsp+70h] [rbp-90h]
  float v284; // [rsp+78h] [rbp-88h]
  hkpVelocityAccumulator regB; // [rsp+80h] [rbp-80h] BYREF
  hkpVelocityAccumulator mA; // [rsp+100h] [rbp+0h] BYREF
  __m128 v287; // [rsp+180h] [rbp+80h]
  __m128 v288; // [rsp+190h] [rbp+90h]
  __m128 v289; // [rsp+1A0h] [rbp+A0h]
  __m128 v290; // [rsp+1B0h] [rbp+B0h]
  __m128 v291; // [rsp+1C0h] [rbp+C0h]
  __m128 v292; // [rsp+1D0h] [rbp+D0h]
  __m128 v293; // [rsp+1E0h] [rbp+E0h]
  __m128 v294; // [rsp+1F0h] [rbp+F0h]
  __m128 v295; // [rsp+200h] [rbp+100h]
  __m128 v296; // [rsp+210h] [rbp+110h]
  __int128 v297; // [rsp+220h] [rbp+120h]
  __m128 v298; // [rsp+230h] [rbp+130h]

  if ( !HK_flyingcolors_solver.m_bool )
  {
    hkpProcessFlyingColors(&HK_flyingcolors_solver);
    if ( !HK_flyingcolors_solver.m_bool )
      return 0;
  }
  temp.m_currentStep.m_storage = currentSolverStep;
  v11 = 0i64;
  v11.m128_f32[0] = (float)(currentSolverStep + 1);
  v12 = (unsigned __int8)schemas->m_jac.m_linear0.m_quad.m128_i8[0];
  temp.m_intregratePositionFactor.m_real = _mm_shuffle_ps(v11, v11, 0);
  if ( v12 )
  {
    if ( v12 != 2 )
      goto LABEL_7;
    p_mA = &mA;
    mB = &regB;
    *(_DWORD *)&mA.m_type.m_storage = _mm_cvtsi128_si32((__m128i)0i64);
    mA.m_linearVel.m_quad.m128_i32[0] = *(_DWORD *)&mA.m_type.m_storage;
    mA.m_angularVel.m_quad.m128_i32[0] = *(_DWORD *)&mA.m_type.m_storage;
    v297 = 0i64;
    mA.m_deactivationClass = _mm_cvtsi128_si32(_mm_srli_si128((__m128i)0i64, 4));
    mA.m_linearVel.m_quad.m128_i32[1] = mA.m_deactivationClass;
    mA.m_angularVel.m_quad.m128_i32[1] = mA.m_deactivationClass;
    regB.m_deactivationClass = mA.m_deactivationClass;
    *(_QWORD *)&mA.m_gravityFactor = __PAIR64__(
                                       _mm_cvtsi128_si32(_mm_srli_si128((__m128i)0i64, 12)),
                                       _mm_cvtsi128_si32(_mm_srli_si128((__m128i)0i64, 8)));
    mA.m_linearVel.m_quad.m128_u64[1] = *(_QWORD *)&mA.m_gravityFactor;
    mA.m_angularVel.m_quad.m128_u64[1] = *(_QWORD *)&mA.m_gravityFactor;
    mA.m_invMasses = *(hkVector4f *)&mA.m_type.m_storage;
    mA.m_scratch0 = *(hkVector4f *)&mA.m_type.m_storage;
    mA.m_scratch1 = *(hkVector4f *)&mA.m_type.m_storage;
    mA.m_scratch2 = *(hkVector4f *)&mA.m_type.m_storage;
    mA.m_scratch3 = *(hkVector4f *)&mA.m_type.m_storage;
    *(_DWORD *)&regB.m_type.m_storage = *(_DWORD *)&mA.m_type.m_storage;
    *(_QWORD *)&regB.m_gravityFactor = *(_QWORD *)&mA.m_gravityFactor;
    regB.m_linearVel = *(hkVector4f *)&mA.m_type.m_storage;
    regB.m_angularVel = *(hkVector4f *)&mA.m_type.m_storage;
    regB.m_invMasses = *(hkVector4f *)&mA.m_type.m_storage;
    regB.m_scratch0 = *(hkVector4f *)&mA.m_type.m_storage;
    regB.m_scratch1 = *(hkVector4f *)&mA.m_type.m_storage;
    regB.m_scratch2 = *(hkVector4f *)&mA.m_type.m_storage;
    regB.m_scratch3 = *(hkVector4f *)&mA.m_type.m_storage;
    while ( 1 )
    {
      switch ( schemas->m_jac.m_linear0.m_quad.m128_i8[0] )
      {
        case 0:
          return 1;
        case 1:
          goto LABEL_7;
        case 2:
          schemas = (hkpJacobian1dBilateralSchema *)((char *)schemas + schemas->m_jac.m_linear0.m_quad.m128_i64[1]);
          continue;
        case 3:
          schemas = (hkpJacobian1dBilateralSchema *)((char *)schemas + 16);
          continue;
        case 5:
          do
          {
            m_quad = schemas->m_jac.m_linear0.m_quad;
            v243 = schemas->m_jac.m_angular[0].m_quad;
            v244 = schemas->m_jac.m_angular[1].m_quad;
            ++schemas;
            v245 = _mm_add_ps(
                     _mm_add_ps(_mm_mul_ps(v244, mB->m_angularVel.m_quad), _mm_mul_ps(v243, p_mA->m_angularVel.m_quad)),
                     _mm_mul_ps(m_quad, _mm_sub_ps(p_mA->m_linearVel.m_quad, mB->m_linearVel.m_quad)));
            v246 = _mm_mul_ps(
                     _mm_shuffle_ps(v243, v243, 255),
                     _mm_sub_ps(
                       _mm_shuffle_ps(m_quad, m_quad, 255),
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v245, v245, 85), _mm_shuffle_ps(v245, v245, 0)),
                         _mm_shuffle_ps(v245, v245, 170))));
            v247 = _mm_mul_ps(p_mA->m_invMasses.m_quad, v246);
            v248 = _mm_mul_ps(mB->m_invMasses.m_quad, v246);
            p_mA->m_linearVel.m_quad = _mm_add_ps(
                                         _mm_mul_ps(_mm_shuffle_ps(v247, v247, 255), m_quad),
                                         p_mA->m_linearVel.m_quad);
            mB->m_linearVel.m_quad = _mm_sub_ps(
                                       mB->m_linearVel.m_quad,
                                       _mm_mul_ps(_mm_shuffle_ps(v248, v248, 255), m_quad));
            v249 = _mm_mul_ps(v248, schemas[-1].m_jac.m_angular[1].m_quad);
            v250 = _mm_shuffle_ps(
                     (__m128)LODWORD(elemTemp->m_impulseApplied),
                     (__m128)LODWORD(elemTemp->m_impulseApplied),
                     0).m128_f32[0]
                 + v246.m128_f32[0];
            p_mA->m_angularVel.m_quad = _mm_add_ps(
                                          _mm_mul_ps(v247, schemas[-1].m_jac.m_angular[0].m_quad),
                                          p_mA->m_angularVel.m_quad);
            mB->m_angularVel.m_quad = _mm_add_ps(mB->m_angularVel.m_quad, v249);
            elemTemp->m_impulseApplied = v250;
            elemTemp += (unsigned __int8)hkpJacobianSchema::s_schemaNumSolverElemTemps[(unsigned __int8)schemas[-1].m_jac.m_linear0.m_quad.m128_i8[0]];
          }
          while ( schemas->m_jac.m_linear0.m_quad.m128_i8[0] == 5 );
          continue;
        case 6:
          do
          {
            hkpAtomSolverFunctions::solve1dBilateralWithImpulseLimit<hkpVelocityAccumulator,hkpSolverInfo,hkSolverStepTemp>(
              info,
              &temp,
              schemas,
              p_mA,
              mB,
              elemTemp);
            v251 = (unsigned __int8)schemas->m_jac.m_linear0.m_quad.m128_i8[0];
            ++schemas;
            elemTemp += (unsigned __int8)hkpJacobianSchema::s_schemaNumSolverElemTemps[v251];
          }
          while ( schemas->m_jac.m_linear0.m_quad.m128_i8[0] == 6 );
          continue;
        case 7:
          do
          {
            hkpAtomSolverFunctions::solve1dBilateralUserTau<hkpVelocityAccumulator,hkpSolverInfo,hkSolverStepTemp>(
              info,
              &temp,
              (hkpJacobian1dBilateralUserTauSchema *)schemas,
              p_mA,
              mB,
              elemTemp);
            v252 = (unsigned __int8)schemas->m_jac.m_linear0.m_quad.m128_i8[0];
            schemas = (hkpJacobian1dBilateralSchema *)((char *)schemas + 64);
            elemTemp += (unsigned __int8)hkpJacobianSchema::s_schemaNumSolverElemTemps[v252];
          }
          while ( schemas->m_jac.m_linear0.m_quad.m128_i8[0] == 7 );
          continue;
        case 8:
          do
          {
            hkpAtomSolverFunctions::solve1dLinLimits<hkpVelocityAccumulator,hkpSolverInfo,hkSolverStepTemp>(
              info,
              &temp,
              (hkpJacobian1dLinearLimitsSchema *)schemas,
              p_mA,
              mB,
              elemTemp);
            v266 = (unsigned __int8)schemas->m_jac.m_linear0.m_quad.m128_i8[0];
            schemas = (hkpJacobian1dBilateralSchema *)((char *)schemas + 64);
            elemTemp += (unsigned __int8)hkpJacobianSchema::s_schemaNumSolverElemTemps[v266];
          }
          while ( schemas->m_jac.m_linear0.m_quad.m128_i8[0] == 8 );
          continue;
        case 9:
          do
          {
            v253 = schemas->m_jac.m_angular[0].m_quad;
            v254 = schemas->m_jac.m_linear0.m_quad;
            v255 = schemas->m_jac.m_angular[1].m_quad;
            schemas = (hkpJacobian1dBilateralSchema *)((char *)schemas + 64);
            v256 = _mm_add_ps(
                     _mm_add_ps(_mm_mul_ps(v255, mB->m_angularVel.m_quad), _mm_mul_ps(v253, p_mA->m_angularVel.m_quad)),
                     _mm_mul_ps(v254, _mm_sub_ps(p_mA->m_linearVel.m_quad, mB->m_linearVel.m_quad)));
            v257 = (__m128i)_mm_mul_ps(
                              _mm_shuffle_ps(v253, v253, 255),
                              _mm_sub_ps(
                                _mm_shuffle_ps(v254, v254, 255),
                                _mm_add_ps(
                                  _mm_add_ps(_mm_shuffle_ps(v256, v256, 85), _mm_shuffle_ps(v256, v256, 0)),
                                  _mm_shuffle_ps(v256, v256, 170))));
            v290 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v257, 1u), 1u);
            v258 = _mm_rcp_ps(v290);
            v259 = _mm_shuffle_ps(
                     (__m128)schemas[-1].m_jac.m_angular[1].m_quad.m128_u32[0],
                     (__m128)schemas[-1].m_jac.m_angular[1].m_quad.m128_u32[0],
                     0);
            v260 = _mm_cmplt_ps(v259, v290);
            v261 = _mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v257, 0x1Fu), 0x1Fu), _mm_min_ps(v290, v259));
            v292 = _mm_or_ps(
                     _mm_andnot_ps(v260, query.m_quad),
                     _mm_and_ps(
                       _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v290, v258)), v258), v259),
                       v260));
            elemTemp[1].m_impulseApplied = v292.m128_f32[0];
            v262 = _mm_mul_ps(p_mA->m_invMasses.m_quad, v261);
            v263 = _mm_mul_ps(mB->m_invMasses.m_quad, v261);
            v264 = _mm_mul_ps(_mm_shuffle_ps(v263, v263, 255), schemas[-2].m_jac.m_angular[1].m_quad);
            p_mA->m_linearVel.m_quad = _mm_add_ps(
                                         p_mA->m_linearVel.m_quad,
                                         _mm_mul_ps(
                                           _mm_shuffle_ps(v262, v262, 255),
                                           schemas[-2].m_jac.m_angular[1].m_quad));
            mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, v264);
            v265 = _mm_mul_ps(v263, schemas[-1].m_jac.m_angular[0].m_quad);
            v258.m128_f32[0] = _mm_shuffle_ps(
                                 (__m128)LODWORD(elemTemp->m_impulseApplied),
                                 (__m128)LODWORD(elemTemp->m_impulseApplied),
                                 0).m128_f32[0];
            p_mA->m_angularVel.m_quad = _mm_add_ps(
                                          _mm_mul_ps(v262, schemas[-1].m_jac.m_linear0.m_quad),
                                          p_mA->m_angularVel.m_quad);
            mB->m_angularVel.m_quad = _mm_add_ps(v265, mB->m_angularVel.m_quad);
            elemTemp->m_impulseApplied = v258.m128_f32[0] + v261.m128_f32[0];
            elemTemp += (unsigned __int8)hkpJacobianSchema::s_schemaNumSolverElemTemps[(unsigned __int8)schemas[-2].m_jac.m_angular[1].m_quad.m128_i8[0]];
          }
          while ( schemas->m_jac.m_linear0.m_quad.m128_i8[0] == 9 );
          continue;
        case 0xA:
          do
          {
            hkpAtomSolverFunctions::solve1dLinearMotor<hkpVelocityAccumulator,hkpSolverInfo,hkSolverStepTemp>(
              0i64,
              info,
              &temp,
              (hkpJacobian1dLinearMotorSchema *)schemas,
              p_mA,
              mB,
              elemTemp,
              0i64);
            v267 = (unsigned __int8)schemas->m_jac.m_linear0.m_quad.m128_i8[0];
            schemas = (hkpJacobian1dBilateralSchema *)((char *)schemas + 80);
            elemTemp += (unsigned __int8)hkpJacobianSchema::s_schemaNumSolverElemTemps[v267];
          }
          while ( schemas->m_jac.m_linear0.m_quad.m128_i8[0] == 10 );
          continue;
        case 0xB:
          hkpAtomSolverFunctions::solvePulley<hkpVelocityAccumulator,hkpSolverInfo,hkSolverStepTemp>(
            info,
            &temp,
            (hkpJacobian1dPulleySchema *)schemas,
            p_mA,
            mB,
            elemTemp++);
          schemas = (hkpJacobian1dBilateralSchema *)((char *)schemas + 64);
          continue;
        case 0xC:
          do
          {
            v236 = schemas->m_jac.m_linear0.m_quad;
            v237 = schemas->m_jac.m_angular[0].m_quad;
            schemas = (hkpJacobian1dBilateralSchema *)((char *)schemas + 32);
            v238 = _mm_add_ps(_mm_mul_ps(v236, p_mA->m_angularVel.m_quad), _mm_mul_ps(v237, mB->m_angularVel.m_quad));
            v239 = _mm_mul_ps(
                     _mm_shuffle_ps(v236, v236, 255),
                     _mm_sub_ps(
                       _mm_shuffle_ps(v237, v237, 255),
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v238, v238, 85), _mm_shuffle_ps(v238, v238, 0)),
                         _mm_shuffle_ps(v238, v238, 170))));
            v240 = _mm_shuffle_ps(
                     (__m128)LODWORD(elemTemp->m_impulseApplied),
                     (__m128)LODWORD(elemTemp->m_impulseApplied),
                     0).m128_f32[0]
                 + v239.m128_f32[0];
            v241 = _mm_mul_ps(_mm_mul_ps(v239, mB->m_invMasses.m_quad), v237);
            p_mA->m_angularVel.m_quad = _mm_add_ps(
                                          _mm_mul_ps(_mm_mul_ps(v239, p_mA->m_invMasses.m_quad), v236),
                                          p_mA->m_angularVel.m_quad);
            mB->m_angularVel.m_quad = _mm_add_ps(v241, mB->m_angularVel.m_quad);
            elemTemp->m_impulseApplied = v240;
            elemTemp += (unsigned __int8)hkpJacobianSchema::s_schemaNumSolverElemTemps[(unsigned __int8)schemas[-1].m_jac.m_angular[0].m_quad.m128_i8[0]];
          }
          while ( schemas->m_jac.m_linear0.m_quad.m128_i8[0] == 12 );
          continue;
        case 0xD:
          do
          {
            v211 = schemas->m_jac.m_angular[0].m_quad;
            v212 = schemas->m_jac.m_linear0.m_quad;
            v213 = _mm_shuffle_ps(
                     (__m128)schemas->m_jac.m_angular[1].m_quad.m128_u32[2],
                     (__m128)schemas->m_jac.m_angular[1].m_quad.m128_u32[2],
                     0);
            v214 = v211;
            v215 = _mm_shuffle_ps(v212, v212, 255);
            v216 = _mm_add_ps(
                     _mm_mul_ps(
                       _mm_mul_ps(
                         _mm_shuffle_ps(
                           info->m_invIntegrateVelocityFactor.m_quad,
                           info->m_invIntegrateVelocityFactor.m_quad,
                           0),
                         v213),
                       _mm_add_ps(
                         _mm_mul_ps(v211, mB->m_scratch1.m_quad),
                         _mm_mul_ps(schemas->m_jac.m_linear0.m_quad, p_mA->m_scratch1.m_quad))),
                     _mm_mul_ps(
                       _mm_add_ps(
                         _mm_mul_ps(v211, _mm_sub_ps(mB->m_angularVel.m_quad, mB->m_scratch1.m_quad)),
                         _mm_mul_ps(
                           _mm_sub_ps(p_mA->m_angularVel.m_quad, p_mA->m_scratch1.m_quad),
                           schemas->m_jac.m_linear0.m_quad)),
                       _mm_shuffle_ps((__m128)LODWORD(info->m_damping), (__m128)LODWORD(info->m_damping), 0)));
            v217 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v216, v216, 85), _mm_shuffle_ps(v216, v216, 0)),
                     _mm_shuffle_ps(v216, v216, 170));
            v218 = _mm_shuffle_ps(
                     (__m128)LODWORD(elemTemp->m_impulseApplied),
                     (__m128)LODWORD(elemTemp->m_impulseApplied),
                     0).m128_f32[0];
            v219 = _mm_sub_ps(_mm_mul_ps(v213, _mm_shuffle_ps(v211, v211, 255)), v217);
            v220 = _mm_mul_ps(
                     _mm_sub_ps(
                       v219,
                       _mm_shuffle_ps(
                         (__m128)schemas->m_jac.m_angular[1].m_quad.m128_u32[0],
                         (__m128)schemas->m_jac.m_angular[1].m_quad.m128_u32[0],
                         0)),
                     v215);
            if ( v220.m128_f32[0] <= (float)(0.0 - v218) )
            {
              v222 = _mm_mul_ps(
                       _mm_sub_ps(
                         v219,
                         _mm_shuffle_ps(
                           (__m128)schemas->m_jac.m_angular[1].m_quad.m128_u32[1],
                           (__m128)schemas->m_jac.m_angular[1].m_quad.m128_u32[1],
                           0)),
                       v215);
              if ( v222.m128_f32[0] < (float)(0.0 - v218) )
              {
                v223 = _mm_mul_ps(mB->m_invMasses.m_quad, v222);
                p_mA->m_angularVel.m_quad = _mm_add_ps(
                                              _mm_mul_ps(_mm_mul_ps(p_mA->m_invMasses.m_quad, v222), v212),
                                              p_mA->m_angularVel.m_quad);
                mB->m_angularVel.m_quad = _mm_add_ps(_mm_mul_ps(v223, v214), mB->m_angularVel.m_quad);
                elemTemp->m_impulseApplied = v222.m128_f32[0] + v218;
              }
            }
            else
            {
              v221 = _mm_mul_ps(_mm_mul_ps(mB->m_invMasses.m_quad, v220), v214);
              p_mA->m_angularVel.m_quad = _mm_add_ps(
                                            _mm_mul_ps(_mm_mul_ps(p_mA->m_invMasses.m_quad, v220), v212),
                                            p_mA->m_angularVel.m_quad);
              mB->m_angularVel.m_quad = _mm_add_ps(v221, mB->m_angularVel.m_quad);
              elemTemp->m_impulseApplied = v218 + v220.m128_f32[0];
            }
            v224 = (unsigned __int8)schemas->m_jac.m_linear0.m_quad.m128_i8[0];
            ++schemas;
            elemTemp += (unsigned __int8)hkpJacobianSchema::s_schemaNumSolverElemTemps[v224];
          }
          while ( schemas->m_jac.m_linear0.m_quad.m128_i8[0] == 13 );
          continue;
        case 0xE:
          do
          {
            v199 = schemas->m_jac.m_linear0.m_quad;
            v200 = schemas->m_jac.m_angular[0].m_quad;
            v201 = (__m128)schemas->m_jac.m_angular[1].m_quad.m128_u32[0];
            ++schemas;
            v202 = _mm_shuffle_ps(v201, v201, 0);
            v203 = _mm_add_ps(_mm_mul_ps(v199, p_mA->m_angularVel.m_quad), _mm_mul_ps(v200, mB->m_angularVel.m_quad));
            v204 = (__m128i)_mm_mul_ps(
                              _mm_shuffle_ps(v199, v199, 255),
                              _mm_sub_ps(
                                _mm_shuffle_ps(v200, v200, 255),
                                _mm_add_ps(
                                  _mm_add_ps(_mm_shuffle_ps(v203, v203, 85), _mm_shuffle_ps(v203, v203, 0)),
                                  _mm_shuffle_ps(v203, v203, 170))));
            v205 = _mm_srli_epi32(v204, 0x1Fu);
            v206 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v204, 1u), 1u);
            v207 = _mm_cmplt_ps(v202, v206);
            v291 = v206;
            v208 = _mm_rcp_ps(v206);
            v209 = _mm_xor_ps((__m128)_mm_slli_epi32(v205, 0x1Fu), _mm_min_ps(v206, v202));
            v295 = _mm_or_ps(
                     _mm_andnot_ps(v207, query.m_quad),
                     _mm_and_ps(
                       _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v206, v208)), v208), v202),
                       v207));
            elemTemp[1].m_impulseApplied = v295.m128_f32[0];
            v206.m128_f32[0] = _mm_shuffle_ps(
                                 (__m128)LODWORD(elemTemp->m_impulseApplied),
                                 (__m128)LODWORD(elemTemp->m_impulseApplied),
                                 0).m128_f32[0]
                             + v209.m128_f32[0];
            v210 = _mm_mul_ps(_mm_mul_ps(mB->m_invMasses.m_quad, v209), schemas[-1].m_jac.m_angular[0].m_quad);
            p_mA->m_angularVel.m_quad = _mm_add_ps(
                                          _mm_mul_ps(
                                            _mm_mul_ps(p_mA->m_invMasses.m_quad, v209),
                                            schemas[-1].m_jac.m_linear0.m_quad),
                                          p_mA->m_angularVel.m_quad);
            mB->m_angularVel.m_quad = _mm_add_ps(v210, mB->m_angularVel.m_quad);
            elemTemp->m_impulseApplied = v206.m128_f32[0];
            elemTemp += (unsigned __int8)hkpJacobianSchema::s_schemaNumSolverElemTemps[(unsigned __int8)schemas[-1].m_jac.m_linear0.m_quad.m128_i8[0]];
          }
          while ( schemas->m_jac.m_linear0.m_quad.m128_i8[0] == 14 );
          continue;
        case 0xF:
          do
          {
            v225 = schemas->m_jac.m_angular[0].m_quad;
            v226 = _mm_shuffle_ps(
                     (__m128)schemas->m_jac.m_angular[1].m_quad.m128_u32[3],
                     (__m128)schemas->m_jac.m_angular[1].m_quad.m128_u32[3],
                     0);
            v227 = _mm_add_ps(
                     _mm_mul_ps(
                       _mm_mul_ps(
                         _mm_shuffle_ps(
                           info->m_invIntegrateVelocityFactor.m_quad,
                           info->m_invIntegrateVelocityFactor.m_quad,
                           0),
                         v226),
                       _mm_add_ps(
                         _mm_mul_ps(v225, mB->m_scratch1.m_quad),
                         _mm_mul_ps(schemas->m_jac.m_linear0.m_quad, p_mA->m_scratch1.m_quad))),
                     _mm_mul_ps(
                       _mm_add_ps(
                         _mm_mul_ps(v225, _mm_sub_ps(mB->m_angularVel.m_quad, mB->m_scratch1.m_quad)),
                         _mm_mul_ps(
                           _mm_sub_ps(p_mA->m_angularVel.m_quad, p_mA->m_scratch1.m_quad),
                           schemas->m_jac.m_linear0.m_quad)),
                       _mm_shuffle_ps(
                         (__m128)schemas[1].m_jac.m_linear0.m_quad.m128_u32[0],
                         (__m128)schemas[1].m_jac.m_linear0.m_quad.m128_u32[0],
                         0)));
            v228 = _mm_mul_ps(
                     _mm_shuffle_ps(schemas->m_jac.m_linear0.m_quad, schemas->m_jac.m_linear0.m_quad, 255),
                     _mm_sub_ps(
                       _mm_mul_ps(
                         _mm_add_ps(
                           _mm_shuffle_ps(v225, v225, 255),
                           _mm_mul_ps(
                             _mm_shuffle_ps(
                               (__m128)schemas->m_jac.m_angular[1].m_quad.m128_u32[2],
                               (__m128)schemas->m_jac.m_angular[1].m_quad.m128_u32[2],
                               0),
                             temp.m_intregratePositionFactor.m_real)),
                         v226),
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v227, v227, 85), _mm_shuffle_ps(v227, v227, 0)),
                         _mm_shuffle_ps(v227, v227, 170))));
            v229 = _mm_rcp_ps(v228);
            v287 = v228;
            v230 = _mm_shuffle_ps(
                     (__m128)schemas->m_jac.m_angular[1].m_quad.m128_u32[0],
                     (__m128)schemas->m_jac.m_angular[1].m_quad.m128_u32[0],
                     0);
            v231 = _mm_shuffle_ps(
                     (__m128)schemas->m_jac.m_angular[1].m_quad.m128_u32[1],
                     (__m128)schemas->m_jac.m_angular[1].m_quad.m128_u32[1],
                     0);
            v232 = _mm_cmplt_ps(v230, v228);
            v233 = _mm_cmplt_ps(v228, v231);
            v293 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v229, v228)), v229), v230);
            v289 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v229, v228)), v229), v231);
            LODWORD(elemTemp[1].m_impulseApplied) = _mm_andnot_ps(
                                                      v232,
                                                      _mm_or_ps(
                                                        _mm_and_ps(v233, v289),
                                                        _mm_andnot_ps(v233, query.m_quad))).m128_u32[0] | v232.m128_i32[0] & v293.m128_i32[0];
            v234 = _mm_cmplt_ps(v287, v230);
            v287 = _mm_max_ps(v231, _mm_or_ps(_mm_and_ps(v234, v287), _mm_andnot_ps(v234, v230)));
            schemas = (hkpJacobian1dBilateralSchema *)((char *)schemas + 64);
            v234.m128_f32[0] = _mm_shuffle_ps(
                                 (__m128)LODWORD(elemTemp->m_impulseApplied),
                                 (__m128)LODWORD(elemTemp->m_impulseApplied),
                                 0).m128_f32[0]
                             + v287.m128_f32[0];
            v235 = _mm_mul_ps(_mm_mul_ps(v287, mB->m_invMasses.m_quad), schemas[-1].m_jac.m_linear0.m_quad);
            p_mA->m_angularVel.m_quad = _mm_add_ps(
                                          _mm_mul_ps(
                                            _mm_mul_ps(v287, p_mA->m_invMasses.m_quad),
                                            schemas[-2].m_jac.m_angular[1].m_quad),
                                          p_mA->m_angularVel.m_quad);
            mB->m_angularVel.m_quad = _mm_add_ps(v235, mB->m_angularVel.m_quad);
            elemTemp->m_impulseApplied = v234.m128_f32[0];
            elemTemp += (unsigned __int8)hkpJacobianSchema::s_schemaNumSolverElemTemps[(unsigned __int8)schemas[-2].m_jac.m_angular[1].m_quad.m128_i8[0]];
          }
          while ( schemas->m_jac.m_linear0.m_quad.m128_i8[0] == 15 );
          continue;
        case 0x10:
          hkpAtomSolverFunctions::solveStableBallSocket<hkpVelocityAccumulator,hkpSolverInfo,hkSolverStepTemp>(
            info,
            &temp,
            (hkpStableBallSocketSchema *)schemas,
            p_mA,
            mB,
            elemTemp);
          schemas = (hkpJacobian1dBilateralSchema *)((char *)schemas + 64);
          elemTemp += 3;
          continue;
        case 0x12:
          hkpAtomSolverFunctions::solveStableStiffSpring<hkpVelocityAccumulator,hkpSolverInfo,hkSolverStepTemp,hkpStableStiffSpringSchema>(
            info,
            &temp,
            (hkpStableStiffSpringSchema *)schemas++,
            p_mA,
            mB,
            elemTemp++);
          continue;
        case 0x14:
        case 0x15:
          do
          {
            v15 = schemas->m_jac.m_linear0.m_quad;
            v16 = schemas->m_jac.m_angular[0].m_quad;
            v17 = schemas->m_jac.m_angular[1].m_quad;
            ++schemas;
            v18 = _mm_add_ps(
                    _mm_mul_ps(v15, _mm_sub_ps(p_mA->m_linearVel.m_quad, mB->m_linearVel.m_quad)),
                    _mm_add_ps(_mm_mul_ps(v17, mB->m_angularVel.m_quad), _mm_mul_ps(v16, p_mA->m_angularVel.m_quad)));
            v19 = _mm_max_ps(
                    _mm_sub_ps(
                      (__m128)0i64,
                      _mm_shuffle_ps(
                        (__m128)LODWORD(elemTemp->m_impulseApplied),
                        (__m128)LODWORD(elemTemp->m_impulseApplied),
                        0)),
                    _mm_mul_ps(
                      _mm_shuffle_ps(v16, v16, 255),
                      _mm_sub_ps(
                        _mm_shuffle_ps(v15, v15, 255),
                        _mm_add_ps(
                          _mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)),
                          _mm_shuffle_ps(v18, v18, 170)))));
            v20 = _mm_mul_ps(p_mA->m_invMasses.m_quad, v19);
            v21 = _mm_mul_ps(mB->m_invMasses.m_quad, v19);
            p_mA->m_linearVel.m_quad = _mm_add_ps(
                                         _mm_mul_ps(_mm_shuffle_ps(v20, v20, 255), v15),
                                         p_mA->m_linearVel.m_quad);
            mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, _mm_mul_ps(_mm_shuffle_ps(v21, v21, 255), v15));
            v22 = _mm_mul_ps(v21, schemas[-1].m_jac.m_angular[1].m_quad);
            v23 = _mm_shuffle_ps(
                    (__m128)LODWORD(elemTemp->m_impulseApplied),
                    (__m128)LODWORD(elemTemp->m_impulseApplied),
                    0).m128_f32[0]
                + v19.m128_f32[0];
            p_mA->m_angularVel.m_quad = _mm_add_ps(
                                          _mm_mul_ps(v20, schemas[-1].m_jac.m_angular[0].m_quad),
                                          p_mA->m_angularVel.m_quad);
            mB->m_angularVel.m_quad = _mm_add_ps(mB->m_angularVel.m_quad, v22);
            elemTemp->m_impulseApplied = v23;
            elemTemp += (unsigned __int8)hkpJacobianSchema::s_schemaNumSolverElemTemps[(unsigned __int8)schemas[-1].m_jac.m_linear0.m_quad.m128_i8[0]];
          }
          while ( schemas->m_jac.m_linear0.m_quad.m128_i8[0] == 20 );
          continue;
        case 0x16:
        case 0x17:
          do
          {
            v24 = schemas->m_jac.m_linear0.m_quad;
            v25 = schemas->m_jac.m_angular[0].m_quad;
            v26 = schemas->m_jac.m_angular[1].m_quad;
            ++schemas;
            v27 = _mm_add_ps(
                    _mm_mul_ps(v24, _mm_sub_ps(p_mA->m_linearVel.m_quad, mB->m_linearVel.m_quad)),
                    _mm_add_ps(_mm_mul_ps(v26, mB->m_angularVel.m_quad), _mm_mul_ps(v25, p_mA->m_angularVel.m_quad)));
            v28 = _mm_shuffle_ps(
                    (__m128)LODWORD(elemTemp->m_impulseApplied),
                    (__m128)LODWORD(elemTemp->m_impulseApplied),
                    0);
            v29 = _mm_min_ps(
                    _mm_sub_ps(_mm_shuffle_ps(v26, v26, 255), v28),
                    _mm_max_ps(
                      _mm_sub_ps((__m128)0i64, v28),
                      _mm_mul_ps(
                        _mm_shuffle_ps(v25, v25, 255),
                        _mm_sub_ps(
                          _mm_shuffle_ps(v24, v24, 255),
                          _mm_add_ps(
                            _mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)),
                            _mm_shuffle_ps(v27, v27, 170))))));
            v30 = _mm_mul_ps(p_mA->m_invMasses.m_quad, v29);
            v31 = _mm_mul_ps(mB->m_invMasses.m_quad, v29);
            p_mA->m_linearVel.m_quad = _mm_add_ps(
                                         _mm_mul_ps(_mm_shuffle_ps(v30, v30, 255), v24),
                                         p_mA->m_linearVel.m_quad);
            mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, _mm_mul_ps(_mm_shuffle_ps(v31, v31, 255), v24));
            v32 = _mm_mul_ps(v31, schemas[-1].m_jac.m_angular[1].m_quad);
            v28.m128_f32[0] = _mm_shuffle_ps(
                                (__m128)LODWORD(elemTemp->m_impulseApplied),
                                (__m128)LODWORD(elemTemp->m_impulseApplied),
                                0).m128_f32[0];
            p_mA->m_angularVel.m_quad = _mm_add_ps(
                                          _mm_mul_ps(v30, schemas[-1].m_jac.m_angular[0].m_quad),
                                          p_mA->m_angularVel.m_quad);
            mB->m_angularVel.m_quad = _mm_add_ps(v32, mB->m_angularVel.m_quad);
            elemTemp->m_impulseApplied = v29.m128_f32[0] + v28.m128_f32[0];
            elemTemp += (unsigned __int8)hkpJacobianSchema::s_schemaNumSolverElemTemps[(unsigned __int8)schemas[-1].m_jac.m_linear0.m_quad.m128_i8[0]];
          }
          while ( schemas->m_jac.m_linear0.m_quad.m128_i8[0] == 22 );
          continue;
        case 0x18:
        case 0x19:
          v33 = mB->m_angularVel.m_quad;
          v34 = _mm_sub_ps(p_mA->m_linearVel.m_quad, mB->m_linearVel.m_quad);
          v35 = _mm_add_ps(
                  _mm_mul_ps(schemas->m_jac.m_linear0.m_quad, v34),
                  _mm_add_ps(
                    _mm_mul_ps(schemas->m_jac.m_angular[1].m_quad, v33),
                    _mm_mul_ps(schemas->m_jac.m_angular[0].m_quad, p_mA->m_angularVel.m_quad)));
          v36 = _mm_sub_ps(
                  _mm_shuffle_ps(schemas->m_jac.m_linear0.m_quad, schemas->m_jac.m_linear0.m_quad, 255),
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v35, v35, 85), _mm_shuffle_ps(v35, v35, 0)),
                    _mm_shuffle_ps(v35, v35, 170)));
          v37 = schemas[1].m_jac.m_linear0.m_quad;
          v38 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(v33, schemas[1].m_jac.m_angular[1].m_quad),
                    _mm_mul_ps(schemas[1].m_jac.m_angular[0].m_quad, p_mA->m_angularVel.m_quad)),
                  _mm_mul_ps(v37, v34));
          v39 = _mm_sub_ps(
                  _mm_shuffle_ps(v37, v37, 255),
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v38, v38, 85), _mm_shuffle_ps(v38, v38, 0)),
                    _mm_shuffle_ps(v38, v38, 170)));
          v40 = _mm_shuffle_ps(
                  (__m128)schemas[2].m_jac.m_linear0.m_quad.m128_u32[0],
                  (__m128)schemas[2].m_jac.m_linear0.m_quad.m128_u32[0],
                  0);
          v41 = _mm_add_ps(
                  _mm_mul_ps(
                    _mm_shuffle_ps(schemas->m_jac.m_angular[1].m_quad, schemas->m_jac.m_angular[1].m_quad, 255),
                    v36),
                  _mm_mul_ps(v40, v39));
          v42 = _mm_add_ps(
                  _mm_mul_ps(
                    _mm_shuffle_ps(schemas[1].m_jac.m_angular[1].m_quad, schemas[1].m_jac.m_angular[1].m_quad, 255),
                    v39),
                  _mm_mul_ps(v40, v36));
          v43 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 80);
          v294 = _mm_xor_ps(v43, (__m128)*(unsigned __int64 *)&elemTemp->m_impulseApplied);
          v44 = _mm_shuffle_ps(v294, v294, 0);
          LODWORD(v45) = _mm_shuffle_ps(v294, v294, 85).m128_u32[0];
          if ( v41.m128_f32[0] <= v44.m128_f32[0] )
          {
            v56 = _mm_mul_ps(
                    _mm_shuffle_ps(schemas[1].m_jac.m_angular[0].m_quad, schemas[1].m_jac.m_angular[0].m_quad, 255),
                    v39);
            if ( v56.m128_f32[0] > v45 )
            {
              v63 = _mm_mul_ps(p_mA->m_invMasses.m_quad, v56);
              v64 = _mm_mul_ps(mB->m_invMasses.m_quad, v56);
              v65 = _mm_mul_ps(_mm_shuffle_ps(v64, v64, 255), schemas[1].m_jac.m_linear0.m_quad);
              p_mA->m_linearVel.m_quad = _mm_add_ps(
                                           p_mA->m_linearVel.m_quad,
                                           _mm_mul_ps(_mm_shuffle_ps(v63, v63, 255), schemas[1].m_jac.m_linear0.m_quad));
              mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, v65);
              v66 = _mm_mul_ps(v64, schemas[1].m_jac.m_angular[1].m_quad);
              v67 = _mm_shuffle_ps(
                      (__m128)LODWORD(elemTemp[1].m_impulseApplied),
                      (__m128)LODWORD(elemTemp[1].m_impulseApplied),
                      0).m128_f32[0];
              p_mA->m_angularVel.m_quad = _mm_add_ps(
                                            _mm_mul_ps(v63, schemas[1].m_jac.m_angular[0].m_quad),
                                            p_mA->m_angularVel.m_quad);
              mB->m_angularVel.m_quad = _mm_add_ps(v66, mB->m_angularVel.m_quad);
              elemTemp[1].m_impulseApplied = v67 + v56.m128_f32[0];
              goto LABEL_21;
            }
LABEL_19:
            v57 = _mm_max_ps(
                    v44,
                    _mm_mul_ps(
                      _mm_shuffle_ps(schemas->m_jac.m_angular[0].m_quad, schemas->m_jac.m_angular[0].m_quad, 255),
                      v36));
            v58 = _mm_mul_ps(p_mA->m_invMasses.m_quad, v57);
            v59 = _mm_mul_ps(mB->m_invMasses.m_quad, v57);
            v60 = _mm_mul_ps(_mm_shuffle_ps(v59, v59, 255), schemas->m_jac.m_linear0.m_quad);
            p_mA->m_linearVel.m_quad = _mm_add_ps(
                                         p_mA->m_linearVel.m_quad,
                                         _mm_mul_ps(_mm_shuffle_ps(v58, v58, 255), schemas->m_jac.m_linear0.m_quad));
            mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, v60);
            v61 = _mm_mul_ps(v59, schemas->m_jac.m_angular[1].m_quad);
            v62 = _mm_shuffle_ps(
                    (__m128)LODWORD(elemTemp->m_impulseApplied),
                    (__m128)LODWORD(elemTemp->m_impulseApplied),
                    0).m128_f32[0]
                + v57.m128_f32[0];
            p_mA->m_angularVel.m_quad = _mm_add_ps(
                                          _mm_mul_ps(v58, schemas->m_jac.m_angular[0].m_quad),
                                          p_mA->m_angularVel.m_quad);
            mB->m_angularVel.m_quad = _mm_add_ps(mB->m_angularVel.m_quad, v61);
            elemTemp->m_impulseApplied = v62;
            goto LABEL_21;
          }
          if ( v42.m128_f32[0] <= v45 )
            goto LABEL_19;
          v46 = _mm_mul_ps(v41, mB->m_invMasses.m_quad);
          v47 = _mm_mul_ps(v41, p_mA->m_invMasses.m_quad);
          v48 = _mm_mul_ps(_mm_shuffle_ps(v46, v46, 255), schemas->m_jac.m_linear0.m_quad);
          p_mA->m_linearVel.m_quad = _mm_add_ps(
                                       p_mA->m_linearVel.m_quad,
                                       _mm_mul_ps(_mm_shuffle_ps(v47, v47, 255), schemas->m_jac.m_linear0.m_quad));
          mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, v48);
          v49 = _mm_mul_ps(v46, schemas->m_jac.m_angular[1].m_quad);
          v50 = _mm_shuffle_ps(
                  (__m128)LODWORD(elemTemp->m_impulseApplied),
                  (__m128)LODWORD(elemTemp->m_impulseApplied),
                  0).m128_f32[0];
          p_mA->m_angularVel.m_quad = _mm_add_ps(
                                        p_mA->m_angularVel.m_quad,
                                        _mm_mul_ps(v47, schemas->m_jac.m_angular[0].m_quad));
          mB->m_angularVel.m_quad = _mm_add_ps(v49, mB->m_angularVel.m_quad);
          elemTemp->m_impulseApplied = v41.m128_f32[0] + v50;
          v51 = _mm_mul_ps(v42, p_mA->m_invMasses.m_quad);
          v52 = _mm_mul_ps(v42, mB->m_invMasses.m_quad);
          v53 = _mm_mul_ps(_mm_shuffle_ps(v52, v52, 255), schemas[1].m_jac.m_linear0.m_quad);
          p_mA->m_linearVel.m_quad = _mm_add_ps(
                                       p_mA->m_linearVel.m_quad,
                                       _mm_mul_ps(_mm_shuffle_ps(v51, v51, 255), schemas[1].m_jac.m_linear0.m_quad));
          mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, v53);
          v54 = _mm_mul_ps(v52, schemas[1].m_jac.m_angular[1].m_quad);
          v55 = _mm_shuffle_ps(
                  (__m128)LODWORD(elemTemp[1].m_impulseApplied),
                  (__m128)LODWORD(elemTemp[1].m_impulseApplied),
                  0).m128_f32[0];
          p_mA->m_angularVel.m_quad = _mm_add_ps(
                                        _mm_mul_ps(v51, schemas[1].m_jac.m_angular[0].m_quad),
                                        p_mA->m_angularVel.m_quad);
          mB->m_angularVel.m_quad = _mm_add_ps(v54, mB->m_angularVel.m_quad);
          elemTemp[1].m_impulseApplied = v42.m128_f32[0] + v55;
LABEL_21:
          schemas = (hkpJacobian1dBilateralSchema *)((char *)schemas + 112);
          elemTemp += 2;
          if ( schemas->m_jac.m_linear0.m_quad.m128_i8[0] == 24 )
          {
            v68 = mB->m_angularVel.m_quad;
            v69 = _mm_sub_ps(p_mA->m_linearVel.m_quad, mB->m_linearVel.m_quad);
            v70 = _mm_add_ps(
                    _mm_mul_ps(schemas->m_jac.m_linear0.m_quad, v69),
                    _mm_add_ps(
                      _mm_mul_ps(schemas->m_jac.m_angular[1].m_quad, v68),
                      _mm_mul_ps(schemas->m_jac.m_angular[0].m_quad, p_mA->m_angularVel.m_quad)));
            v71 = _mm_sub_ps(
                    _mm_shuffle_ps(schemas->m_jac.m_linear0.m_quad, schemas->m_jac.m_linear0.m_quad, 255),
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v70, v70, 85), _mm_shuffle_ps(v70, v70, 0)),
                      _mm_shuffle_ps(v70, v70, 170)));
            v72 = schemas[1].m_jac.m_linear0.m_quad;
            v73 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(v68, schemas[1].m_jac.m_angular[1].m_quad),
                      _mm_mul_ps(schemas[1].m_jac.m_angular[0].m_quad, p_mA->m_angularVel.m_quad)),
                    _mm_mul_ps(v72, v69));
            v74 = _mm_sub_ps(
                    _mm_shuffle_ps(v72, v72, 255),
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v73, v73, 85), _mm_shuffle_ps(v73, v73, 0)),
                      _mm_shuffle_ps(v73, v73, 170)));
            v75 = _mm_shuffle_ps(
                    (__m128)schemas[2].m_jac.m_linear0.m_quad.m128_u32[0],
                    (__m128)schemas[2].m_jac.m_linear0.m_quad.m128_u32[0],
                    0);
            v76 = _mm_add_ps(
                    _mm_mul_ps(
                      _mm_shuffle_ps(schemas->m_jac.m_angular[1].m_quad, schemas->m_jac.m_angular[1].m_quad, 255),
                      v71),
                    _mm_mul_ps(v75, v74));
            v77 = _mm_add_ps(
                    _mm_mul_ps(
                      _mm_shuffle_ps(schemas[1].m_jac.m_angular[1].m_quad, schemas[1].m_jac.m_angular[1].m_quad, 255),
                      v74),
                    _mm_mul_ps(v75, v71));
            v296 = _mm_xor_ps(v43, (__m128)*(unsigned __int64 *)&elemTemp->m_impulseApplied);
            v78 = _mm_shuffle_ps(v296, v296, 0);
            LODWORD(v79) = _mm_shuffle_ps(v296, v296, 85).m128_u32[0];
            if ( v76.m128_f32[0] <= v78.m128_f32[0] )
            {
              v90 = _mm_mul_ps(
                      _mm_shuffle_ps(schemas[1].m_jac.m_angular[0].m_quad, schemas[1].m_jac.m_angular[0].m_quad, 255),
                      v74);
              if ( v90.m128_f32[0] > v79 )
              {
                v97 = _mm_mul_ps(mB->m_invMasses.m_quad, v90);
                v98 = _mm_mul_ps(p_mA->m_invMasses.m_quad, v90);
                v99 = _mm_mul_ps(_mm_shuffle_ps(v97, v97, 255), schemas[1].m_jac.m_linear0.m_quad);
                p_mA->m_linearVel.m_quad = _mm_add_ps(
                                             p_mA->m_linearVel.m_quad,
                                             _mm_mul_ps(
                                               _mm_shuffle_ps(v98, v98, 255),
                                               schemas[1].m_jac.m_linear0.m_quad));
                mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, v99);
                v100 = _mm_mul_ps(v97, schemas[1].m_jac.m_angular[1].m_quad);
                v101 = v90.m128_f32[0]
                     + _mm_shuffle_ps(
                         (__m128)LODWORD(elemTemp[1].m_impulseApplied),
                         (__m128)LODWORD(elemTemp[1].m_impulseApplied),
                         0).m128_f32[0];
                p_mA->m_angularVel.m_quad = _mm_add_ps(
                                              p_mA->m_angularVel.m_quad,
                                              _mm_mul_ps(v98, schemas[1].m_jac.m_angular[0].m_quad));
                mB->m_angularVel.m_quad = _mm_add_ps(v100, mB->m_angularVel.m_quad);
                elemTemp[1].m_impulseApplied = v101;
                goto LABEL_28;
              }
LABEL_26:
              v91 = _mm_max_ps(
                      v78,
                      _mm_mul_ps(
                        _mm_shuffle_ps(schemas->m_jac.m_angular[0].m_quad, schemas->m_jac.m_angular[0].m_quad, 255),
                        v71));
              v92 = _mm_mul_ps(p_mA->m_invMasses.m_quad, v91);
              v93 = _mm_mul_ps(mB->m_invMasses.m_quad, v91);
              v94 = _mm_mul_ps(_mm_shuffle_ps(v93, v93, 255), schemas->m_jac.m_linear0.m_quad);
              p_mA->m_linearVel.m_quad = _mm_add_ps(
                                           p_mA->m_linearVel.m_quad,
                                           _mm_mul_ps(_mm_shuffle_ps(v92, v92, 255), schemas->m_jac.m_linear0.m_quad));
              mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, v94);
              v95 = _mm_mul_ps(v93, schemas->m_jac.m_angular[1].m_quad);
              v96 = _mm_shuffle_ps(
                      (__m128)LODWORD(elemTemp->m_impulseApplied),
                      (__m128)LODWORD(elemTemp->m_impulseApplied),
                      0).m128_f32[0];
              p_mA->m_angularVel.m_quad = _mm_add_ps(
                                            _mm_mul_ps(v92, schemas->m_jac.m_angular[0].m_quad),
                                            p_mA->m_angularVel.m_quad);
              mB->m_angularVel.m_quad = _mm_add_ps(v95, mB->m_angularVel.m_quad);
              elemTemp->m_impulseApplied = v91.m128_f32[0] + v96;
              goto LABEL_28;
            }
            if ( v77.m128_f32[0] <= v79 )
              goto LABEL_26;
            v80 = _mm_mul_ps(p_mA->m_invMasses.m_quad, v76);
            v81 = _mm_mul_ps(mB->m_invMasses.m_quad, v76);
            v82 = _mm_mul_ps(_mm_shuffle_ps(v81, v81, 255), schemas->m_jac.m_linear0.m_quad);
            p_mA->m_linearVel.m_quad = _mm_add_ps(
                                         p_mA->m_linearVel.m_quad,
                                         _mm_mul_ps(_mm_shuffle_ps(v80, v80, 255), schemas->m_jac.m_linear0.m_quad));
            mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, v82);
            v83 = _mm_mul_ps(v81, schemas->m_jac.m_angular[1].m_quad);
            v84 = _mm_shuffle_ps(
                    (__m128)LODWORD(elemTemp->m_impulseApplied),
                    (__m128)LODWORD(elemTemp->m_impulseApplied),
                    0).m128_f32[0];
            p_mA->m_angularVel.m_quad = _mm_add_ps(
                                          _mm_mul_ps(v80, schemas->m_jac.m_angular[0].m_quad),
                                          p_mA->m_angularVel.m_quad);
            mB->m_angularVel.m_quad = _mm_add_ps(mB->m_angularVel.m_quad, v83);
            elemTemp->m_impulseApplied = v84 + v76.m128_f32[0];
            v85 = _mm_mul_ps(mB->m_invMasses.m_quad, v77);
            v86 = _mm_mul_ps(p_mA->m_invMasses.m_quad, v77);
            v87 = _mm_mul_ps(_mm_shuffle_ps(v85, v85, 255), schemas[1].m_jac.m_linear0.m_quad);
            p_mA->m_linearVel.m_quad = _mm_add_ps(
                                         p_mA->m_linearVel.m_quad,
                                         _mm_mul_ps(_mm_shuffle_ps(v86, v86, 255), schemas[1].m_jac.m_linear0.m_quad));
            mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, v87);
            v88 = _mm_mul_ps(v85, schemas[1].m_jac.m_angular[1].m_quad);
            v89 = _mm_shuffle_ps(
                    (__m128)LODWORD(elemTemp[1].m_impulseApplied),
                    (__m128)LODWORD(elemTemp[1].m_impulseApplied),
                    0).m128_f32[0]
                + v77.m128_f32[0];
            p_mA->m_angularVel.m_quad = _mm_add_ps(
                                          p_mA->m_angularVel.m_quad,
                                          _mm_mul_ps(v86, schemas[1].m_jac.m_angular[0].m_quad));
            mB->m_angularVel.m_quad = _mm_add_ps(v88, mB->m_angularVel.m_quad);
            elemTemp[1].m_impulseApplied = v89;
LABEL_28:
            schemas = (hkpJacobian1dBilateralSchema *)((char *)schemas + 112);
            elemTemp += 2;
            if ( schemas->m_jac.m_linear0.m_quad.m128_i8[0] == 27 )
            {
LABEL_29:
              v102 = p_mA->m_angularVel.m_quad;
              v103 = mB->m_angularVel.m_quad;
              v104 = _mm_shuffle_ps(
                       (__m128)schemas[2].m_jac.m_angular[1].m_quad.m128_u32[1],
                       (__m128)schemas[2].m_jac.m_angular[1].m_quad.m128_u32[1],
                       0);
              v105 = _mm_sub_ps(p_mA->m_linearVel.m_quad, mB->m_linearVel.m_quad);
              v106 = _mm_add_ps(
                       _mm_mul_ps(schemas->m_jac.m_linear0.m_quad, v105),
                       _mm_add_ps(
                         _mm_mul_ps(schemas->m_jac.m_angular[1].m_quad, v103),
                         _mm_mul_ps(schemas->m_jac.m_angular[0].m_quad, v102)));
              v107 = _mm_sub_ps(
                       _mm_shuffle_ps(schemas->m_jac.m_linear0.m_quad, schemas->m_jac.m_linear0.m_quad, 255),
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v106, v106, 85), _mm_shuffle_ps(v106, v106, 0)),
                         _mm_shuffle_ps(v106, v106, 170)));
              v108 = schemas[1].m_jac.m_linear0.m_quad;
              v109 = _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(v103, schemas[1].m_jac.m_angular[1].m_quad),
                         _mm_mul_ps(schemas[1].m_jac.m_angular[0].m_quad, v102)),
                       _mm_mul_ps(v108, v105));
              v110 = _mm_sub_ps(
                       _mm_shuffle_ps(v108, v108, 255),
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v109, v109, 85), _mm_shuffle_ps(v109, v109, 0)),
                         _mm_shuffle_ps(v109, v109, 170)));
              v111 = _mm_add_ps(
                       _mm_mul_ps(schemas[2].m_jac.m_linear0.m_quad, v102),
                       _mm_mul_ps(schemas[2].m_jac.m_angular[0].m_quad, v103));
              v112 = _mm_mul_ps(
                       _mm_shuffle_ps(schemas[2].m_jac.m_linear0.m_quad, schemas[2].m_jac.m_linear0.m_quad, 255),
                       _mm_sub_ps(
                         _mm_shuffle_ps(schemas[2].m_jac.m_angular[0].m_quad, schemas[2].m_jac.m_angular[0].m_quad, 255),
                         _mm_add_ps(
                           _mm_add_ps(_mm_shuffle_ps(v111, v111, 85), _mm_shuffle_ps(v111, v111, 0)),
                           _mm_shuffle_ps(v111, v111, 170))));
              v113 = _mm_shuffle_ps(
                       (__m128)schemas[2].m_jac.m_angular[1].m_quad.m128_u32[0],
                       (__m128)schemas[2].m_jac.m_angular[1].m_quad.m128_u32[0],
                       0);
              v114 = _mm_add_ps(
                       _mm_mul_ps(
                         _mm_shuffle_ps(schemas[1].m_jac.m_angular[1].m_quad, schemas[1].m_jac.m_angular[1].m_quad, 255),
                         v110),
                       _mm_mul_ps(v113, v107));
              v115 = _mm_add_ps(
                       _mm_mul_ps(
                         _mm_shuffle_ps(schemas->m_jac.m_angular[1].m_quad, schemas->m_jac.m_angular[1].m_quad, 255),
                         v107),
                       _mm_mul_ps(v113, v110));
              v116 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v114, v114), _mm_mul_ps(v115, v115)), _mm_mul_ps(v112, v112));
              v117 = _mm_cmplt_ps(_mm_mul_ps(v104, v104), v116);
              v298 = v116;
              v118 = _mm_rsqrt_ps(v116);
              v119 = _mm_mul_ps(
                       _mm_mul_ps(
                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v118, v116), v118)),
                         _mm_mul_ps(*(__m128 *)_xmm, v118)),
                       v104);
              v120 = _mm_or_ps(_mm_and_ps(_mm_mul_ps(v119, v115), v117), _mm_andnot_ps(v117, v115));
              v121 = _mm_or_ps(_mm_and_ps(_mm_mul_ps(v119, v114), v117), _mm_andnot_ps(v117, v114));
              LODWORD(elemTemp[3].m_impulseApplied) = v119.m128_i32[0] & v117.m128_i32[0] | _mm_andnot_ps(
                                                                                              v117,
                                                                                              query.m_quad).m128_u32[0];
              v122 = _mm_mul_ps(
                       _mm_or_ps(_mm_and_ps(_mm_mul_ps(v119, v112), v117), _mm_andnot_ps(v117, v112)),
                       _mm_shuffle_ps(
                         (__m128)schemas[2].m_jac.m_angular[1].m_quad.m128_u32[2],
                         (__m128)schemas[2].m_jac.m_angular[1].m_quad.m128_u32[2],
                         0));
              v123 = _mm_mul_ps(p_mA->m_invMasses.m_quad, v120);
              v124 = _mm_mul_ps(mB->m_invMasses.m_quad, v120);
              v125 = _mm_mul_ps(_mm_shuffle_ps(v124, v124, 255), schemas->m_jac.m_linear0.m_quad);
              p_mA->m_linearVel.m_quad = _mm_add_ps(
                                           p_mA->m_linearVel.m_quad,
                                           _mm_mul_ps(_mm_shuffle_ps(v123, v123, 255), schemas->m_jac.m_linear0.m_quad));
              mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, v125);
              v126 = _mm_mul_ps(v124, schemas->m_jac.m_angular[1].m_quad);
              v108.m128_f32[0] = _mm_shuffle_ps(
                                   (__m128)LODWORD(elemTemp->m_impulseApplied),
                                   (__m128)LODWORD(elemTemp->m_impulseApplied),
                                   0).m128_f32[0];
              p_mA->m_angularVel.m_quad = _mm_add_ps(
                                            _mm_mul_ps(v123, schemas->m_jac.m_angular[0].m_quad),
                                            p_mA->m_angularVel.m_quad);
              mB->m_angularVel.m_quad = _mm_add_ps(v126, mB->m_angularVel.m_quad);
              elemTemp->m_impulseApplied = v108.m128_f32[0] + v120.m128_f32[0];
              v127 = _mm_mul_ps(p_mA->m_invMasses.m_quad, v121);
              v128 = _mm_mul_ps(mB->m_invMasses.m_quad, v121);
              v129 = _mm_mul_ps(_mm_shuffle_ps(v128, v128, 255), schemas[1].m_jac.m_linear0.m_quad);
              p_mA->m_linearVel.m_quad = _mm_add_ps(
                                           p_mA->m_linearVel.m_quad,
                                           _mm_mul_ps(
                                             _mm_shuffle_ps(v127, v127, 255),
                                             schemas[1].m_jac.m_linear0.m_quad));
              mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, v129);
              v130 = _mm_mul_ps(v127, schemas[1].m_jac.m_angular[0].m_quad);
              m_impulseApplied_low = (__m128)LODWORD(elemTemp[1].m_impulseApplied);
              v132 = _mm_mul_ps(v128, schemas[1].m_jac.m_angular[1].m_quad);
              schemas = (hkpJacobian1dBilateralSchema *)((char *)schemas + 160);
              elemTemp += 4;
              p_mA->m_angularVel.m_quad = _mm_add_ps(p_mA->m_angularVel.m_quad, v130);
              mB->m_angularVel.m_quad = _mm_add_ps(mB->m_angularVel.m_quad, v132);
              elemTemp[-3].m_impulseApplied = _mm_shuffle_ps(m_impulseApplied_low, m_impulseApplied_low, 0).m128_f32[0]
                                            + v121.m128_f32[0];
              v108.m128_f32[0] = _mm_shuffle_ps(
                                   (__m128)LODWORD(elemTemp[-2].m_impulseApplied),
                                   (__m128)LODWORD(elemTemp[-2].m_impulseApplied),
                                   0).m128_f32[0]
                               + v122.m128_f32[0];
              v133 = _mm_mul_ps(_mm_mul_ps(mB->m_invMasses.m_quad, v122), schemas[-1].m_jac.m_linear0.m_quad);
              p_mA->m_angularVel.m_quad = _mm_add_ps(
                                            _mm_mul_ps(
                                              _mm_mul_ps(p_mA->m_invMasses.m_quad, v122),
                                              schemas[-2].m_jac.m_angular[1].m_quad),
                                            p_mA->m_angularVel.m_quad);
              mB->m_angularVel.m_quad = _mm_add_ps(v133, mB->m_angularVel.m_quad);
              elemTemp[-2].m_impulseApplied = v108.m128_f32[0];
              if ( schemas->m_jac.m_linear0.m_quad.m128_i8[0] == 1 )
              {
LABEL_7:
                p_mA = &accumulators[(unsigned __int64)schemas->m_jac.m_linear0.m_quad.m128_u16[2]];
                mB = &accumulators[(unsigned __int64)schemas->m_jac.m_linear0.m_quad.m128_u16[3]];
LABEL_8:
                schemas = (hkpJacobian1dBilateralSchema *)((char *)schemas + 32);
              }
            }
          }
          break;
        case 0x1A:
          goto LABEL_53;
        case 0x1B:
          goto LABEL_29;
        case 0x1C:
          hkpAtomSolverFunctions::solve2dRollingFriction<hkpVelocityAccumulator,hkpSolverInfo,hkSolverStepTemp>(
            info,
            &temp,
            (hkpJacobian2dRollingFrictionSchema *)schemas,
            p_mA,
            mB,
            elemTemp);
          v172 = (unsigned __int8)schemas->m_jac.m_linear0.m_quad.m128_i8[0];
          schemas += 2;
          elemTemp += (unsigned __int8)hkpJacobianSchema::s_schemaNumSolverElemTemps[v172];
          v173 = (unsigned __int8)schemas->m_jac.m_linear0.m_quad.m128_i8[0];
          if ( v173 == 27 )
            goto LABEL_29;
          if ( v173 != 26 )
            continue;
LABEL_53:
          v174 = mB->m_angularVel.m_quad;
          v175 = _mm_sub_ps(p_mA->m_linearVel.m_quad, mB->m_linearVel.m_quad);
          v176 = _mm_shuffle_ps(
                   (__m128)schemas[2].m_jac.m_linear0.m_quad.m128_u32[1],
                   (__m128)schemas[2].m_jac.m_linear0.m_quad.m128_u32[1],
                   0);
          v177 = _mm_add_ps(
                   _mm_mul_ps(schemas->m_jac.m_linear0.m_quad, v175),
                   _mm_add_ps(
                     _mm_mul_ps(schemas->m_jac.m_angular[1].m_quad, v174),
                     _mm_mul_ps(schemas->m_jac.m_angular[0].m_quad, p_mA->m_angularVel.m_quad)));
          v178 = _mm_sub_ps(
                   _mm_shuffle_ps(schemas->m_jac.m_linear0.m_quad, schemas->m_jac.m_linear0.m_quad, 255),
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v177, v177, 85), _mm_shuffle_ps(v177, v177, 0)),
                     _mm_shuffle_ps(v177, v177, 170)));
          v179 = schemas[1].m_jac.m_linear0.m_quad;
          v180 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(v174, schemas[1].m_jac.m_angular[1].m_quad),
                     _mm_mul_ps(schemas[1].m_jac.m_angular[0].m_quad, p_mA->m_angularVel.m_quad)),
                   _mm_mul_ps(v179, v175));
          v181 = _mm_sub_ps(
                   _mm_shuffle_ps(v179, v179, 255),
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v180, v180, 85), _mm_shuffle_ps(v180, v180, 0)),
                     _mm_shuffle_ps(v180, v180, 170)));
          v182 = _mm_shuffle_ps(
                   (__m128)schemas[2].m_jac.m_linear0.m_quad.m128_u32[0],
                   (__m128)schemas[2].m_jac.m_linear0.m_quad.m128_u32[0],
                   0);
          v183 = _mm_add_ps(
                   _mm_mul_ps(
                     _mm_shuffle_ps(schemas->m_jac.m_angular[1].m_quad, schemas->m_jac.m_angular[1].m_quad, 255),
                     v178),
                   _mm_mul_ps(v182, v181));
          v184 = _mm_add_ps(
                   _mm_mul_ps(
                     _mm_shuffle_ps(schemas[1].m_jac.m_angular[1].m_quad, schemas[1].m_jac.m_angular[1].m_quad, 255),
                     v181),
                   _mm_mul_ps(v182, v178));
          v185 = _mm_add_ps(_mm_mul_ps(v184, v184), _mm_mul_ps(v183, v183));
          v186 = _mm_rsqrt_ps(v185);
          v187 = _mm_cmplt_ps(_mm_mul_ps(v176, v176), v185);
          v288 = v185;
          v188 = _mm_mul_ps(
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v186, v185), v186)),
                     _mm_mul_ps(*(__m128 *)_xmm, v186)),
                   v176);
          v189 = _mm_or_ps(_mm_and_ps(_mm_mul_ps(v188, v183), v187), _mm_andnot_ps(v187, v183));
          schemas = (hkpJacobian1dBilateralSchema *)((char *)schemas + 112);
          elemTemp += 3;
          LODWORD(elemTemp[-1].m_impulseApplied) = v188.m128_i32[0] & v187.m128_i32[0] | _mm_andnot_ps(
                                                                                           v187,
                                                                                           query.m_quad).m128_u32[0];
          v190 = _mm_or_ps(_mm_and_ps(_mm_mul_ps(v188, v184), v187), _mm_andnot_ps(v187, v184));
          v191 = _mm_mul_ps(p_mA->m_invMasses.m_quad, v189);
          v192 = _mm_mul_ps(mB->m_invMasses.m_quad, v189);
          v193 = _mm_mul_ps(_mm_shuffle_ps(v192, v192, 255), schemas[-3].m_jac.m_angular[1].m_quad);
          p_mA->m_linearVel.m_quad = _mm_add_ps(
                                       p_mA->m_linearVel.m_quad,
                                       _mm_mul_ps(
                                         _mm_shuffle_ps(v191, v191, 255),
                                         schemas[-3].m_jac.m_angular[1].m_quad));
          mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, v193);
          v194 = _mm_mul_ps(v192, schemas[-2].m_jac.m_angular[0].m_quad);
          v186.m128_f32[0] = _mm_shuffle_ps(
                               (__m128)LODWORD(elemTemp[-3].m_impulseApplied),
                               (__m128)LODWORD(elemTemp[-3].m_impulseApplied),
                               0).m128_f32[0];
          p_mA->m_angularVel.m_quad = _mm_add_ps(
                                        _mm_mul_ps(v191, schemas[-2].m_jac.m_linear0.m_quad),
                                        p_mA->m_angularVel.m_quad);
          mB->m_angularVel.m_quad = _mm_add_ps(mB->m_angularVel.m_quad, v194);
          elemTemp[-3].m_impulseApplied = v186.m128_f32[0] + v189.m128_f32[0];
          v195 = _mm_mul_ps(mB->m_invMasses.m_quad, v190);
          v196 = _mm_mul_ps(p_mA->m_invMasses.m_quad, v190);
          v197 = _mm_mul_ps(_mm_shuffle_ps(v195, v195, 255), schemas[-2].m_jac.m_angular[1].m_quad);
          p_mA->m_linearVel.m_quad = _mm_add_ps(
                                       p_mA->m_linearVel.m_quad,
                                       _mm_mul_ps(
                                         _mm_shuffle_ps(v196, v196, 255),
                                         schemas[-2].m_jac.m_angular[1].m_quad));
          mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, v197);
          v198 = _mm_mul_ps(v195, schemas[-1].m_jac.m_angular[0].m_quad);
          v186.m128_f32[0] = _mm_shuffle_ps(
                               (__m128)LODWORD(elemTemp[-2].m_impulseApplied),
                               (__m128)LODWORD(elemTemp[-2].m_impulseApplied),
                               0).m128_f32[0];
          p_mA->m_angularVel.m_quad = _mm_add_ps(
                                        p_mA->m_angularVel.m_quad,
                                        _mm_mul_ps(v196, schemas[-1].m_jac.m_linear0.m_quad));
          mB->m_angularVel.m_quad = _mm_add_ps(v198, mB->m_angularVel.m_quad);
          elemTemp[-2].m_impulseApplied = v186.m128_f32[0] + v190.m128_f32[0];
          if ( schemas->m_jac.m_linear0.m_quad.m128_i8[0] == 1 )
            goto LABEL_7;
          continue;
        case 0x1D:
          p_mA->m_invMasses = schemas->m_jac.m_linear0;
          mB->m_invMasses = schemas->m_jac.m_angular[0];
          p_mA->m_invMasses.m_quad.m128_i8[0] = 0;
          goto LABEL_8;
        case 0x1E:
          v268 = 0i64;
          v268.m128_f32[0] = (float)temp.m_currentStep.m_storage;
          v269 = (__m128 *)((unsigned __int64)p_mA ^ -schemas->m_jac.m_angular[0].m_quad.m128_i32[0] & ((unsigned __int64)p_mA ^ (unsigned __int64)mB));
          v270 = _mm_mul_ps(
                   schemas->m_jac.m_linear0.m_quad,
                   _mm_mul_ps(
                     _mm_shuffle_ps(v268, v268, 0),
                     _mm_shuffle_ps(info->m_integrateVelocityFactor.m_quad, info->m_integrateVelocityFactor.m_quad, 0)));
          v269[1] = _mm_add_ps(v270, _mm_add_ps(schemas->m_jac.m_linear0.m_quad, v269[1]));
          v269[4] = _mm_add_ps(v270, v269[4]);
          goto LABEL_8;
        case 0x1F:
          v271 = p_mA->m_angularVel.m_quad;
          schemas += 2;
          v272 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v271, v271, 85), schemas[-2].m_jac.m_angular[0].m_quad),
                     _mm_mul_ps(_mm_shuffle_ps(v271, v271, 0), schemas[-2].m_jac.m_linear0.m_quad)),
                   _mm_mul_ps(_mm_shuffle_ps(v271, v271, 170), schemas[-2].m_jac.m_angular[1].m_quad));
          v273 = mB->m_angularVel.m_quad;
          v274 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v273, v273, 85), schemas[-1].m_jac.m_angular[0].m_quad),
                     _mm_mul_ps(_mm_shuffle_ps(v273, v273, 0), schemas[-1].m_jac.m_linear0.m_quad)),
                   _mm_mul_ps(_mm_shuffle_ps(v273, v273, 170), schemas[-1].m_jac.m_angular[1].m_quad));
          v275 = p_mA->m_scratch1.m_quad;
          v276 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v275, v275, 85), schemas[-2].m_jac.m_angular[0].m_quad),
                     _mm_mul_ps(_mm_shuffle_ps(v275, v275, 0), schemas[-2].m_jac.m_linear0.m_quad)),
                   _mm_mul_ps(_mm_shuffle_ps(v275, v275, 170), schemas[-2].m_jac.m_angular[1].m_quad));
          v277 = mB->m_scratch1.m_quad;
          v278 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v277, v277, 85), schemas[-1].m_jac.m_angular[0].m_quad),
                     _mm_mul_ps(_mm_shuffle_ps(v277, v277, 0), schemas[-1].m_jac.m_linear0.m_quad)),
                   _mm_mul_ps(_mm_shuffle_ps(v277, v277, 170), schemas[-1].m_jac.m_angular[1].m_quad));
          p_mA->m_linearVel.m_quad = _mm_add_ps(p_mA->m_linearVel.m_quad, v272);
          p_mA->m_scratch0.m_quad = _mm_add_ps(v276, p_mA->m_scratch0.m_quad);
          mB->m_linearVel.m_quad = _mm_add_ps(v274, mB->m_linearVel.m_quad);
          mB->m_scratch0.m_quad = _mm_add_ps(v278, mB->m_scratch0.m_quad);
          continue;
        case 0x20:
          hkpAtomSolverFunctions::solveStableAngularConstraint3d<hkpVelocityAccumulator,hkpSolverInfo,hkSolverStepTemp>(
            info,
            &temp,
            (hkpStableAngularSchema3d *)schemas++,
            p_mA,
            mB,
            elemTemp);
          elemTemp += 3;
          continue;
        case 0x22:
          hkpAtomSolverFunctions::solveDeformableLinConstraintStub<hkpVelocityAccumulator,hkpSolverInfo,hkSolverStepTemp>(
            info,
            &temp,
            (hkpDeformableLinSchema *)schemas,
            p_mA,
            mB,
            elemTemp);
          schemas = (hkpJacobian1dBilateralSchema *)((char *)schemas + 128);
          elemTemp += 3;
          continue;
        case 0x23:
          hkpAtomSolverFunctions::solveDeformableAngConstraintStub<hkpVelocityAccumulator,hkpSolverInfo,hkSolverStepTemp>(
            info,
            &temp,
            (hkpDeformableAngSchema *)schemas,
            p_mA,
            mB,
            elemTemp);
          schemas = (hkpJacobian1dBilateralSchema *)((char *)schemas + 128);
          elemTemp += 3;
          continue;
        case 0x27:
          hkSolver_solveStiffSpringChain(
            info,
            &temp,
            accumulators,
            (hkpJacobianStiffSpringChainSchema *)schemas,
            elemTemp);
          elemTemp += schemas->m_jac.m_linear0.m_quad.m128_u16[2];
          schemas = (hkpJacobian1dBilateralSchema *)((char *)schemas
                                                   + (unsigned int)schemas->m_jac.m_linear0.m_quad.m128_i32[2]);
          continue;
        case 0x28:
          hkSolver_solveBallAndSocketChain(
            info,
            &temp,
            accumulators,
            (hkpJacobianBallSocketChainSchema *)schemas,
            elemTemp);
          goto LABEL_91;
        case 0x29:
          hkSolver_solveStabilizedBallAndSocketChain(
            info,
            &temp,
            accumulators,
            (hkpJacobianStabilizedBallSocketChainSchema *)schemas,
            elemTemp);
LABEL_91:
          v279 = 3 * schemas->m_jac.m_linear0.m_quad.m128_u16[2];
          schemas = (hkpJacobian1dBilateralSchema *)((char *)schemas
                                                   + (unsigned int)schemas->m_jac.m_linear0.m_quad.m128_i32[2]);
          elemTemp += v279;
          continue;
        case 0x2A:
          hkSolver_solvePoweredChain(info, &temp, accumulators, (hkpJacobianPoweredChainSchema *)schemas, elemTemp);
          elemTemp += 6 * schemas->m_jac.m_linear0.m_quad.m128_u16[2];
          schemas = (hkpJacobian1dBilateralSchema *)((char *)schemas
                                                   + (unsigned int)schemas->m_jac.m_angular[0].m_quad.m128_i32[0]);
          continue;
        case 0x2B:
          v134 = schemas[2].m_jac.m_linear0.m_quad.m128_u64[1];
          v135 = *(_QWORD *)(v134 + 40);
          if ( *(_BYTE *)(v135 + 36) )
          {
            v136 = 0.0;
            *(_DWORD *)v135 = 0;
          }
          else
          {
            v136 = *(float *)(v135 + 20);
            *(float *)v135 = *(float *)v135
                           + (float)(info->m_invNumMicroSteps
                                   * (float)(info->m_deltaTime * (float)(*(float *)(v134 + 12) * v136)));
          }
          v137 = mB->m_angularVel.m_quad;
          v138 = schemas->m_jac.m_angular[1].m_quad.m128_f32[3];
          v139 = schemas[2].m_jac.m_linear0.m_quad.m128_f32[0];
          v140 = _mm_sub_ps(p_mA->m_linearVel.m_quad, mB->m_linearVel.m_quad);
          v141 = _mm_add_ps(
                   _mm_mul_ps(schemas->m_jac.m_linear0.m_quad, v140),
                   _mm_add_ps(
                     _mm_mul_ps(schemas->m_jac.m_angular[1].m_quad, v137),
                     _mm_mul_ps(schemas->m_jac.m_angular[0].m_quad, p_mA->m_angularVel.m_quad)));
          LODWORD(v142) = COERCE_UNSIGNED_INT(
                            _mm_shuffle_ps(schemas->m_jac.m_linear0.m_quad, schemas->m_jac.m_linear0.m_quad, 255).m128_f32[0]
                          - (float)((float)(_mm_shuffle_ps(v141, v141, 85).m128_f32[0]
                                          + _mm_shuffle_ps(v141, v141, 0).m128_f32[0])
                                  + _mm_shuffle_ps(v141, v141, 170).m128_f32[0])) ^ _xmm[0];
          v143 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(v137, schemas[1].m_jac.m_angular[1].m_quad),
                     _mm_mul_ps(schemas[1].m_jac.m_angular[0].m_quad, p_mA->m_angularVel.m_quad)),
                   _mm_mul_ps(schemas[1].m_jac.m_linear0.m_quad, v140));
          LODWORD(v144) = COERCE_UNSIGNED_INT(
                            _mm_shuffle_ps(schemas[1].m_jac.m_linear0.m_quad, schemas[1].m_jac.m_linear0.m_quad, 255).m128_f32[0]
                          - (float)((float)(_mm_shuffle_ps(v143, v143, 85).m128_f32[0]
                                          + _mm_shuffle_ps(v143, v143, 0).m128_f32[0])
                                  + _mm_shuffle_ps(v143, v143, 170).m128_f32[0])) ^ _xmm[0];
          if ( v136 == 0.0 )
          {
            v145 = (float)(*(float *)v135 * *(float *)(v134 + 16)) - v142;
            v146 = v139 * v144;
            v147 = (float)(v145 * v138) - (float)(v139 * v144);
          }
          else
          {
            v148 = (float)(*(float *)v135 * *(float *)(v134 + 16)) - v142;
            v146 = v139 * v144;
            v147 = (float)((float)(*(float *)(v135 + 24) * (float)(v148 - (float)((float)(v139 * v144) / v138))) * v138)
                 / (float)((float)(v138 * *(float *)(v134 + 16)) + *(float *)(v135 + 24));
          }
          v280 = v147;
          v281 = COERCE_FLOAT(COERCE_UNSIGNED_INT(schemas[1].m_jac.m_angular[1].m_quad.m128_f32[3] * v144) ^ _xmm[0])
               - (float)((float)((float)(v147 + v146) / v138) * v139);
          v284 = (float)(v281 * v281) + (float)(v147 * v147);
          v149 = schemas[2].m_jac.m_linear0.m_quad.m128_f32[1];
          v150 = fsqrt(v284);
          if ( v150 <= v149 )
          {
            *(float *)(v134 + 20) = v147 + *(float *)(v134 + 20);
            *(float *)(v134 + 24) = v281 + *(float *)(v134 + 24);
          }
          else
          {
            v151 = v149 / v150;
            *(float *)(v134 + 20) = (float)(v151 * v147) + *(float *)(v134 + 20);
            *(float *)(v134 + 28) = (float)(v147 - (float)(v151 * v147)) + *(float *)(v134 + 28);
            v280 = v151 * v147;
            v152 = v151 * v281;
            *(float *)(v134 + 24) = v152 + *(float *)(v134 + 24);
            *(float *)(v134 + 32) = (float)(v281 - v152) + *(float *)(v134 + 32);
            v281 = v152;
          }
          v153.m_quad = (__m128)mB->m_invMasses;
          if ( v150 != 0.0 )
          {
            v154 = *(float *)(v135 + 28) * v150;
            if ( v154 > *(float *)(v135 + 32) )
              v154 = *(float *)(v135 + 32);
            v283 = v154 / v150;
            mB->m_invMasses.m_quad = _mm_mul_ps(
                                       mB->m_invMasses.m_quad,
                                       _mm_shuffle_ps(
                                         (__m128)COERCE_UNSIGNED_INT(v154 / v150),
                                         (__m128)COERCE_UNSIGNED_INT(v154 / v150),
                                         0));
          }
          v155 = _mm_shuffle_ps((__m128)LODWORD(v280), (__m128)LODWORD(v280), 0);
          v156 = _mm_shuffle_ps((__m128)LODWORD(v281), (__m128)LODWORD(v281), 0);
          v157 = _mm_mul_ps(p_mA->m_invMasses.m_quad, v155);
          v158 = _mm_mul_ps(mB->m_invMasses.m_quad, v155);
          v159 = _mm_mul_ps(_mm_shuffle_ps(v158, v158, 255), schemas->m_jac.m_linear0.m_quad);
          p_mA->m_linearVel.m_quad = _mm_add_ps(
                                       p_mA->m_linearVel.m_quad,
                                       _mm_mul_ps(_mm_shuffle_ps(v157, v157, 255), schemas->m_jac.m_linear0.m_quad));
          mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, v159);
          v160 = _mm_mul_ps(v158, schemas->m_jac.m_angular[1].m_quad);
          v161 = _mm_shuffle_ps(
                   (__m128)LODWORD(elemTemp->m_impulseApplied),
                   (__m128)LODWORD(elemTemp->m_impulseApplied),
                   0).m128_f32[0];
          p_mA->m_angularVel.m_quad = _mm_add_ps(
                                        _mm_mul_ps(v157, schemas->m_jac.m_angular[0].m_quad),
                                        p_mA->m_angularVel.m_quad);
          mB->m_angularVel.m_quad = _mm_add_ps(v160, mB->m_angularVel.m_quad);
          elemTemp->m_impulseApplied = v161 + v155.m128_f32[0];
          v162 = _mm_mul_ps(p_mA->m_invMasses.m_quad, v156);
          v163 = _mm_mul_ps(mB->m_invMasses.m_quad, v156);
          v164 = _mm_mul_ps(_mm_shuffle_ps(v163, v163, 255), schemas[1].m_jac.m_linear0.m_quad);
          p_mA->m_linearVel.m_quad = _mm_add_ps(
                                       p_mA->m_linearVel.m_quad,
                                       _mm_mul_ps(_mm_shuffle_ps(v162, v162, 255), schemas[1].m_jac.m_linear0.m_quad));
          mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, v164);
          v165 = _mm_mul_ps(v163, schemas[1].m_jac.m_angular[1].m_quad);
          v164.m128_f32[0] = _mm_shuffle_ps(
                               (__m128)LODWORD(elemTemp[1].m_impulseApplied),
                               (__m128)LODWORD(elemTemp[1].m_impulseApplied),
                               0).m128_f32[0]
                           + v156.m128_f32[0];
          p_mA->m_angularVel.m_quad = _mm_add_ps(
                                        p_mA->m_angularVel.m_quad,
                                        _mm_mul_ps(v162, schemas[1].m_jac.m_angular[0].m_quad));
          mB->m_angularVel.m_quad = _mm_add_ps(mB->m_angularVel.m_quad, v165);
          elemTemp[1].m_impulseApplied = v164.m128_f32[0];
          *(float *)v135 = *(float *)v135 - (float)(v280 * v136);
          mB->m_invMasses = (hkVector4f)v153.m_quad;
          v166 = *(_QWORD *)(v134 + 40);
          v167 = *(_DWORD *)(v166 + 12) + 1;
          *(_DWORD *)(v166 + 12) = v167;
          v168 = *(_QWORD *)(v134 + 40);
          if ( v167 == *(_DWORD *)(v168 + 40) * info->m_numMicroSteps )
          {
            v169 = *(float *)v135 - *(float *)(v135 + 4);
            v170 = *(_DWORD *)(v168 + 16) + 1;
            *(_DWORD *)(v168 + 16) = v170;
            if ( v170 == info->m_numSteps )
            {
              *(float *)v135 = v169;
              *(_DWORD *)(v135 + 4) = 0;
              *(_DWORD *)(v135 + 16) = 0;
            }
            else
            {
              v171 = (float)(v169 * info->m_integrateVelocityFactor.m_quad.m128_f32[0]) + *(float *)(v135 + 4);
              *(float *)(v135 + 4) = v171;
              *(float *)v135 = v169 + v171;
            }
            *(_DWORD *)(v135 + 12) = 0;
          }
          schemas = (hkpJacobian1dBilateralSchema *)((char *)schemas + 112);
          elemTemp += 2;
          if ( schemas->m_jac.m_linear0.m_quad.m128_i8[0] != 1 )
            continue;
          goto LABEL_7;
        default:
          __debugbreak();
          return 1;
      }
    }
  }
  return 1;
}();
          return 1;
      }
    }
  }
  return 1;
}

// File Line: 1859
// RVA: 0xDDCF10
__int64 __fastcall hkSolveIntegrateVelocitiesByTheSteps(
        hkpSolverInfo *info,
        int currentSolverStep,
        hkpVelocityAccumulator *accumulators,
        hkpVelocityAccumulator *accumulatorsEnd,
        hkBool *outSolveFinished)
{
  __m128 m_invNumSteps_low; // xmm1
  hkVector4f v6; // xmm0
  int v7; // eax
  hkSimdFloat32 sumVelFactor; // [rsp+30h] [rbp-28h] BYREF
  hkVector4f velocityField; // [rsp+40h] [rbp-18h] BYREF

  m_invNumSteps_low = (__m128)LODWORD(info->m_invNumSteps);
  velocityField.m_quad = (__m128)info->m_globalAccelerationPerSubStep;
  v6.m_quad = (__m128)info->m_invIntegrateVelocityFactor;
  outSolveFinished->m_bool = 0;
  v7 = info->m_numSteps - 1;
  sumVelFactor.m_real = _mm_mul_ps(
                          _mm_shuffle_ps(v6.m_quad, v6.m_quad, 0),
                          _mm_shuffle_ps(m_invNumSteps_low, m_invNumSteps_low, 0));
  if ( currentSolverStep < v7 )
  {
    hkSolver::integrateVelocities<0>(info, &velocityField, &sumVelFactor, accumulators, accumulatorsEnd);
  }
  else
  {
    outSolveFinished->m_bool = 1;
    hkSolver::integrateVelocities<1>(info, &velocityField, &sumVelFactor, accumulators, accumulatorsEnd);
  }
  return 1i64;
}

