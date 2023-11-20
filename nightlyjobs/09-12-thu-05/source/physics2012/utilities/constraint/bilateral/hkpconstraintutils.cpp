// File Line: 40
// RVA: 0xE10630
void __fastcall copyAtoms(hkpRagdollConstraintData::Atoms *atomsIn, hkpRagdollConstraintData::Atoms *atomsOut)
{
  hkpRagdollConstraintData::Atoms *v2; // rbx
  hkReferencedObject **v3; // rbx
  signed __int64 v4; // rdi

  v2 = atomsOut;
  hkpRagdollConstraintData::Atoms::operator=(atomsOut, atomsIn);
  v3 = (hkReferencedObject **)v2->m_ragdollMotors.m_motors;
  v4 = 3i64;
  do
  {
    if ( *v3 )
      hkReferencedObject::addReference(*v3);
    ++v3;
    --v4;
  }
  while ( v4 );
}

// File Line: 53
// RVA: 0xE10680
void __fastcall copyAtoms_0(hkpLimitedHingeConstraintData::Atoms *atomsIn, hkpLimitedHingeConstraintData::Atoms *atomsOut)
{
  hkpLimitedHingeConstraintData::Atoms *v2; // rbx
  hkReferencedObject *v3; // rcx

  v2 = atomsOut;
  hkpLimitedHingeConstraintData::Atoms::operator=(atomsOut, atomsIn);
  v3 = (hkReferencedObject *)&v2->m_angMotor.m_motor->vfptr;
  if ( v3 )
    hkReferencedObject::addReference(v3);
}

// File Line: 61
// RVA: 0xE0F690
hkStringPtr *__fastcall hkpConstraintUtils::convertToPowered(hkpConstraintInstance *originalConstraint, hkpConstraintMotor *constraintMotor, hkBool enableMotors)
{
  hkpConstraintData *v3; // r14
  hkpEntity *v4; // rbp
  hkpEntity *v5; // r15
  hkpConstraintInstance *v6; // rsi
  hkpConstraintMotor *v7; // r12
  int v8; // eax
  const char *v9; // rbx
  hkOstream *v10; // rax
  hkOstream *v11; // rax
  _QWORD **v13; // rax
  hkpRagdollConstraintData *v14; // rax
  hkStringPtr *v15; // rdi
  __int64 v16; // rax
  __int64 v17; // rbx
  _QWORD **v18; // rax
  hkpLimitedHingeConstraintData *v19; // rax
  __int64 v20; // rax
  _QWORD **v21; // rax
  hkpConstraintInstance *v22; // rax
  hkStringPtr *v23; // rax
  hkErrStream v24; // [rsp+30h] [rbp-248h]
  char buf; // [rsp+50h] [rbp-228h]
  char v26; // [rsp+290h] [rbp+18h]

  v26 = enableMotors.m_bool;
  v3 = originalConstraint->m_data;
  v4 = originalConstraint->m_entities[0];
  v5 = originalConstraint->m_entities[1];
  v6 = originalConstraint;
  v7 = constraintMotor;
  v8 = ((__int64 (__fastcall *)(hkpConstraintData *))v3->vfptr[1].__first_virtual_table_function__)(originalConstraint->m_data);
  if ( v8 == 2 )
  {
    v18 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v19 = (hkpLimitedHingeConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v18[11] + 8i64))(
                                             v18[11],
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
    copyAtoms_0(
      (hkpLimitedHingeConstraintData::Atoms *)&v3[1].m_memSizeAndFlags,
      (hkpLimitedHingeConstraintData::Atoms *)(v17 + 32));
  }
  else
  {
    if ( v8 != 7 )
    {
      hkErrStream::hkErrStream(&v24, &buf, 512);
      v9 = (const char *)((_QWORD)v6->m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64);
      v10 = hkOstream::operator<<((hkOstream *)&v24.vfptr, "Cannot convert constraint \"");
      v11 = hkOstream::operator<<(v10, v9);
      hkOstream::operator<<(v11, "\" to a powered constraint.");
      hkError::messageWarning(-1413866700, &buf, "Constraint\\Bilateral\\hkpConstraintUtils.cpp", 86);
      hkOstream::~hkOstream((hkOstream *)&v24.vfptr);
      hkErrStream::hkErrStream(&v24, &buf, 512);
      hkOstream::operator<<((hkOstream *)&v24.vfptr, "Only limited hinges and ragdoll constraints can be powered.");
      hkError::messageWarning(-1413866700, &buf, "Constraint\\Bilateral\\hkpConstraintUtils.cpp", 87);
      hkOstream::~hkOstream((hkOstream *)&v24.vfptr);
      return 0i64;
    }
    v13 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v14 = (hkpRagdollConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v13[11] + 8i64))(
                                        v13[11],
                                        416i64);
    v15 = 0i64;
    if ( v14 )
    {
      hkpRagdollConstraintData::hkpRagdollConstraintData(v14);
      v17 = v16;
      copyAtoms(
        (hkpRagdollConstraintData::Atoms *)&v3[1].m_memSizeAndFlags,
        (hkpRagdollConstraintData::Atoms *)(v16 + 32));
    }
    else
    {
      v17 = 0i64;
      copyAtoms((hkpRagdollConstraintData::Atoms *)&v3[1].m_memSizeAndFlags, (hkpRagdollConstraintData::Atoms *)0x20);
    }
  }
  hkpConstraintDataUtils::convertToPowered((hkpConstraintData *)v17, v7, (hkBool)v26);
  v21 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v22 = (hkpConstraintInstance *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v21[11] + 8i64))(
                                   v21[11],
                                   112i64);
  if ( v22 )
  {
    hkpConstraintInstance::hkpConstraintInstance(
      v22,
      v4,
      v5,
      (hkpConstraintData *)v17,
      (hkpConstraintInstance::ConstraintPriority)(unsigned __int8)v6->m_priority.m_storage);
    v15 = v23;
  }
  hkReferencedObject::removeReference((hkReferencedObject *)v17);
  hkStringPtr::operator=(v15 + 10, (const char *)((_QWORD)v6->m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64));
  return v15;
}

