// File Line: 43
// RVA: 0xE233D0
void __fastcall hkpConstraintChainUtil::addConstraintToBallSocketChain(hkpConstraintChainInstance *instance, hkpEntity *entityToAppend, hkVector4f *pivotWs)
{
  __int64 v3; // r9
  __m128 *v4; // rax
  hkVector4f *v5; // r11
  hkpEntity *v6; // rdi
  hkpConstraintChainInstance *v7; // rbx
  __m128 *v8; // r8
  __m128 v9; // xmm3
  __m128 v10; // xmm0
  hkpBallSocketChainData *v11; // rcx
  __m128 v12; // xmm6
  __m128 v13; // xmm1
  __m128 v14; // xmm2
  __m128 v15; // xmm5
  __m128 v16; // xmm6
  __m128 v17; // xmm0
  __m128 v18; // xmm3
  __m128 v19; // xmm1
  __m128 v20; // xmm2
  hkVector4f pivotInA; // [rsp+20h] [rbp-38h]
  hkVector4f pivotInB; // [rsp+30h] [rbp-28h]

  v3 = instance->m_chainedEntities.m_size;
  v4 = 0i64;
  v5 = pivotWs;
  v6 = entityToAppend;
  v7 = instance;
  if ( instance->m_chainedEntities.m_data[v3 - 1]->m_collidable.m_broadPhaseHandle.m_type == 1 )
    v8 = (__m128 *)((char *)&instance->m_chainedEntities.m_data[v3 - 1]->m_collidable
                  + instance->m_chainedEntities.m_data[v3 - 1]->m_collidable.m_ownerOffset);
  else
    v8 = 0i64;
  if ( entityToAppend->m_collidable.m_broadPhaseHandle.m_type == 1 )
    v4 = (__m128 *)((char *)&entityToAppend->m_collidable + entityToAppend->m_collidable.m_ownerOffset);
  v9 = v8[25];
  v10 = v8[24];
  v11 = (hkpBallSocketChainData *)instance->m_data;
  v12 = v5->m_quad;
  v13 = _mm_unpacklo_ps(v8[23], v10);
  v14 = _mm_movelh_ps(v13, v9);
  v15 = _mm_sub_ps(v5->m_quad, v8[26]);
  pivotInA.m_quad = _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(_mm_movehl_ps(v14, v13), v9, 212)),
                        _mm_mul_ps(_mm_shuffle_ps(v15, v15, 0), v14)),
                      _mm_mul_ps(_mm_shuffle_ps(_mm_unpackhi_ps(v8[23], v10), v9, 228), _mm_shuffle_ps(v15, v15, 170)));
  v16 = _mm_sub_ps(v12, v4[26]);
  v17 = v4[24];
  v18 = v4[25];
  v19 = _mm_unpacklo_ps(v4[23], v17);
  v20 = _mm_movelh_ps(v19, v18);
  pivotInB.m_quad = _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(_mm_movehl_ps(v20, v19), v18, 212)),
                        _mm_mul_ps(_mm_shuffle_ps(v16, v16, 0), v20)),
                      _mm_mul_ps(_mm_shuffle_ps(_mm_unpackhi_ps(v4[23], v17), v18, 228), _mm_shuffle_ps(v16, v16, 170)));
  hkpBallSocketChainData::addConstraintInfoInBodySpace(v11, &pivotInA, &pivotInB);
  hkpConstraintChainInstance::addEntity(v7, v6);
}

