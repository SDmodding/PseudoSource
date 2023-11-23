// File Line: 40
// RVA: 0xE10630
void __fastcall copyAtoms(hkpRagdollConstraintData::Atoms *atomsIn, hkpRagdollConstraintData::Atoms *atomsOut)
{
  hkReferencedObject **m_motors; // rbx
  __int64 v4; // rdi

  hkpRagdollConstraintData::Atoms::operator=(atomsOut, atomsIn);
  m_motors = atomsOut->m_ragdollMotors.m_motors;
  v4 = 3i64;
  do
  {
    if ( *m_motors )
      hkReferencedObject::addReference(*m_motors);
    ++m_motors;
    --v4;
  }
  while ( v4 );
}

// File Line: 53
// RVA: 0xE10680
void __fastcall copyAtoms_0(
        hkpLimitedHingeConstraintData::Atoms *atomsIn,
        hkpLimitedHingeConstraintData::Atoms *atomsOut)
{
  hkpConstraintMotor *m_motor; // rcx

  hkpLimitedHingeConstraintData::Atoms::operator=(atomsOut, atomsIn);
  m_motor = atomsOut->m_angMotor.m_motor;
  if ( m_motor )
    hkReferencedObject::addReference(m_motor);
}

// File Line: 61
// RVA: 0xE0F690
hkStringPtr *__fastcall hkpConstraintUtils::convertToPowered(
        hkpConstraintInstance *originalConstraint,
        hkpConstraintMotor *constraintMotor,
        hkBool enableMotors)
{
  hkpConstraintData *m_data; // r14
  hkpEntity *v4; // rbp
  hkpEntity *v5; // r15
  int v8; // eax
  const char *v9; // rbx
  hkOstream *v10; // rax
  hkOstream *v11; // rax
  _QWORD **v13; // rax
  hkpRagdollConstraintData *v14; // rax
  hkStringPtr *v15; // rdi
  __int64 v16; // rax
  hkpLimitedHingeConstraintData *v17; // rbx
  _QWORD **Value; // rax
  hkpLimitedHingeConstraintData *v19; // rax
  hkpLimitedHingeConstraintData *v20; // rax
  _QWORD **v21; // rax
  hkpConstraintInstance *v22; // rax
  hkStringPtr *v23; // rax
  hkErrStream v24; // [rsp+30h] [rbp-248h] BYREF
  char buf[512]; // [rsp+50h] [rbp-228h] BYREF

  m_data = originalConstraint->m_data;
  v4 = originalConstraint->m_entities[0];
  v5 = originalConstraint->m_entities[1];
  v8 = ((__int64 (__fastcall *)(hkpConstraintData *))m_data->vfptr[1].__first_virtual_table_function__)(m_data);
  if ( v8 == 2 )
  {
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v19 = (hkpLimitedHingeConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                             Value[11],
                                             304i64);
    v15 = 0i64;
    if ( v19 )
    {
      hkpLimitedHingeConstraintData::hkpLimitedHingeConstraintData(v19);
      v17 = v20;
    }
    else
    {
      v17 = 0i64;
    }
    copyAtoms_0((hkpLimitedHingeConstraintData::Atoms *)&m_data[1].m_memSizeAndFlags, &v17->m_atoms);
  }
  else
  {
    if ( v8 != 7 )
    {
      hkErrStream::hkErrStream(&v24, buf, 512);
      v9 = (const char *)((unsigned __int64)originalConstraint->m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64);
      v10 = hkOstream::operator<<(&v24, "Cannot convert constraint \"");
      v11 = hkOstream::operator<<(v10, v9);
      hkOstream::operator<<(v11, "\" to a powered constraint.");
      hkError::messageWarning(0xABBA1B34, buf, "Constraint\\Bilateral\\hkpConstraintUtils.cpp", 86);
      hkOstream::~hkOstream(&v24);
      hkErrStream::hkErrStream(&v24, buf, 512);
      hkOstream::operator<<(&v24, "Only limited hinges and ragdoll constraints can be powered.");
      hkError::messageWarning(0xABBA1B34, buf, "Constraint\\Bilateral\\hkpConstraintUtils.cpp", 87);
      hkOstream::~hkOstream(&v24);
      return 0i64;
    }
    v13 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v14 = (hkpRagdollConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v13[11] + 8i64))(v13[11], 416i64);
    v15 = 0i64;
    if ( v14 )
    {
      hkpRagdollConstraintData::hkpRagdollConstraintData(v14);
      v17 = (hkpLimitedHingeConstraintData *)v16;
      copyAtoms(
        (hkpRagdollConstraintData::Atoms *)&m_data[1].m_memSizeAndFlags,
        (hkpRagdollConstraintData::Atoms *)(v16 + 32));
    }
    else
    {
      v17 = 0i64;
      copyAtoms(
        (hkpRagdollConstraintData::Atoms *)&m_data[1].m_memSizeAndFlags,
        (hkpRagdollConstraintData::Atoms *)0x20);
    }
  }
  hkpConstraintDataUtils::convertToPowered(v17, constraintMotor, enableMotors);
  v21 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v22 = (hkpConstraintInstance *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v21[11] + 8i64))(v21[11], 112i64);
  if ( v22 )
  {
    hkpConstraintInstance::hkpConstraintInstance(
      v22,
      v4,
      v5,
      v17,
      (hkpConstraintInstance::ConstraintPriority)(unsigned __int8)originalConstraint->m_priority.m_storage);
    v15 = v23;
  }
  hkReferencedObject::removeReference(v17);
  hkStringPtr::operator=(
    v15 + 10,
    (const char *)((unsigned __int64)originalConstraint->m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64));
  return v15;
}

