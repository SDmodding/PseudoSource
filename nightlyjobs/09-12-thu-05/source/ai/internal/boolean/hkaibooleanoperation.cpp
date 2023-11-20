// File Line: 162
// RVA: 0xB9FD50
__int64 __fastcall hkaiBooleanOperation::_calculateIntersect2(hkaiBooleanOperation::ShadowResult *ab, hkaiBooleanOperation::ShadowResult *ba, hkaiBooleanOperation::ShadowResult *res)
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
  v8 = _mm_sub_ps(
         v7,
         _mm_sub_ps(_mm_shuffle_ps(v4.m_quad, v4.m_quad, 85), _mm_shuffle_ps(ab->m_shadower.m_quad, v3.m_quad, 85)));
  v9 = _mm_sub_ps((__m128)0i64, _mm_andnot_ps(_mm_cmpeqps((__m128)0i64, v8), _mm_div_ps(v7, v8)));
  v10 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(ba->m_shadowee.m_quad, v3.m_quad), v9), v5.m_quad);
  v11 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(ba->m_shadower.m_quad, v4.m_quad), v9), v6.m_quad);
  v12 = _mm_cmpleps(_mm_shuffle_ps(v10, v10, 170), _mm_shuffle_ps(v11, v11, 170));
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
    result = 0i64;
  }
  return result;
}

// File Line: 208
// RVA: 0xB9FE50
void __fastcall hkaiBooleanOperation::_calculateIntersect3(hkaiBooleanOperation::ShadowResult *ab, hkaiBooleanOperation::ShadowResult *ba, hkVector4f *res)
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
                    _mm_sub_ps((__m128)0i64, _mm_andnot_ps(_mm_cmpeqps((__m128)0i64, v6), _mm_div_ps(v5, v6))),
                    _mm_sub_ps(ba->m_shadowee.m_quad, v4.m_quad)),
                  v3.m_quad);
}

// File Line: 237
// RVA: 0xB9F8C0
int __fastcall hkaiBooleanOperation::_s11(hkVector4f *vs_ea, hkVector4f *ve_ea, hkVector4f *vs_eb, hkVector4f *ve_eb)
{
  hkVector4f v4; // xmm2
  __m128 v5; // xmm11
  __m128 v6; // xmm12
  __m128 v7; // xmm13
  __m128 v8; // xmm9
  __m128 v9; // xmm7
  __m128 v10; // xmm8
  __m128 v11; // xmm1
  hkVector4f v12; // xmm5
  unsigned int v13; // er8
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
  unsigned int v26; // er8
  int v27; // ecx
  int v28; // eax
  __m128 v29; // xmm3
  __m128 v30; // xmm4
  __m128 v31; // xmm0
  __m128 v32; // xmm4
  __m128 v33; // xmm1
  int v34; // edx
  __m128 v35; // xmm1
  unsigned int v36; // er8
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
  unsigned int v49; // er8
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
  hkaiBooleanOperation::ShadowResult ba; // [rsp+20h] [rbp-89h]
  __m128 v63; // [rsp+58h] [rbp-51h]
  __m128 v64; // [rsp+68h] [rbp-41h]
  hkaiBooleanOperation::ShadowResult *v65; // [rsp+128h] [rbp+7Fh]

  v4.m_quad = 0i64;
  ba.m_shadowee.m_quad.m128_i32[2] = 0;
  ba.m_x = 0;
  v5 = ve_eb->m_quad;
  v6 = vs_eb->m_quad;
  v7 = ve_ea->m_quad;
  v8 = _mm_shuffle_ps(v5, v5, 0);
  v63 = 0i64;
  v9 = _mm_shuffle_ps(v7, v7, 0);
  v10 = _mm_shuffle_ps(v6, v6, 0);
  v64 = 0i64;
  v11 = _mm_cmpleps(v9, v10);
  ba.m_shadower = 0i64;
  *(hkVector4f *)((char *)&ba.m_shadower + 8) = 0i64;
  v12.m_quad = 0i64;
  v13 = (_mm_movemask_ps(_mm_cmpleps(v9, v8)) != 0) - (_mm_movemask_ps(v11) != 0);
  if ( v13 )
  {
    v14 = 0;
    v15 = _mm_or_ps(_mm_and_ps(v6, v11), _mm_andnot_ps(v11, v5));
    v16 = _mm_or_ps(_mm_and_ps(v5, v11), _mm_andnot_ps(v11, v6));
    v17 = _mm_shuffle_ps(v15, v15, 0);
    v18 = _mm_add_ps(
            _mm_mul_ps(
              _mm_sub_ps(v16, v15),
              _mm_div_ps(_mm_sub_ps(v9, v17), _mm_sub_ps(_mm_shuffle_ps(v16, v16, 0), v17))),
            v15);
    v19 = _mm_cmpleps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps(v18, v18, 85));
    v20 = _mm_and_ps(v18, v19);
    v21 = _mm_andnot_ps(v19, v7);
    v22 = _mm_and_ps(v7, v19);
    if ( _mm_movemask_ps(v19) == 15 )
      v14 = v13;
    v4.m_quad = _mm_or_ps(v21, v20);
    v12.m_quad = _mm_or_ps(v22, _mm_andnot_ps(v19, v18));
    if ( v14 )
    {
      ba.m_x = v13;
      ba.m_s = v14;
      ba.m_shadower = (hkVector4f)v4.m_quad;
      *(hkVector4f *)((char *)&ba.m_shadower + 8) = (hkVector4f)v12.m_quad;
    }
    else
    {
      ba.m_shadowee.m_quad.m128_u64[1] = v13;
      v63 = v4.m_quad;
      v64 = v12.m_quad;
    }
  }
  else
  {
    v14 = 0;
  }
  v23 = vs_ea->m_quad;
  v24 = _mm_shuffle_ps(v23, v23, 0);
  v25 = _mm_cmpleps(v24, v10);
  v26 = (_mm_movemask_ps(_mm_cmpleps(v24, v8)) != 0) - (_mm_movemask_ps(v25) != 0);
  if ( v26 )
  {
    v27 = 0;
    v29 = _mm_or_ps(_mm_andnot_ps(v25, v5), _mm_and_ps(v6, v25));
    v30 = _mm_or_ps(_mm_andnot_ps(v25, v6), _mm_and_ps(v5, v25));
    v31 = _mm_shuffle_ps(v29, v29, 0);
    v32 = _mm_add_ps(
            _mm_mul_ps(
              _mm_sub_ps(v30, v29),
              _mm_div_ps(_mm_sub_ps(v24, v31), _mm_sub_ps(_mm_shuffle_ps(v30, v30, 0), v31))),
            v29);
    v33 = _mm_cmpleps(_mm_shuffle_ps(v23, v23, 85), _mm_shuffle_ps(v32, v32, 85));
    v4.m_quad = _mm_or_ps(_mm_andnot_ps(v33, v23), _mm_and_ps(v32, v33));
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
      ba.m_shadower = (hkVector4f)v4.m_quad;
      *(hkVector4f *)((char *)&ba.m_shadower + 8) = (hkVector4f)v12.m_quad;
    }
    else
    {
      ba.m_shadowee.m_quad.m128_u64[1] = v26;
      v63 = v4.m_quad;
      v64 = v12.m_quad;
    }
  }
  v35 = _mm_cmpleps(v24, v8);
  v36 = (_mm_movemask_ps(v35) != 0) - (_mm_movemask_ps(_mm_cmpleps(v9, v8)) != 0);
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
    v43 = _mm_cmpleps(_mm_shuffle_ps(v42, v42, 85), _mm_shuffle_ps(v5, v5, 85));
    v44 = _mm_andnot_ps(v43, v42);
    v45 = _mm_and_ps(v43, v5);
    v46 = _mm_and_ps(v42, v43);
    if ( _mm_movemask_ps(v43) == 15 )
      v37 = v36;
    v38 = v37;
    v4.m_quad = _mm_or_ps(v45, v44);
    v12.m_quad = _mm_or_ps(v46, _mm_andnot_ps(v43, v5));
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
      ba.m_shadower = (hkVector4f)v4.m_quad;
      *(hkVector4f *)((char *)&ba.m_shadower + 8) = (hkVector4f)v12.m_quad;
    }
    else
    {
      ba.m_shadowee.m_quad.m128_u64[1] = v36;
      v63 = v4.m_quad;
      v64 = v12.m_quad;
    }
  }
  v48 = _mm_cmpleps(v24, v10);
  v49 = (_mm_movemask_ps(v48) != 0) - (_mm_movemask_ps(_mm_cmpleps(v9, v10)) != 0);
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
    v56 = _mm_cmpleps(_mm_shuffle_ps(v55, v55, 85), _mm_shuffle_ps(v6, v6, 85));
    v57 = _mm_andnot_ps(v56, v55);
    v58 = _mm_and_ps(v56, v6);
    v59 = _mm_and_ps(v55, v56);
    if ( _mm_movemask_ps(v56) == 15 )
      v50 = v49;
    v51 = v50;
    v4.m_quad = _mm_or_ps(v58, v57);
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
      ba.m_shadower = (hkVector4f)v4.m_quad;
      *(hkVector4f *)((char *)&ba.m_shadower + 8) = (hkVector4f)v12.m_quad;
    }
    else
    {
      ba.m_shadowee.m_quad.m128_u64[1] = v49;
      v63 = v4.m_quad;
      v64 = v12.m_quad;
    }
  }
  v65->m_x = v60;
  if ( v60 )
    return hkaiBooleanOperation::_calculateIntersect2(
             (hkaiBooleanOperation::ShadowResult *)((char *)&ba + 40),
             &ba,
             v65);
  v65->m_s = 0;
  return 0;
}

// File Line: 277
// RVA: 0xB9FEB0
__int64 __fastcall hkaiBooleanOperation::_calculate2dLineIntersect(hkVector4f *vs_ea, hkVector4f *ve_ea, hkVector4f *vs_eb, hkVector4f *ve_eb)
{
  hkVector4f v4; // xmm2
  __m128 v5; // xmm11
  __m128 v6; // xmm12
  __m128 v7; // xmm13
  __m128 v8; // xmm9
  __m128 v9; // xmm7
  __m128 v10; // xmm8
  __m128 v11; // xmm1
  hkVector4f v12; // xmm5
  unsigned int v13; // er8
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
  unsigned int v26; // er8
  int v27; // ecx
  int v28; // eax
  __m128 v29; // xmm3
  __m128 v30; // xmm4
  __m128 v31; // xmm0
  __m128 v32; // xmm4
  __m128 v33; // xmm1
  int v34; // edx
  __m128 v35; // xmm1
  unsigned int v36; // er8
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
  unsigned int v49; // er8
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
  __int64 result; // rax
  hkaiBooleanOperation::ShadowResult ba; // [rsp+20h] [rbp-89h]
  __m128 v63; // [rsp+58h] [rbp-51h]
  __m128 v64; // [rsp+68h] [rbp-41h]
  hkaiBooleanOperation::ShadowResult *v65; // [rsp+128h] [rbp+7Fh]

  v4.m_quad = 0i64;
  ba.m_shadowee.m_quad.m128_i32[2] = 0;
  ba.m_x = 0;
  v5 = ve_eb->m_quad;
  v6 = vs_eb->m_quad;
  v7 = ve_ea->m_quad;
  v8 = _mm_shuffle_ps(v5, v5, 0);
  v63 = 0i64;
  v9 = _mm_shuffle_ps(v7, v7, 0);
  v10 = _mm_shuffle_ps(v6, v6, 0);
  v64 = 0i64;
  v11 = _mm_cmpleps(v9, v10);
  ba.m_shadower = 0i64;
  *(hkVector4f *)((char *)&ba.m_shadower + 8) = 0i64;
  v12.m_quad = 0i64;
  v13 = (_mm_movemask_ps(_mm_cmpleps(v9, v8)) != 0) - (_mm_movemask_ps(v11) != 0);
  if ( v13 )
  {
    v14 = 0;
    v15 = _mm_or_ps(_mm_and_ps(v6, v11), _mm_andnot_ps(v11, v5));
    v16 = _mm_or_ps(_mm_and_ps(v5, v11), _mm_andnot_ps(v11, v6));
    v17 = _mm_shuffle_ps(v15, v15, 0);
    v18 = _mm_add_ps(
            _mm_mul_ps(
              _mm_sub_ps(v16, v15),
              _mm_div_ps(_mm_sub_ps(v9, v17), _mm_sub_ps(_mm_shuffle_ps(v16, v16, 0), v17))),
            v15);
    v19 = _mm_cmpleps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps(v18, v18, 85));
    v20 = _mm_and_ps(v18, v19);
    v21 = _mm_andnot_ps(v19, v7);
    v22 = _mm_and_ps(v7, v19);
    if ( _mm_movemask_ps(v19) == 15 )
      v14 = v13;
    v4.m_quad = _mm_or_ps(v21, v20);
    v12.m_quad = _mm_or_ps(v22, _mm_andnot_ps(v19, v18));
    if ( v14 )
    {
      ba.m_x = v13;
      ba.m_s = v14;
      ba.m_shadower = (hkVector4f)v4.m_quad;
      *(hkVector4f *)((char *)&ba.m_shadower + 8) = (hkVector4f)v12.m_quad;
    }
    else
    {
      ba.m_shadowee.m_quad.m128_u64[1] = v13;
      v63 = v4.m_quad;
      v64 = v12.m_quad;
    }
  }
  else
  {
    v14 = 0;
  }
  v23 = vs_ea->m_quad;
  v24 = _mm_shuffle_ps(v23, v23, 0);
  v25 = _mm_cmpleps(v24, v10);
  v26 = (_mm_movemask_ps(_mm_cmpleps(v24, v8)) != 0) - (_mm_movemask_ps(v25) != 0);
  if ( v26 )
  {
    v27 = 0;
    v29 = _mm_or_ps(_mm_andnot_ps(v25, v5), _mm_and_ps(v6, v25));
    v30 = _mm_or_ps(_mm_andnot_ps(v25, v6), _mm_and_ps(v5, v25));
    v31 = _mm_shuffle_ps(v29, v29, 0);
    v32 = _mm_add_ps(
            _mm_mul_ps(
              _mm_sub_ps(v30, v29),
              _mm_div_ps(_mm_sub_ps(v24, v31), _mm_sub_ps(_mm_shuffle_ps(v30, v30, 0), v31))),
            v29);
    v33 = _mm_cmpleps(_mm_shuffle_ps(v23, v23, 85), _mm_shuffle_ps(v32, v32, 85));
    v4.m_quad = _mm_or_ps(_mm_andnot_ps(v33, v23), _mm_and_ps(v32, v33));
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
      ba.m_shadower = (hkVector4f)v4.m_quad;
      *(hkVector4f *)((char *)&ba.m_shadower + 8) = (hkVector4f)v12.m_quad;
    }
    else
    {
      ba.m_shadowee.m_quad.m128_u64[1] = v26;
      v63 = v4.m_quad;
      v64 = v12.m_quad;
    }
  }
  v35 = _mm_cmpleps(v24, v8);
  v36 = (_mm_movemask_ps(v35) != 0) - (_mm_movemask_ps(_mm_cmpleps(v9, v8)) != 0);
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
    v43 = _mm_cmpleps(_mm_shuffle_ps(v42, v42, 85), _mm_shuffle_ps(v5, v5, 85));
    v44 = _mm_andnot_ps(v43, v42);
    v45 = _mm_and_ps(v43, v5);
    v46 = _mm_and_ps(v42, v43);
    if ( _mm_movemask_ps(v43) == 15 )
      v37 = v36;
    v38 = v37;
    v4.m_quad = _mm_or_ps(v45, v44);
    v12.m_quad = _mm_or_ps(v46, _mm_andnot_ps(v43, v5));
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
      ba.m_shadower = (hkVector4f)v4.m_quad;
      *(hkVector4f *)((char *)&ba.m_shadower + 8) = (hkVector4f)v12.m_quad;
    }
    else
    {
      ba.m_shadowee.m_quad.m128_u64[1] = v36;
      v63 = v4.m_quad;
      v64 = v12.m_quad;
    }
  }
  v48 = _mm_cmpleps(v24, v10);
  v49 = (_mm_movemask_ps(v48) != 0) - (_mm_movemask_ps(_mm_cmpleps(v9, v10)) != 0);
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
    v56 = _mm_cmpleps(_mm_shuffle_ps(v55, v55, 85), _mm_shuffle_ps(v6, v6, 85));
    v57 = _mm_andnot_ps(v56, v55);
    v58 = _mm_and_ps(v56, v6);
    v59 = _mm_and_ps(v55, v56);
    if ( _mm_movemask_ps(v56) == 15 )
      v50 = v49;
    v51 = v50;
    v4.m_quad = _mm_or_ps(v58, v57);
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
      ba.m_shadower = (hkVector4f)v4.m_quad;
      *(hkVector4f *)((char *)&ba.m_shadower + 8) = (hkVector4f)v12.m_quad;
    }
    else
    {
      ba.m_shadowee.m_quad.m128_u64[1] = v49;
      v63 = v4.m_quad;
      v64 = v12.m_quad;
    }
  }
  v65->m_x = v60;
  if ( v60 )
  {
    hkaiBooleanOperation::_calculateIntersect2((hkaiBooleanOperation::ShadowResult *)((char *)&ba + 40), &ba, v65);
    result = (unsigned int)v65->m_x;
  }
  else
  {
    v65->m_s = 0;
    result = 0i64;
  }
  return result;
}

