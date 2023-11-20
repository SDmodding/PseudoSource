// File Line: 25
// RVA: 0x1317EC0
void __fastcall hkcdGsk_Vector4Shape::getSupportingVertex(hkcdGsk_Vector4Shape *this, hkVector4f *direction, hkcdVertex *vertexOut)
{
  __m128 v3; // xmm4
  hkcdVertex *v4; // r10
  signed __int64 v5; // rdx
  signed int v6; // eax
  signed int v7; // er9
  __m128 v8; // xmm1
  float v9; // xmm3_4
  __m128 *v10; // rcx
  signed __int64 v11; // rdx
  __m128 v12; // xmm1
  float v13; // xmm2_4

  v3 = direction->m_quad;
  v4 = this->m_vertices;
  v5 = this->m_numVertices;
  v6 = 1;
  v7 = 0;
  v8 = _mm_mul_ps(v3, this->m_vertices->m_quad);
  v9 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v8, v8, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v8, v8, 0)))
     + COERCE_FLOAT(_mm_shuffle_ps(v8, v8, 170));
  if ( v5 > 1 )
  {
    v10 = &v4[1].m_quad;
    v11 = v5 - 1;
    do
    {
      v12 = _mm_mul_ps(v3, *v10);
      v13 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 0)))
          + COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 170));
      if ( v13 > v9 )
      {
        v7 = v6;
        v9 = v13;
      }
      ++v6;
      ++v10;
      --v11;
    }
    while ( v11 );
  }
  *vertexOut = v4[v7];
}

// File Line: 47
// RVA: 0x1317F80
void __fastcall hkcdGsk_Vector4ShapeInterface::getSupportingVertices(hkcdGsk_Vector4ShapeInterface *this, const void *shapeA, hkVector4f *directionA, const void *shapeB, hkTransformf *aTb, hkcdVertex *vertexAinAOut, hkcdVertex *vertexBinBOut, hkVector4f *vertexBinAout)
{
  hkVector4f v8; // xmm3
  __m128 v9; // xmm1
  __m128 v10; // xmm5
  __m128 v11; // xmm8
  __m128 v12; // xmm11
  __m128 v13; // xmm2
  __m128 v14; // xmm14
  __m128 v15; // xmm4
  __m128 v16; // xmm6
  __m128 v17; // xmm5
  __m128 v18; // xmm6
  __m128 v19; // xmm1
  __m128 v20; // xmm4
  __m128 v21; // xmm1
  __m128 v22; // xmm13
  __m128 v23; // xmm1
  int v24; // er8
  __m128 *v25; // rax
  __m128 *v26; // r10
  __m128 v27; // xmm8
  __m128 v28; // xmm1
  __m128 v29; // xmm15
  __m128 v30; // xmm1
  __m128 v31; // xmm2
  __m128 v32; // xmm1
  __m128 v33; // xmm14
  __m128 v34; // xmm1
  int v35; // er11
  int v36; // ecx
  __m128 v37; // xmm2
  __m128 v38; // xmm1
  unsigned int v39; // ecx
  __int64 v40; // rdx
  __m128 v41; // xmm1
  __m128 v42; // xmm3
  __m128 v43; // xmm1
  __m128 v44; // xmm2
  __m128 v45; // ST120_16
  __m128 v46; // xmm14
  __m128 v47; // xmm1
  __m128 v48; // xmm3
  __m128 v49; // xmm12
  __m128 v50; // xmm1
  __m128 v51; // xmm4
  __m128 v52; // xmm9
  __m128 v53; // xmm1
  __m128 v54; // xmm7
  __m128 v55; // xmm1
  __m128 v56; // ST130_16
  __m128 v57; // xmm15
  __m128 v58; // xmm1
  __m128 v59; // xmm13
  __m128 v60; // xmm1
  __m128 v61; // xmm10
  __m128 v62; // xmm5
  __m128 v63; // xmm6
  __m128 v64; // xmm11
  __m128 v65; // xmm8
  __m128 v66; // xmm7
  __m128 v67; // xmm2
  __m128 v68; // xmm1
  __m128 v69; // xmm10
  __m128 v70; // xmm12
  __int64 v71; // rdx
  __m128 v72; // xmm1
  __m128 v73; // xmm8
  __m128 v74; // xmm1
  __m128 v75; // xmm7
  __m128 v76; // xmm1
  __m128 v77; // xmm2
  __m128 v78; // xmm6
  __m128 v79; // xmm1
  __m128 v80; // xmm3
  __m128 v81; // xmm1
  __m128 v82; // xmm4
  __m128 v83; // xmm5
  __m128 v84; // xmm0
  __m128 v85; // xmm11
  __m128 v86; // xmm12
  __m128 v87; // xmm15
  __m128 v88; // xmm13
  __int64 v89; // rcx
  __m128 v90; // xmm1
  __m128 v91; // xmm8
  __m128 v92; // xmm1
  __m128 v93; // xmm7
  __m128 v94; // xmm1
  __m128 v95; // xmm5
  __m128 v96; // xmm1
  __m128 v97; // xmm4
  __m128 v98; // xmm2
  __m128 v99; // xmm3
  __m128 v100; // xmm1
  __m128 v101; // xmm6
  __m128 v102; // xmm9
  __m128 v103; // xmm11
  __m128 v104; // xmm12
  __m128 v105; // xmm10
  __m128 v106; // xmm1
  __m128 v107; // xmm7
  __m128 v108; // xmm3
  __m128 v109; // xmm5
  __m128 v110; // xmm6
  __m128 v111; // xmm2
  hkcdVertex v112; // xmm4
  __m128 v113; // [rsp+0h] [rbp-1E8h]
  __m128 v114; // [rsp+10h] [rbp-1D8h]
  __m128 v115; // [rsp+20h] [rbp-1C8h]
  __m128 v116; // [rsp+30h] [rbp-1B8h]
  __m128 v117; // [rsp+40h] [rbp-1A8h]
  __m128 v118; // [rsp+50h] [rbp-198h]
  __m128 v119; // [rsp+60h] [rbp-188h]
  __m128 v120; // [rsp+70h] [rbp-178h]
  __m128 v121; // [rsp+80h] [rbp-168h]
  __m128 v122; // [rsp+90h] [rbp-158h]
  __m128 v123; // [rsp+A0h] [rbp-148h]
  __m128 v124; // [rsp+B0h] [rbp-138h]
  __m128 v125; // [rsp+C0h] [rbp-128h]
  __m128 v126; // [rsp+D0h] [rbp-118h]
  __m128 v127; // [rsp+E0h] [rbp-108h]
  __m128 v128; // [rsp+F0h] [rbp-F8h]
  __m128 v129; // [rsp+100h] [rbp-E8h]
  __m128 v130; // [rsp+110h] [rbp-D8h]

  v129 = directionA->m_quad;
  v8.m_quad = (__m128)aTb->m_rotation.m_col2;
  v9 = _mm_unpacklo_ps(aTb->m_rotation.m_col0.m_quad, aTb->m_rotation.m_col1.m_quad);
  v10 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), directionA->m_quad);
  v11 = *(__m128 *)(*(_QWORD *)shapeA + 16i64);
  v12 = *(__m128 *)(*(_QWORD *)shapeA + 48i64);
  v13 = _mm_movelh_ps(v9, v8.m_quad);
  v14 = *(__m128 *)(*(_QWORD *)shapeA + 32i64);
  v125 = *(__m128 *)*(_QWORD *)shapeA;
  v126 = *(__m128 *)*(_QWORD *)shapeB;
  v15 = _mm_mul_ps(
          _mm_shuffle_ps(_mm_unpackhi_ps(aTb->m_rotation.m_col0.m_quad, aTb->m_rotation.m_col1.m_quad), v8.m_quad, 228),
          _mm_shuffle_ps(v10, v10, 170));
  v16 = _mm_add_ps(
          _mm_mul_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(_mm_movehl_ps(v13, v9), v8.m_quad, 212)),
          _mm_mul_ps(_mm_shuffle_ps(v10, v10, 0), v13));
  v17 = directionA->m_quad;
  v122 = v11;
  v127 = *(__m128 *)(*(_QWORD *)shapeB + 32i64);
  v18 = _mm_add_ps(v16, v15);
  v19 = _mm_mul_ps(v125, directionA->m_quad);
  v124 = v14;
  v117 = v12;
  v123 = *(__m128 *)(*(_QWORD *)shapeB + 16i64);
  v20 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)), _mm_shuffle_ps(v19, v19, 170));
  v121 = *(__m128 *)(*(_QWORD *)shapeB + 48i64);
  v130 = v18;
  v21 = _mm_mul_ps(v11, directionA->m_quad);
  v113 = v20;
  v22 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)), _mm_shuffle_ps(v21, v21, 170));
  v23 = _mm_mul_ps(v14, directionA->m_quad);
  v116 = v22;
  v24 = *((_DWORD *)shapeA + 2) - 4;
  v25 = (__m128 *)(*(_QWORD *)shapeA + 64i64);
  v26 = (__m128 *)(*(_QWORD *)shapeB + 64i64);
  v27 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v23, v23, 0), _mm_shuffle_ps(v23, v23, 85)), _mm_shuffle_ps(v23, v23, 170));
  v28 = _mm_mul_ps(v12, v17);
  v114 = v27;
  v29 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v28, v28, 85), _mm_shuffle_ps(v28, v28, 0)), _mm_shuffle_ps(v28, v28, 170));
  v30 = _mm_mul_ps(v126, v18);
  v119 = v29;
  v31 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v30, v30, 85), _mm_shuffle_ps(v30, v30, 0)), _mm_shuffle_ps(v30, v30, 170));
  v32 = _mm_mul_ps(v123, v18);
  v118 = v31;
  v33 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v32, v32, 85), _mm_shuffle_ps(v32, v32, 0)), _mm_shuffle_ps(v32, v32, 170));
  v34 = _mm_mul_ps(v127, v18);
  v128 = v33;
  v35 = *((_DWORD *)shapeB + 2) - 4;
  v36 = *((_DWORD *)shapeB + 2) - 4;
  if ( v24 < v35 )
    v36 = *((_DWORD *)shapeA + 2) - 4;
  v37 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v34, v34, 85), _mm_shuffle_ps(v34, v34, 0)), _mm_shuffle_ps(v34, v34, 170));
  v38 = _mm_mul_ps(*(__m128 *)(*(_QWORD *)shapeB + 48i64), v18);
  v120 = v37;
  v115 = _mm_add_ps(
           _mm_add_ps(_mm_shuffle_ps(v38, v38, 85), _mm_shuffle_ps(v38, v38, 0)),
           _mm_shuffle_ps(v38, v38, 170));
  if ( v36 > 0 )
  {
    v39 = ((unsigned int)(v36 - 1) >> 2) + 1;
    v40 = v39;
    v39 *= 4;
    v24 -= v39;
    v35 -= v39;
    do
    {
      v41 = _mm_mul_ps(v17, *v25);
      v42 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v41, v41, 85), _mm_shuffle_ps(v41, v41, 0)),
              _mm_shuffle_ps(v41, v41, 170));
      v43 = _mm_mul_ps(v17, v25[1]);
      v44 = _mm_cmpltps(v20, v42);
      v45 = v42;
      v46 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v43, v43, 85), _mm_shuffle_ps(v43, v43, 0)),
              _mm_shuffle_ps(v43, v43, 170));
      v47 = _mm_mul_ps(v17, v25[2]);
      v48 = _mm_cmpltps(v116, v46);
      v49 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v47, v47, 85), _mm_shuffle_ps(v47, v47, 0)),
              _mm_shuffle_ps(v47, v47, 170));
      v50 = _mm_mul_ps(v17, v25[3]);
      v51 = _mm_cmpltps(v27, v49);
      v52 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v50, v50, 85), _mm_shuffle_ps(v50, v50, 0)),
              _mm_shuffle_ps(v50, v50, 170));
      v53 = _mm_mul_ps(v18, *v26);
      v54 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v53, v53, 85), _mm_shuffle_ps(v53, v53, 0)),
              _mm_shuffle_ps(v53, v53, 170));
      v55 = _mm_mul_ps(v18, v26[1]);
      v56 = v54;
      v57 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v55, v55, 85), _mm_shuffle_ps(v55, v55, 0)),
              _mm_shuffle_ps(v55, v55, 170));
      v58 = _mm_mul_ps(v18, v26[2]);
      v59 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v58, v58, 85), _mm_shuffle_ps(v58, v58, 0)),
              _mm_shuffle_ps(v58, v58, 170));
      v60 = _mm_mul_ps(v18, v26[3]);
      v61 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v60, v60, 85), _mm_shuffle_ps(v60, v60, 0)),
              _mm_shuffle_ps(v60, v60, 170));
      v62 = _mm_cmpltps(v119, v52);
      v63 = _mm_cmpltps(v118, v54);
      v64 = _mm_cmpltps(v115, v61);
      v65 = _mm_cmpltps(v120, v59);
      v66 = _mm_cmpltps(v128, v57);
      v113 = _mm_or_ps(_mm_and_ps(v44, v45), _mm_andnot_ps(v44, v113));
      v116 = _mm_or_ps(_mm_and_ps(v48, v46), _mm_andnot_ps(v48, v116));
      v114 = _mm_or_ps(_mm_and_ps(v51, v49), _mm_andnot_ps(v51, v114));
      v119 = _mm_or_ps(_mm_and_ps(v62, v52), _mm_andnot_ps(v62, v119));
      v125 = _mm_or_ps(_mm_and_ps(v44, *v25), _mm_andnot_ps(v44, v125));
      v118 = _mm_or_ps(_mm_and_ps(v63, v56), _mm_andnot_ps(v63, v118));
      v122 = _mm_or_ps(_mm_and_ps(v48, v25[1]), _mm_andnot_ps(v48, v122));
      v33 = _mm_or_ps(_mm_and_ps(v66, v57), _mm_andnot_ps(v66, v128));
      v128 = v33;
      v124 = _mm_or_ps(_mm_and_ps(v51, v25[2]), _mm_andnot_ps(v51, v124));
      v67 = _mm_or_ps(_mm_and_ps(v62, v25[3]), _mm_andnot_ps(v62, v117));
      v120 = _mm_or_ps(_mm_and_ps(v65, v59), _mm_andnot_ps(v65, v120));
      v117 = v67;
      v68 = _mm_and_ps(v64, v61);
      v69 = _mm_or_ps(_mm_and_ps(v63, *v26), _mm_andnot_ps(v63, v126));
      v115 = _mm_or_ps(v68, _mm_andnot_ps(v64, v115));
      v20 = v113;
      v18 = v130;
      v17 = v129;
      v25 += 4;
      v26 += 4;
      v126 = v69;
      v70 = _mm_or_ps(_mm_and_ps(v65, v26[-2]), _mm_andnot_ps(v65, v127));
      v27 = v114;
      v123 = _mm_or_ps(_mm_and_ps(v66, v26[-3]), _mm_andnot_ps(v66, v123));
      v127 = v70;
      v121 = _mm_or_ps(_mm_and_ps(v64, v26[-1]), _mm_andnot_ps(v64, v121));
      --v40;
    }
    while ( v40 );
    v22 = v116;
    v29 = v119;
    v12 = v67;
  }
  if ( v24 > 0 )
  {
    v71 = ((unsigned int)(v24 - 1) >> 2) + 1;
    while ( 1 )
    {
      v72 = _mm_mul_ps(*v25, v17);
      v73 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v72, v72, 85), _mm_shuffle_ps(v72, v72, 0)),
              _mm_shuffle_ps(v72, v72, 170));
      v74 = _mm_mul_ps(v25[1], v17);
      v75 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v74, v74, 85), _mm_shuffle_ps(v74, v74, 0)),
              _mm_shuffle_ps(v74, v74, 170));
      v76 = _mm_mul_ps(v25[2], v17);
      v77 = _mm_cmpltps(v22, v75);
      v78 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v76, v76, 85), _mm_shuffle_ps(v76, v76, 0)),
              _mm_shuffle_ps(v76, v76, 170));
      v79 = _mm_mul_ps(v25[3], v17);
      v80 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v79, v79, 85), _mm_shuffle_ps(v79, v79, 0)),
              _mm_shuffle_ps(v79, v79, 170));
      v81 = _mm_cmpltps(v20, v73);
      v82 = _mm_cmpltps(v114, v78);
      v83 = _mm_cmpltps(v29, v80);
      v22 = _mm_or_ps(_mm_andnot_ps(v77, v22), _mm_and_ps(v75, v77));
      v113 = _mm_or_ps(_mm_andnot_ps(v81, v113), _mm_and_ps(v73, v81));
      v29 = _mm_or_ps(_mm_andnot_ps(v83, v29), _mm_and_ps(v80, v83));
      v125 = _mm_or_ps(_mm_andnot_ps(v81, v125), _mm_and_ps(*v25, v81));
      v27 = _mm_or_ps(_mm_andnot_ps(v82, v114), _mm_and_ps(v78, v82));
      v114 = v27;
      v122 = _mm_or_ps(_mm_andnot_ps(v77, v122), _mm_and_ps(v25[1], v77));
      v84 = _mm_or_ps(_mm_andnot_ps(v82, v124), _mm_and_ps(v25[2], v82));
      v85 = v83;
      v86 = _mm_and_ps(v25[3], v83);
      v17 = v129;
      v25 += 4;
      v124 = v84;
      v12 = _mm_or_ps(_mm_andnot_ps(v85, v117), v86);
      v117 = v12;
      if ( !--v71 )
        break;
      v20 = v113;
    }
    v33 = v128;
    v119 = v29;
    v116 = v22;
  }
  if ( v35 <= 0 )
  {
    v102 = v123;
    v105 = v121;
  }
  else
  {
    v87 = v118;
    v88 = v120;
    v89 = ((unsigned int)(v35 - 1) >> 2) + 1;
    do
    {
      v90 = _mm_mul_ps(*v26, v130);
      v91 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v90, v90, 85), _mm_shuffle_ps(v90, v90, 0)),
              _mm_shuffle_ps(v90, v90, 170));
      v92 = _mm_mul_ps(v26[1], v130);
      v93 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v92, v92, 85), _mm_shuffle_ps(v92, v92, 0)),
              _mm_shuffle_ps(v92, v92, 170));
      v94 = _mm_mul_ps(v26[2], v130);
      v95 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v94, v94, 85), _mm_shuffle_ps(v94, v94, 0)),
              _mm_shuffle_ps(v94, v94, 170));
      v96 = _mm_mul_ps(v26[3], v130);
      v97 = _mm_cmpltps(v88, v95);
      v98 = _mm_cmpltps(v33, v93);
      v99 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v96, v96, 85), _mm_shuffle_ps(v96, v96, 0)),
              _mm_shuffle_ps(v96, v96, 170));
      v100 = _mm_cmpltps(v87, v91);
      v101 = _mm_cmpltps(v115, v99);
      v87 = _mm_or_ps(_mm_andnot_ps(v100, v87), _mm_and_ps(v91, v100));
      v33 = _mm_or_ps(_mm_andnot_ps(v98, v33), _mm_and_ps(v93, v98));
      v88 = _mm_or_ps(_mm_and_ps(v95, v97), _mm_andnot_ps(v97, v88));
      v115 = _mm_or_ps(_mm_and_ps(v99, v101), _mm_andnot_ps(v101, v115));
      v126 = _mm_or_ps(_mm_andnot_ps(v100, v126), _mm_and_ps(*v26, v100));
      v102 = _mm_or_ps(_mm_andnot_ps(v98, v123), _mm_and_ps(v26[1], v98));
      v123 = v102;
      v103 = _mm_and_ps(v26[2], v97);
      v104 = _mm_and_ps(v26[3], v101);
      v26 += 4;
      v127 = _mm_or_ps(_mm_andnot_ps(v97, v127), v103);
      v105 = _mm_or_ps(_mm_andnot_ps(v101, v121), v104);
      v121 = v105;
      --v89;
    }
    while ( v89 );
    v27 = v114;
    v12 = v117;
    v120 = v88;
    v22 = v116;
    v118 = v87;
    v29 = v119;
  }
  v106 = _mm_cmpltps(v120, v115);
  v107 = _mm_cmpltps(v113, v22);
  v108 = _mm_cmpltps(v118, v33);
  v109 = _mm_cmpltps(v27, v29);
  v110 = _mm_cmpltps(
           _mm_or_ps(_mm_andnot_ps(v109, v27), _mm_and_ps(v29, v109)),
           _mm_or_ps(_mm_andnot_ps(v107, v113), _mm_and_ps(v22, v107)));
  v111 = _mm_cmpltps(
           _mm_or_ps(_mm_and_ps(v106, v115), _mm_andnot_ps(v106, v120)),
           _mm_or_ps(_mm_and_ps(v33, v108), _mm_andnot_ps(v108, v118)));
  v112.m_quad = _mm_or_ps(
                  _mm_andnot_ps(v111, _mm_or_ps(_mm_and_ps(v105, v106), _mm_andnot_ps(v106, v127))),
                  _mm_and_ps(_mm_or_ps(_mm_and_ps(v102, v108), _mm_andnot_ps(v108, v126)), v111));
  vertexBinAout->m_quad = _mm_add_ps(
                            _mm_add_ps(
                              _mm_add_ps(
                                _mm_mul_ps(_mm_shuffle_ps(v112.m_quad, v112.m_quad, 85), aTb->m_rotation.m_col1.m_quad),
                                _mm_mul_ps(_mm_shuffle_ps(v112.m_quad, v112.m_quad, 0), aTb->m_rotation.m_col0.m_quad)),
                              _mm_mul_ps(_mm_shuffle_ps(v112.m_quad, v112.m_quad, 170), aTb->m_rotation.m_col2.m_quad)),
                            aTb->m_translation.m_quad);
  vertexAinAOut->m_quad = _mm_or_ps(
                            _mm_andnot_ps(v110, _mm_or_ps(_mm_andnot_ps(v109, v124), _mm_and_ps(v12, v109))),
                            _mm_and_ps(_mm_or_ps(_mm_andnot_ps(v107, v125), _mm_and_ps(v122, v107)), v110));
  *vertexBinBOut = (hkcdVertex)v112.m_quad;
}

