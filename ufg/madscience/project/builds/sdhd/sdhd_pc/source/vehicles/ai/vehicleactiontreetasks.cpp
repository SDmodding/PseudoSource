// File Line: 58
// RVA: 0x667B90
void __fastcall CarStopTask::CarStopTask(CarStopTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::AiDriverComponent> *p_m_pAIComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax

  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<CarStopTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&CarStopTask::`vftable;
  p_m_pAIComponent = &this->m_pAIComponent;
  this->m_pAIComponent.mPrev = &this->m_pAIComponent;
  this->m_pAIComponent.mNext = &this->m_pAIComponent;
  this->m_pAIComponent.m_pPointer = 0i64;
  this->m_pActionContext = 0i64;
  if ( this->m_pAIComponent.m_pPointer )
  {
    mPrev = p_m_pAIComponent->mPrev;
    mNext = p_m_pAIComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pAIComponent->mPrev = p_m_pAIComponent;
    p_m_pAIComponent->mNext = p_m_pAIComponent;
  }
  p_m_pAIComponent->m_pPointer = 0i64;
}

// File Line: 66
// RVA: 0x6727F0
void __fastcall CarStopTask::Begin(CarStopTask *this, ActionContext *action_context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::SimComponent *v4; // rdi
  UFG::SimComponent *v5; // rdx
  __int16 m_Flags; // dx
  UFG::AiDriverComponent *ComponentOfTypeHK; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AiDriverComponent> *p_m_pAIComponent; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::SimObjectGame *v12; // rcx
  __int16 v13; // dx
  UFG::CharacterOccupantComponent *m_pComponent; // rax
  UFG::SimObjectCVBase *CurrentVehicle; // rax
  __int16 v16; // cx
  UFG::AiDriverComponent *ComponentOfType; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rax
  UFG::AiDriverComponent *v21; // rcx

  this->m_pActionContext = action_context;
  if ( action_context )
  {
    m_pPointer = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
    v4 = 0i64;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
      {
        ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(m_pPointer);
      }
      else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      {
        ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        m_pPointer,
                                                        UFG::AiDriverComponent::_TypeUID);
      }
      else
      {
        ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                                        m_pPointer,
                                                        UFG::AiDriverComponent::_TypeUID);
      }
      v5 = ComponentOfTypeHK;
    }
    else
    {
      v5 = 0i64;
    }
    p_m_pAIComponent = &this->m_pAIComponent;
    if ( this->m_pAIComponent.m_pPointer )
    {
      mPrev = p_m_pAIComponent->mPrev;
      mNext = this->m_pAIComponent.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_m_pAIComponent->mPrev = p_m_pAIComponent;
      this->m_pAIComponent.mNext = &this->m_pAIComponent;
    }
    this->m_pAIComponent.m_pPointer = v5;
    if ( v5 )
    {
      v11 = v5->m_SafePointerList.mNode.mPrev;
      v11->mNext = p_m_pAIComponent;
      p_m_pAIComponent->mPrev = v11;
      this->m_pAIComponent.mNext = &v5->m_SafePointerList.mNode;
      v5->m_SafePointerList.mNode.mPrev = p_m_pAIComponent;
    }
    if ( !this->m_pAIComponent.m_pPointer )
    {
      v12 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
      if ( v12 )
      {
        v13 = v12->m_Flags;
        if ( (v13 & 0x4000) != 0 )
          m_pComponent = (UFG::CharacterOccupantComponent *)v12->m_Components.p[44].m_pComponent;
        else
          m_pComponent = (UFG::CharacterOccupantComponent *)(v13 < 0 || (v13 & 0x2000) != 0 || (v13 & 0x1000) != 0
                                                           ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               v12,
                                                               UFG::CharacterOccupantComponent::_TypeUID)
                                                           : UFG::SimObject::GetComponentOfType(
                                                               v12,
                                                               UFG::CharacterOccupantComponent::_TypeUID));
        if ( m_pComponent )
        {
          CurrentVehicle = (UFG::SimObjectCVBase *)UFG::CharacterOccupantComponent::GetCurrentVehicle(m_pComponent);
          if ( CurrentVehicle )
          {
            v16 = CurrentVehicle->m_Flags;
            if ( (v16 & 0x4000) != 0 || v16 < 0 )
            {
              ComponentOfType = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(CurrentVehicle);
            }
            else if ( (v16 & 0x2000) != 0 || (v16 & 0x1000) != 0 )
            {
              ComponentOfType = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            CurrentVehicle,
                                                            UFG::AiDriverComponent::_TypeUID);
            }
            else
            {
              ComponentOfType = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                                            CurrentVehicle,
                                                            UFG::AiDriverComponent::_TypeUID);
            }
            v4 = ComponentOfType;
          }
          if ( this->m_pAIComponent.m_pPointer )
          {
            v18 = p_m_pAIComponent->mPrev;
            v19 = this->m_pAIComponent.mNext;
            v18->mNext = v19;
            v19->mPrev = v18;
            p_m_pAIComponent->mPrev = p_m_pAIComponent;
            this->m_pAIComponent.mNext = &this->m_pAIComponent;
          }
          this->m_pAIComponent.m_pPointer = v4;
          if ( v4 )
          {
            v20 = v4->m_SafePointerList.mNode.mPrev;
            v20->mNext = p_m_pAIComponent;
            p_m_pAIComponent->mPrev = v20;
            this->m_pAIComponent.mNext = &v4->m_SafePointerList.mNode;
            v4->m_SafePointerList.mNode.mPrev = p_m_pAIComponent;
          }
        }
      }
    }
    v21 = (UFG::AiDriverComponent *)this->m_pAIComponent.m_pPointer;
    if ( v21 )
    {
      this->m_PreviousDrivingMode = v21->m_DrivingMode;
      UFG::AiDriverComponent::SetDrivingMode(v21, 0);
    }
  }
}

// File Line: 102
// RVA: 0x677D00
void __fastcall CarStopTask::End(CarStopTask *this)
{
  if ( this->m_pAIComponent.m_pPointer )
    UFG::AiDriverComponent::SetDrivingMode(
      (UFG::AiDriverComponent *)this->m_pAIComponent.m_pPointer,
      this->m_PreviousDrivingMode);
}

// File Line: 117
// RVA: 0x672BD0
void __fastcall CarWanderTask::Begin(CarWanderTask *this, ActionContext *action_context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::SimComponent *v4; // r8
  __int16 m_Flags; // dx
  UFG::AiDriverComponent *ComponentOfTypeHK; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AiDriverComponent> *p_m_pAIComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::AiDriverComponent *v11; // rcx
  UFG::SimObjectGame *v12; // rcx
  UFG::RoadSpaceComponent *m_pComponent; // rdi
  __int16 v14; // dx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::SimObject *v16; // rcx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  UFG::RoadNetworkResource *RoadNetwork; // rbp
  unsigned int m_RoadNetworkType; // esi
  UFG::RoadNetworkIntersection *ClosestNode; // rbx
  UFG::RoadNetworkLocation *Name; // rax

  this->m_pActionContext = action_context;
  if ( action_context )
  {
    m_pPointer = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
      {
        ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(m_pPointer);
      }
      else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      {
        ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        m_pPointer,
                                                        UFG::AiDriverComponent::_TypeUID);
      }
      else
      {
        ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                                        m_pPointer,
                                                        UFG::AiDriverComponent::_TypeUID);
      }
      v4 = ComponentOfTypeHK;
    }
    else
    {
      v4 = 0i64;
    }
    p_m_pAIComponent = &this->m_pAIComponent;
    if ( this->m_pAIComponent.m_pPointer )
    {
      mPrev = p_m_pAIComponent->mPrev;
      mNext = this->m_pAIComponent.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_m_pAIComponent->mPrev = p_m_pAIComponent;
      this->m_pAIComponent.mNext = &this->m_pAIComponent;
    }
    this->m_pAIComponent.m_pPointer = v4;
    if ( v4 )
    {
      v10 = v4->m_SafePointerList.mNode.mPrev;
      v10->mNext = p_m_pAIComponent;
      p_m_pAIComponent->mPrev = v10;
      this->m_pAIComponent.mNext = &v4->m_SafePointerList.mNode;
      v4->m_SafePointerList.mNode.mPrev = p_m_pAIComponent;
    }
    v11 = (UFG::AiDriverComponent *)this->m_pAIComponent.m_pPointer;
    if ( v11->m_bIsParked )
      UFG::AiDriverComponent::SetParked(v11, 0);
    v12 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
    if ( v12 )
    {
      v14 = v12->m_Flags;
      if ( (v14 & 0x4000) != 0 )
      {
        m_pComponent = (UFG::RoadSpaceComponent *)v12->m_Components.p[24].m_pComponent;
      }
      else if ( v14 >= 0 )
      {
        if ( (v14 & 0x2000) != 0 || (v14 & 0x1000) != 0 )
          ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::RoadSpaceComponent::_TypeUID);
        else
          ComponentOfType = UFG::SimObject::GetComponentOfType(v12, UFG::RoadSpaceComponent::_TypeUID);
        m_pComponent = (UFG::RoadSpaceComponent *)ComponentOfType;
      }
      else
      {
        m_pComponent = (UFG::RoadSpaceComponent *)v12->m_Components.p[24].m_pComponent;
      }
    }
    else
    {
      m_pComponent = 0i64;
    }
    if ( !UFG::RoadSpaceComponent::IsAttachedToRoadNetwork(m_pComponent)
      || (v16 = this->m_pActionContext->mSimObject.m_pPointer) != 0i64
      && (m_pTransformNodeComponent = v16->m_pTransformNodeComponent) != 0i64
      && ((RoadNetwork = UFG::WheeledVehicleNavigationData::GetRoadNetwork(UFG::WheeledVehicleManager::m_Instance->m_NavigationData),
           m_pComponent != (UFG::RoadSpaceComponent *)-552i64)
        ? (m_RoadNetworkType = m_pComponent->mWayClient.m_RoadNetworkType)
        : (m_RoadNetworkType = 0),
          UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent),
          ClosestNode = UFG::RoadNetworkResource::GetClosestNode(
                          RoadNetwork,
                          (UFG::qVector3 *)&m_pTransformNodeComponent->mWorldTransform.v3,
                          m_RoadNetworkType,
                          0i64,
                          0i64),
          Name = Scaleform::GFx::AS3::Instances::fl::XML::GetName(&m_pComponent->mGuide),
          ClosestNode != UFG::RoadNetworkLocation::GetRoadNetworkNode(Name)) )
    {
      UFG::RoadSpaceComponent::AttachToRoadNetwork(m_pComponent, 0);
    }
  }
}

// File Line: 152
// RVA: 0x6905C0
char __fastcall CarWanderTask::Update(CarWanderTask *this, float timestep)
{
  UFG::AiDriverComponent *m_pPointer; // rcx

  m_pPointer = (UFG::AiDriverComponent *)this->m_pAIComponent.m_pPointer;
  if ( !m_pPointer )
    return 0;
  UFG::AiDriverComponent::UpdateWanderingNavigation(m_pPointer);
  return 1;
}

// File Line: 181
// RVA: 0x667A90
void __fastcall CarRaceTask::CarRaceTask(CarRaceTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::AiDriverComponent> *p_m_pAIComponent; // rdx
  UFG::qSafePointer<UFG::SimComponent,UFG::RoadSpaceComponent> *p_m_pRoadSpaceComponent; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax

  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<CarRaceTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&CarRaceTask::`vftable;
  p_m_pAIComponent = &this->m_pAIComponent;
  this->m_pAIComponent.mPrev = &this->m_pAIComponent;
  this->m_pAIComponent.mNext = &this->m_pAIComponent;
  this->m_pAIComponent.m_pPointer = 0i64;
  p_m_pRoadSpaceComponent = &this->m_pRoadSpaceComponent;
  this->m_pRoadSpaceComponent.mPrev = &this->m_pRoadSpaceComponent;
  this->m_pRoadSpaceComponent.mNext = &this->m_pRoadSpaceComponent;
  this->m_pRoadSpaceComponent.m_pPointer = 0i64;
  if ( this->m_pRoadSpaceComponent.m_pPointer )
  {
    mPrev = p_m_pRoadSpaceComponent->mPrev;
    mNext = p_m_pRoadSpaceComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pRoadSpaceComponent->mPrev = p_m_pRoadSpaceComponent;
    p_m_pRoadSpaceComponent->mNext = p_m_pRoadSpaceComponent;
  }
  p_m_pRoadSpaceComponent->m_pPointer = 0i64;
  this->m_pActionContext = 0i64;
  if ( p_m_pAIComponent->m_pPointer )
  {
    v6 = p_m_pAIComponent->mPrev;
    v7 = p_m_pAIComponent->mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    p_m_pAIComponent->mPrev = p_m_pAIComponent;
    p_m_pAIComponent->mNext = p_m_pAIComponent;
  }
  p_m_pAIComponent->m_pPointer = 0i64;
}

// File Line: 191
// RVA: 0x671E00
void __fastcall CarRaceTask::Begin(CarRaceTask *this, ActionContext *action_context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::SimComponent *m_pComponent; // rbx
  UFG::SimComponent *v5; // r8
  __int16 m_Flags; // dx
  UFG::AiDriverComponent *ComponentOfTypeHK; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AiDriverComponent> *p_m_pAIComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::SimObjectGame *v12; // rcx
  __int16 v13; // dx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::RoadSpaceComponent> *p_m_pRoadSpaceComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rax
  UFG::RoadSpaceComponent *v19; // rcx
  UFG::AiDriverComponent *v20; // rcx

  this->m_pActionContext = action_context;
  if ( action_context )
  {
    m_pPointer = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
    m_pComponent = 0i64;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
      {
        ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(m_pPointer);
      }
      else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      {
        ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        m_pPointer,
                                                        UFG::AiDriverComponent::_TypeUID);
      }
      else
      {
        ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                                        m_pPointer,
                                                        UFG::AiDriverComponent::_TypeUID);
      }
      v5 = ComponentOfTypeHK;
    }
    else
    {
      v5 = 0i64;
    }
    p_m_pAIComponent = &this->m_pAIComponent;
    if ( this->m_pAIComponent.m_pPointer )
    {
      mPrev = p_m_pAIComponent->mPrev;
      mNext = this->m_pAIComponent.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_m_pAIComponent->mPrev = p_m_pAIComponent;
      this->m_pAIComponent.mNext = &this->m_pAIComponent;
    }
    this->m_pAIComponent.m_pPointer = v5;
    if ( v5 )
    {
      v11 = v5->m_SafePointerList.mNode.mPrev;
      v11->mNext = p_m_pAIComponent;
      p_m_pAIComponent->mPrev = v11;
      this->m_pAIComponent.mNext = &v5->m_SafePointerList.mNode;
      v5->m_SafePointerList.mNode.mPrev = p_m_pAIComponent;
    }
    v12 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
    if ( v12 )
    {
      v13 = v12->m_Flags;
      if ( (v13 & 0x4000) != 0 )
      {
        m_pComponent = v12->m_Components.p[24].m_pComponent;
      }
      else if ( v13 >= 0 )
      {
        if ( (v13 & 0x2000) != 0 || (v13 & 0x1000) != 0 )
          ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::RoadSpaceComponent::_TypeUID);
        else
          ComponentOfType = UFG::SimObject::GetComponentOfType(v12, UFG::RoadSpaceComponent::_TypeUID);
        m_pComponent = ComponentOfType;
      }
      else
      {
        m_pComponent = v12->m_Components.p[24].m_pComponent;
      }
    }
    p_m_pRoadSpaceComponent = &this->m_pRoadSpaceComponent;
    if ( this->m_pRoadSpaceComponent.m_pPointer )
    {
      v16 = p_m_pRoadSpaceComponent->mPrev;
      v17 = this->m_pRoadSpaceComponent.mNext;
      v16->mNext = v17;
      v17->mPrev = v16;
      p_m_pRoadSpaceComponent->mPrev = p_m_pRoadSpaceComponent;
      this->m_pRoadSpaceComponent.mNext = &this->m_pRoadSpaceComponent;
    }
    this->m_pRoadSpaceComponent.m_pPointer = m_pComponent;
    if ( m_pComponent )
    {
      v18 = m_pComponent->m_SafePointerList.mNode.mPrev;
      v18->mNext = p_m_pRoadSpaceComponent;
      p_m_pRoadSpaceComponent->mPrev = v18;
      this->m_pRoadSpaceComponent.mNext = &m_pComponent->m_SafePointerList.mNode;
      m_pComponent->m_SafePointerList.mNode.mPrev = p_m_pRoadSpaceComponent;
    }
    v19 = (UFG::RoadSpaceComponent *)this->m_pRoadSpaceComponent.m_pPointer;
    if ( v19 && UFG::RoadSpaceComponent::IsAttachedToRoadNetwork(v19) )
      UFG::RoadSpaceComponent::DetachFromRoadNetwork((UFG::RoadSpaceComponent *)this->m_pRoadSpaceComponent.m_pPointer);
    v20 = (UFG::AiDriverComponent *)this->m_pAIComponent.m_pPointer;
    if ( v20 )
    {
      if ( v20->m_bIsParked )
        UFG::AiDriverComponent::SetParked(v20, 0);
    }
  }
}