// File Line: 320
// RVA: 0xBA0350
__int64 __fastcall hkaiBooleanOperation::_s02(hkaiBooleanOperation *this, hkVector4f *va, int faceBIndex, hkaiBooleanOperation::ShadowResult *res)
{
  hkVector4f *v4; // rbx
  hkaiEdgeGeometry::Edge *const **v5; // rax
  unsigned int **v6; // r10
  unsigned int **v7; // r11
  hkVector4f *v8; // r8
  __m128 v9; // xmm8
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
  hkaiBooleanOperation::ShadowResult ba; // [rsp+20h] [rbp-A8h]
  hkaiBooleanOperation::ShadowResult ab; // [rsp+50h] [rbp-78h]

  res->m_x = 0;
  ab.m_x = 0;
  v4 = va;
  ba.m_x = 0;
  ab.m_shadower = 0i64;
  ab.m_shadowee = 0i64;
  ba.m_shadower = 0i64;
  v5 = this->m_b.m_faceEdges.m_faceStartEdges.m_data;
  ba.m_shadowee = 0i64;
  v6 = (unsigned int **)v5[faceBIndex];
  v7 = (unsigned int **)v5[faceBIndex + 1];
  v8 = this->m_b.m_vertices;
  if ( v6 != v7 )
  {
    do
    {
      v9 = v4->m_quad;
      v10.m_quad = 0i64;
      v11.m_quad = 0i64;
      v12 = _mm_shuffle_ps(v9, v9, 0);
      v13 = v8[(*v6)[1]].m_quad;
      v14 = v8[**v6].m_quad;
      v15 = _mm_cmpleps(v12, _mm_shuffle_ps(v14, v14, 0));
      v16 = (_mm_movemask_ps(_mm_cmpleps(v12, _mm_shuffle_ps(v13, v13, 0))) != 0) - (_mm_movemask_ps(v15) != 0);
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
        v23 = _mm_cmpleps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v22, v22, 85));
        v24 = _mm_and_ps(v22, v23);
        v25 = _mm_andnot_ps(v23, v9);
        v26 = _mm_and_ps(v9, v23);
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
__int64 __fastcall hkaiBooleanOperation::_s20(hkaiBooleanOperation *this, int faceAIndex, hkVector4f *vb, hkaiBooleanOperation::ShadowResult *res)
{
  hkaiEdgeGeometry::Edge *const **v4; // rax
  hkVector4f *v5; // r10
  unsigned int **v6; // r11
  hkVector4f *v7; // rbx
  unsigned int **v8; // r8
  __m128 v9; // xmm6
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
  hkaiBooleanOperation::ShadowResult ba; // [rsp+20h] [rbp-98h]
  hkaiBooleanOperation::ShadowResult ab; // [rsp+50h] [rbp-68h]

  res->m_x = 0;
  v4 = this->m_a.m_faceEdges.m_faceStartEdges.m_data;
  v5 = this->m_a.m_vertices;
  ba.m_shadower = 0i64;
  ba.m_shadowee = 0i64;
  ab.m_shadower = 0i64;
  v6 = (unsigned int **)v4[faceAIndex + 1];
  v7 = vb;
  v8 = (unsigned int **)v4[faceAIndex];
  ab.m_shadowee = 0i64;
  ba.m_x = 0;
  ab.m_x = 0;
  if ( v8 != v6 )
  {
    do
    {
      v9 = v7->m_quad;
      v10.m_quad = 0i64;
      v11.m_quad = 0i64;
      v12 = _mm_shuffle_ps(v9, v9, 0);
      v13 = v5[(*v8)[1]].m_quad;
      v14 = v5[**v8].m_quad;
      v15 = _mm_cmpleps(_mm_shuffle_ps(v14, v14, 0), v12);
      v16 = (_mm_movemask_ps(v15) != 0) - (_mm_movemask_ps(_mm_cmpleps(_mm_shuffle_ps(v13, v13, 0), v12)) != 0);
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
        v23 = _mm_cmpleps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v9, v9, 85));
        v24 = _mm_and_ps(v9, v23);
        v25 = _mm_andnot_ps(v23, v22);
        v26 = _mm_and_ps(v22, v23);
        if ( _mm_movemask_ps(v23) == 15 )
          v17 = v16;
        v18 = v17;
        v10.m_quad = _mm_or_ps(v24, v25);
        v11.m_quad = _mm_or_ps(v26, _mm_andnot_ps(v23, v9));
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
__int64 __fastcall hkaiBooleanOperation::_x12(hkaiBooleanOperation *this, hkaiEdgeGeometry::Edge *edgeA, int faceBIndex, hkVector4f *res)
{
  hkVector4f *v4; // rsi
  hkVector4f *v5; // rax
  hkaiEdgeGeometry::Edge *v6; // rbx
  __int64 v7; // rdx
  __int64 v8; // r13
  hkaiBooleanOperation *v9; // r12
  int v10; // edi
  unsigned int v11; // edi
  __int64 v12; // r14
  __int64 v13; // r15
  hkaiEdgeGeometry::Edge *const **v14; // rax
  unsigned int **v15; // rbx
  hkVector4f *v16; // r14
  hkVector4f *v17; // r15
  unsigned int **i; // rsi
  hkaiBooleanOperation::ShadowResult resa; // [rsp+30h] [rbp-69h]
  hkaiBooleanOperation::ShadowResult ba; // [rsp+60h] [rbp-39h]
  hkaiBooleanOperation::ShadowResult ab; // [rsp+90h] [rbp-9h]
  hkVector4f *v23; // [rsp+100h] [rbp+67h]
  hkVector4f *v24; // [rsp+118h] [rbp+7Fh]

  v24 = res;
  v4 = this->m_a.m_vertices;
  v5 = this->m_b.m_vertices;
  v6 = edgeA;
  v7 = edgeA->m_b;
  v8 = faceBIndex;
  ba.m_shadower = 0i64;
  ba.m_shadowee = 0i64;
  ab.m_shadower = 0i64;
  ab.m_shadowee = 0i64;
  resa.m_shadower = 0i64;
  resa.m_shadowee = 0i64;
  v9 = this;
  ba.m_x = 0;
  ab.m_x = 0;
  v23 = v5;
  v10 = -(signed int)hkaiBooleanOperation::_s02(this, &v4[v7], faceBIndex, &resa);
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
  v11 = (unsigned __int64)hkaiBooleanOperation::_s02(v9, &v4[v6->m_a], v8, &resa) + v10;
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
  v12 = v6->m_a;
  v13 = v6->m_b;
  v14 = v9->m_b.m_faceEdges.m_faceStartEdges.m_data;
  v15 = (unsigned int **)v14[v8];
  v16 = &v4[v12];
  v17 = &v4[v13];
  for ( i = (unsigned int **)v14[v8 + 1]; v15 != i; ++v15 )
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
  hkaiBooleanOperation::_calculateIntersect3(&ab, &ba, v24);
  return v11;
}

// File Line: 434
// RVA: 0xBA0920
__int64 __fastcall hkaiBooleanOperation::_x21(hkaiBooleanOperation *this, int faceAIndex, hkaiEdgeGeometry::Edge *edgeB, hkVector4f *res)
{
  hkVector4f *v4; // r12
  hkVector4f *v5; // rax
  hkaiEdgeGeometry::Edge *v6; // rbx
  __int64 v7; // r8
  __int64 v8; // r13
  hkaiBooleanOperation *v9; // rsi
  int v10; // edi
  unsigned int v11; // edi
  hkaiEdgeGeometry::Edge *const **v12; // rax
  __int64 v13; // r14
  __int64 v14; // r15
  unsigned int **v15; // rbx
  unsigned int **v16; // rsi
  hkVector4f *v17; // r14
  hkVector4f *i; // r15
  hkaiBooleanOperation::ShadowResult resa; // [rsp+30h] [rbp-69h]
  hkaiBooleanOperation::ShadowResult ba; // [rsp+60h] [rbp-39h]
  hkaiBooleanOperation::ShadowResult ab; // [rsp+90h] [rbp-9h]
  hkVector4f *v23; // [rsp+100h] [rbp+67h]
  hkVector4f *v24; // [rsp+118h] [rbp+7Fh]

  v24 = res;
  v4 = this->m_b.m_vertices;
  v5 = this->m_a.m_vertices;
  v6 = edgeB;
  v7 = edgeB->m_b;
  v8 = faceAIndex;
  ba.m_shadower = 0i64;
  ba.m_shadowee = 0i64;
  ab.m_shadower = 0i64;
  ab.m_shadowee = 0i64;
  resa.m_shadower = 0i64;
  resa.m_shadowee = 0i64;
  v9 = this;
  ba.m_x = 0;
  ab.m_x = 0;
  v23 = v5;
  v10 = hkaiBooleanOperation::_s20(this, faceAIndex, &v4[v7], &resa);
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
  v11 = v10 - (unsigned __int64)hkaiBooleanOperation::_s20(v9, v8, &v4[v6->m_a], &resa);
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
  v12 = v9->m_a.m_faceEdges.m_faceStartEdges.m_data;
  v13 = v6->m_a;
  v14 = v6->m_b;
  v15 = (unsigned int **)v12[v8];
  v16 = (unsigned int **)v12[v8 + 1];
  v17 = &v4[v13];
  for ( i = &v4[v14]; v15 != v16; ++v15 )
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
  hkaiBooleanOperation::_calculateIntersect3(&ab, &ba, v24);
  return v11;
}

// File Line: 480
// RVA: 0xBA1890
hkResult *__fastcall hkaiBooleanOperation::_addStartEndVertices(hkaiBooleanOperation *this, hkResult *result, unsigned int feature, unsigned int a, int index, int count)
{
  int v6; // esi
  unsigned int v7; // er14
  hkResult *v8; // rbx
  unsigned int v9; // er15
  int v10; // er9
  int v11; // er9
  hkArray<hkaiBooleanOperation::SortVertex,hkContainerHeapAllocator> *v12; // rdi
  int v13; // eax
  int v14; // eax
  int v15; // eax
  unsigned int *v16; // rcx
  __int64 v17; // r12
  int v18; // er9
  hkResult *v19; // rcx
  int v20; // er9
  int v21; // eax
  int v22; // eax
  unsigned int *v23; // rcx
  int v24; // eax
  int *v25; // rax
  __int64 v26; // rcx
  hkResult resulta; // [rsp+30h] [rbp-28h]
  char v29; // [rsp+34h] [rbp-24h]
  hkResult v30; // [rsp+38h] [rbp-20h]

  v6 = count;
  v7 = a;
  v8 = result;
  v9 = feature;
  v10 = abs(count);
  if ( count <= 0 )
  {
    v20 = this->m_startVertices.m_size + v10;
    v12 = &this->m_startVertices;
    v21 = this->m_startVertices.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v21 >= v20 )
    {
      resulta.m_enum = 0;
    }
    else
    {
      v22 = 2 * v21;
      if ( v20 < v22 )
        v20 = v22;
      hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v12, v20, 16);
      if ( resulta.m_enum )
      {
        v8->m_enum = 1;
        return v8;
      }
    }
    v15 = v12->m_capacityAndFlags & 0x3FFFFFFF;
    if ( v6 == -1 )
    {
      if ( v12->m_size == v15 )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v12, 16);
      v23 = &v12->m_data[v12->m_size++].m_feature;
      *v23 = v9;
      v23[2] = v7;
      v23[3] = 0;
      v23[1] = index;
      goto LABEL_32;
    }
    v17 = v12->m_size;
    v6 = -v6;
    v18 = v17 + v6;
    if ( v15 >= (signed int)v17 + v6 )
      goto LABEL_29;
    v19 = &v30;
    goto LABEL_26;
  }
  v11 = this->m_endVertices.m_size + v10;
  v12 = &this->m_endVertices;
  v13 = this->m_endVertices.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v13 >= v11 )
  {
    count = 0;
LABEL_8:
    v15 = v12->m_capacityAndFlags & 0x3FFFFFFF;
    if ( v6 == 1 )
    {
      if ( v12->m_size == v15 )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v12, 16);
      v16 = &v12->m_data[v12->m_size++].m_feature;
      *v16 = v9;
      v16[2] = v7;
      v16[3] = 0;
      v16[1] = index;
LABEL_32:
      v8->m_enum = 0;
      return v8;
    }
    v17 = v12->m_size;
    v18 = v17 + v6;
    if ( v15 >= (signed int)v17 + v6 )
    {
LABEL_29:
      v12->m_size += v6;
      if ( v6 > 0 )
      {
        v25 = &v12->m_data[v17].m_index;
        v26 = (unsigned int)v6;
        do
        {
          *(v25 - 1) = v9;
          v25[1] = v7;
          *v25 = index;
          v25 += 4;
          --v26;
        }
        while ( v26 );
      }
      goto LABEL_32;
    }
    v19 = (hkResult *)&v29;
LABEL_26:
    v24 = 2 * v15;
    if ( v18 < v24 )
      v18 = v24;
    hkArrayUtil::_reserve(v19, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v12, v18, 16);
    goto LABEL_29;
  }
  v14 = 2 * v13;
  if ( v11 < v14 )
    v11 = v14;
  hkArrayUtil::_reserve((hkResult *)&count, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v12, v11, 16);
  if ( !count )
    goto LABEL_8;
  v8->m_enum = 1;
  return v8;
}

// File Line: 590
// RVA: 0xBA2900
hkResult *__fastcall hkaiBooleanOperation::_simpleClassifyFaceAEdgeB(hkaiBooleanOperation *this, hkResult *result, hkaiBooleanFilter *filter)
{
  hkaiEdgeGeometry *v3; // r12
  hkVector4f v4; // xmm6
  unsigned int v5; // edi
  __int64 v6; // rbx
  hkVector4f v7; // xmm7
  hkaiBooleanFilter *v8; // r15
  hkResult *v9; // r14
  hkaiBooleanOperation *v10; // rsi
  __int64 v11; // rbp
  signed int *v12; // rdx
  hkVector4f *v13; // rcx
  hkResult resulta; // [rsp+70h] [rbp+8h]
  hkKeyPair pair; // [rsp+88h] [rbp+20h]

  v3 = this->m_b.m_geometry;
  v4.m_quad = (__m128)this->m_a.m_aabb.m_min;
  v5 = 0;
  v6 = 0i64;
  v7.m_quad = (__m128)this->m_a.m_aabb.m_max;
  v8 = filter;
  v9 = result;
  v10 = this;
  v11 = this->m_b.m_uniqueEdges.m_startUniqueEdge.m_size - 1;
  if ( this->m_b.m_uniqueEdges.m_startUniqueEdge.m_size - 1 <= 0 )
  {
LABEL_5:
    v9->m_enum = 0;
  }
  else
  {
    while ( 1 )
    {
      v12 = (signed int *)*v10->m_b.m_uniqueEdges.m_startUniqueEdge.m_data[v6];
      v13 = v3->m_vertices.m_data;
      if ( (_mm_movemask_ps(
              _mm_and_ps(
                _mm_cmpleps(v4.m_quad, _mm_max_ps(v13[*v12].m_quad, v13[v12[1]].m_quad)),
                _mm_cmpleps(_mm_min_ps(v13[*v12].m_quad, v13[v12[1]].m_quad), v7.m_quad))) & 7) == 7 )
      {
        pair.m_keyA = 1;
        pair.m_keyB = v5;
        hkaiBooleanOperation::_classifyFaceAEdgeB(v10, &resulta, &pair, v8);
        if ( resulta.m_enum )
          break;
      }
      ++v6;
      ++v5;
      if ( v6 >= v11 )
        goto LABEL_5;
    }
    v9->m_enum = 1;
  }
  return v9;
}

// File Line: 621
// RVA: 0xBA2A20
hkResult *__fastcall hkaiBooleanOperation::_simpleClassifyEdgeAFaceB(hkaiBooleanOperation *this, hkResult *result, hkaiBooleanFilter *filter)
{
  hkaiBooleanOperation *v3; // rbp
  hkaiBooleanFilter *v4; // r15
  hkVector4f *v5; // rcx
  hkaiEdgeGeometry::Edge *const **v6; // r10
  hkResult *v7; // r13
  char *v8; // r9
  signed __int64 v9; // r11
  hkaiEdgeGeometry::Edge *const *v10; // rax
  __m128 v11; // xmm2
  signed __int64 v12; // rax
  __m128 v13; // xmm0
  __m128 v14; // xmm2
  unsigned int v15; // esi
  __int64 *v16; // rcx
  signed __int64 v17; // r12
  signed __int64 v18; // r14
  hkaiEdgeGeometry::Edge *const **v19; // rax
  __int64 v20; // r9
  hkaiEdgeGeometry::Edge *const *v21; // rdx
  unsigned __int64 v22; // r8
  hkaiEdgeGeometry::Edge *v23; // rax
  signed int **v24; // rdx
  __m128 v25; // xmm6
  __m128 i; // xmm7
  signed int *v27; // rax
  signed int v28; // ebx
  __m128 *v29; // rdi
  signed __int64 v31; // [rsp+20h] [rbp-C8h]
  char v32; // [rsp+30h] [rbp-B8h]
  hkResult resulta; // [rsp+F0h] [rbp+8h]
  hkKeyPair pair; // [rsp+108h] [rbp+20h]

  v3 = this;
  v4 = filter;
  v5 = this->m_a.m_geometry->m_vertices.m_data;
  v6 = v3->m_a.m_uniqueEdges.m_startUniqueEdge.m_data;
  v7 = result;
  v8 = &v32;
  v9 = 3i64;
  do
  {
    v10 = *v6;
    v8 += 32;
    ++v6;
    v11 = v5[**(signed int **)v10].m_quad;
    v12 = (signed int)(*v10)->m_b;
    v13 = _mm_min_ps(v11, v5[v12].m_quad);
    v14 = _mm_max_ps(v11, v5[v12].m_quad);
    *((__m128 *)v8 - 2) = v13;
    *((__m128 *)v8 - 1) = v14;
    --v9;
  }
  while ( v9 );
  v15 = 1;
  v16 = (__int64 *)&v3->m_b.m_geometry->m_vertices;
  v17 = v3->m_b.m_faceEdges.m_faceStartEdges.m_size - 1;
  v31 = (signed __int64)&v3->m_b.m_geometry->m_vertices;
  v18 = 1i64;
  if ( v17 <= 1 )
  {
LABEL_13:
    v7->m_enum = 0;
  }
  else
  {
LABEL_4:
    v19 = v3->m_b.m_faceEdges.m_faceStartEdges.m_data;
    v20 = *v16;
    v21 = v19[v18];
    v22 = (unsigned __int64)v19[v18 + 1];
    v23 = *v21;
    v24 = (signed int **)(v21 + 1);
    v25 = *(__m128 *)(*v16 + 16i64 * (signed int)v23->m_a);
    for ( i = *(__m128 *)(*v16 + 16i64 * (signed int)v23->m_a);
          (unsigned __int64)v24 < v22;
          i = _mm_max_ps(i, *(__m128 *)(v20 + 16i64 * *v27)) )
    {
      v27 = *v24;
      ++v24;
      v25 = _mm_min_ps(v25, *(__m128 *)(v20 + 16i64 * *v27));
    }
    v28 = 0;
    v29 = (__m128 *)&v32;
    while ( 1 )
    {
      if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmpleps(v25, v29[1]), _mm_cmpleps(*v29, i))) & 7) == 7 )
      {
        pair.m_keyA = v28;
        pair.m_keyB = v15;
        hkaiBooleanOperation::_classifyEdgeAFaceB(v3, &resulta, &pair, v4);
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
        v16 = (__int64 *)v31;
        goto LABEL_4;
      }
    }
    v7->m_enum = 1;
  }
  return v7;
}

// File Line: 678
// RVA: 0xBA26E0
hkResult *__fastcall hkaiBooleanOperation::_sweepAndPruneClassifyEdgeAFaceB(hkaiBooleanOperation *this, hkResult *result, hkaiBooleanFilter *filter, hkArray<hk1AxisSweep::AabbInt,hkContainerTempAllocator> *edgeAabbsA, hkArray<hk1AxisSweep::AabbInt,hkContainerTempAllocator> *faceAabbsB)
{
  hk1AxisSweep::AabbInt *v5; // r11
  hk1AxisSweep::AabbInt *v6; // rdi
  hkResult *v7; // rbx
  hkaiBooleanFilter *v8; // rsi
  hkaiBooleanOperation *v9; // rbp
  unsigned int v10; // eax
  bool v11; // cf
  bool v12; // zf
  hk1AxisSweep::AabbInt *v13; // rax
  hk1AxisSweep::AabbInt *v14; // rcx
  hk1AxisSweep::IteratorAB v16; // [rsp+20h] [rbp-38h]
  hkKeyPair pair; // [rsp+78h] [rbp+20h]

  v5 = edgeAabbsA->m_data;
  v6 = faceAabbsB->m_data;
  v7 = result;
  v16.m_numA = edgeAabbsA->m_size - 4;
  v8 = filter;
  v9 = this;
  v16.m_numB = faceAabbsB->m_size - 4;
  v10 = v6->m_min[0];
  v16.m_pa = v5;
  v11 = v5->m_min[0] < v10;
  v12 = v5->m_min[0] == v10;
  v16.m_pb = v6;
  v16.m_aIsBigger = !v11 && !v12;
  if ( v11 || v12 )
  {
    v16.m_currentPtr = v5;
    v5 = v6;
  }
  else
  {
    v16.m_currentPtr = v6;
  }
  v16.m_potentialPtr = v5 - 1;
  while ( 1 )
  {
    hk1AxisSweep::IteratorAB::next(&v16);
    if ( v16.m_numA <= 0 || v16.m_numB <= 0 )
      break;
    if ( v16.m_aIsBigger )
    {
      v13 = v16.m_potentialPtr;
      v14 = v16.m_pb;
    }
    else
    {
      v13 = v16.m_pa;
      v14 = v16.m_potentialPtr;
    }
    pair.m_keyA = *(_DWORD *)v13->m_expansionMin;
    pair.m_keyB = *(_DWORD *)v14->m_expansionMin;
    hkaiBooleanOperation::_classifyEdgeAFaceB(v9, (hkResult *)&faceAabbsB, &pair, v8);
    if ( (_DWORD)faceAabbsB )
    {
      v7->m_enum = 1;
      return v7;
    }
  }
  v7->m_enum = 0;
  return v7;
}

