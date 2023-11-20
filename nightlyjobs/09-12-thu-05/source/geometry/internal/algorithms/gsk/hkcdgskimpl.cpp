// File Line: 36
// RVA: 0x130CDA0
signed __int64 __fastcall hkcdGskBase::processEdgeTriangle(hkcdGskBase *this, hkVector4f *vertexA, hkVector4f *vertexB, unsigned int comingFromEdgeEdge, hkVector4f *supportOut)
{
  __m128 v5; // xmm10
  __m128 v6; // xmm6
  hkVector4f v7; // xmm9
  __m128 v8; // xmm7
  __m128 v9; // xmm14
  __m128 v10; // xmm1
  __m128 v11; // xmm13
  __m128 v12; // xmm2
  __m128 v13; // xmm2
  __m128 v14; // xmm1
  __m128 v15; // xmm3
  __m128 v16; // xmm1
  __m128 v17; // xmm2
  __m128 v18; // xmm1
  __m128 v19; // xmm4
  __m128 v20; // xmm1
  __m128 v21; // xmm0
  __m128 v22; // xmm2
  __m128 v23; // xmm1
  __m128 v24; // xmm2
  __m128 v25; // xmm0
  __m128 v26; // xmm3
  __m128 v27; // xmm9
  __m128 v28; // xmm10
  __m128 v29; // xmm4
  __m128 v30; // xmm1
  __m128 v31; // xmm4
  __m128 v32; // xmm3
  __m128 v33; // xmm5
  __m128 v34; // xmm2
  __m128 v35; // xmm1
  __m128 v36; // xmm5
  __m128 v37; // xmm9
  __m128 v38; // xmm2
  signed __int64 result; // rax
  __m128 v40; // xmm3
  __m128 v41; // xmm2
  __m128 v42; // xmm1
  __m128 v43; // xmm4
  __m128 v44; // xmm5
  hkVector4f v45; // xmm12
  __m128 v46; // xmm8
  __m128 v47; // xmm6
  __m128 v48; // xmm7
  __m128 v49; // xmm1
  __m128 v50; // xmm11
  __m128 v51; // xmm2
  __m128 v52; // xmm3
  hkVector4f v53; // xmm11
  __m128 v54; // xmm8
  __m128 v55; // xmm8
  __m128 v56; // xmm6
  __m128 v57; // xmm6
  __m128 v58; // xmm1
  __m128 v59; // xmm7
  __m128 v60; // xmm7
  __m128 v61; // xmm2
  hkVector4f v62; // xmm8
  int v63; // er9
  __m128 v64; // xmm2
  __m128 v65; // xmm1
  __m128 v66; // xmm7
  __m128 v67; // xmm15
  __m128 v68; // xmm1
  __m128 v69; // xmm12
  __m128 v70; // ST00_16
  __m128 v71; // xmm10
  __m128 v72; // xmm1
  __m128 v73; // xmm9
  __m128 v74; // xmm1
  __m128 v75; // xmm8
  __m128 v76; // xmm2
  __m128 v77; // xmm1
  __m128 v78; // xmm6
  __m128 v79; // xmm4
  __m128 v80; // xmm1
  __m128 v81; // xmm3
  __m128 v82; // xmm1
  __m128 v83; // xmm5
  __m128 v84; // xmm1
  __m128 v85; // xmm7
  __m128 v86; // xmm6
  __m128 v87; // xmm0
  __m128 v88; // xmm2
  __m128 v89; // xmm3
  __m128 v90; // xmm1
  __m128 v91; // xmm3
  __m128 v92; // xmm10
  __m128 v93; // xmm1
  __m128 v94; // xmm2
  __m128 v95; // xmm1
  __m128 v96; // xmm2
  __m128 v97; // xmm10
  __m128 v98; // xmm9
  __m128 v99; // xmm1
  __m128 v100; // xmm15
  __m128 v101; // xmm1
  __m128 v102; // xmm8
  __m128 v103; // xmm7
  __m128 v104; // xmm1
  __m128 v105; // xmm6
  __m128 v106; // xmm2
  __m128 v107; // xmm4
  __m128 v108; // xmm1
  __m128 v109; // xmm3
  __m128 v110; // xmm1
  __m128 v111; // xmm5
  __m128 v112; // xmm1
  __m128 v113; // xmm0
  __m128 v114; // xmm2
  __m128 v115; // xmm12
  __m128 v116; // xmm6
  __m128 v117; // xmm1
  __m128 v118; // xmm3
  __m128 v119; // xmm1
  __m128 v120; // xmm2
  __m128 v121; // xmm9
  __m128 v122; // xmm1
  __m128 v123; // xmm3
  __m128 v124; // xmm4
  __m128 v125; // xmm4
  __m128 v126; // xmm1
  __m128 v127; // xmm0
  __m128 v128; // xmm1
  __m128 v129; // xmm0
  __m128 v130; // xmm9
  hkVector4f v131; // xmm12
  hkVector4f v132; // xmm10
  __m128 v133; // xmm11
  __m128 v134; // xmm1
  __m128 v135; // xmm2
  __m128 v136; // xmm3
  __m128 v137; // xmm4
  __m128 v138; // xmm1
  __m128 v139; // xmm0
  __m128 v140; // xmm2
  __m128 v141; // xmm1
  __m128 v142; // xmm3
  __m128 v143; // xmm5
  __m128 v144; // xmm0
  __m128 v145; // xmm7
  __m128 v146; // xmm4
  __m128 v147; // xmm5
  __m128 v148; // xmm0
  __m128 v149; // xmm6
  __m128 v150; // xmm6
  __m128 v151; // xmm1
  __m128 v152; // xmm3
  __m128 v153; // xmm0
  __m128 v154; // xmm2
  __m128 v155; // xmm7
  __m128 v156; // xmm1
  __m128 v157; // xmm3
  __m128 v158; // xmm1
  __m128 v159; // xmm7
  __m128 v160; // xmm2
  __m128 v161; // xmm2
  __m128 v162; // xmm3
  __m128 v163; // xmm5
  __m128 v164; // xmm8
  __m128 v165; // xmm4
  __m128 v166; // xmm7
  __m128 v167; // xmm1
  __m128 v168; // xmm9
  __m128 v169; // xmm2
  __m128 v170; // xmm6
  __m128 v171; // xmm6
  __m128 v172; // xmm9
  __m128 v173; // xmm7
  __m128 v174; // xmm9
  __m128 v175; // xmm7
  __m128 v176; // xmm8
  __m128 v177; // xmm1
  __m128 v178; // xmm8
  __m128 v179; // xmm2
  hkVector4f v180; // xmm9
  int v181; // eax
  float v182; // xmm1_4
  float v183; // xmm10_4
  float v184; // xmm1_4
  float v185; // xmm10_4
  float v186; // xmm1_4
  float v187; // xmm10_4
  __m128 v188; // [rsp+0h] [rbp-E8h]
  __m128 v189; // [rsp+10h] [rbp-D8h]
  __m128 v190; // [rsp+20h] [rbp-C8h]

  if ( !comingFromEdgeEdge )
  {
    v130 = vertexB->m_quad;
    v131.m_quad = (__m128)vertexA[1];
    v132.m_quad = (__m128)this->m_checkTriangleDots;
    v133 = _mm_sub_ps(vertexA[1].m_quad, vertexB->m_quad);
    v134 = _mm_mul_ps(_mm_sub_ps(vertexA->m_quad, vertexB->m_quad), supportOut->m_quad);
    v135 = _mm_mul_ps(supportOut->m_quad, v133);
    v136 = _mm_add_ps(
             _mm_add_ps(_mm_shuffle_ps(v134, v134, 85), _mm_shuffle_ps(v134, v134, 0)),
             _mm_shuffle_ps(v134, v134, 170));
    v137 = _mm_add_ps(
             _mm_add_ps(_mm_shuffle_ps(v135, v135, 85), _mm_shuffle_ps(v135, v135, 0)),
             _mm_shuffle_ps(v135, v135, 170));
    if ( (float)(v137.m128_f32[0] * v136.m128_f32[0]) < 0.0 )
    {
      v138 = _mm_sub_ps(v136, v137);
      v139 = _mm_rcp_ps(v138);
      v140 = _mm_sub_ps((__m128)_xmm, _mm_mul_ps(v138, v139));
      v141 = _mm_sub_ps(vertexB[1].m_quad, v130);
      v142 = _mm_add_ps(
               _mm_mul_ps(_mm_sub_ps(v131.m_quad, vertexA->m_quad), _mm_mul_ps(_mm_mul_ps(v140, v139), v136)),
               vertexA->m_quad);
      v143 = vertexB[2].m_quad;
      v144 = v143;
      v145 = _mm_sub_ps(vertexB[1].m_quad, v142);
      v146 = _mm_sub_ps(v130, v142);
      v147 = _mm_sub_ps(v143, v142);
      v148 = _mm_sub_ps(v144, v130);
      v149 = _mm_sub_ps(
               _mm_mul_ps(_mm_shuffle_ps(v148, v148, 201), v141),
               _mm_mul_ps(_mm_shuffle_ps(v141, v141, 201), v148));
      v150 = _mm_shuffle_ps(v149, v149, 201);
      v151 = _mm_shuffle_ps(v150, v150, 210);
      v152 = _mm_mul_ps(
               _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v147, v147, 201), v151),
                 _mm_mul_ps(_mm_shuffle_ps(v147, v147, 210), v150)),
               v145);
      v153 = _mm_shuffle_ps(v145, v145, 210);
      v154 = _mm_mul_ps(
               _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v146, v146, 201), v151),
                 _mm_mul_ps(_mm_shuffle_ps(v146, v146, 210), v150)),
               v147);
      v155 = _mm_mul_ps(_mm_shuffle_ps(v145, v145, 201), v151);
      v156 = v152;
      v157 = _mm_unpackhi_ps(v152, v154);
      v158 = _mm_unpacklo_ps(v156, v154);
      v159 = _mm_mul_ps(_mm_sub_ps(v155, _mm_mul_ps(v153, v150)), v146);
      v160 = _mm_movelh_ps(v158, v159);
      if ( (_mm_movemask_ps(
              _mm_cmpltps(
                (__m128)0i64,
                _mm_add_ps(
                  _mm_shuffle_ps(v157, v159, 228),
                  _mm_add_ps(v160, _mm_shuffle_ps(_mm_movehl_ps(v160, v158), v159, 212))))) & 7) == 7 )
        return 1i64;
    }
    v161 = vertexB[1].m_quad;
    v162 = vertexB[2].m_quad;
    v163 = _mm_sub_ps(v130, v162);
    v164 = _mm_sub_ps(vertexB[1].m_quad, v130);
    v165 = _mm_sub_ps(vertexB[2].m_quad, v161);
    v166 = _mm_shuffle_ps(v163, v163, 201);
    v167 = _mm_sub_ps(v131.m_quad, v161);
    v168 = _mm_shuffle_ps(v165, v165, 201);
    v169 = _mm_sub_ps(v131.m_quad, v162);
    v170 = _mm_sub_ps(_mm_mul_ps(v166, v165), _mm_mul_ps(v168, v163));
    v171 = _mm_shuffle_ps(v170, v170, 201);
    v172 = _mm_sub_ps(_mm_mul_ps(v168, v167), _mm_mul_ps(_mm_shuffle_ps(v167, v167, 201), v165));
    v173 = _mm_sub_ps(_mm_mul_ps(v166, v169), _mm_mul_ps(_mm_shuffle_ps(v169, v169, 201), v163));
    v174 = _mm_mul_ps(_mm_shuffle_ps(v172, v172, 201), v171);
    v175 = _mm_mul_ps(_mm_shuffle_ps(v173, v173, 201), v171);
    v176 = _mm_sub_ps(
             _mm_mul_ps(_mm_shuffle_ps(v164, v164, 201), v133),
             _mm_mul_ps(_mm_shuffle_ps(v133, v133, 201), v164));
    v177 = _mm_unpacklo_ps(v174, v175);
    v178 = _mm_mul_ps(_mm_shuffle_ps(v176, v176, 201), v171);
    v179 = _mm_movelh_ps(v177, v178);
    v180.m_quad = _mm_add_ps(
                    _mm_shuffle_ps(_mm_unpackhi_ps(v174, v175), v178, 228),
                    _mm_add_ps(v179, _mm_shuffle_ps(_mm_movehl_ps(v179, v177), v178, 212)));
    this->m_checkTriangleDots = (hkVector4f)v180.m_quad;
    v181 = _mm_movemask_ps(_mm_cmpltps(v180.m_quad, (__m128)0i64)) & 7;
    if ( v181 == 7 )
    {
      *vertexA = (hkVector4f)v131.m_quad;
      return 0i64;
    }
    if ( v181 == 6 )
      goto LABEL_26;
    if ( v181 != 5 )
    {
      switch ( v181 )
      {
        case 3:
          return 2i64;
        case 1:
          LODWORD(v182) = (unsigned __int128)_mm_shuffle_ps(v132.m_quad, v132.m_quad, 85);
          LODWORD(v183) = (unsigned __int128)_mm_shuffle_ps(v132.m_quad, v132.m_quad, 170);
          if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v180.m_quad, v180.m_quad, 85)) - v182) * v183) <= (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v180.m_quad, v180.m_quad, 170)) - v183) * v182) )
          {
            result = 2i64;
            vertexB[1] = (hkVector4f)vertexB[2].m_quad;
            return result;
          }
          return 2i64;
        case 2:
          LODWORD(v184) = (unsigned __int128)_mm_shuffle_ps(v132.m_quad, v132.m_quad, 170);
          LODWORD(v185) = (unsigned __int128)_mm_shuffle_ps(v132.m_quad, v132.m_quad, 0);
          if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v180.m_quad, v180.m_quad, 170)) - v184) * v185) > (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v180.m_quad, v180.m_quad, 0)) - v185) * v184) )
          {
LABEL_26:
            result = 2i64;
            *vertexB = (hkVector4f)vertexB[2].m_quad;
            return result;
          }
          return 2i64;
      }
      if ( v181 != 4 )
        goto LABEL_26;
      LODWORD(v186) = (unsigned __int128)_mm_shuffle_ps(v132.m_quad, v132.m_quad, 0);
      LODWORD(v187) = (unsigned __int128)_mm_shuffle_ps(v132.m_quad, v132.m_quad, 85);
      if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v180.m_quad, v180.m_quad, 0)) - v186) * v187) <= (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v180.m_quad, v180.m_quad, 85)) - v187) * v186) )
        goto LABEL_26;
    }
    vertexB[1] = (hkVector4f)vertexB[2].m_quad;
    return 2i64;
  }
  v5 = vertexB->m_quad;
  v6 = vertexA->m_quad;
  v7.m_quad = (__m128)vertexB[1];
  v8 = vertexA[1].m_quad;
  v9 = vertexB[2].m_quad;
  v190 = vertexA->m_quad;
  v10 = _mm_sub_ps(vertexB->m_quad, v9);
  v11 = _mm_sub_ps(v7.m_quad, v9);
  v189 = v10;
  v188 = v8;
  v12 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), v11), _mm_mul_ps(_mm_shuffle_ps(v11, v11, 201), v10));
  v13 = _mm_shuffle_ps(v12, v12, 201);
  v14 = _mm_mul_ps(_mm_sub_ps(vertexA->m_quad, vertexB->m_quad), v13);
  v15 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)), _mm_shuffle_ps(v14, v14, 170));
  v16 = _mm_mul_ps(_mm_sub_ps(v8, vertexB->m_quad), v13);
  v17 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)), _mm_shuffle_ps(v16, v16, 170));
  v18 = _mm_mul_ps(v15, v15);
  v19 = _mm_mul_ps(v17, v17);
  if ( _mm_movemask_ps(_mm_mul_ps(v17, v15)) )
  {
    v20 = _mm_sub_ps(v15, v17);
    v21 = _mm_rcp_ps(v20);
    v22 = _mm_sub_ps((__m128)_xmm, _mm_mul_ps(v20, v21));
    v23 = _mm_sub_ps(v7.m_quad, v5);
    v24 = _mm_mul_ps(v22, v21);
    v25 = _mm_sub_ps(v9, v5);
    v26 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v8, v6), _mm_mul_ps(v24, v15)), v6);
    v27 = _mm_sub_ps(v7.m_quad, v26);
    v28 = _mm_sub_ps(v5, v26);
    v29 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v25, v25, 201), v23), _mm_mul_ps(_mm_shuffle_ps(v23, v23, 201), v25));
    v30 = _mm_sub_ps(v9, v26);
    v31 = _mm_shuffle_ps(v29, v29, 201);
    v32 = _mm_shuffle_ps(v31, v31, 210);
    v33 = _mm_mul_ps(
            _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v30, v30, 201), v32), _mm_mul_ps(_mm_shuffle_ps(v30, v30, 210), v31)),
            v27);
    v34 = _mm_mul_ps(
            _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v28, v28, 201), v32), _mm_mul_ps(_mm_shuffle_ps(v28, v28, 210), v31)),
            v30);
    v35 = _mm_unpacklo_ps(v33, v34);
    v36 = _mm_unpackhi_ps(v33, v34);
    v37 = _mm_mul_ps(
            _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v27, v27, 201), v32), _mm_mul_ps(_mm_shuffle_ps(v27, v27, 210), v31)),
            v28);
    v38 = _mm_movelh_ps(v35, v37);
    if ( (_mm_movemask_ps(
            _mm_cmpltps(
              (__m128)0i64,
              _mm_add_ps(
                _mm_shuffle_ps(v36, v37, 228),
                _mm_add_ps(v38, _mm_shuffle_ps(_mm_movehl_ps(v38, v35), v37, 212))))) & 7) == 7 )
      return 1i64;
  }
  else
  {
    v40 = vertexB[2].m_quad;
    v41 = vertexB[1].m_quad;
    v42 = _mm_cmpltps(v18, v19);
    v43 = _mm_sub_ps(vertexB[2].m_quad, v41);
    v44 = _mm_sub_ps(v5, v40);
    v45.m_quad = _mm_or_ps(_mm_and_ps(v42, v6), _mm_andnot_ps(v42, v8));
    v46 = _mm_shuffle_ps(v43, v43, 201);
    v47 = _mm_shuffle_ps(v44, v44, 201);
    v48 = _mm_sub_ps(vertexB[1].m_quad, v5);
    v49 = _mm_sub_ps(v45.m_quad, v41);
    v50 = _mm_sub_ps(_mm_mul_ps(v47, v43), _mm_mul_ps(v46, v44));
    v51 = _mm_sub_ps(v45.m_quad, v40);
    v52 = _mm_sub_ps(v45.m_quad, v5);
    v53.m_quad = _mm_shuffle_ps(v50, v50, 201);
    v54 = _mm_sub_ps(_mm_mul_ps(v46, v49), _mm_mul_ps(_mm_shuffle_ps(v49, v49, 201), v43));
    v55 = _mm_mul_ps(_mm_shuffle_ps(v54, v54, 201), v53.m_quad);
    v56 = _mm_sub_ps(_mm_mul_ps(v47, v51), _mm_mul_ps(_mm_shuffle_ps(v51, v51, 201), v44));
    v57 = _mm_mul_ps(_mm_shuffle_ps(v56, v56, 201), v53.m_quad);
    v58 = _mm_unpacklo_ps(v55, v57);
    v59 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v48, v48, 201), v52), _mm_mul_ps(_mm_shuffle_ps(v52, v52, 201), v48));
    v60 = _mm_mul_ps(_mm_shuffle_ps(v59, v59, 201), v53.m_quad);
    v61 = _mm_movelh_ps(v58, v60);
    v62.m_quad = _mm_add_ps(
                   _mm_shuffle_ps(_mm_unpackhi_ps(v55, v57), v60, 228),
                   _mm_add_ps(v61, _mm_shuffle_ps(_mm_movehl_ps(v61, v58), v60, 212)));
    v63 = _mm_movemask_ps(_mm_cmpltps(v62.m_quad, (__m128)0i64)) & 7;
    if ( v63 == 7 )
    {
      v64 = _mm_mul_ps(_mm_sub_ps(this->m_verticesA[0].m_quad, this->m_verticesBinA[0].m_quad), v53.m_quad);
      if ( _mm_movemask_ps(
             _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v64, v64, 85), _mm_shuffle_ps(v64, v64, 0)),
               _mm_shuffle_ps(v64, v64, 170))) )
      {
        v65 = vertexB->m_quad;
        *vertexB = (hkVector4f)v7.m_quad;
        vertexB[1] = (hkVector4f)v65;
        v53.m_quad = _mm_xor_ps(v53.m_quad, (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0));
        v62.m_quad = _mm_shuffle_ps(v62.m_quad, v62.m_quad, 225);
      }
    }
    this->m_checkTriangleDots = (hkVector4f)v62.m_quad;
    *supportOut = (hkVector4f)v53.m_quad;
    if ( v63 == 7 )
    {
      *vertexA = (hkVector4f)v45.m_quad;
      return 0i64;
    }
    v6 = v190;
    v8 = v188;
  }
  v66 = _mm_sub_ps(v8, v6);
  v67 = _mm_sub_ps(v9, v6);
  v68 = _mm_mul_ps(v66, v11);
  v69 = _mm_mul_ps(v66, v66);
  v70 = v66;
  v71 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v68, v68, 85), _mm_shuffle_ps(v68, v68, 0)), _mm_shuffle_ps(v68, v68, 170));
  v72 = _mm_mul_ps(v67, v66);
  v73 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v72, v72, 85), _mm_shuffle_ps(v72, v72, 0)), _mm_shuffle_ps(v72, v72, 170));
  v74 = _mm_mul_ps(v67, v11);
  v75 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v74, v74, 85), _mm_shuffle_ps(v74, v74, 0)), _mm_shuffle_ps(v74, v74, 170));
  v76 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v69, v69, 85), _mm_shuffle_ps(v69, v69, 0)), _mm_shuffle_ps(v69, v69, 170));
  v77 = _mm_mul_ps(v11, v11);
  v78 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v77, v77, 85), _mm_shuffle_ps(v77, v77, 0)), _mm_shuffle_ps(v77, v77, 170));
  v79 = _mm_max_ps(_mm_sub_ps(_mm_mul_ps(v78, v76), _mm_mul_ps(v71, v71)), *(__m128 *)&epsilon);
  v80 = _mm_rcp_ps(v79);
  v81 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v80, v79)), v80);
  v82 = _mm_rcp_ps(v78);
  v83 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v82, v78)), v82);
  v84 = _mm_rcp_ps(v76);
  v85 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v84, v76)), v84);
  v86 = _mm_sub_ps(_mm_mul_ps(v78, v73), _mm_mul_ps(v75, v71));
  v87 = _mm_cmpltps(v86, v79);
  v88 = _mm_cmpleps(v79, *(__m128 *)&epsilon);
  v89 = _mm_sub_ps(
          _mm_mul_ps(
            _mm_or_ps(
              _mm_andnot_ps(
                v88,
                _mm_mul_ps(_mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_and_ps(v87, v86), _mm_andnot_ps(v87, v79))), v81)),
              _mm_and_ps(v88, query.m_quad)),
            _mm_mul_ps(v71, v83)),
          _mm_mul_ps(v75, v83));
  v90 = _mm_cmpltps(v89, query.m_quad);
  v91 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_andnot_ps(v90, query.m_quad), _mm_and_ps(v90, v89)));
  v92 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v71, v85), v91), _mm_mul_ps(v73, v85));
  v93 = _mm_cmpltps(v92, query.m_quad);
  v94 = _mm_sub_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_max_ps((__m128)0i64, _mm_or_ps(_mm_andnot_ps(v93, query.m_quad), _mm_and_ps(v93, v92))), v70),
            vertexA->m_quad),
          _mm_add_ps(_mm_mul_ps(v91, v11), vertexB[2].m_quad));
  v95 = _mm_mul_ps(v70, v189);
  v96 = _mm_mul_ps(v94, v94);
  v97 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v96, v96, 85), _mm_shuffle_ps(v96, v96, 0)), _mm_shuffle_ps(v96, v96, 170));
  v98 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v95, v95, 85), _mm_shuffle_ps(v95, v95, 0)), _mm_shuffle_ps(v95, v95, 170));
  v99 = v67;
  v100 = _mm_mul_ps(v67, v189);
  v101 = _mm_mul_ps(v99, v70);
  v102 = _mm_add_ps(
           _mm_add_ps(_mm_shuffle_ps(v101, v101, 85), _mm_shuffle_ps(v101, v101, 0)),
           _mm_shuffle_ps(v101, v101, 170));
  v103 = _mm_add_ps(
           _mm_add_ps(_mm_shuffle_ps(v100, v100, 85), _mm_shuffle_ps(v100, v100, 0)),
           _mm_shuffle_ps(v100, v100, 170));
  v104 = _mm_mul_ps(v189, v189);
  v105 = _mm_add_ps(
           _mm_add_ps(_mm_shuffle_ps(v104, v104, 85), _mm_shuffle_ps(v104, v104, 0)),
           _mm_shuffle_ps(v104, v104, 170));
  v106 = _mm_add_ps(
           _mm_add_ps(_mm_shuffle_ps(v69, v69, 85), _mm_shuffle_ps(v69, v69, 0)),
           _mm_shuffle_ps(v69, v69, 170));
  v107 = _mm_max_ps(_mm_sub_ps(_mm_mul_ps(v105, v106), _mm_mul_ps(v98, v98)), *(__m128 *)&epsilon);
  v108 = _mm_rcp_ps(v107);
  v109 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v108, v107)), v108);
  v110 = _mm_rcp_ps(v105);
  v111 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v110, v105)), v110);
  v112 = _mm_rcp_ps(v106);
  v113 = _mm_mul_ps(v112, v106);
  v114 = _mm_cmpleps(v107, *(__m128 *)&epsilon);
  v115 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, v113), v112);
  v116 = _mm_sub_ps(_mm_mul_ps(v105, v102), _mm_mul_ps(v98, v103));
  v117 = _mm_cmpltps(v116, v107);
  v118 = _mm_sub_ps(
           _mm_mul_ps(
             _mm_or_ps(
               _mm_andnot_ps(
                 v114,
                 _mm_mul_ps(
                   _mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_andnot_ps(v117, v107), _mm_and_ps(v117, v116))),
                   v109)),
               _mm_and_ps(v114, query.m_quad)),
             _mm_mul_ps(v98, v111)),
           _mm_mul_ps(v111, v103));
  v119 = _mm_cmpltps(v118, query.m_quad);
  v120 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v119, v118), _mm_andnot_ps(v119, query.m_quad)));
  v121 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v98, v115), v120), _mm_mul_ps(v115, v102));
  v122 = _mm_cmpltps(v121, query.m_quad);
  v123 = vertexB[2].m_quad;
  result = 2i64;
  v124 = _mm_sub_ps(
           _mm_add_ps(
             _mm_mul_ps(
               _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v122, v121), _mm_andnot_ps(v122, query.m_quad))),
               v70),
             vertexA->m_quad),
           _mm_add_ps(_mm_mul_ps(v120, v189), v123));
  v125 = _mm_mul_ps(v124, v124);
  v126 = _mm_cmpltps(
           _mm_add_ps(
             _mm_add_ps(_mm_shuffle_ps(v125, v125, 85), _mm_shuffle_ps(v125, v125, 0)),
             _mm_shuffle_ps(v125, v125, 170)),
           v97);
  v127 = v126;
  v128 = _mm_and_ps(v126, vertexB->m_quad);
  v129 = _mm_andnot_ps(v127, vertexB[1].m_quad);
  vertexB[1] = (hkVector4f)v123;
  vertexB->m_quad = _mm_or_ps(v129, v128);
  return result;
}
             vertexA->m_quad),
           _mm_add_ps(_mm_mul_ps(v120, v189), v123));
  v125 = _mm_mul_ps(v124, v124);
  v126 = _mm_cmpltps(
           _mm_add_ps(
             _mm_add_ps(_mm_shu

// File Line: 43
// RVA: 0x130B1C0
__int64 __fastcall hkcdGskBase::handlePenetration(hkcdGskBase *this, hkcdGskBase::ShapeInterface *shapeInterface, const void *shapeA, const void *shapeB, hkTransformf *aTb, hkPadSpu<int> *dimA, hkPadSpu<int> *dimB, hkcdGsk::GetClosestPointOutput *output, hkVector4f *supportOut)
{
  hkcdGskBase *v9; // r15
  int v10; // eax
  int v11; // er10
  __int64 v12; // rcx
  hkcdVertex v13; // xmm0
  hkcdVertex v14; // xmm1
  __m128 v15; // xmm1
  __m128 v16; // xmm0
  signed int v17; // er14
  hkVector4f *v18; // rbx
  __m128 v19; // xmm0
  __m128 v20; // xmm1
  __m128 v21; // xmm0
  __m128 v22; // xmm0
  __m128 v23; // xmm1
  __m128 v24; // xmm1
  hkVector4f v25; // xmm0
  hkVector4f v26; // xmm1
  hkVector4f v27; // xmm1
  signed int v28; // edi
  int v29; // er10
  int v30; // er10
  int v31; // er10
  __m128 v32; // xmm2
  __m128 v33; // xmm2
  __m128 v34; // xmm2
  __m128 v35; // xmm6
  __m128 v36; // xmm6
  __m128 v37; // xmm3
  __m128 v38; // xmm3
  __m128 v39; // xmm5
  __m128 v40; // xmm2
  __m128 v41; // xmm8
  __m128 v42; // xmm4
  __m128 v43; // xmm8
  __m128 v44; // xmm1
  __m128 v45; // xmm2
  __m128 v46; // xmm3
  __m128 v47; // xmm8
  __m128 v48; // xmm1
  __m128 v49; // xmm4
  __m128 v50; // xmm2
  __m128 v51; // xmm7
  __m128 v52; // xmm7
  __m128 v53; // xmm1
  __m128 v54; // xmm2
  __m128 v55; // xmm1
  hkcdVertex v56; // xmm0
  __m128 v57; // xmm0
  __m128 v58; // xmm1
  __m128 v59; // xmm0
  __m128 v60; // xmm4
  __m128 v61; // xmm4
  __m128 v62; // xmm3
  __m128 v63; // xmm1
  __m128 v64; // xmm2
  hkVector4f *v65; // rax
  __m128 v66; // xmm0
  __m128 v67; // xmm1
  __m128 v68; // xmm0
  __m128 v69; // xmm2
  __m128 v70; // xmm3
  __m128 v71; // xmm1
  __m128 v72; // xmm7
  hkVector4f *v73; // r8
  __m128 v74; // xmm7
  __m128 v75; // xmm5
  __m128 v76; // xmm7
  __m128 v77; // xmm1
  __m128 v78; // xmm4
  __m128 v79; // xmm2
  __m128 v80; // xmm6
  __m128 v81; // xmm1
  __m128 v82; // xmm3
  __m128 v83; // xmm2
  __m128 v84; // xmm1
  __m128 v85; // xmm4
  __m128 v86; // xmm1
  __m128 v87; // xmm2
  __m128 v88; // xmm1
  hkVector4f v89; // xmm0
  hkVector4f v90; // xmm1
  hkVector4f v91; // xmm0
  hkcdVertex v92; // xmm0
  hkVector4f v93; // xmm1
  int v94; // er8
  int v95; // edx
  bool v96; // sf
  int v97; // er8
  float v98; // xmm0_4
  float *v99; // rcx
  hkcdWingedEdge::Triangle *v100; // rdi
  unsigned int v101; // eax
  unsigned __int64 v102; // r9
  hkcdGskBase::ShapeInterface *v103; // rcx
  const void *v104; // r9
  hkVector4f *v105; // r13
  __m128 v106; // xmm1
  __m128 v107; // xmm6
  __m128 v108; // xmm0
  __m128 v109; // xmm5
  __m128 v110; // xmm0
  __m128 v111; // xmm6
  __m128 v112; // xmm1
  __m128 v113; // xmm2
  __int128 v114; // xmm0
  float v115; // xmm3_4
  __m128 v116; // xmm6
  __int128 v117; // xmm7
  __int128 v118; // xmm8
  __int128 v119; // xmm9
  int v120; // ebx
  __int128 v121; // xmm10
  __int128 v122; // xmm11
  __int128 v123; // xmm12
  float v124; // xmm4_4
  signed int v125; // eax
  __m128 v126; // xmm1
  float v127; // xmm2_4
  float v128; // xmm2_4
  int v129; // edx
  __int64 v130; // r12
  int v131; // er9
  __int64 v132; // r10
  __int64 v133; // rcx
  __int64 v134; // rdx
  __int64 *v135; // rcx
  __int64 v136; // rax
  hkcdWingedEdge::Edge *v137; // r9
  __int64 v138; // rsi
  hkcdWingedEdge::Edge *v139; // rbx
  signed int v140; // er15
  __int64 v141; // r11
  __int64 v142; // r14
  __m128 *v143; // r8
  __m128 *v144; // rdx
  __m128 v145; // xmm1
  __m128 v146; // xmm0
  __m128 v147; // xmm4
  __m128 v148; // xmm4
  __m128 v149; // xmm3
  __m128 v150; // xmm1
  __m128 v151; // xmm2
  __m128 v152; // xmm4
  __m128 v153; // xmm5
  hkcdWingedEdge::Edge *v154; // rax
  int v155; // ecx
  hkcdWingedEdge::Triangle::TriangleState *v156; // rax
  int v157; // ecx
  hkPadSpu<hkcdWingedEdge::Edge *> *v158; // rax
  int v159; // eax
  unsigned int v160; // esi
  hkcdWingedEdge::Triangle::TriangleState v161; // eax
  float v162; // xmm0_4
  __m128 *v163; // rdx
  __m128 *v164; // rcx
  __m128 v165; // xmm8
  __m128 v166; // xmm6
  __m128 v167; // xmm4
  __m128 v168; // xmm0
  __m128 v169; // xmm1
  __m128 v170; // xmm7
  __m128 v171; // xmm6
  __m128 v172; // xmm5
  __m128 v173; // xmm5
  __m128 v174; // xmm1
  __m128 v175; // xmm3
  __m128 v176; // xmm2
  __m128 v177; // xmm7
  __m128 v178; // xmm1
  __m128 v179; // xmm7
  __m128 v180; // xmm0
  __m128 v181; // xmm4
  __m128 v182; // xmm3
  __m128 v183; // xmm2
  __m128 v184; // xmm5
  float v185; // xmm13_4
  int v186; // er9
  hkcdWingedEdge::Edge *v187; // r8
  __m128 *v188; // rcx
  __m128 *v189; // rdx
  __m128 v190; // xmm8
  __m128 v191; // xmm5
  __m128 v192; // xmm6
  __m128 v193; // xmm9
  __m128 v194; // xmm1
  __m128 v195; // xmm4
  __m128 v196; // xmm3
  __m128 v197; // xmm3
  __m128 v198; // xmm2
  __m128 v199; // xmm7
  __m128 v200; // xmm1
  __m128 v201; // xmm5
  __m128 v202; // xmm9
  __m128 v203; // xmm4
  __m128 v204; // xmm1
  __m128 v205; // xmm3
  __m128 v206; // xmm1
  __m128 v207; // xmm2
  __m128 v208; // xmm1
  __m128 v209; // xmm4
  __m128 v210; // xmm3
  float v211; // xmm5_4
  __m128 *v212; // rdx
  __m128 *v213; // rax
  __m128 *v214; // rcx
  __m128 v215; // xmm3
  __m128 v216; // xmm7
  __m128 v217; // xmm0
  __m128 v218; // xmm1
  __m128 v219; // xmm6
  __m128 v220; // xmm5
  __m128 v221; // xmm5
  __m128 v222; // xmm1
  __m128 v223; // xmm4
  __m128 v224; // xmm2
  __m128 v225; // xmm7
  __m128 v226; // xmm1
  __m128 v227; // xmm7
  __m128 v228; // xmm0
  __m128 v229; // xmm3
  __m128 v230; // xmm2
  __m128 v231; // xmm1
  __m128 *v232; // r8
  hkcdVertex *v233; // rcx
  hkcdWingedEdge::Vertex *v234; // r9
  hkcdVertex *v235; // rax
  hkcdVertex v236; // xmm1
  __m128 v237; // xmm0
  __m128 v238; // xmm1
  __m128 v239; // xmm4
  __m128 v240; // xmm7
  __m128 v241; // xmm6
  __m128 v242; // xmm5
  __m128 v243; // xmm5
  __m128 v244; // xmm1
  __m128 v245; // xmm3
  __m128 v246; // xmm2
  __m128 v247; // xmm7
  __m128 v248; // xmm1
  __m128 v249; // xmm7
  __m128 v250; // xmm0
  __m128 v251; // xmm5
  __m128 v252; // xmm3
  __m128 v253; // xmm2
  __m128 v254; // xmm4
  hkVector4f v255; // xmm8
  __m128 v256; // xmm9
  __m128i v257; // xmm14
  __m128 v258; // xmm6
  __m128 v259; // xmm7
  __m128 v260; // xmm2
  hkVector4f v261; // xmm11
  __m128 v262; // xmm13
  __m128 v263; // xmm12
  __m128 v264; // xmm10
  __m128 v265; // xmm0
  signed __int64 v266; // rbx
  hkcdGskBase::ShapeInterfaceVtbl *v267; // rax
  __m128 v268; // xmm1
  __m128 v269; // xmm2
  __m128 v270; // xmm5
  __m128 v271; // xmm4
  __m128 v272; // xmm5
  __m128 v273; // xmm1
  __m128 v274; // xmm2
  __m128 v275; // xmm3
  __m128 v276; // xmm7
  __m128 v277; // xmm1
  __m128 v278; // xmm4
  __m128 v279; // xmm2
  __m128 v280; // xmm7
  __m128 v281; // xmm0
  __m128 v282; // xmm4
  __m128 v283; // xmm7
  __m128 v284; // xmm9
  __m128 v285; // xmm4
  __m128 v286; // xmm1
  __m128 v287; // xmm4
  __m128 v288; // xmm2
  __m128 v289; // xmm1
  __m128 v290; // xmm3
  __m128 v291; // xmm6
  __m128 v292; // xmm8
  __m128 v293; // xmm1
  __m128 v294; // xmm10
  __m128 v295; // xmm1
  __m128 v296; // xmm9
  __m128 v297; // xmm4
  __m128 v298; // xmm3
  __int16 v299; // ax
  int v300; // ecx
  __int16 v301; // ax
  int v302; // ecx
  __int64 v303; // rax
  hkPadSpu<int> chainLength; // [rsp+40h] [rbp-C0h]
  hkVector4f v305; // [rsp+50h] [rbp-B0h]
  hkcdConvexPenetrationUtil v306; // [rsp+60h] [rbp-A0h]
  hkVector4f v307; // [rsp+110h] [rbp+10h]
  hkPadSpu<hkcdWingedEdge::Edge *> edgeChain; // [rsp+120h] [rbp+20h]
  hkSimdFloat32 v309; // [rsp+130h] [rbp+30h]
  __m128 v310; // [rsp+140h] [rbp+40h]
  hkSimdFloat32 v311; // [rsp+150h] [rbp+50h]
  __m128 v312; // [rsp+160h] [rbp+60h]
  hkcdWingedEdge::Edge *v313; // [rsp+170h] [rbp+70h]
  hkVector4f direction; // [rsp+180h] [rbp+80h]
  hkcdWingedEdge::Vertex result; // [rsp+190h] [rbp+90h]
  hkcdWingedEdge::Vertex v316; // [rsp+1D0h] [rbp+D0h]
  hkVector4f v317; // [rsp+210h] [rbp+110h]
  hkSimdFloat32 v318; // [rsp+220h] [rbp+120h]
  hkVector4f v319; // [rsp+230h] [rbp+130h]
  hkVector4f v320; // [rsp+240h] [rbp+140h]
  hkVector4f from; // [rsp+250h] [rbp+150h]
  __m128 v322; // [rsp+260h] [rbp+160h]
  __m128 v323; // [rsp+270h] [rbp+170h]
  __m128 v324; // [rsp+280h] [rbp+180h]
  __int128 v325; // [rsp+300h] [rbp+200h]
  __int64 v326; // [rsp+310h] [rbp+210h]
  __int64 v327[99]; // [rsp+318h] [rbp+218h]
  hkcdWingedEdge v328; // [rsp+630h] [rbp+530h]
  hkcdGskBase *v329; // [rsp+4A20h] [rbp+4920h]
  hkcdGskBase::ShapeInterface *v330; // [rsp+4A28h] [rbp+4928h]
  const void *v331; // [rsp+4A30h] [rbp+4930h]
  const void *v332; // [rsp+4A38h] [rbp+4938h]

  v332 = shapeB;
  v331 = shapeA;
  v330 = shapeInterface;
  v329 = this;
  v9 = this;
  v10 = dimB->m_storage;
  v11 = 4;
  if ( dimB->m_storage < 3 )
  {
    v12 = dimA->m_storage;
    if ( (signed int)v12 < 3 )
    {
      v13.m_quad = (__m128)v9->m_verticesA[0];
      v14.m_quad = (__m128)v9->m_verticesBinA[0];
      v11 = 1;
      v9->m_verticesA[v12] = (hkcdVertex)v13.m_quad;
      v9->m_verticesA[dimA->m_storage + 1] = (hkcdVertex)v13.m_quad;
      v9->m_verticesBinA[dimB->m_storage] = (hkcdVertex)v14.m_quad;
      v9->m_verticesBinA[dimB->m_storage + 1] = (hkcdVertex)v14.m_quad;
    }
    else
    {
      if ( (signed int)v12 <= 3 )
      {
        if ( v10 <= 1 )
        {
          v11 = 3;
        }
        else
        {
          v9->m_verticesA[3] = v9->m_verticesA[0];
          v9->m_verticesBinA[3] = v9->m_verticesBinA[1];
        }
      }
      else
      {
        v9->m_verticesBinA[3] = v9->m_verticesBinA[0];
      }
      v9->m_verticesBinA[1] = v9->m_verticesBinA[0];
      v9->m_verticesBinA[2] = v9->m_verticesBinA[0];
    }
  }
  else
  {
    if ( v10 <= 3 )
    {
      if ( dimA->m_storage <= 1 )
      {
        v11 = 3;
      }
      else
      {
        this->m_verticesA[3] = this->m_verticesA[1];
        this->m_verticesBinA[3] = this->m_verticesBinA[0];
      }
    }
    else
    {
      this->m_verticesA[3] = this->m_verticesA[0];
    }
    this->m_verticesA[1] = this->m_verticesA[0];
    this->m_verticesA[2] = this->m_verticesA[0];
  }
  v15 = v9->m_verticesA[1].m_quad;
  v16 = v9->m_verticesA[0].m_quad;
  v17 = 0;
  v18 = &from;
  v306.m_shapeInterface.m_storage = shapeInterface;
  v306.m_shapeA.m_storage = shapeA;
  v19 = _mm_sub_ps(v16, v9->m_verticesBinA[0].m_quad);
  v20 = _mm_sub_ps(v15, v9->m_verticesBinA[1].m_quad);
  v306.m_shapeB.m_storage = shapeB;
  v306.m_pointsAinA.m_storage = v9->m_verticesA;
  v306.m_pointsBinA.m_storage = v9->m_verticesBinA;
  from.m_quad = v19;
  v21 = v9->m_verticesA[2].m_quad;
  v322 = v20;
  v22 = _mm_sub_ps(v21, v9->m_verticesBinA[2].m_quad);
  v23 = v9->m_verticesA[3].m_quad;
  v306.m_backupTries.m_storage = 0;
  v306.m_simplex.m_storage = &from;
  v323 = v22;
  v24 = _mm_sub_ps(v23, v9->m_verticesBinA[3].m_quad);
  v306.m_aTb.m_rotation.m_col0 = aTb->m_rotation.m_col0;
  v25.m_quad = (__m128)aTb->m_rotation.m_col2;
  v324 = v24;
  v26.m_quad = (__m128)aTb->m_rotation.m_col1;
  v306.m_aTb.m_rotation.m_col2 = (hkVector4f)v25.m_quad;
  v306.m_aTb.m_rotation.m_col1 = (hkVector4f)v26.m_quad;
  v27.m_quad = (__m128)aTb->m_translation;
  v306.m_epsTol = *(hkVector4f *)_xmm;
  v306.m_aTb.m_translation = (hkVector4f)v27.m_quad;
  chainLength.m_storage = LODWORD(FLOAT_9_9999991eN9);
  v306.m_epsTolSqrd.m_real = _mm_shuffle_ps((__m128)LODWORD(FLOAT_9_9999991eN9), (__m128)LODWORD(FLOAT_9_9999991eN9), 0);
LABEL_17:
  v306.m_simplexSize.m_storage = v11;
LABEL_18:
  v28 = -1;
  if ( v11 )
  {
    v29 = v11 - 1;
    if ( v29 )
    {
      v30 = v29 - 1;
      if ( v30 )
      {
        v31 = v30 - 1;
        if ( v31 )
        {
          if ( v31 != 1 )
            goto LABEL_109;
          goto LABEL_43;
        }
        goto LABEL_40;
      }
      goto LABEL_34;
    }
    goto LABEL_28;
  }
  while ( 1 )
  {
    v32 = _mm_mul_ps(v306.m_aTb.m_translation.m_quad, v306.m_aTb.m_translation.m_quad);
    direction.m_quad = _mm_xor_ps(
                         (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                         v306.m_aTb.m_translation.m_quad);
    if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v32, v32, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v32, v32, 0)))
               + COERCE_FLOAT(_mm_shuffle_ps(v32, v32, 170))) <= v306.m_epsTolSqrd.m_real.m128_f32[0] )
      direction.m_quad = ::direction.m_quad;
    hkcdConvexPenetrationUtil::getPointForSimplex(&v306, &direction, &result);
    *v306.m_simplex.m_storage = result.m_position;
    *v306.m_pointsAinA.m_storage = result.m_pointAinA;
    *v306.m_pointsBinA.m_storage = result.m_pointBinX;
    v18 = v306.m_simplex.m_storage;
    v306.m_simplexSize.m_storage = 1;
    v33 = _mm_mul_ps(v306.m_simplex.m_storage->m_quad, v306.m_simplex.m_storage->m_quad);
    if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v33, v33, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v33, v33, 0)))
               + COERCE_FLOAT(_mm_shuffle_ps(v33, v33, 170))) <= v306.m_epsTolSqrd.m_real.m128_f32[0] )
      break;
    v28 = 0;
