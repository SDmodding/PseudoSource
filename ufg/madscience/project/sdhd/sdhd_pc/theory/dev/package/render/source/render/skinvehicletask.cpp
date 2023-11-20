// File Line: 13
// RVA: 0x14573D0
__int64 dynamic_initializer_for__gTaskFunctionDecl_SkinVehicleBufferTask__()
{
  UFG::qTaskFunctionDecl::qTaskFunctionDecl(
    &gTaskFunctionDecl_SkinVehicleBufferTask,
    &gTaskFunctionDeclData_SkinVehicleBufferTask);
  return atexit(dynamic_atexit_destructor_for__gTaskFunctionDecl_SkinVehicleBufferTask__);
}

// File Line: 14
// RVA: 0x1457430
__int64 dynamic_initializer_for__gTaskFunctionDecl_SkinVehicleGlassBufferTask__()
{
  UFG::qTaskFunctionDecl::qTaskFunctionDecl(
    &gTaskFunctionDecl_SkinVehicleGlassBufferTask,
    &gTaskFunctionDeclData_SkinVehicleGlassBufferTask);
  return atexit(dynamic_atexit_destructor_for__gTaskFunctionDecl_SkinVehicleGlassBufferTask__);
}

// File Line: 15
// RVA: 0x1457400
__int64 dynamic_initializer_for__gTaskFunctionDecl_SkinVehicleDecalBufferTask__()
{
  UFG::qTaskFunctionDecl::qTaskFunctionDecl(
    &gTaskFunctionDecl_SkinVehicleDecalBufferTask,
    &gTaskFunctionDeclData_SkinVehicleDecalBufferTask);
  return atexit(dynamic_atexit_destructor_for__gTaskFunctionDecl_SkinVehicleDecalBufferTask__);
}

