// File Line: 21
// RVA: 0xBDCEC0
void __fastcall hkaiObstacleCollector::hkaiObstacleCollector(hkaiObstacleCollector *this, int numAgents, hkVector4f *position, hkVector4f *up)
{
  int v4; // edi
  hkaiObstacleCollector *v5; // rbx
  unsigned int v6; // ebp
  hkVector4f *v7; // r15
  hkVector4f *v8; // r12
  hkaiAvoidanceSolver::SphereObstacle *v9; // rax
  hkaiAvoidanceSolver::SphereObstacle *v10; // rcx
  unsigned int v11; // ecx
  int v12; // eax
  hkaiAvoidanceSolver::BoundaryObstacle *v13; // rax
  hkaiAvoidanceSolver::BoundaryObstacle *v14; // rcx
  unsigned int v15; // ecx
  __int32 v16; // edx
  int v17; // eax
  hkaiAvoidanceSolver::ObstacleAgent *v18; // r8
  __m128 v19; // xmm0
  int v20; // er9
  int v21; // er9
  int v22; // eax
  int v23; // eax
  int v24; // er9
  hkResult result; // [rsp+68h] [rbp+10h]

  v4 = numAgents;
  v5 = this;
  this->m_spheres.m_data = 0i64;
  this->m_spheres.m_size = 0;
  v6 = 2147483648;
  this->m_spheres.m_capacityAndFlags = 2147483648;
  v7 = up;
  v8 = position;
  result.m_enum = 1024;
  v9 = (hkaiAvoidanceSolver::SphereObstacle *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                                (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                                                (int *)&result);
  v5->m_spheres.m_size = 32;
  v10 = v9;
  LODWORD(v9) = result;
  result.m_enum = 1024;
  v5->m_spheres.m_data = v10;
  v11 = 2147483648;
  v12 = (signed int)v9 / 32;
  if ( v12 )
    v11 = v12;
  v5->m_spheres.m_capacityAndFlags = v11;
  v5->m_boundaries.m_data = 0i64;
  v5->m_boundaries.m_size = 0;
  v5->m_boundaries.m_capacityAndFlags = 2147483648;
  v13 = (hkaiAvoidanceSolver::BoundaryObstacle *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                                   (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                                                   (int *)&result);
  v5->m_boundaries.m_size = 32;
  v14 = v13;
  LODWORD(v13) = result;
  v5->m_boundaries.m_data = v14;
  v15 = 2147483648;
  v16 = v4;
  v17 = (signed int)v13 / 32;
  if ( v17 )
    v15 = v17;
  v5->m_boundaries.m_capacityAndFlags = v15;
  v5->m_neighborAgents.m_data = 0i64;
  v5->m_neighborAgents.m_size = 0;
  v5->m_neighborAgents.m_capacityAndFlags = 2147483648;
  if ( v4 )
  {
    result.m_enum = 80 * v4;
    v18 = (hkaiAvoidanceSolver::ObstacleAgent *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                                  (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                                                  (int *)&result);
    v16 = result.m_enum / 80;
  }
  else
  {
    v18 = 0i64;
  }
  v5->m_neighborAgents.m_data = v18;
  v5->m_neighborAgents.m_size = v4;
  if ( v16 )
    v6 = v16;
  v5->m_neighborAgents.m_capacityAndFlags = v6;
  v5->m_up = (hkVector4f)v7->m_quad;
  v19 = v8->m_quad;
  v5->m_referenceFrame = 0i64;
  v5->m_position.m_quad = v19;
  if ( (v5->m_spheres.m_capacityAndFlags & 0x3FFFFFFF) < 0 )
  {
    v20 = 0;
    if ( 2 * (v5->m_spheres.m_capacityAndFlags & 0x3FFFFFFF) > 0 )
      v20 = 2 * (v5->m_spheres.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v5, v20, 32);
  }
  v5->m_spheres.m_size = 0;
  if ( (v5->m_boundaries.m_capacityAndFlags & 0x3FFFFFFF) < 0 )
  {
    v21 = 0;
    if ( 2 * (v5->m_boundaries.m_capacityAndFlags & 0x3FFFFFFF) > 0 )
      v21 = 2 * (v5->m_boundaries.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
      &v5->m_boundaries,
      v21,
      32);
  }
  v5->m_boundaries.m_size = 0;
  v22 = v5->m_neighborAgents.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v22 < v4 )
  {
    v23 = 2 * v22;
    v24 = v4;
    if ( v4 < v23 )
      v24 = v23;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
      &v5->m_neighborAgents,
      v24,
      80);
  }
  v5->m_neighborAgents.m_size = v4;
}llocator::s_alloc.vfptr,
      &v5->m_neighb

// File Line: 31
// RVA: 0xBDD0D0
void __fastcall hkaiObstacleCollector::addBoundary(hkaiObstacleCollector *this, hkVector4f *_A, hkVector4f *_B)
{
  __m128 v3; // xmm6
  hkaiObstacleCollector *v4; // rbx
  __m128 v5; // xmm9
  hkaiReferenceFrame *v6; // rax
  __m128 v7; // xmm3
  __m128 v8; // xmm6
  __m128 v9; // xmm9
  __m128 v10; // xmm5
  __m128 v11; // xmm1
  __m128 v12; // xmm2
  __m128 v13; // xmm6
  __m128 v14; // xmm1
  __m128 v15; // xmm4
  __m128 v16; // xmm2
  hkVector4f v17; // xmm3
  __m128 v18; // xmm2
  __m128 v19; // xmm1
  __m128 v20; // xmm2
  __m128 v21; // xmm8
  __m128 v22; // xmm7
  __m128 *v23; // rbp
  int v24; // esi
  float v25; // xmm6_4
  signed __int64 v26; // rdi
  hkaiAvoidanceSolver::BoundaryObstacle *v27; // rax
  hkVector4f B; // [rsp+20h] [rbp-78h]
  hkVector4f A; // [rsp+30h] [rbp-68h]
  hkSimdFloat32 result; // [rsp+40h] [rbp-58h]

  v3 = _A->m_quad;
  v4 = this;
  v5 = _B->m_quad;
  B.m_quad = _B->m_quad;
  A.m_quad = v3;
  v6 = this->m_referenceFrame;
  if ( v6 )
  {
    v7 = v6->m_transform.m_rotation.m_col2.m_quad;
    v8 = _mm_sub_ps(v3, v6->m_transform.m_translation.m_quad);
    v9 = _mm_sub_ps(v5, v6->m_transform.m_translation.m_quad);
    v10 = v8;
    v11 = _mm_unpacklo_ps(v6->m_transform.m_rotation.m_col0.m_quad, v6->m_transform.m_rotation.m_col1.m_quad);
    v12 = _mm_movelh_ps(v11, v7);
    v13 = _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(_mm_movehl_ps(v12, v11), v7, 212)),
            _mm_mul_ps(_mm_shuffle_ps(v10, v10, 0), v12));
    v14 = v11;
    v15 = _mm_unpackhi_ps(v6->m_transform.m_rotation.m_col0.m_quad, v6->m_transform.m_rotation.m_col1.m_quad);
    v3 = _mm_add_ps(v13, _mm_mul_ps(_mm_shuffle_ps(v10, v10, 170), _mm_shuffle_ps(v15, v7, 228)));
    v16 = _mm_movelh_ps(v14, v7);
    A.m_quad = v3;
    v5 = _mm_add_ps(
           _mm_add_ps(
             _mm_mul_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(_mm_movehl_ps(v16, v14), v7, 212)),
             _mm_mul_ps(_mm_shuffle_ps(v9, v9, 0), v16)),
           _mm_mul_ps(_mm_shuffle_ps(v9, v9, 170), _mm_shuffle_ps(v15, v7, 228)));
    B.m_quad = v5;
  }
  v17.m_quad = (__m128)this->m_up;
  v18 = _mm_mul_ps(this->m_up.m_quad, v3);
  v19 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)), _mm_shuffle_ps(v18, v18, 170));
  v20 = _mm_mul_ps(this->m_up.m_quad, v5);
  v21 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps((__m128)0i64, v19), v17.m_quad), v3);
  v22 = _mm_add_ps(
          _mm_mul_ps(
            _mm_sub_ps(
              (__m128)0i64,
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)),
                _mm_shuffle_ps(v20, v20, 170))),
            v17.m_quad),
          v5);
  if ( this->m_boundaries.m_size == 32 )
  {
    v23 = 0i64;
    hkaiObstacleCollector::getBoundaryDistance(this, &result, &A, &B);
    v24 = 0;
    if ( v4->m_boundaries.m_size > 0 )
    {
      v25 = result.m_real.m128_f32[0];
      do
      {
        v26 = v24;
        hkaiObstacleCollector::getBoundaryDistance(v4, &result, &v4->m_boundaries.m_data[v26]);
        if ( result.m_real.m128_f32[0] > v25 )
        {
          v25 = result.m_real.m128_f32[0];
          v23 = &v4->m_boundaries.m_data[v26].m_start.m_quad;
        }
        ++v24;
      }
      while ( v24 < v4->m_boundaries.m_size );
      if ( v23 )
      {
        *v23 = v21;
        v23[1] = v22;
      }
    }
  }
  else
  {
    v27 = &this->m_boundaries.m_data[this->m_boundaries.m_size];
    v27->m_start.m_quad = v21;
    v27->m_end.m_quad = v22;
    ++this->m_boundaries.m_size;
  }
}

