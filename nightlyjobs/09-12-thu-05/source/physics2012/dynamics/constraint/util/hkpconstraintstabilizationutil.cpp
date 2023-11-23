// File Line: 24
// RVA: 0xD65220
void __fastcall collectRigidBodies(
        hkpSimulationIsland *island,
        hkArray<hkpRigidBody *,hkContainerHeapAllocator> *rigidBodiesOut)
{
  int v4; // eax
  __int64 i; // rsi
  __int64 m_size; // r9
  int v7; // edx
  hkpRigidBody *v8; // rdi
  __int64 v9; // rcx
  hkpRigidBody **m_data; // rax

  v4 = island->m_entities.m_size - 1;
  for ( i = v4; i >= 0; --i )
  {
    m_size = rigidBodiesOut->m_size;
    v7 = 0;
    v8 = (hkpRigidBody *)island->m_entities.m_data[i];
    v9 = 0i64;
    if ( (int)m_size <= 0 )
      goto LABEL_8;
    m_data = rigidBodiesOut->m_data;
    while ( *m_data != v8 )
    {
      ++v9;
      ++v7;
      ++m_data;
      if ( v9 >= m_size )
        goto LABEL_8;
    }
    if ( v7 < 0 )
    {
LABEL_8:
      if ( (_DWORD)m_size == (rigidBodiesOut->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&rigidBodiesOut->m_data, 8);
      rigidBodiesOut->m_data[rigidBodiesOut->m_size++] = v8;
    }
  }
}

// File Line: 46
// RVA: 0xD652E0
void __fastcall collectRigidBodies_0(
        hkpWorld *physicsWorld,
        hkArray<hkpRigidBody *,hkContainerHeapAllocator> *rigidBodiesOut)
{
  int v4; // eax
  __int64 i; // rbx
  int v6; // eax
  __int64 j; // rbx

  v4 = physicsWorld->m_activeSimulationIslands.m_size - 1;
  for ( i = v4; i >= 0; collectRigidBodies(physicsWorld->m_activeSimulationIslands.m_data[i--], rigidBodiesOut) )
    ;
  v6 = physicsWorld->m_inactiveSimulationIslands.m_size - 1;
  for ( j = v6; j >= 0; collectRigidBodies(physicsWorld->m_inactiveSimulationIslands.m_data[j--], rigidBodiesOut) )
    ;
  collectRigidBodies(physicsWorld->m_fixedIsland, rigidBodiesOut);
}

// File Line: 71
// RVA: 0xD65360
void __fastcall collectConstraints(
        hkArray<hkpRigidBody *,hkContainerHeapAllocator> *rigidBodies,
        hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *constraintsOut)
{
  int v4; // eax
  __int64 i; // r14
  hkpRigidBody *v6; // r15
  int v7; // esi
  int NumConstraints; // ebp
  hkpConstraintInstance *Constraint; // rdi
  __int64 m_size; // r9
  int v11; // edx
  __int64 v12; // rcx
  hkpConstraintInstance **m_data; // rax

  v4 = rigidBodies->m_size - 1;
  for ( i = v4; i >= 0; --i )
  {
    v6 = rigidBodies->m_data[i];
    v7 = 0;
    NumConstraints = hkpEntity::getNumConstraints(v6);
    if ( NumConstraints > 0 )
    {
      do
      {
        Constraint = hkpEntity::getConstraint(v6, v7);
        if ( ((unsigned int (__fastcall *)(hkpConstraintData *))Constraint->m_data->vfptr[1].__first_virtual_table_function__)(Constraint->m_data) != 11 )
        {
          m_size = constraintsOut->m_size;
          v11 = 0;
          v12 = 0i64;
          if ( (int)m_size <= 0 )
            goto LABEL_10;
          m_data = constraintsOut->m_data;
          while ( *m_data != Constraint )
          {
            ++v12;
            ++v11;
            ++m_data;
            if ( v12 >= m_size )
              goto LABEL_10;
          }
          if ( v11 < 0 )
          {
LABEL_10:
            if ( (_DWORD)m_size == (constraintsOut->m_capacityAndFlags & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&constraintsOut->m_data, 8);
            constraintsOut->m_data[constraintsOut->m_size++] = Constraint;
          }
        }
        ++v7;
      }
      while ( v7 < NumConstraints );
    }
  }
}

// File Line: 112
// RVA: 0xD65470
void __fastcall getRigidBodyInfo(hkpRigidBody *body, hkVector4f *invInertia, hkVector4f *vCom)
{
  __m128 v6; // xmm0
  __m128 v7; // xmm2
  __m128 v8; // xmm0
  __m128 v9; // xmm3
  __int128 v10[3]; // [rsp+20h] [rbp-38h] BYREF

  if ( body )
  {
    ((void (__fastcall *)(hkpMaxSizeMotion *, __int128 *))body->m_motion.hkpEntity::vfptr[5].__first_virtual_table_function__)(
      &body->m_motion,
      v10);
    v6 = (__m128)v10[0];
    *invInertia = (hkVector4f)v10[0];
    v7 = _mm_or_ps(_mm_andnot_ps((__m128)xmmword_141A9A440, v6), _mm_and_ps((__m128)v10[1], (__m128)xmmword_141A9A440));
    v8 = (__m128)v10[2];
    *invInertia = (hkVector4f)v7;
    v9 = _mm_or_ps(_mm_andnot_ps((__m128)xmmword_141A9A460, v7), _mm_and_ps(v8, (__m128)xmmword_141A9A460));
    *invInertia = (hkVector4f)v9;
    invInertia->m_quad = _mm_shuffle_ps(
                           v9,
                           _mm_unpackhi_ps(
                             v9,
                             _mm_shuffle_ps(
                               body->m_motion.m_inertiaAndMassInv.m_quad,
                               body->m_motion.m_inertiaAndMassInv.m_quad,
                               255)),
                           196);
    *vCom = body->m_motion.m_motionState.m_sweptTransform.m_centerOfMassLocal;
  }
  else
  {
    *invInertia = 0i64;
    *vCom = 0i64;
  }
}

// File Line: 135
// RVA: 0xD64620
void __fastcall hkpConstraintStabilizationUtil::computeBallSocketInertiaStabilizationFactors(
        hkpConstraintInstance *constraint,
        hkSimdFloat32 *stabilizationAmount,
        hkSimdFloat32 *inertiaScaleOutA,
        hkSimdFloat32 *inertiaScaleOutB)
{
  hkpConstraintData *m_data; // rdi
  __m128 m_quad; // xmm11
  __m128 v10; // xmm12
  __m128 v11; // xmm10
  __m128 v12; // xmm9
  __m128 *PivotA; // rbx
  hkVector4f *PivotB; // rax
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
  hkVector4f invInertia; // [rsp+20h] [rbp-D8h] BYREF
  hkVector4f v34; // [rsp+30h] [rbp-C8h] BYREF
  hkVector4f vCom; // [rsp+40h] [rbp-B8h] BYREF
  hkVector4f v36; // [rsp+50h] [rbp-A8h] BYREF

  m_data = constraint->m_data;
  getRigidBodyInfo((hkpRigidBody *)constraint->m_entities[0], &invInertia, &vCom);
  getRigidBodyInfo((hkpRigidBody *)constraint->m_entities[1], &v34, &v36);
  m_quad = invInertia.m_quad;
  v10 = v34.m_quad;
  v11 = _mm_max_ps(
          _mm_shuffle_ps(invInertia.m_quad, invInertia.m_quad, 170),
          _mm_max_ps(
            _mm_shuffle_ps(invInertia.m_quad, invInertia.m_quad, 85),
            _mm_shuffle_ps(invInertia.m_quad, invInertia.m_quad, 0)));
  v12 = _mm_max_ps(
          _mm_shuffle_ps(v34.m_quad, v34.m_quad, 170),
          _mm_max_ps(_mm_shuffle_ps(v34.m_quad, v34.m_quad, 85), _mm_shuffle_ps(v34.m_quad, v34.m_quad, 0)));
  PivotA = (__m128 *)hkpConstraintDataUtils::getPivotA(m_data);
  PivotB = hkpConstraintDataUtils::getPivotB(m_data);
  v15 = _mm_sub_ps(*PivotA, vCom.m_quad);
  v16 = _mm_mul_ps(v15, v15);
  v17 = _mm_sub_ps(PivotB->m_quad, v36.m_quad);
  v18 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)), _mm_shuffle_ps(v16, v16, 170));
  v19 = _mm_mul_ps(v17, v17);
  v20 = _mm_rsqrt_ps(v18);
  v21 = _mm_mul_ps(
          _mm_andnot_ps(
            _mm_cmple_ps(v18, (__m128)0i64),
            _mm_mul_ps(
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v20, v18), v20)),
                _mm_mul_ps(*(__m128 *)_xmm, v20)),
              v18)),
          v11);
  v22 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)), _mm_shuffle_ps(v19, v19, 170));
  v23 = _mm_mul_ps(v21, stabilizationAmount->m_real);
  v24 = _mm_rsqrt_ps(v22);
  v25 = _mm_cmplt_ps(*(__m128 *)&epsilon, v23);
  v26 = _mm_mul_ps(*(__m128 *)_xmm, v24);
  v27 = _mm_mul_ps(_mm_mul_ps(v24, v22), v24);
  v28 = _mm_rcp_ps(v23);
  v29 = _mm_mul_ps(
          _mm_mul_ps(
            _mm_andnot_ps(
              _mm_cmple_ps(v22, (__m128)0i64),
              _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, v27), v26), v22)),
            v12),
          stabilizationAmount->m_real);
  v30 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v28, v23)), v28), _mm_shuffle_ps(m_quad, m_quad, 255));
  v31 = _mm_cmplt_ps(*(__m128 *)&epsilon, v29);
  v32 = _mm_rcp_ps(v29);
  inertiaScaleOutA->m_real = _mm_min_ps(_mm_or_ps(_mm_and_ps(v25, v30), _mm_andnot_ps(v25, query.m_quad)), query.m_quad);
  inertiaScaleOutB->m_real = _mm_min_ps(
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
__int64 __fastcall hkpConstraintStabilizationUtil::stabilizeRigidBodyInertia(
        hkpRigidBody *rigidBody,
        hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *constraints,
        const float stabilizationAmount,
        float solverStabilizationAmount)
{
  hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *v4; // rax
  __int64 m_size; // r12
  __int64 v7; // r14
  __m128 i; // xmm6
  __m128 m_quad; // xmm7
  hkpConstraintInstance *v10; // r15
  hkpConstraintData *m_data; // rcx
  float *v12; // rdi
  unsigned __int64 v13; // rsi
  float *v14; // rbx
  bool v15; // zf
  hkSimdFloat32 *p_inertiaScaleOutA; // rax
  __m128 v17; // xmm4
  __m128 v18; // xmm2
  __m128 v19; // xmm1
  __m128 v20; // xmm1
  hkSimdFloat32 stabilizationAmounta; // [rsp+20h] [rbp-79h] BYREF
  hkSimdFloat32 inertiaScaleOutA; // [rsp+30h] [rbp-69h] BYREF
  hkSimdFloat32 inertiaScaleOutB; // [rsp+40h] [rbp-59h] BYREF
  hkMatrix3f inertiaInv; // [rsp+50h] [rbp-49h] BYREF
  float vars0; // [rsp+100h] [rbp+67h]
  hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *retaddr; // [rsp+108h] [rbp+6Fh]
  unsigned int v28; // [rsp+110h] [rbp+77h]

  v4 = constraints;
  if ( !rigidBody || rigidBody->m_motion.m_type.m_storage == 5 )
    return 0i64;
  m_size = constraints->m_size;
  v7 = 0i64;
  stabilizationAmounta.m_real = _mm_shuffle_ps((__m128)v28, (__m128)v28, 0);
  for ( i = query.m_quad; v7 < m_size; i = _mm_min_ps(i, m_quad) )
  {
    m_quad = query.m_quad;
    v10 = v4->m_data[v7];
    m_data = v10->m_data;
    inertiaInv.m_col1.m_quad.m128_i32[3] = 0;
    m_data->vfptr[2].__vecDelDtor(m_data, (unsigned int)&inertiaInv);
    v12 = (float *)inertiaInv.m_col1.m_quad.m128_u64[0];
    v13 = inertiaInv.m_col1.m_quad.m128_u64[0] + inertiaInv.m_col1.m_quad.m128_u32[2];
    if ( inertiaInv.m_col1.m_quad.m128_u64[0] < v13 )
    {
      while ( 2 )
      {
        switch ( *(_WORD *)v12 )
        {
          case 0:
            v12 = (float *)(((unsigned __int64)v12 + 15) & 0xFFFFFFFFFFFFFFF0ui64);
            goto LABEL_22;
          case 1:
          case 0xF:
          case 0x10:
            v12 += 8;
            goto LABEL_22;
          case 2:
            v12 += 36;
            goto LABEL_22;
          case 3:
          case 0x20:
          case 0x22:
            v12 += 12;
            goto LABEL_22;
          case 4:
            v12 += 28;
            goto LABEL_22;
          case 5:
            v14 = v12;
            v12 += 4;
            hkpConstraintStabilizationUtil::computeBallSocketInertiaStabilizationFactors(
              v10,
              &stabilizationAmounta,
              &inertiaScaleOutA,
              &inertiaScaleOutB);
            v15 = v10->m_entities[0] == rigidBody;
            stabilizationAmounta.m_real.m128_i32[0] = 0;
            vars0 = solverStabilizationAmount;
            p_inertiaScaleOutA = &inertiaScaleOutA;
            stabilizationAmounta.m_real.m128_i32[2] = 1065353216;
            v14[3] = fminf(fmaxf(solverStabilizationAmount, 0.0), 1.0);
            if ( !v15 )
              p_inertiaScaleOutA = &inertiaScaleOutB;
            m_quad = p_inertiaScaleOutA->m_real;
            goto LABEL_22;
          case 6:
            v12 += 3;
            goto LABEL_22;
          case 7:
          case 8:
          case 9:
          case 0xA:
          case 0xC:
          case 0xD:
          case 0xE:
          case 0x11:
          case 0x15:
          case 0x16:
          case 0x17:
          case 0x18:
          case 0x1B:
            v12 += 4;
            goto LABEL_22;
          case 0xB:
            v12 += 6;
            goto LABEL_22;
          case 0x12:
            v12 += 10;
            goto LABEL_22;
          case 0x13:
            v12 += 24;
            goto LABEL_22;
          case 0x14:
          case 0x1E:
          case 0x21:
            v12 += 16;
            goto LABEL_22;
          case 0x1D:
            v12 = 0i64;
            goto LABEL_22;
          case 0x1F:
          case 0x23:
            v12 += 20;
LABEL_22:
            if ( (unsigned __int64)v12 >= v13 )
              break;
            continue;
          default:
            goto LABEL_23;
        }
        break;
      }
    }
LABEL_23:
    v4 = retaddr;
    ++v7;
  }
  vars0 = FLOAT_0_99999988;
  if ( i.m128_f32[0] >= _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_99999988), (__m128)LODWORD(FLOAT_0_99999988), 0).m128_f32[0] )
    return 0i64;
  ((void (__fastcall *)(hkpMaxSizeMotion *, hkMatrix3f *))rigidBody->m_motion.hkpEntity::vfptr[5].__first_virtual_table_function__)(
    &rigidBody->m_motion,
    &inertiaInv);
  v17 = _mm_or_ps(
          _mm_andnot_ps(
            (__m128)xmmword_141A9A460,
            _mm_or_ps(
              _mm_andnot_ps((__m128)xmmword_141A9A440, inertiaInv.m_col0.m_quad),
              _mm_and_ps(inertiaInv.m_col1.m_quad, (__m128)xmmword_141A9A440))),
          _mm_and_ps(inertiaInv.m_col2.m_quad, (__m128)xmmword_141A9A460));
  v18 = _mm_max_ps(_mm_shuffle_ps(v17, v17, 170), _mm_max_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)));
  v19 = _mm_cmplt_ps(*(__m128 *)&epsilon, v18);
  v20 = _mm_min_ps(v17, _mm_or_ps(_mm_and_ps(_mm_mul_ps(i, v18), v19), _mm_andnot_ps(v19, *(__m128 *)&epsilon)));
  inertiaInv.m_col2.m_quad = _mm_mul_ps(v20, stru_141A71280.m_quad);
  inertiaInv.m_col0.m_quad = _mm_mul_ps(v20, transform.m_quad);
  inertiaInv.m_col1.m_quad = _mm_mul_ps(v20, direction.m_quad);
  hkpRigidBody::setInertiaInvLocal(rigidBody, &inertiaInv);
  return 1i64;
}

