// File Line: 54
// RVA: 0x32DEA0
void __fastcall DriverPathfindToTargetTask::DriverPathfindToTargetTask(DriverPathfindToTargetTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax
  float v2; // xmm1_4
  float v3; // xmm2_4
  float v4; // xmm1_4
  float v5; // xmm2_4

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable';
  this->vfptr = (ITaskVtbl *)&Task<DriverPathfindToTargetTrack>::`vftable';
  this->vfptr = (ITaskVtbl *)&DriverPathfindToTargetTask::`vftable';
  this->mpContext = 0i64;
  this->mIsCloseEnough = 0;
  this->mInThresholdTimer = 0.0;
  *(_WORD *)&this->mAiDriverUseDirection = 0;
  this->mMode = 0;
  v2 = UFG::qVector3::msZero.y;
  v3 = UFG::qVector3::msZero.z;
  this->mLastDestination.x = UFG::qVector3::msZero.x;
  this->mLastDestination.y = v2;
  this->mLastDestination.z = v3;
  v4 = UFG::qVector3::msZero.y;
  v5 = UFG::qVector3::msZero.z;
  this->mClosestRoadDestination.x = UFG::qVector3::msZero.x;
  this->mClosestRoadDestination.y = v4;
  this->mClosestRoadDestination.z = v5;
}

// File Line: 68
// RVA: 0x3941B0
void __fastcall DriverPathfindToTargetTask::UpdateArrivalMode(DriverPathfindToTargetTask *this, UFG::SimObject *pTarget, UFG::RoadSpaceComponent *pRoadSpaceComponent, UFG::AiDriverComponent *pAIDriverComponent, UFG::TransformNodeComponent *pMyTransform, UFG::TransformNodeComponent *pTargetTransform)
{
  DriverPathfindToTargetTask *v6; // rbx
  UFG::AiDriverComponent *v7; // rsi
  UFG::RoadSpaceComponent *v8; // rbp
  UFG::SimObject *v9; // r14
  UFG::RoadNetworkResource *v10; // r15
  float v11; // xmm1_4
  float v12; // xmm0_4
  unsigned int v13; // er8
  UFG::RoadNetworkIntersection *v14; // rax
  UFG::qVector3 *v15; // rax
  float v16; // xmm0_4
  float v17; // xmm1_4
  signed int v18; // eax
  UFG::qVector3 pos; // [rsp+30h] [rbp-38h]
  UFG::qVector3 result; // [rsp+40h] [rbp-28h]

  v6 = this;
  v7 = pAIDriverComponent;
  v8 = pRoadSpaceComponent;
  v9 = pTarget;
  v10 = UFG::WheeledVehicleNavigationData::GetRoadNetwork(UFG::WheeledVehicleManager::m_Instance->m_NavigationData);
  if ( v10 )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(pTargetTransform);
    v11 = pTargetTransform->mWorldTransform.v3.y;
    pos.x = pTargetTransform->mWorldTransform.v3.x;
    v12 = pTargetTransform->mWorldTransform.v3.z;
    pos.y = v11;
    pos.z = v12;
    if ( v8 == (UFG::RoadSpaceComponent *)-552i64 )
      v13 = 0;
    else
      v13 = v8->mWayClient.m_RoadNetworkType;
    v14 = UFG::RoadNetworkResource::GetClosestNode(v10, &pos, v13, 0i64, 0i64);
    v15 = UFG::RoadNetworkNode::GetClosestPosition((UFG::RoadNetworkNode *)&v14->mType, &result, &pos, 0i64);
    v16 = v15->y;
    v17 = v15->z;
    v6->mClosestRoadDestination.x = v15->x;
    v18 = 2;
    v6->mClosestRoadDestination.y = v16;
    v6->mClosestRoadDestination.z = v17;
  }
  else
  {
    v18 = 1;
  }
  if ( v6->mMode != v18 )
  {
    v6->mMode = v18;
    if ( v18 == 1 )
      DriverPathfindToTargetTask::SetupClosestPosition(v6, v9, v8, v7);
    else
      DriverPathfindToTargetTask::SetupClosestRoadNetworkPosition(v6, v9, v8, v7, pMyTransform, pTargetTransform);
    if ( v7 )
      v7->m_bIgnoreArrivalDirection = BYTE1(v6->m_Track[1].vfptr) != 0;
  }
}

