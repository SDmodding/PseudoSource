// File Line: 58
// RVA: 0x66B3C0
void __fastcall UFG::VehicleFormations::VehicleFormations(UFG::VehicleFormations *this, UFG::VehicleSubjectComponent *pSubject, UFG::qList<UFG::SimObjectPointer,UFG::SimObjectPointer,1,0> *list)
{
  UFG::VehicleFormations *v3; // rdi
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v4; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v5; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> (*v6)[7]; // rbx
  _DWORD *v7; // rax
  signed __int64 v8; // rcx
  bool (*v9)[7]; // rdx
  signed __int64 v10; // r9
  signed __int64 v11; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rax
  int v14; // esi
  float *v15; // rbx
  bool v16; // al
  UFG::qVector3 *v17; // rax
  float v18; // xmm1_4
  float v19; // xmm2_4
  UFG::qVector3 result; // [rsp+38h] [rbp-30h]

  v3 = this;
  this->mpSubject = pSubject;
  this->mpVehicles = list;
  this->mHeuristic = 0;
  v4 = &this->mpSecondaryTarget;
  v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  v4->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  this->mpSecondaryTarget.m_pPointer = 0i64;
  v5 = &this->mpClosestToSecondaryTarget;
  v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v5->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  this->mpClosestToSecondaryTarget.m_pPointer = 0i64;
  v6 = this->mSlots;
  `eh vector constructor iterator'(
    this->mSlots,
    0x18ui64,
    14,
    (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>);
  v7 = (_DWORD *)v3->mCombatStats.mLastAttack;
  v8 = 4i64;
  do
  {
    *v7 = 0;
    v7[4] = 0;
    ++v7;
    --v8;
  }
  while ( v8 );
  v3->mCurrentAttack = 4;
  v3->mpClosestSegment = 0i64;
  *(_QWORD *)&v3->mClosestLaneIndex = 0i64;
  *(_QWORD *)&v3->mTimeSinceFormationRequest = 0i64;
  v3->mParticipantCount = 0;
  *(_DWORD *)&v3->mCustomFormation = 0x1000000;
  v9 = v3->mSlotUsableProcessed;
  v10 = 2i64;
  do
  {
    v11 = 7i64;
    do
    {
      if ( (*v6)[0].m_pPointer )
      {
        v12 = (*v6)[0].mPrev;
        v13 = (*v6)[0].mNext;
        v12->mNext = v13;
        v13->mPrev = v12;
        (*v6)[0].mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)v6;
        (*v6)[0].mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)v6;
      }
      (*v6)[0].m_pPointer = 0i64;
      (*v9)[-14] = 1;
      *(_BYTE *)v9 = 1;
      (*v9)[14] = 0;
      (*v9)[28] = 0;
      v6 = (UFG::qSafePointer<UFG::SimObject,UFG::SimObject> (*)[7])((char *)v6 + 24);
      v9 = (bool (*)[7])((char *)v9 + 1);
      --v11;
    }
    while ( v11 );
    --v10;
  }
  while ( v10 );
  v14 = 0;
  v15 = &v3->mSlotOffsets[0].z;
  do
  {
    if ( !v3->mpSubject->pPhysicsMover.m_pSimComponent
      || (v16 = 1, LODWORD(v3->mpSubject->pPhysicsMover.m_pSimComponent[12].m_BoundComponentHandles.mNode.mNext)) )
    {
      v16 = 0;
    }
    v17 = UFG::AiDriverComponent::GetCombatOffset(&result, 0, v14, v16);
    v18 = v17->y;
    v19 = v17->z;
    *(v15 - 2) = v17->x;
    *(v15 - 1) = v18;
    *v15 = v19;
    ++v14;
    v15 += 3;
  }
  while ( v14 < 7 );
}

// File Line: 89
// RVA: 0x685DC0
void __fastcall UFG::VehicleFormations::OverrideSlotOffsets(UFG::VehicleFormations *this, UFG::qPropertySet *pSlotOffsetProperties)
{
  UFG::qPropertySet *v2; // rsi
  UFG::qSymbol **v3; // rdi
  float *v4; // rbx
  UFG::qVector3 *v5; // rax
  float v6; // xmm0_4
  float v7; // xmm1_4

  v2 = pSlotOffsetProperties;
  v3 = VehicleFormations_SlotOffsetSymbols;
  v4 = &this->mSlotOffsets[0].z;
  do
  {
    v5 = UFG::qPropertySet::Get<UFG::qVector3>(v2, *v3, DEPTH_RECURSE);
    if ( v5 )
    {
      v6 = v5->y;
      v7 = v5->z;
      *(v4 - 2) = v5->x;
      *(v4 - 1) = v6;
      *v4 = v7;
    }
    ++v3;
    v4 += 3;
  }
  while ( (signed __int64)v3 < (signed __int64)&UFG::CarPhysicsMoverComponent::_TypeName );
}

// File Line: 116
// RVA: 0x6740A0
float __fastcall UFG::VehicleFormations::CalculateSecondaryTargetScore(UFG::VehicleFormations *this, UFG::qVector3 *myPosition, UFG::qVector3 *slotPosition, UFG::qVector3 *secondaryTargetPosition)
{
  float v5; // xmm3_4
  float v6; // xmm5_4
  float v7; // xmm9_4
  __m128 v8; // xmm4
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

  if ( this->mHeuristic != 3 )
    return 0.0;
  v8 = (__m128)LODWORD(slotPosition->y);
  v5 = 0.0;
  v6 = slotPosition->z - myPosition->z;
  v7 = myPosition->y;
  v8.m128_f32[0] = v8.m128_f32[0] - v7;
  v9 = slotPosition->x - myPosition->x;
  v10 = v8;
  v10.m128_f32[0] = (float)((float)(v8.m128_f32[0] * v8.m128_f32[0]) + (float)(v9 * v9)) + (float)(v6 * v6);
  if ( v10.m128_f32[0] == 0.0 )
    v11 = 0.0;
  else
    v11 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v10));
  v12 = (__m128)LODWORD(secondaryTargetPosition->y);
  v12.m128_f32[0] = v12.m128_f32[0] - v7;
  v13 = v11 * v9;
  LODWORD(v14) = COERCE_UNSIGNED_INT(v8.m128_f32[0] * v11) ^ _xmm[0];
  LODWORD(v15) = COERCE_UNSIGNED_INT(v6 * v11) ^ _xmm[0];
  v16 = secondaryTargetPosition->x - myPosition->x;
  v19 = v12;
  v17 = LODWORD(v13) ^ _xmm[0];
  v18 = secondaryTargetPosition->z - myPosition->z;
  v19.m128_f32[0] = (float)((float)(v12.m128_f32[0] * v12.m128_f32[0]) + (float)(v16 * v16)) + (float)(v18 * v18);
  if ( v19.m128_f32[0] != 0.0 )
    v5 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v19));
  return (float)((float)((float)((float)((float)(v12.m128_f32[0] * v5) * v14)
                               + (float)((float)(v16 * v5) * *(float *)&v17))
                       + (float)((float)(v18 * v5) * v15))
               + 1.0)
       * 0.5;
}

// File Line: 142
// RVA: 0x6957C0
void __fastcall UFG::VehicleFormations::UpdateClosestToSecondaryTarget(UFG::VehicleFormations *this, int vehicleCount, UFG::VehicleFormations::VehicleSlotDef *slots, UFG::SimObject *pSecondaryTarget, UFG::qVector3 *secondaryTargetPosition)
{
  UFG::SimObject *v5; // rbp
  UFG::VehicleFormations::VehicleSlotDef *v6; // rsi
  int v7; // er10
  UFG::VehicleFormations *v8; // rbx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v9; // rdx
  float v10; // xmm3_4
  int v11; // edx
  int v12; // ecx
  signed __int64 v13; // rax
  float v14; // xmm4_4
  float v15; // xmm5_4
  float v16; // xmm6_4
  float *v17; // r8
  signed int v18; // er9
  float v19; // xmm4_4
  float v20; // xmm5_4
  float *v21; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v22; // r8
  UFG::SimObjectCVBase *v23; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v24; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v25; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v26; // rax
  unsigned __int16 v27; // cx
  UFG::AiDriverComponent *v28; // rax
  UFG::AiDriverComponent *v29; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v30; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v31; // rax

  v5 = pSecondaryTarget;
  v6 = slots;
  v7 = vehicleCount;
  v8 = this;
  if ( this->mHeuristic != 3 )
  {
    v9 = &this->mpClosestToSecondaryTarget;
LABEL_36:
    if ( v9->m_pPointer )
    {
      v30 = v9->mPrev;
      v31 = v9->mNext;
      v30->mNext = v31;
      v31->mPrev = v30;
      v9->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v9->mPrev;
      v9->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v9->mPrev;
    }
    v9->m_pPointer = 0i64;
    return;
  }
  v10 = FLOAT_3_4028235e38;
  v11 = -1;
  if ( !pSecondaryTarget )
    goto LABEL_41;
  v12 = 0;
  v13 = 0i64;
  if ( v7 >= 4 )
  {
    v14 = secondaryTargetPosition->x;
    v15 = secondaryTargetPosition->y;
    v16 = secondaryTargetPosition->z;
    v17 = &slots->vehiclePosition.z;
    v18 = 2;
    v13 = 4i64 * (((unsigned int)(v7 - 4) >> 2) + 1);
    do
    {
      if ( (float)((float)((float)((float)(v15 - *(v17 - 1)) * (float)(v15 - *(v17 - 1)))
                         + (float)((float)(v14 - *(v17 - 2)) * (float)(v14 - *(v17 - 2))))
                 + (float)((float)(v16 - *v17) * (float)(v16 - *v17))) < v10 )
      {
        v10 = (float)((float)((float)(v15 - *(v17 - 1)) * (float)(v15 - *(v17 - 1)))
                    + (float)((float)(v14 - *(v17 - 2)) * (float)(v14 - *(v17 - 2))))
            + (float)((float)(v16 - *v17) * (float)(v16 - *v17));
        v11 = v12;
      }
      if ( (float)((float)((float)((float)(v15 - v17[7]) * (float)(v15 - v17[7]))
                         + (float)((float)(v14 - v17[6]) * (float)(v14 - v17[6])))
                 + (float)((float)(v16 - v17[8]) * (float)(v16 - v17[8]))) < v10 )
      {
        v10 = (float)((float)((float)(v15 - v17[7]) * (float)(v15 - v17[7]))
                    + (float)((float)(v14 - v17[6]) * (float)(v14 - v17[6])))
            + (float)((float)(v16 - v17[8]) * (float)(v16 - v17[8]));
        v11 = v18 - 1;
      }
      if ( (float)((float)((float)((float)(v15 - v17[15]) * (float)(v15 - v17[15]))
                         + (float)((float)(v14 - v17[14]) * (float)(v14 - v17[14])))
                 + (float)((float)(v16 - v17[16]) * (float)(v16 - v17[16]))) < v10 )
      {
        v10 = (float)((float)((float)(v15 - v17[15]) * (float)(v15 - v17[15]))
                    + (float)((float)(v14 - v17[14]) * (float)(v14 - v17[14])))
            + (float)((float)(v16 - v17[16]) * (float)(v16 - v17[16]));
        v11 = v18;
      }
      if ( (float)((float)((float)((float)(v15 - v17[23]) * (float)(v15 - v17[23]))
                         + (float)((float)(v14 - v17[22]) * (float)(v14 - v17[22])))
                 + (float)((float)(v16 - v17[24]) * (float)(v16 - v17[24]))) < v10 )
      {
        v10 = (float)((float)((float)(v15 - v17[23]) * (float)(v15 - v17[23]))
                    + (float)((float)(v14 - v17[22]) * (float)(v14 - v17[22])))
            + (float)((float)(v16 - v17[24]) * (float)(v16 - v17[24]));
        v11 = v18 + 1;
      }
      v12 += 4;
      v17 += 32;
      v18 += 4;
    }
    while ( v12 < v7 - 3 );
  }
  if ( v12 < v7 )
  {
    v21 = &v6[v13].vehiclePosition.z;
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
    while ( v12 < v7 );
  }
  if ( v11 == -1 )
  {
LABEL_41:
    v9 = &v8->mpClosestToSecondaryTarget;
    goto LABEL_36;
  }
  v22 = &v8->mpClosestToSecondaryTarget;
  v23 = (UFG::SimObjectCVBase *)v6[v11].vehicle;
  if ( v8->mpClosestToSecondaryTarget.m_pPointer )
  {
    v24 = v22->mPrev;
    v25 = v8->mpClosestToSecondaryTarget.mNext;
    v24->mNext = v25;
    v25->mPrev = v24;
    v22->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v22->mPrev;
    v8->mpClosestToSecondaryTarget.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v8->mpClosestToSecondaryTarget.mPrev;
  }
  v8->mpClosestToSecondaryTarget.m_pPointer = (UFG::SimObject *)&v23->vfptr;
  if ( v23 )
  {
    v26 = v23->m_SafePointerList.mNode.mPrev;
    v26->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v22->mPrev;
    v22->mPrev = v26;
    v8->mpClosestToSecondaryTarget.mNext = &v23->m_SafePointerList.mNode;
    v23->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v22->mPrev;
    v27 = v23->m_Flags;
    if ( (v27 >> 14) & 1 )
    {
      v28 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v23);
    }
    else if ( (v27 & 0x8000u) == 0 )
    {
      if ( (v27 >> 13) & 1 )
        v28 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                          (UFG::SimObjectGame *)&v23->vfptr,
                                          UFG::AiDriverComponent::_TypeUID);
      else
        v28 = (UFG::AiDriverComponent *)((v27 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             (UFG::SimObjectGame *)&v23->vfptr,
                                                             UFG::AiDriverComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                                   (UFG::SimObject *)&v23->vfptr,
                                                                                                   UFG::AiDriverComponent::_TypeUID));
    }
    else
    {
      v28 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v23);
    }
    v29 = v28;
    if ( v28 )
    {
      UFG::AiDriverComponent::SetEscortEnemy(v28, v5);
      UFG::AiDriverComponent::UpdateEscortOffset(v29, 0.0);
    }
  }
}

// File Line: 225
// RVA: 0x698B80
void __fastcall UFG::VehicleFormations::UpdateSlots(UFG::VehicleFormations *this, float deltaTime)
{
  float xmm6_4_1; // xmm6_4
  UFG::VehicleFormations *v3; // r13
  UFG::qList<UFG::SimObjectPointer,UFG::SimObjectPointer,1,0> *v4; // r8
  int v5; // edx
  UFG::qList<UFG::SimObjectPointer,UFG::SimObjectPointer,1,0> *i; // rax
  unsigned __int64 v7; // rax
  UFG::allocator::free_link *v8; // rdi
  UFG::SimObject *v9; // rcx
  UFG::TransformNodeComponent *v10; // rbx
  int v11; // er15
  int v12; // er12
  _DWORD *v13; // rax
  unsigned int v14; // xmm1_4
  unsigned int v15; // xmm2_4
  __int64 v16; // rax
  float v17; // xmm1_4
  float v18; // xmm2_4
  __int64 v19; // rax
  float v20; // xmm1_4
  float v21; // xmm2_4
  UFG::qList<UFG::SimObjectPointer,UFG::SimObjectPointer,1,0> *v22; // rax
  UFG::qList<UFG::SimObjectPointer,UFG::SimObjectPointer,1,0> *v23; // r14
  signed __int64 v24; // rbx
  UFG::qNode<UFG::SimObjectPointer,UFG::SimObjectPointer> *v25; // rsi
  UFG::qNode<UFG::SimObjectPointer,UFG::SimObjectPointer> *v26; // rdi
  int v27; // xmm0_4
  int v28; // xmm1_4
  UFG::qNode<UFG::SimObjectPointer,UFG::SimObjectPointer> *v29; // rcx
  float v30; // xmm0_4
  int v31; // eax
  signed __int64 v32; // rcx
  signed __int64 v33; // rdx
  signed __int64 v34; // rax
  char v35; // r15
  UFG::RoadSpaceComponent *v36; // rdx
  char *v37; // r8
  char *v38; // r12
  char *v39; // rdi
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v40; // rbx
  float *v41; // rsi
  signed __int64 v42; // rax
  char *v43; // r14
  signed __int64 v44; // r13
  int v45; // xmm1_4
  UFG::qVector3 *v46; // rax
  float v47; // xmm0_4
  float v48; // xmm1_4
  UFG::SimObject *v49; // r8
  char v50; // al
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v51; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v52; // rax
  signed __int64 v53; // rcx
  float *v54; // rax
  UFG::SimObject *v55; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v56; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v57; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v58; // rax
  int v59; // ebx
  unsigned __int64 v60; // rax
  char *v61; // rcx
  int v62; // er13
  UFG::RoadSpaceComponent *v63; // r8
  signed int v64; // er9
  char *v65; // r10
  UFG::qVector3 *v66; // r15
  float v67; // xmm7_4
  float v68; // eax
  signed __int64 v69; // rdi
  signed int v70; // edx
  char *v71; // r14
  int v72; // er12
  float *v73; // r14
  signed __int64 v74; // rsi
  char *v75; // rbx
  UFG::VehicleFormations *v76; // rax
  float v77; // xmm6_4
  float v78; // xmm0_4
  int v79; // edx
  unsigned __int64 v80; // rax
  Render::DebugDrawContext *v81; // rbx
  signed int v82; // ecx
  UFG::BaseCameraComponent *v83; // rcx
  UFG::Camera *v84; // rcx
  UFG::BaseCameraComponent *v85; // rcx
  UFG::Camera *v86; // rcx
  UFG::qVector3 *v87; // rax
  float v88; // xmm1_4
  float v89; // xmm0_4
  float v90; // xmm2_4
  float v91; // xmm2_4
  UFG::RoadSpaceComponent *v92; // r12
  __int64 v93; // rsi
  signed __int64 v94; // r11
  signed __int64 v95; // rbx
  signed __int64 v96; // r10
  float v97; // xmm0_4
  signed __int64 v98; // rcx
  signed __int64 v99; // r9
  signed int v100; // er13
  char *v101; // rax
  signed int v102; // er15
  signed __int64 v103; // r8
  int v104; // eax
  signed __int64 v105; // r14
  float *v106; // rdi
  _BYTE *v107; // rdx
  float *v108; // rdi
  _BYTE *v109; // rdx
  signed __int64 v110; // r10
  __int64 v111; // r8
  signed __int64 v112; // r11
  UFG::VehicleSubjectComponent **v113; // rdx
  UFG::VehicleSubjectComponent *v114; // rcx
  UFG::VehicleSubjectComponent *v115; // rax
  UFG::VehicleSubjectComponent *v116; // rax
  CarCombat::Side v117; // er14
  float *v118; // r15
  UFG::SimObjectCVBase **v119; // rsi
  CarCombat::Position v120; // edi
  float *v121; // rbx
  UFG::SimObjectCVBase *v122; // rcx
  unsigned __int16 v123; // dx
  UFG::AiDriverComponent *v124; // rax
  int v125; // xmm1_4
  float v126; // xmm6_4
  float v127; // xmm7_4
  char *v128; // rsi
  signed __int64 v129; // rdi
  UFG::SimObjectCVBase *v130; // rcx
  unsigned __int16 v131; // dx
  UFG::AiDriverComponent *v132; // rax
  UFG::AiDriverComponent *v133; // rbx
  char v134[4]; // [rsp+0h] [rbp-1C8h]
  char v135[4]; // [rsp+4h] [rbp-1C4h]
  char v136[280]; // [rsp+8h] [rbp-1C0h]
  bool *pIsRightOpen; // [rsp+128h] [rbp-A0h]
  bool v138; // [rsp+130h] [rbp-98h]
  bool v139; // [rsp+131h] [rbp-97h]
  int v140; // [rsp+134h] [rbp-94h]
  int v141; // [rsp+138h] [rbp-90h]
  UFG::qVector3 v2; // [rsp+140h] [rbp-88h]
  __int128 myPosition; // [rsp+150h] [rbp-78h]
  UFG::RoadSpaceComponent *v144; // [rsp+160h] [rbp-68h]
  char *v145; // [rsp+168h] [rbp-60h]
  char *v146; // [rsp+170h] [rbp-58h]
  UFG::qVector2 viewport_scale; // [rsp+178h] [rbp-50h]
  UFG::qVector3 v1; // [rsp+180h] [rbp-48h]
  UFG::qVector3 v149; // [rsp+190h] [rbp-38h]
  char v150[6]; // [rsp+1A0h] [rbp-28h]
  char v151[10]; // [rsp+1A6h] [rbp-22h]
  UFG::SimObject *pSecondaryTarget; // [rsp+1B0h] [rbp-18h]
  UFG::qVector3 result; // [rsp+1B8h] [rbp-10h]
  __int64 v154; // [rsp+1C8h] [rbp+0h]
  UFG::qVector3 world_pos; // [rsp+1D8h] [rbp+10h]
  UFG::VehicleFormations *v156; // [rsp+338h] [rbp+170h]
  bool is_on_screen[8]; // [rsp+348h] [rbp+180h]
  bool pIsLeftOpen[4]; // [rsp+350h] [rbp+188h]

  v154 = -2i64;
  xmm6_4_1 = deltaTime;
  v3 = this;
  v4 = this->mpVehicles;
  v5 = 0;
  for ( i = (UFG::qList<UFG::SimObjectPointer,UFG::SimObjectPointer,1,0> *)v4->mNode.mNext;
        i != v4;
        i = (UFG::qList<UFG::SimObjectPointer,UFG::SimObjectPointer,1,0> *)i->mNode.mNext )
  {
    ++v5;
  }
  v7 = 32i64 * v5;
  if ( !is_mul_ok(v5, 0x20ui64) )
    v7 = -1i64;
  v8 = UFG::qMalloc(v7, UFG::gGlobalNewName, 0i64);
  *((_QWORD *)&myPosition + 1) = v8;
  v9 = v3->mpSecondaryTarget.m_pPointer;
  pSecondaryTarget = v9;
  v139 = v9 != 0i64;
  if ( v9 )
    v10 = v9->m_pTransformNodeComponent;
  else
    v10 = 0i64;
  if ( v9 != 0i64 )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(v10);
    viewport_scale = (UFG::qVector2)&v10->mWorldTransform.v3;
  }
  else
  {
    viewport_scale = (UFG::qVector2)&UFG::qVector3::msZero;
  }
  v11 = 0;
  v140 = 0;
  LODWORD(myPosition) = 0;
  v12 = 0;
  v141 = 0;
  v3->mParticipantCount = 0;
  v13 = (_DWORD *)((__int64 (*)(void))v3->mpSubject->vfptr[17].__vecDelDtor)();
  v14 = v13[1];
  v15 = v13[2];
  LODWORD(myPosition) = *v13;
  *(_QWORD *)((char *)&myPosition + 4) = __PAIR__(v15, v14);
  v16 = ((__int64 (*)(void))v3->mpSubject->vfptr[16].__vecDelDtor)();
  v17 = *(float *)(v16 + 4);
  v18 = *(float *)(v16 + 8);
  v1.x = *(float *)v16;
  v1.y = v17;
  v1.z = v18;
  v19 = ((__int64 (*)(void))v3->mpSubject->vfptr[15].__vecDelDtor)();
  v20 = *(float *)(v19 + 4);
  v21 = *(float *)(v19 + 8);
  v149.x = *(float *)v19;
  v149.y = v20;
  v149.z = v21;
  v144 = (UFG::RoadSpaceComponent *)v3->mpSubject->pRoadSpace.m_pSimComponent;
  v22 = v3->mpVehicles;
  v23 = (UFG::qList<UFG::SimObjectPointer,UFG::SimObjectPointer,1,0> *)v22->mNode.mNext;
  if ( v23 != v22 )
  {
    v24 = (signed __int64)&v8[2];
    do
    {
      v25 = v23[1].mNode.mPrev;
      if ( v25 )
      {
        v26 = v25[6].mNext[2].mPrev;
        if ( v26 )
        {
          *(_QWORD *)(v24 - 16) = v25;
          UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v26);
          v27 = HIDWORD(v26[11].mPrev);
          v28 = (int)v26[11].mNext;
          *(_DWORD *)(v24 - 8) = v26[11].mPrev;
          *(_DWORD *)(v24 - 4) = v27;
          *(_DWORD *)v24 = v28;
          v29 = v25[6].mNext[24].mPrev;
          if ( v29 && (LODWORD(v29[121].mNext) >> 1) & 1 )
          {
            *(_BYTE *)(v24 + 12) = 1;
            ++v3->mParticipantCount;
          }
          else
          {
            *(_BYTE *)(v24 + 12) = 0;
          }
          v2.x = *(float *)&myPosition - *(float *)(v24 - 8);
          v2.y = *((float *)&myPosition + 1) - *(float *)(v24 - 4);
          v2.z = *((float *)&myPosition + 2) - *(float *)v24;
          *(float *)(v24 + 4) = UFG::qAngleBetween(&v1, &v2);
          v30 = UFG::qAngleBetween(&v149, &v2);
          v31 = 0;
          LOBYTE(v31) = v30 <= 1.5707964;
          *(_DWORD *)(v24 + 8) = v31;
          ++v12;
          v24 += 32i64;
        }
      }
      v23 = (UFG::qList<UFG::SimObjectPointer,UFG::SimObjectPointer,1,0> *)v23->mNode.mNext;
    }
    while ( v23 != v3->mpVehicles );
    v141 = v12;
  }
  UFG::VehicleFormations::UpdateUsableLaneInfo(v3, xmm6_4_1, (UFG::qVector3 *)&myPosition, &v1, pIsLeftOpen, &v138);
  BYTE4(myPosition) = pIsLeftOpen[0];
  BYTE5(myPosition) = v138;
  if ( v12 > 0 )
  {
    is_on_screen[0] = 0;
    v32 = (signed __int64)v3->mSlotWeight;
    v33 = 2i64;
    do
    {
      v34 = 6i64;
      while ( *(_BYTE *)(v32 + v34) <= 0 )
      {
        if ( --v34 < 0 )
          goto LABEL_29;
      }
      is_on_screen[0] = 1;
LABEL_29:
      v32 += 7i64;
      --v33;
    }
    while ( v33 );
    v35 = 1;
    v36 = 0i64;
    v144 = 0i64;
    v37 = (char *)&v3->mSlotOffsets[6].z;
    v145 = (char *)&v3->mSlotOffsets[6].z;
    v38 = (char *)(v151 - (char *)v3);
    do
    {
      v39 = (char *)&v3->mSlotUsableProcessed[(_QWORD)v36][6];
      v40 = &v3->mSlots[(_QWORD)v36][6];
      v41 = (float *)v37;
      v42 = 84i64 * (_QWORD)v36 - (_QWORD)v3;
      v146 = &v135[v42];
      viewport_scale = (UFG::qVector2)&v136[v42];
      v43 = &v134[v42];
      v44 = -422 - 7i64 * (_QWORD)v36 - (_QWORD)v156;
      do
      {
        v2.x = *(v41 - 2);
        v45 = *((_DWORD *)v41 - 1);
        v2.y = *(v41 - 1);
        v2.z = *v41;
        if ( v36 == (UFG::RoadSpaceComponent *)1 )
          LODWORD(v2.y) = v45 ^ _xmm[0];
        v46 = UFG::RoadSpaceComponent::ChaseToWorld(v144, &result, &v2, 0i64);
        v47 = v46->y;
        v48 = v46->z;
        *(float *)((char *)v41 + (_QWORD)v43) = v46->x;
        *(float *)((char *)v41 + (_QWORD)v146) = v47;
        *(float *)((char *)v41 + *(_QWORD *)&viewport_scale) = v48;
        v49 = v40->m_pPointer;
        if ( is_on_screen[0] )
          v50 = *(v39 - 14) && v39[v44 + 450 + (_QWORD)v146] > 0;
        else
          v50 = *(v39 - 14);
        *v39 = v50;
        if ( !pIsLeftOpen[0] && !v138 )
          *v39 = 0;
        v146[422] = 0;
        v38[(_QWORD)v39 - 428] = *v39;
        if ( v40->m_pPointer )
        {
          v51 = v40->mPrev;
          v52 = v40->mNext;
          v51->mNext = v52;
          v52->mPrev = v51;
          v40->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v40->mPrev;
          v40->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v40->mPrev;
        }
        v40->m_pPointer = 0i64;
        if ( v35 )
        {
          if ( v49 )
          {
            if ( v38[(_QWORD)v39 - 428] )
            {
              v53 = 0i64;
              if ( (signed __int64)v145 > 0 )
              {
                v54 = (float *)(*((_QWORD *)&myPosition + 1) + 16i64);
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
                  if ( v53 >= (signed __int64)v145 )
                    goto LABEL_59;
                }
                *(_BYTE *)(32 * v53 + *((_QWORD *)&myPosition + 1) + 28) = 0;
                v38[(_QWORD)v39 - 428] = 0;
                if ( v40->m_pPointer )
                {
                  v56 = v40->mPrev;
                  v57 = v40->mNext;
                  v56->mNext = v57;
                  v57->mPrev = v56;
                  v40->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v40->mPrev;
                  v40->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v40->mPrev;
                }
                v40->m_pPointer = v55;
                if ( v55 )
                {
                  v58 = v55->m_SafePointerList.mNode.mPrev;
                  v58->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v40->mPrev;
                  v40->mPrev = v58;
                  v40->mNext = &v55->m_SafePointerList.mNode;
                  v55->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v40->mPrev;
                }
                ++v140;
                LODWORD(myPosition) = myPosition + 1;
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
        v36 = v144;
      }
      while ( (signed __int64)&v39[v44] >= 0 );
      v36 = (UFG::RoadSpaceComponent *)((char *)v144 + 1);
      v144 = v36;
      v37 = v145;
      v3 = v156;
    }
    while ( (signed __int64)v36 < 2 );
    v59 = v141;
    v60 = 56i64 * v141;
    if ( !is_mul_ok(14 * v141, 4ui64) )
      v60 = -1i64;
    v61 = (char *)UFG::qMalloc(v60, "VehicleFormations", 0i64);
    v62 = 0;
    v63 = (UFG::RoadSpaceComponent *)((char *)&myPosition + 4);
    v144 = (UFG::RoadSpaceComponent *)((char *)&myPosition + 4);
    v64 = 0;
    LODWORD(v145) = 0;
    v65 = v150;
    v146 = v150;
    v66 = &world_pos;
    v67 = sVEHICLEFORMATION_DISABLED_WEIGHT;
LABEL_66:
    v68 = 0.0;
    v2.z = 0.0;
    v69 = 0i64;
    v70 = 6;
    *(_DWORD *)pIsLeftOpen = 6;
    while ( 1 )
    {
      v71 = v145;
      if ( v65[v69] )
      {
        ++v140;
        v72 = 0;
        if ( (signed __int64)v145 > 0 )
          break;
      }
LABEL_108:
      ++LODWORD(v68);
      v2.z = v68;
      *(_DWORD *)pIsLeftOpen = --v70;
      ++v69;
      ++v66;
      if ( v69 >= 7 )
      {
        ++v62;
        v64 += 7;
        LODWORD(v145) = v64;
        v65 += 7;
        v146 = v65;
        v63 = (UFG::RoadSpaceComponent *)((char *)v63 + 1);
        v144 = v63;
        if ( v64 >= 14 )
        {
          v91 = sMAX_DIST_SQ_FOR_FORMATION;
          v92 = v144;
          v93 = *((_QWORD *)&myPosition + 1);
          while ( 1 )
          {
            v94 = -1i64;
            v95 = -1i64;
            v96 = -1i64;
            v97 = v91;
            v98 = 0i64;
            v99 = 0i64;
            v100 = 0;
            v101 = v150;
            *(_QWORD *)is_on_screen = v150;
            do
            {
              v102 = 6;
              v103 = 6i64;
              do
              {
                if ( v101[v103] )
                {
                  v104 = v141 * (v102 + v100);
                  if ( (signed __int64)v71 >= 4 )
                  {
                    v105 = (signed __int64)(v71 - 3);
                    v106 = (float *)((char *)v92 + 4 * v104);
                    v107 = (_BYTE *)(*((_QWORD *)&myPosition + 1) + 60i64);
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
                      if ( v107[32] && *((float *)&v92->m_SafePointerList.mNode.mPrev + v98 + v104) < v97 )
                      {
                        v94 = v99;
                        v95 = v103;
                        v96 = v98 + 2;
                        v97 = *((float *)&v92->m_SafePointerList.mNode.mPrev + v98 + v104);
                      }
                      if ( v107[64] && *((float *)&v92->m_SafePointerList.mNode.mPrev + v98 + v104 + 1) < v97 )
                      {
                        v94 = v99;
                        v95 = v103;
                        v96 = v98 + 3;
                        v97 = *((float *)&v92->m_SafePointerList.mNode.mPrev + v98 + v104 + 1);
                      }
                      v98 += 4i64;
                      v106 += 4;
                      v107 += 128;
                    }
                    while ( v98 < v105 );
                    v71 = v145;
                  }
                  if ( v98 >= (signed __int64)v71 )
                  {
                    v93 = *((_QWORD *)&myPosition + 1);
                  }
                  else
                  {
                    v108 = (float *)((char *)v92 + 4 * (v98 + v104));
                    v93 = *((_QWORD *)&myPosition + 1);
                    v109 = (_BYTE *)(32 * v98 + *((_QWORD *)&myPosition + 1) + 28i64);
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
                    while ( v98 < (signed __int64)v71 );
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
            v110 = 32 * v96;
            v111 = *(_QWORD *)(v110 + v93);
            v112 = 7 * v94;
            v113 = &v156->mpSubject + 3 * (v112 + v95 + 3);
            if ( v113[2] )
            {
              v114 = *v113;
              v115 = v113[1];
              v114->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v115;
              v115->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)v114;
              *v113 = (UFG::VehicleSubjectComponent *)v113;
              v113[1] = (UFG::VehicleSubjectComponent *)v113;
            }
            v113[2] = (UFG::VehicleSubjectComponent *)v111;
            if ( v111 )
            {
              v116 = *(UFG::VehicleSubjectComponent **)(v111 + 8);
              v116->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v113;
              *v113 = v116;
              v113[1] = (UFG::VehicleSubjectComponent *)(v111 + 8);
              *(_QWORD *)(v111 + 8) = v113;
            }
            *(_BYTE *)(v110 + v93 + 28) = 0;
            v150[v112 + v95] = 0;
            LODWORD(myPosition) = myPosition + 1;
          }
          operator delete[](v92);
          v117 = 0;
          v118 = &v156->mSlotOffsets[0].z;
          v119 = (UFG::SimObjectCVBase **)&v156->mSlots[0][0].m_pPointer;
          do
          {
            v120 = 0;
            v121 = v118;
            do
            {
              v122 = *v119;
              if ( *v119 )
              {
                v123 = v122->m_Flags;
                if ( (v123 >> 14) & 1 )
                {
                  v124 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v122);
                }
                else if ( (v123 & 0x8000u) == 0 )
                {
                  if ( (v123 >> 13) & 1 )
                    v124 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                       (UFG::SimObjectGame *)&v122->vfptr,
                                                       UFG::AiDriverComponent::_TypeUID);
                  else
                    v124 = (UFG::AiDriverComponent *)((v123 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                           (UFG::SimObjectGame *)&v122->vfptr,
                                                                           UFG::AiDriverComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v122->vfptr, UFG::AiDriverComponent::_TypeUID));
                }
                else
                {
                  v124 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v122);
                }
                if ( v124 )
                {
                  v2.x = *(v121 - 2);
                  v125 = *((_DWORD *)v121 - 1);
                  v2.y = *(v121 - 1);
                  v2.z = *v121;
                  if ( v117 == 1 )
                    LODWORD(v2.y) = v125 ^ _xmm[0];
                  UFG::AiDriverComponent::SetFollowOffsetCustom(v124, v117, v120, &v2, 2.0);
                }
              }
              ++v120;
              v119 += 3;
              v121 += 3;
            }
            while ( (signed int)v120 < 7 );
            ++v117;
          }
          while ( (signed int)v117 < 2 );
          v126 = FLOAT_N10_0;
          v127 = FLOAT_10_0;
          v128 = v145;
          v3 = v156;
          if ( (signed __int64)v145 > 0 )
          {
            v129 = *((_QWORD *)&myPosition + 1) + 20i64;
            do
            {
              if ( *(_BYTE *)(v129 + 8) )
              {
                v130 = *(UFG::SimObjectCVBase **)(v129 - 20);
                if ( v130 )
                {
                  v131 = v130->m_Flags;
                  if ( (v131 >> 14) & 1 )
                  {
                    v132 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v130);
                  }
                  else if ( (v131 & 0x8000u) == 0 )
                  {
                    if ( (v131 >> 13) & 1 )
                      v132 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         (UFG::SimObjectGame *)&v130->vfptr,
                                                         UFG::AiDriverComponent::_TypeUID);
                    else
                      v132 = (UFG::AiDriverComponent *)((v131 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                             (UFG::SimObjectGame *)&v130->vfptr,
                                                                             UFG::AiDriverComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v130->vfptr, UFG::AiDriverComponent::_TypeUID));
                  }
                  else
                  {
                    v132 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v130);
                  }
                  v133 = v132;
                  if ( v132 )
                  {
                    if ( *(float *)v129 <= 1.5707964 )
                    {
                      UFG::AiDriverComponent::SetFollowDistance(v132, v127);
                      v127 = v127 + 3.0;
                    }
                    else
                    {
                      UFG::AiDriverComponent::SetFollowDistance(v132, v126);
                      v126 = v126 + -3.0;
                    }
                    UFG::AiDriverComponent::SetFollowOffset(v133, AnySide, 0, 5.0);
                  }
                }
              }
              v129 += 32i64;
              --v128;
            }
            while ( v128 );
          }
          v11 = v140;
          v12 = v141;
          goto LABEL_187;
        }
        goto LABEL_66;
      }
    }
    v73 = (float *)&v61[4 * v59 * (v64 + LODWORD(v68))];
    v74 = *((_QWORD *)&myPosition + 1) + 16i64;
    v75 = v145;
    v146 = v145;
    v76 = v156;
    while ( v76->mHeuristic == 3 )
    {
      if ( v139 )
      {
        v77 = UFG::VehicleFormations::CalculateSecondaryTargetScore(
                v76,
                (UFG::qVector3 *)&myPosition,
                v66,
                *(UFG::qVector3 **)&viewport_scale);
        goto LABEL_104;
      }
      v77 = 0.0;
LABEL_106:
      *v73 = v77;
      ++v72;
      ++v73;
      v74 += 32i64;
      v146 = --v75;
      if ( !v75 )
      {
        v61 = (char *)v144;
        v68 = v2.z;
        v64 = (signed int)v145;
        v65 = v146;
        v71 = v145;
        v59 = v141;
        goto LABEL_108;
      }
    }
    v77 = (float)((float)((float)((float)(v66->y - *(float *)(v74 - 4)) * (float)(v66->y - *(float *)(v74 - 4)))
                        + (float)((float)(v66->x - *(float *)(v74 - 8)) * (float)(v66->x - *(float *)(v74 - 8))))
                + (float)((float)(v66->z - *(float *)v74) * (float)(v66->z - *(float *)v74)))
        + (float)((float)(sSLOTSCORE_MULTIPLIER * sSLOTSCORE_MULTIPLIER) * (float)v70);
    v78 = *(float *)(v74 + 4);
    v79 = *(_DWORD *)(v74 + 8);
    if ( v79 != v62 )
    {
      v80 = v78 <= 1.5707964 ? v69 - 1 : v69 - 5;
      if ( v80 > 1 )
      {
        v77 = sVEHICLEFORMATION_WRONGSIDE_WEIGHT;
        goto LABEL_89;
      }
    }
    if ( !LOBYTE(v63->vfptr) )
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
      v81 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
      v82 = v81->mTargetHeight;
      viewport_scale.x = (float)v81->mTargetWidth;
      viewport_scale.y = (float)v82;
      is_on_screen[0] = 0;
      v83 = UFG::Director::Get()->mCurrentCamera;
      if ( v83 )
        v84 = &v83->mCamera;
      else
        v84 = 0i64;
      UFG::Camera::GetScreenCoord(v84, &v2, v66, &viewport_scale, is_on_screen);
      if ( is_on_screen[0] )
      {
        *(double *)&pIsRightOpen = v77;
        Render::DebugDrawContext::DrawTextA(
          v81,
          (signed int)v2.x,
          (signed int)v2.y,
          &UFG::qColour::Green,
          "W: %0.2f",
          v77);
      }
      v85 = UFG::Director::Get()->mCurrentCamera;
      if ( v85 )
        v86 = &v85->mCamera;
      else
        v86 = 0i64;
      v87 = UFG::Camera::GetScreenCoord(
              v86,
              &result,
              (UFG::qVector3 *)(32i64 * v72 + *((_QWORD *)&myPosition + 1) + 8i64),
              &viewport_scale,
              is_on_screen);
      v88 = v87->y;
      v89 = v87->z;
      v90 = v87->x;
      v2.x = v87->x;
      v2.y = v88;
      v2.z = v89;
      if ( is_on_screen[0] )
      {
        *(double *)&pIsRightOpen = *(float *)(v74 + 4);
        Render::DebugDrawContext::DrawTextA(
          v81,
          (signed int)v90,
          (signed int)v88,
          &UFG::qColour::Green,
          "       A: %0.2f",
          pIsRightOpen);
      }
      v67 = sVEHICLEFORMATION_DISABLED_WEIGHT;
      v75 = v146;
LABEL_104:
      v63 = v144;
    }
    v76 = v156;
    v70 = *(_DWORD *)pIsLeftOpen;
    goto LABEL_106;
  }
LABEL_187:
  UFG::VehicleFormations::UpdateClosestToSecondaryTarget(
    v3,
    v12,
    *((UFG::VehicleFormations::VehicleSlotDef **)&myPosition + 1),
    pSecondaryTarget,
    *(UFG::qVector3 **)&viewport_scale);
  operator delete[](*((void **)&myPosition + 1));
  if ( v11 - (signed int)myPosition <= 0 )
    v3->mAllSlotsAssigned = 1;
  else
    v3->mAllSlotsAssigned = v12 - (signed int)myPosition <= 0;
}

// File Line: 661
// RVA: 0x69B620
void __fastcall UFG::VehicleFormations::UpdateUsableLaneInfo(UFG::VehicleFormations *this, float deltaTime, UFG::qVector3 *myPosition, UFG::qVector3 *myForward, bool *pIsLeftOpen, bool *pIsRightOpen)
{
  bool *v6; // r13
  bool *v7; // r12
  UFG::VehicleFormations *v8; // rbx
  UFG::SimComponent *v9; // rcx
  UFG::qVector3 *v10; // r14
  int v11; // ebp
  UFG::RoadNetworkResource *v12; // rax
  UFG::RoadNetworkSegment *v13; // rsi
  UFG::RoadNetworkNode *v14; // rcx
  unsigned int v15; // edx
  float v16; // xmm6_4
  bool v17; // cf
  bool v18; // zf
  UFG::RoadNetworkLane *v19; // rax
  UFG::RoadNetworkNode *v20; // rcx
  unsigned int v21; // esi
  signed int v22; // er15
  signed int v23; // er14
  UFG::RoadNetworkLane *v24; // r12
  bool v25; // bp
  UFG::RoadNetworkNode *v26; // rcx
  bool v27; // r12
  signed int i; // edi
  UFG::RoadNetworkLane *v29; // rax
  signed int j; // edi
  UFG::RoadNetworkLane *v31; // rax
  bool *v32; // rcx
  bool v33; // al
  UFG::qVector3 result; // [rsp+30h] [rbp-58h]
  UFG::RoadNetworkLane *nearestLane; // [rsp+90h] [rbp+8h]
  UFG::qVector3 *v1; // [rsp+A8h] [rbp+20h]

  v1 = myForward;
  v6 = pIsLeftOpen;
  v7 = pIsRightOpen;
  v8 = this;
  *pIsLeftOpen = 1;
  *v7 = 1;
  v9 = this->mpSubject->pPhysicsMover.m_pSimComponent;
  v10 = myPosition;
  if ( v9 && !LODWORD(v9[12].m_BoundComponentHandles.mNode.mNext) )
  {
    v8->mClosestLaneIndex = -1;
    v8->mpClosestSegment = 0i64;
    v8->mTimeSinceClosestLaneChanged = 0.0;
    return;
  }
  v11 = 0;
  LODWORD(pIsLeftOpen) = 0;
  v12 = UFG::WheeledVehicleNavigationData::GetRoadNetwork(UFG::WheeledVehicleManager::m_Instance->m_NavigationData);
  if ( v12 )
  {
    v13 = UFG::RoadNetworkResource::GetClosestSegment(v12, v10, 0i64, 0);
    if ( v13 )
    {
      nearestLane = 0i64;
      UFG::RoadNetworkNode::GetNearestPos(
        (UFG::RoadNetworkNode *)&v13->mType,
        &result,
        v10,
        &nearestLane,
        (float *)&pIsLeftOpen);
      if ( nearestLane )
        v11 = nearestLane->mLaneIndex;
      if ( 0 == v13->mType.mValue )
      {
        v14 = (UFG::RoadNetworkNode *)&v8->mpClosestSegment->mType;
        if ( v14 == (UFG::RoadNetworkNode *)v13 )
        {
          v15 = v8->mClosestLaneIndex;
          if ( v15 == v11 )
          {
LABEL_14:
            v8->mTimeSinceClosestLaneChanged = 0.0;
LABEL_15:
            v20 = (UFG::RoadNetworkNode *)&v8->mpClosestSegment->mType;
            v21 = v8->mClosestLaneIndex;
            v22 = (unsigned __int8)v20->mNumLanes;
            v23 = v8->mClosestLaneIndex;
            if ( v22 <= 1 )
            {
              *v6 = 0;
              *v7 = 0;
            }
            else
            {
              v24 = UFG::RoadNetworkNode::GetLane(v20, v21);
              v25 = UFG::RoadNetworkLane::IsReversedInNode(v24);
              v26 = (UFG::RoadNetworkNode *)((char *)v24 + v24->mNode.mOffset);
              if ( !v24->mNode.mOffset )
                v26 = 0i64;
              UFG::RoadNetworkNode::GetTangent(v26, &result, v24->mLaneIndex, *(float *)&pIsLeftOpen);
              v27 = UFG::qAngleBetween(v1, &result) > 1.5707964;
              if ( v22 == 2 )
              {
                v21 = 0;
                v23 = 1;
              }
              else
              {
                for ( i = v8->mClosestLaneIndex - 1; i >= 0; v21 = i-- )
                {
                  v29 = UFG::RoadNetworkNode::GetLane((UFG::RoadNetworkNode *)&v8->mpClosestSegment->mType, i);
                  if ( v25 != UFG::RoadNetworkLane::IsReversedInNode(v29) )
                    break;
                }
                for ( j = v8->mClosestLaneIndex + 1; j < v22; v23 = j++ )
                {
                  v31 = UFG::RoadNetworkNode::GetLane((UFG::RoadNetworkNode *)&v8->mpClosestSegment->mType, j);
                  if ( v25 != UFG::RoadNetworkLane::IsReversedInNode(v31) )
                    break;
                }
              }
              if ( v27 )
                v25 = v25 == 0;
              v32 = pIsRightOpen;
              if ( v25 )
              {
                *v6 = v23 != v8->mClosestLaneIndex;
                v33 = v21 != v8->mClosestLaneIndex;
              }
              else
              {
                *v6 = v21 != v8->mClosestLaneIndex;
                v33 = v23 != v8->mClosestLaneIndex;
              }
              *v32 = v33;
            }
            return;
          }
          v16 = deltaTime + v8->mTimeSinceClosestLaneChanged;
          v17 = v16 < sVEHICLEFORMATION_LANE_CHANGE_TIMER;
          v18 = v16 == sVEHICLEFORMATION_LANE_CHANGE_TIMER;
          v8->mTimeSinceClosestLaneChanged = v16;
          if ( v17 || v18 )
          {
            v19 = UFG::RoadNetworkNode::GetLane(v14, v15);
            LODWORD(pIsLeftOpen) = UFG::RoadNetworkLane::GetClosestT(v19, v10);
            goto LABEL_15;
          }
        }
        v8->mpClosestSegment = v13;
        v8->mClosestLaneIndex = v11;
        goto LABEL_14;
      }
    }
  }
}

// File Line: 813
// RVA: 0x6946F0
void __fastcall UFG::VehicleFormations::Update(UFG::VehicleFormations *this, float deltaTime)
{
  UFG::VehicleFormations *v2; // rbx

  v2 = this;
  if ( this->mUpdateRequested )
  {
    this->mUpdateRequested = 0;
    *(_QWORD *)&this->mTimeSinceFormationRequest = 0i64;
  }
  UFG::VehicleFormations::UpdateSlots(this, deltaTime);
  UFG::VehicleFormations::UpdateTimeInFormation(v2, deltaTime);
}

// File Line: 1007
// RVA: 0x69A1F0
void __fastcall UFG::VehicleFormations::UpdateTimeInFormation(UFG::VehicleFormations *this, float deltaTime)
{
  UFG::VehicleFormations *v2; // r15
  char v3; // bp
  UFG::SimObjectCVBase **v4; // rsi
  bool (*v5)[7]; // rdi
  signed __int64 v6; // r14
  float v7; // xmm2_4
  float v8; // xmm7_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  CarCombat::Position v11; // ebx
  UFG::SimObjectCVBase *v12; // rcx
  unsigned __int16 v13; // dx
  UFG::AiDriverComponent *v14; // rax

  v2 = this;
  v3 = 1;
  v4 = (UFG::SimObjectCVBase **)&this->mSlots[0][0].m_pPointer;
  v5 = this->mSlotUsableProcessed;
  v6 = 2i64;
  this->mTimeSinceFormationRequest = deltaTime + this->mTimeSinceFormationRequest;
  v7 = deltaTime + this->mCombatStats.mLastAttack[0];
  v8 = deltaTime;
  v9 = deltaTime + this->mCombatStats.mLastAttack[1];
  v10 = deltaTime + this->mCombatStats.mLastAttack[2];
  this->mCombatStats.mLastAttack[0] = v7;
  this->mCombatStats.mLastAttack[1] = v9;
  this->mCombatStats.mLastAttack[2] = v10;
  this->mCombatStats.mLastAttack[3] = v8 + this->mCombatStats.mLastAttack[3];
  do
  {
    v11 = 0;
    do
    {
      if ( *(_BYTE *)v5 )
      {
        v12 = *v4;
        if ( *v4 )
        {
          v13 = v12->m_Flags;
          if ( (v13 >> 14) & 1 )
          {
            v14 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v12);
          }
          else if ( (v13 & 0x8000u) == 0 )
          {
            if ( (v13 >> 13) & 1 )
              v14 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                (UFG::SimObjectGame *)&v12->vfptr,
                                                UFG::AiDriverComponent::_TypeUID);
            else
              v14 = (UFG::AiDriverComponent *)((v13 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                   (UFG::SimObjectGame *)&v12->vfptr,
                                                                   UFG::AiDriverComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v12->vfptr, UFG::AiDriverComponent::_TypeUID));
          }
          else
          {
            v14 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v12);
          }
          if ( v14 && v14->m_CurrentAttack == 7 && UFG::AiDriverComponent::GetTimeAtOffset(v14, v11) == 0.0 )
            v3 = 0;
        }
      }
      ++v11;
      v4 += 3;
      v5 = (bool (*)[7])((char *)v5 + 1);
    }
    while ( (signed int)v11 < 7 );
    --v6;
  }
  while ( v6 );
  if ( v3 )
    v2->mTimeInFormation = v8 + v2->mTimeInFormation;
  else
    v2->mTimeInFormation = 0.0;
}

// File Line: 1062
// RVA: 0x68B530
void __fastcall UFG::VehicleFormations::SetSlotUsability(UFG::VehicleFormations *this, CarCombat::Position position, bool usable)
{
  UFG::VehicleFormations *v3; // r9
  char *v4; // rdx
  bool v5; // zf
  bool v6; // r10
  bool (*v7)[7]; // rdx
  signed __int64 v8; // rcx
  bool v9; // r10
  char v10; // r8
  __int64 v11; // rax

  v3 = this;
  v4 = (char *)this + (signed int)position;
  v5 = v4[408] == usable;
  v4[408] = usable;
  v6 = !v5;
  v5 = v4[415] == usable;
  v4[415] = usable;
  v7 = this->mSlotUsable;
  v8 = 2i64;
  v9 = !v5 || v6;
  v10 = 0;
  do
  {
    v11 = 0i64;
    while ( !(*v7)[v11] )
    {
      if ( ++v11 >= 7 )
        goto LABEL_7;
    }
    v10 = 1;
LABEL_7:
    ++v7;
    --v8;
  }
  while ( v8 );
  v5 = v3->mFormationAvailable == v10;
  v3->mFormationAvailable = v10;
  if ( !v5 || v9 )
    v3->mUpdateRequested = 1;
}

// File Line: 1139
// RVA: 0x677D90
void __fastcall UFG::VehicleFormations::EndAttack(UFG::VehicleFormations *this, UFG::SimObject *pVehicle)
{
  UFG::SimObject **v2; // r9
  UFG::SimObject *v3; // rbx
  signed __int64 v4; // rdx
  UFG::VehicleFormations *v5; // r11
  bool (*v6)[7]; // r10
  UFG::SimObject **v7; // r8
  signed __int64 v8; // rcx
  signed __int64 v9; // rax
  char v10; // al
  bool (*v11)[7]; // rcx
  __int64 v12; // rax
  signed __int64 v13; // r10
  signed __int64 v14; // r8
  UFG::VehicleSubjectComponent **v15; // rdx
  UFG::VehicleSubjectComponent *v16; // rcx
  UFG::VehicleSubjectComponent *v17; // rax

  v2 = &this->mSlots[0][0].m_pPointer;
  v3 = pVehicle;
  v4 = 2i64;
  v5 = this;
  v6 = this->mSlotAttacked;
  v7 = &this->mSlots[0][0].m_pPointer;
  v8 = 2i64;
  do
  {
    v9 = 0i64;
    do
    {
      if ( v3 == *v7 )
        (*v6)[v9] = 1;
      ++v9;
      v7 += 3;
    }
    while ( v9 < 7 );
    ++v6;
    --v8;
  }
  while ( v8 );
  v10 = 1;
  v11 = v5->mSlotAttacked;
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
    *(_QWORD *)&v5->mSlotAttacked[0][0] = 0i64;
    *(_DWORD *)&v5->mSlotAttacked[1][1] = 0;
    *(_WORD *)&v5->mSlotAttacked[1][5] = 0;
    v12 = v5->mCurrentAttack;
    ++v5->mCombatStats.mNumAttacks[v12];
    v5->mCombatStats.mLastAttack[v12] = 0.0;
    ++v5->mCombatStats.mNumAttacks[3];
    v5->mCombatStats.mLastAttack[3] = 0.0;
    v5->mCurrentAttack = 4;
  }
  v13 = 3i64;
  do
  {
    v14 = 0i64;
    do
    {
      if ( v3 == *v2 )
      {
        v15 = &v5->mpSubject + 3 * (v13 + v14);
        if ( *((_QWORD *)&v5->mHeuristic + 3 * (v13 + v14)) )
        {
          v16 = *v15;
          v17 = v15[1];
          v16->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v17;
          v17->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)v16;
          *v15 = (UFG::VehicleSubjectComponent *)v15;
          v15[1] = (UFG::VehicleSubjectComponent *)v15;
        }
        v15[2] = 0i64;
        v5->mUpdateRequested = 1;
      }
      ++v14;
      v2 += 3;
    }
    while ( v14 < 7 );
    v13 += 7i64;
  }
  while ( v13 < 17 );
}

