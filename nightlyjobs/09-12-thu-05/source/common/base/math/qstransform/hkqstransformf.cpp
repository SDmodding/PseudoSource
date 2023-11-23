// File Line: 14
// RVA: 0xC54420
void __fastcall hkQsTransformf::fastRenormalizeQuaternionBatch(hkQsTransformf *poseOut, unsigned int numTransforms)
{
  __int64 v2; // r8
  hkQuaternionf v3; // xmm6
  __m128 v4; // xmm1
  __m128 v5; // xmm2
  hkQuaternionf v6; // xmm0
  __m128 v7; // xmm5
  __m128 v8; // xmm0
  __m128 v9; // xmm4
  __m128 v10; // xmm5
  __m128 v11; // xmm1
  __m128 v12; // xmm2
  __m128 v13; // xmm3
  __m128 v14; // xmm2
  __m128 v15; // xmm4
  unsigned int v16; // edx
  hkQuaternionf *p_m_rotation; // rax
  __int64 v18; // rcx
  __m128 m_quad; // xmm3
  __m128 v20; // xmm0
  __m128 v21; // xmm2
  __m128 v22; // xmm1
  __m128 v23; // xmm2

  if ( numTransforms >> 2 )
  {
    v2 = numTransforms >> 2;
    do
    {
      v3.m_vec.m_quad = (__m128)poseOut->m_rotation;
      v4 = _mm_mul_ps(poseOut[1].m_rotation.m_vec.m_quad, poseOut[1].m_rotation.m_vec.m_quad);
      v5 = _mm_mul_ps(poseOut[2].m_rotation.m_vec.m_quad, poseOut[2].m_rotation.m_vec.m_quad);
      v6.m_vec.m_quad = (__m128)poseOut[3].m_rotation;
      poseOut += 4;
      v7 = _mm_mul_ps(v3.m_vec.m_quad, v3.m_vec.m_quad);
      v8 = _mm_mul_ps(v6.m_vec.m_quad, v6.m_vec.m_quad);
      v9 = _mm_shuffle_ps(v7, v4, 68);
      v10 = _mm_shuffle_ps(v7, v4, 238);
      v11 = _mm_shuffle_ps(v5, v8, 68);
      v12 = _mm_shuffle_ps(v5, v8, 238);
      v13 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v10, v12, 221), _mm_shuffle_ps(v10, v12, 136)),
              _mm_add_ps(_mm_shuffle_ps(v9, v11, 221), _mm_shuffle_ps(v9, v11, 136)));
      v14 = _mm_rsqrt_ps(v13);
      v15 = _mm_andnot_ps(
              _mm_cmple_ps(v13, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v14, v13), v14)),
                _mm_mul_ps(*(__m128 *)_xmm, v14)));
      poseOut[-4].m_rotation.m_vec.m_quad = _mm_mul_ps(_mm_shuffle_ps(v15, v15, 0), v3.m_vec.m_quad);
      poseOut[-3].m_rotation.m_vec.m_quad = _mm_mul_ps(
                                              _mm_shuffle_ps(v15, v15, 85),
                                              poseOut[-3].m_rotation.m_vec.m_quad);
      poseOut[-2].m_rotation.m_vec.m_quad = _mm_mul_ps(
                                              _mm_shuffle_ps(v15, v15, 170),
                                              poseOut[-2].m_rotation.m_vec.m_quad);
      poseOut[-1].m_rotation.m_vec.m_quad = _mm_mul_ps(
                                              _mm_shuffle_ps(v15, v15, 255),
                                              poseOut[-1].m_rotation.m_vec.m_quad);
      --v2;
    }
    while ( v2 );
  }
  v16 = numTransforms & 3;
  if ( v16 )
  {
    p_m_rotation = &poseOut->m_rotation;
    v18 = v16;
    do
    {
      m_quad = p_m_rotation->m_vec.m_quad;
      p_m_rotation += 3;
      v20 = _mm_mul_ps(m_quad, m_quad);
      v21 = _mm_add_ps(_mm_shuffle_ps(v20, v20, 78), v20);
      v22 = _mm_add_ps(_mm_shuffle_ps(v21, v21, 177), v21);
      v23 = _mm_rsqrt_ps(v22);
      p_m_rotation[-3].m_vec.m_quad = _mm_mul_ps(
                                        m_quad,
                                        _mm_mul_ps(
                                          _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v23, v22), v23)),
                                          _mm_mul_ps(*(__m128 *)_xmm, v23)));
      --v18;
    }
    while ( v18 );
  }
}

