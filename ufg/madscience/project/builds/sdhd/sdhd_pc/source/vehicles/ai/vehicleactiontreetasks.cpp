// File Line: 58
// RVA: 0x667B90
void __fastcall CarStopTask::CarStopTask(CarStopTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AiDriverComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<CarStopTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&CarStopTask::`vftable;
  v2 = &this->m_pAIComponent;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  this->m_pAIComponent.m_pPointer = 0i64;
  this->m_pActionContext = 0i64;
  if ( this->m_pAIComponent.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  }
  v2->m_pPointer = 0i64;
}

// File Line: 66
// RVA: 0x6727F0
void __fastcall CarStopTask::Begin(CarStopTask *this, ActionContext *action_context)
{
  CarStopTask *v2; // rsi
  UFG::SimObjectCVBase *v3; // rcx
  UFG::AiDriverComponent *v4; // rdi
  UFG::AiDriverComponent *v5; // rdx
  unsigned __int16 v6; // dx
  UFG::AiDriverComponent *v7; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AiDriverComponent> *v8; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::SimObjectGame *v12; // rcx
  unsigned __int16 v13; // dx
  UFG::CharacterOccupantComponent *v14; // rax
  UFG::SimObjectCVBase *v15; // rax
  unsigned __int16 v16; // cx
  UFG::AiDriverComponent *v17; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rax
  UFG::AiDriverComponent *v21; // rcx

  v2 = this;
  this->m_pActionContext = action_context;
  if ( action_context )
  {
    v3 = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
    v4 = 0i64;
    if ( v3 )
    {
      v6 = v3->m_Flags;
      if ( (v6 >> 14) & 1 )
      {
        v7 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v3);
      }
      else if ( (v6 & 0x8000u) == 0 )
      {
        if ( (v6 >> 13) & 1 )
        {
          v7 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           (UFG::SimObjectGame *)&v3->vfptr,
                                           UFG::AiDriverComponent::_TypeUID);
        }
        else if ( (v6 >> 12) & 1 )
        {
          v7 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           (UFG::SimObjectGame *)&v3->vfptr,
                                           UFG::AiDriverComponent::_TypeUID);
        }
        else
        {
          v7 = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                           (UFG::SimObject *)&v3->vfptr,
                                           UFG::AiDriverComponent::_TypeUID);
        }
      }
      else
      {
        v7 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v3);
      }
      v5 = v7;
    }
    else
    {
      v5 = 0i64;
    }
    v8 = &v2->m_pAIComponent;
    if ( v2->m_pAIComponent.m_pPointer )
    {
      v9 = v8->mPrev;
      v10 = v2->m_pAIComponent.mNext;
      v9->mNext = v10;
      v10->mPrev = v9;
      v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
      v2->m_pAIComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pAIComponent.mPrev;
    }
    v2->m_pAIComponent.m_pPointer = (UFG::SimComponent *)&v5->vfptr;
    if ( v5 )
    {
      v11 = v5->m_SafePointerList.mNode.mPrev;
      v11->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
      v8->mPrev = v11;
      v2->m_pAIComponent.mNext = &v5->m_SafePointerList.mNode;
      v5->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
    }
    if ( !v2->m_pAIComponent.m_pPointer )
    {
      v12 = (UFG::SimObjectGame *)v2->m_pActionContext->mSimObject.m_pPointer;
      if ( v12 )
      {
        v13 = v12->m_Flags;
        if ( (v13 >> 14) & 1 )
        {
          v14 = (UFG::CharacterOccupantComponent *)v12->m_Components.p[44].m_pComponent;
        }
        else if ( (v13 & 0x8000u) == 0 )
        {
          if ( (v13 >> 13) & 1 )
            v14 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                       v12,
                                                       UFG::CharacterOccupantComponent::_TypeUID);
          else
            v14 = (UFG::CharacterOccupantComponent *)((v13 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                          v12,
                                                                          UFG::CharacterOccupantComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v12->vfptr, UFG::CharacterOccupantComponent::_TypeUID));
        }
        else
        {
          v14 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                     v12,
                                                     UFG::CharacterOccupantComponent::_TypeUID);
        }
        if ( v14 )
        {
          v15 = (UFG::SimObjectCVBase *)UFG::CharacterOccupantComponent::GetCurrentVehicle(v14);
          if ( v15 )
          {
            v16 = v15->m_Flags;
            if ( (v16 >> 14) & 1 )
            {
              v17 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v15);
            }
            else if ( (v16 & 0x8000u) == 0 )
            {
              if ( (v16 >> 13) & 1 )
              {
                v17 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  (UFG::SimObjectGame *)&v15->vfptr,
                                                  UFG::AiDriverComponent::_TypeUID);
              }
              else if ( (v16 >> 12) & 1 )
              {
                v17 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  (UFG::SimObjectGame *)&v15->vfptr,
                                                  UFG::AiDriverComponent::_TypeUID);
              }
              else
              {
                v17 = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                                  (UFG::SimObject *)&v15->vfptr,
                                                  UFG::AiDriverComponent::_TypeUID);
              }
            }
            else
            {
              v17 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v15);
            }
            v4 = v17;
          }
          if ( v2->m_pAIComponent.m_pPointer )
          {
            v18 = v8->mPrev;
            v19 = v2->m_pAIComponent.mNext;
            v18->mNext = v19;
            v19->mPrev = v18;
            v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
            v2->m_pAIComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pAIComponent.mPrev;
          }
          v2->m_pAIComponent.m_pPointer = (UFG::SimComponent *)&v4->vfptr;
          if ( v4 )
          {
            v20 = v4->m_SafePointerList.mNode.mPrev;
            v20->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
            v8->mPrev = v20;
            v2->m_pAIComponent.mNext = &v4->m_SafePointerList.mNode;
            v4->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
          }
        }
      }
    }
    v21 = (UFG::AiDriverComponent *)v2->m_pAIComponent.m_pPointer;
    if ( v21 )
    {
      v2->m_PreviousDrivingMode = v21->m_DrivingMode;
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
  CarWanderTask *v2; // rbx
  UFG::SimObjectCVBase *v3; // rcx
  UFG::AiDriverComponent *v4; // r8
  unsigned __int16 v5; // dx
  UFG::AiDriverComponent *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AiDriverComponent> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::AiDriverComponent *v11; // rcx
  UFG::SimObjectGame *v12; // rcx
  UFG::RoadSpaceComponent *v13; // rdi
  unsigned __int16 v14; // dx
  UFG::SimComponent *v15; // rax
  UFG::SimObject *v16; // rcx
  UFG::TransformNodeComponent *v17; // rbx
  UFG::RoadNetworkResource *v18; // rbp
  unsigned int v19; // esi
  UFG::RoadNetworkIntersection *v20; // rbx
  UFG::RoadNetworkLocation *v21; // rax

  v2 = this;
  this->m_pActionContext = action_context;
  if ( action_context )
  {
    v3 = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
    if ( v3 )
    {
      v5 = v3->m_Flags;
      if ( (v5 >> 14) & 1 )
      {
        v6 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v3);
      }
      else if ( (v5 & 0x8000u) == 0 )
      {
        if ( (v5 >> 13) & 1 )
        {
          v6 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           (UFG::SimObjectGame *)&v3->vfptr,
                                           UFG::AiDriverComponent::_TypeUID);
        }
        else if ( (v5 >> 12) & 1 )
        {
          v6 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           (UFG::SimObjectGame *)&v3->vfptr,
                                           UFG::AiDriverComponent::_TypeUID);
        }
        else
        {
          v6 = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                           (UFG::SimObject *)&v3->vfptr,
                                           UFG::AiDriverComponent::_TypeUID);
        }
      }
      else
      {
        v6 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v3);
      }
      v4 = v6;
    }
    else
    {
      v4 = 0i64;
    }
    v7 = &v2->m_pAIComponent;
    if ( v2->m_pAIComponent.m_pPointer )
    {
      v8 = v7->mPrev;
      v9 = v2->m_pAIComponent.mNext;
      v8->mNext = v9;
      v9->mPrev = v8;
      v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
      v2->m_pAIComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pAIComponent.mPrev;
    }
    v2->m_pAIComponent.m_pPointer = (UFG::SimComponent *)&v4->vfptr;
    if ( v4 )
    {
      v10 = v4->m_SafePointerList.mNode.mPrev;
      v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
      v7->mPrev = v10;
      v2->m_pAIComponent.mNext = &v4->m_SafePointerList.mNode;
      v4->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    }
    v11 = (UFG::AiDriverComponent *)v2->m_pAIComponent.m_pPointer;
    if ( v11->m_bIsParked )
      UFG::AiDriverComponent::SetParked(v11, 0);
    v12 = (UFG::SimObjectGame *)v2->m_pActionContext->mSimObject.m_pPointer;
    if ( v12 )
    {
      v14 = v12->m_Flags;
      if ( (v14 >> 14) & 1 )
      {
        v13 = (UFG::RoadSpaceComponent *)v12->m_Components.p[24].m_pComponent;
      }
      else if ( (v14 & 0x8000u) == 0 )
      {
        if ( (v14 >> 13) & 1 )
        {
          v15 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::RoadSpaceComponent::_TypeUID);
        }
        else if ( (v14 >> 12) & 1 )
        {
          v15 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::RoadSpaceComponent::_TypeUID);
        }
        else
        {
          v15 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v12->vfptr, UFG::RoadSpaceComponent::_TypeUID);
        }
        v13 = (UFG::RoadSpaceComponent *)v15;
      }
      else
      {
        v13 = (UFG::RoadSpaceComponent *)v12->m_Components.p[24].m_pComponent;
      }
    }
    else
    {
      v13 = 0i64;
    }
    if ( !(unsigned __int8)UFG::RoadSpaceComponent::IsAttachedToRoadNetwork(v13)
      || (v16 = v2->m_pActionContext->mSimObject.m_pPointer) != 0i64
      && (v17 = v16->m_pTransformNodeComponent) != 0i64
      && ((v18 = UFG::WheeledVehicleNavigationData::GetRoadNetwork(UFG::WheeledVehicleManager::m_Instance->m_NavigationData),
           v13 != (UFG::RoadSpaceComponent *)-552i64) ? (v19 = v13->mWayClient.m_RoadNetworkType) : (v19 = 0),
          UFG::TransformNodeComponent::UpdateWorldTransform(v17),
          v20 = UFG::RoadNetworkResource::GetClosestNode(
                  v18,
                  (UFG::qVector3 *)&v17->mWorldTransform.v3,
                  v19,
                  0i64,
                  0i64),
          v21 = Scaleform::GFx::AS3::Instances::fl::XML::GetName(&v13->mGuide),
          v20 != (UFG::RoadNetworkIntersection *)UFG::RoadNetworkLocation::GetRoadNetworkNode(v21)) )
    {
      UFG::RoadSpaceComponent::AttachToRoadNetwork(v13, 0);
    }
  }
}

// File Line: 152
// RVA: 0x6905C0
char __fastcall CarWanderTask::Update(CarWanderTask *this, float timestep)
{
  UFG::AiDriverComponent *v2; // rcx

  v2 = (UFG::AiDriverComponent *)this->m_pAIComponent.m_pPointer;
  if ( !v2 )
    return 0;
  UFG::AiDriverComponent::UpdateWanderingNavigation(v2);
  return 1;
}

// File Line: 181
// RVA: 0x667A90
void __fastcall CarRaceTask::CarRaceTask(CarRaceTask *this)
{
  CarRaceTask *v1; // r9
  UFG::qNode<ITask,ITask> *v2; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AiDriverComponent> *v3; // rdx
  UFG::qSafePointer<UFG::SimComponent,UFG::RoadSpaceComponent> *v4; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rax

  v1 = this;
  v2 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<CarRaceTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&CarRaceTask::`vftable;
  v3 = &this->m_pAIComponent;
  v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  this->m_pAIComponent.m_pPointer = 0i64;
  v4 = &this->m_pRoadSpaceComponent;
  v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  v4->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  this->m_pRoadSpaceComponent.m_pPointer = 0i64;
  if ( this->m_pRoadSpaceComponent.m_pPointer )
  {
    v5 = v4->mPrev;
    v6 = v4->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
    v4->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  }
  v4->m_pPointer = 0i64;
  v1->m_pActionContext = 0i64;
  if ( v3->m_pPointer )
  {
    v7 = v3->mPrev;
    v8 = v3->mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
    v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  }
  v3->m_pPointer = 0i64;
}

// File Line: 191
// RVA: 0x671E00
void __fastcall CarRaceTask::Begin(CarRaceTask *this, ActionContext *action_context)
{
  CarRaceTask *v2; // rdi
  UFG::SimObjectCVBase *v3; // rcx
  UFG::SimComponent *v4; // rbx
  UFG::AiDriverComponent *v5; // r8
  unsigned __int16 v6; // dx
  UFG::AiDriverComponent *v7; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AiDriverComponent> *v8; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::SimObjectGame *v12; // rcx
  unsigned __int16 v13; // dx
  UFG::SimComponent *v14; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::RoadSpaceComponent> *v15; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rax
  UFG::RoadSpaceComponent *v19; // rcx
  UFG::AiDriverComponent *v20; // rcx

  v2 = this;
  this->m_pActionContext = action_context;
  if ( action_context )
  {
    v3 = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
    v4 = 0i64;
    if ( v3 )
    {
      v6 = v3->m_Flags;
      if ( (v6 >> 14) & 1 )
      {
        v7 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v3);
      }
      else if ( (v6 & 0x8000u) == 0 )
      {
        if ( (v6 >> 13) & 1 )
        {
          v7 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           (UFG::SimObjectGame *)&v3->vfptr,
                                           UFG::AiDriverComponent::_TypeUID);
        }
        else if ( (v6 >> 12) & 1 )
        {
          v7 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           (UFG::SimObjectGame *)&v3->vfptr,
                                           UFG::AiDriverComponent::_TypeUID);
        }
        else
        {
          v7 = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                           (UFG::SimObject *)&v3->vfptr,
                                           UFG::AiDriverComponent::_TypeUID);
        }
      }
      else
      {
        v7 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v3);
      }
      v5 = v7;
    }
    else
    {
      v5 = 0i64;
    }
    v8 = &v2->m_pAIComponent;
    if ( v2->m_pAIComponent.m_pPointer )
    {
      v9 = v8->mPrev;
      v10 = v2->m_pAIComponent.mNext;
      v9->mNext = v10;
      v10->mPrev = v9;
      v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
      v2->m_pAIComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pAIComponent.mPrev;
    }
    v2->m_pAIComponent.m_pPointer = (UFG::SimComponent *)&v5->vfptr;
    if ( v5 )
    {
      v11 = v5->m_SafePointerList.mNode.mPrev;
      v11->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
      v8->mPrev = v11;
      v2->m_pAIComponent.mNext = &v5->m_SafePointerList.mNode;
      v5->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
    }
    v12 = (UFG::SimObjectGame *)v2->m_pActionContext->mSimObject.m_pPointer;
    if ( v12 )
    {
      v13 = v12->m_Flags;
      if ( (v13 >> 14) & 1 )
      {
        v4 = v12->m_Components.p[24].m_pComponent;
      }
      else if ( (v13 & 0x8000u) == 0 )
      {
        if ( (v13 >> 13) & 1 )
        {
          v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::RoadSpaceComponent::_TypeUID);
        }
        else if ( (v13 >> 12) & 1 )
        {
          v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::RoadSpaceComponent::_TypeUID);
        }
        else
        {
          v14 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v12->vfptr, UFG::RoadSpaceComponent::_TypeUID);
        }
        v4 = v14;
      }
      else
      {
        v4 = v12->m_Components.p[24].m_pComponent;
      }
    }
    v15 = &v2->m_pRoadSpaceComponent;
    if ( v2->m_pRoadSpaceComponent.m_pPointer )
    {
      v16 = v15->mPrev;
      v17 = v2->m_pRoadSpaceComponent.mNext;
      v16->mNext = v17;
      v17->mPrev = v16;
      v15->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v15->mPrev;
      v2->m_pRoadSpaceComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pRoadSpaceComponent.mPrev;
    }
    v2->m_pRoadSpaceComponent.m_pPointer = v4;
    if ( v4 )
    {
      v18 = v4->m_SafePointerList.mNode.mPrev;
      v18->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v15->mPrev;
      v15->mPrev = v18;
      v2->m_pRoadSpaceComponent.mNext = &v4->m_SafePointerList.mNode;
      v4->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v15->mPrev;
    }
    v19 = (UFG::RoadSpaceComponent *)v2->m_pRoadSpaceComponent.m_pPointer;
    if ( v19 && (unsigned __int8)UFG::RoadSpaceComponent::IsAttachedToRoadNetwork(v19) )
      UFG::RoadSpaceComponent::DetachFromRoadNetwork((UFG::RoadSpaceComponent *)v2->m_pRoadSpaceComponent.m_pPointer);
    v20 = (UFG::AiDriverComponent *)v2->m_pAIComponent.m_pPointer;
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
  CarRaceTask *v2; // rbx
  UFG::AiDriverComponent *v4; // rcx

  v2 = this;
  if ( this->m_pAIComponent.m_pPointer )
  {
    if ( !UFG::RoadSpaceComponent::CleanupOnRaceDeleted((UFG::RoadSpaceComponent *)this->m_pRoadSpaceComponent.m_pPointer) )
      return 1;
    v4 = (UFG::AiDriverComponent *)v2->m_pAIComponent.m_pPointer;
    if ( v4->m_RaceWanderAtEnd )
    {
      UFG::AiDriverComponent::SetDrivingMode(v4, 1u);
      LOBYTE(v2->m_pAIComponent.m_pPointer[24].m_NameUID) = 0;
      return 0;
    }
    UFG::AiDriverComponent::SetDrivingMode(v4, 0);
  }
  return 0;
}

