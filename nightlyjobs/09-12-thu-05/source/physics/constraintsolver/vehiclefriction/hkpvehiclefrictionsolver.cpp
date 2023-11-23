// File Line: 28
// RVA: 0x132CA40
void __fastcall hkVehicleFrictionDescriptionInitValues(
        hkpVehicleFrictionDescription::Cinfo *ci,
        hkpVehicleFrictionDescription *out,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        __int64 a15,
        __int64 a16,
        __int64 a17,
        __int64 a18,
        __int64 a19,
        __int64 a20,
        __int64 a21)
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
  __int64 v30; // rbp
  __int64 v32; // rcx
  signed __int64 v33; // r9
  __m128 m_quad; // xmm4
  __m128 v35; // xmm7
  float m_chassisMassInv; // xmm13_4
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
  float *p_m_wheelChassisMassRatio; // rsi
  float *v48; // r14
  float v49; // xmm6_4
  float v50; // xmm7_4
  float *v51; // rbx
  __int64 v52; // rdi
  float v53; // xmm10_4
  float v54; // xmm0_4
  int v56[39]; // [rsp+C8h] [rbp+10h] BYREF

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
  v28 = (float)(_mm_shuffle_ps(v27, v27, 85).m128_f32[0] + _mm_shuffle_ps(v27, v27, 0).m128_f32[0])
      + _mm_shuffle_ps(v27, v27, 170).m128_f32[0];
  v29 = (float)(_mm_shuffle_ps(v26, v26, 85).m128_f32[0] + _mm_shuffle_ps(v26, v26, 0).m128_f32[0])
      + _mm_shuffle_ps(v26, v26, 170).m128_f32[0];
  v26.m128_i32[0] = (unsigned int)(2 * COERCE_INT(v28 - v29)) >> 1;
  LODWORD(out->m_wheelDistance) = v26.m128_i32[0];
  out->m_axleDescr[0].m_wheelDownForceFactor = 1.0 - ci->m_frictionEqualizer;
  out->m_axleDescr[0].m_wheelDownForceSumFactor = COERCE_FLOAT((2
                                                              * (COERCE_UNSIGNED_INT((float)(1.0 / v26.m128_f32[0]) * v29) ^ _xmm[0])) >> 1)
                                                * ci->m_frictionEqualizer;
  out->m_axleDescr[1].m_wheelDownForceFactor = 1.0 - ci->m_frictionEqualizer;
  v26.m128_f32[0] = COERCE_FLOAT((unsigned int)(2 * COERCE_INT((float)(1.0 / v26.m128_f32[0]) * v28)) >> 1)
                  * ci->m_frictionEqualizer;
  v30 = 0i64;
  v32 = 0i64;
  v33 = (char *)ci - (char *)v56;
  LODWORD(out->m_axleDescr[1].m_wheelDownForceSumFactor) = v26.m128_i32[0];
  m_quad = v21->m_directionRight.m_quad;
  v35 = v21->m_directionUp.m_quad;
  m_chassisMassInv = out->m_chassisMassInv;
  v37 = v21->m_chassisCenterOfMass.m_quad;
  v38 = v21->m_chassisFrictionInertiaInv.m_col1.m_quad;
  v39 = v21->m_chassisFrictionInertiaInv.m_col0.m_quad;
  v40 = v21->m_chassisFrictionInertiaInv.m_col2.m_quad;
  v41 = _mm_shuffle_ps(m_quad, m_quad, 201);
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
    v44 = _mm_sub_ps(_mm_mul_ps(v41, v43), _mm_mul_ps(_mm_shuffle_ps(v43, v43, 201), m_quad));
    v45 = _mm_shuffle_ps(v44, v44, 201);
    v46 = _mm_mul_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v45, v45, 0), v39), _mm_mul_ps(_mm_shuffle_ps(v45, v45, 85), v38)),
              _mm_mul_ps(_mm_shuffle_ps(v45, v45, 170), v40)),
            v45);
    *(float *)&v56[v32 - 1] = (float)((float)(_mm_shuffle_ps(v46, v46, 85).m128_f32[0]
                                            + _mm_shuffle_ps(v46, v46, 0).m128_f32[0])
                                    + _mm_shuffle_ps(v46, v46, 170).m128_f32[0])
                            + m_chassisMassInv;
  }
  while ( v32 < 2 );
  p_m_wheelChassisMassRatio = &out->m_axleDescr[0].m_wheelChassisMassRatio;
  v48 = &out->m_axleDescr[0].m_frictionCircleYtab[15];
  do
  {
    v49 = *(float *)&v56[v30] * *(p_m_wheelChassisMassRatio - 2);
    *p_m_wheelChassisMassRatio = v49;
    v50 = v49 * 0.0625;
    *(p_m_wheelChassisMassRatio - 3) = v49 * 0.0625;
    v51 = p_m_wheelChassisMassRatio - 20;
    v52 = 15i64;
    v53 = powf(1.0 / (float)(v49 * 0.0625), 0.06666667);
    *(p_m_wheelChassisMassRatio - 4) = v53;
    do
    {
      v54 = powf(1.0 - v50, 1.0 / v49);
      ++v51;
      v50 = v50 * v53;
      *(v51 - 1) = 1.0 - v54;
      --v52;
    }
    while ( v52 );
    ++v30;
    *v48 = 1.0;
    p_m_wheelChassisMassRatio += 25;
    v48 += 25;
  }
  while ( v30 < 2 );
}

