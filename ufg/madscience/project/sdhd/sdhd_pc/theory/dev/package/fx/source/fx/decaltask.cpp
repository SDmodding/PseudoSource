// File Line: 9
// RVA: 0x146BC40
__int64 Render::_dynamic_initializer_for__gTaskFunctionDecl_DecalClipTask__()
{
  UFG::qTaskFunctionDecl::qTaskFunctionDecl(
    &Render::gTaskFunctionDecl_DecalClipTask,
    &Render::gTaskFunctionDeclData_DecalClipTask);
  return atexit(Render::_dynamic_atexit_destructor_for__gTaskFunctionDecl_DecalClipTask__);
}

// File Line: 12
// RVA: 0x1E7CD0
void __fastcall Render::DecalClipTask(int worker_id, UFG::qMemoryStreamer *memory_streamer, void *param0, void *param1)
{
  __m128 v4; // xmm2
  int v5; // er12
  __int64 v6; // r13
  float v7; // xmm1_4
  unsigned __int16 *v8; // r15
  char v9; // r14
  int v10; // eax
  float v11; // xmm10_4
  int v12; // xmm0_4
  char *v13; // rbx
  unsigned int *v14; // rdi
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
  int v59; // er11
  __int64 v60; // r10
  __int64 v61; // r9
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
  unsigned int v77; // er10
  float *v78; // r11
  float v79; // xmm11_4
  float v80; // xmm12_4
  signed int v81; // esi
  signed int v82; // er14
  signed int v83; // er15
  signed int v84; // er12
  signed int v85; // er13
  int v86; // xmm0_4
  float v87; // xmm13_4
  float v88; // xmm0_4
  float v89; // xmm10_4
  float v90; // xmm6_4
  float v91; // xmm4_4
  float v92; // xmm2_4
  float v93; // xmm7_4
  float v94; // xmm0_4
  float v95; // xmm4_4
  float v96; // xmm6_4
  float v97; // xmm5_4
  float v98; // xmm7_4
  float v99; // xmm8_4
  float v100; // xmm3_4
  float v101; // xmm1_4
  float v102; // xmm2_4
  float v103; // xmm5_4
  signed __int64 v104; // r8
  unsigned int v105; // edx
  int v106; // er9
  __int16 v107; // r9
  unsigned int v108; // edx
  unsigned int v109; // edx
  int v110; // er9
  __int16 v111; // r9
  unsigned int v112; // edx
  char v113; // al
  __int64 v114; // rax
  unsigned int v115; // [rsp+38h] [rbp-C8h]
  UFG::qVector3 scale; // [rsp+40h] [rbp-C0h]
  int v117; // [rsp+50h] [rbp-B0h]
  int v118; // [rsp+54h] [rbp-ACh]
  float v119; // [rsp+58h] [rbp-A8h]
  UFG::qVector3 v120; // [rsp+60h] [rbp-A0h]
  float v121; // [rsp+70h] [rbp-90h]
  float v122; // [rsp+74h] [rbp-8Ch]
  float v123; // [rsp+78h] [rbp-88h]
  float v124; // [rsp+7Ch] [rbp-84h]
  __int128 v125; // [rsp+80h] [rbp-80h]
  __int128 v126; // [rsp+90h] [rbp-70h]
  __int128 v127; // [rsp+A0h] [rbp-60h]
  UFG::qVector4 v128; // [rsp+B0h] [rbp-50h]
  UFG::qMatrix44 m; // [rsp+C0h] [rbp-40h]
  UFG::qVector4 v130; // [rsp+100h] [rbp+0h]
  UFG::qVector4 v131; // [rsp+110h] [rbp+10h]
  UFG::qVector4 v132; // [rsp+120h] [rbp+20h]
  __int64 v133; // [rsp+130h] [rbp+30h]
  UFG::qVector4 v134; // [rsp+140h] [rbp+40h]
  __int64 v135; // [rsp+150h] [rbp+50h]
  UFG::qMatrix44 v136; // [rsp+160h] [rbp+60h]
  UFG::qMatrix44 result; // [rsp+1A0h] [rbp+A0h]
  UFG::qMatrix44 dest; // [rsp+1E0h] [rbp+E0h]
  UFG::qMatrix44 d; // [rsp+220h] [rbp+120h]
  UFG::qVector4 inpts; // [rsp+260h] [rbp+160h]
  UFG::qVector4 outpts; // [rsp+A60h] [rbp+960h]
  UFG::qVector4 v142; // [rsp+1260h] [rbp+1160h]
  char v143; // [rsp+1B50h] [rbp+1A50h]
  unsigned int v144; // [rsp+1B58h] [rbp+1A58h]

  v4 = (__m128)*((unsigned int *)param0 + 5);
  v5 = *((_DWORD *)param0 + 40);
  v6 = *((_QWORD *)param0 + 1);
  v7 = *((float *)param0 + 6) * *((float *)param0 + 6);
  v8 = *(unsigned __int16 **)param0;
  v9 = 0;
  v10 = 3 * *((_DWORD *)param0 + 39);
  v11 = *(float *)&FLOAT_1_0;
  v122 = *((float *)param0 + 43);
  v12 = *((_DWORD *)param0 + 36);
  v13 = (char *)param1;
  v14 = (unsigned int *)param0;
  v118 = v5;
  width = *((int *)param0 + 42);
  v16 = _xmm[0];
  v124 = *(float *)&v12;
  v115 = v10;
  v135 = v6;
  v143 = 0;
  v17 = *((_DWORD *)param0 + 37);
  v117 = width;
  v119 = *(float *)&v17;
  v123 = *((float *)param0 + 38);
  v121 = *((float *)param0 + 41);
  v18 = *((float *)param0 + 8) * *((float *)param0 + 8);
  v4.m128_f32[0] = (float)((float)(v4.m128_f32[0] * v4.m128_f32[0])
                         + (float)(*((float *)param0 + 4) * *((float *)param0 + 4)))
                 + v7;
  v19 = *((float *)param0 + 10) * *((float *)param0 + 10);
  LODWORD(v20) = (unsigned __int128)_mm_sqrt_ps(v4);
  v21 = (__m128)*((unsigned int *)param0 + 9);
  scale.x = v20;
  v22 = v20 - 1.0;
  v21.m128_f32[0] = (float)(v21.m128_f32[0] * v21.m128_f32[0]) + v18;
  v23 = *((float *)param0 + 12) * *((float *)param0 + 12);
  v21.m128_f32[0] = v21.m128_f32[0] + v19;
  v24 = *((float *)param0 + 14) * *((float *)param0 + 14);
  LODWORD(v25) = (unsigned __int128)_mm_sqrt_ps(v21);
  v26 = (__m128)*((unsigned int *)param0 + 13);
  scale.y = v25;
  v26.m128_f32[0] = (float)((float)(v26.m128_f32[0] * v26.m128_f32[0]) + v23) + v24;
  LODWORD(v27) = (unsigned __int128)_mm_sqrt_ps(v26);
  scale.z = v27;
  if ( v22 < 0.0 )
    LODWORD(v22) ^= _xmm[0];
  if ( v22 >= 0.001 )
    goto LABEL_66;
  v28 = v25 - 1.0;
  if ( v28 < 0.0 )
    LODWORD(v28) ^= _xmm[0];
  if ( v28 >= 0.001 )
    goto LABEL_66;
  v29 = v27 - 1.0;
  if ( v29 < 0.0 )
    LODWORD(v29) ^= _xmm[0];
  if ( v29 >= 0.001 )
  {
LABEL_66:
    v9 = 1;
    v143 = 1;
  }
  UFG::qScaleMatrix(&dest, &scale);
  v120.x = 1.0 / scale.x;
  v120.y = 1.0 / scale.y;
  v120.z = 1.0 / scale.z;
  UFG::qScaleMatrix(&v136, &v120);
  v30 = *((float *)v14 + 4);
  v31 = (__m128)v14[5];
  v32 = *((float *)v14 + 6);
  v131 = dest.v0;
  v33 = v31;
  v130 = dest.v1;
  v134 = dest.v2;
  v132 = dest.v3;
  v33.m128_f32[0] = (float)((float)(v31.m128_f32[0] * v31.m128_f32[0]) + (float)(v30 * v30)) + (float)(v32 * v32);
  if ( v33.m128_f32[0] == 0.0 )
    v34 = 0.0;
  else
    v34 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v33));
  m.v0.x = v30 * v34;
  v35 = *((float *)v14 + 8);
  m.v0.y = v31.m128_f32[0] * v34;
  v36 = (__m128)v14[9];
  m.v0.z = v32 * v34;
  v37 = *((float *)v14 + 10);
  m.v0.w = v34 * 0.0;
  v38 = v36;
  v38.m128_f32[0] = (float)((float)(v36.m128_f32[0] * v36.m128_f32[0]) + (float)(v35 * v35)) + (float)(v37 * v37);
  if ( v38.m128_f32[0] == 0.0 )
    v39 = 0.0;
  else
    v39 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v38));
  m.v1.x = v35 * v39;
  v40 = *((float *)v14 + 12);
  m.v1.y = v36.m128_f32[0] * v39;
  v41 = (__m128)v14[13];
  m.v1.z = v37 * v39;
  v42 = *((float *)v14 + 14);
  m.v1.w = v39 * 0.0;
  v43 = v41;
  v43.m128_f32[0] = (float)((float)(v41.m128_f32[0] * v41.m128_f32[0]) + (float)(v40 * v40)) + (float)(v42 * v42);
  if ( v43.m128_f32[0] == 0.0 )
    v44 = 0.0;
  else
    v44 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v43));
  LODWORD(m.v3.x) = v14[16];
  v45 = *((float *)v14 + 18);
  v46 = v42 * v44;
  m.v2.x = v40 * v44;
  m.v2.y = v41.m128_f32[0] * v44;
  m.v3.z = v45;
  m.v2.w = v44 * 0.0;
  v47 = *((float *)v14 + 17);
  m.v2.z = v46;
  m.v3.y = v47;
  LODWORD(m.v3.w) = v14[19];
  UFG::qInverse(&d, &m);
  v48 = UFG::qMatrix44::operator*((UFG::qMatrix44 *)(v14 + 20), &result, &d);
  v49 = (__int128)v48->v0;
  v50 = (__int128)v48->v1;
  v51 = (__m128)v48->v3;
  v128 = v48->v3;
  v125 = v49;
  v52 = (__int128)v48->v2;
  v126 = v50;
  *(_QWORD *)(v13 + 3116) = 0i64;
  *((_DWORD *)v13 + 781) = 2139095039;
  *((_DWORD *)v13 + 782) = 2139095039;
  *((_DWORD *)v13 + 783) = 2139095039;
  v53 = 0;
  v144 = 0;
  v127 = v52;
  *((_DWORD *)v13 + 784) = -8388609;
  *((_DWORD *)v13 + 785) = -8388609;
  *((_DWORD *)v13 + 786) = -8388609;
  if ( !v115 )
  {
    v13[3148] = 1;
    return;
  }
  v54 = *(float *)&v125;
  v55 = FLOAT_255_0;
  v56 = *((float *)&v125 + 2);
  v57 = *((float *)&v125 + 1);
  while ( 1 )
  {
    v58 = v8;
    v8 += 3;
    v59 = v6 + v5 * *v58;
    v60 = v6 + v5 * (unsigned int)v58[1];
    v61 = v6 + v5 * (unsigned int)v58[2];
    v62 = (v6 + v5 * (unsigned int)*v58) & 0xFFFFFFFFFFFFFFF0ui64;
    *(_QWORD *)&v120.x = v8;
    v63 = *(__m128 *)((v59 & 0xF) + v62);
    v64 = *(__m128 *)((v60 & 0xF) + (v60 & 0xFFFFFFFFFFFFFFF0ui64));
    v65 = *(__m128 *)((v61 & 0xF) + (v61 & 0xFFFFFFFFFFFFFFF0ui64));
    if ( v9 )
    {
      v63 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v63, v63, 0), (__m128)v131), (__m128)0i64),
                  _mm_mul_ps(_mm_shuffle_ps(v63, v63, 85), (__m128)v130)),
                _mm_mul_ps(_mm_shuffle_ps(v63, v63, 170), (__m128)v134)),
              _mm_mul_ps(_mm_shuffle_ps(v63, v63, 255), (__m128)v132));
      v64 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v64, v64, 0), (__m128)v131), (__m128)0i64),
                  _mm_mul_ps(_mm_shuffle_ps(v64, v64, 85), (__m128)v130)),
                _mm_mul_ps(_mm_shuffle_ps(v64, v64, 170), (__m128)v134)),
              _mm_mul_ps(_mm_shuffle_ps(v64, v64, 255), (__m128)v132));
      v65 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v65, v65, 0), (__m128)v131), (__m128)0i64),
                  _mm_mul_ps(_mm_shuffle_ps(v65, v65, 85), (__m128)v130)),
                _mm_mul_ps(_mm_shuffle_ps(v65, v65, 170), (__m128)v134)),
              _mm_mul_ps(_mm_shuffle_ps(v65, v65, 255), (__m128)v132));
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
    if ( (float)((float)((float)(v72.m128_f32[0] * *(float *)&v127)
                       + (float)(COERCE_FLOAT(_mm_shuffle_ps(v72, v72, 85)) * *((float *)&v127 + 1)))
               + (float)(COERCE_FLOAT(_mm_shuffle_ps(v72, v72, 170)) * *((float *)&v127 + 2))) >= v121 )
      goto LABEL_58;
    result.v0 = (UFG::qVector4)_mm_sub_ps(v63, v51);
    result.v1 = (UFG::qVector4)_mm_sub_ps(v64, v51);
    result.v2 = (UFG::qVector4)_mm_sub_ps(v65, v51);
    v73 = ClipToSlab(&result.v0, &outpts, 3u, (UFG::qVector3 *)&v125, *(float *)&width);
    v74 = ClipToSlab(&outpts, &inpts, v73, (UFG::qVector3 *)&v126, *(float *)&width);
    v75 = ClipToSlab(&inpts, &v142, v74, (UFG::qVector3 *)&v127, v122);
    v76 = v75;
    if ( !v75 )
      goto LABEL_58;
    if ( v75 + *((_DWORD *)v13 + 780) > 0x80 )
      break;
    v77 = 0;
    if ( v75 )
    {
      v78 = &v142.z;
      v79 = v11 / (float)(*(float *)&width * 2.0);
      v80 = v11 / (float)(*(float *)&width * 2.0);
      v81 = (signed int)(float)((float)((float)(COERCE_FLOAT(v127 ^ v16) + v11) * 0.5) * v55);
      v82 = (signed int)(float)((float)((float)(COERCE_FLOAT(DWORD1(v127) ^ v16) + v11) * 0.5) * v55);
      v83 = (signed int)(float)((float)((float)(COERCE_FLOAT(DWORD2(v127) ^ v16) + v11) * 0.5) * v55);
      v84 = (signed int)(float)((float)((float)(COERCE_FLOAT(LODWORD(v54) ^ v16) + v11) * 0.5) * v55);
      v85 = (signed int)(float)((float)((float)(COERCE_FLOAT(LODWORD(v57) ^ v16) + v11) * 0.5) * v55);
      v86 = LODWORD(v56) ^ v16;
      v87 = v124;
      v88 = *(float *)&v86 + v11;
      v89 = v119;
      v133 = (unsigned int)(signed int)(float)((float)(v88 * 0.5) * v55);
      do
      {
        v90 = *(v78 - 1);
        v91 = *(v78 - 2);
        v92 = (float)(v54 * v91) + (float)(v57 * v90);
        v93 = *(float *)&v126 * v91;
        v94 = *((float *)&v126 + 1) * v90;
        v95 = v91 + v128.x;
        v96 = v90 + v128.y;
        v97 = *v78 + v128.z;
        v98 = (float)((float)((float)(v93 + v94) + (float)(*v78 * *((float *)&v126 + 2))) * v80) + 0.5;
        v99 = (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(v87 - (float)((float)((float)(v92 + (float)(*v78 * v56)) * v79)
                                                                   + 0.5)) & _xmm)
                    + v89)
            * v123;
        if ( v143 )
        {
          v100 = (float)((float)((float)(v136.v1.x * v96) + (float)(v95 * v136.v0.x)) + (float)(v97 * v136.v2.x))
               + v136.v3.x;
          v101 = v97 * v136.v2.y;
          v102 = (float)(v95 * v136.v0.y) + (float)(v96 * v136.v1.y);
          v103 = (float)(v95 * v136.v0.z) + (float)(v96 * v136.v1.z);
          v95 = v100;
          v96 = (float)(v102 + v101) + v136.v3.y;
          v97 = (float)(v103 + (float)((float)(*v78 + v128.z) * v136.v2.z)) + v136.v3.z;
        }
        v104 = 3i64 * (v77 + *((_DWORD *)v13 + 780));
        v105 = LODWORD(v99) & 0x7FFFFFFF;
        v106 = (LODWORD(v99) >> 16) & 0x8000;
        *(float *)&v13[8 * v104] = v95;
        *(float *)&v13[8 * v104 + 4] = v96;
        *(float *)&v13[8 * v104 + 8] = v97;
        if ( (LODWORD(v99) & 0x7FFFFFFFu) <= 0x47FFEFFF )
        {
          if ( v105 >= 0x38800000 )
            v108 = v105 - 939524096;
          else
            v108 = (LODWORD(v99) & 0x7FFFFF | 0x800000u) >> (113 - (v105 >> 23));
          v107 = ((v108 + ((v108 >> 13) & 1) + 4095) >> 13) | v106;
        }
        else
        {
          v107 = v106 | 0x7FFF;
        }
        *(_WORD *)&v13[8 * v104 + 12] = v107;
        v109 = LODWORD(v98) & 0x7FFFFFFF;
        v110 = (LODWORD(v98) >> 16) & 0x8000;
        if ( (LODWORD(v98) & 0x7FFFFFFFu) <= 0x47FFEFFF )
        {
          if ( v109 >= 0x38800000 )
            v112 = v109 - 939524096;
          else
            v112 = (LODWORD(v98) & 0x7FFFFF | 0x800000u) >> (113 - (v109 >> 23));
          v111 = ((((v112 >> 13) & 1) + v112 + 4095) >> 13) | v110;
        }
        else
        {
          v111 = v110 | 0x7FFF;
        }
        v113 = v133;
        *(_WORD *)&v13[8 * v104 + 14] = v111;
        v13[8 * v104 + 16] = v81;
        v13[8 * v104 + 17] = v82;
        v13[8 * v104 + 18] = v83;
        v13[8 * v104 + 22] = v113;
        v13[8 * v104 + 20] = v84;
        v13[8 * v104 + 21] = v85;
        if ( v95 < *((float *)v13 + 781) )
          *((float *)v13 + 781) = v95;
        if ( v96 < *((float *)v13 + 782) )
          *((float *)v13 + 782) = v96;
        if ( v97 < *((float *)v13 + 783) )
          *((float *)v13 + 783) = v97;
        if ( v95 > *((float *)v13 + 784) )
          *((float *)v13 + 784) = v95;
        if ( v96 > *((float *)v13 + 785) )
          *((float *)v13 + 785) = v96;
        if ( v97 > *((float *)v13 + 786) )
          *((float *)v13 + 786) = v97;
        v54 = *(float *)&v125;
        ++v77;
        v78 += 4;
      }
      while ( v77 < v76 );
      v11 = *(float *)&FLOAT_1_0;
      v16 = _xmm[0];
      v55 = FLOAT_255_0;
      v51 = (__m128)v128;
      v53 = v144;
      v9 = v143;
      v8 = *(unsigned __int16 **)&v120.x;
      v5 = v118;
      v6 = v135;
      width = v117;
    }
    v114 = *((unsigned int *)v13 + 779);
    *((_DWORD *)v13 + 780) += v76;
    v13[v114 + 3072] = v76;
    ++*((_DWORD *)v13 + 779);
LABEL_58:
    v53 += 3;
    v144 = v53;
    if ( v53 >= v115 )
      goto LABEL_61;
  }
  *((_DWORD *)v13 + 779) = 0;
LABEL_61:
  v13[3148] = 1;
} FLOAT_255_0;
      v51 = (__m128)v128;
      v53 = v144;
      v9 = v143;
      v8 = *(unsigned __int16 **)&v120.x;
      v5 = v118;
      v6 = v135;
      width = v117;
    }
    v114 = *((unsigned int *)v13 + 779);
    *((_DWORD *)v13 + 780) += v76;
    v13[v114 + 3072] = v76;
    ++*((_DWORD *)v13 + 779);
LABEL_58:
    v53 += 3;
    v144 = v53;
    if ( v53 >= v115 )
    

