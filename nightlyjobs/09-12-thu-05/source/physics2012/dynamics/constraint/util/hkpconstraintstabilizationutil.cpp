// File Line: 24
// RVA: 0xD65220
void __fastcall collectRigidBodies(hkpSimulationIsland *island, hkArray<hkpRigidBody *,hkContainerHeapAllocator> *rigidBodiesOut)
{
  hkArray<hkpRigidBody *,hkContainerHeapAllocator> *v2; // rbx
  hkpSimulationIsland *v3; // rbp
  int v4; // eax
  __int64 i; // rsi
  __int64 v6; // r9
  int v7; // edx
  hkpRigidBody *v8; // rdi
  __int64 v9; // rcx
  hkpRigidBody **v10; // rax

  v2 = rigidBodiesOut;
  v3 = island;
  v4 = island->m_entities.m_size - 1;
  for ( i = v4; i >= 0; --i )
  {
    v6 = v2->m_size;
    v7 = 0;
    v8 = (hkpRigidBody *)v3->m_entities.m_data[i];
    v9 = 0i64;
    if ( (signed int)v6 <= 0 )
      goto LABEL_8;
    v10 = v2->m_data;
    while ( *v10 != v8 )
    {
      ++v9;
      ++v7;
      ++v10;
      if ( v9 >= v6 )
        goto LABEL_8;
    }
    if ( v7 < 0 )
    {
LABEL_8:
      if ( (_DWORD)v6 == (v2->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v2, 8);
      v2->m_data[v2->m_size++] = v8;
    }
  }
}

// File Line: 46
// RVA: 0xD652E0
void __fastcall collectRigidBodies_0(hkpWorld *physicsWorld, hkArray<hkpRigidBody *,hkContainerHeapAllocator> *rigidBodiesOut)
{
  hkArray<hkpRigidBody *,hkContainerHeapAllocator> *v2; // rsi
  hkpWorld *v3; // rdi
  int v4; // eax
  __int64 i; // rbx
  int v6; // eax
  __int64 j; // rbx

  v2 = rigidBodiesOut;
  v3 = physicsWorld;
  v4 = physicsWorld->m_activeSimulationIslands.m_size - 1;
  for ( i = v4; i >= 0; collectRigidBodies(v3->m_activeSimulationIslands.m_data[i--], v2) )
    ;
  v6 = v3->m_inactiveSimulationIslands.m_size - 1;
  for ( j = v6; j >= 0; collectRigidBodies(v3->m_inactiveSimulationIslands.m_data[j--], v2) )
    ;
  collectRigidBodies(v3->m_fixedIsland, v2);
}

// File Line: 71
// RVA: 0xD65360
void __fastcall collectConstraints(hkArray<hkpRigidBody *,hkContainerHeapAllocator> *rigidBodies, hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *constraintsOut)
{
  hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *v2; // rbx
  hkArray<hkpRigidBody *,hkContainerHeapAllocator> *v3; // r12
  int v4; // eax
  __int64 i; // r14
  hkpEntity *v6; // r15
  int v7; // esi
  int v8; // ebp
  hkpConstraintInstance *v9; // rdi
  __int64 v10; // r9
  int v11; // edx
  __int64 v12; // rcx
  hkpConstraintInstance **v13; // rax

  v2 = constraintsOut;
  v3 = rigidBodies;
  v4 = rigidBodies->m_size - 1;
  for ( i = v4; i >= 0; --i )
  {
    v6 = (hkpEntity *)&v3->m_data[i]->vfptr;
    v7 = 0;
    v8 = hkpEntity::getNumConstraints((hkpEntity *)&v3->m_data[i]->vfptr);
    if ( v8 > 0 )
    {
      do
      {
        v9 = hkpEntity::getConstraint(v6, v7);
        if ( ((unsigned int (*)(void))v9->m_data->vfptr[1].__first_virtual_table_function__)() != 11 )
        {
          v10 = v2->m_size;
          v11 = 0;
          v12 = 0i64;
          if ( (signed int)v10 <= 0 )
            goto LABEL_10;
          v13 = v2->m_data;
          while ( *v13 != v9 )
          {
            ++v12;
            ++v11;
            ++v13;
            if ( v12 >= v10 )
              goto LABEL_10;
          }
          if ( v11 < 0 )
          {
LABEL_10:
            if ( (_DWORD)v10 == (v2->m_capacityAndFlags & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v2, 8);
            v2->m_data[v2->m_size++] = v9;
          }
        }
        ++v7;
      }
      while ( v7 < v8 );
    }
  }
}

// File Line: 112
// RVA: 0xD65470
void __fastcall getRigidBodyInfo(hkpRigidBody *body, hkVector4f *invInertia, hkVector4f *vCom)
{
  hkVector4f *v3; // rsi
  hkVector4f *v4; // rbx
  hkpRigidBody *v5; // rdi
  __m128 v6; // xmm0
  __m128 v7; // xmm2
  __m128 v8; // xmm0
  __m128 v9; // xmm3
  __m128 v10; // [rsp+20h] [rbp-38h]
  __m128 v11; // [rsp+30h] [rbp-28h]
  __m128 v12; // [rsp+40h] [rbp-18h]

  v3 = vCom;
  v4 = invInertia;
  v5 = body;
  if ( body )
  {
    ((void (__fastcall *)(hkpMaxSizeMotion *, __m128 *))body->m_motion.vfptr[5].__first_virtual_table_function__)(
      &body->m_motion,
      &v10);
    v6 = v10;
    *v4 = (hkVector4f)v10;
    v7 = _mm_or_ps(_mm_andnot_ps((__m128)xmmword_141A9A440, v6), _mm_and_ps(v11, (__m128)xmmword_141A9A440));
    v8 = v12;
    *v4 = (hkVector4f)v7;
    v9 = _mm_or_ps(_mm_andnot_ps((__m128)xmmword_141A9A460, v7), _mm_and_ps(v8, (__m128)xmmword_141A9A460));
    *v4 = (hkVector4f)v9;
    v4->m_quad = _mm_shuffle_ps(
                   v9,
                   _mm_unpackhi_ps(
                     v9,
                     _mm_shuffle_ps(
                       v5->m_motion.m_inertiaAndMassInv.m_quad,
                       v5->m_motion.m_inertiaAndMassInv.m_quad,
                       255)),
                   196);
    *v3 = v5->m_motion.m_motionState.m_sweptTransform.m_centerOfMassLocal;
  }
  else
  {
    *invInertia = 0i64;
    *vCom = 0i64;
  }
}

// File Line: 135
// RVA: 0xD64620
void __fastcall hkpConstraintStabilizationUtil::computeBallSocketInertiaStabilizationFactors(hkpConstraintInstance *constraint, hkSimdFloat32 *stabilizationAmount, hkSimdFloat32 *inertiaScaleOutA, hkSimdFloat32 *inertiaScaleOutB)
{
  hkpConstraintData *v4; // rdi
  hkpConstraintInstance *v5; // rbx
  hkSimdFloat32 *v6; // rbp
  hkSimdFloat32 *v7; // rsi
  hkSimdFloat32 *v8; // r14
  __m128 v9; // xmm11
  __m128 v10; // xmm12
  __m128 v11; // xmm10
  __m128 v12; // xmm9
  __m128 *v13; // rbx
  hkVector4f *v14; // rax
  __m128 v15; // xmm1
  __m128 v16; // xmm1
  __m128 v17; // xmm6
  __m128 v18; // xmm3
  __m128 v19; // xmm6
  __m128 v20; // xmm2
  __m128 v21; // xmm8
  __m128 v22; // xmm2
  __m128 v23; // xmm8
  __m128 v24; // xmm1
  __m128 v25; // xmm4
  __m128 v26; // xmm5
  __m128 v27; // xmm0
  __m128 v28; // xmm1
  __m128 v29; // xmm6
  __m128 v30; // xmm2
  __m128 v31; // xmm13
  __m128 v32; // xmm1
  hkVector4f invInertia; // [rsp+20h] [rbp-D8h]
  hkVector4f v34; // [rsp+30h] [rbp-C8h]
  hkVector4f vCom; // [rsp+40h] [rbp-B8h]
  hkVector4f v36; // [rsp+50h] [rbp-A8h]

  v4 = constraint->m_data;
  v5 = constraint;
  v6 = inertiaScaleOutA;
  v7 = stabilizationAmount;
  v8 = inertiaScaleOutB;
  getRigidBodyInfo((hkpRigidBody *)constraint->m_entities[0], &invInertia, &vCom);
  getRigidBodyInfo((hkpRigidBody *)v5->m_entities[1], &v34, &v36);
  v9 = invInertia.m_quad;
  v10 = v34.m_quad;
  v11 = _mm_max_ps(
          _mm_shuffle_ps(invInertia.m_quad, invInertia.m_quad, 170),
          _mm_max_ps(
            _mm_shuffle_ps(invInertia.m_quad, invInertia.m_quad, 85),
            _mm_shuffle_ps(invInertia.m_quad, invInertia.m_quad, 0)));
  v12 = _mm_max_ps(
          _mm_shuffle_ps(v34.m_quad, v34.m_quad, 170),
          _mm_max_ps(_mm_shuffle_ps(v34.m_quad, v34.m_quad, 85), _mm_shuffle_ps(v34.m_quad, v34.m_quad, 0)));
  v13 = (__m128 *)hkpConstraintDataUtils::getPivotA(v4);
  v14 = hkpConstraintDataUtils::getPivotB(v4);
  v15 = _mm_sub_ps(*v13, vCom.m_quad);
  v16 = _mm_mul_ps(v15, v15);
  v17 = _mm_sub_ps(v14->m_quad, v36.m_quad);
  v18 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)), _mm_shuffle_ps(v16, v16, 170));
  v19 = _mm_mul_ps(v17, v17);
  v20 = _mm_rsqrt_ps(v18);
  v21 = _mm_mul_ps(
          _mm_andnot_ps(
            _mm_cmpleps(v18, (__m128)0i64),
            _mm_mul_ps(
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v20, v18), v20)),
                _mm_mul_ps(*(__m128 *)_xmm, v20)),
              v18)),
          v11);
  v22 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)), _mm_shuffle_ps(v19, v19, 170));
  v23 = _mm_mul_ps(v21, v7->m_real);
  v24 = _mm_rsqrt_ps(v22);
  v25 = _mm_cmpltps(*(__m128 *)&epsilon, v23);
  v26 = _mm_mul_ps(*(__m128 *)_xmm, v24);
  v27 = _mm_mul_ps(_mm_mul_ps(v24, v22), v24);
  v28 = _mm_rcp_ps(v23);
  v29 = _mm_mul_ps(
          _mm_mul_ps(
            _mm_andnot_ps(
              _mm_cmpleps(v22, (__m128)0i64),
              _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, v27), v26), v22)),
            v12),
          v7->m_real);
  v30 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v28, v23)), v28), _mm_shuffle_ps(v9, v9, 255));
  v31 = _mm_cmpltps(*(__m128 *)&epsilon, v29);
  v32 = _mm_rcp_ps(v29);
  v6->m_real = _mm_min_ps(_mm_or_ps(_mm_and_ps(v25, v30), _mm_andnot_ps(v25, query.m_quad)), query.m_quad);
  v8->m_real = _mm_min_ps(
                 _mm_or_ps(
                   _mm_and_ps(
                     v31,
                     _mm_mul_ps(
                       _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v32, v29)), v32),
                       _mm_shuffle_ps(v10, v10, 255))),
                   _mm_andnot_ps(v31, query.m_quad)),
                 query.m_quad);
}

