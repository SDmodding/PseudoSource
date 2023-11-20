// File Line: 26
// RVA: 0xBF3E60
void __fastcall hkaiObstacleGenerator::hkaiObstacleGenerator(hkaiObstacleGenerator *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiObstacleGenerator::`vftable;
  *(_WORD *)&this->m_useSpheres.m_bool = 257;
  this->m_clipBoundaries.m_bool = 1;
  this->m_spheres.m_capacityAndFlags = 2147483648;
  this->m_spheres.m_data = 0i64;
  this->m_spheres.m_size = 0;
  this->m_boundaries.m_data = 0i64;
  this->m_boundaries.m_size = 0;
  this->m_boundaries.m_capacityAndFlags = 2147483648;
  this->m_userData = 0i64;
  this->m_transform.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  this->m_transform.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  this->m_transform.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_transform.m_translation = 0i64;
}

// File Line: 34
// RVA: 0xBF3EE0
void __fastcall hkaiObstacleGenerator::hkaiObstacleGenerator(hkaiObstacleGenerator *this, hkFinishLoadedObjectFlag f)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkaiObstacleGenerator::`vftable;
}

// File Line: 39
// RVA: 0xBF4010
void __fastcall hkaiObstacleGenerator::appendObstacles(hkaiObstacleGenerator *this, hkAabb *sensorAabb, hkaiObstacleCollector *collectorInOut)
{
  int v3; // esi
  hkaiObstacleCollector *v4; // r14
  hkAabb *v5; // r15
  hkaiObstacleGenerator *v6; // rbx
  hkaiAvoidanceSolver::SphereObstacle *v7; // rdi
  int v8; // ebp
  __m128 v9; // xmm4
  __m128 v10; // xmm2
  __m128 v11; // xmm2
  hkVector4f *v12; // rdi
  hkaiAvoidanceSolver::SphereObstacle _sphere; // [rsp+20h] [rbp-48h]
  hkVector4f startInOut; // [rsp+40h] [rbp-28h]

  v3 = 0;
  v4 = collectorInOut;
  v5 = sensorAabb;
  v6 = this;
  if ( this->m_useSpheres.m_bool && this->m_spheres.m_size > 0 )
  {
    v7 = this->m_spheres.m_data;
    v8 = 0;
    do
    {
      hkVector4f::setTransformedPos(&startInOut, &v6->m_transform, &v7->m_sphere.m_pos);
      v9 = _mm_shuffle_ps(v7->m_sphere.m_pos.m_quad, v7->m_sphere.m_pos.m_quad, 255);
      v10 = _mm_sub_ps(_mm_min_ps(_mm_max_ps(startInOut.m_quad, v5->m_min.m_quad), v5->m_max.m_quad), startInOut.m_quad);
      v11 = _mm_mul_ps(v10, v10);
      if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 0)))
                 + COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 170))) <= (float)(v9.m128_f32[0] * v9.m128_f32[0]) )
      {
        _sphere.m_velocity = v7->m_velocity;
        _sphere.m_sphere.m_pos.m_quad = _mm_shuffle_ps(startInOut.m_quad, _mm_unpackhi_ps(startInOut.m_quad, v9), 196);
        hkaiObstacleCollector::addSphereObstacle(v4, &_sphere);
      }
      ++v8;
      ++v7;
    }
    while ( v8 < v6->m_spheres.m_size );
  }
  if ( v6->m_useBoundaries.m_bool && v6->m_boundaries.m_size > 0 )
  {
    v12 = &v6->m_boundaries.m_data->m_start;
    do
    {
      hkVector4f::setTransformedPos(&startInOut, &v6->m_transform, v12);
      hkVector4f::setTransformedPos(&_sphere.m_sphere.m_pos, &v6->m_transform, v12 + 1);
      if ( !v6->m_clipBoundaries.m_bool
        || hkaiAvoidanceSolverUtils::clipSegmentInsideAabb(v5, &startInOut, &_sphere.m_sphere.m_pos) )
      {
        hkaiObstacleCollector::addBoundary(v4, &startInOut, &_sphere.m_sphere.m_pos);
      }
      ++v3;
      v12 += 2;
    }
    while ( v3 < v6->m_boundaries.m_size );
  }
}

// File Line: 98
// RVA: 0xBF3F50
void __fastcall hkaiObstacleGenerator::shiftWorldSpace(hkaiObstacleGenerator *this, hkVector4f *shift)
{
  this->m_transform.m_translation.m_quad = _mm_add_ps(shift->m_quad, this->m_transform.m_translation.m_quad);
}