// File Line: 274
// RVA: 0x68F9C0
char __fastcall CarOffsetDriveTask::Update(CarOffsetDriveTask *this, float timestep)
{
  UFG::AiDriverComponent *v2; // rcx

  v2 = (UFG::AiDriverComponent *)this->m_pAIComponent.m_pPointer;
  if ( !v2 )
    return 0;
  UFG::AiDriverComponent::UpdateFollowingNavigation(v2, timestep);
  return 1;
}

// File Line: 298
// RVA: 0x6710E0
void __fastcall CarFollowTask::Begin(CarFollowTask *this, ActionContext *action_context)
{
  CarFollowTask *v2; // rbx
  UFG::SimObjectCVBase *v3; // rcx
  UFG::AiDriverComponent *v4; // r8
  unsigned __int16 v5; // dx
  UFG::AiDriverComponent *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AiDriverComponent> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  ActionContext *v11; // rcx
  UFG::SimObjectGame *v12; // rcx
  unsigned __int16 v13; // dx
  UFG::RoadSpaceComponent *v14; // rbx
  UFG::SimComponent *v15; // rax
  UFG::WayFinder *v16; // rax

  v2 = this;
  this->m_pActionContext = action_context;
  v3 = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
  if ( v3 )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v3);
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v6 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                         (UFG::SimObjectGame *)&v3->vfptr,
                                         UFG::AiDriverComponent::_TypeUID);
      }
      else if ( (v5 >> 12) & 1 )
      {
        v6 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                         (UFG::SimObjectGame *)&v3->vfptr,
                                         UFG::AiDriverComponent::_TypeUID);
      }
      else
      {
        v6 = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                         (UFG::SimObject *)&v3->vfptr,
                                         UFG::AiDriverComponent::_TypeUID);
      }
    }
    else
    {
      v6 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v3);
    }
    v4 = v6;
  }
  else
  {
    v4 = 0i64;
  }
  v7 = &v2->m_pAIComponent;
  if ( v2->m_pAIComponent.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v2->m_pAIComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v2->m_pAIComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pAIComponent.mPrev;
  }
  v2->m_pAIComponent.m_pPointer = (UFG::SimComponent *)&v4->vfptr;
  if ( v4 )
  {
    v10 = v4->m_SafePointerList.mNode.mPrev;
    v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v7->mPrev = v10;
    v2->m_pAIComponent.mNext = &v4->m_SafePointerList.mNode;
    v4->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  }
  v11 = v2->m_pActionContext;
  if ( v11 )
  {
    v12 = (UFG::SimObjectGame *)v11->mSimObject.m_pPointer;
    if ( v12 )
    {
      v13 = v12->m_Flags;
      if ( (v13 >> 14) & 1 )
      {
        v14 = (UFG::RoadSpaceComponent *)v12->m_Components.p[24].m_pComponent;
      }
      else if ( (v13 & 0x8000u) == 0 )
      {
        if ( (v13 >> 13) & 1 )
        {
          v15 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::RoadSpaceComponent::_TypeUID);
        }
        else if ( (v13 >> 12) & 1 )
        {
          v15 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::RoadSpaceComponent::_TypeUID);
        }
        else
        {
          v15 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v12->vfptr, UFG::RoadSpaceComponent::_TypeUID);
        }
        v14 = (UFG::RoadSpaceComponent *)v15;
      }
      else
      {
        v14 = (UFG::RoadSpaceComponent *)v12->m_Components.p[24].m_pComponent;
      }
      if ( v14 )
      {
        if ( (unsigned __int8)UFG::RoadSpaceComponent::IsAttachedToRoadNetwork(v14) )
          UFG::RoadSpaceComponent::DetachFromRoadNetwork(v14);
        v16 = UFG::WheeledVehicleNavigationData::GetRoadWayFinder(
                UFG::WheeledVehicleManager::m_Instance->m_NavigationData,
                &v14->mWayClient);
        UFG::WayFinder::Cancel(v16, (UFG::WayFinderClient *)&v14->mWayClient.vfptr);
      }
    }
  }
}

// File Line: 323
// RVA: 0x68F960
char __fastcall CarEscortTask::Update(CarEscortTask *this, float timestep)
{
  CarEscortTask *v2; // rbx
  UFG::AiDriverComponent *v3; // rcx

  v2 = this;
  v3 = (UFG::AiDriverComponent *)this->m_pAIComponent.m_pPointer;
  if ( !v3 )
    return 0;
  UFG::AiDriverComponent::UpdateEscortMode(v3, timestep);
  UFG::AiDriverComponent::UpdateEscortOffset((UFG::AiDriverComponent *)v2->m_pAIComponent.m_pPointer, timestep);
  UFG::AiDriverComponent::UpdateFollowingNavigation((UFG::AiDriverComponent *)v2->m_pAIComponent.m_pPointer, timestep);
  return 1;
}

// File Line: 349
// RVA: 0x672670
void __fastcall CarStopAtTask::Begin(CarStopAtTask *this, ActionContext *action_context)
{
  CarStopAtTask *v2; // rdi
  UFG::SimObjectCVBase *v3; // rcx
  UFG::SimComponent *v4; // rbx
  UFG::AiDriverComponent *v5; // r8
  unsigned __int16 v6; // dx
  UFG::AiDriverComponent *v7; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AiDriverComponent> *v8; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::SimObjectGame *v12; // rcx
  unsigned __int16 v13; // dx
  UFG::SimComponent *v14; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::RoadSpaceComponent> *v15; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rax

  v2 = this;
  this->m_pActionContext = action_context;
  v3 = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
  v4 = 0i64;
  if ( v3 )
  {
    v6 = v3->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v7 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v3);
    }
    else if ( (v6 & 0x8000u) == 0 )
    {
      if ( (v6 >> 13) & 1 )
      {
        v7 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                         (UFG::SimObjectGame *)&v3->vfptr,
                                         UFG::AiDriverComponent::_TypeUID);
      }
      else if ( (v6 >> 12) & 1 )
      {
        v7 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                         (UFG::SimObjectGame *)&v3->vfptr,
                                         UFG::AiDriverComponent::_TypeUID);
      }
      else
      {
        v7 = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                         (UFG::SimObject *)&v3->vfptr,
                                         UFG::AiDriverComponent::_TypeUID);
      }
    }
    else
    {
      v7 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v3);
    }
    v5 = v7;
  }
  else
  {
    v5 = 0i64;
  }
  v8 = &v2->m_pAiDriver;
  if ( v2->m_pAiDriver.m_pPointer )
  {
    v9 = v8->mPrev;
    v10 = v2->m_pAiDriver.mNext;
    v9->mNext = v10;
    v10->mPrev = v9;
    v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
    v2->m_pAiDriver.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pAiDriver.mPrev;
  }
  v2->m_pAiDriver.m_pPointer = (UFG::SimComponent *)&v5->vfptr;
  if ( v5 )
  {
    v11 = v5->m_SafePointerList.mNode.mPrev;
    v11->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
    v8->mPrev = v11;
    v2->m_pAiDriver.mNext = &v5->m_SafePointerList.mNode;
    v5->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
  }
  v12 = (UFG::SimObjectGame *)v2->m_pActionContext->mSimObject.m_pPointer;
  if ( v12 )
  {
    v13 = v12->m_Flags;
    if ( (v13 >> 14) & 1 )
    {
      v4 = v12->m_Components.p[24].m_pComponent;
    }
    else if ( (v13 & 0x8000u) == 0 )
    {
      if ( (v13 >> 13) & 1 )
      {
        v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::RoadSpaceComponent::_TypeUID);
      }
      else if ( (v13 >> 12) & 1 )
      {
        v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::RoadSpaceComponent::_TypeUID);
      }
      else
      {
        v14 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v12->vfptr, UFG::RoadSpaceComponent::_TypeUID);
      }
      v4 = v14;
    }
    else
    {
      v4 = v12->m_Components.p[24].m_pComponent;
    }
  }
  v15 = &v2->m_pRoadSpace;
  if ( v2->m_pRoadSpace.m_pPointer )
  {
    v16 = v15->mPrev;
    v17 = v2->m_pRoadSpace.mNext;
    v16->mNext = v17;
    v17->mPrev = v16;
    v15->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v15->mPrev;
    v2->m_pRoadSpace.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pRoadSpace.mPrev;
  }
  v2->m_pRoadSpace.m_pPointer = v4;
  if ( v4 )
  {
    v18 = v4->m_SafePointerList.mNode.mPrev;
    v18->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v15->mPrev;
    v15->mPrev = v18;
    v2->m_pRoadSpace.mNext = &v4->m_SafePointerList.mNode;
    v4->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v15->mPrev;
  }
}

// File Line: 360
// RVA: 0x690420
bool __fastcall CarStopAtTask::Update(CarStopAtTask *this, float timestep)
{
  float *v2; // rax
  CarStopAtTask *v3; // rbx
  UFG::TransformNodeComponent *v4; // rsi
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
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rcx

  v2 = (float *)this->m_pRoadSpace.m_pPointer;
  v3 = this;
  if ( !v2 || !this->m_pAiDriver.m_pPointer )
    return 0;
  v4 = 0i64;
  v5 = v2[412];
  v6 = v2[413];
  v7 = v2[414];
  v8 = this->m_pActionContext->mSimObject.m_pPointer;
  if ( v8 )
    v4 = v8->m_pTransformNodeComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform(v4);
  v9 = v3->m_pAiDriver.m_pPointer;
  v10 = 0;
  v11 = *(float *)&v9[24].m_SafePointerList.mNode.mPrev;
  v12 = v4->mWorldTransform.v3.x - v5;
  v13 = v4->mWorldTransform.v3.y - v6;
  v14 = v4->mWorldTransform.v3.z - v7;
  if ( (float)((float)((float)(v13 * v13) + (float)(v12 * v12)) + (float)(v14 * v14)) > (float)(v11 * v11) )
    return 1;
  if ( !LOBYTE(v9[23].m_BoundComponentHandles.mNode.mNext)
    || COERCE_FLOAT(LODWORD(v11) ^ _xmm[0]) < (float)((float)((float)(v13
                                                                    * *((float *)&v3->m_pRoadSpace.m_pPointer[27].m_pSimObject
                                                                      + 1))
                                                            + (float)(v12
                                                                    * *(float *)&v3->m_pRoadSpace.m_pPointer[27].m_pSimObject))
                                                    + (float)(v14
                                                            * *(float *)&v3->m_pRoadSpace.m_pPointer[27].m_BoundComponentHandles.mNode.mPrev)) )
  {
    v16 = v9[12].m_BoundComponentHandles.mNode.mNext;
    if ( v16 )
    {
      if ( LODWORD(v9[13].vfptr) == LODWORD(v16->mNext) )
      {
        LOBYTE(v9) = 1;
        ((void (__fastcall *)(UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *, UFG::SimComponent *))v16->mPrev[7].mNext)(
          v16,
          v9);
      }
    }
    UFG::AiDriverComponent::SetDrivingMode((UFG::AiDriverComponent *)v3->m_pAiDriver.m_pPointer, 0);
    v10 = 1;
  }
  return v10 == 0;
}