// File Line: 146
// RVA: 0x388030
void __fastcall DriverPathfindToTargetTask::SetupClosestPosition(DriverPathfindToTargetTask *this, UFG::SimObject *pTarget, UFG::RoadSpaceComponent *pRoadSpaceComponent, UFG::AiDriverComponent *pAIDriverComponent)
{
  UFG::SimObjectGame *v4; // rbx
  UFG::AiDriverComponent *v5; // rdi
  unsigned __int16 v6; // cx
  UFG::CharacterOccupantComponent *v7; // rax
  UFG::SimObject *v8; // rdx

  v4 = (UFG::SimObjectGame *)pTarget;
  v5 = pAIDriverComponent;
  UFG::AiDriverComponent::SetDrivingMode(pAIDriverComponent, 4u);
  if ( !v4
    || ((v6 = v4->m_Flags, !((v6 >> 14) & 1)) ? ((v6 & 0x8000u) == 0 ? (!((v6 >> 13) & 1) ? (!((v6 >> 12) & 1) ? (v7 = (UFG::CharacterOccupantComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::CharacterOccupantComponent::_TypeUID)) : (v7 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::CharacterOccupantComponent::_TypeUID))) : (v7 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::CharacterOccupantComponent::_TypeUID))) : (v7 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::CharacterOccupantComponent::_TypeUID))) : (v7 = (UFG::CharacterOccupantComponent *)v4->m_Components.p[44].m_pComponent),
        !v7 || (v8 = (UFG::SimObject *)UFG::CharacterOccupantComponent::GetCurrentVehicle(v7)) == 0i64) )
  {
    v8 = (UFG::SimObject *)&v4->vfptr;
  }
  UFG::AiDriverComponent::SetChaseTarget(v5, v8);
  UFG::AiDriverComponent::SetFollowOffset(v5, 0.0, 5.0, 10.0);
}

// File Line: 169
// RVA: 0x388100
void __fastcall DriverPathfindToTargetTask::SetupClosestRoadNetworkPosition(DriverPathfindToTargetTask *this, UFG::SimObject *pTarget, UFG::RoadSpaceComponent *pRoadSpaceComponent, UFG::AiDriverComponent *pAIDriverComponent, UFG::TransformNodeComponent *pMyTransform, UFG::TransformNodeComponent *pTargetTransform)
{
  DriverPathfindToTargetTask *v6; // r15
  UFG::AiDriverComponent *v7; // rbp
  UFG::RoadSpaceComponent *v8; // rdi
  UFG::RoadNetworkResource *v9; // r14
  unsigned int v10; // esi
  UFG::RoadNetworkIntersection *v11; // rbx
  UFG::RoadNetworkLocation *v12; // rax
  float v13; // xmm1_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  UFG::qMatrix44 matrix; // [rsp+30h] [rbp-58h]

  v6 = this;
  v7 = pAIDriverComponent;
  v8 = pRoadSpaceComponent;
  UFG::AiDriverComponent::SetDrivingMode(pAIDriverComponent, 2u);
  if ( v8 )
  {
    if ( !UFG::RoadSpaceComponent::IsAttachedToRoadNetwork(v8)
      || ((v9 = UFG::WheeledVehicleNavigationData::GetRoadNetwork(UFG::WheeledVehicleManager::m_Instance->m_NavigationData),
           v8 != (UFG::RoadSpaceComponent *)-552i64) ? (v10 = v8->mWayClient.m_RoadNetworkType) : (v10 = 0),
          UFG::TransformNodeComponent::UpdateWorldTransform(pMyTransform),
          v11 = UFG::RoadNetworkResource::GetClosestNode(
                  v9,
                  (UFG::qVector3 *)&pMyTransform->mWorldTransform.v3,
                  v10,
                  0i64,
                  0i64),
          v12 = Scaleform::GFx::AS3::Instances::fl::XML::GetName(&v8->mGuide),
          v11 != (UFG::RoadNetworkIntersection *)UFG::RoadNetworkLocation::GetRoadNetworkNode(v12)) )
    {
      UFG::RoadSpaceComponent::AttachToRoadNetwork(v8, 0);
    }
    v13 = v6->mClosestRoadDestination.y;
    matrix.v0 = UFG::qMatrix44::msIdentity.v0;
    matrix.v3.y = v13;
    LODWORD(matrix.v3.w) = (_DWORD)FLOAT_1_0;
    matrix.v1 = UFG::qMatrix44::msIdentity.v1;
    matrix.v2 = UFG::qMatrix44::msIdentity.v2;
    matrix.v3.x = v6->mClosestRoadDestination.x;
    matrix.v3.z = v6->mClosestRoadDestination.z;
    UFG::TransformNodeComponent::UpdateWorldTransform(pTargetTransform);
    v14 = pTargetTransform->mWorldTransform.v0.y;
    matrix.v0.x = pTargetTransform->mWorldTransform.v0.x;
    v15 = pTargetTransform->mWorldTransform.v0.z;
    matrix.v0.y = v14;
    matrix.v0.z = v15;
    matrix.v0.w = 0.0;
    UFG::RoadSpaceComponent::SetCarDestination(v8, &matrix);
    v7->m_StopAtUseDestinationDirection = 0;
    v7->m_GoToSlowDownForDestination = 1;
  }
}