// File Line: 704
// RVA: 0xBA27F0
hkResult *__fastcall hkaiBooleanOperation::_sweepAndPruneClassifyFaceAEdgeB(hkaiBooleanOperation *this, hkResult *result, hkaiBooleanFilter *filter, hkArray<hk1AxisSweep::AabbInt,hkContainerTempAllocator> *faceAabbsA, hkArray<hk1AxisSweep::AabbInt,hkContainerTempAllocator> *edgeAabbsB)
{
  hk1AxisSweep::AabbInt *v5; // r11
  hk1AxisSweep::AabbInt *v6; // rdi
  hkResult *v7; // rbx
  hkaiBooleanFilter *v8; // rsi
  hkaiBooleanOperation *v9; // rbp
  unsigned int v10; // eax
  bool v11; // cf
  bool v12; // zf
  hk1AxisSweep::AabbInt *v13; // rax
  hk1AxisSweep::AabbInt *v14; // rcx
  hk1AxisSweep::IteratorAB v16; // [rsp+20h] [rbp-38h]
  hkKeyPair pair; // [rsp+78h] [rbp+20h]

  v5 = faceAabbsA->m_data;
  v6 = edgeAabbsB->m_data;
  v7 = result;
  v16.m_numA = faceAabbsA->m_size - 4;
  v8 = filter;
  v9 = this;
  v16.m_numB = edgeAabbsB->m_size - 4;
  v10 = v6->m_min[0];
  v16.m_pa = v5;
  v11 = v5->m_min[0] < v10;
  v12 = v5->m_min[0] == v10;
  v16.m_pb = v6;
  v16.m_aIsBigger = !v11 && !v12;
  if ( v11 || v12 )
  {
    v16.m_currentPtr = v5;
    v5 = v6;
  }
  else
  {
    v16.m_currentPtr = v6;
  }
  v16.m_potentialPtr = v5 - 1;
  while ( 1 )
  {
    hk1AxisSweep::IteratorAB::next(&v16);
    if ( v16.m_numA <= 0 || v16.m_numB <= 0 )
      break;
    if ( v16.m_aIsBigger )
    {
      v13 = v16.m_potentialPtr;
      v14 = v16.m_pb;
    }
    else
    {
      v13 = v16.m_pa;
      v14 = v16.m_potentialPtr;
    }
    pair.m_keyA = *(_DWORD *)v13->m_expansionMin;
    pair.m_keyB = *(_DWORD *)v14->m_expansionMin;
    hkaiBooleanOperation::_classifyFaceAEdgeB(v9, (hkResult *)&edgeAabbsB, &pair, v8);
    if ( (_DWORD)edgeAabbsB )
    {
      v7->m_enum = 1;
      return v7;
    }
  }
  v7->m_enum = 0;
  return v7;
}

