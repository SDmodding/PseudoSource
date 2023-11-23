// File Line: 36
// RVA: 0x130CDA0
__int64 __fastcall hkcdGskBase::processEdgeTriangle(
        hkcdGskBase *this,
        hkVector4f *vertexA,
        hkVector4f *vertexB,
        unsigned int comingFromEdgeEdge,
        hkVector4f *supportOut)
{
  __m128 v5; // xmm10
  __m128 v6; // xmm6
  __m128 v7; // xmm9
  __m128 v8; // xmm7
  __m128 v9; // xmm14
  __m128 v10; // xmm13
  __m128 v11; // xmm2
  __m128 v12; // xmm2
  __m128 v13; // xmm1
  __m128 v14; // xmm3
  __m128 v15; // xmm1
  __m128 v16; // xmm2
  __m128 v17; // xmm1
  __m128 v18; // xmm4
  __m128 v19; // xmm1
  __m128 v20; // xmm0
  __m128 v21; // xmm2
  __m128 v22; // xmm1
  __m128 v23; // xmm2
  __m128 v24; // xmm0
  __m128 v25; // xmm3
  __m128 v26; // xmm9
  __m128 v27; // xmm10
  __m128 v28; // xmm4
  __m128 v29; // xmm1
  __m128 v30; // xmm4
  __m128 v31; // xmm3
  __m128 v32; // xmm4
  __m128 v33; // xmm5
  __m128 v34; // xmm2
  __m128 v35; // xmm1
  __m128 v36; // xmm5
  __m128 v37; // xmm9
  __m128 v38; // xmm2
  __int64 result; // rax
  __m128 v40; // xmm3
  __m128 v41; // xmm2
  __m128 v42; // xmm12
  __m128 v43; // xmm4
  __m128 v44; // xmm5
  __m128 v45; // xmm12
  __m128 v46; // xmm8
  __m128 v47; // xmm6
  __m128 v48; // xmm7
  __m128 v49; // xmm1
  __m128 v50; // xmm11
  __m128 v51; // xmm2
  __m128 v52; // xmm3
  __m128 v53; // xmm11
  __m128 v54; // xmm8
  __m128 v55; // xmm8
  __m128 v56; // xmm6
  __m128 v57; // xmm6
  __m128 v58; // xmm1
  __m128 v59; // xmm7
  __m128 v60; // xmm7
  __m128 v61; // xmm2
  hkVector4f v62; // xmm8
  int v63; // r9d
  __m128 v64; // xmm2
  __m128 v65; // xmm1
  __m128 v66; // xmm7
  __m128 v67; // xmm15
  __m128 v68; // xmm1
  __m128 v69; // xmm12
  __m128 v70; // xmm10
  __m128 v71; // xmm1
  __m128 v72; // xmm9
  __m128 v73; // xmm1
  __m128 v74; // xmm8
  __m128 v75; // xmm2
  __m128 v76; // xmm1
  __m128 v77; // xmm6
  __m128 v78; // xmm4
  __m128 v79; // xmm1
  __m128 v80; // xmm3
  __m128 v81; // xmm1
  __m128 v82; // xmm5
  __m128 v83; // xmm1
  __m128 v84; // xmm7
  __m128 v85; // xmm6
  __m128 v86; // xmm1
  __m128 v87; // xmm0
  __m128 v88; // xmm3
  __m128 v89; // xmm3
  __m128 v90; // xmm0
  __m128 v91; // xmm3
  __m128 v92; // xmm10
  __m128 v93; // xmm0
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
  __m128 v117; // xmm0
  __m128 v118; // xmm3
  __m128 v119; // xmm0
  __m128 v120; // xmm2
  __m128 v121; // xmm9
  __m128 v122; // xmm1
  __m128 v123; // xmm3
  __m128 v124; // xmm4
  __m128 v125; // xmm4
  __m128 v126; // xmm0
  __m128 v127; // xmm1
  __m128 v128; // xmm0
  __m128 m_quad; // xmm9
  __m128 v130; // xmm12
  hkVector4f v131; // xmm10
  __m128 v132; // xmm11
  __m128 v133; // xmm1
  __m128 v134; // xmm2
  __m128 v135; // xmm3
  __m128 v136; // xmm4
  __m128 v137; // xmm1
  __m128 v138; // xmm0
  __m128 v139; // xmm2
  __m128 v140; // xmm1
  __m128 v141; // xmm3
  __m128 v142; // xmm0
  __m128 v143; // xmm7
  __m128 v144; // xmm4
  __m128 v145; // xmm5
  __m128 v146; // xmm0
  __m128 v147; // xmm6
  __m128 v148; // xmm6
  __m128 v149; // xmm1
  __m128 v150; // xmm6
  __m128 v151; // xmm3
  __m128 v152; // xmm0
  __m128 v153; // xmm2
  __m128 v154; // xmm7
  __m128 v155; // xmm1
  __m128 v156; // xmm3
  __m128 v157; // xmm1
  __m128 v158; // xmm7
  __m128 v159; // xmm2
  __m128 v160; // xmm2
  __m128 v161; // xmm3
  __m128 v162; // xmm5
  __m128 v163; // xmm8
  __m128 v164; // xmm4
  __m128 v165; // xmm7
  __m128 v166; // xmm1
  __m128 v167; // xmm9
  __m128 v168; // xmm2
  __m128 v169; // xmm6
  __m128 v170; // xmm6
  __m128 v171; // xmm9
  __m128 v172; // xmm7
  __m128 v173; // xmm9
  __m128 v174; // xmm7
  __m128 v175; // xmm8
  __m128 v176; // xmm1
  __m128 v177; // xmm8
  __m128 v178; // xmm2
  hkVector4f v179; // xmm9
  int v180; // eax
  float v181; // xmm1_4
  float v182; // xmm10_4
  float v183; // xmm1_4
  float v184; // xmm10_4
  float v185; // xmm1_4
  float v186; // xmm10_4
  __m128 v187; // [rsp+0h] [rbp-E8h]
  __m128 v188; // [rsp+0h] [rbp-E8h]
  __m128 v189; // [rsp+10h] [rbp-D8h]
  __m128 v190; // [rsp+20h] [rbp-C8h]

  if ( !comingFromEdgeEdge )
  {
    m_quad = vertexB->m_quad;
    v130 = vertexA[1].m_quad;
    v131.m_quad = (__m128)this->m_checkTriangleDots;
    v132 = _mm_sub_ps(v130, vertexB->m_quad);
    v133 = _mm_mul_ps(_mm_sub_ps(vertexA->m_quad, vertexB->m_quad), supportOut->m_quad);
    v134 = _mm_mul_ps(supportOut->m_quad, v132);
    v135 = _mm_add_ps(
             _mm_add_ps(_mm_shuffle_ps(v133, v133, 85), _mm_shuffle_ps(v133, v133, 0)),
             _mm_shuffle_ps(v133, v133, 170));
    v136 = _mm_add_ps(
             _mm_add_ps(_mm_shuffle_ps(v134, v134, 85), _mm_shuffle_ps(v134, v134, 0)),
             _mm_shuffle_ps(v134, v134, 170));
    if ( (float)(v136.m128_f32[0] * v135.m128_f32[0]) < 0.0 )
    {
      v137 = _mm_sub_ps(v135, v136);
      v138 = _mm_rcp_ps(v137);
      v139 = _mm_sub_ps((__m128)_xmm, _mm_mul_ps(v137, v138));
      v140 = _mm_sub_ps(vertexB[1].m_quad, m_quad);
      v141 = _mm_add_ps(
               _mm_mul_ps(_mm_sub_ps(v130, vertexA->m_quad), _mm_mul_ps(_mm_mul_ps(v139, v138), v135)),
               vertexA->m_quad);
      v142 = vertexB[2].m_quad;
      v143 = _mm_sub_ps(vertexB[1].m_quad, v141);
      v144 = _mm_sub_ps(m_quad, v141);
      v145 = _mm_sub_ps(v142, v141);
      v146 = _mm_sub_ps(v142, m_quad);
      v147 = _mm_sub_ps(
               _mm_mul_ps(_mm_shuffle_ps(v146, v146, 201), v140),
               _mm_mul_ps(_mm_shuffle_ps(v140, v140, 201), v146));
      v148 = _mm_shuffle_ps(v147, v147, 201);
      v149 = _mm_shuffle_ps(v148, v148, 210);
      v150 = _mm_shuffle_ps(v148, v148, 201);
      v151 = _mm_mul_ps(
               _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v145, v145, 201), v149),
                 _mm_mul_ps(_mm_shuffle_ps(v145, v145, 210), v150)),
               v143);
      v152 = _mm_shuffle_ps(v143, v143, 210);
      v153 = _mm_mul_ps(
               _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v144, v144, 201), v149),
                 _mm_mul_ps(_mm_shuffle_ps(v144, v144, 210), v150)),
               v145);
      v154 = _mm_mul_ps(_mm_shuffle_ps(v143, v143, 201), v149);
      v155 = v151;
      v156 = _mm_unpackhi_ps(v151, v153);
      v157 = _mm_unpacklo_ps(v155, v153);
      v158 = _mm_mul_ps(_mm_sub_ps(v154, _mm_mul_ps(v152, v150)), v144);
      v159 = _mm_movelh_ps(v157, v158);
      if ( (_mm_movemask_ps(
              _mm_cmplt_ps(
                (__m128)0i64,
                _mm_add_ps(
                  _mm_shuffle_ps(v156, v158, 228),
                  _mm_add_ps(v159, _mm_shuffle_ps(_mm_movehl_ps(v159, v157), v158, 212))))) & 7) == 7 )
        return 1i64;
    }
    v160 = vertexB[1].m_quad;
    v161 = vertexB[2].m_quad;
    v162 = _mm_sub_ps(m_quad, v161);
    v163 = _mm_sub_ps(v160, m_quad);
    v164 = _mm_sub_ps(v161, v160);
    v165 = _mm_shuffle_ps(v162, v162, 201);
    v166 = _mm_sub_ps(v130, v160);
    v167 = _mm_shuffle_ps(v164, v164, 201);
    v168 = _mm_sub_ps(v130, v161);
    v169 = _mm_sub_ps(_mm_mul_ps(v165, v164), _mm_mul_ps(v167, v162));
    v170 = _mm_shuffle_ps(v169, v169, 201);
    v171 = _mm_sub_ps(_mm_mul_ps(v167, v166), _mm_mul_ps(_mm_shuffle_ps(v166, v166, 201), v164));
    v172 = _mm_sub_ps(_mm_mul_ps(v165, v168), _mm_mul_ps(_mm_shuffle_ps(v168, v168, 201), v162));
    v173 = _mm_mul_ps(_mm_shuffle_ps(v171, v171, 201), v170);
    v174 = _mm_mul_ps(_mm_shuffle_ps(v172, v172, 201), v170);
    v175 = _mm_sub_ps(
             _mm_mul_ps(_mm_shuffle_ps(v163, v163, 201), v132),
             _mm_mul_ps(_mm_shuffle_ps(v132, v132, 201), v163));
    v176 = _mm_unpacklo_ps(v173, v174);
    v177 = _mm_mul_ps(_mm_shuffle_ps(v175, v175, 201), v170);
    v178 = _mm_movelh_ps(v176, v177);
    v179.m_quad = _mm_add_ps(
                    _mm_shuffle_ps(_mm_unpackhi_ps(v173, v174), v177, 228),
                    _mm_add_ps(v178, _mm_shuffle_ps(_mm_movehl_ps(v178, v176), v177, 212)));
    this->m_checkTriangleDots = (hkVector4f)v179.m_quad;
    v180 = _mm_movemask_ps(_mm_cmplt_ps(v179.m_quad, (__m128)0i64)) & 7;
    if ( v180 == 7 )
    {
      *vertexA = (hkVector4f)v130;
      return 0i64;
    }
    if ( v180 == 6 )
      goto LABEL_26;
    if ( v180 != 5 )
    {
      switch ( v180 )
      {
        case 3:
          return 2i64;
        case 1:
          v181 = _mm_shuffle_ps(v131.m_quad, v131.m_quad, 85).m128_f32[0];
          v182 = _mm_shuffle_ps(v131.m_quad, v131.m_quad, 170).m128_f32[0];
          if ( (float)((float)(_mm_shuffle_ps(v179.m_quad, v179.m_quad, 85).m128_f32[0] - v181) * v182) <= (float)((float)(_mm_shuffle_ps(v179.m_quad, v179.m_quad, 170).m128_f32[0] - v182) * v181) )
          {
            result = 2i64;
            vertexB[1] = (hkVector4f)vertexB[2].m_quad;
            return result;
          }
          return 2i64;
        case 2:
          v183 = _mm_shuffle_ps(v131.m_quad, v131.m_quad, 170).m128_f32[0];
          v184 = _mm_shuffle_ps(v131.m_quad, v131.m_quad, 0).m128_f32[0];
          if ( (float)((float)(_mm_shuffle_ps(v179.m_quad, v179.m_quad, 170).m128_f32[0] - v183) * v184) > (float)((float)(_mm_shuffle_ps(v179.m_quad, v179.m_quad, 0).m128_f32[0] - v184) * v183) )
          {
LABEL_26:
            result = 2i64;
            *vertexB = (hkVector4f)vertexB[2].m_quad;
            return result;
          }
          return 2i64;
      }
      if ( v180 != 4 )
        goto LABEL_26;
      v185 = _mm_shuffle_ps(v131.m_quad, v131.m_quad, 0).m128_f32[0];
      v186 = _mm_shuffle_ps(v131.m_quad, v131.m_quad, 85).m128_f32[0];
      if ( (float)((float)(_mm_shuffle_ps(v179.m_quad, v179.m_quad, 0).m128_f32[0] - v185) * v186) <= (float)((float)(_mm_shuffle_ps(v179.m_quad, v179.m_quad, 85).m128_f32[0] - v186) * v185) )
        goto LABEL_26;
    }
    vertexB[1] = (hkVector4f)vertexB[2].m_quad;
    return 2i64;
  }
  v5 = vertexB->m_quad;
  v6 = vertexA->m_quad;
  v7 = vertexB[1].m_quad;
  v8 = vertexA[1].m_quad;
  v9 = vertexB[2].m_quad;
  v190 = vertexA->m_quad;
  v10 = _mm_sub_ps(v7, v9);
  v189 = _mm_sub_ps(vertexB->m_quad, v9);
  v187 = v8;
  v11 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v189, v189, 201), v10), _mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), v189));
  v12 = _mm_shuffle_ps(v11, v11, 201);
  v13 = _mm_mul_ps(_mm_sub_ps(vertexA->m_quad, vertexB->m_quad), v12);
  v14 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)), _mm_shuffle_ps(v13, v13, 170));
  v15 = _mm_mul_ps(_mm_sub_ps(v8, vertexB->m_quad), v12);
  v16 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)), _mm_shuffle_ps(v15, v15, 170));
  v17 = _mm_mul_ps(v14, v14);
  v18 = _mm_mul_ps(v16, v16);
  if ( !_mm_movemask_ps(_mm_mul_ps(v16, v14)) )
  {
    v40 = vertexB[2].m_quad;
    v41 = vertexB[1].m_quad;
    v42 = _mm_cmplt_ps(v17, v18);
    v43 = _mm_sub_ps(v40, v41);
    v44 = _mm_sub_ps(v5, v40);
    v45 = _mm_or_ps(_mm_and_ps(v42, v6), _mm_andnot_ps(v42, v8));
    v46 = _mm_shuffle_ps(v43, v43, 201);
    v47 = _mm_shuffle_ps(v44, v44, 201);
    v48 = _mm_sub_ps(v41, v5);
    v49 = _mm_sub_ps(v45, v41);
    v50 = _mm_sub_ps(_mm_mul_ps(v47, v43), _mm_mul_ps(v46, v44));
    v51 = _mm_sub_ps(v45, v40);
    v52 = _mm_sub_ps(v45, v5);
    v53 = _mm_shuffle_ps(v50, v50, 201);
    v54 = _mm_sub_ps(_mm_mul_ps(v46, v49), _mm_mul_ps(_mm_shuffle_ps(v49, v49, 201), v43));
    v55 = _mm_mul_ps(_mm_shuffle_ps(v54, v54, 201), v53);
    v56 = _mm_sub_ps(_mm_mul_ps(v47, v51), _mm_mul_ps(_mm_shuffle_ps(v51, v51, 201), v44));
    v57 = _mm_mul_ps(_mm_shuffle_ps(v56, v56, 201), v53);
    v58 = _mm_unpacklo_ps(v55, v57);
    v59 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v48, v48, 201), v52), _mm_mul_ps(_mm_shuffle_ps(v52, v52, 201), v48));
    v60 = _mm_mul_ps(_mm_shuffle_ps(v59, v59, 201), v53);
    v61 = _mm_movelh_ps(v58, v60);
    v62.m_quad = _mm_add_ps(
                   _mm_shuffle_ps(_mm_unpackhi_ps(v55, v57), v60, 228),
                   _mm_add_ps(v61, _mm_shuffle_ps(_mm_movehl_ps(v61, v58), v60, 212)));
    v63 = _mm_movemask_ps(_mm_cmplt_ps(v62.m_quad, (__m128)0i64)) & 7;
    if ( v63 == 7 )
    {
      v64 = _mm_mul_ps(_mm_sub_ps(this->m_verticesA[0].m_quad, this->m_verticesBinA[0].m_quad), v53);
      if ( _mm_movemask_ps(
             _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v64, v64, 85), _mm_shuffle_ps(v64, v64, 0)),
               _mm_shuffle_ps(v64, v64, 170))) )
      {
        v65 = vertexB->m_quad;
        *vertexB = (hkVector4f)v7;
        vertexB[1] = (hkVector4f)v65;
        v53 = _mm_xor_ps(v53, (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0));
        v62.m_quad = _mm_shuffle_ps(v62.m_quad, v62.m_quad, 225);
      }
    }
    this->m_checkTriangleDots = (hkVector4f)v62.m_quad;
    *supportOut = (hkVector4f)v53;
    if ( v63 == 7 )
    {
      *vertexA = (hkVector4f)v45;
      return 0i64;
    }
    v6 = v190;
    v8 = v187;
    goto LABEL_12;
  }
  v19 = _mm_sub_ps(v14, v16);
  v20 = _mm_rcp_ps(v19);
  v21 = _mm_sub_ps((__m128)_xmm, _mm_mul_ps(v19, v20));
  v22 = _mm_sub_ps(v7, v5);
  v23 = _mm_mul_ps(v21, v20);
  v24 = _mm_sub_ps(v9, v5);
  v25 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v8, v6), _mm_mul_ps(v23, v14)), v6);
  v26 = _mm_sub_ps(v7, v25);
  v27 = _mm_sub_ps(v5, v25);
  v28 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v24, v24, 201), v22), _mm_mul_ps(_mm_shuffle_ps(v22, v22, 201), v24));
  v29 = _mm_sub_ps(v9, v25);
  v30 = _mm_shuffle_ps(v28, v28, 201);
  v31 = _mm_shuffle_ps(v30, v30, 210);
  v32 = _mm_shuffle_ps(v30, v30, 201);
  v33 = _mm_mul_ps(
          _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v29, v29, 201), v31), _mm_mul_ps(_mm_shuffle_ps(v29, v29, 210), v32)),
          v26);
  v34 = _mm_mul_ps(
          _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v27, v27, 201), v31), _mm_mul_ps(_mm_shuffle_ps(v27, v27, 210), v32)),
          v29);
  v35 = _mm_unpacklo_ps(v33, v34);
  v36 = _mm_unpackhi_ps(v33, v34);
  v37 = _mm_mul_ps(
          _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v26, v26, 201), v31), _mm_mul_ps(_mm_shuffle_ps(v26, v26, 210), v32)),
          v27);
  v38 = _mm_movelh_ps(v35, v37);
  if ( (_mm_movemask_ps(
          _mm_cmplt_ps(
            (__m128)0i64,
            _mm_add_ps(
              _mm_shuffle_ps(v36, v37, 228),
              _mm_add_ps(v38, _mm_shuffle_ps(_mm_movehl_ps(v38, v35), v37, 212))))) & 7) != 7 )
  {
LABEL_12:
    v66 = _mm_sub_ps(v8, v6);
    v67 = _mm_sub_ps(v9, v6);
    v68 = _mm_mul_ps(v66, v10);
    v69 = _mm_mul_ps(v66, v66);
    v188 = v66;
    v70 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v68, v68, 85), _mm_shuffle_ps(v68, v68, 0)),
            _mm_shuffle_ps(v68, v68, 170));
    v71 = _mm_mul_ps(v67, v66);
    v72 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v71, v71, 85), _mm_shuffle_ps(v71, v71, 0)),
            _mm_shuffle_ps(v71, v71, 170));
    v73 = _mm_mul_ps(v67, v10);
    v74 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v73, v73, 85), _mm_shuffle_ps(v73, v73, 0)),
            _mm_shuffle_ps(v73, v73, 170));
    v75 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v69, v69, 85), _mm_shuffle_ps(v69, v69, 0)),
            _mm_shuffle_ps(v69, v69, 170));
    v76 = _mm_mul_ps(v10, v10);
    v77 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v76, v76, 85), _mm_shuffle_ps(v76, v76, 0)),
            _mm_shuffle_ps(v76, v76, 170));
    v78 = _mm_max_ps(_mm_sub_ps(_mm_mul_ps(v77, v75), _mm_mul_ps(v70, v70)), *(__m128 *)&epsilon);
    v79 = _mm_rcp_ps(v78);
    v80 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v79, v78)), v79);
    v81 = _mm_rcp_ps(v77);
    v82 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v81, v77)), v81);
    v83 = _mm_rcp_ps(v75);
    v84 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v83, v75)), v83);
    v85 = _mm_sub_ps(_mm_mul_ps(v77, v72), _mm_mul_ps(v74, v70));
    v86 = _mm_cmplt_ps(v85, v78);
    v87 = _mm_mul_ps(_mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_and_ps(v86, v85), _mm_andnot_ps(v86, v78))), v80);
    v88 = _mm_cmple_ps(v78, *(__m128 *)&epsilon);
    v89 = _mm_sub_ps(
            _mm_mul_ps(_mm_or_ps(_mm_andnot_ps(v88, v87), _mm_and_ps(v88, query.m_quad)), _mm_mul_ps(v70, v82)),
            _mm_mul_ps(v74, v82));
    v90 = _mm_cmplt_ps(v89, query.m_quad);
    v91 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_andnot_ps(v90, query.m_quad), _mm_and_ps(v90, v89)));
    v92 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v70, v84), v91), _mm_mul_ps(v72, v84));
    v93 = _mm_cmplt_ps(v92, query.m_quad);
    v94 = _mm_sub_ps(
            _mm_add_ps(
              _mm_mul_ps(
                _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_andnot_ps(v93, query.m_quad), _mm_and_ps(v93, v92))),
                v188),
              vertexA->m_quad),
            _mm_add_ps(_mm_mul_ps(v91, v10), vertexB[2].m_quad));
    v95 = _mm_mul_ps(v188, v189);
    v96 = _mm_mul_ps(v94, v94);
    v97 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v96, v96, 85), _mm_shuffle_ps(v96, v96, 0)),
            _mm_shuffle_ps(v96, v96, 170));
    v98 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v95, v95, 85), _mm_shuffle_ps(v95, v95, 0)),
            _mm_shuffle_ps(v95, v95, 170));
    v99 = v67;
    v100 = _mm_mul_ps(v67, v189);
    v101 = _mm_mul_ps(v99, v188);
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
    v114 = _mm_cmple_ps(v107, *(__m128 *)&epsilon);
    v115 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, v113), v112);
    v116 = _mm_sub_ps(_mm_mul_ps(v105, v102), _mm_mul_ps(v98, v103));
    v117 = _mm_cmplt_ps(v116, v107);
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
    v119 = _mm_cmplt_ps(v118, query.m_quad);
    v120 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v119, v118), _mm_andnot_ps(v119, query.m_quad)));
    v121 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v98, v115), v120), _mm_mul_ps(v115, v102));
    v122 = _mm_cmplt_ps(v121, query.m_quad);
    v123 = vertexB[2].m_quad;
    result = 2i64;
    v124 = _mm_sub_ps(
             _mm_add_ps(
               _mm_mul_ps(
                 _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v122, v121), _mm_andnot_ps(v122, query.m_quad))),
                 v188),
               vertexA->m_quad),
             _mm_add_ps(_mm_mul_ps(v120, v189), v123));
    v125 = _mm_mul_ps(v124, v124);
    v126 = _mm_cmplt_ps(
             _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v125, v125, 85), _mm_shuffle_ps(v125, v125, 0)),
               _mm_shuffle_ps(v125, v125, 170)),
             v97);
    v127 = _mm_and_ps(v126, vertexB->m_quad);
    v128 = _mm_andnot_ps(v126, vertexB[1].m_quad);
    vertexB[1] = (hkVector4f)v123;
    vertexB->m_quad = _mm_or_ps(v128, v127);
    return result;
  }
  return 1i64;
} vertexA->m_quad),
             _mm_add_ps(_mm_mul_ps(v120, v189), v123));
    v125 = _mm_mul_ps(v124, v124);
    v126 = _mm_cmplt_ps(
        

// File Line: 43
// RVA: 0x130B1C0
__int64 __fastcall hkcdGskBase::handlePenetration(
        hkcdGskBase *this,
        hkcdGskBase::ShapeInterface *shapeInterface,
        const void *shapeA,
        const void *shapeB,
        hkTransformf *aTb,
        hkPadSpu<int> *dimA,
        hkPadSpu<int> *dimB,
        hkcdGsk::GetClosestPointOutput *output,
        hkVector4f *supportOut)
{
  int m_storage; // eax
  int v11; // r10d
  __int64 v12; // rcx
  hkcdVertex v13; // xmm0
  hkcdVertex v14; // xmm1
  __m128 m_quad; // xmm1
  __m128 v16; // xmm0
  int v17; // r14d
  hkVector4f *p_from; // rbx
  __m128 v19; // xmm0
  __m128 v20; // xmm1
  __m128 v21; // xmm0
  __m128 v22; // xmm0
  __m128 v23; // xmm1
  __m128 v24; // xmm1
  hkVector4f v25; // xmm0
  hkVector4f v26; // xmm1
  hkVector4f v27; // xmm1
  int v28; // edi
  int v29; // r10d
  int v30; // r10d
  int v31; // r10d
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
  hkVector4f *p_m_normalInA; // r8
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
  int v94; // r8d
  int v95; // edx
  bool v96; // sf
  int v97; // r8d
  float m_distanceToOrigin; // xmm0_4
  hkcdWingedEdge::Triangle *m_triangles; // rcx
  hkcdWingedEdge::Triangle *p_m_neighbour; // rdi
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
  int v125; // eax
  __m128 v126; // xmm1
  float v127; // xmm2_4
  float v128; // xmm2_4
  int v129; // edx
  __int64 v130; // r12
  int v131; // r9d
  __int64 v132; // r10
  __int64 i; // rcx
  __int64 v134; // rdx
  __int64 *v135; // rcx
  __int64 v136; // rax
  hkcdWingedEdge::Edge *v137; // r9
  __int64 v138; // rsi
  hkcdWingedEdge::Edge *v139; // rbx
  int v140; // r15d
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
  hkcdWingedEdge::Edge *m_next; // rax
  int v155; // ecx
  hkcdWingedEdge::Triangle::TriangleState *p_m_state; // rax
  int v157; // ecx
  hkPadSpu<hkcdWingedEdge::Edge *> *p_m_referee; // rax
  unsigned int v159; // esi
  hkcdWingedEdge::Triangle::TriangleState v160; // eax
  float v161; // xmm0_4
  __m128 *p_m_quad; // rdx
  __m128 *v163; // rcx
  __m128 v164; // xmm8
  __m128 v165; // xmm6
  __m128 v166; // xmm4
  __m128 v167; // xmm0
  __m128 v168; // xmm1
  __m128 v169; // xmm7
  __m128 v170; // xmm6
  __m128 v171; // xmm5
  __m128 v172; // xmm5
  __m128 v173; // xmm1
  __m128 v174; // xmm5
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
  int v186; // r9d
  hkcdWingedEdge::Edge *m_edge; // r8
  __m128 *v188; // rcx
  __m128 *v189; // rdx
  __m128 v190; // xmm8
  __m128 v191; // xmm6
  __m128 v192; // xmm9
  __m128 v193; // xmm3
  __m128 v194; // xmm1
  __m128 v195; // xmm4
  __m128 v196; // xmm5
  __m128 v197; // xmm3
  __m128 v198; // xmm3
  __m128 v199; // xmm2
  __m128 v200; // xmm3
  __m128 v201; // xmm7
  __m128 v202; // xmm1
  __m128 v203; // xmm5
  __m128 v204; // xmm9
  __m128 v205; // xmm4
  __m128 v206; // xmm1
  __m128 v207; // xmm3
  __m128 v208; // xmm1
  __m128 v209; // xmm2
  __m128 v210; // xmm1
  __m128 v211; // xmm4
  __m128 v212; // xmm3
  float v213; // xmm5_4
  __m128 *v214; // rdx
  __m128 *v215; // rax
  __m128 *v216; // rcx
  __m128 v217; // xmm3
  __m128 v218; // xmm7
  __m128 v219; // xmm0
  __m128 v220; // xmm1
  __m128 v221; // xmm6
  __m128 v222; // xmm5
  __m128 v223; // xmm5
  __m128 v224; // xmm1
  __m128 v225; // xmm5
  __m128 v226; // xmm4
  __m128 v227; // xmm2
  __m128 v228; // xmm7
  __m128 v229; // xmm1
  __m128 v230; // xmm7
  __m128 v231; // xmm0
  __m128 v232; // xmm3
  __m128 v233; // xmm2
  __m128 v234; // xmm1
  hkcdWingedEdge::Vertex *m_vertex; // r8
  hkcdVertex *v236; // rcx
  hkcdWingedEdge::Vertex *v237; // r9
  hkcdVertex *v238; // rax
  hkcdVertex v239; // xmm1
  __m128 v240; // xmm0
  __m128 v241; // xmm1
  __m128 v242; // xmm4
  __m128 v243; // xmm7
  __m128 v244; // xmm6
  __m128 v245; // xmm5
  __m128 v246; // xmm5
  __m128 v247; // xmm1
  __m128 v248; // xmm5
  __m128 v249; // xmm3
  __m128 v250; // xmm2
  __m128 v251; // xmm7
  __m128 v252; // xmm1
  __m128 v253; // xmm7
  __m128 v254; // xmm0
  __m128 v255; // xmm5
  __m128 v256; // xmm3
  __m128 v257; // xmm2
  __m128 v258; // xmm4
  hkVector4f v259; // xmm8
  __m128 v260; // xmm9
  __m128i inserted; // xmm14
  __m128 v262; // xmm6
  __m128 v263; // xmm7
  __m128 v264; // xmm2
  hkVector4f v265; // xmm11
  __m128 v266; // xmm13
  __m128 m_real; // xmm12
  __m128 v268; // xmm10
  __m128 v269; // xmm0
  __int64 v270; // rbx
  hkcdGskBase::ShapeInterfaceVtbl *vfptr; // rax
  __m128 v272; // xmm1
  __m128 v273; // xmm2
  __m128 v274; // xmm5
  __m128 v275; // xmm4
  __m128 v276; // xmm5
  __m128 v277; // xmm1
  __m128 v278; // xmm2
  __m128 v279; // xmm3
  __m128 v280; // xmm7
  __m128 v281; // xmm1
  __m128 v282; // xmm4
  __m128 v283; // xmm2
  __m128 v284; // xmm7
  __m128 v285; // xmm0
  __m128 v286; // xmm4
  __m128 v287; // xmm7
  __m128 v288; // xmm9
  __m128 v289; // xmm4
  __m128 v290; // xmm1
  __m128 v291; // xmm4
  __m128 v292; // xmm2
  __m128 v293; // xmm1
  __m128 v294; // xmm3
  __m128 v295; // xmm6
  __m128 v296; // xmm8
  __m128 v297; // xmm1
  __m128 v298; // xmm10
  __m128 v299; // xmm1
  __m128 v300; // xmm9
  __m128 v301; // xmm4
  __m128 v302; // xmm3
  __int16 v303; // ax
  int v304; // ecx
  __int16 v305; // ax
  int v306; // ecx
  __int64 v307; // rax
  hkPadSpu<int> chainLength; // [rsp+40h] [rbp-C0h] BYREF
  hkVector4f v309; // [rsp+50h] [rbp-B0h] BYREF
  hkcdConvexPenetrationUtil v310; // [rsp+60h] [rbp-A0h] BYREF
  __m128 v311; // [rsp+110h] [rbp+10h]
  hkPadSpu<hkcdWingedEdge::Edge *> edgeChain; // [rsp+120h] [rbp+20h] BYREF
  hkSimdFloat32 v313; // [rsp+130h] [rbp+30h] BYREF
  __m128 v314; // [rsp+140h] [rbp+40h] BYREF
  hkSimdFloat32 v315; // [rsp+150h] [rbp+50h] BYREF
  __m128 v316; // [rsp+160h] [rbp+60h] BYREF
  hkcdWingedEdge::Edge *v317; // [rsp+170h] [rbp+70h]
  hkVector4f direction; // [rsp+180h] [rbp+80h] BYREF
  hkcdWingedEdge::Vertex result; // [rsp+190h] [rbp+90h] BYREF
  hkcdWingedEdge::Vertex v320; // [rsp+1D0h] [rbp+D0h] BYREF
  hkVector4f v321; // [rsp+210h] [rbp+110h] BYREF
  hkSimdFloat32 v322; // [rsp+220h] [rbp+120h] BYREF
  hkVector4f v323; // [rsp+230h] [rbp+130h] BYREF
  hkVector4f v324; // [rsp+240h] [rbp+140h] BYREF
  hkVector4f from; // [rsp+250h] [rbp+150h] BYREF
  __m128 v326; // [rsp+260h] [rbp+160h]
  __m128 v327; // [rsp+270h] [rbp+170h]
  __m128 v328; // [rsp+280h] [rbp+180h]
  __int128 v329; // [rsp+300h] [rbp+200h]
  __int64 v330[100]; // [rsp+310h] [rbp+210h] BYREF
  hkcdWingedEdge v331; // [rsp+630h] [rbp+530h] BYREF

  m_storage = dimB->m_storage;
  v11 = 4;
  if ( dimB->m_storage < 3 )
  {
    v12 = dimA->m_storage;
    if ( (int)v12 < 3 )
    {
      v13.m_quad = (__m128)this->m_verticesA[0];
      v14.m_quad = (__m128)this->m_verticesBinA[0];
      v11 = 1;
      this->m_verticesA[v12] = (hkcdVertex)v13.m_quad;
      this->m_verticesA[dimA->m_storage + 1] = (hkcdVertex)v13.m_quad;
      this->m_verticesBinA[dimB->m_storage] = (hkcdVertex)v14.m_quad;
      this->m_verticesBinA[dimB->m_storage + 1] = (hkcdVertex)v14.m_quad;
    }
    else
    {
      if ( (int)v12 <= 3 )
      {
        if ( m_storage <= 1 )
        {
          v11 = 3;
        }
        else
        {
          this->m_verticesA[3] = this->m_verticesA[0];
          this->m_verticesBinA[3] = this->m_verticesBinA[1];
        }
      }
      else
      {
        this->m_verticesBinA[3] = this->m_verticesBinA[0];
      }
      this->m_verticesBinA[1] = this->m_verticesBinA[0];
      this->m_verticesBinA[2] = this->m_verticesBinA[0];
    }
  }
  else
  {
    if ( m_storage <= 3 )
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
  m_quad = this->m_verticesA[1].m_quad;
  v16 = this->m_verticesA[0].m_quad;
  v17 = 0;
  p_from = &from;
  v310.m_shapeInterface.m_storage = shapeInterface;
  v310.m_shapeA.m_storage = shapeA;
  v19 = _mm_sub_ps(v16, this->m_verticesBinA[0].m_quad);
  v20 = _mm_sub_ps(m_quad, this->m_verticesBinA[1].m_quad);
  v310.m_shapeB.m_storage = shapeB;
  v310.m_pointsAinA.m_storage = this->m_verticesA;
  v310.m_pointsBinA.m_storage = this->m_verticesBinA;
  from.m_quad = v19;
  v21 = this->m_verticesA[2].m_quad;
  v326 = v20;
  v22 = _mm_sub_ps(v21, this->m_verticesBinA[2].m_quad);
  v23 = this->m_verticesA[3].m_quad;
  v310.m_backupTries.m_storage = 0;
  v310.m_simplex.m_storage = &from;
  v327 = v22;
  v24 = _mm_sub_ps(v23, this->m_verticesBinA[3].m_quad);
  v310.m_aTb.m_rotation.m_col0 = aTb->m_rotation.m_col0;
  v25.m_quad = (__m128)aTb->m_rotation.m_col2;
  v328 = v24;
  v26.m_quad = (__m128)aTb->m_rotation.m_col1;
  v310.m_aTb.m_rotation.m_col2 = (hkVector4f)v25.m_quad;
  v310.m_aTb.m_rotation.m_col1 = (hkVector4f)v26.m_quad;
  v27.m_quad = (__m128)aTb->m_translation;
  v310.m_epsTol = *(hkVector4f *)_xmm;
  v310.m_aTb.m_translation = (hkVector4f)v27.m_quad;
  chainLength.m_storage = LODWORD(FLOAT_9_9999991eN9);
  v310.m_epsTolSqrd.m_real = _mm_shuffle_ps((__m128)LODWORD(FLOAT_9_9999991eN9), (__m128)LODWORD(FLOAT_9_9999991eN9), 0);
LABEL_17:
  v310.m_simplexSize.m_storage = v11;
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
    v32 = _mm_mul_ps(v310.m_aTb.m_translation.m_quad, v310.m_aTb.m_translation.m_quad);
    direction.m_quad = _mm_xor_ps(
                         (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                         v310.m_aTb.m_translation.m_quad);
    if ( (float)((float)(_mm_shuffle_ps(v32, v32, 85).m128_f32[0] + _mm_shuffle_ps(v32, v32, 0).m128_f32[0])
               + _mm_shuffle_ps(v32, v32, 170).m128_f32[0]) <= v310.m_epsTolSqrd.m_real.m128_f32[0] )
      direction.m_quad = ::direction.m_quad;
    hkcdConvexPenetrationUtil::getPointForSimplex(&v310, &direction, &result);
    *v310.m_simplex.m_storage = result.m_position;
    *v310.m_pointsAinA.m_storage = result.m_pointAinA;
    *v310.m_pointsBinA.m_storage = result.m_pointBinX;
    p_from = v310.m_simplex.m_storage;
    v310.m_simplexSize.m_storage = 1;
    v33 = _mm_mul_ps(v310.m_simplex.m_storage->m_quad, v310.m_simplex.m_storage->m_quad);
    if ( (float)((float)(_mm_shuffle_ps(v33, v33, 85).m128_f32[0] + _mm_shuffle_ps(v33, v33, 0).m128_f32[0])
               + _mm_shuffle_ps(v33, v33, 170).m128_f32[0]) <= v310.m_epsTolSqrd.m_real.m128_f32[0] )
      break;
    v28 = 0;
LABEL_28:
    v34 = _mm_mul_ps(p_from->m_quad, p_from->m_quad);
    if ( (float)((float)(_mm_shuffle_ps(v34, v34, 85).m128_f32[0] + _mm_shuffle_ps(v34, v34, 0).m128_f32[0])
               + _mm_shuffle_ps(v34, v34, 170).m128_f32[0]) > v310.m_epsTolSqrd.m_real.m128_f32[0] )
    {
      v28 = 1;
      hkcdConvexPenetrationUtil::getPointForSimplex(&v310, p_from, &result);
      v35 = _mm_sub_ps(result.m_position.m_quad, v310.m_simplex.m_storage->m_quad);
      v36 = _mm_mul_ps(v35, v35);
      v321.m_quad = _mm_xor_ps(
                      (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                      p_from->m_quad);
      hkcdConvexPenetrationUtil::getPointForSimplex(&v310, &v321, &v320);
      v37 = _mm_sub_ps(v320.m_position.m_quad, v310.m_simplex.m_storage->m_quad);
      v38 = _mm_mul_ps(v37, v37);
      if ( (float)((float)(_mm_shuffle_ps(v36, v36, 85).m128_f32[0] + _mm_shuffle_ps(v36, v36, 0).m128_f32[0])
                 + _mm_shuffle_ps(v36, v36, 170).m128_f32[0]) < (float)((float)(_mm_shuffle_ps(v38, v38, 85).m128_f32[0]
                                                                              + _mm_shuffle_ps(v38, v38, 0).m128_f32[0])
                                                                      + _mm_shuffle_ps(v38, v38, 170).m128_f32[0]) )
      {
        v310.m_simplex.m_storage[1] = v320.m_position;
        v310.m_pointsAinA.m_storage[1] = v320.m_pointAinA;
        v310.m_pointsBinA.m_storage[1] = v320.m_pointBinX;
      }
      else
      {
        v310.m_simplex.m_storage[1] = result.m_position;
        v310.m_pointsAinA.m_storage[1] = result.m_pointAinA;
        v310.m_pointsBinA.m_storage[1] = result.m_pointBinX;
      }
      p_from = v310.m_simplex.m_storage;
      while ( 1 )
      {
        v310.m_simplexSize.m_storage = 2;
LABEL_34:
        v39 = _mm_sub_ps(p_from->m_quad, p_from[1].m_quad);
        v40 = _mm_mul_ps(v39, v39);
        if ( (float)((float)(_mm_shuffle_ps(v40, v40, 85).m128_f32[0] + _mm_shuffle_ps(v40, v40, 0).m128_f32[0])
                   + _mm_shuffle_ps(v40, v40, 170).m128_f32[0]) <= v310.m_epsTolSqrd.m_real.m128_f32[0] )
        {
          if ( v28 < 1 )
          {
            v310.m_simplexSize.m_storage = 1;
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
        v46 = _mm_cmplt_ps(
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
        v324.m_quad = _mm_mul_ps(
                        v47,
                        _mm_andnot_ps(
                          _mm_cmple_ps(v49, (__m128)0i64),
                          _mm_mul_ps(
                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v50, v49), v50)),
                            _mm_mul_ps(*(__m128 *)_xmm, v50))));
        v54 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v53, v53, 85), _mm_shuffle_ps(v53, v53, 0)),
                _mm_shuffle_ps(v53, v53, 170));
        v55 = _mm_rsqrt_ps(v54);
        v323.m_quad = _mm_mul_ps(
                        v52,
                        _mm_andnot_ps(
                          _mm_cmple_ps(v54, (__m128)0i64),
                          _mm_mul_ps(
                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v55, v54), v55)),
                            _mm_mul_ps(*(__m128 *)_xmm, v55))));
        hkcdConvexPenetrationUtil::findBestProjection(&v310, &v313, &v324, p_from, &v320);
        hkcdConvexPenetrationUtil::findBestProjection(&v310, &v322, &v323, v310.m_simplex.m_storage, &result);
        if ( v322.m_real.m128_f32[0] >= v313.m_real.m128_f32[0] )
        {
          v310.m_simplex.m_storage[2] = result.m_position;
          v310.m_pointsAinA.m_storage[2] = result.m_pointAinA;
          v56.m_quad = (__m128)result.m_pointBinX;
        }
        else
        {
          v310.m_simplex.m_storage[2] = v320.m_position;
          v310.m_pointsAinA.m_storage[2] = v320.m_pointAinA;
          v56.m_quad = (__m128)v320.m_pointBinX;
        }
        v310.m_pointsBinA.m_storage[2] = (hkcdVertex)v56.m_quad;
        p_from = v310.m_simplex.m_storage;
LABEL_39:
        v310.m_simplexSize.m_storage = 3;
LABEL_40:
        v57 = p_from[1].m_quad;
        v58 = _mm_sub_ps(p_from->m_quad, v57);
        v59 = _mm_sub_ps(v57, p_from[2].m_quad);
        v60 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v59, v59, 201), v58), _mm_mul_ps(_mm_shuffle_ps(v58, v58, 201), v59));
        v61 = _mm_shuffle_ps(v60, v60, 201);
        v309.m_quad = v61;
        v62 = _mm_mul_ps(v61, v61);
        if ( (float)((float)(_mm_shuffle_ps(v62, v62, 85).m128_f32[0] + _mm_shuffle_ps(v62, v62, 0).m128_f32[0])
                   + _mm_shuffle_ps(v62, v62, 170).m128_f32[0]) != 0.0 )
          break;
        if ( v28 >= 2 )
        {
          v72 = _mm_sub_ps(p_from->m_quad, p_from[1].m_quad);
          output->m_distance = 0i64;
          p_m_normalInA = &output->m_normalInA;
          v74 = _mm_shuffle_ps(v72, _mm_unpackhi_ps(v72, (__m128)0i64), 196);
          v75 = _mm_shuffle_ps(v74, v74, 241);
          v76 = _mm_shuffle_ps(v74, v74, 206);
          v77 = _mm_mul_ps(v76, v76);
          v78 = _mm_mul_ps(v75, v75);
          v79 = _mm_cmplt_ps(
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
                                           _mm_cmple_ps(v82, (__m128)0i64),
                                           _mm_mul_ps(
                                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v83, v82), v83)),
                                             _mm_mul_ps(*(__m128 *)_xmm, v83))),
                                         v80);
          v84 = (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128((const __m128i *)p_from), 1u), 1u);
          v85 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v84, v84, 85), _mm_shuffle_ps(v84, v84, 0)),
                  _mm_shuffle_ps(v84, v84, 170));
          v86 = _mm_add_ps(_mm_add_ps(v85, v85), *(__m128 *)&epsilon);
          v87 = _mm_rcp_ps(v86);
          output->m_pointAinA.m_quad = _mm_add_ps(
                                         _mm_mul_ps(
                                           _mm_sub_ps(
                                             v310.m_pointsAinA.m_storage[1].m_quad,
                                             v310.m_pointsAinA.m_storage->m_quad),
                                           _mm_mul_ps(
                                             _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v87, v86)), v87),
                                             v85)),
                                         v310.m_pointsAinA.m_storage->m_quad);
          goto LABEL_138;
        }
      }
      v28 = 3;
      v63 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v62, v62, 85), _mm_shuffle_ps(v62, v62, 0)),
              _mm_shuffle_ps(v62, v62, 170));
      v64 = _mm_rsqrt_ps(v63);
      v309.m_quad = _mm_mul_ps(
                      v61,
                      _mm_andnot_ps(
                        _mm_cmple_ps(v63, (__m128)0i64),
                        _mm_mul_ps(
                          _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v64, v63), v64)),
                          _mm_mul_ps(*(__m128 *)_xmm, v64))));
      hkcdConvexPenetrationUtil::findBestProjection(&v310, &v315, &v309, p_from, &v320);
      v65 = v310.m_simplex.m_storage;
      if ( v315.m_real.m128_f32[0] < _mm_shuffle_ps(v310.m_epsTol.m_quad, v310.m_epsTol.m_quad, 0).m128_f32[0] )
      {
        output->m_normalInA = (hkVector4f)v309.m_quad;
        output->m_distance = 0i64;
        p_m_normalInA = &output->m_normalInA;
        v240 = _mm_sub_ps(v65[2].m_quad, v65->m_quad);
        v241 = _mm_sub_ps(v65[1].m_quad, v65->m_quad);
        v242 = _mm_sub_ps(v65[2].m_quad, aabbOut.m_quad);
        v243 = _mm_sub_ps(v65[1].m_quad, aabbOut.m_quad);
        v244 = _mm_sub_ps(v65->m_quad, aabbOut.m_quad);
        v245 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v240, v240, 201), v241),
                 _mm_mul_ps(_mm_shuffle_ps(v241, v241, 201), v240));
        v246 = _mm_shuffle_ps(v245, v245, 201);
        v247 = _mm_shuffle_ps(v246, v246, 210);
        v248 = _mm_shuffle_ps(v246, v246, 201);
        v249 = _mm_mul_ps(
                 _mm_sub_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v242, v242, 201), v247),
                   _mm_mul_ps(_mm_shuffle_ps(v242, v242, 210), v248)),
                 v243);
        v250 = _mm_mul_ps(
                 _mm_sub_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v244, v244, 201), v247),
                   _mm_mul_ps(_mm_shuffle_ps(v244, v244, 210), v248)),
                 v242);
        v251 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v243, v243, 201), v247),
                 _mm_mul_ps(_mm_shuffle_ps(v243, v243, 210), v248));
        v252 = _mm_unpacklo_ps(v249, v250);
        v253 = _mm_mul_ps(v251, v244);
        v254 = _mm_movelh_ps(v252, v253);
        v255 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(_mm_movehl_ps(v254, v252), v253, 212), v254),
                 _mm_shuffle_ps(_mm_unpackhi_ps(v249, v250), v253, 228));
        v256 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v255, v255, 85), _mm_shuffle_ps(v255, v255, 0)),
                 _mm_shuffle_ps(v255, v255, 170));
        v257 = _mm_rcp_ps(v256);
        v258 = _mm_mul_ps(
                 _mm_andnot_ps(
                   _mm_cmpeq_ps(v256, (__m128)0i64),
                   _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v257, v256)), v257)),
                 v255);
        output->m_pointAinA.m_quad = _mm_add_ps(
                                       _mm_add_ps(
                                         _mm_mul_ps(
                                           _mm_shuffle_ps(v258, v258, 85),
                                           v310.m_pointsAinA.m_storage[1].m_quad),
                                         _mm_mul_ps(_mm_shuffle_ps(v258, v258, 0), v310.m_pointsAinA.m_storage->m_quad)),
                                       _mm_mul_ps(
                                         _mm_shuffle_ps(v258, v258, 170),
                                         v310.m_pointsAinA.m_storage[2].m_quad));
        goto LABEL_138;
      }
      v310.m_simplex.m_storage[3] = v320.m_position;
      v310.m_pointsAinA.m_storage[3] = v320.m_pointAinA;
      v310.m_pointsBinA.m_storage[3] = v320.m_pointBinX;
      p_from = v310.m_simplex.m_storage;
      v310.m_simplexSize.m_storage = 4;