// File Line: 101
// RVA: 0xE0F8C0
hkpConstraintData *__fastcall hkpConstraintUtils::convertToLimits(hkpConstraintInstance *originalConstraint)
{
  hkpConstraintData *result; // rax
  hkpConstraintData *v3; // rbx
  _QWORD **Value; // rax
  hkpConstraintInstance *v5; // rax
  __int64 v6; // rax
  __int64 v7; // rdi

  result = hkpConstraintDataUtils::createLimited(originalConstraint->m_data);
  v3 = result;
  if ( result )
  {
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v5 = (hkpConstraintInstance *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 112i64);
    if ( v5 )
    {
      hkpConstraintInstance::hkpConstraintInstance(
        v5,
        originalConstraint->m_entities[0],
        originalConstraint->m_entities[1],
        v3,
        (hkpConstraintInstance::ConstraintPriority)(unsigned __int8)originalConstraint->m_priority.m_storage);
      v7 = v6;
      hkReferencedObject::removeReference(v3);
      return (hkpConstraintData *)v7;
    }
    else
    {
      hkReferencedObject::removeReference(v3);
      return 0i64;
    }
  }
  return result;
}

// File Line: 117
// RVA: 0xE0F960
hkBool *__fastcall hkpConstraintUtils::checkAndFixConstraint(
        hkBool *result,
        hkpConstraintInstance *constraint,
        float maxAllowedError,
        float relativeFixupOnError)
{
  __m128 m_quad; // xmm4
  __m128 v8; // xmm1
  hkpEntity *v9; // rbp
  hkpRigidBody *v10; // rsi
  float v11; // xmm3_4
  __m128 v12; // xmm5
  __m128 v13; // xmm2
  __m128 v14; // xmm2
  hkErrStream v15; // [rsp+30h] [rbp-258h] BYREF
  hkVector4f pivotInAOut; // [rsp+50h] [rbp-238h] BYREF
  hkVector4f pivotInBOut; // [rsp+60h] [rbp-228h] BYREF
  char buf[512]; // [rsp+70h] [rbp-218h] BYREF
  hkResult resulta; // [rsp+298h] [rbp+10h] BYREF
  unsigned int v20; // [rsp+2A0h] [rbp+18h]
  unsigned int v21; // [rsp+2A8h] [rbp+20h]

  v21 = LODWORD(relativeFixupOnError);
  v20 = LODWORD(maxAllowedError);
  hkpConstraintDataUtils::getConstraintPivots(&resulta, constraint->m_data, &pivotInAOut, &pivotInBOut);
  if ( resulta.m_enum )
  {
    result->m_bool = 0;
    return result;
  }
  else
  {
    m_quad = pivotInAOut.m_quad;
    v8 = _mm_mul_ps(pivotInAOut.m_quad, pivotInAOut.m_quad);
    if ( (float)((float)(_mm_shuffle_ps(v8, v8, 85).m128_f32[0] + _mm_shuffle_ps(v8, v8, 0).m128_f32[0])
               + _mm_shuffle_ps(v8, v8, 170).m128_f32[0]) > _mm_shuffle_ps(
                                                              (__m128)LODWORD(FLOAT_0_000001),
                                                              (__m128)LODWORD(FLOAT_0_000001),
                                                              0).m128_f32[0] )
    {
      hkErrStream::hkErrStream(&v15, buf, 512);
      hkOstream::operator<<(
        &v15,
        "Pivot of child rigid body (A) is expected to be aligned with the constraint at setup time.");
      hkError::messageWarning(0xABBA5DFF, buf, "Constraint\\Bilateral\\hkpConstraintUtils.cpp", 132);
      hkOstream::~hkOstream(&v15);
      m_quad = pivotInAOut.m_quad;
    }
    v9 = constraint->m_entities[1];
    v10 = (hkpRigidBody *)constraint->m_entities[0];
    v11 = _mm_shuffle_ps((__m128)v20, (__m128)v20, 0).m128_f32[0];
    v12 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_shuffle_ps(pivotInBOut.m_quad, pivotInBOut.m_quad, 85),
                  v9->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad),
                _mm_mul_ps(
                  _mm_shuffle_ps(pivotInBOut.m_quad, pivotInBOut.m_quad, 0),
                  v9->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad)),
              _mm_mul_ps(
                _mm_shuffle_ps(pivotInBOut.m_quad, pivotInBOut.m_quad, 170),
                v9->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad)),
            v9->m_motion.m_motionState.m_transform.m_translation.m_quad);
    v13 = _mm_sub_ps(
            v12,
            _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_shuffle_ps(m_quad, m_quad, 85),
                    v10->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad),
                  _mm_mul_ps(
                    _mm_shuffle_ps(m_quad, m_quad, 0),
                    v10->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad)),
                _mm_mul_ps(
                  _mm_shuffle_ps(m_quad, m_quad, 170),
                  v10->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad)),
              v10->m_motion.m_motionState.m_transform.m_translation.m_quad));
    v14 = _mm_mul_ps(v13, v13);
    if ( (float)((float)(_mm_shuffle_ps(v14, v14, 85).m128_f32[0] + _mm_shuffle_ps(v14, v14, 0).m128_f32[0])
               + _mm_shuffle_ps(v14, v14, 170).m128_f32[0]) <= (float)(v11 * v11) )
    {
      result->m_bool = 0;
    }
    else
    {
      v15.hkReferencedObject = (hkReferencedObject)_mm_add_ps(
                                                     _mm_mul_ps(
                                                       _mm_shuffle_ps((__m128)v21, (__m128)v21, 0),
                                                       _mm_sub_ps(
                                                         v9->m_motion.m_motionState.m_transform.m_translation.m_quad,
                                                         v12)),
                                                     v12);
      hkpRigidBody::setPosition(v10, (hkVector4f *)&v15);
      hkpEntity::activate(v10);
      v10->m_motion.hkpEntity::vfptr[9].__vecDelDtor(&v10->m_motion, (unsigned int)&v9->m_motion.m_linearVelocity);
      hkpEntity::activate(v10);
      ((void (__fastcall *)(hkpMaxSizeMotion *, hkVector4f *))v10->m_motion.hkpEntity::vfptr[9].__first_virtual_table_function__)(
        &v10->m_motion,
        &v9->m_motion.m_angularVelocity);
      result->m_bool = 1;
    }
    return result;
  }
}