// File Line: 214
// RVA: 0xD649E0
signed __int64 __fastcall hkpConstraintStabilizationUtil::stabilizeRigidBodyInertia(hkpRigidBody *rigidBody, hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *constraints, const float stabilizationAmount, const float solverStabilizationAmount)
{
  hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *v4; // rax
  hkpRigidBody *v5; // r13
  __int64 v6; // r12
  __int64 v7; // r14
  __m128 i; // xmm6
  __m128 v9; // xmm7
  hkpConstraintInstance *v10; // r15
  hkpConstraintData *v11; // rcx
  float *v12; // rdi
  unsigned __int64 v13; // rsi
  float *v14; // rbx
  bool v15; // zf
  hkSimdFloat32 *v16; // rax
  __m128 v17; // xmm4
  __m128 v18; // xmm2
  __m128 v19; // xmm1
  __m128 v20; // xmm1
  hkSimdFloat32 stabilizationAmounta; // [rsp+20h] [rbp-79h]
  hkSimdFloat32 inertiaScaleOutA; // [rsp+30h] [rbp-69h]
  hkSimdFloat32 inertiaScaleOutB; // [rsp+40h] [rbp-59h]
  hkMatrix3f inertiaInv; // [rsp+50h] [rbp-49h]
  float vars0; // [rsp+100h] [rbp+67h]
  hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *retaddr; // [rsp+108h] [rbp+6Fh]
  unsigned int v28; // [rsp+110h] [rbp+77h]

  v4 = constraints;
  v5 = rigidBody;
  if ( !rigidBody || rigidBody->m_motion.m_type.m_storage == 5 )
    return 0i64;
  v6 = constraints->m_size;
  v7 = 0i64;
  stabilizationAmounta.m_real = _mm_shuffle_ps((__m128)v28, (__m128)v28, 0);
  for ( i = query.m_quad; v7 < v6; i = _mm_min_ps(i, v9) )
  {
    v9 = query.m_quad;
    v10 = v4->m_data[v7];
    v11 = v10->m_data;
    inertiaInv.m_col1.m_quad.m128_i32[3] = 0;
    v11->vfptr[2].__vecDelDtor((hkBaseObject *)&v11->vfptr, (unsigned int)&inertiaInv);
    v12 = (float *)inertiaInv.m_col1.m_quad.m128_u64[0];
    v13 = inertiaInv.m_col1.m_quad.m128_u64[0] + inertiaInv.m_col1.m_quad.m128_u32[2];
    if ( inertiaInv.m_col1.m_quad.m128_u64[0] < v13 )
    {
      while ( 2 )
      {
        switch ( *(unsigned __int16 *)v12 )
        {
          case 0u:
            v12 = (float *)(((unsigned __int64)v12 + 15) & 0xFFFFFFFFFFFFFFF0ui64);
            goto LABEL_22;
          case 1u:
          case 0xFu:
          case 0x10u:
            v12 += 8;
            goto LABEL_22;
          case 2u:
            v12 += 36;
            goto LABEL_22;
          case 3u:
          case 0x20u:
          case 0x22u:
            v12 += 12;
            goto LABEL_22;
          case 4u:
            v12 += 28;
            goto LABEL_22;
          case 5u:
            v14 = v12;
            v12 += 4;
            hkpConstraintStabilizationUtil::computeBallSocketInertiaStabilizationFactors(
              v10,
              &stabilizationAmounta,
              &inertiaScaleOutA,
              &inertiaScaleOutB);
            v15 = v10->m_entities[0] == (hkpEntity *)v5;
            stabilizationAmounta.m_real.m128_i32[0] = 0;
            vars0 = solverStabilizationAmount;
            v16 = &inertiaScaleOutA;
            stabilizationAmounta.m_real.m128_i32[2] = 1065353216;
            v14[3] = fminf(fmaxf(solverStabilizationAmount, 0.0), 1.0);
            if ( !v15 )
              v16 = &inertiaScaleOutB;
            v9 = v16->m_real;
            goto LABEL_22;
          case 6u:
            v12 += 3;
            goto LABEL_22;
          case 7u:
          case 8u:
          case 9u:
          case 0xAu:
          case 0xCu:
          case 0xDu:
          case 0xEu:
          case 0x11u:
          case 0x15u:
          case 0x16u:
          case 0x17u:
          case 0x18u:
          case 0x1Bu:
            v12 += 4;
            goto LABEL_22;
          case 0xBu:
            v12 += 6;
            goto LABEL_22;
          case 0x12u:
            v12 += 10;
            goto LABEL_22;
          case 0x13u:
            v12 += 24;
            goto LABEL_22;
          case 0x14u:
          case 0x1Eu:
          case 0x21u:
            v12 += 16;
            goto LABEL_22;
          case 0x1Du:
            v12 = 0i64;
            goto LABEL_22;
          case 0x1Fu:
          case 0x23u:
            v12 += 20;
LABEL_22:
            if ( (unsigned __int64)v12 >= v13 )
              break;
            continue;
          default:
            goto LABEL_23;
        }
      }
    }
LABEL_23:
    v4 = retaddr;
    ++v7;
  }
  vars0 = FLOAT_0_99999988;
  if ( i.m128_f32[0] >= COERCE_FLOAT(_mm_shuffle_ps((__m128)LODWORD(FLOAT_0_99999988), (__m128)LODWORD(FLOAT_0_99999988), 0)) )
    return 0i64;
  ((void (__fastcall *)(hkpMaxSizeMotion *, hkMatrix3f *))v5->m_motion.vfptr[5].__first_virtual_table_function__)(
    &v5->m_motion,
    &inertiaInv);
  v17 = _mm_or_ps(
          _mm_andnot_ps(
            (__m128)xmmword_141A9A460,
            _mm_or_ps(
              _mm_andnot_ps((__m128)xmmword_141A9A440, inertiaInv.m_col0.m_quad),
              _mm_and_ps(inertiaInv.m_col1.m_quad, (__m128)xmmword_141A9A440))),
          _mm_and_ps(inertiaInv.m_col2.m_quad, (__m128)xmmword_141A9A460));
  v18 = _mm_max_ps(_mm_shuffle_ps(v17, v17, 170), _mm_max_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)));
  v19 = _mm_cmpltps(*(__m128 *)&epsilon, v18);
  v20 = _mm_min_ps(v17, _mm_or_ps(_mm_and_ps(_mm_mul_ps(i, v18), v19), _mm_andnot_ps(v19, *(__m128 *)&epsilon)));
  inertiaInv.m_col2.m_quad = _mm_mul_ps(v20, stru_141A71280.m_quad);
  inertiaInv.m_col0.m_quad = _mm_mul_ps(v20, transform.m_quad);
  inertiaInv.m_col1.m_quad = _mm_mul_ps(v20, direction.m_quad);
  hkpRigidBody::setInertiaInvLocal(v5, &inertiaInv);
  return 1i64;
}

