// File Line: 43
// RVA: 0xE233D0
void __fastcall hkpConstraintChainUtil::addConstraintToBallSocketChain(
        hkpConstraintChainInstance *instance,
        hkpEntity *entityToAppend,
        hkVector4f *pivotWs)
{
  __int64 m_size; // r9
  __m128 *v4; // rax
  __m128 *v8; // r8
  __m128 v9; // xmm3
  __m128 v10; // xmm0
  hkpBallSocketChainData *m_data; // rcx
  __m128 m_quad; // xmm6
  __m128 v13; // xmm1
  __m128 v14; // xmm4
  __m128 v15; // xmm1
  __m128 v16; // xmm2
  __m128 v17; // xmm5
  __m128 v18; // xmm6
  __m128 v19; // xmm0
  __m128 v20; // xmm3
  __m128 v21; // xmm1
  __m128 v22; // xmm4
  __m128 v23; // xmm1
  __m128 v24; // xmm2
  hkVector4f pivotInA; // [rsp+20h] [rbp-38h] BYREF
  hkVector4f pivotInB; // [rsp+30h] [rbp-28h] BYREF

  m_size = instance->m_chainedEntities.m_size;
  v4 = 0i64;
  if ( instance->m_chainedEntities.m_data[m_size - 1]->m_collidable.m_broadPhaseHandle.m_type == 1 )
    v8 = (__m128 *)((char *)&instance->m_chainedEntities.m_data[m_size - 1]->m_collidable
                  + instance->m_chainedEntities.m_data[m_size - 1]->m_collidable.m_ownerOffset);
  else
    v8 = 0i64;
  if ( entityToAppend->m_collidable.m_broadPhaseHandle.m_type == 1 )
    v4 = (__m128 *)((char *)&entityToAppend->m_collidable + entityToAppend->m_collidable.m_ownerOffset);
  v9 = v8[25];
  v10 = v8[24];
  m_data = (hkpBallSocketChainData *)instance->m_data;
  m_quad = pivotWs->m_quad;
  v13 = v8[23];
  v14 = _mm_unpackhi_ps(v13, v10);
  v15 = _mm_unpacklo_ps(v13, v10);
  v16 = _mm_movelh_ps(v15, v9);
  v17 = _mm_sub_ps(pivotWs->m_quad, v8[26]);
  pivotInA.m_quad = _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(_mm_movehl_ps(v16, v15), v9, 212)),
                        _mm_mul_ps(_mm_shuffle_ps(v17, v17, 0), v16)),
                      _mm_mul_ps(_mm_shuffle_ps(v14, v9, 228), _mm_shuffle_ps(v17, v17, 170)));
  v18 = _mm_sub_ps(m_quad, v4[26]);
  v19 = v4[24];
  v20 = v4[25];
  v21 = v4[23];
  v22 = _mm_unpackhi_ps(v21, v19);
  v23 = _mm_unpacklo_ps(v21, v19);
  v24 = _mm_movelh_ps(v23, v20);
  pivotInB.m_quad = _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(_mm_movehl_ps(v24, v23), v20, 212)),
                        _mm_mul_ps(_mm_shuffle_ps(v18, v18, 0), v24)),
                      _mm_mul_ps(_mm_shuffle_ps(v22, v20, 228), _mm_shuffle_ps(v18, v18, 170)));
  hkpBallSocketChainData::addConstraintInfoInBodySpace(m_data, &pivotInA, &pivotInB);
  hkpConstraintChainInstance::addEntity(instance, entityToAppend);
}

