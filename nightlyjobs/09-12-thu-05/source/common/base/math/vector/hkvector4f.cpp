// File Line: 12
// RVA: 0xC56EB0
void __fastcall hkVector4f::setRotatedDir(hkVector4f *this, hkMatrix3f *a, hkVector4f *b)
{
  this->m_quad = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(b->m_quad, b->m_quad, 85), a->m_col1.m_quad),
                     _mm_mul_ps(_mm_shuffle_ps(b->m_quad, b->m_quad, 0), a->m_col0.m_quad)),
                   _mm_mul_ps(_mm_shuffle_ps(b->m_quad, b->m_quad, 170), a->m_col2.m_quad));
}

// File Line: 17
// RVA: 0xC56EF0
void __fastcall hkVector4f::setRotatedInverseDir(hkVector4f *this, hkMatrix3f *a, hkVector4f *b)
{
  hkVector4f v3; // xmm4
  __m128 v4; // xmm1
  __m128 v5; // xmm2

  v3.m_quad = (__m128)a->m_col2;
  v4 = _mm_unpacklo_ps(a->m_col0.m_quad, a->m_col1.m_quad);
  v5 = _mm_movelh_ps(v4, v3.m_quad);
  this->m_quad = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(
                       _mm_shuffle_ps(b->m_quad, b->m_quad, 85),
                       _mm_shuffle_ps(_mm_movehl_ps(v5, v4), v3.m_quad, 212)),
                     _mm_mul_ps(_mm_shuffle_ps(b->m_quad, b->m_quad, 0), v5)),
                   _mm_mul_ps(
                     _mm_shuffle_ps(b->m_quad, b->m_quad, 170),
                     _mm_shuffle_ps(_mm_unpackhi_ps(a->m_col0.m_quad, a->m_col1.m_quad), v3.m_quad, 228)));
}

// File Line: 22
// RVA: 0xC56F50
void __fastcall hkVector4f::setTransformedPos(hkVector4f *this, hkTransformf *a, hkVector4f *b)
{
  this->m_quad = _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(b->m_quad, b->m_quad, 85), a->m_rotation.m_col1.m_quad),
                       _mm_mul_ps(_mm_shuffle_ps(b->m_quad, b->m_quad, 0), a->m_rotation.m_col0.m_quad)),
                     _mm_mul_ps(_mm_shuffle_ps(b->m_quad, b->m_quad, 170), a->m_rotation.m_col2.m_quad)),
                   a->m_translation.m_quad);
}

// File Line: 27
// RVA: 0xC56F90
void __fastcall hkVector4f::setTransformedInversePos(hkVector4f *this, hkTransformf *a, hkVector4f *b)
{
  hkVector4f v3; // xmm3
  __m128 v4; // xmm5
  __m128 v5; // xmm1
  __m128 v6; // xmm2

  v3.m_quad = (__m128)a->m_rotation.m_col2;
  v4 = _mm_sub_ps(b->m_quad, a->m_translation.m_quad);
  v5 = _mm_unpacklo_ps(a->m_rotation.m_col0.m_quad, a->m_rotation.m_col1.m_quad);
  v6 = _mm_movelh_ps(v5, v3.m_quad);
  this->m_quad = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v4, v4, 85), _mm_shuffle_ps(_mm_movehl_ps(v6, v5), v3.m_quad, 212)),
                     _mm_mul_ps(_mm_shuffle_ps(v4, v4, 0), v6)),
                   _mm_mul_ps(
                     _mm_shuffle_ps(
                       _mm_unpackhi_ps(a->m_rotation.m_col0.m_quad, a->m_rotation.m_col1.m_quad),
                       v3.m_quad,
                       228),
                     _mm_shuffle_ps(v4, v4, 170)));
}