// File Line: 203
// RVA: 0x344630
void __fastcall DriverPathfindToTargetTask::Begin(DriverPathfindToTargetTask *this, ActionContext *pContext)
{
  UFG::TransformNodeComponent *pMyTransform; // rdi
  DriverPathfindToTargetTask *v3; // rsi
  UFG::SimObjectGame *v4; // rcx
  UFG::CharacterOccupantComponent *v5; // rbx
  unsigned __int16 v6; // dx
  UFG::SimComponent *v7; // rax
  UFG::SimObjectGame *v8; // rcx
  unsigned __int16 v9; // dx
  UFG::SimComponent *v10; // r8
  UFG::SimComponent *v11; // rax
  UFG::SimObject *v12; // rbp
  UFG::SimObjectCVBase *v13; // rax
  UFG::RoadSpaceComponent *v14; // rbx
  UFG::AiDriverComponent *v15; // r9
  UFG::SimObject *v16; // rcx
  UFG::TransformNodeComponent *pTargetTransform; // ST28_8

  pMyTransform = 0i64;
  v3 = this;
  this->mpContext = pContext;
  this->mInThresholdTimer = 0.0;
  this->mIsCloseEnough = 0;
  v4 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v4 )
  {
    v6 = v4->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v5 = (UFG::CharacterOccupantComponent *)v4->m_Components.p[44].m_pComponent;
    }
    else
    {
      if ( (v6 & 0x8000u) == 0 )
      {
        if ( (v6 >> 13) & 1 )
        {
          v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::CharacterOccupantComponent::_TypeUID);
        }
        else if ( (v6 >> 12) & 1 )
        {
          v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::CharacterOccupantComponent::_TypeUID);
        }
        else
        {
          v7 = UFG::SimObject::GetComponentOfType(
                 (UFG::SimObject *)&v4->vfptr,
                 UFG::CharacterOccupantComponent::_TypeUID);
        }
      }
      else
      {
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::CharacterOccupantComponent::_TypeUID);
      }
      v5 = (UFG::CharacterOccupantComponent *)v7;
    }
  }
  else
  {
    v5 = 0i64;
  }
  v8 = (UFG::SimObjectGame *)v3->mpContext->mSimObject.m_pPointer;
  if ( v8
    && ((v9 = v8->m_Flags, !((v9 >> 14) & 1)) ? ((v9 & 0x8000u) == 0 ? (!((v9 >> 13) & 1) ? (!((v9 >> 12) & 1) ? (v11 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v8->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID)) : (v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::TargetingSystemBaseComponent::_TypeUID))) : (v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::TargetingSystemBaseComponent::_TypeUID)),
                                                                        v10 = v11) : (v10 = v8->m_Components.p[20].m_pComponent)) : (v10 = v8->m_Components.p[20].m_pComponent),
        v10) )
  {
    v12 = *(UFG::SimObject **)(56i64
                             * *(unsigned __int8 *)(LOBYTE(v3->m_Track[1].vfptr) + *(_QWORD *)&v10[1].m_Flags + 8i64)
                             + *(_QWORD *)&v10[1].m_TypeUID
                             + 40);
  }
  else
  {
    v12 = 0i64;
  }
  if ( v5 )
  {
    v13 = (UFG::SimObjectCVBase *)UFG::CharacterOccupantComponent::GetCurrentVehicle(v5);
    if ( v13 )
    {
      v14 = (UFG::RoadSpaceComponent *)v13->m_Components.p[24].m_pComponent;
      goto LABEL_32;
    }
  }
  else
  {
    v13 = 0i64;
  }
  v14 = 0i64;
LABEL_32:
  if ( v13 )
    v15 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v13);
  else
    v15 = 0i64;
  v16 = v3->mpContext->mSimObject.m_pPointer;
  if ( v16 )
    pMyTransform = v16->m_pTransformNodeComponent;
  if ( v12 && v14 )
  {
    if ( v15 )
    {
      pTargetTransform = v12->m_pTransformNodeComponent;
      v3->mAiDriverUseDirection = v15->m_StopAtUseDestinationDirection;
      v3->mAiDriverSlowDownForDestination = v15->m_GoToSlowDownForDestination;
      DriverPathfindToTargetTask::UpdateArrivalMode(v3, v12, v14, v15, pMyTransform, pTargetTransform);
    }
  }
}

