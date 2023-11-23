// File Line: 17
// RVA: 0xDFE540
float __fastcall hkpStaticCompoundShape_Internals::getTransformedMaximumProjection(
        hkpShape *shape,
        hkQsTransformf *transform,
        hkVector4f *direction)
{
  hkQuaternionf v3; // xmm2
  hkBaseObjectVtbl *vfptr; // rax
  __m128 v7; // xmm1
  __m128 v8; // xmm5
  __m128 v9; // xmm6
  __m128 v10; // xmm4
  double v11; // xmm0_8
  __m128 v12; // xmm2
  __m128 v14; // [rsp+20h] [rbp-28h] BYREF

  v3.m_vec.m_quad = (__m128)transform->m_rotation;
  vfptr = shape->vfptr;
  v7 = _mm_mul_ps(v3.m_vec.m_quad, direction->m_quad);
  v8 = _mm_sub_ps(
         _mm_mul_ps(_mm_shuffle_ps(v3.m_vec.m_quad, v3.m_vec.m_quad, 201), direction->m_quad),
         _mm_mul_ps(_mm_shuffle_ps(direction->m_quad, direction->m_quad, 201), v3.m_vec.m_quad));
  v9 = _mm_shuffle_ps(v3.m_vec.m_quad, v3.m_vec.m_quad, 255);
  v10 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps(v7, v7, 0)), _mm_shuffle_ps(v7, v7, 170)),
              v3.m_vec.m_quad),
            _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v9, v9), (__m128)xmmword_141A711B0), direction->m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v8, v8, 201), v9));
  v14 = _mm_mul_ps(_mm_add_ps(v10, v10), transform->m_scale.m_quad);
  v11 = ((double (__fastcall *)(hkpShape *, __m128 *))vfptr[7].__first_virtual_table_function__)(shape, &v14);
  v12 = _mm_mul_ps(transform->m_translation.m_quad, direction->m_quad);
  return (float)((float)(_mm_shuffle_ps(v12, v12, 85).m128_f32[0] + _mm_shuffle_ps(v12, v12, 0).m128_f32[0])
               + _mm_shuffle_ps(v12, v12, 170).m128_f32[0])
       + *(float *)&v11;
}

