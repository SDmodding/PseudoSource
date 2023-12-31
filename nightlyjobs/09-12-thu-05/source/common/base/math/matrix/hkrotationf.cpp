// File Line: 12
// RVA: 0xC5AA10
void __fastcall hkRotationf::set(hkRotationf *this, hkQuaternionf *qi)
{
  __m128 m_quad; // xmm6
  __m128 v3; // xmm3
  float v4; // xmm4_4
  __m128 v5; // xmm1
  __m128 v6; // xmm5
  __m128 v7; // xmm6
  __m128 v8; // xmm2
  hkVector4f v9; // xmm1
  __m128 v10; // xmm0
  hkVector4f v11; // xmm0

  m_quad = qi->m_vec.m_quad;
  v3 = _mm_add_ps(m_quad, m_quad);
  v4 = COERCE_FLOAT(*qi) * v3.m128_f32[0];
  v5 = _mm_mul_ps(_mm_shuffle_ps(v3, v3, 165), _mm_shuffle_ps(qi->m_vec.m_quad, qi->m_vec.m_quad, 65));
  v6 = transform.m_quad;
  v7 = _mm_xor_ps(
         _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 254), _mm_shuffle_ps(v3, v3, 26)),
         (__m128)`hkVector4UtilImpl<float>::convertQuaternionToRotation::`2::negateMask1);
  v8 = _mm_xor_ps((__m128)`hkVector4UtilImpl<float>::convertQuaternionToRotation::`2::negateMask0, v5);
  v6.m128_f32[0] = (float)(1.0 - v4) - v5.m128_f32[0];
  v7.m128_f32[0] = v7.m128_f32[0] + 1.0;
  v9.m_quad = _mm_sub_ps(v7, v8);
  v8.m128_f32[0] = v4;
  this->m_col0 = (hkVector4f)v9.m_quad;
  v10 = _mm_sub_ps(
          _mm_xor_ps((__m128)`hkVector4UtilImpl<float>::convertQuaternionToRotation::`2::negateMask0, v7),
          v8);
  v11.m_quad = _mm_shuffle_ps(v10, v10, 177);
  this->m_col1 = (hkVector4f)v11.m_quad;
  this->m_col2.m_quad = _mm_shuffle_ps(_mm_movehl_ps(v9.m_quad, v11.m_quad), v6, 141);
}

// File Line: 18
// RVA: 0xC5AAB0
void __fastcall hkRotationf::setAxisAngle(hkRotationf *this, hkVector4f *axis, float angle)
{
  hkQuaternionf qi; // [rsp+20h] [rbp-18h] BYREF

  hkQuaternionf::setAxisAngle(&qi, axis, angle);
  hkRotationf::set(this, &qi);
}

// File Line: 25
// RVA: 0xC5AAE0
void __fastcall hkRotationf::setAxisAngle(hkRotationf *this, hkVector4f *axis, hkSimdFloat32 *angle)
{
  hkQuaternionf qi; // [rsp+20h] [rbp-18h] BYREF

  hkQuaternionf::setAxisAngle(&qi, axis, angle);
  hkRotationf::set(this, &qi);
}

// File Line: 32
// RVA: 0xC5AB10
bool __fastcall hkRotationf::isOrthonormal(hkRotationf *this, float epsilon)
{
  hkVector4f v2; // xmm4
  __m128 v3; // xmm3
  __m128 v4; // xmm1
  hkVector4f v6; // xmm5
  __m128 v7; // xmm1
  hkVector4f v8; // xmm7
  __m128 v9; // xmm1
  __m128 v10; // xmm0

  v2.m_quad = (__m128)this->m_col0;
  v3 = _mm_shuffle_ps((__m128)LODWORD(epsilon), (__m128)LODWORD(epsilon), 0);
  v4 = _mm_mul_ps(v2.m_quad, v2.m_quad);
  if ( (float)((float)((float)(_mm_shuffle_ps(v4, v4, 85).m128_f32[0] + _mm_shuffle_ps(v4, v4, 0).m128_f32[0])
                     + _mm_shuffle_ps(v4, v4, 170).m128_f32[0])
             - 1.0) > v3.m128_f32[0] )
    return 0;
  v6.m_quad = (__m128)this->m_col1;
  v7 = _mm_mul_ps(v6.m_quad, v6.m_quad);
  if ( (float)((float)((float)(_mm_shuffle_ps(v7, v7, 85).m128_f32[0] + _mm_shuffle_ps(v7, v7, 0).m128_f32[0])
                     + _mm_shuffle_ps(v7, v7, 170).m128_f32[0])
             - 1.0) > v3.m128_f32[0] )
    return 0;
  v8.m_quad = (__m128)this->m_col2;
  v9 = _mm_mul_ps(v8.m_quad, v8.m_quad);
  if ( (float)((float)((float)(_mm_shuffle_ps(v9, v9, 85).m128_f32[0] + _mm_shuffle_ps(v9, v9, 0).m128_f32[0])
                     + _mm_shuffle_ps(v9, v9, 170).m128_f32[0])
             - 1.0) > v3.m128_f32[0] )
    return 0;
  v10 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v6.m_quad, v6.m_quad, 201), v2.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(v2.m_quad, v2.m_quad, 201), v6.m_quad));
  return (_mm_movemask_ps(
            _mm_cmplt_ps(
              (__m128)_mm_srli_epi32(
                        _mm_slli_epi32((__m128i)_mm_sub_ps(_mm_shuffle_ps(v10, v10, 201), v8.m_quad), 1u),
                        1u),
              v3)) & 7) == 7;
}