// File Line: 728
// RVA: 0xBA2390
hkResult *__fastcall hkaiBooleanOperation::_classifyEdgeAFaceB(hkaiBooleanOperation *this, hkResult *result, hkKeyPair *pair, hkaiBooleanFilter *filter)
{
  hkaiEdgeGeometry::Edge *const **v4; // rax
  __int64 v5; // r10
  unsigned int v6; // er13
  hkaiEdgeGeometry::Edge **v7; // r14
  hkaiBooleanOperation *v8; // rsi
  hkaiEdgeGeometry::Edge *const *v9; // rbp
  hkaiEdgeGeometry::Edge *v10; // r15
  hkaiBooleanFilter *v11; // r12
  hkResult *v12; // rdi
  hkaiEdgeGeometry::Edge **v13; // rbx
  int v14; // er15
  hkaiEdgeGeometry *v15; // rcx
  __int64 v16; // rax
  hkaiEdgeGeometry::Edge *const **v17; // rcx
  hkaiEdgeGeometry::Edge *v18; // rbp
  unsigned int v19; // er9
  int count; // er15
  __int64 index; // rbx
  unsigned int *v22; // r8
  unsigned __int64 v23; // rbx
  unsigned __int64 v24; // r13
  int v25; // er9
  hkArray<hkVector4f,hkContainerHeapAllocator> *v26; // rsi
  int v27; // er9
  int v28; // eax
  int v29; // eax
  int v31; // [rsp+30h] [rbp-88h]
  hkResult v32; // [rsp+34h] [rbp-84h]
  int v33; // [rsp+38h] [rbp-80h]
  unsigned int v34; // [rsp+3Ch] [rbp-7Ch]
  hkResult v35[2]; // [rsp+40h] [rbp-78h]
  hkResult v36[2]; // [rsp+48h] [rbp-70h]
  hkResult resulta; // [rsp+50h] [rbp-68h]
  __int64 v38; // [rsp+58h] [rbp-60h]
  hkaiEdgeGeometry::Edge **v39; // [rsp+60h] [rbp-58h]
  hkVector4f res; // [rsp+70h] [rbp-48h]
  unsigned int a; // [rsp+C0h] [rbp+8h]
  int v42; // [rsp+D0h] [rbp+18h]

  v4 = this->m_a.m_uniqueEdges.m_startUniqueEdge.m_data;
  v5 = (signed int)pair->m_keyA;
  v6 = pair->m_keyB;
  v7 = (hkaiEdgeGeometry::Edge **)v4[v5];
  v8 = this;
  v9 = v4[v5 + 1];
  v10 = *v7;
  v11 = filter;
  v12 = result;
  v34 = pair->m_keyB;
  v13 = v7;
  *(_QWORD *)&v36[0].m_enum = v10;
  *(_QWORD *)&v35[0].m_enum = 8 * v5 + 8;
  if ( v7 != v9 )
  {
    while ( !v11->vfptr->canFacesIntersect(v11, (*v13)->m_face, v6) )
    {
      ++v13;
      if ( v13 == v9 )
        goto LABEL_28;
    }
    v14 = hkaiBooleanOperation::_x12(v8, v10, v6, &res);
    v42 = v14;
    if ( v14 )
    {
      v15 = v8->m_a.m_geometry;
      a = v8->m_intersectVertices.m_size + v8->m_intersectBase;
      v33 = **(_DWORD **)&v36[0].m_enum;
      v31 = 0;
      v16 = (__int64)v15->m_edges.m_data;
      v17 = v8->m_a.m_uniqueEdges.m_startUniqueEdge.m_data;
      v38 = v16;
      v39 = *(hkaiEdgeGeometry::Edge ***)((char *)v17 + *(_QWORD *)&v35[0].m_enum);
      if ( v7 != v39 )
      {
        do
        {
          v18 = *v7;
          if ( v11->vfptr->canFacesIntersect(v11, (*v7)->m_face, v6) )
          {
            v19 = a;
            ++v31;
            count = -v14;
            index = ((signed __int64)v18 - v38) >> 4;
            v22 = &v8->m_edgeAIntersected.m_storage.m_words.m_data[(signed __int64)(signed int)index >> 5];
            *v22 |= 1 << (index & 0x1F);
            hkaiBooleanOperation::_addStartEndVertices(v8, &resulta, index, v19, index, count);
            if ( resulta.m_enum )
              goto LABEL_23;
            hkaiBooleanOperation::_addStartEndVertices(v8, v35, index, a, index, v42);
            if ( v35[0].m_enum )
              goto LABEL_23;
            v32.m_enum = 0;
            v23 = v6 | ((unsigned __int64)v18->m_face << 32);
            LODWORD(v24) = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                             (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v8->m_faceFaceFeatureMap.m_map.m_elem,
                             v23,
                             0xFFFFFFFFFFFFFFFFui64);
            if ( (v24 & 0x80000000) != 0i64 )
            {
              v24 = (signed int)v8->m_faceFaceFeatureCount;
              v8->m_faceFaceFeatureCount = v24 + 1;
              hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::tryInsert(
                (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v8->m_faceFaceFeatureMap.m_map.m_elem,
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                v23,
                v24,
                &v32);
            }
            if ( v32.m_enum )
              goto LABEL_23;
            if ( v33 == v18->m_a )
              count = v42;
            hkaiBooleanOperation::_addStartEndVertices(v8, v36, v24, a, v18->m_face, -count);
            if ( v36[0].m_enum )
              goto LABEL_23;
            v6 = v34;
            v14 = v42;
          }
          ++v7;
        }
        while ( v7 != v39 );
        if ( !v31 )
          goto LABEL_28;
        v25 = v8->m_intersectVertices.m_size;
        v26 = &v8->m_intersectVertices;
        v27 = v25 + 16;
        v28 = v26->m_capacityAndFlags & 0x3FFFFFFF;
        if ( v28 >= v27 )
        {
          a = 0;
        }
        else
        {
          v29 = 2 * v28;
          if ( v27 < v29 )
            v27 = v29;
          hkArrayUtil::_reserve(
            (hkResult *)&a,
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            v26,
            v27,
            16);
          if ( a )
          {
LABEL_23:
            v12->m_enum = 1;
            return v12;
          }
        }
        if ( v26->m_size == (v26->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v26, 16);
        v26->m_data[v26->m_size++] = (hkVector4f)res.m_quad;
      }
    }
  }
LABEL_28:
  v12->m_enum = 0;
  return v12;
}

// File Line: 831
// RVA: 0xBA2100
hkResult *__fastcall hkaiBooleanOperation::_classifyFaceAEdgeB(hkaiBooleanOperation *this, hkResult *result, hkKeyPair *pair, hkaiBooleanFilter *filter)
{
  hkaiEdgeGeometry::Edge *const **v4; // rax
  __int64 v5; // r10
  __int64 v6; // r15
  hkaiEdgeGeometry::Edge **v7; // rdi
  signed __int64 v8; // r13
  hkaiBooleanOperation *v9; // rbp
  hkaiEdgeGeometry::Edge **v10; // r14
  hkaiBooleanFilter *v11; // r12
  hkResult *v12; // rsi
  hkaiEdgeGeometry::Edge *const *v13; // rbx
  int v15; // eax
  hkaiEdgeGeometry::Edge *const **v16; // rcx
  hkaiEdgeGeometry::Edge *v17; // rbx
  unsigned __int64 v18; // r14
  unsigned __int64 v19; // r13
  int count; // eax
  int v21; // er9
  int v22; // eax
  int v23; // eax
  int v24; // [rsp+30h] [rbp-68h]
  int a; // [rsp+34h] [rbp-64h]
  hkResult resulta; // [rsp+38h] [rbp-60h]
  hkaiEdgeGeometry::Edge *edgeB; // [rsp+40h] [rbp-58h]
  hkaiEdgeGeometry::Edge **v28; // [rsp+48h] [rbp-50h]
  hkVector4f res; // [rsp+50h] [rbp-48h]
  hkResult v30; // [rsp+A0h] [rbp+8h]
  hkResult v31; // [rsp+B0h] [rbp+18h]

  v4 = this->m_b.m_uniqueEdges.m_startUniqueEdge.m_data;
  v5 = (signed int)pair->m_keyB;
  v6 = pair->m_keyA;
  v7 = (hkaiEdgeGeometry::Edge **)v4[v5];
  v8 = 8 * v5 + 8;
  v9 = this;
  v10 = *(hkaiEdgeGeometry::Edge ***)((char *)v4 + v8);
  v11 = filter;
  v12 = result;
  v13 = v4[v5];
  edgeB = *v7;
  if ( v7 == v10 )
  {
LABEL_4:
    v12->m_enum = 0;
  }
  else
  {
    while ( !v11->vfptr->canFacesIntersect(v11, v6, (*v13)->m_face) )
    {
      ++v13;
      if ( v13 == v10 )
        goto LABEL_4;
    }
    v24 = hkaiBooleanOperation::_x21(v9, v6, edgeB, &res);
    if ( v24 )
    {
      v15 = v9->m_intersectBase;
      v16 = v9->m_b.m_uniqueEdges.m_startUniqueEdge.m_data;
      v30.m_enum = 0;
      a = v9->m_intersectVertices.m_size + v15;
      v28 = *(hkaiEdgeGeometry::Edge ***)((char *)v16 + v8);
      if ( v7 != v28 )
      {
        do
        {
          v17 = *v7;
          if ( v11->vfptr->canFacesIntersect(v11, v6, (*v7)->m_face) )
          {
            ++v30.m_enum;
            v31.m_enum = 0;
            v18 = v17->m_face | (unsigned __int64)(v6 << 32);
            LODWORD(v19) = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                             (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v9->m_faceFaceFeatureMap.m_map.m_elem,
                             v18,
                             0xFFFFFFFFFFFFFFFFui64);
            if ( (v19 & 0x80000000) != 0i64 )
            {
              v19 = (signed int)v9->m_faceFaceFeatureCount;
              v9->m_faceFaceFeatureCount = v19 + 1;
              hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::tryInsert(
                (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v9->m_faceFaceFeatureMap.m_map.m_elem,
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                v18,
                v19,
                &v31);
            }
            if ( v31.m_enum )
              goto LABEL_21;
            count = v24;
            if ( edgeB->m_a != v17->m_a )
              count = -v24;
            hkaiBooleanOperation::_addStartEndVertices(v9, &resulta, v19, a, v6, count);
            if ( resulta.m_enum )
              goto LABEL_21;
          }
          ++v7;
        }
        while ( v7 != v28 );
        if ( v30.m_enum == HK_SUCCESS )
          goto LABEL_26;
        v21 = v9->m_intersectVertices.m_size + 16;
        v22 = v9->m_intersectVertices.m_capacityAndFlags & 0x3FFFFFFF;
        if ( v22 >= v21 )
        {
          v30.m_enum = 0;
        }
        else
        {
          v23 = 2 * v22;
          if ( v21 < v23 )
            v21 = v23;
          hkArrayUtil::_reserve(
            &v30,
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            &v9->m_intersectVertices,
            v21,
            16);
          if ( v30.m_enum )
          {
LABEL_21:
            v12->m_enum = 1;
            return v12;
          }
        }
        if ( v9->m_intersectVertices.m_size == (v9->m_intersectVertices.m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            &v9->m_intersectVertices,
            16);
        v9->m_intersectVertices.m_data[v9->m_intersectVertices.m_size++] = (hkVector4f)res.m_quad;
      }
    }
LABEL_26:
    v12->m_enum = 0;
  }
  return v12;
}

// File Line: 915
// RVA: 0xBA0BE0
hkResult *__fastcall hkaiBooleanOperation::_addCompleteEdges(hkaiBooleanOperation *this, hkResult *result, hkaiBooleanFilter *filter, hkaiEdgeGeometry *geomOut)
{
  hkaiEdgeGeometry *v4; // rax
  unsigned int *v5; // r8
  hkaiBooleanOperation *v6; // rsi
  int v7; // er12
  hkResult *v8; // r13
  char v9; // cl
  int v10; // er14
  hkaiEdgeGeometry *v11; // rbx
  int v12; // edx
  __int64 v13; // rcx
  __m128i v14; // xmm2
  __m128i v15; // xmm3
  __m128i v16; // xmm4
  int v17; // eax
  __m128i v18; // xmm0
  __m128i v19; // xmm1
  __m128i v20; // xmm0
  __m128i v21; // xmm1
  int v22; // edi
  int v23; // eax
  int v24; // er9
  int v25; // eax
  hkArray<hkaiBooleanOperation::SortVertex,hkContainerHeapAllocator> *v26; // r15
  int v27; // er9
  int v28; // eax
  int v29; // eax
  hkArray<hkaiBooleanOperation::SortVertex,hkContainerHeapAllocator> *v30; // rbp
  int v31; // er9
  int v32; // eax
  int v33; // eax
  hkResultEnum v34; // eax
  __int64 v35; // r14
  int v36; // er9
  int v37; // eax
  int v38; // eax
  signed __int64 v39; // r14
  hkaiEdgeGeometry::Edge *v40; // rdi
  int v41; // ebx
  int v42; // er13
  __int64 v43; // r12
  hkaiBooleanOperation::SortVertex *v44; // rsi
  hkaiBooleanOperation::SortVertex *v45; // rcx
  hkResult resulta; // [rsp+30h] [rbp-58h]
  hkResult v48; // [rsp+34h] [rbp-54h]
  int v49; // [rsp+38h] [rbp-50h]
  hkResult v50; // [rsp+3Ch] [rbp-4Ch]
  hkArray<hkaiEdgeGeometry::Edge,hkContainerHeapAllocator> *v51; // [rsp+40h] [rbp-48h]
  hkaiBooleanOperation *v52; // [rsp+90h] [rbp+8h]
  hkResult *v53; // [rsp+98h] [rbp+10h]
  hkResult v54; // [rsp+A8h] [rbp+20h]

  v53 = result;
  v52 = this;
  v4 = this->m_a.m_geometry;
  v5 = this->m_edgeAIntersected.m_storage.m_words.m_data;
  v6 = this;
  v7 = v4->m_edges.m_size;
  v8 = result;
  v9 = (this->m_edgeAIntersected.m_storage.m_numBits - 1) & 0x1F;
  v51 = &v4->m_edges;
  LODWORD(v4) = v6->m_edgeAIntersected.m_storage.m_words.m_size;
  v10 = 0;
  v11 = geomOut;
  v49 = v7;
  v12 = 2 * ~(-1 << v9) | 1;
  LODWORD(v4) = (_DWORD)v4 - 1;
  v13 = (signed int)v4;
  if ( (signed int)v4 >= 0 )
  {
    v14 = _mm_load_si128((const __m128i *)&_xmm);
    v15 = _mm_load_si128((const __m128i *)&_xmm);
    v16 = _mm_load_si128((const __m128i *)&_xmm);
    do
    {
      v17 = v12 & v5[v13];
      v12 = -1;
      v18 = _mm_cvtsi32_si128(v17);
      v19 = _mm_add_epi8(_mm_and_si128(_mm_srli_epi16(v18, 1u), v14), _mm_and_si128(v18, v14));
      v20 = _mm_add_epi8(_mm_and_si128(_mm_srli_epi16(v19, 2u), v15), _mm_and_si128(v19, v15));
      v21 = _mm_sad_epu8(_mm_and_si128(_mm_add_epi8(_mm_srli_epi16(v20, 4u), v20), v16), (__m128i)0i64);
      v10 += _mm_cvtsi128_si32(_mm_add_epi32(_mm_shuffle_epi32(v21, 78), v21));
      --v13;
    }
    while ( v13 >= 0 );
  }
  v22 = v7 - v10;
  v23 = geomOut->m_edges.m_capacityAndFlags & 0x3FFFFFFF;
  v24 = v7 - v10 + geomOut->m_edges.m_size;
  if ( v23 >= v24 )
  {
    resulta.m_enum = 0;
  }
  else
  {
    v25 = 2 * v23;
    if ( v24 < v25 )
      v24 = v25;
    hkArrayUtil::_reserve(
      &resulta,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v11->m_edges,
      v24,
      16);
  }
  v26 = &v6->m_startVertices;
  v27 = v10 + v6->m_startVertices.m_size;
  v28 = v6->m_startVertices.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v28 >= v27 )
  {
    v48.m_enum = 0;
  }
  else
  {
    v29 = 2 * v28;
    if ( v27 < v29 )
      v27 = v29;
    hkArrayUtil::_reserve(
      &v48,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v6->m_startVertices,
      v27,
      16);
  }
  v30 = &v6->m_endVertices;
  v31 = v10 + v6->m_endVertices.m_size;
  v32 = v6->m_endVertices.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v32 >= v31 )
  {
    v34 = 0;
    v54.m_enum = 0;
  }
  else
  {
    v33 = 2 * v32;
    if ( v31 < v33 )
      v31 = v33;
    hkArrayUtil::_reserve(
      &v54,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v6->m_endVertices,
      v31,
      16);
    v34 = v54.m_enum;
  }
  if ( resulta.m_enum || v48.m_enum || v34 )
  {
    v8->m_enum = 1;
  }
  else
  {
    v35 = v11->m_edges.m_size;
    v36 = v35 + v22;
    v37 = v11->m_edges.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v37 < (signed int)v35 + v22 )
    {
      v38 = 2 * v37;
      if ( v36 < v38 )
        v36 = v38;
      hkArrayUtil::_reserve(&v50, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v11->m_edges, v36, 16);
    }
    v11->m_edges.m_size += v22;
    v39 = (signed __int64)&v11->m_edges.m_data[v35];
    v40 = v51->m_data;
    v41 = 0;
    if ( v7 > 0 )
    {
      v42 = v49;
      v43 = 0i64;
      do
      {
        if ( (v6->m_edgeAIntersected.m_storage.m_words.m_data[v43 >> 5] >> (v41 & 0x1F)) & 1 )
        {
          if ( v30->m_size == (v30->m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v30, 16);
          v44 = &v30->m_data[v30->m_size++];
          if ( v26->m_size == (v26->m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v26, 16);
          v45 = &v26->m_data[v26->m_size++];
          v45->m_feature = v41;
          v45->m_index = v41;
          v45->m_vertexIndex = v40->m_a;
          v44->m_feature = v41;
          v44->m_index = v41;
          v44->m_vertexIndex = v40->m_b;
          v6 = v52;
        }
        else
        {
          v39 += 16i64;
          *(_DWORD *)(v39 - 16) = v40->m_a;
          *(_DWORD *)(v39 - 12) = v40->m_b;
          *(_DWORD *)(v39 - 8) = v40->m_face;
          *(_DWORD *)(v39 - 4) = v40->m_data;
        }
        ++v41;
        ++v43;
        ++v40;
      }
      while ( v41 < v42 );
      v8 = v53;
    }
    v8->m_enum = 0;
  }
  return v8;
}

// File Line: 972
// RVA: 0xBA3D90
bool __fastcall hkaiBooleanOperation_orderFeatures(hkaiBooleanOperation::SortVertex *a, hkaiBooleanOperation::SortVertex *b)
{
  bool result; // al

  if ( a->m_feature == b->m_feature )
    result = a->m_index < b->m_index;
  else
    result = a->m_feature < b->m_feature;
  return result;
}

// File Line: 981
// RVA: 0xBA3DC0
bool __fastcall hkaiBooleanOperation_compareDist(hkaiBooleanOperation::SortVertex *a, hkaiBooleanOperation::SortVertex *b)
{
  return a->m_dist < b->m_dist;
}

// File Line: 1011
// RVA: 0xBA0F60
hkResult *__fastcall hkaiBooleanOperation::_addPartialEdges(hkaiBooleanOperation *this, hkResult *result, hkArray<hkVector4f,hkContainerHeapAllocator> *faceNormals, hkaiEdgeGeometry *geomOut, hkaiBooleanFaceFaceIntersects *intersects)
{
  int v5; // er8
  hkaiEdgeGeometry *v6; // r14
  hkResult *v7; // r12
  hkaiBooleanOperation *v8; // r13
  signed int v9; // er8
  int v10; // ebx
  int v11; // er9
  __int64 v12; // r8
  int v13; // edx
  __int64 v14; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v15; // rax
  int v16; // er9
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v17; // rax
  unsigned __int64 v18; // r8
  char *v19; // rdx
  unsigned __int64 v20; // rax
  __int64 v21; // r8
  int v22; // edx
  __int64 v23; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v24; // rax
  hkArray<hkaiBooleanOperation::SortVertex,hkContainerHeapAllocator> *v25; // rbx
  int v26; // er9
  int v27; // eax
  int v28; // eax
  int v29; // er8
  int v31; // eax
  hkArray<hkaiEdgeGeometry::Edge,hkContainerHeapAllocator> *v32; // r9
  __int64 v33; // rcx
  hkaiBooleanOperation::SortVertex *v34; // rcx
  hkaiBooleanOperation::SortVertex *v35; // rbx
  hkaiBooleanOperation::SortVertex *v36; // rsi
  __int64 v37; // rcx
  unsigned int v38; // edi
  hkaiBooleanOperation::SortVertex *v39; // rax
  unsigned int v40; // er15
  signed __int64 v41; // r14
  signed int *v42; // r13
  int v43; // er9
  int v44; // er9
  int v45; // eax
  int v46; // eax
  __int64 v47; // r12
  int v48; // er9
  int v49; // eax
  int v50; // eax
  unsigned int *v51; // r12
  int v52; // er13
  unsigned int v53; // eax
  int v54; // er8
  unsigned int v55; // eax
  hkaiEdgeGeometry *v56; // rdi
  signed __int64 v57; // r10
  hkVector4f *v58; // rdx
  __m128 v59; // xmm0
  __m128 v60; // xmm3
  signed __int64 v61; // rcx
  signed __int64 v62; // r8
  __int64 v63; // rax
  __m128 v64; // xmm3
  int v65; // er9
  signed __int64 v66; // r11
  signed __int64 v67; // rcx
  signed __int64 v68; // rdx
  __m128 v69; // xmm2
  __m128 v70; // xmm2
  int v71; // er8
  int *v72; // rcx
  __int64 v73; // rdx
  int v74; // eax
  unsigned int v75; // eax
  __int64 v76; // rdi
  hkVector4f *v77; // rdx
  signed __int64 v78; // r10
  _DWORD *v79; // r12
  __m128 v80; // xmm0
  __m128 v81; // xmm3
  signed __int64 v82; // rcx
  signed __int64 v83; // r8
  __int64 v84; // rax
  __m128 v85; // xmm3
  int v86; // er9
  signed __int64 v87; // r11
  signed __int64 v88; // rcx
  signed __int64 v89; // rdx
  __m128 v90; // xmm2
  __m128 v91; // xmm2
  signed __int64 v92; // rax
  hkaiBooleanOperation::SortVertex *v93; // r10
  unsigned int v94; // ecx
  int v95; // edx
  unsigned int v96; // er8
  float v97; // er9
  int v98; // er8
  signed __int64 v99; // r14
  signed __int64 v100; // rcx
  hkaiBooleanOperation::SortVertex *v101; // r10
  unsigned int v102; // ecx
  int v103; // edx
  unsigned int v104; // er8
  float v105; // er9
  _DWORD *v106; // r14
  int v107; // er9
  int v108; // eax
  int v109; // eax
  __int64 v110; // rdi
  int v111; // er9
  int v112; // eax
  int v113; // eax
  unsigned int *v114; // rcx
  __int64 v115; // rdx
  unsigned int v116; // eax
  hkResult *v117; // rbx
  int v118; // er8
  hkResult v119; // [rsp+30h] [rbp-31h]
  int v120; // [rsp+34h] [rbp-2Dh]
  hkResult v121; // [rsp+38h] [rbp-29h]
  hkResult v122; // [rsp+3Ch] [rbp-25h]
  hkResult resulta; // [rsp+40h] [rbp-21h]
  __int64 v124; // [rsp+48h] [rbp-19h]
  void *v125; // [rsp+50h] [rbp-11h]
  char *array; // [rsp+58h] [rbp-9h]
  int v127; // [rsp+60h] [rbp-1h]
  int v128; // [rsp+64h] [rbp+3h]
  hkaiBooleanOperation *v129; // [rsp+C0h] [rbp+5Fh]
  hkResult *v130; // [rsp+C8h] [rbp+67h]
  hkArray<hkVector4f,hkContainerHeapAllocator> *faceNormalsa; // [rsp+D0h] [rbp+6Fh]
  hkaiEdgeGeometry *v132; // [rsp+D8h] [rbp+77h]

  v132 = geomOut;
  faceNormalsa = faceNormals;
  v130 = result;
  v129 = this;
  v5 = this->m_startVertices.m_size;
  v6 = geomOut;
  v7 = result;
  v8 = this;
  if ( v5 > 1 )
    hkAlgorithm::quickSortRecursive<hkaiBooleanOperation::SortVertex,bool (*)(hkaiBooleanOperation::SortVertex const &,hkaiBooleanOperation::SortVertex const &)>(
      this->m_startVertices.m_data,
      0,
      v5 - 1,
      hkaiBooleanOperation_orderFeatures);
  v9 = v8->m_endVertices.m_size;
  if ( v9 > 1 )
    hkAlgorithm::quickSortRecursive<hkaiBooleanOperation::SortVertex,bool (*)(hkaiBooleanOperation::SortVertex const &,hkaiBooleanOperation::SortVertex const &)>(
      v8->m_endVertices.m_data,
      0,
      v9 - 1,
      hkaiBooleanOperation_orderFeatures);
  v128 = 2147483648;
  array = 0i64;
  v127 = 0;
  if ( intersects )
  {
    v10 = v8->m_faceFaceFeatureMap.m_map.m_numElems & 0x7FFFFFFF;
    if ( v10 > 0 )
    {
      v11 = v8->m_faceFaceFeatureMap.m_map.m_numElems & 0x7FFFFFFF;
      if ( v10 < 0 )
        v11 = 0;
      hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v11, 8);
    }
    v12 = v8->m_faceFaceFeatureMap.m_map.m_hashMod;
    v127 = v10;
    v13 = 0;
    v14 = 0i64;
    if ( v12 >= 0 )
    {
      v15 = v8->m_faceFaceFeatureMap.m_map.m_elem;
      do
      {
        if ( v15->key != -1i64 )
          break;
        ++v14;
        ++v13;
        ++v15;
      }
      while ( v14 <= v12 );
    }
    v16 = v13;
    if ( v13 <= v8->m_faceFaceFeatureMap.m_map.m_hashMod )
    {
      do
      {
        v17 = v8->m_faceFaceFeatureMap.m_map.m_elem;
        v18 = v17[v16].key;
        v19 = &array[8 * (LODWORD(v17[v16].val) - v8->m_faceFaceFeatureBase)];
        v20 = v17[v16].key >> 32;
        *((_DWORD *)v19 + 1) = v18;
        *(_DWORD *)v19 = v20;
        v21 = v8->m_faceFaceFeatureMap.m_map.m_hashMod;
        v22 = v16 + 1;
        v23 = v16 + 1;
        if ( v23 <= v21 )
        {
          v24 = &v8->m_faceFaceFeatureMap.m_map.m_elem[v22];
          do
          {
            if ( v24->key != -1i64 )
              break;
            ++v23;
            ++v22;
            ++v24;
          }
          while ( v23 <= v21 );
        }
        v16 = v22;
      }
      while ( v22 <= v8->m_faceFaceFeatureMap.m_map.m_hashMod );
    }
  }
  v25 = &v8->m_startVertices;
  v26 = v8->m_startVertices.m_size + 1;
  v27 = v8->m_startVertices.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v27 >= v26 )
  {
    v119.m_enum = 0;
  }
  else
  {
    v28 = 2 * v27;
    if ( v26 < v28 )
      v26 = v28;
    hkArrayUtil::_reserve(
      &v119,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v8->m_startVertices,
      v26,
      16);
    if ( v119.m_enum )
    {
      v29 = v128;
      v7->m_enum = 1;
      v127 = 0;
      if ( v29 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          array,
          8 * v29);
      return v7;
    }
  }
  if ( v8->m_startVertices.m_size == (v8->m_startVertices.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v8->m_startVertices, 16);
  v31 = v8->m_startVertices.m_size;
  v32 = &v8->m_faceFaceEdges;
  v33 = v8->m_startVertices.m_size;
  v125 = &v8->m_faceFaceEdges;
  v34 = &v25->m_data[v33];
  v8->m_startVertices.m_size = v31 + 1;
  v34->m_feature = -1;
  --v8->m_startVertices.m_size;
  v35 = v25->m_data;
  v36 = v8->m_endVertices.m_data;
  v37 = (__int64)v8->m_a.m_geometry->m_edges.m_data;
  v8->m_faceFaceEdges.m_size = 0;
  v38 = v35->m_feature;
  v124 = v37;
  if ( v38 != -1 )
  {
    while ( 1 )
    {
      v39 = v35;
      v40 = 0;
      v41 = 0i64;
      do
      {
        ++v39;
        ++v40;
        ++v41;
      }
      while ( v39->m_feature == v38 );
      if ( v38 < v8->m_faceFaceFeatureBase )
      {
        if ( v38 >= v8->m_edgeBFeatureBase )
          goto LABEL_62;
        v76 = (__int64)v132;
        v77 = v132->m_vertices.m_data;
        v78 = (signed __int64)&v36->m_vertexIndex;
        v79 = (_DWORD *)(v37 + 16i64 * v35->m_index);
        v80 = v77[v35->m_vertexIndex].m_quad;
        v81 = v77[v36->m_vertexIndex].m_quad;
        if ( v41 > 1 )
        {
          v82 = (signed __int64)&v36[1].m_vertexIndex;
          v83 = v41 - 1;
          do
          {
            v84 = *(signed int *)(v82 + (char *)v35 - (char *)v36);
            v82 += 16i64;
            v80 = _mm_add_ps(v80, v77[v84].m_quad);
            v81 = _mm_add_ps(v81, v77[*(signed int *)(v82 - 16)].m_quad);
            --v83;
          }
          while ( v83 );
        }
        v85 = _mm_sub_ps(v81, v80);
        v86 = 0;
        if ( v41 > 0 )
        {
          v87 = v41;
          do
          {
            v88 = 2i64 * *(signed int *)(v78 + (char *)v35 - (char *)v36);
            v89 = v86++;
            v78 += 16i64;
            v90 = _mm_mul_ps(*(__m128 *)(*(_QWORD *)(v76 + 48) + 8 * v88), v85);
            v35[v89].m_dist = (float)(COERCE_FLOAT(_mm_shuffle_ps(v90, v90, 85))
                                    + COERCE_FLOAT(_mm_shuffle_ps(v90, v90, 0)))
                            + COERCE_FLOAT(_mm_shuffle_ps(v90, v90, 170));
            v91 = _mm_mul_ps(*(__m128 *)(*(_QWORD *)(v76 + 48) + 16i64 * *(signed int *)(v78 - 16)), v85);
            v36[v89].m_dist = (float)(COERCE_FLOAT(_mm_shuffle_ps(v91, v91, 85))
                                    + COERCE_FLOAT(_mm_shuffle_ps(v91, v91, 0)))
                            + COERCE_FLOAT(_mm_shuffle_ps(v91, v91, 170));
            --v87;
          }
          while ( v87 );
        }
        if ( v41 > 1 )
        {
          hkAlgorithm::quickSortRecursive<hkaiBooleanOperation::SortVertex,bool (*)(hkaiBooleanOperation::SortVertex const &,hkaiBooleanOperation::SortVertex const &)>(
            v35,
            0,
            v40 - 1,
            hkaiBooleanOperation_compareDist);
          hkAlgorithm::quickSortRecursive<hkaiBooleanOperation::SortVertex,bool (*)(hkaiBooleanOperation::SortVertex const &,hkaiBooleanOperation::SortVertex const &)>(
            v36,
            0,
            v40 - 1,
            hkaiBooleanOperation_compareDist);
          v76 = (__int64)v132;
        }
        if ( v35->m_vertexIndex != *v79 )
        {
          v92 = 1i64;
          if ( v41 > 1 )
          {
            v93 = v35 + 1;
            while ( v93->m_vertexIndex != *v79 )
            {
              ++v92;
              ++v93;
              if ( v92 >= v41 )
                goto LABEL_82;
            }
            v94 = v93->m_feature;
            v95 = v93->m_index;
            v96 = v93->m_vertexIndex;
            v97 = v93->m_dist;
            v93->m_feature = v35->m_feature;
            v93->m_index = v35->m_index;
            v93->m_vertexIndex = v35->m_vertexIndex;
            v93->m_dist = v35->m_dist;
            v35->m_feature = v94;
            v35->m_index = v95;
            v35->m_vertexIndex = v96;
            v35->m_dist = v97;
          }
        }
LABEL_82:
        v98 = v79[1];
        v99 = v41;
        if ( *((_DWORD *)&v36[v99] - 2) != v98 )
        {
          v100 = 0i64;
          if ( (signed int)(v40 - 1) > 0 )
          {
            v101 = v36;
            while ( v101->m_vertexIndex != v98 )
            {
              ++v100;
              ++v101;
              if ( v100 >= (signed int)(v40 - 1) )
                goto LABEL_89;
            }
            v102 = v101->m_feature;
            v103 = v101->m_index;
            v104 = v101->m_vertexIndex;
            v105 = v101->m_dist;
            v101->m_feature = v36[v99 - 1].m_feature;
            v101->m_index = *((_DWORD *)&v36[v99] - 3);
            v101->m_vertexIndex = *((_DWORD *)&v36[v99] - 2);
            v101->m_dist = *((float *)&v36[v99] - 1);
            v36[v99 - 1].m_feature = v102;
            *((_DWORD *)&v36[v99] - 3) = v103;
            *((_DWORD *)&v36[v99] - 2) = v104;
            *((float *)&v36[v99] - 1) = v105;
          }
        }
LABEL_89:
        v106 = (_DWORD *)(v76 + 16);
        v107 = v40 + *(_DWORD *)(v76 + 24);
        v108 = *(_DWORD *)(v76 + 28) & 0x3FFFFFFF;
        if ( v108 >= v107 )
        {
          v121.m_enum = 0;
        }
        else
        {
          v109 = 2 * v108;
          if ( v107 < v109 )
            v107 = v109;
          hkArrayUtil::_reserve(
            &v121,
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            (void *)(v76 + 16),
            v107,
            16);
          if ( v121.m_enum )
          {
            v117 = v130;
            v118 = v128;
            v130->m_enum = 1;
            v127 = 0;
            if ( v118 >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                array,
                8 * v118);
            return v117;
          }
        }
        v110 = *(signed int *)(v76 + 24);
        v111 = v110 + v40;
        v112 = v106[3] & 0x3FFFFFFF;
        if ( v112 >= (signed int)(v110 + v40) )
        {
          resulta.m_enum = 0;
        }
        else
        {
          v113 = 2 * v112;
          if ( v111 < v113 )
            v111 = v113;
          hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v106, v111, 16);
        }
        v106[2] += v40;
        v114 = (unsigned int *)(*(_QWORD *)v106 + 16 * v110);
        if ( (signed int)v40 > 0 )
        {
          v115 = v40;
          do
          {
            v116 = v35->m_vertexIndex;
            ++v35;
            ++v36;
            *v114 = v116;
            v114 += 4;
            *(v114 - 3) = v36[-1].m_vertexIndex;
            *(v114 - 2) = v79[2];
            *(v114 - 1) = v79[3];
            --v115;
          }
          while ( v115 );
        }
      }
      else
      {
        v42 = (signed int *)v125;
        v43 = *((_DWORD *)v125 + 2);
        v120 = v35->m_index;
        v44 = v40 + v43;
        v45 = *((_DWORD *)v125 + 3) & 0x3FFFFFFF;
        if ( v45 >= v44 )
        {
          v119.m_enum = 0;
        }
        else
        {
          v46 = 2 * v45;
          if ( v44 < v46 )
            v44 = v46;
          hkArrayUtil::_reserve(&v119, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v125, v44, 16);
          if ( v119.m_enum )
          {
            v7 = v130;
            v130->m_enum = 1;
            goto LABEL_109;
          }
        }
        v47 = v42[2];
        v48 = v47 + v40;
        v49 = v42[3] & 0x3FFFFFFF;
        if ( v49 >= (signed int)(v47 + v40) )
        {
          v122.m_enum = 0;
        }
        else
        {
          v50 = 2 * v49;
          if ( v48 < v50 )
            v48 = v50;
          hkArrayUtil::_reserve(&v122, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v42, v48, 16);
        }
        v42[2] += v40;
        v51 = (unsigned int *)(*(_QWORD *)v42 + 16 * v47);
        v52 = 0;
        if ( intersects )
          v52 = *(_DWORD *)&array[8 * (v38 - v129->m_faceFaceFeatureBase) + 4];
        if ( v41 == 1 )
        {
          v53 = v35->m_vertexIndex;
          v54 = v120;
          ++v35;
          *v51 = v53;
          v55 = v36->m_vertexIndex;
          v51[2] = v54;
          v51[3] = v52;
          ++v36;
          v51[1] = v55;
        }
        else
        {
          v56 = v132;
          v57 = (signed __int64)&v36->m_vertexIndex;
          v58 = v132->m_vertices.m_data;
          v59 = v58[v35->m_vertexIndex].m_quad;
          v60 = v58[v36->m_vertexIndex].m_quad;
          if ( v41 > 1 )
          {
            v61 = (signed __int64)&v36[1].m_vertexIndex;
            v62 = v41 - 1;
            do
            {
              v63 = *(signed int *)((char *)v35 - (char *)v36 + v61);
              v61 += 16i64;
              v59 = _mm_add_ps(v59, v58[v63].m_quad);
              v60 = _mm_add_ps(v60, v58[*(signed int *)(v61 - 16)].m_quad);
              --v62;
            }
            while ( v62 );
          }
          v64 = _mm_sub_ps(v60, v59);
          v65 = 0;
          if ( v41 > 0 )
          {
            v66 = v41;
            do
            {
              v67 = *(signed int *)(v57 + (char *)v35 - (char *)v36);
              v68 = v65++;
              v57 += 16i64;
              v69 = _mm_mul_ps(v56->m_vertices.m_data[v67].m_quad, v64);
              v35[v68].m_dist = (float)(COERCE_FLOAT(_mm_shuffle_ps(v69, v69, 85))
                                      + COERCE_FLOAT(_mm_shuffle_ps(v69, v69, 0)))
                              + COERCE_FLOAT(_mm_shuffle_ps(v69, v69, 170));
              v70 = _mm_mul_ps(v56->m_vertices.m_data[*(signed int *)(v57 - 16)].m_quad, v64);
              v36[v68].m_dist = (float)(COERCE_FLOAT(_mm_shuffle_ps(v70, v70, 85))
                                      + COERCE_FLOAT(_mm_shuffle_ps(v70, v70, 0)))
                              + COERCE_FLOAT(_mm_shuffle_ps(v70, v70, 170));
              --v66;
            }
            while ( v66 );
          }
          if ( v41 > 1 )
          {
            hkAlgorithm::quickSortRecursive<hkaiBooleanOperation::SortVertex,bool (*)(hkaiBooleanOperation::SortVertex const &,hkaiBooleanOperation::SortVertex const &)>(
              v35,
              0,
              v40 - 1,
              hkaiBooleanOperation_compareDist);
            hkAlgorithm::quickSortRecursive<hkaiBooleanOperation::SortVertex,bool (*)(hkaiBooleanOperation::SortVertex const &,hkaiBooleanOperation::SortVertex const &)>(
              v36,
              0,
              v40 - 1,
              hkaiBooleanOperation_compareDist);
          }
          if ( (signed int)v40 > 0 )
          {
            v71 = v120;
            v72 = (int *)(v51 + 2);
            v73 = v40;
            do
            {
              v74 = v35->m_vertexIndex;
              ++v35;
              ++v36;
              *(v72 - 2) = v74;
              v75 = v36[-1].m_vertexIndex;
              *v72 = v71;
              v72[1] = v52;
              *(v72 - 1) = v75;
              v72 += 4;
              --v73;
            }
            while ( v73 );
          }
        }
        v8 = v129;
      }
      v37 = v124;
LABEL_62:
      v38 = v35->m_feature;
      if ( v35->m_feature == -1 )
      {
        v6 = v132;
        v7 = v130;
        v32 = &v8->m_faceFaceEdges;
        break;
      }
    }
  }
  hkaiBooleanOperation::_addFaceFaceIntersections(v8, (hkResult *)&v129, faceNormalsa, v32, intersects, v6);
  if ( (_DWORD)v129 )
    v7->m_enum = 1;
  else
    v7->m_enum = 0;
LABEL_109:
  v127 = 0;
  if ( v128 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      8 * v128);
  return v7;
}

// File Line: 1214
// RVA: 0xBA2C00
__int64 __fastcall hkaiBooleanOperation::_linesIntersect(hkaiBooleanOperation *this, hkVector4f *points, hkVector4f *intersectPosition)
{
  __m128 v3; // xmm1
  __m128 v4; // xmm3
  __m128 v5; // xmm2
  hkVector4f *v6; // rdi
  hkVector4f *v7; // rbx
  int v8; // er8
  __int64 result; // rax
  hkaiBooleanOperation::ShadowResult v10; // [rsp+30h] [rbp-38h]

  v3 = points->m_quad;
  v4 = points[2].m_quad;
  v5 = points[3].m_quad;
  v6 = points;
  v7 = intersectPosition;
  v8 = 0;
  if ( ((_mm_movemask_ps(_mm_cmpeqps(points->m_quad, v5)) & 3) == 3) | ((_mm_movemask_ps(_mm_cmpeqps(points->m_quad, v4)) & 3) == 3)
    || (v3 = points[1].m_quad,
        LOBYTE(v8) = (_mm_movemask_ps(_mm_cmpeqps(points[1].m_quad, v5)) & 3) == 3,
        v8 | ((_mm_movemask_ps(_mm_cmpeqps(points[1].m_quad, v4)) & 3) == 3)) )
  {
    *v7 = (hkVector4f)v3;
    result = 1i64;
  }
  else
  {
    v10.m_shadower = 0i64;
    v10.m_shadowee = 0i64;
    if ( (unsigned int)hkaiBooleanOperation::_calculate2dLineIntersect(points, points + 1, points + 2, points + 3)
      || (result = hkaiBooleanOperation::_calculate2dLineIntersect(v6 + 2, v6 + 3, v6, v6 + 1), (_DWORD)result) )
    {
      result = 1i64;
      *v7 = v10.m_shadower;
    }
  }
  return result;
}

// File Line: 1269
// RVA: 0xBA3DE0
bool __fastcall hkaiBooleanOperation_orderEdgeEdgeIntersect(hkaiBooleanOperation::EdgeEdgeIntersect *a, hkaiBooleanOperation::EdgeEdgeIntersect *b)
{
  bool result; // al

  if ( a->m_edgeIndex == b->m_edgeIndex )
    result = a->m_dist < b->m_dist;
  else
    result = a->m_edgeIndex < b->m_edgeIndex;
  return result;
}

// File Line: 1278
// RVA: 0xBA3E10
hkVector4f *__fastcall hkaiBooleanOperation_faceSwizzle(hkVector4f *result, hkVector4f *v, const int majorAxis)
{
  __m128 v3; // xmm0
  hkVector4f *v4; // rax

  v3 = v->m_quad;
  v4 = result;
  if ( majorAxis )
  {
    if ( majorAxis == 1 )
    {
      result->m_quad = _mm_shuffle_ps(v3, v3, 216);
      return v4;
    }
  }
  else
  {
    v3 = _mm_shuffle_ps(v3, v3, 201);
  }
  *result = (hkVector4f)v3;
  return v4;
}

// File Line: 1290
// RVA: 0xBA3E40
hkVector4f *__fastcall hkaiBooleanOperation_faceDeswizzle(hkVector4f *result, hkVector4f *v, const int majorAxis)
{
  __m128 v3; // xmm0
  hkVector4f *v4; // rax

  v3 = v->m_quad;
  v4 = result;
  if ( majorAxis )
  {
    if ( majorAxis == 1 )
    {
      result->m_quad = _mm_shuffle_ps(v3, v3, 216);
      return v4;
    }
  }
  else
  {
    v3 = _mm_shuffle_ps(v3, v3, 210);
  }
  *result = (hkVector4f)v3;
  return v4;
}

// File Line: 1302
// RVA: 0xBA2D20
hkResult *__fastcall hkaiBooleanOperation::_addFaceIntersections(hkaiBooleanOperation *this, hkResult *result, hkVector4f *faceNormalIn, hkaiEdgeGeometry::Edge *edges, int numEdges, hkaiBooleanFaceFaceIntersects *intersects, hkaiEdgeGeometry *geomOut)
{
  unsigned int v7; // er12
  hkVector4f *v8; // rdi
  hkResult *v9; // r14
  hkaiEdgeGeometry::Edge *v10; // rbx
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // er9
  __int64 v16; // r13
  __m128 v17; // xmm3
  hkArray<hkaiEdgeGeometry::Edge,hkContainerHeapAllocator> *v18; // r15
  int v19; // esi
  int v20; // er9
  int v21; // er8
  int v22; // edi
  __m128 v23; // xmm6
  _QWORD *v24; // rsi
  __int64 v25; // r14
  hkVector4f v26; // xmm1
  signed __int64 v27; // rcx
  int v28; // eax
  int v29; // er9
  int v30; // eax
  int v31; // eax
  int v32; // er9
  int v33; // er8
  hk1AxisSweep::AabbInt *v34; // rdi
  hkResultEnum v35; // er13
  hkResultEnum v36; // esi
  int v37; // ebx
  signed __int64 v38; // rcx
  unsigned int v39; // er8
  hk1AxisSweep::AabbInt *v40; // rdx
  hkaiEdgeGeometry::Edge *v41; // r13
  int v42; // er14
  signed __int64 v43; // r9
  unsigned int v44; // er10
  __int64 v45; // rdx
  __int64 v46; // r8
  signed __int64 v47; // rax
  __m128 v48; // xmm1
  __m128 v49; // xmm0
  __m128 v50; // xmm9
  __m128 v51; // xmm0
  __m128 v52; // xmm9
  signed __int64 v53; // rax
  __int64 v54; // r9
  __m128 v55; // xmm2
  __m128 v56; // xmm9
  unsigned int v57; // ecx
  __m128 v58; // xmm8
  __m128 v59; // xmm0
  __m128 v60; // xmm7
  __m128 v61; // xmm0
  hkVector4f v62; // xmm6
  _DWORD *v63; // r14
  int v64; // eax
  int v65; // er9
  int v66; // eax
  int v67; // eax
  int v68; // er8
  hkResult *v69; // rbx
  _DWORD *v70; // rdx
  __m128 v71; // xmm7
  __m128 v72; // xmm2
  int v73; // er9
  int v74; // eax
  __m128 v75; // xmm7
  int v76; // eax
  __int64 v77; // r14
  int v78; // er9
  int v79; // eax
  int v80; // eax
  __int64 v81; // rax
  __m128 v82; // xmm2
  __m128 v83; // xmm2
  signed __int64 v84; // rdx
  __m128 v85; // xmm1
  __m128 v86; // xmm2
  __m128 v87; // xmm2
  __m128 v88; // xmm1
  signed __int64 v89; // rcx
  unsigned int v90; // er8
  hk1AxisSweep::AabbInt *v91; // rdx
  _DWORD *v92; // rbx
  int v93; // er9
  int v94; // eax
  int v95; // eax
  __int64 v96; // rdx
  hkaiBooleanOperation::EdgeEdgeIntersect *v97; // rcx
  signed int v98; // er8
  char *v99; // rbx
  int v100; // esi
  __int32 v101; // eax
  hkaiBooleanFaceFaceIntersects *v102; // r14
  hkResultEnum v103; // edi
  char *i; // rdi
  unsigned __int64 v105; // rdx
  unsigned __int64 v106; // rsi
  int v107; // er13
  int v108; // eax
  int v109; // er9
  int v110; // eax
  int v111; // eax
  int v112; // er9
  int v113; // eax
  int v114; // eax
  hkaiEdgeGeometry::Edge *v115; // r13
  hkaiEdgeGeometry::Edge *v116; // rcx
  unsigned int v117; // eax
  unsigned int v118; // eax
  __int64 v119; // rdx
  unsigned int v120; // eax
  unsigned int v121; // eax
  unsigned int v122; // eax
  unsigned int v123; // eax
  unsigned int v124; // eax
  int v125; // er9
  int v126; // eax
  int v127; // eax
  __int64 v128; // r13
  int v129; // er9
  int v130; // eax
  int v131; // eax
  __int64 v132; // rcx
  unsigned int *v133; // rcx
  unsigned int v134; // eax
  unsigned int v135; // eax
  hkaiBooleanFaceFaceIntersects::Intersect *v136; // rcx
  int v137; // eax
  int v138; // er8
  hkResult resulta; // [rsp+30h] [rbp-D0h]
  hkArrayBase<hkRadixSort::SortData32> sortArray; // [rsp+38h] [rbp-C8h]
  hkArrayBase<hk1AxisSweep::AabbInt> sortedAabbs; // [rsp+48h] [rbp-B8h]
  hkResult v142; // [rsp+58h] [rbp-A8h]
  hk1AxisSweep::AabbInt *array; // [rsp+60h] [rbp-A0h]
  int v144; // [rsp+68h] [rbp-98h]
  int v145; // [rsp+6Ch] [rbp-94h]
  hkResult v146; // [rsp+70h] [rbp-90h]
  hkResult v147; // [rsp+74h] [rbp-8Ch]
  __int64 v148; // [rsp+78h] [rbp-88h]
  void *v149; // [rsp+80h] [rbp-80h]
  hkResult v150; // [rsp+88h] [rbp-78h]
  void *v151; // [rsp+90h] [rbp-70h]
  int v152; // [rsp+98h] [rbp-68h]
  hkResult v153; // [rsp+9Ch] [rbp-64h]
  __int64 v154; // [rsp+A0h] [rbp-60h]
  hkAabb aabbIn; // [rsp+B0h] [rbp-50h]
  hkVector4f points; // [rsp+D0h] [rbp-30h]
  __m128 v157; // [rsp+E0h] [rbp-20h]
  __m128 v158; // [rsp+F0h] [rbp-10h]
  __m128 v159; // [rsp+100h] [rbp+0h]
  hkaiBooleanOperation *v160; // [rsp+1A0h] [rbp+A0h]
  hkResult *v161; // [rsp+1A8h] [rbp+A8h]
  hkaiEdgeGeometry::Edge *v162; // [rsp+1B8h] [rbp+B8h]

  v162 = edges;
  v161 = result;
  v160 = this;
  v7 = edges->m_face;
  v8 = faceNormalIn;
  v9 = result;
  v10 = edges;
  this->m_edgeEdgeIntersects.m_size = 0;
  v11 = this->m_edgeEdgeIntersects.m_capacityAndFlags;
  v151 = &this->m_edgeEdgeIntersects;
  v12 = v11 & 0x3FFFFFFF;
  if ( v12 < 32 )
  {
    v13 = 2 * v12;
    v14 = 32;
    if ( v13 > 32 )
      v14 = v13;
    hkArrayUtil::_reserve(
      &resulta,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &this->m_edgeEdgeIntersects,
      v14,
      12);
    if ( resulta.m_enum )
    {
      v9->m_enum = 1;
      return v9;
    }
  }
  v16 = numEdges;
  v17 = (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128((const __m128i *)v8), 1u), 1u);
  v18 = &geomOut->m_edges;
  v19 = numEdges + 4;
  v149 = &geomOut->m_vertices;
  array = 0i64;
  v144 = 0;
  v145 = 2147483648;
  v152 = (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                                _mm_and_ps(
                                                                  _mm_cmpleps(
                                                                    _mm_max_ps(
                                                                      _mm_shuffle_ps(v17, v17, 170),
                                                                      _mm_max_ps(
                                                                        _mm_shuffle_ps(v17, v17, 85),
                                                                        _mm_shuffle_ps(v17, v17, 0))),
                                                                    v17),
                                                                  (__m128)xmmword_141A4E0F0))];
  if ( numEdges + 4 <= 0 )
  {
    v150.m_enum = 0;
  }
  else
  {
    v20 = numEdges + 4;
    if ( v19 < 0 )
      v20 = 0;
    hkArrayUtil::_reserve(&v150, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v20, 32);
    if ( v150.m_enum )
    {
      v21 = v145;
      v9->m_enum = 1;
      v144 = 0;
      if ( v21 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          array,
          32 * v21);
      return v9;
    }
  }
  v144 = v19;
  resulta.m_enum = LODWORD(FLOAT_0_001);
  v22 = 0;
  v23 = _mm_shuffle_ps((__m128)(unsigned int)resulta.m_enum, (__m128)(unsigned int)resulta.m_enum, 0);
  if ( (signed int)v16 > 0 )
  {
    v24 = v149;
    v25 = 0i64;
    do
    {
      v26.m_quad = _mm_sub_ps(
                     _mm_min_ps(
                       *(__m128 *)(*v24 + 16i64 * (signed int)v10->m_a),
                       *(__m128 *)(*v24 + 16i64 * (signed int)v10->m_b)),
                     v23);
      aabbIn.m_max.m_quad = _mm_add_ps(
                              _mm_max_ps(
                                *(__m128 *)(*v24 + 16i64 * (signed int)v10->m_a),
                                *(__m128 *)(*v24 + 16i64 * (signed int)v10->m_b)),
                              v23);
      aabbIn.m_min = (hkVector4f)v26.m_quad;
      hk1AxisSweep::AabbInt::set(&array[v25], &aabbIn, v22++);
      ++v25;
      ++v10;
    }
    while ( v22 < (signed int)v16 );
    v9 = v161;
    v19 = v16 + 4;
  }
  v27 = v16;
  v154 = v16;
  array[v27].m_min[0] = -1;
  array[v27 + 1].m_min[0] = -1;
  array[v16 + 2].m_min[0] = -1;
  array[v16 + 3].m_min[0] = -1;
  v28 = 2147483648;
  sortedAabbs.m_data = 0i64;
  sortedAabbs.m_size = 0;
  sortedAabbs.m_capacityAndFlags = 2147483648;
  sortArray.m_data = 0i64;
  sortArray.m_capacityAndFlags = 2147483648;
  sortArray.m_size = 0;
  if ( v19 <= 0 )
  {
    v142.m_enum = 0;
  }
  else
  {
    v29 = v19;
    if ( v19 < 0 )
      v29 = 0;
    hkArrayUtil::_reserve(&v142, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &sortedAabbs, v29, 32);
    if ( v142.m_enum )
      goto LABEL_28;
    v28 = sortArray.m_capacityAndFlags;
  }
  v30 = v28 & 0x3FFFFFFF;
  sortedAabbs.m_size = v19;
  if ( v30 < v19 )
  {
    v31 = 2 * v30;
    v32 = v19;
    if ( v19 < v31 )
      v32 = v31;
    hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &sortArray, v32, 8);
    if ( resulta.m_enum )
    {
LABEL_28:
      v33 = sortArray.m_capacityAndFlags;
      sortArray.m_size = 0;
      v9->m_enum = 1;
      if ( v33 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          sortArray.m_data,
          8 * v33);
      sortedAabbs.m_size = 0;
      sortArray.m_capacityAndFlags = 2147483648;
      sortArray.m_data = 0i64;
      if ( sortedAabbs.m_capacityAndFlags >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          sortedAabbs.m_data,
          32 * sortedAabbs.m_capacityAndFlags);
      sortedAabbs.m_data = 0i64;
      sortedAabbs.m_capacityAndFlags = 2147483648;
      v144 = 0;
      if ( v145 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          array,
          32 * v145);
      return v9;
    }
  }
  sortArray.m_size = v19;
  hk1AxisSweep::sortAabbs(array, v16, &sortArray, &sortedAabbs);
  v34 = array;
  v35 = v16 - 1;
  v36 = 0;
  v37 = 1;
  v142.m_enum = v35;
  if ( (signed int)v35 > 0 )
  {
    while ( 1 )
    {
      v38 = v36;
      v39 = array[v38].m_max[0];
      v40 = &array[v37];
      if ( v40->m_min[0] <= v39 )
        break;
LABEL_39:
      v37 = ++v36 + 1;
      if ( v36 >= v35 )
        goto LABEL_40;
    }
    while ( (((v40->m_max[2] - array[v38].m_min[2]) | (v40->m_max[1] - array[v38].m_min[1]) | (array[v38].m_max[2]
                                                                                             - v40->m_min[2]) | (array[v38].m_max[1] - v40->m_min[1])) & 0x80000000) != 0 )
    {
      v40 = &array[++v37];
      if ( v40->m_min[0] > v39 )
        goto LABEL_39;
    }
  }
