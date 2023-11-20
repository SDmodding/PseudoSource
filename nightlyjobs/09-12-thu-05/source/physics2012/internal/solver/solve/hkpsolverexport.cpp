// File Line: 111
// RVA: 0xDE5CF0
void __fastcall hkSolverExport::exportImpulsesAndRhs(hkpSolverInfo *info, hkpSolverElemTemp *solverInputs, hkpJacobianSchema *schemas, hkpVelocityAccumulator *accums)
{
  __m128 v4; // xmm2
  hkpVelocityAccumulator *v5; // rsi
  hkpSolverElemTemp *v6; // r11
  hkpJacobianSchema *v7; // r9
  hkpJacobianSchema *v8; // rbx
  __m128 v9; // xmm8
  float v10; // xmm7_4
  __m128 v11; // xmm11
  __m128 v12; // xmm6
  __int64 v13; // r10
  int v14; // er12
  int v15; // er14
  signed __int64 v16; // r13
  char *v17; // rdx
  __m128i v18; // xmm6
  __int64 *v19; // r8
  float v20; // er15
  __m128 v21; // xmm10
  __int64 v22; // rdi
  float v23; // xmm3_4
  __int64 v24; // rax
  unsigned __int64 v25; // r8
  hkpJacobianSchema i; // al
  __m128 *v27; // rax
  __m128 v28; // xmm0
  __m128 v29; // xmm2
  float v30; // xmm6_4
  __m128 v31; // xmm2
  float v32; // xmm1_4
  float v33; // xmm3_4
  __m128 v34; // xmm1
  __int64 v35; // r10
  __m128 *v36; // rcx
  signed __int64 v37; // rax
  bool v38; // zf
  __int64 v39; // rax
  __m128 v40; // xmm2
  float v41; // xmm3_4
  float v42; // xmm1_4
  float v43; // xmm1_4
  __m128 v44; // xmm4
  __m128 *v45; // rcx
  __m128 v46; // xmm3
  float v47; // xmm4_4
  float v48; // xmm4_4
  __m128 *v49; // rcx
  __m128 v50; // xmm2
  float v51; // xmm1_4
  float v52; // xmm3_4
  __m128 *v53; // rax
  __m128 v54; // xmm4
  __m128 *v55; // rcx
  __m128 *v56; // rax
  __m128 v57; // xmm1
  __m128 v58; // xmm3
  __m128 *v59; // rcx
  __m128 *v60; // rax
  __m128 v61; // xmm2
  __m128 *v62; // rax
  __m128 v63; // xmm0
  __m128 v64; // xmm3
  __m128 *v65; // rdx
  __m128 v66; // xmm3
  __int64 v67; // xmm1_8
  __m128 v68; // xmm0
  __m128 v69; // xmm3
  __m128 v70; // xmm2
  bool v71; // cf
  __int64 v72; // rax
  __m128 v73; // xmm0
  __m128 v74; // xmm1
  __m128 v75; // xmm1
  __m128 v76; // xmm0
  __m128 v77; // xmm1
  __m128 v78; // xmm1
  float v79; // xmm0_4
  __m128 v80; // xmm9
  __m128 *v81; // rax
  __m128 v82; // xmm1
  __m128 v83; // xmm7
  __m128 v84; // xmm5
  float *v85; // rcx
  __m128 v86; // xmm4
  float v87; // xmm8_4
  __m128 v88; // xmm5
  __m128 v89; // xmm1
  __m128 v90; // xmm3
  __m128 v91; // xmm4
  __m128 *v92; // rax
  __m128 v93; // xmm2
  float v94; // xmm9_4
  __m128 v95; // xmm1
  float v96; // xmm7_4
  __m128 v97; // xmm5
  __m128 v98; // xmm0
  __m128 v99; // xmm2
  __m128 v100; // xmm3
  unsigned __int64 v101; // rax
  __m128 v102; // xmm2
  __m128 v103; // xmm2
  __m128 v104; // xmm2
  __m128 v105; // xmm2
  __m128 v106; // xmm7
  __int64 v107; // rcx
  __m128 *v108; // rax
  __m128 v109; // xmm7
  __m128 v110; // xmm3
  __m128 v111; // xmm4
  __m128 v112; // xmm0
  __m128 v113; // xmm6
  __m128 v114; // xmm5
  __m128 *v115; // rcx
  __m128 *v116; // rax
  __int128 v117; // xmm1
  __int128 v118; // xmm1
  __m128 *v119; // rcx
  int v120; // xmm0_4
  char v121; // al
  __m128 v122; // xmm10
  int v123; // eax
  __int128 v124; // xmm0
  __m128 v125; // xmm12
  __m128 v126; // xmm2
  __m128 v127; // xmm7
  __int128 v128; // xmm1
  __m128 v129; // xmm14
  __m128 v130; // xmm6
  __m128 v131; // xmm2
  __m128 v132; // xmm15
  __m128 v133; // xmm9
  __int128 v134; // xmm1
  __m128 v135; // xmm0
  __m128 v136; // xmm8
  __m128 v137; // xmm4
  __m128 v138; // xmm12
  __m128 v139; // xmm15
  __m128 v140; // xmm1
  __m128 *v141; // r8
  hkpJacobianSchema *v142; // rdx
  signed int v143; // er9
  __int64 v144; // rcx
  __int64 v145; // rax
  __m128 v146; // xmm3
  __m128 v147; // xmm2
  __m128 *v148; // r9
  __int64 v149; // r8
  signed int v150; // edi
  hkpJacobianSchema *v151; // rcx
  __int64 v152; // rax
  signed __int64 v153; // r14
  signed __int64 v154; // rdx
  __int64 v155; // rcx
  __m128 v156; // xmm3
  __m128 v157; // xmm2
  __m128 v158; // xmm2
  signed int v159; // edx
  signed __int64 v160; // rax
  __m128 v161; // xmm0
  signed int v162; // er9
  __int64 v163; // rdi
  __int64 v164; // r8
  __int64 v165; // rdx
  signed __int64 v166; // rax
  int v167; // er9
  __m128 *v168; // r14
  __int64 v169; // rcx
  __m128 *v170; // r15
  unsigned __int64 v171; // rax
  signed __int64 v172; // rdx
  int v173; // ecx
  hkpJacobianSchema *v174; // r8
  signed __int64 v175; // r9
  float v176; // xmm7_4
  float *v177; // r12
  __m128 *v178; // r13
  __int64 v179; // rax
  signed int v180; // esi
  __int64 v181; // r8
  float *v182; // rdi
  __m128 *v183; // r11
  signed __int64 v184; // rax
  float v185; // xmm3_4
  __m128 v186; // xmm2
  __m128 v187; // xmm1
  float v188; // xmm5_4
  float v189; // xmm5_4
  __m128 v190; // xmm6
  signed __int64 v191; // r9
  float v192; // xmm1_4
  float v193; // xmm3_4
  __m128 v194; // xmm1
  float v195; // xmm2_4
  float v196; // xmm0_4
  __m128 v197; // xmm1
  float v198; // xmm2_4
  float v199; // xmm0_4
  hkpSolverElemTemp *v200; // [rsp+0h] [rbp-C0h]
  char *v201; // [rsp+8h] [rbp-B8h]
  __int64 *v202; // [rsp+10h] [rbp-B0h]
  __int64 v203; // [rsp+18h] [rbp-A8h]
  int v204; // [rsp+20h] [rbp-A0h]
  int v205; // [rsp+24h] [rbp-9Ch]
  int v206; // [rsp+30h] [rbp-90h]
  __m128 v207; // [rsp+40h] [rbp-80h]
  signed __int64 v208; // [rsp+50h] [rbp-70h]
  signed __int64 v209; // [rsp+58h] [rbp-68h]
  signed __int64 v210; // [rsp+60h] [rbp-60h]
  __int64 v211; // [rsp+68h] [rbp-58h]
  __int64 v212; // [rsp+70h] [rbp-50h]
  int v213; // [rsp+78h] [rbp-48h]
  __m128 v214; // [rsp+80h] [rbp-40h]
  __m128 v215; // [rsp+90h] [rbp-30h]
  __int128 v216; // [rsp+A0h] [rbp-20h]
  __m128 v217; // [rsp+B0h] [rbp-10h]
  __m128 v218; // [rsp+C0h] [rbp+0h]
  __int128 v219; // [rsp+D0h] [rbp+10h]
  __int128 v220; // [rsp+E0h] [rbp+20h]
  char v221; // [rsp+F0h] [rbp+30h]
  char v222; // [rsp+F1h] [rbp+31h]
  int v223; // [rsp+F4h] [rbp+34h]
  int v224; // [rsp+F8h] [rbp+38h]
  __m128 v225; // [rsp+100h] [rbp+40h]
  __m128 v226; // [rsp+110h] [rbp+50h]
  __int128 v227; // [rsp+120h] [rbp+60h]
  __m128 v228; // [rsp+130h] [rbp+70h]
  __m128 v229; // [rsp+140h] [rbp+80h]
  __int128 v230; // [rsp+150h] [rbp+90h]
  __int128 v231; // [rsp+160h] [rbp+A0h]
  __m128 v232; // [rsp+170h] [rbp+B0h]
  __m128 v233; // [rsp+180h] [rbp+C0h]
  int v234; // [rsp+280h] [rbp+1C0h]
  float v235; // [rsp+288h] [rbp+1C8h]
  hkpJacobianSchema *v236; // [rsp+290h] [rbp+1D0h]
  hkpVelocityAccumulator *v237; // [rsp+298h] [rbp+1D8h]

  v4 = 0i64;
  v5 = accums;
  v6 = solverInputs;
  v7 = schemas;
  v200 = solverInputs;
  v8 = schemas;
  v9 = _mm_shuffle_ps((__m128)LODWORD(info->m_deltaTime), (__m128)LODWORD(info->m_deltaTime), 0);
  v10 = COERCE_FLOAT(_mm_shuffle_ps((__m128)LODWORD(info->m_dampDivTau), (__m128)LODWORD(info->m_dampDivTau), 0))
      * v9.m128_f32[0];
  v11 = _mm_mul_ps(
          _mm_shuffle_ps((__m128)LODWORD(info->m_dampDivFrictionTau), (__m128)LODWORD(info->m_dampDivFrictionTau), 0),
          v9);
  v12 = 0i64;
  v12.m128_f32[0] = (float)info->m_numSteps;
  v13 = 0i64;
  v14 = 0;
  v204 = 0;
  v15 = 0;
  v234 = 0;
  v16 = 0i64;
  v207 = v9;
  *(float *)&v210 = v10;
  v233 = v11;
  v17 = 0i64;
  v201 = 0i64;
  v18 = (__m128i)_mm_shuffle_ps(v12, v12, 0);
  v206 = v18.m128i_i32[0];
  v19 = 0i64;
  v202 = 0i64;
  v20 = 0.0;
  v235 = 0.0;
  v21 = _mm_mul_ps((__m128)v18, v9);
  v22 = 0i64;
  v203 = 0i64;
  v232 = v21;
LABEL_2:
  v23 = FLOAT_0_99000001;
  while ( 1 )
  {
    v24 = (__int64)*v8;
    switch ( 0x40000000 )
    {
      case 0:
        *(_DWORD *)v7 = v15;
        return;
      case 1:
        v13 = *(_QWORD *)&v8[8];
        v14 = (unsigned __int8)v8[1];
        v16 = *(_QWORD *)&v8[16];
        v25 = (unsigned __int64)*(unsigned __int16 *)&v8[6] << 7;
        v17 = &v5[(unsigned __int64)*(unsigned __int16 *)&v8[4]].m_type.m_storage;
        v8 += 32;
        v19 = (__int64 *)(&v5->m_type.m_storage + v25);
        v204 = v14;
        v201 = v17;
        v202 = v19;
        if ( !v13 )
        {
          for ( i = *v8; *(_BYTE *)v8 > 4u; i = *v8 )
          {
            if ( *(unsigned __int8 *)&i >= 0x26u )
              break;
            v6 += (unsigned __int8)hkpJacobianSchema::s_schemaNumSolverElemTemps[*(unsigned __int8 *)&i];
            v200 = v6;
            v8 += (unsigned __int8)hkpJacobianSchema::s_schemaSize[*(unsigned __int8 *)&i];
          }
        }
        continue;
      case 2:
        v8 += *(_QWORD *)&v8[8];
        continue;
      case 3:
        v13 += *(_BYTE *)&v8[4] * (signed int)(signed __int16)v14;
        v8 += 16;
        continue;
      case 5:
      case 20:
      case 21:
        v36 = (__m128 *)v8;
        v8 += 48;
        goto $commonCodeForHk1Lin2AngJacobians;
      case 6:
        v36 = (__m128 *)v8;
        v8 += 48;
        v235 = v6->m_impulseApplied;
        if ( COERCE_FLOAT((unsigned int)(2 * LODWORD(v235)) >> 1) > (float)(v36[2].m128_f32[3] * v23) )
          LODWORD(v20) = 1;
        v38 = *v8 == 6;
        v235 = v20;
        if ( !v38 && v20 != 0.0 )
        {
          v39 = v22;
          ++v15;
          ++v22;
          v39 *= 32i64;
          v20 = 0.0;
          v234 = v15;
          *(_DWORD *)&v7[v39 + 16] = 0;
          *(_QWORD *)&v7[v39 + 24] = v16;
          *(_QWORD *)&v7[v39 + 32] = 0i64;
          v235 = 0.0;
          v203 = v22;
        }
        goto $commonCodeForHk1Lin2AngJacobians;
      case 7:
      case 8:
        v36 = (__m128 *)v8;
        v8 += 64;
        goto $commonCodeForHk1Lin2AngJacobians;
      case 9:
        v49 = (__m128 *)v8;
        v8 += 64;
        v50 = _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(*((__m128 *)v19 + 5), v49[2]), _mm_mul_ps(*((__m128 *)v17 + 5), v49[1])),
                _mm_mul_ps(_mm_sub_ps(*((__m128 *)v17 + 4), *((__m128 *)v19 + 4)), *v49));
        v51 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v50, v50, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v50, v50, 0)))
            + COERCE_FLOAT(_mm_shuffle_ps(v50, v50, 170));
        v4 = 0i64;
        v52 = (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(*v49, *v49, 255)) * v10) - (float)(v51 * v21.m128_f32[0]))
            * COERCE_FLOAT(_mm_shuffle_ps((__m128)LODWORD(v6[1].m_impulseApplied), (__m128)LODWORD(v6[1].m_impulseApplied), 0));
        *(hkpSolverElemTemp *)v13 = LODWORD(v6->m_impulseApplied);
        *(float *)(v13 + 4) = v52;
        v13 += 2 * v14;
        v6 += 2;
        v200 = v6;
        goto LABEL_2;
      case 10:
        v44 = (__m128)*(unsigned int *)&v8[56];
        v45 = (__m128 *)v8;
        v8 += 80;
        v46 = _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(*((__m128 *)v19 + 5), v45[2]), _mm_mul_ps(*((__m128 *)v17 + 5), v45[1])),
                _mm_mul_ps(_mm_sub_ps(*((__m128 *)v17 + 4), *((__m128 *)v19 + 4)), *v45));
        v47 = (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v44, v44, 0)) * *(float *)v18.m128i_i32)
                            + COERCE_FLOAT(_mm_shuffle_ps(*v45, *v45, 255)))
                    * v9.m128_f32[0])
            - (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v46, v46, 85))
                                    + COERCE_FLOAT(_mm_shuffle_ps(v46, v46, 0)))
                            + COERCE_FLOAT(_mm_shuffle_ps(v46, v46, 170)))
                    * v21.m128_f32[0]);
        goto LABEL_25;
      case 11:
        v62 = (__m128 *)v8;
        v8 += 64;
        v41 = COERCE_FLOAT(_mm_shuffle_ps(*v62, *v62, 255)) * v10;
        v40 = _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(*((__m128 *)v19 + 5), v62[3]), _mm_mul_ps(*((__m128 *)v17 + 5), v62[2])),
                _mm_sub_ps(_mm_mul_ps(*((__m128 *)v17 + 4), *v62), _mm_mul_ps(*((__m128 *)v19 + 4), v62[1])));
        *(hkpSolverElemTemp *)v13 = LODWORD(v6->m_impulseApplied);
        v42 = COERCE_FLOAT(_mm_shuffle_ps(v40, v40, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v40, v40, 0));
        goto LABEL_23;
      case 12:
        v53 = (__m128 *)v8;
        v8 += 32;
        goto $commonCodeForHk2AngJacobians;
      case 13:
        v53 = (__m128 *)v8;
        v8 += 48;
