// File Line: 14
// RVA: 0xC056C0
void __fastcall hkaiSilhouetteReferenceFrame::hkaiSilhouetteReferenceFrame(hkaiSilhouetteReferenceFrame *this, hkVector4f *up, hkVector4f *referenceAxis)
{
  hkaiSilhouetteReferenceFrame::set(this, up, referenceAxis);
}

// File Line: 19
// RVA: 0xC056E0
void __fastcall hkaiSilhouetteReferenceFrame::set(hkaiSilhouetteReferenceFrame *this, hkVector4f *up, hkVector4f *referenceAxis)
{
  __m128 v3; // xmm0
  __m128 v4; // xmm5
  __m128 v5; // xmm1
  __m128 v6; // xmm5
  __m128 v7; // xmm5
  __m128 v8; // xmm1
  __m128 v9; // xmm3
  __m128 v10; // xmm2

  v3 = up->m_quad;
  this->m_up = (hkVector4f)up->m_quad;
  v4 = referenceAxis->m_quad;
  v5 = _mm_mul_ps(_mm_shuffle_ps(v3, v3, 201), referenceAxis->m_quad);
  this->m_referenceAxis = (hkVector4f)referenceAxis->m_quad;
  v6 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v4, v4, 201), v3), v5);
  v7 = _mm_shuffle_ps(v6, v6, 201);
  v8 = _mm_mul_ps(v7, v7);
  v9 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)), _mm_shuffle_ps(v8, v8, 170));
  v10 = _mm_rsqrt_ps(v9);
  this->m_orthogonalAxis.m_quad = _mm_mul_ps(
                                    _mm_andnot_ps(
                                      _mm_cmpleps(v9, (__m128)0i64),
                                      _mm_mul_ps(
                                        _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v10, v9), v10)),
                                        _mm_mul_ps(*(__m128 *)_xmm, v10))),
                                    v7);
}

// File Line: 29
// RVA: 0xC05800
bool __fastcall hkaiSilhouetteReferenceFrame::isValid(hkaiSilhouetteReferenceFrame *this)
{
  hkVector4f v1; // xmm3
  __m128 v2; // xmm3
  hkVector4f v3; // xmm3
  __m128 v4; // xmm3
  hkVector4f v5; // xmm3
  __m128 v6; // xmm3
  bool result; // al

  v1.m_quad = (__m128)this->m_referenceAxis;
  result = 0;
  if ( !(_mm_movemask_ps(_mm_cmpunordps(v1.m_quad, v1.m_quad)) & 7) )
  {
    v2 = _mm_mul_ps(v1.m_quad, v1.m_quad);
    if ( COERCE_FLOAT((unsigned int)(2
                                   * COERCE_SIGNED_INT(
                                       (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v2, v2, 85))
                                                     + COERCE_FLOAT(_mm_shuffle_ps(v2, v2, 0)))
                                             + COERCE_FLOAT(_mm_shuffle_ps(v2, v2, 170)))
                                     - 1.0)) >> 1) < COERCE_FLOAT(_mm_shuffle_ps((__m128)0x38D1B717u, (__m128)0x38D1B717u, 0)) )
    {
      v3.m_quad = (__m128)this->m_up;
      if ( !(_mm_movemask_ps(_mm_cmpunordps(v3.m_quad, v3.m_quad)) & 7) )
      {
        v4 = _mm_mul_ps(v3.m_quad, v3.m_quad);
        if ( COERCE_FLOAT((unsigned int)(2
                                       * COERCE_SIGNED_INT(
                                           (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v4, v4, 85))
                                                         + COERCE_FLOAT(_mm_shuffle_ps(v4, v4, 0)))
                                                 + COERCE_FLOAT(_mm_shuffle_ps(v4, v4, 170)))
                                         - 1.0)) >> 1) < COERCE_FLOAT(_mm_shuffle_ps((__m128)0x38D1B717u, (__m128)0x38D1B717u, 0)) )
        {
          v5.m_quad = (__m128)this->m_orthogonalAxis;
          if ( !(_mm_movemask_ps(_mm_cmpunordps(v5.m_quad, v5.m_quad)) & 7) )
          {
            v6 = _mm_mul_ps(v5.m_quad, v5.m_quad);
            if ( COERCE_FLOAT((unsigned int)(2
                                           * COERCE_SIGNED_INT(
                                               (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v6, v6, 85))
                                                             + COERCE_FLOAT(_mm_shuffle_ps(v6, v6, 0)))
                                                     + COERCE_FLOAT(_mm_shuffle_ps(v6, v6, 170)))
                                             - 1.0)) >> 1) < COERCE_FLOAT(
                                                               _mm_shuffle_ps(
                                                                 (__m128)0x38D1B717u,
                                                                 (__m128)0x38D1B717u,
                                                                 0)) )
              result = 1;
          }
        }
      }
    }
  }
  return result;
}

// File Line: 37
// RVA: 0xC05770
hkSimdFloat32 *__fastcall hkaiSilhouetteReferenceFrame::getFirstComponent(hkaiSilhouetteReferenceFrame *this, hkSimdFloat32 *result, hkVector4f *v)
{
  hkSimdFloat32 *v3; // rax
  __m128 v4; // xmm2

  v3 = result;
  v4 = _mm_mul_ps(this->m_referenceAxis.m_quad, v->m_quad);
  result->m_real = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v4, v4, 85), _mm_shuffle_ps(v4, v4, 0)),
                     _mm_shuffle_ps(v4, v4, 170));
  return v3;
}

// File Line: 42
// RVA: 0xC057A0
hkSimdFloat32 *__fastcall hkaiSilhouetteReferenceFrame::getSecondComponent(hkaiSilhouetteReferenceFrame *this, hkSimdFloat32 *result, hkVector4f *v)
{
  hkSimdFloat32 *v3; // rax
  __m128 v4; // xmm2

  v3 = result;
  v4 = _mm_mul_ps(this->m_orthogonalAxis.m_quad, v->m_quad);
  result->m_real = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v4, v4, 85), _mm_shuffle_ps(v4, v4, 0)),
                     _mm_shuffle_ps(v4, v4, 170));
  return v3;
}

// File Line: 47
// RVA: 0xC057D0
void __fastcall hkaiSilhouetteReferenceFrame::setUnprojected(hkaiSilhouetteReferenceFrame *this, hkSimdFloat32 *first, hkSimdFloat32 *second, hkVector4f *vOut)
{
  hkVector4f v4; // xmm1

  *vOut = 0i64;
  v4.m_quad = _mm_add_ps(_mm_mul_ps(this->m_referenceAxis.m_quad, first->m_real), (__m128)0i64);
  *vOut = (hkVector4f)v4.m_quad;
  vOut->m_quad = _mm_add_ps(_mm_mul_ps(this->m_orthogonalAxis.m_quad, second->m_real), v4.m_quad);
}

