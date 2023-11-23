// File Line: 18
// RVA: 0xC13430
void __fastcall makeReflectionMatrix(hkVector4f *p, hkMatrix4f *m)
{
  __m128 m_quad; // xmm5
  __m128 v3; // xmm4
  __m128 v4; // xmm4
  hkVector4f v5; // xmm2
  hkVector4f v6; // xmm1

  m_quad = p->m_quad;
  v3 = _mm_shuffle_ps(p->m_quad, _mm_unpackhi_ps(p->m_quad, (__m128)0i64), 196);
  v4 = _mm_add_ps(v3, v3);
  v5.m_quad = _mm_sub_ps(stru_141A71280.m_quad, _mm_mul_ps(_mm_shuffle_ps(p->m_quad, p->m_quad, 170), v4));
  v6.m_quad = _mm_sub_ps(qi.m_vec.m_quad, _mm_mul_ps(_mm_shuffle_ps(p->m_quad, p->m_quad, 255), v4));
  m->m_col1.m_quad = _mm_sub_ps(direction.m_quad, _mm_mul_ps(_mm_shuffle_ps(p->m_quad, p->m_quad, 85), v4));
  m->m_col2 = (hkVector4f)v5.m_quad;
  m->m_col3 = (hkVector4f)v6.m_quad;
  m->m_col0.m_quad = _mm_sub_ps(transform.m_quad, _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 0), v4));
}

