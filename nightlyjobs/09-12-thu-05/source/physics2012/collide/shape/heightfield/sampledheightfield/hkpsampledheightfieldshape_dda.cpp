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
    hkpSampledHeightField_registerDdaRayCastFunction);
}

// File Line: 29
// RVA: 0xD31C20
void __fastcall hkpSampledHeightFieldShape::castRayDda(
        hkpSampledHeightFieldShape *this,
        hkpShapeRayCastInput *input,
        hkpCdBody *cdBody,
        hkpRayHitCollector *collector)
{
  hkOptionalComponent_hkpSampledHeightFieldShape_DdaCast.m_isUsed.m_bool = 1;
  hkpSampledHeightFieldShape::castRayDdaInternal(this, input, cdBody, 0, 0.0, collector);
}

// File Line: 37
// RVA: 0xD31C50
void __fastcall hkpSampledHeightFieldShape::castSphereDda(
        hkpSampledHeightFieldShape *this,
        hkpHeightFieldShape::hkpSphereCastInput *input,
        hkpCdBody *cdBody,
        hkpRayHitCollector *collector)
{
  hkVector4f v4; // xmm1
  __int128 v5; // xmm0
  __int128 v6; // xmm1
  hkVector4f v7; // xmm0
  hkVector4f v8; // xmm1
  hkpShapeRayCastInput v9; // [rsp+30h] [rbp-48h] BYREF

  hkOptionalComponent_hkpSampledHeightFieldShape_DdaCast.m_isUsed.m_bool = 1;
  v4.m_quad = (__m128)input->m_to;
  v9.m_from = input->m_from;
  v5 = *(_OWORD *)&input->m_filterInfo;
  v9.m_to = (hkVector4f)v4.m_quad;
  v6 = *(_OWORD *)&input->m_collidable;
  *(_OWORD *)&v9.m_filterInfo = v5;
  v7.m_quad = (__m128)input->m_from;
  *(_OWORD *)&v9.m_collidable = v6;
  v8.m_quad = (__m128)input->m_to;
  v9.m_from = (hkVector4f)v7.m_quad;
  v7.m_quad.m128_i32[0] = LODWORD(input->m_maxExtraPenetration);
  v9.m_to = (hkVector4f)v8.m_quad;
  hkpSampledHeightFieldShape::castRayDdaInternal(this, &v9, cdBody, (hkBool)1, v7.m_quad.m128_f32[0], collector);
}

