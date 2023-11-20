// File Line: 183
// RVA: 0xDDF410
void __fastcall hkDebugPrintfAccumulators(int step, hkpSolverInfo *info, hkpVelocityAccumulator *accumulators, hkpVelocityAccumulator *accumulatorsEnd)
{
  ;
}

// File Line: 188
// RVA: 0xDDF420
void __fastcall hkSolver_solveStiffSpringChain(hkpSolverInfo *info, hkSolverStepTemp *temp, hkpVelocityAccumulator *accums, hkpJacobianStiffSpringChainSchema *chain, hkpSolverElemTemp *sr)
{
  __int64 v5; // rdx
  hkpJacobianStiffSpringChainSchema *v6; // r10
  hkpVelocityAccumulator *v7; // rdi
  hkpSolverInfo *v8; // r12
  unsigned __int16 *v9; // r11
  float *v10; // rbx
  unsigned __int16 *v11; // rsi
  float *v12; // r14
  __m128 v13; // xmm9
  __m128 v14; // xmm10
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
  int v27; // er9
  float v28; // xmm6_4
  float *v29; // r8
  signed __int64 v30; // rdx
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

  v5 = chain->m_numConstraints;
  v6 = chain + 1;
  v7 = accums;
  v8 = info;
  v9 = &chain[2 * v5 + 1].m_numConstraints;
  v10 = &chain[1].m_typeBuffer + 12 * v5;
  v11 = &chain[1].m_numConstraints + 30 * v5;
  v12 = (float *)(v11 - 2);
  *((_DWORD *)v11 - 1) = 0;
  v13 = (__m128)LODWORD(chain->m_tau);
  v14 = (__m128)LODWORD(chain->m_damping);
  v15 = (signed int)v5;
  v16 = _mm_shuffle_ps(v13, v13, 0);
  v17 = _mm_shuffle_ps(v14, v14, 0);
  if ( (signed int)v5 > 0 )
  {
    v18 = v10;
    v19 = (__m128 *)v6;
    v20 = (char *)v9 - (char *)v11;
    do
    {
      v21 = *v19;
      v22 = v19[2];
      v23 = *(unsigned int *)((char *)v12 + v20 + 8);
      v24 = (__m128 *)(&v7->m_type.m_storage + *(unsigned int *)((char *)v12 + v20 + 4));
      ++v12;
      v25 = (__m128 *)(&v7->m_type.m_storage + v23);
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
                  _mm_shuffle_ps(v8->m_invIntegrateVelocityFactor.m_quad, v8->m_invIntegrateVelocityFactor.m_quad, 0),
                  v16)));
      *v12 = (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v21, v21, 255)) * v16.m128_f32[0])
                           - (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v26, v26, 85))
                                           + COERCE_FLOAT(_mm_shuffle_ps(v26, v26, 0)))
                                   + COERCE_FLOAT(_mm_shuffle_ps(v26, v26, 170))))
                   - (float)(*(v12 - 1) * *(v18 - 3)))
           / *(v18 - 2);
      --v15;
    }
    while ( v15 );
  }
  v27 = v5 - 1;
  v28 = 0.0;
  if ( (signed int)v5 - 1 >= 0 )
  {
    v29 = (float *)&v11[2 * v27];
    v30 = (signed __int64)v6 + 48 * v27;
    v31 = &sr[v27];
    v32 = &v10[3 * v27 + 2];
    v33 = (char *)v9 - (char *)v11;
    do
    {
      v34 = v28;
      v35 = *v29;
      v36 = (__m128 *)(&v7->m_type.m_storage + *(unsigned int *)((char *)v29 + v33));
      v37 = (__m128 *)(&v7->m_type.m_storage + *(unsigned int *)((char *)v29 + v33 + 4));
      v38 = v34 * *v32;
      --v31;
      v32 -= 3;
      --v29;
      v28 = v35 - v38;
      v30 -= 48i64;
      --v27;
      v39 = _mm_shuffle_ps((__m128)LODWORD(v28), (__m128)LODWORD(v28), 0);
      v40 = _mm_mul_ps(v36[3], v39);
      v41 = _mm_mul_ps(v37[3], v39);
      v42 = _mm_mul_ps(_mm_shuffle_ps(v41, v41, 255), *(__m128 *)(v30 + 48));
      v36[1] = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v40, v40, 255), *(__m128 *)(v30 + 48)), v36[1]);
      v43 = _mm_sub_ps(v37[1], v42);
      v44 = *(__m128 *)(v30 + 80);
      v37[1] = v43;
      v45 = _mm_add_ps(_mm_mul_ps(*(__m128 *)(v30 + 64), v40), v36[2]);
      v37[2] = _mm_add_ps(_mm_mul_ps(v44, v41), v37[2]);
      v36[2] = v45;
      v31[1].m_impulseApplied = COERCE_FLOAT(
                                  _mm_shuffle_ps(
                                    (__m128)LODWORD(v31[1].m_impulseApplied),
                                    (__m128)LODWORD(v31[1].m_impulseApplied),
                                    0))
                              + v39.m128_f32[0];
    }
    while ( v27 >= 0 );
  }
}

// File Line: 233
// RVA: 0xDDF6E0
void __fastcall hkSolver_solveBallAndSocketChain(hkpSolverInfo *info, hkSolverStepTemp *temp, hkpVelocityAccumulator *accums, hkpJacobianBallSocketChainSchema *chain, hkpSolverElemTemp *sr)
{
  __int64 v5; // rbx
  hkpVelocityAccumulator *v6; // r14
  __m128 v7; // xmm5
  __int64 v8; // r10
  hkpJacobianBallSocketChainSchema *v9; // r15
  signed __int64 v10; // r11
  signed __int64 v11; // r13
  char *v12; // rbp
  char *v13; // rdx
  char *v14; // r8
  __m128 *v15; // rdi
  __m128 *v16; // r10
  __m128 *v17; // rsi
  signed __int64 v18; // r12
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
  int v38; // er10
  char *v39; // rdi
  signed __int64 v40; // rbx
  __m128 v41; // xmm6
  __m128 v42; // xmm7
  __m128 v43; // xmm5
  hkpSolverElemTemp *v44; // rsi
  __m128 *v45; // r11
  signed __int64 v46; // rdx
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
  hkpSolverInfo *v70; // [rsp+E0h] [rbp+8h]

  v70 = info;
  v5 = chain->m_numConstraints;
  v6 = accums;
  v7 = 0i64;
  v8 = 3 * (signed int)v5;
  v9 = chain + 1;
  v10 = v5 + v8 + 2 * v5;
  v11 = 0i64;
  v12 = (char *)chain + 48 * v8;
  v13 = (char *)chain + 48 * (v10 + 1);
  v14 = (char *)chain + 16 * ((signed int)v5 + 1 + 2i64 + 3 * v10);
  v15 = (__m128 *)&chain[1];
  v16 = (__m128 *)(v13 - 16);
  *((_OWORD *)v13 - 1) = 0i64;
  if ( (signed int)v5 > 0 )
  {
    v17 = (__m128 *)&chain[4].m_damping;
    v18 = (signed __int64)(v12 + 112);
    do
    {
      v19 = v17[-1];
      v20 = v17[-4];
      v21 = (__m128 *)(&v6->m_type.m_storage + *(unsigned int *)&v14[4 * v11]);
      v22 = (__m128 *)(&v6->m_type.m_storage + *(unsigned int *)&v14[4 * v11 + 4]);
      v23 = _mm_shuffle_ps((__m128)LODWORD(chain->m_tau), (__m128)LODWORD(chain->m_tau), 0);
      v24 = _mm_shuffle_ps((__m128)LODWORD(chain->m_damping), (__m128)LODWORD(chain->m_damping), 0);
      v25 = v22[5];
      v26 = v21[5];
      v27 = v21[4];
      v28 = _mm_mul_ps(
              _mm_shuffle_ps(v70->m_invIntegrateVelocityFactor.m_quad, v70->m_invIntegrateVelocityFactor.m_quad, 0),
              v23);
      v29 = _mm_sub_ps(v21[2], v26);
      v30 = _mm_sub_ps(v22[2], v25);
      v31 = *v16;
      v32 = _mm_sub_ps(_mm_sub_ps(v21[1], v27), _mm_sub_ps(v22[1], v22[4]));
      v33 = _mm_add_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_mul_ps(v25, v17[1]), _mm_mul_ps(v26, *v17)),
                  _mm_mul_ps(_mm_sub_ps(v27, v22[4]), v19)),
                v28),
              _mm_mul_ps(
                _mm_add_ps(_mm_add_ps(_mm_mul_ps(v30, v17[1]), _mm_mul_ps(v29, *v17)), _mm_mul_ps(v32, v19)),
                v24));
      v34 = _mm_add_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_mul_ps(v22[5], v17[-2]), _mm_mul_ps(v21[5], v17[-3])),
                  _mm_mul_ps(_mm_sub_ps(v21[4], v22[4]), v20)),
                v28),
              _mm_mul_ps(
                _mm_add_ps(_mm_add_ps(_mm_mul_ps(v29, v17[-3]), _mm_mul_ps(v30, v17[-2])), _mm_mul_ps(v32, v20)),
                v24));
      v35 = _mm_add_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_mul_ps(v21[5], v17[-6]), _mm_mul_ps(v22[5], v17[-5])),
                  _mm_mul_ps(_mm_sub_ps(v21[4], v22[4]), *v15)),
                v28),
              _mm_mul_ps(
                _mm_add_ps(_mm_add_ps(_mm_mul_ps(v29, v17[-6]), _mm_mul_ps(v30, v17[-5])), _mm_mul_ps(v32, *v15)),
                v24));
      v36 = _mm_mul_ps(_mm_shuffle_ps(*v15, *v15, 255), v23);
      ++v11;
      ++v16;
      v15 += 9;
      v17 += 9;
      v18 += 144i64;
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
                  _mm_mul_ps(_mm_shuffle_ps(v31, v31, 85), *(__m128 *)(v18 - 208)),
                  _mm_mul_ps(_mm_shuffle_ps(v31, v31, 0), *(__m128 *)(v18 - 224))),
                _mm_mul_ps(_mm_shuffle_ps(v31, v31, 170), *(__m128 *)(v18 - 192))));
      *v16 = _mm_add_ps(
               _mm_add_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v37, v37, 85), *(__m128 *)(v18 - 160)),
                 _mm_mul_ps(_mm_shuffle_ps(v37, v37, 0), *(__m128 *)(v18 - 176))),
               _mm_mul_ps(_mm_shuffle_ps(v37, v37, 170), *(__m128 *)(v18 - 144)));
    }
    while ( v11 < (signed int)v5 );
    v9 = chain + 1;
    v7 = 0i64;
  }
  v38 = v5 - 1;
  if ( (signed int)v5 - 1 >= 0 )
  {
    v39 = &v14[4 * v38];
    v40 = (signed __int64)(v12 + 160);
    v41 = _mm_shuffle_ps(v7, v7, 85);
    v42 = _mm_shuffle_ps(v7, v7, 0);
    v43 = _mm_shuffle_ps(v7, v7, 170);
    v44 = &sr[3 * v38];
    v45 = (__m128 *)&v13[16 * v38];
    v46 = 144i64 * v38;
    v47 = &sr[3 * v38 + 2];
    v48 = (__m128 *)(v46 + v40);
    v49 = &sr[3 * v38 + 1];
    v50 = (__m128 *)((char *)&v9[2].m_damping + v46);
    do
    {
      v51 = (__m128 *)(&v6->m_type.m_storage + *(unsigned int *)v39);
      v52 = (__m128 *)(&v6->m_type.m_storage + *((unsigned int *)v39 + 1));
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
      v44->m_impulseApplied = COERCE_FLOAT(
                                _mm_shuffle_ps(
                                  (__m128)LODWORD(v44->m_impulseApplied),
                                  (__m128)LODWORD(v44->m_impulseApplied),
                                  0))
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
      v49->m_impulseApplied = COERCE_FLOAT(
                                _mm_shuffle_ps(
                                  (__m128)LODWORD(v49->m_impulseApplied),
                                  (__m128)LODWORD(v49->m_impulseApplied),
                                  0))
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
      v47[3].m_impulseApplied = COERCE_FLOAT(
                                  _mm_shuffle_ps(
                                    (__m128)LODWORD(v47[3].m_impulseApplied),
                                    (__m128)LODWORD(v47[3].m_impulseApplied),
                                    0))
                              + v43.m128_f32[0];
    }
    while ( v38 >= 0 );
  }
}

// File Line: 298
// RVA: 0xDDFCB0
void __fastcall hkSolver_solvePoweredChain(hkpSolverInfo *solverInfo, hkSolverStepTemp *temp, hkpVelocityAccumulator *accums, hkpJacobianPoweredChainSchema *chain, hkpSolverElemTemp *sr)
{
  __int64 v5; // r10
  __m128 v6; // xmm0
  __m128 v7; // xmm1
  hkpVelocityAccumulator *v8; // r13
  __int64 v9; // r8
  int v10; // er14
  __int64 v11; // r12
  signed __int64 v12; // r15
  int v13; // esi
  __int64 v14; // rdi
  signed int v15; // ebx
  char v16; // dl
  int i; // eax
  int j; // eax
  __m128 v19; // xmm6
  int v20; // er9
  __int64 v21; // rsi
  __int64 v22; // rdi
  __m128 v23; // xmm9
  hkVector8f *v24; // rbx
  signed __int64 v25; // r11
  __m128 v26; // xmm8
  __m128 v27; // xmm7
  __m128 v28; // xmm11
  hkpSolverElemTemp *v29; // r14
  signed __int64 v30; // r10
  __m128 v31; // xmm10
  hkpSolverElemTemp *v32; // r12
  hkpSolverElemTemp *v33; // r15
  hkpSolverElemTemp *v34; // r8
  __m128 v35; // xmm3
  __m128 v36; // xmm7
  hkp1Lin2AngJacobian *v37; // rax
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
  float *v65; // rax
  __m128 v66; // xmm1
  __m128 v67; // xmm0
  __m128 v68; // xmm1
  __int64 v69; // rax
  __m128 v70; // xmm1
  hkpChainSolverInfo info; // [rsp+30h] [rbp-B1h]
  int modifiedConstraintIndex; // [rsp+140h] [rbp+5Fh]
  int modifiedCoordinateIndex; // [rsp+150h] [rbp+6Fh]
  float impulse; // [rsp+158h] [rbp+77h]

  v5 = chain->m_numConstraints;
  v6 = (__m128)LODWORD(chain->m_tau);
  v7 = (__m128)LODWORD(chain->m_damping);
  info.m_solverInfo = solverInfo;
  v8 = accums;
  info.m_j.m_storage = (hkp1Lin2AngJacobian *)&chain[1];
  info.m_schemaTau.m_real = _mm_shuffle_ps(v6, v6, 0);
  info.m_schemaDamping.m_real = _mm_shuffle_ps(v7, v7, 0);
  v9 = 3 * (signed int)v5;
  info.m_numConstraints.m_storage = v5;
  info.m_accumsBase.m_storage = v8;
  info.m_jAng.m_storage = (hkp2AngJacobian *)((char *)&chain[1] + 48 * v9);
  info.m_va.m_storage = (hkpVelocityAccumulatorOffset *)((char *)&chain[32 * (unsigned __int64)(unsigned int)v5 + 2]
                                                       + 80 * v9);
  info.m_triples.m_storage = (hkpConstraintChainMatrix6Triple *)((char *)&chain[1] + 80 * v9);
  info.m_motorsState.m_storage = (hkp3dAngularMotorSolverInfo *)(&chain[2].m_numConstraints
                                                               + 514 * (unsigned int)v5
                                                               + 40 * v9);
  info.m_velocitiesBuffer.m_storage = (hkVector8f *)((char *)&chain[31 * v5 + 2] + 80 * v9);
  info.m_gTempBuffer.m_storage = (hkVector8f *)((char *)&chain[1] + 80 * (v9 + 12 * v5));
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
      v15 = 0;
      do
      {
        v16 = ((unsigned __int8)info.m_motorsState.m_storage[v11].m_broken >> v15) & 3;
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
        v15 += 2;
        ++v13;
        ++v14;
      }
      while ( v15 < 6 );
      ++v10;
      ++v11;
      v12 += 8i64;
    }
    while ( v10 < info.m_numConstraints.m_storage );
  }
  hkPoweredChain_SolveConstraintMatrix_ComputeVectorG(&info, info.m_gTempBuffer.m_storage);
  modifiedConstraintIndex = -1;
  modifiedCoordinateIndex = -1;
  impulse = 0.0;
  hkPoweredChain_ScanAndEnableMotors(
    &info,
    &modifiedConstraintIndex,
    &modifiedCoordinateIndex,
    &impulse,
    info.m_motorsState.m_storage);
  for ( i = modifiedConstraintIndex; modifiedConstraintIndex >= 0; i = modifiedConstraintIndex )
  {
    hkPoweredChain_UpdateLuDecomposition(
      i,
      info.m_numConstraints.m_storage,
      info.m_motorsState.m_storage,
      info.m_triples.m_storage);
    hkPoweredChain_RestoreVelocityValue(
      modifiedConstraintIndex,
      modifiedCoordinateIndex,
      &info,
      info.m_velocitiesBuffer.m_storage);
    hkPoweredChain_SolveConstraintMatrix_ComputeVectorG(&info, info.m_gTempBuffer.m_storage);
    modifiedConstraintIndex = -1;
    modifiedCoordinateIndex = -1;
    impulse = 0.0;
    hkPoweredChain_ScanAndEnableMotors(
      &info,
      &modifiedConstraintIndex,
      &modifiedCoordinateIndex,
      &impulse,
      info.m_motorsState.m_storage);
  }
  hkPoweredChain_SolveConstraintMatrix_ComputeVectorG(&info, info.m_gTempBuffer.m_storage);
  modifiedConstraintIndex = -1;
  modifiedCoordinateIndex = -1;
  impulse = 0.0;
  hkPoweredChain_ScanAndDisableMotors(
    &info,
    &modifiedConstraintIndex,
    &modifiedCoordinateIndex,
    &impulse,
    info.m_motorsState.m_storage);
  for ( j = modifiedConstraintIndex; modifiedConstraintIndex >= 0; j = modifiedConstraintIndex )
  {
    hkPoweredChain_UpdateLuDecomposition(
      j,
      info.m_numConstraints.m_storage,
      info.m_motorsState.m_storage,
      info.m_triples.m_storage);
    hkPoweredChain_OverwriteVelocityWithExplicitImpulse(
      modifiedConstraintIndex,
      modifiedCoordinateIndex,
      info.m_motorsState.m_storage,
      info.m_velocitiesBuffer.m_storage);
    hkPoweredChain_SolveConstraintMatrix_ComputeVectorG(&info, info.m_gTempBuffer.m_storage);
    modifiedConstraintIndex = -1;
    modifiedCoordinateIndex = -1;
    impulse = 0.0;
    hkPoweredChain_ScanAndDisableMotors(
      &info,
      &modifiedConstraintIndex,
      &modifiedCoordinateIndex,
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
    *(_QWORD *)&modifiedCoordinateIndex = &sr[6 * v20 + 5];
    *(_QWORD *)&modifiedConstraintIndex = &sr[6 * v20 + 4];
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
      v37 = info.m_j.m_storage;
      v38 = (__m128 *)(&v8->m_type.m_storage + info.m_va.m_storage[v21].m_offset);
      v39 = (__m128 *)(&v8->m_type.m_storage + info.m_va.m_storage[v21 + 1].m_offset);
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
      v45 = *(__m128 *)((char *)&v37[-1] + v30 - 16);
      v39[1] = v44;
      v46 = _mm_add_ps(_mm_mul_ps(*(__m128 *)((char *)&v37[-1] + v30 - 32), v42), v38[2]);
      v39[2] = _mm_add_ps(_mm_mul_ps(v45, v40), v39[2]);
      v47 = _mm_mul_ps(v23, v39[3]);
      v38[2] = v46;
      v48 = _mm_mul_ps(v23, v38[3]);
      v29->m_impulseApplied = COERCE_FLOAT(
                                _mm_shuffle_ps(
                                  (__m128)LODWORD(v29->m_impulseApplied),
                                  (__m128)LODWORD(v29->m_impulseApplied),
                                  0))
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
      v34->m_impulseApplied = COERCE_FLOAT(
                                _mm_shuffle_ps(
                                  (__m128)LODWORD(v34->m_impulseApplied),
                                  (__m128)LODWORD(v34->m_impulseApplied),
                                  0))
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
      v33->m_impulseApplied = COERCE_FLOAT(
                                _mm_shuffle_ps(
                                  (__m128)LODWORD(v33->m_impulseApplied),
                                  (__m128)LODWORD(v33->m_impulseApplied),
                                  0))
                            + v27.m128_f32[0];
      v62 = _mm_add_ps(_mm_mul_ps(v61, *(__m128 *)((char *)&info.m_jAng.m_storage[-1] + v25 - 16)), v39[2]);
      v38[2] = _mm_add_ps(
                 _mm_mul_ps(
                   _mm_mul_ps(v31, v38[3]),
                   *(__m128 *)((char *)&info.m_jAng.m_storage[-2].m_angular[0].m_quad + v25)),
                 v38[2]);
      v39[2] = v62;
      v63 = _mm_mul_ps(v28, v39[3]);
      v32->m_impulseApplied = COERCE_FLOAT(
                                _mm_shuffle_ps(
                                  (__m128)LODWORD(v32->m_impulseApplied),
                                  (__m128)LODWORD(v32->m_impulseApplied),
                                  0))
                            + v31.m128_f32[0];
      v64 = _mm_add_ps(_mm_mul_ps(v63, *(__m128 *)((char *)&info.m_jAng.m_storage->m_angular[-1].m_quad + v25)), v39[2]);
      v38[2] = _mm_add_ps(
                 _mm_mul_ps(
                   _mm_mul_ps(v28, v38[3]),
                   *(__m128 *)((char *)&info.m_jAng.m_storage[-1].m_angular[0].m_quad + v25)),
                 v38[2]);
      v39[2] = v64;
      v65 = *(float **)&modifiedConstraintIndex;
      *(_QWORD *)&modifiedConstraintIndex -= 24i64;
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
      *v65 = COERCE_FLOAT(_mm_shuffle_ps((__m128)*(unsigned int *)v65, (__m128)*(unsigned int *)v65, 0))
           + v28.m128_f32[0];
      v67 = _mm_mul_ps(
              _mm_mul_ps(v19, v38[3]),
              *(__m128 *)((char *)&info.m_jAng.m_storage[3].m_angular[0].m_quad + v25));
      v68 = _mm_mul_ps(v66, *(__m128 *)((char *)&info.m_jAng.m_storage[3].m_angular[1].m_quad + v25));
      --v20;
      *(_QWORD *)&modifiedCoordinateIndex -= 24i64;
      v69 = *(_QWORD *)&modifiedCoordinateIndex;
      v70 = _mm_add_ps(v68, v39[2]);
      v38[2] = _mm_add_ps(v67, v38[2]);
      v39[2] = v70;
      *(float *)(v69 + 24) = COERCE_FLOAT(
                               _mm_shuffle_ps(
                                 (__m128)*(unsigned int *)(v69 + 24),
                                 (__m128)*(unsigned int *)(v69 + 24),
                                 0))
                           + v19.m128_f32[0];
    }
    while ( v20 >= 0 );
  }
}

// File Line: 460
// RVA: 0xDE0480
void __fastcall hkSolver_buildStableJacobiansForBallSocketChain(hkpSolverInfo *solverInfo, hkpStableBallSocketSchema *schema, hkpVelocityAccumulator *regA, hkpVelocityAccumulator *regB, hkSimdFloat32 *virtMassFactor, hkp1Lin2AngJacobian *jacobiansOut)
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
  hkp1Lin2AngJacobian *v50; // rax
  __m128 v51; // xmm12
  __m128 v52; // xmm7
  signed __int64 v53; // rcx
  __m128 v54; // xmm2
  __m128 v55; // xmm10
  __m128 v56; // xmm3
  hkVector4f v57; // xmm1
  __m128 v58; // xmm3
  __m128 v59; // xmm4
  __m128 v60; // xmm11
  __m128 v61; // xmm6
  __m128 v62; // xmm12
  __m128 v63; // xmm2
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
  __m128 v90; // [rsp+50h] [rbp-D8h]
  __m128 v91; // [rsp+60h] [rbp-C8h]
  __m128 v92; // [rsp+70h] [rbp-B8h]

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
  v46 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(schema->m_armDirA.m_quad, v27.m_quad, 201), v36),
          _mm_mul_ps(v39, v27.m_quad));
  v47 = _mm_mul_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v43, v43, 85), _mm_shuffle_ps(v43, v43, 0)),
            _mm_shuffle_ps(v43, v43, 170)),
          v36);
  v48 = _mm_mul_ps(v44, v29.m_quad);
  v49 = _mm_add_ps(
          _mm_add_ps(v47, _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v38, v38), (__m128)xmmword_141A711B0), v27.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v46, v46, 201), v38));
  v50 = jacobiansOut;
  v51 = _mm_sub_ps(_mm_add_ps(v9, regB->m_scratch3.m_quad), v8);
  v52 = _mm_shuffle_ps(v44, v44, 201);
  v53 = 0i64;
  v54 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(schema->m_armDirB.m_quad, v29.m_quad, 201), v44),
          _mm_mul_ps(v52, v29.m_quad));
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
  v90 = transform.m_quad;
  v62 = _mm_mul_ps(_mm_add_ps(v51, _mm_sub_ps(v60, v55)), _mm_shuffle_ps(v57.m_quad, v57.m_quad, 0));
  v92 = stru_141A71280.m_quad;
  v86 = _mm_mul_ps(v38, v38);
  v91 = direction.m_quad;
  v87 = _mm_mul_ps(v45, v45);
  do
  {
    v63 = *(__m128 *)((char *)&v90 + v53 * 16);
    v50->m_linear0.m_quad = v63;
    v64 = _mm_shuffle_ps(v63, v63, 201);
    v65 = _mm_sub_ps(_mm_mul_ps(v55, v64), _mm_mul_ps(v63, v59));
    v66 = _mm_shuffle_ps(v65, v65, 201);
    v67 = _mm_sub_ps(_mm_mul_ps(v63, v61), _mm_mul_ps(v60, v64));
    v68 = _mm_mul_ps(v36, v66);
    v69 = _mm_shuffle_ps(v67, v67, 201);
    v70 = _mm_sub_ps(_mm_mul_ps(v66, v39), _mm_mul_ps(v66, v36));
    v71 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v68, v68, 85), _mm_shuffle_ps(v68, v68, 0)),
            _mm_shuffle_ps(v68, v68, 170));
    v72 = _mm_mul_ps(v44, v69);
    v73 = _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(v71, v36), _mm_mul_ps(_mm_sub_ps(v86, (__m128)xmmword_141A711B0), v66)),
            _mm_mul_ps(_mm_shuffle_ps(v70, v70, 201), v38));
    v74 = _mm_add_ps(v73, v73);
    v50->m_angular[0].m_quad = v74;
    v75 = _mm_sub_ps(_mm_mul_ps(v69, v52), _mm_mul_ps(v69, v44));
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
    v50->m_angular[1].m_quad = v77;
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
    ++v50;
    v82 = _mm_add_ps(_mm_shuffle_ps(v81, v81, 177), v81);
    v83 = _mm_rcp_ps(v82);
    v50[-1].m_angular[1].m_quad = _mm_shuffle_ps(v77, _mm_unpackhi_ps(v77, v82), 196);
    v59 = v88;
    v50[-1].m_angular[0].m_quad = _mm_shuffle_ps(
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
    v50[-1].m_linear0.m_quad = _mm_shuffle_ps(
                                 v50[-1].m_linear0.m_quad,
                                 _mm_unpackhi_ps(
                                   v50[-1].m_linear0.m_quad,
                                   _mm_or_ps(_mm_shuffle_ps(v85, v85, 177), v85)),
                                 196);
  }
  while ( v53 < 3 );
}