// File Line: 44
// RVA: 0xC10CC0
hkaiEdgePathSteeringUtil::CalcForwardVectorResult __fastcall hkaiEdgePathSteeringUtil::calcForwardVector(
        hkaiEdgePath *edgePath,
        hkaiEdgePath::TraversalState *traversalState,
        hkVector4f *positionIn,
        int positionSectionIndex,
        hkaiStreamingCollection *streamingCollection,
        hkVector4f *forwardVector,
        hkVector4f *futureVector,
        hkVector4f *nextCorner,
        hkVector4f *nextUserEdgePlane,
        int *nextEdgeIndex,
        bool *nextIsLeft)
{
  hkaiEdgePath::Edge *Edge; // rax
  __m128 v16; // xmm7
  hkaiEdgePath::Edge *v17; // rsi
  char v18; // r14
  hkaiEdgePathSteeringUtil::CalcForwardVectorResult result; // eax
  hkVector4f v20; // xmm13
  hkaiEdgePath::Edge *v21; // r8
  hkaiEdgePath::Edge *v22; // r11
  __m128 *p_m_quad; // r10
  bool v24; // bl
  char v25; // dl
  __m128 v26; // xmm0
  __m128 v27; // xmm6
  __m128 v28; // xmm5
  __m128 v29; // xmm14
  hkVector4f v30; // xmm15
  hkVector4f v31; // xmm10
  hkVector4f v32; // xmm9
  hkVector4f *p_m_col2; // rax
  hkVector4f v34; // xmm12
  __m128 v35; // xmm11
  __m128 v36; // xmm2
  hkaiEdgePath::Edge *v37; // r15
  __m128 v38; // xmm4
  __m128 v39; // xmm0
  __m128 v40; // xmm2
  __m128 v41; // xmm8
  __m128 v42; // xmm3
  __m128 v43; // xmm1
  __m128 v44; // xmm3
  __m128 v45; // xmm2
  __m128 v46; // xmm1
  __m128 v47; // xmm4
  __m128 v48; // xmm2
  __m128 v49; // xmm1
  __m128 v50; // xmm3
  __m128 v51; // xmm6
  __m128 v52; // xmm1
  __m128 v53; // xmm6
  __m128 v54; // xmm6
  __m128 v55; // xmm2
  __m128 v56; // xmm5
  __m128i v57; // xmm1
  __m128 v58; // xmm7
  __m128 v59; // xmm4
  __m128 v60; // xmm3
  __m128 v61; // xmm11
  __m128i v62; // xmm0
  __m128 v63; // xmm2
  __m128 v64; // xmm1
  __m128 v65; // xmm11
  __m128 v66; // xmm1
  __m128 v67; // xmm1
  __m128 v68; // xmm6
  __m128 v69; // xmm3
  __m128 v70; // xmm3
  __m128 v71; // xmm2
  __m128 v72; // xmm6
  __m128 v73; // xmm2
  bool v74; // zf
  __m128 v75; // xmm1
  __m128 v76; // xmm5
  __m128 v77; // xmm0
  __m128 v78; // xmm2
  __m128 v79; // xmm3
  __m128 v80; // xmm0
  __m128 v81; // xmm5
  __m128 v82; // xmm7
  __m128 v83; // xmm0
  __m128 v84; // xmm3
  __m128 v85; // xmm13
  __m128 v86; // xmm5
  __m128 v87; // xmm1
  __m128 v88; // xmm4
  __m128 v89; // xmm0
  __m128 v90; // xmm0
  __m128 v91; // xmm2
  __m128 v92; // xmm11
  __m128 v93; // xmm8
  __m128 v94; // xmm8
  signed __int64 v95; // r10
  __int128 v96; // rax
  __m128 v97; // xmm6
  __m128 v98; // xmm13
  __m128 *v99; // rax
  float v100; // xmm2_4
  float v101; // xmm1_4
  __m128 v102; // xmm0
  __m128 v103; // xmm1
  __m128 *v104; // rax
  __m128 v105; // xmm2
  __m128 v106; // xmm0
  __m128 v107; // xmm0
  __m128 v108; // xmm14
  __m128 v109; // xmm14
  __m128 v110; // xmm1
  __m128 v111; // xmm3
  __m128 v112; // xmm2
  __m128 v113; // xmm14
  __m128 v114; // xmm2
  __m128 *v115; // r8
  __m128 *v116; // r9
  __m128 v117; // xmm2
  __m128 v118; // xmm4
  __m128 v119; // xmm0
  __m128 v120; // xmm1
  __m128 v121; // xmm13
  __m128 v122; // xmm3
  __m128 v123; // xmm2
  __m128 v124; // xmm2
  __m128 v125; // xmm1
  __m128 v126; // xmm2
  __m128 v127; // xmm2
  __m128 v128; // xmm1
  __m128 v129; // xmm2
  __m128 v130; // xmm4
  __m128 v131; // xmm13
  __m128 v132; // xmm5
  __m128 v133; // xmm3
  __m128 v134; // xmm4
  __m128 v135; // xmm1
  __m128 v136; // xmm2
  __m128 v137; // xmm1
  __m128 v138; // xmm3
  __m128 v139; // xmm2
  __m128 v140; // xmm1
  __m128 v141; // xmm4
  __m128 v142; // xmm10
  __m128 v143; // xmm1
  __m128 v144; // xmm10
  __m128 v145; // xmm10
  __m128 v146; // xmm2
  __m128 v147; // xmm8
  __m128i v148; // xmm1
  __m128 v149; // xmm7
  __m128 v150; // xmm11
  __m128 v151; // xmm12
  __m128 v152; // xmm9
  __m128 v153; // xmm9
  char v154; // di
  __m128 v155; // xmm6
  __m128i v156; // xmm0
  __m128 v157; // xmm1
  __m128 v158; // xmm5
  __m128 v159; // xmm6
  __m128 v160; // xmm1
  __m128 v161; // xmm1
  __m128 v162; // xmm10
  __m128 v163; // xmm3
  __m128 v164; // xmm3
  __m128 v165; // xmm2
  __m128 v166; // xmm4
  __m128 v167; // xmm1
  __m128 v168; // xmm0
  __m128 v169; // xmm3
  __m128 v170; // xmm2
  __m128 v171; // xmm4
  __m128 v172; // xmm2
  __m128 v173; // xmm10
  __m128 v174; // xmm9
  __m128 v175; // xmm5
  char v176; // di
  __m128 v177; // xmm2
  __m128 v178; // xmm8
  __m128 v179; // xmm0
  __m128 v180; // xmm11
  __m128 v181; // xmm6
  __m128 v182; // xmm0
  __m128 v183; // xmm9
  __m128 v184; // xmm0
  __m128 v185; // xmm2
  __m128 v186; // xmm4
  __m128 v187; // xmm1
  __m128 v188; // xmm3
  __m128 v189; // xmm4
  __m128 v190; // xmm0
  __m128 v191; // xmm3
  __m128 v192; // xmm4
  __m128 v193; // xmm2
  __m128 v194; // xmm9
  __m128 v195; // xmm2
  __m128 v196; // xmm10
  bool v197; // al
  __m128 v198; // xmm2
  __m128 v199; // xmm12
  __m128 v200; // xmm0
  __m128 v201; // xmm2
  __m128 v202; // xmm13
  __m128 v203; // xmm14
  __m128 v204; // xmm14
  __m128 v205; // xmm1
  __m128 v206; // xmm3
  __m128 v207; // xmm2
  __m128 v208; // xmm14
  __m128 v209; // xmm8
  __m128 v210; // xmm0
  __m128 *v211; // rax
  __m128 v212; // xmm0
  __m128 v213; // xmm6
  __m128 v214; // xmm0
  __int128 v215; // rax
  __m128 v216; // xmm3
  __m128 v217; // xmm0
  __m128 v218; // xmm0
  __m128 v219; // xmm5
  __m128 v220; // xmm3
  __m128 v221; // xmm5
  __m128 *v222; // rax
  bool v223; // cl
  __m128 v224; // xmm0
  __m128 v225; // xmm1
  __m128 *v226; // rax
  __m128 v227; // [rsp+20h] [rbp-B8h]
  __m128 v228; // [rsp+30h] [rbp-A8h]
  __m128 v229; // [rsp+40h] [rbp-98h]
  _BYTE v230[56]; // [rsp+50h] [rbp-88h] BYREF
  hkaiEdgePath::Edge *end; // [rsp+88h] [rbp-50h] BYREF
  __m128 v232; // [rsp+98h] [rbp-40h]
  __m128 v233; // [rsp+A8h] [rbp-30h] BYREF
  __m128 v234; // [rsp+B8h] [rbp-20h] BYREF
  __m128 v235; // [rsp+C8h] [rbp-10h]
  __m128 v236; // [rsp+D8h] [rbp+0h]
  __m128 v237; // [rsp+E8h] [rbp+10h] BYREF
  __m128 v238; // [rsp+F8h] [rbp+20h] BYREF
  __m128 v239; // [rsp+108h] [rbp+30h]
  __m128 v240; // [rsp+118h] [rbp+40h] BYREF
  __m128 v241; // [rsp+128h] [rbp+50h]
  hkVector4f p; // [rsp+138h] [rbp+60h] BYREF
  __m128 v243; // [rsp+148h] [rbp+70h]
  __m128 v244; // [rsp+158h] [rbp+80h] BYREF
  __m128 m_quad; // [rsp+168h] [rbp+90h]
  hkMatrix4f relativeTransformOut; // [rsp+178h] [rbp+A0h] BYREF
  __m128 v247; // [rsp+1B8h] [rbp+E0h]
  __m128i inserted; // [rsp+1C8h] [rbp+F0h]
  __m128 v249; // [rsp+1D8h] [rbp+100h]
  hkaiEdgePath::Edge *begin; // [rsp+2C8h] [rbp+1F0h] BYREF
  hkaiStreamingCollection *retaddr; // [rsp+2D8h] [rbp+200h]
  __m128 *v252; // [rsp+2E0h] [rbp+208h]
  __m128 *v253; // [rsp+2E8h] [rbp+210h]
  __m128 *v254; // [rsp+2F0h] [rbp+218h]
  _OWORD *v255; // [rsp+2F8h] [rbp+220h]

  Edge = hkaiEdgePath::getEdge(edgePath, 0);
  v16 = 0i64;
  *v255 = 0i64;
  m_quad = positionIn->m_quad;
  v17 = Edge;
  v18 = 0;
  hkaiEdgePath::getFutureEdgeRange(edgePath, traversalState, &begin, &end);
  if ( begin == end )
    return 4;
  v20.m_quad = (__m128)begin->m_up;
  v229 = v20.m_quad;
  result = hkaiEdgePathSteeringUtil::getRelativeTransform(positionSectionIndex, begin, retaddr, &relativeTransformOut);
  if ( result == RESULT_SUCCESS )
  {
    v21 = begin;
    v22 = end;
    p_m_quad = 0i64;
    v24 = 0;
    v25 = 0;
    v26 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_001), (__m128)LODWORD(FLOAT_0_001), 0);
    v27 = 0i64;
    v28 = 0i64;
    v29 = 0i64;
    v247 = _mm_sub_ps((__m128)0i64, v26);
    p.m_quad = 0i64;
    v233 = v26;
    if ( begin == end )
    {
LABEL_11:
      *v252 = v27;
      *v253 = v16;
      *v254 = v28;
LABEL_12:
      v95 = (char *)p_m_quad - (char *)v17;
LABEL_13:
      v96 = v95 * (__int128)0xE38E38E38E38E39i64;
LABEL_14:
      LODWORD(streamingCollection->vfptr) = (*((_QWORD *)&v96 + 1) >> 63) + (*((__int64 *)&v96 + 1) >> 3);
      forwardVector->m_quad.m128_i8[0] = 1;
      return 0;
    }
    else
    {
      v30.m_quad = (__m128)relativeTransformOut.m_col3;
      v31.m_quad = (__m128)relativeTransformOut.m_col2;
      v32.m_quad = (__m128)relativeTransformOut.m_col1;
      p_m_col2 = &begin->m_followingTransform.m_col2;
      v34.m_quad = (__m128)relativeTransformOut.m_col0;
      v35 = _mm_shuffle_ps(v20.m_quad, v20.m_quad, 201);
      v228 = v35;
      while ( 1 )
      {
        v36 = v21->m_left.m_quad;
        p_m_quad = &v21->m_left.m_quad;
        v37 = v21;
        v38 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v36, v36, 0), v34.m_quad), v30.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(v21->m_left.m_quad, v21->m_left.m_quad, 85), v32.m_quad)),
                _mm_mul_ps(_mm_shuffle_ps(v21->m_left.m_quad, v21->m_left.m_quad, 170), v31.m_quad));
        v39 = _mm_unpackhi_ps(v38, _mm_shuffle_ps(v36, v36, 255));
        v40 = p_m_col2[-4].m_quad;
        v227 = _mm_shuffle_ps(v38, v39, 196);
        v41 = _mm_sub_ps(v227, m_quad);
        v237 = v227;
        v42 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v40, v40, 0), v34.m_quad), v30.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(v40, v40, 85), v32.m_quad)),
                _mm_mul_ps(_mm_shuffle_ps(v40, v40, 170), v31.m_quad));
        v43 = _mm_mul_ps(v20.m_quad, v41);
        v44 = _mm_shuffle_ps(v42, _mm_unpackhi_ps(v42, _mm_shuffle_ps(v40, v40, 255)), 196);
        *(_QWORD *)&v230[40] = v44.m128_u64[1];
        v244 = v44;
        v236 = _mm_sub_ps(v44, m_quad);
        v45 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v43, v43, 85), _mm_shuffle_ps(v43, v43, 0)),
                _mm_shuffle_ps(v43, v43, 170));
        v46 = _mm_mul_ps(v20.m_quad, v236);
        v47 = _mm_sub_ps(v41, _mm_mul_ps(v45, v20.m_quad));
        v48 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v46, v46, 85), _mm_shuffle_ps(v46, v46, 0)),
                _mm_shuffle_ps(v46, v46, 170));
        v49 = _mm_mul_ps(v47, v47);
        v50 = _mm_sub_ps(v236, _mm_mul_ps(v48, v20.m_quad));
        v51 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v49, v49, 85), _mm_shuffle_ps(v49, v49, 0)),
                _mm_shuffle_ps(v49, v49, 170));
        v52 = _mm_mul_ps(v50, v50);
        v53 = _mm_unpacklo_ps(
                v51,
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v52, v52, 85), _mm_shuffle_ps(v52, v52, 0)),
                  _mm_shuffle_ps(v52, v52, 170)));
        v54 = _mm_movelh_ps(v53, v53);
        v55 = _mm_rsqrt_ps(v54);
        v56 = _mm_andnot_ps(
                _mm_cmple_ps(v54, v16),
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v54, v55), v55)),
                  _mm_mul_ps(v55, *(__m128 *)_xmm)));
        v57 = (__m128i)_mm_shuffle_ps(v227, v227, 255);
        v58 = _mm_mul_ps(_mm_shuffle_ps(v56, v56, 0), v47);
        v59 = (__m128)_mm_slli_epi32(_mm_srli_epi32(v57, 0x1Fu), 0x1Fu);
        *(__m128 *)&v230[24] = _mm_mul_ps(_mm_shuffle_ps(v56, v56, 85), v50);
        v60 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v58, v58, 201), v20.m_quad), _mm_mul_ps(v58, v35));
        v61 = _mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v230[24], *(__m128 *)&v230[24], 201), v20.m_quad),
                _mm_mul_ps(*(__m128 *)&v230[24], v228));
        v62 = (__m128i)_mm_shuffle_ps(*(__m128 *)&v230[32], *(__m128 *)&v230[32], 255);
        v63 = (__m128)_mm_slli_epi32(_mm_srli_epi32(v62, 0x1Fu), 0x1Fu);
        v64 = _mm_unpacklo_ps((__m128)v57, (__m128)v62);
        v65 = _mm_xor_ps(_mm_shuffle_ps(v61, v61, 201), v63);
        *(__m128 *)&v230[40] = v63;
        v66 = _mm_movelh_ps(v64, v64);
        *(__m128 *)v230 = _mm_xor_ps(_mm_shuffle_ps(v60, v60, 201), v59);
        v67 = _mm_mul_ps(v66, v66);
        v68 = _mm_sub_ps(v54, v67);
        v69 = _mm_cmple_ps(v68, (__m128)0i64);
        v70 = _mm_or_ps(
                _mm_andnot_ps(v69, _mm_mul_ps(_mm_shuffle_ps(v67, v68, 228), v68)),
                _mm_and_ps(v69, `hkaiEdgePathSteeringUtil::calcTangentDirs::`2::insideLenFactorsQuad));
        v71 = _mm_rsqrt_ps(v70);
        v72 = _mm_mul_ps(
                _mm_andnot_ps(
                  _mm_cmple_ps(v70, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v71, v70), v71)),
                      _mm_mul_ps(v71, *(__m128 *)_xmm)),
                    v70)),
                v56);
        v73 = _mm_shuffle_ps(v72, v72, 170);
        v74 = (p_m_col2[3].m_quad.m128_i8[0] & 0x10) == 0;
        v75 = _mm_shuffle_ps(v72, v72, 0);
        v76 = _mm_mul_ps(*(__m128 *)v230, v73);
        v77 = _mm_mul_ps(v58, v73);
        v78 = p_m_col2[-2].m_quad;
        v79 = _mm_add_ps(_mm_mul_ps(*(__m128 *)v230, v75), v77);
        v80 = *(__m128 *)&v230[24];
        *(__m128 *)&v230[16] = v79;
        v238 = v79;
        v81 = _mm_sub_ps(v76, _mm_mul_ps(v58, v75));
        v82 = p_m_col2[-1].m_quad;
        v234 = _mm_shuffle_ps(v72, v72, 85);
        *(__m128 *)&v230[8] = _mm_shuffle_ps(v72, v72, 255);
        v83 = _mm_mul_ps(v80, *(__m128 *)&v230[8]);
        v84 = p_m_col2[1].m_quad;
        *(__m128 *)v230 = _mm_xor_ps(v81, v59);
        v85 = _mm_add_ps(_mm_mul_ps(v65, v234), v83);
        v86 = p_m_col2->m_quad;
        v232 = v85;
        v240 = v85;
        v87 = _mm_mul_ps(_mm_shuffle_ps(v78, v78, 85), v32.m_quad);
        v88 = _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v86, v86, 85), v32.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v86, v86, 0), v34.m_quad));
        v89 = _mm_mul_ps(_mm_shuffle_ps(v84, v84, 85), v32.m_quad);
        v32.m_quad = _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v82, v82, 170), v31.m_quad),
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v82, v82, 85), v32.m_quad),
                         _mm_mul_ps(_mm_shuffle_ps(v82, v82, 0), v34.m_quad)));
        v16 = 0i64;
        v243 = v32.m_quad;
        v30.m_quad = _mm_add_ps(
                       _mm_add_ps(_mm_add_ps(v30.m_quad, _mm_mul_ps(_mm_shuffle_ps(v84, v84, 0), v34.m_quad)), v89),
                       _mm_mul_ps(_mm_shuffle_ps(v84, v84, 170), v31.m_quad));
        v90 = _mm_shuffle_ps(v78, v78, 0);
        v91 = _mm_mul_ps(_mm_shuffle_ps(v78, v78, 170), v31.m_quad);
        v31.m_quad = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v86, v86, 170), v31.m_quad), v88);
        v235 = v31.m_quad;
        v34.m_quad = _mm_add_ps(_mm_add_ps(v87, _mm_mul_ps(v90, v34.m_quad)), v91);
        v241 = v34.m_quad;
        if ( !v74 )
          break;
        v27 = *(__m128 *)&v230[16];
        v92 = _mm_mul_ps(
                _mm_xor_ps(
                  _mm_sub_ps(_mm_mul_ps(v65, *(__m128 *)&v230[8]), _mm_mul_ps(*(__m128 *)&v230[24], v234)),
                  *(__m128 *)&v230[40]),
                *(__m128 *)&v230[16]);
        if ( (float)((float)(_mm_shuffle_ps(v92, v92, 85).m128_f32[0] + _mm_shuffle_ps(v92, v92, 0).m128_f32[0])
                   + _mm_shuffle_ps(v92, v92, 170).m128_f32[0]) > v233.m128_f32[0] )
          goto LABEL_23;
        v93 = _mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(v41, v41, 201), v236),
                _mm_mul_ps(_mm_shuffle_ps(v236, v236, 201), v41));
        v94 = _mm_mul_ps(_mm_shuffle_ps(v93, v93, 201), v229);
        if ( (float)((float)(_mm_shuffle_ps(v94, v94, 85).m128_f32[0] + _mm_shuffle_ps(v94, v94, 0).m128_f32[0])
                   + _mm_shuffle_ps(v94, v94, 170).m128_f32[0]) >= 0.0 )
        {
          if ( traversalState->m_faceEdge >= 0 )
          {
            v97 = _mm_mul_ps(*(__m128 *)&v230[16], *(__m128 *)&v230[16]);
            v98 = _mm_mul_ps(v85, v85);
            v99 = &v238;
            v100 = (float)(_mm_shuffle_ps(v97, v97, 85).m128_f32[0] + _mm_shuffle_ps(v97, v97, 0).m128_f32[0])
                 + _mm_shuffle_ps(v97, v97, 170).m128_f32[0];
            v101 = (float)(_mm_shuffle_ps(v98, v98, 85).m128_f32[0] + _mm_shuffle_ps(v98, v98, 0).m128_f32[0])
                 + _mm_shuffle_ps(v98, v98, 170).m128_f32[0];
            forwardVector->m_quad.m128_i8[0] = v100 < v101;
            if ( v100 >= v101 )
              v99 = &v240;
            v102 = *v99;
            *v252 = *v99;
            v103 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v102, v102, 201), v229), _mm_mul_ps(v102, v228));
            *v253 = _mm_shuffle_ps(v103, v103, 201);
            v104 = &v237;
            if ( !forwardVector->m_quad.m128_i8[0] )
              v104 = &v244;
            *v254 = *v104;
            LODWORD(streamingCollection->vfptr) = v21 - v17;
            return 0;
          }