LABEL_40:
  if ( v36 < v35 )
  {
    v41 = v162;
    do
    {
      v42 = v152;
      LODWORD(v148) = *(_DWORD *)v34[v36].m_expansionMin;
      v43 = *(signed int *)v34[v37].m_expansionMin;
      v44 = v41[(signed int)v148].m_a;
      v45 = *(_QWORD *)v149;
      v46 = (signed int)v41[(signed int)v148].m_b;
      v47 = 2i64 * (signed int)v41[(signed int)v148].m_a;
      v147.m_enum = *(_DWORD *)v34[v37].m_expansionMin;
      v48 = *(__m128 *)(v45 + 8 * v47);
      v49 = *(__m128 *)(v45 + 8 * v47);
      v50 = *(__m128 *)(v45 + 16 * v46);
      if ( v152 )
      {
        if ( v152 == 1 )
          v49 = _mm_shuffle_ps(v48, v48, 216);
      }
      else
      {
        v49 = _mm_shuffle_ps(v48, v48, 201);
      }
      points.m_quad = v49;
      v51 = v50;
      if ( v152 )
      {
        if ( v152 == 1 )
          v51 = _mm_shuffle_ps(v50, v50, 216);
      }
      else
      {
        v51 = _mm_shuffle_ps(v50, v50, 201);
      }
      v52 = _mm_sub_ps(v50, v48);
      v157 = v51;
      v53 = v43;
      v54 = (signed int)v41[v43].m_a;
      v55 = _mm_mul_ps(v52, v48);
      v56 = _mm_shuffle_ps(
              v52,
              _mm_unpackhi_ps(
                v52,
                _mm_sub_ps(
                  (__m128)0i64,
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v55, v55, 85), _mm_shuffle_ps(v55, v55, 0)),
                    _mm_shuffle_ps(v55, v55, 170)))),
              196);
      if ( v44 != (_DWORD)v54 )
      {
        v57 = v41[v53].m_b;
        if ( v44 != v57 && (_DWORD)v46 != (_DWORD)v54 && (_DWORD)v46 != v57 )
        {
          v58 = *(__m128 *)(v45 + 16 * v54);
          v59 = *(__m128 *)(v45 + 16 * v54);
          v60 = *(__m128 *)(v45 + 16i64 * (signed int)v41[v53].m_b);
          if ( v152 )
          {
            if ( v152 == 1 )
              v59 = _mm_shuffle_ps(v59, v58, 216);
          }
          else
          {
            v59 = _mm_shuffle_ps(v59, v58, 201);
          }
          v158 = v59;
          v61 = v60;
          if ( v152 )
          {
            if ( v152 == 1 )
              v61 = _mm_shuffle_ps(v60, v60, 216);
          }
          else
          {
            v61 = _mm_shuffle_ps(v60, v60, 201);
          }
          v159 = v61;
          if ( (unsigned int)hkaiBooleanOperation::_linesIntersect(v160, &points, &aabbIn.m_min) )
          {
            v62.m_quad = (__m128)aabbIn.m_min;
            if ( v42 )
            {
              if ( v42 == 1 )
                v62.m_quad = _mm_shuffle_ps(aabbIn.m_min.m_quad, aabbIn.m_min.m_quad, 216);
            }
            else
            {
              v62.m_quad = _mm_shuffle_ps(aabbIn.m_min.m_quad, aabbIn.m_min.m_quad, 210);
            }
            v63 = v149;
            v64 = *((_DWORD *)v149 + 2);
            HIDWORD(v148) = v64;
            v65 = v64 + 16;
            v66 = *((_DWORD *)v149 + 3) & 0x3FFFFFFF;
            if ( v66 >= v65 )
            {
              v146.m_enum = 0;
            }
            else
            {
              v67 = 2 * v66;
              if ( v65 < v67 )
                v65 = v67;
              hkArrayUtil::_reserve(&v146, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v149, v65, 16);
              if ( v146.m_enum )
                goto LABEL_71;
            }
            if ( v63[2] == (v63[3] & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v63, 16);
            v70 = v151;
            v71 = _mm_sub_ps(v60, v58);
            v72 = _mm_mul_ps(v71, v58);
            *(hkVector4f *)(*(_QWORD *)v63 + 16i64 * (signed int)v63[2]++) = (hkVector4f)v62.m_quad;
            v73 = v70[2] + 16;
            v74 = v70[3] & 0x3FFFFFFF;
            v75 = _mm_shuffle_ps(
                    v71,
                    _mm_unpackhi_ps(
                      v71,
                      _mm_sub_ps(
                        (__m128)0i64,
                        _mm_add_ps(
                          _mm_add_ps(_mm_shuffle_ps(v72, v72, 85), _mm_shuffle_ps(v72, v72, 0)),
                          _mm_shuffle_ps(v72, v72, 170)))),
                    196);
            if ( v74 >= v73 )
            {
              resulta.m_enum = 0;
            }
            else
            {
              v76 = 2 * v74;
              if ( v73 < v76 )
                v73 = v76;
              hkArrayUtil::_reserve(
                &resulta,
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                v70,
                v73,
                12);
              if ( resulta.m_enum )
                goto LABEL_71;
              v70 = v151;
            }
            v77 = (signed int)v70[2];
            v78 = v77 + 2;
            v79 = v70[3] & 0x3FFFFFFF;
            if ( v79 >= (signed int)v77 + 2 )
            {
              v153.m_enum = 0;
            }
            else
            {
              v80 = 2 * v79;
              if ( v78 < v80 )
                v78 = v80;
              hkArrayUtil::_reserve(&v153, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v70, v78, 12);
              v70 = v151;
            }
            v81 = *(_QWORD *)v70;
            v70[2] += 2;
            v82 = _mm_mul_ps(v62.m_quad, v56);
            v83 = _mm_shuffle_ps(v82, _mm_unpackhi_ps(v82, v56), 196);
            v84 = v81 + 12 * v77;
            LODWORD(v81) = HIDWORD(v148);
            *(_QWORD *)v84 = v148;
            v85 = _mm_add_ps(_mm_shuffle_ps(v83, v83, 78), v83);
            v86 = _mm_mul_ps(v75, v62.m_quad);
            *(float *)(v84 + 8) = COERCE_FLOAT(_mm_shuffle_ps(v85, v85, 177)) + v85.m128_f32[0];
            *(_DWORD *)(v84 + 16) = v81;
            *(hkResult *)(v84 + 12) = v147;
            v87 = _mm_shuffle_ps(v86, _mm_unpackhi_ps(v86, v75), 196);
            v88 = _mm_add_ps(_mm_shuffle_ps(v87, v87, 78), v87);
            *(float *)(v84 + 20) = COERCE_FLOAT(_mm_shuffle_ps(v88, v88, 177)) + v88.m128_f32[0];
          }
        }
      }
      ++v37;
      if ( v36 >= v142.m_enum )
        break;
      while ( 1 )
      {
        v89 = v36;
        v90 = v34[v89].m_max[0];
        v91 = &v34[v37];
        if ( v91->m_min[0] <= v90 )
          break;
LABEL_95:
        v37 = ++v36 + 1;
        if ( v36 >= v142.m_enum )
          goto LABEL_96;
      }
      while ( (((v91->m_max[2] - v34[v89].m_min[2]) | (v91->m_max[1] - v34[v89].m_min[1]) | (v34[v89].m_max[2]
                                                                                           - v91->m_min[2]) | (v34[v89].m_max[1] - v91->m_min[1])) & 0x80000000) != 0 )
      {
        v91 = &v34[++v37];
        if ( v91->m_min[0] > v90 )
          goto LABEL_95;
      }
    }
    while ( v36 < v142.m_enum );
  }