// File Line: 101
// RVA: 0xE0F8C0
hkpConstraintData *__fastcall hkpConstraintUtils::convertToLimits(hkpConstraintInstance *originalConstraint)
{
  hkpConstraintInstance *v1; // rdi
  hkpConstraintData *result; // rax
  hkpConstraintData *v3; // rbx
  _QWORD **v4; // rax
  hkpConstraintInstance *v5; // rax
  hkpConstraintInstance *v6; // rax
  hkpConstraintInstance *v7; // rdi

  v1 = originalConstraint;
  result = hkpConstraintDataUtils::createLimited(originalConstraint->m_data);
  v3 = result;
  if ( result )
  {
    v4 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v5 = (hkpConstraintInstance *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v4[11] + 8i64))(v4[11], 112i64);
    if ( v5 )
    {
      hkpConstraintInstance::hkpConstraintInstance(
        v5,
        v1->m_entities[0],
        v1->m_entities[1],
        v3,
        (hkpConstraintInstance::ConstraintPriority)(unsigned __int8)v1->m_priority.m_storage);
      v7 = v6;
      hkReferencedObject::removeReference((hkReferencedObject *)&v3->vfptr);
      result = (hkpConstraintData *)v7;
    }
    else
    {
      hkReferencedObject::removeReference((hkReferencedObject *)&v3->vfptr);
      result = 0i64;
    }
  }
  return result;
}