// File Line: 77
// RVA: 0xD31CC0
void __fastcall hkpSampledHeightFieldShape::castRayDdaInternal(
        hkpSampledHeightFieldShape *this,
        hkpShapeRayCastInput *input,
        hkpCdBody *cdBody,
        hkBool reportPenetratingStartPosition,
        float maxExtraPenetration,
        hkpRayHitCollector *collector)
{
  __int64 v9; // r8
  _QWORD *Value; // r9
  _QWORD *v11; // rcx
  unsigned __int64 v12; // rax
  _QWORD *v13; // rcx
  hkVector4f v14; // xmm3
  __m128 v15; // xmm0
  __m128i v16; // xmm1
  char v17; // al
  float v18; // xmm7_4
  __m128 v19; // xmm15
  __m128 v20; // xmm10
  float v21; // xmm4_4
  float v22; // xmm9_4
  float v23; // xmm0_4
  __int64 v24; // r10
  float v25; // xmm8_4
  unsigned __int64 v26; // rcx
  int v27; // r14d
  __int64 v28; // r8
  float v29; // xmm3_4
  float v30; // xmm2_4
  float v31; // xmm0_4
  float v32; // xmm1_4
  int v33; // edx
  unsigned int m_xRes; // r13d
  int v35; // r8d
  int v36; // r11d
  unsigned int v37; // ebx
  float v38; // xmm0_4
  float v39; // xmm1_4
  __m128i v40; // xmm4
  __m128 v41; // xmm2
  __m128 v42; // xmm3
  int v43; // r9d
  __m128 v44; // xmm3
  __m128 v45; // xmm0
  int v46; // ecx
  int v47; // edx
  int m_zRes; // r9d
  float v49; // xmm0_4
  float v50; // xmm1_4
  __m128 v51; // xmm6
  __m128 v52; // xmm11
  float v53; // xmm14_4
  __m128 v54; // xmm5
  __m128i v55; // xmm4
  __m128 v56; // xmm2
  __m128 v57; // xmm3
  int v58; // r9d
  __m128 v59; // xmm2
  __m128 v60; // xmm0
  int v61; // ecx
  char v62; // bl
  int v63; // r9d
  int v64; // r8d
  float v65; // xmm13_4
  float v66; // xmm1_4
  float v67; // xmm12_4
  __int64 v68; // rax
  float v69; // xmm1_4
  int v70; // esi
  float v71; // xmm10_4
  float v72; // xmm7_4
  float v73; // xmm0_4
  unsigned int v74; // r15d
  unsigned int v75; // r14d
  __int64 v76; // r12
  unsigned int v77; // r13d
  __int64 v78; // r8
  float v79; // xmm9_4
  double v80; // xmm0_8
  float v81; // xmm6_4
  float v82; // xmm2_4
  __m128i v83; // xmm1
  float v84; // xmm6_4
  float v85; // xmm11_4
  float v86; // xmm6_4
  float v87; // xmm6_4
  float v88; // xmm11_4
  float v89; // xmm5_4
  float v90; // xmm3_4
  hkBaseObjectVtbl *v91; // rax
  unsigned int v92; // r12d
  __int64 v93; // r8
  double v94; // xmm0_8
  float v95; // xmm13_4
  double v96; // xmm0_8
  hkBaseObjectVtbl *v97; // rax
  float v98; // xmm14_4
  double v99; // xmm0_8
  int v100; // ecx
  int v101; // eax
  float v102; // xmm1_4
  float v103; // xmm6_4
  float v104; // xmm0_4
  bool v105; // zf
  bool v106; // sf
  bool v107; // of
  double v108; // xmm0_8
  float v109; // xmm6_4
  double v110; // xmm0_8
  float v111; // xmm13_4
  double v112; // xmm0_8
  double v113; // xmm0_8
  void (__fastcall **v114)(float *, hkpCdBody *, __m128 *); // rax
  __m128 v115; // xmm5
  __m128 v116; // xmm1
  __m128 v117; // xmm2
  __m128 v118; // xmm3
  unsigned int v119; // r9d
  float v120; // xmm9_4
  int v121; // r9d
  unsigned int v122; // esi
  unsigned int v123; // ebx
  hkBaseObjectVtbl *vfptr; // rax
  float v125; // xmm6_4
  float v126; // xmm7_4
  hkBaseObjectVtbl *v127; // rax
  double v128; // xmm0_8
  float v129; // xmm12_4
  double v130; // xmm0_8
  hkBaseObjectVtbl *v131; // rax
  float v132; // xmm9_4
  double v133; // xmm0_8
  float v134; // xmm9_4
  float v135; // xmm0_4
  float v136; // xmm3_4
  double v137; // xmm0_8
  float v138; // xmm9_4
  float v139; // xmm3_4
  double v140; // xmm0_8
  float v141; // xmm9_4
  double v142; // xmm0_8
  hkBaseObjectVtbl *v143; // rax
  float v144; // xmm12_4
  double v145; // xmm0_8
  float v146; // xmm2_4
  float v147; // xmm2_4
  float v148; // xmm0_4
  float v149; // xmm12_4
  float v150; // xmm15_4
  float v151; // xmm10_4
  __m128 v152; // xmm5
  void (__fastcall **v153)(float *, hkpCdBody *, __m128 *); // rax
  __m128 v154; // xmm1
  __m128 v155; // xmm2
  __m128 v156; // xmm3
  _QWORD *v157; // r9
  unsigned __int64 v158; // r8
  unsigned __int64 v159; // rax
  unsigned int v160; // [rsp+20h] [rbp-B0h]
  unsigned int v161; // [rsp+28h] [rbp-A8h]
  int v162; // [rsp+2Ch] [rbp-A4h]
  unsigned int v163; // [rsp+30h] [rbp-A0h]
  float v164; // [rsp+38h] [rbp-98h]
  float v165; // [rsp+3Ch] [rbp-94h]
  float v166; // [rsp+40h] [rbp-90h]
  int v167; // [rsp+48h] [rbp-88h]
  int v168; // [rsp+4Ch] [rbp-84h]
  __m128 v169; // [rsp+50h] [rbp-80h]
  __m128 v170; // [rsp+60h] [rbp-70h]
  __int64 v171; // [rsp+70h] [rbp-60h]
  float v172; // [rsp+78h] [rbp-58h]
  __m128 v173; // [rsp+80h] [rbp-50h]
  unsigned __int64 v174; // [rsp+90h] [rbp-40h]
  __m128 v175; // [rsp+A0h] [rbp-30h] BYREF
  int v176; // [rsp+B0h] [rbp-20h]
  unsigned int v177; // [rsp+B4h] [rbp-1Ch]
  int v178; // [rsp+C0h] [rbp-10h]
  int v179; // [rsp+E0h] [rbp+10h]
  char v180[8]; // [rsp+1E0h] [rbp+110h] BYREF
  unsigned int v181; // [rsp+1E8h] [rbp+118h] BYREF
  hkpCdBody *v182; // [rsp+1F0h] [rbp+120h]
  char v183; // [rsp+1F8h] [rbp+128h]
  float vars0; // [rsp+200h] [rbp+130h]
  float *retaddr; // [rsp+208h] [rbp+138h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v11 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v11 < Value[3] )
  {
    *v11 = "TtrcHeightField";
    v12 = __rdtsc();
    v13 = v11 + 2;
    *((_DWORD *)v13 - 2) = v12;
    Value[1] = v13;
  }
  v14.m_quad = (__m128)this->m_floatToIntScale;
  v15 = _mm_mul_ps(_mm_add_ps(this->m_floatToIntOffsetFloorCorrected.m_quad, input->m_from.m_quad), v14.m_quad);
  v19 = _mm_mul_ps(v14.m_quad, input->m_from.m_quad);
  v20 = _mm_mul_ps(input->m_to.m_quad, v14.m_quad);
  v16 = _mm_xor_si128(
          (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v15),
          _mm_cvttps_epi32(v15));
  v174 = _mm_packs_epi32(v16, v16).m128i_u64[0];
  v169 = v19;
  v161 = (__int16)v174;
  v170 = v20;
  v163 = SWORD2(v174);
  ((void (__fastcall *)(hkpSampledHeightFieldShape *, char *, __int64, _QWORD *))this->vfptr[10].__first_virtual_table_function__)(
    this,
    v180,
    v9,
    Value);
  v17 = v180[0];
  v18 = v19.m128_f32[0];
  v19.m128_i32[0] = _mm_shuffle_ps(v19, v19, 85).m128_u32[0];
  v20.m128_i32[0] = _mm_shuffle_ps(v20, v20, 85).m128_u32[0];
  v21 = v170.m128_f32[0];
  v169.m128_i32[3] = v19.m128_i32[0];
  v170.m128_i32[3] = v20.m128_i32[0];
  if ( v180[0] )
  {
    v22 = v169.m128_f32[0] - v19.m128_f32[2];
    v23 = v170.m128_f32[0] - v20.m128_f32[2];
  }
  else
  {
    v22 = v169.m128_f32[2] + v18;
    v23 = v170.m128_f32[2] + v170.m128_f32[0];
  }
  v24 = 3i64;
  v25 = 0.0;
  v26 = 0i64;
  v27 = 1;
  v28 = 3i64;
  v170.m128_f32[1] = v23;
  v169.m128_f32[1] = v22;
  do
  {
    v29 = v169.m128_f32[v26 / 4];
    v30 = v170.m128_f32[v26 / 4] - v29;
    v181 = LODWORD(v30);
    LODWORD(v31) = (unsigned int)(2 * LODWORD(v30)) >> 1;
    v170.m128_f32[v26 / 4] = v31;
    if ( v31 >= 0.000030517578 )
    {
      v32 = 1.0 / v30;
      *(float *)((char *)&v171 + v26) = 1.0 / v30;
      if ( v30 >= 0.0 )
      {
        *(float *)((char *)&v171 + v26) = v32;
        v33 = 1;
        *(int *)((char *)&v167 + v26) = 1;
      }
      else
      {
        v33 = -1;
        *(int *)((char *)&v167 + v26) = -1;
        *(_DWORD *)((char *)&v171 + v26) = LODWORD(v32) ^ _xmm[0];
      }
      if ( (float)(v29 * v30) > 0.0 )
        *(unsigned int *)((char *)&v161 + v26) += v33;
      *(float *)((char *)&v164 + v26) = (float)((float)*(int *)((char *)&v161 + v26) - v29) * v32;
    }
    else
    {
      *(_DWORD *)((char *)&v171 + v26) = 0;
      *(int *)((char *)&v167 + v26) = -1;
      *(float *)((char *)&v164 + v26) = 3.40282e38;
    }
    v26 += 4i64;
    --v28;
  }
  while ( v28 );
  if ( (float)(v172 + *(float *)&v171) == 0.0
    || (float)(*((float *)&v171 + 1) + *(float *)&v171) == 0.0
    || (float)(*((float *)&v171 + 1) + v172) == 0.0 )
  {
    v122 = v161;
    if ( v161 >= this->m_xRes - 1 )
      goto LABEL_154;
    v123 = v163;
    if ( v163 >= this->m_zRes - 1 )
      goto LABEL_154;
    vfptr = this->vfptr;
    v176 = 1065353216;
    v177 = -1;
    v179 = 0;
    v178 = -1;
    v125 = v19.m128_f32[2] - (float)(int)v163;
    v126 = v18 - (float)(int)v161;
    v175 = _mm_shuffle_ps(*(__m128 *)_xmm, _mm_unpackhi_ps(*(__m128 *)_xmm, v175), 196);
    ((void (__fastcall *)(hkpSampledHeightFieldShape *, unsigned int *))vfptr[10].__first_virtual_table_function__)(
      this,
      &v181);
    v127 = this->vfptr;
    if ( (_BYTE)v181 )
    {
      v128 = ((double (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v127[10].__vecDelDtor)(
               this,
               v122,
               v123);
      v129 = *(float *)&v128;
      v130 = ((double (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))this->vfptr[10].__vecDelDtor)(
               this,
               v122 + 1,
               v123 + 1);
      v131 = this->vfptr;
      v132 = *(float *)&v130;
      if ( v126 <= v125 )
      {
        v137 = ((double (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v131[10].__vecDelDtor)(
                 this,
                 v122,
                 v123 + 1);
        v27 = 0;
        v138 = v132 - *(float *)&v137;
        *(float *)&v137 = *(float *)&v137 - v129;
        v175.m128_i32[0] = LODWORD(v138) ^ _xmm[0];
        v175.m128_i32[2] = LODWORD(v137) ^ _xmm[0];
        v139 = (float)((float)(*(float *)&v137 * v125) + v129) + (float)(v138 * v126);
        goto LABEL_144;
      }
      v133 = ((double (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v131[10].__vecDelDtor)(
               this,
               v122 + 1,
               v123);
      v134 = v132 - *(float *)&v133;
      v175.m128_i32[2] = LODWORD(v134) ^ _xmm[0];
      v135 = *(float *)&v133 - v129;
      v136 = (float)(v134 * v125) + v129;
      v175.m128_i32[0] = LODWORD(v135) ^ _xmm[0];
    }
    else
    {
      v140 = ((double (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v127[10].__vecDelDtor)(
               this,
               v122 + 1,
               v123);
      v141 = *(float *)&v140;
      v142 = ((double (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))this->vfptr[10].__vecDelDtor)(
               this,
               v122,
               v123 + 1);
      v143 = this->vfptr;
      v144 = *(float *)&v142;
      if ( (float)(v126 + v125) > 1.0 )
      {
        v145 = ((double (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v143[10].__vecDelDtor)(
                 this,
                 v122 + 1,
                 v123 + 1);
        v146 = *(float *)&v145;
        *(float *)&v145 = *(float *)&v145 - v141;
        v147 = v146 - v144;
        v175.m128_i32[0] = LODWORD(v147) ^ _xmm[0];
        v175.m128_i32[2] = LODWORD(v145) ^ _xmm[0];
        v139 = (float)((float)(v126 - 1.0) * v147) + (float)((float)(*(float *)&v145 * v125) + v141);
        goto LABEL_144;
      }
      v148 = ((float (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v143[10].__vecDelDtor)(
               this,
               v122,
               v123);
      v27 = 0;
      v149 = v144 - v148;
      v175.m128_i32[2] = LODWORD(v149) ^ _xmm[0];
      v136 = (float)(v149 * v125) + v148;
      v135 = v141 - v148;
      v175.m128_i32[0] = LODWORD(v135) ^ _xmm[0];
    }
    v139 = v136 + (float)(v135 * v126);
LABEL_144:
    v150 = v19.m128_f32[0] - v139;
    v151 = v20.m128_f32[0] - v139;
    if ( v151 > v150 )
      goto LABEL_154;
    if ( v183 )
    {
      if ( v150 < 0.0 )
      {
        if ( v151 > (float)(v150 - vars0) )
          goto LABEL_154;
        goto LABEL_152;
      }
    }
    else if ( v150 < 0.0 )
    {
      goto LABEL_154;
    }
    if ( v151 >= 0.0 )
      goto LABEL_154;
    v25 = v150 / (float)(v150 - v151);
LABEL_152:
    if ( v25 < retaddr[2] )
    {
      v176 = LODWORD(v25);
      v152 = _mm_mul_ps(v175, this->m_floatToIntScale.m_quad);
      v177 = v27 + 2 * (v122 + (v123 << 15));
      v153 = *(void (__fastcall ***)(float *, hkpCdBody *, __m128 *))retaddr;
      v154 = _mm_mul_ps(v152, v152);
      v155 = _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v154, v154, 85), _mm_shuffle_ps(v154, v154, 0)),
               _mm_shuffle_ps(v154, v154, 170));
      v156 = _mm_rsqrt_ps(v155);
      v175 = _mm_mul_ps(
               v152,
               _mm_andnot_ps(
                 _mm_cmple_ps(v155, (__m128)0i64),
                 _mm_mul_ps(
                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v156, v155), v156)),
                   _mm_mul_ps(*(__m128 *)_xmm, v156))));
      (*v153)(retaddr, cdBody, &v175);
    }
    goto LABEL_154;
  }
  m_xRes = this->m_xRes;
  v35 = v161;
  v36 = v169.m128_i32[0];
  v173 = v169;
  v37 = v161;
  v38 = (float)(int)(m_xRes - 1);
  if ( v167 <= 0 )
  {
    if ( v21 > v38 || v18 < 0.0 )
      goto LABEL_154;
    if ( (int)v161 > (int)(m_xRes - 2) )
    {
      v35 = m_xRes - 2;
      v161 = m_xRes - 2;
      v39 = (float)(v18 - v38) * *(float *)&v171;
      goto LABEL_28;
    }
LABEL_32:
    v47 = v163;
    goto LABEL_33;
  }
  if ( v21 < 0.0 || v18 > v38 )
    goto LABEL_154;
  if ( (int)v161 > 0 )
    goto LABEL_32;
  v35 = 1;
  v161 = 1;
  LODWORD(v39) = COERCE_UNSIGNED_INT(*(float *)&v171 * v18) ^ _xmm[0];
LABEL_28:
  v164 = *(float *)&v171 + v39;
  v40 = (__m128i)COERCE_UNSIGNED_INT(v170.m128_f32[2] * v39);
  v173 = _mm_add_ps(
           _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(v39), (__m128)LODWORD(v39), 0), _mm_sub_ps(v170, v169)),
           v169);
  v181 = _mm_shuffle_ps(v173, v173, 170).m128_u32[0];
  v41 = _mm_cmplt_ps(*(__m128 *)two23, (__m128)_mm_srli_epi32(_mm_slli_epi32(v40, 1u), 1u));
  v42 = _mm_sub_ps(
          _mm_add_ps(_mm_add_ps(_mm_sub_ps((__m128)v40, *(__m128 *)two23), *(__m128 *)two23), *(__m128 *)two23),
          *(__m128 *)two23);
  v43 = v163
      - 2
      + v169.m128_i32[0]
      * (int)COERCE_FLOAT(_mm_andnot_ps(v41, _mm_add_ps(_mm_cvtepi32_ps((__m128i)_mm_cmplt_ps((__m128)v40, v42)), v42)).m128_u32[0] | v41.m128_i32[0] & v40.m128i_i32[0]);
  v44 = _mm_sub_ps(
          _mm_add_ps(_mm_add_ps(_mm_sub_ps((__m128)v181, *(__m128 *)two23), *(__m128 *)two23), *(__m128 *)two23),
          *(__m128 *)two23);
  v45 = _mm_cmplt_ps(*(__m128 *)two23, (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)v181, 1u), 1u));
  v46 = (int)COERCE_FLOAT(_mm_andnot_ps(v45, _mm_add_ps(_mm_cvtepi32_ps((__m128i)_mm_cmplt_ps((__m128)v181, v44)), v44)).m128_u32[0] | v45.m128_i32[0] & v181);
  if ( v46 >= v43 )
    v43 = v46 + 1;
  v47 = v43 + (v169.m128_i32[0] >> 1);
  v163 = v47;
  if ( v172 != 0.0 )
    v166 = (float)((float)v47 - v19.m128_f32[2]) * v172;
LABEL_33:
  m_zRes = this->m_zRes;
  v49 = (float)(m_zRes - 1);
  if ( v169.m128_i32[0] <= 0 )
  {
    if ( v20.m128_f32[2] > v49 || v19.m128_f32[2] < 0.0 )
      goto LABEL_154;
    if ( v47 > m_zRes - 2 )
    {
      v47 = m_zRes - 2;
      v163 = m_zRes - 2;
      v50 = (float)(v19.m128_f32[2] - v49) * v172;
      goto LABEL_42;
    }
LABEL_46:
    v52 = v170;
    v51 = v169;
    v53 = v170.m128_f32[0];
    goto LABEL_47;
  }
  if ( v20.m128_f32[2] < 0.0 || v19.m128_f32[2] > v49 )
    goto LABEL_154;
  if ( v47 > 0 )
    goto LABEL_46;
  v47 = 1;
  v163 = 1;
  LODWORD(v50) = COERCE_UNSIGNED_INT(v172 * v19.m128_f32[2]) ^ _xmm[0];
LABEL_42:
  v51 = v169;
  v52 = v170;
  v53 = v170.m128_f32[0];
  v166 = v172 + v50;
  v54 = _mm_add_ps(
          _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(v50), (__m128)LODWORD(v50), 0), _mm_sub_ps(v170, v169)),
          v169);
  v55 = (__m128i)COERCE_UNSIGNED_INT(v170.m128_f32[0] * v50);
  v181 = v54.m128_i32[0];
  v173 = v54;
  v56 = _mm_cmplt_ps(*(__m128 *)two23, (__m128)_mm_srli_epi32(_mm_slli_epi32(v55, 1u), 1u));
  v57 = _mm_sub_ps(
          _mm_add_ps(_mm_add_ps(_mm_sub_ps((__m128)v55, *(__m128 *)two23), *(__m128 *)two23), *(__m128 *)two23),
          *(__m128 *)two23);
  v58 = v167
      * (int)COERCE_FLOAT(_mm_andnot_ps(v56, _mm_add_ps(_mm_cvtepi32_ps((__m128i)_mm_cmplt_ps((__m128)v55, v57)), v57)).m128_u32[0] | v56.m128_i32[0] & v55.m128i_i32[0])
      + v37
      - 2;
  v59 = _mm_sub_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_sub_ps((__m128)v54.m128_u32[0], *(__m128 *)two23), *(__m128 *)two23),
            *(__m128 *)two23),
          *(__m128 *)two23);
  v60 = _mm_cmplt_ps(*(__m128 *)two23, (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)v54.m128_u32[0], 1u), 1u));
  v61 = (int)COERCE_FLOAT(_mm_andnot_ps(
                            v60,
                            _mm_add_ps(_mm_cvtepi32_ps((__m128i)_mm_cmplt_ps((__m128)v54.m128_u32[0], v59)), v59)).m128_u32[0] | v60.m128_i32[0] & v54.m128_i32[0]);
  if ( v61 >= v58 )
    v58 = v61 + 1;
  v35 = v58 + (v167 >> 1);
  v161 = v35;
  if ( *(float *)&v171 != 0.0 )
    v164 = (float)((float)v35 - v18) * *(float *)&v171;
