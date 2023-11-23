// File Line: 54
// RVA: 0x32DEA0
void __fastcall DriverPathfindToTargetTask::DriverPathfindToTargetTask(DriverPathfindToTargetTask *this)
{
  float y; // xmm1_4
  float z; // xmm2_4
  float v3; // xmm1_4
  float v4; // xmm2_4

  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<DriverPathfindToTargetTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&DriverPathfindToTargetTask::`vftable;
  this->mpContext = 0i64;
  this->mIsCloseEnough = 0;
  this->mInThresholdTimer = 0.0;
  *(_WORD *)&this->mAiDriverUseDirection = 0;
  this->mMode = Mode_None;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->mLastDestination.x = UFG::qVector3::msZero.x;
  this->mLastDestination.y = y;
  this->mLastDestination.z = z;
  v3 = UFG::qVector3::msZero.y;
  v4 = UFG::qVector3::msZero.z;
  this->mClosestRoadDestination.x = UFG::qVector3::msZero.x;
  this->mClosestRoadDestination.y = v3;
  this->mClosestRoadDestination.z = v4;
}

// File Line: 68
// RVA: 0x3941B0
void __fastcall DriverPathfindToTargetTask::UpdateArrivalMode(
        DriverPathfindToTargetTask *this,
        UFG::SimObjectGame *pTarget,
        UFG::RoadSpaceComponent *pRoadSpaceComponent,
        UFG::AiDriverComponent *pAIDriverComponent,
        UFG::TransformNodeComponent *pMyTransform,
        UFG::TransformNodeComponent *pTargetTransform)
{
  UFG::RoadNetworkResource *RoadNetwork; // r15
  float y; // xmm1_4
  float z; // xmm0_4
  unsigned int m_RoadNetworkType; // r8d
  UFG::RoadNetworkIntersection *ClosestNode; // rax
  UFG::qVector3 *ClosestPosition; // rax
  float v16; // xmm0_4
  float v17; // xmm1_4
  DriverPathfindToTargetTask::Mode v18; // eax
  UFG::qVector3 pos; // [rsp+30h] [rbp-38h] BYREF
  UFG::qVector3 result; // [rsp+40h] [rbp-28h] BYREF

  RoadNetwork = UFG::WheeledVehicleNavigationData::GetRoadNetwork(UFG::WheeledVehicleManager::m_Instance->m_NavigationData);
  if ( RoadNetwork )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(pTargetTransform);
    y = pTargetTransform->mWorldTransform.v3.y;
    pos.x = pTargetTransform->mWorldTransform.v3.x;
    z = pTargetTransform->mWorldTransform.v3.z;
    pos.y = y;
    pos.z = z;
    if ( pRoadSpaceComponent == (UFG::RoadSpaceComponent *)-552i64 )
      m_RoadNetworkType = 0;
    else
      m_RoadNetworkType = pRoadSpaceComponent->mWayClient.m_RoadNetworkType;
    ClosestNode = UFG::RoadNetworkResource::GetClosestNode(RoadNetwork, &pos, m_RoadNetworkType, 0i64, 0i64);
    ClosestPosition = UFG::RoadNetworkNode::GetClosestPosition(ClosestNode, &result, &pos, 0i64);
    v16 = ClosestPosition->y;
    v17 = ClosestPosition->z;
    this->mClosestRoadDestination.x = ClosestPosition->x;
    v18 = Mode_ClosestRoadNetworkPosition;
    this->mClosestRoadDestination.y = v16;
    this->mClosestRoadDestination.z = v17;
  }
  else
  {
    v18 = Mode_ClosestPosition;
  }
  if ( this->mMode != v18 )
  {
    this->mMode = v18;
    if ( v18 == Mode_ClosestPosition )
      DriverPathfindToTargetTask::SetupClosestPosition(this, pTarget, pRoadSpaceComponent, pAIDriverComponent);
    else
      DriverPathfindToTargetTask::SetupClosestRoadNetworkPosition(
        this,
        pTarget,
        pRoadSpaceComponent,
        pAIDriverComponent,
        pMyTransform,
        pTargetTransform);
    if ( pAIDriverComponent )
      pAIDriverComponent->m_bIgnoreArrivalDirection = BYTE1(this->m_Track[1].vfptr) != 0;
  }
}

// File Line: 146
// RVA: 0x388030
void __fastcall DriverPathfindToTargetTask::SetupClosestPosition(
        DriverPathfindToTargetTask *this,
        UFG::SimObjectGame *pTarget,
        UFG::RoadSpaceComponent *pRoadSpaceComponent,
        UFG::AiDriverComponent *pAIDriverComponent)
{
  signed __int16 m_Flags; // cx
  UFG::CharacterOccupantComponent *ComponentOfType; // rax
  UFG::SimObject *CurrentVehicle; // rdx

  UFG::AiDriverComponent::SetDrivingMode(pAIDriverComponent, 4u);
  if ( !pTarget
    || ((m_Flags = pTarget->m_Flags, (m_Flags & 0x4000) == 0)
      ? (m_Flags >= 0 && (m_Flags & 0x2000) == 0 && (m_Flags & 0x1000) == 0
       ? (ComponentOfType = (UFG::CharacterOccupantComponent *)UFG::SimObject::GetComponentOfType(
                                                                 pTarget,
                                                                 UFG::CharacterOccupantComponent::_TypeUID))
       : (ComponentOfType = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                 pTarget,
                                                                 UFG::CharacterOccupantComponent::_TypeUID)))
      : (ComponentOfType = (UFG::CharacterOccupantComponent *)pTarget->m_Components.p[44].m_pComponent),
        !ComponentOfType
     || (CurrentVehicle = (UFG::SimObject *)UFG::CharacterOccupantComponent::GetCurrentVehicle(ComponentOfType)) == 0i64) )
  {
    CurrentVehicle = pTarget;
  }
  UFG::AiDriverComponent::SetChaseTarget(pAIDriverComponent, CurrentVehicle);
  UFG::AiDriverComponent::SetFollowOffset(pAIDriverComponent, 0.0, 5.0, 10.0);
}

// File Line: 169
// RVA: 0x388100
void __fastcall DriverPathfindToTargetTask::SetupClosestRoadNetworkPosition(
        DriverPathfindToTargetTask *this,
        UFG::SimObject *pTarget,
        UFG::RoadSpaceComponent *pRoadSpaceComponent,
        UFG::AiDriverComponent *pAIDriverComponent,
        UFG::TransformNodeComponent *pMyTransform,
        UFG::TransformNodeComponent *pTargetTransform)
{
  UFG::RoadNetworkResource *RoadNetwork; // r14
  unsigned int m_RoadNetworkType; // esi
  UFG::RoadNetworkIntersection *ClosestNode; // rbx
  UFG::RoadNetworkLocation *Name; // rax
  float y; // xmm1_4
  float v14; // xmm1_4
  float z; // xmm0_4
  UFG::qMatrix44 matrix; // [rsp+30h] [rbp-58h] BYREF

  UFG::AiDriverComponent::SetDrivingMode(pAIDriverComponent, 2u);
  if ( pRoadSpaceComponent )
  {
    if ( !UFG::RoadSpaceComponent::IsAttachedToRoadNetwork(pRoadSpaceComponent)
      || ((RoadNetwork = UFG::WheeledVehicleNavigationData::GetRoadNetwork(UFG::WheeledVehicleManager::m_Instance->m_NavigationData),
           pRoadSpaceComponent != (UFG::RoadSpaceComponent *)-552i64)
        ? (m_RoadNetworkType = pRoadSpaceComponent->mWayClient.m_RoadNetworkType)
        : (m_RoadNetworkType = 0),
          UFG::TransformNodeComponent::UpdateWorldTransform(pMyTransform),
          ClosestNode = UFG::RoadNetworkResource::GetClosestNode(
                          RoadNetwork,
                          (UFG::qVector3 *)&pMyTransform->mWorldTransform.v3,
                          m_RoadNetworkType,
                          0i64,
                          0i64),
          Name = Scaleform::GFx::AS3::Instances::fl::XML::GetName(&pRoadSpaceComponent->mGuide),
          ClosestNode != UFG::RoadNetworkLocation::GetRoadNetworkNode(Name)) )
    {
      UFG::RoadSpaceComponent::AttachToRoadNetwork(pRoadSpaceComponent, 0);
    }
    y = this->mClosestRoadDestination.y;
    matrix.v0 = UFG::qMatrix44::msIdentity.v0;
    matrix.v3.y = y;
    LODWORD(matrix.v3.w) = (_DWORD)FLOAT_1_0;
    matrix.v1 = UFG::qMatrix44::msIdentity.v1;
    matrix.v2 = UFG::qMatrix44::msIdentity.v2;
    matrix.v3.x = this->mClosestRoadDestination.x;
    matrix.v3.z = this->mClosestRoadDestination.z;
    UFG::TransformNodeComponent::UpdateWorldTransform(pTargetTransform);
    v14 = pTargetTransform->mWorldTransform.v0.y;
    matrix.v0.x = pTargetTransform->mWorldTransform.v0.x;
    z = pTargetTransform->mWorldTransform.v0.z;
    matrix.v0.y = v14;
    matrix.v0.z = z;
    matrix.v0.w = 0.0;
    UFG::RoadSpaceComponent::SetCarDestination(pRoadSpaceComponent, &matrix);
    pAIDriverComponent->m_StopAtUseDestinationDirection = 0;
    pAIDriverComponent->m_GoToSlowDownForDestination = 1;
  }
}

// File Line: 203
// RVA: 0x344630
void __fastcall DriverPathfindToTargetTask::Begin(DriverPathfindToTargetTask *this, ActionContext *pContext)
{
  UFG::TransformNodeComponent *pMyTransform; // rdi
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::CharacterOccupantComponent *m_pComponent; // rbx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectGame *v8; // rcx
  __int16 v9; // dx
  UFG::SimComponent *v10; // r8
  UFG::SimComponent *ComponentOfType; // rax
  UFG::SimObject *v12; // rbp
  UFG::SimObjectCVBase *CurrentVehicle; // rax
  UFG::RoadSpaceComponent *v14; // rbx
  UFG::AiDriverComponent *v15; // r9
  UFG::SimObject *v16; // rcx
  UFG::TransformNodeComponent *pTargetTransform; // [rsp+28h] [rbp-10h]

  pMyTransform = 0i64;
  this->mpContext = pContext;
  this->mInThresholdTimer = 0.0;
  this->mIsCloseEnough = 0;
  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::CharacterOccupantComponent *)m_pPointer->m_Components.p[44].m_pComponent;
    }
    else
    {
      if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                              m_pPointer,
                              UFG::CharacterOccupantComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::CharacterOccupantComponent::_TypeUID);
      m_pComponent = (UFG::CharacterOccupantComponent *)ComponentOfTypeHK;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  v8 = (UFG::SimObjectGame *)this->mpContext->mSimObject.m_pPointer;
  if ( v8
    && ((v9 = v8->m_Flags, (v9 & 0x4000) == 0)
      ? (v9 >= 0
       ? ((v9 & 0x2000) != 0 || (v9 & 0x1000) != 0
        ? (ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::TargetingSystemBaseComponent::_TypeUID))
        : (ComponentOfType = UFG::SimObject::GetComponentOfType(v8, UFG::TargetingSystemBaseComponent::_TypeUID)),
          v10 = ComponentOfType)
       : (v10 = v8->m_Components.p[20].m_pComponent))
      : (v10 = v8->m_Components.p[20].m_pComponent),
        v10) )
  {
    v12 = *(UFG::SimObject **)(56i64
                             * *(unsigned __int8 *)(LOBYTE(this->m_Track[1].vfptr) + *(_QWORD *)&v10[1].m_Flags + 8i64)
                             + *(_QWORD *)&v10[1].m_TypeUID
                             + 40);
  }
  else
  {
    v12 = 0i64;
  }
  if ( m_pComponent )
  {
    CurrentVehicle = (UFG::SimObjectCVBase *)UFG::CharacterOccupantComponent::GetCurrentVehicle(m_pComponent);
    if ( CurrentVehicle )
    {
      v14 = (UFG::RoadSpaceComponent *)CurrentVehicle->m_Components.p[24].m_pComponent;
      goto LABEL_30;
    }
  }
  else
  {
    CurrentVehicle = 0i64;
  }
  v14 = 0i64;
LABEL_30:
  if ( CurrentVehicle )
    v15 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(CurrentVehicle);
  else
    v15 = 0i64;
  v16 = this->mpContext->mSimObject.m_pPointer;
  if ( v16 )
    pMyTransform = v16->m_pTransformNodeComponent;
  if ( v12 && v14 )
  {
    if ( v15 )
    {
      pTargetTransform = v12->m_pTransformNodeComponent;
      this->mAiDriverUseDirection = v15->m_StopAtUseDestinationDirection;
      this->mAiDriverSlowDownForDestination = v15->m_GoToSlowDownForDestination;
      DriverPathfindToTargetTask::UpdateArrivalMode(this, v12, v14, v15, pMyTransform, pTargetTransform);
    }
  }
}

// File Line: 233
// RVA: 0x38E420
char __fastcall DriverPathfindToTargetTask::Update(DriverPathfindToTargetTask *this, float timestep)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::CharacterOccupantComponent *ComponentOfType; // rax
  UFG::SimObjectCVBase *CurrentVehicle; // rsi
  UFG::PhysicsMoverInterface *m_pComponent; // rcx
  UFG::qVector3 *Velocity; // rax
  UFG::SimObjectGame *v10; // rcx
  __int16 v11; // dx
  UFG::SimComponent *v12; // r8
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObject *v14; // r14
  UFG::RoadSpaceComponent *v15; // r15
  UFG::AiDriverComponent *v16; // rsi
  UFG::SimObject *v17; // rbp
  UFG::TransformNodeComponent *pMyTransform; // rbp
  UFG::TransformNodeComponent *pTargetTransform; // rdi
  ITrack *m_Track; // rcx
  char v21; // al
  float x; // eax
  float z; // xmm1_4
  float v24; // xmm9_4
  float v25; // xmm7_4
  float v26; // xmm8_4
  float v27; // xmm6_4
  UFG::qVector3 result; // [rsp+30h] [rbp-68h] BYREF

  m_pPointer = (UFG::SimObjectGame *)this->mpContext->mSimObject.m_pPointer;
  if ( m_pPointer
    && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
      ? (m_Flags >= 0 && (m_Flags & 0x2000) == 0 && (m_Flags & 0x1000) == 0
       ? (ComponentOfType = (UFG::CharacterOccupantComponent *)UFG::SimObject::GetComponentOfType(
                                                                 m_pPointer,
                                                                 UFG::CharacterOccupantComponent::_TypeUID))
       : (ComponentOfType = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                 m_pPointer,
                                                                 UFG::CharacterOccupantComponent::_TypeUID)))
      : (ComponentOfType = (UFG::CharacterOccupantComponent *)m_pPointer->m_Components.p[44].m_pComponent),
        ComponentOfType) )
  {
    CurrentVehicle = (UFG::SimObjectCVBase *)UFG::CharacterOccupantComponent::GetCurrentVehicle(ComponentOfType);
  }
  else
  {
    CurrentVehicle = 0i64;
  }
  if ( this->mIsCloseEnough )
  {
    if ( !CurrentVehicle )
      return 0;
    m_pComponent = (UFG::PhysicsMoverInterface *)CurrentVehicle->m_Components.p[34].m_pComponent;
    if ( m_pComponent )
    {
      Velocity = UFG::PhysicsMoverInterface::GetVelocity(m_pComponent, &result);
      if ( (float)((float)((float)(Velocity->x * Velocity->x) + (float)(Velocity->y * Velocity->y))
                 + (float)(Velocity->z * Velocity->z)) < 1.0 )
        return 0;
    }
  }
  else
  {
    v10 = (UFG::SimObjectGame *)this->mpContext->mSimObject.m_pPointer;
    if ( v10
      && ((v11 = v10->m_Flags, (v11 & 0x4000) == 0)
        ? (v11 >= 0
         ? ((v11 & 0x2000) != 0 || (v11 & 0x1000) != 0
          ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                   v10,
                                   UFG::TargetingSystemBaseComponent::_TypeUID))
          : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v10, UFG::TargetingSystemBaseComponent::_TypeUID)),
            v12 = ComponentOfTypeHK)
         : (v12 = v10->m_Components.p[20].m_pComponent))
        : (v12 = v10->m_Components.p[20].m_pComponent),
          v12) )
    {
      v14 = *(UFG::SimObject **)(56i64
                               * *(unsigned __int8 *)(LOBYTE(this->m_Track[1].vfptr) + *(_QWORD *)&v12[1].m_Flags + 8i64)
                               + *(_QWORD *)&v12[1].m_TypeUID
                               + 40);
    }
    else
    {
      v14 = 0i64;
    }
    if ( CurrentVehicle )
      v15 = (UFG::RoadSpaceComponent *)CurrentVehicle->m_Components.p[24].m_pComponent;
    else
      v15 = 0i64;
    if ( CurrentVehicle )
      v16 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(CurrentVehicle);
    else
      v16 = 0i64;
    v17 = this->mpContext->mSimObject.m_pPointer;
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
          DriverPathfindToTargetTask::UpdateArrivalMode(
            this,
            v14,
            v15,
            v16,
            pMyTransform,
            v14->m_pTransformNodeComponent);
          UFG::TransformNodeComponent::UpdateWorldTransform(pMyTransform);
          UFG::TransformNodeComponent::UpdateWorldTransform(pTargetTransform);
          if ( this->mMode == Mode_ClosestPosition )
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
                               * (float)(pTargetTransform->mWorldTransform.v3.z - pMyTransform->mWorldTransform.v3.z))) < (float)(*((float *)&this->m_Track[1].vfptr + 1) * *((float *)&this->m_Track[1].vfptr + 1)) )
              this->mInThresholdTimer = timestep + this->mInThresholdTimer;
            if ( UFG::AiDriverComponent::GetTimeAtOffset(v16, Follow) > 0.1 )
              this->mIsCloseEnough = 1;
          }
          else
          {
            m_Track = this->m_Track;
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
                               * (float)(pTargetTransform->mWorldTransform.v3.z - pMyTransform->mWorldTransform.v3.z))) < (float)(*((float *)&m_Track[1].vfptr + 1) * *((float *)&m_Track[1].vfptr + 1)) )
            {
              v21 = 1;
              this->mInThresholdTimer = timestep + this->mInThresholdTimer;
            }
            if ( (float)((float)((float)((float)(this->mClosestRoadDestination.y - pMyTransform->mWorldTransform.v3.y)
                                       * (float)(this->mClosestRoadDestination.y - pMyTransform->mWorldTransform.v3.y))
                               + (float)((float)(this->mClosestRoadDestination.x - pMyTransform->mWorldTransform.v3.x)
                                       * (float)(this->mClosestRoadDestination.x - pMyTransform->mWorldTransform.v3.x)))
                       + (float)((float)(this->mClosestRoadDestination.z - pMyTransform->mWorldTransform.v3.z)
                               * (float)(this->mClosestRoadDestination.z - pMyTransform->mWorldTransform.v3.z))) >= (float)(*((float *)&m_Track[1].vfptr + 1) * *((float *)&m_Track[1].vfptr + 1)) )
            {
              if ( !v21
                && (float)((float)((float)((float)(pTargetTransform->mWorldTransform.v3.y - this->mLastDestination.y)
                                         * (float)(pTargetTransform->mWorldTransform.v3.y - this->mLastDestination.y))
                                 + (float)((float)(pTargetTransform->mWorldTransform.v3.x - this->mLastDestination.x)
                                         * (float)(pTargetTransform->mWorldTransform.v3.x - this->mLastDestination.x)))
                         + (float)((float)(pTargetTransform->mWorldTransform.v3.z - this->mLastDestination.z)
                                 * (float)(pTargetTransform->mWorldTransform.v3.z - this->mLastDestination.z))) > 25.0 )
              {
                UFG::TransformNodeComponent::UpdateWorldTransform(pTargetTransform);
                x = pTargetTransform->mWorldTransform.v3.x;
                z = pTargetTransform->mWorldTransform.v3.z;
                this->mLastDestination.y = pTargetTransform->mWorldTransform.v3.y;
                this->mLastDestination.z = z;
                this->mLastDestination.x = x;
                DriverPathfindToTargetTask::SetupClosestRoadNetworkPosition(
                  this,
                  v14,
                  v15,
                  v16,
                  pMyTransform,
                  pTargetTransform);
              }
            }
            else
            {
              this->mInThresholdTimer = timestep + this->mInThresholdTimer;
            }
          }
          v24 = FLOAT_0_5;
          if ( this->mInThresholdTimer > 0.5 )
            this->mIsCloseEnough = 1;
          if ( this->mIsCloseEnough )
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
            *((_BYTE *)&v16->m_StopInfo + 8) &= ~1u;
            v16->m_StopInfo.fSteeringOverride = v24;
            v16->m_StopInfo.eStopStyle = EStopStyle_Powerslide;
            *((_BYTE *)&v16->m_StopInfo + 8) |= 1u;
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
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::CharacterOccupantComponent *m_pComponent; // rax
  UFG::SimObjectCVBase *CurrentVehicle; // rax
  UFG::AiDriverComponent *v6; // rax
  UFG::AiDriverComponent *v7; // rbx

  m_pPointer = (UFG::SimObjectGame *)this->mpContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::CharacterOccupantComponent *)m_pPointer->m_Components.p[44].m_pComponent;
    }
    else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      m_pComponent = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          m_pPointer,
                                                          UFG::CharacterOccupantComponent::_TypeUID);
    }
    else
    {
      m_pComponent = (UFG::CharacterOccupantComponent *)UFG::SimObject::GetComponentOfType(
                                                          m_pPointer,
                                                          UFG::CharacterOccupantComponent::_TypeUID);
    }
    if ( m_pComponent )
    {
      CurrentVehicle = (UFG::SimObjectCVBase *)UFG::CharacterOccupantComponent::GetCurrentVehicle(m_pComponent);
      if ( CurrentVehicle )
      {
        v6 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(CurrentVehicle);
        v7 = v6;
        if ( v6 )
        {
          UFG::AiDriverComponent::ClearGasBrakeLock(v6);
          v7->m_StopAtUseDestinationDirection = this->mAiDriverUseDirection;
          v7->m_GoToSlowDownForDestination = this->mAiDriverSlowDownForDestination;
        }
      }
    }
  }
}

// File Line: 368
// RVA: 0x32DE00
void __fastcall DriverFollowTargetTask::DriverFollowTargetTask(DriverFollowTargetTask *this)
{
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<DriverFollowTargetTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&DriverFollowTargetTask::`vftable;
}

