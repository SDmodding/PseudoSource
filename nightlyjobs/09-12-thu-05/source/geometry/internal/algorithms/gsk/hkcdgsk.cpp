// File Line: 25
// RVA: 0x1317EC0
void __fastcall hkcdGsk_Vector4Shape::getSupportingVertex(
        hkcdGsk_Vector4Shape *this,
        hkVector4f *direction,
        hkcdVertex *vertexOut)
{
  __m128 m_quad; // xmm4
  hkcdVertex *m_vertices; // r10
  __int64 m_numVertices; // rdx
  int v6; // eax
  int v7; // r9d
  __m128 v8; // xmm1
  float v9; // xmm3_4
  __m128 *p_m_quad; // rcx
  __int64 v11; // rdx
  __m128 v12; // xmm1
  float v13; // xmm2_4

  m_quad = direction->m_quad;
  m_vertices = this->m_vertices;
  m_numVertices = this->m_numVertices;
  v6 = 1;
  v7 = 0;
  v8 = _mm_mul_ps(m_quad, this->m_vertices->m_quad);
  v9 = (float)(_mm_shuffle_ps(v8, v8, 85).m128_f32[0] + _mm_shuffle_ps(v8, v8, 0).m128_f32[0])
     + _mm_shuffle_ps(v8, v8, 170).m128_f32[0];
  if ( m_numVertices > 1 )
  {
    p_m_quad = &m_vertices[1].m_quad;
    v11 = m_numVertices - 1;
    do
    {
      v12 = _mm_mul_ps(m_quad, *p_m_quad);
      v13 = (float)(_mm_shuffle_ps(v12, v12, 85).m128_f32[0] + _mm_shuffle_ps(v12, v12, 0).m128_f32[0])
          + _mm_shuffle_ps(v12, v12, 170).m128_f32[0];
      if ( v13 > v9 )
      {
        v7 = v6;
        v9 = v13;
      }
      ++v6;
      ++p_m_quad;
      --v11;
    }
    while ( v11 );
  }
  *vertexOut = m_vertices[v7];
}

// File Line: 47
// RVA: 0x1317F80
void __fastcall hkcdGsk_Vector4ShapeInterface::getSupportingVertices(
        hkcdGsk_Vector4ShapeInterface *this,
        _DWORD *shapeA,
        hkVector4f *directionA,
        __m128 **shapeB,
        hkTransformf *aTb,
        hkcdVertex *vertexAinAOut,
        hkcdVertex *vertexBinBOut,
        hkVector4f *vertexBinAout)
{
  hkVector4f v8; // xmm3
  __m128 v9; // xmm1
  __m128 v10; // xmm5
  __m128 v11; // xmm11
  __m128 v12; // xmm2
  __m128 v13; // xmm4
  __m128 v14; // xmm6
  __m128 v15; // xmm5
  __m128 v16; // xmm6
  __m128 v17; // xmm1
  __m128 v18; // xmm4
  __m128 v19; // xmm1
  __m128 v20; // xmm13
  __m128 v21; // xmm1
  int v22; // r8d
  __m128 *v23; // rax
  __m128 *v24; // r10
  __m128 v25; // xmm8
  __m128 v26; // xmm1
  __m128 v27; // xmm15
  __m128 v28; // xmm1
  __m128 v29; // xmm2
  __m128 v30; // xmm1
  __m128 v31; // xmm14
  __m128 v32; // xmm1
  int v33; // r11d
  int v34; // ecx
  __m128 v35; // xmm2
  __m128 v36; // xmm1
  __int64 v37; // rdx
  __m128 v38; // xmm1
  __m128 v39; // xmm3
  __m128 v40; // xmm1
  __m128 v41; // xmm2
  __m128 v42; // xmm14
  __m128 v43; // xmm1
  __m128 v44; // xmm3
  __m128 v45; // xmm12
  __m128 v46; // xmm1
  __m128 v47; // xmm4
  __m128 v48; // xmm9
  __m128 v49; // xmm1
  __m128 v50; // xmm7
  __m128 v51; // xmm1
  __m128 v52; // xmm15
  __m128 v53; // xmm1
  __m128 v54; // xmm13
  __m128 v55; // xmm1
  __m128 v56; // xmm10
  __m128 v57; // xmm5
  __m128 v58; // xmm6
  __m128 v59; // xmm11
  __m128 v60; // xmm8
  __m128 v61; // xmm7
  __m128 v62; // xmm2
  __m128 v63; // xmm1
  __m128 v64; // xmm10
  __m128 v65; // xmm12
  __int64 v66; // rdx
  __m128 v67; // xmm1
  __m128 v68; // xmm8
  __m128 v69; // xmm1
  __m128 v70; // xmm7
  __m128 v71; // xmm1
  __m128 v72; // xmm2
  __m128 v73; // xmm6
  __m128 v74; // xmm1
  __m128 v75; // xmm3
  __m128 v76; // xmm1
  __m128 v77; // xmm4
  __m128 v78; // xmm5
  __m128 v79; // xmm0
  __m128 v80; // xmm11
  __m128 v81; // xmm12
  __m128 v82; // xmm15
  __m128 v83; // xmm13
  __int64 v84; // rcx
  __m128 v85; // xmm1
  __m128 v86; // xmm8
  __m128 v87; // xmm1
  __m128 v88; // xmm7
  __m128 v89; // xmm1
  __m128 v90; // xmm5
  __m128 v91; // xmm1
  __m128 v92; // xmm4
  __m128 v93; // xmm2
  __m128 v94; // xmm3
  __m128 v95; // xmm1
  __m128 v96; // xmm6
  __m128 v97; // xmm9
  __m128 v98; // xmm11
  __m128 v99; // xmm12
  __m128 v100; // xmm10
  __m128 v101; // xmm1
  __m128 v102; // xmm7
  __m128 v103; // xmm3
  __m128 v104; // xmm5
  __m128 v105; // xmm6
  __m128 v106; // xmm2
  __m128 v107; // xmm4
  __m128 v108; // [rsp+0h] [rbp-1E8h]
  __m128 v109; // [rsp+10h] [rbp-1D8h]
  __m128 v110; // [rsp+20h] [rbp-1C8h]
  __m128 v111; // [rsp+30h] [rbp-1B8h]
  __m128 v112; // [rsp+40h] [rbp-1A8h]
  __m128 v113; // [rsp+50h] [rbp-198h]
  __m128 v114; // [rsp+60h] [rbp-188h]
  __m128 v115; // [rsp+70h] [rbp-178h]
  __m128 v116; // [rsp+80h] [rbp-168h]
  __m128 v117; // [rsp+90h] [rbp-158h]
  __m128 v118; // [rsp+A0h] [rbp-148h]
  __m128 v119; // [rsp+B0h] [rbp-138h]
  __m128 v120; // [rsp+C0h] [rbp-128h]
  __m128 v121; // [rsp+D0h] [rbp-118h]
  __m128 v122; // [rsp+E0h] [rbp-108h]
  __m128 v123; // [rsp+F0h] [rbp-F8h]
  __m128 m_quad; // [rsp+100h] [rbp-E8h]
  __m128 v125; // [rsp+110h] [rbp-D8h]
  __m128 v126; // [rsp+120h] [rbp-C8h]
  __m128 v127; // [rsp+130h] [rbp-B8h]

  m_quad = directionA->m_quad;
  v8.m_quad = (__m128)aTb->m_rotation.m_col2;
  v9 = _mm_unpacklo_ps(aTb->m_rotation.m_col0.m_quad, aTb->m_rotation.m_col1.m_quad);
  v10 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), directionA->m_quad);
  v11 = *(__m128 *)(*(_QWORD *)shapeA + 48i64);
  v12 = _mm_movelh_ps(v9, v8.m_quad);
  v120 = *(__m128 *)*(_QWORD *)shapeA;
  v121 = **shapeB;
  v13 = _mm_mul_ps(
          _mm_shuffle_ps(_mm_unpackhi_ps(aTb->m_rotation.m_col0.m_quad, aTb->m_rotation.m_col1.m_quad), v8.m_quad, 228),
          _mm_shuffle_ps(v10, v10, 170));
  v14 = _mm_add_ps(
          _mm_mul_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(_mm_movehl_ps(v12, v9), v8.m_quad, 212)),
          _mm_mul_ps(_mm_shuffle_ps(v10, v10, 0), v12));
  v15 = directionA->m_quad;
  v117 = *(__m128 *)(*(_QWORD *)shapeA + 16i64);
  v122 = (*shapeB)[2];
  v16 = _mm_add_ps(v14, v13);
  v17 = _mm_mul_ps(v120, directionA->m_quad);
  v119 = *(__m128 *)(*(_QWORD *)shapeA + 32i64);
  v112 = v11;
  v118 = (*shapeB)[1];
  v18 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)), _mm_shuffle_ps(v17, v17, 170));
  v116 = (*shapeB)[3];
  v125 = v16;
  v19 = _mm_mul_ps(v117, directionA->m_quad);
  v108 = v18;
  v20 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)), _mm_shuffle_ps(v19, v19, 170));
  v21 = _mm_mul_ps(v119, directionA->m_quad);
  v111 = v20;
  v22 = shapeA[2] - 4;
  v23 = (__m128 *)(*(_QWORD *)shapeA + 64i64);
  v24 = *shapeB + 4;
  v25 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v21, v21, 0), _mm_shuffle_ps(v21, v21, 85)), _mm_shuffle_ps(v21, v21, 170));
  v26 = _mm_mul_ps(v11, v15);
  v109 = v25;
  v27 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v26, v26, 85), _mm_shuffle_ps(v26, v26, 0)), _mm_shuffle_ps(v26, v26, 170));
  v28 = _mm_mul_ps(v121, v16);
  v114 = v27;
  v29 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v28, v28, 85), _mm_shuffle_ps(v28, v28, 0)), _mm_shuffle_ps(v28, v28, 170));
  v30 = _mm_mul_ps(v118, v16);
  v113 = v29;
  v31 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v30, v30, 85), _mm_shuffle_ps(v30, v30, 0)), _mm_shuffle_ps(v30, v30, 170));
  v32 = _mm_mul_ps(v122, v16);
  v123 = v31;
  v33 = *((_DWORD *)shapeB + 2) - 4;
  v34 = v33;
  if ( v22 < v33 )
    v34 = shapeA[2] - 4;
  v35 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v32, v32, 85), _mm_shuffle_ps(v32, v32, 0)), _mm_shuffle_ps(v32, v32, 170));
  v36 = _mm_mul_ps((*shapeB)[3], v16);
  v115 = v35;
  v110 = _mm_add_ps(
           _mm_add_ps(_mm_shuffle_ps(v36, v36, 85), _mm_shuffle_ps(v36, v36, 0)),
           _mm_shuffle_ps(v36, v36, 170));
  if ( v34 > 0 )
  {
    v37 = ((unsigned int)(v34 - 1) >> 2) + 1;
    v22 -= 4 * v37;
    v33 -= 4 * v37;
    do
    {
      v38 = _mm_mul_ps(v15, *v23);
      v39 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v38, v38, 85), _mm_shuffle_ps(v38, v38, 0)),
              _mm_shuffle_ps(v38, v38, 170));
      v40 = _mm_mul_ps(v15, v23[1]);
      v41 = _mm_cmplt_ps(v18, v39);
      v126 = v39;
      v42 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v40, v40, 85), _mm_shuffle_ps(v40, v40, 0)),
              _mm_shuffle_ps(v40, v40, 170));
      v43 = _mm_mul_ps(v15, v23[2]);
      v44 = _mm_cmplt_ps(v111, v42);
      v45 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v43, v43, 85), _mm_shuffle_ps(v43, v43, 0)),
              _mm_shuffle_ps(v43, v43, 170));
      v46 = _mm_mul_ps(v15, v23[3]);
      v47 = _mm_cmplt_ps(v25, v45);
      v48 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v46, v46, 85), _mm_shuffle_ps(v46, v46, 0)),
              _mm_shuffle_ps(v46, v46, 170));
      v49 = _mm_mul_ps(v16, *v24);
      v50 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v49, v49, 85), _mm_shuffle_ps(v49, v49, 0)),
              _mm_shuffle_ps(v49, v49, 170));
      v51 = _mm_mul_ps(v16, v24[1]);
      v127 = v50;
      v52 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v51, v51, 85), _mm_shuffle_ps(v51, v51, 0)),
              _mm_shuffle_ps(v51, v51, 170));
      v53 = _mm_mul_ps(v16, v24[2]);
      v54 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v53, v53, 85), _mm_shuffle_ps(v53, v53, 0)),
              _mm_shuffle_ps(v53, v53, 170));
      v55 = _mm_mul_ps(v16, v24[3]);
      v56 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v55, v55, 85), _mm_shuffle_ps(v55, v55, 0)),
              _mm_shuffle_ps(v55, v55, 170));
      v57 = _mm_cmplt_ps(v114, v48);
      v58 = _mm_cmplt_ps(v113, v50);
      v59 = _mm_cmplt_ps(v110, v56);
      v60 = _mm_cmplt_ps(v115, v54);
      v61 = _mm_cmplt_ps(v123, v52);
      v108 = _mm_or_ps(_mm_and_ps(v41, v126), _mm_andnot_ps(v41, v108));
      v111 = _mm_or_ps(_mm_and_ps(v44, v42), _mm_andnot_ps(v44, v111));
      v109 = _mm_or_ps(_mm_and_ps(v47, v45), _mm_andnot_ps(v47, v109));
      v114 = _mm_or_ps(_mm_and_ps(v57, v48), _mm_andnot_ps(v57, v114));
      v120 = _mm_or_ps(_mm_and_ps(v41, *v23), _mm_andnot_ps(v41, v120));
      v113 = _mm_or_ps(_mm_and_ps(v58, v127), _mm_andnot_ps(v58, v113));
      v117 = _mm_or_ps(_mm_and_ps(v44, v23[1]), _mm_andnot_ps(v44, v117));
      v31 = _mm_or_ps(_mm_and_ps(v61, v52), _mm_andnot_ps(v61, v123));
      v123 = v31;
      v119 = _mm_or_ps(_mm_and_ps(v47, v23[2]), _mm_andnot_ps(v47, v119));
      v62 = _mm_or_ps(_mm_and_ps(v57, v23[3]), _mm_andnot_ps(v57, v112));
      v115 = _mm_or_ps(_mm_and_ps(v60, v54), _mm_andnot_ps(v60, v115));
      v112 = v62;
      v63 = _mm_and_ps(v59, v56);
      v64 = _mm_or_ps(_mm_and_ps(v58, *v24), _mm_andnot_ps(v58, v121));
      v110 = _mm_or_ps(v63, _mm_andnot_ps(v59, v110));
      v18 = v108;
      v16 = v125;
      v15 = m_quad;
      v23 += 4;
      v24 += 4;
      v121 = v64;
      v65 = _mm_or_ps(_mm_and_ps(v60, v24[-2]), _mm_andnot_ps(v60, v122));
      v25 = v109;
      v118 = _mm_or_ps(_mm_and_ps(v61, v24[-3]), _mm_andnot_ps(v61, v118));
      v122 = v65;
      v116 = _mm_or_ps(_mm_and_ps(v59, v24[-1]), _mm_andnot_ps(v59, v116));
      --v37;
    }
    while ( v37 );
    v20 = v111;
    v27 = v114;
    v11 = v62;
  }
  if ( v22 > 0 )
  {
    v66 = ((unsigned int)(v22 - 1) >> 2) + 1;
    while ( 1 )
    {
      v67 = _mm_mul_ps(*v23, v15);
      v68 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v67, v67, 85), _mm_shuffle_ps(v67, v67, 0)),
              _mm_shuffle_ps(v67, v67, 170));
      v69 = _mm_mul_ps(v23[1], v15);
      v70 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v69, v69, 85), _mm_shuffle_ps(v69, v69, 0)),
              _mm_shuffle_ps(v69, v69, 170));
      v71 = _mm_mul_ps(v23[2], v15);
      v72 = _mm_cmplt_ps(v20, v70);
      v73 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v71, v71, 85), _mm_shuffle_ps(v71, v71, 0)),
              _mm_shuffle_ps(v71, v71, 170));
      v74 = _mm_mul_ps(v23[3], v15);
      v75 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v74, v74, 85), _mm_shuffle_ps(v74, v74, 0)),
              _mm_shuffle_ps(v74, v74, 170));
      v76 = _mm_cmplt_ps(v18, v68);
      v77 = _mm_cmplt_ps(v109, v73);
      v78 = _mm_cmplt_ps(v27, v75);
      v20 = _mm_or_ps(_mm_andnot_ps(v72, v20), _mm_and_ps(v70, v72));
      v108 = _mm_or_ps(_mm_andnot_ps(v76, v108), _mm_and_ps(v68, v76));
      v27 = _mm_or_ps(_mm_andnot_ps(v78, v27), _mm_and_ps(v75, v78));
      v120 = _mm_or_ps(_mm_andnot_ps(v76, v120), _mm_and_ps(*v23, v76));
      v25 = _mm_or_ps(_mm_andnot_ps(v77, v109), _mm_and_ps(v73, v77));
      v109 = v25;
      v117 = _mm_or_ps(_mm_andnot_ps(v72, v117), _mm_and_ps(v23[1], v72));
      v79 = _mm_or_ps(_mm_andnot_ps(v77, v119), _mm_and_ps(v23[2], v77));
      v80 = v78;
      v81 = _mm_and_ps(v23[3], v78);
      v15 = m_quad;
      v23 += 4;
      v119 = v79;
      v11 = _mm_or_ps(_mm_andnot_ps(v80, v112), v81);
      v112 = v11;
      if ( !--v66 )
        break;
      v18 = v108;
    }
    v31 = v123;
    v114 = v27;
    v111 = v20;
  }
  if ( v33 <= 0 )
  {
    v97 = v118;
    v100 = v116;
  }
  else
  {
    v82 = v113;
    v83 = v115;
    v84 = ((unsigned int)(v33 - 1) >> 2) + 1;
    do
    {
      v85 = _mm_mul_ps(*v24, v125);
      v86 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v85, v85, 85), _mm_shuffle_ps(v85, v85, 0)),
              _mm_shuffle_ps(v85, v85, 170));
      v87 = _mm_mul_ps(v24[1], v125);
      v88 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v87, v87, 85), _mm_shuffle_ps(v87, v87, 0)),
              _mm_shuffle_ps(v87, v87, 170));
      v89 = _mm_mul_ps(v24[2], v125);
      v90 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v89, v89, 85), _mm_shuffle_ps(v89, v89, 0)),
              _mm_shuffle_ps(v89, v89, 170));
      v91 = _mm_mul_ps(v24[3], v125);
      v92 = _mm_cmplt_ps(v83, v90);
      v93 = _mm_cmplt_ps(v31, v88);
      v94 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v91, v91, 85), _mm_shuffle_ps(v91, v91, 0)),
              _mm_shuffle_ps(v91, v91, 170));
      v95 = _mm_cmplt_ps(v82, v86);
      v96 = _mm_cmplt_ps(v110, v94);
      v82 = _mm_or_ps(_mm_andnot_ps(v95, v82), _mm_and_ps(v86, v95));
      v31 = _mm_or_ps(_mm_andnot_ps(v93, v31), _mm_and_ps(v88, v93));
      v83 = _mm_or_ps(_mm_and_ps(v90, v92), _mm_andnot_ps(v92, v83));
      v110 = _mm_or_ps(_mm_and_ps(v94, v96), _mm_andnot_ps(v96, v110));
      v121 = _mm_or_ps(_mm_andnot_ps(v95, v121), _mm_and_ps(*v24, v95));
      v97 = _mm_or_ps(_mm_andnot_ps(v93, v118), _mm_and_ps(v24[1], v93));
      v118 = v97;
      v98 = _mm_and_ps(v24[2], v92);
      v99 = _mm_and_ps(v24[3], v96);
      v24 += 4;
      v122 = _mm_or_ps(_mm_andnot_ps(v92, v122), v98);
      v100 = _mm_or_ps(_mm_andnot_ps(v96, v116), v99);
      v116 = v100;
      --v84;
    }
    while ( v84 );
    v25 = v109;
    v11 = v112;
    v115 = v83;
    v20 = v111;
    v113 = v82;
    v27 = v114;
  }
  v101 = _mm_cmplt_ps(v115, v110);
  v102 = _mm_cmplt_ps(v108, v20);
  v103 = _mm_cmplt_ps(v113, v31);
  v104 = _mm_cmplt_ps(v25, v27);
  v105 = _mm_cmplt_ps(
           _mm_or_ps(_mm_andnot_ps(v104, v25), _mm_and_ps(v27, v104)),
           _mm_or_ps(_mm_andnot_ps(v102, v108), _mm_and_ps(v20, v102)));
  v106 = _mm_cmplt_ps(
           _mm_or_ps(_mm_and_ps(v101, v110), _mm_andnot_ps(v101, v115)),
           _mm_or_ps(_mm_and_ps(v31, v103), _mm_andnot_ps(v103, v113)));
  v107 = _mm_or_ps(
           _mm_andnot_ps(v106, _mm_or_ps(_mm_and_ps(v100, v101), _mm_andnot_ps(v101, v122))),
           _mm_and_ps(_mm_or_ps(_mm_and_ps(v97, v103), _mm_andnot_ps(v103, v121)), v106));
  vertexBinAout->m_quad = _mm_add_ps(
                            _mm_add_ps(
                              _mm_add_ps(
                                _mm_mul_ps(_mm_shuffle_ps(v107, v107, 85), aTb->m_rotation.m_col1.m_quad),
                                _mm_mul_ps(_mm_shuffle_ps(v107, v107, 0), aTb->m_rotation.m_col0.m_quad)),
                              _mm_mul_ps(_mm_shuffle_ps(v107, v107, 170), aTb->m_rotation.m_col2.m_quad)),
                            aTb->m_translation.m_quad);
  vertexAinAOut->m_quad = _mm_or_ps(
                            _mm_andnot_ps(v105, _mm_or_ps(_mm_andnot_ps(v104, v119), _mm_and_ps(v11, v104))),
                            _mm_and_ps(_mm_or_ps(_mm_andnot_ps(v102, v120), _mm_and_ps(v117, v102)), v105));
  *vertexBinBOut = (hkcdVertex)v107;
}