// File Line: 117
// RVA: 0xE0F960
hkBool *__fastcall hkpConstraintUtils::checkAndFixConstraint(hkBool *result, hkpConstraintInstance *constraint, float maxAllowedError, float relativeFixupOnError)
{
  hkpConstraintInstance *v4; // rsi
  hkBool *v5; // rdi
  hkBool *v6; // rax
  __m128 v7; // xmm4
  __m128 v8; // xmm1
  __m128 *v9; // rbp
  hkpRigidBody *v10; // rsi
  float v11; // xmm3_4
  __m128 v12; // xmm5
  __m128 v13; // xmm2
  __m128 v14; // xmm2
  hkErrStream v15; // [rsp+30h] [rbp-258h]
  hkVector4f pivotInAOut; // [rsp+50h] [rbp-238h]
  hkVector4f pivotInBOut; // [rsp+60h] [rbp-228h]
  char buf; // [rsp+70h] [rbp-218h]
  hkResult resulta; // [rsp+298h] [rbp+10h]
  float v20; // [rsp+2A0h] [rbp+18h]
  float v21; // [rsp+2A8h] [rbp+20h]

  v21 = relativeFixupOnError;
  v20 = maxAllowedError;
  v4 = constraint;
  v5 = result;
  hkpConstraintDataUtils::getConstraintPivots(&resulta, constraint->m_data, &pivotInAOut, &pivotInBOut);
  if ( resulta.m_enum )
  {
    v5->m_bool = 0;
    v6 = v5;
  }
  else
  {
    v7 = pivotInAOut.m_quad;
    v8 = _mm_mul_ps(pivotInAOut.m_quad, pivotInAOut.m_quad);
    if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v8, v8, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v8, v8, 0)))
               + COERCE_FLOAT(_mm_shuffle_ps(v8, v8, 170))) > COERCE_FLOAT(
                                                                _mm_shuffle_ps(
                                                                  (__m128)LODWORD(FLOAT_0_000001),
                                                                  (__m128)LODWORD(FLOAT_0_000001),
                                                                  0)) )
    {
      hkErrStream::hkErrStream(&v15, &buf, 512);
      hkOstream::operator<<(
        (hkOstream *)&v15.vfptr,
        "Pivot of child rigid body (A) is expected to be aligned with the constraint at setup time.");
      hkError::messageWarning(-1413849601, &buf, "Constraint\\Bilateral\\hkpConstraintUtils.cpp", 132);
      hkOstream::~hkOstream((hkOstream *)&v15.vfptr);
      v7 = pivotInAOut.m_quad;
    }
    v9 = (__m128 *)v4->m_entities[1];
    v10 = (hkpRigidBody *)v4->m_entities[0];
    LODWORD(v11) = (unsigned __int128)_mm_shuffle_ps((__m128)LODWORD(v20), (__m128)LODWORD(v20), 0);
    v12 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(pivotInBOut.m_quad, pivotInBOut.m_quad, 85), v9[24]),
                _mm_mul_ps(_mm_shuffle_ps(pivotInBOut.m_quad, pivotInBOut.m_quad, 0), v9[23])),
              _mm_mul_ps(_mm_shuffle_ps(pivotInBOut.m_quad, pivotInBOut.m_quad, 170), v9[25])),
            v9[26]);
    v13 = _mm_sub_ps(
            v12,
            _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_shuffle_ps(v7, v7, 85),
                    v10->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad),
                  _mm_mul_ps(
                    _mm_shuffle_ps(v7, v7, 0),
                    v10->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad)),
                _mm_mul_ps(
                  _mm_shuffle_ps(v7, v7, 170),
                  v10->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad)),
              v10->m_motion.m_motionState.m_transform.m_translation.m_quad));
    v14 = _mm_mul_ps(v13, v13);
    if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v14, v14, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v14, v14, 0)))
               + COERCE_FLOAT(_mm_shuffle_ps(v14, v14, 170))) <= (float)(v11 * v11) )
    {
      v5->m_bool = 0;
    }
    else
    {
      *(__m128 *)&v15.vfptr = _mm_add_ps(
                                _mm_mul_ps(
                                  _mm_shuffle_ps((__m128)LODWORD(v21), (__m128)LODWORD(v21), 0),
                                  _mm_sub_ps(v9[26], v12)),
                                v12);
      hkpRigidBody::setPosition(v10, (hkVector4f *)&v15);
      hkpEntity::activate((hkpEntity *)&v10->vfptr);
      v10->m_motion.vfptr[9].__vecDelDtor((hkBaseObject *)&v10->m_motion.vfptr, (unsigned int)&v9[35]);
      hkpEntity::activate((hkpEntity *)&v10->vfptr);
      ((void (__fastcall *)(hkpMaxSizeMotion *, __m128 *))v10->m_motion.vfptr[9].__first_virtual_table_function__)(
        &v10->m_motion,
        &v9[36]);
      v5->m_bool = 1;
    }
    v6 = v5;
  }
  return v6;
}