LABEL_28:
    v34 = _mm_mul_ps(v18->m_quad, v18->m_quad);
    if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v34, v34, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v34, v34, 0)))
               + COERCE_FLOAT(_mm_shuffle_ps(v34, v34, 170))) > v306.m_epsTolSqrd.m_real.m128_f32[0] )
    {
      v28 = 1;
      hkcdConvexPenetrationUtil::getPointForSimplex(&v306, v18, &result);
      v35 = _mm_sub_ps(result.m_position.m_quad, v306.m_simplex.m_storage->m_quad);
      v36 = _mm_mul_ps(v35, v35);
      v317.m_quad = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v18->m_quad);
      hkcdConvexPenetrationUtil::getPointForSimplex(&v306, &v317, &v316);
      v37 = _mm_sub_ps(v316.m_position.m_quad, v306.m_simplex.m_storage->m_quad);
      v38 = _mm_mul_ps(v37, v37);
      if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v36, v36, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v36, v36, 0)))
                 + COERCE_FLOAT(_mm_shuffle_ps(v36, v36, 170))) < (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v38, v38, 85))
                                                                                + COERCE_FLOAT(_mm_shuffle_ps(v38, v38, 0)))
                                                                        + COERCE_FLOAT(_mm_shuffle_ps(v38, v38, 170))) )
      {
        v306.m_simplex.m_storage[1] = v316.m_position;
        v306.m_pointsAinA.m_storage[1] = v316.m_pointAinA;
        v306.m_pointsBinA.m_storage[1] = v316.m_pointBinX;
      }
      else
      {
        v306.m_simplex.m_storage[1] = result.m_position;
        v306.m_pointsAinA.m_storage[1] = result.m_pointAinA;
        v306.m_pointsBinA.m_storage[1] = result.m_pointBinX;
      }
      v18 = v306.m_simplex.m_storage;
      while ( 1 )
      {
        v306.m_simplexSize.m_storage = 2;
LABEL_34:
        v39 = _mm_sub_ps(v18->m_quad, v18[1].m_quad);
        v40 = _mm_mul_ps(v39, v39);
        if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v40, v40, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v40, v40, 0)))
                   + COERCE_FLOAT(_mm_shuffle_ps(v40, v40, 170))) <= v306.m_epsTolSqrd.m_real.m128_f32[0] )
        {
          if ( v28 < 1 )
          {
            v306.m_simplexSize.m_storage = 1;
            goto LABEL_28;
          }
          goto LABEL_109;
        }
        v28 = 2;
        v41 = _mm_shuffle_ps(v39, _mm_unpackhi_ps(v39, (__m128)0i64), 196);
        v42 = _mm_shuffle_ps(v41, v41, 241);
        v43 = _mm_shuffle_ps(v41, v41, 206);
        v44 = _mm_mul_ps(v42, v42);
        v45 = _mm_mul_ps(v43, v43);
        v46 = _mm_cmpltps(
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v44, v44, 85), _mm_shuffle_ps(v44, v44, 0)),
                  _mm_shuffle_ps(v44, v44, 170)),
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v45, v45, 85), _mm_shuffle_ps(v45, v45, 0)),
                  _mm_shuffle_ps(v45, v45, 170)));
        v47 = _mm_xor_ps(
                _mm_or_ps(_mm_and_ps(v43, v46), _mm_andnot_ps(v46, v42)),
                (__m128)_mm_insert_epi16((__m128i)0i64, 0x8000u, 1));
        v48 = _mm_mul_ps(v47, v47);
        v49 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v48, v48, 85), _mm_shuffle_ps(v48, v48, 0)),
                _mm_shuffle_ps(v48, v48, 170));
        v50 = _mm_rsqrt_ps(v49);
        v51 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v47, v47, 201), v39), _mm_mul_ps(_mm_shuffle_ps(v39, v39, 201), v47));
        v52 = _mm_shuffle_ps(v51, v51, 201);
        v53 = _mm_mul_ps(v52, v52);
        v320.m_quad = _mm_mul_ps(
                        v47,
                        _mm_andnot_ps(
                          _mm_cmpleps(v49, (__m128)0i64),
                          _mm_mul_ps(
                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v50, v49), v50)),
                            _mm_mul_ps(*(__m128 *)_xmm, v50))));
        v54 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v53, v53, 85), _mm_shuffle_ps(v53, v53, 0)),
                _mm_shuffle_ps(v53, v53, 170));
        v55 = _mm_rsqrt_ps(v54);
        v319.m_quad = _mm_mul_ps(
                        v52,
                        _mm_andnot_ps(
                          _mm_cmpleps(v54, (__m128)0i64),
                          _mm_mul_ps(
                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v55, v54), v55)),
                            _mm_mul_ps(*(__m128 *)_xmm, v55))));
        hkcdConvexPenetrationUtil::findBestProjection(&v306, &v309, &v320, v18, &v316);
        hkcdConvexPenetrationUtil::findBestProjection(&v306, &v318, &v319, v306.m_simplex.m_storage, &result);
        if ( v318.m_real.m128_f32[0] >= v309.m_real.m128_f32[0] )
        {
          v306.m_simplex.m_storage[2] = result.m_position;
          v306.m_pointsAinA.m_storage[2] = result.m_pointAinA;
          v56.m_quad = (__m128)result.m_pointBinX;
        }
        else
        {
          v306.m_simplex.m_storage[2] = v316.m_position;
          v306.m_pointsAinA.m_storage[2] = v316.m_pointAinA;
          v56.m_quad = (__m128)v316.m_pointBinX;
        }
        v306.m_pointsBinA.m_storage[2] = (hkcdVertex)v56.m_quad;
        v18 = v306.m_simplex.m_storage;