// File Line: 121
// RVA: 0x132DCF0
void __fastcall hkVehicleFrictionSolverCalcRelativeForces(
        hkpVehicleFrictionAxisTmp *axis,
        hkpVehicleFrictionStatus::AxisStatus *status)
{
  status->m_relativeSideForce = axis->m_invMaxSideImpulse * axis->m_sideImpulse;
  status->m_relativeForwardForce = axis->m_invMaxForwardImpulse * axis->m_forwardImpulse;
}

// File Line: 129
// RVA: 0x132DD30
void __fastcall hkCalculateFrictionalEllipsoidScale(
        hkpVehicleFrictionDescription::AxisDescription *adesc,
        float xs,
        float ys,
        float *scaleXOut,
        float *scaleYOut)
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
  if ( COERCE_FLOAT((unsigned int)(2 * COERCE_INT((float)(v12 - v13) - 0.0)) >> 1) <= 0.00000011920929 )
    v14 = FLOAT_1_1920929eN7;
  v15 = (float)(1.0 / v14) * v12;
  LODWORD(v16) = COERCE_UNSIGNED_INT((float)(1.0 / v14) * v13) ^ _xmm[0];
  *scaleXOut = fminf(fmaxf((float)(v15 * v6) + (float)(v16 * v7), -1.1), 1.1);
  *scaleYOut = fminf(fmaxf((float)(v16 * v8) + (float)(v15 * v10), -1.1), 1.1);
}

