// File Line: 111
// RVA: 0xDE5CF0
void __fastcall hkSolverExport::exportImpulsesAndRhs(
        hkpSolverInfo *info,
        hkpSolverElemTemp *solverInputs,
        hkpJacobianSchema *schemas,
        hkpVelocityAccumulator *accums)
{
  __m128 v4; // xmm2
  hkpSolverElemTemp *v6; // r11
  hkpJacobianSchema *v7; // r9
  hkpJacobianSchema *v8; // rbx
  __m128 v9; // xmm8
  float v10; // xmm7_4
  __m128 v11; // xmm11
  __m128 v12; // xmm6
  __int64 v13; // r10
  int v14; // r12d
  int v15; // r14d
  __int64 v16; // r13
  hkpVelocityAccumulator *v17; // rdx
  __m128i v18; // xmm6
  __int64 *v19; // r8
  int v20; // r15d
  __m128 v21; // xmm10
  __int64 v22; // rdi
  float v23; // xmm3_4
  unsigned __int64 v24; // r8
  hkpJacobianSchema i; // al
  __m128 *v26; // rax
  __m128 v27; // xmm0
  __m128 v28; // xmm2
  float v29; // xmm6_4
  __m128 v30; // xmm2
  float v31; // xmm1_4
  float v32; // xmm3_4
  __m128 v33; // xmm1
  __int64 v34; // r10
  __m128 *v35; // rcx
  __int64 v36; // rax
  bool v37; // zf
  __int64 v38; // rax
  __m128 v39; // xmm2
  float v40; // xmm3_4
  float v41; // xmm1_4
  float v42; // xmm1_4
  __m128 v43; // xmm4
  __m128 *v44; // rcx
  __m128 v45; // xmm3
  float v46; // xmm4_4
  float v47; // xmm4_4
  __m128 *v48; // rcx
  __m128 v49; // xmm2
  float v50; // xmm1_4
  float v51; // xmm3_4
  __m128 *v52; // rax
  __m128 v53; // xmm4
  __m128 *v54; // rcx
  __m128 *v55; // rax
  __m128 v56; // xmm1
  __m128 v57; // xmm3
  __m128 *v58; // rcx
  __m128 *v59; // rax
  __m128 v60; // xmm2
  __m128 *v61; // rax
  __m128 m_impulseApplied_low; // xmm0
  __m128 v63; // xmm3
  __m128 *v64; // rdx
  __m128 v65; // xmm3
  unsigned __int64 v66; // xmm1_8
  __m128 v67; // xmm0
  __m128 v68; // xmm3
  __m128 v69; // xmm2
  bool v70; // cc
  __int64 v71; // rax
  __m128 v72; // xmm0
  __m128 v73; // xmm1
  __m128 v74; // xmm1
  __m128 v75; // xmm0
  __m128 v76; // xmm1
  __m128 v77; // xmm1
  float v78; // xmm0_4
  __m128 v79; // xmm9
  __m128 *v80; // rax
  __m128 v81; // xmm1
  __m128 v82; // xmm7
  __m128 v83; // xmm5
  float *v84; // rcx
  __m128 v85; // xmm4
  float v86; // xmm8_4
  __m128 v87; // xmm5
  __m128 v88; // xmm1
  __m128 v89; // xmm3
  __m128 m_quad; // xmm4
  __m128 *v91; // rax
  float v92; // xmm9_4
  __m128 v93; // xmm1
  __m128 v94; // xmm0
  float v95; // xmm7_4
  __m128 v96; // xmm5
  __m128 v97; // xmm0
  __m128 v98; // xmm2
  __m128 v99; // xmm3
  unsigned __int64 v100; // rax
  __m128 v101; // xmm2
  __m128 v102; // xmm2
  __m128 v103; // xmm2
  __m128 v104; // xmm2
  __m128 v105; // xmm7
  __int64 v106; // rcx
  __m128 *v107; // rax
  __m128 v108; // xmm7
  __m128 v109; // xmm3
  __m128 v110; // xmm4
  __m128 v111; // xmm0
  __m128 v112; // xmm6
  __m128 v113; // xmm5
  __m128 *v114; // rcx
  __m128 *v115; // rax
  __int128 m_scratch3; // xmm1
  __int128 v117; // xmm1
  __m128 *v118; // rcx
  int m_gravityFactor_low; // xmm0_4
  char v120; // al
  __m128 v121; // xmm10
  int v122; // eax
  __int128 v123; // xmm0
  __m128 v124; // xmm7
  __int128 v125; // xmm1
  __m128 v126; // xmm14
  __m128 v127; // xmm6
  __m128 v128; // xmm2
  __m128 v129; // xmm9
  __int128 v130; // xmm1
  __m128 v131; // xmm0
  __m128 v132; // xmm8
  __m128 v133; // xmm4
  __m128 v134; // xmm12
  __m128 v135; // xmm15
  __m128 v136; // xmm1
  __m128 *v137; // r8
  hkpJacobianSchema *v138; // rdx
  int v139; // r9d
  __int64 v140; // rcx
  __int64 v141; // rax
  __m128 v142; // xmm3
  __m128 v143; // xmm2
  __m128 *v144; // r9
  int v145; // edi
  hkpJacobianSchema *v146; // rcx
  __int64 v147; // rax
  unsigned int *v148; // r14
  __int64 v149; // rdx
  __int64 v150; // rcx
  __m128 v151; // xmm3
  __m128 v152; // xmm2
  __m128 v153; // xmm2
  int v154; // edx
  __int64 v155; // rax
  __m128 v156; // xmm0
  int v157; // r9d
  __int64 v158; // rdi
  __int64 v159; // r8
  __int64 v160; // rdx
  __int64 v161; // rax
  int v162; // r9d
  __m128 *v163; // r14
  __int64 v164; // rcx
  __m128 *v165; // r15
  unsigned __int64 v166; // rax
  __int64 v167; // rdx
  int v168; // ecx
  hkpJacobianSchema *v169; // r8
  unsigned int *v170; // r9
  float v171; // xmm7_4
  float *p_m_impulseApplied; // r12
  __m128 *v173; // r13
  __m128 *v174; // rax
  int v175; // esi
  __int64 v176; // r8
  float *v177; // rdi
  __m128 *v178; // r11
  __int64 v179; // rax
  float v180; // xmm3_4
  __m128 v181; // xmm2
  __m128 v182; // xmm1
  float v183; // xmm5_4
  float v184; // xmm5_4
  __m128 v185; // xmm6
  hkpJacobianSchema *v186; // r9
  float v187; // xmm1_4
  float v188; // xmm3_4
  __m128 v189; // xmm1
  float v190; // xmm2_4
  float v191; // xmm0_4
  __m128 v192; // xmm1
  float v193; // xmm2_4
  float v194; // xmm0_4
  hkpSolverElemTemp *v195; // [rsp+0h] [rbp-C0h]
  char *p_m_storage; // [rsp+8h] [rbp-B8h]
  __int64 *v197; // [rsp+10h] [rbp-B0h]
  __int64 v198; // [rsp+18h] [rbp-A8h]
  int v199; // [rsp+20h] [rbp-A0h]
  int v200; // [rsp+24h] [rbp-9Ch]
  int v201; // [rsp+30h] [rbp-90h]
  __m128 v202; // [rsp+40h] [rbp-80h]
  unsigned int *v203; // [rsp+50h] [rbp-70h]
  __int64 v204; // [rsp+58h] [rbp-68h]
  float v205; // [rsp+60h] [rbp-60h]
  __int64 v206; // [rsp+68h] [rbp-58h]
  __m128 *v207; // [rsp+70h] [rbp-50h] BYREF
  int v208; // [rsp+78h] [rbp-48h]
  __m128 v209; // [rsp+80h] [rbp-40h]
  __m128 v210; // [rsp+90h] [rbp-30h]
  __int128 v211; // [rsp+A0h] [rbp-20h]
  __m128 v212; // [rsp+B0h] [rbp-10h]
  __m128 v213; // [rsp+C0h] [rbp+0h]
  __int128 v214; // [rsp+D0h] [rbp+10h]
  __int128 v215; // [rsp+E0h] [rbp+20h]
  char m_storage; // [rsp+F0h] [rbp+30h] BYREF
  char v217; // [rsp+F1h] [rbp+31h]
  unsigned int m_deactivationClass; // [rsp+F4h] [rbp+34h]
  float m_gravityFactor; // [rsp+F8h] [rbp+38h]
  __m128 v220; // [rsp+100h] [rbp+40h]
  __m128 v221; // [rsp+110h] [rbp+50h]
  __int128 m_invMasses; // [rsp+120h] [rbp+60h]
  __m128 v223; // [rsp+130h] [rbp+70h]
  __m128 v224; // [rsp+140h] [rbp+80h]
  hkVector4f v225; // [rsp+150h] [rbp+90h]
  __int128 v226; // [rsp+160h] [rbp+A0h]
  __m128 v227; // [rsp+170h] [rbp+B0h]
  __m128 v228; // [rsp+180h] [rbp+C0h]
  int v229; // [rsp+280h] [rbp+1C0h]
  float m_impulseApplied; // [rsp+288h] [rbp+1C8h]
  hkpJacobianSchema *v231; // [rsp+290h] [rbp+1D0h]
  hkpVelocityAccumulator *v232; // [rsp+298h] [rbp+1D8h]

  v4 = 0i64;
  v6 = solverInputs;
  v7 = schemas;
  v195 = solverInputs;
  v8 = schemas;
  v9 = _mm_shuffle_ps((__m128)LODWORD(info->m_deltaTime), (__m128)LODWORD(info->m_deltaTime), 0);
  v10 = _mm_shuffle_ps((__m128)LODWORD(info->m_dampDivTau), (__m128)LODWORD(info->m_dampDivTau), 0).m128_f32[0]
      * v9.m128_f32[0];
  v11 = _mm_mul_ps(
          _mm_shuffle_ps((__m128)LODWORD(info->m_dampDivFrictionTau), (__m128)LODWORD(info->m_dampDivFrictionTau), 0),
          v9);
  v12 = 0i64;
  v12.m128_f32[0] = (float)info->m_numSteps;
  v13 = 0i64;
  v14 = 0;
  v199 = 0;
  v15 = 0;
  v229 = 0;
  v16 = 0i64;
  v202 = v9;
  v205 = v10;
  v228 = v11;
  v17 = 0i64;
  p_m_storage = 0i64;
  v18 = (__m128i)_mm_shuffle_ps(v12, v12, 0);
  v201 = v18.m128i_i32[0];
  v19 = 0i64;
  v197 = 0i64;
  *(float *)&v20 = 0.0;
  m_impulseApplied = 0.0;
  v21 = _mm_mul_ps((__m128)v18, v9);
  v22 = 0i64;
  v198 = 0i64;
  v227 = v21;
  while ( 1 )
  {
LABEL_2:
    v23 = FLOAT_0_99000001;
    while ( 2 )
    {
      switch ( (unsigned __int8)*v8 )
      {
        case 0u:
          *(_DWORD *)v7 = v15;
          return;
        case 1u:
          v13 = *(_QWORD *)&v8[8];
          v14 = (unsigned __int8)v8[1];
          v16 = *(_QWORD *)&v8[16];
          v24 = (unsigned __int64)*(_WORD *)&v8[6] << 7;
          v17 = &accums[(unsigned __int64)*(_WORD *)&v8[4]];
          v8 += 32;
          v19 = (__int64 *)(&accums->m_type.m_storage + v24);
          v199 = v14;
          p_m_storage = &v17->m_type.m_storage;
          v197 = v19;
          if ( !v13 )
          {
            for ( i = *v8; *(_BYTE *)v8 > 4u; i = *v8 )
            {
              if ( *(unsigned __int8 *)&i >= 0x26u )
                break;
              v6 += (unsigned __int8)hkpJacobianSchema::s_schemaNumSolverElemTemps[*(unsigned __int8 *)&i];
              v195 = v6;
              v8 += (unsigned __int8)hkpJacobianSchema::s_schemaSize[*(unsigned __int8 *)&i];
            }
          }
          continue;
        case 2u:
          v8 += *(_QWORD *)&v8[8];
          continue;
        case 3u:
          v13 += *(_BYTE *)&v8[4] * (__int16)v14;
          v8 += 16;
          continue;
        case 5u:
        case 0x14u:
        case 0x15u:
          v35 = (__m128 *)v8;
          v8 += 48;
          goto $commonCodeForHk1Lin2AngJacobians;
        case 6u:
          v35 = (__m128 *)v8;
          v8 += 48;
          m_impulseApplied = v6->m_impulseApplied;
          if ( COERCE_FLOAT((unsigned int)(2 * LODWORD(m_impulseApplied)) >> 1) > (float)(v35[2].m128_f32[3] * v23) )
            v20 = 1;
          v37 = *v8 == 6;
          m_impulseApplied = *(float *)&v20;
          if ( !v37 && *(float *)&v20 != 0.0 )
          {
            v38 = v22;
            ++v15;
            ++v22;
            v38 *= 32i64;
            *(float *)&v20 = 0.0;
            v229 = v15;
            *(_DWORD *)&v7[v38 + 16] = 0;
            *(_QWORD *)&v7[v38 + 24] = v16;
            *(_QWORD *)&v7[v38 + 32] = 0i64;
            m_impulseApplied = 0.0;
            v198 = v22;
          }
          goto $commonCodeForHk1Lin2AngJacobians;
        case 7u:
        case 8u:
          v35 = (__m128 *)v8;
          v8 += 64;
          goto $commonCodeForHk1Lin2AngJacobians;
        case 9u:
          v48 = (__m128 *)v8;
          v8 += 64;
          v49 = _mm_add_ps(
                  _mm_add_ps(_mm_mul_ps(*((__m128 *)v19 + 5), v48[2]), _mm_mul_ps(v17->m_scratch1.m_quad, v48[1])),
                  _mm_mul_ps(_mm_sub_ps(v17->m_scratch0.m_quad, *((__m128 *)v19 + 4)), *v48));
          v50 = (float)(_mm_shuffle_ps(v49, v49, 85).m128_f32[0] + _mm_shuffle_ps(v49, v49, 0).m128_f32[0])
              + _mm_shuffle_ps(v49, v49, 170).m128_f32[0];
          v4 = 0i64;
          v51 = (float)((float)(_mm_shuffle_ps(*v48, *v48, 255).m128_f32[0] * v10) - (float)(v50 * v21.m128_f32[0]))
              * _mm_shuffle_ps((__m128)LODWORD(v6[1].m_impulseApplied), (__m128)LODWORD(v6[1].m_impulseApplied), 0).m128_f32[0];
          *(hkpSolverElemTemp *)v13 = LODWORD(v6->m_impulseApplied);
          *(float *)(v13 + 4) = v51;
          v13 += 2 * v14;
          v6 += 2;
          v195 = v6;
          goto LABEL_2;
        case 0xAu:
          v43 = (__m128)*(unsigned int *)&v8[56];
          v44 = (__m128 *)v8;
          v8 += 80;
          v45 = _mm_add_ps(
                  _mm_add_ps(_mm_mul_ps(*((__m128 *)v19 + 5), v44[2]), _mm_mul_ps(v17->m_scratch1.m_quad, v44[1])),
                  _mm_mul_ps(_mm_sub_ps(v17->m_scratch0.m_quad, *((__m128 *)v19 + 4)), *v44));
          v46 = (float)((float)((float)(_mm_shuffle_ps(v43, v43, 0).m128_f32[0] * *(float *)v18.m128i_i32)
                              + _mm_shuffle_ps(*v44, *v44, 255).m128_f32[0])
                      * v9.m128_f32[0])
              - (float)((float)((float)(_mm_shuffle_ps(v45, v45, 85).m128_f32[0]
                                      + _mm_shuffle_ps(v45, v45, 0).m128_f32[0])
                              + _mm_shuffle_ps(v45, v45, 170).m128_f32[0])
                      * v21.m128_f32[0]);
          goto LABEL_25;
        case 0xBu:
          v61 = (__m128 *)v8;
          v8 += 64;
          v40 = _mm_shuffle_ps(*v61, *v61, 255).m128_f32[0] * v10;
          v39 = _mm_add_ps(
                  _mm_add_ps(_mm_mul_ps(*((__m128 *)v19 + 5), v61[3]), _mm_mul_ps(v17->m_scratch1.m_quad, v61[2])),
                  _mm_sub_ps(_mm_mul_ps(v17->m_scratch0.m_quad, *v61), _mm_mul_ps(*((__m128 *)v19 + 4), v61[1])));
          *(hkpSolverElemTemp *)v13 = LODWORD(v6->m_impulseApplied);
          v41 = _mm_shuffle_ps(v39, v39, 85).m128_f32[0] + _mm_shuffle_ps(v39, v39, 0).m128_f32[0];
          goto LABEL_23;
        case 0xCu:
          v52 = (__m128 *)v8;
          v8 += 32;
          goto $commonCodeForHk2AngJacobians;
        case 0xDu:
          v52 = (__m128 *)v8;
          v8 += 48;
$commonCodeForHk2AngJacobians:
          v39 = _mm_add_ps(_mm_mul_ps(v17->m_scratch1.m_quad, *v52), _mm_mul_ps(*((__m128 *)v19 + 5), v52[1]));
          v40 = _mm_shuffle_ps(v52[1], v52[1], 255).m128_f32[0] * v9.m128_f32[0];
          goto LABEL_22;
        case 0xEu:
          v57 = *(__m128 *)&v8[16];
          v58 = (__m128 *)&v8[16];
          v59 = (__m128 *)v8;
          v8 += 48;
          v60 = _mm_add_ps(_mm_mul_ps(v17->m_scratch1.m_quad, *v59), _mm_mul_ps(*((__m128 *)v19 + 5), *v58));
          v57.m128_f32[0] = (float)((float)(_mm_shuffle_ps(v57, v57, 255).m128_f32[0] * v10)
                                  - (float)((float)((float)(_mm_shuffle_ps(v60, v60, 85).m128_f32[0]
                                                          + _mm_shuffle_ps(v60, v60, 0).m128_f32[0])
                                                  + _mm_shuffle_ps(v60, v60, 170).m128_f32[0])
                                          * v21.m128_f32[0]))
                          * _mm_shuffle_ps(
                              (__m128)LODWORD(v6[1].m_impulseApplied),
                              (__m128)LODWORD(v6[1].m_impulseApplied),
                              0).m128_f32[0];
          *(hkpSolverElemTemp *)v13 = LODWORD(v6->m_impulseApplied);
          *(_DWORD *)(v13 + 4) = v57.m128_i32[0];
          goto LABEL_26;
        case 0xFu:
          v53 = (__m128)*(unsigned int *)&v8[40];
          v54 = (__m128 *)&v8[16];
          v55 = (__m128 *)v8;
          v8 += 64;
          v56 = _mm_add_ps(_mm_mul_ps(v17->m_scratch1.m_quad, *v55), _mm_mul_ps(*((__m128 *)v19 + 5), *v54));
          v46 = (float)((float)((float)(_mm_shuffle_ps(v53, v53, 0).m128_f32[0] * *(float *)v18.m128i_i32)
                              + _mm_shuffle_ps(*v54, *v54, 255).m128_f32[0])
                      * v9.m128_f32[0])
              - (float)((float)((float)(_mm_shuffle_ps(v56, v56, 85).m128_f32[0]
                                      + _mm_shuffle_ps(v56, v56, 0).m128_f32[0])
                              + _mm_shuffle_ps(v56, v56, 170).m128_f32[0])
                      * v21.m128_f32[0]);
LABEL_25:
          v47 = v46
              * _mm_shuffle_ps((__m128)LODWORD(v6[1].m_impulseApplied), (__m128)LODWORD(v6[1].m_impulseApplied), 0).m128_f32[0];
          *(hkpSolverElemTemp *)v13 = LODWORD(v6->m_impulseApplied);
          *(float *)(v13 + 4) = v47;
LABEL_26:
          v4 = 0i64;
          v13 += 2 * v14;
          v6 += 2;
          v195 = v6;
          goto LABEL_2;
        case 0x10u:
          m_impulseApplied_low = (__m128)LODWORD(v6[2].m_impulseApplied);
          v63 = (__m128)*(unsigned __int64 *)&v6->m_impulseApplied;
          v64 = (__m128 *)v8;
          v6 += 3;
          v8 += 64;
          v195 = v6;
          v65 = (__m128)_mm_srli_si128(_mm_slli_si128((__m128i)_mm_movelh_ps(v63, m_impulseApplied_low), 4), 4);
          v66 = _mm_shuffle_ps(v65, v65, 254).m128_u64[0];
          v67 = _mm_shuffle_ps(v65, v65, 220);
          v68 = _mm_mul_ps(v65, v65);
          *(__m128 *)v13 = v67;
          *(_QWORD *)(v13 + 16) = v66;
          v69 = *v64;
          v17 = (hkpVelocityAccumulator *)p_m_storage;
          v13 += 3 * v14;
          *(float *)&v66 = (float)(_mm_shuffle_ps(v68, v68, 85).m128_f32[0] + _mm_shuffle_ps(v68, v68, 0).m128_f32[0])
                         + _mm_shuffle_ps(v68, v68, 170).m128_f32[0];
          v23 = FLOAT_0_99000001;
          v70 = *(float *)&v66 <= _mm_shuffle_ps(v69, v69, 255).m128_f32[0];
          v4 = 0i64;
          if ( v70 )
            continue;
          v71 = v22;
          ++v15;
          ++v22;
          v71 *= 32i64;
          v229 = v15;
          *(_DWORD *)&v7[v71 + 16] = 0;
          *(_QWORD *)&v7[v71 + 24] = v16;
          *(_QWORD *)&v7[v71 + 32] = 0i64;
          *(float *)&v20 = 0.0;
          m_impulseApplied = 0.0;
          v198 = v22;
          break;
        case 0x12u:
          v78 = v6->m_impulseApplied;
          ++v6;
          *(float *)v13 = v78;
          v195 = v6;
          *(_DWORD *)(v13 + 4) = 0;
          v13 += v14;
          v8 += 48;
          continue;
        case 0x16u:
        case 0x17u:
          v35 = (__m128 *)v8;
          v8 += 48;
          if ( (float)(v35[2].m128_f32[3] * v23) < v6->m_impulseApplied )
          {
            accums = v232;
            ++v15;
            v36 = 32 * v22++;
            v229 = v15;
            v198 = v22;
            *(_DWORD *)&v7[v36 + 16] = 0x10000;
            *(_QWORD *)&v7[v36 + 24] = v16;
            *(_QWORD *)&v7[v36 + 32] = v13;
          }
$commonCodeForHk1Lin2AngJacobians:
          v39 = _mm_add_ps(
                  _mm_add_ps(_mm_mul_ps(*((__m128 *)v19 + 5), v35[2]), _mm_mul_ps(v17->m_scratch1.m_quad, v35[1])),
                  _mm_mul_ps(_mm_sub_ps(v17->m_scratch0.m_quad, *((__m128 *)v19 + 4)), *v35));
          v40 = _mm_shuffle_ps(*v35, *v35, 255).m128_f32[0] * v10;
LABEL_22:
          v41 = _mm_shuffle_ps(v39, v39, 85).m128_f32[0] + _mm_shuffle_ps(v39, v39, 0).m128_f32[0];
          *(hkpSolverElemTemp *)v13 = LODWORD(v6->m_impulseApplied);
LABEL_23:
          v42 = v41 + _mm_shuffle_ps(v39, v39, 170).m128_f32[0];
          v4 = 0i64;
          *(float *)(v13 + 4) = v40 - (float)(v42 * v21.m128_f32[0]);
          v13 += v14;
          v195 = ++v6;
          goto LABEL_2;
        case 0x18u:
        case 0x19u:
          v26 = (__m128 *)v8;
          v8 += 112;
          v27 = _mm_sub_ps(v17->m_scratch0.m_quad, *((__m128 *)v19 + 4));
          v28 = _mm_add_ps(
                  _mm_add_ps(_mm_mul_ps(v26[1], v17->m_scratch1.m_quad), _mm_mul_ps(v26[2], *((__m128 *)v19 + 5))),
                  _mm_mul_ps(v27, *v26));
          v29 = (float)(_mm_shuffle_ps(*v26, *v26, 255).m128_f32[0] * v10)
              - (float)((float)((float)(_mm_shuffle_ps(v28, v28, 85).m128_f32[0]
                                      + _mm_shuffle_ps(v28, v28, 0).m128_f32[0])
                              + _mm_shuffle_ps(v28, v28, 170).m128_f32[0])
                      * v21.m128_f32[0]);
          v30 = _mm_add_ps(
                  _mm_add_ps(_mm_mul_ps(v26[4], v17->m_scratch1.m_quad), _mm_mul_ps(v26[5], *((__m128 *)v19 + 5))),
                  _mm_mul_ps(v27, v26[3]));
          v31 = (float)(_mm_shuffle_ps(v30, v30, 85).m128_f32[0] + _mm_shuffle_ps(v30, v30, 0).m128_f32[0])
              + _mm_shuffle_ps(v30, v30, 170).m128_f32[0];
          v4 = 0i64;
          v32 = (float)(_mm_shuffle_ps(v26[3], v26[3], 255).m128_f32[0] * v10) - (float)(v31 * v21.m128_f32[0]);
          v33 = (__m128)*(unsigned __int64 *)&v6->m_impulseApplied;
          *(_DWORD *)v13 = v33.m128_i32[0];
          *(float *)(v13 + 4) = v29;
          v18.m128i_i32[0] = v201;
          v34 = v14 + v13;
          *(_DWORD *)v34 = _mm_shuffle_ps(v33, v33, 85).m128_u32[0];
          *(float *)(v34 + 4) = v32;
          v13 = v14 + v34;
          v6 += 2;
          v195 = v6;
          goto LABEL_2;
        case 0x1Au:
          v79 = (__m128)LODWORD(v6[2].m_impulseApplied);
          v80 = (__m128 *)v8;
          v81 = *(__m128 *)&v8[48];
          v82 = *(__m128 *)v8;
          v83 = *(__m128 *)&v8[16];
          v8 += 112;
          v6 += 3;
          v4 = 0i64;
          v84 = (float *)v80[6].m128_u64[1];
          v79.m128_f32[0] = _mm_shuffle_ps(v79, v79, 0).m128_f32[0];
          v195 = v6;
          v85 = _mm_sub_ps(v17->m_scratch0.m_quad, *((__m128 *)v19 + 4));
          v86 = _mm_shuffle_ps(v81, v81, 255).m128_f32[0];
          v87 = _mm_add_ps(
                  _mm_add_ps(_mm_mul_ps(v83, v17->m_scratch1.m_quad), _mm_mul_ps(v80[2], *((__m128 *)v19 + 5))),
                  _mm_mul_ps(v85, v82));
          v18 = (__m128i)_mm_add_ps(
                           _mm_add_ps(
                             _mm_mul_ps(v80[4], v17->m_scratch1.m_quad),
                             _mm_mul_ps(v80[5], *((__m128 *)v19 + 5))),
                           _mm_mul_ps(v85, v81));
          v81.m128_f32[0] = (float)(_mm_shuffle_ps((__m128)v18, (__m128)v18, 85).m128_f32[0]
                                  + _mm_shuffle_ps((__m128)v18, (__m128)v18, 0).m128_f32[0])
                          + _mm_shuffle_ps((__m128)v18, (__m128)v18, 170).m128_f32[0];
          v18.m128i_i32[0] = v201;
          v84[6] = (float)((float)(_mm_shuffle_ps(v82, v82, 255).m128_f32[0] * v11.m128_f32[0])
                         - (float)((float)((float)(_mm_shuffle_ps(v87, v87, 85).m128_f32[0]
                                                 + _mm_shuffle_ps(v87, v87, 0).m128_f32[0])
                                         + _mm_shuffle_ps(v87, v87, 170).m128_f32[0])
                                 * v21.m128_f32[0]))
                 * v79.m128_f32[0];
          v10 = v205;
          v84[7] = (float)((float)(v86 * v11.m128_f32[0]) - (float)(v81.m128_f32[0] * v21.m128_f32[0]))
                 * v79.m128_f32[0];
          v9 = v202;
          v88 = _mm_mul_ps(
                  (__m128)*(unsigned __int64 *)&v6[-3].m_impulseApplied,
                  (__m128)*(unsigned __int64 *)&v6[-3].m_impulseApplied);
          v84[4] = _mm_shuffle_ps(v88, v88, 85).m128_f32[0] + _mm_shuffle_ps(v88, v88, 0).m128_f32[0];
          goto LABEL_2;
        case 0x1Bu:
          v89 = *((__m128 *)v19 + 5);
          m_quad = v17->m_scratch1.m_quad;
          v91 = (__m128 *)v8;
          v8 += 160;
          v92 = _mm_shuffle_ps((__m128)LODWORD(v6[3].m_impulseApplied), (__m128)LODWORD(v6[3].m_impulseApplied), 0).m128_f32[0];
          v93 = v91[3];
          v94 = _mm_sub_ps(v17->m_scratch0.m_quad, *((__m128 *)v19 + 4));
          v95 = _mm_shuffle_ps(*v91, *v91, 255).m128_f32[0];
          v96 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v91[1], m_quad), _mm_mul_ps(v91[2], v89)), _mm_mul_ps(v94, *v91));
          v18 = (__m128i)_mm_add_ps(
                           _mm_add_ps(_mm_mul_ps(v91[4], m_quad), _mm_mul_ps(v91[5], v89)),
                           _mm_mul_ps(v94, v93));
          v97 = _mm_mul_ps(v91[6], m_quad);
          v98 = _mm_mul_ps(v91[7], v89);
          v99 = v91[7];
          v100 = v91[9].m128_u64[0];
          v101 = _mm_add_ps(v98, v97);
          *(float *)(v100 + 24) = (float)((float)(v95 * v11.m128_f32[0])
                                        - (float)((float)((float)(_mm_shuffle_ps(v96, v96, 85).m128_f32[0]
                                                                + _mm_shuffle_ps(v96, v96, 0).m128_f32[0])
                                                        + _mm_shuffle_ps(v96, v96, 170).m128_f32[0])
                                                * v21.m128_f32[0]))
                                * v92;
          *(float *)(v100 + 28) = (float)((float)(_mm_shuffle_ps(v93, v93, 255).m128_f32[0] * v11.m128_f32[0])
                                        - (float)((float)((float)(_mm_shuffle_ps((__m128)v18, (__m128)v18, 85).m128_f32[0]
                                                                + _mm_shuffle_ps((__m128)v18, (__m128)v18, 0).m128_f32[0])
                                                        + _mm_shuffle_ps((__m128)v18, (__m128)v18, 170).m128_f32[0])
                                                * v21.m128_f32[0]))
                                * v92;
          *(float *)(v100 + 20) = (float)((float)(_mm_shuffle_ps(v99, v99, 255).m128_f32[0] * v11.m128_f32[0])
                                        - (float)((float)((float)(_mm_shuffle_ps(v101, v101, 85).m128_f32[0]
                                                                + _mm_shuffle_ps(v101, v101, 0).m128_f32[0])
                                                        + _mm_shuffle_ps(v101, v101, 170).m128_f32[0])
                                                * v21.m128_f32[0]))
                                * v92;
          v102 = _mm_movelh_ps(
                   (__m128)*(unsigned __int64 *)&v6->m_impulseApplied,
                   (__m128)LODWORD(v6[2].m_impulseApplied));
          v103 = _mm_mul_ps(v102, v102);
          v9 = v202;
          v18.m128i_i32[0] = v201;
          v10 = v205;
          v6 += 4;
          v195 = v6;
          v93.m128_f32[0] = (float)(_mm_shuffle_ps(v103, v103, 85).m128_f32[0]
                                  + _mm_shuffle_ps(v103, v103, 0).m128_f32[0])
                          + _mm_shuffle_ps(v103, v103, 170).m128_f32[0];
          v4 = 0i64;
          *(_DWORD *)(v100 + 16) = v93.m128_i32[0];
          goto LABEL_2;
        case 0x1Cu:
          v104 = v17->m_scratch1.m_quad;
          v105 = (__m128)LODWORD(v6[2].m_impulseApplied);
          v106 = *(_QWORD *)&v8[72];
          v107 = (__m128 *)v8;
          v8 += 96;
          v6 += 3;
          v195 = v6;
          v108 = _mm_shuffle_ps(v105, v105, 0);
          v109 = _mm_add_ps(_mm_mul_ps(*((__m128 *)v19 + 5), v107[1]), _mm_mul_ps(v104, *v107));
          v110 = _mm_add_ps(_mm_mul_ps(v107[3], *((__m128 *)v19 + 5)), _mm_mul_ps(v104, v107[2]));
          v111 = _mm_mul_ps(
                   (__m128)*(unsigned __int64 *)&v6[-3].m_impulseApplied,
                   (__m128)*(unsigned __int64 *)&v6[-3].m_impulseApplied);
          v112 = _mm_unpacklo_ps(
                   _mm_add_ps(_mm_shuffle_ps(v111, v111, 85), _mm_shuffle_ps(v111, v111, 0)),
                   _mm_mul_ps(
                     _mm_sub_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v107[1], v107[1], 255), v9),
                       _mm_mul_ps(
                         _mm_add_ps(
                           _mm_add_ps(_mm_shuffle_ps(v109, v109, 85), _mm_shuffle_ps(v109, v109, 0)),
                           _mm_shuffle_ps(v109, v109, 170)),
                         v21)),
                     v108));
          v4 = 0i64;
          v113 = _mm_mul_ps(
                   _mm_sub_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v107[3], v107[3], 255), v9),
                     _mm_mul_ps(
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v110, v110, 85), _mm_shuffle_ps(v110, v110, 0)),
                         _mm_shuffle_ps(v110, v110, 170)),
                       v21)),
                   v108);
          v10 = v205;
          v18 = _mm_srai_epi32(
                  (__m128i)_mm_mul_ps(
                             _mm_movelh_ps(v112, _mm_unpacklo_ps(v113, aabbOut.m_quad)),
                             (__m128)xmmword_141A71380),
                  0x10u);
          v202.m128_u64[0] = _mm_packs_epi32(v18, v18).m128i_u64[0];
          v18.m128i_i32[0] = v201;
          *(_DWORD *)(v106 + 6) = v202.m128_i32[0];
          *(_WORD *)(v106 + 10) = v202.m128_i16[2];
          goto LABEL_2;
        case 0x1Du:
          v8 += 32;
          continue;
        case 0x1Eu:
          v114 = (__m128 *)v8;
          v8 += 32;
          if ( v114[1].m128_i32[0] )
          {
            LOWORD(v207) = *(_WORD *)v19;
            HIDWORD(v207) = *((_DWORD *)v19 + 1);
            v115 = (__m128 *)&v207;
            v208 = *((_DWORD *)v19 + 2);
            v209 = *((__m128 *)v19 + 1);
            v210 = *((__m128 *)v19 + 2);
            v211 = *((_OWORD *)v19 + 3);
            v212 = *((__m128 *)v19 + 4);
            v213 = *((__m128 *)v19 + 5);
            v214 = *((_OWORD *)v19 + 6);
            v117 = *((_OWORD *)v19 + 7);
            v19 = (__int64 *)&v207;
            v197 = (__int64 *)&v207;
            v215 = v117;
          }
          else
          {
            m_storage = v17->m_type.m_storage;
            v217 = v17->m_context.m_storage;
            m_deactivationClass = v17->m_deactivationClass;
            v115 = (__m128 *)&m_storage;
            m_gravityFactor = v17->m_gravityFactor;
            v220 = v17->m_linearVel.m_quad;
            v221 = v17->m_angularVel.m_quad;
            m_invMasses = (__int128)v17->m_invMasses;
            v223 = v17->m_scratch0.m_quad;
            v224 = v17->m_scratch1.m_quad;
            v225.m_quad = (__m128)v17->m_scratch2;
            m_scratch3 = (__int128)v17->m_scratch3;
            v17 = (hkpVelocityAccumulator *)&m_storage;
            p_m_storage = &m_storage;
            v226 = m_scratch3;
          }
          v4 = 0i64;
          v115[1] = _mm_add_ps(v115[1], *v114);
          v115[4] = _mm_add_ps(v115[4], *v114);
          continue;
        case 0x1Fu:
          v118 = (__m128 *)v8;
          v8 += 96;
          m_storage = v17->m_type.m_storage;
          v217 = v17->m_context.m_storage;
          m_deactivationClass = v17->m_deactivationClass;
          m_gravityFactor_low = LODWORD(v17->m_gravityFactor);
          LOBYTE(v207) = *(_BYTE *)v19;
          v120 = *((_BYTE *)v19 + 1);
          m_gravityFactor = *(float *)&m_gravityFactor_low;
          v220 = v17->m_linearVel.m_quad;
          v121 = v17->m_angularVel.m_quad;
          BYTE1(v207) = v120;
          v122 = *((_DWORD *)v19 + 1);
          v221 = v121;
          v123 = (__int128)v17->m_invMasses;
          HIDWORD(v207) = v122;
          m_invMasses = v123;
          v223 = v17->m_scratch0.m_quad;
          v224 = v17->m_scratch1.m_quad;
          v124 = _mm_mul_ps(_mm_shuffle_ps(v224, v224, 170), v118[2]);
          v225.m_quad = (__m128)v17->m_scratch2;
          v125 = (__int128)v17->m_scratch3;
          v208 = *((_DWORD *)v19 + 2);
          v17 = (hkpVelocityAccumulator *)&m_storage;
          p_m_storage = &m_storage;
          v126 = *((__m128 *)v19 + 1);
          v226 = v125;
          v127 = _mm_mul_ps(_mm_shuffle_ps(v224, v224, 0), *v118);
          v128 = _mm_mul_ps(_mm_shuffle_ps(v224, v224, 85), v118[1]);
          v209 = v126;
          v18 = (__m128i)_mm_add_ps(_mm_add_ps(v127, v128), v124);
          v210 = *((__m128 *)v19 + 2);
          v211 = *((_OWORD *)v19 + 3);
          v212 = *((__m128 *)v19 + 4);
          v213 = *((__m128 *)v19 + 5);
          v129 = _mm_mul_ps(_mm_shuffle_ps(v213, v213, 170), v118[5]);
          v214 = *((_OWORD *)v19 + 6);
          v130 = *((_OWORD *)v19 + 7);
          v19 = (__int64 *)&v207;
          v197 = (__int64 *)&v207;
          v131 = _mm_mul_ps(_mm_shuffle_ps(v121, v121, 85), v118[1]);
          v215 = v130;
          v132 = _mm_mul_ps(_mm_shuffle_ps(v213, v213, 85), v118[4]);
          v133 = _mm_mul_ps(_mm_shuffle_ps(v213, v213, 0), v118[3]);
          v220 = _mm_add_ps(
                   v220,
                   _mm_add_ps(
                     _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v121, v121, 0), *v118), v131),
                     _mm_mul_ps(_mm_shuffle_ps(v121, v121, 170), v118[2])));
          v21 = v227;
          v10 = v205;
          v11.m128_i32[0] = v228.m128_i32[0];
          v134 = _mm_add_ps(v223, (__m128)v18);
          v4 = 0i64;
          v135 = _mm_add_ps(v212, _mm_add_ps(_mm_add_ps(v132, v133), v129));
          v18.m128i_i32[0] = v201;
          v9 = v202;
          v136 = _mm_mul_ps(_mm_shuffle_ps(v210, v210, 85), v118[4]);
          v223 = v134;
          v212 = v135;
          v209 = _mm_add_ps(
                   v126,
                   _mm_add_ps(
                     _mm_add_ps(v136, _mm_mul_ps(_mm_shuffle_ps(v210, v210, 0), v118[3])),
                     _mm_mul_ps(_mm_shuffle_ps(v210, v210, 170), v118[5])));
          goto LABEL_2;
        case 0x20u:
          v72 = (__m128)LODWORD(v6[2].m_impulseApplied);
          v73 = (__m128)*(unsigned __int64 *)&v6->m_impulseApplied;
          v6 += 3;
          v195 = v6;
          v74 = (__m128)_mm_srli_si128(_mm_slli_si128((__m128i)_mm_movelh_ps(v73, v72), 4), 4);
          *(__m128 *)v13 = _mm_shuffle_ps(v74, v74, 220);
          *(_QWORD *)(v13 + 16) = _mm_shuffle_ps(v74, v74, 254).m128_u64[0];
          v13 += 3 * v14;
          v8 += 48;
          continue;
        case 0x22u:
        case 0x23u:
          v75 = (__m128)LODWORD(v6[2].m_impulseApplied);
          v76 = (__m128)*(unsigned __int64 *)&v6->m_impulseApplied;
          v6 += 3;
          v195 = v6;
          v77 = (__m128)_mm_srli_si128(_mm_slli_si128((__m128i)_mm_movelh_ps(v76, v75), 4), 4);
          *(__m128 *)v13 = _mm_shuffle_ps(v77, v77, 220);
          *(_QWORD *)(v13 + 16) = _mm_shuffle_ps(v77, v77, 254).m128_u64[0];
          v13 += 3 * v14;
          v8 += 128;
          continue;
        case 0x27u:
          v137 = (__m128 *)&v8[32];
          if ( v13 )
          {
            v138 = &v8[64 * (unsigned __int64)*(_WORD *)&v8[4] + 36];
            v139 = 0;
            if ( *(_WORD *)&v8[4] )
            {
              do
              {
                v140 = *(_DWORD *)v138;
                v141 = *(unsigned int *)&v138[4];
                v142 = *v137;
                v138 += 4;
                ++v139;
                ++v6;
                v137 += 3;
                v143 = _mm_add_ps(
                         _mm_add_ps(
                           _mm_mul_ps(*(__m128 *)((char *)&accums->m_scratch1.m_quad + v141), v137[-1]),
                           _mm_mul_ps(*(__m128 *)((char *)&accums->m_scratch1.m_quad + v140), v137[-2])),
                         _mm_mul_ps(
                           _mm_sub_ps(
                             *(__m128 *)((char *)&accums->m_scratch0.m_quad + v140),
                             *(__m128 *)((char *)&accums->m_scratch0.m_quad + v141)),
                           v142));
                *(hkpSolverElemTemp *)v13 = v6[-1];
                *(float *)(v13 + 4) = (float)(_mm_shuffle_ps(v142, v142, 255).m128_f32[0] * v9.m128_f32[0])
                                    - (float)((float)((float)(_mm_shuffle_ps(v143, v143, 85).m128_f32[0]
                                                            + _mm_shuffle_ps(v143, v143, 0).m128_f32[0])
                                                    + _mm_shuffle_ps(v143, v143, 170).m128_f32[0])
                                            * v21.m128_f32[0]);
                v13 += v14;
              }
              while ( v139 < *(unsigned __int16 *)&v8[4] );
              v23 = FLOAT_0_99000001;
              v22 = v198;
              v195 = v6;
              v4 = 0i64;
            }
            v7 = v231;
            v17 = (hkpVelocityAccumulator *)p_m_storage;
            v19 = v197;
            v8 += *(unsigned int *)&v8[8];
          }
          else
          {
            v19 = v197;
            v6 += *(unsigned __int16 *)&v8[4];
            v8 += *(unsigned int *)&v8[8];
            v195 = v6;
          }
          continue;
        case 0x28u:
          v144 = (__m128 *)&v8[32];
          if ( v13 )
          {
            v145 = 0;
            v146 = &v8[144 * *(unsigned __int16 *)&v8[4]
                     + 48
                     + 144 * *(unsigned __int16 *)&v8[4]
                     + 16 * *(unsigned __int16 *)&v8[4]];
            if ( *(_WORD *)&v8[4] )
            {
              do
              {
                v147 = *(_DWORD *)v146;
                v148 = (unsigned int *)&v146[4];
                v149 = 3i64;
                v150 = *(unsigned int *)&v146[4];
                do
                {
                  v151 = *v144;
                  v152 = v144[2];
                  ++v6;
                  v144 += 3;
                  v153 = _mm_add_ps(
                           _mm_add_ps(
                             _mm_mul_ps(v152, *(__m128 *)((char *)&accums->m_scratch1.m_quad + v150)),
                             _mm_mul_ps(*(__m128 *)((char *)&accums->m_scratch1.m_quad + v147), v144[-2])),
                           _mm_mul_ps(
                             _mm_sub_ps(
                               *(__m128 *)((char *)&accums->m_scratch0.m_quad + v147),
                               *(__m128 *)((char *)&accums->m_scratch0.m_quad + v150)),
                             v151));
                  *(hkpSolverElemTemp *)v13 = v6[-1];
                  *(float *)(v13 + 4) = (float)(_mm_shuffle_ps(v151, v151, 255).m128_f32[0] * v9.m128_f32[0])
                                      - (float)((float)((float)(_mm_shuffle_ps(v153, v153, 85).m128_f32[0]
                                                              + _mm_shuffle_ps(v153, v153, 0).m128_f32[0])
                                                      + _mm_shuffle_ps(v153, v153, 170).m128_f32[0])
                                              * v21.m128_f32[0]);
                  v13 += v14;
                  --v149;
                }
                while ( v149 );
                ++v145;
                v195 = v6;
                v146 = (hkpJacobianSchema *)v148;
              }
              while ( v145 < *(unsigned __int16 *)&v8[4] );
              v23 = FLOAT_0_99000001;
              v15 = v229;
              v4 = 0i64;
            }
            v22 = v198;
            v19 = v197;
            v17 = (hkpVelocityAccumulator *)p_m_storage;
            v7 = v231;
            v8 += *(unsigned int *)&v8[8];
          }
          else
          {
            v7 = v231;
            v6 += 3 * *(unsigned __int16 *)&v8[4];
            v8 += *(unsigned int *)&v8[8];
            v195 = v6;
          }
          continue;
        case 0x29u:
          if ( v13 )
          {
            v154 = 0;
            if ( *(_WORD *)&v8[4] )
            {
              do
              {
                v155 = 3i64;
                do
                {
                  v156 = (__m128)LODWORD(v6->m_impulseApplied);
                  ++v6;
                  *(_QWORD *)v13 = _mm_shuffle_ps(_mm_unpacklo_ps(v156, v4), v156, 228).m128_u64[0];
                  v13 += v14;
                  --v155;
                }
                while ( v155 );
                ++v154;
                v195 = v6;
              }
              while ( v154 < *(unsigned __int16 *)&v8[4] );
            }
            v17 = (hkpVelocityAccumulator *)p_m_storage;
            v8 += *(unsigned int *)&v8[8];
          }
          else
          {
            v6 += 3 * *(unsigned __int16 *)&v8[4];
            v8 += *(unsigned int *)&v8[8];
            v195 = v6;
          }
          continue;
        case 0x2Au:
          v157 = 0;
          v158 = 0i64;
          if ( *(_WORD *)&v8[4] )
          {
            v159 = 0i64;
            do
            {
              v160 = *(unsigned __int16 *)&v8[4];
              ++v157;
              ++v158;
              v161 = v159 + 240i64 * (_DWORD)v160;
              v159 += 64i64;
              *(hkpJacobianSchema *)(v158 + *(_QWORD *)&v8[8] - 1) = v8[1028 * v160 + 68 + v161];
            }
            while ( v157 < *(unsigned __int16 *)&v8[4] );
          }
          v162 = *(unsigned __int16 *)&v8[4];
          v163 = (__m128 *)&v8[32];
          v164 = 3 * v162;
          v165 = (__m128 *)&v8[48 * v164 + 32];
          if ( v13 )
          {
            v166 = 80 * v164 + ((unsigned __int64)*(_WORD *)&v8[4] << 10);
            v167 = (__int64)&v8[1028 * *(unsigned __int16 *)&v8[4] + 68 + 80 * v164];
            v168 = 0;
            v169 = &v8[v166 + 64];
            v200 = 0;
            v204 = v167;
            if ( *(_WORD *)&v8[4] )
            {
              v202.m128_i32[2] = 1069547520;
              v170 = 0i64;
              LODWORD(v171) = _mm_shuffle_ps((__m128)0x3FC00000u, (__m128)0x3FC00000u, 0).m128_u32[0];
              v206 = 6 * v14;
              do
              {
                p_m_impulseApplied = &v6->m_impulseApplied;
                v203 = (unsigned int *)&v169[4];
                v173 = (__m128 *)(&accums->m_type.m_storage + *(_DWORD *)v169);
                v174 = (__m128 *)(&accums->m_type.m_storage + *(unsigned int *)&v169[4]);
                v175 = 0;
                v176 = 0i64;
                v207 = v174;
                v177 = (float *)(v13 + 28);
                v178 = v174;
                v179 = v167 + ((__int64)v168 << 6) + 12;
                LODWORD(v205) = v167 + (v168 << 6) + 12;
                do
                {
                  v180 = _mm_shuffle_ps(*v163, *v163, 255).m128_f32[0];
                  v181 = _mm_add_ps(
                           _mm_add_ps(_mm_mul_ps(v163[2], v178[5]), _mm_mul_ps(v163[1], v173[5])),
                           _mm_mul_ps(_mm_sub_ps(v173[4], v178[4]), *v163));
                  *(float *)v13 = *p_m_impulseApplied;
                  *(float *)(v13 + 4) = v180
                                      - (float)((float)((float)(_mm_shuffle_ps(v181, v181, 85).m128_f32[0]
                                                              + _mm_shuffle_ps(v181, v181, 0).m128_f32[0])
                                                      + _mm_shuffle_ps(v181, v181, 170).m128_f32[0])
                                              * v21.m128_f32[0]);
                  v182 = _mm_add_ps(_mm_mul_ps(*v165, v173[5]), _mm_mul_ps(v165[1], v178[5]));
                  v183 = (float)((float)(_mm_shuffle_ps(
                                           (__m128)*(unsigned int *)(v179 + v176),
                                           (__m128)*(unsigned int *)(v179 + v176),
                                           0).m128_f32[0]
                                       * *(float *)v18.m128i_i32)
                               + _mm_shuffle_ps(v165[1], v165[1], 255).m128_f32[0])
                       * v9.m128_f32[0];
                  *(v177 - 1) = p_m_impulseApplied[3];
                  v184 = v183
                       - (float)((float)((float)(_mm_shuffle_ps(v182, v182, 85).m128_f32[0]
                                               + _mm_shuffle_ps(v182, v182, 0).m128_f32[0])
                                       + _mm_shuffle_ps(v182, v182, 170).m128_f32[0])
                               * v21.m128_f32[0]);
                  *v177 = v184;
                  v185 = _mm_shuffle_ps(*v165, *v165, 255);
                  v186 = (hkpJacobianSchema *)&v170[257 * *(unsigned __int16 *)&v8[4] + 60 * *(unsigned __int16 *)&v8[4]]
                       + (_QWORD)v8;
                  if ( ((*(_BYTE *)&v186[68] >> (2 * v175)) & 3) == 3 )
                  {
                    v187 = _mm_rcp_ps(v185).m128_f32[0];
                    v188 = (float)(2.0 - (float)(v187 * v185.m128_f32[0])) * v187;
                    v189 = _mm_shuffle_ps((__m128)*(_DWORD *)&v186[v176 + 84], (__m128)*(_DWORD *)&v186[v176 + 84], 0);
                    v190 = _mm_rcp_ps(v189).m128_f32[0];
                    v184 = fmax(
                             v184,
                             (float)((float)((float)(2.0 - (float)(v190 * v189.m128_f32[0])) * v190)
                                   * (float)((float)(v188
                                                   * _mm_shuffle_ps(
                                                       (__m128)*(_DWORD *)&v186[v176 + 76],
                                                       (__m128)*(_DWORD *)&v186[v176 + 76],
                                                       0).m128_f32[0])
                                           * v9.m128_f32[0]))
                           * v171);
                    *v177 = v184;
                  }
                  if ( ((*(_BYTE *)&v186[68] >> (2 * v175)) & 3) == 1 )
                  {
                    v191 = _mm_rcp_ps(v185).m128_f32[0];
                    v192 = _mm_shuffle_ps((__m128)*(_DWORD *)&v186[v176 + 84], (__m128)*(_DWORD *)&v186[v176 + 84], 0);
                    v193 = (float)((float)((float)(2.0 - (float)(v185.m128_f32[0] * v191)) * v191)
                                 * _mm_shuffle_ps(
                                     (__m128)*(_DWORD *)&v186[v176 + 72],
                                     (__m128)*(_DWORD *)&v186[v176 + 72],
                                     0).m128_f32[0])
                         * v9.m128_f32[0];
                    v194 = _mm_rcp_ps(v192).m128_f32[0];
                    *v177 = fmin(
                              v184,
                              (float)((float)((float)(2.0 - (float)(v192.m128_f32[0] * v194)) * v194) * v193) * v171);
                  }
                  v18.m128i_i32[0] = v201;
                  v170 = v203;
                  v179 = v167 + ((__int64)v168 << 6) + 12;
                  ++v175;
                  ++p_m_impulseApplied;
                  v176 += 20i64;
                  v177 += 2;
                  v163 += 3;
                  v165 += 2;
                }
                while ( v175 < 3 );
                v13 += v206;
                v169 = (hkpJacobianSchema *)v203;
                accums = v232;
                v167 = v204;
                v168 = v200 + 1;
                v6 = v195 + 6;
                v170 = v203 + 16;
                v195 += 6;
                v200 = v168;
              }
              while ( v168 < *(unsigned __int16 *)&v8[4] );
              v10 = v205;
              v23 = FLOAT_0_99000001;
              v14 = v199;
              v16 = v204;
              v4 = 0i64;
            }
          }
          else
          {
            v6 += 6 * v162;
            v195 = v6;
          }
          v17 = (hkpVelocityAccumulator *)p_m_storage;
          v19 = v197;
          v7 = v231;
          v22 = v198;
          v15 = v229;
          *(float *)&v20 = m_impulseApplied;
          v8 += *(unsigned int *)&v8[16];
          continue;
        case 0x2Bu:
          v8 += 112;
          v6 += 2;
          v195 = v6;
          continue;
        default:
          continue;
      }
      break;
    }
  }
}

// File Line: 1067
// RVA: 0xDE5CE0
// attributes: thunk
void __fastcall hkExportImpulsesAndRhs(
        hkpSolverInfo *i,
        hkpSolverElemTemp *temp,
        hkpJacobianSchema *schemas,
        hkpVelocityAccumulator *accums)
{
  hkSolverExport::exportImpulsesAndRhs(i, temp, schemas, accums);
}

