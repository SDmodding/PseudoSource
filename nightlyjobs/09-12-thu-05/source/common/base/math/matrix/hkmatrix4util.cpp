// File Line: 126
// RVA: 0xC6E750
hkResult *__fastcall __hkMatrix4UtilAlgo::invert(hkResult *result, hkMatrix4f *m, hkSimdFloat32 *epsilon)
{
  hkMatrix4f *v3; // rbx
  hkResult *v4; // rdi
  hkResult *v5; // rax
  hkVector4f v6; // xmm1
  hkVector4f v7; // xmm0
  hkVector4f v8; // xmm1
  hkMatrix4f out; // [rsp+20h] [rbp-48h]

  v3 = m;
  v4 = result;
  __hkMatrix4UtilAlgo::setInverse(result, m, &out, epsilon);
  v5 = v4;
  if ( v4->m_enum == HK_SUCCESS )
  {
    v6.m_quad = (__m128)out.m_col1;
    v3->m_col0 = out.m_col0;
    v7.m_quad = (__m128)out.m_col2;
    v3->m_col1 = (hkVector4f)v6.m_quad;
    v8.m_quad = (__m128)out.m_col3;
    v3->m_col2 = (hkVector4f)v7.m_quad;
    v3->m_col3 = (hkVector4f)v8.m_quad;
  }
  return v5;
}

// File Line: 137
// RVA: 0xC6E7B0
hkResult *__fastcall __hkMatrix4UtilAlgo::invert(hkResult *result, hkMatrix4d *m, hkSimdDouble64 *epsilon)
{
  hkMatrix4d *v3; // rbx
  hkResult *v4; // rdi
  hkResult *v5; // rax
  __m128d v6; // xmm1
  __m128d v7; // xmm0
  __m128d v8; // xmm1
  __m128d v9; // xmm0
  __m128d v10; // xmm1
  __m128d v11; // xmm0
  __m128d v12; // xmm1
  hkMatrix4d out; // [rsp+40h] [rbp+0h]

  v3 = m;
  v4 = result;
  __hkMatrix4UtilAlgo::setInverse(result, m, (hkMatrix4d *)((unsigned __int64)&out & 0xFFFFFFFFFFFFFFE0ui64), epsilon);
  v5 = v4;
  if ( v4->m_enum == HK_SUCCESS )
  {
    v6 = *(__m128d *)(((unsigned __int64)&out & 0xFFFFFFFFFFFFFFE0ui64) + 0x10);
    v3->m_col0.m_quad.xy = *(__m128d *)((unsigned __int64)&out & 0xFFFFFFFFFFFFFFE0ui64);
    v7 = *(__m128d *)(((unsigned __int64)&out & 0xFFFFFFFFFFFFFFE0ui64) + 0x20);
    v3->m_col0.m_quad.zw = v6;
    v8 = *(__m128d *)(((unsigned __int64)&out & 0xFFFFFFFFFFFFFFE0ui64) + 0x30);
    v3->m_col1.m_quad.xy = v7;
    v9 = *(__m128d *)(((unsigned __int64)&out & 0xFFFFFFFFFFFFFFE0ui64) + 0x40);
    v3->m_col1.m_quad.zw = v8;
    v10 = *(__m128d *)(((unsigned __int64)&out & 0xFFFFFFFFFFFFFFE0ui64) + 0x50);
    v3->m_col2.m_quad.xy = v9;
    v11 = *(__m128d *)(((unsigned __int64)&out & 0xFFFFFFFFFFFFFFE0ui64) + 0x60);
    v3->m_col2.m_quad.zw = v10;
    v12 = *(__m128d *)(((unsigned __int64)&out & 0xFFFFFFFFFFFFFFE0ui64) + 0x70);
    v3->m_col3.m_quad.xy = v11;
    v3->m_col3.m_quad.zw = v12;
  }
  return v5;
}