// File Line: 174
// RVA: 0xE0FBA0
void __fastcall hkpConstraintUtils::setHingePivotToOptimalPosition(hkpConstraintInstance *constraint)
{
  hkpConstraintData *v1; // rbx
  hkpConstraintInstance *v2; // rdi
  int v3; // eax
  __m128 *v4; // rsi
  __m128 *v5; // rdi
  hkVector4f v6; // xmm1
  hkVector4f v7; // xmm0
  __m128 v8; // xmm1
  __m128 v9; // xmm11
  __m128 v10; // xmm1
  __m128 v11; // xmm2
  hkVector4f v12; // xmm1
  hkVector4f v13; // xmm0
  __m128 v14; // xmm1
  __m128 v15; // xmm12
  __m128 v16; // xmm1
  __m128 v17; // xmm2
  __m128 v18; // xmm9
  __m128 v19; // xmm6
  __m128 v20; // xmm1
  __m128 v21; // xmm7
  __m128 v22; // xmm1
  __m128 v23; // xmm4
  __m128 v24; // xmm1
  __m128 v25; // xmm2
  __m128 v26; // xmm0
  __m128 v27; // xmm1
  __m128 v28; // xmm3
  __m128 v29; // xmm0
  hkMatrix3f v30; // [rsp+20h] [rbp-C8h]
  hkMatrix3f v31; // [rsp+50h] [rbp-98h]

  v1 = constraint->m_data;
  v2 = constraint;
  v3 = (unsigned __int64)((__int64 (__fastcall *)(hkpConstraintData *))v1->vfptr[1].__first_virtual_table_function__)(constraint->m_data)
     - 1;
  if ( !v3 || v3 == 1 )
  {
    v4 = (__m128 *)v2->m_entities[0];
    v5 = (__m128 *)v2->m_entities[1];
    (*(void (__fastcall **)(__m128 *, hkMatrix3f *))(v4[21].m128_u64[0] + 88))(v4 + 21, &v31);
    v6.m_quad = *(__m128 *)&v1[2].m_userData;
    v30.m_col0 = *(hkVector4f *)&v1[2].vfptr;
    v7.m_quad = *(__m128 *)&v1[3].m_memSizeAndFlags;
    v30.m_col1 = (hkVector4f)v6.m_quad;
    v30.m_col2 = (hkVector4f)v7.m_quad;
    hkMatrix3f::transpose(&v30);
    hkMatrix3f::changeBasis(&v31, (hkRotationf *)&v30);
    v8 = (__m128)_mm_slli_si128(_mm_srli_si128((__m128i)_mm_add_ps(v31.m_col2.m_quad, v31.m_col1.m_quad), 4), 4);
    v9 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)), _mm_shuffle_ps(v8, v8, 170));
    v10 = _mm_shuffle_ps(v4[34], v4[34], 255);
    if ( v10.m128_f32[0] > 0.00000011920929 )
    {
      v11 = _mm_rcp_ps(v10);
      v9 = _mm_mul_ps(v9, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v11, v10)), v11));
    }
    (*(void (__fastcall **)(__m128 *, hkMatrix3f *))(v5[21].m128_u64[0] + 88))(v5 + 21, &v31);
    v12.m_quad = *(__m128 *)&v1[5].m_memSizeAndFlags;
    v30.m_col0 = *(hkVector4f *)&v1[4].m_userData;
    v13.m_quad = *(__m128 *)&v1[6].vfptr;
    v30.m_col1 = (hkVector4f)v12.m_quad;
    v30.m_col2 = (hkVector4f)v13.m_quad;
    hkMatrix3f::transpose(&v30);
    hkMatrix3f::changeBasis(&v31, (hkRotationf *)&v30);
    v14 = (__m128)_mm_slli_si128(_mm_srli_si128((__m128i)_mm_add_ps(v31.m_col2.m_quad, v31.m_col1.m_quad), 4), 4);
    v15 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)),
            _mm_shuffle_ps(v14, v14, 170));
    v16 = _mm_shuffle_ps(v5[34], v5[34], 255);
    if ( v16.m128_f32[0] > 0.00000011920929 )
    {
      v17 = _mm_rcp_ps(v16);
      v15 = _mm_mul_ps(v15, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v17, v16)), v17));
    }
    v18 = _mm_sub_ps(*(__m128 *)&v1[4].vfptr, v4[31]);
    v19 = _mm_sub_ps(*(__m128 *)&v1[6].m_userData, v5[31]);
    v20 = _mm_mul_ps(*(__m128 *)&v1[2].vfptr, v18);
    v21 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)),
            _mm_shuffle_ps(v20, v20, 170));
    v22 = _mm_mul_ps(*(__m128 *)&v1[4].m_userData, v19);
    v23 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)),
            _mm_shuffle_ps(v22, v22, 170));
    v24 = _mm_add_ps(v9, v15);
    v25 = _mm_rcp_ps(v24);
    v26 = _mm_mul_ps(v25, v24);
    v27 = _mm_sub_ps(v21, v23);
    v28 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, v26), v25);
    v29 = _mm_mul_ps(
            _mm_sub_ps(_mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)0i64, v27), v9), v28), v23),
            *(__m128 *)&v1[4].m_userData);
    *(__m128 *)&v1[4].vfptr = _mm_add_ps(
                                _mm_add_ps(
                                  _mm_mul_ps(
                                    _mm_sub_ps(_mm_mul_ps(_mm_mul_ps(v27, v15), v28), v21),
                                    *(__m128 *)&v1[2].vfptr),
                                  v18),
                                v4[31]);
    *(__m128 *)&v1[6].m_userData = _mm_add_ps(_mm_add_ps(v19, v29), v5[31]);
  }
}