// File Line: 19
// RVA: 0x74D80
void __fastcall SkinVehicleBufferTask(int worker_id, UFG::qMemoryStreamer *memory_streamer, void *param0, void *param1)
{
  __int64 v4; // rdx
  __int64 v5; // rsi
  __int64 v6; // rax
  int v7; // er10
  __int64 v8; // r14
  __int64 v9; // r12
  unsigned int v10; // er9
  __m128 v11; // xmm11
  bool v12; // zf
  char *v13; // r15
  __int64 v14; // rdx
  unsigned int v15; // er8
  unsigned int v16; // er13
  unsigned int v17; // er10
  bool v18; // di
  bool v19; // cf
  unsigned int v20; // er11
  unsigned __int8 *v21; // r10
  __int64 v22; // rax
  __int64 v23; // rbx
  __m128 *v24; // rdx
  __int64 v25; // r11
  int v26; // er8
  __m128 *v27; // rcx
  __m128 *v28; // rax
  __m128 v29; // xmm5
  __m128 v30; // xmm11
  __m128 v31; // xmm12
  __m128 v32; // xmm13
  __m128 v33; // xmm4
  __m128 v34; // xmm3
  __m128 v35; // xmm8
  __m128 v36; // xmm2
  __m128 v37; // xmm5
  __m128 v38; // xmm1
  __m128 v39; // xmm7
  __m128 v40; // xmm6
  __m128 v41; // xmm8
  __m128 v42; // xmm10
  __m128 v43; // xmm4
  __m128 v44; // xmm5
  __m128 v45; // xmm10
  __m128 v46; // xmm4
  __m128 v47; // xmm5
  __m128 v48; // xmm4
  __m128 v49; // xmm5
  __m128 v50; // xmm10
  __m128 v51; // xmm14
  __m128 v52; // xmm1
  __m128 v53; // xmm9
  __m128 v54; // xmm4
  __m128 v55; // xmm10
  UFG::qVector4 v56; // xmm0
  UFG::qVector4 v57; // xmm1
  unsigned int v58; // xmm2_4
  __m128 v59; // xmm8
  __m128 v60; // xmm9
  __int128 v61; // xmm10
  __int128 v62; // xmm12
  float v63; // xmm6_4
  UFG::qVector4 v64; // xmm0
  UFG::qVector4 v65; // xmm1
  int v66; // xmm2_4
  unsigned int v67; // ecx
  __int64 v68; // rax
  double v69; // xmm3_8
  float v70; // xmm2_4
  __m128 v71; // xmm5
  __m128 v72; // xmm4
  float v73; // xmm1_4
  float v74; // xmm1_4
  float v75; // xmm1_4
  __m128 v76; // xmm5
  __m128 v77; // xmm10
  UFG::qVector4 v78; // xmm12
  __m128i v79; // xmm3
  unsigned __int64 v80; // rbx
  unsigned int v81; // esi
  __m128 *v82; // r12
  char *v83; // rdi
  __int64 v84; // r14
  __int64 v85; // rax
  int v86; // edx
  int v87; // er8
  __int64 v88; // rcx
  __int64 v89; // r9
  __int64 v90; // rdx
  __int64 v91; // r8
  unsigned __int64 v92; // r11
  unsigned __int64 v93; // r10
  __m128 *v94; // rcx
  __m128 v95; // xmm4
  __m128 v96; // xmm2
  __int128 v97; // xmm1
  __int128 v98; // xmm0
  __m128i v99; // xmm0
  __int64 v100; // rcx
  __m128 v101; // xmm4
  __m128 v102; // xmm1
  __m128 v103; // xmm2
  float v104; // xmm12_4
  float v105; // xmm13_4
  float v106; // xmm14_4
  float v107; // xmm5_4
  float v108; // xmm8_4
  float v109; // xmm9_4
  float v110; // xmm3_4
  float v111; // xmm6_4
  unsigned int v112; // eax
  unsigned int v113; // eax
  unsigned int v114; // eax
  unsigned int v115; // er9
  float *v116; // r10
  float v117; // xmm9_4
  float v118; // xmm10_4
  float v119; // xmm7_4
  float v120; // xmm11_4
  float v121; // xmm12_4
  float v122; // xmm13_4
  float v123; // xmm14_4
  float v124; // xmm6_4
  unsigned int v125; // edx
  int v126; // er8
  __int16 v127; // r8
  unsigned int v128; // edx
  unsigned int v129; // edx
  int v130; // er8
  __int16 v131; // r8
  unsigned int v132; // edx
  __int64 v133; // rcx
  __m128 v134; // xmm0
  __int64 v135; // rdi
  unsigned int v136; // edx
  __int64 v137; // r8
  __m128 *v138; // r10
  _OWORD *v139; // rbx
  _OWORD *v140; // r11
  __int64 v141; // rcx
  __int64 v142; // rcx
  __int64 v143; // r15
  __int64 v144; // r8
  __int64 v145; // rdi
  __m128 v146; // xmm8
  __m128 v147; // xmm6
  __m128 v148; // xmm1
  __m128 v149; // xmm5
  unsigned __int8 *v150; // rcx
  unsigned __int64 v151; // rdx
  __m128 v152; // xmm12
  __m128 v153; // xmm13
  __m128 v154; // xmm14
  __m128 v155; // xmm0
  __m128 v156; // xmm11
  __m128i v157; // xmm2
  __m128 v158; // xmm1
  __m128 v159; // xmm3
  __m128 v160; // xmm8
  __m128 v161; // xmm9
  __m128 v162; // xmm10
  __m128 v163; // xmm8
  __m128 v164; // xmm9
  __m128 v165; // xmm3
  __m128 v166; // xmm2
  __m128 v167; // xmm0
  __m128 v168; // xmm1
  __m128 v169; // xmm6
  __m128 v170; // xmm7
  __m128 v171; // xmm3
  __m128 v172; // xmm5
  __m128 v173; // xmm2
  __m128 v174; // xmm8
  __m128 v175; // xmm2
  __m128 v176; // xmm0
  __m128 v177; // xmm1
  __m128 v178; // xmm4
  __m128 v179; // xmm7
  __m128 v180; // xmm2
  __m128 v181; // xmm3
  __m128i v182; // xmm0
  __m128i v183; // xmm2
  __m128i v184; // xmm2
  __m128 v185; // xmm1
  __m128 v186; // xmm1
  __m128i v187; // xmm2
  __m128i v188; // xmm2
  bool v189; // [rsp+30h] [rbp-D0h]
  unsigned int v190; // [rsp+34h] [rbp-CCh]
  float width; // [rsp+34h] [rbp-CCh]
  float v192; // [rsp+38h] [rbp-C8h]
  float v193; // [rsp+38h] [rbp-C8h]
  unsigned int v194; // [rsp+40h] [rbp-C0h]
  __m128 v195; // [rsp+50h] [rbp-B0h]
  UFG::qVector3 inpts; // [rsp+60h] [rbp-A0h]
  float v197; // [rsp+6Ch] [rbp-94h]
  float v198; // [rsp+70h] [rbp-90h]
  float v199; // [rsp+74h] [rbp-8Ch]
  float v200; // [rsp+78h] [rbp-88h]
  float v201; // [rsp+7Ch] [rbp-84h]
  float v202; // [rsp+80h] [rbp-80h]
  __int64 v203; // [rsp+88h] [rbp-78h]
  __int64 v204; // [rsp+90h] [rbp-70h]
  unsigned int v205; // [rsp+98h] [rbp-68h]
  float v206; // [rsp+9Ch] [rbp-64h]
  __m128 v207; // [rsp+A0h] [rbp-60h]
  __m128 v208; // [rsp+B0h] [rbp-50h]
  UFG::qMatrix44 v209; // [rsp+C0h] [rbp-40h]
  __int128 v210; // [rsp+100h] [rbp+0h]
  UFG::qMatrix44 m; // [rsp+110h] [rbp+10h]
  __m128 v212; // [rsp+150h] [rbp+50h]
  __m128 v213; // [rsp+160h] [rbp+60h]
  __m128i v214; // [rsp+170h] [rbp+70h]
  __int64 v215; // [rsp+180h] [rbp+80h]
  __m128 v216; // [rsp+190h] [rbp+90h]
  __m128 v217; // [rsp+1A0h] [rbp+A0h]
  UFG::qMatrix44 mat; // [rsp+1B0h] [rbp+B0h]
  unsigned __int64 v219; // [rsp+1F0h] [rbp+F0h]
  __int64 v220; // [rsp+1F8h] [rbp+F8h]
  __m128 v221; // [rsp+200h] [rbp+100h]
  __int64 v222; // [rsp+210h] [rbp+110h]
  __int64 v223; // [rsp+218h] [rbp+118h]
  __m128 v224; // [rsp+220h] [rbp+120h]
  __m128 v225; // [rsp+230h] [rbp+130h]
  __m128i v226; // [rsp+240h] [rbp+140h]
  __m128 v227; // [rsp+250h] [rbp+150h]
  __int128 v228; // [rsp+260h] [rbp+160h]
  __m128 v229; // [rsp+270h] [rbp+170h]
  __int128 v230; // [rsp+280h] [rbp+180h]
  __int128 v231; // [rsp+290h] [rbp+190h]
  __m128 v232; // [rsp+2A0h] [rbp+1A0h]
  __m128 v233; // [rsp+2B0h] [rbp+1B0h]
  __m128 v234; // [rsp+2C0h] [rbp+1C0h]
  __m128 v235; // [rsp+2D0h] [rbp+1D0h]
  __m128 v236; // [rsp+2E0h] [rbp+1E0h]
  char v237; // [rsp+2F0h] [rbp+1F0h]
  char v238; // [rsp+300h] [rbp+200h]
  char v239; // [rsp+310h] [rbp+210h]
  UFG::qMatrix44 d; // [rsp+320h] [rbp+220h]
  char source; // [rsp+360h] [rbp+260h]
  char v242; // [rsp+370h] [rbp+270h]
  char v243; // [rsp+380h] [rbp+280h]
  char v244; // [rsp+3A0h] [rbp+2A0h]
  UFG::qVector3 outpts; // [rsp+3C0h] [rbp+2C0h]
  UFG::qVector3 v246; // [rsp+540h] [rbp+440h]
  UFG::qVector3 v247; // [rsp+6C0h] [rbp+5C0h]
  __int128 v248; // [rsp+840h] [rbp+740h]
  __int128 v249; // [rsp+850h] [rbp+750h]
  __int128 v250; // [rsp+860h] [rbp+760h]
  __int128 v251; // [rsp+870h] [rbp+770h]
  char *v252; // [rsp+4920h] [rbp+4820h]

  v252 = (char *)param0;
  v4 = *((_QWORD *)param0 + 9);
  v5 = *(_QWORD *)param0;
  v6 = *((_QWORD *)param0 + 3);
  v7 = *((_DWORD *)param0 + 15);
  v8 = *((_QWORD *)param0 + 1);
  v9 = *((_QWORD *)param0 + 2);
  v10 = *((_DWORD *)param0 + 16);
  v11 = gVmxOne_4;
  v12 = *(_QWORD *)param0 == 0i64;
  v204 = *((_QWORD *)param0 + 6);
  v13 = (char *)param0;
  v207 = gVmxOne_4;
  v189 = v12;
  v220 = v4;
  v14 = *((_QWORD *)param0 + 14);
  v15 = *((unsigned __int16 *)param0 + 20);
  v219 = v6 & 0xFFFFFFFFFFFFFFF0ui64;
  v215 = v5;
  v223 = v8;
  v16 = (unsigned int)(v6 & 0xF) >> 1;
  v222 = v9;
  v17 = v16 + v7;
  v18 = v14 != 0;
  v19 = v17 < 0x61A8;
  v12 = v17 == 25000;
  v20 = 2 * v17;
  v194 = v17;
  v21 = (unsigned __int8 *)*((_QWORD *)v13 + 13);
  if ( !v19 && !v12 )
    v18 = 0;
  v205 = v10;
  v190 = v20;
  v22 = 0i64;
  v203 = 0i64;
  v23 = 0i64;
  *(_QWORD *)&v210 = 0i64;
  if ( v15 )
  {
    v24 = (__m128 *)&v250;
    v25 = v15;
    do
    {
      v26 = *v21;
      if ( v26 == 255 )
      {
        v24[-2] = gVmxIdentity0_4;
        v24[-1] = gVmxIdentity1_4;
        *v24 = gVmxIdentity2_4;
        v24[1] = gVmxIdentity3_4;
      }
      else
      {
        v27 = (__m128 *)(*((_QWORD *)v13 + 4) + (unsigned int)(48 * v26));
        v28 = (__m128 *)(*((_QWORD *)v13 + 12) + (unsigned int)(v26 << 6));
        v29 = v27[1];
        v30 = v28[1];
        v31 = v28[2];
        v32 = v28[3];
        v33 = _mm_shuffle_ps(v27[1], v29, 255);
        v34 = _mm_add_ps(v29, v29);
        v35 = _mm_shuffle_ps(v27[1], v29, 201);
        v36 = _mm_shuffle_ps(v34, v34, 210);
        v37 = _mm_shuffle_ps(v29, v29, 210);
        v38 = _mm_shuffle_ps(v34, v34, 201);
        v39 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v38, v33), (__m128)0i64), _mm_mul_ps(v37, v34));
        v40 = _mm_sub_ps(_mm_sub_ps(v207, _mm_mul_ps(v38, v35)), _mm_mul_ps(v36, v37));
        v41 = _mm_sub_ps(_mm_add_ps(_mm_mul_ps(v35, v34), (__m128)0i64), _mm_mul_ps(v36, v33));
        v42 = _mm_shuffle_ps(_mm_shuffle_ps(v39, v41, 80), v41, 233);
        v43 = _mm_shuffle_ps(_mm_shuffle_ps(v40, v39, 80), v39, 233);
        v44 = _mm_shuffle_ps(_mm_shuffle_ps(v41, v40, 80), v40, 233);
        v45 = _mm_shuffle_ps(v42, _mm_shuffle_ps(v40, v42, 250), 148);
        v46 = _mm_shuffle_ps(v43, _mm_shuffle_ps(v41, v43, 250), 148);
        v47 = _mm_shuffle_ps(v44, _mm_shuffle_ps(v39, v44, 250), 148);
        v48 = _mm_shuffle_ps(v46, _mm_shuffle_ps(v46, (__m128)0i64, 250), 148);
        v49 = _mm_shuffle_ps(v47, _mm_shuffle_ps(v47, (__m128)0i64, 250), 148);
        v50 = _mm_shuffle_ps(v45, _mm_shuffle_ps(v45, (__m128)0i64, 250), 148);
        v51 = _mm_shuffle_ps(*v27, _mm_shuffle_ps(*v27, v207, 250), 148);
        v24[-2] = _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(*v28, *v28, 0), v48), (__m128)0i64),
                        _mm_mul_ps(_mm_shuffle_ps(*v28, *v28, 85), v49)),
                      _mm_mul_ps(_mm_shuffle_ps(*v28, *v28, 170), v50)),
                    _mm_mul_ps(_mm_shuffle_ps(*v28, *v28, 255), v51));
        v24[-1] = _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v30, v30, 0), v48), (__m128)0i64),
                        _mm_mul_ps(_mm_shuffle_ps(v30, v30, 85), v49)),
                      _mm_mul_ps(_mm_shuffle_ps(v30, v30, 170), v50)),
                    _mm_mul_ps(_mm_shuffle_ps(v30, v30, 255), v51));
        *v24 = _mm_add_ps(
                 _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v31, v31, 0), v48), (__m128)0i64),
                     _mm_mul_ps(_mm_shuffle_ps(v31, v31, 85), v49)),
                   _mm_mul_ps(_mm_shuffle_ps(v31, v31, 170), v50)),
                 _mm_mul_ps(_mm_shuffle_ps(v31, v31, 255), v51));
        v24[1] = _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v32, v32, 0), v48), (__m128)0i64),
                       _mm_mul_ps(_mm_shuffle_ps(v32, v32, 85), v49)),
                     _mm_mul_ps(_mm_shuffle_ps(v32, v32, 170), v50)),
                   _mm_mul_ps(_mm_shuffle_ps(v32, v32, 255), v51));
      }
      v24 += 4;
      ++v21;
      --v25;
    }
    while ( v25 );
    v11 = v207;
    v14 = *((_QWORD *)v13 + 14);
    v20 = v190;
    v22 = 0i64;
  }
  if ( v18 )
  {
    v23 = *((_QWORD *)v13 + 17);
    v22 = v14;
    v203 = v14;
    *(_QWORD *)&v210 = v23;
  }
  v52 = gVmxMinusOne_2;
  v53 = gVmx127_2;
  v54 = (__m128)gVmxi127_2;
  v55 = (__m128)gVmxUnpackMask_2;
  v225 = gVmxOneOver127_2;
  v227 = gVmxMinusOne_2;
  v213 = gVmx127_2;
  v233 = gVmxOneOver255_2;
  v212 = (__m128)gVmxi127_2;
  v232 = gVmxOneOver511_2;
  v214 = gVmxUnpackMask_2;
  _mm_store_si128(&v226, gVmxUnpackBias_2);
  v221 = gVmxUnpackUnbias_2;
  v224 = gVmxUnpackShift_2;
  if ( v18 && v20 <= 0xC350 )
  {
    v56 = *(UFG::qVector4 *)(v22 + 128);
    v57 = *(UFG::qVector4 *)(v22 + 144);
    v58 = *(_DWORD *)(v22 + 200);
    v59 = *(__m128 *)(v22 + 64);
    v60 = *(__m128 *)(v22 + 80);
    v61 = *(_OWORD *)(v22 + 96);
    v228 = *(_OWORD *)(v22 + 64);
    v229 = v60;
    v230 = v61;
    v62 = *(_OWORD *)(v22 + 112);
    v63 = *(float *)(v22 + 228);
    m.v0 = v56;
    v231 = v62;
    v64 = *(UFG::qVector4 *)(v22 + 160);
    m.v1 = v57;
    v65 = *(UFG::qVector4 *)(v22 + 176);
    m.v2 = v64;
    v64.x = *(float *)(v22 + 232);
    m.v3 = v65;
    v65.x = *(float *)(v22 + 196);
    width = v64.x;
    v208.m128_i32[0] = *(_DWORD *)(v22 + 192);
    v64.x = *(float *)(v22 + 208);
    *(unsigned __int64 *)((char *)v208.m128_u64 + 4) = __PAIR__(v58, LODWORD(v65.x));
    v66 = *(_DWORD *)(v22 + 216);
    v195.m128_u64[0] = __PAIR__(*(_DWORD *)(v22 + 212), LODWORD(v64.x));
    v195.m128_i32[2] = v66;
    v206 = v63;
    TransformAABB2(&m, (UFG::qVector3 *)&v208, (UFG::qVector3 *)&v195);
    v67 = 0;
    v68 = 0i64;
    v69 = v63 * 1.45;
    while ( 1 )
    {
      v70 = *(float *)((char *)&v231 + v68 * 4);
      if ( v70 + v69 <= v208.m128_f32[v68] || v70 - v69 >= v195.m128_f32[v68] )
        break;
      ++v67;
      ++v68;
      if ( v67 >= 3 )
      {
        v71 = (__m128)LODWORD(m.v0.y);
        v72 = v71;
        v72.m128_f32[0] = (float)((float)(v71.m128_f32[0] * v71.m128_f32[0]) + (float)(m.v0.x * m.v0.x))
                        + (float)(m.v0.z * m.v0.z);
        if ( v72.m128_f32[0] == 0.0 )
          v73 = 0.0;
        else
          v73 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v72));
        v209.v0.x = m.v0.x * v73;
        v209.v0.y = m.v0.y * v73;
        v209.v0.w = v73 * 0.0;
        v209.v0.z = m.v0.z * v73;
        if ( (float)((float)((float)(m.v1.y * m.v1.y) + (float)(m.v1.x * m.v1.x)) + (float)(m.v1.z * m.v1.z)) == 0.0 )
          v74 = 0.0;
        else
          v74 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps((__m128)LODWORD(m.v1.y)));
        v209.v1.x = m.v1.x * v74;
        v209.v1.y = m.v1.y * v74;
        v209.v1.z = m.v1.z * v74;
        v209.v1.w = v74 * 0.0;
        if ( (float)((float)((float)(m.v2.y * m.v2.y) + (float)(m.v2.x * m.v2.x)) + (float)(m.v2.z * m.v2.z)) == 0.0 )
          v75 = 0.0;
        else
          v75 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps((__m128)LODWORD(m.v2.y)));
        v209.v3 = m.v3;
        v209.v2.x = m.v2.x * v75;
        v209.v2.y = m.v2.y * v75;
        v209.v2.w = v75 * 0.0;
        v209.v2.z = m.v2.z * v75;
        UFG::qInverse(&d, &v209);
        v76 = (__m128)v61;
        v77 = (__m128)v62;
        v78 = (UFG::qVector4)_mm_add_ps(
                               _mm_add_ps(
                                 _mm_add_ps(
                                   _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v59, v59, 0), (__m128)d.v0), (__m128)0i64),
                                   _mm_mul_ps(_mm_shuffle_ps(v59, v59, 85), (__m128)d.v1)),
                                 _mm_mul_ps(_mm_shuffle_ps(v59, v59, 170), (__m128)d.v2)),
                               _mm_mul_ps(_mm_shuffle_ps(v59, v59, 255), (__m128)d.v3));
        mat.v0 = v78;
        mat.v1 = (UFG::qVector4)_mm_add_ps(
                                  _mm_add_ps(
                                    _mm_add_ps(
                                      _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v60, v60, 0), (__m128)d.v0), (__m128)0i64),
                                      _mm_mul_ps(_mm_shuffle_ps(v60, v60, 85), (__m128)d.v1)),
                                    _mm_mul_ps(_mm_shuffle_ps(v60, v60, 170), (__m128)d.v2)),
                                  _mm_mul_ps(_mm_shuffle_ps(v60, v60, 255), (__m128)d.v3));
        mat.v2 = (UFG::qVector4)_mm_add_ps(
                                  _mm_add_ps(
                                    _mm_add_ps(
                                      _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v76, v76, 0), (__m128)d.v0), (__m128)0i64),
                                      _mm_mul_ps(_mm_shuffle_ps(v76, v76, 85), (__m128)d.v1)),
                                    _mm_mul_ps(_mm_shuffle_ps(v76, v76, 170), (__m128)d.v2)),
                                  _mm_mul_ps(_mm_shuffle_ps(v76, v76, 255), (__m128)d.v3));
        mat.v3 = (UFG::qVector4)_mm_add_ps(
                                  _mm_add_ps(
                                    _mm_add_ps(
                                      _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v77, v77, 0), (__m128)d.v0), (__m128)0i64),
                                      _mm_mul_ps(_mm_shuffle_ps(v77, v77, 85), (__m128)d.v1)),
                                    _mm_mul_ps(_mm_shuffle_ps(v77, v77, 170), (__m128)d.v2)),
                                  _mm_mul_ps(_mm_shuffle_ps(v77, v77, 255), (__m128)d.v3));
        if ( v16 < v194 )
        {
          v79 = _mm_cvtps_epi32(
                  _mm_cvtepi32_ps(
                    _mm_cvtps_epi32(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps((__m128)v78, _mm_shuffle_ps((__m128)v78, v11, 250), 148), v213),
                        v213))));
          _mm_store_si128((__m128i *)&v195, v79);
          do
          {
            v80 = v219;
            v81 = 0;
            v82 = &v234;
            v83 = &v242;
            v84 = 0i64;
            do
            {
              v85 = v81++ + v16;
              v86 = *(unsigned __int16 *)(v80 + 2 * v85);
              ++v82;
              v84 += 16i64;
              v87 = 3 * v86;
              v88 = (unsigned int)(8 * v86);
              v89 = v88 + *((_QWORD *)v13 + 6);
              v90 = v88 + *((_QWORD *)v13 + 2);
              v91 = *((_QWORD *)v13 + 1) + (unsigned int)(8 * v87);
              v92 = (v88 + *((_QWORD *)v13 + 2)) & 0xFFFFFFFFFFFFFFF0ui64;
              v93 = (v88 + *((_QWORD *)v13 + 6)) & 0xFFFFFFFFFFFFFFF0ui64;
              v83 += 32;
              v94 = (__m128 *)(v91 & 0xFFFFFFFFFFFFFFF0ui64 ^ ((unsigned __int8)v91 ^ v91 & 0xF0) & 0xF);
              v95 = *v94;
              v96 = v94[1];
              v97 = *(_OWORD *)(v92 ^ ((unsigned __int8)v90 ^ (unsigned __int8)v92) & 0xF);
              v98 = *(_OWORD *)(v93 ^ ((unsigned __int8)v89 ^ (unsigned __int8)v93) & 0xF);
              *((__m128 *)v83 - 3) = *v94;
              *((__m128 *)v83 - 2) = v96;
              *(__m128 *)((char *)&v236 + v84) = (__m128)v97;
              *(__int128 *)((char *)&v210 + v84) = v98;
              v99 = _mm_packs_epi32(v79, v79);
              *((_DWORD *)v83 - 7) = (unsigned __int128)_mm_packus_epi16(v99, v99);
              v100 = *(unsigned __int8 *)v92 << 6;
              v101 = _mm_shuffle_ps(v95, _mm_shuffle_ps(v95, v11, 250), 148);
              v82[-1] = _mm_add_ps(
                          _mm_add_ps(
                            _mm_add_ps(
                              _mm_add_ps(
                                _mm_mul_ps(_mm_shuffle_ps(v101, v101, 0), *(__m128 *)((char *)&v248 + v100)),
                                (__m128)0i64),
                              _mm_mul_ps(_mm_shuffle_ps(v101, v101, 85), *(__m128 *)((char *)&v249 + v100))),
                            _mm_mul_ps(_mm_shuffle_ps(v101, v101, 170), *(__m128 *)((char *)&v250 + v100))),
                          _mm_mul_ps(_mm_shuffle_ps(v101, v101, 255), *(__m128 *)((char *)&v251 + v100)));
              v79 = _mm_load_si128((const __m128i *)&v195);
            }
            while ( v81 < 3 );
            LODWORD(inpts.x) = v234.m128_i32[0];
            v197 = v235.m128_f32[0];
            v200 = v236.m128_f32[0];
            v102 = _mm_shuffle_ps(v236, v236, 85);
            v103 = _mm_shuffle_ps(v236, v236, 170);
            v201 = v102.m128_f32[0];
            v202 = v103.m128_f32[0];
            v217 = v102;
            v216 = v103;
            LODWORD(v104) = (unsigned __int128)_mm_shuffle_ps(v235, v235, 85);
            LODWORD(v105) = (unsigned __int128)_mm_shuffle_ps(v235, v235, 170);
            v198 = v104;
            LODWORD(v106) = (unsigned __int128)_mm_shuffle_ps(v234, v234, 85);
            inpts.y = v106;
            v199 = v105;
            v208 = _mm_shuffle_ps(v234, v234, 170);
            LODWORD(inpts.z) = v208.m128_i32[0];
            v107 = (float)((float)(v104 - v106) * (float)(v103.m128_f32[0] - v105))
                 - (float)((float)(v105 - v208.m128_f32[0]) * (float)(v102.m128_f32[0] - v104));
            v108 = (float)((float)(v235.m128_f32[0] - v234.m128_f32[0]) * (float)(v102.m128_f32[0] - v104))
                 - (float)((float)(v104 - v106) * (float)(v236.m128_f32[0] - v235.m128_f32[0]));
            v109 = (float)((float)(v105 - v208.m128_f32[0]) * (float)(v236.m128_f32[0] - v235.m128_f32[0]))
                 - (float)((float)(v235.m128_f32[0] - v234.m128_f32[0]) * (float)(v103.m128_f32[0] - v105));
            v110 = (float)((float)(v109 * v109) + (float)(v107 * v107)) + (float)(v108 * v108);
            if ( v110 == 0.0 )
              v111 = 0.0;
            else
              v111 = 1.0 / fsqrt(v110);
            v23 = v210;
            if ( (float)((float)((float)(*((float *)&v230 + 1)
                                       * (float)((float)((float)((float)(v111 * v109) * v209.v1.y)
                                                       + (float)((float)(v111 * v107) * v209.v0.y))
                                               + (float)((float)(v111 * v108) * v209.v2.y)))
                               + (float)(*(float *)&v230
                                       * (float)((float)((float)((float)(v111 * v109) * v209.v1.x)
                                                       + (float)((float)(v111 * v107) * v209.v0.x))
                                               + (float)((float)(v111 * v108) * v209.v2.x))))
                       + (float)(*((float *)&v230 + 2)
                               * (float)((float)((float)((float)(v111 * v109) * v209.v1.z)
                                               + (float)((float)(v111 * v107) * v209.v0.z))
                                       + (float)((float)(v111 * v108) * v209.v2.z)))) < *(float *)(v203 + 224) )
            {
              v199 = v105 - mat.v3.z;
              v202 = v216.m128_f32[0] - mat.v3.z;
              inpts.x = v234.m128_f32[0] - mat.v3.x;
              inpts.y = v106 - mat.v3.y;
              inpts.z = v208.m128_f32[0] - mat.v3.z;
              v197 = v235.m128_f32[0] - mat.v3.x;
              v198 = v104 - mat.v3.y;
              v200 = v236.m128_f32[0] - mat.v3.x;
              v201 = v217.m128_f32[0] - mat.v3.y;
              v112 = ClipToSlab(&inpts, &outpts, 3u, &mat, width, 0);
              v113 = ClipToSlab(&outpts, &v246, v112, &mat, width, 1u);
              if ( ClipToSlab(&v246, &v247, v113, &mat, v206, 2u) )
              {
                v114 = *(_DWORD *)(v23 + 1412);
                if ( v114 < 0x1D )
                {
                  UFG::qMemCopy((void *)(v23 + 44i64 * v114), &source, 0x18u);
                  UFG::qMemCopy((void *)(v23 + 44i64 * (unsigned int)(*(_DWORD *)(v23 + 1412) + 1)), &v243, 0x18u);
                  UFG::qMemCopy((void *)(v23 + 44i64 * (unsigned int)(*(_DWORD *)(v23 + 1412) + 2)), &v244, 0x18u);
                  UFG::qMemCopy((void *)(44i64 * *(unsigned int *)(v23 + 1412) + v23 + 24), &v237, 8u);
                  UFG::qMemCopy((void *)(v23 + 44i64 * (unsigned int)(*(_DWORD *)(v23 + 1412) + 1) + 24), &v238, 8u);
                  UFG::qMemCopy((void *)(v23 + 44i64 * (unsigned int)(*(_DWORD *)(v23 + 1412) + 2) + 24), &v239, 8u);
                  UFG::qMemCopy((void *)(44i64 * *(unsigned int *)(v23 + 1412) + v23 + 32), &m, 8u);
                  UFG::qMemCopy((void *)(v23 + 44i64 * (unsigned int)(*(_DWORD *)(v23 + 1412) + 1) + 32), &m.v1, 8u);
                  UFG::qMemCopy((void *)(v23 + 44i64 * (unsigned int)(*(_DWORD *)(v23 + 1412) + 2) + 32), &m.v2, 8u);
                  v115 = 0;
                  v116 = &inpts.z;
                  v117 = mat.v1.z;
                  v118 = mat.v1.y;
                  v119 = 1.0 / (float)(width * 2.0);
                  v120 = mat.v1.x;
                  v121 = mat.v0.z;
                  v122 = mat.v0.y;
                  v123 = mat.v0.x;
                  do
                  {
                    v124 = (float)((float)((float)((float)(v120 * *(v116 - 2)) + (float)(v118 * *(v116 - 1)))
                                         + (float)(v117 * *v116))
                                 * v119)
                         + 0.5;
                    v192 = (float)((float)((float)((float)(v123 * *(v116 - 2)) + (float)(v122 * *(v116 - 1)))
                                         + (float)(v121 * *v116))
                                 * v119)
                         + 0.5;
                    v125 = LODWORD(v192) & 0x7FFFFFFF;
                    v126 = (LODWORD(v192) >> 16) & 0x8000;
                    if ( (LODWORD(v192) & 0x7FFFFFFFu) <= 0x47FFEFFF )
                    {
                      if ( v125 >= 0x38800000 )
                        v128 = v125 - 939524096;
                      else
                        v128 = (LODWORD(v192) & 0x7FFFFF | 0x800000u) >> (113 - (v125 >> 23));
                      v127 = ((((v128 >> 13) & 1) + v128 + 4095) >> 13) | v126;
                    }
                    else
                    {
                      v127 = v126 | 0x7FFF;
                    }
                    v193 = (float)((float)((float)((float)(v120 * *(v116 - 2)) + (float)(v118 * *(v116 - 1)))
                                         + (float)(v117 * *v116))
                                 * v119)
                         + 0.5;
                    *(_WORD *)(44i64 * (v115 + *(_DWORD *)(v23 + 1412)) + v23 + 40) = v127;
                    v129 = LODWORD(v124) & 0x7FFFFFFF;
                    v130 = (LODWORD(v124) >> 16) & 0x8000;
                    if ( (LODWORD(v124) & 0x7FFFFFFFu) <= 0x47FFEFFF )
                    {
                      if ( v129 >= 0x38800000 )
                        v132 = v129 - 939524096;
                      else
                        v132 = (LODWORD(v193) & 0x7FFFFF | 0x800000u) >> (113 - (v129 >> 23));
                      v131 = ((((v132 >> 13) & 1) + v132 + 4095) >> 13) | v130;
                    }
                    else
                    {
                      v131 = v130 | 0x7FFF;
                    }
                    v116 += 3;
                    v133 = v115++ + *(_DWORD *)(v23 + 1412);
                    *(_WORD *)(44 * v133 + v23 + 42) = v131;
                  }
                  while ( v115 < 3 );
                  *(_DWORD *)(v23 + 1412) += 3;
                  v13 = v252;
                }
              }
            }
            v79 = _mm_load_si128((const __m128i *)&v195);
            v11 = v207;
            v16 += 3;
          }
          while ( v16 < v194 );
          v5 = v215;
          v8 = v223;
          v9 = v222;
        }
        break;
      }
    }
    v53 = v213;
    v52 = v227;
    v55 = (__m128)v214;
    v10 = v205;
    *(_BYTE *)(v23 + 1408) = 1;
    v54 = v212;
  }
  if ( !v189 )
  {
    v134 = *(__m128 *)(v13 + 56);
    v195 = *(__m128 *)(v13 + 56);
    if ( v10 )
    {
      v135 = v204;
      do
      {
        v136 = 1024;
        v137 = v5;
        v138 = (__m128 *)v8;
        v139 = (_OWORD *)v135;
        v140 = (_OWORD *)v9;
        if ( v10 < 0x400 )
          v136 = v10;
        v10 -= v136;
        v141 = 24 * v136;
        v5 += v141;
        v8 += v141;
        v142 = 8 * v136;
        v135 += v142;
        v9 += v142;
        v204 = v135;
        if ( v136 )
        {
          v143 = v220;
          v144 = v137 - (_QWORD)v138;
          v145 = v136;
          v146 = _mm_shuffle_ps(v134, v134, 0);
          v217 = v146;
          v216 = _mm_and_ps(v52, v207);
          do
          {
            v147 = *(__m128 *)v139;
            v148 = *(__m128 *)v140;
            v149 = v138[1];
            v150 = (unsigned __int8 *)v140;
            v140 = (_OWORD *)((char *)v140 + 8);
            v139 = (_OWORD *)((char *)v139 + 8);
            v151 = (unsigned __int64)*v150 << 6;
            v152 = *(__m128 *)((char *)&v248 + v151);
            v153 = *(__m128 *)((char *)&v249 + v151);
            v154 = *(__m128 *)((char *)&v250 + v151);
            v155 = _mm_add_ps(
                     _mm_mul_ps(
                       _mm_add_ps(
                         _mm_mul_ps(
                           _mm_add_ps(
                             _mm_cvtepi32_ps((__m128i)_mm_and_ps(
                                                        (__m128)_mm_sub_epi32(
                                                                  (__m128i)_mm_shuffle_ps(v148, v148, 85),
                                                                  v226),
                                                        v55)),
                             v221),
                           v224),
                         (__m128)0i64),
                       v233),
                     (__m128)0i64);
            v156 = _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(
                           _mm_shuffle_ps(v155, v155, 85),
                           _mm_shuffle_ps(*(__m128 *)(v143 + 4i64 * v150[1]), *(__m128 *)(v143 + 4i64 * v150[1]), 0)),
                         (__m128)0i64),
                       _mm_mul_ps(
                         _mm_shuffle_ps(v155, v155, 170),
                         _mm_shuffle_ps(*(__m128 *)(v143 + 4i64 * v150[2]), *(__m128 *)(v143 + 4i64 * v150[2]), 0))),
                     v146);
            v157 = (__m128i)_mm_and_ps((__m128)_mm_sub_epi32((__m128i)_mm_shuffle_ps(v149, v149, 0), v226), v55);
            v158 = _mm_min_ps(v156, v207);
            v159 = _mm_mul_ps(
                     _mm_cvtepi32_ps((__m128i)_mm_and_ps(_mm_shuffle_ps(v147, _mm_shuffle_ps(v147, v212, 85), 149), v55)),
                     v224);
            v160 = _mm_add_ps(
                     _mm_mul_ps(
                       _mm_sub_ps(
                         _mm_add_ps(
                           _mm_mul_ps(
                             _mm_add_ps(
                               _mm_cvtepi32_ps((__m128i)_mm_and_ps(
                                                          (__m128)_mm_sub_epi32(
                                                                    (__m128i)_mm_shuffle_ps(v149, v149, 85),
                                                                    v226),
                                                          v55)),
                               v221),
                             v224),
                           (__m128)0i64),
                         v53),
                       v225),
                     (__m128)0i64);
            v161 = _mm_mul_ps(
                     _mm_sub_ps(
                       _mm_add_ps(
                         _mm_mul_ps(
                           _mm_cvtepi32_ps((__m128i)_mm_and_ps(
                                                      _mm_shuffle_ps(v147, _mm_shuffle_ps(v147, v54, 0), 144),
                                                      v55)),
                           v224),
                         (__m128)0i64),
                       v213),
                     v232);
            v162 = _mm_shuffle_ps(v160, v160, 255);
            v163 = _mm_shuffle_ps(v160, _mm_shuffle_ps(v160, (__m128)0i64, 250), 148);
            v164 = _mm_add_ps(
                     _mm_add_ps(_mm_mul_ps(_mm_add_ps(v161, (__m128)0i64), v158), (__m128)0i64),
                     _mm_shuffle_ps(*v138, _mm_shuffle_ps(*v138, v207, 250), 148));
            v165 = _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(
                         _mm_add_ps(_mm_mul_ps(_mm_sub_ps(_mm_add_ps(v159, (__m128)0i64), v213), v225), (__m128)0i64),
                         v158),
                       (__m128)0i64),
                     _mm_add_ps(
                       _mm_mul_ps(
                         _mm_sub_ps(
                           _mm_add_ps(_mm_mul_ps(_mm_add_ps(_mm_cvtepi32_ps(v157), v221), v224), (__m128)0i64),
                           v213),
                         v225),
                       (__m128)0i64));
            v166 = _mm_shuffle_ps(v165, v165, 0);
            v167 = _mm_shuffle_ps(v165, v165, 85);
            v168 = _mm_shuffle_ps(v165, v165, 170);
            v169 = _mm_add_ps(
                     _mm_mul_ps(
                       _mm_rsqrt_ps(
                         _mm_add_ps(
                           _mm_add_ps(_mm_add_ps(_mm_mul_ps(v166, v166), (__m128)0i64), _mm_mul_ps(v167, v167)),
                           _mm_mul_ps(v168, v168))),
                       v165),
                     (__m128)0i64);
            v170 = _mm_shuffle_ps(v169, v169, 0);
            v171 = _mm_shuffle_ps(v169, v169, 85);
            v172 = _mm_shuffle_ps(v169, v169, 170);
            v173 = _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v163, v163, 0), v170), (__m128)0i64),
                       _mm_mul_ps(_mm_shuffle_ps(v163, v163, 85), v171)),
                     _mm_mul_ps(_mm_shuffle_ps(v163, v163, 170), v172));
            v174 = _mm_sub_ps(
                     v163,
                     _mm_sub_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v169, v169, 210), _mm_shuffle_ps(v173, v173, 201)),
                         (__m128)0i64),
                       _mm_mul_ps(_mm_shuffle_ps(v169, v169, 201), _mm_shuffle_ps(v173, v173, 210))));
            v175 = _mm_shuffle_ps(v174, v174, 0);
            v176 = _mm_shuffle_ps(v174, v174, 85);
            v177 = _mm_shuffle_ps(v174, v174, 170);
            v178 = _mm_add_ps(
                     _mm_mul_ps(
                       _mm_rsqrt_ps(
                         _mm_add_ps(
                           _mm_add_ps(_mm_add_ps(_mm_mul_ps(v175, v175), (__m128)0i64), _mm_mul_ps(v176, v176)),
                           _mm_mul_ps(v177, v177))),
                       v174),
                     (__m128)0i64);
            v146 = v217;
            v138 = (__m128 *)((char *)v138 + 24);
            v179 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v170, v152), (__m128)0i64), _mm_mul_ps(v171, v153));
            v180 = _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v164, v164, 0), v152), (__m128)0i64),
                         _mm_mul_ps(_mm_shuffle_ps(v164, v164, 85), v153)),
                       _mm_mul_ps(_mm_shuffle_ps(v164, v164, 170), v154)),
                     _mm_mul_ps(_mm_shuffle_ps(v164, v164, 255), *(__m128 *)((char *)&v251 + v151)));
            v53 = v213;
            v181 = _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v178, v178, 0), v152), (__m128)0i64),
                         _mm_mul_ps(_mm_shuffle_ps(v178, v178, 85), v153)),
                       _mm_mul_ps(_mm_shuffle_ps(v178, v178, 170), v154)),
                     _mm_mul_ps(_mm_shuffle_ps(v178, v178, 255), (__m128)0i64));
            v54 = v212;
            v182 = _mm_cvtps_epi32(
                     _mm_add_ps(
                       _mm_mul_ps(
                         _mm_add_ps(
                           _mm_add_ps(v179, _mm_mul_ps(v172, v154)),
                           _mm_mul_ps(_mm_shuffle_ps(v169, v169, 255), (__m128)0i64)),
                         v213),
                       v213));
            *(__m128 *)((char *)v138 + v144 - 24) = _mm_shuffle_ps(v180, _mm_shuffle_ps(v180, v156, 250), 148);
            v183 = _mm_cvtps_epi32(_mm_cvtepi32_ps(v182));
            v184 = _mm_packs_epi32(v183, v183);
            v185 = _mm_andnot_ps(v207, _mm_cmpltps(v162, (__m128)0i64));
            v55 = (__m128)v214;
            v186 = _mm_or_ps(v185, v216);
            *(_DWORD *)((char *)&v138->m128_u64[-1] + v144) = (unsigned __int128)_mm_packus_epi16(v184, v184);
            v187 = _mm_cvtps_epi32(_mm_cvtepi32_ps(_mm_cvtps_epi32(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v181, _mm_shuffle_ps(v181, v186, 250), 148), v53), v53))));
            v188 = _mm_packs_epi32(v187, v187);
            *(_DWORD *)((char *)v138->m128_u64 + v144 - 4) = (unsigned __int128)_mm_packus_epi16(v188, v188);
            --v145;
          }
          while ( v145 );
          v134 = v195;
          v135 = v204;
        }
        v52 = v227;
        v55 = (__m128)v214;
        v54 = v212;
      }
      while ( v10 );
    }
  }
}ps_epi32(_mm_cvtepi32_ps(v182));
            v184 = _mm_packs_epi32(v183, v183);
            v185 = _mm_andnot_ps(v207, _mm_cmpltps(v162, (__m128)0i64));
            v55 = (__m128)v214;
            v186 = _mm_or_ps(v185, v216);
            *(_DWORD *)((char *)&v138->m128_u64[-1] + 

// File Line: 27
// RVA: 0x76240
void __fastcall SkinVehicleGlassBufferTask(int worker_id, UFG::qMemoryStreamer *memory_streamer, void *param0, void *param1)
{
  __int64 v4; // rdx
  __int64 v5; // rdi
  __int64 v6; // rax
  int v7; // er10
  __int64 v8; // r14
  __int64 v9; // r12
  unsigned int v10; // er9
  __m128 v11; // xmm11
  bool v12; // zf
  char *v13; // r15
  __int64 v14; // rdx
  unsigned int v15; // er8
  unsigned int v16; // er13
  unsigned int v17; // er10
  bool v18; // si
  bool v19; // cf
  unsigned int v20; // er11
  unsigned __int8 *v21; // r10
  __int64 v22; // rax
  __int64 v23; // rbx
  __m128 *v24; // rdx
  __int64 v25; // r11
  int v26; // er8
  __m128 *v27; // rcx
  __m128 *v28; // rax
  __m128 v29; // xmm5
  __m128 v30; // xmm11
  __m128 v31; // xmm12
  __m128 v32; // xmm13
  __m128 v33; // xmm4
  __m128 v34; // xmm3
  __m128 v35; // xmm8
  __m128 v36; // xmm2
  __m128 v37; // xmm5
  __m128 v38; // xmm1
  __m128 v39; // xmm7
  __m128 v40; // xmm6
  __m128 v41; // xmm8
  __m128 v42; // xmm10
  __m128 v43; // xmm4
  __m128 v44; // xmm5
  __m128 v45; // xmm10
  __m128 v46; // xmm4
  __m128 v47; // xmm5
  __m128 v48; // xmm4
  __m128 v49; // xmm5
  __m128 v50; // xmm10
  __m128 v51; // xmm14
  __m128 v52; // xmm1
  __m128 v53; // xmm10
  __m128 v54; // xmm4
  __m128 v55; // xmm5
  UFG::qVector4 v56; // xmm0
  UFG::qVector4 v57; // xmm1
  unsigned int v58; // xmm2_4
  __m128 v59; // xmm8
  __m128 v60; // xmm9
  __int128 v61; // xmm10
  __int128 v62; // xmm12
  float v63; // xmm6_4
  UFG::qVector4 v64; // xmm0
  UFG::qVector4 v65; // xmm1
  int v66; // xmm2_4
  unsigned int v67; // esi
  unsigned int v68; // ecx
  __int64 v69; // rax
  double v70; // xmm3_8
  float v71; // xmm2_4
  __m128 v72; // xmm5
  __m128 v73; // xmm4
  float v74; // xmm1_4
  float v75; // xmm1_4
  float v76; // xmm1_4
  __m128 v77; // xmm5
  __m128 v78; // xmm10
  UFG::qVector4 v79; // xmm12
  __m128i v80; // xmm3
  unsigned __int64 v81; // rbx
  __m128 *v82; // r12
  __int64 v83; // r14
  char *v84; // rdi
  __int64 v85; // rax
  int v86; // edx
  int v87; // er8
  __int64 v88; // rcx
  __int64 v89; // r9
  __int64 v90; // rdx
  __int64 v91; // r8
  unsigned __int64 v92; // r11
  unsigned __int64 v93; // r10
  __m128 *v94; // rcx
  __m128 v95; // xmm4
  __m128 v96; // xmm2
  __int128 v97; // xmm1
  __int128 v98; // xmm0
  __m128i v99; // xmm0
  __int64 v100; // rcx
  __m128 v101; // xmm4
  __m128 v102; // xmm1
  __m128 v103; // xmm2
  float v104; // xmm12_4
  float v105; // xmm13_4
  float v106; // xmm14_4
  float v107; // xmm5_4
  float v108; // xmm8_4
  float v109; // xmm9_4
  float v110; // xmm3_4
  float v111; // xmm6_4
  unsigned int v112; // eax
  unsigned int v113; // eax
  unsigned int v114; // eax
  unsigned int v115; // er9
  float *v116; // r10
  float v117; // xmm9_4
  float v118; // xmm10_4
  float v119; // xmm7_4
  float v120; // xmm11_4
  float v121; // xmm12_4
  float v122; // xmm13_4
  float v123; // xmm14_4
  float v124; // xmm6_4
  unsigned int v125; // edx
  int v126; // er8
  __int16 v127; // r8
  unsigned int v128; // edx
  unsigned int v129; // edx
  int v130; // er8
  __int16 v131; // r8
  unsigned int v132; // edx
  __int64 v133; // rcx
  __m128 v134; // xmm0
  __int64 v135; // r8
  unsigned int v136; // edx
  __int64 v137; // r10
  __m128 *v138; // r11
  _OWORD *v139; // rsi
  _OWORD *v140; // rbx
  __int64 v141; // rcx
  __int64 v142; // rcx
  __int64 v143; // r15
  __int64 v144; // r10
  __int64 v145; // r14
  __m128 v146; // xmm9
  __m128 v147; // xmm7
  __m128 v148; // xmm1
  unsigned __int8 *v149; // rdx
  __m128 v150; // xmm6
  unsigned __int64 v151; // r8
  __m128 v152; // xmm12
  __m128 v153; // xmm13
  __m128 v154; // xmm14
  __m128 v155; // xmm0
  __m128 v156; // xmm5
  __m128 v157; // xmm9
  __m128 v158; // xmm11
  __m128 v159; // xmm9
  __m128 v160; // xmm10
  __m128 v161; // xmm3
  __m128 v162; // xmm2
  __m128 v163; // xmm0
  __m128 v164; // xmm1
  __m128 v165; // xmm6
  __m128 v166; // xmm7
  __m128 v167; // xmm3
  __m128 v168; // xmm5
  __m128 v169; // xmm2
  __m128 v170; // xmm9
  __m128 v171; // xmm2
  __m128 v172; // xmm0
  __m128 v173; // xmm1
  __m128 v174; // xmm4
  __m128 v175; // xmm7
  __m128 v176; // xmm2
  __m128 v177; // xmm3
  __m128 v178; // xmm7
  __m128i v179; // xmm2
  __m128i v180; // xmm2
  __m128 v181; // xmm1
  __m128i v182; // xmm2
  __m128i v183; // xmm2
  bool v184; // [rsp+30h] [rbp-D0h]
  unsigned int v185; // [rsp+34h] [rbp-CCh]
  float width; // [rsp+34h] [rbp-CCh]
  float v187; // [rsp+38h] [rbp-C8h]
  float v188; // [rsp+38h] [rbp-C8h]
  unsigned int v189; // [rsp+40h] [rbp-C0h]
  __m128 v190; // [rsp+50h] [rbp-B0h]
  UFG::qVector3 inpts; // [rsp+60h] [rbp-A0h]
  float v192; // [rsp+6Ch] [rbp-94h]
  float v193; // [rsp+70h] [rbp-90h]
  float v194; // [rsp+74h] [rbp-8Ch]
  float v195; // [rsp+78h] [rbp-88h]
  float v196; // [rsp+7Ch] [rbp-84h]
  float v197; // [rsp+80h] [rbp-80h]
  __int64 v198; // [rsp+88h] [rbp-78h]
  __int64 v199; // [rsp+90h] [rbp-70h]
  float v200; // [rsp+98h] [rbp-68h]
  unsigned int v201; // [rsp+9Ch] [rbp-64h]
  __int64 v202; // [rsp+A0h] [rbp-60h]
  __m128 v203; // [rsp+B0h] [rbp-50h]
  __m128 v204; // [rsp+C0h] [rbp-40h]
  UFG::qMatrix44 v205; // [rsp+D0h] [rbp-30h]
  __int128 v206; // [rsp+110h] [rbp+10h]
  UFG::qMatrix44 m; // [rsp+120h] [rbp+20h]
  __m128 v208; // [rsp+160h] [rbp+60h]
  __m128 v209; // [rsp+170h] [rbp+70h]
  __m128 v210; // [rsp+180h] [rbp+80h]
  __m128 v211; // [rsp+190h] [rbp+90h]
  __m128 v212; // [rsp+1A0h] [rbp+A0h]
  __m128 v213; // [rsp+1B0h] [rbp+B0h]
  __int64 v214; // [rsp+1C0h] [rbp+C0h]
  __int64 v215; // [rsp+1C8h] [rbp+C8h]
  __int64 v216; // [rsp+1D0h] [rbp+D0h]
  UFG::qMatrix44 mat; // [rsp+1E0h] [rbp+E0h]
  unsigned __int64 v218; // [rsp+220h] [rbp+120h]
  __m128i v219; // [rsp+230h] [rbp+130h]
  __m128 v220; // [rsp+240h] [rbp+140h]
  __m128 v221; // [rsp+250h] [rbp+150h]
  __m128 v222; // [rsp+260h] [rbp+160h]
  __int128 v223; // [rsp+270h] [rbp+170h]
  __m128 v224; // [rsp+280h] [rbp+180h]
  __int128 v225; // [rsp+290h] [rbp+190h]
  __int128 v226; // [rsp+2A0h] [rbp+1A0h]
  __m128 v227; // [rsp+2B0h] [rbp+1B0h]
  __m128 v228; // [rsp+2C0h] [rbp+1C0h]
  __m128 v229; // [rsp+2D0h] [rbp+1D0h]
  __m128 v230; // [rsp+2E0h] [rbp+1E0h]
  __m128 v231; // [rsp+2F0h] [rbp+1F0h]
  char v232; // [rsp+300h] [rbp+200h]
  char v233; // [rsp+310h] [rbp+210h]
  char v234; // [rsp+320h] [rbp+220h]
  UFG::qMatrix44 d; // [rsp+330h] [rbp+230h]
  char source; // [rsp+370h] [rbp+270h]
  char v237; // [rsp+380h] [rbp+280h]
  char v238; // [rsp+390h] [rbp+290h]
  char v239; // [rsp+3B0h] [rbp+2B0h]
  UFG::qVector3 outpts; // [rsp+3D0h] [rbp+2D0h]
  UFG::qVector3 v241; // [rsp+550h] [rbp+450h]
  UFG::qVector3 v242; // [rsp+6D0h] [rbp+5D0h]
  __int128 v243; // [rsp+850h] [rbp+750h]
  __int128 v244; // [rsp+860h] [rbp+760h]
  __int128 v245; // [rsp+870h] [rbp+770h]
  __int128 v246; // [rsp+880h] [rbp+780h]
  char *v247; // [rsp+4930h] [rbp+4830h]

  v247 = (char *)param0;
  v4 = *((_QWORD *)param0 + 9);
  v5 = *(_QWORD *)param0;
  v6 = *((_QWORD *)param0 + 3);
  v7 = *((_DWORD *)param0 + 15);
  v8 = *((_QWORD *)param0 + 1);
  v9 = *((_QWORD *)param0 + 2);
  v10 = *((_DWORD *)param0 + 16);
  v11 = gVmxOne_4;
  v12 = *(_QWORD *)param0 == 0i64;
  v202 = *((_QWORD *)param0 + 6);
  v13 = (char *)param0;
  v203 = gVmxOne_4;
  v184 = v12;
  v214 = v4;
  v14 = *((_QWORD *)param0 + 14);
  v15 = *((unsigned __int16 *)param0 + 20);
  v218 = v6 & 0xFFFFFFFFFFFFFFF0ui64;
  v215 = v5;
  v199 = v8;
  v16 = (unsigned int)(v6 & 0xF) >> 1;
  v216 = v9;
  v17 = v16 + v7;
  v18 = v14 != 0;
  v19 = v17 < 0x61A8;
  v12 = v17 == 25000;
  v20 = 2 * v17;
  v189 = v17;
  v21 = (unsigned __int8 *)*((_QWORD *)v13 + 13);
  if ( !v19 && !v12 )
    v18 = 0;
  v201 = v10;
  v185 = v20;
  v22 = 0i64;
  v198 = 0i64;
  v23 = 0i64;
  *(_QWORD *)&v206 = 0i64;
  if ( v15 )
  {
    v24 = (__m128 *)&v245;
    v25 = v15;
    do
    {
      v26 = *v21;
      if ( v26 == 255 )
      {
        v24[-2] = gVmxIdentity0_4;
        v24[-1] = gVmxIdentity1_4;
        *v24 = gVmxIdentity2_4;
        v24[1] = gVmxIdentity3_4;
      }
      else
      {
        v27 = (__m128 *)(*((_QWORD *)v13 + 4) + (unsigned int)(48 * v26));
        v28 = (__m128 *)(*((_QWORD *)v13 + 12) + (unsigned int)(v26 << 6));
        v29 = v27[1];
        v30 = v28[1];
        v31 = v28[2];
        v32 = v28[3];
        v33 = _mm_shuffle_ps(v27[1], v29, 255);
        v34 = _mm_add_ps(v29, v29);
        v35 = _mm_shuffle_ps(v27[1], v29, 201);
        v36 = _mm_shuffle_ps(v34, v34, 210);
        v37 = _mm_shuffle_ps(v29, v29, 210);
        v38 = _mm_shuffle_ps(v34, v34, 201);
        v39 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v38, v33), (__m128)0i64), _mm_mul_ps(v37, v34));
        v40 = _mm_sub_ps(_mm_sub_ps(v203, _mm_mul_ps(v38, v35)), _mm_mul_ps(v36, v37));
        v41 = _mm_sub_ps(_mm_add_ps(_mm_mul_ps(v35, v34), (__m128)0i64), _mm_mul_ps(v36, v33));
        v42 = _mm_shuffle_ps(_mm_shuffle_ps(v39, v41, 80), v41, 233);
        v43 = _mm_shuffle_ps(_mm_shuffle_ps(v40, v39, 80), v39, 233);
        v44 = _mm_shuffle_ps(_mm_shuffle_ps(v41, v40, 80), v40, 233);
        v45 = _mm_shuffle_ps(v42, _mm_shuffle_ps(v40, v42, 250), 148);
        v46 = _mm_shuffle_ps(v43, _mm_shuffle_ps(v41, v43, 250), 148);
        v47 = _mm_shuffle_ps(v44, _mm_shuffle_ps(v39, v44, 250), 148);
        v48 = _mm_shuffle_ps(v46, _mm_shuffle_ps(v46, (__m128)0i64, 250), 148);
        v49 = _mm_shuffle_ps(v47, _mm_shuffle_ps(v47, (__m128)0i64, 250), 148);
        v50 = _mm_shuffle_ps(v45, _mm_shuffle_ps(v45, (__m128)0i64, 250), 148);
        v51 = _mm_shuffle_ps(*v27, _mm_shuffle_ps(*v27, v203, 250), 148);
        v24[-2] = _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(*v28, *v28, 0), v48), (__m128)0i64),
                        _mm_mul_ps(_mm_shuffle_ps(*v28, *v28, 85), v49)),
                      _mm_mul_ps(_mm_shuffle_ps(*v28, *v28, 170), v50)),
                    _mm_mul_ps(_mm_shuffle_ps(*v28, *v28, 255), v51));
        v24[-1] = _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v30, v30, 0), v48), (__m128)0i64),
                        _mm_mul_ps(_mm_shuffle_ps(v30, v30, 85), v49)),
                      _mm_mul_ps(_mm_shuffle_ps(v30, v30, 170), v50)),
                    _mm_mul_ps(_mm_shuffle_ps(v30, v30, 255), v51));
        *v24 = _mm_add_ps(
                 _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v31, v31, 0), v48), (__m128)0i64),
                     _mm_mul_ps(_mm_shuffle_ps(v31, v31, 85), v49)),
                   _mm_mul_ps(_mm_shuffle_ps(v31, v31, 170), v50)),
                 _mm_mul_ps(_mm_shuffle_ps(v31, v31, 255), v51));
        v24[1] = _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v32, v32, 0), v48), (__m128)0i64),
                       _mm_mul_ps(_mm_shuffle_ps(v32, v32, 85), v49)),
                     _mm_mul_ps(_mm_shuffle_ps(v32, v32, 170), v50)),
                   _mm_mul_ps(_mm_shuffle_ps(v32, v32, 255), v51));
      }
      v24 += 4;
      ++v21;
      --v25;
    }
    while ( v25 );
    v11 = v203;
    v14 = *((_QWORD *)v13 + 14);
    v20 = v185;
    v22 = 0i64;
  }
  if ( v18 )
  {
    v23 = *((_QWORD *)v13 + 17);
    v22 = v14;
    v198 = v14;
    *(_QWORD *)&v206 = v23;
  }
  v52 = gVmxMinusOne_2;
  v53 = gVmx127_2;
  v54 = (__m128)gVmxi127_2;
  v55 = gVmxUnpackShift_2;
  v221 = gVmxOneOver127_2;
  v220 = gVmxMinusOne_2;
  v208 = gVmx127_2;
  v228 = gVmxOneOver255_2;
  v210 = (__m128)gVmxi127_2;
  v227 = gVmxOneOver511_2;
  v209 = gVmxUnpackShift_2;
  _mm_store_si128(&v219, gVmxUnpackBias_2);
  v222 = (__m128)gVmxUnpackMask_2;
  v211 = gVmxUnpackUnbias_2;
  if ( v18 && v20 <= 0xC350 )
  {
    v56 = *(UFG::qVector4 *)(v22 + 128);
    v57 = *(UFG::qVector4 *)(v22 + 144);
    v58 = *(_DWORD *)(v22 + 200);
    v59 = *(__m128 *)(v22 + 64);
    v60 = *(__m128 *)(v22 + 80);
    v61 = *(_OWORD *)(v22 + 96);
    v223 = *(_OWORD *)(v22 + 64);
    v224 = v60;
    v225 = v61;
    v62 = *(_OWORD *)(v22 + 112);
    v63 = *(float *)(v22 + 228);
    m.v0 = v56;
    v226 = v62;
    v64 = *(UFG::qVector4 *)(v22 + 160);
    m.v1 = v57;
    v65 = *(UFG::qVector4 *)(v22 + 176);
    m.v2 = v64;
    v64.x = *(float *)(v22 + 232);
    m.v3 = v65;
    v65.x = *(float *)(v22 + 196);
    width = v64.x;
    v204.m128_i32[0] = *(_DWORD *)(v22 + 192);
    v64.x = *(float *)(v22 + 208);
    *(unsigned __int64 *)((char *)v204.m128_u64 + 4) = __PAIR__(v58, LODWORD(v65.x));
    v66 = *(_DWORD *)(v22 + 216);
    v190.m128_u64[0] = __PAIR__(*(_DWORD *)(v22 + 212), LODWORD(v64.x));
    v190.m128_i32[2] = v66;
    v200 = v63;
    TransformAABB2(&m, (UFG::qVector3 *)&v204, (UFG::qVector3 *)&v190);
    v67 = 0;
    v68 = 0;
    v69 = 0i64;
    v70 = v63 * 1.45;
    while ( 1 )
    {
      v71 = *(float *)((char *)&v226 + v69 * 4);
      if ( v71 + v70 <= v204.m128_f32[v69] || v71 - v70 >= v190.m128_f32[v69] )
        break;
      ++v68;
      ++v69;
      if ( v68 >= 3 )
      {
        v72 = (__m128)LODWORD(m.v0.y);
        v73 = v72;
        v73.m128_f32[0] = (float)((float)(v72.m128_f32[0] * v72.m128_f32[0]) + (float)(m.v0.x * m.v0.x))
                        + (float)(m.v0.z * m.v0.z);
        if ( v73.m128_f32[0] == 0.0 )
          v74 = 0.0;
        else
          v74 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v73));
        v205.v0.x = m.v0.x * v74;
        v205.v0.y = m.v0.y * v74;
        v205.v0.w = v74 * 0.0;
        v205.v0.z = m.v0.z * v74;
        if ( (float)((float)((float)(m.v1.y * m.v1.y) + (float)(m.v1.x * m.v1.x)) + (float)(m.v1.z * m.v1.z)) == 0.0 )
          v75 = 0.0;
        else
          v75 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps((__m128)LODWORD(m.v1.y)));
        v205.v1.x = m.v1.x * v75;
        v205.v1.y = m.v1.y * v75;
        v205.v1.z = m.v1.z * v75;
        v205.v1.w = v75 * 0.0;
        if ( (float)((float)((float)(m.v2.y * m.v2.y) + (float)(m.v2.x * m.v2.x)) + (float)(m.v2.z * m.v2.z)) == 0.0 )
          v76 = 0.0;
        else
          v76 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps((__m128)LODWORD(m.v2.y)));
        v205.v3 = m.v3;
        v205.v2.x = m.v2.x * v76;
        v205.v2.y = m.v2.y * v76;
        v205.v2.w = v76 * 0.0;
        v205.v2.z = m.v2.z * v76;
        UFG::qInverse(&d, &v205);
        v77 = (__m128)v61;
        v78 = (__m128)v62;
        v79 = (UFG::qVector4)_mm_add_ps(
                               _mm_add_ps(
                                 _mm_add_ps(
                                   _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v59, v59, 0), (__m128)d.v0), (__m128)0i64),
                                   _mm_mul_ps(_mm_shuffle_ps(v59, v59, 85), (__m128)d.v1)),
                                 _mm_mul_ps(_mm_shuffle_ps(v59, v59, 170), (__m128)d.v2)),
                               _mm_mul_ps(_mm_shuffle_ps(v59, v59, 255), (__m128)d.v3));
        mat.v0 = v79;
        mat.v1 = (UFG::qVector4)_mm_add_ps(
                                  _mm_add_ps(
                                    _mm_add_ps(
                                      _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v60, v60, 0), (__m128)d.v0), (__m128)0i64),
                                      _mm_mul_ps(_mm_shuffle_ps(v60, v60, 85), (__m128)d.v1)),
                                    _mm_mul_ps(_mm_shuffle_ps(v60, v60, 170), (__m128)d.v2)),
                                  _mm_mul_ps(_mm_shuffle_ps(v60, v60, 255), (__m128)d.v3));
        mat.v2 = (UFG::qVector4)_mm_add_ps(
                                  _mm_add_ps(
                                    _mm_add_ps(
                                      _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v77, v77, 0), (__m128)d.v0), (__m128)0i64),
                                      _mm_mul_ps(_mm_shuffle_ps(v77, v77, 85), (__m128)d.v1)),
                                    _mm_mul_ps(_mm_shuffle_ps(v77, v77, 170), (__m128)d.v2)),
                                  _mm_mul_ps(_mm_shuffle_ps(v77, v77, 255), (__m128)d.v3));
        mat.v3 = (UFG::qVector4)_mm_add_ps(
                                  _mm_add_ps(
                                    _mm_add_ps(
                                      _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v78, v78, 0), (__m128)d.v0), (__m128)0i64),
                                      _mm_mul_ps(_mm_shuffle_ps(v78, v78, 85), (__m128)d.v1)),
                                    _mm_mul_ps(_mm_shuffle_ps(v78, v78, 170), (__m128)d.v2)),
                                  _mm_mul_ps(_mm_shuffle_ps(v78, v78, 255), (__m128)d.v3));
        if ( v16 < v189 )
        {
          v80 = _mm_cvtps_epi32(
                  _mm_cvtepi32_ps(
                    _mm_cvtps_epi32(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps((__m128)v79, _mm_shuffle_ps((__m128)v79, v11, 250), 148), v208),
                        v208))));
          _mm_store_si128((__m128i *)&v190, v80);
          do
          {
            v81 = v218;
            v82 = &v229;
            v83 = 0i64;
            v84 = &v237;
            do
            {
              v85 = v67++ + v16;
              v86 = *(unsigned __int16 *)(v81 + 2 * v85);
              ++v82;
              v83 += 16i64;
              v87 = 3 * v86;
              v88 = (unsigned int)(8 * v86);
              v89 = v88 + *((_QWORD *)v13 + 6);
              v90 = v88 + *((_QWORD *)v13 + 2);
              v91 = *((_QWORD *)v13 + 1) + (unsigned int)(8 * v87);
              v92 = (v88 + *((_QWORD *)v13 + 2)) & 0xFFFFFFFFFFFFFFF0ui64;
              v93 = (v88 + *((_QWORD *)v13 + 6)) & 0xFFFFFFFFFFFFFFF0ui64;
              v84 += 32;
              v94 = (__m128 *)(v91 & 0xFFFFFFFFFFFFFFF0ui64 ^ ((unsigned __int8)v91 ^ v91 & 0xF0) & 0xF);
              v95 = *v94;
              v96 = v94[1];
              v97 = *(_OWORD *)(v92 ^ ((unsigned __int8)v90 ^ (unsigned __int8)v92) & 0xF);
              v98 = *(_OWORD *)(v93 ^ ((unsigned __int8)v89 ^ (unsigned __int8)v93) & 0xF);
              *((__m128 *)v84 - 3) = *v94;
              *((__m128 *)v84 - 2) = v96;
              *(__m128 *)((char *)&v231 + v83) = (__m128)v97;
              *(__int128 *)((char *)&v206 + v83) = v98;
              v99 = _mm_packs_epi32(v80, v80);
              *((_DWORD *)v84 - 7) = (unsigned __int128)_mm_packus_epi16(v99, v99);
              v100 = *(unsigned __int8 *)v92 << 6;
              v101 = _mm_shuffle_ps(v95, _mm_shuffle_ps(v95, v11, 250), 148);
              v82[-1] = _mm_add_ps(
                          _mm_add_ps(
                            _mm_add_ps(
                              _mm_add_ps(
                                _mm_mul_ps(_mm_shuffle_ps(v101, v101, 0), *(__m128 *)((char *)&v243 + v100)),
                                (__m128)0i64),
                              _mm_mul_ps(_mm_shuffle_ps(v101, v101, 85), *(__m128 *)((char *)&v244 + v100))),
                            _mm_mul_ps(_mm_shuffle_ps(v101, v101, 170), *(__m128 *)((char *)&v245 + v100))),
                          _mm_mul_ps(_mm_shuffle_ps(v101, v101, 255), *(__m128 *)((char *)&v246 + v100)));
              v80 = _mm_load_si128((const __m128i *)&v190);
            }
            while ( v67 < 3 );
            LODWORD(inpts.x) = v229.m128_i32[0];
            v192 = v230.m128_f32[0];
            v195 = v231.m128_f32[0];
            v102 = _mm_shuffle_ps(v231, v231, 85);
            v103 = _mm_shuffle_ps(v231, v231, 170);
            v196 = v102.m128_f32[0];
            v197 = v103.m128_f32[0];
            v212 = v102;
            v213 = v103;
            LODWORD(v104) = (unsigned __int128)_mm_shuffle_ps(v230, v230, 85);
            LODWORD(v105) = (unsigned __int128)_mm_shuffle_ps(v230, v230, 170);
            v193 = v104;
            LODWORD(v106) = (unsigned __int128)_mm_shuffle_ps(v229, v229, 85);
            inpts.y = v106;
            v194 = v105;
            v204 = _mm_shuffle_ps(v229, v229, 170);
            LODWORD(inpts.z) = v204.m128_i32[0];
            v107 = (float)((float)(v104 - v106) * (float)(v103.m128_f32[0] - v105))
                 - (float)((float)(v105 - v204.m128_f32[0]) * (float)(v102.m128_f32[0] - v104));
            v108 = (float)((float)(v230.m128_f32[0] - v229.m128_f32[0]) * (float)(v102.m128_f32[0] - v104))
                 - (float)((float)(v104 - v106) * (float)(v231.m128_f32[0] - v230.m128_f32[0]));
            v109 = (float)((float)(v105 - v204.m128_f32[0]) * (float)(v231.m128_f32[0] - v230.m128_f32[0]))
                 - (float)((float)(v230.m128_f32[0] - v229.m128_f32[0]) * (float)(v103.m128_f32[0] - v105));
            v110 = (float)((float)(v109 * v109) + (float)(v107 * v107)) + (float)(v108 * v108);
            if ( v110 == 0.0 )
              v111 = 0.0;
            else
              v111 = 1.0 / fsqrt(v110);
            v23 = v206;
            if ( (float)((float)((float)(*((float *)&v225 + 1)
                                       * (float)((float)((float)((float)(v111 * v109) * v205.v1.y)
                                                       + (float)((float)(v111 * v107) * v205.v0.y))
                                               + (float)((float)(v111 * v108) * v205.v2.y)))
                               + (float)(*(float *)&v225
                                       * (float)((float)((float)((float)(v111 * v109) * v205.v1.x)
                                                       + (float)((float)(v111 * v107) * v205.v0.x))
                                               + (float)((float)(v111 * v108) * v205.v2.x))))
                       + (float)(*((float *)&v225 + 2)
                               * (float)((float)((float)((float)(v111 * v109) * v205.v1.z)
                                               + (float)((float)(v111 * v107) * v205.v0.z))
                                       + (float)((float)(v111 * v108) * v205.v2.z)))) >= *(float *)(v198 + 224) )
            {
              v67 = 0;
            }
            else
            {
              v67 = 0;
              v194 = v105 - mat.v3.z;
              v197 = v213.m128_f32[0] - mat.v3.z;
              inpts.x = v229.m128_f32[0] - mat.v3.x;
              inpts.y = v106 - mat.v3.y;
              inpts.z = v204.m128_f32[0] - mat.v3.z;
              v192 = v230.m128_f32[0] - mat.v3.x;
              v193 = v104 - mat.v3.y;
              v195 = v231.m128_f32[0] - mat.v3.x;
              v196 = v212.m128_f32[0] - mat.v3.y;
              v112 = ClipToSlab(&inpts, &outpts, 3u, &mat, width, 0);
              v113 = ClipToSlab(&outpts, &v241, v112, &mat, width, 1u);
              if ( ClipToSlab(&v241, &v242, v113, &mat, v200, 2u) )
              {
                v114 = *(_DWORD *)(v23 + 1412);
                if ( v114 < 0x1D )
                {
                  UFG::qMemCopy((void *)(v23 + 44i64 * v114), &source, 0x18u);
                  UFG::qMemCopy((void *)(v23 + 44i64 * (unsigned int)(*(_DWORD *)(v23 + 1412) + 1)), &v238, 0x18u);
                  UFG::qMemCopy((void *)(v23 + 44i64 * (unsigned int)(*(_DWORD *)(v23 + 1412) + 2)), &v239, 0x18u);
                  UFG::qMemCopy((void *)(44i64 * *(unsigned int *)(v23 + 1412) + v23 + 24), &v232, 8u);
                  UFG::qMemCopy((void *)(v23 + 44i64 * (unsigned int)(*(_DWORD *)(v23 + 1412) + 1) + 24), &v233, 8u);
                  UFG::qMemCopy((void *)(v23 + 44i64 * (unsigned int)(*(_DWORD *)(v23 + 1412) + 2) + 24), &v234, 8u);
                  UFG::qMemCopy((void *)(44i64 * *(unsigned int *)(v23 + 1412) + v23 + 32), &m, 8u);
                  UFG::qMemCopy((void *)(v23 + 44i64 * (unsigned int)(*(_DWORD *)(v23 + 1412) + 1) + 32), &m.v1, 8u);
                  UFG::qMemCopy((void *)(v23 + 44i64 * (unsigned int)(*(_DWORD *)(v23 + 1412) + 2) + 32), &m.v2, 8u);
                  v115 = 0;
                  v116 = &inpts.z;
                  v117 = mat.v1.z;
                  v118 = mat.v1.y;
                  v119 = 1.0 / (float)(width * 2.0);
                  v120 = mat.v1.x;
                  v121 = mat.v0.z;
                  v122 = mat.v0.y;
                  v123 = mat.v0.x;
                  do
                  {
                    v124 = (float)((float)((float)((float)(v120 * *(v116 - 2)) + (float)(v118 * *(v116 - 1)))
                                         + (float)(v117 * *v116))
                                 * v119)
                         + 0.5;
                    v187 = (float)((float)((float)((float)(v123 * *(v116 - 2)) + (float)(v122 * *(v116 - 1)))
                                         + (float)(v121 * *v116))
                                 * v119)
                         + 0.5;
                    v125 = LODWORD(v187) & 0x7FFFFFFF;
                    v126 = (LODWORD(v187) >> 16) & 0x8000;
                    if ( (LODWORD(v187) & 0x7FFFFFFFu) <= 0x47FFEFFF )
                    {
                      if ( v125 >= 0x38800000 )
                        v128 = v125 - 939524096;
                      else
                        v128 = (LODWORD(v187) & 0x7FFFFF | 0x800000u) >> (113 - (v125 >> 23));
                      v127 = ((((v128 >> 13) & 1) + v128 + 4095) >> 13) | v126;
                    }
                    else
                    {
                      v127 = v126 | 0x7FFF;
                    }
                    v188 = (float)((float)((float)((float)(v120 * *(v116 - 2)) + (float)(v118 * *(v116 - 1)))
                                         + (float)(v117 * *v116))
                                 * v119)
                         + 0.5;
                    *(_WORD *)(44i64 * (v115 + *(_DWORD *)(v23 + 1412)) + v23 + 40) = v127;
                    v129 = LODWORD(v124) & 0x7FFFFFFF;
                    v130 = (LODWORD(v124) >> 16) & 0x8000;
                    if ( (LODWORD(v124) & 0x7FFFFFFFu) <= 0x47FFEFFF )
                    {
                      if ( v129 >= 0x38800000 )
                        v132 = v129 - 939524096;
                      else
                        v132 = (LODWORD(v188) & 0x7FFFFF | 0x800000u) >> (113 - (v129 >> 23));
                      v131 = ((((v132 >> 13) & 1) + v132 + 4095) >> 13) | v130;
                    }
                    else
                    {
                      v131 = v130 | 0x7FFF;
                    }
                    v116 += 3;
                    v133 = v115++ + *(_DWORD *)(v23 + 1412);
                    *(_WORD *)(44 * v133 + v23 + 42) = v131;
                  }
                  while ( v115 < 3 );
                  *(_DWORD *)(v23 + 1412) += 3;
                  v13 = v247;
                }
              }
            }
            v80 = _mm_load_si128((const __m128i *)&v190);
            v11 = v203;
            v16 += 3;
          }
          while ( v16 < v189 );
          v5 = v215;
          v8 = v199;
          v9 = v216;
        }
        break;
      }
    }
    v53 = v208;
    v52 = v220;
    v55 = v209;
    v10 = v201;
    *(_BYTE *)(v23 + 1408) = 1;
    v54 = v210;
  }
  if ( !v184 )
  {
    v134 = *(__m128 *)(v13 + 56);
    v190 = *(__m128 *)(v13 + 56);
    if ( v10 )
    {
      v135 = v202;
      do
      {
        v136 = 1024;
        v137 = v5;
        v138 = (__m128 *)v8;
        v139 = (_OWORD *)v135;
        v140 = (_OWORD *)v9;
        if ( v10 < 0x400 )
          v136 = v10;
        v10 -= v136;
        v141 = 24 * v136;
        v8 += v141;
        v5 += v141;
        v142 = 8 * v136;
        v135 += v142;
        v9 += v142;
        v199 = v8;
        v202 = v135;
        if ( v136 )
        {
          v143 = v214;
          v144 = v137 - (_QWORD)v138;
          v145 = v136;
          v146 = _mm_shuffle_ps(v134, v134, 0);
          v212 = v146;
          v213 = _mm_and_ps(v52, v203);
          do
          {
            v147 = *(__m128 *)v139;
            v148 = *(__m128 *)v140;
            v149 = (unsigned __int8 *)v140;
            v140 = (_OWORD *)((char *)v140 + 8);
            v139 = (_OWORD *)((char *)v139 + 8);
            v150 = v138[1];
            v151 = (unsigned __int64)*v149 << 6;
            v152 = *(__m128 *)((char *)&v243 + v151);
            v153 = *(__m128 *)((char *)&v244 + v151);
            v154 = *(__m128 *)((char *)&v245 + v151);
            v155 = _mm_add_ps(
                     _mm_mul_ps(
                       _mm_add_ps(
                         _mm_mul_ps(
                           _mm_add_ps(
                             _mm_cvtepi32_ps((__m128i)_mm_and_ps(
                                                        (__m128)_mm_sub_epi32(
                                                                  (__m128i)_mm_shuffle_ps(v148, v148, 85),
                                                                  v219),
                                                        v222)),
                             v211),
                           v55),
                         (__m128)0i64),
                       v228),
                     (__m128)0i64);
            v156 = _mm_min_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_add_ps(
                           _mm_mul_ps(
                             _mm_shuffle_ps(v155, v155, 85),
                             _mm_shuffle_ps(*(__m128 *)(v143 + 4i64 * v149[1]), *(__m128 *)(v143 + 4i64 * v149[1]), 0)),
                           (__m128)0i64),
                         _mm_mul_ps(
                           _mm_shuffle_ps(v155, v155, 170),
                           _mm_shuffle_ps(*(__m128 *)(v143 + 4i64 * v149[2]), *(__m128 *)(v143 + 4i64 * v149[2]), 0))),
                       v146),
                     v203);
            v157 = _mm_add_ps(
                     _mm_mul_ps(
                       _mm_sub_ps(
                         _mm_add_ps(
                           _mm_mul_ps(
                             _mm_add_ps(
                               _mm_cvtepi32_ps((__m128i)_mm_and_ps(
                                                          (__m128)_mm_sub_epi32(
                                                                    (__m128i)_mm_shuffle_ps(v150, v150, 85),
                                                                    v219),
                                                          v222)),
                               v211),
                             v209),
                           (__m128)0i64),
                         v53),
                       v221),
                     (__m128)0i64);
            v158 = _mm_shuffle_ps(v157, v157, 255);
            v159 = _mm_shuffle_ps(v157, _mm_shuffle_ps(v157, (__m128)0i64, 250), 148);
            v160 = _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(
                         _mm_add_ps(
                           _mm_mul_ps(
                             _mm_sub_ps(
                               _mm_add_ps(
                                 _mm_mul_ps(
                                   _mm_cvtepi32_ps((__m128i)_mm_and_ps(
                                                              _mm_shuffle_ps(v147, _mm_shuffle_ps(v147, v54, 0), 144),
                                                              v222)),
                                   v209),
                                 (__m128)0i64),
                               v208),
                             v227),
                           (__m128)0i64),
                         v156),
                       (__m128)0i64),
                     _mm_shuffle_ps(*v138, _mm_shuffle_ps(*v138, v203, 250), 148));
            v161 = _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(
                         _mm_add_ps(
                           _mm_mul_ps(
                             _mm_sub_ps(
                               _mm_add_ps(
                                 _mm_mul_ps(
                                   _mm_cvtepi32_ps((__m128i)_mm_and_ps(
                                                              _mm_shuffle_ps(v147, _mm_shuffle_ps(v147, v210, 85), 149),
                                                              v222)),
                                   v209),
                                 (__m128)0i64),
                               v208),
                             v221),
                           (__m128)0i64),
                         v156),
                       (__m128)0i64),
                     _mm_add_ps(
                       _mm_mul_ps(
                         _mm_sub_ps(
                           _mm_add_ps(
                             _mm_mul_ps(
                               _mm_add_ps(
                                 _mm_cvtepi32_ps((__m128i)_mm_and_ps(
                                                            (__m128)_mm_sub_epi32(
                                                                      (__m128i)_mm_shuffle_ps(v150, v150, 0),
                                                                      v219),
                                                            v222)),
                                 v211),
                               v209),
                             (__m128)0i64),
                           v208),
                         v221),
                       (__m128)0i64));
            v162 = _mm_shuffle_ps(v161, v161, 0);
            v163 = _mm_shuffle_ps(v161, v161, 85);
            v164 = _mm_shuffle_ps(v161, v161, 170);
            v165 = _mm_add_ps(
                     _mm_mul_ps(
                       _mm_rsqrt_ps(
                         _mm_add_ps(
                           _mm_add_ps(_mm_add_ps(_mm_mul_ps(v162, v162), (__m128)0i64), _mm_mul_ps(v163, v163)),
                           _mm_mul_ps(v164, v164))),
                       v161),
                     (__m128)0i64);
            v166 = _mm_shuffle_ps(v165, v165, 0);
            v167 = _mm_shuffle_ps(v165, v165, 85);
            v168 = _mm_shuffle_ps(v165, v165, 170);
            v169 = _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v159, v159, 0), v166), (__m128)0i64),
                       _mm_mul_ps(_mm_shuffle_ps(v159, v159, 85), v167)),
                     _mm_mul_ps(_mm_shuffle_ps(v159, v159, 170), v168));
            v170 = _mm_sub_ps(
                     v159,
                     _mm_sub_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v165, v165, 210), _mm_shuffle_ps(v169, v169, 201)),
                         (__m128)0i64),
                       _mm_mul_ps(_mm_shuffle_ps(v165, v165, 201), _mm_shuffle_ps(v169, v169, 210))));
            v171 = _mm_shuffle_ps(v170, v170, 0);
            v172 = _mm_shuffle_ps(v170, v170, 85);
            v173 = _mm_shuffle_ps(v170, v170, 170);
            v174 = _mm_add_ps(
                     _mm_mul_ps(
                       _mm_rsqrt_ps(
                         _mm_add_ps(
                           _mm_add_ps(_mm_add_ps(_mm_mul_ps(v171, v171), (__m128)0i64), _mm_mul_ps(v172, v172)),
                           _mm_mul_ps(v173, v173))),
                       v170),
                     (__m128)0i64);
            v146 = v212;
            v138 = (__m128 *)((char *)v138 + 24);
            v175 = _mm_add_ps(
                     _mm_add_ps(_mm_add_ps(_mm_mul_ps(v166, v152), (__m128)0i64), _mm_mul_ps(v167, v153)),
                     _mm_mul_ps(v168, v154));
            v55 = v209;
            v176 = _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v160, v160, 0), v152), (__m128)0i64),
                         _mm_mul_ps(_mm_shuffle_ps(v160, v160, 85), v153)),
                       _mm_mul_ps(_mm_shuffle_ps(v160, v160, 170), v154)),
                     _mm_mul_ps(_mm_shuffle_ps(v160, v160, 255), *(__m128 *)((char *)&v246 + v151)));
            v53 = v208;
            v177 = _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v174, v174, 0), v152), (__m128)0i64),
                         _mm_mul_ps(_mm_shuffle_ps(v174, v174, 85), v153)),
                       _mm_mul_ps(_mm_shuffle_ps(v174, v174, 170), v154)),
                     _mm_mul_ps(_mm_shuffle_ps(v174, v174, 255), (__m128)0i64));
            v54 = v210;
            v178 = _mm_mul_ps(_mm_add_ps(v175, _mm_mul_ps(_mm_shuffle_ps(v165, v165, 255), (__m128)0i64)), v208);
            *(__m128 *)((char *)v138 + v144 - 24) = _mm_shuffle_ps(
                                                      v176,
                                                      _mm_shuffle_ps(
                                                        v176,
                                                        _mm_shuffle_ps(
                                                          *(__m128 *)(v143 + 4i64 * v149[3]),
                                                          *(__m128 *)(v143 + 4i64 * v149[3]),
                                                          0),
                                                        250),
                                                      148);
            v179 = _mm_cvtps_epi32(_mm_cvtepi32_ps(_mm_cvtps_epi32(_mm_add_ps(v178, v53))));
            v180 = _mm_packs_epi32(v179, v179);
            v181 = _mm_or_ps(_mm_andnot_ps(v203, _mm_cmpltps(v158, (__m128)0i64)), v213);
            *(_DWORD *)((char *)&v138->m128_u64[-1] + v144) = (unsigned __int128)_mm_packus_epi16(v180, v180);
            v182 = _mm_cvtps_epi32(_mm_cvtepi32_ps(_mm_cvtps_epi32(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v177, _mm_shuffle_ps(v177, v181, 250), 148), v53), v53))));
            v183 = _mm_packs_epi32(v182, v182);
            *(_DWORD *)((char *)v138->m128_u64 + v144 - 4) = (unsigned __int128)_mm_packus_epi16(v183, v183);
            --v145;
          }
          while ( v145 );
          v134 = v190;
          v8 = v199;
          v135 = v202;
        }
        v52 = v220;
        v55 = v209;
        v54 = v210;
      }
      while ( v10 );
    }
  }
}