// File Line: 407
// RVA: 0x32DC60
void __fastcall DriverChaseTargetTask::DriverChaseTargetTask(DriverChaseTargetTask *this)
{
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<DriverChaseTargetTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&DriverChaseTargetTask::`vftable;
}

// File Line: 427
// RVA: 0x3567F0
bool __fastcall FindDriverAndVehicle(
        ActionContext *pContext,
        UFG::VehicleOccupantComponent **ppVehicle,
        UFG::SimObject **ppDriver,
        UFG::TargetingSystemBaseComponent **ppTSBC)
{
  UFG::SimObjectVehicle *m_pPointer; // rbx
  UFG::TargetingSystemBaseComponent *v5; // rdi
  __int16 m_Flags; // r9
  UFG::CharacterOccupantComponent *m_pComponent; // rax
  UFG::SimObject *v12; // r8
  __int16 v13; // cx
  bool result; // al
  unsigned int v15; // edx
  UFG::SimObjectGame *v16; // rcx
  bool v17; // zf
  __int16 v18; // cx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::SimObject *Texture; // rax
  __int16 v21; // dx

  m_pPointer = (UFG::SimObjectVehicle *)pContext->mSimObject.m_pPointer;
  v5 = 0i64;
  *ppVehicle = 0i64;
  *ppDriver = 0i64;
  *ppTSBC = 0i64;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = (UFG::CharacterOccupantComponent *)m_pPointer->m_Components.p[44].m_pComponent;
  }
  else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
  {
    m_pComponent = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        m_pPointer,
                                                        UFG::CharacterOccupantComponent::_TypeUID);
  }
  else
  {
    m_pComponent = (UFG::CharacterOccupantComponent *)UFG::SimObject::GetComponentOfType(
                                                        m_pPointer,
                                                        UFG::CharacterOccupantComponent::_TypeUID);
  }
  if ( !m_pComponent )
  {
    v18 = m_pPointer->m_Flags;
    if ( (v18 & 0x4000) == 0 )
    {
      if ( v18 < 0 )
      {
        ComponentOfType = m_pPointer->m_Components.p[30].m_pComponent;
LABEL_29:
        if ( ComponentOfType )
        {
          *ppVehicle = (UFG::VehicleOccupantComponent *)m_pPointer;
          Texture = (UFG::SimObject *)Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture((hkSimpleLocalFrame *)ComponentOfType);
          *ppDriver = Texture;
          if ( Texture )
          {
            v21 = Texture->m_Flags;
            if ( (v21 & 0x4000) != 0 )
            {
              *ppTSBC = (UFG::TargetingSystemBaseComponent *)Texture->m_Components.p[20].m_pComponent;
              return 1;
            }
            else if ( v21 >= 0 )
            {
              v16 = (UFG::SimObjectGame *)Texture;
              if ( (v21 & 0x2000) != 0 )
              {
                v15 = UFG::TargetingSystemBaseComponent::_TypeUID;
                goto LABEL_17;
              }
              v17 = (v21 & 0x1000) == 0;
              v15 = UFG::TargetingSystemBaseComponent::_TypeUID;
              if ( !v17 )
                goto LABEL_17;
              *ppTSBC = (UFG::TargetingSystemBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                               Texture,
                                                               UFG::TargetingSystemBaseComponent::_TypeUID);
              return 1;
            }
            else
            {
              *ppTSBC = (UFG::TargetingSystemBaseComponent *)Texture->m_Components.p[20].m_pComponent;
              return 1;
            }
          }
        }
        return 0;
      }
      if ( (v18 & 0x2000) == 0 && (v18 & 0x1000) == 0 )
      {
        ComponentOfType = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::VehicleOccupantComponent::_TypeUID);
        goto LABEL_29;
      }
    }
    ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::VehicleOccupantComponent::_TypeUID);
    goto LABEL_29;
  }
  *ppVehicle = UFG::CharacterOccupantComponent::GetCurrentVehicle(m_pComponent);
  *ppDriver = m_pPointer;
  v12 = pContext->mSimObject.m_pPointer;
  if ( v12 )
  {
    v13 = v12->m_Flags;
    if ( (v13 & 0x4000) != 0 || v13 < 0 )
    {
      result = 1;
      *ppTSBC = (UFG::TargetingSystemBaseComponent *)v12->m_Components.p[20].m_pComponent;
      return result;
    }
    v15 = UFG::TargetingSystemBaseComponent::_TypeUID;
    if ( (v13 & 0x2000) != 0 )
    {
      v16 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
LABEL_17:
      *ppTSBC = (UFG::TargetingSystemBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v16, v15);
      return 1;
    }
    v17 = (v13 & 0x1000) == 0;
    v16 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
    if ( !v17 )
      goto LABEL_17;
    v5 = (UFG::TargetingSystemBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                v16,
                                                UFG::TargetingSystemBaseComponent::_TypeUID);
  }
  *ppTSBC = v5;
  return 1;
}

// File Line: 461
// RVA: 0x38E2E0
char __fastcall DriverChaseTargetTask::Update(DriverChaseTargetTask *this, float timestep)
{
  ActionContext *mpContext; // rcx
  UFG::SimObjectGame *m_pPointer; // rbx
  UFG::AiDriverComponent *v5; // rax
  UFG::AiDriverComponent *v6; // rdi
  __int16 m_Flags; // dx
  UFG::CharacterOccupantComponent *m_pComponent; // rax
  UFG::SimObject *CurrentVehicle; // rdx
  UFG::TargetingSystemBaseComponent *ppTSBC; // [rsp+30h] [rbp+8h] BYREF
  UFG::SimObjectVehicle *ppVehicle; // [rsp+40h] [rbp+18h] BYREF
  UFG::SimObject *ppDriver; // [rsp+48h] [rbp+20h] BYREF

  mpContext = this->mpContext;
  ppVehicle = 0i64;
  ppDriver = 0i64;
  ppTSBC = 0i64;
  if ( !FindDriverAndVehicle(mpContext, (UFG::VehicleOccupantComponent **)&ppVehicle, &ppDriver, &ppTSBC) )
    return 0;
  m_pPointer = (UFG::SimObjectGame *)ppTSBC->m_pTargets[(unsigned __int8)ppTSBC->m_pTargetingMap->m_Map.p[LOBYTE(this->m_Track[1].vfptr)]].m_pTarget.m_pPointer;
  if ( m_pPointer )
  {
    if ( ppVehicle )
    {
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(ppVehicle);
      v6 = v5;
      if ( v5 )
      {
        UFG::AiDriverComponent::SetDrivingMode(v5, 3u);
        m_Flags = m_pPointer->m_Flags;
        if ( (m_Flags & 0x4000) != 0 )
        {
          m_pComponent = (UFG::CharacterOccupantComponent *)m_pPointer->m_Components.p[44].m_pComponent;
        }
        else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        {
          m_pComponent = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                              m_pPointer,
                                                              UFG::CharacterOccupantComponent::_TypeUID);
        }
        else
        {
          m_pComponent = (UFG::CharacterOccupantComponent *)UFG::SimObject::GetComponentOfType(
                                                              m_pPointer,
                                                              UFG::CharacterOccupantComponent::_TypeUID);
        }
        if ( !m_pComponent
          || (CurrentVehicle = (UFG::SimObject *)UFG::CharacterOccupantComponent::GetCurrentVehicle(m_pComponent)) == 0i64 )
        {
          CurrentVehicle = m_pPointer;
        }
        UFG::AiDriverComponent::SetChaseTarget(v6, CurrentVehicle);
      }
    }
  }
  return 1;
}

// File Line: 519
// RVA: 0x32E040
void __fastcall DriverWanderTask::DriverWanderTask(DriverWanderTask *this)
{
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<DriverWanderTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&DriverWanderTask::`vftable;
  this->mpAIComponent.mPrev = &this->mpAIComponent;
  this->mpAIComponent.mNext = &this->mpAIComponent;
  this->mpAIComponent.m_pPointer = 0i64;
}