// File Line: 233
// RVA: 0x38E420
char __fastcall DriverPathfindToTargetTask::Update(DriverPathfindToTargetTask *this, float timestep)
{
  DriverPathfindToTargetTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::CharacterOccupantComponent *v5; // rax
  UFG::SimObjectCVBase *v6; // rsi
  UFG::PhysicsMoverInterface *v7; // rcx
  UFG::qVector3 *v8; // rax
  UFG::SimObjectGame *v10; // rcx
  unsigned __int16 v11; // dx
  UFG::SimComponent *v12; // r8
  UFG::SimComponent *v13; // rax
  UFG::SimObject *v14; // r14
  UFG::RoadSpaceComponent *v15; // r15
  UFG::AiDriverComponent *v16; // rsi
  UFG::SimObject *v17; // rbp
  UFG::TransformNodeComponent *pMyTransform; // rbp
  UFG::TransformNodeComponent *pTargetTransform; // rdi
  ITrack *v20; // rcx
  char v21; // al
  float v22; // eax
  float v23; // xmm1_4
  float v24; // xmm9_4
  float v25; // xmm7_4
  float v26; // xmm8_4
  float v27; // xmm6_4
  char v28; // al
  UFG::qVector3 result; // [rsp+30h] [rbp-68h]

  v2 = this;
  v3 = (UFG::SimObjectGame *)this->mpContext->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v5 = (UFG::CharacterOccupantComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::CharacterOccupantComponent::_TypeUID)) : (v5 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterOccupantComponent::_TypeUID))) : (v5 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterOccupantComponent::_TypeUID))) : (v5 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterOccupantComponent::_TypeUID))) : (v5 = (UFG::CharacterOccupantComponent *)v3->m_Components.p[44].m_pComponent),
        v5) )
  {
    v6 = (UFG::SimObjectCVBase *)UFG::CharacterOccupantComponent::GetCurrentVehicle(v5);
  }
  else
  {
    v6 = 0i64;
  }
  if ( v2->mIsCloseEnough )
  {
    if ( !v6 )
      return 0;
    v7 = (UFG::PhysicsMoverInterface *)v6->m_Components.p[34].m_pComponent;
    if ( v7 )
    {
      v8 = UFG::PhysicsMoverInterface::GetVelocity(v7, &result);
      if ( (float)((float)((float)(v8->x * v8->x) + (float)(v8->y * v8->y)) + (float)(v8->z * v8->z)) < 1.0 )
        return 0;
    }
  }
  else
  {
    v10 = (UFG::SimObjectGame *)v2->mpContext->mSimObject.m_pPointer;
    if ( v10
      && ((v11 = v10->m_Flags, !((v11 >> 14) & 1)) ? ((v11 & 0x8000u) == 0 ? (!((v11 >> 13) & 1) ? (!((v11 >> 12) & 1) ? (v13 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v10->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID)) : (v13 = UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::TargetingSystemBaseComponent::_TypeUID))) : (v13 = UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::TargetingSystemBaseComponent::_TypeUID)),
                                                                              v12 = v13) : (v12 = v10->m_Components.p[20].m_pComponent)) : (v12 = v10->m_Components.p[20].m_pComponent),
          v12) )
    {
      v14 = *(UFG::SimObject **)(56i64
                               * *(unsigned __int8 *)(LOBYTE(v2->m_Track[1].vfptr) + *(_QWORD *)&v12[1].m_Flags + 8i64)
                               + *(_QWORD *)&v12[1].m_TypeUID
                               + 40);
    }
    else
    {
      v14 = 0i64;
    }
    if ( v6 )
      v15 = (UFG::RoadSpaceComponent *)v6->m_Components.p[24].m_pComponent;
    else
      v15 = 0i64;
    if ( v6 )
      v16 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v6);
    else
      v16 = 0i64;
    v17 = v2->mpContext->mSimObject.m_pPointer;
    if ( v17 )
      pMyTransform = v17->m_pTransformNodeComponent;
    else
      pMyTransform = 0i64;
    if ( v14 )
    {
      pTargetTransform = v14->m_pTransformNodeComponent;
      if ( v15 )
      {
        if ( v16 )
        {
          DriverPathfindToTargetTask::UpdateArrivalMode(v2, v14, v15, v16, pMyTransform, v14->m_pTransformNodeComponent);
          UFG::TransformNodeComponent::UpdateWorldTransform(pMyTransform);
          UFG::TransformNodeComponent::UpdateWorldTransform(pTargetTransform);
          if ( v2->mMode == 1 )
          {
            if ( (float)((float)((float)((float)(pTargetTransform->mWorldTransform.v3.x
                                               - pMyTransform->mWorldTransform.v3.x)
                                       * (float)(pTargetTransform->mWorldTransform.v3.x
                                               - pMyTransform->mWorldTransform.v3.x))
                               + (float)((float)(pTargetTransform->mWorldTransform.v3.y
                                               - pMyTransform->mWorldTransform.v3.y)
                                       * (float)(pTargetTransform->mWorldTransform.v3.y
                                               - pMyTransform->mWorldTransform.v3.y)))
                       + (float)((float)(pTargetTransform->mWorldTransform.v3.z - pMyTransform->mWorldTransform.v3.z)
                               * (float)(pTargetTransform->mWorldTransform.v3.z - pMyTransform->mWorldTransform.v3.z))) < (float)(*((float *)&v2->m_Track[1].vfptr + 1) * *((float *)&v2->m_Track[1].vfptr + 1)) )
              v2->mInThresholdTimer = timestep + v2->mInThresholdTimer;
            if ( UFG::AiDriverComponent::GetTimeAtOffset(v16, 0) > 0.1 )
              v2->mIsCloseEnough = 1;
          }
          else
          {
            v20 = v2->m_Track;
            v21 = 0;
            if ( (float)((float)((float)((float)(pTargetTransform->mWorldTransform.v3.y
                                               - pMyTransform->mWorldTransform.v3.y)
                                       * (float)(pTargetTransform->mWorldTransform.v3.y
                                               - pMyTransform->mWorldTransform.v3.y))
                               + (float)((float)(pTargetTransform->mWorldTransform.v3.x
                                               - pMyTransform->mWorldTransform.v3.x)
                                       * (float)(pTargetTransform->mWorldTransform.v3.x
                                               - pMyTransform->mWorldTransform.v3.x)))
                       + (float)((float)(pTargetTransform->mWorldTransform.v3.z - pMyTransform->mWorldTransform.v3.z)
                               * (float)(pTargetTransform->mWorldTransform.v3.z - pMyTransform->mWorldTransform.v3.z))) < (float)(*((float *)&v20[1].vfptr + 1) * *((float *)&v20[1].vfptr + 1)) )
            {
              v21 = 1;
              v2->mInThresholdTimer = timestep + v2->mInThresholdTimer;
            }
            if ( (float)((float)((float)((float)(v2->mClosestRoadDestination.y - pMyTransform->mWorldTransform.v3.y)
                                       * (float)(v2->mClosestRoadDestination.y - pMyTransform->mWorldTransform.v3.y))
                               + (float)((float)(v2->mClosestRoadDestination.x - pMyTransform->mWorldTransform.v3.x)
                                       * (float)(v2->mClosestRoadDestination.x - pMyTransform->mWorldTransform.v3.x)))
                       + (float)((float)(v2->mClosestRoadDestination.z - pMyTransform->mWorldTransform.v3.z)
                               * (float)(v2->mClosestRoadDestination.z - pMyTransform->mWorldTransform.v3.z))) >= (float)(*((float *)&v20[1].vfptr + 1) * *((float *)&v20[1].vfptr + 1)) )
            {
              if ( !v21
                && (float)((float)((float)((float)(pTargetTransform->mWorldTransform.v3.y - v2->mLastDestination.y)
                                         * (float)(pTargetTransform->mWorldTransform.v3.y - v2->mLastDestination.y))
                                 + (float)((float)(pTargetTransform->mWorldTransform.v3.x - v2->mLastDestination.x)
                                         * (float)(pTargetTransform->mWorldTransform.v3.x - v2->mLastDestination.x)))
                         + (float)((float)(pTargetTransform->mWorldTransform.v3.z - v2->mLastDestination.z)
                                 * (float)(pTargetTransform->mWorldTransform.v3.z - v2->mLastDestination.z))) > 25.0 )
              {
                UFG::TransformNodeComponent::UpdateWorldTransform(pTargetTransform);
                v22 = pTargetTransform->mWorldTransform.v3.x;
                v23 = pTargetTransform->mWorldTransform.v3.z;
                v2->mLastDestination.y = pTargetTransform->mWorldTransform.v3.y;
                v2->mLastDestination.z = v23;
                v2->mLastDestination.x = v22;
                DriverPathfindToTargetTask::SetupClosestRoadNetworkPosition(
                  v2,
                  v14,
                  v15,
                  v16,
                  pMyTransform,
                  pTargetTransform);
              }
            }
            else
            {
              v2->mInThresholdTimer = timestep + v2->mInThresholdTimer;
            }
          }
          v24 = FLOAT_0_5;
          if ( v2->mInThresholdTimer > 0.5 )
            v2->mIsCloseEnough = 1;
          if ( v2->mIsCloseEnough )
          {
            UFG::TransformNodeComponent::UpdateWorldTransform(pMyTransform);
            UFG::TransformNodeComponent::UpdateWorldTransform(pTargetTransform);
            v25 = pTargetTransform->mWorldTransform.v3.x - pMyTransform->mWorldTransform.v3.x;
            v26 = pTargetTransform->mWorldTransform.v3.y - pMyTransform->mWorldTransform.v3.y;
            v27 = pTargetTransform->mWorldTransform.v3.z - pMyTransform->mWorldTransform.v3.z;
            UFG::TransformNodeComponent::UpdateWorldTransform(pMyTransform);
            if ( (float)((float)((float)(v26 * pMyTransform->mWorldTransform.v1.y)
                               + (float)(v25 * pMyTransform->mWorldTransform.v1.x))
                       + (float)(v27 * pMyTransform->mWorldTransform.v1.z)) > 0.0 )
              v24 = FLOAT_N0_5;
            v28 = LOBYTE(result.z);
            *((_BYTE *)&v16->m_StopInfo + 8) &= 0xFEu;
            v16->m_StopInfo.fSteeringOverride = v24;
            v16->m_StopInfo.eStopStyle = 1;
            *((_BYTE *)&v16->m_StopInfo + 8) |= (v28 | 1) & 1;
            UFG::AiDriverComponent::SetDrivingMode(v16, 0);
            UFG::AiDriverComponent::SetChaseTarget(v16, 0i64);
            UFG::AiDriverComponent::SetGasBrakeLock(v16, 1.0);
          }
        }
      }
    }
  }
  return 1;
}

