// File Line: 28
// RVA: 0x132CA40
void __fastcall hkVehicleFrictionDescriptionInitValues(hkpVehicleFrictionDescription::Cinfo *ci, hkpVehicleFrictionDescription *out, __int64 a3, __int64 a4, __int64 a5, __int64 a6, __int64 a7, __int64 a8, __int64 a9, __int64 a10, __int64 a11, __int64 a12, __int64 a13, __int64 a14, __int64 a15, __int64 a16, __int64 a17, __int64 a18, __int64 a19, __int64 a20, __int64 a21)
{
  hkpVehicleFrictionDescription::Cinfo *v21; // r8
  float v22; // xmm0_4
  float v23; // xmm3_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  __m128 v26; // xmm1
  __m128 v27; // xmm2
  float v28; // xmm4_4
  float v29; // xmm3_4
  signed __int64 v30; // rbp
  hkpVehicleFrictionDescription::Cinfo *v31; // r9
  signed __int64 v32; // rcx
  signed __int64 v33; // r9
  __m128 v34; // xmm4
  __m128 v35; // xmm7
  float v36; // xmm13_4
  __m128 v37; // xmm9
  __m128 v38; // xmm10
  __m128 v39; // xmm11
  __m128 v40; // xmm12
  __m128 v41; // xmm5
  signed __int64 v42; // rax
  __m128 v43; // xmm1
  __m128 v44; // xmm2
  __m128 v45; // xmm2
  __m128 v46; // xmm3
  float *v47; // rsi
  _DWORD *v48; // r14
  float v49; // xmm6_4
  float v50; // xmm7_4
  signed __int64 v51; // rbx
  signed __int64 v52; // rdi
  float v53; // xmm10_4
  float v54; // xmm0_4
  int v55; // [rsp+C4h] [rbp+Ch]
  int v56[38]; // [rsp+C8h] [rbp+10h]

  out->m_chassisMassInv = ci->m_chassisMassInv;
  out->m_axleDescr[0].m_wheelRadius = ci->m_wheelRadius[0];
  v21 = ci;
  out->m_axleDescr[1].m_wheelRadius = ci->m_wheelRadius[1];
  v22 = 1.0 / ci->m_wheelRadius[0];
  out->m_axleDescr[0].m_wheelRadiusInv = v22;
  v23 = 1.0 / ci->m_wheelRadius[1];
  out->m_axleDescr[1].m_wheelRadiusInv = v23;
  v24 = ci->m_wheelAxleAngularInertia[0] * v22;
  out->m_axleDescr[0].m_wheelSurfaceInertia = v24;
  v25 = ci->m_wheelAxleAngularInertia[1] * v23;
  out->m_axleDescr[0].m_wheelSurfaceInertiaInv = 1.0 / v24;
  out->m_axleDescr[1].m_wheelSurfaceInertia = v25;
  out->m_axleDescr[1].m_wheelSurfaceInertiaInv = 1.0 / v25;
  v26 = _mm_mul_ps(ci->m_wheelPosition[1].m_quad, ci->m_directionFront.m_quad);
  v27 = _mm_mul_ps(ci->m_directionFront.m_quad, ci->m_wheelPosition[0].m_quad);
  v28 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v27, v27, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v27, v27, 0)))
      + COERCE_FLOAT(_mm_shuffle_ps(v27, v27, 170));
  v29 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v26, v26, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v26, v26, 0)))
      + COERCE_FLOAT(_mm_shuffle_ps(v26, v26, 170));
  v26.m128_i32[0] = (unsigned int)(2 * COERCE_SIGNED_INT(v28 - v29)) >> 1;
  LODWORD(out->m_wheelDistance) = v26.m128_i32[0];
  out->m_axleDescr[0].m_wheelDownForceFactor = 1.0 - ci->m_frictionEqualizer;
  out->m_axleDescr[0].m_wheelDownForceSumFactor = COERCE_FLOAT(2
                                                             * (COERCE_UNSIGNED_INT((float)(1.0 / v26.m128_f32[0]) * v29) ^ _xmm[0]) >> 1)
                                                * ci->m_frictionEqualizer;
  out->m_axleDescr[1].m_wheelDownForceFactor = 1.0 - ci->m_frictionEqualizer;
  v26.m128_f32[0] = COERCE_FLOAT((unsigned int)(2 * COERCE_SIGNED_INT((float)(1.0 / v26.m128_f32[0]) * v28)) >> 1)
                  * ci->m_frictionEqualizer;
  v30 = 0i64;
  v31 = ci;
  v32 = 0i64;
  v33 = (char *)v31 - (char *)v56;
  LODWORD(out->m_axleDescr[1].m_wheelDownForceSumFactor) = v26.m128_i32[0];
  v34 = v21->m_directionRight.m_quad;
  v35 = v21->m_directionUp.m_quad;
  v36 = out->m_chassisMassInv;
  v37 = v21->m_chassisCenterOfMass.m_quad;
  v38 = v21->m_chassisFrictionInertiaInv.m_col1.m_quad;
  v39 = v21->m_chassisFrictionInertiaInv.m_col0.m_quad;
  v40 = v21->m_chassisFrictionInertiaInv.m_col2.m_quad;
  v41 = _mm_shuffle_ps(v34, v34, 201);
  do
  {
    v42 = v33 + 4 * v32++;
    v21 = (hkpVehicleFrictionDescription::Cinfo *)((char *)v21 + 16);
    v43 = _mm_add_ps(
            _mm_mul_ps(
              _mm_shuffle_ps(
                (__m128)(unsigned int)(*(_DWORD *)((char *)&a21 + v42 + 4) ^ _xmm[0]),
                (__m128)(unsigned int)(*(_DWORD *)((char *)&a21 + v42 + 4) ^ _xmm[0]),
                0),
              v35),
            _mm_sub_ps(*(__m128 *)&v21[-1].m_wheelRadius[1], v37));
    v44 = _mm_sub_ps(_mm_mul_ps(v41, v43), _mm_mul_ps(_mm_shuffle_ps(v43, v43, 201), v34));
    v45 = _mm_shuffle_ps(v44, v44, 201);
    v46 = _mm_mul_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v45, v45, 0), v39), _mm_mul_ps(_mm_shuffle_ps(v45, v45, 85), v38)),
              _mm_mul_ps(_mm_shuffle_ps(v45, v45, 170), v40)),
            v45);
    *((float *)&v55 + v32) = (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v46, v46, 85))
                                           + COERCE_FLOAT(_mm_shuffle_ps(v46, v46, 0)))
                                   + COERCE_FLOAT(_mm_shuffle_ps(v46, v46, 170)))
                           + v36;
  }
  while ( v32 < 2 );
  v47 = &out->m_axleDescr[0].m_wheelChassisMassRatio;
  v48 = (_DWORD *)&out->m_axleDescr[0].m_frictionCircleYtab[15];
  do
  {
    v49 = *(float *)&v56[v30] * *(v47 - 2);
    *v47 = v49;
    v50 = v49 * 0.0625;
    *(v47 - 3) = v49 * 0.0625;
    v51 = (signed __int64)(v47 - 20);
    v52 = 15i64;
    v53 = powf(1.0 / (float)(v49 * 0.0625), 0.06666667);
    *(v47 - 4) = v53;
    do
    {
      v54 = powf(1.0 - v50, 1.0 / v49);
      v51 += 4i64;
      v50 = v50 * v53;
      *(float *)(v51 - 4) = 1.0 - v54;
      --v52;
    }
    while ( v52 );
    ++v30;
    *v48 = 1065353216;
    v47 += 25;
    v48 += 25;
  }
  while ( v30 < 2 );
}