LABEL_39:
        v306.m_simplexSize.m_storage = 3;
LABEL_40:
        v57 = v18[1].m_quad;
        v58 = _mm_sub_ps(v18->m_quad, v57);
        v59 = _mm_sub_ps(v57, v18[2].m_quad);
        v60 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v59, v59, 201), v58), _mm_mul_ps(_mm_shuffle_ps(v58, v58, 201), v59));
        v61 = _mm_shuffle_ps(v60, v60, 201);
        v305.m_quad = v61;
        v62 = _mm_mul_ps(v61, v61);
        if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v62, v62, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v62, v62, 0)))
                   + COERCE_FLOAT(_mm_shuffle_ps(v62, v62, 170))) != 0.0 )
          break;
        if ( v28 >= 2 )
        {
          v72 = _mm_sub_ps(v18->m_quad, v18[1].m_quad);
          output->m_distance = 0i64;
          v73 = &output->m_normalInA;
          v74 = _mm_shuffle_ps(v72, _mm_unpackhi_ps(v72, (__m128)0i64), 196);
          v75 = _mm_shuffle_ps(v74, v74, 241);
          v76 = _mm_shuffle_ps(v74, v74, 206);
          v77 = _mm_mul_ps(v76, v76);
          v78 = _mm_mul_ps(v75, v75);
          v79 = _mm_cmpltps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v78, v78, 85), _mm_shuffle_ps(v78, v78, 0)),
                    _mm_shuffle_ps(v78, v78, 170)),
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v77, v77, 85), _mm_shuffle_ps(v77, v77, 0)),
                    _mm_shuffle_ps(v77, v77, 170)));
          v80 = _mm_xor_ps(
                  _mm_or_ps(_mm_andnot_ps(v79, v75), _mm_and_ps(v76, v79)),
                  (__m128)_mm_insert_epi16((__m128i)0i64, 0x8000u, 1));
          v81 = _mm_mul_ps(v80, v80);
          v82 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v81, v81, 85), _mm_shuffle_ps(v81, v81, 0)),
                  _mm_shuffle_ps(v81, v81, 170));
          v83 = _mm_rsqrt_ps(v82);
          output->m_normalInA.m_quad = _mm_mul_ps(
                                         _mm_andnot_ps(
                                           _mm_cmpleps(v82, (__m128)0i64),
                                           _mm_mul_ps(
                                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v83, v82), v83)),
                                             _mm_mul_ps(*(__m128 *)_xmm, v83))),
                                         v80);
          v84 = (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128((const __m128i *)v18), 1u), 1u);
          v85 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v84, v84, 85), _mm_shuffle_ps(v84, v84, 0)),
                  _mm_shuffle_ps(v84, v84, 170));
          v86 = _mm_add_ps(_mm_add_ps(v85, v85), *(__m128 *)&epsilon);
          v87 = _mm_rcp_ps(v86);
          output->m_pointAinA.m_quad = _mm_add_ps(
                                         _mm_mul_ps(
                                           _mm_sub_ps(
                                             v306.m_pointsAinA.m_storage[1].m_quad,
                                             v306.m_pointsAinA.m_storage->m_quad),
                                           _mm_mul_ps(
                                             _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v87, v86)), v87),
                                             v85)),
                                         v306.m_pointsAinA.m_storage->m_quad);
          goto LABEL_138;
        }
      }
      v28 = 3;
      v63 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v62, v62, 85), _mm_shuffle_ps(v62, v62, 0)),
              _mm_shuffle_ps(v62, v62, 170));
      v64 = _mm_rsqrt_ps(v63);
      v305.m_quad = _mm_mul_ps(
                      v61,
                      _mm_andnot_ps(
                        _mm_cmpleps(v63, (__m128)0i64),
                        _mm_mul_ps(
                          _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v64, v63), v64)),
                          _mm_mul_ps(*(__m128 *)_xmm, v64))));
      hkcdConvexPenetrationUtil::findBestProjection(&v306, &v311, &v305, v18, &v316);
      v65 = v306.m_simplex.m_storage;
      if ( v311.m_real.m128_f32[0] < COERCE_FLOAT(_mm_shuffle_ps(v306.m_epsTol.m_quad, v306.m_epsTol.m_quad, 0)) )
      {
        output->m_normalInA = (hkVector4f)v305.m_quad;
        output->m_distance = 0i64;
        v73 = &output->m_normalInA;
        v237 = _mm_sub_ps(v65[2].m_quad, v65->m_quad);
        v238 = _mm_sub_ps(v65[1].m_quad, v65->m_quad);
        v239 = _mm_sub_ps(v65[2].m_quad, aabbOut.m_quad);
        v240 = _mm_sub_ps(v65[1].m_quad, aabbOut.m_quad);
        v241 = _mm_sub_ps(v65->m_quad, aabbOut.m_quad);
        v242 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v237, v237, 201), v238),
                 _mm_mul_ps(_mm_shuffle_ps(v238, v238, 201), v237));
        v243 = _mm_shuffle_ps(v242, v242, 201);
        v244 = _mm_shuffle_ps(v243, v243, 210);
        v245 = _mm_mul_ps(
                 _mm_sub_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v239, v239, 201), v244),
                   _mm_mul_ps(_mm_shuffle_ps(v239, v239, 210), v243)),
                 v240);
        v246 = _mm_mul_ps(
                 _mm_sub_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v241, v241, 201), v244),
                   _mm_mul_ps(_mm_shuffle_ps(v241, v241, 210), v243)),
                 v239);
        v247 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v240, v240, 201), v244),
                 _mm_mul_ps(_mm_shuffle_ps(v240, v240, 210), v243));
        v248 = _mm_unpacklo_ps(v245, v246);
        v249 = _mm_mul_ps(v247, v241);
        v250 = _mm_movelh_ps(v248, v249);
        v251 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(_mm_movehl_ps(v250, v248), v249, 212), v250),
                 _mm_shuffle_ps(_mm_unpackhi_ps(v245, v246), v249, 228));
        v252 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v251, v251, 85), _mm_shuffle_ps(v251, v251, 0)),
                 _mm_shuffle_ps(v251, v251, 170));
        v253 = _mm_rcp_ps(v252);
        v254 = _mm_mul_ps(
                 _mm_andnot_ps(
                   _mm_cmpeqps(v252, (__m128)0i64),
                   _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v253, v252)), v253)),
                 v251);
        output->m_pointAinA.m_quad = _mm_add_ps(
                                       _mm_add_ps(
                                         _mm_mul_ps(
                                           _mm_shuffle_ps(v254, v254, 85),
                                           v306.m_pointsAinA.m_storage[1].m_quad),
                                         _mm_mul_ps(_mm_shuffle_ps(v254, v254, 0), v306.m_pointsAinA.m_storage->m_quad)),
                                       _mm_mul_ps(
                                         _mm_shuffle_ps(v254, v254, 170),
                                         v306.m_pointsAinA.m_storage[2].m_quad));
        goto LABEL_138;
      }
      v306.m_simplex.m_storage[3] = v316.m_position;
      v306.m_pointsAinA.m_storage[3] = v316.m_pointAinA;
      v306.m_pointsBinA.m_storage[3] = v316.m_pointBinX;
      v18 = v306.m_simplex.m_storage;
      v306.m_simplexSize.m_storage = 4;
