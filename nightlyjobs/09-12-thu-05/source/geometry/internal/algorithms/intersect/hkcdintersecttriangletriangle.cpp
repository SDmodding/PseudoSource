// File Line: 63
// RVA: 0x130AED0
void __fastcall updateIntersection(hkVector4f *d0, hkVector4f *d1, hkVector4f *d2, hkVector4f *d3, hkVector4f *triA, hkVector4f *triB, hkVector4fComparison *cmpInOut)
{
  __m128 v7; // xmm0
  __m128 v8; // xmm2
  __m128 v9; // xmm4
  __m128 v10; // xmm1
  __m128 v11; // xmm13
  __m128 v12; // xmm3
  __m128 v13; // xmm6
  __m128 v14; // xmm13
  __m128 v15; // xmm2
  __m128 v16; // xmm0
  __m128 v17; // xmm3
  __m128 v18; // xmm4
  __m128 v19; // xmm1
  __m128 v20; // xmm2
  __m128 v21; // xmm4
  __m128 v22; // xmm6
  __m128 v23; // xmm5
  __m128 v24; // xmm0
  __m128 v25; // xmm3
  __m128 v26; // xmm2
  __m128 v27; // xmm4
  __m128 v28; // xmm1
  __m128 v29; // xmm5
  __m128 v30; // xmm8
  __m128 v31; // xmm13
  __m128 v32; // xmm7
  __m128 v33; // xmm4
  __m128 v34; // xmm3
  __m128 v35; // xmm1
  __m128 v36; // xmm5
  __m128 v37; // xmm2
  __m128 v38; // xmm7
  __m128 v39; // xmm0
  __m128 v40; // xmm6
  __m128 v41; // xmm1
  __m128 v42; // xmm3
  __m128 v43; // xmm4
  __m128 v44; // xmm5
  __m128 v45; // xmm2
  __m128 v46; // xmm6
  __m128 v47; // xmm0
  __m128 v48; // xmm12
  __m128 v49; // xmm10
  __m128 v50; // xmm11
  __m128 v51; // xmm9
  __m128 v52; // xmm2
  __m128 v53; // xmm1
  __m128 v54; // xmm12

  v7 = _mm_mul_ps(triA->m_quad, d1->m_quad);
  v8 = _mm_mul_ps(triA->m_quad, d2->m_quad);
  v9 = _mm_mul_ps(triA->m_quad, d3->m_quad);
  v10 = _mm_shuffle_ps(v8, v9, 68);
  v11 = _mm_mul_ps(triA->m_quad, d0->m_quad);
  v12 = _mm_shuffle_ps(v11, v7, 68);
  v13 = _mm_mul_ps(triA[1].m_quad, d0->m_quad);
  v14 = _mm_add_ps(
          _mm_shuffle_ps(_mm_shuffle_ps(v11, v7, 238), _mm_shuffle_ps(v8, v9, 238), 136),
          _mm_add_ps(_mm_shuffle_ps(v12, v10, 221), _mm_shuffle_ps(v12, v10, 136)));
  v15 = _mm_mul_ps(triA[1].m_quad, d2->m_quad);
  v16 = _mm_mul_ps(triA[1].m_quad, d1->m_quad);
  v17 = _mm_shuffle_ps(v13, v16, 68);
  v18 = _mm_mul_ps(triA[1].m_quad, d3->m_quad);
  v19 = _mm_shuffle_ps(v15, v18, 68);
  v20 = _mm_shuffle_ps(v15, v18, 238);
  v21 = triA[2].m_quad;
  v22 = _mm_add_ps(
          _mm_shuffle_ps(_mm_shuffle_ps(v13, v16, 238), v20, 136),
          _mm_add_ps(_mm_shuffle_ps(v17, v19, 221), _mm_shuffle_ps(v17, v19, 136)));
  v23 = _mm_mul_ps(v21, d0->m_quad);
  v24 = _mm_mul_ps(triA[2].m_quad, d1->m_quad);
  v25 = _mm_shuffle_ps(v23, v24, 68);
  v26 = _mm_mul_ps(triA[2].m_quad, d2->m_quad);
  v27 = _mm_mul_ps(v21, d3->m_quad);
  v28 = _mm_shuffle_ps(v26, v27, 68);
  v29 = _mm_add_ps(
          _mm_shuffle_ps(_mm_shuffle_ps(v23, v24, 238), _mm_shuffle_ps(v26, v27, 238), 136),
          _mm_add_ps(_mm_shuffle_ps(v25, v28, 221), _mm_shuffle_ps(v25, v28, 136)));
  v30 = _mm_min_ps(_mm_min_ps(v14, v22), v29);
  v31 = _mm_max_ps(_mm_max_ps(v14, v22), v29);
  v32 = _mm_mul_ps(d0->m_quad, triB->m_quad);
  v33 = _mm_mul_ps(d2->m_quad, triB->m_quad);
  v34 = _mm_mul_ps(d1->m_quad, triB->m_quad);
  v35 = _mm_mul_ps(d3->m_quad, triB->m_quad);
  v36 = _mm_shuffle_ps(v32, v34, 68);
  v37 = _mm_shuffle_ps(v33, v35, 68);
  v38 = _mm_add_ps(
          _mm_shuffle_ps(_mm_shuffle_ps(v32, v34, 238), _mm_shuffle_ps(v33, v35, 238), 136),
          _mm_add_ps(_mm_shuffle_ps(v36, v37, 221), _mm_shuffle_ps(v36, v37, 136)));
  v39 = triB[1].m_quad;
  v40 = _mm_mul_ps(d0->m_quad, v39);
  v41 = _mm_mul_ps(d3->m_quad, v39);
  v42 = _mm_mul_ps(d1->m_quad, v39);
  v43 = _mm_mul_ps(d2->m_quad, v39);
  v44 = _mm_shuffle_ps(v40, v42, 68);
  v45 = _mm_shuffle_ps(v43, v41, 68);
  v46 = _mm_add_ps(
          _mm_shuffle_ps(_mm_shuffle_ps(v40, v42, 238), _mm_shuffle_ps(v43, v41, 238), 136),
          _mm_add_ps(_mm_shuffle_ps(v44, v45, 221), _mm_shuffle_ps(v44, v45, 136)));
  v47 = triB[2].m_quad;
  v48 = _mm_mul_ps(d0->m_quad, v47);
  v49 = _mm_mul_ps(d1->m_quad, v47);
  v50 = _mm_mul_ps(d2->m_quad, v47);
  v51 = _mm_mul_ps(d3->m_quad, v47);
  v52 = _mm_shuffle_ps(v48, v49, 68);
  v53 = _mm_shuffle_ps(v50, v51, 68);
  v54 = _mm_add_ps(
          _mm_shuffle_ps(_mm_shuffle_ps(v48, v49, 238), _mm_shuffle_ps(v50, v51, 238), 136),
          _mm_add_ps(_mm_shuffle_ps(v52, v53, 221), _mm_shuffle_ps(v52, v53, 136)));
  cmpInOut->m_mask = _mm_and_ps(
                       _mm_and_ps(
                         _mm_cmpleps(v30, _mm_max_ps(_mm_max_ps(v38, v46), v54)),
                         _mm_cmpleps(_mm_min_ps(_mm_min_ps(v38, v46), v54), v31)),
                       cmpInOut->m_mask);
}