// File Line: 577
// RVA: 0xDE0A10
void __usercall hkSolver_solveStabilizedBallAndSocketChain(hkpSolverInfo *info@<rcx>, hkSolverStepTemp *temp@<rdx>, hkpVelocityAccumulator *accumBase@<r8>, hkpJacobianStabilizedBallSocketChainSchema *chain@<r9>, hkpVelocityAccumulator *a5@<rbx>, hkpSolverElemTemp *sr)
{
  __int64 v6; // rsi
  int v7; // er13
  hkpJacobianStabilizedBallSocketChainSchema *v8; // r14
  hkpVelocityAccumulator *v9; // r12
  hkLifoAllocator *v10; // rax
  hkp1Lin2AngJacobian *v11; // rdi
  int v12; // edx
  char *v13; // rcx
  int v14; // eax
  int v15; // ebx
  int v16; // er15
  int v17; // ebx
  int v18; // er9
  __int64 v19; // rdx
  __int64 v20; // rbx
  signed __int64 v21; // r10
  hkpVelocityAccumulatorOffset *v22; // r15
  int v23; // er12
  __int64 v24; // r9
  hkpVelocityAccumulator *v25; // r8
  hkLifoAllocator *v26; // rax
  hkpConstraintChainMatrixTriple *v27; // rbx
  int v28; // edx
  char *v29; // rcx
  signed int v30; // eax
  int v31; // eax
  int v32; // er9
  float v33; // xmm1_4
  __m128 v34; // xmm10
  signed __int64 v35; // r11
  unsigned __int64 v36; // r9
  __m128 *v37; // r8
  __m128 v38; // xmm11
  __m128 v39; // xmm12
  __m128 *v40; // rdi
  signed __int64 v41; // r10
  __m128 *v42; // rcx
  __m128 *v43; // rax
  __m128 v44; // xmm4
  __m128 v45; // xmm1
  __m128 v46; // xmm3
  __m128 v47; // xmm7
  __m128 v48; // xmm5
  __m128 v49; // xmm0
  __m128 v50; // xmm3
  __m128 v51; // xmm2
  __m128 v52; // xmm1
  __m128 v53; // xmm9
  __m128 v54; // xmm9
  int v55; // esi
  hkpVelocityAccumulatorOffset *v56; // rdi
  __m128 v57; // xmm6
  __m128 v58; // xmm7
  __m128 *v59; // r10
  float *v60; // r14
  __m128 *v61; // rbx
  signed __int64 v62; // r11
  __int64 v63; // r15
  float *v64; // rdx
  __m128 *v65; // rax
  __m128 *v66; // rcx
  __m128 v67; // xmm5
  __m128 v68; // xmm3
  __m128 v69; // xmm4
  __m128 v70; // xmm1
  __m128 v71; // xmm0
  __m128 v72; // xmm1
  __m128 v73; // xmm0
  __m128 v74; // xmm4
  __m128 v75; // xmm3
  __m128 v76; // xmm1
  __m128 v77; // xmm0
  __m128 v78; // xmm1
  __m128 v79; // xmm0
  __m128 v80; // xmm4
  __m128 v81; // xmm3
  __m128 v82; // xmm1
  __m128 v83; // xmm0
  int v84; // eax
  char *v85; // rdi
  signed int v86; // ebx
  hkLifoAllocator *v87; // rax
  int v88; // er8
  int v89; // eax
  char *v90; // rdi
  signed int v91; // ebx
  hkLifoAllocator *v92; // rax
  int v93; // er8
  hkResult result[2]; // [rsp+40h] [rbp-B8h]
  hkSimdFloat32 virtMassFactor; // [rsp+50h] [rbp-A8h]
  hkp1Lin2AngJacobian *array; // [rsp+60h] [rbp-98h]
  int v97; // [rsp+68h] [rbp-90h]
  int v98; // [rsp+6Ch] [rbp-8Ch]
  void *v99; // [rsp+70h] [rbp-88h]
  hkpConstraintChainMatrixTriple *v100; // [rsp+78h] [rbp-80h]
  int v101; // [rsp+80h] [rbp-78h]
  int v102; // [rsp+84h] [rbp-74h]
  void *p; // [rsp+88h] [rbp-70h]
  int v104; // [rsp+90h] [rbp-68h]
  hkpSolverInfo *retaddr; // [rsp+148h] [rbp+50h]
  hkpVelocityAccumulator *v106; // [rsp+158h] [rbp+60h]
  hkpVelocityAccumulator *v107; // [rsp+160h] [rbp+68h]
  __int64 v108; // [rsp+168h] [rbp+70h]

  v107 = accumBase;
  v106 = a5;
  v6 = chain->m_numConstraints;
  v7 = 0;
  v8 = chain;
  v9 = accumBase;
  LODWORD(v107) = chain->m_numConstraints;
  array = 0i64;
  v97 = 0;
  v98 = 2147483648;
  LODWORD(v100) = 3 * v6;
  if ( 3 * (_DWORD)v6 )
  {
    v10 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v11 = (hkp1Lin2AngJacobian *)v10->m_cur;
    v12 = (144 * v6 + 127) & 0xFFFFFF80;
    v13 = (char *)v11 + v12;
    if ( v12 > v10->m_slabSize || v13 > v10->m_end )
    {
      v11 = (hkp1Lin2AngJacobian *)hkLifoAllocator::allocateFromNewSlab(v10, v12);
      array = v11;
    }
    else
    {
      v10->m_cur = v13;
      array = v11;
    }
  }
  else
  {
    v11 = 0i64;
    array = 0i64;
  }
  v14 = v8->m_numConstraints;
  v15 = 3 * v6 | 0x80000000;
  v99 = v11;
  v16 = 3 * v14;
  v98 = v15;
  v17 = v15 & 0x3FFFFFFF;
  if ( v17 < 3 * v14 )
  {
    v18 = 3 * v14;
    if ( v16 < 2 * v17 )
      v18 = 2 * v17;
    hkArrayUtil::_reserve(result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v18, 48);
    v11 = array;
  }
  v19 = v8->m_numConstraints;
  v97 = v16;
  v20 = 0i64;
  v21 = (signed __int64)&v8[1];
  *(_QWORD *)&result[0].m_enum = v6;
  v22 = (hkpVelocityAccumulatorOffset *)((char *)v8 + 16 * ((signed int)v19 + 1 + 4 * v19 + 2));
  if ( (signed int)v6 > 0 )
  {
    v23 = 0;
    while ( 1 )
    {
      v24 = v22[v20 + 1].m_offset;
      v25 = (hkpVelocityAccumulator *)((char *)v106 + v22[v20].m_offset);
      virtMassFactor.m_real = _mm_shuffle_ps(
                                (__m128)LODWORD(v8->m_virtualMassFactor),
                                (__m128)LODWORD(v8->m_virtualMassFactor),
                                0);
      hkSolver_buildStableJacobiansForBallSocketChain(
        retaddr,
        (hkpStableBallSocketSchema *)(v21 + ((signed __int64)v7 << 6)),
        v25,
        (hkpVelocityAccumulator *)((char *)v106 + v24),
        &virtMassFactor,
        &v11[v23]);
      v11 = array;
      ++v20;
      ++v7;
      v23 += 3;
      if ( v20 >= *(_QWORD *)&result[0].m_enum )
        break;
      v21 = (signed __int64)&v8[1];
    }
    LODWORD(v6) = (_DWORD)v107;
    v9 = v106;
  }
  v102 = 2147483648;
  v104 = v6;
  v100 = 0i64;
  v101 = 0;
  if ( (_DWORD)v6 )
  {
    v26 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v27 = (hkpConstraintChainMatrixTriple *)v26->m_cur;
    v28 = (144 * v6 + 127) & 0xFFFFFF80;
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
  v100 = v27;
  p = v27;
  v102 = v6 | 0x80000000;
  v30 = (v6 | 0x80000000) & 0x3FFFFFFF;
  if ( v30 < (signed int)v6 )
  {
    v31 = 2 * v30;
    v32 = v6;
    if ( (signed int)v6 < v31 )
      v32 = v31;
    hkArrayUtil::_reserve(
      (hkResult *)&v107,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v100,
      v32,
      144);
    v27 = v100;
  }
  v33 = v8->m_cfm;
  v101 = v6;
  buildConstraintMatrixLuDecompositionForBallAndSocketChain_outOfLine(v6, v33, v11, v22, v9, v27, 144 * v6);
  v34 = 0i64;
  v35 = 0i64;
  v36 = (unsigned __int64)&v8[2 * (unsigned __int64)v8->m_numConstraints + 1].m_damping;
  v37 = (__m128 *)(v36 - 16);
  *(_OWORD *)(v36 - 16) = 0i64;
  v38 = _mm_shuffle_ps((__m128)LODWORD(v8->m_tau), (__m128)LODWORD(v8->m_tau), 0);
  v39 = _mm_shuffle_ps((__m128)LODWORD(v8->m_damping), (__m128)LODWORD(v8->m_damping), 0);
  if ( (signed int)v6 > 0 )
  {
    v40 = (__m128 *)v11[2].m_angular;
    v41 = (signed __int64)&v27->m_diagonalInv.m_col2;
    do
    {
      v42 = (__m128 *)(&v9->m_type.m_storage + v22[v35].m_offset);
      v43 = (__m128 *)(&v9->m_type.m_storage + v22[v35 + 1].m_offset);
      v44 = _mm_sub_ps(v43[2], v43[5]);
      v45 = _mm_sub_ps(v42[2], v42[5]);
      v46 = _mm_sub_ps(_mm_sub_ps(v42[1], v42[4]), _mm_sub_ps(v43[1], v43[4]));
      v47 = _mm_mul_ps(
              _mm_add_ps(_mm_add_ps(_mm_mul_ps(v40[1], v44), _mm_mul_ps(*v40, v45)), _mm_mul_ps(v40[-1], v46)),
              v39);
      v48 = _mm_mul_ps(
              _mm_add_ps(_mm_add_ps(_mm_mul_ps(v40[-3], v45), _mm_mul_ps(v40[-2], v44)), _mm_mul_ps(v40[-4], v46)),
              v39);
      v49 = _mm_mul_ps(v40[-7], v46);
      v50 = *v37;
      v51 = _mm_mul_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(v40[-6], v45), _mm_mul_ps(v40[-5], v44)), v49), v39);
      v52 = _mm_mul_ps(_mm_shuffle_ps(*v37, *v37, 85), *(__m128 *)(v41 - 64));
      v53 = _mm_movelh_ps(
              _mm_unpacklo_ps(
                _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v40[-7], v40[-7], 255), v38),
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v51, v51, 85), _mm_shuffle_ps(v51, v51, 0)),
                    _mm_shuffle_ps(v51, v51, 170))),
                _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v40[-4], v40[-4], 255), v38),
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v48, v48, 85), _mm_shuffle_ps(v48, v48, 0)),
                    _mm_shuffle_ps(v48, v48, 170)))),
              _mm_unpacklo_ps(
                _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v40[-1], v40[-1], 255), v38),
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v47, v47, 85), _mm_shuffle_ps(v47, v47, 0)),
                    _mm_shuffle_ps(v47, v47, 170))),
                aabbOut.m_quad));
      ++v35;
      ++v37;
      v40 += 9;
      v41 += 144i64;
      v54 = _mm_sub_ps(
              v53,
              _mm_add_ps(
                _mm_add_ps(v52, _mm_mul_ps(_mm_shuffle_ps(v50, v50, 0), *(__m128 *)(v41 - 224))),
                _mm_mul_ps(_mm_shuffle_ps(v50, v50, 170), *(__m128 *)(v41 - 192))));
      *v37 = _mm_add_ps(
               _mm_add_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v54, v54, 85), *(__m128 *)(v41 - 160)),
                 _mm_mul_ps(_mm_shuffle_ps(v54, v54, 0), *(__m128 *)(v41 - 176))),
               _mm_mul_ps(_mm_shuffle_ps(v54, v54, 170), *(__m128 *)(v41 - 144)));
    }
    while ( v35 < (signed int)v6 );
  }
  v55 = v6 - 1;
  if ( v55 >= 0 )
  {
    v56 = &v22[v55];
    v57 = _mm_shuffle_ps((__m128)0i64, (__m128)0i64, 85);
    v58 = _mm_shuffle_ps((__m128)0i64, (__m128)0i64, 0);
    v59 = (__m128 *)(v36 + 16i64 * v55);
    v60 = (float *)(v108 + 12i64 * v55);
    v61 = &v27[v55].m_upper.m_col2.m_quad;
    v62 = (signed __int64)&array[3 * v55 + 1].m_angular[1];
    v63 = v108 + 4i64 * (3 * v55 + 2);
    v64 = (float *)(v108 + 4i64 * (3 * v55 + 1));
    do
    {
      v65 = (__m128 *)(&v9->m_type.m_storage + v56->m_offset);
      v66 = (__m128 *)(&v9->m_type.m_storage + v56[1].m_offset);
      v67 = _mm_sub_ps(
              *v59,
              _mm_add_ps(_mm_add_ps(_mm_mul_ps(v61[-2], v58), _mm_mul_ps(v61[-1], v57)), _mm_mul_ps(v34, *v61)));
      v58 = _mm_shuffle_ps(v67, v67, 0);
      v57 = _mm_shuffle_ps(v67, v67, 85);
      v34 = _mm_shuffle_ps(v67, v67, 170);
      v68 = _mm_mul_ps(v58, v65[3]);
      v69 = _mm_mul_ps(v58, v66[3]);
      v70 = _mm_mul_ps(_mm_shuffle_ps(v69, v69, 255), *(__m128 *)(v62 - 80));
      v65[1] = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v68, v68, 255), *(__m128 *)(v62 - 80)), v65[1]);
      v71 = _mm_sub_ps(v66[1], v70);
      v72 = *(__m128 *)(v62 - 48);
      v66[1] = v71;
      v73 = _mm_add_ps(_mm_mul_ps(*(__m128 *)(v62 - 64), v68), v65[2]);
      v66[2] = _mm_add_ps(_mm_mul_ps(v72, v69), v66[2]);
      v74 = _mm_mul_ps(v57, v66[3]);
      v65[2] = v73;
      v75 = _mm_mul_ps(v57, v65[3]);
      *v60 = COERCE_FLOAT(_mm_shuffle_ps((__m128)*(unsigned int *)v60, (__m128)*(unsigned int *)v60, 0))
           + v58.m128_f32[0];
      v76 = _mm_mul_ps(_mm_shuffle_ps(v74, v74, 255), *(__m128 *)(v62 - 32));
      v65[1] = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v75, v75, 255), *(__m128 *)(v62 - 32)), v65[1]);
      v77 = _mm_sub_ps(v66[1], v76);
      v78 = *(__m128 *)v62;
      v66[1] = v77;
      v79 = _mm_add_ps(_mm_mul_ps(*(__m128 *)(v62 - 16), v75), v65[2]);
      v66[2] = _mm_add_ps(_mm_mul_ps(v78, v74), v66[2]);
      v80 = _mm_mul_ps(v34, v66[3]);
      v65[2] = v79;
      v81 = _mm_mul_ps(v34, v65[3]);
      *v64 = COERCE_FLOAT(_mm_shuffle_ps((__m128)*(unsigned int *)v64, (__m128)*(unsigned int *)v64, 0))
           + v57.m128_f32[0];
      v65[1] = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v81, v81, 255), *(__m128 *)(v62 + 16)), v65[1]);
      v63 -= 12i64;
      v60 -= 3;
      v64 -= 3;
      --v56;
      v62 -= 144i64;
      v61 -= 9;
      --v59;
      --v55;
      v82 = _mm_mul_ps(*(__m128 *)(v62 + 192), v80);
      v66[1] = _mm_sub_ps(v66[1], _mm_mul_ps(_mm_shuffle_ps(v80, v80, 255), *(__m128 *)(v62 + 160)));
      v83 = _mm_add_ps(_mm_mul_ps(*(__m128 *)(v62 + 176), v81), v65[2]);
      v66[2] = _mm_add_ps(v82, v66[2]);
      v65[2] = v83;
      *(float *)(v63 + 12) = COERCE_FLOAT(
                               _mm_shuffle_ps(
                                 (__m128)*(unsigned int *)(v63 + 12),
                                 (__m128)*(unsigned int *)(v63 + 12),
                                 0))
                           + v34.m128_f32[0];
    }
    while ( v55 >= 0 );
  }
  v84 = v101;
  v85 = (char *)p;
  if ( p == v100 )
    v84 = 0;
  v101 = v84;
  v86 = (144 * v104 + 127) & 0xFFFFFF80;
  v87 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v88 = (v86 + 15) & 0xFFFFFFF0;
  if ( v86 > v87->m_slabSize || &v85[v88] != v87->m_cur || v87->m_firstNonLifoEnd == v85 )
    hkLifoAllocator::slowBlockFree(v87, v85, v88);
  else
    v87->m_cur = v85;
  v101 = 0;
  if ( v102 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v100,
      144 * (v102 & 0x3FFFFFFF));
  v89 = v97;
  v90 = (char *)v99;
  v100 = 0i64;
  v102 = 2147483648;
  if ( v99 == array )
    v89 = 0;
  v97 = v89;
  v91 = (48 * (_DWORD)v100 + 127) & 0xFFFFFF80;
  v92 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v93 = (v91 + 15) & 0xFFFFFFF0;
  if ( v91 > v92->m_slabSize || &v90[v93] != v92->m_cur || v92->m_firstNonLifoEnd == v90 )
    hkLifoAllocator::slowBlockFree(v92, v90, v93);
  else
    v92->m_cur = v90;
  v97 = 0;
  if ( v98 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      48 * (v98 & 0x3FFFFFFF));
}

// File Line: 1146
// RVA: 0xDE1300
void __fastcall updateSumVelocities_0_(hkpSolverInfo *info, hkVector4f *velocityField, hkSimdFloat32 *sumVelFactor, hkpVelocityAccumulator *m)
{
  hkVector4f v4; // xmm2
  __m128 v5; // xmm3
  __m128 v6; // xmm4
  __m128 v7; // xmm1
  hkVector4f v8; // xmm2
  hkVector4f v9; // xmm1
  __m128 v10; // xmm0

  v4.m_quad = (__m128)info->m_integrateVelocityFactor;
  v5 = _mm_sub_ps(m->m_linearVel.m_quad, m->m_scratch0.m_quad);
  v6 = _mm_sub_ps(m->m_angularVel.m_quad, m->m_scratch1.m_quad);
  v7 = v4.m_quad;
  v8.m_quad = _mm_add_ps(_mm_mul_ps(v4.m_quad, v6), m->m_scratch1.m_quad);
  v9.m_quad = _mm_add_ps(_mm_mul_ps(v7, v5), m->m_scratch0.m_quad);
  m->m_scratch1 = (hkVector4f)v8.m_quad;
  m->m_scratch0 = (hkVector4f)v9.m_quad;
  v10 = (__m128)LODWORD(m->m_gravityFactor);
  m->m_angularVel.m_quad = _mm_add_ps(v8.m_quad, v6);
  m->m_linearVel.m_quad = _mm_add_ps(
                            _mm_mul_ps(_mm_shuffle_ps(v10, v10, 0), velocityField->m_quad),
                            _mm_add_ps(v9.m_quad, v5));
}

// File Line: 1175
// RVA: 0xDE1DD0
void __fastcall hkSolver::integrateVelocities<0>(hkpSolverInfo *info, hkVector4f *velocityField, hkSimdFloat32 *sumVelFactor, hkpVelocityAccumulator *acc, hkpVelocityAccumulator *accEnd)
{
  hkpVelocityAccumulator *v5; // r8
  hkVector4f *v6; // r10
  __m128i v7; // xmm3
  __m128i v8; // xmm2
  __int64 v9; // rdx
  __m128 v10; // xmm4
  __m128 v11; // xmm1
  __m128 v12; // xmm5
  hkVector4f v13; // xmm0
  __m128 v14; // xmm1
  hkVector4f v15; // xmm4
  hkVector4f v16; // xmm3
  __m128 v17; // xmm4
  __m128 v18; // xmm3
  __m128 v19; // xmm4
  hkVector4f v20; // xmm1
  __m128 v21; // xmm0
  __m128i v22; // xmm4
  __m128i v23; // xmm2
  __int64 v24; // rdx
  __m128 v25; // xmm3
  __m128 v26; // xmm1
  __m128 v27; // xmm5
  hkVector4f v28; // xmm0
  __m128 v29; // xmm1
  hkVector4f v30; // xmm4
  hkVector4f v31; // xmm3
  __m128 v32; // xmm4
  __m128 v33; // xmm3
  __m128 v34; // xmm4
  hkVector4f v35; // xmm1
  __m128 v36; // xmm0

  v5 = accEnd;
  v6 = velocityField;
  if ( !accEnd )
    v5 = (hkpVelocityAccumulator *)-1i64;
  while ( acc < v5 )
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
        v7 = _mm_load_si128((const __m128i *)&acc->m_linearVel);
        v8 = _mm_load_si128((const __m128i *)&acc->m_angularVel);
        v9 = acc->m_deactivationClass;
        v10 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v7, 1u), 1u);
        v11 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v8, 1u), 1u);
        v12 = _mm_add_ps(
                _mm_mul_ps(
                  _mm_shuffle_ps(
                    (__m128)LODWORD(info->m_deactivationInfo[v9].m_angularVelocityThresholdInv),
                    (__m128)LODWORD(info->m_deactivationInfo[v9].m_angularVelocityThresholdInv),
                    0),
                  v11),
                _mm_mul_ps(
                  _mm_shuffle_ps(
                    (__m128)LODWORD(info->m_deactivationInfo[v9].m_linearVelocityThresholdInv),
                    (__m128)LODWORD(info->m_deactivationInfo[v9].m_linearVelocityThresholdInv),
                    0),
                  v10));
        if ( (_mm_movemask_ps(
                _mm_and_ps(
                  _mm_and_ps(
                    _mm_and_ps(_mm_cmpltps(v10, *(__m128 *)maxVelf), _mm_cmpltps(v11, *(__m128 *)maxVelf)),
                    _mm_cmpeqps((__m128)v7, (__m128)v7)),
                  _mm_cmpeqps((__m128)v8, (__m128)v8))) & 7) != 7 )
        {
          acc->m_linearVel = (hkVector4f)transform.m_quad;
          acc->m_angularVel = (hkVector4f)transform.m_quad;
        }
        if ( (_mm_movemask_ps(_mm_cmpleps(v12, query.m_quad)) & 7) == 7 )
        {
          if ( (_mm_movemask_ps(
                  _mm_cmpleps(
                    v12,
                    _mm_shuffle_ps(
                      (__m128)LODWORD(info->m_deactivationInfo[v9].m_relativeSleepVelocityThreshold),
                      (__m128)LODWORD(info->m_deactivationInfo[v9].m_relativeSleepVelocityThreshold),
                      0))) & 7) == 7 )
          {
            v13.m_quad = 0i64;
            acc->m_linearVel = 0i64;
          }
          else
          {
            v14 = _mm_shuffle_ps(
                    (__m128)LODWORD(info->m_deactivationInfo[v9].m_slowObjectVelocityMultiplier),
                    (__m128)LODWORD(info->m_deactivationInfo[v9].m_slowObjectVelocityMultiplier),
                    0);
            v13.m_quad = _mm_mul_ps(v14, acc->m_angularVel.m_quad);
            acc->m_linearVel.m_quad = _mm_mul_ps(v14, acc->m_linearVel.m_quad);
          }
          acc->m_angularVel = (hkVector4f)v13.m_quad;
        }
      }
      v15.m_quad = (__m128)acc->m_linearVel;
      v16.m_quad = (__m128)acc->m_angularVel;
      ++acc;
      v17 = _mm_sub_ps(v15.m_quad, acc[-1].m_scratch0.m_quad);
      v18 = _mm_sub_ps(v16.m_quad, acc[-1].m_scratch1.m_quad);
      acc[-1].m_scratch0.m_quad = _mm_add_ps(
                                    _mm_mul_ps(v17, info->m_integrateVelocityFactor.m_quad),
                                    acc[-1].m_scratch0.m_quad);
      v19 = _mm_add_ps(v17, acc[-1].m_scratch0.m_quad);
      v20.m_quad = _mm_add_ps(_mm_mul_ps(v18, info->m_integrateVelocityFactor.m_quad), acc[-1].m_scratch1.m_quad);
      acc[-1].m_scratch1 = (hkVector4f)v20.m_quad;
      v21 = _mm_mul_ps(
              _mm_shuffle_ps((__m128)LODWORD(acc[-1].m_gravityFactor), (__m128)LODWORD(acc[-1].m_gravityFactor), 0),
              aabbOut.m_quad);
      acc[-1].m_angularVel.m_quad = _mm_add_ps(v18, v20.m_quad);
      acc[-1].m_linearVel.m_quad = _mm_add_ps(v21, v19);
    }
    else
    {
      while ( 1 )
      {
        v22 = _mm_load_si128((const __m128i *)&acc->m_linearVel);
        v23 = _mm_load_si128((const __m128i *)&acc->m_angularVel);
        v24 = acc->m_deactivationClass;
        v25 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v23, 1u), 1u);
        v26 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v22, 1u), 1u);
        v27 = _mm_add_ps(
                _mm_mul_ps(
                  _mm_shuffle_ps(
                    (__m128)LODWORD(info->m_deactivationInfo[v24].m_linearVelocityThresholdInv),
                    (__m128)LODWORD(info->m_deactivationInfo[v24].m_linearVelocityThresholdInv),
                    0),
                  v26),
                _mm_mul_ps(
                  _mm_shuffle_ps(
                    (__m128)LODWORD(info->m_deactivationInfo[v24].m_angularVelocityThresholdInv),
                    (__m128)LODWORD(info->m_deactivationInfo[v24].m_angularVelocityThresholdInv),
                    0),
                  v25));
        if ( (_mm_movemask_ps(
                _mm_and_ps(
                  _mm_and_ps(
                    _mm_and_ps(_mm_cmpltps(v25, *(__m128 *)maxVelf), _mm_cmpltps(v26, *(__m128 *)maxVelf)),
                    _mm_cmpeqps((__m128)v22, (__m128)v22)),
                  _mm_cmpeqps((__m128)v23, (__m128)v23))) & 7) != 7 )
        {
          acc->m_linearVel = (hkVector4f)transform.m_quad;
          acc->m_angularVel = (hkVector4f)transform.m_quad;
        }
        if ( (_mm_movemask_ps(_mm_cmpleps(v27, query.m_quad)) & 7) == 7 )
        {
          if ( (_mm_movemask_ps(
                  _mm_cmpleps(
                    v27,
                    _mm_shuffle_ps(
                      (__m128)LODWORD(info->m_deactivationInfo[v24].m_relativeSleepVelocityThreshold),
                      (__m128)LODWORD(info->m_deactivationInfo[v24].m_relativeSleepVelocityThreshold),
                      0))) & 7) == 7 )
          {
            v28.m_quad = 0i64;
            acc->m_linearVel = 0i64;
          }
          else
          {
            v29 = _mm_shuffle_ps(
                    (__m128)LODWORD(info->m_deactivationInfo[v24].m_slowObjectVelocityMultiplier),
                    (__m128)LODWORD(info->m_deactivationInfo[v24].m_slowObjectVelocityMultiplier),
                    0);
            v28.m_quad = _mm_mul_ps(v29, acc->m_angularVel.m_quad);
            acc->m_linearVel.m_quad = _mm_mul_ps(v29, acc->m_linearVel.m_quad);
          }
          acc->m_angularVel = (hkVector4f)v28.m_quad;
        }
        v30.m_quad = (__m128)acc->m_linearVel;
        v31.m_quad = (__m128)acc->m_angularVel;
        ++acc;
        v32 = _mm_sub_ps(v30.m_quad, acc[-1].m_scratch0.m_quad);
        v33 = _mm_sub_ps(v31.m_quad, acc[-1].m_scratch1.m_quad);
        acc[-1].m_scratch0.m_quad = _mm_add_ps(
                                      _mm_mul_ps(v32, info->m_integrateVelocityFactor.m_quad),
                                      acc[-1].m_scratch0.m_quad);
        v34 = _mm_add_ps(v32, acc[-1].m_scratch0.m_quad);
        v35.m_quad = _mm_add_ps(_mm_mul_ps(v33, info->m_integrateVelocityFactor.m_quad), acc[-1].m_scratch1.m_quad);
        acc[-1].m_scratch1 = (hkVector4f)v35.m_quad;
        v36 = _mm_mul_ps(
                _mm_shuffle_ps((__m128)LODWORD(acc[-1].m_gravityFactor), (__m128)LODWORD(acc[-1].m_gravityFactor), 0),
                v6->m_quad);
        acc[-1].m_angularVel.m_quad = _mm_add_ps(v33, v35.m_quad);
        acc[-1].m_linearVel.m_quad = _mm_add_ps(v36, v34);
        if ( acc->m_type.m_storage )
          break;
        if ( acc >= v5 )
          return;
      }
    }
  }
}