LABEL_43:
      v66 = v18[1].m_quad;
      v67 = _mm_sub_ps(v18->m_quad, v66);
      v68 = _mm_sub_ps(v66, v18[2].m_quad);
      v69 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v68, v68, 201), v67), _mm_mul_ps(_mm_shuffle_ps(v67, v67, 201), v68));
      v305.m_quad = _mm_shuffle_ps(v69, v69, 201);
      v70 = _mm_mul_ps(v305.m_quad, v305.m_quad);
      v71 = _mm_mul_ps(_mm_sub_ps(v18[3].m_quad, v18->m_quad), v305.m_quad);
      v69.m128_f32[0] = (float)(COERCE_FLOAT(_mm_shuffle_ps(v71, v71, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v71, v71, 0)))
                      + COERCE_FLOAT(_mm_shuffle_ps(v71, v71, 170));
      if ( (float)(v69.m128_f32[0] * v69.m128_f32[0]) <= (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v70, v70, 85))
                                                                               + COERCE_FLOAT(_mm_shuffle_ps(v70, v70, 0)))
                                                                       + COERCE_FLOAT(_mm_shuffle_ps(v70, v70, 170)))
                                                               * v306.m_epsTolSqrd.m_real.m128_f32[0]) )
      {
        if ( v28 >= 3 )
          goto LABEL_109;
        goto LABEL_39;
      }
      v328.m_numVertices.m_storage = 4;
      v328.m_vertex[0].m_pointAinA = (hkcdVertex)v306.m_pointsAinA.m_storage->m_quad;
      v88 = v306.m_pointsBinA.m_storage->m_quad;
      v89.m_quad = v18->m_quad;
      v328.m_vertex[0].m_referee.m_storage = 0i64;
      v328.m_vertex[0].m_pointBinX.m_quad = v88;
      v328.m_vertex[0].m_position = (hkVector4f)v89.m_quad;
      v328.m_vertex[1].m_pointAinA = v306.m_pointsAinA.m_storage[1];
      v328.m_vertex[1].m_pointBinX = v306.m_pointsBinA.m_storage[1];
      v90.m_quad = (__m128)v18[1];
      v328.m_vertex[1].m_referee.m_storage = 0i64;
      v328.m_vertex[1].m_position = (hkVector4f)v90.m_quad;
      v328.m_vertex[2].m_pointAinA = v306.m_pointsAinA.m_storage[2];
      v328.m_vertex[2].m_pointBinX = v306.m_pointsBinA.m_storage[2];
      v91.m_quad = (__m128)v18[2];
      v328.m_vertex[2].m_referee.m_storage = 0i64;
      v328.m_vertex[2].m_position = (hkVector4f)v91.m_quad;
      v328.m_vertex[3].m_pointAinA = v306.m_pointsAinA.m_storage[3];
      v92.m_quad = (__m128)v306.m_pointsBinA.m_storage[3];
      v93.m_quad = (__m128)v18[3];
      v328.m_vertex[3].m_referee.m_storage = 0i64;
      v328.m_vertex[3].m_pointBinX = (hkcdVertex)v92.m_quad;
      v328.m_vertex[3].m_position = (hkVector4f)v93.m_quad;
      hkcdWingedEdge::addTetrahedron(&v328);
      v94 = v328.m_numTriangles.m_storage;
      v95 = v328.m_numVertices.m_storage;
      v328.m_numFreeTriangle.m_storage = 0;
      while ( 1 )
      {
        v96 = v94 - 2 < 0;
        v97 = v94 - 2;
        v98 = v328.m_triangles[0].m_distanceToOrigin;
        v99 = (float *)v328.m_triangles;
        v100 = v328.m_triangles;
        if ( !v96 )
        {
          v101 = v97 + 1;
          if ( v97 + 1 >= 4 )
          {
            v102 = (unsigned __int64)v101 >> 2;
            v97 -= 4 * (v101 >> 2);
            do
            {
              if ( v99[60] < v98 )
              {
                v98 = v99[60];
                v100 = (hkcdWingedEdge::Triangle *)(v99 + 32);
              }
              if ( v99[92] < v98 )
              {
                v98 = v99[92];
                v100 = (hkcdWingedEdge::Triangle *)(v99 + 64);
              }
              if ( v99[124] < v98 )
              {
                v98 = v99[124];
                v100 = (hkcdWingedEdge::Triangle *)(v99 + 96);
              }
              if ( v99[156] < v98 )
              {
                v98 = v99[156];
                v100 = (hkcdWingedEdge::Triangle *)(v99 + 128);
              }
              v99 += 128;
              --v102;
            }
            while ( v102 );
          }
          for ( ; v97 >= 0; --v97 )
          {
            v99 += 32;
            if ( v99[28] < v98 )
            {
              v98 = v99[28];
              v100 = (hkcdWingedEdge::Triangle *)v99;
            }
          }
        }
        v103 = v306.m_shapeInterface.m_storage;
        v104 = v306.m_shapeB.m_storage;
        v328.m_numVertices.m_storage = v95 + 1;
        v105 = &v328.m_vertex[(signed __int64)v95].m_position;
        v105[3].m_quad.m128_u64[0] = 0i64;
        v103->vfptr->getSupportingVertices(
          v103,
          v306.m_shapeA.m_storage,
          &v100->m_normal,
          v104,
          &v306.m_aTb,
          (hkcdVertex *)&v105[1],
          (hkcdVertex *)&v310,
          (hkVector4f *)&v312);
        v106 = v312;
        v107 = _mm_sub_ps(v105[1].m_quad, v312);
        v108 = v312;
        *v105 = (hkVector4f)v107;
        v105[2].m_quad = _mm_shuffle_ps(v106, _mm_unpackhi_ps(v108, v310), 196);
        v109 = _mm_sub_ps(v107, v100->m_edge[0].m_vertex->m_position.m_quad);
        v110 = _mm_sub_ps(v107, v100->m_edge[1].m_vertex->m_position.m_quad);
        v111 = _mm_sub_ps(v107, v100->m_edge[2].m_vertex->m_position.m_quad);
        v112 = _mm_unpacklo_ps(v109, v110);
        v113 = _mm_movelh_ps(v112, v111);
        if ( _mm_movemask_ps(
               _mm_cmpltps(
                 _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(
                       _mm_shuffle_ps(_mm_movehl_ps(v113, v112), v111, 212),
                       _mm_shuffle_ps(v100->m_normal.m_quad, v100->m_normal.m_quad, 85)),
                     _mm_mul_ps(_mm_shuffle_ps(v100->m_normal.m_quad, v100->m_normal.m_quad, 0), v113)),
                   _mm_mul_ps(
                     _mm_shuffle_ps(_mm_unpackhi_ps(v109, v110), v111, 228),
                     _mm_shuffle_ps(v100->m_normal.m_quad, v100->m_normal.m_quad, 170))),
                 v306.m_epsTol.m_quad)) & 7 )
        {
          v160 = 1;
          goto LABEL_118;
        }
        v114 = *(_OWORD *)&v100->m_distanceToOrigin;
        v115 = FLOAT_1_0eN7;
        v116 = v100->m_normal.m_quad;
        edgeChain.m_storage = 0i64;
        chainLength.m_storage = 0;
        v117 = *(_OWORD *)&v100->m_edge[0].m_vertex;
        v118 = *(_OWORD *)&v100->m_edge[0].m_neighbour;
        v119 = *(_OWORD *)&v100->m_edge[1].m_vertex;
        v120 = v328.m_numFreeTriangle.m_storage - v328.m_numTriangles.m_storage + 100;
        v121 = *(_OWORD *)&v100->m_edge[1].m_neighbour;
        v122 = *(_OWORD *)&v100->m_edge[2].m_vertex;
        v123 = *(_OWORD *)&v100->m_edge[2].m_neighbour;
        v328.m_toleranceBorder.m_storage = FLOAT_1_0eN7;
        v325 = v114;
        v124 = FLOAT_3_40282e38;
        v328.m_previousMinimumDistance.m_storage = FLOAT_3_40282e38;
        v125 = 1;
        v126 = _mm_mul_ps(_mm_sub_ps(v105->m_quad, v100->m_edge[0].m_vertex->m_position.m_quad), v100->m_normal.m_quad);
        v127 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v126, v126, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v126, v126, 0)))
             + COERCE_FLOAT(_mm_shuffle_ps(v126, v126, 170));
        if ( v127 <= 0.0000001 )
        {
          v128 = v127 + 0.0000001;
          if ( v128 > 0.0000001 )
          {
            v115 = v128;
            v328.m_toleranceBorder.m_storage = v128;
          }
          v125 = 2;
        }
        else
        {
          if ( v127 >= 3.40282e38 )
            goto LABEL_78;
          v124 = v127;
          v328.m_previousMinimumDistance.m_storage = v127;
        }
        if ( v115 >= v124 )
          v125 = 4;