// File Line: 355
// RVA: 0xD64890
__int64 __fastcall hkpConstraintStabilizationUtil::stabilizeRigidBodyInertia(hkpRigidBody *rigidBody, const float stabilizationAmount, const float solverStabilizationAmount)
{
  hkpRigidBody *v3; // rsi
  int v5; // eax
  __int64 v6; // rbp
  int v7; // er9
  int v8; // edi
  __int64 v9; // rbx
  hkpConstraintInstance *v10; // rax
  unsigned int v11; // ebx
  _QWORD *array; // [rsp+30h] [rbp-38h]
  int i; // [rsp+38h] [rbp-30h]
  int v14; // [rsp+3Ch] [rbp-2Ch]
  hkResult result; // [rsp+70h] [rbp+8h]

  v3 = rigidBody;
  if ( !rigidBody )
    return 0i64;
  array = 0i64;
  i = 0;
  v14 = 2147483648;
  v5 = hkpEntity::getNumConstraints((hkpEntity *)&rigidBody->vfptr);
  v6 = v5;
  if ( v5 > 0 )
  {
    v7 = v5;
    if ( v5 < 0 )
      v7 = 0;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v7, 8);
  }
  v8 = 0;
  v9 = 0i64;
  for ( i = v6; v9 < v6; ++v8 )
  {
    v10 = hkpEntity::getConstraint((hkpEntity *)&v3->vfptr, v8);
    array[++v9 - 1] = v10;
  }
  v11 = hkpConstraintStabilizationUtil::stabilizeRigidBodyInertia(
          v3,
          (hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *)&array,
          stabilizationAmount,
          solverStabilizationAmount);
  i = 0;
  if ( v14 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      8 * v14);
  return v11;
}