LABEL_43:
      v66 = p_from[1].m_quad;
      v67 = _mm_sub_ps(p_from->m_quad, v66);
      v68 = _mm_sub_ps(v66, p_from[2].m_quad);
      v69 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v68, v68, 201), v67), _mm_mul_ps(_mm_shuffle_ps(v67, v67, 201), v68));
      v309.m_quad = _mm_shuffle_ps(v69, v69, 201);
      v70 = _mm_mul_ps(v309.m_quad, v309.m_quad);
      v71 = _mm_mul_ps(_mm_sub_ps(p_from[3].m_quad, p_from->m_quad), v309.m_quad);
      v69.m128_f32[0] = (float)(_mm_shuffle_ps(v71, v71, 85).m128_f32[0] + _mm_shuffle_ps(v71, v71, 0).m128_f32[0])
                      + _mm_shuffle_ps(v71, v71, 170).m128_f32[0];
      if ( (float)(v69.m128_f32[0] * v69.m128_f32[0]) <= (float)((float)((float)(_mm_shuffle_ps(v70, v70, 85).m128_f32[0]
                                                                               + _mm_shuffle_ps(v70, v70, 0).m128_f32[0])
                                                                       + _mm_shuffle_ps(v70, v70, 170).m128_f32[0])
                                                               * v310.m_epsTolSqrd.m_real.m128_f32[0]) )
      {
        if ( v28 >= 3 )
          goto LABEL_109;
        goto LABEL_39;
      }
      v331.m_numVertices.m_storage = 4;
      v331.m_vertex[0].m_pointAinA = (hkcdVertex)v310.m_pointsAinA.m_storage->m_quad;
      v88 = v310.m_pointsBinA.m_storage->m_quad;
      v89.m_quad = p_from->m_quad;
      v331.m_vertex[0].m_referee.m_storage = 0i64;
      v331.m_vertex[0].m_pointBinX.m_quad = v88;
      v331.m_vertex[0].m_position = (hkVector4f)v89.m_quad;
      v331.m_vertex[1].m_pointAinA = v310.m_pointsAinA.m_storage[1];
      v331.m_vertex[1].m_pointBinX = v310.m_pointsBinA.m_storage[1];
      v90.m_quad = (__m128)p_from[1];
      v331.m_vertex[1].m_referee.m_storage = 0i64;
      v331.m_vertex[1].m_position = (hkVector4f)v90.m_quad;
      v331.m_vertex[2].m_pointAinA = v310.m_pointsAinA.m_storage[2];
      v331.m_vertex[2].m_pointBinX = v310.m_pointsBinA.m_storage[2];
      v91.m_quad = (__m128)p_from[2];
      v331.m_vertex[2].m_referee.m_storage = 0i64;
      v331.m_vertex[2].m_position = (hkVector4f)v91.m_quad;
      v331.m_vertex[3].m_pointAinA = v310.m_pointsAinA.m_storage[3];
      v92.m_quad = (__m128)v310.m_pointsBinA.m_storage[3];
      v93.m_quad = (__m128)p_from[3];
      v331.m_vertex[3].m_referee.m_storage = 0i64;
      v331.m_vertex[3].m_pointBinX = (hkcdVertex)v92.m_quad;
      v331.m_vertex[3].m_position = (hkVector4f)v93.m_quad;
      hkcdWingedEdge::addTetrahedron(&v331);
      v94 = v331.m_numTriangles.m_storage;
      v95 = v331.m_numVertices.m_storage;
      v331.m_numFreeTriangle.m_storage = 0;
      while ( 1 )
      {
        v96 = v94 - 2 < 0;
        v97 = v94 - 2;
        m_distanceToOrigin = v331.m_triangles[0].m_distanceToOrigin;
        m_triangles = v331.m_triangles;
        p_m_neighbour = v331.m_triangles;
        if ( !v96 )
        {
          v101 = v97 + 1;
          if ( v97 + 1 >= 4 )
          {
            v102 = (unsigned __int64)v101 >> 2;
            v97 -= 4 * (v101 >> 2);
            do
            {
              if ( m_triangles[1].m_distanceToOrigin < m_distanceToOrigin )
              {
                m_distanceToOrigin = m_triangles[1].m_distanceToOrigin;
                p_m_neighbour = m_triangles + 1;
              }
              if ( m_triangles[2].m_distanceToOrigin < m_distanceToOrigin )
              {
                m_distanceToOrigin = m_triangles[2].m_distanceToOrigin;
                p_m_neighbour = m_triangles + 2;
              }
              if ( m_triangles[3].m_distanceToOrigin < m_distanceToOrigin )
              {
                m_distanceToOrigin = m_triangles[3].m_distanceToOrigin;
                p_m_neighbour = m_triangles + 3;
              }
              if ( m_triangles[4].m_distanceToOrigin < m_distanceToOrigin )
              {
                m_distanceToOrigin = m_triangles[4].m_distanceToOrigin;
                p_m_neighbour = m_triangles + 4;
              }
              m_triangles += 4;
              --v102;
            }
            while ( v102 );
          }
          for ( ; v97 >= 0; --v97 )
          {
            ++m_triangles;
            if ( m_triangles->m_distanceToOrigin < m_distanceToOrigin )
            {
              m_distanceToOrigin = m_triangles->m_distanceToOrigin;
              p_m_neighbour = m_triangles;
            }
          }
        }
        v103 = v310.m_shapeInterface.m_storage;
        v104 = v310.m_shapeB.m_storage;
        v331.m_numVertices.m_storage = v95 + 1;
        v105 = (hkVector4f *)&v331.m_freeTriangle[8 * (__int64)v95 - 440];
        v105[3].m_quad.m128_u64[0] = 0i64;
        v103->vfptr->getSupportingVertices(
          v103,
          v310.m_shapeA.m_storage,
          &p_m_neighbour->m_normal,
          v104,
          &v310.m_aTb,
          (hkcdVertex *)&v105[1],
          (hkcdVertex *)&v314,
          (hkVector4f *)&v316);
        v106 = v316;
        v107 = _mm_sub_ps(v105[1].m_quad, v316);
        v108 = v316;
        *v105 = (hkVector4f)v107;
        v105[2].m_quad = _mm_shuffle_ps(v106, _mm_unpackhi_ps(v108, v314), 196);
        v109 = _mm_sub_ps(v107, p_m_neighbour->m_edge[0].m_vertex->m_position.m_quad);
        v110 = _mm_sub_ps(v107, p_m_neighbour->m_edge[1].m_vertex->m_position.m_quad);
        v111 = _mm_sub_ps(v107, p_m_neighbour->m_edge[2].m_vertex->m_position.m_quad);
        v112 = _mm_unpacklo_ps(v109, v110);
        v113 = _mm_movelh_ps(v112, v111);
        if ( (_mm_movemask_ps(
                _mm_cmplt_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_shuffle_ps(_mm_movehl_ps(v113, v112), v111, 212),
                        _mm_shuffle_ps(p_m_neighbour->m_normal.m_quad, p_m_neighbour->m_normal.m_quad, 85)),
                      _mm_mul_ps(
                        _mm_shuffle_ps(p_m_neighbour->m_normal.m_quad, p_m_neighbour->m_normal.m_quad, 0),
                        v113)),
                    _mm_mul_ps(
                      _mm_shuffle_ps(_mm_unpackhi_ps(v109, v110), v111, 228),
                      _mm_shuffle_ps(p_m_neighbour->m_normal.m_quad, p_m_neighbour->m_normal.m_quad, 170))),
                  v310.m_epsTol.m_quad)) & 7) != 0 )
        {
          v159 = 1;
          goto LABEL_118;
        }
        v114 = *(_OWORD *)&p_m_neighbour->m_distanceToOrigin;
        v115 = FLOAT_1_0eN7;
        v116 = p_m_neighbour->m_normal.m_quad;
        edgeChain.m_storage = 0i64;
        chainLength.m_storage = 0;
        v117 = *(_OWORD *)&p_m_neighbour->m_edge[0].m_vertex;
        v118 = *(_OWORD *)&p_m_neighbour->m_edge[0].m_neighbour;
        v119 = *(_OWORD *)&p_m_neighbour->m_edge[1].m_vertex;
        v120 = v331.m_numFreeTriangle.m_storage - v331.m_numTriangles.m_storage + 100;
        v121 = *(_OWORD *)&p_m_neighbour->m_edge[1].m_neighbour;
        v122 = *(_OWORD *)&p_m_neighbour->m_edge[2].m_vertex;
        v123 = *(_OWORD *)&p_m_neighbour->m_edge[2].m_neighbour;
        v331.m_toleranceBorder.m_storage = FLOAT_1_0eN7;
        v329 = v114;
        v124 = FLOAT_3_40282e38;
        v331.m_previousMinimumDistance.m_storage = FLOAT_3_40282e38;
        v125 = 1;
        v126 = _mm_mul_ps(
                 _mm_sub_ps(v105->m_quad, p_m_neighbour->m_edge[0].m_vertex->m_position.m_quad),
                 p_m_neighbour->m_normal.m_quad);
        v127 = (float)(_mm_shuffle_ps(v126, v126, 85).m128_f32[0] + _mm_shuffle_ps(v126, v126, 0).m128_f32[0])
             + _mm_shuffle_ps(v126, v126, 170).m128_f32[0];
        if ( v127 <= 0.0000001 )
        {
          v128 = v127 + 0.0000001;
          if ( v128 > 0.0000001 )
          {
            v115 = v128;
            v331.m_toleranceBorder.m_storage = v128;
          }
          v125 = 2;
        }
        else
        {
          if ( v127 >= 3.40282e38 )
            goto LABEL_78;
          v124 = v127;
          v331.m_previousMinimumDistance.m_storage = v127;
        }
        if ( v115 >= v124 )
          v125 = 4;