// File Line: 75
// RVA: 0x130D920
__int64 __fastcall hkcdGsk::getClosestPoint(hkcdVertex *vertsA, int numVertsA, hkcdVertex *vertsB, int numVertsB)
{
  char *v4; // r15
  hkcdVertex *v5; // r11
  hkcdVertex *v6; // r9
  char *v7; // r10
  int v8; // edx
  int v9; // eax
  unsigned int v10; // ebx
  __int64 v11; // rcx
  hkcdVertex *v12; // r8
  __m128 *v13; // r11
  int v14; // ebx
  char *v15; // r10
  __m128 *v16; // r9
  signed __int64 v17; // r8
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
  unsigned int v28; // er14
  hkVector4f v29; // xmm12
  __m128 v30; // xmm2
  __m128 v31; // xmm15
  unsigned int v32; // eax
  __m128 v33; // xmm11
  __m128 *v34; // rdx
  __m128 *v35; // rcx
  __m128 v36; // xmm5
  __m128 v37; // xmm6
  __m128 v38; // xmm7
  __m128 v39; // xmm14
  __m128 v40; // xmm1
  __m128 v41; // xmm2
  __m128 v42; // xmm2
  __m128 v43; // xmm1
  __m128 v44; // xmm4
  __m128 v45; // xmm1
  __m128 v46; // xmm2
  __m128 v47; // xmm1
  __m128 v48; // xmm3
  __m128 v49; // xmm2
  __m128 v50; // xmm1
  __m128 v51; // xmm2
  __m128 v52; // xmm0
  __m128 v53; // xmm7
  __m128 v54; // xmm3
  __m128 v55; // xmm6
  __m128 v56; // xmm5
  __m128 v57; // xmm5
  __m128 v58; // xmm1
  __m128 v59; // xmm4
  __m128 v60; // xmm0
  __m128 v61; // xmm2
  __m128 v62; // xmm7
  __m128 v63; // xmm1
  __m128 v64; // xmm4
  __m128 v65; // xmm1
  __m128 v66; // xmm7
  __m128 v67; // xmm2
  signed int v68; // ecx
  __m128 v69; // xmm1
  __m128 v70; // xmm3
  __m128 v71; // xmm14
  __m128 v72; // xmm1
  __m128 v73; // xmm6
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
  int v93; // er8
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
  __m128 v120; // xmm3
  __m128 v121; // xmm5
  __m128 v122; // xmm0
  __m128 v123; // xmm2
  __m128 v124; // xmm1
  __m128 v125; // xmm2
  __m128 v126; // xmm11
  __m128 v127; // xmm9
  __m128 v128; // xmm1
  __m128 v129; // xmm5
  __m128 v130; // xmm1
  __m128 v131; // xmm8
  __m128 v132; // xmm1
  __m128 v133; // xmm7
  __m128 v134; // xmm5
  __m128 v135; // xmm1
  __m128 v136; // xmm3
  __m128 v137; // xmm1
  __m128 v138; // xmm4
  __m128 v139; // xmm1
  __m128 v140; // xmm2
  __m128 v141; // xmm6
  __m128 v142; // xmm1
  __m128 v143; // xmm3
  __m128 v144; // xmm1
  __m128 v145; // xmm4
  __m128 v146; // xmm3
  __m128 v147; // xmm2
  __m128 v148; // xmm1
  __m128 v149; // xmm2
  __m128 v150; // xmm2
  __m128 v151; // xmm1
  __m128 v152; // xmm8
  __m128 v153; // xmm14
  hkVector4f v154; // xmm11
  __m128 v155; // xmm1
  __m128 v156; // xmm3
  __m128 v157; // xmm1
  __m128 v158; // xmm2
  __m128 v159; // xmm0
  __m128 v160; // xmm0
  __m128 v161; // xmm1
  __m128 v162; // xmm3
  __m128 v163; // xmm6
  __m128 v164; // xmm6
  __m128 v165; // xmm7
  __m128 v166; // xmm4
  __m128 v167; // xmm5
  __m128 v168; // xmm1
  __m128 v169; // xmm3
  __m128 v170; // xmm0
  __m128 v171; // xmm2
  __m128 v172; // xmm7
  __m128 v173; // xmm1
  __m128 v174; // xmm3
  __m128 v175; // xmm1
  __m128 v176; // xmm7
  __m128 v177; // xmm2
  __m128 v178; // xmm1
  __m128 v179; // xmm3
  __m128 v180; // xmm6
  __m128 v181; // xmm9
  __m128 v182; // xmm5
  __m128 v183; // xmm10
  __m128 v184; // xmm7
  __m128 v185; // xmm14
  __m128 v186; // xmm10
  __m128 v187; // xmm4
  __m128 v188; // xmm7
  __m128 v189; // xmm2
  __m128 v190; // xmm8
  __m128 v191; // xmm8
  __m128 v192; // xmm10
  __m128 v193; // xmm7
  __m128 v194; // xmm10
  __m128 v195; // xmm7
  __m128 v196; // xmm1
  __m128 v197; // xmm9
  __m128 v198; // xmm9
  __m128 v199; // xmm2
  hkVector4f v200; // xmm10
  int v201; // eax
  float v202; // xmm1_4
  float v203; // xmm11_4
  float v204; // xmm1_4
  float v205; // xmm11_4
  int v206; // ecx
  __m128 v207; // xmm14
  __m128 v208; // xmm7
  __m128 v209; // xmm5
  __m128 v210; // xmm2
  __m128 v211; // xmm4
  __m128 v212; // xmm13
  __m128 v213; // xmm4
  __m128 v214; // xmm4
  __m128 v215; // xmm2
  __m128 v216; // xmm0
  __m128 v217; // xmm9
  __m128 v218; // xmm2
  __m128 v219; // xmm1
  __m128 v220; // xmm6
  __m128 v221; // xmm3
  __m128 v222; // xmm2
  __m128 v223; // xmm6
  int v224; // ecx
  int v225; // ecx
  int v226; // ecx
  int v227; // ecx
  __m128 v228; // xmm1
  __m128 v229; // xmm2
  __m128 v230; // xmm11
  __m128 v231; // xmm1
  __m128 v232; // xmm2
  __m128 v233; // xmm5
  __m128 v234; // xmm10
  __m128 v235; // xmm1
  __m128 v236; // xmm9
  __m128 v237; // xmm6
  __m128 v238; // xmm1
  __m128 v239; // xmm3
  __m128 v240; // xmm1
  __m128 v241; // xmm5
  __m128 v242; // xmm1
  __m128 v243; // xmm7
  __m128 v244; // xmm0
  __m128 v245; // xmm2
  __m128 v246; // xmm1
  __m128 v247; // xmm2
  __m128 v248; // xmm8
  __m128 v249; // xmm1
  __m128 v250; // xmm0
  __m128 v251; // xmm3
  __m128 v252; // xmm2
  __m128 v253; // xmm0
  __m128 v254; // xmm1
  int v255; // ecx
  float v256; // xmm1_4
  float v257; // xmm11_4
  signed int v258; // eax
  signed int v259; // eax
  signed int v260; // eax
  __m128 v261; // xmm1
  __m128 v262; // xmm3
  __m128 v263; // xmm2
  __m128 v264; // xmm6
  __m128 v265; // xmm2
  __m128 v266; // xmm3
  __m128 v267; // xmm4
  __m128 v268; // xmm1
  __m128 v269; // xmm8
  __m128 v270; // xmm5
  __m128 v271; // xmm1
  __m128 v272; // xmm4
  __m128 v273; // xmm2
  __m128 v274; // xmm0
  __m128 v275; // xmm1
  __m128 v276; // xmm0
  __m128 v277; // xmm3
  __m128 v278; // xmm7
  __m128 v279; // xmm1
  __m128 v280; // xmm10
  __m128 v281; // xmm11
  __m128 v282; // xmm7
  __m128 v283; // xmm12
  __m128 v284; // xmm9
  __m128 v285; // xmm8
  __m128 v286; // xmm2
  __m128 v287; // xmm1
  __m128 v288; // xmm14
  __m128 v289; // xmm1
  int v290; // er8
  int v291; // er9
  __int64 v292; // rcx
  __m128 *v293; // rdx
  int v294; // eax
  __m128 v295; // xmm2
  __m128 v296; // xmm0
  __m128 v297; // xmm1
  __m128 v298; // xmm2
  __m128 v299; // xmm2
  __m128 v300; // xmm1
  __m128 v301; // xmm6
  __m128 v302; // xmm1
  __m128 v303; // xmm2
  __m128 v304; // xmm1
  __m128 v305; // xmm2
  __m128 v306; // xmm1
  __m128 v307; // xmm2
  __m128 v308; // xmm1
  unsigned int v309; // eax
  __int64 v310; // r10
  __m128 v311; // xmm1
  __m128 v312; // xmm2
  __m128 v313; // xmm4
  __m128 v314; // xmm3
  __m128 v315; // xmm1
  __m128 v316; // xmm2
  __m128 v317; // xmm6
  __m128 v318; // xmm14
  __m128 v319; // xmm1
  __m128 v320; // xmm9
  __m128 v321; // xmm12
  __m128 v322; // xmm11
  __m128 v323; // xmm1
  __m128 v324; // xmm10
  __m128 v325; // xmm1
  __m128 v326; // xmm7
  __m128 v327; // xmm1
  __m128 v328; // xmm8
  __m128 v329; // xmm15
  __m128i v330; // xmm4
  __m128i v331; // xmm5
  __m128 v332; // xmm1
  __m128 v333; // xmm9
  __m128 v334; // xmm13
  __m128 v335; // xmm1
  __m128i v336; // xmm2
  __m128 v337; // xmm11
  __m128i v338; // xmm3
  __m128i v339; // xmm6
  __m128i v340; // xmm7
  __m128i v341; // xmm8
  __m128 v342; // xmm0
  __m128 v343; // xmm1
  __m128i v344; // xmm9
  __m128 v345; // xmm0
  __m128 v346; // xmm13
  __m128 v347; // xmm15
  __m128 *v348; // rcx
  __int64 v349; // r8
  __m128 v350; // xmm9
  __m128 v351; // xmm1
  __m128 v352; // xmm10
  __m128 v353; // xmm8
  __m128 v354; // xmm11
  __m128 v355; // xmm1
  __m128 v356; // xmm12
  __m128 v357; // xmm7
  __m128i v358; // xmm2
  __m128 v359; // xmm1
  __m128 v360; // xmm1
  __m128i v361; // xmm3
  __m128 v362; // xmm6
  __m128 v363; // xmm4
  __m128i v364; // xmm1
  __m128i v365; // xmm5
  __m128 v366; // xmm11
  __m128 v367; // xmm0
  __m128 v368; // xmm13
  __m128 v369; // xmm15
  __m128 v370; // xmm14
  __m128 *v371; // rcx
  __int64 v372; // rdx
  __m128 v373; // xmm9
  __m128 v374; // xmm10
  __m128 v375; // xmm1
  __m128 v376; // xmm11
  __m128 v377; // xmm8
  __m128 v378; // xmm12
  __m128 v379; // xmm1
  __m128 v380; // xmm1
  __m128 v381; // xmm6
  __m128 v382; // xmm1
  __m128i v383; // xmm2
  __m128i v384; // xmm4
  __m128 v385; // xmm7
  __m128 v386; // xmm3
  __m128i v387; // xmm1
  __m128i v388; // xmm5
  __m128 v389; // xmm9
  __m128 v390; // xmm11
  __m128 v391; // xmm14
  __m128 v392; // xmm8
  __m128 v393; // xmm6
  __m128 v394; // xmm9
  __m128 v395; // xmm5
  __m128 v396; // xmm1
  __m128 v397; // xmm4
  __m128 v398; // xmm1
  __m128 v399; // xmm2
  int v400; // eax
  __m128 v401; // xmm4
  __m128 v402; // xmm1
  __m128 v403; // xmm2
  __m128 v404; // xmm1
  __m128 v405; // xmm1
  __m128 v406; // xmm8
  __m128 v407; // xmm14
  __m128 v408; // xmm2
  __m128 v409; // xmm6
  __m128 v410; // xmm1
  __m128 v411; // xmm14
  __m128 *v412; // r9
  __m128 v413; // xmm1
  __m128 v414; // xmm2
  __m128 v415; // xmm6
  __m128 v416; // xmm4
  __m128 v417; // xmm5
  __m128 v418; // xmm3
  __m128 v419; // xmm0
  __m128 v420; // xmm1
  __m128 v421; // xmm9
  __m128 v422; // xmm9
  __m128 v423; // xmm3
  __m128 v424; // xmm8
  __m128 v425; // xmm8
  __m128 v426; // xmm0
  __m128 v427; // xmm8
  __m128 v428; // xmm4
  __m128 v429; // xmm5
  __m128 v430; // xmm9
  __m128 v431; // xmm4
  __m128 v432; // xmm1
  __m128 v433; // xmm5
  __m128 v434; // xmm3
  __m128 v435; // xmm2
  __m128 v436; // xmm0
  __m128 v437; // xmm1
  __m128 v438; // xmm4
  __m128i v439; // xmm5
  __m128 v440; // xmm2
  __m128 v441; // xmm9
  __m128 v442; // xmm2
  __m128 v443; // xmm0
  __m128 v444; // xmm4
  __m128 v445; // xmm6
  signed int v446; // edx
  __m128 v447; // xmm2
  signed int v448; // eax
  signed int v449; // ecx
  signed int v450; // ebx
  signed __int64 v451; // rdi
  signed __int64 v452; // r10
  __int64 v453; // r8
  signed __int64 v454; // r11
  int v455; // edx
  __m128 v456; // xmm0
  __m128 v457; // xmm2
  __m128 v458; // xmm4
  __m128 v459; // xmm7
  __m128 v460; // xmm5
  __m128 v461; // xmm1
  __m128 v462; // xmm3
  __m128 v463; // xmm4
  __m128 v464; // xmm7
  __m128 v465; // xmm5
  __m128 v466; // xmm6
  __m128 v467; // xmm1
  __m128 v468; // xmm4
  __m128 v469; // xmm2
  __m128 v470; // xmm11
  __m128 v471; // xmm7
  __m128 v472; // xmm3
  __m128 v473; // xmm8
  __m128 v474; // xmm8
  __m128 v475; // xmm11
  __m128 v476; // xmm6
  __m128 v477; // xmm11
  __m128 v478; // xmm6
  __m128 v479; // xmm7
  __m128 v480; // xmm1
  __m128 v481; // xmm7
  __m128 v482; // xmm2
  hkVector4f v483; // xmm11
  int v484; // ecx
  __m128 v485; // xmm2
  hkcdVertex v486; // xmm0
  __int64 v487; // rcx
  signed int v488; // ecx
  __m128 v489; // xmm5
  __m128 v490; // xmm3
  __m128 v491; // xmm4
  __m128 v492; // xmm11
  __m128 v493; // xmm1
  __m128 v494; // xmm6
  __m128 v495; // xmm7
  __m128 v496; // xmm13
  __m128 v497; // xmm8
  __m128 v498; // xmm8
  __m128 v499; // xmm11
  __m128 v500; // xmm11
  __m128 v501; // xmm6
  __m128 v502; // xmm6
  __m128 v503; // xmm1
  __m128 v504; // xmm7
  __m128 v505; // xmm7
  __m128 v506; // xmm2
  hkVector4f v507; // xmm11
  int v508; // ecx
  __m128 v509; // xmm2
  hkcdVertex v510; // xmm0
  __int64 v511; // rcx
  signed int v512; // ecx
  __int64 v513; // r9
  __int64 v514; // rax
  __int64 v515; // rcx
  __m128 v516; // xmm0
  __m128 v517; // xmm12
  __m128 v518; // xmm3
  __m128 v519; // xmm2
  __m128 v520; // xmm3
  __m128 v521; // xmm4
  __m128 v522; // xmm9
  __m128 v523; // xmm5
  __m128 v524; // xmm1
  __m128 v525; // xmm2
  __m128 v526; // xmm1
  __m128 v527; // xmm6
  __m128 v528; // xmm4
  __m128 v529; // xmm1
  __m128 v530; // xmm2
  __m128 v531; // xmm8
  __m128 v532; // xmm8
  __m128 v533; // xmm8
  __m128 v534; // xmm2
  __int64 v535; // r9
  __int64 v536; // rax
  __int64 v537; // rcx
  __m128 v538; // xmm0
  __m128 v539; // xmm15
  __m128 v540; // xmm3
  __m128 v541; // xmm2
  __m128 v542; // xmm3
  __m128 v543; // xmm4
  __m128 v544; // xmm6
  __m128 v545; // xmm2
  __m128 v546; // xmm8
  __m128 v547; // xmm4
  __m128 v548; // xmm7
  __m128 v549; // xmm3
  __m128 v550; // xmm5
  __m128 v551; // xmm9
  __m128 v552; // xmm10
  __m128 v553; // xmm9
  __m128 v554; // xmm6
  __m128 v555; // xmm0
  __m128 v556; // xmm3
  __m128 v557; // xmm1
  __m128 v558; // xmm2
  __m128 v559; // xmm6
  __m128 v560; // xmm7
  __m128 v561; // xmm2
  __m128 v562; // xmm4
  __m128 v563; // xmm3
  __m128 v564; // xmm6
  __m128 v565; // xmm2
  __m128 v566; // xmm0
  __m128 v567; // xmm1
  __m128 v568; // xmm3
  __m128 v569; // xmm0
  __m128 v570; // xmm7
  hkcdGsk::GetClosestPointOutput *v571; // rax
  hkcdGsk::GetClosestPointOutput *v572; // rax
  __m128 v573; // xmm15
  __m128 v574; // xmm1
  _QWORD *v575; // rbx
  unsigned __int64 v576; // rcx
  unsigned __int64 v577; // rax
  unsigned int v578; // eax
  _QWORD *v579; // rcx
  unsigned __int64 v580; // rax
  signed __int64 v581; // rcx
  __int64 v582; // rdi
  char v583; // bl
  char v584; // r11
  char v585; // dl
  char v586; // r8
  char v587; // r9
  char v588; // r10
  __int64 result; // rax
  __m128 supportOut; // [rsp+40h] [rbp-80h]
  __m128 supportOuta; // [rsp+40h] [rbp-80h]
  __m128 v592; // [rsp+50h] [rbp-70h]
  __m128 v593; // [rsp+50h] [rbp-70h]
  hkcdGskBase v594; // [rsp+60h] [rbp-60h]
  __m128 v595; // [rsp+120h] [rbp+60h]
  __m128 v596; // [rsp+130h] [rbp+70h]
  __m128 v597; // [rsp+140h] [rbp+80h]
  __m128 v598; // [rsp+150h] [rbp+90h]
  __m128 v599; // [rsp+160h] [rbp+A0h]
  __m128 v600; // [rsp+170h] [rbp+B0h]
  __m128 v601; // [rsp+180h] [rbp+C0h]
  __m128 v602; // [rsp+190h] [rbp+D0h]
  __m128 v603; // [rsp+1A0h] [rbp+E0h]
  __m128 v604; // [rsp+1B0h] [rbp+F0h]
  __m128 v605; // [rsp+1C0h] [rbp+100h]
  __m128 v606; // [rsp+1D0h] [rbp+110h]
  hkcdVertex *shapeB; // [rsp+1E0h] [rbp+120h]
  int v608; // [rsp+1E8h] [rbp+128h]
  hkcdVertex *shapeA; // [rsp+1F0h] [rbp+130h]
  int v610; // [rsp+1F8h] [rbp+138h]
  __m128 v611; // [rsp+200h] [rbp+140h]
  __m128 v612; // [rsp+210h] [rbp+150h]
  __m128 v613; // [rsp+220h] [rbp+160h]
  __m128 v614; // [rsp+230h] [rbp+170h]
  __m128 v615; // [rsp+240h] [rbp+180h]
  __m128 v616; // [rsp+250h] [rbp+190h]
  __m128 v617; // [rsp+260h] [rbp+1A0h]
  __m128 v618; // [rsp+270h] [rbp+1B0h]
  __m128 v619; // [rsp+280h] [rbp+1C0h]
  __m128 v620; // [rsp+290h] [rbp+1D0h]
  __m128 v621; // [rsp+2A0h] [rbp+1E0h]
  __m128 v622; // [rsp+2B0h] [rbp+1F0h]
  __m128 v623; // [rsp+2C0h] [rbp+200h]
  __m128 v624; // [rsp+2D0h] [rbp+210h]
  __m128 v625; // [rsp+2E0h] [rbp+220h]
  __m128 v626; // [rsp+2F0h] [rbp+230h]
  __m128 v627; // [rsp+300h] [rbp+240h]
  __m128 v628; // [rsp+310h] [rbp+250h]
  __m128 v629; // [rsp+320h] [rbp+260h]
  __m128 v630; // [rsp+330h] [rbp+270h]
  __m128 v631; // [rsp+340h] [rbp+280h]
  __m128 v632; // [rsp+350h] [rbp+290h]
  __m128 v633; // [rsp+360h] [rbp+2A0h]
  __m128 v634; // [rsp+370h] [rbp+2B0h]
  __m128 v635; // [rsp+380h] [rbp+2C0h]
  __m128 v636; // [rsp+390h] [rbp+2D0h]
  __m128 v637; // [rsp+3A0h] [rbp+2E0h]
  __m128 v638; // [rsp+3B0h] [rbp+2F0h]
  __m128 v639; // [rsp+3C0h] [rbp+300h]
  __m128 v640; // [rsp+3D0h] [rbp+310h]
  __m128 v641; // [rsp+3E0h] [rbp+320h]
  __m128 v642; // [rsp+3F0h] [rbp+330h]
  __m128 v643; // [rsp+400h] [rbp+340h]
  __m128 v644; // [rsp+410h] [rbp+350h]
  __m128 v645; // [rsp+420h] [rbp+360h]
  __m128 v646; // [rsp+430h] [rbp+370h]
  __m128 v647; // [rsp+440h] [rbp+380h]
  __m128 v648; // [rsp+450h] [rbp+390h]
  hkVector4f v649; // [rsp+460h] [rbp+3A0h]
  __m128 v650; // [rsp+470h] [rbp+3B0h]
  __m128 v651; // [rsp+480h] [rbp+3C0h]
  __m128 v652; // [rsp+490h] [rbp+3D0h]
  __m128 v653; // [rsp+4A0h] [rbp+3E0h]
  __m128 v654; // [rsp+4B0h] [rbp+3F0h]
  __m128 v655; // [rsp+4C0h] [rbp+400h]
  __m128 v656; // [rsp+4D0h] [rbp+410h]
  __m128 v657; // [rsp+4E0h] [rbp+420h]
  __m128 v658; // [rsp+4F0h] [rbp+430h]
  __m128 v659; // [rsp+500h] [rbp+440h]
  __m128 v660; // [rsp+510h] [rbp+450h]
  hkVector4f v661; // [rsp+520h] [rbp+460h]
  hkVector4f v662; // [rsp+530h] [rbp+470h]
  hkVector4f v663; // [rsp+540h] [rbp+480h]
  hkVector4f v664; // [rsp+550h] [rbp+490h]
  __m128 v665; // [rsp+560h] [rbp+4A0h]
  __m128 v666; // [rsp+570h] [rbp+4B0h]
  __m128 v667; // [rsp+580h] [rbp+4C0h]
  __m128 v668; // [rsp+590h] [rbp+4D0h]
  __m128 v669; // [rsp+5A0h] [rbp+4E0h]
  __m128 v670; // [rsp+5B0h] [rbp+4F0h]
  __m128 v671; // [rsp+5C0h] [rbp+500h]
  __m128 v672; // [rsp+5D0h] [rbp+510h]
  __m128 v673; // [rsp+5E0h] [rbp+520h]
  __m128 v674; // [rsp+5F0h] [rbp+530h]
  __m128 v675; // [rsp+600h] [rbp+540h]
  __m128 v676; // [rsp+610h] [rbp+550h]
  __m128 v677; // [rsp+620h] [rbp+560h]
  __m128 v678; // [rsp+630h] [rbp+570h]
  __m128 v679; // [rsp+640h] [rbp+580h]
  __m128 v680; // [rsp+650h] [rbp+590h]
  __m128 v681; // [rsp+660h] [rbp+5A0h]
  __m128 v682; // [rsp+670h] [rbp+5B0h]
  __m128 v683; // [rsp+680h] [rbp+5C0h]
  __m128 v684; // [rsp+690h] [rbp+5D0h]
  __m128 v685; // [rsp+6A0h] [rbp+5E0h]
  __m128 v686; // [rsp+6B0h] [rbp+5F0h]
  __m128 v687; // [rsp+6C0h] [rbp+600h]
  __m128 v688; // [rsp+6D0h] [rbp+610h]
  __m128 v689; // [rsp+6E0h] [rbp+620h]
  __m128 v690; // [rsp+6F0h] [rbp+630h]
  __m128 v691; // [rsp+700h] [rbp+640h]
  __m128 v692; // [rsp+710h] [rbp+650h]
  __m128 v693; // [rsp+720h] [rbp+660h]
  __m128 v694; // [rsp+730h] [rbp+670h]
  __m128 v695; // [rsp+740h] [rbp+680h]
  __int128 v696; // [rsp+750h] [rbp+690h]
  __int128 v697; // [rsp+760h] [rbp+6A0h]
  __int128 v698; // [rsp+770h] [rbp+6B0h]
  __int128 v699; // [rsp+780h] [rbp+6C0h]
  __m128 v700; // [rsp+790h] [rbp+6D0h]
  __int128 v701; // [rsp+7A0h] [rbp+6E0h]
  __int128 v702; // [rsp+7B0h] [rbp+6F0h]
  __int128 v703; // [rsp+7C0h] [rbp+700h]
  __int128 v704; // [rsp+7D0h] [rbp+710h]
  __m128 v705; // [rsp+7E0h] [rbp+720h]
  __m128 v706; // [rsp+7F0h] [rbp+730h]
  __m128 v707; // [rsp+800h] [rbp+740h]
  __m128 v708; // [rsp+810h] [rbp+750h]
  __m128 v709; // [rsp+820h] [rbp+760h]
  __m128 v710; // [rsp+830h] [rbp+770h]
  __m128 v711; // [rsp+840h] [rbp+780h]
  __m128 v712; // [rsp+850h] [rbp+790h]
  __m128 v713; // [rsp+860h] [rbp+7A0h]
  __m128 v714; // [rsp+870h] [rbp+7B0h]
  __m128 v715; // [rsp+880h] [rbp+7C0h]
  __m128 v716; // [rsp+890h] [rbp+7D0h]
  __m128 v717; // [rsp+8A0h] [rbp+7E0h]
  __m128 v718; // [rsp+8B0h] [rbp+7F0h]
  __m128 v719; // [rsp+8C0h] [rbp+800h]
  __m128 v720; // [rsp+8D0h] [rbp+810h]
  __int128 v721; // [rsp+8E0h] [rbp+820h]
  __int128 v722; // [rsp+8F0h] [rbp+830h]
  __int128 v723; // [rsp+900h] [rbp+840h]
  __int128 v724; // [rsp+910h] [rbp+850h]
  __m128 v725; // [rsp+920h] [rbp+860h]
  __m128 v726; // [rsp+930h] [rbp+870h]
  __m128 v727; // [rsp+940h] [rbp+880h]
  __m128 v728; // [rsp+950h] [rbp+890h]
  __m128 v729; // [rsp+960h] [rbp+8A0h]
  __m128 v730; // [rsp+970h] [rbp+8B0h]
  __m128 v731; // [rsp+980h] [rbp+8C0h]
  __m128 v732; // [rsp+990h] [rbp+8D0h]
  __m128 v733; // [rsp+9A0h] [rbp+8E0h]
  __m128 v734; // [rsp+9B0h] [rbp+8F0h]
  __m128 v735; // [rsp+9C0h] [rbp+900h]
  __m128 v736; // [rsp+9D0h] [rbp+910h]
  __m128 v737; // [rsp+9E0h] [rbp+920h]
  __m128 v738; // [rsp+9F0h] [rbp+930h]
  __m128 v739; // [rsp+A00h] [rbp+940h]
  __m128 v740; // [rsp+A10h] [rbp+950h]
  __int128 v741; // [rsp+A20h] [rbp+960h]
  __int128 v742; // [rsp+A30h] [rbp+970h]
  __int128 v743; // [rsp+A40h] [rbp+980h]
  __int128 v744; // [rsp+A50h] [rbp+990h]
  __m128 v745; // [rsp+A60h] [rbp+9A0h]
  __m128 v746; // [rsp+A70h] [rbp+9B0h]
  int v747; // [rsp+B70h] [rbp+AB0h]
  hkPadSpu<int> dimA; // [rsp+B78h] [rbp+AB8h]
  hkcdGskBase::ShapeInterface shapeInterface; // [rsp+B80h] [rbp+AC0h]
  hkPadSpu<int> dimB; // [rsp+B88h] [rbp+AC8h]
  hkTransformf *v751; // [rsp+B90h] [rbp+AD0h]
  char *v752; // [rsp+B98h] [rbp+AD8h]
  hkcdGsk::GetClosestPointOutput *vars0; // [rsp+BA0h] [rbp+AE0h]

  v4 = v752;
  v610 = numVertsA;
  v608 = numVertsB;
  shapeA = vertsA;
  shapeB = vertsB;
  v5 = vertsA;
  v6 = v594.m_verticesBinA;
  v7 = v752;
  shapeInterface.vfptr = (hkcdGskBase::ShapeInterfaceVtbl *)&hkcdGsk_Vector4ShapeInterface::`vftable';
  v8 = (unsigned int)(unsigned __int8)v752[4] >> 6;
  v9 = v752[4] & 3;
  v10 = (unsigned int)(unsigned __int8)v752[4] >> 6;
  while ( 1 )
  {
    v11 = (unsigned __int8)*v7;
    v12 = v6;
    ++v6;
    ++v7;
    *v12 = v5[v11];
    if ( !--v10 )
      break;
    v5 = shapeA;
  }
  v13 = &v642;
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
  aTb = v751;
  dimB.m_storage = v9;
  dimA.m_storage = v8;
  v19 = 0i64;
  v20.m_quad = 0i64;
  *(_OWORD *)&v594.m_lastDimB.m_storage = 0i64;
  v21 = v9 - 1;
  v22.m_quad = (__m128)v751->m_rotation.m_col0;
  v23 = v21;
  v661.m_quad = (__m128)v751->m_rotation.m_col0;
  v24.m_quad = (__m128)v751->m_rotation.m_col1;
  v662.m_quad = (__m128)v751->m_rotation.m_col1;
  v25.m_quad = (__m128)v751->m_rotation.m_col2;
  v663.m_quad = (__m128)v751->m_rotation.m_col2;
  v26.m_quad = (__m128)v751->m_translation;
  v664.m_quad = (__m128)v751->m_translation;
  do
  {
    v27 = *(__m128 *)((char *)&v642 + v23 * 16);
    --v23;
    --v21;
    v594.m_verticesBinA[v23 + 1].m_quad = _mm_add_ps(
                                            _mm_add_ps(
                                              _mm_add_ps(
                                                _mm_mul_ps(_mm_shuffle_ps(v27, v27, 85), v24.m_quad),
                                                _mm_mul_ps(_mm_shuffle_ps(v27, v27, 0), v22.m_quad)),
                                              _mm_mul_ps(_mm_shuffle_ps(v27, v27, 170), v25.m_quad)),
                                            v26.m_quad);
  }
  while ( v21 >= 0 );
  v28 = 0;
  v29.m_quad = _mm_shuffle_ps(v594.m_verticesBinA[0].m_quad, _mm_unpackhi_ps(v594.m_verticesBinA[0].m_quad, v642), 196);
  v594.m_verticesBinA[0].0 = (hkVector4f)v29.m_quad;
  v594.m_verticesBinA[1].m_quad = _mm_shuffle_ps(
                                    v594.m_verticesBinA[1].m_quad,
                                    _mm_unpackhi_ps(v594.m_verticesBinA[1].m_quad, v643),
                                    196);
  *(float *)&v752 = FLOAT_0_0000099999997;
  v594.m_verticesBinA[2].m_quad = _mm_shuffle_ps(
                                    v594.m_verticesBinA[2].m_quad,
                                    _mm_unpackhi_ps(v594.m_verticesBinA[2].m_quad, v644),
                                    196);
  v30 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_0000099999997), (__m128)LODWORD(FLOAT_0_0000099999997), 0);
LABEL_9:
  v31 = v594.m_verticesA[0].m_quad;
  *(float *)&v752 = aTb[1].m_rotation.m_col2.m_quad.m128_f32[0];
  v594.m_checkTriangleDots = (hkVector4f)v29.m_quad;
  v32 = (dimB.m_storage | 8 * dimA.m_storage) - 9;
  v627 = _mm_mul_ps(v30, _mm_shuffle_ps((__m128)(unsigned int)v752, (__m128)(unsigned int)v752, 0));
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
        v411 = v31;
        v412 = (__m128 *)v594.m_verticesBinA;
        goto LABEL_97;
      case 8u:
        goto LABEL_136;
      case 9u:
        goto LABEL_44;
      case 0xAu:
        v34 = (__m128 *)v594.m_verticesA;
        v35 = (__m128 *)v594.m_verticesBinA;
        goto LABEL_13;
      case 0x10u:
        goto LABEL_112;
      case 0x11u:
        v34 = (__m128 *)v594.m_verticesBinA;
        v35 = (__m128 *)v594.m_verticesA;
LABEL_13:
        if ( v594.m_lastDimB.m_storage == 2 )
        {
          v36 = *v35;
          v37 = *v34;
          v38 = v34[1];
          v598 = v35[1];
          v39 = _mm_sub_ps(v598, v35[2]);
          v592 = v39;
          v40 = _mm_sub_ps(v36, v35[2]);
          v595 = v40;
          v41 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v40, v40, 201), v39),
                  _mm_mul_ps(_mm_shuffle_ps(v39, v39, 201), v40));
          v42 = _mm_shuffle_ps(v41, v41, 201);
          v43 = _mm_mul_ps(_mm_sub_ps(v37, v36), v42);
          v44 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v43, v43, 85), _mm_shuffle_ps(v43, v43, 0)),
                  _mm_shuffle_ps(v43, v43, 170));
          v45 = _mm_mul_ps(_mm_sub_ps(v38, v36), v42);
          v46 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v45, v45, 85), _mm_shuffle_ps(v45, v45, 0)),
                  _mm_shuffle_ps(v45, v45, 170));
          v47 = _mm_mul_ps(v44, v44);
          v48 = _mm_mul_ps(v46, v46);
          if ( _mm_movemask_ps(_mm_mul_ps(v44, v46)) )
          {
            v720 = _mm_sub_ps(v44, v46);
            v49 = _mm_rcp_ps(v720);
            v651 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v49, v720)), v49), v44);
            v50 = _mm_sub_ps(v35[1], *v35);
            v51 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v34[1], *v34), v651), *v34);
            v52 = _mm_sub_ps(v35[2], *v35);
            v53 = _mm_sub_ps(v35[1], v51);
            v54 = _mm_sub_ps(v35[2], v51);
            v55 = _mm_sub_ps(*v35, v51);
            v56 = _mm_sub_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v52, v52, 201), v50),
                    _mm_mul_ps(_mm_shuffle_ps(v50, v50, 201), v52));
            v57 = _mm_shuffle_ps(v56, v56, 201);
            v58 = _mm_shuffle_ps(v57, v57, 210);
            v59 = _mm_mul_ps(
                    _mm_sub_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v54, v54, 201), v58),
                      _mm_mul_ps(_mm_shuffle_ps(v54, v54, 210), v57)),
                    v53);
            v60 = _mm_shuffle_ps(v53, v53, 210);
            v61 = _mm_mul_ps(
                    _mm_sub_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v55, v55, 201), v58),
                      _mm_mul_ps(_mm_shuffle_ps(v55, v55, 210), v57)),
                    v54);
            v62 = _mm_mul_ps(_mm_shuffle_ps(v53, v53, 201), v58);
            v63 = v59;
            v64 = _mm_unpackhi_ps(v59, v61);
            v65 = _mm_unpacklo_ps(v63, v61);
            v66 = _mm_mul_ps(_mm_sub_ps(v62, _mm_mul_ps(v60, v57)), v55);
            v67 = _mm_movelh_ps(v65, v66);
            if ( (_mm_movemask_ps(
                    _mm_cmpltps(
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
          v69 = _mm_cmpltps(v47, v48);
          v70 = v35[2];
          v71 = _mm_or_ps(_mm_andnot_ps(v69, v38), _mm_and_ps(v69, v37));
          v72 = v35[1];
          v73 = _mm_sub_ps(v36, v70);
          v74 = _mm_sub_ps(v70, v72);
          v75 = _mm_sub_ps(v71, v72);
          v76 = _mm_sub_ps(v72, v36);
          v77 = _mm_sub_ps(v71, v70);
          v78 = _mm_shuffle_ps(v74, v74, 201);
          v79 = _mm_shuffle_ps(v73, v73, 201);
          v80 = _mm_sub_ps(v71, *v35);
          v81 = _mm_sub_ps(_mm_mul_ps(v74, v79), _mm_mul_ps(v73, v78));
          v20.m_quad = _mm_shuffle_ps(v81, v81, 201);
          *(hkVector4f *)&v594.m_lastDimB.m_storage = (hkVector4f)v20.m_quad;
          v82 = _mm_sub_ps(_mm_mul_ps(v75, v78), _mm_mul_ps(_mm_shuffle_ps(v75, v75, 201), v74));
          v83 = _mm_mul_ps(_mm_shuffle_ps(v82, v82, 201), v20.m_quad);
          v84 = _mm_sub_ps(_mm_mul_ps(v77, v79), _mm_mul_ps(_mm_shuffle_ps(v77, v77, 201), v73));
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
          v93 = _mm_movemask_ps(_mm_cmpltps(v92.m_quad, v19)) & 7;
          if ( v93 == 7 )
          {
            v94 = _mm_mul_ps(_mm_sub_ps(v31, v29.m_quad), v20.m_quad);
            if ( _mm_movemask_ps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v94, v94, 85), _mm_shuffle_ps(v94, v94, 0)),
                     _mm_shuffle_ps(v94, v94, 170))) )
            {
              v95 = *v35;
              v20.m_quad = _mm_xor_ps(
                             v20.m_quad,
                             (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0));
              *v35 = v598;
              v35[1] = v95;
              v33 = query.m_quad;
              *(hkVector4f *)&v594.m_lastDimB.m_storage = (hkVector4f)v20.m_quad;
              v92.m_quad = _mm_shuffle_ps(v92.m_quad, v92.m_quad, 225);
              supportOut = query.m_quad;
            }
          }
          v594.m_checkTriangleDots = (hkVector4f)v92.m_quad;
          if ( v93 != 7 )
          {
            v39 = v592;
LABEL_23:
            v96 = _mm_sub_ps(v35[2], *v34);
            v97 = _mm_sub_ps(v34[1], *v34);
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
            v653 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v99, v99, 85), _mm_shuffle_ps(v99, v99, 0)),
                     _mm_shuffle_ps(v99, v99, 170));
            v655 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v105, v105, 85), _mm_shuffle_ps(v105, v105, 0)),
                     _mm_shuffle_ps(v105, v105, 170));
            v106 = _mm_max_ps(_mm_sub_ps(_mm_mul_ps(v655, v653), _mm_mul_ps(v100, v100)), *(__m128 *)&epsilon);
            v107 = _mm_rcp_ps(v106);
            v657 = v106;
            v108 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v107, v106)), v107);
            v109 = _mm_rcp_ps(v655);
            v659 = v108;
            v110 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v109, v655)), v109);
            v111 = _mm_rcp_ps(v653);
            v746 = v110;
            v740 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v111, v653)), v111);
            v112 = _mm_cmpleps(v106, *(__m128 *)&epsilon);
            v113 = _mm_sub_ps(_mm_mul_ps(v655, v103), _mm_mul_ps(v104, v100));
            v114 = _mm_cmpltps(v113, v106);
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
            v116 = _mm_cmpltps(v115, v33);
            v117 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v115, v116), _mm_andnot_ps(v116, v33)));
            v118 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v740, v100), v117), _mm_mul_ps(v740, v103));
            v119 = v35[2];
            v120 = _mm_add_ps(_mm_mul_ps(v117, v592), v119);
            v121 = _mm_sub_ps(v119, *v34);
            v122 = _mm_cmpltps(v118, v33);
            v123 = _mm_sub_ps(
                     _mm_add_ps(
                       _mm_mul_ps(
                         _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v118, v122), _mm_andnot_ps(v122, v33))),
                         v97),
                       *v34),
                     v120);
            v124 = _mm_mul_ps(v97, v595);
            v125 = _mm_mul_ps(v123, v123);
            v126 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v125, v125, 85), _mm_shuffle_ps(v125, v125, 0)),
                     _mm_shuffle_ps(v125, v125, 170));
            v127 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v124, v124, 85), _mm_shuffle_ps(v124, v124, 0)),
                     _mm_shuffle_ps(v124, v124, 170));
            v128 = v121;
            v129 = _mm_mul_ps(v121, v595);
            v130 = _mm_mul_ps(v128, v97);
            v131 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v130, v130, 85), _mm_shuffle_ps(v130, v130, 0)),
                     _mm_shuffle_ps(v130, v130, 170));
            v132 = _mm_mul_ps(v595, v595);
            v133 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v129, v129, 85), _mm_shuffle_ps(v129, v129, 0)),
                     _mm_shuffle_ps(v129, v129, 170));
            v648 = v653;
            v690 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v132, v132, 85), _mm_shuffle_ps(v132, v132, 0)),
                     _mm_shuffle_ps(v132, v132, 170));
            v134 = _mm_max_ps(_mm_sub_ps(_mm_mul_ps(v690, v653), _mm_mul_ps(v127, v127)), *(__m128 *)&epsilon);
            v135 = _mm_rcp_ps(v134);
            v650 = v134;
            v136 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v135, v134)), v135);
            v137 = _mm_rcp_ps(v690);
            v645 = v136;
            v138 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v137, v690)), v137);
            v139 = _mm_rcp_ps(v653);
            v652 = v138;
            v140 = _mm_cmpleps(v134, *(__m128 *)&epsilon);
            v141 = _mm_sub_ps(_mm_mul_ps(v690, v131), _mm_mul_ps(v133, v127));
            v695 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v139, v653)), v139);
            v142 = _mm_cmpltps(v141, v134);
            v19 = 0i64;
            v143 = _mm_sub_ps(
                     _mm_mul_ps(
                       _mm_or_ps(
                         _mm_andnot_ps(
                           v140,
                           _mm_mul_ps(
                             _mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_and_ps(v142, v141), _mm_andnot_ps(v142, v134))),
                             v136)),
                         _mm_and_ps(v140, supportOut)),
                       _mm_mul_ps(v138, v127)),
                     _mm_mul_ps(v138, v133));
            v144 = _mm_cmpltps(v143, supportOut);
            v145 = v35[2];
            v20.m_quad = *(__m128 *)&v594.m_lastDimB.m_storage;
            v146 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v144, v143), _mm_andnot_ps(v144, supportOut)));
            v147 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v695, v127), v146), _mm_mul_ps(v695, v131));
            v148 = _mm_cmpltps(v147, supportOut);
            v149 = _mm_sub_ps(
                     _mm_add_ps(
                       _mm_mul_ps(
                         _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v148, v147), _mm_andnot_ps(v148, supportOut))),
                         v97),
                       *v34),
                     _mm_add_ps(_mm_mul_ps(v146, v595), v145));
            v150 = _mm_mul_ps(v149, v149);
            v151 = _mm_cmpltps(
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v150, v150, 85), _mm_shuffle_ps(v150, v150, 0)),
                       _mm_shuffle_ps(v150, v150, 170)),
                     v126);
            *v35 = _mm_or_ps(_mm_and_ps(*v35, v151), _mm_andnot_ps(v151, v35[1]));
            v35[1] = v145;
LABEL_38:
            v68 = 2;
            goto LABEL_39;
          }
          *v34 = v71;
          v68 = 0;
LABEL_39:
          v31 = v594.m_verticesA[0].m_quad;
          v29.m_quad = (__m128)v594.m_verticesBinA[0];
          supportOut = query.m_quad;
          v594.m_checkTriangleDots = (hkVector4f)v594.m_verticesBinA[0];
          goto LABEL_40;
        }
        v152 = *v35;
        v153 = v34[1];
        v154.m_quad = (__m128)v594.m_checkTriangleDots;
        v155 = _mm_mul_ps(_mm_sub_ps(*v34, *v35), v20.m_quad);
        v156 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v155, v155, 85), _mm_shuffle_ps(v155, v155, 0)),
                 _mm_shuffle_ps(v155, v155, 170));
        v157 = _mm_mul_ps(_mm_sub_ps(v34[1], *v35), v20.m_quad);
        v158 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v157, v157, 85), _mm_shuffle_ps(v157, v157, 0)),
                 _mm_shuffle_ps(v157, v157, 170));
        if ( (float)(v158.m128_f32[0] * v156.m128_f32[0]) < v19.m128_f32[0] )
        {
          v654 = _mm_sub_ps(v156, v158);
          v159 = _mm_rcp_ps(v654);
          v735 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v654, v159)), v159), v156);
          v152 = *v35;
          v153 = v34[1];
          v160 = _mm_sub_ps(v35[2], *v35);
          v161 = _mm_sub_ps(v35[1], *v35);
          v162 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v34[1], *v34), v735), *v34);
          v163 = _mm_sub_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v160, v160, 201), v161),
                   _mm_mul_ps(_mm_shuffle_ps(v161, v161, 201), v160));
          v164 = _mm_shuffle_ps(v163, v163, 201);
          v165 = _mm_sub_ps(v35[1], v162);
          v166 = _mm_sub_ps(*v35, v162);
          v167 = _mm_sub_ps(v35[2], v162);
          v168 = _mm_shuffle_ps(v164, v164, 210);
          v169 = _mm_mul_ps(
                   _mm_sub_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v167, v167, 201), v168),
                     _mm_mul_ps(_mm_shuffle_ps(v167, v167, 210), v164)),
                   v165);
          v170 = _mm_shuffle_ps(v165, v165, 210);
          v171 = _mm_mul_ps(
                   _mm_sub_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v166, v166, 201), v168),
                     _mm_mul_ps(_mm_shuffle_ps(v166, v166, 210), v164)),
                   v167);
          v172 = _mm_mul_ps(_mm_shuffle_ps(v165, v165, 201), v168);
          v173 = v169;
          v174 = _mm_unpackhi_ps(v169, v171);
          v175 = _mm_unpacklo_ps(v173, v171);
          v176 = _mm_mul_ps(_mm_sub_ps(v172, _mm_mul_ps(v170, v164)), v166);
          v177 = _mm_movelh_ps(v175, v176);
          if ( (_mm_movemask_ps(
                  _mm_cmpltps(
                    v19,
                    _mm_add_ps(
                      _mm_shuffle_ps(v174, v176, 228),
                      _mm_add_ps(v177, _mm_shuffle_ps(_mm_movehl_ps(v177, v175), v176, 212))))) & 7) == 7 )
          {
            v68 = 1;
            goto LABEL_40;
          }
        }
        v178 = v35[1];
        v179 = v35[2];
        v180 = _mm_sub_ps(v152, v179);
        v181 = _mm_sub_ps(v35[1], v152);
        v182 = _mm_shuffle_ps(v180, v180, 201);
        v183 = v153;
        v184 = v153;
        v185 = _mm_sub_ps(v153, *v35);
        v186 = _mm_sub_ps(v183, v178);
        v187 = _mm_sub_ps(v35[2], v178);
        v188 = _mm_sub_ps(v184, v179);
        v189 = _mm_shuffle_ps(v187, v187, 201);
        v190 = _mm_sub_ps(_mm_mul_ps(v187, v182), _mm_mul_ps(v180, v189));
        v191 = _mm_shuffle_ps(v190, v190, 201);
        v192 = _mm_sub_ps(_mm_mul_ps(v186, v189), _mm_mul_ps(_mm_shuffle_ps(v186, v186, 201), v187));
        v193 = _mm_sub_ps(_mm_mul_ps(v188, v182), _mm_mul_ps(_mm_shuffle_ps(v188, v188, 201), v180));
        v194 = _mm_mul_ps(_mm_shuffle_ps(v192, v192, 201), v191);
        v195 = _mm_mul_ps(_mm_shuffle_ps(v193, v193, 201), v191);
        v196 = _mm_unpacklo_ps(v194, v195);
        v197 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v181, v181, 201), v185),
                 _mm_mul_ps(_mm_shuffle_ps(v185, v185, 201), v181));
        v198 = _mm_mul_ps(_mm_shuffle_ps(v197, v197, 201), v191);
        v199 = _mm_movelh_ps(v196, v198);
        v200.m_quad = _mm_add_ps(
                        _mm_shuffle_ps(_mm_unpackhi_ps(v194, v195), v198, 228),
                        _mm_add_ps(v199, _mm_shuffle_ps(_mm_movehl_ps(v199, v196), v198, 212)));
        v594.m_checkTriangleDots = (hkVector4f)v200.m_quad;
        v201 = _mm_movemask_ps(_mm_cmpltps(v200.m_quad, (__m128)0i64)) & 7;
        switch ( v201 )
        {
          case 7:
            v68 = 0;
            v19 = 0i64;
            *v34 = v34[1];
            goto LABEL_39;
          case 6:
            goto LABEL_37;
          case 5:
            goto LABEL_54;
          case 3:
            goto LABEL_55;
          case 1:
            LODWORD(v202) = (unsigned __int128)_mm_shuffle_ps(v154.m_quad, v154.m_quad, 85);
            LODWORD(v203) = (unsigned __int128)_mm_shuffle_ps(v154.m_quad, v154.m_quad, 170);
            if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v200.m_quad, v200.m_quad, 85)) - v202) * v203) > (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v200.m_quad, v200.m_quad, 170)) - v203) * v202) )
              goto LABEL_55;
            goto LABEL_54;
        }
        if ( v201 != 2 )
        {
          if ( v201 != 4
            || (LODWORD(v256) = (unsigned __int128)_mm_shuffle_ps(v154.m_quad, v154.m_quad, 0),
                LODWORD(v257) = (unsigned __int128)_mm_shuffle_ps(v154.m_quad, v154.m_quad, 85),
                (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v200.m_quad, v200.m_quad, 0)) - v256) * v257) <= (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v200.m_quad, v200.m_quad, 85)) - v257) * v256)) )
          {
LABEL_37:
            v19 = 0i64;
            *v35 = v35[2];
            goto LABEL_38;
          }
LABEL_54:
          v35[1] = v35[2];
          v29.m_quad = (__m128)v594.m_verticesBinA[0];
          v31 = v594.m_verticesA[0].m_quad;
          v594.m_checkTriangleDots = (hkVector4f)v594.m_verticesBinA[0];
          supportOut = query.m_quad;
          goto LABEL_55;
        }
        LODWORD(v204) = (unsigned __int128)_mm_shuffle_ps(v154.m_quad, v154.m_quad, 170);
        LODWORD(v205) = (unsigned __int128)_mm_shuffle_ps(v154.m_quad, v154.m_quad, 0);
        if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v200.m_quad, v200.m_quad, 170)) - v204) * v205) > (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v200.m_quad, v200.m_quad, 0)) - v205) * v204) )
          goto LABEL_37;
LABEL_55:
        v68 = 2;
        v19 = 0i64;
LABEL_40:
        if ( v68 )
        {
          v206 = v68 - 1;
          if ( !v206 )
            goto LABEL_65;
          if ( v206 != 1 )
            goto LABEL_150;
          dimA.m_storage = 2;
          dimB.m_storage = 2;
LABEL_44:
          v207 = _mm_sub_ps(v31, v29.m_quad);
          v208 = _mm_sub_ps(v594.m_verticesA[1].m_quad, v31);
          v209 = _mm_sub_ps(v594.m_verticesBinA[1].m_quad, v29.m_quad);
          v210 = _mm_shuffle_ps(v209, v209, 201);
          v211 = _mm_shuffle_ps(v208, v208, 201);
          v598 = v208;
          v212 = _mm_sub_ps(_mm_mul_ps(v208, v210), _mm_mul_ps(v209, v211));
          v20.m_quad = _mm_shuffle_ps(v212, v212, 201);
          *(hkVector4f *)&v594.m_lastDimB.m_storage = (hkVector4f)v20.m_quad;
          v213 = _mm_sub_ps(_mm_mul_ps(v211, v20.m_quad), _mm_mul_ps(v208, v20.m_quad));
          v214 = _mm_shuffle_ps(v213, v213, 201);
          v215 = _mm_sub_ps(_mm_mul_ps(v210, v20.m_quad), _mm_mul_ps(v209, v20.m_quad));
          v216 = _mm_mul_ps(v207, v214);
          v217 = _mm_mul_ps(_mm_sub_ps(v594.m_verticesBinA[1].m_quad, v31), v214);
          v218 = _mm_shuffle_ps(v215, v215, 201);
          v219 = _mm_shuffle_ps(v216, v217, 68);
          v220 = _mm_mul_ps(v207, v218);
          v221 = _mm_mul_ps(_mm_sub_ps(v29.m_quad, v594.m_verticesA[1].m_quad), v218);
          v222 = _mm_shuffle_ps(v220, v221, 68);
          v223 = _mm_add_ps(
                   _mm_shuffle_ps(_mm_shuffle_ps(v220, v221, 238), _mm_shuffle_ps(v216, v217, 238), 136),
                   _mm_add_ps(_mm_shuffle_ps(v222, v219, 221), _mm_shuffle_ps(v222, v219, 136)));
          v224 = _mm_movemask_ps(_mm_cmpltps(v19, v223));
          if ( v224 == 15 )
          {
            v407 = _mm_mul_ps(v207, v20.m_quad);
            v408 = _mm_shuffle_ps(v223, v223, 0);
            v409 = _mm_add_ps(_mm_shuffle_ps(v223, v223, 85), v408);
            v410 = _mm_rcp_ps(v409);
            v665 = v409;
            v745 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v410, v409)), v410), v408);
            v392 = _mm_xor_ps(
                     (__m128)_mm_slli_epi32(
                               _mm_srli_epi32(
                                 (__m128i)_mm_add_ps(
                                            _mm_add_ps(_mm_shuffle_ps(v407, v407, 85), _mm_shuffle_ps(v407, v407, 0)),
                                            _mm_shuffle_ps(v407, v407, 170)),
                                 0x1Fu),
                               0x1Fu),
                     v20.m_quad);
            v594.m_closestPointOnEdgeA.m_quad = _mm_add_ps(
                                                  _mm_mul_ps(_mm_sub_ps(v594.m_verticesA[1].m_quad, v31), v745),
                                                  v31);
            goto LABEL_149;
          }
          v225 = v224 - 7;
          if ( !v225 )
          {
            v29.m_quad = (__m128)v594.m_verticesBinA[1];
            v594.m_checkTriangleDots = (hkVector4f)v594.m_verticesBinA[1];
            v594.m_verticesBinA[0] = v594.m_verticesBinA[1];
LABEL_93:
            dimB.m_storage = 1;
LABEL_136:
            v521 = _mm_sub_ps(v31, v29.m_quad);
            v522 = _mm_sub_ps(v594.m_verticesA[1].m_quad, v29.m_quad);
            v523 = _mm_sub_ps(v594.m_verticesA[1].m_quad, v31);
            v524 = _mm_mul_ps(v522, v523);
            v525 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v524, v524, 85), _mm_shuffle_ps(v524, v524, 0)),
                     _mm_shuffle_ps(v524, v524, 170));
            v526 = _mm_mul_ps(v521, v523);
            v527 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v526, v526, 85), _mm_shuffle_ps(v526, v526, 0)),
                     _mm_shuffle_ps(v526, v526, 170));
            if ( (float)(v527.m128_f32[0] * v525.m128_f32[0]) >= v19.m128_f32[0] )
            {
              v534 = _mm_cmpleps(v525, v19);
              dimA.m_storage = 1;
              v31 = _mm_or_ps(_mm_andnot_ps(v534, v31), _mm_and_ps(v594.m_verticesA[1].m_quad, v534));
              v594.m_verticesA[0].m_quad = v31;
              v392 = _mm_sub_ps(v31, v29.m_quad);
            }
            else
            {
              dimA.m_storage = 2;
              v528 = _mm_sub_ps(_mm_mul_ps(v521, v525), _mm_mul_ps(v522, v527));
              v529 = _mm_mul_ps(v523, v523);
              v530 = _mm_shuffle_ps(v523, v523, 201);
              v531 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v528, v528, 201), v523), _mm_mul_ps(v528, v530));
              v675 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v529, v529, 85), _mm_shuffle_ps(v529, v529, 0)),
                       _mm_shuffle_ps(v529, v529, 170));
              v532 = _mm_shuffle_ps(v531, v531, 201);
              v730 = _mm_rcp_ps(v675);
              v533 = _mm_sub_ps(_mm_mul_ps(v532, v530), _mm_mul_ps(v532, v523));
              v392 = _mm_mul_ps(_mm_shuffle_ps(v533, v533, 201), v730);
            }
LABEL_149:
            *(__m128 *)&v594.m_lastDimB.m_storage = v392;
LABEL_150:
            v20.m_quad = *(__m128 *)&v594.m_lastDimB.m_storage;
            v594.m_lastDimB = dimB;
            v260 = 0;
            goto LABEL_66;
          }
          v226 = v225 - 4;
          if ( !v226 )
            goto LABEL_93;
          v227 = v226 - 2;
          if ( !v227 )
          {
            v31 = v594.m_verticesA[1].m_quad;
            v594.m_verticesA[0] = v594.m_verticesA[1];
LABEL_89:
            dimA.m_storage = 1;
LABEL_90:
            v393 = _mm_sub_ps(v29.m_quad, v31);
            v394 = _mm_sub_ps(v594.m_verticesBinA[1].m_quad, v31);
            v395 = _mm_sub_ps(v594.m_verticesBinA[1].m_quad, v29.m_quad);
            v396 = _mm_mul_ps(v394, v395);
            v397 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v396, v396, 85), _mm_shuffle_ps(v396, v396, 0)),
                     _mm_shuffle_ps(v396, v396, 170));
            v398 = _mm_mul_ps(v395, v393);
            v399 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v398, v398, 85), _mm_shuffle_ps(v398, v398, 0)),
                     _mm_shuffle_ps(v398, v398, 170));
            if ( (float)(v399.m128_f32[0] * v397.m128_f32[0]) >= v19.m128_f32[0] )
            {
              v543 = _mm_cmpleps(v397, v19);
              v400 = 1;
              v29.m_quad = _mm_or_ps(_mm_and_ps(v594.m_verticesBinA[1].m_quad, v543), _mm_andnot_ps(v543, v29.m_quad));
              v594.m_checkTriangleDots = (hkVector4f)v29.m_quad;
              v392 = _mm_sub_ps(v31, v29.m_quad);
              v594.m_verticesBinA[0].0 = (hkVector4f)v29.m_quad;
            }
            else
            {
              v400 = 2;
              v401 = _mm_sub_ps(_mm_mul_ps(v397, v393), _mm_mul_ps(v399, v394));
              v402 = _mm_mul_ps(v395, v395);
              v403 = _mm_shuffle_ps(v395, v395, 201);
              v680 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v402, v402, 85), _mm_shuffle_ps(v402, v402, 0)),
                       _mm_shuffle_ps(v402, v402, 170));
              v404 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v401, v401, 201), v395), _mm_mul_ps(v403, v401));
              v715 = _mm_rcp_ps(v680);
              v405 = _mm_shuffle_ps(v404, v404, 201);
              v406 = _mm_sub_ps(_mm_mul_ps(v405, v395), _mm_mul_ps(v403, v405));
              v392 = _mm_mul_ps(_mm_shuffle_ps(v406, v406, 201), v715);
            }
            dimB.m_storage = v400;
            goto LABEL_149;
          }
          if ( v227 == 1 )
            goto LABEL_89;
          v228 = _mm_mul_ps(v209, v208);
          v229 = _mm_sub_ps(v29.m_quad, v31);
          v230 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v228, v228, 85), _mm_shuffle_ps(v228, v228, 0)),
                   _mm_shuffle_ps(v228, v228, 170));
          v231 = _mm_mul_ps(v229, v208);
          v232 = _mm_mul_ps(v229, v209);
          v233 = _mm_mul_ps(v209, v209);
          v234 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v231, v231, 85), _mm_shuffle_ps(v231, v231, 0)),
                   _mm_shuffle_ps(v231, v231, 170));
          v235 = _mm_mul_ps(v208, v208);
          v236 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v232, v232, 85), _mm_shuffle_ps(v232, v232, 0)),
                   _mm_shuffle_ps(v232, v232, 170));
          v656 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v235, v235, 85), _mm_shuffle_ps(v235, v235, 0)),
                   _mm_shuffle_ps(v235, v235, 170));
          v700 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v233, v233, 85), _mm_shuffle_ps(v233, v233, 0)),
                   _mm_shuffle_ps(v233, v233, 170));
          v237 = _mm_max_ps(_mm_sub_ps(_mm_mul_ps(v700, v656), _mm_mul_ps(v230, v230)), *(__m128 *)&epsilon);
          v238 = _mm_rcp_ps(v237);
          v658 = v237;
          v239 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v238, v237)), v238);
          v240 = _mm_rcp_ps(v700);
          v725 = v239;
          v241 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v240, v700)), v240);
          v242 = _mm_rcp_ps(v656);
          v660 = v241;
          v243 = _mm_sub_ps(_mm_mul_ps(v700, v234), _mm_mul_ps(v236, v230));
          v705 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v242, v656)), v242);
          v244 = _mm_cmpltps(v243, v237);
          v245 = _mm_cmpleps(v237, *(__m128 *)&epsilon);
          v246 = _mm_mul_ps(
                   _mm_or_ps(
                     _mm_andnot_ps(
                       v245,
                       _mm_mul_ps(
                         _mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_andnot_ps(v244, v237), _mm_and_ps(v243, v244))),
                         v239)),
                     _mm_and_ps(v245, supportOut)),
                   _mm_mul_ps(v241, v230));
          v247 = _mm_mul_ps(v705, v230);
          v248 = _mm_mul_ps(v705, v234);
          v33 = supportOut;
          v249 = _mm_sub_ps(v246, _mm_mul_ps(v241, v236));
          v19 = 0i64;
          v250 = _mm_cmpltps(v249, supportOut);
          v251 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v249, v250), _mm_andnot_ps(v250, supportOut)));
          v252 = _mm_add_ps(_mm_mul_ps(v247, v251), v248);
          v253 = _mm_cmpltps(v252, supportOut);
          v254 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v252, v253), _mm_andnot_ps(v253, supportOut)));
          v255 = _mm_movemask_ps(
                   _mm_cmpeqps(
                     _mm_movelh_ps(_mm_unpacklo_ps(v254, v254), _mm_unpacklo_ps(v251, v251)),
                     (__m128)xmmword_141A71330));
          v594.m_closestPointOnEdgeA.m_quad = _mm_add_ps(_mm_mul_ps(v254, v598), v31);
          if ( !v255 )
          {
            v391 = _mm_mul_ps(v207, v20.m_quad);
            v392 = _mm_xor_ps(
                     (__m128)_mm_slli_epi32(
                               _mm_srli_epi32(
                                 (__m128i)_mm_add_ps(
                                            _mm_add_ps(_mm_shuffle_ps(v391, v391, 85), _mm_shuffle_ps(v391, v391, 0)),
                                            _mm_shuffle_ps(v391, v391, 170)),
                                 0x1Fu),
                               0x1Fu),
                     v20.m_quad);
            goto LABEL_149;
          }
          if ( v255 & 1 )
          {
            v31 = v594.m_verticesA[1].m_quad;
            dimA.m_storage = 1;
            v594.m_verticesA[0] = v594.m_verticesA[1];
          }
          else
          {
            v258 = dimA.m_storage;
            if ( v255 & 2 )
              v258 = 1;
            dimA.m_storage = v258;
          }
          if ( v255 & 4 )
          {
            v29.m_quad = (__m128)v594.m_verticesBinA[1];
            dimB.m_storage = 1;
            v594.m_checkTriangleDots = (hkVector4f)v594.m_verticesBinA[1];
            v594.m_verticesBinA[0] = v594.m_verticesBinA[1];
          }
          else
          {
            v259 = dimB.m_storage;
            if ( v255 & 8 )
              v259 = 1;
            dimB.m_storage = v259;
          }
          v32 = (dimB.m_storage | 8 * dimA.m_storage) - 9;
          if ( v32 > 0x18 )
          {
LABEL_65:
            v260 = 1;
            goto LABEL_66;
          }
          continue;
        }
        if ( dimA.m_storage == 2 )
        {
          v20.m_quad = *(__m128 *)&v594.m_lastDimB.m_storage;
          dimA.m_storage = 1;
          v594.m_lastDimB = dimB;
        }
        else
        {
          v20.m_quad = *(__m128 *)&v594.m_lastDimB.m_storage;
          dimB.m_storage = 1;
          v594.m_lastDimB.m_storage = 1;
        }
        v260 = 0;
LABEL_66:
        v261 = _mm_mul_ps(v20.m_quad, v20.m_quad);
        v262 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v261, v261, 85), _mm_shuffle_ps(v261, v261, 0)),
                 _mm_shuffle_ps(v261, v261, 170));
        v263 = _mm_rsqrt_ps(v262);
        v685 = v262;
        v264 = _mm_andnot_ps(
                 _mm_cmpleps(v262, v19),
                 _mm_mul_ps(
                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v263, v262), v263)),
                   _mm_mul_ps(v263, *(__m128 *)_xmm)));
        v265 = _mm_mul_ps(_mm_sub_ps(v31, v29.m_quad), v20.m_quad);
        v20.m_quad = _mm_mul_ps(v20.m_quad, v264);
        *(hkVector4f *)&v594.m_lastDimB.m_storage = (hkVector4f)v20.m_quad;
        if ( !v260
          && (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v265, v265, 85))
                                   + COERCE_FLOAT(_mm_shuffle_ps(v265, v265, 0)))
                           + COERCE_FLOAT(_mm_shuffle_ps(v265, v265, 170)))
                   * v264.m128_f32[0]) >= v627.m128_f32[0]
          && v262.m128_f32[0] >= (float)((float)(v627.m128_f32[0] * v627.m128_f32[0])
                                       * (float)(v627.m128_f32[0] * v627.m128_f32[0])) )
        {
          v266 = aTb->m_rotation.m_col2.m_quad;
          v267 = aTb->m_rotation.m_col0.m_quad;
          v268 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
          v269 = _mm_xor_ps(v268, v20.m_quad);
          v602 = v269;
          v270 = _mm_xor_ps(v269, v268);
          v271 = _mm_unpacklo_ps(v267, aTb->m_rotation.m_col1.m_quad);
          v272 = _mm_shuffle_ps(_mm_unpackhi_ps(v267, aTb->m_rotation.m_col1.m_quad), v266, 228);
          v273 = _mm_movelh_ps(v271, v266);
          v274 = _mm_movehl_ps(v273, v271);
          v275 = shapeA->m_quad;
          v276 = _mm_shuffle_ps(v274, v266, 212);
          v277 = v269;
          v623 = v275;
          v624 = shapeA[1].m_quad;
          v278 = shapeA[2].m_quad;
          v593 = v275;
          v279 = _mm_mul_ps(v275, v269);
          v625 = v278;
          v280 = shapeA[3].m_quad;
          v603 = v278;
          v626 = v280;
          v281 = shapeB->m_quad;
          v595 = v624;
          v615 = v281;
          v282 = shapeB[1].m_quad;
          v606 = v280;
          v616 = v282;
          v283 = shapeB[2].m_quad;
          v612 = v281;
          v617 = v283;
          v284 = shapeB[3].m_quad;
          v646 = v269;
          v614 = v282;
          v611 = v283;
          v613 = v284;
          v618 = v284;
          v285 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v270, v270, 85), v276),
                     _mm_mul_ps(_mm_shuffle_ps(v270, v270, 0), v273)),
                   _mm_mul_ps(_mm_shuffle_ps(v270, v270, 170), v272));
          v598 = v285;
          v647 = v285;
          v286 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v279, v279, 85), _mm_shuffle_ps(v279, v279, 0)),
                   _mm_shuffle_ps(v279, v279, 170));
          v287 = _mm_mul_ps(v624, v277);
          v601 = v286;
          v619 = v286;
          v288 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v287, v287, 85), _mm_shuffle_ps(v287, v287, 0)),
                   _mm_shuffle_ps(v287, v287, 170));
          v596 = v288;
          v620 = v288;
          v289 = _mm_mul_ps(v603, v277);
          v290 = v610 - 4;
          v291 = v608 - 4;
          v292 = (__int64)&shapeA[4];
          v293 = &shapeB[4].m_quad;
          v294 = v608 - 4;
          v295 = _mm_shuffle_ps(v289, v289, 85);
          v296 = _mm_shuffle_ps(v289, v289, 0);
          v297 = _mm_shuffle_ps(v289, v289, 170);
          v298 = _mm_add_ps(v295, v296);
          if ( v610 - 4 < v608 - 4 )
            v294 = v610 - 4;
          v299 = _mm_add_ps(v298, v297);
          v300 = _mm_mul_ps(v280, v277);
          v599 = v299;
          v621 = v299;
          v301 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v300, v300, 85), _mm_shuffle_ps(v300, v300, 0)),
                   _mm_shuffle_ps(v300, v300, 170));
          v302 = _mm_mul_ps(v281, v285);
          v597 = v301;
          v622 = v301;
          v303 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v302, v302, 85), _mm_shuffle_ps(v302, v302, 0)),
                   _mm_shuffle_ps(v302, v302, 170));
          v304 = _mm_mul_ps(v282, v285);
          v605 = v303;
          v628 = v303;
          v305 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v304, v304, 85), _mm_shuffle_ps(v304, v304, 0)),
                   _mm_shuffle_ps(v304, v304, 170));
          v306 = _mm_mul_ps(v283, v285);
          v600 = v305;
          v629 = v305;
          v307 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v306, v306, 85), _mm_shuffle_ps(v306, v306, 0)),
                   _mm_shuffle_ps(v306, v306, 170));
          v308 = _mm_mul_ps(v284, v285);
          v604 = v307;
          v630 = v307;
          supportOuta = _mm_add_ps(
                          _mm_add_ps(_mm_shuffle_ps(v308, v308, 85), _mm_shuffle_ps(v308, v308, 0)),
                          _mm_shuffle_ps(v308, v308, 170));
          v631 = supportOuta;
          if ( v294 > 0 )
          {
            v309 = ((unsigned int)(v294 - 1) >> 2) + 1;
            v310 = v309;
            v309 *= 4;
            v290 -= v309;
            v291 -= v309;
            do
            {
              v311 = _mm_mul_ps(v277, *(__m128 *)v292);
              v666 = *(__m128 *)v292;
              v312 = *(__m128 *)(v292 + 16);
              v633 = v666;
              v667 = v312;
              v313 = *(__m128 *)(v292 + 32);
              v637 = v312;
              v314 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v311, v311, 85), _mm_shuffle_ps(v311, v311, 0)),
                       _mm_shuffle_ps(v311, v311, 170));
              v668 = v313;
              v315 = _mm_mul_ps(v602, v312);
              v316 = v598;
              v669 = *(__m128 *)(v292 + 48);
              v317 = *v293;
              v639 = v313;
              v318 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v315, v315, 85), _mm_shuffle_ps(v315, v315, 0)),
                       _mm_shuffle_ps(v315, v315, 170));
              v671 = v317;
              v319 = _mm_mul_ps(v602, v313);
              v672 = v293[1];
              v320 = v293[2];
              v641 = v669;
              v634 = v317;
              v321 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v319, v319, 85), _mm_shuffle_ps(v319, v319, 0)),
                       _mm_shuffle_ps(v319, v319, 170));
              v673 = v320;
              v322 = v293[3];
              v323 = _mm_mul_ps(v602, v669);
              v635 = v672;
              v636 = v320;
              v640 = v322;
              v674 = v322;
              v324 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v323, v323, 85), _mm_shuffle_ps(v323, v323, 0)),
                       _mm_shuffle_ps(v323, v323, 170));
              v632 = v314;
              v676 = v314;
              v325 = _mm_mul_ps(v598, v317);
              v677 = v318;
              v678 = v321;
              v679 = v324;
              v326 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v325, v325, 85), _mm_shuffle_ps(v325, v325, 0)),
                       _mm_shuffle_ps(v325, v325, 170));
              v638 = v326;
              v681 = v326;
              v327 = _mm_mul_ps(v598, v672);
              v328 = v600;
              v694 = supportOuta;
              v692 = v600;
              v688 = v599;
              v329 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v327, v327, 85), _mm_shuffle_ps(v327, v327, 0)),
                       _mm_shuffle_ps(v327, v327, 170));
              v330 = (__m128i)_mm_cmpltps(v599, v321);
              v689 = v597;
              v682 = v329;
              v331 = (__m128i)_mm_cmpltps(v597, v324);
              v332 = _mm_mul_ps(v598, v320);
              v333 = v604;
              v693 = v604;
              _mm_store_si128((__m128i *)&v698, v330);
              _mm_store_si128((__m128i *)&v699, v331);
              v334 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v332, v332, 85), _mm_shuffle_ps(v332, v332, 0)),
                       _mm_shuffle_ps(v332, v332, 170));
              v683 = v334;
              v335 = _mm_mul_ps(v316, v322);
              v686 = v601;
              v336 = (__m128i)_mm_cmpltps(v601, v314);
              _mm_store_si128((__m128i *)&v696, v336);
              v337 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v335, v335, 85), _mm_shuffle_ps(v335, v335, 0)),
                       _mm_shuffle_ps(v335, v335, 170));
              v687 = v596;
              v338 = (__m128i)_mm_cmpltps(v596, v318);
              v339 = (__m128i)_mm_cmpltps(v605, v326);
              v691 = v605;
              v340 = (__m128i)_mm_cmpltps(v328, v329);
              v341 = (__m128i)_mm_cmpltps(v333, v334);
              v342 = _mm_andnot_ps((__m128)v336, v601);
              v343 = _mm_and_ps((__m128)v336, v632);
              v344 = (__m128i)_mm_cmpltps(supportOuta, v337);
              v684 = v337;
              _mm_store_si128((__m128i *)&v697, v338);
              _mm_store_si128((__m128i *)&v701, v339);
              _mm_store_si128((__m128i *)&v702, v340);
              _mm_store_si128((__m128i *)&v703, v341);
              v601 = _mm_or_ps(v342, v343);
              v619 = v601;
              v345 = _mm_andnot_ps((__m128)v338, v596);
              _mm_store_si128((__m128i *)&v704, v344);
              v288 = _mm_or_ps(v345, _mm_and_ps((__m128)v338, v318));
              v596 = v288;
              v620 = v288;
              v599 = _mm_or_ps(_mm_andnot_ps((__m128)v330, v599), _mm_and_ps((__m128)v330, v321));
              v621 = v599;
              v597 = _mm_or_ps(_mm_and_ps((__m128)v331, v324), _mm_andnot_ps((__m128)v331, v597));
              v622 = v597;
              v593 = _mm_or_ps(_mm_andnot_ps((__m128)v336, v593), _mm_and_ps((__m128)v336, v633));
              v623 = v593;
              v595 = _mm_or_ps(_mm_andnot_ps((__m128)v338, v595), _mm_and_ps((__m128)v338, v637));
              v624 = v595;
              v603 = _mm_or_ps(_mm_andnot_ps((__m128)v330, v603), _mm_and_ps((__m128)v330, v639));
              v625 = v603;
              v606 = _mm_or_ps(_mm_andnot_ps((__m128)v331, v606), _mm_and_ps((__m128)v331, v641));
              v626 = v606;
              v605 = _mm_or_ps(_mm_and_ps((__m128)v339, v638), _mm_andnot_ps((__m128)v339, v605));
              v628 = v605;
              v600 = _mm_or_ps(_mm_and_ps((__m128)v340, v329), _mm_andnot_ps((__m128)v340, v600));
              v629 = v600;
              v614 = _mm_or_ps(_mm_andnot_ps((__m128)v340, v614), _mm_and_ps((__m128)v340, v635));
              v616 = v614;
              v604 = _mm_or_ps(_mm_and_ps((__m128)v341, v334), _mm_andnot_ps((__m128)v341, v604));
              v630 = v604;
              v612 = _mm_or_ps(_mm_andnot_ps((__m128)v339, v612), _mm_and_ps((__m128)v339, v634));
              v615 = v612;
              supportOuta = _mm_or_ps(_mm_and_ps((__m128)v344, v337), _mm_andnot_ps((__m128)v344, supportOuta));
              v631 = supportOuta;
              v277 = v602;
              v292 += 64i64;
              v293 += 4;
              v611 = _mm_or_ps(_mm_andnot_ps((__m128)v341, v611), _mm_and_ps((__m128)v341, v636));
              v617 = v611;
              v613 = _mm_or_ps(_mm_andnot_ps((__m128)v344, v613), _mm_and_ps((__m128)v344, v640));
              v618 = v613;
              --v310;
            }
            while ( v310 );
            v20.m_quad = *(__m128 *)&v594.m_lastDimB.m_storage;
            v31 = v593;
          }
          if ( v290 > 0 )
          {
            v346 = v601;
            v347 = v599;
            v348 = (__m128 *)(v292 + 32);
            v349 = ((unsigned int)(v290 - 1) >> 2) + 1;
            do
            {
              v350 = v348[-2];
              v351 = _mm_mul_ps(v277, v350);
              v706 = v348[-2];
              v352 = v348[-1];
              v353 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v351, v351, 85), _mm_shuffle_ps(v351, v351, 0)),
                       _mm_shuffle_ps(v351, v351, 170));
              v707 = v352;
              v354 = *v348;
              v355 = _mm_mul_ps(v277, v352);
              v708 = v354;
              v356 = v348[1];
              v716 = v346;
              v717 = v288;
              v357 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v355, v355, 85), _mm_shuffle_ps(v355, v355, 0)),
                       _mm_shuffle_ps(v355, v355, 170));
              v358 = (__m128i)_mm_cmpltps(v288, v357);
              v711 = v353;
              v712 = v357;
              v359 = _mm_mul_ps(v277, v354);
              v718 = v347;
              v709 = v356;
              _mm_store_si128((__m128i *)&v722, v358);
              v713 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v359, v359, 85), _mm_shuffle_ps(v359, v359, 0)),
                       _mm_shuffle_ps(v359, v359, 170));
              v360 = _mm_mul_ps(v277, v356);
              v361 = (__m128i)_mm_cmpltps(v347, v713);
              v362 = _mm_and_ps(v713, (__m128)v361);
              _mm_store_si128((__m128i *)&v723, v361);
              v363 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v360, v360, 85), _mm_shuffle_ps(v360, v360, 0)),
                       _mm_shuffle_ps(v360, v360, 170));
              v719 = v597;
              v364 = (__m128i)_mm_cmpltps(v346, v353);
              v365 = (__m128i)_mm_cmpltps(v597, v363);
              v714 = v363;
              _mm_store_si128((__m128i *)&v721, v364);
              _mm_store_si128((__m128i *)&v724, v365);
              v346 = _mm_or_ps(_mm_andnot_ps((__m128)v364, v346), _mm_and_ps(v353, (__m128)v364));
              v619 = v346;
              v288 = _mm_or_ps(_mm_andnot_ps((__m128)v358, v288), _mm_and_ps(v357, (__m128)v358));
              v620 = v288;
              v348 += 4;
              v366 = _mm_and_ps(v354, (__m128)v361);
              v597 = _mm_or_ps(_mm_andnot_ps((__m128)v365, v597), _mm_and_ps(v363, (__m128)v365));
              v622 = v597;
              v595 = _mm_or_ps(_mm_andnot_ps((__m128)v358, v595), _mm_and_ps(v352, (__m128)v358));
              v624 = v595;
              v347 = _mm_or_ps(_mm_andnot_ps((__m128)v361, v347), v362);
              v593 = _mm_or_ps(_mm_andnot_ps((__m128)v364, v593), _mm_and_ps(v350, (__m128)v364));
              v623 = v593;
              v367 = _mm_andnot_ps((__m128)v361, v603);
              v277 = v602;
              v621 = v347;
              v606 = _mm_or_ps(_mm_andnot_ps((__m128)v365, v606), _mm_and_ps(v356, (__m128)v365));
              v626 = v606;
              v603 = _mm_or_ps(v367, v366);
              v625 = v603;
              --v349;
            }
            while ( v349 );
            v599 = v347;
            v31 = v593;
            v601 = v346;
            v20.m_quad = *(__m128 *)&v594.m_lastDimB.m_storage;
            v596 = v288;
          }
          if ( v291 <= 0 )
          {
            v389 = v614;
            v390 = v613;
          }
          else
          {
            v368 = v605;
            v369 = v600;
            v370 = v604;
            v371 = v293 + 2;
            v372 = ((unsigned int)(v291 - 1) >> 2) + 1;
            do
            {
              v373 = v371[-2];
              v726 = v373;
              v374 = v371[-1];
              v375 = _mm_mul_ps(v598, v373);
              v727 = v374;
              v376 = *v371;
              v377 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v375, v375, 85), _mm_shuffle_ps(v375, v375, 0)),
                       _mm_shuffle_ps(v375, v375, 170));
              v728 = v376;
              v378 = v371[1];
              v379 = _mm_mul_ps(v598, v374);
              v736 = v368;
              v737 = v369;
              v731 = v377;
              v738 = v370;
              v732 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v379, v379, 85), _mm_shuffle_ps(v379, v379, 0)),
                       _mm_shuffle_ps(v379, v379, 170));
              v729 = v378;
              v380 = _mm_mul_ps(v598, v376);
              v381 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v380, v380, 85), _mm_shuffle_ps(v380, v380, 0)),
                       _mm_shuffle_ps(v380, v380, 170));
              v382 = _mm_mul_ps(v598, v378);
              v383 = (__m128i)_mm_cmpltps(v369, v732);
              v384 = (__m128i)_mm_cmpltps(v370, v381);
              v733 = v381;
              v385 = _mm_and_ps(v732, (__m128)v383);
              _mm_store_si128((__m128i *)&v742, v383);
              _mm_store_si128((__m128i *)&v743, v384);
              v386 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v382, v382, 85), _mm_shuffle_ps(v382, v382, 0)),
                       _mm_shuffle_ps(v382, v382, 170));
              v739 = supportOuta;
              v387 = (__m128i)_mm_cmpltps(v368, v377);
              v388 = (__m128i)_mm_cmpltps(supportOuta, v386);
              v734 = v386;
              _mm_store_si128((__m128i *)&v741, v387);
              _mm_store_si128((__m128i *)&v744, v388);
              v368 = _mm_or_ps(_mm_andnot_ps((__m128)v387, v368), _mm_and_ps(v377, (__m128)v387));
              v628 = v368;
              v369 = _mm_or_ps(_mm_andnot_ps((__m128)v383, v369), v385);
              v629 = v369;
              v371 += 4;
              supportOuta = _mm_or_ps(_mm_andnot_ps((__m128)v388, supportOuta), _mm_and_ps(v386, (__m128)v388));
              v631 = supportOuta;
              v612 = _mm_or_ps(_mm_and_ps(v373, (__m128)v387), _mm_andnot_ps((__m128)v387, v612));
              v615 = v612;
              v389 = _mm_or_ps(_mm_and_ps(v374, (__m128)v383), _mm_andnot_ps((__m128)v383, v614));
              v614 = v389;
              v616 = v389;
              v611 = _mm_or_ps(_mm_and_ps(v376, (__m128)v384), _mm_andnot_ps((__m128)v384, v611));
              v617 = v611;
              v390 = _mm_or_ps(_mm_and_ps(v378, (__m128)v388), _mm_andnot_ps((__m128)v388, v613));
              v370 = _mm_or_ps(_mm_andnot_ps((__m128)v384, v370), _mm_and_ps(v381, (__m128)v384));
              v613 = v390;
              v618 = v390;
              v630 = v370;
              --v372;
            }
            while ( v372 );
            v604 = v370;
            v288 = v596;
            v600 = v369;
            v31 = v593;
            v605 = v368;
            v20.m_quad = *(__m128 *)&v594.m_lastDimB.m_storage;
          }
          v544 = _mm_cmpltps(v599, v597);
          v545 = _mm_cmpltps(v604, supportOuta);
          v546 = _mm_cmpltps(v601, v288);
          v547 = _mm_cmpltps(v605, v600);
          v548 = _mm_cmpltps(
                   _mm_or_ps(_mm_andnot_ps(v544, v599), _mm_and_ps(v544, v597)),
                   _mm_or_ps(_mm_and_ps(v288, v546), _mm_andnot_ps(v546, v601)));
          v549 = _mm_cmpltps(
                   _mm_or_ps(_mm_and_ps(v545, supportOuta), _mm_andnot_ps(v545, v604)),
                   _mm_or_ps(_mm_and_ps(v547, v600), _mm_andnot_ps(v547, v605)));
          v550 = _mm_or_ps(
                   _mm_andnot_ps(v549, _mm_or_ps(_mm_and_ps(v390, v545), _mm_andnot_ps(v545, v611))),
                   _mm_and_ps(_mm_or_ps(_mm_and_ps(v389, v547), _mm_andnot_ps(v547, v612)), v549));
          v551 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v550, v550, 0), aTb->m_rotation.m_col0.m_quad),
                       _mm_mul_ps(_mm_shuffle_ps(v550, v550, 85), aTb->m_rotation.m_col1.m_quad)),
                     _mm_mul_ps(_mm_shuffle_ps(v550, v550, 170), aTb->m_rotation.m_col2.m_quad)),
                   aTb->m_translation.m_quad);
          v552 = _mm_or_ps(
                   _mm_andnot_ps(v548, _mm_or_ps(_mm_and_ps(v606, v544), _mm_andnot_ps(v544, v603))),
                   _mm_and_ps(_mm_or_ps(_mm_and_ps(v595, v546), _mm_andnot_ps(v546, v593)), v548));
          v553 = _mm_shuffle_ps(v551, _mm_unpackhi_ps(v551, v550), 196);
          v554 = _mm_mul_ps(_mm_sub_ps(v552, v553), v20.m_quad);
          v555 = _mm_mul_ps(_mm_sub_ps(v552, v31), v602);
          v556 = _mm_mul_ps(_mm_sub_ps(v553, v594.m_checkTriangleDots.m_quad), v20.m_quad);
          v557 = _mm_unpacklo_ps(v554, v555);
          v558 = _mm_movelh_ps(v557, v556);
          v559 = _mm_shuffle_ps(_mm_unpackhi_ps(v554, v555), v556, 228);
          v560 = _mm_mul_ps(_mm_sub_ps(v552, v594.m_verticesA[1].m_quad), v602);
          v561 = _mm_add_ps(v558, _mm_shuffle_ps(_mm_movehl_ps(v558, v557), v556, 212));
          v562 = _mm_mul_ps(_mm_sub_ps(v552, v594.m_verticesA[2].m_quad), v602);
          v563 = _mm_mul_ps(_mm_sub_ps(v553, v594.m_verticesBinA[1].m_quad), v20.m_quad);
          v564 = _mm_add_ps(v559, v561);
          v565 = _mm_shuffle_ps(v560, v562, 68);
          v566 = _mm_mul_ps(_mm_sub_ps(v553, v594.m_verticesBinA[2].m_quad), v20.m_quad);
          v567 = _mm_shuffle_ps(v563, v566, 68);
          v568 = _mm_shuffle_ps(v563, v566, 238);
          v569 = _mm_add_ps(_mm_shuffle_ps(v565, v567, 221), _mm_shuffle_ps(v565, v567, 136));
          v30 = v627;
          v570 = _mm_cmpltps(_mm_add_ps(_mm_shuffle_ps(_mm_shuffle_ps(v560, v562, 238), v568, 136), v569), v627);
          switch ( _mm_movemask_ps(
                     _mm_cmpltps(
                       _mm_movelh_ps(
                         _mm_unpacklo_ps(aTb[1].m_rotation.m_col1.m_quad, v627),
                         _mm_unpacklo_ps(v627, v627)),
                       v564)) & 7 )
          {
            case 1:
            case 3:
            case 5:
            case 7:
              v571 = vars0;
              v28 = 5;
              vars0->m_distance.m_real = _mm_shuffle_ps(v564, v564, 0);
              v571->m_normalInA = (hkVector4f)v20.m_quad;
              goto LABEL_174;
            case 2:
              goto LABEL_154;
            case 4:
              goto LABEL_156;
            case 6:
              if ( COERCE_FLOAT(_mm_shuffle_ps(v564, v564, 170)) > COERCE_FLOAT(_mm_shuffle_ps(v564, v564, 85)) )
              {
LABEL_156:
                if ( _mm_movemask_ps(v570) & hkcdGskBase::dimToMaskZ[dimB.m_storage] )
                {
LABEL_159:
                  v572 = vars0;
                  v573 = _mm_mul_ps(_mm_sub_ps(v31, v594.m_checkTriangleDots.m_quad), v20.m_quad);
                  vars0->m_normalInA = (hkVector4f)v20.m_quad;
                  v574 = _mm_add_ps(
                           _mm_add_ps(_mm_shuffle_ps(v573, v573, 85), _mm_shuffle_ps(v573, v573, 0)),
                           _mm_shuffle_ps(v573, v573, 170));
                  v572->m_distance.m_real = v574;
                  if ( dimA.m_storage == 1 )
                  {
                    v572->m_pointAinA = (hkVector4f)v594.m_verticesA[0];
                  }
                  else if ( dimB.m_storage == 1 )
                  {
                    v572->m_pointAinA.m_quad = _mm_add_ps(_mm_mul_ps(v574, v20.m_quad), v594.m_verticesBinA[0].m_quad);
                  }
                  else
                  {
                    v572->m_pointAinA = v594.m_closestPointOnEdgeA;
                  }
                  goto LABEL_174;
                }
                v19 = 0i64;
                v594.m_verticesBinA[dimB.m_storage++].m_quad = v553;
                v29.m_quad = (__m128)v594.m_verticesBinA[0];
              }
              else
              {
LABEL_154:
                if ( _mm_movemask_ps(v570) & hkcdGskBase::dimToMaskY[dimA.m_storage] )
                  goto LABEL_159;
                v594.m_verticesA[dimA.m_storage++].m_quad = v552;
                v29.m_quad = (__m128)v594.m_verticesBinA[0];
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
          v575 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
          v576 = v575[1];
          if ( v576 < v575[3] )
          {
            *(_QWORD *)v576 = "TtPenetration";
            v577 = __rdtsc();
            *(_DWORD *)(v576 + 8) = v577;
            v575[1] = v576 + 16;
          }
          v578 = hkcdGskBase::handlePenetration(
                   &v594,
                   &shapeInterface,
                   &shapeA,
                   &shapeB,
                   aTb,
                   &dimA,
                   &dimB,
                   vars0,
                   &v649);
          v579 = (_QWORD *)v575[1];
          v28 = v578;
          if ( (unsigned __int64)v579 < v575[3] )
          {
            *v579 = "Et";
            v580 = __rdtsc();
            v581 = (signed __int64)(v579 + 2);
            *(_DWORD *)(v581 - 8) = v580;
            v575[1] = v581;
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
        v582 = dimA.m_storage;
        v583 = dimB.m_storage;
        v584 = v594.m_verticesBinA[1].m_quad.m128_i8[12];
        v585 = v594.m_verticesA[0].m_quad.m128_i8[12];
        v586 = v594.m_verticesA[1].m_quad.m128_i8[12];
        v587 = v594.m_verticesA[2].m_quad.m128_i8[12];
        v588 = v594.m_verticesBinA[0].m_quad.m128_i8[12];
        v4[(LOBYTE(dimA.m_storage) - 2) & 3] = v594.m_verticesBinA[2].m_quad.m128_i8[12];
        *v4 = v585;
        v4[1] = v586;
        v4[2] = v587;
        v4[v582] = v588;
        v4[v582 + 1] = v584;
        result = v28;
        v4[4] = v583 | 4 * (v28 | 16 * v582);
        return result;
      case 0x18u:
        v33 = g_vectorfConstants[0];
        v411 = v29.m_quad;
        v412 = (__m128 *)v594.m_verticesA;
LABEL_97:
        v413 = v412[1];
        v414 = v412[2];
        v415 = _mm_sub_ps(v412[1], *v412);
        v416 = _mm_sub_ps(*v412, v414);
        v417 = _mm_sub_ps(v412[3], *v412);
        v418 = _mm_sub_ps(v412[2], v413);
        v419 = _mm_sub_ps(v412[3], v413);
        v420 = _mm_sub_ps(v412[3], v414);
        v421 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v419, v419, 201), v418),
                 _mm_mul_ps(_mm_shuffle_ps(v418, v418, 201), v419));
        v422 = _mm_shuffle_ps(v421, v421, 201);
        v423 = _mm_mul_ps(_mm_sub_ps(v411, v412[3]), v33);
        v424 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v420, v420, 201), v416),
                 _mm_mul_ps(_mm_shuffle_ps(v416, v416, 201), v420));
        v425 = _mm_shuffle_ps(v424, v424, 201);
        v426 = _mm_mul_ps(v423, v425);
        v427 = _mm_mul_ps(v425, v425);
        v428 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v417, v417, 201), v415),
                 _mm_mul_ps(_mm_shuffle_ps(v415, v415, 201), v417));
        v429 = _mm_mul_ps(v423, v422);
        v430 = _mm_mul_ps(v422, v422);
        v431 = _mm_shuffle_ps(v428, v428, 201);
        v432 = _mm_unpacklo_ps(v429, v426);
        v433 = _mm_unpackhi_ps(v429, v426);
        v434 = _mm_mul_ps(v423, v431);
        v435 = _mm_movelh_ps(v432, v434);
        v436 = _mm_shuffle_ps(_mm_movehl_ps(v435, v432), v434, 212);
        v437 = _mm_unpacklo_ps(v430, v427);
        v438 = _mm_mul_ps(v431, v431);
        v439 = (__m128i)_mm_add_ps(_mm_shuffle_ps(v433, v434, 228), _mm_add_ps(v435, v436));
        v440 = _mm_movelh_ps(v437, v438);
        v441 = _mm_add_ps(
                 _mm_shuffle_ps(_mm_unpackhi_ps(v430, v427), v438, 228),
                 _mm_add_ps(v440, _mm_shuffle_ps(_mm_movehl_ps(v440, v437), v438, 212)));
        v442 = _mm_cmpeqps(v19, v441);
        v443 = _mm_rcp_ps(v441);
        v670 = v441;
        v710 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v441, v443)), v443);
        LODWORD(v751) = 897988542;
        v444 = _mm_or_ps(
                 _mm_andnot_ps(
                   v442,
                   _mm_mul_ps(_mm_mul_ps((__m128)_mm_srli_epi32(_mm_slli_epi32(v439, 1u), 1u), (__m128)v439), v710)),
                 _mm_and_ps(v442, (__m128)xmmword_141A712A0));
        v445 = _mm_max_ps(
                 _mm_shuffle_ps(v444, v444, 170),
                 _mm_max_ps(_mm_shuffle_ps(v444, v444, 85), _mm_shuffle_ps(v444, v444, 0)));
        v446 = (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                                      _mm_and_ps(
                                                                        _mm_cmpleps(v445, v444),
                                                                        (__m128)xmmword_141C1F4F0))];
        if ( v445.m128_f32[0] < COERCE_FLOAT(_mm_shuffle_ps((__m128)0x358637BEu, (__m128)0x358637BEu, 0)) )
          goto LABEL_65;
        v747 = 1066192077;
        v447 = _mm_or_ps(
                 _mm_and_ps((__m128)`hkVector4f::getComponent'::`2'::indexToMask[v446], (__m128)xmmword_141A712F0),
                 _mm_andnot_ps((__m128)`hkVector4f::getComponent'::`2'::indexToMask[v446], v444));
        if ( v445.m128_f32[0] <= (float)(fmax(
                                           COERCE_FLOAT(_mm_shuffle_ps(v447, v447, 170)),
                                           fmax(
                                             COERCE_FLOAT(_mm_shuffle_ps(v447, v447, 85)),
                                             COERCE_FLOAT(_mm_shuffle_ps(v447, v447, 0))))
                                       * COERCE_FLOAT(_mm_shuffle_ps((__m128)0x3F8CCCCDu, (__m128)0x3F8CCCCDu, 0))) )
        {
          v448 = 2;
          v449 = 1;
          v450 = 4;
          v451 = 16i64;
          v452 = 32i64;
          v453 = 0i64;
          v454 = 3i64;
          v455 = _mm_movemask_ps(_mm_cmpleps(v19, (__m128)v439));
          do
          {
            if ( v449 & v455 && v448 & v455 )
            {
              v456 = *(__m128 *)((char *)v412 + v452);
              v457 = _mm_sub_ps(v412[v453], v456);
              v458 = _mm_sub_ps(v412[3], v456);
              v459 = _mm_sub_ps(v411, v456);
              v460 = _mm_mul_ps(v458, v457);
              v461 = _mm_sub_ps(*(__m128 *)((char *)v412 + v451), v456);
              v462 = _mm_mul_ps(v459, v457);
              v463 = _mm_mul_ps(v458, v461);
              v464 = _mm_mul_ps(v459, v461);
              if ( (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v462, v462, 85))
                                         + COERCE_FLOAT(_mm_shuffle_ps(v462, v462, 0)))
                                 + COERCE_FLOAT(_mm_shuffle_ps(v462, v462, 170)))
                         * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v463, v463, 85))
                                         + COERCE_FLOAT(_mm_shuffle_ps(v463, v463, 0)))
                                 + COERCE_FLOAT(_mm_shuffle_ps(v463, v463, 170)))) >= (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v460, v460, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v460, v460, 0))) + COERCE_FLOAT(_mm_shuffle_ps(v460, v460, 170)))
                                                                                            * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v464, v464, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v464, v464, 0))) + COERCE_FLOAT(_mm_shuffle_ps(v464, v464, 170)))) )
                v448 = v449;
              v455 &= ~v448;
            }
            v448 = v450;
            v451 = v452;
            v450 = v449;
            v449 = __ROL4__(v449, 1);
            v452 = v453 * 16;
            ++v453;
            --v454;
          }
          while ( v454 );
          if ( v455 & 7 )
            v446 = (unsigned __int8)hkVector4Comparison_maskToFirstIndex[v455];
          else
            v446 = -1;
        }
        if ( v446 < 0 )
          goto LABEL_65;
        v412[v446] = v412[3];
        v29.m_quad = (__m128)v594.m_verticesBinA[0];
        v31 = v594.m_verticesA[0].m_quad;
        v594.m_checkTriangleDots = (hkVector4f)v594.m_verticesBinA[0];
        if ( dimA.m_storage == 4 )
        {
          dimA.m_storage = 3;
LABEL_112:
          v465 = _mm_sub_ps(v31, v594.m_verticesA[2].m_quad);
          v466 = _mm_shuffle_ps(v465, v465, 201);
          v467 = _mm_sub_ps(v29.m_quad, v594.m_verticesA[1].m_quad);
          v468 = _mm_sub_ps(v594.m_verticesA[2].m_quad, v594.m_verticesA[1].m_quad);
          v469 = _mm_sub_ps(v29.m_quad, v594.m_verticesA[2].m_quad);
          v470 = _mm_shuffle_ps(v468, v468, 201);
          v471 = _mm_sub_ps(v594.m_verticesA[1].m_quad, v31);
          v472 = _mm_sub_ps(v29.m_quad, v31);
          v473 = _mm_sub_ps(_mm_mul_ps(v466, v468), _mm_mul_ps(v470, v465));
          v474 = _mm_shuffle_ps(v473, v473, 201);
          *(__m128 *)&v594.m_lastDimB.m_storage = v474;
          v475 = _mm_sub_ps(_mm_mul_ps(v470, v467), _mm_mul_ps(_mm_shuffle_ps(v467, v467, 201), v468));
          v476 = _mm_sub_ps(_mm_mul_ps(v466, v469), _mm_mul_ps(_mm_shuffle_ps(v469, v469, 201), v465));
          v477 = _mm_mul_ps(_mm_shuffle_ps(v475, v475, 201), v474);
          v478 = _mm_mul_ps(_mm_shuffle_ps(v476, v476, 201), v474);
          v479 = _mm_sub_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v471, v471, 201), v472),
                   _mm_mul_ps(_mm_shuffle_ps(v472, v472, 201), v471));
          v480 = _mm_unpacklo_ps(v477, v478);
          v481 = _mm_mul_ps(_mm_shuffle_ps(v479, v479, 201), v474);
          v482 = _mm_movelh_ps(v480, v481);
          v483.m_quad = _mm_add_ps(
                          _mm_shuffle_ps(_mm_unpackhi_ps(v477, v478), v481, 228),
                          _mm_add_ps(v482, _mm_shuffle_ps(_mm_movehl_ps(v482, v480), v481, 212)));
          v484 = _mm_movemask_ps(_mm_cmpltps(v483.m_quad, v19)) & 7;
          if ( v484 == 7 )
          {
            v485 = _mm_mul_ps(_mm_sub_ps(v31, v29.m_quad), v474);
            if ( _mm_movemask_ps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v485, v485, 85), _mm_shuffle_ps(v485, v485, 0)),
                     _mm_shuffle_ps(v485, v485, 170))) )
            {
              v594.m_verticesA[0] = v594.m_verticesA[1];
              v486.m_quad = v31;
              v31 = v594.m_verticesA[1].m_quad;
              v594.m_verticesA[1] = (hkcdVertex)v486.m_quad;
              *(__m128 *)&v594.m_lastDimB.m_storage = _mm_xor_ps(
                                                        v474,
                                                        (__m128)_mm_shuffle_epi32(
                                                                  _mm_insert_epi16((__m128i)0i64, 0x8000u, 1),
                                                                  0));
              v483.m_quad = _mm_shuffle_ps(v483.m_quad, v483.m_quad, 225);
            }
          }
          v594.m_checkTriangleDots = (hkVector4f)v483.m_quad;
          if ( v484 == 7 )
            goto LABEL_150;
          v487 = hkcdGskBase::maskToIndex[v484];
          if ( (signed int)v487 < 0 )
          {
            v488 = v487 + 8;
            if ( v488 < 3 )
            {
              v594.m_verticesA[v488] = v594.m_verticesA[2];
              goto LABEL_135;
            }
LABEL_145:
            dimA.m_storage = 1;
            dimB.m_storage = 1;
LABEL_146:
            v392 = _mm_sub_ps(v31, v29.m_quad);
            goto LABEL_149;
          }
          v513 = *(char *)(v487 + 5398197060i64);
          v514 = v487;
          v515 = *(char *)(v487 + 5398197062i64);
          v516 = v594.m_verticesA[v514].m_quad;
          v517 = _mm_sub_ps(v29.m_quad, v516);
          v518 = _mm_sub_ps(v594.m_verticesA[v515].m_quad, v516);
          v519 = _mm_mul_ps(_mm_sub_ps(v594.m_verticesA[v513].m_quad, v516), v517);
          if ( !_mm_movemask_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v519, v519, 85), _mm_shuffle_ps(v519, v519, 0)),
                    _mm_shuffle_ps(v519, v519, 170))) )
          {
            v594.m_verticesA[v515] = v594.m_verticesA[2];
            goto LABEL_135;
          }
          v520 = _mm_mul_ps(v518, v517);
          v594.m_verticesA[v513] = v594.m_verticesA[2];
          if ( !_mm_movemask_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v520, v520, 85), _mm_shuffle_ps(v520, v520, 0)),
                    _mm_shuffle_ps(v520, v520, 170))) )
          {
LABEL_135:
            v29.m_quad = (__m128)v594.m_verticesBinA[0];
            v31 = v594.m_verticesA[0].m_quad;
            v594.m_checkTriangleDots = (hkVector4f)v594.m_verticesBinA[0];
            goto LABEL_136;
          }
          dimA.m_storage = 1;
          if ( (_DWORD)v515 == 2 )
            LODWORD(v515) = v513;
          v594.m_verticesA[(signed int)v515] = v594.m_verticesA[1];