// File Line: 121
// RVA: 0x132DCF0
void __fastcall hkVehicleFrictionSolverCalcRelativeForces(hkpVehicleFrictionAxisTmp *axis, hkpVehicleFrictionStatus::AxisStatus *status)
{
  status->m_relativeSideForce = axis->m_invMaxSideImpulse * axis->m_sideImpulse;
  status->m_relativeForwardForce = axis->m_invMaxForwardImpulse * axis->m_forwardImpulse;
}

// File Line: 129
// RVA: 0x132DD30
void __fastcall hkCalculateFrictionalEllipsoidScale(hkpVehicleFrictionDescription::AxisDescription *adesc, float xs, float ys, float *scaleXOut, float *scaleYOut)
{
  __int64 v5; // rax
  float v6; // xmm8_4
  float v7; // xmm6_4
  float v8; // xmm5_4
  float v9; // xmm1_4
  float v10; // xmm9_4
  float i; // xmm3_4
  float v12; // xmm3_4
  float v13; // xmm10_4
  float v14; // xmm2_4
  float v15; // xmm7_4
  float v16; // xmm4_4

  v5 = 0i64;
  v6 = 0.0;
  v7 = xs * adesc->m_xStart;
  v8 = ys * adesc->m_frictionCircleYtab[0];
  v9 = 0.0;
  v10 = 0.0;
  for ( i = (float)(v8 * v8) + (float)(v7 * v7); i <= 1.0; i = (float)(v8 * v8) + (float)(v7 * v7) )
  {
    if ( ++v5 >= 16 )
      break;
    v9 = i;
    v10 = v8;
    v8 = ys * adesc->m_frictionCircleYtab[v5];
    v6 = v7;
    v7 = v7 * adesc->m_xStep;
  }
  v12 = fsqrt(i) - 1.0;
  v13 = fsqrt(v9) - 1.0;
  v14 = v12 - v13;
  if ( COERCE_FLOAT((unsigned int)(2 * COERCE_SIGNED_INT((float)(v12 - v13) - 0.0)) >> 1) <= 0.00000011920929 )
    v14 = FLOAT_1_1920929eN7;
  v15 = (float)(1.0 / v14) * v12;
  LODWORD(v16) = COERCE_UNSIGNED_INT((float)(1.0 / v14) * v13) ^ _xmm[0];
  *scaleXOut = fminf(fmaxf((float)(v15 * v6) + (float)(v16 * v7), -1.1), 1.1);
  *scaleYOut = fminf(fmaxf((float)(v16 * v8) + (float)(v15 * v10), -1.1), 1.1);
}