LABEL_96:
  v92 = v151;
  v93 = *((_DWORD *)v151 + 2) + 1;
  v94 = *((_DWORD *)v151 + 3) & 0x3FFFFFFF;
  if ( v94 >= v93 )
    goto LABEL_153;
  v95 = 2 * v94;
  if ( v93 < v95 )
    v93 = v95;
  hkArrayUtil::_reserve((hkResult *)&v160, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v151, v93, 12);
  if ( (_DWORD)v160 )
  {
LABEL_71:
    v68 = sortArray.m_capacityAndFlags;
    v69 = v161;
    v161->m_enum = 1;
    sortArray.m_size = 0;
    if ( v68 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        sortArray.m_data,
        8 * v68);
    sortArray.m_data = 0i64;
    sortArray.m_capacityAndFlags = 2147483648;
    sortedAabbs.m_size = 0;
    if ( sortedAabbs.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        sortedAabbs.m_data,
        32 * sortedAabbs.m_capacityAndFlags);
    sortedAabbs.m_data = 0i64;
    v144 = 0;
  }
  else
  {
LABEL_153:
    if ( v92[2] == (v92[3] & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v92, 12);
    v96 = (signed int)v92[2];
    v97 = *(hkaiBooleanOperation::EdgeEdgeIntersect **)v92;
    v92[2] = v96 + 1;
    v97[v96].m_edgeIndex = -1;
    v98 = --v92[2];
    if ( v98 > 1 )
      hkAlgorithm::quickSortRecursive<hkaiBooleanOperation::EdgeEdgeIntersect,unsigned int (*)(hkaiBooleanOperation::EdgeEdgeIntersect const &,hkaiBooleanOperation::EdgeEdgeIntersect const &)>(
        *(hkaiBooleanOperation::EdgeEdgeIntersect **)v92,
        0,
        v98 - 1,
        hkaiBooleanOperation_orderEdgeEdgeIntersect);
    v99 = *(char **)v92;
    v100 = *(_DWORD *)v99;
    v101 = 0;
    v149 = 0i64;
    v142.m_enum = 0;
    if ( v154 > 0 )
    {
      v102 = intersects;
      do
      {
        v103 = v18->m_size;
        resulta.m_enum = v18->m_size;
        if ( v100 == v101 )
        {
          for ( i = v99 + 12; *(_DWORD *)i == v100; i += 12 )
            ;
          v105 = (unsigned __int128)((i - v99) * (signed __int128)3074457345618258603i64) >> 64;
          v106 = (v105 >> 63) + ((signed __int64)v105 >> 1);
          v107 = 2 * v106 + 2;
          v108 = v18->m_capacityAndFlags & 0x3FFFFFFF;
          v109 = v107 + resulta.m_enum;
          if ( v108 >= v107 + resulta.m_enum )
          {
            LODWORD(v160) = 0;
          }
          else
          {
            v110 = 2 * v108;
            if ( v109 < v110 )
              v109 = v110;
            hkArrayUtil::_reserve(
              (hkResult *)&v160,
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
              v18,
              v109,
              16);
            if ( (_DWORD)v160 )
              goto LABEL_71;
          }
          v111 = v18->m_size;
          LODWORD(v148) = v111;
          v112 = v111 + v107;
          v113 = v18->m_capacityAndFlags & 0x3FFFFFFF;
          if ( v113 >= v112 )
          {
            v147.m_enum = 0;
          }
          else
          {
            v114 = 2 * v113;
            if ( v112 < v114 )
              v112 = v114;
            hkArrayUtil::_reserve(&v147, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v18, v112, 16);
          }
          v18->m_size += v107;
          v115 = v162;
          v116 = &v18->m_data[(signed int)v148 + 2];
          v116[-2].m_a = v162->m_a;
          v117 = *((_DWORD *)v99 + 1);
          v116[-2].m_face = v7;
          v116[-2].m_b = v117;
          v116[-2].m_data = 0;
          v116[-1].m_a = *((_DWORD *)v99 + 1);
          v118 = v115->m_a;
          v116[-1].m_face = v7;
          v116[-1].m_b = v118;
          v116[-1].m_data = 0;
          if ( (signed int)v106 - 1 > 0 )
          {
            v119 = (unsigned int)(v106 - 1);
            do
            {
              v120 = *((_DWORD *)v99 + 1);
              v116 += 2;
              v99 += 12;
              v116[-2].m_a = v120;
              v121 = *((_DWORD *)v99 + 1);
              v116[-2].m_face = v7;
              v116[-2].m_data = 0;
              v116[-2].m_b = v121;
              v116[-1].m_a = *((_DWORD *)v99 + 1);
              v122 = *((_DWORD *)v99 - 2);
              v116[-1].m_face = v7;
              v116[-1].m_data = 0;
              v116[-1].m_b = v122;
              --v119;
            }
            while ( v119 );
          }
          v116->m_a = *((_DWORD *)v99 + 1);
          v123 = v115->m_b;
          v116->m_face = v7;
          v116->m_b = v123;
          v116->m_data = 0;
          v116[1].m_a = v115->m_b;
          v124 = *((_DWORD *)v99 + 1);
          v116[1].m_face = v7;
          v116[1].m_data = 0;
          v116[1].m_b = v124;
          v100 = *(_DWORD *)i;
          v99 = i;
          v103 = resulta.m_enum;
        }
        else
        {
          v125 = v103 + 2;
          v126 = v18->m_capacityAndFlags & 0x3FFFFFFF;
          if ( v126 >= v103 + 2 )
          {
            v146.m_enum = 0;
          }
          else
          {
            v127 = 2 * v126;
            if ( v125 < v127 )
              v125 = v127;
            hkArrayUtil::_reserve(&v146, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v18, v125, 16);
            if ( v146.m_enum )
              goto LABEL_71;
          }
          v128 = v18->m_size;
          v129 = v128 + 2;
          v130 = v18->m_capacityAndFlags & 0x3FFFFFFF;
          if ( v130 >= (signed int)v128 + 2 )
          {
            HIDWORD(v148) = 0;
          }
          else
          {
            v131 = 2 * v130;
            if ( v129 < v131 )
              v129 = v131;
            hkArrayUtil::_reserve(
              (hkResult *)&v148 + 1,
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
              v18,
              v129,
              16);
          }
          v18->m_size += 2;
          v132 = v128;
          v115 = v162;
          v133 = &v18->m_data[v132].m_a;
          *v133 = v162->m_a;
          v134 = v115->m_b;
          v133[2] = v7;
          v133[1] = v134;
          v133[3] = 0;
          v133[4] = v115->m_b;
          v135 = v115->m_a;
          v133[6] = v7;
          v133[5] = v135;
          v133[7] = 0;
        }
        if ( v102 )
        {
          if ( v102->m_intersects.m_size == (v102->m_intersects.m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v102, 16);
          v136 = &v102->m_intersects.m_data[v102->m_intersects.m_size++];
          v136->m_faceA = v7;
          v136->m_faceB = v115->m_data;
          v137 = v18->m_size;
          v136->m_startEdgeIndex = v103;
          v136->m_numEdges = v137 - v103;
        }
        v101 = v142.m_enum + 1;
        v162 = v115 + 1;
        ++v142.m_enum;
        v149 = (char *)v149 + 1;
      }
      while ( (signed __int64)v149 < v154 );
    }
    v69 = v161;
    v138 = sortArray.m_capacityAndFlags;
    sortArray.m_size = 0;
    v161->m_enum = 0;
    if ( v138 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        sortArray.m_data,
        8 * v138);
    sortArray.m_data = 0i64;
    sortArray.m_capacityAndFlags = 2147483648;
    sortedAabbs.m_size = 0;
    if ( sortedAabbs.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        sortedAabbs.m_data,
        32 * sortedAabbs.m_capacityAndFlags);
    sortedAabbs.m_data = 0i64;
    v144 = 0;
  }
  sortedAabbs.m_capacityAndFlags = 2147483648;
  if ( v145 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      array,
      32 * v145);
  return v69;
}

// File Line: 1627
// RVA: 0xBA3E70
_BOOL8 __fastcall hkaiBooleanOperation_orderByFace(hkaiEdgeGeometry::Edge *a, hkaiEdgeGeometry::Edge *b)
{
  return a->m_face < b->m_face;
}

// File Line: 1633
// RVA: 0xBA3B30
hkResult *__fastcall hkaiBooleanOperation::_addFaceFaceIntersections(hkaiBooleanOperation *this, hkResult *result, hkArray<hkVector4f,hkContainerHeapAllocator> *faceNormals, hkArray<hkaiEdgeGeometry::Edge,hkContainerHeapAllocator> *faceFaceEdges, hkaiBooleanFaceFaceIntersects *intersects, hkaiEdgeGeometry *geomOut)
{
  hkArray<hkaiEdgeGeometry::Edge,hkContainerHeapAllocator> *v6; // rbx
  hkArray<hkVector4f,hkContainerHeapAllocator> *v7; // r15
  int v8; // er9
  hkResult *v9; // rsi
  int v10; // eax
  hkaiBooleanOperation *v11; // r12
  int v12; // eax
  signed __int64 v14; // rcx
  signed int v15; // er8
  hkaiEdgeGeometry::Edge *v16; // r9
  unsigned __int64 v17; // rdi
  hkaiEdgeGeometry *v18; // rbp
  hkaiBooleanFaceFaceIntersects *v19; // r14
  __int64 v20; // rcx
  unsigned __int64 v21; // rbx
  hkResult resulta; // [rsp+88h] [rbp+20h]

  v6 = faceFaceEdges;
  v7 = faceNormals;
  v8 = faceFaceEdges->m_size + 1;
  v9 = result;
  v10 = v6->m_capacityAndFlags & 0x3FFFFFFF;
  v11 = this;
  if ( v10 >= v8 )
  {
    resulta.m_enum = 0;
  }
  else
  {
    v12 = 2 * v10;
    if ( v8 < v12 )
      v8 = v12;
    hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v6, v8, 16);
    if ( resulta.m_enum )
    {
      v9->m_enum = 1;
      return v9;
    }
  }
  if ( v6->m_size == (v6->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v6, 16);
  v14 = (signed __int64)&v6->m_data[v6->m_size++];
  *(_DWORD *)(v14 + 8) = -1;
  v15 = --v6->m_size;
  if ( v15 > 1 )
    hkAlgorithm::quickSortRecursive<hkaiEdgeGeometry::Edge,unsigned int (*)(hkaiEdgeGeometry::Edge const &,hkaiEdgeGeometry::Edge const &)>(
      v6->m_data,
      0,
      v15 - 1,
      hkaiBooleanOperation_orderByFace);
  v16 = v6->m_data;
  v17 = (unsigned __int64)&v6->m_data[v6->m_size];
  if ( v6->m_data >= (hkaiEdgeGeometry::Edge *)v17 )
  {
LABEL_17:
    v9->m_enum = 0;
  }
  else
  {
    v18 = geomOut;
    v19 = intersects;
    while ( 1 )
    {
      v20 = (signed int)v16->m_face;
      v21 = (unsigned __int64)&v16[1];
      if ( v16[1].m_face == (_DWORD)v20 )
      {
        do
          v21 += 16i64;
        while ( *(_DWORD *)(v21 + 8) == (_DWORD)v20 );
      }
      hkaiBooleanOperation::_addFaceIntersections(
        v11,
        &resulta,
        &v7->m_data[v20],
        v16,
        (signed __int64)(v21 - (_QWORD)v16) >> 4,
        v19,
        v18);
      if ( resulta.m_enum )
        break;
      v16 = (hkaiEdgeGeometry::Edge *)v21;
      if ( v21 >= v17 )
        goto LABEL_17;
    }
    v9->m_enum = 1;
  }
  return v9;
}

// File Line: 1668
// RVA: 0xBA0B00
hkResult *__fastcall hkaiBooleanOperation::_setGeometry(hkaiBooleanOperation *this, hkResult *result, hkaiBooleanOperation::GeometricInfo *info, hkaiEdgeGeometry *geom)
{
  hkVector4f *v4; // rax
  hkResult *v5; // rbx
  hkaiBooleanOperation::GeometricInfo *v6; // rdi
  hkaiEdgeGeometry *v7; // rsi
  hkResult *v8; // rax
  __m128 v9; // xmm2
  int v10; // edx
  __m128 v11; // xmm0
  __int64 v12; // rcx
  hkVector4f *v13; // rax
  hkResult resulta; // [rsp+40h] [rbp+18h]
  hkResult v15; // [rsp+48h] [rbp+20h]

  v4 = geom->m_vertices.m_data;
  v5 = result;
  v6 = info;
  info->m_geometry = geom;
  info->m_vertices = v4;
  v7 = geom;
  hkaiUniqueEdges::setGeometry(&info->m_uniqueEdges, &resulta, geom);
  if ( resulta.m_enum || (hkaiFaceEdges::setGeometry(&v6->m_faceEdges, &v15, v7), v15.m_enum) )
  {
    v5->m_enum = 1;
    v8 = v5;
  }
  else
  {
    v6->m_aabb.m_min = (hkVector4f)xmmword_141A712A0;
    v9 = (__m128)xmmword_141A712A0;
    v10 = 0;
    v11 = _mm_xor_ps(
            (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
            (__m128)xmmword_141A712A0);
    v6->m_aabb.m_max.m_quad = v11;
    if ( v7->m_vertices.m_size > 0 )
    {
      v12 = 0i64;
      do
      {
        v13 = v7->m_vertices.m_data;
        ++v10;
        ++v12;
        v9 = _mm_min_ps(v9, v13[v12 - 1].m_quad);
        v6->m_aabb.m_min.m_quad = v9;
        v11 = _mm_max_ps(v11, v13[v12 - 1].m_quad);
        v6->m_aabb.m_max.m_quad = v11;
      }
      while ( v10 < v7->m_vertices.m_size );
    }
    v5->m_enum = 0;
    v8 = v5;
  }
  return v8;
}

// File Line: 1692
// RVA: 0xBA1DE0
hkResult *__fastcall hkaiBooleanOperation::_calculateFaceAabbs(hkResult *result, hkArray<hkVector4f,hkContainerHeapAllocator> *verticesIn, hkaiFaceEdges *faceEdges, hkAabb *otherAabb, hkArray<hk1AxisSweep::AabbInt,hkContainerTempAllocator> *faceAabbsOut)
{
  hkArray<hk1AxisSweep::AabbInt,hkContainerTempAllocator> *v5; // r12
  signed __int64 v6; // r13
  hkArray<hkVector4f,hkContainerHeapAllocator> *v7; // r15
  int v8; // ebx
  int v9; // eax
  hkResult *v10; // r14
  int v11; // eax
  int v12; // er9
  int v13; // eax
  int v14; // er9
  int v15; // eax
  int v16; // eax
  int v17; // er9
  int v18; // er8
  hkVector4f *v19; // r15
  int v20; // edi
  hk1AxisSweep::AabbInt *v21; // rbx
  signed __int64 v22; // rsi
  __m128 *v23; // r12
  __int64 v24; // r14
  __int64 v25; // rax
  unsigned int **v26; // rdx
  unsigned __int64 v27; // r8
  unsigned int *v28; // rax
  unsigned int **v29; // rdx
  hkVector4f v30; // xmm2
  hkVector4f v31; // xmm1
  unsigned int *v32; // rax
  signed __int64 v33; // rcx
  int v34; // eax
  signed __int64 v35; // rbx
  int v36; // eax
  int v37; // er9
  hk1AxisSweep::AabbInt *v38; // rcx
  int v39; // er8
  hkResult resulta; // [rsp+30h] [rbp-50h]
  hkResult v42; // [rsp+34h] [rbp-4Ch]
  hkResult v43; // [rsp+38h] [rbp-48h]
  hkArrayBase<hkRadixSort::SortData32> sortArray; // [rsp+40h] [rbp-40h]
  void *array; // [rsp+50h] [rbp-30h]
  int v46; // [rsp+58h] [rbp-28h]
  int v47; // [rsp+5Ch] [rbp-24h]
  hkAabb aabbIn; // [rsp+60h] [rbp-20h]
  hkResult *v49; // [rsp+C0h] [rbp+40h]
  hkaiFaceEdges *v50; // [rsp+D0h] [rbp+50h]
  hkAabb *v51; // [rsp+D8h] [rbp+58h]

  v51 = otherAabb;
  v50 = faceEdges;
  v49 = result;
  v5 = faceAabbsOut;
  LODWORD(v6) = faceEdges->m_faceStartEdges.m_size - 1;
  v7 = verticesIn;
  v8 = v6 + 4;
  v9 = faceAabbsOut->m_capacityAndFlags & 0x3FFFFFFF;
  v10 = result;
  if ( v9 >= (signed int)v6 + 4 )
  {
    resulta.m_enum = 0;
  }
  else
  {
    v11 = 2 * v9;
    v12 = v6 + 4;
    if ( v8 < v11 )
      v12 = v11;
    hkArrayUtil::_reserve(
      &resulta,
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
      faceAabbsOut,
      v12,
      32);
    if ( resulta.m_enum )
    {
      v10->m_enum = 1;
      return v10;
    }
  }
  v13 = 2147483648;
  v5->m_size = v8;
  array = 0i64;
  v46 = 0;
  v47 = 2147483648;
  sortArray.m_data = 0i64;
  sortArray.m_capacityAndFlags = 2147483648;
  sortArray.m_size = 0;
  if ( v8 <= 0 )
  {
    v42.m_enum = 0;
  }
  else
  {
    v14 = v6 + 4;
    if ( v8 < 0 )
      v14 = 0;
    hkArrayUtil::_reserve(&v42, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v14, 32);
    if ( v42.m_enum )
      goto LABEL_17;
    v13 = sortArray.m_capacityAndFlags;
  }
  v15 = v13 & 0x3FFFFFFF;
  v46 = v6 + 4;
  if ( v15 >= v8 )
    goto LABEL_40;
  v16 = 2 * v15;
  v17 = v6 + 4;
  if ( v8 < v16 )
    v17 = v16;
  hkArrayUtil::_reserve(&v43, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &sortArray, v17, 8);
  if ( v43.m_enum == HK_SUCCESS )
  {
LABEL_40:
    v19 = v7->m_data;
    v20 = 1;
    v6 = (signed int)v6;
    sortArray.m_size = v6 + 4;
    v21 = v5->m_data;
    v22 = 1i64;
    if ( (signed int)v6 > 1i64 )
    {
      v23 = &v51->m_min.m_quad;
      v24 = (__int64)v50;
      do
      {
        v25 = *(_QWORD *)(v24 + 16);
        v26 = *(unsigned int ***)(v25 + 8 * v22);
        v27 = *(_QWORD *)(v25 + 8 * v22 + 8);
        v28 = *v26;
        v29 = v26 + 1;
        v30.m_quad = (__m128)v19[*v28];
        aabbIn.m_max = (hkVector4f)v30.m_quad;
        v31.m_quad = v30.m_quad;
        for ( aabbIn.m_min = (hkVector4f)v30.m_quad; (unsigned __int64)v29 < v27; aabbIn.m_max = (hkVector4f)v30.m_quad )
        {
          v32 = *v29;
          ++v29;
          v33 = *v32;
          v31.m_quad = _mm_min_ps(v31.m_quad, v19[*v32].m_quad);
          aabbIn.m_min = (hkVector4f)v31.m_quad;
          v30.m_quad = _mm_max_ps(v30.m_quad, v19[v33].m_quad);
        }
        if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmpleps(*v23, v30.m_quad), _mm_cmpleps(v31.m_quad, v23[1]))) & 7) == 7 )
        {
          hk1AxisSweep::AabbInt::set(v21, &aabbIn, v20);
          ++v21;
        }
        ++v22;
        ++v20;
      }
      while ( v22 < v6 );
      v10 = v49;
      v5 = faceAabbsOut;
    }
    v21->m_min[0] = -1;
    v21[1].m_min[0] = -1;
    v21[2].m_min[0] = -1;
    v21[3].m_min[0] = -1;
    v34 = v5->m_capacityAndFlags & 0x3FFFFFFF;
    v35 = &v21[4] - v5->m_data;
    if ( v34 < (signed int)v35 )
    {
      v36 = 2 * v34;
      v37 = v35;
      if ( (signed int)v35 < v36 )
        v37 = v36;
      hkArrayUtil::_reserve(
        (hkResult *)&v50,
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
        v5,
        v37,
        32);
    }
    v38 = v5->m_data;
    v5->m_size = v35;
    hk1AxisSweep::sortAabbs(v38, v35 - 4, &sortArray, (hkArrayBase<hk1AxisSweep::AabbInt> *)&array);
    v39 = sortArray.m_capacityAndFlags;
    v10->m_enum = 0;
    sortArray.m_size = 0;
    if ( v39 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        sortArray.m_data,
        8 * v39);
    sortArray.m_data = 0i64;
    v46 = 0;
    goto LABEL_35;
  }