// File Line: 379
// RVA: 0xD64D70
__int64 __fastcall hkpConstraintStabilizationUtil::stabilizePhysicsSystemInertias(hkpPhysicsSystem *physicsSystem, const float stabilizationAmount, const float solverStabilizationAmount)
{
  hkpPhysicsSystem *v3; // rsi
  __int64 v5; // rbp
  unsigned int v6; // edi
  __int64 i; // rbx
  int v8; // eax

  v3 = physicsSystem;
  if ( !physicsSystem )
    return 0i64;
  v5 = physicsSystem->m_rigidBodies.m_size;
  v6 = 0;
  for ( i = 0i64; i < v5; v6 += v8 )
    v8 = hkpConstraintStabilizationUtil::stabilizeRigidBodyInertia(
           v3->m_rigidBodies.m_data[i++],
           stabilizationAmount,
           solverStabilizationAmount);
  return v6;
}

// File Line: 403
// RVA: 0xD64E10
__int64 __fastcall hkpConstraintStabilizationUtil::stabilizePhysicsWorldInertias(hkpWorld *physicsWorld, const float stabilizationAmount, const float solverStabilizationAmount)
{
  hkpWorld *v3; // rsi
  unsigned int v5; // edi
  __int64 v6; // rbp
  __int64 i; // rbx
  int v8; // eax
  hkArray<hkpRigidBody *,hkContainerHeapAllocator> rigidBodiesOut; // [rsp+20h] [rbp-38h]

  v3 = physicsWorld;
  if ( !physicsWorld )
    return 0i64;
  v5 = 0;
  hkpWorld::lock(physicsWorld);
  rigidBodiesOut.m_data = 0i64;
  rigidBodiesOut.m_size = 0;
  rigidBodiesOut.m_capacityAndFlags = 2147483648;
  collectRigidBodies_0(v3, &rigidBodiesOut);
  v6 = rigidBodiesOut.m_size;
  for ( i = 0i64; i < v6; v5 += v8 )
    v8 = hkpConstraintStabilizationUtil::stabilizeRigidBodyInertia(
           rigidBodiesOut.m_data[i++],
           stabilizationAmount,
           solverStabilizationAmount);
  hkpWorld::unlock(v3);
  rigidBodiesOut.m_size = 0;
  if ( rigidBodiesOut.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      rigidBodiesOut.m_data,
      8 * rigidBodiesOut.m_capacityAndFlags);
  return v5;
}