LABEL_78:
        v100->m_state = v125;
        if ( v125 != 1 || hkcdWingedEdge::findVisibleTriangles(&v328, v100, v105, &chainLength, &edgeChain) )
          goto LABEL_108;
        v129 = v328.m_numFreeTriangle.m_storage;
        v94 = v328.m_numTriangles.m_storage;
        v130 = chainLength.m_storage;
        if ( v328.m_numFreeTriangle.m_storage - v328.m_numTriangles.m_storage + 100 < chainLength.m_storage )
        {
          if ( v328.m_numFreeTriangle.m_storage > v120 )
          {
            do
            {
              hkcdWingedEdge::Triangle::calculateTriangleData(*((hkcdWingedEdge::Triangle **)&v328.m_vertex[54].m_referee
                                                              + v129
                                                              + 1));
              v129 = v328.m_numFreeTriangle.m_storage - 1;
              v328.m_numFreeTriangle.m_storage = v129;
            }
            while ( v129 > v120 );
          }
          v161 = DWORD1(v325);
          v162 = *(float *)&v325;
          v100->m_normal.m_quad = v116;
          *(_OWORD *)&v100->m_edge[0].m_vertex = v117;
          *(_OWORD *)&v100->m_edge[1].m_vertex = v119;
          *(_OWORD *)&v100->m_edge[2].m_vertex = v122;
          v160 = 3;
          *(_OWORD *)&v100->m_edge[0].m_neighbour = v118;
          *(_OWORD *)&v100->m_edge[1].m_neighbour = v121;
          *(_OWORD *)&v100->m_edge[2].m_neighbour = v123;
          v100->m_state = v161;
          v100->m_distanceToOrigin = v162;
LABEL_118:
          v94 = v328.m_numTriangles.m_storage;
          goto LABEL_119;
        }
        v131 = chainLength.m_storage;
        v132 = 0i64;
        v133 = v328.m_numFreeTriangle.m_storage - 1;
        if ( chainLength.m_storage )
        {
          do
          {
            if ( v133 < 0 )
              break;
            --v129;
            *((_QWORD *)&v325 + ++v132 + 1) = v328.m_freeTriangle[v133--];
            v328.m_numFreeTriangle.m_storage = v129;
            --v131;
          }
          while ( v131 );
        }
        if ( v131 > 0 )
        {
          v134 = (unsigned int)v131;
          v135 = &v326 + v132;
          do
          {
            v136 = v94++;
            ++v135;
            *(v135 - 1) = (__int64)&v328.m_triangles[v136];
            --v134;
          }
          while ( v134 );
          v328.m_numTriangles.m_storage = v94;
        }
        v137 = edgeChain.m_storage;
        v138 = 0i64;
        v313 = edgeChain.m_storage;
        v139 = edgeChain.m_storage;
        if ( (signed int)v130 > 0 )
          break;