$commonCodeForHk2AngJacobians:
        v40 = _mm_add_ps(_mm_mul_ps(*((__m128 *)v17 + 5), *v53), _mm_mul_ps(*((__m128 *)v19 + 5), v53[1]));
        v41 = COERCE_FLOAT(_mm_shuffle_ps(v53[1], v53[1], 255)) * v9.m128_f32[0];
        goto LABEL_22;
      case 14:
        v58 = *(__m128 *)&v8[16];
        v59 = (__m128 *)&v8[16];
        v60 = (__m128 *)v8;
        v8 += 48;
        v61 = _mm_add_ps(_mm_mul_ps(*((__m128 *)v17 + 5), *v60), _mm_mul_ps(*((__m128 *)v19 + 5), *v59));
        v58.m128_f32[0] = (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v58, v58, 255)) * v10)
                                - (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v61, v61, 85))
                                                        + COERCE_FLOAT(_mm_shuffle_ps(v61, v61, 0)))
                                                + COERCE_FLOAT(_mm_shuffle_ps(v61, v61, 170)))
                                        * v21.m128_f32[0]))
                        * COERCE_FLOAT(
                            _mm_shuffle_ps(
                              (__m128)LODWORD(v6[1].m_impulseApplied),
                              (__m128)LODWORD(v6[1].m_impulseApplied),
                              0));
        *(hkpSolverElemTemp *)v13 = LODWORD(v6->m_impulseApplied);
        *(_DWORD *)(v13 + 4) = v58.m128_i32[0];
        goto LABEL_26;
      case 15:
        v54 = (__m128)*(unsigned int *)&v8[40];
        v55 = (__m128 *)&v8[16];
        v56 = (__m128 *)v8;
        v8 += 64;
        v57 = _mm_add_ps(_mm_mul_ps(*((__m128 *)v17 + 5), *v56), _mm_mul_ps(*((__m128 *)v19 + 5), *v55));
        v47 = (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v54, v54, 0)) * *(float *)v18.m128i_i32)
                            + COERCE_FLOAT(_mm_shuffle_ps(*v55, *v55, 255)))
                    * v9.m128_f32[0])
            - (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v57, v57, 85))
                                    + COERCE_FLOAT(_mm_shuffle_ps(v57, v57, 0)))
                            + COERCE_FLOAT(_mm_shuffle_ps(v57, v57, 170)))
                    * v21.m128_f32[0]);