// File Line: 1705
// RVA: 0xDDCF90
void __fastcall hkSolveStepJacobians(hkpSolverInfo *info, hkpJacobianSchema *schemas, hkpVelocityAccumulator *accumulators, hkpSolverElemTemp *tmp)
{
  int v4; // eax
  hkpSolverElemTemp *temps; // rsi
  hkpVelocityAccumulator *v6; // r12
  hkpJacobianSchema *v7; // rbx
  hkpSolverInfo *v8; // r15
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
  __m128 v37; // xmm2
  __m128 v38; // xmm8
  float v39; // xmm2_4
  __m128 v40; // xmm4
  __m128 v41; // xmm3
  __m128 v42; // xmm2
  __m128 v43; // xmm3
  float v44; // xmm0_4
  __m128 v45; // xmm4
  __m128 v46; // xmm3
  __m128 v47; // xmm2
  __m128 v48; // xmm3
  float v49; // xmm5_4
  __m128 v50; // xmm5
  __m128 v51; // xmm8
  __m128 v52; // xmm4
  __m128 v53; // xmm3
  __m128 v54; // xmm2
  __m128 v55; // xmm3
  __m128 v56; // xmm4
  __m128 v57; // xmm3
  __m128 v58; // xmm2
  __m128 v59; // xmm3
  float v60; // xmm1_4
  __m128 v61; // xmm5
  __m128 v62; // xmm4
  __m128 v63; // xmm2
  __m128 v64; // xmm9
  __m128 v65; // xmm5
  __m128 v66; // xmm2
  __m128 v67; // xmm1
  __m128 v68; // xmm8
  __m128 v69; // xmm5
  __m128 v70; // xmm7
  __m128 v71; // xmm6
  float v72; // xmm7_4
  __m128 v73; // xmm3
  __m128 v74; // xmm4
  __m128 v75; // xmm2
  __m128 v76; // xmm4
  __m128 v77; // xmm4
  __m128 v78; // xmm3
  __m128 v79; // xmm2
  __m128 v80; // xmm3
  float v81; // xmm0_4
  __m128 v82; // xmm5
  __m128 v83; // xmm6
  __m128 v84; // xmm4
  __m128 v85; // xmm3
  __m128 v86; // xmm2
  __m128 v87; // xmm3
  float v88; // xmm0_4
  __m128 v89; // xmm4
  __m128 v90; // xmm3
  __m128 v91; // xmm2
  __m128 v92; // xmm3
  float v93; // xmm0_4
  __m128 v94; // xmm5
  __m128 v95; // xmm6
  __m128 v96; // xmm3
  __m128 v97; // xmm2
  __m128 v98; // xmm9
  __m128 v99; // xmm2
  __m128 v100; // xmm7
  __m128 v101; // xmm2
  __m128 v102; // xmm10
  __m128 v103; // xmm1
  __m128 v104; // xmm4
  __m128 v105; // xmm5
  __m128 v106; // xmm3
  __m128 v107; // xmm8
  __m128 v108; // xmm1
  __m128 v109; // xmm3
  __m128 v110; // xmm6
  __m128 v111; // xmm5
  __m128 v112; // xmm4
  __m128 v113; // xmm7
  __m128 v114; // xmm3
  __m128 v115; // xmm2
  __m128 v116; // xmm3
  __m128 v117; // xmm3
  __m128 v118; // xmm4
  __m128 v119; // xmm2
  __m128 v120; // xmm3
  __m128 v121; // xmm4
  __m128 v122; // xmm1
  float v123; // xmm0_4
  __m128 v124; // xmm1
  __int64 v125; // r9
  __int64 v126; // r8
  float v127; // xmm9_4
  __m128 v128; // xmm5
  float v129; // xmm8_4
  float v130; // xmm10_4
  __m128 v131; // xmm4
  __m128 v132; // xmm2
  float v133; // xmm7_4
  __m128 v134; // xmm5
  float v135; // xmm1_4
  float v136; // xmm5_4
  float v137; // xmm6_4
  float v138; // xmm4_4
  float v139; // xmm7_4
  float v140; // xmm4_4
  float v141; // xmm2_4
  float v142; // xmm5_4
  float v143; // xmm3_4
  float v144; // xmm5_4
  float v145; // xmm3_4
  float v146; // xmm3_4
  hkVector4f v147; // xmm7
  float v148; // xmm0_4
  __m128 v149; // xmm5
  __m128 v150; // xmm6
  __m128 v151; // xmm4
  __m128 v152; // xmm3
  __m128 v153; // xmm2
  __m128 v154; // xmm3
  float v155; // xmm1_4
  __m128 v156; // xmm4
  __m128 v157; // xmm3
  __m128 v158; // xmm2
  __m128 v159; // xmm4
  float v160; // xmm1_4
  __int64 v161; // rcx
  int v162; // edx
  __int64 v163; // rcx
  float v164; // xmm2_4
  int v165; // eax
  float v166; // xmm1_4
  __int64 v167; // rax
  int v168; // eax
  __m128 v169; // xmm4
  __m128 v170; // xmm6
  __m128 v171; // xmm2
  __m128 v172; // xmm7
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
  float v192; // xmm0_4
  __m128 v193; // xmm6
  __m128 v194; // xmm3
  __m128 v195; // xmm4
  __m128 v196; // xmm4
  __m128 v197; // xmm2
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
  __m128 v225; // xmm4
  __m128 v226; // xmm5
  __m128 v227; // xmm2
  float v228; // xmm1_4
  __m128 v229; // xmm2
  __m128 v230; // xmm5
  __m128 v231; // xmm4
  __m128 v232; // xmm2
  __m128 v233; // xmm1
  float v234; // xmm0_4
  __m128 v235; // xmm3
  __m128 v236; // xmm5
  __m128 v237; // xmm7
  __m128 v238; // xmm3
  __m128 v239; // xmm7
  __m128 v240; // xmm3
  __m128 v241; // xmm4
  __m128 v242; // xmm4
  float v243; // xmm2_4
  __int64 v244; // rax
  __int64 v245; // rax
  __m128 v246; // xmm6
  __m128 v247; // xmm4
  __m128 v248; // xmm3
  __m128i v249; // xmm6
  __m128 v250; // xmm0
  __m128 v251; // xmm1
  __m128 v252; // xmm5
  __m128 v253; // xmm6
  __m128 v254; // xmm4
  __m128 v255; // xmm3
  __m128 v256; // xmm2
  __m128 v257; // xmm3
  __int64 v258; // rax
  __int64 v259; // rax
  __m128 v260; // xmm3
  __m128 *v261; // rcx
  __m128 v262; // xmm2
  __m128 v263; // xmm1
  __m128 v264; // xmm10
  __m128 v265; // xmm1
  __m128 v266; // xmm9
  __m128 v267; // xmm1
  __m128 v268; // xmm3
  __m128 v269; // xmm1
  __m128 v270; // xmm2
  __int64 v271; // rcx
  hkSolverStepTemp temp; // [rsp+40h] [rbp-98h]
  __int64 v273; // [rsp+60h] [rbp-78h]
  __int64 v274; // [rsp+68h] [rbp-70h]
  hkpVelocityAccumulator mA; // [rsp+70h] [rbp-68h]
  __int64 v276; // [rsp+F0h] [rbp+18h]
  __int64 v277; // [rsp+F8h] [rbp+20h]
  __int64 v278; // [rsp+100h] [rbp+28h]
  __int64 v279; // [rsp+108h] [rbp+30h]
  __int64 v280; // [rsp+110h] [rbp+38h]
  __int64 v281; // [rsp+118h] [rbp+40h]
  __int64 v282; // [rsp+120h] [rbp+48h]
  __int64 v283; // [rsp+128h] [rbp+50h]
  __int64 v284; // [rsp+130h] [rbp+58h]
  __int64 v285; // [rsp+138h] [rbp+60h]
  __int64 v286; // [rsp+140h] [rbp+68h]
  __m128 v287; // [rsp+148h] [rbp+70h]
  __m128 v288; // [rsp+158h] [rbp+80h]
  __m128 v289; // [rsp+168h] [rbp+90h]
  __m128 v290; // [rsp+178h] [rbp+A0h]
  __int128 v291; // [rsp+188h] [rbp+B0h]
  __m128 v292; // [rsp+198h] [rbp+C0h]
  __m128 v293; // [rsp+1A8h] [rbp+D0h]
  __m128 v294; // [rsp+1B8h] [rbp+E0h]
  __m128 v295; // [rsp+1C8h] [rbp+F0h]
  __m128 v296; // [rsp+1D8h] [rbp+100h]
  __m128 v297; // [rsp+1E8h] [rbp+110h]
  __m128 v298; // [rsp+1F8h] [rbp+120h]
  float v299; // [rsp+2C0h] [rbp+1E8h]
  float vars0; // [rsp+2D0h] [rbp+1F8h]

  v4 = (int)*schemas;
  temps = tmp;
  v6 = accumulators;
  v7 = schemas;
  v8 = info;
  temp.m_intregratePositionFactor = 0i64;
  temp.m_currentStep.m_storage = 0;
  if ( v4 )
  {
    if ( v4 != 2 )
      goto LABEL_4;
    v9 = (hkpVelocityAccumulator *)((char *)&mA + 88);
    mB = &mA;
    mA.m_scratch1.m_quad.m128_u64[1] = __PAIR__(
                                         _mm_cvtsi128_si32(_mm_srli_si128((__m128i)0i64, 4)),
                                         _mm_cvtsi128_si32((__m128i)0i64));
    mA.m_scratch2.m_quad.m128_u64[1] = mA.m_scratch1.m_quad.m128_u64[1];
    mA.m_scratch3.m_quad.m128_u64[1] = mA.m_scratch1.m_quad.m128_u64[1];
    v291 = 0i64;
    mA.m_scratch2.m_quad.m128_u64[0] = __PAIR__(
                                         _mm_cvtsi128_si32(_mm_srli_si128((__m128i)0i64, 12)),
                                         _mm_cvtsi128_si32(_mm_srli_si128((__m128i)0i64, 8)));
    mA.m_scratch3.m_quad.m128_u64[0] = mA.m_scratch2.m_quad.m128_u64[0];
    v276 = mA.m_scratch2.m_quad.m128_i64[0];
    v277 = mA.m_scratch1.m_quad.m128_i64[1];
    v278 = mA.m_scratch2.m_quad.m128_i64[0];
    v279 = mA.m_scratch1.m_quad.m128_i64[1];
    v280 = mA.m_scratch2.m_quad.m128_i64[0];
    v281 = mA.m_scratch1.m_quad.m128_i64[1];
    v282 = mA.m_scratch2.m_quad.m128_i64[0];
    v283 = mA.m_scratch1.m_quad.m128_i64[1];
    v284 = mA.m_scratch2.m_quad.m128_i64[0];
    v285 = mA.m_scratch1.m_quad.m128_i64[1];
    v286 = mA.m_scratch2.m_quad.m128_i64[0];
    *((_DWORD *)&mA.m_gravityFactor + 1) = LODWORD(mA.m_scratch2.m_quad.m128_f32[1]);
    temp.m_intregratePositionFactor.m_real.m128_u64[1] = mA.m_scratch1.m_quad.m128_u64[1];
    v273 = mA.m_scratch2.m_quad.m128_i64[0];
    v274 = mA.m_scratch1.m_quad.m128_i64[1];
    *(_QWORD *)&mA.m_type.m_storage = mA.m_scratch2.m_quad.m128_u64[0];
    mA.m_gravityFactor = mA.m_scratch1.m_quad.m128_f32[2];
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
            v236 = *(__m128 *)v7;
            v237 = *(__m128 *)&v7[16];
            v7 += 48;
            v238 = _mm_add_ps(
                     _mm_mul_ps(v236, _mm_sub_ps(v9->m_linearVel.m_quad, mB->m_linearVel.m_quad)),
                     _mm_add_ps(
                       _mm_mul_ps(mB->m_angularVel.m_quad, *(__m128 *)&v7[-16]),
                       _mm_mul_ps(v237, v9->m_angularVel.m_quad)));
            v239 = _mm_mul_ps(
                     _mm_shuffle_ps(v237, v237, 255),
                     _mm_sub_ps(
                       _mm_shuffle_ps(v236, v236, 255),
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v238, v238, 85), _mm_shuffle_ps(v238, v238, 0)),
                         _mm_shuffle_ps(v238, v238, 170))));
            v240 = _mm_mul_ps(v9->m_invMasses.m_quad, v239);
            v241 = _mm_mul_ps(mB->m_invMasses.m_quad, v239);
            v9->m_linearVel.m_quad = _mm_add_ps(
                                       _mm_mul_ps(_mm_shuffle_ps(v240, v240, 255), v236),
                                       v9->m_linearVel.m_quad);
            mB->m_linearVel.m_quad = _mm_sub_ps(
                                       mB->m_linearVel.m_quad,
                                       _mm_mul_ps(_mm_shuffle_ps(v241, v241, 255), v236));
            v242 = _mm_mul_ps(v241, *(__m128 *)&v7[-16]);
            v243 = COERCE_FLOAT(
                     _mm_shuffle_ps(
                       (__m128)LODWORD(temps->m_impulseApplied),
                       (__m128)LODWORD(temps->m_impulseApplied),
                       0))
                 + v239.m128_f32[0];
            v9->m_angularVel.m_quad = _mm_add_ps(v9->m_angularVel.m_quad, _mm_mul_ps(v240, *(__m128 *)&v7[-32]));
            mB->m_angularVel.m_quad = _mm_add_ps(mB->m_angularVel.m_quad, v242);
            temps->m_impulseApplied = v243;
            temps += (unsigned __int8)hkpJacobianSchema::s_schemaNumSolverElemTemps[*(_BYTE *)&v7[-48]];
          }
          while ( *v7 == 5 );
          continue;
        case 6u:
          do
          {
            hkpAtomSolverFunctions::solve1dBilateralWithImpulseLimit<hkpVelocityAccumulator,hkpSolverInfo,hkSolverStepTemp>(
              v8,
              &temp,
              (hkpJacobian1dBilateralSchema *)v7,
              v9,
              mB,
              temps);
            v244 = (__int64)*v7;
            v7 += 48;
            temps += *(unsigned __int8 *)(v244 + 5403477904i64);
          }
          while ( *v7 == 6 );
          continue;
        case 7u:
          do
          {
            hkpAtomSolverFunctions::solve1dBilateralUserTau<hkpVelocityAccumulator,hkpSolverInfo,hkSolverStepTemp>(
              v8,
              &temp,
              (hkpJacobian1dBilateralUserTauSchema *)v7,
              v9,
              mB,
              temps);
            v245 = (__int64)*v7;
            v7 += 64;
            temps += *(unsigned __int8 *)(v245 + 5403477904i64);
          }
          while ( *v7 == 7 );
          continue;
        case 8u:
          do
          {
            hkpAtomSolverFunctions::solve1dLinLimits<hkpVelocityAccumulator,hkpSolverInfo,hkSolverStepTemp>(
              v8,
              &temp,
              (hkpJacobian1dLinearLimitsSchema *)v7,
              v9,
              mB,
              temps);
            v258 = (__int64)*v7;
            v7 += 64;
            temps += *(unsigned __int8 *)(v258 + 5403477904i64);
          }
          while ( *v7 == 8 );
          continue;
        case 9u:
          do
          {
            v246 = *(__m128 *)&v7[16];
            v247 = *(__m128 *)v7;
            v7 += 64;
            v248 = _mm_add_ps(
                     _mm_mul_ps(v247, _mm_sub_ps(v9->m_linearVel.m_quad, mB->m_linearVel.m_quad)),
                     _mm_add_ps(
                       _mm_mul_ps(mB->m_angularVel.m_quad, *(__m128 *)&v7[-32]),
                       _mm_mul_ps(v246, v9->m_angularVel.m_quad)));
            v249 = (__m128i)_mm_mul_ps(
                              _mm_shuffle_ps(v246, v246, 255),
                              _mm_sub_ps(
                                _mm_shuffle_ps(v247, v247, 255),
                                _mm_add_ps(
                                  _mm_add_ps(_mm_shuffle_ps(v248, v248, 85), _mm_shuffle_ps(v248, v248, 0)),
                                  _mm_shuffle_ps(v248, v248, 170))));
            v290 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v249, 1u), 1u);
            v250 = _mm_rcp_ps(v290);
            v251 = _mm_shuffle_ps((__m128)*(unsigned int *)&v7[-16], (__m128)*(unsigned int *)&v7[-16], 0);
            v252 = _mm_cmpltps(v251, v290);
            v253 = _mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v249, 0x1Fu), 0x1Fu), _mm_min_ps(v290, v251));
            v292 = _mm_or_ps(
                     _mm_andnot_ps(v252, query.m_quad),
                     _mm_and_ps(
                       _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v290, v250)), v250), v251),
                       v252));
            temps[1].m_impulseApplied = v292.m128_f32[0];
            v254 = _mm_mul_ps(v9->m_invMasses.m_quad, v253);
            v255 = _mm_mul_ps(mB->m_invMasses.m_quad, v253);
            v256 = _mm_mul_ps(_mm_shuffle_ps(v255, v255, 255), *(__m128 *)&v7[-64]);
            v9->m_linearVel.m_quad = _mm_add_ps(
                                       v9->m_linearVel.m_quad,
                                       _mm_mul_ps(_mm_shuffle_ps(v254, v254, 255), *(__m128 *)&v7[-64]));
            mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, v256);
            v257 = _mm_mul_ps(v255, *(__m128 *)&v7[-32]);
            v250.m128_i32[0] = (unsigned __int128)_mm_shuffle_ps(
                                                    (__m128)LODWORD(temps->m_impulseApplied),
                                                    (__m128)LODWORD(temps->m_impulseApplied),
                                                    0);
            v9->m_angularVel.m_quad = _mm_add_ps(_mm_mul_ps(v254, *(__m128 *)&v7[-48]), v9->m_angularVel.m_quad);
            mB->m_angularVel.m_quad = _mm_add_ps(v257, mB->m_angularVel.m_quad);
            temps->m_impulseApplied = v250.m128_f32[0] + v253.m128_f32[0];
            temps += (unsigned __int8)hkpJacobianSchema::s_schemaNumSolverElemTemps[*(_BYTE *)&v7[-64]];
          }
          while ( *v7 == 9 );
          continue;
        case 0xAu:
          do
          {
            hkpAtomSolverFunctions::solve1dLinearMotor<hkpVelocityAccumulator,hkpSolverInfo,hkSolverStepTemp>(
              0i64,
              v8,
              &temp,
              (hkpJacobian1dLinearMotorSchema *)v7,
              v9,
              mB,
              temps,
              0i64);
            v259 = (__int64)*v7;
            v7 += 80;
            temps += *(unsigned __int8 *)(v259 + 5403477904i64);
          }
          while ( *v7 == 10 );
          continue;
        case 0xBu:
          hkpAtomSolverFunctions::solvePulley<hkpVelocityAccumulator,hkpSolverInfo,hkSolverStepTemp>(
            v8,
            &temp,
            (hkpJacobian1dPulleySchema *)v7,
            v9,
            mB,
            temps);
          ++temps;
          v7 += 64;
          continue;
        case 0xCu:
          do
          {
            v230 = *(__m128 *)v7;
            v231 = *(__m128 *)&v7[16];
            v7 += 32;
            v232 = _mm_add_ps(_mm_mul_ps(v230, v9->m_angularVel.m_quad), _mm_mul_ps(v231, mB->m_angularVel.m_quad));
            v233 = _mm_mul_ps(
                     _mm_shuffle_ps(v230, v230, 255),
                     _mm_sub_ps(
                       _mm_shuffle_ps(v231, v231, 255),
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v232, v232, 85), _mm_shuffle_ps(v232, v232, 0)),
                         _mm_shuffle_ps(v232, v232, 170))));
            v234 = COERCE_FLOAT(
                     _mm_shuffle_ps(
                       (__m128)LODWORD(temps->m_impulseApplied),
                       (__m128)LODWORD(temps->m_impulseApplied),
                       0))
                 + v233.m128_f32[0];
            v235 = _mm_mul_ps(_mm_mul_ps(v233, mB->m_invMasses.m_quad), v231);
            v9->m_angularVel.m_quad = _mm_add_ps(
                                        _mm_mul_ps(_mm_mul_ps(v233, v9->m_invMasses.m_quad), v230),
                                        v9->m_angularVel.m_quad);
            mB->m_angularVel.m_quad = _mm_add_ps(v235, mB->m_angularVel.m_quad);
            temps->m_impulseApplied = v234;
            temps += (unsigned __int8)hkpJacobianSchema::s_schemaNumSolverElemTemps[*(_BYTE *)&v7[-32]];
          }
          while ( *v7 == 12 );
          continue;
        case 0xDu:
          do
          {
            v204 = *(__m128 *)&v7[16];
            v205 = *(__m128 *)v7;
            v206 = _mm_shuffle_ps((__m128)*(unsigned int *)&v7[40], (__m128)*(unsigned int *)&v7[40], 0);
            v207 = *(__m128 *)&v7[16];
            v208 = _mm_shuffle_ps(v205, v205, 255);
            v209 = _mm_add_ps(
                     _mm_mul_ps(
                       _mm_mul_ps(
                         _mm_shuffle_ps(
                           v8->m_invIntegrateVelocityFactor.m_quad,
                           v8->m_invIntegrateVelocityFactor.m_quad,
                           0),
                         v206),
                       _mm_add_ps(
                         _mm_mul_ps(*(__m128 *)&v7[16], mB->m_scratch1.m_quad),
                         _mm_mul_ps(*(__m128 *)v7, v9->m_scratch1.m_quad))),
                     _mm_mul_ps(
                       _mm_add_ps(
                         _mm_mul_ps(v204, _mm_sub_ps(mB->m_angularVel.m_quad, mB->m_scratch1.m_quad)),
                         _mm_mul_ps(*(__m128 *)v7, _mm_sub_ps(v9->m_angularVel.m_quad, v9->m_scratch1.m_quad))),
                       _mm_shuffle_ps((__m128)LODWORD(v8->m_damping), (__m128)LODWORD(v8->m_damping), 0)));
            v210 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v209, v209, 85), _mm_shuffle_ps(v209, v209, 0)),
                     _mm_shuffle_ps(v209, v209, 170));
            LODWORD(v211) = (unsigned __int128)_mm_shuffle_ps(
                                                 (__m128)LODWORD(temps->m_impulseApplied),
                                                 (__m128)LODWORD(temps->m_impulseApplied),
                                                 0);
            v212 = _mm_sub_ps(_mm_mul_ps(v206, _mm_shuffle_ps(v204, v204, 255)), v210);
            v213 = _mm_mul_ps(
                     _mm_sub_ps(
                       v212,
                       _mm_shuffle_ps((__m128)*(unsigned int *)&v7[32], (__m128)*(unsigned int *)&v7[32], 0)),
                     v208);
            if ( v213.m128_f32[0] <= (float)(0.0 - v211) )
            {
              v215 = _mm_mul_ps(
                       _mm_sub_ps(
                         v212,
                         _mm_shuffle_ps((__m128)*(unsigned int *)&v7[36], (__m128)*(unsigned int *)&v7[36], 0)),
                       v208);
              if ( v215.m128_f32[0] < (float)(0.0 - v211) )
              {
                v216 = _mm_mul_ps(mB->m_invMasses.m_quad, v215);
                v9->m_angularVel.m_quad = _mm_add_ps(
                                            _mm_mul_ps(_mm_mul_ps(v9->m_invMasses.m_quad, v215), v205),
                                            v9->m_angularVel.m_quad);
                mB->m_angularVel.m_quad = _mm_add_ps(_mm_mul_ps(v216, v207), mB->m_angularVel.m_quad);
                temps->m_impulseApplied = v215.m128_f32[0] + v211;
              }
            }
            else
            {
              v214 = _mm_mul_ps(_mm_mul_ps(mB->m_invMasses.m_quad, v213), v207);
              v9->m_angularVel.m_quad = _mm_add_ps(
                                          _mm_mul_ps(_mm_mul_ps(v9->m_invMasses.m_quad, v213), v205),
                                          v9->m_angularVel.m_quad);
              mB->m_angularVel.m_quad = _mm_add_ps(v214, mB->m_angularVel.m_quad);
              temps->m_impulseApplied = v211 + v213.m128_f32[0];
            }
            v217 = (__int64)*v7;
            v7 += 48;
            temps += *(unsigned __int8 *)(v217 + 5403477904i64);
          }
          while ( *v7 == 13 );
          continue;
        case 0xEu:
          do
          {
            v193 = *(__m128 *)v7;
            v194 = *(__m128 *)&v7[16];
            v195 = (__m128)*(unsigned int *)&v7[32];
            v7 += 48;
            v196 = _mm_shuffle_ps(v195, v195, 0);
            v197 = _mm_add_ps(_mm_mul_ps(v193, v9->m_angularVel.m_quad), _mm_mul_ps(v194, mB->m_angularVel.m_quad));
            v198 = (__m128i)_mm_mul_ps(
                              _mm_shuffle_ps(v193, v193, 255),
                              _mm_sub_ps(
                                _mm_shuffle_ps(v194, v194, 255),
                                _mm_add_ps(
                                  _mm_add_ps(_mm_shuffle_ps(v197, v197, 85), _mm_shuffle_ps(v197, v197, 0)),
                                  _mm_shuffle_ps(v197, v197, 170))));
            v199 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v198, 1u), 1u);
            v200 = _mm_cmpltps(v196, v199);
            v288 = v199;
            v201 = _mm_rcp_ps(v199);
            v202 = _mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v198, 0x1Fu), 0x1Fu), _mm_min_ps(v199, v196));
            v295 = _mm_or_ps(
                     _mm_andnot_ps(v200, query.m_quad),
                     _mm_and_ps(
                       _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v199, v201)), v201), v196),
                       v200));
            temps[1].m_impulseApplied = v295.m128_f32[0];
            v199.m128_f32[0] = COERCE_FLOAT(
                                 _mm_shuffle_ps(
                                   (__m128)LODWORD(temps->m_impulseApplied),
                                   (__m128)LODWORD(temps->m_impulseApplied),
                                   0))
                             + v202.m128_f32[0];
            v203 = _mm_mul_ps(_mm_mul_ps(mB->m_invMasses.m_quad, v202), *(__m128 *)&v7[-32]);
            v9->m_angularVel.m_quad = _mm_add_ps(
                                        _mm_mul_ps(_mm_mul_ps(v9->m_invMasses.m_quad, v202), *(__m128 *)&v7[-48]),
                                        v9->m_angularVel.m_quad);
            mB->m_angularVel.m_quad = _mm_add_ps(v203, mB->m_angularVel.m_quad);
            temps->m_impulseApplied = v199.m128_f32[0];
            temps += (unsigned __int8)hkpJacobianSchema::s_schemaNumSolverElemTemps[*(_BYTE *)&v7[-48]];
          }
          while ( *v7 == 14 );
          continue;
        case 0xFu:
          do
          {
            v218 = *(__m128 *)&v7[16];
            v219 = _mm_shuffle_ps((__m128)*(unsigned int *)&v7[44], (__m128)*(unsigned int *)&v7[44], 0);
            v220 = _mm_add_ps(
                     _mm_mul_ps(
                       _mm_mul_ps(
                         _mm_shuffle_ps(
                           v8->m_invIntegrateVelocityFactor.m_quad,
                           v8->m_invIntegrateVelocityFactor.m_quad,
                           0),
                         v219),
                       _mm_add_ps(
                         _mm_mul_ps(*(__m128 *)&v7[16], mB->m_scratch1.m_quad),
                         _mm_mul_ps(*(__m128 *)v7, v9->m_scratch1.m_quad))),
                     _mm_mul_ps(
                       _mm_add_ps(
                         _mm_mul_ps(v218, _mm_sub_ps(mB->m_angularVel.m_quad, mB->m_scratch1.m_quad)),
                         _mm_mul_ps(*(__m128 *)v7, _mm_sub_ps(v9->m_angularVel.m_quad, v9->m_scratch1.m_quad))),
                       _mm_shuffle_ps((__m128)*(unsigned int *)&v7[48], (__m128)*(unsigned int *)&v7[48], 0)));
            v221 = _mm_mul_ps(
                     _mm_shuffle_ps(*(__m128 *)v7, *(__m128 *)v7, 255),
                     _mm_sub_ps(
                       _mm_mul_ps(
                         _mm_add_ps(
                           _mm_shuffle_ps(v218, v218, 255),
                           _mm_mul_ps(
                             _mm_shuffle_ps((__m128)*(unsigned int *)&v7[40], (__m128)*(unsigned int *)&v7[40], 0),
                             temp.m_intregratePositionFactor.m_real)),
                         v219),
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v220, v220, 85), _mm_shuffle_ps(v220, v220, 0)),
                         _mm_shuffle_ps(v220, v220, 170))));
            v222 = _mm_rcp_ps(v221);
            v287 = v221;
            v223 = _mm_shuffle_ps((__m128)*(unsigned int *)&v7[32], (__m128)*(unsigned int *)&v7[32], 0);
            v224 = _mm_shuffle_ps((__m128)*(unsigned int *)&v7[36], (__m128)*(unsigned int *)&v7[36], 0);
            v225 = _mm_cmpltps(v221, v224);
            v226 = _mm_cmpltps(v223, v221);
            v293 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v222, v221)), v222), v223);
            v289 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v222, v221)), v222), v224);
            LODWORD(temps[1].m_impulseApplied) = *(unsigned __int128 *)&_mm_andnot_ps(
                                                                          v226,
                                                                          _mm_or_ps(
                                                                            _mm_and_ps(v225, v289),
                                                                            _mm_andnot_ps(v225, query.m_quad))) | v226.m128_i32[0] & v293.m128_i32[0];
            v227 = _mm_cmpltps(v287, v223);
            v7 += 64;
            v287 = _mm_max_ps(v224, _mm_or_ps(_mm_andnot_ps(v227, v223), _mm_and_ps(v227, v287)));
            v228 = COERCE_FLOAT(
                     _mm_shuffle_ps(
                       (__m128)LODWORD(temps->m_impulseApplied),
                       (__m128)LODWORD(temps->m_impulseApplied),
                       0))
                 + v287.m128_f32[0];
            v229 = _mm_mul_ps(_mm_mul_ps(mB->m_invMasses.m_quad, v287), *(__m128 *)&v7[-48]);
            v9->m_angularVel.m_quad = _mm_add_ps(
                                        _mm_mul_ps(_mm_mul_ps(v9->m_invMasses.m_quad, v287), *(__m128 *)&v7[-64]),
                                        v9->m_angularVel.m_quad);
            mB->m_angularVel.m_quad = _mm_add_ps(v229, mB->m_angularVel.m_quad);
            temps->m_impulseApplied = v228;
            temps += (unsigned __int8)hkpJacobianSchema::s_schemaNumSolverElemTemps[*(_BYTE *)&v7[-64]];
          }
          while ( *v7 == 15 );
          continue;
        case 0x10u:
          hkpAtomSolverFunctions::solveStableBallSocket<hkpVelocityAccumulator,hkpSolverInfo,hkSolverStepTemp>(
            v8,
            &temp,
            (hkpStableBallSocketSchema *)v7,
            v9,
            mB,
            temps);
          v7 += 64;
          temps += 3;
          continue;
        case 0x12u:
          hkpAtomSolverFunctions::solveStableStiffSpring<hkpVelocityAccumulator,hkpSolverInfo,hkSolverStepTemp,hkpStableStiffSpringSchema>(
            v8,
            &temp,
            (hkpStableStiffSpringSchema *)v7,
            v9,
            mB,
            temps);
          v7 += 48;
          ++temps;
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
                      _mm_shuffle_ps(
                        (__m128)LODWORD(temps->m_impulseApplied),
                        (__m128)LODWORD(temps->m_impulseApplied),
                        0)),
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
            v18 = COERCE_FLOAT(
                    _mm_shuffle_ps(
                      (__m128)LODWORD(temps->m_impulseApplied),
                      (__m128)LODWORD(temps->m_impulseApplied),
                      0))
                + v14.m128_f32[0];
            v9->m_angularVel.m_quad = _mm_add_ps(v9->m_angularVel.m_quad, _mm_mul_ps(v15, *(__m128 *)&v7[-32]));
            mB->m_angularVel.m_quad = _mm_add_ps(mB->m_angularVel.m_quad, v17);
            temps->m_impulseApplied = v18;
            temps += (unsigned __int8)hkpJacobianSchema::s_schemaNumSolverElemTemps[*(_BYTE *)&v7[-48]];
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
            v23 = _mm_shuffle_ps((__m128)LODWORD(temps->m_impulseApplied), (__m128)LODWORD(temps->m_impulseApplied), 0);
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
                            + COERCE_FLOAT(
                                _mm_shuffle_ps(
                                  (__m128)LODWORD(temps->m_impulseApplied),
                                  (__m128)LODWORD(temps->m_impulseApplied),
                                  0));
            v9->m_angularVel.m_quad = _mm_add_ps(v9->m_angularVel.m_quad, _mm_mul_ps(v25, *(__m128 *)&v7[-32]));
            mB->m_angularVel.m_quad = _mm_add_ps(mB->m_angularVel.m_quad, v27);
            temps->m_impulseApplied = v24.m128_f32[0];
            temps += (unsigned __int8)hkpJacobianSchema::s_schemaNumSolverElemTemps[*(_BYTE *)&v7[-48]];
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
          v33 = _mm_shuffle_ps((__m128)*(unsigned int *)&v7[96], (__m128)*(unsigned int *)&v7[96], 0);
          v34 = _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v7[32], *(__m128 *)&v7[32], 255), v30),
                  _mm_mul_ps(v33, v32));
          v35 = _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v7[80], *(__m128 *)&v7[80], 255), v32),
                  _mm_mul_ps(v33, v30));
          v36 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 80);
          v37 = _mm_xor_ps(v36, (__m128)*(unsigned __int64 *)&temps->m_impulseApplied);
          v294 = v37;
          v38 = _mm_shuffle_ps(v37, v37, 0);
          LODWORD(v39) = (unsigned __int128)_mm_shuffle_ps(v37, v37, 85);
          if ( v34.m128_f32[0] <= v38.m128_f32[0] )
          {
            v50 = _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v7[64], *(__m128 *)&v7[64], 255), v32);
            if ( v50.m128_f32[0] > v39 )
            {
              v56 = _mm_mul_ps(v9->m_invMasses.m_quad, v50);
              v57 = _mm_mul_ps(mB->m_invMasses.m_quad, v50);
              v58 = _mm_mul_ps(_mm_shuffle_ps(v57, v57, 255), *(__m128 *)&v7[48]);
              v9->m_linearVel.m_quad = _mm_add_ps(
                                         v9->m_linearVel.m_quad,
                                         _mm_mul_ps(_mm_shuffle_ps(v56, v56, 255), *(__m128 *)&v7[48]));
              mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, v58);
              v59 = _mm_mul_ps(v57, *(__m128 *)&v7[80]);
              v60 = COERCE_FLOAT(
                      _mm_shuffle_ps(
                        (__m128)LODWORD(temps[1].m_impulseApplied),
                        (__m128)LODWORD(temps[1].m_impulseApplied),
                        0))
                  + v50.m128_f32[0];
              v9->m_angularVel.m_quad = _mm_add_ps(_mm_mul_ps(v56, *(__m128 *)&v7[64]), v9->m_angularVel.m_quad);
              mB->m_angularVel.m_quad = _mm_add_ps(mB->m_angularVel.m_quad, v59);
              temps[1].m_impulseApplied = v60;
              goto LABEL_18;
            }