// File Line: 434
// RVA: 0xD64F10
void __fastcall hkpConstraintStabilizationUtil::setConstraintsSolvingMethod(hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *constraints, hkpConstraintAtom::SolvingMethod method)
{
  __int64 v2; // rsi
  __int64 v3; // rbx
  hkpConstraintAtom::SolvingMethod v4; // ebp
  hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *i; // rdi
  hkpConstraintData *v6; // rcx

  v2 = constraints->m_size;
  v3 = 0i64;
  v4 = method;
  for ( i = constraints; v3 < v2; ++v3 )
  {
    v6 = i->m_data[v3]->m_data;
    v6->vfptr[7].__vecDelDtor((hkBaseObject *)&v6->vfptr, v4);
  }
}

// File Line: 448
// RVA: 0xD64F80
void __fastcall hkpConstraintStabilizationUtil::setConstraintsSolvingMethod(hkpRigidBody *rigidBody, hkpConstraintAtom::SolvingMethod method)
{
  hkpConstraintAtom::SolvingMethod v2; // er15
  hkpRigidBody *v3; // rbp
  int v4; // eax
  __int64 v5; // rbx
  int v6; // er9
  int v7; // esi
  __int64 v8; // rdi
  __int64 v9; // r14
  hkpConstraintInstance **v10; // rbx
  hkpConstraintInstance *v11; // rax
  char *array; // [rsp+30h] [rbp-28h]
  int v13; // [rsp+38h] [rbp-20h]
  int v14; // [rsp+3Ch] [rbp-1Ch]
  hkResult result; // [rsp+60h] [rbp+8h]

  if ( rigidBody )
  {
    v2 = method;
    v3 = rigidBody;
    array = 0i64;
    v13 = 0;
    v14 = 2147483648;
    v4 = hkpEntity::getNumConstraints((hkpEntity *)&rigidBody->vfptr);
    v5 = v4;
    if ( v4 > 0 )
    {
      v6 = v5;
      if ( (signed int)v5 < 0 )
        v6 = 0;
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v6, 8);
    }
    v7 = 0;
    v8 = 0i64;
    v13 = v5;
    v9 = v5;
    if ( (signed int)v5 > 0 )
    {
      do
      {
        v10 = (hkpConstraintInstance **)&array[8 * v8];
        v11 = hkpEntity::getConstraint((hkpEntity *)&v3->vfptr, v7);
        ++v8;
        ++v7;
        *v10 = v11;
      }
      while ( v8 < v9 );
    }
    hkpConstraintStabilizationUtil::setConstraintsSolvingMethod(
      (hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *)&array,
      v2);
    v13 = 0;
    if ( v14 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        array,
        8 * v14);
  }
}

