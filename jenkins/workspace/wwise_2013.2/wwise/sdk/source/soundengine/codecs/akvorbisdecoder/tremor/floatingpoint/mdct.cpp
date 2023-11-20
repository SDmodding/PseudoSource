// File Line: 929
// RVA: 0xABD6B0
void __fastcall mdct_bitreverse_SIMD(float *x, int n, int shift)
{
  int v3; // er11
  char v4; // di
  float *v5; // rbx
  int v6; // kr00_4
  __m128 *v7; // r9
  __m128 v8; // xmm2
  __int64 v9; // rdx
  __int64 v10; // rcx
  int v11; // er8
  __m128 v12; // xmm1
  __m128 v13; // xmm2
  __m128 *v14; // rcx
  __m128 v15; // xmm1
  __int64 v16; // rcx
  unsigned __int64 v17; // rcx
  __m128 v18; // xmm2

  v3 = 0;
  v4 = shift;
  v5 = x;
  v6 = n;
  v7 = (__m128 *)&x[(signed __int64)n >> 1];
  do
  {
    v8 = v7[-1];
    v9 = v3;
    --v7;
    v10 = v3;
    v3 += 2;
    v11 = ((unsigned __int8)bitrev[v9 >> 8] | 16
                                            * (16 * (unsigned __int8)bitrev[v9 & 0xF] | (unsigned __int8)bitrev[(v10 >> 4) & 0xF])) >> v4;
    v12 = _mm_shuffle_ps(v8, *(__m128 *)&v5[v11], 238);
    v13 = _mm_shuffle_ps(v8, *(__m128 *)&v5[v11], 68);
    *(__m128 *)&v5[v11] = v12;
    v14 = (__m128 *)&v5[v11 | (unsigned __int64)(v6 / 4)];
    if ( v7 > v14 )
    {
      v15 = _mm_shuffle_ps(v13, *v14, 228);
      v13 = _mm_shuffle_ps(*v14, v13, 228);
      *v14 = v15;
    }
    *v7 = v13;
  }
  while ( v3 < v6 / 8 );
  do
  {
    v16 = v3;
    --v7;
    v3 += 2;
    v17 = (unsigned __int64)&v5[(16
                               * (16 * (unsigned __int8)bitrev[v16 & 0xF] | (unsigned __int8)bitrev[(v16 >> 4) & 0xF]) | (unsigned __int8)bitrev[v16 >> 8]) >> v4];
    if ( (unsigned __int64)v7 > v17 )
    {
      v18 = _mm_shuffle_ps(*v7, *(__m128 *)(v17 - 8), 228);
      *(__m128 *)(v17 - 8) = _mm_shuffle_ps(*(__m128 *)(v17 - 8), *v7, 228);
      *v7 = v18;
    }
  }
  while ( v7 > (__m128 *)v5 );
}