// File Line: 268
// RVA: 0xE0FE70
void __fastcall hkpConstraintUtils::collectConstraints(hkArray<hkpEntity *,hkContainerHeapAllocator> *entities, hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *constraintsOut, hkpConstraintUtils::CollectConstraintsFilter *collectionFilter)
{
  int v3; // er12
  hkpConstraintUtils::CollectConstraintsFilter *v4; // r14
  hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *v5; // rdi
  hkArray<hkpEntity *,hkContainerHeapAllocator> *v6; // rax
  __int64 v7; // r13
  hkpEntity *v8; // r15
  int v9; // ebx
  int v10; // ebp
  hkpConstraintInstance *v11; // rax
  unsigned __int64 v12; // rsi
  int v13; // eax
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v14; // [rsp+20h] [rbp-48h]
  hkArray<hkpEntity *,hkContainerHeapAllocator> *v15; // [rsp+70h] [rbp+8h]
  char v16; // [rsp+88h] [rbp+20h]

  v15 = entities;
  v14.m_elem = 0i64;
  v3 = 0;
  v4 = collectionFilter;
  v5 = constraintsOut;
  v6 = entities;
  v14.m_numElems = 0;
  v14.m_hashMod = -1;
  if ( entities->m_size > 0 )
  {
    v7 = 0i64;
    do
    {
      v8 = v6->m_data[v7];
      v9 = 0;
      v10 = hkpEntity::getNumConstraints(v8);
      if ( v10 > 0 )
      {
        do
        {
          v11 = hkpEntity::getConstraint(v8, v9);
          v12 = (unsigned __int64)v11;
          if ( !v4 || *(_BYTE *)v4->vfptr->collectConstraint(v4, (hkBool *)&v16, v11) )
          {
            v13 = (unsigned __int64)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                                      &v14,
                                      v12);
            if ( v13 > v14.m_hashMod )
            {
              hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
                &v14,
                (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
                v12,
                1ui64);
              if ( v5->m_size == (v5->m_capacityAndFlags & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v5, 8);
              v5->m_data[v5->m_size++] = (hkpConstraintInstance *)v12;
            }
          }
          ++v9;
        }
        while ( v9 < v10 );
      }
      v6 = v15;
      ++v3;
      ++v7;
    }
    while ( v3 < v15->m_size );
  }
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &v14,
    (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&v14);
}