// File Line: 471
// RVA: 0xD650A0
void __fastcall hkpConstraintStabilizationUtil::setConstraintsSolvingMethod(hkpPhysicsSystem *physicsSystem, hkpConstraintAtom::SolvingMethod method)
{
  hkpPhysicsSystem *v2; // rdi
  hkpConstraintAtom::SolvingMethod v3; // esi
  __int64 v4; // rbp
  __int64 i; // rbx

  if ( physicsSystem )
  {
    v2 = physicsSystem;
    v3 = method;
    hkpConstraintStabilizationUtil::setConstraintsSolvingMethod(&physicsSystem->m_constraints, method);
    v4 = v2->m_rigidBodies.m_size;
    for ( i = 0i64; i < v4; ++i )
      hkpConstraintStabilizationUtil::setConstraintsSolvingMethod(v2->m_rigidBodies.m_data[i], v3);
  }
}

// File Line: 496
// RVA: 0xD65120
void __fastcall hkpConstraintStabilizationUtil::setConstraintsSolvingMethod(hkpWorld *physicsWorld, hkpConstraintAtom::SolvingMethod method)
{
  hkpConstraintAtom::SolvingMethod v2; // edi
  hkpWorld *v3; // rbx
  hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> constraintsOut; // [rsp+20h] [rbp-28h]
  hkArray<hkpRigidBody *,hkContainerHeapAllocator> rigidBodiesOut; // [rsp+30h] [rbp-18h]

  if ( physicsWorld )
  {
    v2 = method;
    v3 = physicsWorld;
    hkpWorld::lock(physicsWorld);
    rigidBodiesOut.m_data = 0i64;
    rigidBodiesOut.m_size = 0;
    rigidBodiesOut.m_capacityAndFlags = 2147483648;
    collectRigidBodies_0(v3, &rigidBodiesOut);
    constraintsOut.m_data = 0i64;
    constraintsOut.m_size = 0;
    constraintsOut.m_capacityAndFlags = 2147483648;
    collectConstraints(&rigidBodiesOut, &constraintsOut);
    hkpConstraintStabilizationUtil::setConstraintsSolvingMethod(&constraintsOut, v2);
    hkpWorld::unlock(v3);
    constraintsOut.m_size = 0;
    if ( constraintsOut.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        constraintsOut.m_data,
        8 * constraintsOut.m_capacityAndFlags);
    constraintsOut.m_data = 0i64;
    rigidBodiesOut.m_size = 0;
    constraintsOut.m_capacityAndFlags = 2147483648;
    if ( rigidBodiesOut.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        rigidBodiesOut.m_data,
        8 * rigidBodiesOut.m_capacityAndFlags);
  }
}