// File Line: 526
// RVA: 0x3365D0
void __fastcall DriverWanderTask::~DriverWanderTask(DriverWanderTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::AiDriverComponent> *p_mpAIComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rcx
  UFG::qNode<ITask,ITask> *v8; // rax

  this->vfptr = (ITaskVtbl *)&DriverWanderTask::`vftable;
  p_mpAIComponent = &this->mpAIComponent;
  if ( this->mpAIComponent.m_pPointer )
  {
    mPrev = p_mpAIComponent->mPrev;
    mNext = p_mpAIComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mpAIComponent->mPrev = p_mpAIComponent;
    p_mpAIComponent->mNext = p_mpAIComponent;
  }
  p_mpAIComponent->m_pPointer = 0i64;
  v5 = p_mpAIComponent->mPrev;
  v6 = p_mpAIComponent->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_mpAIComponent->mPrev = p_mpAIComponent;
  p_mpAIComponent->mNext = p_mpAIComponent;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v7 = this->mPrev;
  v8 = this->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 551
// RVA: 0x38E9D0
char __fastcall DriverWanderTask::Update(DriverWanderTask *this, float timestep)
{
  UFG::AiDriverComponent *m_pPointer; // rcx

  m_pPointer = (UFG::AiDriverComponent *)this->mpAIComponent.m_pPointer;
  if ( !m_pPointer )
    return 0;
  UFG::AiDriverComponent::SetDrivingRole(m_pPointer, 0);
  UFG::AiDriverComponent::SetDrivingMode((UFG::AiDriverComponent *)this->mpAIComponent.m_pPointer, 1u);
  return 1;
}

// File Line: 575
// RVA: 0x32DFA0
void __fastcall DriverStopTask::DriverStopTask(DriverStopTask *this)
{
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<DriverStopTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&DriverStopTask::`vftable;
  this->mpAIComponent.mPrev = &this->mpAIComponent;
  this->mpAIComponent.mNext = &this->mpAIComponent;
  this->mpAIComponent.m_pPointer = 0i64;
}