// File Line: 83
// RVA: 0xBDD300
void __fastcall hkaiObstacleCollector::addSphereObstacle(hkaiObstacleCollector *this, hkaiAvoidanceSolver::SphereObstacle *_sphere)
{
  __m128 v2; // xmm5
  hkaiObstacleCollector *v3; // rdi
  hkaiReferenceFrame *v4; // rcx
  hkSphere v5; // xmm8
  hkaiReferenceFrame *v6; // rax
  __m128 v7; // xmm5
  __m128 v8; // xmm3
  __m128 v9; // xmm1
  __m128 v10; // xmm2
  __m128 v11; // xmm8
  __m128 v12; // xmm4
  __int64 v13; // rax
  __m128 v14; // xmm2
  __m128 v15; // xmm1
  __m128 v16; // xmm2
  __m128 v17; // xmm7
  hkSphere v18; // xmm7
  hkaiAvoidanceSolver::SphereObstacle *v19; // rbp
  hkaiAvoidanceSolver::SphereObstacle *v20; // rbx
  float v21; // xmm6_4
  signed __int64 v22; // rsi
  signed __int64 v23; // rax
  hkSimdFloat32 result; // [rsp+20h] [rbp-68h]
  hkaiAvoidanceSolver::SphereObstacle sphere; // [rsp+30h] [rbp-58h]

  v2 = _sphere->m_velocity.m_quad;
  v3 = this;
  v4 = this->m_referenceFrame;
  v5.m_pos.m_quad = (__m128)_sphere->m_sphere;
  sphere.m_sphere = _sphere->m_sphere;
  sphere.m_velocity.m_quad = v2;
  if ( v4 )
  {
    hkaiReferenceFrame::transformWorldPosVelToLocalVel(
      v4,
      &sphere.m_sphere.m_pos,
      &sphere.m_velocity,
      (hkVector4f *)&result);
    v6 = v3->m_referenceFrame;
    v7 = _mm_sub_ps(sphere.m_sphere.m_pos.m_quad, v6->m_transform.m_translation.m_quad);
    v8 = v6->m_transform.m_rotation.m_col2.m_quad;
    v9 = _mm_unpacklo_ps(v6->m_transform.m_rotation.m_col0.m_quad, v6->m_transform.m_rotation.m_col1.m_quad);
    v10 = _mm_movelh_ps(v9, v8);
    v11 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps(_mm_movehl_ps(v10, v9), v8, 212)),
              _mm_mul_ps(_mm_shuffle_ps(v7, v7, 0), v10)),
            _mm_mul_ps(
              _mm_shuffle_ps(v7, v7, 170),
              _mm_shuffle_ps(
                _mm_unpackhi_ps(v6->m_transform.m_rotation.m_col0.m_quad, v6->m_transform.m_rotation.m_col1.m_quad),
                v8,
                228)));
    v2 = result.m_real;
    v5.m_pos.m_quad = _mm_shuffle_ps(v11, _mm_unpackhi_ps(v11, sphere.m_sphere.m_pos.m_quad), 196);
  }
  v12 = v3->m_up.m_quad;
  v13 = v3->m_spheres.m_size;
  v14 = _mm_mul_ps(v3->m_up.m_quad, v5.m_pos.m_quad);
  v15 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)), _mm_shuffle_ps(v14, v14, 170));
  v16 = _mm_mul_ps(v3->m_up.m_quad, v2);
  v17 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps((__m128)0i64, v15), v12), v5.m_pos.m_quad);
  v18.m_pos.m_quad = _mm_shuffle_ps(v17, _mm_unpackhi_ps(v17, v5.m_pos.m_quad), 196);
  sphere.m_sphere = (hkSphere)v18.m_pos.m_quad;
  sphere.m_velocity.m_quad = _mm_add_ps(
                               v2,
                               _mm_mul_ps(
                                 _mm_sub_ps(
                                   (__m128)0i64,
                                   _mm_add_ps(
                                     _mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)),
                                     _mm_shuffle_ps(v16, v16, 170))),
                                 v12));
  if ( (_DWORD)v13 == 32 )
  {
    v19 = 0i64;
    hkaiObstacleCollector::getSphereDistance(v3, &result, &sphere);
    v20 = v3->m_spheres.m_data;
    v21 = result.m_real.m128_f32[0];
    v22 = 32i64;
    do
    {
      hkaiObstacleCollector::getSphereDistance(v3, &result, v20);
      if ( result.m_real.m128_f32[0] > v21 )
      {
        v21 = result.m_real.m128_f32[0];
        v19 = v20;
      }
      ++v20;
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
    v23 = (signed __int64)&v3->m_spheres.m_data[v13];
    *(hkSphere *)v23 = (hkSphere)v18.m_pos.m_quad;
    *(hkVector4f *)(v23 + 16) = sphere.m_velocity;
    ++v3->m_spheres.m_size;
  }
}

