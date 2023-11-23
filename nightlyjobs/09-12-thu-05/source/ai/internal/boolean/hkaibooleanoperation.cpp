// File Line: 162
// RVA: 0xB9FD50
__int64 __fastcall hkaiBooleanOperation::_calculateIntersect2(
        hkaiBooleanOperation::ShadowResult *ab,
        hkaiBooleanOperation::ShadowResult *ba,
        hkaiBooleanOperation::ShadowResult *res)
{
  hkVector4f v3; // xmm3
  hkVector4f v4; // xmm5
  hkVector4f v5; // xmm7
  hkVector4f v6; // xmm8
  __m128 v7; // xmm4
  __m128 v8; // xmm2
  __m128 v9; // xmm1
  __m128 v10; // xmm6
  __m128 v11; // xmm4
  __m128 v12; // xmm3
  __int64 result; // rax

  v3.m_quad = (__m128)ab->m_shadower;
  v4.m_quad = (__m128)ab->m_shadowee;
  v5.m_quad = (__m128)ba->m_shadowee;
  v6.m_quad = (__m128)ba->m_shadower;
  v7 = _mm_sub_ps(_mm_shuffle_ps(v6.m_quad, v6.m_quad, 85), _mm_shuffle_ps(v5.m_quad, v5.m_quad, 85));
  v8 = _mm_sub_ps(v7, _mm_sub_ps(_mm_shuffle_ps(v4.m_quad, v4.m_quad, 85), _mm_shuffle_ps(v3.m_quad, v3.m_quad, 85)));
  v9 = _mm_sub_ps((__m128)0i64, _mm_andnot_ps(_mm_cmpeq_ps((__m128)0i64, v8), _mm_div_ps(v7, v8)));
  v10 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v5.m_quad, v3.m_quad), v9), v5.m_quad);
  v11 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v6.m_quad, v4.m_quad), v9), v6.m_quad);
  v12 = _mm_cmple_ps(_mm_shuffle_ps(v10, v10, 170), _mm_shuffle_ps(v11, v11, 170));
  res->m_shadower.m_quad = _mm_or_ps(_mm_and_ps(v12, v11), _mm_andnot_ps(v12, v10));
  res->m_shadowee.m_quad = _mm_or_ps(_mm_andnot_ps(v12, v11), _mm_and_ps(v12, v10));
  if ( _mm_movemask_ps(v12) )
  {
    result = (unsigned int)res->m_x;
    res->m_s = result;
  }
  else
  {
    res->m_s = 0;
    return 0i64;
  }
  return result;
}

// File Line: 208
// RVA: 0xB9FE50
void __fastcall hkaiBooleanOperation::_calculateIntersect3(
        hkaiBooleanOperation::ShadowResult *ab,
        hkaiBooleanOperation::ShadowResult *ba,
        hkVector4f *res)
{
  hkVector4f v3; // xmm5
  hkVector4f v4; // xmm3
  __m128 v5; // xmm4
  __m128 v6; // xmm2

  v3.m_quad = (__m128)ba->m_shadowee;
  v4.m_quad = (__m128)ab->m_shadower;
  v5 = _mm_sub_ps(
         _mm_shuffle_ps(ba->m_shadower.m_quad, ba->m_shadower.m_quad, 170),
         _mm_shuffle_ps(v3.m_quad, v3.m_quad, 170));
  v6 = _mm_sub_ps(
         v5,
         _mm_sub_ps(
           _mm_shuffle_ps(ab->m_shadowee.m_quad, ab->m_shadowee.m_quad, 170),
           _mm_shuffle_ps(v4.m_quad, v4.m_quad, 170)));
  res->m_quad = _mm_add_ps(
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)0i64, _mm_andnot_ps(_mm_cmpeq_ps((__m128)0i64, v6), _mm_div_ps(v5, v6))),
                    _mm_sub_ps(v3.m_quad, v4.m_quad)),
                  v3.m_quad);
}

// File Line: 237
// RVA: 0xB9F8C0
int __fastcall hkaiBooleanOperation::_s11(hkVector4f *vs_ea, hkVector4f *ve_ea, hkVector4f *vs_eb, hkVector4f *ve_eb)
{
  __m128 v4; // xmm2
  __m128 m_quad; // xmm11
  __m128 v6; // xmm12
  __m128 v7; // xmm13
  __m128 v8; // xmm9
  __m128 v9; // xmm7
  __m128 v10; // xmm8
  __m128 v11; // xmm1
  hkVector4f v12; // xmm5
  unsigned int v13; // r8d
  int v14; // edx
  __m128 v15; // xmm3
  __m128 v16; // xmm4
  __m128 v17; // xmm0
  __m128 v18; // xmm4
  __m128 v19; // xmm1
  __m128 v20; // xmm0
  __m128 v21; // xmm2
  __m128 v22; // xmm5
  __m128 v23; // xmm10
  __m128 v24; // xmm6
  __m128 v25; // xmm1
  unsigned int v26; // r8d
  int v27; // ecx
  int v28; // eax
  __m128 v29; // xmm3
  __m128 v30; // xmm4
  __m128 v31; // xmm0
  __m128 v32; // xmm4
  __m128 v33; // xmm1
  int v34; // edx
  __m128 v35; // xmm1
  unsigned int v36; // r8d
  int v37; // ecx
  int v38; // eax
  __m128 v39; // xmm2
  __m128 v40; // xmm5
  __m128 v41; // xmm0
  __m128 v42; // xmm5
  __m128 v43; // xmm1
  __m128 v44; // xmm0
  __m128 v45; // xmm2
  __m128 v46; // xmm5
  int v47; // edx
  __m128 v48; // xmm6
  unsigned int v49; // r8d
  int v50; // ecx
  int v51; // eax
  __m128 v52; // xmm2
  __m128 v53; // xmm3
  __m128 v54; // xmm0
  __m128 v55; // xmm3
  __m128 v56; // xmm1
  __m128 v57; // xmm0
  __m128 v58; // xmm2
  __m128 v59; // xmm3
  int v60; // edx
  hkaiBooleanOperation::ShadowResult ba; // [rsp+20h] [rbp-89h] BYREF
  __m128 v63; // [rsp+58h] [rbp-51h]
  __m128 v64; // [rsp+68h] [rbp-41h]
  hkaiBooleanOperation::ShadowResult *v65; // [rsp+128h] [rbp+7Fh]

  v4 = 0i64;
  ba.m_x = 0;
  m_quad = ve_eb->m_quad;
  v6 = vs_eb->m_quad;
  v7 = ve_ea->m_quad;
  v8 = _mm_shuffle_ps(m_quad, m_quad, 0);
  v63 = 0i64;
  v9 = _mm_shuffle_ps(v7, v7, 0);
  v10 = _mm_shuffle_ps(v6, v6, 0);
  v64 = 0i64;
  v11 = _mm_cmple_ps(v9, v10);
  memset(&ba.m_shadower, 0, 28);
  v12.m_quad = 0i64;
  v13 = (_mm_movemask_ps(_mm_cmple_ps(v9, v8)) != 0) - (_mm_movemask_ps(v11) != 0);
  if ( v13 )
  {
    v14 = 0;
    v15 = _mm_or_ps(_mm_and_ps(v6, v11), _mm_andnot_ps(v11, m_quad));
    v16 = _mm_or_ps(_mm_and_ps(m_quad, v11), _mm_andnot_ps(v11, v6));
    v17 = _mm_shuffle_ps(v15, v15, 0);
    v18 = _mm_add_ps(
            _mm_mul_ps(
              _mm_sub_ps(v16, v15),
              _mm_div_ps(_mm_sub_ps(v9, v17), _mm_sub_ps(_mm_shuffle_ps(v16, v16, 0), v17))),
            v15);
    v19 = _mm_cmple_ps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps(v18, v18, 85));
    v20 = _mm_and_ps(v18, v19);
    v21 = _mm_andnot_ps(v19, v7);
    v22 = _mm_and_ps(v7, v19);
    if ( _mm_movemask_ps(v19) == 15 )
      v14 = v13;
    v4 = _mm_or_ps(v21, v20);
    v12.m_quad = _mm_or_ps(v22, _mm_andnot_ps(v19, v18));
    if ( v14 )
    {
      ba.m_x = v13;
      ba.m_s = v14;
      ba.m_shadower.m_quad.m128_u64[0] = v4.m128_u64[0];
      *(hkVector4f *)((char *)&ba.m_shadower + 8) = (hkVector4f)v12.m_quad;
    }
    else
    {
      ba.m_shadowee.m_quad.m128_u64[1] = v13;
      v63 = v4;
      v64 = v12.m_quad;
    }
  }
  else
  {
    v14 = 0;
  }
  v23 = vs_ea->m_quad;
  v24 = _mm_shuffle_ps(v23, v23, 0);
  v25 = _mm_cmple_ps(v24, v10);
  v26 = (_mm_movemask_ps(_mm_cmple_ps(v24, v8)) != 0) - (_mm_movemask_ps(v25) != 0);
  if ( v26 )
  {
    v27 = 0;
    v29 = _mm_or_ps(_mm_andnot_ps(v25, m_quad), _mm_and_ps(v6, v25));
    v30 = _mm_or_ps(_mm_andnot_ps(v25, v6), _mm_and_ps(m_quad, v25));
    v31 = _mm_shuffle_ps(v29, v29, 0);
    v32 = _mm_add_ps(
            _mm_mul_ps(
              _mm_sub_ps(v30, v29),
              _mm_div_ps(_mm_sub_ps(v24, v31), _mm_sub_ps(_mm_shuffle_ps(v30, v30, 0), v31))),
            v29);
    v33 = _mm_cmple_ps(_mm_shuffle_ps(v23, v23, 85), _mm_shuffle_ps(v32, v32, 85));
    v4 = _mm_or_ps(_mm_andnot_ps(v33, v23), _mm_and_ps(v32, v33));
    if ( _mm_movemask_ps(v33) == 15 )
      v27 = v26;
    v28 = v27;
    v12.m_quad = _mm_or_ps(_mm_andnot_ps(v33, v32), _mm_and_ps(v23, v33));
  }
  else
  {
    v27 = 0;
    v28 = 0;
  }
  v34 = v14 - v28;
  if ( v26 )
  {
    if ( v27 )
    {
      ba.m_x = v26;
      ba.m_s = v27;
      ba.m_shadower.m_quad.m128_u64[0] = v4.m128_u64[0];
      *(hkVector4f *)((char *)&ba.m_shadower + 8) = (hkVector4f)v12.m_quad;
    }
    else
    {
      ba.m_shadowee.m_quad.m128_u64[1] = v26;
      v63 = v4;
      v64 = v12.m_quad;
    }
  }
  v35 = _mm_cmple_ps(v24, v8);
  v36 = (_mm_movemask_ps(v35) != 0) - (_mm_movemask_ps(_mm_cmple_ps(v9, v8)) != 0);
  if ( v36 )
  {
    v37 = 0;
    v39 = _mm_or_ps(_mm_andnot_ps(v35, v7), _mm_and_ps(v23, v35));
    v40 = _mm_or_ps(_mm_andnot_ps(v35, v23), _mm_and_ps(v7, v35));
    v41 = _mm_shuffle_ps(v39, v39, 0);
    v42 = _mm_add_ps(
            _mm_mul_ps(
              _mm_sub_ps(v40, v39),
              _mm_div_ps(_mm_sub_ps(v8, v41), _mm_sub_ps(_mm_shuffle_ps(v40, v40, 0), v41))),
            v39);
    v43 = _mm_cmple_ps(_mm_shuffle_ps(v42, v42, 85), _mm_shuffle_ps(m_quad, m_quad, 85));
    v44 = _mm_andnot_ps(v43, v42);
    v45 = _mm_and_ps(v43, m_quad);
    v46 = _mm_and_ps(v42, v43);
    if ( _mm_movemask_ps(v43) == 15 )
      v37 = v36;
    v38 = v37;
    v4 = _mm_or_ps(v45, v44);
    v12.m_quad = _mm_or_ps(v46, _mm_andnot_ps(v43, m_quad));
  }
  else
  {
    v37 = 0;
    v38 = 0;
  }
  v47 = v38 + v34;
  if ( v36 )
  {
    if ( v37 )
    {
      ba.m_x = v36;
      ba.m_s = v37;
      ba.m_shadower.m_quad.m128_u64[0] = v4.m128_u64[0];
      *(hkVector4f *)((char *)&ba.m_shadower + 8) = (hkVector4f)v12.m_quad;
    }
    else
    {
      ba.m_shadowee.m_quad.m128_u64[1] = v36;
      v63 = v4;
      v64 = v12.m_quad;
    }
  }
  v48 = _mm_cmple_ps(v24, v10);
  v49 = (_mm_movemask_ps(v48) != 0) - (_mm_movemask_ps(_mm_cmple_ps(v9, v10)) != 0);
  if ( v49 )
  {
    v50 = 0;
    v52 = _mm_or_ps(_mm_and_ps(v48, v23), _mm_andnot_ps(v48, v7));
    v53 = _mm_or_ps(_mm_andnot_ps(v48, v23), _mm_and_ps(v48, v7));
    v54 = _mm_shuffle_ps(v52, v52, 0);
    v55 = _mm_add_ps(
            _mm_mul_ps(
              _mm_sub_ps(v53, v52),
              _mm_div_ps(_mm_sub_ps(v10, v54), _mm_sub_ps(_mm_shuffle_ps(v53, v53, 0), v54))),
            v52);
    v56 = _mm_cmple_ps(_mm_shuffle_ps(v55, v55, 85), _mm_shuffle_ps(v6, v6, 85));
    v57 = _mm_andnot_ps(v56, v55);
    v58 = _mm_and_ps(v56, v6);
    v59 = _mm_and_ps(v55, v56);
    if ( _mm_movemask_ps(v56) == 15 )
      v50 = v49;
    v51 = v50;
    v4 = _mm_or_ps(v58, v57);
    v12.m_quad = _mm_or_ps(_mm_andnot_ps(v56, v6), v59);
  }
  else
  {
    v50 = 0;
    v51 = 0;
  }
  v60 = v47 - v51;
  if ( v49 )
  {
    if ( v50 )
    {
      ba.m_x = v49;
      ba.m_s = v50;
      ba.m_shadower.m_quad.m128_u64[0] = v4.m128_u64[0];
      *(hkVector4f *)((char *)&ba.m_shadower + 8) = (hkVector4f)v12.m_quad;
    }
    else
    {
      ba.m_shadowee.m_quad.m128_u64[1] = v49;
      v63 = v4;
      v64 = v12.m_quad;
    }
  }
  v65->m_x = v60;
  if ( v60 )
    return hkaiBooleanOperation::_calculateIntersect2(
             (hkaiBooleanOperation::ShadowResult *)&ba.m_shadowee.m_quad.m128_u16[4],
             &ba,
             v65);
  v65->m_s = 0;
  return 0;
}

// File Line: 277
// RVA: 0xB9FEB0
__int64 __fastcall hkaiBooleanOperation::_calculate2dLineIntersect(
        hkVector4f *vs_ea,
        hkVector4f *ve_ea,
        hkVector4f *vs_eb,
        hkVector4f *ve_eb)
{
  __m128 v4; // xmm2
  __m128 m_quad; // xmm11
  __m128 v6; // xmm12
  __m128 v7; // xmm13
  __m128 v8; // xmm9
  __m128 v9; // xmm7
  __m128 v10; // xmm8
  __m128 v11; // xmm1
  hkVector4f v12; // xmm5
  unsigned int v13; // r8d
  int v14; // edx
  __m128 v15; // xmm3
  __m128 v16; // xmm4
  __m128 v17; // xmm0
  __m128 v18; // xmm4
  __m128 v19; // xmm1
  __m128 v20; // xmm0
  __m128 v21; // xmm2
  __m128 v22; // xmm5
  __m128 v23; // xmm10
  __m128 v24; // xmm6
  __m128 v25; // xmm1
  unsigned int v26; // r8d
  int v27; // ecx
  int v28; // eax
  __m128 v29; // xmm3
  __m128 v30; // xmm4
  __m128 v31; // xmm0
  __m128 v32; // xmm4
  __m128 v33; // xmm1
  int v34; // edx
  __m128 v35; // xmm1
  unsigned int v36; // r8d
  int v37; // ecx
  int v38; // eax
  __m128 v39; // xmm2
  __m128 v40; // xmm5
  __m128 v41; // xmm0
  __m128 v42; // xmm5
  __m128 v43; // xmm1
  __m128 v44; // xmm0
  __m128 v45; // xmm2
  __m128 v46; // xmm5
  int v47; // edx
  __m128 v48; // xmm6
  unsigned int v49; // r8d
  int v50; // ecx
  int v51; // eax
  __m128 v52; // xmm2
  __m128 v53; // xmm3
  __m128 v54; // xmm0
  __m128 v55; // xmm3
  __m128 v56; // xmm1
  __m128 v57; // xmm0
  __m128 v58; // xmm2
  __m128 v59; // xmm3
  int v60; // edx
  hkaiBooleanOperation::ShadowResult ba; // [rsp+20h] [rbp-89h] BYREF
  __m128 v63; // [rsp+58h] [rbp-51h]
  __m128 v64; // [rsp+68h] [rbp-41h]
  hkaiBooleanOperation::ShadowResult *v65; // [rsp+128h] [rbp+7Fh]

  v4 = 0i64;
  ba.m_x = 0;
  m_quad = ve_eb->m_quad;
  v6 = vs_eb->m_quad;
  v7 = ve_ea->m_quad;
  v8 = _mm_shuffle_ps(m_quad, m_quad, 0);
  v63 = 0i64;
  v9 = _mm_shuffle_ps(v7, v7, 0);
  v10 = _mm_shuffle_ps(v6, v6, 0);
  v64 = 0i64;
  v11 = _mm_cmple_ps(v9, v10);
  memset(&ba.m_shadower, 0, 28);
  v12.m_quad = 0i64;
  v13 = (_mm_movemask_ps(_mm_cmple_ps(v9, v8)) != 0) - (_mm_movemask_ps(v11) != 0);
  if ( v13 )
  {
    v14 = 0;
    v15 = _mm_or_ps(_mm_and_ps(v6, v11), _mm_andnot_ps(v11, m_quad));
    v16 = _mm_or_ps(_mm_and_ps(m_quad, v11), _mm_andnot_ps(v11, v6));
    v17 = _mm_shuffle_ps(v15, v15, 0);
    v18 = _mm_add_ps(
            _mm_mul_ps(
              _mm_sub_ps(v16, v15),
              _mm_div_ps(_mm_sub_ps(v9, v17), _mm_sub_ps(_mm_shuffle_ps(v16, v16, 0), v17))),
            v15);
    v19 = _mm_cmple_ps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps(v18, v18, 85));
    v20 = _mm_and_ps(v18, v19);
    v21 = _mm_andnot_ps(v19, v7);
    v22 = _mm_and_ps(v7, v19);
    if ( _mm_movemask_ps(v19) == 15 )
      v14 = v13;
    v4 = _mm_or_ps(v21, v20);
    v12.m_quad = _mm_or_ps(v22, _mm_andnot_ps(v19, v18));
    if ( v14 )
    {
      ba.m_x = v13;
      ba.m_s = v14;
      ba.m_shadower.m_quad.m128_u64[0] = v4.m128_u64[0];
      *(hkVector4f *)((char *)&ba.m_shadower + 8) = (hkVector4f)v12.m_quad;
    }
    else
    {
      ba.m_shadowee.m_quad.m128_u64[1] = v13;
      v63 = v4;
      v64 = v12.m_quad;
    }
  }
  else
  {
    v14 = 0;
  }
  v23 = vs_ea->m_quad;
  v24 = _mm_shuffle_ps(v23, v23, 0);
  v25 = _mm_cmple_ps(v24, v10);
  v26 = (_mm_movemask_ps(_mm_cmple_ps(v24, v8)) != 0) - (_mm_movemask_ps(v25) != 0);
  if ( v26 )
  {
    v27 = 0;
    v29 = _mm_or_ps(_mm_andnot_ps(v25, m_quad), _mm_and_ps(v6, v25));
    v30 = _mm_or_ps(_mm_andnot_ps(v25, v6), _mm_and_ps(m_quad, v25));
    v31 = _mm_shuffle_ps(v29, v29, 0);
    v32 = _mm_add_ps(
            _mm_mul_ps(
              _mm_sub_ps(v30, v29),
              _mm_div_ps(_mm_sub_ps(v24, v31), _mm_sub_ps(_mm_shuffle_ps(v30, v30, 0), v31))),
            v29);
    v33 = _mm_cmple_ps(_mm_shuffle_ps(v23, v23, 85), _mm_shuffle_ps(v32, v32, 85));
    v4 = _mm_or_ps(_mm_andnot_ps(v33, v23), _mm_and_ps(v32, v33));
    if ( _mm_movemask_ps(v33) == 15 )
      v27 = v26;
    v28 = v27;
    v12.m_quad = _mm_or_ps(_mm_andnot_ps(v33, v32), _mm_and_ps(v23, v33));
  }
  else
  {
    v27 = 0;
    v28 = 0;
  }
  v34 = v14 - v28;
  if ( v26 )
  {
    if ( v27 )
    {
      ba.m_x = v26;
      ba.m_s = v27;
      ba.m_shadower.m_quad.m128_u64[0] = v4.m128_u64[0];
      *(hkVector4f *)((char *)&ba.m_shadower + 8) = (hkVector4f)v12.m_quad;
    }
    else
    {
      ba.m_shadowee.m_quad.m128_u64[1] = v26;
      v63 = v4;
      v64 = v12.m_quad;
    }
  }
  v35 = _mm_cmple_ps(v24, v8);
  v36 = (_mm_movemask_ps(v35) != 0) - (_mm_movemask_ps(_mm_cmple_ps(v9, v8)) != 0);
  if ( v36 )
  {
    v37 = 0;
    v39 = _mm_or_ps(_mm_andnot_ps(v35, v7), _mm_and_ps(v23, v35));
    v40 = _mm_or_ps(_mm_andnot_ps(v35, v23), _mm_and_ps(v7, v35));
    v41 = _mm_shuffle_ps(v39, v39, 0);
    v42 = _mm_add_ps(
            _mm_mul_ps(
              _mm_sub_ps(v40, v39),
              _mm_div_ps(_mm_sub_ps(v8, v41), _mm_sub_ps(_mm_shuffle_ps(v40, v40, 0), v41))),
            v39);
    v43 = _mm_cmple_ps(_mm_shuffle_ps(v42, v42, 85), _mm_shuffle_ps(m_quad, m_quad, 85));
    v44 = _mm_andnot_ps(v43, v42);
    v45 = _mm_and_ps(v43, m_quad);
    v46 = _mm_and_ps(v42, v43);
    if ( _mm_movemask_ps(v43) == 15 )
      v37 = v36;
    v38 = v37;
    v4 = _mm_or_ps(v45, v44);
    v12.m_quad = _mm_or_ps(v46, _mm_andnot_ps(v43, m_quad));
  }
  else
  {
    v37 = 0;
    v38 = 0;
  }
  v47 = v38 + v34;
  if ( v36 )
  {
    if ( v37 )
    {
      ba.m_x = v36;
      ba.m_s = v37;
      ba.m_shadower.m_quad.m128_u64[0] = v4.m128_u64[0];
      *(hkVector4f *)((char *)&ba.m_shadower + 8) = (hkVector4f)v12.m_quad;
    }
    else
    {
      ba.m_shadowee.m_quad.m128_u64[1] = v36;
      v63 = v4;
      v64 = v12.m_quad;
    }
  }
  v48 = _mm_cmple_ps(v24, v10);
  v49 = (_mm_movemask_ps(v48) != 0) - (_mm_movemask_ps(_mm_cmple_ps(v9, v10)) != 0);
  if ( v49 )
  {
    v50 = 0;
    v52 = _mm_or_ps(_mm_and_ps(v48, v23), _mm_andnot_ps(v48, v7));
    v53 = _mm_or_ps(_mm_andnot_ps(v48, v23), _mm_and_ps(v48, v7));
    v54 = _mm_shuffle_ps(v52, v52, 0);
    v55 = _mm_add_ps(
            _mm_mul_ps(
              _mm_sub_ps(v53, v52),
              _mm_div_ps(_mm_sub_ps(v10, v54), _mm_sub_ps(_mm_shuffle_ps(v53, v53, 0), v54))),
            v52);
    v56 = _mm_cmple_ps(_mm_shuffle_ps(v55, v55, 85), _mm_shuffle_ps(v6, v6, 85));
    v57 = _mm_andnot_ps(v56, v55);
    v58 = _mm_and_ps(v56, v6);
    v59 = _mm_and_ps(v55, v56);
    if ( _mm_movemask_ps(v56) == 15 )
      v50 = v49;
    v51 = v50;
    v4 = _mm_or_ps(v58, v57);
    v12.m_quad = _mm_or_ps(_mm_andnot_ps(v56, v6), v59);
  }
  else
  {
    v50 = 0;
    v51 = 0;
  }
  v60 = v47 - v51;
  if ( v49 )
  {
    if ( v50 )
    {
      ba.m_x = v49;
      ba.m_s = v50;
      ba.m_shadower.m_quad.m128_u64[0] = v4.m128_u64[0];
      *(hkVector4f *)((char *)&ba.m_shadower + 8) = (hkVector4f)v12.m_quad;
    }
    else
    {
      ba.m_shadowee.m_quad.m128_u64[1] = v49;
      v63 = v4;
      v64 = v12.m_quad;
    }
  }
  v65->m_x = v60;
  if ( v60 )
  {
    hkaiBooleanOperation::_calculateIntersect2(
      (hkaiBooleanOperation::ShadowResult *)&ba.m_shadowee.m_quad.m128_u16[4],
      &ba,
      v65);
    return (unsigned int)v65->m_x;
  }
  else
  {
    v65->m_s = 0;
    return 0i64;
  }
}