// File Line: 68
// RVA: 0xC5AC10
bool __fastcall hkRotationf::isOk(hkRotationf *this)
{
  return hkRotationf::isOrthonormal(this, 0.0000099999997) && hkMatrix3f::isOk(this);
}

// File Line: 73
// RVA: 0xC5AC50
void __fastcall hkRotationf::renormalize(hkRotationf *this)
{
  float v1; // xmm3_4
  float v2; // xmm2_4
  float v3; // xmm4_4
  float v4; // xmm1_4
  float v5; // xmm0_4
  float v6; // xmm4_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  int v9; // edx
  __int64 v10; // r8
  __int64 v11; // r9
  float v12; // xmm2_4
  float v13; // xmm0_4
  __m128 v14; // xmm0
  __m128 v15; // xmm2
  __m128 v16; // xmm1
  __m128 v17; // xmm2
  hkQuaternionf qi; // [rsp+20h] [rbp-18h] BYREF

  v1 = this->m_col0.m_quad.m128_f32[0];
  v2 = this->m_col1.m_quad.m128_f32[1];
  v3 = this->m_col2.m_quad.m128_f32[2];
  v4 = (float)(this->m_col0.m_quad.m128_f32[0] + v2) + v3;
  if ( v4 <= 0.0 )
  {
    v9 = 0;
    qi.m_vec.m_quad.m128_i32[0] = 1;
    if ( v2 > v1 )
      v9 = 1;
    *(unsigned __int64 *)((char *)qi.m_vec.m_quad.m128_u64 + 4) = 2i64;
    if ( v3 > this->m_col0.m_quad.m128_f32[5 * v9] )
      v9 = 2;
    v10 = qi.m_vec.m_quad.m128_i32[v9];
    v11 = qi.m_vec.m_quad.m128_i32[v10];
    v12 = fsqrt(
            (float)(this->m_col0.m_quad.m128_f32[5 * v9]
                  - (float)(this->m_col0.m_quad.m128_f32[5 * v11] + this->m_col0.m_quad.m128_f32[5 * v10]))
          + 1.0);
    v13 = this->m_col0.m_quad.m128_f32[4 * v10 + v11] - this->m_col0.m_quad.m128_f32[4 * v11 + v10];
    qi.m_vec.m_quad.m128_f32[v9] = v12 * 0.5;
    qi.m_vec.m_quad.m128_f32[3] = v13 * (float)(0.5 / v12);
    qi.m_vec.m_quad.m128_f32[v10] = (float)(this->m_col0.m_quad.m128_f32[4 * v9 + v10]
                                          + this->m_col0.m_quad.m128_f32[4 * v10 + v9])
                                  * (float)(0.5 / v12);
    qi.m_vec.m_quad.m128_f32[v11] = (float)(this->m_col0.m_quad.m128_f32[4 * v11 + v9]
                                          + this->m_col0.m_quad.m128_f32[4 * v9 + v11])
                                  * (float)(0.5 / v12);
  }
  else
  {
    v5 = this->m_col1.m_quad.m128_f32[2] - this->m_col2.m_quad.m128_f32[1];
    v6 = fsqrt(v4 + 1.0);
    v7 = this->m_col2.m_quad.m128_f32[0] - this->m_col0.m_quad.m128_f32[2];
    qi.m_vec.m_quad.m128_f32[3] = v6 * 0.5;
    qi.m_vec.m_quad.m128_f32[0] = v5 * (float)(0.5 / v6);
    v8 = this->m_col0.m_quad.m128_f32[1];
    qi.m_vec.m_quad.m128_f32[1] = v7 * (float)(0.5 / v6);
    qi.m_vec.m_quad.m128_f32[2] = (float)(v8 - this->m_col1.m_quad.m128_f32[0]) * (float)(0.5 / v6);
  }
  v14 = _mm_mul_ps(qi.m_vec.m_quad, qi.m_vec.m_quad);
  v15 = _mm_add_ps(_mm_shuffle_ps(v14, v14, 78), v14);
  v16 = _mm_add_ps(_mm_shuffle_ps(v15, v15, 177), v15);
  v17 = _mm_rsqrt_ps(v16);
  qi.m_vec.m_quad = _mm_mul_ps(
                      qi.m_vec.m_quad,
                      _mm_mul_ps(
                        _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v17, v16), v17)),
                        _mm_mul_ps(*(__m128 *)_xmm, v17)));
  hkRotationf::set(this, &qi);
}