// File Line: 148
// RVA: 0xC6E840
hkResult *__fastcall __hkMatrix4UtilAlgo::setInverse(hkResult *result, hkMatrix4f *m, hkMatrix4f *out, hkSimdFloat32 *epsilon)
{
  hkResult *v4; // rbx
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
  hkResult *v21; // rax
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

  v4 = result;
  v5 = _mm_shuffle_ps(m->m_col2.m_quad, m->m_col2.m_quad, 57);
  v6.m_quad = (__m128)m->m_col3;
  v7 = (__m128)_mm_slli_epi32(_mm_srli_epi32((__m128i)xmmword_141A721E0, 0x1Fu), 0x1Fu);
  v8 = _mm_mul_ps(v6.m_quad, v5);
  v9 = _mm_mul_ps(_mm_shuffle_ps(m->m_col3.m_quad, v6.m_quad, 78), v5);
  v10 = _mm_mul_ps(_mm_shuffle_ps(m->m_col3.m_quad, v6.m_quad, 147), v5);
  v11 = _mm_sub_ps(_mm_shuffle_ps(v9, v9, 57), _mm_shuffle_ps(v8, v8, 78));
  v12 = _mm_sub_ps(v9, _mm_shuffle_ps(v8, v8, 57));
  v13.m_quad = (__m128)m->m_col1;
  v14 = _mm_shuffle_ps(v13.m_quad, v13.m_quad, 78);
  v15 = _mm_shuffle_ps(m->m_col1.m_quad, v13.m_quad, 147);
  v16 = _mm_sub_ps(_mm_shuffle_ps(v10, v10, 78), v10);
  v17 = _mm_add_ps(
          _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(m->m_col1.m_quad, v13.m_quad, 57), v11), _mm_mul_ps(v16, v14)),
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
    v35 = v23;
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
                           _mm_xor_ps(_mm_add_ps(_mm_mul_ps(v37, v38), _mm_add_ps(_mm_mul_ps(v32, v37), v36)), v24),
                           v31);
    hkMatrix4f::transpose(out);
    v4->m_enum = 0;
    v21 = v4;
  }
  else
  {
    result->m_enum = 1;
    v21 = result;
  }
  return v21;
}

