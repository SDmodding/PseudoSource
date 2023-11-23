// File Line: 126
// RVA: 0xC6E750
hkResult *__fastcall __hkMatrix4UtilAlgo::invert(hkResult *result, hkMatrix4f *m, hkSimdFloat32 *epsilon)
{
  hkResult *v5; // rax
  hkVector4f v6; // xmm1
  hkVector4f v7; // xmm0
  hkVector4f v8; // xmm1
  hkMatrix4f out; // [rsp+20h] [rbp-48h] BYREF

  __hkMatrix4UtilAlgo::setInverse(result, m, &out, epsilon);
  v5 = result;
  if ( result->m_enum == HK_SUCCESS )
  {
    v6.m_quad = (__m128)out.m_col1;
    m->m_col0 = out.m_col0;
    v7.m_quad = (__m128)out.m_col2;
    m->m_col1 = (hkVector4f)v6.m_quad;
    v8.m_quad = (__m128)out.m_col3;
    m->m_col2 = (hkVector4f)v7.m_quad;
    m->m_col3 = (hkVector4f)v8.m_quad;
  }
  return v5;
}

// File Line: 137
// RVA: 0xC6E7B0
hkResult *__fastcall __hkMatrix4UtilAlgo::invert(hkResult *result, hkMatrix4d *m, hkSimdDouble64 *epsilon)
{
  hkResult *v5; // rax
  __m128d v6; // xmm1
  __m128d v7; // xmm0
  __m128d v8; // xmm1
  __m128d v9; // xmm0
  __m128d v10; // xmm1
  __m128d v11; // xmm0
  __m128d v12; // xmm1
  hkMatrix4d out; // [rsp+40h] [rbp+0h] BYREF

  __hkMatrix4UtilAlgo::setInverse(result, m, (hkMatrix4d *)((unsigned __int64)&out & 0xFFFFFFFFFFFFFFE0ui64), epsilon);
  v5 = result;
  if ( result->m_enum == HK_SUCCESS )
  {
    v6 = *(__m128d *)(((unsigned __int64)&out & 0xFFFFFFFFFFFFFFE0ui64) + 0x10);
    m->m_col0.m_quad.xy = *(__m128d *)((unsigned __int64)&out & 0xFFFFFFFFFFFFFFE0ui64);
    v7 = *(__m128d *)(((unsigned __int64)&out & 0xFFFFFFFFFFFFFFE0ui64) + 0x20);
    m->m_col0.m_quad.zw = v6;
    v8 = *(__m128d *)(((unsigned __int64)&out & 0xFFFFFFFFFFFFFFE0ui64) + 0x30);
    m->m_col1.m_quad.xy = v7;
    v9 = *(__m128d *)(((unsigned __int64)&out & 0xFFFFFFFFFFFFFFE0ui64) + 0x40);
    m->m_col1.m_quad.zw = v8;
    v10 = *(__m128d *)(((unsigned __int64)&out & 0xFFFFFFFFFFFFFFE0ui64) + 0x50);
    m->m_col2.m_quad.xy = v9;
    v11 = *(__m128d *)(((unsigned __int64)&out & 0xFFFFFFFFFFFFFFE0ui64) + 0x60);
    m->m_col2.m_quad.zw = v10;
    v12 = *(__m128d *)(((unsigned __int64)&out & 0xFFFFFFFFFFFFFFE0ui64) + 0x70);
    m->m_col3.m_quad.xy = v11;
    m->m_col3.m_quad.zw = v12;
  }
  return v5;
}