LABEL_16:
            v51 = _mm_max_ps(v38, _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v7[16], *(__m128 *)&v7[16], 255), v30));
            v52 = _mm_mul_ps(v9->m_invMasses.m_quad, v51);
            v53 = _mm_mul_ps(mB->m_invMasses.m_quad, v51);
            v54 = _mm_mul_ps(_mm_shuffle_ps(v53, v53, 255), *(__m128 *)v7);
            v9->m_linearVel.m_quad = _mm_add_ps(
                                       v9->m_linearVel.m_quad,
                                       _mm_mul_ps(_mm_shuffle_ps(v52, v52, 255), *(__m128 *)v7));
            mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, v54);
            v55 = _mm_mul_ps(v53, *(__m128 *)&v7[32]);
            v54.m128_f32[0] = COERCE_FLOAT(
                                _mm_shuffle_ps(
                                  (__m128)LODWORD(temps->m_impulseApplied),
                                  (__m128)LODWORD(temps->m_impulseApplied),
                                  0))
                            + v51.m128_f32[0];
            v9->m_angularVel.m_quad = _mm_add_ps(v9->m_angularVel.m_quad, _mm_mul_ps(v52, *(__m128 *)&v7[16]));
            mB->m_angularVel.m_quad = _mm_add_ps(mB->m_angularVel.m_quad, v55);
            temps->m_impulseApplied = v54.m128_f32[0];
            goto LABEL_18;
          }
          if ( v35.m128_f32[0] <= v39 )
            goto LABEL_16;
          v40 = _mm_mul_ps(v34, v9->m_invMasses.m_quad);
          v41 = _mm_mul_ps(v34, mB->m_invMasses.m_quad);
          v42 = _mm_mul_ps(_mm_shuffle_ps(v41, v41, 255), *(__m128 *)v7);
          v9->m_linearVel.m_quad = _mm_add_ps(
                                     v9->m_linearVel.m_quad,
                                     _mm_mul_ps(_mm_shuffle_ps(v40, v40, 255), *(__m128 *)v7));
          mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, v42);
          v43 = _mm_mul_ps(v41, *(__m128 *)&v7[32]);
          LODWORD(v44) = (unsigned __int128)_mm_shuffle_ps(
                                              (__m128)LODWORD(temps->m_impulseApplied),
                                              (__m128)LODWORD(temps->m_impulseApplied),
                                              0);
          v9->m_angularVel.m_quad = _mm_add_ps(_mm_mul_ps(v40, *(__m128 *)&v7[16]), v9->m_angularVel.m_quad);
          mB->m_angularVel.m_quad = _mm_add_ps(v43, mB->m_angularVel.m_quad);
          temps->m_impulseApplied = v34.m128_f32[0] + v44;
          v45 = _mm_mul_ps(v35, v9->m_invMasses.m_quad);
          v46 = _mm_mul_ps(v35, mB->m_invMasses.m_quad);
          v47 = _mm_mul_ps(_mm_shuffle_ps(v46, v46, 255), *(__m128 *)&v7[48]);
          v9->m_linearVel.m_quad = _mm_add_ps(
                                     v9->m_linearVel.m_quad,
                                     _mm_mul_ps(_mm_shuffle_ps(v45, v45, 255), *(__m128 *)&v7[48]));
          mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, v47);
          v48 = _mm_mul_ps(v46, *(__m128 *)&v7[80]);
          v49 = v35.m128_f32[0]
              + COERCE_FLOAT(
                  _mm_shuffle_ps(
                    (__m128)LODWORD(temps[1].m_impulseApplied),
                    (__m128)LODWORD(temps[1].m_impulseApplied),
                    0));
          v9->m_angularVel.m_quad = _mm_add_ps(_mm_mul_ps(v45, *(__m128 *)&v7[64]), v9->m_angularVel.m_quad);
          mB->m_angularVel.m_quad = _mm_add_ps(mB->m_angularVel.m_quad, v48);
          temps[1].m_impulseApplied = v49;
LABEL_18:
          v7 += 112;
          temps += 2;
          if ( *v7 == 24 )
          {
            v61 = mB->m_angularVel.m_quad;
            v62 = _mm_sub_ps(v9->m_linearVel.m_quad, mB->m_linearVel.m_quad);
            v63 = _mm_add_ps(
                    _mm_mul_ps(*(__m128 *)v7, v62),
                    _mm_add_ps(
                      _mm_mul_ps(v61, *(__m128 *)&v7[32]),
                      _mm_mul_ps(*(__m128 *)&v7[16], v9->m_angularVel.m_quad)));
            v64 = _mm_sub_ps(
                    _mm_shuffle_ps(*(__m128 *)v7, *(__m128 *)v7, 255),
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v63, v63, 85), _mm_shuffle_ps(v63, v63, 0)),
                      _mm_shuffle_ps(v63, v63, 170)));
            v65 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(v61, *(__m128 *)&v7[80]),
                      _mm_mul_ps(*(__m128 *)&v7[64], v9->m_angularVel.m_quad)),
                    _mm_mul_ps(*(__m128 *)&v7[48], v62));
            v66 = _mm_sub_ps(
                    _mm_shuffle_ps(*(__m128 *)&v7[48], *(__m128 *)&v7[48], 255),
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v65, v65, 85), _mm_shuffle_ps(v65, v65, 0)),
                      _mm_shuffle_ps(v65, v65, 170)));
            v67 = _mm_shuffle_ps((__m128)*(unsigned int *)&v7[96], (__m128)*(unsigned int *)&v7[96], 0);
            v68 = _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v7[32], *(__m128 *)&v7[32], 255), v64),
                    _mm_mul_ps(v67, v66));
            v69 = _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v7[80], *(__m128 *)&v7[80], 255), v66),
                    _mm_mul_ps(v67, v64));
            v70 = _mm_xor_ps(v36, (__m128)*(unsigned __int64 *)&temps->m_impulseApplied);
            v296 = v70;
            v71 = _mm_shuffle_ps(v70, v70, 0);
            LODWORD(v72) = (unsigned __int128)_mm_shuffle_ps(v70, v70, 85);
            if ( v68.m128_f32[0] <= v71.m128_f32[0] )
            {
              v82 = _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v7[64], *(__m128 *)&v7[64], 255), v66);
              if ( v82.m128_f32[0] > v72 )
              {
                v89 = _mm_mul_ps(v9->m_invMasses.m_quad, v82);
                v90 = _mm_mul_ps(mB->m_invMasses.m_quad, v82);
                v91 = _mm_mul_ps(_mm_shuffle_ps(v90, v90, 255), *(__m128 *)&v7[48]);
                v9->m_linearVel.m_quad = _mm_add_ps(
                                           v9->m_linearVel.m_quad,
                                           _mm_mul_ps(_mm_shuffle_ps(v89, v89, 255), *(__m128 *)&v7[48]));
                mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, v91);
                v92 = _mm_mul_ps(v90, *(__m128 *)&v7[80]);
                LODWORD(v93) = (unsigned __int128)_mm_shuffle_ps(
                                                    (__m128)LODWORD(temps[1].m_impulseApplied),
                                                    (__m128)LODWORD(temps[1].m_impulseApplied),
                                                    0);
                v9->m_angularVel.m_quad = _mm_add_ps(_mm_mul_ps(v89, *(__m128 *)&v7[64]), v9->m_angularVel.m_quad);
                mB->m_angularVel.m_quad = _mm_add_ps(v92, mB->m_angularVel.m_quad);
                temps[1].m_impulseApplied = v82.m128_f32[0] + v93;
                goto LABEL_25;
              }
LABEL_23:
              v83 = _mm_max_ps(v71, _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v7[16], *(__m128 *)&v7[16], 255), v64));
              v84 = _mm_mul_ps(v9->m_invMasses.m_quad, v83);
              v85 = _mm_mul_ps(mB->m_invMasses.m_quad, v83);
              v86 = _mm_mul_ps(_mm_shuffle_ps(v85, v85, 255), *(__m128 *)v7);
              v9->m_linearVel.m_quad = _mm_add_ps(
                                         v9->m_linearVel.m_quad,
                                         _mm_mul_ps(_mm_shuffle_ps(v84, v84, 255), *(__m128 *)v7));
              mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, v86);
              v87 = _mm_mul_ps(v85, *(__m128 *)&v7[32]);
              LODWORD(v88) = (unsigned __int128)_mm_shuffle_ps(
                                                  (__m128)LODWORD(temps->m_impulseApplied),
                                                  (__m128)LODWORD(temps->m_impulseApplied),
                                                  0);
              v9->m_angularVel.m_quad = _mm_add_ps(_mm_mul_ps(v84, *(__m128 *)&v7[16]), v9->m_angularVel.m_quad);
              mB->m_angularVel.m_quad = _mm_add_ps(v87, mB->m_angularVel.m_quad);
              temps->m_impulseApplied = v83.m128_f32[0] + v88;
              goto LABEL_25;
            }
            if ( v69.m128_f32[0] <= v72 )
              goto LABEL_23;
            v73 = _mm_mul_ps(v9->m_invMasses.m_quad, v68);
            v74 = _mm_mul_ps(mB->m_invMasses.m_quad, v68);
            v75 = _mm_mul_ps(_mm_shuffle_ps(v74, v74, 255), *(__m128 *)v7);
            v9->m_linearVel.m_quad = _mm_add_ps(
                                       v9->m_linearVel.m_quad,
                                       _mm_mul_ps(_mm_shuffle_ps(v73, v73, 255), *(__m128 *)v7));
            mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, v75);
            v76 = _mm_mul_ps(v74, *(__m128 *)&v7[32]);
            v75.m128_i32[0] = (unsigned __int128)_mm_shuffle_ps(
                                                   (__m128)LODWORD(temps->m_impulseApplied),
                                                   (__m128)LODWORD(temps->m_impulseApplied),
                                                   0);
            v9->m_angularVel.m_quad = _mm_add_ps(v9->m_angularVel.m_quad, _mm_mul_ps(v73, *(__m128 *)&v7[16]));
            mB->m_angularVel.m_quad = _mm_add_ps(mB->m_angularVel.m_quad, v76);
            temps->m_impulseApplied = v75.m128_f32[0] + v68.m128_f32[0];
            v77 = _mm_mul_ps(v9->m_invMasses.m_quad, v69);
            v78 = _mm_mul_ps(mB->m_invMasses.m_quad, v69);
            v79 = _mm_mul_ps(_mm_shuffle_ps(v78, v78, 255), *(__m128 *)&v7[48]);
            v9->m_linearVel.m_quad = _mm_add_ps(
                                       v9->m_linearVel.m_quad,
                                       _mm_mul_ps(_mm_shuffle_ps(v77, v77, 255), *(__m128 *)&v7[48]));
            mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, v79);
            v80 = _mm_mul_ps(v78, *(__m128 *)&v7[80]);
            LODWORD(v81) = (unsigned __int128)_mm_shuffle_ps(
                                                (__m128)LODWORD(temps[1].m_impulseApplied),
                                                (__m128)LODWORD(temps[1].m_impulseApplied),
                                                0);
            v9->m_angularVel.m_quad = _mm_add_ps(_mm_mul_ps(v77, *(__m128 *)&v7[64]), v9->m_angularVel.m_quad);
            mB->m_angularVel.m_quad = _mm_add_ps(v80, mB->m_angularVel.m_quad);
            temps[1].m_impulseApplied = v81 + v69.m128_f32[0];
LABEL_25:
            v7 += 112;
            temps += 2;
            if ( *v7 == 27 )
            {
LABEL_26:
              v94 = v9->m_angularVel.m_quad;
              v95 = _mm_shuffle_ps((__m128)*(unsigned int *)&v7[132], (__m128)*(unsigned int *)&v7[132], 0);
              v96 = _mm_sub_ps(v9->m_linearVel.m_quad, mB->m_linearVel.m_quad);
              v97 = _mm_add_ps(
                      _mm_mul_ps(*(__m128 *)v7, v96),
                      _mm_add_ps(
                        _mm_mul_ps(mB->m_angularVel.m_quad, *(__m128 *)&v7[32]),
                        _mm_mul_ps(*(__m128 *)&v7[16], v94)));
              v98 = _mm_sub_ps(
                      _mm_shuffle_ps(*(__m128 *)v7, *(__m128 *)v7, 255),
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v97, v97, 85), _mm_shuffle_ps(v97, v97, 0)),
                        _mm_shuffle_ps(v97, v97, 170)));
              v99 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(mB->m_angularVel.m_quad, *(__m128 *)&v7[80]),
                        _mm_mul_ps(*(__m128 *)&v7[64], v94)),
                      _mm_mul_ps(*(__m128 *)&v7[48], v96));
              v100 = _mm_sub_ps(
                       _mm_shuffle_ps(*(__m128 *)&v7[48], *(__m128 *)&v7[48], 255),
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v99, v99, 85), _mm_shuffle_ps(v99, v99, 0)),
                         _mm_shuffle_ps(v99, v99, 170)));
              v101 = _mm_add_ps(
                       _mm_mul_ps(*(__m128 *)&v7[96], v94),
                       _mm_mul_ps(*(__m128 *)&v7[112], mB->m_angularVel.m_quad));
              v102 = _mm_mul_ps(
                       _mm_shuffle_ps(*(__m128 *)&v7[96], *(__m128 *)&v7[96], 255),
                       _mm_sub_ps(
                         _mm_shuffle_ps(*(__m128 *)&v7[112], *(__m128 *)&v7[112], 255),
                         _mm_add_ps(
                           _mm_add_ps(_mm_shuffle_ps(v101, v101, 85), _mm_shuffle_ps(v101, v101, 0)),
                           _mm_shuffle_ps(v101, v101, 170))));
              v103 = _mm_shuffle_ps((__m128)*(unsigned int *)&v7[128], (__m128)*(unsigned int *)&v7[128], 0);
              v104 = _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v7[80], *(__m128 *)&v7[80], 255), v100),
                       _mm_mul_ps(v103, v98));
              v105 = _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v7[32], *(__m128 *)&v7[32], 255), v98),
                       _mm_mul_ps(v103, v100));
              v106 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v104, v104), _mm_mul_ps(v105, v105)), _mm_mul_ps(v102, v102));
              v107 = _mm_cmpltps(_mm_mul_ps(v95, v95), v106);
              v298 = v106;
              v108 = _mm_rsqrt_ps(v106);
              v109 = _mm_mul_ps(
                       _mm_mul_ps(
                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v108, v106), v108)),
                         _mm_mul_ps(*(__m128 *)_xmm, v108)),
                       v95);
              v110 = _mm_or_ps(_mm_and_ps(_mm_mul_ps(v109, v105), v107), _mm_andnot_ps(v107, v105));
              v111 = _mm_or_ps(_mm_and_ps(_mm_mul_ps(v109, v104), v107), _mm_andnot_ps(v107, v104));
              LODWORD(temps[3].m_impulseApplied) = v109.m128_i32[0] & v107.m128_i32[0] | *(unsigned __int128 *)&_mm_andnot_ps(v107, query.m_quad);
              v112 = _mm_mul_ps(v9->m_invMasses.m_quad, v110);
              v113 = _mm_mul_ps(
                       _mm_or_ps(_mm_and_ps(_mm_mul_ps(v109, v102), v107), _mm_andnot_ps(v107, v102)),
                       _mm_shuffle_ps((__m128)*(unsigned int *)&v7[136], (__m128)*(unsigned int *)&v7[136], 0));
              v114 = _mm_mul_ps(mB->m_invMasses.m_quad, v110);
              v115 = _mm_mul_ps(_mm_shuffle_ps(v114, v114, 255), *(__m128 *)v7);
              v9->m_linearVel.m_quad = _mm_add_ps(
                                         v9->m_linearVel.m_quad,
                                         _mm_mul_ps(_mm_shuffle_ps(v112, v112, 255), *(__m128 *)v7));
              mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, v115);
              v116 = _mm_mul_ps(v114, *(__m128 *)&v7[32]);
              v108.m128_i32[0] = (unsigned __int128)_mm_shuffle_ps(
                                                      (__m128)LODWORD(temps->m_impulseApplied),
                                                      (__m128)LODWORD(temps->m_impulseApplied),
                                                      0);
              v9->m_angularVel.m_quad = _mm_add_ps(_mm_mul_ps(v112, *(__m128 *)&v7[16]), v9->m_angularVel.m_quad);
              mB->m_angularVel.m_quad = _mm_add_ps(mB->m_angularVel.m_quad, v116);
              temps->m_impulseApplied = v108.m128_f32[0] + v110.m128_f32[0];
              v117 = _mm_mul_ps(v9->m_invMasses.m_quad, v111);
              v118 = _mm_mul_ps(mB->m_invMasses.m_quad, v111);
              v119 = _mm_mul_ps(_mm_shuffle_ps(v118, v118, 255), *(__m128 *)&v7[48]);
              v9->m_linearVel.m_quad = _mm_add_ps(
                                         v9->m_linearVel.m_quad,
                                         _mm_mul_ps(_mm_shuffle_ps(v117, v117, 255), *(__m128 *)&v7[48]));
              mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, v119);
              v120 = _mm_mul_ps(v117, *(__m128 *)&v7[64]);
              v121 = _mm_mul_ps(v118, *(__m128 *)&v7[80]);
              v122 = (__m128)LODWORD(temps[1].m_impulseApplied);
              v7 += 160;
              temps += 4;
              v9->m_angularVel.m_quad = _mm_add_ps(v9->m_angularVel.m_quad, v120);
              mB->m_angularVel.m_quad = _mm_add_ps(v121, mB->m_angularVel.m_quad);
              temps[-3].m_impulseApplied = COERCE_FLOAT(_mm_shuffle_ps(v122, v122, 0)) + v111.m128_f32[0];
              v123 = COERCE_FLOAT(
                       _mm_shuffle_ps(
                         (__m128)LODWORD(temps[-2].m_impulseApplied),
                         (__m128)LODWORD(temps[-2].m_impulseApplied),
                         0))
                   + v113.m128_f32[0];
              v124 = _mm_mul_ps(_mm_mul_ps(mB->m_invMasses.m_quad, v113), *(__m128 *)&v7[-48]);
              v9->m_angularVel.m_quad = _mm_add_ps(
                                          _mm_mul_ps(_mm_mul_ps(v9->m_invMasses.m_quad, v113), *(__m128 *)&v7[-64]),
                                          v9->m_angularVel.m_quad);
              mB->m_angularVel.m_quad = _mm_add_ps(v124, mB->m_angularVel.m_quad);
              temps[-2].m_impulseApplied = v123;
              if ( *v7 == 1 )
              {
LABEL_4:
                v9 = &v6[(unsigned __int64)*(unsigned __int16 *)&v7[4]];
                mB = &v6[(unsigned __int64)*(unsigned __int16 *)&v7[6]];
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
            v8,
            &temp,
            (hkpJacobian2dRollingFrictionSchema *)v7,
            v9,
            mB,
            temps);
          v167 = (__int64)*v7;
          v7 += 96;
          temps += *(unsigned __int8 *)(v167 + 5403477904i64);
          v168 = (int)*v7;
          if ( v168 == 27 )
            goto LABEL_26;
          if ( v168 != 26 )
            continue;