LABEL_78:
        p_m_neighbour->m_state = v125;
        if ( v125 != 1 || hkcdWingedEdge::findVisibleTriangles(&v331, p_m_neighbour, v105, &chainLength, &edgeChain) )
          goto LABEL_108;
        v129 = v331.m_numFreeTriangle.m_storage;
        v94 = v331.m_numTriangles.m_storage;
        v130 = chainLength.m_storage;
        if ( v331.m_numFreeTriangle.m_storage - v331.m_numTriangles.m_storage + 100 < chainLength.m_storage )
        {
          if ( v331.m_numFreeTriangle.m_storage > v120 )
          {
            do
            {
              hkcdWingedEdge::Triangle::calculateTriangleData(v331.m_freeTriangle[v129 - 1]);
              v129 = v331.m_numFreeTriangle.m_storage - 1;
              v331.m_numFreeTriangle.m_storage = v129;
            }
            while ( v129 > v120 );
          }
          v160 = DWORD1(v329);
          v161 = *(float *)&v329;
          p_m_neighbour->m_normal.m_quad = v116;
          *(_OWORD *)&p_m_neighbour->m_edge[0].m_vertex = v117;
          *(_OWORD *)&p_m_neighbour->m_edge[1].m_vertex = v119;
          *(_OWORD *)&p_m_neighbour->m_edge[2].m_vertex = v122;
          v159 = 3;
          *(_OWORD *)&p_m_neighbour->m_edge[0].m_neighbour = v118;
          *(_OWORD *)&p_m_neighbour->m_edge[1].m_neighbour = v121;
          *(_OWORD *)&p_m_neighbour->m_edge[2].m_neighbour = v123;
          p_m_neighbour->m_state = v160;
          p_m_neighbour->m_distanceToOrigin = v161;
LABEL_118:
          v94 = v331.m_numTriangles.m_storage;
          goto LABEL_119;
        }
        v131 = chainLength.m_storage;
        v132 = 0i64;
        for ( i = v331.m_numFreeTriangle.m_storage - 1; v131; --v131 )
        {
          if ( i < 0 )
            break;
          --v129;
          v330[v132++] = (__int64)v331.m_freeTriangle[i--];
          v331.m_numFreeTriangle.m_storage = v129;
        }
        if ( v131 > 0 )
        {
          v134 = (unsigned int)v131;
          v135 = &v330[v132];
          do
          {
            v136 = v94++;
            *v135++ = (__int64)&v331.m_triangles[v136];
            --v134;
          }
          while ( v134 );
          v331.m_numTriangles.m_storage = v94;
        }
        v137 = edgeChain.m_storage;
        v138 = 0i64;
        v317 = edgeChain.m_storage;
        v139 = edgeChain.m_storage;
        if ( (int)v130 > 0 )
          break;