// File Line: 32
// RVA: 0xC570F0
void __fastcall hkVector4f::setTransformedPos(hkVector4f *this, hkQsTransformf *a, hkVector4f *b)
{
  hkQuaternionf v3; // xmm2
  __m128 v4; // xmm5
  __m128 v5; // xmm1
  __m128 v6; // xmm6
  __m128 v7; // xmm4
  __m128 v8; // xmm3

  v3.m_vec.m_quad = (__m128)a->m_rotation;
  v4 = _mm_mul_ps(b->m_quad, a->m_scale.m_quad);
  v5 = _mm_mul_ps(v3.m_vec.m_quad, v4);
  v6 = _mm_shuffle_ps(v3.m_vec.m_quad, v3.m_vec.m_quad, 255);
  v7 = _mm_sub_ps(
         _mm_mul_ps(_mm_shuffle_ps(v4, v4, 201), v3.m_vec.m_quad),
         _mm_mul_ps(_mm_shuffle_ps(v3.m_vec.m_quad, v3.m_vec.m_quad, 201), v4));
  v8 = _mm_add_ps(
         _mm_add_ps(
           _mm_mul_ps(
             _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v5, v5, 85), _mm_shuffle_ps(v5, v5, 0)), _mm_shuffle_ps(v5, v5, 170)),
             v3.m_vec.m_quad),
           _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v6, v6), (__m128)xmmword_141A711B0), v4)),
         _mm_mul_ps(_mm_shuffle_ps(v7, v7, 201), v6));
  this->m_quad = _mm_add_ps(_mm_add_ps(v8, v8), a->m_translation.m_quad);
}

// File Line: 37
// RVA: 0xC57180
void __fastcall hkVector4f::setTransformedInversePos(hkVector4f *this, hkQsTransformf *a, hkVector4f *b)
{
  hkQuaternionf v3; // xmm2
  __m128 v4; // xmm4
  __m128 v5; // xmm5
  __m128 v6; // xmm1
  __m128 v7; // xmm3
  hkVector4f v8; // xmm0
  __m128 v9; // xmm6
  __m128 v10; // xmm1

  v3.m_vec.m_quad = (__m128)a->m_rotation;
  v4 = _mm_sub_ps(b->m_quad, a->m_translation.m_quad);
  v5 = _mm_shuffle_ps(v3.m_vec.m_quad, v3.m_vec.m_quad, 255);
  v6 = _mm_mul_ps(v3.m_vec.m_quad, v4);
  v7 = _mm_sub_ps(
         _mm_mul_ps(_mm_shuffle_ps(v3.m_vec.m_quad, v3.m_vec.m_quad, 201), v4),
         _mm_mul_ps(_mm_shuffle_ps(v4, v4, 201), v3.m_vec.m_quad));
  v8.m_quad = (__m128)a->m_scale;
  v9 = _mm_add_ps(
         _mm_add_ps(
           _mm_mul_ps(
             _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v6, v6, 85), _mm_shuffle_ps(v6, v6, 0)), _mm_shuffle_ps(v6, v6, 170)),
             v3.m_vec.m_quad),
           _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v5, v5), (__m128)xmmword_141A711B0), v4)),
         _mm_mul_ps(_mm_shuffle_ps(v7, v7, 201), v5));
  v10 = _mm_rcp_ps(v8.m_quad);
  this->m_quad = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v8.m_quad, v10)), v10), _mm_add_ps(v9, v9));
}

// File Line: 42
// RVA: 0xC57220
void __fastcall hkVector4f::setTransformedPos(hkVector4f *this, hkQTransformf *a, hkVector4f *b)
{
  __m128 v3; // xmm1
  __m128 v4; // xmm6
  __m128 v5; // xmm5
  __m128 v6; // xmm3

  v3 = _mm_mul_ps(a->m_rotation.m_vec.m_quad, b->m_quad);
  v4 = _mm_shuffle_ps(a->m_rotation.m_vec.m_quad, a->m_rotation.m_vec.m_quad, 255);
  v5 = _mm_sub_ps(
         _mm_mul_ps(_mm_shuffle_ps(b->m_quad, b->m_quad, 201), a->m_rotation.m_vec.m_quad),
         _mm_mul_ps(_mm_shuffle_ps(a->m_rotation.m_vec.m_quad, a->m_rotation.m_vec.m_quad, 201), b->m_quad));
  v6 = _mm_add_ps(
         _mm_add_ps(
           _mm_mul_ps(
             _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v3, v3, 85), _mm_shuffle_ps(v3, v3, 0)), _mm_shuffle_ps(v3, v3, 170)),
             a->m_rotation.m_vec.m_quad),
           _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v4, v4), (__m128)xmmword_141A711B0), b->m_quad)),
         _mm_mul_ps(_mm_shuffle_ps(v5, v5, 201), v4));
  this->m_quad = _mm_add_ps(_mm_add_ps(v6, v6), a->m_translation.m_quad);
}