// File Line: 320
// RVA: 0xBA0350
__int64 __fastcall hkaiBooleanOperation::_s02(
        hkaiBooleanOperation *this,
        hkVector4f *va,
        int faceBIndex,
        hkaiBooleanOperation::ShadowResult *res)
{
  hkaiEdgeGeometry::Edge *const **m_data; // rax
  unsigned int **v6; // r10
  unsigned int **v7; // r11
  hkVector4f *m_vertices; // r8
  __m128 m_quad; // xmm8
  hkVector4f v10; // xmm2
  hkVector4f v11; // xmm5
  __m128 v12; // xmm3
  __m128 v13; // xmm4
  __m128 v14; // xmm9
  __m128 v15; // xmm6
  int v16; // edx
  int v17; // ecx
  int v18; // eax
  __m128 v19; // xmm2
  __m128 v20; // xmm4
  __m128 v21; // xmm0
  __m128 v22; // xmm4
  __m128 v23; // xmm1
  __m128 v24; // xmm2
  __m128 v25; // xmm0
  __m128 v26; // xmm5
  hkaiBooleanOperation::ShadowResult ba; // [rsp+20h] [rbp-A8h] BYREF
  hkaiBooleanOperation::ShadowResult ab; // [rsp+50h] [rbp-78h] BYREF

  res->m_x = 0;
  ab.m_x = 0;
  ba.m_x = 0;
  memset(&ab.m_shadower, 0, 32);
  memset(&ba.m_shadower, 0, 32);
  m_data = this->m_b.m_faceEdges.m_faceStartEdges.m_data;
  v6 = (unsigned int **)m_data[faceBIndex];
  v7 = (unsigned int **)m_data[faceBIndex + 1];
  m_vertices = this->m_b.m_vertices;
  if ( v6 != v7 )
  {
    do
    {
      m_quad = va->m_quad;
      v10.m_quad = 0i64;
      v11.m_quad = 0i64;
      v12 = _mm_shuffle_ps(m_quad, m_quad, 0);
      v13 = m_vertices[(*v6)[1]].m_quad;
      v14 = m_vertices[**v6].m_quad;
      v15 = _mm_cmple_ps(v12, _mm_shuffle_ps(v14, v14, 0));
      v16 = (_mm_movemask_ps(_mm_cmple_ps(v12, _mm_shuffle_ps(v13, v13, 0))) != 0) - (_mm_movemask_ps(v15) != 0);
      if ( v16 )
      {
        v17 = 0;
        v19 = _mm_or_ps(_mm_and_ps(v14, v15), _mm_andnot_ps(v15, v13));
        v20 = _mm_or_ps(_mm_and_ps(v13, v15), _mm_andnot_ps(v15, v14));
        v21 = _mm_shuffle_ps(v19, v19, 0);
        v22 = _mm_add_ps(
                _mm_mul_ps(
                  _mm_sub_ps(v20, v19),
                  _mm_div_ps(_mm_sub_ps(v12, v21), _mm_sub_ps(_mm_shuffle_ps(v20, v20, 0), v21))),
                v19);
        v23 = _mm_cmple_ps(_mm_shuffle_ps(m_quad, m_quad, 85), _mm_shuffle_ps(v22, v22, 85));
        v24 = _mm_and_ps(v22, v23);
        v25 = _mm_andnot_ps(v23, m_quad);
        v26 = _mm_and_ps(m_quad, v23);
        if ( _mm_movemask_ps(v23) == 15 )
          v17 = v16;
        v18 = v17;
        v10.m_quad = _mm_or_ps(v24, v25);
        v11.m_quad = _mm_or_ps(v26, _mm_andnot_ps(v23, v22));
      }
      else
      {
        v17 = 0;
        v18 = 0;
      }
      res->m_x -= v18;
      if ( v16 )
      {
        if ( v17 )
        {
          ba.m_x = v16;
          ba.m_s = v17;
          ba.m_shadower = (hkVector4f)v10.m_quad;
          ba.m_shadowee = (hkVector4f)v11.m_quad;
        }
        else
        {
          ab.m_x = v16;
          ab.m_s = 0;
          ab.m_shadower = (hkVector4f)v10.m_quad;
          ab.m_shadowee = (hkVector4f)v11.m_quad;
        }
      }
      ++v6;
    }
    while ( v6 != v7 );
    if ( res->m_x )
      return hkaiBooleanOperation::_calculateIntersect2(&ab, &ba, res);
  }
  res->m_shadower = 0i64;
  res->m_shadowee = 0i64;
  res->m_s = 0;
  return 0i64;
}

// File Line: 355
// RVA: 0xBA0550
__int64 __fastcall hkaiBooleanOperation::_s20(
        hkaiBooleanOperation *this,
        int faceAIndex,
        hkVector4f *vb,
        hkaiBooleanOperation::ShadowResult *res)
{
  hkaiEdgeGeometry::Edge *const **m_data; // rax
  hkVector4f *m_vertices; // r10
  unsigned int **v6; // r11
  unsigned int **v8; // r8
  __m128 m_quad; // xmm6
  hkVector4f v10; // xmm2
  hkVector4f v11; // xmm3
  __m128 v12; // xmm4
  __m128 v13; // xmm8
  __m128 v14; // xmm7
  __m128 v15; // xmm1
  int v16; // edx
  int v17; // ecx
  int v18; // eax
  __m128 v19; // xmm2
  __m128 v20; // xmm3
  __m128 v21; // xmm0
  __m128 v22; // xmm3
  __m128 v23; // xmm1
  __m128 v24; // xmm2
  __m128 v25; // xmm0
  __m128 v26; // xmm3
  hkaiBooleanOperation::ShadowResult ba; // [rsp+20h] [rbp-98h] BYREF
  hkaiBooleanOperation::ShadowResult ab; // [rsp+50h] [rbp-68h] BYREF

  res->m_x = 0;
  m_data = this->m_a.m_faceEdges.m_faceStartEdges.m_data;
  m_vertices = this->m_a.m_vertices;
  memset(&ba.m_shadower, 0, 32);
  memset(&ab.m_shadower, 0, 32);
  v6 = (unsigned int **)m_data[faceAIndex + 1];
  v8 = (unsigned int **)m_data[faceAIndex];
  ba.m_x = 0;
  ab.m_x = 0;
  if ( v8 != v6 )
  {
    do
    {
      m_quad = vb->m_quad;
      v10.m_quad = 0i64;
      v11.m_quad = 0i64;
      v12 = _mm_shuffle_ps(m_quad, m_quad, 0);
      v13 = m_vertices[(*v8)[1]].m_quad;
      v14 = m_vertices[**v8].m_quad;
      v15 = _mm_cmple_ps(_mm_shuffle_ps(v14, v14, 0), v12);
      v16 = (_mm_movemask_ps(v15) != 0) - (_mm_movemask_ps(_mm_cmple_ps(_mm_shuffle_ps(v13, v13, 0), v12)) != 0);
      if ( v16 )
      {
        v17 = 0;
        v19 = _mm_or_ps(_mm_and_ps(v14, v15), _mm_andnot_ps(v15, v13));
        v20 = _mm_or_ps(_mm_and_ps(v13, v15), _mm_andnot_ps(v15, v14));
        v21 = _mm_shuffle_ps(v19, v19, 0);
        v22 = _mm_add_ps(
                _mm_mul_ps(
                  _mm_sub_ps(v20, v19),
                  _mm_div_ps(_mm_sub_ps(v12, v21), _mm_sub_ps(_mm_shuffle_ps(v20, v20, 0), v21))),
                v19);
        v23 = _mm_cmple_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(m_quad, m_quad, 85));
        v24 = _mm_and_ps(m_quad, v23);
        v25 = _mm_andnot_ps(v23, v22);
        v26 = _mm_and_ps(v22, v23);
        if ( _mm_movemask_ps(v23) == 15 )
          v17 = v16;
        v18 = v17;
        v10.m_quad = _mm_or_ps(v24, v25);
        v11.m_quad = _mm_or_ps(v26, _mm_andnot_ps(v23, m_quad));
      }
      else
      {
        v17 = 0;
        v18 = 0;
      }
      res->m_x += v18;
      if ( v16 )
      {
        if ( v17 )
        {
          ba.m_x = v16;
          ba.m_s = v17;
          ba.m_shadower = (hkVector4f)v10.m_quad;
          ba.m_shadowee = (hkVector4f)v11.m_quad;
        }
        else
        {
          ab.m_x = v16;
          ab.m_s = 0;
          ab.m_shadower = (hkVector4f)v10.m_quad;
          ab.m_shadowee = (hkVector4f)v11.m_quad;
        }
      }
      ++v8;
    }
    while ( v8 != v6 );
    if ( res->m_x )
      return hkaiBooleanOperation::_calculateIntersect2(&ab, &ba, res);
  }
  res->m_shadower = 0i64;
  res->m_shadowee = 0i64;
  res->m_s = 0;
  return 0i64;
}

// File Line: 389
// RVA: 0xBA0740
__int64 __fastcall hkaiBooleanOperation::_x12(
        hkaiBooleanOperation *this,
        hkaiEdgeGeometry::Edge *edgeA,
        int faceBIndex,
        hkVector4f *res)
{
  hkVector4f *m_vertices; // rsi
  hkVector4f *v5; // rax
  __int64 m_b; // rdx
  __int64 v8; // r13
  int v10; // edi
  unsigned int v11; // edi
  __int64 m_a; // r14
  __int64 v13; // r15
  hkaiEdgeGeometry::Edge *const **m_data; // rax
  unsigned int **v15; // rbx
  hkVector4f *v16; // r14
  hkVector4f *v17; // r15
  unsigned int **i; // rsi
  hkaiBooleanOperation::ShadowResult resa; // [rsp+30h] [rbp-69h] BYREF
  hkaiBooleanOperation::ShadowResult ba; // [rsp+60h] [rbp-39h] BYREF
  hkaiBooleanOperation::ShadowResult ab; // [rsp+90h] [rbp-9h] BYREF
  hkVector4f *v23; // [rsp+100h] [rbp+67h]

  m_vertices = this->m_a.m_vertices;
  v5 = this->m_b.m_vertices;
  m_b = edgeA->m_b;
  v8 = faceBIndex;
  memset(&ba.m_shadower, 0, 32);
  memset(&ab.m_shadower, 0, 32);
  memset(&resa.m_shadower, 0, 32);
  ba.m_x = 0;
  ab.m_x = 0;
  v23 = v5;
  v10 = -(int)hkaiBooleanOperation::_s02(this, &m_vertices[m_b], faceBIndex, &resa);
  if ( resa.m_x )
  {
    if ( resa.m_s )
    {
      ba.m_x = resa.m_x;
      ba.m_s = resa.m_s;
      ba.m_shadower = resa.m_shadower;
      ba.m_shadowee = resa.m_shadowee;
    }
    else
    {
      ab.m_x = resa.m_x;
      ab.m_s = 0;
      ab.m_shadower = resa.m_shadower;
      ab.m_shadowee = resa.m_shadowee;
    }
  }
  v11 = hkaiBooleanOperation::_s02(this, &m_vertices[edgeA->m_a], v8, &resa) + v10;
  if ( resa.m_x )
  {
    if ( resa.m_s )
    {
      ba.m_x = resa.m_x;
      ba.m_s = resa.m_s;
      ba.m_shadower = resa.m_shadower;
      ba.m_shadowee = resa.m_shadowee;
    }
    else
    {
      ab.m_x = resa.m_x;
      ab.m_s = 0;
      ab.m_shadower = resa.m_shadower;
      ab.m_shadowee = resa.m_shadowee;
    }
  }
  m_a = edgeA->m_a;
  v13 = edgeA->m_b;
  m_data = this->m_b.m_faceEdges.m_faceStartEdges.m_data;
  v15 = (unsigned int **)m_data[v8];
  v16 = &m_vertices[m_a];
  v17 = &m_vertices[v13];
  for ( i = (unsigned int **)m_data[v8 + 1]; v15 != i; ++v15 )
  {
    v11 -= hkaiBooleanOperation::_s11(v16, v17, &v23[**v15], &v23[(*v15)[1]]);
    if ( resa.m_x )
    {
      if ( resa.m_s )
      {
        ba.m_x = resa.m_x;
        ba.m_s = resa.m_s;
        ba.m_shadower = resa.m_shadower;
        ba.m_shadowee = resa.m_shadowee;
      }
      else
      {
        ab.m_x = resa.m_x;
        ab.m_s = 0;
        ab.m_shadower = resa.m_shadower;
        ab.m_shadowee = resa.m_shadowee;
      }
    }
  }
  if ( !v11 )
    return 0i64;
  hkaiBooleanOperation::_calculateIntersect3(&ab, &ba, res);
  return v11;
}

// File Line: 434
// RVA: 0xBA0920
__int64 __fastcall hkaiBooleanOperation::_x21(
        hkaiBooleanOperation *this,
        int faceAIndex,
        hkaiEdgeGeometry::Edge *edgeB,
        hkVector4f *res)
{
  hkVector4f *m_vertices; // r12
  hkVector4f *v5; // rax
  __int64 m_b; // r8
  __int64 v8; // r13
  int v10; // edi
  unsigned int v11; // edi
  hkaiEdgeGeometry::Edge *const **m_data; // rax
  __int64 m_a; // r14
  __int64 v14; // r15
  unsigned int **v15; // rbx
  unsigned int **v16; // rsi
  hkVector4f *v17; // r14
  hkVector4f *i; // r15
  hkaiBooleanOperation::ShadowResult resa; // [rsp+30h] [rbp-69h] BYREF
  hkaiBooleanOperation::ShadowResult ba; // [rsp+60h] [rbp-39h] BYREF
  hkaiBooleanOperation::ShadowResult ab; // [rsp+90h] [rbp-9h] BYREF
  hkVector4f *v23; // [rsp+100h] [rbp+67h]

  m_vertices = this->m_b.m_vertices;
  v5 = this->m_a.m_vertices;
  m_b = edgeB->m_b;
  v8 = faceAIndex;
  memset(&ba.m_shadower, 0, 32);
  memset(&ab.m_shadower, 0, 32);
  memset(&resa.m_shadower, 0, 32);
  ba.m_x = 0;
  ab.m_x = 0;
  v23 = v5;
  v10 = hkaiBooleanOperation::_s20(this, faceAIndex, &m_vertices[m_b], &resa);
  if ( resa.m_x )
  {
    if ( resa.m_s )
    {
      ba.m_x = resa.m_x;
      ba.m_s = resa.m_s;
      ba.m_shadower = resa.m_shadower;
      ba.m_shadowee = resa.m_shadowee;
    }
    else
    {
      ab.m_x = resa.m_x;
      ab.m_s = 0;
      ab.m_shadower = resa.m_shadower;
      ab.m_shadowee = resa.m_shadowee;
    }
  }
  v11 = v10 - hkaiBooleanOperation::_s20(this, v8, &m_vertices[edgeB->m_a], &resa);
  if ( resa.m_x )
  {
    if ( resa.m_s )
    {
      ba.m_x = resa.m_x;
      ba.m_s = resa.m_s;
      ba.m_shadower = resa.m_shadower;
      ba.m_shadowee = resa.m_shadowee;
    }
    else
    {
      ab.m_x = resa.m_x;
      ab.m_s = 0;
      ab.m_shadower = resa.m_shadower;
      ab.m_shadowee = resa.m_shadowee;
    }
  }
  m_data = this->m_a.m_faceEdges.m_faceStartEdges.m_data;
  m_a = edgeB->m_a;
  v14 = edgeB->m_b;
  v15 = (unsigned int **)m_data[v8];
  v16 = (unsigned int **)m_data[v8 + 1];
  v17 = &m_vertices[m_a];
  for ( i = &m_vertices[v14]; v15 != v16; ++v15 )
  {
    v11 -= hkaiBooleanOperation::_s11(&v23[**v15], &v23[(*v15)[1]], v17, i);
    if ( resa.m_x )
    {
      if ( resa.m_s )
      {
        ba.m_x = resa.m_x;
        ba.m_s = resa.m_s;
        ba.m_shadower = resa.m_shadower;
        ba.m_shadowee = resa.m_shadowee;
      }
      else
      {
        ab.m_x = resa.m_x;
        ab.m_s = 0;
        ab.m_shadower = resa.m_shadower;
        ab.m_shadowee = resa.m_shadowee;
      }
    }
  }
  if ( !v11 )
    return 0i64;
  hkaiBooleanOperation::_calculateIntersect3(&ab, &ba, res);
  return v11;
}

// File Line: 480
// RVA: 0xBA1890
hkResult *__fastcall hkaiBooleanOperation::_addStartEndVertices(
        hkaiBooleanOperation *this,
        hkResult *result,
        unsigned int feature,
        unsigned int a,
        int index,
        int count)
{
  int v6; // esi
  unsigned int v10; // r9d
  int v11; // r9d
  hkArray<hkaiBooleanOperation::SortVertex,hkContainerHeapAllocator> *p_m_startVertices; // rdi
  int v13; // eax
  int v14; // eax
  int v15; // eax
  hkaiBooleanOperation::SortVertex *v16; // rcx
  __int64 m_size; // r12
  int v18; // r9d
  hkResult *v19; // rcx
  int v20; // r9d
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int *p_m_index; // rax
  __int64 v25; // rcx
  hkResult resulta; // [rsp+30h] [rbp-28h] BYREF
  char v28; // [rsp+34h] [rbp-24h] BYREF
  hkResult v29; // [rsp+38h] [rbp-20h] BYREF

  v6 = count;
  v10 = abs32(count);
  if ( count <= 0 )
  {
    v20 = this->m_startVertices.m_size + v10;
    p_m_startVertices = &this->m_startVertices;
    v21 = this->m_startVertices.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v21 >= v20 )
    {
      resulta.m_enum = HK_SUCCESS;
    }
    else
    {
      v22 = 2 * v21;
      if ( v20 < v22 )
        v20 = v22;
      hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, p_m_startVertices, v20, 16);
      if ( resulta.m_enum )
      {
        result->m_enum = HK_FAILURE;
        return result;
      }
    }
    v15 = p_m_startVertices->m_capacityAndFlags & 0x3FFFFFFF;
    if ( v6 == -1 )
    {
      if ( p_m_startVertices->m_size == v15 )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, p_m_startVertices, 16);
      goto LABEL_11;
    }
    m_size = p_m_startVertices->m_size;
    v6 = -v6;
    v18 = m_size + v6;
    if ( v15 < (int)m_size + v6 )
    {
      v19 = &v29;
      goto LABEL_26;
    }
