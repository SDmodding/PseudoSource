// File Line: 32
// RVA: 0xCF1C40
void __fastcall hkpBoxShape::hkpBoxShape(hkpBoxShape *this, hkVector4f *halfExtents, float radius)
{
  __m128 v3; // xmm0
  __m128 v4; // xmm2

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  *(_DWORD *)&this->m_type.m_storage = 1027;
  this->m_radius = radius;
  this->vfptr = (hkBaseObjectVtbl *)&hkpBoxShape::`vftable';
  this->m_userData = 0i64;
  v3 = halfExtents->m_quad;
  v4 = halfExtents->m_quad;
  this->m_halfExtents = (hkVector4f)halfExtents->m_quad;
  this->m_halfExtents.m_quad = _mm_shuffle_ps(
                                 v3,
                                 _mm_unpackhi_ps(
                                   v3,
                                   _mm_min_ps(
                                     _mm_shuffle_ps(v3, v3, 170),
                                     _mm_min_ps(_mm_shuffle_ps(v4, v3, 85), _mm_shuffle_ps(v3, v3, 0)))),
                                 196);
}

// File Line: 44
// RVA: 0xCF2180
void __fastcall hkpBoxShape::hkpBoxShape(hkpBoxShape *this, hkFinishLoadedObjectFlag flag)
{
  hkpBoxShape *v2; // rbx

  v2 = this;
  hkpConvexShape::hkpConvexShape((hkpConvexShape *)&this->vfptr, flag);
  v2->vfptr = (hkBaseObjectVtbl *)&hkpBoxShape::`vftable';
  v2->m_type.m_storage = 3;
}

// File Line: 49
// RVA: 0xCF21B0
void __fastcall hkpBoxShape::~hkpBoxShape(hkpBoxShape *this)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
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
                                  _mm_shuffle_ps(this->m_halfExtents.m_quad, v4.m_quad, 0),
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
void __fastcall hkpBoxShape::getSupportingVertex(hkpBoxShape *this, hkVector4f *direction, hkcdVertex *supportingVertexOut)
{
  hkcdVertex v3; // ST00_16

  v3.m_quad = _mm_xor_ps(
                (__m128)_mm_slli_epi32(_mm_srli_epi32(_mm_load_si128((const __m128i *)direction), 0x1Fu), 0x1Fu),
                this->m_halfExtents.m_quad);
  v3.m_quad.m128_i32[3] = _mm_movemask_ps(_mm_cmpltps(v3.m_quad, (__m128)0i64)) & 7 | 0x3F000000;
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
void __fastcall hkpBoxShape::convertVertexIdsToVertices(hkpBoxShape *this, const unsigned __int16 *ids, int numIds, hkcdVertex *verticesOut)
{
  int v4; // er11
  const unsigned __int16 *i; // r10
  int v6; // er8

  v4 = numIds - 1;
  for ( i = ids; v4 >= 0; verticesOut[-1].m_quad.m128_i32[3] = v6 | 0x3F000000 )
  {
    v6 = *i;
    ++verticesOut;
    ++i;
    --v4;
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
  __m128 v3; // xmm0
  hkSphere *v4; // r8
  hkVector4f v5; // xmm1
  hkSphere *v6; // rcx
  const int *v7; // rax
  signed __int64 v8; // rdx
  __m128 v9; // xmm2
  __m128i v10; // xmm0

  v2.m_quad = (__m128)this->m_halfExtents;
  v3 = (__m128)LODWORD(this->m_radius);
  v4 = sphereBuffer;
  v5.m_quad = (__m128)this->m_halfExtents;
  v6 = sphereBuffer;
  v7 = hkVector4fComparison_maskToComparison_338;
  v8 = 8i64;
  v9 = _mm_shuffle_ps(v2.m_quad, _mm_unpackhi_ps(v5.m_quad, _mm_shuffle_ps(v3, v3, 0)), 196);
  do
  {
    v10 = *(__m128i *)v7;
    ++v6;
    v7 += 4;
    v6[-1].m_pos.m_quad = _mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v10, 0x1Fu), 0x1Fu), v9);
    --v8;
  }
  while ( v8 );
  return v4;
}