LABEL_97:
        v155 = 0;
        if ( v94 > 0 )
        {
          p_m_state = &v331.m_triangles[0].m_state;
          do
          {
            *p_m_state = HKCD_NOT_VISITED;
            v94 = v331.m_numTriangles.m_storage;
            ++v155;
            p_m_state += 32;
          }
          while ( v155 < v331.m_numTriangles.m_storage );
        }
        v95 = v331.m_numVertices.m_storage;
        v157 = 0;
        if ( v331.m_numVertices.m_storage > 0 )
        {
          p_m_referee = &v331.m_vertex[0].m_referee;
          do
          {
            p_m_referee->m_storage = 0i64;
            v95 = v331.m_numVertices.m_storage;
            ++v157;
            p_m_referee += 8;
          }
          while ( v157 < v331.m_numVertices.m_storage );
          v94 = v331.m_numTriangles.m_storage;
        }
        if ( v137 != v139 )
          goto LABEL_108;
        if ( v95 >= 55 )
        {
          v159 = 3;
LABEL_119:
          p_m_quad = &p_m_neighbour->m_edge[2].m_vertex->m_position.m_quad;
          v163 = &p_m_neighbour->m_edge[1].m_vertex->m_position.m_quad;
          v164 = (__m128)_xmm;
          v165 = p_m_neighbour->m_edge[0].m_vertex->m_position.m_quad;
          v166 = _mm_sub_ps(*p_m_quad, aabbOut.m_quad);
          v167 = _mm_sub_ps(*p_m_quad, v165);
          v168 = _mm_sub_ps(*v163, v165);
          v169 = _mm_sub_ps(*v163, aabbOut.m_quad);
          v170 = _mm_sub_ps(v165, aabbOut.m_quad);
          v171 = _mm_sub_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v167, v167, 201), v168),
                   _mm_mul_ps(_mm_shuffle_ps(v168, v168, 201), v167));
          v172 = _mm_shuffle_ps(v171, v171, 201);
          v173 = _mm_shuffle_ps(v172, v172, 210);
          v174 = _mm_shuffle_ps(v172, v172, 201);
          v175 = _mm_mul_ps(
                   _mm_sub_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v166, v166, 201), v173),
                     _mm_mul_ps(_mm_shuffle_ps(v166, v166, 210), v174)),
                   v169);
          v176 = _mm_mul_ps(
                   _mm_sub_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v170, v170, 201), v173),
                     _mm_mul_ps(_mm_shuffle_ps(v170, v170, 210), v174)),
                   v166);
          v177 = _mm_sub_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v169, v169, 201), v173),
                   _mm_mul_ps(_mm_shuffle_ps(v169, v169, 210), v174));
          v178 = _mm_unpacklo_ps(v175, v176);
          v179 = _mm_mul_ps(v177, v170);
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
                     _mm_cmpeq_ps(v182, (__m128)0i64),
                     _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v183, v182)), v183)),
                   v181);
          if ( (_mm_movemask_ps(_mm_cmplt_ps(v184, (__m128)0i64)) & 7) != 0 )
          {
            v185 = -3.40282e38;
            v186 = v94 - 1;
            if ( v94 - 1 >= 0 )
            {
              m_edge = v331.m_triangles[0].m_edge;
              do
              {
                v188 = &m_edge[1].m_vertex->m_position.m_quad;
                v189 = &m_edge[2].m_vertex->m_position.m_quad;
                v190 = m_edge->m_vertex->m_position.m_quad;
                v191 = _mm_sub_ps(*v189, *v188);
                v192 = _mm_sub_ps(v190, *v189);
                v193 = _mm_sub_ps(*v188, v190);
                v194 = _mm_shuffle_ps(v193, v193, 201);
                v195 = _mm_shuffle_ps(v191, v191, 201);
                v196 = _mm_shuffle_ps(v193, v193, 210);
                v197 = _mm_sub_ps(_mm_mul_ps(v193, v195), _mm_mul_ps(v191, v194));
                v198 = _mm_shuffle_ps(v197, v197, 201);
                v199 = _mm_shuffle_ps(v198, v198, 210);
                v200 = _mm_shuffle_ps(v198, v198, 201);
                v201 = _mm_sub_ps(_mm_mul_ps(v199, v194), _mm_mul_ps(v196, v200));
                v202 = _mm_mul_ps(v201, v201);
                v203 = _mm_sub_ps(_mm_mul_ps(v199, v195), _mm_mul_ps(_mm_shuffle_ps(v191, v191, 210), v200));
                v204 = _mm_sub_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v192, v192, 201), v199),
                         _mm_mul_ps(_mm_shuffle_ps(v192, v192, 210), v200));
                v205 = _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v202, v202, 85), _mm_shuffle_ps(v202, v202, 0)),
                         _mm_shuffle_ps(v202, v202, 170));
                v206 = _mm_mul_ps(v203, v203);
                v207 = _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v206, v206, 85), _mm_shuffle_ps(v206, v206, 0)),
                         _mm_shuffle_ps(v206, v206, 170));
                v208 = _mm_mul_ps(v204, v204);
                v209 = _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v208, v208, 85), _mm_shuffle_ps(v208, v208, 0)),
                         _mm_shuffle_ps(v208, v208, 170));
                v210 = _mm_mul_ps(_mm_mul_ps(_mm_rsqrt_ps(v205), v201), v190);
                v211 = _mm_mul_ps(_mm_mul_ps(_mm_rsqrt_ps(v207), v203), *v188);
                v212 = _mm_mul_ps(_mm_mul_ps(_mm_rsqrt_ps(v209), v204), *v189);
                v213 = fmin(
                         fmin(
                           (float)(_mm_shuffle_ps(v210, v210, 85).m128_f32[0] + _mm_shuffle_ps(v210, v210, 0).m128_f32[0])
                         + _mm_shuffle_ps(v210, v210, 170).m128_f32[0],
                           (float)(_mm_shuffle_ps(v211, v211, 85).m128_f32[0] + _mm_shuffle_ps(v211, v211, 0).m128_f32[0])
                         + _mm_shuffle_ps(v211, v211, 170).m128_f32[0]),
                         fmin(
                           (float)(_mm_shuffle_ps(v212, v212, 85).m128_f32[0] + _mm_shuffle_ps(v212, v212, 0).m128_f32[0])
                         + _mm_shuffle_ps(v212, v212, 170).m128_f32[0],
                           0.0))
                     - _mm_shuffle_ps((__m128)LODWORD(m_edge[3].m_vertex), (__m128)LODWORD(m_edge[3].m_vertex), 0).m128_f32[0];
                if ( v213 > v185 )
                {
                  p_m_neighbour = (hkcdWingedEdge::Triangle *)&m_edge[-1].m_neighbour;
                  v185 = v213;
                }
                m_edge += 4;
                --v186;
              }
              while ( v186 >= 0 );
              v164 = (__m128)_xmm;
            }
            v214 = &p_m_neighbour->m_edge[2].m_vertex->m_position.m_quad;
            v215 = &p_m_neighbour->m_edge[0].m_vertex->m_position.m_quad;
            v216 = &p_m_neighbour->m_edge[1].m_vertex->m_position.m_quad;
            v217 = _mm_sub_ps(*v214, aabbOut.m_quad);
            v218 = _mm_sub_ps(*v216, aabbOut.m_quad);
            v219 = _mm_sub_ps(*v214, *v215);
            v220 = _mm_sub_ps(*v216, *v215);
            v221 = _mm_sub_ps(*v215, aabbOut.m_quad);
            v222 = _mm_sub_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v219, v219, 201), v220),
                     _mm_mul_ps(_mm_shuffle_ps(v220, v220, 201), v219));
            v223 = _mm_shuffle_ps(v222, v222, 201);
            v224 = _mm_shuffle_ps(v223, v223, 210);
            v225 = _mm_shuffle_ps(v223, v223, 201);
            v226 = _mm_mul_ps(
                     _mm_sub_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v217, v217, 201), v224),
                       _mm_mul_ps(_mm_shuffle_ps(v217, v217, 210), v225)),
                     v218);
            v227 = _mm_mul_ps(
                     _mm_sub_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v221, v221, 201), v224),
                       _mm_mul_ps(_mm_shuffle_ps(v221, v221, 210), v225)),
                     v217);
            v228 = _mm_sub_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v218, v218, 201), v224),
                     _mm_mul_ps(_mm_shuffle_ps(v218, v218, 210), v225));
            v229 = _mm_unpacklo_ps(v226, v227);
            v230 = _mm_mul_ps(v228, v221);
            v231 = _mm_movelh_ps(v229, v230);
            v232 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(_mm_movehl_ps(v231, v229), v230, 212), v231),
                     _mm_shuffle_ps(_mm_unpackhi_ps(v226, v227), v230, 228));
            v233 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v232, v232, 85), _mm_shuffle_ps(v232, v232, 0)),
                     _mm_shuffle_ps(v232, v232, 170));
            v234 = _mm_rcp_ps(v233);
            v184 = _mm_mul_ps(
                     _mm_andnot_ps(
                       _mm_cmpeq_ps(v233, (__m128)0i64),
                       _mm_mul_ps(_mm_sub_ps(v164, _mm_mul_ps(v234, v233)), v234)),
                     v232);
          }
          m_vertex = p_m_neighbour->m_edge[1].m_vertex;
          v236 = (hkcdVertex *)p_m_neighbour->m_edge[0].m_vertex;
          v237 = p_m_neighbour->m_edge[2].m_vertex;
          v238 = v310.m_pointsAinA.m_storage;
          output->m_pointAinA.m_quad = _mm_add_ps(
                                         _mm_add_ps(
                                           _mm_mul_ps(_mm_shuffle_ps(v184, v184, 0), v236[1].m_quad),
                                           _mm_mul_ps(_mm_shuffle_ps(v184, v184, 85), m_vertex->m_pointAinA.m_quad)),
                                         _mm_mul_ps(_mm_shuffle_ps(v184, v184, 170), v237->m_pointAinA.m_quad));
          *v238 = (hkcdVertex)v236[1].m_quad;
          *v310.m_pointsBinA.m_storage = v236[2];
          v310.m_pointsAinA.m_storage[1] = m_vertex->m_pointAinA;
          v239.m_quad = (__m128)m_vertex->m_pointBinX;
          p_m_normalInA = &output->m_normalInA;
          v310.m_pointsBinA.m_storage[1] = (hkcdVertex)v239.m_quad;
          v310.m_pointsAinA.m_storage[2] = v237->m_pointAinA;
          v310.m_pointsBinA.m_storage[2] = v237->m_pointBinX;
          output->m_normalInA.m_quad = _mm_xor_ps(
                                         (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                                         p_m_neighbour->m_normal.m_quad);
          output->m_distance.m_real = _mm_sub_ps(
                                        (__m128)0i64,
                                        _mm_shuffle_ps(
                                          (__m128)LODWORD(p_m_neighbour->m_distanceToOrigin),
                                          (__m128)LODWORD(p_m_neighbour->m_distanceToOrigin),
                                          0));
          goto LABEL_139;
        }
      }
      v140 = 1;
      while ( 1 )
      {
        if ( !v139 )
          goto LABEL_108;
        v141 = v330[v138];
        v142 = v140 >= (int)v130 ? v330[0] : v330[v138 + 1];
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
        if ( (float)((float)(_mm_shuffle_ps(v149, v149, 85).m128_f32[0] + _mm_shuffle_ps(v149, v149, 0).m128_f32[0])
                   + _mm_shuffle_ps(v149, v149, 170).m128_f32[0]) <= 0.0 )
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
                   _mm_cmple_ps(v150, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v151, v150), v151)),
                     _mm_mul_ps(*(__m128 *)_xmm, v151))));
        v153 = _mm_mul_ps(*v144, v152);
        *(float *)(v141 + 112) = (float)(_mm_shuffle_ps(v153, v153, 85).m128_f32[0]
                                       + _mm_shuffle_ps(v153, v153, 0).m128_f32[0])
                               + _mm_shuffle_ps(v153, v153, 170).m128_f32[0];
        *(__m128 *)v141 = v152;
        m_next = v139->m_next;
        v139 = m_next->m_vertex->m_referee.m_storage;
        m_next->m_vertex->m_referee.m_storage = 0i64;
        if ( v138 >= v130 )
        {
          v94 = v331.m_numTriangles.m_storage;
          v137 = v317;
          goto LABEL_97;
        }
      }
      v17 = 0;
