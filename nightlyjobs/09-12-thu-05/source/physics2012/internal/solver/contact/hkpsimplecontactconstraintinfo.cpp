// File Line: 57
// RVA: 0xDD8590
float __fastcall calculateRhs(hkContactPoint *ccp, hkpContactPointProperties *sr, float distance, float dt)
{
  float v4; // xmm5_4
  float v5; // xmm4_4
  float v6; // xmm6_4
  float v7; // xmm1_4
  float v8; // xmm5_4
  float v9; // xmm4_4
  float result; // xmm0_4

  v4 = sr->m_internalDataA;
  v5 = distance - v4;
  v6 = COERCE_FLOAT(LODWORD(sr->m_internalSolverData) ^ _xmm[0]) - (float)(distance - v4);
  v7 = fminf(
         COERCE_FLOAT(LODWORD(HK_CONTACT_EXPONENTIAL_ERROR_RECOVERY_VELOCITY) ^ _xmm[0]) * v4,
         HK_CONTACT_LINEAR_ERROR_RECOVERY_VELOCITY * dt);
  v8 = v4 + v7;
  v9 = v5 - v7;
  if ( v6 > (float)((float)(v7 * 2.0) + (float)(HK_CONTACT_LINEAR_ERROR_RECOVERY_VELOCITY * dt)) )
  {
    v8 = v8 - v6;
    v9 = v9 + v6;
  }
  result = v9;
  sr->m_internalDataA = fminf(v8, -0.00000011920929);
  return result;
}