// File Line: 63
// RVA: 0xE23520
void __fastcall hkpConstraintChainUtil::addConstraintToPoweredChain(hkpConstraintChainInstance *instance, hkpEntity *entityToAppend, hkVector4f *pivotWs, hkpConstraintMotor *motor0, hkpConstraintMotor *motor1, hkpConstraintMotor *motor2)
{
  __int64 v6; // r10
  __m128 *v7; // rax
  hkVector4f *v8; // rsi
  hkpEntity *v9; // rdi
  hkpConstraintChainInstance *v10; // rbx
  __m128 *v11; // r8
  __m128 v12; // xmm3
  __m128 v13; // xmm0
  __m128 v14; // xmm6
  __m128 v15; // xmm1
  __m128 v16; // xmm2
  __m128 v17; // xmm5
  __m128 v18; // xmm6
  __m128 v19; // xmm3
  __m128 v20; // xmm0
  __m128 v21; // xmm1
  __m128 v22; // xmm2
  __m128 v23; // xmm2
  __m128 v24; // xmm3
  __m128 v25; // xmm1
  __m128 v26; // xmm4
  __m128 v27; // xmm0
  __m128 v28; // xmm3
  __m128 v29; // xmm4
  __m128 v30; // xmm0
  hkpPoweredChainData *v31; // rcx
  hkVector4f pivotInA; // [rsp+40h] [rbp-78h]
  hkVector4f pivotInB; // [rsp+50h] [rbp-68h]
  hkQuaternionf aTc; // [rsp+60h] [rbp-58h]
  hkpConstraintMotor *v35; // [rsp+80h] [rbp-38h]
  hkpConstraintMotor *v36; // [rsp+88h] [rbp-30h]
  hkpConstraintMotor *v37; // [rsp+90h] [rbp-28h]

  v6 = instance->m_chainedEntities.m_size;
  v7 = 0i64;
  v8 = pivotWs;
  v9 = entityToAppend;
  v10 = instance;
  if ( instance->m_chainedEntities.m_data[v6 - 1]->m_collidable.m_broadPhaseHandle.m_type == 1 )
    v11 = (__m128 *)((char *)&instance->m_chainedEntities.m_data[v6 - 1]->m_collidable
                   + instance->m_chainedEntities.m_data[v6 - 1]->m_collidable.m_ownerOffset);
  else
    v11 = 0i64;
  if ( entityToAppend->m_collidable.m_broadPhaseHandle.m_type == 1 )
    v7 = (__m128 *)((char *)&entityToAppend->m_collidable + entityToAppend->m_collidable.m_ownerOffset);
  v12 = v11[25];
  v13 = v11[24];
  v14 = v8->m_quad;
  v15 = _mm_unpacklo_ps(v11[23], v13);
  v16 = _mm_movelh_ps(v15, v12);
  v17 = _mm_sub_ps(v8->m_quad, v11[26]);
  pivotInA.m_quad = _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(_mm_movehl_ps(v16, v15), v12, 212)),
                        _mm_mul_ps(_mm_shuffle_ps(v17, v17, 0), v16)),
                      _mm_mul_ps(_mm_shuffle_ps(_mm_unpackhi_ps(v11[23], v13), v12, 228), _mm_shuffle_ps(v17, v17, 170)));
  v18 = _mm_sub_ps(v14, v7[26]);
  v19 = v7[25];
  v20 = v7[24];
  v21 = _mm_unpacklo_ps(v7[23], v20);
  v22 = _mm_movelh_ps(v21, v19);
  pivotInB.m_quad = _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(_mm_movehl_ps(v22, v21), v19, 212)),
                        _mm_mul_ps(_mm_shuffle_ps(v18, v18, 0), v22)),
                      _mm_mul_ps(_mm_shuffle_ps(v18, v18, 170), _mm_shuffle_ps(_mm_unpackhi_ps(v7[23], v20), v19, 228)));
  v23 = v7[30];
  v24 = v11[30];
  v35 = motor0;
  v25 = _mm_mul_ps(_mm_shuffle_ps(v24, v24, 255), v23);
  v26 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v23, v23, 201), v24), _mm_mul_ps(_mm_shuffle_ps(v24, v24, 201), v23));
  v27 = _mm_mul_ps(_mm_shuffle_ps(v23, v23, 255), v24);
  v28 = _mm_mul_ps(v24, v23);
  v29 = _mm_add_ps(_mm_sub_ps(_mm_shuffle_ps(v26, v26, 201), v27), v25);
  v30 = _mm_add_ps(_mm_shuffle_ps(v28, v28, 78), v28);
  aTc.m_vec.m_quad = _mm_shuffle_ps(v29, _mm_unpackhi_ps(v29, _mm_add_ps(_mm_shuffle_ps(v30, v30, 177), v30)), 196);
  v31 = (hkpPoweredChainData *)instance->m_data;
  v36 = motor1;
  v37 = motor2;
  hkpPoweredChainData::addConstraintInfoInBodySpace(v31, &pivotInA, &pivotInB, &aTc, motor0, motor1, motor2);
  hkpConstraintChainInstance::addEntity(v10, v9);
}

// File Line: 92
// RVA: 0xE23730
hkResult *__fastcall hkpConstraintChainUtil::addConstraintToChain(hkResult *result, hkpConstraintInstance *newChildInstance, hkpConstraintChainInstance *chainInstance, hkpBallSocketChainData *chainData)
{
  hkpConstraintInstance *v4; // rsi
  hkpBallSocketChainData *v5; // rbp
  hkpConstraintChainInstance *v6; // rdi
  hkResult *v7; // rbx
  hkpEntity **v8; // r8
  hkpEntity *v9; // r9
  hkpEntity *v10; // rdx
  hkpEntity *v11; // rcx
  hkVector4f pivotInAOut; // [rsp+20h] [rbp-48h]
  hkVector4f pivotInBOut; // [rsp+30h] [rbp-38h]
  hkpBallSocketChainData::ConstraintInfo t; // [rsp+40h] [rbp-28h]
  hkResult resulta; // [rsp+78h] [rbp+10h]

  v4 = newChildInstance;
  v5 = chainData;
  v6 = chainInstance;
  v7 = result;
  if ( hkpConstraintDataUtils::getConstraintPivots(&resulta, newChildInstance->m_data, &pivotInAOut, &pivotInBOut)->m_enum )
    goto LABEL_12;
  if ( !v6->m_chainedEntities.m_size )
    hkpConstraintChainInstance::addEntity(v6, v4->m_entities[0]);
  v8 = v6->m_chainedEntities.m_data;
  v9 = v4->m_entities[0];
  v10 = v8[v6->m_chainedEntities.m_size - 1];
  if ( v10 != v9 )
  {
    v11 = v4->m_entities[1];
    if ( v10 == v11 )
    {
      hkpBallSocketChainData::addConstraintInfoInBodySpace(v5, &pivotInBOut, &pivotInAOut);
      hkpConstraintChainInstance::addEntity(v6, v4->m_entities[0]);
      v7->m_enum = 0;
      return v7;
    }
    if ( *v8 == v9 )
    {
      t.m_pivotInA = (hkVector4f)pivotInBOut.m_quad;
      t.m_pivotInB = (hkVector4f)pivotInAOut.m_quad;
      hkArrayBase<hkpBallSocketChainData::ConstraintInfo>::_insertAt(
        (hkArrayBase<hkpBallSocketChainData::ConstraintInfo> *)&v5->m_infos.m_data,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        0,
        &t);
      hkpConstraintChainInstance::insertEntityAtFront(v6, v4->m_entities[1]);
      v7->m_enum = 0;
      return v7;
    }
    if ( *v8 == v11 )
    {
      t.m_pivotInA = (hkVector4f)pivotInAOut.m_quad;
      t.m_pivotInB = (hkVector4f)pivotInBOut.m_quad;
      hkArrayBase<hkpBallSocketChainData::ConstraintInfo>::_insertAt(
        (hkArrayBase<hkpBallSocketChainData::ConstraintInfo> *)&v5->m_infos.m_data,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        0,
        &t);
      hkpConstraintChainInstance::insertEntityAtFront(v6, v4->m_entities[0]);
      v7->m_enum = 0;
      return v7;
    }
LABEL_12:
    v7->m_enum = 1;
    return v7;
  }
  hkpBallSocketChainData::addConstraintInfoInBodySpace(v5, &pivotInAOut, &pivotInBOut);
  hkpConstraintChainInstance::addEntity(v6, v4->m_entities[1]);
  v7->m_enum = 0;
  return v7;
}

