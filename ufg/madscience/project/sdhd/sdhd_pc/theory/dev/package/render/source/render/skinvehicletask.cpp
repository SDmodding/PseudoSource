// File Line: 13
// RVA: 0x14573D0
__int64 dynamic_initializer_for__gTaskFunctionDecl_SkinVehicleBufferTask__()
{
  UFG::qTaskFunctionDecl::qTaskFunctionDecl(
    &gTaskFunctionDecl_SkinVehicleBufferTask,
    &gTaskFunctionDeclData_SkinVehicleBufferTask);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gTaskFunctionDecl_SkinVehicleBufferTask__);
}

// File Line: 14
// RVA: 0x1457430
__int64 dynamic_initializer_for__gTaskFunctionDecl_SkinVehicleGlassBufferTask__()
{
  UFG::qTaskFunctionDecl::qTaskFunctionDecl(
    &gTaskFunctionDecl_SkinVehicleGlassBufferTask,
    &gTaskFunctionDeclData_SkinVehicleGlassBufferTask);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gTaskFunctionDecl_SkinVehicleGlassBufferTask__);
}

// File Line: 15
// RVA: 0x1457400
__int64 dynamic_initializer_for__gTaskFunctionDecl_SkinVehicleDecalBufferTask__()
{
  UFG::qTaskFunctionDecl::qTaskFunctionDecl(
    &gTaskFunctionDecl_SkinVehicleDecalBufferTask,
    &gTaskFunctionDeclData_SkinVehicleDecalBufferTask);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gTaskFunctionDecl_SkinVehicleDecalBufferTask__);
}