// File Line: 210
// RVA: 0x6903C0
char __fastcall CarRaceTask::Update(CarRaceTask *this, float timestep)
{
  UFG::AiDriverComponent *m_pPointer; // rcx

  if ( this->m_pAIComponent.m_pPointer )
  {
    if ( !UFG::RoadSpaceComponent::CleanupOnRaceDeleted((UFG::RoadSpaceComponent *)this->m_pRoadSpaceComponent.m_pPointer) )
      return 1;
    m_pPointer = (UFG::AiDriverComponent *)this->m_pAIComponent.m_pPointer;
    if ( m_pPointer->m_RaceWanderAtEnd )
    {
      UFG::AiDriverComponent::SetDrivingMode(m_pPointer, 1u);
      LOBYTE(this->m_pAIComponent.m_pPointer[24].m_NameUID) = 0;
      return 0;
    }
    UFG::AiDriverComponent::SetDrivingMode(m_pPointer, 0);
  }
  return 0;
}

// File Line: 274
// RVA: 0x68F9C0
char __fastcall CarOffsetDriveTask::Update(CarOffsetDriveTask *this, float timestep)
{
  UFG::AiDriverComponent *m_pPointer; // rcx

  m_pPointer = (UFG::AiDriverComponent *)this->m_pAIComponent.m_pPointer;
  if ( !m_pPointer )
    return 0;
  UFG::AiDriverComponent::UpdateFollowingNavigation(m_pPointer, timestep);
  return 1;
}

// File Line: 298
// RVA: 0x6710E0
void __fastcall CarFollowTask::Begin(CarFollowTask *this, ActionContext *action_context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::SimComponent *v4; // r8
  __int16 m_Flags; // dx
  UFG::AiDriverComponent *ComponentOfTypeHK; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AiDriverComponent> *p_m_pAIComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  ActionContext *m_pActionContext; // rcx
  UFG::SimObjectGame *v12; // rcx
  __int16 v13; // dx
  UFG::RoadSpaceComponent *m_pComponent; // rbx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::WayFinder *RoadWayFinder; // rax

  this->m_pActionContext = action_context;
  m_pPointer = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(m_pPointer);
    }
    else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      m_pPointer,
                                                      UFG::AiDriverComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                                      m_pPointer,
                                                      UFG::AiDriverComponent::_TypeUID);
    }
    v4 = ComponentOfTypeHK;
  }
  else
  {
    v4 = 0i64;
  }
  p_m_pAIComponent = &this->m_pAIComponent;
  if ( this->m_pAIComponent.m_pPointer )
  {
    mPrev = p_m_pAIComponent->mPrev;
    mNext = this->m_pAIComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pAIComponent->mPrev = p_m_pAIComponent;
    this->m_pAIComponent.mNext = &this->m_pAIComponent;
  }
  this->m_pAIComponent.m_pPointer = v4;
  if ( v4 )
  {
    v10 = v4->m_SafePointerList.mNode.mPrev;
    v10->mNext = p_m_pAIComponent;
    p_m_pAIComponent->mPrev = v10;
    this->m_pAIComponent.mNext = &v4->m_SafePointerList.mNode;
    v4->m_SafePointerList.mNode.mPrev = p_m_pAIComponent;
  }
  m_pActionContext = this->m_pActionContext;
  if ( m_pActionContext )
  {
    v12 = (UFG::SimObjectGame *)m_pActionContext->mSimObject.m_pPointer;
    if ( v12 )
    {
      v13 = v12->m_Flags;
      if ( (v13 & 0x4000) != 0 )
      {
        m_pComponent = (UFG::RoadSpaceComponent *)v12->m_Components.p[24].m_pComponent;
      }
      else if ( v13 >= 0 )
      {
        if ( (v13 & 0x2000) != 0 || (v13 & 0x1000) != 0 )
          ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::RoadSpaceComponent::_TypeUID);
        else
          ComponentOfType = UFG::SimObject::GetComponentOfType(v12, UFG::RoadSpaceComponent::_TypeUID);
        m_pComponent = (UFG::RoadSpaceComponent *)ComponentOfType;
      }
      else
      {
        m_pComponent = (UFG::RoadSpaceComponent *)v12->m_Components.p[24].m_pComponent;
      }
      if ( m_pComponent )
      {
        if ( UFG::RoadSpaceComponent::IsAttachedToRoadNetwork(m_pComponent) )
          UFG::RoadSpaceComponent::DetachFromRoadNetwork(m_pComponent);
        RoadWayFinder = UFG::WheeledVehicleNavigationData::GetRoadWayFinder(
                          UFG::WheeledVehicleManager::m_Instance->m_NavigationData,
                          &m_pComponent->mWayClient);
        UFG::WayFinder::Cancel(RoadWayFinder, &m_pComponent->mWayClient);
      }
    }
  }
}

// File Line: 323
// RVA: 0x68F960
char __fastcall CarEscortTask::Update(CarEscortTask *this, float timestep)
{
  UFG::AiDriverComponent *m_pPointer; // rcx

  m_pPointer = (UFG::AiDriverComponent *)this->m_pAIComponent.m_pPointer;
  if ( !m_pPointer )
    return 0;
  UFG::AiDriverComponent::UpdateEscortMode(m_pPointer, timestep);
  UFG::AiDriverComponent::UpdateEscortOffset((UFG::AiDriverComponent *)this->m_pAIComponent.m_pPointer, timestep);
  UFG::AiDriverComponent::UpdateFollowingNavigation((UFG::AiDriverComponent *)this->m_pAIComponent.m_pPointer, timestep);
  return 1;
}

// File Line: 349
// RVA: 0x672670
void __fastcall CarStopAtTask::Begin(CarStopAtTask *this, ActionContext *action_context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::SimComponent *m_pComponent; // rbx
  UFG::SimComponent *v5; // r8
  __int16 m_Flags; // dx
  UFG::AiDriverComponent *ComponentOfTypeHK; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AiDriverComponent> *p_m_pAiDriver; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::SimObjectGame *v12; // rcx
  __int16 v13; // dx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::RoadSpaceComponent> *p_m_pRoadSpace; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rax

  this->m_pActionContext = action_context;
  m_pPointer = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
  m_pComponent = 0i64;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(m_pPointer);
    }
    else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      m_pPointer,
                                                      UFG::AiDriverComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                                      m_pPointer,
                                                      UFG::AiDriverComponent::_TypeUID);
    }
    v5 = ComponentOfTypeHK;
  }
  else
  {
    v5 = 0i64;
  }
  p_m_pAiDriver = &this->m_pAiDriver;
  if ( this->m_pAiDriver.m_pPointer )
  {
    mPrev = p_m_pAiDriver->mPrev;
    mNext = this->m_pAiDriver.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pAiDriver->mPrev = p_m_pAiDriver;
    this->m_pAiDriver.mNext = &this->m_pAiDriver;
  }
  this->m_pAiDriver.m_pPointer = v5;
  if ( v5 )
  {
    v11 = v5->m_SafePointerList.mNode.mPrev;
    v11->mNext = p_m_pAiDriver;
    p_m_pAiDriver->mPrev = v11;
    this->m_pAiDriver.mNext = &v5->m_SafePointerList.mNode;
    v5->m_SafePointerList.mNode.mPrev = p_m_pAiDriver;
  }
  v12 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
  if ( v12 )
  {
    v13 = v12->m_Flags;
    if ( (v13 & 0x4000) != 0 )
    {
      m_pComponent = v12->m_Components.p[24].m_pComponent;
    }
    else if ( v13 >= 0 )
    {
      if ( (v13 & 0x2000) != 0 || (v13 & 0x1000) != 0 )
        ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::RoadSpaceComponent::_TypeUID);
      else
        ComponentOfType = UFG::SimObject::GetComponentOfType(v12, UFG::RoadSpaceComponent::_TypeUID);
      m_pComponent = ComponentOfType;
    }
    else
    {
      m_pComponent = v12->m_Components.p[24].m_pComponent;
    }
  }
  p_m_pRoadSpace = &this->m_pRoadSpace;
  if ( this->m_pRoadSpace.m_pPointer )
  {
    v16 = p_m_pRoadSpace->mPrev;
    v17 = this->m_pRoadSpace.mNext;
    v16->mNext = v17;
    v17->mPrev = v16;
    p_m_pRoadSpace->mPrev = p_m_pRoadSpace;
    this->m_pRoadSpace.mNext = &this->m_pRoadSpace;
  }
  this->m_pRoadSpace.m_pPointer = m_pComponent;
  if ( m_pComponent )
  {
    v18 = m_pComponent->m_SafePointerList.mNode.mPrev;
    v18->mNext = p_m_pRoadSpace;
    p_m_pRoadSpace->mPrev = v18;
    this->m_pRoadSpace.mNext = &m_pComponent->m_SafePointerList.mNode;
    m_pComponent->m_SafePointerList.mNode.mPrev = p_m_pRoadSpace;
  }
}onent->m_SafePointerList.mNode;
    m_pComponent->m_SafePointerList.mNode.mPrev = p_

// File Line: 360
// RVA: 0x690420
bool __fastcall CarStopAtTask::Update(CarStopAtTask *this, float timestep)
{
  float *m_pPointer; // rax
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rsi
  float v5; // xmm7_4
  float v6; // xmm8_4
  float v7; // xmm9_4
  UFG::SimObject *v8; // rcx
  UFG::SimComponent *v9; // rdx
  char v10; // cl
  float v11; // xmm6_4
  float v12; // xmm4_4
  float v13; // xmm3_4
  float v14; // xmm5_4
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rcx

  m_pPointer = (float *)this->m_pRoadSpace.m_pPointer;
  if ( !m_pPointer || !this->m_pAiDriver.m_pPointer )
    return 0;
  m_pTransformNodeComponent = 0i64;
  v5 = m_pPointer[412];
  v6 = m_pPointer[413];
  v7 = m_pPointer[414];
  v8 = this->m_pActionContext->mSimObject.m_pPointer;
  if ( v8 )
    m_pTransformNodeComponent = v8->m_pTransformNodeComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  v9 = this->m_pAiDriver.m_pPointer;
  v10 = 0;
  v11 = *(float *)&v9[24].m_SafePointerList.mNode.mPrev;
  v12 = m_pTransformNodeComponent->mWorldTransform.v3.x - v5;
  v13 = m_pTransformNodeComponent->mWorldTransform.v3.y - v6;
  v14 = m_pTransformNodeComponent->mWorldTransform.v3.z - v7;
  if ( (float)((float)((float)(v13 * v13) + (float)(v12 * v12)) + (float)(v14 * v14)) > (float)(v11 * v11) )
    return 1;
  if ( !LOBYTE(v9[23].m_BoundComponentHandles.mNode.mNext)
    || COERCE_FLOAT(LODWORD(v11) ^ _xmm[0]) < (float)((float)((float)(v13
                                                                    * *((float *)&this->m_pRoadSpace.m_pPointer[27].m_pSimObject
                                                                      + 1))
                                                            + (float)(v12
                                                                    * *(float *)&this->m_pRoadSpace.m_pPointer[27].m_pSimObject))
                                                    + (float)(v14
                                                            * *(float *)&this->m_pRoadSpace.m_pPointer[27].m_BoundComponentHandles.mNode.mPrev)) )
  {
    mNext = v9[12].m_BoundComponentHandles.mNode.mNext;
    if ( mNext )
    {
      if ( LODWORD(v9[13].vfptr) == LODWORD(mNext->mNext) )
      {
        LOBYTE(v9) = 1;
        ((void (__fastcall *)(UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *, UFG::SimComponent *))mNext->mPrev[7].mNext)(
          mNext,
          v9);
      }
    }
    UFG::AiDriverComponent::SetDrivingMode((UFG::AiDriverComponent *)this->m_pAiDriver.m_pPointer, 0);
    v10 = 1;
  }
  return v10 == 0;
}

