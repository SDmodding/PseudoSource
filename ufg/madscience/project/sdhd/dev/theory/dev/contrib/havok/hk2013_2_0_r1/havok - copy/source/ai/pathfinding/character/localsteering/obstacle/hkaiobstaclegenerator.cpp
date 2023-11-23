// File Line: 26
// RVA: 0xBF3E60
void __fastcall hkaiObstacleGenerator::hkaiObstacleGenerator(hkaiObstacleGenerator *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiObstacleGenerator::`vftable;
  *(_WORD *)&this->m_useSpheres.m_bool = 257;
  this->m_clipBoundaries.m_bool = 1;
  this->m_spheres.m_capacityAndFlags = 0x80000000;
  this->m_spheres.m_data = 0i64;
  this->m_spheres.m_size = 0;
  this->m_boundaries.m_data = 0i64;
  this->m_boundaries.m_size = 0;
  this->m_boundaries.m_capacityAndFlags = 0x80000000;
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
void __fastcall hkaiObstacleGenerator::appendObstacles(
        hkaiObstacleGenerator *this,
        hkAabb *sensorAabb,
        hkaiObstacleCollector *collectorInOut)
{
  int v3; // esi
  hkaiAvoidanceSolver::SphereObstacle *m_data; // rdi
  int v8; // ebp
  __m128 v9; // xmm4
  __m128 v10; // xmm2
  __m128 v11; // xmm2
  hkaiAvoidanceSolver::BoundaryObstacle *v12; // rdi
  hkaiAvoidanceSolver::SphereObstacle _sphere; // [rsp+20h] [rbp-48h] BYREF
  hkVector4f startInOut; // [rsp+40h] [rbp-28h] BYREF

  v3 = 0;
  if ( this->m_useSpheres.m_bool && this->m_spheres.m_size > 0 )
  {
    m_data = this->m_spheres.m_data;
    v8 = 0;
    do
    {
      hkVector4f::setTransformedPos(&startInOut, &this->m_transform, &m_data->m_sphere.m_pos);
      v9 = _mm_shuffle_ps(m_data->m_sphere.m_pos.m_quad, m_data->m_sphere.m_pos.m_quad, 255);
      v10 = _mm_sub_ps(
              _mm_min_ps(_mm_max_ps(startInOut.m_quad, sensorAabb->m_min.m_quad), sensorAabb->m_max.m_quad),
              startInOut.m_quad);
      v11 = _mm_mul_ps(v10, v10);
      if ( (float)((float)(_mm_shuffle_ps(v11, v11, 85).m128_f32[0] + _mm_shuffle_ps(v11, v11, 0).m128_f32[0])
                 + _mm_shuffle_ps(v11, v11, 170).m128_f32[0]) <= (float)(v9.m128_f32[0] * v9.m128_f32[0]) )
      {
        _sphere.m_velocity = m_data->m_velocity;
        _sphere.m_sphere.m_pos.m_quad = _mm_shuffle_ps(startInOut.m_quad, _mm_unpackhi_ps(startInOut.m_quad, v9), 196);
        hkaiObstacleCollector::addSphereObstacle(collectorInOut, &_sphere);
      }
      ++v8;
      ++m_data;
    }
    while ( v8 < this->m_spheres.m_size );
  }
  if ( this->m_useBoundaries.m_bool && this->m_boundaries.m_size > 0 )
  {
    v12 = this->m_boundaries.m_data;
    do
    {
      hkVector4f::setTransformedPos(&startInOut, &this->m_transform, &v12->m_start);
      hkVector4f::setTransformedPos(&_sphere.m_sphere.m_pos, &this->m_transform, &v12->m_end);
      if ( !this->m_clipBoundaries.m_bool
        || hkaiAvoidanceSolverUtils::clipSegmentInsideAabb(sensorAabb, &startInOut, &_sphere.m_sphere.m_pos) )
      {
        hkaiObstacleCollector::addBoundary(collectorInOut, &startInOut, &_sphere.m_sphere.m_pos);
      }
      ++v3;
      ++v12;
    }
    while ( v3 < this->m_boundaries.m_size );
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
void __fastcall hkaiObstacleGenerator::updateSphereVelocities(
        hkaiObstacleGenerator *this,
        hkVector4f *linearVelocity,
        hkVector4f *angularVelocity)
{
  int v3; // r9d
  __int64 v4; // r10
  hkaiAvoidanceSolver::SphereObstacle *m_data; // rax
  __m128 m_quad; // xmm1
  __m128 v7; // xmm2
  __m128 v8; // xmm2

  v3 = 0;
  if ( this->m_spheres.m_size > 0 )
  {
    v4 = 0i64;
    do
    {
      m_data = this->m_spheres.m_data;
      ++v3;
      m_quad = m_data[v4++].m_sphere.m_pos.m_quad;
      v7 = _mm_add_ps(
             _mm_add_ps(
               _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 0), this->m_transform.m_rotation.m_col0.m_quad),
               _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 85), this->m_transform.m_rotation.m_col1.m_quad)),
             _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 170), this->m_transform.m_rotation.m_col2.m_quad));
      v8 = _mm_sub_ps(
             _mm_mul_ps(_mm_shuffle_ps(v7, v7, 201), angularVelocity->m_quad),
             _mm_mul_ps(_mm_shuffle_ps(angularVelocity->m_quad, angularVelocity->m_quad, 201), v7));
      m_data[v4 - 1].m_velocity.m_quad = _mm_add_ps(_mm_shuffle_ps(v8, v8, 201), linearVelocity->m_quad);
    }
    while ( v3 < this->m_spheres.m_size );
  }
}

// File Line: 118
// RVA: 0xBF3F70
void __fastcall hkaiObstacleGenerator::calcLocalAabb(hkaiObstacleGenerator *this, hkAabb *aabbOut)
{
  hkVector4f v2; // xmm4
  __int64 m_size; // r8
  hkVector4f v5; // xmm3
  hkaiAvoidanceSolver::SphereObstacle *m_data; // rcx
  __m128 m_quad; // xmm2
  __m128 v8; // xmm0
  __m128 v9; // xmm1
  __m128 v10; // xmm2
  __int64 v11; // rcx
  hkaiAvoidanceSolver::BoundaryObstacle *v12; // rax
  __m128 v13; // xmm4
  __m128 v14; // xmm3

  v2.m_quad = (__m128)xmmword_141A712A0;
  m_size = this->m_spheres.m_size;
  v5.m_quad = _mm_xor_ps(
                (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                (__m128)xmmword_141A712A0);
  if ( m_size > 0 )
  {
    m_data = this->m_spheres.m_data;
    do
    {
      m_quad = m_data->m_sphere.m_pos.m_quad;
      ++m_data;
      v8 = _mm_shuffle_ps(m_quad, m_quad, 255);
      v9 = _mm_sub_ps(m_quad, v8);
      v10 = _mm_add_ps(m_quad, v8);
      v2.m_quad = _mm_min_ps(_mm_min_ps(v2.m_quad, v9), v10);
      v5.m_quad = _mm_max_ps(_mm_max_ps(v5.m_quad, v9), v10);
      --m_size;
    }
    while ( m_size );
  }
  v11 = this->m_boundaries.m_size;
  if ( v11 > 0 )
  {
    v12 = this->m_boundaries.m_data;
    do
    {
      v13 = _mm_min_ps(v2.m_quad, v12->m_start.m_quad);
      v14 = _mm_max_ps(v5.m_quad, v12->m_start.m_quad);
      ++v12;
      v2.m_quad = _mm_min_ps(v13, v12[-1].m_end.m_quad);
      v5.m_quad = _mm_max_ps(v14, v12[-1].m_end.m_quad);
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
  hkSimdFloat32 extraRadius; // [rsp+20h] [rbp-38h] BYREF
  hkAabb aabbOuta; // [rsp+30h] [rbp-28h] BYREF

  hkaiObstacleGenerator::calcLocalAabb(this, &aabbOuta);
  extraRadius.m_real = 0i64;
  hkAabbUtil::calcAabb(&this->m_transform, &aabbOuta, &extraRadius, aabbOut);
}