// File Line: 162
// RVA: 0xE22DA0
hkpConstraintChainInstance *__fastcall hkpConstraintChainUtil::buildPoweredChain(hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *constraints, hkBool cloneMotors)
{
  hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *v2; // rsi
  _QWORD **v3; // rax
  hkpPoweredChainData *v4; // rax
  int v5; // er15
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
  signed __int64 v16; // r8
  hkpConstraintInstance **v17; // rcx
  hkpConstraintInstance *v18; // rdx
  __m128 v19; // xmm1
  __m128 v20; // xmm2
  __m128 v21; // xmm4
  __m128 v22; // xmm3
  __m128 v23; // xmm1
  __m128 v24; // xmm0
  __m128 v25; // xmm4
  __m128 v26; // xmm3
  __m128 v27; // xmm0
  hkpConstraintMotor *v28; // rcx
  hkpConstraintMotor *yMotor; // rdx
  hkpConstraintMotor *zMotor; // rax
  hkpConstraintInstance *v31; // rdx
  hkpEntity *v32; // rdx
  hkpConstraintChainInstance *v33; // rax
  hkOstream *v34; // rcx
  int v35; // er9
  int v36; // ecx
  hkpConstraintMotor *motor0; // [rsp+40h] [rbp-C0h]
  hkpConstraintMotor *motor1; // [rsp+48h] [rbp-B8h]
  hkpConstraintMotor *motor2; // [rsp+50h] [rbp-B0h]
  hkVector4f pivotInAOut; // [rsp+60h] [rbp-A0h]
  hkVector4f pivotInBOut; // [rsp+70h] [rbp-90h]
  hkErrStream v42; // [rsp+80h] [rbp-80h]
  hkQuaternionf aTc; // [rsp+A0h] [rbp-60h]
  char buf; // [rsp+B0h] [rbp-50h]
  hkResult result; // [rsp+2E0h] [rbp+1E0h]
  char v46; // [rsp+2E8h] [rbp+1E8h]
  hkResult v47; // [rsp+2F0h] [rbp+1F0h]

  v46 = cloneMotors.m_bool;
  v2 = constraints;
  v3 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v4 = (hkpPoweredChainData *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v3[11] + 8i64))(v3[11], 112i64);
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
  v9 = (hkpConstraintChainInstance *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v8[11] + 8i64))(
                                       v8[11],
                                       144i64);
  if ( v9 )
  {
    hkpConstraintChainInstance::hkpConstraintChainInstance(v9, (hkpConstraintChainData *)&v7->vfptr);
    v11 = v10;
  }
  else
  {
    v11 = 0i64;
  }
  v12 = *v2->m_data;
  v13 = v12->m_entities[0];
  if ( v2->m_size > 1 )
  {
    v14 = *((_QWORD *)v2->m_data + 1);
    if ( v13 == *(hkpEntity **)(v14 + 40) || v13 == *(hkpEntity **)(v14 + 48) )
      v13 = v12->m_entities[1];
  }
  hkpConstraintChainInstance::addEntity(v11, v13);
  if ( v2->m_size <= 0 )
  {
LABEL_29:
    hkReferencedObject::removeReference((hkReferencedObject *)&v7->vfptr);
    v33 = v11;
  }
  else
  {
    v15 = 0i64;
    while ( hkpConstraintDataUtils::getConstraintPivots(&result, v2->m_data[v15]->m_data, &pivotInAOut, &pivotInBOut)->m_enum != 1 )
    {
      v16 = (signed __int64)&v11->m_chainedEntities.m_data[v11->m_chainedEntities.m_size];
      v17 = v2->m_data;
      v18 = v2->m_data[v15];
      if ( v18->m_entities[0] != *(hkpEntity **)(v16 - 8) )
      {
        v19 = pivotInAOut.m_quad;
        pivotInAOut.m_quad = pivotInBOut.m_quad;
        pivotInBOut.m_quad = v19;
        v18 = v17[v15];
        if ( v18->m_entities[1] != *(hkpEntity **)(v16 - 8) )
        {
          hkErrStream::hkErrStream((hkErrStream *)&motor0, &buf, 512);
          hkOstream::operator<<(
            (hkOstream *)&motor0,
            "Constraints are not ordered properly ! Two consecutive constraint share no common hkpEntity.");
          hkError::messageWarning(-1413818227, &buf, "Constraint\\Chain\\hkpConstraintChainUtil.cpp", 192);
          v34 = (hkOstream *)&motor0;
          goto LABEL_35;
        }
      }
      v20 = v18->m_entities[0]->m_motion.m_motionState.m_sweptTransform.m_rotation1.m_vec.m_quad;
      v21 = v18->m_entities[1]->m_motion.m_motionState.m_sweptTransform.m_rotation1.m_vec.m_quad;
      v22 = _mm_mul_ps(
              _mm_shuffle_ps(
                v18->m_entities[0]->m_motion.m_motionState.m_sweptTransform.m_rotation1.m_vec.m_quad,
                v18->m_entities[0]->m_motion.m_motionState.m_sweptTransform.m_rotation1.m_vec.m_quad,
                255),
              v21);
      v23 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v20, v20, 201), v21), _mm_mul_ps(_mm_shuffle_ps(v21, v21, 201), v20));
      v24 = _mm_shuffle_ps(v21, v21, 255);
      v25 = _mm_mul_ps(v21, v20);
      v26 = _mm_sub_ps(_mm_add_ps(v22, _mm_shuffle_ps(v23, v23, 201)), _mm_mul_ps(v24, v20));
      v27 = _mm_add_ps(_mm_shuffle_ps(v25, v25, 78), v25);
      aTc.m_vec.m_quad = _mm_shuffle_ps(v26, _mm_unpackhi_ps(v26, _mm_add_ps(_mm_shuffle_ps(v27, v27, 177), v27)), 196);
      hkpConstraintDataUtils::getConstraintMotors(&v47, v18->m_data, &motor0, &motor1, &motor2);
      v28 = motor0;
      if ( !motor0 )
      {
        hkErrStream::hkErrStream(&v42, &buf, 512);
        hkOstream::operator<<((hkOstream *)&v42.vfptr, "No motors extracted from the original constraint.");
        v35 = 205;
        v36 = -1413838637;
        goto LABEL_34;
      }
      yMotor = motor1;
      zMotor = motor2;
      if ( !motor1 )
        yMotor = motor0;
      if ( !motor2 )
        zMotor = motor0;
      motor1 = yMotor;
      motor2 = zMotor;
      if ( v46 )
      {
        motor0 = (hkpConstraintMotor *)((__int64 (*)(void))motor0->vfptr[1].__first_virtual_table_function__)();
        motor1 = (hkpConstraintMotor *)((__int64 (*)(void))motor1->vfptr[1].__first_virtual_table_function__)();
        zMotor = (hkpConstraintMotor *)((__int64 (*)(void))motor2->vfptr[1].__first_virtual_table_function__)();
        yMotor = motor1;
        v28 = motor0;
        motor2 = zMotor;
      }
      hkpPoweredChainData::addConstraintInfoInBodySpace(v7, &pivotInAOut, &pivotInBOut, &aTc, v28, yMotor, zMotor);
      if ( v46 )
      {
        hkReferencedObject::removeReference((hkReferencedObject *)&motor0->vfptr);
        hkReferencedObject::removeReference((hkReferencedObject *)&motor1->vfptr);
        hkReferencedObject::removeReference((hkReferencedObject *)&motor2->vfptr);
      }
      v31 = v2->m_data[v15];
      if ( v31->m_entities[0] == v11->m_chainedEntities.m_data[v11->m_chainedEntities.m_size - 1] )
      {
        v32 = v31->m_entities[1];
      }
      else
      {
        *((_BYTE *)&v7->m_infos.m_data[v7->m_infos.m_size] - 8) = 1;
        v32 = v2->m_data[v15]->m_entities[0];
      }
      hkpConstraintChainInstance::addEntity(v11, v32);
      ++v5;
      ++v15;
      if ( v5 >= v2->m_size )
        goto LABEL_29;
    }
    hkErrStream::hkErrStream(&v42, &buf, 512);
    hkOstream::operator<<((hkOstream *)&v42.vfptr, "Not supported types of constraints used to build a chain!");
    v35 = 181;
    v36 = -1413818227;