// File Line: 174
// RVA: 0xE0FBA0
void __fastcall hkpConstraintUtils::setHingePivotToOptimalPosition(hkpConstraintInstance *constraint)
{
  hkpConstraintData *m_data; // rbx
  hkpEntity *v3; // rsi
  hkpEntity *v4; // rdi
  hkVector4f v5; // xmm1
  hkVector4f v6; // xmm0
  __m128 v7; // xmm1
  __m128 v8; // xmm11
  __m128 v9; // xmm1
  __m128 v10; // xmm2
  hkVector4f v11; // xmm1
  hkVector4f v12; // xmm0
  __m128 v13; // xmm1
  __m128 v14; // xmm12
  __m128 v15; // xmm1
  __m128 v16; // xmm2
  __m128 v17; // xmm9
  __m128 v18; // xmm6
  __m128 v19; // xmm1
  __m128 v20; // xmm7
  __m128 v21; // xmm1
  __m128 v22; // xmm4
  __m128 v23; // xmm1
  __m128 v24; // xmm2
  __m128 v25; // xmm0
  __m128 v26; // xmm1
  __m128 v27; // xmm3
  __m128 v28; // xmm0
  hkMatrix3f v29; // [rsp+20h] [rbp-C8h] BYREF
  hkMatrix3f v30; // [rsp+50h] [rbp-98h] BYREF

  m_data = constraint->m_data;
  if ( ((unsigned int (__fastcall *)(hkpConstraintData *))m_data->vfptr[1].__first_virtual_table_function__)(m_data) - 1 <= 1 )
  {
    v3 = constraint->m_entities[0];
    v4 = constraint->m_entities[1];
    ((void (__fastcall *)(hkpMaxSizeMotion *, hkMatrix3f *))v3->m_motion.vfptr[5].__first_virtual_table_function__)(
      &v3->m_motion,
      &v30);
    v5.m_quad = *(__m128 *)&m_data[2].m_userData;
    v29.m_col0 = (hkVector4f)m_data[2].hkReferencedObject;
    v6.m_quad = *(__m128 *)&m_data[3].m_memSizeAndFlags;
    v29.m_col1 = (hkVector4f)v5.m_quad;
    v29.m_col2 = (hkVector4f)v6.m_quad;
    hkMatrix3f::transpose(&v29);
    hkMatrix3f::changeBasis(&v30, (hkRotationf *)&v29);
    v7 = (__m128)_mm_slli_si128(_mm_srli_si128((__m128i)_mm_add_ps(v30.m_col2.m_quad, v30.m_col1.m_quad), 4), 4);
    v8 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps(v7, v7, 0)), _mm_shuffle_ps(v7, v7, 170));
    v9 = _mm_shuffle_ps(v3->m_motion.m_inertiaAndMassInv.m_quad, v3->m_motion.m_inertiaAndMassInv.m_quad, 255);
    if ( v9.m128_f32[0] > 0.00000011920929 )
    {
      v10 = _mm_rcp_ps(v9);
      v8 = _mm_mul_ps(v8, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v10, v9)), v10));
    }
    ((void (__fastcall *)(hkpMaxSizeMotion *, hkMatrix3f *))v4->m_motion.vfptr[5].__first_virtual_table_function__)(
      &v4->m_motion,
      &v30);
    v11.m_quad = *(__m128 *)&m_data[5].m_memSizeAndFlags;
    v29.m_col0 = *(hkVector4f *)&m_data[4].m_userData;
    v12.m_quad = (__m128)m_data[6].hkReferencedObject;
    v29.m_col1 = (hkVector4f)v11.m_quad;
    v29.m_col2 = (hkVector4f)v12.m_quad;
    hkMatrix3f::transpose(&v29);
    hkMatrix3f::changeBasis(&v30, (hkRotationf *)&v29);
    v13 = (__m128)_mm_slli_si128(_mm_srli_si128((__m128i)_mm_add_ps(v30.m_col2.m_quad, v30.m_col1.m_quad), 4), 4);
    v14 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)),
            _mm_shuffle_ps(v13, v13, 170));
    v15 = _mm_shuffle_ps(v4->m_motion.m_inertiaAndMassInv.m_quad, v4->m_motion.m_inertiaAndMassInv.m_quad, 255);
    if ( v15.m128_f32[0] > 0.00000011920929 )
    {
      v16 = _mm_rcp_ps(v15);
      v14 = _mm_mul_ps(v14, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v16, v15)), v16));
    }
    v17 = _mm_sub_ps(
            (__m128)m_data[4].hkReferencedObject,
            v3->m_motion.m_motionState.m_sweptTransform.m_centerOfMassLocal.m_quad);
    v18 = _mm_sub_ps(
            *(__m128 *)&m_data[6].m_userData,
            v4->m_motion.m_motionState.m_sweptTransform.m_centerOfMassLocal.m_quad);
    v19 = _mm_mul_ps((__m128)m_data[2].hkReferencedObject, v17);
    v20 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)),
            _mm_shuffle_ps(v19, v19, 170));
    v21 = _mm_mul_ps(*(__m128 *)&m_data[4].m_userData, v18);
    v22 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)),
            _mm_shuffle_ps(v21, v21, 170));
    v23 = _mm_add_ps(v8, v14);
    v24 = _mm_rcp_ps(v23);
    v25 = _mm_mul_ps(v24, v23);
    v26 = _mm_sub_ps(v20, v22);
    v27 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, v25), v24);
    v28 = _mm_mul_ps(
            _mm_sub_ps(_mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)0i64, v26), v8), v27), v22),
            *(__m128 *)&m_data[4].m_userData);
    m_data[4].hkReferencedObject = (hkReferencedObject)_mm_add_ps(
                                                         _mm_add_ps(
                                                           _mm_mul_ps(
                                                             _mm_sub_ps(_mm_mul_ps(_mm_mul_ps(v26, v14), v27), v20),
                                                             (__m128)m_data[2].hkReferencedObject),
                                                           v17),
                                                         v3->m_motion.m_motionState.m_sweptTransform.m_centerOfMassLocal.m_quad);
    *(__m128 *)&m_data[6].m_userData = _mm_add_ps(
                                         _mm_add_ps(v18, v28),
                                         v4->m_motion.m_motionState.m_sweptTransform.m_centerOfMassLocal.m_quad);
  }
}