// File Line: 75
// RVA: 0x130D920
__int64 __fastcall hkcdGsk::getClosestPoint(hkcdVertex *vertsA, int numVertsA, hkcdVertex *vertsB, int numVertsB)
{
  char *v4; // r15
  hkcdVertex *v5; // r11
  hkcdVertex *m_verticesBinA; // r9
  char *v7; // r10
  int v8; // edx
  int v9; // eax
  int v10; // ebx
  __int64 v11; // rcx
  hkcdVertex *v12; // r8
  __m128 *v13; // r11
  int v14; // ebx
  char *v15; // r10
  __m128 *v16; // r9
  __int64 v17; // r8
  hkTransformf *aTb; // rsi
  __m128 v19; // xmm10
  hkVector4f v20; // xmm13
  __int64 v21; // rcx
  hkVector4f v22; // xmm3
  __int64 v23; // rax
  hkVector4f v24; // xmm4
  hkVector4f v25; // xmm5
  hkVector4f v26; // xmm6
  __m128 v27; // xmm1
  unsigned int v28; // r14d
  hkVector4f v29; // xmm12
  __m128 v30; // xmm2
  __m128 v31; // xmm15
  unsigned int v32; // eax
  __m128 v33; // xmm11
  hkcdVertex *m_verticesA; // rdx
  hkcdVertex *v35; // rcx
  __m128 v36; // xmm5
  __m128 v37; // xmm6
  __m128 v38; // xmm7
  __m128 v39; // xmm14
  __m128 v40; // xmm2
  __m128 v41; // xmm2
  __m128 v42; // xmm1
  __m128 v43; // xmm4
  __m128 v44; // xmm1
  __m128 v45; // xmm2
  __m128 v46; // xmm1
  __m128 v47; // xmm3
  __m128 v48; // xmm2
  __m128 v49; // xmm1
  __m128 v50; // xmm2
  __m128 v51; // xmm0
  __m128 v52; // xmm7
  __m128 v53; // xmm3
  __m128 v54; // xmm6
  __m128 v55; // xmm5
  __m128 v56; // xmm5
  __m128 v57; // xmm1
  __m128 v58; // xmm5
  __m128 v59; // xmm4
  __m128 v60; // xmm0
  __m128 v61; // xmm2
  __m128 v62; // xmm7
  __m128 v63; // xmm1
  __m128 v64; // xmm4
  __m128 v65; // xmm1
  __m128 v66; // xmm7
  __m128 v67; // xmm2
  int v68; // ecx
  __m128 v69; // xmm1
  __m128 v70; // xmm3
  __m128 v71; // xmm14
  __m128 v72; // xmm6
  __m128 v73; // xmm8
  __m128 v74; // xmm4
  __m128 v75; // xmm9
  __m128 v76; // xmm8
  __m128 v77; // xmm7
  __m128 v78; // xmm2
  __m128 v79; // xmm5
  __m128 v80; // xmm1
  __m128 v81; // xmm13
  __m128 v82; // xmm9
  __m128 v83; // xmm9
  __m128 v84; // xmm7
  __m128 v85; // xmm0
  __m128 v86; // xmm7
  __m128 v87; // xmm8
  __m128 v88; // xmm1
  __m128 v89; // xmm8
  __m128 v90; // xmm8
  __m128 v91; // xmm2
  hkVector4f v92; // xmm9
  int v93; // r8d
  __m128 v94; // xmm15
  __m128 v95; // xmm1
  __m128 v96; // xmm2
  __m128 v97; // xmm15
  __m128 v98; // xmm1
  __m128 v99; // xmm12
  __m128 v100; // xmm9
  __m128 v101; // xmm1
  __m128 v102; // xmm2
  __m128 v103; // xmm8
  __m128 v104; // xmm7
  __m128 v105; // xmm1
  __m128 v106; // xmm4
  __m128 v107; // xmm1
  __m128 v108; // xmm2
  __m128 v109; // xmm1
  __m128 v110; // xmm3
  __m128 v111; // xmm1
  __m128 v112; // xmm1
  __m128 v113; // xmm6
  __m128 v114; // xmm0
  __m128 v115; // xmm2
  __m128 v116; // xmm0
  __m128 v117; // xmm3
  __m128 v118; // xmm1
  __m128 v119; // xmm5
  __m128 v120; // xmm0
  __m128 v121; // xmm2
  __m128 v122; // xmm1
  __m128 v123; // xmm2
  __m128 v124; // xmm11
  __m128 v125; // xmm9
  __m128 v126; // xmm1
  __m128 v127; // xmm5
  __m128 v128; // xmm1
  __m128 v129; // xmm8
  __m128 v130; // xmm1
  __m128 v131; // xmm7
  __m128 v132; // xmm5
  __m128 v133; // xmm1
  __m128 v134; // xmm3
  __m128 v135; // xmm1
  __m128 v136; // xmm4
  __m128 v137; // xmm1
  __m128 v138; // xmm2
  __m128 v139; // xmm6
  __m128 v140; // xmm0
  __m128 v141; // xmm3
  __m128 v142; // xmm0
  __m128 v143; // xmm4
  __m128 v144; // xmm3
  __m128 v145; // xmm2
  __m128 v146; // xmm0
  __m128 v147; // xmm2
  __m128 v148; // xmm2
  __m128 v149; // xmm1
  __m128 v150; // xmm8
  __m128 v151; // xmm14
  hkVector4f v152; // xmm11
  __m128 v153; // xmm1
  __m128 v154; // xmm3
  __m128 v155; // xmm1
  __m128 v156; // xmm2
  __m128 v157; // xmm0
  __m128 v158; // xmm0
  __m128 v159; // xmm1
  __m128 v160; // xmm3
  __m128 v161; // xmm6
  __m128 v162; // xmm6
  __m128 v163; // xmm7
  __m128 v164; // xmm4
  __m128 v165; // xmm5
  __m128 v166; // xmm1
  __m128 v167; // xmm6
  __m128 v168; // xmm3
  __m128 v169; // xmm0
  __m128 v170; // xmm2
  __m128 v171; // xmm7
  __m128 v172; // xmm1
  __m128 v173; // xmm3
  __m128 v174; // xmm1
  __m128 v175; // xmm7
  __m128 v176; // xmm2
  __m128 v177; // xmm1
  __m128 v178; // xmm3
  __m128 v179; // xmm6
  __m128 v180; // xmm9
  __m128 v181; // xmm5
  __m128 v182; // xmm10
  __m128 v183; // xmm7
  __m128 v184; // xmm14
  __m128 v185; // xmm10
  __m128 v186; // xmm4
  __m128 v187; // xmm7
  __m128 v188; // xmm2
  __m128 v189; // xmm8
  __m128 v190; // xmm8
  __m128 v191; // xmm10
  __m128 v192; // xmm7
  __m128 v193; // xmm10
  __m128 v194; // xmm7
  __m128 v195; // xmm1
  __m128 v196; // xmm9
  __m128 v197; // xmm9
  __m128 v198; // xmm2
  hkVector4f v199; // xmm10
  int v200; // eax
  float v201; // xmm1_4
  float v202; // xmm11_4
  float v203; // xmm1_4
  float v204; // xmm11_4
  int v205; // ecx
  __m128 v206; // xmm14
  __m128 v207; // xmm7
  __m128 v208; // xmm5
  __m128 v209; // xmm2
  __m128 v210; // xmm4
  __m128 v211; // xmm13
  __m128 v212; // xmm1
  __m128 v213; // xmm4
  __m128 v214; // xmm4
  __m128 v215; // xmm2
  __m128 v216; // xmm9
  __m128 v217; // xmm1
  __m128 v218; // xmm0
  __m128 v219; // xmm2
  __m128 v220; // xmm1
  __m128 v221; // xmm3
  __m128 v222; // xmm2
  __m128 v223; // xmm6
  __m128 v224; // xmm2
  __m128 v225; // xmm6
  int v226; // ecx
  int v227; // ecx
  int v228; // ecx
  int v229; // ecx
  __m128 v230; // xmm1
  __m128 v231; // xmm2
  __m128 v232; // xmm11
  __m128 v233; // xmm1
  __m128 v234; // xmm2
  __m128 v235; // xmm5
  __m128 v236; // xmm10
  __m128 v237; // xmm1
  __m128 v238; // xmm9
  __m128 v239; // xmm6
  __m128 v240; // xmm1
  __m128 v241; // xmm3
  __m128 v242; // xmm1
  __m128 v243; // xmm5
  __m128 v244; // xmm1
  __m128 v245; // xmm7
  __m128 v246; // xmm0
  __m128 v247; // xmm2
  __m128 v248; // xmm1
  __m128 v249; // xmm2
  __m128 v250; // xmm8
  __m128 v251; // xmm1
  __m128 v252; // xmm0
  __m128 v253; // xmm3
  __m128 v254; // xmm2
  __m128 v255; // xmm0
  __m128 v256; // xmm0
  int v257; // ecx
  float v258; // xmm1_4
  float v259; // xmm11_4
  int m_storage; // eax
  int v261; // eax
  int v262; // eax
  __m128 v263; // xmm1
  __m128 v264; // xmm3
  __m128 v265; // xmm2
  __m128 v266; // xmm6
  __m128 v267; // xmm2
  __m128 v268; // xmm3
  __m128 v269; // xmm4
  __m128 v270; // xmm1
  __m128 v271; // xmm5
  __m128 v272; // xmm1
  __m128 v273; // xmm4
  __m128 v274; // xmm2
  __m128 v275; // xmm0
  __m128 v276; // xmm3
  __m128 v277; // xmm1
  __m128 v278; // xmm10
  __m128 v279; // xmm11
  __m128 v280; // xmm7
  __m128 v281; // xmm12
  __m128 v282; // xmm9
  __m128 v283; // xmm8
  __m128 v284; // xmm2
  __m128 v285; // xmm1
  __m128 v286; // xmm14
  __m128 v287; // xmm1
  int v288; // r8d
  int v289; // r9d
  hkcdVertex *v290; // rcx
  hkcdVertex *v291; // rdx
  int v292; // eax
  __m128 v293; // xmm2
  __m128 v294; // xmm0
  __m128 v295; // xmm1
  __m128 v296; // xmm2
  __m128 v297; // xmm2
  __m128 v298; // xmm1
  __m128 v299; // xmm6
  __m128 v300; // xmm1
  __m128 v301; // xmm2
  __m128 v302; // xmm1
  __m128 v303; // xmm2
  __m128 v304; // xmm1
  __m128 v305; // xmm2
  __m128 v306; // xmm1
  __int64 v307; // r10
  __m128 v308; // xmm1
  __m128 v309; // xmm2
  __m128 v310; // xmm4
  __m128 v311; // xmm3
  __m128 v312; // xmm1
  __m128 v313; // xmm6
  __m128 v314; // xmm14
  __m128 v315; // xmm1
  __m128 v316; // xmm9
  __m128 v317; // xmm12
  __m128 v318; // xmm11
  __m128 v319; // xmm1
  __m128 v320; // xmm10
  __m128 v321; // xmm1
  __m128 v322; // xmm1
  __m128 v323; // xmm1
  __m128 v324; // xmm1
  __m128 v325; // xmm13
  __m128 v326; // xmm15
  __m128 *p_m_quad; // rcx
  __int64 v328; // r8
  __m128 v329; // xmm9
  __m128 v330; // xmm1
  __m128 v331; // xmm8
  __m128 v332; // xmm1
  __m128 v333; // xmm12
  __m128 v334; // xmm1
  __m128 v335; // xmm1
  __m128 v336; // xmm13
  __m128 v337; // xmm15
  __m128 v338; // xmm14
  __m128 *v339; // rcx
  __int64 v340; // rdx
  __m128 v341; // xmm1
  __m128 v342; // xmm8
  __m128 v343; // xmm12
  __m128 v344; // xmm1
  __m128 v345; // xmm1
  __m128 v346; // xmm6
  __m128 v347; // xmm1
  __m128 v348; // xmm9
  __m128 v349; // xmm11
  __m128 v350; // xmm14
  __m128 v351; // xmm8
  __m128 v352; // xmm6
  __m128 v353; // xmm9
  __m128 v354; // xmm5
  __m128 v355; // xmm1
  __m128 v356; // xmm4
  __m128 v357; // xmm1
  __m128 v358; // xmm2
  int v359; // eax
  __m128 v360; // xmm4
  __m128 v361; // xmm1
  __m128 v362; // xmm2
  __m128 v363; // xmm1
  __m128 v364; // xmm1
  __m128 v365; // xmm8
  __m128 v366; // xmm14
  __m128 v367; // xmm2
  __m128 v368; // xmm6
  __m128 v369; // xmm1
  __m128 v370; // xmm14
  hkcdVertex *v371; // r9
  __m128 v372; // xmm1
  __m128 v373; // xmm2
  __m128 v374; // xmm6
  __m128 v375; // xmm4
  __m128 v376; // xmm5
  __m128 v377; // xmm3
  __m128 v378; // xmm0
  __m128 v379; // xmm1
  __m128 v380; // xmm9
  __m128 v381; // xmm9
  __m128 v382; // xmm3
  __m128 v383; // xmm8
  __m128 v384; // xmm8
  __m128 v385; // xmm0
  __m128 v386; // xmm8
  __m128 v387; // xmm4
  __m128 v388; // xmm5
  __m128 v389; // xmm9
  __m128 v390; // xmm4
  __m128 v391; // xmm1
  __m128 v392; // xmm5
  __m128 v393; // xmm3
  __m128 v394; // xmm2
  __m128 v395; // xmm0
  __m128 v396; // xmm1
  __m128 v397; // xmm4
  __m128i v398; // xmm5
  __m128 v399; // xmm2
  __m128 v400; // xmm9
  __m128 v401; // xmm0
  __m128 v402; // xmm4
  __m128 v403; // xmm4
  __m128 v404; // xmm6
  int v405; // edx
  __m128 v406; // xmm2
  int v407; // eax
  int v408; // ecx
  int v409; // ebx
  __int64 v410; // rdi
  __int64 v411; // r10
  __int64 v412; // r8
  __int64 v413; // r11
  int v414; // edx
  __m128 v415; // xmm0
  __m128 v416; // xmm2
  __m128 v417; // xmm4
  __m128 v418; // xmm7
  __m128 v419; // xmm5
  __m128 v420; // xmm1
  __m128 v421; // xmm3
  __m128 v422; // xmm4
  __m128 v423; // xmm7
  __m128 v424; // xmm5
  __m128 v425; // xmm6
  __m128 v426; // xmm1
  __m128 v427; // xmm4
  __m128 v428; // xmm2
  __m128 v429; // xmm11
  __m128 v430; // xmm7
  __m128 v431; // xmm3
  __m128 v432; // xmm8
  __m128 v433; // xmm8
  __m128 v434; // xmm11
  __m128 v435; // xmm6
  __m128 v436; // xmm11
  __m128 v437; // xmm6
  __m128 v438; // xmm7
  __m128 v439; // xmm1
  __m128 v440; // xmm7
  __m128 v441; // xmm2
  hkVector4f v442; // xmm11
  int v443; // ecx
  __m128 v444; // xmm2
  hkcdVertex v445; // xmm0
  __int64 v446; // rcx
  int v447; // ecx
  __m128 v448; // xmm5
  __m128 v449; // xmm3
  __m128 v450; // xmm4
  __m128 v451; // xmm11
  __m128 v452; // xmm1
  __m128 v453; // xmm6
  __m128 v454; // xmm7
  __m128 v455; // xmm13
  __m128 v456; // xmm8
  __m128 v457; // xmm8
  __m128 v458; // xmm11
  __m128 v459; // xmm11
  __m128 v460; // xmm6
  __m128 v461; // xmm6
  __m128 v462; // xmm1
  __m128 v463; // xmm7
  __m128 v464; // xmm7
  __m128 v465; // xmm2
  hkVector4f v466; // xmm11
  int v467; // ecx
  __m128 v468; // xmm2
  hkcdVertex v469; // xmm0
  __int64 v470; // rcx
  int v471; // ecx
  __int64 v472; // r9
  __int64 v473; // rax
  __int64 v474; // rcx
  __m128 v475; // xmm0
  __m128 v476; // xmm12
  __m128 v477; // xmm3
  __m128 v478; // xmm2
  __m128 v479; // xmm3
  __m128 v480; // xmm4
  __m128 v481; // xmm9
  __m128 v482; // xmm5
  __m128 v483; // xmm1
  __m128 v484; // xmm2
  __m128 v485; // xmm1
  __m128 v486; // xmm6
  __m128 v487; // xmm4
  __m128 v488; // xmm1
  __m128 v489; // xmm2
  __m128 v490; // xmm8
  __m128 v491; // xmm8
  __m128 v492; // xmm8
  __m128 v493; // xmm2
  __int64 v494; // r9
  __int64 v495; // rax
  __int64 v496; // rcx
  __m128 v497; // xmm0
  __m128 v498; // xmm15
  __m128 v499; // xmm3
  __m128 v500; // xmm2
  __m128 v501; // xmm3
  __m128 v502; // xmm4
  __m128 v503; // xmm6
  __m128 v504; // xmm2
  __m128 v505; // xmm8
  __m128 v506; // xmm4
  __m128 v507; // xmm7
  __m128 v508; // xmm3
  __m128 v509; // xmm5
  __m128 v510; // xmm9
  __m128 v511; // xmm10
  __m128 v512; // xmm9
  __m128 v513; // xmm6
  __m128 v514; // xmm0
  __m128 v515; // xmm3
  __m128 v516; // xmm1
  __m128 v517; // xmm2
  __m128 v518; // xmm6
  __m128 v519; // xmm2
  __m128 v520; // xmm4
  __m128 v521; // xmm3
  __m128 v522; // xmm6
  __m128 v523; // xmm2
  __m128 v524; // xmm7
  __m128 v525; // xmm2
  __m128 v526; // xmm0
  __m128 v527; // xmm1
  __m128 v528; // xmm3
  __m128 v529; // xmm0
  __m128 v530; // xmm7
  hkcdGsk::GetClosestPointOutput *v531; // rax
  hkcdGsk::GetClosestPointOutput *v532; // rax
  __m128 v533; // xmm15
  __m128 v534; // xmm1
  _QWORD *Value; // rbx
  unsigned __int64 v536; // rcx
  unsigned __int64 v537; // rax
  unsigned int v538; // eax
  _QWORD *v539; // rcx
  unsigned __int64 v540; // rax
  _QWORD *v541; // rcx
  __int64 v542; // rdi
  char v543; // bl
  char v544; // r11
  char v545; // dl
  char v546; // r8
  char v547; // r9
  char v548; // r10
  __int64 result; // rax
  __m128 supportOut; // [rsp+40h] [rbp-80h]
  __m128 supportOuta; // [rsp+40h] [rbp-80h]
  __m128 v552; // [rsp+50h] [rbp-70h]
  __m128 v553; // [rsp+50h] [rbp-70h]
  hkcdGskBase v554; // [rsp+60h] [rbp-60h] BYREF
  __m128 v555; // [rsp+120h] [rbp+60h]
  __m128 v556; // [rsp+130h] [rbp+70h]
  __m128 v557; // [rsp+140h] [rbp+80h]
  hkcdVertex v558; // [rsp+150h] [rbp+90h]
  __m128 v559; // [rsp+160h] [rbp+A0h]
  __m128 v560; // [rsp+170h] [rbp+B0h]
  __m128 v561; // [rsp+180h] [rbp+C0h]
  __m128 v562; // [rsp+190h] [rbp+D0h]
  __m128 v563; // [rsp+1A0h] [rbp+E0h]
  __m128 v564; // [rsp+1B0h] [rbp+F0h]
  __m128 v565; // [rsp+1C0h] [rbp+100h]
  __m128 v566; // [rsp+1D0h] [rbp+110h]
  hkcdVertex *shapeB; // [rsp+1E0h] [rbp+120h] BYREF
  int v568; // [rsp+1E8h] [rbp+128h]
  hkcdVertex *shapeA; // [rsp+1F0h] [rbp+130h] BYREF
  int v570; // [rsp+1F8h] [rbp+138h]
  __m128 v571; // [rsp+200h] [rbp+140h]
  __m128 v572; // [rsp+210h] [rbp+150h]
  __m128 v573; // [rsp+220h] [rbp+160h]
  __m128 v574; // [rsp+230h] [rbp+170h]
  __m128 v575; // [rsp+240h] [rbp+180h]
  __m128 v576; // [rsp+250h] [rbp+190h]
  __m128 v577; // [rsp+260h] [rbp+1A0h]
  __m128 v578; // [rsp+270h] [rbp+1B0h]
  __m128 v579; // [rsp+280h] [rbp+1C0h]
  __m128 v580; // [rsp+290h] [rbp+1D0h]
  __m128 v581; // [rsp+2A0h] [rbp+1E0h]
  __m128 v582; // [rsp+2B0h] [rbp+1F0h]
  __m128 v583; // [rsp+2C0h] [rbp+200h]
  __m128 v584; // [rsp+2D0h] [rbp+210h]
  __m128 v585; // [rsp+2E0h] [rbp+220h]
  __m128 v586; // [rsp+2F0h] [rbp+230h]
  __m128 v587; // [rsp+300h] [rbp+240h]
  __m128 v588; // [rsp+310h] [rbp+250h]
  __m128 v589; // [rsp+320h] [rbp+260h]
  __m128 v590; // [rsp+330h] [rbp+270h]
  __m128 v591; // [rsp+340h] [rbp+280h]
  __m128 v592; // [rsp+350h] [rbp+290h]
  __int128 v593; // [rsp+360h] [rbp+2A0h]
  __m128 v594; // [rsp+370h] [rbp+2B0h]
  __m128 v595; // [rsp+380h] [rbp+2C0h]
  __m128 v596; // [rsp+390h] [rbp+2D0h]
  __m128 v597; // [rsp+3A0h] [rbp+2E0h]
  __m128 v598; // [rsp+3B0h] [rbp+2F0h]
  __m128 v599; // [rsp+3C0h] [rbp+300h]
  __m128 v600; // [rsp+3D0h] [rbp+310h]
  __m128 v601; // [rsp+3E0h] [rbp+320h]
  __m128 v602[7]; // [rsp+3F0h] [rbp+330h] BYREF
  hkVector4f v603; // [rsp+460h] [rbp+3A0h] BYREF
  __m128 v604; // [rsp+470h] [rbp+3B0h]
  __m128 v605; // [rsp+480h] [rbp+3C0h]
  __m128 v606; // [rsp+490h] [rbp+3D0h]
  __m128 v607; // [rsp+4A0h] [rbp+3E0h]
  __m128 v608; // [rsp+4B0h] [rbp+3F0h]
  __m128 v609; // [rsp+4C0h] [rbp+400h]
  __m128 v610; // [rsp+4D0h] [rbp+410h]
  __m128 v611; // [rsp+4E0h] [rbp+420h]
  __m128 v612; // [rsp+4F0h] [rbp+430h]
  __m128 v613; // [rsp+500h] [rbp+440h]
  __m128 v614; // [rsp+510h] [rbp+450h]
  hkVector4f v615; // [rsp+520h] [rbp+460h]
  __m128 m_quad; // [rsp+530h] [rbp+470h]
  __m128 v617; // [rsp+540h] [rbp+480h]
  __m128 v618; // [rsp+550h] [rbp+490h]
  __m128 v619; // [rsp+560h] [rbp+4A0h]
  __int128 v620; // [rsp+570h] [rbp+4B0h]
  __m128 v621; // [rsp+580h] [rbp+4C0h]
  __m128 v622; // [rsp+590h] [rbp+4D0h]
  __m128 v623; // [rsp+5A0h] [rbp+4E0h]
  __m128 v624; // [rsp+5B0h] [rbp+4F0h]
  __m128 v625; // [rsp+5C0h] [rbp+500h]
  __m128 v626; // [rsp+5D0h] [rbp+510h]
  __m128 v627; // [rsp+5E0h] [rbp+520h]
  __m128 v628; // [rsp+5F0h] [rbp+530h]
  __m128 v629; // [rsp+600h] [rbp+540h]
  __m128 v630; // [rsp+610h] [rbp+550h]
  __m128 v631; // [rsp+620h] [rbp+560h]
  __m128 v632; // [rsp+630h] [rbp+570h]
  __m128 v633; // [rsp+640h] [rbp+580h]
  __m128 v634; // [rsp+650h] [rbp+590h]
  __m128 v635; // [rsp+660h] [rbp+5A0h]
  __m128 v636; // [rsp+670h] [rbp+5B0h]
  __m128 v637; // [rsp+680h] [rbp+5C0h]
  __m128 v638; // [rsp+690h] [rbp+5D0h]
  __m128 v639; // [rsp+6A0h] [rbp+5E0h]
  __m128 v640; // [rsp+6B0h] [rbp+5F0h]
  __m128 v641; // [rsp+6C0h] [rbp+600h]
  __m128 v642; // [rsp+6D0h] [rbp+610h]
  __m128 v643; // [rsp+6E0h] [rbp+620h]
  __m128 v644; // [rsp+6F0h] [rbp+630h]
  __m128 v645; // [rsp+700h] [rbp+640h]
  __m128 v646; // [rsp+710h] [rbp+650h]
  __m128 v647; // [rsp+720h] [rbp+660h]
  __m128 v648; // [rsp+730h] [rbp+670h]
  __m128 v649; // [rsp+740h] [rbp+680h]
  __m128 v650; // [rsp+750h] [rbp+690h]
  __m128 v651; // [rsp+760h] [rbp+6A0h]
  __m128 v652; // [rsp+770h] [rbp+6B0h]
  __m128 v653; // [rsp+780h] [rbp+6C0h]
  __m128 v654; // [rsp+790h] [rbp+6D0h]
  __m128 v655; // [rsp+7A0h] [rbp+6E0h]
  __m128 v656; // [rsp+7B0h] [rbp+6F0h]
  __m128 v657; // [rsp+7C0h] [rbp+700h]
  __m128 v658; // [rsp+7D0h] [rbp+710h]
  __m128 v659; // [rsp+7E0h] [rbp+720h]
  __m128 v660; // [rsp+7F0h] [rbp+730h]
  __m128 v661; // [rsp+800h] [rbp+740h]
  __m128 v662; // [rsp+810h] [rbp+750h]
  __m128 v663; // [rsp+820h] [rbp+760h]
  __m128 v664; // [rsp+830h] [rbp+770h]
  __m128 v665; // [rsp+840h] [rbp+780h]
  __m128 v666; // [rsp+850h] [rbp+790h]
  __m128 v667; // [rsp+860h] [rbp+7A0h]
  __m128 v668; // [rsp+870h] [rbp+7B0h]
  __m128 v669; // [rsp+880h] [rbp+7C0h]
  __m128 v670; // [rsp+890h] [rbp+7D0h]
  __m128 v671; // [rsp+8A0h] [rbp+7E0h]
  __m128 v672; // [rsp+8B0h] [rbp+7F0h]
  __m128 v673; // [rsp+8C0h] [rbp+800h]
  __m128 v674; // [rsp+8D0h] [rbp+810h]
  __m128 v675; // [rsp+8E0h] [rbp+820h]
  __m128 v676; // [rsp+8F0h] [rbp+830h]
  __m128 v677; // [rsp+900h] [rbp+840h]
  __m128 v678; // [rsp+910h] [rbp+850h]
  __m128 v679; // [rsp+920h] [rbp+860h]
  __m128 v680; // [rsp+930h] [rbp+870h]
  __m128 v681; // [rsp+940h] [rbp+880h]
  __m128 v682; // [rsp+950h] [rbp+890h]
  __m128 v683; // [rsp+960h] [rbp+8A0h]
  __m128 v684; // [rsp+970h] [rbp+8B0h]
  __m128 v685; // [rsp+980h] [rbp+8C0h]
  __m128 v686; // [rsp+990h] [rbp+8D0h]
  __m128 v687; // [rsp+9A0h] [rbp+8E0h]
  __m128 v688; // [rsp+9B0h] [rbp+8F0h]
  __m128 v689; // [rsp+9C0h] [rbp+900h]
  __m128 v690; // [rsp+9D0h] [rbp+910h]
  __m128 v691; // [rsp+9E0h] [rbp+920h]
  __m128 v692; // [rsp+9F0h] [rbp+930h]
  __m128 v693; // [rsp+A00h] [rbp+940h]
  __m128 v694; // [rsp+A10h] [rbp+950h]
  __m128 v695; // [rsp+A20h] [rbp+960h]
  __m128 v696; // [rsp+A30h] [rbp+970h]
  __m128 v697; // [rsp+A40h] [rbp+980h]
  __m128 v698; // [rsp+A50h] [rbp+990h]
  __m128 v699; // [rsp+A60h] [rbp+9A0h]
  __m128 v700; // [rsp+A70h] [rbp+9B0h]
  int v701; // [rsp+B70h] [rbp+AB0h]
  hkPadSpu<int> dimA; // [rsp+B78h] [rbp+AB8h] BYREF
  hkcdGskBase::ShapeInterface shapeInterface; // [rsp+B80h] [rbp+AC0h] BYREF
  hkPadSpu<int> dimB; // [rsp+B88h] [rbp+AC8h] BYREF
  hkTransformf *v705; // [rsp+B90h] [rbp+AD0h]
  char *v706; // [rsp+B98h] [rbp+AD8h]
  hkcdGsk::GetClosestPointOutput *vars0; // [rsp+BA0h] [rbp+AE0h]

  v4 = v706;
  v570 = numVertsA;
  v568 = numVertsB;
  shapeA = vertsA;
  shapeB = vertsB;
  v5 = vertsA;
  m_verticesBinA = v554.m_verticesBinA;
  v7 = v706;
  shapeInterface.vfptr = (hkcdGskBase::ShapeInterfaceVtbl *)&hkcdGsk_Vector4ShapeInterface::`vftable;
  v8 = (unsigned __int8)v706[4] >> 6;
  v9 = v706[4] & 3;
  v10 = v8;
  while ( 1 )
  {
    v11 = (unsigned __int8)*v7;
    v12 = m_verticesBinA++;
    ++v7;
    *v12 = v5[v11];
    if ( !--v10 )
      break;
    v5 = shapeA;
  }
  v13 = v602;
  v14 = v9;
  v15 = &v4[(unsigned __int64)(unsigned __int8)v4[4] >> 6];
  do
  {
    v16 = v13;
    v17 = (unsigned __int8)*v15;
    ++v13;
    ++v15;
    *v16 = shapeB[v17].m_quad;
    --v14;
  }
  while ( v14 );
  aTb = v705;
  dimB.m_storage = v9;
  dimA.m_storage = v8;
  v19 = 0i64;
  v20.m_quad = 0i64;
  *(_OWORD *)&v554.m_lastDimB.m_storage = 0i64;
  v21 = v9 - 1;
  v22.m_quad = (__m128)v705->m_rotation.m_col0;
  v23 = v21;
  v615.m_quad = (__m128)v705->m_rotation.m_col0;
  v24.m_quad = (__m128)v705->m_rotation.m_col1;
  m_quad = v24.m_quad;
  v25.m_quad = (__m128)v705->m_rotation.m_col2;
  v617 = v25.m_quad;
  v26.m_quad = (__m128)v705->m_translation;
  v618 = v26.m_quad;
  do
  {
    v27 = v602[v23--];
    --v21;
    v554.m_verticesBinA[v23 + 1].m_quad = _mm_add_ps(
                                            _mm_add_ps(
                                              _mm_add_ps(
                                                _mm_mul_ps(_mm_shuffle_ps(v27, v27, 85), v24.m_quad),
                                                _mm_mul_ps(_mm_shuffle_ps(v27, v27, 0), v22.m_quad)),
                                              _mm_mul_ps(_mm_shuffle_ps(v27, v27, 170), v25.m_quad)),
                                            v26.m_quad);
  }
  while ( v21 >= 0 );
  v28 = 0;
  v29.m_quad = _mm_shuffle_ps(
                 v554.m_verticesBinA[0].m_quad,
                 _mm_unpackhi_ps(v554.m_verticesBinA[0].m_quad, v602[0]),
                 196);
  v554.m_verticesBinA[0] = (hkcdVertex)v29.m_quad;
  v554.m_verticesBinA[1].m_quad = _mm_shuffle_ps(
                                    v554.m_verticesBinA[1].m_quad,
                                    _mm_unpackhi_ps(v554.m_verticesBinA[1].m_quad, v602[1]),
                                    196);
  *(float *)&v706 = FLOAT_0_0000099999997;
  v554.m_verticesBinA[2].m_quad = _mm_shuffle_ps(
                                    v554.m_verticesBinA[2].m_quad,
                                    _mm_unpackhi_ps(v554.m_verticesBinA[2].m_quad, v602[2]),
                                    196);
  v30 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_0000099999997), (__m128)LODWORD(FLOAT_0_0000099999997), 0);
LABEL_9:
  v31 = v554.m_verticesA[0].m_quad;
  LODWORD(v706) = aTb[1].m_rotation.m_col2.m_quad.m128_i32[0];
  v554.m_checkTriangleDots = (hkVector4f)v29.m_quad;
  v32 = (dimB.m_storage | (8 * dimA.m_storage)) - 9;
  v587 = _mm_mul_ps(v30, _mm_shuffle_ps((__m128)(unsigned int)v706, (__m128)(unsigned int)v706, 0));
  v33 = query.m_quad;
  supportOut = query.m_quad;
  while ( 2 )
  {
    switch ( v32 )
    {
      case 0u:
        goto LABEL_146;
      case 1u:
        goto LABEL_90;
      case 2u:
        goto LABEL_120;
      case 3u:
        v370 = v31;
        v371 = v554.m_verticesBinA;
        goto LABEL_97;
      case 8u:
        goto LABEL_136;
      case 9u:
        goto LABEL_44;
      case 0xAu:
        m_verticesA = v554.m_verticesA;
        v35 = v554.m_verticesBinA;
        goto LABEL_13;
      case 0x10u:
        goto LABEL_112;
      case 0x11u:
        m_verticesA = v554.m_verticesBinA;
        v35 = v554.m_verticesA;
LABEL_13:
        if ( v554.m_lastDimB.m_storage == 2 )
        {
          v36 = v35->m_quad;
          v37 = m_verticesA->m_quad;
          v38 = m_verticesA[1].m_quad;
          v558.m_quad = (__m128)v35[1];
          v39 = _mm_sub_ps(v558.m_quad, v35[2].m_quad);
          v552 = v39;
          v555 = _mm_sub_ps(v36, v35[2].m_quad);
          v40 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v555, v555, 201), v39),
                  _mm_mul_ps(_mm_shuffle_ps(v39, v39, 201), v555));
          v41 = _mm_shuffle_ps(v40, v40, 201);
          v42 = _mm_mul_ps(_mm_sub_ps(v37, v36), v41);
          v43 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v42, v42, 85), _mm_shuffle_ps(v42, v42, 0)),
                  _mm_shuffle_ps(v42, v42, 170));
          v44 = _mm_mul_ps(_mm_sub_ps(v38, v36), v41);
          v45 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v44, v44, 85), _mm_shuffle_ps(v44, v44, 0)),
                  _mm_shuffle_ps(v44, v44, 170));
          v46 = _mm_mul_ps(v43, v43);
          v47 = _mm_mul_ps(v45, v45);
          if ( _mm_movemask_ps(_mm_mul_ps(v43, v45)) )
          {
            v674 = _mm_sub_ps(v43, v45);
            v48 = _mm_rcp_ps(v674);
            v605 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v48, v674)), v48), v43);
            v49 = _mm_sub_ps(v35[1].m_quad, v35->m_quad);
            v50 = _mm_add_ps(
                    _mm_mul_ps(_mm_sub_ps(m_verticesA[1].m_quad, m_verticesA->m_quad), v605),
                    m_verticesA->m_quad);
            v51 = _mm_sub_ps(v35[2].m_quad, v35->m_quad);
            v52 = _mm_sub_ps(v35[1].m_quad, v50);
            v53 = _mm_sub_ps(v35[2].m_quad, v50);
            v54 = _mm_sub_ps(v35->m_quad, v50);
            v55 = _mm_sub_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v51, v51, 201), v49),
                    _mm_mul_ps(_mm_shuffle_ps(v49, v49, 201), v51));
            v56 = _mm_shuffle_ps(v55, v55, 201);
            v57 = _mm_shuffle_ps(v56, v56, 210);
            v58 = _mm_shuffle_ps(v56, v56, 201);
            v59 = _mm_mul_ps(
                    _mm_sub_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v53, v53, 201), v57),
                      _mm_mul_ps(_mm_shuffle_ps(v53, v53, 210), v58)),
                    v52);
            v60 = _mm_shuffle_ps(v52, v52, 210);
            v61 = _mm_mul_ps(
                    _mm_sub_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v54, v54, 201), v57),
                      _mm_mul_ps(_mm_shuffle_ps(v54, v54, 210), v58)),
                    v53);
            v62 = _mm_mul_ps(_mm_shuffle_ps(v52, v52, 201), v57);
            v63 = v59;
            v64 = _mm_unpackhi_ps(v59, v61);
            v65 = _mm_unpacklo_ps(v63, v61);
            v66 = _mm_mul_ps(_mm_sub_ps(v62, _mm_mul_ps(v60, v58)), v54);
            v67 = _mm_movelh_ps(v65, v66);
            if ( (_mm_movemask_ps(
                    _mm_cmplt_ps(
                      v19,
                      _mm_add_ps(
                        _mm_shuffle_ps(v64, v66, 228),
                        _mm_add_ps(v67, _mm_shuffle_ps(_mm_movehl_ps(v67, v65), v66, 212))))) & 7) == 7 )
            {
              v68 = 1;
              goto LABEL_40;
            }
            goto LABEL_23;
          }
          v69 = _mm_cmplt_ps(v46, v47);
          v70 = v35[2].m_quad;
          v71 = _mm_or_ps(_mm_andnot_ps(v69, v38), _mm_and_ps(v69, v37));
          v72 = _mm_sub_ps(v36, v70);
          v73 = v35[1].m_quad;
          v74 = _mm_sub_ps(v70, v73);
          v75 = _mm_sub_ps(v71, v73);
          v76 = _mm_sub_ps(v73, v36);
          v77 = _mm_sub_ps(v71, v70);
          v78 = _mm_shuffle_ps(v74, v74, 201);
          v79 = _mm_shuffle_ps(v72, v72, 201);
          v80 = _mm_sub_ps(v71, v35->m_quad);
          v81 = _mm_sub_ps(_mm_mul_ps(v74, v79), _mm_mul_ps(v72, v78));
          v20.m_quad = _mm_shuffle_ps(v81, v81, 201);
          *(hkVector4f *)&v554.m_lastDimB.m_storage = (hkVector4f)v20.m_quad;
          v82 = _mm_sub_ps(_mm_mul_ps(v75, v78), _mm_mul_ps(_mm_shuffle_ps(v75, v75, 201), v74));
          v83 = _mm_mul_ps(_mm_shuffle_ps(v82, v82, 201), v20.m_quad);
          v84 = _mm_sub_ps(_mm_mul_ps(v77, v79), _mm_mul_ps(_mm_shuffle_ps(v77, v77, 201), v72));
          v85 = _mm_mul_ps(_mm_shuffle_ps(v80, v80, 201), v76);
          v86 = _mm_mul_ps(_mm_shuffle_ps(v84, v84, 201), v20.m_quad);
          v87 = _mm_mul_ps(_mm_shuffle_ps(v76, v76, 201), v80);
          v88 = _mm_unpacklo_ps(v83, v86);
          v89 = _mm_sub_ps(v87, v85);
          v90 = _mm_mul_ps(_mm_shuffle_ps(v89, v89, 201), v20.m_quad);
          v91 = _mm_movelh_ps(v88, v90);
          v92.m_quad = _mm_add_ps(
                         _mm_shuffle_ps(_mm_unpackhi_ps(v83, v86), v90, 228),
                         _mm_add_ps(v91, _mm_shuffle_ps(_mm_movehl_ps(v91, v88), v90, 212)));
          v93 = _mm_movemask_ps(_mm_cmplt_ps(v92.m_quad, v19)) & 7;
          if ( v93 == 7 )
          {
            v94 = _mm_mul_ps(_mm_sub_ps(v31, v29.m_quad), v20.m_quad);
            if ( _mm_movemask_ps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v94, v94, 85), _mm_shuffle_ps(v94, v94, 0)),
                     _mm_shuffle_ps(v94, v94, 170))) )
            {
              v95 = v35->m_quad;
              v20.m_quad = _mm_xor_ps(
                             v20.m_quad,
                             (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0));
              *v35 = (hkcdVertex)v558.m_quad;
              v35[1] = (hkcdVertex)v95;
              v33 = query.m_quad;
              *(hkVector4f *)&v554.m_lastDimB.m_storage = (hkVector4f)v20.m_quad;
              v92.m_quad = _mm_shuffle_ps(v92.m_quad, v92.m_quad, 225);
              supportOut = query.m_quad;
            }
          }
          v554.m_checkTriangleDots = (hkVector4f)v92.m_quad;
          if ( v93 != 7 )
          {
            v39 = v552;
LABEL_23:
            v96 = _mm_sub_ps(v35[2].m_quad, m_verticesA->m_quad);
            v97 = _mm_sub_ps(m_verticesA[1].m_quad, m_verticesA->m_quad);
            v98 = _mm_mul_ps(v97, v39);
            v99 = _mm_mul_ps(v97, v97);
            v100 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v98, v98, 85), _mm_shuffle_ps(v98, v98, 0)),
                     _mm_shuffle_ps(v98, v98, 170));
            v101 = _mm_mul_ps(v96, v97);
            v102 = _mm_mul_ps(v96, v39);
            v103 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v101, v101, 85), _mm_shuffle_ps(v101, v101, 0)),
                     _mm_shuffle_ps(v101, v101, 170));
            v104 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v102, v102, 85), _mm_shuffle_ps(v102, v102, 0)),
                     _mm_shuffle_ps(v102, v102, 170));
            v105 = _mm_mul_ps(v39, v39);
            v607 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v99, v99, 85), _mm_shuffle_ps(v99, v99, 0)),
                     _mm_shuffle_ps(v99, v99, 170));
            v609 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v105, v105, 85), _mm_shuffle_ps(v105, v105, 0)),
                     _mm_shuffle_ps(v105, v105, 170));
            v106 = _mm_max_ps(_mm_sub_ps(_mm_mul_ps(v609, v607), _mm_mul_ps(v100, v100)), *(__m128 *)&epsilon);
            v107 = _mm_rcp_ps(v106);
            v611 = v106;
            v108 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v107, v106)), v107);
            v109 = _mm_rcp_ps(v609);
            v613 = v108;
            v110 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v109, v609)), v109);
            v111 = _mm_rcp_ps(v607);
            v700 = v110;
            v694 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v111, v607)), v111);
            v112 = _mm_cmple_ps(v106, *(__m128 *)&epsilon);
            v113 = _mm_sub_ps(_mm_mul_ps(v609, v103), _mm_mul_ps(v104, v100));
            v114 = _mm_cmplt_ps(v113, v106);
            v115 = _mm_sub_ps(
                     _mm_mul_ps(
                       _mm_or_ps(
                         _mm_andnot_ps(
                           v112,
                           _mm_mul_ps(
                             _mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_and_ps(v113, v114), _mm_andnot_ps(v114, v106))),
                             v108)),
                         _mm_and_ps(v112, v33)),
                       _mm_mul_ps(v110, v100)),
                     _mm_mul_ps(v110, v104));
            v116 = _mm_cmplt_ps(v115, v33);
            v117 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v115, v116), _mm_andnot_ps(v116, v33)));
            v118 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v694, v100), v117), _mm_mul_ps(v694, v103));
            v119 = v35[2].m_quad;
            v120 = _mm_cmplt_ps(v118, v33);
            v121 = _mm_sub_ps(
                     _mm_add_ps(
                       _mm_mul_ps(
                         _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v118, v120), _mm_andnot_ps(v120, v33))),
                         v97),
                       m_verticesA->m_quad),
                     _mm_add_ps(_mm_mul_ps(v117, v552), v119));
            v122 = _mm_mul_ps(v97, v555);
            v123 = _mm_mul_ps(v121, v121);
            v124 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v123, v123, 85), _mm_shuffle_ps(v123, v123, 0)),
                     _mm_shuffle_ps(v123, v123, 170));
            v125 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v122, v122, 85), _mm_shuffle_ps(v122, v122, 0)),
                     _mm_shuffle_ps(v122, v122, 170));
            v126 = _mm_sub_ps(v119, m_verticesA->m_quad);
            v127 = _mm_mul_ps(v126, v555);
            v128 = _mm_mul_ps(v126, v97);
            v129 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v128, v128, 85), _mm_shuffle_ps(v128, v128, 0)),
                     _mm_shuffle_ps(v128, v128, 170));
            v130 = _mm_mul_ps(v555, v555);
            v131 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v127, v127, 85), _mm_shuffle_ps(v127, v127, 0)),
                     _mm_shuffle_ps(v127, v127, 170));
            v602[6] = v607;
            v644 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v130, v130, 85), _mm_shuffle_ps(v130, v130, 0)),
                     _mm_shuffle_ps(v130, v130, 170));
            v132 = _mm_max_ps(_mm_sub_ps(_mm_mul_ps(v644, v607), _mm_mul_ps(v125, v125)), *(__m128 *)&epsilon);
            v133 = _mm_rcp_ps(v132);
            v604 = v132;
            v134 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v133, v132)), v133);
            v135 = _mm_rcp_ps(v644);
            v602[3] = v134;
            v136 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v135, v644)), v135);
            v137 = _mm_rcp_ps(v607);
            v606 = v136;
            v138 = _mm_cmple_ps(v132, *(__m128 *)&epsilon);
            v139 = _mm_sub_ps(_mm_mul_ps(v644, v129), _mm_mul_ps(v131, v125));
            v649 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v137, v607)), v137);
            v140 = _mm_cmplt_ps(v139, v132);
            v19 = 0i64;
            v141 = _mm_sub_ps(
                     _mm_mul_ps(
                       _mm_or_ps(
                         _mm_andnot_ps(
                           v138,
                           _mm_mul_ps(
                             _mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_and_ps(v140, v139), _mm_andnot_ps(v140, v132))),
                             v134)),
                         _mm_and_ps(v138, supportOut)),
                       _mm_mul_ps(v136, v125)),
                     _mm_mul_ps(v136, v131));
            v142 = _mm_cmplt_ps(v141, supportOut);
            v143 = v35[2].m_quad;
            v20.m_quad = *(__m128 *)&v554.m_lastDimB.m_storage;
            v144 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v142, v141), _mm_andnot_ps(v142, supportOut)));
            v145 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v649, v125), v144), _mm_mul_ps(v649, v129));
            v146 = _mm_cmplt_ps(v145, supportOut);
            v147 = _mm_sub_ps(
                     _mm_add_ps(
                       _mm_mul_ps(
                         _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v146, v145), _mm_andnot_ps(v146, supportOut))),
                         v97),
                       m_verticesA->m_quad),
                     _mm_add_ps(_mm_mul_ps(v144, v555), v143));
            v148 = _mm_mul_ps(v147, v147);
            v149 = _mm_cmplt_ps(
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v148, v148, 85), _mm_shuffle_ps(v148, v148, 0)),
                       _mm_shuffle_ps(v148, v148, 170)),
                     v124);
            v35->m_quad = _mm_or_ps(_mm_and_ps(v35->m_quad, v149), _mm_andnot_ps(v149, v35[1].m_quad));
            v35[1] = (hkcdVertex)v143;
LABEL_38:
            v68 = 2;
            goto LABEL_39;
          }
          *m_verticesA = (hkcdVertex)v71;
          v68 = 0;
LABEL_39:
          v31 = v554.m_verticesA[0].m_quad;
          v29.m_quad = (__m128)v554.m_verticesBinA[0];
          supportOut = query.m_quad;
          v554.m_checkTriangleDots = (hkVector4f)v554.m_verticesBinA[0];
          goto LABEL_40;
        }
        v150 = v35->m_quad;
        v151 = m_verticesA[1].m_quad;
        v152.m_quad = (__m128)v554.m_checkTriangleDots;
        v153 = _mm_mul_ps(_mm_sub_ps(m_verticesA->m_quad, v35->m_quad), v20.m_quad);
        v154 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v153, v153, 85), _mm_shuffle_ps(v153, v153, 0)),
                 _mm_shuffle_ps(v153, v153, 170));
        v155 = _mm_mul_ps(_mm_sub_ps(v151, v35->m_quad), v20.m_quad);
        v156 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v155, v155, 85), _mm_shuffle_ps(v155, v155, 0)),
                 _mm_shuffle_ps(v155, v155, 170));
        if ( (float)(v156.m128_f32[0] * v154.m128_f32[0]) < v19.m128_f32[0] )
        {
          v608 = _mm_sub_ps(v154, v156);
          v157 = _mm_rcp_ps(v608);
          v689 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v608, v157)), v157), v154);
          v150 = v35->m_quad;
          v151 = m_verticesA[1].m_quad;
          v158 = _mm_sub_ps(v35[2].m_quad, v35->m_quad);
          v159 = _mm_sub_ps(v35[1].m_quad, v35->m_quad);
          v160 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v151, m_verticesA->m_quad), v689), m_verticesA->m_quad);
          v161 = _mm_sub_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v158, v158, 201), v159),
                   _mm_mul_ps(_mm_shuffle_ps(v159, v159, 201), v158));
          v162 = _mm_shuffle_ps(v161, v161, 201);
          v163 = _mm_sub_ps(v35[1].m_quad, v160);
          v164 = _mm_sub_ps(v35->m_quad, v160);
          v165 = _mm_sub_ps(v35[2].m_quad, v160);
          v166 = _mm_shuffle_ps(v162, v162, 210);
          v167 = _mm_shuffle_ps(v162, v162, 201);
          v168 = _mm_mul_ps(
                   _mm_sub_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v165, v165, 201), v166),
                     _mm_mul_ps(_mm_shuffle_ps(v165, v165, 210), v167)),
                   v163);
          v169 = _mm_shuffle_ps(v163, v163, 210);
          v170 = _mm_mul_ps(
                   _mm_sub_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v164, v164, 201), v166),
                     _mm_mul_ps(_mm_shuffle_ps(v164, v164, 210), v167)),
                   v165);
          v171 = _mm_mul_ps(_mm_shuffle_ps(v163, v163, 201), v166);
          v172 = v168;
          v173 = _mm_unpackhi_ps(v168, v170);
          v174 = _mm_unpacklo_ps(v172, v170);
          v175 = _mm_mul_ps(_mm_sub_ps(v171, _mm_mul_ps(v169, v167)), v164);
          v176 = _mm_movelh_ps(v174, v175);
          if ( (_mm_movemask_ps(
                  _mm_cmplt_ps(
                    v19,
                    _mm_add_ps(
                      _mm_shuffle_ps(v173, v175, 228),
                      _mm_add_ps(v176, _mm_shuffle_ps(_mm_movehl_ps(v176, v174), v175, 212))))) & 7) == 7 )
          {
            v68 = 1;
            goto LABEL_40;
          }
        }
        v177 = v35[1].m_quad;
        v178 = v35[2].m_quad;
        v179 = _mm_sub_ps(v150, v178);
        v180 = _mm_sub_ps(v177, v150);
        v181 = _mm_shuffle_ps(v179, v179, 201);
        v182 = v151;
        v183 = v151;
        v184 = _mm_sub_ps(v151, v35->m_quad);
        v185 = _mm_sub_ps(v182, v177);
        v186 = _mm_sub_ps(v178, v177);
        v187 = _mm_sub_ps(v183, v178);
        v188 = _mm_shuffle_ps(v186, v186, 201);
        v189 = _mm_sub_ps(_mm_mul_ps(v186, v181), _mm_mul_ps(v179, v188));
        v190 = _mm_shuffle_ps(v189, v189, 201);
        v191 = _mm_sub_ps(_mm_mul_ps(v185, v188), _mm_mul_ps(_mm_shuffle_ps(v185, v185, 201), v186));
        v192 = _mm_sub_ps(_mm_mul_ps(v187, v181), _mm_mul_ps(_mm_shuffle_ps(v187, v187, 201), v179));
        v193 = _mm_mul_ps(_mm_shuffle_ps(v191, v191, 201), v190);
        v194 = _mm_mul_ps(_mm_shuffle_ps(v192, v192, 201), v190);
        v195 = _mm_unpacklo_ps(v193, v194);
        v196 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v180, v180, 201), v184),
                 _mm_mul_ps(_mm_shuffle_ps(v184, v184, 201), v180));
        v197 = _mm_mul_ps(_mm_shuffle_ps(v196, v196, 201), v190);
        v198 = _mm_movelh_ps(v195, v197);
        v199.m_quad = _mm_add_ps(
                        _mm_shuffle_ps(_mm_unpackhi_ps(v193, v194), v197, 228),
                        _mm_add_ps(v198, _mm_shuffle_ps(_mm_movehl_ps(v198, v195), v197, 212)));
        v554.m_checkTriangleDots = (hkVector4f)v199.m_quad;
        v200 = _mm_movemask_ps(_mm_cmplt_ps(v199.m_quad, (__m128)0i64)) & 7;
        switch ( v200 )
        {
          case 7:
            v68 = 0;
            v19 = 0i64;
            *m_verticesA = (hkcdVertex)m_verticesA[1].m_quad;
            goto LABEL_39;
          case 6:
            goto LABEL_37;
          case 5:
            goto LABEL_54;
          case 3:
            goto LABEL_55;
          case 1:
            v201 = _mm_shuffle_ps(v152.m_quad, v152.m_quad, 85).m128_f32[0];
            v202 = _mm_shuffle_ps(v152.m_quad, v152.m_quad, 170).m128_f32[0];
            if ( (float)((float)(_mm_shuffle_ps(v199.m_quad, v199.m_quad, 85).m128_f32[0] - v201) * v202) > (float)((float)(_mm_shuffle_ps(v199.m_quad, v199.m_quad, 170).m128_f32[0] - v202) * v201) )
              goto LABEL_55;
            goto LABEL_54;
        }
        if ( v200 != 2 )
        {
          if ( v200 != 4
            || (v258 = _mm_shuffle_ps(v152.m_quad, v152.m_quad, 0).m128_f32[0],
                v259 = _mm_shuffle_ps(v152.m_quad, v152.m_quad, 85).m128_f32[0],
                (float)((float)(_mm_shuffle_ps(v199.m_quad, v199.m_quad, 0).m128_f32[0] - v258) * v259) <= (float)((float)(_mm_shuffle_ps(v199.m_quad, v199.m_quad, 85).m128_f32[0] - v259) * v258)) )
          {
LABEL_37:
            v19 = 0i64;
            *v35 = (hkcdVertex)v35[2].m_quad;
            goto LABEL_38;
          }
LABEL_54:
          v35[1] = (hkcdVertex)v35[2].m_quad;
          v29.m_quad = (__m128)v554.m_verticesBinA[0];
          v31 = v554.m_verticesA[0].m_quad;
          v554.m_checkTriangleDots = (hkVector4f)v554.m_verticesBinA[0];
          supportOut = query.m_quad;
          goto LABEL_55;
        }
        v203 = _mm_shuffle_ps(v152.m_quad, v152.m_quad, 170).m128_f32[0];
        v204 = _mm_shuffle_ps(v152.m_quad, v152.m_quad, 0).m128_f32[0];
        if ( (float)((float)(_mm_shuffle_ps(v199.m_quad, v199.m_quad, 170).m128_f32[0] - v203) * v204) > (float)((float)(_mm_shuffle_ps(v199.m_quad, v199.m_quad, 0).m128_f32[0] - v204) * v203) )
          goto LABEL_37;
LABEL_55:
        v68 = 2;
        v19 = 0i64;
LABEL_40:
        if ( v68 )
        {
          v205 = v68 - 1;
          if ( !v205 )
            goto LABEL_65;
          if ( v205 != 1 )
            goto LABEL_150;
          dimA.m_storage = 2;
          dimB.m_storage = 2;
LABEL_44:
          v206 = _mm_sub_ps(v31, v29.m_quad);
          v207 = _mm_sub_ps(v554.m_verticesA[1].m_quad, v31);
          v208 = _mm_sub_ps(v554.m_verticesBinA[1].m_quad, v29.m_quad);
          v209 = _mm_shuffle_ps(v208, v208, 201);
          v210 = _mm_shuffle_ps(v207, v207, 201);
          v558.m_quad = v207;
          v211 = _mm_sub_ps(_mm_mul_ps(v207, v209), _mm_mul_ps(v208, v210));
          v20.m_quad = _mm_shuffle_ps(v211, v211, 201);
          *(hkVector4f *)&v554.m_lastDimB.m_storage = (hkVector4f)v20.m_quad;
          v212 = _mm_shuffle_ps(v20.m_quad, v20.m_quad, 201);
          v213 = _mm_sub_ps(_mm_mul_ps(v210, v20.m_quad), _mm_mul_ps(v207, v212));
          v214 = _mm_shuffle_ps(v213, v213, 201);
          v215 = _mm_sub_ps(_mm_mul_ps(v209, v20.m_quad), _mm_mul_ps(v208, v212));
          v216 = _mm_mul_ps(_mm_sub_ps(v554.m_verticesBinA[1].m_quad, v31), v214);
          v217 = _mm_mul_ps(v206, v214);
          v218 = _mm_shuffle_ps(v217, v216, 238);
          v219 = _mm_shuffle_ps(v215, v215, 201);
          v220 = _mm_shuffle_ps(v217, v216, 68);
          v221 = _mm_mul_ps(_mm_sub_ps(v29.m_quad, v554.m_verticesA[1].m_quad), v219);
          v222 = _mm_mul_ps(v206, v219);
          v223 = _mm_shuffle_ps(v222, v221, 238);
          v224 = _mm_shuffle_ps(v222, v221, 68);
          v225 = _mm_add_ps(
                   _mm_shuffle_ps(v223, v218, 136),
                   _mm_add_ps(_mm_shuffle_ps(v224, v220, 221), _mm_shuffle_ps(v224, v220, 136)));
          v226 = _mm_movemask_ps(_mm_cmplt_ps(v19, v225));
          if ( v226 == 15 )
          {
            v366 = _mm_mul_ps(v206, v20.m_quad);
            v367 = _mm_shuffle_ps(v225, v225, 0);
            v368 = _mm_add_ps(_mm_shuffle_ps(v225, v225, 85), v367);
            v369 = _mm_rcp_ps(v368);
            v619 = v368;
            v699 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v369, v368)), v369), v367);
            v351 = _mm_xor_ps(
                     (__m128)_mm_slli_epi32(
                               _mm_srli_epi32(
                                 (__m128i)_mm_add_ps(
                                            _mm_add_ps(_mm_shuffle_ps(v366, v366, 85), _mm_shuffle_ps(v366, v366, 0)),
                                            _mm_shuffle_ps(v366, v366, 170)),
                                 0x1Fu),
                               0x1Fu),
                     v20.m_quad);
            v554.m_closestPointOnEdgeA.m_quad = _mm_add_ps(
                                                  _mm_mul_ps(_mm_sub_ps(v554.m_verticesA[1].m_quad, v31), v699),
                                                  v31);
            goto LABEL_149;
          }
          v227 = v226 - 7;
          if ( !v227 )
          {
            v29.m_quad = (__m128)v554.m_verticesBinA[1];
            v554.m_checkTriangleDots = (hkVector4f)v554.m_verticesBinA[1];
            v554.m_verticesBinA[0] = v554.m_verticesBinA[1];
LABEL_93:
            dimB.m_storage = 1;
LABEL_136:
            v480 = _mm_sub_ps(v31, v29.m_quad);
            v481 = _mm_sub_ps(v554.m_verticesA[1].m_quad, v29.m_quad);
            v482 = _mm_sub_ps(v554.m_verticesA[1].m_quad, v31);
            v483 = _mm_mul_ps(v481, v482);
            v484 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v483, v483, 85), _mm_shuffle_ps(v483, v483, 0)),
                     _mm_shuffle_ps(v483, v483, 170));
            v485 = _mm_mul_ps(v480, v482);
            v486 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v485, v485, 85), _mm_shuffle_ps(v485, v485, 0)),
                     _mm_shuffle_ps(v485, v485, 170));
            if ( (float)(v486.m128_f32[0] * v484.m128_f32[0]) >= v19.m128_f32[0] )
            {
              v493 = _mm_cmple_ps(v484, v19);
              dimA.m_storage = 1;
              v31 = _mm_or_ps(_mm_andnot_ps(v493, v31), _mm_and_ps(v554.m_verticesA[1].m_quad, v493));
              v554.m_verticesA[0].m_quad = v31;
              v351 = _mm_sub_ps(v31, v29.m_quad);
            }
            else
            {
              dimA.m_storage = 2;
              v487 = _mm_sub_ps(_mm_mul_ps(v480, v484), _mm_mul_ps(v481, v486));
              v488 = _mm_mul_ps(v482, v482);
              v489 = _mm_shuffle_ps(v482, v482, 201);
              v490 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v487, v487, 201), v482), _mm_mul_ps(v487, v489));
              v629 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v488, v488, 85), _mm_shuffle_ps(v488, v488, 0)),
                       _mm_shuffle_ps(v488, v488, 170));
              v491 = _mm_shuffle_ps(v490, v490, 201);
              v684 = _mm_rcp_ps(v629);
              v492 = _mm_sub_ps(_mm_mul_ps(v491, v489), _mm_mul_ps(_mm_shuffle_ps(v491, v491, 201), v482));
              v351 = _mm_mul_ps(_mm_shuffle_ps(v492, v492, 201), v684);
            }
LABEL_149:
            *(__m128 *)&v554.m_lastDimB.m_storage = v351;
LABEL_150:
            v20.m_quad = *(__m128 *)&v554.m_lastDimB.m_storage;
            v554.m_lastDimB = dimB;
            v262 = 0;
            goto LABEL_66;
          }
          v228 = v227 - 4;
          if ( !v228 )
            goto LABEL_93;
          v229 = v228 - 2;
          if ( !v229 )
          {
            v31 = v554.m_verticesA[1].m_quad;
            v554.m_verticesA[0] = v554.m_verticesA[1];
LABEL_89:
            dimA.m_storage = 1;
LABEL_90:
            v352 = _mm_sub_ps(v29.m_quad, v31);
            v353 = _mm_sub_ps(v554.m_verticesBinA[1].m_quad, v31);
            v354 = _mm_sub_ps(v554.m_verticesBinA[1].m_quad, v29.m_quad);
            v355 = _mm_mul_ps(v353, v354);
            v356 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v355, v355, 85), _mm_shuffle_ps(v355, v355, 0)),
                     _mm_shuffle_ps(v355, v355, 170));
            v357 = _mm_mul_ps(v354, v352);
            v358 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v357, v357, 85), _mm_shuffle_ps(v357, v357, 0)),
                     _mm_shuffle_ps(v357, v357, 170));
            if ( (float)(v358.m128_f32[0] * v356.m128_f32[0]) >= v19.m128_f32[0] )
            {
              v502 = _mm_cmple_ps(v356, v19);
              v359 = 1;
              v29.m_quad = _mm_or_ps(_mm_and_ps(v554.m_verticesBinA[1].m_quad, v502), _mm_andnot_ps(v502, v29.m_quad));
              v554.m_checkTriangleDots = (hkVector4f)v29.m_quad;
              v351 = _mm_sub_ps(v31, v29.m_quad);
              v554.m_verticesBinA[0] = (hkcdVertex)v29.m_quad;
            }
            else
            {
              v359 = 2;
              v360 = _mm_sub_ps(_mm_mul_ps(v356, v352), _mm_mul_ps(v358, v353));
              v361 = _mm_mul_ps(v354, v354);
              v362 = _mm_shuffle_ps(v354, v354, 201);
              v634 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v361, v361, 85), _mm_shuffle_ps(v361, v361, 0)),
                       _mm_shuffle_ps(v361, v361, 170));
              v363 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v360, v360, 201), v354), _mm_mul_ps(v362, v360));
              v669 = _mm_rcp_ps(v634);
              v364 = _mm_shuffle_ps(v363, v363, 201);
              v365 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v364, v364, 201), v354), _mm_mul_ps(v362, v364));
              v351 = _mm_mul_ps(_mm_shuffle_ps(v365, v365, 201), v669);
            }
            dimB.m_storage = v359;
            goto LABEL_149;
          }
          if ( v229 == 1 )
            goto LABEL_89;
          v230 = _mm_mul_ps(v208, v207);
          v231 = _mm_sub_ps(v29.m_quad, v31);
          v232 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v230, v230, 85), _mm_shuffle_ps(v230, v230, 0)),
                   _mm_shuffle_ps(v230, v230, 170));
          v233 = _mm_mul_ps(v231, v207);
          v234 = _mm_mul_ps(v231, v208);
          v235 = _mm_mul_ps(v208, v208);
          v236 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v233, v233, 85), _mm_shuffle_ps(v233, v233, 0)),
                   _mm_shuffle_ps(v233, v233, 170));
          v237 = _mm_mul_ps(v207, v207);
          v238 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v234, v234, 85), _mm_shuffle_ps(v234, v234, 0)),
                   _mm_shuffle_ps(v234, v234, 170));
          v610 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v237, v237, 85), _mm_shuffle_ps(v237, v237, 0)),
                   _mm_shuffle_ps(v237, v237, 170));
          v654 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v235, v235, 85), _mm_shuffle_ps(v235, v235, 0)),
                   _mm_shuffle_ps(v235, v235, 170));
          v239 = _mm_max_ps(_mm_sub_ps(_mm_mul_ps(v654, v610), _mm_mul_ps(v232, v232)), *(__m128 *)&epsilon);
          v240 = _mm_rcp_ps(v239);
          v612 = v239;
          v241 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v240, v239)), v240);
          v242 = _mm_rcp_ps(v654);
          v679 = v241;
          v243 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v242, v654)), v242);
          v244 = _mm_rcp_ps(v610);
          v614 = v243;
          v245 = _mm_sub_ps(_mm_mul_ps(v654, v236), _mm_mul_ps(v238, v232));
          v659 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v244, v610)), v244);
          v246 = _mm_cmplt_ps(v245, v239);
          v247 = _mm_cmple_ps(v239, *(__m128 *)&epsilon);
          v248 = _mm_mul_ps(
                   _mm_or_ps(
                     _mm_andnot_ps(
                       v247,
                       _mm_mul_ps(
                         _mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_andnot_ps(v246, v239), _mm_and_ps(v245, v246))),
                         v241)),
                     _mm_and_ps(v247, supportOut)),
                   _mm_mul_ps(v243, v232));
          v249 = _mm_mul_ps(v659, v232);
          v250 = _mm_mul_ps(v659, v236);
          v33 = supportOut;
          v251 = _mm_sub_ps(v248, _mm_mul_ps(v243, v238));
          v19 = 0i64;
          v252 = _mm_cmplt_ps(v251, supportOut);
          v253 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v251, v252), _mm_andnot_ps(v252, supportOut)));
          v254 = _mm_add_ps(_mm_mul_ps(v249, v253), v250);
          v255 = _mm_cmplt_ps(v254, supportOut);
          v256 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v254, v255), _mm_andnot_ps(v255, supportOut)));
          v257 = _mm_movemask_ps(
                   _mm_cmpeq_ps(
                     _mm_movelh_ps(_mm_unpacklo_ps(v256, v256), _mm_unpacklo_ps(v253, v253)),
                     (__m128)xmmword_141A71330));
          v554.m_closestPointOnEdgeA.m_quad = _mm_add_ps(_mm_mul_ps(v256, v558.m_quad), v31);
          if ( !v257 )
          {
            v350 = _mm_mul_ps(v206, v20.m_quad);
            v351 = _mm_xor_ps(
                     (__m128)_mm_slli_epi32(
                               _mm_srli_epi32(
                                 (__m128i)_mm_add_ps(
                                            _mm_add_ps(_mm_shuffle_ps(v350, v350, 85), _mm_shuffle_ps(v350, v350, 0)),
                                            _mm_shuffle_ps(v350, v350, 170)),
                                 0x1Fu),
                               0x1Fu),
                     v20.m_quad);
            goto LABEL_149;
          }
          if ( (v257 & 1) != 0 )
          {
            v31 = v554.m_verticesA[1].m_quad;
            dimA.m_storage = 1;
            v554.m_verticesA[0] = v554.m_verticesA[1];
          }
          else
          {
            m_storage = dimA.m_storage;
            if ( (v257 & 2) != 0 )
              m_storage = 1;
            dimA.m_storage = m_storage;
          }
          if ( (v257 & 4) != 0 )
          {
            v29.m_quad = (__m128)v554.m_verticesBinA[1];
            dimB.m_storage = 1;
            v554.m_checkTriangleDots = (hkVector4f)v554.m_verticesBinA[1];
            v554.m_verticesBinA[0] = v554.m_verticesBinA[1];
          }
          else
          {
            v261 = dimB.m_storage;
            if ( (v257 & 8) != 0 )
              v261 = 1;
            dimB.m_storage = v261;
          }
          v32 = (dimB.m_storage | (8 * dimA.m_storage)) - 9;
          if ( v32 > 0x18 )
          {
LABEL_65:
            v262 = 1;
            goto LABEL_66;
          }
          continue;
        }
        v20.m_quad = *(__m128 *)&v554.m_lastDimB.m_storage;
        if ( dimA.m_storage == 2 )
        {
          dimA.m_storage = 1;
          v554.m_lastDimB = dimB;
        }
        else
        {
          dimB.m_storage = 1;
          v554.m_lastDimB.m_storage = 1;
        }
        v262 = 0;
LABEL_66:
        v263 = _mm_mul_ps(v20.m_quad, v20.m_quad);
        v264 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v263, v263, 85), _mm_shuffle_ps(v263, v263, 0)),
                 _mm_shuffle_ps(v263, v263, 170));
        v265 = _mm_rsqrt_ps(v264);
        v639 = v264;
        v266 = _mm_andnot_ps(
                 _mm_cmple_ps(v264, v19),
                 _mm_mul_ps(
                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v265, v264), v265)),
                   _mm_mul_ps(v265, *(__m128 *)_xmm)));
        v267 = _mm_mul_ps(_mm_sub_ps(v31, v29.m_quad), v20.m_quad);
        v20.m_quad = _mm_mul_ps(v20.m_quad, v266);
        *(hkVector4f *)&v554.m_lastDimB.m_storage = (hkVector4f)v20.m_quad;
        if ( !v262
          && (float)((float)((float)(_mm_shuffle_ps(v267, v267, 85).m128_f32[0]
                                   + _mm_shuffle_ps(v267, v267, 0).m128_f32[0])
                           + _mm_shuffle_ps(v267, v267, 170).m128_f32[0])
                   * v266.m128_f32[0]) >= v587.m128_f32[0]
          && v264.m128_f32[0] >= (float)((float)(v587.m128_f32[0] * v587.m128_f32[0])
                                       * (float)(v587.m128_f32[0] * v587.m128_f32[0])) )
        {
          v268 = aTb->m_rotation.m_col2.m_quad;
          v269 = aTb->m_rotation.m_col0.m_quad;
          v270 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
          v562 = _mm_xor_ps(v270, v20.m_quad);
          v271 = _mm_xor_ps(v562, v270);
          v272 = _mm_unpacklo_ps(v269, aTb->m_rotation.m_col1.m_quad);
          v273 = _mm_shuffle_ps(_mm_unpackhi_ps(v269, aTb->m_rotation.m_col1.m_quad), v268, 228);
          v274 = _mm_movelh_ps(v272, v268);
          v275 = _mm_shuffle_ps(_mm_movehl_ps(v274, v272), v268, 212);
          v276 = v562;
          v583 = shapeA->m_quad;
          v584 = shapeA[1].m_quad;
          v553 = v583;
          v277 = _mm_mul_ps(v583, v562);
          v585 = shapeA[2].m_quad;
          v278 = shapeA[3].m_quad;
          v563 = v585;
          v586 = v278;
          v279 = shapeB->m_quad;
          v555 = v584;
          v575 = v279;
          v280 = shapeB[1].m_quad;
          v566 = v278;
          v576 = v280;
          v281 = shapeB[2].m_quad;
          v572 = v279;
          v577 = v281;
          v282 = shapeB[3].m_quad;
          v602[4] = v562;
          v574 = v280;
          v571 = v281;
          v573 = v282;
          v578 = v282;
          v283 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v271, v271, 85), v275),
                     _mm_mul_ps(_mm_shuffle_ps(v271, v271, 0), v274)),
                   _mm_mul_ps(_mm_shuffle_ps(v271, v271, 170), v273));
          v558.m_quad = v283;
          v602[5] = v283;
          v284 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v277, v277, 85), _mm_shuffle_ps(v277, v277, 0)),
                   _mm_shuffle_ps(v277, v277, 170));
          v285 = _mm_mul_ps(v584, v562);
          v561 = v284;
          v579 = v284;
          v286 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v285, v285, 85), _mm_shuffle_ps(v285, v285, 0)),
                   _mm_shuffle_ps(v285, v285, 170));
          v556 = v286;
          v580 = v286;
          v287 = _mm_mul_ps(v585, v562);
          v288 = v570 - 4;
          v289 = v568 - 4;
          v290 = shapeA + 4;
          v291 = shapeB + 4;
          v292 = v568 - 4;
          v293 = _mm_shuffle_ps(v287, v287, 85);
          v294 = _mm_shuffle_ps(v287, v287, 0);
          v295 = _mm_shuffle_ps(v287, v287, 170);
          v296 = _mm_add_ps(v293, v294);
          if ( v570 - 4 < v568 - 4 )
            v292 = v570 - 4;
          v297 = _mm_add_ps(v296, v295);
          v298 = _mm_mul_ps(v278, v562);
          v559 = v297;
          v581 = v297;
          v299 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v298, v298, 85), _mm_shuffle_ps(v298, v298, 0)),
                   _mm_shuffle_ps(v298, v298, 170));
          v300 = _mm_mul_ps(v279, v283);
          v557 = v299;
          v582 = v299;
          v301 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v300, v300, 85), _mm_shuffle_ps(v300, v300, 0)),
                   _mm_shuffle_ps(v300, v300, 170));
          v302 = _mm_mul_ps(v280, v283);
          v565 = v301;
          v588 = v301;
          v303 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v302, v302, 85), _mm_shuffle_ps(v302, v302, 0)),
                   _mm_shuffle_ps(v302, v302, 170));
          v304 = _mm_mul_ps(v281, v283);
          v560 = v303;
          v589 = v303;
          v305 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v304, v304, 85), _mm_shuffle_ps(v304, v304, 0)),
                   _mm_shuffle_ps(v304, v304, 170));
          v306 = _mm_mul_ps(v282, v283);
          v564 = v305;
          v590 = v305;
          supportOuta = _mm_add_ps(
                          _mm_add_ps(_mm_shuffle_ps(v306, v306, 85), _mm_shuffle_ps(v306, v306, 0)),
                          _mm_shuffle_ps(v306, v306, 170));
          v591 = supportOuta;
          if ( v292 > 0 )
          {
            v307 = ((unsigned int)(v292 - 1) >> 2) + 1;
            v288 -= 4 * v307;
            v289 -= 4 * v307;
            do
            {
              v308 = _mm_mul_ps(v276, v290->m_quad);
              v620 = (__int128)v290->m_quad;
              v309 = v290[1].m_quad;
              v593 = v620;
              v621 = v309;
              v310 = v290[2].m_quad;
              v597 = v309;
              v311 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v308, v308, 85), _mm_shuffle_ps(v308, v308, 0)),
                       _mm_shuffle_ps(v308, v308, 170));
              v622 = v310;
              v312 = _mm_mul_ps(v562, v309);
              v623 = v290[3].m_quad;
              v313 = v291->m_quad;
              v599 = v310;
              v314 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v312, v312, 85), _mm_shuffle_ps(v312, v312, 0)),
                       _mm_shuffle_ps(v312, v312, 170));
              v625 = v313;
              v315 = _mm_mul_ps(v562, v310);
              v626 = v291[1].m_quad;
              v316 = v291[2].m_quad;
              v601 = v623;
              v594 = v313;
              v317 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v315, v315, 85), _mm_shuffle_ps(v315, v315, 0)),
                       _mm_shuffle_ps(v315, v315, 170));
              v627 = v316;
              v318 = v291[3].m_quad;
              v319 = _mm_mul_ps(v562, v623);
              v595 = v626;
              v596 = v316;
              v600 = v318;
              v628 = v318;
              v320 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v319, v319, 85), _mm_shuffle_ps(v319, v319, 0)),
                       _mm_shuffle_ps(v319, v319, 170));
              v592 = v311;
              v630 = v311;
              v321 = _mm_mul_ps(v558.m_quad, v313);
              v631 = v314;
              v632 = v317;
              v633 = v320;
              v598 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v321, v321, 85), _mm_shuffle_ps(v321, v321, 0)),
                       _mm_shuffle_ps(v321, v321, 170));
              v635 = v598;
              v322 = _mm_mul_ps(v558.m_quad, v626);
              v648 = supportOuta;
              v646 = v560;
              v642 = v559;
              v643 = v557;
              v636 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v322, v322, 85), _mm_shuffle_ps(v322, v322, 0)),
                       _mm_shuffle_ps(v322, v322, 170));
              v323 = _mm_mul_ps(v558.m_quad, v316);
              v647 = v564;
              v652 = _mm_cmplt_ps(v559, v317);
              v653 = _mm_cmplt_ps(v557, v320);
              v637 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v323, v323, 85), _mm_shuffle_ps(v323, v323, 0)),
                       _mm_shuffle_ps(v323, v323, 170));
              v324 = _mm_mul_ps(v558.m_quad, v318);
              v640 = v561;
              v650 = _mm_cmplt_ps(v561, v311);
              v641 = v556;
              v645 = v565;
              v638 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v324, v324, 85), _mm_shuffle_ps(v324, v324, 0)),
                       _mm_shuffle_ps(v324, v324, 170));
              v651 = _mm_cmplt_ps(v556, v314);
              v655 = _mm_cmplt_ps(v565, v598);
              v656 = _mm_cmplt_ps(v560, v636);
              v657 = _mm_cmplt_ps(v564, v637);
              v561 = _mm_or_ps(_mm_andnot_ps(v650, v561), _mm_and_ps(v650, v311));
              v579 = v561;
              v658 = _mm_cmplt_ps(supportOuta, v638);
              v286 = _mm_or_ps(_mm_andnot_ps(v651, v556), _mm_and_ps(v651, v314));
              v556 = v286;
              v580 = v286;
              v559 = _mm_or_ps(_mm_andnot_ps(v652, v559), _mm_and_ps(v652, v317));
              v581 = v559;
              v557 = _mm_or_ps(_mm_and_ps(v653, v320), _mm_andnot_ps(v653, v557));
              v582 = v557;
              v553 = _mm_or_ps(_mm_andnot_ps(v650, v553), _mm_and_ps(v650, (__m128)v620));
              v583 = v553;
              v555 = _mm_or_ps(_mm_andnot_ps(v651, v555), _mm_and_ps(v651, v309));
              v584 = v555;
              v563 = _mm_or_ps(_mm_andnot_ps(v652, v563), _mm_and_ps(v652, v310));
              v585 = v563;
              v566 = _mm_or_ps(_mm_andnot_ps(v653, v566), _mm_and_ps(v653, v623));
              v586 = v566;
              v565 = _mm_or_ps(_mm_and_ps(v655, v598), _mm_andnot_ps(v655, v565));
              v588 = v565;
              v560 = _mm_or_ps(_mm_and_ps(v656, v636), _mm_andnot_ps(v656, v560));
              v589 = v560;
              v574 = _mm_or_ps(_mm_andnot_ps(v656, v574), _mm_and_ps(v656, v626));
              v576 = v574;
              v564 = _mm_or_ps(_mm_and_ps(v657, v637), _mm_andnot_ps(v657, v564));
              v590 = v564;
              v572 = _mm_or_ps(_mm_andnot_ps(v655, v572), _mm_and_ps(v655, v313));
              v575 = v572;
              supportOuta = _mm_or_ps(_mm_and_ps(v658, v638), _mm_andnot_ps(v658, supportOuta));
              v591 = supportOuta;
              v276 = v562;
              v290 += 4;
              v291 += 4;
              v571 = _mm_or_ps(_mm_andnot_ps(v657, v571), _mm_and_ps(v657, v316));
              v577 = v571;
              v573 = _mm_or_ps(_mm_andnot_ps(v658, v573), _mm_and_ps(v658, v318));
              v578 = v573;
              --v307;
            }
            while ( v307 );
            v20.m_quad = *(__m128 *)&v554.m_lastDimB.m_storage;
            v31 = v553;
          }
          if ( v288 > 0 )
          {
            v325 = v561;
            v326 = v559;
            p_m_quad = &v290[2].m_quad;
            v328 = ((unsigned int)(v288 - 1) >> 2) + 1;
            do
            {
              v329 = p_m_quad[-2];
              v330 = _mm_mul_ps(v276, v329);
              v660 = v329;
              v331 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v330, v330, 85), _mm_shuffle_ps(v330, v330, 0)),
                       _mm_shuffle_ps(v330, v330, 170));
              v661 = p_m_quad[-1];
              v332 = _mm_mul_ps(v276, v661);
              v662 = *p_m_quad;
              v333 = p_m_quad[1];
              v670 = v325;
              v671 = v286;
              v665 = v331;
              v666 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v332, v332, 85), _mm_shuffle_ps(v332, v332, 0)),
                       _mm_shuffle_ps(v332, v332, 170));
              v334 = _mm_mul_ps(v276, v662);
              v672 = v326;
              v663 = v333;
              v676 = _mm_cmplt_ps(v286, v666);
              v667 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v334, v334, 85), _mm_shuffle_ps(v334, v334, 0)),
                       _mm_shuffle_ps(v334, v334, 170));
              v335 = _mm_mul_ps(v276, v333);
              v677 = _mm_cmplt_ps(v326, v667);
              v673 = v557;
              v668 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v335, v335, 85), _mm_shuffle_ps(v335, v335, 0)),
                       _mm_shuffle_ps(v335, v335, 170));
              v675 = _mm_cmplt_ps(v325, v331);
              v678 = _mm_cmplt_ps(v557, v668);
              v325 = _mm_or_ps(_mm_andnot_ps(v675, v325), _mm_and_ps(v331, v675));
              v579 = v325;
              v286 = _mm_or_ps(_mm_andnot_ps(v676, v286), _mm_and_ps(v666, v676));
              v580 = v286;
              p_m_quad += 4;
              v557 = _mm_or_ps(_mm_andnot_ps(v678, v557), _mm_and_ps(v668, v678));
              v582 = v557;
              v555 = _mm_or_ps(_mm_andnot_ps(v676, v555), _mm_and_ps(v661, v676));
              v584 = v555;
              v326 = _mm_or_ps(_mm_andnot_ps(v677, v326), _mm_and_ps(v667, v677));
              v553 = _mm_or_ps(_mm_andnot_ps(v675, v553), _mm_and_ps(v329, v675));
              v583 = v553;
              v276 = v562;
              v581 = v326;
              v566 = _mm_or_ps(_mm_andnot_ps(v678, v566), _mm_and_ps(v333, v678));
              v586 = v566;
              v563 = _mm_or_ps(_mm_andnot_ps(v677, v563), _mm_and_ps(v662, v677));
              v585 = v563;
              --v328;
            }
            while ( v328 );
            v559 = v326;
            v31 = v553;
            v561 = v325;
            v20.m_quad = *(__m128 *)&v554.m_lastDimB.m_storage;
            v556 = v286;
          }
          if ( v289 <= 0 )
          {
            v348 = v574;
            v349 = v573;
          }
          else
          {
            v336 = v565;
            v337 = v560;
            v338 = v564;
            v339 = &v291[2].m_quad;
            v340 = ((unsigned int)(v289 - 1) >> 2) + 1;
            do
            {
              v680 = v339[-2];
              v341 = _mm_mul_ps(v558.m_quad, v680);
              v681 = v339[-1];
              v342 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v341, v341, 85), _mm_shuffle_ps(v341, v341, 0)),
                       _mm_shuffle_ps(v341, v341, 170));
              v682 = *v339;
              v343 = v339[1];
              v344 = _mm_mul_ps(v558.m_quad, v681);
              v690 = v336;
              v691 = v337;
              v685 = v342;
              v692 = v338;
              v686 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v344, v344, 85), _mm_shuffle_ps(v344, v344, 0)),
                       _mm_shuffle_ps(v344, v344, 170));
              v683 = v343;
              v345 = _mm_mul_ps(v558.m_quad, v682);
              v346 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v345, v345, 85), _mm_shuffle_ps(v345, v345, 0)),
                       _mm_shuffle_ps(v345, v345, 170));
              v347 = _mm_mul_ps(v558.m_quad, v343);
              v687 = v346;
              v696 = _mm_cmplt_ps(v337, v686);
              v697 = _mm_cmplt_ps(v338, v346);
              v693 = supportOuta;
              v688 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v347, v347, 85), _mm_shuffle_ps(v347, v347, 0)),
                       _mm_shuffle_ps(v347, v347, 170));
              v695 = _mm_cmplt_ps(v336, v342);
              v698 = _mm_cmplt_ps(supportOuta, v688);
              v336 = _mm_or_ps(_mm_andnot_ps(v695, v336), _mm_and_ps(v342, v695));
              v588 = v336;
              v337 = _mm_or_ps(_mm_andnot_ps(v696, v337), _mm_and_ps(v686, v696));
              v589 = v337;
              v339 += 4;
              supportOuta = _mm_or_ps(_mm_andnot_ps(v698, supportOuta), _mm_and_ps(v688, v698));
              v591 = supportOuta;
              v572 = _mm_or_ps(_mm_and_ps(v680, v695), _mm_andnot_ps(v695, v572));
              v575 = v572;
              v348 = _mm_or_ps(_mm_and_ps(v681, v696), _mm_andnot_ps(v696, v574));
              v574 = v348;
              v576 = v348;
              v571 = _mm_or_ps(_mm_and_ps(v682, v697), _mm_andnot_ps(v697, v571));
              v577 = v571;
              v349 = _mm_or_ps(_mm_and_ps(v343, v698), _mm_andnot_ps(v698, v573));
              v338 = _mm_or_ps(_mm_andnot_ps(v697, v338), _mm_and_ps(v346, v697));
              v573 = v349;
              v578 = v349;
              v590 = v338;
              --v340;
            }
            while ( v340 );
            v564 = v338;
            v286 = v556;
            v560 = v337;
            v31 = v553;
            v565 = v336;
            v20.m_quad = *(__m128 *)&v554.m_lastDimB.m_storage;
          }
          v503 = _mm_cmplt_ps(v559, v557);
          v504 = _mm_cmplt_ps(v564, supportOuta);
          v505 = _mm_cmplt_ps(v561, v286);
          v506 = _mm_cmplt_ps(v565, v560);
          v507 = _mm_cmplt_ps(
                   _mm_or_ps(_mm_andnot_ps(v503, v559), _mm_and_ps(v503, v557)),
                   _mm_or_ps(_mm_and_ps(v286, v505), _mm_andnot_ps(v505, v561)));
          v508 = _mm_cmplt_ps(
                   _mm_or_ps(_mm_and_ps(v504, supportOuta), _mm_andnot_ps(v504, v564)),
                   _mm_or_ps(_mm_and_ps(v506, v560), _mm_andnot_ps(v506, v565)));
          v509 = _mm_or_ps(
                   _mm_andnot_ps(v508, _mm_or_ps(_mm_and_ps(v349, v504), _mm_andnot_ps(v504, v571))),
                   _mm_and_ps(_mm_or_ps(_mm_and_ps(v348, v506), _mm_andnot_ps(v506, v572)), v508));
          v510 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v509, v509, 0), aTb->m_rotation.m_col0.m_quad),
                       _mm_mul_ps(_mm_shuffle_ps(v509, v509, 85), aTb->m_rotation.m_col1.m_quad)),
                     _mm_mul_ps(_mm_shuffle_ps(v509, v509, 170), aTb->m_rotation.m_col2.m_quad)),
                   aTb->m_translation.m_quad);
          v511 = _mm_or_ps(
                   _mm_andnot_ps(v507, _mm_or_ps(_mm_and_ps(v566, v503), _mm_andnot_ps(v503, v563))),
                   _mm_and_ps(_mm_or_ps(_mm_and_ps(v555, v505), _mm_andnot_ps(v505, v553)), v507));
          v512 = _mm_shuffle_ps(v510, _mm_unpackhi_ps(v510, v509), 196);
          v513 = _mm_mul_ps(_mm_sub_ps(v511, v512), v20.m_quad);
          v514 = _mm_mul_ps(_mm_sub_ps(v511, v31), v562);
          v515 = _mm_mul_ps(_mm_sub_ps(v512, v554.m_checkTriangleDots.m_quad), v20.m_quad);
          v516 = _mm_unpacklo_ps(v513, v514);
          v517 = _mm_movelh_ps(v516, v515);
          v518 = _mm_shuffle_ps(_mm_unpackhi_ps(v513, v514), v515, 228);
          v519 = _mm_add_ps(v517, _mm_shuffle_ps(_mm_movehl_ps(v517, v516), v515, 212));
          v520 = _mm_mul_ps(_mm_sub_ps(v511, v554.m_verticesA[2].m_quad), v562);
          v521 = _mm_mul_ps(_mm_sub_ps(v512, v554.m_verticesBinA[1].m_quad), v20.m_quad);
          v522 = _mm_add_ps(v518, v519);
          v523 = _mm_mul_ps(_mm_sub_ps(v511, v554.m_verticesA[1].m_quad), v562);
          v524 = _mm_shuffle_ps(v523, v520, 238);
          v525 = _mm_shuffle_ps(v523, v520, 68);
          v526 = _mm_mul_ps(_mm_sub_ps(v512, v554.m_verticesBinA[2].m_quad), v20.m_quad);
          v527 = _mm_shuffle_ps(v521, v526, 68);
          v528 = _mm_shuffle_ps(v521, v526, 238);
          v529 = _mm_add_ps(_mm_shuffle_ps(v525, v527, 221), _mm_shuffle_ps(v525, v527, 136));
          v30 = v587;
          v530 = _mm_cmplt_ps(_mm_add_ps(_mm_shuffle_ps(v524, v528, 136), v529), v587);
          switch ( _mm_movemask_ps(
                     _mm_cmplt_ps(
                       _mm_movelh_ps(
                         _mm_unpacklo_ps(aTb[1].m_rotation.m_col1.m_quad, v587),
                         _mm_unpacklo_ps(v587, v587)),
                       v522)) & 7 )
          {
            case 1:
            case 3:
            case 5:
            case 7:
              v531 = vars0;
              v28 = 5;
              vars0->m_distance.m_real = _mm_shuffle_ps(v522, v522, 0);
              v531->m_normalInA = (hkVector4f)v20.m_quad;
              goto LABEL_174;
            case 2:
              goto LABEL_154;
            case 4:
              goto LABEL_156;
            case 6:
              if ( _mm_shuffle_ps(v522, v522, 170).m128_f32[0] > _mm_shuffle_ps(v522, v522, 85).m128_f32[0] )
              {
LABEL_156:
                if ( (_mm_movemask_ps(v530) & hkcdGskBase::dimToMaskZ[dimB.m_storage]) != 0 )
                {
LABEL_159:
                  v532 = vars0;
                  v533 = _mm_mul_ps(_mm_sub_ps(v31, v554.m_checkTriangleDots.m_quad), v20.m_quad);
                  vars0->m_normalInA = (hkVector4f)v20.m_quad;
                  v534 = _mm_add_ps(
                           _mm_add_ps(_mm_shuffle_ps(v533, v533, 85), _mm_shuffle_ps(v533, v533, 0)),
                           _mm_shuffle_ps(v533, v533, 170));
                  v532->m_distance.m_real = v534;
                  if ( dimA.m_storage == 1 )
                  {
                    v532->m_pointAinA = (hkVector4f)v554.m_verticesA[0];
                  }
                  else if ( dimB.m_storage == 1 )
                  {
                    v532->m_pointAinA.m_quad = _mm_add_ps(_mm_mul_ps(v534, v20.m_quad), v554.m_verticesBinA[0].m_quad);
                  }
                  else
                  {
                    v532->m_pointAinA = v554.m_closestPointOnEdgeA;
                  }
                  goto LABEL_174;
                }
                v19 = 0i64;
                v554.m_verticesBinA[dimB.m_storage++].m_quad = v512;
                v29.m_quad = (__m128)v554.m_verticesBinA[0];
              }
              else
              {
LABEL_154:
                if ( (_mm_movemask_ps(v530) & hkcdGskBase::dimToMaskY[dimA.m_storage]) != 0 )
                  goto LABEL_159;
                v554.m_verticesBinA[dimA.m_storage++ - 4].m_quad = v511;
                v29.m_quad = (__m128)v554.m_verticesBinA[0];
                v19 = 0i64;
              }
              break;
            default:
              goto LABEL_159;
          }
          goto LABEL_9;
        }
        if ( aTb[1].m_rotation.m_col0.m_quad.m128_i32[0] )
        {
          Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
          v536 = Value[1];
          if ( v536 < Value[3] )
          {
            *(_QWORD *)v536 = "TtPenetration";
            v537 = __rdtsc();
            *(_DWORD *)(v536 + 8) = v537;
            Value[1] = v536 + 16;
          }
          v538 = hkcdGskBase::handlePenetration(
                   &v554,
                   &shapeInterface,
                   &shapeA,
                   &shapeB,
                   aTb,
                   &dimA,
                   &dimB,
                   vars0,
                   &v603);
          v539 = (_QWORD *)Value[1];
          v28 = v538;
          if ( (unsigned __int64)v539 < Value[3] )
          {
            *v539 = "Et";
            v540 = __rdtsc();
            v541 = v539 + 2;
            *((_DWORD *)v541 - 2) = v540;
            Value[1] = v541;
          }
        }
        else
        {
          if ( dimB.m_storage + dimA.m_storage > 4 )
          {
            if ( dimA.m_storage <= dimB.m_storage )
            {
              dimA.m_storage = 1;
              dimB.m_storage = 3;
            }
            else
            {
              dimA.m_storage = 3;
              dimB.m_storage = 1;
            }
          }
          v28 = 6;
        }
LABEL_174:
        v542 = dimA.m_storage;
        v543 = dimB.m_storage;
        v544 = v554.m_verticesBinA[1].m_quad.m128_i8[12];
        v545 = v554.m_verticesA[0].m_quad.m128_i8[12];
        v546 = v554.m_verticesA[1].m_quad.m128_i8[12];
        v547 = v554.m_verticesA[2].m_quad.m128_i8[12];
        v548 = v554.m_verticesBinA[0].m_quad.m128_i8[12];
        v4[(LOBYTE(dimA.m_storage) - 2) & 3] = v554.m_verticesBinA[2].m_quad.m128_i8[12];
        *v4 = v545;
        v4[1] = v546;
        v4[2] = v547;
        v4[v542] = v548;
        v4[v542 + 1] = v544;
        result = v28;
        v4[4] = v543 | (4 * (v28 | (16 * v542)));
        return result;
      case 0x18u:
        v33 = g_vectorfConstants[0];
        v370 = v29.m_quad;
        v371 = v554.m_verticesA;
LABEL_97:
        v372 = v371[1].m_quad;
        v373 = v371[2].m_quad;
        v374 = _mm_sub_ps(v372, v371->m_quad);
        v375 = _mm_sub_ps(v371->m_quad, v373);
        v376 = _mm_sub_ps(v371[3].m_quad, v371->m_quad);
        v377 = _mm_sub_ps(v373, v372);
        v378 = _mm_sub_ps(v371[3].m_quad, v372);
        v379 = _mm_sub_ps(v371[3].m_quad, v373);
        v380 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v378, v378, 201), v377),
                 _mm_mul_ps(_mm_shuffle_ps(v377, v377, 201), v378));
        v381 = _mm_shuffle_ps(v380, v380, 201);
        v382 = _mm_mul_ps(_mm_sub_ps(v370, v371[3].m_quad), v33);
        v383 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v379, v379, 201), v375),
                 _mm_mul_ps(_mm_shuffle_ps(v375, v375, 201), v379));
        v384 = _mm_shuffle_ps(v383, v383, 201);
        v385 = _mm_mul_ps(v382, v384);
        v386 = _mm_mul_ps(v384, v384);
        v387 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v376, v376, 201), v374),
                 _mm_mul_ps(_mm_shuffle_ps(v374, v374, 201), v376));
        v388 = _mm_mul_ps(v382, v381);
        v389 = _mm_mul_ps(v381, v381);
        v390 = _mm_shuffle_ps(v387, v387, 201);
        v391 = _mm_unpacklo_ps(v388, v385);
        v392 = _mm_unpackhi_ps(v388, v385);
        v393 = _mm_mul_ps(v382, v390);
        v394 = _mm_movelh_ps(v391, v393);
        v395 = _mm_shuffle_ps(_mm_movehl_ps(v394, v391), v393, 212);
        v396 = _mm_unpacklo_ps(v389, v386);
        v397 = _mm_mul_ps(v390, v390);
        v398 = (__m128i)_mm_add_ps(_mm_shuffle_ps(v392, v393, 228), _mm_add_ps(v394, v395));
        v399 = _mm_movelh_ps(v396, v397);
        v400 = _mm_add_ps(
                 _mm_shuffle_ps(_mm_unpackhi_ps(v389, v386), v397, 228),
                 _mm_add_ps(v399, _mm_shuffle_ps(_mm_movehl_ps(v399, v396), v397, 212)));
        v401 = _mm_rcp_ps(v400);
        v624 = v400;
        v664 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v400, v401)), v401);
        v402 = _mm_cmpeq_ps(v19, v400);
        LODWORD(v705) = 897988542;
        v403 = _mm_or_ps(
                 _mm_andnot_ps(
                   v402,
                   _mm_mul_ps(_mm_mul_ps((__m128)_mm_srli_epi32(_mm_slli_epi32(v398, 1u), 1u), (__m128)v398), v664)),
                 _mm_and_ps(v402, (__m128)xmmword_141A712A0));
        v404 = _mm_max_ps(
                 _mm_shuffle_ps(v403, v403, 170),
                 _mm_max_ps(_mm_shuffle_ps(v403, v403, 85), _mm_shuffle_ps(v403, v403, 0)));
        v405 = (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                                      _mm_and_ps(
                                                                        _mm_cmple_ps(v404, v403),
                                                                        (__m128)xmmword_141C1F4F0))];
        if ( v404.m128_f32[0] < _mm_shuffle_ps((__m128)0x358637BEu, (__m128)0x358637BEu, 0).m128_f32[0] )
          goto LABEL_65;
        v701 = 1066192077;
        v406 = _mm_or_ps(
                 _mm_and_ps((__m128)`hkVector4f::getComponent::`2::indexToMask[v405], (__m128)xmmword_141A712F0),
                 _mm_andnot_ps((__m128)`hkVector4f::getComponent::`2::indexToMask[v405], v403));
        if ( v404.m128_f32[0] <= (float)(fmax(
                                           _mm_shuffle_ps(v406, v406, 170).m128_f32[0],
                                           fmax(
                                             _mm_shuffle_ps(v406, v406, 85).m128_f32[0],
                                             _mm_shuffle_ps(v406, v406, 0).m128_f32[0]))
                                       * _mm_shuffle_ps((__m128)0x3F8CCCCDu, (__m128)0x3F8CCCCDu, 0).m128_f32[0]) )
        {
          v407 = 2;
          v408 = 1;
          v409 = 4;
          v410 = 16i64;
          v411 = 32i64;
          v412 = 0i64;
          v413 = 3i64;
          v414 = _mm_movemask_ps(_mm_cmple_ps(v19, (__m128)v398));
          do
          {
            if ( (v408 & v414) != 0 && (v407 & v414) != 0 )
            {
              v415 = *(__m128 *)((char *)&v371->m_quad + v411);
              v416 = _mm_sub_ps(v371[v412].m_quad, v415);
              v417 = _mm_sub_ps(v371[3].m_quad, v415);
              v418 = _mm_sub_ps(v370, v415);
              v419 = _mm_mul_ps(v417, v416);
              v420 = _mm_sub_ps(*(__m128 *)((char *)&v371->m_quad + v410), v415);
              v421 = _mm_mul_ps(v418, v416);
              v422 = _mm_mul_ps(v417, v420);
              v423 = _mm_mul_ps(v418, v420);
              if ( (float)((float)((float)(_mm_shuffle_ps(v421, v421, 85).m128_f32[0]
                                         + _mm_shuffle_ps(v421, v421, 0).m128_f32[0])
                                 + _mm_shuffle_ps(v421, v421, 170).m128_f32[0])
                         * (float)((float)(_mm_shuffle_ps(v422, v422, 85).m128_f32[0]
                                         + _mm_shuffle_ps(v422, v422, 0).m128_f32[0])
                                 + _mm_shuffle_ps(v422, v422, 170).m128_f32[0])) >= (float)((float)((float)(_mm_shuffle_ps(v419, v419, 85).m128_f32[0] + _mm_shuffle_ps(v419, v419, 0).m128_f32[0])
                                                                                                  + _mm_shuffle_ps(v419, v419, 170).m128_f32[0])
                                                                                          * (float)((float)(_mm_shuffle_ps(v423, v423, 85).m128_f32[0] + _mm_shuffle_ps(v423, v423, 0).m128_f32[0])
                                                                                                  + _mm_shuffle_ps(v423, v423, 170).m128_f32[0])) )
                v407 = v408;
              v414 &= ~v407;
            }
            v407 = v409;
            v410 = v411;
            v409 = v408;
            v408 = __ROL4__(v408, 1);
            v411 = v412 * 16;
            ++v412;
            --v413;
          }
          while ( v413 );
          if ( (v414 & 7) != 0 )
            v405 = (unsigned __int8)hkVector4Comparison_maskToFirstIndex[v414];
          else
            v405 = -1;
        }
        if ( v405 < 0 )
          goto LABEL_65;
        v371[v405] = (hkcdVertex)v371[3].m_quad;
        v29.m_quad = (__m128)v554.m_verticesBinA[0];
        v31 = v554.m_verticesA[0].m_quad;
        v554.m_checkTriangleDots = (hkVector4f)v554.m_verticesBinA[0];
        if ( dimA.m_storage == 4 )
        {
          dimA.m_storage = 3;
LABEL_112:
          v424 = _mm_sub_ps(v31, v554.m_verticesA[2].m_quad);
          v425 = _mm_shuffle_ps(v424, v424, 201);
          v426 = _mm_sub_ps(v29.m_quad, v554.m_verticesA[1].m_quad);
          v427 = _mm_sub_ps(v554.m_verticesA[2].m_quad, v554.m_verticesA[1].m_quad);
          v428 = _mm_sub_ps(v29.m_quad, v554.m_verticesA[2].m_quad);
          v429 = _mm_shuffle_ps(v427, v427, 201);
          v430 = _mm_sub_ps(v554.m_verticesA[1].m_quad, v31);
          v431 = _mm_sub_ps(v29.m_quad, v31);
          v432 = _mm_sub_ps(_mm_mul_ps(v425, v427), _mm_mul_ps(v429, v424));
          v433 = _mm_shuffle_ps(v432, v432, 201);
          *(__m128 *)&v554.m_lastDimB.m_storage = v433;
          v434 = _mm_sub_ps(_mm_mul_ps(v429, v426), _mm_mul_ps(_mm_shuffle_ps(v426, v426, 201), v427));
          v435 = _mm_sub_ps(_mm_mul_ps(v425, v428), _mm_mul_ps(_mm_shuffle_ps(v428, v428, 201), v424));
          v436 = _mm_mul_ps(_mm_shuffle_ps(v434, v434, 201), v433);
          v437 = _mm_mul_ps(_mm_shuffle_ps(v435, v435, 201), v433);
          v438 = _mm_sub_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v430, v430, 201), v431),
                   _mm_mul_ps(_mm_shuffle_ps(v431, v431, 201), v430));
          v439 = _mm_unpacklo_ps(v436, v437);
          v440 = _mm_mul_ps(_mm_shuffle_ps(v438, v438, 201), v433);
          v441 = _mm_movelh_ps(v439, v440);
          v442.m_quad = _mm_add_ps(
                          _mm_shuffle_ps(_mm_unpackhi_ps(v436, v437), v440, 228),
                          _mm_add_ps(v441, _mm_shuffle_ps(_mm_movehl_ps(v441, v439), v440, 212)));
          v443 = _mm_movemask_ps(_mm_cmplt_ps(v442.m_quad, v19)) & 7;
          if ( v443 == 7 )
          {
            v444 = _mm_mul_ps(_mm_sub_ps(v31, v29.m_quad), v433);
            if ( _mm_movemask_ps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v444, v444, 85), _mm_shuffle_ps(v444, v444, 0)),
                     _mm_shuffle_ps(v444, v444, 170))) )
            {
              v554.m_verticesA[0] = v554.m_verticesA[1];
              v445.m_quad = v31;
              v31 = v554.m_verticesA[1].m_quad;
              v554.m_verticesA[1] = (hkcdVertex)v445.m_quad;
              *(__m128 *)&v554.m_lastDimB.m_storage = _mm_xor_ps(
                                                        v433,
                                                        (__m128)_mm_shuffle_epi32(
                                                                  _mm_insert_epi16((__m128i)0i64, 0x8000u, 1),
                                                                  0));
              v442.m_quad = _mm_shuffle_ps(v442.m_quad, v442.m_quad, 225);
            }
          }
          v554.m_checkTriangleDots = (hkVector4f)v442.m_quad;
          if ( v443 == 7 )
            goto LABEL_150;
          v446 = hkcdGskBase::maskToIndex[v443];
          if ( (int)v446 < 0 )
          {
            v447 = v446 + 8;
            if ( v447 < 3 )
            {
              v554.m_verticesBinA[v447 - 4] = v554.m_verticesA[2];
              goto LABEL_135;
            }
LABEL_145:
            dimA.m_storage = 1;
            dimB.m_storage = 1;
LABEL_146:
            v351 = _mm_sub_ps(v31, v29.m_quad);
            goto LABEL_149;
          }
          v472 = hkcdGskBase::vertexToEdgeLut[v446];
          v473 = v446;
          v474 = hkcdGskBase::vertexToEdgeLut[v446 + 2];
          v475 = v554.m_verticesBinA[v473 - 4].m_quad;
          v476 = _mm_sub_ps(v29.m_quad, v475);
          v477 = _mm_sub_ps(v554.m_verticesBinA[v474 - 4].m_quad, v475);
          v478 = _mm_mul_ps(_mm_sub_ps(v554.m_verticesBinA[v472 - 4].m_quad, v475), v476);
          if ( !_mm_movemask_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v478, v478, 85), _mm_shuffle_ps(v478, v478, 0)),
                    _mm_shuffle_ps(v478, v478, 170))) )
          {
            v554.m_verticesBinA[v474 - 4] = v554.m_verticesA[2];
            goto LABEL_135;
          }
          v479 = _mm_mul_ps(v477, v476);
          v554.m_verticesBinA[v472 - 4] = v554.m_verticesA[2];
          if ( !_mm_movemask_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v479, v479, 85), _mm_shuffle_ps(v479, v479, 0)),
                    _mm_shuffle_ps(v479, v479, 170))) )
          {
LABEL_135:
            v29.m_quad = (__m128)v554.m_verticesBinA[0];
            v31 = v554.m_verticesA[0].m_quad;
            v554.m_checkTriangleDots = (hkVector4f)v554.m_verticesBinA[0];
            goto LABEL_136;
          }
          dimA.m_storage = 1;
          if ( (_DWORD)v474 == 2 )
            LODWORD(v474) = v472;
          v554.m_verticesBinA[(int)v474 - 4] = v554.m_verticesA[1];
LABEL_133:
          v31 = v554.m_verticesA[0].m_quad;
          v29.m_quad = (__m128)v554.m_verticesBinA[0];
          v554.m_checkTriangleDots = (hkVector4f)v554.m_verticesBinA[0];
          v351 = _mm_sub_ps(v554.m_verticesA[0].m_quad, v554.m_verticesBinA[0].m_quad);
          goto LABEL_149;
        }
        dimB.m_storage = 3;
LABEL_120:
        v448 = _mm_sub_ps(v29.m_quad, v554.m_verticesBinA[2].m_quad);
        v449 = _mm_sub_ps(v554.m_verticesBinA[2].m_quad, v554.m_verticesBinA[1].m_quad);
        v450 = _mm_shuffle_ps(v448, v448, 201);
        v451 = _mm_sub_ps(v31, v554.m_verticesBinA[1].m_quad);
        v452 = _mm_shuffle_ps(v449, v449, 201);
        v453 = _mm_sub_ps(v31, v554.m_verticesBinA[2].m_quad);
        v454 = _mm_sub_ps(v554.m_verticesBinA[1].m_quad, v29.m_quad);
        v455 = _mm_sub_ps(v31, v29.m_quad);
        v456 = _mm_sub_ps(_mm_mul_ps(v449, v450), _mm_mul_ps(v448, v452));
        v457 = _mm_shuffle_ps(v456, v456, 201);
        *(__m128 *)&v554.m_lastDimB.m_storage = v457;
        v458 = _mm_sub_ps(_mm_mul_ps(v451, v452), _mm_mul_ps(_mm_shuffle_ps(v451, v451, 201), v449));
        v459 = _mm_mul_ps(_mm_shuffle_ps(v458, v458, 201), v457);
        v460 = _mm_sub_ps(_mm_mul_ps(v453, v450), _mm_mul_ps(_mm_shuffle_ps(v453, v453, 201), v448));
        v461 = _mm_mul_ps(_mm_shuffle_ps(v460, v460, 201), v457);
        v462 = _mm_unpacklo_ps(v459, v461);
        v463 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v454, v454, 201), v455),
                 _mm_mul_ps(_mm_shuffle_ps(v455, v455, 201), v454));
        v464 = _mm_mul_ps(_mm_shuffle_ps(v463, v463, 201), v457);
        v465 = _mm_movelh_ps(v462, v464);
        v466.m_quad = _mm_add_ps(
                        _mm_shuffle_ps(_mm_unpackhi_ps(v459, v461), v464, 228),
                        _mm_add_ps(v465, _mm_shuffle_ps(_mm_movehl_ps(v465, v462), v464, 212)));
        v467 = _mm_movemask_ps(_mm_cmplt_ps(v466.m_quad, v19)) & 7;
        if ( v467 == 7 )
        {
          v468 = _mm_mul_ps(v457, v455);
          if ( _mm_movemask_ps(
                 _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v468, v468, 85), _mm_shuffle_ps(v468, v468, 0)),
                   _mm_shuffle_ps(v468, v468, 170))) )
          {
            v554.m_checkTriangleDots = (hkVector4f)v554.m_verticesBinA[1];
            v554.m_verticesBinA[0] = v554.m_verticesBinA[1];
            v469.m_quad = v29.m_quad;
            v29.m_quad = (__m128)v554.m_verticesBinA[1];
            v554.m_verticesBinA[1] = (hkcdVertex)v469.m_quad;
            *(__m128 *)&v554.m_lastDimB.m_storage = _mm_xor_ps(
                                                      v457,
                                                      (__m128)_mm_shuffle_epi32(
                                                                _mm_insert_epi16((__m128i)0i64, 0x8000u, 1),
                                                                0));
            v466.m_quad = _mm_shuffle_ps(v466.m_quad, v466.m_quad, 225);
          }
        }
        v554.m_checkTriangleDots = (hkVector4f)v466.m_quad;
        if ( v467 == 7 )
          goto LABEL_150;
        v470 = hkcdGskBase::maskToIndex[v467];
        if ( (int)v470 >= 0 )
        {
          v494 = hkcdGskBase::vertexToEdgeLut[v470];
          v495 = v470;
          v496 = hkcdGskBase::vertexToEdgeLut[v470 + 2];
          v497 = v554.m_verticesBinA[v495].m_quad;
          v498 = _mm_sub_ps(v31, v497);
          v499 = _mm_sub_ps(v554.m_verticesBinA[v496].m_quad, v497);
          v500 = _mm_mul_ps(_mm_sub_ps(v554.m_verticesBinA[v494].m_quad, v497), v498);
          if ( _mm_movemask_ps(
                 _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v500, v500, 85), _mm_shuffle_ps(v500, v500, 0)),
                   _mm_shuffle_ps(v500, v500, 170))) )
          {
            v501 = _mm_mul_ps(v499, v498);
            v554.m_verticesBinA[v494] = v554.m_verticesBinA[2];
            if ( _mm_movemask_ps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v501, v501, 85), _mm_shuffle_ps(v501, v501, 0)),
                     _mm_shuffle_ps(v501, v501, 170))) )
            {
              dimB.m_storage = 1;
              if ( (_DWORD)v496 == 2 )
                LODWORD(v496) = v494;
              v554.m_verticesBinA[(int)v496] = v554.m_verticesBinA[1];
              goto LABEL_133;
            }
          }
          else
          {
            v554.m_verticesBinA[v496] = v554.m_verticesBinA[2];
          }
        }
        else
        {
          v471 = v470 + 8;
          if ( v471 >= 3 )
            goto LABEL_145;
          v554.m_verticesBinA[v471] = v554.m_verticesBinA[2];
        }
        v29.m_quad = (__m128)v554.m_verticesBinA[0];
        v31 = v554.m_verticesA[0].m_quad;
        v554.m_checkTriangleDots = (hkVector4f)v554.m_verticesBinA[0];
        goto LABEL_90;
      default:
        goto LABEL_65;
    }
  }
};
        goto LABEL_90;
      default:
        goto LABEL_65;
    }
  }
}

// File Line: 87
// RVA: 0x1310A10
__int64 __fastcall hkcdGsk::getClosestPoint(const void *__formal, hkcdVertex *vertsA, int numVertsA, const void *a4)
{
  hkcdVertex *v4; // r11
  __int64 *v5; // r9
  char *v6; // r10
  int v7; // ecx
  int v8; // eax
  int v9; // ebx
  __int64 v10; // rdx
  __int64 *v11; // r8
  __m128 *v12; // r11
  int v13; // ebx
  char *v14; // r10
  __m128 *v15; // r9
  __int64 v16; // r8
  hkTransformf *aTb; // rsi
  __m128 v18; // xmm10
  __m128 v19; // xmm13
  __int64 v20; // rcx
  __m128 m_quad; // xmm3
  __int64 v22; // rax
  __m128 v23; // xmm4
  __m128 v24; // xmm5
  __m128 v25; // xmm6
  __m128 v26; // xmm1
  unsigned int v27; // r14d
  __m128 v28; // xmm12
  __m128 v29; // xmm2
  __m128 v30; // xmm14
  unsigned int v31; // eax
  __m128 v32; // xmm11
  __m128 *v33; // rdx
  __m128 *v34; // rcx
  __m128 v35; // xmm5
  __m128 v36; // xmm6
  __m128 v37; // xmm7
  __m128 v38; // xmm3
  __m128 v39; // xmm2
  __m128 v40; // xmm2
  __m128 v41; // xmm1
  __m128 v42; // xmm4
  __m128 v43; // xmm1
  __m128 v44; // xmm2
  __m128 v45; // xmm1
  __m128 v46; // xmm3
  __m128 v47; // xmm2
  __m128 v48; // xmm1
  __m128 v49; // xmm2
  __m128 v50; // xmm0
  __m128 v51; // xmm7
  __m128 v52; // xmm3
  __m128 v53; // xmm6
  __m128 v54; // xmm5
  __m128 v55; // xmm5
  __m128 v56; // xmm1
  __m128 v57; // xmm5
  __m128 v58; // xmm4
  __m128 v59; // xmm0
  __m128 v60; // xmm2
  __m128 v61; // xmm7
  __m128 v62; // xmm1
  __m128 v63; // xmm4
  __m128 v64; // xmm1
  __m128 v65; // xmm7
  __m128 v66; // xmm2
  int v67; // ecx
  __m128 v68; // xmm1
  __m128 v69; // xmm3
  __m128 v70; // xmm15
  __m128 v71; // xmm6
  __m128 v72; // xmm8
  __m128 v73; // xmm4
  __m128 v74; // xmm9
  __m128 v75; // xmm8
  __m128 v76; // xmm7
  __m128 v77; // xmm2
  __m128 v78; // xmm5
  __m128 v79; // xmm1
  __m128 v80; // xmm13
  __m128 v81; // xmm9
  __m128 v82; // xmm9
  __m128 v83; // xmm7
  __m128 v84; // xmm0
  __m128 v85; // xmm7
  __m128 v86; // xmm8
  __m128 v87; // xmm1
  __m128 v88; // xmm8
  __m128 v89; // xmm8
  __m128 v90; // xmm2
  __m128 v91; // xmm9
  int v92; // r8d
  __m128 v93; // xmm14
  __m128 v94; // xmm1
  __m128 v95; // xmm2
  __m128 v96; // xmm15
  __m128 v97; // xmm1
  __m128 v98; // xmm9
  __m128 v99; // xmm1
  __m128 v100; // xmm2
  __m128 v101; // xmm8
  __m128 v102; // xmm12
  __m128 v103; // xmm1
  __m128 v104; // xmm7
  __m128 v105; // xmm4
  __m128 v106; // xmm1
  __m128 v107; // xmm2
  __m128 v108; // xmm1
  __m128 v109; // xmm3
  __m128 v110; // xmm1
  __m128 v111; // xmm1
  __m128 v112; // xmm6
  __m128 v113; // xmm0
  __m128 v114; // xmm2
  __m128 v115; // xmm0
  __m128 v116; // xmm3
  __m128 v117; // xmm1
  __m128 v118; // xmm5
  __m128 v119; // xmm0
  __m128 v120; // xmm2
  __m128 v121; // xmm1
  __m128 v122; // xmm2
  __m128 v123; // xmm11
  __m128 v124; // xmm9
  __m128 v125; // xmm1
  __m128 v126; // xmm5
  __m128 v127; // xmm1
  __m128 v128; // xmm8
  __m128 v129; // xmm1
  __m128 v130; // xmm7
  __m128 v131; // xmm5
  __m128 v132; // xmm1
  __m128 v133; // xmm3
  __m128 v134; // xmm1
  __m128 v135; // xmm4
  __m128 v136; // xmm1
  __m128 v137; // xmm2
  __m128 v138; // xmm6
  __m128 v139; // xmm0
  __m128 v140; // xmm3
  __m128 v141; // xmm0
  __m128 v142; // xmm5
  __m128 v143; // xmm4
  __m128 v144; // xmm2
  __m128 v145; // xmm0
  __m128 v146; // xmm3
  __m128 v147; // xmm3
  __m128 v148; // xmm2
  __m128 v149; // xmm8
  __m128 v150; // xmm15
  __m128 v151; // xmm11
  __m128 v152; // xmm1
  __m128 v153; // xmm3
  __m128 v154; // xmm1
  __m128 v155; // xmm2
  __m128 v156; // xmm0
  __m128 v157; // xmm0
  __m128 v158; // xmm1
  __m128 v159; // xmm3
  __m128 v160; // xmm6
  __m128 v161; // xmm6
  __m128 v162; // xmm7
  __m128 v163; // xmm4
  __m128 v164; // xmm5
  __m128 v165; // xmm1
  __m128 v166; // xmm6
  __m128 v167; // xmm3
  __m128 v168; // xmm0
  __m128 v169; // xmm2
  __m128 v170; // xmm7
  __m128 v171; // xmm1
  __m128 v172; // xmm3
  __m128 v173; // xmm1
  __m128 v174; // xmm7
  __m128 v175; // xmm2
  __m128 v176; // xmm1
  __m128 v177; // xmm3
  __m128 v178; // xmm6
  __m128 v179; // xmm9
  __m128 v180; // xmm5
  __m128 v181; // xmm10
  __m128 v182; // xmm7
  __m128 v183; // xmm15
  __m128 v184; // xmm10
  __m128 v185; // xmm4
  __m128 v186; // xmm7
  __m128 v187; // xmm2
  __m128 v188; // xmm8
  __m128 v189; // xmm8
  __m128 v190; // xmm10
  __m128 v191; // xmm7
  __m128 v192; // xmm10
  __m128 v193; // xmm7
  __m128 v194; // xmm1
  __m128 v195; // xmm9
  __m128 v196; // xmm9
  __m128 v197; // xmm2
  __m128 v198; // xmm10
  int v199; // eax
  float v200; // xmm1_4
  float v201; // xmm11_4
  float v202; // xmm1_4
  float v203; // xmm11_4
  int v204; // ecx
  __m128 v205; // xmm15
  __m128 v206; // xmm7
  __m128 v207; // xmm5
  __m128 v208; // xmm2
  __m128 v209; // xmm4
  __m128 v210; // xmm13
  __m128 v211; // xmm1
  __m128 v212; // xmm4
  __m128 v213; // xmm4
  __m128 v214; // xmm2
  __m128 v215; // xmm9
  __m128 v216; // xmm1
  __m128 v217; // xmm0
  __m128 v218; // xmm2
  __m128 v219; // xmm1
  __m128 v220; // xmm3
  __m128 v221; // xmm2
  __m128 v222; // xmm6
  __m128 v223; // xmm2
  __m128 v224; // xmm6
  int v225; // ecx
  int v226; // ecx
  int v227; // ecx
  int v228; // ecx
  __m128 v229; // xmm1
  __m128 v230; // xmm2
  __m128 v231; // xmm11
  __m128 v232; // xmm1
  __m128 v233; // xmm2
  __m128 v234; // xmm5
  __m128 v235; // xmm10
  __m128 v236; // xmm1
  __m128 v237; // xmm9
  __m128 v238; // xmm6
  __m128 v239; // xmm1
  __m128 v240; // xmm3
  __m128 v241; // xmm1
  __m128 v242; // xmm5
  __m128 v243; // xmm1
  __m128 v244; // xmm7
  __m128 v245; // xmm0
  __m128 v246; // xmm2
  __m128 v247; // xmm1
  __m128 v248; // xmm2
  __m128 v249; // xmm8
  __m128 v250; // xmm1
  __m128 v251; // xmm0
  __m128 v252; // xmm3
  __m128 v253; // xmm2
  __m128 v254; // xmm0
  __m128 v255; // xmm0
  int v256; // ecx
  float v257; // xmm1_4
  float v258; // xmm11_4
  int v259; // eax
  int v260; // eax
  int v261; // eax
  __m128 v262; // xmm1
  __m128 v263; // xmm3
  __m128 v264; // xmm2
  __m128 v265; // xmm6
  __m128 v266; // xmm2
  __m128 v267; // xmm3
  __m128 v268; // xmm4
  __m128 v269; // xmm1
  __m128 v270; // xmm15
  __m128 v271; // xmm5
  __m128 v272; // xmm1
  __m128 v273; // xmm4
  __m128 v274; // xmm1
  __m128 v275; // xmm4
  __m128 v276; // xmm2
  __m128 v277; // xmm8
  __m128 v278; // xmm10
  __m128 v279; // xmm11
  __m128 v280; // xmm7
  __m128 v281; // xmm3
  __int128 v282; // xmm1
  __m128 v283; // xmm8
  __m128 v284; // xmm9
  __m128 v285; // xmm1
  __m128 v286; // xmm1
  int v287; // r8d
  int v288; // r9d
  hkcdVertex *v289; // rcx
  __m128 v290; // xmm1
  __m128 *v291; // rdx
  int v292; // eax
  __m128 v293; // xmm0
  __m128 v294; // xmm12
  __m128 v295; // xmm1
  __m128 v296; // xmm12
  __m128 v297; // xmm1
  __m128 v298; // xmm6
  __m128 v299; // xmm1
  __m128 v300; // xmm15
  __m128 v301; // xmm1
  __m128 v302; // xmm2
  __m128 v303; // xmm1
  __m128 v304; // xmm2
  __m128 v305; // xmm1
  __int64 v306; // r10
  __m128 v307; // xmm1
  __m128 v308; // xmm2
  __m128 v309; // xmm4
  __m128 v310; // xmm3
  __m128 v311; // xmm1
  __m128 v312; // xmm6
  __m128 v313; // xmm14
  __m128 v314; // xmm1
  __m128 v315; // xmm9
  __m128 v316; // xmm12
  __m128 v317; // xmm11
  __m128 v318; // xmm1
  __m128 v319; // xmm10
  __m128 v320; // xmm1
  __m128 v321; // xmm1
  __m128 v322; // xmm1
  __m128 v323; // xmm13
  __m128 v324; // xmm1
  __m128 v325; // xmm13
  __m128 v326; // xmm14
  __m128 v327; // xmm15
  __m128 *p_m_quad; // rcx
  __int64 v329; // r8
  __m128 v330; // xmm9
  __m128 v331; // xmm1
  __m128 v332; // xmm8
  __m128 v333; // xmm1
  __m128 v334; // xmm12
  __m128 v335; // xmm1
  __m128 v336; // xmm1
  __m128 v337; // xmm13
  __m128 v338; // xmm14
  __m128 *v339; // rcx
  __int64 v340; // rdx
  __m128 v341; // xmm1
  __m128 v342; // xmm8
  __m128 v343; // xmm12
  __m128 v344; // xmm1
  __m128 v345; // xmm1
  __m128 v346; // xmm6
  __m128 v347; // xmm1
  __m128 v348; // xmm9
  __m128 v349; // xmm11
  __m128 v350; // xmm15
  __m128 v351; // xmm8
  __m128 v352; // xmm6
  __m128 v353; // xmm9
  __m128 v354; // xmm5
  __m128 v355; // xmm1
  __m128 v356; // xmm4
  __m128 v357; // xmm1
  __m128 v358; // xmm2
  int v359; // eax
  __m128 v360; // xmm4
  __m128 v361; // xmm1
  __m128 v362; // xmm2
  __m128 v363; // xmm1
  __m128 v364; // xmm1
  __m128 v365; // xmm8
  __m128 v366; // xmm15
  __m128 v367; // xmm2
  __m128 v368; // xmm6
  __m128 v369; // xmm1
  __m128 v370; // xmm15
  __m128 *v371; // r9
  __m128 v372; // xmm1
  __m128 v373; // xmm2
  __m128 v374; // xmm6
  __m128 v375; // xmm4
  __m128 v376; // xmm5
  __m128 v377; // xmm3
  __m128 v378; // xmm0
  __m128 v379; // xmm1
  __m128 v380; // xmm9
  __m128 v381; // xmm9
  __m128 v382; // xmm3
  __m128 v383; // xmm8
  __m128 v384; // xmm8
  __m128 v385; // xmm0
  __m128 v386; // xmm8
  __m128 v387; // xmm4
  __m128 v388; // xmm5
  __m128 v389; // xmm9
  __m128 v390; // xmm4
  __m128 v391; // xmm1
  __m128 v392; // xmm5
  __m128 v393; // xmm3
  __m128 v394; // xmm2
  __m128 v395; // xmm0
  __m128 v396; // xmm1
  __m128 v397; // xmm4
  __m128i v398; // xmm5
  __m128 v399; // xmm2
  __m128 v400; // xmm9
  __m128 v401; // xmm0
  __m128 v402; // xmm4
  __m128 v403; // xmm4
  __m128 v404; // xmm6
  int v405; // edx
  __m128 v406; // xmm2
  int v407; // eax
  int v408; // ecx
  int v409; // ebx
  __int64 v410; // rdi
  __int64 v411; // r10
  __int64 v412; // r8
  __int64 v413; // r11
  int v414; // edx
  __m128 v415; // xmm0
  __m128 v416; // xmm2
  __m128 v417; // xmm4
  __m128 v418; // xmm7
  __m128 v419; // xmm5
  __m128 v420; // xmm1
  __m128 v421; // xmm3
  __m128 v422; // xmm4
  __m128 v423; // xmm7
  __m128 v424; // xmm5
  __m128 v425; // xmm6
  __m128 v426; // xmm1
  __m128 v427; // xmm4
  __m128 v428; // xmm2
  __m128 v429; // xmm11
  __m128 v430; // xmm7
  __m128 v431; // xmm3
  __m128 v432; // xmm8
  __m128 v433; // xmm8
  __m128 v434; // xmm11
  __m128 v435; // xmm6
  __m128 v436; // xmm11
  __m128 v437; // xmm6
  __m128 v438; // xmm7
  __m128 v439; // xmm1
  __m128 v440; // xmm7
  __m128 v441; // xmm2
  __m128 v442; // xmm11
  int v443; // ecx
  __m128 v444; // xmm2
  __m128 v445; // xmm0
  __int64 v446; // rcx
  int v447; // ecx
  __m128 v448; // xmm5
  __m128 v449; // xmm3
  __m128 v450; // xmm4
  __m128 v451; // xmm11
  __m128 v452; // xmm1
  __m128 v453; // xmm6
  __m128 v454; // xmm7
  __m128 v455; // xmm13
  __m128 v456; // xmm8
  __m128 v457; // xmm8
  __m128 v458; // xmm11
  __m128 v459; // xmm11
  __m128 v460; // xmm6
  __m128 v461; // xmm6
  __m128 v462; // xmm1
  __m128 v463; // xmm7
  __m128 v464; // xmm7
  __m128 v465; // xmm2
  __m128 v466; // xmm11
  int v467; // ecx
  __m128 v468; // xmm2
  __m128 v469; // xmm0
  __int64 v470; // rcx
  int v471; // ecx
  __int64 v472; // r9
  __int64 v473; // rax
  __int64 v474; // rcx
  __m128 v475; // xmm0
  __m128 v476; // xmm12
  __m128 v477; // xmm3
  __m128 v478; // xmm2
  __m128 v479; // xmm3
  __m128 v480; // xmm4
  __m128 v481; // xmm9
  __m128 v482; // xmm5
  __m128 v483; // xmm1
  __m128 v484; // xmm2
  __m128 v485; // xmm1
  __m128 v486; // xmm6
  __m128 v487; // xmm4
  __m128 v488; // xmm1
  __m128 v489; // xmm2
  __m128 v490; // xmm8
  __m128 v491; // xmm8
  __m128 v492; // xmm8
  __m128 v493; // xmm2
  __int64 v494; // r9
  __int64 v495; // rax
  __int64 v496; // rcx
  __m128 v497; // xmm0
  __m128 v498; // xmm14
  __m128 v499; // xmm3
  __m128 v500; // xmm2
  __m128 v501; // xmm3
  __m128 v502; // xmm4
  __m128 v503; // xmm6
  __m128 v504; // xmm8
  __m128 v505; // xmm2
  __m128 v506; // xmm4
  __m128 v507; // xmm7
  __m128 v508; // xmm3
  __m128 v509; // xmm5
  __m128 v510; // xmm9
  __m128 v511; // xmm10
  __m128 v512; // xmm9
  __m128 v513; // xmm6
  __m128 v514; // xmm0
  __m128 v515; // xmm3
  __m128 v516; // xmm1
  __m128 v517; // xmm2
  __m128 v518; // xmm7
  __m128 v519; // xmm6
  __m128 v520; // xmm4
  __m128 v521; // xmm3
  __m128 v522; // xmm2
  __m128 v523; // xmm0
  __m128 v524; // xmm1
  __m128 v525; // xmm3
  __m128 v526; // xmm0
  __m128 v527; // xmm7
  __m128 v528; // xmm14
  __m128 v529; // xmm1
  _QWORD *Value; // rbx
  unsigned __int64 v531; // rcx
  unsigned __int64 v532; // rax
  unsigned int v533; // eax
  _QWORD *v534; // rcx
  unsigned __int64 v535; // rax
  _QWORD *v536; // rcx
  __int64 v537; // rdi
  char v538; // bl
  char v539; // r11
  char v540; // dl
  char v541; // r8
  char v542; // r9
  char v543; // r10
  __int64 result; // rax
  _BYTE v545[56]; // [rsp+48h] [rbp-80h] BYREF
  __m128 v546; // [rsp+88h] [rbp-40h] BYREF
  __m128 v547; // [rsp+98h] [rbp-30h]
  __m128 v548; // [rsp+A8h] [rbp-20h]
  __int64 v549; // [rsp+C0h] [rbp-8h] BYREF
  __m128 v550; // [rsp+C8h] [rbp+0h] BYREF
  __m128 v551; // [rsp+D8h] [rbp+10h]
  __m128 v552; // [rsp+E8h] [rbp+20h]
  __m128 v553; // [rsp+118h] [rbp+50h]
  __m128 v554; // [rsp+128h] [rbp+60h]
  __m128 v555; // [rsp+138h] [rbp+70h]
  __m128 v556; // [rsp+148h] [rbp+80h]
  __m128 v557; // [rsp+158h] [rbp+90h]
  __m128 v558; // [rsp+168h] [rbp+A0h]
  __int128 v559; // [rsp+178h] [rbp+B0h]
  __m128 v560; // [rsp+188h] [rbp+C0h]
  __m128 v561; // [rsp+198h] [rbp+D0h]
  __m128 v562; // [rsp+1A8h] [rbp+E0h]
  __m128 v563; // [rsp+1B8h] [rbp+F0h]
  __m128 v564; // [rsp+1C8h] [rbp+100h]
  __m128 *shapeB; // [rsp+1D8h] [rbp+110h] BYREF
  int m_storage; // [rsp+1E0h] [rbp+118h]
  __m128 v567; // [rsp+1E8h] [rbp+120h]
  hkcdVertex *shapeA; // [rsp+1F8h] [rbp+130h] BYREF
  int v569; // [rsp+200h] [rbp+138h]
  __m128 v570; // [rsp+208h] [rbp+140h]
  __m128 v571; // [rsp+218h] [rbp+150h]
  __m128 v572; // [rsp+228h] [rbp+160h]
  __m128 v573; // [rsp+238h] [rbp+170h]
  __m128 v574; // [rsp+248h] [rbp+180h]
  __m128 v575; // [rsp+258h] [rbp+190h]
  __m128 v576; // [rsp+268h] [rbp+1A0h]
  __m128 v577; // [rsp+278h] [rbp+1B0h]
  __m128 v578; // [rsp+288h] [rbp+1C0h]
  __int128 v579; // [rsp+298h] [rbp+1D0h]
  __m128 v580; // [rsp+2A8h] [rbp+1E0h]
  __m128 v581; // [rsp+2B8h] [rbp+1F0h]
  __m128 v582; // [rsp+2C8h] [rbp+200h]
  __m128 v583; // [rsp+2D8h] [rbp+210h]
  __m128 v584; // [rsp+2E8h] [rbp+220h]
  __m128 v585; // [rsp+2F8h] [rbp+230h]
  __m128 v586; // [rsp+308h] [rbp+240h]
  __m128 v587; // [rsp+318h] [rbp+250h]
  __m128 v588; // [rsp+328h] [rbp+260h]
  __m128 v589; // [rsp+338h] [rbp+270h]
  __m128 v590; // [rsp+348h] [rbp+280h]
  __m128 v591; // [rsp+358h] [rbp+290h]
  __int128 v592; // [rsp+368h] [rbp+2A0h]
  __m128 v593; // [rsp+378h] [rbp+2B0h]
  __m128 v594; // [rsp+388h] [rbp+2C0h]
  __m128 v595; // [rsp+398h] [rbp+2D0h]
  __m128 v596; // [rsp+3A8h] [rbp+2E0h]
  __m128 v597; // [rsp+3B8h] [rbp+2F0h]
  __m128 v598; // [rsp+3C8h] [rbp+300h]
  __m128 v599; // [rsp+3D8h] [rbp+310h]
  __m128 v600; // [rsp+3E8h] [rbp+320h]
  __m128 v601[7]; // [rsp+3F8h] [rbp+330h] BYREF
  hkVector4f supportOut; // [rsp+468h] [rbp+3A0h] BYREF
  __m128 v603; // [rsp+478h] [rbp+3B0h]
  __m128 v604; // [rsp+488h] [rbp+3C0h]
  __m128 v605; // [rsp+498h] [rbp+3D0h]
  __m128 v606; // [rsp+4A8h] [rbp+3E0h]
  __m128 v607; // [rsp+4B8h] [rbp+3F0h]
  __m128 v608; // [rsp+4C8h] [rbp+400h]
  __m128 v609; // [rsp+4D8h] [rbp+410h]
  __m128 v610; // [rsp+4E8h] [rbp+420h]
  __m128 v611; // [rsp+4F8h] [rbp+430h]
  __m128 v612; // [rsp+508h] [rbp+440h]
  __m128 v613; // [rsp+518h] [rbp+450h]
  hkVector4f v614; // [rsp+528h] [rbp+460h]
  __m128 v615; // [rsp+538h] [rbp+470h]
  __m128 v616; // [rsp+548h] [rbp+480h]
  __m128 v617; // [rsp+558h] [rbp+490h]
  __m128 v618; // [rsp+568h] [rbp+4A0h]
  __int128 v619; // [rsp+578h] [rbp+4B0h]
  __m128 v620; // [rsp+588h] [rbp+4C0h]
  __m128 v621; // [rsp+598h] [rbp+4D0h]
  __m128 v622; // [rsp+5A8h] [rbp+4E0h]
  __m128 v623; // [rsp+5B8h] [rbp+4F0h]
  __m128 v624; // [rsp+5C8h] [rbp+500h]
  __m128 v625; // [rsp+5D8h] [rbp+510h]
  __m128 v626; // [rsp+5E8h] [rbp+520h]
  __m128 v627; // [rsp+5F8h] [rbp+530h]
  __m128 v628; // [rsp+608h] [rbp+540h]
  __m128 v629; // [rsp+618h] [rbp+550h]
  __m128 v630; // [rsp+628h] [rbp+560h]
  __m128 v631; // [rsp+638h] [rbp+570h]
  __m128 v632; // [rsp+648h] [rbp+580h]
  __m128 v633; // [rsp+658h] [rbp+590h]
  __m128 v634; // [rsp+668h] [rbp+5A0h]
  __m128 v635; // [rsp+678h] [rbp+5B0h]
  __m128 v636; // [rsp+688h] [rbp+5C0h]
  __m128 v637; // [rsp+698h] [rbp+5D0h]
  __m128 v638; // [rsp+6A8h] [rbp+5E0h]
  __m128 v639; // [rsp+6B8h] [rbp+5F0h]
  __m128 v640; // [rsp+6C8h] [rbp+600h]
  __m128 v641; // [rsp+6D8h] [rbp+610h]
  __int128 v642; // [rsp+6E8h] [rbp+620h]
  __m128 v643; // [rsp+6F8h] [rbp+630h]
  __m128 v644; // [rsp+708h] [rbp+640h]
  __m128 v645; // [rsp+718h] [rbp+650h]
  __m128 v646; // [rsp+728h] [rbp+660h]
  __m128 v647; // [rsp+738h] [rbp+670h]
  __m128 v648; // [rsp+748h] [rbp+680h]
  __m128 v649; // [rsp+758h] [rbp+690h]
  __m128 v650; // [rsp+768h] [rbp+6A0h]
  __m128 v651; // [rsp+778h] [rbp+6B0h]
  __m128 v652; // [rsp+788h] [rbp+6C0h]
  __m128 v653; // [rsp+798h] [rbp+6D0h]
  __m128 v654; // [rsp+7A8h] [rbp+6E0h]
  __m128 v655; // [rsp+7B8h] [rbp+6F0h]
  __m128 v656; // [rsp+7C8h] [rbp+700h]
  __m128 v657; // [rsp+7D8h] [rbp+710h]
  __m128 v658; // [rsp+7E8h] [rbp+720h]
  __m128 v659; // [rsp+7F8h] [rbp+730h]
  __m128 v660; // [rsp+808h] [rbp+740h]
  __m128 v661; // [rsp+818h] [rbp+750h]
  __m128 v662; // [rsp+828h] [rbp+760h]
  __m128 v663; // [rsp+838h] [rbp+770h]
  __m128 v664; // [rsp+848h] [rbp+780h]
  __m128 v665; // [rsp+858h] [rbp+790h]
  __m128 v666; // [rsp+868h] [rbp+7A0h]
  __m128 v667; // [rsp+878h] [rbp+7B0h]
  __m128 v668; // [rsp+888h] [rbp+7C0h]
  __m128 v669; // [rsp+898h] [rbp+7D0h]
  __m128 v670; // [rsp+8A8h] [rbp+7E0h]
  __m128 v671; // [rsp+8B8h] [rbp+7F0h]
  __int128 v672; // [rsp+8C8h] [rbp+800h]
  __m128 v673; // [rsp+8D8h] [rbp+810h]
  __m128 v674; // [rsp+8E8h] [rbp+820h]
  __m128 v675; // [rsp+8F8h] [rbp+830h]
  __m128 v676; // [rsp+908h] [rbp+840h]
  __m128 v677; // [rsp+918h] [rbp+850h]
  __m128 v678; // [rsp+928h] [rbp+860h]
  __m128 v679; // [rsp+938h] [rbp+870h]
  __m128 v680; // [rsp+948h] [rbp+880h]
  __m128 v681; // [rsp+958h] [rbp+890h]
  __m128 v682; // [rsp+968h] [rbp+8A0h]
  __m128 v683; // [rsp+978h] [rbp+8B0h]
  __m128 v684; // [rsp+988h] [rbp+8C0h]
  __m128 v685; // [rsp+998h] [rbp+8D0h]
  __m128 v686; // [rsp+9A8h] [rbp+8E0h]
  __m128 v687; // [rsp+9B8h] [rbp+8F0h]
  __m128 v688; // [rsp+9C8h] [rbp+900h]
  __m128 v689; // [rsp+9D8h] [rbp+910h]
  __m128 v690; // [rsp+9E8h] [rbp+920h]
  __m128 v691; // [rsp+9F8h] [rbp+930h]
  __m128 v692; // [rsp+A08h] [rbp+940h]
  __m128 v693; // [rsp+A18h] [rbp+950h]
  __m128 v694; // [rsp+A28h] [rbp+960h]
  __m128 v695; // [rsp+A38h] [rbp+970h]
  __m128 v696; // [rsp+A48h] [rbp+980h]
  __m128 v697; // [rsp+A58h] [rbp+990h]
  __m128 v698; // [rsp+A68h] [rbp+9A0h]
  __m128 v699; // [rsp+A78h] [rbp+9B0h]
  hkcdGskBase::ShapeInterface shapeInterface; // [rsp+B70h] [rbp+AA8h] BYREF
  hkPadSpu<int> dimB; // [rsp+B78h] [rbp+AB0h] BYREF
  __m128 *v702; // [rsp+B88h] [rbp+AC0h]
  hkPadSpu<int> dimA; // [rsp+B90h] [rbp+AC8h] BYREF
  hkTransformf *retaddr; // [rsp+B98h] [rbp+AD0h]
  char *v705; // [rsp+BA0h] [rbp+AD8h]
  hkcdGsk::GetClosestPointOutput *v706; // [rsp+BA8h] [rbp+AE0h]

  shapeA = vertsA;
  v569 = numVertsA;
  v4 = vertsA;
  v5 = &v549;
  v6 = v705;
  shapeInterface.vfptr = (hkcdGskBase::ShapeInterfaceVtbl *)&hkcdGsk_Vector4ShapeInterface::`vftable;
  shapeB = v702;
  m_storage = dimA.m_storage;
  v7 = (unsigned __int8)v705[4] >> 6;
  v8 = v705[4] & 3;
  v9 = v7;
  while ( 1 )
  {
    v10 = (unsigned __int8)*v6;
    v11 = v5;
    v5 += 2;
    ++v6;
    *(hkcdVertex *)v11 = v4[v10];
    if ( !--v9 )
      break;
    v4 = shapeA;
  }
  v12 = v601;
  v13 = v8;
  v14 = &v705[(unsigned __int64)(unsigned __int8)v705[4] >> 6];
  do
  {
    v15 = v12;
    v16 = (unsigned __int8)*v14;
    ++v12;
    ++v14;
    *v15 = shapeB[v16];
    --v13;
  }
  while ( v13 );
  aTb = retaddr;
  dimB.m_storage = v8;
  dimA.m_storage = v7;
  v18 = 0i64;
  v19 = 0i64;
  *(_OWORD *)&v545[40] = 0i64;
  v20 = v8 - 1;
  m_quad = retaddr->m_rotation.m_col0.m_quad;
  v22 = v20;
  v614.m_quad = (__m128)retaddr->m_rotation.m_col0;
  v23 = retaddr->m_rotation.m_col1.m_quad;
  v615 = v23;
  v24 = retaddr->m_rotation.m_col2.m_quad;
  v616 = v24;
  v25 = retaddr->m_translation.m_quad;
  v617 = v25;
  do
  {
    v26 = v601[v22--];
    --v20;
    *(__m128 *)((char *)&v551 + v22 * 16) = _mm_add_ps(
                                              _mm_add_ps(
                                                _mm_add_ps(
                                                  _mm_mul_ps(_mm_shuffle_ps(v26, v26, 85), v23),
                                                  _mm_mul_ps(_mm_shuffle_ps(v26, v26, 0), m_quad)),
                                                _mm_mul_ps(_mm_shuffle_ps(v26, v26, 170), v24)),
                                              v25);
  }
  while ( v20 >= 0 );
  v27 = 0;
  v28 = _mm_shuffle_ps(v550, _mm_unpackhi_ps(v550, v601[0]), 196);
  v550 = v28;
  v551 = _mm_shuffle_ps(v551, _mm_unpackhi_ps(v551, v601[1]), 196);
  *(float *)&v702 = FLOAT_0_0000099999997;
  v552 = _mm_shuffle_ps(v552, _mm_unpackhi_ps(v552, v601[2]), 196);
  v29 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_0000099999997), (__m128)LODWORD(FLOAT_0_0000099999997), 0);
