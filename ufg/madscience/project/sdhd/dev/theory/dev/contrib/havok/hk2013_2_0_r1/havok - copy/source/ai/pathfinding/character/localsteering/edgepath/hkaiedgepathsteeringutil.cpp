// File Line: 18
// RVA: 0xC13430
void __fastcall makeReflectionMatrix(hkVector4f *p, hkMatrix4f *m)
{
  __m128 v2; // xmm5
  __m128 v3; // xmm4
  __m128 v4; // xmm4
  hkVector4f v5; // xmm2
  hkVector4f v6; // xmm1

  v2 = p->m_quad;
  v3 = _mm_shuffle_ps(p->m_quad, _mm_unpackhi_ps(p->m_quad, (__m128)0i64), 196);
  v4 = _mm_add_ps(v3, v3);
  v5.m_quad = _mm_sub_ps(stru_141A71280.m_quad, _mm_mul_ps(_mm_shuffle_ps(p->m_quad, p->m_quad, 170), v4));
  v6.m_quad = _mm_sub_ps(qi.m_vec.m_quad, _mm_mul_ps(_mm_shuffle_ps(p->m_quad, p->m_quad, 255), v4));
  m->m_col1.m_quad = _mm_sub_ps(direction.m_quad, _mm_mul_ps(_mm_shuffle_ps(v2, v2, 85), v4));
  m->m_col2 = (hkVector4f)v5.m_quad;
  m->m_col3 = (hkVector4f)v6.m_quad;
  m->m_col0.m_quad = _mm_sub_ps(transform.m_quad, _mm_mul_ps(_mm_shuffle_ps(v2, v2, 0), v4));
}

