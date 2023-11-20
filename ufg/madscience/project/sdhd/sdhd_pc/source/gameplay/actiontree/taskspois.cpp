// File Line: 28
// RVA: 0x2E4200
void __fastcall POIBehaviourActiveTask::~POIBehaviourActiveTask(POIBehaviourActiveTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rdx
  UFG::qNode<ITask,ITask> *v2; // rcx
  UFG::qNode<ITask,ITask> *v3; // rax

  this->vfptr = (ITaskVtbl *)&POIBehaviourActiveTask::`vftable;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v2 = this->mPrev;
  v3 = v1->mNext;
  v2->mNext = v3;
  v3->mPrev = v2;
  v1->mPrev = v1;
  v1->mNext = v1;
}

// File Line: 32
// RVA: 0x2F0F30
void __fastcall POIBehaviourActiveTask::Begin(POIBehaviourActiveTask *this, ActionContext *context)
{
  UFG::SimObjectCVBase *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::ActiveAIEntityComponent *v4; // rax

  this->mContext = context;
  v2 = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v2);
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
      {
        v4 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               (UFG::SimObjectGame *)&v2->vfptr,
                                               UFG::ActiveAIEntityComponent::_TypeUID);
      }
      else if ( (v3 >> 12) & 1 )
      {
        v4 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               (UFG::SimObjectGame *)&v2->vfptr,
                                               UFG::ActiveAIEntityComponent::_TypeUID);
      }
      else
      {
        v4 = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                               (UFG::SimObject *)&v2->vfptr,
                                               UFG::ActiveAIEntityComponent::_TypeUID);
      }
    }
    else
    {
      v4 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v2);
    }
    if ( v4 )
      v4->m_InPOIDynamicBranch = 1;
  }
}

// File Line: 42
// RVA: 0x305D20
bool __fastcall POIBehaviourActiveTask::Update(POIBehaviourActiveTask *this, float timeDelta)
{
  POIBehaviourActiveTask *v2; // rbp
  ActionContext *v3; // rcx
  UFG::SimObjectGame *v4; // rcx
  unsigned __int16 v5; // dx
  UFG::TargetingSystemBaseComponent *v6; // rbx
  UFG::SimComponent *v7; // rax
  UFG::SimComponent *v8; // rdi
  UFG::SimObject *v9; // rsi
  unsigned __int16 v10; // cx
  UFG::SimComponent *v11; // rbx
  UFG::SimObjectGame *v12; // rcx
  unsigned __int16 v13; // dx
  UFG::SimComponent *v14; // rax

  v2 = this;
  v3 = this->mContext;
  if ( !v3 )
    return 0;
  v4 = (UFG::SimObjectGame *)v3->mSimObject.m_pPointer;
  if ( !v4 )
    return 0;
  v5 = v4->m_Flags;
  if ( (v5 >> 14) & 1 )
  {
    v6 = (UFG::TargetingSystemBaseComponent *)v4->m_Components.p[20].m_pComponent;
  }
  else if ( (v5 & 0x8000u) == 0 )
  {
    if ( (v5 >> 13) & 1 )
    {
      v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::TargetingSystemBaseComponent::_TypeUID);
    }
    else if ( (v5 >> 12) & 1 )
    {
      v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::TargetingSystemBaseComponent::_TypeUID);
    }
    else
    {
      v7 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
    }
    v6 = (UFG::TargetingSystemBaseComponent *)v7;
  }
  else
  {
    v6 = (UFG::TargetingSystemBaseComponent *)v4->m_Components.p[20].m_pComponent;
  }
  if ( !v6 )
    return 0;
  v8 = 0i64;
  v9 = v6->m_pTargets[(unsigned __int8)v6->m_pTargetingMap->m_Map.p[26]].m_pTarget.m_pPointer;
  ((void (__fastcall *)(UFG::TargetingSystemBaseComponent *, signed __int64, signed __int64))v6->vfptr[14].__vecDelDtor)(
    v6,
    26i64,
    1i64);
  UFG::TargetingSystemBaseComponent::SetTarget(v6, eTARGET_TYPE_INTERACTION_OFFSET, v9);
  if ( v9 )
  {
    v10 = v9->m_Flags;
    if ( (v10 >> 14) & 1 )
    {
      v11 = v9->m_Components.p[25].m_pComponent;
    }
    else if ( (v10 & 0x8000u) == 0 )
    {
      if ( (v10 >> 13) & 1 )
        v11 = v9->m_Components.p[10].m_pComponent;
      else
        v11 = (v10 >> 12) & 1 ? v9->m_Components.p[3].m_pComponent : UFG::SimObject::GetComponentOfType(
                                                                       v9,
                                                                       UFG::InterestPoint::_TypeUID);
    }
    else
    {
      v11 = v9->m_Components.p[25].m_pComponent;
    }
    if ( v11 && *(_QWORD *)(*(_QWORD *)&v11[6].m_TypeUID + 112i64) )
    {
      v12 = (UFG::SimObjectGame *)v2->mContext->mSimObject.m_pPointer;
      if ( v12 )
      {
        v13 = v12->m_Flags;
        if ( (v13 >> 14) & 1 || (v13 & 0x8000u) != 0 )
        {
          v8 = v12->m_Components.p[7].m_pComponent;
        }
        else if ( (v13 >> 13) & 1 )
        {
          v8 = v12->m_Components.p[6].m_pComponent;
        }
        else
        {
          if ( (v13 >> 12) & 1 )
            v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::ActionTreeComponent::_TypeUID);
          else
            v14 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v12->vfptr, UFG::ActionTreeComponent::_TypeUID);
          v8 = v14;
        }
      }
      ActionController::Play((ActionController *)&v8[3], *(ActionNode **)(*(_QWORD *)&v11[6].m_TypeUID + 120i64), 0);
    }
  }
  return 0;
}

// File Line: 67
// RVA: 0x2FF330
void __fastcall POIBehaviourActiveTask::End(POIBehaviourActiveTask *this)
{
  ActionContext *v1; // rcx
  UFG::SimObjectCVBase *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::ActiveAIEntityComponent *v4; // rax

  v1 = this->mContext;
  if ( v1 )
  {
    v2 = (UFG::SimObjectCVBase *)v1->mSimObject.m_pPointer;
    if ( v2 )
    {
      v3 = v2->m_Flags;
      if ( (v3 >> 14) & 1 )
      {
        v4 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v2);
      }
      else if ( (v3 & 0x8000u) == 0 )
      {
        if ( (v3 >> 13) & 1 )
        {
          v4 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)&v2->vfptr,
                                                 UFG::ActiveAIEntityComponent::_TypeUID);
        }
        else if ( (v3 >> 12) & 1 )
        {
          v4 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)&v2->vfptr,
                                                 UFG::ActiveAIEntityComponent::_TypeUID);
        }
        else
        {
          v4 = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                 (UFG::SimObject *)&v2->vfptr,
                                                 UFG::ActiveAIEntityComponent::_TypeUID);
        }
      }
      else
      {
        v4 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v2);
      }
      if ( v4 )
        v4->m_InPOIDynamicBranch = 0;
    }
  }
}

// File Line: 82
// RVA: 0x2F12B0
void __fastcall POIManagementTask::Begin(POIManagementTask *this, ActionContext *context)
{
  POIManagementTask *v2; // rbp
  UFG::SimObjectGame *v3; // rcx
  UFG::SimComponent *v4; // rbx
  ActionContext *v5; // r14
  UFG::SimComponent *v6; // rsi
  unsigned __int16 v7; // dx
  UFG::SimComponent *v8; // rax
  UFG::SimObject *v9; // r8
  UFG::SimComponent *v10; // rdi
  unsigned __int16 v11; // cx
  UFG::SimObject *v12; // rcx
  unsigned __int16 v13; // dx
  UFG::qSafePointer<UFG::SimComponent,UFG::InterestPoint> *v14; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::InterestPoint *v18; // rcx
  UFG::ePOIUseType v19; // ebx
  UFG::qSymbol skipIntoLabel; // [rsp+40h] [rbp+8h]

  v2 = this;
  this->mContext = context;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  v4 = 0i64;
  v5 = context;
  if ( v3 )
  {
    v7 = v3->m_Flags;
    if ( (v7 >> 14) & 1 )
    {
      v6 = v3->m_Components.p[20].m_pComponent;
    }
    else if ( (v7 & 0x8000u) == 0 )
    {
      if ( (v7 >> 13) & 1 )
      {
        v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else if ( (v7 >> 12) & 1 )
      {
        v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else
      {
        v8 = UFG::SimObject::GetComponentOfType(
               (UFG::SimObject *)&v3->vfptr,
               UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      v6 = v8;
    }
    else
    {
      v6 = v3->m_Components.p[20].m_pComponent;
    }
  }
  else
  {
    v6 = 0i64;
  }
  v9 = v5->mSimObject.m_pPointer;
  if ( v9 )
  {
    v11 = v9->m_Flags;
    if ( (v11 >> 14) & 1 )
    {
      v10 = v9->m_Components.p[43].m_pComponent;
    }
    else if ( (v11 & 0x8000u) == 0 )
    {
      if ( (v11 >> 13) & 1 )
      {
        v10 = v9->m_Components.p[12].m_pComponent;
      }
      else if ( (v11 >> 12) & 1 )
      {
        v10 = 0i64;
      }
      else
      {
        v10 = UFG::SimObject::GetComponentOfType(v5->mSimObject.m_pPointer, UFG::InterestPointUserComponent::_TypeUID);
      }
    }
    else
    {
      v10 = 0i64;
    }
  }
  else
  {
    v10 = 0i64;
  }
  if ( v6 && v10 )
  {
    v12 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v6[1].m_Flags + 34i64)
                             + *(_QWORD *)&v6[1].m_TypeUID
                             + 40);
    if ( v12 )
    {
      v13 = v12->m_Flags;
      if ( (v13 >> 14) & 1 )
      {
        v4 = v12->m_Components.p[25].m_pComponent;
      }
      else if ( (v13 & 0x8000u) == 0 )
      {
        if ( (v13 >> 13) & 1 )
        {
          v4 = v12->m_Components.p[10].m_pComponent;
        }
        else if ( (v13 >> 12) & 1 )
        {
          v4 = v12->m_Components.p[3].m_pComponent;
        }
        else
        {
          v4 = UFG::SimObject::GetComponentOfType(v12, UFG::InterestPoint::_TypeUID);
        }
      }
      else
      {
        v4 = v12->m_Components.p[25].m_pComponent;
      }
    }
    v14 = &v2->mpPOI;
    if ( v2->mpPOI.m_pPointer )
    {
      v15 = v14->mPrev;
      v16 = v2->mpPOI.mNext;
      v15->mNext = v16;
      v16->mPrev = v15;
      v14->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v14->mPrev;
      v2->mpPOI.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mpPOI.mPrev;
    }
    v2->mpPOI.m_pPointer = v4;
    if ( v4 )
    {
      v17 = v4->m_SafePointerList.mNode.mPrev;
      v17->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v14->mPrev;
      v14->mPrev = v17;
      v2->mpPOI.mNext = &v4->m_SafePointerList.mNode;
      v4->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v14->mPrev;
    }
    v18 = (UFG::InterestPoint *)v2->mpPOI.m_pPointer;
    if ( v18 )
    {
      v19 = 1;
      UFG::InterestPoint::BeginReservation(v18, v5->mSimObject.m_pPointer, ReserveReason_normal);
      skipIntoLabel.mUID = UFG::gNullQSymbol.mUID;
      if ( UFG::InterestPointUseDetails::IsValid((UFG::InterestPointUseDetails *)&v10[7].m_Flags) )
      {
        if ( v10[7].m_BoundComponentHandles.mNode.mPrev == (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)v2->mpPOI.m_pPointer )
        {
          v19 = (UFG::ePOIUseType)v10[7].m_BoundComponentHandles.mNode.mNext;
          skipIntoLabel.mUID = HIDWORD(v10[7].m_BoundComponentHandles.mNode.mNext);
        }
      }
      else
      {
        UFG::InterestPointUseDetails::Set(
          (UFG::InterestPointUseDetails *)&v10[7].m_Flags,
          (UFG::InterestPoint *)v2->mpPOI.m_pPointer,
          ePOIUseType_System,
          &skipIntoLabel);
      }
      UFG::InterestPointUseDetails::Set(
        (UFG::InterestPointUseDetails *)&v10[8],
        (UFG::InterestPoint *)v2->mpPOI.m_pPointer,
        v19,
        &skipIntoLabel);
    }
  }
}

// File Line: 125
// RVA: 0x2FF3C0
void __fastcall POIManagementTask::End(POIManagementTask *this)
{
  ActionContext *v1; // r8
  POIManagementTask *v2; // rdi
  UFG::SimObject *v3; // r8
  int v4; // er14
  UFG::SimComponent *v5; // rbx
  unsigned __int16 v6; // cx
  UFG::InterestPoint *v7; // rcx
  char v8; // r12
  bool v9; // si
  char v10; // r15
  bool v11; // bp
  UFG::SimObjectGame *v12; // rcx
  UFG::TargetingSystemBaseComponent *v13; // rsi
  unsigned __int16 v14; // dx
  UFG::SimComponent *v15; // rax
  UFG::SimComponent *v16; // rdx
  __int64 v17; // r9
  UFG::SpawnPoint *v18; // rax
  bool allowNoInterruptResume; // [rsp+70h] [rbp+8h]

  v1 = this->mContext;
  v2 = this;
  if ( !v1 )
    return;
  v3 = v1->mSimObject.m_pPointer;
  v4 = 0;
  if ( v3 )
  {
    v6 = v3->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v5 = v3->m_Components.p[43].m_pComponent;
    }
    else if ( (v6 & 0x8000u) == 0 )
    {
      if ( (v6 >> 13) & 1 )
      {
        v5 = v3->m_Components.p[12].m_pComponent;
      }
      else if ( (v6 >> 12) & 1 )
      {
        v5 = 0i64;
      }
      else
      {
        v5 = UFG::SimObject::GetComponentOfType(v3, UFG::InterestPointUserComponent::_TypeUID);
      }
    }
    else
    {
      v5 = 0i64;
    }
  }
  else
  {
    v5 = 0i64;
  }
  v7 = (UFG::InterestPoint *)v2->mpPOI.m_pPointer;
  if ( v7 )
  {
    if ( !v5 )
      return;
    allowNoInterruptResume = 0;
    v8 = 0;
    v9 = UFG::InterestPoint::WantsToResume(v7, &allowNoInterruptResume);
    UFG::InterestPoint::EndReservation((UFG::InterestPoint *)v2->mpPOI.m_pPointer);
    v10 = 1;
    if ( allowNoInterruptResume
      && UFG::InterestPointUseDetails::operator==(
           (UFG::InterestPointUseDetails *)&v5[7].m_Flags,
           (UFG::InterestPointUseDetails *)&v5[8])
      && v5[8].m_TypeUID == 3 )
    {
      v10 = 0;
    }
    else if ( !v9 )
    {
      goto LABEL_22;
    }
    if ( !((LOBYTE(v2->mContext->mSimObject.m_pPointer->m_Flags) >> 1) & 1) )
    {
      v11 = 1;
      goto LABEL_23;
    }
LABEL_22:
    v11 = 0;
LABEL_23:
    v12 = (UFG::SimObjectGame *)v2->mContext->mSimObject.m_pPointer;
    if ( v12 )
    {
      v14 = v12->m_Flags;
      if ( (v14 >> 14) & 1 )
      {
        v13 = (UFG::TargetingSystemBaseComponent *)v12->m_Components.p[20].m_pComponent;
      }
      else if ( (v14 & 0x8000u) == 0 )
      {
        if ( (v14 >> 13) & 1 )
        {
          v15 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        else if ( (v14 >> 12) & 1 )
        {
          v15 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        else
        {
          v15 = UFG::SimObject::GetComponentOfType(
                  (UFG::SimObject *)&v12->vfptr,
                  UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        v13 = (UFG::TargetingSystemBaseComponent *)v15;
      }
      else
      {
        v13 = (UFG::TargetingSystemBaseComponent *)v12->m_Components.p[20].m_pComponent;
      }
      if ( v13 )
      {
        v16 = v2->mpPOI.m_pPointer;
        if ( v16
          && v16->m_pSimObject == v13->m_pTargets[(unsigned __int8)v13->m_pTargetingMap->m_Map.p[26]].m_pTarget.m_pPointer )
        {
          v8 = 1;
        }
        else
        {
          v11 = 0;
        }
      }
    }
    else
    {
      v13 = 0i64;
    }
    if ( v10 )
    {
      if ( !v11
        || !UFG::InterestPoint::IsRelevantToCharacter(
              (UFG::InterestPoint *)v2->mpPOI.m_pPointer,
              v2->mContext->mSimObject.m_pPointer,
              ReserveReason_resume) )
      {
        v11 = 0;
        goto LABEL_46;
      }
    }
    else if ( !v11 )
    {
LABEL_46:
      if ( v13
        && v8
        && !v11
        && (!UFG::InterestPointUseDetails::IsValid((UFG::InterestPointUseDetails *)&v5[7].m_Flags)
         || v5[7].m_BoundComponentHandles.mNode.mPrev != (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)v2->mpPOI.m_pPointer
         || !UFG::InterestPointUseDetails::operator!=(
               (UFG::InterestPointUseDetails *)&v5[7].m_Flags,
               (UFG::InterestPointUseDetails *)&v5[8])) )
      {
        LOBYTE(v17) = 1;
        ((void (__fastcall *)(UFG::TargetingSystemBaseComponent *, signed __int64, _QWORD, __int64, _DWORD, char *, ActionContext *, ITrack *))v13->vfptr[14].__vecDelDtor)(
          v13,
          26i64,
          0i64,
          v17,
          0,
          &customWorldMapCaption,
          v2->mContext,
          v2->m_Track);
        UFG::TargetingSystemBaseComponent::ClearTarget(v13, eTARGET_TYPE_POI_USE);
      }
      if ( UFG::InterestPointUseDetails::operator==(
             (UFG::InterestPointUseDetails *)&v5[8],
             (UFG::InterestPointUseDetails *)&v5[7].m_Flags) )
      {
        UFG::InterestPointUseDetails::Reset((UFG::InterestPointUseDetails *)&v5[7].m_Flags);
      }
      UFG::ActiveInterestPoint::Reset((UFG::ActiveInterestPoint *)&v5[8]);
      return;
    }
    LOBYTE(v5[8].m_Flags) = 0;
    LOBYTE(v4) = v10 != 0;
    v11 = UFG::InterestPoint::BeginReservation(
            (UFG::InterestPoint *)v2->mpPOI.m_pPointer,
            v2->mContext->mSimObject.m_pPointer,
            (UFG::InterestPoint::eReserveReason)(v4 + 1));
    if ( v11 )
      return;
    goto LABEL_46;
  }
  if ( v5 )
  {
    if ( HIDWORD(v5[7].m_BoundComponentHandles.mNode.mNext) == qSymbol_Link.mUID )
    {
      v18 = UFG::GetOriginatingSpawnPoint(v2->mContext->mSimObject.m_pPointer);
      if ( v18 )
        UFG::SpawnPoint::UpdateLinks(v18, 0);
    }
  }
}

// File Line: 251
// RVA: 0x2F0FB0
void __fastcall POIDisableSelfTask::Begin(POIDisableSelfTask *this, ActionContext *context)
{
  POIDisableSelfTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rdx
  UFG::SimComponent *v6; // rax
  UFG::SimObject *v7; // rcx
  unsigned __int16 v8; // dx
  UFG::InterestPoint *v9; // rax

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = v3->m_Components.p[20].m_pComponent;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else if ( (v4 >> 12) & 1 )
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else
      {
        v6 = UFG::SimObject::GetComponentOfType(
               (UFG::SimObject *)&v3->vfptr,
               UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      v5 = v6;
    }
    else
    {
      v5 = v3->m_Components.p[20].m_pComponent;
    }
    if ( v5 )
    {
      v7 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v5[1].m_Flags + 34i64)
                              + *(_QWORD *)&v5[1].m_TypeUID
                              + 40);
      if ( v7 )
      {
        v8 = v7->m_Flags;
        if ( (v8 >> 14) & 1 )
        {
          v9 = (UFG::InterestPoint *)v7->m_Components.p[25].m_pComponent;
        }
        else if ( (v8 & 0x8000u) == 0 )
        {
          if ( (v8 >> 13) & 1 )
          {
            v9 = (UFG::InterestPoint *)v7->m_Components.p[10].m_pComponent;
          }
          else if ( (v8 >> 12) & 1 )
          {
            v9 = (UFG::InterestPoint *)v7->m_Components.p[3].m_pComponent;
          }
          else
          {
            v9 = (UFG::InterestPoint *)UFG::SimObject::GetComponentOfType(v7, UFG::InterestPoint::_TypeUID);
          }
        }
        else
        {
          v9 = (UFG::InterestPoint *)v7->m_Components.p[25].m_pComponent;
        }
        if ( v9 )
          UFG::InterestPoint::SetActive(v9, 0, LOBYTE(v2->m_Track[1].vfptr) != 0);
      }
    }
  }
}

// File Line: 269
// RVA: 0x2EF9B0
void __fastcall InteractionPointInteractWithBestTask::Begin(InteractionPointInteractWithBestTask *this, ActionContext *pContext)
{
  UFG::SimObjectGame *v2; // r8
  unsigned __int16 v3; // cx
  UFG::InteractorComponent *v4; // rax
  UFG::InteractionPoint *v5; // rdx

  this->m_pContext = pContext;
  v2 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = (UFG::InteractorComponent *)v2->m_Components.p[29].m_pComponent;
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
      {
        v4 = (UFG::InteractorComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           v2,
                                           UFG::InteractorComponent::_TypeUID);
      }
      else if ( (v3 >> 12) & 1 )
      {
        v4 = (UFG::InteractorComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           v2,
                                           UFG::InteractorComponent::_TypeUID);
      }
      else
      {
        v4 = (UFG::InteractorComponent *)UFG::SimObject::GetComponentOfType(
                                           (UFG::SimObject *)&v2->vfptr,
                                           UFG::InteractorComponent::_TypeUID);
      }
    }
    else
    {
      v4 = (UFG::InteractorComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::InteractorComponent::_TypeUID);
    }
    if ( v4 )
    {
      v5 = v4->m_pBestInteractionPoint.m_pPointer;
      if ( v5 )
        UFG::InteractorComponent::StartInteraction(v4, v5, 1);
    }
  }
}

// File Line: 306
// RVA: 0x2FEDD0
void __fastcall InteractionPointInteractWithBestTask::End(InteractionPointInteractWithBestTask *this)
{
  UFG::SimObjectGame *v1; // rcx
  unsigned __int16 v2; // dx
  UFG::InteractorComponent *v3; // rax

  v1 = (UFG::SimObjectGame *)this->m_pContext->mSimObject.m_pPointer;
  if ( v1 )
  {
    v2 = v1->m_Flags;
    if ( (v2 >> 14) & 1 )
    {
      v3 = (UFG::InteractorComponent *)v1->m_Components.p[29].m_pComponent;
    }
    else if ( (v2 & 0x8000u) == 0 )
    {
      if ( (v2 >> 13) & 1 )
      {
        v3 = (UFG::InteractorComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           v1,
                                           UFG::InteractorComponent::_TypeUID);
      }
      else if ( (v2 >> 12) & 1 )
      {
        v3 = (UFG::InteractorComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           v1,
                                           UFG::InteractorComponent::_TypeUID);
      }
      else
      {
        v3 = (UFG::InteractorComponent *)UFG::SimObject::GetComponentOfType(
                                           (UFG::SimObject *)&v1->vfptr,
                                           UFG::InteractorComponent::_TypeUID);
      }
    }
    else
    {
      v3 = (UFG::InteractorComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::InteractorComponent::_TypeUID);
    }
    if ( v3 )
      UFG::InteractorComponent::StopInteraction(v3, 1);
  }
}

// File Line: 327
// RVA: 0x2EFA50
void __fastcall InteractionPointSetupTask::Begin(InteractionPointSetupTask *this, ActionContext *pContext)
{
  InteractionPointSetupTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rdx
  UFG::SimComponent *v6; // rax
  ITrack *v7; // rcx
  signed __int64 v8; // rax
  signed __int64 v9; // r8
  int v10; // ecx

  v2 = this;
  this->m_pContext = pContext;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = v3->m_Components.p[12].m_pComponent;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::InteractableComponent::_TypeUID);
      else
        v6 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::InteractableComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::InteractableComponent::_TypeUID);
      v5 = v6;
    }
    else
    {
      v5 = v3->m_Components.p[12].m_pComponent;
    }
    if ( v5 )
    {
      v7 = v2->m_Track;
      v8 = (unsigned int)LOBYTE(v7[1].vfptr) - 69;
      if ( LOBYTE(v7[1].vfptr) == 69 )
      {
        v8 = 0i64;
      }
      else if ( (unsigned int)v8 >= 5 )
      {
        v8 = 5i64;
      }
      v9 = 160 * v8;
      BYTE4((&v5[2].m_BoundComponentHandles.mNode.mPrev)[(unsigned __int64)v9 / 8]) = BYTE1(v7[1].vfptr) != 0;
      v10 = BYTE2(v2->m_Track[1].vfptr);
      *(_DWORD *)((char *)&v5[2].m_SafePointerList.mNode.mPrev + v9) = v10;
      if ( v10 == 2 )
      {
        *(_DWORD *)((char *)&v5[2].m_pSimObject + v9) = HIDWORD(v2->m_Track[1].vfptr);
      }
      else if ( v10 == 3 )
      {
        *(_DWORD *)((char *)&v5[2].m_pSimObject + v9 + 4) = v2->m_Track[1].mResourceOwner;
      }
    }
  }
}

// File Line: 351
// RVA: 0x3049D0
_BOOL8 __fastcall InteractionPointSetupTask::Update(InteractionPointSetupTask *this, float timeDelta)
{
  return BYTE4(this->m_Track[1].mResourceOwner) != 0;
}

// File Line: 357
// RVA: 0x2FEE60
void __fastcall InteractionPointSetupTask::End(InteractionPointSetupTask *this)
{
  InteractionPointSetupTask *v1; // rbx
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::InteractableComponent *v4; // rcx
  UFG::SimComponent *v5; // rax

  v1 = this;
  if ( BYTE4(this->m_Track[1].mResourceOwner) )
  {
    v2 = (UFG::SimObjectGame *)this->m_pContext->mSimObject.m_pPointer;
    if ( v2 )
    {
      v3 = v2->m_Flags;
      if ( (v3 >> 14) & 1 )
      {
        v4 = (UFG::InteractableComponent *)v2->m_Components.p[12].m_pComponent;
      }
      else if ( (v3 & 0x8000u) == 0 )
      {
        if ( (v3 >> 13) & 1 )
        {
          v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::InteractableComponent::_TypeUID);
        }
        else if ( (v3 >> 12) & 1 )
        {
          v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::InteractableComponent::_TypeUID);
        }
        else
        {
          v5 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::InteractableComponent::_TypeUID);
        }
        v4 = (UFG::InteractableComponent *)v5;
      }
      else
      {
        v4 = (UFG::InteractableComponent *)v2->m_Components.p[12].m_pComponent;
      }
      if ( v4 )
        UFG::InteractableComponent::SetIsActive(v4, (UFG::eTargetTypeEnum)LOBYTE(v1->m_Track[1].vfptr), 0);
    }
  }
}

// File Line: 374
// RVA: 0x2EF860
void __fastcall InteractionPointActivateTask::Begin(InteractionPointActivateTask *this, ActionContext *pContext)
{
  InteractionPointActivateTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::InteractableComponent *v5; // rcx
  UFG::SimComponent *v6; // rax

  v2 = this;
  this->m_pContext = pContext;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = (UFG::InteractableComponent *)v3->m_Components.p[12].m_pComponent;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::InteractableComponent::_TypeUID);
      }
      else if ( (v4 >> 12) & 1 )
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::InteractableComponent::_TypeUID);
      }
      else
      {
        v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::InteractableComponent::_TypeUID);
      }
      v5 = (UFG::InteractableComponent *)v6;
    }
    else
    {
      v5 = (UFG::InteractableComponent *)v3->m_Components.p[12].m_pComponent;
    }
    if ( v5 )
      UFG::InteractableComponent::SetIsActive(v5, (UFG::eTargetTypeEnum)LOBYTE(v2->m_Track[1].vfptr), 1);
  }
}

// File Line: 386
// RVA: 0x3049C0
_BOOL8 __fastcall InteractionPointActivateTask::Update(InteractionPointActivateTask *this, float timeDelta)
{
  return BYTE1(this->m_Track[1].vfptr) != 0;
}

// File Line: 392
// RVA: 0x2FED10
void __fastcall InteractionPointActivateTask::End(InteractionPointActivateTask *this)
{
  InteractionPointActivateTask *v1; // rbx
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::InteractableComponent *v4; // rcx
  UFG::SimComponent *v5; // rax

  v1 = this;
  if ( BYTE1(this->m_Track[1].vfptr) )
  {
    v2 = (UFG::SimObjectGame *)this->m_pContext->mSimObject.m_pPointer;
    if ( v2 )
    {
      v3 = v2->m_Flags;
      if ( (v3 >> 14) & 1 )
      {
        v4 = (UFG::InteractableComponent *)v2->m_Components.p[12].m_pComponent;
      }
      else if ( (v3 & 0x8000u) == 0 )
      {
        if ( (v3 >> 13) & 1 )
        {
          v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::InteractableComponent::_TypeUID);
        }
        else if ( (v3 >> 12) & 1 )
        {
          v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::InteractableComponent::_TypeUID);
        }
        else
        {
          v5 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::InteractableComponent::_TypeUID);
        }
        v4 = (UFG::InteractableComponent *)v5;
      }
      else
      {
        v4 = (UFG::InteractableComponent *)v2->m_Components.p[12].m_pComponent;
      }
      if ( v4 )
        UFG::InteractableComponent::SetIsActive(v4, (UFG::eTargetTypeEnum)LOBYTE(v1->m_Track[1].vfptr), 0);
    }
  }
}

// File Line: 410
// RVA: 0x2EF910
void __fastcall InteractionPointDeactivateTask::Begin(InteractionPointDeactivateTask *this, ActionContext *pContext)
{
  InteractionPointDeactivateTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::InteractableComponent *v5; // rcx
  UFG::SimComponent *v6; // rax

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = (UFG::InteractableComponent *)v3->m_Components.p[12].m_pComponent;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::InteractableComponent::_TypeUID);
      }
      else if ( (v4 >> 12) & 1 )
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::InteractableComponent::_TypeUID);
      }
      else
      {
        v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::InteractableComponent::_TypeUID);
      }
      v5 = (UFG::InteractableComponent *)v6;
    }
    else
    {
      v5 = (UFG::InteractableComponent *)v3->m_Components.p[12].m_pComponent;
    }
    if ( v5 )
      UFG::InteractableComponent::SetIsActive(v5, (UFG::eTargetTypeEnum)LOBYTE(v2->m_Track[1].vfptr), 0);
  }
}

// File Line: 424
// RVA: 0x2F10F0
void __fastcall POIEnableChildTask::Begin(POIEnableChildTask *this, ActionContext *pActionContext)
{
  POIEnableChildTask *v2; // rdi
  UFG::SimObject *v3; // rax
  unsigned __int16 v4; // r8
  UFG::InterestPoint *v5; // rbx
  ITrack *v6; // rax
  Expression::IMemberMapVtbl *v7; // rcx
  signed __int64 v8; // rax
  unsigned __int64 v9; // rcx
  const char *v10; // rcx
  int v11; // eax
  bool v12; // zf
  bool v13; // sf
  ITrack *v14; // rax
  ITrack *v15; // rax
  const char *v16; // rdx
  UFG::SimObject *v17; // rax
  unsigned __int16 v18; // dx
  UFG::InterestPoint *v19; // rax
  UFG::qSymbol childName; // [rsp+38h] [rbp+10h]

  v2 = this;
  v3 = UFG::getTarget(pActionContext->mSimObject.m_pPointer, eTARGET_TYPE_POI_USE);
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = (UFG::InterestPoint *)v3->m_Components.p[25].m_pComponent;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
        v5 = (UFG::InterestPoint *)v3->m_Components.p[10].m_pComponent;
      else
        v5 = (UFG::InterestPoint *)((v4 >> 12) & 1 ? v3->m_Components.p[3].m_pComponent : UFG::SimObject::GetComponentOfType(
                                                                                            v3,
                                                                                            UFG::InterestPoint::_TypeUID));
    }
    else
    {
      v5 = (UFG::InterestPoint *)v3->m_Components.p[25].m_pComponent;
    }
    if ( v5 )
    {
      v6 = v2->m_Track;
      v7 = v6[1].vfptr;
      v8 = (signed __int64)&v6[1];
      v9 = (unsigned __int64)v7 & 0xFFFFFFFFFFFFFFFEui64;
      if ( v9 )
        v10 = (const char *)(v8 + v9);
      else
        v10 = BinString::sEmptyString;
      v11 = UFG::qStringLength(v10);
      v12 = v11 == 0;
      v13 = v11 < 0;
      v14 = v2->m_Track;
      if ( v13 || v12 )
      {
        v17 = UFG::InterestPoint::GetChild(v5, (unsigned int)v14[1].mResourceOwner);
      }
      else
      {
        v15 = v14 + 1;
        childName.mUID = -1;
        v16 = (char *)v15 + ((_QWORD)v15->vfptr & 0xFFFFFFFFFFFFFFFEui64);
        if ( !((_QWORD)v15->vfptr & 0xFFFFFFFFFFFFFFFEui64) )
          v16 = BinString::sEmptyString;
        UFG::qSymbol::set_from_cstr(&childName, v16);
        v17 = UFG::InterestPoint::GetChild(v5, &childName);
      }
      if ( v17 )
      {
        v18 = v17->m_Flags;
        if ( (v18 >> 14) & 1 )
        {
          v19 = (UFG::InterestPoint *)v17->m_Components.p[25].m_pComponent;
        }
        else if ( (v18 & 0x8000u) == 0 )
        {
          if ( (v18 >> 13) & 1 )
          {
            v19 = (UFG::InterestPoint *)v17->m_Components.p[10].m_pComponent;
          }
          else if ( (v18 >> 12) & 1 )
          {
            v19 = (UFG::InterestPoint *)v17->m_Components.p[3].m_pComponent;
          }
          else
          {
            v19 = (UFG::InterestPoint *)UFG::SimObject::GetComponentOfType(v17, UFG::InterestPoint::_TypeUID);
          }
        }
        else
        {
          v19 = (UFG::InterestPoint *)v17->m_Components.p[25].m_pComponent;
        }
        if ( v19 )
          UFG::InterestPoint::SetActive(
            v19,
            BYTE4(v2->m_Track[1].mResourceOwner) != 0,
            BYTE5(v2->m_Track[1].mResourceOwner) != 0);
      }
    }
  }
}