LABEL_9:
  v30 = v546;
  LODWORD(v702) = aTb[1].m_rotation.m_col2.m_quad.m128_i32[0];
  *(__m128 *)&v545[24] = v28;
  *(_QWORD *)&v545[16] = v546.m128_u64[1];
  v31 = (dimB.m_storage | (8 * dimA.m_storage)) - 9;
  v574 = _mm_mul_ps(v29, _mm_shuffle_ps((__m128)(unsigned int)v702, (__m128)(unsigned int)v702, 0));
  v32 = query.m_quad;
  *(hkVector4f *)v545 = (hkVector4f)query.m_quad;
  while ( 2 )
  {
    switch ( v31 )
    {
      case 0u:
        goto LABEL_145;
      case 1u:
        goto LABEL_89;
      case 2u:
        goto LABEL_119;
      case 3u:
        v370 = v30;
        v371 = &v550;
        goto LABEL_96;
      case 8u:
        goto LABEL_135;
      case 9u:
        goto LABEL_43;
      case 0xAu:
        v33 = &v546;
        v34 = &v550;
        goto LABEL_13;
      case 0x10u:
        goto LABEL_111;
      case 0x11u:
        v33 = &v550;
        v34 = &v546;
LABEL_13:
        if ( *(_DWORD *)&v545[48] == 2 )
        {
          v35 = *v34;
          v36 = *v33;
          v37 = v33[1];
          v556 = v34[1];
          v38 = _mm_sub_ps(v35, v34[2]);
          *(__m128 *)&v545[16] = _mm_sub_ps(v556, v34[2]);
          v554 = v38;
          v39 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v38, v38, 201), *(__m128 *)&v545[16]),
                  _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v545[16], *(__m128 *)&v545[16], 201), v38));
          v40 = _mm_shuffle_ps(v39, v39, 201);
          v41 = _mm_mul_ps(_mm_sub_ps(v36, v35), v40);
          v42 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v41, v41, 85), _mm_shuffle_ps(v41, v41, 0)),
                  _mm_shuffle_ps(v41, v41, 170));
          v43 = _mm_mul_ps(_mm_sub_ps(v37, v35), v40);
          v44 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v43, v43, 85), _mm_shuffle_ps(v43, v43, 0)),
                  _mm_shuffle_ps(v43, v43, 170));
          v45 = _mm_mul_ps(v42, v42);
          v46 = _mm_mul_ps(v44, v44);
          if ( _mm_movemask_ps(_mm_mul_ps(v42, v44)) )
          {
            v673 = _mm_sub_ps(v42, v44);
            v47 = _mm_rcp_ps(v673);
            v604 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v47, v673)), v47), v42);
            v48 = _mm_sub_ps(v34[1], *v34);
            v49 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v33[1], *v33), v604), *v33);
            v50 = _mm_sub_ps(v34[2], *v34);
            v51 = _mm_sub_ps(v34[1], v49);
            v52 = _mm_sub_ps(v34[2], v49);
            v53 = _mm_sub_ps(*v34, v49);
            v54 = _mm_sub_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v50, v50, 201), v48),
                    _mm_mul_ps(_mm_shuffle_ps(v48, v48, 201), v50));
            v55 = _mm_shuffle_ps(v54, v54, 201);
            v56 = _mm_shuffle_ps(v55, v55, 210);
            v57 = _mm_shuffle_ps(v55, v55, 201);
            v58 = _mm_mul_ps(
                    _mm_sub_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v52, v52, 201), v56),
                      _mm_mul_ps(_mm_shuffle_ps(v52, v52, 210), v57)),
                    v51);
            v59 = _mm_shuffle_ps(v51, v51, 210);
            v60 = _mm_mul_ps(
                    _mm_sub_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v53, v53, 201), v56),
                      _mm_mul_ps(_mm_shuffle_ps(v53, v53, 210), v57)),
                    v52);
            v61 = _mm_mul_ps(_mm_shuffle_ps(v51, v51, 201), v56);
            v62 = v58;
            v63 = _mm_unpackhi_ps(v58, v60);
            v64 = _mm_unpacklo_ps(v62, v60);
            v65 = _mm_mul_ps(_mm_sub_ps(v61, _mm_mul_ps(v59, v57)), v53);
            v66 = _mm_movelh_ps(v64, v65);
            if ( (_mm_movemask_ps(
                    _mm_cmplt_ps(
                      v18,
                      _mm_add_ps(
                        _mm_shuffle_ps(v63, v65, 228),
                        _mm_add_ps(v66, _mm_shuffle_ps(_mm_movehl_ps(v66, v64), v65, 212))))) & 7) == 7 )
            {
              v67 = 1;
              goto LABEL_39;
            }
            goto LABEL_22;
          }
          v68 = _mm_cmplt_ps(v45, v46);
          v69 = v34[2];
          v70 = _mm_or_ps(_mm_andnot_ps(v68, v37), _mm_and_ps(v68, v36));
          v71 = _mm_sub_ps(v35, v69);
          v72 = v34[1];
          v73 = _mm_sub_ps(v69, v72);
          v74 = _mm_sub_ps(v70, v72);
          v75 = _mm_sub_ps(v72, v35);
          v76 = _mm_sub_ps(v70, v69);
          v77 = _mm_shuffle_ps(v73, v73, 201);
          v78 = _mm_shuffle_ps(v71, v71, 201);
          v79 = _mm_sub_ps(v70, *v34);
          v80 = _mm_sub_ps(_mm_mul_ps(v73, v78), _mm_mul_ps(v71, v77));
          v19 = _mm_shuffle_ps(v80, v80, 201);
          *(__m128 *)&v545[40] = v19;
          v81 = _mm_sub_ps(_mm_mul_ps(v74, v77), _mm_mul_ps(_mm_shuffle_ps(v74, v74, 201), v73));
          v82 = _mm_mul_ps(_mm_shuffle_ps(v81, v81, 201), v19);
          v83 = _mm_sub_ps(_mm_mul_ps(v76, v78), _mm_mul_ps(_mm_shuffle_ps(v76, v76, 201), v71));
          v84 = _mm_mul_ps(_mm_shuffle_ps(v79, v79, 201), v75);
          v85 = _mm_mul_ps(_mm_shuffle_ps(v83, v83, 201), v19);
          v86 = _mm_mul_ps(_mm_shuffle_ps(v75, v75, 201), v79);
          v87 = _mm_unpacklo_ps(v82, v85);
          v88 = _mm_sub_ps(v86, v84);
          v89 = _mm_mul_ps(_mm_shuffle_ps(v88, v88, 201), v19);
          v90 = _mm_movelh_ps(v87, v89);
          v91 = _mm_add_ps(
                  _mm_shuffle_ps(_mm_unpackhi_ps(v82, v85), v89, 228),
                  _mm_add_ps(v90, _mm_shuffle_ps(_mm_movehl_ps(v90, v87), v89, 212)));
          v92 = _mm_movemask_ps(_mm_cmplt_ps(v91, v18)) & 7;
          if ( v92 == 7 )
          {
            v93 = _mm_mul_ps(_mm_sub_ps(v30, v28), v19);
            if ( _mm_movemask_ps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v93, v93, 85), _mm_shuffle_ps(v93, v93, 0)),
                     _mm_shuffle_ps(v93, v93, 170))) )
            {
              v94 = *v34;
              v19 = _mm_xor_ps(v19, (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0));
              *v34 = v556;
              v34[1] = v94;
              v32 = query.m_quad;
              *(__m128 *)&v545[40] = v19;
              v91 = _mm_shuffle_ps(v91, v91, 225);
              *(hkVector4f *)v545 = (hkVector4f)query.m_quad;
            }
          }
          *(__m128 *)&v545[32] = v91;
          if ( v92 != 7 )
          {
LABEL_22:
            v95 = _mm_sub_ps(v34[2], *v33);
            v96 = _mm_sub_ps(v33[1], *v33);
            v97 = _mm_mul_ps(v96, *(__m128 *)&v545[16]);
            v98 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v97, v97, 85), _mm_shuffle_ps(v97, v97, 0)),
                    _mm_shuffle_ps(v97, v97, 170));
            v99 = _mm_mul_ps(v95, v96);
            v100 = _mm_mul_ps(v95, *(__m128 *)&v545[16]);
            v101 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v99, v99, 85), _mm_shuffle_ps(v99, v99, 0)),
                     _mm_shuffle_ps(v99, v99, 170));
            v102 = _mm_mul_ps(v96, v96);
            v103 = _mm_mul_ps(*(__m128 *)&v545[16], *(__m128 *)&v545[16]);
            v606 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v102, v102, 85), _mm_shuffle_ps(v102, v102, 0)),
                     _mm_shuffle_ps(v102, v102, 170));
            v104 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v100, v100, 85), _mm_shuffle_ps(v100, v100, 0)),
                     _mm_shuffle_ps(v100, v100, 170));
            v608 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v103, v103, 85), _mm_shuffle_ps(v103, v103, 0)),
                     _mm_shuffle_ps(v103, v103, 170));
            v105 = _mm_max_ps(_mm_sub_ps(_mm_mul_ps(v608, v606), _mm_mul_ps(v98, v98)), *(__m128 *)&epsilon);
            v106 = _mm_rcp_ps(v105);
            v610 = v105;
            v107 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v106, v105)), v106);
            v108 = _mm_rcp_ps(v608);
            v612 = v107;
            v109 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v108, v608)), v108);
            v110 = _mm_rcp_ps(v606);
            v699 = v109;
            v693 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v110, v606)), v110);
            v111 = _mm_cmple_ps(v105, *(__m128 *)&epsilon);
            v112 = _mm_sub_ps(_mm_mul_ps(v608, v101), _mm_mul_ps(v104, v98));
            v113 = _mm_cmplt_ps(v112, v105);
            v114 = _mm_sub_ps(
                     _mm_mul_ps(
                       _mm_or_ps(
                         _mm_andnot_ps(
                           v111,
                           _mm_mul_ps(
                             _mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_and_ps(v112, v113), _mm_andnot_ps(v113, v105))),
                             v107)),
                         _mm_and_ps(v111, v32)),
                       _mm_mul_ps(v109, v98)),
                     _mm_mul_ps(v109, v104));
            v115 = _mm_cmplt_ps(v114, v32);
            v116 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v114, v115), _mm_andnot_ps(v115, v32)));
            v117 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v693, v98), v116), _mm_mul_ps(v693, v101));
            v118 = v34[2];
            v119 = _mm_cmplt_ps(v117, v32);
            v120 = _mm_sub_ps(
                     _mm_add_ps(
                       _mm_mul_ps(
                         _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v117, v119), _mm_andnot_ps(v119, v32))),
                         v96),
                       *v33),
                     _mm_add_ps(_mm_mul_ps(v116, *(__m128 *)&v545[16]), v118));
            v121 = _mm_mul_ps(v96, v554);
            v122 = _mm_mul_ps(v120, v120);
            v123 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v122, v122, 85), _mm_shuffle_ps(v122, v122, 0)),
                     _mm_shuffle_ps(v122, v122, 170));
            v124 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v121, v121, 85), _mm_shuffle_ps(v121, v121, 0)),
                     _mm_shuffle_ps(v121, v121, 170));
            v125 = _mm_sub_ps(v118, *v33);
            v126 = _mm_mul_ps(v125, v554);
            v127 = _mm_mul_ps(v125, v96);
            v128 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v127, v127, 85), _mm_shuffle_ps(v127, v127, 0)),
                     _mm_shuffle_ps(v127, v127, 170));
            v129 = _mm_mul_ps(v554, v554);
            v130 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v126, v126, 85), _mm_shuffle_ps(v126, v126, 0)),
                     _mm_shuffle_ps(v126, v126, 170));
            v601[6] = v606;
            v643 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v129, v129, 85), _mm_shuffle_ps(v129, v129, 0)),
                     _mm_shuffle_ps(v129, v129, 170));
            v131 = _mm_max_ps(_mm_sub_ps(_mm_mul_ps(v643, v606), _mm_mul_ps(v124, v124)), *(__m128 *)&epsilon);
            v132 = _mm_rcp_ps(v131);
            v603 = v131;
            v133 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v132, v131)), v132);
            v134 = _mm_rcp_ps(v643);
            v601[3] = v133;
            v135 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v134, v643)), v134);
            v136 = _mm_rcp_ps(v606);
            v605 = v135;
            v137 = _mm_cmple_ps(v131, *(__m128 *)&epsilon);
            v138 = _mm_sub_ps(_mm_mul_ps(v643, v128), _mm_mul_ps(v130, v124));
            v648 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v136, v606)), v136);
            v139 = _mm_cmplt_ps(v138, v131);
            v140 = _mm_sub_ps(
                     _mm_mul_ps(
                       _mm_or_ps(
                         _mm_andnot_ps(
                           v137,
                           _mm_mul_ps(
                             _mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_and_ps(v139, v138), _mm_andnot_ps(v139, v131))),
                             v133)),
                         _mm_and_ps(v137, *(__m128 *)v545)),
                       _mm_mul_ps(v135, v124)),
                     _mm_mul_ps(v135, v130));
            v141 = _mm_cmplt_ps(v140, *(__m128 *)v545);
            v142 = v34[2];
            v19 = *(__m128 *)&v545[40];
            v18 = 0i64;
            v143 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v141, v140), _mm_andnot_ps(v141, *(__m128 *)v545)));
            v144 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v648, v124), v143), _mm_mul_ps(v648, v128));
            v145 = _mm_cmplt_ps(v144, *(__m128 *)v545);
            v146 = _mm_sub_ps(
                     _mm_add_ps(
                       _mm_mul_ps(
                         _mm_max_ps(
                           (__m128)0i64,
                           _mm_or_ps(_mm_and_ps(v145, v144), _mm_andnot_ps(v145, *(__m128 *)v545))),
                         v96),
                       *v33),
                     _mm_add_ps(_mm_mul_ps(v143, v554), v142));
            v147 = _mm_mul_ps(v146, v146);
            v148 = _mm_cmplt_ps(
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v147, v147, 85), _mm_shuffle_ps(v147, v147, 0)),
                       _mm_shuffle_ps(v147, v147, 170)),
                     v123);
            *v34 = _mm_or_ps(_mm_andnot_ps(v148, v34[1]), _mm_and_ps(*v34, v148));
            v34[1] = v142;