// File Line: 63
// RVA: 0xE23520
void __fastcall hkpConstraintChainUtil::addConstraintToPoweredChain(
        hkpConstraintChainInstance *instance,
        hkpEntity *entityToAppend,
        hkVector4f *pivotWs,
        hkpConstraintMotor *motor0,
        hkpConstraintMotor *motor1,
        hkpConstraintMotor *motor2)
{
  __int64 m_size; // r10
  __m128 *v7; // rax
  __m128 *v11; // r8
  __m128 v12; // xmm3
  __m128 v13; // xmm0
  __m128 m_quad; // xmm6
  __m128 v15; // xmm1
  __m128 v16; // xmm4
  __m128 v17; // xmm1
  __m128 v18; // xmm2
  __m128 v19; // xmm5
  __m128 v20; // xmm6
  __m128 v21; // xmm3
  __m128 v22; // xmm0
  __m128 v23; // xmm1
  __m128 v24; // xmm4
  __m128 v25; // xmm1
  __m128 v26; // xmm2
  __m128 v27; // xmm2
  __m128 v28; // xmm3
  __m128 v29; // xmm1
  __m128 v30; // xmm4
  __m128 v31; // xmm0
  __m128 v32; // xmm3
  __m128 v33; // xmm4
  __m128 v34; // xmm0
  hkpPoweredChainData *m_data; // rcx
  hkVector4f pivotInA; // [rsp+40h] [rbp-78h] BYREF
  hkVector4f pivotInB; // [rsp+50h] [rbp-68h] BYREF
  hkQuaternionf aTc; // [rsp+60h] [rbp-58h] BYREF
  hkpConstraintMotor *v39; // [rsp+80h] [rbp-38h]
  hkpConstraintMotor *v40; // [rsp+88h] [rbp-30h]
  hkpConstraintMotor *v41; // [rsp+90h] [rbp-28h]

  m_size = instance->m_chainedEntities.m_size;
  v7 = 0i64;
  if ( instance->m_chainedEntities.m_data[m_size - 1]->m_collidable.m_broadPhaseHandle.m_type == 1 )
    v11 = (__m128 *)((char *)&instance->m_chainedEntities.m_data[m_size - 1]->m_collidable
                   + instance->m_chainedEntities.m_data[m_size - 1]->m_collidable.m_ownerOffset);
  else
    v11 = 0i64;
  if ( entityToAppend->m_collidable.m_broadPhaseHandle.m_type == 1 )
    v7 = (__m128 *)((char *)&entityToAppend->m_collidable + entityToAppend->m_collidable.m_ownerOffset);
  v12 = v11[25];
  v13 = v11[24];
  m_quad = pivotWs->m_quad;
  v15 = v11[23];
  v16 = _mm_unpackhi_ps(v15, v13);
  v17 = _mm_unpacklo_ps(v15, v13);
  v18 = _mm_movelh_ps(v17, v12);
  v19 = _mm_sub_ps(pivotWs->m_quad, v11[26]);
  pivotInA.m_quad = _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(_mm_movehl_ps(v18, v17), v12, 212)),
                        _mm_mul_ps(_mm_shuffle_ps(v19, v19, 0), v18)),
                      _mm_mul_ps(_mm_shuffle_ps(v16, v12, 228), _mm_shuffle_ps(v19, v19, 170)));
  v20 = _mm_sub_ps(m_quad, v7[26]);
  v21 = v7[25];
  v22 = v7[24];
  v23 = v7[23];
  v24 = _mm_unpackhi_ps(v23, v22);
  v25 = _mm_unpacklo_ps(v23, v22);
  v26 = _mm_movelh_ps(v25, v21);
  pivotInB.m_quad = _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(_mm_movehl_ps(v26, v25), v21, 212)),
                        _mm_mul_ps(_mm_shuffle_ps(v20, v20, 0), v26)),
                      _mm_mul_ps(_mm_shuffle_ps(v20, v20, 170), _mm_shuffle_ps(v24, v21, 228)));
  v27 = v7[30];
  v28 = v11[30];
  v39 = motor0;
  v29 = _mm_mul_ps(_mm_shuffle_ps(v28, v28, 255), v27);
  v30 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v27, v27, 201), v28), _mm_mul_ps(_mm_shuffle_ps(v28, v28, 201), v27));
  v31 = _mm_mul_ps(_mm_shuffle_ps(v27, v27, 255), v28);
  v32 = _mm_mul_ps(v28, v27);
  v33 = _mm_add_ps(_mm_sub_ps(_mm_shuffle_ps(v30, v30, 201), v31), v29);
  v34 = _mm_add_ps(_mm_shuffle_ps(v32, v32, 78), v32);
  aTc.m_vec.m_quad = _mm_shuffle_ps(v33, _mm_unpackhi_ps(v33, _mm_add_ps(_mm_shuffle_ps(v34, v34, 177), v34)), 196);
  m_data = (hkpPoweredChainData *)instance->m_data;
  v40 = motor1;
  v41 = motor2;
  hkpPoweredChainData::addConstraintInfoInBodySpace(m_data, &pivotInA, &pivotInB, &aTc, motor0, motor1, motor2);
  hkpConstraintChainInstance::addEntity(instance, entityToAppend);
}

// File Line: 92
// RVA: 0xE23730
hkResult *__fastcall hkpConstraintChainUtil::addConstraintToChain(
        hkResult *result,
        hkpConstraintInstance *newChildInstance,
        hkpConstraintChainInstance *chainInstance,
        hkpBallSocketChainData *chainData)
{
  hkpEntity **m_data; // r8
  hkpEntity *v9; // r9
  hkpEntity *v10; // rdx
  hkpEntity *v11; // rcx
  hkVector4f pivotInAOut; // [rsp+20h] [rbp-48h] BYREF
  hkVector4f pivotInBOut; // [rsp+30h] [rbp-38h] BYREF
  hkpBallSocketChainData::ConstraintInfo t; // [rsp+40h] [rbp-28h] BYREF
  hkResult resulta; // [rsp+78h] [rbp+10h] BYREF

  if ( hkpConstraintDataUtils::getConstraintPivots(&resulta, newChildInstance->m_data, &pivotInAOut, &pivotInBOut)->m_enum )
    goto LABEL_12;
  if ( !chainInstance->m_chainedEntities.m_size )
    hkpConstraintChainInstance::addEntity(chainInstance, newChildInstance->m_entities[0]);
  m_data = chainInstance->m_chainedEntities.m_data;
  v9 = newChildInstance->m_entities[0];
  v10 = m_data[chainInstance->m_chainedEntities.m_size - 1];
  if ( v10 != v9 )
  {
    v11 = newChildInstance->m_entities[1];
    if ( v10 == v11 )
    {
      hkpBallSocketChainData::addConstraintInfoInBodySpace(chainData, &pivotInBOut, &pivotInAOut);
      hkpConstraintChainInstance::addEntity(chainInstance, newChildInstance->m_entities[0]);
      result->m_enum = HK_SUCCESS;
      return result;
    }
    if ( *m_data == v9 )
    {
      t.m_pivotInA = (hkVector4f)pivotInBOut.m_quad;
      t.m_pivotInB = (hkVector4f)pivotInAOut.m_quad;
      hkArrayBase<hkpBallSocketChainData::ConstraintInfo>::_insertAt(
        &chainData->m_infos,
        &hkContainerHeapAllocator::s_alloc,
        0,
        &t);
      hkpConstraintChainInstance::insertEntityAtFront(chainInstance, newChildInstance->m_entities[1]);
      result->m_enum = HK_SUCCESS;
      return result;
    }
    if ( *m_data == v11 )
    {
      t.m_pivotInA = (hkVector4f)pivotInAOut.m_quad;
      t.m_pivotInB = (hkVector4f)pivotInBOut.m_quad;
      hkArrayBase<hkpBallSocketChainData::ConstraintInfo>::_insertAt(
        &chainData->m_infos,
        &hkContainerHeapAllocator::s_alloc,
        0,
        &t);
      hkpConstraintChainInstance::insertEntityAtFront(chainInstance, newChildInstance->m_entities[0]);
      result->m_enum = HK_SUCCESS;
      return result;
    }
LABEL_12:
    result->m_enum = HK_FAILURE;
    return result;
  }
  hkpBallSocketChainData::addConstraintInfoInBodySpace(chainData, &pivotInAOut, &pivotInBOut);
  hkpConstraintChainInstance::addEntity(chainInstance, newChildInstance->m_entities[1]);
  result->m_enum = HK_SUCCESS;
  return result;
}

