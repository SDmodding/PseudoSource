// File Line: 21
// RVA: 0xBDCEC0
void __fastcall hkaiObstacleCollector::hkaiObstacleCollector(
        hkaiObstacleCollector *this,
        int numAgents,
        hkVector4f *position,
        hkVector4f *up)
{
  int v6; // ebp
  hkaiAvoidanceSolver::SphereObstacle *v9; // rax
  hkaiAvoidanceSolver::SphereObstacle *v10; // rcx
  int v11; // ecx
  int v12; // eax
  hkaiAvoidanceSolver::BoundaryObstacle *v13; // rax
  hkaiAvoidanceSolver::BoundaryObstacle *v14; // rcx
  int v15; // ecx
  __int32 v16; // edx
  int v17; // eax
  hkaiAvoidanceSolver::ObstacleAgent *v18; // r8
  __m128 m_quad; // xmm0
  int v20; // eax
  int v21; // eax
  int v22; // r9d
  hkResult result; // [rsp+68h] [rbp+10h] BYREF

  this->m_spheres.m_data = 0i64;
  this->m_spheres.m_size = 0;
  v6 = 0x80000000;
  this->m_spheres.m_capacityAndFlags = 0x80000000;
  result.m_enum = 1024;
  v9 = (hkaiAvoidanceSolver::SphereObstacle *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                                &hkContainerTempAllocator::s_alloc,
                                                &result);
  this->m_spheres.m_size = 32;
  v10 = v9;
  LODWORD(v9) = result;
  result.m_enum = 1024;
  this->m_spheres.m_data = v10;
  v11 = 0x80000000;
  v12 = (int)v9 / 32;
  if ( v12 )
    v11 = v12;
  this->m_spheres.m_capacityAndFlags = v11;
  this->m_boundaries.m_data = 0i64;
  this->m_boundaries.m_size = 0;
  this->m_boundaries.m_capacityAndFlags = 0x80000000;
  v13 = (hkaiAvoidanceSolver::BoundaryObstacle *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                                   &hkContainerTempAllocator::s_alloc,
                                                   &result);
  this->m_boundaries.m_size = 32;
  v14 = v13;
  LODWORD(v13) = result;
  this->m_boundaries.m_data = v14;
  v15 = 0x80000000;
  v16 = numAgents;
  v17 = (int)v13 / 32;
  if ( v17 )
    v15 = v17;
  this->m_boundaries.m_capacityAndFlags = v15;
  this->m_neighborAgents.m_data = 0i64;
  this->m_neighborAgents.m_size = 0;
  this->m_neighborAgents.m_capacityAndFlags = 0x80000000;
  if ( numAgents )
  {
    result.m_enum = 80 * numAgents;
    v18 = (hkaiAvoidanceSolver::ObstacleAgent *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                                  &hkContainerTempAllocator::s_alloc,
                                                  &result);
    v16 = result.m_enum / 80;
  }
  else
  {
    v18 = 0i64;
  }
  this->m_neighborAgents.m_data = v18;
  this->m_neighborAgents.m_size = numAgents;
  if ( v16 )
    v6 = v16;
  this->m_neighborAgents.m_capacityAndFlags = v6;
  this->m_up = (hkVector4f)up->m_quad;
  m_quad = position->m_quad;
  this->m_referenceFrame = 0i64;
  this->m_position.m_quad = m_quad;
  this->m_spheres.m_size = 0;
  this->m_boundaries.m_size = 0;
  v20 = this->m_neighborAgents.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v20 < numAgents )
  {
    v21 = 2 * v20;
    v22 = numAgents;
    if ( numAgents < v21 )
      v22 = v21;
    hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, &this->m_neighborAgents, v22, 80);
  }
  this->m_neighborAgents.m_size = numAgents;
}