// File Line: 144
// RVA: 0xCF1E60
hkBool *__fastcall hkpBoxShape::castRay(hkpBoxShape *this, hkBool *result, hkpShapeRayCastInput *input, hkpShapeRayCastOutput *results)
{
  __m128 *v4; // rbp
  hkpShapeRayCastOutput *v5; // rbx
  hkpShapeRayCastInput *v6; // rsi
  hkBool *v7; // rdi
  _QWORD *v8; // r9
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  signed __int64 v11; // rcx
  __m128 v12; // xmm8
  __m128 v13; // xmm4
  __m128i v14; // xmm9
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
  __m128 v36; // xmm4
  float v37; // xmm0_4
  _QWORD *v38; // r8
  unsigned __int64 v39; // rcx
  unsigned __int64 v40; // rax
  _QWORD *v41; // r8
  unsigned __int64 v42; // rcx
  unsigned __int64 v43; // rax

  v4 = (__m128 *)this;
  v5 = results;
  v6 = input;
  v7 = result;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v8[1];
  if ( (unsigned __int64)v9 < v8[3] )
  {
    *v9 = "TtrcBox";
    v10 = __rdtsc();
    v11 = (signed __int64)(v9 + 2);
    *(_DWORD *)(v11 - 8) = v10;
    v8[1] = v11;
  }
  v12 = v6->m_from.m_quad;
  v13 = _mm_sub_ps(v6->m_to.m_quad, v6->m_from.m_quad);
  v14 = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
  v15 = _mm_shuffle_ps((__m128)LODWORD(v5->m_hitFraction), (__m128)LODWORD(v5->m_hitFraction), 0);
  v16 = _mm_add_ps(_mm_shuffle_ps((__m128)v4[2].m128_u32[0], (__m128)v4[2].m128_u32[0], 0), v4[3]);
  v17 = _mm_shuffle_ps(v13, _mm_unpackhi_ps(v13, query.m_quad), 196);
  v18 = _mm_xor_ps((__m128)_mm_shuffle_epi32(v14, 64), v16);
  v19 = _mm_cmpleps(v16, v6->m_from.m_quad);
  v20 = _mm_cmpleps(v6->m_from.m_quad, v18);
  v21 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v17, v17, 255), v17), v6->m_from.m_quad);
  if ( _mm_movemask_ps(_mm_or_ps(_mm_and_ps(_mm_cmpleps(v21, v18), v20), _mm_and_ps(_mm_cmpleps(v16, v21), v19))) & 7
    || !(_mm_movemask_ps(_mm_or_ps(v20, v19)) & 7) )
  {
    goto LABEL_18;
  }
  v22 = _mm_add_ps(v12, v16);
  v23 = _mm_cmpneqps(v17, (__m128)0i64);
  v24 = _mm_or_ps(_mm_andnot_ps(v23, *(__m128 *)&epsilon), _mm_and_ps(v17, v23));
  v25 = _mm_rcp_ps(v24);
  v26 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v24, v25)), v25);
  v27 = _mm_mul_ps(_mm_sub_ps(v16, v12), v26);
  v28 = _mm_xor_ps(_mm_mul_ps(v26, v22), (__m128)_mm_shuffle_epi32(v14, 0));
  v29 = _mm_or_ps(_mm_and_ps(_mm_min_ps(v28, v27), v23), _mm_andnot_ps(v23, (__m128)xmmword_141A712F0));
  v30 = _mm_or_ps(_mm_and_ps(_mm_max_ps(v28, v27), v23), _mm_andnot_ps(v23, (__m128)xmmword_141A712A0));
  v31 = _mm_max_ps(_mm_shuffle_ps(v29, v29, 170), _mm_max_ps(_mm_shuffle_ps(v29, v29, 85), _mm_shuffle_ps(v29, v29, 0)));
  v32 = _mm_min_ps(_mm_shuffle_ps(v30, v30, 170), _mm_min_ps(_mm_shuffle_ps(v30, v30, 85), _mm_shuffle_ps(v30, v30, 0)));
  v33 = _mm_movemask_ps(_mm_cmpeqps(v31, v29));
  v34 = v33 & 7 ? (unsigned __int8)hkVector4Comparison_maskToFirstIndex[v33] : -1;
  v35 = _mm_and_ps(_mm_and_ps(_mm_cmpleps((__m128)0i64, v31), _mm_cmpleps(v31, v32)), _mm_cmpltps(v31, v15));
  v36 = _mm_xor_ps(
          (__m128)_mm_slli_epi32(_mm_srli_epi32((__m128i)_mm_cmpltps(v28, v27), 0x1Fu), 0x1Fu),
          *(&transform.m_quad + v34));
  LODWORD(v37) = *(unsigned __int128 *)&_mm_andnot_ps(v35, v15) | v31.m128_i32[0] & v35.m128_i32[0];
  if ( _mm_movemask_ps(v35) )
  {
    v5->m_normal.m_quad = v36;
    v5->m_hitFraction = v37;
    v5->m_shapeKeys[v5->m_shapeKeyIndex] = -1;
    v38 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v39 = v38[1];
    if ( v39 < v38[3] )
    {
      *(_QWORD *)v39 = "Et";
      v40 = __rdtsc();
      *(_DWORD *)(v39 + 8) = v40;
      v38[1] = v39 + 16;
    }
    v7->m_bool = 1;
  }
  else
  {
LABEL_18:
    v41 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v42 = v41[1];
    if ( v42 < v41[3] )
    {
      *(_QWORD *)v42 = "Et";
      v43 = __rdtsc();
      *(_DWORD *)(v42 + 8) = v43;
      v41[1] = v42 + 16;
    }
    v7->m_bool = 0;
  }
  return v7;
}