LABEL_23:
          v28 = v227;
          goto LABEL_28;
        }
        v35 = v228;
        ++v21;
        p_m_col2 += 9;
        v20.m_quad = v229;
        if ( v21 == end )
        {
          v28 = v227;
          goto LABEL_11;
        }
      }
      v105 = _mm_mul_ps(*(__m128 *)v230, v85);
      if ( (float)((float)(_mm_shuffle_ps(v105, v105, 85).m128_f32[0] + _mm_shuffle_ps(v105, v105, 0).m128_f32[0])
                 + _mm_shuffle_ps(v105, v105, 170).m128_f32[0]) <= 0.0 )
      {
        v27 = *(__m128 *)&v230[16];
        v106 = *(__m128 *)&v230[32];
        v28 = v227;
      }
      else
      {
        v106 = v227;
        v27 = v85;
        v232 = *(__m128 *)&v230[16];
        v28 = *(__m128 *)&v230[32];
        *(__m128 *)&v230[16] = v85;
        v227 = *(__m128 *)&v230[32];
        *(__m128 *)&v230[32] = v106;
      }
      v107 = _mm_sub_ps(v106, v28);
      v18 = 1;
      v25 = 1;
      v108 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v107, v107, 201), v229), _mm_mul_ps(v107, v228));
      v109 = _mm_shuffle_ps(v108, v108, 201);
      v110 = _mm_mul_ps(v109, v109);
      v111 = _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v110, v110, 85), _mm_shuffle_ps(v110, v110, 0)),
               _mm_shuffle_ps(v110, v110, 170));
      v112 = _mm_rsqrt_ps(v111);
      v113 = _mm_mul_ps(
               v109,
               _mm_andnot_ps(
                 _mm_cmple_ps(v111, (__m128)0i64),
                 _mm_mul_ps(
                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v112, v111), v112)),
                   _mm_mul_ps(*(__m128 *)_xmm, v112))));
      v114 = _mm_mul_ps(v113, v28);
      v29 = _mm_shuffle_ps(
              v113,
              _mm_unpackhi_ps(
                v113,
                _mm_sub_ps(
                  (__m128)0i64,
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v114, v114, 85), _mm_shuffle_ps(v114, v114, 0)),
                    _mm_shuffle_ps(v114, v114, 170)))),
              196);
      p.m_quad = v29;
      *v255 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v29);