// File Line: 148
// RVA: 0xC6E840
hkResult *__fastcall __hkMatrix4UtilAlgo::setInverse(
        hkResult *result,
        hkMatrix4f *m,
        hkMatrix4f *out,
        hkSimdFloat32 *epsilon)
{
  __m128 v5; // xmm8
  hkVector4f v6; // xmm9
  __m128 v7; // xmm10
  __m128 v8; // xmm2
  __m128 v9; // xmm3
  __m128 v10; // xmm1
  __m128 v11; // xmm5
  __m128 v12; // xmm3
  hkVector4f v13; // xmm2
  __m128 v14; // xmm12
  __m128 v15; // xmm13
  __m128 v16; // xmm4
  __m128 v17; // xmm7
  __m128 v18; // xmm0
  __m128 v19; // xmm1
  __m128 v20; // xmm11
  __m128 v22; // xmm14
  __m128 v23; // xmm9
  __m128 v24; // xmm15
  __m128 v25; // xmm0
  __m128 v26; // xmm1
  __m128 v27; // xmm12
  __m128 v28; // xmm4
  __m128 v29; // xmm14
  __m128 v30; // xmm6
  __m128 v31; // xmm3
  __m128 v32; // xmm4
  __m128 v33; // xmm5
  __m128 v34; // xmm1
  __m128 v35; // xmm9
  __m128 v36; // xmm5
  __m128 v37; // xmm8
  __m128 v38; // xmm12

  v5 = _mm_shuffle_ps(m->m_col2.m_quad, m->m_col2.m_quad, 57);
  v6.m_quad = (__m128)m->m_col3;
  v7 = (__m128)_mm_slli_epi32(_mm_srli_epi32((__m128i)xmmword_141A721E0, 0x1Fu), 0x1Fu);
  v8 = _mm_mul_ps(v6.m_quad, v5);
  v9 = _mm_mul_ps(_mm_shuffle_ps(v6.m_quad, v6.m_quad, 78), v5);
  v10 = _mm_mul_ps(_mm_shuffle_ps(v6.m_quad, v6.m_quad, 147), v5);
  v11 = _mm_sub_ps(_mm_shuffle_ps(v9, v9, 57), _mm_shuffle_ps(v8, v8, 78));
  v12 = _mm_sub_ps(v9, _mm_shuffle_ps(v8, v8, 57));
  v13.m_quad = (__m128)m->m_col1;
  v14 = _mm_shuffle_ps(v13.m_quad, v13.m_quad, 78);
  v15 = _mm_shuffle_ps(v13.m_quad, v13.m_quad, 147);
  v16 = _mm_sub_ps(_mm_shuffle_ps(v10, v10, 78), v10);
  v17 = _mm_add_ps(
          _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v13.m_quad, v13.m_quad, 57), v11), _mm_mul_ps(v16, v14)),
          _mm_mul_ps(v12, v15));
  v18 = _mm_xor_ps(_mm_mul_ps(v17, m->m_col0.m_quad), v7);
  v19 = _mm_add_ps(_mm_shuffle_ps(v18, v18, 78), v18);
  v20 = _mm_add_ps(_mm_shuffle_ps(v19, v19, 177), v19);
  if ( COERCE_FLOAT((unsigned int)(2 * v20.m128_i32[0]) >> 1) >= epsilon->m_real.m128_f32[0] )
  {
    v22 = _mm_shuffle_ps(m->m_col0.m_quad, m->m_col0.m_quad, 57);
    v23 = _mm_shuffle_ps(v6.m_quad, v6.m_quad, 57);
    v24 = (__m128)_mm_slli_epi32(_mm_srli_epi32((__m128i)xmmword_141A72230, 0x1Fu), 0x1Fu);
    v25 = _mm_shuffle_ps(v22, v22, 57);
    v26 = _mm_mul_ps(v22, v15);
    v27 = _mm_mul_ps(v14, v22);
    v28 = _mm_add_ps(_mm_mul_ps(v16, v25), _mm_mul_ps(v11, v22));
    v29 = _mm_mul_ps(v22, v13.m_quad);
    v30 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v25, v25, 57), v12), v28);
    v31 = _mm_div_ps(query.m_quad, v20);
    v32 = _mm_sub_ps(_mm_shuffle_ps(v26, v26, 78), v26);
    v33 = _mm_sub_ps(_mm_shuffle_ps(v27, v27, 57), _mm_shuffle_ps(v29, v29, 78));
    v34 = _mm_mul_ps(v33, v23);
    v35 = _mm_shuffle_ps(v23, v23, 57);
    v36 = _mm_mul_ps(v33, v5);
    v37 = _mm_shuffle_ps(v5, v5, 57);
    v38 = _mm_sub_ps(v27, _mm_shuffle_ps(v29, v29, 57));
    out->m_col1.m_quad = _mm_mul_ps(v31, _mm_xor_ps(v30, v24));
    out->m_col0.m_quad = _mm_mul_ps(v31, _mm_xor_ps(v17, v7));
    out->m_col2.m_quad = _mm_mul_ps(
                           v31,
                           _mm_xor_ps(
                             _mm_add_ps(
                               _mm_mul_ps(_mm_shuffle_ps(v35, v35, 57), v38),
                               _mm_add_ps(_mm_mul_ps(v32, v35), v34)),
                             v7));
    out->m_col3.m_quad = _mm_mul_ps(
                           _mm_xor_ps(
                             _mm_add_ps(
                               _mm_mul_ps(_mm_shuffle_ps(v37, v37, 57), v38),
                               _mm_add_ps(_mm_mul_ps(v32, v37), v36)),
                             v24),
                           v31);
    hkMatrix4f::transpose(out);
    result->m_enum = HK_SUCCESS;
    return result;
  }
  else
  {
    result->m_enum = HK_FAILURE;
    return result;
  }
}

