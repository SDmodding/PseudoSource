// File Line: 57
// RVA: 0xDD8590
float __fastcall calculateRhs(hkContactPoint *ccp, hkpContactPointProperties *sr, float distance, float dt)
{
  float m_internalDataA; // xmm5_4
  float v5; // xmm4_4
  float v6; // xmm6_4
  float v7; // xmm1_4
  float v8; // xmm5_4
  float v9; // xmm4_4
  float result; // xmm0_4

  m_internalDataA = sr->m_internalDataA;
  v5 = distance - m_internalDataA;
  v6 = COERCE_FLOAT(LODWORD(sr->m_internalSolverData) ^ _xmm[0]) - (float)(distance - m_internalDataA);
  v7 = fminf(
         COERCE_FLOAT(LODWORD(HK_CONTACT_EXPONENTIAL_ERROR_RECOVERY_VELOCITY) ^ _xmm[0]) * m_internalDataA,
         HK_CONTACT_LINEAR_ERROR_RECOVERY_VELOCITY * dt);
  v8 = m_internalDataA + v7;
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
void __fastcall hkSimpleContactConstraintDataBuildJacobian(
        hkpSimpleContactConstraintAtom *atom,
        hkpConstraintQueryIn *in,
        hkBool writeHeaderSchemas,
        hkpConstraintQueryOut *out)
{
  __m128 *m_storage; // rbx
  unsigned __int8 m_contactPointPropertiesStriding; // r10
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
  int v20; // esi
  float v21; // xmm15_4
  __m128 *v22; // r13
  char *v23; // rdi
  __m128 v24; // xmm8
  __m128 v25; // xmm13
  __m128 v26; // xmm1
  __m128 v27; // xmm3
  __m128 v28; // xmm4
  __m128 v29; // xmm2
  __m128 v30; // xmm4
  __m128 v31; // xmm4
  __m128 v32; // xmm1
  __m128 m_quad; // xmm2
  __m128 v34; // xmm1
  __m128 v35; // xmm5
  __m128 v36; // xmm4
  __m128 v37; // xmm3
  __m128 v38; // xmm3
  __m128 v39; // xmm0
  __m128 v40; // xmm1
  __m128 v41; // xmm2
  unsigned __int8 v42; // cl
  unsigned __int16 EncodedFloat; // ax
  float v44; // xmm0_4
  float v45; // xmm3_4
  float v46; // xmm4_4
  float v47; // xmm3_4
  float v48; // xmm5_4
  float v49; // xmm1_4
  float v50; // xmm4_4
  float v51; // xmm3_4
  unsigned __int8 v52; // cl
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
  int v72; // ecx
  hkpSimpleContactConstraintDataInfo *v73; // rsi
  float v74; // xmm10_4
  __m128 v75; // xmm3
  float v76; // xmm4_4
  __m128 v77; // xmm6
  __m128 v78; // xmm1
  __m128 v79; // xmm2
  __m128 v80; // xmm3
  __m128 v81; // xmm11
  __m128 v82; // xmm0
  __m128 v83; // xmm5
  __m128 v84; // xmm5
  __m128 v85; // xmm2
  __m128 v86; // xmm3
  __m128 v87; // xmm5
  __int16 m_value; // dx
  __m128 v89; // xmm7
  __m128 v90; // xmm1
  __m128 v91; // xmm3
  __m128 v92; // xmm2
  __m128 v93; // xmm5
  float v94; // xmm0_4
  __m128 v95; // xmm5
  __m128 v96; // xmm3
  __m128 v97; // xmm1
  __m128 v98; // xmm4
  __m128 v99; // xmm15
  __m128 v100; // xmm0
  __m128 v101; // xmm2
  float v102; // xmm5_4
  __m128 v103; // xmm4
  __m128 v104; // xmm1
  __m128 v105; // xmm0
  __m128 v106; // xmm2
  __m128 v107; // xmm1
  __m128 v108; // xmm2
  __m128 v109; // xmm15
  __m128 v110; // xmm0
  __m128 v111; // xmm1
  __m128 v112; // xmm4
  int v113; // eax
  __m128 v114; // xmm2
  __m128 v115; // xmm2
  __m128 v116; // xmm2
  __m128 v117; // xmm1
  __m128 v118; // xmm2
  float v119; // xmm0_4
  __m128 v120; // xmm10
  __m128 *v121; // r11
  __m128 v122; // xmm4
  __m128 v123; // xmm15
  __m128 v124; // xmm7
  __m128 v125; // xmm4
  __m128 v126; // xmm15
  __m128 v127; // xmm2
  __m128 v128; // xmm6
  __m128 v129; // xmm3
  __m128 v130; // xmm2
  __m128 v131; // xmm2
  __m128 v132; // xmm3
  __m128 v133; // xmm1
  __m128 v134; // xmm3
  __m128 v135; // xmm2
  __m128 v136; // xmm1
  __m128 v137; // xmm1
  __m128 v138; // xmm0
  __m128 v139; // xmm1
  __m128 v140; // xmm2
  float v141; // xmm5_4
  __m128 v142; // xmm1
  __m128 v143; // xmm1
  __m128 v144; // xmm2
  __m128 v145; // xmm4
  __m128 v146; // xmm2
  __m128 v147; // xmm3
  __m128 v148; // xmm1
  __m128 v149; // xmm1
  __m128 v150; // xmm0
  __m128 v151; // xmm1
  __m128 v152; // xmm2
  __m128 v153; // xmm6
  __m128 *v154; // r9
  __m128 *v155; // rdx
  __m128 v156; // xmm1
  float v157; // xmm12_4
  __m128 v158; // xmm4
  __m128 v159; // xmm7
  __m128 v160; // xmm8
  __m128 v161; // xmm5
  __m128 v162; // xmm3
  __m128 v163; // xmm1
  __m128 v164; // xmm4
  __m128 v165; // xmm2
  float v166; // xmm14_4
  __m128 v167; // xmm5
  int v168; // r8d
  float v169; // xmm13_4
  __m128 v170; // xmm5
  hkpSimpleContactConstraintAtom *v171; // rax
  int i; // ecx
  __m128 v173; // xmm1
  __m128 v174; // xmm1
  __m128 v175; // xmm1
  __m128 v176; // xmm4
  __m128 v177; // xmm1
  __m128 v178; // xmm3
  __m128 v179; // xmm2
  __m128 v180; // xmm4
  __m128 m_storage_low; // xmm3
  __m128 v182; // xmm0
  __m128 v183; // xmm1
  __m128 v184; // xmm1
  __m128 v185; // xmm2
  __m128 v186; // xmm1
  __m128 v187; // xmm2
  __m128 v188; // xmm3
  __m128 v189; // xmm1
  int v190; // [rsp+20h] [rbp-E0h]
  int v191; // [rsp+38h] [rbp-C8h]
  float v192; // [rsp+40h] [rbp-C0h]
  __m128 v193; // [rsp+50h] [rbp-B0h]
  __m128 v194; // [rsp+50h] [rbp-B0h]
  __m128 *v195; // [rsp+60h] [rbp-A0h]
  __m128 v196; // [rsp+60h] [rbp-A0h]
  __m128 v197; // [rsp+70h] [rbp-90h]
  __m128 v198; // [rsp+70h] [rbp-90h]
  hkpSimpleContactConstraintDataInfo *p_m_info; // [rsp+80h] [rbp-80h]
  __m128 v200; // [rsp+80h] [rbp-80h]
  hkpSimpleContactConstraintDataInfo *v201; // [rsp+90h] [rbp-70h]
  float v202; // [rsp+90h] [rbp-70h]
  hkpSimpleContactConstraintAtom *v203; // [rsp+A0h] [rbp-60h]
  float v204; // [rsp+B0h] [rbp-50h]
  __m128 v205; // [rsp+C0h] [rbp-40h]
  __m128 v206; // [rsp+D0h] [rbp-30h]
  int m_numContactPoints; // [rsp+1C0h] [rbp+C0h]
  float v208; // [rsp+1C0h] [rbp+C0h]
  unsigned int v209; // [rsp+1C0h] [rbp+C0h]
  float v210; // [rsp+1C8h] [rbp+C8h]
  float v211; // [rsp+1C8h] [rbp+C8h]

  m_storage = (__m128 *)out->m_jacobianSchemas.m_storage;
  m_contactPointPropertiesStriding = atom->m_contactPointPropertiesStriding;
  v7 = in->m_bodyA.m_storage;
  v8 = in->m_bodyB.m_storage;
  v9 = atom + 1;
  m_numContactPoints = atom->m_numContactPoints;
  v10 = 0.0;
  v191 = m_contactPointPropertiesStriding;
  v203 = atom + 1;
  v11 = 0i64;
  v12 = 0i64;
  v11.m128_f32[0] = (float)m_numContactPoints;
  p_m_info = &atom->m_info;
  v13 = 0i64;
  v14 = (char *)&atom[1] + 32 * atom->m_numReservedContactPoints;
  v15 = _mm_shuffle_ps(v11, v11, 0);
  v16 = _mm_rcp_ps(v15);
  v205 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v16, v15)), v16);
  if ( writeHeaderSchemas.m_bool )
  {
    v17 = in->m_accumulatorBIndex.m_storage;
    v18 = in->m_accumulatorAIndex.m_storage;
    v19 = in->m_constraintInstance.m_storage;
    m_storage->m128_f32[0] = m_storage->m128_f32[0] + 0.00000011920929;
    m_storage->m128_i16[2] = v18;
    m_storage->m128_i16[3] = v17;
    m_storage->m128_i8[0] = 1;
    m_storage->m128_i8[1] = m_contactPointPropertiesStriding;
    m_storage->m128_u64[1] = (unsigned __int64)v14;
    m_storage[1].m128_u64[0] = (unsigned __int64)v19;
    m_storage += 2;
  }
  v20 = 0;
  v21 = 0.0;
  v201 = &v9->m_info;
  v22 = (__m128 *)&v9->m_info;
  v23 = v14 + 19;
  do
  {
    v24 = *v22;
    v25 = v22[-1];
    v210 = in->m_virtMassFactor.m_storage;
    v195 = m_storage;
    v190 = *v23 & 2;
    v26 = _mm_sub_ps(v25, v7->m_scratch3.m_quad);
    v27 = _mm_sub_ps(v25, v8->m_scratch3.m_quad);
    v28 = _mm_shuffle_ps(v24, v24, 201);
    *m_storage = *v22;
    v29 = _mm_mul_ps(v28, v27);
    v30 = _mm_sub_ps(_mm_mul_ps(v28, v26), _mm_mul_ps(_mm_shuffle_ps(v26, v26, 201), v24));
    v31 = _mm_shuffle_ps(v30, v30, 201);
    v32 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v27, v27, 201), v24), v29);
    m_quad = v7->m_invMasses.m_quad;
    v34 = _mm_shuffle_ps(v32, v32, 201);
    v35 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v31, v31, 85), v7->m_scratch1.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v31, v31, 0), v7->m_scratch0.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v31, v31, 170), v7->m_scratch2.m_quad));
    v36 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v34, v34, 85), v8->m_scratch1.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v34, v34, 0), v8->m_scratch0.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v34, v34, 170), v8->m_scratch2.m_quad));
    v37 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v36, v36), v8->m_invMasses.m_quad), _mm_mul_ps(_mm_mul_ps(v35, v35), m_quad));
    v38 = _mm_shuffle_ps(
            v37,
            _mm_unpackhi_ps(v37, _mm_max_ps(_mm_add_ps(m_quad, v8->m_invMasses.m_quad), (__m128)xmmword_141A712D0)),
            196);
    v39 = _mm_add_ps(_mm_shuffle_ps(v38, v38, 78), v38);
    v40 = _mm_add_ps(_mm_shuffle_ps(v39, v39, 177), v39);
    v41 = _mm_rcp_ps(v40);
    m_storage[2] = _mm_shuffle_ps(v36, _mm_unpackhi_ps(v36, v40), 196);
    v42 = *(v23 - 3);
    m_storage[1] = _mm_shuffle_ps(
                     v35,
                     _mm_unpackhi_ps(
                       v35,
                       _mm_mul_ps(
                         _mm_shuffle_ps((__m128)LODWORD(v210), (__m128)LODWORD(v210), 0),
                         _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v41, v40)), v41))),
                     196);
    EncodedFloat = hkUFloat8::getEncodedFloat(v42);
    if ( EncodedFloat )
      LODWORD(v44) = (EncodedFloat + 243712) << 12;
    else
      v44 = 0.0;
    v21 = v21 + *(float *)(v23 - 19);
    v10 = v10 + v44;
    if ( (*v23 & 8) != 0 )
      v45 = FLOAT_1_8446726e19;
    else
      v45 = v22->m128_f32[3];
    v46 = *(float *)(v23 + 5);
    v47 = v45 - v46;
    v192 = HK_CONTACT_LINEAR_ERROR_RECOVERY_VELOCITY * in->m_frameDeltaTime.m_storage;
    v48 = COERCE_FLOAT(*(_DWORD *)(v23 - 15) ^ _xmm[0]) - v47;
    v49 = fminf(COERCE_FLOAT(LODWORD(HK_CONTACT_EXPONENTIAL_ERROR_RECOVERY_VELOCITY) ^ _xmm[0]) * v46, v192);
    v50 = v46 + v49;
    v51 = v47 - v49;
    if ( v48 > (float)((float)(v49 * 2.0) + v192) )
    {
      v50 = v50 - v48;
      v51 = v51 + v48;
    }
    v12 = _mm_add_ps(v12, v25);
    v13 = _mm_add_ps(v13, v24);
    v197 = v12;
    v193 = v13;
    *(float *)(v23 + 5) = fminf(v50, -0.00000011920929);
    m_storage->m128_f32[3] = COERCE_FLOAT(LODWORD(v51) ^ _xmm[0]) * in->m_rhsFactor.m_storage;
    if ( v190 )
    {
      v56 = m_storage[-1];
      v57 = v8->m_invMasses.m_quad;
      v58 = v7->m_invMasses.m_quad;
      v59 = m_storage[-3];
      v60 = _mm_mul_ps(_mm_mul_ps(m_storage[2], v56), v57);
      v61 = _mm_mul_ps(_mm_mul_ps(m_storage[1], m_storage[-2]), v58);
      m_storage += 4;
      v62 = _mm_mul_ps(v59, m_storage[-4]);
      v63 = _mm_shuffle_ps(v56, v56, 255);
      v64 = _mm_add_ps(
              _mm_add_ps(v61, v60),
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v58, v58, 255), v62), _mm_mul_ps(_mm_shuffle_ps(v57, v57, 255), v62)));
      v65 = _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v64, v64, 85), _mm_shuffle_ps(v64, v64, 0)),
                _mm_shuffle_ps(v64, v64, 170)),
              _mm_shuffle_ps((__m128)0x3F7D70A4u, (__m128)0x3F7D70A4u, 0));
      v66 = _mm_shuffle_ps(m_storage[-2], m_storage[-2], 255);
      v67 = _mm_sub_ps(_mm_mul_ps(v66, v63), _mm_mul_ps(v65, v65));
      v68 = _mm_rcp_ps(v67);
      v69 = _mm_mul_ps(
              _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v68, v67)), v68),
              _mm_shuffle_ps(
                (__m128)LODWORD(in->m_virtMassFactor.m_storage),
                (__m128)LODWORD(in->m_virtMassFactor.m_storage),
                0));
      m_storage[-5] = _mm_shuffle_ps(v56, _mm_unpackhi_ps(v56, _mm_mul_ps(v66, v69)), 196);
      v70 = _mm_unpackhi_ps(m_storage[-2], _mm_mul_ps(v63, v69));
      v13 = v193;
      v71 = _mm_shuffle_ps(m_storage[-2], v70, 196);
      v70.m128_f32[0] = 0.0 - v65.m128_f32[0];
      v12 = v197;
      m_storage[-2] = v71;
      m_storage[-1].m128_f32[0] = v70.m128_f32[0] * v69.m128_f32[0];
      m_storage[-7].m128_f32[0] = m_storage[-7].m128_f32[0] + 0.00000011920929;
      m_storage[-7].m128_i8[0] = 24;
    }
    else
    {
      v52 = *(v23 - 1);
      v53 = (float *)m_storage;
      v54 = m_storage->m128_f32[0] + 0.00000011920929;
      m_storage += 3;
      m_storage[-3].m128_f32[0] = v54;
      m_storage[-3].m128_i8[0] = 20;
      if ( v52 )
      {
        *v53 = *v53 + 0.00000011920929;
        *(_BYTE *)v53 = 22;
        v55 = hkUFloat8::getEncodedFloat(v52);
        if ( v55 )
          v195[2].m128_i32[3] = (v55 + 243712) << 12;
        else
          v195[2].m128_i32[3] = 0;
      }
    }
    ++v20;
    v22 += 2;
    v23 += v191;
    v72 = m_numContactPoints;
  }
  while ( v20 < m_numContactPoints );
  v73 = p_m_info;
  v74 = _mm_shuffle_ps((__m128)COERCE_UNSIGNED_INT(v10 * v21), (__m128)COERCE_UNSIGNED_INT(v10 * v21), 0).m128_f32[0]
      * v205.m128_f32[0];
  v204 = v74;
  if ( v74 <= 0.0 )
    goto LABEL_40;
  v75 = _mm_mul_ps(v13, v13);
  v76 = (float)(_mm_shuffle_ps(v75, v75, 85).m128_f32[0] + _mm_shuffle_ps(v75, v75, 0).m128_f32[0])
      + _mm_shuffle_ps(v75, v75, 170).m128_f32[0];
  if ( (float)((float)(v205.m128_f32[0] * v205.m128_f32[0]) * v76) <= _mm_shuffle_ps(
                                                                        (__m128)LODWORD(FLOAT_0_99989998),
                                                                        (__m128)LODWORD(FLOAT_0_99989998),
                                                                        0).m128_f32[0] )
  {
    if ( v76 <= _mm_shuffle_ps((__m128)0x3DCCCCCDu, (__m128)0x3DCCCCCDu, 0).m128_f32[0] )
    {
      v194 = *(__m128 *)&v201->m_flags;
      v77 = *(__m128 *)&v201->m_flags;
      v80 = _mm_mul_ps(v77, v77);
      if ( (float)((float)(_mm_shuffle_ps(v80, v80, 85).m128_f32[0] + _mm_shuffle_ps(v80, v80, 0).m128_f32[0])
                 + _mm_shuffle_ps(v80, v80, 170).m128_f32[0]) >= _mm_shuffle_ps(
                                                                   (__m128)LODWORD(FLOAT_0_89999998),
                                                                   (__m128)LODWORD(FLOAT_0_89999998),
                                                                   0).m128_f32[0] )
        goto LABEL_27;
      v77 = direction.m_quad;
      v74 = 0.0;
      v204 = 0.0;
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
                _mm_cmple_ps(v78, (__m128)0i64),
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v79, v78), v79)),
                  _mm_mul_ps(*(__m128 *)_xmm, v79))));
    }
  }
  else
  {
    v77 = *(__m128 *)&v201->m_flags;
  }
  v194 = v77;
