// File Line: 929
// RVA: 0xABD6B0
void __fastcall mdct_bitreverse_SIMD(__m128 *x, int n, char shift)
{
  int v3; // r11d
  __m128 *v6; // r9
  unsigned __int64 v7; // rsi
  int v8; // r10d
  __m128 v9; // xmm2
  __int64 v10; // rdx
  __int64 v11; // rcx
  int v12; // r8d
  __m128 v13; // xmm1
  __m128 v14; // xmm2
  __m128 *v15; // rcx
  __m128 v16; // xmm1
  __int64 v17; // rcx
  float *v18; // rcx
  __m128 v19; // xmm2

  v3 = 0;
  v6 = (__m128 *)((char *)x + 4 * ((__int64)n >> 1));
  v7 = n / 4;
  v8 = n / 8;
  do
  {
    v9 = v6[-1];
    v10 = v3;
    --v6;
    v11 = v3;
    v3 += 2;
    v12 = ((unsigned __int8)bitrev[v10 >> 8] | (16
                                              * ((16 * (unsigned __int8)bitrev[v10 & 0xF]) | (unsigned __int8)bitrev[(v11 >> 4) & 0xF]))) >> shift;
    v13 = _mm_shuffle_ps(v9, *(__m128 *)((char *)x + 4 * v12), 238);
    v14 = _mm_shuffle_ps(v9, *(__m128 *)((char *)x + 4 * v12), 68);
    *(__m128 *)((char *)x + 4 * v12) = v13;
    v15 = (__m128 *)((char *)x + 4 * (v12 | v7));
    if ( v6 > v15 )
    {
      v16 = _mm_shuffle_ps(v14, *v15, 228);
      v14 = _mm_shuffle_ps(*v15, v14, 228);
      *v15 = v16;
    }
    *v6 = v14;
  }
  while ( v3 < v8 );
  do
  {
    v17 = v3;
    --v6;
    v3 += 2;
    v18 = &x->m128_f32[((16 * ((16 * (unsigned __int8)bitrev[v17 & 0xF]) | (unsigned __int8)bitrev[(v17 >> 4) & 0xF])) | (unsigned __int8)bitrev[v17 >> 8]) >> shift];
    if ( v6 > (__m128 *)v18 )
    {
      v19 = _mm_shuffle_ps(*v6, *(__m128 *)(v18 - 2), 228);
      *(__m128 *)(v18 - 2) = _mm_shuffle_ps(*(__m128 *)(v18 - 2), *v6, 228);
      *v6 = v19;
    }
  }
  while ( v6 > x );
}

