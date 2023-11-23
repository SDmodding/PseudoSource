// File Line: 33
// RVA: 0xB251F0
hkBool *__fastcall hkaTwoJointsIkSolver::solve(hkBool *result, hkaTwoJointsIkSolver::Setup *setup, hkaPose *poseInOut)
{
  hkaTwoJointsIkSolver::Setup *v5; // r13
  _QWORD *Value; // rax
  unsigned __int64 v7; // r8
  _QWORD *v8; // r9
  unsigned __int64 v9; // rax
  hkBool *v10; // rax
  __m128 v11; // xmm10
  __int16 m_firstJointTwistIdx; // ax
  __m128 v13; // xmm12
  __m128 v14; // xmm11
  __m128 v15; // xmm9
  hkQsTransformf *v16; // rdi
  __int64 m_firstJointIdx; // rdx
  hkQsTransformf *v18; // r14
  __m128i inserted; // xmm0
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
  __int16 m_secondJointTwistIdx; // ax
  hkQsTransformf *v34; // rdi
  __int64 m_secondJointIdx; // rdx
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
  __int64 m_endBoneIdx; // r8
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
  __m128 v108; // xmm8
  __m128 v109; // xmm7
  __m128 v110; // xmm6
  __m128 v111; // xmm1
  __m128 v112; // xmm8
  __m128 v113; // xmm3
  __m128 v114; // xmm0
  __m128 v115; // xmm1
  __m128 v116; // xmm2
  __m128 v117; // xmm1
  __m128 v118; // xmm8
  __m128 v119; // xmm7
  __m128 v120; // xmm6
  __m128 v121; // xmm2
  __m128 v122; // xmm5
  __m128 v123; // xmm4
  __m128 v124; // xmm3
  __m128 v125; // xmm2
  __m128 v126; // xmm3
  __m128 v127; // xmm1
  __m128 v128; // xmm5
  __m128 v129; // xmm3
  __m128 v130; // xmm1
  __m128 v131; // xmm4
  __m128 v132; // xmm6
  __m128 v133; // xmm5
  __m128 v134; // xmm8
  __m128 v135; // xmm14
  __m128 v136; // xmm3
  __m128 v137; // xmm2
  __m128 v138; // xmm1
  __m128 v139; // xmm0
  hkQsTransformf *v140; // rax
  __m128 v141; // xmm8
  __m128 *p_m_quad; // rbx
  __m128 v143; // xmm0
  __m128 v144; // xmm1
  __m128 v145; // xmm2
  __m128 v146; // xmm1
  __m128 v147; // xmm8
  __m128 v148; // xmm3
  __m128 v149; // xmm7
  __m128 v150; // xmm1
  __m128 v151; // xmm6
  __m128 v152; // xmm2
  __m128 v153; // xmm1
  __m128 v154; // xmm4
  __m128 v155; // xmm3
  __m128 v156; // xmm2
  __m128 v157; // xmm6
  __m128 v158; // xmm6
  __m128 v159; // xmm6
  __m128 v160; // xmm6
  __m128 v161; // xmm0
  __m128 v162; // xmm2
  __m128 v163; // xmm1
  _QWORD *v164; // r8
  unsigned __int64 v165; // rcx
  unsigned __int64 v166; // rax
  __int64 v167; // rdx
  hkQsTransformf *v168; // rbx
  __int64 v169; // rax
  __m128 v170; // xmm11
  hkVector4f v171; // xmm7
  __int64 v172; // rdx
  hkQsTransformf *v173; // rax
  __m128 v174; // xmm3
  __m128 v175; // xmm4
  __m128 v176; // xmm1
  __m128 v177; // xmm5
  __m128 v178; // xmm0
  __m128 v179; // xmm6
  __m128 v180; // xmm7
  int v181; // ecx
  int v182; // eax
  __m128 v183; // xmm1
  __m128 v184; // xmm3
  __m128 v185; // xmm1
  __m128 v186; // xmm7
  __m128 v187; // xmm6
  __m128 v188; // xmm1
  __m128 v189; // xmm3
  __m128 v190; // xmm1
  __m128 v191; // xmm8
  __m128 v192; // xmm6
  __m128 v193; // xmm1
  __m128 v194; // xmm3
  float v195; // xmm1_4
  __m128 v196; // xmm4
  __m128 v197; // xmm1
  __m128 v198; // xmm5
  __m128 v199; // xmm1
  __m128 v200; // xmm2
  __m128 v201; // xmm5
  __m128 v202; // xmm5
  __m128 v203; // xmm0
  __m128 v204; // xmm1
  __m128 v205; // xmm3
  __m128 v206; // xmm1
  hkQsTransformf *v207; // rax
  __m128 v208; // xmm3
  __m128 v209; // xmm5
  __m128 v210; // xmm6
  __m128 v211; // xmm4
  __m128 v212; // xmm6
  __m128 v213; // xmm6
  __m128 v214; // xmm6
  __m128 v215; // xmm0
  __m128 v216; // xmm2
  __m128 v217; // xmm1
  __m128 v218; // xmm1
  __m128 v219; // xmm2
  __m128 v220; // xmm3
  __m128 v221; // xmm3
  __m128 v222; // xmm2
  __m128 v223; // xmm3
  __m128 v224; // xmm0
  __int64 v225; // rdx
  hkQsTransformf *v226; // rax
  __int64 v227; // r8
  __int64 m_size; // rdx
  int v229; // eax
  __int64 v230; // r9
  __int64 v231; // r15
  __int64 v232; // r14
  __int16 v233; // dx
  unsigned int *m_data; // r8
  hkQsTransformf *v235; // r12
  hkQsTransformf *v236; // rdi
  __m128i v237; // xmm0
  __m128 v238; // xmm0
  __m128 v239; // xmm4
  __m128 v240; // xmm1
  __m128 v241; // xmm3
  __m128 v242; // xmm1
  __m128 v243; // xmm2
  __m128 v244; // xmm1
  __m128 v245; // xmm5
  __m128 v246; // xmm2
  __m128 v247; // xmm5
  __m128 v248; // xmm6
  __m128 v249; // xmm4
  __m128 v250; // xmm3
  __m128 v251; // xmm3
  __int64 i; // rcx
  unsigned int *v253; // rdx
  unsigned int v254; // eax
  hkQsTransformf *v255; // rax
  __int64 v256; // rcx
  __int64 v257; // rdx
  hkQsTransformf *v258; // rax
  __m128 v259; // xmm3
  __m128 v260; // xmm1
  __m128 v261; // xmm4
  __m128 v262; // xmm5
  __m128 v263; // xmm1
  __m128 v264; // xmm1
  __m128 v265; // xmm4
  __m128 v266; // xmm5
  __m128 v267; // xmm2
  __m128 v268; // xmm3
  __m128 v269; // xmm5
  __m128 v270; // xmm0
  __m128 v271; // xmm10
  __m128 v272; // xmm5
  __int64 v273; // rdx
  __int64 v274; // r8
  int v275; // eax
  __int64 v276; // r15
  __int64 v277; // r9
  __int64 v278; // r14
  __int16 v279; // dx
  unsigned int *v280; // r8
  hkQsTransformf *v281; // r12
  hkQsTransformf *v282; // rdi
  __m128i v283; // xmm0
  __m128 v284; // xmm2
  __m128 v285; // xmm4
  __m128 v286; // xmm3
  __m128 v287; // xmm1
  __m128 v288; // xmm0
  __m128 v289; // xmm5
  __m128 v290; // xmm2
  __m128 v291; // xmm5
  __m128 v292; // xmm6
  __m128 v293; // xmm3
  __m128 v294; // xmm4
  __m128 v295; // xmm3
  __int64 j; // rcx
  unsigned int *v297; // rdx
  unsigned int v298; // eax
  hkQsTransformf *v299; // rax
  __int64 v300; // rcx
  __int64 v301; // rdx
  hkQsTransformf *v302; // rax
  __m128 v303; // xmm3
  __m128 v304; // xmm1
  __m128 v305; // xmm4
  __m128 v306; // xmm5
  __m128 v307; // xmm0
  __m128 v308; // xmm0
  __m128 v309; // xmm4
  __m128 v310; // xmm5
  __m128 v311; // xmm2
  __m128 v312; // xmm3
  __m128 v313; // xmm5
  __m128 v314; // xmm0
  __m128 v315; // xmm9
  __m128 v316; // xmm5
  __int64 v317; // rdx
  __int64 v318; // r9
  int v319; // eax
  __int64 v320; // r15
  __int64 v321; // r8
  __int64 v322; // r14
  __int16 v323; // dx
  unsigned int *v324; // rcx
  hkQsTransformf *v325; // r12
  hkQsTransformf *v326; // r13
  hkQsTransformf *v327; // rdi
  __m128i v328; // xmm0
  __m128 v329; // xmm0
  __m128 v330; // xmm4
  __m128 v331; // xmm1
  __m128 v332; // xmm3
  __m128 v333; // xmm1
  __m128 v334; // xmm2
  __m128 v335; // xmm1
  __m128 v336; // xmm5
  __m128 v337; // xmm2
  __m128 v338; // xmm5
  __m128 v339; // xmm6
  __m128 v340; // xmm4
  __m128 v341; // xmm3
  __m128 v342; // xmm3
  __int64 k; // rcx
  unsigned int *v344; // rdx
  unsigned int v345; // eax
  hkQsTransformf *v346; // rax
  __int64 v347; // rcx
  _QWORD *v348; // rax
  unsigned __int64 v349; // rcx
  _QWORD *v350; // r8
  unsigned __int64 v351; // rax
  int v352; // [rsp+20h] [rbp-E0h]
  int v353; // [rsp+20h] [rbp-E0h]
  __int64 v354; // [rsp+30h] [rbp-D0h]
  hkQsTransformf *v355; // [rsp+30h] [rbp-D0h]
  __int64 v356; // [rsp+30h] [rbp-D0h]
  __int64 v357; // [rsp+40h] [rbp-C0h]
  __int64 v358; // [rsp+40h] [rbp-C0h]
  __int64 v359; // [rsp+40h] [rbp-C0h]
  unsigned int v360; // [rsp+5Ch] [rbp-A4h]
  unsigned int v361; // [rsp+60h] [rbp-A0h]
  __m128 v362; // [rsp+70h] [rbp-90h]
  hkQsTransformf *v363; // [rsp+70h] [rbp-90h]
  __int64 v364; // [rsp+70h] [rbp-90h]
  __m128 v365; // [rsp+80h] [rbp-80h]
  __m128 v366; // [rsp+90h] [rbp-70h]
  __m128 v367; // [rsp+A0h] [rbp-60h]
  hkQuaternionf v368; // [rsp+B0h] [rbp-50h] BYREF
  __m128 v369; // [rsp+C0h] [rbp-40h]
  __m128 v370; // [rsp+D0h] [rbp-30h]
  __m128 m_quad; // [rsp+E0h] [rbp-20h]
  __m128 v372; // [rsp+F0h] [rbp-10h]
  hkVector4f v373; // [rsp+100h] [rbp+0h] BYREF
  __m128 v374; // [rsp+110h] [rbp+10h]
  __m128 v375; // [rsp+120h] [rbp+20h]
  hkVector4f v376; // [rsp+130h] [rbp+30h]
  hkQuaternionf v377; // [rsp+140h] [rbp+40h] BYREF
  hkVector4f v378; // [rsp+150h] [rbp+50h]
  hkVector4f v379; // [rsp+160h] [rbp+60h] BYREF
  __m128 v380; // [rsp+170h] [rbp+70h]
  __m128 v381; // [rsp+180h] [rbp+80h]
  hkVector4f v382; // [rsp+190h] [rbp+90h] BYREF
  __m128 v383; // [rsp+1A0h] [rbp+A0h]
  __m128 v384; // [rsp+1B0h] [rbp+B0h]
  hkVector4f axis; // [rsp+1C0h] [rbp+C0h] BYREF
  __m128 v386; // [rsp+1D0h] [rbp+D0h]
  __m128 v387; // [rsp+1E0h] [rbp+E0h]
  __m128 v388; // [rsp+1F0h] [rbp+F0h]
  hkSimdFloat32 angle; // [rsp+200h] [rbp+100h] BYREF
  hkQuaternionf q1; // [rsp+210h] [rbp+110h] BYREF
  __m128 v391; // [rsp+220h] [rbp+120h]
  __m128 v392; // [rsp+230h] [rbp+130h]
  __m128 v393; // [rsp+240h] [rbp+140h]
  __m128 v394; // [rsp+250h] [rbp+150h]
  __m128 v395; // [rsp+260h] [rbp+160h]
  hkSimdFloat32 t; // [rsp+270h] [rbp+170h] BYREF
  hkQuaternionf v397; // [rsp+280h] [rbp+180h] BYREF
  hkVector4f from; // [rsp+290h] [rbp+190h] BYREF
  __m128 v399; // [rsp+2A0h] [rbp+1A0h]
  __m128 v400; // [rsp+2B0h] [rbp+1B0h]
  __m128 v401; // [rsp+2C0h] [rbp+1C0h]
  hkVector4f v402; // [rsp+2D0h] [rbp+1D0h] BYREF
  __m128 v403; // [rsp+2E0h] [rbp+1E0h]
  __m128 v404; // [rsp+2F0h] [rbp+1F0h]
  hkVector4f v405; // [rsp+300h] [rbp+200h] BYREF
  __m128 v406; // [rsp+310h] [rbp+210h]
  __m128 v407; // [rsp+320h] [rbp+220h]
  __m128 v408; // [rsp+330h] [rbp+230h]
  __m128 v409; // [rsp+340h] [rbp+240h]
  __m128 v410; // [rsp+350h] [rbp+250h]
  __m128 v411; // [rsp+360h] [rbp+260h]
  __m128 v412; // [rsp+370h] [rbp+270h]
  __m128 v413; // [rsp+380h] [rbp+280h]
  __m128 v414; // [rsp+390h] [rbp+290h]
  __m128 v415; // [rsp+3A0h] [rbp+2A0h]
  __m128 v416; // [rsp+3B0h] [rbp+2B0h]
  __m128 v417; // [rsp+3C0h] [rbp+2C0h]
  __m128 v418; // [rsp+3D0h] [rbp+2D0h]
  __m128 v419; // [rsp+3E0h] [rbp+2E0h]
  __m128 v420; // [rsp+3F0h] [rbp+2F0h]
  __m128 v421; // [rsp+400h] [rbp+300h]
  __m128 v422; // [rsp+410h] [rbp+310h]
  __m128 v423; // [rsp+420h] [rbp+320h]
  __m128 v424; // [rsp+430h] [rbp+330h]
  __m128 v425; // [rsp+440h] [rbp+340h]
  __m128 v426; // [rsp+450h] [rbp+350h]
  int v429; // [rsp+548h] [rbp+448h]

  v5 = setup;
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = Value[1];
  v8 = Value;
  if ( v7 < Value[3] )
  {
    *(_QWORD *)v7 = "LtTWOJOINTSOLVER";
    *(_QWORD *)(v7 + 16) = "StINIT";
    v9 = __rdtsc();
    *(_DWORD *)(v7 + 8) = v9;
    v8[1] = v7 + 24;
  }
  if ( v5->m_enforceEndPosition.m_bool || v5->m_enforceEndRotation.m_bool )
  {
    m_quad = query.m_quad;
    v367 = query.m_quad;
    v11 = qi.m_vec.m_quad;
    v370 = qi.m_vec.m_quad;
    v369 = 0i64;
    v365 = 0i64;
    v366 = qi.m_vec.m_quad;
    m_firstJointTwistIdx = v5->m_firstJointTwistIdx;
    v13 = 0i64;
    v14 = 0i64;
    v15 = qi.m_vec.m_quad;
    if ( m_firstJointTwistIdx >= 0 )
    {
      if ( (poseInOut->m_boneFlags.m_data[m_firstJointTwistIdx] & 2) != 0 )
        v16 = hkaPose::calculateBoneModelSpace(poseInOut, m_firstJointTwistIdx);
      else
        v16 = &poseInOut->m_modelPose.m_data[m_firstJointTwistIdx];
      m_firstJointIdx = v5->m_firstJointIdx;
      if ( (poseInOut->m_boneFlags.m_data[m_firstJointIdx] & 2) != 0 )
        v18 = hkaPose::calculateBoneModelSpace(poseInOut, m_firstJointIdx);
      else
        v18 = &poseInOut->m_modelPose.m_data[m_firstJointIdx];
      hkVector4f::setRotatedInverseDir(&v405, &v18->m_rotation, &v18->m_translation);
      inserted = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
      v405.m_quad = _mm_xor_ps((__m128)_mm_shuffle_epi32(inserted, 0), v405.m_quad);
      v406 = _mm_xor_ps((__m128)_mm_shuffle_epi32(inserted, 64), v18->m_rotation.m_vec.m_quad);
      v20 = v18->m_scale.m_quad;
      v21 = _mm_shuffle_ps(v406, v406, 255);
      v22 = _mm_rcp_ps(v20);
      v407 = (__m128)_mm_srli_si128(
                       _mm_slli_si128((__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v20, v22)), v22), 4),
                       4);
      v23 = _mm_mul_ps(v16->m_translation.m_quad, v406);
      v24 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v23, v23, 85), _mm_shuffle_ps(v23, v23, 0)),
              _mm_shuffle_ps(v23, v23, 170));
      v25 = _mm_shuffle_ps(v406, v406, 201);
      v26 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v16->m_translation.m_quad, v16->m_translation.m_quad, 201), v406),
              _mm_mul_ps(v16->m_translation.m_quad, v25));
      v27 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(v16->m_translation.m_quad, _mm_sub_ps(_mm_mul_ps(v21, v21), (__m128)xmmword_141A711B0)),
                _mm_mul_ps(v24, v406)),
              _mm_mul_ps(_mm_shuffle_ps(v26, v26, 201), v21));
      v13 = _mm_add_ps(_mm_add_ps(v27, v27), v405.m_quad);
      v369 = v13;
      v28 = v16->m_rotation.m_vec.m_quad;
      v29 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v28, v28, 201), v406), _mm_mul_ps(v25, v28));
      v30 = _mm_shuffle_ps(v28, v28, 255);
      v31 = _mm_mul_ps(v406, v28);
      v32 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v29, v29, 201), _mm_mul_ps(v21, v28)), _mm_mul_ps(v30, v406));
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
      v370 = v11;
      m_quad = _mm_mul_ps(v16->m_scale.m_quad, v407);
    }
    m_secondJointTwistIdx = v5->m_secondJointTwistIdx;
    if ( m_secondJointTwistIdx >= 0 )
    {
      if ( (poseInOut->m_boneFlags.m_data[m_secondJointTwistIdx] & 2) != 0 )
        v34 = hkaPose::calculateBoneModelSpace(poseInOut, m_secondJointTwistIdx);
      else
        v34 = &poseInOut->m_modelPose.m_data[m_secondJointTwistIdx];
      m_secondJointIdx = v5->m_secondJointIdx;
      if ( (poseInOut->m_boneFlags.m_data[m_secondJointIdx] & 2) != 0 )
        v36 = hkaPose::calculateBoneModelSpace(poseInOut, m_secondJointIdx);
      else
        v36 = &poseInOut->m_modelPose.m_data[m_secondJointIdx];
      hkVector4f::setRotatedInverseDir(&v402, &v36->m_rotation, &v36->m_translation);
      v37 = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
      v402.m_quad = _mm_xor_ps((__m128)_mm_shuffle_epi32(v37, 0), v402.m_quad);
      v403 = _mm_xor_ps((__m128)_mm_shuffle_epi32(v37, 64), v36->m_rotation.m_vec.m_quad);
      v38 = _mm_rcp_ps(v36->m_scale.m_quad);
      v39 = _mm_shuffle_ps(v403, v403, 255);
      v40 = _mm_shuffle_ps(v403, v403, 201);
      v404 = (__m128)_mm_srli_si128(
                       _mm_slli_si128(
                         (__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v38, v36->m_scale.m_quad)), v38),
                         4),
                       4);
      v41 = _mm_mul_ps(v34->m_translation.m_quad, v403);
      v42 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v41, v41, 85), _mm_shuffle_ps(v41, v41, 0)),
              _mm_shuffle_ps(v41, v41, 170));
      v43 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v34->m_translation.m_quad, v34->m_translation.m_quad, 201), v403),
              _mm_mul_ps(v40, v34->m_translation.m_quad));
      v44 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v39, v39), (__m128)xmmword_141A711B0), v34->m_translation.m_quad),
                _mm_mul_ps(v42, v403)),
              _mm_mul_ps(_mm_shuffle_ps(v43, v43, 201), v39));
      v14 = _mm_add_ps(_mm_add_ps(v44, v44), v402.m_quad);
      v365 = v14;
      v45 = v34->m_rotation.m_vec.m_quad;
      v46 = _mm_shuffle_ps(v45, v45, 255);
      v47 = _mm_mul_ps(v403, v45);
      v48 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v45, v45, 201), v403), _mm_mul_ps(v40, v45));
      v49 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v48, v48, 201), _mm_mul_ps(v39, v45)), _mm_mul_ps(v46, v403));
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
      v366 = v15;
      v367 = _mm_mul_ps(v34->m_scale.m_quad, v404);
    }
    if ( v5->m_enforceEndPosition.m_bool )
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
      v53 = v5->m_firstJointIdx;
      if ( (poseInOut->m_boneFlags.m_data[v53] & 2) != 0 )
        v54 = hkaPose::calculateBoneModelSpace(poseInOut, v53);
      else
        v54 = &poseInOut->m_modelPose.m_data[v53];
      v55 = v5->m_secondJointIdx;
      if ( (poseInOut->m_boneFlags.m_data[v55] & 2) != 0 )
        v56 = hkaPose::calculateBoneModelSpace(poseInOut, v55);
      else
        v56 = &poseInOut->m_modelPose.m_data[v55];
      m_endBoneIdx = v5->m_endBoneIdx;
      if ( (poseInOut->m_boneFlags.m_data[m_endBoneIdx] & 2) != 0 )
        v58 = hkaPose::calculateBoneModelSpace(poseInOut, m_endBoneIdx);
      else
        v58 = &poseInOut->m_modelPose.m_data[m_endBoneIdx];
      v59 = (__m128)xmmword_141A711B0;
      if ( v5->m_enforceEndRotation.m_bool )
      {
        v68 = v5->m_endBoneRotationOffsetLS.m_vec.m_quad;
        v69 = _mm_mul_ps(v5->m_endBoneOffsetLS.m_quad, v68);
        v70 = _mm_shuffle_ps(v68, v68, 255);
        v71 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v69, v69, 85), _mm_shuffle_ps(v69, v69, 0)),
                _mm_shuffle_ps(v69, v69, 170));
        v72 = v5->m_endBoneOffsetLS.m_quad;
        v73 = _mm_add_ps(
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v70, v70), (__m128)xmmword_141A711B0), v72),
                _mm_mul_ps(v68, v71));
        v74 = v5->m_endTargetRotationMS.m_vec.m_quad;
        v75 = _mm_sub_ps(_mm_mul_ps(v72, _mm_shuffle_ps(v68, v68, 201)), _mm_mul_ps(v68, _mm_shuffle_ps(v72, v72, 201)));
        v76 = _mm_shuffle_ps(v74, v74, 255);
        v77 = _mm_add_ps(v73, _mm_mul_ps(_mm_shuffle_ps(v75, v75, 201), v70));
        v78 = _mm_add_ps(v77, v77);
        v79 = _mm_mul_ps(v74, v78);
        v80 = _mm_add_ps(
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v76, v76), (__m128)xmmword_141A711B0), v78),
                _mm_mul_ps(
                  v74,
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v79, v79, 85), _mm_shuffle_ps(v79, v79, 0)),
                    _mm_shuffle_ps(v79, v79, 170))));
        v81 = _mm_sub_ps(_mm_mul_ps(v74, _mm_shuffle_ps(v78, v78, 201)), _mm_mul_ps(_mm_shuffle_ps(v74, v74, 201), v78));
        v82 = _mm_add_ps(v80, _mm_mul_ps(_mm_shuffle_ps(v81, v81, 201), v76));
        v60 = _mm_sub_ps(v5->m_endTargetMS.m_quad, _mm_add_ps(v82, v82));
        v372 = v60;
        v67 = v58->m_translation.m_quad;
      }
      else
      {
        v60 = v5->m_endTargetMS.m_quad;
        v372 = v60;
        v61 = v58->m_rotation.m_vec.m_quad;
        v62 = _mm_mul_ps(v5->m_endBoneOffsetLS.m_quad, v58->m_scale.m_quad);
        v63 = _mm_mul_ps(v61, v62);
        v64 = _mm_shuffle_ps(v61, v61, 255);
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
      v83 = v5->m_secondJointIdx;
      v84 = _mm_sub_ps(v67, v56->m_translation.m_quad);
      v85 = _mm_sub_ps(v60, v54->m_translation.m_quad);
      v86 = _mm_sub_ps(v56->m_translation.m_quad, v54->m_translation.m_quad);
      if ( (poseInOut->m_boneFlags.m_data[v83] & 2) != 0 )
      {
        v87 = hkaPose::calculateBoneModelSpace(poseInOut, v83);
        v59 = (__m128)xmmword_141A711B0;
      }
      else
      {
        v87 = &poseInOut->m_modelPose.m_data[v83];
      }
      v88 = v87->m_rotation.m_vec.m_quad;
      v89 = _mm_mul_ps(v88, v88);
      v90 = _mm_add_ps(_mm_shuffle_ps(v89, v89, 78), v89);
      v91 = _mm_add_ps(_mm_shuffle_ps(v90, v90, 177), v90);
      v92 = _mm_rsqrt_ps(v91);
      v412 = v91;
      v409 = _mm_mul_ps(
               v88,
               _mm_mul_ps(
                 _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v92, v91), v92)),
                 _mm_mul_ps(*(__m128 *)_xmm, v92)));
      v93 = v5->m_hingeAxisLS.m_quad;
      v94 = _mm_shuffle_ps(v409, v409, 255);
      v95 = _mm_mul_ps(v93, v409);
      v96 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v95, v95, 85), _mm_shuffle_ps(v95, v95, 0)),
              _mm_shuffle_ps(v95, v95, 170));
      v97 = _mm_sub_ps(
              _mm_mul_ps(v409, _mm_shuffle_ps(v93, v93, 201)),
              _mm_mul_ps(v93, _mm_shuffle_ps(v409, v409, 201)));
      v98 = _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(v93, _mm_sub_ps(_mm_mul_ps(v94, v94), v59)), _mm_mul_ps(v96, v409)),
              _mm_mul_ps(_mm_shuffle_ps(v97, v97, 201), v94));
      v99 = _mm_add_ps(v98, v98);
      v100 = _mm_mul_ps(v99, v86);
      v101 = _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v100, v100, 85), _mm_shuffle_ps(v100, v100, 0)),
               _mm_shuffle_ps(v100, v100, 170));
      v102 = _mm_mul_ps(v99, v84);
      v103 = _mm_mul_ps(v101, v99);
      v391 = _mm_sub_ps(v86, v103);
      v104 = _mm_mul_ps(
               _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v102, v102, 85), _mm_shuffle_ps(v102, v102, 0)),
                 _mm_shuffle_ps(v102, v102, 170)),
               v99);
      v105 = _mm_sub_ps(v103, v104);
      v386 = _mm_sub_ps(v84, v104);
      v106 = _mm_mul_ps(v105, v105);
      v107 = _mm_mul_ps(v85, v85);
      v362 = _mm_mul_ps(v391, v391);
      v108 = _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v107, v107, 85), _mm_shuffle_ps(v107, v107, 0)),
               _mm_shuffle_ps(v107, v107, 170));
      v109 = _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v362, v362, 85), _mm_shuffle_ps(v362, v362, 0)),
               _mm_shuffle_ps(v362, v362, 170));
      v395 = _mm_mul_ps(v386, v386);
      v110 = _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v395, v395, 85), _mm_shuffle_ps(v395, v395, 0)),
               _mm_shuffle_ps(v395, v395, 170));
      v111 = _mm_rsqrt_ps(v109);
      v410 = v109;
      v112 = _mm_sub_ps(
               _mm_sub_ps(
                 _mm_sub_ps(
                   v108,
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v106, v106, 85), _mm_shuffle_ps(v106, v106, 0)),
                     _mm_shuffle_ps(v106, v106, 170))),
                 v109),
               v110);
      v113 = _mm_mul_ps(v111, *(__m128 *)_xmm);
      v408 = v110;
      v114 = _mm_mul_ps(_mm_mul_ps(v111, v109), v111);
      v115 = _mm_rsqrt_ps(v110);
      v116 = _mm_sub_ps(
               (__m128)0i64,
               _mm_mul_ps(
                 _mm_mul_ps(
                   (__m128)xmmword_141A710D0,
                   _mm_andnot_ps(
                     _mm_cmple_ps(v109, (__m128)0i64),
                     _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, v114), v113), v109))),
                 _mm_andnot_ps(
                   _mm_cmple_ps(v110, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_mul_ps(
                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v115, v110), v115)),
                       _mm_mul_ps(v115, *(__m128 *)_xmm)),
                     v110))));
      v117 = _mm_rcp_ps(v116);
      v414 = v116;
      v388 = (__m128)_xmm;
      v416 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v117, v116)), v117), v112);
      v118 = _mm_min_ps(
               _mm_max_ps(
                 (__m128)COERCE_UNSIGNED_INT(
                           fmax(
                             _mm_shuffle_ps(
                               (__m128)LODWORD(v5->m_cosineMaxHingeAngle),
                               (__m128)LODWORD(v5->m_cosineMaxHingeAngle),
                               0).m128_f32[0],
                             fmin(
                               _mm_shuffle_ps(
                                 (__m128)LODWORD(v5->m_cosineMinHingeAngle),
                                 (__m128)LODWORD(v5->m_cosineMinHingeAngle),
                                 0).m128_f32[0],
                               v416.m128_f32[0]))),
                 *(__m128 *)_xmm_bf800000bf800000bf800000bf800000),
               *(__m128 *)_xmm);
      v119 = _mm_andnot_ps(*(__m128 *)_xmm, v118);
      v120 = _mm_cmplt_ps(v119, *(__m128 *)_xmm);
      v121 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)_xmm, v119), *(__m128 *)_xmm);
      v122 = _mm_cmplt_ps(*(__m128 *)_xmm, v119);
      v123 = _mm_or_ps(_mm_and_ps(_mm_sqrt_ps(v121), v122), _mm_andnot_ps(v122, v119));
      v124 = _mm_or_ps(_mm_andnot_ps(v122, _mm_mul_ps(v119, v119)), _mm_and_ps(v122, v121));
      v125 = _mm_add_ps(
               _mm_mul_ps(
                 _mm_mul_ps(
                   _mm_add_ps(
                     _mm_mul_ps(
                       _mm_add_ps(
                         _mm_mul_ps(
                           _mm_add_ps(
                             _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v124, *(__m128 *)coeff4), *(__m128 *)coeff3), v124),
                             *(__m128 *)coeff2),
                           v124),
                         *(__m128 *)coeff1),
                       v124),
                     *(__m128 *)coeff0),
                   v124),
                 v123),
               v123);
      *(float *)&v360 = 1.5707964
                      - COERCE_FLOAT((_mm_andnot_ps(
                                        v120,
                                        _mm_or_ps(
                                          _mm_and_ps(_mm_sub_ps(*(__m128 *)_xmm, _mm_add_ps(v125, v125)), v122),
                                          _mm_andnot_ps(v122, v125))).m128_u32[0] | v120.m128_i32[0] & v119.m128_i32[0]) ^ v118.m128_i32[0] & _xmm[0]);
      v387 = _mm_shuffle_ps((__m128)v360, (__m128)v360, 0);
      v126 = _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v362, v362, 85), _mm_shuffle_ps(v362, v362, 0)),
               _mm_shuffle_ps(v362, v362, 170));
      v127 = _mm_rsqrt_ps(v126);
      v418 = v126;
      v128 = _mm_xor_ps(
               _mm_mul_ps(
                 _mm_andnot_ps(
                   _mm_cmple_ps(v126, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v127, v126), v127)),
                     _mm_mul_ps(v127, *(__m128 *)_xmm))),
                 v391),
               (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64));
      v129 = _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v395, v395, 85), _mm_shuffle_ps(v395, v395, 0)),
               _mm_shuffle_ps(v395, v395, 170));
      v130 = _mm_rsqrt_ps(v129);
      v420 = v129;
      v131 = _mm_mul_ps(
               _mm_mul_ps(
                 _mm_andnot_ps(
                   _mm_cmple_ps(v129, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v130, v129), v130)),
                     _mm_mul_ps(v130, *(__m128 *)_xmm))),
                 v386),
               v128);
      v132 = _mm_min_ps(
               _mm_max_ps(
                 (__m128)COERCE_UNSIGNED_INT(
                           (float)(_mm_shuffle_ps(v131, v131, 85).m128_f32[0] + _mm_shuffle_ps(v131, v131, 0).m128_f32[0])
                         + _mm_shuffle_ps(v131, v131, 170).m128_f32[0]),
                 *(__m128 *)_xmm_bf800000bf800000bf800000bf800000),
               *(__m128 *)_xmm);
      v133 = _mm_andnot_ps(*(__m128 *)_xmm, v132);
      v134 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)_xmm, v133), *(__m128 *)_xmm);
      v135 = _mm_cmplt_ps(*(__m128 *)_xmm, v133);
      v136 = _mm_or_ps(_mm_and_ps(_mm_sqrt_ps(v134), v135), _mm_andnot_ps(v135, v133));
      v137 = _mm_or_ps(_mm_andnot_ps(v135, _mm_mul_ps(v133, v133)), _mm_and_ps(v135, v134));
      v138 = _mm_add_ps(
               _mm_mul_ps(
                 _mm_mul_ps(
                   _mm_add_ps(
                     _mm_mul_ps(
                       _mm_add_ps(
                         _mm_mul_ps(
                           _mm_add_ps(
                             _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v137, *(__m128 *)coeff4), *(__m128 *)coeff3), v137),
                             *(__m128 *)coeff2),
                           v137),
                         *(__m128 *)coeff1),
                       v137),
                     *(__m128 *)coeff0),
                   v137),
                 v136),
               v136);
      v139 = _mm_cmplt_ps(v133, *(__m128 *)_xmm);
      *(float *)&v361 = 1.5707964
                      - COERCE_FLOAT((_mm_andnot_ps(
                                        v139,
                                        _mm_or_ps(
                                          _mm_and_ps(_mm_sub_ps(*(__m128 *)_xmm, _mm_add_ps(v138, v138)), v135),
                                          _mm_andnot_ps(v135, v138))).m128_u32[0] | v139.m128_i32[0] & v133.m128_i32[0]) ^ v132.m128_i32[0] & _xmm[0]);
      v140 = hkaPose::accessBoneModelSpace(poseInOut, v5->m_secondJointIdx, PROPAGATE);
      v141 = v140->m_rotation.m_vec.m_quad;
      p_m_quad = &v140->m_translation.m_quad;
      v143 = _mm_mul_ps(v141, v141);
      v144 = _mm_add_ps(_mm_shuffle_ps(v143, v143, 78), v143);
      v145 = _mm_add_ps(_mm_shuffle_ps(v144, v144, 177), v144);
      v146 = _mm_rsqrt_ps(v145);
      v422 = v145;
      v147 = _mm_mul_ps(
               v141,
               _mm_mul_ps(
                 _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v146, v145), v146)),
                 _mm_mul_ps(v146, *(__m128 *)_xmm)));
      v424 = v147;
      v148 = v5->m_hingeAxisLS.m_quad;
      v149 = _mm_shuffle_ps(v147, v147, 255);
      v150 = _mm_mul_ps(v148, v147);
      v151 = _mm_shuffle_ps(v147, v147, 201);
      v152 = _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v150, v150, 85), _mm_shuffle_ps(v150, v150, 0)),
               _mm_shuffle_ps(v150, v150, 170));
      v153 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v148, v148, 201), v147), _mm_mul_ps(v151, v148));
      v154 = _mm_add_ps(
               _mm_add_ps(
                 _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v149, v149), (__m128)xmmword_141A711B0), v148),
                 _mm_mul_ps(v152, v147)),
               _mm_mul_ps(_mm_shuffle_ps(v153, v153, 201), v149));
      axis.m_quad = _mm_add_ps(v154, v154);
      angle.m_real = _mm_mul_ps(
                       _mm_shuffle_ps(
                         (__m128)LODWORD(v5->m_secondJointIkGain),
                         (__m128)LODWORD(v5->m_secondJointIkGain),
                         0),
                       _mm_sub_ps(v387, _mm_shuffle_ps((__m128)v361, (__m128)v361, 0)));
      hkQuaternionf::setAxisAngle(&v397, &axis, &angle);
      v155 = _mm_shuffle_ps(v397.m_vec.m_quad, v397.m_vec.m_quad, 255);
      v156 = _mm_mul_ps(v397.m_vec.m_quad, v147);
      v157 = _mm_sub_ps(
               _mm_mul_ps(v151, v397.m_vec.m_quad),
               _mm_mul_ps(_mm_shuffle_ps(v397.m_vec.m_quad, v397.m_vec.m_quad, 201), v147));
      v158 = _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v157, v157, 201), _mm_mul_ps(v147, v155)),
               _mm_mul_ps(v397.m_vec.m_quad, v149));
      v159 = _mm_shuffle_ps(
               v158,
               _mm_unpackhi_ps(
                 v158,
                 _mm_sub_ps(
                   _mm_mul_ps(v149, v155),
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v156, v156, 85), _mm_shuffle_ps(v156, v156, 0)),
                     _mm_shuffle_ps(v156, v156, 170)))),
               196);
      p_m_quad[1] = v159;
      v160 = _mm_mul_ps(v159, v159);
      v161 = _mm_add_ps(_mm_shuffle_ps(v160, v160, 78), v160);
      v162 = _mm_add_ps(_mm_shuffle_ps(v161, v161, 177), v161);
      v163 = _mm_rsqrt_ps(v162);
      v426 = v162;
      p_m_quad[1] = _mm_mul_ps(
                      _mm_mul_ps(
                        _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v163, v162), v163)),
                        _mm_mul_ps(*(__m128 *)_xmm, v163)),
                      p_m_quad[1]);
      v164 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v165 = v164[1];
      if ( v165 < v164[3] )
      {
        *(_QWORD *)v165 = "StFIXDIRECTION";
        v166 = __rdtsc();
        *(_DWORD *)(v165 + 8) = v166;
        v164[1] = v165 + 16;
      }
      v167 = v5->m_firstJointIdx;
      if ( (poseInOut->m_boneFlags.m_data[v167] & 2) != 0 )
        v168 = hkaPose::calculateBoneModelSpace(poseInOut, v167);
      else
        v168 = &poseInOut->m_modelPose.m_data[v167];
      if ( v5->m_enforceEndRotation.m_bool )
      {
        v169 = v5->m_endBoneIdx;
        v170 = (__m128)xmmword_141A711B0;
        if ( (poseInOut->m_boneFlags.m_data[v169] & 2) != 0 )
          v171.m_quad = (__m128)hkaPose::calculateBoneModelSpace(poseInOut, v169)->m_translation;
        else
          v171.m_quad = (__m128)poseInOut->m_modelPose.m_data[v169].m_translation;
      }
      else
      {
        v172 = v5->m_endBoneIdx;
        if ( (poseInOut->m_boneFlags.m_data[v172] & 2) != 0 )
          v173 = hkaPose::calculateBoneModelSpace(poseInOut, v172);
        else
          v173 = &poseInOut->m_modelPose.m_data[v172];
        v174 = v173->m_rotation.m_vec.m_quad;
        v170 = (__m128)xmmword_141A711B0;
        v175 = _mm_mul_ps(v5->m_endBoneOffsetLS.m_quad, v173->m_scale.m_quad);
        v176 = _mm_mul_ps(v175, v174);
        v177 = _mm_shuffle_ps(v174, v174, 255);
        v178 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v175, v175, 201), v174),
                 _mm_mul_ps(_mm_shuffle_ps(v174, v174, 201), v175));
        v179 = _mm_add_ps(
                 _mm_add_ps(
                   _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v177, v177), (__m128)xmmword_141A711B0), v175),
                   _mm_mul_ps(
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v176, v176, 85), _mm_shuffle_ps(v176, v176, 0)),
                       _mm_shuffle_ps(v176, v176, 170)),
                     v174)),
                 _mm_mul_ps(_mm_shuffle_ps(v178, v178, 201), v177));
        v171.m_quad = _mm_add_ps(v173->m_translation.m_quad, _mm_add_ps(v179, v179));
      }
      v180 = _mm_sub_ps(v171.m_quad, v168->m_translation.m_quad);
      v181 = 0;
      v182 = 0;
      v183 = _mm_mul_ps(v180, v180);
      v184 = _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v183, v183, 85), _mm_shuffle_ps(v183, v183, 0)),
               _mm_shuffle_ps(v183, v183, 170));
      v185 = _mm_rsqrt_ps(v184);
      v425 = v184;
      v186 = _mm_mul_ps(
               v180,
               _mm_andnot_ps(
                 _mm_cmple_ps(v184, (__m128)0i64),
                 _mm_mul_ps(
                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v185, v184), v185)),
                   _mm_mul_ps(*(__m128 *)_xmm, v185))));
      from.m_quad = v186;
      v187 = _mm_sub_ps(v372, v168->m_translation.m_quad);
      v188 = _mm_mul_ps(v187, v187);
      v189 = _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v188, v188, 0), _mm_shuffle_ps(v188, v188, 85)),
               _mm_shuffle_ps(v188, v188, 170));
      v190 = _mm_rsqrt_ps(v189);
      v411 = v189;
      v191 = _mm_shuffle_ps((__m128)LODWORD(v5->m_firstJointIkGain), (__m128)LODWORD(v5->m_firstJointIkGain), 0);
      v192 = _mm_mul_ps(
               v187,
               _mm_andnot_ps(
                 _mm_cmple_ps(v189, (__m128)0i64),
                 _mm_mul_ps(
                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v190, v189), v190)),
                   _mm_mul_ps(v190, *(__m128 *)_xmm))));
      v193 = _mm_mul_ps(v192, v186);
      v194 = _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v193, v193, 85), _mm_shuffle_ps(v193, v193, 0)),
               _mm_shuffle_ps(v193, v193, 170));
      v195 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_99999899), (__m128)LODWORD(FLOAT_0_99999899), 0).m128_f32[0];
      v196 = _mm_mul_ps(
               _mm_add_ps(_mm_add_ps(_mm_sub_ps(query.m_quad, v191), _mm_mul_ps(v191, v194)), query.m_quad),
               v170);
      v419 = v196;
      if ( v194.m128_f32[0] < (float)(0.0 - v195) )
        v182 = 1;
      if ( v196.m128_f32[0] <= 0.0 )
        v181 = 1;
      if ( v181 | v182 )
      {
        hkQuaternionf::setFlippedRotation(&v368, &from);
      }
      else if ( v194.m128_f32[0] <= v195 )
      {
        v197 = _mm_rsqrt_ps(v196);
        v198 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v192, v192, 201), v186),
                 _mm_mul_ps(_mm_shuffle_ps(v186, v186, 201), v192));
        v413 = _mm_mul_ps(
                 _mm_mul_ps(
                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v197, v196), v197)),
                   _mm_mul_ps(v197, *(__m128 *)_xmm)),
                 v196);
        v199 = _mm_rcp_ps(v413);
        v200 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps(v388, _mm_mul_ps(v199, v413)), v199), _mm_mul_ps(v191, v170));
        v201 = _mm_mul_ps(_mm_shuffle_ps(v198, v198, 201), v200);
        v423 = v200;
        v202 = _mm_shuffle_ps(v201, _mm_unpackhi_ps(v201, v413), 196);
        v203 = _mm_mul_ps(v202, v202);
        v204 = _mm_add_ps(_mm_shuffle_ps(v203, v203, 78), v203);
        v205 = _mm_add_ps(_mm_shuffle_ps(v204, v204, 177), v204);
        v206 = _mm_rsqrt_ps(v205);
        v415 = v205;
        v368.m_vec.m_quad = _mm_mul_ps(
                              _mm_andnot_ps(
                                _mm_cmple_ps(v205, (__m128)0i64),
                                _mm_mul_ps(
                                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v206, v205), v206)),
                                  _mm_mul_ps(v206, *(__m128 *)_xmm))),
                              v202);
      }
      else
      {
        v368.m_vec.m_quad = qi.m_vec.m_quad;
      }
      v207 = hkaPose::accessBoneModelSpace(poseInOut, v5->m_firstJointIdx, PROPAGATE);
      v208 = _mm_shuffle_ps(v368.m_vec.m_quad, v368.m_vec.m_quad, 255);
      v421 = v207->m_rotation.m_vec.m_quad;
      v209 = _mm_shuffle_ps(v421, v421, 255);
      v210 = _mm_sub_ps(
               _mm_mul_ps(_mm_shuffle_ps(v421, v421, 201), v368.m_vec.m_quad),
               _mm_mul_ps(_mm_shuffle_ps(v368.m_vec.m_quad, v368.m_vec.m_quad, 201), v421));
      v211 = _mm_mul_ps(v421, v368.m_vec.m_quad);
      v212 = _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v210, v210, 201), _mm_mul_ps(v208, v421)),
               _mm_mul_ps(v209, v368.m_vec.m_quad));
      v213 = _mm_shuffle_ps(
               v212,
               _mm_unpackhi_ps(
                 v212,
                 _mm_sub_ps(
                   _mm_mul_ps(v209, v208),
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v211, v211, 85), _mm_shuffle_ps(v211, v211, 0)),
                     _mm_shuffle_ps(v211, v211, 170)))),
               196);
      v207->m_rotation.m_vec.m_quad = v213;
      v214 = _mm_mul_ps(v213, v213);
      v215 = _mm_add_ps(_mm_shuffle_ps(v214, v214, 78), v214);
      v216 = _mm_add_ps(_mm_shuffle_ps(v215, v215, 177), v215);
      v217 = _mm_rsqrt_ps(v216);
      v417 = v216;
      v207->m_rotation.m_vec.m_quad = _mm_mul_ps(
                                        _mm_mul_ps(
                                          _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v217, v216), v217)),
                                          _mm_mul_ps(v217, *(__m128 *)_xmm)),
                                        v207->m_rotation.m_vec.m_quad);
      v11 = v370;
      v13 = v369;
      v15 = v366;
      v14 = v365;
    }
    if ( v5->m_enforceEndRotation.m_bool )
    {
      v218 = v5->m_endTargetRotationMS.m_vec.m_quad;
      v219 = v5->m_endBoneRotationOffsetLS.m_vec.m_quad;
      v220 = _mm_sub_ps(
               _mm_mul_ps(_mm_shuffle_ps(v218, v218, 201), v219),
               _mm_mul_ps(_mm_shuffle_ps(v219, v219, 201), v218));
      v221 = _mm_sub_ps(_mm_shuffle_ps(v220, v220, 201), _mm_mul_ps(_mm_shuffle_ps(v218, v218, 255), v219));
      v222 = _mm_mul_ps(v219, v218);
      v223 = _mm_add_ps(
               v221,
               _mm_mul_ps(
                 _mm_shuffle_ps(
                   v5->m_endBoneRotationOffsetLS.m_vec.m_quad,
                   v5->m_endBoneRotationOffsetLS.m_vec.m_quad,
                   255),
                 v218));
      v224 = _mm_add_ps(_mm_shuffle_ps(v222, v222, 78), v222);
      q1.m_vec.m_quad = _mm_shuffle_ps(
                          v223,
                          _mm_unpackhi_ps(v223, _mm_add_ps(_mm_shuffle_ps(v224, v224, 177), v224)),
                          196);
      v225 = v5->m_endBoneIdx;
      if ( (poseInOut->m_boneFlags.m_data[v225] & 2) != 0 )
        v226 = hkaPose::calculateBoneModelSpace(poseInOut, v225);
      else
        v226 = &poseInOut->m_modelPose.m_data[v225];
      v376.m_quad = (__m128)v226->m_translation;
      v377.m_vec.m_quad = (__m128)v226->m_rotation;
      v378.m_quad = (__m128)v226->m_scale;
      t.m_real = _mm_shuffle_ps((__m128)LODWORD(v5->m_endJointIkGain), (__m128)LODWORD(v5->m_endJointIkGain), 0);
      hkQuaternionf::setSlerp(&v377, &v226->m_rotation, &q1, &t);
      v227 = v5->m_endBoneIdx;
      v354 = v227;
      m_size = poseInOut->m_skeleton->m_bones.m_size;
      poseInOut->m_boneFlags.m_data[v227] |= 4u;
      v229 = v227 + 1;
      v230 = m_size;
      v231 = (int)v227 + 1;
      v352 = v227 + 1;
      v357 = m_size;
      if ( v231 < m_size )
      {
        v232 = v229;
        do
        {
          v233 = poseInOut->m_skeleton->m_parentIndices.m_data[v231];
          if ( v233 != -1 )
          {
            m_data = poseInOut->m_boneFlags.m_data;
            if ( (m_data[v233] & 4) != 0 )
            {
              if ( (m_data[v231] & 1) != 0 )
              {
                v363 = poseInOut->m_modelPose.m_data;
                if ( (m_data[v233] & 2) != 0 )
                  v235 = hkaPose::calculateBoneModelSpace(poseInOut, v233);
                else
                  v235 = &poseInOut->m_modelPose.m_data[v233];
                v236 = poseInOut->m_localPose.m_data;
                hkVector4f::setRotatedInverseDir(&v373, &v235->m_rotation, &v235->m_translation);
                v237 = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
                v373.m_quad = _mm_xor_ps((__m128)_mm_shuffle_epi32(v237, 0), v373.m_quad);
                v374 = _mm_xor_ps((__m128)_mm_shuffle_epi32(v237, 64), v235->m_rotation.m_vec.m_quad);
                v238 = v235->m_scale.m_quad;
                v239 = _mm_shuffle_ps(v374, v374, 255);
                v240 = _mm_rcp_ps(v238);
                v375 = (__m128)_mm_srli_si128(
                                 _mm_slli_si128(
                                   (__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v238, v240)), v240),
                                   4),
                                 4);
                v241 = v363[v232].m_translation.m_quad;
                v242 = _mm_mul_ps(v374, v241);
                v243 = _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v242, v242, 85), _mm_shuffle_ps(v242, v242, 0)),
                         _mm_shuffle_ps(v242, v242, 170));
                v244 = _mm_sub_ps(
                         _mm_mul_ps(v374, _mm_shuffle_ps(v241, v241, 201)),
                         _mm_mul_ps(_mm_shuffle_ps(v374, v374, 201), v241));
                v245 = _mm_add_ps(
                         _mm_add_ps(
                           _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v239, v239), (__m128)xmmword_141A711B0), v241),
                           _mm_mul_ps(v374, v243)),
                         _mm_mul_ps(_mm_shuffle_ps(v244, v244, 201), v239));
                v236[v232].m_translation.m_quad = _mm_add_ps(_mm_add_ps(v245, v245), v373.m_quad);
                v246 = v363[v232].m_rotation.m_vec.m_quad;
                v247 = _mm_shuffle_ps(v374, v374, 255);
                v248 = _mm_shuffle_ps(v246, v246, 255);
                v249 = _mm_mul_ps(v374, v246);
                v250 = _mm_sub_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v246, v246, 201), v374),
                         _mm_mul_ps(_mm_shuffle_ps(v374, v374, 201), v246));
                v251 = _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v250, v250, 201), _mm_mul_ps(v246, v247)),
                         _mm_mul_ps(v374, v248));
                v230 = v357;
                v236[v232].m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                                       v251,
                                                       _mm_unpackhi_ps(
                                                         v251,
                                                         _mm_sub_ps(
                                                           _mm_mul_ps(v248, v247),
                                                           _mm_add_ps(
                                                             _mm_add_ps(
                                                               _mm_shuffle_ps(v249, v249, 85),
                                                               _mm_shuffle_ps(v249, v249, 0)),
                                                             _mm_shuffle_ps(v249, v249, 170)))),
                                                       196);
                v236[v232].m_scale.m_quad = _mm_mul_ps(v363[v232].m_scale.m_quad, v375);
                poseInOut->m_boneFlags.m_data[v231] &= ~1u;
              }
              poseInOut->m_boneFlags.m_data[v231] |= 4u;
              poseInOut->m_modelInSync.m_bool = 0;
            }
          }
          ++v231;
          ++v232;
        }
        while ( v231 < v230 );
        v5 = setup;
        v227 = v354;
        v229 = v352;
      }
      for ( i = v229; i < v230; ++i )
      {
        v253 = poseInOut->m_boneFlags.m_data;
        v254 = v253[i];
        if ( (v254 & 4) != 0 )
          v253[i] = v254 & 0xFFFFFFF9 | 2;
      }
      v255 = poseInOut->m_modelPose.m_data;
      v256 = v227;
      v255[v256].m_translation = (hkVector4f)v376.m_quad;
      v255[v256].m_rotation = (hkQuaternionf)v377.m_vec.m_quad;
      v255[v256].m_scale = (hkVector4f)v378.m_quad;
      poseInOut->m_boneFlags.m_data[v227] = 1;
      poseInOut->m_localInSync.m_bool = 0;
      v11 = v370;
      v13 = v369;
      v15 = v366;
      v14 = v365;
    }
    if ( v5->m_firstJointTwistIdx >= 0 )
    {
      v257 = v5->m_firstJointIdx;
      if ( (poseInOut->m_boneFlags.m_data[v257] & 2) != 0 )
        v258 = hkaPose::calculateBoneModelSpace(poseInOut, v257);
      else
        v258 = &poseInOut->m_modelPose.m_data[v257];
      v259 = v258->m_rotation.m_vec.m_quad;
      v260 = _mm_mul_ps(v13, v259);
      v261 = _mm_shuffle_ps(v259, v259, 255);
      v262 = _mm_add_ps(
               _mm_mul_ps(v13, _mm_sub_ps(_mm_mul_ps(v261, v261), (__m128)xmmword_141A711B0)),
               _mm_mul_ps(
                 v259,
                 _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v260, v260, 85), _mm_shuffle_ps(v260, v260, 0)),
                   _mm_shuffle_ps(v260, v260, 170))));
      v263 = _mm_sub_ps(
               _mm_mul_ps(v259, _mm_shuffle_ps(v13, v13, 201)),
               _mm_mul_ps(v13, _mm_shuffle_ps(v259, v259, 201)));
      v264 = _mm_mul_ps(_mm_shuffle_ps(v263, v263, 201), v261);
      v265 = _mm_shuffle_ps(v11, v11, 255);
      v266 = _mm_add_ps(v262, v264);
      v399 = _mm_add_ps(_mm_add_ps(v266, v266), v258->m_translation.m_quad);
      v267 = v258->m_rotation.m_vec.m_quad;
      v268 = _mm_shuffle_ps(v267, v267, 255);
      v269 = _mm_sub_ps(
               _mm_mul_ps(_mm_shuffle_ps(v11, v11, 201), v267),
               _mm_mul_ps(_mm_shuffle_ps(v267, v267, 201), v11));
      v270 = _mm_mul_ps(v11, v268);
      v271 = _mm_mul_ps(v11, v267);
      v272 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v269, v269, 201), v270), _mm_mul_ps(v267, v265));
      v400 = _mm_shuffle_ps(
               v272,
               _mm_unpackhi_ps(
                 v272,
                 _mm_sub_ps(
                   _mm_mul_ps(v265, v268),
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v271, v271, 85), _mm_shuffle_ps(v271, v271, 0)),
                     _mm_shuffle_ps(v271, v271, 170)))),
               196);
      v401 = _mm_mul_ps(v258->m_scale.m_quad, m_quad);
      v273 = poseInOut->m_skeleton->m_bones.m_size;
      v274 = v5->m_firstJointTwistIdx;
      poseInOut->m_boneFlags.m_data[v274] |= 4u;
      v275 = v274 + 1;
      v364 = v274;
      v353 = v274 + 1;
      v276 = (int)v274 + 1;
      v277 = v273;
      v358 = v273;
      if ( v276 < v273 )
      {
        v278 = v275;
        do
        {
          v279 = poseInOut->m_skeleton->m_parentIndices.m_data[v276];
          if ( v279 != -1 )
          {
            v280 = poseInOut->m_boneFlags.m_data;
            if ( (v280[v279] & 4) != 0 )
            {
              if ( (v280[v276] & 1) != 0 )
              {
                v355 = poseInOut->m_modelPose.m_data;
                if ( (v280[v279] & 2) != 0 )
                  v281 = hkaPose::calculateBoneModelSpace(poseInOut, v279);
                else
                  v281 = &poseInOut->m_modelPose.m_data[v279];
                v282 = poseInOut->m_localPose.m_data;
                hkVector4f::setRotatedInverseDir(&v382, &v281->m_rotation, &v281->m_translation);
                v283 = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
                v382.m_quad = _mm_xor_ps((__m128)_mm_shuffle_epi32(v283, 0), v382.m_quad);
                v383 = _mm_xor_ps((__m128)_mm_shuffle_epi32(v283, 64), v281->m_rotation.m_vec.m_quad);
                v284 = _mm_rcp_ps(v281->m_scale.m_quad);
                v285 = _mm_shuffle_ps(v383, v383, 255);
                v384 = (__m128)_mm_srli_si128(
                                 _mm_slli_si128(
                                   (__m128i)_mm_mul_ps(
                                              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(v284, v281->m_scale.m_quad)),
                                              v284),
                                   4),
                                 4);
                v286 = v355[v278].m_translation.m_quad;
                v287 = _mm_mul_ps(v383, v286);
                v288 = _mm_sub_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v286, v286, 201), v383),
                         _mm_mul_ps(_mm_shuffle_ps(v383, v383, 201), v286));
                v289 = _mm_add_ps(
                         _mm_add_ps(
                           _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v285, v285), (__m128)xmmword_141A711B0), v286),
                           _mm_mul_ps(
                             _mm_add_ps(
                               _mm_add_ps(_mm_shuffle_ps(v287, v287, 85), _mm_shuffle_ps(v287, v287, 0)),
                               _mm_shuffle_ps(v287, v287, 170)),
                             v383)),
                         _mm_mul_ps(_mm_shuffle_ps(v288, v288, 201), v285));
                v282[v278].m_translation.m_quad = _mm_add_ps(_mm_add_ps(v289, v289), v382.m_quad);
                v290 = v355[v278].m_rotation.m_vec.m_quad;
                v291 = _mm_shuffle_ps(v383, v383, 255);
                v292 = _mm_shuffle_ps(v290, v290, 255);
                v293 = _mm_sub_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v290, v290, 201), v383),
                         _mm_mul_ps(_mm_shuffle_ps(v383, v383, 201), v290));
                v294 = _mm_mul_ps(v383, v290);
                v295 = _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v293, v293, 201), _mm_mul_ps(v291, v290)),
                         _mm_mul_ps(v292, v383));
                v277 = v358;
                v282[v278].m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                                       v295,
                                                       _mm_unpackhi_ps(
                                                         v295,
                                                         _mm_sub_ps(
                                                           _mm_mul_ps(v292, v291),
                                                           _mm_add_ps(
                                                             _mm_add_ps(
                                                               _mm_shuffle_ps(v294, v294, 85),
                                                               _mm_shuffle_ps(v294, v294, 0)),
                                                             _mm_shuffle_ps(v294, v294, 170)))),
                                                       196);
                v282[v278].m_scale.m_quad = _mm_mul_ps(v355[v278].m_scale.m_quad, v384);
                poseInOut->m_boneFlags.m_data[v276] &= ~1u;
              }
              poseInOut->m_boneFlags.m_data[v276] |= 4u;
              poseInOut->m_modelInSync.m_bool = 0;
            }
          }
          ++v276;
          ++v278;
        }
        while ( v276 < v277 );
        v5 = setup;
        v274 = v364;
        v275 = v353;
      }
      for ( j = v275; j < v277; ++j )
      {
        v297 = poseInOut->m_boneFlags.m_data;
        v298 = v297[j];
        if ( (v298 & 4) != 0 )
          v297[j] = v298 & 0xFFFFFFF9 | 2;
      }
      v299 = poseInOut->m_modelPose.m_data;
      v300 = v274;
      v299[v300].m_translation.m_quad = v399;
      v299[v300].m_rotation.m_vec.m_quad = v400;
      v299[v300].m_scale.m_quad = v401;
      poseInOut->m_boneFlags.m_data[v274] = 1;
      poseInOut->m_localInSync.m_bool = 0;
      v15 = v366;
      v14 = v365;
    }
    if ( v5->m_secondJointTwistIdx >= 0 )
    {
      v301 = v5->m_secondJointIdx;
      if ( (poseInOut->m_boneFlags.m_data[v301] & 2) != 0 )
        v302 = hkaPose::calculateBoneModelSpace(poseInOut, v301);
      else
        v302 = &poseInOut->m_modelPose.m_data[v301];
      v303 = v302->m_rotation.m_vec.m_quad;
      v304 = _mm_mul_ps(v303, v14);
      v305 = _mm_shuffle_ps(v303, v303, 255);
      v306 = _mm_add_ps(
               _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v305, v305), (__m128)xmmword_141A711B0), v14),
               _mm_mul_ps(
                 _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v304, v304, 85), _mm_shuffle_ps(v304, v304, 0)),
                   _mm_shuffle_ps(v304, v304, 170)),
                 v303));
      v307 = _mm_sub_ps(
               _mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v303),
               _mm_mul_ps(_mm_shuffle_ps(v303, v303, 201), v14));
      v308 = _mm_mul_ps(_mm_shuffle_ps(v307, v307, 201), v305);
      v309 = _mm_shuffle_ps(v15, v15, 255);
      v310 = _mm_add_ps(v306, v308);
      v392 = _mm_add_ps(_mm_add_ps(v310, v310), v302->m_translation.m_quad);
      v311 = v302->m_rotation.m_vec.m_quad;
      v312 = _mm_shuffle_ps(v311, v311, 255);
      v313 = _mm_sub_ps(
               _mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), v311),
               _mm_mul_ps(_mm_shuffle_ps(v311, v311, 201), v15));
      v314 = _mm_mul_ps(v312, v15);
      v315 = _mm_mul_ps(v15, v311);
      v316 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v313, v313, 201), v314), _mm_mul_ps(v309, v311));
      v393 = _mm_shuffle_ps(
               v316,
               _mm_unpackhi_ps(
                 v316,
                 _mm_sub_ps(
                   _mm_mul_ps(v309, v312),
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v315, v315, 85), _mm_shuffle_ps(v315, v315, 0)),
                     _mm_shuffle_ps(v315, v315, 170)))),
               196);
      v394 = _mm_mul_ps(v302->m_scale.m_quad, v367);
      v317 = poseInOut->m_skeleton->m_bones.m_size;
      v318 = v5->m_secondJointTwistIdx;
      poseInOut->m_boneFlags.m_data[v318] |= 4u;
      v319 = v318 + 1;
      v359 = v318;
      v320 = (int)v318 + 1;
      v429 = v318 + 1;
      v321 = v317;
      v356 = v317;
      if ( v320 < v317 )
      {
        v322 = v319;
        do
        {
          v323 = poseInOut->m_skeleton->m_parentIndices.m_data[v320];
          if ( v323 != -1 )
          {
            v324 = poseInOut->m_boneFlags.m_data;
            if ( (v324[v323] & 4) != 0 )
            {
              if ( (v324[v320] & 1) != 0 )
              {
                v325 = poseInOut->m_modelPose.m_data;
                if ( (v324[v323] & 2) != 0 )
                  v326 = hkaPose::calculateBoneModelSpace(poseInOut, v323);
                else
                  v326 = &v325[v323];
                v327 = poseInOut->m_localPose.m_data;
                hkVector4f::setRotatedInverseDir(&v379, &v326->m_rotation, &v326->m_translation);
                v328 = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
                v379.m_quad = _mm_xor_ps((__m128)_mm_shuffle_epi32(v328, 0), v379.m_quad);
                v380 = _mm_xor_ps((__m128)_mm_shuffle_epi32(v328, 64), v326->m_rotation.m_vec.m_quad);
                v329 = v326->m_scale.m_quad;
                v330 = _mm_shuffle_ps(v380, v380, 255);
                v331 = _mm_rcp_ps(v329);
                v381 = (__m128)_mm_srli_si128(
                                 _mm_slli_si128(
                                   (__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v329, v331)), v331),
                                   4),
                                 4);
                v332 = v325[v322].m_translation.m_quad;
                v333 = _mm_mul_ps(v332, v380);
                v334 = _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v333, v333, 85), _mm_shuffle_ps(v333, v333, 0)),
                         _mm_shuffle_ps(v333, v333, 170));
                v335 = _mm_sub_ps(
                         _mm_mul_ps(v380, _mm_shuffle_ps(v332, v332, 201)),
                         _mm_mul_ps(v332, _mm_shuffle_ps(v380, v380, 201)));
                v336 = _mm_add_ps(
                         _mm_add_ps(
                           _mm_mul_ps(v332, _mm_sub_ps(_mm_mul_ps(v330, v330), (__m128)xmmword_141A711B0)),
                           _mm_mul_ps(v380, v334)),
                         _mm_mul_ps(_mm_shuffle_ps(v335, v335, 201), v330));
                v327[v322].m_translation.m_quad = _mm_add_ps(_mm_add_ps(v336, v336), v379.m_quad);
                v337 = v325[v322].m_rotation.m_vec.m_quad;
                v338 = _mm_shuffle_ps(v380, v380, 255);
                v339 = _mm_shuffle_ps(v337, v337, 255);
                v340 = _mm_mul_ps(v380, v337);
                v341 = _mm_sub_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v337, v337, 201), v380),
                         _mm_mul_ps(_mm_shuffle_ps(v380, v380, 201), v337));
                v342 = _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v341, v341, 201), _mm_mul_ps(v337, v338)),
                         _mm_mul_ps(v380, v339));
                v321 = v356;
                v327[v322].m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                                       v342,
                                                       _mm_unpackhi_ps(
                                                         v342,
                                                         _mm_sub_ps(
                                                           _mm_mul_ps(v339, v338),
                                                           _mm_add_ps(
                                                             _mm_add_ps(
                                                               _mm_shuffle_ps(v340, v340, 85),
                                                               _mm_shuffle_ps(v340, v340, 0)),
                                                             _mm_shuffle_ps(v340, v340, 170)))),
                                                       196);
                v327[v322].m_scale.m_quad = _mm_mul_ps(v325[v322].m_scale.m_quad, v381);
                poseInOut->m_boneFlags.m_data[v320] &= ~1u;
              }
              poseInOut->m_boneFlags.m_data[v320] |= 4u;
              poseInOut->m_modelInSync.m_bool = 0;
            }
          }
          ++v320;
          ++v322;
        }
        while ( v320 < v321 );
        v318 = v359;
        v319 = v429;
      }
      for ( k = v319; k < v321; ++k )
      {
        v344 = poseInOut->m_boneFlags.m_data;
        v345 = v344[k];
        if ( (v345 & 4) != 0 )
          v344[k] = v345 & 0xFFFFFFF9 | 2;
      }
      v346 = poseInOut->m_modelPose.m_data;
      v347 = v318;
      v346[v347].m_translation.m_quad = v392;
      v346[v347].m_rotation.m_vec.m_quad = v393;
      v346[v347].m_scale.m_quad = v394;
      poseInOut->m_boneFlags.m_data[v318] = 1;
      poseInOut->m_localInSync.m_bool = 0;
    }
    v348 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v349 = v348[1];
    v350 = v348;
    if ( v349 < v348[3] )
    {
      *(_QWORD *)v349 = "lt";
      v351 = __rdtsc();
      *(_DWORD *)(v349 + 8) = v351;
      v350[1] = v349 + 16;
    }
    v10 = result;
    result->m_bool = 1;
  }
  else
  {
    result->m_bool = 1;
    return result;
  }
  return v10;
}
  {
    result->m_bool = 1;
    return result;
  }
  return v10;
}