// File Line: 46
// RVA: 0xC54330
void __fastcall hkQsTransformf::fastRenormalizeBatch(
        hkQsTransformf *poseOut,
        float *weight,
        unsigned int numTransforms)
{
  hkQsTransformf *v3; // rax
  __int64 v4; // r9
  __m128 v5; // xmm1
  __m128 v6; // xmm1
  __m128 v7; // xmm0
  __m128 v8; // xmm2

  if ( numTransforms )
  {
    v3 = poseOut;
    v4 = numTransforms;
    do
    {
      v5 = (__m128)*(unsigned int *)weight;
      ++v3;
      ++weight;
      v6 = _mm_shuffle_ps(v5, v5, 0);
      v7 = _mm_rcp_ps(v6);
      v8 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v6, v7)), v7);
      v3[-1].m_translation.m_quad = _mm_mul_ps(v3[-1].m_translation.m_quad, v8);
      v3[-1].m_scale.m_quad = _mm_mul_ps(v3[-1].m_scale.m_quad, v8);
      --v4;
    }
    while ( v4 );
  }
  hkQsTransformf::fastRenormalizeQuaternionBatch(poseOut, numTransforms);
}

// File Line: 59
// RVA: 0xC543A0
void __fastcall hkQsTransformf::fastRenormalizeBatch(hkQsTransformf *poseOut, float weight, unsigned int numTransforms)
{
  __m128 v4; // xmm1
  __m128 v5; // xmm0
  __m128 v6; // xmm2
  hkQsTransformf *v7; // rax
  __int64 v8; // rcx
  __m128 m_quad; // xmm0

  v4 = _mm_shuffle_ps((__m128)LODWORD(weight), (__m128)LODWORD(weight), 0);
  v5 = _mm_rcp_ps(v4);
  v6 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v4, v5)), v5);
  if ( numTransforms )
  {
    v7 = poseOut;
    v8 = numTransforms;
    do
    {
      m_quad = v7->m_translation.m_quad;
      ++v7;
      v7[-1].m_translation.m_quad = _mm_mul_ps(m_quad, v6);
      v7[-1].m_scale.m_quad = _mm_mul_ps(v7[-1].m_scale.m_quad, v6);
      --v8;
    }
    while ( v8 );
  }
  hkQsTransformf::fastRenormalizeQuaternionBatch(poseOut, numTransforms);
}

// File Line: 73
// RVA: 0xC54090
void __fastcall hkQsTransformf::get4x4ColumnMajor(hkQsTransformf *this, float *d)
{
  hkVector4f v4; // xmm1
  hkVector4f v5; // xmm1
  hkMatrix3f v6; // [rsp+20h] [rbp-D8h] BYREF
  hkMatrix3f bTc; // [rsp+50h] [rbp-A8h] BYREF
  hkTransformf v8; // [rsp+80h] [rbp-78h] BYREF
  hkRotationf v9; // [rsp+C0h] [rbp-38h] BYREF

  hkRotationf::set(&v9, &this->m_rotation);
  v4.m_quad = (__m128)this->m_scale;
  bTc.m_col2.m_quad = _mm_mul_ps(v4.m_quad, stru_141A71280.m_quad);
  bTc.m_col0.m_quad = _mm_mul_ps(v4.m_quad, transform.m_quad);
  bTc.m_col1.m_quad = _mm_mul_ps(v4.m_quad, direction.m_quad);
  hkMatrix3f::setMul(&v6, &v9, &bTc);
  v8.m_rotation.m_col0 = v6.m_col0;
  v8.m_rotation.m_col1 = v6.m_col1;
  v5.m_quad = (__m128)this->m_translation;
  v8.m_rotation.m_col2 = v6.m_col2;
  v8.m_translation = (hkVector4f)v5.m_quad;
  hkTransformf::get4x4ColumnMajor(&v8, d);
}

// File Line: 93
// RVA: 0xC54160
_BOOL8 __fastcall hkQsTransformf::set4x4ColumnMajor(hkQsTransformf *this, const float *p)
{
  hkQuaternionf v3; // xmm1
  _BOOL8 result; // rax
  hkVector4f v5; // xmm0
  hkMatrixDecompositionImpl<float>::Decomposition decompOut; // [rsp+20h] [rbp-F8h] BYREF

  hkMatrixDecompositionImpl<float>::decompose4x4ColTransform(p, &decompOut);
  v3.m_vec.m_quad = (__m128)decompOut.m_rotation;
  result = decompOut.m_hasSkew.m_bool == 0;
  this->m_translation = decompOut.m_translation;
  v5.m_quad = (__m128)decompOut.m_scale;
  this->m_rotation = (hkQuaternionf)v3.m_vec.m_quad;
  this->m_scale = (hkVector4f)v5.m_quad;
  return result;
}