// File Line: 1108
// RVA: 0xABCBF0
void __fastcall mdct_backward(int n, float *in)
{
  int v3; // edx
  int v4; // eax
  int i; // edi
  int v6; // r9d
  float *v7; // rdx
  int v8; // r13d
  __int64 v9; // rbp
  __int64 v10; // r10
  __int64 v11; // r14
  float *v12; // rcx
  float *v13; // r8
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
  int v33; // r12d
  int v34; // esi
  char v35; // r13
  float *v36; // r10
  __int64 v37; // r11
  __int64 v38; // rdi
  __int64 v39; // r9
  float *v40; // rcx
  __m128 *v41; // rdx
  __m128 *v42; // r8
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
  float *v57; // rcx
  unsigned __int64 v58; // rax
  __m128 v59; // xmm6
  __m128 v60; // xmm1
  __m128 v61; // xmm2
  __m128 v62; // xmm3
  __m128 v63; // xmm1
  __m128 v64; // xmm3
  __m128 v65; // xmm1
  __m128 v66; // xmm2
  __m128 v67; // xmm1
  __m128 v68; // xmm3
  __m128 v69; // xmm1
  __m128 v70; // xmm2
  __m128 v71; // xmm1
  __m128 v72; // xmm3
  __m128 v73; // xmm2
  __m128 v74; // xmm1
  __m128 v75; // xmm5
  __m128 v76; // xmm5
  __m128 v77; // xmm0
  __m128 v78; // xmm6
  __m128 v79; // xmm0
  __m128 v80; // xmm1
  __m128 v81; // xmm2
  __m128 v82; // xmm1
  __m128 v83; // xmm6
  __m128 v84; // xmm3
  __m128 v85; // xmm1
  __m128 v86; // xmm3
  __m128 v87; // xmm5
  __m128 v88; // xmm4
  __m128 v89; // xmm2
  __m128 v90; // xmm5
  __m128 v91; // xmm2
  __m128 v92; // xmm0
  __m128 v93; // xmm2
  __m128 v94; // xmm1
  __m128 v95; // xmm5
  __m128 v96; // xmm2
  __m128 v97; // xmm0
  __m128 v98; // xmm1
  __m128 v99; // xmm2
  __m128 v100; // xmm3
  __m128 v101; // xmm2
  __m128 v102; // xmm1
  __m128 v103; // xmm2
  __m128 v104; // xmm1
  __m128 v105; // xmm2
  __m128 v106; // xmm3
  __m128 v107; // xmm1
  __m128 v108; // xmm3
  __m128 v109; // xmm2
  __m128 v110; // xmm1
  __m128 v111; // xmm2
  __m128 v112; // xmm4
  __m128 v113; // xmm0
  __m128 v114; // xmm6
  __m128 v115; // xmm2
  __m128 v116; // xmm2
  __m128 v117; // xmm3
  __m128 v118; // xmm0
  __m128 v119; // xmm2
  __m128 v120; // xmm1
  __m128 v121; // xmm2
  __m128 v122; // xmm6
  __m128 v123; // xmm0
  __m128 v124; // xmm1
  __m128 v125; // xmm2
  __m128 v126; // xmm3
  __m128 v127; // xmm2
  float *v128; // rcx
  float *v129; // rdx
  float *v130; // r9
  float *v131; // rax
  float *v132; // r8
  float *v133; // r10
  float v134; // xmm7_4
  float v135; // xmm2_4
  float v136; // xmm9_4
  float v137; // xmm8_4
  float v138; // xmm3_4
  float v139; // xmm1_4
  float v140; // xmm8_4
  float v141; // xmm9_4
  float v142; // xmm5_4
  float v143; // xmm7_4
  float v144; // xmm9_4
  float v145; // xmm8_4
  float v146; // xmm4_4
  float v147; // xmm3_4
  float v148; // xmm5_4
  float v149; // xmm2_4
  float v150; // xmm1_4
  float v151; // xmm8_4
  float v152; // xmm9_4
  float v153; // xmm5_4
  float v154; // xmm7_4
  int v155; // r13d
  float v156; // xmm3_4
  float v157; // xmm4_4
  float v158; // xmm5_4
  int v159; // xmm2_4
  int v160; // xmm2_4
  float *v161; // r8
  float *v162; // rcx
  float v163; // xmm6_4
  float v164; // xmm7_4
  float v165; // xmm5_4
  float v166; // xmm4_4
  float v167; // xmm5_4
  int v168; // xmm2_4
  float v169; // xmm4_4
  float v170; // xmm3_4
  float v171; // xmm6_4
  float v172; // xmm7_4
  float v173; // xmm1_4
  float v174; // xmm0_4
  float v175; // xmm2_4
  float v176; // xmm3_4
  float v177; // xmm5_4
  int v178; // xmm2_4
  float v179; // xmm4_4
  __int64 v180; // [rsp+28h] [rbp-F0h]
  int v182; // [rsp+128h] [rbp+10h]
  int v183; // [rsp+130h] [rbp+18h]
  int v184; // [rsp+138h] [rbp+20h]

  v3 = 4;
  v4 = 16;
  for ( i = n; (v4 & n) == 0; ++v3 )
    v4 = __ROL4__(v4, 1);
  v6 = 13 - v3;
  v7 = fsincos_lookup0;
  v182 = v6;
  v8 = 2 << v6;
  v9 = 2 << v6;
  v184 = 2 << v6;
  v10 = n >> 1;
  v183 = n >> 1;
  v11 = 4 * v9;
  v180 = v10;
  v12 = &in[v10 - 3];
  v13 = &in[i >> 2];
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
  while ( v12 >= v13 );
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
  while ( v12 >= in );
  v22 = in;
  v23 = fsincos_lookup0;
  v24 = &in[v10 - 4];
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
  while ( v24 >= v13 );
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
        v36 = in;
        v37 = v183 >> v32;
        v38 = (unsigned int)v34;
        v39 = 16i64 * ((4 << (v32 + v35)) / 4);
        do
        {
          v40 = fsincos_lookup0;
          v41 = (__m128 *)&v36[v37 - 4];
          v42 = (__m128 *)&v36[(v37 >> 1) - 4];
          do
          {
            v43 = *v41;
            v44 = *v42--;
            --v41;
            v45 = _mm_sub_ps(_mm_shuffle_ps(v43, v44, 220), _mm_shuffle_ps(v43, v44, 137));
            v46 = v44;
            v47 = _mm_shuffle_ps(v44, v43, 216);
            v48 = _mm_shuffle_ps(v46, v43, 141);
            v41[1] = _mm_add_ps(_mm_shuffle_ps(v47, v47, 114), _mm_shuffle_ps(v48, v48, 114));
            v49 = *(__m128 *)v40;
            v40 = (float *)((char *)v40 + v39);
            v42[1] = _mm_add_ps(
                       _mm_mul_ps(_mm_mul_ps(_mm_shuffle_ps(v49, v49, 85), _mm_shuffle_ps(v45, v45, 156)), vfsign1),
                       _mm_mul_ps(_mm_shuffle_ps(v49, v49, 0), _mm_shuffle_ps(v45, v45, 201)));
          }
          while ( v40 < &fsincos_lookup0[1024] );
          do
          {
            v50 = *v41;
            v51 = *v42--;
            --v41;
            v52 = _mm_sub_ps(_mm_shuffle_ps(v50, v51, 200), _mm_shuffle_ps(v50, v51, 157));
            v53 = v51;
            v54 = _mm_shuffle_ps(v51, v50, 216);
            v55 = _mm_shuffle_ps(v53, v50, 141);
            v41[1] = _mm_add_ps(_mm_shuffle_ps(v54, v54, 114), _mm_shuffle_ps(v55, v55, 114));
            v56 = *(__m128 *)v40;
            v40 = (float *)((char *)v40 - v39);
            v42[1] = _mm_add_ps(
                       _mm_mul_ps(_mm_mul_ps(_mm_shuffle_ps(v56, v56, 85), _mm_shuffle_ps(v52, v52, 201)), vfsign2),
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
    v8 = v184;
    v6 = v182;
    i = n;
    v10 = v180;
  }
  if ( v10 > 0 )
  {
    v57 = in + 12;
    v58 = ((unsigned __int64)(v10 - 1) >> 5) + 1;
    do
    {
      v59 = *(__m128 *)(v57 + 16);
      v60 = *(__m128 *)(v57 + 4);
      v61 = _mm_shuffle_ps(v60, *(__m128 *)(v57 - 12), 141);
      v62 = _mm_shuffle_ps(v60, *(__m128 *)(v57 - 12), 216);
      v63 = _mm_shuffle_ps(v62, v62, 216);
      v64 = _mm_sub_ps(v62, v61);
      *((__m128 *)v57 + 1) = _mm_add_ps(_mm_shuffle_ps(v61, v61, 216), v63);
      v65 = *(__m128 *)(v57 + 8);
      v66 = _mm_shuffle_ps(v65, *(__m128 *)(v57 - 8), 141);
      v67 = _mm_shuffle_ps(v65, *(__m128 *)(v57 - 8), 216);
      *((__m128 *)v57 - 3) = _mm_add_ps(
                               _mm_mul_ps(_mm_shuffle_ps(v64, v64, 216), vfcPI_3131),
                               _mm_mul_ps(_mm_shuffle_ps(v64, v64, 141), vfcPI_m131m3));
      v68 = _mm_sub_ps(v67, v66);
      *((__m128 *)v57 + 2) = _mm_add_ps(_mm_shuffle_ps(v66, v66, 216), _mm_shuffle_ps(v67, v67, 216));
      v69 = *(__m128 *)(v57 + 12);
      v70 = _mm_shuffle_ps(v69, *(__m128 *)(v57 - 4), 141);
      v71 = _mm_shuffle_ps(v69, *(__m128 *)(v57 - 4), 216);
      *((__m128 *)v57 - 2) = _mm_mul_ps(
                               _mm_add_ps(
                                 _mm_mul_ps(_mm_shuffle_ps(v68, v68, 153), vfsign3),
                                 _mm_shuffle_ps(v68, v68, 204)),
                               vfcPI2_8);
      v72 = _mm_sub_ps(v71, v70);
      v73 = _mm_add_ps(_mm_shuffle_ps(v70, v70, 216), _mm_shuffle_ps(v71, v71, 216));
      v74 = *(__m128 *)v57;
      v75 = _mm_shuffle_ps(v59, *(__m128 *)v57, 200);
      *((__m128 *)v57 + 3) = v73;
      *((__m128 *)v57 - 1) = _mm_add_ps(
                               _mm_mul_ps(_mm_shuffle_ps(v72, v72, 216), vfcPI_1313),
                               _mm_mul_ps(_mm_shuffle_ps(v72, v72, 141), vfcPI_m313m1));
      v76 = _mm_sub_ps(v75, _mm_shuffle_ps(v59, v74, 157));
      v77 = v59;
      v78 = _mm_shuffle_ps(v59, v74, 141);
      v79 = _mm_shuffle_ps(v77, v74, 216);
      v80 = *(__m128 *)(v57 - 4);
      v81 = _mm_shuffle_ps(v80, *(__m128 *)(v57 - 12), 141);
      v82 = _mm_shuffle_ps(v80, *(__m128 *)(v57 - 12), 216);
      v83 = _mm_add_ps(_mm_shuffle_ps(v78, v78, 216), _mm_shuffle_ps(v79, v79, 216));
      v84 = _mm_sub_ps(v82, v81);
      *((__m128 *)v57 - 1) = _mm_add_ps(_mm_shuffle_ps(v81, v81, 216), _mm_shuffle_ps(v82, v82, 216));
      *((__m128 *)v57 - 3) = _mm_mul_ps(
                               _mm_add_ps(
                                 _mm_mul_ps(_mm_shuffle_ps(v84, v84, 157), vfsign3),
                                 _mm_shuffle_ps(v84, v84, 200)),
                               vfcPI2_8);
      v85 = *(__m128 *)(v57 - 8);
      v86 = *(__m128 *)(v57 - 4);
      v87 = _mm_shuffle_ps(v76, v76, 156);
      v88 = _mm_shuffle_ps(v87, v85, 216);
      v89 = _mm_sub_ps(_mm_shuffle_ps(v85, v87, 140), _mm_shuffle_ps(v85, v87, 217));
      v90 = _mm_shuffle_ps(v87, v85, 141);
      v91 = _mm_shuffle_ps(v89, v89, 54);
      v92 = _mm_shuffle_ps(*(__m128 *)(v57 - 12), v91, 221);
      v93 = _mm_shuffle_ps(*(__m128 *)(v57 - 12), v91, 136);
      v94 = _mm_sub_ps(v93, v92);
      v95 = _mm_add_ps(_mm_shuffle_ps(v90, v90, 216), _mm_shuffle_ps(v88, v88, 216));
      v96 = _mm_add_ps(v93, v92);
      *((__m128 *)v57 - 3) = _mm_add_ps(
                               _mm_mul_ps(_mm_shuffle_ps(v94, v94, 17), vfsign4),
                               _mm_shuffle_ps(v94, v94, 238));
      v97 = _mm_shuffle_ps(v86, v95, 221);
      v98 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v96, v96, 68), vfsign2), _mm_shuffle_ps(v96, v96, 238));
      v99 = _mm_shuffle_ps(v86, v95, 136);
      v100 = _mm_sub_ps(v99, v97);
      *((__m128 *)v57 - 2) = v98;
      v101 = _mm_add_ps(v99, v97);
      *((__m128 *)v57 - 1) = _mm_add_ps(
                               _mm_mul_ps(_mm_shuffle_ps(v100, v100, 17), vfsign4),
                               _mm_shuffle_ps(v100, v100, 238));
      v102 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v101, v101, 68), vfsign2), _mm_shuffle_ps(v101, v101, 238));
      v103 = *(__m128 *)(v57 + 12);
      *(__m128 *)v57 = v102;
      v104 = v103;
      v105 = _mm_shuffle_ps(v103, *(__m128 *)(v57 + 4), 141);
      v106 = _mm_shuffle_ps(v104, *(__m128 *)(v57 + 4), 216);
      v107 = _mm_shuffle_ps(v106, v106, 216);
      v108 = _mm_sub_ps(v106, v105);
      v109 = _mm_add_ps(_mm_shuffle_ps(v105, v105, 216), v107);
      v110 = *(__m128 *)(v57 + 8);
      *((__m128 *)v57 + 3) = v109;
      v111 = _mm_shuffle_ps(v110, v83, 140);
      v112 = _mm_shuffle_ps(v83, v110, 216);
      *((__m128 *)v57 + 1) = _mm_mul_ps(
                               _mm_add_ps(
                                 _mm_mul_ps(_mm_shuffle_ps(v108, v108, 157), vfsign3),
                                 _mm_shuffle_ps(v108, v108, 200)),
                               vfcPI2_8);
      v113 = _mm_shuffle_ps(v110, v83, 217);
      v114 = _mm_shuffle_ps(v83, v110, 141);
      v115 = _mm_sub_ps(v111, v113);
      v116 = _mm_shuffle_ps(v115, v115, 54);
      v117 = *(__m128 *)(v57 + 12);
      v118 = _mm_shuffle_ps(*(__m128 *)(v57 + 4), v116, 221);
      v119 = _mm_shuffle_ps(*(__m128 *)(v57 + 4), v116, 136);
      v57 += 32;
      v120 = _mm_sub_ps(v119, v118);
      v121 = _mm_add_ps(v119, v118);
      v122 = _mm_add_ps(_mm_shuffle_ps(v114, v114, 216), _mm_shuffle_ps(v112, v112, 216));
      *((__m128 *)v57 - 7) = _mm_add_ps(
                               _mm_mul_ps(_mm_shuffle_ps(v120, v120, 17), vfsign4),
                               _mm_shuffle_ps(v120, v120, 238));
      v123 = _mm_shuffle_ps(v117, v122, 221);
      v124 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v121, v121, 68), vfsign2), _mm_shuffle_ps(v121, v121, 238));
      v125 = _mm_shuffle_ps(v117, v122, 136);
      v126 = _mm_sub_ps(v125, v123);
      *((__m128 *)v57 - 6) = v124;
      v127 = _mm_add_ps(v125, v123);
      *((__m128 *)v57 - 5) = _mm_add_ps(
                               _mm_mul_ps(_mm_shuffle_ps(v126, v126, 17), vfsign4),
                               _mm_shuffle_ps(v126, v126, 238));
      *((__m128 *)v57 - 4) = _mm_add_ps(
                               _mm_mul_ps(_mm_shuffle_ps(v127, v127, 68), vfsign2),
                               _mm_shuffle_ps(v127, v127, 238));
      --v58;
    }
    while ( v58 );
  }
  mdct_bitreverse_SIMD(in, i, v6);
  v128 = in;
  v129 = fsincos_lookup1;
  v130 = &in[(__int64)i >> 1];
  v131 = v130;
  if ( v8 < 4 )
    v132 = fsincos_lookup1;
  else
    v132 = &fsincos_lookup0[v9 >> 1];
  v133 = v132 + 1024;
  do
  {
    v134 = v132[1];
    v135 = *v132;
    v136 = *v128;
    v131 -= 2;
    v132 = (float *)((char *)v132 + v11);
    v137 = v128[1];
    v138 = *v128 + *v131;
    v128 += 2;
    v139 = v131[1] - v137;
    v140 = (float)(v137 + v131[1]) * 0.5;
    v141 = (float)(v136 - *v131) * 0.5;
    v142 = (float)((float)(v135 * v139) + (float)(v134 * v138)) * 0.5;
    v143 = (float)((float)(v134 * v139) - (float)(v135 * v138)) * 0.5;
    *(v128 - 2) = v142 + v140;
    *(v128 - 1) = v143 + v141;
    *v131 = v140 - v142;
    v131[1] = v143 - v141;
  }
  while ( v132 < v133 );
  do
  {
    v144 = *v128;
    v145 = v128[1];
    v146 = *(v131 - 1);
    v131 -= 2;
    v132 = (float *)((char *)v132 - v11);
    v128 += 2;
    v147 = v144 + *v131;
    v148 = v132[1];
    v149 = v148 * v147;
    v150 = v146 - v145;
    v151 = (float)(v145 + v146) * 0.5;
    v152 = (float)(v144 - *v131) * 0.5;
    v153 = (float)((float)(v148 * v150) + (float)(*v132 * v147)) * 0.5;
    v154 = (float)((float)(*v132 * v150) - v149) * 0.5;
    *(v128 - 2) = v153 + v151;
    *(v128 - 1) = v154 + v152;
    *v131 = v151 - v153;
    v131[1] = v154 - v152;
  }
  while ( v128 < v131 );
  v155 = v8 >> 2;
  if ( v155 <= 1 )
  {
    v161 = &fsincos_lookup0[2];
    v162 = in + 2;
    v163 = fsincos_lookup0[0] * 0.5;
    v164 = fsincos_lookup0[1] * 0.5;
    do
    {
      v165 = *v129;
      v166 = v129[1];
      v129 += 2;
      v161 += 2;
      v167 = v165 * 0.5;
      v168 = *((_DWORD *)v162 - 1) ^ _xmm[0];
      v169 = v166 * 0.5;
      v170 = *(v162 - 2);
      v171 = v163 + v167;
      v172 = v164 + v169;
      v173 = *(float *)&v168;
      v162 += 4;
      v174 = v170 * v171;
      v175 = (float)(*(float *)&v168 * v171) - (float)(v170 * v172);
      v176 = *(v162 - 4);
      *(v162 - 6) = (float)(v173 * v172) + v174;
      *(v162 - 5) = v175;
      v163 = *(v161 - 2) * 0.5;
      v177 = v167 + v163;
      v178 = *((_DWORD *)v162 - 3) ^ _xmm[0];
      v164 = *(v161 - 1) * 0.5;
      v179 = v169 + v164;
      *(v162 - 4) = (float)(v179 * *(float *)&v178) + (float)(v177 * v176);
      *(v162 - 3) = (float)(v177 * *(float *)&v178) - (float)(v179 * v176);
    }
    while ( v162 - 2 < v130 );
  }
  else
  {
    if ( v155 >= 4 )
      v129 = &fsincos_lookup0[(__int64)v155 >> 1];
    do
    {
      v156 = v129[1];
      v157 = *v129;
      v158 = *in;
      v129 += v155;
      v159 = *((_DWORD *)in + 1);
      in += 2;
      v160 = v159 ^ _xmm[0];
      *(in - 2) = (float)(v156 * *(float *)&v160) + (float)(v157 * v158);
      *(in - 1) = (float)(v157 * *(float *)&v160) - (float)(v156 * v158);
    }
    while ( in < v130 );
  }
}