// File Line: 407
// RVA: 0x671FD0
void __fastcall CarStopAtStimulusTask::Begin(CarStopAtStimulusTask *this, ActionContext *action_context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::SimComponent *v5; // r8
  __int16 m_Flags; // dx
  UFG::AiDriverComponent *ComponentOfTypeHK; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AiDriverComponent> *p_m_pAiDriver; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::SimObjectGame *v12; // rcx
  UFG::SimComponent *m_pComponent; // r8
  __int16 v14; // dx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::RoadSpaceComponent> *p_m_pRoadSpace; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::SimComponent *v20; // rax
  UFG::SimObjectGame *v21; // rcx
  UFG::SimComponent *v22; // rdx
  __int16 v23; // dx
  UFG::SimComponent *v24; // rax
  __int64 v25; // rbx
  UFG::TransformNodeComponent *v26; // rbx
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::RoadNetworkResource *RoadNetwork; // rax
  UFG::SimComponent *v30; // rcx
  UFG::SimObject **p_m_pSimObject; // rcx
  unsigned int v32; // r8d
  UFG::RoadNetworkIntersection *ClosestNode; // rdi
  UFG::RoadNetworkLane *ClosestLane; // rbx
  float ClosestT; // xmm0_4
  UFG::qVector3 *v36; // rax
  UFG::SimComponent *v37; // rcx
  float v38; // xmm12_4
  float v39; // xmm13_4
  float x; // xmm14_4
  float v41; // xmm6_4
  __m128 m_pSimObject_low; // xmm7
  float v43; // xmm8_4
  __m128 v44; // xmm2
  float v45; // xmm3_4
  float v46; // xmm9_4
  float v47; // xmm10_4
  float v48; // xmm3_4
  float v49; // xmm9_4
  float v50; // xmm10_4
  __m128 x_low; // xmm2
  float v52; // xmm0_4
  __m128 v53; // xmm2
  __m128 v54; // xmm1
  float v55; // xmm6_4
  float v56; // xmm6_4
  __m128 v57; // xmm7
  float v58; // xmm6_4
  __m128 v59; // xmm8
  float v60; // xmm1_4
  float v61; // xmm8_4
  float v62; // xmm2_4
  __m128 v63; // xmm11
  __m128 v64; // xmm3
  float v65; // xmm4_4
  UFG::SimComponent *v66; // rax
  int v67; // xmm6_4
  UFG::RoadNetworkLocation *Name; // rax
  UFG::qVector3 *v69; // rax
  UFG::RoadSpaceComponent *v70; // rcx
  unsigned int v71; // edx
  UFG::qVector3 result; // [rsp+30h] [rbp-D0h] BYREF
  UFG::qVector3 pos; // [rsp+40h] [rbp-C0h] BYREF
  UFG::qVector3 v74; // [rsp+50h] [rbp-B0h] BYREF
  UFG::qMatrix44 matrix; // [rsp+60h] [rbp-A0h] BYREF

  this->m_pActionContext = action_context;
  m_pPointer = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(m_pPointer);
    }
    else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      m_pPointer,
                                                      UFG::AiDriverComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                                      m_pPointer,
                                                      UFG::AiDriverComponent::_TypeUID);
    }
    v5 = ComponentOfTypeHK;
  }
  else
  {
    v5 = 0i64;
  }
  p_m_pAiDriver = &this->m_pAiDriver;
  if ( this->m_pAiDriver.m_pPointer )
  {
    mPrev = p_m_pAiDriver->mPrev;
    mNext = this->m_pAiDriver.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pAiDriver->mPrev = p_m_pAiDriver;
    this->m_pAiDriver.mNext = &this->m_pAiDriver;
  }
  this->m_pAiDriver.m_pPointer = v5;
  if ( v5 )
  {
    v11 = v5->m_SafePointerList.mNode.mPrev;
    v11->mNext = p_m_pAiDriver;
    p_m_pAiDriver->mPrev = v11;
    this->m_pAiDriver.mNext = &v5->m_SafePointerList.mNode;
    v5->m_SafePointerList.mNode.mPrev = p_m_pAiDriver;
  }
  v12 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
  if ( v12 )
  {
    v14 = v12->m_Flags;
    if ( (v14 & 0x4000) != 0 )
    {
      m_pComponent = v12->m_Components.p[24].m_pComponent;
    }
    else if ( v14 >= 0 )
    {
      if ( (v14 & 0x2000) != 0 || (v14 & 0x1000) != 0 )
        ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::RoadSpaceComponent::_TypeUID);
      else
        ComponentOfType = UFG::SimObject::GetComponentOfType(v12, UFG::RoadSpaceComponent::_TypeUID);
      m_pComponent = ComponentOfType;
    }
    else
    {
      m_pComponent = v12->m_Components.p[24].m_pComponent;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  p_m_pRoadSpace = &this->m_pRoadSpace;
  if ( this->m_pRoadSpace.m_pPointer )
  {
    v17 = p_m_pRoadSpace->mPrev;
    v18 = this->m_pRoadSpace.mNext;
    v17->mNext = v18;
    v18->mPrev = v17;
    p_m_pRoadSpace->mPrev = p_m_pRoadSpace;
    this->m_pRoadSpace.mNext = &this->m_pRoadSpace;
  }
  this->m_pRoadSpace.m_pPointer = m_pComponent;
  if ( m_pComponent )
  {
    v19 = m_pComponent->m_SafePointerList.mNode.mPrev;
    v19->mNext = p_m_pRoadSpace;
    p_m_pRoadSpace->mPrev = v19;
    this->m_pRoadSpace.mNext = &m_pComponent->m_SafePointerList.mNode;
    m_pComponent->m_SafePointerList.mNode.mPrev = p_m_pRoadSpace;
  }
  v20 = this->m_pAiDriver.m_pPointer;
  this->mElapsedTime = 0.0;
  if ( v20 )
    this->mPrevAI = (unsigned int)v20[13].m_SafePointerList.mNode.mPrev;
  v21 = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  if ( v21 )
  {
    v23 = v21->m_Flags;
    if ( (v23 & 0x4000) != 0 )
    {
      v22 = v21->m_Components.p[20].m_pComponent;
    }
    else if ( v23 >= 0 )
    {
      if ( (v23 & 0x2000) != 0 || (v23 & 0x1000) != 0 )
        v24 = UFG::SimObjectGame::GetComponentOfTypeHK(v21, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        v24 = UFG::SimObject::GetComponentOfType(v21, UFG::TargetingSystemBaseComponent::_TypeUID);
      v22 = v24;
    }
    else
    {
      v22 = v21->m_Components.p[20].m_pComponent;
    }
  }
  else
  {
    v22 = 0i64;
  }
  v25 = *(_QWORD *)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v22[1].m_Flags + 41i64) + *(_QWORD *)&v22[1].m_TypeUID + 40);
  if ( v25 )
    v26 = *(UFG::TransformNodeComponent **)(v25 + 88);
  else
    v26 = 0i64;
  UFG::TransformNodeComponent::UpdateWorldTransform(v26);
  y = v26->mWorldTransform.v3.y;
  z = v26->mWorldTransform.v3.z;
  pos.x = v26->mWorldTransform.v3.x;
  pos.y = y;
  pos.z = z;
  RoadNetwork = UFG::WheeledVehicleNavigationData::GetRoadNetwork(UFG::WheeledVehicleManager::m_Instance->m_NavigationData);
  if ( !RoadNetwork )
    goto LABEL_65;
  v30 = this->m_pRoadSpace.m_pPointer;
  if ( v30 && (p_m_pSimObject = &v30[8].m_pSimObject) != 0i64 )
    v32 = *((_DWORD *)p_m_pSimObject + 268);
  else
    v32 = 0;
  ClosestNode = UFG::RoadNetworkResource::GetClosestNode(RoadNetwork, &pos, v32, 0i64, 0i64);
  ClosestLane = UFG::RoadNetworkNode::GetClosestLane(ClosestNode, &pos);
  UFG::RoadNetworkNode::GetClosestPosition(ClosestNode, &result, &pos, 0i64);
  ClosestT = UFG::RoadNetworkNode::GetClosestT(ClosestNode, ClosestLane->mLaneIndex, &result);
  v36 = UFG::RoadNetworkNode::GetPos(ClosestNode, &v74, ClosestLane->mLaneIndex, ClosestT);
  v37 = this->m_pRoadSpace.m_pPointer;
  v38 = v36->y;
  v39 = v36->z;
  x = v36->x;
  result.x = v36->x;
  result.y = v38;
  result.z = v39;
  v41 = *((float *)&v37[27].m_pSimObject + 1);
  m_pSimObject_low = (__m128)LODWORD(v37[27].m_pSimObject);
  v43 = *(float *)&v37[27].m_BoundComponentHandles.mNode.mPrev;
  v44 = m_pSimObject_low;
  v44.m128_f32[0] = (float)((float)(m_pSimObject_low.m128_f32[0] * m_pSimObject_low.m128_f32[0]) + (float)(v41 * v41))
                  + (float)(v43 * v43);
  v45 = v44.m128_f32[0] == 0.0 ? 0.0 : 1.0 / _mm_sqrt_ps(v44).m128_f32[0];
  v46 = v45;
  v47 = v45;
  v48 = v45 * v43;
  matrix.v0.w = 0.0;
  v49 = v46 * m_pSimObject_low.m128_f32[0];
  v50 = v47 * v41;
  matrix.v0.z = v48;
  x_low = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
  matrix.v0.x = v49;
  matrix.v0.y = v50;
  x_low.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0])
                            + (float)(UFG::qVector3::msDirUp.y * UFG::qVector3::msDirUp.y))
                    + (float)(UFG::qVector3::msDirUp.z * UFG::qVector3::msDirUp.z);
  if ( x_low.m128_f32[0] == 0.0 )
  {
    v53 = 0i64;
  }
  else
  {
    v52 = _mm_sqrt_ps(x_low).m128_f32[0];
    v53 = (__m128)(unsigned int)FLOAT_1_0;
    v53.m128_f32[0] = 1.0 / v52;
  }
  v54 = v53;
  v55 = v53.m128_f32[0];
  v53.m128_f32[0] = v53.m128_f32[0] * UFG::qVector3::msDirUp.z;
  v54.m128_f32[0] = v54.m128_f32[0] * UFG::qVector3::msDirUp.y;
  v56 = v55 * UFG::qVector3::msDirUp.x;
  v57 = v54;
  v57.m128_f32[0] = (float)(v54.m128_f32[0] * v48) - (float)(v53.m128_f32[0] * v50);
  v53.m128_f32[0] = (float)(v53.m128_f32[0] * v49) - (float)(v56 * v48);
  v58 = (float)(v56 * v50) - (float)(v54.m128_f32[0] * v49);
  v59 = v53;
  v59.m128_f32[0] = (float)((float)(v53.m128_f32[0] * v53.m128_f32[0]) + (float)(v57.m128_f32[0] * v57.m128_f32[0]))
                  + (float)(v58 * v58);
  v60 = v59.m128_f32[0] == 0.0 ? 0.0 : 1.0 / _mm_sqrt_ps(v59).m128_f32[0];
  v57.m128_f32[0] = v57.m128_f32[0] * v60;
  matrix.v1.w = 0.0;
  v63 = v57;
  LODWORD(matrix.v1.x) = v57.m128_i32[0];
  matrix.v1.y = v53.m128_f32[0] * v60;
  matrix.v1.z = v58 * v60;
  v61 = (float)((float)(v58 * v60) * v50) - (float)((float)(v53.m128_f32[0] * v60) * v48);
  v62 = (float)((float)(v53.m128_f32[0] * v60) * v49) - (float)(v57.m128_f32[0] * v50);
  v63.m128_f32[0] = (float)(v57.m128_f32[0] * v48) - (float)((float)(v58 * v60) * v49);
  v64 = v63;
  v64.m128_f32[0] = (float)((float)(v63.m128_f32[0] * v63.m128_f32[0]) + (float)(v61 * v61)) + (float)(v62 * v62);
  v65 = v64.m128_f32[0] == 0.0 ? 0.0 : 1.0 / _mm_sqrt_ps(v64).m128_f32[0];
  v66 = this->m_pAiDriver.m_pPointer;
  matrix.v3.x = x;
  matrix.v3.y = v38;
  matrix.v3.z = v39;
  matrix.v2.w = 0.0;
  matrix.v3.w = 1.0;
  matrix.v2.x = v61 * v65;
  matrix.v2.y = v63.m128_f32[0] * v65;
  matrix.v2.z = v62 * v65;
  v67 = (int)v66[24].m_SafePointerList.mNode.mPrev;
  Name = Scaleform::GFx::AS3::Instances::fl::XML::GetName((UFG::RoadNetworkGuide *)&v37[5].m_BoundComponentHandles.mNode.mNext);
  v69 = UFG::RoadNetworkLocation::GetPos(Name, &v74);
  v70 = (UFG::RoadSpaceComponent *)this->m_pRoadSpace.m_pPointer;
  if ( COERCE_FLOAT(v67 ^ _xmm[0]) >= (float)((float)((float)((float)(v69->y - result.y) * v70->m_ChaseWorld.v0.y)
                                                    + (float)((float)(v69->x - result.x) * v70->m_ChaseWorld.v0.x))
                                            + (float)((float)(v69->z - result.z) * v70->m_ChaseWorld.v0.z)) )
  {
    UFG::RoadSpaceComponent::SetCarDestination(v70, &matrix);
    v71 = 5;
  }
  else
  {
LABEL_65:
    v71 = 0;
  }
  UFG::AiDriverComponent::SetDrivingMode((UFG::AiDriverComponent *)this->m_pAiDriver.m_pPointer, v71);
}

// File Line: 496
// RVA: 0x672A30
void __fastcall CarWaitTask::Begin(CarWaitTask *this, ActionContext *action_context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::SimComponent *v4; // r8
  __int16 m_Flags; // dx
  UFG::AiDriverComponent *ComponentOfTypeHK; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AiDriverComponent> *p_m_pAiDriver; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::SimObjectGame *v11; // rcx
  UFG::SimComponent *m_pComponent; // r8
  __int16 v13; // dx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::RoadSpaceComponent> *p_m_pRoadSpace; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rax
  UFG::AiDriverComponent *v19; // rcx

  this->m_pActionContext = action_context;
  m_pPointer = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(m_pPointer);
    }
    else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      m_pPointer,
                                                      UFG::AiDriverComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                                      m_pPointer,
                                                      UFG::AiDriverComponent::_TypeUID);
    }
    v4 = ComponentOfTypeHK;
  }
  else
  {
    v4 = 0i64;
  }
  p_m_pAiDriver = &this->m_pAiDriver;
  if ( this->m_pAiDriver.m_pPointer )
  {
    mPrev = p_m_pAiDriver->mPrev;
    mNext = this->m_pAiDriver.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pAiDriver->mPrev = p_m_pAiDriver;
    this->m_pAiDriver.mNext = &this->m_pAiDriver;
  }
  this->m_pAiDriver.m_pPointer = v4;
  if ( v4 )
  {
    v10 = v4->m_SafePointerList.mNode.mPrev;
    v10->mNext = p_m_pAiDriver;
    p_m_pAiDriver->mPrev = v10;
    this->m_pAiDriver.mNext = &v4->m_SafePointerList.mNode;
    v4->m_SafePointerList.mNode.mPrev = p_m_pAiDriver;
  }
  v11 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
  if ( v11 )
  {
    v13 = v11->m_Flags;
    if ( (v13 & 0x4000) != 0 )
    {
      m_pComponent = v11->m_Components.p[24].m_pComponent;
    }
    else if ( v13 >= 0 )
    {
      if ( (v13 & 0x2000) != 0 || (v13 & 0x1000) != 0 )
        ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::RoadSpaceComponent::_TypeUID);
      else
        ComponentOfType = UFG::SimObject::GetComponentOfType(v11, UFG::RoadSpaceComponent::_TypeUID);
      m_pComponent = ComponentOfType;
    }
    else
    {
      m_pComponent = v11->m_Components.p[24].m_pComponent;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  p_m_pRoadSpace = &this->m_pRoadSpace;
  if ( this->m_pRoadSpace.m_pPointer )
  {
    v16 = p_m_pRoadSpace->mPrev;
    v17 = this->m_pRoadSpace.mNext;
    v16->mNext = v17;
    v17->mPrev = v16;
    p_m_pRoadSpace->mPrev = p_m_pRoadSpace;
    this->m_pRoadSpace.mNext = &this->m_pRoadSpace;
  }
  this->m_pRoadSpace.m_pPointer = m_pComponent;
  if ( m_pComponent )
  {
    v18 = m_pComponent->m_SafePointerList.mNode.mPrev;
    v18->mNext = p_m_pRoadSpace;
    p_m_pRoadSpace->mPrev = v18;
    this->m_pRoadSpace.mNext = &m_pComponent->m_SafePointerList.mNode;
    m_pComponent->m_SafePointerList.mNode.mPrev = p_m_pRoadSpace;
  }
  v19 = (UFG::AiDriverComponent *)this->m_pAiDriver.m_pPointer;
  this->mElapsedTime = 0.0;
  if ( v19 )
  {
    this->mPrevAI = v19->m_DrivingMode;
    UFG::AiDriverComponent::SetDrivingMode(v19, 0);
  }
}

// File Line: 513
// RVA: 0x6905A0
bool __fastcall CarWaitTask::Update(CarWaitTask *this, float timestep)
{
  float mElapsedTime; // xmm0_4
  bool result; // al

  mElapsedTime = this->mElapsedTime;
  if ( mElapsedTime > *(float *)&this->m_Track[1].vfptr )
    return 0;
  result = 1;
  this->mElapsedTime = mElapsedTime + timestep;
  return result;
}

// File Line: 533
// RVA: 0x677D20
void __fastcall CarWaitTask::End(CarWaitTask *this)
{
  if ( this->m_pAiDriver.m_pPointer )
    UFG::AiDriverComponent::SetDrivingMode((UFG::AiDriverComponent *)this->m_pAiDriver.m_pPointer, this->mPrevAI);
}

