// File Line: 33
// RVA: 0xB251F0
hkBool *__fastcall hkaTwoJointsIkSolver::solve(hkBool *result, hkaTwoJointsIkSolver::Setup *setup, hkaPose *poseInOut)
{
  hkBool *v3; // rbx
  hkaPose *v4; // rsi
  __m128 *v5; // r13
  _QWORD *v6; // rax
  unsigned __int64 v7; // r8
  _QWORD *v8; // r9
  unsigned __int64 v9; // rax
  hkBool *v10; // rax
  __m128 v11; // xmm10
  __int16 v12; // ax
  __m128 v13; // xmm12
  __m128 v14; // xmm11
  __m128 v15; // xmm9
  hkQsTransformf *v16; // rdi
  __int64 v17; // rdx
  hkQsTransformf *v18; // r14
  __m128i v19; // xmm0
  __m128 v20; // xmm0
  __m128 v21; // xmm5
  __m128 v22; // xmm1
  __m128 v23; // xmm1
  __m128 v24; // xmm2
  __m128 v25; // xmm1
  __m128 v26; // xmm0
  __m128 v27; // xmm12
  __m128 v28; // xmm2
  __m128 v29; // xmm10
  __m128 v30; // xmm1
  __m128 v31; // xmm6
  __m128 v32; // xmm10
  __int16 v33; // ax
  hkQsTransformf *v34; // rdi
  __int64 v35; // rdx
  hkQsTransformf *v36; // r14
  __m128i v37; // xmm0
  __m128 v38; // xmm2
  __m128 v39; // xmm6
  __m128 v40; // xmm4
  __m128 v41; // xmm1
  __m128 v42; // xmm2
  __m128 v43; // xmm1
  __m128 v44; // xmm11
  __m128 v45; // xmm2
  __m128 v46; // xmm3
  __m128 v47; // xmm7
  __m128 v48; // xmm9
  __m128 v49; // xmm9
  _QWORD *v50; // r8
  unsigned __int64 v51; // rcx
  unsigned __int64 v52; // rax
  __int64 v53; // rdx
  hkQsTransformf *v54; // rdi
  __int64 v55; // r8
  hkQsTransformf *v56; // rbx
  __int64 v57; // r8
  hkQsTransformf *v58; // rax
  __m128 v59; // xmm8
  __m128 v60; // xmm7
  __m128 v61; // xmm3
  __m128 v62; // xmm4
  __m128 v63; // xmm1
  __m128 v64; // xmm5
  __m128 v65; // xmm0
  __m128 v66; // xmm6
  __m128 v67; // xmm10
  __m128 v68; // xmm4
  __m128 v69; // xmm1
  __m128 v70; // xmm5
  __m128 v71; // xmm2
  __m128 v72; // xmm1
  __m128 v73; // xmm6
  __m128 v74; // xmm3
  __m128 v75; // xmm1
  __m128 v76; // xmm4
  __m128 v77; // xmm6
  __m128 v78; // xmm6
  __m128 v79; // xmm1
  __m128 v80; // xmm5
  __m128 v81; // xmm1
  __m128 v82; // xmm5
  __int64 v83; // rdx
  __m128 v84; // xmm10
  __m128 v85; // xmm7
  __m128 v86; // xmm12
  hkQsTransformf *v87; // rax
  __m128 v88; // xmm5
  __m128 v89; // xmm0
  __m128 v90; // xmm1
  __m128 v91; // xmm2
  __m128 v92; // xmm0
  __m128 v93; // xmm3
  __m128 v94; // xmm4
  __m128 v95; // xmm1
  __m128 v96; // xmm2
  __m128 v97; // xmm1
  __m128 v98; // xmm6
  __m128 v99; // xmm6
  __m128 v100; // xmm1
  __m128 v101; // xmm3
  __m128 v102; // xmm1
  __m128 v103; // xmm3
  __m128 v104; // xmm2
  __m128 v105; // xmm3
  __m128 v106; // xmm3
  __m128 v107; // xmm7
  __m128 v108; // ST70_16
  __m128 v109; // xmm8
  __m128 v110; // xmm7
  __m128 v111; // xmm6
  __m128 v112; // xmm1
  __m128 v113; // xmm8
  __m128 v114; // xmm3
  __m128 v115; // xmm0
  __m128 v116; // xmm1
  __m128 v117; // xmm2
  __m128 v118; // xmm1
  __m128 v119; // xmm8
  __m128 v120; // xmm7
  __m128 v121; // xmm6
  __m128 v122; // xmm2
  __m128 v123; // xmm5
  __m128 v124; // xmm4
  __m128 v125; // xmm3
  __m128 v126; // xmm2
  unsigned int v127; // ST5C_4
  __m128 v128; // xmm3
  __m128 v129; // xmm1
  __m128 v130; // xmm5
  __m128 v131; // xmm3
  __m128 v132; // xmm1
  __m128 v133; // xmm4
  __m128 v134; // xmm6
  __m128 v135; // xmm5
  __m128 v136; // xmm4
  __m128 v137; // xmm8
  __m128 v138; // xmm14
  __m128 v139; // xmm3
  __m128 v140; // xmm2
  __m128 v141; // xmm1
  unsigned int v142; // ST60_4
  hkQsTransformf *v143; // rax
  __m128 v144; // xmm8
  __m128 *v145; // rbx
  __m128 v146; // xmm0
  __m128 v147; // xmm1
  __m128 v148; // xmm2
  __m128 v149; // xmm1
  __m128 v150; // xmm8
  __m128 v151; // xmm3
  __m128 v152; // xmm7
  __m128 v153; // xmm1
  __m128 v154; // xmm6
  __m128 v155; // xmm2
  __m128 v156; // xmm1
  __m128 v157; // xmm4
  __m128 v158; // xmm3
  __m128 v159; // xmm2
  __m128 v160; // xmm6
  __m128 v161; // xmm6
  __m128 v162; // xmm6
  __m128 v163; // xmm6
  __m128 v164; // xmm0
  __m128 v165; // xmm2
  __m128 v166; // xmm1
  _QWORD *v167; // r8
  unsigned __int64 v168; // rcx
  unsigned __int64 v169; // rax
  __int64 v170; // rdx
  hkQsTransformf *v171; // rbx
  __int64 v172; // rax
  __m128 v173; // xmm11
  hkVector4f v174; // xmm7
  __int64 v175; // rdx
  hkQsTransformf *v176; // rax
  __m128 v177; // xmm3
  __m128 v178; // xmm4
  __m128 v179; // xmm1
  __m128 v180; // xmm5
  __m128 v181; // xmm0
  __m128 v182; // xmm6
  __m128 v183; // xmm7
  signed int v184; // ecx
  signed int v185; // eax
  __m128 v186; // xmm1
  __m128 v187; // xmm3
  __m128 v188; // xmm1
  __m128 v189; // xmm7
  __m128 v190; // xmm6
  __m128 v191; // xmm1
  __m128 v192; // xmm3
  __m128 v193; // xmm1
  __m128 v194; // xmm8
  __m128 v195; // xmm6
  __m128 v196; // xmm1
  __m128 v197; // xmm3
  float v198; // xmm1_4
  __m128 v199; // xmm4
  __m128 v200; // xmm1
  __m128 v201; // xmm5
  __m128 v202; // xmm1
  __m128 v203; // xmm2
  __m128 v204; // xmm5
  __m128 v205; // xmm5
  __m128 v206; // xmm0
  __m128 v207; // xmm1
  __m128 v208; // xmm3
  __m128 v209; // xmm1
  hkQsTransformf *v210; // rax
  __m128 v211; // xmm3
  __m128 v212; // xmm5
  __m128 v213; // xmm6
  __m128 v214; // xmm4
  __m128 v215; // xmm6
  __m128 v216; // xmm6
  __m128 v217; // xmm6
  __m128 v218; // xmm0
  __m128 v219; // xmm2
  __m128 v220; // xmm1
  __m128 v221; // xmm1
  __m128 v222; // xmm2
  __m128 v223; // xmm3
  __m128 v224; // xmm3
  __m128 v225; // xmm2
  __m128 v226; // xmm3
  __m128 v227; // xmm0
  __int64 v228; // rdx
  hkQsTransformf *v229; // rax
  signed __int64 v230; // r8
  __int64 v231; // rdx
  int v232; // eax
  __int64 v233; // r9
  __int64 v234; // r15
  signed __int64 v235; // r14
  __int64 v236; // rdx
  unsigned int *v237; // r8
  hkQsTransformf *v238; // rcx
  hkQsTransformf *v239; // r12
  hkQsTransformf *v240; // rdi
  __m128i v241; // xmm0
  __m128 v242; // xmm7
  __m128 v243; // xmm6
  __m128 v244; // xmm0
  __m128 v245; // xmm4
  __m128 v246; // xmm1
  __m128 v247; // xmm3
  __m128 v248; // xmm1
  __m128 v249; // xmm2
  __m128 v250; // xmm1
  __m128 v251; // xmm5
  __m128 v252; // xmm2
  __m128 v253; // xmm5
  __m128 v254; // xmm6
  __m128 v255; // xmm4
  __m128 v256; // xmm3
  __m128 v257; // xmm3
  hkQsTransformf *v258; // rax
  __int64 i; // rcx
  unsigned int *v260; // rdx
  unsigned int v261; // eax
  hkQsTransformf *v262; // rax
  signed __int64 v263; // rcx
  __int64 v264; // rdx
  hkQsTransformf *v265; // rax
  __m128 v266; // xmm3
  __m128 v267; // xmm1
  __m128 v268; // xmm4
  __m128 v269; // xmm5
  __m128 v270; // xmm1
  __m128 v271; // xmm1
  __m128 v272; // xmm4
  __m128 v273; // xmm5
  __m128 v274; // xmm2
  __m128 v275; // xmm3
  __m128 v276; // xmm5
  __m128 v277; // xmm0
  __m128 v278; // xmm10
  __m128 v279; // xmm5
  __int64 v280; // rdx
  signed __int64 v281; // r8
  int v282; // eax
  __int64 v283; // r15
  __int64 v284; // r9
  signed __int64 v285; // r14
  __int64 v286; // rdx
  unsigned int *v287; // r8
  hkQsTransformf *v288; // rcx
  hkQsTransformf *v289; // r12
  hkQsTransformf *v290; // rdi
  __m128i v291; // xmm0
  __m128 v292; // xmm7
  __m128 v293; // xmm6
  __m128 v294; // xmm2
  __m128 v295; // xmm4
  __m128 v296; // xmm3
  __m128 v297; // xmm1
  __m128 v298; // xmm0
  __m128 v299; // xmm5
  __m128 v300; // xmm2
  __m128 v301; // xmm5
  __m128 v302; // xmm6
  __m128 v303; // xmm3
  __m128 v304; // xmm4
  __m128 v305; // xmm3
  hkQsTransformf *v306; // rax
  __int64 j; // rcx
  unsigned int *v308; // rdx
  unsigned int v309; // eax
  hkQsTransformf *v310; // rax
  signed __int64 v311; // rcx
  __int64 v312; // rdx
  hkQsTransformf *v313; // rax
  __m128 v314; // xmm3
  __m128 v315; // xmm1
  __m128 v316; // xmm4
  __m128 v317; // xmm5
  __m128 v318; // xmm0
  __m128 v319; // xmm0
  __m128 v320; // xmm4
  __m128 v321; // xmm5
  __m128 v322; // xmm2
  __m128 v323; // xmm3
  __m128 v324; // xmm5
  __m128 v325; // xmm0
  __m128 v326; // xmm9
  __m128 v327; // xmm5
  __int64 v328; // rdx
  signed __int64 v329; // r9
  int v330; // eax
  __int64 v331; // r15
  __int64 v332; // r8
  signed __int64 v333; // r14
  __int64 v334; // rdx
  unsigned int *v335; // rcx
  hkQsTransformf *v336; // r12
  hkQsTransformf *v337; // r13
  hkQsTransformf *v338; // rdi
  __m128i v339; // xmm0
  __m128 v340; // xmm7
  __m128 v341; // xmm6
  __m128 v342; // xmm0
  __m128 v343; // xmm4
  __m128 v344; // xmm1
  __m128 v345; // xmm3
  __m128 v346; // xmm1
  __m128 v347; // xmm2
  __m128 v348; // xmm1
  __m128 v349; // xmm5
  __m128 v350; // xmm2
  __m128 v351; // xmm5
  __m128 v352; // xmm6
  __m128 v353; // xmm4
  __m128 v354; // xmm3
  __m128 v355; // xmm3
  hkQsTransformf *v356; // rax
  __int64 k; // rcx
  unsigned int *v358; // rdx
  unsigned int v359; // eax
  hkQsTransformf *v360; // rax
  signed __int64 v361; // rcx
  _QWORD *v362; // rax
  unsigned __int64 v363; // rcx
  _QWORD *v364; // r8
  unsigned __int64 v365; // rax
  int v366; // [rsp+20h] [rbp-E0h]
  int v367; // [rsp+20h] [rbp-E0h]
  signed __int64 v368; // [rsp+30h] [rbp-D0h]
  hkQsTransformf *v369; // [rsp+30h] [rbp-D0h]
  __int64 v370; // [rsp+30h] [rbp-D0h]
  __int64 v371; // [rsp+40h] [rbp-C0h]
  __int64 v372; // [rsp+40h] [rbp-C0h]
  signed __int64 v373; // [rsp+40h] [rbp-C0h]
  hkQsTransformf *v374; // [rsp+70h] [rbp-90h]
  signed __int64 v375; // [rsp+70h] [rbp-90h]
  __m128 v376; // [rsp+80h] [rbp-80h]
  __m128 v377; // [rsp+90h] [rbp-70h]
  __m128 v378; // [rsp+A0h] [rbp-60h]
  hkQuaternionf v379; // [rsp+B0h] [rbp-50h]
  __m128 v380; // [rsp+C0h] [rbp-40h]
  __m128 v381; // [rsp+D0h] [rbp-30h]
  __m128 v382; // [rsp+E0h] [rbp-20h]
  __m128 v383; // [rsp+F0h] [rbp-10h]
  hkVector4f v384; // [rsp+100h] [rbp+0h]
  __m128 v385; // [rsp+110h] [rbp+10h]
  __m128 v386; // [rsp+120h] [rbp+20h]
  hkVector4f v387; // [rsp+130h] [rbp+30h]
  hkQuaternionf v388; // [rsp+140h] [rbp+40h]
  hkVector4f v389; // [rsp+150h] [rbp+50h]
  hkVector4f v390; // [rsp+160h] [rbp+60h]
  __m128 v391; // [rsp+170h] [rbp+70h]
  __m128 v392; // [rsp+180h] [rbp+80h]
  hkVector4f v393; // [rsp+190h] [rbp+90h]
  __m128 v394; // [rsp+1A0h] [rbp+A0h]
  __m128 v395; // [rsp+1B0h] [rbp+B0h]
  hkVector4f axis; // [rsp+1C0h] [rbp+C0h]
  __m128 v397; // [rsp+1D0h] [rbp+D0h]
  __m128 v398; // [rsp+1E0h] [rbp+E0h]
  __m128 v399; // [rsp+1F0h] [rbp+F0h]
  hkSimdFloat32 angle; // [rsp+200h] [rbp+100h]
  hkQuaternionf q1; // [rsp+210h] [rbp+110h]
  __m128 v402; // [rsp+220h] [rbp+120h]
  __m128 v403; // [rsp+230h] [rbp+130h]
  __m128 v404; // [rsp+240h] [rbp+140h]
  __m128 v405; // [rsp+250h] [rbp+150h]
  __m128 v406; // [rsp+260h] [rbp+160h]
  hkSimdFloat32 t; // [rsp+270h] [rbp+170h]
  hkQuaternionf v408; // [rsp+280h] [rbp+180h]
  hkVector4f from; // [rsp+290h] [rbp+190h]
  __m128 v410; // [rsp+2A0h] [rbp+1A0h]
  __m128 v411; // [rsp+2B0h] [rbp+1B0h]
  __m128 v412; // [rsp+2C0h] [rbp+1C0h]
  hkVector4f v413; // [rsp+2D0h] [rbp+1D0h]
  __m128 v414; // [rsp+2E0h] [rbp+1E0h]
  __m128 v415; // [rsp+2F0h] [rbp+1F0h]
  hkVector4f v416; // [rsp+300h] [rbp+200h]
  __m128 v417; // [rsp+310h] [rbp+210h]
  __m128 v418; // [rsp+320h] [rbp+220h]
  __m128 v419; // [rsp+330h] [rbp+230h]
  __m128 v420; // [rsp+340h] [rbp+240h]
  __m128 v421; // [rsp+350h] [rbp+250h]
  __m128 v422; // [rsp+360h] [rbp+260h]
  __m128 v423; // [rsp+370h] [rbp+270h]
  __m128 v424; // [rsp+380h] [rbp+280h]
  __m128 v425; // [rsp+390h] [rbp+290h]
  __m128 v426; // [rsp+3A0h] [rbp+2A0h]
  __m128 v427; // [rsp+3B0h] [rbp+2B0h]
  __m128 v428; // [rsp+3C0h] [rbp+2C0h]
  __m128 v429; // [rsp+3D0h] [rbp+2D0h]
  __m128 v430; // [rsp+3E0h] [rbp+2E0h]
  __m128 v431; // [rsp+3F0h] [rbp+2F0h]
  __m128 v432; // [rsp+400h] [rbp+300h]
  __m128 v433; // [rsp+410h] [rbp+310h]
  __m128 v434; // [rsp+420h] [rbp+320h]
  __m128 v435; // [rsp+430h] [rbp+330h]
  __m128 v436; // [rsp+440h] [rbp+340h]
  __m128 v437; // [rsp+450h] [rbp+350h]
  hkBool *v438; // [rsp+540h] [rbp+440h]
  hkaTwoJointsIkSolver::Setup *v439; // [rsp+548h] [rbp+448h]
  int v440; // [rsp+548h] [rbp+448h]

  v439 = setup;
  v438 = result;
  v3 = result;
  v4 = poseInOut;
  v5 = (__m128 *)setup;
  v6 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = v6[1];
  v8 = v6;
  if ( v7 < v6[3] )
  {
    *(_QWORD *)v7 = "LtTWOJOINTSOLVER";
    *(_QWORD *)(v7 + 16) = "StINIT";
    v9 = __rdtsc();
    *(_DWORD *)(v7 + 8) = v9;
    v8[1] = v7 + 24;
  }
  if ( v5[8].m128_i8[0] || v5[8].m128_i8[1] )
  {
    v382 = query.m_quad;
    v378 = query.m_quad;
    v11 = qi.m_vec.m_quad;
    v381 = qi.m_vec.m_quad;
    v380 = 0i64;
    v376 = 0i64;
    v377 = qi.m_vec.m_quad;
    v12 = HIWORD(v5->m128_u64[0]);
    v13 = 0i64;
    v14 = 0i64;
    v15 = qi.m_vec.m_quad;
    if ( v12 >= 0 )
    {
      if ( v4->m_boneFlags.m_data[v12] & 2 )
        v16 = hkaPose::calculateBoneModelSpace(v4, v12);
      else
        v16 = &v4->m_modelPose.m_data[v12];
      v17 = SLOWORD(v5->m128_u64[0]);
      if ( v4->m_boneFlags.m_data[v17] & 2 )
        v18 = hkaPose::calculateBoneModelSpace(v4, v17);
      else
        v18 = &v4->m_modelPose.m_data[v17];
      hkVector4f::setRotatedInverseDir(&v416, &v18->m_rotation, &v18->m_translation);
      v19 = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
      v416.m_quad = _mm_xor_ps((__m128)_mm_shuffle_epi32(v19, 0), v416.m_quad);
      v417 = _mm_xor_ps((__m128)_mm_shuffle_epi32(v19, 64), v18->m_rotation.m_vec.m_quad);
      v20 = v18->m_scale.m_quad;
      v21 = _mm_shuffle_ps(v417, v417, 255);
      v22 = _mm_rcp_ps(v20);
      v418 = (__m128)_mm_srli_si128(
                       _mm_slli_si128((__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v20, v22)), v22), 4),
                       4);
      v23 = _mm_mul_ps(v16->m_translation.m_quad, v417);
      v24 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v23, v23, 85), _mm_shuffle_ps(v23, v23, 0)),
              _mm_shuffle_ps(v23, v23, 170));
      v25 = _mm_shuffle_ps(v417, v417, 201);
      v26 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v16->m_translation.m_quad, v16->m_translation.m_quad, 201), v417),
              _mm_mul_ps(v16->m_translation.m_quad, v25));
      v27 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(v16->m_translation.m_quad, _mm_sub_ps(_mm_mul_ps(v21, v21), (__m128)xmmword_141A711B0)),
                _mm_mul_ps(v24, v417)),
              _mm_mul_ps(_mm_shuffle_ps(v26, v26, 201), v21));
      v13 = _mm_add_ps(_mm_add_ps(v27, v27), v416.m_quad);
      v380 = v13;
      v28 = v16->m_rotation.m_vec.m_quad;
      v29 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v16->m_rotation.m_vec.m_quad, v28, 201), v417), _mm_mul_ps(v25, v28));
      v30 = _mm_shuffle_ps(v16->m_rotation.m_vec.m_quad, v16->m_rotation.m_vec.m_quad, 255);
      v31 = _mm_mul_ps(v417, v28);
      v32 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v29, v29, 201), _mm_mul_ps(v21, v28)), _mm_mul_ps(v30, v417));
      v11 = _mm_shuffle_ps(
              v32,
              _mm_unpackhi_ps(
                v32,
                _mm_sub_ps(
                  _mm_mul_ps(v30, v21),
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v31, v31, 85), _mm_shuffle_ps(v31, v31, 0)),
                    _mm_shuffle_ps(v31, v31, 170)))),
              196);
      v381 = v11;
      v382 = _mm_mul_ps(v16->m_scale.m_quad, v418);
    }
    v33 = v5->m128_u64[1];
    if ( v33 >= 0 )
    {
      if ( v4->m_boneFlags.m_data[v33] & 2 )
        v34 = hkaPose::calculateBoneModelSpace(v4, v33);
      else
        v34 = &v4->m_modelPose.m_data[v33];
      v35 = SWORD1(v5->m128_u64[0]);
      if ( v4->m_boneFlags.m_data[v35] & 2 )
        v36 = hkaPose::calculateBoneModelSpace(v4, v35);
      else
        v36 = &v4->m_modelPose.m_data[v35];
      hkVector4f::setRotatedInverseDir(&v413, &v36->m_rotation, &v36->m_translation);
      v37 = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
      v413.m_quad = _mm_xor_ps((__m128)_mm_shuffle_epi32(v37, 0), v413.m_quad);
      v414 = _mm_xor_ps((__m128)_mm_shuffle_epi32(v37, 64), v36->m_rotation.m_vec.m_quad);
      v38 = _mm_rcp_ps(v36->m_scale.m_quad);
      v39 = _mm_shuffle_ps(v414, v414, 255);
      v40 = _mm_shuffle_ps(v414, v414, 201);
      v415 = (__m128)_mm_srli_si128(
                       _mm_slli_si128(
                         (__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v38, v36->m_scale.m_quad)), v38),
                         4),
                       4);
      v41 = _mm_mul_ps(v34->m_translation.m_quad, v414);
      v42 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v41, v41, 85), _mm_shuffle_ps(v41, v41, 0)),
              _mm_shuffle_ps(v41, v41, 170));
      v43 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v34->m_translation.m_quad, v34->m_translation.m_quad, 201), v414),
              _mm_mul_ps(v40, v34->m_translation.m_quad));
      v44 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v39, v39), (__m128)xmmword_141A711B0), v34->m_translation.m_quad),
                _mm_mul_ps(v42, v414)),
              _mm_mul_ps(_mm_shuffle_ps(v43, v43, 201), v39));
      v14 = _mm_add_ps(_mm_add_ps(v44, v44), v413.m_quad);
      v376 = v14;
      v45 = v34->m_rotation.m_vec.m_quad;
      v46 = _mm_shuffle_ps(v34->m_rotation.m_vec.m_quad, v34->m_rotation.m_vec.m_quad, 255);
      v47 = _mm_mul_ps(v414, v45);
      v48 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v34->m_rotation.m_vec.m_quad, v45, 201), v414), _mm_mul_ps(v40, v45));
      v49 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v48, v48, 201), _mm_mul_ps(v39, v45)), _mm_mul_ps(v46, v414));
      v15 = _mm_shuffle_ps(
              v49,
              _mm_unpackhi_ps(
                v49,
                _mm_sub_ps(
                  _mm_mul_ps(v46, v39),
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v47, v47, 85), _mm_shuffle_ps(v47, v47, 0)),
                    _mm_shuffle_ps(v47, v47, 170)))),
              196);
      v377 = v15;
      v378 = _mm_mul_ps(v34->m_scale.m_quad, v415);
    }
    if ( v5[8].m128_i8[0] )
    {
      v50 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v51 = v50[1];
      if ( v51 < v50[3] )
      {
        *(_QWORD *)v51 = "StFIXLENGTH";
        v52 = __rdtsc();
        *(_DWORD *)(v51 + 8) = v52;
        v50[1] = v51 + 16;
      }
      v53 = SLOWORD(v5->m128_u64[0]);
      if ( v4->m_boneFlags.m_data[v53] & 2 )
        v54 = hkaPose::calculateBoneModelSpace(v4, v53);
      else
        v54 = &v4->m_modelPose.m_data[v53];
      v55 = SWORD1(v5->m128_u64[0]);
      if ( v4->m_boneFlags.m_data[v55] & 2 )
        v56 = hkaPose::calculateBoneModelSpace(v4, v55);
      else
        v56 = &v4->m_modelPose.m_data[v55];
      v57 = SWORD2(v5->m128_u64[0]);
      if ( v4->m_boneFlags.m_data[v57] & 2 )
        v58 = hkaPose::calculateBoneModelSpace(v4, v57);
      else
        v58 = &v4->m_modelPose.m_data[v57];
      v59 = (__m128)xmmword_141A711B0;
      if ( v5[8].m128_i8[1] )
      {
        v68 = v5[7];
        v69 = _mm_mul_ps(v5[6], v68);
        v70 = _mm_shuffle_ps(v68, v68, 255);
        v71 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v69, v69, 85), _mm_shuffle_ps(v69, v69, 0)),
                _mm_shuffle_ps(v69, v69, 170));
        v72 = v5[6];
        v73 = _mm_add_ps(
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v70, v70), (__m128)xmmword_141A711B0), v72),
                _mm_mul_ps(v5[7], v71));
        v74 = v5[5];
        v75 = _mm_sub_ps(
                _mm_mul_ps(v72, _mm_shuffle_ps(v5[7], v68, 201)),
                _mm_mul_ps(v68, _mm_shuffle_ps(v72, v72, 201)));
        v76 = _mm_shuffle_ps(v74, v74, 255);
        v77 = _mm_add_ps(v73, _mm_mul_ps(_mm_shuffle_ps(v75, v75, 201), v70));
        v78 = _mm_add_ps(v77, v77);
        v79 = _mm_mul_ps(v5[5], v78);
        v80 = _mm_add_ps(
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v76, v76), (__m128)xmmword_141A711B0), v78),
                _mm_mul_ps(
                  v5[5],
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v79, v79, 85), _mm_shuffle_ps(v79, v79, 0)),
                    _mm_shuffle_ps(v79, v79, 170))));
        v81 = _mm_sub_ps(
                _mm_mul_ps(v5[5], _mm_shuffle_ps(v78, v78, 201)),
                _mm_mul_ps(_mm_shuffle_ps(v74, v74, 201), v78));
        v82 = _mm_add_ps(v80, _mm_mul_ps(_mm_shuffle_ps(v81, v81, 201), v76));
        v60 = _mm_sub_ps(v5[4], _mm_add_ps(v82, v82));
        v383 = v60;
        v67 = v58->m_translation.m_quad;
      }
      else
      {
        v60 = v5[4];
        v383 = v5[4];
        v61 = v58->m_rotation.m_vec.m_quad;
        v62 = _mm_mul_ps(v5[6], v58->m_scale.m_quad);
        v63 = _mm_mul_ps(v61, v62);
        v64 = _mm_shuffle_ps(v58->m_rotation.m_vec.m_quad, v61, 255);
        v65 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v62, v62, 201), v61), _mm_mul_ps(_mm_shuffle_ps(v61, v61, 201), v62));
        v66 = _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v64, v64), (__m128)xmmword_141A711B0), v62),
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v63, v63, 85), _mm_shuffle_ps(v63, v63, 0)),
                      _mm_shuffle_ps(v63, v63, 170)),
                    v61)),
                _mm_mul_ps(_mm_shuffle_ps(v65, v65, 201), v64));
        v67 = _mm_add_ps(v58->m_translation.m_quad, _mm_add_ps(v66, v66));
      }
      v83 = SWORD1(v5->m128_u64[0]);
      v84 = _mm_sub_ps(v67, v56->m_translation.m_quad);
      v85 = _mm_sub_ps(v60, v54->m_translation.m_quad);
      v86 = _mm_sub_ps(v56->m_translation.m_quad, v54->m_translation.m_quad);
      if ( v4->m_boneFlags.m_data[v83] & 2 )
      {
        v87 = hkaPose::calculateBoneModelSpace(v4, v83);
        v59 = (__m128)xmmword_141A711B0;
      }
      else
      {
        v87 = &v4->m_modelPose.m_data[v83];
      }
      v88 = v87->m_rotation.m_vec.m_quad;
      v89 = _mm_mul_ps(v88, v88);
      v90 = _mm_add_ps(_mm_shuffle_ps(v89, v89, 78), v89);
      v91 = _mm_add_ps(_mm_shuffle_ps(v90, v90, 177), v90);
      v92 = _mm_rsqrt_ps(v91);
      v423 = v91;
      v420 = _mm_mul_ps(
               v88,
               _mm_mul_ps(
                 _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v92, v91), v92)),
                 _mm_mul_ps(*(__m128 *)_xmm, v92)));
      v93 = v5[1];
      v94 = _mm_shuffle_ps(v420, v420, 255);
      v95 = _mm_mul_ps(v93, v420);
      v96 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v95, v95, 85), _mm_shuffle_ps(v95, v95, 0)),
              _mm_shuffle_ps(v95, v95, 170));
      v97 = _mm_sub_ps(
              _mm_mul_ps(v420, _mm_shuffle_ps(v5[1], v93, 201)),
              _mm_mul_ps(v93, _mm_shuffle_ps(v420, v420, 201)));
      v98 = _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(v5[1], _mm_sub_ps(_mm_mul_ps(v94, v94), v59)), _mm_mul_ps(v96, v420)),
              _mm_mul_ps(_mm_shuffle_ps(v97, v97, 201), v94));
      v99 = _mm_add_ps(v98, v98);
      v100 = _mm_mul_ps(v99, v86);
      v101 = _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v100, v100, 85), _mm_shuffle_ps(v100, v100, 0)),
               _mm_shuffle_ps(v100, v100, 170));
      v102 = _mm_mul_ps(v99, v84);
      v103 = _mm_mul_ps(v101, v99);
      v402 = _mm_sub_ps(v86, v103);
      v104 = _mm_mul_ps(
               _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v102, v102, 85), _mm_shuffle_ps(v102, v102, 0)),
                 _mm_shuffle_ps(v102, v102, 170)),
               v99);
      v105 = _mm_sub_ps(v103, v104);
      v397 = _mm_sub_ps(v84, v104);
      v106 = _mm_mul_ps(v105, v105);
      v107 = _mm_mul_ps(v85, v85);
      v108 = _mm_mul_ps(v402, v402);
      v109 = _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v107, v107, 85), _mm_shuffle_ps(v107, v107, 0)),
               _mm_shuffle_ps(v107, v107, 170));
      v110 = _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v108, v108, 85), _mm_shuffle_ps(v108, v108, 0)),
               _mm_shuffle_ps(v108, v108, 170));
      v406 = _mm_mul_ps(v397, v397);
      v111 = _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v406, v406, 85), _mm_shuffle_ps(v406, v406, 0)),
               _mm_shuffle_ps(v406, v406, 170));
      v112 = _mm_rsqrt_ps(v110);
      v421 = v110;
      v113 = _mm_sub_ps(
               _mm_sub_ps(
                 _mm_sub_ps(
                   v109,
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v106, v106, 85), _mm_shuffle_ps(v106, v106, 0)),
                     _mm_shuffle_ps(v106, v106, 170))),
                 v110),
               v111);
      v114 = _mm_mul_ps(v112, *(__m128 *)_xmm);
      v419 = v111;
      v115 = _mm_mul_ps(_mm_mul_ps(v112, v110), v112);
      v116 = _mm_rsqrt_ps(v111);
      v117 = _mm_sub_ps(
               (__m128)0i64,
               _mm_mul_ps(
                 _mm_mul_ps(
                   (__m128)xmmword_141A710D0,
                   _mm_andnot_ps(
                     _mm_cmpleps(v110, (__m128)0i64),
                     _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, v115), v114), v110))),
                 _mm_andnot_ps(
                   _mm_cmpleps(v111, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_mul_ps(
                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v116, v111), v116)),
                       _mm_mul_ps(v116, *(__m128 *)_xmm)),
                     v111))));
      v118 = _mm_rcp_ps(v117);
      v425 = v117;
      v399 = (__m128)_xmm;
      v427 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v118, v117)), v118), v113);
      v119 = _mm_min_ps(
               _mm_max_ps(
                 (__m128)COERCE_UNSIGNED_INT(
                           fmax(
                             COERCE_FLOAT(_mm_shuffle_ps((__m128)v5[2].m128_u32[0], (__m128)v5[2].m128_u32[0], 0)),
                             fmin(
                               COERCE_FLOAT(_mm_shuffle_ps((__m128)v5[2].m128_u32[1], (__m128)v5[2].m128_u32[1], 0)),
                               v427.m128_f32[0]))),
                 *(__m128 *)_xmm_bf800000bf800000bf800000bf800000),
               *(__m128 *)_xmm);
      v120 = _mm_andnot_ps(*(__m128 *)_xmm, v119);
      v121 = _mm_cmpltps(v120, *(__m128 *)_xmm);
      v122 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)_xmm, v120), *(__m128 *)_xmm);
      v123 = _mm_cmpltps(*(__m128 *)_xmm, v120);
      v124 = _mm_or_ps(_mm_and_ps(_mm_sqrt_ps(v122), v123), _mm_andnot_ps(v123, v120));
      v125 = _mm_or_ps(_mm_andnot_ps(v123, _mm_mul_ps(v120, v120)), _mm_and_ps(v123, v122));
      v126 = _mm_add_ps(
               _mm_mul_ps(
                 _mm_mul_ps(
                   _mm_add_ps(
                     _mm_mul_ps(
                       _mm_add_ps(
                         _mm_mul_ps(
                           _mm_add_ps(
                             _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v125, *(__m128 *)coeff4), *(__m128 *)coeff3), v125),
                             *(__m128 *)coeff2),
                           v125),
                         *(__m128 *)coeff1),
                       v125),
                     *(__m128 *)coeff0),
                   v125),
                 v124),
               v124);
      *(float *)&v127 = 1.5707964
                      - COERCE_FLOAT((*(unsigned __int128 *)&_mm_andnot_ps(
                                                               v121,
                                                               _mm_or_ps(
                                                                 _mm_and_ps(
                                                                   _mm_sub_ps(*(__m128 *)_xmm, _mm_add_ps(v126, v126)),
                                                                   v123),
                                                                 _mm_andnot_ps(v123, v126))) | v121.m128_i32[0] & v120.m128_i32[0]) ^ v119.m128_i32[0] & _xmm[0]);
      v398 = _mm_shuffle_ps((__m128)v127, (__m128)v127, 0);
      v128 = _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v108, v108, 85), _mm_shuffle_ps(v108, v108, 0)),
               _mm_shuffle_ps(v108, v108, 170));
      v129 = _mm_rsqrt_ps(v128);
      v429 = v128;
      v130 = _mm_xor_ps(
               _mm_mul_ps(
                 _mm_andnot_ps(
                   _mm_cmpleps(v128, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v129, v128), v129)),
                     _mm_mul_ps(v129, *(__m128 *)_xmm))),
                 v402),
               (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64));
      v131 = _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v406, v406, 85), _mm_shuffle_ps(v406, v406, 0)),
               _mm_shuffle_ps(v406, v406, 170));
      v132 = _mm_rsqrt_ps(v131);
      v431 = v131;
      v133 = _mm_mul_ps(
               _mm_mul_ps(
                 _mm_andnot_ps(
                   _mm_cmpleps(v131, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v132, v131), v132)),
                     _mm_mul_ps(v132, *(__m128 *)_xmm))),
                 v397),
               v130);
      v134 = _mm_min_ps(
               _mm_max_ps(
                 (__m128)COERCE_UNSIGNED_INT(
                           (float)(COERCE_FLOAT(_mm_shuffle_ps(v133, v133, 85))
                                 + COERCE_FLOAT(_mm_shuffle_ps(v133, v133, 0)))
                         + COERCE_FLOAT(_mm_shuffle_ps(v133, v133, 170))),
                 *(__m128 *)_xmm_bf800000bf800000bf800000bf800000),
               *(__m128 *)_xmm);
      v135 = _mm_andnot_ps(*(__m128 *)_xmm, v134);
      v136 = _mm_cmpltps(v135, *(__m128 *)_xmm);
      v137 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)_xmm, v135), *(__m128 *)_xmm);
      v138 = _mm_cmpltps(*(__m128 *)_xmm, v135);
      v139 = _mm_or_ps(_mm_and_ps(_mm_sqrt_ps(v137), v138), _mm_andnot_ps(v138, v135));
      v140 = _mm_or_ps(_mm_andnot_ps(v138, _mm_mul_ps(v135, v135)), _mm_and_ps(v138, v137));
      v141 = _mm_add_ps(
               _mm_mul_ps(
                 _mm_mul_ps(
                   _mm_add_ps(
                     _mm_mul_ps(
                       _mm_add_ps(
                         _mm_mul_ps(
                           _mm_add_ps(
                             _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v140, *(__m128 *)coeff4), *(__m128 *)coeff3), v140),
                             *(__m128 *)coeff2),
                           v140),
                         *(__m128 *)coeff1),
                       v140),
                     *(__m128 *)coeff0),
                   v140),
                 v139),
               v139);
      *(float *)&v142 = 1.5707964
                      - COERCE_FLOAT((*(unsigned __int128 *)&_mm_andnot_ps(
                                                               v136,
                                                               _mm_or_ps(
                                                                 _mm_and_ps(
                                                                   _mm_sub_ps(*(__m128 *)_xmm, _mm_add_ps(v141, v141)),
                                                                   v138),
                                                                 _mm_andnot_ps(v138, v141))) | v136.m128_i32[0] & v135.m128_i32[0]) ^ v134.m128_i32[0] & _xmm[0]);
      v143 = hkaPose::accessBoneModelSpace(v4, SWORD1(v5->m128_u64[0]), PROPAGATE);
      v144 = v143->m_rotation.m_vec.m_quad;
      v145 = &v143->m_translation.m_quad;
      v146 = _mm_mul_ps(v144, v144);
      v147 = _mm_add_ps(_mm_shuffle_ps(v146, v146, 78), v146);
      v148 = _mm_add_ps(_mm_shuffle_ps(v147, v147, 177), v147);
      v149 = _mm_rsqrt_ps(v148);
      v433 = v148;
      v150 = _mm_mul_ps(
               v144,
               _mm_mul_ps(
                 _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v149, v148), v149)),
                 _mm_mul_ps(v149, *(__m128 *)_xmm)));
      v435 = v150;
      v151 = v5[1];
      v152 = _mm_shuffle_ps(v150, v150, 255);
      v153 = _mm_mul_ps(v5[1], v150);
      v154 = _mm_shuffle_ps(v150, v150, 201);
      v155 = _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v153, v153, 85), _mm_shuffle_ps(v153, v153, 0)),
               _mm_shuffle_ps(v153, v153, 170));
      v156 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v5[1], v151, 201), v150), _mm_mul_ps(v154, v151));
      v157 = _mm_add_ps(
               _mm_add_ps(
                 _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v152, v152), (__m128)xmmword_141A711B0), v151),
                 _mm_mul_ps(v155, v150)),
               _mm_mul_ps(_mm_shuffle_ps(v156, v156, 201), v152));
      axis.m_quad = _mm_add_ps(v157, v157);
      angle.m_real = _mm_mul_ps(
                       _mm_shuffle_ps((__m128)v5[2].m128_u32[3], (__m128)v5[2].m128_u32[3], 0),
                       _mm_sub_ps(v398, _mm_shuffle_ps((__m128)v142, (__m128)v142, 0)));
      hkQuaternionf::setAxisAngle(&v408, &axis, &angle);
      v158 = _mm_shuffle_ps(v408.m_vec.m_quad, v408.m_vec.m_quad, 255);
      v159 = _mm_mul_ps(v408.m_vec.m_quad, v150);
      v160 = _mm_sub_ps(
               _mm_mul_ps(v154, v408.m_vec.m_quad),
               _mm_mul_ps(_mm_shuffle_ps(v408.m_vec.m_quad, v408.m_vec.m_quad, 201), v150));
      v161 = _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v160, v160, 201), _mm_mul_ps(v150, v158)),
               _mm_mul_ps(v408.m_vec.m_quad, v152));
      v162 = _mm_shuffle_ps(
               v161,
               _mm_unpackhi_ps(
                 v161,
                 _mm_sub_ps(
                   _mm_mul_ps(v152, v158),
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v159, v159, 85), _mm_shuffle_ps(v159, v159, 0)),
                     _mm_shuffle_ps(v159, v159, 170)))),
               196);
      v145[1] = v162;
      v163 = _mm_mul_ps(v162, v162);
      v164 = _mm_add_ps(_mm_shuffle_ps(v163, v163, 78), v163);
      v165 = _mm_add_ps(_mm_shuffle_ps(v164, v164, 177), v164);
      v166 = _mm_rsqrt_ps(v165);
      v437 = v165;
      v145[1] = _mm_mul_ps(
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v166, v165), v166)),
                    _mm_mul_ps(*(__m128 *)_xmm, v166)),
                  v145[1]);
      v167 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v168 = v167[1];
      if ( v168 < v167[3] )
      {
        *(_QWORD *)v168 = "StFIXDIRECTION";
        v169 = __rdtsc();
        *(_DWORD *)(v168 + 8) = v169;
        v167[1] = v168 + 16;
      }
      v170 = SLOWORD(v5->m128_u64[0]);
      if ( v4->m_boneFlags.m_data[v170] & 2 )
        v171 = hkaPose::calculateBoneModelSpace(v4, v170);
      else
        v171 = &v4->m_modelPose.m_data[v170];
      if ( v5[8].m128_i8[1] )
      {
        v172 = SWORD2(v5->m128_u64[0]);
        if ( v4->m_boneFlags.m_data[v172] & 2 )
        {
          v173 = (__m128)xmmword_141A711B0;
          v174.m_quad = (__m128)hkaPose::calculateBoneModelSpace(v4, v172)->m_translation;
        }
        else
        {
          v173 = (__m128)xmmword_141A711B0;
          v174.m_quad = (__m128)v4->m_modelPose.m_data[v172].m_translation;
        }
      }
      else
      {
        v175 = SWORD2(v5->m128_u64[0]);
        if ( v4->m_boneFlags.m_data[v175] & 2 )
          v176 = hkaPose::calculateBoneModelSpace(v4, v175);
        else
          v176 = &v4->m_modelPose.m_data[v175];
        v177 = v176->m_rotation.m_vec.m_quad;
        v173 = (__m128)xmmword_141A711B0;
        v178 = _mm_mul_ps(v5[6], v176->m_scale.m_quad);
        v179 = _mm_mul_ps(v178, v177);
        v180 = _mm_shuffle_ps(v177, v177, 255);
        v181 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v178, v178, 201), v177),
                 _mm_mul_ps(_mm_shuffle_ps(v177, v177, 201), v178));
        v182 = _mm_add_ps(
                 _mm_add_ps(
                   _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v180, v180), (__m128)xmmword_141A711B0), v178),
                   _mm_mul_ps(
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v179, v179, 85), _mm_shuffle_ps(v179, v179, 0)),
                       _mm_shuffle_ps(v179, v179, 170)),
                     v177)),
                 _mm_mul_ps(_mm_shuffle_ps(v181, v181, 201), v180));
        v174.m_quad = _mm_add_ps(v176->m_translation.m_quad, _mm_add_ps(v182, v182));
      }
      v183 = _mm_sub_ps(v174.m_quad, v171->m_translation.m_quad);
      v184 = 0;
      v185 = 0;
      v186 = _mm_mul_ps(v183, v183);
      v187 = _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v186, v186, 85), _mm_shuffle_ps(v186, v186, 0)),
               _mm_shuffle_ps(v186, v186, 170));
      v188 = _mm_rsqrt_ps(v187);
      v436 = v187;
      v189 = _mm_mul_ps(
               v183,
               _mm_andnot_ps(
                 _mm_cmpleps(v187, (__m128)0i64),
                 _mm_mul_ps(
                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v188, v187), v188)),
                   _mm_mul_ps(*(__m128 *)_xmm, v188))));
      from.m_quad = v189;
      v190 = _mm_sub_ps(v383, v171->m_translation.m_quad);
      v191 = _mm_mul_ps(v190, v190);
      v192 = _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v191, v191, 0), _mm_shuffle_ps(v191, v191, 85)),
               _mm_shuffle_ps(v191, v191, 170));
      v193 = _mm_rsqrt_ps(v192);
      v422 = v192;
      v194 = _mm_shuffle_ps((__m128)v5[2].m128_u32[2], (__m128)v5[2].m128_u32[2], 0);
      v195 = _mm_mul_ps(
               v190,
               _mm_andnot_ps(
                 _mm_cmpleps(v192, (__m128)0i64),
                 _mm_mul_ps(
                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v193, v192), v193)),
                   _mm_mul_ps(v193, *(__m128 *)_xmm))));
      v196 = _mm_mul_ps(v195, v189);
      v197 = _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v196, v196, 85), _mm_shuffle_ps(v196, v196, 0)),
               _mm_shuffle_ps(v196, v196, 170));
      LODWORD(v198) = (unsigned __int128)_mm_shuffle_ps(
                                           (__m128)LODWORD(FLOAT_0_99999899),
                                           (__m128)LODWORD(FLOAT_0_99999899),
                                           0);
      v199 = _mm_mul_ps(
               _mm_add_ps(_mm_add_ps(_mm_sub_ps(query.m_quad, v194), _mm_mul_ps(v194, v197)), query.m_quad),
               v173);
      v430 = v199;
      if ( v197.m128_f32[0] < (float)(0.0 - v198) )
        v185 = 1;
      if ( v199.m128_f32[0] <= 0.0 )
        v184 = 1;
      if ( v184 | v185 )
      {
        hkQuaternionf::setFlippedRotation(&v379, &from);
      }
      else if ( v197.m128_f32[0] <= v198 )
      {
        v200 = _mm_rsqrt_ps(v199);
        v201 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v195, v195, 201), v189),
                 _mm_mul_ps(_mm_shuffle_ps(v189, v189, 201), v195));
        v424 = _mm_mul_ps(
                 _mm_mul_ps(
                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v200, v199), v200)),
                   _mm_mul_ps(v200, *(__m128 *)_xmm)),
                 v199);
        v202 = _mm_rcp_ps(v424);
        v203 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps(v399, _mm_mul_ps(v202, v424)), v202), _mm_mul_ps(v194, v173));
        v204 = _mm_mul_ps(_mm_shuffle_ps(v201, v201, 201), v203);
        v434 = v203;
        v205 = _mm_shuffle_ps(v204, _mm_unpackhi_ps(v204, v424), 196);
        v206 = _mm_mul_ps(v205, v205);
        v207 = _mm_add_ps(_mm_shuffle_ps(v206, v206, 78), v206);
        v208 = _mm_add_ps(_mm_shuffle_ps(v207, v207, 177), v207);
        v209 = _mm_rsqrt_ps(v208);
        v426 = v208;
        v379.m_vec.m_quad = _mm_mul_ps(
                              _mm_andnot_ps(
                                _mm_cmpleps(v208, (__m128)0i64),
                                _mm_mul_ps(
                                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v209, v208), v209)),
                                  _mm_mul_ps(v209, *(__m128 *)_xmm))),
                              v205);
      }
      else
      {
        v379.m_vec.m_quad = qi.m_vec.m_quad;
      }
      v210 = hkaPose::accessBoneModelSpace(v4, SLOWORD(v5->m128_u64[0]), PROPAGATE);
      v211 = _mm_shuffle_ps(v379.m_vec.m_quad, v379.m_vec.m_quad, 255);
      v432 = v210->m_rotation.m_vec.m_quad;
      v212 = _mm_shuffle_ps(v432, v432, 255);
      v213 = _mm_sub_ps(
               _mm_mul_ps(_mm_shuffle_ps(v432, v432, 201), v379.m_vec.m_quad),
               _mm_mul_ps(_mm_shuffle_ps(v379.m_vec.m_quad, v379.m_vec.m_quad, 201), v432));
      v214 = _mm_mul_ps(v432, v379.m_vec.m_quad);
      v215 = _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v213, v213, 201), _mm_mul_ps(v211, v432)),
               _mm_mul_ps(v212, v379.m_vec.m_quad));
      v216 = _mm_shuffle_ps(
               v215,
               _mm_unpackhi_ps(
                 v215,
                 _mm_sub_ps(
                   _mm_mul_ps(v212, v211),
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v214, v214, 85), _mm_shuffle_ps(v214, v214, 0)),
                     _mm_shuffle_ps(v214, v214, 170)))),
               196);
      v210->m_rotation.m_vec.m_quad = v216;
      v217 = _mm_mul_ps(v216, v216);
      v218 = _mm_add_ps(_mm_shuffle_ps(v217, v217, 78), v217);
      v219 = _mm_add_ps(_mm_shuffle_ps(v218, v218, 177), v218);
      v220 = _mm_rsqrt_ps(v219);
      v428 = v219;
      v210->m_rotation.m_vec.m_quad = _mm_mul_ps(
                                        _mm_mul_ps(
                                          _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v220, v219), v220)),
                                          _mm_mul_ps(v220, *(__m128 *)_xmm)),
                                        v210->m_rotation.m_vec.m_quad);
      v11 = v381;
      v13 = v380;
      v15 = v377;
      v14 = v376;
    }
    if ( v5[8].m128_i8[1] )
    {
      v221 = v5[5];
      v222 = v5[7];
      v223 = _mm_sub_ps(
               _mm_mul_ps(_mm_shuffle_ps(v221, v221, 201), v222),
               _mm_mul_ps(_mm_shuffle_ps(v222, v222, 201), v221));
      v224 = _mm_sub_ps(_mm_shuffle_ps(v223, v223, 201), _mm_mul_ps(_mm_shuffle_ps(v5[5], v5[5], 255), v222));
      v225 = _mm_mul_ps(v222, v221);
      v226 = _mm_add_ps(v224, _mm_mul_ps(_mm_shuffle_ps(v5[7], v5[7], 255), v221));
      v227 = _mm_add_ps(_mm_shuffle_ps(v225, v225, 78), v225);
      q1.m_vec.m_quad = _mm_shuffle_ps(
                          v226,
                          _mm_unpackhi_ps(v226, _mm_add_ps(_mm_shuffle_ps(v227, v227, 177), v227)),
                          196);
      v228 = SWORD2(v5->m128_u64[0]);
      if ( v4->m_boneFlags.m_data[v228] & 2 )
        v229 = hkaPose::calculateBoneModelSpace(v4, v228);
      else
        v229 = &v4->m_modelPose.m_data[v228];
      v387.m_quad = (__m128)v229->m_translation;
      v388.m_vec.m_quad = (__m128)v229->m_rotation;
      v389.m_quad = (__m128)v229->m_scale;
      t.m_real = _mm_shuffle_ps((__m128)v5[3].m128_u32[0], (__m128)v5[3].m128_u32[0], 0);
      hkQuaternionf::setSlerp(&v388, &v229->m_rotation, &q1, &t);
      v230 = SWORD2(v5->m128_u64[0]);
      v368 = SWORD2(v5->m128_u64[0]);
      v231 = v4->m_skeleton->m_bones.m_size;
      v4->m_boneFlags.m_data[v230] |= 4u;
      v232 = v230 + 1;
      v233 = v231;
      v234 = (signed int)v230 + 1;
      v366 = v230 + 1;
      v371 = v231;
      if ( v234 < v231 )
      {
        v235 = v232;
        do
        {
          LOWORD(v236) = v4->m_skeleton->m_parentIndices.m_data[v234];
          if ( (_WORD)v236 != -1 )
          {
            v237 = v4->m_boneFlags.m_data;
            if ( v237[(signed __int16)v236] & 4 )
            {
              if ( v237[v234] & 1 )
              {
                v238 = v4->m_modelPose.m_data;
                v374 = v4->m_modelPose.m_data;
                if ( (_WORD)v236 == -1 )
                {
                  v258 = v4->m_localPose.m_data;
                  v258[v235].m_translation = v238[v235].m_translation;
                  v258[v235].m_rotation = v238[v235].m_rotation;
                  v258[v235].m_scale = v238[v235].m_scale;
                }
                else
                {
                  v236 = (signed __int16)v236;
                  if ( v237[(signed __int16)v236] & 2 )
                    v239 = hkaPose::calculateBoneModelSpace(v4, v236);
                  else
                    v239 = &v238[v236];
                  v240 = v4->m_localPose.m_data;
                  hkVector4f::setRotatedInverseDir(&v384, &v239->m_rotation, &v239->m_translation);
                  v241 = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
                  v242 = _mm_xor_ps((__m128)_mm_shuffle_epi32(v241, 0), v384.m_quad);
                  v384.m_quad = v242;
                  v243 = _mm_xor_ps((__m128)_mm_shuffle_epi32(v241, 64), v239->m_rotation.m_vec.m_quad);
                  v385 = v243;
                  v244 = v239->m_scale.m_quad;
                  v245 = _mm_shuffle_ps(v243, v243, 255);
                  v246 = _mm_rcp_ps(v244);
                  _mm_store_si128(
                    (__m128i *)&v386,
                    _mm_srli_si128(
                      _mm_slli_si128((__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v244, v246)), v246), 4),
                      4));
                  v247 = v374[v235].m_translation.m_quad;
                  v248 = _mm_mul_ps(v243, v247);
                  v249 = _mm_add_ps(
                           _mm_add_ps(_mm_shuffle_ps(v248, v248, 85), _mm_shuffle_ps(v248, v248, 0)),
                           _mm_shuffle_ps(v248, v248, 170));
                  v250 = _mm_sub_ps(
                           _mm_mul_ps(v243, _mm_shuffle_ps(v247, v247, 201)),
                           _mm_mul_ps(_mm_shuffle_ps(v243, v243, 201), v247));
                  v251 = _mm_add_ps(
                           _mm_add_ps(
                             _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v245, v245), (__m128)xmmword_141A711B0), v247),
                             _mm_mul_ps(v243, v249)),
                           _mm_mul_ps(_mm_shuffle_ps(v250, v250, 201), v245));
                  v240[v235].m_translation.m_quad = _mm_add_ps(_mm_add_ps(v251, v251), v242);
                  v252 = v374[v235].m_rotation.m_vec.m_quad;
                  v253 = _mm_shuffle_ps(v385, v385, 255);
                  v254 = _mm_shuffle_ps(v252, v252, 255);
                  v255 = _mm_mul_ps(v385, v252);
                  v256 = _mm_sub_ps(
                           _mm_mul_ps(_mm_shuffle_ps(v252, v252, 201), v385),
                           _mm_mul_ps(_mm_shuffle_ps(v385, v385, 201), v252));
                  v257 = _mm_add_ps(
                           _mm_add_ps(_mm_shuffle_ps(v256, v256, 201), _mm_mul_ps(v252, v253)),
                           _mm_mul_ps(v385, v254));
                  v233 = v371;
                  v240[v235].m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                                         v257,
                                                         _mm_unpackhi_ps(
                                                           v257,
                                                           _mm_sub_ps(
                                                             _mm_mul_ps(v254, v253),
                                                             _mm_add_ps(
                                                               _mm_add_ps(
                                                                 _mm_shuffle_ps(v255, v255, 85),
                                                                 _mm_shuffle_ps(v255, v255, 0)),
                                                               _mm_shuffle_ps(v255, v255, 170)))),
                                                         196);
                  v240[v235].m_scale.m_quad = _mm_mul_ps(v374[v235].m_scale.m_quad, v386);
                }
                v4->m_boneFlags.m_data[v234] &= 0xFFFFFFFE;
              }
              v4->m_boneFlags.m_data[v234] |= 4u;
              v4->m_modelInSync.m_bool = 0;
            }
          }
          ++v234;
          ++v235;
        }
        while ( v234 < v233 );
        v5 = (__m128 *)v439;
        v230 = v368;
        v232 = v366;
      }
      for ( i = v232; i < v233; ++i )
      {
        v260 = v4->m_boneFlags.m_data;
        v261 = v260[i];
        if ( v261 & 4 )
          v260[i] = v261 & 0xFFFFFFFB | 2;
      }
      v262 = v4->m_modelPose.m_data;
      v263 = v230;
      v262[v263].m_translation = (hkVector4f)v387.m_quad;
      v262[v263].m_rotation = (hkQuaternionf)v388.m_vec.m_quad;
      v262[v263].m_scale = (hkVector4f)v389.m_quad;
      v4->m_boneFlags.m_data[v230] = 1;
      v4->m_localInSync.m_bool = 0;
      v11 = v381;
      v13 = v380;
      v15 = v377;
      v14 = v376;
    }
    if ( (v5->m128_u64[0] & 0x8000000000000000ui64) == 0i64 )
    {
      v264 = SLOWORD(v5->m128_u64[0]);
      if ( v4->m_boneFlags.m_data[v264] & 2 )
        v265 = hkaPose::calculateBoneModelSpace(v4, v264);
      else
        v265 = &v4->m_modelPose.m_data[v264];
      v266 = v265->m_rotation.m_vec.m_quad;
      v267 = _mm_mul_ps(v13, v266);
      v268 = _mm_shuffle_ps(v265->m_rotation.m_vec.m_quad, v266, 255);
      v269 = _mm_add_ps(
               _mm_mul_ps(v13, _mm_sub_ps(_mm_mul_ps(v268, v268), (__m128)xmmword_141A711B0)),
               _mm_mul_ps(
                 v265->m_rotation.m_vec.m_quad,
                 _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v267, v267, 85), _mm_shuffle_ps(v267, v267, 0)),
                   _mm_shuffle_ps(v267, v267, 170))));
      v270 = _mm_sub_ps(
               _mm_mul_ps(v265->m_rotation.m_vec.m_quad, _mm_shuffle_ps(v13, v13, 201)),
               _mm_mul_ps(v13, _mm_shuffle_ps(v266, v266, 201)));
      v271 = _mm_mul_ps(_mm_shuffle_ps(v270, v270, 201), v268);
      v272 = _mm_shuffle_ps(v11, v11, 255);
      v273 = _mm_add_ps(v269, v271);
      v410 = _mm_add_ps(_mm_add_ps(v273, v273), v265->m_translation.m_quad);
      v274 = v265->m_rotation.m_vec.m_quad;
      v275 = _mm_shuffle_ps(v265->m_rotation.m_vec.m_quad, v265->m_rotation.m_vec.m_quad, 255);
      v276 = _mm_sub_ps(
               _mm_mul_ps(_mm_shuffle_ps(v11, v11, 201), v274),
               _mm_mul_ps(_mm_shuffle_ps(v265->m_rotation.m_vec.m_quad, v274, 201), v11));
      v277 = _mm_mul_ps(v11, v275);
      v278 = _mm_mul_ps(v11, v274);
      v279 = _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v276, v276, 201), v277),
               _mm_mul_ps(v265->m_rotation.m_vec.m_quad, v272));
      v411 = _mm_shuffle_ps(
               v279,
               _mm_unpackhi_ps(
                 v279,
                 _mm_sub_ps(
                   _mm_mul_ps(v272, v275),
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v278, v278, 85), _mm_shuffle_ps(v278, v278, 0)),
                     _mm_shuffle_ps(v278, v278, 170)))),
               196);
      v412 = _mm_mul_ps(v265->m_scale.m_quad, v382);
      v280 = v4->m_skeleton->m_bones.m_size;
      v281 = SHIWORD(v5->m128_u64[0]);
      v4->m_boneFlags.m_data[v281] |= 4u;
      v282 = v281 + 1;
      v375 = v281;
      v367 = v281 + 1;
      v283 = (signed int)v281 + 1;
      v284 = v280;
      v372 = v280;
      if ( v283 < v280 )
      {
        v285 = v282;
        do
        {
          LOWORD(v286) = v4->m_skeleton->m_parentIndices.m_data[v283];
          if ( (_WORD)v286 != -1 )
          {
            v287 = v4->m_boneFlags.m_data;
            if ( v287[(signed __int16)v286] & 4 )
            {
              if ( v287[v283] & 1 )
              {
                v288 = v4->m_modelPose.m_data;
                v369 = v4->m_modelPose.m_data;
                if ( (_WORD)v286 == -1 )
                {
                  v306 = v4->m_localPose.m_data;
                  v306[v285].m_translation = v288[v285].m_translation;
                  v306[v285].m_rotation = v288[v285].m_rotation;
                  v306[v285].m_scale = v288[v285].m_scale;
                }
                else
                {
                  v286 = (signed __int16)v286;
                  if ( v287[(signed __int16)v286] & 2 )
                    v289 = hkaPose::calculateBoneModelSpace(v4, v286);
                  else
                    v289 = &v288[v286];
                  v290 = v4->m_localPose.m_data;
                  hkVector4f::setRotatedInverseDir(&v393, &v289->m_rotation, &v289->m_translation);
                  v291 = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
                  v292 = _mm_xor_ps((__m128)_mm_shuffle_epi32(v291, 0), v393.m_quad);
                  v393.m_quad = v292;
                  v293 = _mm_xor_ps((__m128)_mm_shuffle_epi32(v291, 64), v289->m_rotation.m_vec.m_quad);
                  v394 = v293;
                  v294 = _mm_rcp_ps(v289->m_scale.m_quad);
                  v295 = _mm_shuffle_ps(v293, v293, 255);
                  _mm_store_si128(
                    (__m128i *)&v395,
                    _mm_srli_si128(
                      _mm_slli_si128(
                        (__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v294, v289->m_scale.m_quad)), v294),
                        4),
                      4));
                  v296 = v369[v285].m_translation.m_quad;
                  v297 = _mm_mul_ps(v293, v296);
                  v298 = _mm_sub_ps(
                           _mm_mul_ps(_mm_shuffle_ps(v296, v296, 201), v293),
                           _mm_mul_ps(_mm_shuffle_ps(v293, v293, 201), v296));
                  v299 = _mm_add_ps(
                           _mm_add_ps(
                             _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v295, v295), (__m128)xmmword_141A711B0), v296),
                             _mm_mul_ps(
                               _mm_add_ps(
                                 _mm_add_ps(_mm_shuffle_ps(v297, v297, 85), _mm_shuffle_ps(v297, v297, 0)),
                                 _mm_shuffle_ps(v297, v297, 170)),
                               v293)),
                           _mm_mul_ps(_mm_shuffle_ps(v298, v298, 201), v295));
                  v290[v285].m_translation.m_quad = _mm_add_ps(_mm_add_ps(v299, v299), v292);
                  v300 = v369[v285].m_rotation.m_vec.m_quad;
                  v301 = _mm_shuffle_ps(v394, v394, 255);
                  v302 = _mm_shuffle_ps(v300, v300, 255);
                  v303 = _mm_sub_ps(
                           _mm_mul_ps(_mm_shuffle_ps(v300, v300, 201), v394),
                           _mm_mul_ps(_mm_shuffle_ps(v394, v394, 201), v300));
                  v304 = _mm_mul_ps(v394, v300);
                  v305 = _mm_add_ps(
                           _mm_add_ps(_mm_shuffle_ps(v303, v303, 201), _mm_mul_ps(v301, v300)),
                           _mm_mul_ps(v302, v394));
                  v284 = v372;
                  v290[v285].m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                                         v305,
                                                         _mm_unpackhi_ps(
                                                           v305,
                                                           _mm_sub_ps(
                                                             _mm_mul_ps(v302, v301),
                                                             _mm_add_ps(
                                                               _mm_add_ps(
                                                                 _mm_shuffle_ps(v304, v304, 85),
                                                                 _mm_shuffle_ps(v304, v304, 0)),
                                                               _mm_shuffle_ps(v304, v304, 170)))),
                                                         196);
                  v290[v285].m_scale.m_quad = _mm_mul_ps(v369[v285].m_scale.m_quad, v395);
                }
                v4->m_boneFlags.m_data[v283] &= 0xFFFFFFFE;
              }
              v4->m_boneFlags.m_data[v283] |= 4u;
              v4->m_modelInSync.m_bool = 0;
            }
          }
          ++v283;
          ++v285;
        }
        while ( v283 < v284 );
        v5 = (__m128 *)v439;
        v281 = v375;
        v282 = v367;
      }
      for ( j = v282; j < v284; ++j )
      {
        v308 = v4->m_boneFlags.m_data;
        v309 = v308[j];
        if ( v309 & 4 )
          v308[j] = v309 & 0xFFFFFFFB | 2;
      }
      v310 = v4->m_modelPose.m_data;
      v311 = v281;
      v310[v311].m_translation.m_quad = v410;
      v310[v311].m_rotation.m_vec.m_quad = v411;
      v310[v311].m_scale.m_quad = v412;
      v4->m_boneFlags.m_data[v281] = 1;
      v4->m_localInSync.m_bool = 0;
      v15 = v377;
      v14 = v376;
    }
    if ( SLOWORD(v5->m128_u64[1]) >= 0 )
    {
      v312 = SWORD1(v5->m128_u64[0]);
      if ( v4->m_boneFlags.m_data[v312] & 2 )
        v313 = hkaPose::calculateBoneModelSpace(v4, v312);
      else
        v313 = &v4->m_modelPose.m_data[v312];
      v314 = v313->m_rotation.m_vec.m_quad;
      v315 = _mm_mul_ps(v314, v14);
      v316 = _mm_shuffle_ps(v313->m_rotation.m_vec.m_quad, v314, 255);
      v317 = _mm_add_ps(
               _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v316, v316), (__m128)xmmword_141A711B0), v14),
               _mm_mul_ps(
                 _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v315, v315, 85), _mm_shuffle_ps(v315, v315, 0)),
                   _mm_shuffle_ps(v315, v315, 170)),
                 v314));
      v318 = _mm_sub_ps(
               _mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v314),
               _mm_mul_ps(_mm_shuffle_ps(v314, v314, 201), v14));
      v319 = _mm_mul_ps(_mm_shuffle_ps(v318, v318, 201), v316);
      v320 = _mm_shuffle_ps(v15, v15, 255);
      v321 = _mm_add_ps(v317, v319);
      v403 = _mm_add_ps(_mm_add_ps(v321, v321), v313->m_translation.m_quad);
      v322 = v313->m_rotation.m_vec.m_quad;
      v323 = _mm_shuffle_ps(v313->m_rotation.m_vec.m_quad, v313->m_rotation.m_vec.m_quad, 255);
      v324 = _mm_sub_ps(
               _mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), v322),
               _mm_mul_ps(_mm_shuffle_ps(v313->m_rotation.m_vec.m_quad, v322, 201), v15));
      v325 = _mm_mul_ps(v323, v15);
      v326 = _mm_mul_ps(v15, v322);
      v327 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v324, v324, 201), v325), _mm_mul_ps(v320, v322));
      v404 = _mm_shuffle_ps(
               v327,
               _mm_unpackhi_ps(
                 v327,
                 _mm_sub_ps(
                   _mm_mul_ps(v320, v323),
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v326, v326, 85), _mm_shuffle_ps(v326, v326, 0)),
                     _mm_shuffle_ps(v326, v326, 170)))),
               196);
      v405 = _mm_mul_ps(v313->m_scale.m_quad, v378);
      v328 = v4->m_skeleton->m_bones.m_size;
      v329 = SLOWORD(v5->m128_u64[1]);
      v4->m_boneFlags.m_data[v329] |= 4u;
      v330 = v329 + 1;
      v373 = v329;
      v331 = (signed int)v329 + 1;
      v440 = v329 + 1;
      v332 = v328;
      v370 = v328;
      if ( v331 < v328 )
      {
        v333 = v330;
        do
        {
          LOWORD(v334) = v4->m_skeleton->m_parentIndices.m_data[v331];
          if ( (_WORD)v334 != -1 )
          {
            v335 = v4->m_boneFlags.m_data;
            if ( v335[(signed __int16)v334] & 4 )
            {
              if ( v335[v331] & 1 )
              {
                v336 = v4->m_modelPose.m_data;
                if ( (_WORD)v334 == -1 )
                {
                  v356 = v4->m_localPose.m_data;
                  v356[v333].m_translation = v336[v333].m_translation;
                  v356[v333].m_rotation = v336[v333].m_rotation;
                  v356[v333].m_scale = v336[v333].m_scale;
                }
                else
                {
                  v334 = (signed __int16)v334;
                  if ( v335[(signed __int16)v334] & 2 )
                    v337 = hkaPose::calculateBoneModelSpace(v4, v334);
                  else
                    v337 = &v336[v334];
                  v338 = v4->m_localPose.m_data;
                  hkVector4f::setRotatedInverseDir(&v390, &v337->m_rotation, &v337->m_translation);
                  v339 = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
                  v340 = _mm_xor_ps((__m128)_mm_shuffle_epi32(v339, 0), v390.m_quad);
                  v390.m_quad = v340;
                  v341 = _mm_xor_ps((__m128)_mm_shuffle_epi32(v339, 64), v337->m_rotation.m_vec.m_quad);
                  v391 = v341;
                  v342 = v337->m_scale.m_quad;
                  v343 = _mm_shuffle_ps(v341, v341, 255);
                  v344 = _mm_rcp_ps(v342);
                  _mm_store_si128(
                    (__m128i *)&v392,
                    _mm_srli_si128(
                      _mm_slli_si128((__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v342, v344)), v344), 4),
                      4));
                  v345 = v336[v333].m_translation.m_quad;
                  v346 = _mm_mul_ps(v345, v341);
                  v347 = _mm_add_ps(
                           _mm_add_ps(_mm_shuffle_ps(v346, v346, 85), _mm_shuffle_ps(v346, v346, 0)),
                           _mm_shuffle_ps(v346, v346, 170));
                  v348 = _mm_sub_ps(
                           _mm_mul_ps(v341, _mm_shuffle_ps(v336[v333].m_translation.m_quad, v345, 201)),
                           _mm_mul_ps(v345, _mm_shuffle_ps(v341, v341, 201)));
                  v349 = _mm_add_ps(
                           _mm_add_ps(
                             _mm_mul_ps(
                               v336[v333].m_translation.m_quad,
                               _mm_sub_ps(_mm_mul_ps(v343, v343), (__m128)xmmword_141A711B0)),
                             _mm_mul_ps(v341, v347)),
                           _mm_mul_ps(_mm_shuffle_ps(v348, v348, 201), v343));
                  v338[v333].m_translation.m_quad = _mm_add_ps(_mm_add_ps(v349, v349), v340);
                  v350 = v336[v333].m_rotation.m_vec.m_quad;
                  v351 = _mm_shuffle_ps(v391, v391, 255);
                  v352 = _mm_shuffle_ps(v336[v333].m_rotation.m_vec.m_quad, v336[v333].m_rotation.m_vec.m_quad, 255);
                  v353 = _mm_mul_ps(v391, v350);
                  v354 = _mm_sub_ps(
                           _mm_mul_ps(_mm_shuffle_ps(v350, v350, 201), v391),
                           _mm_mul_ps(_mm_shuffle_ps(v391, v391, 201), v350));
                  v355 = _mm_add_ps(
                           _mm_add_ps(
                             _mm_shuffle_ps(v354, v354, 201),
                             _mm_mul_ps(v336[v333].m_rotation.m_vec.m_quad, v351)),
                           _mm_mul_ps(v391, v352));
                  v332 = v370;
                  v338[v333].m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                                         v355,
                                                         _mm_unpackhi_ps(
                                                           v355,
                                                           _mm_sub_ps(
                                                             _mm_mul_ps(v352, v351),
                                                             _mm_add_ps(
                                                               _mm_add_ps(
                                                                 _mm_shuffle_ps(v353, v353, 85),
                                                                 _mm_shuffle_ps(v353, v353, 0)),
                                                               _mm_shuffle_ps(v353, v353, 170)))),
                                                         196);
                  v338[v333].m_scale.m_quad = _mm_mul_ps(v336[v333].m_scale.m_quad, v392);
                }
                v4->m_boneFlags.m_data[v331] &= 0xFFFFFFFE;
              }
              v4->m_boneFlags.m_data[v331] |= 4u;
              v4->m_modelInSync.m_bool = 0;
            }
          }
          ++v331;
          ++v333;
        }
        while ( v331 < v332 );
        v329 = v373;
        v330 = v440;
      }
      for ( k = v330; k < v332; ++k )
      {
        v358 = v4->m_boneFlags.m_data;
        v359 = v358[k];
        if ( v359 & 4 )
          v358[k] = v359 & 0xFFFFFFFB | 2;
      }
      v360 = v4->m_modelPose.m_data;
      v361 = v329;
      v360[v361].m_translation.m_quad = v403;
      v360[v361].m_rotation.m_vec.m_quad = v404;
      v360[v361].m_scale.m_quad = v405;
      v4->m_boneFlags.m_data[v329] = 1;
      v4->m_localInSync.m_bool = 0;
    }
    v362 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v363 = v362[1];
    v364 = v362;
    if ( v363 < v362[3] )
    {
      *(_QWORD *)v363 = "lt";
      v365 = __rdtsc();
      *(_DWORD *)(v363 + 8) = v365;
      v364[1] = v363 + 16;
    }
    v10 = v438;
    v438->m_bool = 1;
  }
  else
  {
    v3->m_bool = 1;
    v10 = v3;
  }
  return v10;
}                  _mm_shuffle_ps(v353, v353, 85),
                                                                 _mm_shuffle_ps(v353, v353, 0)),
                                                               _mm_shuffle_ps(v353, v353, 170)))),
                                                         196);
                  v338[v333].m_scale.m_quad = _mm_mul_ps(v336[v333].m_scale.m_quad, v392);
                }
                v4->m_boneFlags.m_data[v331] &= 0xFFFFFFFE;
              }
              v4->m_boneFlags.m_data[v331] |= 4u;
              v4->m_modelInSync.m_bool = 0;
            }
          }
          ++v331;
          ++v333;
        }
        while ( v331 < v332 );
        v329 = v373;
        v330 = v440;
      }
      for ( k = v330; k < v332; ++k )
      {
        v358 = v4->m_boneFlags.m_data;
        v359 = v358[k];
        if ( v359 & 4 )
      