// File Line: 407
// RVA: 0x671FD0
void __fastcall CarStopAtStimulusTask::Begin(CarStopAtStimulusTask *this, ActionContext *action_context)
{
  CarStopAtStimulusTask *v2; // rsi
  UFG::SimObjectCVBase *v3; // rcx
  ActionContext *v4; // rbx
  UFG::AiDriverComponent *v5; // r8
  unsigned __int16 v6; // dx
  UFG::AiDriverComponent *v7; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AiDriverComponent> *v8; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::SimObjectGame *v12; // rcx
  UFG::SimComponent *v13; // r8
  unsigned __int16 v14; // dx
  UFG::SimComponent *v15; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::RoadSpaceComponent> *v16; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::SimComponent *v20; // rax
  UFG::SimObjectGame *v21; // rcx
  UFG::SimComponent *v22; // rdx
  unsigned __int16 v23; // dx
  UFG::SimComponent *v24; // rax
  __int64 v25; // rbx
  UFG::TransformNodeComponent *v26; // rbx
  float v27; // xmm1_4
  float v28; // xmm2_4
  UFG::RoadNetworkResource *v29; // rax
  UFG::SimComponent *v30; // rcx
  signed __int64 v31; // rcx
  unsigned int v32; // er8
  UFG::RoadNetworkIntersection *v33; // rdi
  UFG::RoadNetworkLane *v34; // rbx
  float v35; // xmm0_4
  UFG::qVector3 *v36; // rax
  UFG::SimComponent *v37; // rcx
  float v38; // xmm12_4
  float v39; // xmm13_4
  float v40; // xmm14_4
  float v41; // xmm6_4
  __m128 v42; // xmm7
  float v43; // xmm8_4
  __m128 v44; // xmm2
  float v45; // xmm3_4
  float v46; // xmm9_4
  float v47; // xmm10_4
  float v48; // xmm3_4
  float v49; // xmm9_4
  float v50; // xmm10_4
  __m128 v51; // xmm7
  __m128 v52; // xmm2
  float v53; // xmm0_4
  __m128 v54; // xmm2
  __m128 v55; // xmm1
  float v56; // xmm6_4
  float v57; // xmm6_4
  __m128 v58; // xmm7
  float v59; // xmm6_4
  __m128 v60; // xmm8
  float v61; // xmm1_4
  float v62; // xmm2_4
  float v63; // xmm8_4
  float v64; // xmm2_4
  __m128 v65; // xmm11
  __m128 v66; // xmm3
  float v67; // xmm4_4
  UFG::SimComponent *v68; // rax
  int v69; // xmm6_4
  UFG::RoadNetworkLocation *v70; // rax
  UFG::qVector3 *v71; // rax
  UFG::RoadSpaceComponent *v72; // rcx
  unsigned int v73; // edx
  UFG::qVector3 result; // [rsp+30h] [rbp-D0h]
  UFG::qVector3 pos; // [rsp+40h] [rbp-C0h]
  UFG::qVector3 v76; // [rsp+50h] [rbp-B0h]
  UFG::qMatrix44 matrix; // [rsp+60h] [rbp-A0h]

  v2 = this;
  this->m_pActionContext = action_context;
  v3 = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
  v4 = action_context;
  if ( v3 )
  {
    v6 = v3->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v7 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v3);
    }
    else if ( (v6 & 0x8000u) == 0 )
    {
      if ( (v6 >> 13) & 1 )
      {
        v7 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                         (UFG::SimObjectGame *)&v3->vfptr,
                                         UFG::AiDriverComponent::_TypeUID);
      }
      else if ( (v6 >> 12) & 1 )
      {
        v7 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                         (UFG::SimObjectGame *)&v3->vfptr,
                                         UFG::AiDriverComponent::_TypeUID);
      }
      else
      {
        v7 = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                         (UFG::SimObject *)&v3->vfptr,
                                         UFG::AiDriverComponent::_TypeUID);
      }
    }
    else
    {
      v7 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v3);
    }
    v5 = v7;
  }
  else
  {
    v5 = 0i64;
  }
  v8 = &v2->m_pAiDriver;
  if ( v2->m_pAiDriver.m_pPointer )
  {
    v9 = v8->mPrev;
    v10 = v2->m_pAiDriver.mNext;
    v9->mNext = v10;
    v10->mPrev = v9;
    v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
    v2->m_pAiDriver.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pAiDriver.mPrev;
  }
  v2->m_pAiDriver.m_pPointer = (UFG::SimComponent *)&v5->vfptr;
  if ( v5 )
  {
    v11 = v5->m_SafePointerList.mNode.mPrev;
    v11->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
    v8->mPrev = v11;
    v2->m_pAiDriver.mNext = &v5->m_SafePointerList.mNode;
    v5->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
  }
  v12 = (UFG::SimObjectGame *)v2->m_pActionContext->mSimObject.m_pPointer;
  if ( v12 )
  {
    v14 = v12->m_Flags;
    if ( (v14 >> 14) & 1 )
    {
      v13 = v12->m_Components.p[24].m_pComponent;
    }
    else if ( (v14 & 0x8000u) == 0 )
    {
      if ( (v14 >> 13) & 1 )
      {
        v15 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::RoadSpaceComponent::_TypeUID);
      }
      else if ( (v14 >> 12) & 1 )
      {
        v15 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::RoadSpaceComponent::_TypeUID);
      }
      else
      {
        v15 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v12->vfptr, UFG::RoadSpaceComponent::_TypeUID);
      }
      v13 = v15;
    }
    else
    {
      v13 = v12->m_Components.p[24].m_pComponent;
    }
  }
  else
  {
    v13 = 0i64;
  }
  v16 = &v2->m_pRoadSpace;
  if ( v2->m_pRoadSpace.m_pPointer )
  {
    v17 = v16->mPrev;
    v18 = v2->m_pRoadSpace.mNext;
    v17->mNext = v18;
    v18->mPrev = v17;
    v16->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v16->mPrev;
    v2->m_pRoadSpace.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pRoadSpace.mPrev;
  }
  v2->m_pRoadSpace.m_pPointer = v13;
  if ( v13 )
  {
    v19 = v13->m_SafePointerList.mNode.mPrev;
    v19->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v16->mPrev;
    v16->mPrev = v19;
    v2->m_pRoadSpace.mNext = &v13->m_SafePointerList.mNode;
    v13->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v16->mPrev;
  }
  v20 = v2->m_pAiDriver.m_pPointer;
  v2->mElapsedTime = 0.0;
  if ( v20 )
    v2->mPrevAI = (unsigned int)v20[13].m_SafePointerList.mNode.mPrev;
  v21 = (UFG::SimObjectGame *)v4->mSimObject.m_pPointer;
  if ( v21 )
  {
    v23 = v21->m_Flags;
    if ( (v23 >> 14) & 1 )
    {
      v22 = v21->m_Components.p[20].m_pComponent;
    }
    else if ( (v23 & 0x8000u) == 0 )
    {
      if ( (v23 >> 13) & 1 )
      {
        v24 = UFG::SimObjectGame::GetComponentOfTypeHK(v21, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else if ( (v23 >> 12) & 1 )
      {
        v24 = UFG::SimObjectGame::GetComponentOfTypeHK(v21, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else
      {
        v24 = UFG::SimObject::GetComponentOfType(
                (UFG::SimObject *)&v21->vfptr,
                UFG::TargetingSystemBaseComponent::_TypeUID);
      }
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
  v27 = v26->mWorldTransform.v3.y;
  v28 = v26->mWorldTransform.v3.z;
  pos.x = v26->mWorldTransform.v3.x;
  pos.y = v27;
  pos.z = v28;
  v29 = UFG::WheeledVehicleNavigationData::GetRoadNetwork(UFG::WheeledVehicleManager::m_Instance->m_NavigationData);
  if ( !v29 )
    goto LABEL_73;
  v30 = v2->m_pRoadSpace.m_pPointer;
  if ( v30 && (v31 = (signed __int64)&v30[8].m_pSimObject) != 0 )
    v32 = *(_DWORD *)(v31 + 1072);
  else
    v32 = 0;
  v33 = UFG::RoadNetworkResource::GetClosestNode(v29, &pos, v32, 0i64, 0i64);
  v34 = UFG::RoadNetworkNode::GetClosestLane((UFG::RoadNetworkNode *)&v33->mType, &pos);
  UFG::RoadNetworkNode::GetClosestPosition((UFG::RoadNetworkNode *)&v33->mType, &result, &pos, 0i64);
  v35 = UFG::RoadNetworkNode::GetClosestT((UFG::RoadNetworkNode *)&v33->mType, v34->mLaneIndex, &result);
  v36 = UFG::RoadNetworkNode::GetPos((UFG::RoadNetworkNode *)&v33->mType, &v76, v34->mLaneIndex, v35);
  v37 = v2->m_pRoadSpace.m_pPointer;
  v38 = v36->y;
  v39 = v36->z;
  v40 = v36->x;
  result.x = v36->x;
  result.y = v38;
  result.z = v39;
  v41 = *((float *)&v37[27].m_pSimObject + 1);
  v42 = (__m128)LODWORD(v37[27].m_pSimObject);
  v43 = *(float *)&v37[27].m_BoundComponentHandles.mNode.mPrev;
  v44 = v42;
  v44.m128_f32[0] = (float)((float)(v42.m128_f32[0] * v42.m128_f32[0]) + (float)(v41 * v41)) + (float)(v43 * v43);
  v45 = v44.m128_f32[0] == 0.0 ? 0.0 : 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v44));
  v46 = v45;
  v47 = v45;
  v48 = v45 * v43;
  matrix.v0.w = 0.0;
  v49 = v46 * v42.m128_f32[0];
  v50 = v47 * v41;
  v51 = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
  matrix.v0.z = v48;
  v52 = v51;
  matrix.v0.x = v49;
  matrix.v0.y = v50;
  v52.m128_f32[0] = (float)((float)(v51.m128_f32[0] * v51.m128_f32[0])
                          + (float)(UFG::qVector3::msDirUp.y * UFG::qVector3::msDirUp.y))
                  + (float)(UFG::qVector3::msDirUp.z * UFG::qVector3::msDirUp.z);
  if ( v52.m128_f32[0] == 0.0 )
  {
    v54 = 0i64;
  }
  else
  {
    LODWORD(v53) = (unsigned __int128)_mm_sqrt_ps(v52);
    v54 = (__m128)(unsigned int)FLOAT_1_0;
    v54.m128_f32[0] = 1.0 / v53;
  }
  v55 = v54;
  v56 = v54.m128_f32[0];
  v54.m128_f32[0] = v54.m128_f32[0] * UFG::qVector3::msDirUp.z;
  v55.m128_f32[0] = v55.m128_f32[0] * UFG::qVector3::msDirUp.y;
  v57 = v56 * UFG::qVector3::msDirUp.x;
  v58 = v55;
  v58.m128_f32[0] = (float)(v55.m128_f32[0] * v48) - (float)(v54.m128_f32[0] * v50);
  v54.m128_f32[0] = (float)(v54.m128_f32[0] * v49) - (float)(v57 * v48);
  v59 = (float)(v57 * v50) - (float)(v55.m128_f32[0] * v49);
  v60 = v54;
  v60.m128_f32[0] = (float)((float)(v54.m128_f32[0] * v54.m128_f32[0]) + (float)(v58.m128_f32[0] * v58.m128_f32[0]))
                  + (float)(v59 * v59);
  v61 = v60.m128_f32[0] == 0.0 ? 0.0 : 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v60));
  v58.m128_f32[0] = v58.m128_f32[0] * v61;
  v62 = v54.m128_f32[0] * v61;
  matrix.v1.w = 0.0;
  v65 = v58;
  LODWORD(matrix.v1.x) = v58.m128_i32[0];
  matrix.v1.y = v62;
  matrix.v1.z = v59 * v61;
  v63 = (float)((float)(v59 * v61) * v50) - (float)(v62 * v48);
  v64 = (float)(v62 * v49) - (float)(v58.m128_f32[0] * v50);
  v65.m128_f32[0] = (float)(v58.m128_f32[0] * v48) - (float)((float)(v59 * v61) * v49);
  v66 = v65;
  v66.m128_f32[0] = (float)((float)(v65.m128_f32[0] * v65.m128_f32[0]) + (float)(v63 * v63)) + (float)(v64 * v64);
  v67 = v66.m128_f32[0] == 0.0 ? 0.0 : 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v66));
  v68 = v2->m_pAiDriver.m_pPointer;
  matrix.v3.x = v40;
  matrix.v3.y = v38;
  matrix.v3.z = v39;
  matrix.v2.w = 0.0;
  matrix.v3.w = 1.0;
  matrix.v2.x = v63 * v67;
  matrix.v2.y = v65.m128_f32[0] * v67;
  matrix.v2.z = v64 * v67;
  v69 = (int)v68[24].m_SafePointerList.mNode.mPrev;
  v70 = Scaleform::GFx::AS3::Instances::fl::XML::GetName((UFG::RoadNetworkGuide *)&v37[5].m_BoundComponentHandles.mNode.mNext);
  v71 = UFG::RoadNetworkLocation::GetPos(v70, &v76);
  v72 = (UFG::RoadSpaceComponent *)v2->m_pRoadSpace.m_pPointer;
  if ( COERCE_FLOAT(v69 ^ _xmm[0]) >= (float)((float)((float)((float)(v71->y - result.y) * v72->m_ChaseWorld.v0.y)
                                                    + (float)((float)(v71->x - result.x) * v72->m_ChaseWorld.v0.x))
                                            + (float)((float)(v71->z - result.z) * v72->m_ChaseWorld.v0.z)) )
  {
    UFG::RoadSpaceComponent::SetCarDestination(v72, &matrix);
    v73 = 5;
  }
  else
  {
LABEL_73:
    v73 = 0;
  }
  UFG::AiDriverComponent::SetDrivingMode((UFG::AiDriverComponent *)v2->m_pAiDriver.m_pPointer, v73);
}

// File Line: 496
// RVA: 0x672A30
void __fastcall CarWaitTask::Begin(CarWaitTask *this, ActionContext *action_context)
{
  CarWaitTask *v2; // rbx
  UFG::SimObjectCVBase *v3; // rcx
  UFG::AiDriverComponent *v4; // r8
  unsigned __int16 v5; // dx
  UFG::AiDriverComponent *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AiDriverComponent> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::SimObjectGame *v11; // rcx
  UFG::SimComponent *v12; // r8
  unsigned __int16 v13; // dx
  UFG::SimComponent *v14; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::RoadSpaceComponent> *v15; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rax
  UFG::AiDriverComponent *v19; // rcx

  v2 = this;
  this->m_pActionContext = action_context;
  v3 = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
  if ( v3 )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v3);
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v6 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                         (UFG::SimObjectGame *)&v3->vfptr,
                                         UFG::AiDriverComponent::_TypeUID);
      }
      else if ( (v5 >> 12) & 1 )
      {
        v6 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                         (UFG::SimObjectGame *)&v3->vfptr,
                                         UFG::AiDriverComponent::_TypeUID);
      }
      else
      {
        v6 = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                         (UFG::SimObject *)&v3->vfptr,
                                         UFG::AiDriverComponent::_TypeUID);
      }
    }
    else
    {
      v6 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v3);
    }
    v4 = v6;
  }
  else
  {
    v4 = 0i64;
  }
  v7 = &v2->m_pAiDriver;
  if ( v2->m_pAiDriver.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v2->m_pAiDriver.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v2->m_pAiDriver.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pAiDriver.mPrev;
  }
  v2->m_pAiDriver.m_pPointer = (UFG::SimComponent *)&v4->vfptr;
  if ( v4 )
  {
    v10 = v4->m_SafePointerList.mNode.mPrev;
    v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v7->mPrev = v10;
    v2->m_pAiDriver.mNext = &v4->m_SafePointerList.mNode;
    v4->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  }
  v11 = (UFG::SimObjectGame *)v2->m_pActionContext->mSimObject.m_pPointer;
  if ( v11 )
  {
    v13 = v11->m_Flags;
    if ( (v13 >> 14) & 1 )
    {
      v12 = v11->m_Components.p[24].m_pComponent;
    }
    else if ( (v13 & 0x8000u) == 0 )
    {
      if ( (v13 >> 13) & 1 )
      {
        v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::RoadSpaceComponent::_TypeUID);
      }
      else if ( (v13 >> 12) & 1 )
      {
        v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::RoadSpaceComponent::_TypeUID);
      }
      else
      {
        v14 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v11->vfptr, UFG::RoadSpaceComponent::_TypeUID);
      }
      v12 = v14;
    }
    else
    {
      v12 = v11->m_Components.p[24].m_pComponent;
    }
  }
  else
  {
    v12 = 0i64;
  }
  v15 = &v2->m_pRoadSpace;
  if ( v2->m_pRoadSpace.m_pPointer )
  {
    v16 = v15->mPrev;
    v17 = v2->m_pRoadSpace.mNext;
    v16->mNext = v17;
    v17->mPrev = v16;
    v15->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v15->mPrev;
    v2->m_pRoadSpace.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pRoadSpace.mPrev;
  }
  v2->m_pRoadSpace.m_pPointer = v12;
  if ( v12 )
  {
    v18 = v12->m_SafePointerList.mNode.mPrev;
    v18->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v15->mPrev;
    v15->mPrev = v18;
    v2->m_pRoadSpace.mNext = &v12->m_SafePointerList.mNode;
    v12->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v15->mPrev;
  }
  v19 = (UFG::AiDriverComponent *)v2->m_pAiDriver.m_pPointer;
  v2->mElapsedTime = 0.0;
  if ( v19 )
  {
    v2->mPrevAI = v19->m_DrivingMode;
    UFG::AiDriverComponent::SetDrivingMode(v19, 0);
  }
}