// File Line: 162
// RVA: 0xE22DA0
hkpConstraintChainInstance *__fastcall hkpConstraintChainUtil::buildPoweredChain(
        hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *constraints,
        hkBool cloneMotors)
{
  _QWORD **Value; // rax
  hkpPoweredChainData *v4; // rax
  int v5; // r15d
  hkpPoweredChainData *v6; // rax
  hkpPoweredChainData *v7; // r14
  _QWORD **v8; // rax
  hkpConstraintChainInstance *v9; // rax
  hkpConstraintChainInstance *v10; // rax
  hkpConstraintChainInstance *v11; // rbx
  hkpConstraintInstance *v12; // rcx
  hkpEntity *v13; // rdx
  __int64 v14; // r8
  __int64 v15; // rdi
  __int64 v16; // r8
  hkpConstraintInstance **m_data; // rcx
  hkpConstraintInstance *v18; // rdx
  __m128 m_quad; // xmm1
  __m128 v20; // xmm2
  __m128 v21; // xmm4
  __m128 v22; // xmm3
  __m128 v23; // xmm1
  __m128 v24; // xmm0
  __m128 v25; // xmm4
  __m128 v26; // xmm3
  __m128 v27; // xmm0
  hkBaseObjectVtbl *vfptr; // rcx
  hkBaseObjectVtbl *yMotor; // rdx
  hkStreamWriter *zMotor; // rax
  hkpConstraintInstance *v31; // rdx
  hkpEntity *v32; // rdx
  hkErrStream *p_motor0; // rcx
  int v35; // r9d
  unsigned int v36; // ecx
  hkOstream motor0; // [rsp+40h] [rbp-C0h] BYREF
  hkVector4f pivotInAOut; // [rsp+60h] [rbp-A0h] BYREF
  hkVector4f pivotInBOut; // [rsp+70h] [rbp-90h] BYREF
  hkErrStream v40; // [rsp+80h] [rbp-80h] BYREF
  hkQuaternionf aTc; // [rsp+A0h] [rbp-60h] BYREF
  char buf[544]; // [rsp+B0h] [rbp-50h] BYREF
  hkResult result; // [rsp+2E0h] [rbp+1E0h] BYREF
  char m_bool; // [rsp+2E8h] [rbp+1E8h]
  hkResult v45; // [rsp+2F0h] [rbp+1F0h] BYREF

  m_bool = cloneMotors.m_bool;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v4 = (hkpPoweredChainData *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 112i64);
  v5 = 0;
  if ( v4 )
  {
    hkpPoweredChainData::hkpPoweredChainData(v4);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = (hkpConstraintChainInstance *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v8[11] + 8i64))(v8[11], 144i64);
  if ( v9 )
  {
    hkpConstraintChainInstance::hkpConstraintChainInstance(v9, v7);
    v11 = v10;
  }
  else
  {
    v11 = 0i64;
  }
  v12 = *constraints->m_data;
  v13 = v12->m_entities[0];
  if ( constraints->m_size > 1 )
  {
    v14 = *((_QWORD *)constraints->m_data + 1);
    if ( v13 == *(hkpEntity **)(v14 + 40) || v13 == *(hkpEntity **)(v14 + 48) )
      v13 = v12->m_entities[1];
  }
  hkpConstraintChainInstance::addEntity(v11, v13);
  if ( constraints->m_size <= 0 )
  {
LABEL_29:
    hkReferencedObject::removeReference(v7);
    return v11;
  }
  else
  {
    v15 = 0i64;
    while ( hkpConstraintDataUtils::getConstraintPivots(
              &result,
              constraints->m_data[v15]->m_data,
              &pivotInAOut,
              &pivotInBOut)->m_enum != HK_FAILURE )
    {
      v16 = (__int64)&v11->m_chainedEntities.m_data[v11->m_chainedEntities.m_size];
      m_data = constraints->m_data;
      v18 = constraints->m_data[v15];
      if ( v18->m_entities[0] != *(hkpEntity **)(v16 - 8) )
      {
        m_quad = pivotInAOut.m_quad;
        pivotInAOut.m_quad = pivotInBOut.m_quad;
        pivotInBOut.m_quad = m_quad;
        v18 = m_data[v15];
        if ( v18->m_entities[1] != *(hkpEntity **)(v16 - 8) )
        {
          hkErrStream::hkErrStream((hkErrStream *)&motor0, buf, 512);
          hkOstream::operator<<(
            &motor0,
            "Constraints are not ordered properly ! Two consecutive constraint share no common hkpEntity.");
          hkError::messageWarning(0xABBAD88D, buf, "Constraint\\Chain\\hkpConstraintChainUtil.cpp", 192);
          p_motor0 = (hkErrStream *)&motor0;
          goto LABEL_34;
        }
      }
      v20 = v18->m_entities[0]->m_motion.m_motionState.m_sweptTransform.m_rotation1.m_vec.m_quad;
      v21 = v18->m_entities[1]->m_motion.m_motionState.m_sweptTransform.m_rotation1.m_vec.m_quad;
      v22 = _mm_mul_ps(_mm_shuffle_ps(v20, v20, 255), v21);
      v23 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v20, v20, 201), v21), _mm_mul_ps(_mm_shuffle_ps(v21, v21, 201), v20));
      v24 = _mm_shuffle_ps(v21, v21, 255);
      v25 = _mm_mul_ps(v21, v20);
      v26 = _mm_sub_ps(_mm_add_ps(v22, _mm_shuffle_ps(v23, v23, 201)), _mm_mul_ps(v24, v20));
      v27 = _mm_add_ps(_mm_shuffle_ps(v25, v25, 78), v25);
      aTc.m_vec.m_quad = _mm_shuffle_ps(v26, _mm_unpackhi_ps(v26, _mm_add_ps(_mm_shuffle_ps(v27, v27, 177), v27)), 196);
      hkpConstraintDataUtils::getConstraintMotors(
        &v45,
        (hkpRagdollConstraintData *)v18->m_data,
        (hkpConstraintMotor **)&motor0,
        (hkpConstraintMotor **)&motor0.m_memSizeAndFlags,
        (hkpConstraintMotor **)&motor0.m_writer);
      vfptr = motor0.vfptr;
      if ( !motor0.vfptr )
      {
        hkErrStream::hkErrStream(&v40, buf, 512);
        hkOstream::operator<<(&v40, "No motors extracted from the original constraint.");
        v35 = 205;
        v36 = -1413838637;
        goto LABEL_33;
      }
      yMotor = *(hkBaseObjectVtbl **)&motor0.m_memSizeAndFlags;
      zMotor = motor0.m_writer.m_pntr;
      if ( !*(_QWORD *)&motor0.m_memSizeAndFlags )
        yMotor = motor0.vfptr;
      if ( !motor0.m_writer.m_pntr )
        zMotor = (hkStreamWriter *)motor0.vfptr;
      *(_QWORD *)&motor0.m_memSizeAndFlags = yMotor;
      motor0.m_writer.m_pntr = zMotor;
      if ( m_bool )
      {
        motor0.vfptr = (hkBaseObjectVtbl *)(*((__int64 (**)(void))motor0.vfptr->__vecDelDtor + 3))();
        *(_QWORD *)&motor0.m_memSizeAndFlags = (*(__int64 (__fastcall **)(_QWORD))(**(_QWORD **)&motor0.m_memSizeAndFlags
                                                                                 + 24i64))(*(_QWORD *)&motor0.m_memSizeAndFlags);
        zMotor = (hkStreamWriter *)((__int64 (__fastcall *)(hkStreamWriter *))motor0.m_writer.m_pntr->vfptr[1].__first_virtual_table_function__)(motor0.m_writer.m_pntr);
        yMotor = *(hkBaseObjectVtbl **)&motor0.m_memSizeAndFlags;
        vfptr = motor0.vfptr;
        motor0.m_writer.m_pntr = zMotor;
      }
      hkpPoweredChainData::addConstraintInfoInBodySpace(
        v7,
        &pivotInAOut,
        &pivotInBOut,
        &aTc,
        (hkpConstraintMotor *)vfptr,
        (hkpConstraintMotor *)yMotor,
        (hkpConstraintMotor *)zMotor);
      if ( m_bool )
      {
        hkReferencedObject::removeReference((hkReferencedObject *)motor0.vfptr);
        hkReferencedObject::removeReference(*(hkReferencedObject **)&motor0.m_memSizeAndFlags);
        hkReferencedObject::removeReference(motor0.m_writer.m_pntr);
      }
      v31 = constraints->m_data[v15];
      if ( v31->m_entities[0] == v11->m_chainedEntities.m_data[v11->m_chainedEntities.m_size - 1] )
      {
        v32 = v31->m_entities[1];
      }
      else
      {
        v7->m_infos.m_data[v7->m_infos.m_size - 1].m_switchBodies.m_bool = 1;
        v32 = constraints->m_data[v15]->m_entities[0];
      }
      hkpConstraintChainInstance::addEntity(v11, v32);
      ++v5;
      ++v15;
      if ( v5 >= constraints->m_size )
        goto LABEL_29;
    }
    hkErrStream::hkErrStream(&v40, buf, 512);
    hkOstream::operator<<(&v40, "Not supported types of constraints used to build a chain!");
    v35 = 181;
    v36 = -1413818227;