// File Line: 1108
// RVA: 0xABCBF0
void __fastcall mdct_backward(int n, float *in)
{
  float *v2; // rbx
  signed int v3; // edx
  signed int v4; // eax
  int i; // edi
  int v6; // er9
  float *v7; // rdx
  signed int v8; // er13
  __int64 v9; // rbp
  __int64 v10; // r10
  signed __int64 v11; // r14
  float *v12; // rcx
  unsigned __int64 v13; // r8
  float v14; // xmm3_4
  float v15; // xmm4_4
  float v16; // xmm5_4
  float v17; // xmm1_4
  float v18; // xmm3_4
  float v19; // xmm4_4
  float v20; // xmm5_4
  float v21; // xmm1_4
  float *v22; // rcx
  float *v23; // rdx
  float *v24; // rax
  float v25; // xmm3_4
  float v26; // xmm5_4
  float v27; // xmm2_4
  float v28; // xmm4_4
  float v29; // xmm7_4
  float v30; // xmm6_4
  float v31; // xmm1_4
  char v32; // r15
  int v33; // er12
  signed int v34; // esi
  char v35; // r13
  float *v36; // r10
  __int64 v37; // r11
  __int64 v38; // rdi
  signed __int64 v39; // r9
  float *v40; // rcx
  signed __int64 v41; // rdx
  signed __int64 v42; // r8
  __m128 v43; // xmm1
  __m128 v44; // xmm2
  __m128 v45; // xmm3
  __m128 v46; // xmm0
  __m128 v47; // xmm2
  __m128 v48; // xmm0
  __m128 v49; // xmm1
  __m128 v50; // xmm1
  __m128 v51; // xmm2
  __m128 v52; // xmm3
  __m128 v53; // xmm0
  __m128 v54; // xmm2
  __m128 v55; // xmm0
  __m128 v56; // xmm1
  signed __int64 v57; // rcx
  unsigned __int64 v58; // rax
  __m128 v59; // xmm2
  __m128 v60; // xmm6
  __m128 v61; // xmm1
  __m128 v62; // xmm5
  __m128 v63; // xmm2
  __m128 v64; // xmm1
  __m128 v65; // xmm3
  __m128 v66; // xmm2
  __m128 v67; // xmm1
  __m128 v68; // xmm2
  __m128 v69; // xmm1
  __m128 v70; // xmm3
  __m128 v71; // xmm2
  __m128 v72; // xmm1
  __m128 v73; // xmm2
  __m128 v74; // xmm1
  __m128 v75; // xmm3
  __m128 v76; // xmm2
  __m128 v77; // xmm1
  __m128 v78; // xmm5
  __m128 v79; // xmm2
  __m128 v80; // xmm5
  __m128 v81; // xmm0
  __m128 v82; // xmm6
  __m128 v83; // xmm0
  __m128 v84; // xmm1
  __m128 v85; // xmm2
  __m128 v86; // xmm1
  __m128 v87; // xmm6
  __m128 v88; // xmm3
  __m128 v89; // xmm1
  __m128 v90; // xmm3
  __m128 v91; // xmm5
  __m128 v92; // xmm4
  __m128 v93; // xmm2
  __m128 v94; // xmm5
  __m128 v95; // xmm2
  __m128 v96; // xmm0
  __m128 v97; // xmm1
  __m128 v98; // xmm2
  __m128 v99; // xmm1
  __m128 v100; // xmm5
  __m128 v101; // xmm2
  __m128 v102; // xmm0
  __m128 v103; // xmm3
  __m128 v104; // xmm1
  __m128 v105; // xmm2
  __m128 v106; // xmm3
  __m128 v107; // xmm2
  __m128 v108; // xmm1
  __m128 v109; // xmm2
  __m128 v110; // xmm1
  __m128 v111; // xmm2
  __m128 v112; // xmm1
  __m128 v113; // xmm3
  __m128 v114; // xmm2
  __m128 v115; // xmm1
  __m128 v116; // xmm2
  __m128 v117; // xmm4
  __m128 v118; // xmm0
  __m128 v119; // xmm6
  __m128 v120; // xmm2
  __m128 v121; // xmm2
  __m128 v122; // xmm3
  __m128 v123; // xmm0
  __m128 v124; // xmm1
  __m128 v125; // xmm2
  __m128 v126; // xmm1
  __m128 v127; // xmm2
  __m128 v128; // xmm6
  __m128 v129; // xmm0
  __m128 v130; // xmm3
  __m128 v131; // xmm1
  __m128 v132; // xmm2
  __m128 v133; // xmm3
  __m128 v134; // xmm2
  float *v135; // rcx
  float *v136; // rdx
  unsigned __int64 v137; // r9
  float *v138; // rax
  float *v139; // r8
  unsigned __int64 v140; // r10
  float v141; // xmm7_4
  float v142; // xmm2_4
  float v143; // xmm9_4
  float v144; // xmm8_4
  float v145; // xmm3_4
  float v146; // xmm1_4
  float v147; // xmm8_4
  float v148; // xmm9_4
  float v149; // xmm5_4
  float v150; // xmm7_4
  float v151; // xmm9_4
  float v152; // xmm8_4
  float v153; // xmm4_4
  float v154; // xmm3_4
  float v155; // xmm1_4
  float v156; // xmm8_4
  float v157; // xmm9_4
  float v158; // xmm5_4
  float v159; // xmm7_4
  signed int v160; // er13
  float v161; // xmm3_4
  float v162; // xmm4_4
  float v163; // xmm5_4
  int v164; // xmm2_4
  int v165; // xmm2_4
  float *v166; // r8
  signed __int64 v167; // rcx
  float v168; // xmm6_4
  float v169; // xmm7_4
  float v170; // xmm5_4
  float v171; // xmm4_4
  float v172; // xmm5_4
  int v173; // xmm2_4
  float v174; // xmm4_4
  float v175; // xmm3_4
  float v176; // xmm6_4
  float v177; // xmm7_4
  int v178; // xmm1_4
  float v179; // xmm0_4
  float v180; // xmm2_4
  float v181; // xmm3_4
  float v182; // xmm5_4
  int v183; // xmm2_4
  float v184; // xmm4_4
  __int64 v185; // [rsp+28h] [rbp-F0h]
  __int64 v186; // [rsp+30h] [rbp-E8h]
  int v187; // [rsp+120h] [rbp+8h]
  int v188; // [rsp+128h] [rbp+10h]
  int v189; // [rsp+130h] [rbp+18h]
  signed int v190; // [rsp+138h] [rbp+20h]

  v187 = n;
  v2 = in;
  v3 = 4;
  v4 = 16;
  for ( i = n; !(v4 & n); ++v3 )
    v4 = __ROL4__(v4, 1);
  v6 = 13 - v3;
  v7 = fsincos_lookup0;
  v188 = v6;
  v8 = 2 << v6;
  v9 = 2 << v6;
  v190 = 2 << v6;
  v10 = n >> 1;
  v189 = n >> 1;
  v11 = 4 * v9;
  v185 = v10;
  v186 = 2 << v6;
  v12 = &v2[v10 - 3];
  v13 = (unsigned __int64)&v2[i >> 2];
  do
  {
    v14 = v7[1];
    v15 = *v7;
    v16 = *v12;
    v12 -= 4;
    v7 = (float *)((char *)v7 + v11);
    v17 = (float)(v14 * v12[6]) + (float)(v15 * v16);
    v12[6] = (float)(v15 * v12[6]) - (float)(v14 * v16);
    v12[4] = v17;
  }
  while ( (unsigned __int64)v12 >= v13 );
  do
  {
    v18 = *v7;
    v19 = v7[1];
    v20 = *v12;
    v12 -= 4;
    v7 = (float *)((char *)v7 - v11);
    v21 = (float)(v18 * v12[6]) + (float)(v19 * v20);
    v12[6] = (float)(v19 * v12[6]) - (float)(v18 * v20);
    v12[4] = v21;
  }
  while ( v12 >= v2 );
  v22 = v2;
  v23 = fsincos_lookup0;
  v24 = &v2[v10 - 4];
  do
  {
    v25 = v23[1];
    v26 = *v23;
    v27 = v22[2];
    v23 = (float *)((char *)v23 + v11);
    v28 = *v22;
    v29 = *v24;
    v30 = v24[2];
    v24 -= 4;
    v22 += 4;
    v24[4] = (float)(v25 * v27) - (float)(v26 * v28);
    v24[6] = (float)(v26 * v27) + (float)(v25 * v28);
    v31 = (float)(*v23 * v30) - (float)(v23[1] * v29);
    *(v22 - 2) = (float)(v23[1] * v30) + (float)(*v23 * v29);
    *(v22 - 4) = v31;
  }
  while ( (unsigned __int64)v24 >= v13 );
  v32 = 0;
  v33 = 7 - v6;
  v34 = 1;
  if ( 7 - v6 > 0 )
  {
    v35 = v6;
    do
    {
      if ( v34 > 0 )
      {
        v36 = v2;
        v37 = v189 >> v32;
        v38 = (unsigned int)v34;
        v39 = 16i64 * ((4 << (v32 + v35)) / 4);
        do
        {
          v40 = fsincos_lookup0;
          v41 = (signed __int64)&v36[v37 - 4];
          v42 = (signed __int64)&v36[(v37 >> 1) - 4];
          do
          {
            v43 = *(__m128 *)v41;
            v44 = *(__m128 *)v42;
            v42 -= 16i64;
            v41 -= 16i64;
            v45 = _mm_sub_ps(_mm_shuffle_ps(v43, v44, 220), _mm_shuffle_ps(v43, v44, 137));
            v46 = v44;
            v47 = _mm_shuffle_ps(v44, v43, 216);
            v48 = _mm_shuffle_ps(v46, v43, 141);
            *(__m128 *)(v41 + 16) = _mm_add_ps(_mm_shuffle_ps(v47, v47, 114), _mm_shuffle_ps(v48, v48, 114));
            v49 = *(__m128 *)v40;
            v40 = (float *)((char *)v40 + v39);
            *(__m128 *)(v42 + 16) = _mm_add_ps(
                                      _mm_mul_ps(
                                        _mm_mul_ps(_mm_shuffle_ps(v49, v49, 85), _mm_shuffle_ps(v45, v45, 156)),
                                        vfsign1),
                                      _mm_mul_ps(_mm_shuffle_ps(v49, v49, 0), _mm_shuffle_ps(v45, v45, 201)));
          }
          while ( v40 < &fsincos_lookup0[1024] );
          do
          {
            v50 = *(__m128 *)v41;
            v51 = *(__m128 *)v42;
            v42 -= 16i64;
            v41 -= 16i64;
            v52 = _mm_sub_ps(_mm_shuffle_ps(v50, v51, 200), _mm_shuffle_ps(v50, v51, 157));
            v53 = v51;
            v54 = _mm_shuffle_ps(v51, v50, 216);
            v55 = _mm_shuffle_ps(v53, v50, 141);
            *(__m128 *)(v41 + 16) = _mm_add_ps(_mm_shuffle_ps(v54, v54, 114), _mm_shuffle_ps(v55, v55, 114));
            v56 = *(__m128 *)v40;
            v40 = (float *)((char *)v40 - v39);
            *(__m128 *)(v42 + 16) = _mm_add_ps(
                                      _mm_mul_ps(
                                        _mm_mul_ps(_mm_shuffle_ps(v56, v56, 85), _mm_shuffle_ps(v52, v52, 201)),
                                        vfsign2),
                                      _mm_mul_ps(_mm_shuffle_ps(v56, v56, 0), _mm_shuffle_ps(v52, v52, 156)));
          }
          while ( v40 > fsincos_lookup0 );
          v36 += v37;
          --v38;
        }
        while ( v38 );
      }
      v34 = __ROL4__(v34, 1);
      --v33;
      ++v32;
    }
    while ( v33 > 0 );
    v11 = 4 * v9;
    v8 = v190;
    v6 = v188;
    i = v187;
    v10 = v185;
    v9 = v186;
  }
  if ( v10 > 0 )
  {
    v57 = (signed __int64)(v2 + 12);
    v58 = ((unsigned __int64)(v10 - 1) >> 5) + 1;
    do
    {
      v59 = *(__m128 *)(v57 + 16);
      v60 = *(__m128 *)(v57 + 64);
      v61 = v59;
      v62 = *(__m128 *)(v57 + 64);
      v63 = _mm_shuffle_ps(v59, *(__m128 *)(v57 - 48), 141);
      v64 = _mm_shuffle_ps(v61, *(__m128 *)(v57 - 48), 216);
      v65 = _mm_sub_ps(v64, v63);
      *(__m128 *)(v57 + 16) = _mm_add_ps(_mm_shuffle_ps(v63, v63, 216), _mm_shuffle_ps(v64, v64, 216));
      v66 = *(__m128 *)(v57 + 32);
      v67 = v66;
      v68 = _mm_shuffle_ps(v66, *(__m128 *)(v57 - 32), 141);
      v69 = _mm_shuffle_ps(v67, *(__m128 *)(v57 - 32), 216);
      *(__m128 *)(v57 - 48) = _mm_add_ps(
                                _mm_mul_ps(_mm_shuffle_ps(v65, v65, 216), vfcPI_3131),
                                _mm_mul_ps(_mm_shuffle_ps(v65, v65, 141), vfcPI_m131m3));
      v70 = _mm_sub_ps(v69, v68);
      *(__m128 *)(v57 + 32) = _mm_add_ps(_mm_shuffle_ps(v68, v68, 216), _mm_shuffle_ps(v69, v69, 216));
      v71 = *(__m128 *)(v57 + 48);
      v72 = v71;
      v73 = _mm_shuffle_ps(v71, *(__m128 *)(v57 - 16), 141);
      v74 = _mm_shuffle_ps(v72, *(__m128 *)(v57 - 16), 216);
      *(__m128 *)(v57 - 32) = _mm_mul_ps(
                                _mm_add_ps(
                                  _mm_mul_ps(_mm_shuffle_ps(v70, v70, 153), vfsign3),
                                  _mm_shuffle_ps(v70, v70, 204)),
                                vfcPI2_8);
      v75 = _mm_sub_ps(v74, v73);
      v76 = _mm_add_ps(_mm_shuffle_ps(v73, v73, 216), _mm_shuffle_ps(v74, v74, 216));
      v77 = *(__m128 *)v57;
      v78 = _mm_shuffle_ps(v62, *(__m128 *)v57, 200);
      *(__m128 *)(v57 + 48) = v76;
      *(__m128 *)(v57 - 16) = _mm_add_ps(
                                _mm_mul_ps(_mm_shuffle_ps(v75, v75, 216), vfcPI_1313),
                                _mm_mul_ps(_mm_shuffle_ps(v75, v75, 141), vfcPI_m313m1));
      v79 = *(__m128 *)(v57 - 16);
      v80 = _mm_sub_ps(v78, _mm_shuffle_ps(v60, v77, 157));
      v81 = v60;
      v82 = _mm_shuffle_ps(v60, v77, 141);
      v83 = _mm_shuffle_ps(v81, v77, 216);
      v84 = v79;
      v85 = _mm_shuffle_ps(v79, *(__m128 *)(v57 - 48), 141);
      v86 = _mm_shuffle_ps(v84, *(__m128 *)(v57 - 48), 216);
      v87 = _mm_add_ps(_mm_shuffle_ps(v82, v82, 216), _mm_shuffle_ps(v83, v83, 216));
      v88 = _mm_sub_ps(v86, v85);
      *(__m128 *)(v57 - 16) = _mm_add_ps(_mm_shuffle_ps(v85, v85, 216), _mm_shuffle_ps(v86, v86, 216));
      *(__m128 *)(v57 - 48) = _mm_mul_ps(
                                _mm_add_ps(
                                  _mm_mul_ps(_mm_shuffle_ps(v88, v88, 157), vfsign3),
                                  _mm_shuffle_ps(v88, v88, 200)),
                                vfcPI2_8);
      v89 = *(__m128 *)(v57 - 32);
      v90 = *(__m128 *)(v57 - 16);
      v91 = _mm_shuffle_ps(v80, v80, 156);
      v92 = _mm_shuffle_ps(v91, v89, 216);
      v93 = _mm_sub_ps(_mm_shuffle_ps(*(__m128 *)(v57 - 32), v91, 140), _mm_shuffle_ps(v89, v91, 217));
      v94 = _mm_shuffle_ps(v91, v89, 141);
      v95 = _mm_shuffle_ps(v93, v93, 54);
      v96 = _mm_shuffle_ps(*(__m128 *)(v57 - 48), v95, 221);
      v97 = _mm_shuffle_ps(*(__m128 *)(v57 - 48), v95, 136);
      v98 = v97;
      v99 = _mm_sub_ps(v97, v96);
      v100 = _mm_add_ps(_mm_shuffle_ps(v94, v94, 216), _mm_shuffle_ps(v92, v92, 216));
      v101 = _mm_add_ps(v98, v96);
      *(__m128 *)(v57 - 48) = _mm_add_ps(
                                _mm_mul_ps(_mm_shuffle_ps(v99, v99, 17), vfsign4),
                                _mm_shuffle_ps(v99, v99, 238));
      v102 = _mm_shuffle_ps(v90, v100, 221);
      v103 = _mm_shuffle_ps(v90, v100, 136);
      v104 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v101, v101, 68), vfsign2), _mm_shuffle_ps(v101, v101, 238));
      v105 = v103;
      v106 = _mm_sub_ps(v103, v102);
      *(__m128 *)(v57 - 32) = v104;
      v107 = _mm_add_ps(v105, v102);
      *(__m128 *)(v57 - 16) = _mm_add_ps(
                                _mm_mul_ps(_mm_shuffle_ps(v106, v106, 17), vfsign4),
                                _mm_shuffle_ps(v106, v106, 238));
      v108 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v107, v107, 68), vfsign2), _mm_shuffle_ps(v107, v107, 238));
      v109 = *(__m128 *)(v57 + 48);
      *(__m128 *)v57 = v108;
      v110 = v109;
      v111 = _mm_shuffle_ps(v109, *(__m128 *)(v57 + 16), 141);
      v112 = _mm_shuffle_ps(v110, *(__m128 *)(v57 + 16), 216);
      v113 = _mm_sub_ps(v112, v111);
      v114 = _mm_add_ps(_mm_shuffle_ps(v111, v111, 216), _mm_shuffle_ps(v112, v112, 216));
      v115 = *(__m128 *)(v57 + 32);
      *(__m128 *)(v57 + 48) = v114;
      v116 = _mm_shuffle_ps(v115, v87, 140);
      v117 = _mm_shuffle_ps(v87, v115, 216);
      *(__m128 *)(v57 + 16) = _mm_mul_ps(
                                _mm_add_ps(
                                  _mm_mul_ps(_mm_shuffle_ps(v113, v113, 157), vfsign3),
                                  _mm_shuffle_ps(v113, v113, 200)),
                                vfcPI2_8);
      v118 = _mm_shuffle_ps(v115, v87, 217);
      v119 = _mm_shuffle_ps(v87, v115, 141);
      v120 = _mm_sub_ps(v116, v118);
      v121 = _mm_shuffle_ps(v120, v120, 54);
      v122 = *(__m128 *)(v57 + 48);
      v123 = _mm_shuffle_ps(*(__m128 *)(v57 + 16), v121, 221);
      v124 = _mm_shuffle_ps(*(__m128 *)(v57 + 16), v121, 136);
      v125 = v124;
      v57 += 128i64;
      v126 = _mm_sub_ps(v124, v123);
      v127 = _mm_add_ps(v125, v123);
      v128 = _mm_add_ps(_mm_shuffle_ps(v119, v119, 216), _mm_shuffle_ps(v117, v117, 216));
      *(__m128 *)(v57 - 112) = _mm_add_ps(
                                 _mm_mul_ps(_mm_shuffle_ps(v126, v126, 17), vfsign4),
                                 _mm_shuffle_ps(v126, v126, 238));
      v129 = _mm_shuffle_ps(v122, v128, 221);
      v130 = _mm_shuffle_ps(v122, v128, 136);
      v131 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v127, v127, 68), vfsign2), _mm_shuffle_ps(v127, v127, 238));
      v132 = v130;
      v133 = _mm_sub_ps(v130, v129);
      *(__m128 *)(v57 - 96) = v131;
      v134 = _mm_add_ps(v132, v129);
      *(__m128 *)(v57 - 80) = _mm_add_ps(
                                _mm_mul_ps(_mm_shuffle_ps(v133, v133, 17), vfsign4),
                                _mm_shuffle_ps(v133, v133, 238));
      *(__m128 *)(v57 - 64) = _mm_add_ps(
                                _mm_mul_ps(_mm_shuffle_ps(v134, v134, 68), vfsign2),
                                _mm_shuffle_ps(v134, v134, 238));
      --v58;
    }
    while ( v58 );
  }
  mdct_bitreverse_SIMD(v2, i, v6);
  v135 = v2;
  v136 = fsincos_lookup1;
  v137 = (unsigned __int64)&v2[(signed __int64)i >> 1];
  v138 = &v2[(signed __int64)i >> 1];
  if ( v8 < 4 )
    v139 = fsincos_lookup1;
  else
    v139 = &fsincos_lookup0[v9 >> 1];
  v140 = (unsigned __int64)(v139 + 1024);
  do
  {
    v141 = v139[1];
    v142 = *v139;
    v143 = *v135;
    v138 -= 2;
    v139 = (float *)((char *)v139 + v11);
    v144 = v135[1];
    v145 = *v135 + *v138;
    v135 += 2;
    v146 = v138[1] - v144;
    v147 = (float)(v144 + v138[1]) * 0.5;
    v148 = (float)(v143 - *v138) * 0.5;
    v149 = (float)((float)(v142 * v146) + (float)(v141 * v145)) * 0.5;
    v150 = (float)((float)(v141 * v146) - (float)(v142 * v145)) * 0.5;
    *(v135 - 2) = v149 + v147;
    *(v135 - 1) = v150 + v148;
    *v138 = v147 - v149;
    v138[1] = v150 - v148;
  }
  while ( (unsigned __int64)v139 < v140 );
  do
  {
    v151 = *v135;
    v152 = v135[1];
    v153 = *(v138 - 1);
    v138 -= 2;
    v139 = (float *)((char *)v139 - v11);
    v135 += 2;
    v154 = v151 + *v138;
    v155 = v153 - v152;
    v156 = (float)(v152 + v153) * 0.5;
    v157 = (float)(v151 - *v138) * 0.5;
    v158 = (float)((float)(v139[1] * v155) + (float)(*v139 * v154)) * 0.5;
    v159 = (float)((float)(*v139 * v155) - (float)(v139[1] * v154)) * 0.5;
    *(v135 - 2) = v158 + v156;
    *(v135 - 1) = v159 + v157;
    *v138 = v156 - v158;
    v138[1] = v159 - v157;
  }
  while ( v135 < v138 );
  v160 = v8 >> 2;
  if ( v160 <= 1 )
  {
    v166 = &fsincos_lookup0[2];
    v167 = (signed __int64)(v2 + 2);
    v168 = fsincos_lookup0[0] * 0.5;
    v169 = fsincos_lookup0[1] * 0.5;
    do
    {
      v170 = *v136;
      v171 = v136[1];
      v136 += 2;
      v166 += 2;
      v172 = v170 * 0.5;
      v173 = *(_DWORD *)(v167 - 4) ^ _xmm[0];
      v174 = v171 * 0.5;
      v175 = *(float *)(v167 - 8);
      v176 = v168 + v172;
      v177 = v169 + v174;
      v178 = *(_DWORD *)(v167 - 4) ^ _xmm[0];
      v167 += 16i64;
      v179 = v175 * v176;
      v180 = (float)(*(float *)&v173 * v176) - (float)(v175 * v177);
      v181 = *(float *)(v167 - 16);
      *(float *)(v167 - 24) = (float)(*(float *)&v178 * v177) + v179;
      *(float *)(v167 - 20) = v180;
      v168 = *(v166 - 2) * 0.5;
      v182 = v172 + v168;
      v183 = *(_DWORD *)(v167 - 12) ^ _xmm[0];
      v169 = *(v166 - 1) * 0.5;
      v184 = v174 + v169;
      *(float *)(v167 - 16) = (float)(v184 * *(float *)&v183) + (float)(v182 * v181);
      *(float *)(v167 - 12) = (float)(v182 * *(float *)&v183) - (float)(v184 * v181);
    }
    while ( v167 - 8 < v137 );
  }
  else
  {
    if ( v160 >= 4 )
      v136 = &fsincos_lookup0[(signed __int64)v160 >> 1];
    do
    {
      v161 = v136[1];
      v162 = *v136;
      v163 = *v2;
      v136 += v160;
      v164 = *((_DWORD *)v2 + 1);
      v2 += 2;
      v165 = v164 ^ _xmm[0];
      *(v2 - 2) = (float)(v161 * *(float *)&v165) + (float)(v162 * v163);
      *(v2 - 1) = (float)(v162 * *(float *)&v165) - (float)(v161 * v163);
    }
    while ( (unsigned __int64)v2 < v137 );
  }
}