// File Line: 19
// RVA: 0x74D80
void __fastcall SkinVehicleBufferTask(
        int worker_id,
        UFG::qMemoryStreamer *memory_streamer,
        _QWORD *param0,
        void *param1)
{
  __int64 v4; // rdx
  __int64 v5; // rsi
  __int64 v6; // rax
  int v7; // r10d
  __int64 v8; // r14
  __int64 v9; // r12
  unsigned int v10; // r9d
  __m128 v11; // xmm11
  bool v12; // zf
  _QWORD *v13; // r15
  __int64 v14; // rdx
  unsigned int v15; // r8d
  unsigned int v16; // r13d
  unsigned int v17; // r10d
  bool v18; // di
  bool v19; // cc
  unsigned int v20; // r11d
  unsigned __int8 *v21; // r10
  __int64 v22; // rax
  __int64 v23; // rbx
  __m128 *v24; // rdx
  __int64 v25; // r11
  int v26; // r8d
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
  __int128 v64; // xmm0
  __int128 v65; // xmm1
  int v66; // xmm2_4
  unsigned int v67; // ecx
  __int64 v68; // rax
  double v69; // xmm3_8
  float v70; // xmm2_4
  __m128 y_low; // xmm4
  float v72; // xmm1_4
  float v73; // xmm1_4
  float v74; // xmm1_4
  __m128 v75; // xmm5
  __m128 v76; // xmm10
  UFG::qVector4 v77; // xmm12
  __m128i v78; // xmm3
  unsigned __int64 v79; // rbx
  unsigned int v80; // esi
  __m128 *v81; // r12
  char *v82; // rdi
  __int64 v83; // r14
  __int64 v84; // rax
  int v85; // edx
  int v86; // r8d
  __int64 v87; // rcx
  __int64 v88; // r9
  __int64 v89; // rdx
  __int64 v90; // r8
  __m128 *v91; // rcx
  __m128 v92; // xmm4
  __m128 v93; // xmm2
  __m128 v94; // xmm1
  __int128 v95; // xmm0
  __m128i v96; // xmm0
  __int64 v97; // rcx
  __m128 v98; // xmm4
  __m128 v99; // xmm1
  __m128 v100; // xmm2
  float v101; // xmm12_4
  float v102; // xmm13_4
  float v103; // xmm14_4
  float v104; // xmm5_4
  float v105; // xmm8_4
  float v106; // xmm9_4
  float v107; // xmm3_4
  float v108; // xmm6_4
  unsigned int v109; // eax
  unsigned int v110; // eax
  unsigned int v111; // eax
  unsigned int v112; // r9d
  float *p_z; // r10
  float z; // xmm9_4
  float y; // xmm10_4
  float v116; // xmm7_4
  float x; // xmm11_4
  float v118; // xmm12_4
  float v119; // xmm13_4
  float v120; // xmm14_4
  float v121; // xmm6_4
  unsigned int v122; // edx
  int v123; // r8d
  __int16 v124; // r8
  unsigned int v125; // edx
  unsigned int v126; // edx
  int v127; // r8d
  __int16 v128; // r8
  unsigned int v129; // edx
  __int64 v130; // rcx
  __m128 v131; // xmm0
  __int64 v132; // rdi
  unsigned int v133; // edx
  __int64 v134; // r8
  __m128 *v135; // r10
  _OWORD *v136; // rbx
  _OWORD *v137; // r11
  __int64 v138; // rcx
  __int64 v139; // rcx
  __int64 v140; // r15
  __int64 v141; // r8
  __int64 v142; // rdi
  __m128 v143; // xmm8
  __m128 v144; // xmm6
  __m128 v145; // xmm1
  __m128 v146; // xmm5
  unsigned __int8 *v147; // rcx
  unsigned __int64 v148; // rdx
  __m128 v149; // xmm12
  __m128 v150; // xmm13
  __m128 v151; // xmm14
  __m128 v152; // xmm0
  __m128 v153; // xmm11
  __m128i v154; // xmm2
  __m128 v155; // xmm1
  __m128 v156; // xmm3
  __m128 v157; // xmm8
  __m128 v158; // xmm9
  __m128 v159; // xmm10
  __m128 v160; // xmm8
  __m128 v161; // xmm9
  __m128 v162; // xmm3
  __m128 v163; // xmm2
  __m128 v164; // xmm0
  __m128 v165; // xmm1
  __m128 v166; // xmm6
  __m128 v167; // xmm7
  __m128 v168; // xmm3
  __m128 v169; // xmm5
  __m128 v170; // xmm2
  __m128 v171; // xmm8
  __m128 v172; // xmm2
  __m128 v173; // xmm0
  __m128 v174; // xmm1
  __m128 v175; // xmm4
  __m128 v176; // xmm7
  __m128 v177; // xmm2
  __m128 v178; // xmm3
  __m128i v179; // xmm0
  __m128i v180; // xmm2
  __m128i v181; // xmm2
  __m128 v182; // xmm1
  __m128 v183; // xmm1
  __m128i v184; // xmm2
  __m128i v185; // xmm2
  bool v186; // [rsp+30h] [rbp-D0h]
  unsigned int v187; // [rsp+34h] [rbp-CCh]
  float width; // [rsp+34h] [rbp-CCh]
  float v189; // [rsp+38h] [rbp-C8h]
  float v190; // [rsp+38h] [rbp-C8h]
  unsigned int v191; // [rsp+40h] [rbp-C0h]
  __m128i v192; // [rsp+50h] [rbp-B0h] BYREF
  UFG::qVector3 inpts; // [rsp+60h] [rbp-A0h] BYREF
  float v194; // [rsp+6Ch] [rbp-94h]
  float v195; // [rsp+70h] [rbp-90h]
  float v196; // [rsp+74h] [rbp-8Ch]
  float v197; // [rsp+78h] [rbp-88h]
  float v198; // [rsp+7Ch] [rbp-84h]
  float v199; // [rsp+80h] [rbp-80h]
  __int64 v200; // [rsp+88h] [rbp-78h]
  __int64 v201; // [rsp+90h] [rbp-70h]
  unsigned int v202; // [rsp+98h] [rbp-68h]
  float v203; // [rsp+9Ch] [rbp-64h]
  __m128 v204; // [rsp+A0h] [rbp-60h]
  __m128 v205; // [rsp+B0h] [rbp-50h] BYREF
  UFG::qMatrix44 v206; // [rsp+C0h] [rbp-40h] BYREF
  __int128 v207; // [rsp+100h] [rbp+0h]
  UFG::qMatrix44 m; // [rsp+110h] [rbp+10h] BYREF
  __m128 v209; // [rsp+150h] [rbp+50h]
  __m128 v210; // [rsp+160h] [rbp+60h]
  __m128i v211; // [rsp+170h] [rbp+70h]
  __int64 v212; // [rsp+180h] [rbp+80h]
  __m128 v213; // [rsp+190h] [rbp+90h]
  __m128 v214; // [rsp+1A0h] [rbp+A0h]
  UFG::qMatrix44 mat; // [rsp+1B0h] [rbp+B0h] BYREF
  unsigned __int64 v216; // [rsp+1F0h] [rbp+F0h]
  __int64 v217; // [rsp+1F8h] [rbp+F8h]
  __m128 v218; // [rsp+200h] [rbp+100h]
  __int64 v219; // [rsp+210h] [rbp+110h]
  __int64 v220; // [rsp+218h] [rbp+118h]
  __m128 v221; // [rsp+220h] [rbp+120h]
  __m128 v222; // [rsp+230h] [rbp+130h]
  __m128i v223; // [rsp+240h] [rbp+140h]
  __m128 v224; // [rsp+250h] [rbp+150h]
  __m128 v225; // [rsp+260h] [rbp+160h]
  __m128 v226; // [rsp+270h] [rbp+170h]
  __int128 v227; // [rsp+280h] [rbp+180h]
  __int128 v228; // [rsp+290h] [rbp+190h]
  __m128 v229; // [rsp+2A0h] [rbp+1A0h]
  __m128 v230; // [rsp+2B0h] [rbp+1B0h]
  __m128 v231; // [rsp+2C0h] [rbp+1C0h] BYREF
  __m128 v232; // [rsp+2D0h] [rbp+1D0h]
  __m128 v233; // [rsp+2E0h] [rbp+1E0h]
  char v234[16]; // [rsp+2F0h] [rbp+1F0h] BYREF
  char v235[16]; // [rsp+300h] [rbp+200h] BYREF
  char v236[16]; // [rsp+310h] [rbp+210h] BYREF
  UFG::qMatrix44 d; // [rsp+320h] [rbp+220h] BYREF
  char source[16]; // [rsp+360h] [rbp+260h] BYREF
  char v239; // [rsp+370h] [rbp+270h] BYREF
  char v240[32]; // [rsp+380h] [rbp+280h] BYREF
  char v241[32]; // [rsp+3A0h] [rbp+2A0h] BYREF
  UFG::qVector3 outpts; // [rsp+3C0h] [rbp+2C0h] BYREF
  UFG::qVector3 v243; // [rsp+540h] [rbp+440h] BYREF
  UFG::qVector3 v244; // [rsp+6C0h] [rbp+5C0h] BYREF
  __int128 v245[2]; // [rsp+840h] [rbp+740h]
  __int128 v246[1022]; // [rsp+860h] [rbp+760h] BYREF

  v4 = param0[9];
  v5 = *param0;
  v6 = param0[3];
  v7 = *((_DWORD *)param0 + 15);
  v8 = param0[1];
  v9 = param0[2];
  v10 = *((_DWORD *)param0 + 16);
  v11 = gVmxOne_4;
  v12 = *param0 == 0i64;
  v201 = param0[6];
  v13 = param0;
  v204 = gVmxOne_4;
  v186 = v12;
  v217 = v4;
  v14 = param0[14];
  v15 = *((unsigned __int16 *)param0 + 20);
  v216 = v6 & 0xFFFFFFFFFFFFFFF0ui64;
  v212 = v5;
  v220 = v8;
  v16 = (unsigned __int8)(v6 & 0xF) >> 1;
  v219 = v9;
  v17 = v16 + v7;
  v18 = v14 != 0;
  v19 = v17 <= 0x61A8;
  v20 = 2 * v17;
  v191 = v17;
  v21 = (unsigned __int8 *)v13[13];
  if ( !v19 )
    v18 = 0;
  v202 = v10;
  v187 = v20;
  v22 = 0i64;
  v200 = 0i64;
  v23 = 0i64;
  *(_QWORD *)&v207 = 0i64;
  if ( v15 )
  {
    v24 = (__m128 *)v246;
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
        v27 = (__m128 *)(v13[4] + (unsigned int)(48 * v26));
        v28 = (__m128 *)(v13[12] + (unsigned int)(v26 << 6));
        v29 = v27[1];
        v30 = v28[1];
        v31 = v28[2];
        v32 = v28[3];
        v33 = _mm_shuffle_ps(v29, v29, 255);
        v34 = _mm_add_ps(v29, v29);
        v35 = _mm_shuffle_ps(v29, v29, 201);
        v36 = _mm_shuffle_ps(v34, v34, 210);
        v37 = _mm_shuffle_ps(v29, v29, 210);
        v38 = _mm_shuffle_ps(v34, v34, 201);
        v39 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v38, v33), (__m128)0i64), _mm_mul_ps(v37, v34));
        v40 = _mm_sub_ps(_mm_sub_ps(v204, _mm_mul_ps(v38, v35)), _mm_mul_ps(v36, v37));
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
        v51 = _mm_shuffle_ps(*v27, _mm_shuffle_ps(*v27, v204, 250), 148);
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
    v11 = v204;
    v14 = v13[14];
    v20 = v187;
    v22 = 0i64;
  }
  if ( v18 )
  {
    v23 = v13[17];
    v22 = v14;
    v200 = v14;
    *(_QWORD *)&v207 = v23;
  }
  v52 = gVmxMinusOne_2;
  v53 = gVmx127_2;
  v54 = (__m128)gVmxi127_2;
  v55 = (__m128)gVmxUnpackMask_2;
  v222 = gVmxOneOver127_2;
  v224 = gVmxMinusOne_2;
  v210 = gVmx127_2;
  v230 = gVmxOneOver255_2;
  v209 = (__m128)gVmxi127_2;
  v229 = gVmxOneOver511_2;
  v211 = gVmxUnpackMask_2;
  v223 = gVmxUnpackBias_2;
  v218 = gVmxUnpackUnbias_2;
  v221 = gVmxUnpackShift_2;
  if ( v18 && v20 <= 0xC350 )
  {
    v56 = *(UFG::qVector4 *)(v22 + 128);
    v57 = *(UFG::qVector4 *)(v22 + 144);
    v58 = *(_DWORD *)(v22 + 200);
    v59 = *(__m128 *)(v22 + 64);
    v60 = *(__m128 *)(v22 + 80);
    v61 = *(_OWORD *)(v22 + 96);
    v225 = v59;
    v226 = v60;
    v227 = v61;
    v62 = *(_OWORD *)(v22 + 112);
    v63 = *(float *)(v22 + 228);
    m.v0 = v56;
    v228 = v62;
    v64 = *(_OWORD *)(v22 + 160);
    m.v1 = v57;
    v65 = *(_OWORD *)(v22 + 176);
    m.v2 = (UFG::qVector4)v64;
    LODWORD(v64) = *(_DWORD *)(v22 + 232);
    m.v3 = (UFG::qVector4)v65;
    LODWORD(v65) = *(_DWORD *)(v22 + 196);
    width = *(float *)&v64;
    v205.m128_i32[0] = *(_DWORD *)(v22 + 192);
    LODWORD(v64) = *(_DWORD *)(v22 + 208);
    *(unsigned __int64 *)((char *)v205.m128_u64 + 4) = __PAIR64__(v58, v65);
    v66 = *(_DWORD *)(v22 + 216);
    v192.m128i_i64[0] = __PAIR64__(*(_DWORD *)(v22 + 212), v64);
    v192.m128i_i32[2] = v66;
    v203 = v63;
    TransformAABB2(&m, (UFG::qVector3 *)&v205, (UFG::qVector3 *)&v192);
    v67 = 0;
    v68 = 0i64;
    v69 = v63 * 1.45;
    while ( 1 )
    {
      v70 = *(float *)((char *)&v228 + v68 * 4);
      if ( v70 + v69 <= v205.m128_f32[v68] || v70 - v69 >= *(float *)&v192.m128i_i32[v68] )
        break;
      ++v67;
      ++v68;
      if ( v67 >= 3 )
      {
        y_low = (__m128)LODWORD(m.v0.y);
        y_low.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(m.v0.x * m.v0.x))
                          + (float)(m.v0.z * m.v0.z);
        if ( y_low.m128_f32[0] == 0.0 )
          v72 = 0.0;
        else
          v72 = 1.0 / _mm_sqrt_ps(y_low).m128_f32[0];
        v206.v0.x = m.v0.x * v72;
        v206.v0.y = m.v0.y * v72;
        v206.v0.w = v72 * 0.0;
        v206.v0.z = m.v0.z * v72;
        if ( (float)((float)((float)(m.v1.y * m.v1.y) + (float)(m.v1.x * m.v1.x)) + (float)(m.v1.z * m.v1.z)) == 0.0 )
          v73 = 0.0;
        else
          v73 = 1.0 / _mm_sqrt_ps((__m128)LODWORD(m.v1.y)).m128_f32[0];
        v206.v1.x = m.v1.x * v73;
        v206.v1.y = m.v1.y * v73;
        v206.v1.z = m.v1.z * v73;
        v206.v1.w = v73 * 0.0;
        if ( (float)((float)((float)(m.v2.y * m.v2.y) + (float)(m.v2.x * m.v2.x)) + (float)(m.v2.z * m.v2.z)) == 0.0 )
          v74 = 0.0;
        else
          v74 = 1.0 / _mm_sqrt_ps((__m128)LODWORD(m.v2.y)).m128_f32[0];
        v206.v3 = m.v3;
        v206.v2.x = m.v2.x * v74;
        v206.v2.y = m.v2.y * v74;
        v206.v2.w = v74 * 0.0;
        v206.v2.z = m.v2.z * v74;
        UFG::qInverse(&d, &v206);
        v75 = (__m128)v61;
        v76 = (__m128)v62;
        v77 = (UFG::qVector4)_mm_add_ps(
                               _mm_add_ps(
                                 _mm_add_ps(
                                   _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v59, v59, 0), (__m128)d.v0), (__m128)0i64),
                                   _mm_mul_ps(_mm_shuffle_ps(v59, v59, 85), (__m128)d.v1)),
                                 _mm_mul_ps(_mm_shuffle_ps(v59, v59, 170), (__m128)d.v2)),
                               _mm_mul_ps(_mm_shuffle_ps(v59, v59, 255), (__m128)d.v3));
        mat.v0 = v77;
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
                                      _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v75, v75, 0), (__m128)d.v0), (__m128)0i64),
                                      _mm_mul_ps(_mm_shuffle_ps(v75, v75, 85), (__m128)d.v1)),
                                    _mm_mul_ps(_mm_shuffle_ps(v75, v75, 170), (__m128)d.v2)),
                                  _mm_mul_ps(_mm_shuffle_ps(v75, v75, 255), (__m128)d.v3));
        mat.v3 = (UFG::qVector4)_mm_add_ps(
                                  _mm_add_ps(
                                    _mm_add_ps(
                                      _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v76, v76, 0), (__m128)d.v0), (__m128)0i64),
                                      _mm_mul_ps(_mm_shuffle_ps(v76, v76, 85), (__m128)d.v1)),
                                    _mm_mul_ps(_mm_shuffle_ps(v76, v76, 170), (__m128)d.v2)),
                                  _mm_mul_ps(_mm_shuffle_ps(v76, v76, 255), (__m128)d.v3));
        if ( v16 < v191 )
        {
          v78 = _mm_cvtps_epi32(
                  _mm_cvtepi32_ps(
                    _mm_cvtps_epi32(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps((__m128)v77, _mm_shuffle_ps((__m128)v77, v11, 250), 148), v210),
                        v210))));
          v192 = v78;
          do
          {
            v79 = v216;
            v80 = 0;
            v81 = &v231;
            v82 = &v239;
            v83 = 0i64;
            do
            {
              v84 = v80 + v16;
              ++v80;
              v85 = *(unsigned __int16 *)(v79 + 2 * v84);
              ++v81;
              v83 += 16i64;
              v86 = 3 * v85;
              v87 = (unsigned int)(8 * v85);
              v88 = v87 + v13[6];
              v89 = v87 + v13[2];
              v90 = v13[1] + (unsigned int)(8 * v86);
              v82 += 32;
              v91 = (__m128 *)(v90 & 0xFFFFFFFFFFFFFFF0ui64 ^ ((unsigned __int8)v90 ^ v90 & 0xF0) & 0xF);
              v92 = *v91;
              v93 = v91[1];
              v94 = *(__m128 *)(v89 & 0xFFFFFFFFFFFFFFF0ui64 ^ ((unsigned __int8)v89 ^ v89 & 0xF0) & 0xF);
              v95 = *(_OWORD *)(v88 & 0xFFFFFFFFFFFFFFF0ui64 ^ ((unsigned __int8)v88 ^ v88 & 0xF0) & 0xF);
              *((__m128 *)v82 - 3) = *v91;
              *((__m128 *)v82 - 2) = v93;
              *(__m128 *)((char *)&v233 + v83) = v94;
              *(__int128 *)((char *)&v207 + v83) = v95;
              v96 = _mm_packs_epi32(v78, v78);
              *((_DWORD *)v82 - 7) = _mm_packus_epi16(v96, v96).m128i_u32[0];
              v97 = *(unsigned __int8 *)(v89 & 0xFFFFFFFFFFFFFFF0ui64) << 6;
              v98 = _mm_shuffle_ps(v92, _mm_shuffle_ps(v92, v11, 250), 148);
              v81[-1] = _mm_add_ps(
                          _mm_add_ps(
                            _mm_add_ps(
                              _mm_add_ps(
                                _mm_mul_ps(_mm_shuffle_ps(v98, v98, 0), *(__m128 *)((char *)v245 + v97)),
                                (__m128)0i64),
                              _mm_mul_ps(_mm_shuffle_ps(v98, v98, 85), *(__m128 *)((char *)&v245[1] + v97))),
                            _mm_mul_ps(_mm_shuffle_ps(v98, v98, 170), *(__m128 *)((char *)v246 + v97))),
                          _mm_mul_ps(_mm_shuffle_ps(v98, v98, 255), *(__m128 *)((char *)&v246[1] + v97)));
              v78 = _mm_load_si128(&v192);
            }
            while ( v80 < 3 );
            LODWORD(inpts.x) = v231.m128_i32[0];
            v194 = v232.m128_f32[0];
            v197 = v233.m128_f32[0];
            v99 = _mm_shuffle_ps(v233, v233, 85);
            v100 = _mm_shuffle_ps(v233, v233, 170);
            v198 = v99.m128_f32[0];
            v199 = v100.m128_f32[0];
            v214 = v99;
            v213 = v100;
            v101 = _mm_shuffle_ps(v232, v232, 85).m128_f32[0];
            v102 = _mm_shuffle_ps(v232, v232, 170).m128_f32[0];
            v195 = v101;
            v103 = _mm_shuffle_ps(v231, v231, 85).m128_f32[0];
            inpts.y = v103;
            v196 = v102;
            v205 = _mm_shuffle_ps(v231, v231, 170);
            LODWORD(inpts.z) = v205.m128_i32[0];
            v104 = (float)((float)(v101 - v103) * (float)(v100.m128_f32[0] - v102))
                 - (float)((float)(v102 - v205.m128_f32[0]) * (float)(v99.m128_f32[0] - v101));
            v105 = (float)((float)(v232.m128_f32[0] - v231.m128_f32[0]) * (float)(v99.m128_f32[0] - v101))
                 - (float)((float)(v101 - v103) * (float)(v233.m128_f32[0] - v232.m128_f32[0]));
            v106 = (float)((float)(v102 - v205.m128_f32[0]) * (float)(v233.m128_f32[0] - v232.m128_f32[0]))
                 - (float)((float)(v232.m128_f32[0] - v231.m128_f32[0]) * (float)(v100.m128_f32[0] - v102));
            v107 = (float)((float)(v106 * v106) + (float)(v104 * v104)) + (float)(v105 * v105);
            if ( v107 == 0.0 )
              v108 = 0.0;
            else
              v108 = 1.0 / fsqrt(v107);
            v23 = v207;
            if ( (float)((float)((float)(*((float *)&v227 + 1)
                                       * (float)((float)((float)((float)(v108 * v106) * v206.v1.y)
                                                       + (float)((float)(v108 * v104) * v206.v0.y))
                                               + (float)((float)(v108 * v105) * v206.v2.y)))
                               + (float)(*(float *)&v227
                                       * (float)((float)((float)((float)(v108 * v106) * v206.v1.x)
                                                       + (float)((float)(v108 * v104) * v206.v0.x))
                                               + (float)((float)(v108 * v105) * v206.v2.x))))
                       + (float)(*((float *)&v227 + 2)
                               * (float)((float)((float)((float)(v108 * v106) * v206.v1.z)
                                               + (float)((float)(v108 * v104) * v206.v0.z))
                                       + (float)((float)(v108 * v105) * v206.v2.z)))) < *(float *)(v200 + 224) )
            {
              v196 = v102 - mat.v3.z;
              v199 = v213.m128_f32[0] - mat.v3.z;
              inpts.x = v231.m128_f32[0] - mat.v3.x;
              inpts.y = v103 - mat.v3.y;
              inpts.z = v205.m128_f32[0] - mat.v3.z;
              v194 = v232.m128_f32[0] - mat.v3.x;
              v195 = v101 - mat.v3.y;
              v197 = v233.m128_f32[0] - mat.v3.x;
              v198 = v214.m128_f32[0] - mat.v3.y;
              v109 = ClipToSlab(&inpts, &outpts, 3u, &mat, width, 0);
              v110 = ClipToSlab(&outpts, &v243, v109, &mat, width, 1u);
              if ( ClipToSlab(&v243, &v244, v110, &mat, v203, 2u) )
              {
                v111 = *(_DWORD *)(v23 + 1412);
                if ( v111 < 0x1D )
                {
                  UFG::qMemCopy((void *)(v23 + 44i64 * v111), source, 0x18u);
                  UFG::qMemCopy((void *)(v23 + 44i64 * (unsigned int)(*(_DWORD *)(v23 + 1412) + 1)), v240, 0x18u);
                  UFG::qMemCopy((void *)(v23 + 44i64 * (unsigned int)(*(_DWORD *)(v23 + 1412) + 2)), v241, 0x18u);
                  UFG::qMemCopy((void *)(44i64 * *(unsigned int *)(v23 + 1412) + v23 + 24), v234, 8u);
                  UFG::qMemCopy((void *)(v23 + 44i64 * (unsigned int)(*(_DWORD *)(v23 + 1412) + 1) + 24), v235, 8u);
                  UFG::qMemCopy((void *)(v23 + 44i64 * (unsigned int)(*(_DWORD *)(v23 + 1412) + 2) + 24), v236, 8u);
                  UFG::qMemCopy((void *)(44i64 * *(unsigned int *)(v23 + 1412) + v23 + 32), &m, 8u);
                  UFG::qMemCopy((void *)(v23 + 44i64 * (unsigned int)(*(_DWORD *)(v23 + 1412) + 1) + 32), &m.v1, 8u);
                  UFG::qMemCopy((void *)(v23 + 44i64 * (unsigned int)(*(_DWORD *)(v23 + 1412) + 2) + 32), &m.v2, 8u);
                  v112 = 0;
                  p_z = &inpts.z;
                  z = mat.v1.z;
                  y = mat.v1.y;
                  v116 = 1.0 / (float)(width * 2.0);
                  x = mat.v1.x;
                  v118 = mat.v0.z;
                  v119 = mat.v0.y;
                  v120 = mat.v0.x;
                  do
                  {
                    v121 = (float)((float)((float)((float)(x * *(p_z - 2)) + (float)(y * *(p_z - 1))) + (float)(z * *p_z))
                                 * v116)
                         + 0.5;
                    v189 = (float)((float)((float)((float)(v120 * *(p_z - 2)) + (float)(v119 * *(p_z - 1)))
                                         + (float)(v118 * *p_z))
                                 * v116)
                         + 0.5;
                    v122 = fabs(v189);
                    v123 = HIWORD(LODWORD(v189)) & 0x8000;
                    if ( v122 <= 0x47FFEFFF )
                    {
                      if ( v122 >= 0x38800000 )
                        v125 = v122 - 939524096;
                      else
                        v125 = (LODWORD(v189) & 0x7FFFFF | 0x800000u) >> (113 - (v122 >> 23));
                      v124 = ((((v125 >> 13) & 1) + v125 + 4095) >> 13) | v123;
                    }
                    else
                    {
                      v124 = v123 | 0x7FFF;
                    }
                    v190 = (float)((float)((float)((float)(x * *(p_z - 2)) + (float)(y * *(p_z - 1))) + (float)(z * *p_z))
                                 * v116)
                         + 0.5;
                    *(_WORD *)(44i64 * (v112 + *(_DWORD *)(v23 + 1412)) + v23 + 40) = v124;
                    v126 = LODWORD(v121) & 0x7FFFFFFF;
                    v127 = HIWORD(LODWORD(v121)) & 0x8000;
                    if ( (LODWORD(v121) & 0x7FFFFFFFu) <= 0x47FFEFFF )
                    {
                      if ( v126 >= 0x38800000 )
                        v129 = v126 - 939524096;
                      else
                        v129 = (LODWORD(v190) & 0x7FFFFF | 0x800000u) >> (113 - (v126 >> 23));
                      v128 = ((((v129 >> 13) & 1) + v129 + 4095) >> 13) | v127;
                    }
                    else
                    {
                      v128 = v127 | 0x7FFF;
                    }
                    p_z += 3;
                    v130 = v112 + *(_DWORD *)(v23 + 1412);
                    ++v112;
                    *(_WORD *)(44 * v130 + v23 + 42) = v128;
                  }
                  while ( v112 < 3 );
                  *(_DWORD *)(v23 + 1412) += 3;
                  v13 = param0;
                }
              }
            }
            v78 = _mm_load_si128(&v192);
            v11 = v204;
            v16 += 3;
          }
          while ( v16 < v191 );
          v5 = v212;
          v8 = v220;
          v9 = v219;
        }
        break;
      }
    }
    v53 = v210;
    v52 = v224;
    v55 = (__m128)v211;
    v10 = v202;
    *(_BYTE *)(v23 + 1408) = 1;
    v54 = v209;
  }
  if ( !v186 )
  {
    v131 = *(__m128 *)(v13 + 7);
    v192 = (__m128i)v131;
    if ( v10 )
    {
      v132 = v201;
      do
      {
        v133 = 1024;
        v134 = v5;
        v135 = (__m128 *)v8;
        v136 = (_OWORD *)v132;
        v137 = (_OWORD *)v9;
        if ( v10 < 0x400 )
          v133 = v10;
        v10 -= v133;
        v138 = 24 * v133;
        v5 += v138;
        v8 += v138;
        v139 = 8 * v133;
        v9 += v139;
        v201 = v139 + v132;
        v140 = v217;
        v141 = v134 - (_QWORD)v135;
        v142 = v133;
        v143 = _mm_shuffle_ps(v131, v131, 0);
        v214 = v143;
        v213 = _mm_and_ps(v52, v204);
        do
        {
          v144 = *(__m128 *)v136;
          v145 = *(__m128 *)v137;
          v146 = v135[1];
          v147 = (unsigned __int8 *)v137;
          v137 = (_OWORD *)((char *)v137 + 8);
          v136 = (_OWORD *)((char *)v136 + 8);
          v148 = (unsigned __int64)*v147 << 6;
          v149 = *(__m128 *)((char *)v245 + v148);
          v150 = *(__m128 *)((char *)&v245[1] + v148);
          v151 = *(__m128 *)((char *)v246 + v148);
          v152 = _mm_add_ps(
                   _mm_mul_ps(
                     _mm_add_ps(
                       _mm_mul_ps(
                         _mm_add_ps(
                           _mm_cvtepi32_ps((__m128i)_mm_and_ps(
                                                      (__m128)_mm_sub_epi32(
                                                                (__m128i)_mm_shuffle_ps(v145, v145, 85),
                                                                v223),
                                                      v55)),
                           v218),
                         v221),
                       (__m128)0i64),
                     v230),
                   (__m128)0i64);
          v153 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(
                         _mm_shuffle_ps(v152, v152, 85),
                         _mm_shuffle_ps(*(__m128 *)(v140 + 4i64 * v147[1]), *(__m128 *)(v140 + 4i64 * v147[1]), 0)),
                       (__m128)0i64),
                     _mm_mul_ps(
                       _mm_shuffle_ps(v152, v152, 170),
                       _mm_shuffle_ps(*(__m128 *)(v140 + 4i64 * v147[2]), *(__m128 *)(v140 + 4i64 * v147[2]), 0))),
                   v143);
          v154 = (__m128i)_mm_and_ps((__m128)_mm_sub_epi32((__m128i)_mm_shuffle_ps(v146, v146, 0), v223), v55);
          v155 = _mm_min_ps(v153, v204);
          v156 = _mm_mul_ps(
                   _mm_cvtepi32_ps((__m128i)_mm_and_ps(_mm_shuffle_ps(v144, _mm_shuffle_ps(v144, v209, 85), 149), v55)),
                   v221);
          v157 = _mm_add_ps(
                   _mm_mul_ps(
                     _mm_sub_ps(
                       _mm_add_ps(
                         _mm_mul_ps(
                           _mm_add_ps(
                             _mm_cvtepi32_ps((__m128i)_mm_and_ps(
                                                        (__m128)_mm_sub_epi32(
                                                                  (__m128i)_mm_shuffle_ps(v146, v146, 85),
                                                                  v223),
                                                        v55)),
                             v218),
                           v221),
                         (__m128)0i64),
                       v53),
                     v222),
                   (__m128)0i64);
          v158 = _mm_mul_ps(
                   _mm_sub_ps(
                     _mm_add_ps(
                       _mm_mul_ps(
                         _mm_cvtepi32_ps((__m128i)_mm_and_ps(
                                                    _mm_shuffle_ps(v144, _mm_shuffle_ps(v144, v54, 0), 144),
                                                    v55)),
                         v221),
                       (__m128)0i64),
                     v210),
                   v229);
          v159 = _mm_shuffle_ps(v157, v157, 255);
          v160 = _mm_shuffle_ps(v157, _mm_shuffle_ps(v157, (__m128)0i64, 250), 148);
          v161 = _mm_add_ps(
                   _mm_add_ps(_mm_mul_ps(_mm_add_ps(v158, (__m128)0i64), v155), (__m128)0i64),
                   _mm_shuffle_ps(*v135, _mm_shuffle_ps(*v135, v204, 250), 148));
          v162 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(
                       _mm_add_ps(_mm_mul_ps(_mm_sub_ps(_mm_add_ps(v156, (__m128)0i64), v210), v222), (__m128)0i64),
                       v155),
                     (__m128)0i64),
                   _mm_add_ps(
                     _mm_mul_ps(
                       _mm_sub_ps(
                         _mm_add_ps(_mm_mul_ps(_mm_add_ps(_mm_cvtepi32_ps(v154), v218), v221), (__m128)0i64),
                         v210),
                       v222),
                     (__m128)0i64));
          v163 = _mm_shuffle_ps(v162, v162, 0);
          v164 = _mm_shuffle_ps(v162, v162, 85);
          v165 = _mm_shuffle_ps(v162, v162, 170);
          v166 = _mm_add_ps(
                   _mm_mul_ps(
                     _mm_rsqrt_ps(
                       _mm_add_ps(
                         _mm_add_ps(_mm_add_ps(_mm_mul_ps(v163, v163), (__m128)0i64), _mm_mul_ps(v164, v164)),
                         _mm_mul_ps(v165, v165))),
                     v162),
                   (__m128)0i64);
          v167 = _mm_shuffle_ps(v166, v166, 0);
          v168 = _mm_shuffle_ps(v166, v166, 85);
          v169 = _mm_shuffle_ps(v166, v166, 170);
          v170 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v160, v160, 0), v167), (__m128)0i64),
                     _mm_mul_ps(_mm_shuffle_ps(v160, v160, 85), v168)),
                   _mm_mul_ps(_mm_shuffle_ps(v160, v160, 170), v169));
          v171 = _mm_sub_ps(
                   v160,
                   _mm_sub_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v166, v166, 210), _mm_shuffle_ps(v170, v170, 201)),
                       (__m128)0i64),
                     _mm_mul_ps(_mm_shuffle_ps(v166, v166, 201), _mm_shuffle_ps(v170, v170, 210))));
          v172 = _mm_shuffle_ps(v171, v171, 0);
          v173 = _mm_shuffle_ps(v171, v171, 85);
          v174 = _mm_shuffle_ps(v171, v171, 170);
          v175 = _mm_add_ps(
                   _mm_mul_ps(
                     _mm_rsqrt_ps(
                       _mm_add_ps(
                         _mm_add_ps(_mm_add_ps(_mm_mul_ps(v172, v172), (__m128)0i64), _mm_mul_ps(v173, v173)),
                         _mm_mul_ps(v174, v174))),
                     v171),
                   (__m128)0i64);
          v143 = v214;
          v135 = (__m128 *)((char *)v135 + 24);
          v176 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v167, v149), (__m128)0i64), _mm_mul_ps(v168, v150));
          v177 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v161, v161, 0), v149), (__m128)0i64),
                       _mm_mul_ps(_mm_shuffle_ps(v161, v161, 85), v150)),
                     _mm_mul_ps(_mm_shuffle_ps(v161, v161, 170), v151)),
                   _mm_mul_ps(_mm_shuffle_ps(v161, v161, 255), *(__m128 *)((char *)&v246[1] + v148)));
          v53 = v210;
          v178 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v175, v175, 0), v149), (__m128)0i64),
                       _mm_mul_ps(_mm_shuffle_ps(v175, v175, 85), v150)),
                     _mm_mul_ps(_mm_shuffle_ps(v175, v175, 170), v151)),
                   _mm_mul_ps(_mm_shuffle_ps(v175, v175, 255), (__m128)0i64));
          v54 = v209;
          v179 = _mm_cvtps_epi32(
                   _mm_add_ps(
                     _mm_mul_ps(
                       _mm_add_ps(
                         _mm_add_ps(v176, _mm_mul_ps(v169, v151)),
                         _mm_mul_ps(_mm_shuffle_ps(v166, v166, 255), (__m128)0i64)),
                       v210),
                     v210));
          *(__m128 *)((char *)v135 + v141 - 24) = _mm_shuffle_ps(v177, _mm_shuffle_ps(v177, v153, 250), 148);
          v180 = _mm_cvtps_epi32(_mm_cvtepi32_ps(v179));
          v181 = _mm_packs_epi32(v180, v180);
          v182 = _mm_andnot_ps(v204, _mm_cmplt_ps(v159, (__m128)0i64));
          v55 = (__m128)v211;
          v183 = _mm_or_ps(v182, v213);
          *(int *)((char *)&v135->m128_i32[-2] + v141) = _mm_packus_epi16(v181, v181).m128i_u32[0];
          v184 = _mm_cvtps_epi32(_mm_cvtepi32_ps(_mm_cvtps_epi32(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v178, _mm_shuffle_ps(v178, v183, 250), 148), v53), v53))));
          v185 = _mm_packs_epi32(v184, v184);
          *(int *)((char *)&v135->m128_i32[-1] + v141) = _mm_packus_epi16(v185, v185).m128i_u32[0];
          --v142;
        }
        while ( v142 );
        v131 = (__m128)v192;
        v132 = v201;
        v52 = v224;
        v55 = (__m128)v211;
        v54 = v209;
      }
      while ( v10 );
    }
  }
}v211;
        v54 = v209;
      }
      while ( v10 );
    }
  }
}