// File Line: 31
// RVA: 0xBDD0D0
void __fastcall hkaiObstacleCollector::addBoundary(hkaiObstacleCollector *this, hkVector4f *_A, hkVector4f *_B)
{
  __m128 m_quad; // xmm6
  __m128 v5; // xmm9
  hkaiReferenceFrame *m_referenceFrame; // rax
  __m128 v7; // xmm3
  __m128 v8; // xmm5
  __m128 v9; // xmm1
  __m128 v10; // xmm2
  __m128 v11; // xmm4
  __m128 v12; // xmm5
  hkVector4f v13; // xmm3
  __m128 v14; // xmm2
  __m128 v15; // xmm1
  __m128 v16; // xmm2
  __m128 v17; // xmm8
  __m128 v18; // xmm7
  hkaiAvoidanceSolver::BoundaryObstacle *v19; // rbp
  int v20; // esi
  float v21; // xmm6_4
  __int64 v22; // rdi
  hkaiAvoidanceSolver::BoundaryObstacle *v23; // rax
  hkVector4f B; // [rsp+20h] [rbp-78h] BYREF
  hkVector4f A; // [rsp+30h] [rbp-68h] BYREF
  hkSimdFloat32 result; // [rsp+40h] [rbp-58h] BYREF

  m_quad = _A->m_quad;
  v5 = _B->m_quad;
  B.m_quad = _B->m_quad;
  A.m_quad = m_quad;
  m_referenceFrame = this->m_referenceFrame;
  if ( m_referenceFrame )
  {
    v7 = m_referenceFrame->m_transform.m_rotation.m_col2.m_quad;
    v8 = _mm_sub_ps(m_quad, m_referenceFrame->m_transform.m_translation.m_quad);
    v9 = _mm_unpacklo_ps(
           m_referenceFrame->m_transform.m_rotation.m_col0.m_quad,
           m_referenceFrame->m_transform.m_rotation.m_col1.m_quad);
    v10 = _mm_movelh_ps(v9, v7);
    v11 = _mm_unpackhi_ps(
            m_referenceFrame->m_transform.m_rotation.m_col0.m_quad,
            m_referenceFrame->m_transform.m_rotation.m_col1.m_quad);
    m_quad = _mm_add_ps(
               _mm_add_ps(
                 _mm_mul_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(_mm_movehl_ps(v10, v9), v7, 212)),
                 _mm_mul_ps(_mm_shuffle_ps(v8, v8, 0), v10)),
               _mm_mul_ps(_mm_shuffle_ps(v8, v8, 170), _mm_shuffle_ps(v11, v7, 228)));
    v12 = _mm_sub_ps(v5, m_referenceFrame->m_transform.m_translation.m_quad);
    A.m_quad = m_quad;
    v5 = _mm_add_ps(
           _mm_add_ps(
             _mm_mul_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(_mm_movehl_ps(v10, v9), v7, 212)),
             _mm_mul_ps(_mm_shuffle_ps(v12, v12, 0), v10)),
           _mm_mul_ps(_mm_shuffle_ps(v12, v12, 170), _mm_shuffle_ps(v11, v7, 228)));
    B.m_quad = v5;
  }
  v13.m_quad = (__m128)this->m_up;
  v14 = _mm_mul_ps(v13.m_quad, m_quad);
  v15 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)), _mm_shuffle_ps(v14, v14, 170));
  v16 = _mm_mul_ps(v13.m_quad, v5);
  v17 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps((__m128)0i64, v15), v13.m_quad), m_quad);
  v18 = _mm_add_ps(
          _mm_mul_ps(
            _mm_sub_ps(
              (__m128)0i64,
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)),
                _mm_shuffle_ps(v16, v16, 170))),
            v13.m_quad),
          v5);
  if ( this->m_boundaries.m_size == 32 )
  {
    v19 = 0i64;
    hkaiObstacleCollector::getBoundaryDistance(this, &result, &A, &B);
    v20 = 0;
    if ( this->m_boundaries.m_size > 0 )
    {
      v21 = result.m_real.m128_f32[0];
      do
      {
        v22 = v20;
        hkaiObstacleCollector::getBoundaryDistance(this, &result, &this->m_boundaries.m_data[v22]);
        if ( result.m_real.m128_f32[0] > v21 )
        {
          v21 = result.m_real.m128_f32[0];
          v19 = &this->m_boundaries.m_data[v22];
        }
        ++v20;
      }
      while ( v20 < this->m_boundaries.m_size );
      if ( v19 )
      {
        v19->m_start.m_quad = v17;
        v19->m_end.m_quad = v18;
      }
    }
  }
  else
  {
    v23 = &this->m_boundaries.m_data[this->m_boundaries.m_size];
    v23->m_start.m_quad = v17;
    v23->m_end.m_quad = v18;
    ++this->m_boundaries.m_size;
  }
}