LABEL_37:
            v67 = 2;
            goto LABEL_38;
          }
          *v33 = v70;
          v67 = 0;
LABEL_38:
          v30 = v546;
          v28 = v550;
          *(_QWORD *)v545 = 0x3F8000003F800000i64;
          *(__m128 *)&v545[8] = v546;
          *(__m128 *)&v545[24] = v550;
          goto LABEL_39;
        }
        v149 = *v34;
        v150 = v33[1];
        v151 = *(__m128 *)&v545[32];
        v152 = _mm_mul_ps(_mm_sub_ps(*v33, *v34), v19);
        v153 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v152, v152, 85), _mm_shuffle_ps(v152, v152, 0)),
                 _mm_shuffle_ps(v152, v152, 170));
        v154 = _mm_mul_ps(_mm_sub_ps(v150, *v34), v19);
        v155 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v154, v154, 85), _mm_shuffle_ps(v154, v154, 0)),
                 _mm_shuffle_ps(v154, v154, 170));
        if ( (float)(v155.m128_f32[0] * v153.m128_f32[0]) < v18.m128_f32[0] )
        {
          v607 = _mm_sub_ps(v153, v155);
          v156 = _mm_rcp_ps(v607);
          v688 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v607, v156)), v156), v153);
          v149 = *v34;
          v150 = v33[1];
          v157 = _mm_sub_ps(v34[2], *v34);
          v158 = _mm_sub_ps(v34[1], *v34);
          v159 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v150, *v33), v688), *v33);
          v160 = _mm_sub_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v157, v157, 201), v158),
                   _mm_mul_ps(_mm_shuffle_ps(v158, v158, 201), v157));
          v161 = _mm_shuffle_ps(v160, v160, 201);
          v162 = _mm_sub_ps(v34[1], v159);
          v163 = _mm_sub_ps(*v34, v159);
          v164 = _mm_sub_ps(v34[2], v159);
          v165 = _mm_shuffle_ps(v161, v161, 210);
          v166 = _mm_shuffle_ps(v161, v161, 201);
          v167 = _mm_mul_ps(
                   _mm_sub_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v164, v164, 201), v165),
                     _mm_mul_ps(_mm_shuffle_ps(v164, v164, 210), v166)),
                   v162);
          v168 = _mm_shuffle_ps(v162, v162, 210);
          v169 = _mm_mul_ps(
                   _mm_sub_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v163, v163, 201), v165),
                     _mm_mul_ps(_mm_shuffle_ps(v163, v163, 210), v166)),
                   v164);
          v170 = _mm_mul_ps(_mm_shuffle_ps(v162, v162, 201), v165);
          v171 = v167;
          v172 = _mm_unpackhi_ps(v167, v169);
          v173 = _mm_unpacklo_ps(v171, v169);
          v174 = _mm_mul_ps(_mm_sub_ps(v170, _mm_mul_ps(v168, v166)), v163);
          v175 = _mm_movelh_ps(v173, v174);
          if ( (_mm_movemask_ps(
                  _mm_cmplt_ps(
                    v18,
                    _mm_add_ps(
                      _mm_shuffle_ps(v172, v174, 228),
                      _mm_add_ps(v175, _mm_shuffle_ps(_mm_movehl_ps(v175, v173), v174, 212))))) & 7) == 7 )
          {
            v67 = 1;
            goto LABEL_39;
          }
        }
        v176 = v34[1];
        v177 = v34[2];
        v178 = _mm_sub_ps(v149, v177);
        v179 = _mm_sub_ps(v176, v149);
        v180 = _mm_shuffle_ps(v178, v178, 201);
        v181 = v150;
        v182 = v150;
        v183 = _mm_sub_ps(v150, *v34);
        v184 = _mm_sub_ps(v181, v176);
        v185 = _mm_sub_ps(v177, v176);
        v186 = _mm_sub_ps(v182, v177);
        v187 = _mm_shuffle_ps(v185, v185, 201);
        v188 = _mm_sub_ps(_mm_mul_ps(v185, v180), _mm_mul_ps(v178, v187));
        v189 = _mm_shuffle_ps(v188, v188, 201);
        v190 = _mm_sub_ps(_mm_mul_ps(v184, v187), _mm_mul_ps(_mm_shuffle_ps(v184, v184, 201), v185));
        v191 = _mm_sub_ps(_mm_mul_ps(v186, v180), _mm_mul_ps(_mm_shuffle_ps(v186, v186, 201), v178));
        v192 = _mm_mul_ps(_mm_shuffle_ps(v190, v190, 201), v189);
        v193 = _mm_mul_ps(_mm_shuffle_ps(v191, v191, 201), v189);
        v194 = _mm_unpacklo_ps(v192, v193);
        v195 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v179, v179, 201), v183),
                 _mm_mul_ps(_mm_shuffle_ps(v183, v183, 201), v179));
        v196 = _mm_mul_ps(_mm_shuffle_ps(v195, v195, 201), v189);
        v197 = _mm_movelh_ps(v194, v196);
        v198 = _mm_add_ps(
                 _mm_shuffle_ps(_mm_unpackhi_ps(v192, v193), v196, 228),
                 _mm_add_ps(v197, _mm_shuffle_ps(_mm_movehl_ps(v197, v194), v196, 212)));
        *(__m128 *)&v545[32] = v198;
        v199 = _mm_movemask_ps(_mm_cmplt_ps(v198, (__m128)0i64)) & 7;
        switch ( v199 )
        {
          case 7:
            v67 = 0;
            v18 = 0i64;
            *v33 = v33[1];
            goto LABEL_38;
          case 6:
            goto LABEL_36;
          case 5:
            goto LABEL_53;
          case 3:
            goto LABEL_54;
          case 1:
            v200 = _mm_shuffle_ps(v151, v151, 85).m128_f32[0];
            v201 = _mm_shuffle_ps(v151, v151, 170).m128_f32[0];
            if ( (float)((float)(_mm_shuffle_ps(v198, v198, 85).m128_f32[0] - v200) * v201) > (float)((float)(_mm_shuffle_ps(v198, v198, 170).m128_f32[0] - v201) * v200) )
              goto LABEL_54;
            goto LABEL_53;
        }
        if ( v199 != 2 )
        {
          if ( v199 != 4
            || (v257 = _mm_shuffle_ps(v151, v151, 0).m128_f32[0],
                v258 = _mm_shuffle_ps(v151, v151, 85).m128_f32[0],
                (float)((float)(_mm_shuffle_ps(v198, v198, 0).m128_f32[0] - v257) * v258) <= (float)((float)(_mm_shuffle_ps(v198, v198, 85).m128_f32[0] - v258) * v257)) )
          {
LABEL_36:
            v18 = 0i64;
            *v34 = v34[2];
            goto LABEL_37;
          }
LABEL_53:
          v34[1] = v34[2];
          v28 = v550;
          v30 = v546;
          *(__m128 *)&v545[24] = v550;
          *(_QWORD *)&v545[16] = v546.m128_u64[1];
          *(hkVector4f *)v545 = (hkVector4f)query.m_quad;
          goto LABEL_54;
        }
        v202 = _mm_shuffle_ps(v151, v151, 170).m128_f32[0];
        v203 = _mm_shuffle_ps(v151, v151, 0).m128_f32[0];
        if ( (float)((float)(_mm_shuffle_ps(v198, v198, 170).m128_f32[0] - v202) * v203) > (float)((float)(_mm_shuffle_ps(v198, v198, 0).m128_f32[0] - v203)
                                                                                                 * v202) )
          goto LABEL_36;