LABEL_29:
    p_m_startVertices->m_size += v6;
    if ( v6 > 0 )
    {
      p_m_index = &p_m_startVertices->m_data[m_size].m_index;
      v25 = (unsigned int)v6;
      do
      {
        *(p_m_index - 1) = feature;
        p_m_index[1] = a;
        *p_m_index = index;
        p_m_index += 4;
        --v25;
      }
      while ( v25 );
    }
    goto LABEL_32;
  }
  v11 = this->m_endVertices.m_size + v10;
  p_m_startVertices = &this->m_endVertices;
  v13 = this->m_endVertices.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v13 >= v11 )
  {
    count = 0;
    goto LABEL_8;
  }
  v14 = 2 * v13;
  if ( v11 < v14 )
    v11 = v14;
  hkArrayUtil::_reserve((hkResult *)&count, &hkContainerHeapAllocator::s_alloc, p_m_startVertices, v11, 16);
  if ( !count )
  {
LABEL_8:
    v15 = p_m_startVertices->m_capacityAndFlags & 0x3FFFFFFF;
    if ( v6 == 1 )
    {
      if ( p_m_startVertices->m_size == v15 )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, p_m_startVertices, 16);
LABEL_11:
      v16 = &p_m_startVertices->m_data[p_m_startVertices->m_size++];
      v16->m_feature = feature;
      v16->m_vertexIndex = a;
      v16->m_dist = 0.0;
      v16->m_index = index;
LABEL_32:
      result->m_enum = HK_SUCCESS;
      return result;
    }
    m_size = p_m_startVertices->m_size;
    v18 = m_size + v6;
    if ( v15 < (int)m_size + v6 )
    {
      v19 = (hkResult *)&v28;
LABEL_26:
      v23 = 2 * v15;
      if ( v18 < v23 )
        v18 = v23;
      hkArrayUtil::_reserve(v19, &hkContainerHeapAllocator::s_alloc, p_m_startVertices, v18, 16);
      goto LABEL_29;
    }
    goto LABEL_29;
  }
  result->m_enum = HK_FAILURE;
  return result;
}

// File Line: 590
// RVA: 0xBA2900
hkResult *__fastcall hkaiBooleanOperation::_simpleClassifyFaceAEdgeB(
        hkaiBooleanOperation *this,
        hkResult *result,
        hkaiBooleanFilter *filter)
{
  hkaiEdgeGeometry *m_geometry; // r12
  hkVector4f v4; // xmm6
  unsigned int v5; // edi
  __int64 v6; // rbx
  hkVector4f v7; // xmm7
  __int64 v11; // rbp
  int *v12; // rdx
  hkVector4f *m_data; // rcx
  hkResult resulta; // [rsp+70h] [rbp+8h] BYREF
  hkKeyPair pair; // [rsp+88h] [rbp+20h] BYREF

  m_geometry = this->m_b.m_geometry;
  v4.m_quad = (__m128)this->m_a.m_aabb.m_min;
  v5 = 0;
  v6 = 0i64;
  v7.m_quad = (__m128)this->m_a.m_aabb.m_max;
  v11 = this->m_b.m_uniqueEdges.m_startUniqueEdge.m_size - 1;
  if ( this->m_b.m_uniqueEdges.m_startUniqueEdge.m_size - 1 <= 0 )
  {
LABEL_5:
    result->m_enum = HK_SUCCESS;
  }
  else
  {
    while ( 1 )
    {
      v12 = (int *)*this->m_b.m_uniqueEdges.m_startUniqueEdge.m_data[v6];
      m_data = m_geometry->m_vertices.m_data;
      if ( (_mm_movemask_ps(
              _mm_and_ps(
                _mm_cmple_ps(v4.m_quad, _mm_max_ps(m_data[*v12].m_quad, m_data[v12[1]].m_quad)),
                _mm_cmple_ps(_mm_min_ps(m_data[*v12].m_quad, m_data[v12[1]].m_quad), v7.m_quad))) & 7) == 7 )
      {
        pair.m_keyA = 1;
        pair.m_keyB = v5;
        hkaiBooleanOperation::_classifyFaceAEdgeB(this, &resulta, &pair, filter);
        if ( resulta.m_enum )
          break;
      }
      ++v6;
      ++v5;
      if ( v6 >= v11 )
        goto LABEL_5;
    }
    result->m_enum = HK_FAILURE;
  }
  return result;
}

// File Line: 621
// RVA: 0xBA2A20
hkResult *__fastcall hkaiBooleanOperation::_simpleClassifyEdgeAFaceB(
        hkaiBooleanOperation *this,
        hkResult *result,
        hkaiBooleanFilter *filter)
{
  hkVector4f *m_data; // rcx
  hkaiEdgeGeometry::Edge *const **v6; // r10
  char *v8; // r9
  __int64 v9; // r11
  hkaiEdgeGeometry::Edge *const *v10; // rax
  __m128 m_quad; // xmm2
  __int64 m_b; // rax
  __m128 v13; // xmm0
  __m128 v14; // xmm2
  unsigned int v15; // esi
  hkArray<hkVector4f,hkContainerHeapAllocator> *p_m_vertices; // rcx
  __int64 v17; // r12
  __int64 v18; // r14
  hkaiEdgeGeometry::Edge *const **v19; // rax
  hkVector4f *v20; // r9
  hkaiEdgeGeometry::Edge *const *v21; // rdx
  hkaiEdgeGeometry::Edge *const *v22; // r8
  hkaiEdgeGeometry::Edge *v23; // rax
  int **v24; // rdx
  __m128 v25; // xmm6
  __m128 i; // xmm7
  int *v27; // rax
  signed int v28; // ebx
  __m128 *v29; // rdi
  hkArray<hkVector4f,hkContainerHeapAllocator> *v31; // [rsp+20h] [rbp-C8h]
  char v32[96]; // [rsp+30h] [rbp-B8h] BYREF
  hkResult resulta; // [rsp+F0h] [rbp+8h] BYREF
  hkKeyPair pair; // [rsp+108h] [rbp+20h] BYREF

  m_data = this->m_a.m_geometry->m_vertices.m_data;
  v6 = this->m_a.m_uniqueEdges.m_startUniqueEdge.m_data;
  v8 = v32;
  v9 = 3i64;
  do
  {
    v10 = *v6;
    v8 += 32;
    ++v6;
    m_quad = m_data[**(int **)v10].m_quad;
    m_b = (int)(*v10)->m_b;
    v13 = _mm_min_ps(m_quad, m_data[m_b].m_quad);
    v14 = _mm_max_ps(m_quad, m_data[m_b].m_quad);
    *((__m128 *)v8 - 2) = v13;
    *((__m128 *)v8 - 1) = v14;
    --v9;
  }
  while ( v9 );
  v15 = 1;
  p_m_vertices = &this->m_b.m_geometry->m_vertices;
  v17 = this->m_b.m_faceEdges.m_faceStartEdges.m_size - 1;
  v31 = p_m_vertices;
  v18 = 1i64;
  if ( v17 <= 1 )
  {
LABEL_13:
    result->m_enum = HK_SUCCESS;
  }
  else
  {
LABEL_4:
    v19 = this->m_b.m_faceEdges.m_faceStartEdges.m_data;
    v20 = p_m_vertices->m_data;
    v21 = v19[v18];
    v22 = v19[v18 + 1];
    v23 = *v21;
    v24 = (int **)(v21 + 1);
    v25 = p_m_vertices->m_data[v23->m_a].m_quad;
    for ( i = v25; v24 < (int **)v22; i = _mm_max_ps(i, v20[*v27].m_quad) )
    {
      v27 = *v24++;
      v25 = _mm_min_ps(v25, v20[*v27].m_quad);
    }
    v28 = 0;
    v29 = (__m128 *)v32;
    while ( 1 )
    {
      if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v25, v29[1]), _mm_cmple_ps(*v29, i))) & 7) == 7 )
      {
        pair.m_keyA = v28;
        pair.m_keyB = v15;
        hkaiBooleanOperation::_classifyEdgeAFaceB(this, &resulta, &pair, filter);
        if ( resulta.m_enum )
          break;
      }
      ++v28;
      v29 += 2;
      if ( v28 >= 3 )
      {
        ++v18;
        ++v15;
        if ( v18 >= v17 )
          goto LABEL_13;
        p_m_vertices = v31;
        goto LABEL_4;
      }
    }
    result->m_enum = HK_FAILURE;
  }
  return result;
}

// File Line: 678
// RVA: 0xBA26E0
hkResult *__fastcall hkaiBooleanOperation::_sweepAndPruneClassifyEdgeAFaceB(
        hkaiBooleanOperation *this,
        hkResult *result,
        hkaiBooleanFilter *filter,
        hkArray<hk1AxisSweep::AabbInt,hkContainerTempAllocator> *edgeAabbsA,
        hkArray<hk1AxisSweep::AabbInt,hkContainerTempAllocator> *faceAabbsB)
{
  hk1AxisSweep::AabbInt *m_data; // r11
  hk1AxisSweep::AabbInt *v6; // rdi
  unsigned int v10; // eax
  bool v11; // cf
  bool v12; // zf
  hk1AxisSweep::AabbInt *m_potentialPtr; // rax
  hk1AxisSweep::AabbInt *m_pb; // rcx
  hk1AxisSweep::IteratorAB v16; // [rsp+20h] [rbp-38h] BYREF
  hkKeyPair pair; // [rsp+78h] [rbp+20h] BYREF

  m_data = edgeAabbsA->m_data;
  v6 = faceAabbsB->m_data;
  v16.m_numA = edgeAabbsA->m_size - 4;
  v16.m_numB = faceAabbsB->m_size - 4;
  v10 = v6->m_min[0];
  v16.m_pa = m_data;
  v11 = m_data->m_min[0] < v10;
  v12 = m_data->m_min[0] == v10;
  v16.m_pb = v6;
  v16.m_aIsBigger = !v11 && !v12;
  if ( v11 || v12 )
  {
    v16.m_currentPtr = m_data;
    m_data = v6;
  }
  else
  {
    v16.m_currentPtr = v6;
  }
  v16.m_potentialPtr = m_data - 1;
  while ( 1 )
  {
    hk1AxisSweep::IteratorAB::next(&v16);
    if ( v16.m_numA <= 0 || v16.m_numB <= 0 )
      break;
    if ( v16.m_aIsBigger )
    {
      m_potentialPtr = v16.m_potentialPtr;
      m_pb = v16.m_pb;
    }
    else
    {
      m_potentialPtr = v16.m_pa;
      m_pb = v16.m_potentialPtr;
    }
    pair.m_keyA = *(_DWORD *)m_potentialPtr->m_expansionMin;
    pair.m_keyB = *(_DWORD *)m_pb->m_expansionMin;
    hkaiBooleanOperation::_classifyEdgeAFaceB(this, (hkResult *)&faceAabbsB, &pair, filter);
    if ( (_DWORD)faceAabbsB )
    {
      result->m_enum = HK_FAILURE;
      return result;
    }
  }
  result->m_enum = HK_SUCCESS;
  return result;
}

// File Line: 704
// RVA: 0xBA27F0
hkResult *__fastcall hkaiBooleanOperation::_sweepAndPruneClassifyFaceAEdgeB(
        hkaiBooleanOperation *this,
        hkResult *result,
        hkaiBooleanFilter *filter,
        hkArray<hk1AxisSweep::AabbInt,hkContainerTempAllocator> *faceAabbsA,
        hkArray<hk1AxisSweep::AabbInt,hkContainerTempAllocator> *edgeAabbsB)
{
  hk1AxisSweep::AabbInt *m_data; // r11
  hk1AxisSweep::AabbInt *v6; // rdi
  unsigned int v10; // eax
  bool v11; // cf
  bool v12; // zf
  hk1AxisSweep::AabbInt *m_potentialPtr; // rax
  hk1AxisSweep::AabbInt *m_pb; // rcx
  hk1AxisSweep::IteratorAB v16; // [rsp+20h] [rbp-38h] BYREF
  hkKeyPair pair; // [rsp+78h] [rbp+20h] BYREF

  m_data = faceAabbsA->m_data;
  v6 = edgeAabbsB->m_data;
  v16.m_numA = faceAabbsA->m_size - 4;
  v16.m_numB = edgeAabbsB->m_size - 4;
  v10 = v6->m_min[0];
  v16.m_pa = m_data;
  v11 = m_data->m_min[0] < v10;
  v12 = m_data->m_min[0] == v10;
  v16.m_pb = v6;
  v16.m_aIsBigger = !v11 && !v12;
  if ( v11 || v12 )
  {
    v16.m_currentPtr = m_data;
    m_data = v6;
  }
  else
  {
    v16.m_currentPtr = v6;
  }
  v16.m_potentialPtr = m_data - 1;
  while ( 1 )
  {
    hk1AxisSweep::IteratorAB::next(&v16);
    if ( v16.m_numA <= 0 || v16.m_numB <= 0 )
      break;
    if ( v16.m_aIsBigger )
    {
      m_potentialPtr = v16.m_potentialPtr;
      m_pb = v16.m_pb;
    }
    else
    {
      m_potentialPtr = v16.m_pa;
      m_pb = v16.m_potentialPtr;
    }
    pair.m_keyA = *(_DWORD *)m_potentialPtr->m_expansionMin;
    pair.m_keyB = *(_DWORD *)m_pb->m_expansionMin;
    hkaiBooleanOperation::_classifyFaceAEdgeB(this, (hkResult *)&edgeAabbsB, &pair, filter);
    if ( (_DWORD)edgeAabbsB )
    {
      result->m_enum = HK_FAILURE;
      return result;
    }
  }
  result->m_enum = HK_SUCCESS;
  return result;
}

// File Line: 728
// RVA: 0xBA2390
hkResult *__fastcall hkaiBooleanOperation::_classifyEdgeAFaceB(
        hkaiBooleanOperation *this,
        hkResult *result,
        hkKeyPair *pair,
        hkaiBooleanFilter *filter)
{
  hkaiEdgeGeometry::Edge *const **m_data; // rax
  __int64 m_keyA; // r10
  unsigned int m_keyB; // r13d
  hkaiEdgeGeometry::Edge **v7; // r14
  hkaiEdgeGeometry::Edge *const *v9; // rbp
  hkaiEdgeGeometry::Edge *v10; // r15
  hkaiEdgeGeometry::Edge **v13; // rbx
  int v14; // r15d
  hkaiEdgeGeometry *m_geometry; // rcx
  __int64 v16; // rax
  hkaiEdgeGeometry::Edge *const **v17; // rcx
  hkaiEdgeGeometry::Edge *v18; // rbp
  unsigned int v19; // r9d
  int count; // r15d
  __int64 index; // rbx
  unsigned int *v22; // r8
  unsigned __int64 v23; // rbx
  unsigned __int64 m_faceFaceFeatureCount; // r13
  int m_size; // r9d
  hkArray<hkVector4f,hkContainerHeapAllocator> *p_m_intersectVertices; // rsi
  int v27; // r9d
  int v28; // eax
  int v29; // eax
  int v31; // [rsp+30h] [rbp-88h]
  hkResult v32; // [rsp+34h] [rbp-84h] BYREF
  int v33; // [rsp+38h] [rbp-80h]
  unsigned int v34; // [rsp+3Ch] [rbp-7Ch]
  hkResult v35[2]; // [rsp+40h] [rbp-78h] BYREF
  hkResult v36[2]; // [rsp+48h] [rbp-70h] BYREF
  hkResult resulta; // [rsp+50h] [rbp-68h] BYREF
  __int64 v38; // [rsp+58h] [rbp-60h]
  hkaiEdgeGeometry::Edge **v39; // [rsp+60h] [rbp-58h]
  hkVector4f res; // [rsp+70h] [rbp-48h] BYREF
  unsigned int a; // [rsp+C0h] [rbp+8h] BYREF
  int v42; // [rsp+D0h] [rbp+18h]

  m_data = this->m_a.m_uniqueEdges.m_startUniqueEdge.m_data;
  m_keyA = (int)pair->m_keyA;
  m_keyB = pair->m_keyB;
  v7 = (hkaiEdgeGeometry::Edge **)m_data[m_keyA];
  v9 = m_data[m_keyA + 1];
  v10 = *v7;
  v34 = m_keyB;
  v13 = v7;
  *(_QWORD *)&v36[0].m_enum = v10;
  *(_QWORD *)&v35[0].m_enum = 8 * m_keyA + 8;
  if ( v7 != v9 )
  {
    while ( !filter->vfptr->canFacesIntersect(filter, (*v13)->m_face, m_keyB) )
    {
      if ( ++v13 == v9 )
        goto LABEL_28;
    }
    v14 = hkaiBooleanOperation::_x12(this, v10, m_keyB, &res);
    v42 = v14;
    if ( v14 )
    {
      m_geometry = this->m_a.m_geometry;
      a = this->m_intersectVertices.m_size + this->m_intersectBase;
      v33 = **(_DWORD **)&v36[0].m_enum;
      v31 = 0;
      v16 = (__int64)m_geometry->m_edges.m_data;
      v17 = this->m_a.m_uniqueEdges.m_startUniqueEdge.m_data;
      v38 = v16;
      v39 = *(hkaiEdgeGeometry::Edge ***)((char *)v17 + *(_QWORD *)&v35[0].m_enum);
      if ( v7 != v39 )
      {
        do
        {
          v18 = *v7;
          if ( filter->vfptr->canFacesIntersect(filter, (*v7)->m_face, m_keyB) )
          {
            v19 = a;
            ++v31;
            count = -v14;
            index = ((__int64)v18 - v38) >> 4;
            v22 = &this->m_edgeAIntersected.m_storage.m_words.m_data[(__int64)(int)index >> 5];
            *v22 |= 1 << (index & 0x1F);
            hkaiBooleanOperation::_addStartEndVertices(this, &resulta, index, v19, index, count);
            if ( resulta.m_enum )
              goto LABEL_23;
            hkaiBooleanOperation::_addStartEndVertices(this, v35, index, a, index, v42);
            if ( v35[0].m_enum )
              goto LABEL_23;
            v32.m_enum = HK_SUCCESS;
            v23 = m_keyB | ((unsigned __int64)v18->m_face << 32);
            LODWORD(m_faceFaceFeatureCount) = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                                                &this->m_faceFaceFeatureMap.m_map,
                                                v23,
                                                0xFFFFFFFFFFFFFFFFui64);
            if ( (m_faceFaceFeatureCount & 0x80000000) != 0i64 )
            {
              m_faceFaceFeatureCount = (int)this->m_faceFaceFeatureCount;
              this->m_faceFaceFeatureCount = m_faceFaceFeatureCount + 1;
              hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::tryInsert(
                &this->m_faceFaceFeatureMap.m_map,
                &hkContainerHeapAllocator::s_alloc,
                v23,
                m_faceFaceFeatureCount,
                &v32);
            }
            if ( v32.m_enum )
              goto LABEL_23;
            if ( v33 == v18->m_a )
              count = v42;
            hkaiBooleanOperation::_addStartEndVertices(this, v36, m_faceFaceFeatureCount, a, v18->m_face, -count);
            if ( v36[0].m_enum )
              goto LABEL_23;
            m_keyB = v34;
            v14 = v42;
          }
          ++v7;
        }
        while ( v7 != v39 );
        if ( !v31 )
          goto LABEL_28;
        m_size = this->m_intersectVertices.m_size;
        p_m_intersectVertices = &this->m_intersectVertices;
        v27 = m_size + 16;
        v28 = p_m_intersectVertices->m_capacityAndFlags & 0x3FFFFFFF;
        if ( v28 >= v27 )
        {
          a = 0;
        }
        else
        {
          v29 = 2 * v28;
          if ( v27 < v29 )
            v27 = v29;
          hkArrayUtil::_reserve((hkResult *)&a, &hkContainerHeapAllocator::s_alloc, p_m_intersectVertices, v27, 16);
          if ( a )
          {
LABEL_23:
            result->m_enum = HK_FAILURE;
            return result;
          }
        }
        if ( p_m_intersectVertices->m_size == (p_m_intersectVertices->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, p_m_intersectVertices, 16);
        p_m_intersectVertices->m_data[p_m_intersectVertices->m_size++] = (hkVector4f)res.m_quad;
      }
    }
  }
LABEL_28:
  result->m_enum = HK_SUCCESS;
  return result;
}

