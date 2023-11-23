// File Line: 17
// RVA: 0xC1C3F0
float __fastcall hkaiDefaultSilhouettePriorityController::getGeneratorAddedPriority(
        hkaiDefaultSilhouettePriorityController *this,
        hkaiSilhouetteGenerator *gen,
        hkAabb *aabb,
        hkVector4f *up)
{
  hkSimdFloat32 result; // [rsp+20h] [rbp-18h] BYREF

  return hkaiDefaultSilhouettePriorityController::getProjectedAabbArea(&result, aabb, up)->m_real.m128_f32[0];
}

// File Line: 22
// RVA: 0xC1C420
float __fastcall hkaiDefaultSilhouettePriorityController::getGeneratorRemovedPriority(
        hkaiDefaultSilhouettePriorityController *this,
        hkaiSilhouetteGenerator *gen,
        hkAabb *aabb,
        hkVector4f *up)
{
  hkSimdFloat32 result; // [rsp+20h] [rbp-18h] BYREF

  return hkaiDefaultSilhouettePriorityController::getProjectedAabbArea(&result, aabb, up)->m_real.m128_f32[0];
}

// File Line: 27
// RVA: 0xC1C450
float __fastcall hkaiDefaultSilhouettePriorityController::getGeneratorMovedPriority(
        hkaiDefaultSilhouettePriorityController *this,
        hkaiSilhouetteGenerator *gen,
        hkAabb *aabb,
        hkVector4f *up,
        hkQTransformf *prevTransform,
        hkQTransformf *currTransform)
{
  hkSimdFloat32 *ProjectedAabbArea; // rax
  hkSimdFloat32 result; // [rsp+20h] [rbp-28h] BYREF
  hkSimdFloat32 v11; // [rsp+30h] [rbp-18h] BYREF

  hkaiSilhouetteGenerator::getDisplacementRelativeToSection(gen, &result, prevTransform, currTransform);
  ProjectedAabbArea = hkaiDefaultSilhouettePriorityController::getProjectedAabbArea(&v11, aabb, up);
  return ProjectedAabbArea->m_real.m128_f32[0] * result.m_real.m128_f32[0];
}

// File Line: 33
// RVA: 0xC1C560
hkSimdFloat32 *__fastcall hkaiDefaultSilhouettePriorityController::getProjectedAabbArea(
        hkSimdFloat32 *result,
        hkAabb *aabb,
        hkVector4f *up)
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
void __fastcall hkaiDefaultSilhouettePriorityController::sortSilhouetteGenerators(
        hkaiDefaultSilhouettePriorityController *this,
        hkArrayBase<hkaiSilhouetteGeneratorSectionContext const *> *contexts)
{
  __int64 m_size; // r14
  hkaiSilhouetteGeneratorSectionContext **m_data; // rbx
  int v4; // ebp
  __int64 i; // rsi
  __m128 *p_m_quad; // rdi
  int v7; // r8d
  __int64 j; // rdx
  __m128 *v9; // r9
  int v10; // r10d
  int v11; // r11d
  BOOL v12; // eax

  m_size = contexts->m_size;
  m_data = contexts->m_data;
  v4 = 0;
  for ( i = 0i64; i < m_size; m_data[j] = (hkaiSilhouetteGeneratorSectionContext *)p_m_quad )
  {
    p_m_quad = &m_data[i]->m_lastRelativeTransform.m_rotation.m_vec.m_quad;
    v7 = v4;
    for ( j = i; v7 > 0; m_data[j--] = (hkaiSilhouetteGeneratorSectionContext *)v9 )
    {
      v9 = &m_data[j - 1]->m_lastRelativeTransform.m_rotation.m_vec.m_quad;
      v10 = *(_DWORD *)(p_m_quad[2].m128_u64[0] + 32);
      v11 = *(_DWORD *)(v9[2].m128_u64[0] + 32);
      if ( v10 == v11 )
        v12 = _mm_shuffle_ps(p_m_quad[1], p_m_quad[1], 0).m128_f32[0] < _mm_shuffle_ps(v9[1], v9[1], 0).m128_f32[0];
      else
        v12 = v10 < v11;
      if ( !v12 )
        break;
      --v7;
    }
    ++i;
    ++v4;
  }
}