// File Line: 130
// RVA: 0xDD7470
void __fastcall hkSimpleContactConstraintDataBuildJacobian(hkpSimpleContactConstraintAtom *atom, hkpConstraintQueryIn *in, hkBool writeHeaderSchemas, hkpConstraintQueryOut *out)
{
  __m128 *v4; // rbx
  char v5; // r10
  hkpConstraintQueryIn *v6; // r14
  hkpVelocityAccumulator *v7; // r15
  hkpVelocityAccumulator *v8; // r12
  hkpSimpleContactConstraintAtom *v9; // r9
  float v10; // xmm14_4
  __m128 v11; // xmm2
  __m128 v12; // xmm7
  __m128 v13; // xmm6
  char *v14; // rdi
  __m128 v15; // xmm2
  __m128 v16; // xmm1
  unsigned int v17; // ecx
  unsigned int v18; // eax
  hkpConstraintInstance *v19; // rdx
  signed int v20; // esi
  float v21; // xmm15_4
  signed __int64 v22; // r13
  signed __int64 v23; // rdi
  __m128 v24; // xmm8
  __m128 v25; // xmm13
  __m128 v26; // xmm1
  __m128 v27; // xmm3
  __m128 v28; // xmm2
  __m128 v29; // xmm4
  __m128 v30; // xmm4
  __m128 v31; // xmm1
  __m128 v32; // xmm2
  __m128 v33; // xmm1
  __m128 v34; // xmm5
  __m128 v35; // xmm4
  __m128 v36; // xmm3
  __m128 v37; // xmm3
  __m128 v38; // xmm0
  __m128 v39; // xmm1
  __m128 v40; // xmm2
  char v41; // cl
  unsigned __int16 v42; // ax
  float v43; // xmm0_4
  float v44; // xmm3_4
  float v45; // xmm4_4
  float v46; // xmm3_4
  float v47; // ST40_4
  float v48; // xmm5_4
  float v49; // xmm1_4
  float v50; // xmm4_4
  float v51; // xmm3_4
  char v52; // cl
  float *v53; // rax
  float v54; // xmm0_4
  unsigned __int16 v55; // ax
  __m128 v56; // xmm8
  __m128 v57; // xmm1
  __m128 v58; // xmm2
  __m128 v59; // xmm3
  __m128 v60; // xmm0
  __m128 v61; // xmm4
  __m128 v62; // xmm3
  __m128 v63; // xmm6
  __m128 v64; // xmm4
  __m128 v65; // xmm7
  __m128 v66; // xmm5
  __m128 v67; // xmm3
  __m128 v68; // xmm1
  __m128 v69; // xmm4
  __m128 v70; // xmm0
  __m128 v71; // xmm1
  signed int v72; // ecx
  hkpSimpleContactConstraintDataInfo *v73; // rsi
  float v74; // xmm10_4
  __m128 v75; // xmm3
  float v76; // xmm4_4
  __m128 v77; // xmm6
  __m128 v78; // xmm1
  __m128 v79; // xmm2
  __m128 v80; // xmm3
  __m128 v81; // xmm11
  __m128 v82; // xmm1
  __m128 v83; // xmm5
  __m128 v84; // xmm5
  __m128 v85; // xmm2
  __m128 v86; // xmm3
  __m128 v87; // xmm5
  __int16 v88; // dx
  __m128 v89; // xmm7
  __m128 v90; // xmm1
  __m128 v91; // xmm3
  __m128 v92; // xmm2
  __m128 v93; // xmm5
  __m128 v94; // xmm0
  __m128 v95; // xmm5
  float v96; // xmm0_4
  __m128 v97; // xmm5
  __m128 v98; // xmm3
  float v99; // ST90_4
  __m128 v100; // xmm1
  __m128 v101; // xmm4
  __m128 v102; // xmm15
  __m128 v103; // xmm0
  __m128 v104; // xmm2
  float v105; // xmm5_4
  __m128 v106; // xmm4
  __m128 v107; // xmm1
  __m128 v108; // xmm0
  __m128 v109; // xmm2
  __m128 v110; // xmm1
  __m128 v111; // xmm2
  __m128 v112; // xmm15
  __m128 v113; // xmm0
  __m128 v114; // xmm1
  __m128 v115; // xmm4
  int v116; // eax
  __m128 v117; // xmm2
  __m128 v118; // xmm2
  __m128 v119; // xmm2
  __m128 v120; // xmm1
  __m128 v121; // xmm2
  float v122; // xmm0_4
  __m128 v123; // xmm10
  __m128 *v124; // r11
  __m128 v125; // xmm4
  __m128 v126; // xmm15
  __m128 v127; // xmm7
  __m128 v128; // xmm4
  __m128 v129; // xmm15
  __m128 v130; // xmm1
  __m128 v131; // xmm6
  __m128 v132; // xmm3
  __m128 v133; // xmm2
  __m128 v134; // xmm2
  __m128 v135; // xmm3
  __m128 v136; // xmm1
  __m128 v137; // xmm3
  __m128 v138; // xmm2
  __m128 v139; // xmm1
  __m128 v140; // xmm1
  __m128 v141; // xmm0
  __m128 v142; // xmm1
  __m128 v143; // xmm2
  float v144; // xmm5_4
  __m128 v145; // xmm1
  __m128 v146; // xmm1
  __m128 v147; // xmm2
  __m128 v148; // xmm4
  __m128 v149; // xmm2
  __m128 v150; // xmm3
  __m128 v151; // xmm1
  __m128 v152; // xmm1
  __m128 v153; // xmm0
  __m128 v154; // xmm1
  __m128 v155; // xmm2
  __m128 v156; // xmm6
  signed __int64 v157; // r9
  __m128 *v158; // rdx
  __m128 v159; // xmm1
  float v160; // xmm12_4
  __m128 v161; // xmm4
  __m128 v162; // xmm7
  __m128 v163; // xmm8
  __m128 v164; // xmm5
  __m128 v165; // xmm3
  __m128 v166; // xmm1
  __m128 v167; // xmm4
  __m128 v168; // xmm2
  float v169; // xmm14_4
  __m128 v170; // xmm5
  int v171; // er8
  float v172; // xmm13_4
  __m128 v173; // xmm5
  hkpSimpleContactConstraintAtom *v174; // rax
  int i; // ecx
  __m128 v176; // xmm1
  __m128 v177; // xmm1
  __m128 v178; // xmm1
  __m128 v179; // xmm4
  __m128 v180; // xmm1
  __m128 v181; // xmm3
  __m128 v182; // xmm2
  __m128 v183; // xmm4
  __m128 v184; // xmm3
  __m128 v185; // xmm0
  __m128 v186; // xmm1
  __m128 v187; // xmm1
  __m128 v188; // xmm2
  __m128 v189; // xmm1
  __m128 v190; // xmm2
  __m128 v191; // xmm3
  __m128 v192; // xmm1
  int v193; // [rsp+20h] [rbp-E0h]
  int v194; // [rsp+38h] [rbp-C8h]
  __m128 v195; // [rsp+50h] [rbp-B0h]
  __m128 v196; // [rsp+50h] [rbp-B0h]
  __m128 *v197; // [rsp+60h] [rbp-A0h]
  __m128 v198; // [rsp+60h] [rbp-A0h]
  __m128 v199; // [rsp+70h] [rbp-90h]
  __m128 v200; // [rsp+70h] [rbp-90h]
  hkpSimpleContactConstraintDataInfo *v201; // [rsp+80h] [rbp-80h]
  __m128 v202; // [rsp+80h] [rbp-80h]
  hkpSimpleContactConstraintDataInfo *v203; // [rsp+90h] [rbp-70h]
  hkpSimpleContactConstraintAtom *v204; // [rsp+A0h] [rbp-60h]
  float v205; // [rsp+B0h] [rbp-50h]
  __m128 v206; // [rsp+C0h] [rbp-40h]
  __m128 v207; // [rsp+D0h] [rbp-30h]
  signed int v208; // [rsp+1C0h] [rbp+C0h]
  float v209; // [rsp+1C0h] [rbp+C0h]
  unsigned int v210; // [rsp+1C0h] [rbp+C0h]
  float v211; // [rsp+1C8h] [rbp+C8h]
  hkpConstraintQueryOut *v212; // [rsp+1D8h] [rbp+D8h]

  v212 = out;
  v4 = (__m128 *)out->m_jacobianSchemas.m_storage;
  v5 = atom->m_contactPointPropertiesStriding;
  v6 = in;
  v7 = in->m_bodyA.m_storage;
  v8 = in->m_bodyB.m_storage;
  v9 = atom + 1;
  v208 = atom->m_numContactPoints;
  v10 = 0.0;
  v194 = (unsigned __int8)atom->m_contactPointPropertiesStriding;
  v204 = atom + 1;
  v11 = 0i64;
  v12 = 0i64;
  v11.m128_f32[0] = (float)v208;
  v201 = &atom->m_info;
  v13 = 0i64;
  v14 = (char *)&atom[1] + 32 * atom->m_numReservedContactPoints;
  v15 = _mm_shuffle_ps(v11, v11, 0);
  v16 = _mm_rcp_ps(v15);
  v206 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v16, v15)), v16);
  if ( writeHeaderSchemas.m_bool )
  {
    v17 = in->m_accumulatorBIndex.m_storage;
    v18 = in->m_accumulatorAIndex.m_storage;
    v19 = in->m_constraintInstance.m_storage;
    *(float *)v4->m128_u64 = *(float *)v4->m128_u64 + 0.00000011920929;
    WORD2(v4->m128_u64[0]) = v18;
    HIWORD(v4->m128_u64[0]) = v17;
    LOBYTE(v4->m128_u64[0]) = 1;
    BYTE1(v4->m128_u64[0]) = v5;
    v4->m128_u64[1] = (unsigned __int64)v14;
    v4[1].m128_u64[0] = (unsigned __int64)v19;
    v4 += 2;
  }
  v20 = 0;
  v21 = 0.0;
  v203 = &v9->m_info;
  v22 = (signed __int64)&v9->m_info;
  v23 = (signed __int64)(v14 + 19);
  do
  {
    v24 = *(__m128 *)v22;
    v25 = *(__m128 *)(v22 - 16);
    v211 = v6->m_virtMassFactor.m_storage;
    v197 = v4;
    v193 = *(_BYTE *)v23 & 2;
    v26 = _mm_sub_ps(v25, v7->m_scratch3.m_quad);
    v27 = _mm_sub_ps(v25, v8->m_scratch3.m_quad);
    v28 = _mm_shuffle_ps(v24, v24, 201);
    *v4 = *(__m128 *)v22;
    v29 = _mm_sub_ps(_mm_mul_ps(v28, v26), _mm_mul_ps(_mm_shuffle_ps(v26, v26, 201), v24));
    v30 = _mm_shuffle_ps(v29, v29, 201);
    v31 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v27, v27, 201), v24), _mm_mul_ps(v28, v27));
    v32 = v7->m_invMasses.m_quad;
    v33 = _mm_shuffle_ps(v31, v31, 201);
    v34 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v30, v30, 85), v7->m_scratch1.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v30, v30, 0), v7->m_scratch0.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v30, v30, 170), v7->m_scratch2.m_quad));
    v35 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v33, v33, 85), v8->m_scratch1.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v33, v33, 0), v8->m_scratch0.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v33, v33, 170), v8->m_scratch2.m_quad));
    v36 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v35, v35), v8->m_invMasses.m_quad), _mm_mul_ps(_mm_mul_ps(v34, v34), v32));
    v37 = _mm_shuffle_ps(
            v36,
            _mm_unpackhi_ps(v36, _mm_max_ps(_mm_add_ps(v32, v8->m_invMasses.m_quad), (__m128)xmmword_141A712D0)),
            196);
    v38 = _mm_add_ps(_mm_shuffle_ps(v37, v37, 78), v37);
    v39 = _mm_add_ps(_mm_shuffle_ps(v38, v38, 177), v38);
    v40 = _mm_rcp_ps(v39);
    v4[2] = _mm_shuffle_ps(v35, _mm_unpackhi_ps(v35, v39), 196);
    v41 = *(_BYTE *)(v23 - 3);
    v4[1] = _mm_shuffle_ps(
              v34,
              _mm_unpackhi_ps(
                v34,
                _mm_mul_ps(
                  _mm_shuffle_ps((__m128)LODWORD(v211), (__m128)LODWORD(v211), 0),
                  _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v40, v39)), v40))),
              196);
    v42 = hkUFloat8::getEncodedFloat(v41);
    if ( v42 )
      LODWORD(v43) = (v42 + 243712) << 12;
    else
      v43 = 0.0;
    v21 = v21 + *(float *)(v23 - 19);
    v10 = v10 + v43;
    if ( *(_BYTE *)v23 & 8 )
      v44 = FLOAT_1_8446726e19;
    else
      v44 = *(float *)(v22 + 12);
    v45 = *(float *)(v23 + 5);
    v46 = v44 - v45;
    v47 = HK_CONTACT_LINEAR_ERROR_RECOVERY_VELOCITY * v6->m_frameDeltaTime.m_storage;
    v48 = COERCE_FLOAT(*(_DWORD *)(v23 - 15) ^ _xmm[0]) - v46;
    v49 = fminf(COERCE_FLOAT(LODWORD(HK_CONTACT_EXPONENTIAL_ERROR_RECOVERY_VELOCITY) ^ _xmm[0]) * v45, v47);
    v50 = v45 + v49;
    v51 = v46 - v49;
    if ( v48 > (float)((float)(v49 * 2.0) + v47) )
    {
      v50 = v50 - v48;
      v51 = v51 + v48;
    }
    v12 = _mm_add_ps(v12, v25);
    v13 = _mm_add_ps(v13, v24);
    v199 = v12;
    v195 = v13;
    *(float *)(v23 + 5) = fminf(v50, -0.00000011920929);
    *((float *)&v4->m128_u64[1] + 1) = COERCE_FLOAT(LODWORD(v51) ^ _xmm[0]) * v6->m_rhsFactor.m_storage;
    if ( v193 )
    {
      v56 = v4[-1];
      v57 = v8->m_invMasses.m_quad;
      v58 = v7->m_invMasses.m_quad;
      v59 = v4[-3];
      v60 = _mm_mul_ps(_mm_mul_ps(v4[2], v56), v57);
      v61 = _mm_mul_ps(_mm_mul_ps(v4[1], v4[-2]), v58);
      v4 += 4;
      v62 = _mm_mul_ps(v59, v4[-4]);
      v63 = _mm_shuffle_ps(v56, v56, 255);
      v64 = _mm_add_ps(
              _mm_add_ps(v61, v60),
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v58, v58, 255), v62), _mm_mul_ps(_mm_shuffle_ps(v57, v57, 255), v62)));
      v65 = _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v64, v64, 85), _mm_shuffle_ps(v64, v64, 0)),
                _mm_shuffle_ps(v64, v64, 170)),
              _mm_shuffle_ps((__m128)0x3F7D70A4u, (__m128)0x3F7D70A4u, 0));
      v66 = _mm_shuffle_ps(v4[-2], v4[-2], 255);
      v67 = _mm_sub_ps(_mm_mul_ps(v66, v63), _mm_mul_ps(v65, v65));
      v68 = _mm_rcp_ps(v67);
      v69 = _mm_mul_ps(
              _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v68, v67)), v68),
              _mm_shuffle_ps(
                (__m128)LODWORD(v6->m_virtMassFactor.m_storage),
                (__m128)LODWORD(v6->m_virtMassFactor.m_storage),
                0));
      v4[-5] = _mm_shuffle_ps(v56, _mm_unpackhi_ps(v56, _mm_mul_ps(v66, v69)), 196);
      v70 = _mm_unpackhi_ps(v4[-2], _mm_mul_ps(v63, v69));
      v13 = v195;
      v71 = _mm_shuffle_ps(v4[-2], v70, 196);
      v70.m128_f32[0] = 0.0 - v65.m128_f32[0];
      v12 = v199;
      v4[-2] = v71;
      v4[-1].m128_f32[0] = v70.m128_f32[0] * v69.m128_f32[0];
      v4[-7].m128_f32[0] = v4[-7].m128_f32[0] + 0.00000011920929;
      v4[-7].m128_i8[0] = 24;
    }
    else
    {
      v52 = *(_BYTE *)(v23 - 1);
      v53 = (float *)v4;
      v54 = *(float *)v4->m128_u64 + 0.00000011920929;
      v4 += 3;
      v4[-3].m128_f32[0] = v54;
      v4[-3].m128_i8[0] = 20;
      if ( v52 )
      {
        *v53 = *v53 + 0.00000011920929;
        *(_BYTE *)v53 = 22;
        v55 = hkUFloat8::getEncodedFloat(v52);
        if ( v55 )
          v197[2].m128_i32[3] = (v55 + 243712) << 12;
        else
          v197[2].m128_i32[3] = 0;
      }
    }
    ++v20;
    v22 += 32i64;
    v23 += v194;
    v72 = v208;
  }
  while ( v20 < v208 );
  v73 = v201;
  v74 = COERCE_FLOAT(_mm_shuffle_ps((__m128)COERCE_UNSIGNED_INT(v10 * v21), (__m128)COERCE_UNSIGNED_INT(v10 * v21), 0))
      * v206.m128_f32[0];
  v205 = v74;
  if ( v74 <= 0.0 )
    goto LABEL_40;
  v75 = _mm_mul_ps(v13, v13);
  v76 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v75, v75, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v75, v75, 0)))
      + COERCE_FLOAT(_mm_shuffle_ps(v75, v75, 170));
  if ( (float)((float)(v206.m128_f32[0] * v206.m128_f32[0]) * v76) <= COERCE_FLOAT(
                                                                        _mm_shuffle_ps(
                                                                          (__m128)LODWORD(FLOAT_0_99989998),
                                                                          (__m128)LODWORD(FLOAT_0_99989998),
                                                                          0)) )
  {
    if ( v76 <= COERCE_FLOAT(_mm_shuffle_ps((__m128)0x3DCCCCCDu, (__m128)0x3DCCCCCDu, 0)) )
    {
      v196 = *(__m128 *)&v203->m_flags;
      v77 = *(__m128 *)&v203->m_flags;
      v80 = _mm_mul_ps(v77, v77);
      if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v80, v80, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v80, v80, 0)))
                 + COERCE_FLOAT(_mm_shuffle_ps(v80, v80, 170))) >= COERCE_FLOAT(
                                                                     _mm_shuffle_ps(
                                                                       (__m128)LODWORD(FLOAT_0_89999998),
                                                                       (__m128)LODWORD(FLOAT_0_89999998),
                                                                       0)) )
        goto LABEL_27;
      v77 = direction.m_quad;
      v74 = 0.0;
      v205 = 0.0;
    }
    else
    {
      v78 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v75, v75, 85), _mm_shuffle_ps(v75, v75, 0)),
              _mm_shuffle_ps(v75, v75, 170));
      v79 = _mm_rsqrt_ps(v78);
      v77 = _mm_mul_ps(
              v13,
              _mm_andnot_ps(
                _mm_cmpleps(v78, (__m128)0i64),
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v79, v78), v79)),
                  _mm_mul_ps(*(__m128 *)_xmm, v79))));
    }
  }
  else
  {
    v77 = *(__m128 *)&v203->m_flags;
  }
  v196 = v77;