// File Line: 346
// RVA: 0x354F30
void __fastcall DriverPathfindToTargetTask::End(DriverPathfindToTargetTask *this)
{
  DriverPathfindToTargetTask *v1; // rdi
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::CharacterOccupantComponent *v4; // rax
  UFG::SimObjectCVBase *v5; // rax
  UFG::AiDriverComponent *v6; // rax
  UFG::AiDriverComponent *v7; // rbx

  v1 = this;
  v2 = (UFG::SimObjectGame *)this->mpContext->mSimObject.m_pPointer;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = (UFG::CharacterOccupantComponent *)v2->m_Components.p[44].m_pComponent;
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
      {
        v4 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  v2,
                                                  UFG::CharacterOccupantComponent::_TypeUID);
      }
      else if ( (v3 >> 12) & 1 )
      {
        v4 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  v2,
                                                  UFG::CharacterOccupantComponent::_TypeUID);
      }
      else
      {
        v4 = (UFG::CharacterOccupantComponent *)UFG::SimObject::GetComponentOfType(
                                                  (UFG::SimObject *)&v2->vfptr,
                                                  UFG::CharacterOccupantComponent::_TypeUID);
      }
    }
    else
    {
      v4 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                v2,
                                                UFG::CharacterOccupantComponent::_TypeUID);
    }
    if ( v4 )
    {
      v5 = (UFG::SimObjectCVBase *)UFG::CharacterOccupantComponent::GetCurrentVehicle(v4);
      if ( v5 )
      {
        v6 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v5);
        v7 = v6;
        if ( v6 )
        {
          UFG::AiDriverComponent::ClearGasBrakeLock(v6);
          v7->m_StopAtUseDestinationDirection = v1->mAiDriverUseDirection;
          v7->m_GoToSlowDownForDestination = v1->mAiDriverSlowDownForDestination;
        }
      }
    }
  }
}