LABEL_28:
      v115 = &v21[1].m_left.m_quad;
      if ( v115 == (__m128 *)v22 )
        goto LABEL_11;
      v116 = v115 + 5;
      inserted = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
      v249 = (__m128)_mm_shuffle_epi32(inserted, 64);
      while ( 2 )
      {
        v117 = *v115;
        v118 = v116[-4];
        v119 = _mm_shuffle_ps(*v115, *v115, 85);
        v120 = _mm_shuffle_ps(*v115, *v115, 170);
        v244 = _mm_shuffle_ps(v117, v117, 0);
        v237 = v119;
        v240 = v120;
        v239 = v117;
        *(_QWORD *)v230 = v118.m128_u64[0];
        v121 = _mm_add_ps(
                 _mm_add_ps(_mm_add_ps(_mm_mul_ps(v244, v34.m_quad), v30.m_quad), _mm_mul_ps(v119, v32.m_quad)),
                 _mm_mul_ps(v120, v31.m_quad));
        v238 = _mm_shuffle_ps(v118, v118, 0);
        v236 = _mm_shuffle_ps(v118, v118, 85);
        *(__m128 *)&v230[8] = _mm_shuffle_ps(v118, v118, 170);
        v122 = _mm_add_ps(
                 _mm_add_ps(_mm_add_ps(_mm_mul_ps(v238, v34.m_quad), v30.m_quad), _mm_mul_ps(v236, v32.m_quad)),
                 _mm_mul_ps(*(__m128 *)&v230[8], v31.m_quad));
        if ( v25 )
        {
          v123 = _mm_mul_ps(v121, v29);
          v124 = _mm_shuffle_ps(v123, _mm_unpackhi_ps(v123, v29), 196);
          v125 = _mm_add_ps(_mm_shuffle_ps(v124, v124, 78), v124);
          if ( (float)(_mm_shuffle_ps(v125, v125, 177).m128_f32[0] + v125.m128_f32[0]) < v16.m128_f32[0] )
          {
            v126 = _mm_mul_ps(v122, v29);
            v127 = _mm_shuffle_ps(v126, _mm_unpackhi_ps(v126, v29), 196);
            v128 = _mm_add_ps(_mm_shuffle_ps(v127, v127, 78), v127);
            if ( (float)(_mm_shuffle_ps(v128, v128, 177).m128_f32[0] + v128.m128_f32[0]) < v16.m128_f32[0] )
            {
              makeReflectionMatrix(&p, &relativeTransformOut);
              v24 = !v24;
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
              v243 = _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v32.m_quad, v32.m_quad, 85), relativeTransformOut.m_col1.m_quad),
                         _mm_mul_ps(_mm_shuffle_ps(v32.m_quad, v32.m_quad, 0), relativeTransformOut.m_col0.m_quad)),
                       _mm_mul_ps(_mm_shuffle_ps(v32.m_quad, v32.m_quad, 170), relativeTransformOut.m_col2.m_quad));
              v241 = _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v34.m_quad, v34.m_quad, 85), relativeTransformOut.m_col1.m_quad),
                         _mm_mul_ps(_mm_shuffle_ps(v34.m_quad, v34.m_quad, 0), relativeTransformOut.m_col0.m_quad)),
                       _mm_mul_ps(_mm_shuffle_ps(v34.m_quad, v34.m_quad, 170), relativeTransformOut.m_col2.m_quad));
              v118 = *(__m128 *)v230;
              v235 = _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v31.m_quad, v235, 85), relativeTransformOut.m_col1.m_quad),
                         _mm_mul_ps(_mm_shuffle_ps(v235, v235, 0), relativeTransformOut.m_col0.m_quad)),
                       _mm_mul_ps(_mm_shuffle_ps(v235, v235, 170), relativeTransformOut.m_col2.m_quad));
              v121 = _mm_add_ps(
                       _mm_add_ps(_mm_add_ps(_mm_mul_ps(v244, v241), v30.m_quad), _mm_mul_ps(v237, v243)),
                       _mm_mul_ps(v240, v235));
              v122 = _mm_add_ps(
                       _mm_add_ps(_mm_add_ps(_mm_mul_ps(v238, v241), v30.m_quad), _mm_mul_ps(v236, v243)),
                       _mm_mul_ps(*(__m128 *)&v230[8], v235));
            }
          }
          v117 = v239;
          v25 = 0;
        }
        v129 = _mm_shuffle_ps(v117, v117, 255);
        v130 = _mm_shuffle_ps(v118, v118, 255);
        if ( v24 )
        {
          v131 = _mm_shuffle_ps(v121, _mm_unpackhi_ps(v121, _mm_sub_ps(v16, v129)), 196);
          v132 = _mm_shuffle_ps(v122, _mm_unpackhi_ps(v122, _mm_sub_ps(v16, v130)), 196);
        }
        else
        {
          v132 = _mm_shuffle_ps(v121, _mm_unpackhi_ps(v121, v129), 196);
          v131 = _mm_shuffle_ps(v122, _mm_unpackhi_ps(v122, v130), 196);
        }
        v133 = _mm_sub_ps(v132, m_quad);
        v134 = _mm_sub_ps(v131, m_quad);
        *(__m128 *)&v230[24] = v131;
        *(__m128 *)&v230[40] = v132;
        v135 = _mm_mul_ps(v133, v229);
        *(__m128 *)v230 = v132;
        v136 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v135, v135, 85), _mm_shuffle_ps(v135, v135, 0)),
                 _mm_shuffle_ps(v135, v135, 170));
        v137 = _mm_mul_ps(v134, v229);
        v138 = _mm_sub_ps(v133, _mm_mul_ps(v136, v229));
        v139 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v137, v137, 85), _mm_shuffle_ps(v137, v137, 0)),
                 _mm_shuffle_ps(v137, v137, 170));
        v140 = _mm_mul_ps(v138, v138);
        v141 = _mm_sub_ps(v134, _mm_mul_ps(v139, v229));
        v142 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v140, v140, 85), _mm_shuffle_ps(v140, v140, 0)),
                 _mm_shuffle_ps(v140, v140, 170));
        v143 = _mm_mul_ps(v141, v141);
        v144 = _mm_unpacklo_ps(
                 v142,
                 _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v143, v143, 85), _mm_shuffle_ps(v143, v143, 0)),
                   _mm_shuffle_ps(v143, v143, 170)));
        v145 = _mm_movelh_ps(v144, v144);
        v146 = _mm_rsqrt_ps(v145);
        v147 = _mm_andnot_ps(
                 _mm_cmple_ps(v145, v16),
                 _mm_mul_ps(
                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v146, v145), v146)),
                   _mm_mul_ps(v146, *(__m128 *)_xmm)));
        v148 = (__m128i)_mm_shuffle_ps(v132, v132, 255);
        v149 = (__m128)_mm_slli_epi32(_mm_srli_epi32(v148, 0x1Fu), 0x1Fu);
        v150 = _mm_mul_ps(_mm_shuffle_ps(v147, v147, 0), v138);
        v151 = _mm_mul_ps(_mm_shuffle_ps(v147, v147, 85), v141);
        v152 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v150, v150, 201), v229), _mm_mul_ps(v150, v228));
        v153 = _mm_xor_ps(_mm_shuffle_ps(v152, v152, 201), v149);
        v154 = v116[3].m128_i8[0];
        v155 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v151, v151, 201), v229), _mm_mul_ps(v151, v228));
        v156 = (__m128i)_mm_shuffle_ps(v131, v131, 255);
        v157 = _mm_unpacklo_ps((__m128)v148, (__m128)v156);
        v158 = (__m128)_mm_slli_epi32(_mm_srli_epi32(v156, 0x1Fu), 0x1Fu);
        v159 = _mm_xor_ps(_mm_shuffle_ps(v155, v155, 201), v158);
        v160 = _mm_movelh_ps(v157, v157);
        v161 = _mm_mul_ps(v160, v160);
        v162 = _mm_sub_ps(v145, v161);
        v163 = _mm_cmple_ps(v162, (__m128)0i64);
        v164 = _mm_or_ps(
                 _mm_andnot_ps(v163, _mm_mul_ps(_mm_shuffle_ps(v161, v162, 228), v162)),
                 _mm_and_ps(v163, `hkaiEdgePathSteeringUtil::calcTangentDirs::`2::insideLenFactorsQuad));
        v165 = _mm_rsqrt_ps(v164);
        v166 = _mm_mul_ps(
                 _mm_andnot_ps(
                   _mm_cmple_ps(v164, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_mul_ps(
                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v165, v164), v165)),
                       _mm_mul_ps(v165, *(__m128 *)_xmm)),
                     v164)),
                 v147);
        v167 = _mm_shuffle_ps(v166, v166, 0);
        v168 = _mm_shuffle_ps(v166, v166, 170);
        v169 = _mm_add_ps(_mm_mul_ps(v167, v153), _mm_mul_ps(v168, v150));
        v233 = v169;
        v239 = _mm_shuffle_ps(v166, v166, 255);
        v170 = _mm_shuffle_ps(v166, v166, 85);
        v171 = _mm_mul_ps(v170, v151);
        v172 = _mm_add_ps(_mm_mul_ps(v170, v159), _mm_mul_ps(v239, v151));
        *(__m128 *)&v230[8] = v172;
        v234 = v172;
        v173 = _mm_xor_ps(_mm_sub_ps(_mm_mul_ps(v168, v153), _mm_mul_ps(v167, v150)), v149);
        v174 = _mm_xor_ps(_mm_sub_ps(_mm_mul_ps(v239, v159), v171), v158);
        v175 = v172;
        v176 = v154 & 0x10;
        if ( v176
          && (v177 = _mm_mul_ps(v173, v172),
              (float)((float)(_mm_shuffle_ps(v177, v177, 85).m128_f32[0] + _mm_shuffle_ps(v177, v177, 0).m128_f32[0])
                    + _mm_shuffle_ps(v177, v177, 170).m128_f32[0]) > 0.0) )
        {
          v178 = v131;
          *(__m128 *)&v230[40] = v131;
          v131 = *(__m128 *)v230;
          v233 = v175;
          v175 = v169;
          v234 = v169;
          v179 = v173;
          v173 = v174;
          *(_OWORD *)&v230[24] = *(_OWORD *)v230;
          v174 = v179;
        }
        else
        {
          v178 = *(__m128 *)v230;
        }
        v180 = *(__m128 *)&v230[16];
        v181 = v232;
        v182 = _mm_xor_ps(v174, v249);
        v183 = _mm_mul_ps(v182, v232);
        v184 = _mm_mul_ps(v182, *(__m128 *)&v230[16]);
        v185 = _mm_mul_ps(v173, v232);
        v186 = _mm_mul_ps(v173, *(__m128 *)&v230[16]);
        v187 = _mm_shuffle_ps(v185, v183, 68);
        v188 = _mm_shuffle_ps(v186, v184, 68);
        v189 = _mm_shuffle_ps(v186, v184, 238);
        v190 = _mm_add_ps(_mm_shuffle_ps(v188, v187, 221), _mm_shuffle_ps(v188, v187, 136));
        v191 = v233;
        v192 = _mm_add_ps(_mm_shuffle_ps(v189, _mm_shuffle_ps(v185, v183, 238), 136), v190);
        v193 = _mm_sub_ps(v233, v175);
        v194 = _mm_cmple_ps((__m128)0i64, v192);
        v195 = _mm_mul_ps(v193, v193);
        v197 = 0;
        if ( (float)((float)(_mm_shuffle_ps(v195, v195, 85).m128_f32[0] + _mm_shuffle_ps(v195, v195, 0).m128_f32[0])
                   + _mm_shuffle_ps(v195, v195, 170).m128_f32[0]) > v247.m128_f32[0] )
        {
          v196 = _mm_mul_ps(v173, v175);
          if ( (float)((float)(_mm_shuffle_ps(v196, v196, 85).m128_f32[0] + _mm_shuffle_ps(v196, v196, 0).m128_f32[0])
                     + _mm_shuffle_ps(v196, v196, 170).m128_f32[0]) > v247.m128_f32[0] )
            v197 = 1;
        }
        switch ( (v197 ? 0x10 : 0) | _mm_movemask_ps(v194) )
        {
          case 1:
          case 3:
            *(__m128 *)&v230[16] = v233;
            v227 = v178;
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
            v211 = v252;
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
            v211 = v252;
            goto LABEL_61;
          case 6:
          case 0x16:
          case 0x19:
          case 0x1B:
            v220 = _mm_mul_ps(v233, v233);
            v221 = _mm_mul_ps(v175, v175);
            v222 = &v233;
            v223 = (float)((float)(_mm_shuffle_ps(v220, v220, 85).m128_f32[0] + _mm_shuffle_ps(v220, v220, 0).m128_f32[0])
                         + _mm_shuffle_ps(v220, v220, 170).m128_f32[0]) < (float)((float)(_mm_shuffle_ps(v221, v221, 85).m128_f32[0]
                                                                                        + _mm_shuffle_ps(v221, v221, 0).m128_f32[0])
                                                                                + _mm_shuffle_ps(v221, v221, 170).m128_f32[0]);
            forwardVector->m_quad.m128_i8[0] = v223;
            if ( !v223 )
              v222 = &v234;
            v224 = *v222;
            *v252 = *v222;
            v225 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v224, v224, 201), v229), _mm_mul_ps(v228, v224));
            *v253 = _mm_shuffle_ps(v225, v225, 201);
            v226 = (__m128 *)&v230[40];
            if ( !forwardVector->m_quad.m128_i8[0] )
              v226 = (__m128 *)&v230[24];
            *v254 = *v226;
            LODWORD(streamingCollection->vfptr) = ((char *)v115 - (char *)v17) / 144;
            return 0;
          case 8:
          case 0xC:
            v232 = v175;
            v37 = (hkaiEdgePath::Edge *)v115;
            *(__m128 *)&v230[32] = v131;
            goto LABEL_51;
          case 9:
            *(__m128 *)&v230[16] = v233;
            v37 = (hkaiEdgePath::Edge *)v115;
            v227 = v178;
            v232 = v175;
            *(__m128 *)&v230[32] = v131;
LABEL_50:
            p_m_quad = v115;
            goto LABEL_51;
          case 0xF:
          case 0x10:
            v211 = v252;
            v216 = _mm_mul_ps(v233, v232);
            if ( (float)((float)(_mm_shuffle_ps(v216, v216, 85).m128_f32[0] + _mm_shuffle_ps(v216, v216, 0).m128_f32[0])
                       + _mm_shuffle_ps(v216, v216, 170).m128_f32[0]) <= 0.0 )
            {
LABEL_59:
              *v211 = *(__m128 *)&v230[16];
              v212 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v180, v180, 201), v229), _mm_mul_ps(v180, v228));
              *v253 = _mm_shuffle_ps(v212, v212, 201);
              *v254 = v227;
              goto LABEL_12;
            }
LABEL_61:
            *v211 = v232;
            v213 = _mm_sub_ps(_mm_mul_ps(v181, v228), _mm_mul_ps(_mm_shuffle_ps(v181, v181, 201), v229));
            v214 = *(__m128 *)&v230[32];
            *v253 = _mm_shuffle_ps(v213, v213, 201);
            *v254 = v214;
            v215 = ((char *)v37 - (char *)v17) * (__int128)0xE38E38E38E38E39i64;
LABEL_62:
            LODWORD(streamingCollection->vfptr) = (*((_QWORD *)&v215 + 1) >> 63) + (*((__int64 *)&v215 + 1) >> 3);
            forwardVector->m_quad.m128_i8[0] = 0;
            return 0;
          case 0x1D:
            *v252 = v175;
            v219 = _mm_sub_ps(_mm_mul_ps(v175, v228), _mm_mul_ps(_mm_shuffle_ps(v175, v175, 201), v229));
            *v253 = _mm_shuffle_ps(v219, v219, 201);
            *v254 = v131;
            v215 = ((char *)v115 - (char *)v17) * (__int128)0xE38E38E38E38E39i64;
            goto LABEL_62;
          case 0x1F:
            v217 = _mm_mul_ps(_mm_shuffle_ps(v233, v233, 201), v229);
            *v252 = v233;
            v218 = _mm_sub_ps(v217, _mm_mul_ps(v191, v228));
            *v253 = _mm_shuffle_ps(v218, v218, 201);
            *v254 = v178;
            v96 = ((char *)v115 - (char *)v17) * (__int128)0xE38E38E38E38E39i64;
            goto LABEL_14;
          default:
LABEL_51:
            v198 = v116[-2];
            v199 = _mm_mul_ps(_mm_shuffle_ps(v198, v198, 85), v243);
            v200 = _mm_shuffle_ps(v198, v198, 0);
            v30.m_quad = _mm_add_ps(
                           _mm_add_ps(
                             _mm_add_ps(v30.m_quad, _mm_mul_ps(_mm_shuffle_ps(v116[1], v116[1], 0), v241)),
                             _mm_mul_ps(_mm_shuffle_ps(v116[1], v116[1], 85), v243)),
                           _mm_mul_ps(_mm_shuffle_ps(v116[1], v116[1], 170), v235));
            v201 = _mm_mul_ps(_mm_shuffle_ps(v198, v198, 170), v235);
            v32.m_quad = _mm_add_ps(
                           _mm_add_ps(
                             _mm_mul_ps(_mm_shuffle_ps(v116[-1], v116[-1], 85), v243),
                             _mm_mul_ps(_mm_shuffle_ps(v116[-1], v116[-1], 0), v241)),
                           _mm_mul_ps(_mm_shuffle_ps(v116[-1], v116[-1], 170), v235));
            v31.m_quad = _mm_add_ps(
                           _mm_add_ps(
                             _mm_mul_ps(_mm_shuffle_ps(*v116, *v116, 85), v243),
                             _mm_mul_ps(_mm_shuffle_ps(*v116, *v116, 0), v241)),
                           _mm_mul_ps(_mm_shuffle_ps(*v116, *v116, 170), v235));
            v16 = 0i64;
            v243 = v32.m_quad;
            v235 = v31.m_quad;
            v34.m_quad = _mm_add_ps(_mm_add_ps(v199, _mm_mul_ps(v200, v241)), v201);
            v241 = v34.m_quad;
            if ( v176 )
            {
              v202 = _mm_sub_ps(v131, v178);
              v203 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v202, v202, 201), v229), _mm_mul_ps(v202, v228));
              v204 = _mm_shuffle_ps(v203, v203, 201);
              v205 = _mm_mul_ps(v204, v204);
              v206 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v205, v205, 85), _mm_shuffle_ps(v205, v205, 0)),
                       _mm_shuffle_ps(v205, v205, 170));
              v207 = _mm_rsqrt_ps(v206);
              v208 = _mm_mul_ps(
                       v204,
                       _mm_andnot_ps(
                         _mm_cmple_ps(v206, (__m128)0i64),
                         _mm_mul_ps(
                           _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v207, v206), v207)),
                           _mm_mul_ps(v207, *(__m128 *)_xmm))));
              v209 = _mm_mul_ps(v178, v208);
              v29 = _mm_shuffle_ps(
                      v208,
                      _mm_unpackhi_ps(
                        v208,
                        _mm_sub_ps(
                          (__m128)0i64,
                          _mm_add_ps(
                            _mm_add_ps(_mm_shuffle_ps(v209, v209, 85), _mm_shuffle_ps(v209, v209, 0)),
                            _mm_shuffle_ps(v209, v209, 170)))),
                      196);
              p.m_quad = v29;
              if ( !v18 )
              {
                v18 = 1;
                *v255 = _mm_xor_ps((__m128)_mm_shuffle_epi32(inserted, 0), v29);
              }
              v25 = 1;
            }
            v115 += 9;
            v116 += 9;
            if ( v115 != (__m128 *)v22 )
              continue;
            v210 = _mm_cmpeq_ps(p_m_quad[1], *p_m_quad);
            v95 = (char *)p_m_quad - (char *)v17;
            if ( _mm_movemask_ps(v210) == 15 )
            {
              *v252 = *(__m128 *)&v230[16];
              *v254 = v227;
              *v253 = 0i64;
              goto LABEL_13;
            }
            *v252 = _mm_add_ps(
                      _mm_mul_ps(_mm_sub_ps(v232, *(__m128 *)&v230[16]), (__m128)xmmword_141A711B0),
                      *(__m128 *)&v230[16]);
            *v254 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(*(__m128 *)&v230[32], v227), (__m128)xmmword_141A711B0), v227);
            *v253 = 0i64;
            LODWORD(streamingCollection->vfptr) = v95 / 144;
            forwardVector->m_quad.m128_i8[0] = 1;
            result = RESULT_HIT_END;
            break;
        }
        break;
      }
    }
  }
  return result;
}

// File Line: 487
// RVA: 0xC12140
hkaiEdgePathSteeringUtil::CalcForwardVectorResult __fastcall hkaiEdgePathSteeringUtil::calcForwardVector(
        hkaiEdgePath *edgePath,
        hkaiEdgePath::TraversalState *traversalState,
        hkVector4f *positionLocal,
        int positionSectionIndex,
        hkaiStreamingCollection *streamingCollection,
        hkVector4f *forwardVectorLocal,
        hkVector4f *futureVectorLocal,
        hkVector4f *nextCornerLocal,
        hkVector4f *nextUserEdgePlane)
{
  bool v10; // [rsp+60h] [rbp-18h] BYREF
  int v11[5]; // [rsp+64h] [rbp-14h] BYREF

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
           v11,
           &v10);
}