// File Line: 190
// RVA: 0x132DF00
void __fastcall hkVehicleFrictionSolverClipImpulse(
        hkpVehicleFrictionSolverAxleParams *apar,
        hkpVehicleFrictionAxisTmp *atmp,
        hkpVehicleFrictionDescription::AxisDescription *adesc,
        hkpVehicleFrictionStatus::AxisStatus *astatus)
{
  float m_invMaxSideImpulse; // xmm0_4
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
  float scaleXOut; // [rsp+68h] [rbp+18h] BYREF
  float scaleYOut; // [rsp+78h] [rbp+28h] BYREF

  m_invMaxSideImpulse = atmp->m_invMaxSideImpulse;
  scaleYOut = -1.8446726e19;
  scaleXOut = m_invMaxSideImpulse * atmp->m_sideImpulse;
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
    v13 = v12 * scaleYOut;
    v14 = v11 * scaleXOut;
    v15 = v8[24];
    v8[33] = v11 * scaleXOut;
    v16 = v10 - v14;
    v17 = v8[32] - v13;
    v8[32] = v13;
    v18 = (float)(v15 * v15) + (float)(v8[26] * v8[26]);
    v8[38] = v17;
    scaleYOut = 0.0;
    scaleXOut = v18;
    if ( COERCE_FLOAT((unsigned int)(2 * COERCE_INT(v18 - 0.0)) >> 1) <= 0.00000011920929 )
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
void __fastcall hkVehicleFrictionApplyVehicleFriction(
        hkpVehicleStepInfo *stepInfo,
        hkpVehicleFrictionDescription *descr,
        hkpVehicleFrictionSolverParams *params,
        hkpVehicleFrictionStatus *status)
{
  hkpVehicleFrictionSolverParams *v4; // r11
  __int64 v5; // rsi
  float *p_m_forwardRhs; // r8
  float *p_m_wheelSurfaceInertiaInv; // r9
  __int64 v11; // rdi
  hkVector4f *p_m_forwardDirWs; // rdx
  __m128 *v13; // rcx
  __m128 m_quad; // xmm2
  __m128 *v15; // rax
  __m128 v16; // xmm15
  __m128 v17; // xmm12
  __m128 v18; // xmm10
  __m128 v19; // xmm14
  __m128 v20; // xmm7
  __m128 v21; // xmm9
  __m128 v22; // xmm3
  __m128 v23; // xmm4
  __m128 v24; // xmm15
  __m128 v25; // xmm1
  __m128 v26; // xmm6
  __m128 v27; // xmm3
  __m128 v28; // xmm3
  __m128 v29; // xmm4
  __m128 v30; // xmm4
  __m128 v31; // xmm5
  __m128 v32; // xmm3
  __m128 v33; // xmm1
  __m128 v34; // xmm1
  __m128 v35; // xmm0
  __m128 v36; // xmm2
  __m128 v37; // xmm1
  __m128 v38; // xmm0
  __m128 v39; // xmm2
  __m128 v40; // xmm4
  __m128 v41; // xmm1
  __m128 v42; // xmm3
  __m128 v43; // xmm3
  __m128 v44; // xmm4
  __m128 v45; // xmm4
  __m128 v46; // xmm5
  __m128 v47; // xmm4
  __m128 v48; // xmm1
  __m128 v49; // xmm1
  __m128 v50; // xmm0
  __m128 v51; // xmm2
  __m128 v52; // xmm1
  __m128 v53; // xmm3
  __m128 v54; // xmm4
  __m128 *v55; // rax
  __m128 v56; // xmm4
  __m128 v57; // xmm2
  __m128 v58; // xmm6
  __m128 *m_groundObject; // rax
  __m128 v60; // xmm2
  __m128 **p_m_groundObject; // rdi
  __m128 v62; // xmm1
  __m128 v63; // xmm2
  int v64; // xmm10_4
  __m128 v65; // xmm3
  float v66; // xmm15_4
  __m128 *v67; // rcx
  __m128 **v68; // r8
  float *p_m_delayed_forward_impulse; // rdx
  __int64 v70; // r9
  __m128 v71; // xmm5
  __m128 *v72; // rax
  __m128 v73; // xmm3
  __m128 v74; // xmm4
  __m128 v75; // xmm1
  __m128 v76; // xmm4
  __m128 v77; // xmm0
  float m_wheelDownForce; // xmm1_4
  float *v79; // r8
  float *p_m_forwardForce; // rdx
  __m128 *v81; // rcx
  __int64 v82; // r9
  float v83; // xmm3_4
  float v84; // xmm2_4
  float v85; // xmm3_4
  float v86; // xmm1_4
  float v87; // xmm0_4
  float v88; // xmm3_4
  __m128 *v89; // rax
  float v90; // xmm11_4
  __m128 v91; // xmm4
  __m128 v92; // xmm5
  __m128 v93; // xmm2
  float v94; // xmm6_4
  __m128 v95; // xmm1
  float v96; // xmm3_4
  float v97; // xmm7_4
  float v98; // xmm7_4
  float v99; // xmm5_4
  float v100; // xmm2_4
  float v101; // xmm4_4
  float v102; // xmm2_4
  bool v103; // cc
  float v104; // xmm5_4
  float v105; // xmm2_4
  float v106; // xmm1_4
  float v107; // xmm11_4
  float v108; // xmm1_4
  float v109; // xmm2_4
  float v110; // xmm0_4
  float *p_m_slipVelocityFactor; // rax
  void **v112; // rcx
  __int64 v113; // rdx
  float v114; // xmm2_4
  float v115; // xmm2_4
  float v116; // xmm2_4
  float v117; // xmm1_4
  float v118; // xmm1_4
  __m128 v119; // xmm7
  __m128 v120; // xmm2
  __m128 v121; // xmm2
  __m128 v122; // xmm1
  __m128 v123; // xmm7
  float v124; // xmm3_4
  float v125; // xmm2_4
  float *v126; // rdx
  hkpVehicleFrictionDescription::AxisDescription *m_axleDescr; // rcx
  __int64 v128; // r8
  float v129; // xmm7_4
  float v130; // xmm2_4
  float v131; // xmm1_4
  float v132; // xmm1_4
  float v133; // xmm2_4
  float v134; // xmm4_4
  float v135; // xmm5_4
  float v136; // xmm3_4
  float v137; // xmm1_4
  float v138; // xmm0_4
  float v139; // xmm0_4
  int v140; // ecx
  int v141; // r12d
  __int64 v142; // rax
  __int64 v143; // rdi
  char *v144; // rdx
  __int64 v145; // rdx
  float v146; // xmm1_4
  float v147; // xmm0_4
  float v148; // xmm1_4
  __m128 *v149; // rcx
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
  char v161[24]; // [rsp+50h] [rbp-98h] BYREF
  __m128 v162; // [rsp+68h] [rbp-80h] BYREF
  __m128 v163[2]; // [rsp+78h] [rbp-70h] BYREF
  float v164; // [rsp+98h] [rbp-50h]
  int v165[2]; // [rsp+A0h] [rbp-48h]
  float v166; // [rsp+A8h] [rbp-40h]
  float v167; // [rsp+ACh] [rbp-3Ch]
  float v168; // [rsp+B4h] [rbp-34h]
  float v169; // [rsp+B8h] [rbp-30h]
  float v170; // [rsp+BCh] [rbp-2Ch]
  float v171; // [rsp+C8h] [rbp-20h] BYREF
  float v172; // [rsp+CCh] [rbp-1Ch]
  float v173; // [rsp+D0h] [rbp-18h]
  __m128 v174; // [rsp+108h] [rbp+20h]
  __m128 v175; // [rsp+118h] [rbp+30h]
  __m128 v176; // [rsp+128h] [rbp+40h]
  float v177; // [rsp+140h] [rbp+58h]
  float v178; // [rsp+144h] [rbp+5Ch]
  float v179; // [rsp+148h] [rbp+60h]
  unsigned int v180; // [rsp+14Ch] [rbp+64h]
  float v181; // [rsp+154h] [rbp+6Ch]
  float v182; // [rsp+158h] [rbp+70h]
  float v183; // [rsp+15Ch] [rbp+74h]
  float v184; // [rsp+168h] [rbp+80h]
  float v185; // [rsp+16Ch] [rbp+84h]
  float v186; // [rsp+170h] [rbp+88h]
  __m128 v187; // [rsp+178h] [rbp+90h]
  __m128 v188; // [rsp+188h] [rbp+A0h]
  float scaleXOut[2]; // [rsp+288h] [rbp+1A0h] BYREF
  float scaleYOut; // [rsp+290h] [rbp+1A8h] BYREF
  void *retaddr; // [rsp+298h] [rbp+1B0h] BYREF
  float v192; // [rsp+2A0h] [rbp+1B8h]

  v4 = params;
  scaleYOut = 1.0;
  v5 = 2i64;
  p_m_forwardRhs = &status->m_axis[0].m_forwardRhs;
  v159 = _mm_shuffle_ps((__m128)0x3F800000u, (__m128)0x3F800000u, 0);
  p_m_wheelSurfaceInertiaInv = &descr->m_axleDescr[0].m_wheelSurfaceInertiaInv;
  v11 = 2i64;
  p_m_forwardDirWs = &v4->m_axleParams[0].m_forwardDirWs;
  v13 = v163;
  v188 = v159;
  do
  {
    m_quad = p_m_forwardDirWs->m_quad;
    v15 = (__m128 *)p_m_forwardDirWs[1].m_quad.m128_u64[0];
    v16 = p_m_forwardDirWs[-2].m_quad;
    v17 = v4->m_chassis.m_scratch1.m_quad;
    v18 = v4->m_chassis.m_scratch0.m_quad;
    v19 = v4->m_chassis.m_scratch2.m_quad;
    v20 = v15[3];
    v21 = v4->m_chassis.m_invMasses.m_quad;
    v22 = _mm_shuffle_ps(m_quad, m_quad, 201);
    v13[-4] = p_m_forwardDirWs->m_quad;
    v23 = v16;
    v24 = _mm_sub_ps(v16, v15[7]);
    v25 = _mm_mul_ps(v22, v24);
    v187 = _mm_sub_ps(v23, v4->m_chassis.m_scratch3.m_quad);
    v26 = _mm_max_ps(_mm_add_ps(v21, v20), (__m128)xmmword_141A712D0);
    v27 = _mm_sub_ps(_mm_mul_ps(v22, v187), _mm_mul_ps(_mm_shuffle_ps(v187, v187, 201), m_quad));
    v28 = _mm_shuffle_ps(v27, v27, 201);
    v29 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v24, v24, 201), m_quad), v25);
    v30 = _mm_shuffle_ps(v29, v29, 201);
    v31 = _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v28, v28, 0), v18), _mm_mul_ps(_mm_shuffle_ps(v28, v28, 85), v17)),
            _mm_mul_ps(_mm_shuffle_ps(v28, v28, 170), v19));
    v32 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v30, v30, 0), v15[4]),
              _mm_mul_ps(_mm_shuffle_ps(v30, v30, 85), v15[5])),
            _mm_mul_ps(_mm_shuffle_ps(v30, v30, 170), v15[6]));
    v33 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v32, v32), v20), _mm_mul_ps(_mm_mul_ps(v31, v31), v21));
    v34 = _mm_shuffle_ps(v33, _mm_unpackhi_ps(v33, v26), 196);
    v35 = _mm_add_ps(_mm_shuffle_ps(v34, v34, 78), v34);
    v36 = _mm_add_ps(_mm_shuffle_ps(v35, v35, 177), v35);
    v37 = _mm_rcp_ps(v36);
    v13[-2] = _mm_shuffle_ps(v32, _mm_unpackhi_ps(v32, v36), 196);
    v38 = _mm_unpackhi_ps(v31, _mm_mul_ps(v159, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v37, v36)), v37)));
    v39 = p_m_forwardDirWs[-1].m_quad;
    v40 = v187;
    v13[-3] = _mm_shuffle_ps(v31, v38, 196);
    v37.m128_f32[0] = v13[-2].m128_f32[3] + *p_m_wheelSurfaceInertiaInv;
    v13[3].m128_i32[3] = v37.m128_i32[0];
    v38.m128_f32[0] = 1.0 / v37.m128_f32[0];
    v41 = _mm_shuffle_ps(v39, v39, 201);
    v13[3].m128_i32[2] = v38.m128_i32[0];
    v13[-1] = v39;
    v42 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v24, v24, 201), v39), _mm_mul_ps(v24, v41));
    v43 = _mm_shuffle_ps(v42, v42, 201);
    v44 = _mm_sub_ps(_mm_mul_ps(v40, v41), _mm_mul_ps(_mm_shuffle_ps(v40, v40, 201), v39));
    v45 = _mm_shuffle_ps(v44, v44, 201);
    v46 = _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v45, v45, 0), v18), _mm_mul_ps(_mm_shuffle_ps(v45, v45, 85), v17)),
            _mm_mul_ps(_mm_shuffle_ps(v45, v45, 170), v19));
    v47 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v43, v43, 0), v15[4]),
              _mm_mul_ps(_mm_shuffle_ps(v43, v43, 85), v15[5])),
            _mm_mul_ps(_mm_shuffle_ps(v43, v43, 170), v15[6]));
    v48 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v47, v47), v20), _mm_mul_ps(_mm_mul_ps(v46, v46), v21));
    v49 = _mm_shuffle_ps(v48, _mm_unpackhi_ps(v48, v26), 196);
    v50 = _mm_add_ps(_mm_shuffle_ps(v49, v49, 78), v49);
    v51 = _mm_add_ps(_mm_shuffle_ps(v50, v50, 177), v50);
    v52 = _mm_rcp_ps(v51);
    v13[1] = _mm_shuffle_ps(v47, _mm_unpackhi_ps(v47, v51), 196);
    *v13 = _mm_shuffle_ps(
             v46,
             _mm_unpackhi_ps(v46, _mm_mul_ps(v188, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v52, v51)), v52))),
             196);
    v13[3].m128_i32[0] = v13->m128_i32[3];
    v53 = v4->m_chassisAtLastIntegration.m_angularVel.m_quad;
    v54 = v4->m_chassisAtLastIntegration.m_linearVel.m_quad;
    v13[3].m128_i32[1] = v13[1].m128_i32[3];
    v55 = (__m128 *)p_m_forwardDirWs[1].m_quad.m128_u64[1];
    p_m_forwardRhs += 9;
    p_m_forwardDirWs += 6;
    v13 += 10;
    p_m_wheelSurfaceInertiaInv += 25;
    v56 = _mm_sub_ps(v54, v55[1]);
    v57 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v53, v13[-13]), _mm_mul_ps(v55[2], v13[-12])), _mm_mul_ps(v56, v13[-14]));
    v58 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v55[2], v13[-9]), _mm_mul_ps(v13[-10], v53)), _mm_mul_ps(v56, v13[-11]));
    *(p_m_forwardRhs - 9) = (float)((float)(_mm_shuffle_ps(v57, v57, 85).m128_f32[0]
                                          + _mm_shuffle_ps(v57, v57, 0).m128_f32[0])
                                  + _mm_shuffle_ps(v57, v57, 170).m128_f32[0])
                          + *(p_m_forwardRhs - 9);
    *(p_m_forwardRhs - 10) = (float)((float)(_mm_shuffle_ps(v58, v58, 85).m128_f32[0]
                                           + _mm_shuffle_ps(v58, v58, 0).m128_f32[0])
                                   + _mm_shuffle_ps(v58, v58, 170).m128_f32[0])
                           + *(p_m_forwardRhs - 10);
    --v11;
  }
  while ( v11 );
  m_groundObject = (__m128 *)v4->m_axleParams[0].m_groundObject;
  v60 = v4->m_chassis.m_invMasses.m_quad;
  p_m_groundObject = (__m128 **)&v4->m_axleParams[0].m_groundObject;
  if ( m_groundObject == (__m128 *)v4->m_axleParams[1].m_groundObject )
  {
    v62 = _mm_mul_ps(v162, v174);
    v63 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v60, v60, 255), v62),
              _mm_mul_ps(_mm_shuffle_ps(m_groundObject[3], m_groundObject[3], 255), v62)),
            _mm_add_ps(
              _mm_mul_ps(_mm_mul_ps(v163[0], v175), v4->m_chassis.m_invMasses.m_quad),
              _mm_mul_ps(_mm_mul_ps(v163[1], v176), m_groundObject[3])));
    *(float *)&v64 = (float)(_mm_shuffle_ps(v63, v63, 85).m128_f32[0] + _mm_shuffle_ps(v63, v63, 0).m128_f32[0])
                   + _mm_shuffle_ps(v63, v63, 170).m128_f32[0];
  }
  else
  {
    v65 = _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v60, v60, 255), _mm_mul_ps(v162, v174)),
            _mm_mul_ps(_mm_mul_ps(v163[0], v175), v60));
    *(float *)&v64 = (float)(_mm_shuffle_ps(v65, v65, 85).m128_f32[0] + _mm_shuffle_ps(v65, v65, 0).m128_f32[0])
                   + _mm_shuffle_ps(v65, v65, 170).m128_f32[0];
  }
  v66 = v167;
  v67 = (__m128 *)v161;
  v68 = (__m128 **)&v4->m_axleParams[0].m_groundObject;
  p_m_delayed_forward_impulse = &status->m_axis[0].m_delayed_forward_impulse;
  v70 = 2i64;
  v159.m128_u64[0] = __PAIR64__(v64, LODWORD(v167));
  v160 = *(float *)&v180;
  v159.m128_u64[1] = __PAIR64__(v180, v64);
  do
  {
    v71 = _mm_shuffle_ps(
            (__m128)*(unsigned int *)p_m_delayed_forward_impulse,
            (__m128)*(unsigned int *)p_m_delayed_forward_impulse,
            0);
    if ( v71.m128_f32[0] != 0.0 )
    {
      v72 = *v68;
      v73 = _mm_mul_ps(v4->m_chassis.m_invMasses.m_quad, v71);
      v74 = _mm_mul_ps((*v68)[3], v71);
      v75 = _mm_shuffle_ps(v74, v74, 255);
      v76 = _mm_mul_ps(v74, v67[2]);
      v4->m_chassis.m_linearVel.m_quad = _mm_add_ps(
                                           _mm_mul_ps(_mm_shuffle_ps(v73, v73, 255), *v67),
                                           v4->m_chassis.m_linearVel.m_quad);
      v72[1] = _mm_sub_ps(v72[1], _mm_mul_ps(v75, *v67));
      v77 = _mm_add_ps(_mm_mul_ps(v67[1], v73), v4->m_chassis.m_angularVel.m_quad);
      v4->m_chassis.m_angularVel.m_quad = v77;
      v77.m128_f32[0] = 0.0;
      v72[2] = _mm_add_ps(v76, v72[2]);
      scaleYOut = _mm_shuffle_ps(v77, v77, 0).m128_f32[0] + v71.m128_f32[0];
    }
    p_m_delayed_forward_impulse += 9;
    v68 += 12;
    v67 += 10;
    --v70;
  }
  while ( v70 );
  m_wheelDownForce = v4->m_axleParams[0].m_wheelDownForce;
  v79 = &status->m_axis[0].m_forwardRhs;
  p_m_forwardForce = &v4->m_axleParams[0].m_forwardForce;
  v81 = v163;
  v82 = 2i64;
  v83 = v4->m_axleParams[1].m_wheelDownForce;
  v84 = v83 * descr->m_axleDescr[1].m_wheelDownForceFactor;
  v85 = v83 + m_wheelDownForce;
  v86 = m_wheelDownForce * descr->m_axleDescr[0].m_wheelDownForceFactor;
  v87 = v85 * descr->m_axleDescr[0].m_wheelDownForceSumFactor;
  v88 = (float)(v85 * descr->m_axleDescr[1].m_wheelDownForceSumFactor) + v84;
  status->m_axis[0].m_skid_energy_density = 0.0;
  status->m_axis[1].m_skid_energy_density = 0.0;
  v178 = v88;
  *(float *)&v165[1] = v87 + v86;
  do
  {
    v89 = (__m128 *)*((_QWORD *)p_m_forwardForce - 4);
    v90 = *p_m_forwardForce;
    v91 = v4->m_chassis.m_angularVel.m_quad;
    v92 = _mm_sub_ps(v4->m_chassis.m_linearVel.m_quad, v89[1]);
    v93 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v81[-3], v91), _mm_mul_ps(v81[-2], v89[2])), _mm_mul_ps(v81[-4], v92));
    v94 = (float)(_mm_shuffle_ps(v93, v93, 85).m128_f32[0] + _mm_shuffle_ps(v93, v93, 0).m128_f32[0])
        + _mm_shuffle_ps(v93, v93, 170).m128_f32[0];
    v81[2].m128_f32[0] = v94;
    v95 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v81[1], v89[2]), _mm_mul_ps(v91, *v81)), _mm_mul_ps(v81[-1], v92));
    v96 = (float)((float)(_mm_shuffle_ps(v95, v95, 85).m128_f32[0] + _mm_shuffle_ps(v95, v95, 0).m128_f32[0])
                + _mm_shuffle_ps(v95, v95, 170).m128_f32[0])
        + (float)(*(v79 - 1) * 0.25);
    scaleYOut = v81[2].m128_f32[3];
    v97 = scaleYOut;
    v81[2].m128_f32[2] = v96;
    v98 = COERCE_FLOAT((unsigned int)(2 * LODWORD(v97)) >> 1) * stepInfo->m_deltaTime;
    if ( *((_BYTE *)p_m_forwardForce + 8) )
    {
      v99 = (float)(v98 * *(p_m_forwardForce - 4)) * v81[3].m128_f32[3];
      v100 = (float)((float)(*v79 * 0.5) + v94) * (float)(v81[3].m128_f32[3] * v81[3].m128_f32[0]);
      LODWORD(v101) = LODWORD(v94) ^ _xmm[0];
      v81[2].m128_i32[1] = LODWORD(v94) ^ _xmm[0];
      v102 = v100 * 0.5;
      scaleYOut = v102;
      if ( COERCE_FLOAT((unsigned int)(2 * LODWORD(v102)) >> 1) > v99 )
      {
        v103 = v102 <= 0.0;
        v102 = v99;
        if ( v103 )
          LODWORD(v102) = LODWORD(v99) ^ _xmm[0];
      }
      v90 = 0.0;
      v81[2].m128_f32[1] = v101 - v102;
    }
    else
    {
      *v79 = 0.0;
      v101 = *(v79 - 6);
      v81[2].m128_f32[1] = v101;
    }
    v104 = *(p_m_forwardForce - 3);
    v105 = *(p_m_forwardForce - 4);
    if ( v104 != 0.0 )
    {
      scaleYOut = fminf(
                    (float)(v104 * fsqrt((float)(v96 * v96) + (float)(v101 * v101))) + v105,
                    *(p_m_forwardForce - 2));
      v105 = fmaxf(0.0, scaleYOut);
    }
    v106 = v81[3].m128_f32[2];
    v107 = v90 * stepInfo->m_deltaTime;
    v81 += 10;
    p_m_forwardForce += 24;
    v79 += 9;
    v108 = v106 * v81[-8].m128_f32[1];
    v109 = v105 * v98;
    v81[-6].m128_f32[2] = v109;
    v81[-6].m128_f32[3] = v109;
    v110 = 1.0 / (float)(v109 + 1.4210855e-14);
    v81[-6].m128_f32[0] = v108 + v107;
    v81[-5].m128_f32[0] = v110;
    v81[-5].m128_f32[1] = v110;
    --v82;
  }
  while ( v82 );
  p_m_slipVelocityFactor = &v4->m_axleParams[0].m_slipVelocityFactor;
  if ( (float)(v4->m_axleParams[1].m_slipVelocityFactor + v4->m_axleParams[0].m_slipVelocityFactor) > 0.0 )
  {
    v112 = &retaddr;
    v113 = 2i64;
    *(float *)&retaddr = v4->m_axleParams[0].m_wheelDownForce;
    scaleYOut = v4->m_axleParams[1].m_wheelDownForce;
    v114 = scaleYOut;
    scaleYOut = 0.0;
    v115 = (float)(COERCE_FLOAT((unsigned int)(2 * LODWORD(v114)) >> 1)
                 + COERCE_FLOAT((unsigned int)(2 * (_DWORD)retaddr) >> 1))
         * descr->m_chassisMassInv;
    scaleYOut = FLOAT_10000_0;
    v116 = v115 * stepInfo->m_deltaTime;
    do
    {
      scaleYOut = *p_m_slipVelocityFactor;
      v117 = fmaxf(scaleYOut, 0.0);
      if ( v116 < v117 )
        v118 = v117 / v116;
      else
        v118 = *(float *)&FLOAT_1_0;
      scaleYOut = v118;
      v112 = (void **)((char *)v112 + 4);
      p_m_slipVelocityFactor += 24;
      *((float *)v112 - 1) = fminf(10000.0, v118);
      --v113;
    }
    while ( v113 );
    v159.m128_f32[3] = v160 * *((float *)&retaddr + 1);
    v159.m128_f32[0] = v66 * *(float *)&retaddr;
    scaleYOut = *((float *)&retaddr + 1) * *(float *)&retaddr;
    v166 = v166 / *(float *)&retaddr;
    *(float *)&v64 = fsqrt(*((float *)&retaddr + 1) * *(float *)&retaddr) * *(float *)&v64;
    v159.m128_i32[2] = v64;
    v159.m128_i32[1] = v64;
    v179 = v179 / *((float *)&retaddr + 1);
    v167 = v167 * *(float *)&retaddr;
    *(float *)&v180 = *(float *)&v180 * *((float *)&retaddr + 1);
  }
  v119 = (__m128)_xmm;
  v120 = _mm_mul_ps(_mm_shuffle_ps(v159, v159, 187), v159);
  v121 = _mm_sub_ps(_mm_shuffle_ps(v120, v120, 0), _mm_shuffle_ps(v120, v120, 85));
  if ( COERCE_FLOAT((unsigned int)(2 * v121.m128_i32[0]) >> 1) > 0.0 )
  {
    v122 = _mm_rcp_ps(v121);
    v123 = _mm_mul_ps(
             _mm_xor_ps(
               (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 80),
               _mm_shuffle_ps(v159, v159, 57)),
             _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v122, v121)), v122));
    v119 = _mm_shuffle_ps(v123, v123, 198);
  }
  LODWORD(v170) = COERCE_UNSIGNED_INT(
                    (float)(v177 * _mm_shuffle_ps(v119, v119, 85).m128_f32[0])
                  + (float)(*(float *)v165 * v119.m128_f32[0])) ^ _xmm[0];
  LODWORD(v183) = COERCE_UNSIGNED_INT(
                    (float)(_mm_shuffle_ps(v119, v119, 255).m128_f32[0] * v177)
                  + (float)(_mm_shuffle_ps(v119, v119, 170).m128_f32[0] * *(float *)v165)) ^ _xmm[0];
  v124 = (float)((float)(v172 * v170) * (float)(v172 * v170)) + (float)((float)(v169 * v171) * (float)(v169 * v171));
  scaleYOut = v164;
  v125 = (float)((float)(v185 * v183) * (float)(v185 * v183)) + (float)((float)(v182 * v184) * (float)(v182 * v184));
  if ( COERCE_FLOAT((unsigned int)(2 * LODWORD(v164)) >> 1) >= v4->m_maxVelocityForPositionalFriction )
  {
    *(_QWORD *)&status->m_axis[0].m_sideRhs = 0i64;
    *(_QWORD *)&status->m_axis[1].m_sideRhs = 0i64;
  }
  if ( v124 > 1.0 )
    goto LABEL_40;
  if ( v125 <= 1.0 )
  {
    v126 = &v171;
    m_axleDescr = descr->m_axleDescr;
    v128 = 2i64;
    do
    {
      v129 = *(v126 - 3);
      v130 = *(v126 - 4) * *v126;
      v131 = v129 * v126[1];
      if ( (float)((float)(v130 * v130) + (float)(v131 * v131)) < 1.0 )
      {
        *((_DWORD *)v126 - 3) = COERCE_UNSIGNED_INT(*(v126 - 10) * *(v126 - 8)) ^ _xmm[0];
      }
      else
      {
        hkCalculateFrictionalEllipsoidScale(m_axleDescr, v131, v130, scaleXOut, &scaleYOut);
        scaleYOut = scaleXOut[0] * *(v126 - 1);
        v132 = scaleYOut;
        scaleYOut = v129;
        LODWORD(v192) = (unsigned int)(2 * LODWORD(v132)) >> 1;
        LODWORD(retaddr) = LODWORD(v192) ^ _xmm[0];
        *(v126 - 3) = fminf(fmaxf(v129, COERCE_FLOAT(LODWORD(v192) ^ _xmm[0])), v192);
      }
      ++m_axleDescr;
      v126 += 40;
      v177 = v177 + (float)(*(float *)&v64 * *(v126 - 43));
      --v128;
    }
    while ( v128 );
    v133 = v170;
    v134 = v169;
    v135 = v182;
    v136 = v183;
    v137 = v185 * v183;
    status->m_axis[0].m_relativeSideForce = v172 * v170;
    status->m_axis[0].m_relativeForwardForce = v134 * v171;
    status->m_axis[1].m_relativeSideForce = v137;
    status->m_axis[1].m_relativeForwardForce = v135 * v184;
    *(_QWORD *)&status->m_axis[0].m_forward_slip_velocity = 0i64;
    *(_QWORD *)&status->m_axis[1].m_forward_slip_velocity = 0i64;
    goto LABEL_49;
  }
  if ( v124 > 1.0 )
  {
LABEL_40:
    v138 = (float)(1.0 / v124) * status->m_axis[0].m_sideRhs;
    status->m_axis[0].m_forwardRhs = (float)(1.0 / v124) * status->m_axis[0].m_forwardRhs;
    status->m_axis[0].m_sideRhs = v138;
  }
  if ( v125 > 1.0 )
  {
    v139 = (float)(1.0 / v125) * status->m_axis[1].m_sideRhs;
    status->m_axis[1].m_forwardRhs = (float)(1.0 / v125) * status->m_axis[1].m_forwardRhs;
    status->m_axis[1].m_sideRhs = v139;
  }
  if ( v124 <= v125 )
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
      &descr->m_axleDescr[v140],
      &status->m_axis[v140]);
    v140 = v141;
    v142 = v141;
    *(float *)&v165[40 * v141] = (float)(*(float *)&v64 * *(float *)(v145 + 132)) + *(float *)&v165[40 * v141];
    --v143;
  }
  while ( v143 );
  v136 = v183;
  stepInfo = *(hkpVehicleStepInfo **)scaleXOut;
  p_m_groundObject = (__m128 **)&v4->m_axleParams[0].m_groundObject;
  v146 = v181 * v186;
  v135 = v182;
  v133 = v170;
  v134 = v169;
  status->m_axis[0].m_forward_slip_velocity = v168 * v173;
  v147 = *(float *)v165;
  status->m_axis[1].m_forward_slip_velocity = v146;
  v148 = v177;
  status->m_axis[0].m_side_slip_velocity = v147;
  status->m_axis[1].m_side_slip_velocity = v148;