// File Line: 355
// RVA: 0xD64890
__int64 __fastcall hkpConstraintStabilizationUtil::stabilizeRigidBodyInertia(
        hkpRigidBody *rigidBody,
        float stabilizationAmount,
        float solverStabilizationAmount)
{
  int NumConstraints; // eax
  __int64 v6; // rbp
  int v7; // r9d
  int v8; // edi
  __int64 v9; // rbx
  hkpConstraintInstance *Constraint; // rax
  unsigned int v11; // ebx
  hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> array; // [rsp+30h] [rbp-38h] BYREF
  hkResult result; // [rsp+70h] [rbp+8h] BYREF

  if ( !rigidBody )
    return 0i64;
  array.m_data = 0i64;
  array.m_size = 0;
  array.m_capacityAndFlags = 0x80000000;
  NumConstraints = hkpEntity::getNumConstraints(rigidBody);
  v6 = NumConstraints;
  if ( NumConstraints > 0 )
  {
    v7 = NumConstraints;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&array.m_data, v7, 8);
  }
  v8 = 0;
  v9 = 0i64;
  for ( array.m_size = v6; v9 < v6; ++v8 )
  {
    Constraint = hkpEntity::getConstraint(rigidBody, v8);
    array.m_data[v9++] = Constraint;
  }
  v11 = hkpConstraintStabilizationUtil::stabilizeRigidBodyInertia(
          rigidBody,
          &array,
          stabilizationAmount,
          solverStabilizationAmount);
  array.m_size = 0;
  if ( array.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      array.m_data,
      8 * array.m_capacityAndFlags);
  return v11;
}