// File Line: 511
// RVA: 0xC121B0
__int64 __fastcall hkaiEdgePathSteeringUtil::calcForwardVector_corner(
        hkaiEdgePath *edgePath,
        int edgeIndex,
        bool edgeIsLeft,
        int *nextEdgeIndex,
        bool *nextIsLeft)
{
  int v7; // esi
  hkaiEdgePath::Edge *Edge; // rax
  int v10; // r15d
  char v11; // r12
  __m128 m_quad; // xmm14
  hkaiEdgePath::Edge *v13; // rbx
  __m128 v14; // xmm11
  int NumEdges; // r13d
  __int64 result; // rax
  bool v17; // zf
  __m128 *p_m_quad; // rdi
  __m128 v19; // xmm15
  __m128 v20; // xmm15
  __m128 v21; // xmm2
  __m128 v22; // xmm3
  __m128 v23; // xmm2
  __m128 v24; // xmm1
  __m128 v25; // xmm9
  __m128 v26; // xmm13
  __m128 v27; // xmm6
  __m128 v28; // xmm7
  __m128 v29; // xmm11
  __m128 v30; // xmm11
  __m128 v31; // xmm11
  __m128 v32; // xmm1
  __m128 v33; // xmm3
  __m128 v34; // xmm2
  __m128 v35; // xmm11
  __m128 v36; // xmm2
  int v37; // ebx
  _BYTE *v38; // rax
  __m128 v39; // xmm0
  hkaiEdgePath::Edge *v40; // rdi
  __m128 v41; // xmm12
  __m128 v42; // xmm1
  __m128 v43; // xmm2
  __m128 v44; // xmm0
  __m128 v45; // xmm1
  __m128 v46; // xmm13
  __m128 v47; // xmm8
  __m128 v48; // xmm3
  __m128 v49; // xmm2
  __m128 v50; // xmm2
  __m128 v51; // xmm1
  __m128 v52; // xmm2
  __m128 v53; // xmm2
  __m128 v54; // xmm1
  __m128 v55; // xmm9
  __m128 v56; // xmm8
  __m128 v57; // xmm12
  __m128 v58; // xmm13
  __m128 v59; // xmm8
  __m128 v60; // xmm12
  __m128 v61; // xmm3
  float v62; // xmm4_4
  __m128 v63; // xmm1
  __m128 v64; // xmm3
  __m128 v65; // xmm3
  __m128 v66; // xmm7
  __m128 v67; // xmm6
  __m128 v68; // xmm9
  __m128 v69; // xmm9
  __m128 v70; // xmm7
  __m128 v71; // xmm3
  __m128 v72; // xmm3
  char v73; // dl
  __m128 v74; // xmm2
  __m128 v75; // xmm0
  __m128 v76; // xmm1
  __m128 v77; // xmm0
  __m128 v78; // xmm5
  __m128 v79; // xmm2
  __m128 v80; // xmm0
  __m128 v81; // xmm4
  __m128 v82; // xmm0
  __m128 v83; // xmm1
  __m128 v84; // xmm3
  __m128 v85; // xmm5
  __m128 v86; // xmm2
  __m128 v87; // xmm2
  __m128 v88; // xmm3
  __m128 v89; // xmm2
  bool v90; // al
  int v91; // ecx
  __m128 v92; // xmm13
  __m128 v93; // xmm5
  __m128 v94; // xmm4
  __m128 v95; // xmm2
  __m128 v96; // xmm1
  __m128 v97; // xmm0
  __m128 v98; // xmm2
  __m128 v99; // xmm1
  __m128 v100; // xmm8
  __m128 v101; // xmm11
  __m128 v102; // xmm11
  __m128 v103; // xmm1
  __m128 v104; // xmm3
  __m128 v105; // xmm2
  __m128 v106; // xmm11
  __m128 v107; // xmm12
  _BYTE *v108; // rax
  _BYTE *v109; // rax
  _BYTE *v110; // rax
  __m128 v111; // xmm6
  _BYTE *v112; // rax
  bool *v113; // rax
  __m128 v114; // xmm6
  __m128 v115; // xmm7
  _BYTE *v116; // rax
  __m128 v117; // [rsp+30h] [rbp-98h]
  __m128 v118; // [rsp+40h] [rbp-88h]
  _BYTE bIn[56]; // [rsp+50h] [rbp-78h] BYREF
  hkVector4f aIn; // [rsp+88h] [rbp-40h] BYREF
  hkVector4f up; // [rsp+98h] [rbp-30h] BYREF
  hkVector4f p; // [rsp+A8h] [rbp-20h] BYREF
  __m128 v123; // [rsp+B8h] [rbp-10h]
  __m128 v124; // [rsp+C8h] [rbp+0h]
  __m128 v125; // [rsp+D8h] [rbp+10h]
  hkVector4f bTangentPoint; // [rsp+E8h] [rbp+20h] BYREF
  __m128 v127; // [rsp+F8h] [rbp+30h]
  hkVector4f v128; // [rsp+108h] [rbp+40h] BYREF
  __m128 v129; // [rsp+118h] [rbp+50h]
  hkVector4f v130; // [rsp+128h] [rbp+60h] BYREF
  __m128 v131; // [rsp+138h] [rbp+70h]
  hkVector4f v132; // [rsp+148h] [rbp+80h] BYREF
  __m128 v133; // [rsp+158h] [rbp+90h]
  __m128 v134; // [rsp+168h] [rbp+A0h]
  __m128 v135; // [rsp+178h] [rbp+B0h]
  hkMatrix4f m; // [rsp+188h] [rbp+C0h] BYREF
  hkaiEdgePath *v137; // [rsp+2A8h] [rbp+1E0h]
  bool v138; // [rsp+2B0h] [rbp+1E8h]
  char v139; // [rsp+2B8h] [rbp+1F0h]
  _BYTE *v140; // [rsp+2C8h] [rbp+200h]

  v7 = edgeIndex;
  Edge = hkaiEdgePath::getEdge(edgePath, edgeIndex);
  v10 = v7;
  v138 = 0;
  v11 = 0;
  m_quad = Edge->m_up.m_quad;
  v13 = Edge;
  *(hkVector4f *)bIn = (hkVector4f)stru_141A71280.m_quad;
  v118 = qi.m_vec.m_quad;
  up.m_quad = m_quad;
  v118.m128_f32[2] = FLOAT_0_001;
  v14 = 0i64;
  p.m_quad = 0i64;
  v124 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_001), (__m128)LODWORD(FLOAT_0_001), 0);
  v134 = _mm_sub_ps((__m128)0i64, v124);
  NumEdges = hkaiEdgePath::getNumEdges(edgePath);
  if ( v7 == NumEdges - 1 )
    return 4i64;
  v17 = !edgeIsLeft;
  p_m_quad = &v13->m_right.m_quad;
  if ( v17 )
  {
    v20 = *p_m_quad;
    v21 = *p_m_quad;
    *(_OWORD *)&bIn[32] = 0i64;
    v19 = _mm_shuffle_ps(v20, _mm_unpackhi_ps(v21, _mm_sub_ps((__m128)0i64, _mm_shuffle_ps(v20, v20, 255))), 196);
    aIn.m_quad = v19;
    hkaiEdgePathSteeringUtil::calcMutualTangentPoints(
      &aIn,
      &v13->m_left,
      &up,
      (hkVector4f *)&bIn[24],
      (hkVector4f *)&bIn[8]);
    v117 = _mm_sub_ps(*(__m128 *)&bIn[8], *(__m128 *)&bIn[24]);
  }
  else
  {
    v117 = 0i64;
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
      (hkVector4f *)&bIn[24],
      (hkVector4f *)&bIn[8]);
    *(__m128 *)&bIn[32] = _mm_sub_ps(*(__m128 *)&bIn[8], *(__m128 *)&bIn[24]);
  }
  v17 = (v13->m_flags.m_storage & 0x10) == 0;
  v22 = v13->m_followingTransform.m_col2.m_quad;
  v23 = v13->m_followingTransform.m_col3.m_quad;
  v24 = v13->m_followingTransform.m_col0.m_quad;
  v25 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_shuffle_ps(v13->m_followingTransform.m_col1.m_quad, v13->m_followingTransform.m_col1.m_quad, 85),
              direction.m_quad),
            _mm_mul_ps(
              _mm_shuffle_ps(v13->m_followingTransform.m_col1.m_quad, v13->m_followingTransform.m_col1.m_quad, 0),
              transform.m_quad)),
          _mm_mul_ps(
            _mm_shuffle_ps(v13->m_followingTransform.m_col1.m_quad, v13->m_followingTransform.m_col1.m_quad, 170),
            *(__m128 *)bIn));
  *(__m128 *)&bIn[40] = v25;
  v26 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v22, v22, 85), direction.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v22, v22, 0), transform.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v22, v22, 170), *(__m128 *)bIn));
  *(__m128 *)&bIn[16] = v26;
  v27 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v23, v23, 0), transform.m_quad), v118),
            _mm_mul_ps(_mm_shuffle_ps(v23, v23, 85), direction.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v23, v23, 170), *(__m128 *)bIn));
  v118.m128_u64[0] = v27.m128_u64[0];
  v28 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v24, v24, 85), direction.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v24, v24, 0), transform.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v24, v24, 170), *(__m128 *)bIn));
  *(__m128 *)bIn = v28;
  if ( !v17 )
  {
    v11 = 1;
    v29 = _mm_sub_ps(*p_m_quad, v13->m_left.m_quad);
    v30 = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(v29, v29, 201), m_quad),
            _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v29));
    v31 = _mm_shuffle_ps(v30, v30, 201);
    v32 = _mm_mul_ps(v31, v31);
    v33 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v32, v32, 85), _mm_shuffle_ps(v32, v32, 0)),
            _mm_shuffle_ps(v32, v32, 170));
    v34 = _mm_rsqrt_ps(v33);
    v35 = _mm_mul_ps(
            v31,
            _mm_andnot_ps(
              _mm_cmple_ps(v33, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v34, v33), v34)),
                _mm_mul_ps(*(__m128 *)_xmm, v34))));
    v36 = _mm_mul_ps(v19, v35);
    v14 = _mm_shuffle_ps(
            v35,
            _mm_unpackhi_ps(
              v35,
              _mm_sub_ps(
                (__m128)0i64,
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v36, v36, 85), _mm_shuffle_ps(v36, v36, 0)),
                  _mm_shuffle_ps(v36, v36, 170)))),
            196);
    p.m_quad = v14;
  }
  v37 = v7 + 1;
  if ( v7 + 1 >= NumEdges )
    return 1i64;
  v38 = &bIn[8];
  v39 = _mm_shuffle_ps(v19, v19, 255);
  if ( !v139 )
    v38 = &bIn[24];
  v118.m128_u64[1] = (unsigned __int64)v38;
  v133 = v39;
  while ( 1 )
  {
    v40 = hkaiEdgePath::getEdge(v137, v37);
    v41 = v40->m_left.m_quad;
    v42 = _mm_shuffle_ps(v40->m_left.m_quad, v40->m_left.m_quad, 85);
    v43 = _mm_shuffle_ps(v40->m_left.m_quad, v40->m_left.m_quad, 170);
    v123 = _mm_shuffle_ps(v41, v41, 0);
    v125 = v42;
    v131 = v43;
    v44 = _mm_mul_ps(v25, v42);
    v45 = v26;
    v46 = v40->m_right.m_quad;
    v47 = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(v28, v123), v27), v44), _mm_mul_ps(v45, v43));
    v127 = _mm_shuffle_ps(v46, v46, 0);
    v129 = _mm_shuffle_ps(v46, v46, 170);
    v135 = _mm_shuffle_ps(v46, v46, 85);
    v48 = _mm_add_ps(
            _mm_add_ps(_mm_add_ps(_mm_mul_ps(v28, v127), v27), _mm_mul_ps(v25, v135)),
            _mm_mul_ps(*(__m128 *)&bIn[16], v129));
    if ( v11 )
    {
      v49 = _mm_mul_ps(v47, v14);
      v50 = _mm_shuffle_ps(v49, _mm_unpackhi_ps(v49, v14), 196);
      v51 = _mm_add_ps(_mm_shuffle_ps(v50, v50, 78), v50);
      if ( (float)(_mm_shuffle_ps(v51, v51, 177).m128_f32[0] + v51.m128_f32[0]) < 0.0 )
      {
        v52 = _mm_mul_ps(v48, v14);
        v53 = _mm_shuffle_ps(v52, _mm_unpackhi_ps(v52, v14), 196);
        v54 = _mm_add_ps(_mm_shuffle_ps(v53, v53, 78), v53);
        if ( (float)(_mm_shuffle_ps(v54, v54, 177).m128_f32[0] + v54.m128_f32[0]) < 0.0 )
        {
          makeReflectionMatrix(&p, &m);
          v138 = !v138;
          v55 = _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v25, *(__m128 *)&bIn[40], 85), m.m_col1.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&bIn[40], *(__m128 *)&bIn[40], 0), m.m_col0.m_quad));
          *(__m128 *)&bIn[40] = _mm_mul_ps(
                                  _mm_shuffle_ps(*(__m128 *)&bIn[40], *(__m128 *)&bIn[40], 170),
                                  m.m_col2.m_quad);
          v56 = _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&bIn[16], *(__m128 *)&bIn[16], 85), m.m_col1.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&bIn[16], *(__m128 *)&bIn[16], 0), m.m_col0.m_quad));
          *(__m128 *)&bIn[16] = _mm_mul_ps(
                                  _mm_shuffle_ps(*(__m128 *)&bIn[16], *(__m128 *)&bIn[16], 170),
                                  m.m_col2.m_quad);
          *(__m128 *)&bIn[40] = _mm_add_ps(*(__m128 *)&bIn[40], v55);
          *(__m128 *)bIn = _mm_add_ps(
                             _mm_add_ps(
                               _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)bIn, *(__m128 *)bIn, 85), m.m_col1.m_quad),
                               _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)bIn, *(__m128 *)bIn, 0), m.m_col0.m_quad)),
                             _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)bIn, *(__m128 *)bIn, 170), m.m_col2.m_quad));
          *(__m128 *)&bIn[16] = _mm_add_ps(*(__m128 *)&bIn[16], v56);
          v118 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v118, v118, 0), m.m_col0.m_quad), m.m_col3.m_quad),
                     _mm_mul_ps(_mm_shuffle_ps(v118, v118, 85), m.m_col1.m_quad)),
                   _mm_mul_ps(_mm_shuffle_ps(v118, v118, 170), m.m_col2.m_quad));
          v47 = _mm_add_ps(
                  _mm_add_ps(_mm_add_ps(_mm_mul_ps(*(__m128 *)bIn, v123), v118), _mm_mul_ps(*(__m128 *)&bIn[40], v125)),
                  _mm_mul_ps(*(__m128 *)&bIn[16], v131));
          v48 = _mm_add_ps(
                  _mm_add_ps(_mm_add_ps(_mm_mul_ps(*(__m128 *)bIn, v127), v118), _mm_mul_ps(*(__m128 *)&bIn[40], v135)),
                  _mm_mul_ps(*(__m128 *)&bIn[16], v129));
        }
      }
      v11 = 0;
    }
    v57 = _mm_shuffle_ps(v41, v41, 255);
    v58 = _mm_shuffle_ps(v46, v46, 255);
    if ( v138 )
    {
      v59 = _mm_shuffle_ps(v47, _mm_unpackhi_ps(v47, _mm_sub_ps((__m128)0i64, v57)), 196);
      v60 = _mm_shuffle_ps(v48, _mm_unpackhi_ps(v48, _mm_sub_ps((__m128)0i64, v58)), 196);
    }
    else
    {
      v60 = _mm_shuffle_ps(v47, _mm_unpackhi_ps(v47, v57), 196);
      v59 = _mm_shuffle_ps(v48, _mm_unpackhi_ps(v48, v58), 196);
    }
    *(__m128 *)&bIn[8] = v59;
    *(__m128 *)&bIn[24] = v60;
    v61 = _mm_sub_ps(*(__m128 *)v118.m128_u64[1], v19);
    v62 = _mm_shuffle_ps(*(__m128 *)v118.m128_u64[1], *(__m128 *)v118.m128_u64[1], 255).m128_f32[0] + v133.m128_f32[0];
    v63 = _mm_mul_ps(v61, m_quad);
    v64 = _mm_sub_ps(
            v61,
            _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v63, v63, 85), _mm_shuffle_ps(v63, v63, 0)),
                _mm_shuffle_ps(v63, v63, 170)),
              m_quad));
    v65 = _mm_mul_ps(v64, v64);
    if ( (float)((float)(_mm_shuffle_ps(v65, v65, 85).m128_f32[0] + _mm_shuffle_ps(v65, v65, 0).m128_f32[0])
               + _mm_shuffle_ps(v65, v65, 170).m128_f32[0]) < (float)(v62 * v62) )
      return 5i64;
    v66 = v124;
    if ( (_mm_movemask_ps(_mm_cmplt_ps((__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(v60, v19), 1u), 1u), v124)) & 7) == 7 )
    {
      v67 = 0i64;
      v68 = 0i64;
    }
    else
    {
      hkaiEdgePathSteeringUtil::calcMutualTangentPoints(&aIn, (hkVector4f *)&bIn[24], &up, &v128, &bTangentPoint);
      v67 = _mm_sub_ps(bTangentPoint.m_quad, v128.m_quad);
      v69 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v67, v67, 201), m_quad),
              _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v67));
      v68 = _mm_shuffle_ps(v69, v69, 201);
    }
    if ( (_mm_movemask_ps(_mm_cmplt_ps((__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(v59, v19), 1u), 1u), v66)) & 7) == 7 )
    {
      v70 = 0i64;
      v71 = 0i64;
    }
    else
    {
      hkaiEdgePathSteeringUtil::calcMutualTangentPoints(&aIn, (hkVector4f *)&bIn[8], &up, &v132, &v130);
      v70 = _mm_sub_ps(v130.m_quad, v132.m_quad);
      v72 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v70, v70, 201), m_quad),
              _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v70));
      v71 = _mm_shuffle_ps(v72, v72, 201);
    }
    v73 = v40->m_flags.m_storage & 0x10;
    if ( v73 )
    {
      v74 = _mm_mul_ps(v70, v68);
      if ( (float)((float)(_mm_shuffle_ps(v74, v74, 85).m128_f32[0] + _mm_shuffle_ps(v74, v74, 0).m128_f32[0])
                 + _mm_shuffle_ps(v74, v74, 170).m128_f32[0]) > 0.0 )
      {
        v75 = v67;
        v76 = v60;
        v67 = v70;
        v70 = v75;
        v77 = v68;
        v60 = v59;
        v68 = v71;
        v59 = v76;
        v71 = v77;
      }
    }
    v78 = _mm_mul_ps(v68, v117);
    v79 = _mm_mul_ps(v68, *(__m128 *)&bIn[32]);
    v80 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64), v71);
    v81 = _mm_mul_ps(v80, *(__m128 *)&bIn[32]);
    v82 = _mm_mul_ps(v80, v117);
    v83 = _mm_shuffle_ps(v79, v81, 68);
    v84 = _mm_shuffle_ps(v78, v82, 68);
    v85 = _mm_shuffle_ps(_mm_shuffle_ps(v78, v82, 238), _mm_shuffle_ps(v79, v81, 238), 136);
    v86 = _mm_sub_ps(v67, v70);
    v87 = _mm_mul_ps(v86, v86);
    v88 = _mm_cmple_ps(
            (__m128)0i64,
            _mm_add_ps(v85, _mm_add_ps(_mm_shuffle_ps(v84, v83, 221), _mm_shuffle_ps(v84, v83, 136))));
    v90 = 0;
    if ( (float)((float)(_mm_shuffle_ps(v87, v87, 85).m128_f32[0] + _mm_shuffle_ps(v87, v87, 0).m128_f32[0])
               + _mm_shuffle_ps(v87, v87, 170).m128_f32[0]) > v134.m128_f32[0] )
    {
      v89 = _mm_mul_ps(v70, v68);
      if ( (float)((float)(_mm_shuffle_ps(v89, v89, 85).m128_f32[0] + _mm_shuffle_ps(v89, v89, 0).m128_f32[0])
                 + _mm_shuffle_ps(v89, v89, 170).m128_f32[0]) > v134.m128_f32[0] )
        v90 = 1;
    }
    v91 = (v90 ? 0x10 : 0) | _mm_movemask_ps(v88);
    if ( !v139 )
      break;
    if ( (_mm_movemask_ps(_mm_cmpeq_ps(v117, (__m128)0i64)) & 7) != 7 )
      goto LABEL_47;
    if ( _mm_movemask_ps(_mm_cmpeq_ps(v67, (__m128)0i64)) != 15 )
    {
      switch ( v91 & 0x1C )
      {
        case 0:
          v117 = v67;
          v7 = v37;
          goto LABEL_52;
        case 4:
        case 0xC:
        case 0x10:
        case 0x14:
          goto $LN10_137;
        case 8:
          v117 = v67;
          goto LABEL_50;
        case 0x18:
        case 0x1C:
          goto $LN4_168;
        default:
          goto LABEL_52;
      }
    }
    if ( (v91 & 8) != 0 )
    {
$LN1241:
      v10 = v37;
      *(__m128 *)&bIn[32] = v70;
    }