// File Line: 44
// RVA: 0xC10CC0
hkaiEdgePathSteeringUtil::CalcForwardVectorResult __fastcall hkaiEdgePathSteeringUtil::calcForwardVector(hkaiEdgePath *edgePath, hkaiEdgePath::TraversalState *traversalState, hkVector4f *positionIn, int positionSectionIndex, hkaiStreamingCollection *streamingCollection, hkVector4f *forwardVector, hkVector4f *futureVector, hkVector4f *nextCorner, hkVector4f *nextUserEdgePlane, int *nextEdgeIndex, bool *nextIsLeft)
{
  hkaiEdgePath::TraversalState *v11; // r13
  int v12; // er15
  hkVector4f *v13; // rbx
  hkaiEdgePath *v14; // rdi
  hkaiEdgePath::Edge *v15; // rax
  __m128 v16; // xmm7
  hkaiEdgePath::Edge *v17; // rsi
  char v18; // r14
  hkaiEdgePathSteeringUtil::CalcForwardVectorResult result; // eax
  hkVector4f v20; // xmm13
  hkaiEdgePath::Edge *v21; // r8
  hkaiEdgePath::Edge *v22; // r11
  __m128 *v23; // r10
  bool v24; // bl
  char v25; // dl
  __m128 v26; // xmm0
  __m128 v27; // xmm6
  __m128 v28; // xmm5
  __m128 v29; // xmm14
  hkVector4f v30; // xmm15
  hkVector4f v31; // xmm10
  hkVector4f v32; // xmm9
  hkVector4f *v33; // rax
  hkVector4f v34; // xmm12
  __m128 v35; // xmm11
  __m128 v36; // xmm2
  hkaiEdgePath::Edge *v37; // r15
  __m128 v38; // xmm4
  __m128 v39; // xmm0
  __m128 v40; // xmm2
  __m128 v41; // xmm4
  __m128 v42; // xmm0
  __m128 v43; // xmm8
  __m128 v44; // xmm1
  __m128 v45; // xmm3
  __m128 v46; // xmm1
  __m128 v47; // xmm2
  __m128 v48; // xmm1
  __m128 v49; // xmm4
  __m128 v50; // xmm2
  __m128 v51; // xmm1
  __m128 v52; // xmm3
  __m128 v53; // xmm6
  __m128 v54; // xmm1
  __m128 v55; // xmm6
  __m128 v56; // xmm6
  __m128 v57; // xmm2
  __m128 v58; // xmm5
  __m128i v59; // xmm1
  __m128 v60; // xmm7
  __m128 v61; // xmm4
  __m128 v62; // xmm3
  __m128 v63; // xmm11
  __m128i v64; // xmm0
  __m128i v65; // xmm2
  __m128 v66; // xmm1
  __m128 v67; // xmm11
  __m128 v68; // xmm1
  __m128 v69; // xmm1
  __m128 v70; // xmm6
  __m128 v71; // xmm0
  __m128 v72; // xmm3
  __m128 v73; // xmm2
  __m128 v74; // xmm6
  __m128 v75; // xmm2
  bool v76; // zf
  __m128 v77; // xmm1
  __m128 v78; // xmm5
  __m128 v79; // xmm0
  __m128 v80; // xmm2
  __m128 v81; // xmm3
  __m128 v82; // xmm0
  __m128 v83; // xmm5
  __m128 v84; // xmm7
  __m128 v85; // xmm0
  __m128 v86; // xmm3
  __m128 v87; // xmm13
  __m128 v88; // xmm5
  __m128 v89; // xmm1
  __m128 v90; // xmm4
  __m128 v91; // xmm0
  __m128 v92; // xmm0
  __m128 v93; // xmm2
  __m128 v94; // xmm11
  __m128 v95; // xmm8
  __m128 v96; // xmm8
  signed __int64 v97; // r10
  signed __int128 v98; // ax
  __m128 v99; // xmm6
  __m128 v100; // xmm13
  __m128 *v101; // rax
  float v102; // xmm2_4
  float v103; // xmm1_4
  __m128 v104; // xmm0
  __m128 v105; // xmm1
  __m128 *v106; // rax
  __m128 v107; // xmm2
  __m128 v108; // xmm0
  __m128 v109; // xmm0
  __m128 v110; // xmm14
  __m128 v111; // xmm14
  __m128 v112; // xmm1
  __m128 v113; // xmm3
  __m128 v114; // xmm2
  __m128 v115; // xmm14
  __m128 v116; // xmm2
  __m128 *v117; // r8
  __m128 *v118; // r9
  __m128i v119; // xmm0
  __m128 v120; // xmm2
  __m128 v121; // xmm4
  __m128 v122; // xmm3
  __m128 v123; // xmm0
  __m128 v124; // xmm1
  __m128 v125; // xmm13
  __m128 v126; // xmm3
  __m128 v127; // xmm2
  __m128 v128; // xmm2
  __m128 v129; // xmm1
  __m128 v130; // xmm2
  __m128 v131; // xmm2
  __m128 v132; // xmm1
  __m128 v133; // xmm2
  __m128 v134; // xmm4
  __m128 v135; // xmm13
  __m128 v136; // xmm5
  __m128 v137; // xmm3
  __m128 v138; // xmm4
  __m128 v139; // xmm1
  __m128 v140; // xmm2
  __m128 v141; // xmm1
  __m128 v142; // xmm3
  __m128 v143; // xmm2
  __m128 v144; // xmm1
  __m128 v145; // xmm4
  __m128 v146; // xmm10
  __m128 v147; // xmm1
  __m128 v148; // xmm10
  __m128 v149; // xmm10
  __m128 v150; // xmm2
  __m128 v151; // xmm8
  __m128i v152; // xmm1
  __m128 v153; // xmm7
  __m128 v154; // xmm11
  __m128 v155; // xmm12
  __m128 v156; // xmm9
  __m128 v157; // xmm9
  char v158; // di
  __m128 v159; // xmm6
  __m128i v160; // xmm0
  __m128 v161; // xmm1
  __m128 v162; // xmm5
  __m128 v163; // xmm6
  __m128 v164; // xmm1
  __m128 v165; // xmm1
  __m128 v166; // xmm10
  __m128 v167; // xmm0
  __m128 v168; // xmm3
  __m128 v169; // xmm2
  __m128 v170; // xmm4
  __m128 v171; // xmm10
  __m128 v172; // xmm1
  __m128 v173; // xmm3
  __m128 v174; // xmm0
  __m128 v175; // xmm4
  __m128 v176; // xmm2
  __m128 v177; // xmm10
  __m128 v178; // xmm9
  __m128 v179; // xmm5
  char v180; // di
  __m128 v181; // xmm2
  __m128 v182; // xmm8
  __m128 v183; // xmm0
  __m128 v184; // xmm9
  __m128 v185; // xmm11
  __m128 v186; // xmm6
  __m128 v187; // xmm0
  __m128 v188; // xmm9
  __m128 v189; // xmm0
  __m128 v190; // xmm2
  __m128 v191; // xmm4
  __m128 v192; // xmm1
  __m128 v193; // xmm3
  __m128 v194; // xmm4
  __m128 v195; // xmm0
  __m128 v196; // xmm3
  __m128 v197; // xmm4
  __m128 v198; // xmm2
  __m128 v199; // xmm9
  __m128 v200; // xmm2
  __m128 v201; // xmm10
  bool v202; // al
  __m128 v203; // xmm2
  __m128 v204; // xmm12
  __m128 v205; // xmm0
  __m128 v206; // xmm2
  __m128 v207; // xmm13
  __m128 v208; // xmm14
  __m128 v209; // xmm14
  __m128 v210; // xmm1
  __m128 v211; // xmm3
  __m128 v212; // xmm2
  __m128 v213; // xmm14
  __m128 v214; // xmm8
  __m128 v215; // xmm0
  __m128 *v216; // rax
  __m128 v217; // xmm0
  __m128 v218; // xmm6
  __m128 v219; // xmm0
  signed __int128 v220; // ax
  __m128 v221; // xmm3
  __m128 v222; // xmm0
  __m128 v223; // xmm0
  __m128 v224; // xmm5
  __m128 v225; // xmm3
  __m128 v226; // xmm5
  __m128 *v227; // rax
  bool v228; // cl
  __m128 v229; // xmm0
  __m128 v230; // xmm1
  char *v231; // rax
  __m128 v232; // [rsp+20h] [rbp-B8h]
  __m128 v233; // [rsp+30h] [rbp-A8h]
  hkVector4f v234; // [rsp+40h] [rbp-98h]
  __m128 v235; // [rsp+50h] [rbp-88h]
  __m256i v236; // [rsp+60h] [rbp-78h]
  hkaiEdgePath::Edge *end; // [rsp+88h] [rbp-50h]
  __m128 v238; // [rsp+98h] [rbp-40h]
  __m128 v239; // [rsp+A8h] [rbp-30h]
  __m128 v240; // [rsp+B8h] [rbp-20h]
  __m128 v241; // [rsp+C8h] [rbp-10h]
  __m128 v242; // [rsp+D8h] [rbp+0h]
  __m128 v243; // [rsp+E8h] [rbp+10h]
  __m128 v244; // [rsp+F8h] [rbp+20h]
  __m128 v245; // [rsp+108h] [rbp+30h]
  __m128 v246; // [rsp+118h] [rbp+40h]
  __m128 v247; // [rsp+128h] [rbp+50h]
  hkVector4f p; // [rsp+138h] [rbp+60h]
  __m128 v249; // [rsp+148h] [rbp+70h]
  __m128 v250; // [rsp+158h] [rbp+80h]
  __m128 v251; // [rsp+168h] [rbp+90h]
  hkMatrix4f relativeTransformOut; // [rsp+178h] [rbp+A0h]
  __m128 v253; // [rsp+1B8h] [rbp+E0h]
  __m128i v254; // [rsp+1C8h] [rbp+F0h]
  __m128 v255; // [rsp+1D8h] [rbp+100h]
  hkaiEdgePath::Edge *begin; // [rsp+2C8h] [rbp+1F0h]
  hkaiStreamingCollection *retaddr; // [rsp+2D8h] [rbp+200h]
  __m128 *v258; // [rsp+2E0h] [rbp+208h]
  __m128 *v259; // [rsp+2E8h] [rbp+210h]
  __m128 *v260; // [rsp+2F0h] [rbp+218h]
  _OWORD *v261; // [rsp+2F8h] [rbp+220h]

  v11 = traversalState;
  v12 = positionSectionIndex;
  v13 = positionIn;
  v14 = edgePath;
  v15 = hkaiEdgePath::getEdge(edgePath, 0);
  v16 = 0i64;
  *v261 = 0i64;
  v251 = v13->m_quad;
  v17 = v15;
  v18 = 0;
  hkaiEdgePath::getFutureEdgeRange(v14, v11, &begin, &end);
  if ( begin == end )
    return 4;
  v20.m_quad = (__m128)begin->m_up;
  v234.m_quad = (__m128)begin->m_up;
  result = hkaiEdgePathSteeringUtil::getRelativeTransform(v12, begin, retaddr, &relativeTransformOut);
  if ( result == RESULT_SUCCESS )
  {
    v21 = begin;
    v22 = end;
    v23 = 0i64;
    v24 = 0;
    v25 = 0;
    v26 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_001), (__m128)LODWORD(FLOAT_0_001), 0);
    v27 = 0i64;
    v28 = 0i64;
    v29 = 0i64;
    v253 = _mm_sub_ps((__m128)0i64, v26);
    p.m_quad = 0i64;
    v239 = v26;
    if ( begin == end )
    {
LABEL_11:
      *v258 = v27;
      *v259 = v16;
      *v260 = v28;
LABEL_12:
      v97 = (char *)v23 - (char *)v17;
LABEL_13:
      v98 = v97 * (signed __int128)1024819115206086201i64;
LABEL_14:
      LODWORD(streamingCollection->vfptr) = (*((_QWORD *)&v98 + 1) >> 63) + (*((_QWORD *)&v98 + 1) >> 3);
      forwardVector->m_quad.m128_i8[0] = 1;
LABEL_15:
      result = 0;
    }
    else
    {
      v30.m_quad = (__m128)relativeTransformOut.m_col3;
      v31.m_quad = (__m128)relativeTransformOut.m_col2;
      v32.m_quad = (__m128)relativeTransformOut.m_col1;
      v33 = &begin->m_followingTransform.m_col2;
      v34.m_quad = (__m128)relativeTransformOut.m_col0;
      v35 = _mm_shuffle_ps(v20.m_quad, v20.m_quad, 201);
      v233 = v35;
      while ( 1 )
      {
        v36 = v21->m_left.m_quad;
        v23 = &v21->m_left.m_quad;
        v37 = v21;
        v38 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v36, v36, 0), v34.m_quad), v30.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(v21->m_left.m_quad, v21->m_left.m_quad, 85), v32.m_quad)),
                _mm_mul_ps(_mm_shuffle_ps(v21->m_left.m_quad, v21->m_left.m_quad, 170), v31.m_quad));
        v39 = _mm_unpackhi_ps(v38, _mm_shuffle_ps(v36, v36, 255));
        v40 = v33[-4].m_quad;
        v41 = _mm_shuffle_ps(v38, v39, 196);
        v42 = _mm_shuffle_ps(v33[-4].m_quad, v40, 85);
        v232 = v41;
        v43 = _mm_sub_ps(v41, v251);
        v44 = _mm_shuffle_ps(v33[-4].m_quad, v40, 170);
        v243 = v41;
        v45 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v40, v40, 0), v34.m_quad), v30.m_quad),
                  _mm_mul_ps(v42, v32.m_quad)),
                _mm_mul_ps(v44, v31.m_quad));
        v46 = _mm_mul_ps(v20.m_quad, v43);
        *(__m128 *)&v236.m256i_u64[2] = _mm_shuffle_ps(v45, _mm_unpackhi_ps(v45, _mm_shuffle_ps(v40, v40, 255)), 196);
        v250 = *(__m128 *)&v236.m256i_u64[2];
        v242 = _mm_sub_ps(*(__m128 *)&v236.m256i_u64[2], v251);
        v47 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v46, v46, 85), _mm_shuffle_ps(v46, v46, 0)),
                _mm_shuffle_ps(v46, v46, 170));
        v48 = _mm_mul_ps(v20.m_quad, v242);
        v49 = _mm_sub_ps(v43, _mm_mul_ps(v47, v20.m_quad));
        v50 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v48, v48, 85), _mm_shuffle_ps(v48, v48, 0)),
                _mm_shuffle_ps(v48, v48, 170));
        v51 = _mm_mul_ps(v49, v49);
        v52 = _mm_sub_ps(v242, _mm_mul_ps(v50, v20.m_quad));
        v53 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v51, v51, 85), _mm_shuffle_ps(v51, v51, 0)),
                _mm_shuffle_ps(v51, v51, 170));
        v54 = _mm_mul_ps(v52, v52);
        v55 = _mm_unpacklo_ps(
                v53,
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v54, v54, 85), _mm_shuffle_ps(v54, v54, 0)),
                  _mm_shuffle_ps(v54, v54, 170)));
        v56 = _mm_movelh_ps(v55, v55);
        v57 = _mm_rsqrt_ps(v56);
        v58 = _mm_andnot_ps(
                _mm_cmpleps(v56, v16),
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v56, v57), v57)),
                  _mm_mul_ps(v57, *(__m128 *)_xmm)));
        v59 = (__m128i)_mm_shuffle_ps(v232, v232, 255);
        v60 = _mm_mul_ps(_mm_shuffle_ps(v58, v58, 0), v49);
        v61 = (__m128)_mm_slli_epi32(_mm_srli_epi32(v59, 0x1Fu), 0x1Fu);
        *(__m128 *)&v236.m256i_u64[1] = _mm_mul_ps(_mm_shuffle_ps(v58, v58, 85), v52);
        v62 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v60, v60, 201), v20.m_quad), _mm_mul_ps(v60, v35));
        v63 = _mm_sub_ps(
                _mm_mul_ps(
                  _mm_shuffle_ps(*(__m128 *)&v236.m256i_u64[1], *(__m128 *)&v236.m256i_u64[1], 201),
                  v20.m_quad),
                _mm_mul_ps(*(__m128 *)&v236.m256i_u64[1], v233));
        v64 = (__m128i)_mm_shuffle_ps(*(__m128 *)&v236.m256i_u64[2], *(__m128 *)&v236.m256i_u64[2], 255);
        v65 = _mm_slli_epi32(_mm_srli_epi32(v64, 0x1Fu), 0x1Fu);
        v66 = _mm_unpacklo_ps((__m128)v59, (__m128)v64);
        v67 = _mm_xor_ps(_mm_shuffle_ps(v63, v63, 201), (__m128)v65);
        _mm_store_si128((__m128i *)&v236.m256i_u64[3], v65);
        v68 = _mm_movelh_ps(v66, v66);
        v235 = _mm_xor_ps(_mm_shuffle_ps(v62, v62, 201), v61);
        v69 = _mm_mul_ps(v68, v68);
        v70 = _mm_sub_ps(v56, v69);
        v71 = _mm_cmpleps(v70, (__m128)0i64);
        v72 = _mm_or_ps(
                _mm_andnot_ps(v71, _mm_mul_ps(_mm_shuffle_ps(v69, v70, 228), v70)),
                _mm_and_ps(v71, `hkaiEdgePathSteeringUtil::calcTangentDirs'::`2'::insideLenFactorsQuad));
        v73 = _mm_rsqrt_ps(v72);
        v74 = _mm_mul_ps(
                _mm_andnot_ps(
                  _mm_cmpleps(v72, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v73, v72), v73)),
                      _mm_mul_ps(v73, *(__m128 *)_xmm)),
                    v72)),
                v58);
        v75 = _mm_shuffle_ps(v74, v74, 170);
        v76 = (v33[3].m_quad.m128_i8[0] & 0x10) == 0;
        v77 = _mm_shuffle_ps(v74, v74, 0);
        v78 = _mm_mul_ps(v235, v75);
        v79 = _mm_mul_ps(v60, v75);
        v80 = v33[-2].m_quad;
        v81 = _mm_add_ps(_mm_mul_ps(v235, v77), v79);
        v82 = *(__m128 *)&v236.m256i_u64[1];
        *(__m128 *)v236.m256i_i8 = v81;
        v244 = v81;
        v83 = _mm_sub_ps(v78, _mm_mul_ps(v60, v77));
        v84 = v33[-1].m_quad;
        v240 = _mm_shuffle_ps(v74, v74, 85);
        *(__m128 *)((char *)&v235 + 8) = _mm_shuffle_ps(v74, v74, 255);
        v85 = _mm_mul_ps(v82, *(__m128 *)((char *)&v235 + 8));
        v86 = v33[1].m_quad;
        v235 = _mm_xor_ps(v83, v61);
        v87 = _mm_add_ps(_mm_mul_ps(v67, v240), v85);
        v88 = v33->m_quad;
        v238 = v87;
        v246 = v87;
        v89 = _mm_mul_ps(_mm_shuffle_ps(v80, v80, 85), v32.m_quad);
        v90 = _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v88, v88, 85), v32.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v88, v88, 0), v34.m_quad));
        v91 = _mm_mul_ps(_mm_shuffle_ps(v86, v86, 85), v32.m_quad);
        v32.m_quad = _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v84, v84, 170), v31.m_quad),
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v84, v84, 85), v32.m_quad),
                         _mm_mul_ps(_mm_shuffle_ps(v84, v84, 0), v34.m_quad)));
        v16 = 0i64;
        v249 = v32.m_quad;
        v30.m_quad = _mm_add_ps(
                       _mm_add_ps(_mm_add_ps(v30.m_quad, _mm_mul_ps(_mm_shuffle_ps(v86, v86, 0), v34.m_quad)), v91),
                       _mm_mul_ps(_mm_shuffle_ps(v86, v86, 170), v31.m_quad));
        v92 = _mm_shuffle_ps(v80, v80, 0);
        v93 = _mm_mul_ps(_mm_shuffle_ps(v80, v80, 170), v31.m_quad);
        v31.m_quad = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v88, v88, 170), v31.m_quad), v90);
        v241 = v31.m_quad;
        v34.m_quad = _mm_add_ps(_mm_add_ps(v89, _mm_mul_ps(v92, v34.m_quad)), v93);
        v247 = v34.m_quad;
        if ( !v76 )
          break;
        v27 = *(__m128 *)v236.m256i_i8;
        v94 = _mm_mul_ps(
                _mm_xor_ps(
                  _mm_sub_ps(
                    _mm_mul_ps(v67, *(__m128 *)((char *)&v235 + 8)),
                    _mm_mul_ps(*(__m128 *)&v236.m256i_u64[1], v240)),
                  *(__m128 *)&v236.m256i_u64[3]),
                *(__m128 *)v236.m256i_i8);
        if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v94, v94, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v94, v94, 0)))
                   + COERCE_FLOAT(_mm_shuffle_ps(v94, v94, 170))) > v239.m128_f32[0] )
          goto LABEL_23;
        v95 = _mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(v43, v43, 201), v242),
                _mm_mul_ps(_mm_shuffle_ps(v242, v242, 201), v43));
        v96 = _mm_mul_ps(_mm_shuffle_ps(v95, v95, 201), v234.m_quad);
        if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v96, v96, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v96, v96, 0)))
                   + COERCE_FLOAT(_mm_shuffle_ps(v96, v96, 170))) >= 0.0 )
        {
          if ( v11->m_faceEdge >= 0 )
          {
            v99 = _mm_mul_ps(*(__m128 *)v236.m256i_i8, *(__m128 *)v236.m256i_i8);
            v100 = _mm_mul_ps(v87, v87);
            v101 = &v244;
            v102 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v99, v99, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v99, v99, 0)))
                 + COERCE_FLOAT(_mm_shuffle_ps(v99, v99, 170));
            v103 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v100, v100, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v100, v100, 0)))
                 + COERCE_FLOAT(_mm_shuffle_ps(v100, v100, 170));
            forwardVector->m_quad.m128_i8[0] = v102 < v103;
            if ( v102 >= v103 )
              v101 = &v246;
            v104 = *v101;
            *v258 = *v101;
            v105 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v104, v104, 201), v234.m_quad), _mm_mul_ps(v104, v233));
            *v259 = _mm_shuffle_ps(v105, v105, 201);
            v106 = &v243;
            if ( !forwardVector->m_quad.m128_i8[0] )
              v106 = &v250;
            *v260 = *v106;
            LODWORD(streamingCollection->vfptr) = ((unsigned __int64)((unsigned __int128)(((char *)v21 - (char *)v17)
                                                                                        * (signed __int128)1024819115206086201i64) >> 64) >> 63)
                                                + ((signed __int64)((unsigned __int128)(((char *)v21 - (char *)v17)
                                                                                      * (signed __int128)1024819115206086201i64) >> 64) >> 3);
            goto LABEL_15;
          }