// File Line: 291
// RVA: 0xE0FFE0
hkpConstraintInstance *__fastcall hkpConstraintUtils::createMatchingHingeConstraintFromCogWheelConstraint(hkpConstraintInstance *constraint, int bodyIndex, hkpRigidBody *anotherBody, bool createLimitedHinge)
{
  hkpConstraintData *v4; // rax
  hkpRigidBody *v5; // r14
  hkpEntity *v6; // rsi
  signed __int64 v7; // rbp
  _QWORD **v8; // rax
  hkpHingeConstraintData *v9; // rax
  __int64 v10; // rdi
  hkpLimitedHingeConstraintData *v11; // rax
  hkpLimitedHingeConstraintData *v12; // rbx
  __m128 v13; // xmm1
  __m128 v14; // xmm2
  __m128 v15; // xmm1
  __m128 v16; // xmm0
  _QWORD **v17; // rax
  hkpLimitedHingeConstraintData *v18; // rax
  hkpLimitedHingeConstraintData *v19; // rax
  __m128 v20; // xmm1
  __m128 v21; // xmm2
  __m128 v22; // xmm1
  __m128 v23; // xmm0
  _QWORD **v24; // rax
  hkpConstraintInstance *v25; // rax
  __int64 v26; // rax
  hkVector4f axis; // [rsp+30h] [rbp-48h]
  hkVector4f pivot; // [rsp+40h] [rbp-38h]
  hkVector4f axisIn; // [rsp+50h] [rbp-28h]
  hkVector4f v31; // [rsp+60h] [rbp-18h]

  v4 = constraint->m_data;
  v5 = anotherBody;
  if ( bodyIndex )
    v6 = constraint->m_entities[0];
  else
    v6 = constraint->m_entities[1];
  v7 = (signed __int64)&v4[4].m_userData;
  if ( !bodyIndex )
    v7 = (signed __int64)&v4[2];
  if ( createLimitedHinge )
  {
    v17 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v18 = (hkpLimitedHingeConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v17[11] + 8i64))(
                                             v17[11],
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
    v20 = *(__m128 *)(v7 + 48);
    v21 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v20, v20, 0), v6->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad),
              _mm_mul_ps(
                _mm_shuffle_ps(*(__m128 *)(v7 + 48), v20, 85),
                v6->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v20, v20, 170), v6->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad));
    v22 = *(__m128 *)v7;
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
      &v5->m_motion.m_motionState.m_transform,
      &v31,
      &axisIn);
  }
  else
  {
    v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v9 = (hkpHingeConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v8[11] + 8i64))(
                                     v8[11],
                                     224i64);
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
    v13 = *(__m128 *)(v7 + 48);
    v14 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v13, v13, 0), v6->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad),
              _mm_mul_ps(
                _mm_shuffle_ps(*(__m128 *)(v7 + 48), v13, 85),
                v6->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v13, v13, 170), v6->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad));
    v15 = *(__m128 *)v7;
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
      &v5->m_motion.m_motionState.m_transform,
      &pivot,
      &axis);
  }
  v24 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v25 = (hkpConstraintInstance *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v24[11] + 8i64))(
                                   v24[11],
                                   112i64);
  if ( v25 )
  {
    hkpConstraintInstance::hkpConstraintInstance(
      v25,
      v6,
      (hkpEntity *)&v5->vfptr,
      (hkpConstraintData *)&v12->vfptr,
      PRIORITY_PSI);
    v10 = v26;
  }
  hkReferencedObject::removeReference((hkReferencedObject *)&v12->vfptr);
  return (hkpConstraintInstance *)v10;
}

