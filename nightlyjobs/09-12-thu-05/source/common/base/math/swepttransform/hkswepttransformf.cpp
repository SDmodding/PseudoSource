// File Line: 13
// RVA: 0x12FE960
void __fastcall hkSweptTransformf::approxTransformAt(
        hkSweptTransformf *this,
        hkSimdFloat32 *time,
        hkTransformf *transformOut)
{
  __m128 v5; // xmm6
  __m128 v6; // xmm3
  __m128 v7; // xmm0
  __m128 v8; // xmm2
  __m128 v9; // xmm1
  __m128 v10; // xmm2
  hkVector4f v11; // xmm3
  hkVector4f v12; // xmm1
  hkQuaternionf qi; // [rsp+20h] [rbp-28h] BYREF

  v5 = _mm_mul_ps(
         _mm_sub_ps(time->m_real, _mm_shuffle_ps(this->m_centerOfMass0.m_quad, this->m_centerOfMass0.m_quad, 255)),
         _mm_shuffle_ps(this->m_centerOfMass1.m_quad, this->m_centerOfMass1.m_quad, 255));
  v6 = _mm_add_ps(
         _mm_mul_ps(_mm_sub_ps(this->m_rotation1.m_vec.m_quad, this->m_rotation0.m_vec.m_quad), v5),
         this->m_rotation0.m_vec.m_quad);
  v7 = _mm_mul_ps(v6, v6);
  v8 = _mm_add_ps(_mm_shuffle_ps(v7, v7, 78), v7);
  v9 = _mm_add_ps(_mm_shuffle_ps(v8, v8, 177), v8);
  v10 = _mm_rsqrt_ps(v9);
  qi.m_vec.m_quad = _mm_mul_ps(
                      v6,
                      _mm_mul_ps(
                        _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v10, v9), v10)),
                        _mm_mul_ps(*(__m128 *)_xmm, v10)));
  hkRotationf::set(&transformOut->m_rotation, &qi);
  v11.m_quad = _mm_add_ps(
                 _mm_mul_ps(_mm_sub_ps(this->m_centerOfMass1.m_quad, this->m_centerOfMass0.m_quad), v5),
                 this->m_centerOfMass0.m_quad);
  transformOut->m_translation = (hkVector4f)v11.m_quad;
  v12.m_quad = (__m128)this->m_centerOfMassLocal;
  transformOut->m_translation.m_quad = _mm_sub_ps(
                                         v11.m_quad,
                                         _mm_add_ps(
                                           _mm_add_ps(
                                             _mm_mul_ps(
                                               _mm_shuffle_ps(v12.m_quad, v12.m_quad, 85),
                                               transformOut->m_rotation.m_col1.m_quad),
                                             _mm_mul_ps(
                                               _mm_shuffle_ps(v12.m_quad, v12.m_quad, 0),
                                               transformOut->m_rotation.m_col0.m_quad)),
                                           _mm_mul_ps(
                                             _mm_shuffle_ps(v12.m_quad, v12.m_quad, 170),
                                             transformOut->m_rotation.m_col2.m_quad)));
}

// File Line: 34
// RVA: 0x12FE870
void __fastcall hkSweptTransformf::approxTransformAt(hkSweptTransformf *this, float time, hkTransformf *transformOut)
{
  __m128 v5; // xmm6
  __m128 v6; // xmm3
  __m128 v7; // xmm0
  __m128 v8; // xmm2
  __m128 v9; // xmm1
  __m128 v10; // xmm2
  hkVector4f v11; // xmm3
  hkVector4f v12; // xmm1
  hkQuaternionf qi; // [rsp+20h] [rbp-28h] BYREF

  v5 = _mm_mul_ps(
         _mm_sub_ps(
           _mm_shuffle_ps((__m128)LODWORD(time), (__m128)LODWORD(time), 0),
           _mm_shuffle_ps(this->m_centerOfMass0.m_quad, this->m_centerOfMass0.m_quad, 255)),
         _mm_shuffle_ps(this->m_centerOfMass1.m_quad, this->m_centerOfMass1.m_quad, 255));
  v6 = _mm_add_ps(
         _mm_mul_ps(_mm_sub_ps(this->m_rotation1.m_vec.m_quad, this->m_rotation0.m_vec.m_quad), v5),
         this->m_rotation0.m_vec.m_quad);
  v7 = _mm_mul_ps(v6, v6);
  v8 = _mm_add_ps(_mm_shuffle_ps(v7, v7, 78), v7);
  v9 = _mm_add_ps(_mm_shuffle_ps(v8, v8, 177), v8);
  v10 = _mm_rsqrt_ps(v9);
  qi.m_vec.m_quad = _mm_mul_ps(
                      v6,
                      _mm_mul_ps(
                        _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v10, v9), v10)),
                        _mm_mul_ps(*(__m128 *)_xmm, v10)));
  hkRotationf::set(&transformOut->m_rotation, &qi);
  v11.m_quad = _mm_add_ps(
                 _mm_mul_ps(_mm_sub_ps(this->m_centerOfMass1.m_quad, this->m_centerOfMass0.m_quad), v5),
                 this->m_centerOfMass0.m_quad);
  transformOut->m_translation = (hkVector4f)v11.m_quad;
  v12.m_quad = (__m128)this->m_centerOfMassLocal;
  transformOut->m_translation.m_quad = _mm_sub_ps(
                                         v11.m_quad,
                                         _mm_add_ps(
                                           _mm_add_ps(
                                             _mm_mul_ps(
                                               _mm_shuffle_ps(v12.m_quad, v12.m_quad, 85),
                                               transformOut->m_rotation.m_col1.m_quad),
                                             _mm_mul_ps(
                                               _mm_shuffle_ps(v12.m_quad, v12.m_quad, 0),
                                               transformOut->m_rotation.m_col0.m_quad)),
                                           _mm_mul_ps(
                                             _mm_shuffle_ps(v12.m_quad, v12.m_quad, 170),
                                             transformOut->m_rotation.m_col2.m_quad)));
}

// File Line: 55
// RVA: 0x12FEA50
void __fastcall hkSweptTransformf::initSweptTransform(
        hkSweptTransformf *this,
        hkVector4f *position,
        hkQuaternionf *rotation)
{
  __m128 m_quad; // xmm1

  this->m_centerOfMass0.m_quad = _mm_shuffle_ps(position->m_quad, _mm_unpackhi_ps(position->m_quad, (__m128)0i64), 196);
  this->m_centerOfMass1.m_quad = _mm_shuffle_ps(position->m_quad, _mm_unpackhi_ps(position->m_quad, (__m128)0i64), 196);
  this->m_rotation0 = (hkQuaternionf)rotation->m_vec.m_quad;
  m_quad = rotation->m_vec.m_quad;
  this->m_centerOfMassLocal = 0i64;
  this->m_rotation1.m_vec.m_quad = m_quad;
}