LABEL_47:
  if ( v35 >= m_xRes || v35 - v167 >= m_xRes )
    goto LABEL_154;
  v62 = (v17 != 0) ^ ((v167 ^ v169.m128_i32[0]) >= 0);
  if ( *((float *)&v171 + 1) == 0.0 )
    v62 = 0;
  v63 = 2;
  v181 = 2;
  if ( v17 )
    v64 = v35 - v47;
  else
    v64 = v47 + v35;
  v65 = *(float *)&FLOAT_1_0;
  v162 = v64;
  v66 = v173.m128_f32[1] - (float)v64;
  if ( v62 )
  {
    if ( COERCE_FLOAT((unsigned int)(2 * LODWORD(v66)) >> 1) > 1.0 )
    {
      v64 -= v168;
LABEL_60:
      v162 = v64;
      goto LABEL_61;
    }
    v63 = 0;
    v181 = 0;
  }
  else if ( (float)((float)v168 * v66) > 0.0 )
  {
    v63 = 0;
    v181 = 0;
    v64 += v168;
    goto LABEL_60;
  }
LABEL_61:
  v67 = FLOAT_3_40282e38;
  if ( *((float *)&v171 + 1) == 0.0 )
    v165 = 3.40282e38;
  else
    v165 = (float)((float)((float)v64 - v22) * *((float *)&v171 + 1)) * (float)v168;
  v68 = 0i64;
  do
  {
    v69 = *(float *)((char *)&v171 + v68);
    if ( v69 == 0.0 )
      *(_DWORD *)((char *)&v171 + v68) = -8388626;
    else
      *(float *)((char *)&v171 + v68) = *(float *)((char *)&v164 + v68) - v69;
    v68 += 4i64;
    --v24;
  }
  while ( v24 );
  if ( v62 )
  {
    if ( v63 )
    {
      v70 = 2;
      if ( *(float *)&v171 > v172 )
        v70 = 0;
    }
    else
    {
      v70 = 1;
    }
  }
  else if ( v53 >= v170.m128_f32[2] )
  {
    v70 = 0;
    if ( !v63 )
    {
      LOBYTE(v70) = *((float *)&v171 + 1) <= v172;
      ++v70;
    }
  }
  else if ( v63 )
  {
    v70 = 2;
  }
  else
  {
    v70 = 0;
    LOBYTE(v70) = *(float *)&v171 <= *((float *)&v171 + 1);
  }
  v71 = FLOAT_N1_0;
  v72 = 0.0;
  v73 = *(&v164 + v70);
  *(&v161 + v70) -= *(&v167 + v70);
  v74 = v161;
  *(&v164 + v70) = v73 - *((float *)&v171 + v70);
  if ( v74 < m_xRes )
  {
    while ( 1 )
    {
      v75 = v163;
      if ( v163 >= this->m_zRes || v71 > retaddr[2] )
        goto LABEL_154;
      v76 = v70;
      v77 = v74 - v167;
      v171 = v70;
      v78 = v163;
      v79 = *(&v164 + v70);
      v173 = _mm_add_ps(
               _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(v79), (__m128)LODWORD(v79), 0), _mm_sub_ps(v52, v51)),
               v51);
      if ( !v70 )
        break;
      if ( v70 == 2 )
      {
        v80 = ((double (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))this->vfptr[10].__vecDelDtor)(
                this,
                v77,
                v163);
        v81 = *(float *)&v80;
        ((void (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))this->vfptr[10].__vecDelDtor)(
          this,
          v74,
          v75);
        v82 = v173.m128_f32[0];
        v83 = _mm_cvtsi32_si128(v74);
        goto LABEL_86;
      }
      v160 = v163;
      v169.m128_f32[2] = v173.m128_f32[0] - (float)(int)v74;
      LODWORD(v85) = (unsigned int)(2 * v169.m128_i32[2]) >> 1;
      if ( v62 )
        v160 = v163 - v36;
      else
        v78 = v163 - v36;
      v80 = ((double (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, __int64))this->vfptr[10].__vecDelDtor)(
              this,
              v77,
              v78);
      v86 = *(float *)&v80;
      *(float *)&v80 = ((float (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))this->vfptr[10].__vecDelDtor)(
                         this,
                         v74,
                         v160);
      v84 = (float)(v86 - *(float *)&v80) * v85;