// File Line: 368
// RVA: 0x32DE00
void __fastcall DriverFollowTargetTask::DriverFollowTargetTask(DriverFollowTargetTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable';
  this->vfptr = (ITaskVtbl *)&Task<DriverFollowTargetTrack>::`vftable';
  this->vfptr = (ITaskVtbl *)&DriverFollowTargetTask::`vftable';
}

// File Line: 407
// RVA: 0x32DC60
void __fastcall DriverChaseTargetTask::DriverChaseTargetTask(DriverChaseTargetTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable';
  this->vfptr = (ITaskVtbl *)&Task<DriverChaseTargetTrack>::`vftable';
  this->vfptr = (ITaskVtbl *)&DriverChaseTargetTask::`vftable';
}

// File Line: 427
// RVA: 0x3567F0
bool __fastcall FindDriverAndVehicle(ActionContext *pContext, UFG::SimObjectVehicle **ppVehicle, UFG::SimObject **ppDriver, UFG::TargetingSystemBaseComponent **ppTSBC)
{
  UFG::SimObjectGame *v4; // rbx
  UFG::SimComponent *v5; // rdi
  UFG::TargetingSystemBaseComponent **v6; // r14
  UFG::SimObject **v7; // r15
  UFG::SimObjectVehicle **v8; // rbp
  ActionContext *v9; // rsi
  unsigned __int16 v10; // r9
  UFG::CharacterOccupantComponent *v11; // rax
  UFG::SimObject *v12; // r8
  unsigned __int16 v13; // cx
  bool result; // al
  UFG::SimObjectGame *v15; // rcx
  bool v16; // zf
  unsigned __int16 v17; // cx
  UFG::SimComponent *v18; // rax
  UFG::SimObjectGame *v19; // rax
  unsigned __int16 v20; // dx
  unsigned int v21; // edx

  v4 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  v5 = 0i64;
  v6 = ppTSBC;
  *ppVehicle = 0i64;
  *ppDriver = 0i64;
  v7 = ppDriver;
  v8 = ppVehicle;
  v9 = pContext;
  *ppTSBC = 0i64;
  if ( !v4 )
    return 0;
  v10 = v4->m_Flags;
  if ( (v10 >> 14) & 1 )
  {
    v11 = (UFG::CharacterOccupantComponent *)v4->m_Components.p[44].m_pComponent;
  }
  else if ( (v10 & 0x8000u) == 0 )
  {
    if ( (v10 >> 13) & 1 )
    {
      v11 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 v4,
                                                 UFG::CharacterOccupantComponent::_TypeUID);
    }
    else if ( (v10 >> 12) & 1 )
    {
      v11 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 v4,
                                                 UFG::CharacterOccupantComponent::_TypeUID);
    }
    else
    {
      v11 = (UFG::CharacterOccupantComponent *)UFG::SimObject::GetComponentOfType(
                                                 (UFG::SimObject *)&v4->vfptr,
                                                 UFG::CharacterOccupantComponent::_TypeUID);
    }
  }
  else
  {
    v11 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               v4,
                                               UFG::CharacterOccupantComponent::_TypeUID);
  }
  if ( !v11 )
  {
    v17 = v4->m_Flags;
    if ( (v17 >> 14) & 1 )
    {
      v18 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::VehicleOccupantComponent::_TypeUID);
    }
    else if ( (v17 & 0x8000u) == 0 )
    {
      if ( (v17 >> 13) & 1 )
      {
        v18 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::VehicleOccupantComponent::_TypeUID);
      }
      else if ( (v17 >> 12) & 1 )
      {
        v18 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::VehicleOccupantComponent::_TypeUID);
      }
      else
      {
        v18 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::VehicleOccupantComponent::_TypeUID);
      }
    }
    else
    {
      v18 = v4->m_Components.p[30].m_pComponent;
    }
    if ( v18 )
    {
      *v8 = (UFG::SimObjectVehicle *)v4;
      v19 = (UFG::SimObjectGame *)Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture((hkSimpleLocalFrame *)v18);
      *v7 = (UFG::SimObject *)&v19->vfptr;
      if ( v19 )
      {
        v20 = v19->m_Flags;
        if ( (v20 >> 14) & 1 )
        {
          *v6 = (UFG::TargetingSystemBaseComponent *)v19->m_Components.p[20].m_pComponent;
          return 1;
        }
        if ( (v20 & 0x8000u) != 0 )
        {
          *v6 = (UFG::TargetingSystemBaseComponent *)v19->m_Components.p[20].m_pComponent;
          return 1;
        }
        if ( (v20 >> 13) & 1 )
        {
          v21 = UFG::TargetingSystemBaseComponent::_TypeUID;
        }
        else
        {
          v16 = ((v20 >> 12) & 1) == 0;
          v21 = UFG::TargetingSystemBaseComponent::_TypeUID;
          if ( v16 )
          {
            *v6 = (UFG::TargetingSystemBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                         (UFG::SimObject *)&v19->vfptr,
                                                         UFG::TargetingSystemBaseComponent::_TypeUID);
            return 1;
          }
        }
        *v6 = (UFG::TargetingSystemBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v19, v21);
        return 1;
      }
    }
    return 0;
  }
  *v8 = (UFG::SimObjectVehicle *)UFG::CharacterOccupantComponent::GetCurrentVehicle(v11);
  *v7 = (UFG::SimObject *)&v4->vfptr;
  v12 = v9->mSimObject.m_pPointer;
  if ( v12 )
  {
    v13 = v12->m_Flags;
    if ( (v13 >> 14) & 1 || (v13 & 0x8000u) != 0 )
    {
      result = 1;
      *v6 = (UFG::TargetingSystemBaseComponent *)v12->m_Components.p[20].m_pComponent;
      return result;
    }
    if ( (v13 >> 13) & 1 )
    {
      v15 = (UFG::SimObjectGame *)v9->mSimObject.m_pPointer;
LABEL_18:
      *v6 = (UFG::TargetingSystemBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   v15,
                                                   UFG::TargetingSystemBaseComponent::_TypeUID);
      return 1;
    }
    v16 = ((v13 >> 12) & 1) == 0;
    v15 = (UFG::SimObjectGame *)v9->mSimObject.m_pPointer;
    if ( !v16 )
      goto LABEL_18;
    v5 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v15->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
  }
  *v6 = (UFG::TargetingSystemBaseComponent *)v5;
  return 1;
}