LABEL_97:
        v155 = 0;
        if ( v94 > 0 )
        {
          v156 = &v328.m_triangles[0].m_state;
          do
          {
            *v156 = 0;
            v94 = v328.m_numTriangles.m_storage;
            ++v155;
            v156 += 32;
          }
          while ( v155 < v328.m_numTriangles.m_storage );
        }
        v95 = v328.m_numVertices.m_storage;
        v157 = 0;
        if ( v328.m_numVertices.m_storage > 0 )
        {
          v158 = &v328.m_vertex[0].m_referee;
          do
          {
            v158->m_storage = 0i64;
            v95 = v328.m_numVertices.m_storage;
            ++v157;
            v158 += 8;
          }
          while ( v157 < v328.m_numVertices.m_storage );
          v94 = v328.m_numTriangles.m_storage;
        }
        if ( v137 != v139 )
          goto LABEL_108;
        if ( v95 >= 55 )
        {
          v160 = 3;
LABEL_119:
          v163 = &v100->m_edge[2].m_vertex->m_position.m_quad;
          v164 = &v100->m_edge[1].m_vertex->m_position.m_quad;
          v165 = (__m128)_xmm;
          v166 = v100->m_edge[0].m_vertex->m_position.m_quad;
          v167 = _mm_sub_ps(*v163, aabbOut.m_quad);
          v168 = _mm_sub_ps(*v163, v166);
          v169 = _mm_sub_ps(*v164, v166);
          v170 = _mm_sub_ps(*v164, aabbOut.m_quad);
          v171 = _mm_sub_ps(v166, aabbOut.m_quad);
          v172 = _mm_sub_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v168, v168, 201), v169),
                   _mm_mul_ps(_mm_shuffle_ps(v169, v169, 201), v168));
          v173 = _mm_shuffle_ps(v172, v172, 201);
          v174 = _mm_shuffle_ps(v173, v173, 210);
          v175 = _mm_mul_ps(
                   _mm_sub_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v167, v167, 201), v174),
                     _mm_mul_ps(_mm_shuffle_ps(v167, v167, 210), v173)),
                   v170);
          v176 = _mm_mul_ps(
                   _mm_sub_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v171, v171, 201), v174),
                     _mm_mul_ps(_mm_shuffle_ps(v171, v171, 210), v173)),
                   v167);
          v177 = _mm_sub_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v170, v170, 201), v174),
                   _mm_mul_ps(_mm_shuffle_ps(v170, v170, 210), v173));
          v178 = _mm_unpacklo_ps(v175, v176);
          v179 = _mm_mul_ps(v177, v171);
          v180 = _mm_movelh_ps(v178, v179);
          v181 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(_mm_movehl_ps(v180, v178), v179, 212), v180),
                   _mm_shuffle_ps(_mm_unpackhi_ps(v175, v176), v179, 228));
          v182 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v181, v181, 85), _mm_shuffle_ps(v181, v181, 0)),
                   _mm_shuffle_ps(v181, v181, 170));
          v183 = _mm_rcp_ps(v182);
          v184 = _mm_mul_ps(
                   _mm_andnot_ps(
                     _mm_cmpeqps(v182, (__m128)0i64),
                     _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v183, v182)), v183)),
                   v181);
          if ( _mm_movemask_ps(_mm_cmpltps(v184, (__m128)0i64)) & 7 )
          {
            v185 = *(float *)&xmmword_141A712F0;
            v186 = v94 - 1;
            if ( v94 - 1 >= 0 )
            {
              v187 = v328.m_triangles[0].m_edge;
              do
              {
                v188 = &v187[1].m_vertex->m_position.m_quad;
                v189 = &v187[2].m_vertex->m_position.m_quad;
                v190 = v187->m_vertex->m_position.m_quad;
                v191 = _mm_sub_ps(*v188, v190);
                v192 = _mm_sub_ps(*v189, *v188);
                v193 = _mm_sub_ps(v190, *v189);
                v194 = _mm_shuffle_ps(v191, v191, 201);
                v195 = _mm_shuffle_ps(v192, v192, 201);
                v196 = _mm_sub_ps(_mm_mul_ps(v191, v195), _mm_mul_ps(v192, v194));
                v197 = _mm_shuffle_ps(v196, v196, 201);
                v198 = _mm_shuffle_ps(v197, v197, 210);
                v199 = _mm_sub_ps(_mm_mul_ps(v198, v194), _mm_mul_ps(_mm_shuffle_ps(v191, v191, 210), v197));
                v200 = _mm_mul_ps(v199, v199);
                v201 = _mm_sub_ps(_mm_mul_ps(v198, v195), _mm_mul_ps(_mm_shuffle_ps(v192, v192, 210), v197));
                v202 = _mm_sub_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v193, v193, 201), v198),
                         _mm_mul_ps(_mm_shuffle_ps(v193, v193, 210), v197));
                v203 = _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v200, v200, 85), _mm_shuffle_ps(v200, v200, 0)),
                         _mm_shuffle_ps(v200, v200, 170));
                v204 = _mm_mul_ps(v201, v201);
                v205 = _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v204, v204, 85), _mm_shuffle_ps(v204, v204, 0)),
                         _mm_shuffle_ps(v204, v204, 170));
                v206 = _mm_mul_ps(v202, v202);
                v207 = _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v206, v206, 85), _mm_shuffle_ps(v206, v206, 0)),
                         _mm_shuffle_ps(v206, v206, 170));
                v208 = _mm_mul_ps(_mm_mul_ps(_mm_rsqrt_ps(v203), v199), v190);
                v209 = _mm_mul_ps(_mm_mul_ps(_mm_rsqrt_ps(v205), v201), *v188);
                v210 = _mm_mul_ps(_mm_mul_ps(_mm_rsqrt_ps(v207), v202), *v189);
                v211 = fmin(
                         fmin(
                           (float)(COERCE_FLOAT(_mm_shuffle_ps(v208, v208, 85))
                                 + COERCE_FLOAT(_mm_shuffle_ps(v208, v208, 0)))
                         + COERCE_FLOAT(_mm_shuffle_ps(v208, v208, 170)),
                           (float)(COERCE_FLOAT(_mm_shuffle_ps(v209, v209, 85))
                                 + COERCE_FLOAT(_mm_shuffle_ps(v209, v209, 0)))
                         + COERCE_FLOAT(_mm_shuffle_ps(v209, v209, 170))),
                         fmin(
                           (float)(COERCE_FLOAT(_mm_shuffle_ps(v210, v210, 85))
                                 + COERCE_FLOAT(_mm_shuffle_ps(v210, v210, 0)))
                         + COERCE_FLOAT(_mm_shuffle_ps(v210, v210, 170)),
                           0.0))
                     - COERCE_FLOAT(_mm_shuffle_ps((__m128)LODWORD(v187[3].m_vertex), (__m128)LODWORD(v187[3].m_vertex), 0));
                if ( v211 > v185 )
                {
                  v100 = (hkcdWingedEdge::Triangle *)&v187[-1].m_neighbour;
                  v185 = v211;
                }
                v187 += 4;
                --v186;
              }
              while ( v186 >= 0 );
              v165 = (__m128)_xmm;
            }
            v212 = &v100->m_edge[2].m_vertex->m_position.m_quad;
            v213 = &v100->m_edge[0].m_vertex->m_position.m_quad;
            v214 = &v100->m_edge[1].m_vertex->m_position.m_quad;
            v215 = _mm_sub_ps(*v212, aabbOut.m_quad);
            v216 = _mm_sub_ps(*v214, aabbOut.m_quad);
            v217 = _mm_sub_ps(*v212, *v213);
            v218 = _mm_sub_ps(*v214, *v213);
            v219 = _mm_sub_ps(*v213, aabbOut.m_quad);
            v220 = _mm_sub_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v217, v217, 201), v218),
                     _mm_mul_ps(_mm_shuffle_ps(v218, v218, 201), v217));
            v221 = _mm_shuffle_ps(v220, v220, 201);
            v222 = _mm_shuffle_ps(v221, v221, 210);
            v223 = _mm_mul_ps(
                     _mm_sub_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v215, v215, 201), v222),
                       _mm_mul_ps(_mm_shuffle_ps(v215, v215, 210), v221)),
                     v216);
            v224 = _mm_mul_ps(
                     _mm_sub_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v219, v219, 201), v222),
                       _mm_mul_ps(_mm_shuffle_ps(v219, v219, 210), v221)),
                     v215);
            v225 = _mm_sub_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v216, v216, 201), v222),
                     _mm_mul_ps(_mm_shuffle_ps(v216, v216, 210), v221));
            v226 = _mm_unpacklo_ps(v223, v224);
            v227 = _mm_mul_ps(v225, v219);
            v228 = _mm_movelh_ps(v226, v227);
            v229 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(_mm_movehl_ps(v228, v226), v227, 212), v228),
                     _mm_shuffle_ps(_mm_unpackhi_ps(v223, v224), v227, 228));
            v230 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v229, v229, 85), _mm_shuffle_ps(v229, v229, 0)),
                     _mm_shuffle_ps(v229, v229, 170));
            v231 = _mm_rcp_ps(v230);
            v184 = _mm_mul_ps(
                     _mm_andnot_ps(
                       _mm_cmpeqps(v230, (__m128)0i64),
                       _mm_mul_ps(_mm_sub_ps(v165, _mm_mul_ps(v231, v230)), v231)),
                     v229);
          }
          v232 = &v100->m_edge[1].m_vertex->m_position.m_quad;
          v233 = (hkcdVertex *)v100->m_edge[0].m_vertex;
          v234 = v100->m_edge[2].m_vertex;
          v235 = v306.m_pointsAinA.m_storage;
          output->m_pointAinA.m_quad = _mm_add_ps(
                                         _mm_add_ps(
                                           _mm_mul_ps(_mm_shuffle_ps(v184, v184, 0), v233[1].m_quad),
                                           _mm_mul_ps(_mm_shuffle_ps(v184, v184, 85), v232[1])),
                                         _mm_mul_ps(_mm_shuffle_ps(v184, v184, 170), v234->m_pointAinA.m_quad));
          *v235 = (hkcdVertex)v233[1].m_quad;
          *v306.m_pointsBinA.m_storage = v233[2];
          v306.m_pointsAinA.m_storage[1].m_quad = v232[1];
          v236.m_quad = v232[2];
          v73 = &output->m_normalInA;
          v306.m_pointsBinA.m_storage[1] = (hkcdVertex)v236.m_quad;
          v306.m_pointsAinA.m_storage[2] = v234->m_pointAinA;
          v306.m_pointsBinA.m_storage[2] = v234->m_pointBinX;
          output->m_normalInA.m_quad = _mm_xor_ps(
                                         (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                                         v100->m_normal.m_quad);
          output->m_distance.m_real = _mm_sub_ps(
                                        (__m128)0i64,
                                        _mm_shuffle_ps(
                                          (__m128)LODWORD(v100->m_distanceToOrigin),
                                          (__m128)LODWORD(v100->m_distanceToOrigin),
                                          0));
          goto LABEL_139;
        }
      }
      v140 = 1;
      while ( 1 )
      {
        if ( !v139 )
          goto LABEL_108;
        v141 = *(&v326 + v138);
        v142 = v140 >= (signed int)v130 ? v326 : v327[v138];
        *(_QWORD *)(v141 + 40) = v141;
        *(_QWORD *)(v141 + 72) = v141;
        *(_QWORD *)(v141 + 104) = v141;
        *(_QWORD *)(v141 + 24) = v141 + 48;
        *(_QWORD *)(v141 + 56) = v141 + 80;
        *(_QWORD *)(v141 + 88) = v141 + 16;
        v143 = &v139->m_vertex->m_position.m_quad;
        v144 = (__m128 *)v139->m_next->m_vertex;
        *(_QWORD *)(v141 + 48) = v139->m_vertex;
        *(_QWORD *)(v141 + 80) = v105;
        *(_QWORD *)(v141 + 16) = v144;
        v139->m_neighbour = (hkcdWingedEdge::Edge *)(v141 + 16);
        *(_QWORD *)(v141 + 32) = v139;
        *(_QWORD *)(v142 + 64) = v141 + 80;
        *(_QWORD *)(v141 + 96) = v142 + 48;
        v145 = _mm_sub_ps(*v144, *v143);
        v146 = _mm_sub_ps(*v143, v105->m_quad);
        v147 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v146, v146, 201), v145),
                 _mm_mul_ps(_mm_shuffle_ps(v145, v145, 201), v146));
        v148 = _mm_shuffle_ps(v147, v147, 201);
        v149 = _mm_mul_ps(v148, v148);
        if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v149, v149, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v149, v149, 0)))
                   + COERCE_FLOAT(_mm_shuffle_ps(v149, v149, 170))) <= 0.0 )
          break;
        v17 = 0;
        ++v138;
        ++v140;
        v150 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v149, v149, 85), _mm_shuffle_ps(v149, v149, 0)),
                 _mm_shuffle_ps(v149, v149, 170));
        v151 = _mm_rsqrt_ps(v150);
        v152 = _mm_mul_ps(
                 v148,
                 _mm_andnot_ps(
                   _mm_cmpleps(v150, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v151, v150), v151)),
                     _mm_mul_ps(*(__m128 *)_xmm, v151))));
        v153 = _mm_mul_ps(*v144, v152);
        *(float *)(v141 + 112) = (float)(COERCE_FLOAT(_mm_shuffle_ps(v153, v153, 85))
                                       + COERCE_FLOAT(_mm_shuffle_ps(v153, v153, 0)))
                               + COERCE_FLOAT(_mm_shuffle_ps(v153, v153, 170));
        *(__m128 *)v141 = v152;
        v154 = v139->m_next;
        v139 = v154->m_vertex->m_referee.m_storage;
        v154->m_vertex->m_referee.m_storage = 0i64;
        if ( v138 >= v130 )
        {
          v94 = v328.m_numTriangles.m_storage;
          v137 = v313;
          goto LABEL_97;
        }
      }
      v17 = 0;