// File Line: 136
// RVA: 0xBDD510
hkSimdFloat32 *__fastcall hkaiObstacleCollector::getSphereDistance(hkaiObstacleCollector *this, hkSimdFloat32 *result, hkaiAvoidanceSolver::SphereObstacle *sphere)
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
                       _mm_cmpleps(v6, (__m128)0i64),
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
hkSimdFloat32 *__fastcall hkaiObstacleCollector::getBoundaryDistance(hkaiObstacleCollector *this, hkSimdFloat32 *result, hkaiAvoidanceSolver::BoundaryObstacle *boundary)
{
  hkSimdFloat32 *v3; // rbx

  v3 = result;
  hkaiObstacleCollector::getBoundaryDistance(this, result, &boundary->m_start, &boundary->m_end);
  return v3;
}

// File Line: 146
// RVA: 0xBDD580
hkSimdFloat32 *__fastcall hkaiObstacleCollector::getBoundaryDistance(hkaiObstacleCollector *this, hkSimdFloat32 *result, hkVector4f *A, hkVector4f *B)
{
  hkSimdFloat32 *v4; // rax
  __m128 v5; // xmm6
  __m128 v6; // xmm5
  __m128 v7; // xmm1
  __m128 v8; // xmm4
  __m128 v9; // xmm1
  __m128 v10; // xmm0
  __m128 v11; // xmm3
  __m128 v12; // xmm1
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
  v12 = _mm_cmpltps(v11, query.m_quad);
  v13 = _mm_sub_ps(
          v5,
          _mm_mul_ps(_mm_max_ps((__m128)0i64, _mm_or_ps(_mm_andnot_ps(v12, query.m_quad), _mm_and_ps(v12, v11))), v6));
  v14 = _mm_mul_ps(v13, v13);
  result->m_real = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)),
                     _mm_shuffle_ps(v14, v14, 170));
  return v4;
}

