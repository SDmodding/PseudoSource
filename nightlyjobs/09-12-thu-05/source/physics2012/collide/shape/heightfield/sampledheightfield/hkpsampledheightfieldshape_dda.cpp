// File Line: 15
// RVA: 0xD32E20
void hkpSampledHeightField_registerDdaRayCastFunction(void)
{
  hkpSampledHeightFieldShape::s_rayCastFunc = hkpSampledHeightFieldShape::castRayDda;
  hkpSampledHeightFieldShape::s_sphereCastFunc = hkpSampledHeightFieldShape::castSphereDda;
}

// File Line: 22
// RVA: 0x15CC980
void dynamic_initializer_for__hkOptionalComponent_hkpSampledHeightFieldShape_DdaCast__()
{
  hkOptionalComponent::hkOptionalComponent(
    &hkOptionalComponent_hkpSampledHeightFieldShape_DdaCast,
    "hkpSampledHeightFieldShape_DdaCast",
    (void (__fastcall *)())hkpSampledHeightField_registerDdaRayCastFunction);
}

// File Line: 29
// RVA: 0xD31C20
void __fastcall hkpSampledHeightFieldShape::castRayDda(hkpSampledHeightFieldShape *this, hkpShapeRayCastInput *input, hkpCdBody *cdBody, hkpRayHitCollector *collector)
{
  hkOptionalComponent_hkpSampledHeightFieldShape_DdaCast.m_isUsed.m_bool = 1;
  hkpSampledHeightFieldShape::castRayDdaInternal(this, input, cdBody, 0, 0.0, collector);
}

// File Line: 37
// RVA: 0xD31C50
void __fastcall hkpSampledHeightFieldShape::castSphereDda(hkpSampledHeightFieldShape *this, hkpHeightFieldShape::hkpSphereCastInput *input, hkpCdBody *cdBody, hkpRayHitCollector *collector)
{
  hkVector4f v4; // xmm1
  __int128 v5; // xmm0
  __int128 v6; // xmm1
  hkVector4f v7; // xmm0
  hkVector4f v8; // xmm1
  hkVector4f v9; // [rsp+30h] [rbp-48h]
  __m128 v10; // [rsp+40h] [rbp-38h]
  __int128 v11; // [rsp+50h] [rbp-28h]
  __int128 v12; // [rsp+60h] [rbp-18h]

  hkOptionalComponent_hkpSampledHeightFieldShape_DdaCast.m_isUsed.m_bool = 1;
  v4.m_quad = (__m128)input->m_to;
  v9.m_quad = (__m128)input->m_from;
  v5 = *(_OWORD *)&input->m_filterInfo;
  v10 = v4.m_quad;
  v6 = *(_OWORD *)&input->m_collidable;
  v11 = v5;
  v7.m_quad = (__m128)input->m_from;
  v12 = v6;
  v8.m_quad = (__m128)input->m_to;
  v9.m_quad = v7.m_quad;
  v7.m_quad.m128_i32[0] = LODWORD(input->m_maxExtraPenetration);
  v10 = v8.m_quad;
  hkpSampledHeightFieldShape::castRayDdaInternal(
    this,
    (hkpShapeRayCastInput *)&v9,
    cdBody,
    (hkBool)1,
    v7.m_quad.m128_f32[0],
    collector);
}