LABEL_54:
        v67 = 2;
        v18 = 0i64;
LABEL_39:
        if ( v67 )
        {
          v204 = v67 - 1;
          if ( !v204 )
            goto LABEL_64;
          if ( v204 != 1 )
            goto LABEL_149;
          dimA.m_storage = 2;
          dimB.m_storage = 2;
LABEL_43:
          v205 = _mm_sub_ps(v30, v28);
          v206 = _mm_sub_ps(v547, v30);
          v207 = _mm_sub_ps(v551, v28);
          *(__m128 *)&v545[16] = v547;
          v208 = _mm_shuffle_ps(v207, v207, 201);
          v209 = _mm_shuffle_ps(v206, v206, 201);
          v556 = v206;
          v210 = _mm_sub_ps(_mm_mul_ps(v206, v208), _mm_mul_ps(v207, v209));
          v19 = _mm_shuffle_ps(v210, v210, 201);
          *(__m128 *)&v545[40] = v19;
          v211 = _mm_shuffle_ps(v19, v19, 201);
          v212 = _mm_sub_ps(_mm_mul_ps(v209, v19), _mm_mul_ps(v206, v211));
          v213 = _mm_shuffle_ps(v212, v212, 201);
          v214 = _mm_sub_ps(_mm_mul_ps(v208, v19), _mm_mul_ps(v207, v211));
          v215 = _mm_mul_ps(_mm_sub_ps(v551, v30), v213);
          v216 = _mm_mul_ps(v205, v213);
          v217 = _mm_shuffle_ps(v216, v215, 238);
          v218 = _mm_shuffle_ps(v214, v214, 201);
          v219 = _mm_shuffle_ps(v216, v215, 68);
          v220 = _mm_mul_ps(_mm_sub_ps(v28, v547), v218);
          v221 = _mm_mul_ps(v205, v218);
          v222 = _mm_shuffle_ps(v221, v220, 238);
          v223 = _mm_shuffle_ps(v221, v220, 68);
          v224 = _mm_add_ps(
                   _mm_shuffle_ps(v222, v217, 136),
                   _mm_add_ps(_mm_shuffle_ps(v223, v219, 221), _mm_shuffle_ps(v223, v219, 136)));
          v225 = _mm_movemask_ps(_mm_cmplt_ps(v18, v224));
          if ( v225 == 15 )
          {
            v366 = _mm_mul_ps(v205, v19);
            v367 = _mm_shuffle_ps(v224, v224, 0);
            v368 = _mm_add_ps(_mm_shuffle_ps(v224, v224, 85), v367);
            v369 = _mm_rcp_ps(v368);
            v618 = v368;
            v698 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v369, v368)), v369), v367);
            v351 = _mm_xor_ps(
                     (__m128)_mm_slli_epi32(
                               _mm_srli_epi32(
                                 (__m128i)_mm_add_ps(
                                            _mm_add_ps(_mm_shuffle_ps(v366, v366, 85), _mm_shuffle_ps(v366, v366, 0)),
                                            _mm_shuffle_ps(v366, v366, 170)),
                                 0x1Fu),
                               0x1Fu),
                     v19);
            v553 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v547, v30), v698), v30);
            goto LABEL_148;
          }
          v226 = v225 - 7;
          if ( !v226 )
          {
            v28 = v551;
            *(__m128 *)&v545[24] = v551;
            v550 = v551;
LABEL_92:
            dimB.m_storage = 1;
LABEL_135:
            v480 = _mm_sub_ps(v30, v28);
            v481 = _mm_sub_ps(v547, v28);
            v482 = _mm_sub_ps(v547, v30);
            v483 = _mm_mul_ps(v481, v482);
            v484 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v483, v483, 85), _mm_shuffle_ps(v483, v483, 0)),
                     _mm_shuffle_ps(v483, v483, 170));
            v485 = _mm_mul_ps(v480, v482);
            v486 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v485, v485, 85), _mm_shuffle_ps(v485, v485, 0)),
                     _mm_shuffle_ps(v485, v485, 170));
            if ( (float)(v486.m128_f32[0] * v484.m128_f32[0]) >= v18.m128_f32[0] )
            {
              v493 = _mm_cmple_ps(v484, v18);
              dimA.m_storage = 1;
              v30 = _mm_or_ps(_mm_andnot_ps(v493, v30), _mm_and_ps(v547, v493));
              *(_QWORD *)&v545[16] = v30.m128_u64[1];
              v546 = v30;
              v351 = _mm_sub_ps(v30, v28);
            }
            else
            {
              dimA.m_storage = 2;
              v487 = _mm_sub_ps(_mm_mul_ps(v480, v484), _mm_mul_ps(v481, v486));
              v488 = _mm_mul_ps(v482, v482);
              v489 = _mm_shuffle_ps(v482, v482, 201);
              v490 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v487, v487, 201), v482), _mm_mul_ps(v487, v489));
              v628 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v488, v488, 85), _mm_shuffle_ps(v488, v488, 0)),
                       _mm_shuffle_ps(v488, v488, 170));
              v491 = _mm_shuffle_ps(v490, v490, 201);
              v683 = _mm_rcp_ps(v628);
              v492 = _mm_sub_ps(_mm_mul_ps(v491, v489), _mm_mul_ps(_mm_shuffle_ps(v491, v491, 201), v482));
              v351 = _mm_mul_ps(_mm_shuffle_ps(v492, v492, 201), v683);
            }