LABEL_52:
    if ( _mm_movemask_ps(_mm_cmpeq_ps(v40->m_right.m_quad, v40->m_left.m_quad)) == 15 )
    {
$LN1224:
      v116 = v140;
      *nextEdgeIndex = v37;
      *v116 = 1;
      return 0i64;
    }
    v92 = *(__m128 *)&bIn[40];
    v93 = v40->m_followingTransform.m_col2.m_quad;
    v94 = _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v93, v93, 85), *(__m128 *)&bIn[40]),
            _mm_mul_ps(_mm_shuffle_ps(v93, v93, 0), *(__m128 *)bIn));
    v95 = v40->m_followingTransform.m_col0.m_quad;
    v96 = _mm_shuffle_ps(v95, v95, 85);
    v97 = _mm_mul_ps(_mm_shuffle_ps(v95, v95, 0), *(__m128 *)bIn);
    v25 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(
                _mm_shuffle_ps(v40->m_followingTransform.m_col1.m_quad, v40->m_followingTransform.m_col1.m_quad, 85),
                *(__m128 *)&bIn[40]),
              _mm_mul_ps(
                _mm_shuffle_ps(v40->m_followingTransform.m_col1.m_quad, v40->m_followingTransform.m_col1.m_quad, 0),
                *(__m128 *)bIn)),
            _mm_mul_ps(
              _mm_shuffle_ps(v40->m_followingTransform.m_col1.m_quad, v40->m_followingTransform.m_col1.m_quad, 170),
              *(__m128 *)&bIn[16]));
    v27 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                v118,
                _mm_mul_ps(
                  _mm_shuffle_ps(v40->m_followingTransform.m_col3.m_quad, v40->m_followingTransform.m_col3.m_quad, 0),
                  *(__m128 *)bIn)),
              _mm_mul_ps(
                _mm_shuffle_ps(v40->m_followingTransform.m_col3.m_quad, v40->m_followingTransform.m_col3.m_quad, 85),
                *(__m128 *)&bIn[40])),
            _mm_mul_ps(
              _mm_shuffle_ps(v40->m_followingTransform.m_col3.m_quad, v40->m_followingTransform.m_col3.m_quad, 170),
              *(__m128 *)&bIn[16]));
    *(__m128 *)&bIn[40] = v25;
    v98 = _mm_mul_ps(_mm_shuffle_ps(v95, v95, 170), *(__m128 *)&bIn[16]);
    v99 = _mm_mul_ps(v96, v92);
    v118 = v27;
    v26 = _mm_add_ps(v94, _mm_mul_ps(_mm_shuffle_ps(v93, v93, 170), *(__m128 *)&bIn[16]));
    *(__m128 *)&bIn[16] = v26;
    *(__m128 *)bIn = _mm_add_ps(_mm_add_ps(v99, v97), v98);
    if ( v73 )
    {
      v100 = _mm_sub_ps(v59, v60);
      v11 = 1;
      v101 = _mm_sub_ps(
               _mm_mul_ps(_mm_shuffle_ps(v100, v100, 201), m_quad),
               _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v100));
      v102 = _mm_shuffle_ps(v101, v101, 201);
      v103 = _mm_mul_ps(v102, v102);
      v104 = _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v103, v103, 85), _mm_shuffle_ps(v103, v103, 0)),
               _mm_shuffle_ps(v103, v103, 170));
      v105 = _mm_rsqrt_ps(v104);
      v106 = _mm_mul_ps(
               v102,
               _mm_andnot_ps(
                 _mm_cmple_ps(v104, (__m128)0i64),
                 _mm_mul_ps(
                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v105, v104), v105)),
                   _mm_mul_ps(*(__m128 *)_xmm, v105))));
      v107 = _mm_mul_ps(v60, v106);
      v14 = _mm_shuffle_ps(
              v106,
              _mm_unpackhi_ps(
                v106,
                _mm_sub_ps(
                  (__m128)0i64,
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v107, v107, 85), _mm_shuffle_ps(v107, v107, 0)),
                    _mm_shuffle_ps(v107, v107, 170)))),
              196);
      p.m_quad = v14;
    }
    if ( ++v37 >= NumEdges )
      return 1i64;
    v28 = *(__m128 *)bIn;
  }
  if ( (_mm_movemask_ps(_mm_cmpeq_ps(*(__m128 *)&bIn[32], (__m128)0i64)) & 7) != 7 )
  {
LABEL_47:
    switch ( v91 )
    {
      case 1:
      case 3:
        v117 = v67;
        v7 = v37;
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
        v109 = v140;
        *nextEdgeIndex = v10;
        *v109 = 0;
        result = 0i64;
        break;
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
        v110 = v140;
        v111 = _mm_mul_ps(v67, *(__m128 *)&bIn[32]);
        if ( (float)((float)(_mm_shuffle_ps(v111, v111, 85).m128_f32[0] + _mm_shuffle_ps(v111, v111, 0).m128_f32[0])
                   + _mm_shuffle_ps(v111, v111, 170).m128_f32[0]) <= 0.0 )
        {
          *nextEdgeIndex = v7;
          *v110 = 1;
        }
        else
        {
          *nextEdgeIndex = v10;
          *v110 = 0;
        }
        result = 0i64;
        break;
      case 29:
        v112 = v140;
        *nextEdgeIndex = v37;
        *v112 = 0;
        result = 0i64;
        break;
      case 31:
        goto $LN1224;
      default:
        goto LABEL_52;
    }
    return result;
  }
  if ( _mm_movemask_ps(_mm_cmpeq_ps(v70, (__m128)0i64)) == 15 )
  {
    if ( (v91 & 1) != 0 )
    {
      v117 = v67;
      v7 = v37;
    }
    goto LABEL_52;
  }
  switch ( v91 & 0x13 )
  {
    case 0:
      goto $LN1241;
    case 1:
$LN12_121:
      v117 = v67;
LABEL_50:
      v7 = v37;
      goto $LN1241;
    case 2:
    case 3:
    case 0x10:
    case 0x12:
$LN11_115:
      v108 = v140;
      *nextEdgeIndex = v7;
      *v108 = 1;
      result = 0i64;
      break;
    case 0x11:
    case 0x13:
$LN4_168:
      v113 = v140;
      v114 = _mm_mul_ps(v67, v67);
      v115 = _mm_mul_ps(v70, v70);
      *nextEdgeIndex = v37;
      *v113 = (float)((float)(_mm_shuffle_ps(v114, v114, 85).m128_f32[0] + _mm_shuffle_ps(v114, v114, 0).m128_f32[0])
                    + _mm_shuffle_ps(v114, v114, 170).m128_f32[0]) < (float)((float)(_mm_shuffle_ps(v115, v115, 85).m128_f32[0]
                                                                                   + _mm_shuffle_ps(v115, v115, 0).m128_f32[0])
                                                                           + _mm_shuffle_ps(v115, v115, 170).m128_f32[0]);
      result = 0i64;
      break;
    default:
      goto LABEL_52;
  }
  return result;
}