LABEL_23:
          v28 = v232;
          goto LABEL_28;
        }
        v35 = v233;
        ++v21;
        v33 += 9;
        v20.m_quad = v234.m_quad;
        if ( v21 == v22 )
        {
          v28 = v232;
          goto LABEL_11;
        }
      }
      v107 = _mm_mul_ps(v235, v87);
      if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v107, v107, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v107, v107, 0)))
                 + COERCE_FLOAT(_mm_shuffle_ps(v107, v107, 170))) <= 0.0 )
      {
        v27 = *(__m128 *)v236.m256i_i8;
        v108 = *(__m128 *)&v236.m256i_u64[2];
        v28 = v232;
      }
      else
      {
        v108 = v232;
        v27 = v87;
        v238 = *(__m128 *)v236.m256i_i8;
        v28 = *(__m128 *)&v236.m256i_u64[2];
        *(__m128 *)v236.m256i_i8 = v87;
        v232 = *(__m128 *)&v236.m256i_u64[2];
        *(__m128 *)&v236.m256i_u64[2] = v108;
      }
      v109 = _mm_sub_ps(v108, v28);
      v18 = 1;
      v25 = 1;
      v110 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v109, v109, 201), v234.m_quad), _mm_mul_ps(v109, v233));
      v111 = _mm_shuffle_ps(v110, v110, 201);
      v112 = _mm_mul_ps(v111, v111);
      v113 = _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v112, v112, 85), _mm_shuffle_ps(v112, v112, 0)),
               _mm_shuffle_ps(v112, v112, 170));
      v114 = _mm_rsqrt_ps(v113);
      v115 = _mm_mul_ps(
               v111,
               _mm_andnot_ps(
                 _mm_cmpleps(v113, (__m128)0i64),
                 _mm_mul_ps(
                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v114, v113), v114)),
                   _mm_mul_ps(*(__m128 *)_xmm, v114))));
      v116 = _mm_mul_ps(v115, v28);
      v29 = _mm_shuffle_ps(
              v115,
              _mm_unpackhi_ps(
                v115,
                _mm_sub_ps(
                  (__m128)0i64,
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v116, v116, 85), _mm_shuffle_ps(v116, v116, 0)),
                    _mm_shuffle_ps(v116, v116, 170)))),
              196);
      p.m_quad = v29;
      *v261 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v29);