LABEL_148:
            *(__m128 *)&v545[40] = v351;
LABEL_149:
            v19 = *(__m128 *)&v545[40];
            *(hkPadSpu<int> *)&v545[48] = dimB;
            v261 = 0;
            goto LABEL_65;
          }
          v227 = v226 - 4;
          if ( !v227 )
            goto LABEL_92;
          v228 = v227 - 2;
          if ( !v228 )
          {
            v30 = v547;
            *(_QWORD *)&v545[16] = v547.m128_u64[1];
            v546 = v547;
LABEL_88:
            dimA.m_storage = 1;
LABEL_89:
            v352 = _mm_sub_ps(v28, v30);
            v353 = _mm_sub_ps(v551, v30);
            v354 = _mm_sub_ps(v551, v28);
            v355 = _mm_mul_ps(v353, v354);
            v356 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v355, v355, 85), _mm_shuffle_ps(v355, v355, 0)),
                     _mm_shuffle_ps(v355, v355, 170));
            v357 = _mm_mul_ps(v354, v352);
            v358 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v357, v357, 85), _mm_shuffle_ps(v357, v357, 0)),
                     _mm_shuffle_ps(v357, v357, 170));
            if ( (float)(v358.m128_f32[0] * v356.m128_f32[0]) >= v18.m128_f32[0] )
            {
              v502 = _mm_cmple_ps(v356, v18);
              v359 = 1;
              v28 = _mm_or_ps(_mm_and_ps(v551, v502), _mm_andnot_ps(v502, v28));
              *(__m128 *)&v545[24] = v28;
              v351 = _mm_sub_ps(v30, v28);
              v550 = v28;
            }
            else
            {
              v359 = 2;
              v360 = _mm_sub_ps(_mm_mul_ps(v356, v352), _mm_mul_ps(v358, v353));
              v361 = _mm_mul_ps(v354, v354);
              v362 = _mm_shuffle_ps(v354, v354, 201);
              v633 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v361, v361, 85), _mm_shuffle_ps(v361, v361, 0)),
                       _mm_shuffle_ps(v361, v361, 170));
              v363 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v360, v360, 201), v354), _mm_mul_ps(v362, v360));
              v668 = _mm_rcp_ps(v633);
              v364 = _mm_shuffle_ps(v363, v363, 201);
              v365 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v364, v364, 201), v354), _mm_mul_ps(v362, v364));
              v351 = _mm_mul_ps(_mm_shuffle_ps(v365, v365, 201), v668);
            }
            dimB.m_storage = v359;
            goto LABEL_148;
          }
          if ( v228 == 1 )
            goto LABEL_88;
          v229 = _mm_mul_ps(v207, v206);
          v230 = _mm_sub_ps(v28, v30);
          v231 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v229, v229, 85), _mm_shuffle_ps(v229, v229, 0)),
                   _mm_shuffle_ps(v229, v229, 170));
          v232 = _mm_mul_ps(v230, v206);
          v233 = _mm_mul_ps(v230, v207);
          v234 = _mm_mul_ps(v207, v207);
          v235 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v232, v232, 85), _mm_shuffle_ps(v232, v232, 0)),
                   _mm_shuffle_ps(v232, v232, 170));
          v236 = _mm_mul_ps(v206, v206);
          v237 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v233, v233, 85), _mm_shuffle_ps(v233, v233, 0)),
                   _mm_shuffle_ps(v233, v233, 170));
          v609 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v236, v236, 85), _mm_shuffle_ps(v236, v236, 0)),
                   _mm_shuffle_ps(v236, v236, 170));
          v653 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v234, v234, 85), _mm_shuffle_ps(v234, v234, 0)),
                   _mm_shuffle_ps(v234, v234, 170));
          v238 = _mm_max_ps(_mm_sub_ps(_mm_mul_ps(v653, v609), _mm_mul_ps(v231, v231)), *(__m128 *)&epsilon);
          v239 = _mm_rcp_ps(v238);
          v611 = v238;
          v240 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v239, v238)), v239);
          v241 = _mm_rcp_ps(v653);
          v678 = v240;
          v242 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v241, v653)), v241);
          v243 = _mm_rcp_ps(v609);
          v613 = v242;
          v244 = _mm_sub_ps(_mm_mul_ps(v653, v235), _mm_mul_ps(v237, v231));
          v658 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v243, v609)), v243);
          v245 = _mm_cmplt_ps(v244, v238);
          v246 = _mm_cmple_ps(v238, *(__m128 *)&epsilon);
          v247 = _mm_mul_ps(
                   _mm_or_ps(
                     _mm_andnot_ps(
                       v246,
                       _mm_mul_ps(
                         _mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_andnot_ps(v245, v238), _mm_and_ps(v244, v245))),
                         v240)),
                     _mm_and_ps(v246, *(__m128 *)v545)),
                   _mm_mul_ps(v242, v231));
          v248 = _mm_mul_ps(v658, v231);
          v249 = _mm_mul_ps(v658, v235);
          v32 = *(__m128 *)v545;
          v250 = _mm_sub_ps(v247, _mm_mul_ps(v242, v237));
          v18 = 0i64;
          v251 = _mm_cmplt_ps(v250, *(__m128 *)v545);
          v252 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v250, v251), _mm_andnot_ps(v251, *(__m128 *)v545)));
          v253 = _mm_add_ps(_mm_mul_ps(v248, v252), v249);
          v254 = _mm_cmplt_ps(v253, *(__m128 *)v545);
          v255 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v253, v254), _mm_andnot_ps(v254, *(__m128 *)v545)));
          v256 = _mm_movemask_ps(
                   _mm_cmpeq_ps(
                     _mm_movelh_ps(_mm_unpacklo_ps(v255, v255), _mm_unpacklo_ps(v252, v252)),
                     (__m128)xmmword_141A71330));
          v553 = _mm_add_ps(_mm_mul_ps(v255, v556), v30);
          if ( !v256 )
          {
            v350 = _mm_mul_ps(v205, v19);
            v351 = _mm_xor_ps(
                     (__m128)_mm_slli_epi32(
                               _mm_srli_epi32(
                                 (__m128i)_mm_add_ps(
                                            _mm_add_ps(_mm_shuffle_ps(v350, v350, 85), _mm_shuffle_ps(v350, v350, 0)),
                                            _mm_shuffle_ps(v350, v350, 170)),
                                 0x1Fu),
                               0x1Fu),
                     v19);
            goto LABEL_148;
          }
          if ( (v256 & 1) != 0 )
          {
            v30 = *(__m128 *)&v545[16];
            dimA.m_storage = 1;
            *(_OWORD *)&v545[8] = *(_OWORD *)&v545[16];
            v546 = *(__m128 *)&v545[8];
          }
          else
          {
            v259 = dimA.m_storage;
            if ( (v256 & 2) != 0 )
              v259 = 1;
            dimA.m_storage = v259;
          }
          if ( (v256 & 4) != 0 )
          {
            v28 = v551;
            dimB.m_storage = 1;
            *(__m128 *)&v545[24] = v551;
            v550 = v551;
          }
          else
          {
            v260 = dimB.m_storage;
            if ( (v256 & 8) != 0 )
              v260 = 1;
            dimB.m_storage = v260;
          }
          v31 = (dimB.m_storage | (8 * dimA.m_storage)) - 9;
          if ( v31 > 0x18 )
          {
LABEL_64:
            v261 = 1;
            goto LABEL_65;
          }
          continue;
        }
        v19 = *(__m128 *)&v545[40];
        if ( dimA.m_storage == 2 )
        {
          dimA.m_storage = 1;
          *(hkPadSpu<int> *)&v545[48] = dimB;
        }
        else
        {
          dimB.m_storage = 1;
          *(_DWORD *)&v545[48] = 1;
        }
        v261 = 0;