// File Line: 831
// RVA: 0xBA2100
hkResult *__fastcall hkaiBooleanOperation::_classifyFaceAEdgeB(
        hkaiBooleanOperation *this,
        hkResult *result,
        hkKeyPair *pair,
        hkaiBooleanFilter *filter)
{
  hkaiEdgeGeometry::Edge *const **m_data; // rax
  __int64 m_keyB; // r10
  __int64 m_keyA; // r15
  hkaiEdgeGeometry::Edge **v7; // rdi
  __int64 v8; // r13
  hkaiEdgeGeometry::Edge **v10; // r14
  hkaiEdgeGeometry::Edge **v13; // rbx
  int m_intersectBase; // eax
  hkaiEdgeGeometry::Edge *const **v16; // rcx
  hkaiEdgeGeometry::Edge *v17; // rbx
  unsigned __int64 v18; // r14
  unsigned __int64 m_faceFaceFeatureCount; // r13
  int count; // eax
  int v21; // r9d
  int v22; // eax
  int v23; // eax
  int v24; // [rsp+30h] [rbp-68h]
  unsigned int a; // [rsp+34h] [rbp-64h]
  hkResult resulta; // [rsp+38h] [rbp-60h] BYREF
  hkaiEdgeGeometry::Edge *edgeB; // [rsp+40h] [rbp-58h]
  hkaiEdgeGeometry::Edge **v28; // [rsp+48h] [rbp-50h]
  hkVector4f res; // [rsp+50h] [rbp-48h] BYREF
  hkResult v30; // [rsp+A0h] [rbp+8h] BYREF
  hkResult v31; // [rsp+B0h] [rbp+18h] BYREF

  m_data = this->m_b.m_uniqueEdges.m_startUniqueEdge.m_data;
  m_keyB = (int)pair->m_keyB;
  m_keyA = pair->m_keyA;
  v7 = (hkaiEdgeGeometry::Edge **)m_data[m_keyB];
  v8 = 8 * m_keyB + 8;
  v10 = *(hkaiEdgeGeometry::Edge ***)((char *)m_data + v8);
  v13 = v7;
  edgeB = *v7;
  if ( v7 == v10 )
  {
LABEL_4:
    result->m_enum = HK_SUCCESS;
  }
  else
  {
    while ( !filter->vfptr->canFacesIntersect(filter, m_keyA, (*v13)->m_face) )
    {
      if ( ++v13 == v10 )
        goto LABEL_4;
    }
    v24 = hkaiBooleanOperation::_x21(this, m_keyA, edgeB, &res);
    if ( v24 )
    {
      m_intersectBase = this->m_intersectBase;
      v16 = this->m_b.m_uniqueEdges.m_startUniqueEdge.m_data;
      v30.m_enum = HK_SUCCESS;
      a = this->m_intersectVertices.m_size + m_intersectBase;
      v28 = *(hkaiEdgeGeometry::Edge ***)((char *)v16 + v8);
      if ( v7 != v28 )
      {
        do
        {
          v17 = *v7;
          if ( filter->vfptr->canFacesIntersect(filter, m_keyA, (*v7)->m_face) )
          {
            ++v30.m_enum;
            v31.m_enum = HK_SUCCESS;
            v18 = v17->m_face | (unsigned __int64)(m_keyA << 32);
            LODWORD(m_faceFaceFeatureCount) = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                                                &this->m_faceFaceFeatureMap.m_map,
                                                v18,
                                                0xFFFFFFFFFFFFFFFFui64);
            if ( (m_faceFaceFeatureCount & 0x80000000) != 0i64 )
            {
              m_faceFaceFeatureCount = (int)this->m_faceFaceFeatureCount;
              this->m_faceFaceFeatureCount = m_faceFaceFeatureCount + 1;
              hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::tryInsert(
                &this->m_faceFaceFeatureMap.m_map,
                &hkContainerHeapAllocator::s_alloc,
                v18,
                m_faceFaceFeatureCount,
                &v31);
            }
            if ( v31.m_enum )
              goto LABEL_21;
            count = v24;
            if ( edgeB->m_a != v17->m_a )
              count = -v24;
            hkaiBooleanOperation::_addStartEndVertices(this, &resulta, m_faceFaceFeatureCount, a, m_keyA, count);
            if ( resulta.m_enum )
              goto LABEL_21;
          }
          ++v7;
        }
        while ( v7 != v28 );
        if ( v30.m_enum == HK_SUCCESS )
          goto LABEL_26;
        v21 = this->m_intersectVertices.m_size + 16;
        v22 = this->m_intersectVertices.m_capacityAndFlags & 0x3FFFFFFF;
        if ( v22 >= v21 )
        {
          v30.m_enum = HK_SUCCESS;
        }
        else
        {
          v23 = 2 * v22;
          if ( v21 < v23 )
            v21 = v23;
          hkArrayUtil::_reserve(&v30, &hkContainerHeapAllocator::s_alloc, &this->m_intersectVertices, v21, 16);
          if ( v30.m_enum )
          {
LABEL_21:
            result->m_enum = HK_FAILURE;
            return result;
          }
        }
        if ( this->m_intersectVertices.m_size == (this->m_intersectVertices.m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &this->m_intersectVertices, 16);
        this->m_intersectVertices.m_data[this->m_intersectVertices.m_size++] = (hkVector4f)res.m_quad;
      }
    }
LABEL_26:
    result->m_enum = HK_SUCCESS;
  }
  return result;
}

// File Line: 915
// RVA: 0xBA0BE0
hkResult *__fastcall hkaiBooleanOperation::_addCompleteEdges(
        hkaiBooleanOperation *this,
        hkResult *result,
        hkaiBooleanFilter *filter,
        hkaiEdgeGeometry *geomOut)
{
  hkaiEdgeGeometry *m_geometry; // rax
  unsigned int *m_data; // r8
  hkaiBooleanOperation *v6; // rsi
  int m_size; // r12d
  hkResult *v8; // r13
  char v9; // cl
  int v10; // r14d
  int v12; // edx
  __int64 v13; // rcx
  __m128i si128; // xmm2
  __m128i v15; // xmm3
  __m128i v16; // xmm4
  int v17; // eax
  __m128i v18; // xmm1
  __m128i v19; // xmm0
  __m128i v20; // xmm0
  __m128i v21; // xmm1
  int v22; // edi
  int v23; // eax
  int v24; // r9d
  int v25; // eax
  hkArray<hkaiBooleanOperation::SortVertex,hkContainerHeapAllocator> *p_m_startVertices; // r15
  int v27; // r9d
  int v28; // eax
  int v29; // eax
  hkArray<hkaiBooleanOperation::SortVertex,hkContainerHeapAllocator> *p_m_endVertices; // rbp
  int v31; // r9d
  int v32; // eax
  int v33; // eax
  hkResultEnum m_enum; // eax
  __int64 v35; // r14
  int v36; // r9d
  int v37; // eax
  int v38; // eax
  hkaiEdgeGeometry::Edge *v39; // r14
  unsigned int *p_m_a; // rdi
  int v41; // ebx
  int v42; // r13d
  __int64 v43; // r12
  hkaiBooleanOperation::SortVertex *v44; // rsi
  hkaiBooleanOperation::SortVertex *v45; // rcx
  hkResult resulta; // [rsp+30h] [rbp-58h] BYREF
  hkResult v48; // [rsp+34h] [rbp-54h] BYREF
  int v49; // [rsp+38h] [rbp-50h]
  hkResult v50; // [rsp+3Ch] [rbp-4Ch] BYREF
  hkArray<hkaiEdgeGeometry::Edge,hkContainerHeapAllocator> *p_m_edges; // [rsp+40h] [rbp-48h]
  hkResult v54; // [rsp+A8h] [rbp+20h] BYREF

  m_geometry = this->m_a.m_geometry;
  m_data = this->m_edgeAIntersected.m_storage.m_words.m_data;
  v6 = this;
  m_size = m_geometry->m_edges.m_size;
  v8 = result;
  v9 = (this->m_edgeAIntersected.m_storage.m_numBits - 1) & 0x1F;
  p_m_edges = &m_geometry->m_edges;
  LODWORD(m_geometry) = v6->m_edgeAIntersected.m_storage.m_words.m_size;
  v10 = 0;
  v49 = m_size;
  v12 = (2 * ~(-1 << v9)) | 1;
  LODWORD(m_geometry) = (_DWORD)m_geometry - 1;
  v13 = (int)m_geometry;
  if ( (int)m_geometry >= 0 )
  {
    si128 = _mm_load_si128((const __m128i *)&_xmm);
    v15 = _mm_load_si128((const __m128i *)&_xmm);
    v16 = _mm_load_si128((const __m128i *)&_xmm);
    do
    {
      v17 = v12 & m_data[v13];
      v12 = -1;
      v18 = _mm_cvtsi32_si128(v17);
      v19 = _mm_add_epi8(_mm_and_si128(_mm_srli_epi16(v18, 1u), si128), _mm_and_si128(v18, si128));
      v20 = _mm_add_epi8(_mm_and_si128(_mm_srli_epi16(v19, 2u), v15), _mm_and_si128(v19, v15));
      v21 = _mm_sad_epu8(_mm_and_si128(_mm_add_epi8(_mm_srli_epi16(v20, 4u), v20), v16), (__m128i)0i64);
      v10 += _mm_cvtsi128_si32(_mm_add_epi32(_mm_shuffle_epi32(v21, 78), v21));
      --v13;
    }
    while ( v13 >= 0 );
  }
  v22 = m_size - v10;
  v23 = geomOut->m_edges.m_capacityAndFlags & 0x3FFFFFFF;
  v24 = m_size - v10 + geomOut->m_edges.m_size;
  if ( v23 >= v24 )
  {
    resulta.m_enum = HK_SUCCESS;
  }
  else
  {
    v25 = 2 * v23;
    if ( v24 < v25 )
      v24 = v25;
    hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, &geomOut->m_edges, v24, 16);
  }
  p_m_startVertices = &v6->m_startVertices;
  v27 = v10 + v6->m_startVertices.m_size;
  v28 = v6->m_startVertices.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v28 >= v27 )
  {
    v48.m_enum = HK_SUCCESS;
  }
  else
  {
    v29 = 2 * v28;
    if ( v27 < v29 )
      v27 = v29;
    hkArrayUtil::_reserve(&v48, &hkContainerHeapAllocator::s_alloc, &v6->m_startVertices, v27, 16);
  }
  p_m_endVertices = &v6->m_endVertices;
  v31 = v10 + v6->m_endVertices.m_size;
  v32 = v6->m_endVertices.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v32 >= v31 )
  {
    m_enum = HK_SUCCESS;
    v54.m_enum = HK_SUCCESS;
  }
  else
  {
    v33 = 2 * v32;
    if ( v31 < v33 )
      v31 = v33;
    hkArrayUtil::_reserve(&v54, &hkContainerHeapAllocator::s_alloc, &v6->m_endVertices, v31, 16);
    m_enum = v54.m_enum;
  }
  if ( resulta.m_enum || v48.m_enum || m_enum )
  {
    v8->m_enum = HK_FAILURE;
  }
  else
  {
    v35 = geomOut->m_edges.m_size;
    v36 = v35 + v22;
    v37 = geomOut->m_edges.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v37 < (int)v35 + v22 )
    {
      v38 = 2 * v37;
      if ( v36 < v38 )
        v36 = v38;
      hkArrayUtil::_reserve(&v50, &hkContainerHeapAllocator::s_alloc, &geomOut->m_edges, v36, 16);
    }
    geomOut->m_edges.m_size += v22;
    v39 = &geomOut->m_edges.m_data[v35];
    p_m_a = &p_m_edges->m_data->m_a;
    v41 = 0;
    if ( m_size > 0 )
    {
      v42 = v49;
      v43 = 0i64;
      do
      {
        if ( ((v6->m_edgeAIntersected.m_storage.m_words.m_data[v43 >> 5] >> (v41 & 0x1F)) & 1) != 0 )
        {
          if ( p_m_endVertices->m_size == (p_m_endVertices->m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, p_m_endVertices, 16);
          v44 = &p_m_endVertices->m_data[p_m_endVertices->m_size++];
          if ( p_m_startVertices->m_size == (p_m_startVertices->m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, p_m_startVertices, 16);
          v45 = &p_m_startVertices->m_data[p_m_startVertices->m_size++];
          v45->m_feature = v41;
          v45->m_index = v41;
          v45->m_vertexIndex = *p_m_a;
          v44->m_feature = v41;
          v44->m_index = v41;
          v44->m_vertexIndex = p_m_a[1];
          v6 = this;
        }
        else
        {
          ++v39;
          v39[-1].m_a = *p_m_a;
          v39[-1].m_b = p_m_a[1];
          v39[-1].m_face = p_m_a[2];
          v39[-1].m_data = p_m_a[3];
        }
        ++v41;
        ++v43;
        p_m_a += 4;
      }
      while ( v41 < v42 );
      v8 = result;
    }
    v8->m_enum = HK_SUCCESS;
  }
  return v8;
}

// File Line: 972
// RVA: 0xBA3D90
bool __fastcall hkaiBooleanOperation_orderFeatures(
        hkaiBooleanOperation::SortVertex *a,
        hkaiBooleanOperation::SortVertex *b)
{
  if ( a->m_feature == b->m_feature )
    return a->m_index < b->m_index;
  else
    return a->m_feature < b->m_feature;
}

// File Line: 981
// RVA: 0xBA3DC0
bool __fastcall hkaiBooleanOperation_compareDist(
        hkaiBooleanOperation::SortVertex *a,
        hkaiBooleanOperation::SortVertex *b)
{
  return a->m_dist < b->m_dist;
}