// File Line: 83
// RVA: 0xBDD300
void __fastcall hkaiObstacleCollector::addSphereObstacle(
        hkaiObstacleCollector *this,
        hkaiAvoidanceSolver::SphereObstacle *_sphere)
{
  hkVector4f v2; // xmm5
  hkaiReferenceFrame *m_referenceFrame; // rcx
  hkSphere v5; // xmm8
  hkaiReferenceFrame *v6; // rax
  __m128 v7; // xmm5
  __m128 m_quad; // xmm3
  __m128 v9; // xmm1
  __m128 v10; // xmm2
  __m128 v11; // xmm8
  hkVector4f v12; // xmm4
  __int64 m_size; // rax
  __m128 v14; // xmm2
  __m128 v15; // xmm1
  __m128 v16; // xmm2
  __m128 v17; // xmm7
  hkSphere v18; // xmm7
  hkaiAvoidanceSolver::SphereObstacle *v19; // rbp
  hkaiAvoidanceSolver::SphereObstacle *m_data; // rbx
  float v21; // xmm6_4
  __int64 v22; // rsi
  hkaiAvoidanceSolver::SphereObstacle *v23; // rax
  hkSimdFloat32 result; // [rsp+20h] [rbp-68h] BYREF
  hkaiAvoidanceSolver::SphereObstacle sphere; // [rsp+30h] [rbp-58h] BYREF

  v2.m_quad = (__m128)_sphere->m_velocity;
  m_referenceFrame = this->m_referenceFrame;
  v5.m_pos.m_quad = (__m128)_sphere->m_sphere;
  sphere.m_sphere = _sphere->m_sphere;
  sphere.m_velocity = (hkVector4f)v2.m_quad;
  if ( m_referenceFrame )
  {
    hkaiReferenceFrame::transformWorldPosVelToLocalVel(
      m_referenceFrame,
      &sphere.m_sphere.m_pos,
      &sphere.m_velocity,
      (hkVector4f *)&result);
    v6 = this->m_referenceFrame;
    v7 = _mm_sub_ps(sphere.m_sphere.m_pos.m_quad, v6->m_transform.m_translation.m_quad);
    m_quad = v6->m_transform.m_rotation.m_col2.m_quad;
    v9 = _mm_unpacklo_ps(v6->m_transform.m_rotation.m_col0.m_quad, v6->m_transform.m_rotation.m_col1.m_quad);
    v10 = _mm_movelh_ps(v9, m_quad);
    v11 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps(_mm_movehl_ps(v10, v9), m_quad, 212)),
              _mm_mul_ps(_mm_shuffle_ps(v7, v7, 0), v10)),
            _mm_mul_ps(
              _mm_shuffle_ps(v7, v7, 170),
              _mm_shuffle_ps(
                _mm_unpackhi_ps(v6->m_transform.m_rotation.m_col0.m_quad, v6->m_transform.m_rotation.m_col1.m_quad),
                m_quad,
                228)));
    v2.m_quad = result.m_real;
    v5.m_pos.m_quad = _mm_shuffle_ps(v11, _mm_unpackhi_ps(v11, sphere.m_sphere.m_pos.m_quad), 196);
  }
  v12.m_quad = (__m128)this->m_up;
  m_size = this->m_spheres.m_size;
  v14 = _mm_mul_ps(v12.m_quad, v5.m_pos.m_quad);
  v15 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)), _mm_shuffle_ps(v14, v14, 170));
  v16 = _mm_mul_ps(v12.m_quad, v2.m_quad);
  v17 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps((__m128)0i64, v15), v12.m_quad), v5.m_pos.m_quad);
  v18.m_pos.m_quad = _mm_shuffle_ps(v17, _mm_unpackhi_ps(v17, v5.m_pos.m_quad), 196);
  sphere.m_sphere = (hkSphere)v18.m_pos.m_quad;
  sphere.m_velocity.m_quad = _mm_add_ps(
                               v2.m_quad,
                               _mm_mul_ps(
                                 _mm_sub_ps(
                                   (__m128)0i64,
                                   _mm_add_ps(
                                     _mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)),
                                     _mm_shuffle_ps(v16, v16, 170))),
                                 v12.m_quad));
  if ( (_DWORD)m_size == 32 )
  {
    v19 = 0i64;
    hkaiObstacleCollector::getSphereDistance(this, &result, &sphere);
    m_data = this->m_spheres.m_data;
    v21 = result.m_real.m128_f32[0];
    v22 = 32i64;
    do
    {
      hkaiObstacleCollector::getSphereDistance(this, &result, m_data);
      if ( result.m_real.m128_f32[0] > v21 )
      {
        v21 = result.m_real.m128_f32[0];
        v19 = m_data;
      }
      ++m_data;
      --v22;
    }
    while ( v22 );
    if ( v19 )
    {
      v19->m_sphere = (hkSphere)v18.m_pos.m_quad;
      v19->m_velocity = sphere.m_velocity;
    }
  }
  else
  {
    v23 = &this->m_spheres.m_data[m_size];
    v23->m_sphere = (hkSphere)v18.m_pos.m_quad;
    v23->m_velocity = sphere.m_velocity;
    ++this->m_spheres.m_size;
  }
}hkSphere)v18.m_pos.m_quad;
    v23->m_velocity = sphere.m_velocity;
    ++this->m_sphe