LABEL_133:
          v31 = v594.m_verticesA[0].m_quad;
          v29.m_quad = (__m128)v594.m_verticesBinA[0];
          v594.m_checkTriangleDots = (hkVector4f)v594.m_verticesBinA[0];
          v392 = _mm_sub_ps(v594.m_verticesA[0].m_quad, v594.m_verticesBinA[0].m_quad);
          goto LABEL_149;
        }
        dimB.m_storage = 3;
LABEL_120:
        v489 = _mm_sub_ps(v29.m_quad, v594.m_verticesBinA[2].m_quad);
        v490 = _mm_sub_ps(v594.m_verticesBinA[2].m_quad, v594.m_verticesBinA[1].m_quad);
        v491 = _mm_shuffle_ps(v489, v489, 201);
        v492 = _mm_sub_ps(v31, v594.m_verticesBinA[1].m_quad);
        v493 = _mm_shuffle_ps(v490, v490, 201);
        v494 = _mm_sub_ps(v31, v594.m_verticesBinA[2].m_quad);
        v495 = _mm_sub_ps(v594.m_verticesBinA[1].m_quad, v29.m_quad);
        v496 = _mm_sub_ps(v31, v29.m_quad);
        v497 = _mm_sub_ps(_mm_mul_ps(v490, v491), _mm_mul_ps(v489, v493));
        v498 = _mm_shuffle_ps(v497, v497, 201);
        *(__m128 *)&v594.m_lastDimB.m_storage = v498;
        v499 = _mm_sub_ps(_mm_mul_ps(v492, v493), _mm_mul_ps(_mm_shuffle_ps(v492, v492, 201), v490));
        v500 = _mm_mul_ps(_mm_shuffle_ps(v499, v499, 201), v498);
        v501 = _mm_sub_ps(_mm_mul_ps(v494, v491), _mm_mul_ps(_mm_shuffle_ps(v494, v494, 201), v489));
        v502 = _mm_mul_ps(_mm_shuffle_ps(v501, v501, 201), v498);
        v503 = _mm_unpacklo_ps(v500, v502);
        v504 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v495, v495, 201), v496),
                 _mm_mul_ps(_mm_shuffle_ps(v496, v496, 201), v495));
        v505 = _mm_mul_ps(_mm_shuffle_ps(v504, v504, 201), v498);
        v506 = _mm_movelh_ps(v503, v505);
        v507.m_quad = _mm_add_ps(
                        _mm_shuffle_ps(_mm_unpackhi_ps(v500, v502), v505, 228),
                        _mm_add_ps(v506, _mm_shuffle_ps(_mm_movehl_ps(v506, v503), v505, 212)));
        v508 = _mm_movemask_ps(_mm_cmpltps(v507.m_quad, v19)) & 7;
        if ( v508 == 7 )
        {
          v509 = _mm_mul_ps(v498, v496);
          if ( _mm_movemask_ps(
                 _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v509, v509, 85), _mm_shuffle_ps(v509, v509, 0)),
                   _mm_shuffle_ps(v509, v509, 170))) )
          {
            v594.m_checkTriangleDots = (hkVector4f)v594.m_verticesBinA[1];
            v594.m_verticesBinA[0] = v594.m_verticesBinA[1];
            v510.m_quad = v29.m_quad;
            v29.m_quad = (__m128)v594.m_verticesBinA[1];
            v594.m_verticesBinA[1] = (hkcdVertex)v510.m_quad;
            *(__m128 *)&v594.m_lastDimB.m_storage = _mm_xor_ps(
                                                      v498,
                                                      (__m128)_mm_shuffle_epi32(
                                                                _mm_insert_epi16((__m128i)0i64, 0x8000u, 1),
                                                                0));
            v507.m_quad = _mm_shuffle_ps(v507.m_quad, v507.m_quad, 225);
          }
        }
        v594.m_checkTriangleDots = (hkVector4f)v507.m_quad;
        if ( v508 == 7 )
          goto LABEL_150;
        v511 = hkcdGskBase::maskToIndex[v508];
        if ( (signed int)v511 >= 0 )
        {
          v535 = *(char *)(v511 + 5398197060i64);
          v536 = v511;
          v537 = *(char *)(v511 + 5398197062i64);
          v538 = v594.m_verticesBinA[v536].m_quad;
          v539 = _mm_sub_ps(v31, v538);
          v540 = _mm_sub_ps(v594.m_verticesBinA[v537].m_quad, v538);
          v541 = _mm_mul_ps(_mm_sub_ps(v594.m_verticesBinA[v535].m_quad, v538), v539);
          if ( _mm_movemask_ps(
                 _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v541, v541, 85), _mm_shuffle_ps(v541, v541, 0)),
                   _mm_shuffle_ps(v541, v541, 170))) )
          {
            v542 = _mm_mul_ps(v540, v539);
            v594.m_verticesBinA[v535] = v594.m_verticesBinA[2];
            if ( _mm_movemask_ps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v542, v542, 85), _mm_shuffle_ps(v542, v542, 0)),
                     _mm_shuffle_ps(v542, v542, 170))) )
            {
              dimB.m_storage = 1;
              if ( (_DWORD)v537 == 2 )
                LODWORD(v537) = v535;
              v594.m_verticesBinA[(signed int)v537] = v594.m_verticesBinA[1];
              goto LABEL_133;
            }
          }
          else
          {
            v594.m_verticesBinA[v537] = v594.m_verticesBinA[2];
          }
        }
        else
        {
          v512 = v511 + 8;
          if ( v512 >= 3 )
            goto LABEL_145;
          v594.m_verticesBinA[v512] = v594.m_verticesBinA[2];
        }
        v29.m_quad = (__m128)v594.m_verticesBinA[0];
        v31 = v594.m_verticesA[0].m_quad;
        v594.m_checkTriangleDots = (hkVector4f)v594.m_verticesBinA[0];
        goto LABEL_90;
      default:
        goto LABEL_65;
    }
  }
}   default:
        goto LABEL_65;
    }
  }
})&v594.m_lastDimB.m_storage = _mm_xor_ps(
                                                      v498,
                                                      (__m128)_mm_shuffle_epi32(
                                                                _mm_insert_epi16((__m128i)0i64, 0x8000u, 1),
                                                                0));
            v507.m_quad = _mm_shuffle_ps(v507.m_quad, v507.m_quad, 225);
          }
        }
        v594.m_checkTriangleDots = (hkVector4f)v507.m_quad;
        if ( v508 == 7 )
      

