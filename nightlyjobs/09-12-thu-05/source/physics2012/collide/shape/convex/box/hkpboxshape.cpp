// File Line: 32
// RVA: 0xCF1C40
void __fastcall hkpBoxShape::hkpBoxShape(hkpBoxShape *this, hkVector4f *halfExtents, float radius)
{
  __m128 m_quad; // xmm3

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  *(_DWORD *)&this->m_type.m_storage = 1027;
  this->m_radius = radius;
  this->vfptr = (hkBaseObjectVtbl *)&hkpBoxShape::`vftable;
  this->m_userData = 0i64;
  m_quad = halfExtents->m_quad;
  this->m_halfExtents = (hkVector4f)halfExtents->m_quad;
  this->m_halfExtents.m_quad = _mm_shuffle_ps(
                                 m_quad,
                                 _mm_unpackhi_ps(
                                   m_quad,
                                   _mm_min_ps(
                                     _mm_shuffle_ps(m_quad, m_quad, 170),
                                     _mm_min_ps(_mm_shuffle_ps(m_quad, m_quad, 85), _mm_shuffle_ps(m_quad, m_quad, 0)))),
                                 196);
}

// File Line: 44
// RVA: 0xCF2180
void __fastcall hkpBoxShape::hkpBoxShape(hkpBoxShape *this, hkFinishLoadedObjectFlag flag)
{
  hkpConvexShape::hkpConvexShape(this, flag);
  this->vfptr = (hkBaseObjectVtbl *)&hkpBoxShape::`vftable;
  this->m_type.m_storage = 3;
}

// File Line: 49
// RVA: 0xCF21B0
void __fastcall hkpBoxShape::~hkpBoxShape(hkpBoxShape *this)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 54
// RVA: 0xCF21D0
void __fastcall hkpBoxShape::getFirstVertex(hkpBoxShape *this, hkVector4f *v)
{
  *v = this->m_halfExtents;
}

// File Line: 61
// RVA: 0xCF2140
void __fastcall hkpBoxShape::setHalfExtents(hkpBoxShape *this, hkVector4f *halfExtents)
{
  this->m_halfExtents.m_quad = _mm_shuffle_ps(
                                 halfExtents->m_quad,
                                 _mm_unpackhi_ps(
                                   halfExtents->m_quad,
                                   _mm_min_ps(
                                     _mm_shuffle_ps(halfExtents->m_quad, halfExtents->m_quad, 170),
                                     _mm_min_ps(
                                       _mm_shuffle_ps(halfExtents->m_quad, halfExtents->m_quad, 85),
                                       _mm_shuffle_ps(halfExtents->m_quad, halfExtents->m_quad, 0)))),
                                 196);
}

// File Line: 67
// RVA: 0xCF1DD0
void __fastcall hkpBoxShape::getAabb(hkpBoxShape *this, hkTransformf *localToWorld, float tolerance, hkAabb *out)
{
  hkVector4f v4; // xmm2
  __m128 v5; // xmm3
  hkVector4f v6; // xmm2
  unsigned int v7; // [rsp+18h] [rbp+18h]

  *(float *)&v7 = tolerance + this->m_radius;
  v4.m_quad = (__m128)this->m_halfExtents;
  v5 = _mm_add_ps(
         _mm_add_ps(
           (__m128)_mm_srli_epi32(
                     _mm_slli_epi32(
                       (__m128i)_mm_mul_ps(
                                  _mm_shuffle_ps(v4.m_quad, v4.m_quad, 85),
                                  localToWorld->m_rotation.m_col1.m_quad),
                       1u),
                     1u),
           (__m128)_mm_srli_epi32(
                     _mm_slli_epi32(
                       (__m128i)_mm_mul_ps(
                                  _mm_shuffle_ps(v4.m_quad, v4.m_quad, 0),
                                  localToWorld->m_rotation.m_col0.m_quad),
                       1u),
                     1u)),
         _mm_add_ps(
           (__m128)_mm_srli_epi32(
                     _mm_slli_epi32(
                       (__m128i)_mm_mul_ps(
                                  _mm_shuffle_ps(v4.m_quad, v4.m_quad, 170),
                                  localToWorld->m_rotation.m_col2.m_quad),
                       1u),
                     1u),
           _mm_shuffle_ps((__m128)v7, (__m128)v7, 0)));
  v6.m_quad = (__m128)localToWorld->m_translation;
  out->m_max.m_quad = _mm_add_ps(v6.m_quad, v5);
  out->m_min.m_quad = _mm_add_ps(
                        _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v5),
                        v6.m_quad);
}