// File Line: 965
// RVA: 0xC132A0
float __fastcall hkaiEdgePathSteeringUtil::calcMultilevelDistance(
        hkVector4f *a,
        hkVector4f *b,
        hkVector4f *up,
        hkSimdFloat32 *maxIgnoredHeight)
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
  LODWORD(result) = _mm_andnot_ps(
                      _mm_cmple_ps(v8, (__m128)0i64),
                      _mm_mul_ps(
                        _mm_mul_ps(
                          _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v9, v8), v9)),
                          _mm_mul_ps(*(__m128 *)_xmm, v9)),
                        v8)).m128_u32[0];
  return result;
}

// File Line: 990
// RVA: 0xC13340
float __fastcall hkaiEdgePathSteeringUtil::approximateDistanceToGoal(
        hkVector4f *position,
        hkVector4f *corner,
        hkVector4f *goal,
        hkVector4f *up,
        hkSimdFloat32 *maxIgnoredHeight)
{
  float v8; // xmm6_4

  v8 = hkaiEdgePathSteeringUtil::calcMultilevelDistance(position, corner, up, maxIgnoredHeight);
  return v8 + hkaiEdgePathSteeringUtil::calcMultilevelDistance(corner, goal, up, maxIgnoredHeight);
}

// File Line: 1005
// RVA: 0xC133B0
float __fastcall hkaiEdgePathSteeringUtil::calcOptimalSpeed(
        float distToGoal,
        float currentSpeed,
        float desiredMaxSpeed,
        float desiredGoalSpeed,
        float desiredMaxAcceleration,
        float desiredMaxDeceleration,
        float absoluteMaxAcceleration,
        float absoluteMaxDeceleration,
        float timeStep,
        bool *approachingGoal)
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
    return desiredMaxSpeed;
  }
  else
  {
    *approachingGoal = 1;
  }
  return result;
}

// File Line: 1046
// RVA: 0xC13120
__int64 __fastcall hkaiEdgePathSteeringUtil::getFollowingCorner(
        hkaiEdgePath *edgePath,
        int startEdge,
        bool startIsLeft,
        hkaiStreamingCollection *streamingCollection,
        int *followingEdge,
        bool *followingIsLeft)
{
  int v10; // eax

  if ( (unsigned int)hkaiEdgePath::hasFollowingCornerInfo(edgePath, startEdge, startIsLeft) )
    return hkaiEdgePath::getFollowingCornerInfo(edgePath, startEdge, startIsLeft, followingEdge, followingIsLeft);
  v10 = hkaiEdgePathSteeringUtil::calcForwardVector_corner(
          edgePath,
          startEdge,
          startIsLeft,
          followingEdge,
          followingIsLeft);
  if ( (unsigned int)(v10 - 4) <= 1 || v10 == 1 )
  {
    hkaiEdgePath::setFollowingCornerInfoInvalid(edgePath, startEdge, startIsLeft);
    return 0i64;
  }
  else
  {
    hkaiEdgePath::setFollowingCornerInfoValid(edgePath, startEdge, startIsLeft, *followingEdge, *followingIsLeft);
    return 1i64;
  }
}

// File Line: 1088
// RVA: 0xC12F60
__int64 __fastcall hkaiEdgePathSteeringUtil::getRelativeTransform(
        int positionSectionIndex,
        hkaiEdgePath::Edge *targetEdge,
        hkaiStreamingCollection *streamingCollection,
        const __m128i *relativeTransformOut)
{
  unsigned int m_key; // eax
  hkaiNavMeshInstance *m_instancePtr; // rdx
  __int64 result; // rax
  hkVector4f v8; // xmm0
  __m128i si128; // xmm1
  __m128i v10; // xmm0
  hkVector4f v11; // xmm1
  hkaiStreamingCollection::InstanceInfo *m_data; // r8
  hkaiNavMeshInstance *v13; // r10
  __int64 v14; // rax
  hkaiNavMeshInstance *v15; // r8
  __m128 m_quad; // xmm2
  __m128i m_col1; // xmm1
  hkVector4f v18; // xmm0
  __m128i v19; // xmm0
  hkTransformf v20; // [rsp+20h] [rbp-48h] BYREF

  if ( positionSectionIndex == -1 )
  {
    m_key = targetEdge->m_edge.m_faceKey.m_key;
    if ( m_key != -1 )
    {
      m_instancePtr = streamingCollection->m_instances.m_data[m_key >> 22].m_instancePtr;
      result = 0i64;
      *relativeTransformOut = (const __m128i)m_instancePtr->m_referenceFrame.m_transform.m_rotation.m_col0;
      relativeTransformOut[1] = (const __m128i)m_instancePtr->m_referenceFrame.m_transform.m_rotation.m_col1;
      relativeTransformOut[2] = (const __m128i)m_instancePtr->m_referenceFrame.m_transform.m_rotation.m_col2;
      v8.m_quad = (__m128)_mm_srli_si128(_mm_slli_si128(_mm_load_si128(relativeTransformOut), 4), 4);
      relativeTransformOut[3] = (const __m128i)m_instancePtr->m_referenceFrame.m_transform.m_translation;
      si128 = _mm_load_si128(relativeTransformOut + 1);
      *(hkVector4f *)relativeTransformOut = (hkVector4f)v8.m_quad;
      v10 = _mm_load_si128(relativeTransformOut + 2);
      relativeTransformOut[1] = _mm_srli_si128(_mm_slli_si128(si128, 4), 4);
      v11.m_quad = (__m128)relativeTransformOut[3];
      relativeTransformOut[2] = _mm_srli_si128(_mm_slli_si128(v10, 4), 4);
      relativeTransformOut[3] = (const __m128i)_mm_shuffle_ps(
                                                 v11.m_quad,
                                                 _mm_unpackhi_ps(v11.m_quad, query.m_quad),
                                                 196);
      return result;
    }
LABEL_7:
    result = 0i64;
    *(hkVector4f *)relativeTransformOut = (hkVector4f)transform.m_quad;
    relativeTransformOut[1] = (const __m128i)direction.m_quad;
    relativeTransformOut[2] = (const __m128i)stru_141A71280.m_quad;
    relativeTransformOut[3] = (const __m128i)qi.m_vec.m_quad;
    return result;
  }
  m_data = streamingCollection->m_instances.m_data;
  v13 = m_data[positionSectionIndex].m_instancePtr;
  if ( !v13 )
    return 2i64;
  v14 = targetEdge->m_edge.m_faceKey.m_key >> 22;
  if ( positionSectionIndex == (_DWORD)v14 )
    goto LABEL_7;
  v15 = m_data[v14].m_instancePtr;
  if ( !v15 )
    return 3i64;
  hkTransformf::setMulInverseMul(&v20, &v13->m_referenceFrame.m_transform, &v15->m_referenceFrame.m_transform);
  result = 0i64;
  m_quad = v20.m_translation.m_quad;
  m_col1 = (__m128i)v20.m_rotation.m_col1;
  *relativeTransformOut = (const __m128i)v20.m_rotation.m_col0;
  v18.m_quad = (__m128)v20.m_rotation.m_col2;
  relativeTransformOut[1] = m_col1;
  relativeTransformOut[2] = (const __m128i)v18.m_quad;
  v19 = _mm_load_si128(relativeTransformOut);
  relativeTransformOut[3] = (const __m128i)m_quad;
  *relativeTransformOut = _mm_srli_si128(_mm_slli_si128(v19, 4), 4);
  relativeTransformOut[2] = _mm_srli_si128(_mm_slli_si128(_mm_load_si128(relativeTransformOut + 2), 4), 4);
  relativeTransformOut[1] = _mm_srli_si128(_mm_slli_si128(m_col1, 4), 4);
  relativeTransformOut[3] = (const __m128i)_mm_shuffle_ps(m_quad, _mm_unpackhi_ps(m_quad, query.m_quad), 196);
  return result;
}

// File Line: 1143
// RVA: 0xC131F0
__int64 __fastcall hkaiEdgePathSteeringUtil::resolveEdgeToKey(
        hkaiEdgePath::Edge *edge,
        hkaiGeneralAccessor *accessor,
        hkaiNavMeshCutter *cutter,
        unsigned int *faceKeyOut)
{
  unsigned int v7; // eax
  unsigned int v8; // ebx
  hkVector4f edgeA; // [rsp+20h] [rbp-28h] BYREF
  hkVector4f edgeB; // [rsp+30h] [rbp-18h] BYREF

  v7 = hkaiNavMeshCutter::resolvePersistentEdgeKey(cutter, accessor, &edge->m_edge, faceKeyOut);
  v8 = v7;
  if ( v7 != -1 )
  {
    hkaiGeneralAccessor::setSection(accessor, v7 >> 22);
    hkaiNavMeshInstance::getEdgePoints(accessor->m_accessor, v8 & 0x3FFFFF, &edgeA, &edgeB);
    if ( (_mm_movemask_ps(_mm_cmpeq_ps(edge->m_right.m_quad, edgeA.m_quad)) & 7) == 7
      && (_mm_movemask_ps(_mm_cmpeq_ps(edge->m_left.m_quad, edgeB.m_quad)) & 7) == 7 )
    {
      return v8;
    }
    *faceKeyOut = -1;
  }
  return 0xFFFFFFFFi64;
}