LABEL_25:
        v48 = v47
            * COERCE_FLOAT(_mm_shuffle_ps((__m128)LODWORD(v6[1].m_impulseApplied), (__m128)LODWORD(v6[1].m_impulseApplied), 0));
        *(hkpSolverElemTemp *)v13 = LODWORD(v6->m_impulseApplied);
        *(float *)(v13 + 4) = v48;
LABEL_26:
        v4 = 0i64;
        v13 += 2 * v14;
        v6 += 2;
        v200 = v6;
        goto LABEL_2;
      case 16:
        v63 = (__m128)LODWORD(v6[2].m_impulseApplied);
        v64 = (__m128)*(unsigned __int64 *)&v6->m_impulseApplied;
        v65 = (__m128 *)v8;
        v6 += 3;
        v8 += 64;
        v200 = v6;
        v66 = (__m128)_mm_srli_si128(_mm_slli_si128((__m128i)_mm_movelh_ps(v64, v63), 4), 4);
        v67 = (unsigned __int128)_mm_shuffle_ps(v66, v66, 254);
        v68 = _mm_shuffle_ps(v66, v66, 220);
        v69 = _mm_mul_ps(v66, v66);
        *(__m128 *)v13 = v68;
        *(_QWORD *)(v13 + 16) = v67;
        v70 = *v65;
        v17 = v201;
        v13 += 3 * v14;
        *(float *)&v67 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v69, v69, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v69, v69, 0)))
                       + COERCE_FLOAT(_mm_shuffle_ps(v69, v69, 170));
        v23 = FLOAT_0_99000001;
        v70.m128_i32[0] = (unsigned __int128)_mm_shuffle_ps(v70, v70, 255);
        v71 = *(float *)&v67 < v70.m128_f32[0];
        v38 = *(float *)&v67 == v70.m128_f32[0];
        v4 = 0i64;
        if ( v71 || v38 )
          continue;
        v72 = v22;
        ++v15;
        ++v22;
        v72 *= 32i64;
        v234 = v15;
        *(_DWORD *)&v7[v72 + 16] = 0;
        *(_QWORD *)&v7[v72 + 24] = v16;
        *(_QWORD *)&v7[v72 + 32] = 0i64;
        v20 = 0.0;
        v235 = 0.0;
        v203 = v22;
        goto LABEL_2;
      case 18:
        v79 = v6->m_impulseApplied;
        ++v6;
        *(float *)v13 = v79;
        v200 = v6;
        *(_DWORD *)(v13 + 4) = aabbOut.m_quad.m128_i32[0];
        v13 += v14;
        v8 += 48;
        continue;
      case 22:
      case 23:
        v36 = (__m128 *)v8;
        v8 += 48;
        if ( (float)(v36[2].m128_f32[3] * v23) < v6->m_impulseApplied )
        {
          v5 = v237;
          ++v15;
          v37 = 32 * v22++;
          v234 = v15;
          v203 = v22;
          *(_DWORD *)&v7[v37 + 16] = 0x10000;
          *(_QWORD *)&v7[v37 + 24] = v16;
          *(_QWORD *)&v7[v37 + 32] = v13;
        }