// File Line: 549
// RVA: 0x678CE0
void __fastcall CarGoToTask::FindWay(CarGoToTask *this)
{
  ActionContext *m_pActionContext; // rcx
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::SimComponent *v4; // r8
  __int16 m_Flags; // dx
  UFG::AiDriverComponent *ComponentOfTypeHK; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AiDriverComponent> *p_m_pAIComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::SimObjectGame *v11; // rcx
  UFG::SimComponent *m_pComponent; // r8
  __int16 v13; // dx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::RoadSpaceComponent> *p_m_pRoadSpaceComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rax
  UFG::AiDriverComponent *v19; // rcx
  UFG::SimObject *v20; // rcx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rcx
  UFG::SimObject *v22; // rcx
  UFG::TransformNodeComponent *v23; // rcx
  UFG::VehicleWayFinderClient *p_m_pSimObject; // rsi
  UFG::SimComponent *v25; // rax
  UFG::qVector3 *p_m_BoundComponentHandles; // r14
  float *v27; // rdi
  UFG::WayFinder *RoadWayFinder; // rax
  UFG::WayFinder *v29; // rbp
  UFG::qVector3 *v30; // r9

  m_pActionContext = this->m_pActionContext;
  if ( m_pActionContext )
  {
    m_pPointer = (UFG::SimObjectCVBase *)m_pActionContext->mSimObject.m_pPointer;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
      {
        ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(m_pPointer);
      }
      else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      {
        ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        m_pPointer,
                                                        UFG::AiDriverComponent::_TypeUID);
      }
      else
      {
        ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                                        m_pPointer,
                                                        UFG::AiDriverComponent::_TypeUID);
      }
      v4 = ComponentOfTypeHK;
    }
    else
    {
      v4 = 0i64;
    }
    p_m_pAIComponent = &this->m_pAIComponent;
    if ( this->m_pAIComponent.m_pPointer )
    {
      mPrev = p_m_pAIComponent->mPrev;
      mNext = this->m_pAIComponent.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_m_pAIComponent->mPrev = p_m_pAIComponent;
      this->m_pAIComponent.mNext = &this->m_pAIComponent;
    }
    this->m_pAIComponent.m_pPointer = v4;
    if ( v4 )
    {
      v10 = v4->m_SafePointerList.mNode.mPrev;
      v10->mNext = p_m_pAIComponent;
      p_m_pAIComponent->mPrev = v10;
      this->m_pAIComponent.mNext = &v4->m_SafePointerList.mNode;
      v4->m_SafePointerList.mNode.mPrev = p_m_pAIComponent;
    }
    v11 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
    if ( v11 )
    {
      v13 = v11->m_Flags;
      if ( (v13 & 0x4000) != 0 )
      {
        m_pComponent = v11->m_Components.p[24].m_pComponent;
      }
      else if ( v13 >= 0 )
      {
        if ( (v13 & 0x2000) != 0 || (v13 & 0x1000) != 0 )
          ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::RoadSpaceComponent::_TypeUID);
        else
          ComponentOfType = UFG::SimObject::GetComponentOfType(v11, UFG::RoadSpaceComponent::_TypeUID);
        m_pComponent = ComponentOfType;
      }
      else
      {
        m_pComponent = v11->m_Components.p[24].m_pComponent;
      }
    }
    else
    {
      m_pComponent = 0i64;
    }
    p_m_pRoadSpaceComponent = &this->m_pRoadSpaceComponent;
    if ( this->m_pRoadSpaceComponent.m_pPointer )
    {
      v16 = p_m_pRoadSpaceComponent->mPrev;
      v17 = this->m_pRoadSpaceComponent.mNext;
      v16->mNext = v17;
      v17->mPrev = v16;
      p_m_pRoadSpaceComponent->mPrev = p_m_pRoadSpaceComponent;
      this->m_pRoadSpaceComponent.mNext = &this->m_pRoadSpaceComponent;
    }
    this->m_pRoadSpaceComponent.m_pPointer = m_pComponent;
    if ( m_pComponent )
    {
      v18 = m_pComponent->m_SafePointerList.mNode.mPrev;
      v18->mNext = p_m_pRoadSpaceComponent;
      p_m_pRoadSpaceComponent->mPrev = v18;
      this->m_pRoadSpaceComponent.mNext = &m_pComponent->m_SafePointerList.mNode;
      m_pComponent->m_SafePointerList.mNode.mPrev = p_m_pRoadSpaceComponent;
    }
    v19 = (UFG::AiDriverComponent *)this->m_pAIComponent.m_pPointer;
    if ( v19->m_bIsParked )
      UFG::AiDriverComponent::SetParked(v19, 0);
    if ( !UFG::RoadSpaceComponent::IsAttachedToRoadNetwork((UFG::RoadSpaceComponent *)this->m_pRoadSpaceComponent.m_pPointer) )
      UFG::RoadSpaceComponent::AttachToRoadNetwork((UFG::RoadSpaceComponent *)this->m_pRoadSpaceComponent.m_pPointer, 0);
    v20 = this->m_pActionContext->mSimObject.m_pPointer;
    if ( v20 )
      m_pTransformNodeComponent = v20->m_pTransformNodeComponent;
    else
      m_pTransformNodeComponent = 0i64;
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
    v22 = this->m_pActionContext->mSimObject.m_pPointer;
    if ( v22 )
      v23 = v22->m_pTransformNodeComponent;
    else
      v23 = 0i64;
    UFG::TransformNodeComponent::UpdateWorldTransform(v23);
    p_m_pSimObject = (UFG::VehicleWayFinderClient *)&this->m_pRoadSpaceComponent.m_pPointer[8].m_pSimObject;
    UFG::WayFinderClient::Reset(p_m_pSimObject);
    v25 = this->m_pRoadSpaceComponent.m_pPointer;
    p_m_BoundComponentHandles = (UFG::qVector3 *)&v25[25].m_BoundComponentHandles;
    v27 = (float *)&v25[25].m_BoundComponentHandles.mNode.mNext + 1;
    RoadWayFinder = UFG::WheeledVehicleNavigationData::GetRoadWayFinder(
                      UFG::WheeledVehicleManager::m_Instance->m_NavigationData,
                      p_m_pSimObject);
    v29 = RoadWayFinder;
    if ( LOBYTE(this->m_pAIComponent.m_pPointer[22].m_BoundComponentHandles.mNode.mNext)
      || UFG::qVector3::msZero.x == *v27 && UFG::qVector3::msZero.y == v27[1] && UFG::qVector3::msZero.z == v27[2] )
    {
      v30 = 0i64;
    }
    else
    {
      v30 = (UFG::qVector3 *)v27;
    }
    UFG::WayFinder::FindWay(RoadWayFinder, p_m_pSimObject, p_m_BoundComponentHandles, v30);
    UFG::WayFinder::Service(v29, 0.0);
    if ( p_m_pSimObject->m_NumWayEdges )
      UFG::VehicleOccupantComponent::SetParkingSpot(
        (UFG::RoadNetworkGuide *)&this->m_pRoadSpaceComponent.m_pPointer[5].m_BoundComponentHandles.mNode.mNext,
        0i64);
  }
}

// File Line: 619
// RVA: 0x671640
void __fastcall CarGoToTask::Begin(CarGoToTask *this, ActionContext *action_context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::SimComponent *v4; // r8
  __int16 m_Flags; // dx
  UFG::AiDriverComponent *ComponentOfTypeHK; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AiDriverComponent> *p_m_pAIComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::SimObjectGame *v11; // rcx
  UFG::SimComponent *m_pComponent; // r8
  __int16 v13; // dx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::RoadSpaceComponent> *p_m_pRoadSpaceComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rax
  UFG::RoadSpaceComponent *v19; // rcx
  bool IsNavGuideEnabled; // al
  UFG::AiDriverComponent *v21; // rcx
  UFG::SimObject *v22; // rcx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  unsigned int m_TypeUID; // esi
  UFG::RoadNetworkResource *RoadNetwork; // rbp
  UFG::RoadNetworkIntersection *ClosestNode; // rbx
  UFG::RoadNetworkLocation *Name; // rax

  this->m_pActionContext = action_context;
  if ( action_context )
  {
    m_pPointer = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
      {
        ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(m_pPointer);
      }
      else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      {
        ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        m_pPointer,
                                                        UFG::AiDriverComponent::_TypeUID);
      }
      else
      {
        ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                                        m_pPointer,
                                                        UFG::AiDriverComponent::_TypeUID);
      }
      v4 = ComponentOfTypeHK;
    }
    else
    {
      v4 = 0i64;
    }
    p_m_pAIComponent = &this->m_pAIComponent;
    if ( this->m_pAIComponent.m_pPointer )
    {
      mPrev = p_m_pAIComponent->mPrev;
      mNext = this->m_pAIComponent.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_m_pAIComponent->mPrev = p_m_pAIComponent;
      this->m_pAIComponent.mNext = &this->m_pAIComponent;
    }
    this->m_pAIComponent.m_pPointer = v4;
    if ( v4 )
    {
      v10 = v4->m_SafePointerList.mNode.mPrev;
      v10->mNext = p_m_pAIComponent;
      p_m_pAIComponent->mPrev = v10;
      this->m_pAIComponent.mNext = &v4->m_SafePointerList.mNode;
      v4->m_SafePointerList.mNode.mPrev = p_m_pAIComponent;
    }
    v11 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
    if ( v11 )
    {
      v13 = v11->m_Flags;
      if ( (v13 & 0x4000) != 0 )
      {
        m_pComponent = v11->m_Components.p[24].m_pComponent;
      }
      else if ( v13 >= 0 )
      {
        if ( (v13 & 0x2000) != 0 || (v13 & 0x1000) != 0 )
          ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::RoadSpaceComponent::_TypeUID);
        else
          ComponentOfType = UFG::SimObject::GetComponentOfType(v11, UFG::RoadSpaceComponent::_TypeUID);
        m_pComponent = ComponentOfType;
      }
      else
      {
        m_pComponent = v11->m_Components.p[24].m_pComponent;
      }
    }
    else
    {
      m_pComponent = 0i64;
    }
    p_m_pRoadSpaceComponent = &this->m_pRoadSpaceComponent;
    if ( this->m_pRoadSpaceComponent.m_pPointer )
    {
      v16 = p_m_pRoadSpaceComponent->mPrev;
      v17 = this->m_pRoadSpaceComponent.mNext;
      v16->mNext = v17;
      v17->mPrev = v16;
      p_m_pRoadSpaceComponent->mPrev = p_m_pRoadSpaceComponent;
      this->m_pRoadSpaceComponent.mNext = &this->m_pRoadSpaceComponent;
    }
    this->m_pRoadSpaceComponent.m_pPointer = m_pComponent;
    if ( m_pComponent )
    {
      v18 = m_pComponent->m_SafePointerList.mNode.mPrev;
      v18->mNext = p_m_pRoadSpaceComponent;
      p_m_pRoadSpaceComponent->mPrev = v18;
      this->m_pRoadSpaceComponent.mNext = &m_pComponent->m_SafePointerList.mNode;
      m_pComponent->m_SafePointerList.mNode.mPrev = p_m_pRoadSpaceComponent;
    }
  }
  v19 = (UFG::RoadSpaceComponent *)this->m_pRoadSpaceComponent.m_pPointer;
  if ( v19 )
  {
    IsNavGuideEnabled = UFG::RoadSpaceComponent::IsNavGuideEnabled(v19);
    v21 = (UFG::AiDriverComponent *)this->m_pAIComponent.m_pPointer;
    if ( IsNavGuideEnabled )
    {
      UFG::AiDriverComponent::BeginPathingNavigation(v21);
    }
    else
    {
      if ( v21->m_bIsParked )
        UFG::AiDriverComponent::SetParked(v21, 0);
      if ( !UFG::RoadSpaceComponent::IsAttachedToRoadNetwork((UFG::RoadSpaceComponent *)this->m_pRoadSpaceComponent.m_pPointer) )
        goto LABEL_42;
      v22 = this->m_pActionContext->mSimObject.m_pPointer;
      if ( v22 )
      {
        m_pTransformNodeComponent = v22->m_pTransformNodeComponent;
        if ( m_pTransformNodeComponent )
        {
          m_TypeUID = 0;
          RoadNetwork = UFG::WheeledVehicleNavigationData::GetRoadNetwork(UFG::WheeledVehicleManager::m_Instance->m_NavigationData);
          if ( this->m_pRoadSpaceComponent.m_pPointer != (UFG::SimComponent *)-552i64 )
            m_TypeUID = this->m_pRoadSpaceComponent.m_pPointer[25].m_TypeUID;
          UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
          ClosestNode = UFG::RoadNetworkResource::GetClosestNode(
                          RoadNetwork,
                          (UFG::qVector3 *)&m_pTransformNodeComponent->mWorldTransform.v3,
                          m_TypeUID,
                          0i64,
                          0i64);
          Name = Scaleform::GFx::AS3::Instances::fl::XML::GetName((UFG::RoadNetworkGuide *)&this->m_pRoadSpaceComponent.m_pPointer[5].m_BoundComponentHandles.mNode.mNext);
          if ( ClosestNode != UFG::RoadNetworkLocation::GetRoadNetworkNode(Name) )
LABEL_42:
            UFG::RoadSpaceComponent::AttachToRoadNetwork(
              (UFG::RoadSpaceComponent *)this->m_pRoadSpaceComponent.m_pPointer,
              0);
        }
      }
      if ( !WORD2(this->m_pRoadSpaceComponent.m_pPointer[9].m_SafePointerList.mNode.mPrev) )
        CarGoToTask::FindWay(this);
    }
  }
}