// File Line: 87
// RVA: 0x1310A10
__int64 __fastcall hkcdGsk::getClosestPoint(const void *__formal, hkcdVertex *vertsA, int numVertsA, const void *a4)
{
  hkcdVertex *v4; // r11
  hkcdVertex *v5; // r9
  char *v6; // r10
  int v7; // ecx
  int v8; // eax
  unsigned int v9; // ebx
  __int64 v10; // rdx
  hkcdVertex *v11; // r8
  __m128 *v12; // r11
  int v13; // ebx
  char *v14; // r10
  __m128 *v15; // r9
  signed __int64 v16; // r8
  hkTransformf *aTb; // rsi
  __m128 v18; // xmm10
  __m128 v19; // xmm13
  __int64 v20; // rcx
  __m128 v21; // xmm3
  signed __int64 v22; // rax
  __m128 v23; // xmm4
  __m128 v24; // xmm5
  __m128 v25; // xmm6
  __m128 v26; // xmm1
  unsigned int v27; // er14
  hkVector4f v28; // xmm12
  __m128 v29; // xmm2
  __m128 v30; // xmm14
  unsigned int v31; // eax
  __m128 v32; // xmm11
  __m128 *v33; // rdx
  __m128 *v34; // rcx
  __m128 v35; // xmm5
  __m128 v36; // xmm1
  __m128 v37; // xmm6
  __m128 v38; // xmm7
  __m128 v39; // xmm1
  __m128 v40; // xmm3
  __m128 v41; // xmm2
  __m128 v42; // xmm2
  __m128 v43; // xmm1
  __m128 v44; // xmm4
  __m128 v45; // xmm1
  __m128 v46; // xmm2
  __m128 v47; // xmm1
  __m128 v48; // xmm3
  __m128 v49; // xmm2
  __m128 v50; // xmm1
  __m128 v51; // xmm2
  __m128 v52; // xmm0
  __m128 v53; // xmm7
  __m128 v54; // xmm3
  __m128 v55; // xmm6
  __m128 v56; // xmm5
  __m128 v57; // xmm5
  __m128 v58; // xmm1
  __m128 v59; // xmm4
  __m128 v60; // xmm0
  __m128 v61; // xmm2
  __m128 v62; // xmm7
  __m128 v63; // xmm1
  __m128 v64; // xmm4
  __m128 v65; // xmm1
  __m128 v66; // xmm7
  __m128 v67; // xmm2
  signed int v68; // ecx
  __m128 v69; // xmm1
  __m128 v70; // xmm3
  __m128 v71; // xmm15
  __m128 v72; // xmm1
  __m128 v73; // xmm6
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
  __m128 v92; // xmm9
  int v93; // er8
  __m128 v94; // xmm14
  __m128 v95; // xmm1
  __m128 v96; // xmm2
  __m128 v97; // xmm15
  __m128 v98; // xmm1
  __m128 v99; // xmm9
  __m128 v100; // xmm1
  __m128 v101; // xmm2
  __m128 v102; // xmm8
  __m128 v103; // xmm12
  __m128 v104; // xmm1
  __m128 v105; // xmm7
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
  __m128 v120; // xmm3
  __m128 v121; // xmm5
  __m128 v122; // xmm0
  __m128 v123; // xmm2
  __m128 v124; // xmm1
  __m128 v125; // xmm2
  __m128 v126; // xmm11
  __m128 v127; // xmm9
  __m128 v128; // xmm1
  __m128 v129; // xmm5
  __m128 v130; // xmm1
  __m128 v131; // xmm8
  __m128 v132; // xmm1
  __m128 v133; // xmm7
  __m128 v134; // xmm5
  __m128 v135; // xmm1
  __m128 v136; // xmm3
  __m128 v137; // xmm1
  __m128 v138; // xmm4
  __m128 v139; // xmm1
  __m128 v140; // xmm2
  __m128 v141; // xmm6
  __m128 v142; // xmm1
  __m128 v143; // xmm3
  __m128 v144; // xmm1
  __m128 v145; // xmm5
  __m128 v146; // xmm4
  __m128 v147; // xmm2
  __m128 v148; // xmm1
  __m128 v149; // xmm3
  __m128 v150; // xmm3
  __m128 v151; // xmm2
  __m128 v152; // xmm8
  __m128 v153; // xmm15
  __m128 v154; // xmm11
  __m128 v155; // xmm1
  __m128 v156; // xmm3
  __m128 v157; // xmm1
  __m128 v158; // xmm2
  __m128 v159; // xmm0
  __m128 v160; // xmm0
  __m128 v161; // xmm1
  __m128 v162; // xmm3
  __m128 v163; // xmm6
  __m128 v164; // xmm6
  __m128 v165; // xmm7
  __m128 v166; // xmm4
  __m128 v167; // xmm5
  __m128 v168; // xmm1
  __m128 v169; // xmm3
  __m128 v170; // xmm0
  __m128 v171; // xmm2
  __m128 v172; // xmm7
  __m128 v173; // xmm1
  __m128 v174; // xmm3
  __m128 v175; // xmm1
  __m128 v176; // xmm7
  __m128 v177; // xmm2
  __m128 v178; // xmm1
  __m128 v179; // xmm3
  __m128 v180; // xmm6
  __m128 v181; // xmm9
  __m128 v182; // xmm5
  __m128 v183; // xmm10
  __m128 v184; // xmm7
  __m128 v185; // xmm15
  __m128 v186; // xmm10
  __m128 v187; // xmm4
  __m128 v188; // xmm7
  __m128 v189; // xmm2
  __m128 v190; // xmm8
  __m128 v191; // xmm8
  __m128 v192; // xmm10
  __m128 v193; // xmm7
  __m128 v194; // xmm10
  __m128 v195; // xmm7
  __m128 v196; // xmm1
  __m128 v197; // xmm9
  __m128 v198; // xmm9
  __m128 v199; // xmm2
  __m128 v200; // xmm10
  int v201; // eax
  float v202; // xmm1_4
  float v203; // xmm11_4
  float v204; // xmm1_4
  float v205; // xmm11_4
  int v206; // ecx
  __m128 v207; // xmm15
  __m128 v208; // xmm7
  __m128 v209; // xmm5
  __m128 v210; // xmm2
  __m128 v211; // xmm4
  __m128 v212; // xmm13
  __m128 v213; // xmm4
  __m128 v214; // xmm4
  __m128 v215; // xmm2
  __m128 v216; // xmm0
  __m128 v217; // xmm9
  __m128 v218; // xmm2
  __m128 v219; // xmm1
  __m128 v220; // xmm6
  __m128 v221; // xmm3
  __m128 v222; // xmm2
  __m128 v223; // xmm6
  int v224; // ecx
  int v225; // ecx
  int v226; // ecx
  int v227; // ecx
  __m128 v228; // xmm1
  __m128 v229; // xmm2
  __m128 v230; // xmm11
  __m128 v231; // xmm1
  __m128 v232; // xmm2
  __m128 v233; // xmm5
  __m128 v234; // xmm10
  __m128 v235; // xmm1
  __m128 v236; // xmm9
  __m128 v237; // xmm6
  __m128 v238; // xmm1
  __m128 v239; // xmm3
  __m128 v240; // xmm1
  __m128 v241; // xmm5
  __m128 v242; // xmm1
  __m128 v243; // xmm7
  __m128 v244; // xmm0
  __m128 v245; // xmm2
  __m128 v246; // xmm1
  __m128 v247; // xmm2
  __m128 v248; // xmm8
  __m128 v249; // xmm1
  __m128 v250; // xmm0
  __m128 v251; // xmm3
  __m128 v252; // xmm2
  __m128 v253; // xmm0
  __m128 v254; // xmm1
  int v255; // ecx
  float v256; // xmm1_4
  float v257; // xmm11_4
  signed int v258; // eax
  signed int v259; // eax
  signed int v260; // eax
  __m128 v261; // xmm1
  __m128 v262; // xmm3
  __m128 v263; // xmm2
  __m128 v264; // xmm6
  __m128 v265; // xmm2
  __m128 v266; // xmm3
  __m128 v267; // xmm4
  __m128 v268; // xmm12
  __m128 v269; // xmm1
  __m128 v270; // xmm15
  __m128 v271; // xmm5
  __m128 v272; // xmm1
  __m128 v273; // xmm4
  __m128 v274; // xmm1
  __m128 v275; // xmm4
  __m128 v276; // xmm2
  __m128 v277; // xmm0
  __m128 v278; // xmm1
  __m128 v279; // xmm8
  __m128 v280; // xmm10
  __m128 v281; // xmm11
  __m128 v282; // xmm7
  __m128 v283; // xmm3
  __m128 v284; // xmm1
  __m128 v285; // xmm8
  __m128 v286; // xmm9
  __m128 v287; // xmm1
  __m128 v288; // xmm1
  int v289; // er8
  int v290; // er9
  __int64 v291; // rcx
  __m128 v292; // xmm1
  __m128 *v293; // rdx
  int v294; // eax
  __m128 v295; // xmm0
  __m128 v296; // xmm12
  __m128 v297; // xmm1
  __m128 v298; // xmm12
  __m128 v299; // xmm1
  __m128 v300; // xmm6
  __m128 v301; // xmm1
  __m128 v302; // xmm15
  __m128 v303; // xmm1
  __m128 v304; // xmm2
  __m128 v305; // xmm1
  __m128 v306; // xmm2
  __m128 v307; // xmm1
  unsigned int v308; // eax
  __int64 v309; // r10
  __m128 v310; // xmm1
  __m128 v311; // xmm2
  __m128 v312; // xmm4
  __m128 v313; // xmm3
  __m128 v314; // xmm1
  __m128 v315; // xmm6
  __m128 v316; // xmm14
  __m128 v317; // xmm1
  __m128 v318; // xmm9
  __m128 v319; // xmm12
  __m128 v320; // xmm11
  __m128 v321; // xmm1
  __m128 v322; // xmm10
  __m128 v323; // xmm1
  __m128 v324; // xmm1
  __m128 v325; // xmm15
  __m128 v326; // xmm1
  __m128 v327; // xmm13
  __m128 v328; // xmm1
  __m128i v329; // xmm8
  __m128i v330; // xmm2
  __m128i v331; // xmm3
  __m128 v332; // xmm11
  __m128i v333; // xmm4
  __m128i v334; // xmm5
  __m128i v335; // xmm9
  __m128i v336; // xmm6
  __m128 v337; // xmm0
  __m128 v338; // xmm1
  __m128i v339; // xmm7
  __m128 v340; // xmm0
  __m128 v341; // xmm13
  __m128 v342; // xmm14
  __m128 v343; // xmm15
  __m128 *v344; // rcx
  __int64 v345; // r8
  __m128 v346; // xmm9
  __m128 v347; // xmm1
  __m128 v348; // xmm10
  __m128 v349; // xmm8
  __m128 v350; // xmm11
  __m128 v351; // xmm1
  __m128 v352; // xmm12
  __m128 v353; // xmm7
  __m128i v354; // xmm2
  __m128 v355; // xmm1
  __m128 v356; // xmm1
  __m128i v357; // xmm3
  __m128 v358; // xmm6
  __m128 v359; // xmm4
  __m128i v360; // xmm1
  __m128i v361; // xmm5
  __m128 v362; // xmm11
  __m128 v363; // xmm0
  __m128 v364; // xmm13
  __m128 v365; // xmm14
  __m128 *v366; // rcx
  __int64 v367; // rdx
  __m128 v368; // xmm9
  __m128 v369; // xmm10
  __m128 v370; // xmm1
  __m128 v371; // xmm11
  __m128 v372; // xmm8
  __m128 v373; // xmm12
  __m128 v374; // xmm1
  __m128 v375; // xmm1
  __m128 v376; // xmm6
  __m128 v377; // xmm1
  __m128i v378; // xmm2
  __m128i v379; // xmm4
  __m128 v380; // xmm7
  __m128 v381; // xmm3
  __m128i v382; // xmm1
  __m128i v383; // xmm5
  __m128 v384; // xmm9
  __m128 v385; // xmm11
  __m128 v386; // xmm15
  __m128 v387; // xmm8
  __m128 v388; // xmm6
  __m128 v389; // xmm9
  __m128 v390; // xmm5
  __m128 v391; // xmm1
  __m128 v392; // xmm4
  __m128 v393; // xmm1
  __m128 v394; // xmm2
  int v395; // eax
  __m128 v396; // xmm4
  __m128 v397; // xmm1
  __m128 v398; // xmm2
  __m128 v399; // xmm1
  __m128 v400; // xmm1
  __m128 v401; // xmm8
  __m128 v402; // xmm15
  __m128 v403; // xmm2
  __m128 v404; // xmm6
  __m128 v405; // xmm1
  __m128 v406; // xmm15
  __m128 *v407; // r9
  __m128 v408; // xmm1
  __m128 v409; // xmm2
  __m128 v410; // xmm6
  __m128 v411; // xmm4
  __m128 v412; // xmm5
  __m128 v413; // xmm3
  __m128 v414; // xmm0
  __m128 v415; // xmm1
  __m128 v416; // xmm9
  __m128 v417; // xmm9
  __m128 v418; // xmm3
  __m128 v419; // xmm8
  __m128 v420; // xmm8
  __m128 v421; // xmm0
  __m128 v422; // xmm8
  __m128 v423; // xmm4
  __m128 v424; // xmm5
  __m128 v425; // xmm9
  __m128 v426; // xmm4
  __m128 v427; // xmm1
  __m128 v428; // xmm5
  __m128 v429; // xmm3
  __m128 v430; // xmm2
  __m128 v431; // xmm0
  __m128 v432; // xmm1
  __m128 v433; // xmm4
  __m128i v434; // xmm5
  __m128 v435; // xmm2
  __m128 v436; // xmm9
  __m128 v437; // xmm2
  __m128 v438; // xmm0
  __m128 v439; // xmm4
  __m128 v440; // xmm6
  signed int v441; // edx
  __m128 v442; // xmm2
  signed int v443; // eax
  signed int v444; // ecx
  signed int v445; // ebx
  signed __int64 v446; // rdi
  signed __int64 v447; // r10
  __int64 v448; // r8
  signed __int64 v449; // r11
  int v450; // edx
  __m128 v451; // xmm0
  __m128 v452; // xmm2
  __m128 v453; // xmm4
  __m128 v454; // xmm7
  __m128 v455; // xmm5
  __m128 v456; // xmm1
  __m128 v457; // xmm3
  __m128 v458; // xmm4
  __m128 v459; // xmm7
  __m128 v460; // xmm5
  __m128 v461; // xmm6
  __m128 v462; // xmm1
  __m128 v463; // xmm4
  __m128 v464; // xmm2
  __m128 v465; // xmm11
  __m128 v466; // xmm7
  __m128 v467; // xmm3
  __m128 v468; // xmm8
  __m128 v469; // xmm8
  __m128 v470; // xmm11
  __m128 v471; // xmm6
  __m128 v472; // xmm11
  __m128 v473; // xmm6
  __m128 v474; // xmm7
  __m128 v475; // xmm1
  __m128 v476; // xmm7
  __m128 v477; // xmm2
  __m128 v478; // xmm11
  int v479; // ecx
  __m128 v480; // xmm2
  hkcdVertex v481; // xmm0
  __int64 v482; // rcx
  signed int v483; // ecx
  __m128 v484; // xmm5
  __m128 v485; // xmm3
  __m128 v486; // xmm4
  __m128 v487; // xmm11
  __m128 v488; // xmm1
  __m128 v489; // xmm6
  __m128 v490; // xmm7
  __m128 v491; // xmm13
  __m128 v492; // xmm8
  __m128 v493; // xmm8
  __m128 v494; // xmm11
  __m128 v495; // xmm11
  __m128 v496; // xmm6
  __m128 v497; // xmm6
  __m128 v498; // xmm1
  __m128 v499; // xmm7
  __m128 v500; // xmm7
  __m128 v501; // xmm2
  __m128 v502; // xmm11
  int v503; // ecx
  __m128 v504; // xmm2
  hkcdVertex v505; // xmm0
  __int64 v506; // rcx
  signed int v507; // ecx
  __int64 v508; // r9
  __int64 v509; // rax
  __int64 v510; // rcx
  __m128 v511; // xmm0
  __m128 v512; // xmm12
  __m128 v513; // xmm3
  __m128 v514; // xmm2
  __m128 v515; // xmm3
  __m128 v516; // xmm4
  __m128 v517; // xmm9
  __m128 v518; // xmm5
  __m128 v519; // xmm1
  __m128 v520; // xmm2
  __m128 v521; // xmm1
  __m128 v522; // xmm6
  __m128 v523; // xmm4
  __m128 v524; // xmm1
  __m128 v525; // xmm2
  __m128 v526; // xmm8
  __m128 v527; // xmm8
  __m128 v528; // xmm8
  __m128 v529; // xmm2
  __int64 v530; // r9
  __int64 v531; // rax
  __int64 v532; // rcx
  __m128 v533; // xmm0
  __m128 v534; // xmm14
  __m128 v535; // xmm3
  __m128 v536; // xmm2
  __m128 v537; // xmm3
  __m128 v538; // xmm4
  __m128 v539; // xmm6
  __m128 v540; // xmm8
  __m128 v541; // xmm2
  __m128 v542; // xmm4
  __m128 v543; // xmm7
  __m128 v544; // xmm3
  __m128 v545; // xmm5
  __m128 v546; // xmm9
  __m128 v547; // xmm10
  __m128 v548; // xmm9
  __m128 v549; // xmm6
  __m128 v550; // xmm0
  __m128 v551; // xmm3
  __m128 v552; // xmm1
  __m128 v553; // xmm2
  __m128 v554; // xmm7
  __m128 v555; // xmm6
  __m128 v556; // xmm4
  __m128 v557; // xmm3
  __m128 v558; // xmm2
  __m128 v559; // xmm0
  __m128 v560; // xmm1
  __m128 v561; // xmm3
  __m128 v562; // xmm0
  __m128 v563; // xmm7
  __m128 v564; // xmm14
  __m128 v565; // xmm1
  _QWORD *v566; // rbx
  unsigned __int64 v567; // rcx
  unsigned __int64 v568; // rax
  unsigned int v569; // eax
  _QWORD *v570; // rcx
  unsigned __int64 v571; // rax
  signed __int64 v572; // rcx
  __int64 v573; // rdi
  char v574; // bl
  char v575; // r11
  char v576; // dl
  char v577; // r8
  char v578; // r9
  char v579; // r10
  __int64 result; // rax
  char v581[24]; // [rsp+48h] [rbp-80h]
  hkcdGskBase v582; // [rsp+60h] [rbp-68h]
  __m128 v583; // [rsp+128h] [rbp+60h]
  __m128 v584; // [rsp+138h] [rbp+70h]
  __m128 v585; // [rsp+148h] [rbp+80h]
  __m128 v586; // [rsp+158h] [rbp+90h]
  __m128 v587; // [rsp+168h] [rbp+A0h]
  __m128 v588; // [rsp+178h] [rbp+B0h]
  __m128 v589; // [rsp+188h] [rbp+C0h]
  __m128 v590; // [rsp+198h] [rbp+D0h]
  __m128 v591; // [rsp+1A8h] [rbp+E0h]
  __m128 v592; // [rsp+1B8h] [rbp+F0h]
  __m128 v593; // [rsp+1C8h] [rbp+100h]
  __m128 *shapeB; // [rsp+1D8h] [rbp+110h]
  int v595; // [rsp+1E0h] [rbp+118h]
  __m128 v596; // [rsp+1E8h] [rbp+120h]
  hkcdVertex *shapeA; // [rsp+1F8h] [rbp+130h]
  int v598; // [rsp+200h] [rbp+138h]
  __m128 v599; // [rsp+208h] [rbp+140h]
  __m128 v600; // [rsp+218h] [rbp+150h]
  __m128 v601; // [rsp+228h] [rbp+160h]
  __m128 v602; // [rsp+238h] [rbp+170h]
  __m128 v603; // [rsp+248h] [rbp+180h]
  __m128 v604; // [rsp+258h] [rbp+190h]
  __m128 v605; // [rsp+268h] [rbp+1A0h]
  __m128 v606; // [rsp+278h] [rbp+1B0h]
  __m128 v607; // [rsp+288h] [rbp+1C0h]
  __m128 v608; // [rsp+298h] [rbp+1D0h]
  __m128 v609; // [rsp+2A8h] [rbp+1E0h]
  __m128 v610; // [rsp+2B8h] [rbp+1F0h]
  __m128 v611; // [rsp+2C8h] [rbp+200h]
  __m128 v612; // [rsp+2D8h] [rbp+210h]
  __m128 v613; // [rsp+2E8h] [rbp+220h]
  __m128 v614; // [rsp+2F8h] [rbp+230h]
  __m128 v615; // [rsp+308h] [rbp+240h]
  __m128 v616; // [rsp+318h] [rbp+250h]
  __m128 v617; // [rsp+328h] [rbp+260h]
  __m128 v618; // [rsp+338h] [rbp+270h]
  __m128 v619; // [rsp+348h] [rbp+280h]
  __m128 v620; // [rsp+358h] [rbp+290h]
  __m128 v621; // [rsp+368h] [rbp+2A0h]
  __m128 v622; // [rsp+378h] [rbp+2B0h]
  __m128 v623; // [rsp+388h] [rbp+2C0h]
  __m128 v624; // [rsp+398h] [rbp+2D0h]
  __m128 v625; // [rsp+3A8h] [rbp+2E0h]
  __m128 v626; // [rsp+3B8h] [rbp+2F0h]
  __m128 v627; // [rsp+3C8h] [rbp+300h]
  __m128 v628; // [rsp+3D8h] [rbp+310h]
  __m128 v629; // [rsp+3E8h] [rbp+320h]
  __m128 v630; // [rsp+3F8h] [rbp+330h]
  __m128 v631; // [rsp+408h] [rbp+340h]
  __m128 v632; // [rsp+418h] [rbp+350h]
  __m128 v633; // [rsp+428h] [rbp+360h]
  __m128 v634; // [rsp+438h] [rbp+370h]
  __m128 v635; // [rsp+448h] [rbp+380h]
  __m128 v636; // [rsp+458h] [rbp+390h]
  hkVector4f supportOut; // [rsp+468h] [rbp+3A0h]
  __m128 v638; // [rsp+478h] [rbp+3B0h]
  __m128 v639; // [rsp+488h] [rbp+3C0h]
  __m128 v640; // [rsp+498h] [rbp+3D0h]
  __m128 v641; // [rsp+4A8h] [rbp+3E0h]
  __m128 v642; // [rsp+4B8h] [rbp+3F0h]
  __m128 v643; // [rsp+4C8h] [rbp+400h]
  __m128 v644; // [rsp+4D8h] [rbp+410h]
  __m128 v645; // [rsp+4E8h] [rbp+420h]
  __m128 v646; // [rsp+4F8h] [rbp+430h]
  __m128 v647; // [rsp+508h] [rbp+440h]
  __m128 v648; // [rsp+518h] [rbp+450h]
  hkVector4f v649; // [rsp+528h] [rbp+460h]
  hkVector4f v650; // [rsp+538h] [rbp+470h]
  hkVector4f v651; // [rsp+548h] [rbp+480h]
  hkVector4f v652; // [rsp+558h] [rbp+490h]
  __m128 v653; // [rsp+568h] [rbp+4A0h]
  __m128 v654; // [rsp+578h] [rbp+4B0h]
  __m128 v655; // [rsp+588h] [rbp+4C0h]
  __m128 v656; // [rsp+598h] [rbp+4D0h]
  __m128 v657; // [rsp+5A8h] [rbp+4E0h]
  __m128 v658; // [rsp+5B8h] [rbp+4F0h]
  __m128 v659; // [rsp+5C8h] [rbp+500h]
  __m128 v660; // [rsp+5D8h] [rbp+510h]
  __m128 v661; // [rsp+5E8h] [rbp+520h]
  __m128 v662; // [rsp+5F8h] [rbp+530h]
  __m128 v663; // [rsp+608h] [rbp+540h]
  __m128 v664; // [rsp+618h] [rbp+550h]
  __m128 v665; // [rsp+628h] [rbp+560h]
  __m128 v666; // [rsp+638h] [rbp+570h]
  __m128 v667; // [rsp+648h] [rbp+580h]
  __m128 v668; // [rsp+658h] [rbp+590h]
  __m128 v669; // [rsp+668h] [rbp+5A0h]
  __m128 v670; // [rsp+678h] [rbp+5B0h]
  __m128 v671; // [rsp+688h] [rbp+5C0h]
  __m128 v672; // [rsp+698h] [rbp+5D0h]
  __m128 v673; // [rsp+6A8h] [rbp+5E0h]
  __m128 v674; // [rsp+6B8h] [rbp+5F0h]
  __m128 v675; // [rsp+6C8h] [rbp+600h]
  __m128 v676; // [rsp+6D8h] [rbp+610h]
  __int128 v677; // [rsp+6E8h] [rbp+620h]
  __m128 v678; // [rsp+6F8h] [rbp+630h]
  __m128 v679; // [rsp+708h] [rbp+640h]
  __m128 v680; // [rsp+718h] [rbp+650h]
  __m128 v681; // [rsp+728h] [rbp+660h]
  __m128 v682; // [rsp+738h] [rbp+670h]
  __m128 v683; // [rsp+748h] [rbp+680h]
  __int128 v684; // [rsp+758h] [rbp+690h]
  __int128 v685; // [rsp+768h] [rbp+6A0h]
  __int128 v686; // [rsp+778h] [rbp+6B0h]
  __int128 v687; // [rsp+788h] [rbp+6C0h]
  __m128 v688; // [rsp+798h] [rbp+6D0h]
  __int128 v689; // [rsp+7A8h] [rbp+6E0h]
  __int128 v690; // [rsp+7B8h] [rbp+6F0h]
  __int128 v691; // [rsp+7C8h] [rbp+700h]
  __int128 v692; // [rsp+7D8h] [rbp+710h]
  __m128 v693; // [rsp+7E8h] [rbp+720h]
  __m128 v694; // [rsp+7F8h] [rbp+730h]
  __m128 v695; // [rsp+808h] [rbp+740h]
  __m128 v696; // [rsp+818h] [rbp+750h]
  __m128 v697; // [rsp+828h] [rbp+760h]
  __m128 v698; // [rsp+838h] [rbp+770h]
  __m128 v699; // [rsp+848h] [rbp+780h]
  __m128 v700; // [rsp+858h] [rbp+790h]
  __m128 v701; // [rsp+868h] [rbp+7A0h]
  __m128 v702; // [rsp+878h] [rbp+7B0h]
  __m128 v703; // [rsp+888h] [rbp+7C0h]
  __m128 v704; // [rsp+898h] [rbp+7D0h]
  __m128 v705; // [rsp+8A8h] [rbp+7E0h]
  __m128 v706; // [rsp+8B8h] [rbp+7F0h]
  __int128 v707; // [rsp+8C8h] [rbp+800h]
  __m128 v708; // [rsp+8D8h] [rbp+810h]
  __int128 v709; // [rsp+8E8h] [rbp+820h]
  __int128 v710; // [rsp+8F8h] [rbp+830h]
  __int128 v711; // [rsp+908h] [rbp+840h]
  __int128 v712; // [rsp+918h] [rbp+850h]
  __m128 v713; // [rsp+928h] [rbp+860h]
  __m128 v714; // [rsp+938h] [rbp+870h]
  __m128 v715; // [rsp+948h] [rbp+880h]
  __m128 v716; // [rsp+958h] [rbp+890h]
  __m128 v717; // [rsp+968h] [rbp+8A0h]
  __m128 v718; // [rsp+978h] [rbp+8B0h]
  __m128 v719; // [rsp+988h] [rbp+8C0h]
  __m128 v720; // [rsp+998h] [rbp+8D0h]
  __m128 v721; // [rsp+9A8h] [rbp+8E0h]
  __m128 v722; // [rsp+9B8h] [rbp+8F0h]
  __m128 v723; // [rsp+9C8h] [rbp+900h]
  __m128 v724; // [rsp+9D8h] [rbp+910h]
  __m128 v725; // [rsp+9E8h] [rbp+920h]
  __m128 v726; // [rsp+9F8h] [rbp+930h]
  __m128 v727; // [rsp+A08h] [rbp+940h]
  __m128 v728; // [rsp+A18h] [rbp+950h]
  __int128 v729; // [rsp+A28h] [rbp+960h]
  __int128 v730; // [rsp+A38h] [rbp+970h]
  __int128 v731; // [rsp+A48h] [rbp+980h]
  __int128 v732; // [rsp+A58h] [rbp+990h]
  __m128 v733; // [rsp+A68h] [rbp+9A0h]
  __m128 v734; // [rsp+A78h] [rbp+9B0h]
  hkcdGskBase::ShapeInterface shapeInterface; // [rsp+B70h] [rbp+AA8h]
  hkPadSpu<int> dimB; // [rsp+B78h] [rbp+AB0h]
  __m128 *v737; // [rsp+B88h] [rbp+AC0h]
  hkPadSpu<int> dimA; // [rsp+B90h] [rbp+AC8h]
  hkTransformf *retaddr; // [rsp+B98h] [rbp+AD0h]
  char *v740; // [rsp+BA0h] [rbp+AD8h]
  hkcdGsk::GetClosestPointOutput *v741; // [rsp+BA8h] [rbp+AE0h]

  shapeA = vertsA;
  v598 = numVertsA;
  v4 = vertsA;
  v5 = v582.m_verticesBinA;
  v6 = v740;
  shapeInterface.vfptr = (hkcdGskBase::ShapeInterfaceVtbl *)&hkcdGsk_Vector4ShapeInterface::`vftable';
  shapeB = v737;
  v595 = dimA.m_storage;
  v7 = (unsigned int)(unsigned __int8)v740[4] >> 6;
  v8 = v740[4] & 3;
  v9 = (unsigned int)(unsigned __int8)v740[4] >> 6;
  while ( 1 )
  {
    v10 = (unsigned __int8)*v6;
    v11 = v5;
    ++v5;
    ++v6;
    *v11 = v4[v10];
    if ( !--v9 )
      break;
    v4 = shapeA;
  }
  v12 = &v630;
  v13 = v8;
  v14 = &v740[(unsigned __int64)(unsigned __int8)v740[4] >> 6];
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
  *(_OWORD *)&v582.m_lastDimB.m_storage = 0i64;
  v20 = v8 - 1;
  v21 = retaddr->m_rotation.m_col0.m_quad;
  v22 = 16 * v20;
  v649.m_quad = (__m128)retaddr->m_rotation.m_col0;
  v23 = retaddr->m_rotation.m_col1.m_quad;
  v650.m_quad = (__m128)retaddr->m_rotation.m_col1;
  v24 = retaddr->m_rotation.m_col2.m_quad;
  v651.m_quad = (__m128)retaddr->m_rotation.m_col2;
  v25 = retaddr->m_translation.m_quad;
  v652.m_quad = (__m128)retaddr->m_translation;
  do
  {
    v26 = *(__m128 *)((char *)&v630 + v22);
    v22 -= 16i64;
    --v20;
    *(__m128 *)((char *)&v582.m_verticesBinA[1].m_quad + v22 + 8) = _mm_add_ps(
                                                                      _mm_add_ps(
                                                                        _mm_add_ps(
                                                                          _mm_mul_ps(_mm_shuffle_ps(v26, v26, 85), v23),
                                                                          _mm_mul_ps(_mm_shuffle_ps(v26, v26, 0), v21)),
                                                                        _mm_mul_ps(_mm_shuffle_ps(v26, v26, 170), v24)),
                                                                      v25);
  }
  while ( v20 >= 0 );
  v27 = 0;
  v28.m_quad = _mm_shuffle_ps(
                 *(__m128 *)((char *)&v582.m_verticesBinA[0].m_quad + 8),
                 _mm_unpackhi_ps(*(__m128 *)((char *)&v582.m_verticesBinA[0].m_quad + 8), v630),
                 196);
  *(hkVector4f *)((char *)&v582.m_verticesBinA[0].0 + 8) = (hkVector4f)v28.m_quad;
  *(__m128 *)((char *)&v582.m_verticesBinA[1].m_quad + 8) = _mm_shuffle_ps(
                                                              *(__m128 *)((char *)&v582.m_verticesBinA[1].m_quad + 8),
                                                              _mm_unpackhi_ps(
                                                                *(__m128 *)((char *)&v582.m_verticesBinA[1].m_quad + 8),
                                                                v631),
                                                              196);
  *(float *)&v737 = FLOAT_0_0000099999997;
  *(__m128 *)((char *)&v582.m_verticesBinA[2].m_quad + 8) = _mm_shuffle_ps(
                                                              *(__m128 *)((char *)&v582.m_verticesBinA[2].m_quad + 8),
                                                              _mm_unpackhi_ps(
                                                                *(__m128 *)((char *)&v582.m_verticesBinA[2].m_quad + 8),
                                                                v632),
                                                              196);
  v29 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_0000099999997), (__m128)LODWORD(FLOAT_0_0000099999997), 0);
LABEL_9:
  v30 = *(__m128 *)((char *)&v582.m_verticesA[0].m_quad + 8);
  *(float *)&v737 = aTb[1].m_rotation.m_col2.m_quad.m128_f32[0];
  v582.m_checkTriangleDots = (hkVector4f)v28.m_quad;
  *(hkcdVertex *)&v581[8] = *(hkcdVertex *)((char *)v582.m_verticesA + 8);
  v31 = (dimB.m_storage | 8 * dimA.m_storage) - 9;
  v603 = _mm_mul_ps(v29, _mm_shuffle_ps((__m128)(unsigned int)v737, (__m128)(unsigned int)v737, 0));
  v32 = query.m_quad;
  *(hkVector4f *)v581 = (hkVector4f)query.m_quad;
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
        v406 = v30;
        v407 = (__m128 *)((char *)&v582.m_verticesBinA[0].m_quad + 8);
        goto LABEL_96;
      case 8u:
        goto LABEL_135;
      case 9u:
        goto LABEL_43;
      case 0xAu:
        v33 = (__m128 *)((char *)&v582.m_verticesA[0].m_quad + 8);
        v34 = (__m128 *)((char *)&v582.m_verticesBinA[0].m_quad + 8);
        goto LABEL_13;
      case 0x10u:
        goto LABEL_111;
      case 0x11u:
        v33 = (__m128 *)((char *)&v582.m_verticesBinA[0].m_quad + 8);
        v34 = (__m128 *)((char *)&v582.m_verticesA[0].m_quad + 8);
LABEL_13:
        if ( *((_DWORD *)&v582.m_lastDimB + 2) == 2 )
        {
          v35 = *v34;
          v36 = v34[1];
          v37 = *v33;
          v38 = v33[1];
          v585 = v36;
          v39 = _mm_sub_ps(v36, v34[2]);
          v40 = _mm_sub_ps(v35, v34[2]);
          *(__m128 *)&v581[16] = v39;
          v583 = v40;
          v41 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v40, v40, 201), v39),
                  _mm_mul_ps(_mm_shuffle_ps(v39, v39, 201), v40));
          v42 = _mm_shuffle_ps(v41, v41, 201);
          v43 = _mm_mul_ps(_mm_sub_ps(v37, v35), v42);
          v44 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v43, v43, 85), _mm_shuffle_ps(v43, v43, 0)),
                  _mm_shuffle_ps(v43, v43, 170));
          v45 = _mm_mul_ps(_mm_sub_ps(v38, v35), v42);
          v46 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v45, v45, 85), _mm_shuffle_ps(v45, v45, 0)),
                  _mm_shuffle_ps(v45, v45, 170));
          v47 = _mm_mul_ps(v44, v44);
          v48 = _mm_mul_ps(v46, v46);
          if ( _mm_movemask_ps(_mm_mul_ps(v44, v46)) )
          {
            v708 = _mm_sub_ps(v44, v46);
            v49 = _mm_rcp_ps(v708);
            v639 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v49, v708)), v49), v44);
            v50 = _mm_sub_ps(v34[1], *v34);
            v51 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v33[1], *v33), v639), *v33);
            v52 = _mm_sub_ps(v34[2], *v34);
            v53 = _mm_sub_ps(v34[1], v51);
            v54 = _mm_sub_ps(v34[2], v51);
            v55 = _mm_sub_ps(*v34, v51);
            v56 = _mm_sub_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v52, v52, 201), v50),
                    _mm_mul_ps(_mm_shuffle_ps(v50, v50, 201), v52));
            v57 = _mm_shuffle_ps(v56, v56, 201);
            v58 = _mm_shuffle_ps(v57, v57, 210);
            v59 = _mm_mul_ps(
                    _mm_sub_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v54, v54, 201), v58),
                      _mm_mul_ps(_mm_shuffle_ps(v54, v54, 210), v57)),
                    v53);
            v60 = _mm_shuffle_ps(v53, v53, 210);
            v61 = _mm_mul_ps(
                    _mm_sub_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v55, v55, 201), v58),
                      _mm_mul_ps(_mm_shuffle_ps(v55, v55, 210), v57)),
                    v54);
            v62 = _mm_mul_ps(_mm_shuffle_ps(v53, v53, 201), v58);
            v63 = v59;
            v64 = _mm_unpackhi_ps(v59, v61);
            v65 = _mm_unpacklo_ps(v63, v61);
            v66 = _mm_mul_ps(_mm_sub_ps(v62, _mm_mul_ps(v60, v57)), v55);
            v67 = _mm_movelh_ps(v65, v66);
            if ( (_mm_movemask_ps(
                    _mm_cmpltps(
                      v18,
                      _mm_add_ps(
                        _mm_shuffle_ps(v64, v66, 228),
                        _mm_add_ps(v67, _mm_shuffle_ps(_mm_movehl_ps(v67, v65), v66, 212))))) & 7) == 7 )
            {
              v68 = 1;
              goto LABEL_39;
            }
            goto LABEL_22;
          }
          v69 = _mm_cmpltps(v47, v48);
          v70 = v34[2];
          v71 = _mm_or_ps(_mm_andnot_ps(v69, v38), _mm_and_ps(v69, v37));
          v72 = v34[1];
          v73 = _mm_sub_ps(v35, v70);
          v74 = _mm_sub_ps(v70, v72);
          v75 = _mm_sub_ps(v71, v72);
          v76 = _mm_sub_ps(v72, v35);
          v77 = _mm_sub_ps(v71, v70);
          v78 = _mm_shuffle_ps(v74, v74, 201);
          v79 = _mm_shuffle_ps(v73, v73, 201);
          v80 = _mm_sub_ps(v71, *v34);
          v81 = _mm_sub_ps(_mm_mul_ps(v74, v79), _mm_mul_ps(v73, v78));
          v19 = _mm_shuffle_ps(v81, v81, 201);
          *(__m128 *)&v582.m_lastDimB.m_storage = v19;
          v82 = _mm_sub_ps(_mm_mul_ps(v75, v78), _mm_mul_ps(_mm_shuffle_ps(v75, v75, 201), v74));
          v83 = _mm_mul_ps(_mm_shuffle_ps(v82, v82, 201), v19);
          v84 = _mm_sub_ps(_mm_mul_ps(v77, v79), _mm_mul_ps(_mm_shuffle_ps(v77, v77, 201), v73));
          v85 = _mm_mul_ps(_mm_shuffle_ps(v80, v80, 201), v76);
          v86 = _mm_mul_ps(_mm_shuffle_ps(v84, v84, 201), v19);
          v87 = _mm_mul_ps(_mm_shuffle_ps(v76, v76, 201), v80);
          v88 = _mm_unpacklo_ps(v83, v86);
          v89 = _mm_sub_ps(v87, v85);
          v90 = _mm_mul_ps(_mm_shuffle_ps(v89, v89, 201), v19);
          v91 = _mm_movelh_ps(v88, v90);
          v92 = _mm_add_ps(
                  _mm_shuffle_ps(_mm_unpackhi_ps(v83, v86), v90, 228),
                  _mm_add_ps(v91, _mm_shuffle_ps(_mm_movehl_ps(v91, v88), v90, 212)));
          v93 = _mm_movemask_ps(_mm_cmpltps(v92, v18)) & 7;
          if ( v93 == 7 )
          {
            v94 = _mm_mul_ps(_mm_sub_ps(v30, v28.m_quad), v19);
            if ( _mm_movemask_ps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v94, v94, 85), _mm_shuffle_ps(v94, v94, 0)),
                     _mm_shuffle_ps(v94, v94, 170))) )
            {
              v95 = *v34;
              v19 = _mm_xor_ps(v19, (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0));
              *v34 = v585;
              v34[1] = v95;
              v32 = query.m_quad;
              *(__m128 *)&v582.m_lastDimB.m_storage = v19;
              v92 = _mm_shuffle_ps(v92, v92, 225);
              *(hkVector4f *)v581 = (hkVector4f)query.m_quad;
            }
          }
          *(__m128 *)((char *)&v582.m_checkTriangleDots.m_quad + 8) = v92;
          if ( v93 != 7 )
          {
LABEL_22:
            v96 = _mm_sub_ps(v34[2], *v33);
            v97 = _mm_sub_ps(v33[1], *v33);
            v98 = _mm_mul_ps(v97, *(__m128 *)&v581[16]);
            v99 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v98, v98, 85), _mm_shuffle_ps(v98, v98, 0)),
                    _mm_shuffle_ps(v98, v98, 170));
            v100 = _mm_mul_ps(v96, v97);
            v101 = _mm_mul_ps(v96, *(__m128 *)&v581[16]);
            v102 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v100, v100, 85), _mm_shuffle_ps(v100, v100, 0)),
                     _mm_shuffle_ps(v100, v100, 170));
            v103 = _mm_mul_ps(v97, v97);
            v104 = _mm_mul_ps(*(__m128 *)&v581[16], *(__m128 *)&v581[16]);
            v641 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v103, v103, 85), _mm_shuffle_ps(v103, v103, 0)),
                     _mm_shuffle_ps(v103, v103, 170));
            v105 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v101, v101, 85), _mm_shuffle_ps(v101, v101, 0)),
                     _mm_shuffle_ps(v101, v101, 170));
            v643 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v104, v104, 85), _mm_shuffle_ps(v104, v104, 0)),
                     _mm_shuffle_ps(v104, v104, 170));
            v106 = _mm_max_ps(_mm_sub_ps(_mm_mul_ps(v643, v641), _mm_mul_ps(v99, v99)), *(__m128 *)&epsilon);
            v107 = _mm_rcp_ps(v106);
            v645 = v106;
            v108 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v107, v106)), v107);
            v109 = _mm_rcp_ps(v643);
            v647 = v108;
            v110 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v109, v643)), v109);
            v111 = _mm_rcp_ps(v641);
            v734 = v110;
            v728 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v111, v641)), v111);
            v112 = _mm_cmpleps(v106, *(__m128 *)&epsilon);
            v113 = _mm_sub_ps(_mm_mul_ps(v643, v102), _mm_mul_ps(v105, v99));
            v114 = _mm_cmpltps(v113, v106);
            v115 = _mm_sub_ps(
                     _mm_mul_ps(
                       _mm_or_ps(
                         _mm_andnot_ps(
                           v112,
                           _mm_mul_ps(
                             _mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_and_ps(v113, v114), _mm_andnot_ps(v114, v106))),
                             v108)),
                         _mm_and_ps(v112, v32)),
                       _mm_mul_ps(v110, v99)),
                     _mm_mul_ps(v110, v105));
            v116 = _mm_cmpltps(v115, v32);
            v117 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v115, v116), _mm_andnot_ps(v116, v32)));
            v118 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v728, v99), v117), _mm_mul_ps(v728, v102));
            v119 = v34[2];
            v120 = _mm_add_ps(_mm_mul_ps(v117, *(__m128 *)&v581[16]), v119);
            v121 = _mm_sub_ps(v119, *v33);
            v122 = _mm_cmpltps(v118, v32);
            v123 = _mm_sub_ps(
                     _mm_add_ps(
                       _mm_mul_ps(
                         _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v118, v122), _mm_andnot_ps(v122, v32))),
                         v97),
                       *v33),
                     v120);
            v124 = _mm_mul_ps(v97, v583);
            v125 = _mm_mul_ps(v123, v123);
            v126 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v125, v125, 85), _mm_shuffle_ps(v125, v125, 0)),
                     _mm_shuffle_ps(v125, v125, 170));
            v127 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v124, v124, 85), _mm_shuffle_ps(v124, v124, 0)),
                     _mm_shuffle_ps(v124, v124, 170));
            v128 = v121;
            v129 = _mm_mul_ps(v121, v583);
            v130 = _mm_mul_ps(v128, v97);
            v131 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v130, v130, 85), _mm_shuffle_ps(v130, v130, 0)),
                     _mm_shuffle_ps(v130, v130, 170));
            v132 = _mm_mul_ps(v583, v583);
            v133 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v129, v129, 85), _mm_shuffle_ps(v129, v129, 0)),
                     _mm_shuffle_ps(v129, v129, 170));
            v636 = v641;
            v678 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v132, v132, 85), _mm_shuffle_ps(v132, v132, 0)),
                     _mm_shuffle_ps(v132, v132, 170));
            v134 = _mm_max_ps(_mm_sub_ps(_mm_mul_ps(v678, v641), _mm_mul_ps(v127, v127)), *(__m128 *)&epsilon);
            v135 = _mm_rcp_ps(v134);
            v638 = v134;
            v136 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v135, v134)), v135);
            v137 = _mm_rcp_ps(v678);
            v633 = v136;
            v138 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v137, v678)), v137);
            v139 = _mm_rcp_ps(v641);
            v640 = v138;
            v140 = _mm_cmpleps(v134, *(__m128 *)&epsilon);
            v141 = _mm_sub_ps(_mm_mul_ps(v678, v131), _mm_mul_ps(v133, v127));
            v683 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v139, v641)), v139);
            v142 = _mm_cmpltps(v141, v134);
            v143 = _mm_sub_ps(
                     _mm_mul_ps(
                       _mm_or_ps(
                         _mm_andnot_ps(
                           v140,
                           _mm_mul_ps(
                             _mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_and_ps(v142, v141), _mm_andnot_ps(v142, v134))),
                             v136)),
                         _mm_and_ps(v140, *(__m128 *)v581)),
                       _mm_mul_ps(v138, v127)),
                     _mm_mul_ps(v138, v133));
            v144 = _mm_cmpltps(v143, *(__m128 *)v581);
            v145 = v34[2];
            v19 = *(__m128 *)&v582.m_lastDimB.m_storage;
            v18 = 0i64;
            v146 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v144, v143), _mm_andnot_ps(v144, *(__m128 *)v581)));
            v147 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v683, v127), v146), _mm_mul_ps(v683, v131));
            v148 = _mm_cmpltps(v147, *(__m128 *)v581);
            v149 = _mm_sub_ps(
                     _mm_add_ps(
                       _mm_mul_ps(
                         _mm_max_ps(
                           (__m128)0i64,
                           _mm_or_ps(_mm_and_ps(v148, v147), _mm_andnot_ps(v148, *(__m128 *)v581))),
                         v97),
                       *v33),
                     _mm_add_ps(_mm_mul_ps(v146, v583), v145));
            v150 = _mm_mul_ps(v149, v149);
            v151 = _mm_cmpltps(
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v150, v150, 85), _mm_shuffle_ps(v150, v150, 0)),
                       _mm_shuffle_ps(v150, v150, 170)),
                     v126);
            *v34 = _mm_or_ps(_mm_andnot_ps(v151, v34[1]), _mm_and_ps(*v34, v151));
            v34[1] = v145;
LABEL_37:
            v68 = 2;
            goto LABEL_38;
          }
          *v33 = v71;
          v68 = 0;
LABEL_38:
          v30 = *(__m128 *)((char *)&v582.m_verticesA[0].m_quad + 8);
          v28.m_quad = *(__m128 *)((char *)v582.m_verticesBinA + 8);
          *(hkVector4f *)v581 = (hkVector4f)query.m_quad;
          *(hkcdVertex *)&v581[8] = *(hkcdVertex *)((char *)v582.m_verticesA + 8);
          v582.m_checkTriangleDots = *(hkVector4f *)((char *)v582.m_verticesBinA + 8);
          goto LABEL_39;
        }
        v152 = *v34;
        v153 = v33[1];
        v154 = *(__m128 *)((char *)&v582.m_checkTriangleDots.m_quad + 8);
        v155 = _mm_mul_ps(_mm_sub_ps(*v33, *v34), v19);
        v156 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v155, v155, 85), _mm_shuffle_ps(v155, v155, 0)),
                 _mm_shuffle_ps(v155, v155, 170));
        v157 = _mm_mul_ps(_mm_sub_ps(v33[1], *v34), v19);
        v158 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v157, v157, 85), _mm_shuffle_ps(v157, v157, 0)),
                 _mm_shuffle_ps(v157, v157, 170));
        if ( (float)(v158.m128_f32[0] * v156.m128_f32[0]) < v18.m128_f32[0] )
        {
          v642 = _mm_sub_ps(v156, v158);
          v159 = _mm_rcp_ps(v642);
          v723 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v642, v159)), v159), v156);
          v152 = *v34;
          v153 = v33[1];
          v160 = _mm_sub_ps(v34[2], *v34);
          v161 = _mm_sub_ps(v34[1], *v34);
          v162 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v33[1], *v33), v723), *v33);
          v163 = _mm_sub_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v160, v160, 201), v161),
                   _mm_mul_ps(_mm_shuffle_ps(v161, v161, 201), v160));
          v164 = _mm_shuffle_ps(v163, v163, 201);
          v165 = _mm_sub_ps(v34[1], v162);
          v166 = _mm_sub_ps(*v34, v162);
          v167 = _mm_sub_ps(v34[2], v162);
          v168 = _mm_shuffle_ps(v164, v164, 210);
          v169 = _mm_mul_ps(
                   _mm_sub_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v167, v167, 201), v168),
                     _mm_mul_ps(_mm_shuffle_ps(v167, v167, 210), v164)),
                   v165);
          v170 = _mm_shuffle_ps(v165, v165, 210);
          v171 = _mm_mul_ps(
                   _mm_sub_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v166, v166, 201), v168),
                     _mm_mul_ps(_mm_shuffle_ps(v166, v166, 210), v164)),
                   v167);
          v172 = _mm_mul_ps(_mm_shuffle_ps(v165, v165, 201), v168);
          v173 = v169;
          v174 = _mm_unpackhi_ps(v169, v171);
          v175 = _mm_unpacklo_ps(v173, v171);
          v176 = _mm_mul_ps(_mm_sub_ps(v172, _mm_mul_ps(v170, v164)), v166);
          v177 = _mm_movelh_ps(v175, v176);
          if ( (_mm_movemask_ps(
                  _mm_cmpltps(
                    v18,
                    _mm_add_ps(
                      _mm_shuffle_ps(v174, v176, 228),
                      _mm_add_ps(v177, _mm_shuffle_ps(_mm_movehl_ps(v177, v175), v176, 212))))) & 7) == 7 )
          {
            v68 = 1;
            goto LABEL_39;
          }
        }
        v178 = v34[1];
        v179 = v34[2];
        v180 = _mm_sub_ps(v152, v179);
        v181 = _mm_sub_ps(v34[1], v152);
        v182 = _mm_shuffle_ps(v180, v180, 201);
        v183 = v153;
        v184 = v153;
        v185 = _mm_sub_ps(v153, *v34);
        v186 = _mm_sub_ps(v183, v178);
        v187 = _mm_sub_ps(v34[2], v178);
        v188 = _mm_sub_ps(v184, v179);
        v189 = _mm_shuffle_ps(v187, v187, 201);
        v190 = _mm_sub_ps(_mm_mul_ps(v187, v182), _mm_mul_ps(v180, v189));
        v191 = _mm_shuffle_ps(v190, v190, 201);
        v192 = _mm_sub_ps(_mm_mul_ps(v186, v189), _mm_mul_ps(_mm_shuffle_ps(v186, v186, 201), v187));
        v193 = _mm_sub_ps(_mm_mul_ps(v188, v182), _mm_mul_ps(_mm_shuffle_ps(v188, v188, 201), v180));
        v194 = _mm_mul_ps(_mm_shuffle_ps(v192, v192, 201), v191);
        v195 = _mm_mul_ps(_mm_shuffle_ps(v193, v193, 201), v191);
        v196 = _mm_unpacklo_ps(v194, v195);
        v197 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v181, v181, 201), v185),
                 _mm_mul_ps(_mm_shuffle_ps(v185, v185, 201), v181));
        v198 = _mm_mul_ps(_mm_shuffle_ps(v197, v197, 201), v191);
        v199 = _mm_movelh_ps(v196, v198);
        v200 = _mm_add_ps(
                 _mm_shuffle_ps(_mm_unpackhi_ps(v194, v195), v198, 228),
                 _mm_add_ps(v199, _mm_shuffle_ps(_mm_movehl_ps(v199, v196), v198, 212)));
        *(__m128 *)((char *)&v582.m_checkTriangleDots.m_quad + 8) = v200;
        v201 = _mm_movemask_ps(_mm_cmpltps(v200, (__m128)0i64)) & 7;
        switch ( v201 )
        {
          case 7:
            v68 = 0;
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
            LODWORD(v202) = (unsigned __int128)_mm_shuffle_ps(v154, v154, 85);
            LODWORD(v203) = (unsigned __int128)_mm_shuffle_ps(v154, v154, 170);
            if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v200, v200, 85)) - v202) * v203) > (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v200, v200, 170)) - v203) * v202) )
              goto LABEL_54;
            goto LABEL_53;
        }
        if ( v201 != 2 )
        {
          if ( v201 != 4
            || (LODWORD(v256) = (unsigned __int128)_mm_shuffle_ps(v154, v154, 0),
                LODWORD(v257) = (unsigned __int128)_mm_shuffle_ps(v154, v154, 85),
                (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v200, v200, 0)) - v256) * v257) <= (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v200, v200, 85)) - v257) * v256)) )
          {
LABEL_36:
            v18 = 0i64;
            *v34 = v34[2];
            goto LABEL_37;
          }
LABEL_53:
          v34[1] = v34[2];
          v28.m_quad = *(__m128 *)((char *)v582.m_verticesBinA + 8);
          v30 = *(__m128 *)((char *)&v582.m_verticesA[0].m_quad + 8);
          v582.m_checkTriangleDots = *(hkVector4f *)((char *)v582.m_verticesBinA + 8);
          *(hkcdVertex *)&v581[8] = *(hkcdVertex *)((char *)v582.m_verticesA + 8);
          *(hkVector4f *)v581 = (hkVector4f)query.m_quad;
          goto LABEL_54;
        }
        LODWORD(v204) = (unsigned __int128)_mm_shuffle_ps(v154, v154, 170);
        LODWORD(v205) = (unsigned __int128)_mm_shuffle_ps(v154, v154, 0);
        if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v200, v200, 170)) - v204) * v205) > (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v200, v200, 0)) - v205) * v204) )
          goto LABEL_36;
LABEL_54:
        v68 = 2;
        v18 = 0i64;
LABEL_39:
        if ( v68 )
        {
          v206 = v68 - 1;
          if ( !v206 )
            goto LABEL_64;
          if ( v206 != 1 )
            goto LABEL_149;
          dimA.m_storage = 2;
          dimB.m_storage = 2;
LABEL_43:
          v207 = _mm_sub_ps(v30, v28.m_quad);
          v208 = _mm_sub_ps(*(__m128 *)((char *)&v582.m_verticesA[1].m_quad + 8), v30);
          v209 = _mm_sub_ps(*(__m128 *)((char *)&v582.m_verticesBinA[1].m_quad + 8), v28.m_quad);
          *(hkcdVertex *)&v581[16] = *(hkcdVertex *)((char *)&v582.m_verticesA[1] + 8);
          v210 = _mm_shuffle_ps(v209, v209, 201);
          v211 = _mm_shuffle_ps(v208, v208, 201);
          v585 = v208;
          v212 = _mm_sub_ps(_mm_mul_ps(v208, v210), _mm_mul_ps(v209, v211));
          v19 = _mm_shuffle_ps(v212, v212, 201);
          *(__m128 *)&v582.m_lastDimB.m_storage = v19;
          v213 = _mm_sub_ps(_mm_mul_ps(v211, v19), _mm_mul_ps(v208, v19));
          v214 = _mm_shuffle_ps(v213, v213, 201);
          v215 = _mm_sub_ps(_mm_mul_ps(v210, v19), _mm_mul_ps(v209, v19));
          v216 = _mm_mul_ps(v207, v214);
          v217 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)((char *)&v582.m_verticesBinA[1].m_quad + 8), v30), v214);
          v218 = _mm_shuffle_ps(v215, v215, 201);
          v219 = _mm_shuffle_ps(v216, v217, 68);
          v220 = _mm_mul_ps(v207, v218);
          v221 = _mm_mul_ps(_mm_sub_ps(v28.m_quad, *(__m128 *)((char *)&v582.m_verticesA[1].m_quad + 8)), v218);
          v222 = _mm_shuffle_ps(v220, v221, 68);
          v223 = _mm_add_ps(
                   _mm_shuffle_ps(_mm_shuffle_ps(v220, v221, 238), _mm_shuffle_ps(v216, v217, 238), 136),
                   _mm_add_ps(_mm_shuffle_ps(v222, v219, 221), _mm_shuffle_ps(v222, v219, 136)));
          v224 = _mm_movemask_ps(_mm_cmpltps(v18, v223));
          if ( v224 == 15 )
          {
            v402 = _mm_mul_ps(v207, v19);
            v403 = _mm_shuffle_ps(v223, v223, 0);
            v404 = _mm_add_ps(_mm_shuffle_ps(v223, v223, 85), v403);
            v405 = _mm_rcp_ps(v404);
            v653 = v404;
            v733 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v405, v404)), v405), v403);
            v387 = _mm_xor_ps(
                     (__m128)_mm_slli_epi32(
                               _mm_srli_epi32(
                                 (__m128i)_mm_add_ps(
                                            _mm_add_ps(_mm_shuffle_ps(v402, v402, 85), _mm_shuffle_ps(v402, v402, 0)),
                                            _mm_shuffle_ps(v402, v402, 170)),
                                 0x1Fu),
                               0x1Fu),
                     v19);
            *(__m128 *)((char *)&v582.m_closestPointOnEdgeA.m_quad + 8) = _mm_add_ps(
                                                                            _mm_mul_ps(
                                                                              _mm_sub_ps(
                                                                                *(__m128 *)((char *)&v582.m_verticesA[1].m_quad
                                                                                          + 8),
                                                                                v30),
                                                                              v733),
                                                                            v30);
            goto LABEL_148;
          }
          v225 = v224 - 7;
          if ( !v225 )
          {
            v28.m_quad = *(__m128 *)((char *)&v582.m_verticesBinA[1] + 8);
            v582.m_checkTriangleDots = *(hkVector4f *)((char *)&v582.m_verticesBinA[1] + 8);
            *(hkcdVertex *)((char *)v582.m_verticesBinA + 8) = *(hkcdVertex *)((char *)&v582.m_verticesBinA[1] + 8);
LABEL_92:
            dimB.m_storage = 1;
LABEL_135:
            v516 = _mm_sub_ps(v30, v28.m_quad);
            v517 = _mm_sub_ps(*(__m128 *)((char *)&v582.m_verticesA[1].m_quad + 8), v28.m_quad);
            v518 = _mm_sub_ps(*(__m128 *)((char *)&v582.m_verticesA[1].m_quad + 8), v30);
            v519 = _mm_mul_ps(v517, v518);
            v520 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v519, v519, 85), _mm_shuffle_ps(v519, v519, 0)),
                     _mm_shuffle_ps(v519, v519, 170));
            v521 = _mm_mul_ps(v516, v518);
            v522 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v521, v521, 85), _mm_shuffle_ps(v521, v521, 0)),
                     _mm_shuffle_ps(v521, v521, 170));
            if ( (float)(v522.m128_f32[0] * v520.m128_f32[0]) >= v18.m128_f32[0] )
            {
              v529 = _mm_cmpleps(v520, v18);
              dimA.m_storage = 1;
              v30 = _mm_or_ps(
                      _mm_andnot_ps(v529, v30),
                      _mm_and_ps(*(__m128 *)((char *)&v582.m_verticesA[1].m_quad + 8), v529));
              *(__m128 *)&v581[8] = v30;
              *(__m128 *)((char *)&v582.m_verticesA[0].m_quad + 8) = v30;
              v387 = _mm_sub_ps(v30, v28.m_quad);
            }
            else
            {
              dimA.m_storage = 2;
              v523 = _mm_sub_ps(_mm_mul_ps(v516, v520), _mm_mul_ps(v517, v522));
              v524 = _mm_mul_ps(v518, v518);
              v525 = _mm_shuffle_ps(v518, v518, 201);
              v526 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v523, v523, 201), v518), _mm_mul_ps(v523, v525));
              v663 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v524, v524, 85), _mm_shuffle_ps(v524, v524, 0)),
                       _mm_shuffle_ps(v524, v524, 170));
              v527 = _mm_shuffle_ps(v526, v526, 201);
              v718 = _mm_rcp_ps(v663);
              v528 = _mm_sub_ps(_mm_mul_ps(v527, v525), _mm_mul_ps(v527, v518));
              v387 = _mm_mul_ps(_mm_shuffle_ps(v528, v528, 201), v718);
            }
LABEL_148:
            *(__m128 *)&v582.m_lastDimB.m_storage = v387;
LABEL_149:
            v19 = *(__m128 *)&v582.m_lastDimB.m_storage;
            *(&v582.m_lastDimB + 2) = dimB;
            v260 = 0;
            goto LABEL_65;
          }
          v226 = v225 - 4;
          if ( !v226 )
            goto LABEL_92;
          v227 = v226 - 2;
          if ( !v227 )
          {
            v30 = *(__m128 *)((char *)&v582.m_verticesA[1].m_quad + 8);
            *(hkcdVertex *)&v581[8] = *(hkcdVertex *)((char *)&v582.m_verticesA[1] + 8);
            *(hkcdVertex *)((char *)v582.m_verticesA + 8) = *(hkcdVertex *)((char *)&v582.m_verticesA[1] + 8);
LABEL_88:
            dimA.m_storage = 1;
LABEL_89:
            v388 = _mm_sub_ps(v28.m_quad, v30);
            v389 = _mm_sub_ps(*(__m128 *)((char *)&v582.m_verticesBinA[1].m_quad + 8), v30);
            v390 = _mm_sub_ps(*(__m128 *)((char *)&v582.m_verticesBinA[1].m_quad + 8), v28.m_quad);
            v391 = _mm_mul_ps(v389, v390);
            v392 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v391, v391, 85), _mm_shuffle_ps(v391, v391, 0)),
                     _mm_shuffle_ps(v391, v391, 170));
            v393 = _mm_mul_ps(v390, v388);
            v394 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v393, v393, 85), _mm_shuffle_ps(v393, v393, 0)),
                     _mm_shuffle_ps(v393, v393, 170));
            if ( (float)(v394.m128_f32[0] * v392.m128_f32[0]) >= v18.m128_f32[0] )
            {
              v538 = _mm_cmpleps(v392, v18);
              v395 = 1;
              v28.m_quad = _mm_or_ps(
                             _mm_and_ps(*(__m128 *)((char *)&v582.m_verticesBinA[1].m_quad + 8), v538),
                             _mm_andnot_ps(v538, v28.m_quad));
              v582.m_checkTriangleDots = (hkVector4f)v28.m_quad;
              v387 = _mm_sub_ps(v30, v28.m_quad);
              *(hkVector4f *)((char *)&v582.m_verticesBinA[0].0 + 8) = (hkVector4f)v28.m_quad;
            }
            else
            {
              v395 = 2;
              v396 = _mm_sub_ps(_mm_mul_ps(v392, v388), _mm_mul_ps(v394, v389));
              v397 = _mm_mul_ps(v390, v390);
              v398 = _mm_shuffle_ps(v390, v390, 201);
              v668 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v397, v397, 85), _mm_shuffle_ps(v397, v397, 0)),
                       _mm_shuffle_ps(v397, v397, 170));
              v399 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v396, v396, 201), v390), _mm_mul_ps(v398, v396));
              v703 = _mm_rcp_ps(v668);
              v400 = _mm_shuffle_ps(v399, v399, 201);
              v401 = _mm_sub_ps(_mm_mul_ps(v400, v390), _mm_mul_ps(v398, v400));
              v387 = _mm_mul_ps(_mm_shuffle_ps(v401, v401, 201), v703);
            }
            dimB.m_storage = v395;
            goto LABEL_148;
          }
          if ( v227 == 1 )
            goto LABEL_88;
          v228 = _mm_mul_ps(v209, v208);
          v229 = _mm_sub_ps(v28.m_quad, v30);
          v230 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v228, v228, 85), _mm_shuffle_ps(v228, v228, 0)),
                   _mm_shuffle_ps(v228, v228, 170));
          v231 = _mm_mul_ps(v229, v208);
          v232 = _mm_mul_ps(v229, v209);
          v233 = _mm_mul_ps(v209, v209);
          v234 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v231, v231, 85), _mm_shuffle_ps(v231, v231, 0)),
                   _mm_shuffle_ps(v231, v231, 170));
          v235 = _mm_mul_ps(v208, v208);
          v236 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v232, v232, 85), _mm_shuffle_ps(v232, v232, 0)),
                   _mm_shuffle_ps(v232, v232, 170));
          v644 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v235, v235, 85), _mm_shuffle_ps(v235, v235, 0)),
                   _mm_shuffle_ps(v235, v235, 170));
          v688 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v233, v233, 85), _mm_shuffle_ps(v233, v233, 0)),
                   _mm_shuffle_ps(v233, v233, 170));
          v237 = _mm_max_ps(_mm_sub_ps(_mm_mul_ps(v688, v644), _mm_mul_ps(v230, v230)), *(__m128 *)&epsilon);
          v238 = _mm_rcp_ps(v237);
          v646 = v237;
          v239 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v238, v237)), v238);
          v240 = _mm_rcp_ps(v688);
          v713 = v239;
          v241 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v240, v688)), v240);
          v242 = _mm_rcp_ps(v644);
          v648 = v241;
          v243 = _mm_sub_ps(_mm_mul_ps(v688, v234), _mm_mul_ps(v236, v230));
          v693 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v242, v644)), v242);
          v244 = _mm_cmpltps(v243, v237);
          v245 = _mm_cmpleps(v237, *(__m128 *)&epsilon);
          v246 = _mm_mul_ps(
                   _mm_or_ps(
                     _mm_andnot_ps(
                       v245,
                       _mm_mul_ps(
                         _mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_andnot_ps(v244, v237), _mm_and_ps(v243, v244))),
                         v239)),
                     _mm_and_ps(v245, *(__m128 *)v581)),
                   _mm_mul_ps(v241, v230));
          v247 = _mm_mul_ps(v693, v230);
          v248 = _mm_mul_ps(v693, v234);
          v32 = *(__m128 *)v581;
          v249 = _mm_sub_ps(v246, _mm_mul_ps(v241, v236));
          v18 = 0i64;
          v250 = _mm_cmpltps(v249, *(__m128 *)v581);
          v251 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v249, v250), _mm_andnot_ps(v250, *(__m128 *)v581)));
          v252 = _mm_add_ps(_mm_mul_ps(v247, v251), v248);
          v253 = _mm_cmpltps(v252, *(__m128 *)v581);
          v254 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v252, v253), _mm_andnot_ps(v253, *(__m128 *)v581)));
          v255 = _mm_movemask_ps(
                   _mm_cmpeqps(
                     _mm_movelh_ps(_mm_unpacklo_ps(v254, v254), _mm_unpacklo_ps(v251, v251)),
                     (__m128)xmmword_141A71330));
          *(__m128 *)((char *)&v582.m_closestPointOnEdgeA.m_quad + 8) = _mm_add_ps(_mm_mul_ps(v254, v585), v30);
          if ( !v255 )
          {
            v386 = _mm_mul_ps(v207, v19);
            v387 = _mm_xor_ps(
                     (__m128)_mm_slli_epi32(
                               _mm_srli_epi32(
                                 (__m128i)_mm_add_ps(
                                            _mm_add_ps(_mm_shuffle_ps(v386, v386, 85), _mm_shuffle_ps(v386, v386, 0)),
                                            _mm_shuffle_ps(v386, v386, 170)),
                                 0x1Fu),
                               0x1Fu),
                     v19);
            goto LABEL_148;
          }
          if ( v255 & 1 )
          {
            v30 = *(__m128 *)&v581[16];
            dimA.m_storage = 1;
            *(_OWORD *)&v581[8] = *(_OWORD *)&v581[16];
            *(hkcdVertex *)((char *)v582.m_verticesA + 8) = *(hkcdVertex *)&v581[8];
          }
          else
          {
            v258 = dimA.m_storage;
            if ( v255 & 2 )
              v258 = 1;
            dimA.m_storage = v258;
          }
          if ( v255 & 4 )
          {
            v28.m_quad = *(__m128 *)((char *)&v582.m_verticesBinA[1] + 8);
            dimB.m_storage = 1;
            v582.m_checkTriangleDots = *(hkVector4f *)((char *)&v582.m_verticesBinA[1] + 8);
            *(hkcdVertex *)((char *)v582.m_verticesBinA + 8) = *(hkcdVertex *)((char *)&v582.m_verticesBinA[1] + 8);
          }
          else
          {
            v259 = dimB.m_storage;
            if ( v255 & 8 )
              v259 = 1;
            dimB.m_storage = v259;
          }
          v31 = (dimB.m_storage | 8 * dimA.m_storage) - 9;
          if ( v31 > 0x18 )
          {
LABEL_64:
            v260 = 1;
            goto LABEL_65;
          }
          continue;
        }
        if ( dimA.m_storage == 2 )
        {
          v19 = *(__m128 *)&v582.m_lastDimB.m_storage;
          dimA.m_storage = 1;
          *(&v582.m_lastDimB + 2) = dimB;
        }
        else
        {
          v19 = *(__m128 *)&v582.m_lastDimB.m_storage;
          dimB.m_storage = 1;
          *((_DWORD *)&v582.m_lastDimB + 2) = 1;
        }
        v260 = 0;
LABEL_65:
        v261 = _mm_mul_ps(v19, v19);
        v262 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v261, v261, 85), _mm_shuffle_ps(v261, v261, 0)),
                 _mm_shuffle_ps(v261, v261, 170));
        v263 = _mm_rsqrt_ps(v262);
        v673 = v262;
        v264 = _mm_andnot_ps(
                 _mm_cmpleps(v262, v18),
                 _mm_mul_ps(
                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v263, v262), v263)),
                   _mm_mul_ps(v263, *(__m128 *)_xmm)));
        v265 = _mm_mul_ps(_mm_sub_ps(v30, v28.m_quad), v19);
        v19 = _mm_mul_ps(v19, v264);
        *(__m128 *)&v582.m_lastDimB.m_storage = v19;
        if ( !v260
          && (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v265, v265, 85))
                                   + COERCE_FLOAT(_mm_shuffle_ps(v265, v265, 0)))
                           + COERCE_FLOAT(_mm_shuffle_ps(v265, v265, 170)))
                   * v264.m128_f32[0]) >= v603.m128_f32[0]
          && v262.m128_f32[0] >= (float)((float)(v603.m128_f32[0] * v603.m128_f32[0])
                                       * (float)(v603.m128_f32[0] * v603.m128_f32[0])) )
        {
          v266 = aTb->m_rotation.m_col2.m_quad;
          v267 = aTb->m_rotation.m_col0.m_quad;
          v268 = shapeA->m_quad;
          *(__m128 *)&v581[16] = v268;
          v269 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
          v270 = _mm_xor_ps(v269, v19);
          v589 = v270;
          v271 = _mm_xor_ps(v270, v269);
          v272 = v267;
          v273 = _mm_unpackhi_ps(v267, aTb->m_rotation.m_col1.m_quad);
          v274 = _mm_unpacklo_ps(v272, aTb->m_rotation.m_col1.m_quad);
          v608 = v268;
          v275 = _mm_shuffle_ps(v273, v266, 228);
          v609 = shapeA[1].m_quad;
          v276 = _mm_movelh_ps(v274, v266);
          v277 = _mm_movehl_ps(v276, v274);
          v278 = shapeA[2].m_quad;
          v279 = _mm_mul_ps(_mm_shuffle_ps(v271, v271, 85), _mm_shuffle_ps(v277, v266, 212));
          v610 = v278;
          v280 = shapeA[3].m_quad;
          v592 = v278;
          v611 = v280;
          v281 = *shapeB;
          v612 = v281;
          v282 = shapeB[1];
          v283 = v270;
          v613 = v282;
          v284 = shapeB[2];
          v583 = v609;
          v285 = _mm_add_ps(
                   _mm_add_ps(v279, _mm_mul_ps(_mm_shuffle_ps(v271, v271, 0), v276)),
                   _mm_mul_ps(_mm_shuffle_ps(v271, v271, 170), v275));
          v614 = v284;
          v286 = shapeB[3];
          v588 = v284;
          v601 = v280;
          v602 = v281;
          v287 = _mm_mul_ps(v268, v270);
          v596 = v282;
          v600 = v286;
          v615 = v286;
          v634 = v270;
          v591 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v287, v287, 85), _mm_shuffle_ps(v287, v287, 0)),
                   _mm_shuffle_ps(v287, v287, 170));
          v604 = v591;
          v288 = _mm_mul_ps(v609, v270);
          v585 = v285;
          v635 = v285;
          v586 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v288, v288, 85), _mm_shuffle_ps(v288, v288, 0)),
                   _mm_shuffle_ps(v288, v288, 170));
          v605 = v586;
          v289 = v598 - 4;
          v290 = v595 - 4;
          v291 = (__int64)&shapeA[4];
          v292 = _mm_mul_ps(v592, v270);
          v293 = shapeB + 4;
          v294 = v595 - 4;
          v295 = _mm_shuffle_ps(v292, v292, 0);
          v296 = _mm_shuffle_ps(v292, v292, 85);
          v297 = _mm_shuffle_ps(v292, v292, 170);
          if ( v598 - 4 < v595 - 4 )
            v294 = v598 - 4;
          v298 = _mm_add_ps(_mm_add_ps(v296, v295), v297);
          v299 = _mm_mul_ps(v280, v270);
          v587 = v298;
          v606 = v298;
          v300 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v299, v299, 85), _mm_shuffle_ps(v299, v299, 0)),
                   _mm_shuffle_ps(v299, v299, 170));
          v301 = _mm_mul_ps(v281, v285);
          *(__m128 *)v581 = v300;
          v607 = v300;
          v302 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v301, v301, 85), _mm_shuffle_ps(v301, v301, 0)),
                   _mm_shuffle_ps(v301, v301, 170));
          v303 = _mm_mul_ps(v282, v285);
          v599 = v302;
          v616 = v302;
          v304 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v303, v303, 85), _mm_shuffle_ps(v303, v303, 0)),
                   _mm_shuffle_ps(v303, v303, 170));
          v305 = _mm_mul_ps(v588, v285);
          v590 = v304;
          v617 = v304;
          v306 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v305, v305, 85), _mm_shuffle_ps(v305, v305, 0)),
                   _mm_shuffle_ps(v305, v305, 170));
          v307 = _mm_mul_ps(v286, v285);
          v593 = v306;
          v618 = v306;
          v584 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v307, v307, 85), _mm_shuffle_ps(v307, v307, 0)),
                   _mm_shuffle_ps(v307, v307, 170));
          v619 = v584;
          if ( v294 > 0 )
          {
            v308 = ((unsigned int)(v294 - 1) >> 2) + 1;
            v309 = v308;
            v308 *= 4;
            v289 -= v308;
            v290 -= v308;
            do
            {
              v310 = _mm_mul_ps(v283, *(__m128 *)v291);
              v654 = *(__m128 *)v291;
              v311 = *(__m128 *)(v291 + 16);
              v621 = v654;
              v655 = v311;
              v312 = *(__m128 *)(v291 + 32);
              v625 = v311;
              v313 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v310, v310, 85), _mm_shuffle_ps(v310, v310, 0)),
                       _mm_shuffle_ps(v310, v310, 170));
              v656 = v312;
              v314 = _mm_mul_ps(v589, v311);
              v657 = *(__m128 *)(v291 + 48);
              v315 = *v293;
              v627 = v312;
              v316 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v314, v314, 85), _mm_shuffle_ps(v314, v314, 0)),
                       _mm_shuffle_ps(v314, v314, 170));
              v659 = v315;
              v317 = _mm_mul_ps(v589, v312);
              v660 = v293[1];
              v318 = v293[2];
              v629 = v657;
              v622 = v315;
              v319 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v317, v317, 85), _mm_shuffle_ps(v317, v317, 0)),
                       _mm_shuffle_ps(v317, v317, 170));
              v661 = v318;
              v320 = v293[3];
              v321 = _mm_mul_ps(v589, v657);
              v623 = v660;
              v624 = v318;
              v628 = v320;
              v662 = v320;
              v322 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v321, v321, 85), _mm_shuffle_ps(v321, v321, 0)),
                       _mm_shuffle_ps(v321, v321, 170));
              v620 = v313;
              v664 = v313;
              v323 = _mm_mul_ps(v585, v315);
              v665 = v316;
              v666 = v319;
              v667 = v322;
              v626 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v323, v323, 85), _mm_shuffle_ps(v323, v323, 0)),
                       _mm_shuffle_ps(v323, v323, 170));
              v669 = v626;
              v324 = _mm_mul_ps(v585, v660);
              v675 = v586;
              v676 = v587;
              v677 = *(_OWORD *)v581;
              v325 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v324, v324, 85), _mm_shuffle_ps(v324, v324, 0)),
                       _mm_shuffle_ps(v324, v324, 170));
              v681 = v593;
              v670 = v325;
              v326 = _mm_mul_ps(v585, v318);
              v682 = v584;
              v327 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v326, v326, 85), _mm_shuffle_ps(v326, v326, 0)),
                       _mm_shuffle_ps(v326, v326, 170));
              v328 = _mm_mul_ps(v585, v320);
              v329 = (__m128i)_mm_cmpltps(v593, v327);
              v674 = v591;
              v671 = v327;
              v330 = (__m128i)_mm_cmpltps(v591, v313);
              v331 = (__m128i)_mm_cmpltps(v586, v316);
              v332 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v328, v328, 85), _mm_shuffle_ps(v328, v328, 0)),
                       _mm_shuffle_ps(v328, v328, 170));
              v333 = (__m128i)_mm_cmpltps(v587, v319);
              v679 = v599;
              v334 = (__m128i)_mm_cmpltps(*(__m128 *)v581, v322);
              v335 = (__m128i)_mm_cmpltps(v584, v332);
              v680 = v590;
              v336 = (__m128i)_mm_cmpltps(v599, v626);
              v337 = _mm_andnot_ps((__m128)v330, v591);
              v672 = v332;
              v338 = _mm_and_ps((__m128)v330, v620);
              v339 = (__m128i)_mm_cmpltps(v590, v325);
              _mm_store_si128((__m128i *)&v684, v330);
              _mm_store_si128((__m128i *)&v685, v331);
              _mm_store_si128((__m128i *)&v686, v333);
              v591 = _mm_or_ps(v337, v338);
              v604 = v591;
              v340 = _mm_andnot_ps((__m128)v331, v586);
              _mm_store_si128((__m128i *)&v687, v334);
              _mm_store_si128((__m128i *)&v689, v336);
              v586 = _mm_or_ps(_mm_and_ps((__m128)v331, v316), v340);
              v605 = v586;
              _mm_store_si128((__m128i *)&v690, v339);
              _mm_store_si128((__m128i *)&v691, v329);
              _mm_store_si128((__m128i *)&v692, v335);
              v587 = _mm_or_ps(_mm_and_ps((__m128)v333, v319), _mm_andnot_ps((__m128)v333, v587));
              v606 = v587;
              *(__m128 *)v581 = _mm_or_ps(_mm_and_ps((__m128)v334, v322), _mm_andnot_ps((__m128)v334, *(__m128 *)v581));
              v607 = *(__m128 *)v581;
              *(__m128 *)&v581[16] = _mm_or_ps(
                                       _mm_andnot_ps((__m128)v330, *(__m128 *)&v581[16]),
                                       _mm_and_ps((__m128)v330, v621));
              v608 = *(__m128 *)&v581[16];
              v592 = _mm_or_ps(_mm_andnot_ps((__m128)v333, v592), _mm_and_ps((__m128)v333, v627));
              v610 = v592;
              v583 = _mm_or_ps(_mm_andnot_ps((__m128)v331, v583), _mm_and_ps((__m128)v331, v625));
              v609 = v583;
              v599 = _mm_or_ps(_mm_and_ps((__m128)v336, v626), _mm_andnot_ps((__m128)v336, v599));
              v616 = v599;
              v590 = _mm_or_ps(_mm_and_ps((__m128)v339, v325), _mm_andnot_ps((__m128)v339, v590));
              v617 = v590;
              v601 = _mm_or_ps(_mm_andnot_ps((__m128)v334, v601), _mm_and_ps((__m128)v334, v629));
              v611 = v601;
              v596 = _mm_or_ps(_mm_andnot_ps((__m128)v339, v596), _mm_and_ps((__m128)v339, v623));
              v613 = v596;
              v593 = _mm_or_ps(_mm_and_ps((__m128)v329, v327), _mm_andnot_ps((__m128)v329, v593));
              v618 = v593;
              v584 = _mm_or_ps(_mm_and_ps((__m128)v335, v332), _mm_andnot_ps((__m128)v335, v584));
              v619 = v584;
              v602 = _mm_or_ps(_mm_andnot_ps((__m128)v336, v602), _mm_and_ps((__m128)v336, v622));
              v612 = v602;
              v588 = _mm_or_ps(_mm_andnot_ps((__m128)v329, v588), _mm_and_ps((__m128)v329, v624));
              v614 = v588;
              v283 = v589;
              v291 += 64i64;
              v293 += 4;
              v600 = _mm_or_ps(_mm_andnot_ps((__m128)v335, v600), _mm_and_ps((__m128)v335, v628));
              v615 = v600;
              --v309;
            }
            while ( v309 );
            v19 = *(__m128 *)&v582.m_lastDimB.m_storage;
            v30 = *(__m128 *)&v581[8];
            v302 = v599;
          }
          if ( v289 > 0 )
          {
            v341 = v591;
            v342 = v586;
            v343 = v587;
            v344 = (__m128 *)(v291 + 32);
            v345 = ((unsigned int)(v289 - 1) >> 2) + 1;
            do
            {
              v346 = v344[-2];
              v347 = _mm_mul_ps(v283, v346);
              v694 = v344[-2];
              v348 = v344[-1];
              v349 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v347, v347, 85), _mm_shuffle_ps(v347, v347, 0)),
                       _mm_shuffle_ps(v347, v347, 170));
              v695 = v348;
              v350 = *v344;
              v351 = _mm_mul_ps(v283, v348);
              v696 = v350;
              v352 = v344[1];
              v704 = v341;
              v705 = v342;
              v353 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v351, v351, 85), _mm_shuffle_ps(v351, v351, 0)),
                       _mm_shuffle_ps(v351, v351, 170));
              v354 = (__m128i)_mm_cmpltps(v342, v353);
              v699 = v349;
              v700 = v353;
              v355 = _mm_mul_ps(v283, v350);
              v706 = v343;
              v697 = v352;
              _mm_store_si128((__m128i *)&v710, v354);
              v701 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v355, v355, 85), _mm_shuffle_ps(v355, v355, 0)),
                       _mm_shuffle_ps(v355, v355, 170));
              v356 = _mm_mul_ps(v283, v352);
              v357 = (__m128i)_mm_cmpltps(v343, v701);
              v358 = _mm_and_ps(v701, (__m128)v357);
              _mm_store_si128((__m128i *)&v711, v357);
              v359 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v356, v356, 85), _mm_shuffle_ps(v356, v356, 0)),
                       _mm_shuffle_ps(v356, v356, 170));
              v707 = *(_OWORD *)v581;
              v360 = (__m128i)_mm_cmpltps(v341, v349);
              v361 = (__m128i)_mm_cmpltps(*(__m128 *)v581, v359);
              v702 = v359;
              _mm_store_si128((__m128i *)&v709, v360);
              _mm_store_si128((__m128i *)&v712, v361);
              v341 = _mm_or_ps(_mm_andnot_ps((__m128)v360, v341), _mm_and_ps(v349, (__m128)v360));
              v604 = v341;
              v342 = _mm_or_ps(_mm_andnot_ps((__m128)v354, v342), _mm_and_ps(v353, (__m128)v354));
              v605 = v342;
              v344 += 4;
              v362 = _mm_and_ps(v350, (__m128)v357);
              *(__m128 *)v581 = _mm_or_ps(_mm_andnot_ps((__m128)v361, *(__m128 *)v581), _mm_and_ps(v359, (__m128)v361));
              v607 = *(__m128 *)v581;
              v583 = _mm_or_ps(_mm_andnot_ps((__m128)v354, v583), _mm_and_ps(v348, (__m128)v354));
              v609 = v583;
              v343 = _mm_or_ps(_mm_andnot_ps((__m128)v357, v343), v358);
              *(__m128 *)&v581[16] = _mm_or_ps(
                                       _mm_andnot_ps((__m128)v360, *(__m128 *)&v581[16]),
                                       _mm_and_ps(v346, (__m128)v360));
              v608 = *(__m128 *)&v581[16];
              v363 = _mm_andnot_ps((__m128)v357, v592);
              v283 = v589;
              v606 = v343;
              v601 = _mm_or_ps(_mm_andnot_ps((__m128)v361, v601), _mm_and_ps(v352, (__m128)v361));
              v611 = v601;
              v592 = _mm_or_ps(v363, v362);
              v610 = v592;
              --v345;
            }
            while ( v345 );
            v587 = v343;
            v302 = v599;
            v586 = v342;
            v30 = *(__m128 *)&v581[8];
            v591 = v341;
            v19 = *(__m128 *)&v582.m_lastDimB.m_storage;
          }
          if ( v290 <= 0 )
          {
            v384 = v596;
            v385 = v600;
          }
          else
          {
            v364 = v590;
            v365 = v593;
            v366 = v293 + 2;
            v367 = ((unsigned int)(v290 - 1) >> 2) + 1;
            do
            {
              v368 = v366[-2];
              v714 = v368;
              v369 = v366[-1];
              v370 = _mm_mul_ps(v585, v368);
              v715 = v369;
              v371 = *v366;
              v372 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v370, v370, 85), _mm_shuffle_ps(v370, v370, 0)),
                       _mm_shuffle_ps(v370, v370, 170));
              v716 = v371;
              v373 = v366[1];
              v374 = _mm_mul_ps(v585, v369);
              v724 = v302;
              v725 = v364;
              v719 = v372;
              v726 = v365;
              v720 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v374, v374, 85), _mm_shuffle_ps(v374, v374, 0)),
                       _mm_shuffle_ps(v374, v374, 170));
              v717 = v373;
              v375 = _mm_mul_ps(v585, v371);
              v376 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v375, v375, 85), _mm_shuffle_ps(v375, v375, 0)),
                       _mm_shuffle_ps(v375, v375, 170));
              v377 = _mm_mul_ps(v585, v373);
              v378 = (__m128i)_mm_cmpltps(v364, v720);
              v379 = (__m128i)_mm_cmpltps(v365, v376);
              v721 = v376;
              v380 = _mm_and_ps(v720, (__m128)v378);
              _mm_store_si128((__m128i *)&v730, v378);
              _mm_store_si128((__m128i *)&v731, v379);
              v381 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v377, v377, 85), _mm_shuffle_ps(v377, v377, 0)),
                       _mm_shuffle_ps(v377, v377, 170));
              v727 = v584;
              v382 = (__m128i)_mm_cmpltps(v302, v372);
              v383 = (__m128i)_mm_cmpltps(v584, v381);
              v722 = v381;
              _mm_store_si128((__m128i *)&v729, v382);
              _mm_store_si128((__m128i *)&v732, v383);
              v302 = _mm_or_ps(_mm_andnot_ps((__m128)v382, v302), _mm_and_ps(v372, (__m128)v382));
              v616 = v302;
              v364 = _mm_or_ps(_mm_andnot_ps((__m128)v378, v364), v380);
              v617 = v364;
              v366 += 4;
              v584 = _mm_or_ps(_mm_andnot_ps((__m128)v383, v584), _mm_and_ps(v381, (__m128)v383));
              v619 = v584;
              v602 = _mm_or_ps(_mm_and_ps(v368, (__m128)v382), _mm_andnot_ps((__m128)v382, v602));
              v612 = v602;
              v384 = _mm_or_ps(_mm_and_ps(v369, (__m128)v378), _mm_andnot_ps((__m128)v378, v596));
              v596 = v384;
              v613 = v384;
              v588 = _mm_or_ps(_mm_and_ps(v371, (__m128)v379), _mm_andnot_ps((__m128)v379, v588));
              v614 = v588;
              v385 = _mm_or_ps(_mm_and_ps(v373, (__m128)v383), _mm_andnot_ps((__m128)v383, v600));
              v365 = _mm_or_ps(_mm_andnot_ps((__m128)v379, v365), _mm_and_ps(v376, (__m128)v379));
              v600 = v385;
              v615 = v385;
              v618 = v365;
              --v367;
            }
            while ( v367 );
            v593 = v365;
            v30 = *(__m128 *)&v581[8];
            v590 = v364;
            v19 = *(__m128 *)&v582.m_lastDimB.m_storage;
          }
          v539 = _mm_cmpltps(v587, *(__m128 *)v581);
          v540 = _mm_cmpltps(v591, v586);
          v541 = _mm_cmpltps(v593, v584);
          v542 = _mm_cmpltps(v302, v590);
          v543 = _mm_cmpltps(
                   _mm_or_ps(_mm_and_ps(v539, *(__m128 *)v581), _mm_andnot_ps(v539, v587)),
                   _mm_or_ps(_mm_andnot_ps(v540, v591), _mm_and_ps(v540, v586)));
          v544 = _mm_cmpltps(
                   _mm_or_ps(_mm_and_ps(v541, v584), _mm_andnot_ps(v541, v593)),
                   _mm_or_ps(_mm_and_ps(v542, v590), _mm_andnot_ps(v542, v302)));
          v545 = _mm_or_ps(
                   _mm_andnot_ps(v544, _mm_or_ps(_mm_and_ps(v385, v541), _mm_andnot_ps(v541, v588))),
                   _mm_and_ps(_mm_or_ps(_mm_and_ps(v384, v542), _mm_andnot_ps(v542, v602)), v544));
          v546 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v545, v545, 0), aTb->m_rotation.m_col0.m_quad),
                       _mm_mul_ps(_mm_shuffle_ps(v545, v545, 85), aTb->m_rotation.m_col1.m_quad)),
                     _mm_mul_ps(_mm_shuffle_ps(v545, v545, 170), aTb->m_rotation.m_col2.m_quad)),
                   aTb->m_translation.m_quad);
          v547 = _mm_or_ps(
                   _mm_andnot_ps(v543, _mm_or_ps(_mm_and_ps(v601, v539), _mm_andnot_ps(v539, v592))),
                   _mm_and_ps(_mm_or_ps(_mm_and_ps(v583, v540), _mm_andnot_ps(v540, *(__m128 *)&v581[16])), v543));
          v548 = _mm_shuffle_ps(v546, _mm_unpackhi_ps(v546, v545), 196);
          v549 = _mm_mul_ps(_mm_sub_ps(v547, v548), v19);
          v550 = _mm_mul_ps(_mm_sub_ps(v547, v30), v589);
          v551 = _mm_mul_ps(_mm_sub_ps(v548, v582.m_checkTriangleDots.m_quad), v19);
          v552 = _mm_unpacklo_ps(v549, v550);
          v553 = _mm_movelh_ps(v552, v551);
          v554 = _mm_mul_ps(_mm_sub_ps(v547, *(__m128 *)((char *)&v582.m_verticesA[1].m_quad + 8)), v589);
          v555 = _mm_add_ps(
                   _mm_shuffle_ps(_mm_unpackhi_ps(v549, v550), v551, 228),
                   _mm_add_ps(v553, _mm_shuffle_ps(_mm_movehl_ps(v553, v552), v551, 212)));
          v556 = _mm_mul_ps(_mm_sub_ps(v547, *(__m128 *)((char *)&v582.m_verticesA[2].m_quad + 8)), v589);
          v557 = _mm_mul_ps(_mm_sub_ps(v548, *(__m128 *)((char *)&v582.m_verticesBinA[1].m_quad + 8)), v19);
          v558 = _mm_shuffle_ps(v554, v556, 68);
          v559 = _mm_mul_ps(_mm_sub_ps(v548, *(__m128 *)((char *)&v582.m_verticesBinA[2].m_quad + 8)), v19);
          v560 = _mm_shuffle_ps(v557, v559, 68);
          v561 = _mm_shuffle_ps(v557, v559, 238);
          v562 = _mm_add_ps(_mm_shuffle_ps(v558, v560, 221), _mm_shuffle_ps(v558, v560, 136));
          v29 = v603;
          v563 = _mm_cmpltps(_mm_add_ps(_mm_shuffle_ps(_mm_shuffle_ps(v554, v556, 238), v561, 136), v562), v603);
          switch ( _mm_movemask_ps(
                     _mm_cmpltps(
                       _mm_movelh_ps(
                         _mm_unpacklo_ps(aTb[1].m_rotation.m_col1.m_quad, v603),
                         _mm_unpacklo_ps(v603, v603)),
                       v555)) & 7 )
          {
            case 1:
            case 3:
            case 5:
            case 7:
              v27 = 5;
              v741->m_distance.m_real = _mm_shuffle_ps(v555, v555, 0);
              v741->m_normalInA.m_quad = v19;
              goto LABEL_173;
            case 2:
              goto LABEL_153;
            case 4:
              goto LABEL_155;
            case 6:
              if ( COERCE_FLOAT(_mm_shuffle_ps(v555, v555, 170)) > COERCE_FLOAT(_mm_shuffle_ps(v555, v555, 85)) )
              {
LABEL_155:
                if ( _mm_movemask_ps(v563) & hkcdGskBase::dimToMaskZ[dimB.m_storage] )
                {
LABEL_158:
                  v564 = _mm_mul_ps(_mm_sub_ps(v30, v582.m_checkTriangleDots.m_quad), v19);
                  v741->m_normalInA.m_quad = v19;
                  v565 = _mm_add_ps(
                           _mm_add_ps(_mm_shuffle_ps(v564, v564, 85), _mm_shuffle_ps(v564, v564, 0)),
                           _mm_shuffle_ps(v564, v564, 170));
                  v741->m_distance.m_real = v565;
                  if ( dimA.m_storage == 1 )
                  {
                    v741->m_pointAinA = *(hkVector4f *)((char *)v582.m_verticesA + 8);
                  }
                  else if ( dimB.m_storage == 1 )
                  {
                    v741->m_pointAinA.m_quad = _mm_add_ps(
                                                 _mm_mul_ps(v565, v19),
                                                 *(__m128 *)((char *)&v582.m_verticesBinA[0].m_quad + 8));
                  }
                  else
                  {
                    v741->m_pointAinA = *(hkVector4f *)((char *)&v582.m_closestPointOnEdgeA + 8);
                  }
                  goto LABEL_173;
                }
                v18 = 0i64;
                *(__m128 *)((char *)&v582.m_verticesBinA[0].m_quad + 16 * dimB.m_storage++ + 8) = v548;
                v28.m_quad = *(__m128 *)((char *)v582.m_verticesBinA + 8);
              }
              else
              {
LABEL_153:
                if ( _mm_movemask_ps(v563) & hkcdGskBase::dimToMaskY[dimA.m_storage] )
                  goto LABEL_158;
                *(__m128 *)((char *)&v582.m_verticesA[0].m_quad + 16 * dimA.m_storage++ + 8) = v547;
                v28.m_quad = *(__m128 *)((char *)v582.m_verticesBinA + 8);
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
          v566 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
          v567 = v566[1];
          if ( v567 < v566[3] )
          {
            *(_QWORD *)v567 = "TtPenetration";
            v568 = __rdtsc();
            *(_DWORD *)(v567 + 8) = v568;
            v566[1] = v567 + 16;
          }
          v569 = hkcdGskBase::handlePenetration(
                   (hkcdGskBase *)((char *)&v582 + 8),
                   &shapeInterface,
                   &shapeA,
                   &shapeB,
                   aTb,
                   &dimA,
                   &dimB,
                   v741,
                   &supportOut);
          v570 = (_QWORD *)v566[1];
          v27 = v569;
          if ( (unsigned __int64)v570 < v566[3] )
          {
            *v570 = "Et";
            v571 = __rdtsc();
            v572 = (signed __int64)(v570 + 2);
            *(_DWORD *)(v572 - 8) = v571;
            v566[1] = v572;
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
        v573 = dimA.m_storage;
        v574 = dimB.m_storage;
        v575 = v582.m_verticesBinA[2].m_quad.m128_i8[4];
        v576 = v582.m_verticesA[1].m_quad.m128_i8[4];
        v577 = v582.m_verticesA[2].m_quad.m128_i8[4];
        v578 = v582.m_verticesA[3].m_quad.m128_i8[4];
        v579 = v582.m_verticesBinA[1].m_quad.m128_i8[4];
        v740[(LOBYTE(dimA.m_storage) - 2) & 3] = v582.m_verticesBinA[3].m_quad.m128_i8[4];
        *v740 = v576;
        v740[1] = v577;
        v740[2] = v578;
        v740[v573] = v579;
        v740[v573 + 1] = v575;
        result = v27;
        v740[4] = v574 | 4 * (v27 | 16 * v573);
        return result;
      case 0x18u:
        v32 = g_vectorfConstants[0];
        v406 = v28.m_quad;
        v407 = (__m128 *)((char *)&v582.m_verticesA[0].m_quad + 8);
LABEL_96:
        v408 = v407[1];
        v409 = v407[2];
        v410 = _mm_sub_ps(v407[1], *v407);
        v411 = _mm_sub_ps(*v407, v409);
        v412 = _mm_sub_ps(v407[3], *v407);
        v413 = _mm_sub_ps(v407[2], v408);
        v414 = _mm_sub_ps(v407[3], v408);
        v415 = _mm_sub_ps(v407[3], v409);
        v416 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v414, v414, 201), v413),
                 _mm_mul_ps(_mm_shuffle_ps(v413, v413, 201), v414));
        v417 = _mm_shuffle_ps(v416, v416, 201);
        v418 = _mm_mul_ps(_mm_sub_ps(v406, v407[3]), v32);
        v419 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v415, v415, 201), v411),
                 _mm_mul_ps(_mm_shuffle_ps(v411, v411, 201), v415));
        v420 = _mm_shuffle_ps(v419, v419, 201);
        v421 = _mm_mul_ps(v418, v420);
        v422 = _mm_mul_ps(v420, v420);
        v423 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v412, v412, 201), v410),
                 _mm_mul_ps(_mm_shuffle_ps(v410, v410, 201), v412));
        v424 = _mm_mul_ps(v418, v417);
        v425 = _mm_mul_ps(v417, v417);
        v426 = _mm_shuffle_ps(v423, v423, 201);
        v427 = _mm_unpacklo_ps(v424, v421);
        v428 = _mm_unpackhi_ps(v424, v421);
        v429 = _mm_mul_ps(v418, v426);
        v430 = _mm_movelh_ps(v427, v429);
        v431 = _mm_shuffle_ps(_mm_movehl_ps(v430, v427), v429, 212);
        v432 = _mm_unpacklo_ps(v425, v422);
        v433 = _mm_mul_ps(v426, v426);
        v434 = (__m128i)_mm_add_ps(_mm_shuffle_ps(v428, v429, 228), _mm_add_ps(v430, v431));
        v435 = _mm_movelh_ps(v432, v433);
        v436 = _mm_add_ps(
                 _mm_shuffle_ps(_mm_unpackhi_ps(v425, v422), v433, 228),
                 _mm_add_ps(v435, _mm_shuffle_ps(_mm_movehl_ps(v435, v432), v433, 212)));
        v437 = _mm_cmpeqps(v18, v436);
        v438 = _mm_rcp_ps(v436);
        v658 = v436;
        v698 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v436, v438)), v438);
        v439 = _mm_or_ps(
                 _mm_andnot_ps(
                   v437,
                   _mm_mul_ps(_mm_mul_ps((__m128)_mm_srli_epi32(_mm_slli_epi32(v434, 1u), 1u), (__m128)v434), v698)),
                 _mm_and_ps(v437, (__m128)xmmword_141A712A0));
        v440 = _mm_max_ps(
                 _mm_shuffle_ps(v439, v439, 170),
                 _mm_max_ps(_mm_shuffle_ps(v439, v439, 85), _mm_shuffle_ps(v439, v439, 0)));
        v441 = (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                                      _mm_and_ps(
                                                                        _mm_cmpleps(v440, v439),
                                                                        (__m128)xmmword_141C1F4F0))];
        if ( v440.m128_f32[0] < COERCE_FLOAT(_mm_shuffle_ps((__m128)0x358637BEu, (__m128)0x358637BEu, 0)) )
          goto LABEL_64;
        LODWORD(retaddr) = 1066192077;
        v442 = _mm_or_ps(
                 _mm_and_ps((__m128)`hkVector4f::getComponent'::`2'::indexToMask[v441], (__m128)xmmword_141A712F0),
                 _mm_andnot_ps((__m128)`hkVector4f::getComponent'::`2'::indexToMask[v441], v439));
        if ( v440.m128_f32[0] <= (float)(fmax(
                                           COERCE_FLOAT(_mm_shuffle_ps(v442, v442, 170)),
                                           fmax(
                                             COERCE_FLOAT(_mm_shuffle_ps(v442, v442, 85)),
                                             COERCE_FLOAT(_mm_shuffle_ps(v442, v442, 0))))
                                       * COERCE_FLOAT(_mm_shuffle_ps((__m128)0x3F8CCCCDu, (__m128)0x3F8CCCCDu, 0))) )
        {
          v443 = 2;
          v444 = 1;
          v445 = 4;
          v446 = 16i64;
          v447 = 32i64;
          v448 = 0i64;
          v449 = 3i64;
          v450 = _mm_movemask_ps(_mm_cmpleps(v18, (__m128)v434));
          do
          {
            if ( v444 & v450 && v443 & v450 )
            {
              v451 = *(__m128 *)((char *)v407 + v447);
              v452 = _mm_sub_ps(v407[v448], v451);
              v453 = _mm_sub_ps(v407[3], v451);
              v454 = _mm_sub_ps(v406, v451);
              v455 = _mm_mul_ps(v453, v452);
              v456 = _mm_sub_ps(*(__m128 *)((char *)v407 + v446), v451);
              v457 = _mm_mul_ps(v454, v452);
              v458 = _mm_mul_ps(v453, v456);
              v459 = _mm_mul_ps(v454, v456);
              if ( (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v457, v457, 85))
                                         + COERCE_FLOAT(_mm_shuffle_ps(v457, v457, 0)))
                                 + COERCE_FLOAT(_mm_shuffle_ps(v457, v457, 170)))
                         * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v458, v458, 85))
                                         + COERCE_FLOAT(_mm_shuffle_ps(v458, v458, 0)))
                                 + COERCE_FLOAT(_mm_shuffle_ps(v458, v458, 170)))) >= (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v455, v455, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v455, v455, 0))) + COERCE_FLOAT(_mm_shuffle_ps(v455, v455, 170)))
                                                                                            * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v459, v459, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v459, v459, 0))) + COERCE_FLOAT(_mm_shuffle_ps(v459, v459, 170)))) )
                v443 = v444;
              v450 &= ~v443;
            }
            v443 = v445;
            v446 = v447;
            v445 = v444;
            v444 = __ROL4__(v444, 1);
            v447 = v448 * 16;
            ++v448;
            --v449;
          }
          while ( v449 );
          if ( v450 & 7 )
            v441 = (unsigned __int8)hkVector4Comparison_maskToFirstIndex[v450];
          else
            v441 = -1;
        }
        if ( v441 < 0 )
          goto LABEL_64;
        v407[v441] = v407[3];
        v28.m_quad = *(__m128 *)((char *)v582.m_verticesBinA + 8);
        v30 = *(__m128 *)((char *)&v582.m_verticesA[0].m_quad + 8);
        v582.m_checkTriangleDots = *(hkVector4f *)((char *)v582.m_verticesBinA + 8);
        *(hkcdVertex *)&v581[8] = *(hkcdVertex *)((char *)v582.m_verticesA + 8);
        if ( dimA.m_storage == 4 )
        {
          dimA.m_storage = 3;
LABEL_111:
          v460 = _mm_sub_ps(v30, *(__m128 *)((char *)&v582.m_verticesA[2].m_quad + 8));
          v461 = _mm_shuffle_ps(v460, v460, 201);
          v462 = _mm_sub_ps(v28.m_quad, *(__m128 *)((char *)&v582.m_verticesA[1].m_quad + 8));
          v463 = _mm_sub_ps(
                   *(__m128 *)((char *)&v582.m_verticesA[2].m_quad + 8),
                   *(__m128 *)((char *)&v582.m_verticesA[1].m_quad + 8));
          v464 = _mm_sub_ps(v28.m_quad, *(__m128 *)((char *)&v582.m_verticesA[2].m_quad + 8));
          v465 = _mm_shuffle_ps(v463, v463, 201);
          v466 = _mm_sub_ps(*(__m128 *)((char *)&v582.m_verticesA[1].m_quad + 8), v30);
          v467 = _mm_sub_ps(v28.m_quad, v30);
          v468 = _mm_sub_ps(_mm_mul_ps(v461, v463), _mm_mul_ps(v465, v460));
          v469 = _mm_shuffle_ps(v468, v468, 201);
          *(__m128 *)&v582.m_lastDimB.m_storage = v469;
          v470 = _mm_sub_ps(_mm_mul_ps(v465, v462), _mm_mul_ps(_mm_shuffle_ps(v462, v462, 201), v463));
          v471 = _mm_sub_ps(_mm_mul_ps(v461, v464), _mm_mul_ps(_mm_shuffle_ps(v464, v464, 201), v460));
          v472 = _mm_mul_ps(_mm_shuffle_ps(v470, v470, 201), v469);
          v473 = _mm_mul_ps(_mm_shuffle_ps(v471, v471, 201), v469);
          v474 = _mm_sub_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v466, v466, 201), v467),
                   _mm_mul_ps(_mm_shuffle_ps(v467, v467, 201), v466));
          v475 = _mm_unpacklo_ps(v472, v473);
          v476 = _mm_mul_ps(_mm_shuffle_ps(v474, v474, 201), v469);
          v477 = _mm_movelh_ps(v475, v476);
          v478 = _mm_add_ps(
                   _mm_shuffle_ps(_mm_unpackhi_ps(v472, v473), v476, 228),
                   _mm_add_ps(v477, _mm_shuffle_ps(_mm_movehl_ps(v477, v475), v476, 212)));
          v479 = _mm_movemask_ps(_mm_cmpltps(v478, v18)) & 7;
          if ( v479 == 7 )
          {
            v480 = _mm_mul_ps(_mm_sub_ps(v30, v28.m_quad), v469);
            if ( _mm_movemask_ps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v480, v480, 85), _mm_shuffle_ps(v480, v480, 0)),
                     _mm_shuffle_ps(v480, v480, 170))) )
            {
              *(hkcdVertex *)&v581[8] = *(hkcdVertex *)((char *)&v582.m_verticesA[1] + 8);
              *(hkcdVertex *)((char *)v582.m_verticesA + 8) = *(hkcdVertex *)((char *)&v582.m_verticesA[1] + 8);
              v481.m_quad = v30;
              v30 = *(__m128 *)((char *)&v582.m_verticesA[1].m_quad + 8);
              *(hkcdVertex *)((char *)&v582.m_verticesA[1] + 8) = (hkcdVertex)v481.m_quad;
              *(__m128 *)&v582.m_lastDimB.m_storage = _mm_xor_ps(
                                                        v469,
                                                        (__m128)_mm_shuffle_epi32(
                                                                  _mm_insert_epi16((__m128i)0i64, 0x8000u, 1),
                                                                  0));
              v478 = _mm_shuffle_ps(v478, v478, 225);
            }
          }
          *(__m128 *)((char *)&v582.m_checkTriangleDots.m_quad + 8) = v478;
          if ( v479 == 7 )
            goto LABEL_149;
          v482 = hkcdGskBase::maskToIndex[v479];
          if ( (signed int)v482 < 0 )
          {
            v483 = v482 + 8;
            if ( v483 < 3 )
            {
              *(__m128 *)((char *)&v582.m_verticesA[0].m_quad + 16 * v483 + 8) = *(__m128 *)((char *)&v582.m_verticesA[2]
                                                                                           + 8);
              goto LABEL_134;
            }
LABEL_144:
            dimA.m_storage = 1;
            dimB.m_storage = 1;
LABEL_145:
            v387 = _mm_sub_ps(v30, v28.m_quad);
            goto LABEL_148;
          }
          v508 = *(char *)(v482 + 5398197060i64);
          v509 = v482;
          v510 = *(char *)(v482 + 5398197062i64);
          v511 = *(__m128 *)((char *)&v582.m_verticesA[0].m_quad + 16 * v509 + 8);
          v512 = _mm_sub_ps(v28.m_quad, v511);
          v513 = _mm_sub_ps(*(__m128 *)((char *)&v582.m_verticesA[0].m_quad + 16 * v510 + 8), v511);
          v514 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)((char *)&v582.m_verticesA[0].m_quad + 16 * v508 + 8), v511), v512);
          if ( !_mm_movemask_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v514, v514, 85), _mm_shuffle_ps(v514, v514, 0)),
                    _mm_shuffle_ps(v514, v514, 170))) )
          {
            *(__m128 *)((char *)&v582.m_verticesA[0].m_quad + 16 * v510 + 8) = *(__m128 *)((char *)&v582.m_verticesA[2]
                                                                                         + 8);
            goto LABEL_134;
          }
          v515 = _mm_mul_ps(v513, v512);
          *(__m128 *)((char *)&v582.m_verticesA[0].m_quad + 16 * v508 + 8) = *(__m128 *)((char *)&v582.m_verticesA[2] + 8);
          if ( !_mm_movemask_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v515, v515, 85), _mm_shuffle_ps(v515, v515, 0)),
                    _mm_shuffle_ps(v515, v515, 170))) )
          {
LABEL_134:
            v28.m_quad = *(__m128 *)((char *)v582.m_verticesBinA + 8);
            v30 = *(__m128 *)((char *)&v582.m_verticesA[0].m_quad + 8);
            v582.m_checkTriangleDots = *(hkVector4f *)((char *)v582.m_verticesBinA + 8);
            *(hkcdVertex *)&v581[8] = *(hkcdVertex *)((char *)v582.m_verticesA + 8);
            goto LABEL_135;
          }
          dimA.m_storage = 1;
          if ( (_DWORD)v510 == 2 )
            LODWORD(v510) = v508;
          *(__m128 *)((char *)&v582.m_verticesA[0].m_quad + 16 * (signed int)v510 + 8) = *(__m128 *)((char *)&v582.m_verticesA[1] + 8);