LABEL_50:
          v169 = _mm_sub_ps(v9->m_linearVel.m_quad, mB->m_linearVel.m_quad);
          v170 = _mm_shuffle_ps((__m128)*(unsigned int *)&v7[100], (__m128)*(unsigned int *)&v7[100], 0);
          v171 = _mm_add_ps(
                   _mm_mul_ps(*(__m128 *)v7, v169),
                   _mm_add_ps(
                     _mm_mul_ps(mB->m_angularVel.m_quad, *(__m128 *)&v7[32]),
                     _mm_mul_ps(*(__m128 *)&v7[16], v9->m_angularVel.m_quad)));
          v172 = _mm_sub_ps(
                   _mm_shuffle_ps(*(__m128 *)v7, *(__m128 *)v7, 255),
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v171, v171, 85), _mm_shuffle_ps(v171, v171, 0)),
                     _mm_shuffle_ps(v171, v171, 170)));
          v173 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(mB->m_angularVel.m_quad, *(__m128 *)&v7[80]),
                     _mm_mul_ps(*(__m128 *)&v7[64], v9->m_angularVel.m_quad)),
                   _mm_mul_ps(*(__m128 *)&v7[48], v169));
          v174 = _mm_sub_ps(
                   _mm_shuffle_ps(*(__m128 *)&v7[48], *(__m128 *)&v7[48], 255),
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v173, v173, 85), _mm_shuffle_ps(v173, v173, 0)),
                     _mm_shuffle_ps(v173, v173, 170)));
          v175 = _mm_shuffle_ps((__m128)*(unsigned int *)&v7[96], (__m128)*(unsigned int *)&v7[96], 0);
          v176 = _mm_add_ps(
                   _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v7[32], *(__m128 *)&v7[32], 255), v172),
                   _mm_mul_ps(v175, v174));
          v177 = _mm_add_ps(
                   _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v7[80], *(__m128 *)&v7[80], 255), v174),
                   _mm_mul_ps(v175, v172));
          v178 = _mm_add_ps(_mm_mul_ps(v177, v177), _mm_mul_ps(v176, v176));
          v179 = _mm_rsqrt_ps(v178);
          v180 = _mm_cmpltps(_mm_mul_ps(v170, v170), v178);
          v297 = v178;
          v181 = _mm_mul_ps(
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v179, v178), v179)),
                     _mm_mul_ps(*(__m128 *)_xmm, v179)),
                   v170);
          v182 = _mm_or_ps(_mm_and_ps(_mm_mul_ps(v181, v176), v180), _mm_andnot_ps(v180, v176));
          v7 += 112;
          temps += 3;
          LODWORD(temps[-1].m_impulseApplied) = v181.m128_i32[0] & v180.m128_i32[0] | *(unsigned __int128 *)&_mm_andnot_ps(v180, query.m_quad);
          v183 = _mm_or_ps(_mm_and_ps(_mm_mul_ps(v181, v177), v180), _mm_andnot_ps(v180, v177));
          v184 = _mm_mul_ps(v9->m_invMasses.m_quad, v182);
          v185 = _mm_mul_ps(mB->m_invMasses.m_quad, v182);
          v186 = _mm_mul_ps(_mm_shuffle_ps(v185, v185, 255), *(__m128 *)&v7[-112]);
          v9->m_linearVel.m_quad = _mm_add_ps(
                                     v9->m_linearVel.m_quad,
                                     _mm_mul_ps(_mm_shuffle_ps(v184, v184, 255), *(__m128 *)&v7[-112]));
          mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, v186);
          v187 = _mm_mul_ps(v185, *(__m128 *)&v7[-80]);
          v186.m128_i32[0] = (unsigned __int128)_mm_shuffle_ps(
                                                  (__m128)LODWORD(temps[-3].m_impulseApplied),
                                                  (__m128)LODWORD(temps[-3].m_impulseApplied),
                                                  0);
          v9->m_angularVel.m_quad = _mm_add_ps(v9->m_angularVel.m_quad, _mm_mul_ps(v184, *(__m128 *)&v7[-96]));
          mB->m_angularVel.m_quad = _mm_add_ps(mB->m_angularVel.m_quad, v187);
          temps[-3].m_impulseApplied = v186.m128_f32[0] + v182.m128_f32[0];
          v188 = _mm_mul_ps(v9->m_invMasses.m_quad, v183);
          v189 = _mm_mul_ps(mB->m_invMasses.m_quad, v183);
          v190 = _mm_mul_ps(_mm_shuffle_ps(v189, v189, 255), *(__m128 *)&v7[-64]);
          v9->m_linearVel.m_quad = _mm_add_ps(
                                     v9->m_linearVel.m_quad,
                                     _mm_mul_ps(_mm_shuffle_ps(v188, v188, 255), *(__m128 *)&v7[-64]));
          mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, v190);
          v191 = _mm_mul_ps(v189, *(__m128 *)&v7[-32]);
          LODWORD(v192) = (unsigned __int128)_mm_shuffle_ps(
                                               (__m128)LODWORD(temps[-2].m_impulseApplied),
                                               (__m128)LODWORD(temps[-2].m_impulseApplied),
                                               0);
          v9->m_angularVel.m_quad = _mm_add_ps(_mm_mul_ps(v188, *(__m128 *)&v7[-48]), v9->m_angularVel.m_quad);
          mB->m_angularVel.m_quad = _mm_add_ps(v191, mB->m_angularVel.m_quad);
          temps[-2].m_impulseApplied = v192 + v183.m128_f32[0];
          if ( *v7 == 1 )
            goto LABEL_4;
          continue;
        case 0x1Du:
          v9->m_invMasses = *(hkVector4f *)v7;
          mB->m_invMasses = *(hkVector4f *)&v7[16];
          v9->m_invMasses.m_quad.m128_i8[0] = 0;
          goto LABEL_5;
        case 0x1Eu:
          v260 = 0i64;
          v260.m128_f32[0] = (float)temp.m_currentStep.m_storage;
          v261 = (__m128 *)((unsigned __int64)v9 ^ -*(_DWORD *)&v7[16] & ((unsigned __int64)v9 ^ (unsigned __int64)mB));
          v262 = _mm_mul_ps(
                   *(__m128 *)v7,
                   _mm_mul_ps(
                     _mm_shuffle_ps(v260, v260, 0),
                     _mm_shuffle_ps(v8->m_integrateVelocityFactor.m_quad, v8->m_integrateVelocityFactor.m_quad, 0)));
          v261[1] = _mm_add_ps(v262, _mm_add_ps(*(__m128 *)v7, v261[1]));
          v261[4] = _mm_add_ps(v262, v261[4]);
          goto LABEL_5;
        case 0x1Fu:
          v263 = v9->m_angularVel.m_quad;
          v7 += 96;
          v264 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v9->m_angularVel.m_quad, v263, 85), *(__m128 *)&v7[-80]),
                     _mm_mul_ps(_mm_shuffle_ps(v263, v263, 0), *(__m128 *)&v7[-96])),
                   _mm_mul_ps(_mm_shuffle_ps(v263, v263, 170), *(__m128 *)&v7[-64]));
          v265 = mB->m_angularVel.m_quad;
          v266 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(mB->m_angularVel.m_quad, v265, 85), *(__m128 *)&v7[-32]),
                     _mm_mul_ps(_mm_shuffle_ps(v265, v265, 0), *(__m128 *)&v7[-48])),
                   _mm_mul_ps(_mm_shuffle_ps(v265, v265, 170), *(__m128 *)&v7[-16]));
          v267 = v9->m_scratch1.m_quad;
          v268 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v9->m_scratch1.m_quad, v267, 85), *(__m128 *)&v7[-80]),
                     _mm_mul_ps(_mm_shuffle_ps(v267, v267, 0), *(__m128 *)&v7[-96])),
                   _mm_mul_ps(_mm_shuffle_ps(v267, v267, 170), *(__m128 *)&v7[-64]));
          v269 = mB->m_scratch1.m_quad;
          v270 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(mB->m_scratch1.m_quad, v269, 85), *(__m128 *)&v7[-32]),
                     _mm_mul_ps(_mm_shuffle_ps(v269, v269, 0), *(__m128 *)&v7[-48])),
                   _mm_mul_ps(_mm_shuffle_ps(v269, v269, 170), *(__m128 *)&v7[-16]));
          v9->m_linearVel.m_quad = _mm_add_ps(v9->m_linearVel.m_quad, v264);
          v9->m_scratch0.m_quad = _mm_add_ps(v268, v9->m_scratch0.m_quad);
          mB->m_linearVel.m_quad = _mm_add_ps(v266, mB->m_linearVel.m_quad);
          mB->m_scratch0.m_quad = _mm_add_ps(v270, mB->m_scratch0.m_quad);
          continue;
        case 0x20u:
          hkpAtomSolverFunctions::solveStableAngularConstraint3d<hkpVelocityAccumulator,hkpSolverInfo,hkSolverStepTemp>(
            v8,
            &temp,
            (hkpStableAngularSchema3d *)v7,
            v9,
            mB,
            temps);
          v7 += 48;
          temps += 3;
          continue;
        case 0x22u:
          hkpAtomSolverFunctions::solveDeformableLinConstraintStub<hkpVelocityAccumulator,hkpSolverInfo,hkSolverStepTemp>(
            v8,
            &temp,
            (hkpDeformableLinSchema *)v7,
            v9,
            mB,
            temps);
          v7 += 128;
          temps += 3;
          continue;
        case 0x23u:
          hkpAtomSolverFunctions::solveDeformableAngConstraintStub<hkpVelocityAccumulator,hkpSolverInfo,hkSolverStepTemp>(
            v8,
            &temp,
            (hkpDeformableAngSchema *)v7,
            v9,
            mB,
            temps);
          v7 += 128;
          temps += 3;
          continue;
        case 0x27u:
          hkSolver_solveStiffSpringChain(v8, &temp, v6, (hkpJacobianStiffSpringChainSchema *)v7, temps);
          temps += *(unsigned __int16 *)&v7[4];
          v7 += *(unsigned int *)&v7[8];
          continue;
        case 0x28u:
          hkSolver_solveBallAndSocketChain(v8, &temp, v6, (hkpJacobianBallSocketChainSchema *)v7, temps);
          goto LABEL_88;
        case 0x29u:
          hkSolver_solveStabilizedBallAndSocketChain(
            v8,
            &temp,
            v6,
            (hkpJacobianStabilizedBallSocketChainSchema *)v7,
            temps);