// File Line: 190
// RVA: 0x132DF00
void __fastcall hkVehicleFrictionSolverClipImpulse(hkpVehicleFrictionSolverAxleParams *apar, hkpVehicleFrictionAxisTmp *atmp, hkpVehicleFrictionDescription::AxisDescription *adesc, hkpVehicleFrictionStatus::AxisStatus *astatus)
{
  float v4; // xmm0_4
  float v5; // xmm3_4
  float v6; // xmm3_4
  float v7; // xmm2_4
  float *v8; // rdx
  __int64 v9; // r10
  float v10; // xmm2_4
  float v11; // xmm4_4
  float v12; // xmm5_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm3_4
  float v16; // xmm2_4
  float v17; // xmm0_4
  float v18; // xmm3_4
  float scaleXOut; // [rsp+68h] [rbp+18h]
  float scaleYOut; // [rsp+78h] [rbp+28h]

  v4 = atmp->m_invMaxSideImpulse;
  scaleYOut = -1.8446726e19;
  scaleXOut = v4 * atmp->m_sideImpulse;
  v5 = fmaxf(scaleXOut, -1.8446726e19);
  scaleXOut = atmp->m_invMaxForwardImpulse * atmp->m_forwardImpulse;
  scaleYOut = -1.8446726e19;
  v6 = fminf(v5, 1.8446726e19);
  v7 = fminf(fmaxf(scaleXOut, -1.8446726e19), 1.8446726e19);
  astatus->m_relativeSideForce = v6;
  astatus->m_relativeForwardForce = v7;
  if ( (float)((float)(v7 * v7) + (float)(v6 * v6)) >= 1.0 )
  {
    hkCalculateFrictionalEllipsoidScale(adesc, v6, v7, &scaleXOut, &scaleYOut);
    v10 = v8[33];
    v11 = v8[35];
    v12 = v8[34];
    v13 = v8[34] * scaleYOut;
    v14 = v8[35] * scaleXOut;
    v15 = v8[24];
    v8[33] = v14;
    v16 = v10 - v14;
    v17 = v8[32] - v13;
    v8[32] = v13;
    v18 = (float)(v15 * v15) + (float)(v8[26] * v8[26]);
    v8[38] = v17;
    scaleYOut = 0.0;
    scaleXOut = v18;
    if ( COERCE_FLOAT((unsigned int)(2 * COERCE_SIGNED_INT(v18 - 0.0)) >> 1) <= 0.00000011920929 )
      v18 = FLOAT_1_1920929eN7;
    scaleXOut = (float)((float)((float)((float)(v16 * v8[29]) * v11) * (float)((float)(v16 * v8[29]) * v11))
                      + (float)((float)((float)(v8[31] * v8[38]) * v12) * (float)((float)(v8[31] * v8[38]) * v12)))
              * (float)(1.0 / v18);
    *(float *)(v9 + 8) = fsqrt(scaleXOut);
  }
  else
  {
    atmp->m_restForwardSlipImpulse = 0.0;
  }
}