// File Line: 1011
// RVA: 0xBA0F60
hkResult *__fastcall hkaiBooleanOperation::_addPartialEdges(
        hkaiBooleanOperation *this,
        hkResult *result,
        hkArray<hkVector4f,hkContainerHeapAllocator> *faceNormals,
        hkaiEdgeGeometry *geomOut,
        hkaiBooleanFaceFaceIntersects *intersects)
{
  int m_size; // r8d
  hkaiEdgeGeometry *v6; // r14
  hkResult *v7; // r12
  hkaiBooleanOperation *v8; // r13
  int v9; // r8d
  int v10; // ebx
  __int64 m_hashMod; // r8
  int v12; // edx
  __int64 v13; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *m_elem; // rax
  int v15; // r9d
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v16; // rax
  unsigned __int64 key; // r8
  char *v18; // rdx
  __int64 v19; // r8
  int v20; // edx
  __int64 v21; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v22; // rax
  hkArray<hkaiBooleanOperation::SortVertex,hkContainerHeapAllocator> *p_m_startVertices; // rbx
  int v24; // r9d
  int v25; // eax
  int v26; // eax
  int v27; // r8d
  int v29; // eax
  hkArray<hkaiEdgeGeometry::Edge,hkContainerHeapAllocator> *p_m_faceFaceEdges; // r9
  hkaiBooleanOperation::SortVertex *v31; // rcx
  hkaiBooleanOperation::SortVertex *m_data; // rbx
  hkaiBooleanOperation::SortVertex *v33; // rsi
  __int64 v34; // rcx
  unsigned int m_feature; // edi
  hkaiBooleanOperation::SortVertex *v36; // rax
  int v37; // r15d
  __int64 v38; // r14
  int *v39; // r13
  int v40; // r9d
  int v41; // r9d
  int v42; // eax
  int v43; // eax
  __int64 v44; // r12
  int v45; // r9d
  int v46; // eax
  int v47; // eax
  unsigned int *v48; // r12
  int v49; // r13d
  unsigned int v50; // eax
  int v51; // r8d
  unsigned int v52; // eax
  hkaiEdgeGeometry *v53; // rdi
  unsigned int *v54; // r10
  hkVector4f *v55; // rdx
  __m128 v56; // xmm0
  __m128 v57; // xmm3
  unsigned int *v58; // rcx
  __int64 v59; // r8
  __int64 v60; // rax
  __m128 v61; // xmm3
  int v62; // r9d
  __int64 v63; // r11
  __int64 v64; // rcx
  __int64 v65; // rdx
  __m128 v66; // xmm2
  __m128 v67; // xmm2
  int v68; // r8d
  int *v69; // rcx
  __int64 v70; // rdx
  int v71; // eax
  unsigned int v72; // eax
  __int64 v73; // rdi
  hkVector4f *v74; // rdx
  unsigned int *p_m_vertexIndex; // r10
  _DWORD *v76; // r12
  __m128 m_quad; // xmm0
  __m128 v78; // xmm3
  unsigned int *v79; // rcx
  __int64 v80; // r8
  __int64 v81; // rax
  __m128 v82; // xmm3
  int v83; // r9d
  __int64 v84; // r11
  __int64 v85; // rcx
  __int64 v86; // rdx
  __m128 v87; // xmm2
  __m128 v88; // xmm2
  __int64 v89; // rax
  hkaiBooleanOperation::SortVertex *v90; // r10
  unsigned int v91; // ecx
  int m_index; // edx
  unsigned int m_vertexIndex; // r8d
  float m_dist; // r9d
  int v95; // r8d
  __int64 v96; // r14
  __int64 v97; // rcx
  hkaiBooleanOperation::SortVertex *v98; // r10
  unsigned int v99; // ecx
  int v100; // edx
  unsigned int v101; // r8d
  float v102; // r9d
  _DWORD *v103; // r14
  int v104; // r9d
  int v105; // eax
  int v106; // eax
  __int64 v107; // rdi
  int v108; // r9d
  int v109; // eax
  int v110; // eax
  unsigned int *v111; // rcx
  __int64 v112; // rdx
  unsigned int v113; // eax
  hkResult *v114; // rbx
  int v115; // r8d
  hkResult v116; // [rsp+30h] [rbp-31h] BYREF
  int v117; // [rsp+34h] [rbp-2Dh]
  hkResult v118; // [rsp+38h] [rbp-29h] BYREF
  hkResult v119; // [rsp+3Ch] [rbp-25h] BYREF
  hkResult resulta; // [rsp+40h] [rbp-21h] BYREF
  __int64 v121; // [rsp+48h] [rbp-19h]
  void *v122; // [rsp+50h] [rbp-11h]
  char *array; // [rsp+58h] [rbp-9h] BYREF
  int v124; // [rsp+60h] [rbp-1h]
  int v125; // [rsp+64h] [rbp+3h]
  hkaiBooleanOperation *v126; // [rsp+C0h] [rbp+5Fh] BYREF
  hkResult *v127; // [rsp+C8h] [rbp+67h]
  hkArray<hkVector4f,hkContainerHeapAllocator> *faceNormalsa; // [rsp+D0h] [rbp+6Fh]
  hkaiEdgeGeometry *v129; // [rsp+D8h] [rbp+77h]

  v129 = geomOut;
  faceNormalsa = faceNormals;
  v127 = result;
  v126 = this;
  m_size = this->m_startVertices.m_size;
  v6 = geomOut;
  v7 = result;
  v8 = this;
  if ( m_size > 1 )
    hkAlgorithm::quickSortRecursive<hkaiBooleanOperation::SortVertex,bool (*)(hkaiBooleanOperation::SortVertex const &,hkaiBooleanOperation::SortVertex const &)>(
      this->m_startVertices.m_data,
      0,
      m_size - 1,
      hkaiBooleanOperation_orderFeatures);
  v9 = v8->m_endVertices.m_size;
  if ( v9 > 1 )
    hkAlgorithm::quickSortRecursive<hkaiBooleanOperation::SortVertex,bool (*)(hkaiBooleanOperation::SortVertex const &,hkaiBooleanOperation::SortVertex const &)>(
      v8->m_endVertices.m_data,
      0,
      v9 - 1,
      hkaiBooleanOperation_orderFeatures);
  v125 = 0x80000000;
  array = 0i64;
  v124 = 0;
  if ( intersects )
  {
    v10 = v8->m_faceFaceFeatureMap.m_map.m_numElems & 0x7FFFFFFF;
    if ( v10 )
      hkArrayUtil::_reserve(
        &resulta,
        &hkContainerHeapAllocator::s_alloc,
        &array,
        v8->m_faceFaceFeatureMap.m_map.m_numElems & 0x7FFFFFFF,
        8);
    m_hashMod = v8->m_faceFaceFeatureMap.m_map.m_hashMod;
    v124 = v10;
    v12 = 0;
    v13 = 0i64;
    if ( m_hashMod >= 0 )
    {
      m_elem = v8->m_faceFaceFeatureMap.m_map.m_elem;
      do
      {
        if ( m_elem->key != -1i64 )
          break;
        ++v13;
        ++v12;
        ++m_elem;
      }
      while ( v13 <= m_hashMod );
    }
    v15 = v12;
    if ( v12 <= v8->m_faceFaceFeatureMap.m_map.m_hashMod )
    {
      do
      {
        v16 = v8->m_faceFaceFeatureMap.m_map.m_elem;
        key = v16[v15].key;
        v18 = &array[8 * (LODWORD(v16[v15].val) - v8->m_faceFaceFeatureBase)];
        *((_DWORD *)v18 + 1) = key;
        *(_DWORD *)v18 = HIDWORD(key);
        v19 = v8->m_faceFaceFeatureMap.m_map.m_hashMod;
        v20 = v15 + 1;
        v21 = v15 + 1;
        if ( v21 <= v19 )
        {
          v22 = &v8->m_faceFaceFeatureMap.m_map.m_elem[v20];
          do
          {
            if ( v22->key != -1i64 )
              break;
            ++v21;
            ++v20;
            ++v22;
          }
          while ( v21 <= v19 );
        }
        v15 = v20;
      }
      while ( v20 <= v8->m_faceFaceFeatureMap.m_map.m_hashMod );
    }
  }
  p_m_startVertices = &v8->m_startVertices;
  v24 = v8->m_startVertices.m_size + 1;
  v25 = v8->m_startVertices.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v25 >= v24 )
  {
    v116.m_enum = HK_SUCCESS;
  }
  else
  {
    v26 = 2 * v25;
    if ( v24 < v26 )
      v24 = v26;
    hkArrayUtil::_reserve(&v116, &hkContainerHeapAllocator::s_alloc, &v8->m_startVertices, v24, 16);
    if ( v116.m_enum )
    {
      v27 = v125;
      v7->m_enum = HK_FAILURE;
      v124 = 0;
      if ( v27 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 8 * v27);
      return v7;
    }
  }
  if ( v8->m_startVertices.m_size == (v8->m_startVertices.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &v8->m_startVertices, 16);
  v29 = v8->m_startVertices.m_size;
  p_m_faceFaceEdges = &v8->m_faceFaceEdges;
  v122 = &v8->m_faceFaceEdges;
  v31 = &p_m_startVertices->m_data[v29];
  v8->m_startVertices.m_size = v29 + 1;
  v31->m_feature = -1;
  --v8->m_startVertices.m_size;
  m_data = p_m_startVertices->m_data;
  v33 = v8->m_endVertices.m_data;
  v34 = (__int64)v8->m_a.m_geometry->m_edges.m_data;
  v8->m_faceFaceEdges.m_size = 0;
  m_feature = m_data->m_feature;
  v121 = v34;
  if ( m_feature != -1 )
  {
    while ( 1 )
    {
      v36 = m_data;
      v37 = 0;
      v38 = 0i64;
      do
      {
        ++v36;
        ++v37;
        ++v38;
      }
      while ( v36->m_feature == m_feature );
      if ( m_feature < v8->m_faceFaceFeatureBase )
      {
        if ( m_feature >= v8->m_edgeBFeatureBase )
          goto LABEL_60;
        v73 = (__int64)v129;
        v74 = v129->m_vertices.m_data;
        p_m_vertexIndex = &v33->m_vertexIndex;
        v76 = (_DWORD *)(v34 + 16i64 * m_data->m_index);
        m_quad = v74[m_data->m_vertexIndex].m_quad;
        v78 = v74[v33->m_vertexIndex].m_quad;
        if ( v38 > 1 )
        {
          v79 = &v33[1].m_vertexIndex;
          v80 = v38 - 1;
          do
          {
            v81 = *(int *)((char *)v79 + (char *)m_data - (char *)v33);
            v79 += 4;
            m_quad = _mm_add_ps(m_quad, v74[v81].m_quad);
            v78 = _mm_add_ps(v78, v74[*(v79 - 4)].m_quad);
            --v80;
          }
          while ( v80 );
        }
        v82 = _mm_sub_ps(v78, m_quad);
        v83 = 0;
        if ( v38 > 0 )
        {
          v84 = v38;
          do
          {
            v85 = 2i64 * *(int *)((char *)p_m_vertexIndex + (char *)m_data - (char *)v33);
            v86 = v83++;
            p_m_vertexIndex += 4;
            v87 = _mm_mul_ps(*(__m128 *)(*(_QWORD *)(v73 + 48) + 8 * v85), v82);
            m_data[v86].m_dist = (float)(_mm_shuffle_ps(v87, v87, 85).m128_f32[0]
                                       + _mm_shuffle_ps(v87, v87, 0).m128_f32[0])
                               + _mm_shuffle_ps(v87, v87, 170).m128_f32[0];
            v88 = _mm_mul_ps(*(__m128 *)(*(_QWORD *)(v73 + 48) + 16i64 * (int)*(p_m_vertexIndex - 4)), v82);
            v33[v86].m_dist = (float)(_mm_shuffle_ps(v88, v88, 85).m128_f32[0] + _mm_shuffle_ps(v88, v88, 0).m128_f32[0])
                            + _mm_shuffle_ps(v88, v88, 170).m128_f32[0];
            --v84;
          }
          while ( v84 );
        }
        if ( v38 > 1 )
        {
          hkAlgorithm::quickSortRecursive<hkaiBooleanOperation::SortVertex,bool (*)(hkaiBooleanOperation::SortVertex const &,hkaiBooleanOperation::SortVertex const &)>(
            m_data,
            0,
            v37 - 1,
            hkaiBooleanOperation_compareDist);
          hkAlgorithm::quickSortRecursive<hkaiBooleanOperation::SortVertex,bool (*)(hkaiBooleanOperation::SortVertex const &,hkaiBooleanOperation::SortVertex const &)>(
            v33,
            0,
            v37 - 1,
            hkaiBooleanOperation_compareDist);
          v73 = (__int64)v129;
        }
        if ( m_data->m_vertexIndex != *v76 )
        {
          v89 = 1i64;
          if ( v38 > 1 )
          {
            v90 = m_data + 1;
            while ( v90->m_vertexIndex != *v76 )
            {
              ++v89;
              ++v90;
              if ( v89 >= v38 )
                goto LABEL_80;
            }
            v91 = v90->m_feature;
            m_index = v90->m_index;
            m_vertexIndex = v90->m_vertexIndex;
            m_dist = v90->m_dist;
            v90->m_feature = m_data->m_feature;
            v90->m_index = m_data->m_index;
            v90->m_vertexIndex = m_data->m_vertexIndex;
            v90->m_dist = m_data->m_dist;
            m_data->m_feature = v91;
            m_data->m_index = m_index;
            m_data->m_vertexIndex = m_vertexIndex;
            m_data->m_dist = m_dist;
          }
        }
LABEL_80:
        v95 = v76[1];
        v96 = v38;
        if ( v33[v96 - 1].m_vertexIndex != v95 )
        {
          v97 = 0i64;
          if ( v37 - 1 > 0 )
          {
            v98 = v33;
            while ( v98->m_vertexIndex != v95 )
            {
              ++v97;
              ++v98;
              if ( v97 >= v37 - 1 )
                goto LABEL_87;
            }
            v99 = v98->m_feature;
            v100 = v98->m_index;
            v101 = v98->m_vertexIndex;
            v102 = v98->m_dist;
            v98->m_feature = v33[v96 - 1].m_feature;
            v98->m_index = v33[v96 - 1].m_index;
            v98->m_vertexIndex = v33[v96 - 1].m_vertexIndex;
            v98->m_dist = v33[v96 - 1].m_dist;
            v33[v96 - 1].m_feature = v99;
            v33[v96 - 1].m_index = v100;
            v33[v96 - 1].m_vertexIndex = v101;
            v33[v96 - 1].m_dist = v102;
          }
        }
LABEL_87:
        v103 = (_DWORD *)(v73 + 16);
        v104 = v37 + *(_DWORD *)(v73 + 24);
        v105 = *(_DWORD *)(v73 + 28) & 0x3FFFFFFF;
        if ( v105 >= v104 )
        {
          v118.m_enum = HK_SUCCESS;
        }
        else
        {
          v106 = 2 * v105;
          if ( v104 < v106 )
            v104 = v106;
          hkArrayUtil::_reserve(&v118, &hkContainerHeapAllocator::s_alloc, (void *)(v73 + 16), v104, 16);
          if ( v118.m_enum )
          {
            v114 = v127;
            v115 = v125;
            v127->m_enum = HK_FAILURE;
            v124 = 0;
            if ( v115 >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 8 * v115);
            return v114;
          }
        }
        v107 = *(int *)(v73 + 24);
        v108 = v107 + v37;
        v109 = v103[3] & 0x3FFFFFFF;
        if ( v109 >= (int)v107 + v37 )
        {
          resulta.m_enum = HK_SUCCESS;
        }
        else
        {
          v110 = 2 * v109;
          if ( v108 < v110 )
            v108 = v110;
          hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, v103, v108, 16);
        }
        v103[2] += v37;
        v111 = (unsigned int *)(*(_QWORD *)v103 + 16 * v107);
        if ( v37 > 0 )
        {
          v112 = (unsigned int)v37;
          do
          {
            v113 = m_data->m_vertexIndex;
            ++m_data;
            ++v33;
            *v111 = v113;
            v111 += 4;
            *(v111 - 3) = v33[-1].m_vertexIndex;
            *(v111 - 2) = v76[2];
            *(v111 - 1) = v76[3];
            --v112;
          }
          while ( v112 );
        }
      }
      else
      {
        v39 = (int *)v122;
        v40 = *((_DWORD *)v122 + 2);
        v117 = m_data->m_index;
        v41 = v37 + v40;
        v42 = *((_DWORD *)v122 + 3) & 0x3FFFFFFF;
        if ( v42 >= v41 )
        {
          v116.m_enum = HK_SUCCESS;
        }
        else
        {
          v43 = 2 * v42;
          if ( v41 < v43 )
            v41 = v43;
          hkArrayUtil::_reserve(&v116, &hkContainerHeapAllocator::s_alloc, v122, v41, 16);
          if ( v116.m_enum )
          {
            v7 = v127;
            v127->m_enum = HK_FAILURE;
            goto LABEL_107;
          }
        }
        v44 = v39[2];
        v45 = v44 + v37;
        v46 = v39[3] & 0x3FFFFFFF;
        if ( v46 >= (int)v44 + v37 )
        {
          v119.m_enum = HK_SUCCESS;
        }
        else
        {
          v47 = 2 * v46;
          if ( v45 < v47 )
            v45 = v47;
          hkArrayUtil::_reserve(&v119, &hkContainerHeapAllocator::s_alloc, v39, v45, 16);
        }
        v39[2] += v37;
        v48 = (unsigned int *)(*(_QWORD *)v39 + 16 * v44);
        v49 = 0;
        if ( intersects )
          v49 = *(_DWORD *)&array[8 * (m_feature - v126->m_faceFaceFeatureBase) + 4];
        if ( v38 == 1 )
        {
          v50 = m_data->m_vertexIndex;
          v51 = v117;
          ++m_data;
          *v48 = v50;
          v52 = v33->m_vertexIndex;
          v48[2] = v51;
          v48[3] = v49;
          ++v33;
          v48[1] = v52;
        }
        else
        {
          v53 = v129;
          v54 = &v33->m_vertexIndex;
          v55 = v129->m_vertices.m_data;
          v56 = v55[m_data->m_vertexIndex].m_quad;
          v57 = v55[v33->m_vertexIndex].m_quad;
          if ( v38 > 1 )
          {
            v58 = &v33[1].m_vertexIndex;
            v59 = v38 - 1;
            do
            {
              v60 = *(int *)((char *)v58 + (char *)m_data - (char *)v33);
              v58 += 4;
              v56 = _mm_add_ps(v56, v55[v60].m_quad);
              v57 = _mm_add_ps(v57, v55[*(v58 - 4)].m_quad);
              --v59;
            }
            while ( v59 );
          }
          v61 = _mm_sub_ps(v57, v56);
          v62 = 0;
          if ( v38 > 0 )
          {
            v63 = v38;
            do
            {
              v64 = *(int *)((char *)v54 + (char *)m_data - (char *)v33);
              v65 = v62++;
              v54 += 4;
              v66 = _mm_mul_ps(v53->m_vertices.m_data[v64].m_quad, v61);
              m_data[v65].m_dist = (float)(_mm_shuffle_ps(v66, v66, 85).m128_f32[0]
                                         + _mm_shuffle_ps(v66, v66, 0).m128_f32[0])
                                 + _mm_shuffle_ps(v66, v66, 170).m128_f32[0];
              v67 = _mm_mul_ps(v53->m_vertices.m_data[*(v54 - 4)].m_quad, v61);
              v33[v65].m_dist = (float)(_mm_shuffle_ps(v67, v67, 85).m128_f32[0]
                                      + _mm_shuffle_ps(v67, v67, 0).m128_f32[0])
                              + _mm_shuffle_ps(v67, v67, 170).m128_f32[0];
              --v63;
            }
            while ( v63 );
          }
          if ( v38 > 1 )
          {
            hkAlgorithm::quickSortRecursive<hkaiBooleanOperation::SortVertex,bool (*)(hkaiBooleanOperation::SortVertex const &,hkaiBooleanOperation::SortVertex const &)>(
              m_data,
              0,
              v37 - 1,
              hkaiBooleanOperation_compareDist);
            hkAlgorithm::quickSortRecursive<hkaiBooleanOperation::SortVertex,bool (*)(hkaiBooleanOperation::SortVertex const &,hkaiBooleanOperation::SortVertex const &)>(
              v33,
              0,
              v37 - 1,
              hkaiBooleanOperation_compareDist);
          }
          if ( v37 > 0 )
          {
            v68 = v117;
            v69 = (int *)(v48 + 2);
            v70 = (unsigned int)v37;
            do
            {
              v71 = m_data->m_vertexIndex;
              ++m_data;
              ++v33;
              *(v69 - 2) = v71;
              v72 = v33[-1].m_vertexIndex;
              *v69 = v68;
              v69[1] = v49;
              *(v69 - 1) = v72;
              v69 += 4;
              --v70;
            }
            while ( v70 );
          }
        }
        v8 = v126;
      }
      v34 = v121;
LABEL_60:
      m_feature = m_data->m_feature;
      if ( m_data->m_feature == -1 )
      {
        v6 = v129;
        v7 = v127;
        p_m_faceFaceEdges = &v8->m_faceFaceEdges;
        break;
      }
    }
  }
  hkaiBooleanOperation::_addFaceFaceIntersections(
    v8,
    (hkResult *)&v126,
    faceNormalsa,
    p_m_faceFaceEdges,
    intersects,
    v6);
  if ( (_DWORD)v126 )
    v7->m_enum = HK_FAILURE;
  else
    v7->m_enum = HK_SUCCESS;
LABEL_107:
  v124 = 0;
  if ( v125 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 8 * v125);
  return v7;
}

// File Line: 1214
// RVA: 0xBA2C00
__int64 __fastcall hkaiBooleanOperation::_linesIntersect(
        hkaiBooleanOperation *this,
        hkVector4f *points,
        hkVector4f *intersectPosition)
{
  __m128 m_quad; // xmm1
  __m128 v4; // xmm3
  __m128 v5; // xmm2
  int v8; // r8d
  __int64 result; // rax

  m_quad = points->m_quad;
  v4 = points[2].m_quad;
  v5 = points[3].m_quad;
  v8 = 0;
  if ( ((_mm_movemask_ps(_mm_cmpeq_ps(points->m_quad, v5)) & 3) == 3) | ((_mm_movemask_ps(_mm_cmpeq_ps(points->m_quad, v4)) & 3) == 3)
    || (m_quad = points[1].m_quad,
        LOBYTE(v8) = (_mm_movemask_ps(_mm_cmpeq_ps(m_quad, v5)) & 3) == 3,
        v8 | ((_mm_movemask_ps(_mm_cmpeq_ps(m_quad, v4)) & 3) == 3)) )
  {
    *intersectPosition = (hkVector4f)m_quad;
    return 1i64;
  }
  else if ( (unsigned int)hkaiBooleanOperation::_calculate2dLineIntersect(points, points + 1, points + 2, points + 3)
         || (result = hkaiBooleanOperation::_calculate2dLineIntersect(points + 2, points + 3, points, points + 1),
             (_DWORD)result) )
  {
    result = 1i64;
    *intersectPosition = 0i64;
  }
  return result;
}

// File Line: 1269
// RVA: 0xBA3DE0
bool __fastcall hkaiBooleanOperation_orderEdgeEdgeIntersect(
        hkaiBooleanOperation::EdgeEdgeIntersect *a,
        hkaiBooleanOperation::EdgeEdgeIntersect *b)
{
  if ( a->m_edgeIndex == b->m_edgeIndex )
    return a->m_dist < b->m_dist;
  else
    return a->m_edgeIndex < b->m_edgeIndex;
}

// File Line: 1278
// RVA: 0xBA3E10
hkVector4f *__fastcall hkaiBooleanOperation_faceSwizzle(hkVector4f *result, hkVector4f *v, const int majorAxis)
{
  __m128 m_quad; // xmm0
  hkVector4f *v4; // rax

  m_quad = v->m_quad;
  v4 = result;
  if ( majorAxis )
  {
    if ( majorAxis == 1 )
    {
      result->m_quad = _mm_shuffle_ps(m_quad, m_quad, 216);
      return v4;
    }
  }
  else
  {
    m_quad = _mm_shuffle_ps(m_quad, m_quad, 201);
  }
  *result = (hkVector4f)m_quad;
  return v4;
}

// File Line: 1290
// RVA: 0xBA3E40
hkVector4f *__fastcall hkaiBooleanOperation_faceDeswizzle(hkVector4f *result, hkVector4f *v, const int majorAxis)
{
  __m128 m_quad; // xmm0
  hkVector4f *v4; // rax

  m_quad = v->m_quad;
  v4 = result;
  if ( majorAxis )
  {
    if ( majorAxis == 1 )
    {
      result->m_quad = _mm_shuffle_ps(m_quad, m_quad, 216);
      return v4;
    }
  }
  else
  {
    m_quad = _mm_shuffle_ps(m_quad, m_quad, 210);
  }
  *result = (hkVector4f)m_quad;
  return v4;
}