// File Line: 103
// RVA: 0xC541C0
_BOOL8 __fastcall hkQsTransformf::set(hkQsTransformf *this, hkMatrix4f *m)
{
  hkQuaternionf v3; // xmm1
  _BOOL8 result; // rax
  hkVector4f v5; // xmm0
  hkMatrixDecompositionImpl<float>::Decomposition decompOut; // [rsp+20h] [rbp-F8h] BYREF

  hkMatrixDecompositionImpl<float>::decomposeMatrix(m, &decompOut);
  v3.m_vec.m_quad = (__m128)decompOut.m_rotation;
  result = decompOut.m_hasSkew.m_bool == 0;
  this->m_translation = decompOut.m_translation;
  v5.m_quad = (__m128)decompOut.m_scale;
  this->m_rotation = (hkQuaternionf)v3.m_vec.m_quad;
  this->m_scale = (hkVector4f)v5.m_quad;
  return result;
}

// File Line: 113
// RVA: 0xC53FD0
void __fastcall hkQsTransformf::setFromTransformNoScale(hkQsTransformf *this, hkTransformf *transform)
{
  hkQuaternionf::set(&this->m_rotation, &transform->m_rotation);
  this->m_translation = transform->m_translation;
  this->m_scale = (hkVector4f)query.m_quad;
}

// File Line: 120
// RVA: 0xC54010
void __fastcall hkQsTransformf::copyToTransformNoScale(hkQsTransformf *this, hkTransformf *transformOut)
{
  hkRotationf::set(&transformOut->m_rotation, &this->m_rotation);
  transformOut->m_translation = this->m_translation;
}

// File Line: 125
// RVA: 0xC54050
// attributes: thunk
void __fastcall hkQsTransformf::setFromTransform(hkQsTransformf *this, hkTransformf *transform)
{
  hkQsTransformf::set4x4ColumnMajor(this, transform->m_rotation.m_col0.m_quad.m128_f32);
}

// File Line: 133
// RVA: 0xC54060
void __fastcall hkQsTransformf::setFromTransform(hkQsTransformf *this, hkQTransformf *qt)
{
  this->m_rotation = qt->m_rotation;
  this->m_translation = qt->m_translation;
  this->m_scale = (hkVector4f)query.m_quad;
}

// File Line: 140
// RVA: 0xC54080
// attributes: thunk
void __fastcall hkQsTransformf::copyToTransform(hkQsTransformf *this, hkTransformf *transformOut)
{
  hkQsTransformf::get4x4ColumnMajor(this, transformOut->m_rotation.m_col0.m_quad.m128_f32);
}

// File Line: 146
// RVA: 0xC54220
bool __fastcall hkQsTransformf::isOk(hkQsTransformf *this, float epsilon)
{
  __m128 v2; // xmm6
  __m128 v3; // xmm7
  bool v4; // cl

  v2 = _mm_cmpunord_ps(this->m_translation.m_quad, this->m_translation.m_quad);
  v3 = _mm_cmpunord_ps(this->m_scale.m_quad, this->m_scale.m_quad);
  v4 = hkQuaternionf::isOk(&this->m_rotation, epsilon) != 0;
  return (_mm_movemask_ps(v2) & 7) == 0 && (_mm_movemask_ps(v3) & 7) == 0 && v4;
}

// File Line: 154
// RVA: 0xC54290
bool __fastcall hkQsTransformf::isApproximatelyEqual(hkQsTransformf *this, hkQsTransformf *other, float epsilon)
{
  hkQuaternionf v3; // xmm3
  __m128 v4; // xmm0
  __m128 v5; // xmm4
  __m128 v6; // xmm1

  v3.m_vec.m_quad = (__m128)this->m_rotation;
  v4 = _mm_mul_ps(other->m_rotation.m_vec.m_quad, v3.m_vec.m_quad);
  v5 = _mm_shuffle_ps((__m128)LODWORD(epsilon), (__m128)LODWORD(epsilon), 0);
  v6 = _mm_add_ps(_mm_shuffle_ps(v4, v4, 78), v4);
  return _mm_movemask_ps(
           _mm_cmplt_ps(
             (__m128)_mm_srli_epi32(
                       _mm_slli_epi32(
                         (__m128i)_mm_sub_ps(
                                    v3.m_vec.m_quad,
                                    _mm_xor_ps(
                                      (__m128)_mm_slli_epi32(
                                                _mm_srli_epi32(
                                                  (__m128i)_mm_add_ps(_mm_shuffle_ps(v6, v6, 177), v6),
                                                  0x1Fu),
                                                0x1Fu),
                                      other->m_rotation.m_vec.m_quad)),
                         1u),
                       1u),
             v5)) == 15
      && (_mm_movemask_ps(
            _mm_cmplt_ps(
              (__m128)_mm_srli_epi32(
                        _mm_slli_epi32((__m128i)_mm_sub_ps(this->m_translation.m_quad, other->m_translation.m_quad), 1u),
                        1u),
              v5)) & 7) == 7
      && (_mm_movemask_ps(
            _mm_cmplt_ps(
              (__m128)_mm_srli_epi32(
                        _mm_slli_epi32((__m128i)_mm_sub_ps(this->m_scale.m_quad, other->m_scale.m_quad), 1u),
                        1u),
              v5)) & 7) == 7;
}