// File Line: 27
// RVA: 0x76240
void __fastcall SkinVehicleGlassBufferTask(
        int worker_id,
        UFG::qMemoryStreamer *memory_streamer,
        _QWORD *param0,
        void *param1)
{
  __int64 v4; // rdx
  __int64 v5; // rdi
  __int64 v6; // rax
  int v7; // r10d
  __int64 v8; // r14
  __int64 v9; // r12
  unsigned int v10; // r9d
  __m128 v11; // xmm11
  bool v12; // zf
  _QWORD *v13; // r15
  __int64 v14; // rdx
  unsigned int v15; // r8d
  unsigned int v16; // r13d
  unsigned int v17; // r10d
  bool v18; // si
  bool v19; // cc
  unsigned int v20; // r11d
  unsigned __int8 *v21; // r10
  __int64 v22; // rax
  __int64 v23; // rbx
  __m128 *v24; // rdx
  __int64 v25; // r11
  int v26; // r8d
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
  __int128 v64; // xmm0
  __int128 v65; // xmm1
  int v66; // xmm2_4
  unsigned int v67; // esi
  unsigned int v68; // ecx
  __int64 v69; // rax
  double v70; // xmm3_8
  float v71; // xmm2_4
  __m128 y_low; // xmm4
  float v73; // xmm1_4
  float v74; // xmm1_4
  float v75; // xmm1_4
  __m128 v76; // xmm5
  __m128 v77; // xmm10
  UFG::qVector4 v78; // xmm12
  __m128i v79; // xmm3
  unsigned __int64 v80; // rbx
  __m128 *v81; // r12
  __int64 v82; // r14
  char *v83; // rdi
  __int64 v84; // rax
  int v85; // edx
  int v86; // r8d
  __int64 v87; // rcx
  __int64 v88; // r9
  __int64 v89; // rdx
  __int64 v90; // r8
  __m128 *v91; // rcx
  __m128 v92; // xmm4
  __m128 v93; // xmm2
  __m128 v94; // xmm1
  __int128 v95; // xmm0
  __m128i v96; // xmm0
  __int64 v97; // rcx
  __m128 v98; // xmm4
  __m128 v99; // xmm1
  __m128 v100; // xmm2
  float v101; // xmm12_4
  float v102; // xmm13_4
  float v103; // xmm14_4
  float v104; // xmm5_4
  float v105; // xmm8_4
  float v106; // xmm9_4
  float v107; // xmm3_4
  float v108; // xmm6_4
  unsigned int v109; // eax
  unsigned int v110; // eax
  unsigned int v111; // eax
  unsigned int v112; // r9d
  float *p_z; // r10
  float z; // xmm9_4
  float y; // xmm10_4
  float v116; // xmm7_4
  float x; // xmm11_4
  float v118; // xmm12_4
  float v119; // xmm13_4
  float v120; // xmm14_4
  float v121; // xmm6_4
  unsigned int v122; // edx
  int v123; // r8d
  __int16 v124; // r8
  unsigned int v125; // edx
  unsigned int v126; // edx
  int v127; // r8d
  __int16 v128; // r8
  unsigned int v129; // edx
  __int64 v130; // rcx
  __m128 v131; // xmm0
  __int64 v132; // r8
  unsigned int v133; // edx
  __int64 v134; // r10
  __m128 *v135; // r11
  _OWORD *v136; // rsi
  _OWORD *v137; // rbx
  __int64 v138; // rcx
  __int64 v139; // r14
  __int64 v140; // rcx
  __int64 v141; // r15
  __int64 v142; // r10
  __int64 v143; // r14
  __m128 v144; // xmm9
  __m128 v145; // xmm7
  __m128 v146; // xmm1
  unsigned __int8 *v147; // rdx
  __m128 v148; // xmm6
  unsigned __int64 v149; // r8
  __m128 v150; // xmm12
  __m128 v151; // xmm13
  __m128 v152; // xmm14
  __m128 v153; // xmm0
  __m128 v154; // xmm5
  __m128 v155; // xmm9
  __m128 v156; // xmm11
  __m128 v157; // xmm9
  __m128 v158; // xmm10
  __m128 v159; // xmm3
  __m128 v160; // xmm2
  __m128 v161; // xmm0
  __m128 v162; // xmm1
  __m128 v163; // xmm6
  __m128 v164; // xmm7
  __m128 v165; // xmm3
  __m128 v166; // xmm5
  __m128 v167; // xmm2
  __m128 v168; // xmm9
  __m128 v169; // xmm2
  __m128 v170; // xmm0
  __m128 v171; // xmm1
  __m128 v172; // xmm4
  __m128 v173; // xmm7
  __m128 v174; // xmm2
  __m128 v175; // xmm3
  __m128 v176; // xmm7
  __m128i v177; // xmm2
  __m128i v178; // xmm2
  __m128 v179; // xmm1
  __m128i v180; // xmm2
  __m128i v181; // xmm2
  bool v182; // [rsp+30h] [rbp-D0h]
  unsigned int v183; // [rsp+34h] [rbp-CCh]
  float width; // [rsp+34h] [rbp-CCh]
  float v185; // [rsp+38h] [rbp-C8h]
  float v186; // [rsp+38h] [rbp-C8h]
  unsigned int v187; // [rsp+40h] [rbp-C0h]
  __m128i v188; // [rsp+50h] [rbp-B0h] BYREF
  UFG::qVector3 inpts; // [rsp+60h] [rbp-A0h] BYREF
  float v190; // [rsp+6Ch] [rbp-94h]
  float v191; // [rsp+70h] [rbp-90h]
  float v192; // [rsp+74h] [rbp-8Ch]
  float v193; // [rsp+78h] [rbp-88h]
  float v194; // [rsp+7Ch] [rbp-84h]
  float v195; // [rsp+80h] [rbp-80h]
  __int64 v196; // [rsp+88h] [rbp-78h]
  __int64 v197; // [rsp+90h] [rbp-70h]
  float v198; // [rsp+98h] [rbp-68h]
  unsigned int v199; // [rsp+9Ch] [rbp-64h]
  __int64 v200; // [rsp+A0h] [rbp-60h]
  __m128 v201; // [rsp+B0h] [rbp-50h]
  __m128 v202; // [rsp+C0h] [rbp-40h] BYREF
  UFG::qMatrix44 v203; // [rsp+D0h] [rbp-30h] BYREF
  __int128 v204; // [rsp+110h] [rbp+10h]
  UFG::qMatrix44 m; // [rsp+120h] [rbp+20h] BYREF
  __m128 v206; // [rsp+160h] [rbp+60h]
  __m128 v207; // [rsp+170h] [rbp+70h]
  __m128 v208; // [rsp+180h] [rbp+80h]
  __m128 v209; // [rsp+190h] [rbp+90h]
  __m128 v210; // [rsp+1A0h] [rbp+A0h]
  __m128 v211; // [rsp+1B0h] [rbp+B0h]
  __int64 v212; // [rsp+1C0h] [rbp+C0h]
  __int64 v213; // [rsp+1C8h] [rbp+C8h]
  __int64 v214; // [rsp+1D0h] [rbp+D0h]
  UFG::qMatrix44 mat; // [rsp+1E0h] [rbp+E0h] BYREF
  unsigned __int64 v216; // [rsp+220h] [rbp+120h]
  __m128i v217; // [rsp+230h] [rbp+130h]
  __m128 v218; // [rsp+240h] [rbp+140h]
  __m128 v219; // [rsp+250h] [rbp+150h]
  __m128 v220; // [rsp+260h] [rbp+160h]
  __m128 v221; // [rsp+270h] [rbp+170h]
  __m128 v222; // [rsp+280h] [rbp+180h]
  __int128 v223; // [rsp+290h] [rbp+190h]
  __int128 v224; // [rsp+2A0h] [rbp+1A0h]
  __m128 v225; // [rsp+2B0h] [rbp+1B0h]
  __m128 v226; // [rsp+2C0h] [rbp+1C0h]
  __m128 v227; // [rsp+2D0h] [rbp+1D0h] BYREF
  __m128 v228; // [rsp+2E0h] [rbp+1E0h]
  __m128 v229; // [rsp+2F0h] [rbp+1F0h]
  char v230[16]; // [rsp+300h] [rbp+200h] BYREF
  char v231[16]; // [rsp+310h] [rbp+210h] BYREF
  char v232[16]; // [rsp+320h] [rbp+220h] BYREF
  UFG::qMatrix44 d; // [rsp+330h] [rbp+230h] BYREF
  char source[16]; // [rsp+370h] [rbp+270h] BYREF
  char v235; // [rsp+380h] [rbp+280h] BYREF
  char v236[32]; // [rsp+390h] [rbp+290h] BYREF
  char v237[32]; // [rsp+3B0h] [rbp+2B0h] BYREF
  UFG::qVector3 outpts; // [rsp+3D0h] [rbp+2D0h] BYREF
  UFG::qVector3 v239; // [rsp+550h] [rbp+450h] BYREF
  UFG::qVector3 v240; // [rsp+6D0h] [rbp+5D0h] BYREF
  __int128 v241[2]; // [rsp+850h] [rbp+750h]
  __int128 v242[1022]; // [rsp+870h] [rbp+770h] BYREF

  v4 = param0[9];
  v5 = *param0;
  v6 = param0[3];
  v7 = *((_DWORD *)param0 + 15);
  v8 = param0[1];
  v9 = param0[2];
  v10 = *((_DWORD *)param0 + 16);
  v11 = gVmxOne_4;
  v12 = *param0 == 0i64;
  v200 = param0[6];
  v13 = param0;
  v201 = gVmxOne_4;
  v182 = v12;
  v212 = v4;
  v14 = param0[14];
  v15 = *((unsigned __int16 *)param0 + 20);
  v216 = v6 & 0xFFFFFFFFFFFFFFF0ui64;
  v213 = v5;
  v197 = v8;
  v16 = (unsigned __int8)(v6 & 0xF) >> 1;
  v214 = v9;
  v17 = v16 + v7;
  v18 = v14 != 0;
  v19 = v17 <= 0x61A8;
  v20 = 2 * v17;
  v187 = v17;
  v21 = (unsigned __int8 *)v13[13];
  if ( !v19 )
    v18 = 0;
  v199 = v10;
  v183 = v20;
  v22 = 0i64;
  v196 = 0i64;
  v23 = 0i64;
  *(_QWORD *)&v204 = 0i64;
  if ( v15 )
  {
    v24 = (__m128 *)v242;
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
        v27 = (__m128 *)(v13[4] + (unsigned int)(48 * v26));
        v28 = (__m128 *)(v13[12] + (unsigned int)(v26 << 6));
        v29 = v27[1];
        v30 = v28[1];
        v31 = v28[2];
        v32 = v28[3];
        v33 = _mm_shuffle_ps(v29, v29, 255);
        v34 = _mm_add_ps(v29, v29);
        v35 = _mm_shuffle_ps(v29, v29, 201);
        v36 = _mm_shuffle_ps(v34, v34, 210);
        v37 = _mm_shuffle_ps(v29, v29, 210);
        v38 = _mm_shuffle_ps(v34, v34, 201);
        v39 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v38, v33), (__m128)0i64), _mm_mul_ps(v37, v34));
        v40 = _mm_sub_ps(_mm_sub_ps(v201, _mm_mul_ps(v38, v35)), _mm_mul_ps(v36, v37));
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
        v51 = _mm_shuffle_ps(*v27, _mm_shuffle_ps(*v27, v201, 250), 148);
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
    v11 = v201;
    v14 = v13[14];
    v20 = v183;
    v22 = 0i64;
  }
  if ( v18 )
  {
    v23 = v13[17];
    v22 = v14;
    v196 = v14;
    *(_QWORD *)&v204 = v23;
  }
  v52 = gVmxMinusOne_2;
  v53 = gVmx127_2;
  v54 = (__m128)gVmxi127_2;
  v55 = gVmxUnpackShift_2;
  v219 = gVmxOneOver127_2;
  v218 = gVmxMinusOne_2;
  v206 = gVmx127_2;
  v226 = gVmxOneOver255_2;
  v208 = (__m128)gVmxi127_2;
  v225 = gVmxOneOver511_2;
  v207 = gVmxUnpackShift_2;
  v217 = gVmxUnpackBias_2;
  v220 = (__m128)gVmxUnpackMask_2;
  v209 = gVmxUnpackUnbias_2;
  if ( v18 && v20 <= 0xC350 )
  {
    v56 = *(UFG::qVector4 *)(v22 + 128);
    v57 = *(UFG::qVector4 *)(v22 + 144);
    v58 = *(_DWORD *)(v22 + 200);
    v59 = *(__m128 *)(v22 + 64);
    v60 = *(__m128 *)(v22 + 80);
    v61 = *(_OWORD *)(v22 + 96);
    v221 = v59;
    v222 = v60;
    v223 = v61;
    v62 = *(_OWORD *)(v22 + 112);
    v63 = *(float *)(v22 + 228);
    m.v0 = v56;
    v224 = v62;
    v64 = *(_OWORD *)(v22 + 160);
    m.v1 = v57;
    v65 = *(_OWORD *)(v22 + 176);
    m.v2 = (UFG::qVector4)v64;
    LODWORD(v64) = *(_DWORD *)(v22 + 232);
    m.v3 = (UFG::qVector4)v65;
    LODWORD(v65) = *(_DWORD *)(v22 + 196);
    width = *(float *)&v64;
    v202.m128_i32[0] = *(_DWORD *)(v22 + 192);
    LODWORD(v64) = *(_DWORD *)(v22 + 208);
    *(unsigned __int64 *)((char *)v202.m128_u64 + 4) = __PAIR64__(v58, v65);
    v66 = *(_DWORD *)(v22 + 216);
    v188.m128i_i64[0] = __PAIR64__(*(_DWORD *)(v22 + 212), v64);
    v188.m128i_i32[2] = v66;
    v198 = v63;
    TransformAABB2(&m, (UFG::qVector3 *)&v202, (UFG::qVector3 *)&v188);
    v67 = 0;
    v68 = 0;
    v69 = 0i64;
    v70 = v63 * 1.45;
    while ( 1 )
    {
      v71 = *(float *)((char *)&v224 + v69 * 4);
      if ( v71 + v70 <= v202.m128_f32[v69] || v71 - v70 >= *(float *)&v188.m128i_i32[v69] )
        break;
      ++v68;
      ++v69;
      if ( v68 >= 3 )
      {
        y_low = (__m128)LODWORD(m.v0.y);
        y_low.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(m.v0.x * m.v0.x))
                          + (float)(m.v0.z * m.v0.z);
        if ( y_low.m128_f32[0] == 0.0 )
          v73 = 0.0;
        else
          v73 = 1.0 / _mm_sqrt_ps(y_low).m128_f32[0];
        v203.v0.x = m.v0.x * v73;
        v203.v0.y = m.v0.y * v73;
        v203.v0.w = v73 * 0.0;
        v203.v0.z = m.v0.z * v73;
        if ( (float)((float)((float)(m.v1.y * m.v1.y) + (float)(m.v1.x * m.v1.x)) + (float)(m.v1.z * m.v1.z)) == 0.0 )
          v74 = 0.0;
        else
          v74 = 1.0 / _mm_sqrt_ps((__m128)LODWORD(m.v1.y)).m128_f32[0];
        v203.v1.x = m.v1.x * v74;
        v203.v1.y = m.v1.y * v74;
        v203.v1.z = m.v1.z * v74;
        v203.v1.w = v74 * 0.0;
        if ( (float)((float)((float)(m.v2.y * m.v2.y) + (float)(m.v2.x * m.v2.x)) + (float)(m.v2.z * m.v2.z)) == 0.0 )
          v75 = 0.0;
        else
          v75 = 1.0 / _mm_sqrt_ps((__m128)LODWORD(m.v2.y)).m128_f32[0];
        v203.v3 = m.v3;
        v203.v2.x = m.v2.x * v75;
        v203.v2.y = m.v2.y * v75;
        v203.v2.w = v75 * 0.0;
        v203.v2.z = m.v2.z * v75;
        UFG::qInverse(&d, &v203);
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
        if ( v16 < v187 )
        {
          v79 = _mm_cvtps_epi32(
                  _mm_cvtepi32_ps(
                    _mm_cvtps_epi32(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps((__m128)v78, _mm_shuffle_ps((__m128)v78, v11, 250), 148), v206),
                        v206))));
          v188 = v79;
          do
          {
            v80 = v216;
            v81 = &v227;
            v82 = 0i64;
            v83 = &v235;
            do
            {
              v84 = v67 + v16;
              ++v67;
              v85 = *(unsigned __int16 *)(v80 + 2 * v84);
              ++v81;
              v82 += 16i64;
              v86 = 3 * v85;
              v87 = (unsigned int)(8 * v85);
              v88 = v87 + v13[6];
              v89 = v87 + v13[2];
              v90 = v13[1] + (unsigned int)(8 * v86);
              v83 += 32;
              v91 = (__m128 *)(v90 & 0xFFFFFFFFFFFFFFF0ui64 ^ ((unsigned __int8)v90 ^ v90 & 0xF0) & 0xF);
              v92 = *v91;
              v93 = v91[1];
              v94 = *(__m128 *)(v89 & 0xFFFFFFFFFFFFFFF0ui64 ^ ((unsigned __int8)v89 ^ v89 & 0xF0) & 0xF);
              v95 = *(_OWORD *)(v88 & 0xFFFFFFFFFFFFFFF0ui64 ^ ((unsigned __int8)v88 ^ v88 & 0xF0) & 0xF);
              *((__m128 *)v83 - 3) = *v91;
              *((__m128 *)v83 - 2) = v93;
              *(__m128 *)((char *)&v229 + v82) = v94;
              *(__int128 *)((char *)&v204 + v82) = v95;
              v96 = _mm_packs_epi32(v79, v79);
              *((_DWORD *)v83 - 7) = _mm_packus_epi16(v96, v96).m128i_u32[0];
              v97 = *(unsigned __int8 *)(v89 & 0xFFFFFFFFFFFFFFF0ui64) << 6;
              v98 = _mm_shuffle_ps(v92, _mm_shuffle_ps(v92, v11, 250), 148);
              v81[-1] = _mm_add_ps(
                          _mm_add_ps(
                            _mm_add_ps(
                              _mm_add_ps(
                                _mm_mul_ps(_mm_shuffle_ps(v98, v98, 0), *(__m128 *)((char *)v241 + v97)),
                                (__m128)0i64),
                              _mm_mul_ps(_mm_shuffle_ps(v98, v98, 85), *(__m128 *)((char *)&v241[1] + v97))),
                            _mm_mul_ps(_mm_shuffle_ps(v98, v98, 170), *(__m128 *)((char *)v242 + v97))),
                          _mm_mul_ps(_mm_shuffle_ps(v98, v98, 255), *(__m128 *)((char *)&v242[1] + v97)));
              v79 = _mm_load_si128(&v188);
            }
            while ( v67 < 3 );
            LODWORD(inpts.x) = v227.m128_i32[0];
            v190 = v228.m128_f32[0];
            v193 = v229.m128_f32[0];
            v99 = _mm_shuffle_ps(v229, v229, 85);
            v100 = _mm_shuffle_ps(v229, v229, 170);
            v194 = v99.m128_f32[0];
            v195 = v100.m128_f32[0];
            v210 = v99;
            v211 = v100;
            v101 = _mm_shuffle_ps(v228, v228, 85).m128_f32[0];
            v102 = _mm_shuffle_ps(v228, v228, 170).m128_f32[0];
            v191 = v101;
            v103 = _mm_shuffle_ps(v227, v227, 85).m128_f32[0];
            inpts.y = v103;
            v192 = v102;
            v202 = _mm_shuffle_ps(v227, v227, 170);
            LODWORD(inpts.z) = v202.m128_i32[0];
            v104 = (float)((float)(v101 - v103) * (float)(v100.m128_f32[0] - v102))
                 - (float)((float)(v102 - v202.m128_f32[0]) * (float)(v99.m128_f32[0] - v101));
            v105 = (float)((float)(v228.m128_f32[0] - v227.m128_f32[0]) * (float)(v99.m128_f32[0] - v101))
                 - (float)((float)(v101 - v103) * (float)(v229.m128_f32[0] - v228.m128_f32[0]));
            v106 = (float)((float)(v102 - v202.m128_f32[0]) * (float)(v229.m128_f32[0] - v228.m128_f32[0]))
                 - (float)((float)(v228.m128_f32[0] - v227.m128_f32[0]) * (float)(v100.m128_f32[0] - v102));
            v107 = (float)((float)(v106 * v106) + (float)(v104 * v104)) + (float)(v105 * v105);
            if ( v107 == 0.0 )
              v108 = 0.0;
            else
              v108 = 1.0 / fsqrt(v107);
            v23 = v204;
            if ( (float)((float)((float)(*((float *)&v223 + 1)
                                       * (float)((float)((float)((float)(v108 * v106) * v203.v1.y)
                                                       + (float)((float)(v108 * v104) * v203.v0.y))
                                               + (float)((float)(v108 * v105) * v203.v2.y)))
                               + (float)(*(float *)&v223
                                       * (float)((float)((float)((float)(v108 * v106) * v203.v1.x)
                                                       + (float)((float)(v108 * v104) * v203.v0.x))
                                               + (float)((float)(v108 * v105) * v203.v2.x))))
                       + (float)(*((float *)&v223 + 2)
                               * (float)((float)((float)((float)(v108 * v106) * v203.v1.z)
                                               + (float)((float)(v108 * v104) * v203.v0.z))
                                       + (float)((float)(v108 * v105) * v203.v2.z)))) >= *(float *)(v196 + 224) )
            {
              v67 = 0;
            }
            else
            {
              v67 = 0;
              v192 = v102 - mat.v3.z;
              v195 = v211.m128_f32[0] - mat.v3.z;
              inpts.x = v227.m128_f32[0] - mat.v3.x;
              inpts.y = v103 - mat.v3.y;
              inpts.z = v202.m128_f32[0] - mat.v3.z;
              v190 = v228.m128_f32[0] - mat.v3.x;
              v191 = v101 - mat.v3.y;
              v193 = v229.m128_f32[0] - mat.v3.x;
              v194 = v210.m128_f32[0] - mat.v3.y;
              v109 = ClipToSlab(&inpts, &outpts, 3u, &mat, width, 0);
              v110 = ClipToSlab(&outpts, &v239, v109, &mat, width, 1u);
              if ( ClipToSlab(&v239, &v240, v110, &mat, v198, 2u) )
              {
                v111 = *(_DWORD *)(v23 + 1412);
                if ( v111 < 0x1D )
                {
                  UFG::qMemCopy((void *)(v23 + 44i64 * v111), source, 0x18u);
                  UFG::qMemCopy((void *)(v23 + 44i64 * (unsigned int)(*(_DWORD *)(v23 + 1412) + 1)), v236, 0x18u);
                  UFG::qMemCopy((void *)(v23 + 44i64 * (unsigned int)(*(_DWORD *)(v23 + 1412) + 2)), v237, 0x18u);
                  UFG::qMemCopy((void *)(44i64 * *(unsigned int *)(v23 + 1412) + v23 + 24), v230, 8u);
                  UFG::qMemCopy((void *)(v23 + 44i64 * (unsigned int)(*(_DWORD *)(v23 + 1412) + 1) + 24), v231, 8u);
                  UFG::qMemCopy((void *)(v23 + 44i64 * (unsigned int)(*(_DWORD *)(v23 + 1412) + 2) + 24), v232, 8u);
                  UFG::qMemCopy((void *)(44i64 * *(unsigned int *)(v23 + 1412) + v23 + 32), &m, 8u);
                  UFG::qMemCopy((void *)(v23 + 44i64 * (unsigned int)(*(_DWORD *)(v23 + 1412) + 1) + 32), &m.v1, 8u);
                  UFG::qMemCopy((void *)(v23 + 44i64 * (unsigned int)(*(_DWORD *)(v23 + 1412) + 2) + 32), &m.v2, 8u);
                  v112 = 0;
                  p_z = &inpts.z;
                  z = mat.v1.z;
                  y = mat.v1.y;
                  v116 = 1.0 / (float)(width * 2.0);
                  x = mat.v1.x;
                  v118 = mat.v0.z;
                  v119 = mat.v0.y;
                  v120 = mat.v0.x;
                  do
                  {
                    v121 = (float)((float)((float)((float)(x * *(p_z - 2)) + (float)(y * *(p_z - 1))) + (float)(z * *p_z))
                                 * v116)
                         + 0.5;
                    v185 = (float)((float)((float)((float)(v120 * *(p_z - 2)) + (float)(v119 * *(p_z - 1)))
                                         + (float)(v118 * *p_z))
                                 * v116)
                         + 0.5;
                    v122 = fabs(v185);
                    v123 = HIWORD(LODWORD(v185)) & 0x8000;
                    if ( v122 <= 0x47FFEFFF )
                    {
                      if ( v122 >= 0x38800000 )
                        v125 = v122 - 939524096;
                      else
                        v125 = (LODWORD(v185) & 0x7FFFFF | 0x800000u) >> (113 - (v122 >> 23));
                      v124 = ((((v125 >> 13) & 1) + v125 + 4095) >> 13) | v123;
                    }
                    else
                    {
                      v124 = v123 | 0x7FFF;
                    }
                    v186 = (float)((float)((float)((float)(x * *(p_z - 2)) + (float)(y * *(p_z - 1))) + (float)(z * *p_z))
                                 * v116)
                         + 0.5;
                    *(_WORD *)(44i64 * (v112 + *(_DWORD *)(v23 + 1412)) + v23 + 40) = v124;
                    v126 = LODWORD(v121) & 0x7FFFFFFF;
                    v127 = HIWORD(LODWORD(v121)) & 0x8000;
                    if ( (LODWORD(v121) & 0x7FFFFFFFu) <= 0x47FFEFFF )
                    {
                      if ( v126 >= 0x38800000 )
                        v129 = v126 - 939524096;
                      else
                        v129 = (LODWORD(v186) & 0x7FFFFF | 0x800000u) >> (113 - (v126 >> 23));
                      v128 = ((((v129 >> 13) & 1) + v129 + 4095) >> 13) | v127;
                    }
                    else
                    {
                      v128 = v127 | 0x7FFF;
                    }
                    p_z += 3;
                    v130 = v112 + *(_DWORD *)(v23 + 1412);
                    ++v112;
                    *(_WORD *)(44 * v130 + v23 + 42) = v128;
                  }
                  while ( v112 < 3 );
                  *(_DWORD *)(v23 + 1412) += 3;
                  v13 = param0;
                }
              }
            }
            v79 = _mm_load_si128(&v188);
            v11 = v201;
            v16 += 3;
          }
          while ( v16 < v187 );
          v5 = v213;
          v8 = v197;
          v9 = v214;
        }
        break;
      }
    }
    v53 = v206;
    v52 = v218;
    v55 = v207;
    v10 = v199;
    *(_BYTE *)(v23 + 1408) = 1;
    v54 = v208;
  }
  if ( !v182 )
  {
    v131 = *(__m128 *)(v13 + 7);
    v188 = (__m128i)v131;
    if ( v10 )
    {
      v132 = v200;
      do
      {
        v133 = 1024;
        v134 = v5;
        v135 = (__m128 *)v8;
        v136 = (_OWORD *)v132;
        v137 = (_OWORD *)v9;
        if ( v10 < 0x400 )
          v133 = v10;
        v10 -= v133;
        v138 = 24 * v133;
        v139 = v138 + v8;
        v5 += v138;
        v140 = 8 * v133;
        v9 += v140;
        v197 = v139;
        v200 = v140 + v132;
        v141 = v212;
        v142 = v134 - (_QWORD)v135;
        v143 = v133;
        v144 = _mm_shuffle_ps(v131, v131, 0);
        v210 = v144;
        v211 = _mm_and_ps(v52, v201);
        do
        {
          v145 = *(__m128 *)v136;
          v146 = *(__m128 *)v137;
          v147 = (unsigned __int8 *)v137;
          v137 = (_OWORD *)((char *)v137 + 8);
          v136 = (_OWORD *)((char *)v136 + 8);
          v148 = v135[1];
          v149 = (unsigned __int64)*v147 << 6;
          v150 = *(__m128 *)((char *)v241 + v149);
          v151 = *(__m128 *)((char *)&v241[1] + v149);
          v152 = *(__m128 *)((char *)v242 + v149);
          v153 = _mm_add_ps(
                   _mm_mul_ps(
                     _mm_add_ps(
                       _mm_mul_ps(
                         _mm_add_ps(
                           _mm_cvtepi32_ps((__m128i)_mm_and_ps(
                                                      (__m128)_mm_sub_epi32(
                                                                (__m128i)_mm_shuffle_ps(v146, v146, 85),
                                                                v217),
                                                      v220)),
                           v209),
                         v55),
                       (__m128)0i64),
                     v226),
                   (__m128)0i64);
          v154 = _mm_min_ps(
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(
                           _mm_shuffle_ps(v153, v153, 85),
                           _mm_shuffle_ps(*(__m128 *)(v141 + 4i64 * v147[1]), *(__m128 *)(v141 + 4i64 * v147[1]), 0)),
                         (__m128)0i64),
                       _mm_mul_ps(
                         _mm_shuffle_ps(v153, v153, 170),
                         _mm_shuffle_ps(*(__m128 *)(v141 + 4i64 * v147[2]), *(__m128 *)(v141 + 4i64 * v147[2]), 0))),
                     v144),
                   v201);
          v155 = _mm_add_ps(
                   _mm_mul_ps(
                     _mm_sub_ps(
                       _mm_add_ps(
                         _mm_mul_ps(
                           _mm_add_ps(
                             _mm_cvtepi32_ps((__m128i)_mm_and_ps(
                                                        (__m128)_mm_sub_epi32(
                                                                  (__m128i)_mm_shuffle_ps(v148, v148, 85),
                                                                  v217),
                                                        v220)),
                             v209),
                           v207),
                         (__m128)0i64),
                       v53),
                     v219),
                   (__m128)0i64);
          v156 = _mm_shuffle_ps(v155, v155, 255);
          v157 = _mm_shuffle_ps(v155, _mm_shuffle_ps(v155, (__m128)0i64, 250), 148);
          v158 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(
                       _mm_add_ps(
                         _mm_mul_ps(
                           _mm_sub_ps(
                             _mm_add_ps(
                               _mm_mul_ps(
                                 _mm_cvtepi32_ps((__m128i)_mm_and_ps(
                                                            _mm_shuffle_ps(v145, _mm_shuffle_ps(v145, v54, 0), 144),
                                                            v220)),
                                 v207),
                               (__m128)0i64),
                             v206),
                           v225),
                         (__m128)0i64),
                       v154),
                     (__m128)0i64),
                   _mm_shuffle_ps(*v135, _mm_shuffle_ps(*v135, v201, 250), 148));
          v159 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(
                       _mm_add_ps(
                         _mm_mul_ps(
                           _mm_sub_ps(
                             _mm_add_ps(
                               _mm_mul_ps(
                                 _mm_cvtepi32_ps((__m128i)_mm_and_ps(
                                                            _mm_shuffle_ps(v145, _mm_shuffle_ps(v145, v208, 85), 149),
                                                            v220)),
                                 v207),
                               (__m128)0i64),
                             v206),
                           v219),
                         (__m128)0i64),
                       v154),
                     (__m128)0i64),
                   _mm_add_ps(
                     _mm_mul_ps(
                       _mm_sub_ps(
                         _mm_add_ps(
                           _mm_mul_ps(
                             _mm_add_ps(
                               _mm_cvtepi32_ps((__m128i)_mm_and_ps(
                                                          (__m128)_mm_sub_epi32(
                                                                    (__m128i)_mm_shuffle_ps(v148, v148, 0),
                                                                    v217),
                                                          v220)),
                               v209),
                             v207),
                           (__m128)0i64),
                         v206),
                       v219),
                     (__m128)0i64));
          v160 = _mm_shuffle_ps(v159, v159, 0);
          v161 = _mm_shuffle_ps(v159, v159, 85);
          v162 = _mm_shuffle_ps(v159, v159, 170);
          v163 = _mm_add_ps(
                   _mm_mul_ps(
                     _mm_rsqrt_ps(
                       _mm_add_ps(
                         _mm_add_ps(_mm_add_ps(_mm_mul_ps(v160, v160), (__m128)0i64), _mm_mul_ps(v161, v161)),
                         _mm_mul_ps(v162, v162))),
                     v159),
                   (__m128)0i64);
          v164 = _mm_shuffle_ps(v163, v163, 0);
          v165 = _mm_shuffle_ps(v163, v163, 85);
          v166 = _mm_shuffle_ps(v163, v163, 170);
          v167 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v157, v157, 0), v164), (__m128)0i64),
                     _mm_mul_ps(_mm_shuffle_ps(v157, v157, 85), v165)),
                   _mm_mul_ps(_mm_shuffle_ps(v157, v157, 170), v166));
          v168 = _mm_sub_ps(
                   v157,
                   _mm_sub_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v163, v163, 210), _mm_shuffle_ps(v167, v167, 201)),
                       (__m128)0i64),
                     _mm_mul_ps(_mm_shuffle_ps(v163, v163, 201), _mm_shuffle_ps(v167, v167, 210))));
          v169 = _mm_shuffle_ps(v168, v168, 0);
          v170 = _mm_shuffle_ps(v168, v168, 85);
          v171 = _mm_shuffle_ps(v168, v168, 170);
          v172 = _mm_add_ps(
                   _mm_mul_ps(
                     _mm_rsqrt_ps(
                       _mm_add_ps(
                         _mm_add_ps(_mm_add_ps(_mm_mul_ps(v169, v169), (__m128)0i64), _mm_mul_ps(v170, v170)),
                         _mm_mul_ps(v171, v171))),
                     v168),
                   (__m128)0i64);
          v144 = v210;
          v135 = (__m128 *)((char *)v135 + 24);
          v173 = _mm_add_ps(
                   _mm_add_ps(_mm_add_ps(_mm_mul_ps(v164, v150), (__m128)0i64), _mm_mul_ps(v165, v151)),
                   _mm_mul_ps(v166, v152));
          v55 = v207;
          v174 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v158, v158, 0), v150), (__m128)0i64),
                       _mm_mul_ps(_mm_shuffle_ps(v158, v158, 85), v151)),
                     _mm_mul_ps(_mm_shuffle_ps(v158, v158, 170), v152)),
                   _mm_mul_ps(_mm_shuffle_ps(v158, v158, 255), *(__m128 *)((char *)&v242[1] + v149)));
          v53 = v206;
          v175 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v172, v172, 0), v150), (__m128)0i64),
                       _mm_mul_ps(_mm_shuffle_ps(v172, v172, 85), v151)),
                     _mm_mul_ps(_mm_shuffle_ps(v172, v172, 170), v152)),
                   _mm_mul_ps(_mm_shuffle_ps(v172, v172, 255), (__m128)0i64));
          v54 = v208;
          v176 = _mm_mul_ps(_mm_add_ps(v173, _mm_mul_ps(_mm_shuffle_ps(v163, v163, 255), (__m128)0i64)), v206);
          *(__m128 *)((char *)v135 + v142 - 24) = _mm_shuffle_ps(
                                                    v174,
                                                    _mm_shuffle_ps(
                                                      v174,
                                                      _mm_shuffle_ps(
                                                        *(__m128 *)(v141 + 4i64 * v147[3]),
                                                        *(__m128 *)(v141 + 4i64 * v147[3]),
                                                        0),
                                                      250),
                                                    148);
          v177 = _mm_cvtps_epi32(_mm_cvtepi32_ps(_mm_cvtps_epi32(_mm_add_ps(v176, v53))));
          v178 = _mm_packs_epi32(v177, v177);
          v179 = _mm_or_ps(_mm_andnot_ps(v201, _mm_cmplt_ps(v156, (__m128)0i64)), v211);
          *(int *)((char *)&v135->m128_i32[-2] + v142) = _mm_packus_epi16(v178, v178).m128i_u32[0];
          v180 = _mm_cvtps_epi32(_mm_cvtepi32_ps(_mm_cvtps_epi32(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v175, _mm_shuffle_ps(v175, v179, 250), 148), v53), v53))));
          v181 = _mm_packs_epi32(v180, v180);
          *(int *)((char *)&v135->m128_i32[-1] + v142) = _mm_packus_epi16(v181, v181).m128i_u32[0];
          --v143;
        }
        while ( v143 );
        v131 = (__m128)v188;
        v8 = v197;
        v132 = v200;
        v52 = v218;
        v55 = v207;
        v54 = v208;
      }
      while ( v10 );
    }
  }
}