// File Line: 268
// RVA: 0x132CDF0
void __fastcall hkVehicleFrictionApplyVehicleFriction(hkpVehicleStepInfo *stepInfo, hkpVehicleFrictionDescription *descr, hkpVehicleFrictionSolverParams *params, hkpVehicleFrictionStatus *status)
{
  hkpVehicleFrictionSolverParams *v4; // r11
  signed __int64 v5; // rsi
  hkpVehicleFrictionStatus *v6; // rbx
  float *v7; // r8
  float *v8; // r15
  hkpVehicleStepInfo *v9; // r13
  float *v10; // r9
  signed __int64 v11; // rdi
  signed __int64 v12; // rdx
  __m128 *v13; // rcx
  __m128 v14; // xmm2
  __m128 *v15; // rax
  __m128 v16; // xmm15
  __m128 v17; // xmm12
  __m128 v18; // xmm10
  __m128 v19; // xmm14
  __m128 v20; // xmm7
  __m128 v21; // xmm9
  __m128 v22; // xmm1
  __m128 v23; // xmm4
  __m128 v24; // xmm15
  __m128 v25; // xmm6
  __m128 v26; // xmm3
  __m128 v27; // xmm3
  __m128 v28; // xmm4
  __m128 v29; // xmm4
  __m128 v30; // xmm5
  __m128 v31; // xmm3
  __m128 v32; // xmm1
  __m128 v33; // xmm1
  __m128 v34; // xmm0
  __m128 v35; // xmm2
  __m128 v36; // xmm1
  __m128 v37; // xmm0
  __m128 v38; // xmm2
  __m128 v39; // xmm4
  __m128 v40; // xmm1
  __m128 v41; // xmm3
  __m128 v42; // xmm3
  __m128 v43; // xmm4
  __m128 v44; // xmm4
  __m128 v45; // xmm5
  __m128 v46; // xmm4
  __m128 v47; // xmm1
  __m128 v48; // xmm1
  __m128 v49; // xmm0
  __m128 v50; // xmm2
  __m128 v51; // xmm1
  __m128 v52; // xmm3
  __m128 v53; // xmm4
  __m128 *v54; // rax
  __m128 v55; // xmm4
  __m128 v56; // xmm2
  __m128 v57; // xmm6
  __m128 *v58; // rax
  __m128 v59; // xmm2
  __m128 **v60; // rdi
  __m128 v61; // xmm1
  __m128 v62; // xmm2
  float v63; // xmm10_4
  __m128 v64; // xmm3
  float v65; // xmm15_4
  __m128 *v66; // rcx
  __m128 **v67; // r8
  unsigned int *v68; // rdx
  signed __int64 v69; // r9
  __m128 v70; // xmm5
  __m128 *v71; // rax
  __m128 v72; // xmm3
  __m128 v73; // xmm4
  __m128 v74; // xmm1
  __m128 v75; // xmm4
  __m128 v76; // xmm0
  float v77; // xmm1_4
  float *v78; // r8
  signed __int64 v79; // rdx
  __m128 *v80; // rcx
  signed __int64 v81; // r9
  float v82; // xmm3_4
  float v83; // xmm1_4
  float v84; // xmm0_4
  float v85; // xmm3_4
  __m128 *v86; // rax
  float v87; // xmm11_4
  __m128 v88; // xmm4
  __m128 v89; // xmm5
  __m128 v90; // xmm2
  float v91; // xmm6_4
  __m128 v92; // xmm1
  float v93; // xmm3_4
  float v94; // xmm7_4
  float v95; // xmm7_4
  float v96; // xmm5_4
  float v97; // xmm2_4
  float v98; // xmm4_4
  float v99; // xmm2_4
  bool v100; // cf
  bool v101; // zf
  float v102; // xmm5_4
  float v103; // xmm2_4
  float v104; // xmm1_4
  float v105; // xmm11_4
  float v106; // xmm1_4
  float v107; // xmm2_4
  float v108; // xmm0_4
  float *v109; // rax
  void **v110; // rcx
  signed __int64 v111; // rdx
  float v112; // xmm0_4
  float v113; // xmm2_4
  float v114; // xmm2_4
  float v115; // xmm2_4
  float v116; // xmm1_4
  float v117; // xmm1_4
  __m128 v118; // xmm7
  __m128 v119; // xmm2
  __m128 v120; // xmm2
  __m128 v121; // xmm1
  __m128 v122; // xmm7
  float v123; // xmm3_4
  float v124; // xmm2_4
  float *v125; // rdx
  hkpVehicleFrictionDescription::AxisDescription *v126; // rcx
  signed __int64 v127; // r8
  float v128; // xmm7_4
  float v129; // xmm2_4
  float v130; // xmm1_4
  float v131; // xmm1_4
  float v132; // xmm1_4
  float v133; // xmm2_4
  float v134; // xmm4_4
  float v135; // xmm5_4
  float v136; // xmm3_4
  float v137; // xmm1_4
  float v138; // xmm0_4
  float v139; // xmm0_4
  signed int v140; // ecx
  signed int v141; // er12
  __int64 v142; // rax
  signed __int64 v143; // rdi
  char *v144; // rdx
  __int64 v145; // rdx
  float v146; // xmm1_4
  float v147; // xmm0_4
  float v148; // xmm1_4
  __int128 *v149; // rcx
  __m128 *v150; // rax
  __m128 v151; // xmm5
  __m128 v152; // xmm5
  __m128 v153; // xmm3
  __m128 v154; // xmm4
  __m128 v155; // xmm1
  __m128 v156; // xmm0
  __m128 v157; // xmm1
  __m128 v158; // xmm0
  __m128 v159; // [rsp+30h] [rbp-B8h]
  float v160; // [rsp+40h] [rbp-A8h]
  char v161[24]; // [rsp+50h] [rbp-98h]
  __m128 v162; // [rsp+68h] [rbp-80h]
  __m128 v163; // [rsp+78h] [rbp-70h]
  __m128 v164; // [rsp+88h] [rbp-60h]
  float v165; // [rsp+98h] [rbp-50h]
  float v166; // [rsp+A0h] [rbp-48h]
  float v167; // [rsp+A4h] [rbp-44h]
  float v168; // [rsp+A8h] [rbp-40h]
  float v169; // [rsp+ACh] [rbp-3Ch]
  float v170; // [rsp+B4h] [rbp-34h]
  float v171; // [rsp+B8h] [rbp-30h]
  float v172; // [rsp+BCh] [rbp-2Ch]
  float v173; // [rsp+C8h] [rbp-20h]
  float v174; // [rsp+CCh] [rbp-1Ch]
  float v175; // [rsp+D0h] [rbp-18h]
  __m128 v176; // [rsp+108h] [rbp+20h]
  __m128 v177; // [rsp+118h] [rbp+30h]
  __m128 v178; // [rsp+128h] [rbp+40h]
  float v179; // [rsp+140h] [rbp+58h]
  float v180; // [rsp+144h] [rbp+5Ch]
  float v181; // [rsp+148h] [rbp+60h]
  unsigned int v182; // [rsp+14Ch] [rbp+64h]
  float v183; // [rsp+154h] [rbp+6Ch]
  float v184; // [rsp+158h] [rbp+70h]
  float v185; // [rsp+15Ch] [rbp+74h]
  float v186; // [rsp+168h] [rbp+80h]
  float v187; // [rsp+16Ch] [rbp+84h]
  float v188; // [rsp+170h] [rbp+88h]
  __m128 v189; // [rsp+178h] [rbp+90h]
  __m128 v190; // [rsp+188h] [rbp+A0h]
  float scaleXOut[2]; // [rsp+288h] [rbp+1A0h]
  float scaleYOut; // [rsp+290h] [rbp+1A8h]
  void *retaddr; // [rsp+298h] [rbp+1B0h]

  v4 = params;
  scaleYOut = 1.0;
  v5 = 2i64;
  v6 = status;
  v7 = &status->m_axis[0].m_forwardRhs;
  v8 = (float *)descr;
  v159 = _mm_shuffle_ps((__m128)0x3F800000u, (__m128)0x3F800000u, 0);
  v9 = stepInfo;
  v10 = &descr->m_axleDescr[0].m_wheelSurfaceInertiaInv;
  v11 = 2i64;
  v12 = (signed __int64)&v4->m_axleParams[0].m_forwardDirWs;
  v13 = &v163;
  v190 = v159;
  do
  {
    v14 = *(__m128 *)v12;
    v15 = *(__m128 **)(v12 + 16);
    v16 = *(__m128 *)(v12 - 32);
    v17 = v4->m_chassis.m_scratch1.m_quad;
    v18 = v4->m_chassis.m_scratch0.m_quad;
    v19 = v4->m_chassis.m_scratch2.m_quad;
    v20 = v15[3];
    v21 = v4->m_chassis.m_invMasses.m_quad;
    v22 = _mm_shuffle_ps(v14, v14, 201);
    v13[-4] = *(__m128 *)v12;
    v23 = v16;
    v24 = _mm_sub_ps(v16, v15[7]);
    v189 = _mm_sub_ps(v23, v4->m_chassis.m_scratch3.m_quad);
    v25 = _mm_max_ps(_mm_add_ps(v21, v20), (__m128)xmmword_141A712D0);
    v26 = _mm_sub_ps(_mm_mul_ps(v22, v189), _mm_mul_ps(_mm_shuffle_ps(v189, v189, 201), v14));
    v27 = _mm_shuffle_ps(v26, v26, 201);
    v28 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v24, v24, 201), v14), _mm_mul_ps(v22, v24));
    v29 = _mm_shuffle_ps(v28, v28, 201);
    v30 = _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v27, v27, 0), v18), _mm_mul_ps(_mm_shuffle_ps(v27, v27, 85), v17)),
            _mm_mul_ps(_mm_shuffle_ps(v27, v27, 170), v19));
    v31 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v29, v29, 0), v15[4]),
              _mm_mul_ps(_mm_shuffle_ps(v29, v29, 85), v15[5])),
            _mm_mul_ps(_mm_shuffle_ps(v29, v29, 170), v15[6]));
    v32 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v31, v31), v20), _mm_mul_ps(_mm_mul_ps(v30, v30), v21));
    v33 = _mm_shuffle_ps(v32, _mm_unpackhi_ps(v32, v25), 196);
    v34 = _mm_add_ps(_mm_shuffle_ps(v33, v33, 78), v33);
    v35 = _mm_add_ps(_mm_shuffle_ps(v34, v34, 177), v34);
    v36 = _mm_rcp_ps(v35);
    v13[-2] = _mm_shuffle_ps(v31, _mm_unpackhi_ps(v31, v35), 196);
    v37 = _mm_unpackhi_ps(v30, _mm_mul_ps(v159, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v36, v35)), v36)));
    v38 = *(__m128 *)(v12 - 16);
    v39 = v189;
    v13[-3] = _mm_shuffle_ps(v30, v37, 196);
    v36.m128_f32[0] = v13[-2].m128_f32[3] + *v10;
    v13[3].m128_i32[3] = v36.m128_i32[0];
    v37.m128_f32[0] = 1.0 / v36.m128_f32[0];
    v40 = _mm_shuffle_ps(v38, v38, 201);
    v13[3].m128_i32[2] = v37.m128_i32[0];
    v13[-1] = v38;
    v41 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v24, v24, 201), v38), _mm_mul_ps(v24, v40));
    v42 = _mm_shuffle_ps(v41, v41, 201);
    v43 = _mm_sub_ps(_mm_mul_ps(v39, v40), _mm_mul_ps(_mm_shuffle_ps(v39, v39, 201), v38));
    v44 = _mm_shuffle_ps(v43, v43, 201);
    v45 = _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v44, v44, 0), v18), _mm_mul_ps(_mm_shuffle_ps(v44, v44, 85), v17)),
            _mm_mul_ps(_mm_shuffle_ps(v44, v44, 170), v19));
    v46 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v42, v42, 0), v15[4]),
              _mm_mul_ps(_mm_shuffle_ps(v42, v42, 85), v15[5])),
            _mm_mul_ps(_mm_shuffle_ps(v42, v42, 170), v15[6]));
    v47 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v46, v46), v20), _mm_mul_ps(_mm_mul_ps(v45, v45), v21));
    v48 = _mm_shuffle_ps(v47, _mm_unpackhi_ps(v47, v25), 196);
    v49 = _mm_add_ps(_mm_shuffle_ps(v48, v48, 78), v48);
    v50 = _mm_add_ps(_mm_shuffle_ps(v49, v49, 177), v49);
    v51 = _mm_rcp_ps(v50);
    v13[1] = _mm_shuffle_ps(v46, _mm_unpackhi_ps(v46, v50), 196);
    *v13 = _mm_shuffle_ps(
             v45,
             _mm_unpackhi_ps(v45, _mm_mul_ps(v190, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v51, v50)), v51))),
             196);
    v13[3].m128_i32[0] = HIDWORD(v13->m128_u64[1]);
    v52 = v4->m_chassisAtLastIntegration.m_angularVel.m_quad;
    v53 = v4->m_chassisAtLastIntegration.m_linearVel.m_quad;
    v13[3].m128_i32[1] = v13[1].m128_i32[3];
    v54 = *(__m128 **)(v12 + 24);
    v7 += 9;
    v12 += 96i64;
    v13 += 10;
    v10 += 25;
    v55 = _mm_sub_ps(v53, v54[1]);
    v56 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v52, v13[-13]), _mm_mul_ps(v54[2], v13[-12])), _mm_mul_ps(v55, v13[-14]));
    v57 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v54[2], v13[-9]), _mm_mul_ps(v13[-10], v52)), _mm_mul_ps(v55, v13[-11]));
    *(v7 - 9) = (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v56, v56, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v56, v56, 0)))
                      + COERCE_FLOAT(_mm_shuffle_ps(v56, v56, 170)))
              + *(v7 - 9);
    *(v7 - 10) = (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v57, v57, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v57, v57, 0)))
                       + COERCE_FLOAT(_mm_shuffle_ps(v57, v57, 170)))
               + *(v7 - 10);
    --v11;
  }
  while ( v11 );
  v58 = (__m128 *)v4->m_axleParams[0].m_groundObject;
  v59 = v4->m_chassis.m_invMasses.m_quad;
  v60 = (__m128 **)&v4->m_axleParams[0].m_groundObject;
  if ( v58 == (__m128 *)v4->m_axleParams[1].m_groundObject )
  {
    v61 = _mm_mul_ps(v162, v176);
    v62 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v59, v59, 255), v61),
              _mm_mul_ps(_mm_shuffle_ps(v58[3], v58[3], 255), v61)),
            _mm_add_ps(
              _mm_mul_ps(_mm_mul_ps(v163, v177), v4->m_chassis.m_invMasses.m_quad),
              _mm_mul_ps(_mm_mul_ps(v164, v178), v58[3])));
    v63 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v62, v62, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v62, v62, 0)))
        + COERCE_FLOAT(_mm_shuffle_ps(v62, v62, 170));
  }
  else
  {
    v64 = _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v59, v59, 255), _mm_mul_ps(v162, v176)),
            _mm_mul_ps(_mm_mul_ps(v163, v177), v59));
    v63 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v64, v64, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v64, v64, 0)))
        + COERCE_FLOAT(_mm_shuffle_ps(v64, v64, 170));
  }
  v65 = v169;
  v66 = (__m128 *)v161;
  v67 = (__m128 **)&v4->m_axleParams[0].m_groundObject;
  v68 = (unsigned int *)&v6->m_axis[0].m_delayed_forward_impulse;
  v69 = 2i64;
  v159.m128_u64[0] = __PAIR__(LODWORD(v63), LODWORD(v169));
  v160 = *(float *)&v182;
  v159.m128_u64[1] = __PAIR__(v182, LODWORD(v63));
  do
  {
    v70 = _mm_shuffle_ps((__m128)*v68, (__m128)*v68, 0);
    if ( v70.m128_f32[0] != 0.0 )
    {
      v71 = *v67;
      v72 = _mm_mul_ps(v4->m_chassis.m_invMasses.m_quad, v70);
      v73 = _mm_mul_ps((*v67)[3], v70);
      v74 = _mm_shuffle_ps(v73, v73, 255);
      v75 = _mm_mul_ps(v73, v66[2]);
      v4->m_chassis.m_linearVel.m_quad = _mm_add_ps(
                                           _mm_mul_ps(_mm_shuffle_ps(v72, v72, 255), *v66),
                                           v4->m_chassis.m_linearVel.m_quad);
      v71[1] = _mm_sub_ps(v71[1], _mm_mul_ps(v74, *v66));
      v76 = _mm_add_ps(_mm_mul_ps(v66[1], v72), v4->m_chassis.m_angularVel.m_quad);
      v4->m_chassis.m_angularVel.m_quad = v76;
      v76.m128_f32[0] = 0.0;
      v71[2] = _mm_add_ps(v75, v71[2]);
      scaleYOut = COERCE_FLOAT(_mm_shuffle_ps(v76, v76, 0)) + v70.m128_f32[0];
    }
    v68 += 9;
    v67 += 12;
    v66 += 10;
    --v69;
  }
  while ( v69 );
  v77 = v4->m_axleParams[0].m_wheelDownForce;
  v78 = &v6->m_axis[0].m_forwardRhs;
  v79 = (signed __int64)&v4->m_axleParams[0].m_forwardForce;
  v80 = &v163;
  v81 = 2i64;
  v82 = v4->m_axleParams[1].m_wheelDownForce + v77;
  v83 = v77 * v8[29];
  v84 = v82 * v8[30];
  v85 = (float)(v82 * v8[55]) + (float)(v4->m_axleParams[1].m_wheelDownForce * v8[54]);
  v6->m_axis[0].m_skid_energy_density = 0.0;
  v6->m_axis[1].m_skid_energy_density = 0.0;
  v180 = v85;
  v167 = v84 + v83;
  do
  {
    v86 = *(__m128 **)(v79 - 32);
    v87 = *(float *)v79;
    v88 = v4->m_chassis.m_angularVel.m_quad;
    v89 = _mm_sub_ps(v4->m_chassis.m_linearVel.m_quad, v86[1]);
    v90 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v80[-3], v88), _mm_mul_ps(v80[-2], v86[2])), _mm_mul_ps(v80[-4], v89));
    v91 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v90, v90, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v90, v90, 0)))
        + COERCE_FLOAT(_mm_shuffle_ps(v90, v90, 170));
    v80[2].m128_f32[0] = v91;
    v92 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v80[1], v86[2]), _mm_mul_ps(v88, *v80)), _mm_mul_ps(v80[-1], v89));
    v93 = (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v92, v92, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v92, v92, 0)))
                + COERCE_FLOAT(_mm_shuffle_ps(v92, v92, 170)))
        + (float)(*(v78 - 1) * 0.25);
    scaleYOut = v80[2].m128_f32[3];
    v94 = scaleYOut;
    v80[2].m128_f32[2] = v93;
    v95 = COERCE_FLOAT((unsigned int)(2 * LODWORD(v94)) >> 1) * v9->m_deltaTime;
    if ( *(_BYTE *)(v79 + 8) )
    {
      v96 = (float)(v95 * *(float *)(v79 - 16)) * v80[3].m128_f32[3];
      v97 = (float)((float)(*v78 * 0.5) + v91) * (float)(v80[3].m128_f32[3] * v80[3].m128_f32[0]);
      LODWORD(v98) = LODWORD(v91) ^ _xmm[0];
      v80[2].m128_i32[1] = LODWORD(v91) ^ _xmm[0];
      v99 = v97 * 0.5;
      scaleYOut = v99;
      if ( COERCE_FLOAT((unsigned int)(2 * LODWORD(v99)) >> 1) > v96 )
      {
        v100 = v99 < 0.0;
        v101 = v99 == 0.0;
        v99 = v96;
        if ( v100 || v101 )
          LODWORD(v99) = LODWORD(v96) ^ _xmm[0];
      }
      v87 = 0.0;
      v80[2].m128_f32[1] = v98 - v99;
    }
    else
    {
      *v78 = 0.0;
      v98 = *(v78 - 6);
      v80[2].m128_f32[1] = v98;
    }
    v102 = *(float *)(v79 - 12);
    v103 = *(float *)(v79 - 16);
    if ( v102 != 0.0 )
    {
      scaleYOut = fminf((float)(v102 * fsqrt((float)(v93 * v93) + (float)(v98 * v98))) + v103, *(float *)(v79 - 8));
      v103 = fmaxf(0.0, scaleYOut);
    }
    v104 = v80[3].m128_f32[2];
    v105 = v87 * v9->m_deltaTime;
    v80 += 10;
    v79 += 96i64;
    v78 += 9;
    v106 = v104 * v80[-8].m128_f32[1];
    v107 = v103 * v95;
    v80[-6].m128_f32[2] = v107;
    v80[-6].m128_f32[3] = v107;
    v108 = 1.0 / (float)(v107 + 1.4210855e-14);
    v80[-6].m128_f32[0] = v106 + v105;
    v80[-5].m128_f32[0] = v108;
    v80[-5].m128_f32[1] = v108;
    --v81;
  }
  while ( v81 );
  v109 = &v4->m_axleParams[0].m_slipVelocityFactor;
  if ( (float)(v4->m_axleParams[1].m_slipVelocityFactor + v4->m_axleParams[0].m_slipVelocityFactor) > 0.0 )
  {
    v110 = &retaddr;
    v111 = 2i64;
    *(float *)&retaddr = v4->m_axleParams[0].m_wheelDownForce;
    v112 = v4->m_axleParams[0].m_wheelDownForce;
    scaleYOut = v4->m_axleParams[1].m_wheelDownForce;
    v113 = scaleYOut;
    scaleYOut = 0.0;
    v114 = (float)(COERCE_FLOAT((unsigned int)(2 * LODWORD(v113)) >> 1)
                 + COERCE_FLOAT((unsigned int)(2 * LODWORD(v112)) >> 1))
         * v8[5];
    scaleYOut = FLOAT_10000_0;
    v115 = v114 * v9->m_deltaTime;
    do
    {
      scaleYOut = *v109;
      v116 = fmaxf(scaleYOut, 0.0);
      if ( v115 < v116 )
        v117 = v116 / v115;
      else
        v117 = *(float *)&FLOAT_1_0;
      scaleYOut = v117;
      v110 = (void **)((char *)v110 + 4);
      v109 += 24;
      *((float *)v110 - 1) = fminf(10000.0, v117);
      --v111;
    }
    while ( v111 );
    v159.m128_f32[3] = v160 * *((float *)&retaddr + 1);
    v159.m128_f32[0] = v65 * *(float *)&retaddr;
    scaleYOut = *((float *)&retaddr + 1) * *(float *)&retaddr;
    v168 = v168 / *(float *)&retaddr;
    v63 = fsqrt(*((float *)&retaddr + 1) * *(float *)&retaddr) * v63;
    v159.m128_f32[2] = v63;
    v159.m128_f32[1] = v63;
    v181 = v181 / *((float *)&retaddr + 1);
    v169 = v169 * *(float *)&retaddr;
    *(float *)&v182 = *(float *)&v182 * *((float *)&retaddr + 1);
  }
  v118 = (__m128)_xmm;
  v119 = _mm_mul_ps(_mm_shuffle_ps(v159, v159, 187), v159);
  v120 = _mm_sub_ps(_mm_shuffle_ps(v119, v119, 0), _mm_shuffle_ps(v119, v119, 85));
  if ( COERCE_FLOAT((unsigned int)(2 * v120.m128_i32[0]) >> 1) > 0.0 )
  {
    v121 = _mm_rcp_ps(v120);
    v122 = _mm_mul_ps(
             _mm_xor_ps(
               (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 80),
               _mm_shuffle_ps(v159, v159, 57)),
             _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v121, v120)), v121));
    v118 = _mm_shuffle_ps(v122, v122, 198);
  }
  LODWORD(v172) = COERCE_UNSIGNED_INT((float)(v179 * COERCE_FLOAT(_mm_shuffle_ps(v118, v118, 85))) + (float)(v166 * v118.m128_f32[0])) ^ _xmm[0];
  LODWORD(v185) = COERCE_UNSIGNED_INT(
                    (float)(COERCE_FLOAT(_mm_shuffle_ps(v118, v118, 255)) * v179)
                  + (float)(COERCE_FLOAT(_mm_shuffle_ps(v118, v118, 170)) * v166)) ^ _xmm[0];
  v123 = (float)((float)(v174 * v172) * (float)(v174 * v172)) + (float)((float)(v171 * v173) * (float)(v171 * v173));
  scaleYOut = v165;
  v124 = (float)((float)(v187 * v185) * (float)(v187 * v185)) + (float)((float)(v184 * v186) * (float)(v184 * v186));
  if ( COERCE_FLOAT((unsigned int)(2 * LODWORD(v165)) >> 1) >= v4->m_maxVelocityForPositionalFriction )
  {
    *(_QWORD *)&v6->m_axis[0].m_sideRhs = 0i64;
    *(_QWORD *)&v6->m_axis[1].m_sideRhs = 0i64;
  }
  if ( v123 > 1.0 )
    goto LABEL_53;
  if ( v124 <= 1.0 )
  {
    v125 = &v173;
    v126 = (hkpVehicleFrictionDescription::AxisDescription *)(v8 + 6);
    v127 = 2i64;
    do
    {
      v128 = *(v125 - 3);
      v129 = *(v125 - 4) * *v125;
      v130 = *(v125 - 3) * v125[1];
      if ( (float)((float)(v129 * v129) + (float)(v130 * v130)) < 1.0 )
      {
        *((_DWORD *)v125 - 3) = COERCE_UNSIGNED_INT(*(v125 - 10) * *(v125 - 8)) ^ _xmm[0];
      }
      else
      {
        hkCalculateFrictionalEllipsoidScale(v126, v130, v129, scaleXOut, &scaleYOut);
        scaleYOut = scaleXOut[0] * *(v125 - 1);
        v131 = scaleYOut;
        scaleYOut = v128;
        LODWORD(v132) = (unsigned int)(2 * LODWORD(v131)) >> 1;
        LODWORD(retaddr) = LODWORD(v132) ^ _xmm[0];
        *(v125 - 3) = fminf(fmaxf(v128, COERCE_FLOAT(LODWORD(v132) ^ _xmm[0])), v132);
      }
      ++v126;
      v125 += 40;
      v179 = v179 + (float)(v63 * *(v125 - 43));
      --v127;
    }
    while ( v127 );
    v133 = v172;
    v134 = v171;
    v135 = v184;
    v136 = v185;
    v137 = v187 * v185;
    v6->m_axis[0].m_relativeSideForce = v174 * v172;
    v6->m_axis[0].m_relativeForwardForce = v134 * v173;
    v6->m_axis[1].m_relativeSideForce = v137;
    v6->m_axis[1].m_relativeForwardForce = v135 * v186;
    *(_QWORD *)&v6->m_axis[0].m_forward_slip_velocity = 0i64;
    *(_QWORD *)&v6->m_axis[1].m_forward_slip_velocity = 0i64;
    goto LABEL_49;
  }
  if ( v123 > 1.0 )
  {
LABEL_53:
    v138 = (float)(1.0 / v123) * v6->m_axis[0].m_sideRhs;
    v6->m_axis[0].m_forwardRhs = (float)(1.0 / v123) * v6->m_axis[0].m_forwardRhs;
    v6->m_axis[0].m_sideRhs = v138;
  }
  if ( v124 > 1.0 )
  {
    v139 = (float)(1.0 / v124) * v6->m_axis[1].m_sideRhs;
    v6->m_axis[1].m_forwardRhs = (float)(1.0 / v124) * v6->m_axis[1].m_forwardRhs;
    v6->m_axis[1].m_sideRhs = v139;
  }
  if ( v123 <= v124 )
  {
    v140 = 1;
    v141 = 0;
  }
  else
  {
    v140 = 0;
    v141 = 1;
  }
  v142 = v140;
  v143 = 2i64;
  do
  {
    v144 = &v161[160 * v142];
    *((_DWORD *)v144 + 33) = COERCE_UNSIGNED_INT(*((float *)v144 + 28) * *((float *)v144 + 26)) ^ _xmm[0];
    hkVehicleFrictionSolverClipImpulse(
      &v4->m_axleParams[v140],
      (hkpVehicleFrictionAxisTmp *)v144,
      (hkpVehicleFrictionDescription::AxisDescription *)&v8[25 * v140 + 6],
      &v6->m_axis[v140]);
    v140 = v141;
    v142 = v141;
    *(&v166 + 40 * v141) = (float)(v63 * *(float *)(v145 + 132)) + *(&v166 + 40 * v141);
    --v143;
  }
  while ( v143 );
  v136 = v185;
  v9 = *(hkpVehicleStepInfo **)scaleXOut;
  v60 = (__m128 **)&v4->m_axleParams[0].m_groundObject;
  v146 = v183 * v188;
  v135 = v184;
  v133 = v172;
  v134 = v171;
  v6->m_axis[0].m_forward_slip_velocity = v170 * v175;
  v147 = v166;
  v6->m_axis[1].m_forward_slip_velocity = v146;
  v148 = v179;
  v6->m_axis[0].m_side_slip_velocity = v147;
  v6->m_axis[1].m_side_slip_velocity = v148;