// File Line: 1302
// RVA: 0xBA2D20
hkResult *__fastcall hkaiBooleanOperation::_addFaceIntersections(
        hkaiBooleanOperation *this,
        hkResult *result,
        const __m128i *faceNormalIn,
        hkaiEdgeGeometry::Edge *edges,
        int numEdges,
        hkaiBooleanFaceFaceIntersects *intersects,
        hkaiEdgeGeometry *geomOut)
{
  unsigned int m_face; // r12d
  hkResult *v9; // r14
  hkaiEdgeGeometry::Edge *v10; // rbx
  int m_capacityAndFlags; // eax
  int v12; // eax
  int v13; // eax
  int v14; // r9d
  __int64 v16; // r13
  __m128 v17; // xmm3
  hkArray<hkaiEdgeGeometry::Edge,hkContainerHeapAllocator> *p_m_edges; // r15
  int v19; // esi
  int v20; // r8d
  int v21; // edi
  __m128 v22; // xmm6
  _QWORD *v23; // rsi
  __int64 v24; // r14
  hkVector4f v25; // xmm1
  __int64 v26; // rcx
  int v27; // eax
  int v28; // eax
  int v29; // eax
  int v30; // r9d
  int v31; // r8d
  hk1AxisSweep::AabbInt *v32; // rdi
  hkResultEnum v33; // r13d
  hkResultEnum v34; // esi
  int v35; // ebx
  __int64 v36; // rcx
  unsigned int v37; // r8d
  hk1AxisSweep::AabbInt *v38; // rdx
  hkaiEdgeGeometry::Edge *v39; // r13
  int v40; // r14d
  __int64 v41; // r9
  signed int m_a; // r10d
  __int64 v43; // rdx
  __int64 m_b; // r8
  __m128 v45; // xmm1
  __m128 v46; // xmm0
  __m128 v47; // xmm9
  __m128 v48; // xmm0
  __m128 v49; // xmm9
  __int64 v50; // rax
  __int64 v51; // r9
  __m128 v52; // xmm2
  __m128 v53; // xmm9
  unsigned int v54; // ecx
  __m128 v55; // xmm8
  __m128 v56; // xmm0
  __m128 v57; // xmm7
  __m128 v58; // xmm0
  hkVector4f v59; // xmm6
  _DWORD *v60; // r14
  int v61; // r9d
  int v62; // eax
  int v63; // eax
  int v64; // r8d
  hkResult *v65; // rbx
  _DWORD *v66; // rdx
  __m128 v67; // xmm7
  __m128 v68; // xmm2
  int v69; // r9d
  int v70; // eax
  __m128 v71; // xmm7
  int v72; // eax
  __int64 v73; // r14
  int v74; // r9d
  int v75; // eax
  int v76; // eax
  __int64 v77; // rax
  __m128 v78; // xmm2
  __m128 v79; // xmm2
  __int64 v80; // rdx
  __m128 v81; // xmm1
  __m128 v82; // xmm2
  __m128 v83; // xmm2
  __m128 v84; // xmm1
  __int64 v85; // rcx
  unsigned int v86; // r8d
  hk1AxisSweep::AabbInt *v87; // rdx
  _DWORD *v88; // rbx
  int v89; // r9d
  int v90; // eax
  int v91; // eax
  __int64 v92; // rdx
  hkaiBooleanOperation::EdgeEdgeIntersect *v93; // rcx
  int v94; // r8d
  char *v95; // rbx
  int v96; // esi
  __int32 v97; // eax
  hkaiBooleanFaceFaceIntersects *v98; // r14
  hkResultEnum m_size; // edi
  char *i; // rdi
  __int64 v101; // rsi
  int v102; // r13d
  int v103; // eax
  int v104; // r9d
  int v105; // eax
  int v106; // r9d
  int v107; // eax
  int v108; // eax
  hkaiEdgeGeometry::Edge *v109; // r13
  hkaiEdgeGeometry::Edge *v110; // rcx
  unsigned int v111; // eax
  unsigned int v112; // eax
  __int64 v113; // rdx
  unsigned int v114; // eax
  unsigned int v115; // eax
  unsigned int v116; // eax
  unsigned int v117; // eax
  unsigned int v118; // eax
  int v119; // r9d
  int v120; // eax
  int v121; // eax
  __int64 v122; // r13
  int v123; // r9d
  int v124; // eax
  int v125; // eax
  __int64 v126; // rcx
  hkaiEdgeGeometry::Edge *v127; // rcx
  unsigned int v128; // eax
  unsigned int v129; // eax
  hkaiBooleanFaceFaceIntersects::Intersect *v130; // rcx
  int v131; // eax
  int v132; // r8d
  hkResult resulta; // [rsp+30h] [rbp-D0h] BYREF
  hkArrayBase<hkRadixSort::SortData32> sortArray; // [rsp+38h] [rbp-C8h] BYREF
  hkArrayBase<hk1AxisSweep::AabbInt> sortedAabbs; // [rsp+48h] [rbp-B8h] BYREF
  hkResult v136; // [rsp+58h] [rbp-A8h] BYREF
  hk1AxisSweep::AabbInt *array; // [rsp+60h] [rbp-A0h] BYREF
  int v138; // [rsp+68h] [rbp-98h]
  int v139; // [rsp+6Ch] [rbp-94h]
  hkResult v140; // [rsp+70h] [rbp-90h] BYREF
  hkResult v141; // [rsp+74h] [rbp-8Ch] BYREF
  __int64 v142; // [rsp+78h] [rbp-88h] BYREF
  void *p_m_vertices; // [rsp+80h] [rbp-80h]
  hkResult v144; // [rsp+88h] [rbp-78h] BYREF
  void *p_m_edgeEdgeIntersects; // [rsp+90h] [rbp-70h]
  int v146; // [rsp+98h] [rbp-68h]
  hkResult v147; // [rsp+9Ch] [rbp-64h] BYREF
  __int64 v148; // [rsp+A0h] [rbp-60h]
  hkAabb aabbIn; // [rsp+B0h] [rbp-50h] BYREF
  hkVector4f points; // [rsp+D0h] [rbp-30h] BYREF
  __m128 v151; // [rsp+E0h] [rbp-20h]
  __m128 v152; // [rsp+F0h] [rbp-10h]
  __m128 v153; // [rsp+100h] [rbp+0h]
  hkaiBooleanOperation *v154; // [rsp+1A0h] [rbp+A0h] BYREF
  hkResult *v155; // [rsp+1A8h] [rbp+A8h]
  hkaiEdgeGeometry::Edge *v156; // [rsp+1B8h] [rbp+B8h]

  v156 = edges;
  v155 = result;
  v154 = this;
  m_face = edges->m_face;
  v9 = result;
  v10 = edges;
  this->m_edgeEdgeIntersects.m_size = 0;
  m_capacityAndFlags = this->m_edgeEdgeIntersects.m_capacityAndFlags;
  p_m_edgeEdgeIntersects = &this->m_edgeEdgeIntersects;
  v12 = m_capacityAndFlags & 0x3FFFFFFF;
  if ( v12 < 32 )
  {
    v13 = 2 * v12;
    v14 = 32;
    if ( v13 > 32 )
      v14 = v13;
    hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, &this->m_edgeEdgeIntersects, v14, 12);
    if ( resulta.m_enum )
    {
      v9->m_enum = HK_FAILURE;
      return v9;
    }
  }
  v16 = numEdges;
  v17 = (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128(faceNormalIn), 1u), 1u);
  p_m_edges = &geomOut->m_edges;
  v19 = numEdges + 4;
  p_m_vertices = &geomOut->m_vertices;
  array = 0i64;
  v138 = 0;
  v139 = 0x80000000;
  v146 = (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                                _mm_and_ps(
                                                                  _mm_cmple_ps(
                                                                    _mm_max_ps(
                                                                      _mm_shuffle_ps(v17, v17, 170),
                                                                      _mm_max_ps(
                                                                        _mm_shuffle_ps(v17, v17, 85),
                                                                        _mm_shuffle_ps(v17, v17, 0))),
                                                                    v17),
                                                                  (__m128)xmmword_141A4E0F0))];
  if ( numEdges + 4 <= 0 )
  {
    v144.m_enum = HK_SUCCESS;
  }
  else
  {
    hkArrayUtil::_reserve(&v144, &hkContainerTempAllocator::s_alloc, &array, numEdges + 4, 32);
    if ( v144.m_enum )
    {
      v20 = v139;
      v9->m_enum = HK_FAILURE;
      v138 = 0;
      if ( v20 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 32 * v20);
      return v9;
    }
  }
  v138 = v19;
  resulta.m_enum = LODWORD(FLOAT_0_001);
  v21 = 0;
  v22 = _mm_shuffle_ps((__m128)(unsigned int)resulta.m_enum, (__m128)(unsigned int)resulta.m_enum, 0);
  if ( (int)v16 > 0 )
  {
    v23 = p_m_vertices;
    v24 = 0i64;
    do
    {
      v25.m_quad = _mm_sub_ps(
                     _mm_min_ps(*(__m128 *)(*v23 + 16i64 * (int)v10->m_a), *(__m128 *)(*v23 + 16i64 * (int)v10->m_b)),
                     v22);
      aabbIn.m_max.m_quad = _mm_add_ps(
                              _mm_max_ps(
                                *(__m128 *)(*v23 + 16i64 * (int)v10->m_a),
                                *(__m128 *)(*v23 + 16i64 * (int)v10->m_b)),
                              v22);
      aabbIn.m_min = (hkVector4f)v25.m_quad;
      hk1AxisSweep::AabbInt::set(&array[v24++], &aabbIn, v21++);
      ++v10;
    }
    while ( v21 < (int)v16 );
    v9 = v155;
    v19 = v16 + 4;
  }
  v26 = v16;
  v148 = v16;
  array[v26].m_min[0] = -1;
  array[v26 + 1].m_min[0] = -1;
  array[v16 + 2].m_min[0] = -1;
  array[v16 + 3].m_min[0] = -1;
  v27 = 0x80000000;
  sortedAabbs.m_data = 0i64;
  sortedAabbs.m_size = 0;
  sortedAabbs.m_capacityAndFlags = 0x80000000;
  sortArray.m_data = 0i64;
  sortArray.m_capacityAndFlags = 0x80000000;
  sortArray.m_size = 0;
  if ( v19 <= 0 )
  {
    v136.m_enum = HK_SUCCESS;
  }
  else
  {
    hkArrayUtil::_reserve(&v136, &hkContainerTempAllocator::s_alloc, &sortedAabbs, v19, 32);
    if ( v136.m_enum )
    {
LABEL_24:
      v31 = sortArray.m_capacityAndFlags;
      sortArray.m_size = 0;
      v9->m_enum = HK_FAILURE;
      if ( v31 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, sortArray.m_data, 8 * v31);
      sortedAabbs.m_size = 0;
      sortArray.m_capacityAndFlags = 0x80000000;
      sortArray.m_data = 0i64;
      if ( sortedAabbs.m_capacityAndFlags >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          &hkContainerTempAllocator::s_alloc,
          sortedAabbs.m_data,
          32 * sortedAabbs.m_capacityAndFlags);
      sortedAabbs.m_data = 0i64;
      sortedAabbs.m_capacityAndFlags = 0x80000000;
      v138 = 0;
      if ( v139 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 32 * v139);
      return v9;
    }
    v27 = sortArray.m_capacityAndFlags;
  }
  v28 = v27 & 0x3FFFFFFF;
  sortedAabbs.m_size = v19;
  if ( v28 < v19 )
  {
    v29 = 2 * v28;
    v30 = v19;
    if ( v19 < v29 )
      v30 = v29;
    hkArrayUtil::_reserve(&resulta, &hkContainerTempAllocator::s_alloc, &sortArray, v30, 8);
    if ( resulta.m_enum )
      goto LABEL_24;
  }
  sortArray.m_size = v19;
  hk1AxisSweep::sortAabbs(array, v16, &sortArray, &sortedAabbs);
  v32 = array;
  v33 = v16 - 1;
  v34 = HK_SUCCESS;
  v35 = 1;
  v136.m_enum = v33;
  if ( v33 > HK_SUCCESS )
  {
    while ( 1 )
    {
      v36 = v34;
      v37 = array[v36].m_max[0];
      v38 = &array[v35];
      if ( v38->m_min[0] <= v37 )
        break;
LABEL_35:
      v35 = ++v34 + 1;
      if ( v34 >= v33 )
        goto LABEL_36;
    }
    while ( (((v38->m_max[2] - array[v36].m_min[2]) | (v38->m_max[1] - array[v36].m_min[1]) | (array[v36].m_max[2]
                                                                                             - v38->m_min[2]) | (array[v36].m_max[1] - v38->m_min[1])) & 0x80000000) != 0 )
    {
      v38 = &array[++v35];
      if ( v38->m_min[0] > v37 )
        goto LABEL_35;
    }
  }
LABEL_36:
  if ( v34 < v33 )
  {
    v39 = v156;
    do
    {
      v40 = v146;
      LODWORD(v142) = *(_DWORD *)v32[v34].m_expansionMin;
      v41 = *(int *)v32[v35].m_expansionMin;
      m_a = v39[(int)v142].m_a;
      v43 = *(_QWORD *)p_m_vertices;
      m_b = (int)v39[(int)v142].m_b;
      v141.m_enum = *(_DWORD *)v32[v35].m_expansionMin;
      v45 = *(__m128 *)(v43 + 16i64 * m_a);
      v46 = v45;
      v47 = *(__m128 *)(v43 + 16 * m_b);
      if ( v146 )
      {
        if ( v146 == 1 )
          v46 = _mm_shuffle_ps(v45, v45, 216);
      }
      else
      {
        v46 = _mm_shuffle_ps(v45, v45, 201);
      }
      points.m_quad = v46;
      v48 = v47;
      if ( v146 )
      {
        if ( v146 == 1 )
          v48 = _mm_shuffle_ps(v47, v47, 216);
      }
      else
      {
        v48 = _mm_shuffle_ps(v47, v47, 201);
      }
      v49 = _mm_sub_ps(v47, v45);
      v151 = v48;
      v50 = v41;
      v51 = (int)v39[v41].m_a;
      v52 = _mm_mul_ps(v49, v45);
      v53 = _mm_shuffle_ps(
              v49,
              _mm_unpackhi_ps(
                v49,
                _mm_sub_ps(
                  (__m128)0i64,
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v52, v52, 85), _mm_shuffle_ps(v52, v52, 0)),
                    _mm_shuffle_ps(v52, v52, 170)))),
              196);
      if ( m_a != (_DWORD)v51 )
      {
        v54 = v39[v50].m_b;
        if ( m_a != v54 && (_DWORD)m_b != (_DWORD)v51 && (_DWORD)m_b != v54 )
        {
          v55 = *(__m128 *)(v43 + 16 * v51);
          v56 = v55;
          v57 = *(__m128 *)(v43 + 16i64 * (int)v39[v50].m_b);
          if ( v146 )
          {
            if ( v146 == 1 )
              v56 = _mm_shuffle_ps(v55, v55, 216);
          }
          else
          {
            v56 = _mm_shuffle_ps(v55, v55, 201);
          }
          v152 = v56;
          v58 = v57;
          if ( v146 )
          {
            if ( v146 == 1 )
              v58 = _mm_shuffle_ps(v57, v57, 216);
          }
          else
          {
            v58 = _mm_shuffle_ps(v57, v57, 201);
          }
          v153 = v58;
          if ( (unsigned int)hkaiBooleanOperation::_linesIntersect(v154, &points, &aabbIn.m_min) )
          {
            v59.m_quad = (__m128)aabbIn.m_min;
            if ( v40 )
            {
              if ( v40 == 1 )
                v59.m_quad = _mm_shuffle_ps(aabbIn.m_min.m_quad, aabbIn.m_min.m_quad, 216);
            }
            else
            {
              v59.m_quad = _mm_shuffle_ps(aabbIn.m_min.m_quad, aabbIn.m_min.m_quad, 210);
            }
            v60 = p_m_vertices;
            HIDWORD(v142) = *((_DWORD *)p_m_vertices + 2);
            v61 = HIDWORD(v142) + 16;
            v62 = *((_DWORD *)p_m_vertices + 3) & 0x3FFFFFFF;
            if ( v62 >= HIDWORD(v142) + 16 )
            {
              v140.m_enum = HK_SUCCESS;
            }
            else
            {
              v63 = 2 * v62;
              if ( v61 < v63 )
                v61 = v63;
              hkArrayUtil::_reserve(&v140, &hkContainerHeapAllocator::s_alloc, p_m_vertices, v61, 16);
              if ( v140.m_enum )
                goto LABEL_67;
            }
            if ( v60[2] == (v60[3] & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, v60, 16);
            v66 = p_m_edgeEdgeIntersects;
            v67 = _mm_sub_ps(v57, v55);
            v68 = _mm_mul_ps(v67, v55);
            *(hkVector4f *)(*(_QWORD *)v60 + 16i64 * (int)v60[2]++) = (hkVector4f)v59.m_quad;
            v69 = v66[2] + 16;
            v70 = v66[3] & 0x3FFFFFFF;
            v71 = _mm_shuffle_ps(
                    v67,
                    _mm_unpackhi_ps(
                      v67,
                      _mm_sub_ps(
                        (__m128)0i64,
                        _mm_add_ps(
                          _mm_add_ps(_mm_shuffle_ps(v68, v68, 85), _mm_shuffle_ps(v68, v68, 0)),
                          _mm_shuffle_ps(v68, v68, 170)))),
                    196);
            if ( v70 >= v69 )
            {
              resulta.m_enum = HK_SUCCESS;
            }
            else
            {
              v72 = 2 * v70;
              if ( v69 < v72 )
                v69 = v72;
              hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, v66, v69, 12);
              if ( resulta.m_enum )
                goto LABEL_67;
              v66 = p_m_edgeEdgeIntersects;
            }
            v73 = (int)v66[2];
            v74 = v73 + 2;
            v75 = v66[3] & 0x3FFFFFFF;
            if ( v75 >= (int)v73 + 2 )
            {
              v147.m_enum = HK_SUCCESS;
            }
            else
            {
              v76 = 2 * v75;
              if ( v74 < v76 )
                v74 = v76;
              hkArrayUtil::_reserve(&v147, &hkContainerHeapAllocator::s_alloc, v66, v74, 12);
              v66 = p_m_edgeEdgeIntersects;
            }
            v77 = *(_QWORD *)v66;
            v66[2] += 2;
            v78 = _mm_mul_ps(v59.m_quad, v53);
            v79 = _mm_shuffle_ps(v78, _mm_unpackhi_ps(v78, v53), 196);
            v80 = v77 + 12 * v73;
            LODWORD(v77) = HIDWORD(v142);
            *(_QWORD *)v80 = v142;
            v81 = _mm_add_ps(_mm_shuffle_ps(v79, v79, 78), v79);
            v82 = _mm_mul_ps(v71, v59.m_quad);
            *(float *)(v80 + 8) = _mm_shuffle_ps(v81, v81, 177).m128_f32[0] + v81.m128_f32[0];
            *(_DWORD *)(v80 + 16) = v77;
            *(hkResult *)(v80 + 12) = v141;
            v83 = _mm_shuffle_ps(v82, _mm_unpackhi_ps(v82, v71), 196);
            v84 = _mm_add_ps(_mm_shuffle_ps(v83, v83, 78), v83);
            *(float *)(v80 + 20) = _mm_shuffle_ps(v84, v84, 177).m128_f32[0] + v84.m128_f32[0];
          }
        }
      }
      ++v35;
      if ( v34 >= v136.m_enum )
        break;
      while ( 1 )
      {
        v85 = v34;
        v86 = v32[v85].m_max[0];
        v87 = &v32[v35];
        if ( v87->m_min[0] <= v86 )
          break;
LABEL_91:
        v35 = ++v34 + 1;
        if ( v34 >= v136.m_enum )
          goto LABEL_92;
      }
      while ( (((v87->m_max[2] - v32[v85].m_min[2]) | (v87->m_max[1] - v32[v85].m_min[1]) | (v32[v85].m_max[2]
                                                                                           - v87->m_min[2]) | (v32[v85].m_max[1] - v87->m_min[1])) & 0x80000000) != 0 )
      {
        v87 = &v32[++v35];
        if ( v87->m_min[0] > v86 )
          goto LABEL_91;
      }
    }
    while ( v34 < v136.m_enum );
  }
