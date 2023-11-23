// File Line: 63
// RVA: 0x130AED0
void __fastcall updateIntersection(
        hkVector4f *d0,
        hkVector4f *d1,
        hkVector4f *d2,
        hkVector4f *d3,
        hkVector4f *triA,
        hkVector4f *triB,
        hkVector4fComparison *cmpInOut)
{
  __m128 v7; // xmm0
  __m128 v8; // xmm1
  __m128 v9; // xmm4
  __m128 v10; // xmm2
  __m128 v11; // xmm1
  __m128 v12; // xmm13
  __m128 v13; // xmm3
  __m128 v14; // xmm6
  __m128 v15; // xmm13
  __m128 v16; // xmm2
  __m128 v17; // xmm0
  __m128 v18; // xmm3
  __m128 v19; // xmm4
  __m128 v20; // xmm1
  __m128 v21; // xmm2
  __m128 m_quad; // xmm4
  __m128 v23; // xmm6
  __m128 v24; // xmm0
  __m128 v25; // xmm3
  __m128 v26; // xmm5
  __m128 v27; // xmm3
  __m128 v28; // xmm2
  __m128 v29; // xmm4
  __m128 v30; // xmm1
  __m128 v31; // xmm5
  __m128 v32; // xmm8
  __m128 v33; // xmm13
  __m128 v34; // xmm7
  __m128 v35; // xmm4
  __m128 v36; // xmm3
  __m128 v37; // xmm1
  __m128 v38; // xmm5
  __m128 v39; // xmm2
  __m128 v40; // xmm7
  __m128 v41; // xmm0
  __m128 v42; // xmm1
  __m128 v43; // xmm3
  __m128 v44; // xmm5
  __m128 v45; // xmm4
  __m128 v46; // xmm6
  __m128 v47; // xmm5
  __m128 v48; // xmm2
  __m128 v49; // xmm6
  __m128 v50; // xmm0
  __m128 v51; // xmm10
  __m128 v52; // xmm11
  __m128 v53; // xmm2
  __m128 v54; // xmm9
  __m128 v55; // xmm12
  __m128 v56; // xmm2
  __m128 v57; // xmm1
  __m128 v58; // xmm12

  v7 = _mm_mul_ps(triA->m_quad, d1->m_quad);
  v8 = _mm_mul_ps(triA->m_quad, d2->m_quad);
  v9 = _mm_mul_ps(triA->m_quad, d3->m_quad);
  v10 = _mm_shuffle_ps(v8, v9, 238);
  v11 = _mm_shuffle_ps(v8, v9, 68);
  v12 = _mm_mul_ps(triA->m_quad, d0->m_quad);
  v13 = _mm_shuffle_ps(v12, v7, 68);
  v14 = _mm_mul_ps(triA[1].m_quad, d0->m_quad);
  v15 = _mm_add_ps(
          _mm_shuffle_ps(_mm_shuffle_ps(v12, v7, 238), v10, 136),
          _mm_add_ps(_mm_shuffle_ps(v13, v11, 221), _mm_shuffle_ps(v13, v11, 136)));
  v16 = _mm_mul_ps(triA[1].m_quad, d2->m_quad);
  v17 = _mm_mul_ps(triA[1].m_quad, d1->m_quad);
  v18 = _mm_shuffle_ps(v14, v17, 68);
  v19 = _mm_mul_ps(triA[1].m_quad, d3->m_quad);
  v20 = _mm_shuffle_ps(v16, v19, 68);
  v21 = _mm_shuffle_ps(v16, v19, 238);
  m_quad = triA[2].m_quad;
  v23 = _mm_add_ps(
          _mm_shuffle_ps(_mm_shuffle_ps(v14, v17, 238), v21, 136),
          _mm_add_ps(_mm_shuffle_ps(v18, v20, 221), _mm_shuffle_ps(v18, v20, 136)));
  v24 = _mm_mul_ps(m_quad, d1->m_quad);
  v25 = _mm_mul_ps(m_quad, d0->m_quad);
  v26 = _mm_shuffle_ps(v25, v24, 238);
  v27 = _mm_shuffle_ps(v25, v24, 68);
  v28 = _mm_mul_ps(m_quad, d2->m_quad);
  v29 = _mm_mul_ps(m_quad, d3->m_quad);
  v30 = _mm_shuffle_ps(v28, v29, 68);
  v31 = _mm_add_ps(
          _mm_shuffle_ps(v26, _mm_shuffle_ps(v28, v29, 238), 136),
          _mm_add_ps(_mm_shuffle_ps(v27, v30, 221), _mm_shuffle_ps(v27, v30, 136)));
  v32 = _mm_min_ps(_mm_min_ps(v15, v23), v31);
  v33 = _mm_max_ps(_mm_max_ps(v15, v23), v31);
  v34 = _mm_mul_ps(d0->m_quad, triB->m_quad);
  v35 = _mm_mul_ps(d2->m_quad, triB->m_quad);
  v36 = _mm_mul_ps(d1->m_quad, triB->m_quad);
  v37 = _mm_mul_ps(d3->m_quad, triB->m_quad);
  v38 = _mm_shuffle_ps(v34, v36, 68);
  v39 = _mm_shuffle_ps(v35, v37, 68);
  v40 = _mm_add_ps(
          _mm_shuffle_ps(_mm_shuffle_ps(v34, v36, 238), _mm_shuffle_ps(v35, v37, 238), 136),
          _mm_add_ps(_mm_shuffle_ps(v38, v39, 221), _mm_shuffle_ps(v38, v39, 136)));
  v41 = triB[1].m_quad;
  v42 = _mm_mul_ps(d3->m_quad, v41);
  v43 = _mm_mul_ps(d1->m_quad, v41);
  v44 = _mm_mul_ps(d0->m_quad, v41);
  v45 = _mm_mul_ps(d2->m_quad, v41);
  v46 = _mm_shuffle_ps(v44, v43, 238);
  v47 = _mm_shuffle_ps(v44, v43, 68);
  v48 = _mm_shuffle_ps(v45, v42, 68);
  v49 = _mm_add_ps(
          _mm_shuffle_ps(v46, _mm_shuffle_ps(v45, v42, 238), 136),
          _mm_add_ps(_mm_shuffle_ps(v47, v48, 221), _mm_shuffle_ps(v47, v48, 136)));
  v50 = triB[2].m_quad;
  v51 = _mm_mul_ps(d1->m_quad, v50);
  v52 = _mm_mul_ps(d2->m_quad, v50);
  v53 = _mm_mul_ps(d0->m_quad, v50);
  v54 = _mm_mul_ps(d3->m_quad, v50);
  v55 = _mm_shuffle_ps(v53, v51, 238);
  v56 = _mm_shuffle_ps(v53, v51, 68);
  v57 = _mm_shuffle_ps(v52, v54, 68);
  v58 = _mm_add_ps(
          _mm_shuffle_ps(v55, _mm_shuffle_ps(v52, v54, 238), 136),
          _mm_add_ps(_mm_shuffle_ps(v56, v57, 221), _mm_shuffle_ps(v56, v57, 136)));
  cmpInOut->m_mask = _mm_and_ps(
                       _mm_and_ps(
                         _mm_cmple_ps(v32, _mm_max_ps(_mm_max_ps(v40, v49), v58)),
                         _mm_cmple_ps(_mm_min_ps(_mm_min_ps(v40, v49), v58), v33)),
                       cmpInOut->m_mask);
}

