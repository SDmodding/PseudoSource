// File Line: 17
// RVA: 0xC1C3F0
float __fastcall hkaiDefaultSilhouettePriorityController::getGeneratorAddedPriority(hkaiDefaultSilhouettePriorityController *this, hkaiSilhouetteGenerator *gen, hkAabb *aabb, hkVector4f *up)
{
  __int128 v4; // xmm0
  hkSimdFloat32 result; // [rsp+20h] [rbp-18h]

  v4 = hkaiDefaultSilhouettePriorityController::getProjectedAabbArea(&result, aabb, up)->m_real.m128_u32[0];
  return *(float *)&v4;
}

// File Line: 22
// RVA: 0xC1C420
float __fastcall hkaiDefaultSilhouettePriorityController::getGeneratorRemovedPriority(hkaiDefaultSilhouettePriorityController *this, hkaiSilhouetteGenerator *gen, hkAabb *aabb, hkVector4f *up)
{
  __int128 v4; // xmm0
  hkSimdFloat32 result; // [rsp+20h] [rbp-18h]

  v4 = hkaiDefaultSilhouettePriorityController::getProjectedAabbArea(&result, aabb, up)->m_real.m128_u32[0];
  return *(float *)&v4;
}

// File Line: 27
// RVA: 0xC1C450
float __fastcall hkaiDefaultSilhouettePriorityController::getGeneratorMovedPriority(hkaiDefaultSilhouettePriorityController *this, hkaiSilhouetteGenerator *gen, hkAabb *aabb, hkVector4f *up, hkQTransformf *prevTransform, hkQTransformf *currTransform)
{
  hkVector4f *v6; // rbx
  hkAabb *v7; // rdi
  hkSimdFloat32 *v8; // rax
  hkSimdFloat32 result; // [rsp+20h] [rbp-28h]
  hkSimdFloat32 v11; // [rsp+30h] [rbp-18h]

  v6 = up;
  v7 = aabb;
  hkaiSilhouetteGenerator::getDisplacementRelativeToSection(gen, &result, prevTransform, currTransform);
  v8 = hkaiDefaultSilhouettePriorityController::getProjectedAabbArea(&v11, v7, v6);
  return v8->m_real.m128_f32[0] * result.m_real.m128_f32[0];
}

// File Line: 33
// RVA: 0xC1C560
hkSimdFloat32 *__fastcall hkaiDefaultSilhouettePriorityController::getProjectedAabbArea(hkSimdFloat32 *result, hkAabb *aabb, hkVector4f *up)
{
  hkSimdFloat32 *v3; // rax
  __m128 v4; // xmm2

  v3 = result;
  v4 = _mm_add_ps(
         _mm_mul_ps(_mm_sub_ps(aabb->m_max.m_quad, aabb->m_min.m_quad), _mm_sub_ps(query.m_quad, up->m_quad)),
         up->m_quad);
  result->m_real = _mm_mul_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v4, v4, 85), _mm_shuffle_ps(v4, v4, 0)),
                     _mm_shuffle_ps(v4, v4, 170));
  return v3;
}

// File Line: 62
// RVA: 0xC1C4A0
void __fastcall hkaiDefaultSilhouettePriorityController::sortSilhouetteGenerators(hkaiDefaultSilhouettePriorityController *this, hkArrayBase<hkaiSilhouetteGeneratorSectionContext const *> *contexts)
{
  __int64 v2; // r14
  hkaiSilhouetteGeneratorSectionContext **v3; // rbx
  int v4; // ebp
  __int64 i; // rsi
  __m128 *v6; // rdi
  int v7; // er8
  __int64 j; // rdx
  __m128 *v9; // r9
  int v10; // er10
  int v11; // er11
  BOOL v12; // eax

  v2 = contexts->m_size;
  v3 = contexts->m_data;
  v4 = 0;
  for ( i = 0i64; i < v2; v3[j] = (hkaiSilhouetteGeneratorSectionContext *)v6 )
  {
    v6 = &v3[i]->m_lastRelativeTransform.m_rotation.m_vec.m_quad;
    v7 = v4;
    for ( j = i; v7 > 0; v3[j--] = (hkaiSilhouetteGeneratorSectionContext *)v9 )
    {
      v9 = &v3[j - 1]->m_lastRelativeTransform.m_rotation.m_vec.m_quad;
      v10 = *(_DWORD *)(v6[2].m128_u64[0] + 32);
      v11 = *(_DWORD *)(v9[2].m128_u64[0] + 32);
      if ( v10 == v11 )
      {
        v12 = 0;
        if ( COERCE_FLOAT(_mm_shuffle_ps(v6[1], v6[1], 0)) < COERCE_FLOAT(_mm_shuffle_ps(v9[1], v9[1], 0)) )
          v12 = 1;
      }
      else
      {
        v12 = v10 < v11;
      }
      if ( !v12 )
        break;
      --v7;
    }
    ++i;
    ++v4;
  }
}