LABEL_34:
    hkError::messageWarning(v36, &buf, "Constraint\\Chain\\hkpConstraintChainUtil.cpp", v35);
    v34 = (hkOstream *)&v42;
LABEL_35:
    hkOstream::~hkOstream(v34);
    hkReferencedObject::removeReference((hkReferencedObject *)&v7->vfptr);
    hkReferencedObject::removeReference((hkReferencedObject *)&v11->vfptr);
    v33 = 0i64;
  }
  return v33;
}

// File Line: 252
// RVA: 0xE23190
hkpConstraintChainInstance *__fastcall hkpConstraintChainUtil::buildBallSocketChain(hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *constraints)
{
  hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *v1; // r14
  _QWORD **v2; // rax
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
  hkpConstraintInstance **v15; // r8
  signed __int64 v16; // rdx
  __m128 v17; // xmm1
  hkpConstraintInstance *v18; // rdx
  hkpEntity *v19; // rdx
  hkpConstraintChainInstance *v20; // rax
  int v21; // er9
  hkVector4f pivotInAOut; // [rsp+20h] [rbp-258h]
  hkErrStream v23; // [rsp+30h] [rbp-248h]
  hkVector4f pivotInBOut; // [rsp+50h] [rbp-228h]
  char buf; // [rsp+60h] [rbp-218h]
  hkResult result; // [rsp+280h] [rbp+8h]

  v1 = constraints;
  v2 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkpBallSocketChainData *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v2[11] + 8i64))(v2[11], 112i64);
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
  v8 = (hkpConstraintChainInstance *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v7[11] + 8i64))(
                                       v7[11],
                                       144i64);
  if ( v8 )
  {
    hkpConstraintChainInstance::hkpConstraintChainInstance(v8, (hkpConstraintChainData *)&v6->vfptr);
    v10 = v9;
  }
  else
  {
    v10 = 0i64;
  }
  v11 = *v1->m_data;
  v12 = v11->m_entities[0];
  if ( v1->m_size > 1 )
  {
    v13 = *((_QWORD *)v1->m_data + 1);
    if ( v12 == *(hkpEntity **)(v13 + 40) || v12 == *(hkpEntity **)(v13 + 48) )
      v12 = v11->m_entities[1];
  }
  hkpConstraintChainInstance::addEntity(v10, v12);
  if ( v1->m_size <= 0 )
  {
LABEL_20:
    hkReferencedObject::removeReference((hkReferencedObject *)&v6->vfptr);
    v20 = v10;
  }
  else
  {
    v14 = 0i64;
    while ( hkpConstraintDataUtils::getConstraintPivots(&result, v1->m_data[v14]->m_data, &pivotInAOut, &pivotInBOut)->m_enum != 1 )
    {
      v15 = v1->m_data;
      v16 = (signed __int64)&v10->m_chainedEntities.m_data[v10->m_chainedEntities.m_size];
      if ( v1->m_data[v14]->m_entities[0] != *(hkpEntity **)(v16 - 8) )
      {
        v17 = pivotInAOut.m_quad;
        pivotInAOut.m_quad = pivotInBOut.m_quad;
        pivotInBOut.m_quad = v17;
        if ( v15[v14]->m_entities[1] != *(hkpEntity **)(v16 - 8) )
        {
          hkErrStream::hkErrStream(&v23, &buf, 512);
          hkOstream::operator<<(
            (hkOstream *)&v23.vfptr,
            "Constraints are not ordered properly ! Two consecutive constraint share no common hkpEntity.");
          v21 = 282;
          goto LABEL_24;
        }
      }
      hkpBallSocketChainData::addConstraintInfoInBodySpace(v6, &pivotInAOut, &pivotInBOut);
      v18 = v1->m_data[v14];
      if ( v18->m_entities[0] == v10->m_chainedEntities.m_data[v10->m_chainedEntities.m_size - 1] )
        v19 = v18->m_entities[1];
      else
        v19 = v18->m_entities[0];
      hkpConstraintChainInstance::addEntity(v10, v19);
      ++v4;
      ++v14;
      if ( v4 >= v1->m_size )
        goto LABEL_20;
    }
    hkErrStream::hkErrStream(&v23, &buf, 512);
    hkOstream::operator<<((hkOstream *)&v23.vfptr, "Not supported types of constraints used to build a chain!");
    v21 = 271;
LABEL_24:
    hkError::messageWarning(-1413818227, &buf, "Constraint\\Chain\\hkpConstraintChainUtil.cpp", v21);
    hkOstream::~hkOstream((hkOstream *)&v23.vfptr);
    hkReferencedObject::removeReference((hkReferencedObject *)&v6->vfptr);
    hkReferencedObject::removeReference((hkReferencedObject *)&v10->vfptr);
    v20 = 0i64;
  }
  return v20;
}    hkReferencedO