// File Line: 73
// RVA: 0xCF1CA0
void __fastcall hkpBoxShape::getSupportingVertex(
        hkpBoxShape *this,
        const __m128i *direction,
        hkcdVertex *supportingVertexOut)
{
  hkcdVertex v3; // [rsp+0h] [rbp-18h]

  v3.m_quad = _mm_xor_ps(
                (__m128)_mm_slli_epi32(_mm_srli_epi32(_mm_load_si128(direction), 0x1Fu), 0x1Fu),
                this->m_halfExtents.m_quad);
  v3.m_quad.m128_i32[3] = _mm_movemask_ps(_mm_cmplt_ps(v3.m_quad, (__m128)0i64)) & 7 | 0x3F000000;
  *supportingVertexOut = (hkcdVertex)v3.m_quad;
}

// File Line: 86
// RVA: 0xCF1D60
void __fastcall hkpBoxShape::getCentre(hkpBoxShape *this, hkVector4f *centreOut)
{
  *centreOut = 0i64;
}

// File Line: 95
// RVA: 0xCF1CF0
void __fastcall hkpBoxShape::convertVertexIdsToVertices(
        hkpBoxShape *this,
        const unsigned __int16 *ids,
        int numIds,
        hkcdVertex *verticesOut)
{
  int i; // r11d
  int v6; // r8d

  for ( i = numIds - 1; i >= 0; verticesOut[-1].m_quad.m128_i32[3] = v6 | 0x3F000000 )
  {
    v6 = *ids;
    ++verticesOut;
    ++ids;
    --i;
    verticesOut[-1].m_quad = _mm_xor_ps(
                               (__m128)_mm_slli_epi32(
                                         _mm_srli_epi32(
                                           *(__m128i *)&hkVector4fComparison_maskToComparison_338[4 * v6],
                                           0x1Fu),
                                         0x1Fu),
                               this->m_halfExtents.m_quad);
  }
}

// File Line: 109
// RVA: 0xCF1D70
hkSphere *__fastcall hkpBoxShape::getCollisionSpheres(hkpBoxShape *this, hkSphere *sphereBuffer)
{
  hkVector4f v2; // xmm2
  __m128 m_radius_low; // xmm0
  hkSphere *v5; // rcx
  const int *v6; // rax
  __int64 v7; // rdx
  __m128 v8; // xmm2
  __m128i v9; // xmm0

  v2.m_quad = (__m128)this->m_halfExtents;
  m_radius_low = (__m128)LODWORD(this->m_radius);
  v5 = sphereBuffer;
  v6 = hkVector4fComparison_maskToComparison_338;
  v7 = 8i64;
  v8 = _mm_shuffle_ps(v2.m_quad, _mm_unpackhi_ps(v2.m_quad, _mm_shuffle_ps(m_radius_low, m_radius_low, 0)), 196);
  do
  {
    v9 = *(__m128i *)v6;
    ++v5;
    v6 += 4;
    v5[-1].m_pos.m_quad = _mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v9, 0x1Fu), 0x1Fu), v8);
    --v7;
  }
  while ( v7 );
  return sphereBuffer;
}