// File Line: 74
// RVA: 0x130A210
_BOOL8 __fastcall hkcdIntersectTriangleTriangle(hkVector4f (*triangleA)[3], hkVector4f (*triangleB)[3])
{
  __m128 v2; // xmm1
  __m128 m_quad; // xmm6
  __m128 v4; // xmm2
  __m128 v5; // xmm11
  __m128 v6; // xmm10
  __m128 v7; // xmm1
  __m128 v8; // xmm15
  __m128 v9; // xmm13
  __m128 v10; // xmm14
  __m128 v11; // xmm12
  __m128 v12; // xmm9
  __m128 v13; // xmm15
  __m128 v14; // xmm8
  __m128 v15; // xmm7
  __m128 v16; // xmm3
  __m128 v17; // xmm10
  __m128 v18; // xmm2
  __m128 v19; // xmm0
  __m128 v20; // xmm1
  __m128 v21; // xmm3
  __m128 v22; // xmm0
  __m128 v23; // xmm6
  __m128 v24; // xmm5
  __m128 v25; // xmm3
  __m128 v26; // xmm0
  __m128 v27; // xmm2
  __m128 v28; // xmm3
  __m128 v29; // xmm1
  __m128 v30; // xmm4
  __m128 v31; // xmm6
  __m128 v32; // xmm3
  __m128 v33; // xmm0
  __m128 v34; // xmm5
  __m128 v35; // xmm2
  __m128 v36; // xmm3
  __m128 v37; // xmm1
  __m128 v38; // xmm4
  __m128 v39; // xmm5
  __m128 v40; // xmm0
  __m128 v41; // xmm5
  __m128 v42; // xmm2
  __m128 v43; // xmm3
  __m128 v44; // xmm1
  __m128 v45; // xmm4
  __m128 v46; // xmm5
  __m128 v47; // xmm0
  __m128 v48; // xmm6
  __m128 v49; // xmm2
  __m128 v50; // xmm0
  __m128 v51; // xmm4
  __m128 v52; // xmm3
  __m128 v53; // xmm1
  __m128 v54; // xmm6
  __m128 v55; // xmm3
  __m128 v56; // xmm0
  __m128 v57; // xmm5
  __m128 v58; // xmm2
  __m128 v59; // xmm1
  __m128 v60; // xmm3
  __m128 v61; // xmm1
  __m128 v62; // xmm4
  __m128 v63; // xmm5
  __m128 v64; // xmm7
  __m128 v65; // xmm1
  __m128 v66; // xmm11
  __m128 v67; // xmm10
  __m128 v68; // xmm9
  __m128 v69; // xmm0
  __m128 v70; // xmm11
  __m128 v71; // xmm2
  __m128 v72; // xmm8
  __m128 v73; // xmm0
  __m128 v74; // xmm4
  __m128 v75; // xmm1
  __m128 v76; // xmm3
  __m128 v77; // xmm1
  __m128 v78; // xmm11
  __m128 v79; // xmm6
  __m128 v80; // xmm0
  __m128 v81; // xmm2
  __m128 v82; // xmm6
  __m128 v83; // xmm1
  __m128 v84; // xmm3
  __m128 v85; // xmm1
  __m128 v86; // xmm4
  __m128 v87; // xmm6
  __m128 v88; // xmm5
  __m128 v89; // xmm0
  __m128 v90; // xmm2
  __m128 v91; // xmm5
  __m128 v92; // xmm1
  __m128 v93; // xmm3
  __m128 v94; // xmm1
  __m128 v95; // xmm4
  __m128 v96; // xmm5
  __m128 v97; // xmm0
  __m128 v98; // xmm11
  __m128 v99; // xmm2
  __m128 v100; // xmm1
  __m128 v101; // xmm3
  __m128 v102; // xmm1
  __m128 v103; // xmm4
  __m128 v104; // xmm11
  __m128 v105; // xmm3
  __m128 v106; // xmm0
  __m128 v107; // xmm6
  __m128 v108; // xmm2
  __m128 v109; // xmm1
  __m128 v110; // xmm4
  __m128 v111; // xmm3
  __m128 v112; // xmm1
  __m128 v113; // xmm6
  __m128 v114; // xmm13
  __m128 v115; // xmm2
  __m128 v116; // xmm0
  __m128 v117; // xmm5
  __m128 v118; // xmm1
  __m128 v119; // xmm3
  __m128 v120; // xmm1
  __m128 v121; // xmm2
  __m128 v122; // xmm4
  __m128 v123; // xmm9
  __m128 v124; // xmm14
  __m128 v125; // xmm5
  __m128 v126; // xmm0
  __m128 v127; // xmm11
  __m128 v128; // xmm6
  __m128 v129; // xmm0
  __m128 v130; // xmm12
  __m128 v131; // xmm11
  __m128 v132; // xmm8
  __m128 v133; // xmm7
  __m128 v134; // xmm10
  __m128 v135; // xmm2
  __m128 v136; // xmm0
  __m128 v137; // xmm4
  __m128 v138; // xmm1
  __m128 v139; // xmm3
  __m128 v140; // xmm1
  __m128 v141; // xmm10
  __m128 v142; // xmm2
  __m128 v143; // xmm15
  __m128 v144; // xmm0
  __m128 v145; // xmm1
  __m128 v146; // xmm3
  __m128 v147; // xmm1
  __m128 v148; // xmm4
  __m128 v149; // xmm5
  __m128 v150; // xmm6
  __m128 v151; // xmm2
  __m128 v152; // xmm1
  __m128 v153; // xmm0
  __m128 v154; // xmm4
  __m128 v155; // xmm3
  __m128 v156; // xmm1
  __m128 v157; // xmm5
  __m128 v158; // xmm0
  __m128 v159; // xmm10
  __m128 v160; // xmm2
  __m128 v161; // xmm1
  __m128 v162; // xmm3
  __m128 v163; // xmm1
  __m128 v164; // xmm4
  __m128 v165; // xmm10
  __m128 v166; // xmm3
  __m128 v167; // xmm0
  __m128 v168; // xmm6
  __m128 v169; // xmm2
  __m128 v170; // xmm3
  __m128 v171; // xmm1
  __m128 v172; // xmm4
  __m128 v173; // xmm6
  __m128 v174; // xmm5
  __m128 v175; // xmm0
  __m128 v176; // xmm2
  __m128 v177; // xmm1
  __m128 v178; // xmm7
  __m128 v179; // xmm3
  __m128 v180; // xmm1
  __m128 v181; // xmm11
  __m128 v182; // xmm8
  __m128 v183; // xmm5
  __m128 v184; // xmm11
  __m128 v185; // xmm9
  __m128 v186; // xmm4
  __m128 v187; // xmm5
  __m128 v188; // xmm2
  __m128 v189; // xmm0
  __m128 v190; // xmm10
  __m128 v191; // xmm1
  __m128 v192; // xmm6
  __m128 v193; // xmm10
  __m128 v194; // xmm5
  __m128 v195; // xmm0
  __m128 v196; // xmm4
  __m128 v197; // xmm10
  __m128 v198; // xmm3
  __m128 v199; // xmm1
  __m128 v200; // xmm2
  __m128 v201; // xmm10
  __m128 v202; // xmm3
  __m128 v203; // xmm4
  __m128 v204; // xmm0
  __m128 v205; // xmm1
  __m128 v206; // xmm6
  __m128 v207; // xmm2
  __m128 v208; // xmm1
  __m128 v209; // xmm0
  __m128 v210; // xmm4
  __m128 v211; // xmm5
  __m128 v212; // xmm3
  __m128 v213; // xmm1
  __m128 v214; // xmm2
  __m128 v215; // xmm5
  __m128 v216; // xmm14
  __m128 v217; // xmm15
  __m128 v218; // xmm1
  __m128 v219; // xmm0
  __m128 v220; // xmm4
  __m128 v221; // xmm10
  __m128 v222; // xmm3
  __m128 v223; // xmm1
  __m128 v224; // xmm5
  __m128 v225; // xmm14
  __m128 v226; // xmm2
  __m128 v227; // xmm0
  __m128 v228; // xmm3
  __m128 v229; // xmm6
  __m128 v230; // xmm2
  __m128 v231; // xmm1
  __m128 v232; // xmm4
  __m128 v233; // xmm6
  __m128 v234; // xmm2
  __m128 v235; // xmm6
  __m128 v236; // xmm0
  __m128 v237; // xmm4
  __m128 v238; // xmm1
  __m128 v239; // xmm3
  __m128 v240; // xmm1
  __m128 v241; // xmm7
  __m128 v242; // xmm13
  __m128 v243; // xmm11
  __m128 v244; // xmm5
  __m128 v245; // xmm9
  __m128 v246; // xmm0
  __m128 v247; // xmm4
  __m128 v248; // xmm14
  __m128 v249; // xmm8
  __m128 v250; // xmm13
  __m128 v251; // xmm10
  __m128 v252; // xmm12
  __m128 v253; // xmm5
  __m128 v254; // xmm3
  __m128 v255; // xmm1
  __m128 v256; // xmm2
  __m128 v257; // xmm1
  __m128 v258; // xmm12
  __m128 v259; // xmm2
  __m128 v260; // xmm0
  __m128 v261; // xmm6
  __m128 v262; // xmm3
  __m128 v263; // xmm5
  __m128 v264; // xmm1
  __m128 v265; // xmm0
  __m128 v266; // xmm3
  __m128 v267; // xmm5
  __m128 v268; // xmm2
  __m128 v269; // xmm5
  __m128 v270; // xmm0
  __m128 v271; // xmm7
  __m128 v272; // xmm1
  __m128 v273; // xmm4
  __m128 v274; // xmm3
  __m128 v275; // xmm4
  __m128 v276; // xmm7
  __m128 v277; // xmm12
  __m128 v278; // xmm4
  __m128 v279; // xmm0
  __m128 v280; // xmm6
  __m128 v281; // xmm1
  __m128 v282; // xmm3
  __m128 v283; // xmm2
  __m128 v284; // xmm1
  __m128 v285; // xmm6
  __m128 v286; // xmm5
  __m128 v287; // xmm2
  __m128 v288; // xmm6
  __m128 v289; // xmm0
  __m128 v290; // xmm4
  __m128 v291; // xmm5
  __m128 v292; // xmm3
  __m128 v293; // xmm1
  __m128 v294; // xmm2
  __m128 v295; // xmm4
  __m128 v296; // xmm5
  __m128 v297; // xmm2
  __m128 v298; // xmm0
  __m128 v299; // xmm3
  __m128 v300; // xmm8
  __m128 v301; // xmm1
  __m128 v302; // xmm4
  __m128 v304; // [rsp+0h] [rbp-198h]
  __m128 v305; // [rsp+0h] [rbp-198h]
  __m128 v306; // [rsp+0h] [rbp-198h]
  __m128 v307; // [rsp+10h] [rbp-188h]
  __m128 v308; // [rsp+10h] [rbp-188h]
  __m128 v309; // [rsp+20h] [rbp-178h]
  __m128 v310; // [rsp+20h] [rbp-178h]
  __m128 v311; // [rsp+30h] [rbp-168h]
  __m128 v312; // [rsp+30h] [rbp-168h]
  __m128 v313; // [rsp+40h] [rbp-158h]
  __m128 v314; // [rsp+40h] [rbp-158h]
  __m128 v315; // [rsp+50h] [rbp-148h]
  __m128 v316; // [rsp+60h] [rbp-138h]
  __m128 v317; // [rsp+60h] [rbp-138h]
  __m128 v318; // [rsp+70h] [rbp-128h]
  __m128 v319; // [rsp+80h] [rbp-118h]
  __m128 v320; // [rsp+90h] [rbp-108h]
  __m128 v321; // [rsp+A0h] [rbp-F8h]
  __m128 v322; // [rsp+B0h] [rbp-E8h]
  __m128 v323; // [rsp+C0h] [rbp-D8h]
  __m128 v324; // [rsp+D0h] [rbp-C8h]
  __m128 v325; // [rsp+E0h] [rbp-B8h]

  v2 = _mm_sub_ps((*triangleB)[1].m_quad, (*triangleB)[0].m_quad);
  m_quad = (*triangleA)[1].m_quad;
  v4 = _mm_sub_ps((*triangleA)[2].m_quad, m_quad);
  v5 = _mm_sub_ps((*triangleB)[2].m_quad, (*triangleB)[1].m_quad);
  v6 = _mm_shuffle_ps(v2, v2, 210);
  v7 = _mm_shuffle_ps(v2, v2, 201);
  v8 = _mm_sub_ps((*triangleB)[0].m_quad, (*triangleB)[2].m_quad);
  v313 = _mm_sub_ps((*triangleA)[0].m_quad, (*triangleA)[2].m_quad);
  v9 = _mm_shuffle_ps(v313, v313, 210);
  v324 = _mm_sub_ps(m_quad, (*triangleA)[0].m_quad);
  v10 = _mm_shuffle_ps(v324, v324, 210);
  v315 = _mm_shuffle_ps(v324, v324, 201);
  v11 = _mm_shuffle_ps(v8, v8, 201);
  v12 = _mm_sub_ps(_mm_mul_ps(v6, v315), _mm_mul_ps(v10, v7));
  v13 = _mm_shuffle_ps(v8, v8, 210);
  v307 = _mm_shuffle_ps(v4, v4, 210);
  v309 = _mm_shuffle_ps(v4, v4, 201);
  v311 = _mm_shuffle_ps(v313, v313, 201);
  v14 = _mm_sub_ps(_mm_mul_ps(v6, v309), _mm_mul_ps(v307, v7));
  v15 = _mm_sub_ps(_mm_mul_ps(v6, v311), _mm_mul_ps(v9, v7));
  v16 = _mm_mul_ps((*triangleA)[0].m_quad, v15);
  v304 = _mm_mul_ps((*triangleA)[0].m_quad, v12);
  v17 = _mm_sub_ps(_mm_mul_ps(v6, v11), _mm_mul_ps(v13, v7));
  v18 = _mm_mul_ps((*triangleA)[0].m_quad, v14);
  v19 = _mm_mul_ps((*triangleA)[0].m_quad, v17);
  v20 = _mm_shuffle_ps(v16, v19, 68);
  v21 = _mm_shuffle_ps(v16, v19, 238);
  v22 = _mm_shuffle_ps(v304, v18, 68);
  v23 = _mm_mul_ps(m_quad, v12);
  v24 = _mm_add_ps(
          _mm_shuffle_ps(_mm_shuffle_ps(v304, v18, 238), v21, 136),
          _mm_add_ps(_mm_shuffle_ps(v22, v20, 221), _mm_shuffle_ps(v22, v20, 136)));
  v25 = (*triangleA)[1].m_quad;
  v26 = _mm_mul_ps(v25, v17);
  v305 = v24;
  v27 = _mm_mul_ps(v25, v14);
  v28 = _mm_mul_ps(v25, v15);
  v29 = _mm_shuffle_ps(v28, v26, 68);
  v30 = _mm_shuffle_ps(v23, v27, 68);
  v31 = _mm_add_ps(
          _mm_shuffle_ps(_mm_shuffle_ps(v23, v27, 238), _mm_shuffle_ps(v28, v26, 238), 136),
          _mm_add_ps(_mm_shuffle_ps(v30, v29, 221), _mm_shuffle_ps(v30, v29, 136)));
  v32 = (*triangleA)[2].m_quad;
  v33 = _mm_mul_ps(v32, v17);
  v34 = _mm_mul_ps(v32, v12);
  v35 = _mm_mul_ps(v32, v14);
  v36 = _mm_mul_ps(v32, v15);
  v37 = _mm_shuffle_ps(v36, v33, 68);
  v38 = _mm_shuffle_ps(v34, v35, 68);
  v39 = _mm_add_ps(
          _mm_shuffle_ps(_mm_shuffle_ps(v34, v35, 238), _mm_shuffle_ps(v36, v33, 238), 136),
          _mm_add_ps(_mm_shuffle_ps(v38, v37, 221), _mm_shuffle_ps(v38, v37, 136)));
  v320 = _mm_min_ps(_mm_min_ps(v305, v31), v39);
  v306 = _mm_max_ps(_mm_max_ps(v305, v31), v39);
  v40 = _mm_mul_ps((*triangleB)[0].m_quad, v17);
  v41 = _mm_mul_ps((*triangleB)[0].m_quad, v12);
  v42 = _mm_mul_ps((*triangleB)[0].m_quad, v14);
  v43 = _mm_mul_ps((*triangleB)[0].m_quad, v15);
  v44 = _mm_shuffle_ps(v43, v40, 68);
  v45 = _mm_shuffle_ps(v41, v42, 68);
  v46 = _mm_add_ps(
          _mm_shuffle_ps(_mm_shuffle_ps(v41, v42, 238), _mm_shuffle_ps(v43, v40, 238), 136),
          _mm_add_ps(_mm_shuffle_ps(v45, v44, 221), _mm_shuffle_ps(v45, v44, 136)));
  v47 = (*triangleB)[1].m_quad;
  v316 = v46;
  v48 = _mm_mul_ps(v47, v12);
  v49 = _mm_mul_ps(v47, v14);
  v50 = _mm_mul_ps(v47, v17);
  v51 = _mm_shuffle_ps(v48, v49, 68);
  v52 = _mm_mul_ps((*triangleB)[1].m_quad, v15);
  v53 = _mm_shuffle_ps(v52, v50, 68);
  v54 = _mm_add_ps(
          _mm_shuffle_ps(_mm_shuffle_ps(v48, v49, 238), _mm_shuffle_ps(v52, v50, 238), 136),
          _mm_add_ps(_mm_shuffle_ps(v51, v53, 221), _mm_shuffle_ps(v51, v53, 136)));
  v55 = (*triangleB)[2].m_quad;
  v56 = _mm_mul_ps(v55, v17);
  v57 = _mm_mul_ps(v55, v12);
  v58 = _mm_mul_ps(v55, v14);
  v59 = _mm_mul_ps(v55, v15);
  v60 = _mm_shuffle_ps(v59, v56, 238);
  v61 = _mm_shuffle_ps(v59, v56, 68);
  v62 = _mm_shuffle_ps(v57, v58, 68);
  v63 = _mm_add_ps(
          _mm_shuffle_ps(_mm_shuffle_ps(v57, v58, 238), v60, 136),
          _mm_add_ps(_mm_shuffle_ps(v62, v61, 221), _mm_shuffle_ps(v62, v61, 136)));
  v64 = _mm_sub_ps((*triangleA)[0].m_quad, (*triangleB)[0].m_quad);
  v318 = _mm_min_ps(_mm_min_ps(v316, v54), v63);
  v317 = _mm_max_ps(_mm_max_ps(v316, v54), v63);
  v65 = _mm_shuffle_ps(v5, v5, 210);
  v66 = _mm_shuffle_ps(v5, v5, 201);
  v67 = _mm_sub_ps(_mm_mul_ps(v315, v65), _mm_mul_ps(v10, v66));
  v68 = _mm_sub_ps(_mm_mul_ps(v309, v65), _mm_mul_ps(v307, v66));
  v69 = _mm_mul_ps(v9, v66);
  v70 = _mm_mul_ps((*triangleA)[0].m_quad, v67);
  v71 = _mm_mul_ps((*triangleA)[0].m_quad, v68);
  v72 = _mm_sub_ps(_mm_mul_ps(v311, v65), v69);
  v73 = _mm_mul_ps((*triangleA)[0].m_quad, v64);
  v74 = _mm_shuffle_ps(v70, v71, 68);
  v75 = _mm_mul_ps((*triangleA)[0].m_quad, v72);
  v76 = _mm_shuffle_ps(v75, v73, 238);
  v77 = _mm_shuffle_ps(v75, v73, 68);
  v78 = _mm_add_ps(
          _mm_shuffle_ps(_mm_shuffle_ps(v70, v71, 238), v76, 136),
          _mm_add_ps(_mm_shuffle_ps(v74, v77, 221), _mm_shuffle_ps(v74, v77, 136)));
  v79 = (*triangleA)[1].m_quad;
  v80 = _mm_mul_ps(v79, v64);
  v81 = _mm_mul_ps(v79, v68);
  v82 = _mm_mul_ps(v79, v67);
  v83 = _mm_mul_ps((*triangleA)[1].m_quad, v72);
  v84 = _mm_shuffle_ps(v83, v80, 238);
  v85 = _mm_shuffle_ps(v83, v80, 68);
  v86 = _mm_shuffle_ps(v82, v81, 68);
  v87 = _mm_add_ps(
          _mm_shuffle_ps(_mm_shuffle_ps(v82, v81, 238), v84, 136),
          _mm_add_ps(_mm_shuffle_ps(v86, v85, 221), _mm_shuffle_ps(v86, v85, 136)));
  v88 = (*triangleA)[2].m_quad;
  v89 = _mm_mul_ps(v88, v64);
  v90 = _mm_mul_ps(v88, v68);
  v91 = _mm_mul_ps(v88, v67);
  v92 = _mm_mul_ps((*triangleA)[2].m_quad, v72);
  v93 = _mm_shuffle_ps(v92, v89, 238);
  v94 = _mm_shuffle_ps(v92, v89, 68);
  v95 = _mm_shuffle_ps(v91, v90, 68);
  v96 = _mm_add_ps(
          _mm_shuffle_ps(_mm_shuffle_ps(v91, v90, 238), v93, 136),
          _mm_add_ps(_mm_shuffle_ps(v95, v94, 221), _mm_shuffle_ps(v95, v94, 136)));
  v322 = _mm_min_ps(_mm_min_ps(v78, v87), v96);
  v323 = _mm_max_ps(_mm_max_ps(v78, v87), v96);
  v97 = _mm_mul_ps((*triangleB)[0].m_quad, v64);
  v98 = _mm_mul_ps((*triangleB)[0].m_quad, v67);
  v99 = _mm_mul_ps((*triangleB)[0].m_quad, v68);
  v100 = _mm_mul_ps((*triangleB)[0].m_quad, v72);
  v101 = _mm_shuffle_ps(v100, v97, 238);
  v102 = _mm_shuffle_ps(v100, v97, 68);
  v103 = _mm_shuffle_ps(v98, v99, 68);
  v104 = _mm_add_ps(
           _mm_shuffle_ps(_mm_shuffle_ps(v98, v99, 238), v101, 136),
           _mm_add_ps(_mm_shuffle_ps(v103, v102, 221), _mm_shuffle_ps(v103, v102, 136)));
  v105 = (*triangleB)[1].m_quad;
  v106 = _mm_mul_ps(v105, v64);
  v107 = _mm_mul_ps(v105, v67);
  v108 = _mm_mul_ps(v105, v68);
  v109 = _mm_mul_ps(v105, v72);
  v110 = _mm_shuffle_ps(v107, v108, 68);
  v111 = _mm_shuffle_ps(v109, v106, 238);
  v112 = _mm_shuffle_ps(v109, v106, 68);
  v113 = _mm_add_ps(
           _mm_shuffle_ps(_mm_shuffle_ps(v107, v108, 238), v111, 136),
           _mm_add_ps(_mm_shuffle_ps(v110, v112, 221), _mm_shuffle_ps(v110, v112, 136)));
  v114 = _mm_mul_ps(v9, v11);
  v115 = (*triangleB)[2].m_quad;
  v116 = _mm_mul_ps(v115, v64);
  v117 = _mm_mul_ps(v115, v67);
  v118 = _mm_mul_ps(v115, v72);
  v119 = _mm_shuffle_ps(v118, v116, 238);
  v120 = _mm_shuffle_ps(v118, v116, 68);
  v121 = _mm_mul_ps(v115, v68);
  v122 = _mm_shuffle_ps(v117, v121, 68);
  v123 = _mm_sub_ps(_mm_mul_ps(v315, v13), _mm_mul_ps(v10, v11));
  v124 = (*triangleA)[1].m_quad;
  v125 = _mm_add_ps(
           _mm_shuffle_ps(_mm_shuffle_ps(v117, v121, 238), v119, 136),
           _mm_add_ps(_mm_shuffle_ps(v122, v120, 221), _mm_shuffle_ps(v122, v120, 136)));
  v126 = _mm_min_ps(v104, v113);
  v127 = _mm_max_ps(v104, v113);
  v128 = _mm_mul_ps(v124, v123);
  v321 = _mm_min_ps(v126, v125);
  v319 = _mm_max_ps(v127, v125);
  v129 = _mm_mul_ps(v307, v11);
  v130 = v311;
  v131 = _mm_sub_ps(_mm_mul_ps(v309, v13), v129);
  v132 = _mm_sub_ps(_mm_mul_ps(v311, v13), v114);
  v133 = _mm_sub_ps((*triangleA)[0].m_quad, (*triangleB)[1].m_quad);
  v134 = _mm_mul_ps((*triangleA)[0].m_quad, v123);
  v135 = _mm_mul_ps((*triangleA)[0].m_quad, v131);
  v136 = _mm_mul_ps((*triangleA)[0].m_quad, v133);
  v137 = _mm_shuffle_ps(v134, v135, 68);
  v138 = _mm_mul_ps((*triangleA)[0].m_quad, v132);
  v139 = _mm_shuffle_ps(v138, v136, 238);
  v140 = _mm_shuffle_ps(v138, v136, 68);
  v141 = _mm_add_ps(
           _mm_shuffle_ps(_mm_shuffle_ps(v134, v135, 238), v139, 136),
           _mm_add_ps(_mm_shuffle_ps(v137, v140, 221), _mm_shuffle_ps(v137, v140, 136)));
  v142 = _mm_mul_ps(v124, v131);
  v143 = (*triangleA)[2].m_quad;
  v144 = _mm_mul_ps(v124, v133);
  v145 = _mm_mul_ps(v124, v132);
  v146 = _mm_shuffle_ps(v145, v144, 238);
  v147 = _mm_shuffle_ps(v145, v144, 68);
  v148 = _mm_shuffle_ps(v128, v142, 68);
  v149 = _mm_mul_ps(v143, v123);
  v150 = _mm_add_ps(
           _mm_shuffle_ps(_mm_shuffle_ps(v128, v142, 238), v146, 136),
           _mm_add_ps(_mm_shuffle_ps(v148, v147, 221), _mm_shuffle_ps(v148, v147, 136)));
  v151 = _mm_mul_ps(v143, v131);
  v152 = _mm_mul_ps(v143, v132);
  v153 = _mm_mul_ps(v143, v133);
  v154 = _mm_shuffle_ps(v149, v151, 68);
  v155 = _mm_shuffle_ps(v152, v153, 238);
  v156 = _mm_shuffle_ps(v152, v153, 68);
  v157 = _mm_add_ps(
           _mm_shuffle_ps(_mm_shuffle_ps(v149, v151, 238), v155, 136),
           _mm_add_ps(_mm_shuffle_ps(v154, v156, 221), _mm_shuffle_ps(v154, v156, 136)));
  v312 = _mm_min_ps(_mm_min_ps(v141, v150), v157);
  v325 = _mm_max_ps(_mm_max_ps(v141, v150), v157);
  v158 = _mm_mul_ps((*triangleB)[0].m_quad, v133);
  v159 = _mm_mul_ps((*triangleB)[0].m_quad, v123);
  v160 = _mm_mul_ps((*triangleB)[0].m_quad, v131);
  v161 = _mm_mul_ps((*triangleB)[0].m_quad, v132);
  v162 = _mm_shuffle_ps(v161, v158, 238);
  v163 = _mm_shuffle_ps(v161, v158, 68);
  v164 = _mm_shuffle_ps(v159, v160, 68);
  v165 = _mm_add_ps(
           _mm_shuffle_ps(_mm_shuffle_ps(v159, v160, 238), v162, 136),
           _mm_add_ps(_mm_shuffle_ps(v164, v163, 221), _mm_shuffle_ps(v164, v163, 136)));
  v166 = (*triangleB)[1].m_quad;
  v167 = _mm_mul_ps(v166, v133);
  v168 = _mm_mul_ps(v166, v123);
  v169 = _mm_mul_ps(v166, v131);
  v170 = _mm_mul_ps(v166, v132);
  v171 = _mm_shuffle_ps(v170, v167, 68);
  v172 = _mm_shuffle_ps(v168, v169, 68);
  v173 = _mm_add_ps(
           _mm_shuffle_ps(_mm_shuffle_ps(v168, v169, 238), _mm_shuffle_ps(v170, v167, 238), 136),
           _mm_add_ps(_mm_shuffle_ps(v172, v171, 221), _mm_shuffle_ps(v172, v171, 136)));
  v174 = (*triangleB)[2].m_quad;
  v175 = _mm_mul_ps(v174, v133);
  v176 = _mm_mul_ps(v174, v131);
  v177 = _mm_mul_ps(v174, v132);
  v178 = _mm_sub_ps((*triangleA)[0].m_quad, v174);
  v179 = _mm_shuffle_ps(v177, v175, 238);
  v180 = _mm_shuffle_ps(v177, v175, 68);
  v181 = _mm_sub_ps(_mm_mul_ps(v315, v313), _mm_mul_ps(v130, v324));
  v182 = _mm_sub_ps(v124, (*triangleB)[0].m_quad);
  v183 = _mm_mul_ps(v174, v123);
  v184 = _mm_shuffle_ps(v181, v181, 201);
  v185 = _mm_sub_ps(v124, (*triangleB)[1].m_quad);
  v186 = _mm_shuffle_ps(v183, v176, 68);
  v187 = _mm_add_ps(
           _mm_shuffle_ps(_mm_shuffle_ps(v183, v176, 238), v179, 136),
           _mm_add_ps(_mm_shuffle_ps(v186, v180, 221), _mm_shuffle_ps(v186, v180, 136)));
  v188 = _mm_mul_ps((*triangleA)[0].m_quad, v178);
  v189 = _mm_min_ps(v165, v173);
  v190 = _mm_max_ps(_mm_max_ps(v165, v173), v187);
  v191 = _mm_mul_ps((*triangleA)[0].m_quad, v182);
  v192 = _mm_mul_ps(v124, v184);
  v308 = _mm_min_ps(v189, v187);
  v310 = v190;
  v193 = _mm_mul_ps((*triangleA)[0].m_quad, v184);
  v194 = _mm_mul_ps(v143, v184);
  v195 = _mm_mul_ps((*triangleA)[0].m_quad, v185);
  v196 = _mm_shuffle_ps(v193, v188, 68);
  v197 = _mm_shuffle_ps(v193, v188, 238);
  v198 = _mm_shuffle_ps(v191, v195, 238);
  v199 = _mm_shuffle_ps(v191, v195, 68);
  v200 = _mm_mul_ps(v124, v178);
  v201 = _mm_add_ps(
           _mm_shuffle_ps(v197, v198, 136),
           _mm_add_ps(_mm_shuffle_ps(v196, v199, 221), _mm_shuffle_ps(v196, v199, 136)));
  v202 = _mm_mul_ps(v124, v182);
  v203 = _mm_shuffle_ps(v192, v200, 68);
  v204 = _mm_mul_ps(v124, v185);
  v205 = _mm_shuffle_ps(v202, v204, 68);
  v206 = _mm_add_ps(
           _mm_shuffle_ps(_mm_shuffle_ps(v192, v200, 238), _mm_shuffle_ps(v202, v204, 238), 136),
           _mm_add_ps(_mm_shuffle_ps(v203, v205, 221), _mm_shuffle_ps(v203, v205, 136)));
  v207 = _mm_mul_ps(v143, v178);
  v208 = _mm_mul_ps(v143, v182);
  v209 = _mm_mul_ps(v143, v185);
  v210 = _mm_shuffle_ps(v194, v207, 68);
  v211 = _mm_shuffle_ps(v194, v207, 238);
  v212 = _mm_shuffle_ps(v208, v209, 238);
  v213 = _mm_shuffle_ps(v208, v209, 68);
  v214 = _mm_mul_ps((*triangleB)[0].m_quad, v178);
  v215 = _mm_add_ps(
           _mm_shuffle_ps(v211, v212, 136),
           _mm_add_ps(_mm_shuffle_ps(v210, v213, 221), _mm_shuffle_ps(v210, v213, 136)));
  v216 = _mm_mul_ps((*triangleB)[0].m_quad, v184);
  v217 = _mm_min_ps(_mm_min_ps(v201, v206), v215);
  v218 = _mm_mul_ps((*triangleB)[0].m_quad, v182);
  v314 = _mm_max_ps(_mm_max_ps(v201, v206), v215);
  v219 = _mm_mul_ps((*triangleB)[0].m_quad, v185);
  v220 = _mm_shuffle_ps(v216, v214, 68);
  v221 = (*triangleB)[2].m_quad;
  v222 = _mm_shuffle_ps(v218, v219, 238);
  v223 = _mm_shuffle_ps(v218, v219, 68);
  v224 = _mm_mul_ps(v221, v184);
  v225 = _mm_add_ps(
           _mm_shuffle_ps(_mm_shuffle_ps(v216, v214, 238), v222, 136),
           _mm_add_ps(_mm_shuffle_ps(v220, v223, 221), _mm_shuffle_ps(v220, v223, 136)));
  v226 = (*triangleB)[1].m_quad;
  v227 = _mm_mul_ps(v226, v185);
  v228 = _mm_mul_ps(v226, v182);
  v229 = _mm_mul_ps(v226, v184);
  v230 = _mm_mul_ps(v226, v178);
  v231 = _mm_shuffle_ps(v228, v227, 68);
  v232 = _mm_shuffle_ps(v229, v230, 68);
  v233 = _mm_shuffle_ps(_mm_shuffle_ps(v229, v230, 238), _mm_shuffle_ps(v228, v227, 238), 136);
  v234 = _mm_mul_ps(v221, v178);
  v235 = _mm_add_ps(v233, _mm_add_ps(_mm_shuffle_ps(v232, v231, 221), _mm_shuffle_ps(v232, v231, 136)));
  v236 = _mm_mul_ps(v221, v185);
  v237 = _mm_shuffle_ps(v224, v234, 68);
  v238 = _mm_mul_ps(v221, v182);
  v239 = _mm_shuffle_ps(v238, v236, 238);
  v240 = _mm_shuffle_ps(v238, v236, 68);
  v241 = (*triangleA)[2].m_quad;
  v242 = v225;
  v243 = _mm_sub_ps(v241, v221);
  v244 = _mm_add_ps(
           _mm_shuffle_ps(_mm_shuffle_ps(v224, v234, 238), v239, 136),
           _mm_add_ps(_mm_shuffle_ps(v237, v240, 221), _mm_shuffle_ps(v237, v240, 136)));
  v245 = _mm_sub_ps(v241, (*triangleB)[0].m_quad);
  v246 = _mm_mul_ps((*triangleA)[0].m_quad, v245);
  v247 = _mm_mul_ps((*triangleA)[0].m_quad, v243);
  v248 = _mm_max_ps(_mm_max_ps(v225, v235), v244);
  v249 = _mm_sub_ps((*triangleA)[1].m_quad, v221);
  v250 = _mm_min_ps(_mm_min_ps(v242, v235), v244);
  v251 = _mm_sub_ps(v241, (*triangleB)[1].m_quad);
  v252 = _mm_mul_ps((*triangleA)[0].m_quad, v249);
  v253 = _mm_mul_ps((*triangleA)[1].m_quad, v249);
  v254 = _mm_shuffle_ps(v252, v246, 68);
  v255 = _mm_mul_ps((*triangleA)[0].m_quad, v251);
  v256 = _mm_shuffle_ps(v255, v247, 238);
  v257 = _mm_shuffle_ps(v255, v247, 68);
  v258 = _mm_add_ps(
           _mm_shuffle_ps(_mm_shuffle_ps(v252, v246, 238), v256, 136),
           _mm_add_ps(_mm_shuffle_ps(v254, v257, 221), _mm_shuffle_ps(v254, v257, 136)));
  v259 = _mm_mul_ps((*triangleA)[1].m_quad, v251);
  v260 = _mm_mul_ps((*triangleA)[1].m_quad, v245);
  v261 = _mm_mul_ps((*triangleA)[1].m_quad, v243);
  v262 = _mm_shuffle_ps(v253, v260, 68);
  v263 = _mm_shuffle_ps(v253, v260, 238);
  v264 = _mm_shuffle_ps(v259, v261, 68);
  v265 = _mm_add_ps(_mm_shuffle_ps(v262, v264, 221), _mm_shuffle_ps(v262, v264, 136));
  v266 = _mm_mul_ps(v241, v249);
  v267 = _mm_shuffle_ps(v263, _mm_shuffle_ps(v259, v261, 238), 136);
  v268 = _mm_mul_ps(v241, v251);
  v269 = _mm_add_ps(v267, v265);
  v270 = _mm_mul_ps(v241, v245);
  v271 = _mm_mul_ps(v241, v243);
  v272 = _mm_shuffle_ps(v268, v271, 68);
  v273 = _mm_shuffle_ps(v266, v270, 238);
  v274 = _mm_shuffle_ps(v266, v270, 68);
  v275 = _mm_add_ps(
           _mm_shuffle_ps(v273, _mm_shuffle_ps(v268, v271, 238), 136),
           _mm_add_ps(_mm_shuffle_ps(v274, v272, 221), _mm_shuffle_ps(v274, v272, 136)));
  v276 = _mm_min_ps(_mm_min_ps(v258, v269), v275);
  v277 = _mm_max_ps(_mm_max_ps(v258, v269), v275);
  v278 = _mm_mul_ps((*triangleB)[0].m_quad, v243);
  v279 = _mm_mul_ps((*triangleB)[0].m_quad, v245);
  v280 = _mm_mul_ps((*triangleB)[0].m_quad, v249);
  v281 = _mm_mul_ps((*triangleB)[0].m_quad, v251);
  v282 = _mm_shuffle_ps(v280, v279, 68);
  v283 = _mm_shuffle_ps(v281, v278, 238);
  v284 = _mm_shuffle_ps(v281, v278, 68);
  v285 = _mm_shuffle_ps(_mm_shuffle_ps(v280, v279, 238), v283, 136);
  v286 = (*triangleB)[1].m_quad;
  v287 = _mm_mul_ps(v286, v251);
  v288 = _mm_add_ps(v285, _mm_add_ps(_mm_shuffle_ps(v282, v284, 221), _mm_shuffle_ps(v282, v284, 136)));
  v289 = _mm_mul_ps(v286, v245);
  v290 = _mm_mul_ps(v286, v243);
  v291 = _mm_mul_ps(v286, v249);
  v292 = _mm_shuffle_ps(v291, v289, 68);
  v293 = _mm_shuffle_ps(v287, v290, 68);
  v294 = _mm_shuffle_ps(v287, v290, 238);
  v295 = _mm_mul_ps((*triangleB)[2].m_quad, v249);
  v296 = _mm_add_ps(
           _mm_shuffle_ps(_mm_shuffle_ps(v291, v289, 238), v294, 136),
           _mm_add_ps(_mm_shuffle_ps(v292, v293, 221), _mm_shuffle_ps(v292, v293, 136)));
  v297 = _mm_mul_ps((*triangleB)[2].m_quad, v251);
  v298 = _mm_mul_ps((*triangleB)[2].m_quad, v245);
  v299 = _mm_shuffle_ps(v295, v298, 68);
  v300 = _mm_mul_ps((*triangleB)[2].m_quad, v243);
  v301 = _mm_shuffle_ps(v297, v300, 68);
  v302 = _mm_add_ps(
           _mm_shuffle_ps(_mm_shuffle_ps(v295, v298, 238), _mm_shuffle_ps(v297, v300, 238), 136),
           _mm_add_ps(_mm_shuffle_ps(v299, v301, 221), _mm_shuffle_ps(v299, v301, 136)));
  return _mm_movemask_ps(
           _mm_and_ps(
             _mm_and_ps(
               _mm_and_ps(
                 _mm_and_ps(
                   _mm_and_ps(_mm_and_ps(_mm_cmple_ps(v320, v317), _mm_cmple_ps(v318, v306)), (__m128)xmmword_141C1F330),
                   _mm_and_ps(_mm_cmple_ps(v322, v319), _mm_cmple_ps(v321, v323))),
                 _mm_and_ps(_mm_cmple_ps(v312, v310), _mm_cmple_ps(v308, v325))),
               _mm_and_ps(_mm_cmple_ps(v217, v248), _mm_cmple_ps(v250, v314))),
             _mm_and_ps(
               _mm_cmple_ps(v276, _mm_max_ps(_mm_max_ps(v288, v296), v302)),
               _mm_cmple_ps(_mm_min_ps(_mm_min_ps(v288, v296), v302), v277)))) == 15;
}