// File Line: 77
// RVA: 0xD31CC0
void __fastcall hkpSampledHeightFieldShape::castRayDdaInternal(hkpSampledHeightFieldShape *this, hkpShapeRayCastInput *input, hkpCdBody *cdBody, hkBool reportPenetratingStartPosition, float maxExtraPenetration, hkpRayHitCollector *collector)
{
  hkpSampledHeightFieldShape *v6; // rdi
  hkpCdBody *v7; // r13
  hkpShapeRayCastInput *v8; // rbx
  __int64 v9; // r8
  _QWORD *v10; // r9
  _QWORD *v11; // rcx
  unsigned __int64 v12; // rax
  signed __int64 v13; // rcx
  __m128 v14; // xmm3
  __m128 v15; // xmm0
  __m128i v16; // xmm1
  char v17; // al
  float v18; // xmm7_4
  __m128 v19; // xmm15
  __m128 v20; // xmm10
  float v21; // xmm4_4
  float v22; // xmm9_4
  float v23; // xmm0_4
  signed __int64 v24; // r10
  float v25; // xmm8_4
  unsigned __int64 v26; // rcx
  signed int v27; // er14
  signed __int64 v28; // r8
  float v29; // xmm3_4
  float v30; // xmm2_4
  float v31; // xmm0_4
  float v32; // xmm1_4
  signed int v33; // edx
  float v34; // xmm12_4
  float v35; // xmm13_4
  unsigned int v36; // er13
  int v37; // esi
  __m128 v38; // xmm2
  int v39; // er8
  int v40; // er11
  int v41; // ebx
  float v42; // xmm0_4
  float v43; // xmm1_4
  __m128 v44; // xmm5
  __m128i v45; // xmm4
  __m128 v46; // xmm2
  __m128 v47; // xmm3
  int v48; // er9
  __m128 v49; // xmm3
  __m128 v50; // xmm2
  signed int v51; // ecx
  int v52; // edx
  int v53; // er9
  float v54; // xmm0_4
  float v55; // xmm1_4
  __m128 v56; // xmm6
  __m128 v57; // xmm11
  float v58; // xmm14_4
  __m128 v59; // xmm5
  __m128i v60; // xmm4
  __m128 v61; // xmm2
  __m128 v62; // xmm3
  int v63; // er9
  __m128 v64; // xmm2
  __m128 v65; // xmm10
  signed int v66; // ecx
  char v67; // bl
  signed int v68; // er9
  int v69; // er8
  float v70; // xmm13_4
  float v71; // xmm1_4
  float v72; // xmm12_4
  __int64 v73; // rax
  float v74; // xmm1_4
  signed int v75; // esi
  float v76; // xmm10_4
  __int64 v77; // rcx
  float v78; // xmm7_4
  float v79; // xmm0_4
  unsigned int v80; // er15
  unsigned int v81; // er14
  __int64 v82; // r12
  unsigned int v83; // er13
  __int64 v84; // r8
  float v85; // xmm9_4
  __m128 v86; // xmm0
  float v87; // xmm6_4
  float v88; // xmm2_4
  __m128i v89; // xmm1
  float v90; // xmm6_4
  float v91; // xmm11_4
  float v92; // xmm6_4
  float v93; // xmm0_4
  float v94; // xmm11_4
  float v95; // xmm5_4
  float v96; // xmm7_4
  float v97; // xmm3_4
  hkBaseObjectVtbl *v98; // rax
  unsigned int v99; // er12
  __int64 v100; // r8
  hkBaseObjectVtbl *v101; // rax
  int v102; // ecx
  float v103; // xmm1_4
  float v104; // xmm6_4
  bool v105; // zf
  bool v106; // sf
  unsigned __int8 v107; // of
  void (__fastcall **v108)(float *, hkpCdBody *, __m128 *); // rax
  __m128 v109; // xmm5
  __m128 v110; // xmm1
  __m128 v111; // xmm2
  __m128 v112; // xmm3
  int v113; // er9
  float v114; // xmm9_4
  int v115; // er9
  unsigned int v116; // esi
  unsigned int v117; // ebx
  hkBaseObjectVtbl *v118; // rax
  float v119; // xmm6_4
  float v120; // xmm7_4
  __m128 v121; // xmm0
  hkBaseObjectVtbl *v122; // rax
  float v123; // xmm12_4
  hkBaseObjectVtbl *v124; // rax
  float v125; // xmm0_4
  float v126; // xmm3_4
  float v127; // xmm0_4
  float v128; // xmm3_4
  float v129; // xmm9_4
  hkBaseObjectVtbl *v130; // rax
  float v131; // xmm12_4
  float v132; // xmm2_4
  float v133; // xmm0_4
  float v134; // xmm2_4
  float v135; // xmm15_4
  float v136; // xmm10_4
  __m128 v137; // xmm5
  void (__fastcall **v138)(float *, hkpCdBody *, __m128 *); // rax
  __m128 v139; // xmm1
  __m128 v140; // xmm2
  __m128 v141; // xmm3
  _QWORD *v142; // r9
  unsigned __int64 v143; // r8
  unsigned __int64 v144; // rax
  unsigned int v145; // [rsp+20h] [rbp-B0h]
  unsigned int v146; // [rsp+28h] [rbp-A8h]
  int v147; // [rsp+2Ch] [rbp-A4h]
  unsigned int v148; // [rsp+30h] [rbp-A0h]
  float v149; // [rsp+38h] [rbp-98h]
  float v150; // [rsp+3Ch] [rbp-94h]
  float v151; // [rsp+40h] [rbp-90h]
  int v152; // [rsp+48h] [rbp-88h]
  int v153; // [rsp+4Ch] [rbp-84h]
  __m128i v154; // [rsp+50h] [rbp-80h]
  __m128 v155; // [rsp+60h] [rbp-70h]
  __int64 v156; // [rsp+70h] [rbp-60h]
  float v157; // [rsp+78h] [rbp-58h]
  __m128 v158; // [rsp+80h] [rbp-50h]
  __int64 v159; // [rsp+90h] [rbp-40h]
  __m128 v160; // [rsp+A0h] [rbp-30h]
  float v161; // [rsp+B0h] [rbp-20h]
  unsigned int v162; // [rsp+B4h] [rbp-1Ch]
  int v163; // [rsp+C0h] [rbp-10h]
  int v164; // [rsp+E0h] [rbp+10h]
  char v165; // [rsp+1E0h] [rbp+110h]
  int v166; // [rsp+1E8h] [rbp+118h]
  hkpCdBody *v167; // [rsp+1F0h] [rbp+120h]
  char v168; // [rsp+1F8h] [rbp+128h]
  float vars0; // [rsp+200h] [rbp+130h]
  float *retaddr; // [rsp+208h] [rbp+138h]

  v6 = this;
  v7 = cdBody;
  v8 = input;
  v10 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v11 = (_QWORD *)v10[1];
  if ( (unsigned __int64)v11 < v10[3] )
  {
    *v11 = "TtrcHeightField";
    v12 = __rdtsc();
    v13 = (signed __int64)(v11 + 2);
    *(_DWORD *)(v13 - 8) = v12;
    v10[1] = v13;
  }
  v14 = v6->m_floatToIntScale.m_quad;
  v15 = _mm_mul_ps(_mm_add_ps(v6->m_floatToIntOffsetFloorCorrected.m_quad, v8->m_from.m_quad), v14);
  v19 = _mm_mul_ps(v14, v8->m_from.m_quad);
  v20 = _mm_mul_ps(v8->m_to.m_quad, v14);
  v16 = _mm_xor_si128(
          (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v15),
          _mm_cvttps_epi32(v15));
  v159 = (unsigned __int128)_mm_packs_epi32(v16, v16);
  v154 = (__m128i)v19;
  v146 = (signed __int16)v159;
  v155 = v20;
  v148 = SWORD2(v159);
  ((void (__fastcall *)(hkpSampledHeightFieldShape *, char *, __int64, _QWORD *))v6->vfptr[10].__first_virtual_table_function__)(
    v6,
    &v165,
    v9,
    v10);
  v17 = v165;
  v18 = v19.m128_f32[0];
  v19.m128_i32[0] = (unsigned __int128)_mm_shuffle_ps(v19, v19, 85);
  v20.m128_i32[0] = (unsigned __int128)_mm_shuffle_ps(v20, v20, 85);
  v21 = v155.m128_f32[0];
  v154.m128i_i32[3] = v19.m128_i32[0];
  v155.m128_i32[3] = v20.m128_i32[0];
  if ( v165 )
  {
    v22 = *(float *)v154.m128i_i32 - v19.m128_f32[2];
    v23 = v155.m128_f32[0] - v20.m128_f32[2];
  }
  else
  {
    v22 = *(float *)&v154.m128i_i32[2] + v18;
    v23 = v155.m128_f32[2] + v155.m128_f32[0];
  }
  v24 = 3i64;
  v25 = 0.0;
  v26 = 0i64;
  v27 = 1;
  v28 = 3i64;
  v155.m128_f32[1] = v23;
  *(float *)&v154.m128i_i32[1] = v22;
  do
  {
    v29 = *(float *)&v154.m128i_i32[v26 / 4];
    v30 = v155.m128_f32[v26 / 4] - v29;
    v166 = LODWORD(v30);
    LODWORD(v31) = (unsigned int)(2 * LODWORD(v30)) >> 1;
    v155.m128_f32[v26 / 4] = v31;
    if ( v31 >= 0.000030517578 )
    {
      v32 = 1.0 / v30;
      *(float *)((char *)&v156 + v26) = 1.0 / v30;
      if ( v30 >= 0.0 )
      {
        *(float *)((char *)&v156 + v26) = v32;
        v33 = 1;
        *(int *)((char *)&v152 + v26) = 1;
      }
      else
      {
        v33 = -1;
        *(int *)((char *)&v152 + v26) = -1;
        *(_DWORD *)((char *)&v156 + v26) = LODWORD(v32) ^ _xmm[0];
      }
      if ( (float)(v29 * v30) > 0.0 )
        *(unsigned int *)((char *)&v146 + v26) += v33;
      *(float *)((char *)&v149 + v26) = (float)((float)*(signed int *)((char *)&v146 + v26) - v29) * v32;
    }
    else
    {
      *(_DWORD *)((char *)&v156 + v26) = 0;
      *(int *)((char *)&v152 + v26) = -1;
      *(float *)((char *)&v149 + v26) = 3.40282e38;
    }
    v26 += 4i64;
    --v28;
  }
  while ( v28 );
  v34 = v157;
  v35 = *(float *)&v156;
  if ( (float)(v157 + *(float *)&v156) == 0.0
    || (float)(*((float *)&v156 + 1) + *(float *)&v156) == 0.0
    || (float)(*((float *)&v156 + 1) + v157) == 0.0 )
  {
    v116 = v146;
    if ( v146 >= v6->m_xRes - 1 )
      goto LABEL_154;
    v117 = v148;
    if ( v148 >= v6->m_zRes - 1 )
      goto LABEL_154;
    v118 = v6->vfptr;
    v161 = 1.0;
    v162 = -1;
    v164 = 0;
    v163 = -1;
    v119 = v19.m128_f32[2] - (float)(signed int)v148;
    v120 = v18 - (float)(signed int)v146;
    v121 = _mm_unpackhi_ps(*(__m128 *)_xmm, v160);
    v160 = _mm_shuffle_ps(*(__m128 *)_xmm, v121, 196);
    ((void (__fastcall *)(hkpSampledHeightFieldShape *, int *))v118[10].__first_virtual_table_function__)(v6, &v166);
    v122 = v6->vfptr;
    if ( (_BYTE)v166 )
    {
      ((void (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v122[10].__vecDelDtor)(v6, v116, v117);
      v123 = v121.m128_f32[0];
      ((void (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v6->vfptr[10].__vecDelDtor)(
        v6,
        v116 + 1,
        v117 + 1);
      v124 = v6->vfptr;
      if ( v120 <= v119 )
      {
        ((void (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v124[10].__vecDelDtor)(v6, v116, v117 + 1);
        v27 = 0;
        v127 = v121.m128_f32[0] - v121.m128_f32[0];
        v160.m128_i32[0] = LODWORD(v127) ^ _xmm[0];
        v160.m128_i32[2] = LODWORD(v127) ^ _xmm[0];
        v128 = (float)((float)(v127 * v119) + v123) + (float)(v127 * v120);
        goto LABEL_144;
      }
      ((void (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v124[10].__vecDelDtor)(v6, v116 + 1, v117);
      v160.m128_i32[2] = COERCE_UNSIGNED_INT(v121.m128_f32[0] - v121.m128_f32[0]) ^ _xmm[0];
      v125 = v121.m128_f32[0] - v121.m128_f32[0];
      v126 = (float)(v125 * v119) + v123;
      v160.m128_i32[0] = LODWORD(v125) ^ _xmm[0];
    }
    else
    {
      ((void (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v122[10].__vecDelDtor)(v6, v116 + 1, v117);
      v129 = v121.m128_f32[0];
      ((void (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v6->vfptr[10].__vecDelDtor)(
        v6,
        v116,
        v117 + 1);
      v130 = v6->vfptr;
      v131 = v121.m128_f32[0];
      if ( (float)(v120 + v119) > 1.0 )
      {
        ((void (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v130[10].__vecDelDtor)(
          v6,
          v116 + 1,
          v117 + 1);
        v132 = v121.m128_f32[0];
        v133 = v121.m128_f32[0] - v121.m128_f32[0];
        v134 = v132 - v131;
        v160.m128_i32[0] = LODWORD(v134) ^ _xmm[0];
        v160.m128_i32[2] = LODWORD(v133) ^ _xmm[0];
        v128 = (float)((float)(v120 - 1.0) * v134) + (float)((float)(v133 * v119) + v129);
        goto LABEL_144;
      }
      ((void (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v130[10].__vecDelDtor)(v6, v116, v117);
      v27 = 0;
      v160.m128_i32[2] = COERCE_UNSIGNED_INT(v121.m128_f32[0] - v121.m128_f32[0]) ^ _xmm[0];
      v126 = (float)((float)(v121.m128_f32[0] - v121.m128_f32[0]) * v119) + v121.m128_f32[0];
      v125 = v121.m128_f32[0] - v121.m128_f32[0];
      v160.m128_i32[0] = LODWORD(v125) ^ _xmm[0];
    }
    v128 = v126 + (float)(v125 * v120);
LABEL_144:
    v135 = v19.m128_f32[0] - v128;
    v136 = v20.m128_f32[0] - v128;
    if ( v136 > v135 )
      goto LABEL_154;
    if ( v168 )
    {
      if ( v135 < 0.0 )
      {
        if ( v136 > (float)(v135 - vars0) )
          goto LABEL_154;
        goto LABEL_152;
      }
    }
    else if ( v135 < 0.0 )
    {
      goto LABEL_154;
    }
    if ( v136 >= 0.0 )
      goto LABEL_154;
    v25 = v135 / (float)(v135 - v136);
LABEL_152:
    if ( v25 < retaddr[2] )
    {
      v161 = v25;
      v137 = _mm_mul_ps(v160, v6->m_floatToIntScale.m_quad);
      v162 = v27 + 2 * (v116 + (v117 << 15));
      v138 = *(void (__fastcall ***)(float *, hkpCdBody *, __m128 *))retaddr;
      v139 = _mm_mul_ps(v137, v137);
      v140 = _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v139, v139, 85), _mm_shuffle_ps(v139, v139, 0)),
               _mm_shuffle_ps(v139, v139, 170));
      v141 = _mm_rsqrt_ps(v140);
      v160 = _mm_mul_ps(
               v137,
               _mm_andnot_ps(
                 _mm_cmpleps(v140, (__m128)0i64),
                 _mm_mul_ps(
                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v141, v140), v141)),
                   _mm_mul_ps(*(__m128 *)_xmm, v141))));
      (*v138)(retaddr, v7, &v160);
    }
    goto LABEL_154;
  }
  v36 = v6->m_xRes;
  v37 = v152;
  v38 = (__m128)v154;
  v39 = v146;
  v40 = v154.m128i_i32[0];
  _mm_store_si128((__m128i *)&v158, v154);
  v41 = v39;
  v42 = (float)(signed int)(v36 - 1);
  if ( v37 <= 0 )
  {
    if ( v21 > v42 || v18 < 0.0 )
      goto LABEL_154;
    if ( v39 > (signed int)(v36 - 2) )
    {
      v39 = v36 - 2;
      v146 = v36 - 2;
      v43 = (float)(v18 - v42) * v35;
      goto LABEL_28;
    }
LABEL_32:
    v52 = v148;
    goto LABEL_33;
  }
  if ( v21 < 0.0 || v18 > v42 )
    goto LABEL_154;
  if ( v39 > 0 )
    goto LABEL_32;
  v39 = 1;
  v146 = 1;
  LODWORD(v43) = COERCE_UNSIGNED_INT(v35 * v18) ^ _xmm[0];
LABEL_28:
  v149 = v35 + v43;
  v44 = _mm_add_ps(
          _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(v43), (__m128)LODWORD(v43), 0), _mm_sub_ps(v155, v38)),
          v38);
  v45 = (__m128i)COERCE_UNSIGNED_INT(v155.m128_f32[2] * v43);
  v158 = v44;
  v44.m128_i32[0] = (unsigned __int128)_mm_shuffle_ps(v44, v44, 170);
  v166 = v44.m128_i32[0];
  v46 = _mm_cmpltps(*(__m128 *)two23, (__m128)_mm_srli_epi32(_mm_slli_epi32(v45, 1u), 1u));
  v47 = _mm_sub_ps(
          _mm_add_ps(_mm_add_ps(_mm_sub_ps((__m128)v45, *(__m128 *)two23), *(__m128 *)two23), *(__m128 *)two23),
          *(__m128 *)two23);
  v48 = v148
      - 2
      + v40
      * (signed int)COERCE_FLOAT(*(unsigned __int128 *)&_mm_andnot_ps(
                                                          v46,
                                                          _mm_add_ps(
                                                            _mm_cvtepi32_ps((__m128i)_mm_cmpltps((__m128)v45, v47)),
                                                            v47)) | v46.m128_i32[0] & v45.m128i_i32[0]);
  v49 = _mm_sub_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_sub_ps((__m128)v44.m128_u32[0], *(__m128 *)two23), *(__m128 *)two23),
            *(__m128 *)two23),
          *(__m128 *)two23);
  v50 = _mm_cmpltps(*(__m128 *)two23, (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)v44.m128_u32[0], 1u), 1u));
  v51 = (signed int)COERCE_FLOAT(*(unsigned __int128 *)&_mm_andnot_ps(
                                                          v50,
                                                          _mm_add_ps(
                                                            _mm_cvtepi32_ps((__m128i)_mm_cmpltps(
                                                                                       (__m128)v44.m128_u32[0],
                                                                                       v49)),
                                                            v49)) | v50.m128_i32[0] & v44.m128_i32[0]);
  if ( v51 >= v48 )
    v48 = v51 + 1;
  v52 = v48 + (v40 >> 1);
  v148 = v48 + (v40 >> 1);
  if ( v34 != 0.0 )
    v151 = (float)((float)v52 - v19.m128_f32[2]) * v157;
LABEL_33:
  v53 = v6->m_zRes;
  v54 = (float)(v6->m_zRes - 1);
  if ( v40 <= 0 )
  {
    if ( v20.m128_f32[2] > v54 || v19.m128_f32[2] < 0.0 )
      goto LABEL_154;
    if ( v52 > v53 - 2 )
    {
      v52 = v53 - 2;
      v148 = v53 - 2;
      v55 = (float)(v19.m128_f32[2] - v54) * v34;
      goto LABEL_42;
    }
LABEL_46:
    v57 = v155;
    v56 = (__m128)v154;
    v58 = v155.m128_f32[0];
    goto LABEL_47;
  }
  if ( v20.m128_f32[2] < 0.0 || v19.m128_f32[2] > v54 )
    goto LABEL_154;
  if ( v52 > 0 )
    goto LABEL_46;
  v52 = 1;
  v148 = 1;
  LODWORD(v55) = COERCE_UNSIGNED_INT(v34 * v19.m128_f32[2]) ^ _xmm[0];
LABEL_42:
  v56 = (__m128)v154;
  v57 = v155;
  v58 = v155.m128_f32[0];
  v151 = v34 + v55;
  v59 = _mm_add_ps(
          _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(v55), (__m128)LODWORD(v55), 0), _mm_sub_ps(v155, (__m128)v154)),
          (__m128)v154);
  v60 = (__m128i)COERCE_UNSIGNED_INT(v155.m128_f32[0] * v55);
  v166 = v59.m128_i32[0];
  v158 = v59;
  v61 = _mm_cmpltps(*(__m128 *)two23, (__m128)_mm_srli_epi32(_mm_slli_epi32(v60, 1u), 1u));
  v62 = _mm_sub_ps(
          _mm_add_ps(_mm_add_ps(_mm_sub_ps((__m128)v60, *(__m128 *)two23), *(__m128 *)two23), *(__m128 *)two23),
          *(__m128 *)two23);
  v63 = v37
      * (signed int)COERCE_FLOAT(*(unsigned __int128 *)&_mm_andnot_ps(
                                                          v61,
                                                          _mm_add_ps(
                                                            _mm_cvtepi32_ps((__m128i)_mm_cmpltps((__m128)v60, v62)),
                                                            v62)) | v61.m128_i32[0] & v60.m128i_i32[0])
      + v41
      - 2;
  v64 = _mm_sub_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_sub_ps((__m128)v59.m128_u32[0], *(__m128 *)two23), *(__m128 *)two23),
            *(__m128 *)two23),
          *(__m128 *)two23);
  v65 = _mm_cmpltps(*(__m128 *)two23, (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)v59.m128_u32[0], 1u), 1u));
  v66 = (signed int)COERCE_FLOAT(*(unsigned __int128 *)&_mm_andnot_ps(
                                                          v65,
                                                          _mm_add_ps(
                                                            _mm_cvtepi32_ps((__m128i)_mm_cmpltps(
                                                                                       (__m128)v59.m128_u32[0],
                                                                                       v64)),
                                                            v64)) | v65.m128_i32[0] & v59.m128_i32[0]);
  if ( v66 >= v63 )
    v63 = v66 + 1;
  v39 = v63 + (v37 >> 1);
  v146 = v63 + (v37 >> 1);
  if ( v35 != 0.0 )
    v149 = (float)((float)v39 - v18) * *(float *)&v156;