LABEL_93:
      v87 = v84 + *(float *)&v80;
      if ( v183 )
      {
        if ( v173.m128_f32[3] >= v87
          || (float)(v173.m128_f32[3] - v87) >= (float)((float)(v72 - v67) - (float)((float)(v79 - v71) * vars0)) )
        {
          goto $setAndWalk;
        }
        if ( (float)(v72 - v67) <= 0.0 )
        {
          LODWORD(v174) = 0;
          v169.m128_f32[2] = v71;
          v88 = fmaxf(0.0, v71);
          goto $reportHit;
        }
      }
      else if ( v173.m128_f32[3] >= v87 || v72 < v67 )
      {
$setAndWalk:
        v67 = v87;
        v72 = v173.m128_f32[3];
        v71 = v79;
        goto $walk;
      }
      v89 = v173.m128_f32[3] - v87;
      if ( v71 < 0.0 )
      {
        v90 = v19.m128_f32[0]
            - (float)((float)((float)(v65 - (float)(v79 / (float)(v79 - v71))) * v87)
                    + (float)((float)(v79 / (float)(v79 - v71)) * v67));
        if ( v90 < 0.0 )
        {
          if ( !v183 )
            goto $setAndWalk;
          v90 = 0.0;
        }
        v88 = (float)(v90 / (float)(v90 - v89)) * v79;
      }
      else
      {
        v88 = (float)((float)((float)(v72 - v67) / (float)((float)(v72 - v67) - v89)) * (float)(v79 - v71)) + v71;
      }