LABEL_27:
  v81 = _mm_shuffle_ps(v77, v77, 201);
  v82 = *(&transform.m_quad + p_m_info->m_biNormalAxis);
  v83 = _mm_sub_ps(_mm_mul_ps(v81, v82), _mm_mul_ps(_mm_shuffle_ps(v82, v82, 201), v77));
  v84 = _mm_shuffle_ps(v83, v83, 201);
  v85 = _mm_mul_ps(v84, v84);
  if ( (float)((float)(_mm_shuffle_ps(v85, v85, 0).m128_f32[0] + _mm_shuffle_ps(v85, v85, 85).m128_f32[0])
             + _mm_shuffle_ps(v85, v85, 170).m128_f32[0]) <= _mm_shuffle_ps((__m128)0x3DCCCCCDu, (__m128)0x3DCCCCCDu, 0).m128_f32[0] )
  {
    v86 = (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)v77, 1u), 1u);
    v72 = m_numContactPoints;
    p_m_info->m_biNormalAxis = (unsigned __int8)hkVector4Comparison_maskToFirstIndex[_mm_movemask_ps(
                                                                                       _mm_and_ps(
                                                                                         _mm_cmple_ps(
                                                                                           v86,
                                                                                           _mm_min_ps(
                                                                                             _mm_shuffle_ps(
                                                                                               v86,
                                                                                               v86,
                                                                                               170),
                                                                                             _mm_min_ps(
                                                                                               _mm_shuffle_ps(
                                                                                                 v86,
                                                                                                 v86,
                                                                                                 85),
                                                                                               _mm_shuffle_ps(
                                                                                                 v86,
                                                                                                 v86,
                                                                                                 0)))),
                                                                                         (__m128)xmmword_141A9E880))];
    *(_QWORD *)&p_m_info->m_data[2] = 0i64;
    *(_DWORD *)&p_m_info->m_rhsRolling[0].m_value = 0;
    v87 = _mm_sub_ps(
            _mm_mul_ps(v81, *(&transform.m_quad + p_m_info->m_biNormalAxis)),
            _mm_mul_ps(
              _mm_shuffle_ps(
                *(&transform.m_quad + p_m_info->m_biNormalAxis),
                *(&transform.m_quad + p_m_info->m_biNormalAxis),
                201),
              v77));
    v84 = _mm_shuffle_ps(v87, v87, 201);
  }
  m_value = p_m_info->m_rollingFrictionMultiplier.m_value;
  v89 = _mm_mul_ps(v12, v205);
  v90 = _mm_mul_ps(v84, v84);
  v198 = v89;
  v91 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v90, v90, 85), _mm_shuffle_ps(v90, v90, 0)), _mm_shuffle_ps(v90, v90, 170));
  v92 = _mm_rsqrt_ps(v91);
  v200 = _mm_mul_ps(
           v84,
           _mm_andnot_ps(
             _mm_cmple_ps(v91, (__m128)0i64),
             _mm_mul_ps(
               _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v92, v91), v92)),
               _mm_mul_ps(*(__m128 *)_xmm, v92))));
  v196 = _mm_shuffle_ps(v200, v200, 201);
  v93 = _mm_sub_ps(_mm_mul_ps(v196, v77), _mm_mul_ps(v81, v200));
  v94 = _mm_shuffle_ps(
          (__m128)(unsigned int)(v73->m_rollingFrictionMultiplier.m_value << 16),
          (__m128)(unsigned int)(v73->m_rollingFrictionMultiplier.m_value << 16),
          0).m128_f32[0]
      * v74;
  v95 = _mm_shuffle_ps(v93, v93, 201);
  v206 = v95;
  if ( v94 > 0.0 )
  {
    v202 = v94 * in->m_invNumStepsTimesMicroSteps.m_storage;
    LODWORD(v208) = v73->m_rhsRolling[0].m_value << 16;
    v96 = _mm_shuffle_ps(
            (__m128)LODWORD(in->m_virtMassFactor.m_storage),
            (__m128)LODWORD(in->m_virtMassFactor.m_storage),
            0);
    v211 = in->m_virtMassFactor.m_storage;
    v97 = _mm_mul_ps(_mm_shuffle_ps(v95, v95, 170), v7->m_scratch2.m_quad);
    v98 = _mm_mul_ps(_mm_shuffle_ps(v95, v95, 0), v7->m_scratch0.m_quad);
    v99 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
    v100 = _mm_shuffle_ps(v95, v95, 85);
    v101 = _mm_xor_ps(v99, v95);
    v102 = in->m_frictionRhsFactor.m_storage;
    v103 = _mm_add_ps(_mm_add_ps(v98, _mm_mul_ps(v100, v7->m_scratch1.m_quad)), v97);
    v104 = _mm_add_ps(
             _mm_add_ps(
               _mm_mul_ps(_mm_shuffle_ps(v101, v101, 0), v8->m_scratch0.m_quad),
               _mm_mul_ps(_mm_shuffle_ps(v101, v101, 85), v8->m_scratch1.m_quad)),
             _mm_mul_ps(_mm_shuffle_ps(v101, v101, 170), v8->m_scratch2.m_quad));
    v105 = _mm_mul_ps(_mm_mul_ps(v103, v103), v7->m_invMasses.m_quad);
    m_storage[1] = v104;
    v106 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v104, v104), v8->m_invMasses.m_quad), v105);
    v107 = _mm_add_ps(
             _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v106, v106, 85), _mm_shuffle_ps(v106, v106, 0)),
               _mm_shuffle_ps(v106, v106, 170)),
             *(__m128 *)&epsilon);
    v108 = _mm_rcp_ps(v107);
    v109 = _mm_xor_ps(v99, v200);
    v110 = _mm_unpackhi_ps(v103, _mm_mul_ps(v96, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v108, v107)), v108)));
    v111 = _mm_mul_ps(_mm_shuffle_ps(v200, v200, 170), v7->m_scratch2.m_quad);
    *m_storage = _mm_shuffle_ps(v103, v110, 196);
    m_storage[1].m128_f32[3] = v102 * v208;
    v112 = _mm_add_ps(
             _mm_add_ps(
               _mm_mul_ps(_mm_shuffle_ps(v200, v200, 0), v7->m_scratch0.m_quad),
               _mm_mul_ps(_mm_shuffle_ps(v200, v200, 85), v7->m_scratch1.m_quad)),
             v111);
    v113 = v73->m_rhsRolling[1].m_value;
    v114 = _mm_mul_ps(_mm_shuffle_ps(v109, v109, 0), v8->m_scratch0.m_quad);
    m_storage[4].m128_u64[1] = (unsigned __int64)v73;
    m_storage += 6;
    v115 = _mm_add_ps(
             _mm_add_ps(v114, _mm_mul_ps(_mm_shuffle_ps(v109, v109, 85), v8->m_scratch1.m_quad)),
             _mm_mul_ps(_mm_shuffle_ps(v109, v109, 170), v8->m_scratch2.m_quad));
    m_storage[-3] = v115;
    v116 = _mm_add_ps(
             _mm_mul_ps(_mm_mul_ps(v115, v115), v8->m_invMasses.m_quad),
             _mm_mul_ps(_mm_mul_ps(v112, v112), v7->m_invMasses.m_quad));
    v117 = _mm_add_ps(
             _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v116, v116, 85), _mm_shuffle_ps(v116, v116, 0)),
               _mm_shuffle_ps(v116, v116, 170)),
             *(__m128 *)&epsilon);
    v118 = _mm_rcp_ps(v117);
    m_storage[-4] = _mm_shuffle_ps(
                      v112,
                      _mm_unpackhi_ps(
                        v112,
                        _mm_mul_ps(
                          _mm_shuffle_ps((__m128)LODWORD(v211), (__m128)LODWORD(v211), 0),
                          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v118, v117)), v118))),
                      196);
    m_storage[-2].m128_f32[0] = v202;
    m_storage[-1].m128_i16[0] = m_value;
    v110.m128_f32[0] = m_storage[-6].m128_f32[0] + 0.00000011920929;
    m_storage[-3].m128_f32[3] = v102 * COERCE_FLOAT(v113 << 16);
    v95 = v206;
    m_storage[-6].m128_i32[0] = v110.m128_i32[0];
    m_storage[-6].m128_i8[0] = 28;
  }
  v119 = in->m_virtMassFactor.m_storage;
  v120 = v7->m_invMasses.m_quad;
  *m_storage = v95;
  v121 = m_storage;
  v122 = v89;
  v123 = v89;
  v124 = v8->m_invMasses.m_quad;
  v125 = _mm_sub_ps(v122, v7->m_scratch3.m_quad);
  v126 = _mm_sub_ps(v123, v8->m_scratch3.m_quad);
  v127 = _mm_shuffle_ps(v95, v95, 201);
  v128 = _mm_max_ps(_mm_add_ps(v120, v124), (__m128)xmmword_141A712D0);
  v129 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v126, v126, 201), v95), _mm_mul_ps(v127, v126));
  v130 = _mm_sub_ps(_mm_mul_ps(v127, v125), _mm_mul_ps(_mm_shuffle_ps(v125, v125, 201), v95));
  v131 = _mm_shuffle_ps(v130, v130, 201);
  v132 = _mm_shuffle_ps(v129, v129, 201);
  m_storage[1] = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v131, v131, 0), v7->m_scratch0.m_quad),
                     _mm_mul_ps(_mm_shuffle_ps(v131, v131, 85), v7->m_scratch1.m_quad)),
                   _mm_mul_ps(_mm_shuffle_ps(v131, v131, 170), v7->m_scratch2.m_quad));
  v133 = _mm_add_ps(
           _mm_add_ps(
             _mm_mul_ps(_mm_shuffle_ps(v132, v132, 0), v8->m_scratch0.m_quad),
             _mm_mul_ps(_mm_shuffle_ps(v132, v132, 85), v8->m_scratch1.m_quad)),
           _mm_mul_ps(_mm_shuffle_ps(v132, v132, 170), v8->m_scratch2.m_quad));
  v134 = _mm_shuffle_ps((__m128)LODWORD(v119), (__m128)LODWORD(v119), 0);
  m_storage[2] = v133;
  v135 = v133;
  v136 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v133, v133), v124), _mm_mul_ps(_mm_mul_ps(m_storage[1], m_storage[1]), v120));
  v137 = _mm_shuffle_ps(v136, _mm_unpackhi_ps(v136, v128), 196);
  v138 = _mm_add_ps(_mm_shuffle_ps(v137, v137, 78), v137);
  v139 = _mm_add_ps(_mm_shuffle_ps(v138, v138, 177), v138);
  m_storage[2] = _mm_shuffle_ps(v135, _mm_unpackhi_ps(v135, v139), 196);
  v140 = _mm_rcp_ps(v139);
  v138.m128_f32[0] = in->m_frictionRhsFactor.m_storage * v73->m_data[2];
  v141 = in->m_frictionRhsFactor.m_storage * v73->m_data[3];
  m_storage[1] = _mm_shuffle_ps(
                   m_storage[1],
                   _mm_unpackhi_ps(
                     m_storage[1],
                     _mm_mul_ps(v134, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v140, v139)), v140))),
                   196);
  v139.m128_i32[0] = LODWORD(in->m_virtMassFactor.m_storage);
  m_storage->m128_i32[3] = v138.m128_i32[0];
  v209 = v139.m128_i32[0];
  m_storage[3] = v200;
  v142 = _mm_sub_ps(_mm_mul_ps(v196, v125), _mm_mul_ps(_mm_shuffle_ps(v125, v125, 201), v200));
  v143 = _mm_shuffle_ps(v142, v142, 201);
  v144 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v126, v126, 201), v200), _mm_mul_ps(v196, v126));
  v145 = _mm_add_ps(
           _mm_add_ps(
             _mm_mul_ps(_mm_shuffle_ps(v143, v143, 0), v7->m_scratch0.m_quad),
             _mm_mul_ps(_mm_shuffle_ps(v143, v143, 85), v7->m_scratch1.m_quad)),
           _mm_mul_ps(_mm_shuffle_ps(v143, v143, 170), v7->m_scratch2.m_quad));
  v146 = _mm_shuffle_ps(v144, v144, 201);
  v147 = _mm_add_ps(
           _mm_add_ps(
             _mm_mul_ps(_mm_shuffle_ps(v146, v146, 0), v8->m_scratch0.m_quad),
             _mm_mul_ps(_mm_shuffle_ps(v146, v146, 85), v8->m_scratch1.m_quad)),
           _mm_mul_ps(_mm_shuffle_ps(v146, v146, 170), v8->m_scratch2.m_quad));
  v148 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v147, v147), v124), _mm_mul_ps(_mm_mul_ps(v145, v145), v120));
  v149 = _mm_shuffle_ps(v148, _mm_unpackhi_ps(v148, v128), 196);
  v150 = _mm_add_ps(_mm_shuffle_ps(v149, v149, 78), v149);
  v151 = _mm_add_ps(_mm_shuffle_ps(v150, v150, 177), v150);
  v152 = _mm_rcp_ps(v151);
  m_storage[5] = _mm_shuffle_ps(v147, _mm_unpackhi_ps(v147, v151), 196);
  m_storage[4] = _mm_shuffle_ps(
                   v145,
                   _mm_unpackhi_ps(
                     v145,
                     _mm_mul_ps(
                       _mm_shuffle_ps((__m128)v209, (__m128)v209, 0),
                       _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v152, v151)), v152))),
                   196);
  m_storage[3].m128_f32[3] = v141;
  v153 = m_storage[2];
  v154 = m_storage + 6;
  v155 = m_storage;
  v156 = _mm_mul_ps(m_storage[3], *m_storage);
  v157 = v204 * in->m_invNumStepsTimesMicroSteps.m_storage;
  v158 = _mm_add_ps(
           _mm_add_ps(
             _mm_mul_ps(_mm_shuffle_ps(v120, v120, 255), v156),
             _mm_mul_ps(_mm_shuffle_ps(v124, v124, 255), v156)),
           _mm_add_ps(
             _mm_mul_ps(_mm_mul_ps(m_storage[4], m_storage[1]), v120),
             _mm_mul_ps(_mm_mul_ps(m_storage[5], v153), v124)));
  v159 = _mm_shuffle_ps(v153, v153, 255);
  v160 = _mm_mul_ps(
           _mm_add_ps(
             _mm_add_ps(_mm_shuffle_ps(v158, v158, 85), _mm_shuffle_ps(v158, v158, 0)),
             _mm_shuffle_ps(v158, v158, 170)),
           _mm_shuffle_ps((__m128)(unsigned int)FLOAT_1_0, (__m128)(unsigned int)FLOAT_1_0, 0));
  v161 = _mm_shuffle_ps(m_storage[5], m_storage[5], 255);
  v162 = _mm_sub_ps(_mm_mul_ps(v161, v159), _mm_mul_ps(v160, v160));
  v163 = _mm_rcp_ps(v162);
  v164 = _mm_mul_ps(
           _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v163, v162)), v163),
           _mm_shuffle_ps(
             (__m128)LODWORD(in->m_virtMassFactor.m_storage),
             (__m128)LODWORD(in->m_virtMassFactor.m_storage),
             0));
  m_storage[2] = _mm_shuffle_ps(v153, _mm_unpackhi_ps(v153, _mm_mul_ps(v164, v161)), 196);
  m_storage[5] = _mm_shuffle_ps(m_storage[5], _mm_unpackhi_ps(m_storage[5], _mm_mul_ps(v164, v159)), 196);
  v165 = 0i64;
  v150.m128_f32[0] = m_storage->m128_f32[0] + 0.00000011920929;
  m_storage[6].m128_f32[1] = v157;
  m_storage[6].m128_u64[1] = (unsigned __int64)v73;
  m_storage->m128_i32[0] = v150.m128_i32[0];
  m_storage->m128_i8[0] = 26;
  v166 = (float)(0.0 - v160.m128_f32[0]) * v164.m128_f32[0];
  m_storage[6].m128_f32[0] = v166;
  m_storage += 7;
  if ( v72 > 1 )
  {
    v167 = _mm_shuffle_ps((__m128)LODWORD(v73->m_contactRadius), (__m128)LODWORD(v73->m_contactRadius), 0);
    if ( (v73->m_flags & 4) != 0 )
    {
      v168 = v72 - 1;
      LODWORD(v169) = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_000001), (__m128)LODWORD(FLOAT_0_000001), 0).m128_u32[0];
      while ( 1 )
      {
        v170 = v165;
        v171 = v203;
        for ( i = v168; i >= 0; v170 = _mm_add_ps(v170, v178) )
        {
          v173 = *(__m128 *)&v171->m_type.m_storage;
          v171 = (hkpSimpleContactConstraintAtom *)((char *)v171 + 32);
          --i;
          v174 = _mm_sub_ps(v173, v198);
          v175 = _mm_mul_ps(v174, v174);
          v176 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v175, v175, 85), _mm_shuffle_ps(v175, v175, 0)),
                   _mm_shuffle_ps(v175, v175, 170));
          v177 = _mm_rsqrt_ps(v176);
          v178 = _mm_andnot_ps(
                   _mm_cmple_ps(v176, v165),
                   _mm_mul_ps(
                     _mm_mul_ps(
                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v177, v176), v177)),
                       _mm_mul_ps(*(__m128 *)_xmm, v177)),
                     v176));
          v165 = 0i64;
        }
        v167 = _mm_mul_ps(v170, v205);
        if ( v167.m128_f32[0] < v169 )
          break;
        v73->m_flags &= ~4u;
        if ( (v73->m_flags & 4) == 0 )
          goto LABEL_38;
      }
    }
    else
    {
LABEL_38:
      v179 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v194);
      v180 = _mm_add_ps(
               _mm_add_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v194, v194, 85), v7->m_scratch1.m_quad),
                 _mm_mul_ps(_mm_shuffle_ps(v194, v194, 0), v7->m_scratch0.m_quad)),
               _mm_mul_ps(_mm_shuffle_ps(v194, v194, 170), v7->m_scratch2.m_quad));
      m_storage_low = (__m128)LODWORD(in->m_virtMassFactor.m_storage);
      v182 = _mm_mul_ps(_mm_shuffle_ps(v179, v179, 0), v8->m_scratch0.m_quad);
      v183 = _mm_mul_ps(_mm_shuffle_ps(v179, v179, 85), v8->m_scratch1.m_quad);
      *v154 = v180;
      v184 = _mm_add_ps(_mm_add_ps(v183, v182), _mm_mul_ps(_mm_shuffle_ps(v179, v179, 170), v8->m_scratch2.m_quad));
      v154[1] = v184;
      v185 = _mm_add_ps(
               _mm_mul_ps(_mm_mul_ps(v184, v184), v8->m_invMasses.m_quad),
               _mm_mul_ps(_mm_mul_ps(v180, v180), v7->m_invMasses.m_quad));
      v186 = _mm_add_ps(
               _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v185, v185, 85), _mm_shuffle_ps(v185, v185, 0)),
                 _mm_shuffle_ps(v185, v185, 170)),
               *(__m128 *)&epsilon);
      v187 = _mm_rcp_ps(v186);
      v188 = _mm_mul_ps(
               _mm_shuffle_ps(m_storage_low, m_storage_low, 0),
               _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v187, v186)), v187));
      v189 = _mm_rcp_ps(v167);
      v182.m128_f32[0] = v73->m_data[1] * in->m_frictionRhsFactor.m_storage;
      *v154 = _mm_shuffle_ps(v180, _mm_unpackhi_ps(v180, v188), 196);
      v121[7].m128_i32[3] = v182.m128_i32[0];
      *v154 = _mm_shuffle_ps(
                *v154,
                _mm_unpackhi_ps(
                  *v154,
                  _mm_mul_ps(
                    _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v167, v189)), v189),
                    _mm_shuffle_ps(*v154, *v154, 255))),
                196);
      v182.m128_i32[0] = v155->m128_i32[0];
      v155[8].m128_f32[0] = v166;
      v155[9].m128_u64[0] = (unsigned __int64)v73;
      v155[8].m128_f32[1] = v157;
      v155[8].m128_i32[2] = v167.m128_i32[0];
      v155->m128_f32[0] = v182.m128_f32[0] + 0.00000011920929;
      v155->m128_i8[0] = 27;
      m_storage = v155 + 10;
    }
    LODWORD(v73->m_contactRadius) = v167.m128_i32[0];
  }
LABEL_40:
  out->m_jacobianSchemas.m_storage = (hkpJacobianSchema *)m_storage;
}
  }
LABEL_40:
  out->m_jacobianSchemas.m_storage = (hkpJacobianSchema *)m_storage;
}

// File Line: 470
// RVA: 0xDD8570
void __fastcall hkSimpleContactConstraintDataAddALittleSurfaceViscosity(hkpSimpleContactConstraintDataInfo *infoExt)
{
  *(_QWORD *)&infoExt->m_data[2] = 0i64;
  infoExt->m_data[1] = 0.0;
  *(_DWORD *)&infoExt->m_rhsRolling[0].m_value = 0;
}