LABEL_108:
      v18 = v306.m_simplex.m_storage;
LABEL_109:
      if ( ++v306.m_backupTries.m_storage == 1 )
      {
        v11 = 1;
        goto LABEL_17;
      }
      if ( v306.m_backupTries.m_storage >= 20 )
      {
        v255.m_quad = (__m128)xmmword_141A712F0;
        v256 = transform.m_quad;
        v257 = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
        v258 = ::direction.m_quad;
        v259 = stru_141A71280.m_quad;
        v260 = _mm_mul_ps(g_vectorfConstants[0], g_vectorfConstants[0]);
        v261.m_quad = 0i64;
        v262 = (__m128)_mm_shuffle_epi32(v257, 0);
        v263 = 0i64;
        v264 = _mm_mul_ps(
                 g_vectorfConstants[0],
                 _mm_rsqrt_ps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v260, v260, 85), _mm_shuffle_ps(v260, v260, 0)),
                     _mm_shuffle_ps(v260, v260, 170))));
        v265 = query.m_quad;
        while ( 1 )
        {
          v305.m_quad = v265;
          v266 = 4i64;
          do
          {
            v267 = v330->vfptr;
            v310 = _mm_xor_ps(v256, v262);
            v267->getSupportingVertices(
              v330,
              v331,
              (hkVector4f *)&v310,
              v332,
              aTb,
              (hkcdVertex *)&v312,
              (hkcdVertex *)&v309,
              (hkVector4f *)&v311);
            v268 = _mm_mul_ps(_mm_sub_ps(v312, v311.m_real), v256);
            v269 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v268, v268, 85), _mm_shuffle_ps(v268, v268, 0)),
                     _mm_shuffle_ps(v268, v268, 170));
            if ( v269.m128_f32[0] > COERCE_FLOAT(_mm_shuffle_ps(v255.m_quad, v255.m_quad, 255)) )
            {
              v263 = v309.m_real;
              v255.m_quad = _mm_shuffle_ps(v256, _mm_unpackhi_ps(v256, v269), 196);
              v261.m_quad = v312;
            }
            v256 = v258;
            v258 = v259;
            v259 = v264;
            --v266;
          }
          while ( v266 );
          if ( v17 >= 20 )
            break;
          v270 = _mm_shuffle_ps(v255.m_quad, _mm_unpackhi_ps(v255.m_quad, (__m128)0i64), 196);
          v271 = _mm_shuffle_ps(v270, v270, 241);
          v272 = _mm_shuffle_ps(v270, v270, 206);
          v273 = _mm_mul_ps(v271, v271);
          v274 = _mm_mul_ps(v272, v272);
          v275 = _mm_cmpltps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v273, v273, 85), _mm_shuffle_ps(v273, v273, 0)),
                     _mm_shuffle_ps(v273, v273, 170)),
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v274, v274, 85), _mm_shuffle_ps(v274, v274, 0)),
                     _mm_shuffle_ps(v274, v274, 170)));
          v276 = _mm_xor_ps(_mm_or_ps(_mm_andnot_ps(v275, v271), _mm_and_ps(v272, v275)), (__m128)v257);
          v277 = _mm_mul_ps(v276, v276);
          v278 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v277, v277, 85), _mm_shuffle_ps(v277, v277, 0)),
                   _mm_shuffle_ps(v277, v277, 170));
          v279 = _mm_rsqrt_ps(v278);
          v280 = _mm_mul_ps(
                   v276,
                   _mm_andnot_ps(
                     _mm_cmpleps(v278, (__m128)0i64),
                     _mm_mul_ps(
                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v279, v278), v279)),
                       _mm_mul_ps(*(__m128 *)_xmm, v279))));
          v281 = _mm_mul_ps(_mm_shuffle_ps(v255.m_quad, v255.m_quad, 201), v280);
          v282 = _mm_shuffle_ps(v280, v280, 201);
          v283 = _mm_mul_ps(v280, v305.m_quad);
          v284 = _mm_add_ps(v283, v255.m_quad);
          v285 = _mm_sub_ps(_mm_mul_ps(v282, v255.m_quad), v281);
          v286 = _mm_mul_ps(v284, v284);
          v287 = _mm_mul_ps(_mm_shuffle_ps(v285, v285, 201), v305.m_quad);
          v288 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v286, v286, 85), _mm_shuffle_ps(v286, v286, 0)),
                   _mm_shuffle_ps(v286, v286, 170));
          v289 = _mm_rsqrt_ps(v288);
          ++v17;
          v265 = _mm_mul_ps(v305.m_quad, (__m128)xmmword_141A711B0);
          v290 = _mm_andnot_ps(
                   _mm_cmpleps(v288, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v289, v288), v289)),
                     _mm_mul_ps(*(__m128 *)_xmm, v289)));
          v256 = _mm_mul_ps(v284, v290);
          v264 = _mm_mul_ps(_mm_sub_ps(v255.m_quad, v287), v290);
          v291 = _mm_sub_ps(v255.m_quad, v283);
          v259 = _mm_mul_ps(_mm_add_ps(v287, v255.m_quad), v290);
          v258 = _mm_mul_ps(v291, v290);
        }
        v160 = 2;
        v329->m_verticesA[0].0 = (hkVector4f)v261.m_quad;
        v329->m_verticesBinA[0].m_quad = v263;
        output->m_pointAinA = (hkVector4f)v261.m_quad;
        output->m_normalInA = (hkVector4f)v255.m_quad;
        v73 = &output->m_normalInA;
        output->m_distance.m_real = _mm_shuffle_ps(v255.m_quad, v255.m_quad, 255);
        dimA->m_storage = 1;
        dimB->m_storage = 1;
        goto LABEL_155;
      }
      v307.m_quad.m128_i32[3] = 0;
      v11 = 0;
      v306.m_simplexSize.m_storage = 0;
      v159 = (12345 - 1043968403 * v306.m_backupTries.m_storage) & 0x7FFFFFFF;
      v307.m_quad.m128_f32[0] = (float)((float)((float)v159 * 4.6566129e-10) - 0.000099999997) * 0.00019999999;
      v307.m_quad.m128_f32[1] = (float)((float)((float)v159 * 4.6566129e-10) - 0.000099999997) * 0.00019999999;
      v307.m_quad.m128_f32[2] = (float)((float)((float)v159 * 4.6566129e-10) - 0.000099999997) * 0.00019999999;
      v307.m_quad = _mm_add_ps(v307.m_quad, v306.m_aTb.m_translation.m_quad);
      v306.m_aTb.m_translation = (hkVector4f)v307.m_quad;
      goto LABEL_18;
    }
    if ( v28 >= 0 )
      goto LABEL_109;
    v306.m_simplexSize.m_storage = 0;
  }
  v292 = direction.m_quad;
  v293 = _mm_mul_ps(v306.m_simplex.m_storage->m_quad, v306.m_simplex.m_storage->m_quad);
  v73 = &output->m_normalInA;
  output->m_pointAinA = (hkVector4f)result.m_pointAinA;
  v294 = _mm_add_ps(
           _mm_add_ps(_mm_shuffle_ps(v293, v293, 85), _mm_shuffle_ps(v293, v293, 0)),
           _mm_shuffle_ps(v293, v293, 170));
  v295 = _mm_mul_ps(v292, v292);
  v296 = _mm_rsqrt_ps(v294);
  v297 = _mm_add_ps(
           _mm_add_ps(_mm_shuffle_ps(v295, v295, 85), _mm_shuffle_ps(v295, v295, 0)),
           _mm_shuffle_ps(v295, v295, 170));
  v298 = _mm_rsqrt_ps(v297);
  output->m_normalInA.m_quad = _mm_mul_ps(
                                 v292,
                                 _mm_andnot_ps(
                                   _mm_cmpleps(v297, (__m128)0i64),
                                   _mm_mul_ps(
                                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v298, v297), v298)),
                                     _mm_mul_ps(v298, *(__m128 *)_xmm))));
  output->m_distance.m_real = _mm_andnot_ps(
                                _mm_cmpleps(v294, (__m128)0i64),
                                _mm_mul_ps(
                                  _mm_mul_ps(
                                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v296, v294), v296)),
                                    _mm_mul_ps(v296, *(__m128 *)_xmm)),
                                  v294));
