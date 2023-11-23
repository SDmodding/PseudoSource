// File Line: 58
// RVA: 0x66B3C0
void __fastcall UFG::VehicleFormations::VehicleFormations(
        UFG::VehicleFormations *this,
        UFG::VehicleSubjectComponent *pSubject,
        UFG::qList<UFG::SimObjectPointer,UFG::SimObjectPointer,1,0> *list)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> (*mSlots)[7]; // rbx
  UFG::VehicleFormationCombatStats *p_mCombatStats; // rax
  __int64 v6; // rcx
  bool (*mSlotUsableProcessed)[7]; // rdx
  __int64 v8; // r9
  __int64 v9; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rax
  int v12; // esi
  float *p_z; // rbx
  bool v14; // al
  UFG::qVector3 *CombatOffset; // rax
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::qVector3 result; // [rsp+38h] [rbp-30h] BYREF

  this->mpSubject = pSubject;
  this->mpVehicles = list;
  this->mHeuristic = FORMATIONHEURISTIC_GENERIC;
  this->mpSecondaryTarget.mPrev = &this->mpSecondaryTarget;
  this->mpSecondaryTarget.mNext = &this->mpSecondaryTarget;
  this->mpSecondaryTarget.m_pPointer = 0i64;
  this->mpClosestToSecondaryTarget.mPrev = &this->mpClosestToSecondaryTarget;
  this->mpClosestToSecondaryTarget.mNext = &this->mpClosestToSecondaryTarget;
  this->mpClosestToSecondaryTarget.m_pPointer = 0i64;
  mSlots = this->mSlots;
  `eh vector constructor iterator(
    this->mSlots,
    0x18ui64,
    14,
    (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>);
  p_mCombatStats = &this->mCombatStats;
  v6 = 4i64;
  do
  {
    p_mCombatStats->mLastAttack[0] = 0.0;
    p_mCombatStats->mNumAttacks[0] = 0;
    p_mCombatStats = (UFG::VehicleFormationCombatStats *)((char *)p_mCombatStats + 4);
    --v6;
  }
  while ( v6 );
  this->mCurrentAttack = NumFormationAttacks;
  this->mpClosestSegment = 0i64;
  *(_QWORD *)&this->mClosestLaneIndex = 0i64;
  *(_QWORD *)&this->mTimeSinceFormationRequest = 0i64;
  this->mParticipantCount = 0;
  *(_DWORD *)&this->mCustomFormation = 0x1000000;
  mSlotUsableProcessed = this->mSlotUsableProcessed;
  v8 = 2i64;
  do
  {
    v9 = 7i64;
    do
    {
      if ( (*mSlots)[0].m_pPointer )
      {
        mPrev = (*mSlots)[0].mPrev;
        v11 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)*((_QWORD *)mSlots + 1);
        mPrev->mNext = v11;
        v11->mPrev = mPrev;
        (*mSlots)[0].mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)mSlots;
        (*mSlots)[0].mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)mSlots;
      }
      (*mSlots)[0].m_pPointer = 0i64;
      (*mSlotUsableProcessed)[-14] = 1;
      *(_BYTE *)mSlotUsableProcessed = 1;
      (*mSlotUsableProcessed)[14] = 0;
      (*mSlotUsableProcessed)[28] = 0;
      mSlots = (UFG::qSafePointer<UFG::SimObject,UFG::SimObject> (*)[7])((char *)mSlots + 24);
      mSlotUsableProcessed = (bool (*)[7])((char *)mSlotUsableProcessed + 1);
      --v9;
    }
    while ( v9 );
    --v8;
  }
  while ( v8 );
  v12 = 0;
  p_z = &this->mSlotOffsets[0].z;
  do
  {
    if ( !this->mpSubject->pPhysicsMover.m_pSimComponent
      || (v14 = 1, LODWORD(this->mpSubject->pPhysicsMover.m_pSimComponent[12].m_BoundComponentHandles.mNode.mNext)) )
    {
      v14 = 0;
    }
    CombatOffset = UFG::AiDriverComponent::GetCombatOffset(&result, 0, v12, v14);
    y = CombatOffset->y;
    z = CombatOffset->z;
    *(p_z - 2) = CombatOffset->x;
    *(p_z - 1) = y;
    *p_z = z;
    ++v12;
    p_z += 3;
  }
  while ( v12 < 7 );
}

// File Line: 89
// RVA: 0x685DC0
void __fastcall UFG::VehicleFormations::OverrideSlotOffsets(
        UFG::VehicleFormations *this,
        UFG::qPropertySet *pSlotOffsetProperties)
{
  UFG::qArray<unsigned long,0> **v3; // rdi
  float *p_z; // rbx
  UFG::qVector3 *v5; // rax
  float y; // xmm0_4
  float z; // xmm1_4

  v3 = (UFG::qArray<unsigned long,0> **)VehicleFormations_SlotOffsetSymbols;
  p_z = &this->mSlotOffsets[0].z;
  do
  {
    v5 = UFG::qPropertySet::Get<UFG::qVector3>(pSlotOffsetProperties, *v3, DEPTH_RECURSE);
    if ( v5 )
    {
      y = v5->y;
      z = v5->z;
      *(p_z - 2) = v5->x;
      *(p_z - 1) = y;
      *p_z = z;
    }
    ++v3;
    p_z += 3;
  }
  while ( (__int64)v3 < (__int64)&UFG::CarPhysicsMoverComponent::_TypeName );
}

// File Line: 116
// RVA: 0x6740A0
float __fastcall UFG::VehicleFormations::CalculateSecondaryTargetScore(
        UFG::VehicleFormations *this,
        UFG::qVector3 *myPosition,
        UFG::qVector3 *slotPosition,
        UFG::qVector3 *secondaryTargetPosition)
{
  float v5; // xmm3_4
  float v6; // xmm5_4
  float y; // xmm9_4
  __m128 y_low; // xmm4
  float v9; // xmm6_4
  __m128 v10; // xmm2
  float v11; // xmm1_4
  __m128 v12; // xmm2
  float v13; // xmm11_4
  float v14; // xmm4_4
  float v15; // xmm5_4
  float v16; // xmm6_4
  int v17; // xmm11_4
  float v18; // xmm7_4
  __m128 v19; // xmm9

  if ( this->mHeuristic != FORMATIONHEURISTIC_ESCORT )
    return 0.0;
  y_low = (__m128)LODWORD(slotPosition->y);
  v5 = 0.0;
  v6 = slotPosition->z - myPosition->z;
  y = myPosition->y;
  y_low.m128_f32[0] = y_low.m128_f32[0] - y;
  v9 = slotPosition->x - myPosition->x;
  v10 = y_low;
  v10.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v9 * v9)) + (float)(v6 * v6);
  if ( v10.m128_f32[0] == 0.0 )
    v11 = 0.0;
  else
    v11 = 1.0 / _mm_sqrt_ps(v10).m128_f32[0];
  v12 = (__m128)LODWORD(secondaryTargetPosition->y);
  v12.m128_f32[0] = v12.m128_f32[0] - y;
  v13 = v11 * v9;
  LODWORD(v14) = COERCE_UNSIGNED_INT(y_low.m128_f32[0] * v11) ^ _xmm[0];
  LODWORD(v15) = COERCE_UNSIGNED_INT(v6 * v11) ^ _xmm[0];
  v16 = secondaryTargetPosition->x - myPosition->x;
  v19 = v12;
  v17 = LODWORD(v13) ^ _xmm[0];
  v18 = secondaryTargetPosition->z - myPosition->z;
  v19.m128_f32[0] = (float)((float)(v12.m128_f32[0] * v12.m128_f32[0]) + (float)(v16 * v16)) + (float)(v18 * v18);
  if ( v19.m128_f32[0] != 0.0 )
    v5 = 1.0 / _mm_sqrt_ps(v19).m128_f32[0];
  return (float)((float)((float)((float)((float)(v12.m128_f32[0] * v5) * v14)
                               + (float)((float)(v16 * v5) * *(float *)&v17))
                       + (float)((float)(v18 * v5) * v15))
               + 1.0)
       * 0.5;
}

// File Line: 142
// RVA: 0x6957C0
void __fastcall UFG::VehicleFormations::UpdateClosestToSecondaryTarget(
        UFG::VehicleFormations *this,
        int vehicleCount,
        UFG::VehicleFormations::VehicleSlotDef *slots,
        UFG::SimObjectVehicle *pSecondaryTarget,
        UFG::qVector3 *secondaryTargetPosition)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mpClosestToSecondaryTarget; // rdx
  float v10; // xmm3_4
  int v11; // edx
  int v12; // ecx
  __int64 v13; // rax
  float x; // xmm4_4
  float y; // xmm5_4
  float z; // xmm6_4
  float *p_z; // r8
  int v18; // r9d
  float v19; // xmm4_4
  float v20; // xmm5_4
  float *v21; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v22; // r8
  UFG::SimObjectCVBase *vehicle; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v24; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v25; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v26; // rax
  __int16 m_Flags; // cx
  UFG::AiDriverComponent *ComponentOfTypeHK; // rax
  UFG::AiDriverComponent *v29; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax

  if ( this->mHeuristic != FORMATIONHEURISTIC_ESCORT )
  {
    p_mpClosestToSecondaryTarget = &this->mpClosestToSecondaryTarget;
LABEL_34:
    if ( p_mpClosestToSecondaryTarget->m_pPointer )
    {
      mPrev = p_mpClosestToSecondaryTarget->mPrev;
      mNext = p_mpClosestToSecondaryTarget->mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_mpClosestToSecondaryTarget->mPrev = p_mpClosestToSecondaryTarget;
      p_mpClosestToSecondaryTarget->mNext = p_mpClosestToSecondaryTarget;
    }
    p_mpClosestToSecondaryTarget->m_pPointer = 0i64;
    return;
  }
  v10 = FLOAT_3_4028235e38;
  v11 = -1;
  if ( !pSecondaryTarget )
    goto LABEL_33;
  v12 = 0;
  v13 = 0i64;
  if ( vehicleCount >= 4 )
  {
    x = secondaryTargetPosition->x;
    y = secondaryTargetPosition->y;
    z = secondaryTargetPosition->z;
    p_z = &slots->vehiclePosition.z;
    v18 = 2;
    v13 = 4i64 * (((unsigned int)(vehicleCount - 4) >> 2) + 1);
    do
    {
      if ( (float)((float)((float)((float)(y - *(p_z - 1)) * (float)(y - *(p_z - 1)))
                         + (float)((float)(x - *(p_z - 2)) * (float)(x - *(p_z - 2))))
                 + (float)((float)(z - *p_z) * (float)(z - *p_z))) < v10 )
      {
        v10 = (float)((float)((float)(y - *(p_z - 1)) * (float)(y - *(p_z - 1)))
                    + (float)((float)(x - *(p_z - 2)) * (float)(x - *(p_z - 2))))
            + (float)((float)(z - *p_z) * (float)(z - *p_z));
        v11 = v12;
      }
      if ( (float)((float)((float)((float)(y - p_z[7]) * (float)(y - p_z[7]))
                         + (float)((float)(x - p_z[6]) * (float)(x - p_z[6])))
                 + (float)((float)(z - p_z[8]) * (float)(z - p_z[8]))) < v10 )
      {
        v10 = (float)((float)((float)(y - p_z[7]) * (float)(y - p_z[7]))
                    + (float)((float)(x - p_z[6]) * (float)(x - p_z[6])))
            + (float)((float)(z - p_z[8]) * (float)(z - p_z[8]));
        v11 = v18 - 1;
      }
      if ( (float)((float)((float)((float)(y - p_z[15]) * (float)(y - p_z[15]))
                         + (float)((float)(x - p_z[14]) * (float)(x - p_z[14])))
                 + (float)((float)(z - p_z[16]) * (float)(z - p_z[16]))) < v10 )
      {
        v10 = (float)((float)((float)(y - p_z[15]) * (float)(y - p_z[15]))
                    + (float)((float)(x - p_z[14]) * (float)(x - p_z[14])))
            + (float)((float)(z - p_z[16]) * (float)(z - p_z[16]));
        v11 = v18;
      }
      if ( (float)((float)((float)((float)(y - p_z[23]) * (float)(y - p_z[23]))
                         + (float)((float)(x - p_z[22]) * (float)(x - p_z[22])))
                 + (float)((float)(z - p_z[24]) * (float)(z - p_z[24]))) < v10 )
      {
        v10 = (float)((float)((float)(y - p_z[23]) * (float)(y - p_z[23]))
                    + (float)((float)(x - p_z[22]) * (float)(x - p_z[22])))
            + (float)((float)(z - p_z[24]) * (float)(z - p_z[24]));
        v11 = v18 + 1;
      }
      v12 += 4;
      p_z += 32;
      v18 += 4;
    }
    while ( v12 < vehicleCount - 3 );
  }
  if ( v12 < vehicleCount )
  {
    v21 = &slots[v13].vehiclePosition.z;
    do
    {
      v19 = secondaryTargetPosition->x;
      v20 = secondaryTargetPosition->y;
      if ( (float)((float)((float)((float)(v20 - *(v21 - 1)) * (float)(v20 - *(v21 - 1)))
                         + (float)((float)(v19 - *(v21 - 2)) * (float)(v19 - *(v21 - 2))))
                 + (float)((float)(secondaryTargetPosition->z - *v21) * (float)(secondaryTargetPosition->z - *v21))) < v10 )
      {
        v10 = (float)((float)((float)(v20 - *(v21 - 1)) * (float)(v20 - *(v21 - 1)))
                    + (float)((float)(v19 - *(v21 - 2)) * (float)(v19 - *(v21 - 2))))
            + (float)((float)(secondaryTargetPosition->z - *v21) * (float)(secondaryTargetPosition->z - *v21));
        v11 = v12;
      }
      ++v12;
      v21 += 8;
    }
    while ( v12 < vehicleCount );
  }
  if ( v11 == -1 )
  {
LABEL_33:
    p_mpClosestToSecondaryTarget = &this->mpClosestToSecondaryTarget;
    goto LABEL_34;
  }
  v22 = &this->mpClosestToSecondaryTarget;
  vehicle = (UFG::SimObjectCVBase *)slots[v11].vehicle;
  if ( this->mpClosestToSecondaryTarget.m_pPointer )
  {
    v24 = v22->mPrev;
    v25 = this->mpClosestToSecondaryTarget.mNext;
    v24->mNext = v25;
    v25->mPrev = v24;
    v22->mPrev = v22;
    this->mpClosestToSecondaryTarget.mNext = &this->mpClosestToSecondaryTarget;
  }
  this->mpClosestToSecondaryTarget.m_pPointer = vehicle;
  if ( vehicle )
  {
    v26 = vehicle->m_SafePointerList.UFG::SimObjectGame::UFG::SimObject::UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    v26->mNext = v22;
    v22->mPrev = v26;
    this->mpClosestToSecondaryTarget.mNext = &vehicle->m_SafePointerList.UFG::SimObjectGame::UFG::SimObject::UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
    vehicle->m_SafePointerList.UFG::SimObjectGame::UFG::SimObject::UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = v22;
    m_Flags = vehicle->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(vehicle);
    }
    else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      vehicle,
                                                      UFG::AiDriverComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                                      vehicle,
                                                      UFG::AiDriverComponent::_TypeUID);
    }
    v29 = ComponentOfTypeHK;
    if ( ComponentOfTypeHK )
    {
      UFG::AiDriverComponent::SetEscortEnemy(ComponentOfTypeHK, pSecondaryTarget);
      UFG::AiDriverComponent::UpdateEscortOffset(v29, 0.0);
    }
  }
}

// File Line: 225
// RVA: 0x698B80
void __fastcall UFG::VehicleFormations::UpdateSlots(UFG::VehicleFormations *this, float deltaTime)
{
  UFG::VehicleFormations *v3; // r13
  UFG::qList<UFG::SimObjectPointer,UFG::SimObjectPointer,1,0> *mpVehicles; // r8
  int v5; // edx
  UFG::qList<UFG::SimObjectPointer,UFG::SimObjectPointer,1,0> *i; // rax
  unsigned __int64 v7; // rax
  UFG::allocator::free_link *v8; // rdi
  UFG::SimObject *m_pPointer; // rcx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  int v11; // r15d
  int v12; // r12d
  __int64 v13; // rax
  float v14; // xmm1_4
  int v15; // xmm2_4
  __int64 v16; // rax
  float v17; // xmm1_4
  float v18; // xmm2_4
  __int64 v19; // rax
  float v20; // xmm1_4
  float v21; // xmm2_4
  UFG::qList<UFG::SimObjectPointer,UFG::SimObjectPointer,1,0> *v22; // rax
  UFG::qList<UFG::SimObjectPointer,UFG::SimObjectPointer,1,0> *mNext; // r14
  UFG::allocator::free_link *v24; // rbx
  UFG::allocator::free_link *mPrev; // rsi
  UFG::allocator::free_link *v26; // rdi
  int mNext_high; // xmm0_4
  int v28; // xmm1_4
  UFG::allocator::free_link *v29; // rcx
  float v30; // xmm0_4
  int v31; // eax
  char (*mSlotWeight)[7]; // rcx
  __int64 v33; // rdx
  __int64 v34; // rax
  char v35; // r15
  UFG::RoadSpaceComponent *v36; // rdx
  char *p_z; // r8
  char *v38; // r12
  char *v39; // rdi
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v40; // rbx
  float *v41; // rsi
  __int64 v42; // rax
  char *v43; // r14
  __int64 v44; // r13
  float v45; // xmm1_4
  UFG::qVector3 *v46; // rax
  float y; // xmm0_4
  float z; // xmm1_4
  UFG::SimObject *v49; // r8
  char v50; // al
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v51; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v52; // rax
  __int64 v53; // rcx
  float *v54; // rax
  UFG::SimObject *v55; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v56; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v57; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v58; // rax
  int v59; // ebx
  unsigned __int64 v60; // rax
  char *v61; // rcx
  int v62; // r13d
  UFG::RoadSpaceComponent *p_myPosition_4; // r8
  int v64; // r9d
  char *v65; // r10
  UFG::qVector3 *p_world_pos; // r15
  float v67; // xmm7_4
  float v68; // eax
  __int64 v69; // rdi
  int v70; // edx
  __int64 v71; // r14
  int v72; // r12d
  float *v73; // r14
  float *v74; // rsi
  char *v75; // rbx
  UFG::VehicleFormations *v76; // rax
  float v77; // xmm6_4
  float v78; // xmm0_4
  int v79; // edx
  unsigned __int64 v80; // rax
  Render::DebugDrawContext *Context; // rbx
  int mTargetHeight; // ecx
  UFG::BaseCameraComponent *mCurrentCamera; // rcx
  UFG::Camera *p_mCamera; // rcx
  UFG::BaseCameraComponent *v85; // rcx
  UFG::Camera *v86; // rcx
  UFG::qVector3 *ScreenCoord; // rax
  float v88; // xmm1_4
  float v89; // xmm0_4
  float x; // xmm2_4
  float v91; // xmm2_4
  UFG::RoadSpaceComponent *v92; // r12
  UFG::allocator::free_link *v93; // rsi
  __int64 v94; // r11
  __int64 v95; // rbx
  __int64 v96; // r10
  float v97; // xmm0_4
  __int64 v98; // rcx
  __int64 v99; // r9
  int v100; // r13d
  char *v101; // rax
  int v102; // r15d
  __int64 v103; // r8
  int v104; // eax
  __int64 v105; // r14
  float *v106; // rdi
  char *v107; // rdx
  float *v108; // rdi
  _BYTE *v109; // rdx
  __int64 v110; // r10
  UFG::SimObject *v111; // r8
  __int64 v112; // r11
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v113; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v114; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v115; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v116; // rax
  signed __int32 v117; // r14d
  float *v118; // r15
  UFG::SimObject **p_m_pPointer; // rsi
  signed __int32 v120; // edi
  float *v121; // rbx
  UFG::SimObjectCVBase *v122; // rcx
  __int16 m_Flags; // dx
  UFG::AiDriverComponent *v124; // rax
  float v125; // xmm1_4
  float v126; // xmm6_4
  float v127; // xmm7_4
  char *v128; // rsi
  float *v129; // rdi
  UFG::SimObjectCVBase *v130; // rcx
  __int16 v131; // dx
  UFG::AiDriverComponent *v132; // rax
  UFG::AiDriverComponent *v133; // rbx
  char v134[4]; // [rsp+0h] [rbp-1C8h] BYREF
  char v135[4]; // [rsp+4h] [rbp-1C4h] BYREF
  char v136[280]; // [rsp+8h] [rbp-1C0h] BYREF
  bool pIsRightOpen; // [rsp+130h] [rbp-98h] BYREF
  bool v138; // [rsp+131h] [rbp-97h]
  int v139; // [rsp+134h] [rbp-94h]
  int v140; // [rsp+138h] [rbp-90h]
  UFG::qVector3 v2; // [rsp+140h] [rbp-88h] BYREF
  float myPosition; // [rsp+150h] [rbp-78h] BYREF
  float myPosition_4; // [rsp+154h] [rbp-74h] BYREF
  UFG::allocator::free_link *myPosition_8; // [rsp+158h] [rbp-70h]
  UFG::RoadSpaceComponent *m_pSimComponent; // [rsp+160h] [rbp-68h]
  char *v146; // [rsp+168h] [rbp-60h]
  char *v147; // [rsp+170h] [rbp-58h]
  UFG::qVector2 viewport_scale; // [rsp+178h] [rbp-50h] BYREF
  UFG::qVector3 v1; // [rsp+180h] [rbp-48h] BYREF
  UFG::qVector3 v150; // [rsp+190h] [rbp-38h] BYREF
  char v151[6]; // [rsp+1A0h] [rbp-28h] BYREF
  char v152[10]; // [rsp+1A6h] [rbp-22h] BYREF
  UFG::SimObject *pSecondaryTarget; // [rsp+1B0h] [rbp-18h]
  UFG::qVector3 result; // [rsp+1B8h] [rbp-10h] BYREF
  __int64 v155; // [rsp+1C8h] [rbp+0h]
  UFG::qVector3 world_pos; // [rsp+1D8h] [rbp+10h] BYREF
  UFG::VehicleFormations *v157; // [rsp+338h] [rbp+170h]
  bool is_on_screen[8]; // [rsp+348h] [rbp+180h] BYREF
  bool pIsLeftOpen[4]; // [rsp+350h] [rbp+188h] BYREF

  v155 = -2i64;
  v3 = this;
  mpVehicles = this->mpVehicles;
  v5 = 0;
  for ( i = (UFG::qList<UFG::SimObjectPointer,UFG::SimObjectPointer,1,0> *)mpVehicles->mNode.mNext;
        i != mpVehicles;
        i = (UFG::qList<UFG::SimObjectPointer,UFG::SimObjectPointer,1,0> *)i->mNode.mNext )
  {
    ++v5;
  }
  v7 = 32i64 * v5;
  if ( !is_mul_ok(v5, 0x20ui64) )
    v7 = -1i64;
  v8 = UFG::qMalloc(v7, UFG::gGlobalNewName, 0i64);
  myPosition_8 = v8;
  m_pPointer = v3->mpSecondaryTarget.m_pPointer;
  pSecondaryTarget = m_pPointer;
  v138 = m_pPointer != 0i64;
  if ( m_pPointer )
    m_pTransformNodeComponent = m_pPointer->m_pTransformNodeComponent;
  else
    m_pTransformNodeComponent = 0i64;
  if ( m_pPointer )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
    viewport_scale = (UFG::qVector2)&m_pTransformNodeComponent->mWorldTransform.v3;
  }
  else
  {
    viewport_scale = (UFG::qVector2)&UFG::qVector3::msZero;
  }
  v11 = 0;
  v139 = 0;
  myPosition = 0.0;
  v12 = 0;
  v140 = 0;
  v3->mParticipantCount = 0;
  v13 = ((__int64 (__fastcall *)(UFG::VehicleSubjectComponent *))v3->mpSubject->vfptr[17].__vecDelDtor)(v3->mpSubject);
  v14 = *(float *)(v13 + 4);
  v15 = *(_DWORD *)(v13 + 8);
  myPosition = *(float *)v13;
  myPosition_4 = v14;
  LODWORD(myPosition_8) = v15;
  v16 = ((__int64 (__fastcall *)(UFG::VehicleSubjectComponent *))v3->mpSubject->vfptr[16].__vecDelDtor)(v3->mpSubject);
  v17 = *(float *)(v16 + 4);
  v18 = *(float *)(v16 + 8);
  v1.x = *(float *)v16;
  v1.y = v17;
  v1.z = v18;
  v19 = ((__int64 (__fastcall *)(UFG::VehicleSubjectComponent *))v3->mpSubject->vfptr[15].__vecDelDtor)(v3->mpSubject);
  v20 = *(float *)(v19 + 4);
  v21 = *(float *)(v19 + 8);
  v150.x = *(float *)v19;
  v150.y = v20;
  v150.z = v21;
  m_pSimComponent = (UFG::RoadSpaceComponent *)v3->mpSubject->pRoadSpace.m_pSimComponent;
  v22 = v3->mpVehicles;
  mNext = (UFG::qList<UFG::SimObjectPointer,UFG::SimObjectPointer,1,0> *)v22->mNode.mNext;
  if ( mNext != v22 )
  {
    v24 = v8 + 2;
    do
    {
      mPrev = (UFG::allocator::free_link *)mNext[1].mNode.mPrev;
      if ( mPrev )
      {
        v26 = mPrev[13].mNext[4].mNext;
        if ( v26 )
        {
          v24[-2].mNext = mPrev;
          UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v26);
          mNext_high = HIDWORD(v26[22].mNext);
          v28 = (int)v26[23].mNext;
          LODWORD(v24[-1].mNext) = v26[22].mNext;
          HIDWORD(v24[-1].mNext) = mNext_high;
          LODWORD(v24->mNext) = v28;
          v29 = mPrev[13].mNext[48].mNext;
          if ( v29 && ((__int64)v29[243].mNext & 2) != 0 )
          {
            BYTE4(v24[1].mNext) = 1;
            ++v3->mParticipantCount;
          }
          else
          {
            BYTE4(v24[1].mNext) = 0;
          }
          v2.x = myPosition - *(float *)&v24[-1].mNext;
          v2.y = myPosition_4 - *((float *)&v24[-1].mNext + 1);
          v2.z = *(float *)&myPosition_8 - *(float *)&v24->mNext;
          *((float *)&v24->mNext + 1) = UFG::qAngleBetween(&v1, &v2);
          v30 = UFG::qAngleBetween(&v150, &v2);
          v31 = 0;
          LOBYTE(v31) = v30 <= 1.5707964;
          LODWORD(v24[1].mNext) = v31;
          ++v12;
          v24 += 4;
        }
      }
      mNext = (UFG::qList<UFG::SimObjectPointer,UFG::SimObjectPointer,1,0> *)mNext->mNode.mNext;
    }
    while ( mNext != v3->mpVehicles );
    v140 = v12;
  }
  UFG::VehicleFormations::UpdateUsableLaneInfo(
    v3,
    deltaTime,
    (UFG::qVector3 *)&myPosition,
    &v1,
    pIsLeftOpen,
    &pIsRightOpen);
  LOBYTE(myPosition_4) = pIsLeftOpen[0];
  BYTE1(myPosition_4) = pIsRightOpen;
  if ( v12 > 0 )
  {
    is_on_screen[0] = 0;
    mSlotWeight = v3->mSlotWeight;
    v33 = 2i64;
    do
    {
      v34 = 6i64;
      while ( (*mSlotWeight)[v34] <= 0 )
      {
        if ( --v34 < 0 )
          goto LABEL_29;
      }
      is_on_screen[0] = 1;
LABEL_29:
      ++mSlotWeight;
      --v33;
    }
    while ( v33 );
    v35 = 1;
    v36 = 0i64;
    m_pSimComponent = 0i64;
    p_z = (char *)&v3->mSlotOffsets[6].z;
    v146 = (char *)&v3->mSlotOffsets[6].z;
    v38 = (char *)(v152 - (char *)v3);
    do
    {
      v39 = (char *)&v3->mSlotUsableProcessed[(_QWORD)v36][6];
      v40 = &v3->mSlots[(_QWORD)v36][6];
      v41 = (float *)p_z;
      v42 = 84i64 * (_QWORD)v36 - (_QWORD)v3;
      v147 = &v135[v42];
      viewport_scale = (UFG::qVector2)&v136[v42];
      v43 = &v134[v42];
      v44 = -422 - 7i64 * (_QWORD)v36 - (_QWORD)v157;
      do
      {
        v2.x = *(v41 - 2);
        v45 = *(v41 - 1);
        v2.y = v45;
        v2.z = *v41;
        if ( v36 == (UFG::RoadSpaceComponent *)1 )
          LODWORD(v2.y) = LODWORD(v45) ^ _xmm[0];
        v46 = UFG::RoadSpaceComponent::ChaseToWorld(m_pSimComponent, &result, &v2, 0i64);
        y = v46->y;
        z = v46->z;
        *(float *)((char *)v41 + (_QWORD)v43) = v46->x;
        *(float *)((char *)v41 + (_QWORD)v147) = y;
        *(float *)((char *)v41 + *(_QWORD *)&viewport_scale) = z;
        v49 = v40->m_pPointer;
        if ( is_on_screen[0] )
          v50 = *(v39 - 14) && v39[v44 + 450 + (_QWORD)v147] > 0;
        else
          v50 = *(v39 - 14);
        *v39 = v50;
        if ( !pIsLeftOpen[0] && !pIsRightOpen )
          *v39 = 0;
        v147[422] = 0;
        v38[(_QWORD)v39 - 428] = *v39;
        if ( v40->m_pPointer )
        {
          v51 = v40->mPrev;
          v52 = v40->mNext;
          v51->mNext = v52;
          v52->mPrev = v51;
          v40->mPrev = v40;
          v40->mNext = v40;
        }
        v40->m_pPointer = 0i64;
        if ( v35 )
        {
          if ( v49 )
          {
            if ( v38[(_QWORD)v39 - 428] )
            {
              v53 = 0i64;
              if ( (__int64)v146 > 0 )
              {
                v54 = (float *)&myPosition_8[2];
                while ( 1 )
                {
                  v55 = (UFG::SimObject *)*((_QWORD *)v54 - 2);
                  if ( v49 == v55
                    && (float)((float)((float)((float)(*(float *)((char *)v41 + (_QWORD)v43 + 4) - *(v54 - 1))
                                             * (float)(*(float *)((char *)v41 + (_QWORD)v43 + 4) - *(v54 - 1)))
                                     + (float)((float)(*(float *)((char *)v41 + (_QWORD)v43) - *(v54 - 2))
                                             * (float)(*(float *)((char *)v41 + (_QWORD)v43) - *(v54 - 2))))
                             + (float)((float)(*(float *)((char *)v41 + (_QWORD)v43 + 8) - *v54)
                                     * (float)(*(float *)((char *)v41 + (_QWORD)v43 + 8) - *v54))) < sFAVOR_EXISTING_SLOT_DISTANCE_SQ )
                  {
                    break;
                  }
                  ++v53;
                  v54 += 8;
                  if ( v53 >= (__int64)v146 )
                    goto LABEL_59;
                }
                BYTE4(myPosition_8[4 * v53 + 3].mNext) = 0;
                v38[(_QWORD)v39 - 428] = 0;
                if ( v40->m_pPointer )
                {
                  v56 = v40->mPrev;
                  v57 = v40->mNext;
                  v56->mNext = v57;
                  v57->mPrev = v56;
                  v40->mPrev = v40;
                  v40->mNext = v40;
                }
                v40->m_pPointer = v55;
                if ( v55 )
                {
                  v58 = v55->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
                  v58->mNext = v40;
                  v40->mPrev = v58;
                  v40->mNext = &v55->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
                  v55->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = v40;
                }
                ++v139;
                ++LODWORD(myPosition);
              }
            }
          }
LABEL_59:
          if ( v38[(_QWORD)v39 - 428] )
            v35 = 0;
        }
        --v40;
        v41 -= 3;
        --v39;
        v36 = m_pSimComponent;
      }
      while ( (__int64)&v39[v44] >= 0 );
      v36 = (UFG::RoadSpaceComponent *)((char *)&m_pSimComponent->vfptr + 1);
      m_pSimComponent = v36;
      p_z = v146;
      v3 = v157;
    }
    while ( (__int64)v36 < 2 );
    v59 = v140;
    v60 = 56i64 * v140;
    if ( !is_mul_ok(14 * v140, 4ui64) )
      v60 = -1i64;
    v61 = (char *)UFG::qMalloc(v60, "VehicleFormations", 0i64);
    v62 = 0;
    p_myPosition_4 = (UFG::RoadSpaceComponent *)&myPosition_4;
    m_pSimComponent = (UFG::RoadSpaceComponent *)&myPosition_4;
    v64 = 0;
    LODWORD(v146) = 0;
    v65 = v151;
    v147 = v151;
    p_world_pos = &world_pos;
    v67 = sVEHICLEFORMATION_DISABLED_WEIGHT;
LABEL_66:
    v68 = 0.0;
    v2.z = 0.0;
    v69 = 0i64;
    v70 = 6;
    *(_DWORD *)pIsLeftOpen = 6;
    while ( 1 )
    {
      v71 = (__int64)v146;
      if ( v65[v69] )
      {
        ++v139;
        v72 = 0;
        if ( (__int64)v146 > 0 )
          break;
      }
LABEL_108:
      ++LODWORD(v68);
      v2.z = v68;
      *(_DWORD *)pIsLeftOpen = --v70;
      ++v69;
      ++p_world_pos;
      if ( v69 >= 7 )
      {
        ++v62;
        v64 += 7;
        LODWORD(v146) = v64;
        v65 += 7;
        v147 = v65;
        p_myPosition_4 = (UFG::RoadSpaceComponent *)((char *)p_myPosition_4 + 1);
        m_pSimComponent = p_myPosition_4;
        if ( v64 >= 14 )
        {
          v91 = sMAX_DIST_SQ_FOR_FORMATION;
          v92 = m_pSimComponent;
          v93 = myPosition_8;
          while ( 1 )
          {
            v94 = -1i64;
            v95 = -1i64;
            v96 = -1i64;
            v97 = v91;
            v98 = 0i64;
            v99 = 0i64;
            v100 = 0;
            v101 = v151;
            *(_QWORD *)is_on_screen = v151;
            do
            {
              v102 = 6;
              v103 = 6i64;
              do
              {
                if ( v101[v103] )
                {
                  v104 = v140 * (v102 + v100);
                  if ( v71 >= 4 )
                  {
                    v105 = v71 - 3;
                    v106 = (float *)((char *)v92 + 4 * v104);
                    v107 = (char *)&myPosition_8[7].mNext + 4;
                    do
                    {
                      if ( *(v107 - 32) && *v106 < v97 )
                      {
                        v94 = v99;
                        v95 = v103;
                        v96 = v98;
                        v97 = *v106;
                      }
                      if ( *v107 && v106[1] < v97 )
                      {
                        v94 = v99;
                        v95 = v103;
                        v96 = v98 + 1;
                        v97 = v106[1];
                      }
                      if ( v107[32]
                        && *((float *)&v92->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev
                           + v98
                           + v104) < v97 )
                      {
                        v94 = v99;
                        v95 = v103;
                        v96 = v98 + 2;
                        v97 = *((float *)&v92->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev
                              + v98
                              + v104);
                      }
                      if ( v107[64]
                        && *((float *)&v92->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev
                           + v98
                           + v104
                           + 1) < v97 )
                      {
                        v94 = v99;
                        v95 = v103;
                        v96 = v98 + 3;
                        v97 = *((float *)&v92->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev
                              + v98
                              + v104
                              + 1);
                      }
                      v98 += 4i64;
                      v106 += 4;
                      v107 += 128;
                    }
                    while ( v98 < v105 );
                    v71 = (__int64)v146;
                  }
                  if ( v98 >= v71 )
                  {
                    v93 = myPosition_8;
                  }
                  else
                  {
                    v108 = (float *)((char *)v92 + 4 * v98 + 4 * v104);
                    v93 = myPosition_8;
                    v109 = (char *)&myPosition_8[4 * v98 + 3].mNext + 4;
                    do
                    {
                      if ( *v109 && *v108 < v97 )
                      {
                        v94 = v99;
                        v95 = v103;
                        v96 = v98;
                        v97 = *v108;
                      }
                      ++v98;
                      ++v108;
                      v109 += 32;
                    }
                    while ( v98 < v71 );
                  }
                  v98 = 0i64;
                  v101 = *(char **)is_on_screen;
                }
                --v103;
                --v102;
              }
              while ( v102 >= 0 );
              v100 += 7;
              ++v99;
              v101 += 7;
              *(_QWORD *)is_on_screen = v101;
            }
            while ( v100 < 14 );
            if ( v94 == -1 || v95 == -1 || v96 == -1 )
              break;
            v110 = 4 * v96;
            v111 = (UFG::SimObject *)v93[v110].mNext;
            v112 = v94;
            v113 = &v157->mSlots[v112][v95];
            if ( v113->m_pPointer )
            {
              v114 = v113->mPrev;
              v115 = v113->mNext;
              v114->mNext = v115;
              v115->mPrev = v114;
              v113->mPrev = v113;
              v113->mNext = v113;
            }
            v113->m_pPointer = v111;
            if ( v111 )
            {
              v116 = v111->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
              v116->mNext = v113;
              v113->mPrev = v116;
              v113->mNext = &v111->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
              v111->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = v113;
            }
            BYTE4(v93[v110 + 3].mNext) = 0;
            v151[v112 * 7 + v95] = 0;
            ++LODWORD(myPosition);
          }
          operator delete[](v92);
          v117 = 0;
          v118 = &v157->mSlotOffsets[0].z;
          p_m_pPointer = &v157->mSlots[0][0].m_pPointer;
          do
          {
            v120 = 0;
            v121 = v118;
            do
            {
              v122 = (UFG::SimObjectCVBase *)*p_m_pPointer;
              if ( *p_m_pPointer )
              {
                m_Flags = v122->m_Flags;
                if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
                  v124 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v122);
                else
                  v124 = (UFG::AiDriverComponent *)((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                                  ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      v122,
                                                      UFG::AiDriverComponent::_TypeUID)
                                                  : UFG::SimObject::GetComponentOfType(
                                                      v122,
                                                      UFG::AiDriverComponent::_TypeUID));
                if ( v124 )
                {
                  v2.x = *(v121 - 2);
                  v125 = *(v121 - 1);
                  v2.y = v125;
                  v2.z = *v121;
                  if ( v117 == 1 )
                    LODWORD(v2.y) = LODWORD(v125) ^ _xmm[0];
                  UFG::AiDriverComponent::SetFollowOffsetCustom(v124, v117, v120, &v2, 2.0);
                }
              }
              ++v120;
              p_m_pPointer += 3;
              v121 += 3;
            }
            while ( v120 < 7 );
            ++v117;
          }
          while ( v117 < 2 );
          v126 = FLOAT_N10_0;
          v127 = FLOAT_10_0;
          v128 = v146;
          v3 = v157;
          if ( (__int64)v146 > 0 )
          {
            v129 = (float *)&myPosition_8[2].mNext + 1;
            do
            {
              if ( *((_BYTE *)v129 + 8) )
              {
                v130 = *(UFG::SimObjectCVBase **)(v129 - 5);
                if ( v130 )
                {
                  v131 = v130->m_Flags;
                  if ( (v131 & 0x4000) != 0 || v131 < 0 )
                    v132 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v130);
                  else
                    v132 = (UFG::AiDriverComponent *)((v131 & 0x2000) != 0 || (v131 & 0x1000) != 0
                                                    ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        v130,
                                                        UFG::AiDriverComponent::_TypeUID)
                                                    : UFG::SimObject::GetComponentOfType(
                                                        v130,
                                                        UFG::AiDriverComponent::_TypeUID));
                  v133 = v132;
                  if ( v132 )
                  {
                    if ( *v129 <= 1.5707964 )
                    {
                      UFG::AiDriverComponent::SetFollowDistance(v132, v127);
                      v127 = v127 + 3.0;
                    }
                    else
                    {
                      UFG::AiDriverComponent::SetFollowDistance(v132, v126);
                      v126 = v126 + -3.0;
                    }
                    UFG::AiDriverComponent::SetFollowOffset(v133, AnySide, Follow, 5.0);
                  }
                }
              }
              v129 += 8;
              --v128;
            }
            while ( v128 );
          }
          v11 = v139;
          v12 = v140;
          goto LABEL_183;
        }
        goto LABEL_66;
      }
    }
    v73 = (float *)&v61[4 * v59 * (v64 + LODWORD(v68))];
    v74 = (float *)&myPosition_8[2];
    v75 = v146;
    v147 = v146;
    v76 = v157;
    while ( v76->mHeuristic == FORMATIONHEURISTIC_ESCORT )
    {
      if ( v138 )
      {
        v77 = UFG::VehicleFormations::CalculateSecondaryTargetScore(
                v76,
                (UFG::qVector3 *)&myPosition,
                p_world_pos,
                *(UFG::qVector3 **)&viewport_scale);
        goto LABEL_104;
      }
      v77 = 0.0;
LABEL_106:
      *v73 = v77;
      ++v72;
      ++v73;
      v74 += 8;
      v147 = --v75;
      if ( !v75 )
      {
        v61 = (char *)m_pSimComponent;
        v68 = v2.z;
        v64 = (int)v146;
        v65 = 0i64;
        v71 = (__int64)v146;
        v59 = v140;
        goto LABEL_108;
      }
    }
    v77 = (float)((float)((float)((float)(p_world_pos->y - *(v74 - 1)) * (float)(p_world_pos->y - *(v74 - 1)))
                        + (float)((float)(p_world_pos->x - *(v74 - 2)) * (float)(p_world_pos->x - *(v74 - 2))))
                + (float)((float)(p_world_pos->z - *v74) * (float)(p_world_pos->z - *v74)))
        + (float)((float)(sSLOTSCORE_MULTIPLIER * sSLOTSCORE_MULTIPLIER) * (float)v70);
    v78 = v74[1];
    v79 = *((_DWORD *)v74 + 2);
    if ( v79 != v62 )
    {
      v80 = v78 <= 1.5707964 ? v69 - 1 : v69 - 5;
      if ( v80 > 1 )
      {
        v77 = sVEHICLEFORMATION_WRONGSIDE_WEIGHT;
        goto LABEL_89;
      }
    }
    if ( !LOBYTE(p_myPosition_4->vfptr) )
    {
      if ( v78 <= 1.5707964 )
      {
        if ( (unsigned __int64)(v69 - 1) > 1 )
          goto LABEL_84;
        if ( v78 > 0.78539819 )
        {
LABEL_86:
          if ( v62 == v79 )
          {
            v77 = 0.0;
            goto LABEL_89;
          }
LABEL_84:
          v77 = v67;
          goto LABEL_89;
        }
      }
      else
      {
        if ( (unsigned __int64)(v69 - 5) > 1 )
        {
          v77 = v67;
          goto LABEL_89;
        }
        if ( v78 < 2.3561945 )
          goto LABEL_86;
      }
      v77 = v77 * 2.0;
    }
LABEL_89:
    if ( UFG::EncounterBase::sVisualizeVehicleFormationScoring )
    {
      Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(
                                              Render::DebugDrawManager::mInstance,
                                              1u);
      mTargetHeight = Context->mTargetHeight;
      viewport_scale.x = (float)Context->mTargetWidth;
      viewport_scale.y = (float)mTargetHeight;
      is_on_screen[0] = 0;
      mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
      if ( mCurrentCamera )
        p_mCamera = &mCurrentCamera->mCamera;
      else
        p_mCamera = 0i64;
      UFG::Camera::GetScreenCoord(p_mCamera, &v2, p_world_pos, &viewport_scale, is_on_screen);
      if ( is_on_screen[0] )
        Render::DebugDrawContext::DrawTextA(Context, (int)v2.x, (int)v2.y, &UFG::qColour::Green, "W: %0.2f", v77);
      v85 = UFG::Director::Get()->mCurrentCamera;
      if ( v85 )
        v86 = &v85->mCamera;
      else
        v86 = 0i64;
      ScreenCoord = UFG::Camera::GetScreenCoord(
                      v86,
                      &result,
                      (UFG::qVector3 *)&myPosition_8[4 * v72 + 1],
                      &viewport_scale,
                      is_on_screen);
      v88 = ScreenCoord->y;
      v89 = ScreenCoord->z;
      x = ScreenCoord->x;
      v2.x = ScreenCoord->x;
      v2.y = v88;
      v2.z = v89;
      if ( is_on_screen[0] )
        Render::DebugDrawContext::DrawTextA(Context, (int)x, (int)v88, &UFG::qColour::Green, "       A: %0.2f", v74[1]);
      v67 = sVEHICLEFORMATION_DISABLED_WEIGHT;
      v75 = v147;
LABEL_104:
      p_myPosition_4 = m_pSimComponent;
    }
    v76 = v157;
    v70 = *(_DWORD *)pIsLeftOpen;
    goto LABEL_106;
  }
LABEL_183:
  UFG::VehicleFormations::UpdateClosestToSecondaryTarget(
    v3,
    v12,
    (UFG::VehicleFormations::VehicleSlotDef *)myPosition_8,
    (UFG::SimObjectVehicle *)pSecondaryTarget,
    *(UFG::qVector3 **)&viewport_scale);
  operator delete[](myPosition_8);
  v3->mAllSlotsAssigned = v11 - LODWORD(myPosition) <= 0 || v12 - LODWORD(myPosition) <= 0;
}rd->z;
      x = ScreenCoord->x;
      v2.x = ScreenCoord->x;
      v2.y = v88;
      v2.z = v89;
      if ( is_on_screen[0] )
        Render::DebugDrawContext::DrawTextA(Context, (int)x, (int)v88

// File Line: 661
// RVA: 0x69B620
void __fastcall UFG::VehicleFormations::UpdateUsableLaneInfo(
        UFG::VehicleFormations *this,
        float deltaTime,
        UFG::qVector3 *myPosition,
        UFG::qVector3 *myForward,
        bool *pIsLeftOpen,
        bool *pIsRightOpen)
{
  bool *v6; // r13
  bool *v7; // r12
  UFG::SimComponent *m_pSimComponent; // rcx
  int mLaneIndex; // ebp
  UFG::RoadNetworkResource *RoadNetwork; // rax
  UFG::RoadNetworkSegment *ClosestSegment; // rsi
  UFG::RoadNetworkSegment *mpClosestSegment; // rcx
  int mClosestLaneIndex; // edx
  float v16; // xmm6_4
  bool v17; // cc
  UFG::RoadNetworkLane *v18; // rax
  UFG::RoadNetworkSegment *v19; // rcx
  int v20; // esi
  unsigned int mNumLanes; // r15d
  int v22; // r14d
  UFG::RoadNetworkLane *Lane; // r12
  bool IsReversedInNode; // bp
  UFG::RoadNetworkNode *v25; // rcx
  bool v26; // r12
  signed int i; // edi
  UFG::RoadNetworkLane *v28; // rax
  signed int j; // edi
  UFG::RoadNetworkLane *v30; // rax
  bool *v31; // rcx
  bool v32; // al
  UFG::qVector3 result; // [rsp+30h] [rbp-58h] BYREF
  UFG::RoadNetworkLane *nearestLane; // [rsp+90h] [rbp+8h] BYREF
  UFG::qVector3 *v1; // [rsp+A8h] [rbp+20h]

  v1 = myForward;
  v6 = pIsLeftOpen;
  v7 = pIsRightOpen;
  *pIsLeftOpen = 1;
  *v7 = 1;
  m_pSimComponent = this->mpSubject->pPhysicsMover.m_pSimComponent;
  if ( m_pSimComponent && !LODWORD(m_pSimComponent[12].m_BoundComponentHandles.mNode.mNext) )
  {
    this->mClosestLaneIndex = -1;
    this->mpClosestSegment = 0i64;
    this->mTimeSinceClosestLaneChanged = 0.0;
    return;
  }
  mLaneIndex = 0;
  LODWORD(pIsLeftOpen) = 0;
  RoadNetwork = UFG::WheeledVehicleNavigationData::GetRoadNetwork(UFG::WheeledVehicleManager::m_Instance->m_NavigationData);
  if ( RoadNetwork )
  {
    ClosestSegment = UFG::RoadNetworkResource::GetClosestSegment(RoadNetwork, myPosition, 0i64, 0);
    if ( ClosestSegment )
    {
      nearestLane = 0i64;
      UFG::RoadNetworkNode::GetNearestPos(ClosestSegment, &result, myPosition, &nearestLane, (float *)&pIsLeftOpen);
      if ( nearestLane )
        mLaneIndex = nearestLane->mLaneIndex;
      if ( !ClosestSegment->mType.mValue )
      {
        mpClosestSegment = this->mpClosestSegment;
        if ( mpClosestSegment == ClosestSegment )
        {
          mClosestLaneIndex = this->mClosestLaneIndex;
          if ( mClosestLaneIndex == mLaneIndex )
          {
LABEL_14:
            this->mTimeSinceClosestLaneChanged = 0.0;
LABEL_15:
            v19 = this->mpClosestSegment;
            v20 = this->mClosestLaneIndex;
            mNumLanes = (unsigned __int8)v19->mNumLanes;
            v22 = v20;
            if ( mNumLanes <= 1 )
            {
              *v6 = 0;
              *v7 = 0;
            }
            else
            {
              Lane = UFG::RoadNetworkNode::GetLane(v19, v20);
              IsReversedInNode = UFG::RoadNetworkLane::IsReversedInNode(Lane);
              v25 = (UFG::RoadNetworkNode *)((char *)Lane + Lane->mNode.mOffset);
              if ( !Lane->mNode.mOffset )
                v25 = 0i64;
              UFG::RoadNetworkNode::GetTangent(v25, &result, Lane->mLaneIndex, *(float *)&pIsLeftOpen);
              v26 = UFG::qAngleBetween(v1, &result) > 1.5707964;
              if ( mNumLanes == 2 )
              {
                v20 = 0;
                v22 = 1;
              }
              else
              {
                for ( i = this->mClosestLaneIndex - 1; i >= 0; v20 = i-- )
                {
                  v28 = UFG::RoadNetworkNode::GetLane(this->mpClosestSegment, i);
                  if ( IsReversedInNode != UFG::RoadNetworkLane::IsReversedInNode(v28) )
                    break;
                }
                for ( j = this->mClosestLaneIndex + 1; j < (int)mNumLanes; v22 = j++ )
                {
                  v30 = UFG::RoadNetworkNode::GetLane(this->mpClosestSegment, j);
                  if ( IsReversedInNode != UFG::RoadNetworkLane::IsReversedInNode(v30) )
                    break;
                }
              }
              if ( v26 )
                IsReversedInNode = !IsReversedInNode;
              v31 = pIsRightOpen;
              if ( IsReversedInNode )
              {
                *v6 = v22 != this->mClosestLaneIndex;
                v32 = v20 != this->mClosestLaneIndex;
              }
              else
              {
                *v6 = v20 != this->mClosestLaneIndex;
                v32 = v22 != this->mClosestLaneIndex;
              }
              *v31 = v32;
            }
            return;
          }
          v16 = deltaTime + this->mTimeSinceClosestLaneChanged;
          v17 = v16 <= sVEHICLEFORMATION_LANE_CHANGE_TIMER;
          this->mTimeSinceClosestLaneChanged = v16;
          if ( v17 )
          {
            v18 = UFG::RoadNetworkNode::GetLane(mpClosestSegment, mClosestLaneIndex);
            LODWORD(pIsLeftOpen) = UFG::RoadNetworkLane::GetClosestT(v18, myPosition);
            goto LABEL_15;
          }
        }
        this->mpClosestSegment = ClosestSegment;
        this->mClosestLaneIndex = mLaneIndex;
        goto LABEL_14;
      }
    }
  }
}

// File Line: 813
// RVA: 0x6946F0
void __fastcall UFG::VehicleFormations::Update(UFG::VehicleFormations *this, float deltaTime)
{
  if ( this->mUpdateRequested )
  {
    this->mUpdateRequested = 0;
    *(_QWORD *)&this->mTimeSinceFormationRequest = 0i64;
  }
  UFG::VehicleFormations::UpdateSlots(this, deltaTime);
  UFG::VehicleFormations::UpdateTimeInFormation(this, deltaTime);
}

// File Line: 1007
// RVA: 0x69A1F0
void __fastcall UFG::VehicleFormations::UpdateTimeInFormation(UFG::VehicleFormations *this, float deltaTime)
{
  char v3; // bp
  UFG::SimObject **p_m_pPointer; // rsi
  bool (*mSlotUsableProcessed)[7]; // rdi
  __int64 v6; // r14
  float v7; // xmm2_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  int i; // ebx
  UFG::SimObjectCVBase *v12; // rcx
  __int16 m_Flags; // dx
  UFG::AiDriverComponent *ComponentOfTypeHK; // rax

  v3 = 1;
  p_m_pPointer = &this->mSlots[0][0].m_pPointer;
  mSlotUsableProcessed = this->mSlotUsableProcessed;
  v6 = 2i64;
  this->mTimeSinceFormationRequest = deltaTime + this->mTimeSinceFormationRequest;
  v7 = deltaTime + this->mCombatStats.mLastAttack[0];
  v9 = deltaTime + this->mCombatStats.mLastAttack[1];
  v10 = deltaTime + this->mCombatStats.mLastAttack[2];
  this->mCombatStats.mLastAttack[0] = v7;
  this->mCombatStats.mLastAttack[1] = v9;
  this->mCombatStats.mLastAttack[2] = v10;
  this->mCombatStats.mLastAttack[3] = deltaTime + this->mCombatStats.mLastAttack[3];
  do
  {
    for ( i = 0; i < 7; ++i )
    {
      if ( *(_BYTE *)mSlotUsableProcessed )
      {
        v12 = (UFG::SimObjectCVBase *)*p_m_pPointer;
        if ( *p_m_pPointer )
        {
          m_Flags = v12->m_Flags;
          if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
          {
            ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v12);
          }
          else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          {
            ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            v12,
                                                            UFG::AiDriverComponent::_TypeUID);
          }
          else
          {
            ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                                            v12,
                                                            UFG::AiDriverComponent::_TypeUID);
          }
          if ( ComponentOfTypeHK
            && ComponentOfTypeHK->m_CurrentAttack == NumAttacks
            && UFG::AiDriverComponent::GetTimeAtOffset(ComponentOfTypeHK, (CarCombat::Position)i) == 0.0 )
          {
            v3 = 0;
          }
        }
      }
      p_m_pPointer += 3;
      mSlotUsableProcessed = (bool (*)[7])((char *)mSlotUsableProcessed + 1);
    }
    --v6;
  }
  while ( v6 );
  if ( v3 )
    this->mTimeInFormation = deltaTime + this->mTimeInFormation;
  else
    this->mTimeInFormation = 0.0;
}

// File Line: 1062
// RVA: 0x68B530
void __fastcall UFG::VehicleFormations::SetSlotUsability(UFG::VehicleFormations *this, int position, char usable)
{
  char *v4; // rdx
  bool v5; // zf
  bool v6; // r10
  bool (*mSlotUsable)[7]; // rdx
  __int64 v8; // rcx
  bool v9; // r10
  bool v10; // r8
  __int64 v11; // rax

  v4 = (char *)this + position;
  v5 = v4[408] == usable;
  v4[408] = usable;
  v6 = !v5;
  v5 = v4[415] == usable;
  v4[415] = usable;
  mSlotUsable = this->mSlotUsable;
  v8 = 2i64;
  v9 = !v5 || v6;
  v10 = 0;
  do
  {
    v11 = 0i64;
    while ( !(*mSlotUsable)[v11] )
    {
      if ( ++v11 >= 7 )
        goto LABEL_7;
    }
    v10 = 1;
LABEL_7:
    ++mSlotUsable;
    --v8;
  }
  while ( v8 );
  v5 = this->mFormationAvailable == v10;
  this->mFormationAvailable = v10;
  if ( !v5 || v9 )
    this->mUpdateRequested = 1;
}

// File Line: 1139
// RVA: 0x677D90
void __fastcall UFG::VehicleFormations::EndAttack(UFG::VehicleFormations *this, UFG::SimObject *pVehicle)
{
  UFG::SimObject **p_m_pPointer; // r9
  __int64 v4; // rdx
  bool (*mSlotAttacked)[7]; // r10
  UFG::SimObject **v7; // r8
  __int64 v8; // rcx
  __int64 i; // rax
  char v10; // al
  bool (*v11)[7]; // rcx
  __int64 mCurrentAttack; // rax
  __int64 j; // r10
  __int64 k; // r8
  UFG::VehicleSubjectComponent **v15; // rdx
  UFG::VehicleSubjectComponent *v16; // rcx
  UFG::VehicleSubjectComponent *v17; // rax

  p_m_pPointer = &this->mSlots[0][0].m_pPointer;
  v4 = 2i64;
  mSlotAttacked = this->mSlotAttacked;
  v7 = &this->mSlots[0][0].m_pPointer;
  v8 = 2i64;
  do
  {
    for ( i = 0i64; i < 7; ++i )
    {
      if ( pVehicle == *v7 )
        (*mSlotAttacked)[i] = 1;
      v7 += 3;
    }
    ++mSlotAttacked;
    --v8;
  }
  while ( v8 );
  v10 = 1;
  v11 = this->mSlotAttacked;
  do
  {
    if ( (*v11)[-28] && !*(_BYTE *)v11 )
      v10 = 0;
    if ( (*v11)[-27] && !(*v11)[1] )
      v10 = 0;
    if ( (*v11)[-26] && !(*v11)[2] )
      v10 = 0;
    if ( (*v11)[-25] && !(*v11)[3] )
      v10 = 0;
    if ( (*v11)[-24] && !(*v11)[4] )
      v10 = 0;
    if ( (*v11)[-23] && !(*v11)[5] )
      v10 = 0;
    if ( (*v11)[-22] && !(*v11)[6] )
      v10 = 0;
    ++v11;
    --v4;
  }
  while ( v4 );
  if ( v10 )
  {
    *(_QWORD *)&this->mSlotAttacked[0][0] = 0i64;
    *(_DWORD *)&this->mSlotAttacked[1][1] = 0;
    *(_WORD *)&this->mSlotAttacked[1][5] = 0;
    mCurrentAttack = this->mCurrentAttack;
    ++this->mCombatStats.mNumAttacks[mCurrentAttack];
    this->mCombatStats.mLastAttack[mCurrentAttack] = 0.0;
    ++this->mCombatStats.mNumAttacks[3];
    this->mCombatStats.mLastAttack[3] = 0.0;
    this->mCurrentAttack = NumFormationAttacks;
  }
  for ( j = 3i64; j < 17; j += 7i64 )
  {
    for ( k = 0i64; k < 7; ++k )
    {
      if ( pVehicle == *p_m_pPointer )
      {
        v15 = &this->mpSubject + 3 * j + 3 * k;
        if ( v15[2] )
        {
          v16 = *v15;
          v17 = v15[1];
          v16->m_SafePointerList.mNode.UFG::CameraSubject::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v17;
          v17->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)v16;
          *v15 = (UFG::VehicleSubjectComponent *)v15;
          v15[1] = (UFG::VehicleSubjectComponent *)v15;
        }
        v15[2] = 0i64;
        this->mUpdateRequested = 1;
      }
      p_m_pPointer += 3;
    }
  }
}