LABEL_65:
        v262 = _mm_mul_ps(v19, v19);
        v263 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v262, v262, 85), _mm_shuffle_ps(v262, v262, 0)),
                 _mm_shuffle_ps(v262, v262, 170));
        v264 = _mm_rsqrt_ps(v263);
        v638 = v263;
        v265 = _mm_andnot_ps(
                 _mm_cmple_ps(v263, v18),
                 _mm_mul_ps(
                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v264, v263), v264)),
                   _mm_mul_ps(v264, *(__m128 *)_xmm)));
        v266 = _mm_mul_ps(_mm_sub_ps(v30, v28), v19);
        v19 = _mm_mul_ps(v19, v265);
        *(__m128 *)&v545[40] = v19;
        if ( !v261
          && (float)((float)((float)(_mm_shuffle_ps(v266, v266, 85).m128_f32[0]
                                   + _mm_shuffle_ps(v266, v266, 0).m128_f32[0])
                           + _mm_shuffle_ps(v266, v266, 170).m128_f32[0])
                   * v265.m128_f32[0]) >= v574.m128_f32[0]
          && v263.m128_f32[0] >= (float)((float)(v574.m128_f32[0] * v574.m128_f32[0])
                                       * (float)(v574.m128_f32[0] * v574.m128_f32[0])) )
        {
          v267 = aTb->m_rotation.m_col2.m_quad;
          v268 = aTb->m_rotation.m_col0.m_quad;
          *(hkcdVertex *)&v545[16] = (hkcdVertex)shapeA->m_quad;
          v269 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
          v270 = _mm_xor_ps(v269, v19);
          v560 = v270;
          v271 = _mm_xor_ps(v270, v269);
          v272 = v268;
          v273 = _mm_unpackhi_ps(v268, aTb->m_rotation.m_col1.m_quad);
          v274 = _mm_unpacklo_ps(v272, aTb->m_rotation.m_col1.m_quad);
          v579 = *(_OWORD *)&v545[16];
          v275 = _mm_shuffle_ps(v273, v267, 228);
          v580 = shapeA[1].m_quad;
          v276 = _mm_movelh_ps(v274, v267);
          v277 = _mm_mul_ps(_mm_shuffle_ps(v271, v271, 85), _mm_shuffle_ps(_mm_movehl_ps(v276, v274), v267, 212));
          v581 = shapeA[2].m_quad;
          v278 = shapeA[3].m_quad;
          v563 = v581;
          v582 = v278;
          v279 = *shapeB;
          v583 = v279;
          v280 = shapeB[1];
          v281 = v270;
          v584 = v280;
          v282 = (__int128)shapeB[2];
          v554 = v580;
          v283 = _mm_add_ps(
                   _mm_add_ps(v277, _mm_mul_ps(_mm_shuffle_ps(v271, v271, 0), v276)),
                   _mm_mul_ps(_mm_shuffle_ps(v271, v271, 170), v275));
          v585 = (__m128)v282;
          v284 = shapeB[3];
          v559 = v282;
          v572 = v278;
          v573 = v279;
          v285 = _mm_mul_ps(*(__m128 *)&v545[16], v270);
          v567 = v280;
          v571 = v284;
          v586 = v284;
          v601[4] = v270;
          v562 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v285, v285, 85), _mm_shuffle_ps(v285, v285, 0)),
                   _mm_shuffle_ps(v285, v285, 170));
          v575 = v562;
          v286 = _mm_mul_ps(v580, v270);
          v556 = v283;
          v601[5] = v283;
          v557 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v286, v286, 85), _mm_shuffle_ps(v286, v286, 0)),
                   _mm_shuffle_ps(v286, v286, 170));
          v576 = v557;
          v287 = v569 - 4;
          v288 = m_storage - 4;
          v289 = shapeA + 4;
          v290 = _mm_mul_ps(v581, v270);
          v291 = shapeB + 4;
          v292 = m_storage - 4;
          v293 = _mm_shuffle_ps(v290, v290, 0);
          v294 = _mm_shuffle_ps(v290, v290, 85);
          v295 = _mm_shuffle_ps(v290, v290, 170);
          if ( v569 - 4 < m_storage - 4 )
            v292 = v569 - 4;
          v296 = _mm_add_ps(_mm_add_ps(v294, v293), v295);
          v297 = _mm_mul_ps(v278, v270);
          v558 = v296;
          v577 = v296;
          v298 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v297, v297, 85), _mm_shuffle_ps(v297, v297, 0)),
                   _mm_shuffle_ps(v297, v297, 170));
          v299 = _mm_mul_ps(v279, v283);
          *(__m128 *)v545 = v298;
          v578 = v298;
          v300 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v299, v299, 85), _mm_shuffle_ps(v299, v299, 0)),
                   _mm_shuffle_ps(v299, v299, 170));
          v301 = _mm_mul_ps(v280, v283);
          v570 = v300;
          v587 = v300;
          v302 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v301, v301, 85), _mm_shuffle_ps(v301, v301, 0)),
                   _mm_shuffle_ps(v301, v301, 170));
          v303 = _mm_mul_ps((__m128)v559, v283);
          v561 = v302;
          v588 = v302;
          v304 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v303, v303, 85), _mm_shuffle_ps(v303, v303, 0)),
                   _mm_shuffle_ps(v303, v303, 170));
          v305 = _mm_mul_ps(v284, v283);
          v564 = v304;
          v589 = v304;
          v555 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v305, v305, 85), _mm_shuffle_ps(v305, v305, 0)),
                   _mm_shuffle_ps(v305, v305, 170));
          v590 = v555;
          if ( v292 > 0 )
          {
            v306 = ((unsigned int)(v292 - 1) >> 2) + 1;
            v287 -= 4 * v306;
            v288 -= 4 * v306;
            do
            {
              v307 = _mm_mul_ps(v281, v289->m_quad);
              v619 = (__int128)v289->m_quad;
              v308 = v289[1].m_quad;
              v592 = v619;
              v620 = v308;
              v309 = v289[2].m_quad;
              v596 = v308;
              v310 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v307, v307, 85), _mm_shuffle_ps(v307, v307, 0)),
                       _mm_shuffle_ps(v307, v307, 170));
              v621 = v309;
              v311 = _mm_mul_ps(v560, v308);
              v622 = v289[3].m_quad;
              v312 = *v291;
              v598 = v309;
              v313 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v311, v311, 85), _mm_shuffle_ps(v311, v311, 0)),
                       _mm_shuffle_ps(v311, v311, 170));
              v624 = v312;
              v314 = _mm_mul_ps(v560, v309);
              v625 = v291[1];
              v315 = v291[2];
              v600 = v622;
              v593 = v312;
              v316 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v314, v314, 85), _mm_shuffle_ps(v314, v314, 0)),
                       _mm_shuffle_ps(v314, v314, 170));
              v626 = v315;
              v317 = v291[3];
              v318 = _mm_mul_ps(v560, v622);
              v594 = v625;
              v595 = v315;
              v599 = v317;
              v627 = v317;
              v319 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v318, v318, 85), _mm_shuffle_ps(v318, v318, 0)),
                       _mm_shuffle_ps(v318, v318, 170));
              v591 = v310;
              v629 = v310;
              v320 = _mm_mul_ps(v556, v312);
              v630 = v313;
              v631 = v316;
              v632 = v319;
              v597 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v320, v320, 85), _mm_shuffle_ps(v320, v320, 0)),
                       _mm_shuffle_ps(v320, v320, 170));
              v634 = v597;
              v321 = _mm_mul_ps(v556, v625);
              v640 = v557;
              v641 = v558;
              v642 = *(_OWORD *)v545;
              v646 = v564;
              v635 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v321, v321, 85), _mm_shuffle_ps(v321, v321, 0)),
                       _mm_shuffle_ps(v321, v321, 170));
              v322 = _mm_mul_ps(v556, v315);
              v647 = v555;
              v323 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v322, v322, 85), _mm_shuffle_ps(v322, v322, 0)),
                       _mm_shuffle_ps(v322, v322, 170));
              v324 = _mm_mul_ps(v556, v317);
              v639 = v562;
              v636 = v323;
              v644 = v570;
              v645 = v561;
              v637 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v324, v324, 85), _mm_shuffle_ps(v324, v324, 0)),
                       _mm_shuffle_ps(v324, v324, 170));
              v649 = _mm_cmplt_ps(v562, v310);
              v650 = _mm_cmplt_ps(v557, v313);
              v651 = _mm_cmplt_ps(v558, v316);
              v562 = _mm_or_ps(_mm_andnot_ps(v649, v562), _mm_and_ps(v649, v310));
              v575 = v562;
              v652 = _mm_cmplt_ps(*(__m128 *)v545, v319);
              v654 = _mm_cmplt_ps(v570, v597);
              v557 = _mm_or_ps(_mm_and_ps(v650, v313), _mm_andnot_ps(v650, v557));
              v576 = v557;
              v655 = _mm_cmplt_ps(v561, v635);
              v656 = _mm_cmplt_ps(v564, v323);
              v657 = _mm_cmplt_ps(v555, v637);
              v558 = _mm_or_ps(_mm_and_ps(v651, v316), _mm_andnot_ps(v651, v558));
              v577 = v558;
              *(__m128 *)v545 = _mm_or_ps(_mm_and_ps(v652, v319), _mm_andnot_ps(v652, *(__m128 *)v545));
              v578 = *(__m128 *)v545;
              *(__m128 *)&v545[16] = _mm_or_ps(
                                       _mm_andnot_ps(v649, *(__m128 *)&v545[16]),
                                       _mm_and_ps(v649, (__m128)v619));
              v579 = *(_OWORD *)&v545[16];
              v563 = _mm_or_ps(_mm_andnot_ps(v651, v563), _mm_and_ps(v651, v309));
              v581 = v563;
              v554 = _mm_or_ps(_mm_andnot_ps(v650, v554), _mm_and_ps(v650, v308));
              v580 = v554;
              v570 = _mm_or_ps(_mm_and_ps(v654, v597), _mm_andnot_ps(v654, v570));
              v587 = v570;
              v561 = _mm_or_ps(_mm_and_ps(v655, v635), _mm_andnot_ps(v655, v561));
              v588 = v561;
              v572 = _mm_or_ps(_mm_andnot_ps(v652, v572), _mm_and_ps(v652, v622));
              v582 = v572;
              v567 = _mm_or_ps(_mm_andnot_ps(v655, v567), _mm_and_ps(v655, v625));
              v584 = v567;
              v564 = _mm_or_ps(_mm_and_ps(v656, v323), _mm_andnot_ps(v656, v564));
              v589 = v564;
              v555 = _mm_or_ps(_mm_and_ps(v657, v637), _mm_andnot_ps(v657, v555));
              v590 = v555;
              v573 = _mm_or_ps(_mm_andnot_ps(v654, v573), _mm_and_ps(v654, v312));
              v583 = v573;
              v559 = (__int128)_mm_or_ps(_mm_andnot_ps(v656, (__m128)v559), _mm_and_ps(v656, v315));
              v585 = (__m128)v559;
              v281 = v560;
              v289 += 4;
              v291 += 4;
              v571 = _mm_or_ps(_mm_andnot_ps(v657, v571), _mm_and_ps(v657, v317));
              v586 = v571;
              --v306;
            }
            while ( v306 );
            v19 = *(__m128 *)&v545[40];
            v30 = *(__m128 *)&v545[8];
            v300 = v570;
          }
          if ( v287 > 0 )
          {
            v325 = v562;
            v326 = v557;
            v327 = v558;
            p_m_quad = &v289[2].m_quad;
            v329 = ((unsigned int)(v287 - 1) >> 2) + 1;
            do
            {
              v330 = p_m_quad[-2];
              v331 = _mm_mul_ps(v281, v330);
              v659 = v330;
              v332 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v331, v331, 85), _mm_shuffle_ps(v331, v331, 0)),
                       _mm_shuffle_ps(v331, v331, 170));
              v660 = p_m_quad[-1];
              v333 = _mm_mul_ps(v281, v660);
              v661 = *p_m_quad;
              v334 = p_m_quad[1];
              v669 = v325;
              v670 = v326;
              v664 = v332;
              v665 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v333, v333, 85), _mm_shuffle_ps(v333, v333, 0)),
                       _mm_shuffle_ps(v333, v333, 170));
              v335 = _mm_mul_ps(v281, v661);
              v671 = v327;
              v662 = v334;
              v675 = _mm_cmplt_ps(v326, v665);
              v666 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v335, v335, 85), _mm_shuffle_ps(v335, v335, 0)),
                       _mm_shuffle_ps(v335, v335, 170));
              v336 = _mm_mul_ps(v281, v334);
              v676 = _mm_cmplt_ps(v327, v666);
              v672 = *(_OWORD *)v545;
              v667 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v336, v336, 85), _mm_shuffle_ps(v336, v336, 0)),
                       _mm_shuffle_ps(v336, v336, 170));
              v674 = _mm_cmplt_ps(v325, v332);
              v677 = _mm_cmplt_ps(*(__m128 *)v545, v667);
              v325 = _mm_or_ps(_mm_andnot_ps(v674, v325), _mm_and_ps(v332, v674));
              v575 = v325;
              v326 = _mm_or_ps(_mm_andnot_ps(v675, v326), _mm_and_ps(v665, v675));
              v576 = v326;
              p_m_quad += 4;
              *(__m128 *)v545 = _mm_or_ps(_mm_andnot_ps(v677, *(__m128 *)v545), _mm_and_ps(v667, v677));
              v578 = *(__m128 *)v545;
              v554 = _mm_or_ps(_mm_andnot_ps(v675, v554), _mm_and_ps(v660, v675));
              v580 = v554;
              v327 = _mm_or_ps(_mm_andnot_ps(v676, v327), _mm_and_ps(v666, v676));
              *(__m128 *)&v545[16] = _mm_or_ps(_mm_andnot_ps(v674, *(__m128 *)&v545[16]), _mm_and_ps(v330, v674));
              v579 = *(_OWORD *)&v545[16];
              v281 = v560;
              v577 = v327;
              v572 = _mm_or_ps(_mm_andnot_ps(v677, v572), _mm_and_ps(v334, v677));
              v582 = v572;
              v563 = _mm_or_ps(_mm_andnot_ps(v676, v563), _mm_and_ps(v661, v676));
              v581 = v563;
              --v329;
            }
            while ( v329 );
            v558 = v327;
            v300 = v570;
            v557 = v326;
            v30 = *(__m128 *)&v545[8];
            v562 = v325;
            v19 = *(__m128 *)&v545[40];
          }
          if ( v288 <= 0 )
          {
            v348 = v567;
            v349 = v571;
          }
          else
          {
            v337 = v561;
            v338 = v564;
            v339 = v291 + 2;
            v340 = ((unsigned int)(v288 - 1) >> 2) + 1;
            do
            {
              v679 = v339[-2];
              v341 = _mm_mul_ps(v556, v679);
              v680 = v339[-1];
              v342 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v341, v341, 85), _mm_shuffle_ps(v341, v341, 0)),
                       _mm_shuffle_ps(v341, v341, 170));
              v681 = *v339;
              v343 = v339[1];
              v344 = _mm_mul_ps(v556, v680);
              v689 = v300;
              v690 = v337;
              v684 = v342;
              v691 = v338;
              v685 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v344, v344, 85), _mm_shuffle_ps(v344, v344, 0)),
                       _mm_shuffle_ps(v344, v344, 170));
              v682 = v343;
              v345 = _mm_mul_ps(v556, v681);
              v346 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v345, v345, 85), _mm_shuffle_ps(v345, v345, 0)),
                       _mm_shuffle_ps(v345, v345, 170));
              v347 = _mm_mul_ps(v556, v343);
              v686 = v346;
              v695 = _mm_cmplt_ps(v337, v685);
              v696 = _mm_cmplt_ps(v338, v346);
              v692 = v555;
              v687 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v347, v347, 85), _mm_shuffle_ps(v347, v347, 0)),
                       _mm_shuffle_ps(v347, v347, 170));
              v694 = _mm_cmplt_ps(v300, v342);
              v697 = _mm_cmplt_ps(v555, v687);
              v300 = _mm_or_ps(_mm_andnot_ps(v694, v300), _mm_and_ps(v342, v694));
              v587 = v300;
              v337 = _mm_or_ps(_mm_andnot_ps(v695, v337), _mm_and_ps(v685, v695));
              v588 = v337;
              v339 += 4;
              v555 = _mm_or_ps(_mm_andnot_ps(v697, v555), _mm_and_ps(v687, v697));
              v590 = v555;
              v573 = _mm_or_ps(_mm_and_ps(v679, v694), _mm_andnot_ps(v694, v573));
              v583 = v573;
              v348 = _mm_or_ps(_mm_and_ps(v680, v695), _mm_andnot_ps(v695, v567));
              v567 = v348;
              v584 = v348;
              v559 = (__int128)_mm_or_ps(_mm_and_ps(v681, v696), _mm_andnot_ps(v696, (__m128)v559));
              v585 = (__m128)v559;
              v349 = _mm_or_ps(_mm_and_ps(v343, v697), _mm_andnot_ps(v697, v571));
              v338 = _mm_or_ps(_mm_andnot_ps(v696, v338), _mm_and_ps(v346, v696));
              v571 = v349;
              v586 = v349;
              v589 = v338;
              --v340;
            }
            while ( v340 );
            v564 = v338;
            v30 = *(__m128 *)&v545[8];
            v561 = v337;
            v19 = *(__m128 *)&v545[40];
          }
          v503 = _mm_cmplt_ps(v558, *(__m128 *)v545);
          v504 = _mm_cmplt_ps(v562, v557);
          v505 = _mm_cmplt_ps(v564, v555);
          v506 = _mm_cmplt_ps(v300, v561);
          v507 = _mm_cmplt_ps(
                   _mm_or_ps(_mm_and_ps(v503, *(__m128 *)v545), _mm_andnot_ps(v503, v558)),
                   _mm_or_ps(_mm_andnot_ps(v504, v562), _mm_and_ps(v504, v557)));
          v508 = _mm_cmplt_ps(
                   _mm_or_ps(_mm_and_ps(v505, v555), _mm_andnot_ps(v505, v564)),
                   _mm_or_ps(_mm_and_ps(v506, v561), _mm_andnot_ps(v506, v300)));
          v509 = _mm_or_ps(
                   _mm_andnot_ps(v508, _mm_or_ps(_mm_and_ps(v349, v505), _mm_andnot_ps(v505, (__m128)v559))),
                   _mm_and_ps(_mm_or_ps(_mm_and_ps(v348, v506), _mm_andnot_ps(v506, v573)), v508));
          v510 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v509, v509, 0), aTb->m_rotation.m_col0.m_quad),
                       _mm_mul_ps(_mm_shuffle_ps(v509, v509, 85), aTb->m_rotation.m_col1.m_quad)),
                     _mm_mul_ps(_mm_shuffle_ps(v509, v509, 170), aTb->m_rotation.m_col2.m_quad)),
                   aTb->m_translation.m_quad);
          v511 = _mm_or_ps(
                   _mm_andnot_ps(v507, _mm_or_ps(_mm_and_ps(v572, v503), _mm_andnot_ps(v503, v563))),
                   _mm_and_ps(_mm_or_ps(_mm_and_ps(v554, v504), _mm_andnot_ps(v504, *(__m128 *)&v545[16])), v507));
          v512 = _mm_shuffle_ps(v510, _mm_unpackhi_ps(v510, v509), 196);
          v513 = _mm_mul_ps(_mm_sub_ps(v511, v512), v19);
          v514 = _mm_mul_ps(_mm_sub_ps(v511, v30), v560);
          v515 = _mm_mul_ps(_mm_sub_ps(v512, *(__m128 *)&v545[24]), v19);
          v516 = _mm_unpacklo_ps(v513, v514);
          v517 = _mm_movelh_ps(v516, v515);
          v518 = _mm_mul_ps(_mm_sub_ps(v511, v547), v560);
          v519 = _mm_add_ps(
                   _mm_shuffle_ps(_mm_unpackhi_ps(v513, v514), v515, 228),
                   _mm_add_ps(v517, _mm_shuffle_ps(_mm_movehl_ps(v517, v516), v515, 212)));
          v520 = _mm_mul_ps(_mm_sub_ps(v511, v548), v560);
          v521 = _mm_mul_ps(_mm_sub_ps(v512, v551), v19);
          v522 = _mm_shuffle_ps(v518, v520, 68);
          v523 = _mm_mul_ps(_mm_sub_ps(v512, v552), v19);
          v524 = _mm_shuffle_ps(v521, v523, 68);
          v525 = _mm_shuffle_ps(v521, v523, 238);
          v526 = _mm_add_ps(_mm_shuffle_ps(v522, v524, 221), _mm_shuffle_ps(v522, v524, 136));
          v29 = v574;
          v527 = _mm_cmplt_ps(_mm_add_ps(_mm_shuffle_ps(_mm_shuffle_ps(v518, v520, 238), v525, 136), v526), v574);
          switch ( _mm_movemask_ps(
                     _mm_cmplt_ps(
                       _mm_movelh_ps(
                         _mm_unpacklo_ps(aTb[1].m_rotation.m_col1.m_quad, v574),
                         _mm_unpacklo_ps(v574, v574)),
                       v519)) & 7 )
          {
            case 1:
            case 3:
            case 5:
            case 7:
              v27 = 5;
              v706->m_distance.m_real = _mm_shuffle_ps(v519, v519, 0);
              v706->m_normalInA.m_quad = v19;
              goto LABEL_173;
            case 2:
              goto LABEL_153;
            case 4:
              goto LABEL_155;
            case 6:
              if ( _mm_shuffle_ps(v519, v519, 170).m128_f32[0] > _mm_shuffle_ps(v519, v519, 85).m128_f32[0] )
              {
LABEL_155:
                if ( (_mm_movemask_ps(v527) & hkcdGskBase::dimToMaskZ[dimB.m_storage]) != 0 )
                {
LABEL_158:
                  v528 = _mm_mul_ps(_mm_sub_ps(v30, *(__m128 *)&v545[24]), v19);
                  v706->m_normalInA.m_quad = v19;
                  v529 = _mm_add_ps(
                           _mm_add_ps(_mm_shuffle_ps(v528, v528, 85), _mm_shuffle_ps(v528, v528, 0)),
                           _mm_shuffle_ps(v528, v528, 170));
                  v706->m_distance.m_real = v529;
                  if ( dimA.m_storage == 1 )
                  {
                    v706->m_pointAinA.m_quad = v546;
                  }
                  else if ( dimB.m_storage == 1 )
                  {
                    v706->m_pointAinA.m_quad = _mm_add_ps(_mm_mul_ps(v529, v19), v550);
                  }
                  else
                  {
                    v706->m_pointAinA.m_quad = v553;
                  }
                  goto LABEL_173;
                }
                v18 = 0i64;
                *(&v550 + dimB.m_storage++) = v512;
                v28 = v550;
              }
              else
              {
LABEL_153:
                if ( (_mm_movemask_ps(v527) & hkcdGskBase::dimToMaskY[dimA.m_storage]) != 0 )
                  goto LABEL_158;
                *(&v546 + dimA.m_storage++) = v511;
                v28 = v550;
                v18 = 0i64;
              }
              break;
            default:
              goto LABEL_158;
          }
          goto LABEL_9;
        }
        if ( aTb[1].m_rotation.m_col0.m_quad.m128_i32[0] )
        {
          Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
          v531 = Value[1];
          if ( v531 < Value[3] )
          {
            *(_QWORD *)v531 = "TtPenetration";
            v532 = __rdtsc();
            *(_DWORD *)(v531 + 8) = v532;
            Value[1] = v531 + 16;
          }
          v533 = hkcdGskBase::handlePenetration(
                   (hkcdGskBase *)&v545[32],
                   &shapeInterface,
                   &shapeA,
                   &shapeB,
                   aTb,
                   &dimA,
                   &dimB,
                   v706,
                   &supportOut);
          v534 = (_QWORD *)Value[1];
          v27 = v533;
          if ( (unsigned __int64)v534 < Value[3] )
          {
            *v534 = "Et";
            v535 = __rdtsc();
            v536 = v534 + 2;
            *((_DWORD *)v536 - 2) = v535;
            Value[1] = v536;
          }
        }
        else
        {
          if ( dimB.m_storage + dimA.m_storage > 4 )
          {
            if ( dimA.m_storage <= dimB.m_storage )
            {
              dimA.m_storage = 1;
              dimB.m_storage = 3;
            }
            else
            {
              dimA.m_storage = 3;
              dimB.m_storage = 1;
            }
          }
          v27 = 6;
        }