// File Line: 264
// RVA: 0xC6EAD0
hkResult *__fastcall __hkMatrix4UtilAlgo::setInverse(hkResult *result, hkMatrix4d *m, hkMatrix4d *out, hkSimdDouble64 *epsilon)
{
  __m128d *v4; // rbp
  __m128d v5; // xmm2
  __m128d v6; // xmm5
  __m128d v7; // xmm1
  hkResult *v8; // rbx
  __m128d v9; // xmm0
  __m128d v10; // xmm1
  __m128d v11; // xmm3
  __m128d v12; // xmm7
  __m128d v13; // xmm8
  __m128d v14; // xmm4
  __m128d v15; // xmm6
  __m128d v16; // xmm5
  __m128d v17; // xmm13
  __m128i v18; // xmm2
  __m128d v19; // xmm6
  __m128d v20; // xmm5
  __m128d v21; // xmm1
  __m128d v22; // xmm14
  __m128d v23; // xmm9
  __m128d v24; // xmm6
  __m128d v25; // xmm15
  __m128d v26; // xmm7
  __m128d v27; // xmm15
  __m128d v28; // xmm8
  __m128d v29; // xmm4
  __m128d v30; // xmm5
  __m128d v31; // xmm3
  __m128d v32; // xmm10
  __m128d v33; // xmm11
  __m128d v34; // xmm1
  __m128d v35; // xmm0
  __m128d v36; // xmm12
  __m128d v37; // xmm10
  __m128d v38; // xmm2
  __m128d v39; // xmm0
  __m128d v40; // xmm2
  __m128d v41; // xmm1
  __m128d v42; // xmm15
  __m128d v43; // xmm2
  __m128d v44; // xmm14
  __m128d v45; // xmm0
  __m128d v46; // xmm6
  __m128d v47; // xmm2
  __m128d v48; // xmm1
  __m128d v49; // xmm15
  __m128d v50; // xmm6
  __m128d v51; // xmm8
  __m128d v52; // xmm2
  __m128d v53; // xmm14
  __m128d v54; // xmm0
  __m128d v55; // xmm9
  __m128d v56; // xmm15
  __m128d v57; // xmm0
  __m128d v58; // xmm2
  __m128d v59; // xmm0
  __m128d v60; // xmm6
  __m128d v61; // xmm1
  __m128d v62; // xmm5
  __m128d v63; // xmm4
  __m128d v64; // xmm3
  __m128d v65; // xmm2
  __m128d v66; // xmm8
  __m128d v67; // xmm7
  __m128d v68; // xmm4
  __m128d v69; // xmm3
  __m128d v70; // xmm8
  __m128d v71; // xmm7
  __m128d v72; // xmm6
  __m128d v73; // xmm2
  __m128d v74; // xmm1
  __m128d v75; // xmm1
  __m128d v76; // xmm3
  __m128d v77; // xmm6
  __m128d v78; // xmm5
  __m128d v79; // xmm2
  __m128d v80; // xmm3
  __m128d v81; // xmm1
  __m128d v82; // xmm6
  __m128d v83; // xmm5
  __m128d v84; // xmm3
  __m128d v85; // xmm2
  __m128d v86; // xmm6
  __m128d v87; // xmm0
  __m128d v88; // xmm3
  __m128d v89; // xmm5
  __m128d v90; // xmm0
  __m128d v91; // xmm3
  __m128d v92; // xmm8
  __m128d v93; // xmm7
  __m128d v94; // xmm1
  __m128d v95; // xmm3
  __m128d v96; // xmm0
  __m128d v97; // xmm8
  __m128d v98; // xmm7
  __m128d v99; // xmm0
  __m128d v100; // xmm3
  __m128d v101; // xmm1
  __m128d v102; // xmm1
  __m128d v103; // xmm0
  __m128d v104; // xmm7
  __int128 v106; // [rsp+40h] [rbp+0h]

  v4 = (__m128d *)((unsigned __int64)&v106 & 0xFFFFFFFFFFFFFFE0ui64);
  v5 = m->m_col3.m_quad.zw;
  v6 = m->m_col3.m_quad.xy;
  v7 = m->m_col2.m_quad.zw;
  v8 = result;
  v9 = _mm_shuffle_pd(m->m_col2.m_quad.xy, v7, 1);
  v10 = _mm_shuffle_pd(v7, m->m_col2.m_quad.xy, 1);
  v11 = _mm_mul_pd(m->m_col3.m_quad.xy, v9);
  v12 = _mm_mul_pd(v5, v9);
  v13 = _mm_mul_pd(v6, v10);
  v14 = _mm_mul_pd(m->m_col3.m_quad.zw, v10);
  v15 = _mm_shuffle_pd(m->m_col3.m_quad.zw, v6, 1);
  v16 = _mm_shuffle_pd(v6, v5, 1);
  v17 = (__m128d)_mm_slli_epi64(_mm_srli_epi64((__m128i)xmmword_141A72160, 0x3Fu), 0x3Fu);
  v18 = (__m128i)v17;
  v19 = _mm_mul_pd(v15, v9);
  v20 = _mm_mul_pd(v16, v10);
  _mm_store_si128((__m128i *)(((unsigned __int64)&v106 & 0xFFFFFFFFFFFFFFE0ui64) + 64), v18);
  v21 = m->m_col1.m_quad.xy;
  v22 = _mm_sub_pd(_mm_shuffle_pd(v12, v13, 1), v14);
  v23 = _mm_sub_pd(v20, v19);
  v24 = _mm_sub_pd(v19, v20);
  v25 = _mm_shuffle_pd(v13, v12, 1);
  v26 = _mm_sub_pd(v12, _mm_shuffle_pd(v11, v14, 1));
  v27 = _mm_sub_pd(v25, v11);
  v28 = _mm_sub_pd(v13, _mm_shuffle_pd(v14, v11, 1));
  v29 = m->m_col1.m_quad.zw;
  v30 = _mm_shuffle_pd(m->m_col1.m_quad.xy, v29, 1);
  v31 = _mm_shuffle_pd(m->m_col1.m_quad.zw, v21, 1);
  v32 = _mm_add_pd(_mm_add_pd(_mm_mul_pd(v22, v30), _mm_mul_pd(v23, v29)), _mm_mul_pd(v26, v31));
  v33 = _mm_add_pd(_mm_add_pd(_mm_mul_pd(v27, v31), _mm_mul_pd(v24, v21)), _mm_mul_pd(v28, v30));
  v34 = _mm_xor_pd(_mm_mul_pd(v32, m->m_col0.m_quad.xy), (__m128d)v18);
  v35 = _mm_xor_pd(_mm_mul_pd(v33, m->m_col0.m_quad.zw), v17);
  v36 = _mm_add_pd(_mm_add_pd(_mm_shuffle_pd(v35, v35, 1), v35), _mm_add_pd(_mm_shuffle_pd(v34, v34, 1), v34));
  if ( COERCE_DOUBLE((unsigned __int64)(2i64 * *(_QWORD *)&v36.m128d_f64[0]) >> 1) >= epsilon->m_real.m128d_f64[0] )
  {
    v37 = _mm_xor_pd(v32, (__m128d)v18);
    v38 = m->m_col0.m_quad.zw;
    v39 = _mm_shuffle_pd(m->m_col0.m_quad.xy, v38, 1);
    v40 = _mm_shuffle_pd(v38, m->m_col0.m_quad.xy, 1);
    v41 = _mm_shuffle_pd(v39, v40, 1);
    v42 = _mm_mul_pd(v27, v40);
    v43 = _mm_shuffle_pd(v40, v39, 1);
    v44 = _mm_add_pd(_mm_mul_pd(v22, v39), _mm_mul_pd(v23, v41));
    v45 = _mm_shuffle_pd(v41, v43, 1);
    v46 = _mm_mul_pd(v24, v43);
    v47 = _mm_shuffle_pd(v43, v41, 1);
    v48 = m->m_col1.m_quad.zw;
    v49 = _mm_add_pd(v42, v46);
    v50 = m->m_col1.m_quad.xy;
    v51 = _mm_mul_pd(v28, v47);
    v52 = m->m_col0.m_quad.xy;
    v53 = _mm_add_pd(v44, _mm_mul_pd(v26, v45));
    v54 = (__m128d)_mm_slli_epi64(_mm_srli_epi64((__m128i)xmmword_141A72170, 0x3Fu), 0x3Fu);
    v55 = v54;
    v56 = _mm_xor_pd(_mm_add_pd(v49, v51), v54);
    *(__m128d *)(((unsigned __int64)&v106 & 0xFFFFFFFFFFFFFFE0ui64) + 0x50) = v54;
    v57 = m->m_col0.m_quad.zw;
    v58 = _mm_shuffle_pd(v52, v57, 1);
    v59 = _mm_shuffle_pd(v57, m->m_col0.m_quad.xy, 1);
    v60 = _mm_mul_pd(v50, v59);
    v61 = _mm_mul_pd(v48, v59);
    v62 = _mm_mul_pd(v30, v59);
    v63 = _mm_mul_pd(v29, v58);
    v64 = _mm_mul_pd(v31, v58);
    v65 = _mm_mul_pd(v58, m->m_col1.m_quad.xy);
    *v4 = v63;
    v66 = _mm_shuffle_pd(v63, v60, 1);
    v67 = _mm_shuffle_pd(v60, v63, 1);
    v68 = _mm_sub_pd(v62, v64);
    *(__m128d *)(((unsigned __int64)&v106 & 0xFFFFFFFFFFFFFFE0ui64) + 0x20) = _mm_sub_pd(v64, v62);
    v69 = m->m_col3.m_quad.zw;
    v70 = _mm_sub_pd(v66, v61);
    v71 = _mm_sub_pd(v67, v65);
    v72 = _mm_sub_pd(v60, _mm_shuffle_pd(v61, v65, 1));
    v73 = _mm_sub_pd(*v4, _mm_shuffle_pd(v65, v61, 1));
    v74 = m->m_col3.m_quad.xy;
    *(__m128d *)(((unsigned __int64)&v106 & 0xFFFFFFFFFFFFFFE0ui64) + 0x30) = v72;
    *v4 = v73;
    v75 = _mm_shuffle_pd(v74, v69, 1);
    v76 = _mm_shuffle_pd(v69, m->m_col3.m_quad.xy, 1);
    v77 = _mm_mul_pd(v70, v75);
    v78 = _mm_mul_pd(v71, v76);
    v79 = _mm_shuffle_pd(v75, v76, 1);
    v80 = _mm_shuffle_pd(v76, v75, 1);
    v81 = _mm_shuffle_pd(v79, v80, 1);
    v82 = _mm_add_pd(v77, _mm_mul_pd(v68, v79));
    v83 = _mm_add_pd(v78, _mm_mul_pd(*(__m128d *)(((unsigned __int64)&v106 & 0xFFFFFFFFFFFFFFE0ui64) + 0x20), v80));
    v84 = _mm_shuffle_pd(v80, v79, 1);
    v85 = _mm_div_pd(g_vectordConstants[2].xy, v36);
    v86 = _mm_xor_pd(
            _mm_add_pd(v82, _mm_mul_pd(*v4, v81)),
            *(__m128d *)(((unsigned __int64)&v106 & 0xFFFFFFFFFFFFFFE0ui64) + 0x40));
    v87 = _mm_mul_pd(*(__m128d *)(((unsigned __int64)&v106 & 0xFFFFFFFFFFFFFFE0ui64) + 0x30), v84);
    v88 = m->m_col2.m_quad.zw;
    v89 = _mm_add_pd(v83, v87);
    v90 = _mm_shuffle_pd(m->m_col2.m_quad.xy, v88, 1);
    v91 = _mm_shuffle_pd(v88, m->m_col2.m_quad.xy, 1);
    out->m_col0.m_quad.xy = _mm_mul_pd(v37, v85);
    v92 = _mm_mul_pd(v70, v90);
    v93 = _mm_mul_pd(v71, v91);
    v94 = _mm_shuffle_pd(v90, v91, 1);
    v95 = _mm_shuffle_pd(v91, v90, 1);
    v96 = *(__m128d *)(((unsigned __int64)&v106 & 0xFFFFFFFFFFFFFFE0ui64) + 0x20);
    v97 = _mm_add_pd(v92, _mm_mul_pd(v68, v94));
    out->m_col1.m_quad.xy = _mm_mul_pd(_mm_xor_pd(v53, v55), v85);
    v98 = _mm_add_pd(v93, _mm_mul_pd(v96, v95));
    out->m_col2.m_quad.xy = _mm_mul_pd(v86, v85);
    out->m_col0.m_quad.zw = _mm_mul_pd(_mm_xor_pd(v33, v17), v85);
    v99 = _mm_shuffle_pd(v94, v95, 1);
    v100 = _mm_shuffle_pd(v95, v94, 1);
    v101 = *v4;
    out->m_col1.m_quad.zw = _mm_mul_pd(v56, v85);
    v102 = _mm_mul_pd(v101, v99);
    v103 = *(__m128d *)(((unsigned __int64)&v106 & 0xFFFFFFFFFFFFFFE0ui64) + 0x30);
    out->m_col2.m_quad.zw = _mm_mul_pd(_mm_xor_pd(v89, v17), v85);
    v104 = _mm_xor_pd(
             _mm_add_pd(v98, _mm_mul_pd(v103, v100)),
             *(__m128d *)(((unsigned __int64)&v106 & 0xFFFFFFFFFFFFFFE0ui64) + 0x50));
    out->m_col3.m_quad.xy = _mm_mul_pd(_mm_xor_pd(_mm_add_pd(v97, v102), v55), v85);
    out->m_col3.m_quad.zw = _mm_mul_pd(v104, v85);
    hkMatrix4d::transpose(out);
    v8->m_enum = 0;
  }
  else
  {
    result->m_enum = 1;
  }
  return v8;
}