// File Line: 513
// RVA: 0x6905A0
char __fastcall CarWaitTask::Update(CarWaitTask *this, float timestep)
{
  float v2; // xmm0_4
  char result; // al

  v2 = this->mElapsedTime;
  if ( v2 > *(float *)&this->m_Track[1].vfptr )
    return 0;
  result = 1;
  this->mElapsedTime = v2 + timestep;
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
  CarGoToTask *v1; // rbx
  ActionContext *v2; // rcx
  UFG::SimObjectCVBase *v3; // rcx
  UFG::AiDriverComponent *v4; // r8
  unsigned __int16 v5; // dx
  UFG::AiDriverComponent *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AiDriverComponent> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::SimObjectGame *v11; // rcx
  UFG::SimComponent *v12; // r8
  unsigned __int16 v13; // dx
  UFG::SimComponent *v14; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::RoadSpaceComponent> *v15; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rax
  UFG::AiDriverComponent *v19; // rcx
  UFG::SimObject *v20; // rcx
  UFG::TransformNodeComponent *v21; // rcx
  UFG::SimObject *v22; // rcx
  UFG::TransformNodeComponent *v23; // rcx
  UFG::VehicleWayFinderClient *v24; // rsi
  UFG::SimComponent *v25; // rax
  UFG::qVector3 *v26; // r14
  float *v27; // rdi
  UFG::WayFinder *v28; // rax
  UFG::WayFinder *v29; // rbp
  UFG::qVector3 *v30; // r9

  v1 = this;
  v2 = this->m_pActionContext;
  if ( v2 )
  {
    v3 = (UFG::SimObjectCVBase *)v2->mSimObject.m_pPointer;
    if ( v3 )
    {
      v5 = v3->m_Flags;
      if ( (v5 >> 14) & 1 )
      {
        v6 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v3);
      }
      else if ( (v5 & 0x8000u) == 0 )
      {
        if ( (v5 >> 13) & 1 )
        {
          v6 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           (UFG::SimObjectGame *)&v3->vfptr,
                                           UFG::AiDriverComponent::_TypeUID);
        }
        else if ( (v5 >> 12) & 1 )
        {
          v6 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           (UFG::SimObjectGame *)&v3->vfptr,
                                           UFG::AiDriverComponent::_TypeUID);
        }
        else
        {
          v6 = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                           (UFG::SimObject *)&v3->vfptr,
                                           UFG::AiDriverComponent::_TypeUID);
        }
      }
      else
      {
        v6 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v3);
      }
      v4 = v6;
    }
    else
    {
      v4 = 0i64;
    }
    v7 = &v1->m_pAIComponent;
    if ( v1->m_pAIComponent.m_pPointer )
    {
      v8 = v7->mPrev;
      v9 = v1->m_pAIComponent.mNext;
      v8->mNext = v9;
      v9->mPrev = v8;
      v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
      v1->m_pAIComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pAIComponent.mPrev;
    }
    v1->m_pAIComponent.m_pPointer = (UFG::SimComponent *)&v4->vfptr;
    if ( v4 )
    {
      v10 = v4->m_SafePointerList.mNode.mPrev;
      v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
      v7->mPrev = v10;
      v1->m_pAIComponent.mNext = &v4->m_SafePointerList.mNode;
      v4->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    }
    v11 = (UFG::SimObjectGame *)v1->m_pActionContext->mSimObject.m_pPointer;
    if ( v11 )
    {
      v13 = v11->m_Flags;
      if ( (v13 >> 14) & 1 )
      {
        v12 = v11->m_Components.p[24].m_pComponent;
      }
      else if ( (v13 & 0x8000u) == 0 )
      {
        if ( (v13 >> 13) & 1 )
        {
          v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::RoadSpaceComponent::_TypeUID);
        }
        else if ( (v13 >> 12) & 1 )
        {
          v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::RoadSpaceComponent::_TypeUID);
        }
        else
        {
          v14 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v11->vfptr, UFG::RoadSpaceComponent::_TypeUID);
        }
        v12 = v14;
      }
      else
      {
        v12 = v11->m_Components.p[24].m_pComponent;
      }
    }
    else
    {
      v12 = 0i64;
    }
    v15 = &v1->m_pRoadSpaceComponent;
    if ( v1->m_pRoadSpaceComponent.m_pPointer )
    {
      v16 = v15->mPrev;
      v17 = v1->m_pRoadSpaceComponent.mNext;
      v16->mNext = v17;
      v17->mPrev = v16;
      v15->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v15->mPrev;
      v1->m_pRoadSpaceComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pRoadSpaceComponent.mPrev;
    }
    v1->m_pRoadSpaceComponent.m_pPointer = v12;
    if ( v12 )
    {
      v18 = v12->m_SafePointerList.mNode.mPrev;
      v18->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v15->mPrev;
      v15->mPrev = v18;
      v1->m_pRoadSpaceComponent.mNext = &v12->m_SafePointerList.mNode;
      v12->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v15->mPrev;
    }
    v19 = (UFG::AiDriverComponent *)v1->m_pAIComponent.m_pPointer;
    if ( v19->m_bIsParked )
      UFG::AiDriverComponent::SetParked(v19, 0);
    if ( !(unsigned __int8)UFG::RoadSpaceComponent::IsAttachedToRoadNetwork((UFG::RoadSpaceComponent *)v1->m_pRoadSpaceComponent.m_pPointer) )
      UFG::RoadSpaceComponent::AttachToRoadNetwork((UFG::RoadSpaceComponent *)v1->m_pRoadSpaceComponent.m_pPointer, 0);
    v20 = v1->m_pActionContext->mSimObject.m_pPointer;
    if ( v20 )
      v21 = v20->m_pTransformNodeComponent;
    else
      v21 = 0i64;
    UFG::TransformNodeComponent::UpdateWorldTransform(v21);
    v22 = v1->m_pActionContext->mSimObject.m_pPointer;
    if ( v22 )
      v23 = v22->m_pTransformNodeComponent;
    else
      v23 = 0i64;
    UFG::TransformNodeComponent::UpdateWorldTransform(v23);
    v24 = (UFG::VehicleWayFinderClient *)&v1->m_pRoadSpaceComponent.m_pPointer[8].m_pSimObject;
    UFG::WayFinderClient::Reset((UFG::WayFinderClient *)&v24->vfptr);
    v25 = v1->m_pRoadSpaceComponent.m_pPointer;
    v26 = (UFG::qVector3 *)&v25[25].m_BoundComponentHandles;
    v27 = (float *)((char *)&v25[25].m_BoundComponentHandles.mNode.mNext + 4);
    v28 = UFG::WheeledVehicleNavigationData::GetRoadWayFinder(
            UFG::WheeledVehicleManager::m_Instance->m_NavigationData,
            v24);
    v29 = v28;
    if ( LOBYTE(v1->m_pAIComponent.m_pPointer[22].m_BoundComponentHandles.mNode.mNext)
      || UFG::qVector3::msZero.x == *v27 && UFG::qVector3::msZero.y == v27[1] && UFG::qVector3::msZero.z == v27[2] )
    {
      v30 = 0i64;
    }
    else
    {
      v30 = (UFG::qVector3 *)v27;
    }
    UFG::WayFinder::FindWay(v28, (UFG::WayFinderClient *)&v24->vfptr, v26, v30);
    UFG::WayFinder::Service(v29, 0.0);
    if ( v24->m_NumWayEdges )
      UFG::VehicleOccupantComponent::SetParkingSpot(
        (UFG::RoadNetworkGuide *)&v1->m_pRoadSpaceComponent.m_pPointer[5].m_BoundComponentHandles.mNode.mNext,
        0i64);
  }
}

// File Line: 619
// RVA: 0x671640
void __fastcall CarGoToTask::Begin(CarGoToTask *this, ActionContext *action_context)
{
  CarGoToTask *v2; // rdi
  UFG::SimObjectCVBase *v3; // rcx
  UFG::AiDriverComponent *v4; // r8
  unsigned __int16 v5; // dx
  UFG::AiDriverComponent *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AiDriverComponent> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::SimObjectGame *v11; // rcx
  UFG::SimComponent *v12; // r8
  unsigned __int16 v13; // dx
  UFG::SimComponent *v14; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::RoadSpaceComponent> *v15; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rax
  UFG::RoadSpaceComponent *v19; // rcx
  bool v20; // al
  UFG::AiDriverComponent *v21; // rcx
  UFG::SimObject *v22; // rcx
  UFG::TransformNodeComponent *v23; // rbx
  unsigned int v24; // esi
  UFG::RoadNetworkResource *v25; // rbp
  UFG::RoadNetworkIntersection *v26; // rbx
  UFG::RoadNetworkLocation *v27; // rax

  v2 = this;
  this->m_pActionContext = action_context;
  if ( action_context )
  {
    v3 = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
    if ( v3 )
    {
      v5 = v3->m_Flags;
      if ( (v5 >> 14) & 1 )
      {
        v6 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v3);
      }
      else if ( (v5 & 0x8000u) == 0 )
      {
        if ( (v5 >> 13) & 1 )
        {
          v6 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           (UFG::SimObjectGame *)&v3->vfptr,
                                           UFG::AiDriverComponent::_TypeUID);
        }
        else if ( (v5 >> 12) & 1 )
        {
          v6 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           (UFG::SimObjectGame *)&v3->vfptr,
                                           UFG::AiDriverComponent::_TypeUID);
        }
        else
        {
          v6 = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                           (UFG::SimObject *)&v3->vfptr,
                                           UFG::AiDriverComponent::_TypeUID);
        }
      }
      else
      {
        v6 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v3);
      }
      v4 = v6;
    }
    else
    {
      v4 = 0i64;
    }
    v7 = &v2->m_pAIComponent;
    if ( v2->m_pAIComponent.m_pPointer )
    {
      v8 = v7->mPrev;
      v9 = v2->m_pAIComponent.mNext;
      v8->mNext = v9;
      v9->mPrev = v8;
      v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
      v2->m_pAIComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pAIComponent.mPrev;
    }
    v2->m_pAIComponent.m_pPointer = (UFG::SimComponent *)&v4->vfptr;
    if ( v4 )
    {
      v10 = v4->m_SafePointerList.mNode.mPrev;
      v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
      v7->mPrev = v10;
      v2->m_pAIComponent.mNext = &v4->m_SafePointerList.mNode;
      v4->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    }
    v11 = (UFG::SimObjectGame *)v2->m_pActionContext->mSimObject.m_pPointer;
    if ( v11 )
    {
      v13 = v11->m_Flags;
      if ( (v13 >> 14) & 1 )
      {
        v12 = v11->m_Components.p[24].m_pComponent;
      }
      else if ( (v13 & 0x8000u) == 0 )
      {
        if ( (v13 >> 13) & 1 )
        {
          v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::RoadSpaceComponent::_TypeUID);
        }
        else if ( (v13 >> 12) & 1 )
        {
          v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::RoadSpaceComponent::_TypeUID);
        }
        else
        {
          v14 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v11->vfptr, UFG::RoadSpaceComponent::_TypeUID);
        }
        v12 = v14;
      }
      else
      {
        v12 = v11->m_Components.p[24].m_pComponent;
      }
    }
    else
    {
      v12 = 0i64;
    }
    v15 = &v2->m_pRoadSpaceComponent;
    if ( v2->m_pRoadSpaceComponent.m_pPointer )
    {
      v16 = v15->mPrev;
      v17 = v2->m_pRoadSpaceComponent.mNext;
      v16->mNext = v17;
      v17->mPrev = v16;
      v15->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v15->mPrev;
      v2->m_pRoadSpaceComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pRoadSpaceComponent.mPrev;
    }
    v2->m_pRoadSpaceComponent.m_pPointer = v12;
    if ( v12 )
    {
      v18 = v12->m_SafePointerList.mNode.mPrev;
      v18->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v15->mPrev;
      v15->mPrev = v18;
      v2->m_pRoadSpaceComponent.mNext = &v12->m_SafePointerList.mNode;
      v12->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v15->mPrev;
    }
  }
  v19 = (UFG::RoadSpaceComponent *)v2->m_pRoadSpaceComponent.m_pPointer;
  if ( v19 )
  {
    v20 = UFG::RoadSpaceComponent::IsNavGuideEnabled(v19);
    v21 = (UFG::AiDriverComponent *)v2->m_pAIComponent.m_pPointer;
    if ( v20 )
    {
      UFG::AiDriverComponent::BeginPathingNavigation(v21);
    }
    else
    {
      if ( v21->m_bIsParked )
        UFG::AiDriverComponent::SetParked(v21, 0);
      if ( (unsigned __int8)UFG::RoadSpaceComponent::IsAttachedToRoadNetwork((UFG::RoadSpaceComponent *)v2->m_pRoadSpaceComponent.m_pPointer) )
      {
        v22 = v2->m_pActionContext->mSimObject.m_pPointer;
        if ( v22 )
        {
          v23 = v22->m_pTransformNodeComponent;
          if ( v23 )
          {
            v24 = 0;
            v25 = UFG::WheeledVehicleNavigationData::GetRoadNetwork(UFG::WheeledVehicleManager::m_Instance->m_NavigationData);
            if ( v2->m_pRoadSpaceComponent.m_pPointer != (UFG::SimComponent *)-552i64 )
              v24 = v2->m_pRoadSpaceComponent.m_pPointer[25].m_TypeUID;
            UFG::TransformNodeComponent::UpdateWorldTransform(v23);
            v26 = UFG::RoadNetworkResource::GetClosestNode(
                    v25,
                    (UFG::qVector3 *)&v23->mWorldTransform.v3,
                    v24,
                    0i64,
                    0i64);
            v27 = Scaleform::GFx::AS3::Instances::fl::XML::GetName((UFG::RoadNetworkGuide *)&v2->m_pRoadSpaceComponent.m_pPointer[5].m_BoundComponentHandles.mNode.mNext);
            if ( v26 != (UFG::RoadNetworkIntersection *)UFG::RoadNetworkLocation::GetRoadNetworkNode(v27) )
              UFG::RoadSpaceComponent::AttachToRoadNetwork(
                (UFG::RoadSpaceComponent *)v2->m_pRoadSpaceComponent.m_pPointer,
                0);
          }
        }
      }
      else
      {
        UFG::RoadSpaceComponent::AttachToRoadNetwork((UFG::RoadSpaceComponent *)v2->m_pRoadSpaceComponent.m_pPointer, 0);
      }
      if ( 0 == WORD2(v2->m_pRoadSpaceComponent.m_pPointer[9].m_SafePointerList.mNode.mPrev) )
        CarGoToTask::FindWay(v2);
    }
  }
}