LABEL_49:
  v6->m_axis[0].m_delayed_forward_impulse = v134;
  v6->m_axis[1].m_delayed_forward_impulse = v135;
  v149 = (__int128 *)&v162;
  v6->m_axis[0].m_side_force = v133 * v9->m_invDeltaTime;
  v6->m_axis[1].m_side_force = v136 * v9->m_invDeltaTime;
  do
  {
    v150 = *v60;
    v151 = (__m128)*((unsigned int *)v149 + 21);
    v149 += 10;
    v60 += 12;
    v152 = _mm_shuffle_ps(v151, v151, 0);
    v153 = _mm_mul_ps(v4->m_chassis.m_invMasses.m_quad, v152);
    v154 = _mm_mul_ps(v150[3], v152);
    v155 = _mm_mul_ps(_mm_shuffle_ps(v154, v154, 255), (__m128)*(v149 - 10));
    v4->m_chassis.m_linearVel.m_quad = _mm_add_ps(
                                         _mm_mul_ps(_mm_shuffle_ps(v153, v153, 255), (__m128)*(v149 - 10)),
                                         v4->m_chassis.m_linearVel.m_quad);
    v156 = _mm_sub_ps(v150[1], v155);
    v157 = (__m128)*(v149 - 8);
    v150[1] = v156;
    v158 = _mm_add_ps(_mm_mul_ps((__m128)*(v149 - 9), v153), v4->m_chassis.m_angularVel.m_quad);
    v4->m_chassis.m_angularVel.m_quad = v158;
    v158.m128_f32[0] = 0.0;
    v150[2] = _mm_add_ps(_mm_mul_ps(v157, v154), v150[2]);
    scaleXOut[0] = COERCE_FLOAT(_mm_shuffle_ps(v158, v158, 0)) + v152.m128_f32[0];
    --v5;
  }
  while ( v5 );
}