// File Line: 310
// RVA: 0xE238B0
hkResult *__fastcall hkpConstraintChainUtil::findConstraintLinkBetweenEntities(hkResult *result, hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *allConstraints, hkpEntity *entityA, hkpEntity *entityB, hkArray<hkpEntity *,hkContainerHeapAllocator> *entitiesOut, hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *constraintsOut)
{
  hkpEntity *v6; // r15
  hkpEntity *v7; // r12
  hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *v8; // r14
  hkResult *v9; // rsi
  hkResult *v10; // rax
  int v11; // ebx
  int v12; // edi
  __int64 v13; // rsi
  hkpConstraintInstance *v14; // rbx
  int v15; // eax
  int v16; // ecx
  hkpEntity *v17; // r14
  int v18; // eax
  int v19; // ecx
  hkpEntity *v20; // rbx
  int v21; // er9
  int v22; // edx
  __int64 v23; // rcx
  int v24; // eax
  __int64 v25; // rbx
  int v26; // eax
  signed int v27; // er12
  __int64 v28; // rdi
  signed __int64 v29; // rcx
  signed __int64 v30; // rcx
  int v31; // ecx
  int v32; // ecx
  hkResultEnum v33; // er14
  int v34; // ecx
  __int64 v35; // rax
  int v36; // er13
  __int64 v37; // rdx
  signed __int64 v38; // rcx
  char **v39; // rbx
  hkpEntity *v40; // rdx
  __int64 v41; // rsi
  __int64 v42; // rax
  int v43; // edi
  int v44; // eax
  __int64 v45; // rdx
  __int64 v46; // r15
  int v47; // eax
  signed __int64 v48; // r14
  __int64 v49; // r8
  signed __int64 v50; // rax
  __int64 v51; // rdx
  hkArray<hkpEntity *,hkContainerHeapAllocator> *v52; // rsi
  __int64 v53; // r15
  int v54; // ebx
  int v55; // eax
  int v56; // er14
  int v57; // eax
  int v58; // eax
  int v59; // er9
  hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *v60; // rdi
  int v61; // eax
  int v62; // eax
  int v63; // eax
  int v64; // er9
  int v65; // ecx
  __int64 i; // r9
  signed __int64 v67; // r8
  __int64 v68; // r10
  int v69; // eax
  signed __int64 v70; // r9
  signed __int64 v71; // r8
  int v72; // er8
  int *v73; // rbx
  int v74; // er8
  int v75; // er8
  int *v76; // rbx
  int v77; // er8
  _QWORD *array; // [rsp+30h] [rbp-D0h]
  int v79; // [rsp+38h] [rbp-C8h]
  int v80; // [rsp+3Ch] [rbp-C4h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v81; // [rsp+40h] [rbp-C0h]
  __int64 v82; // [rsp+50h] [rbp-B0h]
  int v83; // [rsp+58h] [rbp-A8h]
  __int64 v84; // [rsp+60h] [rbp-A0h]
  int v85; // [rsp+68h] [rbp-98h]
  int v86; // [rsp+6Ch] [rbp-94h]
  __int64 v87; // [rsp+70h] [rbp-90h]
  hkpConstraintInstance *v88; // [rsp+78h] [rbp-88h]
  __int64 v89; // [rsp+80h] [rbp-80h]
  __int64 v90; // [rsp+88h] [rbp-78h]
  hkErrStream v91; // [rsp+90h] [rbp-70h]
  char *v92; // [rsp+B0h] [rbp-50h]
  int v93; // [rsp+B8h] [rbp-48h]
  int v94; // [rsp+BCh] [rbp-44h]
  char v95; // [rsp+C0h] [rbp-40h]
  char *v96; // [rsp+140h] [rbp+40h]
  int v97; // [rsp+148h] [rbp+48h]
  int v98; // [rsp+14Ch] [rbp+4Ch]
  char v99; // [rsp+150h] [rbp+50h]
  hkArray<hkpEntity *,hkContainerHeapAllocator> v100; // [rsp+1D0h] [rbp+D0h]
  char v101; // [rsp+1E0h] [rbp+E0h]
  hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> v102; // [rsp+2E0h] [rbp+1E0h]
  char v103; // [rsp+2F0h] [rbp+1F0h]
  char *v104; // [rsp+3F0h] [rbp+2F0h]
  int v105; // [rsp+3F8h] [rbp+2F8h]
  int v106; // [rsp+3FCh] [rbp+2FCh]
  char v107; // [rsp+400h] [rbp+300h]
  char buf; // [rsp+700h] [rbp+600h]
  hkResult *v109; // [rsp+950h] [rbp+850h]
  hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *allConstraintsa; // [rsp+958h] [rbp+858h]
  hkResult resulta; // [rsp+960h] [rbp+860h]
  int v112; // [rsp+968h] [rbp+868h]

  allConstraintsa = allConstraints;
  v109 = result;
  v6 = entityB;
  v7 = entityA;
  v8 = allConstraints;
  v9 = result;
  if ( entityA == entityB )
  {
    hkErrStream::hkErrStream(&v91, &buf, 512);
    hkOstream::operator<<((hkOstream *)&v91.vfptr, "Specify two different end bodies.");
    hkError::messageWarning(-1413858381, &buf, "Constraint\\Chain\\hkpConstraintChainUtil.cpp", 313);
    hkOstream::~hkOstream((hkOstream *)&v91.vfptr);
    v10 = v9;
    v9->m_enum = 1;
  }
  else
  {
    v80 = 2147483648;
    v81.m_hashMod = -1;
    v11 = 0;
    array = 0i64;
    v81.m_elem = 0i64;
    v81.m_numElems = 0;
    v12 = 0;
    v79 = 0;
    if ( allConstraints->m_size > 0 )
    {
      v13 = 0i64;
      do
      {
        v14 = v8->m_data[v13];
        v15 = (unsigned __int64)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                                  &v81,
                                  (unsigned __int64)v14->m_entities[0]);
        if ( v15 > v81.m_hashMod )
        {
          hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
            &v81,
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            (unsigned __int64)v14->m_entities[0],
            v79);
          v16 = v79;
          v17 = v14->m_entities[0];
          if ( v79 == (v80 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 8);
            v16 = v79;
          }
          array[v16] = v17;
          ++v79;
          v8 = allConstraintsa;
        }
        v18 = (unsigned __int64)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                                  &v81,
                                  (unsigned __int64)v14->m_entities[1]);
        if ( v18 <= v81.m_hashMod )
        {
          v11 = v79;
        }
        else
        {
          hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
            &v81,
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            (unsigned __int64)v14->m_entities[1],
            v79);
          v19 = v79;
          v20 = v14->m_entities[1];
          if ( v79 == (v80 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 8);
            v19 = v79;
          }
          array[v19] = v20;
          v11 = v79++ + 1;
        }
        ++v12;
        ++v13;
      }
      while ( v12 < v8->m_size );
    }
    v105 = 0;
    v106 = -2147483616;
    v104 = &v107;
    if ( v11 > 32 )
    {
      v21 = v11;
      if ( v11 < 64 )
        v21 = 64;
      hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v104, v21, 24);
    }
    v105 = v11;
    v22 = 0;
    if ( v11 > 0 )
    {
      v23 = 0i64;
      do
      {
        ++v22;
        v23 += 24i64;
        *(_DWORD *)&v104[v23 - 24] = -1;
      }
      while ( v22 < v105 );
    }
    v92 = &v95;
    v93 = 0;
    v94 = -2147483616;
    v97 = 0;
    v98 = -2147483616;
    v96 = &v99;
    v82 = -1i64;
    v24 = (unsigned __int64)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                              &v81,
                              (unsigned __int64)v7);
    v25 = SLODWORD(v81.m_elem[v24].val);
    v26 = (unsigned __int64)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                              &v81,
                              (unsigned __int64)v6);
    v27 = 1;
    v28 = SLODWORD(v81.m_elem[v26].val);
    v29 = 3 * v25;
    *(_DWORD *)&v104[8 * v29] = 0;
    *(_DWORD *)&v104[8 * v29 + 4] = -1;
    *(_QWORD *)&v104[8 * v29 + 8] = 0i64;
    *(_DWORD *)&v104[8 * v29 + 16] = 0;
    v30 = 3 * v28;
    *(_DWORD *)&v104[8 * v30] = 1;
    *(_DWORD *)&v104[8 * v30 + 4] = -1;
    *(_QWORD *)&v104[8 * v30 + 8] = 0i64;
    *(_DWORD *)&v104[8 * v30 + 16] = 0;
    v31 = v93;
    if ( v93 == (v94 & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v92, 4);
      v31 = v93;
    }
    *(_DWORD *)&v92[4 * v31] = v25;
    v32 = v97;
    ++v93;
    if ( v97 == (v98 & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v96, 4);
      v32 = v97;
    }
    v33 = 0;
    *(_DWORD *)&v96[4 * v32] = v28;
    ++v97;
    v34 = 0;
    v88 = 0i64;
    v112 = 0;
    v100.m_data = (hkpEntity **)&v101;
    v100.m_size = 0;
    v102.m_data = (hkpConstraintInstance **)&v103;
    v100.m_capacityAndFlags = -2147483616;
    v102.m_size = 0;
    v35 = 0i64;
    v102.m_capacityAndFlags = -2147483616;
    resulta.m_enum = 0;
    while ( 1 )
    {
      v36 = 1 - v34;
      v84 = 1 - v35;
      v37 = (signed int)++*((_DWORD *)&v82 + v35);
      v89 = 4 * v35;
      v38 = 18 * v35;
      if ( (signed int)v37 >= *(&v93 + 36 * v35) )
        break;
      v39 = &(&v92)[v38];
      v83 = *(_DWORD *)&(&v92)[v38][4 * v37];
      v40 = (hkpEntity *)array[v83];
      v100.m_size = 0;
      v102.m_size = 0;
      hkpConstraintChainUtil::getAdjointEntities(allConstraintsa, v40, &v100, &v102);
      v41 = 0i64;
      v42 = v33;
      v43 = 0;
      v90 = v33;
      if ( v100.m_size > 0 )
      {
        while ( !v42 )
        {
          v44 = (unsigned __int64)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                                    &v81,
                                    (unsigned __int64)v100.m_data[v41]);
          v45 = (__int64)v104;
          v46 = SLODWORD(v81.m_elem[v44].val);
          v47 = *(_DWORD *)&v104[24 * v46];
          v48 = 24 * v46;
          if ( v47 != v112 )
          {
            if ( v47 == v36 )
            {
              v49 = v89;
              v33 = 1;
              v50 = 3i64 * v83;
              *(int *)((char *)&v85 + v89) = v83;
              resulta.m_enum = 1;
              *(_DWORD *)((char *)&v87 + v49) = *(_DWORD *)(v45 + 8 * v50 + 16) + 1;
              LODWORD(v50) = *(_DWORD *)(v45 + 24 * v46 + 16);
              v51 = v84;
              *(&v85 + v84) = v46;
              *((_DWORD *)&v87 + v51) = v50 + 1;
              v88 = v102.m_data[v41];
              goto LABEL_40;
            }
            if ( *((_DWORD *)v39 + 2) == (*((_DWORD *)v39 + 3) & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v39, 4);
            *(_DWORD *)&(*v39)[4 * (*((_DWORD *)v39 + 2))++] = v46;
            *(_DWORD *)&v104[v48] = v112;
            *(_DWORD *)&v104[v48 + 4] = *(_DWORD *)&(*v39)[4 * *(signed int *)((char *)&v82 + v89)];
            *(_QWORD *)&v104[v48 + 8] = v102.m_data[v41];
            *(_DWORD *)&v104[v48 + 16] = *(_DWORD *)&v104[24 * v83 + 16] + 1;
          }
          ++v43;
          ++v41;
          if ( v43 >= v100.m_size )
            break;
          v42 = v90;
        }
        v33 = resulta.m_enum;
      }
      v51 = v84;
LABEL_40:
      v34 = v36;
      v35 = v51;
      v112 = v36;
      if ( v33 )
      {
        v52 = entitiesOut;
        v53 = SHIDWORD(v87);
        v54 = v87;
        v55 = entitiesOut->m_capacityAndFlags;
        v56 = HIDWORD(v87) + v87;
        entitiesOut->m_size = 0;
        v57 = v55 & 0x3FFFFFFF;
        if ( v57 < v56 )
        {
          v58 = 2 * v57;
          v59 = v56;
          if ( v56 < v58 )
            v59 = v58;
          hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v52, v59, 8);
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
          hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v60, v64, 8);
        }
        v65 = v85;
        v60->m_size = v56;
        for ( i = v54 - 1; i > 0; v65 = *(_DWORD *)&v104[v67 + 4] )
        {
          v52->m_data[--i + 1] = (hkpEntity *)array[v65];
          v67 = 24i64 * v65;
          v60->m_data[i] = *(hkpConstraintInstance **)&v104[v67 + 8];
        }
        v68 = v53;
        *v52->m_data = (hkpEntity *)array[v65];
        v60->m_data[v54 - 1] = v88;
        v69 = v86;
        if ( (signed int)v53 > 0 )
        {
          v70 = v54;
          do
          {
            ++v70;
            v52->m_data[v70 - 1] = (hkpEntity *)array[v69];
            v71 = 24i64 * v69;
            v60->m_data[v70 - 1] = *(hkpConstraintInstance **)&v104[v71 + 8];
            v69 = *(_DWORD *)&v104[v71 + 4];
            --v68;
          }
          while ( v68 );
        }
        --v60->m_size;
        v72 = v102.m_capacityAndFlags;
        v109->m_enum = 0;
        v102.m_size = 0;
        if ( v72 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            v102.m_data,
            8 * v72);
        v102.m_data = 0i64;
        v102.m_capacityAndFlags = 2147483648;
        v100.m_size = 0;
        if ( v100.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            v100.m_data,
            8 * v100.m_capacityAndFlags);
        v100.m_data = 0i64;
        v100.m_capacityAndFlags = 2147483648;
        v73 = &v100.m_capacityAndFlags;
        do
        {
          v73 -= 36;
          v74 = *v73;
          *(v73 - 1) = 0;
          if ( v74 >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              *(void **)(v73 - 3),
              4 * v74);
          --v27;
          *(_QWORD *)(v73 - 3) = 0i64;
          *v73 = 2147483648;
        }
        while ( v27 >= 0 );
        v105 = 0;
        if ( v106 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            v104,
            24 * (v106 & 0x3FFFFFFF));
        v104 = 0i64;
        v106 = 2147483648;
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
          &v81,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
        _((AMD_HD3D *)&v81);
        v79 = 0;
        if ( v80 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            array,
            8 * v80);
        return v109;
      }
    }
    v75 = v102.m_capacityAndFlags;
    v102.m_size = 0;
    v109->m_enum = 1;
    if ( v75 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v102.m_data,
        8 * v75);
    v102.m_data = 0i64;
    v102.m_capacityAndFlags = 2147483648;
    v100.m_size = 0;
    if ( v100.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v100.m_data,
        8 * v100.m_capacityAndFlags);
    v100.m_data = 0i64;
    v100.m_capacityAndFlags = 2147483648;
    v76 = &v100.m_capacityAndFlags;
    do
    {
      v76 -= 36;
      v77 = *v76;
      *(v76 - 1) = 0;
      if ( v77 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          *(void **)(v76 - 3),
          4 * v77);
      --v27;
      *(_QWORD *)(v76 - 3) = 0i64;
      *v76 = 2147483648;
    }
    while ( v27 >= 0 );
    v105 = 0;
    if ( v106 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v104,
        24 * (v106 & 0x3FFFFFFF));
    v104 = 0i64;
    v106 = 2147483648;
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
      &v81,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
    _((AMD_HD3D *)&v81);
    v79 = 0;
    if ( v80 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        array,
        8 * v80);
    v10 = v109;
  }
  return v10;
}0x3FFFFFFF));
    v104 = 0i64;
    v106 = 2147483648;
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
      &v81,
      (hkMemoryAlloca

// File Line: 477
// RVA: 0xE243B0
void __fastcall hkpConstraintChainUtil::getAdjointEntities(hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *allConstraints, hkpEntity *entity, hkArray<hkpEntity *,hkContainerHeapAllocator> *entitiesOut, hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *constraintsOut)
{
  int v4; // esi
  hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *v5; // rbx
  hkArray<hkpEntity *,hkContainerHeapAllocator> *v6; // r14
  hkpEntity *v7; // r12
  hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *v8; // r13
  __int64 v9; // r15
  hkpConstraintInstance *v10; // rdi
  hkpEntity *v11; // rax
  hkpEntity *v12; // rbp

  v4 = 0;
  v5 = constraintsOut;
  v6 = entitiesOut;
  v7 = entity;
  v8 = allConstraints;
  if ( allConstraints->m_size > 0 )
  {
    v9 = 0i64;
    do
    {
      v10 = v8->m_data[v9];
      v11 = v10->m_entities[0];
      if ( v11 == v7 || v10->m_entities[1] == v7 )
      {
        v12 = (hkpEntity *)((unsigned __int64)v7 ^ (unsigned __int64)v11 ^ (_QWORD)v10->m_entities[1]);
        if ( v6->m_size == (v6->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v6, 8);
        v6->m_data[v6->m_size++] = v12;
        if ( v5->m_size == (v5->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v5, 8);
        v5->m_data[v5->m_size++] = v10;
      }
      ++v4;
      ++v9;
    }
    while ( v4 < v8->m_size );
  }
}