// File Line: 670
// RVA: 0x68FAC0
bool __fastcall CarGoToTask::Update(CarGoToTask *this, float timestep)
{
  CarGoToTask *v2; // rbx
  UFG::RoadSpaceComponent *v3; // rcx
  bool v4; // si
  UFG::AiDriverComponent *v5; // r8
  SSInvokedCoroutine *v6; // rcx
  __int64 v7; // rdx
  bool v8; // al
  UFG::VehicleWayFinderClient *v9; // rsi
  UFG::WayFinder *v10; // rax
  UFG::RoadNetworkLocation *v11; // rax
  UFG::AiDriverComponent *v12; // rcx
  float *v13; // rax
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm0_4
  ActionContext *v17; // rax
  UFG::SimObject *v18; // r14
  UFG::TransformNodeComponent *v19; // r14
  char v20; // bp
  UFG::RoadNetworkGuide *v21; // r14
  UFG::RoadNetworkLocation *v22; // rax
  UFG::RoadNetworkNode *v23; // rax
  UFG::RoadNetworkLane *v24; // r15
  float v25; // xmm6_4
  __int64 v26; // rax
  signed __int64 v27; // rsi
  UFG::RoadNetworkLane *v28; // rcx
  __int64 v29; // rax
  signed __int64 v30; // rcx
  signed __int64 v31; // rax
  UFG::AiDriverComponent *v32; // rdx
  SSInvokedCoroutine *v33; // rcx
  UFG::qVector3 pos; // [rsp+20h] [rbp-48h]
  UFG::qVector3 result; // [rsp+30h] [rbp-38h]

  v2 = this;
  v3 = (UFG::RoadSpaceComponent *)this->m_pRoadSpaceComponent.m_pPointer;
  if ( !v3 || !v2->m_pAIComponent.m_pPointer )
    return 0;
  if ( (unsigned __int8)UFG::RoadSpaceComponent::IsNavGuideEnabled(v3) )
  {
    v4 = UFG::AiDriverComponent::UpdatePathingNavigation((UFG::AiDriverComponent *)v2->m_pAIComponent.m_pPointer);
    if ( v4 )
    {
      v5 = (UFG::AiDriverComponent *)v2->m_pAIComponent.m_pPointer;
      v6 = v5->m_DriveToCoroutine.i_obj_p;
      if ( v6 )
      {
        v7 = v6->i_ptr_id;
        if ( v5->m_DriveToCoroutine.i_ptr_id == (_DWORD)v7 )
        {
          LOBYTE(v7) = 1;
          ((void (__fastcall *)(SSInvokedCoroutine *, __int64))v6->vfptr[1].get_topmost_scope)(v6, v7);
        }
      }
      UFG::AiDriverComponent::SetDrivingMode((UFG::AiDriverComponent *)v2->m_pAIComponent.m_pPointer, 5u);
    }
    v8 = v4 == 0;
  }
  else
  {
    v9 = (UFG::VehicleWayFinderClient *)&v2->m_pRoadSpaceComponent.m_pPointer[8].m_pSimObject;
    v10 = UFG::WheeledVehicleNavigationData::GetRoadWayFinder(
            UFG::WheeledVehicleManager::m_Instance->m_NavigationData,
            v9);
    if ( !v9->m_NumWayEdges || UFG::WayFinderClient::LostWay((UFG::WayFinderClient *)&v9->vfptr, v10->m_WayGraph) )
    {
      v11 = Scaleform::GFx::AS3::Instances::fl::XML::GetName((UFG::RoadNetworkGuide *)&v2->m_pRoadSpaceComponent.m_pPointer[5].m_BoundComponentHandles.mNode.mNext);
      if ( UFG::RoadNetworkLocation::GetRoadNetworkNode(v11)->mType.mValue != 1 )
        CarGoToTask::FindWay(v2);
    }
    v12 = (UFG::AiDriverComponent *)v2->m_pAIComponent.m_pPointer;
    if ( 0 == v9->m_NumWayEdges )
      UFG::AiDriverComponent::UpdateWanderingNavigation(v12);
    else
      UFG::AiDriverComponent::UpdateWayfindingNavigation(v12);
    if ( UFG::AiDriverComponent::IsTransit((UFG::AiDriverComponent *)v2->m_pAIComponent.m_pPointer) )
    {
      v8 = 1;
    }
    else
    {
      v13 = (float *)v2->m_pRoadSpaceComponent.m_pPointer;
      v14 = v13[413];
      v15 = v13[414];
      v16 = v13[412];
      v17 = v2->m_pActionContext;
      pos.x = v16;
      pos.y = v14;
      pos.z = v15;
      v18 = v17->mSimObject.m_pPointer;
      if ( v18 )
        v19 = v18->m_pTransformNodeComponent;
      else
        v19 = 0i64;
      UFG::TransformNodeComponent::UpdateWorldTransform(v19);
      v20 = 0;
      if ( (float)((float)((float)((float)(pos.y - v19->mWorldTransform.v3.y)
                                 * (float)(pos.y - v19->mWorldTransform.v3.y))
                         + (float)((float)(pos.x - v19->mWorldTransform.v3.x)
                                 * (float)(pos.x - v19->mWorldTransform.v3.x)))
                 + (float)((float)(pos.z - v19->mWorldTransform.v3.z) * (float)(pos.z - v19->mWorldTransform.v3.z))) < (float)(*((float *)&v2->m_pAIComponent.m_pPointer[23].m_BoundComponentHandles.mNode.mPrev + 1) * *((float *)&v2->m_pAIComponent.m_pPointer[23].m_BoundComponentHandles.mNode.mPrev + 1)) )
        goto LABEL_41;
      if ( v9->m_CurrEdgeIndex == v9->m_NumWayEdges - 1 )
      {
        v21 = (UFG::RoadNetworkGuide *)&v2->m_pRoadSpaceComponent.m_pPointer[5].m_BoundComponentHandles.mNode.mNext;
        v22 = Scaleform::GFx::AS3::Instances::fl::XML::GetName(v21);
        v23 = UFG::RoadNetworkLocation::GetRoadNetworkNode(v22);
        v24 = UFG::RoadNetworkNode::GetClosestLane(v23, &pos);
        v25 = Scaleform::GFx::AS3::Instances::fl::XML::GetName(v21)->m_LaneT;
        v26 = v24->mStartGate.mOffset;
        if ( v26 )
          v27 = (signed __int64)&v24->mStartGate + v26;
        else
          v27 = 0i64;
        v28 = Scaleform::GFx::AS3::Instances::fl::XML::GetName(v21)->m_CurrentLane;
        v29 = v28->mStartGate.mOffset;
        v30 = (signed __int64)&v28->mStartGate;
        if ( v29 )
          v31 = v30 + v29;
        else
          v31 = 0i64;
        if ( v27 != v31 )
          v25 = 1.0 - v25;
        UFG::RoadNetworkLane::GetPos(v24, &result, v25);
        if ( (float)((float)((float)((float)(result.y - pos.y) * (float)(result.y - pos.y))
                           + (float)((float)(result.x - pos.x) * (float)(result.x - pos.x)))
                   + (float)((float)(result.z - pos.z) * (float)(result.z - pos.z))) < 100.0 )
        {
LABEL_41:
          v32 = (UFG::AiDriverComponent *)v2->m_pAIComponent.m_pPointer;
          v20 = 1;
          v33 = v32->m_DriveToCoroutine.i_obj_p;
          if ( v33 && v32->m_DriveToCoroutine.i_ptr_id == v33->i_ptr_id )
            ((void (__fastcall *)(SSInvokedCoroutine *, signed __int64))v33->vfptr[1].get_topmost_scope)(v33, 1i64);
          UFG::AiDriverComponent::SetDrivingMode((UFG::AiDriverComponent *)v2->m_pAIComponent.m_pPointer, 5u);
        }
      }
      v8 = v20 == 0;
    }
  }
  return v8;
}

// File Line: 762
// RVA: 0x677C00
void __fastcall CarGoToTask::End(CarGoToTask *this)
{
  CarGoToTask *v1; // rbx
  UFG::RoadSpaceComponent *v2; // rcx
  UFG::SimComponent *v3; // rbx

  v1 = this;
  v2 = (UFG::RoadSpaceComponent *)this->m_pRoadSpaceComponent.m_pPointer;
  if ( v2 )
  {
    if ( (unsigned __int8)UFG::RoadSpaceComponent::IsNavGuideEnabled(v2) )
    {
      UFG::AiDriverComponent::EndPathingNavigation((UFG::AiDriverComponent *)v1->m_pAIComponent.m_pPointer);
    }
    else
    {
      v3 = v1->m_pRoadSpaceComponent.m_pPointer;
      UFG::WayFinderClient::Reset((UFG::WayFinderClient *)&v3[8].m_pSimObject);
      ((void (__fastcall *)(UFG::SimObject **))v3[8].m_pSimObject->m_pTransformNodeComponent)(&v3[8].m_pSimObject);
    }
  }
}

// File Line: 788
// RVA: 0x667790
void __fastcall CarNoDestinationTask::CarNoDestinationTask(CarNoDestinationTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AiDriverComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<CarNoDestinationTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&CarNoDestinationTask::`vftable;
  v2 = &this->m_pAIComponent;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  this->m_pAIComponent.m_pPointer = 0i64;
  this->m_pActionContext = 0i64;
  if ( this->m_pAIComponent.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  }
  v2->m_pPointer = 0i64;
}

// File Line: 797
// RVA: 0x6718F0
void __fastcall CarNoDestinationTask::Begin(CarNoDestinationTask *this, ActionContext *action_context)
{
  CarNoDestinationTask *v2; // rbx
  UFG::SimObjectCVBase *v3; // rcx
  UFG::AiDriverComponent *v4; // r8
  unsigned __int16 v5; // dx
  UFG::AiDriverComponent *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AiDriverComponent> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::SimComponent *v11; // rcx
  UFG::SimObjectGame *v12; // rcx
  unsigned __int16 v13; // dx
  UFG::RoadSpaceComponent *v14; // rbx
  UFG::SimComponent *v15; // rax

  v2 = this;
  this->m_pActionContext = action_context;
  if ( action_context )
  {
    v3 = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
    if ( v3 )
    {
      v5 = v3->m_Flags;
      if ( (v5 >> 14) & 1 )
      {
        v6 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v3);
      }
      else if ( (v5 & 0x8000u) == 0 )
      {
        if ( (v5 >> 13) & 1 )
        {
          v6 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           (UFG::SimObjectGame *)&v3->vfptr,
                                           UFG::AiDriverComponent::_TypeUID);
        }
        else if ( (v5 >> 12) & 1 )
        {
          v6 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           (UFG::SimObjectGame *)&v3->vfptr,
                                           UFG::AiDriverComponent::_TypeUID);
        }
        else
        {
          v6 = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                           (UFG::SimObject *)&v3->vfptr,
                                           UFG::AiDriverComponent::_TypeUID);
        }
      }
      else
      {
        v6 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v3);
      }
      v4 = v6;
    }
    else
    {
      v4 = 0i64;
    }
    v7 = &v2->m_pAIComponent;
    if ( v2->m_pAIComponent.m_pPointer )
    {
      v8 = v7->mPrev;
      v9 = v2->m_pAIComponent.mNext;
      v8->mNext = v9;
      v9->mPrev = v8;
      v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
      v2->m_pAIComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pAIComponent.mPrev;
    }
    v2->m_pAIComponent.m_pPointer = (UFG::SimComponent *)&v4->vfptr;
    if ( v4 )
    {
      v10 = v4->m_SafePointerList.mNode.mPrev;
      v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
      v7->mPrev = v10;
      v2->m_pAIComponent.mNext = &v4->m_SafePointerList.mNode;
      v4->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    }
    v11 = v2->m_pAIComponent.m_pPointer;
    if ( v11 )
    {
      if ( !(unsigned __int8)v11->vfptr[16].__vecDelDtor(
                               (UFG::qSafePointerNode<UFG::SimComponent> *)&v11->vfptr,
                               (unsigned int)v7)
        && !UFG::AiDriverComponent::IsTaxi((UFG::AiDriverComponent *)v2->m_pAIComponent.m_pPointer) )
      {
        v12 = (UFG::SimObjectGame *)v2->m_pActionContext->mSimObject.m_pPointer;
        if ( v12 )
        {
          v13 = v12->m_Flags;
          if ( (v13 >> 14) & 1 )
          {
            v14 = (UFG::RoadSpaceComponent *)v12->m_Components.p[24].m_pComponent;
          }
          else if ( (v13 & 0x8000u) == 0 )
          {
            if ( (v13 >> 13) & 1 )
            {
              v15 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::RoadSpaceComponent::_TypeUID);
            }
            else if ( (v13 >> 12) & 1 )
            {
              v15 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::RoadSpaceComponent::_TypeUID);
            }
            else
            {
              v15 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v12->vfptr, UFG::RoadSpaceComponent::_TypeUID);
            }
            v14 = (UFG::RoadSpaceComponent *)v15;
          }
          else
          {
            v14 = (UFG::RoadSpaceComponent *)v12->m_Components.p[24].m_pComponent;
          }
          if ( v14 )
          {
            if ( (unsigned __int8)UFG::RoadSpaceComponent::IsAttachedToRoadNetwork(v14) )
              UFG::RoadSpaceComponent::DetachFromRoadNetwork(v14);
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
  UFG::qNode<ITask,ITask> *v1; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<CarAttackTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&CarAttackTask::`vftable;
  this->m_pActionContext = 0i64;
}

// File Line: 857
// RVA: 0x671020
void __fastcall CarAttackTask::Begin(CarAttackTask *this, ActionContext *action_context)
{
  ITrack *v2; // rdi
  CarAttackTask *v3; // rbx
  UFG::SimObjectCVBase *v4; // rcx
  unsigned __int16 v5; // dx
  UFG::AiDriverComponent *v6; // rax

  v2 = this->m_Track;
  v3 = this;
  this->m_pActionContext = action_context;
  if ( action_context )
  {
    v4 = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
    if ( v4 )
    {
      v5 = v4->m_Flags;
      if ( (v5 >> 14) & 1 )
      {
        v6 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v4);
      }
      else if ( (v5 & 0x8000u) == 0 )
      {
        if ( (v5 >> 13) & 1 )
        {
          v6 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           (UFG::SimObjectGame *)&v4->vfptr,
                                           UFG::AiDriverComponent::_TypeUID);
        }
        else if ( (v5 >> 12) & 1 )
        {
          v6 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           (UFG::SimObjectGame *)&v4->vfptr,
                                           UFG::AiDriverComponent::_TypeUID);
        }
        else
        {
          v6 = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                           (UFG::SimObject *)&v4->vfptr,
                                           UFG::AiDriverComponent::_TypeUID);
        }
      }
      else
      {
        v6 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v4);
      }
      if ( v6 )
        UFG::AiDriverComponent::BeginAttack(v6, (CarCombat::Attack)LOBYTE(v2[1].vfptr));
    }
    v3->m_fTime = 0.0;
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
  ITrack *v3; // rax

  v2 = timestep + this->m_fTime;
  v3 = this->m_Track;
  this->m_fTime = v2;
  return v2 <= *((float *)&v3[1].vfptr + 1);
}

// File Line: 888
// RVA: 0x677940
void __fastcall CarAttackTask::End(CarAttackTask *this)
{
  ActionContext *v1; // rcx
  UFG::SimObjectCVBase *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::AiDriverComponent *v4; // rax

  v1 = this->m_pActionContext;
  if ( v1 )
  {
    v2 = (UFG::SimObjectCVBase *)v1->mSimObject.m_pPointer;
    if ( v2 )
    {
      v3 = v2->m_Flags;
      if ( (v3 >> 14) & 1 )
      {
        v4 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v2);
      }
      else if ( (v3 & 0x8000u) == 0 )
      {
        if ( (v3 >> 13) & 1 )
        {
          v4 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           (UFG::SimObjectGame *)&v2->vfptr,
                                           UFG::AiDriverComponent::_TypeUID);
        }
        else if ( (v3 >> 12) & 1 )
        {
          v4 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           (UFG::SimObjectGame *)&v2->vfptr,
                                           UFG::AiDriverComponent::_TypeUID);
        }
        else
        {
          v4 = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                           (UFG::SimObject *)&v2->vfptr,
                                           UFG::AiDriverComponent::_TypeUID);
        }
      }
      else
      {
        v4 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v2);
      }
      if ( v4 )
        UFG::AiDriverComponent::EndAttack(v4);
    }
  }
}