// File Line: 74
// RVA: 0x130A210
_BOOL8 __fastcall hkcdIntersectTriangleTriangle(hkVector4f (*triangleA)[3], hkVector4f (*triangleB)[3])
{
  __m128 v2; // xmm1
  __m128 v3; // xmm6
  __m128 v4; // xmm2
  __m128 v5; // xmm11
  __m128 v6; // xmm10
  __m128 v7; // xmm1
  __m128 v8; // xmm15
  __m128 v9; // ST40_16
  __m128 v10; // xmm13
  __m128 v11; // STD0_16
  __m128 v12; // xmm14
  __m128 v13; // ST50_16
  __m128 v14; // xmm12
  __m128 v15; // xmm9
  __m128 v16; // xmm15
  __m128 v17; // ST10_16
  __m128 v18; // ST20_16
  __m128 v19; // ST30_16
  __m128 v20; // xmm8
  __m128 v21; // xmm7
  __m128 v22; // xmm3
  __m128 v23; // ST00_16
  __m128 v24; // xmm10
  __m128 v25; // xmm2
  __m128 v26; // xmm0
  __m128 v27; // xmm1
  __m128 v28; // xmm4
  __m128 v29; // xmm6
  __m128 v30; // xmm5
  __m128 v31; // xmm0
  __m128 v32; // xmm2
  __m128 v33; // xmm0
  __m128 v34; // ST00_16
  __m128 v35; // xmm2
  __m128 v36; // xmm3
  __m128 v37; // xmm1
  __m128 v38; // xmm4
  __m128 v39; // xmm6
  __m128 v40; // xmm0
  __m128 v41; // xmm5
  __m128 v42; // xmm0
  __m128 v43; // xmm5
  __m128 v44; // xmm2
  __m128 v45; // xmm3
  __m128 v46; // xmm1
  __m128 v47; // xmm4
  __m128 v48; // xmm5
  __m128 v49; // ST90_16
  __m128 v50; // ST00_16
  __m128 v51; // xmm0
  __m128 v52; // xmm5
  __m128 v53; // xmm2
  __m128 v54; // xmm3
  __m128 v55; // xmm1
  __m128 v56; // xmm4
  __m128 v57; // xmm5
  __m128 v58; // xmm0
  __m128 v59; // ST60_16
  __m128 v60; // xmm6
  __m128 v61; // xmm2
  __m128 v62; // xmm0
  __m128 v63; // xmm4
  __m128 v64; // xmm3
  __m128 v65; // xmm1
  __m128 v66; // xmm6
  __m128 v67; // xmm0
  __m128 v68; // xmm5
  __m128 v69; // xmm0
  __m128 v70; // xmm5
  __m128 v71; // xmm2
  __m128 v72; // xmm3
  __m128 v73; // xmm1
  __m128 v74; // xmm4
  __m128 v75; // xmm5
  __m128 v76; // xmm7
  __m128 v77; // ST70_16
  __m128 v78; // ST60_16
  __m128 v79; // xmm1
  __m128 v80; // xmm11
  __m128 v81; // xmm10
  __m128 v82; // xmm9
  __m128 v83; // xmm0
  __m128 v84; // xmm11
  __m128 v85; // xmm2
  __m128 v86; // xmm8
  __m128 v87; // xmm0
  __m128 v88; // xmm3
  __m128 v89; // xmm4
  __m128 v90; // xmm1
  __m128 v91; // xmm11
  __m128 v92; // xmm0
  __m128 v93; // xmm6
  __m128 v94; // xmm0
  __m128 v95; // xmm3
  __m128 v96; // xmm2
  __m128 v97; // xmm6
  __m128 v98; // xmm1
  __m128 v99; // xmm4
  __m128 v100; // xmm6
  __m128 v101; // xmm0
  __m128 v102; // xmm5
  __m128 v103; // xmm0
  __m128 v104; // xmm3
  __m128 v105; // xmm2
  __m128 v106; // xmm5
  __m128 v107; // xmm1
  __m128 v108; // xmm4
  __m128 v109; // xmm5
  __m128 v110; // STB0_16
  __m128 v111; // STC0_16
  __m128 v112; // xmm0
  __m128 v113; // xmm11
  __m128 v114; // xmm2
  __m128 v115; // xmm3
  __m128 v116; // xmm1
  __m128 v117; // xmm4
  __m128 v118; // xmm11
  __m128 v119; // xmm0
  __m128 v120; // xmm6
  __m128 v121; // xmm0
  __m128 v122; // xmm6
  __m128 v123; // xmm2
  __m128 v124; // xmm3
  __m128 v125; // xmm4
  __m128 v126; // xmm1
  __m128 v127; // xmm6
  __m128 v128; // xmm0
  __m128 v129; // xmm13
  __m128 v130; // xmm5
  __m128 v131; // xmm0
  __m128 v132; // xmm3
  __m128 v133; // xmm5
  __m128 v134; // xmm1
  __m128 v135; // xmm2
  __m128 v136; // xmm4
  __m128 v137; // xmm9
  __m128 v138; // xmm14
  __m128 v139; // xmm5
  __m128 v140; // xmm0
  __m128 v141; // xmm11
  __m128 v142; // xmm6
  __m128 v143; // STA0_16
  __m128 v144; // ST80_16
  __m128 v145; // xmm0
  __m128 v146; // xmm12
  __m128 v147; // xmm11
  __m128 v148; // xmm8
  __m128 v149; // xmm7
  __m128 v150; // xmm10
  __m128 v151; // xmm2
  __m128 v152; // xmm0
  __m128 v153; // xmm3
  __m128 v154; // xmm4
  __m128 v155; // xmm1
  __m128 v156; // xmm10
  __m128 v157; // xmm2
  __m128 v158; // xmm3
  __m128 v159; // xmm15
  __m128 v160; // xmm0
  __m128 v161; // xmm1
  __m128 v162; // xmm4
  __m128 v163; // xmm5
  __m128 v164; // xmm6
  __m128 v165; // xmm3
  __m128 v166; // xmm2
  __m128 v167; // xmm0
  __m128 v168; // xmm4
  __m128 v169; // xmm1
  __m128 v170; // xmm5
  __m128 v171; // ST30_16
  __m128 v172; // STE0_16
  __m128 v173; // xmm0
  __m128 v174; // xmm3
  __m128 v175; // xmm10
  __m128 v176; // xmm2
  __m128 v177; // xmm1
  __m128 v178; // xmm4
  __m128 v179; // xmm10
  __m128 v180; // xmm0
  __m128 v181; // xmm6
  __m128 v182; // xmm0
  __m128 v183; // xmm6
  __m128 v184; // xmm2
  __m128 v185; // xmm3
  __m128 v186; // xmm1
  __m128 v187; // xmm4
  __m128 v188; // xmm6
  __m128 v189; // xmm0
  __m128 v190; // xmm5
  __m128 v191; // xmm0
  __m128 v192; // xmm2
  __m128 v193; // xmm3
  __m128 v194; // xmm7
  __m128 v195; // xmm1
  __m128 v196; // xmm11
  __m128 v197; // xmm8
  __m128 v198; // xmm5
  __m128 v199; // xmm11
  __m128 v200; // xmm9
  __m128 v201; // xmm4
  __m128 v202; // xmm5
  __m128 v203; // xmm3
  __m128 v204; // xmm2
  __m128 v205; // xmm0
  __m128 v206; // xmm10
  __m128 v207; // xmm6
  __m128 v208; // ST10_16
  __m128 v209; // ST20_16
  __m128 v210; // xmm10
  __m128 v211; // xmm5
  __m128 v212; // xmm0
  __m128 v213; // xmm4
  __m128 v214; // xmm10
  __m128 v215; // xmm1
  __m128 v216; // xmm2
  __m128 v217; // xmm10
  __m128 v218; // xmm3
  __m128 v219; // xmm4
  __m128 v220; // xmm0
  __m128 v221; // xmm1
  __m128 v222; // xmm6
  __m128 v223; // xmm3
  __m128 v224; // xmm2
  __m128 v225; // xmm0
  __m128 v226; // xmm4
  __m128 v227; // xmm5
  __m128 v228; // xmm1
  __m128 v229; // xmm2
  __m128 v230; // xmm5
  __m128 v231; // xmm3
  __m128 v232; // xmm14
  __m128 v233; // xmm15
  __m128 v234; // ST40_16
  __m128 v235; // xmm0
  __m128 v236; // xmm4
  __m128 v237; // xmm10
  __m128 v238; // xmm1
  __m128 v239; // xmm5
  __m128 v240; // xmm14
  __m128 v241; // xmm0
  __m128 v242; // xmm6
  __m128 v243; // xmm0
  __m128 v244; // xmm3
  __m128 v245; // xmm6
  __m128 v246; // xmm2
  __m128 v247; // xmm1
  __m128 v248; // xmm4
  __m128 v249; // xmm6
  __m128 v250; // xmm2
  __m128 v251; // xmm6
  __m128 v252; // xmm0
  __m128 v253; // xmm3
  __m128 v254; // xmm4
  __m128 v255; // xmm1
  __m128 v256; // xmm7
  __m128 v257; // xmm13
  __m128 v258; // xmm11
  __m128 v259; // xmm5
  __m128 v260; // xmm9
  __m128 v261; // xmm0
  __m128 v262; // xmm4
  __m128 v263; // xmm14
  __m128 v264; // xmm8
  __m128 v265; // xmm13
  __m128 v266; // xmm10
  __m128 v267; // xmm12
  __m128 v268; // xmm5
  __m128 v269; // xmm3
  __m128 v270; // xmm2
  __m128 v271; // xmm1
  __m128 v272; // xmm12
  __m128 v273; // xmm2
  __m128 v274; // xmm4
  __m128 v275; // xmm0
  __m128 v276; // xmm6
  __m128 v277; // xmm3
  __m128 v278; // xmm1
  __m128 v279; // xmm5
  __m128 v280; // xmm2
  __m128 v281; // xmm5
  __m128 v282; // xmm0
  __m128 v283; // xmm7
  __m128 v284; // xmm1
  __m128 v285; // xmm3
  __m128 v286; // xmm4
  __m128 v287; // xmm7
  __m128 v288; // xmm12
  __m128 v289; // xmm4
  __m128 v290; // xmm0
  __m128 v291; // xmm2
  __m128 v292; // xmm6
  __m128 v293; // xmm3
  __m128 v294; // xmm1
  __m128 v295; // xmm6
  __m128 v296; // xmm4
  __m128 v297; // xmm5
  __m128 v298; // xmm2
  __m128 v299; // xmm6
  __m128 v300; // xmm0
  __m128 v301; // xmm4
  __m128 v302; // xmm5
  __m128 v303; // xmm3
  __m128 v304; // xmm1
  __m128 v305; // xmm2
  __m128 v306; // xmm4
  __m128 v307; // xmm5
  __m128 v308; // xmm2
  __m128 v309; // xmm0
  __m128 v310; // xmm3
  __m128 v311; // xmm8
  __m128 v312; // xmm1
  __m128 v313; // xmm4

  v2 = _mm_sub_ps((*triangleB)[1].m_quad, (*triangleB)[0].m_quad);
  v3 = (*triangleA)[1].m_quad;
  v4 = _mm_sub_ps((*triangleA)[2].m_quad, v3);
  v5 = _mm_sub_ps((*triangleB)[2].m_quad, (*triangleB)[1].m_quad);
  v6 = _mm_shuffle_ps(v2, v2, 210);
  v7 = _mm_shuffle_ps(v2, v2, 201);
  v8 = _mm_sub_ps((*triangleB)[0].m_quad, (*triangleB)[2].m_quad);
  v9 = _mm_sub_ps((*triangleA)[0].m_quad, (*triangleA)[2].m_quad);
  v10 = _mm_shuffle_ps(v9, v9, 210);
  v11 = _mm_sub_ps((*triangleA)[1].m_quad, (*triangleA)[0].m_quad);
  v12 = _mm_shuffle_ps(v11, v11, 210);
  v13 = _mm_shuffle_ps(v11, v11, 201);
  v14 = _mm_shuffle_ps(v8, v8, 201);
  v15 = _mm_sub_ps(_mm_mul_ps(v6, v13), _mm_mul_ps(v12, v7));
  v16 = _mm_shuffle_ps(v8, v8, 210);
  v17 = _mm_shuffle_ps(v4, v4, 210);
  v18 = _mm_shuffle_ps(v4, v4, 201);
  v19 = _mm_shuffle_ps(v9, v9, 201);
  v20 = _mm_sub_ps(_mm_mul_ps(v6, v18), _mm_mul_ps(v17, v7));
  v21 = _mm_sub_ps(_mm_mul_ps(v6, v19), _mm_mul_ps(v10, v7));
  v22 = _mm_mul_ps((*triangleA)[0].m_quad, v21);
  v23 = _mm_mul_ps((*triangleA)[0].m_quad, v15);
  v24 = _mm_sub_ps(_mm_mul_ps(v6, v14), _mm_mul_ps(v16, v7));
  v25 = _mm_mul_ps((*triangleA)[0].m_quad, v20);
  v26 = _mm_mul_ps((*triangleA)[0].m_quad, v24);
  v27 = _mm_shuffle_ps(v22, v26, 68);
  v28 = _mm_shuffle_ps(v23, v25, 68);
  v29 = _mm_mul_ps(v3, v15);
  v30 = _mm_add_ps(
          _mm_shuffle_ps(_mm_shuffle_ps(v23, v25, 238), _mm_shuffle_ps(v22, v26, 238), 136),
          _mm_add_ps(_mm_shuffle_ps(v28, v27, 221), _mm_shuffle_ps(v28, v27, 136)));
  v31 = (*triangleA)[1].m_quad;
  v32 = v31;
  v33 = _mm_mul_ps(v31, v24);
  v34 = v30;
  v35 = _mm_mul_ps(v32, v20);
  v36 = _mm_mul_ps((*triangleA)[1].m_quad, v21);
  v37 = _mm_shuffle_ps(v36, v33, 68);
  v38 = _mm_shuffle_ps(v29, v35, 68);
  v39 = _mm_add_ps(
          _mm_shuffle_ps(_mm_shuffle_ps(v29, v35, 238), _mm_shuffle_ps(v36, v33, 238), 136),
          _mm_add_ps(_mm_shuffle_ps(v38, v37, 221), _mm_shuffle_ps(v38, v37, 136)));
  v40 = (*triangleA)[2].m_quad;
  v41 = v40;
  v42 = _mm_mul_ps(v40, v24);
  v43 = _mm_mul_ps(v41, v15);
  v44 = _mm_mul_ps((*triangleA)[2].m_quad, v20);
  v45 = _mm_mul_ps((*triangleA)[2].m_quad, v21);
  v46 = _mm_shuffle_ps(v45, v42, 68);
  v47 = _mm_shuffle_ps(v43, v44, 68);
  v48 = _mm_add_ps(
          _mm_shuffle_ps(_mm_shuffle_ps(v43, v44, 238), _mm_shuffle_ps(v45, v42, 238), 136),
          _mm_add_ps(_mm_shuffle_ps(v47, v46, 221), _mm_shuffle_ps(v47, v46, 136)));
  v49 = _mm_min_ps(_mm_min_ps(v34, v39), v48);
  v50 = _mm_max_ps(_mm_max_ps(v34, v39), v48);
  v51 = _mm_mul_ps((*triangleB)[0].m_quad, v24);
  v52 = _mm_mul_ps((*triangleB)[0].m_quad, v15);
  v53 = _mm_mul_ps((*triangleB)[0].m_quad, v20);
  v54 = _mm_mul_ps((*triangleB)[0].m_quad, v21);
  v55 = _mm_shuffle_ps(v54, v51, 68);
  v56 = _mm_shuffle_ps(v52, v53, 68);
  v57 = _mm_add_ps(
          _mm_shuffle_ps(_mm_shuffle_ps(v52, v53, 238), _mm_shuffle_ps(v54, v51, 238), 136),
          _mm_add_ps(_mm_shuffle_ps(v56, v55, 221), _mm_shuffle_ps(v56, v55, 136)));
  v58 = (*triangleB)[1].m_quad;
  v59 = v57;
  v60 = _mm_mul_ps(v58, v15);
  v61 = _mm_mul_ps((*triangleB)[1].m_quad, v20);
  v62 = _mm_mul_ps(v58, v24);
  v63 = _mm_shuffle_ps(v60, v61, 68);
  v64 = _mm_mul_ps((*triangleB)[1].m_quad, v21);
  v65 = _mm_shuffle_ps(v64, v62, 68);
  v66 = _mm_add_ps(
          _mm_shuffle_ps(_mm_shuffle_ps(v60, v61, 238), _mm_shuffle_ps(v64, v62, 238), 136),
          _mm_add_ps(_mm_shuffle_ps(v63, v65, 221), _mm_shuffle_ps(v63, v65, 136)));
  v67 = (*triangleB)[2].m_quad;
  v68 = v67;
  v69 = _mm_mul_ps(v67, v24);
  v70 = _mm_mul_ps(v68, v15);
  v71 = _mm_mul_ps((*triangleB)[2].m_quad, v20);
  v72 = _mm_mul_ps((*triangleB)[2].m_quad, v21);
  v73 = _mm_shuffle_ps(v72, v69, 68);
  v74 = _mm_shuffle_ps(v70, v71, 68);
  v75 = _mm_add_ps(
          _mm_shuffle_ps(_mm_shuffle_ps(v70, v71, 238), _mm_shuffle_ps(v72, v69, 238), 136),
          _mm_add_ps(_mm_shuffle_ps(v74, v73, 221), _mm_shuffle_ps(v74, v73, 136)));
  v76 = _mm_sub_ps((*triangleA)[0].m_quad, (*triangleB)[0].m_quad);
  v77 = _mm_min_ps(_mm_min_ps(v59, v66), v75);
  v78 = _mm_max_ps(_mm_max_ps(v59, v66), v75);
  v79 = _mm_shuffle_ps(v5, v5, 210);
  v80 = _mm_shuffle_ps(v5, v5, 201);
  v81 = _mm_sub_ps(_mm_mul_ps(v13, v79), _mm_mul_ps(v12, v80));
  v82 = _mm_sub_ps(_mm_mul_ps(v18, v79), _mm_mul_ps(v17, v80));
  v83 = _mm_mul_ps(v10, v80);
  v84 = _mm_mul_ps((*triangleA)[0].m_quad, v81);
  v85 = _mm_mul_ps((*triangleA)[0].m_quad, v82);
  v86 = _mm_sub_ps(_mm_mul_ps(v19, v79), v83);
  v87 = _mm_mul_ps((*triangleA)[0].m_quad, v76);
  v88 = _mm_mul_ps((*triangleA)[0].m_quad, v86);
  v89 = _mm_shuffle_ps(v84, v85, 68);
  v90 = _mm_shuffle_ps(v88, v87, 68);
  v91 = _mm_add_ps(
          _mm_shuffle_ps(_mm_shuffle_ps(v84, v85, 238), _mm_shuffle_ps(v88, v87, 238), 136),
          _mm_add_ps(_mm_shuffle_ps(v89, v90, 221), _mm_shuffle_ps(v89, v90, 136)));
  v92 = (*triangleA)[1].m_quad;
  v93 = v92;
  v94 = _mm_mul_ps(v92, v76);
  v95 = _mm_mul_ps((*triangleA)[1].m_quad, v86);
  v96 = _mm_mul_ps((*triangleA)[1].m_quad, v82);
  v97 = _mm_mul_ps(v93, v81);
  v98 = _mm_shuffle_ps(v95, v94, 68);
  v99 = _mm_shuffle_ps(v97, v96, 68);
  v100 = _mm_add_ps(
           _mm_shuffle_ps(_mm_shuffle_ps(v97, v96, 238), _mm_shuffle_ps(v95, v94, 238), 136),
           _mm_add_ps(_mm_shuffle_ps(v99, v98, 221), _mm_shuffle_ps(v99, v98, 136)));
  v101 = (*triangleA)[2].m_quad;
  v102 = v101;
  v103 = _mm_mul_ps(v101, v76);
  v104 = _mm_mul_ps((*triangleA)[2].m_quad, v86);
  v105 = _mm_mul_ps((*triangleA)[2].m_quad, v82);
  v106 = _mm_mul_ps(v102, v81);
  v107 = _mm_shuffle_ps(v104, v103, 68);
  v108 = _mm_shuffle_ps(v106, v105, 68);
  v109 = _mm_add_ps(
           _mm_shuffle_ps(_mm_shuffle_ps(v106, v105, 238), _mm_shuffle_ps(v104, v103, 238), 136),
           _mm_add_ps(_mm_shuffle_ps(v108, v107, 221), _mm_shuffle_ps(v108, v107, 136)));
  v110 = _mm_min_ps(_mm_min_ps(v91, v100), v109);
  v111 = _mm_max_ps(_mm_max_ps(v91, v100), v109);
  v112 = _mm_mul_ps((*triangleB)[0].m_quad, v76);
  v113 = _mm_mul_ps((*triangleB)[0].m_quad, v81);
  v114 = _mm_mul_ps((*triangleB)[0].m_quad, v82);
  v115 = _mm_mul_ps((*triangleB)[0].m_quad, v86);
  v116 = _mm_shuffle_ps(v115, v112, 68);
  v117 = _mm_shuffle_ps(v113, v114, 68);
  v118 = _mm_add_ps(
           _mm_shuffle_ps(_mm_shuffle_ps(v113, v114, 238), _mm_shuffle_ps(v115, v112, 238), 136),
           _mm_add_ps(_mm_shuffle_ps(v117, v116, 221), _mm_shuffle_ps(v117, v116, 136)));
  v119 = (*triangleB)[1].m_quad;
  v120 = v119;
  v121 = _mm_mul_ps(v119, v76);
  v122 = _mm_mul_ps(v120, v81);
  v123 = _mm_mul_ps((*triangleB)[1].m_quad, v82);
  v124 = _mm_mul_ps((*triangleB)[1].m_quad, v86);
  v125 = _mm_shuffle_ps(v122, v123, 68);
  v126 = _mm_shuffle_ps(v124, v121, 68);
  v127 = _mm_add_ps(
           _mm_shuffle_ps(_mm_shuffle_ps(v122, v123, 238), _mm_shuffle_ps(v124, v121, 238), 136),
           _mm_add_ps(_mm_shuffle_ps(v125, v126, 221), _mm_shuffle_ps(v125, v126, 136)));
  v128 = (*triangleB)[2].m_quad;
  v129 = _mm_mul_ps(v10, v14);
  v130 = v128;
  v131 = _mm_mul_ps(v128, v76);
  v132 = _mm_mul_ps((*triangleB)[2].m_quad, v86);
  v133 = _mm_mul_ps(v130, v81);
  v134 = _mm_shuffle_ps(v132, v131, 68);
  v135 = _mm_mul_ps((*triangleB)[2].m_quad, v82);
  v136 = _mm_shuffle_ps(v133, v135, 68);
  v137 = _mm_sub_ps(_mm_mul_ps(v13, v16), _mm_mul_ps(v12, v14));
  v138 = (*triangleA)[1].m_quad;
  v139 = _mm_add_ps(
           _mm_shuffle_ps(_mm_shuffle_ps(v133, v135, 238), _mm_shuffle_ps(v132, v131, 238), 136),
           _mm_add_ps(_mm_shuffle_ps(v136, v134, 221), _mm_shuffle_ps(v136, v134, 136)));
  v140 = _mm_min_ps(v118, v127);
  v141 = _mm_max_ps(v118, v127);
  v142 = _mm_mul_ps((*triangleA)[1].m_quad, v137);
  v143 = _mm_min_ps(v140, v139);
  v144 = _mm_max_ps(v141, v139);
  v145 = _mm_mul_ps(v17, v14);
  v146 = v19;
  v147 = _mm_sub_ps(_mm_mul_ps(v18, v16), v145);
  v148 = _mm_sub_ps(_mm_mul_ps(v19, v16), v129);
  v149 = _mm_sub_ps((*triangleA)[0].m_quad, (*triangleB)[1].m_quad);
  v150 = _mm_mul_ps((*triangleA)[0].m_quad, v137);
  v151 = _mm_mul_ps((*triangleA)[0].m_quad, v147);
  v152 = _mm_mul_ps((*triangleA)[0].m_quad, v149);
  v153 = _mm_mul_ps((*triangleA)[0].m_quad, v148);
  v154 = _mm_shuffle_ps(v150, v151, 68);
  v155 = _mm_shuffle_ps(v153, v152, 68);
  v156 = _mm_add_ps(
           _mm_shuffle_ps(_mm_shuffle_ps(v150, v151, 238), _mm_shuffle_ps(v153, v152, 238), 136),
           _mm_add_ps(_mm_shuffle_ps(v154, v155, 221), _mm_shuffle_ps(v154, v155, 136)));
  v157 = _mm_mul_ps(v138, v147);
  v158 = _mm_mul_ps(v138, v148);
  v159 = (*triangleA)[2].m_quad;
  v160 = _mm_mul_ps(v138, v149);
  v161 = _mm_shuffle_ps(v158, v160, 68);
  v162 = _mm_shuffle_ps(v142, v157, 68);
  v163 = _mm_mul_ps((*triangleA)[2].m_quad, v137);
  v164 = _mm_add_ps(
           _mm_shuffle_ps(_mm_shuffle_ps(v142, v157, 238), _mm_shuffle_ps(v158, v160, 238), 136),
           _mm_add_ps(_mm_shuffle_ps(v162, v161, 221), _mm_shuffle_ps(v162, v161, 136)));
  v165 = _mm_mul_ps((*triangleA)[2].m_quad, v148);
  v166 = _mm_mul_ps(v159, v147);
  v167 = _mm_mul_ps((*triangleA)[2].m_quad, v149);
  v168 = _mm_shuffle_ps(v163, v166, 68);
  v169 = _mm_shuffle_ps(v165, v167, 68);
  v170 = _mm_add_ps(
           _mm_shuffle_ps(_mm_shuffle_ps(v163, v166, 238), _mm_shuffle_ps(v165, v167, 238), 136),
           _mm_add_ps(_mm_shuffle_ps(v168, v169, 221), _mm_shuffle_ps(v168, v169, 136)));
  v171 = _mm_min_ps(_mm_min_ps(v156, v164), v170);
  v172 = _mm_max_ps(_mm_max_ps(v156, v164), v170);
  v173 = _mm_mul_ps((*triangleB)[0].m_quad, v149);
  v174 = _mm_mul_ps((*triangleB)[0].m_quad, v148);
  v175 = _mm_mul_ps((*triangleB)[0].m_quad, v137);
  v176 = _mm_mul_ps((*triangleB)[0].m_quad, v147);
  v177 = _mm_shuffle_ps(v174, v173, 68);
  v178 = _mm_shuffle_ps(v175, v176, 68);
  v179 = _mm_add_ps(
           _mm_shuffle_ps(_mm_shuffle_ps(v175, v176, 238), _mm_shuffle_ps(v174, v173, 238), 136),
           _mm_add_ps(_mm_shuffle_ps(v178, v177, 221), _mm_shuffle_ps(v178, v177, 136)));
  v180 = (*triangleB)[1].m_quad;
  v181 = v180;
  v182 = _mm_mul_ps(v180, v149);
  v183 = _mm_mul_ps(v181, v137);
  v184 = _mm_mul_ps((*triangleB)[1].m_quad, v147);
  v185 = _mm_mul_ps((*triangleB)[1].m_quad, v148);
  v186 = _mm_shuffle_ps(v185, v182, 68);
  v187 = _mm_shuffle_ps(v183, v184, 68);
  v188 = _mm_add_ps(
           _mm_shuffle_ps(_mm_shuffle_ps(v183, v184, 238), _mm_shuffle_ps(v185, v182, 238), 136),
           _mm_add_ps(_mm_shuffle_ps(v187, v186, 221), _mm_shuffle_ps(v187, v186, 136)));
  v189 = (*triangleB)[2].m_quad;
  v190 = v189;
  v191 = _mm_mul_ps(v189, v149);
  v192 = _mm_mul_ps((*triangleB)[2].m_quad, v147);
  v193 = _mm_mul_ps((*triangleB)[2].m_quad, v148);
  v194 = _mm_sub_ps((*triangleA)[0].m_quad, (*triangleB)[2].m_quad);
  v195 = _mm_shuffle_ps(v193, v191, 68);
  v196 = _mm_sub_ps(_mm_mul_ps(v13, v9), _mm_mul_ps(v146, v11));
  v197 = _mm_sub_ps(v138, (*triangleB)[0].m_quad);
  v198 = _mm_mul_ps(v190, v137);
  v199 = _mm_shuffle_ps(v196, v196, 201);
  v200 = _mm_sub_ps(v138, (*triangleB)[1].m_quad);
  v201 = _mm_shuffle_ps(v198, v192, 68);
  v202 = _mm_add_ps(
           _mm_shuffle_ps(_mm_shuffle_ps(v198, v192, 238), _mm_shuffle_ps(v193, v191, 238), 136),
           _mm_add_ps(_mm_shuffle_ps(v201, v195, 221), _mm_shuffle_ps(v201, v195, 136)));
  v203 = _mm_mul_ps((*triangleA)[0].m_quad, v197);
  v204 = _mm_mul_ps((*triangleA)[0].m_quad, v194);
  v205 = _mm_min_ps(v179, v188);
  v206 = _mm_max_ps(_mm_max_ps(v179, v188), v202);
  v207 = _mm_mul_ps(v138, v199);
  v208 = _mm_min_ps(v205, v202);
  v209 = v206;
  v210 = _mm_mul_ps((*triangleA)[0].m_quad, v199);
  v211 = _mm_mul_ps(v159, v199);
  v212 = _mm_mul_ps((*triangleA)[0].m_quad, v200);
  v213 = _mm_shuffle_ps(v210, v204, 68);
  v214 = _mm_shuffle_ps(v210, v204, 238);
  v215 = _mm_shuffle_ps(v203, v212, 68);
  v216 = _mm_mul_ps(v138, v194);
  v217 = _mm_add_ps(
           _mm_shuffle_ps(v214, _mm_shuffle_ps(v203, v212, 238), 136),
           _mm_add_ps(_mm_shuffle_ps(v213, v215, 221), _mm_shuffle_ps(v213, v215, 136)));
  v218 = _mm_mul_ps(v138, v197);
  v219 = _mm_shuffle_ps(v207, v216, 68);
  v220 = _mm_mul_ps(v138, v200);
  v221 = _mm_shuffle_ps(v218, v220, 68);
  v222 = _mm_add_ps(
           _mm_shuffle_ps(_mm_shuffle_ps(v207, v216, 238), _mm_shuffle_ps(v218, v220, 238), 136),
           _mm_add_ps(_mm_shuffle_ps(v219, v221, 221), _mm_shuffle_ps(v219, v221, 136)));
  v223 = _mm_mul_ps(v159, v197);
  v224 = _mm_mul_ps(v159, v194);
  v225 = _mm_mul_ps((*triangleA)[2].m_quad, v200);
  v226 = _mm_shuffle_ps(v211, v224, 68);
  v227 = _mm_shuffle_ps(v211, v224, 238);
  v228 = _mm_shuffle_ps(v223, v225, 68);
  v229 = _mm_mul_ps((*triangleB)[0].m_quad, v194);
  v230 = _mm_add_ps(
           _mm_shuffle_ps(v227, _mm_shuffle_ps(v223, v225, 238), 136),
           _mm_add_ps(_mm_shuffle_ps(v226, v228, 221), _mm_shuffle_ps(v226, v228, 136)));
  v231 = _mm_mul_ps((*triangleB)[0].m_quad, v197);
  v232 = _mm_mul_ps((*triangleB)[0].m_quad, v199);
  v233 = _mm_min_ps(_mm_min_ps(v217, v222), v230);
  v234 = _mm_max_ps(_mm_max_ps(v217, v222), v230);
  v235 = _mm_mul_ps((*triangleB)[0].m_quad, v200);
  v236 = _mm_shuffle_ps(v232, v229, 68);
  v237 = (*triangleB)[2].m_quad;
  v238 = _mm_shuffle_ps(v231, v235, 68);
  v239 = _mm_mul_ps((*triangleB)[2].m_quad, v199);
  v240 = _mm_add_ps(
           _mm_shuffle_ps(_mm_shuffle_ps(v232, v229, 238), _mm_shuffle_ps(v231, v235, 238), 136),
           _mm_add_ps(_mm_shuffle_ps(v236, v238, 221), _mm_shuffle_ps(v236, v238, 136)));
  v241 = (*triangleB)[1].m_quad;
  v242 = v241;
  v243 = _mm_mul_ps(v241, v200);
  v244 = _mm_mul_ps((*triangleB)[1].m_quad, v197);
  v245 = _mm_mul_ps(v242, v199);
  v246 = _mm_mul_ps((*triangleB)[1].m_quad, v194);
  v247 = _mm_shuffle_ps(v244, v243, 68);
  v248 = _mm_shuffle_ps(v245, v246, 68);
  v249 = _mm_shuffle_ps(_mm_shuffle_ps(v245, v246, 238), _mm_shuffle_ps(v244, v243, 238), 136);
  v250 = _mm_mul_ps((*triangleB)[2].m_quad, v194);
  v251 = _mm_add_ps(v249, _mm_add_ps(_mm_shuffle_ps(v248, v247, 221), _mm_shuffle_ps(v248, v247, 136)));
  v252 = _mm_mul_ps((*triangleB)[2].m_quad, v200);
  v253 = _mm_mul_ps(v237, v197);
  v254 = _mm_shuffle_ps(v239, v250, 68);
  v255 = _mm_shuffle_ps(v253, v252, 68);
  v256 = (*triangleA)[2].m_quad;
  v257 = v240;
  v258 = _mm_sub_ps((*triangleA)[2].m_quad, (*triangleB)[2].m_quad);
  v259 = _mm_add_ps(
           _mm_shuffle_ps(_mm_shuffle_ps(v239, v250, 238), _mm_shuffle_ps(v253, v252, 238), 136),
           _mm_add_ps(_mm_shuffle_ps(v254, v255, 221), _mm_shuffle_ps(v254, v255, 136)));
  v260 = _mm_sub_ps(v256, (*triangleB)[0].m_quad);
  v261 = _mm_mul_ps((*triangleA)[0].m_quad, v260);
  v262 = _mm_mul_ps((*triangleA)[0].m_quad, v258);
  v263 = _mm_max_ps(_mm_max_ps(v240, v251), v259);
  v264 = _mm_sub_ps((*triangleA)[1].m_quad, v237);
  v265 = _mm_min_ps(_mm_min_ps(v257, v251), v259);
  v266 = _mm_sub_ps((*triangleA)[2].m_quad, (*triangleB)[1].m_quad);
  v267 = _mm_mul_ps((*triangleA)[0].m_quad, v264);
  v268 = _mm_mul_ps((*triangleA)[1].m_quad, v264);
  v269 = _mm_shuffle_ps(v267, v261, 68);
  v270 = _mm_mul_ps((*triangleA)[0].m_quad, v266);
  v271 = _mm_shuffle_ps(v270, v262, 68);
  v272 = _mm_add_ps(
           _mm_shuffle_ps(_mm_shuffle_ps(v267, v261, 238), _mm_shuffle_ps(v270, v262, 238), 136),
           _mm_add_ps(_mm_shuffle_ps(v269, v271, 221), _mm_shuffle_ps(v269, v271, 136)));
  v273 = _mm_mul_ps((*triangleA)[1].m_quad, v266);
  v274 = _mm_mul_ps((*triangleA)[2].m_quad, v264);
  v275 = _mm_mul_ps((*triangleA)[1].m_quad, v260);
  v276 = _mm_mul_ps((*triangleA)[1].m_quad, v258);
  v277 = _mm_shuffle_ps(v268, v275, 68);
  v278 = _mm_shuffle_ps(v273, v276, 68);
  v279 = _mm_shuffle_ps(_mm_shuffle_ps(v268, v275, 238), _mm_shuffle_ps(v273, v276, 238), 136);
  v280 = _mm_mul_ps((*triangleA)[2].m_quad, v266);
  v281 = _mm_add_ps(v279, _mm_add_ps(_mm_shuffle_ps(v277, v278, 221), _mm_shuffle_ps(v277, v278, 136)));
  v282 = _mm_mul_ps((*triangleA)[2].m_quad, v260);
  v283 = _mm_mul_ps(v256, v258);
  v284 = _mm_shuffle_ps(v280, v283, 68);
  v285 = _mm_shuffle_ps(v274, v282, 68);
  v286 = _mm_add_ps(
           _mm_shuffle_ps(_mm_shuffle_ps(v274, v282, 238), _mm_shuffle_ps(v280, v283, 238), 136),
           _mm_add_ps(_mm_shuffle_ps(v285, v284, 221), _mm_shuffle_ps(v285, v284, 136)));
  v287 = _mm_min_ps(_mm_min_ps(v272, v281), v286);
  v288 = _mm_max_ps(_mm_max_ps(v272, v281), v286);
  v289 = _mm_mul_ps((*triangleB)[0].m_quad, v258);
  v290 = _mm_mul_ps((*triangleB)[0].m_quad, v260);
  v291 = _mm_mul_ps((*triangleB)[0].m_quad, v266);
  v292 = _mm_mul_ps((*triangleB)[0].m_quad, v264);
  v293 = _mm_shuffle_ps(v292, v290, 68);
  v294 = _mm_shuffle_ps(v291, v289, 68);
  v295 = _mm_shuffle_ps(_mm_shuffle_ps(v292, v290, 238), _mm_shuffle_ps(v291, v289, 238), 136);
  v296 = (*triangleB)[1].m_quad;
  v297 = v296;
  v298 = _mm_mul_ps((*triangleB)[1].m_quad, v266);
  v299 = _mm_add_ps(v295, _mm_add_ps(_mm_shuffle_ps(v293, v294, 221), _mm_shuffle_ps(v293, v294, 136)));
  v300 = _mm_mul_ps((*triangleB)[1].m_quad, v260);
  v301 = _mm_mul_ps(v296, v258);
  v302 = _mm_mul_ps(v297, v264);
  v303 = _mm_shuffle_ps(v302, v300, 68);
  v304 = _mm_shuffle_ps(v298, v301, 68);
  v305 = _mm_shuffle_ps(v298, v301, 238);
  v306 = _mm_mul_ps((*triangleB)[2].m_quad, v264);
  v307 = _mm_add_ps(
           _mm_shuffle_ps(_mm_shuffle_ps(v302, v300, 238), v305, 136),
           _mm_add_ps(_mm_shuffle_ps(v303, v304, 221), _mm_shuffle_ps(v303, v304, 136)));
  v308 = _mm_mul_ps((*triangleB)[2].m_quad, v266);
  v309 = _mm_mul_ps((*triangleB)[2].m_quad, v260);
  v310 = _mm_shuffle_ps(v306, v309, 68);
  v311 = _mm_mul_ps((*triangleB)[2].m_quad, v258);
  v312 = _mm_shuffle_ps(v308, v311, 68);
  v313 = _mm_add_ps(
           _mm_shuffle_ps(_mm_shuffle_ps(v306, v309, 238), _mm_shuffle_ps(v308, v311, 238), 136),
           _mm_add_ps(_mm_shuffle_ps(v310, v312, 221), _mm_shuffle_ps(v310, v312, 136)));
  return _mm_movemask_ps(
           _mm_and_ps(
             _mm_and_ps(
               _mm_and_ps(
                 _mm_and_ps(
                   _mm_and_ps(_mm_and_ps(_mm_cmpleps(v49, v78), _mm_cmpleps(v77, v50)), (__m128)xmmword_141C1F330),
                   _mm_and_ps(_mm_cmpleps(v110, v144), _mm_cmpleps(v143, v111))),
                 _mm_and_ps(_mm_cmpleps(v171, v209), _mm_cmpleps(v208, v172))),
               _mm_and_ps(_mm_cmpleps(v233, v263), _mm_cmpleps(v265, v234))),
             _mm_and_ps(
               _mm_cmpleps(v287, _mm_max_ps(_mm_max_ps(v299, v307), v313)),
               _mm_cmpleps(_mm_min_ps(_mm_min_ps(v299, v307), v313), v288)))) == 15;
}