$reportHit:
      v67 = v87;
      v72 = v173.m128_f32[3];
      v71 = v79;
      if ( v88 > retaddr[2] )
        goto LABEL_154;
      v91 = this->vfptr;
      v176 = 1065353216;
      v92 = v75 - v169.m128_i32[0];
      v177 = -1;
      v179 = 0;
      v178 = -1;
      v175.m128_i32[3] = 0;
      v175.m128_i32[1] = 1065353216;
      v93 = v75 - v169.m128_i32[0];
      if ( v62 )
      {
        v94 = ((double (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, __int64))v91[10].__vecDelDtor)(
                this,
                v74,
                v93);
        v95 = *(float *)&v94;
        v96 = ((double (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))this->vfptr[10].__vecDelDtor)(
                this,
                v77,
                v75);
        v97 = this->vfptr;
        v98 = *(float *)&v96;
        if ( v70 != 1 )
        {
          v104 = ((float (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v97[10].__vecDelDtor)(
                   this,
                   v74,
                   v75);
          v107 = __OFSUB__(v75, v92);
          v105 = v75 == v92;
          v106 = (int)(v75 - v92) < 0;
          v100 = 0;
          v101 = 0;
          v102 = v98 - v104;
          v103 = v95 - v104;
          goto LABEL_117;
        }
        v99 = ((double (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v97[10].__vecDelDtor)(
                this,
                v77,
                v92);
        v100 = 0;
        v101 = 0;
        v102 = *(float *)&v99 - v95;
        v103 = *(float *)&v99 - v98;
      }
      else
      {
        v108 = ((double (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, __int64))v91[10].__vecDelDtor)(
                 this,
                 v77,
                 v93);
        v109 = *(float *)&v108;
        v110 = ((double (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))this->vfptr[10].__vecDelDtor)(
                 this,
                 v74,
                 v75);
        v111 = *(float *)&v110;
        if ( v70 && (v70 != 1 || v53 >= v170.m128_f32[2]) )
        {
          v112 = ((double (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))this->vfptr[10].__vecDelDtor)(
                   this,
                   v77,
                   v75);
          v107 = __OFSUB__(v75, v92);
          v105 = v75 == v92;
          v106 = (int)(v75 - v92) < 0;
          v100 = 0;
          v101 = 0;
          v103 = v109 - *(float *)&v112;
          v102 = *(float *)&v112 - v111;
          goto LABEL_117;
        }
        v113 = ((double (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))this->vfptr[10].__vecDelDtor)(
                 this,
                 v74,
                 v92);
        v101 = 0;
        v100 = 0;
        v102 = v109 - *(float *)&v113;
        v103 = *(float *)&v113 - v111;
      }
      v107 = __OFSUB__(v92, v75);
      v105 = v92 == v75;
      v106 = (int)(v92 - v75) < 0;
LABEL_117:
      LOBYTE(v100) = !(v106 ^ v107 | v105);
      v176 = LODWORD(v88);
      LOBYTE(v101) = v180[0] != 0;
      v175.m128_f32[0] = v102 * (float)v167;
      v175.m128_f32[2] = v103 * (float)v169.m128_i32[0];
      v177 = (v101 ^ v100) - 65538 + 2 * (v74 + ((v75 - (v169.m128_i32[0] >> 1)) << 15) - (v167 >> 1));
      v114 = *(void (__fastcall ***)(float *, hkpCdBody *, __m128 *))retaddr;
      v115 = _mm_mul_ps(v175, this->m_floatToIntScale.m_quad);
      v116 = _mm_mul_ps(v115, v115);
      v117 = _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v116, v116, 85), _mm_shuffle_ps(v116, v116, 0)),
               _mm_shuffle_ps(v116, v116, 170));
      v118 = _mm_rsqrt_ps(v117);
      v175 = _mm_mul_ps(
               v115,
               _mm_andnot_ps(
                 _mm_cmple_ps(v117, (__m128)0i64),
                 _mm_mul_ps(
                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v118, v117), v118)),
                   _mm_mul_ps(*(__m128 *)_xmm, v118))));
      (*v114)(retaddr, v182, &v175);
      v76 = v171;
      if ( v183 )
        v183 = 0;