// File Line: 1134
// RVA: 0xABD810
void __fastcall mdct_shift_right(int n, int *in, int *right)
{
  int v3; // ecx
  int v4; // er9
  __int64 v5; // rax
  __int64 v6; // r11
  int v7; // ecx

  v3 = n >> 2;
  v4 = 0;
  v5 = 0i64;
  v6 = v3;
  if ( v3 > 0 )
  {
    do
    {
      v7 = 2 * v4;
      ++v5;
      ++v4;
      right[v5 - 1] = in[v7 + 1];
    }
    while ( v5 < v6 );
  }
}

// File Line: 1160
// RVA: 0xABD850
void __fastcall mdct_unroll_lap(int n0, int n1, int lW, int W, float *in, float *right, const float *w0, const float *w1, __int16 *out, int step, int start, int end)
{
  int v12; // esi
  int v13; // eax
  int v14; // eax
  const float *v15; // rdi
  float *v16; // r11
  const float *v17; // rbx
  int v18; // edx
  int v19; // er14
  int v20; // er14
  int v21; // esi
  int v22; // ebp
  int v23; // er15
  __int16 *v24; // r10
  int v25; // ecx
  unsigned __int64 v26; // r9
  float v27; // xmm0_4
  float v28; // xmm0_4
  int v29; // er9
  int v30; // er8
  int v31; // ebp
  int v32; // er15
  signed __int64 v33; // rdx
  unsigned __int64 v34; // r13
  float *v35; // r11
  const float *v36; // rbx
  float *v37; // rdi
  float *i; // r12
  float v39; // xmm1_4
  float v40; // xmm0_4
  signed int v41; // er8
  int v42; // er8
  int v43; // ebp
  unsigned __int64 v44; // r13
  int v45; // er15
  signed __int64 v46; // rdx
  float *v47; // r11
  float *v48; // rbx
  float *v49; // rdi
  float *v50; // r9
  int v51; // er14
  signed __int64 v52; // r12
  signed int v53; // er8
  __int16 *v54; // r10
  signed int v55; // er8
  __int16 *v56; // r10
  signed int v57; // er8
  __int16 *v58; // r10
  signed int v59; // er8
  signed __int64 v60; // r14
  signed __int64 v61; // rdi
  float v62; // xmm1_4
  signed int v63; // er8
  int v64; // eax
  __int64 v65; // rax
  unsigned __int64 v66; // rbx
  float *v67; // r9
  int v68; // edi
  signed __int64 v69; // r11
  __int16 *v70; // r10
  signed int v71; // er8
  __int16 *v72; // r10
  signed int v73; // er8
  __int16 *v74; // r10
  float v75; // xmm0_4
  float v76; // xmm0_4
  float *ina; // [rsp+50h] [rbp+28h]

  v12 = n1;
  if ( !W || (v13 = n1, !lW) )
    v13 = n0;
  ina = &in[v13 >> 1];
  v14 = n1;
  if ( !lW )
    v14 = n0;
  v15 = w1;
  v16 = &right[v14 >> 2];
  if ( W && lW )
    v17 = &w1[(signed __int64)n1 >> 1];
  else
    v17 = &w0[(signed __int64)n0 >> 1];
  if ( (W && lW || (v15 = w0, w1 = w0, lW)) && !W )
    v18 = (n1 >> 2) - (n0 >> 2);
  else
    v18 = 0;
  if ( !lW || (v19 = v12, !W) )
    v19 = n0;
  v20 = v19 >> 2;
  if ( lW || !W )
    v21 = 0;
  else
    v21 = (v12 >> 2) - (n0 >> 2);
  v22 = end;
  v23 = start;
  v24 = out;
  if ( v18 )
  {
    v25 = v18;
    if ( end < v18 )
      v25 = end;
    if ( start < v18 )
      v18 = start;
    v22 = end - v25;
    v23 = start - v18;
    v26 = (unsigned __int64)&v16[-v25];
    v16 -= v18;
    if ( (unsigned __int64)v16 > v26 )
    {
      do
      {
        v27 = *(v16 - 1);
        --v16;
        v28 = v27 * 0.001953125;
        *v24 = (signed int)v28
             - ((signed int)v28 >= -32768 ? 0 : (signed int)v28 + -32768)
             - (((signed int)v28 - 0x7FFF) & (((signed int)v28 <= 0x7FFF) - 1));
        v24 += step;
      }
      while ( (unsigned __int64)v16 > v26 );
      v15 = w1;
    }
  }
  v29 = v20;
  if ( v22 < v20 )
    v29 = v22;
  v30 = v20;
  if ( v23 < v20 )
    v30 = v23;
  v31 = v22 - v29;
  v32 = v23 - v30;
  v33 = 4i64 * v30;
  v34 = (unsigned __int64)&v16[-v29];
  v35 = &v16[v33 / 0xFFFFFFFFFFFFFFFCui64];
  v36 = &v17[v33 / 0xFFFFFFFFFFFFFFFCui64];
  v37 = (float *)&v15[(unsigned __int64)v33 / 4];
  for ( i = &ina[-2 * v30]; (unsigned __int64)v35 > v34; v24 += step )
  {
    v39 = *v37;
    v40 = *(v36 - 1);
    --v36;
    i -= 2;
    --v35;
    ++v37;
    v41 = (signed int)(float)((float)((float)(v39 * *i) + (float)(v40 * *v35)) * 0.001953125);
    *v24 = v41 - (v41 >= -32768 ? 0 : v41 + -32768) - ((v41 - 0x7FFF) & ((v41 <= 0x7FFF) - 1));
  }
  v42 = v20;
  if ( v31 < v20 )
    v42 = v31;
  if ( v32 < v20 )
    v20 = v32;
  v43 = v31 - v42;
  v44 = (unsigned __int64)&v35[v42];
  v45 = v32 - v20;
  v46 = 4i64 * v20;
  v47 = &v35[(unsigned __int64)v46 / 4];
  v48 = (float *)&v36[v46 / 0xFFFFFFFFFFFFFFFCui64];
  v49 = &v37[(unsigned __int64)v46 / 4];
  v50 = &i[2 * v20];
  if ( (unsigned __int64)v47 < v44 )
  {
    if ( (signed __int64)(v44 - (_QWORD)v47 + 3) / 4 < 4 )
    {
      v51 = step;
    }
    else
    {
      v51 = step;
      v52 = step;
      do
      {
        v53 = (signed int)(float)((float)((float)(*(v48 - 1) * *v47) - (float)(*v50 * *v49)) * 0.001953125);
        *v24 = v53 - (v53 >= -32768 ? 0 : v53 + -32768) - ((v53 - 0x7FFF) & ((v53 <= 0x7FFF) - 1));
        v54 = &v24[v52];
        v55 = (signed int)(float)((float)((float)(*(v48 - 2) * v47[1]) - (float)(v49[1] * v50[2])) * 0.001953125);
        *v54 = v55 - (v55 >= -32768 ? 0 : v55 + -32768) - ((v55 - 0x7FFF) & ((v55 <= 0x7FFF) - 1));
        v56 = &v54[v52];
        v57 = (signed int)(float)((float)((float)(*(v48 - 3) * v47[2]) - (float)(v49[2] * v50[4])) * 0.001953125);
        v48 -= 4;
        *v56 = v57 - (v57 >= -32768 ? 0 : v57 + -32768) - ((v57 - 0x7FFF) & ((v57 <= 0x7FFF) - 1));
        v58 = &v56[v52];
        v59 = (signed int)(float)((float)((float)(v47[3] * *v48) - (float)(v49[3] * v50[6])) * 0.001953125);
        v47 += 4;
        v50 += 8;
        v49 += 4;
        *v58 = v59 - (v59 >= -32768 ? 0 : v59 + -32768) - ((v59 - 0x7FFF) & ((v59 <= 0x7FFF) - 1));
        v24 = &v58[v52];
      }
      while ( (signed __int64)v47 < (signed __int64)(v44 - 12) );
    }
    if ( (unsigned __int64)v47 < v44 )
    {
      v60 = 2i64 * v51;
      v61 = (char *)v49 - (char *)v47;
      do
      {
        v62 = *(v48 - 1);
        --v48;
        v63 = (signed int)(float)((float)((float)(v62 * *v47) - (float)(*(float *)((char *)v47 + v61) * *v50))
                                * 0.001953125);
        ++v47;
        v50 += 2;
        *v24 = v63 - (v63 >= -32768 ? 0 : v63 + -32768) - ((v63 - 0x7FFF) & ((v63 <= 0x7FFF) - 1));
        v24 = (__int16 *)((char *)v24 + v60);
      }
      while ( (unsigned __int64)v47 < v44 );
    }
  }
  if ( v21 )
  {
    v64 = v21;
    if ( v43 < v21 )
      v64 = v43;
    v65 = 2 * v64;
    if ( v45 < v21 )
      v21 = v45;
    v66 = (unsigned __int64)&v50[v65];
    v67 = &v50[2 * v21];
    if ( (unsigned __int64)v67 < v66 )
    {
      if ( (signed __int64)(v66 - (_QWORD)v67 + 7) / 8 < 4 )
      {
        v68 = step;
      }
      else
      {
        v68 = step;
        v69 = step;
        do
        {
          *v24 = (signed int)(float)(*v67 * -0.001953125)
               - ((signed int)(float)(*v67 * -0.001953125) >= -32768 ? 0 : (signed int)(float)(*v67 * -0.001953125)
                                                                         + -32768)
               - (((signed int)(float)(*v67 * -0.001953125) - 0x7FFF) & (((signed int)(float)(*v67 * -0.001953125) <= 0x7FFF)
                                                                       - 1));
          v70 = &v24[v69];
          v71 = (signed int)(float)(v67[2] * -0.001953125);
          *v70 = v71 - (v71 >= -32768 ? 0 : v71 + -32768) - ((v71 - 0x7FFF) & ((v71 <= 0x7FFF) - 1));
          v72 = &v70[v69];
          v73 = (signed int)(float)(v67[4] * -0.001953125);
          *v72 = v73 - (v73 >= -32768 ? 0 : v73 + -32768) - ((v73 - 0x7FFF) & ((v73 <= 0x7FFF) - 1));
          v74 = &v72[v69];
          v75 = v67[6] * -0.001953125;
          *v74 = (signed int)v75
               - ((signed int)v75 >= -32768 ? 0 : (signed int)v75 + -32768)
               - (((signed int)v75 - 0x7FFF) & (((signed int)v75 <= 0x7FFF) - 1));
          v24 = &v74[v69];
          v67 += 8;
        }
        while ( (signed __int64)v67 < (signed __int64)(v66 - 24) );
      }
      for ( ; (unsigned __int64)v67 < v66; v24 += v68 )
      {
        v76 = *v67 * -0.001953125;
        v67 += 2;
        *v24 = (signed int)v76
             - ((signed int)v76 >= -32768 ? 0 : (signed int)v76 + -32768)
             - (((signed int)v76 - 0x7FFF) & (((signed int)v76 <= 0x7FFF) - 1));
      }
    }
  }
}