// File Line: 268
// RVA: 0xE0FE70
void __fastcall hkpConstraintUtils::collectConstraints(
        hkArray<hkpEntity *,hkContainerHeapAllocator> *entities,
        hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *constraintsOut,
        hkpConstraintUtils::CollectConstraintsFilter *collectionFilter)
{
  int v3; // r12d
  hkArray<hkpEntity *,hkContainerHeapAllocator> *v6; // rax
  __int64 v7; // r13
  hkpEntity *v8; // r15
  int v9; // ebx
  int NumConstraints; // ebp
  hkpConstraintInstance *Constraint; // rax
  hkpConstraintInstance *v12; // rsi
  int Key; // eax
  AMD_HD3D v14; // [rsp+20h] [rbp-48h] BYREF
  char v16; // [rsp+88h] [rbp+20h] BYREF

  *(_QWORD *)&v14.mEnableStereo = 0i64;
  v3 = 0;
  v6 = entities;
  v14.mWidth = 0;
  v14.mHeight = -1;
  if ( entities->m_size > 0 )
  {
    v7 = 0i64;
    do
    {
      v8 = v6->m_data[v7];
      v9 = 0;
      NumConstraints = hkpEntity::getNumConstraints(v8);
      if ( NumConstraints > 0 )
      {
        do
        {
          Constraint = hkpEntity::getConstraint(v8, v9);
          v12 = Constraint;
          if ( !collectionFilter
            || collectionFilter->vfptr->collectConstraint(collectionFilter, &v16, Constraint)->m_bool )
          {
            Key = (unsigned int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                                  (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v14,
                                  (unsigned __int64)v12);
            if ( Key > (int)v14.mHeight )
            {
              hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
                (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v14,
                &hkContainerTempAllocator::s_alloc,
                (unsigned __int64)v12,
                1ui64);
              if ( constraintsOut->m_size == (constraintsOut->m_capacityAndFlags & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&constraintsOut->m_data, 8);
              constraintsOut->m_data[constraintsOut->m_size++] = v12;
            }
          }
          ++v9;
        }
        while ( v9 < NumConstraints );
      }
      v6 = entities;
      ++v3;
      ++v7;
    }
    while ( v3 < entities->m_size );
  }
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v14,
    &hkContainerTempAllocator::s_alloc);
  _(&v14);
}

// File Line: 291
// RVA: 0xE0FFE0
hkpConstraintInstance *__fastcall hkpConstraintUtils::createMatchingHingeConstraintFromCogWheelConstraint(
        hkpConstraintInstance *constraint,
        int bodyIndex,
        hkpRigidBody *anotherBody,
        bool createLimitedHinge)
{
  hkpConstraintData *m_data; // rax
  hkpEntity *v6; // rsi
  __m128 *p_m_userData; // rbp
  _QWORD **v8; // rax
  hkpHingeConstraintData *v9; // rax
  __int64 v10; // rdi
  hkpLimitedHingeConstraintData *v11; // rax
  hkpLimitedHingeConstraintData *v12; // rbx
  __m128 v13; // xmm1
  __m128 v14; // xmm2
  __m128 v15; // xmm1
  __m128 v16; // xmm0
  _QWORD **Value; // rax
  hkpLimitedHingeConstraintData *v18; // rax
  hkpLimitedHingeConstraintData *v19; // rax
  __m128 v20; // xmm1
  __m128 v21; // xmm2
  __m128 v22; // xmm1
  __m128 v23; // xmm0
  _QWORD **v24; // rax
  hkpConstraintInstance *v25; // rax
  __int64 v26; // rax
  hkVector4f axis; // [rsp+30h] [rbp-48h] BYREF
  hkVector4f pivot; // [rsp+40h] [rbp-38h] BYREF
  hkVector4f axisIn; // [rsp+50h] [rbp-28h] BYREF
  hkVector4f v31; // [rsp+60h] [rbp-18h] BYREF

  m_data = constraint->m_data;
  if ( bodyIndex )
    v6 = constraint->m_entities[0];
  else
    v6 = constraint->m_entities[1];
  p_m_userData = (__m128 *)&m_data[4].m_userData;
  if ( !bodyIndex )
    p_m_userData = (__m128 *)&m_data[2];
  if ( createLimitedHinge )
  {
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v18 = (hkpLimitedHingeConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                             Value[11],
                                             304i64);
    v10 = 0i64;
    if ( v18 )
    {
      hkpLimitedHingeConstraintData::hkpLimitedHingeConstraintData(v18);
      v12 = v19;
    }
    else
    {
      v12 = 0i64;
    }
    v20 = p_m_userData[3];
    v21 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v20, v20, 0), v6->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v20, v20, 85), v6->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v20, v20, 170), v6->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad));
    v22 = *p_m_userData;
    v23 = _mm_mul_ps(_mm_shuffle_ps(v22, v22, 85), v6->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad);
    v31.m_quad = _mm_add_ps(v21, v6->m_motion.m_motionState.m_transform.m_translation.m_quad);
    axisIn.m_quad = _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(
                          _mm_shuffle_ps(v22, v22, 0),
                          v6->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad),
                        v23),
                      _mm_mul_ps(
                        _mm_shuffle_ps(v22, v22, 170),
                        v6->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad));
    hkpLimitedHingeConstraintData::setInWorldSpace(
      v12,
      &v6->m_motion.m_motionState.m_transform,
      &anotherBody->m_motion.m_motionState.m_transform,
      &v31,
      &axisIn);
  }
  else
  {
    v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v9 = (hkpHingeConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v8[11] + 8i64))(v8[11], 224i64);
    v10 = 0i64;
    if ( v9 )
    {
      hkpHingeConstraintData::hkpHingeConstraintData(v9);
      v12 = v11;
    }
    else
    {
      v12 = 0i64;
    }
    v13 = p_m_userData[3];
    v14 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v13, v13, 0), v6->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v13, v13, 85), v6->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v13, v13, 170), v6->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad));
    v15 = *p_m_userData;
    v16 = _mm_mul_ps(_mm_shuffle_ps(v15, v15, 85), v6->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad);
    pivot.m_quad = _mm_add_ps(v14, v6->m_motion.m_motionState.m_transform.m_translation.m_quad);
    axis.m_quad = _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_shuffle_ps(v15, v15, 0),
                        v6->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad),
                      v16),
                    _mm_mul_ps(
                      _mm_shuffle_ps(v15, v15, 170),
                      v6->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad));
    hkpHingeConstraintData::setInWorldSpace(
      (hkpHingeConstraintData *)v12,
      &v6->m_motion.m_motionState.m_transform,
      &anotherBody->m_motion.m_motionState.m_transform,
      &pivot,
      &axis);
  }
  v24 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v25 = (hkpConstraintInstance *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v24[11] + 8i64))(v24[11], 112i64);
  if ( v25 )
  {
    hkpConstraintInstance::hkpConstraintInstance(v25, v6, anotherBody, v12, PRIORITY_PSI);
    v10 = v26;
  }
  hkReferencedObject::removeReference(v12);
  return (hkpConstraintInstance *)v10;
}