// File Line: 907
// RVA: 0x6672B0
void __fastcall CarFormationAttackTask::CarFormationAttackTask(CarFormationAttackTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<CarFormationAttackTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&CarFormationAttackTask::`vftable;
  this->m_pActionContext = 0i64;
}

// File Line: 915
// RVA: 0x671270
void __fastcall CarFormationAttackTask::Begin(CarFormationAttackTask *this, ActionContext *action_context)
{
  ITrack *v2; // rdi
  CarFormationAttackTask *v3; // rbx
  UFG::SimObjectGame *v4; // rcx
  unsigned __int16 v5; // dx
  UFG::RoadSpaceComponent *v6; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rax

  v2 = this->m_Track;
  v3 = this;
  this->m_pActionContext = action_context;
  v4 = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  if ( v4 )
  {
    v5 = v4->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = (UFG::RoadSpaceComponent *)v4->m_Components.p[24].m_pComponent;
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v6 = (UFG::RoadSpaceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::RoadSpaceComponent::_TypeUID);
      }
      else if ( (v5 >> 12) & 1 )
      {
        v6 = (UFG::RoadSpaceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::RoadSpaceComponent::_TypeUID);
      }
      else
      {
        v6 = (UFG::RoadSpaceComponent *)UFG::SimObject::GetComponentOfType(
                                          (UFG::SimObject *)&v4->vfptr,
                                          UFG::RoadSpaceComponent::_TypeUID);
      }
    }
    else
    {
      v6 = (UFG::RoadSpaceComponent *)v4->m_Components.p[24].m_pComponent;
    }
    if ( v6 )
    {
      v7 = UFG::RoadSpaceComponent::GetCarChaseTargetFormation(v6);
      if ( v7 )
        HIDWORD(v7[36].mPrev) = LOBYTE(v2[1].vfptr);
    }
  }
  v3->m_fTime = 0.0;
}

// File Line: 950
// RVA: 0x6779D0
void __fastcall CarFormationAttackTask::End(CarFormationAttackTask *this)
{
  CarFormationAttackTask *v1; // rbx
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::RoadSpaceComponent *v4; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rax

  v1 = this;
  v2 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = (UFG::RoadSpaceComponent *)v2->m_Components.p[24].m_pComponent;
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
      {
        v4 = (UFG::RoadSpaceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::RoadSpaceComponent::_TypeUID);
      }
      else if ( (v3 >> 12) & 1 )
      {
        v4 = (UFG::RoadSpaceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::RoadSpaceComponent::_TypeUID);
      }
      else
      {
        v4 = (UFG::RoadSpaceComponent *)UFG::SimObject::GetComponentOfType(
                                          (UFG::SimObject *)&v2->vfptr,
                                          UFG::RoadSpaceComponent::_TypeUID);
      }
    }
    else
    {
      v4 = (UFG::RoadSpaceComponent *)v2->m_Components.p[24].m_pComponent;
    }
    if ( v4 )
    {
      v5 = UFG::RoadSpaceComponent::GetCarChaseTargetFormation(v4);
      if ( v5 )
        UFG::VehicleFormations::EndAttack((UFG::VehicleFormations *)v5, v1->m_pActionContext->mSimObject.m_pPointer);
    }
  }
}

// File Line: 971
// RVA: 0x6674E0
void __fastcall CarFormationTask::CarFormationTask(CarFormationTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<CarFormationTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&CarFormationTask::`vftable;
  this->m_pActionContext = 0i64;
}

// File Line: 979
// RVA: 0x6714D0
void __fastcall CarFormationTask::Begin(CarFormationTask *this, ActionContext *action_context)
{
  ITrack *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rdx
  char v8; // cl
  char v9; // cl
  char v10; // al
  char v11; // al
  char v12; // al
  char v13; // al
  char v14; // al

  v2 = this->m_Track;
  this->m_pActionContext = action_context;
  if ( action_context )
  {
    v3 = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
    if ( v3 )
    {
      v4 = v3->m_Flags;
      if ( (v4 >> 14) & 1 )
      {
        v5 = v3->m_Components.p[24].m_pComponent;
      }
      else if ( (v4 & 0x8000u) == 0 )
      {
        if ( (v4 >> 13) & 1 )
        {
          v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RoadSpaceComponent::_TypeUID);
        }
        else if ( (v4 >> 12) & 1 )
        {
          v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RoadSpaceComponent::_TypeUID);
        }
        else
        {
          v5 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::RoadSpaceComponent::_TypeUID);
        }
      }
      else
      {
        v5 = v3->m_Components.p[24].m_pComponent;
      }
      if ( v5 )
      {
        v5[30].m_TypeUID |= 2u;
        v6 = UFG::RoadSpaceComponent::GetCarChaseTargetFormation((UFG::RoadSpaceComponent *)v5);
        v7 = v6;
        if ( v6 )
        {
          v8 = LOBYTE(v2[1].vfptr) != 0;
          BYTE2(v6[28].mPrev) += v8;
          BYTE1(v6[28].mNext) += v8;
          BYTE6(v6[38].mPrev) = 1;
          v9 = BYTE1(v2[1].vfptr) != 0;
          BYTE3(v6[28].mPrev) += v9;
          BYTE2(v6[28].mNext) += v9;
          BYTE6(v6[38].mPrev) = 1;
          v10 = BYTE2(v2[1].vfptr) != 0;
          BYTE4(v7[28].mPrev) += v10;
          BYTE3(v7[28].mNext) += v10;
          BYTE6(v7[38].mPrev) = 1;
          v11 = BYTE3(v2[1].vfptr) != 0;
          BYTE5(v7[28].mPrev) += v11;
          BYTE4(v7[28].mNext) += v11;
          BYTE6(v7[38].mPrev) = 1;
          v12 = BYTE4(v2[1].vfptr) != 0;
          BYTE6(v7[28].mPrev) += v12;
          BYTE5(v7[28].mNext) += v12;
          BYTE6(v7[38].mPrev) = 1;
          v13 = BYTE5(v2[1].vfptr) != 0;
          HIBYTE(v7[28].mPrev) += v13;
          BYTE6(v7[28].mNext) += v13;
          BYTE6(v7[38].mPrev) = 1;
          v14 = BYTE6(v2[1].vfptr) != 0;
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
  ITrack *v1; // rbx
  ActionContext *v2; // rcx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::RoadSpaceComponent *v5; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // r8
  char v8; // dl
  char v9; // cl
  char v10; // cl
  char v11; // cl
  char v12; // cl
  char v13; // cl
  char v14; // al

  v1 = this->m_Track;
  v2 = this->m_pActionContext;
  if ( v2 )
  {
    v3 = (UFG::SimObjectGame *)v2->mSimObject.m_pPointer;
    if ( v3 )
    {
      v4 = v3->m_Flags;
      if ( (v4 >> 14) & 1 )
      {
        v5 = (UFG::RoadSpaceComponent *)v3->m_Components.p[24].m_pComponent;
      }
      else if ( (v4 & 0x8000u) == 0 )
      {
        if ( (v4 >> 13) & 1 )
        {
          v5 = (UFG::RoadSpaceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                            v3,
                                            UFG::RoadSpaceComponent::_TypeUID);
        }
        else if ( (v4 >> 12) & 1 )
        {
          v5 = (UFG::RoadSpaceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                            v3,
                                            UFG::RoadSpaceComponent::_TypeUID);
        }
        else
        {
          v5 = (UFG::RoadSpaceComponent *)UFG::SimObject::GetComponentOfType(
                                            (UFG::SimObject *)&v3->vfptr,
                                            UFG::RoadSpaceComponent::_TypeUID);
        }
      }
      else
      {
        v5 = (UFG::RoadSpaceComponent *)v3->m_Components.p[24].m_pComponent;
      }
      if ( v5 )
      {
        v6 = UFG::RoadSpaceComponent::GetCarChaseTargetFormation(v5);
        v7 = v6;
        if ( v6 )
        {
          v8 = -(LOBYTE(v1[1].vfptr) != 0);
          BYTE2(v6[28].mPrev) -= LOBYTE(v1[1].vfptr) != 0;
          BYTE1(v6[28].mNext) += v8;
          BYTE6(v6[38].mPrev) = 1;
          v9 = BYTE1(v1[1].vfptr);
          BYTE3(v6[28].mPrev) -= v9 != 0;
          BYTE2(v6[28].mNext) -= v9 != 0;
          BYTE6(v6[38].mPrev) = 1;
          v10 = -(BYTE2(v1[1].vfptr) != 0);
          BYTE4(v6[28].mPrev) -= BYTE2(v1[1].vfptr) != 0;
          BYTE3(v6[28].mNext) += v10;
          BYTE6(v6[38].mPrev) = 1;
          v11 = -(BYTE3(v1[1].vfptr) != 0);
          BYTE5(v6[28].mPrev) -= BYTE3(v1[1].vfptr) != 0;
          BYTE4(v6[28].mNext) += v11;
          BYTE6(v6[38].mPrev) = 1;
          v12 = -(BYTE4(v1[1].vfptr) != 0);
          BYTE6(v6[28].mPrev) -= BYTE4(v1[1].vfptr) != 0;
          BYTE5(v6[28].mNext) += v12;
          BYTE6(v6[38].mPrev) = 1;
          v13 = -(BYTE5(v1[1].vfptr) != 0);
          HIBYTE(v6[28].mPrev) -= BYTE5(v1[1].vfptr) != 0;
          BYTE6(v6[28].mNext) += v13;
          BYTE6(v6[38].mPrev) = 1;
          v14 = -BYTE6(v1[1].vfptr);
          LOBYTE(v7[28].mNext) -= BYTE6(v1[1].vfptr) != 0;
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
  UFG::qNode<ITask,ITask> *v1; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AiDriverComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<CarOffsetDriveTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&CarOffsetDriveTask::`vftable;
  v2 = &this->m_pAIComponent;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  this->m_pAIComponent.m_pPointer = 0i64;
  this->m_pActionContext = 0i64;
  if ( this->m_pAIComponent.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  }
  v2->m_pPointer = 0i64;
}

// File Line: 1048
// RVA: 0x671C40
void __fastcall CarOffsetDriveTask::Begin(CarOffsetDriveTask *this, ActionContext *action_context)
{
  ITrack *v2; // rbp
  CarOffsetDriveTask *v3; // rsi
  UFG::SimObjectGame *v4; // rcx
  UFG::AiDriverComponent *v5; // rdi
  UFG::RoadSpaceComponent *v6; // rbx
  unsigned __int16 v7; // dx
  UFG::SimComponent *v8; // rax
  UFG::WayFinder *v9; // rax
  UFG::SimObjectCVBase *v10; // rcx
  unsigned __int16 v11; // dx
  UFG::AiDriverComponent *v12; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AiDriverComponent> *v13; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax

  v2 = this->m_Track;
  v3 = this;
  this->m_pActionContext = action_context;
  if ( action_context )
  {
    v4 = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
    v5 = 0i64;
    if ( v4 )
    {
      v7 = v4->m_Flags;
      if ( (v7 >> 14) & 1 )
      {
        v6 = (UFG::RoadSpaceComponent *)v4->m_Components.p[24].m_pComponent;
      }
      else if ( (v7 & 0x8000u) == 0 )
      {
        if ( (v7 >> 13) & 1 )
        {
          v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::RoadSpaceComponent::_TypeUID);
        }
        else if ( (v7 >> 12) & 1 )
        {
          v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::RoadSpaceComponent::_TypeUID);
        }
        else
        {
          v8 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::RoadSpaceComponent::_TypeUID);
        }
        v6 = (UFG::RoadSpaceComponent *)v8;
      }
      else
      {
        v6 = (UFG::RoadSpaceComponent *)v4->m_Components.p[24].m_pComponent;
      }
    }
    else
    {
      v6 = 0i64;
    }
    if ( (unsigned __int8)UFG::RoadSpaceComponent::IsAttachedToRoadNetwork(v6) )
      UFG::RoadSpaceComponent::DetachFromRoadNetwork(v6);
    if ( v6 )
    {
      v9 = UFG::WheeledVehicleNavigationData::GetRoadWayFinder(
             UFG::WheeledVehicleManager::m_Instance->m_NavigationData,
             &v6->mWayClient);
      UFG::WayFinder::Cancel(v9, (UFG::WayFinderClient *)&v6->mWayClient.vfptr);
    }
    v10 = (UFG::SimObjectCVBase *)v3->m_pActionContext->mSimObject.m_pPointer;
    if ( v10 )
    {
      v11 = v10->m_Flags;
      if ( (v11 >> 14) & 1 )
      {
        v12 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v10);
      }
      else if ( (v11 & 0x8000u) == 0 )
      {
        if ( (v11 >> 13) & 1 )
        {
          v12 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                            (UFG::SimObjectGame *)&v10->vfptr,
                                            UFG::AiDriverComponent::_TypeUID);
        }
        else if ( (v11 >> 12) & 1 )
        {
          v12 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                            (UFG::SimObjectGame *)&v10->vfptr,
                                            UFG::AiDriverComponent::_TypeUID);
        }
        else
        {
          v12 = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                            (UFG::SimObject *)&v10->vfptr,
                                            UFG::AiDriverComponent::_TypeUID);
        }
      }
      else
      {
        v12 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v10);
      }
      v5 = v12;
    }
    v13 = &v3->m_pAIComponent;
    if ( v3->m_pAIComponent.m_pPointer )
    {
      v14 = v13->mPrev;
      v15 = v3->m_pAIComponent.mNext;
      v14->mNext = v15;
      v15->mPrev = v14;
      v13->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v13->mPrev;
      v3->m_pAIComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->m_pAIComponent.mPrev;
    }
    v3->m_pAIComponent.m_pPointer = (UFG::SimComponent *)&v5->vfptr;
    if ( v5 )
    {
      v16 = v5->m_SafePointerList.mNode.mPrev;
      v16->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v13->mPrev;
      v13->mPrev = v16;
      v3->m_pAIComponent.mNext = &v5->m_SafePointerList.mNode;
      v5->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v13->mPrev;
    }
    UFG::AiDriverComponent::SetFollowOffset(
      (UFG::AiDriverComponent *)v3->m_pAIComponent.m_pPointer,
      AnySide,
      (CarCombat::Position)BYTE4(v2[1].vfptr),
      *(float *)&v2[1].vfptr);
  }
}

// File Line: 1102
// RVA: 0x667390
void __fastcall CarFormationDriveTask::CarFormationDriveTask(CarFormationDriveTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AiDriverComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<CarFormationDriveTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&CarFormationDriveTask::`vftable;
  v2 = &this->m_pAIComponent;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  this->m_pAIComponent.m_pPointer = 0i64;
  this->m_pActionContext = 0i64;
  if ( this->m_pAIComponent.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  }
  v2->m_pPointer = 0i64;
}

// File Line: 1111
// RVA: 0x671330
void __fastcall CarFormationDriveTask::Begin(CarFormationDriveTask *this, ActionContext *action_context)
{
  CarFormationDriveTask *v2; // rsi
  UFG::SimObjectGame *v3; // rcx
  UFG::AiDriverComponent *v4; // rdi
  UFG::RoadSpaceComponent *v5; // rbx
  unsigned __int16 v6; // dx
  UFG::SimComponent *v7; // rax
  UFG::WayFinder *v8; // rax
  UFG::SimObjectCVBase *v9; // rcx
  unsigned __int16 v10; // dx
  UFG::AiDriverComponent *v11; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AiDriverComponent> *v12; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rax

  v2 = this;
  this->m_pActionContext = action_context;
  if ( action_context )
  {
    v3 = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
    v4 = 0i64;
    if ( v3 )
    {
      v6 = v3->m_Flags;
      if ( (v6 >> 14) & 1 )
      {
        v5 = (UFG::RoadSpaceComponent *)v3->m_Components.p[24].m_pComponent;
      }
      else if ( (v6 & 0x8000u) == 0 )
      {
        if ( (v6 >> 13) & 1 )
        {
          v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RoadSpaceComponent::_TypeUID);
        }
        else if ( (v6 >> 12) & 1 )
        {
          v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RoadSpaceComponent::_TypeUID);
        }
        else
        {
          v7 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::RoadSpaceComponent::_TypeUID);
        }
        v5 = (UFG::RoadSpaceComponent *)v7;
      }
      else
      {
        v5 = (UFG::RoadSpaceComponent *)v3->m_Components.p[24].m_pComponent;
      }
    }
    else
    {
      v5 = 0i64;
    }
    if ( (unsigned __int8)UFG::RoadSpaceComponent::IsAttachedToRoadNetwork(v5) )
      UFG::RoadSpaceComponent::DetachFromRoadNetwork(v5);
    if ( v5 )
    {
      v8 = UFG::WheeledVehicleNavigationData::GetRoadWayFinder(
             UFG::WheeledVehicleManager::m_Instance->m_NavigationData,
             &v5->mWayClient);
      UFG::WayFinder::Cancel(v8, (UFG::WayFinderClient *)&v5->mWayClient.vfptr);
    }
    v9 = (UFG::SimObjectCVBase *)v2->m_pActionContext->mSimObject.m_pPointer;
    if ( v9 )
    {
      v10 = v9->m_Flags;
      if ( (v10 >> 14) & 1 )
      {
        v11 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v9);
      }
      else if ( (v10 & 0x8000u) == 0 )
      {
        if ( (v10 >> 13) & 1 )
        {
          v11 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                            (UFG::SimObjectGame *)&v9->vfptr,
                                            UFG::AiDriverComponent::_TypeUID);
        }
        else if ( (v10 >> 12) & 1 )
        {
          v11 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                            (UFG::SimObjectGame *)&v9->vfptr,
                                            UFG::AiDriverComponent::_TypeUID);
        }
        else
        {
          v11 = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                            (UFG::SimObject *)&v9->vfptr,
                                            UFG::AiDriverComponent::_TypeUID);
        }
      }
      else
      {
        v11 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v9);
      }
      v4 = v11;
    }
    v12 = &v2->m_pAIComponent;
    if ( v2->m_pAIComponent.m_pPointer )
    {
      v13 = v12->mPrev;
      v14 = v2->m_pAIComponent.mNext;
      v13->mNext = v14;
      v14->mPrev = v13;
      v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v12->mPrev;
      v2->m_pAIComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pAIComponent.mPrev;
    }
    v2->m_pAIComponent.m_pPointer = (UFG::SimComponent *)&v4->vfptr;
    if ( v4 )
    {
      v15 = v4->m_SafePointerList.mNode.mPrev;
      v15->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v12->mPrev;
      v12->mPrev = v15;
      v2->m_pAIComponent.mNext = &v4->m_SafePointerList.mNode;
      v4->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v12->mPrev;
    }
  }
}