// File Line: 327
// RVA: 0xE10200
hkpConstraintInstance *__fastcall hkpConstraintUtils::createMatchingPrismaticConstraintFromRackAndPinionConstraint(hkpConstraintInstance *constraint, hkpRigidBody *anotherBody)
{
  hkpEntity *v2; // r14
  hkpRigidBody *v3; // rbp
  __m128 *v4; // rdx
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
  _QWORD **v16; // rax
  hkpPrismaticConstraintData *v17; // rax
  __int64 v18; // rdi
  hkpPrismaticConstraintData *v19; // rax
  hkpPrismaticConstraintData *v20; // rbx
  _QWORD **v21; // rax
  hkpConstraintInstance *v22; // rax
  __int64 v23; // rax
  hkVector4f pivot; // [rsp+30h] [rbp-28h]
  hkVector4f axis; // [rsp+40h] [rbp-18h]

  v2 = constraint->m_entities[1];
  v3 = anotherBody;
  v4 = (__m128 *)constraint->m_data;
  v5 = v4[10];
  v6 = _mm_add_ps(
         _mm_add_ps(
           _mm_add_ps(
             _mm_mul_ps(_mm_shuffle_ps(v5, v5, 85), v2->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad),
             _mm_mul_ps(_mm_shuffle_ps(v4[10], v5, 0), v2->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad)),
           _mm_mul_ps(_mm_shuffle_ps(v5, v5, 170), v2->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad)),
         v2->m_motion.m_motionState.m_transform.m_translation.m_quad);
  pivot.m_quad = v6;
  v7 = v4[7];
  v8 = _mm_add_ps(
         _mm_add_ps(
           _mm_mul_ps(_mm_shuffle_ps(v7, v7, 0), v2->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad),
           _mm_mul_ps(_mm_shuffle_ps(v4[7], v7, 85), v2->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad)),
         _mm_mul_ps(_mm_shuffle_ps(v7, v7, 170), v2->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad));
  axis.m_quad = v8;
  if ( !v4[11].m128_i8[8] )
  {
    v9 = v4[3];
    v10 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(
                _mm_shuffle_ps(v9, v9, 85),
                constraint->m_entities[0]->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad),
              _mm_mul_ps(
                _mm_shuffle_ps(v4[3], v9, 0),
                constraint->m_entities[0]->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad)),
            _mm_mul_ps(
              _mm_shuffle_ps(v9, v9, 170),
              constraint->m_entities[0]->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad));
    v11 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), v8), _mm_mul_ps(_mm_shuffle_ps(v8, v8, 201), v10));
    v12 = _mm_shuffle_ps(v11, v11, 201);
    v13 = _mm_mul_ps(v12, v12);
    if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v13, v13, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v13, v13, 0)))
               + COERCE_FLOAT(_mm_shuffle_ps(v13, v13, 170))) >= 1.4210855e-14 )
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
                             _mm_cmpleps(v14, (__m128)0i64),
                             _mm_mul_ps(
                               _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v15, v14), v15)),
                               _mm_mul_ps(*(__m128 *)_xmm, v15))),
                           v12),
                         _mm_shuffle_ps((__m128)v4[11].m128_u32[1], (__m128)v4[11].m128_u32[1], 0)));
    }
  }
  v16 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v17 = (hkpPrismaticConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v16[11] + 8i64))(
                                        v16[11],
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
    &v3->m_motion.m_motionState.m_transform,
    &pivot,
    &axis);
  v21 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v22 = (hkpConstraintInstance *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v21[11] + 8i64))(
                                   v21[11],
                                   112i64);
  if ( v22 )
  {
    hkpConstraintInstance::hkpConstraintInstance(
      v22,
      v2,
      (hkpEntity *)&v3->vfptr,
      (hkpConstraintData *)&v20->vfptr,
      PRIORITY_PSI);
    v18 = v23;
  }
  hkReferencedObject::removeReference((hkReferencedObject *)&v20->vfptr);
  return (hkpConstraintInstance *)v18;
}