// File Line: 264
// RVA: 0xC6EAD0
hkResult *__fastcall __hkMatrix4UtilAlgo::setInverse(
        hkResult *result,
        hkMatrix4d *m,
        hkMatrix4d *out,
        hkSimdDouble64 *epsilon)
{
  __m128d *v4; // rbp
  __m128d zw; // xmm2
  __m128d xy; // xmm5
  __m128d v7; // xmm1
  __m128d v9; // xmm0
  __m128d v10; // xmm1
  __m128d v11; // xmm3
  __m128d v12; // xmm7
  __m128d v13; // xmm8
  __m128d v14; // xmm4
  __m128d v15; // xmm13
  __m128d v16; // xmm6
  __m128d v17; // xmm5
  __m128d v18; // xmm1
  __m128d v19; // xmm14
  __m128d v20; // xmm9
  __m128d v21; // xmm6
  __m128d v22; // xmm15
  __m128d v23; // xmm7
  __m128d v24; // xmm15
  __m128d v25; // xmm8
  __m128d v26; // xmm4
  __m128d v27; // xmm5
  __m128d v28; // xmm3
  __m128d v29; // xmm10
  __m128d v30; // xmm11
  __m128d v31; // xmm1
  __m128d v32; // xmm0
  __m128d v33; // xmm12
  __m128d v34; // xmm2
  __m128d v35; // xmm0
  __m128d v36; // xmm2
  __m128d v37; // xmm1
  __m128d v38; // xmm15
  __m128d v39; // xmm2
  __m128d v40; // xmm14
  __m128d v41; // xmm0
  __m128d v42; // xmm6
  __m128d v43; // xmm2
  __m128d v44; // xmm1
  __m128d v45; // xmm15
  __m128d v46; // xmm6
  __m128d v47; // xmm8
  __m128d v48; // xmm2
  __m128d v49; // xmm14
  __m128d v50; // xmm0
  __m128d v51; // xmm9
  __m128d v52; // xmm15
  __m128d v53; // xmm0
  __m128d v54; // xmm2
  __m128d v55; // xmm0
  __m128d v56; // xmm6
  __m128d v57; // xmm1
  __m128d v58; // xmm5
  __m128d v59; // xmm4
  __m128d v60; // xmm3
  __m128d v61; // xmm2
  __m128d v62; // xmm8
  __m128d v63; // xmm7
  __m128d v64; // xmm4
  __m128d v65; // xmm3
  __m128d v66; // xmm8
  __m128d v67; // xmm7
  __m128d v68; // xmm6
  __m128d v69; // xmm2
  __m128d v70; // xmm1
  __m128d v71; // xmm1
  __m128d v72; // xmm3
  __m128d v73; // xmm6
  __m128d v74; // xmm5
  __m128d v75; // xmm2
  __m128d v76; // xmm3
  __m128d v77; // xmm1
  __m128d v78; // xmm6
  __m128d v79; // xmm5
  __m128d v80; // xmm3
  __m128d v81; // xmm2
  __m128d v82; // xmm6
  __m128d v83; // xmm0
  __m128d v84; // xmm3
  __m128d v85; // xmm5
  __m128d v86; // xmm0
  __m128d v87; // xmm3
  __m128d v88; // xmm8
  __m128d v89; // xmm7
  __m128d v90; // xmm1
  __m128d v91; // xmm3
  __m128d v92; // xmm0
  __m128d v93; // xmm8
  __m128d v94; // xmm7
  __m128d v95; // xmm0
  __m128d v96; // xmm3
  __m128d v97; // xmm1
  __m128d v98; // xmm1
  __m128d v99; // xmm0
  __m128d v100; // xmm7
  __int128 v102[2]; // [rsp+40h] [rbp+0h] BYREF

  v4 = (__m128d *)((unsigned __int64)v102 & 0xFFFFFFFFFFFFFFE0ui64);
  zw = m->m_col3.m_quad.zw;
  xy = m->m_col3.m_quad.xy;
  v7 = m->m_col2.m_quad.zw;
  v9 = _mm_shuffle_pd(m->m_col2.m_quad.xy, v7, 1);
  v10 = _mm_shuffle_pd(v7, m->m_col2.m_quad.xy, 1);
  v11 = _mm_mul_pd(xy, v9);
  v12 = _mm_mul_pd(zw, v9);
  v13 = _mm_mul_pd(xy, v10);
  v14 = _mm_mul_pd(zw, v10);
  v15 = (__m128d)_mm_slli_epi64(_mm_srli_epi64((__m128i)xmmword_141A72160, 0x3Fu), 0x3Fu);
  v16 = _mm_mul_pd(_mm_shuffle_pd(zw, xy, 1), v9);
  v17 = _mm_mul_pd(_mm_shuffle_pd(xy, zw, 1), v10);
  *(__m128d *)(((unsigned __int64)v102 & 0xFFFFFFFFFFFFFFE0ui64) + 0x40) = v15;
  v18 = m->m_col1.m_quad.xy;
  v19 = _mm_sub_pd(_mm_shuffle_pd(v12, v13, 1), v14);
  v20 = _mm_sub_pd(v17, v16);
  v21 = _mm_sub_pd(v16, v17);
  v22 = _mm_shuffle_pd(v13, v12, 1);
  v23 = _mm_sub_pd(v12, _mm_shuffle_pd(v11, v14, 1));
  v24 = _mm_sub_pd(v22, v11);
  v25 = _mm_sub_pd(v13, _mm_shuffle_pd(v14, v11, 1));
  v26 = m->m_col1.m_quad.zw;
  v27 = _mm_shuffle_pd(v18, v26, 1);
  v28 = _mm_shuffle_pd(v26, v18, 1);
  v29 = _mm_add_pd(_mm_add_pd(_mm_mul_pd(v19, v27), _mm_mul_pd(v20, v26)), _mm_mul_pd(v23, v28));
  v30 = _mm_add_pd(_mm_add_pd(_mm_mul_pd(v24, v28), _mm_mul_pd(v21, v18)), _mm_mul_pd(v25, v27));
  v31 = _mm_xor_pd(_mm_mul_pd(v29, m->m_col0.m_quad.xy), v15);
  v32 = _mm_xor_pd(_mm_mul_pd(v30, m->m_col0.m_quad.zw), v15);
  v33 = _mm_add_pd(_mm_add_pd(_mm_shuffle_pd(v32, v32, 1), v32), _mm_add_pd(_mm_shuffle_pd(v31, v31, 1), v31));
  if ( COERCE_DOUBLE((unsigned __int64)(2i64 * *(_QWORD *)&v33.m128d_f64[0]) >> 1) >= epsilon->m_real.m128d_f64[0] )
  {
    v34 = m->m_col0.m_quad.zw;
    v35 = _mm_shuffle_pd(m->m_col0.m_quad.xy, v34, 1);
    v36 = _mm_shuffle_pd(v34, m->m_col0.m_quad.xy, 1);
    v37 = _mm_shuffle_pd(v35, v36, 1);
    v38 = _mm_mul_pd(v24, v36);
    v39 = _mm_shuffle_pd(v36, v35, 1);
    v40 = _mm_add_pd(_mm_mul_pd(v19, v35), _mm_mul_pd(v20, v37));
    v41 = _mm_shuffle_pd(v37, v39, 1);
    v42 = _mm_mul_pd(v21, v39);
    v43 = _mm_shuffle_pd(v39, v37, 1);
    v44 = m->m_col1.m_quad.zw;
    v45 = _mm_add_pd(v38, v42);
    v46 = m->m_col1.m_quad.xy;
    v47 = _mm_mul_pd(v25, v43);
    v48 = m->m_col0.m_quad.xy;
    v49 = _mm_add_pd(v40, _mm_mul_pd(v23, v41));
    v50 = (__m128d)_mm_slli_epi64(_mm_srli_epi64((__m128i)xmmword_141A72170, 0x3Fu), 0x3Fu);
    v51 = v50;
    v52 = _mm_xor_pd(_mm_add_pd(v45, v47), v50);
    *(__m128d *)(((unsigned __int64)v102 & 0xFFFFFFFFFFFFFFE0ui64) + 0x50) = v50;
    v53 = m->m_col0.m_quad.zw;
    v54 = _mm_shuffle_pd(v48, v53, 1);
    v55 = _mm_shuffle_pd(v53, m->m_col0.m_quad.xy, 1);
    v56 = _mm_mul_pd(v46, v55);
    v57 = _mm_mul_pd(v44, v55);
    v58 = _mm_mul_pd(v27, v55);
    v59 = _mm_mul_pd(v26, v54);
    v60 = _mm_mul_pd(v28, v54);
    v61 = _mm_mul_pd(v54, m->m_col1.m_quad.xy);
    *v4 = v59;
    v62 = _mm_shuffle_pd(v59, v56, 1);
    v63 = _mm_shuffle_pd(v56, v59, 1);
    v64 = _mm_sub_pd(v58, v60);
    *(__m128d *)(((unsigned __int64)v102 & 0xFFFFFFFFFFFFFFE0ui64) + 0x20) = _mm_sub_pd(v60, v58);
    v65 = m->m_col3.m_quad.zw;
    v66 = _mm_sub_pd(v62, v57);
    v67 = _mm_sub_pd(v63, v61);
    v68 = _mm_sub_pd(v56, _mm_shuffle_pd(v57, v61, 1));
    v69 = _mm_sub_pd(*v4, _mm_shuffle_pd(v61, v57, 1));
    v70 = m->m_col3.m_quad.xy;
    *(__m128d *)(((unsigned __int64)v102 & 0xFFFFFFFFFFFFFFE0ui64) + 0x30) = v68;
    *v4 = v69;
    v71 = _mm_shuffle_pd(v70, v65, 1);
    v72 = _mm_shuffle_pd(v65, m->m_col3.m_quad.xy, 1);
    v73 = _mm_mul_pd(v66, v71);
    v74 = _mm_mul_pd(v67, v72);
    v75 = _mm_shuffle_pd(v71, v72, 1);
    v76 = _mm_shuffle_pd(v72, v71, 1);
    v77 = _mm_shuffle_pd(v75, v76, 1);
    v78 = _mm_add_pd(v73, _mm_mul_pd(v64, v75));
    v79 = _mm_add_pd(v74, _mm_mul_pd(*(__m128d *)(((unsigned __int64)v102 & 0xFFFFFFFFFFFFFFE0ui64) + 0x20), v76));
    v80 = _mm_shuffle_pd(v76, v75, 1);
    v81 = _mm_div_pd(g_vectordConstants[2].xy, v33);
    v82 = _mm_xor_pd(
            _mm_add_pd(v78, _mm_mul_pd(*v4, v77)),
            *(__m128d *)(((unsigned __int64)v102 & 0xFFFFFFFFFFFFFFE0ui64) + 0x40));
    v83 = _mm_mul_pd(*(__m128d *)(((unsigned __int64)v102 & 0xFFFFFFFFFFFFFFE0ui64) + 0x30), v80);
    v84 = m->m_col2.m_quad.zw;
    v85 = _mm_add_pd(v79, v83);
    v86 = _mm_shuffle_pd(m->m_col2.m_quad.xy, v84, 1);
    v87 = _mm_shuffle_pd(v84, m->m_col2.m_quad.xy, 1);
    out->m_col0.m_quad.xy = _mm_mul_pd(_mm_xor_pd(v29, v15), v81);
    v88 = _mm_mul_pd(v66, v86);
    v89 = _mm_mul_pd(v67, v87);
    v90 = _mm_shuffle_pd(v86, v87, 1);
    v91 = _mm_shuffle_pd(v87, v86, 1);
    v92 = *(__m128d *)(((unsigned __int64)v102 & 0xFFFFFFFFFFFFFFE0ui64) + 0x20);
    v93 = _mm_add_pd(v88, _mm_mul_pd(v64, v90));
    out->m_col1.m_quad.xy = _mm_mul_pd(_mm_xor_pd(v49, v51), v81);
    v94 = _mm_add_pd(v89, _mm_mul_pd(v92, v91));
    out->m_col2.m_quad.xy = _mm_mul_pd(v82, v81);
    out->m_col0.m_quad.zw = _mm_mul_pd(_mm_xor_pd(v30, v15), v81);
    v95 = _mm_shuffle_pd(v90, v91, 1);
    v96 = _mm_shuffle_pd(v91, v90, 1);
    v97 = *v4;
    out->m_col1.m_quad.zw = _mm_mul_pd(v52, v81);
    v98 = _mm_mul_pd(v97, v95);
    v99 = *(__m128d *)(((unsigned __int64)v102 & 0xFFFFFFFFFFFFFFE0ui64) + 0x30);
    out->m_col2.m_quad.zw = _mm_mul_pd(_mm_xor_pd(v85, v15), v81);
    v100 = _mm_xor_pd(
             _mm_add_pd(v94, _mm_mul_pd(v99, v96)),
             *(__m128d *)(((unsigned __int64)v102 & 0xFFFFFFFFFFFFFFE0ui64) + 0x50));
    out->m_col3.m_quad.xy = _mm_mul_pd(_mm_xor_pd(_mm_add_pd(v93, v98), v51), v81);
    out->m_col3.m_quad.zw = _mm_mul_pd(v100, v81);
    hkMatrix4d::transpose(out);
    result->m_enum = HK_SUCCESS;
  }
  else
  {
    result->m_enum = HK_FAILURE;
  }
  return result;
}m_add_pd(v93, v98), v51), v81);
    out->m_col3.m_quad.zw = _mm_mul_pd(v100, v81);
    h