// File Line: 1139
// RVA: 0x68FA00
char __fastcall CarFormationDriveTask::Update(CarFormationDriveTask *this, float timestep)
{
  CarFormationDriveTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rax
  UFG::AiDriverComponent *v6; // rcx

  v2 = this;
  v3 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = v3->m_Components.p[24].m_pComponent;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
        v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RoadSpaceComponent::_TypeUID);
      else
        v5 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RoadSpaceComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::RoadSpaceComponent::_TypeUID);
    }
    else
    {
      v5 = v3->m_Components.p[24].m_pComponent;
    }
    if ( v5 )
      v5[30].m_TypeUID |= 2u;
  }
  v6 = (UFG::AiDriverComponent *)v2->m_pAIComponent.m_pPointer;
  if ( !v6 )
    return 0;
  UFG::AiDriverComponent::UpdateFollowingNavigation(v6, timestep);
  return 1;
}

// File Line: 1169
// RVA: 0x667810
void __fastcall CarOccupantAimTask::CarOccupantAimTask(CarOccupantAimTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<CarOccupantAimTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&CarOccupantAimTask::`vftable;
  v2 = &this->m_pActiveAIEntityComponent;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  this->m_pActiveAIEntityComponent.m_pPointer = 0i64;
  if ( this->m_pActiveAIEntityComponent.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  }
  v2->m_pPointer = 0i64;
}

// File Line: 1176
// RVA: 0x671A80
void __fastcall CarOccupantAimTask::Begin(CarOccupantAimTask *this, ActionContext *action_context)
{
  CarOccupantAimTask *v2; // rbx
  UFG::SimObjectCVBase *v3; // rax
  unsigned __int16 v4; // r8
  UFG::ActiveAIEntityComponent *v5; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v6; // rdx
  UFG::ActiveAIEntityComponent *v7; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax

  v2 = this;
  v3 = (UFG::SimObjectCVBase *)UFG::getTarget(
                                 action_context->mSimObject.m_pPointer,
                                 (UFG::eTargetTypeEnum)LOBYTE(this->m_Track[1].vfptr));
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v3);
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
      {
        v5 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               (UFG::SimObjectGame *)&v3->vfptr,
                                               UFG::ActiveAIEntityComponent::_TypeUID);
      }
      else if ( (v4 >> 12) & 1 )
      {
        v5 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               (UFG::SimObjectGame *)&v3->vfptr,
                                               UFG::ActiveAIEntityComponent::_TypeUID);
      }
      else
      {
        v5 = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                               (UFG::SimObject *)&v3->vfptr,
                                               UFG::ActiveAIEntityComponent::_TypeUID);
      }
    }
    else
    {
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v3);
    }
    v6 = &v2->m_pActiveAIEntityComponent;
    v7 = v5;
    if ( v2->m_pActiveAIEntityComponent.m_pPointer )
    {
      v8 = v6->mPrev;
      v9 = v2->m_pActiveAIEntityComponent.mNext;
      v8->mNext = v9;
      v9->mPrev = v8;
      v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
      v2->m_pActiveAIEntityComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pActiveAIEntityComponent.mPrev;
    }
    v2->m_pActiveAIEntityComponent.m_pPointer = (UFG::SimComponent *)&v7->vfptr;
    if ( v7 )
    {
      v10 = v7->m_SafePointerList.mNode.mPrev;
      v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
      v6->mPrev = v10;
      v2->m_pActiveAIEntityComponent.mNext = &v7->m_SafePointerList.mNode;
      v7->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
    }
  }
}

// File Line: 1191
// RVA: 0x690120
bool __fastcall CarOccupantAimTask::Update(CarOccupantAimTask *this, float timestep)
{
  UFG::SimComponent *v2; // rax
  UFG::SimObject *v3; // rcx
  UFG::SimComponent *v4; // rax
  Intention *v5; // rbx

  v2 = this->m_pActiveAIEntityComponent.m_pPointer;
  if ( v2 )
  {
    v3 = v2->m_pSimObject;
    if ( v3 )
    {
      v4 = UFG::SimObject::GetComponentOfType(v3, UFG::AICharacterControllerBaseComponent::_TypeUID);
      if ( v4 )
      {
        v5 = (Intention *)&v4[2];
        Intention::Set((Intention *)&v4[2], gActionRequest_Focus.m_EnumValue, 0.0);
        Intention::Set(v5, gActionRequest_Aiming.m_EnumValue, 0.0);
      }
    }
    LOBYTE(v2) = 1;
  }
  return (char)v2;
}

// File Line: 1220
// RVA: 0x671BB0
void __fastcall CarOccupantShootTask::Begin(CarOccupantShootTask *this, ActionContext *action_context)
{
  UFG::SimObject *v2; // rax
  UFG::SimComponent *v3; // rax
  Intention *v4; // rbx

  v2 = UFG::getTarget(action_context->mSimObject.m_pPointer, (UFG::eTargetTypeEnum)LOBYTE(this->m_Track[1].vfptr));
  if ( v2 )
  {
    v3 = UFG::SimObject::GetComponentOfType(v2, UFG::AICharacterControllerBaseComponent::_TypeUID);
    if ( v3 )
    {
      v4 = (Intention *)&v3[2];
      Intention::Set((Intention *)&v3[2], gActionRequest_Focus.m_EnumValue, 0.0);
      Intention::Set(v4, gActionRequest_Aiming.m_EnumValue, 0.0);
      Intention::Set(v4, gActionRequest_FireWeapon.m_EnumValue, 0.0);
    }
  }
}

// File Line: 1247
// RVA: 0x671B50
void __fastcall CarOccupantIntentionTask::Begin(CarOccupantIntentionTask *this, ActionContext *action_context)
{
  CarOccupantIntentionTask *v2; // rbx
  UFG::SimObject *v3; // rax
  UFG::SimComponent *v4; // rax

  v2 = this;
  v3 = UFG::getTarget(action_context->mSimObject.m_pPointer, (UFG::eTargetTypeEnum)LOBYTE(this->m_Track[1].vfptr));
  if ( v3 )
  {
    v4 = UFG::SimObject::GetComponentOfType(v3, UFG::AICharacterControllerBaseComponent::_TypeUID);
    if ( v4 )
      Intention::Set((Intention *)&v4[2], HIDWORD(v2->m_Track[1].vfptr), 0.0);
  }
}

// File Line: 1280
// RVA: 0x690190
char __fastcall CarOccupantsActionTask::Update(CarOccupantsActionTask *this, float timestep)
{
  CarOccupantsActionTask *v2; // rbp
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rax
  UFG::VehicleOccupantComponent *v6; // rsi
  UFG::qNode<UFG::CharacterOccupantComponent,UFG::_VehicleOccupantList> **v7; // r14
  int v8; // ecx
  signed __int64 v9; // rax
  signed __int64 v10; // rbx
  unsigned int v12; // edi
  UFG::SimObject *v13; // rcx
  int v14; // er8
  int v15; // edx
  signed __int64 v16; // rax
  signed __int64 i; // rcx
  signed int v18; // edx
  signed __int64 j; // rcx
  signed int k; // ecx
  UFG::SimComponent *v21; // rax

  v2 = this;
  v3 = (UFG::SimObjectGame *)this->mpActionContext->mSimObject.m_pPointer;
  if ( !v3 )
    return 1;
  v4 = v3->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::VehicleOccupantComponent::_TypeUID);
  }
  else
  {
    if ( (v4 & 0x8000u) != 0 )
    {
      v6 = (UFG::VehicleOccupantComponent *)v3->m_Components.p[30].m_pComponent;
      goto LABEL_12;
    }
    if ( (v4 >> 13) & 1 )
    {
      v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::VehicleOccupantComponent::_TypeUID);
    }
    else if ( (v4 >> 12) & 1 )
    {
      v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::VehicleOccupantComponent::_TypeUID);
    }
    else
    {
      v5 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::VehicleOccupantComponent::_TypeUID);
    }
  }
  v6 = (UFG::VehicleOccupantComponent *)v5;
LABEL_12:
  if ( !v6 )
    return 1;
  v7 = &v6->mPassengers.mNode.mNext;
  v8 = 0;
  v9 = (signed __int64)&v6->mPassengers.mNode.mNext[-4];
  v10 = (signed __int64)&v6->m_BoundComponentHandles;
  if ( v6->mpDriver.m_pPointer )
  {
    for ( ; v9 != v10; v9 = *(_QWORD *)(v9 + 72) - 64i64 )
      ++v8;
    ++v8;
  }
  else
  {
    for ( ; v9 != v10; v9 = *(_QWORD *)(v9 + 72) - 64i64 )
      ++v8;
  }
  if ( !v8 )
    return 0;
  v12 = 0;
  if ( (unsigned int)UFG::VehicleOccupantComponent::GetNumberOfOccupants(v6) )
  {
    do
    {
      v13 = v6->mpDriver.m_pPointer;
      if ( v13 )
      {
        if ( !v12 )
          goto LABEL_39;
        v14 = 0;
        v15 = v12 - 1;
        v16 = (signed __int64)&(*v7)[-4];
        for ( i = v16; i != v10; i = *(_QWORD *)(i + 72) - 64i64 )
          ++v14;
        if ( v15 >= v14 )
          goto LABEL_42;
        for ( ; v15 > 0; v16 = *(_QWORD *)(v16 + 72) - 64i64 )
        {
          if ( v16 == v10 )
            break;
          --v15;
        }
      }
      else
      {
        v18 = 0;
        v16 = (signed __int64)&(*v7)[-4];
        for ( j = v16; j != v10; j = *(_QWORD *)(j + 72) - 64i64 )
          ++v18;
        if ( (signed int)v12 >= v18 )
          goto LABEL_42;
        for ( k = v12; k > 0; v16 = *(_QWORD *)(v16 + 72) - 64i64 )
        {
          if ( v16 == v10 )
            break;
          --k;
        }
      }
      v13 = *(UFG::SimObject **)(v16 + 40);
LABEL_39:
      if ( v13 )
      {
        v21 = UFG::SimObject::GetComponentOfType(v13, UFG::AICharacterControllerBaseComponent::_TypeUID);
        if ( v21 )
          Intention::Set((Intention *)&v21[2], (unsigned int)v2->m_Track[1].vfptr, 0.0);
      }
LABEL_42:
      ++v12;
    }
    while ( v12 < (unsigned int)UFG::VehicleOccupantComponent::GetNumberOfOccupants(v6) );
  }
  return 0;
}

// File Line: 1318
// RVA: 0x677C60
void __fastcall CarOccupantsActionTask::End(CarOccupantsActionTask *this)
{
  UFG::SimObjectCVBase *v1; // rcx
  unsigned __int16 v2; // dx
  UFG::AiDriverComponent *v3; // rax
  unsigned int v4; // edx
  UFG::AiDriverComponent *v5; // rax
  bool v6; // zf
  UFG::AiDriverComponent *v7; // rax

  v1 = (UFG::SimObjectCVBase *)this->mpActionContext->mSimObject.m_pPointer;
  if ( !v1 )
  {
    UFG::AiDriverComponent::SetDrivingMode(0i64, 0);
    return;
  }
  v2 = v1->m_Flags;
  if ( (v2 >> 14) & 1 || (v2 & 0x8000u) != 0 )
  {
    v3 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v1);
    UFG::AiDriverComponent::SetDrivingMode(v3, 0);
    return;
  }
  if ( (v2 >> 13) & 1 )
  {
    v4 = UFG::AiDriverComponent::_TypeUID;
LABEL_8:
    v5 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v1->vfptr, v4);
    UFG::AiDriverComponent::SetDrivingMode(v5, 0);
    return;
  }
  v6 = ((v2 >> 12) & 1) == 0;
  v4 = UFG::AiDriverComponent::_TypeUID;
  if ( !v6 )
    goto LABEL_8;
  v7 = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                   (UFG::SimObject *)&v1->vfptr,
                                   UFG::AiDriverComponent::_TypeUID);
  UFG::AiDriverComponent::SetDrivingMode(v7, 0);
}

// File Line: 1329
// RVA: 0x672DF0
void __fastcall SetCarModeTask::Begin(SetCarModeTask *this, ActionContext *action_context)
{
  SetCarModeTask *v2; // rbx
  UFG::SimObjectCVBase *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::AiDriverComponent *v5; // rax

  v2 = this;
  v3 = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v3);
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
      {
        v5 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                         (UFG::SimObjectGame *)&v3->vfptr,
                                         UFG::AiDriverComponent::_TypeUID);
      }
      else if ( (v4 >> 12) & 1 )
      {
        v5 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                         (UFG::SimObjectGame *)&v3->vfptr,
                                         UFG::AiDriverComponent::_TypeUID);
      }
      else
      {
        v5 = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                         (UFG::SimObject *)&v3->vfptr,
                                         UFG::AiDriverComponent::_TypeUID);
      }
    }
    else
    {
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v3);
    }
    if ( v5 )
      UFG::AiDriverComponent::SetDrivingMode(v5, (unsigned int)v2->m_Track[1].vfptr);
  }
}

// File Line: 1342
// RVA: 0x672E80
void __fastcall VehicleAudioEventTask::Begin(VehicleAudioEventTask *this, ActionContext *action_context)
{
  VehicleAudioEventTask *v2; // rsi
  UFG::SimObjectVehicle *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::VehicleAudioComponent *v5; // rax
  hkgpIndexedMeshDefinitions::Edge *v6; // rdx
  hkgpIndexedMesh::EdgeBarrier *v7; // rcx
  UFG::VehicleAudioComponent *v8; // rbx
  float v9; // xmm0_4
  float *v10; // rax
  float v11; // xmm7_4
  float v12; // xmm8_4
  float v13; // xmm6_4
  UFG::DriverReactions *v14; // rdi
  unsigned int v15; // eax
  char v16; // al
  char v17; // al

  v2 = this;
  v3 = (UFG::SimObjectVehicle *)action_context->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = (UFG::VehicleAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           (UFG::SimObjectGame *)&v3->vfptr,
                                           UFG::VehicleAudioComponent::_TypeUID);
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
        v5 = (UFG::VehicleAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             (UFG::SimObjectGame *)&v3->vfptr,
                                             UFG::VehicleAudioComponent::_TypeUID);
      else
        v5 = (UFG::VehicleAudioComponent *)((v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               (UFG::SimObjectGame *)&v3->vfptr,
                                                               UFG::VehicleAudioComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::VehicleAudioComponent::_TypeUID));
    }
    else
    {
      v5 = UFG::SimObjectVehicle::GetComponent<UFG::VehicleAudioComponent>(v3);
    }
    v8 = v5;
    if ( v5 )
    {
      if ( !LODWORD(v2->m_Track[1].vfptr) )
      {
        v9 = UFG::qRandom(1.0, &UFG::qDefaultSeed);
        v10 = (float *)v2->m_Track;
        if ( v9 < v10[15] )
        {
          v11 = v10[16];
          v12 = v10[17];
          v13 = UFG::qRandom(v10[16], &UFG::qDefaultSeed);
          if ( v13 <= v12 )
            v13 = v12;
          if ( v13 >= v11 )
            v13 = v11;
          v14 = v8->m_driverReaction;
          if ( v14 )
          {
            v15 = v14->m_numReactions;
            if ( v15 <= UFG::DriverReactions::sm_NumReactions )
            {
              v14->m_reactionCooldownTimer = 0.0;
              v14->m_numReactions = v15 + 1;
              if ( UFG::qRandom(1.0, &UFG::qDefaultSeed) >= 0.33000001 )
                UFG::VehicleAudioComponent::HonkAmbientHorn(v14->m_pVehAudComponent, v13);
              else
                UFG::DriverReactions::YellReactionBase(v14, eVocalDriverReactionType_BadDriver);
            }
          }
        }
      }
      if ( LODWORD(v2->m_Track[1].vfptr) == 3
        && !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(v7, v6) )
      {
        v16 = *((_BYTE *)v8 + 636);
        if ( !(v16 & 2) )
          *((_BYTE *)v8 + 636) = v16 | 2;
      }
      if ( LODWORD(v2->m_Track[1].vfptr) == 4
        && !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(v7, v6) )
      {
        v17 = *((_BYTE *)v8 + 636);
        if ( v17 & 2 )
          *((_BYTE *)v8 + 636) = v17 & 0xFD;
      }
      if ( LODWORD(v2->m_Track[1].vfptr) == 1 )
        UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&v8->vfptr, 0x2861EDD7u, 0i64, 0, 0i64);
    }
  }
}

// File Line: 1381
// RVA: 0x673070
void __fastcall VehicleEffectTask::Begin(VehicleEffectTask *this, ActionContext *action_context)
{
  UFG::SimComponent *v2; // rax
  VehicleEffectTask *v3; // rbx
  UFG::SimObjectGame *v4; // rcx
  unsigned __int16 v5; // dx
  UFG::VehicleEffectsComponent *v6; // rbx
  UFG::SimComponent *v7; // rcx

  v2 = 0i64;
  v3 = this;
  this->mElapsedTime = 0.0;
  v4 = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  if ( v4 )
  {
    v5 = v4->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v2 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::VehicleEffectsComponent::_TypeUID);
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v2 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::VehicleEffectsComponent::_TypeUID);
      }
      else if ( (v5 >> 12) & 1 )
      {
        v2 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::VehicleEffectsComponent::_TypeUID);
      }
      else
      {
        v2 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::VehicleEffectsComponent::_TypeUID);
      }
    }
    else
    {
      v2 = v4->m_Components.p[32].m_pComponent;
    }
  }
  v3->mRenderComponent = (UFG::VehicleEffectsComponent *)v2;
  if ( v2 )
  {
    v2[29].m_NameUID |= 0x10u;
    if ( !HIDWORD(v3->m_Track[1].vfptr) )
    {
      v6 = v3->mRenderComponent;
      UFG::VehicleEffectsComponent::TurnOffEffect_New(v6, FX_DAYTIME);
      v7 = v6->mVehicleDriverComponent.m_pSimComponent;
      if ( v7 && ((unsigned __int8 (*)(void))v7->vfptr[15].__vecDelDtor)() )
      {
        UFG::VehicleEffectsComponent::TurnOnLightEffects(v6, FX_PLAYERHEADLIGHTS);
        UFG::VehicleEffectsComponent::TurnOnLightEffects(v6, 0);
        UFG::VehicleEffectsComponent::TurnOnLightEffects(v6, FX_PLAYERHEADLIGHTFLARES);
      }
      else
      {
        UFG::VehicleEffectsComponent::TurnOnLightEffects(v6, FX_TRAFFICHEADLIGHTS);
        UFG::VehicleEffectsComponent::TurnOnLightEffects(v6, 0);
        UFG::VehicleEffectsComponent::TurnOnLightEffects(v6, FX_TRAFFICHEADLIGHTFLARES);
      }
    }
  }
}

// File Line: 1398
// RVA: 0x6946D0
char __fastcall VehicleEffectTask::Update(VehicleEffectTask *this, float timestep)
{
  float v2; // xmm0_4
  char result; // al

  v2 = this->mElapsedTime;
  if ( v2 > *(float *)&this->m_Track[1].vfptr )
    return 0;
  result = 1;
  this->mElapsedTime = v2 + timestep;
  return result;
}

// File Line: 1416
// RVA: 0x677D40
void __fastcall VehicleEffectTask::End(VehicleEffectTask *this)
{
  UFG::VehicleEffectsComponent *v1; // rax

  v1 = this->mRenderComponent;
  if ( v1 )
  {
    *((_DWORD *)v1 + 471) &= 0xFFFFFFEF;
    if ( !HIDWORD(this->m_Track[1].vfptr) )
      UFG::VehicleEffectsComponent::TurnOffHeadlights(this->mRenderComponent);
  }
}

// File Line: 1430
// RVA: 0x673350
void __fastcall VehicleQueueHeadlightFlashesTask::Begin(VehicleQueueHeadlightFlashesTask *this, ActionContext *action_context)
{
  VehicleQueueHeadlightFlashesTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  UFG::SimComponent *v4; // r8
  unsigned __int16 v5; // dx
  UFG::SimComponent *v6; // rax
  ITrack *v7; // rax
  signed int v8; // edx
  float v9; // xmm2_4
  UFG::VehicleEffectsComponent *v10; // rcx

  v2 = this;
  v3 = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  if ( !v3 )
  {
    v4 = 0i64;
    goto LABEL_13;
  }
  v5 = v3->m_Flags;
  if ( (v5 >> 14) & 1 )
  {
    v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::VehicleEffectsComponent::_TypeUID);
  }
  else
  {
    if ( (v5 & 0x8000u) != 0 )
    {
      v4 = v3->m_Components.p[32].m_pComponent;
      goto LABEL_13;
    }
    if ( (v5 >> 13) & 1 )
    {
      v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::VehicleEffectsComponent::_TypeUID);
    }
    else if ( (v5 >> 12) & 1 )
    {
      v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::VehicleEffectsComponent::_TypeUID);
    }
    else
    {
      v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::VehicleEffectsComponent::_TypeUID);
    }
  }
  v4 = v6;
LABEL_13:
  v2->mRenderComponent = (UFG::VehicleEffectsComponent *)v4;
  if ( v4 )
  {
    v7 = v2->m_Track;
    v8 = HIDWORD(v7[1].vfptr);
    v9 = *(float *)&v7[1].vfptr;
    v2->mTaskDuration = (float)(*(float *)&v7[1].vfptr * 2.0) * (float)v8;
    v4[29].m_NameUID |= 0x10u;
    v10 = v2->mRenderComponent;
    v10->mNumQueuedHeadlightChanges = 2 * v8;
    v10->mHeadlightFlashesTimer = 0.0;
    v10->mHeadlightFlashesLength = v9;
  }
}

// File Line: 1447
// RVA: 0x694740
char __fastcall VehicleQueueHeadlightFlashesTask::Update(VehicleQueueHeadlightFlashesTask *this, float timestep)
{
  float v2; // xmm0_4
  char result; // al

  v2 = this->mElapsedTime;
  if ( v2 > this->mTaskDuration )
    return 0;
  result = 1;
  this->mElapsedTime = v2 + timestep;
  return result;
}

// File Line: 1464
// RVA: 0x677D70
void __fastcall VehicleQueueHeadlightFlashesTask::End(VehicleQueueHeadlightFlashesTask *this)
{
  UFG::VehicleEffectsComponent *v1; // rax

  v1 = this->mRenderComponent;
  if ( v1 )
    *((_DWORD *)v1 + 471) &= 0xFFFFFFEF;
}

// File Line: 1475
// RVA: 0x673190
void __fastcall VehicleEnableTemporaryPassTask::Begin(VehicleEnableTemporaryPassTask *this, ActionContext *action_context)
{
  UFG::SimObjectCVBase *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::AiDriverComponent *v4; // rax

  v2 = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v2);
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
      {
        v4 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                         (UFG::SimObjectGame *)&v2->vfptr,
                                         UFG::AiDriverComponent::_TypeUID);
      }
      else if ( (v3 >> 12) & 1 )
      {
        v4 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                         (UFG::SimObjectGame *)&v2->vfptr,
                                         UFG::AiDriverComponent::_TypeUID);
      }
      else
      {
        v4 = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                         (UFG::SimObject *)&v2->vfptr,
                                         UFG::AiDriverComponent::_TypeUID);
      }
    }
    else
    {
      v4 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v2);
    }
    if ( v4 )
      UFG::AiDriverComponent::EnableTemporaryPassing(v4);
  }
}

// File Line: 1486
// RVA: 0x673210
void __fastcall VehicleOnDeadDriverStopTask::Begin(VehicleOnDeadDriverStopTask *this, ActionContext *actionContext)
{
  UFG::SimObjectCVBase *v2; // rcx
  ActionContext *v3; // rdi
  unsigned __int16 v4; // r8
  UFG::AiDriverComponent *v5; // rax
  UFG::AiDriverComponent *v6; // rbx
  UFG::SimObjectGame *v7; // rcx
  unsigned __int16 v8; // dx
  UFG::RoadSpaceComponent *v9; // rbx
  UFG::SimComponent *v10; // rax

  v2 = (UFG::SimObjectCVBase *)actionContext->mSimObject.m_pPointer;
  v3 = actionContext;
  if ( v2 )
  {
    v4 = v2->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v2);
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
        v5 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                         (UFG::SimObjectGame *)&v2->vfptr,
                                         UFG::AiDriverComponent::_TypeUID);
      else
        v5 = (UFG::AiDriverComponent *)((v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                           (UFG::SimObjectGame *)&v2->vfptr,
                                                           UFG::AiDriverComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                                 (UFG::SimObject *)&v2->vfptr,
                                                                                                 UFG::AiDriverComponent::_TypeUID));
    }
    else
    {
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v2);
    }
    v6 = v5;
    if ( v5 )
    {
      if ( ((unsigned __int8 (__fastcall *)(UFG::AiDriverComponent *))v5->vfptr[16].__vecDelDtor)(v5) )
        v6->m_IsAmbient = 0;
    }
  }
  v7 = (UFG::SimObjectGame *)v3->mSimObject.m_pPointer;
  if ( v7 )
  {
    v8 = v7->m_Flags;
    if ( (v8 >> 14) & 1 )
    {
      v9 = (UFG::RoadSpaceComponent *)v7->m_Components.p[24].m_pComponent;
    }
    else if ( (v8 & 0x8000u) == 0 )
    {
      if ( (v8 >> 13) & 1 )
      {
        v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RoadSpaceComponent::_TypeUID);
      }
      else if ( (v8 >> 12) & 1 )
      {
        v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RoadSpaceComponent::_TypeUID);
      }
      else
      {
        v10 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::RoadSpaceComponent::_TypeUID);
      }
      v9 = (UFG::RoadSpaceComponent *)v10;
    }
    else
    {
      v9 = (UFG::RoadSpaceComponent *)v7->m_Components.p[24].m_pComponent;
    }
    if ( v9 )
    {
      if ( (unsigned __int8)UFG::RoadSpaceComponent::IsAttachedToRoadNetwork(v9) )
        UFG::RoadSpaceComponent::DetachFromRoadNetwork(v9);
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
  CarAttackTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, CarAttackTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<CarAttackTask>::`vftable;
  v1->vfptr = (Expression::IMemberMapVtbl *)&CarAttackTrack::`vftable;
  v1->mAttackType.mValue = 0;
  *(_QWORD *)&v1->mDuration = 0i64;
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
  CarFormationAttackTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, CarFormationAttackTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<CarFormationAttackTask>::`vftable;
  v1->vfptr = (Expression::IMemberMapVtbl *)&CarFormationAttackTrack::`vftable;
  v1->mAttackType.mValue = 0;
  *(_QWORD *)&v1->mDuration = 0i64;
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
  CarFormationTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, CarFormationTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<CarFormationTask>::`vftable;
  v1->vfptr = (Expression::IMemberMapVtbl *)&CarFormationTrack::`vftable;
  *(_DWORD *)v1->mPosition = 0;
  *(_WORD *)&v1->mPosition[4] = 0;
  v1->mPosition[6] = 0;
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
  CarOffsetDriveTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, CarOffsetDriveTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<CarOffsetDriveTask>::`vftable;
  v1->vfptr = (Expression::IMemberMapVtbl *)&CarOffsetDriveTrack::`vftable;
  v1->mTolerance = 0.0;
  *(_WORD *)&v1->mPosition.mValue = 768;
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
  CarFormationDriveTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, CarFormationDriveTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<CarFormationDriveTask>::`vftable;
  v1->vfptr = (Expression::IMemberMapVtbl *)&CarFormationDriveTrack::`vftable;
  v1->mTolerance = 0.0;
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
  CarOccupantIntentionTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, CarOccupantIntentionTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<CarOccupantIntentionTask>::`vftable;
  v1->vfptr = (Expression::IMemberMapVtbl *)&CarOccupantIntentionTrack::`vftable;
  v1->m_eTargetType.mValue = 4;
  v1->m_ActionRequest = gActionRequest_Action.m_EnumValue;
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
  CarOccupantsActionTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, CarOccupantsActionTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<CarOccupantsActionTask>::`vftable;
  v1->vfptr = (Expression::IMemberMapVtbl *)&CarOccupantsActionTrack::`vftable;
  v1->m_ActionRequest = gActionRequest_Action.m_EnumValue;
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

