// File Line: 28
// RVA: 0x2E4200
void __fastcall POIBehaviourActiveTask::~POIBehaviourActiveTask(POIBehaviourActiveTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rdx
  UFG::qNode<ITask,ITask> *mPrev; // rcx
  UFG::qNode<ITask,ITask> *mNext; // rax

  this->vfptr = (ITaskVtbl *)&POIBehaviourActiveTask::`vftable;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v1 = &this->UFG::qNode<ITask,ITask>;
  mPrev = this->mPrev;
  mNext = v1->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
}

// File Line: 32
// RVA: 0x2F0F30
void __fastcall POIBehaviourActiveTask::Begin(POIBehaviourActiveTask *this, ActionContext *context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::ActiveAIEntityComponent *ComponentOfTypeHK; // rax

  this->mContext = context;
  m_pPointer = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(m_pPointer);
    }
    else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            m_pPointer,
                                                            UFG::ActiveAIEntityComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                            m_pPointer,
                                                            UFG::ActiveAIEntityComponent::_TypeUID);
    }
    if ( ComponentOfTypeHK )
      ComponentOfTypeHK->m_InPOIDynamicBranch = 1;
  }
}

// File Line: 42
// RVA: 0x305D20
bool __fastcall POIBehaviourActiveTask::Update(POIBehaviourActiveTask *this, float timeDelta)
{
  ActionContext *mContext; // rcx
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::TargetingSystemBaseComponent *m_pComponent; // rbx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimComponent *v8; // rdi
  UFG::SimObject *v9; // rsi
  __int16 v10; // cx
  UFG::SimComponent *v11; // rbx
  UFG::SimObjectGame *v12; // rcx
  __int16 v13; // dx
  UFG::SimComponent *ComponentOfType; // rax

  mContext = this->mContext;
  if ( !mContext )
    return 0;
  m_pPointer = (UFG::SimObjectGame *)mContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = (UFG::TargetingSystemBaseComponent *)m_pPointer->m_Components.p[20].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                            m_pPointer,
                            UFG::TargetingSystemBaseComponent::_TypeUID);
    else
      ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
    m_pComponent = (UFG::TargetingSystemBaseComponent *)ComponentOfTypeHK;
  }
  else
  {
    m_pComponent = (UFG::TargetingSystemBaseComponent *)m_pPointer->m_Components.p[20].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  v8 = 0i64;
  v9 = m_pComponent->m_pTargets[(unsigned __int8)m_pComponent->m_pTargetingMap->m_Map.p[26]].m_pTarget.m_pPointer;
  ((void (__fastcall *)(UFG::TargetingSystemBaseComponent *, __int64, __int64))m_pComponent->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[14].__vecDelDtor)(
    m_pComponent,
    26i64,
    1i64);
  UFG::TargetingSystemBaseComponent::SetTarget(m_pComponent, eTARGET_TYPE_INTERACTION_OFFSET, v9);
  if ( v9 )
  {
    v10 = v9->m_Flags;
    if ( (v10 & 0x4000) != 0 )
    {
      v11 = v9->m_Components.p[25].m_pComponent;
    }
    else if ( v10 >= 0 )
    {
      if ( (v10 & 0x2000) != 0 )
        v11 = v9->m_Components.p[10].m_pComponent;
      else
        v11 = (v10 & 0x1000) != 0
            ? v9->m_Components.p[3].m_pComponent
            : UFG::SimObject::GetComponentOfType(v9, UFG::InterestPoint::_TypeUID);
    }
    else
    {
      v11 = v9->m_Components.p[25].m_pComponent;
    }
    if ( v11 && *(_QWORD *)(*(_QWORD *)&v11[6].m_TypeUID + 112i64) )
    {
      v12 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
      if ( v12 )
      {
        v13 = v12->m_Flags;
        if ( (v13 & 0x4000) != 0 || v13 < 0 )
        {
          v8 = v12->m_Components.p[7].m_pComponent;
        }
        else if ( (v13 & 0x2000) != 0 )
        {
          v8 = v12->m_Components.p[6].m_pComponent;
        }
        else
        {
          if ( (v13 & 0x1000) != 0 )
            ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::ActionTreeComponent::_TypeUID);
          else
            ComponentOfType = UFG::SimObject::GetComponentOfType(v12, UFG::ActionTreeComponent::_TypeUID);
          v8 = ComponentOfType;
        }
      }
      ActionController::Play(
        (ActionController *)&v8[3],
        *(ActionNodePlayable **)(*(_QWORD *)&v11[6].m_TypeUID + 120i64),
        0);
    }
  }
  return 0;
}

// File Line: 67
// RVA: 0x2FF330
void __fastcall POIBehaviourActiveTask::End(POIBehaviourActiveTask *this)
{
  ActionContext *mContext; // rcx
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::ActiveAIEntityComponent *ComponentOfTypeHK; // rax

  mContext = this->mContext;
  if ( mContext )
  {
    m_pPointer = (UFG::SimObjectCVBase *)mContext->mSimObject.m_pPointer;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
      {
        ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(m_pPointer);
      }
      else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      {
        ComponentOfTypeHK = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                              m_pPointer,
                                                              UFG::ActiveAIEntityComponent::_TypeUID);
      }
      else
      {
        ComponentOfTypeHK = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                              m_pPointer,
                                                              UFG::ActiveAIEntityComponent::_TypeUID);
      }
      if ( ComponentOfTypeHK )
        ComponentOfTypeHK->m_InPOIDynamicBranch = 0;
    }
  }
}

// File Line: 82
// RVA: 0x2F12B0
void __fastcall POIManagementTask::Begin(POIManagementTask *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::SimComponent *v4; // rbx
  UFG::SimComponent *m_pComponent; // rsi
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObject *v9; // r8
  UFG::SimComponent *ComponentOfType; // rdi
  __int16 v11; // cx
  UFG::SimObject *v12; // rcx
  __int16 v13; // dx
  UFG::qSafePointer<UFG::SimComponent,UFG::InterestPoint> *p_mpPOI; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::InterestPoint *v18; // rcx
  UFG::ePOIUseType v19; // ebx
  UFG::qSymbol skipIntoLabel; // [rsp+40h] [rbp+8h] BYREF

  this->mContext = context;
  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  v4 = 0i64;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                              m_pPointer,
                              UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = ComponentOfTypeHK;
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  v9 = context->mSimObject.m_pPointer;
  if ( v9 )
  {
    v11 = v9->m_Flags;
    if ( (v11 & 0x4000) != 0 )
    {
      ComponentOfType = v9->m_Components.p[43].m_pComponent;
    }
    else if ( v11 >= 0 )
    {
      if ( (v11 & 0x2000) != 0 )
      {
        ComponentOfType = v9->m_Components.p[12].m_pComponent;
      }
      else if ( (v11 & 0x1000) != 0 )
      {
        ComponentOfType = 0i64;
      }
      else
      {
        ComponentOfType = UFG::SimObject::GetComponentOfType(
                            context->mSimObject.m_pPointer,
                            UFG::InterestPointUserComponent::_TypeUID);
      }
    }
    else
    {
      ComponentOfType = 0i64;
    }
  }
  else
  {
    ComponentOfType = 0i64;
  }
  if ( m_pComponent && ComponentOfType )
  {
    v12 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + 34i64)
                             + *(_QWORD *)&m_pComponent[1].m_TypeUID
                             + 40);
    if ( v12 )
    {
      v13 = v12->m_Flags;
      if ( (v13 & 0x4000) != 0 )
      {
        v4 = v12->m_Components.p[25].m_pComponent;
      }
      else if ( v13 >= 0 )
      {
        if ( (v13 & 0x2000) != 0 )
        {
          v4 = v12->m_Components.p[10].m_pComponent;
        }
        else if ( (v13 & 0x1000) != 0 )
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
    p_mpPOI = &this->mpPOI;
    if ( this->mpPOI.m_pPointer )
    {
      mPrev = p_mpPOI->mPrev;
      mNext = this->mpPOI.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_mpPOI->mPrev = p_mpPOI;
      this->mpPOI.mNext = &this->mpPOI;
    }
    this->mpPOI.m_pPointer = v4;
    if ( v4 )
    {
      v17 = v4->m_SafePointerList.mNode.mPrev;
      v17->mNext = p_mpPOI;
      p_mpPOI->mPrev = v17;
      this->mpPOI.mNext = &v4->m_SafePointerList.mNode;
      v4->m_SafePointerList.mNode.mPrev = p_mpPOI;
    }
    v18 = (UFG::InterestPoint *)this->mpPOI.m_pPointer;
    if ( v18 )
    {
      v19 = ePOIUseType_System;
      UFG::InterestPoint::BeginReservation(v18, context->mSimObject.m_pPointer, ReserveReason_normal);
      skipIntoLabel.mUID = UFG::gNullQSymbol.mUID;
      if ( UFG::InterestPointUseDetails::IsValid((UFG::InterestPointUseDetails *)&ComponentOfType[7].m_Flags) )
      {
        if ( ComponentOfType[7].m_BoundComponentHandles.mNode.mPrev == (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)this->mpPOI.m_pPointer )
        {
          v19 = (UFG::ePOIUseType)ComponentOfType[7].m_BoundComponentHandles.mNode.mNext;
          skipIntoLabel.mUID = HIDWORD(ComponentOfType[7].m_BoundComponentHandles.mNode.mNext);
        }
      }
      else
      {
        UFG::InterestPointUseDetails::Set(
          (UFG::InterestPointUseDetails *)&ComponentOfType[7].m_Flags,
          (UFG::InterestPoint *)this->mpPOI.m_pPointer,
          ePOIUseType_System,
          &skipIntoLabel);
      }
      UFG::InterestPointUseDetails::Set(
        (UFG::InterestPointUseDetails *)&ComponentOfType[8],
        (UFG::InterestPoint *)this->mpPOI.m_pPointer,
        v19,
        &skipIntoLabel);
    }
  }
}

// File Line: 125
// RVA: 0x2FF3C0
void __fastcall POIManagementTask::End(POIManagementTask *this)
{
  ActionContext *mContext; // r8
  UFG::SimObject *m_pPointer; // r8
  int v4; // r14d
  UFG::SimComponent *m_pComponent; // rbx
  __int16 m_Flags; // cx
  UFG::InterestPoint *v7; // rcx
  char v8; // r12
  bool v9; // si
  char v10; // r15
  char v11; // bp
  UFG::SimObjectGame *v12; // rcx
  UFG::TargetingSystemBaseComponent *v13; // rsi
  __int16 v14; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimComponent *v16; // rdx
  __int64 v17; // r9
  UFG::SpawnPoint *OriginatingSpawnPoint; // rax
  bool allowNoInterruptResume; // [rsp+70h] [rbp+8h] BYREF

  mContext = this->mContext;
  if ( !mContext )
    return;
  m_pPointer = mContext->mSimObject.m_pPointer;
  v4 = 0;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[43].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = m_pPointer->m_Components.p[12].m_pComponent;
      }
      else if ( (m_Flags & 0x1000) != 0 )
      {
        m_pComponent = 0i64;
      }
      else
      {
        m_pComponent = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::InterestPointUserComponent::_TypeUID);
      }
    }
    else
    {
      m_pComponent = 0i64;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  v7 = (UFG::InterestPoint *)this->mpPOI.m_pPointer;
  if ( v7 )
  {
    if ( !m_pComponent )
      return;
    allowNoInterruptResume = 0;
    v8 = 0;
    v9 = UFG::InterestPoint::WantsToResume(v7, &allowNoInterruptResume);
    UFG::InterestPoint::EndReservation((UFG::InterestPoint *)this->mpPOI.m_pPointer);
    v10 = 1;
    if ( allowNoInterruptResume
      && UFG::InterestPointUseDetails::operator==(
           (UFG::InterestPointUseDetails *)&m_pComponent[7].m_Flags,
           (UFG::InterestPointUseDetails *)&m_pComponent[8])
      && m_pComponent[8].m_TypeUID == 3 )
    {
      v10 = 0;
    }
    else if ( !v9 )
    {
      goto LABEL_22;
    }
    if ( (this->mContext->mSimObject.m_pPointer->m_Flags & 2) == 0 )
    {
      v11 = 1;
      goto LABEL_23;
    }
LABEL_22:
    v11 = 0;
LABEL_23:
    v12 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
    if ( v12 )
    {
      v14 = v12->m_Flags;
      if ( (v14 & 0x4000) != 0 )
      {
        v13 = (UFG::TargetingSystemBaseComponent *)v12->m_Components.p[20].m_pComponent;
      }
      else if ( v14 >= 0 )
      {
        if ( (v14 & 0x2000) != 0 || (v14 & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::TargetingSystemBaseComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v12, UFG::TargetingSystemBaseComponent::_TypeUID);
        v13 = (UFG::TargetingSystemBaseComponent *)ComponentOfTypeHK;
      }
      else
      {
        v13 = (UFG::TargetingSystemBaseComponent *)v12->m_Components.p[20].m_pComponent;
      }
      if ( v13 )
      {
        v16 = this->mpPOI.m_pPointer;
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
              (UFG::InterestPoint *)this->mpPOI.m_pPointer,
              this->mContext->mSimObject.m_pPointer,
              ReserveReason_resume) )
      {
        goto LABEL_45;
      }
    }
    else if ( !v11 )
    {
LABEL_45:
      if ( v13
        && v8
        && (!UFG::InterestPointUseDetails::IsValid((UFG::InterestPointUseDetails *)&m_pComponent[7].m_Flags)
         || m_pComponent[7].m_BoundComponentHandles.mNode.mPrev != (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)this->mpPOI.m_pPointer
         || !UFG::InterestPointUseDetails::operator!=(
               (UFG::InterestPointUseDetails *)&m_pComponent[7].m_Flags,
               (UFG::InterestPointUseDetails *)&m_pComponent[8])) )
      {
        LOBYTE(v17) = 1;
        ((void (__fastcall *)(UFG::TargetingSystemBaseComponent *, __int64, _QWORD, __int64, _DWORD, char *, ActionContext *, ITrack *))v13->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[14].__vecDelDtor)(
          v13,
          26i64,
          0i64,
          v17,
          0,
          &customCaption,
          this->mContext,
          this->m_Track);
        UFG::TargetingSystemBaseComponent::ClearTarget(v13, eTARGET_TYPE_POI_USE);
      }
      if ( UFG::InterestPointUseDetails::operator==(
             (UFG::InterestPointUseDetails *)&m_pComponent[8],
             (UFG::InterestPointUseDetails *)&m_pComponent[7].m_Flags) )
      {
        UFG::InterestPointUseDetails::Reset((UFG::InterestPointUseDetails *)&m_pComponent[7].m_Flags);
      }
      UFG::ActiveInterestPoint::Reset((UFG::ActiveInterestPoint *)&m_pComponent[8]);
      return;
    }
    LOBYTE(m_pComponent[8].m_Flags) = 0;
    LOBYTE(v4) = v10 != 0;
    if ( UFG::InterestPoint::BeginReservation(
           (UFG::InterestPoint *)this->mpPOI.m_pPointer,
           this->mContext->mSimObject.m_pPointer,
           (UFG::InterestPoint::eReserveReason)(v4 + 1)) )
    {
      return;
    }
    goto LABEL_45;
  }
  if ( m_pComponent )
  {
    if ( HIDWORD(m_pComponent[7].m_BoundComponentHandles.mNode.mNext) == qSymbol_Link.mUID )
    {
      OriginatingSpawnPoint = UFG::GetOriginatingSpawnPoint(this->mContext->mSimObject.m_pPointer);
      if ( OriginatingSpawnPoint )
        UFG::SpawnPoint::UpdateLinks(OriginatingSpawnPoint, 0);
    }
  }
}

// File Line: 251
// RVA: 0x2F0FB0
void __fastcall POIDisableSelfTask::Begin(POIDisableSelfTask *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObject *v7; // rcx
  __int16 v8; // dx
  UFG::InterestPoint *ComponentOfType; // rax

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                              m_pPointer,
                              UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = ComponentOfTypeHK;
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    if ( m_pComponent )
    {
      v7 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + 34i64)
                              + *(_QWORD *)&m_pComponent[1].m_TypeUID
                              + 40);
      if ( v7 )
      {
        v8 = v7->m_Flags;
        if ( (v8 & 0x4000) != 0 )
        {
          ComponentOfType = (UFG::InterestPoint *)v7->m_Components.p[25].m_pComponent;
        }
        else if ( v8 >= 0 )
        {
          if ( (v8 & 0x2000) != 0 )
          {
            ComponentOfType = (UFG::InterestPoint *)v7->m_Components.p[10].m_pComponent;
          }
          else if ( (v8 & 0x1000) != 0 )
          {
            ComponentOfType = (UFG::InterestPoint *)v7->m_Components.p[3].m_pComponent;
          }
          else
          {
            ComponentOfType = (UFG::InterestPoint *)UFG::SimObject::GetComponentOfType(v7, UFG::InterestPoint::_TypeUID);
          }
        }
        else
        {
          ComponentOfType = (UFG::InterestPoint *)v7->m_Components.p[25].m_pComponent;
        }
        if ( ComponentOfType )
          UFG::InterestPoint::SetActive(ComponentOfType, 0, LOBYTE(this->m_Track[1].vfptr) != 0);
      }
    }
  }
}

// File Line: 269
// RVA: 0x2EF9B0
void __fastcall InteractionPointInteractWithBestTask::Begin(
        InteractionPointInteractWithBestTask *this,
        ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // r8
  __int16 m_Flags; // cx
  UFG::InteractorComponent *m_pComponent; // rax
  UFG::InteractionPoint *v5; // rdx

  this->m_pContext = pContext;
  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::InteractorComponent *)m_pPointer->m_Components.p[29].m_pComponent;
    }
    else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      m_pComponent = (UFG::InteractorComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   m_pPointer,
                                                   UFG::InteractorComponent::_TypeUID);
    }
    else
    {
      m_pComponent = (UFG::InteractorComponent *)UFG::SimObject::GetComponentOfType(
                                                   m_pPointer,
                                                   UFG::InteractorComponent::_TypeUID);
    }
    if ( m_pComponent )
    {
      v5 = m_pComponent->m_pBestInteractionPoint.m_pPointer;
      if ( v5 )
        UFG::InteractorComponent::StartInteraction(m_pComponent, v5, 1);
    }
  }
}

// File Line: 306
// RVA: 0x2FEDD0
void __fastcall InteractionPointInteractWithBestTask::End(InteractionPointInteractWithBestTask *this)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::InteractorComponent *m_pComponent; // rax

  m_pPointer = (UFG::SimObjectGame *)this->m_pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::InteractorComponent *)m_pPointer->m_Components.p[29].m_pComponent;
    }
    else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      m_pComponent = (UFG::InteractorComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   m_pPointer,
                                                   UFG::InteractorComponent::_TypeUID);
    }
    else
    {
      m_pComponent = (UFG::InteractorComponent *)UFG::SimObject::GetComponentOfType(
                                                   m_pPointer,
                                                   UFG::InteractorComponent::_TypeUID);
    }
    if ( m_pComponent )
      UFG::InteractorComponent::StopInteraction(m_pComponent, 1);
  }
}

// File Line: 327
// RVA: 0x2EFA50
void __fastcall InteractionPointSetupTask::Begin(InteractionPointSetupTask *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  ITrack *m_Track; // rcx
  __int64 v8; // rax
  __int64 v9; // r8
  int v10; // ecx

  this->m_pContext = pContext;
  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[12].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::InteractableComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::InteractableComponent::_TypeUID);
      m_pComponent = ComponentOfTypeHK;
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[12].m_pComponent;
    }
    if ( m_pComponent )
    {
      m_Track = this->m_Track;
      v8 = (unsigned int)LOBYTE(m_Track[1].vfptr) - 69;
      if ( LOBYTE(m_Track[1].vfptr) == 69 )
      {
        v8 = 0i64;
      }
      else if ( (unsigned int)v8 >= 5 )
      {
        v8 = 5i64;
      }
      v9 = 160 * v8;
      BYTE4((&m_pComponent[2].m_BoundComponentHandles.mNode.mPrev)[(unsigned __int64)v9 / 8]) = BYTE1(m_Track[1].vfptr) != 0;
      v10 = BYTE2(this->m_Track[1].vfptr);
      *(_DWORD *)((char *)&m_pComponent[2].m_SafePointerList.mNode.mPrev + v9) = v10;
      if ( v10 == 2 )
      {
        *(_DWORD *)((char *)&m_pComponent[2].m_pSimObject + v9) = HIDWORD(this->m_Track[1].vfptr);
      }
      else if ( v10 == 3 )
      {
        *(_DWORD *)((char *)&m_pComponent[2].m_pSimObject + v9 + 4) = this->m_Track[1].mResourceOwner;
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
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::InteractableComponent *m_pComponent; // rcx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  if ( BYTE4(this->m_Track[1].mResourceOwner) )
  {
    m_pPointer = (UFG::SimObjectGame *)this->m_pContext->mSimObject.m_pPointer;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = (UFG::InteractableComponent *)m_pPointer->m_Components.p[12].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::InteractableComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::InteractableComponent::_TypeUID);
        m_pComponent = (UFG::InteractableComponent *)ComponentOfTypeHK;
      }
      else
      {
        m_pComponent = (UFG::InteractableComponent *)m_pPointer->m_Components.p[12].m_pComponent;
      }
      if ( m_pComponent )
        UFG::InteractableComponent::SetIsActive(m_pComponent, (UFG::eTargetTypeEnum)LOBYTE(this->m_Track[1].vfptr), 0);
    }
  }
}

// File Line: 374
// RVA: 0x2EF860
void __fastcall InteractionPointActivateTask::Begin(InteractionPointActivateTask *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::InteractableComponent *m_pComponent; // rcx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  this->m_pContext = pContext;
  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::InteractableComponent *)m_pPointer->m_Components.p[12].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::InteractableComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::InteractableComponent::_TypeUID);
      m_pComponent = (UFG::InteractableComponent *)ComponentOfTypeHK;
    }
    else
    {
      m_pComponent = (UFG::InteractableComponent *)m_pPointer->m_Components.p[12].m_pComponent;
    }
    if ( m_pComponent )
      UFG::InteractableComponent::SetIsActive(m_pComponent, (UFG::eTargetTypeEnum)LOBYTE(this->m_Track[1].vfptr), 1);
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
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::InteractableComponent *m_pComponent; // rcx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  if ( BYTE1(this->m_Track[1].vfptr) )
  {
    m_pPointer = (UFG::SimObjectGame *)this->m_pContext->mSimObject.m_pPointer;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = (UFG::InteractableComponent *)m_pPointer->m_Components.p[12].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::InteractableComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::InteractableComponent::_TypeUID);
        m_pComponent = (UFG::InteractableComponent *)ComponentOfTypeHK;
      }
      else
      {
        m_pComponent = (UFG::InteractableComponent *)m_pPointer->m_Components.p[12].m_pComponent;
      }
      if ( m_pComponent )
        UFG::InteractableComponent::SetIsActive(m_pComponent, (UFG::eTargetTypeEnum)LOBYTE(this->m_Track[1].vfptr), 0);
    }
  }
}

// File Line: 410
// RVA: 0x2EF910
void __fastcall InteractionPointDeactivateTask::Begin(InteractionPointDeactivateTask *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::InteractableComponent *m_pComponent; // rcx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::InteractableComponent *)m_pPointer->m_Components.p[12].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::InteractableComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::InteractableComponent::_TypeUID);
      m_pComponent = (UFG::InteractableComponent *)ComponentOfTypeHK;
    }
    else
    {
      m_pComponent = (UFG::InteractableComponent *)m_pPointer->m_Components.p[12].m_pComponent;
    }
    if ( m_pComponent )
      UFG::InteractableComponent::SetIsActive(m_pComponent, (UFG::eTargetTypeEnum)LOBYTE(this->m_Track[1].vfptr), 0);
  }
}

// File Line: 424
// RVA: 0x2F10F0
void __fastcall POIEnableChildTask::Begin(POIEnableChildTask *this, ActionContext *pActionContext)
{
  UFG::SimObject *Target; // rax
  __int16 m_Flags; // r8
  UFG::InterestPoint *m_pComponent; // rbx
  ITrack *m_Track; // rax
  Expression::IMemberMapVtbl *vfptr; // rcx
  ITrack *v8; // rax
  unsigned __int64 v9; // rcx
  const char *v10; // rcx
  bool v11; // cc
  ITrack *v12; // rax
  ITrack *v13; // rax
  const char *v14; // rdx
  UFG::SimObject *Child; // rax
  __int16 v16; // dx
  UFG::InterestPoint *ComponentOfType; // rax
  UFG::qSymbol childName; // [rsp+38h] [rbp+10h] BYREF

  Target = UFG::getTarget(pActionContext->mSimObject.m_pPointer, eTARGET_TYPE_POI_USE);
  if ( Target )
  {
    m_Flags = Target->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::InterestPoint *)Target->m_Components.p[25].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
        m_pComponent = (UFG::InterestPoint *)Target->m_Components.p[10].m_pComponent;
      else
        m_pComponent = (UFG::InterestPoint *)((m_Flags & 0x1000) != 0
                                            ? Target->m_Components.p[3].m_pComponent
                                            : UFG::SimObject::GetComponentOfType(Target, UFG::InterestPoint::_TypeUID));
    }
    else
    {
      m_pComponent = (UFG::InterestPoint *)Target->m_Components.p[25].m_pComponent;
    }
    if ( m_pComponent )
    {
      m_Track = this->m_Track;
      vfptr = m_Track[1].vfptr;
      v8 = m_Track + 1;
      v9 = (unsigned __int64)vfptr & 0xFFFFFFFFFFFFFFFEui64;
      if ( v9 )
        v10 = (char *)v8 + v9;
      else
        v10 = BinString::sEmptyString;
      v11 = (int)UFG::qStringLength(v10) <= 0;
      v12 = this->m_Track;
      if ( v11 )
      {
        Child = UFG::InterestPoint::GetChild(m_pComponent, (unsigned int)v12[1].mResourceOwner);
      }
      else
      {
        v13 = v12 + 1;
        childName.mUID = -1;
        v14 = (char *)v13 + ((unsigned __int64)v13->vfptr & 0xFFFFFFFFFFFFFFFEui64);
        if ( ((unsigned __int64)v13->vfptr & 0xFFFFFFFFFFFFFFFEui64) == 0 )
          v14 = BinString::sEmptyString;
        UFG::qSymbol::set_from_cstr(&childName, v14);
        Child = UFG::InterestPoint::GetChild(m_pComponent, &childName);
      }
      if ( Child )
      {
        v16 = Child->m_Flags;
        if ( (v16 & 0x4000) != 0 )
        {
          ComponentOfType = (UFG::InterestPoint *)Child->m_Components.p[25].m_pComponent;
        }
        else if ( v16 >= 0 )
        {
          if ( (v16 & 0x2000) != 0 )
          {
            ComponentOfType = (UFG::InterestPoint *)Child->m_Components.p[10].m_pComponent;
          }
          else if ( (v16 & 0x1000) != 0 )
          {
            ComponentOfType = (UFG::InterestPoint *)Child->m_Components.p[3].m_pComponent;
          }
          else
          {
            ComponentOfType = (UFG::InterestPoint *)UFG::SimObject::GetComponentOfType(
                                                      Child,
                                                      UFG::InterestPoint::_TypeUID);
          }
        }
        else
        {
          ComponentOfType = (UFG::InterestPoint *)Child->m_Components.p[25].m_pComponent;
        }
        if ( ComponentOfType )
          UFG::InterestPoint::SetActive(
            ComponentOfType,
            BYTE4(this->m_Track[1].mResourceOwner) != 0,
            BYTE5(this->m_Track[1].mResourceOwner) != 0);
      }
    }
  }
}

