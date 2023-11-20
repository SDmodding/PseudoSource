// File Line: 31
// RVA: 0x1457520
__int64 dynamic_initializer_for__gTaskFunctionDecl_UpdateFogTask__()
{
  UFG::qTaskFunctionDecl::qTaskFunctionDecl(&gTaskFunctionDecl_UpdateFogTask, &gTaskFunctionDeclData_UpdateFogTask);
  return atexit(dynamic_atexit_destructor_for__gTaskFunctionDecl_UpdateFogTask__);
}

// File Line: 435
// RVA: 0x7ABE0
void __fastcall UpdateFogTask(int workerId, UFG::qMemoryStreamer *memory_streamer, void *param_stream, void *pad0, void *pad2)
{
  __int64 v5; // rcx
  int v6; // er12
  void *v7; // r13
  __m128 v8; // xmm7
  __m128 v9; // xmm8
  int v10; // xmm5_4
  float v11; // xmm0_4
  unsigned int v12; // xmm12_4
  unsigned int v13; // xmm13_4
  float v14; // xmm11_4
  __int64 v15; // rax
  __m128 v16; // xmm14
  int v17; // xmm15_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  int v20; // xmm0_4
  float v21; // xmm0_4
  unsigned int v22; // xmm3_4
  float v23; // xmm2_4
  unsigned int v24; // xmm1_4
  __m128 v25; // xmm1
  __int128 v26; // xmm0
  __m128i v27; // xmm6
  __m128 v28; // xmm9
  __m128 v29; // xmm0
  __m128 v30; // xmm10
  volatile int *v31; // rcx
  unsigned int v32; // edi
  float v33; // xmm12_4
  __m128 v34; // xmm11
  float v35; // xmm13_4
  bool v36; // r14
  int v37; // xmm0_4
  __m128 *v38; // rbx
  __m128 *v39; // rdx
  unsigned __int64 v40; // rsi
  __m128 v41; // xmm2
  __m128 v42; // xmm0
  float v43; // xmm0_4
  __m128 v44; // xmm5
  __m128 *v45; // rdi
  __int128 *v46; // rax
  bool v47; // zf
  __m128 v48; // xmm9
  signed __int64 v49; // rcx
  signed __int64 v50; // rax
  __m128i v51; // xmm6
  __m128i v52; // xmm6
  __m128 v53; // xmm15
  __m128 v54; // xmm11
  __m128 v55; // xmm12
  __m128 v56; // xmm3
  __m128 v57; // xmm2
  __m128 v58; // xmm6
  __m128 v59; // xmm10
  __m128 v60; // xmm13
  __m128 v61; // xmm8
  signed __int64 v62; // r14
  signed __int64 v63; // r15
  __m128 v64; // xmm4
  __m128 v65; // xmm0
  __m128 v66; // xmm1
  __m128 v67; // xmm3
  __m128 v68; // xmm1
  __m128 v69; // xmm2
  __m128 v70; // xmm4
  __m128 v71; // xmm1
  __m128 v72; // xmm3
  __m128 v73; // xmm0
  __m128 v74; // xmm2
  __m128 v75; // xmm13
  __m128 v76; // xmm11
  __m128 v77; // xmm12
  __m128 v78; // xmm12
  __m128 v79; // xmm1
  __m128 v80; // xmm12
  __m128 v81; // xmm12
  __m128 v82; // xmm1
  __m128 v83; // xmm10
  __m128 v84; // xmm10
  __m128 v85; // xmm1
  __m128 v86; // xmm12
  __m128 v87; // xmm1
  __m128 v88; // xmm10
  __m128 v89; // xmm10
  __m128 v90; // xmm0
  __m128 v91; // xmm10
  __m128 v92; // xmm9
  __m128 v93; // xmm8
  __m128 v94; // xmm0
  __m128 v95; // xmm7
  __m128 v96; // xmm0
  __m128 v97; // xmm6
  __m128 v98; // xmm0
  __m128 v99; // xmm8
  __m128 v100; // xmm0
  __m128 v101; // xmm9
  __m128 v102; // xmm11
  __m128 v103; // xmm8
  __m128 v104; // xmm0
  __m128 v105; // xmm7
  __m128 v106; // xmm0
  __m128 v107; // xmm6
  __m128 v108; // xmm0
  __m128 v109; // xmm9
  __m128 v110; // xmm2
  __m128 v111; // xmm3
  __m128 v112; // xmm2
  __m128 v113; // xmm4
  __m128 v114; // xmm1
  __m128 v115; // xmm1
  __m128 v116; // xmm0
  __m128 v117; // xmm1
  __m128 v118; // xmm15
  __m128 v119; // xmm15
  __m128 v120; // xmm15
  __m128 v121; // xmm4
  __m128 v122; // xmm1
  __m128 v123; // xmm5
  __m128 v124; // xmm2
  __m128 v125; // xmm3
  __m128 v126; // xmm1
  __m128 v127; // xmm13
  __m128 v128; // xmm0
  __m128 v129; // xmm4
  __m128 v130; // xmm12
  __m128 v131; // xmm2
  __m128 v132; // xmm2
  __m128 v133; // xmm11
  __m128 v134; // xmm11
  __m128 v135; // xmm1
  __m128 v136; // xmm10
  __m128 v137; // xmm10
  __m128 v138; // xmm1
  __m128 v139; // xmm11
  __m128 v140; // xmm1
  __m128 v141; // xmm10
  __m128 v142; // xmm10
  __m128 v143; // xmm0
  __m128 v144; // xmm10
  __m128 v145; // xmm9
  __m128 v146; // xmm8
  __m128 v147; // xmm0
  __m128 v148; // xmm7
  __m128 v149; // xmm0
  __m128 v150; // xmm6
  __m128 v151; // xmm0
  __m128 v152; // xmm7
  __m128 v153; // xmm0
  __m128 v154; // xmm12
  __m128 v155; // xmm9
  __m128 v156; // xmm8
  __m128 v157; // xmm0
  __m128 v158; // xmm7
  __m128 v159; // xmm0
  __m128 v160; // xmm6
  __m128 v161; // xmm0
  __m128 v162; // xmm8
  __m128 v163; // xmm8
  __m128 v164; // xmm9
  __m128 v165; // xmm3
  __m128 v166; // xmm3
  __m128 v167; // xmm3
  __m128 v168; // xmm1
  __m128 v169; // xmm1
  __m128 v170; // xmm0
  __m128i v171; // xmm1
  __m128i v172; // xmm1
  __m128 v173; // xmm2
  __m128 v174; // xmm2
  __m128i v175; // xmm0
  __m128i v176; // xmm0
  float v177; // [rsp+20h] [rbp-C0h]
  float v178; // [rsp+24h] [rbp-BCh]
  float v179; // [rsp+28h] [rbp-B8h]
  int v180; // [rsp+2Ch] [rbp-B4h]
  float v181; // [rsp+30h] [rbp-B0h]
  int v182; // [rsp+34h] [rbp-ACh]
  float v183; // [rsp+38h] [rbp-A8h]
  float v184; // [rsp+3Ch] [rbp-A4h]
  __m128 v185; // [rsp+40h] [rbp-A0h]
  __m128 v186; // [rsp+50h] [rbp-90h]
  __m128 v187; // [rsp+60h] [rbp-80h]
  __m128 v188; // [rsp+70h] [rbp-70h]
  __m128 v189; // [rsp+80h] [rbp-60h]
  __m128 v190; // [rsp+90h] [rbp-50h]
  __m128 v191; // [rsp+A0h] [rbp-40h]
  __m128 v192; // [rsp+B0h] [rbp-30h]
  int v193; // [rsp+C0h] [rbp-20h]
  int v194; // [rsp+C4h] [rbp-1Ch]
  int v195; // [rsp+C8h] [rbp-18h]
  int v196; // [rsp+CCh] [rbp-14h]
  __m128 v197; // [rsp+D0h] [rbp-10h]
  __m128 v198; // [rsp+E0h] [rbp+0h]
  __m128 v199; // [rsp+F0h] [rbp+10h]
  __m128 v200; // [rsp+100h] [rbp+20h]
  __m128 v201; // [rsp+110h] [rbp+30h]
  __m128 v202; // [rsp+120h] [rbp+40h]
  __m128 v203; // [rsp+130h] [rbp+50h]
  __m128 v204; // [rsp+140h] [rbp+60h]
  __m128 v205; // [rsp+150h] [rbp+70h]
  __m128 v206; // [rsp+160h] [rbp+80h]
  __m128 v207; // [rsp+170h] [rbp+90h]
  __int128 v208; // [rsp+180h] [rbp+A0h]
  __m128 v209; // [rsp+190h] [rbp+B0h]
  __m128 v210; // [rsp+1A0h] [rbp+C0h]
  __m128 v211; // [rsp+1B0h] [rbp+D0h]
  __m128 v212; // [rsp+1C0h] [rbp+E0h]
  __m128 v213; // [rsp+1D0h] [rbp+F0h]
  __m128 v214; // [rsp+1E0h] [rbp+100h]
  __m128 v215; // [rsp+1F0h] [rbp+110h]
  __m128 v216; // [rsp+200h] [rbp+120h]
  __m128 v217; // [rsp+210h] [rbp+130h]
  __m128 v218; // [rsp+220h] [rbp+140h]
  __m128 v219; // [rsp+230h] [rbp+150h]
  __m128 v220; // [rsp+240h] [rbp+160h]
  __int128 v221; // [rsp+250h] [rbp+170h]
  __m128 v222; // [rsp+260h] [rbp+180h]
  __int128 v223; // [rsp+270h] [rbp+190h]
  __m128 v224; // [rsp+280h] [rbp+1A0h]
  __m128 v225; // [rsp+290h] [rbp+1B0h]
  __m128 v226; // [rsp+2A0h] [rbp+1C0h]
  __m128 v227; // [rsp+2B0h] [rbp+1D0h]
  __m128 v228; // [rsp+2C0h] [rbp+1E0h]
  __int128 v229; // [rsp+2D0h] [rbp+1F0h]
  __m128 v230; // [rsp+2E0h] [rbp+200h]
  __m128 v231; // [rsp+2F0h] [rbp+210h]
  __m128 v232; // [rsp+300h] [rbp+220h]
  __m128 v233; // [rsp+320h] [rbp+240h]
  __m128 v234; // [rsp+330h] [rbp+250h]
  __int128 v235; // [rsp+350h] [rbp+270h]
  __m128 v236; // [rsp+360h] [rbp+280h]
  float vars0; // [rsp+450h] [rbp+370h]

  v5 = *((_QWORD *)param_stream + 3);
  v6 = 0;
  v7 = param_stream;
  v189.m128_u64[1] = 0i64;
  v8 = (__m128)_xmm;
  v9 = *(__m128 *)(v5 + 16);
  v10 = *(_DWORD *)(v5 + 244);
  v179 = *(float *)(v5 + 168);
  v11 = *(float *)(v5 + 164) - *(float *)(v5 + 160);
  v181 = *(float *)(v5 + 160);
  v197.m128_i32[0] = *(_DWORD *)(v5 + 240);
  v12 = *(_DWORD *)(v5 + 72);
  v13 = *(_DWORD *)(v5 + 76);
  v14 = *(float *)(v5 + 252);
  v221 = *(_OWORD *)_xmm;
  v15 = *((_QWORD *)param_stream + 2);
  v16 = 0i64;
  v17 = _xmm[0];
  v184 = v11 * 0.03125;
  v18 = *(float *)(v5 + 64);
  v229 = 0i64;
  v236 = v9;
  v19 = *(float *)(v15 + 12);
  vars0 = v18;
  v180 = *(_DWORD *)(v5 + 68);
  v20 = *(_DWORD *)(v5 + 228);
  *(unsigned __int64 *)((char *)v197.m128_u64 + 4) = __PAIR__(v197.m128_u32[0], v10);
  v182 = v20;
  v178 = *(float *)(v5 + 248);
  v21 = *(float *)(v5 + 220);
  v197.m128_i32[3] = v10;
  v177 = v21;
  *(float *)&v22 = v19 / (float)(v19 - *(float *)(v15 + 8));
  v190.m128_i32[0] = *(_DWORD *)v15;
  v223 = *(_OWORD *)_xmm_bf800000bf800000bf800000bf800000;
  v23 = *(float *)&v22 / v19;
  v24 = *(_DWORD *)(v15 + 4);
  v192 = _mm_shuffle_ps((__m128)*((unsigned int *)param_stream + 14), (__m128)*((unsigned int *)param_stream + 14), 0);
  *(unsigned __int64 *)((char *)v190.m128_u64 + 4) = __PAIR__(v22, v24);
  v25 = *(__m128 *)(v5 + 80);
  v214 = *(__m128 *)param_stream;
  v207 = *(__m128 *)(v5 + 96);
  v26 = *(_OWORD *)(v5 + 112);
  v218 = v25;
  v190.m128_i32[3] = LODWORD(v23) ^ _xmm[0];
  v189.m128_u64[0] = (unsigned int)(LODWORD(v23) ^ _xmm[0]);
  v27 = (__m128i)_xmm;
  v28 = (__m128)(unsigned int)FLOAT_1_0;
  v235 = v26;
  v196 = 1065353216;
  v29 = *(__m128 *)(v5 + 128);
  _mm_store_si128((__m128i *)&v208, (__m128i)_xmm);
  v30 = _mm_shuffle_ps(v25, v25, 255);
  v194 = *(_DWORD *)(v5 + 232);
  v200 = v29;
  v198 = v30;
  v216 = (__m128)gVmxAbsMask_0;
  v193 = *(_DWORD *)(v5 + 192);
  v29.m128_i32[0] = *(_DWORD *)(v5 + 236);
  v31 = (volatile int *)*((_QWORD *)param_stream + 5);
  v195 = v29.m128_i32[0];
  v32 = UFG::qAtomicAdd(v31, 1) - 1;
  if ( v32 < *((_DWORD *)v7 + 16) )
  {
    v186.m128_f32[0] = vars0;
    v186.m128_u64[1] = __PAIR__(v13, v12);
    v33 = 1.0 / (float)(v14 - v178);
    v34 = (__m128)LODWORD(v179);
    v35 = vars0;
    v185.m128_f32[2] = v179;
    v183 = v33;
    v185.m128_i32[1] = COERCE_UNSIGNED_INT(v179 * vars0) ^ _xmm[0];
    v187.m128_u64[1] = 0i64;
    v187.m128_i32[1] = expf(COERCE_FLOAT(COERCE_UNSIGNED_INT((float)(v179 * vars0) * v177) ^ _xmm[0]));
    do
    {
      v36 = v32 == 31;
      if ( v32 == 31 )
        v37 = v182;
      else
        v37 = v180;
      v38 = &v192;
      v39 = &v234;
      v186.m128_i32[1] = v37;
      if ( !v36 )
        v38 = (__m128 *)&v223;
      if ( !v6 )
        v39 = &v232;
      v40 = *((_QWORD *)v7 + 4) + (v32 << 12);
      v39->m128_u64[1] = v40;
      if ( v36 )
      {
        v41 = v34;
      }
      else
      {
        v41 = 0i64;
        v41.m128_f32[0] = (float)(signed int)v32 * v184;
      }
      v42 = v41;
      v42.m128_f32[0] = (float)((float)(v41.m128_f32[0] + v181) - v178) * v33;
      if ( v42.m128_f32[0] <= 0.0 )
      {
        v42 = 0i64;
      }
      else if ( v42.m128_f32[0] >= v28.m128_f32[0] )
      {
        v42 = v28;
      }
      v185.m128_i32[3] = v41.m128_i32[0];
      v191 = _mm_shuffle_ps(v42, v42, 0);
      v185.m128_i32[0] = COERCE_UNSIGNED_INT(v41.m128_f32[0] * v35) ^ v17;
      v43 = expf(COERCE_FLOAT(COERCE_UNSIGNED_INT((float)(v41.m128_f32[0] * v35) * v177) ^ v17));
      v44 = (__m128)_xmm;
      v45 = (__m128 *)&v193;
      v188 = (__m128)_xmm;
      v187.m128_f32[0] = v43;
      if ( !v36 )
        v45 = (__m128 *)&v235;
      v46 = &v221;
      if ( !v36 )
        v46 = &v229;
      v47 = *((_DWORD *)v7 + 18) == 0;
      v48 = _mm_add_ps(_mm_mul_ps((__m128)*v46, v16), v16);
      v202 = v48;
      if ( v47 )
      {
        v53 = _mm_sub_ps(v218, v207);
        v54 = _mm_shuffle_ps(v9, v9, 85);
        v55 = _mm_shuffle_ps(v9, v9, 170);
        v233 = _mm_shuffle_ps(
                 (__m128)_xmm_b92951de3c0658eebe2a84b53f800000,
                 (__m128)_xmm_b92951de3c0658eebe2a84b53f800000,
                 170);
        v56 = _mm_shuffle_ps(
                (__m128)_xmm_b92951de3c0658eebe2a84b53f800000,
                (__m128)_xmm_b92951de3c0658eebe2a84b53f800000,
                85);
        v57 = _mm_shuffle_ps(
                (__m128)_xmm_b92951de3c0658eebe2a84b53f800000,
                (__m128)_xmm_b92951de3c0658eebe2a84b53f800000,
                255);
        v201 = v54;
        v203 = v55;
        v206 = v53;
        v225 = _mm_shuffle_ps(
                 (__m128)_xmm_ba72600c3d1eda81befd9e413f800000,
                 (__m128)_xmm_ba72600c3d1eda81befd9e413f800000,
                 85);
        v215 = v56;
        v231 = _mm_shuffle_ps(
                 (__m128)_xmm_ba72600c3d1eda81befd9e413f800000,
                 (__m128)_xmm_ba72600c3d1eda81befd9e413f800000,
                 0);
        v213 = v57;
        v58 = _mm_shuffle_ps(
                (__m128)_xmm_ba72600c3d1eda81befd9e413f800000,
                (__m128)_xmm_ba72600c3d1eda81befd9e413f800000,
                255);
        v227 = _mm_shuffle_ps(
                 (__m128)_xmm_ba72600c3d1eda81befd9e413f800000,
                 (__m128)_xmm_ba72600c3d1eda81befd9e413f800000,
                 170);
        v211 = v58;
        v219 = _mm_rcp_ps(_mm_sub_ps(*(__m128 *)_xmm, v30));
        v220 = v56;
        v224 = v57;
        v222 = v233;
        v226 = v225;
        v228 = v231;
        v232 = v58;
        v230 = v227;
        v59 = _mm_shuffle_ps(v9, v9, 0);
        v234 = v219;
        v217 = _mm_shuffle_ps(v197, v197, 85);
        v60 = _mm_shuffle_ps(v197, v197, 0);
        v61 = _mm_shuffle_ps(v186, v186, 85);
        v212 = _mm_shuffle_ps(v186, v186, 255);
        v199 = v59;
        v205 = v60;
        v204 = v61;
        v209 = _mm_shuffle_ps(v200, v200, 255);
        v210 = _mm_shuffle_ps(v185, v185, 255);
        v62 = 32i64;
        do
        {
          v63 = 16i64;
          do
          {
            v64 = _mm_add_ps(_mm_mul_ps(v44, v44), v16);
            v65 = _mm_add_ps(_mm_mul_ps(v64, v44), v16);
            v66 = _mm_add_ps(_mm_mul_ps(v65, v64), v16);
            v67 = _mm_add_ps(
                    _mm_add_ps(_mm_add_ps(_mm_mul_ps(v56, v65), v44), _mm_mul_ps(v233, v66)),
                    _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v66, v64), v16), v57));
            v68 = _mm_add_ps(_mm_mul_ps(v64, v64), v16);
            v69 = _mm_add_ps(
                    _mm_add_ps(_mm_add_ps(_mm_mul_ps(v225, v64), v231), _mm_mul_ps(v227, v68)),
                    _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v68, v64), v16), v58));
            v70 = _mm_add_ps(
                    _mm_mul_ps(
                      _mm_shuffle_ps(v67, _mm_shuffle_ps(v69, v67, 240), 64),
                      _mm_shuffle_ps(_mm_shuffle_ps(v69, v67, 85), v69, 249)),
                    v16);
            v71 = _mm_shuffle_ps(v70, v70, 170);
            v72 = _mm_min_ps(
                    _mm_max_ps(_mm_add_ps(_mm_mul_ps(_mm_sub_ps(_mm_shuffle_ps(v44, v44, 0), v198), v219), v16), v16),
                    *(__m128 *)_xmm);
            v73 = _mm_cmpltps(v71, *v38);
            v74 = _mm_add_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v70, v70, 0), v59), v16),
                          _mm_mul_ps(_mm_shuffle_ps(v70, v70, 85), v54)),
                        _mm_mul_ps(v55, v71)),
                      v60),
                    v217);
            v75 = _mm_add_ps(_mm_mul_ps(v210, v70), v214);
            v76 = _mm_or_ps(_mm_and_ps(v73, v16), _mm_andnot_ps(v73, v185));
            v77 = _mm_shuffle_ps(_mm_min_ps(_mm_shuffle_ps(v76, v76, 255), _mm_shuffle_ps(v76, v76, 170)), v76, 160);
            v78 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v77, v77, 153), v71), v16);
            v79 = v78;
            v80 = _mm_add_ps(
                    _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v78, v61), (__m128)_xmm), (__m128)`FogFunction::`2::neg_z),
                    (__m128)0i64);
            v81 = _mm_shuffle_ps(
                    v80,
                    _mm_shuffle_ps(
                      v80,
                      _mm_min_ps(_mm_max_ps(_mm_add_ps(_mm_mul_ps(v79, v212), v16), v16), *(__m128 *)_xmm),
                      10),
                    148);
            v82 = _mm_min_ps(_mm_max_ps(v81, (__m128)0i64), *(__m128 *)_xmm);
            v83 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v82, v82, 0), v53), v207);
            v84 = _mm_add_ps(v83, _mm_mul_ps(_mm_shuffle_ps(v82, v82, 170), _mm_sub_ps(*v45, v83)));
            v85 = _mm_shuffle_ps(v81, v81, 85);
            v86 = _mm_shuffle_ps(v81, v81, 255);
            v87 = _mm_add_ps(_mm_mul_ps(v85, v53), v207);
            v88 = _mm_add_ps(v84, _mm_mul_ps(_mm_sub_ps(v87, v84), v86));
            v89 = _mm_add_ps(v88, _mm_mul_ps(_mm_sub_ps(v87, v88), v48));
            v90 = (__m128)LODWORD(FLOAT_2_0);
            v91 = _mm_add_ps(
                    v89,
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_mul_ps(
                          _mm_add_ps(
                            _mm_mul_ps(
                              _mm_min_ps(
                                _mm_max_ps(
                                  _mm_add_ps(
                                    _mm_mul_ps(
                                      _mm_add_ps(_mm_mul_ps(_mm_and_ps(v74, v216), v74), (__m128)0i64),
                                      _mm_add_ps(_mm_mul_ps(v72, v72), (__m128)0i64)),
                                    (__m128)0i64),
                                  (__m128)0i64),
                                *(__m128 *)_xmm),
                              v209),
                            (__m128)0i64),
                          v191),
                        (__m128)0i64),
                      _mm_sub_ps(v200, v89)));
            v92 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v76, v76, 0), v91), (__m128)0i64);
            v90.m128_f32[0] = powf(2.0, v92.m128_f32[0]);
            v93 = v90;
            v94 = (__m128)LODWORD(FLOAT_2_0);
            v94.m128_f32[0] = powf(2.0, COERCE_FLOAT(_mm_shuffle_ps(v92, v92, 85)));
            v95 = v94;
            v96 = (__m128)LODWORD(FLOAT_2_0);
            v96.m128_f32[0] = powf(2.0, COERCE_FLOAT(_mm_shuffle_ps(v92, v92, 170)));
            v97 = v96;
            v98 = (__m128)LODWORD(FLOAT_2_0);
            v98.m128_f32[0] = powf(2.0, COERCE_FLOAT(_mm_shuffle_ps(v92, v92, 255)));
            v99 = _mm_unpacklo_ps(_mm_unpacklo_ps(v93, v97), _mm_unpacklo_ps(v95, v98));
            v100 = (__m128)LODWORD(FLOAT_2_0);
            v101 = _mm_sub_ps(*(__m128 *)_xmm, v99);
            v102 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v76, v76, 85), v91), (__m128)0i64);
            v100.m128_f32[0] = powf(2.0, v102.m128_f32[0]);
            v103 = v100;
            v104 = (__m128)LODWORD(FLOAT_2_0);
            v104.m128_f32[0] = powf(2.0, COERCE_FLOAT(_mm_shuffle_ps(v102, v102, 85)));
            v105 = v104;
            v106 = (__m128)LODWORD(FLOAT_2_0);
            v106.m128_f32[0] = powf(2.0, COERCE_FLOAT(_mm_shuffle_ps(v102, v102, 170)));
            v107 = v106;
            v108 = (__m128)LODWORD(FLOAT_2_0);
            v108.m128_f32[0] = powf(2.0, COERCE_FLOAT(_mm_shuffle_ps(v102, v102, 255)));
            v109 = _mm_shuffle_ps(v101, _mm_shuffle_ps(v101, v187, 10), 148);
            v110 = _mm_sub_ps(
                     *(__m128 *)_xmm,
                     _mm_unpacklo_ps(_mm_unpacklo_ps(v103, v107), _mm_unpacklo_ps(v105, v108)));
            v188 = _mm_add_ps(_mm_mul_ps(v188, *(__m128 *)_xmm), (__m128)_xmm);
            v111 = _mm_add_ps(_mm_mul_ps(v188, v188), (__m128)0i64);
            v112 = _mm_add_ps(
                     _mm_mul_ps(_mm_sub_ps(_mm_shuffle_ps(v110, _mm_shuffle_ps(v110, v187, 90), 148), v109), v86),
                     v109);
            v113 = _mm_add_ps(_mm_mul_ps(v111, v188), (__m128)0i64);
            v114 = _mm_sub_ps(v190, v75);
            v115 = _mm_add_ps(_mm_mul_ps(v114, v114), (__m128)0i64);
            v116 = _mm_add_ps(_mm_shuffle_ps(v115, v115, 85), v115);
            v117 = _mm_add_ps(_mm_mul_ps(v113, v111), (__m128)0i64);
            v118 = _mm_min_ps(
                     _mm_max_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_add_ps(_mm_mul_ps(_mm_rsqrt_ps(v116), v116), (__m128)0i64), v189),
                         v187),
                       v188),
                     *(__m128 *)_xmm);
            v119 = _mm_shuffle_ps(v118, v118, 0);
            v120 = _mm_min_ps(
                     _mm_max_ps(
                       _mm_add_ps(
                         _mm_mul_ps(
                           _mm_shuffle_ps(v119, _mm_shuffle_ps(v119, *(__m128 *)_xmm, 250), 148),
                           _mm_shuffle_ps(v112, _mm_shuffle_ps(v112, _mm_sub_ps(*(__m128 *)_xmm, v112), 250), 148)),
                         (__m128)0i64),
                       (__m128)0i64),
                     *(__m128 *)_xmm);
            v16 = 0i64;
            v121 = _mm_add_ps(
                     _mm_add_ps(_mm_add_ps(_mm_mul_ps(v113, v220), v188), _mm_mul_ps(v117, v222)),
                     _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v117, v111), (__m128)0i64), v224));
            v122 = _mm_add_ps(_mm_mul_ps(v111, v111), (__m128)0i64);
            v123 = _mm_min_ps(
                     _mm_max_ps(
                       _mm_add_ps(_mm_mul_ps(_mm_sub_ps(_mm_shuffle_ps(v188, v188, 0), v198), v234), (__m128)0i64),
                       (__m128)0i64),
                     *(__m128 *)_xmm);
            v124 = _mm_add_ps(
                     _mm_add_ps(_mm_add_ps(_mm_mul_ps(v111, v226), v228), _mm_mul_ps(v122, v230)),
                     _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v122, v111), (__m128)0i64), v232));
            v125 = _mm_add_ps(
                     _mm_mul_ps(
                       _mm_shuffle_ps(v121, _mm_shuffle_ps(v124, v121, 240), 64),
                       _mm_shuffle_ps(_mm_shuffle_ps(v124, v121, 85), v124, 249)),
                     (__m128)0i64);
            v126 = _mm_shuffle_ps(v125, v125, 170);
            v127 = _mm_add_ps(_mm_mul_ps(v210, v125), v214);
            v128 = _mm_cmpltps(v126, *v38);
            v129 = _mm_add_ps(
                     _mm_mul_ps(
                       _mm_add_ps(
                         _mm_add_ps(
                           _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v125, v125, 0), v199), (__m128)0i64),
                           _mm_mul_ps(_mm_shuffle_ps(v125, v125, 85), v201)),
                         _mm_mul_ps(v203, v126)),
                       v205),
                     v217);
            v130 = _mm_or_ps(_mm_andnot_ps(v128, v185), _mm_and_ps(v128, (__m128)0i64));
            v131 = _mm_shuffle_ps(
                     _mm_min_ps(_mm_shuffle_ps(v130, v130, 255), _mm_shuffle_ps(v130, v130, 170)),
                     v130,
                     160);
            v132 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v131, v131, 153), v126), (__m128)0i64);
            v133 = _mm_add_ps(
                     _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v204, v132), (__m128)_xmm), (__m128)`FogFunction::`2::neg_z),
                     (__m128)0i64);
            v134 = _mm_shuffle_ps(
                     v133,
                     _mm_shuffle_ps(
                       v133,
                       _mm_min_ps(
                         _mm_max_ps(_mm_add_ps(_mm_mul_ps(v212, v132), (__m128)0i64), (__m128)0i64),
                         *(__m128 *)_xmm),
                       10),
                     148);
            v135 = _mm_min_ps(_mm_max_ps(v134, (__m128)0i64), *(__m128 *)_xmm);
            v136 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v135, v135, 0), v206), v207);
            v137 = _mm_add_ps(v136, _mm_mul_ps(_mm_shuffle_ps(v135, v135, 170), _mm_sub_ps(*v45, v136)));
            v138 = _mm_shuffle_ps(v134, v134, 85);
            v139 = _mm_shuffle_ps(v134, v134, 255);
            v140 = _mm_add_ps(_mm_mul_ps(v138, v206), v207);
            v141 = _mm_add_ps(v137, _mm_mul_ps(_mm_sub_ps(v140, v137), v139));
            v142 = _mm_add_ps(v141, _mm_mul_ps(_mm_sub_ps(v140, v141), v202));
            v143 = (__m128)LODWORD(FLOAT_2_0);
            v144 = _mm_add_ps(
                     v142,
                     _mm_mul_ps(
                       _mm_add_ps(
                         _mm_mul_ps(
                           _mm_add_ps(
                             _mm_mul_ps(
                               _mm_min_ps(
                                 _mm_max_ps(
                                   _mm_add_ps(
                                     _mm_mul_ps(
                                       _mm_add_ps(_mm_mul_ps(_mm_and_ps(v129, v216), v129), (__m128)0i64),
                                       _mm_add_ps(_mm_mul_ps(v123, v123), (__m128)0i64)),
                                     (__m128)0i64),
                                   (__m128)0i64),
                                 *(__m128 *)_xmm),
                               v209),
                             (__m128)0i64),
                           v191),
                         (__m128)0i64),
                       _mm_sub_ps(v200, v142)));
            v145 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v130, v130, 0), v144), (__m128)0i64);
            v143.m128_f32[0] = powf(2.0, v145.m128_f32[0]);
            v146 = v143;
            v147 = (__m128)LODWORD(FLOAT_2_0);
            v147.m128_f32[0] = powf(2.0, COERCE_FLOAT(_mm_shuffle_ps(v145, v145, 85)));
            v148 = v147;
            v149 = (__m128)LODWORD(FLOAT_2_0);
            v149.m128_f32[0] = powf(2.0, COERCE_FLOAT(_mm_shuffle_ps(v145, v145, 170)));
            v150 = v149;
            v151 = (__m128)LODWORD(FLOAT_2_0);
            v151.m128_f32[0] = powf(2.0, COERCE_FLOAT(_mm_shuffle_ps(v145, v145, 255)));
            v152 = _mm_unpacklo_ps(v148, v151);
            v153 = (__m128)LODWORD(FLOAT_2_0);
            v154 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v130, v130, 85), v144), (__m128)0i64);
            v155 = _mm_sub_ps(*(__m128 *)_xmm, _mm_unpacklo_ps(_mm_unpacklo_ps(v146, v150), v152));
            v153.m128_f32[0] = powf(2.0, v154.m128_f32[0]);
            v156 = v153;
            v157 = (__m128)LODWORD(FLOAT_2_0);
            v157.m128_f32[0] = powf(2.0, COERCE_FLOAT(_mm_shuffle_ps(v154, v154, 85)));
            v158 = v157;
            v159 = (__m128)LODWORD(FLOAT_2_0);
            v159.m128_f32[0] = powf(2.0, COERCE_FLOAT(_mm_shuffle_ps(v154, v154, 170)));
            v160 = v159;
            v161 = (__m128)LODWORD(FLOAT_2_0);
            v161.m128_f32[0] = powf(2.0, COERCE_FLOAT(_mm_shuffle_ps(v154, v154, 255)));
            v162 = _mm_unpacklo_ps(v156, v160);
            v40 += 8i64;
            --v63;
            v58 = v211;
            v163 = _mm_unpacklo_ps(v162, _mm_unpacklo_ps(v158, v161));
            v8 = (__m128)_xmm;
            v59 = v199;
            v44 = v188;
            v164 = _mm_shuffle_ps(v155, _mm_shuffle_ps(v155, v187, 10), 148);
            v165 = _mm_sub_ps(*(__m128 *)_xmm, v163);
            v61 = v204;
            v166 = _mm_mul_ps(_mm_sub_ps(_mm_shuffle_ps(v165, _mm_shuffle_ps(v165, v187, 90), 148), v164), v139);
            v54 = v201;
            v167 = _mm_add_ps(v166, v164);
            v48 = v202;
            v168 = _mm_sub_ps(v190, v127);
            v169 = _mm_add_ps(_mm_mul_ps(v168, v168), (__m128)0i64);
            v170 = _mm_add_ps(_mm_shuffle_ps(v169, v169, 85), v169);
            v171 = _mm_cvtps_epi32(_mm_add_ps(_mm_mul_ps(v120, (__m128)_xmm), (__m128)0i64));
            v53 = v206;
            v172 = _mm_packs_epi32(v171, v171);
            *(_DWORD *)(v40 - 8) = (unsigned __int128)_mm_packus_epi16(v172, v172);
            v173 = _mm_min_ps(
                     _mm_max_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_add_ps(_mm_mul_ps(_mm_rsqrt_ps(v170), v170), (__m128)0i64), v189),
                         v187),
                       v188),
                     *(__m128 *)_xmm);
            v174 = _mm_shuffle_ps(v173, v173, 0);
            v175 = _mm_cvtps_epi32(
                     _mm_add_ps(
                       _mm_mul_ps(
                         _mm_min_ps(
                           _mm_max_ps(
                             _mm_add_ps(
                               _mm_mul_ps(
                                 _mm_shuffle_ps(v174, _mm_shuffle_ps(v174, *(__m128 *)_xmm, 250), 148),
                                 _mm_shuffle_ps(v167, _mm_shuffle_ps(v167, _mm_sub_ps(*(__m128 *)_xmm, v167), 250), 148)),
                               (__m128)0i64),
                             (__m128)0i64),
                           *(__m128 *)_xmm),
                         (__m128)_xmm),
                       (__m128)0i64));
            v57 = v213;
            v176 = _mm_packs_epi32(v175, v175);
            *(_DWORD *)(v40 - 4) = (unsigned __int128)_mm_packus_epi16(v176, v176);
            v55 = v203;
            v60 = v205;
            v56 = v215;
          }
          while ( v63 );
          v44 = _mm_add_ps(_mm_mul_ps(v188, (__m128)_xmm), (__m128)_xmm);
          v188 = v44;
          --v62;
        }
        while ( v62 );
        v27 = _mm_load_si128((const __m128i *)&v208);
        v9 = v236;
        v30 = v198;
        v17 = _xmm[0];
        v33 = v183;
        v34 = (__m128)LODWORD(v179);
        v35 = vars0;
      }
      else
      {
        v49 = 32i64;
        do
        {
          v50 = 16i64;
          do
          {
            v40 += 8i64;
            v51 = _mm_cvtps_epi32((__m128)_mm_cvtps_epi32(
                                            _mm_add_ps(
                                              _mm_mul_ps(_mm_add_ps(_mm_mul_ps((__m128)v27, v8), v16), v8),
                                              v16)));
            v52 = _mm_packs_epi32(v51, v51);
            v27 = _mm_packus_epi16(v52, v52);
            *(_DWORD *)(v40 - 8) = v27.m128i_i32[0];
            *(_DWORD *)(v40 - 4) = v27.m128i_i32[0];
            --v50;
          }
          while ( v50 );
          _mm_store_si128((__m128i *)&v208, v27);
          --v49;
        }
        while ( v49 );
      }
      v6 ^= 1u;
      v28 = (__m128)(unsigned int)FLOAT_1_0;
      v32 = UFG::qAtomicAdd(*((volatile int **)v7 + 5), 1) - 1;
    }
    while ( v32 < *((_DWORD *)v7 + 16) );
  }
}