LABEL_28:
      v117 = &v21[1].m_left.m_quad;
      if ( v117 == (__m128 *)v22 )
        goto LABEL_11;
      v118 = v117 + 5;
      v119 = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
      _mm_store_si128(&v254, v119);
      _mm_store_si128((__m128i *)&v255, _mm_shuffle_epi32(v119, 64));
      while ( 2 )
      {
        v120 = *v117;
        v121 = v118[-4];
        v122 = _mm_shuffle_ps(v120, v120, 0);
        v123 = _mm_shuffle_ps(*v117, *v117, 85);
        v124 = _mm_shuffle_ps(*v117, *v117, 170);
        v250 = v122;
        v243 = v123;
        v246 = v124;
        v245 = v120;
        v235 = v121;
        v125 = _mm_add_ps(
                 _mm_add_ps(_mm_add_ps(_mm_mul_ps(v122, v34.m_quad), v30.m_quad), _mm_mul_ps(v123, v32.m_quad)),
                 _mm_mul_ps(v124, v31.m_quad));
        v244 = _mm_shuffle_ps(v121, v121, 0);
        v242 = _mm_shuffle_ps(v121, v121, 85);
        *(__m128 *)((char *)&v235 + 8) = _mm_shuffle_ps(v121, v121, 170);
        v126 = _mm_add_ps(
                 _mm_add_ps(_mm_add_ps(_mm_mul_ps(v244, v34.m_quad), v30.m_quad), _mm_mul_ps(v242, v32.m_quad)),
                 _mm_mul_ps(*(__m128 *)((char *)&v235 + 8), v31.m_quad));
        if ( v25 )
        {
          v127 = _mm_mul_ps(v125, v29);
          v128 = _mm_shuffle_ps(v127, _mm_unpackhi_ps(v127, v29), 196);
          v129 = _mm_add_ps(_mm_shuffle_ps(v128, v128, 78), v128);
          if ( (float)(COERCE_FLOAT(_mm_shuffle_ps(v129, v129, 177)) + v129.m128_f32[0]) < v16.m128_f32[0] )
          {
            v130 = _mm_mul_ps(v126, v29);
            v131 = _mm_shuffle_ps(v130, _mm_unpackhi_ps(v130, v29), 196);
            v132 = _mm_add_ps(_mm_shuffle_ps(v131, v131, 78), v131);
            if ( (float)(COERCE_FLOAT(_mm_shuffle_ps(v132, v132, 177)) + v132.m128_f32[0]) < v16.m128_f32[0] )
            {
              makeReflectionMatrix(&p, &relativeTransformOut);
              v24 = v24 == 0;
              v30.m_quad = _mm_add_ps(
                             _mm_add_ps(
                               _mm_add_ps(
                                 relativeTransformOut.m_col3.m_quad,
                                 _mm_mul_ps(
                                   _mm_shuffle_ps(v30.m_quad, v30.m_quad, 0),
                                   relativeTransformOut.m_col0.m_quad)),
                               _mm_mul_ps(
                                 _mm_shuffle_ps(v30.m_quad, v30.m_quad, 85),
                                 relativeTransformOut.m_col1.m_quad)),
                             _mm_mul_ps(_mm_shuffle_ps(v30.m_quad, v30.m_quad, 170), relativeTransformOut.m_col2.m_quad));
              v16 = 0i64;
              v249 = _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v32.m_quad, v32.m_quad, 85), relativeTransformOut.m_col1.m_quad),
                         _mm_mul_ps(_mm_shuffle_ps(v32.m_quad, v32.m_quad, 0), relativeTransformOut.m_col0.m_quad)),
                       _mm_mul_ps(_mm_shuffle_ps(v32.m_quad, v32.m_quad, 170), relativeTransformOut.m_col2.m_quad));
              v247 = _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v34.m_quad, v34.m_quad, 85), relativeTransformOut.m_col1.m_quad),
                         _mm_mul_ps(_mm_shuffle_ps(v34.m_quad, v34.m_quad, 0), relativeTransformOut.m_col0.m_quad)),
                       _mm_mul_ps(_mm_shuffle_ps(v34.m_quad, v34.m_quad, 170), relativeTransformOut.m_col2.m_quad));
              v121 = v235;
              v241 = _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v31.m_quad, v241, 85), relativeTransformOut.m_col1.m_quad),
                         _mm_mul_ps(_mm_shuffle_ps(v241, v241, 0), relativeTransformOut.m_col0.m_quad)),
                       _mm_mul_ps(_mm_shuffle_ps(v241, v241, 170), relativeTransformOut.m_col2.m_quad));
              v125 = _mm_add_ps(
                       _mm_add_ps(_mm_add_ps(_mm_mul_ps(v250, v247), v30.m_quad), _mm_mul_ps(v243, v249)),
                       _mm_mul_ps(v246, v241));
              v126 = _mm_add_ps(
                       _mm_add_ps(_mm_add_ps(_mm_mul_ps(v244, v247), v30.m_quad), _mm_mul_ps(v242, v249)),
                       _mm_mul_ps(*(__m128 *)((char *)&v235 + 8), v241));
            }
          }
          v120 = v245;
          v25 = 0;
        }
        v133 = _mm_shuffle_ps(v120, v120, 255);
        v134 = _mm_shuffle_ps(v121, v121, 255);
        if ( v24 )
        {
          v135 = _mm_shuffle_ps(v125, _mm_unpackhi_ps(v125, _mm_sub_ps(v16, v133)), 196);
          v136 = _mm_shuffle_ps(v126, _mm_unpackhi_ps(v126, _mm_sub_ps(v16, v134)), 196);
        }
        else
        {
          v136 = _mm_shuffle_ps(v125, _mm_unpackhi_ps(v125, v133), 196);
          v135 = _mm_shuffle_ps(v126, _mm_unpackhi_ps(v126, v134), 196);
        }
        v137 = _mm_sub_ps(v136, v251);
        v138 = _mm_sub_ps(v135, v251);
        *(__m128 *)&v236.m256i_u64[1] = v135;
        *(__m128 *)&v236.m256i_u64[3] = v136;
        v139 = _mm_mul_ps(v137, v234.m_quad);
        v235 = v136;
        v140 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v139, v139, 85), _mm_shuffle_ps(v139, v139, 0)),
                 _mm_shuffle_ps(v139, v139, 170));
        v141 = _mm_mul_ps(v138, v234.m_quad);
        v142 = _mm_sub_ps(v137, _mm_mul_ps(v140, v234.m_quad));
        v143 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v141, v141, 85), _mm_shuffle_ps(v141, v141, 0)),
                 _mm_shuffle_ps(v141, v141, 170));
        v144 = _mm_mul_ps(v142, v142);
        v145 = _mm_sub_ps(v138, _mm_mul_ps(v143, v234.m_quad));
        v146 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v144, v144, 85), _mm_shuffle_ps(v144, v144, 0)),
                 _mm_shuffle_ps(v144, v144, 170));
        v147 = _mm_mul_ps(v145, v145);
        v148 = _mm_unpacklo_ps(
                 v146,
                 _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v147, v147, 85), _mm_shuffle_ps(v147, v147, 0)),
                   _mm_shuffle_ps(v147, v147, 170)));
        v149 = _mm_movelh_ps(v148, v148);
        v150 = _mm_rsqrt_ps(v149);
        v151 = _mm_andnot_ps(
                 _mm_cmpleps(v149, v16),
                 _mm_mul_ps(
                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v150, v149), v150)),
                   _mm_mul_ps(v150, *(__m128 *)_xmm)));
        v152 = (__m128i)_mm_shuffle_ps(v136, v136, 255);
        v153 = (__m128)_mm_slli_epi32(_mm_srli_epi32(v152, 0x1Fu), 0x1Fu);
        v154 = _mm_mul_ps(_mm_shuffle_ps(v151, v151, 0), v142);
        v155 = _mm_mul_ps(_mm_shuffle_ps(v151, v151, 85), v145);
        v156 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v154, v154, 201), v234.m_quad), _mm_mul_ps(v154, v233));
        v157 = _mm_xor_ps(_mm_shuffle_ps(v156, v156, 201), v153);
        v158 = v118[3].m128_i8[0];
        v159 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v155, v155, 201), v234.m_quad), _mm_mul_ps(v155, v233));
        v160 = (__m128i)_mm_shuffle_ps(v135, v135, 255);
        v161 = _mm_unpacklo_ps((__m128)v152, (__m128)v160);
        v162 = (__m128)_mm_slli_epi32(_mm_srli_epi32(v160, 0x1Fu), 0x1Fu);
        v163 = _mm_xor_ps(_mm_shuffle_ps(v159, v159, 201), v162);
        v164 = _mm_movelh_ps(v161, v161);
        v165 = _mm_mul_ps(v164, v164);
        v166 = _mm_sub_ps(v149, v165);
        v167 = _mm_cmpleps(v166, (__m128)0i64);
        v168 = _mm_or_ps(
                 _mm_andnot_ps(v167, _mm_mul_ps(_mm_shuffle_ps(v165, v166, 228), v166)),
                 _mm_and_ps(v167, `hkaiEdgePathSteeringUtil::calcTangentDirs'::`2'::insideLenFactorsQuad));
        v169 = _mm_rsqrt_ps(v168);
        v170 = _mm_mul_ps(
                 _mm_andnot_ps(
                   _mm_cmpleps(v168, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_mul_ps(
                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v169, v168), v169)),
                       _mm_mul_ps(v169, *(__m128 *)_xmm)),
                     v168)),
                 v151);
        v171 = _mm_shuffle_ps(v170, v170, 170);
        v172 = _mm_shuffle_ps(v170, v170, 0);
        v173 = _mm_add_ps(_mm_mul_ps(v172, v157), _mm_mul_ps(v171, v154));
        v239 = v173;
        v174 = _mm_shuffle_ps(v170, v170, 255);
        v175 = _mm_shuffle_ps(v170, v170, 85);
        v245 = v174;
        v176 = _mm_add_ps(_mm_mul_ps(v175, v163), _mm_mul_ps(v174, v155));
        *(__m128 *)((char *)&v235 + 8) = v176;
        v240 = v176;
        v177 = _mm_xor_ps(_mm_sub_ps(_mm_mul_ps(v171, v157), _mm_mul_ps(v172, v154)), v153);
        v178 = _mm_xor_ps(_mm_sub_ps(_mm_mul_ps(v174, v163), _mm_mul_ps(v175, v155)), v162);
        v179 = v176;
        v180 = v158 & 0x10;
        if ( v180
          && (v181 = _mm_mul_ps(v177, v176),
              (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v181, v181, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v181, v181, 0)))
                    + COERCE_FLOAT(_mm_shuffle_ps(v181, v181, 170))) > 0.0) )
        {
          v182 = v135;
          *(__m128 *)&v236.m256i_u64[3] = v135;
          v135 = v235;
          v239 = v179;
          v179 = v173;
          v240 = v173;
          v183 = v177;
          v177 = v178;
          *(__m128 *)&v236.m256i_u64[1] = v235;
          v178 = v183;
        }
        else
        {
          v182 = v235;
        }
        v184 = _mm_xor_ps(v178, v255);
        v185 = *(__m128 *)v236.m256i_i8;
        v186 = v238;
        v187 = v184;
        v188 = _mm_mul_ps(v184, v238);
        v189 = _mm_mul_ps(v187, *(__m128 *)v236.m256i_i8);
        v190 = _mm_mul_ps(v177, v238);
        v191 = _mm_mul_ps(v177, *(__m128 *)v236.m256i_i8);
        v192 = _mm_shuffle_ps(v190, v188, 68);
        v193 = _mm_shuffle_ps(v191, v189, 68);
        v194 = _mm_shuffle_ps(v191, v189, 238);
        v195 = _mm_add_ps(_mm_shuffle_ps(v193, v192, 221), _mm_shuffle_ps(v193, v192, 136));
        v196 = v239;
        v197 = _mm_add_ps(_mm_shuffle_ps(v194, _mm_shuffle_ps(v190, v188, 238), 136), v195);
        v198 = _mm_sub_ps(v239, v179);
        v199 = _mm_cmpleps((__m128)0i64, v197);
        v200 = _mm_mul_ps(v198, v198);
        v202 = 0;
        if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v200, v200, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v200, v200, 0)))
                   + COERCE_FLOAT(_mm_shuffle_ps(v200, v200, 170))) > v253.m128_f32[0] )
        {
          v201 = _mm_mul_ps(v177, v179);
          if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v201, v201, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v201, v201, 0)))
                     + COERCE_FLOAT(_mm_shuffle_ps(v201, v201, 170))) > v253.m128_f32[0] )
            v202 = 1;
        }
        switch ( (v202 != 0 ? 0x10 : 0) | _mm_movemask_ps(v199) )
        {
          case 1:
          case 3:
            *(__m128 *)v236.m256i_i8 = v239;
            v232 = v182;
            goto LABEL_50;
          case 2:
          case 0xA:
          case 0xB:
          case 0xE:
          case 0x12:
          case 0x13:
          case 0x18:
          case 0x1A:
          case 0x1E:
            v216 = v258;
            goto LABEL_59;
          case 4:
          case 5:
          case 7:
          case 0xD:
          case 0x11:
          case 0x14:
          case 0x15:
          case 0x17:
          case 0x1C:
            v216 = v258;
            goto LABEL_61;
          case 6:
          case 0x16:
          case 0x19:
          case 0x1B:
            v225 = _mm_mul_ps(v239, v239);
            v226 = _mm_mul_ps(v179, v179);
            v227 = &v239;
            v228 = (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v225, v225, 85))
                                 + COERCE_FLOAT(_mm_shuffle_ps(v225, v225, 0)))
                         + COERCE_FLOAT(_mm_shuffle_ps(v225, v225, 170))) < (float)((float)(COERCE_FLOAT(
                                                                                              _mm_shuffle_ps(
                                                                                                v226,
                                                                                                v226,
                                                                                                85))
                                                                                          + COERCE_FLOAT(
                                                                                              _mm_shuffle_ps(
                                                                                                v226,
                                                                                                v226,
                                                                                                0)))
                                                                                  + COERCE_FLOAT(_mm_shuffle_ps(v226, v226, 170)));
            forwardVector->m_quad.m128_i8[0] = v228;
            if ( !v228 )
              v227 = &v240;
            v229 = *v227;
            *v258 = *v227;
            v230 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v229, v229, 201), v234.m_quad), _mm_mul_ps(v233, v229));
            *v259 = _mm_shuffle_ps(v230, v230, 201);
            v231 = &v236.m256i_i8[24];
            if ( !forwardVector->m_quad.m128_i8[0] )
              v231 = &v236.m256i_i8[8];
            *v260 = *(__m128 *)v231;
            LODWORD(streamingCollection->vfptr) = ((unsigned __int64)((unsigned __int128)(((char *)v117 - (char *)v17)
                                                                                        * (signed __int128)1024819115206086201i64) >> 64) >> 63)
                                                + ((signed __int64)((unsigned __int128)(((char *)v117 - (char *)v17)
                                                                                      * (signed __int128)1024819115206086201i64) >> 64) >> 3);
            goto LABEL_15;
          case 8:
          case 0xC:
            v238 = v179;
            v37 = (hkaiEdgePath::Edge *)v117;
            *(__m128 *)&v236.m256i_u64[2] = v135;
            goto LABEL_51;
          case 9:
            *(__m128 *)v236.m256i_i8 = v239;
            v37 = (hkaiEdgePath::Edge *)v117;
            v232 = v182;
            v238 = v179;
            *(__m128 *)&v236.m256i_u64[2] = v135;
LABEL_50:
            v23 = v117;
            goto LABEL_51;
          case 0xF:
          case 0x10:
            v216 = v258;
            v221 = _mm_mul_ps(v239, v238);
            if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v221, v221, 85))
                               + COERCE_FLOAT(_mm_shuffle_ps(v221, v221, 0)))
                       + COERCE_FLOAT(_mm_shuffle_ps(v221, v221, 170))) <= 0.0 )
            {
LABEL_59:
              *v216 = *(__m128 *)v236.m256i_i8;
              v217 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v185, v185, 201), v234.m_quad), _mm_mul_ps(v185, v233));
              *v259 = _mm_shuffle_ps(v217, v217, 201);
              *v260 = v232;
              goto LABEL_12;
            }
LABEL_61:
            *v216 = v238;
            v218 = _mm_sub_ps(_mm_mul_ps(v186, v233), _mm_mul_ps(_mm_shuffle_ps(v186, v186, 201), v234.m_quad));
            v219 = *(__m128 *)&v236.m256i_u64[2];
            *v259 = _mm_shuffle_ps(v218, v218, 201);
            *v260 = v219;
            v220 = ((char *)v37 - (char *)v17) * (signed __int128)1024819115206086201i64;
LABEL_62:
            LODWORD(streamingCollection->vfptr) = (*((_QWORD *)&v220 + 1) >> 63) + (*((_QWORD *)&v220 + 1) >> 3);
            forwardVector->m_quad.m128_i8[0] = 0;
            goto LABEL_15;
          case 0x1D:
            *v258 = v179;
            v224 = _mm_sub_ps(_mm_mul_ps(v179, v233), _mm_mul_ps(_mm_shuffle_ps(v179, v179, 201), v234.m_quad));
            *v259 = _mm_shuffle_ps(v224, v224, 201);
            *v260 = v135;
            v220 = ((char *)v117 - (char *)v17) * (signed __int128)1024819115206086201i64;
            goto LABEL_62;
          case 0x1F:
            v222 = _mm_mul_ps(_mm_shuffle_ps(v239, v239, 201), v234.m_quad);
            *v258 = v239;
            v223 = _mm_sub_ps(v222, _mm_mul_ps(v196, v233));
            *v259 = _mm_shuffle_ps(v223, v223, 201);
            *v260 = v182;
            v98 = ((char *)v117 - (char *)v17) * (signed __int128)1024819115206086201i64;
            goto LABEL_14;
          default:
LABEL_51:
            v203 = v118[-2];
            v204 = _mm_mul_ps(_mm_shuffle_ps(v203, v203, 85), v249);
            v205 = _mm_shuffle_ps(v118[-2], v203, 0);
            v30.m_quad = _mm_add_ps(
                           _mm_add_ps(
                             _mm_add_ps(v30.m_quad, _mm_mul_ps(_mm_shuffle_ps(v118[1], v118[1], 0), v247)),
                             _mm_mul_ps(_mm_shuffle_ps(v118[1], v118[1], 85), v249)),
                           _mm_mul_ps(_mm_shuffle_ps(v118[1], v118[1], 170), v241));
            v206 = _mm_mul_ps(_mm_shuffle_ps(v203, v203, 170), v241);
            v32.m_quad = _mm_add_ps(
                           _mm_add_ps(
                             _mm_mul_ps(_mm_shuffle_ps(v118[-1], v118[-1], 85), v249),
                             _mm_mul_ps(_mm_shuffle_ps(v118[-1], v118[-1], 0), v247)),
                           _mm_mul_ps(_mm_shuffle_ps(v118[-1], v118[-1], 170), v241));
            v31.m_quad = _mm_add_ps(
                           _mm_add_ps(
                             _mm_mul_ps(_mm_shuffle_ps(*v118, *v118, 85), v249),
                             _mm_mul_ps(_mm_shuffle_ps(*v118, *v118, 0), v247)),
                           _mm_mul_ps(_mm_shuffle_ps(*v118, *v118, 170), v241));
            v16 = 0i64;
            v249 = v32.m_quad;
            v241 = v31.m_quad;
            v34.m_quad = _mm_add_ps(_mm_add_ps(v204, _mm_mul_ps(v205, v247)), v206);
            v247 = v34.m_quad;
            if ( v180 )
            {
              v207 = _mm_sub_ps(v135, v182);
              v208 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v207, v207, 201), v234.m_quad), _mm_mul_ps(v207, v233));
              v209 = _mm_shuffle_ps(v208, v208, 201);
              v210 = _mm_mul_ps(v209, v209);
              v211 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v210, v210, 85), _mm_shuffle_ps(v210, v210, 0)),
                       _mm_shuffle_ps(v210, v210, 170));
              v212 = _mm_rsqrt_ps(v211);
              v213 = _mm_mul_ps(
                       v209,
                       _mm_andnot_ps(
                         _mm_cmpleps(v211, (__m128)0i64),
                         _mm_mul_ps(
                           _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v212, v211), v212)),
                           _mm_mul_ps(v212, *(__m128 *)_xmm))));
              v214 = _mm_mul_ps(v182, v213);
              v29 = _mm_shuffle_ps(
                      v213,
                      _mm_unpackhi_ps(
                        v213,
                        _mm_sub_ps(
                          (__m128)0i64,
                          _mm_add_ps(
                            _mm_add_ps(_mm_shuffle_ps(v214, v214, 85), _mm_shuffle_ps(v214, v214, 0)),
                            _mm_shuffle_ps(v214, v214, 170)))),
                      196);
              p.m_quad = v29;
              if ( !v18 )
              {
                v18 = 1;
                *v261 = _mm_xor_ps((__m128)_mm_shuffle_epi32(v254, 0), v29);
              }
              v25 = 1;
            }
            v117 += 9;
            v118 += 9;
            if ( v117 != (__m128 *)v22 )
              continue;
            v215 = _mm_cmpeqps(v23[1], *v23);
            v97 = (char *)v23 - (char *)v17;
            if ( _mm_movemask_ps(v215) == 15 )
            {
              *v258 = *(__m128 *)v236.m256i_i8;
              *v260 = v232;
              *v259 = 0i64;
              goto LABEL_13;
            }
            *v258 = _mm_add_ps(
                      _mm_mul_ps(_mm_sub_ps(v238, *(__m128 *)v236.m256i_i8), (__m128)xmmword_141A711B0),
                      *(__m128 *)v236.m256i_i8);
            *v260 = _mm_add_ps(
                      _mm_mul_ps(_mm_sub_ps(*(__m128 *)&v236.m256i_u64[2], v232), (__m128)xmmword_141A711B0),
                      v232);
            *v259 = 0i64;
            LODWORD(streamingCollection->vfptr) = ((unsigned __int64)((unsigned __int128)(v97
                                                                                        * (signed __int128)1024819115206086201i64) >> 64) >> 63)
                                                + ((signed __int64)((unsigned __int128)(v97
                                                                                      * (signed __int128)1024819115206086201i64) >> 64) >> 3);
            forwardVector->m_quad.m128_i8[0] = 1;
            result = 1;
            break;
        }
        break;
      }
    }
  }
  return result;
}_mm_mul_ps(_mm_sub_ps(v238, *(__m128 *)v236.m256i_i8), (__m128)xmmword_141A711B0),
                      *(__m128 *)v236.m256i_i8);
            *v260 = _mm_add_ps(
                      _mm_mul_ps(_mm_sub_ps(*(__m128 *)&v236.m256i_u64[2], v232), (__m128)xmmword_141A711B0),
                      v232);
            *v259 = 0i64;
            LODWORD(streamingCollection->vfptr) = ((unsigned __int64)((unsigned __int128)(v97

// File Line: 487
// RVA: 0xC12140
hkaiEdgePathSteeringUtil::CalcForwardVectorResult __fastcall hkaiEdgePathSteeringUtil::calcForwardVector(hkaiEdgePath *edgePath, hkaiEdgePath::TraversalState *traversalState, hkVector4f *positionLocal, int positionSectionIndex, hkaiStreamingCollection *streamingCollection, hkVector4f *forwardVectorLocal, hkVector4f *futureVectorLocal, hkVector4f *nextCornerLocal, hkVector4f *nextUserEdgePlane)
{
  __int64 v10; // [rsp+60h] [rbp-18h]
  int v11; // [rsp+64h] [rbp-14h]

  return hkaiEdgePathSteeringUtil::calcForwardVector(
           edgePath,
           traversalState,
           positionLocal,
           positionSectionIndex,
           streamingCollection,
           forwardVectorLocal,
           futureVectorLocal,
           nextCornerLocal,
           nextUserEdgePlane,
           &v11,
           (bool *)&v10);
}

// File Line: 511
// RVA: 0xC121B0
signed __int64 __fastcall hkaiEdgePathSteeringUtil::calcForwardVector_corner(hkaiEdgePath *edgePath, int edgeIndex, bool edgeIsLeft, int *nextEdgeIndex, bool *nextIsLeft)
{
  int *v5; // r14
  bool v6; // di
  int v7; // esi
  hkaiEdgePath *v8; // r13
  hkaiEdgePath::Edge *v9; // rax
  int v10; // er15
  char v11; // r12
  __m128 v12; // xmm14
  hkaiEdgePath::Edge *v13; // rbx
  __m128 v14; // xmm11
  int v15; // er13
  bool v17; // zf
  __m128 *v18; // rdi
  __m128 v19; // xmm15
  __m128 v20; // xmm15
  __m128 v21; // xmm2
  __m128 v22; // xmm3
  __m128 v23; // xmm2
  __m128 v24; // xmm1
  __m128 v25; // xmm13
  __m128 v26; // xmm0
  __m128 v27; // xmm9
  __m128 v28; // xmm13
  __m128 v29; // xmm6
  __m128 v30; // xmm7
  __m128 v31; // xmm11
  __m128 v32; // xmm11
  __m128 v33; // xmm11
  __m128 v34; // xmm1
  __m128 v35; // xmm3
  __m128 v36; // xmm2
  __m128 v37; // xmm11
  __m128 v38; // xmm2
  int v39; // ebx
  char *v40; // rax
  __m128 v41; // xmm0
  hkaiEdgePath::Edge *v42; // rdi
  __m128 v43; // xmm12
  __m128 v44; // xmm1
  __m128 v45; // xmm2
  __m128 v46; // xmm0
  __m128 v47; // xmm1
  __m128 v48; // xmm13
  __m128 v49; // xmm8
  __m128 v50; // xmm2
  __m128 v51; // xmm1
  __m128 v52; // xmm3
  __m128 v53; // xmm2
  __m128 v54; // xmm2
  __m128 v55; // xmm1
  __m128 v56; // xmm2
  __m128 v57; // xmm2
  __m128 v58; // xmm1
  __m128 v59; // xmm9
  __m128 v60; // xmm8
  __m128 v61; // xmm12
  __m128 v62; // xmm13
  __m128 v63; // xmm8
  __m128 v64; // xmm12
  __m128 v65; // xmm3
  float v66; // xmm4_4
  __m128 v67; // xmm1
  __m128 v68; // xmm3
  __m128 v69; // xmm3
  __m128 v70; // xmm7
  __m128 v71; // xmm6
  __m128 v72; // xmm9
  __m128 v73; // xmm9
  __m128 v74; // xmm7
  __m128 v75; // xmm3
  __m128 v76; // xmm3
  char v77; // dl
  __m128 v78; // xmm2
  __m128 v79; // xmm0
  __m128 v80; // xmm1
  __m128 v81; // xmm0
  __m128 v82; // xmm5
  __m128 v83; // xmm2
  __m128 v84; // xmm4
  __m128 v85; // xmm0
  __m128 v86; // xmm4
  __m128 v87; // xmm0
  __m128 v88; // xmm1
  __m128 v89; // xmm3
  __m128 v90; // xmm5
  __m128 v91; // xmm2
  __m128 v92; // xmm2
  __m128 v93; // xmm3
  __m128 v94; // xmm2
  bool v95; // al
  int v96; // ecx
  __m128 v97; // xmm13
  __m128 v98; // xmm5
  __m128 v99; // xmm4
  __m128 v100; // xmm2
  __m128 v101; // xmm1
  __m128 v102; // xmm0
  __m128 v103; // xmm2
  __m128 v104; // xmm1
  __m128 v105; // xmm8
  __m128 v106; // xmm11
  __m128 v107; // xmm11
  __m128 v108; // xmm1
  __m128 v109; // xmm3
  __m128 v110; // xmm2
  __m128 v111; // xmm11
  __m128 v112; // xmm12
  _BYTE *v113; // rax
  _BYTE *v114; // rax
  _BYTE *v115; // rax
  __m128 v116; // xmm6
  _BYTE *v117; // rax
  bool *v118; // rax
  __m128 v119; // xmm6
  __m128 v120; // xmm7
  _BYTE *v121; // rax
  __m128 v122; // [rsp+30h] [rbp-98h]
  __m128 v123; // [rsp+40h] [rbp-88h]
  hkVector4f bIn; // [rsp+50h] [rbp-78h]
  __m128 v125; // [rsp+60h] [rbp-68h]
  __m128 v126; // [rsp+70h] [rbp-58h]
  hkVector4f aIn; // [rsp+88h] [rbp-40h]
  hkVector4f up; // [rsp+98h] [rbp-30h]
  hkVector4f p; // [rsp+A8h] [rbp-20h]
  __m128 v130; // [rsp+B8h] [rbp-10h]
  __m128 v131; // [rsp+C8h] [rbp+0h]
  __m128 v132; // [rsp+D8h] [rbp+10h]
  hkVector4f bTangentPoint; // [rsp+E8h] [rbp+20h]
  __m128 v134; // [rsp+F8h] [rbp+30h]
  hkVector4f v135; // [rsp+108h] [rbp+40h]
  __m128 v136; // [rsp+118h] [rbp+50h]
  hkVector4f v137; // [rsp+128h] [rbp+60h]
  __m128 v138; // [rsp+138h] [rbp+70h]
  hkVector4f v139; // [rsp+148h] [rbp+80h]
  __m128 v140; // [rsp+158h] [rbp+90h]
  __m128 v141; // [rsp+168h] [rbp+A0h]
  __m128 v142; // [rsp+178h] [rbp+B0h]
  hkMatrix4f m; // [rsp+188h] [rbp+C0h]
  hkaiEdgePath *v144; // [rsp+2A8h] [rbp+1E0h]
  bool v145; // [rsp+2B0h] [rbp+1E8h]
  char v146; // [rsp+2B8h] [rbp+1F0h]
  _BYTE *v147; // [rsp+2C8h] [rbp+200h]

  v5 = nextEdgeIndex;
  v6 = edgeIsLeft;
  v7 = edgeIndex;
  v8 = edgePath;
  v9 = hkaiEdgePath::getEdge(edgePath, edgeIndex);
  v10 = v7;
  v145 = 0;
  v11 = 0;
  v12 = v9->m_up.m_quad;
  v13 = v9;
  bIn.m_quad = stru_141A71280.m_quad;
  v123 = qi.m_vec.m_quad;
  up.m_quad = v12;
  v123.m128_f32[2] = FLOAT_0_001;
  v14 = 0i64;
  p.m_quad = 0i64;
  v131 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_001), (__m128)LODWORD(FLOAT_0_001), 0);
  v141 = _mm_sub_ps((__m128)0i64, v131);
  v15 = hkaiEdgePath::getNumEdges(v8);
  if ( v7 == v15 - 1 )
    return 4i64;
  v17 = v6 == 0;
  v18 = &v13->m_right.m_quad;
  if ( v17 )
  {
    v20 = *v18;
    v21 = *v18;
    v126 = 0i64;
    v19 = _mm_shuffle_ps(v20, _mm_unpackhi_ps(v21, _mm_sub_ps((__m128)0i64, _mm_shuffle_ps(v20, v20, 255))), 196);
    aIn.m_quad = v19;
    hkaiEdgePathSteeringUtil::calcMutualTangentPoints(
      &aIn,
      &v13->m_left,
      &up,
      (hkVector4f *)&v125.m128_u16[4],
      (hkVector4f *)((char *)&bIn + 8));
    v122 = _mm_sub_ps(*(__m128 *)((char *)&bIn.m_quad + 8), *(__m128 *)((char *)&v125 + 8));
  }
  else
  {
    v122 = 0i64;
    v19 = _mm_shuffle_ps(
            v13->m_left.m_quad,
            _mm_unpackhi_ps(
              v13->m_left.m_quad,
              _mm_sub_ps((__m128)0i64, _mm_shuffle_ps(v13->m_left.m_quad, v13->m_left.m_quad, 255))),
            196);
    aIn.m_quad = v19;
    hkaiEdgePathSteeringUtil::calcMutualTangentPoints(
      &aIn,
      &v13->m_right,
      &up,
      (hkVector4f *)&v125.m128_u16[4],
      (hkVector4f *)((char *)&bIn + 8));
    v126 = _mm_sub_ps(*(__m128 *)((char *)&bIn.m_quad + 8), *(__m128 *)((char *)&v125 + 8));
  }
  v17 = (v13->m_flags.m_storage & 0x10) == 0;
  v22 = v13->m_followingTransform.m_col2.m_quad;
  v23 = v13->m_followingTransform.m_col3.m_quad;
  v24 = v13->m_followingTransform.m_col0.m_quad;
  v25 = _mm_add_ps(
          _mm_mul_ps(_mm_shuffle_ps(v22, v22, 85), direction.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(v13->m_followingTransform.m_col2.m_quad, v22, 0), transform.m_quad));
  v26 = v13->m_followingTransform.m_col3.m_quad;
  v27 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_shuffle_ps(v13->m_followingTransform.m_col1.m_quad, v13->m_followingTransform.m_col1.m_quad, 85),
              direction.m_quad),
            _mm_mul_ps(
              _mm_shuffle_ps(v13->m_followingTransform.m_col1.m_quad, v13->m_followingTransform.m_col1.m_quad, 0),
              transform.m_quad)),
          _mm_mul_ps(
            _mm_shuffle_ps(v13->m_followingTransform.m_col1.m_quad, v13->m_followingTransform.m_col1.m_quad, 170),
            bIn.m_quad));
  *(__m128 *)((char *)&v126 + 8) = v27;
  v28 = _mm_add_ps(v25, _mm_mul_ps(_mm_shuffle_ps(v22, v22, 170), bIn.m_quad));
  v125 = v28;
  v29 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v23, v23, 0), transform.m_quad), v123),
            _mm_mul_ps(_mm_shuffle_ps(v26, v23, 85), direction.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v23, v23, 170), bIn.m_quad));
  v123.m128_u64[0] = v29.m128_u64[0];
  v30 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v24, v24, 85), direction.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v24, v24, 0), transform.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v24, v24, 170), bIn.m_quad));
  bIn.m_quad = v30;
  if ( !v17 )
  {
    v11 = 1;
    v31 = _mm_sub_ps(*v18, v13->m_left.m_quad);
    v32 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v31, v31, 201), v12), _mm_mul_ps(_mm_shuffle_ps(v12, v12, 201), v31));
    v33 = _mm_shuffle_ps(v32, v32, 201);
    v34 = _mm_mul_ps(v33, v33);
    v35 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v34, v34, 85), _mm_shuffle_ps(v34, v34, 0)),
            _mm_shuffle_ps(v34, v34, 170));
    v36 = _mm_rsqrt_ps(v35);
    v37 = _mm_mul_ps(
            v33,
            _mm_andnot_ps(
              _mm_cmpleps(v35, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v36, v35), v36)),
                _mm_mul_ps(*(__m128 *)_xmm, v36))));
    v38 = _mm_mul_ps(v19, v37);
    v14 = _mm_shuffle_ps(
            v37,
            _mm_unpackhi_ps(
              v37,
              _mm_sub_ps(
                (__m128)0i64,
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v38, v38, 85), _mm_shuffle_ps(v38, v38, 0)),
                  _mm_shuffle_ps(v38, v38, 170)))),
            196);
    p.m_quad = v14;
  }
  v39 = v7 + 1;
  if ( v7 + 1 < v15 )
  {
    v40 = &bIn.m_quad.m128_i8[8];
    v41 = _mm_shuffle_ps(v19, v19, 255);
    if ( !v146 )
      v40 = &v125.m128_i8[8];
    v123.m128_u64[1] = (unsigned __int64)v40;
    v140 = v41;
    while ( 1 )
    {
      v42 = hkaiEdgePath::getEdge(v144, v39);
      v43 = v42->m_left.m_quad;
      v44 = _mm_shuffle_ps(v42->m_left.m_quad, v42->m_left.m_quad, 85);
      v45 = _mm_shuffle_ps(v42->m_left.m_quad, v42->m_left.m_quad, 170);
      v130 = _mm_shuffle_ps(v43, v43, 0);
      v132 = v44;
      v138 = v45;
      v46 = _mm_mul_ps(v27, v44);
      v47 = v28;
      v48 = v42->m_right.m_quad;
      v49 = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(v30, v130), v29), v46), _mm_mul_ps(v47, v45));
      v50 = _mm_shuffle_ps(v42->m_right.m_quad, v48, 170);
      v51 = v42->m_right.m_quad;
      v134 = _mm_shuffle_ps(v48, v48, 0);
      v136 = v50;
      v142 = _mm_shuffle_ps(v51, v48, 85);
      v52 = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(v30, v134), v29), _mm_mul_ps(v27, v142)), _mm_mul_ps(v125, v50));
      if ( v11 )
      {
        v53 = _mm_mul_ps(v49, v14);
        v54 = _mm_shuffle_ps(v53, _mm_unpackhi_ps(v53, v14), 196);
        v55 = _mm_add_ps(_mm_shuffle_ps(v54, v54, 78), v54);
        if ( (float)(COERCE_FLOAT(_mm_shuffle_ps(v55, v55, 177)) + v55.m128_f32[0]) < 0.0 )
        {
          v56 = _mm_mul_ps(v52, v14);
          v57 = _mm_shuffle_ps(v56, _mm_unpackhi_ps(v56, v14), 196);
          v58 = _mm_add_ps(_mm_shuffle_ps(v57, v57, 78), v57);
          if ( (float)(COERCE_FLOAT(_mm_shuffle_ps(v58, v58, 177)) + v58.m128_f32[0]) < 0.0 )
          {
            makeReflectionMatrix(&p, &m);
            v145 = v145 == 0;
            v59 = _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v27, *(__m128 *)((char *)&v126 + 8), 85), m.m_col1.m_quad),
                    _mm_mul_ps(
                      _mm_shuffle_ps(*(__m128 *)((char *)&v126 + 8), *(__m128 *)((char *)&v126 + 8), 0),
                      m.m_col0.m_quad));
            *(__m128 *)((char *)&v126 + 8) = _mm_mul_ps(
                                               _mm_shuffle_ps(
                                                 *(__m128 *)((char *)&v126 + 8),
                                                 *(__m128 *)((char *)&v126 + 8),
                                                 170),
                                               m.m_col2.m_quad);
            v60 = _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v125, v125, 85), m.m_col1.m_quad),
                    _mm_mul_ps(_mm_shuffle_ps(v125, v125, 0), m.m_col0.m_quad));
            v125 = _mm_mul_ps(_mm_shuffle_ps(v125, v125, 170), m.m_col2.m_quad);
            *(__m128 *)((char *)&v126 + 8) = _mm_add_ps(*(__m128 *)((char *)&v126 + 8), v59);
            bIn.m_quad = _mm_add_ps(
                           _mm_add_ps(
                             _mm_mul_ps(_mm_shuffle_ps(bIn.m_quad, bIn.m_quad, 85), m.m_col1.m_quad),
                             _mm_mul_ps(_mm_shuffle_ps(bIn.m_quad, bIn.m_quad, 0), m.m_col0.m_quad)),
                           _mm_mul_ps(_mm_shuffle_ps(bIn.m_quad, bIn.m_quad, 170), m.m_col2.m_quad));
            v125 = _mm_add_ps(v125, v60);
            v123 = _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v123, v123, 0), m.m_col0.m_quad), m.m_col3.m_quad),
                       _mm_mul_ps(_mm_shuffle_ps(v123, v123, 85), m.m_col1.m_quad)),
                     _mm_mul_ps(_mm_shuffle_ps(v123, v123, 170), m.m_col2.m_quad));
            v49 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_mul_ps(bIn.m_quad, v130), v123),
                      _mm_mul_ps(*(__m128 *)((char *)&v126 + 8), v132)),
                    _mm_mul_ps(v125, v138));
            v52 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_mul_ps(bIn.m_quad, v134), v123),
                      _mm_mul_ps(*(__m128 *)((char *)&v126 + 8), v142)),
                    _mm_mul_ps(v125, v136));
          }
        }
        v11 = 0;
      }
      v61 = _mm_shuffle_ps(v43, v43, 255);
      v62 = _mm_shuffle_ps(v48, v48, 255);
      if ( v145 )
      {
        v63 = _mm_shuffle_ps(v49, _mm_unpackhi_ps(v49, _mm_sub_ps((__m128)0i64, v61)), 196);
        v64 = _mm_shuffle_ps(v52, _mm_unpackhi_ps(v52, _mm_sub_ps((__m128)0i64, v62)), 196);
      }
      else
      {
        v64 = _mm_shuffle_ps(v49, _mm_unpackhi_ps(v49, v61), 196);
        v63 = _mm_shuffle_ps(v52, _mm_unpackhi_ps(v52, v62), 196);
      }
      *(hkVector4f *)((char *)&bIn + 8) = (hkVector4f)v63;
      *(__m128 *)((char *)&v125 + 8) = v64;
      v65 = _mm_sub_ps(*(__m128 *)v123.m128_u64[1], v19);
      v66 = COERCE_FLOAT(_mm_shuffle_ps(*(__m128 *)v123.m128_u64[1], *(__m128 *)v123.m128_u64[1], 255))
          + v140.m128_f32[0];
      v67 = _mm_mul_ps(v65, v12);
      v68 = _mm_sub_ps(
              v65,
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v67, v67, 85), _mm_shuffle_ps(v67, v67, 0)),
                  _mm_shuffle_ps(v67, v67, 170)),
                v12));
      v69 = _mm_mul_ps(v68, v68);
      if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v69, v69, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v69, v69, 0)))
                 + COERCE_FLOAT(_mm_shuffle_ps(v69, v69, 170))) < (float)(v66 * v66) )
        return 5i64;
      v70 = v131;
      if ( (_mm_movemask_ps(_mm_cmpltps((__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(v64, v19), 1u), 1u), v131)) & 7) == 7 )
      {
        v71 = 0i64;
        v72 = 0i64;
      }
      else
      {
        hkaiEdgePathSteeringUtil::calcMutualTangentPoints(
          &aIn,
          (hkVector4f *)&v125.m128_u16[4],
          &up,
          &v135,
          &bTangentPoint);
        v71 = _mm_sub_ps(bTangentPoint.m_quad, v135.m_quad);
        v73 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v71, v71, 201), v12), _mm_mul_ps(_mm_shuffle_ps(v12, v12, 201), v71));
        v72 = _mm_shuffle_ps(v73, v73, 201);
      }
      if ( (_mm_movemask_ps(_mm_cmpltps((__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(v63, v19), 1u), 1u), v70)) & 7) == 7 )
      {
        v74 = 0i64;
        v75 = 0i64;
      }
      else
      {
        hkaiEdgePathSteeringUtil::calcMutualTangentPoints(&aIn, (hkVector4f *)((char *)&bIn + 8), &up, &v139, &v137);
        v74 = _mm_sub_ps(v137.m_quad, v139.m_quad);
        v76 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v74, v74, 201), v12), _mm_mul_ps(_mm_shuffle_ps(v12, v12, 201), v74));
        v75 = _mm_shuffle_ps(v76, v76, 201);
      }
      v77 = v42->m_flags.m_storage & 0x10;
      if ( v77 )
      {
        v78 = _mm_mul_ps(v74, v72);
        if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v78, v78, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v78, v78, 0)))
                   + COERCE_FLOAT(_mm_shuffle_ps(v78, v78, 170))) > 0.0 )
        {
          v79 = v71;
          v80 = v64;
          v71 = v74;
          v74 = v79;
          v81 = v72;
          v64 = v63;
          v72 = v75;
          v63 = v80;
          v75 = v81;
        }
      }
      v82 = _mm_mul_ps(v72, v122);
      v83 = _mm_mul_ps(v72, v126);
      v84 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64), v75);
      v85 = v84;
      v86 = _mm_mul_ps(v84, v126);
      v87 = _mm_mul_ps(v85, v122);
      v88 = _mm_shuffle_ps(v83, v86, 68);
      v89 = _mm_shuffle_ps(v82, v87, 68);
      v90 = _mm_shuffle_ps(_mm_shuffle_ps(v82, v87, 238), _mm_shuffle_ps(v83, v86, 238), 136);
      v91 = _mm_sub_ps(v71, v74);
      v92 = _mm_mul_ps(v91, v91);
      v93 = _mm_cmpleps(
              (__m128)0i64,
              _mm_add_ps(v90, _mm_add_ps(_mm_shuffle_ps(v89, v88, 221), _mm_shuffle_ps(v89, v88, 136))));
      v95 = 0;
      if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v92, v92, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v92, v92, 0)))
                 + COERCE_FLOAT(_mm_shuffle_ps(v92, v92, 170))) > v141.m128_f32[0] )
      {
        v94 = _mm_mul_ps(v74, v72);
        if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v94, v94, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v94, v94, 0)))
                   + COERCE_FLOAT(_mm_shuffle_ps(v94, v94, 170))) > v141.m128_f32[0] )
          v95 = 1;
      }
      v96 = (v95 != 0 ? 0x10 : 0) | _mm_movemask_ps(v93);
      if ( v146 )
      {
        if ( (_mm_movemask_ps(_mm_cmpeqps(v122, (__m128)0i64)) & 7) != 7 )
          goto LABEL_47;
        if ( _mm_movemask_ps(_mm_cmpeqps(v71, (__m128)0i64)) == 15 )
        {
          if ( v96 & 8 )
          {
$LN1241:
            v10 = v39;
            v126 = v74;
          }
        }
        else
        {
          switch ( v96 & 0x1C )
          {
            case 0:
              v122 = v71;
              v7 = v39;
              break;
            case 4:
            case 0xC:
            case 0x10:
            case 0x14:
              goto $LN10_137;
            case 8:
              v122 = v71;
              goto LABEL_50;
            case 0x18:
            case 0x1C:
              goto $LN4_168;
            default:
              break;
          }
        }
      }
      else
      {
        if ( (_mm_movemask_ps(_mm_cmpeqps(v126, (__m128)0i64)) & 7) != 7 )
        {
LABEL_47:
          switch ( v96 )
          {
            case 1:
            case 3:
              v122 = v71;
              v7 = v39;
              goto LABEL_52;
            case 2:
            case 10:
            case 11:
            case 14:
            case 18:
            case 19:
            case 24:
            case 26:
            case 30:
              goto $LN11_115;
            case 4:
            case 5:
            case 7:
            case 13:
            case 17:
            case 20:
            case 21:
            case 23:
            case 28:
$LN10_137:
              v114 = v147;
              *v5 = v10;
              *v114 = 0;
              return 0i64;
            case 6:
            case 22:
            case 25:
            case 27:
              goto $LN4_168;
            case 8:
            case 12:
              goto $LN1241;
            case 9:
              goto $LN12_121;
            case 15:
            case 16:
              v115 = v147;
              v116 = _mm_mul_ps(v71, v126);
              if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v116, v116, 85))
                                 + COERCE_FLOAT(_mm_shuffle_ps(v116, v116, 0)))
                         + COERCE_FLOAT(_mm_shuffle_ps(v116, v116, 170))) <= 0.0 )
              {
                *v5 = v7;
                *v115 = 1;
              }
              else
              {
                *v5 = v10;
                *v115 = 0;
              }
              return 0i64;
            case 29:
              v117 = v147;
              *v5 = v39;
              *v117 = 0;
              return 0i64;
            case 31:
              goto $LN1224;
            default:
              goto LABEL_52;
          }
          goto LABEL_52;
        }
        if ( _mm_movemask_ps(_mm_cmpeqps(v74, (__m128)0i64)) == 15 )
        {
          if ( v96 & 1 )
          {
            v122 = v71;
            v7 = v39;
          }
        }
        else
        {
          switch ( v96 & 0x13 )
          {
            case 0:
              goto $LN1241;
            case 1:
$LN12_121:
              v122 = v71;
LABEL_50:
              v7 = v39;
              goto $LN1241;
            case 2:
            case 3:
            case 0x10:
            case 0x12:
$LN11_115:
              v113 = v147;
              *v5 = v7;
              *v113 = 1;
              return 0i64;
            case 0x11:
            case 0x13:
$LN4_168:
              v118 = v147;
              v119 = _mm_mul_ps(v71, v71);
              v120 = _mm_mul_ps(v74, v74);
              *v5 = v39;
              *v118 = (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v119, v119, 85))
                                    + COERCE_FLOAT(_mm_shuffle_ps(v119, v119, 0)))
                            + COERCE_FLOAT(_mm_shuffle_ps(v119, v119, 170))) < (float)((float)(COERCE_FLOAT(
                                                                                                 _mm_shuffle_ps(
                                                                                                   v120,
                                                                                                   v120,
                                                                                                   85))
                                                                                             + COERCE_FLOAT(
                                                                                                 _mm_shuffle_ps(
                                                                                                   v120,
                                                                                                   v120,
                                                                                                   0)))
                                                                                     + COERCE_FLOAT(_mm_shuffle_ps(v120, v120, 170)));
              return 0i64;
            default:
              break;
          }
        }
      }