LABEL_138:
  v160 = 1;
LABEL_139:
  dimA->m_storage = 3;
  dimB->m_storage = 3;
  v299 = v329->m_verticesA[2].m_quad.m128_i16[6];
  if ( v329->m_verticesA[1].m_quad.m128_i16[6] == v299 || v329->m_verticesA[0].m_quad.m128_i16[6] == v299 )
    --dimA->m_storage;
  v300 = dimA->m_storage;
  if ( dimA->m_storage >= 2 && v329->m_verticesA[0].m_quad.m128_i16[6] == v329->m_verticesA[1].m_quad.m128_i16[6] )
  {
    dimA->m_storage = v300 - 1;
    v329->m_verticesA[0] = (hkcdVertex)*((_OWORD *)&v329->m_checkTriangleDots + v300 - 1 + 2i64);
  }
  v301 = v329->m_verticesBinA[2].m_quad.m128_i16[6];
  if ( v329->m_verticesBinA[1].m_quad.m128_i16[6] == v301 || v329->m_verticesBinA[0].m_quad.m128_i16[6] == v301 )
    --dimB->m_storage;
  v302 = dimB->m_storage;
  if ( dimB->m_storage >= 2 && v329->m_verticesBinA[0].m_quad.m128_i16[6] == v329->m_verticesBinA[1].m_quad.m128_i16[6] )
  {
    dimB->m_storage = v302 - 1;
    v329->m_verticesBinA[0] = (hkcdVertex)*((_OWORD *)&v329->m_checkTriangleDots + v302 - 1 + 6i64);
  }
  if ( dimA->m_storage + dimB->m_storage > 4 )
  {
    if ( dimA->m_storage <= dimB->m_storage )
    {
      dimB->m_storage = 3;
      dimA->m_storage = 1;
    }
    else
    {
      dimA->m_storage = 3;
      dimB->m_storage = 1;
    }
  }
LABEL_155:
  v303 = v160;
  *supportOut = (hkVector4f)v73->m_quad;
  return v303;
}),
                                  v294));
LABEL_138:
  v160 = 1;
LABEL_139:
  dimA->m_storage = 3;
  dimB->m_storage = 3;
  v299 = v329->m_verticesA[2].m_quad.m128_i16[6];
  if ( v329->m_verticesA[1].m_quad.m128_i16[6] == v299 || v329->m_verticesA[0].m_quad.m128_i16[6] == v299 )
    --dimA->m_storage;
  v300 = dimA->m_storage;
  if ( dimA->m_storage >= 2 && v329->m_verticesA[0