// File Line: 35
// RVA: 0x77730
void __fastcall SkinVehicleDecalBufferTask(int worker_id, UFG::qMemoryStreamer *memory_streamer, void *param0, void *param1)
{
  __int64 v4; // rbp
  __int64 v5; // r15
  __int64 v6; // r14
  unsigned __int8 *v7; // r9
  char *v8; // r10
  __m128 v9; // xmm10
  __int64 v10; // rbx
  __int64 v11; // rdi
  __m128 *v12; // rdx
  __int64 v13; // r11
  int v14; // er8
  __int64 v15; // rcx
  __m128 *v16; // rax
  __m128 v17; // xmm5
  __m128 v18; // xmm11
  __m128 v19; // xmm12
  __m128 v20; // xmm13
  __m128 v21; // xmm4
  __m128 v22; // xmm3
  __m128 v23; // xmm8
  __m128 v24; // xmm2
  __m128 v25; // xmm5
  __m128 v26; // xmm1
  __m128 v27; // xmm6
  __m128 v28; // xmm7
  __m128 v29; // xmm8
  __m128 v30; // xmm6
  __m128 v31; // xmm10
  __m128 v32; // xmm5
  __m128 v33; // xmm4
  __m128 v34; // xmm10
  __m128 v35; // xmm5
  __m128 v36; // xmm4
  __m128 v37; // xmm4
  __m128 v38; // xmm5
  __m128 v39; // xmm10
  __m128 v40; // xmm14
  __m128 v41; // xmm1
  bool v42; // zf
  __m128 v43; // xmm9
  __m128 v44; // xmm8
  __m128 v45; // xmm4
  __m128 v46; // xmm11
  __int64 v47; // r8
  __m128 v48; // xmm8
  signed __int64 v49; // rbp
  unsigned __int8 *v50; // r14
  __m128 v51; // xmm5
  unsigned __int64 v52; // rdx
  __m128 v53; // xmm12
  __m128 v54; // xmm13
  __m128 v55; // xmm2
  __m128i v56; // xmm4
  __m128 v57; // xmm14
  __m128i v58; // xmm6
  __m128 v59; // xmm0
  __m128 v60; // xmm11
  __m128 v61; // xmm1
  __m128 v62; // xmm8
  __m128 v63; // xmm10
  __m128 v64; // xmm8
  __m128 v65; // xmm9
  __m128 v66; // xmm3
  __m128 v67; // xmm2
  __m128 v68; // xmm0
  __m128 v69; // xmm1
  __m128 v70; // xmm6
  __m128 v71; // xmm7
  __m128 v72; // xmm3
  __m128 v73; // xmm5
  __m128 v74; // xmm2
  __m128 v75; // xmm8
  __m128 v76; // xmm2
  __m128 v77; // xmm0
  __m128 v78; // xmm1
  __m128 v79; // xmm4
  __m128 v80; // xmm7
  __m128 v81; // xmm2
  __m128 v82; // xmm0
  __m128 v83; // xmm3
  __m128i v84; // xmm2
  __m128i v85; // xmm2
  __m128 v86; // xmm1
  __m128 v87; // xmm1
  __m128i v88; // xmm2
  __m128i v89; // xmm2
  __m128i v90; // [rsp+50h] [rbp-4118h]
  __m128 v91; // [rsp+60h] [rbp-4108h]
  __m128 v92; // [rsp+70h] [rbp-40F8h]
  __m128 v93; // [rsp+80h] [rbp-40E8h]
  __m128 v94; // [rsp+90h] [rbp-40D8h]
  __m128 v95; // [rsp+A0h] [rbp-40C8h]
  __m128 v96; // [rsp+B0h] [rbp-40B8h]
  __int128 v97; // [rsp+C0h] [rbp-40A8h]
  __int128 v98; // [rsp+D0h] [rbp-4098h]
  __int128 v99; // [rsp+E0h] [rbp-4088h]
  __int128 v100; // [rsp+F0h] [rbp-4078h]

  v4 = *(_QWORD *)param0;
  v5 = *((_QWORD *)param0 + 9);
  v6 = *((_QWORD *)param0 + 15);
  v7 = (unsigned __int8 *)*((_QWORD *)param0 + 13);
  v8 = (char *)param0;
  v9 = gVmxOne_4;
  v10 = *((_QWORD *)param0 + 4);
  v11 = *((_QWORD *)param0 + 12);
  if ( *((_WORD *)param0 + 20) )
  {
    v12 = (__m128 *)&v99;
    v13 = *((unsigned __int16 *)param0 + 20);
    do
    {
      v14 = *v7;
      if ( v14 == 255 )
      {
        v12[-2] = gVmxIdentity0_4;
        v12[-1] = gVmxIdentity1_4;
        *v12 = gVmxIdentity2_4;
        v12[1] = gVmxIdentity3_4;
      }
      else
      {
        v15 = (unsigned int)(48 * v14);
        v16 = (__m128 *)(v11 + (unsigned int)(v14 << 6));
        v17 = *(__m128 *)(v15 + v10 + 16);
        v18 = v16[1];
        v19 = v16[2];
        v20 = v16[3];
        v21 = _mm_shuffle_ps(*(__m128 *)(v15 + v10 + 16), v17, 255);
        v22 = _mm_add_ps(v17, v17);
        v23 = _mm_shuffle_ps(*(__m128 *)(v15 + v10 + 16), v17, 201);
        v24 = _mm_shuffle_ps(v22, v22, 210);
        v25 = _mm_shuffle_ps(v17, v17, 210);
        v26 = _mm_shuffle_ps(v22, v22, 201);
        v27 = _mm_sub_ps(v9, _mm_mul_ps(v26, v23));
        v28 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v26, v21), (__m128)0i64), _mm_mul_ps(v25, v22));
        v29 = _mm_sub_ps(_mm_add_ps(_mm_mul_ps(v23, v22), (__m128)0i64), _mm_mul_ps(v24, v21));
        v30 = _mm_sub_ps(v27, _mm_mul_ps(v24, v25));
        v31 = _mm_shuffle_ps(_mm_shuffle_ps(v28, v29, 80), v29, 233);
        v32 = _mm_shuffle_ps(_mm_shuffle_ps(v29, v30, 80), v30, 233);
        v33 = _mm_shuffle_ps(_mm_shuffle_ps(v30, v28, 80), v28, 233);
        v34 = _mm_shuffle_ps(v31, _mm_shuffle_ps(v30, v31, 250), 148);
        v35 = _mm_shuffle_ps(v32, _mm_shuffle_ps(v28, v32, 250), 148);
        v36 = _mm_shuffle_ps(v33, _mm_shuffle_ps(v29, v33, 250), 148);
        v37 = _mm_shuffle_ps(v36, _mm_shuffle_ps(v36, (__m128)0i64, 250), 148);
        v38 = _mm_shuffle_ps(v35, _mm_shuffle_ps(v35, (__m128)0i64, 250), 148);
        v39 = _mm_shuffle_ps(v34, _mm_shuffle_ps(v34, (__m128)0i64, 250), 148);
        v40 = _mm_shuffle_ps(*(__m128 *)(v15 + v10), _mm_shuffle_ps(*(__m128 *)(v15 + v10), gVmxOne_4, 250), 148);
        v12[-2] = _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(*v16, *v16, 0), v37), (__m128)0i64),
                        _mm_mul_ps(_mm_shuffle_ps(*v16, *v16, 85), v38)),
                      _mm_mul_ps(_mm_shuffle_ps(*v16, *v16, 170), v39)),
                    _mm_mul_ps(_mm_shuffle_ps(*v16, *v16, 255), v40));
        v12[-1] = _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v18, v18, 0), v37), (__m128)0i64),
                        _mm_mul_ps(_mm_shuffle_ps(v18, v18, 85), v38)),
                      _mm_mul_ps(_mm_shuffle_ps(v18, v18, 170), v39)),
                    _mm_mul_ps(_mm_shuffle_ps(v18, v18, 255), v40));
        *v12 = _mm_add_ps(
                 _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v19, v19, 0), v37), (__m128)0i64),
                     _mm_mul_ps(_mm_shuffle_ps(v19, v19, 85), v38)),
                   _mm_mul_ps(_mm_shuffle_ps(v19, v19, 170), v39)),
                 _mm_mul_ps(_mm_shuffle_ps(v19, v19, 255), v40));
        v41 = _mm_mul_ps(_mm_shuffle_ps(v20, v20, 170), v39);
        v9 = gVmxOne_4;
        v12[1] = _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v20, v20, 0), v37), (__m128)0i64),
                       _mm_mul_ps(_mm_shuffle_ps(v20, v20, 85), v38)),
                     v41),
                   _mm_mul_ps(_mm_shuffle_ps(v20, v20, 255), v40));
      }
      v12 += 4;
      ++v7;
      --v13;
    }
    while ( v13 );
  }
  v42 = *((_DWORD *)v8 + 32) == 0;
  v43 = gVmx127_2;
  v44 = *(__m128 *)(v8 + 56);
  v45 = (__m128)gVmxi127_2;
  v46 = (__m128)gVmxUnpackMask_2;
  v91 = gVmxOneOver127_2;
  v93 = gVmxOneOver255_2;
  v96 = gVmxOneOver511_2;
  _mm_store_si128(&v90, gVmxUnpackBias_2);
  v92 = gVmxUnpackShift_2;
  if ( !v42 )
  {
    v47 = *((unsigned int *)v8 + 32);
    v48 = _mm_shuffle_ps(v44, v44, 0);
    v49 = v4 + 20;
    v50 = (unsigned __int8 *)(v6 + 24);
    v94 = _mm_and_ps(gVmxMinusOne_2, v9);
    v95 = v48;
    do
    {
      v51 = *(__m128 *)(v50 - 8);
      v52 = (unsigned __int64)*v50 << 6;
      v53 = (__m128)*(&v97 + 4 * (unsigned __int64)*v50);
      v54 = (__m128)*(&v98 + 4 * (unsigned __int64)*v50);
      v55 = *(__m128 *)(v5 + 4i64 * v50[1]);
      v56 = (__m128i)_mm_and_ps(
                       _mm_shuffle_ps(*(__m128 *)(v50 + 8), _mm_shuffle_ps(*(__m128 *)(v50 + 8), v45, 0), 144),
                       v46);
      v57 = (__m128)*(&v99 + 4 * (unsigned __int64)*v50);
      v58 = (__m128i)_mm_and_ps(
                       _mm_shuffle_ps(
                         *(__m128 *)(v50 + 8),
                         _mm_shuffle_ps(*(__m128 *)(v50 + 8), (__m128)gVmxi127_2, 85),
                         149),
                       v46);
      v59 = _mm_add_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_cvtepi32_ps((__m128i)_mm_and_ps(
                                                 (__m128)_mm_sub_epi32(
                                                           (__m128i)_mm_shuffle_ps(*(__m128 *)v50, *(__m128 *)v50, 85),
                                                           v90),
                                                 v46)),
                      gVmxUnpackUnbias_2),
                    v92),
                  (__m128)0i64),
                v93),
              (__m128)0i64);
      v60 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v59, v59, 85), _mm_shuffle_ps(v55, v55, 0)), (__m128)0i64),
                _mm_mul_ps(
                  _mm_shuffle_ps(v59, v59, 170),
                  _mm_shuffle_ps(*(__m128 *)(v5 + 4i64 * v50[2]), *(__m128 *)(v5 + 4i64 * v50[2]), 0))),
              v48);
      v61 = _mm_min_ps(v60, v9);
      v62 = _mm_add_ps(
              _mm_mul_ps(
                _mm_sub_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_cvtepi32_ps((__m128i)_mm_and_ps(
                                                   (__m128)_mm_sub_epi32((__m128i)_mm_shuffle_ps(v51, v51, 85), v90),
                                                   (__m128)gVmxUnpackMask_2)),
                        gVmxUnpackUnbias_2),
                      v92),
                    (__m128)0i64),
                  v43),
                v91),
              (__m128)0i64);
      v63 = _mm_shuffle_ps(v62, v62, 255);
      v64 = _mm_shuffle_ps(v62, _mm_shuffle_ps(v62, (__m128)0i64, 250), 148);
      v65 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_sub_ps(_mm_add_ps(_mm_mul_ps(_mm_cvtepi32_ps(v56), v92), (__m128)0i64), gVmx127_2),
                      v96),
                    (__m128)0i64),
                  v61),
                (__m128)0i64),
              _mm_shuffle_ps(*(__m128 *)(v50 - 24), _mm_shuffle_ps(*(__m128 *)(v50 - 24), gVmxOne_4, 250), 148));
      v66 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_sub_ps(_mm_add_ps(_mm_mul_ps(_mm_cvtepi32_ps(v58), v92), (__m128)0i64), gVmx127_2),
                      v91),
                    (__m128)0i64),
                  v61),
                (__m128)0i64),
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_sub_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_add_ps(
                          _mm_cvtepi32_ps((__m128i)_mm_and_ps(
                                                     (__m128)_mm_sub_epi32((__m128i)_mm_shuffle_ps(v51, v51, 0), v90),
                                                     (__m128)gVmxUnpackMask_2)),
                          gVmxUnpackUnbias_2),
                        v92),
                      (__m128)0i64),
                    gVmx127_2),
                  v91),
                (__m128)0i64));
      v67 = _mm_shuffle_ps(v66, v66, 0);
      v68 = _mm_shuffle_ps(v66, v66, 85);
      v69 = _mm_shuffle_ps(v66, v66, 170);
      v70 = _mm_add_ps(
              _mm_mul_ps(
                _mm_rsqrt_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_add_ps(_mm_mul_ps(v67, v67), (__m128)0i64), _mm_mul_ps(v68, v68)),
                    _mm_mul_ps(v69, v69))),
                v66),
              (__m128)0i64);
      v71 = _mm_shuffle_ps(v70, v70, 0);
      v72 = _mm_shuffle_ps(v70, v70, 85);
      v73 = _mm_shuffle_ps(v70, v70, 170);
      v74 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v64, v64, 0), v71), (__m128)0i64),
                _mm_mul_ps(_mm_shuffle_ps(v64, v64, 85), v72)),
              _mm_mul_ps(_mm_shuffle_ps(v64, v64, 170), v73));
      v75 = _mm_sub_ps(
              v64,
              _mm_sub_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v70, v70, 210), _mm_shuffle_ps(v74, v74, 201)), (__m128)0i64),
                _mm_mul_ps(_mm_shuffle_ps(v70, v70, 201), _mm_shuffle_ps(v74, v74, 210))));
      v76 = _mm_shuffle_ps(v75, v75, 0);
      v77 = _mm_shuffle_ps(v75, v75, 85);
      v78 = _mm_shuffle_ps(v75, v75, 170);
      v79 = _mm_add_ps(
              _mm_mul_ps(
                _mm_rsqrt_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_add_ps(_mm_mul_ps(v76, v76), (__m128)0i64), _mm_mul_ps(v77, v77)),
                    _mm_mul_ps(v78, v78))),
                v75),
              (__m128)0i64);
      v48 = v95;
      v49 += 28i64;
      v50 += 44;
      v80 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v71, v53), (__m128)0i64), _mm_mul_ps(v72, v54));
      v81 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v65, v65, 0), v53), (__m128)0i64),
                  _mm_mul_ps(_mm_shuffle_ps(v65, v65, 85), v54)),
                _mm_mul_ps(_mm_shuffle_ps(v65, v65, 170), v57)),
              _mm_mul_ps(_mm_shuffle_ps(v65, v65, 255), *(__m128 *)((char *)&v100 + v52)));
      v43 = gVmx127_2;
      v82 = _mm_shuffle_ps(v81, v60, 250);
      v46 = (__m128)gVmxUnpackMask_2;
      v83 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v79, v79, 0), v53), (__m128)0i64),
                  _mm_mul_ps(_mm_shuffle_ps(v79, v79, 85), v54)),
                _mm_mul_ps(_mm_shuffle_ps(v79, v79, 170), v57)),
              _mm_mul_ps(_mm_shuffle_ps(v79, v79, 255), (__m128)0i64));
      v45 = (__m128)gVmxi127_2;
      *(__m128 *)(v49 - 48) = _mm_shuffle_ps(v81, v82, 148);
      v84 = _mm_cvtps_epi32(
              _mm_cvtepi32_ps(
                _mm_cvtps_epi32(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_add_ps(v80, _mm_mul_ps(v73, v57)),
                        _mm_mul_ps(_mm_shuffle_ps(v70, v70, 255), (__m128)0i64)),
                      gVmx127_2),
                    gVmx127_2))));
      v85 = _mm_packs_epi32(v84, v84);
      v86 = _mm_andnot_ps(gVmxOne_4, _mm_cmpltps(v63, (__m128)0i64));
      v9 = gVmxOne_4;
      v87 = _mm_or_ps(v86, v94);
      *(_DWORD *)(v49 - 32) = (unsigned __int128)_mm_packus_epi16(v85, v85);
      v88 = _mm_cvtps_epi32(_mm_cvtepi32_ps(_mm_cvtps_epi32(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v83, _mm_shuffle_ps(v83, v87, 250), 148), gVmx127_2), gVmx127_2))));
      v89 = _mm_packs_epi32(v88, v88);
      *(_DWORD *)(v49 - 28) = (unsigned __int128)_mm_packus_epi16(v89, v89);
      *(_DWORD *)(v49 - 24) = *((_DWORD *)v50 - 7);
      --v47;
    }
    while ( v47 );
  }
}