LABEL_92:
  v88 = p_m_edgeEdgeIntersects;
  v89 = *((_DWORD *)p_m_edgeEdgeIntersects + 2) + 1;
  v90 = *((_DWORD *)p_m_edgeEdgeIntersects + 3) & 0x3FFFFFFF;
  if ( v90 >= v89 )
    goto LABEL_96;
  v91 = 2 * v90;
  if ( v89 < v91 )
    v89 = v91;
  hkArrayUtil::_reserve((hkResult *)&v154, &hkContainerHeapAllocator::s_alloc, p_m_edgeEdgeIntersects, v89, 12);
  if ( (_DWORD)v154 )
  {
LABEL_67:
    v64 = sortArray.m_capacityAndFlags;
    v65 = v155;
    v155->m_enum = HK_FAILURE;
    sortArray.m_size = 0;
    if ( v64 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, sortArray.m_data, 8 * v64);
    sortArray.m_data = 0i64;
    sortArray.m_capacityAndFlags = 0x80000000;
    sortedAabbs.m_size = 0;
    if ( sortedAabbs.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        &hkContainerTempAllocator::s_alloc,
        sortedAabbs.m_data,
        32 * sortedAabbs.m_capacityAndFlags);
    sortedAabbs.m_data = 0i64;
    v138 = 0;
  }
  else
  {
LABEL_96:
    if ( v88[2] == (v88[3] & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, v88, 12);
    v92 = (int)v88[2];
    v93 = *(hkaiBooleanOperation::EdgeEdgeIntersect **)v88;
    v88[2] = v92 + 1;
    v93[v92].m_edgeIndex = -1;
    v94 = --v88[2];
    if ( v94 > 1 )
      hkAlgorithm::quickSortRecursive<hkaiBooleanOperation::EdgeEdgeIntersect,unsigned int (*)(hkaiBooleanOperation::EdgeEdgeIntersect const &,hkaiBooleanOperation::EdgeEdgeIntersect const &)>(
        *(hkaiBooleanOperation::EdgeEdgeIntersect **)v88,
        0,
        v94 - 1,
        hkaiBooleanOperation_orderEdgeEdgeIntersect);
    v95 = *(char **)v88;
    v96 = *(_DWORD *)v95;
    v97 = 0;
    p_m_vertices = 0i64;
    v136.m_enum = HK_SUCCESS;
    if ( v148 > 0 )
    {
      v98 = intersects;
      do
      {
        m_size = p_m_edges->m_size;
        resulta.m_enum = m_size;
        if ( v96 == v97 )
        {
          for ( i = v95 + 12; *(_DWORD *)i == v96; i += 12 )
            ;
          v101 = (i - v95) / 12;
          v102 = 2 * v101 + 2;
          v103 = p_m_edges->m_capacityAndFlags & 0x3FFFFFFF;
          v104 = v102 + resulta.m_enum;
          if ( v103 >= v102 + resulta.m_enum )
          {
            LODWORD(v154) = 0;
          }
          else
          {
            v105 = 2 * v103;
            if ( v104 < v105 )
              v104 = v105;
            hkArrayUtil::_reserve((hkResult *)&v154, &hkContainerHeapAllocator::s_alloc, p_m_edges, v104, 16);
            if ( (_DWORD)v154 )
              goto LABEL_67;
          }
          LODWORD(v142) = p_m_edges->m_size;
          v106 = v142 + v102;
          v107 = p_m_edges->m_capacityAndFlags & 0x3FFFFFFF;
          if ( v107 >= (int)v142 + v102 )
          {
            v141.m_enum = HK_SUCCESS;
          }
          else
          {
            v108 = 2 * v107;
            if ( v106 < v108 )
              v106 = v108;
            hkArrayUtil::_reserve(&v141, &hkContainerHeapAllocator::s_alloc, p_m_edges, v106, 16);
          }
          p_m_edges->m_size += v102;
          v109 = v156;
          v110 = &p_m_edges->m_data[(int)v142 + 2];
          v110[-2].m_a = v156->m_a;
          v111 = *((_DWORD *)v95 + 1);
          v110[-2].m_face = m_face;
          v110[-2].m_b = v111;
          v110[-2].m_data = 0;
          v110[-1].m_a = *((_DWORD *)v95 + 1);
          v112 = v109->m_a;
          v110[-1].m_face = m_face;
          v110[-1].m_b = v112;
          v110[-1].m_data = 0;
          if ( (int)v101 - 1 > 0 )
          {
            v113 = (unsigned int)(v101 - 1);
            do
            {
              v114 = *((_DWORD *)v95 + 1);
              v110 += 2;
              v95 += 12;
              v110[-2].m_a = v114;
              v115 = *((_DWORD *)v95 + 1);
              v110[-2].m_face = m_face;
              v110[-2].m_data = 0;
              v110[-2].m_b = v115;
              v110[-1].m_a = *((_DWORD *)v95 + 1);
              v116 = *((_DWORD *)v95 - 2);
              v110[-1].m_face = m_face;
              v110[-1].m_data = 0;
              v110[-1].m_b = v116;
              --v113;
            }
            while ( v113 );
          }
          v110->m_a = *((_DWORD *)v95 + 1);
          v117 = v109->m_b;
          v110->m_face = m_face;
          v110->m_b = v117;
          v110->m_data = 0;
          v110[1].m_a = v109->m_b;
          v118 = *((_DWORD *)v95 + 1);
          v110[1].m_face = m_face;
          v110[1].m_data = 0;
          v110[1].m_b = v118;
          v96 = *(_DWORD *)i;
          v95 = i;
          m_size = resulta.m_enum;
        }
        else
        {
          v119 = m_size + 2;
          v120 = p_m_edges->m_capacityAndFlags & 0x3FFFFFFF;
          if ( v120 >= m_size + 2 )
          {
            v140.m_enum = HK_SUCCESS;
          }
          else
          {
            v121 = 2 * v120;
            if ( v119 < v121 )
              v119 = v121;
            hkArrayUtil::_reserve(&v140, &hkContainerHeapAllocator::s_alloc, p_m_edges, v119, 16);
            if ( v140.m_enum )
              goto LABEL_67;
          }
          v122 = p_m_edges->m_size;
          v123 = v122 + 2;
          v124 = p_m_edges->m_capacityAndFlags & 0x3FFFFFFF;
          if ( v124 >= (int)v122 + 2 )
          {
            HIDWORD(v142) = 0;
          }
          else
          {
            v125 = 2 * v124;
            if ( v123 < v125 )
              v123 = v125;
            hkArrayUtil::_reserve((hkResult *)&v142 + 1, &hkContainerHeapAllocator::s_alloc, p_m_edges, v123, 16);
          }
          p_m_edges->m_size += 2;
          v126 = v122;
          v109 = v156;
          v127 = &p_m_edges->m_data[v126];
          v127->m_a = v156->m_a;
          v128 = v109->m_b;
          v127->m_face = m_face;
          v127->m_b = v128;
          v127->m_data = 0;
          v127[1].m_a = v109->m_b;
          v129 = v109->m_a;
          v127[1].m_face = m_face;
          v127[1].m_b = v129;
          v127[1].m_data = 0;
        }
        if ( v98 )
        {
          if ( v98->m_intersects.m_size == (v98->m_intersects.m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, v98, 16);
          v130 = &v98->m_intersects.m_data[v98->m_intersects.m_size++];
          v130->m_faceA = m_face;
          v130->m_faceB = v109->m_data;
          v131 = p_m_edges->m_size;
          v130->m_startEdgeIndex = m_size;
          v130->m_numEdges = v131 - m_size;
        }
        v97 = v136.m_enum + 1;
        v156 = v109 + 1;
        ++v136.m_enum;
        p_m_vertices = (char *)p_m_vertices + 1;
      }
      while ( (__int64)p_m_vertices < v148 );
    }
    v65 = v155;
    v132 = sortArray.m_capacityAndFlags;
    sortArray.m_size = 0;
    v155->m_enum = HK_SUCCESS;
    if ( v132 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, sortArray.m_data, 8 * v132);
    sortArray.m_data = 0i64;
    sortArray.m_capacityAndFlags = 0x80000000;
    sortedAabbs.m_size = 0;
    if ( sortedAabbs.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        &hkContainerTempAllocator::s_alloc,
        sortedAabbs.m_data,
        32 * sortedAabbs.m_capacityAndFlags);
    sortedAabbs.m_data = 0i64;
    v138 = 0;
  }
  sortedAabbs.m_capacityAndFlags = 0x80000000;
  if ( v139 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 32 * v139);
  return v65;
}
    v155->m_enum = HK_SUCCESS;
    if ( v132 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, sortArray.m_data, 8 * v132);
    sortArray.m_data = 0i64;
    sortArray.m_capacityAndFlags = 0x80000000;
    sortedAabbs.m_size = 0;
    if ( sortedAabbs.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        &hkContainerTempAllocator::s_alloc,
        sortedAabbs.m_data,
        32 * sortedAabb

// File Line: 1627
// RVA: 0xBA3E70
_BOOL8 __fastcall hkaiBooleanOperation_orderByFace(hkaiEdgeGeometry::Edge *a, hkaiEdgeGeometry::Edge *b)
{
  return a->m_face < b->m_face;
}

// File Line: 1633
// RVA: 0xBA3B30
hkResult *__fastcall hkaiBooleanOperation::_addFaceFaceIntersections(
        hkaiBooleanOperation *this,
        hkResult *result,
        hkArray<hkVector4f,hkContainerHeapAllocator> *faceNormals,
        hkArray<hkaiEdgeGeometry::Edge,hkContainerHeapAllocator> *faceFaceEdges,
        hkaiBooleanFaceFaceIntersects *intersects,
        hkaiEdgeGeometry *geomOut)
{
  int v8; // r9d
  int v10; // eax
  int v12; // eax
  hkaiEdgeGeometry::Edge *v14; // rcx
  int v15; // r8d
  hkaiEdgeGeometry::Edge *m_data; // r9
  hkaiEdgeGeometry::Edge *v17; // rdi
  hkaiEdgeGeometry *v18; // rbp
  hkaiBooleanFaceFaceIntersects *v19; // r14
  __int64 m_face; // rcx
  hkaiEdgeGeometry::Edge *v21; // rbx
  hkResult resulta; // [rsp+88h] [rbp+20h] BYREF

  v8 = faceFaceEdges->m_size + 1;
  v10 = faceFaceEdges->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v10 >= v8 )
  {
    resulta.m_enum = HK_SUCCESS;
  }
  else
  {
    v12 = 2 * v10;
    if ( v8 < v12 )
      v8 = v12;
    hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, faceFaceEdges, v8, 16);
    if ( resulta.m_enum )
    {
      result->m_enum = HK_FAILURE;
      return result;
    }
  }
  if ( faceFaceEdges->m_size == (faceFaceEdges->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, faceFaceEdges, 16);
  v14 = &faceFaceEdges->m_data[faceFaceEdges->m_size++];
  v14->m_face = -1;
  v15 = --faceFaceEdges->m_size;
  if ( v15 > 1 )
    hkAlgorithm::quickSortRecursive<hkaiEdgeGeometry::Edge,unsigned int (*)(hkaiEdgeGeometry::Edge const &,hkaiEdgeGeometry::Edge const &)>(
      faceFaceEdges->m_data,
      0,
      v15 - 1,
      hkaiBooleanOperation_orderByFace);
  m_data = faceFaceEdges->m_data;
  v17 = &faceFaceEdges->m_data[faceFaceEdges->m_size];
  if ( faceFaceEdges->m_data >= v17 )
  {
LABEL_17:
    result->m_enum = HK_SUCCESS;
  }
  else
  {
    v18 = geomOut;
    v19 = intersects;
    while ( 1 )
    {
      m_face = (int)m_data->m_face;
      v21 = m_data + 1;
      if ( m_data[1].m_face == (_DWORD)m_face )
      {
        do
          ++v21;
        while ( v21->m_face == (_DWORD)m_face );
      }
      hkaiBooleanOperation::_addFaceIntersections(
        this,
        &resulta,
        (const __m128i *)&faceNormals->m_data[m_face],
        m_data,
        v21 - m_data,
        v19,
        v18);
      if ( resulta.m_enum )
        break;
      m_data = v21;
      if ( v21 >= v17 )
        goto LABEL_17;
    }
    result->m_enum = HK_FAILURE;
  }
  return result;
}

// File Line: 1668
// RVA: 0xBA0B00
hkResult *__fastcall hkaiBooleanOperation::_setGeometry(
        hkaiBooleanOperation *this,
        hkResult *result,
        hkaiBooleanOperation::GeometricInfo *info,
        hkaiEdgeGeometry *geom)
{
  hkVector4f *m_data; // rax
  hkVector4f v9; // xmm2
  int v10; // edx
  hkVector4f v11; // xmm0
  __int64 v12; // rcx
  hkVector4f *v13; // rax
  hkResult resulta; // [rsp+40h] [rbp+18h] BYREF
  hkResult v15; // [rsp+48h] [rbp+20h] BYREF

  m_data = geom->m_vertices.m_data;
  info->m_geometry = geom;
  info->m_vertices = m_data;
  hkaiUniqueEdges::setGeometry(&info->m_uniqueEdges, &resulta, geom);
  if ( resulta.m_enum || (hkaiFaceEdges::setGeometry(&info->m_faceEdges, &v15, geom), v15.m_enum) )
  {
    result->m_enum = HK_FAILURE;
    return result;
  }
  else
  {
    info->m_aabb.m_min = (hkVector4f)xmmword_141A712A0;
    v9.m_quad = (__m128)xmmword_141A712A0;
    v10 = 0;
    v11.m_quad = _mm_xor_ps(
                   (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                   (__m128)xmmword_141A712A0);
    info->m_aabb.m_max = (hkVector4f)v11.m_quad;
    if ( geom->m_vertices.m_size > 0 )
    {
      v12 = 0i64;
      do
      {
        v13 = geom->m_vertices.m_data;
        ++v10;
        v9.m_quad = _mm_min_ps(v9.m_quad, v13[v12++].m_quad);
        info->m_aabb.m_min = (hkVector4f)v9.m_quad;
        v11.m_quad = _mm_max_ps(v11.m_quad, v13[v12 - 1].m_quad);
        info->m_aabb.m_max = (hkVector4f)v11.m_quad;
      }
      while ( v10 < geom->m_vertices.m_size );
    }
    result->m_enum = HK_SUCCESS;
    return result;
  }
}

// File Line: 1692
// RVA: 0xBA1DE0
hkResult *__fastcall hkaiBooleanOperation::_calculateFaceAabbs(
        hkResult *result,
        hkArray<hkVector4f,hkContainerHeapAllocator> *verticesIn,
        hkaiFaceEdges *faceEdges,
        hkAabb *otherAabb,
        hkArray<hk1AxisSweep::AabbInt,hkContainerTempAllocator> *faceAabbsOut)
{
  hkArray<hk1AxisSweep::AabbInt,hkContainerTempAllocator> *v5; // r12
  int v6; // r13d
  int v8; // ebx
  int v9; // eax
  hkResult *v10; // r14
  int v11; // eax
  int v12; // r9d
  int m_capacityAndFlags; // eax
  int v14; // eax
  int v15; // eax
  int v16; // r9d
  int v17; // r8d
  hkVector4f *m_data; // r15
  int v19; // edi
  hk1AxisSweep::AabbInt *v20; // rbx
  __int64 v21; // rsi
  __m128 *p_m_quad; // r12
  __int64 v23; // r14
  __int64 v24; // rax
  unsigned int **v25; // rdx
  unsigned __int64 v26; // r8
  unsigned int *v27; // rax
  unsigned int **v28; // rdx
  hkVector4f v29; // xmm2
  hkVector4f v30; // xmm1
  unsigned int *v31; // rax
  __int64 v32; // rcx
  int v33; // eax
  __int64 v34; // rbx
  int v35; // eax
  int v36; // r9d
  hk1AxisSweep::AabbInt *v37; // rcx
  int v38; // r8d
  hkResult resulta; // [rsp+30h] [rbp-50h] BYREF
  hkResult v41; // [rsp+34h] [rbp-4Ch] BYREF
  hkResult v42; // [rsp+38h] [rbp-48h] BYREF
  hkArrayBase<hkRadixSort::SortData32> sortArray; // [rsp+40h] [rbp-40h] BYREF
  hkArrayBase<hk1AxisSweep::AabbInt> array; // [rsp+50h] [rbp-30h] BYREF
  hkAabb aabbIn; // [rsp+60h] [rbp-20h] BYREF
  hkaiFaceEdges *v47; // [rsp+D0h] [rbp+50h] BYREF
  hkAabb *v48; // [rsp+D8h] [rbp+58h]

  v48 = otherAabb;
  v47 = faceEdges;
  v5 = faceAabbsOut;
  v6 = faceEdges->m_faceStartEdges.m_size - 1;
  v8 = v6 + 4;
  v9 = faceAabbsOut->m_capacityAndFlags & 0x3FFFFFFF;
  v10 = result;
  if ( v9 >= v6 + 4 )
  {
    resulta.m_enum = HK_SUCCESS;
  }
  else
  {
    v11 = 2 * v9;
    v12 = v6 + 4;
    if ( v8 < v11 )
      v12 = v11;
    hkArrayUtil::_reserve(&resulta, &hkContainerTempAllocator::s_alloc, faceAabbsOut, v12, 32);
    if ( resulta.m_enum )
    {
      v10->m_enum = HK_FAILURE;
      return v10;
    }
  }
  m_capacityAndFlags = 0x80000000;
  v5->m_size = v8;
  array.m_data = 0i64;
  array.m_size = 0;
  array.m_capacityAndFlags = 0x80000000;
  sortArray.m_data = 0i64;
  sortArray.m_capacityAndFlags = 0x80000000;
  sortArray.m_size = 0;
  if ( v8 <= 0 )
  {
    v41.m_enum = HK_SUCCESS;
  }
  else
  {
    hkArrayUtil::_reserve(&v41, &hkContainerTempAllocator::s_alloc, &array, v6 + 4, 32);
    if ( v41.m_enum )
      goto LABEL_15;
    m_capacityAndFlags = sortArray.m_capacityAndFlags;
  }
  v14 = m_capacityAndFlags & 0x3FFFFFFF;
  array.m_size = v6 + 4;
  if ( v14 >= v8 )
    goto LABEL_18;
  v15 = 2 * v14;
  v16 = v6 + 4;
  if ( v8 < v15 )
    v16 = v15;
  hkArrayUtil::_reserve(&v42, &hkContainerTempAllocator::s_alloc, &sortArray, v16, 8);
  if ( v42.m_enum == HK_SUCCESS )
  {
LABEL_18:
    m_data = verticesIn->m_data;
    v19 = 1;
    sortArray.m_size = v6 + 4;
    v20 = v5->m_data;
    v21 = 1i64;
    if ( v6 > 1i64 )
    {
      p_m_quad = &v48->m_min.m_quad;
      v23 = (__int64)v47;
      do
      {
        v24 = *(_QWORD *)(v23 + 16);
        v25 = *(unsigned int ***)(v24 + 8 * v21);
        v26 = *(_QWORD *)(v24 + 8 * v21 + 8);
        v27 = *v25;
        v28 = v25 + 1;
        v29.m_quad = (__m128)m_data[*v27];
        aabbIn.m_max = (hkVector4f)v29.m_quad;
        v30.m_quad = v29.m_quad;
        for ( aabbIn.m_min = (hkVector4f)v29.m_quad; (unsigned __int64)v28 < v26; aabbIn.m_max = (hkVector4f)v29.m_quad )
        {
          v31 = *v28++;
          v32 = *v31;
          v30.m_quad = _mm_min_ps(v30.m_quad, m_data[*v31].m_quad);
          aabbIn.m_min = (hkVector4f)v30.m_quad;
          v29.m_quad = _mm_max_ps(v29.m_quad, m_data[v32].m_quad);
        }
        if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(*p_m_quad, v29.m_quad), _mm_cmple_ps(v30.m_quad, p_m_quad[1]))) & 7) == 7 )
          hk1AxisSweep::AabbInt::set(v20++, &aabbIn, v19);
        ++v21;
        ++v19;
      }
      while ( v21 < v6 );
      v10 = result;
      v5 = faceAabbsOut;
    }
    v20->m_min[0] = -1;
    v20[1].m_min[0] = -1;
    v20[2].m_min[0] = -1;
    v20[3].m_min[0] = -1;
    v33 = v5->m_capacityAndFlags & 0x3FFFFFFF;
    v34 = &v20[4] - v5->m_data;
    if ( v33 < (int)v34 )
    {
      v35 = 2 * v33;
      v36 = v34;
      if ( (int)v34 < v35 )
        v36 = v35;
      hkArrayUtil::_reserve((hkResult *)&v47, &hkContainerTempAllocator::s_alloc, v5, v36, 32);
    }
    v37 = v5->m_data;
    v5->m_size = v34;
    hk1AxisSweep::sortAabbs(v37, v34 - 4, &sortArray, &array);
    v38 = sortArray.m_capacityAndFlags;
    v10->m_enum = HK_SUCCESS;
    sortArray.m_size = 0;
    if ( v38 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, sortArray.m_data, 8 * v38);
    sortArray.m_data = 0i64;
    array.m_size = 0;
    goto LABEL_33;
  }
LABEL_15:
  v17 = sortArray.m_capacityAndFlags;
  sortArray.m_size = 0;
  v10->m_enum = HK_FAILURE;
  if ( v17 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, sortArray.m_data, 8 * v17);
  sortArray.m_data = 0i64;
  array.m_size = 0;
LABEL_33:
  sortArray.m_capacityAndFlags = 0x80000000;
  if ( array.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      array.m_data,
      32 * array.m_capacityAndFlags);
  return v10;
}

// File Line: 1774
// RVA: 0xBA1AD0
hkResult *__fastcall hkaiBooleanOperation::_calculateEdgeAabbs(
        hkResult *result,
        hkArray<hkVector4f,hkContainerHeapAllocator> *verticesIn,
        hkaiUniqueEdges *edgeList,
        hkAabb *otherAabb,
        hkArray<hk1AxisSweep::AabbInt,hkContainerTempAllocator> *edgeAabbs)
{
  hkArray<hk1AxisSweep::AabbInt,hkContainerTempAllocator> *v5; // r15
  int v6; // r13d
  int v8; // ebx
  int v9; // eax
  int v11; // eax
  int v12; // r9d
  int m_capacityAndFlags; // eax
  int v14; // eax
  int v15; // eax
  int v16; // r9d
  int v17; // r8d
  hkVector4f *m_data; // r8
  hk1AxisSweep::AabbInt *v19; // rbx
  int v20; // esi
  __int64 v21; // rdi
  __int64 v22; // r12
  __int64 v23; // r13
  __int64 v24; // r15
  __m128 v25; // xmm0
  unsigned int **v26; // rcx
  __int64 v27; // rdx
  hkVector4f v28; // xmm2
  __int64 v29; // rax
  __m128 v30; // xmm1
  int v31; // eax
  __int64 v32; // rbx
  int v33; // eax
  int v34; // r9d
  hk1AxisSweep::AabbInt *v35; // rcx
  int v36; // r8d
  hkResult resulta; // [rsp+30h] [rbp-50h] BYREF
  hkResult v39; // [rsp+34h] [rbp-4Ch] BYREF
  hkResult v40[2]; // [rsp+38h] [rbp-48h] BYREF
  hkArrayBase<hkRadixSort::SortData32> sortArray; // [rsp+40h] [rbp-40h] BYREF
  hkArrayBase<hk1AxisSweep::AabbInt> array; // [rsp+50h] [rbp-30h] BYREF
  hkAabb aabbIn; // [rsp+60h] [rbp-20h] BYREF
  hkaiUniqueEdges *v44; // [rsp+D0h] [rbp+50h] BYREF
  hkAabb *v45; // [rsp+D8h] [rbp+58h]

  v45 = otherAabb;
  v44 = edgeList;
  v5 = edgeAabbs;
  v6 = edgeList->m_startUniqueEdge.m_size - 1;
  v8 = v6 + 4;
  v9 = edgeAabbs->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v9 >= v6 + 4 )
  {
    resulta.m_enum = HK_SUCCESS;
  }
  else
  {
    v11 = 2 * v9;
    v12 = v6 + 4;
    if ( v8 < v11 )
      v12 = v11;
    hkArrayUtil::_reserve(&resulta, &hkContainerTempAllocator::s_alloc, edgeAabbs, v12, 32);
    if ( resulta.m_enum )
    {
      result->m_enum = HK_FAILURE;
      return result;
    }
  }
  m_capacityAndFlags = 0x80000000;
  v5->m_size = v8;
  array.m_data = 0i64;
  array.m_size = 0;
  array.m_capacityAndFlags = 0x80000000;
  sortArray.m_data = 0i64;
  sortArray.m_capacityAndFlags = 0x80000000;
  sortArray.m_size = 0;
  if ( v8 <= 0 )
  {
    v39.m_enum = HK_SUCCESS;
  }
  else
  {
    hkArrayUtil::_reserve(&v39, &hkContainerTempAllocator::s_alloc, &array, v6 + 4, 32);
    if ( v39.m_enum )
      goto LABEL_15;
    m_capacityAndFlags = sortArray.m_capacityAndFlags;
  }
  v14 = m_capacityAndFlags & 0x3FFFFFFF;
  array.m_size = v6 + 4;
  if ( v14 >= v8 )
    goto LABEL_18;
  v15 = 2 * v14;
  v16 = v6 + 4;
  if ( v8 < v15 )
    v16 = v15;
  hkArrayUtil::_reserve(v40, &hkContainerTempAllocator::s_alloc, &sortArray, v16, 8);
  if ( v40[0].m_enum == HK_SUCCESS )
  {
LABEL_18:
    m_data = verticesIn->m_data;
    sortArray.m_size = v6 + 4;
    v19 = v5->m_data;
    v20 = 0;
    v21 = 0i64;
    *(_QWORD *)&v40[0].m_enum = m_data;
    v22 = v6;
    if ( v6 > 0 )
    {
      v23 = (__int64)v44;
      v24 = (__int64)v45;
      do
      {
        v25 = *(__m128 *)v24;
        v26 = *(unsigned int ***)(*(_QWORD *)(v23 + 16) + 8 * v21);
        v27 = (__int64)*v26;
        v28.m_quad = (__m128)m_data[**v26];
        aabbIn.m_min = (hkVector4f)v28.m_quad;
        aabbIn.m_max = (hkVector4f)v28.m_quad;
        v29 = *(unsigned int *)(v27 + 4);
        aabbIn.m_min.m_quad = _mm_min_ps(v28.m_quad, m_data[*(unsigned int *)(v27 + 4)].m_quad);
        v30 = _mm_cmple_ps(aabbIn.m_min.m_quad, *(__m128 *)(v24 + 16));
        aabbIn.m_max.m_quad = _mm_max_ps(v28.m_quad, m_data[v29].m_quad);
        if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v25, aabbIn.m_max.m_quad), v30)) & 7) == 7 )
        {
          hk1AxisSweep::AabbInt::set(v19, &aabbIn, v20);
          m_data = *(hkVector4f **)&v40[0].m_enum;
          ++v19;
        }
        ++v21;
        ++v20;
      }
      while ( v21 < v22 );
      v5 = edgeAabbs;
    }
    v19->m_min[0] = -1;
    v19[1].m_min[0] = -1;
    v19[2].m_min[0] = -1;
    v19[3].m_min[0] = -1;
    v31 = v5->m_capacityAndFlags & 0x3FFFFFFF;
    v32 = &v19[4] - v5->m_data;
    if ( v31 < (int)v32 )
    {
      v33 = 2 * v31;
      v34 = v32;
      if ( (int)v32 < v33 )
        v34 = v33;
      hkArrayUtil::_reserve((hkResult *)&v44, &hkContainerTempAllocator::s_alloc, v5, v34, 32);
    }
    v35 = v5->m_data;
    v5->m_size = v32;
    hk1AxisSweep::sortAabbs(v35, v32 - 4, &sortArray, &array);
    v36 = sortArray.m_capacityAndFlags;
    result->m_enum = HK_SUCCESS;
    sortArray.m_size = 0;
    if ( v36 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, sortArray.m_data, 8 * v36);
    sortArray.m_data = 0i64;
    array.m_size = 0;
    goto LABEL_31;
  }
LABEL_15:
  v17 = sortArray.m_capacityAndFlags;
  result->m_enum = HK_FAILURE;
  sortArray.m_size = 0;
  if ( v17 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, sortArray.m_data, 8 * v17);
  sortArray.m_data = 0i64;
  array.m_size = 0;
LABEL_31:
  sortArray.m_capacityAndFlags = 0x80000000;
  if ( array.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      array.m_data,
      32 * array.m_capacityAndFlags);
  return result;
}

