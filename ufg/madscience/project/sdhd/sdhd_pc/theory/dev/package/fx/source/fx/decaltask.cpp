// File Line: 9
// RVA: 0x146BC40
__int64 Render::_dynamic_initializer_for__gTaskFunctionDecl_DecalClipTask__()
{
  UFG::qTaskFunctionDecl::qTaskFunctionDecl(
    &Render::gTaskFunctionDecl_DecalClipTask,
    &Render::gTaskFunctionDeclData_DecalClipTask);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gTaskFunctionDecl_DecalClipTask__);
}

// File Line: 12
// RVA: 0x1E7CD0
void __fastcall Render::DecalClipTask(
        int worker_id,
        UFG::qMemoryStreamer *memory_streamer,
        unsigned int *param0,
        char *param1)
{
  __m128 v4; // xmm2
  int v5; // r12d
  __int64 v6; // r13
  float v7; // xmm1_4
  unsigned __int16 *v8; // r15
  char v9; // r14
  int v10; // eax
  float v11; // xmm10_4
  int v12; // xmm0_4
  int width; // xmm12_4
  int v16; // xmm13_4
  int v17; // xmm0_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm4_4
  __m128 v21; // xmm2
  float v22; // xmm4_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm3_4
  __m128 v26; // xmm2
  float v27; // xmm0_4
  float v28; // xmm3_4
  float v29; // xmm0_4
  float v30; // xmm3_4
  __m128 v31; // xmm4
  float v32; // xmm5_4
  __m128 v33; // xmm2
  float v34; // xmm1_4
  float v35; // xmm3_4
  __m128 v36; // xmm4
  float v37; // xmm5_4
  __m128 v38; // xmm2
  float v39; // xmm1_4
  float v40; // xmm3_4
  __m128 v41; // xmm4
  float v42; // xmm5_4
  __m128 v43; // xmm2
  float v44; // xmm1_4
  float v45; // xmm0_4
  float v46; // xmm5_4
  float v47; // xmm1_4
  UFG::qMatrix44 *v48; // rax
  __int128 v49; // xmm0
  __int128 v50; // xmm1
  __m128 v51; // xmm11
  __int128 v52; // xmm0
  unsigned int v53; // esi
  float v54; // xmm7_4
  float v55; // xmm8_4
  float v56; // xmm14_4
  float v57; // xmm15_4
  unsigned __int16 *v58; // rcx
  __int16 v59; // r11
  __m128 *v60; // r10
  __m128 *v61; // r9
  unsigned __int64 v62; // rcx
  __m128 v63; // xmm5
  __m128 v64; // xmm4
  __m128 v65; // xmm6
  __m128 v66; // xmm2
  __m128 v67; // xmm1
  __m128 v68; // xmm3
  __m128 v69; // xmm2
  __m128 v70; // xmm0
  __m128 v71; // xmm1
  __m128 v72; // xmm1
  unsigned int v73; // eax
  unsigned int v74; // eax
  unsigned int v75; // eax
  unsigned int v76; // edi
  unsigned int v77; // r10d
  float *p_z; // r11
  float v79; // xmm11_4
  int v80; // esi
  int v81; // r14d
  int v82; // r15d
  int v83; // r12d
  int v84; // r13d
  int v85; // xmm0_4
  float v86; // xmm13_4
  float v87; // xmm0_4
  float v88; // xmm10_4
  float v89; // xmm6_4
  float v90; // xmm4_4
  float v91; // xmm2_4
  float v92; // xmm7_4
  float v93; // xmm0_4
  float v94; // xmm4_4
  float v95; // xmm6_4
  float v96; // xmm5_4
  float v97; // xmm7_4
  float v98; // xmm8_4
  float v99; // xmm3_4
  float v100; // xmm1_4
  float v101; // xmm2_4
  float v102; // xmm5_4
  __int64 v103; // r8
  unsigned int v104; // edx
  int v105; // r9d
  __int16 v106; // r9
  unsigned int v107; // edx
  unsigned int v108; // edx
  int v109; // r9d
  __int16 v110; // r9
  unsigned int v111; // edx
  char v112; // al
  __int64 v113; // rax
  unsigned int v114; // [rsp+38h] [rbp-C8h]
  UFG::qVector3 scale; // [rsp+40h] [rbp-C0h] BYREF
  int v116; // [rsp+50h] [rbp-B0h]
  int v117; // [rsp+54h] [rbp-ACh]
  float v118; // [rsp+58h] [rbp-A8h]
  UFG::qVector3 v119; // [rsp+60h] [rbp-A0h] BYREF
  float v120; // [rsp+70h] [rbp-90h]
  float v121; // [rsp+74h] [rbp-8Ch]
  float v122; // [rsp+78h] [rbp-88h]
  float v123; // [rsp+7Ch] [rbp-84h]
  __int128 v124; // [rsp+80h] [rbp-80h] BYREF
  __int128 v125; // [rsp+90h] [rbp-70h] BYREF
  __int128 v126; // [rsp+A0h] [rbp-60h] BYREF
  __m128 v127; // [rsp+B0h] [rbp-50h]
  UFG::qMatrix44 m; // [rsp+C0h] [rbp-40h] BYREF
  __m128 v129; // [rsp+100h] [rbp+0h]
  __m128 v130; // [rsp+110h] [rbp+10h]
  __m128 v131; // [rsp+120h] [rbp+20h]
  __int64 v132; // [rsp+130h] [rbp+30h]
  __m128 v133; // [rsp+140h] [rbp+40h]
  __int64 v134; // [rsp+150h] [rbp+50h]
  UFG::qMatrix44 v135; // [rsp+160h] [rbp+60h] BYREF
  UFG::qMatrix44 result; // [rsp+1A0h] [rbp+A0h] BYREF
  UFG::qMatrix44 dest; // [rsp+1E0h] [rbp+E0h] BYREF
  UFG::qMatrix44 d; // [rsp+220h] [rbp+120h] BYREF
  UFG::qVector4 inpts; // [rsp+260h] [rbp+160h] BYREF
  UFG::qVector4 outpts; // [rsp+A60h] [rbp+960h] BYREF
  UFG::qVector4 v141; // [rsp+1260h] [rbp+1160h] BYREF
  char v142; // [rsp+1B50h] [rbp+1A50h]
  unsigned int v143; // [rsp+1B58h] [rbp+1A58h]

  v4 = (__m128)param0[5];
  v5 = param0[40];
  v6 = *((_QWORD *)param0 + 1);
  v7 = *((float *)param0 + 6) * *((float *)param0 + 6);
  v8 = *(unsigned __int16 **)param0;
  v9 = 0;
  v10 = 3 * param0[39];
  v11 = *(float *)&FLOAT_1_0;
  LODWORD(v121) = param0[43];
  v12 = param0[36];
  v117 = v5;
  width = *((int *)param0 + 42);
  v16 = _xmm[0];
  v123 = *(float *)&v12;
  v114 = v10;
  v134 = v6;
  v142 = 0;
  v17 = param0[37];
  v116 = width;
  v118 = *(float *)&v17;
  v122 = *((float *)param0 + 38);
  v120 = *((float *)param0 + 41);
  v18 = *((float *)param0 + 8) * *((float *)param0 + 8);
  v4.m128_f32[0] = (float)((float)(v4.m128_f32[0] * v4.m128_f32[0])
                         + (float)(*((float *)param0 + 4) * *((float *)param0 + 4)))
                 + v7;
  v19 = *((float *)param0 + 10) * *((float *)param0 + 10);
  v20 = _mm_sqrt_ps(v4).m128_f32[0];
  v21 = (__m128)param0[9];
  scale.x = v20;
  v22 = v20 - 1.0;
  v21.m128_f32[0] = (float)(v21.m128_f32[0] * v21.m128_f32[0]) + v18;
  v23 = *((float *)param0 + 12) * *((float *)param0 + 12);
  v21.m128_f32[0] = v21.m128_f32[0] + v19;
  v24 = *((float *)param0 + 14) * *((float *)param0 + 14);
  LODWORD(v25) = _mm_sqrt_ps(v21).m128_u32[0];
  v26 = (__m128)param0[13];
  scale.y = v25;
  v26.m128_f32[0] = (float)((float)(v26.m128_f32[0] * v26.m128_f32[0]) + v23) + v24;
  LODWORD(v27) = _mm_sqrt_ps(v26).m128_u32[0];
  scale.z = v27;
  if ( v22 < 0.0 )
    LODWORD(v22) ^= _xmm[0];
  if ( v22 >= 0.001 )
    goto LABEL_10;
  v28 = v25 - 1.0;
  if ( v28 < 0.0 )
    LODWORD(v28) ^= _xmm[0];
  if ( v28 >= 0.001 )
    goto LABEL_10;
  v29 = v27 - 1.0;
  if ( v29 < 0.0 )
    LODWORD(v29) ^= _xmm[0];
  if ( v29 >= 0.001 )
  {
LABEL_10:
    v9 = 1;
    v142 = 1;
  }
  UFG::qScaleMatrix(&dest, &scale);
  v119.x = 1.0 / scale.x;
  v119.y = 1.0 / scale.y;
  v119.z = 1.0 / scale.z;
  UFG::qScaleMatrix(&v135, &v119);
  v30 = *((float *)param0 + 4);
  v31 = (__m128)param0[5];
  v32 = *((float *)param0 + 6);
  v130 = (__m128)dest.v0;
  v33 = v31;
  v129 = (__m128)dest.v1;
  v133 = (__m128)dest.v2;
  v131 = (__m128)dest.v3;
  v33.m128_f32[0] = (float)((float)(v31.m128_f32[0] * v31.m128_f32[0]) + (float)(v30 * v30)) + (float)(v32 * v32);
  if ( v33.m128_f32[0] == 0.0 )
    v34 = 0.0;
  else
    v34 = 1.0 / _mm_sqrt_ps(v33).m128_f32[0];
  m.v0.x = v30 * v34;
  v35 = *((float *)param0 + 8);
  m.v0.y = v31.m128_f32[0] * v34;
  v36 = (__m128)param0[9];
  m.v0.z = v32 * v34;
  v37 = *((float *)param0 + 10);
  m.v0.w = v34 * 0.0;
  v38 = v36;
  v38.m128_f32[0] = (float)((float)(v36.m128_f32[0] * v36.m128_f32[0]) + (float)(v35 * v35)) + (float)(v37 * v37);
  if ( v38.m128_f32[0] == 0.0 )
    v39 = 0.0;
  else
    v39 = 1.0 / _mm_sqrt_ps(v38).m128_f32[0];
  m.v1.x = v35 * v39;
  v40 = *((float *)param0 + 12);
  m.v1.y = v36.m128_f32[0] * v39;
  v41 = (__m128)param0[13];
  m.v1.z = v37 * v39;
  v42 = *((float *)param0 + 14);
  m.v1.w = v39 * 0.0;
  v43 = v41;
  v43.m128_f32[0] = (float)((float)(v41.m128_f32[0] * v41.m128_f32[0]) + (float)(v40 * v40)) + (float)(v42 * v42);
  if ( v43.m128_f32[0] == 0.0 )
    v44 = 0.0;
  else
    v44 = 1.0 / _mm_sqrt_ps(v43).m128_f32[0];
  LODWORD(m.v3.x) = param0[16];
  v45 = *((float *)param0 + 18);
  v46 = v42 * v44;
  m.v2.x = v40 * v44;
  m.v2.y = v41.m128_f32[0] * v44;
  m.v3.z = v45;
  m.v2.w = v44 * 0.0;
  v47 = *((float *)param0 + 17);
  m.v2.z = v46;
  m.v3.y = v47;
  LODWORD(m.v3.w) = param0[19];
  UFG::qInverse(&d, &m);
  v48 = UFG::qMatrix44::operator*((UFG::qMatrix44 *)(param0 + 20), &result, &d);
  v49 = (__int128)v48->v0;
  v50 = (__int128)v48->v1;
  v51 = (__m128)v48->v3;
  v127 = v51;
  v124 = v49;
  v52 = (__int128)v48->v2;
  v125 = v50;
  *(_QWORD *)(param1 + 3116) = 0i64;
  *((_DWORD *)param1 + 781) = 2139095039;
  *((_DWORD *)param1 + 782) = 2139095039;
  *((_DWORD *)param1 + 783) = 2139095039;
  v53 = 0;
  v143 = 0;
  v126 = v52;
  *((_DWORD *)param1 + 784) = -8388609;
  *((_DWORD *)param1 + 785) = -8388609;
  *((_DWORD *)param1 + 786) = -8388609;
  if ( !v114 )
  {
    param1[3148] = 1;
    return;
  }
  v54 = *(float *)&v124;
  v55 = FLOAT_255_0;
  v56 = *((float *)&v124 + 2);
  v57 = *((float *)&v124 + 1);
  while ( 1 )
  {
    v58 = v8;
    v8 += 3;
    v59 = v6 + v5 * *v58;
    v60 = (__m128 *)(v6 + v5 * (unsigned int)v58[1]);
    v61 = (__m128 *)(v6 + v5 * (unsigned int)v58[2]);
    v62 = (v6 + v5 * (unsigned int)*v58) & 0xFFFFFFFFFFFFFFF0ui64;
    *(_QWORD *)&v119.x = v8;
    v63 = *(__m128 *)((v59 & 0xF) + v62);
    v64 = *v60;
    v65 = *v61;
    if ( v9 )
    {
      v63 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v63, v63, 0), v130), (__m128)0i64),
                  _mm_mul_ps(_mm_shuffle_ps(v63, v63, 85), v129)),
                _mm_mul_ps(_mm_shuffle_ps(v63, v63, 170), v133)),
              _mm_mul_ps(_mm_shuffle_ps(v63, v63, 255), v131));
      v64 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v64, v64, 0), v130), (__m128)0i64),
                  _mm_mul_ps(_mm_shuffle_ps(v64, v64, 85), v129)),
                _mm_mul_ps(_mm_shuffle_ps(v64, v64, 170), v133)),
              _mm_mul_ps(_mm_shuffle_ps(v64, v64, 255), v131));
      v65 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v65, v65, 0), v130), (__m128)0i64),
                  _mm_mul_ps(_mm_shuffle_ps(v65, v65, 85), v129)),
                _mm_mul_ps(_mm_shuffle_ps(v65, v65, 170), v133)),
              _mm_mul_ps(_mm_shuffle_ps(v65, v65, 255), v131));
    }
    v66 = _mm_sub_ps(v65, v64);
    v67 = _mm_sub_ps(v64, v63);
    v68 = _mm_sub_ps(
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v67, v67, 201), _mm_shuffle_ps(v66, v66, 210)), (__m128)0i64),
            _mm_mul_ps(_mm_shuffle_ps(v67, v67, 210), _mm_shuffle_ps(v66, v66, 201)));
    v69 = _mm_shuffle_ps(v68, v68, 0);
    v70 = _mm_shuffle_ps(v68, v68, 85);
    v71 = _mm_shuffle_ps(v68, v68, 170);
    v72 = _mm_add_ps(
            _mm_mul_ps(
              _mm_rsqrt_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_add_ps(_mm_mul_ps(v69, v69), _xmm), _mm_mul_ps(v70, v70)),
                  _mm_mul_ps(v71, v71))),
              v68),
            (__m128)0i64);
    if ( (float)((float)((float)(v72.m128_f32[0] * *(float *)&v126)
                       + (float)(_mm_shuffle_ps(v72, v72, 85).m128_f32[0] * *((float *)&v126 + 1)))
               + (float)(_mm_shuffle_ps(v72, v72, 170).m128_f32[0] * *((float *)&v126 + 2))) >= v120 )
      goto LABEL_58;
    result.v0 = (UFG::qVector4)_mm_sub_ps(v63, v51);
    result.v1 = (UFG::qVector4)_mm_sub_ps(v64, v51);
    result.v2 = (UFG::qVector4)_mm_sub_ps(v65, v51);
    v73 = ClipToSlab(&result.v0, &outpts, 3u, (UFG::qVector3 *)&v124, *(float *)&width);
    v74 = ClipToSlab(&outpts, &inpts, v73, (UFG::qVector3 *)&v125, *(float *)&width);
    v75 = ClipToSlab(&inpts, &v141, v74, (UFG::qVector3 *)&v126, v121);
    v76 = v75;
    if ( !v75 )
      goto LABEL_58;
    if ( v75 + *((_DWORD *)param1 + 780) > 0x80 )
      break;
    v77 = 0;
    p_z = &v141.z;
    v79 = v11 / (float)(*(float *)&width * 2.0);
    v80 = (int)(float)((float)((float)(COERCE_FLOAT(v126 ^ v16) + v11) * 0.5) * v55);
    v81 = (int)(float)((float)((float)(COERCE_FLOAT(DWORD1(v126) ^ v16) + v11) * 0.5) * v55);
    v82 = (int)(float)((float)((float)(COERCE_FLOAT(DWORD2(v126) ^ v16) + v11) * 0.5) * v55);
    v83 = (int)(float)((float)((float)(COERCE_FLOAT(LODWORD(v54) ^ v16) + v11) * 0.5) * v55);
    v84 = (int)(float)((float)((float)(COERCE_FLOAT(LODWORD(v57) ^ v16) + v11) * 0.5) * v55);
    v85 = LODWORD(v56) ^ v16;
    v86 = v123;
    v87 = *(float *)&v85 + v11;
    v88 = v118;
    v132 = (unsigned int)(int)(float)((float)(v87 * 0.5) * v55);
    do
    {
      v89 = *(p_z - 1);
      v90 = *(p_z - 2);
      v91 = (float)(v54 * v90) + (float)(v57 * v89);
      v92 = *(float *)&v125 * v90;
      v93 = *((float *)&v125 + 1) * v89;
      v94 = v90 + v127.m128_f32[0];
      v95 = v89 + v127.m128_f32[1];
      v96 = *p_z + v127.m128_f32[2];
      v97 = (float)((float)((float)(v92 + v93) + (float)(*p_z * *((float *)&v125 + 2))) * v79) + 0.5;
      v98 = (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(v86 - (float)((float)((float)(v91 + (float)(*p_z * v56)) * v79)
                                                                 + 0.5)) & _xmm)
                  + v88)
          * v122;
      if ( v142 )
      {
        v99 = (float)((float)((float)(v135.v1.x * v95) + (float)(v94 * v135.v0.x)) + (float)(v96 * v135.v2.x))
            + v135.v3.x;
        v100 = v96 * v135.v2.y;
        v101 = (float)(v94 * v135.v0.y) + (float)(v95 * v135.v1.y);
        v102 = (float)(v94 * v135.v0.z) + (float)(v95 * v135.v1.z);
        v94 = v99;
        v95 = (float)(v101 + v100) + v135.v3.y;
        v96 = (float)(v102 + (float)((float)(*p_z + v127.m128_f32[2]) * v135.v2.z)) + v135.v3.z;
      }
      v103 = 3i64 * (v77 + *((_DWORD *)param1 + 780));
      v104 = LODWORD(v98) & 0x7FFFFFFF;
      v105 = HIWORD(LODWORD(v98)) & 0x8000;
      *(float *)&param1[8 * v103] = v94;
      *(float *)&param1[8 * v103 + 4] = v95;
      *(float *)&param1[8 * v103 + 8] = v96;
      if ( (LODWORD(v98) & 0x7FFFFFFFu) <= 0x47FFEFFF )
      {
        if ( v104 >= 0x38800000 )
          v107 = v104 - 939524096;
        else
          v107 = (LODWORD(v98) & 0x7FFFFF | 0x800000u) >> (113 - (v104 >> 23));
        v106 = ((v107 + ((v107 >> 13) & 1) + 4095) >> 13) | v105;
      }
      else
      {
        v106 = v105 | 0x7FFF;
      }
      *(_WORD *)&param1[8 * v103 + 12] = v106;
      v108 = LODWORD(v97) & 0x7FFFFFFF;
      v109 = HIWORD(LODWORD(v97)) & 0x8000;
      if ( (LODWORD(v97) & 0x7FFFFFFFu) <= 0x47FFEFFF )
      {
        if ( v108 >= 0x38800000 )
          v111 = v108 - 939524096;
        else
          v111 = (LODWORD(v97) & 0x7FFFFF | 0x800000u) >> (113 - (v108 >> 23));
        v110 = ((((v111 >> 13) & 1) + v111 + 4095) >> 13) | v109;
      }
      else
      {
        v110 = v109 | 0x7FFF;
      }
      v112 = v132;
      *(_WORD *)&param1[8 * v103 + 14] = v110;
      param1[8 * v103 + 16] = v80;
      param1[8 * v103 + 17] = v81;
      param1[8 * v103 + 18] = v82;
      param1[8 * v103 + 22] = v112;
      param1[8 * v103 + 20] = v83;
      param1[8 * v103 + 21] = v84;
      if ( v94 < *((float *)param1 + 781) )
        *((float *)param1 + 781) = v94;
      if ( v95 < *((float *)param1 + 782) )
        *((float *)param1 + 782) = v95;
      if ( v96 < *((float *)param1 + 783) )
        *((float *)param1 + 783) = v96;
      if ( v94 > *((float *)param1 + 784) )
        *((float *)param1 + 784) = v94;
      if ( v95 > *((float *)param1 + 785) )
        *((float *)param1 + 785) = v95;
      if ( v96 > *((float *)param1 + 786) )
        *((float *)param1 + 786) = v96;
      v54 = *(float *)&v124;
      ++v77;
      p_z += 4;
    }
    while ( v77 < v76 );
    v11 = *(float *)&FLOAT_1_0;
    v16 = _xmm[0];
    v55 = FLOAT_255_0;
    v51 = v127;
    v53 = v143;
    v9 = v142;
    v8 = *(unsigned __int16 **)&v119.x;
    v5 = v117;
    v6 = v134;
    width = v116;
    v113 = *((unsigned int *)param1 + 779);
    *((_DWORD *)param1 + 780) += v76;
    param1[v113 + 3072] = v76;
    ++*((_DWORD *)param1 + 779);
LABEL_58:
    v53 += 3;
    v143 = v53;
    if ( v53 >= v114 )
      goto LABEL_61;
  }
  *((_DWORD *)param1 + 779) = 0;
LABEL_61:
  param1[3148] = 1;
}