// File Line: 379
// RVA: 0xD64D70
__int64 __fastcall hkpConstraintStabilizationUtil::stabilizePhysicsSystemInertias(
        hkpPhysicsSystem *physicsSystem,
        float stabilizationAmount,
        float solverStabilizationAmount)
{
  __int64 m_size; // rbp
  unsigned int v6; // edi
  __int64 i; // rbx
  int v8; // eax

  if ( !physicsSystem )
    return 0i64;
  m_size = physicsSystem->m_rigidBodies.m_size;
  v6 = 0;
  for ( i = 0i64; i < m_size; v6 += v8 )
    v8 = hkpConstraintStabilizationUtil::stabilizeRigidBodyInertia(
           physicsSystem->m_rigidBodies.m_data[i++],
           stabilizationAmount,
           solverStabilizationAmount);
  return v6;
}

// File Line: 403
// RVA: 0xD64E10
__int64 __fastcall hkpConstraintStabilizationUtil::stabilizePhysicsWorldInertias(
        hkpWorld *physicsWorld,
        float stabilizationAmount,
        float solverStabilizationAmount)
{
  unsigned int v5; // edi
  __int64 m_size; // rbp
  __int64 i; // rbx
  int v8; // eax
  hkArray<hkpRigidBody *,hkContainerHeapAllocator> rigidBodiesOut; // [rsp+20h] [rbp-38h] BYREF

  if ( !physicsWorld )
    return 0i64;
  v5 = 0;
  hkpWorld::lock(physicsWorld);
  rigidBodiesOut.m_data = 0i64;
  rigidBodiesOut.m_size = 0;
  rigidBodiesOut.m_capacityAndFlags = 0x80000000;
  collectRigidBodies_0(physicsWorld, &rigidBodiesOut);
  m_size = rigidBodiesOut.m_size;
  for ( i = 0i64; i < m_size; v5 += v8 )
    v8 = hkpConstraintStabilizationUtil::stabilizeRigidBodyInertia(
           rigidBodiesOut.m_data[i++],
           stabilizationAmount,
           solverStabilizationAmount);
  hkpWorld::unlock(physicsWorld);
  rigidBodiesOut.m_size = 0;
  if ( rigidBodiesOut.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      rigidBodiesOut.m_data,
      8 * rigidBodiesOut.m_capacityAndFlags);
  return v5;
}