LABEL_108:
      p_from = v310.m_simplex.m_storage;
LABEL_109:
      if ( ++v310.m_backupTries.m_storage == 1 )
      {
        v11 = 1;
        goto LABEL_17;
      }
      if ( v310.m_backupTries.m_storage >= 20 )
      {
        v259.m_quad = (__m128)xmmword_141A712F0;
        v260 = transform.m_quad;
        inserted = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
        v262 = ::direction.m_quad;
        v263 = stru_141A71280.m_quad;
        v264 = _mm_mul_ps(g_vectorfConstants[0], g_vectorfConstants[0]);
        v265.m_quad = 0i64;
        v266 = (__m128)_mm_shuffle_epi32(inserted, 0);
        m_real = 0i64;
        v268 = _mm_mul_ps(
                 g_vectorfConstants[0],
                 _mm_rsqrt_ps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v264, v264, 85), _mm_shuffle_ps(v264, v264, 0)),
                     _mm_shuffle_ps(v264, v264, 170))));
        v269 = query.m_quad;
        while ( 1 )
        {
          v309.m_quad = v269;
          v270 = 4i64;
          do
          {
            vfptr = shapeInterface->vfptr;
            v314 = _mm_xor_ps(v260, v266);
            vfptr->getSupportingVertices(
              shapeInterface,
              shapeA,
              (hkVector4f *)&v314,
              shapeB,
              aTb,
              (hkcdVertex *)&v316,
              (hkcdVertex *)&v313,
              (hkVector4f *)&v315);
            v272 = _mm_mul_ps(_mm_sub_ps(v316, v315.m_real), v260);
            v273 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v272, v272, 85), _mm_shuffle_ps(v272, v272, 0)),
                     _mm_shuffle_ps(v272, v272, 170));
            if ( v273.m128_f32[0] > _mm_shuffle_ps(v259.m_quad, v259.m_quad, 255).m128_f32[0] )
            {
              m_real = v313.m_real;
              v259.m_quad = _mm_shuffle_ps(v260, _mm_unpackhi_ps(v260, v273), 196);
              v265.m_quad = v316;
            }
            v260 = v262;
            v262 = v263;
            v263 = v268;
            --v270;
          }
          while ( v270 );
          if ( v17 >= 20 )
            break;
          v274 = _mm_shuffle_ps(v259.m_quad, _mm_unpackhi_ps(v259.m_quad, (__m128)0i64), 196);
          v275 = _mm_shuffle_ps(v274, v274, 241);
          v276 = _mm_shuffle_ps(v274, v274, 206);
          v277 = _mm_mul_ps(v275, v275);
          v278 = _mm_mul_ps(v276, v276);
          v279 = _mm_cmplt_ps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v277, v277, 85), _mm_shuffle_ps(v277, v277, 0)),
                     _mm_shuffle_ps(v277, v277, 170)),
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v278, v278, 85), _mm_shuffle_ps(v278, v278, 0)),
                     _mm_shuffle_ps(v278, v278, 170)));
          v280 = _mm_xor_ps(_mm_or_ps(_mm_andnot_ps(v279, v275), _mm_and_ps(v276, v279)), (__m128)inserted);
          v281 = _mm_mul_ps(v280, v280);
          v282 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v281, v281, 85), _mm_shuffle_ps(v281, v281, 0)),
                   _mm_shuffle_ps(v281, v281, 170));
          v283 = _mm_rsqrt_ps(v282);
          v284 = _mm_mul_ps(
                   v280,
                   _mm_andnot_ps(
                     _mm_cmple_ps(v282, (__m128)0i64),
                     _mm_mul_ps(
                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v283, v282), v283)),
                       _mm_mul_ps(*(__m128 *)_xmm, v283))));
          v285 = _mm_mul_ps(_mm_shuffle_ps(v259.m_quad, v259.m_quad, 201), v284);
          v286 = _mm_shuffle_ps(v284, v284, 201);
          v287 = _mm_mul_ps(v284, v309.m_quad);
          v288 = _mm_add_ps(v287, v259.m_quad);
          v289 = _mm_sub_ps(_mm_mul_ps(v286, v259.m_quad), v285);
          v290 = _mm_mul_ps(v288, v288);
          v291 = _mm_mul_ps(_mm_shuffle_ps(v289, v289, 201), v309.m_quad);
          v292 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v290, v290, 85), _mm_shuffle_ps(v290, v290, 0)),
                   _mm_shuffle_ps(v290, v290, 170));
          v293 = _mm_rsqrt_ps(v292);
          ++v17;
          v269 = _mm_mul_ps(v309.m_quad, (__m128)xmmword_141A711B0);
          v294 = _mm_andnot_ps(
                   _mm_cmple_ps(v292, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v293, v292), v293)),
                     _mm_mul_ps(*(__m128 *)_xmm, v293)));
          v260 = _mm_mul_ps(v288, v294);
          v268 = _mm_mul_ps(_mm_sub_ps(v259.m_quad, v291), v294);
          v295 = _mm_sub_ps(v259.m_quad, v287);
          v263 = _mm_mul_ps(_mm_add_ps(v291, v259.m_quad), v294);
          v262 = _mm_mul_ps(v295, v294);
        }
        v159 = 2;
        this->m_verticesA[0] = (hkcdVertex)v265.m_quad;
        this->m_verticesBinA[0].m_quad = m_real;
        output->m_pointAinA = (hkVector4f)v265.m_quad;
        output->m_normalInA = (hkVector4f)v259.m_quad;
        p_m_normalInA = &output->m_normalInA;
        output->m_distance.m_real = _mm_shuffle_ps(v259.m_quad, v259.m_quad, 255);
        dimA->m_storage = 1;
        dimB->m_storage = 1;
        goto LABEL_155;
      }
      v311.m128_i32[3] = 0;
      v11 = 0;
      v310.m_simplexSize.m_storage = 0;
      v311.m128_f32[0] = (float)((float)((float)((12345 - 1043968403 * v310.m_backupTries.m_storage) & 0x7FFFFFFF)
                                       * 4.6566129e-10)
                               - 0.000099999997)
                       * 0.00019999999;
      v311.m128_f32[1] = v311.m128_f32[0];
      v311.m128_f32[2] = v311.m128_f32[0];
      v311 = _mm_add_ps(v311, v310.m_aTb.m_translation.m_quad);
      v310.m_aTb.m_translation.m_quad = v311;
      goto LABEL_18;
    }
    if ( v28 >= 0 )
      goto LABEL_109;
    v310.m_simplexSize.m_storage = 0;
  }
  v296 = direction.m_quad;
  v297 = _mm_mul_ps(v310.m_simplex.m_storage->m_quad, v310.m_simplex.m_storage->m_quad);
  p_m_normalInA = &output->m_normalInA;
  output->m_pointAinA = (hkVector4f)result.m_pointAinA;
  v298 = _mm_add_ps(
           _mm_add_ps(_mm_shuffle_ps(v297, v297, 85), _mm_shuffle_ps(v297, v297, 0)),
           _mm_shuffle_ps(v297, v297, 170));
  v299 = _mm_mul_ps(v296, v296);
  v300 = _mm_rsqrt_ps(v298);
  v301 = _mm_add_ps(
           _mm_add_ps(_mm_shuffle_ps(v299, v299, 85), _mm_shuffle_ps(v299, v299, 0)),
           _mm_shuffle_ps(v299, v299, 170));
  v302 = _mm_rsqrt_ps(v301);
  output->m_normalInA.m_quad = _mm_mul_ps(
                                 v296,
                                 _mm_andnot_ps(
                                   _mm_cmple_ps(v301, (__m128)0i64),
                                   _mm_mul_ps(
                                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v302, v301), v302)),
                                     _mm_mul_ps(v302, *(__m128 *)_xmm))));
  output->m_distance.m_real = _mm_andnot_ps(
                                _mm_cmple_ps(v298, (__m128)0i64),
                                _mm_mul_ps(
                                  _mm_mul_ps(
                                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v300, v298), v300)),
                                    _mm_mul_ps(v300, *(__m128 *)_xmm)),
                                  v298));