// File Line: 35
// RVA: 0x77730
void __fastcall SkinVehicleDecalBufferTask(
        int worker_id,
        UFG::qMemoryStreamer *memory_streamer,
        unsigned __int16 *param0,
        void *param1)
{
  __int64 v4; // rbp
  __int64 v5; // r15
  __int64 v6; // r14
  unsigned __int8 *v7; // r9
  __m128 v9; // xmm10
  __int64 v10; // rbx
  __int64 v11; // rdi
  __m128 *v12; // rdx
  __int64 v13; // r11
  int v14; // r8d
  __int64 v15; // rcx
  __m128 *v16; // rax
  __m128 v17; // xmm5
  __m128 v18; // xmm11
  __m128 v19; // xmm12
  __m128 v20; // xmm13
  __m128 v21; // xmm4
  __m128 v22; // xmm3
  __m128 v23; // xmm8
  __m128 v24; // xmm5
  __m128 v25; // xmm1
  __m128 v26; // xmm6
  __m128 v27; // xmm7
  __m128 v28; // xmm0
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
  __m128 v42; // xmm9
  __m128 v43; // xmm4
  __m128 v44; // xmm11
  __int64 v45; // r8
  __m128 v46; // xmm8
  __int64 v47; // rbp
  unsigned __int8 *v48; // r14
  __m128 v49; // xmm5
  unsigned __int64 v50; // rdx
  __m128 v51; // xmm12
  __m128 v52; // xmm13
  __m128 v53; // xmm2
  __m128i v54; // xmm4
  __m128 v55; // xmm14
  __m128i v56; // xmm6
  __m128 v57; // xmm0
  __m128 v58; // xmm11
  __m128 v59; // xmm1
  __m128 v60; // xmm8
  __m128 v61; // xmm10
  __m128 v62; // xmm8
  __m128 v63; // xmm9
  __m128 v64; // xmm3
  __m128 v65; // xmm2
  __m128 v66; // xmm0
  __m128 v67; // xmm1
  __m128 v68; // xmm6
  __m128 v69; // xmm7
  __m128 v70; // xmm3
  __m128 v71; // xmm5
  __m128 v72; // xmm2
  __m128 v73; // xmm8
  __m128 v74; // xmm2
  __m128 v75; // xmm0
  __m128 v76; // xmm1
  __m128 v77; // xmm4
  __m128 v78; // xmm7
  __m128 v79; // xmm2
  __m128 v80; // xmm0
  __m128 v81; // xmm3
  __m128i v82; // xmm2
  __m128i v83; // xmm2
  __m128 v84; // xmm1
  __m128i v85; // xmm2
  __m128i v86; // xmm2
  __m128 v87; // [rsp+90h] [rbp-40D8h]
  __m128 v88; // [rsp+A0h] [rbp-40C8h]
  __int128 v89[2]; // [rsp+C0h] [rbp-40A8h]
  __int128 v90[1022]; // [rsp+E0h] [rbp-4088h] BYREF

  v4 = *(_QWORD *)param0;
  v5 = *((_QWORD *)param0 + 9);
  v6 = *((_QWORD *)param0 + 15);
  v7 = (unsigned __int8 *)*((_QWORD *)param0 + 13);
  v9 = gVmxOne_4;
  v10 = *((_QWORD *)param0 + 4);
  v11 = *((_QWORD *)param0 + 12);
  if ( param0[20] )
  {
    v12 = (__m128 *)v90;
    v13 = param0[20];
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
        v21 = _mm_shuffle_ps(v17, v17, 255);
        v22 = _mm_add_ps(v17, v17);
        v23 = _mm_shuffle_ps(v17, v17, 201);
        v24 = _mm_shuffle_ps(v17, v17, 210);
        v25 = _mm_shuffle_ps(v22, v22, 201);
        v26 = _mm_sub_ps(v9, _mm_mul_ps(v25, v23));
        v27 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v25, v21), (__m128)0i64), _mm_mul_ps(v24, v22));
        v28 = _mm_shuffle_ps(v22, v22, 210);
        v29 = _mm_sub_ps(_mm_add_ps(_mm_mul_ps(v23, v22), (__m128)0i64), _mm_mul_ps(v28, v21));
        v30 = _mm_sub_ps(v26, _mm_mul_ps(v28, v24));
        v31 = _mm_shuffle_ps(_mm_shuffle_ps(v27, v29, 80), v29, 233);
        v32 = _mm_shuffle_ps(_mm_shuffle_ps(v29, v30, 80), v30, 233);
        v33 = _mm_shuffle_ps(_mm_shuffle_ps(v30, v27, 80), v27, 233);
        v34 = _mm_shuffle_ps(v31, _mm_shuffle_ps(v30, v31, 250), 148);
        v35 = _mm_shuffle_ps(v32, _mm_shuffle_ps(v27, v32, 250), 148);
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
  v42 = gVmx127_2;
  v43 = (__m128)gVmxi127_2;
  v44 = (__m128)gVmxUnpackMask_2;
  if ( *((_DWORD *)param0 + 32) )
  {
    v45 = *((unsigned int *)param0 + 32);
    v46 = _mm_shuffle_ps(*(__m128 *)(param0 + 28), *(__m128 *)(param0 + 28), 0);
    v47 = v4 + 20;
    v48 = (unsigned __int8 *)(v6 + 24);
    v87 = _mm_and_ps(gVmxMinusOne_2, v9);
    v88 = v46;
    do
    {
      v49 = *(__m128 *)(v48 - 8);
      v50 = (unsigned __int64)*v48 << 6;
      v51 = *(__m128 *)((char *)v89 + v50);
      v52 = *(__m128 *)((char *)&v89[1] + v50);
      v53 = *(__m128 *)(v5 + 4i64 * v48[1]);
      v54 = (__m128i)_mm_and_ps(
                       _mm_shuffle_ps(*(__m128 *)(v48 + 8), _mm_shuffle_ps(*(__m128 *)(v48 + 8), v43, 0), 144),
                       v44);
      v55 = *(__m128 *)((char *)v90 + v50);
      v56 = (__m128i)_mm_and_ps(
                       _mm_shuffle_ps(
                         *(__m128 *)(v48 + 8),
                         _mm_shuffle_ps(*(__m128 *)(v48 + 8), (__m128)gVmxi127_2, 85),
                         149),
                       v44);
      v57 = _mm_add_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_cvtepi32_ps((__m128i)_mm_and_ps(
                                                 (__m128)_mm_sub_epi32(
                                                           (__m128i)_mm_shuffle_ps(*(__m128 *)v48, *(__m128 *)v48, 85),
                                                           gVmxUnpackBias_2),
                                                 v44)),
                      gVmxUnpackUnbias_2),
                    gVmxUnpackShift_2),
                  (__m128)0i64),
                gVmxOneOver255_2),
              (__m128)0i64);
      v58 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v57, v57, 85), _mm_shuffle_ps(v53, v53, 0)), (__m128)0i64),
                _mm_mul_ps(
                  _mm_shuffle_ps(v57, v57, 170),
                  _mm_shuffle_ps(*(__m128 *)(v5 + 4i64 * v48[2]), *(__m128 *)(v5 + 4i64 * v48[2]), 0))),
              v46);
      v59 = _mm_min_ps(v58, v9);
      v60 = _mm_add_ps(
              _mm_mul_ps(
                _mm_sub_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_cvtepi32_ps((__m128i)_mm_and_ps(
                                                   (__m128)_mm_sub_epi32(
                                                             (__m128i)_mm_shuffle_ps(v49, v49, 85),
                                                             gVmxUnpackBias_2),
                                                   (__m128)gVmxUnpackMask_2)),
                        gVmxUnpackUnbias_2),
                      gVmxUnpackShift_2),
                    (__m128)0i64),
                  v42),
                gVmxOneOver127_2),
              (__m128)0i64);
      v61 = _mm_shuffle_ps(v60, v60, 255);
      v62 = _mm_shuffle_ps(v60, _mm_shuffle_ps(v60, (__m128)0i64, 250), 148);
      v63 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_sub_ps(
                        _mm_add_ps(_mm_mul_ps(_mm_cvtepi32_ps(v54), gVmxUnpackShift_2), (__m128)0i64),
                        gVmx127_2),
                      gVmxOneOver511_2),
                    (__m128)0i64),
                  v59),
                (__m128)0i64),
              _mm_shuffle_ps(*(__m128 *)(v48 - 24), _mm_shuffle_ps(*(__m128 *)(v48 - 24), gVmxOne_4, 250), 148));
      v64 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_sub_ps(
                        _mm_add_ps(_mm_mul_ps(_mm_cvtepi32_ps(v56), gVmxUnpackShift_2), (__m128)0i64),
                        gVmx127_2),
                      gVmxOneOver127_2),
                    (__m128)0i64),
                  v59),
                (__m128)0i64),
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_sub_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_add_ps(
                          _mm_cvtepi32_ps((__m128i)_mm_and_ps(
                                                     (__m128)_mm_sub_epi32(
                                                               (__m128i)_mm_shuffle_ps(v49, v49, 0),
                                                               gVmxUnpackBias_2),
                                                     (__m128)gVmxUnpackMask_2)),
                          gVmxUnpackUnbias_2),
                        gVmxUnpackShift_2),
                      (__m128)0i64),
                    gVmx127_2),
                  gVmxOneOver127_2),
                (__m128)0i64));
      v65 = _mm_shuffle_ps(v64, v64, 0);
      v66 = _mm_shuffle_ps(v64, v64, 85);
      v67 = _mm_shuffle_ps(v64, v64, 170);
      v68 = _mm_add_ps(
              _mm_mul_ps(
                _mm_rsqrt_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_add_ps(_mm_mul_ps(v65, v65), (__m128)0i64), _mm_mul_ps(v66, v66)),
                    _mm_mul_ps(v67, v67))),
                v64),
              (__m128)0i64);
      v69 = _mm_shuffle_ps(v68, v68, 0);
      v70 = _mm_shuffle_ps(v68, v68, 85);
      v71 = _mm_shuffle_ps(v68, v68, 170);
      v72 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v62, v62, 0), v69), (__m128)0i64),
                _mm_mul_ps(_mm_shuffle_ps(v62, v62, 85), v70)),
              _mm_mul_ps(_mm_shuffle_ps(v62, v62, 170), v71));
      v73 = _mm_sub_ps(
              v62,
              _mm_sub_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v68, v68, 210), _mm_shuffle_ps(v72, v72, 201)), (__m128)0i64),
                _mm_mul_ps(_mm_shuffle_ps(v68, v68, 201), _mm_shuffle_ps(v72, v72, 210))));
      v74 = _mm_shuffle_ps(v73, v73, 0);
      v75 = _mm_shuffle_ps(v73, v73, 85);
      v76 = _mm_shuffle_ps(v73, v73, 170);
      v77 = _mm_add_ps(
              _mm_mul_ps(
                _mm_rsqrt_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_add_ps(_mm_mul_ps(v74, v74), (__m128)0i64), _mm_mul_ps(v75, v75)),
                    _mm_mul_ps(v76, v76))),
                v73),
              (__m128)0i64);
      v46 = v88;
      v47 += 28i64;
      v48 += 44;
      v78 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v69, v51), (__m128)0i64), _mm_mul_ps(v70, v52));
      v79 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v63, v63, 0), v51), (__m128)0i64),
                  _mm_mul_ps(_mm_shuffle_ps(v63, v63, 85), v52)),
                _mm_mul_ps(_mm_shuffle_ps(v63, v63, 170), v55)),
              _mm_mul_ps(_mm_shuffle_ps(v63, v63, 255), *(__m128 *)((char *)&v90[1] + v50)));
      v42 = gVmx127_2;
      v80 = _mm_shuffle_ps(v79, v58, 250);
      v44 = (__m128)gVmxUnpackMask_2;
      v81 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v77, v77, 0), v51), (__m128)0i64),
                  _mm_mul_ps(_mm_shuffle_ps(v77, v77, 85), v52)),
                _mm_mul_ps(_mm_shuffle_ps(v77, v77, 170), v55)),
              _mm_mul_ps(_mm_shuffle_ps(v77, v77, 255), (__m128)0i64));
      v43 = (__m128)gVmxi127_2;
      *(__m128 *)(v47 - 48) = _mm_shuffle_ps(v79, v80, 148);
      v82 = _mm_cvtps_epi32(
              _mm_cvtepi32_ps(
                _mm_cvtps_epi32(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_add_ps(v78, _mm_mul_ps(v71, v55)),
                        _mm_mul_ps(_mm_shuffle_ps(v68, v68, 255), (__m128)0i64)),
                      gVmx127_2),
                    gVmx127_2))));
      v83 = _mm_packs_epi32(v82, v82);
      v84 = _mm_andnot_ps(gVmxOne_4, _mm_cmplt_ps(v61, (__m128)0i64));
      v9 = gVmxOne_4;
      *(_DWORD *)(v47 - 32) = _mm_packus_epi16(v83, v83).m128i_u32[0];
      v85 = _mm_cvtps_epi32(
              _mm_cvtepi32_ps(
                _mm_cvtps_epi32(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v81, _mm_shuffle_ps(v81, _mm_or_ps(v84, v87), 250), 148), gVmx127_2),
                    gVmx127_2))));
      v86 = _mm_packs_epi32(v85, v85);
      *(_DWORD *)(v47 - 28) = _mm_packus_epi16(v86, v86).m128i_u32[0];
      *(_DWORD *)(v47 - 24) = *((_DWORD *)v48 - 7);
      --v45;
    }
    while ( v45 );
  }
}