// File Line: 106
// RVA: 0xBF4170
void __fastcall hkaiObstacleGenerator::updateSphereVelocities(hkaiObstacleGenerator *this, hkVector4f *linearVelocity, hkVector4f *angularVelocity)
{
  int v3; // er9
  __int64 v4; // r10
  hkaiAvoidanceSolver::SphereObstacle *v5; // rax
  __m128 v6; // xmm1
  __m128 v7; // xmm2
  __m128 v8; // xmm2

  v3 = 0;
  if ( this->m_spheres.m_size > 0 )
  {
    v4 = 0i64;
    do
    {
      v5 = this->m_spheres.m_data;
      ++v3;
      ++v4;
      v6 = v5[v4 - 1].m_sphere.m_pos.m_quad;
      v7 = _mm_add_ps(
             _mm_add_ps(
               _mm_mul_ps(_mm_shuffle_ps(v6, v6, 0), this->m_transform.m_rotation.m_col0.m_quad),
               _mm_mul_ps(
                 _mm_shuffle_ps(v5[v4 - 1].m_sphere.m_pos.m_quad, v6, 85),
                 this->m_transform.m_rotation.m_col1.m_quad)),
             _mm_mul_ps(_mm_shuffle_ps(v6, v6, 170), this->m_transform.m_rotation.m_col2.m_quad));
      v8 = _mm_sub_ps(
             _mm_mul_ps(_mm_shuffle_ps(v7, v7, 201), angularVelocity->m_quad),
             _mm_mul_ps(_mm_shuffle_ps(angularVelocity->m_quad, angularVelocity->m_quad, 201), v7));
      *((__m128 *)&v5[v4] - 1) = _mm_add_ps(_mm_shuffle_ps(v8, v8, 201), linearVelocity->m_quad);
    }
    while ( v3 < this->m_spheres.m_size );
  }
}

// File Line: 118
// RVA: 0xBF3F70
void __fastcall hkaiObstacleGenerator::calcLocalAabb(hkaiObstacleGenerator *this, hkAabb *aabbOut)
{
  hkVector4f v2; // xmm4
  hkaiObstacleGenerator *v3; // rax
  __int64 v4; // r8
  hkVector4f v5; // xmm3
  hkaiAvoidanceSolver::SphereObstacle *v6; // rcx
  __m128 v7; // xmm2
  __m128 v8; // xmm0
  __m128 v9; // xmm1
  __m128 v10; // xmm2
  __int64 v11; // rcx
  __m128 *v12; // rax
  __m128 v13; // xmm4
  __m128 v14; // xmm3

  v2.m_quad = (__m128)xmmword_141A712A0;
  v3 = this;
  v4 = this->m_spheres.m_size;
  v5.m_quad = _mm_xor_ps(
                (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                (__m128)xmmword_141A712A0);
  if ( v4 > 0 )
  {
    v6 = this->m_spheres.m_data;
    do
    {
      v7 = v6->m_sphere.m_pos.m_quad;
      ++v6;
      v8 = _mm_shuffle_ps(v7, v7, 255);
      v9 = _mm_sub_ps(v7, v8);
      v10 = _mm_add_ps(v7, v8);
      v2.m_quad = _mm_min_ps(_mm_min_ps(v2.m_quad, v9), v10);
      v5.m_quad = _mm_max_ps(_mm_max_ps(v5.m_quad, v9), v10);
      --v4;
    }
    while ( v4 );
  }
  v11 = v3->m_boundaries.m_size;
  if ( v11 > 0 )
  {
    v12 = &v3->m_boundaries.m_data->m_start.m_quad;
    do
    {
      v13 = _mm_min_ps(v2.m_quad, *v12);
      v14 = _mm_max_ps(v5.m_quad, *v12);
      v12 += 2;
      v2.m_quad = _mm_min_ps(v13, v12[-1]);
      v5.m_quad = _mm_max_ps(v14, v12[-1]);
      --v11;
    }
    while ( v11 );
  }
  aabbOut->m_max = (hkVector4f)v5.m_quad;
  aabbOut->m_min = (hkVector4f)v2.m_quad;
}

// File Line: 140
// RVA: 0xBF3F00
void __fastcall hkaiObstacleGenerator::getAabb(hkaiObstacleGenerator *this, hkAabb *aabbOut)
{
  hkAabb *v2; // rdi
  hkaiObstacleGenerator *v3; // rbx
  hkSimdFloat32 extraRadius; // [rsp+20h] [rbp-38h]
  hkAabb aabbOuta; // [rsp+30h] [rbp-28h]

  v2 = aabbOut;
  v3 = this;
  hkaiObstacleGenerator::calcLocalAabb(this, &aabbOuta);
  extraRadius.m_real = 0i64;
  hkAabbUtil::calcAabb(&v3->m_transform, &aabbOuta, &extraRadius, v2);
}