LABEL_33:
    hkError::messageWarning(v36, buf, "Constraint\\Chain\\hkpConstraintChainUtil.cpp", v35);
    p_motor0 = &v40;
LABEL_34:
    hkOstream::~hkOstream(p_motor0);
    hkReferencedObject::removeReference(v7);
    hkReferencedObject::removeReference(v11);
    return 0i64;
  }
}

// File Line: 252
// RVA: 0xE23190
hkpConstraintChainInstance *__fastcall hkpConstraintChainUtil::buildBallSocketChain(
        hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *constraints)
{
  _QWORD **Value; // rax
  hkpBallSocketChainData *v3; // rax
  int v4; // edi
  hkpBallSocketChainData *v5; // rax
  hkpBallSocketChainData *v6; // rbp
  _QWORD **v7; // rax
  hkpConstraintChainInstance *v8; // rax
  hkpConstraintChainInstance *v9; // rax
  hkpConstraintChainInstance *v10; // rbx
  hkpConstraintInstance *v11; // rcx
  hkpEntity *v12; // rdx
  __int64 v13; // r8
  __int64 v14; // rsi
  hkpConstraintInstance **m_data; // r8
  __int64 v16; // rdx
  __m128 m_quad; // xmm1
  hkpConstraintInstance *v18; // rdx
  hkpEntity *v19; // rdx
  int v21; // r9d
  hkVector4f pivotInAOut; // [rsp+20h] [rbp-258h] BYREF
  hkErrStream v23; // [rsp+30h] [rbp-248h] BYREF
  hkVector4f pivotInBOut; // [rsp+50h] [rbp-228h] BYREF
  char buf[536]; // [rsp+60h] [rbp-218h] BYREF
  hkResult result; // [rsp+280h] [rbp+8h] BYREF

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkpBallSocketChainData *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 112i64);
  v4 = 0;
  if ( v3 )
  {
    hkpBallSocketChainData::hkpBallSocketChainData(v3);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  v7 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v8 = (hkpConstraintChainInstance *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v7[11] + 8i64))(v7[11], 144i64);
  if ( v8 )
  {
    hkpConstraintChainInstance::hkpConstraintChainInstance(v8, v6);
    v10 = v9;
  }
  else
  {
    v10 = 0i64;
  }
  v11 = *constraints->m_data;
  v12 = v11->m_entities[0];
  if ( constraints->m_size > 1 )
  {
    v13 = *((_QWORD *)constraints->m_data + 1);
    if ( v12 == *(hkpEntity **)(v13 + 40) || v12 == *(hkpEntity **)(v13 + 48) )
      v12 = v11->m_entities[1];
  }
  hkpConstraintChainInstance::addEntity(v10, v12);
  if ( constraints->m_size <= 0 )
  {
LABEL_20:
    hkReferencedObject::removeReference(v6);
    return v10;
  }
  else
  {
    v14 = 0i64;
    while ( hkpConstraintDataUtils::getConstraintPivots(
              &result,
              constraints->m_data[v14]->m_data,
              &pivotInAOut,
              &pivotInBOut)->m_enum != HK_FAILURE )
    {
      m_data = constraints->m_data;
      v16 = (__int64)&v10->m_chainedEntities.m_data[v10->m_chainedEntities.m_size];
      if ( constraints->m_data[v14]->m_entities[0] != *(hkpEntity **)(v16 - 8) )
      {
        m_quad = pivotInAOut.m_quad;
        pivotInAOut.m_quad = pivotInBOut.m_quad;
        pivotInBOut.m_quad = m_quad;
        if ( m_data[v14]->m_entities[1] != *(hkpEntity **)(v16 - 8) )
        {
          hkErrStream::hkErrStream(&v23, buf, 512);
          hkOstream::operator<<(
            &v23,
            "Constraints are not ordered properly ! Two consecutive constraint share no common hkpEntity.");
          v21 = 282;
          goto LABEL_23;
        }
      }
      hkpBallSocketChainData::addConstraintInfoInBodySpace(v6, &pivotInAOut, &pivotInBOut);
      v18 = constraints->m_data[v14];
      if ( v18->m_entities[0] == v10->m_chainedEntities.m_data[v10->m_chainedEntities.m_size - 1] )
        v19 = v18->m_entities[1];
      else
        v19 = v18->m_entities[0];
      hkpConstraintChainInstance::addEntity(v10, v19);
      ++v4;
      ++v14;
      if ( v4 >= constraints->m_size )
        goto LABEL_20;
    }
    hkErrStream::hkErrStream(&v23, buf, 512);
    hkOstream::operator<<(&v23, "Not supported types of constraints used to build a chain!");
    v21 = 271;
LABEL_23:
    hkError::messageWarning(0xABBAD88D, buf, "Constraint\\Chain\\hkpConstraintChainUtil.cpp", v21);
    hkOstream::~hkOstream(&v23);
    hkReferencedObject::removeReference(v6);
    hkReferencedObject::removeReference(v10);
    return 0i64;
  }
}