LABEL_49:
  status->m_axis[0].m_delayed_forward_impulse = v134;
  status->m_axis[1].m_delayed_forward_impulse = v135;
  v149 = &v162;
  status->m_axis[0].m_side_force = v133 * stepInfo->m_invDeltaTime;
  status->m_axis[1].m_side_force = v136 * stepInfo->m_invDeltaTime;
  do
  {
    v150 = *p_m_groundObject;
    v151 = (__m128)v149[5].m128_u32[1];
    v149 += 10;
    p_m_groundObject += 12;
    v152 = _mm_shuffle_ps(v151, v151, 0);
    v153 = _mm_mul_ps(v4->m_chassis.m_invMasses.m_quad, v152);
    v154 = _mm_mul_ps(v150[3], v152);
    v155 = _mm_mul_ps(_mm_shuffle_ps(v154, v154, 255), v149[-10]);
    v4->m_chassis.m_linearVel.m_quad = _mm_add_ps(
                                         _mm_mul_ps(_mm_shuffle_ps(v153, v153, 255), v149[-10]),
                                         v4->m_chassis.m_linearVel.m_quad);
    v156 = _mm_sub_ps(v150[1], v155);
    v157 = v149[-8];
    v150[1] = v156;
    v158 = _mm_add_ps(_mm_mul_ps(v149[-9], v153), v4->m_chassis.m_angularVel.m_quad);
    v4->m_chassis.m_angularVel.m_quad = v158;
    v158.m128_f32[0] = 0.0;
    v150[2] = _mm_add_ps(_mm_mul_ps(v157, v154), v150[2]);
    scaleXOut[0] = _mm_shuffle_ps(v158, v158, 0).m128_f32[0] + v152.m128_f32[0];
    --v5;
  }
  while ( v5 );
}