// File Line: 144
// RVA: 0xCF1E60
hkBool *__fastcall hkpBoxShape::castRay(
        hkpBoxShape *this,
        hkBool *result,
        hkpShapeRayCastInput *input,
        hkpShapeRayCastOutput *results)
{
  _QWORD *Value; // r9
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  _QWORD *v11; // rcx
  hkVector4f v12; // xmm8
  __m128 v13; // xmm4
  __m128i inserted; // xmm9
  __m128 v15; // xmm7
  __m128 v16; // xmm6
  __m128 v17; // xmm4
  __m128 v18; // xmm0
  __m128 v19; // xmm5
  __m128 v20; // xmm3
  __m128 v21; // xmm2
  __m128 v22; // xmm2
  __m128 v23; // xmm3
  __m128 v24; // xmm1
  __m128 v25; // xmm0
  __m128 v26; // xmm4
  __m128 v27; // xmm6
  __m128 v28; // xmm4
  __m128 v29; // xmm2
  __m128 v30; // xmm8
  __m128 v31; // xmm3
  __m128 v32; // xmm8
  int v33; // eax
  int v34; // ecx
  __m128 v35; // xmm5
  hkVector4f v36; // xmm4
  float v37; // xmm0_4
  _QWORD *v38; // r8
  unsigned __int64 v39; // rcx
  unsigned __int64 v40; // rax
  _QWORD *v41; // r8
  unsigned __int64 v42; // rcx
  unsigned __int64 v43; // rax

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v9 < Value[3] )
  {
    *v9 = "TtrcBox";
    v10 = __rdtsc();
    v11 = v9 + 2;
    *((_DWORD *)v11 - 2) = v10;
    Value[1] = v11;
  }
  v12.m_quad = (__m128)input->m_from;
  v13 = _mm_sub_ps(input->m_to.m_quad, input->m_from.m_quad);
  inserted = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
  v15 = _mm_shuffle_ps((__m128)LODWORD(results->m_hitFraction), (__m128)LODWORD(results->m_hitFraction), 0);
  v16 = _mm_add_ps(
          _mm_shuffle_ps((__m128)LODWORD(this->m_radius), (__m128)LODWORD(this->m_radius), 0),
          this->m_halfExtents.m_quad);
  v17 = _mm_shuffle_ps(v13, _mm_unpackhi_ps(v13, query.m_quad), 196);
  v18 = _mm_xor_ps((__m128)_mm_shuffle_epi32(inserted, 64), v16);
  v19 = _mm_cmple_ps(v16, input->m_from.m_quad);
  v20 = _mm_cmple_ps(input->m_from.m_quad, v18);
  v21 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v17, v17, 255), v17), input->m_from.m_quad);
  if ( (_mm_movemask_ps(_mm_or_ps(_mm_and_ps(_mm_cmple_ps(v21, v18), v20), _mm_and_ps(_mm_cmple_ps(v16, v21), v19))) & 7) != 0
    || (_mm_movemask_ps(_mm_or_ps(v20, v19)) & 7) == 0 )
  {
    goto LABEL_12;
  }
  v22 = _mm_add_ps(v12.m_quad, v16);
  v23 = _mm_cmpneq_ps(v17, (__m128)0i64);
  v24 = _mm_or_ps(_mm_andnot_ps(v23, *(__m128 *)&epsilon), _mm_and_ps(v17, v23));
  v25 = _mm_rcp_ps(v24);
  v26 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v24, v25)), v25);
  v27 = _mm_mul_ps(_mm_sub_ps(v16, v12.m_quad), v26);
  v28 = _mm_xor_ps(_mm_mul_ps(v26, v22), (__m128)_mm_shuffle_epi32(inserted, 0));
  v29 = _mm_or_ps(_mm_and_ps(_mm_min_ps(v28, v27), v23), _mm_andnot_ps(v23, (__m128)xmmword_141A712F0));
  v30 = _mm_or_ps(_mm_and_ps(_mm_max_ps(v28, v27), v23), _mm_andnot_ps(v23, (__m128)xmmword_141A712A0));
  v31 = _mm_max_ps(_mm_shuffle_ps(v29, v29, 170), _mm_max_ps(_mm_shuffle_ps(v29, v29, 85), _mm_shuffle_ps(v29, v29, 0)));
  v32 = _mm_min_ps(_mm_shuffle_ps(v30, v30, 170), _mm_min_ps(_mm_shuffle_ps(v30, v30, 85), _mm_shuffle_ps(v30, v30, 0)));
  v33 = _mm_movemask_ps(_mm_cmpeq_ps(v31, v29));
  v34 = (v33 & 7) != 0 ? (unsigned __int8)hkVector4Comparison_maskToFirstIndex[v33] : -1;
  v35 = _mm_and_ps(_mm_and_ps(_mm_cmple_ps((__m128)0i64, v31), _mm_cmple_ps(v31, v32)), _mm_cmplt_ps(v31, v15));
  v36.m_quad = _mm_xor_ps(
                 (__m128)_mm_slli_epi32(_mm_srli_epi32((__m128i)_mm_cmplt_ps(v28, v27), 0x1Fu), 0x1Fu),
                 *(&transform.m_quad + v34));
  LODWORD(v37) = _mm_andnot_ps(v35, v15).m128_u32[0] | v31.m128_i32[0] & v35.m128_i32[0];
  if ( _mm_movemask_ps(v35) )
  {
    results->m_normal = (hkVector4f)v36.m_quad;
    results->m_hitFraction = v37;
    results->m_shapeKeys[results->m_shapeKeyIndex] = -1;
    v38 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v39 = v38[1];
    if ( v39 < v38[3] )
    {
      *(_QWORD *)v39 = "Et";
      v40 = __rdtsc();
      *(_DWORD *)(v39 + 8) = v40;
      v38[1] = v39 + 16;
    }
    result->m_bool = 1;
  }
  else
  {
LABEL_12:
    v41 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v42 = v41[1];
    if ( v42 < v41[3] )
    {
      *(_QWORD *)v42 = "Et";
      v43 = __rdtsc();
      *(_DWORD *)(v42 + 8) = v43;
      v41[1] = v42 + 16;
    }
    result->m_bool = 0;
  }
  return result;
}