// File Line: 1854
// RVA: 0xB9EFC0
hkResult *__fastcall hkaiBooleanOperation::subtract(
        hkaiBooleanOperation *this,
        hkResult *result,
        hkaiEdgeGeometry *a,
        hkaiEdgeGeometry *b,
        hkaiEdgeGeometry *geomOut,
        hkaiBooleanFaceFaceIntersects *intersects,
        hkaiBooleanFilter *filter)
{
  hkResult *v9; // rbx
  hkaiBooleanFaceFaceIntersects *v11; // rax
  hkaiBooleanFilter *v12; // r12
  hkaiFaceEdges *p_m_faceEdges; // r15
  hkaiEdgeGeometry *v14; // rdi
  int m_size; // r9d
  int v16; // eax
  __int64 v17; // rax
  hkaiEdgeGeometry::Face *m_data; // rcx
  __int64 v19; // rdi
  char *v20; // rdx
  unsigned int v21; // eax
  hkBitField *p_m_edgeAIntersected; // rdi
  int v23; // r13d
  int v24; // r15d
  __int32 v25; // ecx
  unsigned int *v26; // r8
  int v27; // eax
  int v28; // eax
  int v29; // eax
  int v30; // r9d
  __int64 v31; // rcx
  unsigned int *v32; // rdi
  int v33; // ecx
  int v34; // eax
  unsigned int v35; // ecx
  hkArray<hkVector4f,hkContainerHeapAllocator> *p_m_vertices; // rdx
  hkaiEdgeGeometry *m_geometry; // rdx
  hkVector4f v38; // xmm1
  int m_capacityAndFlags; // r8d
  hkArray<hkVector4f,hkContainerHeapAllocator> *v40; // rdx
  hkaiEdgeGeometry *v41; // rdx
  hkVector4f v42; // xmm1
  hk1AxisSweep::AabbInt *v43; // rdx
  hkMemoryAllocatorVtbl *vfptr; // rax
  hkContainerTempAllocator::Allocator *v45; // rcx
  int v46; // r15d
  int v47; // r15d
  int v48; // r9d
  __int64 v49; // rdi
  int v50; // r12d
  hkaiEdgeGeometry *v51; // r13
  int v52; // edi
  int v53; // eax
  int v54; // eax
  int v55; // r9d
  int v56; // r8d
  int v58; // eax
  hkVector4f *v59; // r8
  __m128 *p_m_quad; // r9
  __int64 v61; // r10
  int v62; // edx
  int v63; // edi
  int v64; // eax
  int v65; // eax
  hkVector4f *v66; // r10
  __m128 *v67; // r8
  __int64 v68; // r11
  int v69; // edx
  int v70; // edi
  int v71; // eax
  hkArray<hk1AxisSweep::AabbInt,hkContainerTempAllocator> faceAabbsOut; // [rsp+30h] [rbp-91h] BYREF
  hkArray<hk1AxisSweep::AabbInt,hkContainerTempAllocator> edgeAabbs; // [rsp+40h] [rbp-81h] BYREF
  hkResult v74; // [rsp+50h] [rbp-71h] BYREF
  hkAabb otherAabb; // [rsp+60h] [rbp-61h] BYREF
  hkaiEdgeGeometry **array; // [rsp+80h] [rbp-41h] BYREF
  int v77; // [rsp+88h] [rbp-39h]
  int geom; // [rsp+8Ch] [rbp-35h]
  hkaiEdgeGeometry *geom_4; // [rsp+90h] [rbp-31h] BYREF
  hkResult resulta; // [rsp+128h] [rbp+67h] BYREF

  v9 = result;
  if ( b->m_edges.m_size <= 0 || a->m_edges.m_size <= 0 )
  {
    hkaiEdgeGeometry::set(geomOut, &resulta, a);
    v9->m_enum = resulta.m_enum;
    return v9;
  }
  v11 = intersects;
  this->m_intersectVertices.m_size = 0;
  this->m_startVertices.m_size = 0;
  this->m_endVertices.m_size = 0;
  if ( v11 )
    v11->m_intersects.m_size = 0;
  hkaiBooleanOperation::_setGeometry(this, &resulta, &this->m_a, a);
  if ( resulta.m_enum == HK_SUCCESS )
  {
    hkaiBooleanOperation::_setGeometry(this, &resulta, &this->m_b, b);
    if ( resulta.m_enum == HK_SUCCESS )
    {
      v12 = filter;
      p_m_faceEdges = &this->m_a.m_faceEdges;
      filter->vfptr->setFaceEdges(filter, &v74, &this->m_a.m_faceEdges, &this->m_b.m_faceEdges);
      if ( v74.m_enum == HK_SUCCESS )
      {
        v14 = geomOut;
        geomOut->m_edges.m_size = 0;
        m_size = a->m_faces.m_size;
        if ( (v14->m_faces.m_capacityAndFlags & 0x3FFFFFFF) >= m_size )
        {
          resulta.m_enum = HK_SUCCESS;
          goto LABEL_13;
        }
        hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, &v14->m_faces, m_size, 12);
        if ( resulta.m_enum == HK_SUCCESS )
        {
LABEL_13:
          v16 = v14->m_faces.m_capacityAndFlags & 0x3FFFFFFF;
          if ( v16 < a->m_faces.m_size )
          {
            if ( v14->m_faces.m_capacityAndFlags >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                &hkContainerHeapAllocator::s_alloc,
                v14->m_faces.m_data,
                12 * v16);
            v74.m_enum = 12 * a->m_faces.m_size;
            v14->m_faces.m_data = (hkaiEdgeGeometry::Face *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                              &hkContainerHeapAllocator::s_alloc,
                                                              &v74);
            v14->m_faces.m_capacityAndFlags = v74.m_enum / 12;
          }
          v17 = a->m_faces.m_size;
          m_data = v14->m_faces.m_data;
          v14->m_faces.m_size = v17;
          v19 = v17;
          if ( (int)v17 > 0 )
          {
            v20 = (char *)((char *)a->m_faces.m_data - (char *)m_data);
            do
            {
              v21 = *(unsigned int *)((char *)&m_data->m_data + (_QWORD)v20);
              ++m_data;
              m_data[-1].m_data = v21;
              m_data[-1].m_faceIndex = *(_DWORD *)((char *)m_data + (_QWORD)v20 - 8);
              *(_DWORD *)&m_data[-1].m_flags.m_storage = *(_DWORD *)((char *)m_data + (_QWORD)v20 - 4);
              --v19;
            }
            while ( v19 );
          }
          if ( resulta.m_enum )
            goto LABEL_41;
          p_m_edgeAIntersected = &this->m_edgeAIntersected;
          v23 = this->m_a.m_geometry->m_edges.m_size;
          if ( this != (hkaiBooleanOperation *)-256i64 )
          {
            this->m_edgeAIntersected.m_storage.m_words.m_capacityAndFlags = 0x80000000;
            v24 = (v23 + 31) >> 5;
            p_m_edgeAIntersected->m_storage.m_words.m_data = 0i64;
            this->m_edgeAIntersected.m_storage.m_words.m_size = 0;
            v25 = v24;
            if ( v24 )
            {
              resulta.m_enum = 4 * v24;
              v26 = (unsigned int *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                      &hkContainerHeapAllocator::s_alloc,
                                      &resulta);
              v25 = resulta.m_enum / 4;
            }
            else
            {
              v26 = 0i64;
            }
            p_m_edgeAIntersected->m_storage.m_words.m_data = v26;
            this->m_edgeAIntersected.m_storage.m_words.m_size = v24;
            v27 = 0x80000000;
            if ( v25 )
              v27 = v25;
            this->m_edgeAIntersected.m_storage.m_words.m_capacityAndFlags = v27;
            this->m_edgeAIntersected.m_storage.m_numBits = v23;
            v28 = this->m_edgeAIntersected.m_storage.m_words.m_capacityAndFlags & 0x3FFFFFFF;
            if ( v28 < v24 )
            {
              v29 = 2 * v28;
              v30 = (v23 + 31) >> 5;
              if ( v24 < v29 )
                v30 = v29;
              hkArrayUtil::_reserve(&v74, &hkContainerHeapAllocator::s_alloc, &this->m_edgeAIntersected, v30, 4);
            }
            this->m_edgeAIntersected.m_storage.m_words.m_size = v24;
            p_m_faceEdges = &this->m_a.m_faceEdges;
          }
          if ( !p_m_edgeAIntersected->m_storage.m_words.m_data )
            goto LABEL_41;
          if ( this->m_edgeAIntersected.m_storage.m_words.m_size - 1 >= 0 )
          {
            v31 = (unsigned int)this->m_edgeAIntersected.m_storage.m_words.m_size;
            v32 = p_m_edgeAIntersected->m_storage.m_words.m_data;
            while ( v31 )
            {
              *v32++ = 0;
              --v31;
            }
          }
          v33 = this->m_a.m_geometry->m_edges.m_size;
          v34 = this->m_b.m_uniqueEdges.m_startUniqueEdge.m_size;
          this->m_edgeBFeatureBase = v33;
          v35 = v34 - 1 + v33;
          this->m_faceFaceFeatureBase = v35;
          this->m_faceFaceFeatureCount = v35;
          hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::clear(&this->m_faceFaceFeatureMap.m_map);
          this->m_intersectBase = a->m_vertices.m_size;
          if ( this->m_a.m_faceEdges.m_faceStartEdges.m_size == 3 && this->m_a.m_geometry->m_edges.m_size == 3 )
          {
            hkaiBooleanOperation::_simpleClassifyEdgeAFaceB(this, &resulta, v12);
            if ( resulta.m_enum )
              goto LABEL_41;
            hkaiBooleanOperation::_simpleClassifyFaceAEdgeB(this, &resulta, v12);
            if ( resulta.m_enum )
              goto LABEL_41;
LABEL_65:
            v46 = p_m_faceEdges->m_faceStartEdges.m_size;
            v77 = 0;
            v47 = v46 - 1;
            array = &geom_4;
            geom = -2147483644;
            if ( v47 <= 4 )
            {
              resulta.m_enum = HK_SUCCESS;
            }
            else
            {
              v48 = v47;
              if ( v47 < 8 )
                v48 = 8;
              hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, &array, v48, 16);
              if ( resulta.m_enum )
              {
                v77 = 0;
LABEL_80:
                v56 = geom;
                v9->m_enum = HK_FAILURE;
LABEL_81:
                if ( v56 < 0 )
                  return v9;
                vfptr = hkContainerHeapAllocator::s_alloc.vfptr;
                v43 = (hk1AxisSweep::AabbInt *)array;
                v45 = (hkContainerTempAllocator::Allocator *)&hkContainerHeapAllocator::s_alloc;
                goto LABEL_83;
              }
            }
            v49 = 1i64;
            v77 = v47;
            v50 = 1;
            if ( v47 > 1i64 )
            {
              do
              {
                hkaiEdgeGeometry::calculateFaceNormal(
                  a,
                  this->m_a.m_faceEdges.m_faceStartEdges.m_data[v49],
                  this->m_a.m_faceEdges.m_faceStartEdges.m_data[v49 + 1],
                  (hkVector4f *)&array[2 * v50]);
                ++v49;
                ++v50;
              }
              while ( v49 < v47 );
              v9 = result;
            }
            v51 = geomOut;
            hkaiBooleanOperation::_addCompleteEdges(this, &resulta, filter, geomOut);
            if ( resulta.m_enum == HK_SUCCESS )
            {
              v52 = this->m_intersectVertices.m_size + a->m_vertices.m_size;
              v53 = v51->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
              if ( v53 >= v52 )
              {
                resulta.m_enum = HK_SUCCESS;
              }
              else
              {
                v54 = 2 * v53;
                v55 = this->m_intersectVertices.m_size + a->m_vertices.m_size;
                if ( v52 < v54 )
                  v55 = v54;
                hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, &v51->m_vertices, v55, 16);
                if ( resulta.m_enum )
                  goto LABEL_79;
              }
              v51->m_vertices.m_size = v52;
              v58 = a->m_vertices.m_size;
              v59 = a->m_vertices.m_data;
              p_m_quad = &v51->m_vertices.m_data->m_quad;
              if ( v58 > 0 )
              {
                v61 = (unsigned int)v58;
                do
                {
                  v62 = v59->m_quad.m128_i32[2];
                  v63 = v59->m_quad.m128_i32[3];
                  v64 = v59->m_quad.m128_i32[0];
                  p_m_quad->m128_i32[1] = v59->m_quad.m128_i32[1];
                  p_m_quad->m128_i32[2] = v62;
                  p_m_quad->m128_i32[3] = v63;
                  p_m_quad->m128_i32[0] = v64;
                  ++p_m_quad;
                  ++v59;
                  --v61;
                }
                while ( v61 );
              }
              v65 = this->m_intersectVertices.m_size;
              v66 = this->m_intersectVertices.m_data;
              v67 = &v51->m_vertices.m_data[a->m_vertices.m_size].m_quad;
              if ( v65 > 0 )
              {
                v68 = (unsigned int)v65;
                do
                {
                  v69 = v66->m_quad.m128_i32[2];
                  v70 = v66->m_quad.m128_i32[3];
                  v71 = v66->m_quad.m128_i32[0];
                  v67->m128_i32[1] = v66->m_quad.m128_i32[1];
                  v67->m128_i32[2] = v69;
                  v67->m128_i32[3] = v70;
                  v67->m128_i32[0] = v71;
                  ++v67;
                  ++v66;
                  --v68;
                }
                while ( v68 );
              }
              hkaiBooleanOperation::_addPartialEdges(
                this,
                &resulta,
                (hkArray<hkVector4f,hkContainerHeapAllocator> *)&array,
                v51,
                intersects);
              v56 = geom;
              v77 = 0;
              if ( resulta.m_enum )
                v9->m_enum = HK_FAILURE;
              else
                v9->m_enum = HK_SUCCESS;
              goto LABEL_81;
            }
LABEL_79:
            v77 = 0;
            goto LABEL_80;
          }
          p_m_vertices = &this->m_a.m_geometry->m_vertices;
          edgeAabbs.m_data = 0i64;
          edgeAabbs.m_size = 0;
          edgeAabbs.m_capacityAndFlags = 0x80000000;
          hkaiBooleanOperation::_calculateEdgeAabbs(
            &resulta,
            p_m_vertices,
            &this->m_a.m_uniqueEdges,
            &this->m_b.m_aabb,
            &edgeAabbs);
          if ( resulta.m_enum )
          {
            v9->m_enum = HK_FAILURE;
LABEL_59:
            edgeAabbs.m_size = 0;
            if ( edgeAabbs.m_capacityAndFlags < 0 )
              return v9;
            v43 = edgeAabbs.m_data;
            vfptr = hkContainerTempAllocator::s_alloc.vfptr;
            v45 = &hkContainerTempAllocator::s_alloc;
LABEL_83:
            ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, hk1AxisSweep::AabbInt *))vfptr->bufFree)(
              v45,
              v43);
            return v9;
          }
          m_geometry = this->m_b.m_geometry;
          v38.m_quad = (__m128)this->m_a.m_aabb.m_max;
          otherAabb.m_min = this->m_a.m_aabb.m_min;
          otherAabb.m_max = (hkVector4f)v38.m_quad;
          faceAabbsOut.m_data = 0i64;
          faceAabbsOut.m_size = 0;
          faceAabbsOut.m_capacityAndFlags = 0x80000000;
          otherAabb.m_max.m_quad.m128_i32[2] = 2139095022;
          otherAabb.m_min.m_quad.m128_i32[2] = -8388626;
          hkaiBooleanOperation::_calculateFaceAabbs(
            &resulta,
            &m_geometry->m_vertices,
            &this->m_b.m_faceEdges,
            &otherAabb,
            &faceAabbsOut);
          if ( resulta.m_enum )
          {
            m_capacityAndFlags = faceAabbsOut.m_capacityAndFlags;
            faceAabbsOut.m_size = 0;
          }
          else
          {
            hkaiBooleanOperation::_sweepAndPruneClassifyEdgeAFaceB(this, &resulta, v12, &edgeAabbs, &faceAabbsOut);
            m_capacityAndFlags = faceAabbsOut.m_capacityAndFlags;
            faceAabbsOut.m_size = 0;
            if ( resulta.m_enum == HK_SUCCESS )
            {
              if ( faceAabbsOut.m_capacityAndFlags >= 0 )
                hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                  &hkContainerTempAllocator::s_alloc,
                  faceAabbsOut.m_data,
                  32 * faceAabbsOut.m_capacityAndFlags);
              faceAabbsOut.m_data = 0i64;
              faceAabbsOut.m_capacityAndFlags = 0x80000000;
              edgeAabbs.m_size = 0;
              if ( edgeAabbs.m_capacityAndFlags >= 0 )
                hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                  &hkContainerTempAllocator::s_alloc,
                  edgeAabbs.m_data,
                  32 * edgeAabbs.m_capacityAndFlags);
              v40 = &this->m_b.m_geometry->m_vertices;
              edgeAabbs.m_data = 0i64;
              edgeAabbs.m_size = 0;
              edgeAabbs.m_capacityAndFlags = 0x80000000;
              hkaiBooleanOperation::_calculateEdgeAabbs(
                &resulta,
                v40,
                &this->m_b.m_uniqueEdges,
                &this->m_a.m_aabb,
                &edgeAabbs);
              if ( resulta.m_enum )
              {
                v9->m_enum = HK_FAILURE;
                goto LABEL_59;
              }
              v41 = this->m_a.m_geometry;
              v42.m_quad = (__m128)this->m_b.m_aabb.m_max;
              p_m_faceEdges = &this->m_a.m_faceEdges;
              otherAabb.m_min = this->m_b.m_aabb.m_min;
              otherAabb.m_max = (hkVector4f)v42.m_quad;
              faceAabbsOut.m_data = 0i64;
              faceAabbsOut.m_size = 0;
              faceAabbsOut.m_capacityAndFlags = 0x80000000;
              otherAabb.m_max.m_quad.m128_i32[2] = 2139095022;
              otherAabb.m_min.m_quad.m128_i32[2] = -8388626;
              hkaiBooleanOperation::_calculateFaceAabbs(
                &resulta,
                &v41->m_vertices,
                &this->m_a.m_faceEdges,
                &otherAabb,
                &faceAabbsOut);
              if ( resulta.m_enum )
              {
                m_capacityAndFlags = faceAabbsOut.m_capacityAndFlags;
                faceAabbsOut.m_size = 0;
              }
              else
              {
                hkaiBooleanOperation::_sweepAndPruneClassifyFaceAEdgeB(this, &resulta, v12, &faceAabbsOut, &edgeAabbs);
                m_capacityAndFlags = faceAabbsOut.m_capacityAndFlags;
                faceAabbsOut.m_size = 0;
                if ( resulta.m_enum == HK_SUCCESS )
                {
                  if ( faceAabbsOut.m_capacityAndFlags >= 0 )
                    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                      &hkContainerTempAllocator::s_alloc,
                      faceAabbsOut.m_data,
                      32 * faceAabbsOut.m_capacityAndFlags);
                  faceAabbsOut.m_data = 0i64;
                  faceAabbsOut.m_capacityAndFlags = 0x80000000;
                  edgeAabbs.m_size = 0;
                  if ( edgeAabbs.m_capacityAndFlags >= 0 )
                    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                      &hkContainerTempAllocator::s_alloc,
                      edgeAabbs.m_data,
                      32 * edgeAabbs.m_capacityAndFlags);
                  goto LABEL_65;
                }
              }
            }
          }
          v9->m_enum = HK_FAILURE;
          if ( m_capacityAndFlags >= 0 )
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(
              &hkContainerTempAllocator::s_alloc,
              faceAabbsOut.m_data,
              32 * m_capacityAndFlags);
          faceAabbsOut.m_data = 0i64;
          faceAabbsOut.m_capacityAndFlags = 0x80000000;
          goto LABEL_59;
        }
      }
LABEL_41:
      v9->m_enum = HK_FAILURE;
      return v9;
    }
  }
  v9->m_enum = HK_FAILURE;
  return v9;
}

// File Line: 2153
// RVA: 0xB9F860
void __fastcall hkaiBooleanOperation::GeometricInfo::clear(hkaiBooleanOperation::GeometricInfo *this)
{
  hkaiUniqueEdges *p_m_uniqueEdges; // rcx

  p_m_uniqueEdges = &this->m_uniqueEdges;
  p_m_uniqueEdges[-1].m_startUniqueEdge.m_data = 0i64;
  *(_QWORD *)&p_m_uniqueEdges[-1].m_startUniqueEdge.m_size = 0i64;
  hkaiUniqueEdges::clear(p_m_uniqueEdges);
  hkaiFaceEdges::clear(&this->m_faceEdges);
  this->m_aabb.m_min = (hkVector4f)xmmword_141A712A0;
  this->m_aabb.m_max.m_quad = _mm_xor_ps(
                                (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                                this->m_aabb.m_min.m_quad);
}

// File Line: 2165
// RVA: 0xBA3CD0
void __fastcall hkaiBooleanOperation::clear(hkaiBooleanOperation *this)
{
  int m_capacityAndFlags; // r8d

  hkaiBooleanOperation::GeometricInfo::clear(&this->m_a);
  hkaiBooleanOperation::GeometricInfo::clear(&this->m_b);
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::clear(&this->m_faceFaceFeatureMap.m_map);
  *(_QWORD *)&this->m_faceFaceFeatureCount = 0i64;
  *(_QWORD *)&this->m_edgeBFeatureBase = 0i64;
  this->m_edgeAIntersected.m_storage.m_numBits = 0;
  m_capacityAndFlags = this->m_edgeAIntersected.m_storage.m_words.m_capacityAndFlags;
  this->m_edgeAIntersected.m_storage.m_words.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_edgeAIntersected.m_storage.m_words.m_data,
      4 * m_capacityAndFlags);
  this->m_edgeAIntersected.m_storage.m_words.m_data = 0i64;
  this->m_edgeAIntersected.m_storage.m_words.m_capacityAndFlags = 0x80000000;
  this->m_intersectVertices.m_size = 0;
  this->m_startVertices.m_size = 0;
  this->m_endVertices.m_size = 0;
}