// File Line: 310
// RVA: 0xE238B0
hkResult *__fastcall hkpConstraintChainUtil::findConstraintLinkBetweenEntities(
        hkResult *result,
        hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *allConstraints,
        hkpEntity *entityA,
        hkpEntity *entityB,
        hkArray<hkpEntity *,hkContainerHeapAllocator> *entitiesOut,
        hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *constraintsOut)
{
  hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *v8; // r14
  hkResult *v10; // rax
  int v11; // ebx
  int v12; // edi
  __int64 v13; // rsi
  hkpConstraintInstance *v14; // rbx
  int Key; // eax
  int v16; // ecx
  hkpEntity *v17; // r14
  int v18; // eax
  int v19; // ecx
  hkpEntity *v20; // rbx
  int v21; // r9d
  int v22; // edx
  __int64 v23; // rcx
  signed int v24; // eax
  __int64 v25; // rbx
  signed int v26; // eax
  int v27; // r12d
  __int64 v28; // rdi
  __int64 v29; // rcx
  __int64 v30; // rcx
  int v31; // ecx
  int v32; // ecx
  hkResultEnum m_enum; // r14d
  int v34; // ecx
  __int64 v35; // rax
  int v36; // r13d
  __int64 v37; // rdx
  __int64 v38; // rcx
  const void **v39; // rbx
  hkpEntity *v40; // rdx
  __int64 v41; // rsi
  __int64 v42; // rax
  int v43; // edi
  signed int v44; // eax
  char *v45; // rdx
  __int64 v46; // r15
  int v47; // eax
  __int64 v48; // r14
  unsigned __int64 v49; // r8
  __int64 v50; // rax
  __int64 v51; // rdx
  hkArray<hkpEntity *,hkContainerHeapAllocator> *v52; // rsi
  __int64 v53; // r15
  int v54; // ebx
  int m_capacityAndFlags; // eax
  int v56; // r14d
  int v57; // eax
  int v58; // eax
  int v59; // r9d
  hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *v60; // rdi
  int v61; // eax
  int v62; // eax
  int v63; // eax
  int v64; // r9d
  int v65; // ecx
  __int64 i; // r9
  __int64 v67; // r8
  __int64 v68; // r10
  int v69; // eax
  __int64 v70; // r9
  __int64 v71; // r8
  int v72; // r8d
  int *p_m_capacityAndFlags; // rbx
  int v74; // r8d
  int v75; // r8d
  int *v76; // rbx
  int v77; // r8d
  _QWORD *array; // [rsp+30h] [rbp-D0h] BYREF
  int v79; // [rsp+38h] [rbp-C8h]
  int v80; // [rsp+3Ch] [rbp-C4h]
  AMD_HD3D v81; // [rsp+40h] [rbp-C0h] BYREF
  __int64 v82; // [rsp+60h] [rbp-A0h]
  int v83[2]; // [rsp+68h] [rbp-98h]
  int v84; // [rsp+70h] [rbp-90h]
  int v85; // [rsp+74h] [rbp-8Ch]
  hkpConstraintInstance *v86; // [rsp+78h] [rbp-88h]
  unsigned __int64 v87; // [rsp+80h] [rbp-80h]
  __int64 v88; // [rsp+88h] [rbp-78h]
  hkErrStream v89; // [rsp+90h] [rbp-70h] BYREF
  char *v90; // [rsp+B0h] [rbp-50h] BYREF
  int v91; // [rsp+B8h] [rbp-48h]
  int v92; // [rsp+BCh] [rbp-44h]
  char v93; // [rsp+C0h] [rbp-40h] BYREF
  char *v94; // [rsp+140h] [rbp+40h] BYREF
  int v95; // [rsp+148h] [rbp+48h]
  int v96; // [rsp+14Ch] [rbp+4Ch]
  char v97; // [rsp+150h] [rbp+50h] BYREF
  hkArray<hkpEntity *,hkContainerHeapAllocator> v98; // [rsp+1D0h] [rbp+D0h] BYREF
  char v99; // [rsp+1E0h] [rbp+E0h] BYREF
  hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> v100; // [rsp+2E0h] [rbp+1E0h] BYREF
  char v101; // [rsp+2F0h] [rbp+1F0h] BYREF
  char *v102; // [rsp+3F0h] [rbp+2F0h] BYREF
  int v103; // [rsp+3F8h] [rbp+2F8h]
  int v104; // [rsp+3FCh] [rbp+2FCh]
  char v105; // [rsp+400h] [rbp+300h] BYREF
  char buf[520]; // [rsp+700h] [rbp+600h] BYREF
  hkResult resulta; // [rsp+960h] [rbp+860h] BYREF
  int v110; // [rsp+968h] [rbp+868h]

  v8 = allConstraints;
  if ( entityA == entityB )
  {
    hkErrStream::hkErrStream(&v89, buf, 512);
    hkOstream::operator<<(&v89, "Specify two different end bodies.");
    hkError::messageWarning(0xABBA3BB3, buf, "Constraint\\Chain\\hkpConstraintChainUtil.cpp", 313);
    hkOstream::~hkOstream(&v89);
    v10 = result;
    result->m_enum = HK_FAILURE;
  }
  else
  {
    v80 = 0x80000000;
    v81.mHeight = -1;
    v11 = 0;
    array = 0i64;
    *(_QWORD *)&v81.mEnableStereo = 0i64;
    v81.mWidth = 0;
    v12 = 0;
    v79 = 0;
    if ( allConstraints->m_size > 0 )
    {
      v13 = 0i64;
      do
      {
        v14 = v8->m_data[v13];
        Key = (unsigned int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                              (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v81,
                              (unsigned __int64)v14->m_entities[0]);
        if ( Key > (int)v81.mHeight )
        {
          hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
            (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v81,
            &hkContainerHeapAllocator::s_alloc,
            (unsigned __int64)v14->m_entities[0],
            v79);
          v16 = v79;
          v17 = v14->m_entities[0];
          if ( v79 == (v80 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 8);
            v16 = v79;
          }
          array[v16] = v17;
          ++v79;
          v8 = allConstraints;
        }
        v18 = (unsigned int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                              (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v81,
                              (unsigned __int64)v14->m_entities[1]);
        if ( v18 <= (int)v81.mHeight )
        {
          v11 = v79;
        }
        else
        {
          hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
            (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v81,
            &hkContainerHeapAllocator::s_alloc,
            (unsigned __int64)v14->m_entities[1],
            v79);
          v19 = v79;
          v20 = v14->m_entities[1];
          if ( v79 == (v80 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 8);
            v19 = v79;
          }
          array[v19] = v20;
          v11 = ++v79;
        }
        ++v12;
        ++v13;
      }
      while ( v12 < v8->m_size );
    }
    v103 = 0;
    v104 = -2147483616;
    v102 = &v105;
    if ( v11 > 32 )
    {
      v21 = v11;
      if ( v11 < 64 )
        v21 = 64;
      hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, (const void **)&v102, v21, 24);
    }
    v103 = v11;
    v22 = 0;
    if ( v11 > 0 )
    {
      v23 = 0i64;
      do
      {
        ++v22;
        v23 += 24i64;
        *(_DWORD *)&v102[v23 - 24] = -1;
      }
      while ( v22 < v103 );
    }
    v90 = &v93;
    v91 = 0;
    v92 = -2147483616;
    v95 = 0;
    v96 = -2147483616;
    v94 = &v97;
    v81.mStereo = (IAmdDxExtQuadBufferStereo *)-1i64;
    v24 = (unsigned int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                          (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v81,
                          (unsigned __int64)entityA);
    v25 = *(int *)(*(_QWORD *)&v81.mEnableStereo + 16i64 * v24 + 8);
    v26 = (unsigned int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                          (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v81,
                          (unsigned __int64)entityB);
    v27 = 1;
    v28 = *(int *)(*(_QWORD *)&v81.mEnableStereo + 16i64 * v26 + 8);
    v29 = 3 * v25;
    *(_DWORD *)&v102[8 * v29] = 0;
    *(_DWORD *)&v102[8 * v29 + 4] = -1;
    *(_QWORD *)&v102[8 * v29 + 8] = 0i64;
    *(_DWORD *)&v102[8 * v29 + 16] = 0;
    v30 = 3 * v28;
    *(_DWORD *)&v102[8 * v30] = 1;
    *(_DWORD *)&v102[8 * v30 + 4] = -1;
    *(_QWORD *)&v102[8 * v30 + 8] = 0i64;
    *(_DWORD *)&v102[8 * v30 + 16] = 0;
    v31 = v91;
    if ( v91 == (v92 & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v90, 4);
      v31 = v91;
    }
    *(_DWORD *)&v90[4 * v31] = v25;
    v32 = v95;
    ++v91;
    if ( v95 == (v96 & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v94, 4);
      v32 = v95;
    }
    m_enum = HK_SUCCESS;
    *(_DWORD *)&v94[4 * v32] = v28;
    ++v95;
    v34 = 0;
    v86 = 0i64;
    v110 = 0;
    v98.m_data = (hkpEntity **)&v99;
    v98.m_size = 0;
    v100.m_data = (hkpConstraintInstance **)&v101;
    v98.m_capacityAndFlags = -2147483616;
    v100.m_size = 0;
    v35 = 0i64;
    v100.m_capacityAndFlags = -2147483616;
    resulta.m_enum = HK_SUCCESS;
    while ( 1 )
    {
      v36 = 1 - v34;
      v82 = 1 - v35;
      v37 = (int)++*((_DWORD *)&v81.mStereo + v35);
      v87 = 4 * v35;
      v38 = 18 * v35;
      if ( (int)v37 >= *(&v91 + 36 * v35) )
        break;
      v39 = (const void **)&(&v90)[v38];
      LODWORD(v81.mExtension) = *(_DWORD *)&(&v90)[v38][4 * v37];
      v40 = (hkpEntity *)array[SLODWORD(v81.mExtension)];
      v98.m_size = 0;
      v100.m_size = 0;
      hkpConstraintChainUtil::getAdjointEntities(allConstraints, v40, &v98, &v100);
      v41 = 0i64;
      v42 = m_enum;
      v43 = 0;
      v88 = m_enum;
      if ( v98.m_size > 0 )
      {
        while ( !v42 )
        {
          v44 = (unsigned int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                                (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v81,
                                (unsigned __int64)v98.m_data[v41]);
          v45 = v102;
          v46 = *(int *)(*(_QWORD *)&v81.mEnableStereo + 16i64 * v44 + 8);
          v47 = *(_DWORD *)&v102[24 * v46];
          v48 = 24 * v46;
          if ( v47 != v110 )
          {
            if ( v47 == v36 )
            {
              v49 = v87;
              m_enum = HK_FAILURE;
              v50 = 3i64 * SLODWORD(v81.mExtension);
              v83[v87 / 4] = (int)v81.mExtension;
              resulta.m_enum = HK_FAILURE;
              *(int *)((char *)&v84 + v49) = *(_DWORD *)&v45[8 * v50 + 16] + 1;
              LODWORD(v50) = *(_DWORD *)&v45[24 * v46 + 16];
              v51 = v82;
              v83[v82] = v46;
              *(&v84 + v51) = v50 + 1;
              v86 = v100.m_data[v41];
              goto LABEL_40;
            }
            if ( *((_DWORD *)v39 + 2) == (*((_DWORD *)v39 + 3) & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, v39, 4);
            *((_DWORD *)*v39 + (int)(*((_DWORD *)v39 + 2))++) = v46;
            *(_DWORD *)&v102[24 * v46] = v110;
            *(_DWORD *)&v102[v48 + 4] = *((_DWORD *)*v39 + *(int *)((char *)&v81.mStereo + v87));
            *(_QWORD *)&v102[v48 + 8] = v100.m_data[v41];
            *(_DWORD *)&v102[v48 + 16] = *(_DWORD *)&v102[24 * SLODWORD(v81.mExtension) + 16] + 1;
          }
          ++v43;
          ++v41;
          if ( v43 >= v98.m_size )
            break;
          v42 = v88;
        }
        m_enum = resulta.m_enum;
      }
      v51 = v82;
LABEL_40:
      v34 = v36;
      v35 = v51;
      v110 = v36;
      if ( m_enum )
      {
        v52 = entitiesOut;
        v53 = v85;
        v54 = v84;
        m_capacityAndFlags = entitiesOut->m_capacityAndFlags;
        v56 = v85 + v84;
        entitiesOut->m_size = 0;
        v57 = m_capacityAndFlags & 0x3FFFFFFF;
        if ( v57 < v56 )
        {
          v58 = 2 * v57;
          v59 = v56;
          if ( v56 < v58 )
            v59 = v58;
          hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, (const void **)&v52->m_data, v59, 8);
        }
        v60 = constraintsOut;
        v52->m_size = v56;
        v61 = v60->m_capacityAndFlags;
        v60->m_size = 0;
        v62 = v61 & 0x3FFFFFFF;
        if ( v62 < v56 )
        {
          v63 = 2 * v62;
          v64 = v56;
          if ( v56 < v63 )
            v64 = v63;
          hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, (const void **)&v60->m_data, v64, 8);
        }
        v65 = v83[0];
        v60->m_size = v56;
        for ( i = v54 - 1; i > 0; v65 = *(_DWORD *)&v102[v67 + 4] )
        {
          v52->m_data[i--] = (hkpEntity *)array[v65];
          v67 = 24i64 * v65;
          v60->m_data[i] = *(hkpConstraintInstance **)&v102[v67 + 8];
        }
        v68 = v53;
        *v52->m_data = (hkpEntity *)array[v65];
        v60->m_data[v54 - 1] = v86;
        v69 = v83[1];
        if ( (int)v53 > 0 )
        {
          v70 = v54;
          do
          {
            v52->m_data[v70++] = (hkpEntity *)array[v69];
            v71 = 24i64 * v69;
            v60->m_data[v70 - 1] = *(hkpConstraintInstance **)&v102[v71 + 8];
            v69 = *(_DWORD *)&v102[v71 + 4];
            --v68;
          }
          while ( v68 );
        }
        --v60->m_size;
        v72 = v100.m_capacityAndFlags;
        result->m_enum = HK_SUCCESS;
        v100.m_size = 0;
        if ( v72 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v100.m_data, 8 * v72);
        v100.m_data = 0i64;
        v100.m_capacityAndFlags = 0x80000000;
        v98.m_size = 0;
        if ( v98.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            v98.m_data,
            8 * v98.m_capacityAndFlags);
        v98.m_data = 0i64;
        v98.m_capacityAndFlags = 0x80000000;
        p_m_capacityAndFlags = &v98.m_capacityAndFlags;
        do
        {
          p_m_capacityAndFlags -= 36;
          v74 = *p_m_capacityAndFlags;
          *(p_m_capacityAndFlags - 1) = 0;
          if ( v74 >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              &hkContainerHeapAllocator::s_alloc,
              *(void **)(p_m_capacityAndFlags - 3),
              4 * v74);
          --v27;
          *(_QWORD *)(p_m_capacityAndFlags - 3) = 0i64;
          *p_m_capacityAndFlags = 0x80000000;
        }
        while ( v27 >= 0 );
        v103 = 0;
        if ( v104 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            v102,
            24 * (v104 & 0x3FFFFFFF));
        v102 = 0i64;
        v104 = 0x80000000;
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
          (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v81,
          &hkContainerHeapAllocator::s_alloc);
        _(&v81);
        v79 = 0;
        if ( v80 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 8 * v80);
        return result;
      }
    }
    v75 = v100.m_capacityAndFlags;
    v100.m_size = 0;
    result->m_enum = HK_FAILURE;
    if ( v75 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v100.m_data, 8 * v75);
    v100.m_data = 0i64;
    v100.m_capacityAndFlags = 0x80000000;
    v98.m_size = 0;
    if ( v98.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        v98.m_data,
        8 * v98.m_capacityAndFlags);
    v98.m_data = 0i64;
    v98.m_capacityAndFlags = 0x80000000;
    v76 = &v98.m_capacityAndFlags;
    do
    {
      v76 -= 36;
      v77 = *v76;
      *(v76 - 1) = 0;
      if ( v77 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          *(void **)(v76 - 3),
          4 * v77);
      --v27;
      *(_QWORD *)(v76 - 3) = 0i64;
      *v76 = 0x80000000;
    }
    while ( v27 >= 0 );
    v103 = 0;
    if ( v104 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        v102,
        24 * (v104 & 0x3FFFFFFF));
    v102 = 0i64;
    v104 = 0x80000000;
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v81,
      &hkContainerHeapAllocator::s_alloc);
    _(&v81);
    v79 = 0;
    if ( v80 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 8 * v80);
    return result;
  }
  return v10;
}  v102 = 0i64;
    v104 =

// File Line: 477
// RVA: 0xE243B0
void __fastcall hkpConstraintChainUtil::getAdjointEntities(
        hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *allConstraints,
        hkpEntity *entity,
        hkArray<hkpEntity *,hkContainerHeapAllocator> *entitiesOut,
        hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *constraintsOut)
{
  int v4; // esi
  __int64 v9; // r15
  hkpConstraintInstance *v10; // rdi
  hkpEntity *v11; // rax
  hkpEntity *v12; // rbp

  v4 = 0;
  if ( allConstraints->m_size > 0 )
  {
    v9 = 0i64;
    do
    {
      v10 = allConstraints->m_data[v9];
      v11 = v10->m_entities[0];
      if ( v11 == entity || v10->m_entities[1] == entity )
      {
        v12 = (hkpEntity *)((unsigned __int64)entity ^ (unsigned __int64)v11 ^ (unsigned __int64)v10->m_entities[1]);
        if ( entitiesOut->m_size == (entitiesOut->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&entitiesOut->m_data, 8);
        entitiesOut->m_data[entitiesOut->m_size++] = v12;
        if ( constraintsOut->m_size == (constraintsOut->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&constraintsOut->m_data, 8);
        constraintsOut->m_data[constraintsOut->m_size++] = v10;
      }
      ++v4;
      ++v9;
    }
    while ( v4 < allConstraints->m_size );
  }
}