// File Line: 461
// RVA: 0x38E2E0
char __fastcall DriverChaseTargetTask::Update(DriverChaseTargetTask *this, float timestep)
{
  DriverChaseTargetTask *v2; // rbx
  ActionContext *v3; // rcx
  UFG::SimObjectGame *v4; // rbx
  UFG::AiDriverComponent *v5; // rax
  UFG::AiDriverComponent *v6; // rdi
  unsigned __int16 v7; // dx
  UFG::CharacterOccupantComponent *v8; // rax
  UFG::SimObject *v9; // rdx
  UFG::TargetingSystemBaseComponent *ppTSBC; // [rsp+30h] [rbp+8h]
  UFG::SimObjectVehicle *ppVehicle; // [rsp+40h] [rbp+18h]
  UFG::SimObject *ppDriver; // [rsp+48h] [rbp+20h]

  v2 = this;
  v3 = this->mpContext;
  ppVehicle = 0i64;
  ppDriver = 0i64;
  ppTSBC = 0i64;
  if ( !FindDriverAndVehicle(v3, &ppVehicle, &ppDriver, &ppTSBC) )
    return 0;
  v4 = (UFG::SimObjectGame *)ppTSBC->m_pTargets[(unsigned __int8)ppTSBC->m_pTargetingMap->m_Map.p[LOBYTE(v2->m_Track[1].vfptr)]].m_pTarget.m_pPointer;
  if ( v4 )
  {
    if ( ppVehicle )
    {
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>((UFG::SimObjectCVBase *)&ppVehicle->vfptr);
      v6 = v5;
      if ( v5 )
      {
        UFG::AiDriverComponent::SetDrivingMode(v5, 3u);
        v7 = v4->m_Flags;
        if ( (v7 >> 14) & 1 )
        {
          v8 = (UFG::CharacterOccupantComponent *)v4->m_Components.p[44].m_pComponent;
        }
        else if ( (v7 & 0x8000u) == 0 )
        {
          if ( (v7 >> 13) & 1 )
          {
            v8 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      v4,
                                                      UFG::CharacterOccupantComponent::_TypeUID);
          }
          else if ( (v7 >> 12) & 1 )
          {
            v8 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      v4,
                                                      UFG::CharacterOccupantComponent::_TypeUID);
          }
          else
          {
            v8 = (UFG::CharacterOccupantComponent *)UFG::SimObject::GetComponentOfType(
                                                      (UFG::SimObject *)&v4->vfptr,
                                                      UFG::CharacterOccupantComponent::_TypeUID);
          }
        }
        else
        {
          v8 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    v4,
                                                    UFG::CharacterOccupantComponent::_TypeUID);
        }
        if ( !v8 || (v9 = (UFG::SimObject *)UFG::CharacterOccupantComponent::GetCurrentVehicle(v8)) == 0i64 )
          v9 = (UFG::SimObject *)&v4->vfptr;
        UFG::AiDriverComponent::SetChaseTarget(v6, v9);
      }
    }
  }
  return 1;
}

// File Line: 519
// RVA: 0x32E040
void __fastcall DriverWanderTask::DriverWanderTask(DriverWanderTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AiDriverComponent> *v2; // [rsp+28h] [rbp+10h]

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable';
  this->vfptr = (ITaskVtbl *)&Task<DriverWanderTrack>::`vftable';
  this->vfptr = (ITaskVtbl *)&DriverWanderTask::`vftable';
  v2 = &this->mpAIComponent;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  this->mpAIComponent.m_pPointer = 0i64;
}