// File Line: 1134
// RVA: 0xABD810
void __fastcall mdct_shift_right(int n, int *in, int *right)
{
  int v3; // ecx
  int v4; // r9d
  __int64 v5; // rax
  __int64 i; // r11
  int v7; // ecx

  v3 = n >> 2;
  v4 = 0;
  v5 = 0i64;
  for ( i = v3; v5 < i; right[v5 - 1] = in[v7 + 1] )
  {
    v7 = 2 * v4;
    ++v5;
    ++v4;
  }
}

// File Line: 1160
// RVA: 0xABD850
void __fastcall mdct_unroll_lap(
        int n0,
        int n1,
        int lW,
        int W,
        float *in,
        float *right,
        const float *w0,
        const float *w1,
        __int16 *out,
        int step,
        int start,
        int end)
{
  int v13; // eax
  int v14; // eax
  const float *v15; // rdi
  float *v16; // r11
  const float *v17; // rbx
  int v18; // edx
  int v19; // r14d
  int v20; // r14d
  int v21; // esi
  int v22; // ebp
  int v23; // r15d
  int v25; // ecx
  float *v26; // r9
  float v27; // xmm0_4
  float v28; // xmm0_4
  int v29; // r9d
  int v30; // r8d
  int v31; // ebp
  int v32; // r15d
  __int64 v33; // rdx
  float *v34; // r13
  float *v35; // r11
  const float *v36; // rbx
  float *v37; // rdi
  float *i; // r12
  float v39; // xmm1_4
  float v40; // xmm0_4
  int v41; // r8d
  int v42; // r8d
  int v43; // ebp
  float *v44; // r13
  int v45; // r15d
  __int64 v46; // rdx
  float *v47; // r11
  float *v48; // rbx
  float *v49; // rdi
  float *v50; // r9
  int v51; // r14d
  unsigned __int64 v52; // r12
  int v53; // r8d
  __int16 *v54; // r10
  int v55; // r8d
  __int16 *v56; // r10
  int v57; // r8d
  __int16 *v58; // r10
  int v59; // r8d
  __int64 v60; // r14
  signed __int64 v61; // rdi
  float v62; // xmm1_4
  int v63; // r8d
  int v64; // eax
  __int64 v65; // rax
  float *v66; // rbx
  float *v67; // r9
  int v68; // edi
  unsigned __int64 v69; // r11
  __int16 *v70; // r10
  int v71; // r8d
  __int16 *v72; // r10
  int v73; // r8d
  __int16 *v74; // r10
  float v75; // xmm0_4
  float v76; // xmm0_4
  float *ina; // [rsp+50h] [rbp+28h]

  if ( !W || (v13 = n1, !lW) )
    v13 = n0;
  ina = &in[v13 >> 1];
  v14 = n1;
  if ( !lW )
    v14 = n0;
  v15 = w1;
  v16 = &right[v14 >> 2];
  if ( W && lW )
    v17 = &w1[(__int64)n1 >> 1];
  else
    v17 = &w0[(__int64)n0 >> 1];
  if ( (W && lW || (v15 = w0, w1 = w0, lW)) && !W )
    v18 = (n1 >> 2) - (n0 >> 2);
  else
    v18 = 0;
  if ( !lW || (v19 = n1, !W) )
    v19 = n0;
  v20 = v19 >> 2;
  if ( lW || !W )
    v21 = 0;
  else
    v21 = (n1 >> 2) - (n0 >> 2);
  v22 = end;
  v23 = start;
  if ( v18 )
  {
    v25 = v18;
    if ( end < v18 )
      v25 = end;
    if ( start < v18 )
      v18 = start;
    v22 = end - v25;
    v23 = start - v18;
    v26 = &v16[-v25];
    v16 -= v18;
    if ( v16 > v26 )
    {
      do
      {
        v27 = *--v16;
        v28 = v27 * 0.001953125;
        *out = (int)v28
             - ((int)v28 >= -32768 ? 0 : (int)v28 + 0x8000)
             - (((int)v28 - 0x7FFF) & (((int)v28 <= 0x7FFF) - 1));
        out += step;
      }
      while ( v16 > v26 );
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
  v34 = &v16[-v29];
  v35 = &v16[v33 / 0xFFFFFFFFFFFFFFFCui64];
  v36 = &v17[v33 / 0xFFFFFFFFFFFFFFFCui64];
  v37 = (float *)&v15[(unsigned __int64)v33 / 4];
  for ( i = &ina[-2 * v30]; v35 > v34; out += step )
  {
    v39 = *v37;
    v40 = *--v36;
    i -= 2;
    --v35;
    ++v37;
    v41 = (int)(float)((float)((float)(v39 * *i) + (float)(v40 * *v35)) * 0.001953125);
    *out = v41 - (v41 >= -32768 ? 0 : v41 + 0x8000) - ((v41 - 0x7FFF) & ((v41 <= 0x7FFF) - 1));
  }
  v42 = v20;
  if ( v31 < v20 )
    v42 = v31;
  if ( v32 < v20 )
    v20 = v32;
  v43 = v31 - v42;
  v44 = &v35[v42];
  v45 = v32 - v20;
  v46 = 4i64 * v20;
  v47 = &v35[(unsigned __int64)v46 / 4];
  v48 = (float *)&v36[v46 / 0xFFFFFFFFFFFFFFFCui64];
  v49 = &v37[(unsigned __int64)v46 / 4];
  v50 = &i[2 * v20];
  if ( v47 < v44 )
  {
    if ( ((char *)v44 - (char *)v47 + 3) / 4 < 4 )
    {
      v51 = step;
    }
    else
    {
      v51 = step;
      v52 = step;
      do
      {
        v53 = (int)(float)((float)((float)(*(v48 - 1) * *v47) - (float)(*v50 * *v49)) * 0.001953125);
        *out = v53 - (v53 >= -32768 ? 0 : v53 + 0x8000) - ((v53 - 0x7FFF) & ((v53 <= 0x7FFF) - 1));
        v54 = &out[v52];
        v55 = (int)(float)((float)((float)(*(v48 - 2) * v47[1]) - (float)(v49[1] * v50[2])) * 0.001953125);
        *v54 = v55 - (v55 >= -32768 ? 0 : v55 + 0x8000) - ((v55 - 0x7FFF) & ((v55 <= 0x7FFF) - 1));
        v56 = &v54[v52];
        v57 = (int)(float)((float)((float)(*(v48 - 3) * v47[2]) - (float)(v49[2] * v50[4])) * 0.001953125);
        v48 -= 4;
        *v56 = v57 - (v57 >= -32768 ? 0 : v57 + 0x8000) - ((v57 - 0x7FFF) & ((v57 <= 0x7FFF) - 1));
        v58 = &v56[v52];
        v59 = (int)(float)((float)((float)(v47[3] * *v48) - (float)(v49[3] * v50[6])) * 0.001953125);
        v47 += 4;
        v50 += 8;
        v49 += 4;
        *v58 = v59 - (v59 >= -32768 ? 0 : v59 + 0x8000) - ((v59 - 0x7FFF) & ((v59 <= 0x7FFF) - 1));
        out = &v58[v52];
      }
      while ( (__int64)v47 < (__int64)(v44 - 3) );
    }
    if ( v47 < v44 )
    {
      v60 = 2i64 * v51;
      v61 = (char *)v49 - (char *)v47;
      do
      {
        v62 = *--v48;
        v63 = (int)(float)((float)((float)(v62 * *v47) - (float)(*(float *)((char *)v47 + v61) * *v50)) * 0.001953125);
        ++v47;
        v50 += 2;
        *out = v63 - (v63 >= -32768 ? 0 : v63 + 0x8000) - ((v63 - 0x7FFF) & ((v63 <= 0x7FFF) - 1));
        out = (__int16 *)((char *)out + v60);
      }
      while ( v47 < v44 );
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
    v66 = &v50[v65];
    v67 = &v50[2 * v21];
    if ( v67 < v66 )
    {
      if ( ((char *)v66 - (char *)v67 + 7) / 8 < 4 )
      {
        v68 = step;
      }
      else
      {
        v68 = step;
        v69 = step;
        do
        {
          *out = (int)(float)(*v67 * -0.001953125)
               - ((int)(float)(*v67 * -0.001953125) >= -32768 ? 0 : (int)(float)(*v67 * -0.001953125) + 0x8000)
               - (((int)(float)(*v67 * -0.001953125) - 0x7FFF) & (((int)(float)(*v67 * -0.001953125) <= 0x7FFF) - 1));
          v70 = &out[v69];
          v71 = (int)(float)(v67[2] * -0.001953125);
          *v70 = v71 - (v71 >= -32768 ? 0 : v71 + 0x8000) - ((v71 - 0x7FFF) & ((v71 <= 0x7FFF) - 1));
          v72 = &v70[v69];
          v73 = (int)(float)(v67[4] * -0.001953125);
          *v72 = v73 - (v73 >= -32768 ? 0 : v73 + 0x8000) - ((v73 - 0x7FFF) & ((v73 <= 0x7FFF) - 1));
          v74 = &v72[v69];
          v75 = v67[6] * -0.001953125;
          *v74 = (int)v75
               - ((int)v75 >= -32768 ? 0 : (int)v75 + 0x8000)
               - (((int)v75 - 0x7FFF) & (((int)v75 <= 0x7FFF) - 1));
          out = &v74[v69];
          v67 += 8;
        }
        while ( (__int64)v67 < (__int64)(v66 - 6) );
      }
      for ( ; v67 < v66; out += v68 )
      {
        v76 = *v67 * -0.001953125;
        v67 += 2;
        *out = (int)v76
             - ((int)v76 >= -32768 ? 0 : (int)v76 + 0x8000)
             - (((int)v76 - 0x7FFF) & (((int)v76 <= 0x7FFF) - 1));
      }
    }
  }
}