// File Line: 670
// RVA: 0x68FAC0
char __fastcall CarGoToTask::Update(CarGoToTask *this, float timestep)
{
  UFG::RoadSpaceComponent *m_pPointer; // rcx
  bool updated; // si
  UFG::AiDriverComponent *v5; // r8
  SSInvokedCoroutine *i_obj_p; // rcx
  __int64 i_ptr_id; // rdx
  UFG::VehicleWayFinderClient *p_m_pSimObject; // rsi
  UFG::WayFinder *RoadWayFinder; // rax
  UFG::RoadNetworkLocation *Name; // rax
  UFG::AiDriverComponent *v12; // rcx
  UFG::SimComponent *v13; // rax
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm0_4
  ActionContext *m_pActionContext; // rax
  UFG::SimObject *v18; // r14
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // r14
  char v20; // bp
  UFG::RoadNetworkGuide *p_mNext; // r14
  UFG::RoadNetworkLocation *v22; // rax
  UFG::RoadNetworkNode *RoadNetworkNode; // rax
  UFG::RoadNetworkLane *ClosestLane; // r15
  float m_LaneT; // xmm6_4
  __int64 mOffset; // rax
  char *v27; // rsi
  UFG::RoadNetworkLane *m_CurrentLane; // rcx
  __int64 v29; // rax
  UFG::qOffset64<UFG::RoadNetworkGate *> *p_mStartGate; // rcx
  char *v31; // rax
  UFG::AiDriverComponent *v32; // rdx
  SSInvokedCoroutine *v33; // rcx
  UFG::qVector3 pos; // [rsp+20h] [rbp-48h] BYREF
  UFG::qVector3 v35; // [rsp+30h] [rbp-38h] BYREF

  m_pPointer = (UFG::RoadSpaceComponent *)this->m_pRoadSpaceComponent.m_pPointer;
  if ( !m_pPointer || !this->m_pAIComponent.m_pPointer )
    return 0;
  if ( UFG::RoadSpaceComponent::IsNavGuideEnabled(m_pPointer) )
  {
    updated = UFG::AiDriverComponent::UpdatePathingNavigation((UFG::AiDriverComponent *)this->m_pAIComponent.m_pPointer);
    if ( updated )
    {
      v5 = (UFG::AiDriverComponent *)this->m_pAIComponent.m_pPointer;
      i_obj_p = v5->m_DriveToCoroutine.i_obj_p;
      if ( i_obj_p )
      {
        i_ptr_id = i_obj_p->i_ptr_id;
        if ( v5->m_DriveToCoroutine.i_ptr_id == (_DWORD)i_ptr_id )
        {
          LOBYTE(i_ptr_id) = 1;
          ((void (__fastcall *)(SSInvokedCoroutine *, __int64))i_obj_p->vfptr[1].get_topmost_scope)(i_obj_p, i_ptr_id);
        }
      }
      UFG::AiDriverComponent::SetDrivingMode((UFG::AiDriverComponent *)this->m_pAIComponent.m_pPointer, 5u);
    }
    return !updated;
  }
  else
  {
    p_m_pSimObject = (UFG::VehicleWayFinderClient *)&this->m_pRoadSpaceComponent.m_pPointer[8].m_pSimObject;
    RoadWayFinder = UFG::WheeledVehicleNavigationData::GetRoadWayFinder(
                      UFG::WheeledVehicleManager::m_Instance->m_NavigationData,
                      p_m_pSimObject);
    if ( !p_m_pSimObject->m_NumWayEdges || UFG::WayFinderClient::LostWay(p_m_pSimObject, RoadWayFinder->m_WayGraph) )
    {
      Name = Scaleform::GFx::AS3::Instances::fl::XML::GetName((UFG::RoadNetworkGuide *)&this->m_pRoadSpaceComponent.m_pPointer[5].m_BoundComponentHandles.mNode.mNext);
      if ( UFG::RoadNetworkLocation::GetRoadNetworkNode(Name)->mType.mValue != 1 )
        CarGoToTask::FindWay(this);
    }
    v12 = (UFG::AiDriverComponent *)this->m_pAIComponent.m_pPointer;
    if ( p_m_pSimObject->m_NumWayEdges )
      UFG::AiDriverComponent::UpdateWayfindingNavigation(v12);
    else
      UFG::AiDriverComponent::UpdateWanderingNavigation(v12);
    if ( UFG::AiDriverComponent::IsTransit((UFG::AiDriverComponent *)this->m_pAIComponent.m_pPointer) )
    {
      return 1;
    }
    else
    {
      v13 = this->m_pRoadSpaceComponent.m_pPointer;
      v14 = *((float *)&v13[25].m_BoundComponentHandles.mNode.mPrev + 1);
      v15 = *(float *)&v13[25].m_BoundComponentHandles.mNode.mNext;
      v16 = *(float *)&v13[25].m_BoundComponentHandles.mNode.mPrev;
      m_pActionContext = this->m_pActionContext;
      pos.x = v16;
      pos.y = v14;
      pos.z = v15;
      v18 = m_pActionContext->mSimObject.m_pPointer;
      if ( v18 )
        m_pTransformNodeComponent = v18->m_pTransformNodeComponent;
      else
        m_pTransformNodeComponent = 0i64;
      UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
      v20 = 0;
      if ( (float)((float)((float)((float)(pos.y - m_pTransformNodeComponent->mWorldTransform.v3.y)
                                 * (float)(pos.y - m_pTransformNodeComponent->mWorldTransform.v3.y))
                         + (float)((float)(pos.x - m_pTransformNodeComponent->mWorldTransform.v3.x)
                                 * (float)(pos.x - m_pTransformNodeComponent->mWorldTransform.v3.x)))
                 + (float)((float)(pos.z - m_pTransformNodeComponent->mWorldTransform.v3.z)
                         * (float)(pos.z - m_pTransformNodeComponent->mWorldTransform.v3.z))) < (float)(*((float *)&this->m_pAIComponent.m_pPointer[23].m_BoundComponentHandles.mNode.mPrev + 1) * *((float *)&this->m_pAIComponent.m_pPointer[23].m_BoundComponentHandles.mNode.mPrev + 1)) )
        goto LABEL_33;
      if ( p_m_pSimObject->m_CurrEdgeIndex == p_m_pSimObject->m_NumWayEdges - 1 )
      {
        p_mNext = (UFG::RoadNetworkGuide *)&this->m_pRoadSpaceComponent.m_pPointer[5].m_BoundComponentHandles.mNode.mNext;
        v22 = Scaleform::GFx::AS3::Instances::fl::XML::GetName(p_mNext);
        RoadNetworkNode = UFG::RoadNetworkLocation::GetRoadNetworkNode(v22);
        ClosestLane = UFG::RoadNetworkNode::GetClosestLane(RoadNetworkNode, &pos);
        m_LaneT = Scaleform::GFx::AS3::Instances::fl::XML::GetName(p_mNext)->m_LaneT;
        mOffset = ClosestLane->mStartGate.mOffset;
        if ( mOffset )
          v27 = (char *)&ClosestLane->mStartGate + mOffset;
        else
          v27 = 0i64;
        m_CurrentLane = Scaleform::GFx::AS3::Instances::fl::XML::GetName(p_mNext)->m_CurrentLane;
        v29 = m_CurrentLane->mStartGate.mOffset;
        p_mStartGate = &m_CurrentLane->mStartGate;
        if ( v29 )
          v31 = (char *)p_mStartGate + v29;
        else
          v31 = 0i64;
        if ( v27 != v31 )
          m_LaneT = 1.0 - m_LaneT;
        UFG::RoadNetworkLane::GetPos(ClosestLane, &v35, m_LaneT);
        if ( (float)((float)((float)((float)(v35.y - pos.y) * (float)(v35.y - pos.y))
                           + (float)((float)(v35.x - pos.x) * (float)(v35.x - pos.x)))
                   + (float)((float)(v35.z - pos.z) * (float)(v35.z - pos.z))) < 100.0 )
        {
LABEL_33:
          v32 = (UFG::AiDriverComponent *)this->m_pAIComponent.m_pPointer;
          v20 = 1;
          v33 = v32->m_DriveToCoroutine.i_obj_p;
          if ( v33 && v32->m_DriveToCoroutine.i_ptr_id == v33->i_ptr_id )
            ((void (__fastcall *)(SSInvokedCoroutine *, __int64))v33->vfptr[1].get_topmost_scope)(v33, 1i64);
          UFG::AiDriverComponent::SetDrivingMode((UFG::AiDriverComponent *)this->m_pAIComponent.m_pPointer, 5u);
        }
      }
      return v20 == 0;
    }
  }
}

// File Line: 762
// RVA: 0x677C00
void __fastcall CarGoToTask::End(CarGoToTask *this)
{
  UFG::RoadSpaceComponent *m_pPointer; // rcx
  UFG::SimComponent *v3; // rbx

  m_pPointer = (UFG::RoadSpaceComponent *)this->m_pRoadSpaceComponent.m_pPointer;
  if ( m_pPointer )
  {
    if ( UFG::RoadSpaceComponent::IsNavGuideEnabled(m_pPointer) )
    {
      UFG::AiDriverComponent::EndPathingNavigation((UFG::AiDriverComponent *)this->m_pAIComponent.m_pPointer);
    }
    else
    {
      v3 = this->m_pRoadSpaceComponent.m_pPointer;
      UFG::WayFinderClient::Reset((UFG::WayFinderClient *)&v3[8].m_pSimObject);
      ((void (__fastcall *)(UFG::SimObject **))v3[8].m_pSimObject->m_pTransformNodeComponent)(&v3[8].m_pSimObject);
    }
  }
}

// File Line: 788
// RVA: 0x667790
void __fastcall CarNoDestinationTask::CarNoDestinationTask(CarNoDestinationTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::AiDriverComponent> *p_m_pAIComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax

  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<CarNoDestinationTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&CarNoDestinationTask::`vftable;
  p_m_pAIComponent = &this->m_pAIComponent;
  this->m_pAIComponent.mPrev = &this->m_pAIComponent;
  this->m_pAIComponent.mNext = &this->m_pAIComponent;
  this->m_pAIComponent.m_pPointer = 0i64;
  this->m_pActionContext = 0i64;
  if ( this->m_pAIComponent.m_pPointer )
  {
    mPrev = p_m_pAIComponent->mPrev;
    mNext = p_m_pAIComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pAIComponent->mPrev = p_m_pAIComponent;
    p_m_pAIComponent->mNext = p_m_pAIComponent;
  }
  p_m_pAIComponent->m_pPointer = 0i64;
}

// File Line: 797
// RVA: 0x6718F0
void __fastcall CarNoDestinationTask::Begin(CarNoDestinationTask *this, ActionContext *action_context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::SimComponent *v4; // r8
  __int16 m_Flags; // dx
  UFG::AiDriverComponent *ComponentOfTypeHK; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AiDriverComponent> *p_m_pAIComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::SimComponent *v11; // rcx
  UFG::SimObjectGame *v12; // rcx
  __int16 v13; // dx
  UFG::RoadSpaceComponent *m_pComponent; // rbx
  UFG::SimComponent *ComponentOfType; // rax

  this->m_pActionContext = action_context;
  if ( action_context )
  {
    m_pPointer = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
      {
        ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(m_pPointer);
      }
      else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      {
        ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        m_pPointer,
                                                        UFG::AiDriverComponent::_TypeUID);
      }
      else
      {
        ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                                        m_pPointer,
                                                        UFG::AiDriverComponent::_TypeUID);
      }
      v4 = ComponentOfTypeHK;
    }
    else
    {
      v4 = 0i64;
    }
    p_m_pAIComponent = &this->m_pAIComponent;
    if ( this->m_pAIComponent.m_pPointer )
    {
      mPrev = p_m_pAIComponent->mPrev;
      mNext = this->m_pAIComponent.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_m_pAIComponent->mPrev = p_m_pAIComponent;
      this->m_pAIComponent.mNext = &this->m_pAIComponent;
    }
    this->m_pAIComponent.m_pPointer = v4;
    if ( v4 )
    {
      v10 = v4->m_SafePointerList.mNode.mPrev;
      v10->mNext = p_m_pAIComponent;
      p_m_pAIComponent->mPrev = v10;
      this->m_pAIComponent.mNext = &v4->m_SafePointerList.mNode;
      v4->m_SafePointerList.mNode.mPrev = p_m_pAIComponent;
    }
    v11 = this->m_pAIComponent.m_pPointer;
    if ( v11 )
    {
      if ( !v11->vfptr[16].__vecDelDtor(v11, (unsigned int)p_m_pAIComponent)
        && !UFG::AiDriverComponent::IsTaxi((UFG::AiDriverComponent *)this->m_pAIComponent.m_pPointer) )
      {
        v12 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
        if ( v12 )
        {
          v13 = v12->m_Flags;
          if ( (v13 & 0x4000) != 0 )
          {
            m_pComponent = (UFG::RoadSpaceComponent *)v12->m_Components.p[24].m_pComponent;
          }
          else if ( v13 >= 0 )
          {
            if ( (v13 & 0x2000) != 0 || (v13 & 0x1000) != 0 )
              ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::RoadSpaceComponent::_TypeUID);
            else
              ComponentOfType = UFG::SimObject::GetComponentOfType(v12, UFG::RoadSpaceComponent::_TypeUID);
            m_pComponent = (UFG::RoadSpaceComponent *)ComponentOfType;
          }
          else
          {
            m_pComponent = (UFG::RoadSpaceComponent *)v12->m_Components.p[24].m_pComponent;
          }
          if ( m_pComponent )
          {
            if ( UFG::RoadSpaceComponent::IsAttachedToRoadNetwork(m_pComponent) )
              UFG::RoadSpaceComponent::DetachFromRoadNetwork(m_pComponent);
          }
        }
      }
    }
  }
}

// File Line: 849
// RVA: 0x667110
void __fastcall CarAttackTask::CarAttackTask(CarAttackTask *this)
{
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<CarAttackTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&CarAttackTask::`vftable;
  this->m_pActionContext = 0i64;
}

// File Line: 857
// RVA: 0x671020
void __fastcall CarAttackTask::Begin(CarAttackTask *this, ActionContext *action_context)
{
  ITrack *m_Track; // rdi
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::AiDriverComponent *ComponentOfTypeHK; // rax

  m_Track = this->m_Track;
  this->m_pActionContext = action_context;
  if ( action_context )
  {
    m_pPointer = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
      {
        ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(m_pPointer);
      }
      else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      {
        ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        m_pPointer,
                                                        UFG::AiDriverComponent::_TypeUID);
      }
      else
      {
        ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                                        m_pPointer,
                                                        UFG::AiDriverComponent::_TypeUID);
      }
      if ( ComponentOfTypeHK )
        UFG::AiDriverComponent::BeginAttack(ComponentOfTypeHK, (CarCombat::Attack)LOBYTE(m_Track[1].vfptr));
    }
    this->m_fTime = 0.0;
  }
  else
  {
    this->m_fTime = 0.0;
  }
}

// File Line: 872
// RVA: 0x68F9E0
bool __fastcall CarAttackTask::Update(CarFormationAttackTask *this, float timestep)
{
  float v2; // xmm1_4
  ITrack *m_Track; // rax

  v2 = timestep + this->m_fTime;
  m_Track = this->m_Track;
  this->m_fTime = v2;
  return v2 <= *((float *)&m_Track[1].vfptr + 1);
}

// File Line: 888
// RVA: 0x677940
void __fastcall CarAttackTask::End(CarAttackTask *this)
{
  ActionContext *m_pActionContext; // rcx
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::AiDriverComponent *ComponentOfTypeHK; // rax

  m_pActionContext = this->m_pActionContext;
  if ( m_pActionContext )
  {
    m_pPointer = (UFG::SimObjectCVBase *)m_pActionContext->mSimObject.m_pPointer;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
      {
        ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(m_pPointer);
      }
      else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      {
        ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        m_pPointer,
                                                        UFG::AiDriverComponent::_TypeUID);
      }
      else
      {
        ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                                        m_pPointer,
                                                        UFG::AiDriverComponent::_TypeUID);
      }
      if ( ComponentOfTypeHK )
        UFG::AiDriverComponent::EndAttack(ComponentOfTypeHK);
    }
  }
}

// File Line: 907
// RVA: 0x6672B0
void __fastcall CarFormationAttackTask::CarFormationAttackTask(CarFormationAttackTask *this)
{
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<CarFormationAttackTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&CarFormationAttackTask::`vftable;
  this->m_pActionContext = 0i64;
}

// File Line: 915
// RVA: 0x671270
void __fastcall CarFormationAttackTask::Begin(CarFormationAttackTask *this, ActionContext *action_context)
{
  ITrack *m_Track; // rdi
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::RoadSpaceComponent *m_pComponent; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *CarChaseTargetFormation; // rax

  m_Track = this->m_Track;
  this->m_pActionContext = action_context;
  m_pPointer = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::RoadSpaceComponent *)m_pPointer->m_Components.p[24].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        m_pComponent = (UFG::RoadSpaceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    m_pPointer,
                                                    UFG::RoadSpaceComponent::_TypeUID);
      else
        m_pComponent = (UFG::RoadSpaceComponent *)UFG::SimObject::GetComponentOfType(
                                                    m_pPointer,
                                                    UFG::RoadSpaceComponent::_TypeUID);
    }
    else
    {
      m_pComponent = (UFG::RoadSpaceComponent *)m_pPointer->m_Components.p[24].m_pComponent;
    }
    if ( m_pComponent )
    {
      CarChaseTargetFormation = UFG::RoadSpaceComponent::GetCarChaseTargetFormation(m_pComponent);
      if ( CarChaseTargetFormation )
        HIDWORD(CarChaseTargetFormation[36].mPrev) = LOBYTE(m_Track[1].vfptr);
    }
  }
  this->m_fTime = 0.0;
}

// File Line: 950
// RVA: 0x6779D0
void __fastcall CarFormationAttackTask::End(CarFormationAttackTask *this)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::RoadSpaceComponent *m_pComponent; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *CarChaseTargetFormation; // rax

  m_pPointer = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::RoadSpaceComponent *)m_pPointer->m_Components.p[24].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        m_pComponent = (UFG::RoadSpaceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    m_pPointer,
                                                    UFG::RoadSpaceComponent::_TypeUID);
      else
        m_pComponent = (UFG::RoadSpaceComponent *)UFG::SimObject::GetComponentOfType(
                                                    m_pPointer,
                                                    UFG::RoadSpaceComponent::_TypeUID);
    }
    else
    {
      m_pComponent = (UFG::RoadSpaceComponent *)m_pPointer->m_Components.p[24].m_pComponent;
    }
    if ( m_pComponent )
    {
      CarChaseTargetFormation = UFG::RoadSpaceComponent::GetCarChaseTargetFormation(m_pComponent);
      if ( CarChaseTargetFormation )
        UFG::VehicleFormations::EndAttack(
          (UFG::VehicleFormations *)CarChaseTargetFormation,
          this->m_pActionContext->mSimObject.m_pPointer);
    }
  }
}

// File Line: 971
// RVA: 0x6674E0
void __fastcall CarFormationTask::CarFormationTask(CarFormationTask *this)
{
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<CarFormationTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&CarFormationTask::`vftable;
  this->m_pActionContext = 0i64;
}