// File Line: 136
// RVA: 0xBDD510
hkSimdFloat32 *__fastcall hkaiObstacleCollector::getSphereDistance(
        hkaiObstacleCollector *this,
        hkSimdFloat32 *result,
        hkaiAvoidanceSolver::SphereObstacle *sphere)
{
  hkSimdFloat32 *v3; // rax
  __m128 v4; // xmm1
  __m128 v5; // xmm1
  __m128 v6; // xmm4
  __m128 v7; // xmm1

  v3 = result;
  v4 = _mm_sub_ps(this->m_position.m_quad, sphere->m_sphere.m_pos.m_quad);
  v5 = _mm_mul_ps(v4, v4);
  v6 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v5, v5, 85), _mm_shuffle_ps(v5, v5, 0)), _mm_shuffle_ps(v5, v5, 170));
  v7 = _mm_rsqrt_ps(v6);
  result->m_real = _mm_sub_ps(
                     _mm_andnot_ps(
                       _mm_cmple_ps(v6, (__m128)0i64),
                       _mm_mul_ps(
                         _mm_mul_ps(
                           _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v6, v7), v7)),
                           _mm_mul_ps(*(__m128 *)_xmm, v7)),
                         v6)),
                     _mm_shuffle_ps(sphere->m_sphere.m_pos.m_quad, sphere->m_sphere.m_pos.m_quad, 255));
  return v3;
}

// File Line: 141
// RVA: 0xBDD640
hkSimdFloat32 *__fastcall hkaiObstacleCollector::getBoundaryDistance(
        hkaiObstacleCollector *this,
        hkSimdFloat32 *result,
        hkaiAvoidanceSolver::BoundaryObstacle *boundary)
{
  hkaiObstacleCollector::getBoundaryDistance(this, result, &boundary->m_start, &boundary->m_end);
  return result;
}

// File Line: 146
// RVA: 0xBDD580
hkSimdFloat32 *__fastcall hkaiObstacleCollector::getBoundaryDistance(
        hkaiObstacleCollector *this,
        hkSimdFloat32 *result,
        hkVector4f *A,
        hkVector4f *B)
{
  hkSimdFloat32 *v4; // rax
  __m128 v5; // xmm6
  __m128 v6; // xmm5
  __m128 v7; // xmm1
  __m128 v8; // xmm4
  __m128 v9; // xmm1
  __m128 v10; // xmm0
  __m128 v11; // xmm3
  __m128 v12; // xmm2
  __m128 v13; // xmm6
  __m128 v14; // xmm6

  v4 = result;
  v5 = _mm_sub_ps(A->m_quad, this->m_position.m_quad);
  v6 = _mm_sub_ps(A->m_quad, B->m_quad);
  v7 = _mm_mul_ps(v6, v6);
  v8 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps(v7, v7, 0)), _mm_shuffle_ps(v7, v7, 170));
  v9 = _mm_mul_ps(v5, v6);
  v10 = _mm_rcp_ps(v8);
  v11 = _mm_mul_ps(
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v8, v10)), v10),
          _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)), _mm_shuffle_ps(v9, v9, 170)));
  v12 = _mm_cmplt_ps(v11, query.m_quad);
  v13 = _mm_sub_ps(
          v5,
          _mm_mul_ps(_mm_max_ps((__m128)0i64, _mm_or_ps(_mm_andnot_ps(v12, query.m_quad), _mm_and_ps(v12, v11))), v6));
  v14 = _mm_mul_ps(v13, v13);
  result->m_real = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)),
                     _mm_shuffle_ps(v14, v14, 170));
  return v4;
}