LABEL_132:
          v30 = *(__m128 *)((char *)&v582.m_verticesA[0].m_quad + 8);
          v28.m_quad = *(__m128 *)((char *)v582.m_verticesBinA + 8);
          v582.m_checkTriangleDots = *(hkVector4f *)((char *)v582.m_verticesBinA + 8);
          *(hkcdVertex *)&v581[8] = *(hkcdVertex *)((char *)v582.m_verticesA + 8);
          v387 = _mm_sub_ps(
                   *(__m128 *)((char *)&v582.m_verticesA[0].m_quad + 8),
                   *(__m128 *)((char *)&v582.m_verticesBinA[0].m_quad + 8));
          goto LABEL_148;
        }
        dimB.m_storage = 3;
LABEL_119:
        v484 = _mm_sub_ps(v28.m_quad, *(__m128 *)((char *)&v582.m_verticesBinA[2].m_quad + 8));
        v485 = _mm_sub_ps(
                 *(__m128 *)((char *)&v582.m_verticesBinA[2].m_quad + 8),
                 *(__m128 *)((char *)&v582.m_verticesBinA[1].m_quad + 8));
        v486 = _mm_shuffle_ps(v484, v484, 201);
        v487 = _mm_sub_ps(v30, *(__m128 *)((char *)&v582.m_verticesBinA[1].m_quad + 8));
        v488 = _mm_shuffle_ps(v485, v485, 201);
        v489 = _mm_sub_ps(v30, *(__m128 *)((char *)&v582.m_verticesBinA[2].m_quad + 8));
        v490 = _mm_sub_ps(*(__m128 *)((char *)&v582.m_verticesBinA[1].m_quad + 8), v28.m_quad);
        v491 = _mm_sub_ps(v30, v28.m_quad);
        v492 = _mm_sub_ps(_mm_mul_ps(v485, v486), _mm_mul_ps(v484, v488));
        v493 = _mm_shuffle_ps(v492, v492, 201);
        *(__m128 *)&v582.m_lastDimB.m_storage = v493;
        v494 = _mm_sub_ps(_mm_mul_ps(v487, v488), _mm_mul_ps(_mm_shuffle_ps(v487, v487, 201), v485));
        v495 = _mm_mul_ps(_mm_shuffle_ps(v494, v494, 201), v493);
        v496 = _mm_sub_ps(_mm_mul_ps(v489, v486), _mm_mul_ps(_mm_shuffle_ps(v489, v489, 201), v484));
        v497 = _mm_mul_ps(_mm_shuffle_ps(v496, v496, 201), v493);
        v498 = _mm_unpacklo_ps(v495, v497);
        v499 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v490, v490, 201), v491),
                 _mm_mul_ps(_mm_shuffle_ps(v491, v491, 201), v490));
        v500 = _mm_mul_ps(_mm_shuffle_ps(v499, v499, 201), v493);
        v501 = _mm_movelh_ps(v498, v500);
        v502 = _mm_add_ps(
                 _mm_shuffle_ps(_mm_unpackhi_ps(v495, v497), v500, 228),
                 _mm_add_ps(v501, _mm_shuffle_ps(_mm_movehl_ps(v501, v498), v500, 212)));
        v503 = _mm_movemask_ps(_mm_cmpltps(v502, v18)) & 7;
        if ( v503 == 7 )
        {
          v504 = _mm_mul_ps(v493, v491);
          if ( _mm_movemask_ps(
                 _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v504, v504, 85), _mm_shuffle_ps(v504, v504, 0)),
                   _mm_shuffle_ps(v504, v504, 170))) )
          {
            v582.m_checkTriangleDots = *(hkVector4f *)((char *)&v582.m_verticesBinA[1] + 8);
            *(hkcdVertex *)((char *)v582.m_verticesBinA + 8) = *(hkcdVertex *)((char *)&v582.m_verticesBinA[1] + 8);
            v505.m_quad = v28.m_quad;
            v28.m_quad = *(__m128 *)((char *)&v582.m_verticesBinA[1] + 8);
            *(hkcdVertex *)((char *)&v582.m_verticesBinA[1] + 8) = (hkcdVertex)v505.m_quad;
            *(__m128 *)&v582.m_lastDimB.m_storage = _mm_xor_ps(
                                                      v493,
                                                      (__m128)_mm_shuffle_epi32(
                                                                _mm_insert_epi16((__m128i)0i64, 0x8000u, 1),
                                                                0));
            v502 = _mm_shuffle_ps(v502, v502, 225);
          }
        }
        *(__m128 *)((char *)&v582.m_checkTriangleDots.m_quad + 8) = v502;
        if ( v503 == 7 )
          goto LABEL_149;
        v506 = hkcdGskBase::maskToIndex[v503];
        if ( (signed int)v506 >= 0 )
        {
          v530 = *(char *)(v506 + 5398197060i64);
          v531 = v506;
          v532 = *(char *)(v506 + 5398197062i64);
          v533 = *(__m128 *)((char *)&v582.m_verticesBinA[0].m_quad + 16 * v531 + 8);
          v534 = _mm_sub_ps(v30, v533);
          v535 = _mm_sub_ps(*(__m128 *)((char *)&v582.m_verticesBinA[0].m_quad + 16 * v532 + 8), v533);
          v536 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)((char *)&v582.m_verticesBinA[0].m_quad + 16 * v530 + 8), v533), v534);
          if ( _mm_movemask_ps(
                 _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v536, v536, 85), _mm_shuffle_ps(v536, v536, 0)),
                   _mm_shuffle_ps(v536, v536, 170))) )
          {
            v537 = _mm_mul_ps(v535, v534);
            *(__m128 *)((char *)&v582.m_verticesBinA[0].m_quad + 16 * v530 + 8) = *(__m128 *)((char *)&v582.m_verticesBinA[2]
                                                                                            + 8);
            if ( _mm_movemask_ps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v537, v537, 85), _mm_shuffle_ps(v537, v537, 0)),
                     _mm_shuffle_ps(v537, v537, 170))) )
            {
              dimB.m_storage = 1;
              if ( (_DWORD)v532 == 2 )
                LODWORD(v532) = v530;
              *(__m128 *)((char *)&v582.m_verticesBinA[0].m_quad + 16 * (signed int)v532 + 8) = *(__m128 *)((char *)&v582.m_verticesBinA[1] + 8);
              goto LABEL_132;
            }
          }
          else
          {
            *(__m128 *)((char *)&v582.m_verticesBinA[0].m_quad + 16 * v532 + 8) = *(__m128 *)((char *)&v582.m_verticesBinA[2]
                                                                                            + 8);
          }
        }
        else
        {
          v507 = v506 + 8;
          if ( v507 >= 3 )
            goto LABEL_144;
          *(__m128 *)((char *)&v582.m_verticesBinA[0].m_quad + 16 * v507 + 8) = *(__m128 *)((char *)&v582.m_verticesBinA[2]
                                                                                          + 8);
        }
        v28.m_quad = *(__m128 *)((char *)v582.m_verticesBinA + 8);
        v30 = *(__m128 *)((char *)&v582.m_verticesA[0].m_quad + 8);
        v582.m_checkTriangleDots = *(hkVector4f *)((char *)v582.m_verticesBinA + 8);
        *(hkcdVertex *)&v581[8] = *(hkcdVertex *)((char *)v582.m_verticesA + 8);
        goto LABEL_89;
      default:
        goto LABEL_64;
    }
  }
}L_89;
      default:
        goto LABEL_64;
    }
  }
}