$walk:
      v119 = v181;
      v120 = v79 + *((float *)&v171 + v76);
      *(&v161 + v76) += *(&v167 + v76);
      v121 = v119 ^ 2;
      v53 = v170.m128_f32[0];
      *(&v164 + v76) = v120;
      v181 = v121;
      if ( v62 )
      {
        if ( v121 )
        {
          v70 = 2;
          if ( v166 > v164 )
            v70 = 0;
        }
        else
        {
          v70 = 1;
        }
      }
      else if ( v53 >= v170.m128_f32[2] )
      {
        v70 = 0;
        if ( !v121 )
        {
          LOBYTE(v70) = v166 <= v165;
          ++v70;
        }
      }
      else if ( v121 )
      {
        v70 = 2;
      }
      else
      {
        v70 = v165 <= v164;
      }
      v74 = v161;
      if ( v161 >= this->m_xRes )
        goto LABEL_154;
      v65 = *(float *)&FLOAT_1_0;
      v51 = v169;
      v52 = v170;
      v36 = v169.m128_i32[0];
    }
    v80 = ((double (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))this->vfptr[10].__vecDelDtor)(
            this,
            v74,
            v163 - v36);
    v81 = *(float *)&v80;
    ((void (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))this->vfptr[10].__vecDelDtor)(this, v74, v75);
    v82 = v173.m128_f32[2];
    v83 = _mm_cvtsi32_si128(v75);
LABEL_86:
    v84 = (float)(v81 - *(float *)&v80)
        * COERCE_FLOAT((unsigned int)(2 * COERCE_INT(v82 - _mm_cvtepi32_ps(v83).m128_f32[0])) >> 1);
    goto LABEL_93;
  }
LABEL_154:
  v157 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v158 = v157[1];
  if ( v158 < v157[3] )
  {
    v159 = __rdtsc();
    *(_DWORD *)(v158 + 8) = v159;
    *(_QWORD *)v158 = "Et";
    v157[1] = v158 + 16;
  }
}