// File Line: 979
// RVA: 0x6714D0
void __fastcall CarFormationTask::Begin(CarFormationTask *this, ActionContext *action_context)
{
  ITrack *m_Track; // rbx
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *CarChaseTargetFormation; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rdx
  char v8; // cl
  char v9; // cl
  char v10; // al
  char v11; // al
  char v12; // al
  char v13; // al
  char v14; // al

  m_Track = this->m_Track;
  this->m_pActionContext = action_context;
  if ( action_context )
  {
    m_pPointer = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = m_pPointer->m_Components.p[24].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::RoadSpaceComponent::_TypeUID);
        else
          m_pComponent = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::RoadSpaceComponent::_TypeUID);
      }
      else
      {
        m_pComponent = m_pPointer->m_Components.p[24].m_pComponent;
      }
      if ( m_pComponent )
      {
        m_pComponent[30].m_TypeUID |= 2u;
        CarChaseTargetFormation = UFG::RoadSpaceComponent::GetCarChaseTargetFormation((UFG::RoadSpaceComponent *)m_pComponent);
        v7 = CarChaseTargetFormation;
        if ( CarChaseTargetFormation )
        {
          v8 = LOBYTE(m_Track[1].vfptr) != 0;
          BYTE2(CarChaseTargetFormation[28].mPrev) += v8;
          BYTE1(CarChaseTargetFormation[28].mNext) += v8;
          BYTE6(CarChaseTargetFormation[38].mPrev) = 1;
          v9 = BYTE1(m_Track[1].vfptr) != 0;
          BYTE3(CarChaseTargetFormation[28].mPrev) += v9;
          BYTE2(CarChaseTargetFormation[28].mNext) += v9;
          BYTE6(CarChaseTargetFormation[38].mPrev) = 1;
          v10 = BYTE2(m_Track[1].vfptr) != 0;
          BYTE4(v7[28].mPrev) += v10;
          BYTE3(v7[28].mNext) += v10;
          BYTE6(v7[38].mPrev) = 1;
          v11 = BYTE3(m_Track[1].vfptr) != 0;
          BYTE5(v7[28].mPrev) += v11;
          BYTE4(v7[28].mNext) += v11;
          BYTE6(v7[38].mPrev) = 1;
          v12 = BYTE4(m_Track[1].vfptr) != 0;
          BYTE6(v7[28].mPrev) += v12;
          BYTE5(v7[28].mNext) += v12;
          BYTE6(v7[38].mPrev) = 1;
          v13 = BYTE5(m_Track[1].vfptr) != 0;
          HIBYTE(v7[28].mPrev) += v13;
          BYTE6(v7[28].mNext) += v13;
          BYTE6(v7[38].mPrev) = 1;
          v14 = BYTE6(m_Track[1].vfptr) != 0;
          LOBYTE(v7[28].mNext) += v14;
          HIBYTE(v7[28].mNext) += v14;
          BYTE6(v7[38].mPrev) = 1;
        }
      }
    }
  }
}

// File Line: 1013
// RVA: 0x677A80
void __fastcall CarFormationTask::End(CarFormationTask *this)
{
  ITrack *m_Track; // rbx
  ActionContext *m_pActionContext; // rcx
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::RoadSpaceComponent *m_pComponent; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *CarChaseTargetFormation; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // r8
  char v8; // dl
  char v9; // cl
  char v10; // cl
  char v11; // cl
  char v12; // cl
  char v13; // cl
  char v14; // al

  m_Track = this->m_Track;
  m_pActionContext = this->m_pActionContext;
  if ( m_pActionContext )
  {
    m_pPointer = (UFG::SimObjectGame *)m_pActionContext->mSimObject.m_pPointer;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = (UFG::RoadSpaceComponent *)m_pPointer->m_Components.p[24].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          m_pComponent = (UFG::RoadSpaceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      m_pPointer,
                                                      UFG::RoadSpaceComponent::_TypeUID);
        else
          m_pComponent = (UFG::RoadSpaceComponent *)UFG::SimObject::GetComponentOfType(
                                                      m_pPointer,
                                                      UFG::RoadSpaceComponent::_TypeUID);
      }
      else
      {
        m_pComponent = (UFG::RoadSpaceComponent *)m_pPointer->m_Components.p[24].m_pComponent;
      }
      if ( m_pComponent )
      {
        CarChaseTargetFormation = UFG::RoadSpaceComponent::GetCarChaseTargetFormation(m_pComponent);
        v7 = CarChaseTargetFormation;
        if ( CarChaseTargetFormation )
        {
          v8 = -(LOBYTE(m_Track[1].vfptr) != 0);
          BYTE2(CarChaseTargetFormation[28].mPrev) -= LOBYTE(m_Track[1].vfptr) != 0;
          BYTE1(CarChaseTargetFormation[28].mNext) += v8;
          BYTE6(CarChaseTargetFormation[38].mPrev) = 1;
          v9 = BYTE1(m_Track[1].vfptr);
          BYTE3(CarChaseTargetFormation[28].mPrev) -= v9 != 0;
          BYTE2(CarChaseTargetFormation[28].mNext) -= v9 != 0;
          BYTE6(CarChaseTargetFormation[38].mPrev) = 1;
          v10 = -(BYTE2(m_Track[1].vfptr) != 0);
          BYTE4(CarChaseTargetFormation[28].mPrev) -= BYTE2(m_Track[1].vfptr) != 0;
          BYTE3(CarChaseTargetFormation[28].mNext) += v10;
          BYTE6(CarChaseTargetFormation[38].mPrev) = 1;
          v11 = -(BYTE3(m_Track[1].vfptr) != 0);
          BYTE5(CarChaseTargetFormation[28].mPrev) -= BYTE3(m_Track[1].vfptr) != 0;
          BYTE4(CarChaseTargetFormation[28].mNext) += v11;
          BYTE6(CarChaseTargetFormation[38].mPrev) = 1;
          v12 = -(BYTE4(m_Track[1].vfptr) != 0);
          BYTE6(CarChaseTargetFormation[28].mPrev) -= BYTE4(m_Track[1].vfptr) != 0;
          BYTE5(CarChaseTargetFormation[28].mNext) += v12;
          BYTE6(CarChaseTargetFormation[38].mPrev) = 1;
          v13 = -(BYTE5(m_Track[1].vfptr) != 0);
          HIBYTE(CarChaseTargetFormation[28].mPrev) -= BYTE5(m_Track[1].vfptr) != 0;
          BYTE6(CarChaseTargetFormation[28].mNext) += v13;
          BYTE6(CarChaseTargetFormation[38].mPrev) = 1;
          v14 = -BYTE6(m_Track[1].vfptr);
          LOBYTE(v7[28].mNext) -= BYTE6(m_Track[1].vfptr) != 0;
          HIBYTE(v7[28].mNext) -= v14 != 0;
          BYTE6(v7[38].mPrev) = 1;
        }
      }
    }
  }
}

// File Line: 1039
// RVA: 0x667930
void __fastcall CarOffsetDriveTask::CarOffsetDriveTask(CarOffsetDriveTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::AiDriverComponent> *p_m_pAIComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax

  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<CarOffsetDriveTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&CarOffsetDriveTask::`vftable;
  p_m_pAIComponent = &this->m_pAIComponent;
  this->m_pAIComponent.mPrev = &this->m_pAIComponent;
  this->m_pAIComponent.mNext = &this->m_pAIComponent;
  this->m_pAIComponent.m_pPointer = 0i64;
  this->m_pActionContext = 0i64;
  if ( this->m_pAIComponent.m_pPointer )
  {
    mPrev = p_m_pAIComponent->mPrev;
    mNext = p_m_pAIComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pAIComponent->mPrev = p_m_pAIComponent;
    p_m_pAIComponent->mNext = p_m_pAIComponent;
  }
  p_m_pAIComponent->m_pPointer = 0i64;
}

// File Line: 1048
// RVA: 0x671C40
void __fastcall CarOffsetDriveTask::Begin(CarOffsetDriveTask *this, ActionContext *action_context)
{
  ITrack *m_Track; // rbp
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::SimComponent *v5; // rdi
  UFG::RoadSpaceComponent *m_pComponent; // rbx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::WayFinder *RoadWayFinder; // rax
  UFG::SimObjectCVBase *v10; // rcx
  __int16 v11; // dx
  UFG::AiDriverComponent *ComponentOfType; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AiDriverComponent> *p_m_pAIComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax

  m_Track = this->m_Track;
  this->m_pActionContext = action_context;
  if ( action_context )
  {
    m_pPointer = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
    v5 = 0i64;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = (UFG::RoadSpaceComponent *)m_pPointer->m_Components.p[24].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::RoadSpaceComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::RoadSpaceComponent::_TypeUID);
        m_pComponent = (UFG::RoadSpaceComponent *)ComponentOfTypeHK;
      }
      else
      {
        m_pComponent = (UFG::RoadSpaceComponent *)m_pPointer->m_Components.p[24].m_pComponent;
      }
    }
    else
    {
      m_pComponent = 0i64;
    }
    if ( UFG::RoadSpaceComponent::IsAttachedToRoadNetwork(m_pComponent) )
      UFG::RoadSpaceComponent::DetachFromRoadNetwork(m_pComponent);
    if ( m_pComponent )
    {
      RoadWayFinder = UFG::WheeledVehicleNavigationData::GetRoadWayFinder(
                        UFG::WheeledVehicleManager::m_Instance->m_NavigationData,
                        &m_pComponent->mWayClient);
      UFG::WayFinder::Cancel(RoadWayFinder, &m_pComponent->mWayClient);
    }
    v10 = (UFG::SimObjectCVBase *)this->m_pActionContext->mSimObject.m_pPointer;
    if ( v10 )
    {
      v11 = v10->m_Flags;
      if ( (v11 & 0x4000) != 0 || v11 < 0 )
      {
        ComponentOfType = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v10);
      }
      else if ( (v11 & 0x2000) != 0 || (v11 & 0x1000) != 0 )
      {
        ComponentOfType = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      v10,
                                                      UFG::AiDriverComponent::_TypeUID);
      }
      else
      {
        ComponentOfType = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                                      v10,
                                                      UFG::AiDriverComponent::_TypeUID);
      }
      v5 = ComponentOfType;
    }
    p_m_pAIComponent = &this->m_pAIComponent;
    if ( this->m_pAIComponent.m_pPointer )
    {
      mPrev = p_m_pAIComponent->mPrev;
      mNext = this->m_pAIComponent.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_m_pAIComponent->mPrev = p_m_pAIComponent;
      this->m_pAIComponent.mNext = &this->m_pAIComponent;
    }
    this->m_pAIComponent.m_pPointer = v5;
    if ( v5 )
    {
      v16 = v5->m_SafePointerList.mNode.mPrev;
      v16->mNext = p_m_pAIComponent;
      p_m_pAIComponent->mPrev = v16;
      this->m_pAIComponent.mNext = &v5->m_SafePointerList.mNode;
      v5->m_SafePointerList.mNode.mPrev = p_m_pAIComponent;
    }
    UFG::AiDriverComponent::SetFollowOffset(
      (UFG::AiDriverComponent *)this->m_pAIComponent.m_pPointer,
      AnySide,
      (CarCombat::Position)BYTE4(m_Track[1].vfptr),
      *(float *)&m_Track[1].vfptr);
  }
}Side,
      (C

// File Line: 1102
// RVA: 0x667390
void __fastcall CarFormationDriveTask::CarFormationDriveTask(CarFormationDriveTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::AiDriverComponent> *p_m_pAIComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax

  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<CarFormationDriveTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&CarFormationDriveTask::`vftable;
  p_m_pAIComponent = &this->m_pAIComponent;
  this->m_pAIComponent.mPrev = &this->m_pAIComponent;
  this->m_pAIComponent.mNext = &this->m_pAIComponent;
  this->m_pAIComponent.m_pPointer = 0i64;
  this->m_pActionContext = 0i64;
  if ( this->m_pAIComponent.m_pPointer )
  {
    mPrev = p_m_pAIComponent->mPrev;
    mNext = p_m_pAIComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pAIComponent->mPrev = p_m_pAIComponent;
    p_m_pAIComponent->mNext = p_m_pAIComponent;
  }
  p_m_pAIComponent->m_pPointer = 0i64;
}

// File Line: 1111
// RVA: 0x671330
void __fastcall CarFormationDriveTask::Begin(CarFormationDriveTask *this, ActionContext *action_context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::SimComponent *v4; // rdi
  UFG::RoadSpaceComponent *m_pComponent; // rbx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::WayFinder *RoadWayFinder; // rax
  UFG::SimObjectCVBase *v9; // rcx
  __int16 v10; // dx
  UFG::AiDriverComponent *ComponentOfType; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AiDriverComponent> *p_m_pAIComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rax

  this->m_pActionContext = action_context;
  if ( action_context )
  {
    m_pPointer = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
    v4 = 0i64;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = (UFG::RoadSpaceComponent *)m_pPointer->m_Components.p[24].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::RoadSpaceComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::RoadSpaceComponent::_TypeUID);
        m_pComponent = (UFG::RoadSpaceComponent *)ComponentOfTypeHK;
      }
      else
      {
        m_pComponent = (UFG::RoadSpaceComponent *)m_pPointer->m_Components.p[24].m_pComponent;
      }
    }
    else
    {
      m_pComponent = 0i64;
    }
    if ( UFG::RoadSpaceComponent::IsAttachedToRoadNetwork(m_pComponent) )
      UFG::RoadSpaceComponent::DetachFromRoadNetwork(m_pComponent);
    if ( m_pComponent )
    {
      RoadWayFinder = UFG::WheeledVehicleNavigationData::GetRoadWayFinder(
                        UFG::WheeledVehicleManager::m_Instance->m_NavigationData,
                        &m_pComponent->mWayClient);
      UFG::WayFinder::Cancel(RoadWayFinder, &m_pComponent->mWayClient);
    }
    v9 = (UFG::SimObjectCVBase *)this->m_pActionContext->mSimObject.m_pPointer;
    if ( v9 )
    {
      v10 = v9->m_Flags;
      if ( (v10 & 0x4000) != 0 || v10 < 0 )
      {
        ComponentOfType = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v9);
      }
      else if ( (v10 & 0x2000) != 0 || (v10 & 0x1000) != 0 )
      {
        ComponentOfType = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      v9,
                                                      UFG::AiDriverComponent::_TypeUID);
      }
      else
      {
        ComponentOfType = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                                      v9,
                                                      UFG::AiDriverComponent::_TypeUID);
      }
      v4 = ComponentOfType;
    }
    p_m_pAIComponent = &this->m_pAIComponent;
    if ( this->m_pAIComponent.m_pPointer )
    {
      mPrev = p_m_pAIComponent->mPrev;
      mNext = this->m_pAIComponent.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_m_pAIComponent->mPrev = p_m_pAIComponent;
      this->m_pAIComponent.mNext = &this->m_pAIComponent;
    }
    this->m_pAIComponent.m_pPointer = v4;
    if ( v4 )
    {
      v15 = v4->m_SafePointerList.mNode.mPrev;
      v15->mNext = p_m_pAIComponent;
      p_m_pAIComponent->mPrev = v15;
      this->m_pAIComponent.mNext = &v4->m_SafePointerList.mNode;
      v4->m_SafePointerList.mNode.mPrev = p_m_pAIComponent;
    }
  }
}

// File Line: 1139
// RVA: 0x68FA00
char __fastcall CarFormationDriveTask::Update(CarFormationDriveTask *this, float timestep)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  UFG::AiDriverComponent *v6; // rcx

  m_pPointer = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[24].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::RoadSpaceComponent::_TypeUID);
      else
        m_pComponent = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::RoadSpaceComponent::_TypeUID);
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[24].m_pComponent;
    }
    if ( m_pComponent )
      m_pComponent[30].m_TypeUID |= 2u;
  }
  v6 = (UFG::AiDriverComponent *)this->m_pAIComponent.m_pPointer;
  if ( !v6 )
    return 0;
  UFG::AiDriverComponent::UpdateFollowingNavigation(v6, timestep);
  return 1;
}