LABEL_27:
  v81 = _mm_shuffle_ps(v77, v77, 201);
  v82 = *(&transform.m_quad + v201->m_biNormalAxis);
  v83 = _mm_sub_ps(_mm_mul_ps(v81, v82), _mm_mul_ps(_mm_shuffle_ps(v82, v82, 201), v77));
  v84 = _mm_shuffle_ps(v83, v83, 201);
  v85 = _mm_mul_ps(v84, v84);
  if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v85, v85, 0)) + COERCE_FLOAT(_mm_shuffle_ps(v85, v85, 85)))
             + COERCE_FLOAT(_mm_shuffle_ps(v85, v85, 170))) <= COERCE_FLOAT(
                                                                 _mm_shuffle_ps(
                                                                   (__m128)0x3DCCCCCDu,
                                                                   (__m128)0x3DCCCCCDu,
                                                                   0)) )
  {
    v86 = (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)v77, 1u), 1u);
    v72 = v208;
    v201->m_biNormalAxis = (unsigned __int8)hkVector4Comparison_maskToFirstIndex[_mm_movemask_ps(
                                                                                   _mm_and_ps(
                                                                                     _mm_cmpleps(
                                                                                       v86,
                                                                                       _mm_min_ps(
                                                                                         _mm_shuffle_ps(v86, v86, 170),
                                                                                         _mm_min_ps(
                                                                                           _mm_shuffle_ps(v86, v86, 85),
                                                                                           _mm_shuffle_ps(v86, v86, 0)))),
                                                                                     (__m128)xmmword_141A9E880))];
    *(_QWORD *)&v201->m_data[2] = 0i64;
    *(_DWORD *)&v201->m_rhsRolling[0].m_value = 0;
    v87 = _mm_sub_ps(
            _mm_mul_ps(v81, *(&transform.m_quad + v201->m_biNormalAxis)),
            _mm_mul_ps(
              _mm_shuffle_ps(
                *(&transform.m_quad + v201->m_biNormalAxis),
                *(&transform.m_quad + v201->m_biNormalAxis),
                201),
              v77));
    v84 = _mm_shuffle_ps(v87, v87, 201);
  }
  v88 = v201->m_rollingFrictionMultiplier.m_value;
  v89 = _mm_mul_ps(v12, v206);
  v90 = _mm_mul_ps(v84, v84);
  v200 = v89;
  v91 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v90, v90, 85), _mm_shuffle_ps(v90, v90, 0)), _mm_shuffle_ps(v90, v90, 170));
  v92 = _mm_rsqrt_ps(v91);
  v93 = _mm_mul_ps(
          v84,
          _mm_andnot_ps(
            _mm_cmpleps(v91, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v92, v91), v92)),
              _mm_mul_ps(*(__m128 *)_xmm, v92))));
  v202 = v93;
  v94 = _mm_shuffle_ps(v93, v93, 201);
  v198 = v94;
  v95 = _mm_sub_ps(_mm_mul_ps(v94, v77), _mm_mul_ps(v81, v93));
  v96 = COERCE_FLOAT(
          _mm_shuffle_ps(
            (__m128)(unsigned int)(v73->m_rollingFrictionMultiplier.m_value << 16),
            (__m128)(unsigned int)(v73->m_rollingFrictionMultiplier.m_value << 16),
            0))
      * v74;
  v97 = _mm_shuffle_ps(v95, v95, 201);
  v207 = v97;
  if ( v96 > 0.0 )
  {
    v98 = (__m128)LODWORD(v6->m_virtMassFactor.m_storage);
    v99 = v96 * v6->m_invNumStepsTimesMicroSteps.m_storage;
    LODWORD(v209) = v73->m_rhsRolling[0].m_value << 16;
    v100 = _mm_mul_ps(_mm_shuffle_ps(v97, v97, 170), v7->m_scratch2.m_quad);
    v101 = _mm_mul_ps(_mm_shuffle_ps(v97, v97, 0), v7->m_scratch0.m_quad);
    v102 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
    v103 = _mm_shuffle_ps(v97, v97, 85);
    v104 = _mm_xor_ps(v102, v97);
    v105 = v6->m_frictionRhsFactor.m_storage;
    v106 = _mm_add_ps(_mm_add_ps(v101, _mm_mul_ps(v103, v7->m_scratch1.m_quad)), v100);
    v107 = _mm_add_ps(
             _mm_add_ps(
               _mm_mul_ps(_mm_shuffle_ps(v104, v104, 0), v8->m_scratch0.m_quad),
               _mm_mul_ps(_mm_shuffle_ps(v104, v104, 85), v8->m_scratch1.m_quad)),
             _mm_mul_ps(_mm_shuffle_ps(v104, v104, 170), v8->m_scratch2.m_quad));
    v108 = _mm_mul_ps(_mm_mul_ps(v106, v106), v7->m_invMasses.m_quad);
    v4[1] = v107;
    v109 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v107, v107), v8->m_invMasses.m_quad), v108);
    v110 = _mm_add_ps(
             _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v109, v109, 85), _mm_shuffle_ps(v109, v109, 0)),
               _mm_shuffle_ps(v109, v109, 170)),
             *(__m128 *)&epsilon);
    v111 = _mm_rcp_ps(v110);
    v112 = _mm_xor_ps(v102, v202);
    v113 = _mm_unpackhi_ps(
             v106,
             _mm_mul_ps(_mm_shuffle_ps(v98, v98, 0), _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v111, v110)), v111)));
    v114 = _mm_mul_ps(_mm_shuffle_ps(v202, v202, 170), v7->m_scratch2.m_quad);
    *v4 = _mm_shuffle_ps(v106, v113, 196);
    v4[1].m128_f32[3] = v105 * v209;
    v115 = _mm_add_ps(
             _mm_add_ps(
               _mm_mul_ps(_mm_shuffle_ps(v202, v202, 0), v7->m_scratch0.m_quad),
               _mm_mul_ps(_mm_shuffle_ps(v202, v202, 85), v7->m_scratch1.m_quad)),
             v114);
    v116 = v73->m_rhsRolling[1].m_value;
    v117 = _mm_mul_ps(_mm_shuffle_ps(v112, v112, 0), v8->m_scratch0.m_quad);
    v4[4].m128_u64[1] = (unsigned __int64)v73;
    v4 += 6;
    v118 = _mm_add_ps(
             _mm_add_ps(v117, _mm_mul_ps(_mm_shuffle_ps(v112, v112, 85), v8->m_scratch1.m_quad)),
             _mm_mul_ps(_mm_shuffle_ps(v112, v112, 170), v8->m_scratch2.m_quad));
    v4[-3] = v118;
    v119 = _mm_add_ps(
             _mm_mul_ps(_mm_mul_ps(v118, v118), v8->m_invMasses.m_quad),
             _mm_mul_ps(_mm_mul_ps(v115, v115), v7->m_invMasses.m_quad));
    v120 = _mm_add_ps(
             _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v119, v119, 85), _mm_shuffle_ps(v119, v119, 0)),
               _mm_shuffle_ps(v119, v119, 170)),
             *(__m128 *)&epsilon);
    v121 = _mm_rcp_ps(v120);
    v4[-4] = _mm_shuffle_ps(
               v115,
               _mm_unpackhi_ps(
                 v115,
                 _mm_mul_ps(
                   _mm_shuffle_ps(v98, v98, 0),
                   _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v121, v120)), v121))),
               196);
    v4[-2].m128_f32[0] = v99;
    v4[-1].m128_i16[0] = v88;
    v113.m128_f32[0] = v4[-6].m128_f32[0] + 0.00000011920929;
    v4[-3].m128_f32[3] = v105 * COERCE_FLOAT(v116 << 16);
    v97 = v207;
    v4[-6].m128_i32[0] = v113.m128_i32[0];
    v4[-6].m128_i8[0] = 28;
  }
  v122 = v6->m_virtMassFactor.m_storage;
  v123 = v7->m_invMasses.m_quad;
  *v4 = v97;
  v124 = v4;
  v125 = v89;
  v126 = v89;
  v127 = v8->m_invMasses.m_quad;
  v128 = _mm_sub_ps(v125, v7->m_scratch3.m_quad);
  v129 = _mm_sub_ps(v126, v8->m_scratch3.m_quad);
  v130 = _mm_shuffle_ps(v97, v97, 201);
  v131 = _mm_max_ps(_mm_add_ps(v123, v127), (__m128)xmmword_141A712D0);
  v132 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v129, v129, 201), v97), _mm_mul_ps(v130, v129));
  v133 = _mm_sub_ps(_mm_mul_ps(v130, v128), _mm_mul_ps(_mm_shuffle_ps(v128, v128, 201), v97));
  v134 = _mm_shuffle_ps(v133, v133, 201);
  v135 = _mm_shuffle_ps(v132, v132, 201);
  v4[1] = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v134, v134, 0), v7->m_scratch0.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v134, v134, 85), v7->m_scratch1.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v134, v134, 170), v7->m_scratch2.m_quad));
  v136 = _mm_add_ps(
           _mm_add_ps(
             _mm_mul_ps(_mm_shuffle_ps(v135, v135, 0), v8->m_scratch0.m_quad),
             _mm_mul_ps(_mm_shuffle_ps(v135, v135, 85), v8->m_scratch1.m_quad)),
           _mm_mul_ps(_mm_shuffle_ps(v135, v135, 170), v8->m_scratch2.m_quad));
  v137 = _mm_shuffle_ps((__m128)LODWORD(v122), (__m128)LODWORD(v122), 0);
  v4[2] = v136;
  v138 = v136;
  v139 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v136, v136), v127), _mm_mul_ps(_mm_mul_ps(v4[1], v4[1]), v123));
  v140 = _mm_shuffle_ps(v139, _mm_unpackhi_ps(v139, v131), 196);
  v141 = _mm_add_ps(_mm_shuffle_ps(v140, v140, 78), v140);
  v142 = _mm_add_ps(_mm_shuffle_ps(v141, v141, 177), v141);
  v4[2] = _mm_shuffle_ps(v138, _mm_unpackhi_ps(v138, v142), 196);
  v143 = _mm_rcp_ps(v142);
  v141.m128_f32[0] = v6->m_frictionRhsFactor.m_storage * v73->m_data[2];
  v144 = v6->m_frictionRhsFactor.m_storage * v73->m_data[3];
  v4[1] = _mm_shuffle_ps(
            v4[1],
            _mm_unpackhi_ps(v4[1], _mm_mul_ps(v137, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v143, v142)), v143))),
            196);
  v142.m128_i32[0] = LODWORD(v6->m_virtMassFactor.m_storage);
  HIDWORD(v4->m128_u64[1]) = v141.m128_i32[0];
  v210 = v142.m128_i32[0];
  v4[3] = v202;
  v145 = _mm_sub_ps(_mm_mul_ps(v198, v128), _mm_mul_ps(_mm_shuffle_ps(v128, v128, 201), v202));
  v146 = _mm_shuffle_ps(v145, v145, 201);
  v147 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v129, v129, 201), v202), _mm_mul_ps(v198, v129));
  v148 = _mm_add_ps(
           _mm_add_ps(
             _mm_mul_ps(_mm_shuffle_ps(v146, v146, 0), v7->m_scratch0.m_quad),
             _mm_mul_ps(_mm_shuffle_ps(v146, v146, 85), v7->m_scratch1.m_quad)),
           _mm_mul_ps(_mm_shuffle_ps(v146, v146, 170), v7->m_scratch2.m_quad));
  v149 = _mm_shuffle_ps(v147, v147, 201);
  v150 = _mm_add_ps(
           _mm_add_ps(
             _mm_mul_ps(_mm_shuffle_ps(v149, v149, 0), v8->m_scratch0.m_quad),
             _mm_mul_ps(_mm_shuffle_ps(v149, v149, 85), v8->m_scratch1.m_quad)),
           _mm_mul_ps(_mm_shuffle_ps(v149, v149, 170), v8->m_scratch2.m_quad));
  v151 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v150, v150), v127), _mm_mul_ps(_mm_mul_ps(v148, v148), v123));
  v152 = _mm_shuffle_ps(v151, _mm_unpackhi_ps(v151, v131), 196);
  v153 = _mm_add_ps(_mm_shuffle_ps(v152, v152, 78), v152);
  v154 = _mm_add_ps(_mm_shuffle_ps(v153, v153, 177), v153);
  v155 = _mm_rcp_ps(v154);
  v4[5] = _mm_shuffle_ps(v150, _mm_unpackhi_ps(v150, v154), 196);
  v4[4] = _mm_shuffle_ps(
            v148,
            _mm_unpackhi_ps(
              v148,
              _mm_mul_ps(
                _mm_shuffle_ps((__m128)v210, (__m128)v210, 0),
                _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v155, v154)), v155))),
            196);
  v4[3].m128_f32[3] = v144;
  v156 = v4[2];
  v157 = (signed __int64)&v4[6];
  v158 = v4;
  v159 = _mm_mul_ps(v4[3], *v4);
  v160 = v205 * v6->m_invNumStepsTimesMicroSteps.m_storage;
  v161 = _mm_add_ps(
           _mm_add_ps(
             _mm_mul_ps(_mm_shuffle_ps(v123, v123, 255), v159),
             _mm_mul_ps(_mm_shuffle_ps(v127, v127, 255), v159)),
           _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v4[4], v4[1]), v123), _mm_mul_ps(_mm_mul_ps(v4[5], v4[2]), v127)));
  v162 = _mm_shuffle_ps(v156, v156, 255);
  v163 = _mm_mul_ps(
           _mm_add_ps(
             _mm_add_ps(_mm_shuffle_ps(v161, v161, 85), _mm_shuffle_ps(v161, v161, 0)),
             _mm_shuffle_ps(v161, v161, 170)),
           _mm_shuffle_ps((__m128)(unsigned int)FLOAT_1_0, (__m128)(unsigned int)FLOAT_1_0, 0));
  v164 = _mm_shuffle_ps(v4[5], v4[5], 255);
  v165 = _mm_sub_ps(_mm_mul_ps(v164, v162), _mm_mul_ps(v163, v163));
  v166 = _mm_rcp_ps(v165);
  v167 = _mm_mul_ps(
           _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v166, v165)), v166),
           _mm_shuffle_ps(
             (__m128)LODWORD(v6->m_virtMassFactor.m_storage),
             (__m128)LODWORD(v6->m_virtMassFactor.m_storage),
             0));
  v4[2] = _mm_shuffle_ps(v156, _mm_unpackhi_ps(v156, _mm_mul_ps(v167, v164)), 196);
  v4[5] = _mm_shuffle_ps(v4[5], _mm_unpackhi_ps(v4[5], _mm_mul_ps(v167, v162)), 196);
  v168 = 0i64;
  v153.m128_f32[0] = *(float *)v4->m128_u64 + 0.00000011920929;
  v4[6].m128_f32[1] = v160;
  v4[6].m128_u64[1] = (unsigned __int64)v73;
  LODWORD(v4->m128_u64[0]) = v153.m128_i32[0];
  LOBYTE(v4->m128_u64[0]) = 26;
  v169 = (float)(0.0 - v163.m128_f32[0]) * v167.m128_f32[0];
  v4[6].m128_f32[0] = v169;
  v4 += 7;
  if ( v72 > 1 )
  {
    v170 = _mm_shuffle_ps((__m128)LODWORD(v73->m_contactRadius), (__m128)LODWORD(v73->m_contactRadius), 0);
    if ( v73->m_flags & 4 )
    {
      v171 = v72 - 1;
      LODWORD(v172) = (unsigned __int128)_mm_shuffle_ps(
                                           (__m128)LODWORD(FLOAT_0_000001),
                                           (__m128)LODWORD(FLOAT_0_000001),
                                           0);
      while ( 1 )
      {
        v173 = v168;
        v174 = v204;
        for ( i = v171; i >= 0; v173 = _mm_add_ps(v173, v181) )
        {
          v176 = *(__m128 *)&v174->m_type.m_storage;
          v174 = (hkpSimpleContactConstraintAtom *)((char *)v174 + 32);
          --i;
          v177 = _mm_sub_ps(v176, v200);
          v178 = _mm_mul_ps(v177, v177);
          v179 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v178, v178, 85), _mm_shuffle_ps(v178, v178, 0)),
                   _mm_shuffle_ps(v178, v178, 170));
          v180 = _mm_rsqrt_ps(v179);
          v181 = _mm_andnot_ps(
                   _mm_cmpleps(v179, v168),
                   _mm_mul_ps(
                     _mm_mul_ps(
                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v180, v179), v180)),
                       _mm_mul_ps(*(__m128 *)_xmm, v180)),
                     v179));
          v168 = 0i64;
        }
        v170 = _mm_mul_ps(v173, v206);
        if ( v170.m128_f32[0] < v172 )
          break;
        v73->m_flags &= 0xFFFBu;
        if ( !(v73->m_flags & 4) )
          goto LABEL_38;
      }
    }
    else
    {
LABEL_38:
      v182 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v196);
      v183 = _mm_add_ps(
               _mm_add_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v196, v196, 85), v7->m_scratch1.m_quad),
                 _mm_mul_ps(_mm_shuffle_ps(v196, v196, 0), v7->m_scratch0.m_quad)),
               _mm_mul_ps(_mm_shuffle_ps(v196, v196, 170), v7->m_scratch2.m_quad));
      v184 = (__m128)LODWORD(v6->m_virtMassFactor.m_storage);
      v185 = _mm_mul_ps(_mm_shuffle_ps(v182, v182, 0), v8->m_scratch0.m_quad);
      v186 = _mm_mul_ps(_mm_shuffle_ps(v182, v182, 85), v8->m_scratch1.m_quad);
      *(__m128 *)v157 = v183;
      v187 = _mm_add_ps(_mm_add_ps(v186, v185), _mm_mul_ps(_mm_shuffle_ps(v182, v182, 170), v8->m_scratch2.m_quad));
      *(__m128 *)(v157 + 16) = v187;
      v188 = _mm_add_ps(
               _mm_mul_ps(_mm_mul_ps(v187, v187), v8->m_invMasses.m_quad),
               _mm_mul_ps(_mm_mul_ps(v183, v183), v7->m_invMasses.m_quad));
      v189 = _mm_add_ps(
               _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v188, v188, 85), _mm_shuffle_ps(v188, v188, 0)),
                 _mm_shuffle_ps(v188, v188, 170)),
               *(__m128 *)&epsilon);
      v190 = _mm_rcp_ps(v189);
      v191 = _mm_mul_ps(
               _mm_shuffle_ps(v184, v184, 0),
               _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v190, v189)), v190));
      v192 = _mm_rcp_ps(v170);
      v185.m128_f32[0] = v73->m_data[1] * v6->m_frictionRhsFactor.m_storage;
      *(__m128 *)v157 = _mm_shuffle_ps(v183, _mm_unpackhi_ps(v183, v191), 196);
      v124[7].m128_i32[3] = v185.m128_i32[0];
      *(__m128 *)v157 = _mm_shuffle_ps(
                          *(__m128 *)v157,
                          _mm_unpackhi_ps(
                            *(__m128 *)v157,
                            _mm_mul_ps(
                              _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v170, v192)), v192),
                              _mm_shuffle_ps(*(__m128 *)v157, *(__m128 *)v157, 255))),
                          196);
      v185.m128_i32[0] = v158->m128_u64[0];
      v158[8].m128_f32[0] = v169;
      v158[9].m128_u64[0] = (unsigned __int64)v73;
      v158[8].m128_f32[1] = v160;
      v158[8].m128_i32[2] = v170.m128_i32[0];
      *(float *)v158->m128_u64 = v185.m128_f32[0] + 0.00000011920929;
      LOBYTE(v158->m128_u64[0]) = 27;
      v4 = v158 + 10;
    }
    LODWORD(v73->m_contactRadius) = v170.m128_i32[0];
  }
LABEL_40:
  v212->m_jacobianSchemas.m_storage = (hkpJacobianSchema *)v4;
}

// File Line: 470
// RVA: 0xDD8570
void __fastcall hkSimpleContactConstraintDataAddALittleSurfaceViscosity(hkpSimpleContactConstraintDataInfo *infoExt)
{
  *(_QWORD *)&infoExt->m_data[2] = 0i64;
  infoExt->m_data[1] = 0.0;
  *(_DWORD *)&infoExt->m_rhsRolling[0].m_value = 0;
}