LABEL_173:
        v537 = dimA.m_storage;
        v538 = dimB.m_storage;
        v539 = v551.m128_i8[12];
        v540 = v546.m128_i8[12];
        v541 = v547.m128_i8[12];
        v542 = v548.m128_i8[12];
        v543 = v550.m128_i8[12];
        v705[(LOBYTE(dimA.m_storage) - 2) & 3] = v552.m128_i8[12];
        *v705 = v540;
        v705[1] = v541;
        v705[2] = v542;
        v705[v537] = v543;
        v705[v537 + 1] = v539;
        result = v27;
        v705[4] = v538 | (4 * (v27 | (16 * v537)));
        return result;
      case 0x18u:
        v32 = g_vectorfConstants[0];
        v370 = v28;
        v371 = &v546;
LABEL_96:
        v372 = v371[1];
        v373 = v371[2];
        v374 = _mm_sub_ps(v372, *v371);
        v375 = _mm_sub_ps(*v371, v373);
        v376 = _mm_sub_ps(v371[3], *v371);
        v377 = _mm_sub_ps(v373, v372);
        v378 = _mm_sub_ps(v371[3], v372);
        v379 = _mm_sub_ps(v371[3], v373);
        v380 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v378, v378, 201), v377),
                 _mm_mul_ps(_mm_shuffle_ps(v377, v377, 201), v378));
        v381 = _mm_shuffle_ps(v380, v380, 201);
        v382 = _mm_mul_ps(_mm_sub_ps(v370, v371[3]), v32);
        v383 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v379, v379, 201), v375),
                 _mm_mul_ps(_mm_shuffle_ps(v375, v375, 201), v379));
        v384 = _mm_shuffle_ps(v383, v383, 201);
        v385 = _mm_mul_ps(v382, v384);
        v386 = _mm_mul_ps(v384, v384);
        v387 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v376, v376, 201), v374),
                 _mm_mul_ps(_mm_shuffle_ps(v374, v374, 201), v376));
        v388 = _mm_mul_ps(v382, v381);
        v389 = _mm_mul_ps(v381, v381);
        v390 = _mm_shuffle_ps(v387, v387, 201);
        v391 = _mm_unpacklo_ps(v388, v385);
        v392 = _mm_unpackhi_ps(v388, v385);
        v393 = _mm_mul_ps(v382, v390);
        v394 = _mm_movelh_ps(v391, v393);
        v395 = _mm_shuffle_ps(_mm_movehl_ps(v394, v391), v393, 212);
        v396 = _mm_unpacklo_ps(v389, v386);
        v397 = _mm_mul_ps(v390, v390);
        v398 = (__m128i)_mm_add_ps(_mm_shuffle_ps(v392, v393, 228), _mm_add_ps(v394, v395));
        v399 = _mm_movelh_ps(v396, v397);
        v400 = _mm_add_ps(
                 _mm_shuffle_ps(_mm_unpackhi_ps(v389, v386), v397, 228),
                 _mm_add_ps(v399, _mm_shuffle_ps(_mm_movehl_ps(v399, v396), v397, 212)));
        v401 = _mm_rcp_ps(v400);
        v623 = v400;
        v663 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v400, v401)), v401);
        v402 = _mm_cmpeq_ps(v18, v400);
        v403 = _mm_or_ps(
                 _mm_andnot_ps(
                   v402,
                   _mm_mul_ps(_mm_mul_ps((__m128)_mm_srli_epi32(_mm_slli_epi32(v398, 1u), 1u), (__m128)v398), v663)),
                 _mm_and_ps(v402, (__m128)xmmword_141A712A0));
        v404 = _mm_max_ps(
                 _mm_shuffle_ps(v403, v403, 170),
                 _mm_max_ps(_mm_shuffle_ps(v403, v403, 85), _mm_shuffle_ps(v403, v403, 0)));
        v405 = (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                                      _mm_and_ps(
                                                                        _mm_cmple_ps(v404, v403),
                                                                        (__m128)xmmword_141C1F4F0))];
        if ( v404.m128_f32[0] < _mm_shuffle_ps((__m128)0x358637BEu, (__m128)0x358637BEu, 0).m128_f32[0] )
          goto LABEL_64;
        LODWORD(retaddr) = 1066192077;
        v406 = _mm_or_ps(
                 _mm_and_ps((__m128)`hkVector4f::getComponent::`2::indexToMask[v405], (__m128)xmmword_141A712F0),
                 _mm_andnot_ps((__m128)`hkVector4f::getComponent::`2::indexToMask[v405], v403));
        if ( v404.m128_f32[0] <= (float)(fmax(
                                           _mm_shuffle_ps(v406, v406, 170).m128_f32[0],
                                           fmax(
                                             _mm_shuffle_ps(v406, v406, 85).m128_f32[0],
                                             _mm_shuffle_ps(v406, v406, 0).m128_f32[0]))
                                       * _mm_shuffle_ps((__m128)0x3F8CCCCDu, (__m128)0x3F8CCCCDu, 0).m128_f32[0]) )
        {
          v407 = 2;
          v408 = 1;
          v409 = 4;
          v410 = 16i64;
          v411 = 32i64;
          v412 = 0i64;
          v413 = 3i64;
          v414 = _mm_movemask_ps(_mm_cmple_ps(v18, (__m128)v398));
          do
          {
            if ( (v408 & v414) != 0 && (v407 & v414) != 0 )
            {
              v415 = *(__m128 *)((char *)v371 + v411);
              v416 = _mm_sub_ps(v371[v412], v415);
              v417 = _mm_sub_ps(v371[3], v415);
              v418 = _mm_sub_ps(v370, v415);
              v419 = _mm_mul_ps(v417, v416);
              v420 = _mm_sub_ps(*(__m128 *)((char *)v371 + v410), v415);
              v421 = _mm_mul_ps(v418, v416);
              v422 = _mm_mul_ps(v417, v420);
              v423 = _mm_mul_ps(v418, v420);
              if ( (float)((float)((float)(_mm_shuffle_ps(v421, v421, 85).m128_f32[0]
                                         + _mm_shuffle_ps(v421, v421, 0).m128_f32[0])
                                 + _mm_shuffle_ps(v421, v421, 170).m128_f32[0])
                         * (float)((float)(_mm_shuffle_ps(v422, v422, 85).m128_f32[0]
                                         + _mm_shuffle_ps(v422, v422, 0).m128_f32[0])
                                 + _mm_shuffle_ps(v422, v422, 170).m128_f32[0])) >= (float)((float)((float)(_mm_shuffle_ps(v419, v419, 85).m128_f32[0] + _mm_shuffle_ps(v419, v419, 0).m128_f32[0])
                                                                                                  + _mm_shuffle_ps(v419, v419, 170).m128_f32[0])
                                                                                          * (float)((float)(_mm_shuffle_ps(v423, v423, 85).m128_f32[0] + _mm_shuffle_ps(v423, v423, 0).m128_f32[0])
                                                                                                  + _mm_shuffle_ps(v423, v423, 170).m128_f32[0])) )
                v407 = v408;
              v414 &= ~v407;
            }
            v407 = v409;
            v410 = v411;
            v409 = v408;
            v408 = __ROL4__(v408, 1);
            v411 = v412 * 16;
            ++v412;
            --v413;
          }
          while ( v413 );
          if ( (v414 & 7) != 0 )
            v405 = (unsigned __int8)hkVector4Comparison_maskToFirstIndex[v414];
          else
            v405 = -1;
        }
        if ( v405 < 0 )
          goto LABEL_64;
        v371[v405] = v371[3];
        v28 = v550;
        v30 = v546;
        *(__m128 *)&v545[24] = v550;
        *(_QWORD *)&v545[16] = v546.m128_u64[1];
        if ( dimA.m_storage == 4 )
        {
          dimA.m_storage = 3;
LABEL_111:
          v424 = _mm_sub_ps(v30, v548);
          v425 = _mm_shuffle_ps(v424, v424, 201);
          v426 = _mm_sub_ps(v28, v547);
          v427 = _mm_sub_ps(v548, v547);
          v428 = _mm_sub_ps(v28, v548);
          v429 = _mm_shuffle_ps(v427, v427, 201);
          v430 = _mm_sub_ps(v547, v30);
          v431 = _mm_sub_ps(v28, v30);
          v432 = _mm_sub_ps(_mm_mul_ps(v425, v427), _mm_mul_ps(v429, v424));
          v433 = _mm_shuffle_ps(v432, v432, 201);
          *(__m128 *)&v545[40] = v433;
          v434 = _mm_sub_ps(_mm_mul_ps(v429, v426), _mm_mul_ps(_mm_shuffle_ps(v426, v426, 201), v427));
          v435 = _mm_sub_ps(_mm_mul_ps(v425, v428), _mm_mul_ps(_mm_shuffle_ps(v428, v428, 201), v424));
          v436 = _mm_mul_ps(_mm_shuffle_ps(v434, v434, 201), v433);
          v437 = _mm_mul_ps(_mm_shuffle_ps(v435, v435, 201), v433);
          v438 = _mm_sub_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v430, v430, 201), v431),
                   _mm_mul_ps(_mm_shuffle_ps(v431, v431, 201), v430));
          v439 = _mm_unpacklo_ps(v436, v437);
          v440 = _mm_mul_ps(_mm_shuffle_ps(v438, v438, 201), v433);
          v441 = _mm_movelh_ps(v439, v440);
          v442 = _mm_add_ps(
                   _mm_shuffle_ps(_mm_unpackhi_ps(v436, v437), v440, 228),
                   _mm_add_ps(v441, _mm_shuffle_ps(_mm_movehl_ps(v441, v439), v440, 212)));
          v443 = _mm_movemask_ps(_mm_cmplt_ps(v442, v18)) & 7;
          if ( v443 == 7 )
          {
            v444 = _mm_mul_ps(_mm_sub_ps(v30, v28), v433);
            if ( _mm_movemask_ps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v444, v444, 85), _mm_shuffle_ps(v444, v444, 0)),
                     _mm_shuffle_ps(v444, v444, 170))) )
            {
              *(_QWORD *)&v545[16] = v547.m128_u64[1];
              v546 = v547;
              v445 = v30;
              v30 = v547;
              v547 = v445;
              *(__m128 *)&v545[40] = _mm_xor_ps(
                                       v433,
                                       (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0));
              v442 = _mm_shuffle_ps(v442, v442, 225);
            }
          }
          *(__m128 *)&v545[32] = v442;
          if ( v443 == 7 )
            goto LABEL_149;
          v446 = hkcdGskBase::maskToIndex[v443];
          if ( (int)v446 < 0 )
          {
            v447 = v446 + 8;
            if ( v447 < 3 )
            {
              *(&v546 + v447) = v548;
              goto LABEL_134;
            }
LABEL_144:
            dimA.m_storage = 1;
            dimB.m_storage = 1;
LABEL_145:
            v351 = _mm_sub_ps(v30, v28);
            goto LABEL_148;
          }
          v472 = hkcdGskBase::vertexToEdgeLut[v446];
          v473 = v446;
          v474 = hkcdGskBase::vertexToEdgeLut[v446 + 2];
          v475 = *(&v546 + v473);
          v476 = _mm_sub_ps(v28, v475);
          v477 = _mm_sub_ps(*(&v546 + v474), v475);
          v478 = _mm_mul_ps(_mm_sub_ps(*(&v546 + v472), v475), v476);
          if ( !_mm_movemask_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v478, v478, 85), _mm_shuffle_ps(v478, v478, 0)),
                    _mm_shuffle_ps(v478, v478, 170))) )
          {
            *(&v546 + v474) = v548;
            goto LABEL_134;
          }
          v479 = _mm_mul_ps(v477, v476);
          *(&v546 + v472) = v548;
          if ( !_mm_movemask_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v479, v479, 85), _mm_shuffle_ps(v479, v479, 0)),
                    _mm_shuffle_ps(v479, v479, 170))) )
          {
LABEL_134:
            v28 = v550;
            v30 = v546;
            *(__m128 *)&v545[24] = v550;
            *(_QWORD *)&v545[16] = v546.m128_u64[1];
            goto LABEL_135;
          }
          dimA.m_storage = 1;
          if ( (_DWORD)v474 == 2 )
            LODWORD(v474) = v472;
          *(&v546 + (int)v474) = v547;
LABEL_132:
          v30 = v546;
          v28 = v550;
          *(__m128 *)&v545[24] = v550;
          *(_QWORD *)&v545[16] = v546.m128_u64[1];
          v351 = _mm_sub_ps(v546, v550);
          goto LABEL_148;
        }
        dimB.m_storage = 3;
LABEL_119:
        v448 = _mm_sub_ps(v28, v552);
        v449 = _mm_sub_ps(v552, v551);
        v450 = _mm_shuffle_ps(v448, v448, 201);
        v451 = _mm_sub_ps(v30, v551);
        v452 = _mm_shuffle_ps(v449, v449, 201);
        v453 = _mm_sub_ps(v30, v552);
        v454 = _mm_sub_ps(v551, v28);
        v455 = _mm_sub_ps(v30, v28);
        v456 = _mm_sub_ps(_mm_mul_ps(v449, v450), _mm_mul_ps(v448, v452));
        v457 = _mm_shuffle_ps(v456, v456, 201);
        *(__m128 *)&v545[40] = v457;
        v458 = _mm_sub_ps(_mm_mul_ps(v451, v452), _mm_mul_ps(_mm_shuffle_ps(v451, v451, 201), v449));
        v459 = _mm_mul_ps(_mm_shuffle_ps(v458, v458, 201), v457);
        v460 = _mm_sub_ps(_mm_mul_ps(v453, v450), _mm_mul_ps(_mm_shuffle_ps(v453, v453, 201), v448));
        v461 = _mm_mul_ps(_mm_shuffle_ps(v460, v460, 201), v457);
        v462 = _mm_unpacklo_ps(v459, v461);
        v463 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v454, v454, 201), v455),
                 _mm_mul_ps(_mm_shuffle_ps(v455, v455, 201), v454));
        v464 = _mm_mul_ps(_mm_shuffle_ps(v463, v463, 201), v457);
        v465 = _mm_movelh_ps(v462, v464);
        v466 = _mm_add_ps(
                 _mm_shuffle_ps(_mm_unpackhi_ps(v459, v461), v464, 228),
                 _mm_add_ps(v465, _mm_shuffle_ps(_mm_movehl_ps(v465, v462), v464, 212)));
        v467 = _mm_movemask_ps(_mm_cmplt_ps(v466, v18)) & 7;
        if ( v467 == 7 )
        {
          v468 = _mm_mul_ps(v457, v455);
          if ( _mm_movemask_ps(
                 _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v468, v468, 85), _mm_shuffle_ps(v468, v468, 0)),
                   _mm_shuffle_ps(v468, v468, 170))) )
          {
            *(__m128 *)&v545[24] = v551;
            v550 = v551;
            v469 = v28;
            v28 = v551;
            v551 = v469;
            *(__m128 *)&v545[40] = _mm_xor_ps(
                                     v457,
                                     (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0));
            v466 = _mm_shuffle_ps(v466, v466, 225);
          }
        }
        *(__m128 *)&v545[32] = v466;
        if ( v467 == 7 )
          goto LABEL_149;
        v470 = hkcdGskBase::maskToIndex[v467];
        if ( (int)v470 >= 0 )
        {
          v494 = hkcdGskBase::vertexToEdgeLut[v470];
          v495 = v470;
          v496 = hkcdGskBase::vertexToEdgeLut[v470 + 2];
          v497 = *(&v550 + v495);
          v498 = _mm_sub_ps(v30, v497);
          v499 = _mm_sub_ps(*(&v550 + v496), v497);
          v500 = _mm_mul_ps(_mm_sub_ps(*(&v550 + v494), v497), v498);
          if ( _mm_movemask_ps(
                 _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v500, v500, 85), _mm_shuffle_ps(v500, v500, 0)),
                   _mm_shuffle_ps(v500, v500, 170))) )
          {
            v501 = _mm_mul_ps(v499, v498);
            *(&v550 + v494) = v552;
            if ( _mm_movemask_ps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v501, v501, 85), _mm_shuffle_ps(v501, v501, 0)),
                     _mm_shuffle_ps(v501, v501, 170))) )
            {
              dimB.m_storage = 1;
              if ( (_DWORD)v496 == 2 )
                LODWORD(v496) = v494;
              *(&v550 + (int)v496) = v551;
              goto LABEL_132;
            }
          }
          else
          {
            *(&v550 + v496) = v552;
          }
        }
        else
        {
          v471 = v470 + 8;
          if ( v471 >= 3 )
            goto LABEL_144;
          *(&v550 + v471) = v552;
        }
        v28 = v550;
        v30 = v546;
        *(__m128 *)&v545[24] = v550;
        *(_QWORD *)&v545[16] = v546.m128_u64[1];
        goto LABEL_89;
      default:
        goto LABEL_64;
    }
  }
}
        goto LABEL_89;
      default:
        goto LABEL_64;
    }
  }
}

// File Line: 99
// RVA: 0x1313AE0
hkBool *__fastcall hkcdGsk::linearCast(
        hkBool *result,
        hkcdVertex *vertsShape,
        int numVertsShape,
        hkcdVertex *vertsCast,
        int numVertsCast,
        hkcdGsk::LinearCastInput *input,
        hkcdGsk::Cache *cache,
        hkcdGsk::LinearCastOutput *output)
{
  hkcdVertex *shapeA; // [rsp+50h] [rbp-E8h] BYREF
  int v11; // [rsp+58h] [rbp-E0h]
  hkcdVertex *shapeB; // [rsp+60h] [rbp-D8h] BYREF
  int v13; // [rsp+68h] [rbp-D0h]
  hkcdGskImpl<hkcdGsk_Vector4ShapeInterface> v14; // [rsp+70h] [rbp-C8h] BYREF
  hkcdGsk_Vector4ShapeInterface v15; // [rsp+140h] [rbp+8h] BYREF

  shapeA = vertsShape;
  v15.vfptr = (hkcdGskBase::ShapeInterfaceVtbl *)&hkcdGsk_Vector4ShapeInterface::`vftable;
  v13 = numVertsCast;
  v11 = numVertsShape;
  shapeB = vertsCast;
  hkcdGskImpl<hkcdGsk_Vector4ShapeInterface>::linearCast<hkcdGsk::Cache>(
    &v14,
    result,
    &v15,
    &shapeA,
    &shapeB,
    input,
    cache,
    &output->m_fractionInOut,
    &output->m_normalOut);
  return result;
}

// File Line: 110
// RVA: 0x1313B80
hkBool *__fastcall hkcdGsk::rayCast(
        hkBool *result,
        hkcdVertex *verts,
        int numVerts,
        hkcdGsk_Vector4Shape *input,
        hkSimdFloat32 *output)
{
  hkVector4f *normalOut; // [rsp+20h] [rbp-18h] BYREF
  int v8; // [rsp+28h] [rbp-10h]

  v8 = numVerts;
  result->m_bool = hkcdGskBase::castRay<hkcdGsk_Vector4Shape>(
                     (hkcdGskBase *)&normalOut,
                     input,
                     (hkcdGsk::RayCastInput *)&output[1],
                     output,
                     verts) != 0;
  return result;
}

// File Line: 119
// RVA: 0x1313BD0
hkBool *__fastcall hkcdGsk::rayCast(
        hkBool *result,
        hkFourTransposedPointsf *fours,
        int numUnTransposed,
        hkcdGsk_Vector4Shape *input,
        hkSimdFloat32 *output)
{
  unsigned int v9; // esi
  hkLifoAllocator *Value; // rax
  hkcdVertex *m_cur; // rbx
  int v12; // edx
  char *v13; // rcx
  unsigned int v14; // eax
  unsigned int m_slotID; // ecx
  signed int v16; // esi
  hkLifoAllocator *v17; // rax
  int v18; // r8d
  hkVector4f *normalOut; // [rsp+20h] [rbp-28h] BYREF
  int v21; // [rsp+28h] [rbp-20h]

  v9 = (numUnTransposed + 3) & 0xFFFFFFFC;
  if ( v9 )
  {
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (hkcdVertex *)Value->m_cur;
    v12 = (16 * v9 + 127) & 0xFFFFFF80;
    v13 = (char *)m_cur + v12;
    if ( v12 > Value->m_slabSize || v13 > Value->m_end )
      m_cur = (hkcdVertex *)hkLifoAllocator::allocateFromNewSlab(Value, v12);
    else
      Value->m_cur = v13;
  }
  else
  {
    m_cur = 0i64;
  }
  hkFourTransposedPointsf::getOriginalVertices(fours, numUnTransposed, m_cur);
  v21 = numUnTransposed;
  v14 = hkcdGskBase::castRay<hkcdGsk_Vector4Shape>(
          (hkcdGskBase *)&normalOut,
          input,
          (hkcdGsk::RayCastInput *)&output[1],
          output,
          m_cur);
  m_slotID = hkMemoryRouter::s_memoryRouter.m_slotID;
  result->m_bool = v14 != 0;
  v16 = (16 * v9 + 127) & 0xFFFFFF80;
  v17 = (hkLifoAllocator *)TlsGetValue(m_slotID);
  v18 = (v16 + 15) & 0xFFFFFFF0;
  if ( v16 > v17->m_slabSize || (char *)m_cur + v18 != v17->m_cur || v17->m_firstNonLifoEnd == m_cur )
    hkLifoAllocator::slowBlockFree(v17, (char *)m_cur, v18);
  else
    v17->m_cur = m_cur;
  return result;
}