LABEL_138:
  v159 = 1;
LABEL_139:
  dimA->m_storage = 3;
  dimB->m_storage = 3;
  v303 = this->m_verticesA[2].m_quad.m128_i16[6];
  if ( this->m_verticesA[1].m_quad.m128_i16[6] == v303 || this->m_verticesA[0].m_quad.m128_i16[6] == v303 )
    --dimA->m_storage;
  v304 = dimA->m_storage;
  if ( dimA->m_storage >= 2 && this->m_verticesA[0].m_quad.m128_i16[6] == this->m_verticesA[1].m_quad.m128_i16[6] )
  {
    dimA->m_storage = v304 - 1;
    this->m_verticesA[0] = (hkcdVertex)*((_OWORD *)&this->m_lastDimB.m_storage + v304);
  }
  v305 = this->m_verticesBinA[2].m_quad.m128_i16[6];
  if ( this->m_verticesBinA[1].m_quad.m128_i16[6] == v305 || this->m_verticesBinA[0].m_quad.m128_i16[6] == v305 )
    --dimB->m_storage;
  v306 = dimB->m_storage;
  if ( dimB->m_storage >= 2 && this->m_verticesBinA[0].m_quad.m128_i16[6] == this->m_verticesBinA[1].m_quad.m128_i16[6] )
  {
    dimB->m_storage = v306 - 1;
    this->m_verticesBinA[0] = this->m_verticesA[v306 + 3];
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
  v307 = v159;
  *supportOut = (hkVector4f)p_m_normalInA->m_quad;
  return v307;
}