LABEL_88:
          v271 = 3 * *(unsigned __int16 *)&v7[4];
          v7 += *(unsigned int *)&v7[8];
          temps += v271;
          continue;
        case 0x2Au:
          hkSolver_solvePoweredChain(v8, &temp, v6, (hkpJacobianPoweredChainSchema *)v7, temps);
          temps += 6 * *(unsigned __int16 *)&v7[4];
          v7 += *(unsigned int *)&v7[16];
          continue;
        case 0x2Bu:
          v125 = *(_QWORD *)&v7[104];
          v126 = *(_QWORD *)(v125 + 40);
          if ( *(_BYTE *)(v126 + 36) )
          {
            v127 = 0.0;
            *(_DWORD *)v126 = 0;
          }
          else
          {
            v127 = *(float *)(v126 + 20);
            *(float *)v126 = (float)(v8->m_invNumMicroSteps
                                   * (float)(v8->m_deltaTime * (float)(*(float *)(v125 + 12) * v127)))
                           + *(float *)v126;
          }
          v128 = mB->m_angularVel.m_quad;
          v129 = *(float *)&v7[44];
          v130 = *(float *)&v7[96];
          v131 = _mm_sub_ps(v9->m_linearVel.m_quad, mB->m_linearVel.m_quad);
          v132 = _mm_add_ps(
                   _mm_mul_ps(*(__m128 *)v7, v131),
                   _mm_add_ps(
                     _mm_mul_ps(v128, *(__m128 *)&v7[32]),
                     _mm_mul_ps(*(__m128 *)&v7[16], v9->m_angularVel.m_quad)));
          LODWORD(v133) = COERCE_UNSIGNED_INT(
                            COERCE_FLOAT(_mm_shuffle_ps(*(__m128 *)v7, *(__m128 *)v7, 255))
                          - (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v132, v132, 85))
                                          + COERCE_FLOAT(_mm_shuffle_ps(v132, v132, 0)))
                                  + COERCE_FLOAT(_mm_shuffle_ps(v132, v132, 170)))) ^ _xmm[0];
          v134 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(v128, *(__m128 *)&v7[80]),
                     _mm_mul_ps(*(__m128 *)&v7[64], v9->m_angularVel.m_quad)),
                   _mm_mul_ps(*(__m128 *)&v7[48], v131));
          v135 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v134, v134, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v134, v134, 0)))
               + COERCE_FLOAT(_mm_shuffle_ps(v134, v134, 170));
          v136 = *(float *)&v7[92];
          LODWORD(v137) = COERCE_UNSIGNED_INT(COERCE_FLOAT(_mm_shuffle_ps(*(__m128 *)&v7[48], *(__m128 *)&v7[48], 255)) - v135) ^ _xmm[0];
          if ( v127 == 0.0 )
          {
            v138 = (float)(*(float *)(v125 + 16) * *(float *)v126) - v133;
            v139 = v130 * v137;
            v140 = (float)(v138 * v129) - (float)(v130 * v137);
          }
          else
          {
            v141 = (float)(*(float *)(v125 + 16) * *(float *)v126) - v133;
            v139 = v130 * v137;
            v140 = (float)((float)(*(float *)(v126 + 24) * (float)(v141 - (float)((float)(v130 * v137) / v129))) * v129)
                 / (float)((float)(v129 * *(float *)(v125 + 16)) + *(float *)(v126 + 24));
          }
          vars0 = v140;
          v142 = COERCE_FLOAT(COERCE_UNSIGNED_INT(v136 * v137) ^ _xmm[0])
               - (float)((float)((float)(v140 + v139) / v129) * v130);
          v299 = v142;
          *(float *)&v274 = (float)(v142 * v142) + (float)(v140 * v140);
          v143 = *(float *)&v7[100];
          v144 = fsqrt(*(float *)&v274);
          if ( v144 <= v143 )
          {
            *(float *)(v125 + 20) = v140 + *(float *)(v125 + 20);
            *(float *)(v125 + 24) = v299 + *(float *)(v125 + 24);
          }
          else
          {
            v145 = v143 / v144;
            *(float *)(v125 + 20) = (float)(v145 * v140) + *(float *)(v125 + 20);
            *(float *)(v125 + 28) = (float)(vars0 - (float)(v145 * v140)) + *(float *)(v125 + 28);
            vars0 = v145 * v140;
            v146 = v145 * v299;
            *(float *)(v125 + 24) = v146 + *(float *)(v125 + 24);
            *(float *)(v125 + 32) = (float)(v299 - v146) + *(float *)(v125 + 32);
            v299 = v146;
          }
          v147.m_quad = (__m128)mB->m_invMasses;
          if ( v144 != 0.0 )
          {
            v148 = *(float *)(v126 + 28) * v144;
            if ( v148 > *(float *)(v126 + 32) )
              v148 = *(float *)(v126 + 32);
            *(float *)&v273 = v148 / v144;
            mB->m_invMasses.m_quad = _mm_mul_ps(
                                       mB->m_invMasses.m_quad,
                                       _mm_shuffle_ps(
                                         (__m128)COERCE_UNSIGNED_INT(v148 / v144),
                                         (__m128)COERCE_UNSIGNED_INT(v148 / v144),
                                         0));
          }
          v149 = _mm_shuffle_ps((__m128)LODWORD(vars0), (__m128)LODWORD(vars0), 0);
          v150 = _mm_shuffle_ps((__m128)LODWORD(v299), (__m128)LODWORD(v299), 0);
          v151 = _mm_mul_ps(v9->m_invMasses.m_quad, v149);
          v152 = _mm_mul_ps(mB->m_invMasses.m_quad, v149);
          v153 = _mm_mul_ps(_mm_shuffle_ps(v152, v152, 255), *(__m128 *)v7);
          v9->m_linearVel.m_quad = _mm_add_ps(
                                     v9->m_linearVel.m_quad,
                                     _mm_mul_ps(_mm_shuffle_ps(v151, v151, 255), *(__m128 *)v7));
          mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, v153);
          v154 = _mm_mul_ps(v152, *(__m128 *)&v7[32]);
          LODWORD(v155) = (unsigned __int128)_mm_shuffle_ps(
                                               (__m128)LODWORD(temps->m_impulseApplied),
                                               (__m128)LODWORD(temps->m_impulseApplied),
                                               0);
          v9->m_angularVel.m_quad = _mm_add_ps(_mm_mul_ps(v151, *(__m128 *)&v7[16]), v9->m_angularVel.m_quad);
          mB->m_angularVel.m_quad = _mm_add_ps(mB->m_angularVel.m_quad, v154);
          temps->m_impulseApplied = v155 + v149.m128_f32[0];
          v156 = _mm_mul_ps(mB->m_invMasses.m_quad, v150);
          v157 = _mm_mul_ps(v9->m_invMasses.m_quad, v150);
          v158 = _mm_mul_ps(_mm_shuffle_ps(v156, v156, 255), *(__m128 *)&v7[48]);
          v9->m_linearVel.m_quad = _mm_add_ps(
                                     v9->m_linearVel.m_quad,
                                     _mm_mul_ps(_mm_shuffle_ps(v157, v157, 255), *(__m128 *)&v7[48]));
          mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, v158);
          v159 = _mm_mul_ps(v156, *(__m128 *)&v7[80]);
          LODWORD(v160) = (unsigned __int128)_mm_shuffle_ps(
                                               (__m128)LODWORD(temps[1].m_impulseApplied),
                                               (__m128)LODWORD(temps[1].m_impulseApplied),
                                               0);
          v9->m_angularVel.m_quad = _mm_add_ps(v9->m_angularVel.m_quad, _mm_mul_ps(v157, *(__m128 *)&v7[64]));
          mB->m_angularVel.m_quad = _mm_add_ps(v159, mB->m_angularVel.m_quad);
          temps[1].m_impulseApplied = v160 + v150.m128_f32[0];
          *(float *)v126 = *(float *)v126 - (float)(vars0 * v127);
          mB->m_invMasses = (hkVector4f)v147.m_quad;
          v161 = *(_QWORD *)(v125 + 40);
          v162 = *(_DWORD *)(v161 + 12) + 1;
          *(_DWORD *)(v161 + 12) = v162;
          v163 = *(_QWORD *)(v125 + 40);
          if ( v162 == *(_DWORD *)(v163 + 40) * v8->m_numMicroSteps )
          {
            v164 = *(float *)v126 - *(float *)(v126 + 4);
            v165 = *(_DWORD *)(v163 + 16) + 1;
            *(_DWORD *)(v163 + 16) = v165;
            if ( v165 == v8->m_numSteps )
            {
              *(float *)v126 = v164;
              *(_DWORD *)(v126 + 4) = 0;
              *(_DWORD *)(v126 + 16) = 0;
            }
            else
            {
              v166 = *(float *)(v126 + 4) + (float)(v164 * v8->m_integrateVelocityFactor.m_quad.m128_f32[0]);
              *(float *)(v126 + 4) = v166;
              *(float *)v126 = v164 + v166;
            }
            *(_DWORD *)(v126 + 12) = 0;
          }
          v7 += 112;
          temps += 2;
          if ( *v7 != 1 )
            continue;
          goto LABEL_4;
        default:
          __debugbreak();
          return;
      }
    }
  }
}                                               0);
          v9->m_angularVel.m_quad = _mm_add_ps(v9->m_angularVel.m_quad, _mm_mul_ps(v157, *(__m128 *)&v7[64]));
          mB->m_angularVel.m_quad = _mm_add_ps(v159, mB->m_angularVel.m_quad);
          temps[1].m_impulseApplied = v160 + v150.m128_f32[0];
          *(float *)v126 = *(float *)v126 - (float)(vars0 * v127);
          mB->m_invMasses = (hkVector4f)v147.m_quad;
          v161 = *(_QWORD *)(v125 + 40);
          v162 = *(_DWORD *)(v161 + 12) + 1;
          *(_DWORD *)(v161 + 12) = v162;
          v163 = *(_QWORD *)(v125 + 40);
          if ( v162 == *(_DWORD *)(v163 + 40) * v8->m_numMicroSteps )
          {
            v164 = *(float *)v126 - *(float *)(v126 + 4);
            v165 = *(_DWORD *)(v163 + 16) + 1;
            *(_DWORD *)(v163 + 16) = v165;
            if ( v165 == v8->m_numSteps )
            {
              *(float *)v126 = v164;
              *(_DWORD *)(v126 + 4) = 0;
              *(_DWORD *)(v126 + 16) = 0;
            }
            else
            {
              v166 = *(float *)(v126 + 4

// File Line: 1738
// RVA: 0xDD86E0
hkSolveConstraints

// File Line: 1777
// RVA: 0xDDAB50
void __fastcall hkSolveApplyGravityByTheSteps(hkpSolverInfo *info, hkpVelocityAccumulator *accumulators, hkpVelocityAccumulator *accumulatorsEnd)
{
  hkpVelocityAccumulator *v3; // rbx
  hkVector4f v4; // xmm9
  signed int v6; // eax
  float v7; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm3_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm3_4
  float v13; // xmm0_4
  float v14; // xmm0_4
  signed __int64 v15; // r10
  __int64 v16; // r8
  __int64 v17; // r9
  float v18; // xmm0_4
  __m128 v19; // xmm4
  float v20; // xmm2_4
  float v21; // xmm1_4
  float v22; // xmm3_4
  __m128 v23; // xmm4
  float v24; // xmm0_4
  float v25; // xmm1_4
  float v26; // xmm3_4
  float v27; // xmm0_4
  float v28; // xmm0_4
  signed __int64 v29; // r10
  __int64 v30; // r8
  __int64 v31; // r9
  float v32; // xmm0_4
  int v33; // [rsp+0h] [rbp-39h]
  __int64 v34; // [rsp+4h] [rbp-35h]
  int v35; // [rsp+10h] [rbp-29h]
  __int64 v36; // [rsp+14h] [rbp-25h]
  hkVector4f v37; // [rsp+20h] [rbp-19h]
  hkVector4f v38; // [rsp+30h] [rbp-9h]

  v3 = accumulatorsEnd;
  if ( !accumulatorsEnd )
    v3 = (hkpVelocityAccumulator *)-1i64;
  v4.m_quad = (__m128)info->m_globalAccelerationPerSubStep;
  _R11 = accumulators;
  while ( _R11 < v3 )
  {
    __asm { prefetchnta byte ptr [r11+100h]; Prefetch to L1 cache }
    v6 = (unsigned __int8)_R11->m_type.m_storage;
    if ( !_R11->m_type.m_storage )
    {
      while ( 1 )
      {
        v19 = (__m128)LODWORD(_R11->m_gravityFactor);
        _R11->m_context.m_storage = 1;
        v20 = _R11->m_scratch0.m_quad.m128_f32[0];
        v21 = _R11->m_scratch1.m_quad.m128_f32[1];
        v22 = _R11->m_scratch2.m_quad.m128_f32[2];
        v23 = _mm_shuffle_ps(v19, v19, 0);
        v24 = (float)(_R11->m_scratch0.m_quad.m128_f32[0] + v21) + v22;
        if ( v24 <= 0.0 )
        {
          v35 = 1;
          v36 = 2i64;
          v29 = 0i64;
          if ( v21 > v20 )
            v29 = 1i64;
          if ( v22 > _R11->m_scratch0.m_quad.m128_f32[5 * v29] )
            v29 = 2i64;
          v30 = *(&v35 + v29);
          v31 = *(&v35 + v30);
          v32 = fsqrt(
                  (float)(_R11->m_scratch0.m_quad.m128_f32[5 * v29]
                        - (float)(_R11->m_scratch0.m_quad.m128_f32[5 * v31] + _R11->m_scratch0.m_quad.m128_f32[5 * v30]))
                + 1.0);
          v38.m_quad.m128_f32[v29] = v32 * 0.5;
          v38.m_quad.m128_f32[3] = (float)(_R11->m_scratch0.m_quad.m128_f32[v31 + 4 * v30]
                                         - _R11->m_scratch0.m_quad.m128_f32[v30 + 4 * v31])
                                 * (float)(0.5 / v32);
          v38.m_quad.m128_f32[v30] = (float)(_R11->m_scratch0.m_quad.m128_f32[v29 + 4 * v30]
                                           + _R11->m_scratch0.m_quad.m128_f32[v30 + 4 * v29])
                                   * (float)(0.5 / v32);
          v38.m_quad.m128_f32[v31] = (float)(_R11->m_scratch0.m_quad.m128_f32[v29 + 4 * v31]
                                           + _R11->m_scratch0.m_quad.m128_f32[v31 + 4 * v29])
                                   * (float)(0.5 / v32);
        }
        else
        {
          v25 = _R11->m_scratch2.m_quad.m128_f32[0] - _R11->m_scratch0.m_quad.m128_f32[2];
          v26 = fsqrt(v24 + 1.0);
          v27 = _R11->m_scratch1.m_quad.m128_f32[2] - _R11->m_scratch2.m_quad.m128_f32[1];
          v38.m_quad.m128_f32[3] = v26 * 0.5;
          v38.m_quad.m128_f32[0] = v27 * (float)(0.5 / v26);
          v28 = _R11->m_scratch0.m_quad.m128_f32[1];
          v38.m_quad.m128_f32[1] = v25 * (float)(0.5 / v26);
          v38.m_quad.m128_f32[2] = (float)(v28 - _R11->m_scratch1.m_quad.m128_f32[0]) * (float)(0.5 / v26);
        }
        ++_R11;
        _R11[-1].m_scratch2 = (hkVector4f)v38.m_quad;
        _R11[-1].m_scratch0 = 0i64;
        _R11[-1].m_scratch1 = 0i64;
        _R11[-1].m_linearVel.m_quad = _mm_add_ps(_mm_mul_ps(v4.m_quad, v23), _R11[-1].m_linearVel.m_quad);
        if ( _R11->m_type.m_storage )
          break;
        if ( _R11 >= v3 )
          return;
      }
      continue;
    }
    if ( v6 > 0 )
    {
      if ( v6 <= 2 )
      {
        _R11->m_context.m_storage = 1;
        v7 = _R11->m_scratch0.m_quad.m128_f32[0];
        v8 = _R11->m_scratch1.m_quad.m128_f32[1];
        v9 = _R11->m_scratch2.m_quad.m128_f32[2];
        v10 = (float)(_R11->m_scratch0.m_quad.m128_f32[0] + v8) + v9;
        if ( v10 <= 0.0 )
        {
          v33 = 1;
          v34 = 2i64;
          v15 = 0i64;
          if ( v8 > v7 )
            v15 = 1i64;
          if ( v9 > _R11->m_scratch0.m_quad.m128_f32[5 * v15] )
            v15 = 2i64;
          v16 = *(&v33 + v15);
          v17 = *(&v33 + v16);
          v18 = fsqrt(
                  (float)(_R11->m_scratch0.m_quad.m128_f32[5 * v15]
                        - (float)(_R11->m_scratch0.m_quad.m128_f32[5 * v17] + _R11->m_scratch0.m_quad.m128_f32[5 * v16]))
                + 1.0);
          v37.m_quad.m128_f32[v15] = v18 * 0.5;
          v37.m_quad.m128_f32[3] = (float)(_R11->m_scratch0.m_quad.m128_f32[v17 + 4 * v16]
                                         - _R11->m_scratch0.m_quad.m128_f32[v16 + 4 * v17])
                                 * (float)(0.5 / v18);
          v37.m_quad.m128_f32[v16] = (float)(_R11->m_scratch0.m_quad.m128_f32[v16 + 4 * v15]
                                           + _R11->m_scratch0.m_quad.m128_f32[v15 + 4 * v16])
                                   * (float)(0.5 / v18);
          v37.m_quad.m128_f32[v17] = (float)(_R11->m_scratch0.m_quad.m128_f32[v17 + 4 * v15]
                                           + _R11->m_scratch0.m_quad.m128_f32[v15 + 4 * v17])
                                   * (float)(0.5 / v18);
        }
        else
        {
          v11 = _R11->m_scratch2.m_quad.m128_f32[0] - _R11->m_scratch0.m_quad.m128_f32[2];
          v12 = fsqrt(v10 + 1.0);
          v13 = _R11->m_scratch1.m_quad.m128_f32[2] - _R11->m_scratch2.m_quad.m128_f32[1];
          v37.m_quad.m128_f32[3] = v12 * 0.5;
          v37.m_quad.m128_f32[0] = v13 * (float)(0.5 / v12);
          v14 = _R11->m_scratch0.m_quad.m128_f32[1];
          v37.m_quad.m128_f32[1] = v11 * (float)(0.5 / v12);
          v37.m_quad.m128_f32[2] = (float)(v14 - _R11->m_scratch1.m_quad.m128_f32[0]) * (float)(0.5 / v12);
        }
        ++_R11;
        _R11[-1].m_scratch2 = (hkVector4f)v37.m_quad;
        _R11[-1].m_scratch0 = 0i64;
        _R11[-1].m_scratch1 = 0i64;
        continue;
      }
      if ( v6 == 3 )
        return;
    }
    __debugbreak();
  }
}

// File Line: 1789
// RVA: 0xDDAF60
char __fastcall hkSolveConstraintsByTheSteps(hkpSolverInfo *info, int currentSolverStep, int currentSolverMicroStep, hkpJacobianSchema *schemas, hkpVelocityAccumulator *accumulators, hkpSolverElemTemp *elemTemp)
{
  hkpJacobianSchema *v6; // rbx
  int v7; // edi
  hkpSolverInfo *v8; // r15
  hkpSolverElemTemp *temps; // rsi
  __m128 v11; // xmm0
  int v12; // eax
  hkpVelocityAccumulator *v13; // r14
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
  __m128 v35; // xmm3
  __m128 v36; // xmm2
  __m128 v37; // xmm9
  __m128 v38; // xmm5
  __m128 v39; // xmm3
  __m128 v40; // xmm1
  __m128 v41; // xmm6
  __m128 v42; // xmm5
  __m128 v43; // xmm7
  __m128 v44; // xmm2
  __m128 v45; // xmm8
  float v46; // xmm2_4
  __m128 v47; // xmm4
  __m128 v48; // xmm3
  __m128 v49; // xmm2
  __m128 v50; // xmm4
  float v51; // xmm1_4
  __m128 v52; // xmm3
  __m128 v53; // xmm4
  __m128 v54; // xmm2
  __m128 v55; // xmm4
  float v56; // xmm0_4
  __m128 v57; // xmm5
  __m128 v58; // xmm8
  __m128 v59; // xmm4
  __m128 v60; // xmm3
  __m128 v61; // xmm2
  __m128 v62; // xmm3
  float v63; // xmm1_4
  __m128 v64; // xmm4
  __m128 v65; // xmm3
  __m128 v66; // xmm2
  __m128 v67; // xmm3
  float v68; // xmm0_4
  __m128 v69; // xmm5
  __m128 v70; // xmm4
  __m128 v71; // xmm2
  __m128 v72; // xmm1
  __m128 v73; // xmm2
  __m128 v74; // xmm9
  __m128 v75; // xmm5
  __m128 v76; // xmm2
  __m128 v77; // xmm1
  __m128 v78; // xmm8
  __m128 v79; // xmm5
  __m128 v80; // xmm7
  __m128 v81; // xmm6
  float v82; // xmm7_4
  __m128 v83; // xmm4
  __m128 v84; // xmm3
  __m128 v85; // xmm2
  __m128 v86; // xmm3
  float v87; // xmm1_4
  __m128 v88; // xmm4
  __m128 v89; // xmm3
  __m128 v90; // xmm2
  __m128 v91; // xmm4
  float v92; // xmm1_4
  __m128 v93; // xmm5
  __m128 v94; // xmm6
  __m128 v95; // xmm4
  __m128 v96; // xmm3
  __m128 v97; // xmm2
  __m128 v98; // xmm3
  float v99; // xmm0_4
  __m128 v100; // xmm4
  __m128 v101; // xmm3
  __m128 v102; // xmm2
  __m128 v103; // xmm4
  float v104; // xmm5_4
  __m128 v105; // xmm5
  __m128 v106; // xmm4
  __m128 v107; // xmm6
  __m128 v108; // xmm3
  __m128 v109; // xmm7
  __m128 v110; // xmm2
  __m128 v111; // xmm9
  __m128 v112; // xmm2
  __m128 v113; // xmm7
  __m128 v114; // xmm2
  __m128 v115; // xmm10
  __m128 v116; // xmm1
  __m128 v117; // xmm4
  __m128 v118; // xmm5
  __m128 v119; // xmm3
  __m128 v120; // xmm8
  __m128 v121; // xmm1
  __m128 v122; // xmm3
  __m128 v123; // xmm6
  __m128 v124; // xmm5
  __m128 v125; // xmm7
  __m128 v126; // xmm4
  __m128 v127; // xmm3
  __m128 v128; // xmm2
  __m128 v129; // xmm3
  float v130; // xmm0_4
  __m128 v131; // xmm3
  __m128 v132; // xmm4
  __m128 v133; // xmm2
  __m128 v134; // xmm3
  __m128 v135; // xmm2
  __m128 v136; // xmm4
  float v137; // xmm0_4
  __m128 v138; // xmm1
  __int64 v139; // r9
  __int64 v140; // r8
  float v141; // xmm9_4
  __m128 v142; // xmm5
  float v143; // xmm8_4
  float v144; // xmm10_4
  __m128 v145; // xmm4
  __m128 v146; // xmm2
  float v147; // xmm7_4
  __m128 v148; // xmm5
  float v149; // xmm6_4
  float v150; // xmm4_4
  float v151; // xmm7_4
  float v152; // xmm4_4
  float v153; // xmm2_4
  float v154; // xmm5_4
  float v155; // xmm3_4
  float v156; // xmm5_4
  float v157; // xmm3_4
  float v158; // xmm3_4
  hkVector4f v159; // xmm7
  float v160; // xmm0_4
  __m128 v161; // xmm5
  __m128 v162; // xmm6
  __m128 v163; // xmm4
  __m128 v164; // xmm3
  __m128 v165; // xmm2
  __m128 v166; // xmm3
  float v167; // xmm0_4
  __m128 v168; // xmm3
  __m128 v169; // xmm4
  __m128 v170; // xmm2
  __m128 v171; // xmm4
  __int64 v172; // rcx
  int v173; // edx
  __int64 v174; // rcx
  float v175; // xmm1_4
  int v176; // eax
  float v177; // xmm0_4
  __int64 v178; // rax
  int v179; // eax
  __m128 v180; // xmm5
  __m128 v181; // xmm4
  __m128 v182; // xmm6
  __m128 v183; // xmm2
  __m128 v184; // xmm7
  __m128 v185; // xmm5
  __m128 v186; // xmm2
  __m128 v187; // xmm1
  __m128 v188; // xmm5
  __m128 v189; // xmm4
  __m128 v190; // xmm3
  __m128 v191; // xmm1
  __m128 v192; // xmm8
  __m128 v193; // xmm3
  __m128 v194; // xmm6
  __m128 v195; // xmm5
  __m128 v196; // xmm4
  __m128 v197; // xmm3
  __m128 v198; // xmm2
  __m128 v199; // xmm3
  __m128 v200; // xmm4
  __m128 v201; // xmm3
  __m128 v202; // xmm2
  __m128 v203; // xmm4
  __m128 v204; // xmm6
  __m128 v205; // xmm3
  __m128 v206; // xmm4
  __m128 v207; // xmm4
  __m128 v208; // xmm2
  __m128i v209; // xmm6
  __m128 v210; // xmm1
  __m128 v211; // xmm5
  __m128 v212; // xmm0
  __m128 v213; // xmm6
  __m128 v214; // xmm2
  __m128 v215; // xmm3
  __m128 v216; // xmm7
  __m128 v217; // xmm6
  __m128 v218; // xmm8
  __m128 v219; // xmm4
  __m128 v220; // xmm2
  __m128 v221; // xmm1
  float v222; // xmm2_4
  __m128 v223; // xmm6
  __m128 v224; // xmm3
  __m128 v225; // xmm0
  __m128 v226; // xmm6
  __m128 v227; // xmm0
  __int64 v228; // rax
  __m128 v229; // xmm4
  __m128 v230; // xmm5
  __m128 v231; // xmm2
  __m128 v232; // xmm7
  __m128 v233; // xmm2
  __m128 v234; // xmm6
  __m128 v235; // xmm8
  __m128 v236; // xmm4
  __m128 v237; // xmm5
  __m128 v238; // xmm2
  float v239; // xmm1_4
  __m128 v240; // xmm3
  __m128 v241; // xmm5
  __m128 v242; // xmm4
  __m128 v243; // xmm2
  __m128 v244; // xmm1
  float v245; // xmm0_4
  __m128 v246; // xmm3
  __m128 v247; // xmm4
  __m128 v248; // xmm6
  __m128 v249; // xmm2
  __m128 v250; // xmm2
  __m128 v251; // xmm6
  __m128 v252; // xmm3
  __m128 v253; // xmm2
  __m128 v254; // xmm2
  float v255; // xmm1_4
  __int64 v256; // rax
  __int64 v257; // rax
  __m128 v258; // xmm6
  __m128 v259; // xmm3
  __m128 v260; // xmm2
  __m128 v261; // xmm2
  __m128i v262; // xmm6
  __m128 v263; // xmm0
  __m128 v264; // xmm1
  __m128 v265; // xmm5
  __m128 v266; // xmm6
  __m128 v267; // xmm4
  __m128 v268; // xmm3
  __m128 v269; // xmm2
  __m128 v270; // xmm3
  __int64 v271; // rax
  __int64 v272; // rax
  __m128 v273; // xmm3
  __m128 *v274; // rcx
  __m128 v275; // xmm2
  __m128 v276; // xmm1
  __m128 v277; // xmm10
  __m128 v278; // xmm1
  __m128 v279; // xmm9
  __m128 v280; // xmm1
  __m128 v281; // xmm3
  __m128 v282; // xmm1
  __m128 v283; // xmm2
  __int64 v284; // rcx
  float v285; // [rsp+40h] [rbp-C0h]
  float v286; // [rsp+44h] [rbp-BCh]
  hkSolverStepTemp temp; // [rsp+50h] [rbp-B0h]
  float v288; // [rsp+70h] [rbp-90h]
  float v289; // [rsp+78h] [rbp-88h]
  hkpVelocityAccumulator regB; // [rsp+80h] [rbp-80h]
  hkpVelocityAccumulator mA; // [rsp+100h] [rbp+0h]
  __m128 v292; // [rsp+180h] [rbp+80h]
  __m128 v293; // [rsp+190h] [rbp+90h]
  __m128 v294; // [rsp+1A0h] [rbp+A0h]
  __m128 v295; // [rsp+1B0h] [rbp+B0h]
  __m128 v296; // [rsp+1C0h] [rbp+C0h]
  __m128 v297; // [rsp+1D0h] [rbp+D0h]
  __m128 v298; // [rsp+1E0h] [rbp+E0h]
  __m128 v299; // [rsp+1F0h] [rbp+F0h]
  __m128 v300; // [rsp+200h] [rbp+100h]
  __m128 v301; // [rsp+210h] [rbp+110h]
  __int128 v302; // [rsp+220h] [rbp+120h]
  __m128 v303; // [rsp+230h] [rbp+130h]

  v6 = schemas;
  v7 = currentSolverStep;
  v8 = info;
  if ( !HK_flyingcolors_solver.m_bool )
  {
    hkpProcessFlyingColors(&HK_flyingcolors_solver);
    if ( !HK_flyingcolors_solver.m_bool )
      return 0;
  }
  temps = elemTemp;
  temp.m_currentStep.m_storage = v7;
  v11 = 0i64;
  v11.m128_f32[0] = (float)(v7 + 1);
  v12 = (int)*v6;
  temp.m_intregratePositionFactor.m_real = _mm_shuffle_ps(v11, v11, 0);
  if ( v12 )
  {
    if ( v12 != 2 )
      goto LABEL_7;
    v13 = &mA;
    mB = &regB;
    *(_QWORD *)&mA.m_type.m_storage = __PAIR__(
                                        _mm_cvtsi128_si32(_mm_srli_si128((__m128i)0i64, 4)),
                                        _mm_cvtsi128_si32((__m128i)0i64));
    mA.m_linearVel.m_quad.m128_u64[0] = *(_QWORD *)&mA.m_type.m_storage;
    mA.m_angularVel.m_quad.m128_u64[0] = *(_QWORD *)&mA.m_type.m_storage;
    v302 = 0i64;
    *(_QWORD *)&mA.m_gravityFactor = __PAIR__(
                                       _mm_cvtsi128_si32(_mm_srli_si128((__m128i)0i64, 12)),
                                       _mm_cvtsi128_si32(_mm_srli_si128((__m128i)0i64, 8)));
    mA.m_linearVel.m_quad.m128_u64[1] = *(_QWORD *)&mA.m_gravityFactor;
    mA.m_angularVel.m_quad.m128_u64[1] = *(_QWORD *)&mA.m_gravityFactor;
    mA.m_invMasses = *(hkVector4f *)&mA.m_type.m_storage;
    mA.m_scratch0 = *(hkVector4f *)&mA.m_type.m_storage;
    mA.m_scratch1 = *(hkVector4f *)&mA.m_type.m_storage;
    mA.m_scratch2 = *(hkVector4f *)&mA.m_type.m_storage;
    mA.m_scratch3 = *(hkVector4f *)&mA.m_type.m_storage;
    *(_QWORD *)&regB.m_type.m_storage = *(_QWORD *)&mA.m_type.m_storage;
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
      switch ( (unsigned __int8)*v6 )
      {
        case 0u:
          return 1;
        case 1u:
          goto LABEL_7;
        case 2u:
          v6 += *(_QWORD *)&v6[8];
          continue;
        case 3u:
          v6 += 16;
          continue;
        case 5u:
          do
          {
            v247 = *(__m128 *)v6;
            v248 = *(__m128 *)&v6[16];
            v249 = *(__m128 *)&v6[32];
            v6 += 48;
            v250 = _mm_add_ps(
                     _mm_add_ps(_mm_mul_ps(v249, mB->m_angularVel.m_quad), _mm_mul_ps(v248, v13->m_angularVel.m_quad)),
                     _mm_mul_ps(v247, _mm_sub_ps(v13->m_linearVel.m_quad, mB->m_linearVel.m_quad)));
            v251 = _mm_mul_ps(
                     _mm_shuffle_ps(v248, v248, 255),
                     _mm_sub_ps(
                       _mm_shuffle_ps(v247, v247, 255),
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v250, v250, 85), _mm_shuffle_ps(v250, v250, 0)),
                         _mm_shuffle_ps(v250, v250, 170))));
            v252 = _mm_mul_ps(v13->m_invMasses.m_quad, v251);
            v253 = _mm_mul_ps(mB->m_invMasses.m_quad, v251);
            v13->m_linearVel.m_quad = _mm_add_ps(
                                        _mm_mul_ps(_mm_shuffle_ps(v252, v252, 255), v247),
                                        v13->m_linearVel.m_quad);
            mB->m_linearVel.m_quad = _mm_sub_ps(
                                       mB->m_linearVel.m_quad,
                                       _mm_mul_ps(_mm_shuffle_ps(v253, v253, 255), v247));
            v254 = _mm_mul_ps(v253, *(__m128 *)&v6[-16]);
            v255 = COERCE_FLOAT(
                     _mm_shuffle_ps(
                       (__m128)LODWORD(temps->m_impulseApplied),
                       (__m128)LODWORD(temps->m_impulseApplied),
                       0))
                 + v251.m128_f32[0];
            v13->m_angularVel.m_quad = _mm_add_ps(_mm_mul_ps(v252, *(__m128 *)&v6[-32]), v13->m_angularVel.m_quad);
            mB->m_angularVel.m_quad = _mm_add_ps(mB->m_angularVel.m_quad, v254);
            temps->m_impulseApplied = v255;
            temps += (unsigned __int8)hkpJacobianSchema::s_schemaNumSolverElemTemps[*(_BYTE *)&v6[-48]];
          }
          while ( *v6 == 5 );
          continue;
        case 6u:
          do
          {
            hkpAtomSolverFunctions::solve1dBilateralWithImpulseLimit<hkpVelocityAccumulator,hkpSolverInfo,hkSolverStepTemp>(
              v8,
              &temp,
              (hkpJacobian1dBilateralSchema *)v6,
              v13,
              mB,
              temps);
            v256 = (__int64)*v6;
            v6 += 48;
            temps += *(unsigned __int8 *)(v256 + 5403477904i64);
          }
          while ( *v6 == 6 );
          continue;
        case 7u:
          do
          {
            hkpAtomSolverFunctions::solve1dBilateralUserTau<hkpVelocityAccumulator,hkpSolverInfo,hkSolverStepTemp>(
              v8,
              &temp,
              (hkpJacobian1dBilateralUserTauSchema *)v6,
              v13,
              mB,
              temps);
            v257 = (__int64)*v6;
            v6 += 64;
            temps += *(unsigned __int8 *)(v257 + 5403477904i64);
          }
          while ( *v6 == 7 );
          continue;
        case 8u:
          do
          {
            hkpAtomSolverFunctions::solve1dLinLimits<hkpVelocityAccumulator,hkpSolverInfo,hkSolverStepTemp>(
              v8,
              &temp,
              (hkpJacobian1dLinearLimitsSchema *)v6,
              v13,
              mB,
              temps);
            v271 = (__int64)*v6;
            v6 += 64;
            temps += *(unsigned __int8 *)(v271 + 5403477904i64);
          }
          while ( *v6 == 8 );
          continue;
        case 9u:
          do
          {
            v258 = *(__m128 *)&v6[16];
            v259 = *(__m128 *)v6;
            v260 = *(__m128 *)&v6[32];
            v6 += 64;
            v261 = _mm_add_ps(
                     _mm_add_ps(_mm_mul_ps(v260, mB->m_angularVel.m_quad), _mm_mul_ps(v258, v13->m_angularVel.m_quad)),
                     _mm_mul_ps(v259, _mm_sub_ps(v13->m_linearVel.m_quad, mB->m_linearVel.m_quad)));
            v262 = (__m128i)_mm_mul_ps(
                              _mm_shuffle_ps(v258, v258, 255),
                              _mm_sub_ps(
                                _mm_shuffle_ps(v259, v259, 255),
                                _mm_add_ps(
                                  _mm_add_ps(_mm_shuffle_ps(v261, v261, 85), _mm_shuffle_ps(v261, v261, 0)),
                                  _mm_shuffle_ps(v261, v261, 170))));
            v295 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v262, 1u), 1u);
            v263 = _mm_rcp_ps(v295);
            v264 = _mm_shuffle_ps((__m128)*(unsigned int *)&v6[-16], (__m128)*(unsigned int *)&v6[-16], 0);
            v265 = _mm_cmpltps(v264, v295);
            v266 = _mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v262, 0x1Fu), 0x1Fu), _mm_min_ps(v295, v264));
            v297 = _mm_or_ps(
                     _mm_andnot_ps(v265, query.m_quad),
                     _mm_and_ps(
                       _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v295, v263)), v263), v264),
                       v265));
            temps[1].m_impulseApplied = v297.m128_f32[0];
            v267 = _mm_mul_ps(v13->m_invMasses.m_quad, v266);
            v268 = _mm_mul_ps(mB->m_invMasses.m_quad, v266);
            v269 = _mm_mul_ps(_mm_shuffle_ps(v268, v268, 255), *(__m128 *)&v6[-64]);
            v13->m_linearVel.m_quad = _mm_add_ps(
                                        v13->m_linearVel.m_quad,
                                        _mm_mul_ps(_mm_shuffle_ps(v267, v267, 255), *(__m128 *)&v6[-64]));
            mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, v269);
            v270 = _mm_mul_ps(v268, *(__m128 *)&v6[-32]);
            v263.m128_i32[0] = (unsigned __int128)_mm_shuffle_ps(
                                                    (__m128)LODWORD(temps->m_impulseApplied),
                                                    (__m128)LODWORD(temps->m_impulseApplied),
                                                    0);
            v13->m_angularVel.m_quad = _mm_add_ps(_mm_mul_ps(v267, *(__m128 *)&v6[-48]), v13->m_angularVel.m_quad);
            mB->m_angularVel.m_quad = _mm_add_ps(v270, mB->m_angularVel.m_quad);
            temps->m_impulseApplied = v263.m128_f32[0] + v266.m128_f32[0];
            temps += (unsigned __int8)hkpJacobianSchema::s_schemaNumSolverElemTemps[*(_BYTE *)&v6[-64]];
          }
          while ( *v6 == 9 );
          continue;
        case 0xAu:
          do
          {
            hkpAtomSolverFunctions::solve1dLinearMotor<hkpVelocityAccumulator,hkpSolverInfo,hkSolverStepTemp>(
              0i64,
              v8,
              &temp,
              (hkpJacobian1dLinearMotorSchema *)v6,
              v13,
              mB,
              temps,
              0i64);
            v272 = (__int64)*v6;
            v6 += 80;
            temps += *(unsigned __int8 *)(v272 + 5403477904i64);
          }
          while ( *v6 == 10 );
          continue;
        case 0xBu:
          hkpAtomSolverFunctions::solvePulley<hkpVelocityAccumulator,hkpSolverInfo,hkSolverStepTemp>(
            v8,
            &temp,
            (hkpJacobian1dPulleySchema *)v6,
            v13,
            mB,
            temps);
          ++temps;
          v6 += 64;
          continue;
        case 0xCu:
          do
          {
            v241 = *(__m128 *)v6;
            v242 = *(__m128 *)&v6[16];
            v6 += 32;
            v243 = _mm_add_ps(_mm_mul_ps(v241, v13->m_angularVel.m_quad), _mm_mul_ps(v242, mB->m_angularVel.m_quad));
            v244 = _mm_mul_ps(
                     _mm_shuffle_ps(v241, v241, 255),
                     _mm_sub_ps(
                       _mm_shuffle_ps(v242, v242, 255),
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v243, v243, 85), _mm_shuffle_ps(v243, v243, 0)),
                         _mm_shuffle_ps(v243, v243, 170))));
            v245 = COERCE_FLOAT(
                     _mm_shuffle_ps(
                       (__m128)LODWORD(temps->m_impulseApplied),
                       (__m128)LODWORD(temps->m_impulseApplied),
                       0))
                 + v244.m128_f32[0];
            v246 = _mm_mul_ps(_mm_mul_ps(v244, mB->m_invMasses.m_quad), v242);
            v13->m_angularVel.m_quad = _mm_add_ps(
                                         _mm_mul_ps(_mm_mul_ps(v244, v13->m_invMasses.m_quad), v241),
                                         v13->m_angularVel.m_quad);
            mB->m_angularVel.m_quad = _mm_add_ps(v246, mB->m_angularVel.m_quad);
            temps->m_impulseApplied = v245;
            temps += (unsigned __int8)hkpJacobianSchema::s_schemaNumSolverElemTemps[*(_BYTE *)&v6[-32]];
          }
          while ( *v6 == 12 );
          continue;
        case 0xDu:
          do
          {
            v215 = *(__m128 *)&v6[16];
            v216 = *(__m128 *)v6;
            v217 = _mm_shuffle_ps((__m128)*(unsigned int *)&v6[40], (__m128)*(unsigned int *)&v6[40], 0);
            v218 = *(__m128 *)&v6[16];
            v219 = _mm_shuffle_ps(v216, v216, 255);
            v220 = _mm_add_ps(
                     _mm_mul_ps(
                       _mm_mul_ps(
                         _mm_shuffle_ps(
                           v8->m_invIntegrateVelocityFactor.m_quad,
                           v8->m_invIntegrateVelocityFactor.m_quad,
                           0),
                         v217),
                       _mm_add_ps(
                         _mm_mul_ps(*(__m128 *)&v6[16], mB->m_scratch1.m_quad),
                         _mm_mul_ps(*(__m128 *)v6, v13->m_scratch1.m_quad))),
                     _mm_mul_ps(
                       _mm_add_ps(
                         _mm_mul_ps(v215, _mm_sub_ps(mB->m_angularVel.m_quad, mB->m_scratch1.m_quad)),
                         _mm_mul_ps(_mm_sub_ps(v13->m_angularVel.m_quad, v13->m_scratch1.m_quad), *(__m128 *)v6)),
                       _mm_shuffle_ps((__m128)LODWORD(v8->m_damping), (__m128)LODWORD(v8->m_damping), 0)));
            v221 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v220, v220, 85), _mm_shuffle_ps(v220, v220, 0)),
                     _mm_shuffle_ps(v220, v220, 170));
            LODWORD(v222) = (unsigned __int128)_mm_shuffle_ps(
                                                 (__m128)LODWORD(temps->m_impulseApplied),
                                                 (__m128)LODWORD(temps->m_impulseApplied),
                                                 0);
            v223 = _mm_sub_ps(_mm_mul_ps(v217, _mm_shuffle_ps(v215, v215, 255)), v221);
            v224 = _mm_mul_ps(
                     _mm_sub_ps(
                       v223,
                       _mm_shuffle_ps((__m128)*(unsigned int *)&v6[32], (__m128)*(unsigned int *)&v6[32], 0)),
                     v219);
            if ( v224.m128_f32[0] <= (float)(0.0 - v222) )
            {
              v226 = _mm_mul_ps(
                       _mm_sub_ps(
                         v223,
                         _mm_shuffle_ps((__m128)*(unsigned int *)&v6[36], (__m128)*(unsigned int *)&v6[36], 0)),
                       v219);
              if ( v226.m128_f32[0] < (float)(0.0 - v222) )
              {
                v227 = _mm_mul_ps(mB->m_invMasses.m_quad, v226);
                v13->m_angularVel.m_quad = _mm_add_ps(
                                             _mm_mul_ps(_mm_mul_ps(v13->m_invMasses.m_quad, v226), v216),
                                             v13->m_angularVel.m_quad);
                mB->m_angularVel.m_quad = _mm_add_ps(_mm_mul_ps(v227, v218), mB->m_angularVel.m_quad);
                temps->m_impulseApplied = v226.m128_f32[0] + v222;
              }
            }
            else
            {
              v225 = _mm_mul_ps(_mm_mul_ps(mB->m_invMasses.m_quad, v224), v218);
              v13->m_angularVel.m_quad = _mm_add_ps(
                                           _mm_mul_ps(_mm_mul_ps(v13->m_invMasses.m_quad, v224), v216),
                                           v13->m_angularVel.m_quad);
              mB->m_angularVel.m_quad = _mm_add_ps(v225, mB->m_angularVel.m_quad);
              temps->m_impulseApplied = v222 + v224.m128_f32[0];
            }
            v228 = (__int64)*v6;
            v6 += 48;
            temps += *(unsigned __int8 *)(v228 + 5403477904i64);
          }
          while ( *v6 == 13 );
          continue;
        case 0xEu:
          do
          {
            v204 = *(__m128 *)v6;
            v205 = *(__m128 *)&v6[16];
            v206 = (__m128)*(unsigned int *)&v6[32];
            v6 += 48;
            v207 = _mm_shuffle_ps(v206, v206, 0);
            v208 = _mm_add_ps(_mm_mul_ps(v204, v13->m_angularVel.m_quad), _mm_mul_ps(v205, mB->m_angularVel.m_quad));
            v209 = (__m128i)_mm_mul_ps(
                              _mm_shuffle_ps(v204, v204, 255),
                              _mm_sub_ps(
                                _mm_shuffle_ps(v205, v205, 255),
                                _mm_add_ps(
                                  _mm_add_ps(_mm_shuffle_ps(v208, v208, 85), _mm_shuffle_ps(v208, v208, 0)),
                                  _mm_shuffle_ps(v208, v208, 170))));
            v210 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v209, 1u), 1u);
            v211 = _mm_cmpltps(v207, v210);
            v296 = v210;
            v212 = _mm_rcp_ps(v210);
            v213 = _mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v209, 0x1Fu), 0x1Fu), _mm_min_ps(v210, v207));
            v300 = _mm_or_ps(
                     _mm_andnot_ps(v211, query.m_quad),
                     _mm_and_ps(
                       _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v210, v212)), v212), v207),
                       v211));
            temps[1].m_impulseApplied = v300.m128_f32[0];
            v210.m128_f32[0] = COERCE_FLOAT(
                                 _mm_shuffle_ps(
                                   (__m128)LODWORD(temps->m_impulseApplied),
                                   (__m128)LODWORD(temps->m_impulseApplied),
                                   0))
                             + v213.m128_f32[0];
            v214 = _mm_mul_ps(_mm_mul_ps(mB->m_invMasses.m_quad, v213), *(__m128 *)&v6[-32]);
            v13->m_angularVel.m_quad = _mm_add_ps(
                                         _mm_mul_ps(_mm_mul_ps(v13->m_invMasses.m_quad, v213), *(__m128 *)&v6[-48]),
                                         v13->m_angularVel.m_quad);
            mB->m_angularVel.m_quad = _mm_add_ps(v214, mB->m_angularVel.m_quad);
            temps->m_impulseApplied = v210.m128_f32[0];
            temps += (unsigned __int8)hkpJacobianSchema::s_schemaNumSolverElemTemps[*(_BYTE *)&v6[-48]];
          }
          while ( *v6 == 14 );
          continue;
        case 0xFu:
          do
          {
            v229 = *(__m128 *)&v6[16];
            v230 = _mm_shuffle_ps((__m128)*(unsigned int *)&v6[44], (__m128)*(unsigned int *)&v6[44], 0);
            v231 = _mm_add_ps(
                     _mm_mul_ps(
                       _mm_mul_ps(
                         _mm_shuffle_ps(
                           v8->m_invIntegrateVelocityFactor.m_quad,
                           v8->m_invIntegrateVelocityFactor.m_quad,
                           0),
                         v230),
                       _mm_add_ps(
                         _mm_mul_ps(*(__m128 *)&v6[16], mB->m_scratch1.m_quad),
                         _mm_mul_ps(*(__m128 *)v6, v13->m_scratch1.m_quad))),
                     _mm_mul_ps(
                       _mm_add_ps(
                         _mm_mul_ps(v229, _mm_sub_ps(mB->m_angularVel.m_quad, mB->m_scratch1.m_quad)),
                         _mm_mul_ps(_mm_sub_ps(v13->m_angularVel.m_quad, v13->m_scratch1.m_quad), *(__m128 *)v6)),
                       _mm_shuffle_ps((__m128)*(unsigned int *)&v6[48], (__m128)*(unsigned int *)&v6[48], 0)));
            v232 = _mm_mul_ps(
                     _mm_shuffle_ps(*(__m128 *)v6, *(__m128 *)v6, 255),
                     _mm_sub_ps(
                       _mm_mul_ps(
                         _mm_add_ps(
                           _mm_shuffle_ps(v229, v229, 255),
                           _mm_mul_ps(
                             _mm_shuffle_ps((__m128)*(unsigned int *)&v6[40], (__m128)*(unsigned int *)&v6[40], 0),
                             temp.m_intregratePositionFactor.m_real)),
                         v230),
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v231, v231, 85), _mm_shuffle_ps(v231, v231, 0)),
                         _mm_shuffle_ps(v231, v231, 170))));
            v233 = _mm_rcp_ps(v232);
            v292 = v232;
            v234 = _mm_shuffle_ps((__m128)*(unsigned int *)&v6[32], (__m128)*(unsigned int *)&v6[32], 0);
            v235 = _mm_shuffle_ps((__m128)*(unsigned int *)&v6[36], (__m128)*(unsigned int *)&v6[36], 0);
            v236 = _mm_cmpltps(v232, v235);
            v237 = _mm_cmpltps(v234, v232);
            v298 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v233, v232)), v233), v234);
            v294 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v233, v232)), v233), v235);
            LODWORD(temps[1].m_impulseApplied) = *(unsigned __int128 *)&_mm_andnot_ps(
                                                                          v237,
                                                                          _mm_or_ps(
                                                                            _mm_and_ps(v236, v294),
                                                                            _mm_andnot_ps(v236, query.m_quad))) | v237.m128_i32[0] & v298.m128_i32[0];
            v238 = _mm_cmpltps(v292, v234);
            v292 = _mm_max_ps(v235, _mm_or_ps(_mm_and_ps(v238, v292), _mm_andnot_ps(v238, v234)));
            v6 += 64;
            v239 = COERCE_FLOAT(
                     _mm_shuffle_ps(
                       (__m128)LODWORD(temps->m_impulseApplied),
                       (__m128)LODWORD(temps->m_impulseApplied),
                       0))
                 + v292.m128_f32[0];
            v240 = _mm_mul_ps(_mm_mul_ps(v292, mB->m_invMasses.m_quad), *(__m128 *)&v6[-48]);
            v13->m_angularVel.m_quad = _mm_add_ps(
                                         _mm_mul_ps(_mm_mul_ps(v292, v13->m_invMasses.m_quad), *(__m128 *)&v6[-64]),
                                         v13->m_angularVel.m_quad);
            mB->m_angularVel.m_quad = _mm_add_ps(v240, mB->m_angularVel.m_quad);
            temps->m_impulseApplied = v239;
            temps += (unsigned __int8)hkpJacobianSchema::s_schemaNumSolverElemTemps[*(_BYTE *)&v6[-64]];
          }
          while ( *v6 == 15 );
          continue;
        case 0x10u:
          hkpAtomSolverFunctions::solveStableBallSocket<hkpVelocityAccumulator,hkpSolverInfo,hkSolverStepTemp>(
            v8,
            &temp,
            (hkpStableBallSocketSchema *)v6,
            v13,
            mB,
            temps);
          v6 += 64;
          temps += 3;
          continue;
        case 0x12u:
          hkpAtomSolverFunctions::solveStableStiffSpring<hkpVelocityAccumulator,hkpSolverInfo,hkSolverStepTemp,hkpStableStiffSpringSchema>(
            v8,
            &temp,
            (hkpStableStiffSpringSchema *)v6,
            v13,
            mB,
            temps);
          v6 += 48;
          ++temps;
          continue;
        case 0x14u:
        case 0x15u:
          do
          {
            v15 = *(__m128 *)v6;
            v16 = *(__m128 *)&v6[16];
            v17 = *(__m128 *)&v6[32];
            v6 += 48;
            v18 = _mm_add_ps(
                    _mm_mul_ps(v15, _mm_sub_ps(v13->m_linearVel.m_quad, mB->m_linearVel.m_quad)),
                    _mm_add_ps(_mm_mul_ps(v17, mB->m_angularVel.m_quad), _mm_mul_ps(v16, v13->m_angularVel.m_quad)));
            v19 = _mm_max_ps(
                    _mm_sub_ps(
                      (__m128)0i64,
                      _mm_shuffle_ps(
                        (__m128)LODWORD(temps->m_impulseApplied),
                        (__m128)LODWORD(temps->m_impulseApplied),
                        0)),
                    _mm_mul_ps(
                      _mm_shuffle_ps(v16, v16, 255),
                      _mm_sub_ps(
                        _mm_shuffle_ps(v15, v15, 255),
                        _mm_add_ps(
                          _mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)),
                          _mm_shuffle_ps(v18, v18, 170)))));
            v20 = _mm_mul_ps(v13->m_invMasses.m_quad, v19);
            v21 = _mm_mul_ps(mB->m_invMasses.m_quad, v19);
            v13->m_linearVel.m_quad = _mm_add_ps(
                                        _mm_mul_ps(_mm_shuffle_ps(v20, v20, 255), v15),
                                        v13->m_linearVel.m_quad);
            mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, _mm_mul_ps(_mm_shuffle_ps(v21, v21, 255), v15));
            v22 = _mm_mul_ps(v21, *(__m128 *)&v6[-16]);
            v23 = COERCE_FLOAT(
                    _mm_shuffle_ps(
                      (__m128)LODWORD(temps->m_impulseApplied),
                      (__m128)LODWORD(temps->m_impulseApplied),
                      0))
                + v19.m128_f32[0];
            v13->m_angularVel.m_quad = _mm_add_ps(_mm_mul_ps(v20, *(__m128 *)&v6[-32]), v13->m_angularVel.m_quad);
            mB->m_angularVel.m_quad = _mm_add_ps(mB->m_angularVel.m_quad, v22);
            temps->m_impulseApplied = v23;
            temps += (unsigned __int8)hkpJacobianSchema::s_schemaNumSolverElemTemps[*(_BYTE *)&v6[-48]];
          }
          while ( *v6 == 20 );
          continue;
        case 0x16u:
        case 0x17u:
          do
          {
            v24 = *(__m128 *)v6;
            v25 = *(__m128 *)&v6[16];
            v26 = *(__m128 *)&v6[32];
            v6 += 48;
            v27 = _mm_add_ps(
                    _mm_mul_ps(v24, _mm_sub_ps(v13->m_linearVel.m_quad, mB->m_linearVel.m_quad)),
                    _mm_add_ps(_mm_mul_ps(v26, mB->m_angularVel.m_quad), _mm_mul_ps(v25, v13->m_angularVel.m_quad)));
            v28 = _mm_shuffle_ps((__m128)LODWORD(temps->m_impulseApplied), (__m128)LODWORD(temps->m_impulseApplied), 0);
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
            v30 = _mm_mul_ps(v13->m_invMasses.m_quad, v29);
            v31 = _mm_mul_ps(mB->m_invMasses.m_quad, v29);
            v13->m_linearVel.m_quad = _mm_add_ps(
                                        _mm_mul_ps(_mm_shuffle_ps(v30, v30, 255), v24),
                                        v13->m_linearVel.m_quad);
            mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, _mm_mul_ps(_mm_shuffle_ps(v31, v31, 255), v24));
            v32 = _mm_mul_ps(v31, *(__m128 *)&v6[-16]);
            v28.m128_i32[0] = (unsigned __int128)_mm_shuffle_ps(
                                                   (__m128)LODWORD(temps->m_impulseApplied),
                                                   (__m128)LODWORD(temps->m_impulseApplied),
                                                   0);
            v13->m_angularVel.m_quad = _mm_add_ps(_mm_mul_ps(v30, *(__m128 *)&v6[-32]), v13->m_angularVel.m_quad);
            mB->m_angularVel.m_quad = _mm_add_ps(v32, mB->m_angularVel.m_quad);
            temps->m_impulseApplied = v29.m128_f32[0] + v28.m128_f32[0];
            temps += (unsigned __int8)hkpJacobianSchema::s_schemaNumSolverElemTemps[*(_BYTE *)&v6[-48]];
          }
          while ( *v6 == 22 );
          continue;
        case 0x18u:
        case 0x19u:
          v33 = mB->m_angularVel.m_quad;
          v34 = _mm_sub_ps(v13->m_linearVel.m_quad, mB->m_linearVel.m_quad);
          v35 = *(__m128 *)&v6[48];
          v36 = _mm_add_ps(
                  _mm_mul_ps(*(__m128 *)v6, v34),
                  _mm_add_ps(
                    _mm_mul_ps(*(__m128 *)&v6[32], v33),
                    _mm_mul_ps(*(__m128 *)&v6[16], v13->m_angularVel.m_quad)));
          v37 = _mm_sub_ps(
                  _mm_shuffle_ps(*(__m128 *)v6, *(__m128 *)v6, 255),
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v36, v36, 85), _mm_shuffle_ps(v36, v36, 0)),
                    _mm_shuffle_ps(v36, v36, 170)));
          v38 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(v33, *(__m128 *)&v6[80]),
                    _mm_mul_ps(*(__m128 *)&v6[64], v13->m_angularVel.m_quad)),
                  _mm_mul_ps(v35, v34));
          v39 = _mm_sub_ps(
                  _mm_shuffle_ps(v35, v35, 255),
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v38, v38, 85), _mm_shuffle_ps(v38, v38, 0)),
                    _mm_shuffle_ps(v38, v38, 170)));
          v40 = _mm_shuffle_ps((__m128)*(unsigned int *)&v6[96], (__m128)*(unsigned int *)&v6[96], 0);
          v41 = _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v6[32], *(__m128 *)&v6[32], 255), v37),
                  _mm_mul_ps(v40, v39));
          v42 = _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v6[80], *(__m128 *)&v6[80], 255), v39),
                  _mm_mul_ps(v40, v37));
          v43 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 80);
          v44 = _mm_xor_ps(v43, (__m128)*(unsigned __int64 *)&temps->m_impulseApplied);
          v299 = v44;
          v45 = _mm_shuffle_ps(v44, v44, 0);
          LODWORD(v46) = (unsigned __int128)_mm_shuffle_ps(v44, v44, 85);
          if ( v41.m128_f32[0] <= v45.m128_f32[0] )
          {
            v57 = _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v6[64], *(__m128 *)&v6[64], 255), v39);
            if ( v57.m128_f32[0] > v46 )
            {
              v64 = _mm_mul_ps(v13->m_invMasses.m_quad, v57);
              v65 = _mm_mul_ps(mB->m_invMasses.m_quad, v57);
              v66 = _mm_mul_ps(_mm_shuffle_ps(v65, v65, 255), *(__m128 *)&v6[48]);
              v13->m_linearVel.m_quad = _mm_add_ps(
                                          v13->m_linearVel.m_quad,
                                          _mm_mul_ps(_mm_shuffle_ps(v64, v64, 255), *(__m128 *)&v6[48]));
              mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, v66);
              v67 = _mm_mul_ps(v65, *(__m128 *)&v6[80]);
              LODWORD(v68) = (unsigned __int128)_mm_shuffle_ps(
                                                  (__m128)LODWORD(temps[1].m_impulseApplied),
                                                  (__m128)LODWORD(temps[1].m_impulseApplied),
                                                  0);
              v13->m_angularVel.m_quad = _mm_add_ps(_mm_mul_ps(v64, *(__m128 *)&v6[64]), v13->m_angularVel.m_quad);
              mB->m_angularVel.m_quad = _mm_add_ps(v67, mB->m_angularVel.m_quad);
              temps[1].m_impulseApplied = v68 + v57.m128_f32[0];
              goto LABEL_21;
            }