// File Line: 327
// RVA: 0xE10200
hkpConstraintInstance *__fastcall hkpConstraintUtils::createMatchingPrismaticConstraintFromRackAndPinionConstraint(
        hkpConstraintInstance *constraint,
        hkpRigidBody *anotherBody)
{
  hkpEntity *v2; // r14
  hkpConstraintData *m_data; // rdx
  __m128 v5; // xmm1
  __m128 v6; // xmm4
  __m128 v7; // xmm1
  __m128 v8; // xmm3
  __m128 v9; // xmm1
  __m128 v10; // xmm2
  __m128 v11; // xmm5
  __m128 v12; // xmm5
  __m128 v13; // xmm3
  __m128 v14; // xmm2
  __m128 v15; // xmm1
  _QWORD **Value; // rax
  hkpPrismaticConstraintData *v17; // rax
  __int64 v18; // rdi
  hkpPrismaticConstraintData *v19; // rax
  hkpPrismaticConstraintData *v20; // rbx
  _QWORD **v21; // rax
  hkpConstraintInstance *v22; // rax
  __int64 v23; // rax
  hkVector4f pivot; // [rsp+30h] [rbp-28h] BYREF
  hkVector4f axis; // [rsp+40h] [rbp-18h] BYREF

  v2 = constraint->m_entities[1];
  m_data = constraint->m_data;
  v5 = *(__m128 *)&m_data[6].m_userData;
  v6 = _mm_add_ps(
         _mm_add_ps(
           _mm_add_ps(
             _mm_mul_ps(_mm_shuffle_ps(v5, v5, 85), v2->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad),
             _mm_mul_ps(_mm_shuffle_ps(v5, v5, 0), v2->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad)),
           _mm_mul_ps(_mm_shuffle_ps(v5, v5, 170), v2->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad)),
         v2->m_motion.m_motionState.m_transform.m_translation.m_quad);
  pivot.m_quad = v6;
  v7 = *(__m128 *)&m_data[4].m_userData;
  v8 = _mm_add_ps(
         _mm_add_ps(
           _mm_mul_ps(_mm_shuffle_ps(v7, v7, 0), v2->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad),
           _mm_mul_ps(_mm_shuffle_ps(v7, v7, 85), v2->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad)),
         _mm_mul_ps(_mm_shuffle_ps(v7, v7, 170), v2->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad));
  axis.m_quad = v8;
  if ( !LOBYTE(m_data[7].m_userData) )
  {
    v9 = (__m128)m_data[2].hkReferencedObject;
    v10 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(
                _mm_shuffle_ps(v9, v9, 85),
                constraint->m_entities[0]->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad),
              _mm_mul_ps(
                _mm_shuffle_ps(v9, v9, 0),
                constraint->m_entities[0]->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad)),
            _mm_mul_ps(
              _mm_shuffle_ps(v9, v9, 170),
              constraint->m_entities[0]->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad));
    v11 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), v8), _mm_mul_ps(_mm_shuffle_ps(v8, v8, 201), v10));
    v12 = _mm_shuffle_ps(v11, v11, 201);
    v13 = _mm_mul_ps(v12, v12);
    if ( (float)((float)(_mm_shuffle_ps(v13, v13, 85).m128_f32[0] + _mm_shuffle_ps(v13, v13, 0).m128_f32[0])
               + _mm_shuffle_ps(v13, v13, 170).m128_f32[0]) >= 1.4210855e-14 )
    {
      v14 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)),
              _mm_shuffle_ps(v13, v13, 170));
      v15 = _mm_rsqrt_ps(v14);
      pivot.m_quad = _mm_add_ps(
                       v6,
                       _mm_mul_ps(
                         _mm_mul_ps(
                           _mm_andnot_ps(
                             _mm_cmple_ps(v14, (__m128)0i64),
                             _mm_mul_ps(
                               _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v15, v14), v15)),
                               _mm_mul_ps(*(__m128 *)_xmm, v15))),
                           v12),
                         _mm_shuffle_ps(
                           (__m128)*(unsigned int *)(&m_data[7].m_referenceCount + 1),
                           (__m128)*(unsigned int *)(&m_data[7].m_referenceCount + 1),
                           0)));
    }
  }
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v17 = (hkpPrismaticConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                        Value[11],
                                        288i64);
  v18 = 0i64;
  if ( v17 )
  {
    hkpPrismaticConstraintData::hkpPrismaticConstraintData(v17);
    v20 = v19;
  }
  else
  {
    v20 = 0i64;
  }
  hkpPrismaticConstraintData::setInWorldSpace(
    v20,
    &v2->m_motion.m_motionState.m_transform,
    &anotherBody->m_motion.m_motionState.m_transform,
    &pivot,
    &axis);
  v21 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v22 = (hkpConstraintInstance *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v21[11] + 8i64))(v21[11], 112i64);
  if ( v22 )
  {
    hkpConstraintInstance::hkpConstraintInstance(v22, v2, anotherBody, v20, PRIORITY_PSI);
    v18 = v23;
  }
  hkReferencedObject::removeReference(v20);
  return (hkpConstraintInstance *)v18;
}