LABEL_52:
      if ( _mm_movemask_ps(_mm_cmpeqps(v42->m_right.m_quad, v42->m_left.m_quad)) == 15 )
      {
$LN1224:
        v121 = v147;
        *v5 = v39;
        *v121 = 1;
        return 0i64;
      }
      v97 = *(__m128 *)((char *)&v126 + 8);
      v98 = v42->m_followingTransform.m_col2.m_quad;
      v99 = _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v98, v98, 85), *(__m128 *)((char *)&v126 + 8)),
              _mm_mul_ps(_mm_shuffle_ps(v42->m_followingTransform.m_col2.m_quad, v98, 0), bIn.m_quad));
      v100 = v42->m_followingTransform.m_col0.m_quad;
      v101 = _mm_shuffle_ps(v100, v100, 85);
      v102 = _mm_mul_ps(_mm_shuffle_ps(v100, v100, 0), bIn.m_quad);
      v27 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_shuffle_ps(v42->m_followingTransform.m_col1.m_quad, v42->m_followingTransform.m_col1.m_quad, 85),
                  *(__m128 *)((char *)&v126 + 8)),
                _mm_mul_ps(
                  _mm_shuffle_ps(v42->m_followingTransform.m_col1.m_quad, v42->m_followingTransform.m_col1.m_quad, 0),
                  bIn.m_quad)),
              _mm_mul_ps(
                _mm_shuffle_ps(v42->m_followingTransform.m_col1.m_quad, v42->m_followingTransform.m_col1.m_quad, 170),
                v125));
      v29 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  v123,
                  _mm_mul_ps(
                    _mm_shuffle_ps(v42->m_followingTransform.m_col3.m_quad, v42->m_followingTransform.m_col3.m_quad, 0),
                    bIn.m_quad)),
                _mm_mul_ps(
                  _mm_shuffle_ps(v42->m_followingTransform.m_col3.m_quad, v42->m_followingTransform.m_col3.m_quad, 85),
                  *(__m128 *)((char *)&v126 + 8))),
              _mm_mul_ps(
                _mm_shuffle_ps(v42->m_followingTransform.m_col3.m_quad, v42->m_followingTransform.m_col3.m_quad, 170),
                v125));
      *(__m128 *)((char *)&v126 + 8) = v27;
      v103 = _mm_mul_ps(_mm_shuffle_ps(v100, v100, 170), v125);
      v104 = _mm_mul_ps(v101, v97);
      v123 = v29;
      v28 = _mm_add_ps(v99, _mm_mul_ps(_mm_shuffle_ps(v98, v98, 170), v125));
      v125 = v28;
      bIn.m_quad = _mm_add_ps(_mm_add_ps(v104, v102), v103);
      if ( v77 )
      {
        v105 = _mm_sub_ps(v63, v64);
        v11 = 1;
        v106 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v105, v105, 201), v12),
                 _mm_mul_ps(_mm_shuffle_ps(v12, v12, 201), v105));
        v107 = _mm_shuffle_ps(v106, v106, 201);
        v108 = _mm_mul_ps(v107, v107);
        v109 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v108, v108, 85), _mm_shuffle_ps(v108, v108, 0)),
                 _mm_shuffle_ps(v108, v108, 170));
        v110 = _mm_rsqrt_ps(v109);
        v111 = _mm_mul_ps(
                 v107,
                 _mm_andnot_ps(
                   _mm_cmpleps(v109, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v110, v109), v110)),
                     _mm_mul_ps(*(__m128 *)_xmm, v110))));
        v112 = _mm_mul_ps(v64, v111);
        v14 = _mm_shuffle_ps(
                v111,
                _mm_unpackhi_ps(
                  v111,
                  _mm_sub_ps(
                    (__m128)0i64,
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v112, v112, 85), _mm_shuffle_ps(v112, v112, 0)),
                      _mm_shuffle_ps(v112, v112, 170)))),
                196);
        p.m_quad = v14;
      }
      if ( ++v39 >= v15 )
        return 1i64;
      v30 = bIn.m_quad;
    }
  }
  return 1i64;
}