LABEL_19:
            v58 = _mm_max_ps(v45, _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v6[16], *(__m128 *)&v6[16], 255), v37));
            v59 = _mm_mul_ps(v13->m_invMasses.m_quad, v58);
            v60 = _mm_mul_ps(mB->m_invMasses.m_quad, v58);
            v61 = _mm_mul_ps(_mm_shuffle_ps(v60, v60, 255), *(__m128 *)v6);
            v13->m_linearVel.m_quad = _mm_add_ps(
                                        v13->m_linearVel.m_quad,
                                        _mm_mul_ps(_mm_shuffle_ps(v59, v59, 255), *(__m128 *)v6));
            mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, v61);
            v62 = _mm_mul_ps(v60, *(__m128 *)&v6[32]);
            v63 = COERCE_FLOAT(
                    _mm_shuffle_ps(
                      (__m128)LODWORD(temps->m_impulseApplied),
                      (__m128)LODWORD(temps->m_impulseApplied),
                      0))
                + v58.m128_f32[0];
            v13->m_angularVel.m_quad = _mm_add_ps(_mm_mul_ps(v59, *(__m128 *)&v6[16]), v13->m_angularVel.m_quad);
            mB->m_angularVel.m_quad = _mm_add_ps(mB->m_angularVel.m_quad, v62);
            temps->m_impulseApplied = v63;
            goto LABEL_21;
          }
          if ( v42.m128_f32[0] <= v46 )
            goto LABEL_19;
          v47 = _mm_mul_ps(v41, mB->m_invMasses.m_quad);
          v48 = _mm_mul_ps(v41, v13->m_invMasses.m_quad);
          v49 = _mm_mul_ps(_mm_shuffle_ps(v47, v47, 255), *(__m128 *)v6);
          v13->m_linearVel.m_quad = _mm_add_ps(
                                      v13->m_linearVel.m_quad,
                                      _mm_mul_ps(_mm_shuffle_ps(v48, v48, 255), *(__m128 *)v6));
          mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, v49);
          v50 = _mm_mul_ps(v47, *(__m128 *)&v6[32]);
          LODWORD(v51) = (unsigned __int128)_mm_shuffle_ps(
                                              (__m128)LODWORD(temps->m_impulseApplied),
                                              (__m128)LODWORD(temps->m_impulseApplied),
                                              0);
          v13->m_angularVel.m_quad = _mm_add_ps(v13->m_angularVel.m_quad, _mm_mul_ps(v48, *(__m128 *)&v6[16]));
          mB->m_angularVel.m_quad = _mm_add_ps(v50, mB->m_angularVel.m_quad);
          temps->m_impulseApplied = v41.m128_f32[0] + v51;
          v52 = _mm_mul_ps(v42, v13->m_invMasses.m_quad);
          v53 = _mm_mul_ps(v42, mB->m_invMasses.m_quad);
          v54 = _mm_mul_ps(_mm_shuffle_ps(v53, v53, 255), *(__m128 *)&v6[48]);
          v13->m_linearVel.m_quad = _mm_add_ps(
                                      v13->m_linearVel.m_quad,
                                      _mm_mul_ps(_mm_shuffle_ps(v52, v52, 255), *(__m128 *)&v6[48]));
          mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, v54);
          v55 = _mm_mul_ps(v53, *(__m128 *)&v6[80]);
          LODWORD(v56) = (unsigned __int128)_mm_shuffle_ps(
                                              (__m128)LODWORD(temps[1].m_impulseApplied),
                                              (__m128)LODWORD(temps[1].m_impulseApplied),
                                              0);
          v13->m_angularVel.m_quad = _mm_add_ps(_mm_mul_ps(v52, *(__m128 *)&v6[64]), v13->m_angularVel.m_quad);
          mB->m_angularVel.m_quad = _mm_add_ps(v55, mB->m_angularVel.m_quad);
          temps[1].m_impulseApplied = v42.m128_f32[0] + v56;
LABEL_21:
          v6 += 112;
          temps += 2;
          if ( *v6 == 24 )
          {
            v69 = mB->m_angularVel.m_quad;
            v70 = _mm_sub_ps(v13->m_linearVel.m_quad, mB->m_linearVel.m_quad);
            v71 = _mm_add_ps(
                    _mm_mul_ps(*(__m128 *)v6, v70),
                    _mm_add_ps(
                      _mm_mul_ps(*(__m128 *)&v6[32], v69),
                      _mm_mul_ps(*(__m128 *)&v6[16], v13->m_angularVel.m_quad)));
            v72 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v71, v71, 85), _mm_shuffle_ps(v71, v71, 0)),
                    _mm_shuffle_ps(v71, v71, 170));
            v73 = *(__m128 *)&v6[48];
            v74 = _mm_sub_ps(_mm_shuffle_ps(*(__m128 *)v6, *(__m128 *)v6, 255), v72);
            v75 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(v69, *(__m128 *)&v6[80]),
                      _mm_mul_ps(*(__m128 *)&v6[64], v13->m_angularVel.m_quad)),
                    _mm_mul_ps(v73, v70));
            v76 = _mm_sub_ps(
                    _mm_shuffle_ps(v73, v73, 255),
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v75, v75, 85), _mm_shuffle_ps(v75, v75, 0)),
                      _mm_shuffle_ps(v75, v75, 170)));
            v77 = _mm_shuffle_ps((__m128)*(unsigned int *)&v6[96], (__m128)*(unsigned int *)&v6[96], 0);
            v78 = _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v6[32], *(__m128 *)&v6[32], 255), v74),
                    _mm_mul_ps(v77, v76));
            v79 = _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v6[80], *(__m128 *)&v6[80], 255), v76),
                    _mm_mul_ps(v77, v74));
            v80 = _mm_xor_ps(v43, (__m128)*(unsigned __int64 *)&temps->m_impulseApplied);
            v301 = v80;
            v81 = _mm_shuffle_ps(v80, v80, 0);
            LODWORD(v82) = (unsigned __int128)_mm_shuffle_ps(v80, v80, 85);
            if ( v78.m128_f32[0] <= v81.m128_f32[0] )
            {
              v93 = _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v6[64], *(__m128 *)&v6[64], 255), v76);
              if ( v93.m128_f32[0] > v82 )
              {
                v100 = _mm_mul_ps(mB->m_invMasses.m_quad, v93);
                v101 = _mm_mul_ps(v13->m_invMasses.m_quad, v93);
                v102 = _mm_mul_ps(_mm_shuffle_ps(v100, v100, 255), *(__m128 *)&v6[48]);
                v13->m_linearVel.m_quad = _mm_add_ps(
                                            v13->m_linearVel.m_quad,
                                            _mm_mul_ps(_mm_shuffle_ps(v101, v101, 255), *(__m128 *)&v6[48]));
                mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, v102);
                v103 = _mm_mul_ps(v100, *(__m128 *)&v6[80]);
                v104 = v93.m128_f32[0]
                     + COERCE_FLOAT(
                         _mm_shuffle_ps(
                           (__m128)LODWORD(temps[1].m_impulseApplied),
                           (__m128)LODWORD(temps[1].m_impulseApplied),
                           0));
                v13->m_angularVel.m_quad = _mm_add_ps(v13->m_angularVel.m_quad, _mm_mul_ps(v101, *(__m128 *)&v6[64]));
                mB->m_angularVel.m_quad = _mm_add_ps(v103, mB->m_angularVel.m_quad);
                temps[1].m_impulseApplied = v104;
                goto LABEL_28;
              }
LABEL_26:
              v94 = _mm_max_ps(v81, _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v6[16], *(__m128 *)&v6[16], 255), v74));
              v95 = _mm_mul_ps(v13->m_invMasses.m_quad, v94);
              v96 = _mm_mul_ps(mB->m_invMasses.m_quad, v94);
              v97 = _mm_mul_ps(_mm_shuffle_ps(v96, v96, 255), *(__m128 *)v6);
              v13->m_linearVel.m_quad = _mm_add_ps(
                                          v13->m_linearVel.m_quad,
                                          _mm_mul_ps(_mm_shuffle_ps(v95, v95, 255), *(__m128 *)v6));
              mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, v97);
              v98 = _mm_mul_ps(v96, *(__m128 *)&v6[32]);
              LODWORD(v99) = (unsigned __int128)_mm_shuffle_ps(
                                                  (__m128)LODWORD(temps->m_impulseApplied),
                                                  (__m128)LODWORD(temps->m_impulseApplied),
                                                  0);
              v13->m_angularVel.m_quad = _mm_add_ps(_mm_mul_ps(v95, *(__m128 *)&v6[16]), v13->m_angularVel.m_quad);
              mB->m_angularVel.m_quad = _mm_add_ps(v98, mB->m_angularVel.m_quad);
              temps->m_impulseApplied = v94.m128_f32[0] + v99;
              goto LABEL_28;
            }
            if ( v79.m128_f32[0] <= v82 )
              goto LABEL_26;
            v83 = _mm_mul_ps(v13->m_invMasses.m_quad, v78);
            v84 = _mm_mul_ps(mB->m_invMasses.m_quad, v78);
            v85 = _mm_mul_ps(_mm_shuffle_ps(v84, v84, 255), *(__m128 *)v6);
            v13->m_linearVel.m_quad = _mm_add_ps(
                                        v13->m_linearVel.m_quad,
                                        _mm_mul_ps(_mm_shuffle_ps(v83, v83, 255), *(__m128 *)v6));
            mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, v85);
            v86 = _mm_mul_ps(v84, *(__m128 *)&v6[32]);
            LODWORD(v87) = (unsigned __int128)_mm_shuffle_ps(
                                                (__m128)LODWORD(temps->m_impulseApplied),
                                                (__m128)LODWORD(temps->m_impulseApplied),
                                                0);
            v13->m_angularVel.m_quad = _mm_add_ps(_mm_mul_ps(v83, *(__m128 *)&v6[16]), v13->m_angularVel.m_quad);
            mB->m_angularVel.m_quad = _mm_add_ps(mB->m_angularVel.m_quad, v86);
            temps->m_impulseApplied = v87 + v78.m128_f32[0];
            v88 = _mm_mul_ps(mB->m_invMasses.m_quad, v79);
            v89 = _mm_mul_ps(v13->m_invMasses.m_quad, v79);
            v90 = _mm_mul_ps(_mm_shuffle_ps(v88, v88, 255), *(__m128 *)&v6[48]);
            v13->m_linearVel.m_quad = _mm_add_ps(
                                        v13->m_linearVel.m_quad,
                                        _mm_mul_ps(_mm_shuffle_ps(v89, v89, 255), *(__m128 *)&v6[48]));
            mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, v90);
            v91 = _mm_mul_ps(v88, *(__m128 *)&v6[80]);
            v92 = COERCE_FLOAT(
                    _mm_shuffle_ps(
                      (__m128)LODWORD(temps[1].m_impulseApplied),
                      (__m128)LODWORD(temps[1].m_impulseApplied),
                      0))
                + v79.m128_f32[0];
            v13->m_angularVel.m_quad = _mm_add_ps(v13->m_angularVel.m_quad, _mm_mul_ps(v89, *(__m128 *)&v6[64]));
            mB->m_angularVel.m_quad = _mm_add_ps(v91, mB->m_angularVel.m_quad);
            temps[1].m_impulseApplied = v92;