LABEL_17:
  v18 = sortArray.m_capacityAndFlags;
  sortArray.m_size = 0;
  v10->m_enum = 1;
  if ( v18 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      sortArray.m_data,
      8 * v18);
  sortArray.m_data = 0i64;
  v46 = 0;
LABEL_35:
  sortArray.m_capacityAndFlags = 2147483648;
  if ( v47 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      array,
      32 * v47);
  return v10;
}

// File Line: 1774
// RVA: 0xBA1AD0
hkResult *__fastcall hkaiBooleanOperation::_calculateEdgeAabbs(hkResult *result, hkArray<hkVector4f,hkContainerHeapAllocator> *verticesIn, hkaiUniqueEdges *edgeList, hkAabb *otherAabb, hkArray<hk1AxisSweep::AabbInt,hkContainerTempAllocator> *edgeAabbs)
{
  hkArray<hk1AxisSweep::AabbInt,hkContainerTempAllocator> *v5; // r15
  int v6; // er13
  hkArray<hkVector4f,hkContainerHeapAllocator> *v7; // rdi
  int v8; // ebx
  int v9; // eax
  hkResult *v10; // r14
  int v11; // eax
  int v12; // er9
  int v13; // eax
  int v14; // er9
  int v15; // eax
  int v16; // eax
  int v17; // er9
  int v18; // er8
  hkVector4f *v19; // r8
  hk1AxisSweep::AabbInt *v20; // rbx
  int v21; // esi
  __int64 v22; // rdi
  __int64 v23; // r12
  __int64 v24; // r13
  __int64 v25; // r15
  __m128 v26; // xmm0
  unsigned int **v27; // rcx
  __int64 v28; // rdx
  hkVector4f v29; // xmm2
  signed __int64 v30; // rax
  hkVector4f v31; // xmm1
  __m128 v32; // xmm1
  int v33; // eax
  signed __int64 v34; // rbx
  int v35; // eax
  int v36; // er9
  hk1AxisSweep::AabbInt *v37; // rcx
  int v38; // er8
  hkResult resulta; // [rsp+30h] [rbp-50h]
  hkResult v41; // [rsp+34h] [rbp-4Ch]
  hkResult v42[2]; // [rsp+38h] [rbp-48h]
  hkArrayBase<hkRadixSort::SortData32> sortArray; // [rsp+40h] [rbp-40h]
  void *array; // [rsp+50h] [rbp-30h]
  int v45; // [rsp+58h] [rbp-28h]
  int v46; // [rsp+5Ch] [rbp-24h]
  hkAabb aabbIn; // [rsp+60h] [rbp-20h]
  hkaiUniqueEdges *v48; // [rsp+D0h] [rbp+50h]
  hkAabb *v49; // [rsp+D8h] [rbp+58h]

  v49 = otherAabb;
  v48 = edgeList;
  v5 = edgeAabbs;
  v6 = edgeList->m_startUniqueEdge.m_size - 1;
  v7 = verticesIn;
  v8 = v6 + 4;
  v9 = edgeAabbs->m_capacityAndFlags & 0x3FFFFFFF;
  v10 = result;
  if ( v9 >= v6 + 4 )
  {
    resulta.m_enum = 0;
  }
  else
  {
    v11 = 2 * v9;
    v12 = v6 + 4;
    if ( v8 < v11 )
      v12 = v11;
    hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, edgeAabbs, v12, 32);
    if ( resulta.m_enum )
    {
      v10->m_enum = 1;
      return v10;
    }
  }
  v13 = 2147483648;
  v5->m_size = v8;
  array = 0i64;
  v45 = 0;
  v46 = 2147483648;
  sortArray.m_data = 0i64;
  sortArray.m_capacityAndFlags = 2147483648;
  sortArray.m_size = 0;
  if ( v8 <= 0 )
  {
    v41.m_enum = 0;
  }
  else
  {
    v14 = v6 + 4;
    if ( v8 < 0 )
      v14 = 0;
    hkArrayUtil::_reserve(&v41, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v14, 32);
    if ( v41.m_enum )
      goto LABEL_17;
    v13 = sortArray.m_capacityAndFlags;
  }
  v15 = v13 & 0x3FFFFFFF;
  v45 = v6 + 4;
  if ( v15 >= v8 )
    goto LABEL_38;
  v16 = 2 * v15;
  v17 = v6 + 4;
  if ( v8 < v16 )
    v17 = v16;
  hkArrayUtil::_reserve(v42, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &sortArray, v17, 8);
  if ( v42[0].m_enum == HK_SUCCESS )
  {
LABEL_38:
    v19 = v7->m_data;
    sortArray.m_size = v6 + 4;
    v20 = v5->m_data;
    v21 = 0;
    v22 = 0i64;
    *(_QWORD *)&v42[0].m_enum = v19;
    v23 = v6;
    if ( v6 > 0 )
    {
      v24 = (__int64)v48;
      v25 = (__int64)v49;
      do
      {
        v26 = *(__m128 *)v25;
        v27 = *(unsigned int ***)(*(_QWORD *)(v24 + 16) + 8 * v22);
        v28 = (__int64)*v27;
        v29.m_quad = (__m128)v19[**v27];
        aabbIn.m_min = (hkVector4f)v29.m_quad;
        aabbIn.m_max = (hkVector4f)v29.m_quad;
        v30 = *(unsigned int *)(v28 + 4);
        v31.m_quad = _mm_min_ps(v29.m_quad, v19[*(unsigned int *)(v28 + 4)].m_quad);
        aabbIn.m_min = (hkVector4f)v31.m_quad;
        v32 = _mm_cmpleps(v31.m_quad, *(__m128 *)(v25 + 16));
        aabbIn.m_max.m_quad = _mm_max_ps(v29.m_quad, v19[v30].m_quad);
        if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmpleps(v26, aabbIn.m_max.m_quad), v32)) & 7) == 7 )
        {
          hk1AxisSweep::AabbInt::set(v20, &aabbIn, v21);
          v19 = *(hkVector4f **)&v42[0].m_enum;
          ++v20;
        }
        ++v22;
        ++v21;
      }
      while ( v22 < v23 );
      v5 = edgeAabbs;
    }
    v20->m_min[0] = -1;
    v20[1].m_min[0] = -1;
    v20[2].m_min[0] = -1;
    v20[3].m_min[0] = -1;
    v33 = v5->m_capacityAndFlags & 0x3FFFFFFF;
    v34 = &v20[4] - v5->m_data;
    if ( v33 < (signed int)v34 )
    {
      v35 = 2 * v33;
      v36 = v34;
      if ( (signed int)v34 < v35 )
        v36 = v35;
      hkArrayUtil::_reserve(
        (hkResult *)&v48,
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
        v5,
        v36,
        32);
    }
    v37 = v5->m_data;
    v5->m_size = v34;
    hk1AxisSweep::sortAabbs(v37, v34 - 4, &sortArray, (hkArrayBase<hk1AxisSweep::AabbInt> *)&array);
    v38 = sortArray.m_capacityAndFlags;
    v10->m_enum = 0;
    sortArray.m_size = 0;
    if ( v38 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        sortArray.m_data,
        8 * v38);
    sortArray.m_data = 0i64;
    v45 = 0;
    goto LABEL_33;
  }
LABEL_17:
  v18 = sortArray.m_capacityAndFlags;
  v10->m_enum = 1;
  sortArray.m_size = 0;
  if ( v18 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      sortArray.m_data,
      8 * v18);
  sortArray.m_data = 0i64;
  v45 = 0;
LABEL_33:
  sortArray.m_capacityAndFlags = 2147483648;
  if ( v46 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      array,
      32 * v46);
  return v10;
}