// File Line: 1169
// RVA: 0x667810
void __fastcall CarOccupantAimTask::CarOccupantAimTask(CarOccupantAimTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pActiveAIEntityComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax

  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<CarOccupantAimTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&CarOccupantAimTask::`vftable;
  p_m_pActiveAIEntityComponent = &this->m_pActiveAIEntityComponent;
  this->m_pActiveAIEntityComponent.mPrev = &this->m_pActiveAIEntityComponent;
  this->m_pActiveAIEntityComponent.mNext = &this->m_pActiveAIEntityComponent;
  this->m_pActiveAIEntityComponent.m_pPointer = 0i64;
  if ( this->m_pActiveAIEntityComponent.m_pPointer )
  {
    mPrev = p_m_pActiveAIEntityComponent->mPrev;
    mNext = p_m_pActiveAIEntityComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pActiveAIEntityComponent->mPrev = p_m_pActiveAIEntityComponent;
    p_m_pActiveAIEntityComponent->mNext = p_m_pActiveAIEntityComponent;
  }
  p_m_pActiveAIEntityComponent->m_pPointer = 0i64;
}

// File Line: 1176
// RVA: 0x671A80
void __fastcall CarOccupantAimTask::Begin(CarOccupantAimTask *this, ActionContext *action_context)
{
  UFG::SimObjectCVBase *Target; // rax
  __int16 m_Flags; // r8
  UFG::ActiveAIEntityComponent *ComponentOfTypeHK; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pActiveAIEntityComponent; // rdx
  UFG::SimComponent *v7; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax

  Target = (UFG::SimObjectCVBase *)UFG::getTarget(action_context->mSimObject.m_pPointer, LOBYTE(this->m_Track[1].vfptr));
  if ( Target )
  {
    m_Flags = Target->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(Target);
    }
    else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            Target,
                                                            UFG::ActiveAIEntityComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                            Target,
                                                            UFG::ActiveAIEntityComponent::_TypeUID);
    }
    p_m_pActiveAIEntityComponent = &this->m_pActiveAIEntityComponent;
    v7 = ComponentOfTypeHK;
    if ( this->m_pActiveAIEntityComponent.m_pPointer )
    {
      mPrev = p_m_pActiveAIEntityComponent->mPrev;
      mNext = this->m_pActiveAIEntityComponent.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_m_pActiveAIEntityComponent->mPrev = p_m_pActiveAIEntityComponent;
      this->m_pActiveAIEntityComponent.mNext = &this->m_pActiveAIEntityComponent;
    }
    this->m_pActiveAIEntityComponent.m_pPointer = v7;
    if ( v7 )
    {
      v10 = v7->m_SafePointerList.mNode.mPrev;
      v10->mNext = p_m_pActiveAIEntityComponent;
      p_m_pActiveAIEntityComponent->mPrev = v10;
      this->m_pActiveAIEntityComponent.mNext = &v7->m_SafePointerList.mNode;
      v7->m_SafePointerList.mNode.mPrev = p_m_pActiveAIEntityComponent;
    }
  }
}

// File Line: 1191
// RVA: 0x690120
bool __fastcall CarOccupantAimTask::Update(CarOccupantAimTask *this, float timestep)
{
  UFG::SimComponent *m_pPointer; // rax
  UFG::SimObject *m_pSimObject; // rcx
  UFG::SimComponent *ComponentOfType; // rax
  Intention *v5; // rbx

  m_pPointer = this->m_pActiveAIEntityComponent.m_pPointer;
  if ( m_pPointer )
  {
    m_pSimObject = m_pPointer->m_pSimObject;
    if ( m_pSimObject )
    {
      ComponentOfType = UFG::SimObject::GetComponentOfType(
                          m_pSimObject,
                          UFG::AICharacterControllerBaseComponent::_TypeUID);
      if ( ComponentOfType )
      {
        v5 = (Intention *)&ComponentOfType[2];
        Intention::Set((Intention *)&ComponentOfType[2], gActionRequest_Focus.m_EnumValue, 0.0);
        Intention::Set(v5, gActionRequest_Aiming.m_EnumValue, 0.0);
      }
    }
    LOBYTE(m_pPointer) = 1;
  }
  return (char)m_pPointer;
}

// File Line: 1220
// RVA: 0x671BB0
void __fastcall CarOccupantShootTask::Begin(CarOccupantShootTask *this, ActionContext *action_context)
{
  UFG::SimObject *Target; // rax
  UFG::SimComponent *ComponentOfType; // rax
  Intention *v4; // rbx

  Target = UFG::getTarget(action_context->mSimObject.m_pPointer, LOBYTE(this->m_Track[1].vfptr));
  if ( Target )
  {
    ComponentOfType = UFG::SimObject::GetComponentOfType(Target, UFG::AICharacterControllerBaseComponent::_TypeUID);
    if ( ComponentOfType )
    {
      v4 = (Intention *)&ComponentOfType[2];
      Intention::Set((Intention *)&ComponentOfType[2], gActionRequest_Focus.m_EnumValue, 0.0);
      Intention::Set(v4, gActionRequest_Aiming.m_EnumValue, 0.0);
      Intention::Set(v4, gActionRequest_FireWeapon.m_EnumValue, 0.0);
    }
  }
}

// File Line: 1247
// RVA: 0x671B50
void __fastcall CarOccupantIntentionTask::Begin(CarOccupantIntentionTask *this, ActionContext *action_context)
{
  UFG::SimObject *Target; // rax
  UFG::SimComponent *ComponentOfType; // rax

  Target = UFG::getTarget(action_context->mSimObject.m_pPointer, LOBYTE(this->m_Track[1].vfptr));
  if ( Target )
  {
    ComponentOfType = UFG::SimObject::GetComponentOfType(Target, UFG::AICharacterControllerBaseComponent::_TypeUID);
    if ( ComponentOfType )
      Intention::Set((Intention *)&ComponentOfType[2], HIDWORD(this->m_Track[1].vfptr), 0.0);
  }
}

// File Line: 1280
// RVA: 0x690190
char __fastcall CarOccupantsActionTask::Update(CarOccupantsActionTask *this, float timestep)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::VehicleOccupantComponent *m_pComponent; // rsi
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList> **p_mNext; // r14
  int v8; // ecx
  __int64 v9; // rax
  UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *p_m_BoundComponentHandles; // rbx
  unsigned int i; // edi
  UFG::SimObject *v13; // rcx
  int v14; // r8d
  int v15; // edx
  __int64 v16; // rax
  __int64 j; // rcx
  signed int v18; // edx
  __int64 k; // rcx
  int m; // ecx
  UFG::SimComponent *ComponentOfType; // rax

  m_pPointer = (UFG::SimObjectGame *)this->mpActionContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 1;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
    goto LABEL_8;
  if ( m_Flags < 0 )
  {
    m_pComponent = (UFG::VehicleOccupantComponent *)m_pPointer->m_Components.p[30].m_pComponent;
    goto LABEL_11;
  }
  if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
LABEL_8:
    ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::VehicleOccupantComponent::_TypeUID);
  else
    ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::VehicleOccupantComponent::_TypeUID);
  m_pComponent = (UFG::VehicleOccupantComponent *)ComponentOfTypeHK;
LABEL_11:
  if ( !m_pComponent )
    return 1;
  p_mNext = &m_pComponent->mPassengers.mNode.mNext;
  v8 = 0;
  v9 = (__int64)&m_pComponent->mPassengers.mNode.mNext[-4];
  p_m_BoundComponentHandles = &m_pComponent->m_BoundComponentHandles;
  if ( m_pComponent->mpDriver.m_pPointer )
  {
    for ( ;
          (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)v9 != p_m_BoundComponentHandles;
          v9 = *(_QWORD *)(v9 + 72) - 64i64 )
    {
      ++v8;
    }
    ++v8;
  }
  else
  {
    for ( ;
          (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)v9 != p_m_BoundComponentHandles;
          v9 = *(_QWORD *)(v9 + 72) - 64i64 )
    {
      ++v8;
    }
  }
  if ( !v8 )
    return 0;
  for ( i = 0; i < (unsigned int)UFG::VehicleOccupantComponent::GetNumberOfOccupants(m_pComponent); ++i )
  {
    v13 = m_pComponent->mpDriver.m_pPointer;
    if ( v13 )
    {
      if ( !i )
        goto LABEL_37;
      v14 = 0;
      v15 = i - 1;
      v16 = (__int64)&(*p_mNext)[-4];
      for ( j = v16;
            (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)j != p_m_BoundComponentHandles;
            j = *(_QWORD *)(j + 72) - 64i64 )
      {
        ++v14;
      }
      if ( v15 >= v14 )
        continue;
      for ( ; v15 > 0; v16 = *(_QWORD *)(v16 + 72) - 64i64 )
      {
        if ( (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)v16 == p_m_BoundComponentHandles )
          break;
        --v15;
      }
    }
    else
    {
      v18 = 0;
      v16 = (__int64)&(*p_mNext)[-4];
      for ( k = v16;
            (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)k != p_m_BoundComponentHandles;
            k = *(_QWORD *)(k + 72) - 64i64 )
      {
        ++v18;
      }
      if ( (int)i >= v18 )
        continue;
      for ( m = i; m > 0; v16 = *(_QWORD *)(v16 + 72) - 64i64 )
      {
        if ( (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)v16 == p_m_BoundComponentHandles )
          break;
        --m;
      }
    }
    v13 = *(UFG::SimObject **)(v16 + 40);
LABEL_37:
    if ( v13 )
    {
      ComponentOfType = UFG::SimObject::GetComponentOfType(v13, UFG::AICharacterControllerBaseComponent::_TypeUID);
      if ( ComponentOfType )
        Intention::Set((Intention *)&ComponentOfType[2], (int)this->m_Track[1].vfptr, 0.0);
    }
  }
  return 0;
}

// File Line: 1318
// RVA: 0x677C60
void __fastcall CarOccupantsActionTask::End(CarOccupantsActionTask *this)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::AiDriverComponent *v3; // rax
  unsigned int v4; // edx
  UFG::AiDriverComponent *ComponentOfTypeHK; // rax
  bool v6; // zf
  UFG::AiDriverComponent *ComponentOfType; // rax

  m_pPointer = (UFG::SimObjectCVBase *)this->mpActionContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
  {
    UFG::AiDriverComponent::SetDrivingMode(0i64, 0);
    return;
  }
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
  {
    v3 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(m_pPointer);
    UFG::AiDriverComponent::SetDrivingMode(v3, 0);
    return;
  }
  if ( (m_Flags & 0x2000) != 0 )
  {
    v4 = UFG::AiDriverComponent::_TypeUID;
LABEL_8:
    ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, v4);
    UFG::AiDriverComponent::SetDrivingMode(ComponentOfTypeHK, 0);
    return;
  }
  v6 = (m_Flags & 0x1000) == 0;
  v4 = UFG::AiDriverComponent::_TypeUID;
  if ( !v6 )
    goto LABEL_8;
  ComponentOfType = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                                m_pPointer,
                                                UFG::AiDriverComponent::_TypeUID);
  UFG::AiDriverComponent::SetDrivingMode(ComponentOfType, 0);
}

// File Line: 1329
// RVA: 0x672DF0
void __fastcall SetCarModeTask::Begin(SetCarModeTask *this, ActionContext *action_context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::AiDriverComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(m_pPointer);
    }
    else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      m_pPointer,
                                                      UFG::AiDriverComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                                      m_pPointer,
                                                      UFG::AiDriverComponent::_TypeUID);
    }
    if ( ComponentOfTypeHK )
      UFG::AiDriverComponent::SetDrivingMode(ComponentOfTypeHK, (unsigned int)this->m_Track[1].vfptr);
  }
}

// File Line: 1342
// RVA: 0x672E80
void __fastcall VehicleAudioEventTask::Begin(VehicleAudioEventTask *this, ActionContext *action_context)
{
  UFG::SimObjectVehicle *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::VehicleAudioComponent *ComponentOfTypeHK; // rax
  hkgpIndexedMeshDefinitions::Edge *v6; // rdx
  hkgpIndexedMesh::EdgeBarrier *v7; // rcx
  UFG::VehicleAudioComponent *v8; // rbx
  float v9; // xmm0_4
  float *m_Track; // rax
  float v11; // xmm7_4
  float v12; // xmm8_4
  float v13; // xmm6_4
  UFG::DriverReactions *m_driverReaction; // rdi
  unsigned int m_numReactions; // eax
  char v16; // al
  char v17; // al

  m_pPointer = (UFG::SimObjectVehicle *)action_context->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
    goto LABEL_8;
  if ( m_Flags < 0 )
  {
    ComponentOfTypeHK = UFG::SimObjectVehicle::GetComponent<UFG::VehicleAudioComponent>(m_pPointer);
    goto LABEL_10;
  }
  if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
LABEL_8:
    ComponentOfTypeHK = (UFG::VehicleAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        m_pPointer,
                                                        UFG::VehicleAudioComponent::_TypeUID);
  else
    ComponentOfTypeHK = (UFG::VehicleAudioComponent *)UFG::SimObject::GetComponentOfType(
                                                        m_pPointer,
                                                        UFG::VehicleAudioComponent::_TypeUID);
LABEL_10:
  v8 = ComponentOfTypeHK;
  if ( ComponentOfTypeHK )
  {
    if ( !LODWORD(this->m_Track[1].vfptr) )
    {
      v9 = UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed);
      m_Track = (float *)this->m_Track;
      if ( v9 < m_Track[15] )
      {
        v11 = m_Track[16];
        v12 = m_Track[17];
        v13 = UFG::qRandom(v11, (unsigned int *)&UFG::qDefaultSeed);
        if ( v13 <= v12 )
          v13 = v12;
        if ( v13 >= v11 )
          v13 = v11;
        m_driverReaction = v8->m_driverReaction;
        if ( m_driverReaction )
        {
          m_numReactions = m_driverReaction->m_numReactions;
          if ( m_numReactions <= UFG::DriverReactions::sm_NumReactions )
          {
            m_driverReaction->m_reactionCooldownTimer = 0.0;
            m_driverReaction->m_numReactions = m_numReactions + 1;
            if ( UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed) >= 0.33000001 )
              UFG::VehicleAudioComponent::HonkAmbientHorn(m_driverReaction->m_pVehAudComponent, v13);
            else
              UFG::DriverReactions::YellReactionBase(m_driverReaction, eVocalDriverReactionType_BadDriver);
          }
        }
      }
    }
    if ( LODWORD(this->m_Track[1].vfptr) == 3
      && !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(v7, v6) )
    {
      v16 = *((_BYTE *)v8 + 636);
      if ( (v16 & 2) == 0 )
        *((_BYTE *)v8 + 636) = v16 | 2;
    }
    if ( LODWORD(this->m_Track[1].vfptr) == 4
      && !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(v7, v6) )
    {
      v17 = *((_BYTE *)v8 + 636);
      if ( (v17 & 2) != 0 )
        *((_BYTE *)v8 + 636) = v17 & 0xFD;
    }
    if ( LODWORD(this->m_Track[1].vfptr) == 1 )
      UFG::AudioEntity::CreateAndPlayEvent(&v8->UFG::AudioEntity, 0x2861EDD7u, 0i64, 0, 0i64);
  }
}

// File Line: 1381
// RVA: 0x673070
void __fastcall VehicleEffectTask::Begin(VehicleEffectTask *this, ActionContext *action_context)
{
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::VehicleEffectsComponent *mRenderComponent; // rbx
  UFG::SimComponent *m_pSimComponent; // rcx

  ComponentOfTypeHK = 0i64;
  this->mElapsedTime = 0.0;
  m_pPointer = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
LABEL_8:
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::VehicleEffectsComponent::_TypeUID);
      goto LABEL_10;
    }
    if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) == 0 && (m_Flags & 0x1000) == 0 )
      {
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::VehicleEffectsComponent::_TypeUID);
        goto LABEL_10;
      }
      goto LABEL_8;
    }
    ComponentOfTypeHK = m_pPointer->m_Components.p[32].m_pComponent;
  }
LABEL_10:
  this->mRenderComponent = (UFG::VehicleEffectsComponent *)ComponentOfTypeHK;
  if ( ComponentOfTypeHK )
  {
    ComponentOfTypeHK[29].m_NameUID |= 0x10u;
    if ( !HIDWORD(this->m_Track[1].vfptr) )
    {
      mRenderComponent = this->mRenderComponent;
      UFG::VehicleEffectsComponent::TurnOffEffect_New(mRenderComponent, FX_DAYTIME);
      m_pSimComponent = mRenderComponent->mVehicleDriverComponent.m_pSimComponent;
      if ( m_pSimComponent
        && ((unsigned __int8 (__fastcall *)(UFG::SimComponent *))m_pSimComponent->vfptr[15].__vecDelDtor)(m_pSimComponent) )
      {
        UFG::VehicleEffectsComponent::TurnOnLightEffects(mRenderComponent, FX_PLAYERHEADLIGHTS);
        UFG::VehicleEffectsComponent::TurnOnLightEffects(mRenderComponent, FX_NIGHTTIME);
        UFG::VehicleEffectsComponent::TurnOnLightEffects(mRenderComponent, FX_PLAYERHEADLIGHTFLARES);
      }
      else
      {
        UFG::VehicleEffectsComponent::TurnOnLightEffects(mRenderComponent, FX_TRAFFICHEADLIGHTS);
        UFG::VehicleEffectsComponent::TurnOnLightEffects(mRenderComponent, FX_NIGHTTIME);
        UFG::VehicleEffectsComponent::TurnOnLightEffects(mRenderComponent, FX_TRAFFICHEADLIGHTFLARES);
      }
    }
  }
}

// File Line: 1398
// RVA: 0x6946D0
bool __fastcall VehicleEffectTask::Update(VehicleEffectTask *this, float timestep)
{
  float mElapsedTime; // xmm0_4
  bool result; // al

  mElapsedTime = this->mElapsedTime;
  if ( mElapsedTime > *(float *)&this->m_Track[1].vfptr )
    return 0;
  result = 1;
  this->mElapsedTime = mElapsedTime + timestep;
  return result;
}

// File Line: 1416
// RVA: 0x677D40
void __fastcall VehicleEffectTask::End(VehicleEffectTask *this)
{
  UFG::VehicleEffectsComponent *mRenderComponent; // rax

  mRenderComponent = this->mRenderComponent;
  if ( mRenderComponent )
  {
    *((_DWORD *)mRenderComponent + 471) &= ~0x10u;
    if ( !HIDWORD(this->m_Track[1].vfptr) )
      UFG::VehicleEffectsComponent::TurnOffHeadlights(this->mRenderComponent);
  }
}

// File Line: 1430
// RVA: 0x673350
void __fastcall VehicleQueueHeadlightFlashesTask::Begin(
        VehicleQueueHeadlightFlashesTask *this,
        ActionContext *action_context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::SimComponent *m_pComponent; // r8
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  ITrack *m_Track; // rax
  int vfptr_high; // edx
  float v9; // xmm2_4
  UFG::VehicleEffectsComponent *mRenderComponent; // rcx

  m_pPointer = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  if ( !m_pPointer )
  {
    m_pComponent = 0i64;
    goto LABEL_12;
  }
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
    goto LABEL_9;
  if ( m_Flags < 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[32].m_pComponent;
    goto LABEL_12;
  }
  if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
LABEL_9:
    ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::VehicleEffectsComponent::_TypeUID);
  else
    ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::VehicleEffectsComponent::_TypeUID);
  m_pComponent = ComponentOfTypeHK;
LABEL_12:
  this->mRenderComponent = (UFG::VehicleEffectsComponent *)m_pComponent;
  if ( m_pComponent )
  {
    m_Track = this->m_Track;
    vfptr_high = HIDWORD(m_Track[1].vfptr);
    v9 = *(float *)&m_Track[1].vfptr;
    this->mTaskDuration = (float)(v9 * 2.0) * (float)vfptr_high;
    m_pComponent[29].m_NameUID |= 0x10u;
    mRenderComponent = this->mRenderComponent;
    mRenderComponent->mNumQueuedHeadlightChanges = 2 * vfptr_high;
    mRenderComponent->mHeadlightFlashesTimer = 0.0;
    mRenderComponent->mHeadlightFlashesLength = v9;
  }
}

// File Line: 1447
// RVA: 0x694740
bool __fastcall VehicleQueueHeadlightFlashesTask::Update(VehicleQueueHeadlightFlashesTask *this, float timestep)
{
  float mElapsedTime; // xmm0_4
  bool result; // al

  mElapsedTime = this->mElapsedTime;
  if ( mElapsedTime > this->mTaskDuration )
    return 0;
  result = 1;
  this->mElapsedTime = mElapsedTime + timestep;
  return result;
}

// File Line: 1464
// RVA: 0x677D70
void __fastcall VehicleQueueHeadlightFlashesTask::End(VehicleQueueHeadlightFlashesTask *this)
{
  UFG::VehicleEffectsComponent *mRenderComponent; // rax

  mRenderComponent = this->mRenderComponent;
  if ( mRenderComponent )
    *((_DWORD *)mRenderComponent + 471) &= ~0x10u;
}

// File Line: 1475
// RVA: 0x673190
void __fastcall VehicleEnableTemporaryPassTask::Begin(
        VehicleEnableTemporaryPassTask *this,
        ActionContext *action_context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::AiDriverComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(m_pPointer);
    }
    else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      m_pPointer,
                                                      UFG::AiDriverComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                                      m_pPointer,
                                                      UFG::AiDriverComponent::_TypeUID);
    }
    if ( ComponentOfTypeHK )
      UFG::AiDriverComponent::EnableTemporaryPassing(ComponentOfTypeHK);
  }
}

// File Line: 1486
// RVA: 0x673210
void __fastcall VehicleOnDeadDriverStopTask::Begin(VehicleOnDeadDriverStopTask *this, ActionContext *actionContext)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::AiDriverComponent *v5; // rax
  UFG::AiDriverComponent *v6; // rbx
  UFG::SimObjectGame *v7; // rcx
  __int16 v8; // dx
  UFG::RoadSpaceComponent *m_pComponent; // rbx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectCVBase *)actionContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(m_pPointer);
    else
      v5 = (UFG::AiDriverComponent *)((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                    ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                        m_pPointer,
                                        UFG::AiDriverComponent::_TypeUID)
                                    : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::AiDriverComponent::_TypeUID));
    v6 = v5;
    if ( v5 )
    {
      if ( ((unsigned __int8 (__fastcall *)(UFG::AiDriverComponent *))v5->UFG::VehicleDriverInterface::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[16].__vecDelDtor)(v5) )
        v6->m_IsAmbient = 0;
    }
  }
  v7 = (UFG::SimObjectGame *)actionContext->mSimObject.m_pPointer;
  if ( v7 )
  {
    v8 = v7->m_Flags;
    if ( (v8 & 0x4000) != 0 )
    {
      m_pComponent = (UFG::RoadSpaceComponent *)v7->m_Components.p[24].m_pComponent;
    }
    else if ( v8 >= 0 )
    {
      if ( (v8 & 0x2000) != 0 || (v8 & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RoadSpaceComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v7, UFG::RoadSpaceComponent::_TypeUID);
      m_pComponent = (UFG::RoadSpaceComponent *)ComponentOfTypeHK;
    }
    else
    {
      m_pComponent = (UFG::RoadSpaceComponent *)v7->m_Components.p[24].m_pComponent;
    }
    if ( m_pComponent )
    {
      if ( UFG::RoadSpaceComponent::IsAttachedToRoadNetwork(m_pComponent) )
        UFG::RoadSpaceComponent::DetachFromRoadNetwork(m_pComponent);
    }
  }
}

// File Line: 1513
// RVA: 0x157B510
__int64 dynamic_initializer_for__CarStopTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CarStopTrack", 0xFFFFFFFF);
  CarStopTrack::sClassNameUID = result;
  return result;
}

// File Line: 1526
// RVA: 0x157B4F0
__int64 dynamic_initializer_for__CarStopAtTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CarStopAtTrack", 0xFFFFFFFF);
  CarStopAtTrack::sClassNameUID = result;
  return result;
}

// File Line: 1539
// RVA: 0x157B4D0
__int64 dynamic_initializer_for__CarStopAtStimulusTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CarStopAtStimulusTrack", 0xFFFFFFFF);
  CarStopAtStimulusTrack::sClassNameUID = result;
  return result;
}

// File Line: 1554
// RVA: 0x157B530
__int64 dynamic_initializer_for__CarWaitTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CarWaitTrack", 0xFFFFFFFF);
  CarWaitTrack::sClassNameUID = result;
  return result;
}

// File Line: 1569
// RVA: 0x157B470
__int64 dynamic_initializer_for__CarRaceTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CarRaceTrack", 0xFFFFFFFF);
  CarRaceTrack::sClassNameUID = result;
  return result;
}

// File Line: 1583
// RVA: 0x157B550
__int64 dynamic_initializer_for__CarWanderTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CarWanderTrack", 0xFFFFFFFF);
  CarWanderTrack::sClassNameUID = result;
  return result;
}

// File Line: 1596
// RVA: 0x157B150
__int64 dynamic_initializer_for__CarFollowTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CarFollowTrack", 0xFFFFFFFF);
  CarFollowTrack::sClassNameUID = result;
  return result;
}

// File Line: 1609
// RVA: 0x157B130
__int64 dynamic_initializer_for__CarEscortTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CarEscortTrack", 0xFFFFFFFF);
  CarEscortTrack::sClassNameUID = result;
  return result;
}

// File Line: 1622
// RVA: 0x157B2B0
__int64 dynamic_initializer_for__CarGoToTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CarGoToTrack", 0xFFFFFFFF);
  CarGoToTrack::sClassNameUID = result;
  return result;
}

// File Line: 1635
// RVA: 0x157B350
__int64 dynamic_initializer_for__CarNoDestinationTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CarNoDestinationTrack", 0xFFFFFFFF);
  CarNoDestinationTrack::sClassNameUID = result;
  return result;
}

// File Line: 1649
// RVA: 0x157B0B0
__int64 dynamic_initializer_for__CarAttackTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CarAttackTrack", 0xFFFFFFFF);
  CarAttackTrack::sClassNameUID = result;
  return result;
}

// File Line: 1659
// RVA: 0x667160
void __fastcall CarAttackTrack::CarAttackTrack(CarAttackTrack *this)
{
  ITrack::ITrack(this, CarAttackTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<CarAttackTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&CarAttackTrack::`vftable;
  this->mAttackType.mValue = 0;
  *(_QWORD *)&this->mDuration = 0i64;
}