LABEL_28:
            v6 += 112;
            temps += 2;
            if ( *v6 == 27 )
            {
LABEL_29:
              v105 = v13->m_angularVel.m_quad;
              v106 = mB->m_angularVel.m_quad;
              v107 = _mm_shuffle_ps((__m128)*(unsigned int *)&v6[132], (__m128)*(unsigned int *)&v6[132], 0);
              v108 = _mm_sub_ps(v13->m_linearVel.m_quad, mB->m_linearVel.m_quad);
              v109 = *(__m128 *)&v6[48];
              v110 = _mm_add_ps(
                       _mm_mul_ps(*(__m128 *)v6, v108),
                       _mm_add_ps(_mm_mul_ps(*(__m128 *)&v6[32], v106), _mm_mul_ps(*(__m128 *)&v6[16], v105)));
              v111 = _mm_sub_ps(
                       _mm_shuffle_ps(*(__m128 *)v6, *(__m128 *)v6, 255),
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v110, v110, 85), _mm_shuffle_ps(v110, v110, 0)),
                         _mm_shuffle_ps(v110, v110, 170)));
              v112 = _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(mB->m_angularVel.m_quad, *(__m128 *)&v6[80]),
                         _mm_mul_ps(*(__m128 *)&v6[64], v105)),
                       _mm_mul_ps(v109, v108));
              v113 = _mm_sub_ps(
                       _mm_shuffle_ps(v109, v109, 255),
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v112, v112, 85), _mm_shuffle_ps(v112, v112, 0)),
                         _mm_shuffle_ps(v112, v112, 170)));
              v114 = _mm_add_ps(_mm_mul_ps(*(__m128 *)&v6[96], v105), _mm_mul_ps(*(__m128 *)&v6[112], v106));
              v115 = _mm_mul_ps(
                       _mm_shuffle_ps(*(__m128 *)&v6[96], *(__m128 *)&v6[96], 255),
                       _mm_sub_ps(
                         _mm_shuffle_ps(*(__m128 *)&v6[112], *(__m128 *)&v6[112], 255),
                         _mm_add_ps(
                           _mm_add_ps(_mm_shuffle_ps(v114, v114, 85), _mm_shuffle_ps(v114, v114, 0)),
                           _mm_shuffle_ps(v114, v114, 170))));
              v116 = _mm_shuffle_ps((__m128)*(unsigned int *)&v6[128], (__m128)*(unsigned int *)&v6[128], 0);
              v117 = _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v6[80], *(__m128 *)&v6[80], 255), v113),
                       _mm_mul_ps(v116, v111));
              v118 = _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v6[32], *(__m128 *)&v6[32], 255), v111),
                       _mm_mul_ps(v116, v113));
              v119 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v117, v117), _mm_mul_ps(v118, v118)), _mm_mul_ps(v115, v115));
              v120 = _mm_cmpltps(_mm_mul_ps(v107, v107), v119);
              v303 = v119;
              v121 = _mm_rsqrt_ps(v119);
              v122 = _mm_mul_ps(
                       _mm_mul_ps(
                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v121, v119), v121)),
                         _mm_mul_ps(*(__m128 *)_xmm, v121)),
                       v107);
              v123 = _mm_or_ps(_mm_and_ps(_mm_mul_ps(v122, v118), v120), _mm_andnot_ps(v120, v118));
              v124 = _mm_or_ps(_mm_and_ps(_mm_mul_ps(v122, v117), v120), _mm_andnot_ps(v120, v117));
              LODWORD(temps[3].m_impulseApplied) = v122.m128_i32[0] & v120.m128_i32[0] | *(unsigned __int128 *)&_mm_andnot_ps(v120, query.m_quad);
              v125 = _mm_mul_ps(
                       _mm_or_ps(_mm_and_ps(_mm_mul_ps(v122, v115), v120), _mm_andnot_ps(v120, v115)),
                       _mm_shuffle_ps((__m128)*(unsigned int *)&v6[136], (__m128)*(unsigned int *)&v6[136], 0));
              v126 = _mm_mul_ps(v13->m_invMasses.m_quad, v123);
              v127 = _mm_mul_ps(mB->m_invMasses.m_quad, v123);
              v128 = _mm_mul_ps(_mm_shuffle_ps(v127, v127, 255), *(__m128 *)v6);
              v13->m_linearVel.m_quad = _mm_add_ps(
                                          v13->m_linearVel.m_quad,
                                          _mm_mul_ps(_mm_shuffle_ps(v126, v126, 255), *(__m128 *)v6));
              mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, v128);
              v129 = _mm_mul_ps(v127, *(__m128 *)&v6[32]);
              LODWORD(v130) = (unsigned __int128)_mm_shuffle_ps(
                                                   (__m128)LODWORD(temps->m_impulseApplied),
                                                   (__m128)LODWORD(temps->m_impulseApplied),
                                                   0);
              v13->m_angularVel.m_quad = _mm_add_ps(_mm_mul_ps(v126, *(__m128 *)&v6[16]), v13->m_angularVel.m_quad);
              mB->m_angularVel.m_quad = _mm_add_ps(v129, mB->m_angularVel.m_quad);
              temps->m_impulseApplied = v130 + v123.m128_f32[0];
              v131 = _mm_mul_ps(v13->m_invMasses.m_quad, v124);
              v132 = _mm_mul_ps(mB->m_invMasses.m_quad, v124);
              v133 = _mm_mul_ps(_mm_shuffle_ps(v132, v132, 255), *(__m128 *)&v6[48]);
              v13->m_linearVel.m_quad = _mm_add_ps(
                                          v13->m_linearVel.m_quad,
                                          _mm_mul_ps(_mm_shuffle_ps(v131, v131, 255), *(__m128 *)&v6[48]));
              mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, v133);
              v134 = _mm_mul_ps(v131, *(__m128 *)&v6[64]);
              v135 = (__m128)LODWORD(temps[1].m_impulseApplied);
              v136 = _mm_mul_ps(v132, *(__m128 *)&v6[80]);
              v6 += 160;
              temps += 4;
              v13->m_angularVel.m_quad = _mm_add_ps(v13->m_angularVel.m_quad, v134);
              mB->m_angularVel.m_quad = _mm_add_ps(mB->m_angularVel.m_quad, v136);
              temps[-3].m_impulseApplied = COERCE_FLOAT(_mm_shuffle_ps(v135, v135, 0)) + v124.m128_f32[0];
              v137 = COERCE_FLOAT(
                       _mm_shuffle_ps(
                         (__m128)LODWORD(temps[-2].m_impulseApplied),
                         (__m128)LODWORD(temps[-2].m_impulseApplied),
                         0))
                   + v125.m128_f32[0];
              v138 = _mm_mul_ps(_mm_mul_ps(mB->m_invMasses.m_quad, v125), *(__m128 *)&v6[-48]);
              v13->m_angularVel.m_quad = _mm_add_ps(
                                           _mm_mul_ps(_mm_mul_ps(v13->m_invMasses.m_quad, v125), *(__m128 *)&v6[-64]),
                                           v13->m_angularVel.m_quad);
              mB->m_angularVel.m_quad = _mm_add_ps(v138, mB->m_angularVel.m_quad);
              temps[-2].m_impulseApplied = v137;
              if ( *v6 == 1 )
              {
LABEL_7:
                v13 = &accumulators[(unsigned __int64)*(unsigned __int16 *)&v6[4]];
                mB = &accumulators[(unsigned __int64)*(unsigned __int16 *)&v6[6]];
LABEL_8:
                v6 += 32;
              }
            }
          }
          break;
        case 0x1Au:
          goto LABEL_53;
        case 0x1Bu:
          goto LABEL_29;
        case 0x1Cu:
          hkpAtomSolverFunctions::solve2dRollingFriction<hkpVelocityAccumulator,hkpSolverInfo,hkSolverStepTemp>(
            v8,
            &temp,
            (hkpJacobian2dRollingFrictionSchema *)v6,
            v13,
            mB,
            temps);
          v178 = (__int64)*v6;
          v6 += 96;
          temps += *(unsigned __int8 *)(v178 + 5403477904i64);
          v179 = (int)*v6;
          if ( v179 == 27 )
            goto LABEL_29;
          if ( v179 != 26 )
            continue;
LABEL_53:
          v180 = mB->m_angularVel.m_quad;
          v181 = _mm_sub_ps(v13->m_linearVel.m_quad, mB->m_linearVel.m_quad);
          v182 = _mm_shuffle_ps((__m128)*(unsigned int *)&v6[100], (__m128)*(unsigned int *)&v6[100], 0);
          v183 = _mm_add_ps(
                   _mm_mul_ps(*(__m128 *)v6, v181),
                   _mm_add_ps(
                     _mm_mul_ps(*(__m128 *)&v6[32], v180),
                     _mm_mul_ps(*(__m128 *)&v6[16], v13->m_angularVel.m_quad)));
          v184 = _mm_sub_ps(
                   _mm_shuffle_ps(*(__m128 *)v6, *(__m128 *)v6, 255),
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v183, v183, 85), _mm_shuffle_ps(v183, v183, 0)),
                     _mm_shuffle_ps(v183, v183, 170)));
          v185 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(v180, *(__m128 *)&v6[80]),
                     _mm_mul_ps(*(__m128 *)&v6[64], v13->m_angularVel.m_quad)),
                   _mm_mul_ps(*(__m128 *)&v6[48], v181));
          v186 = _mm_sub_ps(
                   _mm_shuffle_ps(*(__m128 *)&v6[48], *(__m128 *)&v6[48], 255),
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v185, v185, 85), _mm_shuffle_ps(v185, v185, 0)),
                     _mm_shuffle_ps(v185, v185, 170)));
          v187 = _mm_shuffle_ps((__m128)*(unsigned int *)&v6[96], (__m128)*(unsigned int *)&v6[96], 0);
          v188 = _mm_add_ps(
                   _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v6[32], *(__m128 *)&v6[32], 255), v184),
                   _mm_mul_ps(v187, v186));
          v189 = _mm_add_ps(
                   _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v6[80], *(__m128 *)&v6[80], 255), v186),
                   _mm_mul_ps(v187, v184));
          v190 = _mm_add_ps(_mm_mul_ps(v189, v189), _mm_mul_ps(v188, v188));
          v191 = _mm_rsqrt_ps(v190);
          v192 = _mm_cmpltps(_mm_mul_ps(v182, v182), v190);
          v293 = v190;
          v193 = _mm_mul_ps(
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v191, v190), v191)),
                     _mm_mul_ps(*(__m128 *)_xmm, v191)),
                   v182);
          v194 = _mm_or_ps(_mm_and_ps(_mm_mul_ps(v193, v188), v192), _mm_andnot_ps(v192, v188));
          v6 += 112;
          temps += 3;
          LODWORD(temps[-1].m_impulseApplied) = v193.m128_i32[0] & v192.m128_i32[0] | *(unsigned __int128 *)&_mm_andnot_ps(v192, query.m_quad);
          v195 = _mm_or_ps(_mm_and_ps(_mm_mul_ps(v193, v189), v192), _mm_andnot_ps(v192, v189));
          v196 = _mm_mul_ps(v13->m_invMasses.m_quad, v194);
          v197 = _mm_mul_ps(mB->m_invMasses.m_quad, v194);
          v198 = _mm_mul_ps(_mm_shuffle_ps(v197, v197, 255), *(__m128 *)&v6[-112]);
          v13->m_linearVel.m_quad = _mm_add_ps(
                                      v13->m_linearVel.m_quad,
                                      _mm_mul_ps(_mm_shuffle_ps(v196, v196, 255), *(__m128 *)&v6[-112]));
          mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, v198);
          v199 = _mm_mul_ps(v197, *(__m128 *)&v6[-80]);
          v191.m128_i32[0] = (unsigned __int128)_mm_shuffle_ps(
                                                  (__m128)LODWORD(temps[-3].m_impulseApplied),
                                                  (__m128)LODWORD(temps[-3].m_impulseApplied),
                                                  0);
          v13->m_angularVel.m_quad = _mm_add_ps(_mm_mul_ps(v196, *(__m128 *)&v6[-96]), v13->m_angularVel.m_quad);
          mB->m_angularVel.m_quad = _mm_add_ps(mB->m_angularVel.m_quad, v199);
          temps[-3].m_impulseApplied = v191.m128_f32[0] + v194.m128_f32[0];
          v200 = _mm_mul_ps(mB->m_invMasses.m_quad, v195);
          v201 = _mm_mul_ps(v13->m_invMasses.m_quad, v195);
          v202 = _mm_mul_ps(_mm_shuffle_ps(v200, v200, 255), *(__m128 *)&v6[-64]);
          v13->m_linearVel.m_quad = _mm_add_ps(
                                      v13->m_linearVel.m_quad,
                                      _mm_mul_ps(_mm_shuffle_ps(v201, v201, 255), *(__m128 *)&v6[-64]));
          mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, v202);
          v203 = _mm_mul_ps(v200, *(__m128 *)&v6[-32]);
          v191.m128_i32[0] = (unsigned __int128)_mm_shuffle_ps(
                                                  (__m128)LODWORD(temps[-2].m_impulseApplied),
                                                  (__m128)LODWORD(temps[-2].m_impulseApplied),
                                                  0);
          v13->m_angularVel.m_quad = _mm_add_ps(v13->m_angularVel.m_quad, _mm_mul_ps(v201, *(__m128 *)&v6[-48]));
          mB->m_angularVel.m_quad = _mm_add_ps(v203, mB->m_angularVel.m_quad);
          temps[-2].m_impulseApplied = v191.m128_f32[0] + v195.m128_f32[0];
          if ( *v6 == 1 )
            goto LABEL_7;
          continue;
        case 0x1Du:
          v13->m_invMasses = *(hkVector4f *)v6;
          mB->m_invMasses = *(hkVector4f *)&v6[16];
          v13->m_invMasses.m_quad.m128_i8[0] = 0;
          goto LABEL_8;
        case 0x1Eu:
          v273 = 0i64;
          v273.m128_f32[0] = (float)temp.m_currentStep.m_storage;
          v274 = (__m128 *)((unsigned __int64)v13 ^ -*(_DWORD *)&v6[16] & ((unsigned __int64)v13 ^ (unsigned __int64)mB));
          v275 = _mm_mul_ps(
                   *(__m128 *)v6,
                   _mm_mul_ps(
                     _mm_shuffle_ps(v273, v273, 0),
                     _mm_shuffle_ps(v8->m_integrateVelocityFactor.m_quad, v8->m_integrateVelocityFactor.m_quad, 0)));
          v274[1] = _mm_add_ps(v275, _mm_add_ps(*(__m128 *)v6, v274[1]));
          v274[4] = _mm_add_ps(v275, v274[4]);
          goto LABEL_8;
        case 0x1Fu:
          v276 = v13->m_angularVel.m_quad;
          v6 += 96;
          v277 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v13->m_angularVel.m_quad, v276, 85), *(__m128 *)&v6[-80]),
                     _mm_mul_ps(_mm_shuffle_ps(v276, v276, 0), *(__m128 *)&v6[-96])),
                   _mm_mul_ps(_mm_shuffle_ps(v276, v276, 170), *(__m128 *)&v6[-64]));
          v278 = mB->m_angularVel.m_quad;
          v279 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(mB->m_angularVel.m_quad, v278, 85), *(__m128 *)&v6[-32]),
                     _mm_mul_ps(_mm_shuffle_ps(v278, v278, 0), *(__m128 *)&v6[-48])),
                   _mm_mul_ps(_mm_shuffle_ps(v278, v278, 170), *(__m128 *)&v6[-16]));
          v280 = v13->m_scratch1.m_quad;
          v281 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v13->m_scratch1.m_quad, v280, 85), *(__m128 *)&v6[-80]),
                     _mm_mul_ps(_mm_shuffle_ps(v280, v280, 0), *(__m128 *)&v6[-96])),
                   _mm_mul_ps(_mm_shuffle_ps(v280, v280, 170), *(__m128 *)&v6[-64]));
          v282 = mB->m_scratch1.m_quad;
          v283 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(mB->m_scratch1.m_quad, v282, 85), *(__m128 *)&v6[-32]),
                     _mm_mul_ps(_mm_shuffle_ps(v282, v282, 0), *(__m128 *)&v6[-48])),
                   _mm_mul_ps(_mm_shuffle_ps(v282, v282, 170), *(__m128 *)&v6[-16]));
          v13->m_linearVel.m_quad = _mm_add_ps(v13->m_linearVel.m_quad, v277);
          v13->m_scratch0.m_quad = _mm_add_ps(v281, v13->m_scratch0.m_quad);
          mB->m_linearVel.m_quad = _mm_add_ps(v279, mB->m_linearVel.m_quad);
          mB->m_scratch0.m_quad = _mm_add_ps(v283, mB->m_scratch0.m_quad);
          continue;
        case 0x20u:
          hkpAtomSolverFunctions::solveStableAngularConstraint3d<hkpVelocityAccumulator,hkpSolverInfo,hkSolverStepTemp>(
            v8,
            &temp,
            (hkpStableAngularSchema3d *)v6,
            v13,
            mB,
            temps);
          v6 += 48;
          temps += 3;
          continue;
        case 0x22u:
          hkpAtomSolverFunctions::solveDeformableLinConstraintStub<hkpVelocityAccumulator,hkpSolverInfo,hkSolverStepTemp>(
            v8,
            &temp,
            (hkpDeformableLinSchema *)v6,
            v13,
            mB,
            temps);
          v6 += 128;
          temps += 3;
          continue;
        case 0x23u:
          hkpAtomSolverFunctions::solveDeformableAngConstraintStub<hkpVelocityAccumulator,hkpSolverInfo,hkSolverStepTemp>(
            v8,
            &temp,
            (hkpDeformableAngSchema *)v6,
            v13,
            mB,
            temps);
          v6 += 128;
          temps += 3;
          continue;
        case 0x27u:
          hkSolver_solveStiffSpringChain(v8, &temp, accumulators, (hkpJacobianStiffSpringChainSchema *)v6, temps);
          temps += *(unsigned __int16 *)&v6[4];
          v6 += *(unsigned int *)&v6[8];
          continue;
        case 0x28u:
          hkSolver_solveBallAndSocketChain(v8, &temp, accumulators, (hkpJacobianBallSocketChainSchema *)v6, temps);
          goto LABEL_91;
        case 0x29u:
          hkSolver_solveStabilizedBallAndSocketChain(
            v8,
            &temp,
            accumulators,
            (hkpJacobianStabilizedBallSocketChainSchema *)v6,
            temps);
LABEL_91:
          v284 = 3 * *(unsigned __int16 *)&v6[4];
          v6 += *(unsigned int *)&v6[8];
          temps += v284;
          continue;
        case 0x2Au:
          hkSolver_solvePoweredChain(v8, &temp, accumulators, (hkpJacobianPoweredChainSchema *)v6, temps);
          temps += 6 * *(unsigned __int16 *)&v6[4];
          v6 += *(unsigned int *)&v6[16];
          continue;
        case 0x2Bu:
          v139 = *(_QWORD *)&v6[104];
          v140 = *(_QWORD *)(v139 + 40);
          if ( *(_BYTE *)(v140 + 36) )
          {
            v141 = 0.0;
            *(_DWORD *)v140 = 0;
          }
          else
          {
            v141 = *(float *)(v140 + 20);
            *(float *)v140 = *(float *)v140
                           + (float)(v8->m_invNumMicroSteps
                                   * (float)(v8->m_deltaTime * (float)(*(float *)(v139 + 12) * v141)));
          }
          v142 = mB->m_angularVel.m_quad;
          v143 = *(float *)&v6[44];
          v144 = *(float *)&v6[96];
          v145 = _mm_sub_ps(v13->m_linearVel.m_quad, mB->m_linearVel.m_quad);
          v146 = _mm_add_ps(
                   _mm_mul_ps(*(__m128 *)v6, v145),
                   _mm_add_ps(
                     _mm_mul_ps(*(__m128 *)&v6[32], v142),
                     _mm_mul_ps(*(__m128 *)&v6[16], v13->m_angularVel.m_quad)));
          LODWORD(v147) = COERCE_UNSIGNED_INT(
                            COERCE_FLOAT(_mm_shuffle_ps(*(__m128 *)v6, *(__m128 *)v6, 255))
                          - (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v146, v146, 85))
                                          + COERCE_FLOAT(_mm_shuffle_ps(v146, v146, 0)))
                                  + COERCE_FLOAT(_mm_shuffle_ps(v146, v146, 170)))) ^ _xmm[0];
          v148 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(v142, *(__m128 *)&v6[80]),
                     _mm_mul_ps(*(__m128 *)&v6[64], v13->m_angularVel.m_quad)),
                   _mm_mul_ps(*(__m128 *)&v6[48], v145));
          LODWORD(v149) = COERCE_UNSIGNED_INT(
                            COERCE_FLOAT(_mm_shuffle_ps(*(__m128 *)&v6[48], *(__m128 *)&v6[48], 255))
                          - (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v148, v148, 85))
                                          + COERCE_FLOAT(_mm_shuffle_ps(v148, v148, 0)))
                                  + COERCE_FLOAT(_mm_shuffle_ps(v148, v148, 170)))) ^ _xmm[0];
          if ( v141 == 0.0 )
          {
            v150 = (float)(*(float *)v140 * *(float *)(v139 + 16)) - v147;
            v151 = v144 * v149;
            v152 = (float)(v150 * v143) - (float)(v144 * v149);
          }
          else
          {
            v153 = (float)(*(float *)v140 * *(float *)(v139 + 16)) - v147;
            v151 = v144 * v149;
            v152 = (float)((float)(*(float *)(v140 + 24) * (float)(v153 - (float)((float)(v144 * v149) / v143))) * v143)
                 / (float)((float)(v143 * *(float *)(v139 + 16)) + *(float *)(v140 + 24));
          }
          v285 = v152;
          v154 = COERCE_FLOAT(COERCE_UNSIGNED_INT(*(float *)&v6[92] * v149) ^ _xmm[0])
               - (float)((float)((float)(v152 + v151) / v143) * v144);
          v286 = v154;
          v289 = (float)(v154 * v154) + (float)(v152 * v152);
          v155 = *(float *)&v6[100];
          v156 = fsqrt(v289);
          if ( v156 <= v155 )
          {
            *(float *)(v139 + 20) = v152 + *(float *)(v139 + 20);
            *(float *)(v139 + 24) = v286 + *(float *)(v139 + 24);
          }
          else
          {
            v157 = v155 / v156;
            *(float *)(v139 + 20) = (float)(v157 * v152) + *(float *)(v139 + 20);
            *(float *)(v139 + 28) = (float)(v152 - (float)(v157 * v152)) + *(float *)(v139 + 28);
            v285 = v157 * v152;
            v158 = v157 * v286;
            *(float *)(v139 + 24) = v158 + *(float *)(v139 + 24);
            *(float *)(v139 + 32) = (float)(v286 - v158) + *(float *)(v139 + 32);
            v286 = v158;
          }
          v159.m_quad = (__m128)mB->m_invMasses;
          if ( v156 != 0.0 )
          {
            v160 = *(float *)(v140 + 28) * v156;
            if ( v160 > *(float *)(v140 + 32) )
              v160 = *(float *)(v140 + 32);
            v288 = v160 / v156;
            mB->m_invMasses.m_quad = _mm_mul_ps(
                                       mB->m_invMasses.m_quad,
                                       _mm_shuffle_ps(
                                         (__m128)COERCE_UNSIGNED_INT(v160 / v156),
                                         (__m128)COERCE_UNSIGNED_INT(v160 / v156),
                                         0));
          }
          v161 = _mm_shuffle_ps((__m128)LODWORD(v285), (__m128)LODWORD(v285), 0);
          v162 = _mm_shuffle_ps((__m128)LODWORD(v286), (__m128)LODWORD(v286), 0);
          v163 = _mm_mul_ps(v13->m_invMasses.m_quad, v161);
          v164 = _mm_mul_ps(mB->m_invMasses.m_quad, v161);
          v165 = _mm_mul_ps(_mm_shuffle_ps(v164, v164, 255), *(__m128 *)v6);
          v13->m_linearVel.m_quad = _mm_add_ps(
                                      v13->m_linearVel.m_quad,
                                      _mm_mul_ps(_mm_shuffle_ps(v163, v163, 255), *(__m128 *)v6));
          mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, v165);
          v166 = _mm_mul_ps(v164, *(__m128 *)&v6[32]);
          LODWORD(v167) = (unsigned __int128)_mm_shuffle_ps(
                                               (__m128)LODWORD(temps->m_impulseApplied),
                                               (__m128)LODWORD(temps->m_impulseApplied),
                                               0);
          v13->m_angularVel.m_quad = _mm_add_ps(_mm_mul_ps(v163, *(__m128 *)&v6[16]), v13->m_angularVel.m_quad);
          mB->m_angularVel.m_quad = _mm_add_ps(v166, mB->m_angularVel.m_quad);
          temps->m_impulseApplied = v167 + v161.m128_f32[0];
          v168 = _mm_mul_ps(v13->m_invMasses.m_quad, v162);
          v169 = _mm_mul_ps(mB->m_invMasses.m_quad, v162);
          v170 = _mm_mul_ps(_mm_shuffle_ps(v169, v169, 255), *(__m128 *)&v6[48]);
          v13->m_linearVel.m_quad = _mm_add_ps(
                                      v13->m_linearVel.m_quad,
                                      _mm_mul_ps(_mm_shuffle_ps(v168, v168, 255), *(__m128 *)&v6[48]));
          mB->m_linearVel.m_quad = _mm_sub_ps(mB->m_linearVel.m_quad, v170);
          v171 = _mm_mul_ps(v169, *(__m128 *)&v6[80]);
          v170.m128_f32[0] = COERCE_FLOAT(
                               _mm_shuffle_ps(
                                 (__m128)LODWORD(temps[1].m_impulseApplied),
                                 (__m128)LODWORD(temps[1].m_impulseApplied),
                                 0))
                           + v162.m128_f32[0];
          v13->m_angularVel.m_quad = _mm_add_ps(v13->m_angularVel.m_quad, _mm_mul_ps(v168, *(__m128 *)&v6[64]));
          mB->m_angularVel.m_quad = _mm_add_ps(mB->m_angularVel.m_quad, v171);
          temps[1].m_impulseApplied = v170.m128_f32[0];
          *(float *)v140 = *(float *)v140 - (float)(v285 * v141);
          mB->m_invMasses = (hkVector4f)v159.m_quad;
          v172 = *(_QWORD *)(v139 + 40);
          v173 = *(_DWORD *)(v172 + 12) + 1;
          *(_DWORD *)(v172 + 12) = v173;
          v174 = *(_QWORD *)(v139 + 40);
          if ( v173 == *(_DWORD *)(v174 + 40) * v8->m_numMicroSteps )
          {
            v175 = *(float *)v140 - *(float *)(v140 + 4);
            v176 = *(_DWORD *)(v174 + 16) + 1;
            *(_DWORD *)(v174 + 16) = v176;
            if ( v176 == v8->m_numSteps )
            {
              *(float *)v140 = v175;
              *(_DWORD *)(v140 + 4) = 0;
              *(_DWORD *)(v140 + 16) = 0;
            }
            else
            {
              v177 = (float)(v175 * v8->m_integrateVelocityFactor.m_quad.m128_f32[0]) + *(float *)(v140 + 4);
              *(float *)(v140 + 4) = v177;
              *(float *)v140 = v175 + v177;
            }
            *(_DWORD *)(v140 + 12) = 0;
          }
          v6 += 112;
          temps += 2;
          if ( *v6 != 1 )
            continue;
          goto LABEL_7;
        default:
          __debugbreak();
          return 1;
      }
    }
  }
  return 1;
}                       + v162.m128_f32[0];
          v13->m_angularVel.m_quad = _mm_add_ps(v13->m_angularVel.m_quad, _mm_mul_ps(v168, *(__m128 *)&v6[64]));
          mB->m_angularVel.m_quad = _mm_add_ps(mB->m_angularVel.m_quad, v171);
          temps[1].m_impulseApplied = v170.m128_f32[0];
          *(float *)v140 = *(float *)v140 - (float)(v285 * v141);
          mB->m_invMasses = (hkVector4f)v159.m_quad;
          v172 = *(_QWORD *)(v139 + 40);
          v173 = *(_DWORD *)(v172 + 12) + 1;
          *(_DWORD *)(v172 + 12) = v173;
          v174 = *(_QWORD *)(v139 + 40);
          if ( v173 == *(_DWORD *)(v174 + 40) * v8->m_numMicroSteps )
          {
            v175 = *(float *)v140 - *(float *)(v140 + 4);
            v176 = *(_DWORD *)(v174 + 16) + 1;
            *(_DWORD *)(v174 + 16) = v176;
            if ( v176 == v8->m_numSteps )
            {
              *(float *)v140 = v175;
              *(_DWORD *)(v140 + 4) = 0;
              *(_DWORD *)(v140 + 16) = 0;
            }
            else
            {
              v177 = (float)(v175 * v8->m_integrateVelocityFactor.m_quad.m128_f32[0]) + *(float *)(v140 + 4);
              *(float *)(v140 + 4) = v177;
              *(float *)v140 = v175 + v177;
            }
            *(_DWORD *)(v140 + 12) = 0;
          }
          v6 += 112;
          temps += 2;
          if ( *v6

// File Line: 1859
// RVA: 0xDDCF10
signed __int64 __fastcall hkSolveIntegrateVelocitiesByTheSteps(hkpSolverInfo *info, int currentSolverStep, hkpVelocityAccumulator *accumulators, hkpVelocityAccumulator *accumulatorsEnd, hkBool *outSolveFinished)
{
  __m128 v5; // xmm1
  hkVector4f v6; // xmm0
  int v7; // eax
  hkSimdFloat32 sumVelFactor; // [rsp+30h] [rbp-28h]
  hkVector4f velocityField; // [rsp+40h] [rbp-18h]

  v5 = (__m128)LODWORD(info->m_invNumSteps);
  _mm_store_si128((__m128i *)&velocityField, (__m128i)info->m_globalAccelerationPerSubStep.m_quad);
  v6.m_quad = (__m128)info->m_invIntegrateVelocityFactor;
  outSolveFinished->m_bool = 0;
  v7 = info->m_numSteps - 1;
  sumVelFactor.m_real = _mm_mul_ps(_mm_shuffle_ps(v6.m_quad, v6.m_quad, 0), _mm_shuffle_ps(v5, v5, 0));
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

