// File Line: 31
// RVA: 0x1457520
__int64 dynamic_initializer_for__gTaskFunctionDecl_UpdateFogTask__()
{
  UFG::qTaskFunctionDecl::qTaskFunctionDecl(&gTaskFunctionDecl_UpdateFogTask, &gTaskFunctionDeclData_UpdateFogTask);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gTaskFunctionDecl_UpdateFogTask__);
}

// File Line: 435
// RVA: 0x7ABE0
void __fastcall UpdateFogTask(
        int workerId,
        UFG::qMemoryStreamer *memory_streamer,
        unsigned int *param_stream,
        void *pad0,
        void *pad2)
{
  __int64 v5; // rcx
  int v6; // r12d
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
  __m128 si128; // xmm6
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
  __int64 v49; // rcx
  __int64 v50; // rax
  __m128i v51; // xmm6
  __m128i v52; // xmm6
  __m128i v53; // xmm6
  __m128i v54; // xmm6
  __m128 v55; // xmm15
  __m128 v56; // xmm11
  __m128 v57; // xmm12
  __m128 v58; // xmm3
  __m128 v59; // xmm2
  __m128 v60; // xmm6
  __m128 v61; // xmm10
  __m128 v62; // xmm13
  __m128 v63; // xmm8
  __int64 v64; // r14
  __int64 v65; // r15
  __m128 v66; // xmm4
  __m128 v67; // xmm0
  __m128 v68; // xmm1
  __m128 v69; // xmm3
  __m128 v70; // xmm1
  __m128 v71; // xmm2
  __m128 v72; // xmm4
  __m128 v73; // xmm1
  __m128 v74; // xmm3
  __m128 v75; // xmm2
  __m128 v76; // xmm11
  __m128 v77; // xmm13
  __m128 v78; // xmm11
  __m128 v79; // xmm12
  __m128 v80; // xmm1
  __m128 v81; // xmm12
  __m128 v82; // xmm12
  __m128 v83; // xmm1
  __m128 v84; // xmm10
  __m128 v85; // xmm10
  __m128 v86; // xmm1
  __m128 v87; // xmm12
  __m128 v88; // xmm1
  __m128 v89; // xmm10
  __m128 v90; // xmm10
  __m128 v91; // xmm0
  __m128 v92; // xmm10
  __m128 v93; // xmm9
  __m128 v94; // xmm8
  __m128 v95; // xmm0
  __m128 v96; // xmm7
  __m128 v97; // xmm0
  __m128 v98; // xmm6
  __m128 v99; // xmm0
  __m128 v100; // xmm8
  __m128 v101; // xmm0
  __m128 v102; // xmm9
  __m128 v103; // xmm11
  __m128 v104; // xmm8
  __m128 v105; // xmm0
  __m128 v106; // xmm7
  __m128 v107; // xmm0
  __m128 v108; // xmm6
  __m128 v109; // xmm0
  __m128 v110; // xmm9
  __m128 v111; // xmm2
  __m128 v112; // xmm3
  __m128 v113; // xmm2
  __m128 v114; // xmm1
  __m128 v115; // xmm1
  __m128 v116; // xmm0
  __m128 v117; // xmm1
  __m128 v118; // xmm15
  __m128 v119; // xmm15
  __m128 v120; // xmm15
  __m128 v121; // xmm0
  __m128 v122; // xmm4
  __m128 v123; // xmm0
  __m128 v124; // xmm5
  __m128 v125; // xmm2
  __m128 v126; // xmm3
  __m128 v127; // xmm1
  __m128 v128; // xmm13
  __m128 v129; // xmm12
  __m128 v130; // xmm4
  __m128 v131; // xmm12
  __m128 v132; // xmm2
  __m128 v133; // xmm2
  __m128 v134; // xmm11
  __m128 v135; // xmm11
  __m128 v136; // xmm1
  __m128 v137; // xmm10
  __m128 v138; // xmm10
  __m128 v139; // xmm1
  __m128 v140; // xmm11
  __m128 v141; // xmm1
  __m128 v142; // xmm10
  __m128 v143; // xmm10
  __m128 v144; // xmm0
  __m128 v145; // xmm10
  __m128 v146; // xmm9
  __m128 v147; // xmm8
  __m128 v148; // xmm0
  __m128 v149; // xmm7
  __m128 v150; // xmm0
  __m128 v151; // xmm6
  __m128 v152; // xmm0
  __m128 v153; // xmm7
  __m128 v154; // xmm0
  __m128 v155; // xmm12
  __m128 v156; // xmm9
  __m128 v157; // xmm8
  __m128 v158; // xmm0
  __m128 v159; // xmm7
  __m128 v160; // xmm0
  __m128 v161; // xmm6
  __m128 v162; // xmm0
  __m128 v163; // xmm8
  __m128 v164; // xmm8
  __m128 v165; // xmm9
  __m128 v166; // xmm3
  __m128 v167; // xmm3
  __m128 v168; // xmm3
  __m128 v169; // xmm1
  __m128 v170; // xmm1
  __m128 v171; // xmm0
  __m128i v172; // xmm1
  __m128i v173; // xmm1
  __m128 v174; // xmm2
  __m128 v175; // xmm2
  __m128i v176; // xmm0
  __m128i v177; // xmm0
  float v178; // [rsp+20h] [rbp-C0h]
  float v179; // [rsp+24h] [rbp-BCh]
  float v180; // [rsp+28h] [rbp-B8h]
  int v181; // [rsp+2Ch] [rbp-B4h]
  float v182; // [rsp+30h] [rbp-B0h]
  int v183; // [rsp+34h] [rbp-ACh]
  float v184; // [rsp+38h] [rbp-A8h]
  float v185; // [rsp+3Ch] [rbp-A4h]
  __m128 v186; // [rsp+40h] [rbp-A0h]
  __m128 v187; // [rsp+50h] [rbp-90h]
  __m128 v188; // [rsp+60h] [rbp-80h]
  __m128 v189; // [rsp+70h] [rbp-70h]
  __m128 v190; // [rsp+70h] [rbp-70h]
  __m128 v191; // [rsp+80h] [rbp-60h]
  __m128 v192; // [rsp+90h] [rbp-50h]
  __m128 v193; // [rsp+A0h] [rbp-40h]
  __m128 v194; // [rsp+B0h] [rbp-30h] BYREF
  int v195[4]; // [rsp+C0h] [rbp-20h] BYREF
  __m128 v196; // [rsp+D0h] [rbp-10h]
  __m128 v197; // [rsp+E0h] [rbp+0h]
  __m128 v198; // [rsp+F0h] [rbp+10h]
  __m128 v199; // [rsp+100h] [rbp+20h]
  __m128 v200; // [rsp+110h] [rbp+30h]
  __m128 v201; // [rsp+120h] [rbp+40h]
  __m128 v202; // [rsp+130h] [rbp+50h]
  __m128 v203; // [rsp+140h] [rbp+60h]
  __m128 v204; // [rsp+150h] [rbp+70h]
  __m128 v205; // [rsp+160h] [rbp+80h]
  __m128 v206; // [rsp+170h] [rbp+90h]
  __int128 v207; // [rsp+180h] [rbp+A0h] BYREF
  __m128 v208; // [rsp+190h] [rbp+B0h]
  __m128 v209; // [rsp+1A0h] [rbp+C0h]
  __m128 v210; // [rsp+1B0h] [rbp+D0h]
  __m128 v211; // [rsp+1C0h] [rbp+E0h]
  __m128 v212; // [rsp+1D0h] [rbp+F0h]
  __m128 v213; // [rsp+1E0h] [rbp+100h]
  __m128 v214; // [rsp+1F0h] [rbp+110h]
  __m128 v215; // [rsp+200h] [rbp+120h]
  __m128 v216; // [rsp+210h] [rbp+130h]
  __m128 v217; // [rsp+220h] [rbp+140h]
  __m128 v218; // [rsp+230h] [rbp+150h]
  __m128 v219; // [rsp+240h] [rbp+160h]
  __int128 v220; // [rsp+250h] [rbp+170h] BYREF
  __m128 v221; // [rsp+260h] [rbp+180h]
  __int128 v222; // [rsp+270h] [rbp+190h] BYREF
  __m128 v223; // [rsp+280h] [rbp+1A0h]
  __m128 v224; // [rsp+290h] [rbp+1B0h]
  __m128 v225; // [rsp+2A0h] [rbp+1C0h]
  __m128 v226; // [rsp+2B0h] [rbp+1D0h]
  __m128 v227; // [rsp+2C0h] [rbp+1E0h]
  __int128 v228; // [rsp+2D0h] [rbp+1F0h] BYREF
  __m128 v229; // [rsp+2E0h] [rbp+200h]
  __m128 v230; // [rsp+2F0h] [rbp+210h]
  __m128 v231; // [rsp+300h] [rbp+220h] BYREF
  __m128 v232; // [rsp+320h] [rbp+240h]
  __m128 v233; // [rsp+330h] [rbp+250h] BYREF
  __int128 v234; // [rsp+350h] [rbp+270h] BYREF
  __m128 v235; // [rsp+360h] [rbp+280h]
  float vars0; // [rsp+450h] [rbp+370h]

  v5 = *((_QWORD *)param_stream + 3);
  v6 = 0;
  v8 = (__m128)_xmm;
  v9 = *(__m128 *)(v5 + 16);
  v10 = *(_DWORD *)(v5 + 244);
  v180 = *(float *)(v5 + 168);
  v11 = *(float *)(v5 + 164) - *(float *)(v5 + 160);
  v182 = *(float *)(v5 + 160);
  v196.m128_i32[0] = *(_DWORD *)(v5 + 240);
  v12 = *(_DWORD *)(v5 + 72);
  v13 = *(_DWORD *)(v5 + 76);
  v14 = *(float *)(v5 + 252);
  v220 = *(_OWORD *)_xmm;
  v15 = *((_QWORD *)param_stream + 2);
  v16 = 0i64;
  v17 = _xmm[0];
  v185 = v11 * 0.03125;
  v18 = *(float *)(v5 + 64);
  v228 = 0i64;
  v235 = v9;
  v19 = *(float *)(v15 + 12);
  vars0 = v18;
  v181 = *(_DWORD *)(v5 + 68);
  v20 = *(_DWORD *)(v5 + 228);
  *(unsigned __int64 *)((char *)v196.m128_u64 + 4) = __PAIR64__(v196.m128_u32[0], v10);
  v183 = v20;
  v179 = *(float *)(v5 + 248);
  v21 = *(float *)(v5 + 220);
  v196.m128_i32[3] = v10;
  v178 = v21;
  *(float *)&v22 = v19 / (float)(v19 - *(float *)(v15 + 8));
  v192.m128_i32[0] = *(_DWORD *)v15;
  v222 = *(_OWORD *)_xmm_bf800000bf800000bf800000bf800000;
  v23 = *(float *)&v22 / v19;
  v24 = *(_DWORD *)(v15 + 4);
  v194 = _mm_shuffle_ps((__m128)param_stream[14], (__m128)param_stream[14], 0);
  *(unsigned __int64 *)((char *)v192.m128_u64 + 4) = __PAIR64__(v22, v24);
  v25 = *(__m128 *)(v5 + 80);
  v213 = *(__m128 *)param_stream;
  v206 = *(__m128 *)(v5 + 96);
  v26 = *(_OWORD *)(v5 + 112);
  v217 = v25;
  v192.m128_i32[3] = LODWORD(v23) ^ _xmm[0];
  v191 = (__m128)(unsigned int)(LODWORD(v23) ^ _xmm[0]);
  si128 = (__m128)_xmm;
  v28 = (__m128)(unsigned int)FLOAT_1_0;
  v234 = v26;
  v195[3] = 1065353216;
  v29 = *(__m128 *)(v5 + 128);
  v207 = _xmm;
  v30 = _mm_shuffle_ps(v25, v25, 255);
  v195[1] = *(_DWORD *)(v5 + 232);
  v199 = v29;
  v197 = v30;
  v215 = (__m128)gVmxAbsMask_0;
  v195[0] = *(_DWORD *)(v5 + 192);
  v29.m128_i32[0] = *(_DWORD *)(v5 + 236);
  v31 = (volatile int *)*((_QWORD *)param_stream + 5);
  v195[2] = v29.m128_i32[0];
  v32 = UFG::qAtomicAdd(v31, 1) - 1;
  if ( v32 < param_stream[16] )
  {
    v187.m128_f32[0] = vars0;
    v187.m128_u64[1] = __PAIR64__(v13, v12);
    v33 = 1.0 / (float)(v14 - v179);
    v34 = (__m128)LODWORD(v180);
    v35 = vars0;
    v186.m128_f32[2] = v180;
    v184 = v33;
    v186.m128_i32[1] = COERCE_UNSIGNED_INT(v180 * vars0) ^ _xmm[0];
    v188.m128_u64[1] = 0i64;
    v188.m128_i32[1] = expf(COERCE_FLOAT(COERCE_UNSIGNED_INT((float)(v180 * vars0) * v178) ^ _xmm[0]));
    do
    {
      v36 = v32 == 31;
      if ( v32 == 31 )
        v37 = v183;
      else
        v37 = v181;
      v38 = &v194;
      v39 = &v233;
      v187.m128_i32[1] = v37;
      if ( v32 != 31 )
        v38 = (__m128 *)&v222;
      if ( !v6 )
        v39 = &v231;
      v40 = *((_QWORD *)param_stream + 4) + (v32 << 12);
      v39->m128_u64[1] = v40;
      if ( v32 == 31 )
      {
        v41 = v34;
      }
      else
      {
        v41 = 0i64;
        v41.m128_f32[0] = (float)(int)v32 * v185;
      }
      v42 = v41;
      v42.m128_f32[0] = (float)((float)(v41.m128_f32[0] + v182) - v179) * v33;
      if ( v42.m128_f32[0] <= 0.0 )
      {
        v42 = 0i64;
      }
      else if ( v42.m128_f32[0] >= v28.m128_f32[0] )
      {
        v42 = v28;
      }
      v186.m128_i32[3] = v41.m128_i32[0];
      v193 = _mm_shuffle_ps(v42, v42, 0);
      v186.m128_i32[0] = COERCE_UNSIGNED_INT(v41.m128_f32[0] * v35) ^ v17;
      v43 = expf(COERCE_FLOAT(COERCE_UNSIGNED_INT((float)(v41.m128_f32[0] * v35) * v178) ^ v17));
      v44 = (__m128)_xmm;
      v45 = (__m128 *)v195;
      v189 = (__m128)_xmm;
      v188.m128_f32[0] = v43;
      if ( !v36 )
        v45 = (__m128 *)&v234;
      v46 = &v220;
      if ( !v36 )
        v46 = &v228;
      v47 = param_stream[18] == 0;
      v48 = _mm_add_ps(_mm_mul_ps(*(__m128 *)v46, v16), v16);
      v201 = v48;
      if ( v47 )
      {
        v55 = _mm_sub_ps(v217, v206);
        v56 = _mm_shuffle_ps(v9, v9, 85);
        v57 = _mm_shuffle_ps(v9, v9, 170);
        v232 = _mm_shuffle_ps(
                 (__m128)_xmm_b92951de3c0658eebe2a84b53f800000,
                 (__m128)_xmm_b92951de3c0658eebe2a84b53f800000,
                 170);
        v58 = _mm_shuffle_ps(
                (__m128)_xmm_b92951de3c0658eebe2a84b53f800000,
                (__m128)_xmm_b92951de3c0658eebe2a84b53f800000,
                85);
        v59 = _mm_shuffle_ps(
                (__m128)_xmm_b92951de3c0658eebe2a84b53f800000,
                (__m128)_xmm_b92951de3c0658eebe2a84b53f800000,
                255);
        v200 = v56;
        v202 = v57;
        v205 = v55;
        v224 = _mm_shuffle_ps(
                 (__m128)_xmm_ba72600c3d1eda81befd9e413f800000,
                 (__m128)_xmm_ba72600c3d1eda81befd9e413f800000,
                 85);
        v214 = v58;
        v230 = _mm_shuffle_ps(
                 (__m128)_xmm_ba72600c3d1eda81befd9e413f800000,
                 (__m128)_xmm_ba72600c3d1eda81befd9e413f800000,
                 0);
        v212 = v59;
        v60 = _mm_shuffle_ps(
                (__m128)_xmm_ba72600c3d1eda81befd9e413f800000,
                (__m128)_xmm_ba72600c3d1eda81befd9e413f800000,
                255);
        v226 = _mm_shuffle_ps(
                 (__m128)_xmm_ba72600c3d1eda81befd9e413f800000,
                 (__m128)_xmm_ba72600c3d1eda81befd9e413f800000,
                 170);
        v210 = v60;
        v218 = _mm_rcp_ps(_mm_sub_ps(*(__m128 *)_xmm, v30));
        v219 = v58;
        v223 = v59;
        v221 = v232;
        v225 = v224;
        v227 = v230;
        v231 = v60;
        v229 = v226;
        v61 = _mm_shuffle_ps(v9, v9, 0);
        v233 = v218;
        v216 = _mm_shuffle_ps(v196, v196, 85);
        v62 = _mm_shuffle_ps(v196, v196, 0);
        v63 = _mm_shuffle_ps(v187, v187, 85);
        v211 = _mm_shuffle_ps(v187, v187, 255);
        v198 = v61;
        v204 = v62;
        v203 = v63;
        v208 = _mm_shuffle_ps(v199, v199, 255);
        v209 = _mm_shuffle_ps(v186, v186, 255);
        v64 = 32i64;
        do
        {
          v65 = 16i64;
          do
          {
            v66 = _mm_add_ps(_mm_mul_ps(v44, v44), v16);
            v67 = _mm_add_ps(_mm_mul_ps(v66, v44), v16);
            v68 = _mm_add_ps(_mm_mul_ps(v67, v66), v16);
            v69 = _mm_add_ps(
                    _mm_add_ps(_mm_add_ps(_mm_mul_ps(v58, v67), v44), _mm_mul_ps(v232, v68)),
                    _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v68, v66), v16), v59));
            v70 = _mm_add_ps(_mm_mul_ps(v66, v66), v16);
            v71 = _mm_add_ps(
                    _mm_add_ps(_mm_add_ps(_mm_mul_ps(v224, v66), v230), _mm_mul_ps(v226, v70)),
                    _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v70, v66), v16), v60));
            v72 = _mm_add_ps(
                    _mm_mul_ps(
                      _mm_shuffle_ps(v69, _mm_shuffle_ps(v71, v69, 240), 64),
                      _mm_shuffle_ps(_mm_shuffle_ps(v71, v69, 85), v71, 249)),
                    v16);
            v73 = _mm_shuffle_ps(v72, v72, 170);
            v74 = _mm_min_ps(
                    _mm_max_ps(_mm_add_ps(_mm_mul_ps(_mm_sub_ps(_mm_shuffle_ps(v44, v44, 0), v197), v218), v16), v16),
                    *(__m128 *)_xmm);
            v75 = _mm_add_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v72, v72, 0), v61), v16),
                          _mm_mul_ps(_mm_shuffle_ps(v72, v72, 85), v56)),
                        _mm_mul_ps(v57, v73)),
                      v62),
                    v216);
            v76 = _mm_cmplt_ps(v73, *v38);
            v77 = _mm_add_ps(_mm_mul_ps(v209, v72), v213);
            v78 = _mm_or_ps(_mm_and_ps(v76, v16), _mm_andnot_ps(v76, v186));
            v79 = _mm_shuffle_ps(_mm_min_ps(_mm_shuffle_ps(v78, v78, 255), _mm_shuffle_ps(v78, v78, 170)), v78, 160);
            v80 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v79, v79, 153), v73), v16);
            v81 = _mm_add_ps(
                    _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v80, v63), (__m128)_xmm), (__m128)`FogFunction::`2::neg_z),
                    (__m128)0i64);
            v82 = _mm_shuffle_ps(
                    v81,
                    _mm_shuffle_ps(
                      v81,
                      _mm_min_ps(_mm_max_ps(_mm_add_ps(_mm_mul_ps(v80, v211), v16), v16), *(__m128 *)_xmm),
                      10),
                    148);
            v83 = _mm_min_ps(_mm_max_ps(v82, (__m128)0i64), *(__m128 *)_xmm);
            v84 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v83, v83, 0), v55), v206);
            v85 = _mm_add_ps(v84, _mm_mul_ps(_mm_shuffle_ps(v83, v83, 170), _mm_sub_ps(*v45, v84)));
            v86 = _mm_shuffle_ps(v82, v82, 85);
            v87 = _mm_shuffle_ps(v82, v82, 255);
            v88 = _mm_add_ps(_mm_mul_ps(v86, v55), v206);
            v89 = _mm_add_ps(v85, _mm_mul_ps(_mm_sub_ps(v88, v85), v87));
            v90 = _mm_add_ps(v89, _mm_mul_ps(_mm_sub_ps(v88, v89), v48));
            v91 = (__m128)LODWORD(FLOAT_2_0);
            v92 = _mm_add_ps(
                    v90,
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_mul_ps(
                          _mm_add_ps(
                            _mm_mul_ps(
                              _mm_min_ps(
                                _mm_max_ps(
                                  _mm_add_ps(
                                    _mm_mul_ps(
                                      _mm_add_ps(_mm_mul_ps(_mm_and_ps(v75, v215), v75), (__m128)0i64),
                                      _mm_add_ps(_mm_mul_ps(v74, v74), (__m128)0i64)),
                                    (__m128)0i64),
                                  (__m128)0i64),
                                *(__m128 *)_xmm),
                              v208),
                            (__m128)0i64),
                          v193),
                        (__m128)0i64),
                      _mm_sub_ps(v199, v90)));
            v93 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v78, v78, 0), v92), (__m128)0i64);
            v91.m128_f32[0] = powf(2.0, v93.m128_f32[0]);
            v94 = v91;
            v95 = (__m128)LODWORD(FLOAT_2_0);
            v95.m128_f32[0] = powf(2.0, _mm_shuffle_ps(v93, v93, 85).m128_f32[0]);
            v96 = v95;
            v97 = (__m128)LODWORD(FLOAT_2_0);
            v97.m128_f32[0] = powf(2.0, _mm_shuffle_ps(v93, v93, 170).m128_f32[0]);
            v98 = v97;
            v99 = (__m128)LODWORD(FLOAT_2_0);
            v99.m128_f32[0] = powf(2.0, _mm_shuffle_ps(v93, v93, 255).m128_f32[0]);
            v100 = _mm_unpacklo_ps(_mm_unpacklo_ps(v94, v98), _mm_unpacklo_ps(v96, v99));
            v101 = (__m128)LODWORD(FLOAT_2_0);
            v102 = _mm_sub_ps(*(__m128 *)_xmm, v100);
            v103 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v78, v78, 85), v92), (__m128)0i64);
            v101.m128_f32[0] = powf(2.0, v103.m128_f32[0]);
            v104 = v101;
            v105 = (__m128)LODWORD(FLOAT_2_0);
            v105.m128_f32[0] = powf(2.0, _mm_shuffle_ps(v103, v103, 85).m128_f32[0]);
            v106 = v105;
            v107 = (__m128)LODWORD(FLOAT_2_0);
            v107.m128_f32[0] = powf(2.0, _mm_shuffle_ps(v103, v103, 170).m128_f32[0]);
            v108 = v107;
            v109 = (__m128)LODWORD(FLOAT_2_0);
            v109.m128_f32[0] = powf(2.0, _mm_shuffle_ps(v103, v103, 255).m128_f32[0]);
            v110 = _mm_shuffle_ps(v102, _mm_shuffle_ps(v102, v188, 10), 148);
            v111 = _mm_sub_ps(
                     *(__m128 *)_xmm,
                     _mm_unpacklo_ps(_mm_unpacklo_ps(v104, v108), _mm_unpacklo_ps(v106, v109)));
            v190 = _mm_add_ps(_mm_mul_ps(v189, *(__m128 *)_xmm), (__m128)_xmm);
            v112 = _mm_add_ps(_mm_mul_ps(v190, v190), (__m128)0i64);
            v113 = _mm_add_ps(
                     _mm_mul_ps(_mm_sub_ps(_mm_shuffle_ps(v111, _mm_shuffle_ps(v111, v188, 90), 148), v110), v87),
                     v110);
            v114 = _mm_sub_ps(v192, v77);
            v115 = _mm_add_ps(_mm_mul_ps(v114, v114), (__m128)0i64);
            v116 = _mm_add_ps(_mm_shuffle_ps(v115, v115, 85), v115);
            v117 = _mm_add_ps(_mm_mul_ps(v112, v190), (__m128)0i64);
            v118 = _mm_min_ps(
                     _mm_max_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_add_ps(_mm_mul_ps(_mm_rsqrt_ps(v116), v116), (__m128)0i64), v191),
                         v188),
                       v190),
                     *(__m128 *)_xmm);
            v119 = _mm_shuffle_ps(v118, v118, 0);
            v120 = _mm_min_ps(
                     _mm_max_ps(
                       _mm_add_ps(
                         _mm_mul_ps(
                           _mm_shuffle_ps(v119, _mm_shuffle_ps(v119, *(__m128 *)_xmm, 250), 148),
                           _mm_shuffle_ps(v113, _mm_shuffle_ps(v113, _mm_sub_ps(*(__m128 *)_xmm, v113), 250), 148)),
                         (__m128)0i64),
                       (__m128)0i64),
                     *(__m128 *)_xmm);
            v121 = _mm_add_ps(_mm_mul_ps(v117, v112), (__m128)0i64);
            v16 = 0i64;
            v122 = _mm_add_ps(
                     _mm_add_ps(_mm_add_ps(_mm_mul_ps(v117, v219), v190), _mm_mul_ps(v121, v221)),
                     _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v121, v112), (__m128)0i64), v223));
            v123 = _mm_add_ps(_mm_mul_ps(v112, v112), (__m128)0i64);
            v124 = _mm_min_ps(
                     _mm_max_ps(
                       _mm_add_ps(_mm_mul_ps(_mm_sub_ps(_mm_shuffle_ps(v190, v190, 0), v197), v233), (__m128)0i64),
                       (__m128)0i64),
                     *(__m128 *)_xmm);
            v125 = _mm_add_ps(
                     _mm_add_ps(_mm_add_ps(_mm_mul_ps(v112, v225), v227), _mm_mul_ps(v123, v229)),
                     _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v123, v112), (__m128)0i64), v231));
            v126 = _mm_add_ps(
                     _mm_mul_ps(
                       _mm_shuffle_ps(v122, _mm_shuffle_ps(v125, v122, 240), 64),
                       _mm_shuffle_ps(_mm_shuffle_ps(v125, v122, 85), v125, 249)),
                     (__m128)0i64);
            v127 = _mm_shuffle_ps(v126, v126, 170);
            v128 = _mm_add_ps(_mm_mul_ps(v209, v126), v213);
            v129 = _mm_cmplt_ps(v127, *v38);
            v130 = _mm_add_ps(
                     _mm_mul_ps(
                       _mm_add_ps(
                         _mm_add_ps(
                           _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v126, v126, 0), v198), (__m128)0i64),
                           _mm_mul_ps(_mm_shuffle_ps(v126, v126, 85), v200)),
                         _mm_mul_ps(v202, v127)),
                       v204),
                     v216);
            v131 = _mm_or_ps(_mm_andnot_ps(v129, v186), _mm_and_ps(v129, (__m128)0i64));
            v132 = _mm_shuffle_ps(
                     _mm_min_ps(_mm_shuffle_ps(v131, v131, 255), _mm_shuffle_ps(v131, v131, 170)),
                     v131,
                     160);
            v133 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v132, v132, 153), v127), (__m128)0i64);
            v134 = _mm_add_ps(
                     _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v203, v133), (__m128)_xmm), (__m128)`FogFunction::`2::neg_z),
                     (__m128)0i64);
            v135 = _mm_shuffle_ps(
                     v134,
                     _mm_shuffle_ps(
                       v134,
                       _mm_min_ps(
                         _mm_max_ps(_mm_add_ps(_mm_mul_ps(v211, v133), (__m128)0i64), (__m128)0i64),
                         *(__m128 *)_xmm),
                       10),
                     148);
            v136 = _mm_min_ps(_mm_max_ps(v135, (__m128)0i64), *(__m128 *)_xmm);
            v137 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v136, v136, 0), v205), v206);
            v138 = _mm_add_ps(v137, _mm_mul_ps(_mm_shuffle_ps(v136, v136, 170), _mm_sub_ps(*v45, v137)));
            v139 = _mm_shuffle_ps(v135, v135, 85);
            v140 = _mm_shuffle_ps(v135, v135, 255);
            v141 = _mm_add_ps(_mm_mul_ps(v139, v205), v206);
            v142 = _mm_add_ps(v138, _mm_mul_ps(_mm_sub_ps(v141, v138), v140));
            v143 = _mm_add_ps(v142, _mm_mul_ps(_mm_sub_ps(v141, v142), v201));
            v144 = (__m128)LODWORD(FLOAT_2_0);
            v145 = _mm_add_ps(
                     v143,
                     _mm_mul_ps(
                       _mm_add_ps(
                         _mm_mul_ps(
                           _mm_add_ps(
                             _mm_mul_ps(
                               _mm_min_ps(
                                 _mm_max_ps(
                                   _mm_add_ps(
                                     _mm_mul_ps(
                                       _mm_add_ps(_mm_mul_ps(_mm_and_ps(v130, v215), v130), (__m128)0i64),
                                       _mm_add_ps(_mm_mul_ps(v124, v124), (__m128)0i64)),
                                     (__m128)0i64),
                                   (__m128)0i64),
                                 *(__m128 *)_xmm),
                               v208),
                             (__m128)0i64),
                           v193),
                         (__m128)0i64),
                       _mm_sub_ps(v199, v143)));
            v146 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v131, v131, 0), v145), (__m128)0i64);
            v144.m128_f32[0] = powf(2.0, v146.m128_f32[0]);
            v147 = v144;
            v148 = (__m128)LODWORD(FLOAT_2_0);
            v148.m128_f32[0] = powf(2.0, _mm_shuffle_ps(v146, v146, 85).m128_f32[0]);
            v149 = v148;
            v150 = (__m128)LODWORD(FLOAT_2_0);
            v150.m128_f32[0] = powf(2.0, _mm_shuffle_ps(v146, v146, 170).m128_f32[0]);
            v151 = v150;
            v152 = (__m128)LODWORD(FLOAT_2_0);
            v152.m128_f32[0] = powf(2.0, _mm_shuffle_ps(v146, v146, 255).m128_f32[0]);
            v153 = _mm_unpacklo_ps(v149, v152);
            v154 = (__m128)LODWORD(FLOAT_2_0);
            v155 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v131, v131, 85), v145), (__m128)0i64);
            v156 = _mm_sub_ps(*(__m128 *)_xmm, _mm_unpacklo_ps(_mm_unpacklo_ps(v147, v151), v153));
            v154.m128_f32[0] = powf(2.0, v155.m128_f32[0]);
            v157 = v154;
            v158 = (__m128)LODWORD(FLOAT_2_0);
            v158.m128_f32[0] = powf(2.0, _mm_shuffle_ps(v155, v155, 85).m128_f32[0]);
            v159 = v158;
            v160 = (__m128)LODWORD(FLOAT_2_0);
            v160.m128_f32[0] = powf(2.0, _mm_shuffle_ps(v155, v155, 170).m128_f32[0]);
            v161 = v160;
            v162 = (__m128)LODWORD(FLOAT_2_0);
            v162.m128_f32[0] = powf(2.0, _mm_shuffle_ps(v155, v155, 255).m128_f32[0]);
            v163 = _mm_unpacklo_ps(v157, v161);
            v40 += 8i64;
            --v65;
            v60 = v210;
            v164 = _mm_unpacklo_ps(v163, _mm_unpacklo_ps(v159, v162));
            v8 = (__m128)_xmm;
            v61 = v198;
            v44 = _mm_add_ps(_mm_mul_ps(v190, *(__m128 *)_xmm), (__m128)_xmm);
            v165 = _mm_shuffle_ps(v156, _mm_shuffle_ps(v156, v188, 10), 148);
            v189 = v44;
            v166 = _mm_sub_ps(*(__m128 *)_xmm, v164);
            v63 = v203;
            v167 = _mm_mul_ps(_mm_sub_ps(_mm_shuffle_ps(v166, _mm_shuffle_ps(v166, v188, 90), 148), v165), v140);
            v56 = v200;
            v168 = _mm_add_ps(v167, v165);
            v48 = v201;
            v169 = _mm_sub_ps(v192, v128);
            v170 = _mm_add_ps(_mm_mul_ps(v169, v169), (__m128)0i64);
            v171 = _mm_add_ps(_mm_shuffle_ps(v170, v170, 85), v170);
            v172 = _mm_cvtps_epi32(_mm_add_ps(_mm_mul_ps(v120, (__m128)_xmm), (__m128)0i64));
            v55 = v205;
            v173 = _mm_packs_epi32(v172, v172);
            *(_DWORD *)(v40 - 8) = _mm_packus_epi16(v173, v173).m128i_u32[0];
            v174 = _mm_min_ps(
                     _mm_max_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_add_ps(_mm_mul_ps(_mm_rsqrt_ps(v171), v171), (__m128)0i64), v191),
                         v188),
                       v44),
                     *(__m128 *)_xmm);
            v175 = _mm_shuffle_ps(v174, v174, 0);
            v176 = _mm_cvtps_epi32(
                     _mm_add_ps(
                       _mm_mul_ps(
                         _mm_min_ps(
                           _mm_max_ps(
                             _mm_add_ps(
                               _mm_mul_ps(
                                 _mm_shuffle_ps(v175, _mm_shuffle_ps(v175, *(__m128 *)_xmm, 250), 148),
                                 _mm_shuffle_ps(v168, _mm_shuffle_ps(v168, _mm_sub_ps(*(__m128 *)_xmm, v168), 250), 148)),
                               (__m128)0i64),
                             (__m128)0i64),
                           *(__m128 *)_xmm),
                         (__m128)_xmm),
                       (__m128)0i64));
            v59 = v212;
            v177 = _mm_packs_epi32(v176, v176);
            *(_DWORD *)(v40 - 4) = _mm_packus_epi16(v177, v177).m128i_u32[0];
            v57 = v202;
            v62 = v204;
            v58 = v214;
          }
          while ( v65 );
          v44 = _mm_add_ps(_mm_mul_ps(v44, (__m128)_xmm), (__m128)_xmm);
          v189 = v44;
          --v64;
        }
        while ( v64 );
        si128 = (__m128)_mm_load_si128((const __m128i *)&v207);
        v9 = v235;
        v30 = v197;
        v17 = _xmm[0];
        v33 = v184;
        v34 = (__m128)LODWORD(v180);
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
            v51 = _mm_cvtps_epi32((__m128)_mm_cvtps_epi32(_mm_add_ps(_mm_mul_ps(_mm_add_ps(_mm_mul_ps(si128, v8), v16), v8), v16)));
            v52 = _mm_packs_epi32(v51, v51);
            v53 = _mm_packs_epi32(v52, v52);
            v54 = _mm_packus_epi16(v53, v53);
            si128 = (__m128)_mm_packus_epi16(v54, v54);
            *(_DWORD *)(v40 - 8) = si128.m128_i32[0];
            *(_DWORD *)(v40 - 4) = si128.m128_i32[0];
            --v50;
          }
          while ( v50 );
          v207 = (__int128)si128;
          --v49;
        }
        while ( v49 );
      }
      v6 ^= 1u;
      v28 = (__m128)(unsigned int)FLOAT_1_0;
      v32 = UFG::qAtomicAdd(*((volatile int **)param_stream + 5), 1) - 1;
    }
    while ( v32 < param_stream[16] );
  }
}