// File Line: 1676
// RVA: 0x157B1B0
__int64 dynamic_initializer_for__CarFormationAttackTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CarFormationAttackTrack", 0xFFFFFFFF);
  CarFormationAttackTrack::sClassNameUID = result;
  return result;
}

// File Line: 1686
// RVA: 0x667300
void __fastcall CarFormationAttackTrack::CarFormationAttackTrack(CarFormationAttackTrack *this)
{
  ITrack::ITrack(this, CarFormationAttackTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<CarFormationAttackTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&CarFormationAttackTrack::`vftable;
  this->mAttackType.mValue = 0;
  *(_QWORD *)&this->mDuration = 0i64;
}

// File Line: 1702
// RVA: 0x157B290
__int64 dynamic_initializer_for__CarFormationTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CarFormationTrack", 0xFFFFFFFF);
  CarFormationTrack::sClassNameUID = result;
  return result;
}

// File Line: 1713
// RVA: 0x667570
void __fastcall CarFormationTrack::CarFormationTrack(CarFormationTrack *this)
{
  ITrack::ITrack(this, CarFormationTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<CarFormationTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&CarFormationTrack::`vftable;
  *(_DWORD *)this->mPosition = 0;
  *(_WORD *)&this->mPosition[4] = 0;
  this->mPosition[6] = 0;
}

// File Line: 1731
// RVA: 0x157B450
__int64 dynamic_initializer_for__CarOffsetDriveTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CarOffsetDriveTrack", 0xFFFFFFFF);
  CarOffsetDriveTrack::sClassNameUID = result;
  return result;
}

// File Line: 1743
// RVA: 0x6679B0
void __fastcall CarOffsetDriveTrack::CarOffsetDriveTrack(CarOffsetDriveTrack *this)
{
  ITrack::ITrack(this, CarOffsetDriveTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<CarOffsetDriveTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&CarOffsetDriveTrack::`vftable;
  this->mTolerance = 0.0;
  *(_WORD *)&this->mPosition.mValue = 768;
}

// File Line: 1760
// RVA: 0x157B1F0
__int64 dynamic_initializer_for__CarFormationDriveTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CarFormationDriveTrack", 0xFFFFFFFF);
  CarFormationDriveTrack::sClassNameUID = result;
  return result;
}

// File Line: 1768
// RVA: 0x667410
void __fastcall CarFormationDriveTrack::CarFormationDriveTrack(CarFormationDriveTrack *this)
{
  ITrack::ITrack(this, CarFormationDriveTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<CarFormationDriveTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&CarFormationDriveTrack::`vftable;
  this->mTolerance = 0.0;
}

// File Line: 1782
// RVA: 0x157B370
__int64 dynamic_initializer_for__CarOccupantAimTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CarOccupantAimTrack", 0xFFFFFFFF);
  CarOccupantAimTrack::sClassNameUID = result;
  return result;
}

// File Line: 1799
// RVA: 0x157B3F0
__int64 dynamic_initializer_for__CarOccupantShootTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CarOccupantShootTrack", 0xFFFFFFFF);
  CarOccupantShootTrack::sClassNameUID = result;
  return result;
}

// File Line: 1819
// RVA: 0x667890
void __fastcall CarOccupantIntentionTrack::CarOccupantIntentionTrack(CarOccupantIntentionTrack *this)
{
  ITrack::ITrack(this, CarOccupantIntentionTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<CarOccupantIntentionTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&CarOccupantIntentionTrack::`vftable;
  this->m_eTargetType.mValue = 4;
  this->m_ActionRequest = gActionRequest_Action.m_EnumValue;
}

// File Line: 1822
// RVA: 0x157B3D0
__int64 dynamic_initializer_for__CarOccupantIntentionTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CarOccupantIntentionTrack", 0xFFFFFFFF);
  CarOccupantIntentionTrack::sClassNameUID = result;
  return result;
}

// File Line: 1843
// RVA: 0x6678E0
void __fastcall CarOccupantsActionTrack::CarOccupantsActionTrack(CarOccupantsActionTrack *this)
{
  ITrack::ITrack(this, CarOccupantsActionTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<CarOccupantsActionTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&CarOccupantsActionTrack::`vftable;
  this->m_ActionRequest = gActionRequest_Action.m_EnumValue;
}

// File Line: 1846
// RVA: 0x157B430
__int64 dynamic_initializer_for__CarOccupantsActionTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CarOccupantsActionTrack", 0xFFFFFFFF);
  CarOccupantsActionTrack::sClassNameUID = result;
  return result;
}

// File Line: 1864
// RVA: 0x157B590
__int64 dynamic_initializer_for__SetCarModeTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("SetCarModeTrack", 0xFFFFFFFF);
  SetCarModeTrack::sClassNameUID = result;
  return result;
}

// File Line: 1880
// RVA: 0x157B5D0
__int64 dynamic_initializer_for__VehicleAudioEventTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleAudioEventTrack", 0xFFFFFFFF);
  VehicleAudioEventTrack::sClassNameUID = result;
  return result;
}

// File Line: 1899
// RVA: 0x157B5F0
__int64 dynamic_initializer_for__VehicleEffectTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleEffectTrack", 0xFFFFFFFF);
  VehicleEffectTrack::sClassNameUID = result;
  return result;
}

// File Line: 1914
// RVA: 0x157B6F0
__int64 dynamic_initializer_for__VehicleQueueHeadlightFlashesTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleQueueHeadlightFlashesTrack", 0xFFFFFFFF);
  VehicleQueueHeadlightFlashesTrack::sClassNameUID = result;
  return result;
}

// File Line: 1929
// RVA: 0x157B6D0
__int64 dynamic_initializer_for__VehicleOnDeadDriverStopTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleOnDeadDriverStopTrack", 0xFFFFFFFF);
  VehicleOnDeadDriverStopTrack::sClassNameUID = result;
  return result;
}

// File Line: 1941
// RVA: 0x157B610
__int64 dynamic_initializer_for__VehicleEnableTemporaryPassTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleEnableTemporaryPassTrack", 0xFFFFFFFF);
  VehicleEnableTemporaryPassTrack::sClassNameUID = result;
  return result;
}