// File Line: 434
// RVA: 0xD64F10
void __fastcall hkpConstraintStabilizationUtil::setConstraintsSolvingMethod(
        hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *constraints,
        unsigned int method)
{
  __int64 m_size; // rsi
  __int64 i; // rbx
  hkpConstraintData *m_data; // rcx

  m_size = constraints->m_size;
  for ( i = 0i64; i < m_size; ++i )
  {
    m_data = constraints->m_data[i]->m_data;
    m_data->vfptr[7].__vecDelDtor(m_data, method);
  }
}

// File Line: 448
// RVA: 0xD64F80
void __fastcall hkpConstraintStabilizationUtil::setConstraintsSolvingMethod(
        hkpRigidBody *rigidBody,
        unsigned int method)
{
  int NumConstraints; // eax
  __int64 v5; // rbx
  int v6; // r9d
  int v7; // esi
  __int64 v8; // rdi
  __int64 v9; // r14
  hkpConstraintInstance **v10; // rbx
  hkpConstraintInstance *Constraint; // rax
  hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> array; // [rsp+30h] [rbp-28h] BYREF
  hkResult result; // [rsp+60h] [rbp+8h] BYREF

  if ( rigidBody )
  {
    array.m_data = 0i64;
    array.m_size = 0;
    array.m_capacityAndFlags = 0x80000000;
    NumConstraints = hkpEntity::getNumConstraints(rigidBody);
    v5 = NumConstraints;
    if ( NumConstraints > 0 )
    {
      v6 = NumConstraints;
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&array.m_data, v6, 8);
    }
    v7 = 0;
    v8 = 0i64;
    array.m_size = v5;
    v9 = v5;
    if ( (int)v5 > 0 )
    {
      do
      {
        v10 = &array.m_data[v8];
        Constraint = hkpEntity::getConstraint(rigidBody, v7);
        ++v8;
        ++v7;
        *v10 = Constraint;
      }
      while ( v8 < v9 );
    }
    hkpConstraintStabilizationUtil::setConstraintsSolvingMethod(&array, method);
    array.m_size = 0;
    if ( array.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        array.m_data,
        8 * array.m_capacityAndFlags);
  }
}