// File Line: 370
// RVA: 0xE10430
hkpConstraintInstance *__fastcall hkpConstraintUtils::createMatchingHingeConstraintFromRackAndPinionConstraint(hkpConstraintInstance *constraint, hkpRigidBody *anotherBody, bool createLimitedHinge)
{
  hkpConstraintData *v3; // r14
  hkpEntity *v4; // rbp
  hkpRigidBody *v5; // rsi
  _QWORD **v6; // rax
  hkpHingeConstraintData *v7; // rax
  __int64 v8; // rdi
  hkpLimitedHingeConstraintData *v9; // rax
  hkpLimitedHingeConstraintData *v10; // rbx
  __m128 v11; // xmm1
  __m128 v12; // xmm2
  __m128 v13; // xmm1
  __m128 v14; // xmm0
  _QWORD **v15; // rax
  hkpLimitedHingeConstraintData *v16; // rax
  hkpLimitedHingeConstraintData *v17; // rax
  __m128 v18; // xmm1
  __m128 v19; // xmm2
  __m128 v20; // xmm1
  __m128 v21; // xmm0
  _QWORD **v22; // rax
  hkpConstraintInstance *v23; // rax
  __int64 v24; // rax
  hkVector4f axis; // [rsp+30h] [rbp-48h]
  hkVector4f pivot; // [rsp+40h] [rbp-38h]
  hkVector4f axisIn; // [rsp+50h] [rbp-28h]
  hkVector4f v29; // [rsp+60h] [rbp-18h]

  v3 = constraint->m_data;
  v4 = constraint->m_entities[0];
  v5 = anotherBody;
  if ( createLimitedHinge )
  {
    v15 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v16 = (hkpLimitedHingeConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v15[11] + 8i64))(
                                             v15[11],
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
    v18 = *(__m128 *)&v3[4].vfptr;
    v19 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v18, v18, 0), v4->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad),
              _mm_mul_ps(
                _mm_shuffle_ps(*(__m128 *)&v3[4].vfptr, v18, 85),
                v4->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v18, v18, 170), v4->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad));
    v20 = *(__m128 *)&v3[2].vfptr;
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
      &v5->m_motion.m_motionState.m_transform,
      &v29,
      &axisIn);
  }
  else
  {
    v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v7 = (hkpHingeConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v6[11] + 8i64))(
                                     v6[11],
                                     224i64);
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
    v11 = *(__m128 *)&v3[4].vfptr;
    v12 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v11, v11, 0), v4->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad),
              _mm_mul_ps(
                _mm_shuffle_ps(*(__m128 *)&v3[4].vfptr, v11, 85),
                v4->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v11, v11, 170), v4->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad));
    v13 = *(__m128 *)&v3[2].vfptr;
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
      &v5->m_motion.m_motionState.m_transform,
      &pivot,
      &axis);
  }
  v22 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v23 = (hkpConstraintInstance *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v22[11] + 8i64))(
                                   v22[11],
                                   112i64);
  if ( v23 )
  {
    hkpConstraintInstance::hkpConstraintInstance(
      v23,
      v4,
      (hkpEntity *)&v5->vfptr,
      (hkpConstraintData *)&v10->vfptr,
      PRIORITY_PSI);
    v8 = v24;
  }
  hkReferencedObject::removeReference((hkReferencedObject *)&v10->vfptr);
  return (hkpConstraintInstance *)v8;
}