$commonCodeForHk1Lin2AngJacobians:
        v40 = _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(*((__m128 *)v19 + 5), v36[2]), _mm_mul_ps(*((__m128 *)v17 + 5), v36[1])),
                _mm_mul_ps(_mm_sub_ps(*((__m128 *)v17 + 4), *((__m128 *)v19 + 4)), *v36));
        v41 = COERCE_FLOAT(_mm_shuffle_ps(*v36, *v36, 255)) * v10;
LABEL_22:
        v42 = COERCE_FLOAT(_mm_shuffle_ps(v40, v40, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v40, v40, 0));
        *(hkpSolverElemTemp *)v13 = LODWORD(v6->m_impulseApplied);
LABEL_23:
        v43 = v42 + COERCE_FLOAT(_mm_shuffle_ps(v40, v40, 170));
        v4 = 0i64;
        *(float *)(v13 + 4) = v41 - (float)(v43 * v21.m128_f32[0]);
        v13 += v14;
        ++v6;
        v200 = v6;
        goto LABEL_2;
      case 24:
      case 25:
        v27 = (__m128 *)v8;
        v8 += 112;
        v28 = _mm_sub_ps(*((__m128 *)v17 + 4), *((__m128 *)v19 + 4));
        v29 = _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(v27[1], *((__m128 *)v17 + 5)), _mm_mul_ps(v27[2], *((__m128 *)v19 + 5))),
                _mm_mul_ps(v28, *v27));
        v30 = (float)(COERCE_FLOAT(_mm_shuffle_ps(*v27, *v27, 255)) * v10)
            - (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v29, v29, 85))
                                    + COERCE_FLOAT(_mm_shuffle_ps(v29, v29, 0)))
                            + COERCE_FLOAT(_mm_shuffle_ps(v29, v29, 170)))
                    * v21.m128_f32[0]);
        v31 = _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(v27[4], *((__m128 *)v17 + 5)), _mm_mul_ps(v27[5], *((__m128 *)v19 + 5))),
                _mm_mul_ps(v28, v27[3]));
        v32 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v31, v31, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v31, v31, 0)))
            + COERCE_FLOAT(_mm_shuffle_ps(v31, v31, 170));
        v4 = 0i64;
        v33 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v27[3], v27[3], 255)) * v10) - (float)(v32 * v21.m128_f32[0]);
        v34 = (__m128)*(unsigned __int64 *)&v6->m_impulseApplied;
        *(_DWORD *)v13 = v34.m128_i32[0];
        *(float *)(v13 + 4) = v30;
        v18.m128i_i32[0] = v206;
        v35 = v14 + v13;
        *(_DWORD *)v35 = (unsigned __int128)_mm_shuffle_ps(v34, v34, 85);
        *(float *)(v35 + 4) = v33;
        v13 = v14 + v35;
        v6 += 2;
        v200 = v6;
        goto LABEL_2;
      case 26:
        v80 = (__m128)LODWORD(v6[2].m_impulseApplied);
        v81 = (__m128 *)v8;
        v82 = *(__m128 *)&v8[48];
        v83 = *(__m128 *)v8;
        v84 = *(__m128 *)&v8[16];
        v8 += 112;
        v6 += 3;
        v4 = 0i64;
        v85 = (float *)v81[6].m128_u64[1];
        v80.m128_i32[0] = (unsigned __int128)_mm_shuffle_ps(v80, v80, 0);
        v200 = v6;
        v86 = _mm_sub_ps(*((__m128 *)v17 + 4), *((__m128 *)v19 + 4));
        LODWORD(v87) = (unsigned __int128)_mm_shuffle_ps(v82, v82, 255);
        v88 = _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(v84, *((__m128 *)v17 + 5)), _mm_mul_ps(v81[2], *((__m128 *)v19 + 5))),
                _mm_mul_ps(v86, v83));
        v18 = (__m128i)_mm_add_ps(
                         _mm_add_ps(_mm_mul_ps(v81[4], *((__m128 *)v17 + 5)), _mm_mul_ps(v81[5], *((__m128 *)v19 + 5))),
                         _mm_mul_ps(v86, v82));
        v82.m128_f32[0] = (float)(COERCE_FLOAT(_mm_shuffle_ps((__m128)v18, (__m128)v18, 85))
                                + COERCE_FLOAT(_mm_shuffle_ps((__m128)v18, (__m128)v18, 0)))
                        + COERCE_FLOAT(_mm_shuffle_ps((__m128)v18, (__m128)v18, 170));
        v18.m128i_i32[0] = v206;
        v85[6] = (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v83, v83, 255)) * v11.m128_f32[0])
                       - (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v88, v88, 85))
                                               + COERCE_FLOAT(_mm_shuffle_ps(v88, v88, 0)))
                                       + COERCE_FLOAT(_mm_shuffle_ps(v88, v88, 170)))
                               * v21.m128_f32[0]))
               * v80.m128_f32[0];
        v10 = *(float *)&v210;
        v85[7] = (float)((float)(v87 * v11.m128_f32[0]) - (float)(v82.m128_f32[0] * v21.m128_f32[0])) * v80.m128_f32[0];
        v9 = v207;
        v89 = _mm_mul_ps(
                (__m128)*(unsigned __int64 *)&v6[-3].m_impulseApplied,
                (__m128)*(unsigned __int64 *)&v6[-3].m_impulseApplied);
        v85[4] = COERCE_FLOAT(_mm_shuffle_ps(v89, v89, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v89, v89, 0));
        goto LABEL_2;
      case 27:
        v90 = *((__m128 *)v19 + 5);
        v91 = *((__m128 *)v17 + 5);
        v92 = (__m128 *)v8;
        v93 = _mm_sub_ps(*((__m128 *)v17 + 4), *((__m128 *)v19 + 4));
        v8 += 160;
        LODWORD(v94) = (unsigned __int128)_mm_shuffle_ps(
                                            (__m128)LODWORD(v6[3].m_impulseApplied),
                                            (__m128)LODWORD(v6[3].m_impulseApplied),
                                            0);
        v95 = v92[3];
        LODWORD(v96) = (unsigned __int128)_mm_shuffle_ps(*v92, *v92, 255);
        v97 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v92[1], v91), _mm_mul_ps(v92[2], v90)), _mm_mul_ps(v93, *v92));
        v18 = (__m128i)_mm_add_ps(_mm_add_ps(_mm_mul_ps(v92[4], v91), _mm_mul_ps(v92[5], v90)), _mm_mul_ps(v93, v95));
        v98 = _mm_mul_ps(v92[6], v91);
        v99 = _mm_mul_ps(v92[7], v90);
        v100 = v92[7];
        v101 = v92[9].m128_u64[0];
        v102 = _mm_add_ps(v99, v98);
        *(float *)(v101 + 24) = (float)((float)(v96 * v11.m128_f32[0])
                                      - (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v97, v97, 85))
                                                              + COERCE_FLOAT(_mm_shuffle_ps(v97, v97, 0)))
                                                      + COERCE_FLOAT(_mm_shuffle_ps(v97, v97, 170)))
                                              * v21.m128_f32[0]))
                              * v94;
        *(float *)(v101 + 28) = (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v95, v95, 255)) * v11.m128_f32[0])
                                      - (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps((__m128)v18, (__m128)v18, 85))
                                                              + COERCE_FLOAT(_mm_shuffle_ps((__m128)v18, (__m128)v18, 0)))
                                                      + COERCE_FLOAT(_mm_shuffle_ps((__m128)v18, (__m128)v18, 170)))
                                              * v21.m128_f32[0]))
                              * v94;
        *(float *)(v101 + 20) = (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v100, v100, 255)) * v11.m128_f32[0])
                                      - (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v102, v102, 85))
                                                              + COERCE_FLOAT(_mm_shuffle_ps(v102, v102, 0)))
                                                      + COERCE_FLOAT(_mm_shuffle_ps(v102, v102, 170)))
                                              * v21.m128_f32[0]))
                              * v94;
        v103 = _mm_movelh_ps(
                 (__m128)*(unsigned __int64 *)&v6->m_impulseApplied,
                 (__m128)LODWORD(v6[2].m_impulseApplied));
        v104 = _mm_mul_ps(v103, v103);
        v9 = v207;
        v18.m128i_i32[0] = v206;
        v10 = *(float *)&v210;
        v6 += 4;
        v200 = v6;
        v95.m128_f32[0] = (float)(COERCE_FLOAT(_mm_shuffle_ps(v104, v104, 85))
                                + COERCE_FLOAT(_mm_shuffle_ps(v104, v104, 0)))
                        + COERCE_FLOAT(_mm_shuffle_ps(v104, v104, 170));
        v4 = 0i64;
        *(_DWORD *)(v101 + 16) = v95.m128_i32[0];
        goto LABEL_2;
      case 28:
        v105 = *((__m128 *)v17 + 5);
        v106 = (__m128)LODWORD(v6[2].m_impulseApplied);
        v107 = *(_QWORD *)&v8[72];
        v108 = (__m128 *)v8;
        v8 += 96;
        v6 += 3;
        v200 = v6;
        v109 = _mm_shuffle_ps(v106, v106, 0);
        v110 = _mm_add_ps(_mm_mul_ps(*((__m128 *)v19 + 5), v108[1]), _mm_mul_ps(v105, *v108));
        v111 = _mm_add_ps(_mm_mul_ps(v108[3], *((__m128 *)v19 + 5)), _mm_mul_ps(v105, v108[2]));
        v112 = _mm_mul_ps(
                 (__m128)*(unsigned __int64 *)&v6[-3].m_impulseApplied,
                 (__m128)*(unsigned __int64 *)&v6[-3].m_impulseApplied);
        v113 = _mm_unpacklo_ps(
                 _mm_add_ps(_mm_shuffle_ps(v112, v112, 85), _mm_shuffle_ps(v112, v112, 0)),
                 _mm_mul_ps(
                   _mm_sub_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v108[1], v108[1], 255), v9),
                     _mm_mul_ps(
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v110, v110, 85), _mm_shuffle_ps(v110, v110, 0)),
                         _mm_shuffle_ps(v110, v110, 170)),
                       v21)),
                   v109));
        v4 = 0i64;
        v114 = _mm_mul_ps(
                 _mm_sub_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v108[3], v108[3], 255), v9),
                   _mm_mul_ps(
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v111, v111, 85), _mm_shuffle_ps(v111, v111, 0)),
                       _mm_shuffle_ps(v111, v111, 170)),
                     v21)),
                 v109);
        v10 = *(float *)&v210;
        v18 = _mm_srai_epi32(
                (__m128i)_mm_mul_ps(
                           _mm_movelh_ps(v113, _mm_unpacklo_ps(v114, aabbOut.m_quad)),
                           (__m128)xmmword_141A71380),
                0x10u);
        v18.m128i_i64[0] = (unsigned __int128)_mm_packs_epi32(v18, v18);
        v207.m128_u64[0] = v18.m128i_i64[0];
        LOWORD(v108) = v18.m128i_i16[0];
        v18.m128i_i32[0] = v206;
        *(_WORD *)(v107 + 6) = (_WORD)v108;
        *(float *)(v107 + 8) = *(float *)((char *)v207.m128_f32 + 2);
        goto LABEL_2;
      case 29:
        v8 += 32;
        continue;
      case 30:
        v115 = (__m128 *)v8;
        v8 += 32;
        if ( v115[1].m128_i32[0] )
        {
          LOWORD(v212) = *(_WORD *)v19;
          HIDWORD(v212) = *((_DWORD *)v19 + 1);
          v116 = (__m128 *)&v212;
          v213 = *((_DWORD *)v19 + 2);
          v214 = *((__m128 *)v19 + 1);
          v215 = *((__m128 *)v19 + 2);
          v216 = *((_OWORD *)v19 + 3);
          v217 = *((__m128 *)v19 + 4);
          v218 = *((__m128 *)v19 + 5);
          v219 = *((_OWORD *)v19 + 6);
          v118 = *((_OWORD *)v19 + 7);
          v19 = &v212;
          v202 = &v212;
          v220 = v118;
        }
        else
        {
          v221 = *v17;
          v222 = v17[1];
          v223 = *((_DWORD *)v17 + 1);
          v116 = (__m128 *)&v221;
          v224 = *((_DWORD *)v17 + 2);
          v225 = *((__m128 *)v17 + 1);
          v226 = *((__m128 *)v17 + 2);
          v227 = *((_OWORD *)v17 + 3);
          v228 = *((__m128 *)v17 + 4);
          v229 = *((__m128 *)v17 + 5);
          v230 = *((_OWORD *)v17 + 6);
          v117 = *((_OWORD *)v17 + 7);
          v17 = &v221;
          v201 = &v221;
          v231 = v117;
        }
        v4 = 0i64;
        v116[1] = _mm_add_ps(v116[1], *v115);
        v116[4] = _mm_add_ps(v116[4], *v115);
        continue;
      case 31:
        v119 = (__m128 *)v8;
        v8 += 96;
        v221 = *v17;
        v222 = v17[1];
        v223 = *((_DWORD *)v17 + 1);
        v120 = *((_DWORD *)v17 + 2);
        LOBYTE(v212) = *(_BYTE *)v19;
        v121 = *((_BYTE *)v19 + 1);
        v224 = v120;
        v11 = *((__m128 *)v17 + 1);
        v225 = v11;
        v122 = *((__m128 *)v17 + 2);
        BYTE1(v212) = v121;
        v123 = *((_DWORD *)v19 + 1);
        v226 = v122;
        v124 = *((_OWORD *)v17 + 3);
        HIDWORD(v212) = v123;
        v227 = v124;
        v125 = *((__m128 *)v17 + 4);
        v228 = v125;
        v126 = *((__m128 *)v17 + 5);
        v229 = v126;
        v127 = _mm_mul_ps(_mm_shuffle_ps(v126, v126, 170), v119[2]);
        v230 = *((_OWORD *)v17 + 6);
        v128 = *((_OWORD *)v17 + 7);
        v213 = *((_DWORD *)v19 + 2);
        v17 = &v221;
        v201 = &v221;
        v129 = *((__m128 *)v19 + 1);
        v231 = v128;
        v130 = _mm_mul_ps(_mm_shuffle_ps(v126, v126, 0), *v119);
        v131 = _mm_mul_ps(_mm_shuffle_ps(v126, v126, 85), v119[1]);
        v214 = v129;
        v18 = (__m128i)_mm_add_ps(_mm_add_ps(v130, v131), v127);
        v215 = *((__m128 *)v19 + 2);
        v216 = *((_OWORD *)v19 + 3);
        v132 = *((__m128 *)v19 + 4);
        v217 = v132;
        v218 = *((__m128 *)v19 + 5);
        v133 = _mm_mul_ps(_mm_shuffle_ps(v218, v218, 170), v119[5]);
        v219 = *((_OWORD *)v19 + 6);
        v134 = *((_OWORD *)v19 + 7);
        v19 = &v212;
        v202 = &v212;
        v135 = _mm_mul_ps(_mm_shuffle_ps(v122, v122, 85), v119[1]);
        v220 = v134;
        v136 = _mm_mul_ps(_mm_shuffle_ps(v218, v218, 85), v119[4]);
        v137 = _mm_mul_ps(_mm_shuffle_ps(v218, v218, 0), v119[3]);
        v225 = _mm_add_ps(
                 v11,
                 _mm_add_ps(
                   _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v122, v122, 0), *v119), v135),
                   _mm_mul_ps(_mm_shuffle_ps(v122, v122, 170), v119[2])));
        v21 = v232;
        v10 = *(float *)&v210;
        v11.m128_i32[0] = v233.m128_i32[0];
        v138 = _mm_add_ps(v125, (__m128)v18);
        v4 = 0i64;
        v139 = _mm_add_ps(v132, _mm_add_ps(_mm_add_ps(v136, v137), v133));
        v18.m128i_i32[0] = v206;
        v9 = v207;
        v140 = _mm_mul_ps(_mm_shuffle_ps(v215, v215, 85), v119[4]);
        v228 = v138;
        v217 = v139;
        v214 = _mm_add_ps(
                 v129,
                 _mm_add_ps(
                   _mm_add_ps(v140, _mm_mul_ps(_mm_shuffle_ps(v215, v215, 0), v119[3])),
                   _mm_mul_ps(_mm_shuffle_ps(v215, v215, 170), v119[5])));
        goto LABEL_2;
      case 32:
        v73 = (__m128)LODWORD(v6[2].m_impulseApplied);
        v74 = (__m128)*(unsigned __int64 *)&v6->m_impulseApplied;
        v6 += 3;
        v200 = v6;
        v75 = (__m128)_mm_srli_si128(_mm_slli_si128((__m128i)_mm_movelh_ps(v74, v73), 4), 4);
        *(__m128 *)v13 = _mm_shuffle_ps(v75, v75, 220);
        *(_QWORD *)(v13 + 16) = (unsigned __int128)_mm_shuffle_ps(v75, v75, 254);
        v13 += 3 * v14;
        v8 += 48;
        break;
      case 34:
      case 35:
        v76 = (__m128)LODWORD(v6[2].m_impulseApplied);
        v77 = (__m128)*(unsigned __int64 *)&v6->m_impulseApplied;
        v6 += 3;
        v200 = v6;
        v78 = (__m128)_mm_srli_si128(_mm_slli_si128((__m128i)_mm_movelh_ps(v77, v76), 4), 4);
        *(__m128 *)v13 = _mm_shuffle_ps(v78, v78, 220);
        *(_QWORD *)(v13 + 16) = (unsigned __int128)_mm_shuffle_ps(v78, v78, 254);
        v13 += 3 * v14;
        v8 += 128;
        break;
      case 39:
        v141 = (__m128 *)&v8[32];
        if ( v13 )
        {
          v142 = &v8[64 * (unsigned __int64)*(unsigned __int16 *)&v8[4] + 36];
          v143 = 0;
          if ( *(_WORD *)&v8[4] > 0u )
          {
            do
            {
              v144 = *(_DWORD *)v142;
              v145 = *(unsigned int *)&v142[4];
              v146 = *v141;
              v142 += 4;
              ++v143;
              ++v6;
              v141 += 3;
              v147 = _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(*(__m128 *)((char *)&v5->m_scratch1.m_quad + v145), v141[-1]),
                         _mm_mul_ps(*(__m128 *)((char *)&v5->m_scratch1.m_quad + v144), v141[-2])),
                       _mm_mul_ps(
                         _mm_sub_ps(
                           *(__m128 *)((char *)&v5->m_scratch0.m_quad + v144),
                           *(__m128 *)((char *)&v5->m_scratch0.m_quad + v145)),
                         v146));
              *(hkpSolverElemTemp *)v13 = v6[-1];
              *(float *)(v13 + 4) = (float)(COERCE_FLOAT(_mm_shuffle_ps(v146, v146, 255)) * v9.m128_f32[0])
                                  - (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v147, v147, 85))
                                                          + COERCE_FLOAT(_mm_shuffle_ps(v147, v147, 0)))
                                                  + COERCE_FLOAT(_mm_shuffle_ps(v147, v147, 170)))
                                          * v21.m128_f32[0]);
              v13 += v14;
            }
            while ( v143 < *(unsigned __int16 *)&v8[4] );
            v23 = FLOAT_0_99000001;
            v22 = v203;
            v200 = v6;
            v4 = 0i64;
          }
          v7 = v236;
          v17 = v201;
          v19 = v202;
          v8 += *(unsigned int *)&v8[8];
        }
        else
        {
          v19 = v202;
          v6 += *(unsigned __int16 *)&v8[4];
          v8 += *(unsigned int *)&v8[8];
          v200 = v6;
        }
        break;
      case 40:
        v148 = (__m128 *)&v8[32];
        if ( v13 )
        {
          v149 = *(unsigned __int16 *)&v8[4];
          v150 = 0;
          v151 = &v8[16 * (3 * (3 * v149 + 3 * (signed int)v149) + (signed int)v149 + 1 + 2i64)];
          if ( (signed int)v149 > 0 )
          {
            do
            {
              v152 = *(_DWORD *)v151;
              v153 = (signed __int64)&v151[4];
              v154 = 3i64;
              v155 = *(unsigned int *)&v151[4];
              do
              {
                v156 = *v148;
                v157 = v148[2];
                ++v6;
                v148 += 3;
                v158 = _mm_add_ps(
                         _mm_add_ps(
                           _mm_mul_ps(v157, *(__m128 *)((char *)&v5->m_scratch1.m_quad + v155)),
                           _mm_mul_ps(*(__m128 *)((char *)&v5->m_scratch1.m_quad + v152), v148[-2])),
                         _mm_mul_ps(
                           _mm_sub_ps(
                             *(__m128 *)((char *)&v5->m_scratch0.m_quad + v152),
                             *(__m128 *)((char *)&v5->m_scratch0.m_quad + v155)),
                           v156));
                *(hkpSolverElemTemp *)v13 = v6[-1];
                *(float *)(v13 + 4) = (float)(COERCE_FLOAT(_mm_shuffle_ps(v156, v156, 255)) * v9.m128_f32[0])
                                    - (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v158, v158, 85))
                                                            + COERCE_FLOAT(_mm_shuffle_ps(v158, v158, 0)))
                                                    + COERCE_FLOAT(_mm_shuffle_ps(v158, v158, 170)))
                                            * v21.m128_f32[0]);
                v13 += v14;
                --v154;
              }
              while ( v154 );
              ++v150;
              v200 = v6;
              v151 = (hkpJacobianSchema *)v153;
            }
            while ( v150 < *(unsigned __int16 *)&v8[4] );
            v23 = FLOAT_0_99000001;
            v15 = v234;
            v4 = 0i64;
          }
          v22 = v203;
          v19 = v202;
          v17 = v201;
          v7 = v236;
          v8 += *(unsigned int *)&v8[8];
        }
        else
        {
          v7 = v236;
          v6 += 3 * *(unsigned __int16 *)&v8[4];
          v8 += *(unsigned int *)&v8[8];
          v200 = v6;
        }
        break;
      case 41:
        if ( v13 )
        {
          v159 = 0;
          if ( *(_WORD *)&v8[4] > 0u )
          {
            do
            {
              v160 = 3i64;
              do
              {
                v161 = (__m128)LODWORD(v6->m_impulseApplied);
                ++v6;
                *(_QWORD *)v13 = (unsigned __int128)_mm_shuffle_ps(_mm_unpacklo_ps(v161, v4), v161, 228);
                v13 += v14;
                --v160;
              }
              while ( v160 );
              ++v159;
              v200 = v6;
            }
            while ( v159 < *(unsigned __int16 *)&v8[4] );
          }
          v17 = v201;
          v8 += *(unsigned int *)&v8[8];
        }
        else
        {
          v6 += 3 * *(unsigned __int16 *)&v8[4];
          v8 += *(unsigned int *)&v8[8];
          v200 = v6;
        }
        break;
      case 42:
        v162 = 0;
        v163 = 0i64;
        if ( *(_WORD *)&v8[4] > 0u )
        {
          v164 = 0i64;
          do
          {
            v165 = *(unsigned __int16 *)&v8[4];
            ++v162;
            ++v163;
            v166 = v164 + 240i64 * (_DWORD)v165;
            v164 += 64i64;
            *(hkpJacobianSchema *)(v163 + *(_QWORD *)&v8[8] - 1) = v8[1028 * v165 + 68 + v166];
          }
          while ( v162 < *(unsigned __int16 *)&v8[4] );
        }
        v167 = *(unsigned __int16 *)&v8[4];
        v168 = (__m128 *)&v8[32];
        v169 = 3 * v167;
        v170 = (__m128 *)&v8[48 * v169 + 32];
        if ( v13 )
        {
          v171 = 80 * v169 + ((unsigned __int64)*(unsigned __int16 *)&v8[4] << 10);
          v172 = (signed __int64)&v8[1028 * *(unsigned __int16 *)&v8[4] + 68 + 80 * v169];
          v173 = 0;
          v174 = &v8[v171 + 64];
          v205 = 0;
          v209 = v172;
          if ( v167 > 0 )
          {
            v207.m128_i32[2] = 1069547520;
            v175 = 0i64;
            LODWORD(v176) = (unsigned __int128)_mm_shuffle_ps((__m128)0x3FC00000u, (__m128)0x3FC00000u, 0);
            v211 = 6 * v14;
            do
            {
              v177 = &v6->m_impulseApplied;
              v208 = (signed __int64)&v174[4];
              v178 = (__m128 *)(&v5->m_type.m_storage + *(_DWORD *)v174);
              v179 = (__int64)v5 + *(unsigned int *)&v174[4];
              v180 = 0;
              v181 = 0i64;
              v212 = v179;
              v182 = (float *)(v13 + 28);
              v183 = (__m128 *)v179;
              v184 = v172 + ((signed __int64)v173 << 6) + 12;
              v210 = v172 + ((signed __int64)v173 << 6) + 12;
              do
              {
                LODWORD(v185) = (unsigned __int128)_mm_shuffle_ps(*v168, *v168, 255);
                v186 = _mm_add_ps(
                         _mm_add_ps(_mm_mul_ps(v168[2], v183[5]), _mm_mul_ps(v168[1], v178[5])),
                         _mm_mul_ps(_mm_sub_ps(v178[4], v183[4]), *v168));
                *(float *)v13 = *v177;
                *(float *)(v13 + 4) = v185
                                    - (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v186, v186, 85))
                                                            + COERCE_FLOAT(_mm_shuffle_ps(v186, v186, 0)))
                                                    + COERCE_FLOAT(_mm_shuffle_ps(v186, v186, 170)))
                                            * v21.m128_f32[0]);
                v187 = _mm_add_ps(_mm_mul_ps(*v170, v178[5]), _mm_mul_ps(v170[1], v183[5]));
                v188 = (float)((float)(COERCE_FLOAT(
                                         _mm_shuffle_ps(
                                           (__m128)*(unsigned int *)(v184 + v181),
                                           (__m128)*(unsigned int *)(v184 + v181),
                                           0))
                                     * *(float *)v18.m128i_i32)
                             + COERCE_FLOAT(_mm_shuffle_ps(v170[1], v170[1], 255)))
                     * v9.m128_f32[0];
                *(v182 - 1) = v177[3];
                v189 = v188
                     - (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v187, v187, 85))
                                             + COERCE_FLOAT(_mm_shuffle_ps(v187, v187, 0)))
                                     + COERCE_FLOAT(_mm_shuffle_ps(v187, v187, 170)))
                             * v21.m128_f32[0]);
                *v182 = v189;
                v190 = _mm_shuffle_ps(*v170, *v170, 255);
                v191 = (signed __int64)&v8[1028 * *(unsigned __int16 *)&v8[4] + 240 * *(unsigned __int16 *)&v8[4] + v175];
                if ( ((*(_BYTE *)(v191 + 68) >> 2 * v180) & 3) == 3 )
                {
                  LODWORD(v192) = (unsigned __int128)_mm_rcp_ps(v190);
                  v193 = (float)(2.0 - (float)(v192 * v190.m128_f32[0])) * v192;
                  v194 = _mm_shuffle_ps(
                           (__m128)*(unsigned int *)(v191 + v181 + 84),
                           (__m128)*(unsigned int *)(v191 + v181 + 84),
                           0);
                  LODWORD(v195) = (unsigned __int128)_mm_rcp_ps(v194);
                  v189 = fmax(
                           v189,
                           (float)((float)((float)(2.0 - (float)(v195 * v194.m128_f32[0])) * v195)
                                 * (float)((float)(v193
                                                 * COERCE_FLOAT(
                                                     _mm_shuffle_ps(
                                                       (__m128)*(unsigned int *)(v191 + v181 + 76),
                                                       (__m128)*(unsigned int *)(v191 + v181 + 76),
                                                       0)))
                                         * v9.m128_f32[0]))
                         * v176);
                  *v182 = v189;
                }
                if ( ((*(_BYTE *)(v191 + 68) >> 2 * v180) & 3) == 1 )
                {
                  LODWORD(v196) = (unsigned __int128)_mm_rcp_ps(v190);
                  v197 = _mm_shuffle_ps(
                           (__m128)*(unsigned int *)(v191 + v181 + 84),
                           (__m128)*(unsigned int *)(v191 + v181 + 84),
                           0);
                  v198 = (float)((float)((float)(2.0 - (float)(v190.m128_f32[0] * v196)) * v196)
                               * COERCE_FLOAT(
                                   _mm_shuffle_ps(
                                     (__m128)*(unsigned int *)(v191 + v181 + 72),
                                     (__m128)*(unsigned int *)(v191 + v181 + 72),
                                     0)))
                       * v9.m128_f32[0];
                  LODWORD(v199) = (unsigned __int128)_mm_rcp_ps(v197);
                  *v182 = fmin(
                            v189,
                            (float)((float)((float)(2.0 - (float)(v197.m128_f32[0] * v199)) * v199) * v198) * v176);
                }
                v18.m128i_i32[0] = v206;
                v175 = v208;
                v184 = v172 + ((signed __int64)v173 << 6) + 12;
                ++v180;
                ++v177;
                v181 += 20i64;
                v182 += 2;
                v168 += 3;
                v170 += 2;
              }
              while ( v180 < 3 );
              v13 += v211;
              v174 = (hkpJacobianSchema *)v208;
              v5 = v237;
              v172 = v209;
              v173 = v205 + 1;
              v6 = v200 + 6;
              v175 = v208 + 64;
              v200 += 6;
              v205 = v173;
            }
            while ( v173 < *(unsigned __int16 *)&v8[4] );
            v10 = *(float *)&v210;
            v23 = FLOAT_0_99000001;
            v14 = v204;
            v16 = v209;
            v4 = 0i64;
          }
        }
        else
        {
          v6 += 6 * v167;
          v200 = v6;
        }
        v17 = v201;
        v19 = v202;
        v7 = v236;
        v22 = v203;
        v15 = v234;
        v20 = v235;
        v8 += *(unsigned int *)&v8[16];
        break;
      case 43:
        v8 += 112;
        v6 += 2;
        v200 = v6;
        break;
      default:
        continue;
    }
  }
}6 += 2;
        v200 = v6;
        break;
      default:
        continue;
    }
  }
}

// File Line: 1067
// RVA: 0xDE5CE0
void __fastcall hkExportImpulsesAndRhs(hkpSolverInfo *i, hkpSolverElemTemp *temp, hkpJacobianSchema *schemas, hkpVelocityAccumulator *accums)
{
  hkSolverExport::exportImpulsesAndRhs(i, temp, schemas, accums);
}