// File Line: 965
// RVA: 0xC132A0
float __fastcall hkaiEdgePathSteeringUtil::calcMultilevelDistance(hkVector4f *a, hkVector4f *b, hkVector4f *up, hkSimdFloat32 *maxIgnoredHeight)
{
  __m128 v4; // xmm2
  __m128 v5; // xmm1
  __m128 v6; // xmm3
  __m128 v7; // xmm2
  __m128 v8; // xmm5
  __m128 v9; // xmm2
  float result; // xmm0_4

  v4 = _mm_sub_ps(a->m_quad, b->m_quad);
  v5 = _mm_mul_ps(up->m_quad, v4);
  v6 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v5, v5, 85), _mm_shuffle_ps(v5, v5, 0)), _mm_shuffle_ps(v5, v5, 170));
  if ( COERCE_FLOAT((unsigned int)(2 * v6.m128_i32[0]) >> 1) < maxIgnoredHeight->m_real.m128_f32[0] )
    v4 = _mm_sub_ps(v4, _mm_mul_ps(up->m_quad, v6));
  v7 = _mm_mul_ps(v4, v4);
  v8 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps(v7, v7, 0)), _mm_shuffle_ps(v7, v7, 170));
  v9 = _mm_rsqrt_ps(v8);
  LODWORD(result) = (unsigned __int128)_mm_andnot_ps(
                                         _mm_cmpleps(v8, (__m128)0i64),
                                         _mm_mul_ps(
                                           _mm_mul_ps(
                                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v9, v8), v9)),
                                             _mm_mul_ps(*(__m128 *)_xmm, v9)),
                                           v8));
  return result;
}

