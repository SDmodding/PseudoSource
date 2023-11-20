// File Line: 21
// RVA: 0xC09D90
void __fastcall hkaiSilhouetteGenerator::hkaiSilhouetteGenerator(hkaiSilhouetteGenerator *this, hkaiSilhouetteGenerator::GeneratorType type)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_lazyRecomputeDisplacementThreshold = 0.1;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiSilhouetteGenerator::`vftable';
  this->m_userData = 0i64;
  this->m_type.m_storage = type;
  this->m_forceGenerateOntoPpu = 0;
  this->m_materialId = -1;
  this->m_cachedSilhouettes.m_pntr = 0i64;
  this->m_transform.m_translation = 0i64;
  this->m_transform.m_rotation = (hkQuaternionf)qi.m_vec.m_quad;
}

// File Line: 28
// RVA: 0xC09DE0
void __fastcall hkaiSilhouetteGenerator::hkaiSilhouetteGenerator(hkaiSilhouetteGenerator *this, hkFinishLoadedObjectFlag f)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkaiSilhouetteGenerator::`vftable';
}

// File Line: 33
// RVA: 0xC09E00
void __fastcall hkaiSilhouetteGenerator::~hkaiSilhouetteGenerator(hkaiSilhouetteGenerator *this)
{
  hkaiSilhouetteGenerator *v1; // rbx
  hkaiConvexSilhouetteSet *v2; // rcx

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiSilhouetteGenerator::`vftable';
  v2 = this->m_cachedSilhouettes.m_pntr;
  if ( v2 )
    hkReferencedObject::removeReference((hkReferencedObject *)&v2->vfptr);
  v1->m_cachedSilhouettes.m_pntr = 0i64;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
}

// File Line: 38
// RVA: 0xC09E40
char __fastcall hkaiSilhouetteGenerator::willGenerateSilhouettes(hkaiSilhouetteGenerator *this, hkaiNavMeshInstance *meshInstance, hkVector4f *up)
{
  return 1;
}

// File Line: 43
// RVA: 0xC09E50
void __fastcall hkaiSilhouetteGenerator::shiftWorldSpace(hkaiSilhouetteGenerator *this, hkVector4f *shift)
{
  this->m_transform.m_translation.m_quad = _mm_add_ps(shift->m_quad, this->m_transform.m_translation.m_quad);
}

// File Line: 50
// RVA: 0xC09E70
_BOOL8 __usercall hkaiSilhouetteGenerator::canReuseCachedSilhouettes@<rax>(hkaiSilhouetteGenerator *this@<rcx>, hkQTransformf *localTransform@<rdx>, hkVector4f *referenceUp@<r8>, __m128 a4@<xmm0>)
{
  hkQTransformf *v4; // r9
  hkaiConvexSilhouetteSet *v5; // rdx
  float v6; // xmm2_4
  _BOOL8 result; // rax

  v4 = localTransform;
  v5 = this->m_cachedSilhouettes.m_pntr;
  result = 0;
  if ( v5 )
  {
    if ( v5->m_silhouetteOffsets.m_size > 0 )
    {
      v6 = this->m_lazyRecomputeDisplacementThreshold;
      a4.m128_f32[0] = v6;
      if ( (_mm_movemask_ps(
              _mm_cmpltps(
                (__m128)_mm_srli_epi32(
                          _mm_slli_epi32((__m128i)_mm_sub_ps(referenceUp->m_quad, v5->m_cachedUp.m_quad), 1u),
                          1u),
                _mm_shuffle_ps(a4, a4, 0))) & 7) == 7
        && hkQTransformf::isApproximatelyEqual(v4, &v5->m_cachedTransform, v6) )
      {
        result = 1;
      }
    }
  }
  return result;
}

// File Line: 58
// RVA: 0xC0A180
hkSimdFloat32 *__fastcall getTranslationalDisplacement(hkSimdFloat32 *result, hkQTransformf *prevTransform, hkQTransformf *currTransform)
{
  hkSimdFloat32 *v3; // rax
  __m128 v4; // xmm1
  __m128 v5; // xmm1
  __m128 v6; // xmm4
  __m128 v7; // xmm1

  v3 = result;
  v4 = _mm_sub_ps(currTransform->m_translation.m_quad, prevTransform->m_translation.m_quad);
  v5 = _mm_mul_ps(v4, v4);
  v6 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v5, v5, 85), _mm_shuffle_ps(v5, v5, 0)), _mm_shuffle_ps(v5, v5, 170));
  v7 = _mm_rsqrt_ps(v6);
  result->m_real = _mm_andnot_ps(
                     _mm_cmpleps(v6, (__m128)0i64),
                     _mm_mul_ps(
                       _mm_mul_ps(
                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v7, v6), v7)),
                         _mm_mul_ps(*(__m128 *)_xmm, v7)),
                       v6));
  return v3;
}

// File Line: 65
// RVA: 0xC0A1F0
hkSimdFloat32 *__fastcall getRotationalDisplacement(hkSimdFloat32 *result, hkaiSilhouetteGenerator *gen, hkQTransformf *prevTransform, hkQTransformf *currTransform)
{
  hkSimdFloat32 *v4; // rbx
  __m128 v5; // xmm4
  __m128 v6; // xmm5
  __m128 v7; // xmm9
  __m128 v8; // xmm1
  __m128 v9; // xmm3
  __m128 v10; // xmm0
  __m128 v11; // xmm5
  __m128 v12; // xmm9
  __m128 v13; // xmm9
  __m128 v14; // xmm9
  __m128 v15; // xmm0
  __m128 v16; // xmm1
  __m128 v17; // xmm2
  __m128 v18; // xmm3
  __m128 v19; // xmm9
  __m128 v20; // xmm9
  __m128 v21; // xmm7
  __m128 v22; // xmm6
  __m128 v23; // xmm2
  __m128 v24; // xmm5
  __m128 v25; // xmm4
  __m128 v26; // xmm3
  __m128 v27; // xmm2
  __m128 v28; // xmm1
  hkSimdFloat32 *v29; // rax
  __m128 v30; // xmm3
  __m128 v31; // xmm4
  __m128 v32; // xmm1
  __m128 v33; // [rsp+20h] [rbp-88h]
  __m128 v34; // [rsp+30h] [rbp-78h]

  v4 = result;
  v5 = _mm_shuffle_ps(currTransform->m_rotation.m_vec.m_quad, currTransform->m_rotation.m_vec.m_quad, 255);
  v6 = _mm_xor_ps(
         (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64),
         prevTransform->m_rotation.m_vec.m_quad);
  v7 = _mm_mul_ps(
         _mm_shuffle_ps(currTransform->m_rotation.m_vec.m_quad, currTransform->m_rotation.m_vec.m_quad, 201),
         v6);
  v8 = _mm_mul_ps(v6, v5);
  v9 = _mm_shuffle_ps(v6, v6, 255);
  v10 = _mm_mul_ps(_mm_shuffle_ps(v6, v6, 201), currTransform->m_rotation.m_vec.m_quad);
  v11 = _mm_mul_ps(v6, currTransform->m_rotation.m_vec.m_quad);
  v12 = _mm_sub_ps(v7, v10);
  v13 = _mm_add_ps(
          _mm_add_ps(_mm_shuffle_ps(v12, v12, 201), _mm_mul_ps(currTransform->m_rotation.m_vec.m_quad, v9)),
          v8);
  v14 = _mm_shuffle_ps(
          v13,
          _mm_unpackhi_ps(
            v13,
            _mm_sub_ps(
              _mm_mul_ps(v5, v9),
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)),
                _mm_shuffle_ps(v11, v11, 170)))),
          196);
  v15 = _mm_mul_ps(v14, v14);
  v16 = _mm_add_ps(_mm_shuffle_ps(v15, v15, 78), v15);
  v17 = _mm_add_ps(_mm_shuffle_ps(v16, v16, 177), v16);
  v18 = _mm_rsqrt_ps(v17);
  v19 = _mm_mul_ps(
          v14,
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v18, v17), v18)), _mm_mul_ps(*(__m128 *)_xmm, v18)));
  v20 = (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_shuffle_ps(v19, v19, 255), 1u), 1u);
  v21 = _mm_andnot_ps(*(__m128 *)_xmm, v20);
  v22 = _mm_cmpltps(v21, *(__m128 *)_xmm);
  v23 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)_xmm, v21), *(__m128 *)_xmm);
  v24 = _mm_cmpltps(*(__m128 *)_xmm, v21);
  v25 = _mm_or_ps(_mm_and_ps(_mm_sqrt_ps(v23), v24), _mm_andnot_ps(v24, v21));
  v26 = _mm_or_ps(_mm_andnot_ps(v24, _mm_mul_ps(v21, v21)), _mm_and_ps(v24, v23));
  v27 = _mm_add_ps(
          _mm_mul_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v26, *(__m128 *)coeff4), *(__m128 *)coeff3), v26),
                        *(__m128 *)coeff2),
                      v26),
                    *(__m128 *)coeff1),
                  v26),
                *(__m128 *)coeff0),
              v26),
            v25),
          v25);
  v15.m128_f32[0] = (float)(1.5707964
                          - COERCE_FLOAT((*(unsigned __int128 *)&_mm_andnot_ps(
                                                                   v22,
                                                                   _mm_or_ps(
                                                                     _mm_and_ps(
                                                                       _mm_sub_ps(*(__m128 *)_xmm, _mm_add_ps(v27, v27)),
                                                                       v24),
                                                                     _mm_andnot_ps(v24, v27))) | v22.m128_i32[0] & v21.m128_i32[0]) ^ v20.m128_i32[0] & _xmm[0]))
                  * 2.0;
  gen->vfptr[4].__vecDelDtor((hkBaseObject *)gen, (unsigned int)&v33);
  v28 = _mm_mul_ps(v34, v34);
  v29 = v4;
  v30 = _mm_mul_ps(v33, v33);
  v31 = _mm_max_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v30, v30, 85), _mm_shuffle_ps(v30, v30, 0)),
            _mm_shuffle_ps(v30, v30, 170)),
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v28, v28, 85), _mm_shuffle_ps(v28, v28, 0)),
            _mm_shuffle_ps(v28, v28, 170)));
  v32 = _mm_rsqrt_ps(v31);
  v4->m_real = _mm_mul_ps(
                 _mm_andnot_ps(
                   _mm_cmpleps(v31, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_mul_ps(
                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v31, v32), v32)),
                       _mm_mul_ps(*(__m128 *)_xmm, v32)),
                     v31)),
                 _mm_shuffle_ps((__m128)v15.m128_u32[0], (__m128)v15.m128_u32[0], 0));
  return v29;
}

// File Line: 90
// RVA: 0xC09EE0
hkSimdFloat32 *__fastcall hkaiSilhouetteGenerator::getDisplacementRelativeToSection(hkaiSilhouetteGenerator *this, hkSimdFloat32 *result, hkQTransformf *prevTransform, hkQTransformf *currTransform)
{
  hkSimdFloat32 *v4; // rbx
  hkQTransformf *v5; // r9
  hkaiSilhouetteGenerator *v6; // r10
  hkQTransformf *v7; // r11
  hkSimdFloat32 *v8; // rax
  hkSimdFloat32 resulta; // [rsp+20h] [rbp-18h]

  v4 = result;
  getTranslationalDisplacement(result, prevTransform, currTransform);
  getRotationalDisplacement(&resulta, v6, v7, v5);
  v8 = v4;
  v4->m_real = _mm_add_ps(v4->m_real, resulta.m_real);
  return v8;
}

// File Line: 100
// RVA: 0xC09F30
signed __int64 __fastcall hkaiSilhouetteGenerator::hasMovedAgainstSection(hkaiSilhouetteGenerator *this, hkQTransformf *prevTransform, hkQTransformf *currTransform)
{
  float v3; // xmm7_4
  hkQTransformf *v4; // rdx
  hkQTransformf *v5; // r8
  hkaiSilhouetteGenerator *v6; // r10
  float v7; // xmm6_4
  unsigned int v8; // ebx
  signed __int64 v9; // rax
  hkSimdFloat32 result; // [rsp+20h] [rbp-38h]

  LODWORD(v3) = (unsigned __int128)_mm_shuffle_ps(
                                     (__m128)LODWORD(this->m_lazyRecomputeDisplacementThreshold),
                                     (__m128)LODWORD(this->m_lazyRecomputeDisplacementThreshold),
                                     0);
  getTranslationalDisplacement(&result, prevTransform, currTransform);
  v7 = result.m_real.m128_f32[0];
  v8 = 0;
  v9 = 0i64;
  if ( result.m_real.m128_f32[0] >= v3 )
    v9 = 1i64;
  if ( !(_DWORD)v9 )
  {
    getRotationalDisplacement(&result, v6, v4, v5);
    if ( (float)(v7 + result.m_real.m128_f32[0]) >= v3 )
      v8 = 1;
    v9 = v8;
  }
  return v9;
}

// File Line: 121
// RVA: 0xC09FC0
void __fastcall hkaiSilhouetteGenerator::expandAabb(hkAabb *aabbInOut, hkVector4f *up, hkSimdFloat32 *extrusion, hkSimdFloat32 *planarExpansion, unsigned int expansionFlags)
{
  __m128 v5; // xmm9
  __m128 v6; // xmm10
  __m128 v7; // xmm11
  __m128 v8; // xmm0
  __m128 v9; // xmm6
  __m128 v10; // xmm5
  __m128 v11; // xmm6
  __m128 v12; // xmm1
  __m128 v13; // xmm3
  __m128 v14; // xmm1
  __m128 v15; // xmm2
  __m128 v16; // xmm4
  __m128 v17; // xmm7
  __m128 v18; // xmm1
  __m128 v19; // xmm7
  __m128 v20; // xmm3
  __m128 v21; // xmm2
  __m128 v22; // xmm0
  __m128 v23; // xmm1

  v5 = aabbInOut->m_max.m_quad;
  v6 = aabbInOut->m_min.m_quad;
  v7 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_1_45), (__m128)LODWORD(FLOAT_1_45), 0);
  if ( expansionFlags & 4 )
  {
    v8 = _mm_max_ps(_mm_mul_ps(planarExpansion->m_real, v7), extrusion->m_real);
    v5 = _mm_add_ps(v5, v8);
    v6 = _mm_sub_ps(v6, v8);
  }
  else
  {
    if ( expansionFlags & 2 )
    {
      v9 = _mm_shuffle_ps(up->m_quad, _mm_unpackhi_ps(up->m_quad, (__m128)0i64), 196);
      v10 = _mm_shuffle_ps(v9, v9, 241);
      v11 = _mm_shuffle_ps(v9, v9, 206);
      v12 = _mm_mul_ps(v10, v10);
      v13 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)),
              _mm_shuffle_ps(v12, v12, 170));
      v14 = _mm_mul_ps(v11, v11);
      v15 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)),
              _mm_shuffle_ps(v14, v14, 170));
      v16 = _mm_max_ps(v13, v15);
      v17 = _mm_cmpltps(v13, v15);
      v18 = _mm_rsqrt_ps(v16);
      v19 = _mm_xor_ps(
              _mm_or_ps(_mm_andnot_ps(v17, v10), _mm_and_ps(v11, v17)),
              (__m128)_mm_insert_epi16((__m128i)0i64, 0x8000u, 1));
      v20 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(up->m_quad, up->m_quad, 201), v19),
              _mm_mul_ps(_mm_shuffle_ps(v19, v19, 201), up->m_quad));
      v21 = _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v16, v18), v18)),
              _mm_mul_ps(*(__m128 *)_xmm, v18));
      v22 = _mm_mul_ps(
              _mm_mul_ps(planarExpansion->m_real, v7),
              _mm_add_ps(
                (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_mul_ps(_mm_shuffle_ps(v20, v20, 201), v21), 1u), 1u),
                (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_mul_ps(v19, v21), 1u), 1u)));
      v6 = _mm_sub_ps(v6, v22);
      v5 = _mm_add_ps(v5, v22);
    }
    if ( expansionFlags & 1 )
    {
      v23 = _mm_mul_ps(_mm_sub_ps((__m128)0i64, extrusion->m_real), up->m_quad);
      v5 = _mm_max_ps(v5, _mm_add_ps(v23, v5));
      v6 = _mm_min_ps(v6, _mm_add_ps(v23, v6));
    }
  }
  aabbInOut->m_min.m_quad = v6;
  aabbInOut->m_max.m_quad = v5;
}