// File Line: 47
// RVA: 0xC572B0
void __fastcall hkVector4f::setTransformedInversePos(hkVector4f *this, hkQTransformf *a, hkVector4f *b)
{
  __m128 v3; // xmm5
  __m128 v4; // xmm1
  __m128 v5; // xmm6
  __m128 v6; // xmm4
  __m128 v7; // xmm3

  v3 = _mm_sub_ps(b->m_quad, a->m_translation.m_quad);
  v4 = _mm_mul_ps(a->m_rotation.m_vec.m_quad, v3);
  v5 = _mm_shuffle_ps(a->m_rotation.m_vec.m_quad, a->m_rotation.m_vec.m_quad, 255);
  v6 = _mm_sub_ps(
         _mm_mul_ps(_mm_shuffle_ps(a->m_rotation.m_vec.m_quad, a->m_rotation.m_vec.m_quad, 201), v3),
         _mm_mul_ps(_mm_shuffle_ps(v3, v3, 201), a->m_rotation.m_vec.m_quad));
  v7 = _mm_add_ps(
         _mm_add_ps(
           _mm_mul_ps(
             _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v4, v4, 85), _mm_shuffle_ps(v4, v4, 0)), _mm_shuffle_ps(v4, v4, 170)),
             a->m_rotation.m_vec.m_quad),
           _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v5, v5), (__m128)xmmword_141A711B0), v3)),
         _mm_mul_ps(_mm_shuffle_ps(v6, v6, 201), v5));
  this->m_quad = _mm_add_ps(v7, v7);
}

// File Line: 52
// RVA: 0xC56FF0
void __fastcall hkVector4f::setRotatedDir(hkVector4f *this, hkQuaternionf *quat, hkVector4f *direction)
{
  __m128 v3; // xmm1
  __m128 v4; // xmm6
  __m128 v5; // xmm5
  __m128 v6; // xmm3

  v3 = _mm_mul_ps(quat->m_vec.m_quad, direction->m_quad);
  v4 = _mm_shuffle_ps(quat->m_vec.m_quad, quat->m_vec.m_quad, 255);
  v5 = _mm_sub_ps(
         _mm_mul_ps(_mm_shuffle_ps(direction->m_quad, direction->m_quad, 201), quat->m_vec.m_quad),
         _mm_mul_ps(_mm_shuffle_ps(quat->m_vec.m_quad, quat->m_vec.m_quad, 201), direction->m_quad));
  v6 = _mm_add_ps(
         _mm_add_ps(
           _mm_mul_ps(
             _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v3, v3, 85), _mm_shuffle_ps(v3, v3, 0)), _mm_shuffle_ps(v3, v3, 170)),
             quat->m_vec.m_quad),
           _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v4, v4), (__m128)xmmword_141A711B0), direction->m_quad)),
         _mm_mul_ps(_mm_shuffle_ps(v5, v5, 201), v4));
  this->m_quad = _mm_add_ps(v6, v6);
}

// File Line: 57
// RVA: 0xC57070
void __fastcall hkVector4f::setRotatedInverseDir(hkVector4f *this, hkQuaternionf *quat, hkVector4f *direction)
{
  __m128 v3; // xmm1
  __m128 v4; // xmm6
  __m128 v5; // xmm5
  __m128 v6; // xmm3

  v3 = _mm_mul_ps(quat->m_vec.m_quad, direction->m_quad);
  v4 = _mm_shuffle_ps(quat->m_vec.m_quad, quat->m_vec.m_quad, 255);
  v5 = _mm_sub_ps(
         _mm_mul_ps(_mm_shuffle_ps(quat->m_vec.m_quad, quat->m_vec.m_quad, 201), direction->m_quad),
         _mm_mul_ps(_mm_shuffle_ps(direction->m_quad, direction->m_quad, 201), quat->m_vec.m_quad));
  v6 = _mm_add_ps(
         _mm_add_ps(
           _mm_mul_ps(
             _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v3, v3, 85), _mm_shuffle_ps(v3, v3, 0)), _mm_shuffle_ps(v3, v3, 170)),
             quat->m_vec.m_quad),
           _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v4, v4), (__m128)xmmword_141A711B0), direction->m_quad)),
         _mm_mul_ps(_mm_shuffle_ps(v5, v5, 201), v4));
  this->m_quad = _mm_add_ps(v6, v6);
}