// File Line: 1854
// RVA: 0xB9EFC0
hkResult *__fastcall hkaiBooleanOperation::subtract(hkaiBooleanOperation *this, hkResult *result, hkaiEdgeGeometry *a, hkaiEdgeGeometry *b, hkaiEdgeGeometry *geomOut, hkaiBooleanFaceFaceIntersects *intersects, hkaiBooleanFilter *filter)
{
  hkaiEdgeGeometry *v7; // rdi
  hkaiEdgeGeometry *v8; // r14
  hkResult *v9; // rbx
  hkaiBooleanOperation *v10; // rsi
  hkaiBooleanFaceFaceIntersects *v11; // rax
  hkaiBooleanFilter *v12; // r12
  signed __int64 v13; // r15
  hkaiEdgeGeometry *v14; // rdi
  int v15; // er9
  int v16; // eax
  __int64 v17; // rax
  hkaiEdgeGeometry::Face *v18; // rcx
  __int64 v19; // rdi
  char *v20; // rdx
  unsigned int v21; // eax
  hkBitField *v22; // rdi
  int v23; // er13
  int v24; // er15
  __int32 v25; // ecx
  unsigned int *v26; // r8
  unsigned int v27; // eax
  int v28; // eax
  int v29; // eax
  int v30; // er9
  __int64 v31; // rcx
  unsigned int *v32; // rdi
  int v33; // ecx
  int v34; // eax
  int v35; // ecx
  hkArray<hkVector4f,hkContainerHeapAllocator> *v36; // rdx
  hkArray<hkVector4f,hkContainerHeapAllocator> *v37; // rdx
  hkVector4f v38; // xmm1
  int v39; // er8
  hkArray<hkVector4f,hkContainerHeapAllocator> *v40; // rdx
  hkArray<hkVector4f,hkContainerHeapAllocator> *v41; // rdx
  hkVector4f v42; // xmm1
  hk1AxisSweep::AabbInt *v43; // rdx
  hkMemoryAllocatorVtbl *v44; // rax
  hkContainerTempAllocator::Allocator *v45; // rcx
  int v46; // er15
  int v47; // er9
  signed __int64 v48; // rdi
  signed int v49; // er12
  hkaiEdgeGeometry *v50; // r13
  int v51; // edi
  int v52; // eax
  int v53; // eax
  int v54; // er9
  int v55; // er8
  int v57; // eax
  __m128 *v58; // r8
  __m128 *v59; // r9
  __int64 v60; // r10
  int v61; // edx
  int v62; // edi
  int v63; // eax
  int v64; // eax
  __m128 *v65; // r10
  __m128 *v66; // r8
  __int64 v67; // r11
  int v68; // edx
  int v69; // edi
  int v70; // eax
  hkArray<hk1AxisSweep::AabbInt,hkContainerTempAllocator> faceAabbsOut; // [rsp+30h] [rbp-91h]
  hkArray<hk1AxisSweep::AabbInt,hkContainerTempAllocator> edgeAabbs; // [rsp+40h] [rbp-81h]
  hkResult v73; // [rsp+50h] [rbp-71h]
  hkAabb otherAabb; // [rsp+60h] [rbp-61h]
  hk1AxisSweep::AabbInt *array; // [rsp+80h] [rbp-41h]
  int v76; // [rsp+88h] [rbp-39h]
  hkaiEdgeGeometry *geom; // [rsp+8Ch] [rbp-35h]
  hkResult *v78; // [rsp+118h] [rbp+57h]
  hkResult resulta; // [rsp+128h] [rbp+67h]

  v78 = result;
  v7 = b;
  v8 = a;
  v9 = result;
  v10 = this;
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
    hkaiBooleanOperation::_setGeometry(v10, &resulta, &v10->m_b, v7);
    if ( resulta.m_enum == HK_SUCCESS )
    {
      v12 = filter;
      v13 = (signed __int64)&v10->m_a.m_faceEdges;
      filter->vfptr->setFaceEdges(filter, &v73, &v10->m_a.m_faceEdges, &v10->m_b.m_faceEdges);
      if ( v73.m_enum == HK_SUCCESS )
      {
        v14 = geomOut;
        geomOut->m_edges.m_size = 0;
        v15 = v8->m_faces.m_size;
        if ( (v14->m_faces.m_capacityAndFlags & 0x3FFFFFFF) >= v15 )
        {
          resulta.m_enum = 0;
          goto LABEL_13;
        }
        hkArrayUtil::_reserve(
          &resulta,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          &v14->m_faces,
          v15,
          12);
        if ( resulta.m_enum == HK_SUCCESS )
        {
LABEL_13:
          v16 = v14->m_faces.m_capacityAndFlags & 0x3FFFFFFF;
          if ( v16 < v8->m_faces.m_size )
          {
            if ( v14->m_faces.m_capacityAndFlags >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                v14->m_faces.m_data,
                12 * v16);
            v73.m_enum = 12 * v8->m_faces.m_size;
            v14->m_faces.m_data = (hkaiEdgeGeometry::Face *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                                              (int *)&v73);
            v14->m_faces.m_capacityAndFlags = v73.m_enum / 12;
          }
          v17 = v8->m_faces.m_size;
          v18 = v14->m_faces.m_data;
          v14->m_faces.m_size = v17;
          v19 = v17;
          if ( (signed int)v17 > 0 )
          {
            v20 = (char *)((char *)v8->m_faces.m_data - (char *)v18);
            do
            {
              v21 = *(unsigned int *)((char *)&v18->m_data + (_QWORD)v20);
              ++v18;
              v18[-1].m_data = v21;
              v18[-1].m_faceIndex = *(_DWORD *)((char *)v18 + (_QWORD)v20 - 8);
              *(_DWORD *)&v18[-1].m_flags.m_storage = *(_DWORD *)((char *)v18 + (_QWORD)v20 - 4);
              --v19;
            }
            while ( v19 );
          }
          if ( resulta.m_enum )
            goto LABEL_41;
          v22 = &v10->m_edgeAIntersected;
          v23 = v10->m_a.m_geometry->m_edges.m_size;
          if ( v10 != (hkaiBooleanOperation *)-256i64 )
          {
            v10->m_edgeAIntersected.m_storage.m_words.m_capacityAndFlags = 2147483648;
            v24 = (v23 + 31) >> 5;
            v22->m_storage.m_words.m_data = 0i64;
            v10->m_edgeAIntersected.m_storage.m_words.m_size = 0;
            v25 = v24;
            if ( v24 )
            {
              resulta.m_enum = 4 * v24;
              v26 = (unsigned int *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                      (int *)&resulta);
              v25 = resulta.m_enum / 4;
            }
            else
            {
              v26 = 0i64;
            }
            v22->m_storage.m_words.m_data = v26;
            v10->m_edgeAIntersected.m_storage.m_words.m_size = v24;
            v27 = 2147483648;
            if ( v25 )
              v27 = v25;
            v10->m_edgeAIntersected.m_storage.m_words.m_capacityAndFlags = v27;
            v10->m_edgeAIntersected.m_storage.m_numBits = v23;
            v28 = v10->m_edgeAIntersected.m_storage.m_words.m_capacityAndFlags & 0x3FFFFFFF;
            if ( v28 < v24 )
            {
              v29 = 2 * v28;
              v30 = (v23 + 31) >> 5;
              if ( v24 < v29 )
                v30 = v29;
              hkArrayUtil::_reserve(
                &v73,
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                &v10->m_edgeAIntersected,
                v30,
                4);
            }
            v10->m_edgeAIntersected.m_storage.m_words.m_size = v24;
            v13 = (signed __int64)&v10->m_a.m_faceEdges;
          }
          if ( !v22->m_storage.m_words.m_data )
            goto LABEL_41;
          if ( v10->m_edgeAIntersected.m_storage.m_words.m_size - 1 >= 0 )
          {
            v31 = (unsigned int)v10->m_edgeAIntersected.m_storage.m_words.m_size;
            v32 = v22->m_storage.m_words.m_data;
            while ( v31 )
            {
              *v32 = 0;
              ++v32;
              --v31;
            }
          }
          v33 = v10->m_a.m_geometry->m_edges.m_size;
          v34 = v10->m_b.m_uniqueEdges.m_startUniqueEdge.m_size;
          v10->m_edgeBFeatureBase = v33;
          v35 = v34 - 1 + v33;
          v10->m_faceFaceFeatureBase = v35;
          v10->m_faceFaceFeatureCount = v35;
          hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::clear((hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v10->m_faceFaceFeatureMap.m_map.m_elem);
          v10->m_intersectBase = v8->m_vertices.m_size;
          if ( v10->m_a.m_faceEdges.m_faceStartEdges.m_size == 3 && v10->m_a.m_geometry->m_edges.m_size == 3 )
          {
            hkaiBooleanOperation::_simpleClassifyEdgeAFaceB(v10, &resulta, v12);
            if ( resulta.m_enum )
              goto LABEL_41;
            hkaiBooleanOperation::_simpleClassifyFaceAEdgeB(v10, &resulta, v12);
            if ( resulta.m_enum )
              goto LABEL_41;
LABEL_65:
            v46 = *(_DWORD *)(v13 + 24);
            v76 = 0;
            LODWORD(v13) = v46 - 1;
            array = (hk1AxisSweep::AabbInt *)((char *)&geom + 4);
            LODWORD(geom) = -2147483644;
            if ( (signed int)v13 <= 4 )
            {
              resulta.m_enum = 0;
            }
            else
            {
              v47 = v13;
              if ( (signed int)v13 < 8 )
                v47 = 8;
              hkArrayUtil::_reserve(
                &resulta,
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                &array,
                v47,
                16);
              if ( resulta.m_enum )
              {
                v76 = 0;
LABEL_80:
                v55 = (signed int)geom;
                v9->m_enum = 1;
LABEL_81:
                if ( v55 < 0 )
                  return v9;
                v44 = hkContainerHeapAllocator::s_alloc.vfptr;
                v43 = array;
                v45 = (hkContainerTempAllocator::Allocator *)&hkContainerHeapAllocator::s_alloc;
                goto LABEL_83;
              }
            }
            v48 = 1i64;
            v76 = v13;
            v13 = (signed int)v13;
            v49 = 1;
            if ( (signed int)v13 > 1i64 )
            {
              do
              {
                hkaiEdgeGeometry::calculateFaceNormal(
                  v8,
                  v10->m_a.m_faceEdges.m_faceStartEdges.m_data[v48],
                  v10->m_a.m_faceEdges.m_faceStartEdges.m_data[v48 + 1],
                  (hkVector4f *)array + v49);
                ++v48;
                ++v49;
              }
              while ( v48 < v13 );
              v9 = v78;
            }
            v50 = geomOut;
            hkaiBooleanOperation::_addCompleteEdges(v10, &resulta, filter, geomOut);
            if ( resulta.m_enum == HK_SUCCESS )
            {
              v51 = v10->m_intersectVertices.m_size + v8->m_vertices.m_size;
              v52 = v50->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
              if ( v52 >= v51 )
              {
                resulta.m_enum = 0;
              }
              else
              {
                v53 = 2 * v52;
                v54 = v10->m_intersectVertices.m_size + v8->m_vertices.m_size;
                if ( v51 < v53 )
                  v54 = v53;
                hkArrayUtil::_reserve(
                  &resulta,
                  (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                  &v50->m_vertices,
                  v54,
                  16);
                if ( resulta.m_enum )
                  goto LABEL_79;
              }
              v50->m_vertices.m_size = v51;
              v57 = v8->m_vertices.m_size;
              v58 = &v8->m_vertices.m_data->m_quad;
              v59 = &v50->m_vertices.m_data->m_quad;
              if ( v57 > 0 )
              {
                v60 = (unsigned int)v57;
                do
                {
                  v61 = v58->m128_u64[1];
                  v62 = HIDWORD(v58->m128_u64[1]);
                  v63 = v58->m128_u64[0];
                  HIDWORD(v59->m128_u64[0]) = HIDWORD(v58->m128_u64[0]);
                  LODWORD(v59->m128_u64[1]) = v61;
                  HIDWORD(v59->m128_u64[1]) = v62;
                  LODWORD(v59->m128_u64[0]) = v63;
                  ++v59;
                  ++v58;
                  --v60;
                }
                while ( v60 );
              }
              v64 = v10->m_intersectVertices.m_size;
              v65 = &v10->m_intersectVertices.m_data->m_quad;
              v66 = &v50->m_vertices.m_data[v8->m_vertices.m_size].m_quad;
              if ( v64 > 0 )
              {
                v67 = (unsigned int)v64;
                do
                {
                  v68 = v65->m128_u64[1];
                  v69 = HIDWORD(v65->m128_u64[1]);
                  v70 = v65->m128_u64[0];
                  HIDWORD(v66->m128_u64[0]) = HIDWORD(v65->m128_u64[0]);
                  LODWORD(v66->m128_u64[1]) = v68;
                  HIDWORD(v66->m128_u64[1]) = v69;
                  LODWORD(v66->m128_u64[0]) = v70;
                  ++v66;
                  ++v65;
                  --v67;
                }
                while ( v67 );
              }
              hkaiBooleanOperation::_addPartialEdges(
                v10,
                &resulta,
                (hkArray<hkVector4f,hkContainerHeapAllocator> *)&array,
                v50,
                intersects);
              v55 = (signed int)geom;
              v76 = 0;
              if ( resulta.m_enum )
                v9->m_enum = 1;
              else
                v9->m_enum = 0;
              goto LABEL_81;
            }
LABEL_79:
            v76 = 0;
            goto LABEL_80;
          }
          v36 = &v10->m_a.m_geometry->m_vertices;
          edgeAabbs.m_data = 0i64;
          edgeAabbs.m_size = 0;
          edgeAabbs.m_capacityAndFlags = 2147483648;
          hkaiBooleanOperation::_calculateEdgeAabbs(
            &resulta,
            v36,
            &v10->m_a.m_uniqueEdges,
            &v10->m_b.m_aabb,
            &edgeAabbs);
          if ( resulta.m_enum )
          {
            v9->m_enum = 1;
LABEL_59:
            edgeAabbs.m_size = 0;
            if ( edgeAabbs.m_capacityAndFlags < 0 )
              return v9;
            v43 = edgeAabbs.m_data;
            v44 = hkContainerTempAllocator::s_alloc.vfptr;
            v45 = &hkContainerTempAllocator::s_alloc;
LABEL_83:
            ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, hk1AxisSweep::AabbInt *))v44->bufFree)(
              v45,
              v43);
            return v9;
          }
          v37 = (hkArray<hkVector4f,hkContainerHeapAllocator> *)v10->m_b.m_geometry;
          v38.m_quad = (__m128)v10->m_a.m_aabb.m_max;
          otherAabb.m_min = v10->m_a.m_aabb.m_min;
          otherAabb.m_max = (hkVector4f)v38.m_quad;
          faceAabbsOut.m_data = 0i64;
          faceAabbsOut.m_size = 0;
          faceAabbsOut.m_capacityAndFlags = 2147483648;
          otherAabb.m_max.m_quad.m128_i32[2] = 2139095022;
          otherAabb.m_min.m_quad.m128_i32[2] = -8388626;
          hkaiBooleanOperation::_calculateFaceAabbs(&resulta, v37 + 3, &v10->m_b.m_faceEdges, &otherAabb, &faceAabbsOut);
          if ( resulta.m_enum )
          {
            v39 = faceAabbsOut.m_capacityAndFlags;
            faceAabbsOut.m_size = 0;
          }
          else
          {
            hkaiBooleanOperation::_sweepAndPruneClassifyEdgeAFaceB(v10, &resulta, v12, &edgeAabbs, &faceAabbsOut);
            v39 = faceAabbsOut.m_capacityAndFlags;
            faceAabbsOut.m_size = 0;
            if ( resulta.m_enum == HK_SUCCESS )
            {
              if ( faceAabbsOut.m_capacityAndFlags >= 0 )
                hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                  (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                  faceAabbsOut.m_data,
                  32 * faceAabbsOut.m_capacityAndFlags);
              faceAabbsOut.m_data = 0i64;
              faceAabbsOut.m_capacityAndFlags = 2147483648;
              edgeAabbs.m_size = 0;
              if ( edgeAabbs.m_capacityAndFlags >= 0 )
                hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                  (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                  edgeAabbs.m_data,
                  32 * edgeAabbs.m_capacityAndFlags);
              v40 = &v10->m_b.m_geometry->m_vertices;
              edgeAabbs.m_data = 0i64;
              edgeAabbs.m_size = 0;
              edgeAabbs.m_capacityAndFlags = 2147483648;
              hkaiBooleanOperation::_calculateEdgeAabbs(
                &resulta,
                v40,
                &v10->m_b.m_uniqueEdges,
                &v10->m_a.m_aabb,
                &edgeAabbs);
              if ( resulta.m_enum )
              {
                v9->m_enum = 1;
                goto LABEL_59;
              }
              v41 = (hkArray<hkVector4f,hkContainerHeapAllocator> *)v10->m_a.m_geometry;
              v42.m_quad = (__m128)v10->m_b.m_aabb.m_max;
              v13 = (signed __int64)&v10->m_a.m_faceEdges;
              otherAabb.m_min = v10->m_b.m_aabb.m_min;
              otherAabb.m_max = (hkVector4f)v42.m_quad;
              faceAabbsOut.m_data = 0i64;
              faceAabbsOut.m_size = 0;
              faceAabbsOut.m_capacityAndFlags = 2147483648;
              otherAabb.m_max.m_quad.m128_i32[2] = 2139095022;
              otherAabb.m_min.m_quad.m128_i32[2] = -8388626;
              hkaiBooleanOperation::_calculateFaceAabbs(
                &resulta,
                v41 + 3,
                &v10->m_a.m_faceEdges,
                &otherAabb,
                &faceAabbsOut);
              if ( resulta.m_enum )
              {
                v39 = faceAabbsOut.m_capacityAndFlags;
                faceAabbsOut.m_size = 0;
              }
              else
              {
                hkaiBooleanOperation::_sweepAndPruneClassifyFaceAEdgeB(v10, &resulta, v12, &faceAabbsOut, &edgeAabbs);
                v39 = faceAabbsOut.m_capacityAndFlags;
                faceAabbsOut.m_size = 0;
                if ( resulta.m_enum == HK_SUCCESS )
                {
                  if ( faceAabbsOut.m_capacityAndFlags >= 0 )
                    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                      faceAabbsOut.m_data,
                      32 * faceAabbsOut.m_capacityAndFlags);
                  faceAabbsOut.m_data = 0i64;
                  faceAabbsOut.m_capacityAndFlags = 2147483648;
                  edgeAabbs.m_size = 0;
                  if ( edgeAabbs.m_capacityAndFlags >= 0 )
                    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                      edgeAabbs.m_data,
                      32 * edgeAabbs.m_capacityAndFlags);
                  goto LABEL_65;
                }
              }
            }
          }
          v9->m_enum = 1;
          if ( v39 >= 0 )
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
              faceAabbsOut.m_data,
              32 * v39);
          faceAabbsOut.m_data = 0i64;
          faceAabbsOut.m_capacityAndFlags = 2147483648;
          goto LABEL_59;
        }
      }
LABEL_41:
      v9->m_enum = 1;
      return v9;
    }
  }
  v9->m_enum = 1;
  return v9;
}

// File Line: 2153
// RVA: 0xB9F860
void __fastcall hkaiBooleanOperation::GeometricInfo::clear(hkaiBooleanOperation::GeometricInfo *this)
{
  hkaiBooleanOperation::GeometricInfo *v1; // rbx
  hkaiUniqueEdges *v2; // rcx

  v1 = this;
  v2 = &this->m_uniqueEdges;
  v2[-1].m_startUniqueEdge.m_data = 0i64;
  *(_QWORD *)&v2[-1].m_startUniqueEdge.m_size = 0i64;
  hkaiUniqueEdges::clear(v2);
  hkaiFaceEdges::clear(&v1->m_faceEdges);
  v1->m_aabb.m_min = (hkVector4f)xmmword_141A712A0;
  v1->m_aabb.m_max.m_quad = _mm_xor_ps(
                              (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                              v1->m_aabb.m_min.m_quad);
}

// File Line: 2165
// RVA: 0xBA3CD0
void __fastcall hkaiBooleanOperation::clear(hkaiBooleanOperation *this)
{
  hkaiBooleanOperation *v1; // rbx
  int v2; // er8

  v1 = this;
  hkaiBooleanOperation::GeometricInfo::clear(&this->m_a);
  hkaiBooleanOperation::GeometricInfo::clear(&v1->m_b);
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::clear((hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v1->m_faceFaceFeatureMap.m_map.m_elem);
  *(_QWORD *)&v1->m_faceFaceFeatureCount = 0i64;
  *(_QWORD *)&v1->m_edgeBFeatureBase = 0i64;
  v1->m_edgeAIntersected.m_storage.m_numBits = 0;
  v2 = v1->m_edgeAIntersected.m_storage.m_words.m_capacityAndFlags;
  v1->m_edgeAIntersected.m_storage.m_words.m_size = 0;
  if ( v2 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_edgeAIntersected.m_storage.m_words.m_data,
      4 * v2);
  v1->m_edgeAIntersected.m_storage.m_words.m_data = 0i64;
  v1->m_edgeAIntersected.m_storage.m_words.m_capacityAndFlags = 2147483648;
  v1->m_intersectVertices.m_size = 0;
  v1->m_startVertices.m_size = 0;
  v1->m_endVertices.m_size = 0;
}