LABEL_47:
  if ( v39 >= v36 || v39 - v37 >= v36 )
    goto LABEL_154;
  v67 = (v17 != 0) ^ ((v37 ^ v40) >= 0);
  if ( *((float *)&v156 + 1) == 0.0 )
    v67 = 0;
  v68 = 2;
  v166 = 2;
  if ( v17 )
    v69 = v39 - v52;
  else
    v69 = v52 + v39;
  v70 = *(float *)&FLOAT_1_0;
  v147 = v69;
  v71 = v158.m128_f32[1] - (float)v69;
  if ( v67 )
  {
    if ( COERCE_FLOAT((unsigned int)(2 * LODWORD(v71)) >> 1) > 1.0 )
    {
      v69 -= v153;
LABEL_60:
      v147 = v69;
      goto LABEL_61;
    }
    v68 = 0;
    v166 = 0;
  }
  else if ( (float)((float)v153 * v71) > 0.0 )
  {
    v68 = 0;
    v166 = 0;
    v69 += v153;
    goto LABEL_60;
  }
LABEL_61:
  v72 = FLOAT_3_40282e38;
  if ( *((float *)&v156 + 1) == 0.0 )
    v150 = 3.40282e38;
  else
    v150 = (float)((float)((float)v69 - v22) * *((float *)&v156 + 1)) * (float)v153;
  v73 = 0i64;
  do
  {
    v74 = *(float *)((char *)&v156 + v73);
    if ( v74 == 0.0 )
      *(_DWORD *)((char *)&v156 + v73) = -8388626;
    else
      *(float *)((char *)&v156 + v73) = *(float *)((char *)&v149 + v73) - v74;
    v73 += 4i64;
    --v24;
  }
  while ( v24 );
  if ( v67 )
  {
    if ( v68 )
    {
      v75 = 2;
      if ( *(float *)&v156 > v157 )
        v75 = 0;
    }
    else
    {
      v75 = 1;
    }
  }
  else if ( v58 >= v155.m128_f32[2] )
  {
    v75 = 0;
    if ( !v68 )
    {
      LOBYTE(v75) = *((float *)&v156 + 1) <= v157;
      ++v75;
    }
  }
  else if ( v68 )
  {
    v75 = 2;
  }
  else
  {
    v75 = 0;
    LOBYTE(v75) = *(float *)&v156 <= *((float *)&v156 + 1);
  }
  v76 = FLOAT_N1_0;
  v77 = v75;
  v78 = 0.0;
  v79 = *(&v149 + v75);
  *(&v146 + v77) -= *(&v152 + v75);
  v80 = v146;
  *(&v149 + v77) = v79 - *((float *)&v156 + v75);
  if ( v80 < v36 )
  {
    while ( 1 )
    {
      v81 = v148;
      if ( v148 >= v6->m_zRes || v76 > retaddr[2] )
        goto LABEL_154;
      v82 = v75;
      v83 = v80 - v152;
      v156 = v75;
      v84 = v148;
      v85 = *(&v149 + v75);
      v86 = _mm_sub_ps(v57, v56);
      v158 = _mm_add_ps(
               _mm_mul_ps(
                 _mm_shuffle_ps((__m128)*((unsigned int *)&v149 + v75), (__m128)*((unsigned int *)&v149 + v75), 0),
                 v86),
               v56);
      if ( !v75 )
        break;
      if ( v75 == 2 )
      {
        ((void (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v6->vfptr[10].__vecDelDtor)(v6, v83, v148);
        v87 = v86.m128_f32[0];
        ((void (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v6->vfptr[10].__vecDelDtor)(v6, v80, v81);
        v88 = v158.m128_f32[0];
        v89 = _mm_cvtsi32_si128(v80);
        goto LABEL_86;
      }
      v145 = v148;
      v86.m128_f32[0] = (float)(signed int)v80;
      *(float *)&v154.m128i_i32[2] = v158.m128_f32[0] - (float)(signed int)v80;
      LODWORD(v91) = (unsigned int)(2 * COERCE_SIGNED_INT(v158.m128_f32[0] - (float)(signed int)v80)) >> 1;
      if ( v67 )
        v145 = v148 - v40;
      else
        v84 = v148 - v40;
      ((void (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, __int64))v6->vfptr[10].__vecDelDtor)(v6, v83, v84);
      ((void (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v6->vfptr[10].__vecDelDtor)(v6, v80, v145);
      v90 = (float)(v86.m128_f32[0] - v86.m128_f32[0]) * v91;
LABEL_93:
      v92 = v90 + v86.m128_f32[0];
      if ( v168 )
      {
        if ( v158.m128_f32[3] >= v92 )
          goto $setAndWalk;
        v93 = (float)(v78 - v72) - (float)((float)(v85 - v76) * vars0);
        if ( (float)(v158.m128_f32[3] - v92) >= v93 )
          goto $setAndWalk;
        if ( (float)(v78 - v72) <= 0.0 )
        {
          LODWORD(v159) = 0;
          *(float *)&v154.m128i_i32[2] = v76;
          v94 = fmaxf(0.0, v76);
          goto $reportHit;
        }
      }
      else if ( v158.m128_f32[3] >= v92 || v78 < v72 )
      {
$setAndWalk:
        v72 = v92;
        v78 = v158.m128_f32[3];
        v76 = v85;
        goto $walk;
      }
      v95 = v158.m128_f32[3] - v92;
      if ( v76 < 0.0 )
      {
        v97 = v19.m128_f32[0]
            - (float)((float)((float)(v70 - (float)(v85 / (float)(v85 - v76))) * v92)
                    + (float)((float)(v85 / (float)(v85 - v76)) * v72));
        if ( v97 < 0.0 )
        {
          if ( !v168 )
            goto $setAndWalk;
          v97 = 0.0;
        }
        v93 = v97 - v95;
        v94 = (float)(v97 / (float)(v97 - v95)) * v85;
      }
      else
      {
        v96 = v78 - v72;
        v93 = v96 - v95;
        v94 = (float)((float)(v96 / (float)(v96 - v95)) * (float)(v85 - v76)) + v76;
      }
$reportHit:
      v72 = v92;
      v78 = v158.m128_f32[3];
      v76 = v85;
      if ( v94 > retaddr[2] )
        goto LABEL_154;
      v98 = v6->vfptr;
      v161 = 1.0;
      v99 = v81 - v154.m128i_i32[0];
      v162 = -1;
      v164 = 0;
      v163 = -1;
      v160.m128_i32[3] = 0;
      v160.m128_i32[1] = 1065353216;
      v100 = v81 - v154.m128i_i32[0];
      if ( v67 )
      {
        ((void (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, __int64))v98[10].__vecDelDtor)(v6, v80, v100);
        ((void (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v6->vfptr[10].__vecDelDtor)(v6, v83, v81);
        v101 = v6->vfptr;
        if ( v75 != 1 )
        {
          ((void (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v101[10].__vecDelDtor)(v6, v80, v81);
          v107 = __OFSUB__(v81, v99);
          v105 = v81 == v99;
          v106 = (signed int)(v81 - v99) < 0;
          v102 = 0;
          v103 = v93 - v93;
          v104 = v93 - v93;
          goto LABEL_117;
        }
        ((void (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v101[10].__vecDelDtor)(v6, v83, v99);
        v102 = 0;
        v103 = v93 - v93;
        v104 = v93 - v93;
      }
      else
      {
        ((void (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, __int64))v98[10].__vecDelDtor)(v6, v83, v100);
        ((void (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v6->vfptr[10].__vecDelDtor)(v6, v80, v81);
        if ( v75 && (v75 != 1 || v58 >= v155.m128_f32[2]) )
        {
          ((void (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v6->vfptr[10].__vecDelDtor)(v6, v83, v81);
          v107 = __OFSUB__(v81, v99);
          v105 = v81 == v99;
          v106 = (signed int)(v81 - v99) < 0;
          v102 = 0;
          v104 = v93 - v93;
          v103 = v93 - v93;
          goto LABEL_117;
        }
        ((void (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v6->vfptr[10].__vecDelDtor)(v6, v80, v99);
        v102 = 0;
        v103 = v93 - v93;
        v104 = v93 - v93;
      }
      v107 = __OFSUB__(v99, v81);
      v105 = v99 == v81;
      v106 = (signed int)(v99 - v81) < 0;
LABEL_117:
      LOBYTE(v102) = !((unsigned __int8)(v106 ^ v107) | v105);
      v161 = v94;
      v160.m128_f32[0] = v103 * (float)v152;
      v160.m128_f32[2] = v104 * (float)v154.m128i_i32[0];
      v162 = ((v165 != 0) ^ v102) - 65538 + 2 * (v80 + ((v81 - (v154.m128i_i32[0] >> 1)) << 15) - (v152 >> 1));
      v108 = *(void (__fastcall ***)(float *, hkpCdBody *, __m128 *))retaddr;
      v109 = _mm_mul_ps(v160, v6->m_floatToIntScale.m_quad);
      v110 = _mm_mul_ps(v109, v109);
      v111 = _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v110, v110, 85), _mm_shuffle_ps(v110, v110, 0)),
               _mm_shuffle_ps(v110, v110, 170));
      v112 = _mm_rsqrt_ps(v111);
      v160 = _mm_mul_ps(
               v109,
               _mm_andnot_ps(
                 _mm_cmpleps(v111, (__m128)0i64),
                 _mm_mul_ps(
                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v112, v111), v112)),
                   _mm_mul_ps(*(__m128 *)_xmm, v112))));
      (*v108)(retaddr, v167, &v160);
      v82 = v156;
      if ( v168 )
        v168 = 0;
$walk:
      v113 = v166;
      v114 = v85 + *((float *)&v156 + v82);
      *(&v146 + v82) += *(&v152 + v82);
      v115 = v113 ^ 2;
      v58 = v155.m128_f32[0];
      *(&v149 + v82) = v114;
      v166 = v115;
      if ( v67 )
      {
        if ( v115 )
        {
          v75 = 2;
          if ( v151 > v149 )
            v75 = 0;
        }
        else
        {
          v75 = 1;
        }
      }
      else if ( v58 >= v155.m128_f32[2] )
      {
        v75 = 0;
        if ( !v115 )
        {
          LOBYTE(v75) = v151 <= v150;
          ++v75;
        }
      }
      else if ( v115 )
      {
        v75 = 2;
      }
      else
      {
        v75 = v150 <= v149;
      }
      v80 = v146;
      if ( v146 >= v6->m_xRes )
        goto LABEL_154;
      v70 = *(float *)&FLOAT_1_0;
      v56 = (__m128)v154;
      v57 = v155;
      v40 = v154.m128i_i32[0];
    }
    ((void (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v6->vfptr[10].__vecDelDtor)(v6, v80, v148 - v40);
    v87 = v86.m128_f32[0];
    ((void (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v6->vfptr[10].__vecDelDtor)(v6, v80, v81);
    v88 = v158.m128_f32[2];
    v89 = _mm_cvtsi32_si128(v81);
LABEL_86:
    v90 = (float)(v87 - v86.m128_f32[0])
        * COERCE_FLOAT((unsigned int)(2 * COERCE_SIGNED_INT(v88 - COERCE_FLOAT(_mm_cvtepi32_ps(v89)))) >> 1);
    goto LABEL_93;
  }
LABEL_154:
  v142 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v143 = v142[1];
  if ( v143 < v142[3] )
  {
    v144 = __rdtsc();
    *(_DWORD *)(v143 + 8) = v144;
    *(_QWORD *)v143 = "Et";
    v142[1] = v143 + 16;
  }
}