// File Line: 582
// RVA: 0x3364D0
void __fastcall DriverStopTask::~DriverStopTask(DriverStopTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::AiDriverComponent> *p_mpAIComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rcx
  UFG::qNode<ITask,ITask> *v8; // rax

  this->vfptr = (ITaskVtbl *)&DriverStopTask::`vftable;
  p_mpAIComponent = &this->mpAIComponent;
  if ( this->mpAIComponent.m_pPointer )
  {
    mPrev = p_mpAIComponent->mPrev;
    mNext = p_mpAIComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mpAIComponent->mPrev = p_mpAIComponent;
    p_mpAIComponent->mNext = p_mpAIComponent;
  }
  p_mpAIComponent->m_pPointer = 0i64;
  v5 = p_mpAIComponent->mPrev;
  v6 = p_mpAIComponent->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_mpAIComponent->mPrev = p_mpAIComponent;
  p_mpAIComponent->mNext = p_mpAIComponent;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v7 = this->mPrev;
  v8 = this->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 587
// RVA: 0x344810
void __fastcall DriverStopTask::Begin(DriverWanderTask *this, ActionContext *action_context)
{
  UFG::AiDriverComponent *v3; // rbx
  UFG::qSafePointer<UFG::SimComponent,UFG::AiDriverComponent> *p_mpAIComponent; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::SimObjectVehicle *ppVehicle; // [rsp+30h] [rbp+8h] BYREF
  UFG::SimObject *ppDriver; // [rsp+38h] [rbp+10h] BYREF
  UFG::TargetingSystemBaseComponent *ppTSBC; // [rsp+40h] [rbp+18h] BYREF

  this->mpContext = action_context;
  if ( action_context )
  {
    v3 = 0i64;
    ppVehicle = 0i64;
    ppDriver = 0i64;
    if ( FindDriverAndVehicle(action_context, &ppVehicle, &ppDriver, &ppTSBC) )
    {
      if ( ppVehicle )
        v3 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(ppVehicle);
      p_mpAIComponent = &this->mpAIComponent;
      if ( this->mpAIComponent.m_pPointer )
      {
        mPrev = p_mpAIComponent->mPrev;
        mNext = this->mpAIComponent.mNext;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        p_mpAIComponent->mPrev = p_mpAIComponent;
        this->mpAIComponent.mNext = &this->mpAIComponent;
      }
      this->mpAIComponent.m_pPointer = v3;
      if ( v3 )
      {
        v7 = v3->m_SafePointerList.mNode.UFG::VehicleDriverInterface::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
        v7->mNext = p_mpAIComponent;
        p_mpAIComponent->mPrev = v7;
        this->mpAIComponent.mNext = &v3->m_SafePointerList.mNode;
        v3->m_SafePointerList.mNode.UFG::VehicleDriverInterface::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = p_mpAIComponent;
      }
    }
  }
}

// File Line: 607
// RVA: 0x38E990
char __fastcall DriverStopTask::Update(DriverStopTask *this, float timestep)
{
  UFG::AiDriverComponent *m_pPointer; // rcx

  m_pPointer = (UFG::AiDriverComponent *)this->mpAIComponent.m_pPointer;
  if ( !m_pPointer )
    return 0;
  UFG::AiDriverComponent::SetDrivingRole(m_pPointer, 0);
  UFG::AiDriverComponent::SetDrivingMode((UFG::AiDriverComponent *)this->mpAIComponent.m_pPointer, 0);
  return 1;
}