// File Line: 990
// RVA: 0xC13340
float __fastcall hkaiEdgePathSteeringUtil::approximateDistanceToGoal(hkVector4f *position, hkVector4f *corner, hkVector4f *goal, hkVector4f *up, hkSimdFloat32 *maxIgnoredHeight)
{
  hkVector4f *v5; // rdi
  hkVector4f *v6; // rsi
  hkVector4f *v7; // rbp
  float v8; // xmm6_4

  v5 = up;
  v6 = goal;
  v7 = corner;
  v8 = hkaiEdgePathSteeringUtil::calcMultilevelDistance(position, corner, up, maxIgnoredHeight);
  return v8 + hkaiEdgePathSteeringUtil::calcMultilevelDistance(v7, v6, v5, maxIgnoredHeight);
}

// File Line: 1005
// RVA: 0xC133B0
float __fastcall hkaiEdgePathSteeringUtil::calcOptimalSpeed(float distToGoal, float currentSpeed, float desiredMaxSpeed, float desiredGoalSpeed, float desiredMaxAcceleration, float desiredMaxDeceleration, float absoluteMaxAcceleration, float absoluteMaxDeceleration, float timeStep, bool *approachingGoal)
{
  float result; // xmm0_4

  result = (float)((float)((float)(fsqrt(
                                     (float)(desiredGoalSpeed * desiredGoalSpeed)
                                   - (float)((float)((float)(desiredMaxDeceleration * 0.5) * 4.0)
                                           * COERCE_FLOAT(LODWORD(distToGoal) ^ _xmm[0])))
                                 - desiredGoalSpeed)
                         / (float)((float)(desiredMaxDeceleration * 0.5) * 2.0))
                 * desiredMaxDeceleration)
         - desiredGoalSpeed;
  if ( result >= desiredMaxSpeed )
  {
    *approachingGoal = 0;
    result = desiredMaxSpeed;
  }
  else
  {
    *approachingGoal = 1;
  }
  return result;
}

// File Line: 1046
// RVA: 0xC13120
signed __int64 __fastcall hkaiEdgePathSteeringUtil::getFollowingCorner(hkaiEdgePath *edgePath, int startEdge, bool startIsLeft, hkaiStreamingCollection *streamingCollection, int *followingEdge, bool *followingIsLeft)
{
  bool v6; // bl
  int v7; // edi
  hkaiEdgePath *v8; // rsi
  signed __int64 result; // rax
  int v10; // eax

  v6 = startIsLeft;
  v7 = startEdge;
  v8 = edgePath;
  if ( (unsigned int)hkaiEdgePath::hasFollowingCornerInfo(edgePath, startEdge, startIsLeft) )
    return hkaiEdgePath::getFollowingCornerInfo(v8, v7, v6, followingEdge, followingIsLeft);
  v10 = hkaiEdgePathSteeringUtil::calcForwardVector_corner(v8, v7, v6, followingEdge, followingIsLeft);
  if ( (unsigned int)(v10 - 4) <= 1 || v10 == 1 )
  {
    hkaiEdgePath::setFollowingCornerInfoInvalid(v8, v7, v6);
    result = 0i64;
  }
  else
  {
    hkaiEdgePath::setFollowingCornerInfoValid(v8, v7, v6, *followingEdge, *followingIsLeft);
    result = 1i64;
  }
  return result;
}

// File Line: 1088
// RVA: 0xC12F60
signed __int64 __fastcall hkaiEdgePathSteeringUtil::getRelativeTransform(int positionSectionIndex, hkaiEdgePath::Edge *targetEdge, hkaiStreamingCollection *streamingCollection, hkMatrix4f *relativeTransformOut)
{
  hkMatrix4f *v4; // rbx
  unsigned int v5; // eax
  hkaiNavMeshInstance *v6; // rdx
  signed __int64 result; // rax
  __m128i v8; // xmm0
  __m128i v9; // xmm1
  __m128i v10; // xmm0
  hkVector4f v11; // xmm1
  hkaiStreamingCollection::InstanceInfo *v12; // r8
  hkaiNavMeshInstance *v13; // r10
  __int64 v14; // rax
  hkaiNavMeshInstance *v15; // r8
  hkVector4f v16; // xmm2
  hkVector4f v17; // xmm1
  hkVector4f v18; // xmm0
  __m128i v19; // xmm0
  hkTransformf v20; // [rsp+20h] [rbp-48h]

  v4 = relativeTransformOut;
  if ( positionSectionIndex == -1 )
  {
    v5 = targetEdge->m_edge.m_faceKey.m_key;
    if ( v5 != -1 )
    {
      v6 = streamingCollection->m_instances.m_data[v5 >> 22].m_instancePtr;
      result = 0i64;
      relativeTransformOut->m_col0 = v6->m_referenceFrame.m_transform.m_rotation.m_col0;
      relativeTransformOut->m_col1 = v6->m_referenceFrame.m_transform.m_rotation.m_col1;
      relativeTransformOut->m_col2 = v6->m_referenceFrame.m_transform.m_rotation.m_col2;
      v8 = _mm_srli_si128(_mm_slli_si128(_mm_load_si128((const __m128i *)relativeTransformOut), 4), 4);
      relativeTransformOut->m_col3 = v6->m_referenceFrame.m_transform.m_translation;
      v9 = _mm_load_si128((const __m128i *)&relativeTransformOut->m_col1);
      _mm_store_si128((__m128i *)relativeTransformOut, v8);
      v10 = _mm_load_si128((const __m128i *)&relativeTransformOut->m_col2);
      _mm_store_si128((__m128i *)&relativeTransformOut->m_col1, _mm_srli_si128(_mm_slli_si128(v9, 4), 4));
      v11.m_quad = (__m128)relativeTransformOut->m_col3;
      _mm_store_si128((__m128i *)&relativeTransformOut->m_col2, _mm_srli_si128(_mm_slli_si128(v10, 4), 4));
      relativeTransformOut->m_col3.m_quad = _mm_shuffle_ps(v11.m_quad, _mm_unpackhi_ps(v11.m_quad, query.m_quad), 196);
      return result;
    }
LABEL_7:
    result = 0i64;
    relativeTransformOut->m_col0 = (hkVector4f)transform.m_quad;
    relativeTransformOut->m_col1 = (hkVector4f)direction.m_quad;
    relativeTransformOut->m_col2 = (hkVector4f)stru_141A71280.m_quad;
    relativeTransformOut->m_col3 = (hkVector4f)qi.m_vec.m_quad;
    return result;
  }
  v12 = streamingCollection->m_instances.m_data;
  v13 = v12[positionSectionIndex].m_instancePtr;
  if ( !v13 )
    return 2i64;
  v14 = targetEdge->m_edge.m_faceKey.m_key >> 22;
  if ( positionSectionIndex == (_DWORD)v14 )
    goto LABEL_7;
  v15 = v12[v14].m_instancePtr;
  if ( !v15 )
    return 3i64;
  hkTransformf::setMulInverseMul(&v20, &v13->m_referenceFrame.m_transform, &v15->m_referenceFrame.m_transform);
  result = 0i64;
  v16.m_quad = (__m128)v20.m_translation;
  v17.m_quad = (__m128)v20.m_rotation.m_col1;
  v4->m_col0 = v20.m_rotation.m_col0;
  v18.m_quad = (__m128)v20.m_rotation.m_col2;
  v4->m_col1 = (hkVector4f)v17.m_quad;
  v4->m_col2 = (hkVector4f)v18.m_quad;
  v19 = _mm_load_si128((const __m128i *)v4);
  v4->m_col3 = (hkVector4f)v16.m_quad;
  _mm_store_si128((__m128i *)v4, _mm_srli_si128(_mm_slli_si128(v19, 4), 4));
  _mm_store_si128(
    (__m128i *)&v4->m_col2,
    _mm_srli_si128(_mm_slli_si128(_mm_load_si128((const __m128i *)&v4->m_col2), 4), 4));
  _mm_store_si128((__m128i *)&v4->m_col1, _mm_srli_si128(_mm_slli_si128((__m128i)v17.m_quad, 4), 4));
  v4->m_col3.m_quad = _mm_shuffle_ps(v16.m_quad, _mm_unpackhi_ps(v16.m_quad, query.m_quad), 196);
  return result;
}

// File Line: 1143
// RVA: 0xC131F0
signed __int64 __fastcall hkaiEdgePathSteeringUtil::resolveEdgeToKey(hkaiEdgePath::Edge *edge, hkaiGeneralAccessor *accessor, hkaiNavMeshCutter *cutter, unsigned int *faceKeyOut)
{
  hkaiEdgePath::Edge *v4; // rdi
  unsigned int *v5; // rsi
  hkaiGeneralAccessor *v6; // r14
  unsigned int v7; // eax
  unsigned int v8; // ebx
  hkVector4f edgeA; // [rsp+20h] [rbp-28h]
  hkVector4f edgeB; // [rsp+30h] [rbp-18h]

  v4 = edge;
  v5 = faceKeyOut;
  v6 = accessor;
  v7 = hkaiNavMeshCutter::resolvePersistentEdgeKey(cutter, accessor, &edge->m_edge, faceKeyOut);
  v8 = v7;
  if ( v7 != -1 )
  {
    hkaiGeneralAccessor::setSection(v6, v7 >> 22);
    hkaiNavMeshInstance::getEdgePoints(v6->m_accessor, v8 & 0x3FFFFF, &edgeA, &edgeB);
    if ( (_mm_movemask_ps(_mm_cmpeqps(v4->m_right.m_quad, edgeA.m_quad)) & 7) == 7
      && (_mm_movemask_ps(_mm_cmpeqps(v4->m_left.m_quad, edgeB.m_quad)) & 7) == 7 )
    {
      return v8;
    }
    *v5 = -1;
  }
  return 0xFFFFFFFFi64;
}