// File Line: 99
// RVA: 0x1313AE0
hkBool *__fastcall hkcdGsk::linearCast(hkBool *result, hkcdVertex *vertsShape, int numVertsShape, hkcdVertex *vertsCast, int numVertsCast, hkcdGsk::LinearCastInput *input, hkcdGsk::Cache *cache, hkcdGsk::LinearCastOutput *output)
{
  hkBool *v8; // rbx
  hkcdVertex *shapeA; // [rsp+50h] [rbp-E8h]
  int v11; // [rsp+58h] [rbp-E0h]
  hkcdVertex *shapeB; // [rsp+60h] [rbp-D8h]
  int v13; // [rsp+68h] [rbp-D0h]
  hkcdGskImpl<hkcdGsk_Vector4ShapeInterface> v14; // [rsp+70h] [rbp-C8h]
  void **v15; // [rsp+140h] [rbp+8h]

  shapeA = vertsShape;
  v15 = &hkcdGsk_Vector4ShapeInterface::`vftable';
  v8 = result;
  v13 = numVertsCast;
  v11 = numVertsShape;
  shapeB = vertsCast;
  hkcdGskImpl<hkcdGsk_Vector4ShapeInterface>::linearCast<hkcdGsk::Cache>(
    &v14,
    result,
    (hkcdGsk_Vector4ShapeInterface *)&v15,
    &shapeA,
    &shapeB,
    input,
    cache,
    &output->m_fractionInOut,
    &output->m_normalOut);
  return v8;
}

// File Line: 110
// RVA: 0x1313B80
hkBool *__fastcall hkcdGsk::rayCast(hkBool *result, hkcdVertex *verts, int numVerts, hkcdGsk::RayCastInput *input, hkcdGsk::RayCastOutput *output)
{
  hkBool *v5; // rbx
  hkVector4f *normalOut; // [rsp+20h] [rbp-18h]
  int v8; // [rsp+28h] [rbp-10h]

  v5 = result;
  v8 = numVerts;
  result->m_bool = hkcdGskBase::castRay<hkcdGsk_Vector4Shape>(
                     (hkcdGskBase *)&normalOut,
                     (hkcdGsk_Vector4Shape *)input,
                     (hkcdGsk::RayCastInput *)&output->m_fractionInOut,
                     (hkSimdFloat32 *)output,
                     (hkVector4f *)&verts->m_quad) != 0;
  return v5;
}

// File Line: 119
// RVA: 0x1313BD0
hkBool *__fastcall hkcdGsk::rayCast(hkBool *result, hkFourTransposedPointsf *fours, int numUnTransposed, hkcdGsk::RayCastInput *input, hkcdGsk::RayCastOutput *output)
{
  hkcdGsk_Vector4Shape *v5; // r15
  int v6; // ebp
  hkFourTransposedPointsf *v7; // r12
  hkBool *v8; // r14
  unsigned int v9; // esi
  hkLifoAllocator *v10; // rax
  hkcdVertex *v11; // rbx
  int v12; // edx
  char *v13; // rcx
  signed int v14; // edi
  unsigned int v15; // eax
  unsigned int v16; // ecx
  signed int v17; // esi
  hkLifoAllocator *v18; // rax
  int v19; // er8
  hkVector4f *normalOut; // [rsp+20h] [rbp-28h]
  int v22; // [rsp+28h] [rbp-20h]

  v5 = (hkcdGsk_Vector4Shape *)input;
  v6 = numUnTransposed;
  v7 = fours;
  v8 = result;
  v9 = (numUnTransposed + 3) & 0xFFFFFFFC;
  if ( v9 )
  {
    v10 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v11 = (hkcdVertex *)v10->m_cur;
    v12 = (16 * v9 + 127) & 0xFFFFFF80;
    v13 = (char *)v11 + v12;
    if ( v12 > v10->m_slabSize || v13 > v10->m_end )
      v11 = (hkcdVertex *)hkLifoAllocator::allocateFromNewSlab(v10, v12);
    else
      v10->m_cur = v13;
  }
  else
  {
    v11 = 0i64;
  }
  v14 = v9 | 0x80000000;
  hkFourTransposedPointsf::getOriginalVertices(v7, v6, v11);
  v22 = v6;
  v15 = hkcdGskBase::castRay<hkcdGsk_Vector4Shape>(
          (hkcdGskBase *)&normalOut,
          v5,
          (hkcdGsk::RayCastInput *)&output->m_fractionInOut,
          (hkSimdFloat32 *)output,
          (hkVector4f *)&v11->m_quad);
  v16 = hkMemoryRouter::s_memoryRouter.m_slotID;
  v8->m_bool = v15 != 0;
  v17 = (16 * v9 + 127) & 0xFFFFFF80;
  v18 = (hkLifoAllocator *)TlsGetValue(v16);
  v19 = (v17 + 15) & 0xFFFFFFF0;
  if ( v17 > v18->m_slabSize || (char *)v11 + v19 != v18->m_cur || v18->m_firstNonLifoEnd == v11 )
    hkLifoAllocator::slowBlockFree(v18, v11, v19);
  else
    v18->m_cur = v11;
  if ( v14 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v11,
      16 * v14);
  return v8;
}