// File Line: 526
// RVA: 0x3365D0
void __fastcall DriverWanderTask::~DriverWanderTask(DriverWanderTask *this)
{
  DriverWanderTask *v1; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::AiDriverComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rdx
  UFG::qNode<ITask,ITask> *v8; // rcx
  UFG::qNode<ITask,ITask> *v9; // rax

  v1 = this;
  this->vfptr = (ITaskVtbl *)&DriverWanderTask::`vftable';
  v2 = &this->mpAIComponent;
  if ( this->mpAIComponent.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  }
  v2->m_pPointer = 0i64;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v1->vfptr = (ITaskVtbl *)&ITask::`vftable';
  v7 = (UFG::qNode<ITask,ITask> *)&v1->mPrev;
  v8 = v1->mPrev;
  v9 = v1->mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v7->mPrev = v7;
  v7->mNext = v7;
}

// File Line: 551
// RVA: 0x38E9D0
char __fastcall DriverWanderTask::Update(DriverWanderTask *this, float timestep)
{
  DriverWanderTask *v2; // rbx
  UFG::AiDriverComponent *v3; // rcx

  v2 = this;
  v3 = (UFG::AiDriverComponent *)this->mpAIComponent.m_pPointer;
  if ( !v3 )
    return 0;
  UFG::AiDriverComponent::SetDrivingRole(v3, 0);
  UFG::AiDriverComponent::SetDrivingMode((UFG::AiDriverComponent *)v2->mpAIComponent.m_pPointer, 1u);
  return 1;
}

// File Line: 575
// RVA: 0x32DFA0
void __fastcall DriverStopTask::DriverStopTask(DriverStopTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AiDriverComponent> *v2; // [rsp+28h] [rbp+10h]

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable';
  this->vfptr = (ITaskVtbl *)&Task<DriverStopTrack>::`vftable';
  this->vfptr = (ITaskVtbl *)&DriverStopTask::`vftable';
  v2 = &this->mpAIComponent;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  this->mpAIComponent.m_pPointer = 0i64;
}

// File Line: 582
// RVA: 0x3364D0
void __fastcall DriverStopTask::~DriverStopTask(DriverStopTask *this)
{
  DriverStopTask *v1; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::AiDriverComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rdx
  UFG::qNode<ITask,ITask> *v8; // rcx
  UFG::qNode<ITask,ITask> *v9; // rax

  v1 = this;
  this->vfptr = (ITaskVtbl *)&DriverStopTask::`vftable';
  v2 = &this->mpAIComponent;
  if ( this->mpAIComponent.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  }
  v2->m_pPointer = 0i64;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v1->vfptr = (ITaskVtbl *)&ITask::`vftable';
  v7 = (UFG::qNode<ITask,ITask> *)&v1->mPrev;
  v8 = v1->mPrev;
  v9 = v1->mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v7->mPrev = v7;
  v7->mNext = v7;
}

// File Line: 587
// RVA: 0x344810
void __fastcall DriverStopTask::Begin(DriverWanderTask *this, ActionContext *action_context)
{
  DriverWanderTask *v2; // rdi
  UFG::AiDriverComponent *v3; // rbx
  UFG::qSafePointer<UFG::SimComponent,UFG::AiDriverComponent> *v4; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::SimObjectVehicle *ppVehicle; // [rsp+30h] [rbp+8h]
  UFG::SimObject *ppDriver; // [rsp+38h] [rbp+10h]
  UFG::TargetingSystemBaseComponent *ppTSBC; // [rsp+40h] [rbp+18h]

  v2 = this;
  this->mpContext = action_context;
  if ( action_context )
  {
    v3 = 0i64;
    ppVehicle = 0i64;
    ppDriver = 0i64;
    if ( FindDriverAndVehicle(action_context, &ppVehicle, &ppDriver, &ppTSBC) )
    {
      if ( ppVehicle )
        v3 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>((UFG::SimObjectCVBase *)&ppVehicle->vfptr);
      v4 = &v2->mpAIComponent;
      if ( v2->mpAIComponent.m_pPointer )
      {
        v5 = v4->mPrev;
        v6 = v2->mpAIComponent.mNext;
        v5->mNext = v6;
        v6->mPrev = v5;
        v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
        v2->mpAIComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mpAIComponent.mPrev;
      }
      v2->mpAIComponent.m_pPointer = (UFG::SimComponent *)&v3->vfptr;
      if ( v3 )
      {
        v7 = v3->m_SafePointerList.mNode.mPrev;
        v7->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
        v4->mPrev = v7;
        v2->mpAIComponent.mNext = &v3->m_SafePointerList.mNode;
        v3->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
      }
    }
  }
}

// File Line: 607
// RVA: 0x38E990
char __fastcall DriverStopTask::Update(DriverStopTask *this, float timestep)
{
  DriverStopTask *v2; // rbx
  UFG::AiDriverComponent *v3; // rcx

  v2 = this;
  v3 = (UFG::AiDriverComponent *)this->mpAIComponent.m_pPointer;
  if ( !v3 )
    return 0;
  UFG::AiDriverComponent::SetDrivingRole(v3, 0);
  UFG::AiDriverComponent::SetDrivingMode((UFG::AiDriverComponent *)v2->mpAIComponent.m_pPointer, 0);
  return 1;
}