// File Line: 471
// RVA: 0xD650A0
void __fastcall hkpConstraintStabilizationUtil::setConstraintsSolvingMethod(
        hkpPhysicsSystem *physicsSystem,
        unsigned int method)
{
  __int64 m_size; // rbp
  __int64 i; // rbx

  if ( physicsSystem )
  {
    hkpConstraintStabilizationUtil::setConstraintsSolvingMethod(&physicsSystem->m_constraints, method);
    m_size = physicsSystem->m_rigidBodies.m_size;
    for ( i = 0i64; i < m_size; ++i )
      hkpConstraintStabilizationUtil::setConstraintsSolvingMethod(physicsSystem->m_rigidBodies.m_data[i], method);
  }
}

// File Line: 496
// RVA: 0xD65120
void __fastcall hkpConstraintStabilizationUtil::setConstraintsSolvingMethod(
        hkpWorld *physicsWorld,
        unsigned int method)
{
  hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> constraintsOut; // [rsp+20h] [rbp-28h] BYREF
  hkArray<hkpRigidBody *,hkContainerHeapAllocator> rigidBodiesOut; // [rsp+30h] [rbp-18h] BYREF

  if ( physicsWorld )
  {
    hkpWorld::lock(physicsWorld);
    rigidBodiesOut.m_data = 0i64;
    rigidBodiesOut.m_size = 0;
    rigidBodiesOut.m_capacityAndFlags = 0x80000000;
    collectRigidBodies_0(physicsWorld, &rigidBodiesOut);
    constraintsOut.m_data = 0i64;
    constraintsOut.m_size = 0;
    constraintsOut.m_capacityAndFlags = 0x80000000;
    collectConstraints(&rigidBodiesOut, &constraintsOut);
    hkpConstraintStabilizationUtil::setConstraintsSolvingMethod(&constraintsOut, method);
    hkpWorld::unlock(physicsWorld);
    constraintsOut.m_size = 0;
    if ( constraintsOut.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        constraintsOut.m_data,
        8 * constraintsOut.m_capacityAndFlags);
    constraintsOut.m_data = 0i64;
    rigidBodiesOut.m_size = 0;
    constraintsOut.m_capacityAndFlags = 0x80000000;
    if ( rigidBodiesOut.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        rigidBodiesOut.m_data,
        8 * rigidBodiesOut.m_capacityAndFlags);
  }
}