// File Line: 370
// RVA: 0xE10430
hkpConstraintInstance *__fastcall hkpConstraintUtils::createMatchingHingeConstraintFromRackAndPinionConstraint(
        hkpConstraintInstance *constraint,
        hkpRigidBody *anotherBody,
        bool createLimitedHinge)
{
  hkpConstraintData *m_data; // r14
  hkpEntity *v4; // rbp
  _QWORD **v6; // rax
  hkpHingeConstraintData *v7; // rax
  __int64 v8; // rdi
  hkpLimitedHingeConstraintData *v9; // rax
  hkpLimitedHingeConstraintData *v10; // rbx
  __m128 v11; // xmm1
  __m128 v12; // xmm2
  __m128 v13; // xmm1
  __m128 v14; // xmm0
  _QWORD **Value; // rax
  hkpLimitedHingeConstraintData *v16; // rax
  hkpLimitedHingeConstraintData *v17; // rax
  __m128 v18; // xmm1
  __m128 v19; // xmm2
  __m128 v20; // xmm1
  __m128 v21; // xmm0
  _QWORD **v22; // rax
  hkpConstraintInstance *v23; // rax
  __int64 v24; // rax
  hkVector4f axis; // [rsp+30h] [rbp-48h] BYREF
  hkVector4f pivot; // [rsp+40h] [rbp-38h] BYREF
  hkVector4f axisIn; // [rsp+50h] [rbp-28h] BYREF
  hkVector4f v29; // [rsp+60h] [rbp-18h] BYREF

  m_data = constraint->m_data;
  v4 = constraint->m_entities[0];
  if ( createLimitedHinge )
  {
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v16 = (hkpLimitedHingeConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                             Value[11],
                                             304i64);
    v8 = 0i64;
    if ( v16 )
    {
      hkpLimitedHingeConstraintData::hkpLimitedHingeConstraintData(v16);
      v10 = v17;
    }
    else
    {
      v10 = 0i64;
    }
    v18 = (__m128)m_data[4].hkReferencedObject;
    v19 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v18, v18, 0), v4->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v18, v18, 85), v4->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v18, v18, 170), v4->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad));
    v20 = (__m128)m_data[2].hkReferencedObject;
    v21 = _mm_mul_ps(_mm_shuffle_ps(v20, v20, 85), v4->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad);
    v29.m_quad = _mm_add_ps(v19, v4->m_motion.m_motionState.m_transform.m_translation.m_quad);
    axisIn.m_quad = _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(
                          _mm_shuffle_ps(v20, v20, 0),
                          v4->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad),
                        v21),
                      _mm_mul_ps(
                        _mm_shuffle_ps(v20, v20, 170),
                        v4->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad));
    hkpLimitedHingeConstraintData::setInWorldSpace(
      v10,
      &v4->m_motion.m_motionState.m_transform,
      &anotherBody->m_motion.m_motionState.m_transform,
      &v29,
      &axisIn);
  }
  else
  {
    v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v7 = (hkpHingeConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v6[11] + 8i64))(v6[11], 224i64);
    v8 = 0i64;
    if ( v7 )
    {
      hkpHingeConstraintData::hkpHingeConstraintData(v7);
      v10 = v9;
    }
    else
    {
      v10 = 0i64;
    }
    v11 = (__m128)m_data[4].hkReferencedObject;
    v12 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v11, v11, 0), v4->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v11, v11, 85), v4->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v11, v11, 170), v4->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad));
    v13 = (__m128)m_data[2].hkReferencedObject;
    v14 = _mm_mul_ps(_mm_shuffle_ps(v13, v13, 85), v4->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad);
    pivot.m_quad = _mm_add_ps(v12, v4->m_motion.m_motionState.m_transform.m_translation.m_quad);
    axis.m_quad = _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_shuffle_ps(v13, v13, 0),
                        v4->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad),
                      v14),
                    _mm_mul_ps(
                      _mm_shuffle_ps(v13, v13, 170),
                      v4->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad));
    hkpHingeConstraintData::setInWorldSpace(
      (hkpHingeConstraintData *)v10,
      &v4->m_motion.m_motionState.m_transform,
      &anotherBody->m_motion.m_motionState.m_transform,
      &pivot,
      &axis);
  }
  v22 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v23 = (hkpConstraintInstance *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v22[11] + 8i64))(v22[11], 112i64);
  if ( v23 )
  {
    hkpConstraintInstance::hkpConstraintInstance(v23, v4, anotherBody, v10, PRIORITY_PSI);
    v8 = v24;
  }
  hkReferencedObject::removeReference(v10);
  return (hkpConstraintInstance *)v8;
}

