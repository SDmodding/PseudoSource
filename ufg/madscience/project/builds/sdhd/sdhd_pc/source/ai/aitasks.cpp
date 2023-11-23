// File Line: 102
// RVA: 0x360EF0
UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *__fastcall GetNextPathNode(
        UFG::TransformNodeComponent *pNode,
        UFG::AIMarker **ppNextMarker)
{
  UFG::TransformNodeComponent *mParent; // rax
  UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *v4; // rdi
  UFG::SimObjectGame *mNext; // rbx
  UFG::AIMarker *ComponentOfType; // rax
  __int16 m_Flags; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  *ppNextMarker = 0i64;
  mParent = pNode->mParent;
  if ( !mParent )
    return 0i64;
  v4 = pNode->mNext - 4;
  if ( v4 == (UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *)&mParent->m_SafePointerList.mNode.mNext )
    return 0i64;
  mNext = (UFG::SimObjectGame *)v4[2].mNext;
  if ( !mNext )
    return 0i64;
  ComponentOfType = (UFG::AIMarker *)UFG::SimObject::GetComponentOfType(
                                       (UFG::SimObject *)v4[2].mNext,
                                       UFG::AIMarker::_TypeUID);
  if ( ComponentOfType )
  {
    *ppNextMarker = ComponentOfType;
    return v4;
  }
  m_Flags = mNext->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(mNext, UFG::MarkerBase::_TypeUID);
  else
    ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(mNext, UFG::MarkerBase::_TypeUID);
  if ( !ComponentOfTypeHK )
    return 0i64;
  *ppNextMarker = 0i64;
  return v4;
}

// File Line: 134
// RVA: 0x389390
void __fastcall SubmitPathPoints(UFG::NavComponent *pNC, UFG::qSymbol *pathName)
{
  UFG::qBaseTreeRB *Named; // rax
  UFG::qBaseTreeRB *v4; // rbx
  char *v5; // rax
  __int64 v6; // rdi
  char v7; // bp
  float v8; // xmm7_4
  UFG::SimObject *v9; // rcx
  UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *NextPathNode; // rdi
  UFG::AIMarker *ComponentOfType; // rbx
  float fDestinationTolerance; // xmm6_4
  int MoveType; // eax
  UFG::AiPathGoalMode v14; // r8d
  __m128 mPrev_low; // xmm3
  __m128 mPrev_high; // xmm2
  __m128 mNext_low; // xmm0
  UFG::HavokNavPosition npDestination; // [rsp+30h] [rbp-A8h] BYREF
  UFG::AIMarker *ppNextMarker; // [rsp+F0h] [rbp+18h] BYREF

  Named = UFG::MarkerBase::GetNamed(pathName);
  v4 = Named;
  if ( Named )
  {
    v5 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)Named->mNULL.mChild[0][2].mChild);
    UFG::qPrintf("PathBegin (%s)\n", v5);
    v6 = *(_QWORD *)&v4[1].mNULL.mParent[2].mUID;
    v7 = 1;
    v8 = FLOAT_N1_0;
    v9 = *(UFG::SimObject **)(v6 - 24);
    NextPathNode = (UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *)(v6 - 64);
    if ( v9 )
    {
      ComponentOfType = (UFG::AIMarker *)UFG::SimObject::GetComponentOfType(v9, UFG::AIMarker::_TypeUID);
      ppNextMarker = ComponentOfType;
    }
    else
    {
      ComponentOfType = 0i64;
      ppNextMarker = 0i64;
    }
    while ( 1 )
    {
      fDestinationTolerance = FLOAT_N1_0;
      if ( ComponentOfType )
      {
        fDestinationTolerance = UFG::AIMarker::GetArrivalTolerance(ComponentOfType, ComponentOfType->m_pSimObject);
        MoveType = UFG::AIMarker::GetMoveType(ComponentOfType, ComponentOfType->m_pSimObject);
        if ( MoveType )
          v8 = sNaturalMovementSpeeds[MoveType];
      }
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)NextPathNode);
      v14 = AiGoal_Append;
      mPrev_low = (__m128)LODWORD(NextPathNode[11].mPrev);
      mPrev_high = (__m128)HIDWORD(NextPathNode[11].mPrev);
      mNext_low = (__m128)LODWORD(NextPathNode[11].mNext);
      if ( v7 )
        v14 = AiGoal_Replace;
      npDestination.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
      npDestination.m_bValid = 0;
      LODWORD(npDestination.m_vPosition.x) = mPrev_low.m128_i32[0];
      LODWORD(npDestination.m_vPosition.y) = mPrev_high.m128_i32[0];
      LODWORD(npDestination.m_vPosition.z) = mNext_low.m128_i32[0];
      *(_QWORD *)&npDestination.m_packedKey = -1i64;
      npDestination.m_hkvMeshPosition.m_quad = _mm_unpacklo_ps(
                                                 _mm_unpacklo_ps(mPrev_low, mNext_low),
                                                 _mm_unpacklo_ps(mPrev_high, (__m128)(unsigned int)FLOAT_1_0));
      UFG::NavComponent::AddGoalPoint(pNC, &npDestination, v14, v8, fDestinationTolerance);
      v7 = 0;
      NextPathNode = GetNextPathNode((UFG::TransformNodeComponent *)NextPathNode, &ppNextMarker);
      if ( !NextPathNode )
        break;
      ComponentOfType = ppNextMarker;
    }
  }
}

// File Line: 182
// RVA: 0x3479F0
void __fastcall PerformScriptCommandTask::Begin(PerformScriptCommandTask *this, ActionContext *context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::SimComponent *v4; // rbx
  UFG::SimComponent *v6; // r8
  __int16 m_Flags; // dx
  UFG::ActiveAIEntityComponent *ComponentOfTypeHK; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pAIEntityComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::SimObjectGame *v13; // rcx
  UFG::SimComponent *m_pComponent; // r8
  __int16 v15; // dx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AIScriptInterfaceComponent> *p_m_pAIScriptInterfaceComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rax
  UFG::SimObject *v21; // rcx
  UFG::SimComponent *v22; // rax
  __int16 v23; // dx
  UFG::qSafePointer<UFG::SimComponent,UFG::TSActorComponent> *p_m_pActorComponent; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v25; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v26; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *p_mNode; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v28; // rax
  UFG::SimObjectGame *v29; // rcx
  __int16 v30; // dx
  UFG::SimComponent *v31; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActionTreeComponent> *p_m_pActionTreeComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v33; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v34; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v35; // rax
  UFG::TSActorComponent *v36; // rcx
  UFG::TSActor *Actor; // rax
  UFG::qNode<IFinishUpdate,IFinishUpdate> *mActionController; // rdx
  UFG::qNode<IFinishUpdate,IFinishUpdate> *v39; // rax
  UFG::SimComponent *v40; // rax

  this->m_pActionContext = context;
  m_pPointer = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  v4 = 0i64;
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
    v6 = ComponentOfTypeHK;
  }
  else
  {
    v6 = 0i64;
  }
  p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
  if ( this->m_pAIEntityComponent.m_pPointer )
  {
    mPrev = p_m_pAIEntityComponent->mPrev;
    mNext = this->m_pAIEntityComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
    this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
  }
  this->m_pAIEntityComponent.m_pPointer = v6;
  if ( v6 )
  {
    v12 = v6->m_SafePointerList.mNode.mPrev;
    v12->mNext = p_m_pAIEntityComponent;
    p_m_pAIEntityComponent->mPrev = v12;
    this->m_pAIEntityComponent.mNext = &v6->m_SafePointerList.mNode;
    v6->m_SafePointerList.mNode.mPrev = p_m_pAIEntityComponent;
  }
  v13 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v13 )
  {
    v15 = v13->m_Flags;
    if ( (v15 & 0x4000) != 0 )
    {
      m_pComponent = v13->m_Components.p[5].m_pComponent;
    }
    else if ( v15 >= 0 )
    {
      if ( (v15 & 0x2000) != 0 || (v15 & 0x1000) != 0 )
        ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::AIScriptInterfaceComponent::_TypeUID);
      else
        ComponentOfType = UFG::SimObject::GetComponentOfType(v13, UFG::AIScriptInterfaceComponent::_TypeUID);
      m_pComponent = ComponentOfType;
    }
    else
    {
      m_pComponent = v13->m_Components.p[5].m_pComponent;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  p_m_pAIScriptInterfaceComponent = &this->m_pAIScriptInterfaceComponent;
  if ( this->m_pAIScriptInterfaceComponent.m_pPointer )
  {
    v18 = p_m_pAIScriptInterfaceComponent->mPrev;
    v19 = this->m_pAIScriptInterfaceComponent.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    p_m_pAIScriptInterfaceComponent->mPrev = p_m_pAIScriptInterfaceComponent;
    this->m_pAIScriptInterfaceComponent.mNext = &this->m_pAIScriptInterfaceComponent;
  }
  this->m_pAIScriptInterfaceComponent.m_pPointer = m_pComponent;
  if ( m_pComponent )
  {
    v20 = m_pComponent->m_SafePointerList.mNode.mPrev;
    v20->mNext = p_m_pAIScriptInterfaceComponent;
    p_m_pAIScriptInterfaceComponent->mPrev = v20;
    this->m_pAIScriptInterfaceComponent.mNext = &m_pComponent->m_SafePointerList.mNode;
    m_pComponent->m_SafePointerList.mNode.mPrev = p_m_pAIScriptInterfaceComponent;
  }
  v21 = context->mSimObject.m_pPointer;
  if ( v21 )
  {
    v23 = v21->m_Flags;
    if ( (v23 & 0x4000) != 0 )
    {
      v22 = v21->m_Components.p[4].m_pComponent;
    }
    else if ( v23 >= 0 )
    {
      if ( (v23 & 0x2000) != 0 )
      {
        v22 = v21->m_Components.p[3].m_pComponent;
      }
      else if ( (v23 & 0x1000) != 0 )
      {
        v22 = v21->m_Components.p[2].m_pComponent;
      }
      else
      {
        v22 = UFG::SimObject::GetComponentOfType(v21, UFG::TSActorComponent::_TypeUID);
      }
    }
    else
    {
      v22 = v21->m_Components.p[4].m_pComponent;
    }
  }
  else
  {
    v22 = 0i64;
  }
  p_m_pActorComponent = &this->m_pActorComponent;
  if ( this->m_pActorComponent.m_pPointer )
  {
    v25 = p_m_pActorComponent->mPrev;
    v26 = this->m_pActorComponent.mNext;
    v25->mNext = v26;
    v26->mPrev = v25;
    p_m_pActorComponent->mPrev = p_m_pActorComponent;
    this->m_pActorComponent.mNext = &this->m_pActorComponent;
  }
  this->m_pActorComponent.m_pPointer = v22;
  if ( v22 )
  {
    p_mNode = &v22->m_SafePointerList.mNode;
    v28 = v22->m_SafePointerList.mNode.mPrev;
    v28->mNext = p_m_pActorComponent;
    p_m_pActorComponent->mPrev = v28;
    this->m_pActorComponent.mNext = p_mNode;
    p_mNode->mPrev = p_m_pActorComponent;
  }
  v29 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v29 )
  {
    v30 = v29->m_Flags;
    if ( (v30 & 0x4000) != 0 )
    {
      v4 = v29->m_Components.p[7].m_pComponent;
    }
    else if ( v30 >= 0 )
    {
      if ( (v30 & 0x2000) != 0 )
      {
        v4 = v29->m_Components.p[6].m_pComponent;
      }
      else
      {
        if ( (v30 & 0x1000) != 0 )
          v31 = UFG::SimObjectGame::GetComponentOfTypeHK(v29, UFG::ActionTreeComponent::_TypeUID);
        else
          v31 = UFG::SimObject::GetComponentOfType(v29, UFG::ActionTreeComponent::_TypeUID);
        v4 = v31;
      }
    }
    else
    {
      v4 = v29->m_Components.p[7].m_pComponent;
    }
  }
  p_m_pActionTreeComponent = &this->m_pActionTreeComponent;
  if ( this->m_pActionTreeComponent.m_pPointer )
  {
    v33 = p_m_pActionTreeComponent->mPrev;
    v34 = this->m_pActionTreeComponent.mNext;
    v33->mNext = v34;
    v34->mPrev = v33;
    p_m_pActionTreeComponent->mPrev = p_m_pActionTreeComponent;
    this->m_pActionTreeComponent.mNext = &this->m_pActionTreeComponent;
  }
  this->m_pActionTreeComponent.m_pPointer = v4;
  if ( v4 )
  {
    v35 = v4->m_SafePointerList.mNode.mPrev;
    v35->mNext = p_m_pActionTreeComponent;
    p_m_pActionTreeComponent->mPrev = v35;
    this->m_pActionTreeComponent.mNext = &v4->m_SafePointerList.mNode;
    v4->m_SafePointerList.mNode.mPrev = p_m_pActionTreeComponent;
  }
  v36 = (UFG::TSActorComponent *)this->m_pActorComponent.m_pPointer;
  if ( v36 && UFG::TSActorComponent::GetActor(v36) )
  {
    Actor = UFG::TSActorComponent::GetActor((UFG::TSActorComponent *)this->m_pActorComponent.m_pPointer);
    Actor->i_actor_flags |= 4u;
  }
  mActionController = (UFG::qNode<IFinishUpdate,IFinishUpdate> *)context->mActionController;
  v39 = mActionController[7].mNext;
  mActionController = (UFG::qNode<IFinishUpdate,IFinishUpdate> *)((char *)mActionController + 120);
  v39->mNext = &this->UFG::qNode<IFinishUpdate,IFinishUpdate>;
  this->IFinishUpdate::UFG::qNode<IFinishUpdate,IFinishUpdate>::mPrev = v39;
  this->IFinishUpdate::UFG::qNode<IFinishUpdate,IFinishUpdate>::mNext = mActionController;
  mActionController->mPrev = &this->UFG::qNode<IFinishUpdate,IFinishUpdate>;
  v40 = this->m_pAIScriptInterfaceComponent.m_pPointer;
  if ( v40 )
    BYTE1(v40[32].m_BoundComponentHandles.mNode.mPrev) &= ~0x80u;
}

// File Line: 204
// RVA: 0x3919A0
bool __fastcall PerformScriptCommandTask::Update(PerformScriptCommandTask *this, float timeDelta)
{
  UFG::SimComponent *m_pPointer; // rdx
  UFG::SimComponent *v4; // r8
  UFG::NavComponent *v5; // rbx
  UFG::SimObjectGame *v6; // rcx
  UFG::NavComponent *m_pComponent; // rcx
  __int16 v8; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  unsigned int mPrev; // eax
  float v11; // xmm6_4
  UFG::SimObjectGame *v12; // rcx
  __int16 v13; // dx
  unsigned int v14; // edx
  UFG::SimComponent *ComponentOfType; // rax
  bool v16; // zf
  __int16 m_Flags; // dx
  UFG::CharacterControllerInterface *v18; // rcx
  const char *v19; // rbp
  const char *mNext; // rsi
  bool v21; // bl
  unsigned __int8 IsPlaying; // al
  UFG::SimComponent *v23; // rdx
  UFG::SimObjectCVBase *v24; // rcx
  UFG::AICharacterControllerBaseComponent *v25; // rbx
  __int16 v26; // dx
  UFG::AICharacterControllerBaseComponent *v27; // rax
  unsigned int v28; // edx
  UFG::SimObjectCVBase *v29; // rcx
  __int16 v30; // dx
  UFG::AICharacterControllerBaseComponent *v31; // rax
  float v32; // xmm5_4
  __m128 v33; // xmm4
  float v34; // xmm6_4
  __m128 v35; // xmm3
  float v36; // xmm2_4
  int v37; // eax
  float v38; // xmm6_4
  __m128 v39; // xmm7
  float v40; // xmm8_4
  __int64 v41; // rbx
  UFG::SimObjectCVBase *v42; // rcx
  __int16 v43; // dx
  UFG::AICharacterControllerBaseComponent *v44; // rax
  UFG::AICharacterControllerBaseComponent *v45; // rsi
  UFG::TransformNodeComponent *v46; // rbx
  float v47; // xmm6_4
  float v48; // xmm8_4
  __m128 v49; // xmm3
  float v50; // xmm2_4
  float mMotionIntentionSpeed; // xmm0_4
  ActionID v53; // [rsp+20h] [rbp-88h] BYREF
  __int64 v54; // [rsp+28h] [rbp-80h]
  UFG::qString v55; // [rsp+30h] [rbp-78h] BYREF
  UFG::qSymbol pathName; // [rsp+B0h] [rbp+8h] BYREF
  UFG::qSymbol *action_request; // [rsp+C0h] [rbp+18h] BYREF
  ActionID node_id; // [rsp+C8h] [rbp+20h] BYREF

  v54 = -2i64;
  m_pPointer = this->m_pAIScriptInterfaceComponent.m_pPointer;
  if ( m_pPointer )
  {
    if ( !m_pPointer[1].m_TypeUID )
      return HIDWORD(m_pPointer[1].m_SafePointerList.mNode.mNext) != 0;
    v4 = this->m_pAIEntityComponent.m_pPointer;
    if ( v4 )
    {
      switch ( m_pPointer[1].m_TypeUID )
      {
        case 1u:
        case 2u:
          v11 = *((float *)&m_pPointer[1].m_BoundComponentHandles.mNode.mNext + 1);
          v12 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
          if ( !v12 )
          {
            v5 = 0i64;
            goto LABEL_28;
          }
          m_Flags = v12->m_Flags;
          if ( (m_Flags & 0x4000) != 0 )
            goto LABEL_20;
          if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 )
            goto LABEL_22;
          v16 = (m_Flags & 0x1000) == 0;
          v14 = UFG::NavComponent::_TypeUID;
          if ( v16 )
            goto LABEL_26;
          goto LABEL_23;
        case 3u:
          v5 = 0i64;
          if ( SBYTE1(m_pPointer[32].m_BoundComponentHandles.mNode.mPrev) >= 0 )
          {
            v6 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
            if ( v6 )
            {
              v8 = v6->m_Flags;
              if ( (v8 & 0x4000) != 0 )
              {
                m_pComponent = (UFG::NavComponent *)v6->m_Components.p[36].m_pComponent;
              }
              else
              {
                if ( v8 < 0 || (v8 & 0x2000) != 0 || (v8 & 0x1000) != 0 )
                  ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::NavComponent::_TypeUID);
                else
                  ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v6, UFG::NavComponent::_TypeUID);
                m_pComponent = (UFG::NavComponent *)ComponentOfTypeHK;
              }
            }
            else
            {
              m_pComponent = 0i64;
            }
            mPrev = (unsigned int)this->m_pAIScriptInterfaceComponent.m_pPointer[3].m_SafePointerList.mNode.mPrev;
            action_request = &pathName;
            pathName.mUID = mPrev;
            SubmitPathPoints(m_pComponent, &pathName);
            BYTE1(this->m_pAIScriptInterfaceComponent.m_pPointer[32].m_BoundComponentHandles.mNode.mPrev) |= 0x80u;
          }
          v11 = *((float *)&this->m_pAIScriptInterfaceComponent.m_pPointer[1].m_BoundComponentHandles.mNode.mNext + 1);
          v12 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
          if ( !v12 )
            goto LABEL_28;
          v13 = v12->m_Flags;
          if ( (v13 & 0x4000) != 0 )
          {
LABEL_20:
            v5 = (UFG::NavComponent *)v12->m_Components.p[36].m_pComponent;
            goto LABEL_28;
          }
          if ( v13 < 0 || (v13 & 0x2000) != 0 )
          {
LABEL_22:
            v14 = UFG::NavComponent::_TypeUID;
          }
          else
          {
            v16 = (v13 & 0x1000) == 0;
            v14 = UFG::NavComponent::_TypeUID;
            if ( v16 )
            {
LABEL_26:
              ComponentOfType = UFG::SimObject::GetComponentOfType(v12, v14);
LABEL_27:
              v5 = (UFG::NavComponent *)ComponentOfType;
LABEL_28:
              UFG::NavComponent::SetDesiredSpeed(v5, v11);
              return 1;
            }
          }
LABEL_23:
          ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v12, v14);
          goto LABEL_27;
        case 4u:
          v18 = (UFG::CharacterControllerInterface *)v4[24].m_BoundComponentHandles.mNode.mPrev;
          if ( v18 )
            UFG::CharacterControllerInterface::PlayActionNode(
              v18,
              (const char *)m_pPointer[1].m_BoundComponentHandles.mNode.mPrev);
          return 1;
        case 5u:
          v19 = (const char *)m_pPointer[1].m_BoundComponentHandles.mNode.mPrev;
          mNext = (const char *)m_pPointer[2].m_BoundComponentHandles.mNode.mNext;
          v21 = LODWORD(m_pPointer[4].m_SafePointerList.mNode.mPrev) == 1;
          UFG::qString::qString(&v55);
          if ( ((__int64)this->m_pAIScriptInterfaceComponent.m_pPointer[32].m_BoundComponentHandles.mNode.mPrev & 2) == 0 )
          {
            node_id.mUID = UFG::qStringHashUpper32(mNext, -1);
            IsPlaying = ActionController::IsPlaying(
                          (ActionController *)&this->m_pActionTreeComponent.m_pPointer[3],
                          &node_id,
                          0xFFFFFFFF,
                          1);
            v23 = this->m_pAIScriptInterfaceComponent.m_pPointer;
            LOBYTE(v23[32].m_BoundComponentHandles.mNode.mPrev) &= ~2u;
            LOBYTE(v23[32].m_BoundComponentHandles.mNode.mPrev) |= 2 * (IsPlaying & 1);
          }
          if ( ((__int64)this->m_pAIScriptInterfaceComponent.m_pPointer[32].m_BoundComponentHandles.mNode.mPrev & 2) != 0 )
          {
            if ( !v21
              || (v53.mUID = UFG::qStringHashUpper32(mNext, -1),
                  !ActionController::IsPlaying(
                     (ActionController *)&this->m_pActionTreeComponent.m_pPointer[3],
                     &v53,
                     0xFFFFFFFF,
                     1)) )
            {
              LOBYTE(this->m_pAIScriptInterfaceComponent.m_pPointer[32].m_BoundComponentHandles.mNode.mPrev) |= 4u;
            }
LABEL_57:
            UFG::qString::~qString(&v55);
            return 1;
          }
          LODWORD(action_request) = gActionRequest_Action.m_EnumValue;
          if ( !Intention::GetActionRequest(v19, (unsigned int *)&action_request) )
            goto LABEL_57;
          v24 = (UFG::SimObjectCVBase *)this->m_pActionContext->mSimObject.m_pPointer;
          if ( !v24 )
          {
            v25 = 0i64;
LABEL_53:
            Intention::Set(&v25->m_Intention, (int)action_request, 0.0);
            goto LABEL_57;
          }
          v26 = v24->m_Flags;
          if ( (v26 & 0x4000) != 0 || v26 < 0 )
          {
            v27 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v24);
          }
          else
          {
            if ( (v26 & 0x2000) != 0 )
            {
              v28 = UFG::AICharacterControllerBaseComponent::_TypeUID;
            }
            else
            {
              v16 = (v26 & 0x1000) == 0;
              v28 = UFG::AICharacterControllerBaseComponent::_TypeUID;
              if ( v16 )
              {
                v27 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                                   v24,
                                                                   UFG::AICharacterControllerBaseComponent::_TypeUID);
                goto LABEL_52;
              }
            }
            v27 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v24, v28);
          }
LABEL_52:
          v25 = v27;
          goto LABEL_53;
        case 6u:
          v29 = (UFG::SimObjectCVBase *)this->m_pActionContext->mSimObject.m_pPointer;
          if ( v29 )
          {
            v30 = v29->m_Flags;
            if ( (v30 & 0x4000) != 0 || v30 < 0 )
              v31 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v29);
            else
              v31 = (UFG::AICharacterControllerBaseComponent *)((v30 & 0x2000) != 0 || (v30 & 0x1000) != 0
                                                              ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                  v29,
                                                                  UFG::AICharacterControllerBaseComponent::_TypeUID)
                                                              : UFG::SimObject::GetComponentOfType(
                                                                  v29,
                                                                  UFG::AICharacterControllerBaseComponent::_TypeUID));
            if ( v31 )
            {
              v32 = *(float *)(&this->m_pAIScriptInterfaceComponent.m_pPointer[1].m_SimObjIndex + 1);
              v33 = (__m128)*(unsigned int *)&this->m_pAIScriptInterfaceComponent.m_pPointer[1].m_Flags;
              v34 = *(float *)&this->m_pAIScriptInterfaceComponent.m_pPointer[1].m_pSimObject;
              v35 = v33;
              v35.m128_f32[0] = (float)((float)(v33.m128_f32[0] * v33.m128_f32[0]) + (float)(v32 * v32))
                              + (float)(v34 * v34);
              v36 = 0.0;
              if ( v35.m128_f32[0] != 0.0 )
                v36 = 1.0 / _mm_sqrt_ps(v35).m128_f32[0];
              v31->m_Intention.mMotionIntentionDirection.x = v33.m128_f32[0] * v36;
              v31->m_Intention.mMotionIntentionDirection.y = v32 * v36;
              v31->m_Intention.mMotionIntentionDirection.z = v34 * v36;
            }
          }
          return 1;
        case 7u:
          v37 = *(_DWORD *)&m_pPointer[2].m_Flags;
          if ( v37 == 1 )
          {
            v38 = *(float *)&m_pPointer[1].m_Flags;
            v39 = (__m128)*(unsigned int *)(&m_pPointer[1].m_SimObjIndex + 1);
            v40 = *(float *)&m_pPointer[1].m_pSimObject;
          }
          else
          {
            if ( v37 != 6 )
              return 1;
            v41 = *(_QWORD *)&m_pPointer[2].m_TypeUID;
            if ( !v41 )
              return 1;
            UFG::TransformNodeComponent::UpdateWorldTransform(*(UFG::TransformNodeComponent **)&m_pPointer[2].m_TypeUID);
            v38 = *(float *)(v41 + 176);
            v39 = (__m128)*(unsigned int *)(v41 + 180);
            v40 = *(float *)(v41 + 184);
          }
          v42 = (UFG::SimObjectCVBase *)this->m_pActionContext->mSimObject.m_pPointer;
          if ( v42 )
          {
            v43 = v42->m_Flags;
            if ( (v43 & 0x4000) != 0 || v43 < 0 )
              v44 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v42);
            else
              v44 = (UFG::AICharacterControllerBaseComponent *)((v43 & 0x2000) != 0 || (v43 & 0x1000) != 0
                                                              ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                  v42,
                                                                  UFG::AICharacterControllerBaseComponent::_TypeUID)
                                                              : UFG::SimObject::GetComponentOfType(
                                                                  v42,
                                                                  UFG::AICharacterControllerBaseComponent::_TypeUID));
            v45 = v44;
            if ( v44 )
            {
              v46 = (UFG::TransformNodeComponent *)this->m_pActionContext->mSimObject.m_pPointer;
              if ( v46 )
                v46 = (UFG::TransformNodeComponent *)v46->mChildren.mNode.mNext;
              UFG::TransformNodeComponent::UpdateWorldTransform(v46);
              v47 = v38 - v46->mWorldTransform.v3.x;
              v39.m128_f32[0] = v39.m128_f32[0] - v46->mWorldTransform.v3.y;
              v48 = v40 - v46->mWorldTransform.v3.z;
              v49 = v39;
              v49.m128_f32[0] = (float)((float)(v39.m128_f32[0] * v39.m128_f32[0]) + (float)(v47 * v47))
                              + (float)(v48 * v48);
              v50 = 0.0;
              if ( v49.m128_f32[0] != 0.0 )
                v50 = 1.0 / _mm_sqrt_ps(v49).m128_f32[0];
              v45->m_Intention.mMotionIntentionDirection.x = v47 * v50;
              v45->m_Intention.mMotionIntentionDirection.y = v39.m128_f32[0] * v50;
              v45->m_Intention.mMotionIntentionDirection.z = v48 * v50;
              mMotionIntentionSpeed = FLOAT_0_0099999998;
              if ( v45->m_Intention.mMotionIntentionSpeed >= 0.0099999998 )
                mMotionIntentionSpeed = v45->m_Intention.mMotionIntentionSpeed;
              v45->m_Intention.mMotionIntentionSpeed = mMotionIntentionSpeed;
            }
          }
          return 1;
        default:
          return 1;
      }
    }
  }
  return 0;
}

// File Line: 466
// RVA: 0x3581A0
void __fastcall PerformScriptCommandTask::FinishUpdate(PerformScriptCommandTask *this)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rax

  mPrev = this->m_pAIEntityComponent.mPrev;
  if ( mPrev )
  {
    LODWORD(mPrev[5].mNext) = 0;
    LODWORD(mPrev[28].mNext) = 0;
  }
}

// File Line: 487
// RVA: 0x3553E0
void __fastcall PerformScriptCommandTask::End(PerformScriptCommandTask *this)
{
  UFG::SimComponent *m_pPointer; // rax
  UFG::SimComponent *v3; // rax
  UFG::TSActorComponent *v4; // rcx
  UFG::TSActor *Actor; // rax
  UFG::qNode<IFinishUpdate,IFinishUpdate> *mPrev; // rcx
  UFG::qNode<IFinishUpdate,IFinishUpdate> *mNext; // rax

  m_pPointer = this->m_pAIEntityComponent.m_pPointer;
  if ( m_pPointer )
    LODWORD(m_pPointer[13].m_pSimObject) = -1;
  v3 = this->m_pAIScriptInterfaceComponent.m_pPointer;
  if ( v3 )
  {
    v3[1].m_TypeUID = 0;
    LODWORD(v3[7].m_SafePointerList.mNode.mPrev) = 0;
    BYTE1(this->m_pAIScriptInterfaceComponent.m_pPointer[32].m_BoundComponentHandles.mNode.mPrev) &= ~0x80u;
  }
  v4 = (UFG::TSActorComponent *)this->m_pActorComponent.m_pPointer;
  if ( v4
    && UFG::TSActorComponent::GetActor(v4)
    && ((__int64)UFG::TSActorComponent::GetActor((UFG::TSActorComponent *)this->m_pActorComponent.m_pPointer)[1].vfptr & 4) != 0 )
  {
    Actor = UFG::TSActorComponent::GetActor((UFG::TSActorComponent *)this->m_pActorComponent.m_pPointer);
    Actor->i_actor_flags &= ~4u;
  }
  mPrev = this->IFinishUpdate::UFG::qNode<IFinishUpdate,IFinishUpdate>::mPrev;
  mNext = this->IFinishUpdate::UFG::qNode<IFinishUpdate,IFinishUpdate>::mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->IFinishUpdate::UFG::qNode<IFinishUpdate,IFinishUpdate>::mPrev = &this->UFG::qNode<IFinishUpdate,IFinishUpdate>;
  this->IFinishUpdate::UFG::qNode<IFinishUpdate,IFinishUpdate>::mNext = &this->UFG::qNode<IFinishUpdate,IFinishUpdate>;
}

// File Line: 548
// RVA: 0x332AA0
void __fastcall WanderTask::WanderTask(WanderTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pAIEntityComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax

  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<WanderTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&WanderTask::`vftable;
  p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.mPrev = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.m_pPointer = 0i64;
  this->m_pAINavComponent.mPrev = &this->m_pAINavComponent;
  this->m_pAINavComponent.mNext = &this->m_pAINavComponent;
  this->m_pAINavComponent.m_pPointer = 0i64;
  this->m_pActionContext = 0i64;
  if ( this->m_pAIEntityComponent.m_pPointer )
  {
    mPrev = p_m_pAIEntityComponent->mPrev;
    mNext = p_m_pAIEntityComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
    p_m_pAIEntityComponent->mNext = p_m_pAIEntityComponent;
  }
  p_m_pAIEntityComponent->m_pPointer = 0i64;
  *(_QWORD *)&this->m_iGoalIdCounter = 0i64;
  this->m_maxWaitOnStuck = UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed) + 2.0;
}

// File Line: 559
// RVA: 0x33B980
void __fastcall WanderTask::~WanderTask(WanderTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::NavComponent> *p_m_pAINavComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pAIEntityComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<ITask,ITask> *v12; // rcx
  UFG::qNode<ITask,ITask> *v13; // rax

  this->vfptr = (ITaskVtbl *)&WanderTask::`vftable;
  p_m_pAINavComponent = &this->m_pAINavComponent;
  if ( this->m_pAINavComponent.m_pPointer )
  {
    mPrev = p_m_pAINavComponent->mPrev;
    mNext = p_m_pAINavComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pAINavComponent->mPrev = p_m_pAINavComponent;
    p_m_pAINavComponent->mNext = p_m_pAINavComponent;
  }
  p_m_pAINavComponent->m_pPointer = 0i64;
  v5 = p_m_pAINavComponent->mPrev;
  v6 = p_m_pAINavComponent->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_m_pAINavComponent->mPrev = p_m_pAINavComponent;
  p_m_pAINavComponent->mNext = p_m_pAINavComponent;
  p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
  if ( this->m_pAIEntityComponent.m_pPointer )
  {
    v8 = p_m_pAIEntityComponent->mPrev;
    v9 = this->m_pAIEntityComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
    this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
  }
  this->m_pAIEntityComponent.m_pPointer = 0i64;
  v10 = p_m_pAIEntityComponent->mPrev;
  v11 = this->m_pAIEntityComponent.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
  this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v12 = this->mPrev;
  v13 = this->mNext;
  v12->mNext = v13;
  v13->mPrev = v12;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 565
// RVA: 0x394840
void __fastcall WanderTask::UpdateCrosswalkUsable(WanderTask *this)
{
  UFG::SimComponent *m_pPointer; // rax
  signed __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  unsigned int v5; // edx
  bool v6; // zf

  m_pPointer = this->m_pAIEntityComponent.m_pPointer;
  if ( HIBYTE(m_pPointer[20].m_BoundComponentHandles.mNode.mPrev) && LocalPlayer )
  {
    m_Flags = LocalPlayer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = LocalPlayer->m_Components.p[44].m_pComponent;
    }
    else
    {
      if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 )
      {
        v5 = UFG::CharacterOccupantComponent::_TypeUID;
      }
      else
      {
        v6 = (m_Flags & 0x1000) == 0;
        v5 = UFG::CharacterOccupantComponent::_TypeUID;
        if ( v6 )
        {
          m_pComponent = UFG::SimObject::GetComponentOfType(LocalPlayer, UFG::CharacterOccupantComponent::_TypeUID);
          goto LABEL_11;
        }
      }
      m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(LocalPlayer, v5);
    }
LABEL_11:
    LOBYTE(this->m_pAIEntityComponent.m_pPointer[12].m_SafePointerList.mNode.mNext) = m_pComponent == 0i64;
    return;
  }
  LOBYTE(m_pPointer[12].m_SafePointerList.mNode.mNext) = 0;
}

// File Line: 581
// RVA: 0x349020
void __fastcall WanderTask::Begin(WanderTask *this, ActionContext *action_context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::SimComponent *m_pComponent; // rbx
  UFG::SimComponent *v5; // r8
  __int16 m_Flags; // dx
  UFG::ActiveAIEntityComponent *ComponentOfTypeHK; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pAIEntityComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::SimObjectGame *v12; // rcx
  __int16 v13; // dx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::NavComponent> *p_m_pAINavComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rax

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
      v5 = ComponentOfTypeHK;
    }
    else
    {
      v5 = 0i64;
    }
    p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
    if ( this->m_pAIEntityComponent.m_pPointer )
    {
      mPrev = p_m_pAIEntityComponent->mPrev;
      mNext = this->m_pAIEntityComponent.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
      this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
    }
    this->m_pAIEntityComponent.m_pPointer = v5;
    if ( v5 )
    {
      v11 = v5->m_SafePointerList.mNode.mPrev;
      v11->mNext = p_m_pAIEntityComponent;
      p_m_pAIEntityComponent->mPrev = v11;
      this->m_pAIEntityComponent.mNext = &v5->m_SafePointerList.mNode;
      v5->m_SafePointerList.mNode.mPrev = p_m_pAIEntityComponent;
    }
    v12 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
    if ( v12 )
    {
      v13 = v12->m_Flags;
      if ( (v13 & 0x4000) != 0 )
      {
        m_pComponent = v12->m_Components.p[36].m_pComponent;
      }
      else
      {
        if ( v13 < 0 || (v13 & 0x2000) != 0 || (v13 & 0x1000) != 0 )
          ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::NavComponent::_TypeUID);
        else
          ComponentOfType = UFG::SimObject::GetComponentOfType(v12, UFG::NavComponent::_TypeUID);
        m_pComponent = ComponentOfType;
      }
    }
    p_m_pAINavComponent = &this->m_pAINavComponent;
    if ( this->m_pAINavComponent.m_pPointer )
    {
      v16 = p_m_pAINavComponent->mPrev;
      v17 = this->m_pAINavComponent.mNext;
      v16->mNext = v17;
      v17->mPrev = v16;
      p_m_pAINavComponent->mPrev = p_m_pAINavComponent;
      this->m_pAINavComponent.mNext = &this->m_pAINavComponent;
    }
    this->m_pAINavComponent.m_pPointer = m_pComponent;
    if ( m_pComponent )
    {
      v18 = m_pComponent->m_SafePointerList.mNode.mPrev;
      v18->mNext = p_m_pAINavComponent;
      p_m_pAINavComponent->mPrev = v18;
      this->m_pAINavComponent.mNext = &m_pComponent->m_SafePointerList.mNode;
      m_pComponent->m_SafePointerList.mNode.mPrev = p_m_pAINavComponent;
    }
    if ( this->m_pAIEntityComponent.m_pPointer )
    {
      if ( this->m_pAINavComponent.m_pPointer )
      {
        WanderTask::UpdateCrosswalkUsable(this);
        WanderTask::ReCalculatePath(this, 0);
        BYTE6(this->m_pAIEntityComponent.m_pPointer[20].m_BoundComponentHandles.mNode.mPrev) = 0;
      }
    }
  }
}

// File Line: 613
// RVA: 0x393E10
char __fastcall WanderTask::Update(WanderTask *this, float timestep)
{
  unsigned int v3; // ecx
  unsigned int v4; // eax
  unsigned int v5; // ecx
  UFG::SimComponent *m_pPointer; // rax
  bool v7; // di

  if ( UFG::Metrics::msFrameCount == last_frame )
  {
    v3 = call_count;
  }
  else
  {
    v3 = 0;
    last_frame = UFG::Metrics::msFrameCount;
  }
  v4 = max_call_count;
  v5 = v3 + 1;
  call_count = v5;
  if ( v5 > max_call_count )
    v4 = v5;
  max_call_count = v4;
  m_pPointer = this->m_pAIEntityComponent.m_pPointer;
  if ( m_pPointer )
  {
    if ( BYTE6(m_pPointer[20].m_BoundComponentHandles.mNode.mPrev) )
    {
      WanderTask::UpdateCrosswalkUsable(this);
      WanderTask::ReCalculatePath(this, 0);
      BYTE6(this->m_pAIEntityComponent.m_pPointer[20].m_BoundComponentHandles.mNode.mPrev) = 0;
    }
    WanderTask::UpdateCrosswalkUsable(this);
    v7 = LOBYTE(this->m_pAIEntityComponent.m_pPointer[10].m_SafePointerList.mNode.mNext)
      && !UFG::NavComponent::HasDestination((UFG::NavComponent *)this->m_pAINavComponent.m_pPointer);
    if ( UFG::NavComponent::IsDestinationUnreachable((UFG::NavComponent *)this->m_pAINavComponent.m_pPointer) )
      this->m_replanTimerOnStuck = timestep + this->m_replanTimerOnStuck;
    else
      this->m_replanTimerOnStuck = 0.0;
    if ( !v7 && this->m_maxWaitOnStuck >= this->m_replanTimerOnStuck )
    {
      WanderTask::UpdatePath(this);
      return 1;
    }
    WanderTask::ReCalculatePath(this, this->m_maxWaitOnStuck < this->m_replanTimerOnStuck);
  }
  return 1;
}

// File Line: 680
// RVA: 0x397790
char __fastcall WanderTask::UpdatePath(WanderTask *this)
{
  unsigned __int16 *p_m_Flags; // rsi
  __int64 v3; // rdx
  __int64 v4; // rcx
  __int64 v5; // rax
  __int64 v6; // rax
  __int64 v7; // rax
  __int64 v8; // rcx
  int v9; // eax
  unsigned int v10; // r15d
  int v11; // ebx
  unsigned __int16 v12; // di
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v14; // rax
  UFG::qResourceInventory *v15; // rax
  UFG::qResourceWarehouse *v16; // rax
  _QWORD *v17; // rax
  char *v18; // rax
  unsigned int v19; // r15d
  unsigned int v20; // ebx
  __int16 v21; // di
  UFG::qResourceInventory *v22; // rax
  UFG::qResourceWarehouse *v23; // rax
  UFG::qResourceInventory *v24; // rax
  UFG::qResourceWarehouse *v25; // rax
  unsigned int v26; // edx
  __int64 v27; // rax
  __int64 v28; // rcx
  __int64 v29; // rax
  unsigned int v30; // r15d
  unsigned int v31; // ebx
  __int16 v32; // di
  UFG::qResourceInventory *v33; // rax
  UFG::qResourceWarehouse *v34; // rax
  UFG::qResourceInventory *v35; // rax
  UFG::qResourceWarehouse *v36; // rax
  UFG::SimComponent *m_pPointer; // rax
  UFG::TransformNodeComponent *v38; // rbx
  bool v39; // r8
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *vfptr; // rax
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::qResourceInventory *v43; // rax
  UFG::qResourceWarehouse *v44; // rax
  UFG::qResourceInventory *v45; // rax
  UFG::qResourceWarehouse *v46; // rax
  UFG::SimComponent *v47; // rax
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *v48; // rdi
  UFG::TransformNodeComponent *v49; // rbx
  float v50; // xmm1_4
  float v51; // xmm2_4
  unsigned __int8 v52; // r9
  UFG::qVector3 destPos; // [rsp+30h] [rbp-69h] BYREF
  UFG::qVector3 current_position; // [rsp+40h] [rbp-59h] BYREF
  UFG::qResourceHandle v56; // [rsp+50h] [rbp-49h] BYREF
  int v57; // [rsp+70h] [rbp-29h]
  unsigned int objUID; // [rsp+74h] [rbp-25h]
  __int64 v59; // [rsp+78h] [rbp-21h]
  UFG::qResourceHandle v60; // [rsp+80h] [rbp-19h] BYREF
  int v61; // [rsp+A0h] [rbp+7h]
  int v62; // [rsp+A4h] [rbp+Bh]
  __int64 v63; // [rsp+A8h] [rbp+Fh]
  __int64 v64; // [rsp+B0h] [rbp+17h]
  float speed; // [rsp+100h] [rbp+67h] BYREF
  float elapsedTime; // [rsp+108h] [rbp+6Fh] BYREF

  v64 = -2i64;
  p_m_Flags = &this->m_pAIEntityComponent.m_pPointer[8].m_Flags;
  *((_DWORD *)p_m_Flags + 80) = UFG::Metrics::msFrameCount;
  v3 = *((_QWORD *)p_m_Flags + 5);
  if ( v3 )
  {
    v4 = *(_QWORD *)v3 + v3;
    if ( !*(_QWORD *)v3 )
      v4 = 0i64;
    v5 = *(_QWORD *)(v4 + 40);
    if ( !v5
      || !*(_WORD *)(v5 + 34)
      || ((v6 = *(_QWORD *)(v3 + 8)) == 0 ? (v7 = 0i64) : (v7 = v3 + v6 + 8),
          (v8 = *(_QWORD *)(v7 + 40)) == 0
       || !*(_WORD *)(v8 + 34)
       || (v9 = *(_DWORD *)(v3 + 24), (v9 & 2) == 0)
       || (v9 & 0x80u) != 0) )
    {
      UFG::qResourceHandle::qResourceHandle(&v60);
      v61 = 0xFFFF;
      v62 = -1;
      v63 = 0i64;
      v60.mNameUID = -1;
      v10 = *((_DWORD *)p_m_Flags + 18);
      v11 = *((_DWORD *)p_m_Flags + 21);
      v12 = p_m_Flags[40];
      v63 = 0i64;
      Inventory = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result;
      if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result )
      {
        v14 = UFG::qResourceWarehouse::Instance();
        Inventory = UFG::qResourceWarehouse::GetInventory(v14, 0x43E99F7Eu);
        `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result = Inventory;
      }
      UFG::qResourceHandle::Close(&v60, Inventory);
      LOWORD(v61) = v12;
      v62 = v11;
      v15 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result;
      if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result )
      {
        v16 = UFG::qResourceWarehouse::Instance();
        v15 = UFG::qResourceWarehouse::GetInventory(v16, 0x43E99F7Eu);
        `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result = v15;
      }
      UFG::qResourceHandle::Init(&v60, 0x43E99F7Eu, v10, v15);
      if ( !v63 || *(_WORD *)(v63 + 34) == 0 )
      {
        UFG::qResourceHandle::qResourceHandle(&v56);
        v57 = 0xFFFF;
        objUID = -1;
        v59 = 0i64;
        v56.mNameUID = -1;
        v17 = (_QWORD *)*((_QWORD *)p_m_Flags + 5);
        if ( *v17 )
          v18 = (char *)v17 + *v17;
        else
          v18 = 0i64;
        v19 = *((_DWORD *)v18 + 6);
        v20 = *((_DWORD *)v18 + 9);
        v21 = *((_WORD *)v18 + 16);
        v59 = 0i64;
        v22 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result;
        if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result )
        {
          v23 = UFG::qResourceWarehouse::Instance();
          v22 = UFG::qResourceWarehouse::GetInventory(v23, 0x43E99F7Eu);
          `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result = v22;
        }
        UFG::qResourceHandle::Close(&v56, v22);
        LOWORD(v57) = v21;
        objUID = v20;
        v24 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result;
        if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result )
        {
          v25 = UFG::qResourceWarehouse::Instance();
          v24 = UFG::qResourceWarehouse::GetInventory(v25, 0x43E99F7Eu);
          `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result = v24;
        }
        UFG::qResourceHandle::Init(&v56, 0x43E99F7Eu, v19, v24);
        v26 = objUID;
        if ( v62 == objUID )
        {
          v27 = *((_QWORD *)p_m_Flags + 5);
          v28 = *(_QWORD *)(v27 + 8);
          if ( v28 )
            v29 = v28 + v27 + 8;
          else
            v29 = 0i64;
          v30 = *(_DWORD *)(v29 + 24);
          v31 = *(_DWORD *)(v29 + 36);
          v32 = *(_WORD *)(v29 + 32);
          v59 = 0i64;
          v33 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result;
          if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result )
          {
            v34 = UFG::qResourceWarehouse::Instance();
            v33 = UFG::qResourceWarehouse::GetInventory(v34, 0x43E99F7Eu);
            `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result = v33;
          }
          UFG::qResourceHandle::Close(&v56, v33);
          LOWORD(v57) = v32;
          objUID = v31;
          v35 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result;
          if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result )
          {
            v36 = UFG::qResourceWarehouse::Instance();
            v35 = UFG::qResourceWarehouse::GetInventory(v36, 0x43E99F7Eu);
            `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result = v35;
          }
          UFG::qResourceHandle::Init(&v56, 0x43E99F7Eu, v30, v35);
          v26 = objUID;
        }
        if ( v59 && *(_WORD *)(v59 + 34) != 0 )
        {
          UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::_Set(
            (UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *)p_m_Flags + 1,
            v26,
            v56.mNameUID,
            (unsigned __int16)v57);
          m_pPointer = this->m_pAIEntityComponent.m_pPointer;
          v38 = *(UFG::TransformNodeComponent **)&m_pPointer[1].m_TypeUID;
          destPos = UFG::qVector3::msZero;
          v39 = 0;
          if ( m_pPointer )
          {
            vfptr = m_pPointer[15].vfptr;
            if ( vfptr )
              v39 = vfptr[28].__vecDelDtor && LODWORD(vfptr[15].__vecDelDtor);
          }
          UFG::AISidewalkGraph::GetDestinationPointFromNode(
            (UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *)p_m_Flags + 1,
            &destPos,
            v39);
          current_position = UFG::qVector3::msZero;
          if ( v38 )
          {
            UFG::TransformNodeComponent::UpdateWorldTransform(v38);
            y = v38->mWorldTransform.v3.y;
            z = v38->mWorldTransform.v3.z;
            current_position.x = v38->mWorldTransform.v3.x;
            current_position.y = y;
            current_position.z = z;
          }
          UFG::SidewalkWanderData::SetDestinationPos((UFG::SidewalkWanderData *)p_m_Flags, &destPos, &current_position);
        }
        else
        {
          UFG::SidewalkWanderData::ClearDestination((UFG::SidewalkWanderData *)p_m_Flags);
        }
        v43 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result;
        if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result )
        {
          v44 = UFG::qResourceWarehouse::Instance();
          v43 = UFG::qResourceWarehouse::GetInventory(v44, 0x43E99F7Eu);
          `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result = v43;
        }
        UFG::qResourceHandle::Close(&v56, v43);
        UFG::qResourceHandle::~qResourceHandle(&v56);
      }
      v45 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result;
      if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result )
      {
        v46 = UFG::qResourceWarehouse::Instance();
        v45 = UFG::qResourceWarehouse::GetInventory(v46, 0x43E99F7Eu);
        `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result = v45;
      }
      UFG::qResourceHandle::Close(&v60, v45);
      UFG::qResourceHandle::~qResourceHandle(&v60);
    }
  }
  if ( *((_BYTE *)p_m_Flags + 112) != 1 || !*((_QWORD *)p_m_Flags + 5) )
  {
    v47 = this->m_pAIEntityComponent.m_pPointer;
    v48 = (UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *)&v47[8].m_Flags;
    v49 = *(UFG::TransformNodeComponent **)&v47[1].m_TypeUID;
    UFG::TransformNodeComponent::UpdateWorldTransform(v49);
    v50 = v49->mWorldTransform.v3.y;
    v51 = v49->mWorldTransform.v3.z;
    destPos.x = v49->mWorldTransform.v3.x;
    destPos.y = v50;
    destPos.z = v51;
    v52 = -5;
    if ( LOBYTE(v48[5].mPrev) )
      v52 = -1;
    UFG::AISidewalkGraph::FindClosestSidewalkConnection(&destPos, 30.0, v48, v52);
    UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::SetToNull(v48 + 1);
    if ( !v48->mPtr || !WanderTask::CalculateDestination(this, 0) )
      return 0;
  }
  destPos = *(UFG::qVector3 *)((_BYTE *)p_m_Flags + 8);
  speed = FLOAT_1_5;
  if ( *((_BYTE *)p_m_Flags + 257) )
    WanderTask::HandleCrossWalk(this, (UFG::SidewalkWanderData *)p_m_Flags, &destPos, &speed);
  if ( UFG::NavComponent::IsAtDestination((UFG::NavComponent *)this->m_pAINavComponent.m_pPointer) )
  {
    WanderTask::CalculateDestination(this, 0);
  }
  else
  {
    UFG::NavComponent::PreserveDestination((UFG::NavComponent *)this->m_pAINavComponent.m_pPointer);
    speed = NAN;
    elapsedTime = FLOAT_N1_0;
    if ( UFG::NavComponent::GetCurrGoalPointInfo(
           (UFG::NavComponent *)this->m_pAINavComponent.m_pPointer,
           &current_position,
           &destPos,
           &elapsedTime,
           (int *)&speed)
      && LODWORD(speed) == *((_DWORD *)p_m_Flags + 57) )
    {
      UFG::SidewalkWanderData::MakeLookAheadCurrent((UFG::SidewalkWanderData *)p_m_Flags);
    }
    if ( !*((_BYTE *)p_m_Flags + 232) )
      WanderTask::CalculateLookAheadDestination(this);
  }
  return 1;
}

// File Line: 796
// RVA: 0x364BB0
void __fastcall WanderTask::HandleCrossWalk(
        WanderTask *this,
        UFG::SidewalkWanderData *wanderData,
        UFG::qVector3 *pos,
        float *speed)
{
  UFG::SimComponent *m_pPointer; // rax
  float x; // xmm0_4
  float y; // xmm3_4
  float *v10; // rbx
  float z; // xmm4_4
  __m128 y_low; // xmm2
  UFG::CrosswalkLanes *p_mCrosswalkLanes; // rcx
  float v14; // xmm1_4

  m_pPointer = this->m_pAIEntityComponent.m_pPointer;
  x = UFG::qVector3::msZero.x;
  y = UFG::qVector3::msZero.y;
  v10 = *(float **)&m_pPointer[1].m_TypeUID;
  z = UFG::qVector3::msZero.z;
  if ( v10 )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(*(UFG::TransformNodeComponent **)&m_pPointer[1].m_TypeUID);
    x = v10[44];
    y = v10[45];
    z = v10[46];
  }
  y_low = (__m128)LODWORD(pos->y);
  p_mCrosswalkLanes = &wanderData->mCrosswalkLanes;
  y_low.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] - y) * (float)(y_low.m128_f32[0] - y))
                            + (float)((float)(pos->x - x) * (float)(pos->x - x)))
                    + (float)((float)(pos->z - z) * (float)(pos->z - z));
  v14 = _mm_sqrt_ps(y_low).m128_f32[0] / *speed;
  if ( wanderData->mWaitingToCross )
  {
    if ( UFG::AISidewalkGraph::IsCrosswalkCrossable(p_mCrosswalkLanes, v14) )
      wanderData->mWaitingToCross = 0;
    else
      *speed = 0.0;
  }
  else if ( UFG::AISidewalkGraph::IsCrosswalkCrossable(p_mCrosswalkLanes, 2.0) )
  {
    *speed = 1.5;
  }
  else
  {
    *speed = 3.95;
  }
}

// File Line: 846
// RVA: 0x37F3B0
void __fastcall WanderTask::ReCalculatePath(WanderTask *this, bool useInverseDirection)
{
  UFG::SimComponent *m_pPointer; // rax
  UFG::SidewalkWanderData *p_m_Flags; // rdi
  UFG::TransformNodeComponent *v6; // rbx
  float y; // xmm1_4
  float z; // xmm2_4
  unsigned __int8 v9; // r9
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v11; // rax
  UFG::qVector3 pos; // [rsp+28h] [rbp-50h] BYREF
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> v13; // [rsp+38h] [rbp-40h] BYREF

  this->m_replanTimerOnStuck = 0.0;
  this->m_maxWaitOnStuck = UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed) + 2.0;
  m_pPointer = this->m_pAIEntityComponent.m_pPointer;
  p_m_Flags = (UFG::SidewalkWanderData *)&m_pPointer[8].m_Flags;
  v6 = *(UFG::TransformNodeComponent **)&m_pPointer[1].m_TypeUID;
  UFG::TransformNodeComponent::UpdateWorldTransform(v6);
  y = v6->mWorldTransform.v3.y;
  z = v6->mWorldTransform.v3.z;
  pos.x = v6->mWorldTransform.v3.x;
  pos.y = y;
  pos.z = z;
  UFG::qResourceHandle::qResourceHandle(&v13);
  *(_DWORD *)&v13.mIndex = 0x1FFFF;
  v13.mObjUID = -1;
  v13.mPtr = 0i64;
  v13.mNameUID = -1;
  v9 = -5;
  if ( p_m_Flags->mAllowedToUseCrosswalks )
    v9 = -1;
  UFG::AISidewalkGraph::FindClosestSidewalkConnection(&pos, 30.0, &v13, v9);
  UFG::SidewalkWanderData::ClearData(p_m_Flags);
  if ( v13.mPtr )
  {
    UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::_Set(
      (UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *)p_m_Flags,
      v13.mObjUID,
      v13.mNameUID,
      v13.mIndex);
    UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::SetToNull(&p_m_Flags->mGoals[0].mpDestinationNode);
    WanderTask::CalculateDestination(this, useInverseDirection);
  }
  Inventory = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result;
  if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result )
  {
    v11 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v11, 0x43E99F7Eu);
    `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Close(&v13, Inventory);
  UFG::qResourceHandle::~qResourceHandle(&v13);
}

// File Line: 888
// RVA: 0x34A770
char __fastcall WanderTask::CalculateDestination(WanderTask *this, bool useInverseDirection)
{
  UFG::SimComponent *m_pPointer; // rsi
  UFG::SidewalkWanderData *sidewalkWanderData; // rbx
  __int64 v7; // rsi
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm3_4
  UFG::AIEntityComponent *pAIEntityComponent; // r14
  bool isGroupLeader; // bp
  UFG::GroupComponent *v13; // rax
  unsigned int mFlags; // ecx
  UFG::SimObjectGame *v15; // rcx
  __int16 m_Flags; // dx
  UFG::CharacterPhysicsComponent *m_pComponent; // rax
  unsigned int TerrainTypeHash; // eax
  __m128 x_low; // xmm3
  __m128 y_low; // xmm2
  UFG::NavComponent *v21; // rcx
  int mGoalId; // eax
  __m128 z_low; // xmm0
  UFG::qVector3 pCurrentFacing; // [rsp+40h] [rbp-78h] BYREF
  UFG::qVector3 pDestinationPoint; // [rsp+50h] [rbp-68h] BYREF
  UFG::HavokNavPosition npDestination; // [rsp+60h] [rbp-58h] BYREF

  m_pPointer = this->m_pAIEntityComponent.m_pPointer;
  sidewalkWanderData = (UFG::SidewalkWanderData *)&m_pPointer[8].m_Flags;
  if ( !m_pPointer[9].m_SafePointerList.mNode.mPrev )
    return 0;
  v7 = *(_QWORD *)&m_pPointer[1].m_TypeUID;
  pDestinationPoint = UFG::qVector3::msZero;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v7);
  v8 = *(float *)(v7 + 128);
  v9 = *(float *)(v7 + 132);
  v10 = *(float *)(v7 + 136);
  pCurrentFacing.x = v8;
  pCurrentFacing.y = v9;
  pCurrentFacing.z = v10;
  if ( useInverseDirection )
  {
    pCurrentFacing.x = v8 * -1.0;
    pCurrentFacing.y = v9 * -1.0;
    pCurrentFacing.z = v10 * -1.0;
  }
  pAIEntityComponent = (UFG::AIEntityComponent *)this->m_pAIEntityComponent.m_pPointer;
  isGroupLeader = 0;
  if ( pAIEntityComponent )
  {
    v13 = pAIEntityComponent->m_pGroupComponent.m_pPointer;
    if ( v13 )
      isGroupLeader = v13->mGroupLeader.mFormationProfile && v13->mGroupLeader.mFollowers.size;
  }
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v7);
  if ( UFG::AISidewalkGraph::CalculateDestinationPoint(
         (UFG::SidewalkCommonHandle<UFG::AISidewalkEdge_Game> *)sidewalkWanderData,
         &sidewalkWanderData->mGoals[0].mpDestinationNode,
         &pDestinationPoint,
         (UFG::qVector3 *)(v7 + 176),
         &pCurrentFacing,
         isGroupLeader,
         pAIEntityComponent,
         sidewalkWanderData) )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v7);
    UFG::SidewalkWanderData::SetDestinationPos(sidewalkWanderData, &pDestinationPoint, (UFG::qVector3 *)(v7 + 176));
    mFlags = sidewalkWanderData->mGoals[0].mpSidewalkEdge.mPtr->mFlags;
    sidewalkWanderData->mWaitingToCross = 1;
    sidewalkWanderData->mAtCrossWalk = (mFlags & 4) != 0;
    sidewalkWanderData->mGoals[0].mGoalId = ++this->m_iGoalIdCounter;
    if ( sidewalkWanderData->mAtCrossWalk )
    {
      UFG::AISidewalkGraph::CalculateCrosswalkLanes(
        (UFG::SidewalkCommonHandle<UFG::AISidewalkEdge_Game> *)sidewalkWanderData,
        &sidewalkWanderData->mCrosswalkLanes);
      v15 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
      if ( v15 )
      {
        m_Flags = v15->m_Flags;
        if ( (m_Flags & 0x4000) != 0 )
        {
          m_pComponent = (UFG::CharacterPhysicsComponent *)v15->m_Components.p[27].m_pComponent;
        }
        else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        {
          m_pComponent = (UFG::CharacterPhysicsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             v15,
                                                             UFG::CharacterPhysicsComponent::_TypeUID);
        }
        else
        {
          m_pComponent = (UFG::CharacterPhysicsComponent *)UFG::SimObject::GetComponentOfType(
                                                             v15,
                                                             UFG::CharacterPhysicsComponent::_TypeUID);
        }
        if ( m_pComponent )
        {
          TerrainTypeHash = UFG::GetTerrainTypeHash(m_pComponent);
          if ( UFG::GetTerrainTypeEnum(TerrainTypeHash) == eTerrainType_Road )
            sidewalkWanderData->mWaitingToCross = 0;
        }
      }
    }
    x_low = (__m128)LODWORD(sidewalkWanderData->mGoals[0].mPosition.x);
    y_low = (__m128)LODWORD(sidewalkWanderData->mGoals[0].mPosition.y);
    v21 = (UFG::NavComponent *)this->m_pAINavComponent.m_pPointer;
    npDestination.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
    mGoalId = sidewalkWanderData->mGoals[0].mGoalId;
    z_low = (__m128)LODWORD(sidewalkWanderData->mGoals[0].mPosition.z);
    LODWORD(npDestination.m_vPosition.x) = x_low.m128_i32[0];
    npDestination.m_bValid = 0;
    LODWORD(npDestination.m_vPosition.y) = y_low.m128_i32[0];
    LODWORD(npDestination.m_vPosition.z) = z_low.m128_i32[0];
    *(_QWORD *)&npDestination.m_packedKey = -1i64;
    npDestination.m_hkvMeshPosition.m_quad = _mm_unpacklo_ps(
                                               _mm_unpacklo_ps(x_low, z_low),
                                               _mm_unpacklo_ps(y_low, (__m128)(unsigned int)FLOAT_1_0));
    UFG::NavComponent::AddGoalPointUidHACK(v21, &npDestination, 0, 1.5, mGoalId, 512, 1.0);
    return 1;
  }
  else
  {
    UFG::SidewalkWanderData::ClearDestination(sidewalkWanderData);
    UFG::SidewalkWanderData::ClearLookAheadDestination(sidewalkWanderData);
    return 0;
  }
}

// File Line: 957
// RVA: 0x34B810
char __fastcall WanderTask::CalculateLookAheadDestination(WanderTask *this)
{
  UFG::SimComponent *m_pPointer; // rax
  char *sidewalkWanderData; // rbx
  float y; // xmm1_4
  float z; // xmm2_4
  _QWORD *v7; // rax
  char *v8; // rax
  unsigned int v9; // r12d
  int v10; // r14d
  __int16 v11; // r15
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v13; // rax
  UFG::qResourceInventory *v14; // rax
  UFG::qResourceWarehouse *v15; // rax
  __int64 v16; // rax
  __int64 v17; // rcx
  __int64 v18; // rax
  unsigned int v19; // r12d
  int v20; // r14d
  __int16 v21; // r15
  UFG::qResourceInventory *v22; // rax
  UFG::qResourceWarehouse *v23; // rax
  UFG::qResourceInventory *v24; // rax
  UFG::qResourceWarehouse *v25; // rax
  float v26; // xmm5_4
  float v27; // xmm5_4
  __m128 v28; // xmm6
  float v29; // xmm3_4
  __m128 v30; // xmm4
  float v31; // xmm2_4
  UFG::SimComponent *v32; // rax
  bool isGroupLeader; // cl
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *vfptr; // rax
  __m128 x_low; // xmm3
  __m128 y_low; // xmm2
  __m128 z_low; // xmm0
  int v38; // eax
  char v39; // bl
  UFG::qResourceInventory *v40; // rax
  UFG::qResourceWarehouse *v41; // rax
  UFG::qVector3 pDestinationPoint; // [rsp+40h] [rbp-98h] BYREF
  UFG::qResourceHandle pCurrentFacing; // [rsp+50h] [rbp-88h] BYREF
  int v44; // [rsp+70h] [rbp-68h]
  int v45; // [rsp+74h] [rbp-64h]
  UFG::HavokNavPosition npDestination; // [rsp+78h] [rbp-60h] BYREF
  __int64 v47; // [rsp+B8h] [rbp-20h]

  v47 = -2i64;
  m_pPointer = this->m_pAIEntityComponent.m_pPointer;
  sidewalkWanderData = (char *)&m_pPointer[8].m_Flags;
  if ( !m_pPointer[9].m_SafePointerList.mNode.mPrev )
    return 0;
  pDestinationPoint = UFG::qVector3::msZero;
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::SetToNull((UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *)&m_pPointer[10].m_TypeUID);
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::SetToNull((UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *)(sidewalkWanderData + 168));
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  *((_DWORD *)sidewalkWanderData + 54) = LODWORD(UFG::qVector3::msZero.x);
  *((float *)sidewalkWanderData + 55) = y;
  *((float *)sidewalkWanderData + 56) = z;
  *((_DWORD *)sidewalkWanderData + 57) = -1;
  sidewalkWanderData[232] = 0;
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::_Set(
    (UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *)(sidewalkWanderData + 120),
    *((_DWORD *)sidewalkWanderData + 9),
    *((_DWORD *)sidewalkWanderData + 6),
    *((unsigned __int16 *)sidewalkWanderData + 16));
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::_Set(
    (UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *)(sidewalkWanderData + 168),
    *((_DWORD *)sidewalkWanderData + 21),
    *((_DWORD *)sidewalkWanderData + 18),
    *((unsigned __int16 *)sidewalkWanderData + 40));
  UFG::qResourceHandle::qResourceHandle(&pCurrentFacing);
  v44 = 0xFFFF;
  v45 = -1;
  npDestination.vfptr = 0i64;
  pCurrentFacing.mNameUID = -1;
  v7 = (_QWORD *)*((_QWORD *)sidewalkWanderData + 5);
  if ( *v7 )
    v8 = (char *)v7 + *v7;
  else
    v8 = 0i64;
  v9 = *((_DWORD *)v8 + 6);
  v10 = *((_DWORD *)v8 + 9);
  v11 = *((_WORD *)v8 + 16);
  npDestination.vfptr = 0i64;
  Inventory = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result;
  if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result )
  {
    v13 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v13, 0x43E99F7Eu);
    `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Close(&pCurrentFacing, Inventory);
  LOWORD(v44) = v11;
  v45 = v10;
  v14 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result;
  if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result )
  {
    v15 = UFG::qResourceWarehouse::Instance();
    v14 = UFG::qResourceWarehouse::GetInventory(v15, 0x43E99F7Eu);
    `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result = v14;
  }
  UFG::qResourceHandle::Init(&pCurrentFacing, 0x43E99F7Eu, v9, v14);
  if ( *((_DWORD *)sidewalkWanderData + 21) == v45 )
  {
    v16 = *((_QWORD *)sidewalkWanderData + 5);
    v17 = *(_QWORD *)(v16 + 8);
    if ( v17 )
      v18 = v17 + v16 + 8;
    else
      v18 = 0i64;
    v19 = *(_DWORD *)(v18 + 24);
    v20 = *(_DWORD *)(v18 + 36);
    v21 = *(_WORD *)(v18 + 32);
    npDestination.vfptr = 0i64;
    v22 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result;
    if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result )
    {
      v23 = UFG::qResourceWarehouse::Instance();
      v22 = UFG::qResourceWarehouse::GetInventory(v23, 0x43E99F7Eu);
      `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result = v22;
    }
    UFG::qResourceHandle::Close(&pCurrentFacing, v22);
    LOWORD(v44) = v21;
    v45 = v20;
    v24 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result;
    if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result )
    {
      v25 = UFG::qResourceWarehouse::Instance();
      v24 = UFG::qResourceWarehouse::GetInventory(v25, 0x43E99F7Eu);
      `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result = v24;
    }
    UFG::qResourceHandle::Init(&pCurrentFacing, 0x43E99F7Eu, v19, v24);
  }
  if ( !npDestination.vfptr )
    goto LABEL_31;
  v28 = (__m128)*((unsigned int *)sidewalkWanderData + 25);
  v26 = *((float *)sidewalkWanderData + 26);
  pCurrentFacing.mNameUID = *((_DWORD *)sidewalkWanderData + 24);
  pCurrentFacing.mTailPad = v28.m128_i32[0];
  v44 = LODWORD(v26);
  v27 = v26 - *(float *)&npDestination.vfptr->Invalidate;
  v28.m128_f32[0] = v28.m128_f32[0] - *((float *)&npDestination.vfptr->Validate + 1);
  v29 = *(float *)&pCurrentFacing.mNameUID - *(float *)&npDestination.vfptr->Validate;
  v30 = v28;
  v30.m128_f32[0] = (float)((float)(v28.m128_f32[0] * v28.m128_f32[0]) + (float)(v29 * v29)) + (float)(v27 * v27);
  v31 = 0.0;
  if ( v30.m128_f32[0] != 0.0 )
    v31 = 1.0 / _mm_sqrt_ps(v30).m128_f32[0];
  *(float *)&pCurrentFacing.mNext = v29 * v31;
  *((float *)&pCurrentFacing.mNext + 1) = v31 * v28.m128_f32[0];
  *(float *)&pCurrentFacing.mData = v31 * v27;
  v32 = this->m_pAIEntityComponent.m_pPointer;
  isGroupLeader = 0;
  if ( v32 )
  {
    vfptr = v32[15].vfptr;
    if ( vfptr )
      isGroupLeader = vfptr[28].__vecDelDtor && LODWORD(vfptr[15].__vecDelDtor);
  }
  if ( !UFG::AISidewalkGraph::CalculateDestinationPoint(
          (UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *)(sidewalkWanderData + 120),
          (UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *)(sidewalkWanderData + 168),
          &pDestinationPoint,
          (UFG::qVector3 *)&pCurrentFacing.mNameUID,
          (UFG::qVector3 *)&pCurrentFacing.mNext,
          isGroupLeader,
          0i64,
          (UFG::SidewalkWanderData *)sidewalkWanderData) )
  {
    UFG::SidewalkWanderData::ClearLookAheadDestination((UFG::SidewalkWanderData *)sidewalkWanderData);
LABEL_31:
    v39 = 0;
    goto LABEL_32;
  }
  x_low = (__m128)LODWORD(pDestinationPoint.x);
  *((_DWORD *)sidewalkWanderData + 54) = LODWORD(pDestinationPoint.x);
  y_low = (__m128)LODWORD(pDestinationPoint.y);
  *((_DWORD *)sidewalkWanderData + 55) = LODWORD(pDestinationPoint.y);
  z_low = (__m128)LODWORD(pDestinationPoint.z);
  *((_DWORD *)sidewalkWanderData + 56) = LODWORD(pDestinationPoint.z);
  sidewalkWanderData[232] = 1;
  v38 = this->m_iGoalIdCounter + 1;
  this->m_iGoalIdCounter = v38;
  *((_DWORD *)sidewalkWanderData + 57) = v38;
  LODWORD(npDestination.m_vPosition.x) = x_low.m128_i32[0];
  LODWORD(npDestination.m_vPosition.y) = y_low.m128_i32[0];
  LODWORD(npDestination.m_vPosition.z) = z_low.m128_i32[0];
  npDestination.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
  npDestination.m_bValid = 0;
  *(_QWORD *)&npDestination.m_packedKey = -1i64;
  npDestination.m_hkvMeshPosition.m_quad = _mm_unpacklo_ps(
                                             _mm_unpacklo_ps(x_low, z_low),
                                             _mm_unpacklo_ps(y_low, (__m128)(unsigned int)FLOAT_1_0));
  UFG::NavComponent::AddGoalPointUid(
    (UFG::NavComponent *)this->m_pAINavComponent.m_pPointer,
    &npDestination,
    AiGoal_Append,
    1.5,
    v38,
    1.0);
  v39 = 1;
LABEL_32:
  v40 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result;
  if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result )
  {
    v41 = UFG::qResourceWarehouse::Instance();
    v40 = UFG::qResourceWarehouse::GetInventory(v41, 0x43E99F7Eu);
    `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result = v40;
  }
  UFG::qResourceHandle::Close(&pCurrentFacing, v40);
  UFG::qResourceHandle::~qResourceHandle(&pCurrentFacing);
  return v39;
}

// File Line: 1041
// RVA: 0x32E530
void __fastcall FleeTask::FleeTask(FleeTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pAIEntityComponent; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::NavComponent> *p_m_pNavComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax

  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<FleeTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&FleeTask::`vftable;
  p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.mPrev = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.m_pPointer = 0i64;
  p_m_pNavComponent = &this->m_pNavComponent;
  this->m_pNavComponent.mPrev = &this->m_pNavComponent;
  this->m_pNavComponent.mNext = &this->m_pNavComponent;
  this->m_pNavComponent.m_pPointer = 0i64;
  this->m_pActorAudioComponent.mPrev = &this->m_pActorAudioComponent;
  this->m_pActorAudioComponent.mNext = &this->m_pActorAudioComponent;
  this->m_pActorAudioComponent.m_pPointer = 0i64;
  this->m_pFleeToPoint.mPrev = &this->m_pFleeToPoint;
  this->m_pFleeToPoint.mNext = &this->m_pFleeToPoint;
  this->m_pFleeToPoint.m_pPointer = 0i64;
  this->m_NavParams.m_fRadius = 0.0;
  this->m_NavParams.m_flags = 65280;
  this->m_pActionContext = 0i64;
  if ( this->m_pAIEntityComponent.m_pPointer )
  {
    mPrev = p_m_pAIEntityComponent->mPrev;
    mNext = p_m_pAIEntityComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
    p_m_pAIEntityComponent->mNext = p_m_pAIEntityComponent;
  }
  p_m_pAIEntityComponent->m_pPointer = 0i64;
  if ( p_m_pNavComponent->m_pPointer )
  {
    v6 = p_m_pNavComponent->mPrev;
    v7 = p_m_pNavComponent->mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    p_m_pNavComponent->mPrev = p_m_pNavComponent;
    p_m_pNavComponent->mNext = p_m_pNavComponent;
  }
  p_m_pNavComponent->m_pPointer = 0i64;
  this->m_LastTimeInteriorStatusChanged = -99999.0;
  this->m_CurrentlyInInterior = 0;
  this->m_LastTimeFleeDirectionChecked = -99999.0;
}

// File Line: 1055
// RVA: 0x336B20
void __fastcall FleeTask::~FleeTask(FleeTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::AIMarker> *p_m_pFleeToPoint; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActorAudioComponent> *p_m_pActorAudioComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::NavComponent> *p_m_pNavComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pAIEntityComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v21; // rax
  UFG::qNode<ITask,ITask> *v22; // rcx
  UFG::qNode<ITask,ITask> *v23; // rax

  this->vfptr = (ITaskVtbl *)&FleeTask::`vftable;
  p_m_pFleeToPoint = &this->m_pFleeToPoint;
  if ( this->m_pFleeToPoint.m_pPointer )
  {
    mPrev = p_m_pFleeToPoint->mPrev;
    mNext = p_m_pFleeToPoint->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pFleeToPoint->mPrev = p_m_pFleeToPoint;
    p_m_pFleeToPoint->mNext = p_m_pFleeToPoint;
  }
  p_m_pFleeToPoint->m_pPointer = 0i64;
  v5 = p_m_pFleeToPoint->mPrev;
  v6 = p_m_pFleeToPoint->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_m_pFleeToPoint->mPrev = p_m_pFleeToPoint;
  p_m_pFleeToPoint->mNext = p_m_pFleeToPoint;
  p_m_pActorAudioComponent = &this->m_pActorAudioComponent;
  if ( this->m_pActorAudioComponent.m_pPointer )
  {
    v8 = p_m_pActorAudioComponent->mPrev;
    v9 = this->m_pActorAudioComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    p_m_pActorAudioComponent->mPrev = p_m_pActorAudioComponent;
    this->m_pActorAudioComponent.mNext = &this->m_pActorAudioComponent;
  }
  this->m_pActorAudioComponent.m_pPointer = 0i64;
  v10 = p_m_pActorAudioComponent->mPrev;
  v11 = this->m_pActorAudioComponent.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  p_m_pActorAudioComponent->mPrev = p_m_pActorAudioComponent;
  this->m_pActorAudioComponent.mNext = &this->m_pActorAudioComponent;
  p_m_pNavComponent = &this->m_pNavComponent;
  if ( this->m_pNavComponent.m_pPointer )
  {
    v13 = p_m_pNavComponent->mPrev;
    v14 = this->m_pNavComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    p_m_pNavComponent->mPrev = p_m_pNavComponent;
    this->m_pNavComponent.mNext = &this->m_pNavComponent;
  }
  this->m_pNavComponent.m_pPointer = 0i64;
  v15 = p_m_pNavComponent->mPrev;
  v16 = this->m_pNavComponent.mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  p_m_pNavComponent->mPrev = p_m_pNavComponent;
  this->m_pNavComponent.mNext = &this->m_pNavComponent;
  p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
  if ( this->m_pAIEntityComponent.m_pPointer )
  {
    v18 = p_m_pAIEntityComponent->mPrev;
    v19 = this->m_pAIEntityComponent.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
    this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
  }
  this->m_pAIEntityComponent.m_pPointer = 0i64;
  v20 = p_m_pAIEntityComponent->mPrev;
  v21 = this->m_pAIEntityComponent.mNext;
  v20->mNext = v21;
  v21->mPrev = v20;
  p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
  this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v22 = this->mPrev;
  v23 = this->mNext;
  v22->mNext = v23;
  v23->mPrev = v22;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 1074
// RVA: 0x349C30
void __fastcall FleeTask::BeginInteriorFleeing(FleeTask *this)
{
  UFG::SimComponent *m_pPointer; // r15
  UFG::qNode<UFG::AIMarker,UFG::AIMarker> *v3; // rbx
  float v4; // xmm6_4
  UFG::SimComponent *v5; // rsi
  float *mNext; // rdi
  __m128 m_NameUID; // xmm2
  float v8; // xmm1_4
  float v9; // xmm1_4
  UFG::qSafePointer<UFG::SimComponent,UFG::AIMarker> *p_m_pFleeToPoint; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AIMarker> *v14; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax

  m_pPointer = this->m_pNavComponent.m_pPointer;
  if ( m_pPointer )
  {
    v3 = UFG::AIMarker::s_AIFleeToPointList.mNode.mNext - 7;
    v4 = FLOAT_N1_0;
    v5 = 0i64;
    if ( (UFG::qList<UFG::AIMarker,UFG::AIMarker,1,0> *)&UFG::AIMarker::s_AIFleeToPointList.mNode.mNext[-7] == &UFG::AIMarker::s_AIFleeToPointList - 7 )
      goto LABEL_15;
    do
    {
      mNext = (float *)v3[6].mNext;
      if ( mNext )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v3[6].mNext);
        m_NameUID = (__m128)m_pPointer[1].m_NameUID;
        v8 = *(float *)&m_pPointer[1].m_TypeUID - mNext[44];
        m_NameUID.m128_f32[0] = (float)((float)((float)(m_NameUID.m128_f32[0] - mNext[45])
                                              * (float)(m_NameUID.m128_f32[0] - mNext[45]))
                                      + (float)(v8 * v8))
                              + (float)((float)(*(float *)&m_pPointer[1].m_Flags - mNext[46])
                                      * (float)(*(float *)&m_pPointer[1].m_Flags - mNext[46]));
        LODWORD(v9) = _mm_sqrt_ps(m_NameUID).m128_u32[0];
        if ( (!v5 || v9 < v4) && v9 < 1000.0 )
        {
          v5 = (UFG::SimComponent *)v3;
          v4 = v9;
        }
      }
      v3 = v3[7].mNext - 7;
    }
    while ( v3 != (UFG::qNode<UFG::AIMarker,UFG::AIMarker> *)(&UFG::AIMarker::s_AIFleeToPointList - 7) );
    if ( v5 && this->m_pAIEntityComponent.m_pPointer && v5[1].m_pSimObject )
    {
      p_m_pFleeToPoint = &this->m_pFleeToPoint;
      if ( this->m_pFleeToPoint.m_pPointer )
      {
        mPrev = p_m_pFleeToPoint->mPrev;
        v12 = this->m_pFleeToPoint.mNext;
        mPrev->mNext = v12;
        v12->mPrev = mPrev;
        p_m_pFleeToPoint->mPrev = p_m_pFleeToPoint;
        this->m_pFleeToPoint.mNext = &this->m_pFleeToPoint;
      }
      this->m_pFleeToPoint.m_pPointer = v5;
      v13 = v5->m_SafePointerList.mNode.mPrev;
      v13->mNext = p_m_pFleeToPoint;
      p_m_pFleeToPoint->mPrev = v13;
      this->m_pFleeToPoint.mNext = &v5->m_SafePointerList.mNode;
      v5->m_SafePointerList.mNode.mPrev = p_m_pFleeToPoint;
    }
    else
    {
LABEL_15:
      v14 = &this->m_pFleeToPoint;
      if ( this->m_pFleeToPoint.m_pPointer )
      {
        v15 = v14->mPrev;
        v16 = this->m_pFleeToPoint.mNext;
        v15->mNext = v16;
        v16->mPrev = v15;
        v14->mPrev = v14;
        this->m_pFleeToPoint.mNext = &this->m_pFleeToPoint;
      }
      this->m_pFleeToPoint.m_pPointer = 0i64;
    }
  }
  if ( !this->m_pFleeToPoint.m_pPointer )
    FleeTask::BeginExteriorFleeing(this);
}

// File Line: 1123
// RVA: 0x3493D0
void __fastcall FleeTask::BeginExteriorFleeing(FleeTask *this)
{
  UFG::SimObjectGame *m_pPointer; // r8
  UFG::SimComponent *m_pComponent; // rsi
  __int16 m_Flags; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qVector4 *CurrentPosition; // rax
  float y; // xmm1_4
  float z; // xmm2_4
  unsigned int m_NameUID; // xmm1_4
  int v10; // xmm2_4
  ITrack *m_Track; // rcx
  float x; // xmm6_4
  float v13; // xmm7_4
  float v14; // xmm8_4
  __int64 v15; // rsi
  unsigned int v16; // ebx
  unsigned int v17; // edx
  unsigned __int64 v18; // rcx
  unsigned __int64 m_LastMeleeCombatTimestamp; // rcx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  __m128 y_low; // xmm2
  __m128 z_low; // xmm0
  UFG::SimObjectGame *v23; // rcx
  __int16 v24; // dx
  UFG::SimComponent *v25; // rbx
  UFG::SimComponent *v26; // rax
  __int64 v27; // rsi
  __int64 v28; // rsi
  __m128 v29; // xmm2
  __m128 v30; // xmm0
  __int64 v31; // rbx
  __int64 v32; // rbx
  __m128 v33; // xmm3
  __m128 v34; // xmm0
  UFG::SimComponent *v35; // rax
  __int64 v36; // r15
  __int64 v37; // rsi
  UFG::SimComponent *v38; // r14
  __int64 v39; // rax
  __int64 v40; // rbx
  int v41; // xmm6_4
  int v42; // xmm7_4
  int v43; // xmm8_4
  int v44; // xmm9_4
  __int64 v45; // r14
  unsigned int v46; // ebx
  unsigned int v47; // edx
  unsigned __int64 v48; // rcx
  UFG::DaemonManager *v49; // rax
  UFG::qVector4 *v50; // rax
  float v51; // xmm2_4
  float v52; // xmm1_4
  __int64 v53; // rcx
  UFG::HavokNavPosition navPosition; // [rsp+20h] [rbp-B8h] BYREF
  UFG::FleeTraversalImmediateQuery v55; // [rsp+60h] [rbp-78h] BYREF
  UFG::qVector3 v56; // [rsp+F0h] [rbp+18h]
  char v57; // [rsp+100h] [rbp+28h]
  __int128 v58; // [rsp+108h] [rbp+30h]
  __int64 v59; // [rsp+118h] [rbp+40h]
  __int64 v60; // [rsp+128h] [rbp+50h]
  __int64 v61; // [rsp+138h] [rbp+60h]

  v61 = -2i64;
  this->m_FailedQuery = 1;
  v55.vfptr = (UFG::DaemonQueryInputVtbl *)&UFG::FleeTraversalImmediateQuery::`vftable;
  *(_QWORD *)(&navPosition.m_aiMeshUid + 1) = 0i64;
  *(UFG::qVector3 *)&v55.m_mode = UFG::qVector3::msZero;
  *(_QWORD *)&v55.m_daemonType = &UFG::HavokNavPosition::`vftable;
  LOBYTE(v55.mpNavParams) = 0;
  *(_QWORD *)&v55.mEscapeOrigin.m_vPosition.x = -1i64;
  *(__m128 *)&(&v55.mpNavParams)[1] = _mm_unpacklo_ps(
                                        _mm_unpacklo_ps(
                                          (__m128)LODWORD(UFG::qVector3::msZero.x),
                                          (__m128)LODWORD(UFG::qVector3::msZero.z)),
                                        _mm_unpacklo_ps(
                                          (__m128)LODWORD(UFG::qVector3::msZero.y),
                                          (__m128)(unsigned int)FLOAT_1_0));
  *(_DWORD *)&v55.mEscapeOrigin.m_bValid = 0;
  *((float *)&v55.mEscapeOrigin.m_bValid + 1) = FLOAT_N1_0;
  v55.mEscapeOrigin.m_hkvMeshPosition = 0ui64;
  v55.mEscapeOrigin.m_packedKey = -1;
  v55.mEscapeRadius = 0.0;
  *(_QWORD *)&v55.mRoadCost = 3i64;
  *(_QWORD *)(&v55.mEscapeOrigin.m_aiMeshUid + 1) = &UFG::FleeTraversalOutput::`vftable;
  v56 = UFG::qVector3::msZero;
  *(_QWORD *)&v55.mMaxSearchIterations = &UFG::HavokNavPosition::`vftable;
  v57 = 0;
  v59 = -1i64;
  v58 = *(_OWORD *)&(&v55.mpNavParams)[1];
  v60 = 0i64;
  m_pPointer = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[36].m_pComponent;
    }
    else
    {
      if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::NavComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::NavComponent::_TypeUID);
      m_pComponent = ComponentOfTypeHK;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  if ( !((unsigned __int8 (__fastcall *)(UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **))m_pComponent[1].m_SafePointerList.mNode.mNext[2].mPrev)(&m_pComponent[1].m_SafePointerList.mNode.mNext) )
  {
    CurrentPosition = UFG::NavComponent::GetCurrentPosition((UFG::NavComponent *)m_pComponent);
    y = CurrentPosition->y;
    z = CurrentPosition->z;
    this->m_FleeDestination.x = CurrentPosition->x;
    this->m_FleeDestination.z = z;
LABEL_77:
    this->m_FleeDestination.y = y;
    goto LABEL_78;
  }
  m_NameUID = m_pComponent[1].m_NameUID;
  v10 = *(_DWORD *)&m_pComponent[1].m_Flags;
  v55.m_mode = m_pComponent[1].m_TypeUID;
  *((_DWORD *)&v55.m_mode + 1) = m_NameUID;
  LODWORD(v55.m_pOutput) = v10;
  if ( LOBYTE(m_pComponent[1].m_pSimObject) )
  {
    LOBYTE(v55.mpNavParams) = m_pComponent[1].m_pSimObject;
    *(UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)&(&v55.mpNavParams)[1] = m_pComponent[1].m_BoundComponentHandles;
    v55.mEscapeOrigin.m_vPosition.x = *(float *)&m_pComponent[2].vfptr;
    v55.mEscapeOrigin.m_vPosition.y = *((float *)&m_pComponent[2].vfptr + 1);
  }
  else
  {
    LOBYTE(v55.mpNavParams) = 0;
  }
  m_Track = this->m_Track;
  *(float *)&v55.mEscapeOrigin.m_bValid = *(float *)&m_Track[1].mResourceOwner - this->m_FailedRetryCount;
  this->m_NavParams = *(UFG::NavParams *)((char *)&m_pComponent[2].m_BoundComponentHandles.mNode.mNext + 4);
  if ( !LOBYTE(m_Track[1].mMasterRate.expression.mOffset) )
    *((float *)&v55.mEscapeOrigin.m_bValid + 1) = FLOAT_500000_0;
  *(_QWORD *)(&navPosition.m_aiMeshUid + 1) = &this->m_NavParams;
  x = this->m_LastFleeOrigin.x;
  v13 = this->m_LastFleeOrigin.y;
  v14 = this->m_LastFleeOrigin.z;
  v15 = v55.mEscapeOrigin.m_hkvMeshPosition.m_quad.m128_u32[0];
  v16 = v55.mEscapeOrigin.m_hkvMeshPosition.m_quad.m128_i32[0] + 1;
  if ( (unsigned int)(v55.mEscapeOrigin.m_hkvMeshPosition.m_quad.m128_i32[0] + 1) > v55.mEscapeOrigin.m_hkvMeshPosition.m_quad.m128_i32[1] )
  {
    if ( v55.mEscapeOrigin.m_hkvMeshPosition.m_quad.m128_i32[1] )
      v17 = 2 * v55.mEscapeOrigin.m_hkvMeshPosition.m_quad.m128_i32[1];
    else
      v17 = 1;
    for ( ; v17 < v16; v17 *= 2 )
      ;
    if ( v17 - v16 > 0x10000 )
      v17 = v55.mEscapeOrigin.m_hkvMeshPosition.m_quad.m128_i32[0] + 65537;
    UFG::qArray<UFG::FleeTraversalImmediateQuery::ThreatTarget,0>::Reallocate(
      (UFG::qArray<UFG::FleeTraversalImmediateQuery::ThreatTarget,0> *)&v55.mEscapeOrigin.m_hkvMeshPosition,
      v17,
      "qArray.Add");
  }
  v55.mEscapeOrigin.m_hkvMeshPosition.m_quad.m128_i32[0] = v16;
  v18 = v55.mEscapeOrigin.m_hkvMeshPosition.m_quad.m128_u64[1] + 80 * v15;
  *(float *)(v18 + 8) = x;
  *(float *)(v18 + 12) = v13;
  *(float *)(v18 + 16) = v14;
  *(_BYTE *)(v18 + 24) = 0;
  *(_DWORD *)(v18 + 64) = 1120403456;
  m_LastMeleeCombatTimestamp = UFG::LocalPlayerIsInCombatManager::s_pInstance->m_LastMeleeCombatTimestamp;
  if ( m_LastMeleeCombatTimestamp
    && UFG::Metrics::msInstance.mSimTimeMSec - m_LastMeleeCombatTimestamp < UFG::LocalPlayerIsInCombatManager::s_InCombatTimer )
  {
    if ( LocalPlayer )
      m_pTransformNodeComponent = LocalPlayer->m_pTransformNodeComponent;
    else
      m_pTransformNodeComponent = 0i64;
    if ( m_pTransformNodeComponent )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
      y_low = (__m128)LODWORD(m_pTransformNodeComponent->mWorldTransform.v3.y);
      z_low = (__m128)LODWORD(m_pTransformNodeComponent->mWorldTransform.v3.z);
      navPosition.m_vPosition.x = m_pTransformNodeComponent->mWorldTransform.v3.x;
      LODWORD(navPosition.m_vPosition.y) = y_low.m128_i32[0];
      LODWORD(navPosition.m_vPosition.z) = z_low.m128_i32[0];
      navPosition.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
      navPosition.m_bValid = 0;
      *(_QWORD *)&navPosition.m_packedKey = -1i64;
      navPosition.m_hkvMeshPosition.m_quad = _mm_unpacklo_ps(
                                               _mm_unpacklo_ps((__m128)LODWORD(navPosition.m_vPosition.x), z_low),
                                               _mm_unpacklo_ps(y_low, (__m128)(unsigned int)FLOAT_1_0));
      UFG::FleeTraversalImmediateQuery::AddThreat(&v55, &navPosition, 100.0);
    }
  }
  else
  {
    v23 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
    if ( v23 )
    {
      v24 = v23->m_Flags;
      if ( (v24 & 0x4000) != 0 )
      {
        v25 = v23->m_Components.p[20].m_pComponent;
      }
      else if ( v24 >= 0 )
      {
        v26 = (v24 & 0x2000) != 0 || (v24 & 0x1000) != 0
            ? UFG::SimObjectGame::GetComponentOfTypeHK(v23, UFG::TargetingSystemBaseComponent::_TypeUID)
            : UFG::SimObject::GetComponentOfType(v23, UFG::TargetingSystemBaseComponent::_TypeUID);
        v25 = v26;
      }
      else
      {
        v25 = v23->m_Components.p[20].m_pComponent;
      }
      if ( v25 )
      {
        v27 = *(_QWORD *)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v25[1].m_Flags + 37i64)
                        + *(_QWORD *)&v25[1].m_TypeUID
                        + 40);
        if ( v27 )
          v28 = *(_QWORD *)(v27 + 88);
        else
          v28 = 0i64;
        if ( v28 )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v28);
          v29 = (__m128)*(unsigned int *)(v28 + 180);
          v30 = (__m128)*(unsigned int *)(v28 + 184);
          navPosition.m_vPosition.x = *(float *)(v28 + 176);
          LODWORD(navPosition.m_vPosition.y) = v29.m128_i32[0];
          LODWORD(navPosition.m_vPosition.z) = v30.m128_i32[0];
          navPosition.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
          navPosition.m_bValid = 0;
          *(_QWORD *)&navPosition.m_packedKey = -1i64;
          navPosition.m_hkvMeshPosition.m_quad = _mm_unpacklo_ps(
                                                   _mm_unpacklo_ps((__m128)LODWORD(navPosition.m_vPosition.x), v30),
                                                   _mm_unpacklo_ps(v29, (__m128)(unsigned int)FLOAT_1_0));
          UFG::FleeTraversalImmediateQuery::AddThreat(&v55, &navPosition, 100.0);
        }
        v31 = *(_QWORD *)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v25[1].m_Flags + 30i64)
                        + *(_QWORD *)&v25[1].m_TypeUID
                        + 40);
        if ( v31 )
          v32 = *(_QWORD *)(v31 + 88);
        else
          v32 = 0i64;
        if ( v32 )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v32);
          v33 = (__m128)*(unsigned int *)(v32 + 180);
          v34 = (__m128)*(unsigned int *)(v32 + 184);
          navPosition.m_vPosition.x = *(float *)(v32 + 176);
          LODWORD(navPosition.m_vPosition.y) = v33.m128_i32[0];
          LODWORD(navPosition.m_vPosition.z) = v34.m128_i32[0];
          navPosition.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
          navPosition.m_bValid = 0;
          *(_QWORD *)&navPosition.m_packedKey = -1i64;
          navPosition.m_hkvMeshPosition.m_quad = _mm_unpacklo_ps(
                                                   _mm_unpacklo_ps((__m128)LODWORD(navPosition.m_vPosition.x), v34),
                                                   _mm_unpacklo_ps(v33, (__m128)(unsigned int)FLOAT_1_0));
          UFG::FleeTraversalImmediateQuery::AddThreat(&v55, &navPosition, 100.0);
        }
      }
    }
    v35 = this->m_pAIEntityComponent.m_pPointer;
    v36 = *(unsigned int *)&v35[15].m_Flags;
    if ( *(_DWORD *)&v35[15].m_Flags )
    {
      v37 = 0i64;
      do
      {
        v38 = this->m_pAIEntityComponent.m_pPointer;
        v39 = *(__int64 *)((char *)&v38[15].m_BoundComponentHandles.mNode.mNext + v37 * 8);
        if ( v39 )
          v40 = *(_QWORD *)(v39 + 88);
        else
          v40 = 0i64;
        if ( v39 && v40 )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v40);
          v41 = *(_DWORD *)(v40 + 176);
          v42 = *(_DWORD *)(v40 + 180);
          v43 = *(_DWORD *)(v40 + 184);
          v44 = (int)(&v38[16].vfptr)[v37];
          v45 = v55.mEscapeOrigin.m_hkvMeshPosition.m_quad.m128_u32[0];
          v46 = v55.mEscapeOrigin.m_hkvMeshPosition.m_quad.m128_i32[0] + 1;
          if ( (unsigned int)(v55.mEscapeOrigin.m_hkvMeshPosition.m_quad.m128_i32[0] + 1) > v55.mEscapeOrigin.m_hkvMeshPosition.m_quad.m128_i32[1] )
          {
            if ( v55.mEscapeOrigin.m_hkvMeshPosition.m_quad.m128_i32[1] )
              v47 = 2 * v55.mEscapeOrigin.m_hkvMeshPosition.m_quad.m128_i32[1];
            else
              v47 = 1;
            for ( ; v47 < v46; v47 *= 2 )
              ;
            if ( v47 - v46 > 0x10000 )
              v47 = v55.mEscapeOrigin.m_hkvMeshPosition.m_quad.m128_i32[0] + 65537;
            UFG::qArray<UFG::FleeTraversalImmediateQuery::ThreatTarget,0>::Reallocate(
              (UFG::qArray<UFG::FleeTraversalImmediateQuery::ThreatTarget,0> *)&v55.mEscapeOrigin.m_hkvMeshPosition,
              v47,
              "qArray.Add");
          }
          v55.mEscapeOrigin.m_hkvMeshPosition.m_quad.m128_i32[0] = v46;
          v48 = v55.mEscapeOrigin.m_hkvMeshPosition.m_quad.m128_u64[1] + 80 * v45;
          *(_DWORD *)(v48 + 8) = v41;
          *(_DWORD *)(v48 + 12) = v42;
          *(_DWORD *)(v48 + 16) = v43;
          *(_BYTE *)(v48 + 24) = 0;
          *(_DWORD *)(v48 + 64) = v44;
        }
        v37 += 4i64;
        --v36;
      }
      while ( v36 );
    }
  }
  v49 = UFG::DaemonManager::Instance();
  UFG::DaemonManager::SubmitQuery(v49, &v55, (UFG::DaemonQueryOutput *)(&v55.mEscapeOrigin.m_aiMeshUid + 1));
  if ( v55.mThreats.size != 3 )
  {
    LODWORD(this->m_FleeDestination.x) = v55.m_mode;
    y = *((float *)&v55.m_mode + 1);
    this->m_FleeDestination.z = *(float *)&v55.m_pOutput;
    goto LABEL_77;
  }
  this->m_FleeDestination = v56;
  v50 = UFG::NavComponent::GetCurrentPosition((UFG::NavComponent *)this->m_pNavComponent.m_pPointer);
  v51 = v50->y + this->m_LastFleeOrigin.y;
  v52 = v50->z + this->m_LastFleeOrigin.z;
  this->m_LastFleeOrigin.x = (float)(this->m_LastFleeOrigin.x + v50->x) * 0.5;
  this->m_LastFleeOrigin.y = v51 * 0.5;
  this->m_LastFleeOrigin.z = v52 * 0.5;
  this->m_FailedQuery = 0;
LABEL_78:
  v53 = v60;
  if ( v60 )
  {
    --*(_DWORD *)(v60 + 40);
    if ( !*(_DWORD *)(v53 + 40) )
      (**(void (__fastcall ***)(__int64, __int64))v53)(v53, 1i64);
  }
  *(_QWORD *)(&v55.mEscapeOrigin.m_aiMeshUid + 1) = &UFG::DaemonQueryOutput::`vftable;
  if ( v55.mEscapeOrigin.m_hkvMeshPosition.m_quad.m128_u64[1] )
    operator delete[]((void *)v55.mEscapeOrigin.m_hkvMeshPosition.m_quad.m128_u64[1]);
}

// File Line: 1225
// RVA: 0x396F80
bool __fastcall FleeTask::UpdateInteriorFleeing(FleeTask *this)
{
  UFG::NavComponent *m_pPointer; // rbp
  UFG::SimComponent *v3; // rax
  UFG::SimObject *m_pSimObject; // rsi
  __int64 v5; // rbx
  __m128 v6; // xmm0
  __m128 v7; // xmm2
  UFG::HavokNavPosition npDestination; // [rsp+30h] [rbp-48h] BYREF

  if ( !this->m_pAIEntityComponent.m_pPointer )
    return 0;
  m_pPointer = (UFG::NavComponent *)this->m_pNavComponent.m_pPointer;
  if ( !m_pPointer )
    return 0;
  v3 = this->m_pFleeToPoint.m_pPointer;
  if ( !v3 )
    return 0;
  m_pSimObject = v3[1].m_pSimObject;
  if ( !m_pSimObject )
    return 0;
  v5 = BYTE4(this->m_Track[1].vfptr);
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)m_pSimObject);
  v6 = (__m128)LODWORD(m_pSimObject[1].mNode.mChild[1]);
  v7 = (__m128)HIDWORD(m_pSimObject[1].mNode.mChild[0]);
  npDestination.m_vPosition.x = *(float *)m_pSimObject[1].mNode.mChild;
  LODWORD(npDestination.m_vPosition.y) = v7.m128_i32[0];
  npDestination.m_bValid = 0;
  *(_QWORD *)&npDestination.m_packedKey = -1i64;
  npDestination.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
  LODWORD(npDestination.m_vPosition.z) = v6.m128_i32[0];
  npDestination.m_hkvMeshPosition.m_quad = _mm_unpacklo_ps(
                                             _mm_unpacklo_ps((__m128)LODWORD(npDestination.m_vPosition.x), v6),
                                             _mm_unpacklo_ps(v7, (__m128)(unsigned int)FLOAT_1_0));
  UFG::NavComponent::AddGoalPoint(m_pPointer, &npDestination, AiGoal_Replace, sNaturalMovementSpeeds[v5], 1.5);
  return !UFG::NavComponent::IsAtDestination((UFG::NavComponent *)this->m_pNavComponent.m_pPointer);
}

// File Line: 1250
// RVA: 0x396450
char __fastcall FleeTask::UpdateExteriorFleeing(FleeTask *this)
{
  __int64 v2; // rsi
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::NavComponent *m_pComponent; // rbx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  __m128 z_low; // xmm0
  __m128 x_low; // xmm3
  __m128 y_low; // xmm2
  UFG::HavokNavPosition npDestination; // [rsp+30h] [rbp-48h] BYREF

  if ( !this->m_pAIEntityComponent.m_pPointer )
    return 0;
  v2 = BYTE4(this->m_Track[1].vfptr);
  m_pPointer = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::NavComponent *)m_pPointer->m_Components.p[36].m_pComponent;
    }
    else
    {
      if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::NavComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::NavComponent::_TypeUID);
      m_pComponent = (UFG::NavComponent *)ComponentOfTypeHK;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  z_low = (__m128)LODWORD(this->m_FleeDestination.z);
  x_low = (__m128)LODWORD(this->m_FleeDestination.x);
  y_low = (__m128)LODWORD(this->m_FleeDestination.y);
  npDestination.m_bValid = 0;
  *(_QWORD *)&npDestination.m_packedKey = -1i64;
  LODWORD(npDestination.m_vPosition.x) = x_low.m128_i32[0];
  LODWORD(npDestination.m_vPosition.y) = y_low.m128_i32[0];
  npDestination.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
  LODWORD(npDestination.m_vPosition.z) = z_low.m128_i32[0];
  npDestination.m_hkvMeshPosition.m_quad = _mm_unpacklo_ps(
                                             _mm_unpacklo_ps(x_low, z_low),
                                             _mm_unpacklo_ps(y_low, (__m128)(unsigned int)FLOAT_1_0));
  UFG::NavComponent::AddGoalPoint(m_pComponent, &npDestination, AiGoal_Replace, sNaturalMovementSpeeds[v2], 1.5);
  if ( UFG::NavComponent::IsAtDestination(m_pComponent) )
  {
    FleeTask::BeginExteriorFleeing(this);
    return 0;
  }
  return 1;
}

// File Line: 1302
// RVA: 0x356AD0
float __fastcall FleeTask::FindNearestThreat(FleeTask *this, UFG::qVector3 *pNearestPosition)
{
  float v2; // xmm6_4
  float x; // xmm7_4
  float y; // xmm8_4
  float z; // xmm9_4
  UFG::NavComponent *m_pPointer; // rcx
  UFG::qVector4 *CurrentPosition; // r15
  __m128 y_low; // xmm0
  UFG::SimObjectGame *v11; // r8
  __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rbx
  UFG::SimComponent *v14; // rax
  UFG::TransformNodeComponent *mNext; // rdi
  __m128 v16; // xmm1
  float v17; // xmm2_4
  UFG::TransformNodeComponent *v18; // rbx
  __m128 v19; // xmm1
  float v20; // xmm2_4
  UFG::SimComponent *v21; // rax
  __int64 v22; // rsi
  __int64 v23; // rdi
  __int64 v24; // rcx
  UFG::TransformNodeComponent *v25; // rbx
  __m128 v26; // xmm1
  float v27; // xmm2_4
  float result; // xmm0_4

  v2 = FLOAT_N1_0;
  x = this->m_LastFleeOrigin.x;
  y = this->m_LastFleeOrigin.y;
  z = this->m_LastFleeOrigin.z;
  if ( this->m_pAIEntityComponent.m_pPointer )
  {
    m_pPointer = (UFG::NavComponent *)this->m_pNavComponent.m_pPointer;
    if ( m_pPointer )
    {
      CurrentPosition = UFG::NavComponent::GetCurrentPosition(m_pPointer);
      y_low = (__m128)LODWORD(CurrentPosition->y);
      v11 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
      y_low.m128_f32[0] = (float)((float)(y_low.m128_f32[0] - this->m_LastFleeOrigin.y)
                                * (float)(y_low.m128_f32[0] - this->m_LastFleeOrigin.y))
                        + (float)((float)(CurrentPosition->x - this->m_LastFleeOrigin.x)
                                * (float)(CurrentPosition->x - this->m_LastFleeOrigin.x));
      LODWORD(v2) = _mm_sqrt_ps(y_low).m128_u32[0];
      if ( v11 )
      {
        m_Flags = v11->m_Flags;
        if ( (m_Flags & 0x4000) != 0 )
        {
          m_pComponent = v11->m_Components.p[20].m_pComponent;
        }
        else if ( m_Flags >= 0 )
        {
          v14 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
              ? UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::TargetingSystemBaseComponent::_TypeUID)
              : UFG::SimObject::GetComponentOfType(v11, UFG::TargetingSystemBaseComponent::_TypeUID);
          m_pComponent = v14;
        }
        else
        {
          m_pComponent = v11->m_Components.p[20].m_pComponent;
        }
        if ( m_pComponent )
        {
          mNext = *(UFG::TransformNodeComponent **)(56i64
                                                  * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + 37i64)
                                                  + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                                  + 40);
          if ( mNext )
            mNext = (UFG::TransformNodeComponent *)mNext->mChildren.mNode.mNext;
          if ( mNext )
          {
            UFG::TransformNodeComponent::UpdateWorldTransform(mNext);
            v16 = (__m128)LODWORD(CurrentPosition->y);
            v16.m128_f32[0] = (float)((float)(v16.m128_f32[0] - mNext->mWorldTransform.v3.y)
                                    * (float)(v16.m128_f32[0] - mNext->mWorldTransform.v3.y))
                            + (float)((float)(CurrentPosition->x - mNext->mWorldTransform.v3.x)
                                    * (float)(CurrentPosition->x - mNext->mWorldTransform.v3.x));
            LODWORD(v17) = _mm_sqrt_ps(v16).m128_u32[0];
            if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(CurrentPosition->z - mNext->mWorldTransform.v3.z) & _xmm) < 3.0
              && (v2 < 0.0 || v17 < v2) )
            {
              v2 = v17;
              x = mNext->mWorldTransform.v3.x;
              y = mNext->mWorldTransform.v3.y;
              z = mNext->mWorldTransform.v3.z;
            }
          }
          v18 = *(UFG::TransformNodeComponent **)(56i64
                                                * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + 30i64)
                                                + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                                + 40);
          if ( v18 )
            v18 = (UFG::TransformNodeComponent *)v18->mChildren.mNode.mNext;
          if ( v18 )
          {
            UFG::TransformNodeComponent::UpdateWorldTransform(v18);
            v19 = (__m128)LODWORD(CurrentPosition->y);
            v19.m128_f32[0] = (float)((float)(v19.m128_f32[0] - v18->mWorldTransform.v3.y)
                                    * (float)(v19.m128_f32[0] - v18->mWorldTransform.v3.y))
                            + (float)((float)(CurrentPosition->x - v18->mWorldTransform.v3.x)
                                    * (float)(CurrentPosition->x - v18->mWorldTransform.v3.x));
            LODWORD(v20) = _mm_sqrt_ps(v19).m128_u32[0];
            if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(CurrentPosition->z - v18->mWorldTransform.v3.z) & _xmm) < 3.0
              && (v2 < 0.0 || v20 < v2) )
            {
              v2 = v20;
              x = v18->mWorldTransform.v3.x;
              y = v18->mWorldTransform.v3.y;
              z = v18->mWorldTransform.v3.z;
            }
          }
        }
      }
      v21 = this->m_pAIEntityComponent.m_pPointer;
      v22 = *(unsigned int *)&v21[15].m_Flags;
      if ( *(_DWORD *)&v21[15].m_Flags )
      {
        v23 = 0i64;
        do
        {
          v24 = *(__int64 *)((char *)&this->m_pAIEntityComponent.m_pPointer[15].m_BoundComponentHandles.mNode.mNext + v23);
          if ( v24 )
            v25 = *(UFG::TransformNodeComponent **)(v24 + 88);
          else
            v25 = 0i64;
          if ( v24 )
          {
            if ( v25 )
            {
              UFG::TransformNodeComponent::UpdateWorldTransform(v25);
              v26 = (__m128)LODWORD(CurrentPosition->y);
              v26.m128_f32[0] = (float)((float)(v26.m128_f32[0] - v25->mWorldTransform.v3.y)
                                      * (float)(v26.m128_f32[0] - v25->mWorldTransform.v3.y))
                              + (float)((float)(CurrentPosition->x - v25->mWorldTransform.v3.x)
                                      * (float)(CurrentPosition->x - v25->mWorldTransform.v3.x));
              LODWORD(v27) = _mm_sqrt_ps(v26).m128_u32[0];
              if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(CurrentPosition->z - v25->mWorldTransform.v3.z) & _xmm) < 3.0
                && (v2 < 0.0 || v27 < v2) )
              {
                v2 = v27;
                x = v25->mWorldTransform.v3.x;
                y = v25->mWorldTransform.v3.y;
                z = v25->mWorldTransform.v3.z;
              }
            }
          }
          v23 += 32i64;
          --v22;
        }
        while ( v22 );
      }
    }
  }
  result = v2;
  if ( pNearestPosition )
  {
    pNearestPosition->x = x;
    pNearestPosition->y = y;
    pNearestPosition->z = z;
  }
  return result;
}

// File Line: 1379
// RVA: 0x38A180
void __fastcall FleeTask::TurnToFaceNearestScaryThing(FleeTask *this)
{
  float v2; // xmm6_4
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::AICharacterControllerBaseComponent *ComponentOfTypeHK; // rax
  float *v6; // rbx
  UFG::qVector4 *CurrentPosition; // rax
  float v8; // xmm2_4
  __m128 y_low; // xmm3
  float v10; // xmm4_4
  __m128 v11; // xmm5
  UFG::qVector3 pNearestPosition; // [rsp+20h] [rbp-28h] BYREF

  if ( this->m_pAIEntityComponent.m_pPointer )
  {
    if ( this->m_pNavComponent.m_pPointer )
    {
      pNearestPosition = UFG::qVector3::msZero;
      v2 = 0.0;
      if ( FleeTask::FindNearestThreat(this, &pNearestPosition) >= 0.0 )
      {
        m_pPointer = (UFG::SimObjectCVBase *)this->m_pActionContext->mSimObject.m_pPointer;
        if ( m_pPointer )
        {
          m_Flags = m_pPointer->m_Flags;
          if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
          {
            ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(m_pPointer);
          }
          else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          {
            ComponentOfTypeHK = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                             m_pPointer,
                                                                             UFG::AICharacterControllerBaseComponent::_TypeUID);
          }
          else
          {
            ComponentOfTypeHK = (UFG::AICharacterControllerBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                                             m_pPointer,
                                                                             UFG::AICharacterControllerBaseComponent::_TypeUID);
          }
          v6 = (float *)ComponentOfTypeHK;
          if ( ComponentOfTypeHK )
          {
            CurrentPosition = UFG::NavComponent::GetCurrentPosition((UFG::NavComponent *)this->m_pNavComponent.m_pPointer);
            y_low = (__m128)LODWORD(pNearestPosition.y);
            v8 = pNearestPosition.x - CurrentPosition->x;
            y_low.m128_f32[0] = pNearestPosition.y - CurrentPosition->y;
            v10 = pNearestPosition.z - CurrentPosition->z;
            v11 = y_low;
            v11.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v8 * v8))
                            + (float)(v10 * v10);
            if ( v11.m128_f32[0] != 0.0 )
              v2 = 1.0 / _mm_sqrt_ps(v11).m128_f32[0];
            v6[37] = v8 * v2;
            v6[38] = y_low.m128_f32[0] * v2;
            v6[39] = v10 * v2;
          }
        }
      }
    }
  }
}

// File Line: 1410
// RVA: 0x399180
void __fastcall FleeTask::UpdateWhetherCurrentlyInInterior(FleeTask *this)
{
  ITrack *m_Track; // rax
  bool m_CurrentlyInInterior; // bp
  UFG::SimComponent *m_pPointer; // rax
  UFG::NavComponent *v5; // rcx
  UFG::qVector4 *CurrentPosition; // rdi
  UFG::TransformNodeComponent *m_pSimObject; // rbx
  __m128 y_low; // xmm2
  float v9; // xmm0_4

  m_Track = this->m_Track;
  m_CurrentlyInInterior = this->m_CurrentlyInInterior;
  if ( BYTE1(m_Track[1].mMasterRate.expression.mOffset) )
  {
    this->m_CurrentlyInInterior = BYTE1(m_Track[1].mMasterRate.expression.mOffset) == 1;
    goto LABEL_13;
  }
  if ( m_CurrentlyInInterior )
  {
    m_pPointer = this->m_pFleeToPoint.m_pPointer;
    if ( m_pPointer )
    {
      if ( m_pPointer[1].m_pSimObject )
      {
        v5 = (UFG::NavComponent *)this->m_pNavComponent.m_pPointer;
        if ( v5 )
        {
          CurrentPosition = UFG::NavComponent::GetCurrentPosition(v5);
          m_pSimObject = (UFG::TransformNodeComponent *)this->m_pFleeToPoint.m_pPointer[1].m_pSimObject;
          UFG::TransformNodeComponent::UpdateWorldTransform(m_pSimObject);
          y_low = (__m128)LODWORD(CurrentPosition->y);
          v9 = CurrentPosition->z - m_pSimObject->mWorldTransform.v3.z;
          y_low.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] - m_pSimObject->mWorldTransform.v3.y)
                                            * (float)(y_low.m128_f32[0] - m_pSimObject->mWorldTransform.v3.y))
                                    + (float)((float)(CurrentPosition->x - m_pSimObject->mWorldTransform.v3.x)
                                            * (float)(CurrentPosition->x - m_pSimObject->mWorldTransform.v3.x)))
                            + (float)(v9 * v9);
          if ( _mm_sqrt_ps(y_low).m128_f32[0] >= 5.0 )
            goto LABEL_13;
        }
      }
    }
  }
  else if ( (float)(UFG::Metrics::msInstance.mSimTime_Temp - this->m_LastTimeInteriorStatusChanged) <= 2.0 )
  {
    goto LABEL_13;
  }
  this->m_CurrentlyInInterior = BYTE4(this->m_pActorAudioComponent.m_pPointer[5].vfptr) != 0;
LABEL_13:
  if ( this->m_CurrentlyInInterior != m_CurrentlyInInterior )
    this->m_LastTimeInteriorStatusChanged = UFG::Metrics::msInstance.mSimTime_Temp;
}

// File Line: 1492
// RVA: 0x344BD0
void __fastcall FleeTask::Begin(FleeTask *this, ActionContext *action_context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::SimComponent *v4; // r8
  __int16 m_Flags; // dx
  UFG::ActiveAIEntityComponent *ComponentOfTypeHK; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pAIEntityComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::SimObjectGame *v11; // rcx
  UFG::SimComponent *m_pComponent; // r8
  __int16 v13; // dx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::NavComponent> *p_m_pNavComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rax
  UFG::SimObjectCharacter *v19; // rcx
  UFG::SimComponent *v20; // r8
  __int16 v21; // dx
  UFG::ActorAudioComponent *v22; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActorAudioComponent> *p_m_pActorAudioComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v24; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v25; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v26; // rax
  UFG::NavComponent *v27; // rcx
  UFG::qVector4 *CurrentPosition; // rax
  float y; // xmm0_4
  float z; // xmm1_4
  UFG::SimObject *v31; // rbx
  UFG::PedSpawnManager *Instance; // rax
  UFG::SimComponent *PedInfoFromSimObject; // rax

  this->m_pActionContext = action_context;
  if ( action_context )
  {
    m_pPointer = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
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
      v4 = ComponentOfTypeHK;
    }
    else
    {
      v4 = 0i64;
    }
    p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
    if ( this->m_pAIEntityComponent.m_pPointer )
    {
      mPrev = p_m_pAIEntityComponent->mPrev;
      mNext = this->m_pAIEntityComponent.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
      this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
    }
    this->m_pAIEntityComponent.m_pPointer = v4;
    if ( v4 )
    {
      v10 = v4->m_SafePointerList.mNode.mPrev;
      v10->mNext = p_m_pAIEntityComponent;
      p_m_pAIEntityComponent->mPrev = v10;
      this->m_pAIEntityComponent.mNext = &v4->m_SafePointerList.mNode;
      v4->m_SafePointerList.mNode.mPrev = p_m_pAIEntityComponent;
    }
    v11 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
    if ( v11 )
    {
      v13 = v11->m_Flags;
      if ( (v13 & 0x4000) != 0 )
      {
        m_pComponent = v11->m_Components.p[36].m_pComponent;
      }
      else
      {
        if ( v13 < 0 || (v13 & 0x2000) != 0 || (v13 & 0x1000) != 0 )
          ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::NavComponent::_TypeUID);
        else
          ComponentOfType = UFG::SimObject::GetComponentOfType(v11, UFG::NavComponent::_TypeUID);
        m_pComponent = ComponentOfType;
      }
    }
    else
    {
      m_pComponent = 0i64;
    }
    p_m_pNavComponent = &this->m_pNavComponent;
    if ( this->m_pNavComponent.m_pPointer )
    {
      v16 = p_m_pNavComponent->mPrev;
      v17 = this->m_pNavComponent.mNext;
      v16->mNext = v17;
      v17->mPrev = v16;
      p_m_pNavComponent->mPrev = p_m_pNavComponent;
      this->m_pNavComponent.mNext = &this->m_pNavComponent;
    }
    this->m_pNavComponent.m_pPointer = m_pComponent;
    if ( m_pComponent )
    {
      v18 = m_pComponent->m_SafePointerList.mNode.mPrev;
      v18->mNext = p_m_pNavComponent;
      p_m_pNavComponent->mPrev = v18;
      this->m_pNavComponent.mNext = &m_pComponent->m_SafePointerList.mNode;
      m_pComponent->m_SafePointerList.mNode.mPrev = p_m_pNavComponent;
    }
    v19 = (UFG::SimObjectCharacter *)this->m_pActionContext->mSimObject.m_pPointer;
    if ( v19 )
    {
      v21 = v19->m_Flags;
      if ( (v21 & 0x4000) != 0 )
      {
        v22 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(v19);
      }
      else if ( v21 < 0 || (v21 & 0x2000) != 0 || (v21 & 0x1000) != 0 )
      {
        v22 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                            v19,
                                            UFG::ActorAudioComponent::_TypeUID);
      }
      else
      {
        v22 = (UFG::ActorAudioComponent *)UFG::SimObject::GetComponentOfType(v19, UFG::ActorAudioComponent::_TypeUID);
      }
      v20 = v22;
    }
    else
    {
      v20 = 0i64;
    }
    p_m_pActorAudioComponent = &this->m_pActorAudioComponent;
    if ( this->m_pActorAudioComponent.m_pPointer )
    {
      v24 = p_m_pActorAudioComponent->mPrev;
      v25 = this->m_pActorAudioComponent.mNext;
      v24->mNext = v25;
      v25->mPrev = v24;
      p_m_pActorAudioComponent->mPrev = p_m_pActorAudioComponent;
      this->m_pActorAudioComponent.mNext = &this->m_pActorAudioComponent;
    }
    this->m_pActorAudioComponent.m_pPointer = v20;
    if ( v20 )
    {
      v26 = v20->m_SafePointerList.mNode.mPrev;
      v26->mNext = p_m_pActorAudioComponent;
      p_m_pActorAudioComponent->mPrev = v26;
      this->m_pActorAudioComponent.mNext = &v20->m_SafePointerList.mNode;
      v20->m_SafePointerList.mNode.mPrev = p_m_pActorAudioComponent;
    }
  }
  v27 = (UFG::NavComponent *)this->m_pNavComponent.m_pPointer;
  this->m_LastTimeInteriorStatusChanged = -99999.0;
  CurrentPosition = UFG::NavComponent::GetCurrentPosition(v27);
  y = CurrentPosition->y;
  z = CurrentPosition->z;
  this->m_LastFleeOrigin.x = CurrentPosition->x;
  this->m_LastFleeOrigin.y = y;
  this->m_LastFleeOrigin.z = z;
  this->m_FailedRetryCount = 0.0;
  this->m_FailedQuery = 1;
  FleeTask::UpdateWhetherCurrentlyInInterior(this);
  v31 = this->m_pActionContext->mSimObject.m_pPointer;
  Instance = UFG::PedSpawnManager::GetInstance();
  PedInfoFromSimObject = UFG::PedSpawnManager::FindPedInfoFromSimObject(Instance, v31);
  if ( PedInfoFromSimObject && LODWORD(PedInfoFromSimObject[12].m_BoundComponentHandles.mNode.mPrev) == 1 )
    *(_DWORD *)(&PedInfoFromSimObject[10].m_SimObjIndex + 1) = 4;
  if ( this->m_CurrentlyInInterior )
    FleeTask::BeginInteriorFleeing(this);
  else
    FleeTask::BeginExteriorFleeing(this);
}

// File Line: 1531
// RVA: 0x38EB80
char __fastcall FleeTask::Update(FleeTask *this, float timestep)
{
  char m_CurrentlyInInterior; // bl
  char v4; // al
  bool updated; // al
  bool IsDestinationUnreachable; // al
  UFG::qVector4 *CurrentPosition; // rax
  UFG::qVector3 pNearestPosition; // [rsp+20h] [rbp-38h] BYREF

  if ( this->m_pAIEntityComponent.m_pPointer )
  {
    m_CurrentlyInInterior = this->m_CurrentlyInInterior;
    FleeTask::UpdateWhetherCurrentlyInInterior(this);
    v4 = this->m_CurrentlyInInterior;
    if ( m_CurrentlyInInterior != v4 )
    {
      if ( v4 )
        FleeTask::BeginInteriorFleeing(this);
      else
        FleeTask::BeginExteriorFleeing(this);
    }
    if ( this->m_CurrentlyInInterior && this->m_pFleeToPoint.m_pPointer )
      updated = FleeTask::UpdateInteriorFleeing(this);
    else
      updated = FleeTask::UpdateExteriorFleeing(this);
    if ( !updated )
      FleeTask::TurnToFaceNearestScaryThing(this);
    IsDestinationUnreachable = UFG::NavComponent::IsDestinationUnreachable((UFG::NavComponent *)this->m_pNavComponent.m_pPointer);
    if ( IsDestinationUnreachable || this->m_FailedQuery )
      IsDestinationUnreachable = 1;
    if ( IsDestinationUnreachable )
    {
      this->m_FailedRetryCount = fmodf(this->m_FailedRetryCount + 1.0, *(float *)&this->m_Track[1].mResourceOwner);
    }
    else
    {
      if ( (float)(UFG::Metrics::msInstance.mSimTime_Temp - this->m_LastTimeFleeDirectionChecked) <= 0.5 )
        return 1;
      this->m_LastTimeFleeDirectionChecked = UFG::Metrics::msInstance.mSimTime_Temp;
      FleeTask::FindNearestThreat(this, &pNearestPosition);
      CurrentPosition = UFG::NavComponent::GetCurrentPosition((UFG::NavComponent *)this->m_pNavComponent.m_pPointer);
      if ( (float)((float)((float)((float)(this->m_FleeDestination.y - CurrentPosition->y)
                                 * (float)(pNearestPosition.y - CurrentPosition->y))
                         + (float)((float)(this->m_FleeDestination.x - CurrentPosition->x)
                                 * (float)(pNearestPosition.x - CurrentPosition->x)))
                 + (float)((float)(this->m_FleeDestination.z - CurrentPosition->z)
                         * (float)(pNearestPosition.z - CurrentPosition->z))) < 0.0 )
        return 1;
    }
    if ( this->m_CurrentlyInInterior )
    {
      FleeTask::BeginInteriorFleeing(this);
      return 1;
    }
    FleeTask::BeginExteriorFleeing(this);
    return 1;
  }
  return 0;
}

// File Line: 1660
// RVA: 0x355000
void __fastcall FleeTask::End(FleeTask *this)
{
  UFG::SimObject *m_pPointer; // r8
  __int16 m_Flags; // cx
  UFG::InterestPointUserComponent *m_pComponent; // rax

  UFG::GroupComponent::LeaveGroup(this->m_pActionContext->mSimObject.m_pPointer);
  m_pPointer = this->m_pActionContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::InterestPointUserComponent *)m_pPointer->m_Components.p[43].m_pComponent;
    }
    else
    {
      if ( m_Flags < 0 )
        return;
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = (UFG::InterestPointUserComponent *)m_pPointer->m_Components.p[12].m_pComponent;
      }
      else
      {
        if ( (m_Flags & 0x1000) != 0 )
          return;
        m_pComponent = (UFG::InterestPointUserComponent *)UFG::SimObject::GetComponentOfType(
                                                            m_pPointer,
                                                            UFG::InterestPointUserComponent::_TypeUID);
      }
    }
    if ( m_pComponent )
      UFG::InterestPointUserComponent::StopPOI(m_pComponent);
  }
}

// File Line: 1693
// RVA: 0x32F650
void __fastcall HangOutTask::HangOutTask(HangOutTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pAIEntityComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax

  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<HangOutTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&HangOutTask::`vftable;
  p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.mPrev = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.m_pPointer = 0i64;
  this->m_pActionContext = 0i64;
  if ( this->m_pAIEntityComponent.m_pPointer )
  {
    mPrev = p_m_pAIEntityComponent->mPrev;
    mNext = p_m_pAIEntityComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
    p_m_pAIEntityComponent->mNext = p_m_pAIEntityComponent;
  }
  p_m_pAIEntityComponent->m_pPointer = 0i64;
}

// File Line: 1701
// RVA: 0x338050
void __fastcall HangOutTask::~HangOutTask(HangOutTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pAIEntityComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rcx
  UFG::qNode<ITask,ITask> *v8; // rax

  this->vfptr = (ITaskVtbl *)&HangOutTask::`vftable;
  p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
  if ( this->m_pAIEntityComponent.m_pPointer )
  {
    mPrev = p_m_pAIEntityComponent->mPrev;
    mNext = p_m_pAIEntityComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
    p_m_pAIEntityComponent->mNext = p_m_pAIEntityComponent;
  }
  p_m_pAIEntityComponent->m_pPointer = 0i64;
  v5 = p_m_pAIEntityComponent->mPrev;
  v6 = p_m_pAIEntityComponent->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
  p_m_pAIEntityComponent->mNext = p_m_pAIEntityComponent;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v7 = this->mPrev;
  v8 = this->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 1706
// RVA: 0x348840
void __fastcall SetCurrentEmotionTask::Begin(SetFacialEmotionTask *this, ActionContext *action_context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::SimComponent *v4; // r8
  __int16 m_Flags; // dx
  UFG::ActiveAIEntityComponent *ComponentOfTypeHK; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pAIEntityComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax

  this->m_pActionContext = action_context;
  if ( action_context )
  {
    m_pPointer = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
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
      v4 = ComponentOfTypeHK;
    }
    else
    {
      v4 = 0i64;
    }
    p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
    if ( this->m_pAIEntityComponent.m_pPointer )
    {
      mPrev = p_m_pAIEntityComponent->mPrev;
      mNext = this->m_pAIEntityComponent.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
      this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
    }
    this->m_pAIEntityComponent.m_pPointer = v4;
    if ( v4 )
    {
      v10 = v4->m_SafePointerList.mNode.mPrev;
      v10->mNext = p_m_pAIEntityComponent;
      p_m_pAIEntityComponent->mPrev = v10;
      this->m_pAIEntityComponent.mNext = &v4->m_SafePointerList.mNode;
      v4->m_SafePointerList.mNode.mPrev = p_m_pAIEntityComponent;
    }
  }
}

// File Line: 1742
// RVA: 0x32FC30
void __fastcall IdleTask::IdleTask(IdleTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pAIEntityComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax

  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<IdleTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&IdleTask::`vftable;
  p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.mPrev = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.m_pPointer = 0i64;
  this->m_pActionContext = 0i64;
  if ( this->m_pAIEntityComponent.m_pPointer )
  {
    mPrev = p_m_pAIEntityComponent->mPrev;
    mNext = p_m_pAIEntityComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
    p_m_pAIEntityComponent->mNext = p_m_pAIEntityComponent;
  }
  p_m_pAIEntityComponent->m_pPointer = 0i64;
}

// File Line: 1750
// RVA: 0x3387D0
void __fastcall IdleTask::~IdleTask(IdleTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pAIEntityComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rcx
  UFG::qNode<ITask,ITask> *v8; // rax

  this->vfptr = (ITaskVtbl *)&IdleTask::`vftable;
  p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
  if ( this->m_pAIEntityComponent.m_pPointer )
  {
    mPrev = p_m_pAIEntityComponent->mPrev;
    mNext = p_m_pAIEntityComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
    p_m_pAIEntityComponent->mNext = p_m_pAIEntityComponent;
  }
  p_m_pAIEntityComponent->m_pPointer = 0i64;
  v5 = p_m_pAIEntityComponent->mPrev;
  v6 = p_m_pAIEntityComponent->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
  p_m_pAIEntityComponent->mNext = p_m_pAIEntityComponent;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v7 = this->mPrev;
  v8 = this->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 1791
// RVA: 0x32E0E0
void __fastcall FacialRequestTask::FacialRequestTask(FacialRequestTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pAIEntityComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax

  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<FacialRequestTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&FacialRequestTask::`vftable;
  p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.mPrev = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.m_pPointer = 0i64;
  this->m_pActionContext = 0i64;
  if ( this->m_pAIEntityComponent.m_pPointer )
  {
    mPrev = p_m_pAIEntityComponent->mPrev;
    mNext = p_m_pAIEntityComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
    p_m_pAIEntityComponent->mNext = p_m_pAIEntityComponent;
  }
  p_m_pAIEntityComponent->m_pPointer = 0i64;
}

// File Line: 1799
// RVA: 0x3366D0
void __fastcall FacialRequestTask::~FacialRequestTask(FacialRequestTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pAIEntityComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rcx
  UFG::qNode<ITask,ITask> *v8; // rax

  this->vfptr = (ITaskVtbl *)&FacialRequestTask::`vftable;
  p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
  if ( this->m_pAIEntityComponent.m_pPointer )
  {
    mPrev = p_m_pAIEntityComponent->mPrev;
    mNext = p_m_pAIEntityComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
    p_m_pAIEntityComponent->mNext = p_m_pAIEntityComponent;
  }
  p_m_pAIEntityComponent->m_pPointer = 0i64;
  v5 = p_m_pAIEntityComponent->mPrev;
  v6 = p_m_pAIEntityComponent->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
  p_m_pAIEntityComponent->mNext = p_m_pAIEntityComponent;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v7 = this->mPrev;
  v8 = this->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 1804
// RVA: 0x3448C0
void __fastcall FacialRequestTask::Begin(FacialRequestTask *this, ActionContext *action_context)
{
  UFG::SimComponent *ComponentOfType; // rdi
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::SimComponent *v5; // r8
  __int16 m_Flags; // dx
  UFG::ActiveAIEntityComponent *ComponentOfTypeHK; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pAIEntityComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::SimObject *v12; // rcx

  ComponentOfType = 0i64;
  this->m_pActionContext = action_context;
  this->m_fChargeTime = 0.0;
  if ( action_context )
  {
    m_pPointer = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
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
      v5 = ComponentOfTypeHK;
    }
    else
    {
      v5 = 0i64;
    }
    p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
    if ( this->m_pAIEntityComponent.m_pPointer )
    {
      mPrev = p_m_pAIEntityComponent->mPrev;
      mNext = this->m_pAIEntityComponent.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
      this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
    }
    this->m_pAIEntityComponent.m_pPointer = v5;
    if ( v5 )
    {
      v11 = v5->m_SafePointerList.mNode.mPrev;
      v11->mNext = p_m_pAIEntityComponent;
      p_m_pAIEntityComponent->mPrev = v11;
      this->m_pAIEntityComponent.mNext = &v5->m_SafePointerList.mNode;
      v5->m_SafePointerList.mNode.mPrev = p_m_pAIEntityComponent;
    }
    if ( WORD1(this->m_Track[1].vfptr) == 1 )
    {
      v12 = this->m_pActionContext->mSimObject.m_pPointer;
      if ( v12 )
        ComponentOfType = UFG::SimObject::GetComponentOfType(v12, UFG::AICharacterControllerBaseComponent::_TypeUID);
      this->m_fChargeTime = (float)*((unsigned __int8 *)&ComponentOfType[5].m_BoundComponentHandles.mNode.mNext
                                   + (unsigned int)SLOWORD(this->m_Track[1].vfptr))
                          * 0.016666668;
    }
  }
  FacialRequestTask::DoIntentionSetting(this);
}

// File Line: 1834
// RVA: 0x38EA10
char __fastcall FacialRequestTask::Update(FacialRequestTask *this, float timestep)
{
  ITrack *m_Track; // rax

  m_Track = this->m_Track;
  if ( BYTE4(m_Track[1].vfptr) )
  {
    if ( WORD1(m_Track[1].vfptr) == 1 )
      this->m_fChargeTime = timestep + this->m_fChargeTime;
    FacialRequestTask::DoIntentionSetting(this);
  }
  return 1;
}

// File Line: 1852
// RVA: 0x352CF0
void __fastcall FacialRequestTask::DoIntentionSetting(FacialRequestTask *this)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::AICharacterControllerBaseComponent *v3; // r9
  __int16 m_Flags; // dx
  UFG::AICharacterControllerBaseComponent *ComponentOfTypeHK; // rax
  __int64 vfptr_low; // r10
  float v7; // xmm0_4
  float v8; // xmm1_4

  m_pPointer = (UFG::SimObjectCVBase *)this->m_pActionContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(m_pPointer);
    }
    else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                       m_pPointer,
                                                                       UFG::AICharacterControllerBaseComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::AICharacterControllerBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                                       m_pPointer,
                                                                       UFG::AICharacterControllerBaseComponent::_TypeUID);
    }
    v3 = ComponentOfTypeHK;
  }
  else
  {
    v3 = 0i64;
  }
  vfptr_low = SLOWORD(this->m_Track[1].vfptr);
  v7 = this->m_fChargeTime * 60.0;
  v3->m_Intention.mFacialRequests.mBits[vfptr_low >> 6] |= 1i64 << ((__int64)this->m_Track[1].vfptr & 0x3F);
  v8 = (float)(int)v7;
  if ( v8 >= 255.0 )
    v8 = FLOAT_255_0;
  v3->m_Intention.mFacialRequestChargeTimes[vfptr_low] = (int)v8;
}

// File Line: 1879
// RVA: 0x32C270
void __fastcall ActionRequestTask::ActionRequestTask(ActionRequestTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pAIEntityComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax

  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<ActionRequestTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&ActionRequestTask::`vftable;
  p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.mPrev = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.m_pPointer = 0i64;
  this->m_pActionContext = 0i64;
  if ( this->m_pAIEntityComponent.m_pPointer )
  {
    mPrev = p_m_pAIEntityComponent->mPrev;
    mNext = p_m_pAIEntityComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
    p_m_pAIEntityComponent->mNext = p_m_pAIEntityComponent;
  }
  p_m_pAIEntityComponent->m_pPointer = 0i64;
}

// File Line: 1887
// RVA: 0x334EF0
void __fastcall ActionRequestTask::~ActionRequestTask(ActionRequestTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pAIEntityComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rcx
  UFG::qNode<ITask,ITask> *v8; // rax

  this->vfptr = (ITaskVtbl *)&ActionRequestTask::`vftable;
  p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
  if ( this->m_pAIEntityComponent.m_pPointer )
  {
    mPrev = p_m_pAIEntityComponent->mPrev;
    mNext = p_m_pAIEntityComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
    p_m_pAIEntityComponent->mNext = p_m_pAIEntityComponent;
  }
  p_m_pAIEntityComponent->m_pPointer = 0i64;
  v5 = p_m_pAIEntityComponent->mPrev;
  v6 = p_m_pAIEntityComponent->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
  p_m_pAIEntityComponent->mNext = p_m_pAIEntityComponent;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v7 = this->mPrev;
  v8 = this->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 1892
// RVA: 0x343C50
void __fastcall ActionRequestTask::Begin(ActionRequestTask *this, ActionContext *action_context)
{
  UFG::AICharacterControllerBaseComponent *v2; // rbx
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::SimComponent *v5; // r8
  __int16 m_Flags; // dx
  UFG::ActiveAIEntityComponent *v7; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pAIEntityComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::SimObjectCVBase *v12; // rcx
  __int16 v13; // dx
  UFG::AICharacterControllerBaseComponent *ComponentOfType; // rax
  unsigned int v15; // edx
  bool v16; // zf

  v2 = 0i64;
  this->m_pActionContext = action_context;
  this->m_fChargeTime = 0.0;
  if ( action_context )
  {
    m_pPointer = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
        v7 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(m_pPointer);
      else
        v7 = (UFG::ActiveAIEntityComponent *)((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                            ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                m_pPointer,
                                                UFG::ActiveAIEntityComponent::_TypeUID)
                                            : UFG::SimObject::GetComponentOfType(
                                                m_pPointer,
                                                UFG::ActiveAIEntityComponent::_TypeUID));
      v5 = v7;
    }
    else
    {
      v5 = 0i64;
    }
    p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
    if ( this->m_pAIEntityComponent.m_pPointer )
    {
      mPrev = p_m_pAIEntityComponent->mPrev;
      mNext = this->m_pAIEntityComponent.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
      this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
    }
    this->m_pAIEntityComponent.m_pPointer = v5;
    if ( v5 )
    {
      v11 = v5->m_SafePointerList.mNode.mPrev;
      v11->mNext = p_m_pAIEntityComponent;
      p_m_pAIEntityComponent->mPrev = v11;
      this->m_pAIEntityComponent.mNext = &v5->m_SafePointerList.mNode;
      v5->m_SafePointerList.mNode.mPrev = p_m_pAIEntityComponent;
    }
    if ( WORD1(this->m_Track[1].vfptr) == 1 )
    {
      v12 = (UFG::SimObjectCVBase *)this->m_pActionContext->mSimObject.m_pPointer;
      if ( !v12 )
      {
LABEL_27:
        this->m_fChargeTime = (float)(unsigned __int8)v2->m_Intention.mActionRequestChargeTimes[SLOWORD(this->m_Track[1].vfptr)]
                            * 0.016666668;
        goto LABEL_28;
      }
      v13 = v12->m_Flags;
      if ( (v13 & 0x4000) != 0 || v13 < 0 )
      {
        ComponentOfType = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v12);
      }
      else
      {
        if ( (v13 & 0x2000) != 0 )
        {
          v15 = UFG::AICharacterControllerBaseComponent::_TypeUID;
        }
        else
        {
          v16 = (v13 & 0x1000) == 0;
          v15 = UFG::AICharacterControllerBaseComponent::_TypeUID;
          if ( v16 )
          {
            ComponentOfType = (UFG::AICharacterControllerBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                                           v12,
                                                                           UFG::AICharacterControllerBaseComponent::_TypeUID);
            goto LABEL_26;
          }
        }
        ComponentOfType = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v12, v15);
      }
LABEL_26:
      v2 = ComponentOfType;
      goto LABEL_27;
    }
  }
LABEL_28:
  ActionRequestTask::DoIntentionSetting(this);
}

// File Line: 1922
// RVA: 0x38C860
char __fastcall ActionRequestTask::Update(ActionRequestTask *this, float timestep)
{
  ITrack *m_Track; // rax

  m_Track = this->m_Track;
  if ( BYTE4(m_Track[1].vfptr) )
  {
    if ( WORD1(m_Track[1].vfptr) == 1 )
      this->m_fChargeTime = timestep + this->m_fChargeTime;
    ActionRequestTask::DoIntentionSetting(this);
  }
  return 1;
}

// File Line: 1940
// RVA: 0x352C00
void __fastcall ActionRequestTask::DoIntentionSetting(ActionRequestTask *this)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::AICharacterControllerBaseComponent *v3; // rdx
  __int16 m_Flags; // dx
  UFG::AICharacterControllerBaseComponent *ComponentOfTypeHK; // rax
  __int64 vfptr_low; // r9
  __int64 v7; // r8
  float v8; // xmm0_4
  float v9; // xmm1_4

  m_pPointer = (UFG::SimObjectCVBase *)this->m_pActionContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(m_pPointer);
    }
    else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                       m_pPointer,
                                                                       UFG::AICharacterControllerBaseComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::AICharacterControllerBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                                       m_pPointer,
                                                                       UFG::AICharacterControllerBaseComponent::_TypeUID);
    }
    v3 = ComponentOfTypeHK;
  }
  else
  {
    v3 = 0i64;
  }
  vfptr_low = SLOWORD(this->m_Track[1].vfptr);
  v7 = 1i64 << ((__int64)this->m_Track[1].vfptr & 0x3F);
  v8 = this->m_fChargeTime * 60.0;
  v3->m_Intention.mActionRequests.mBits[vfptr_low >> 6] |= v7;
  v9 = (float)(int)v8;
  if ( v9 >= 255.0 )
    v9 = FLOAT_255_0;
  v3->m_Intention.mActionRequestChargeTimes[vfptr_low] = (int)v9;
  v3->m_Intention.mSignals |= v7;
}

// File Line: 1967
// RVA: 0x32C1C0
void __fastcall ActionRequestClearTask::ActionRequestClearTask(ActionRequestClearTask *this)
{
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<ActionRequestClearTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&ActionRequestClearTask::`vftable;
  this->m_pAIEntityComponent.mPrev = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.m_pPointer = 0i64;
  this->m_pActionContext = 0i64;
}

// File Line: 1974
// RVA: 0x334DF0
void __fastcall ActionRequestClearTask::~ActionRequestClearTask(ActionRequestClearTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pAIEntityComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rcx
  UFG::qNode<ITask,ITask> *v8; // rax

  this->vfptr = (ITaskVtbl *)&ActionRequestClearTask::`vftable;
  p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
  if ( this->m_pAIEntityComponent.m_pPointer )
  {
    mPrev = p_m_pAIEntityComponent->mPrev;
    mNext = p_m_pAIEntityComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
    p_m_pAIEntityComponent->mNext = p_m_pAIEntityComponent;
  }
  p_m_pAIEntityComponent->m_pPointer = 0i64;
  v5 = p_m_pAIEntityComponent->mPrev;
  v6 = p_m_pAIEntityComponent->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
  p_m_pAIEntityComponent->mNext = p_m_pAIEntityComponent;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v7 = this->mPrev;
  v8 = this->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 1988
// RVA: 0x38C7B0
char __fastcall ActionRequestClearTask::Update(ActionRequestClearTask *this, float timestep)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::AICharacterControllerBaseComponent *ComponentOfTypeHK; // rax
  UFG::AICharacterControllerBaseComponent *v6; // rdx
  __int64 vfptr_low; // rax

  m_pPointer = (UFG::SimObjectCVBase *)this->m_pActionContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(m_pPointer);
    }
    else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                       m_pPointer,
                                                                       UFG::AICharacterControllerBaseComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::AICharacterControllerBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                                       m_pPointer,
                                                                       UFG::AICharacterControllerBaseComponent::_TypeUID);
    }
    v6 = ComponentOfTypeHK;
    if ( ComponentOfTypeHK )
    {
      vfptr_low = SLOWORD(this->m_Track[1].vfptr);
      v6->m_Intention.mActionRequests.mBits[vfptr_low >> 6] &= ~(1i64 << (vfptr_low & 0x3F));
    }
  }
  return 1;
}

// File Line: 2020
// RVA: 0x32B850
void __fastcall AIObjectiveTask::AIObjectiveTask(AIObjectiveTask *this)
{
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<AIObjectiveTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&AIObjectiveTask::`vftable;
}

// File Line: 2032
// RVA: 0x3434F0
void __fastcall AIObjectiveTask::Begin(AIObjectiveTask *this, ActionContext *action_context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::SimComponent *m_pComponent; // rax
  UFG::SimObjectCVBase *v7; // rcx
  __int16 v8; // dx
  UFG::ActiveAIEntityComponent *ComponentOfTypeHK; // rax
  UFG::ActiveAIEntityComponent *v10; // rdi
  UFG::eAIObjective vfptr_low; // ebx
  const char *Clone; // rax

  if ( action_context )
  {
    m_pPointer = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = m_pPointer->m_Components.p[7].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 )
          m_pComponent = m_pPointer->m_Components.p[6].m_pComponent;
        else
          m_pComponent = (m_Flags & 0x1000) != 0
                       ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::ActionTreeComponent::_TypeUID)
                       : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::ActionTreeComponent::_TypeUID);
      }
      else
      {
        m_pComponent = m_pPointer->m_Components.p[7].m_pComponent;
      }
      if ( m_pComponent )
      {
        v7 = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
        if ( v7 )
        {
          v8 = v7->m_Flags;
          if ( (v8 & 0x4000) != 0 || v8 < 0 )
          {
            ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v7);
          }
          else if ( (v8 & 0x2000) != 0 || (v8 & 0x1000) != 0 )
          {
            ComponentOfTypeHK = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                  v7,
                                                                  UFG::ActiveAIEntityComponent::_TypeUID);
          }
          else
          {
            ComponentOfTypeHK = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                                  v7,
                                                                  UFG::ActiveAIEntityComponent::_TypeUID);
          }
          v10 = ComponentOfTypeHK;
          if ( ComponentOfTypeHK )
          {
            vfptr_low = LOBYTE(this->m_Track[1].vfptr);
            Clone = (const char *)TargetVisibleInAIDataCondition::CreateClone((hkResourceHandle *)action_context->mActionController);
            UFG::ActiveAIEntityComponent::SetCurrentObjective(v10, vfptr_low, Clone);
          }
        }
      }
    }
  }
}

// File Line: 2077
// RVA: 0x3328C0
void __fastcall UsePOITask::UsePOITask(UsePOITask *this)
{
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<UsePOITrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&UsePOITask::`vftable;
  this->m_pPOI.mPrev = &this->m_pPOI;
  this->m_pPOI.mNext = &this->m_pPOI;
  this->m_pPOI.m_pPointer = 0i64;
  this->m_pActionContext = 0i64;
  this->m_pFAC = 0i64;
}

// File Line: 2085
// RVA: 0x33B7A0
void __fastcall UsePOITask::~UsePOITask(UsePOITask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::InterestPoint> *p_m_pPOI; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rcx
  UFG::qNode<ITask,ITask> *v8; // rax

  this->vfptr = (ITaskVtbl *)&UsePOITask::`vftable;
  p_m_pPOI = &this->m_pPOI;
  if ( this->m_pPOI.m_pPointer )
  {
    mPrev = p_m_pPOI->mPrev;
    mNext = p_m_pPOI->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pPOI->mPrev = p_m_pPOI;
    p_m_pPOI->mNext = p_m_pPOI;
  }
  p_m_pPOI->m_pPointer = 0i64;
  v5 = p_m_pPOI->mPrev;
  v6 = p_m_pPOI->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_m_pPOI->mPrev = p_m_pPOI;
  p_m_pPOI->mNext = p_m_pPOI;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v7 = this->mPrev;
  v8 = this->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 2090
// RVA: 0x348C50
void __fastcall UsePOITask::Begin(UsePOITask *this, ActionContext *action_context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::FaceActionComponent *v4; // rdi
  UFG::SimComponent *m_pComponent; // rbx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectGame *v8; // rcx
  __int16 v9; // dx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::SimObject *v11; // rcx
  __int16 v12; // dx
  UFG::SimComponent *v13; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::InterestPoint> *p_m_pPOI; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *p_mNode; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rax

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
        m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                m_pPointer,
                                UFG::TargetingSystemBaseComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                m_pPointer,
                                UFG::TargetingSystemBaseComponent::_TypeUID);
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
    v8 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
    if ( v8 )
    {
      v9 = v8->m_Flags;
      if ( (v9 & 0x4000) != 0 )
      {
        v4 = (UFG::FaceActionComponent *)v8->m_Components.p[45].m_pComponent;
      }
      else
      {
        if ( v9 < 0 || (v9 & 0x2000) != 0 || (v9 & 0x1000) != 0 )
          ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::FaceActionComponent::_TypeUID);
        else
          ComponentOfType = UFG::SimObject::GetComponentOfType(v8, UFG::FaceActionComponent::_TypeUID);
        v4 = (UFG::FaceActionComponent *)ComponentOfType;
      }
    }
    this->m_pFAC = v4;
    if ( m_pComponent )
    {
      v11 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + 34i64)
                               + *(_QWORD *)&m_pComponent[1].m_TypeUID
                               + 40);
      if ( v11 )
      {
        v12 = v11->m_Flags;
        if ( (v12 & 0x4000) != 0 )
        {
          v13 = v11->m_Components.p[25].m_pComponent;
        }
        else if ( v12 >= 0 )
        {
          if ( (v12 & 0x2000) != 0 )
          {
            v13 = v11->m_Components.p[10].m_pComponent;
          }
          else if ( (v12 & 0x1000) != 0 )
          {
            v13 = v11->m_Components.p[3].m_pComponent;
          }
          else
          {
            v13 = UFG::SimObject::GetComponentOfType(v11, UFG::InterestPoint::_TypeUID);
          }
        }
        else
        {
          v13 = v11->m_Components.p[25].m_pComponent;
        }
        p_m_pPOI = &this->m_pPOI;
        if ( this->m_pPOI.m_pPointer )
        {
          mPrev = p_m_pPOI->mPrev;
          mNext = this->m_pPOI.mNext;
          mPrev->mNext = mNext;
          mNext->mPrev = mPrev;
          p_m_pPOI->mPrev = p_m_pPOI;
          this->m_pPOI.mNext = &this->m_pPOI;
        }
        this->m_pPOI.m_pPointer = v13;
        if ( v13 )
        {
          p_mNode = &v13->m_SafePointerList.mNode;
          v18 = v13->m_SafePointerList.mNode.mPrev;
          v18->mNext = p_m_pPOI;
          p_m_pPOI->mPrev = v18;
          this->m_pPOI.mNext = p_mNode;
          p_mNode->mPrev = p_m_pPOI;
        }
        if ( UFG::InterestPoint::IsReservationMatch(
               (UFG::InterestPoint *)this->m_pPOI.m_pPointer,
               2u,
               ReserveReason_normal) )
        {
          this->mTimePOIUnusedFor = FLOAT_N1_0;
        }
        else
        {
          this->mTimePOIUnusedFor = 0.0;
        }
      }
    }
  }
}

// File Line: 2111
// RVA: 0x3939C0
char __fastcall UsePOITask::Update(UsePOITask *this, float timestep)
{
  UFG::InterestPoint *m_pPointer; // rcx
  char v4; // si
  float mTimePOIUnusedFor; // xmm0_4
  UFG::FaceActionComponent *m_pFAC; // rax
  UFG::FaceActionComponent *v7; // rax
  UFG::SimObjectCVBase *v8; // rcx
  __int16 m_Flags; // dx
  UFG::AICharacterControllerBaseComponent *ComponentOfTypeHK; // rax
  UFG::AICharacterControllerBaseComponent *v11; // rdi
  unsigned __int64 v12; // rax

  m_pPointer = (UFG::InterestPoint *)this->m_pPOI.m_pPointer;
  v4 = 0;
  if ( !m_pPointer )
    return v4;
  mTimePOIUnusedFor = this->mTimePOIUnusedFor;
  if ( mTimePOIUnusedFor >= 0.0 )
  {
    if ( mTimePOIUnusedFor > *(float *)&this->m_Track[1].vfptr
      || UFG::InterestPoint::IsReservationMatch(m_pPointer, 2u, ReserveReason_normal) )
    {
      this->mTimePOIUnusedFor = -1.0;
    }
    else
    {
      m_pFAC = this->m_pFAC;
      v4 = 1;
      this->mTimePOIUnusedFor = timestep + this->mTimePOIUnusedFor;
      if ( m_pFAC )
        m_pFAC->mWaitingForPOIBlock = 1;
    }
  }
  if ( this->mTimePOIUnusedFor >= 0.0 )
    return v4;
  v7 = this->m_pFAC;
  if ( v7 )
    v7->mWaitingForPOIBlock = 0;
  v8 = (UFG::SimObjectCVBase *)this->m_pActionContext->mSimObject.m_pPointer;
  if ( !v8 )
    return v4;
  m_Flags = v8->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
  {
    ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v8);
  }
  else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
  {
    ComponentOfTypeHK = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                     v8,
                                                                     UFG::AICharacterControllerBaseComponent::_TypeUID);
  }
  else
  {
    ComponentOfTypeHK = (UFG::AICharacterControllerBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                                     v8,
                                                                     UFG::AICharacterControllerBaseComponent::_TypeUID);
  }
  v11 = ComponentOfTypeHK;
  if ( !ComponentOfTypeHK )
    return v4;
  if ( !UFG::InterestPoint::IsReservationMatch((UFG::InterestPoint *)this->m_pPOI.m_pPointer, 2u, ReserveReason_normal) )
  {
    v12 = v11->m_Intention.mActionRequests.mBits[(__int64)(int)gActionRequest_POI_Use.m_EnumValue >> 6];
    if ( !_bittest64((const __int64 *)&v12, gActionRequest_POI_Use.m_EnumValue & 0x3F)
      || v11->m_Intention.mActionRequestChargeTimes[gActionRequest_POI_Use.m_EnumValue] )
    {
      return 0;
    }
  }
  return !UFG::InterestPoint::IsReservationMatch(
            (UFG::InterestPoint *)this->m_pPOI.m_pPointer,
            0x10u,
            ReserveReason_normal);
}

// File Line: 2163
// RVA: 0x355630
void __fastcall UsePOITask::End(UsePOITask *this)
{
  UFG::FaceActionComponent *m_pFAC; // rax

  m_pFAC = this->m_pFAC;
  if ( m_pFAC )
    m_pFAC->mWaitingForPOIBlock = 0;
}

// File Line: 2178
// RVA: 0x330CB0
void __fastcall POIBeginTask::POIBeginTask(POIBeginTask *this)
{
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<POIBeginTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&POIBeginTask::`vftable;
}

// File Line: 2188
// RVA: 0x347260
void __fastcall POIBeginTask::Begin(POIBeginTask *this, ActionContext *action_context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObject *v7; // rcx
  __int16 v8; // dx
  UFG::InterestPoint *v9; // rbx

  if ( action_context )
  {
    m_pPointer = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
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
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                m_pPointer,
                                UFG::TargetingSystemBaseComponent::_TypeUID);
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
            v9 = (UFG::InterestPoint *)v7->m_Components.p[25].m_pComponent;
          }
          else if ( v8 >= 0 )
          {
            if ( (v8 & 0x2000) != 0 )
              v9 = (UFG::InterestPoint *)v7->m_Components.p[10].m_pComponent;
            else
              v9 = (UFG::InterestPoint *)((v8 & 0x1000) != 0
                                        ? v7->m_Components.p[3].m_pComponent
                                        : UFG::SimObject::GetComponentOfType(v7, UFG::InterestPoint::_TypeUID));
          }
          else
          {
            v9 = (UFG::InterestPoint *)v7->m_Components.p[25].m_pComponent;
          }
          if ( v9 )
          {
            if ( UFG::InterestPoint::IsReservationMatch(v9, 8u, ReserveReason_normal) )
              UFG::InterestPoint::BeginReservation(v9, action_context->mSimObject.m_pPointer, ReserveReason_normal);
            UFG::InterestPoint::BeginUsing(v9);
          }
        }
      }
    }
  }
}

// File Line: 2220
// RVA: 0x32D310
void __fastcall CollisionAvoidanceTask::CollisionAvoidanceTask(CollisionAvoidanceTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pAIEntityComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax

  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<CollisionAvoidanceTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&CollisionAvoidanceTask::`vftable;
  p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.mPrev = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.m_pPointer = 0i64;
  if ( this->m_pAIEntityComponent.m_pPointer )
  {
    mPrev = p_m_pAIEntityComponent->mPrev;
    mNext = p_m_pAIEntityComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
    p_m_pAIEntityComponent->mNext = p_m_pAIEntityComponent;
  }
  p_m_pAIEntityComponent->m_pPointer = 0i64;
}

// File Line: 2227
// RVA: 0x335B60
void __fastcall CollisionAvoidanceTask::~CollisionAvoidanceTask(CollisionAvoidanceTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pAIEntityComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rcx
  UFG::qNode<ITask,ITask> *v8; // rax

  this->vfptr = (ITaskVtbl *)&CollisionAvoidanceTask::`vftable;
  p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
  if ( this->m_pAIEntityComponent.m_pPointer )
  {
    mPrev = p_m_pAIEntityComponent->mPrev;
    mNext = p_m_pAIEntityComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
    p_m_pAIEntityComponent->mNext = p_m_pAIEntityComponent;
  }
  p_m_pAIEntityComponent->m_pPointer = 0i64;
  v5 = p_m_pAIEntityComponent->mPrev;
  v6 = p_m_pAIEntityComponent->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
  p_m_pAIEntityComponent->mNext = p_m_pAIEntityComponent;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v7 = this->mPrev;
  v8 = this->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 2232
// RVA: 0x3443D0
void __fastcall CollisionAvoidanceTask::Begin(CollisionAvoidanceTask *this, ActionContext *action_context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::SimComponent *v4; // r8
  __int16 m_Flags; // dx
  UFG::ActiveAIEntityComponent *ComponentOfTypeHK; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pAIEntityComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax

  if ( action_context )
  {
    m_pPointer = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
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
      v4 = ComponentOfTypeHK;
    }
    else
    {
      v4 = 0i64;
    }
    p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
    if ( this->m_pAIEntityComponent.m_pPointer )
    {
      mPrev = p_m_pAIEntityComponent->mPrev;
      mNext = this->m_pAIEntityComponent.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
      this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
    }
    this->m_pAIEntityComponent.m_pPointer = v4;
    if ( v4 )
    {
      v10 = v4->m_SafePointerList.mNode.mPrev;
      v10->mNext = p_m_pAIEntityComponent;
      p_m_pAIEntityComponent->mPrev = v10;
      this->m_pAIEntityComponent.mNext = &v4->m_SafePointerList.mNode;
      v4->m_SafePointerList.mNode.mPrev = p_m_pAIEntityComponent;
    }
  }
}

// File Line: 2309
// RVA: 0x330FC0
void __fastcall Pathing_OverrideCollisionAvoidanceTypeTask::Pathing_OverrideCollisionAvoidanceTypeTask(
        Pathing_OverrideCollisionAvoidanceTypeTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::NavComponent> *p_m_pNavComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax

  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<Pathing_OverrideCollisionAvoidanceTypeTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&Pathing_OverrideCollisionAvoidanceTypeTask::`vftable;
  p_m_pNavComponent = &this->m_pNavComponent;
  this->m_pNavComponent.mPrev = &this->m_pNavComponent;
  this->m_pNavComponent.mNext = &this->m_pNavComponent;
  this->m_pNavComponent.m_pPointer = 0i64;
  if ( this->m_pNavComponent.m_pPointer )
  {
    mPrev = p_m_pNavComponent->mPrev;
    mNext = p_m_pNavComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pNavComponent->mPrev = p_m_pNavComponent;
    p_m_pNavComponent->mNext = p_m_pNavComponent;
  }
  p_m_pNavComponent->m_pPointer = 0i64;
}

// File Line: 2316
// RVA: 0x339DC0
void __fastcall Pathing_OverrideCollisionAvoidanceTypeTask::~Pathing_OverrideCollisionAvoidanceTypeTask(
        Pathing_OverrideCollisionAvoidanceTypeTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::NavComponent> *p_m_pNavComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rcx
  UFG::qNode<ITask,ITask> *v8; // rax

  this->vfptr = (ITaskVtbl *)&Pathing_OverrideCollisionAvoidanceTypeTask::`vftable;
  p_m_pNavComponent = &this->m_pNavComponent;
  if ( this->m_pNavComponent.m_pPointer )
  {
    mPrev = p_m_pNavComponent->mPrev;
    mNext = p_m_pNavComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pNavComponent->mPrev = p_m_pNavComponent;
    p_m_pNavComponent->mNext = p_m_pNavComponent;
  }
  p_m_pNavComponent->m_pPointer = 0i64;
  v5 = p_m_pNavComponent->mPrev;
  v6 = p_m_pNavComponent->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_m_pNavComponent->mPrev = p_m_pNavComponent;
  p_m_pNavComponent->mNext = p_m_pNavComponent;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v7 = this->mPrev;
  v8 = this->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 2321
// RVA: 0x347900
void __fastcall Pathing_OverrideCollisionAvoidanceTypeTask::Begin(
        Pathing_OverrideCollisionAvoidanceTypeTask *this,
        ActionContext *action_context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::SimComponent *m_pComponent; // r8
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::NavComponent> *p_m_pNavComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::NavComponent *v11; // rcx
  UFG::eCollisionAvoidanceType CollisionAvoidanceType; // eax
  UFG::NavComponent *v13; // rcx

  m_pPointer = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[36].m_pComponent;
    }
    else
    {
      if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::NavComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::NavComponent::_TypeUID);
      m_pComponent = ComponentOfTypeHK;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  p_m_pNavComponent = &this->m_pNavComponent;
  if ( this->m_pNavComponent.m_pPointer )
  {
    mPrev = p_m_pNavComponent->mPrev;
    mNext = this->m_pNavComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pNavComponent->mPrev = p_m_pNavComponent;
    this->m_pNavComponent.mNext = &this->m_pNavComponent;
  }
  this->m_pNavComponent.m_pPointer = m_pComponent;
  if ( m_pComponent )
  {
    v10 = m_pComponent->m_SafePointerList.mNode.mPrev;
    v10->mNext = p_m_pNavComponent;
    p_m_pNavComponent->mPrev = v10;
    this->m_pNavComponent.mNext = &m_pComponent->m_SafePointerList.mNode;
    m_pComponent->m_SafePointerList.mNode.mPrev = p_m_pNavComponent;
  }
  v11 = (UFG::NavComponent *)this->m_pNavComponent.m_pPointer;
  if ( v11 )
  {
    CollisionAvoidanceType = (unsigned int)UFG::NavComponent::GetCollisionAvoidanceType(v11);
    v13 = (UFG::NavComponent *)this->m_pNavComponent.m_pPointer;
    this->m_PrevCollisionAvoidanceType = CollisionAvoidanceType;
    UFG::NavComponent::SetCollisionAvoidanceType(v13, LOBYTE(this->m_Track[1].vfptr));
  }
}

// File Line: 2346
// RVA: 0x3553C0
void __fastcall Pathing_OverrideCollisionAvoidanceTypeTask::End(Pathing_OverrideCollisionAvoidanceTypeTask *this)
{
  if ( this->m_pNavComponent.m_pPointer )
    UFG::NavComponent::SetCollisionAvoidanceType(
      (UFG::NavComponent *)this->m_pNavComponent.m_pPointer,
      (unsigned int)this->m_PrevCollisionAvoidanceType);
}

// File Line: 2362
// RVA: 0x32C0A0
void __fastcall ActionRequestAndWaitUntilPlayingTask::ActionRequestAndWaitUntilPlayingTask(
        ActionRequestAndWaitUntilPlayingTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pAIEntityComponent; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::ActionTreeComponent> *p_m_pActionTreeComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax

  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<ActionRequestAndWaitUntilPlayingTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&ActionRequestAndWaitUntilPlayingTask::`vftable;
  p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.mPrev = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.m_pPointer = 0i64;
  p_m_pActionTreeComponent = &this->m_pActionTreeComponent;
  this->m_pActionTreeComponent.mPrev = &this->m_pActionTreeComponent;
  this->m_pActionTreeComponent.mNext = &this->m_pActionTreeComponent;
  this->m_pActionTreeComponent.m_pPointer = 0i64;
  this->m_pActionContext = 0i64;
  if ( this->m_pAIEntityComponent.m_pPointer )
  {
    mPrev = p_m_pAIEntityComponent->mPrev;
    mNext = p_m_pAIEntityComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
    p_m_pAIEntityComponent->mNext = p_m_pAIEntityComponent;
  }
  p_m_pAIEntityComponent->m_pPointer = 0i64;
  if ( p_m_pActionTreeComponent->m_pPointer )
  {
    v6 = p_m_pActionTreeComponent->mPrev;
    v7 = p_m_pActionTreeComponent->mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    p_m_pActionTreeComponent->mPrev = p_m_pActionTreeComponent;
    p_m_pActionTreeComponent->mNext = p_m_pActionTreeComponent;
  }
  p_m_pActionTreeComponent->m_pPointer = 0i64;
  *(_WORD *)&this->m_HasFinishedNodePreviously = 0;
}

// File Line: 2374
// RVA: 0x334CB0
void __fastcall ActionRequestAndWaitUntilPlayingTask::~ActionRequestAndWaitUntilPlayingTask(
        ActionRequestAndWaitUntilPlayingTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::ActionTreeComponent> *p_m_pActionTreeComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pAIEntityComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<ITask,ITask> *v12; // rcx
  UFG::qNode<ITask,ITask> *v13; // rax

  this->vfptr = (ITaskVtbl *)&ActionRequestAndWaitUntilPlayingTask::`vftable;
  p_m_pActionTreeComponent = &this->m_pActionTreeComponent;
  if ( this->m_pActionTreeComponent.m_pPointer )
  {
    mPrev = p_m_pActionTreeComponent->mPrev;
    mNext = p_m_pActionTreeComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pActionTreeComponent->mPrev = p_m_pActionTreeComponent;
    p_m_pActionTreeComponent->mNext = p_m_pActionTreeComponent;
  }
  p_m_pActionTreeComponent->m_pPointer = 0i64;
  v5 = p_m_pActionTreeComponent->mPrev;
  v6 = p_m_pActionTreeComponent->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_m_pActionTreeComponent->mPrev = p_m_pActionTreeComponent;
  p_m_pActionTreeComponent->mNext = p_m_pActionTreeComponent;
  p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
  if ( this->m_pAIEntityComponent.m_pPointer )
  {
    v8 = p_m_pAIEntityComponent->mPrev;
    v9 = this->m_pAIEntityComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
    this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
  }
  this->m_pAIEntityComponent.m_pPointer = 0i64;
  v10 = p_m_pAIEntityComponent->mPrev;
  v11 = this->m_pAIEntityComponent.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
  this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v12 = this->mPrev;
  v13 = this->mNext;
  v12->mNext = v13;
  v13->mPrev = v12;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 2379
// RVA: 0x343A70
void __fastcall ActionRequestAndWaitUntilPlayingTask::Begin(
        ActionRequestAndWaitUntilPlayingTask *this,
        ActionContext *action_context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::SimComponent *m_pComponent; // rdi
  UFG::SimComponent *v5; // r8
  __int16 m_Flags; // dx
  UFG::ActiveAIEntityComponent *ComponentOfTypeHK; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pAIEntityComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::SimObjectGame *v12; // rcx
  __int16 v13; // dx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActionTreeComponent> *p_m_pActionTreeComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rax
  UFG::SimComponent *v19; // rcx

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
      v5 = ComponentOfTypeHK;
    }
    else
    {
      v5 = 0i64;
    }
    p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
    if ( this->m_pAIEntityComponent.m_pPointer )
    {
      mPrev = p_m_pAIEntityComponent->mPrev;
      mNext = this->m_pAIEntityComponent.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
      this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
    }
    this->m_pAIEntityComponent.m_pPointer = v5;
    if ( v5 )
    {
      v11 = v5->m_SafePointerList.mNode.mPrev;
      v11->mNext = p_m_pAIEntityComponent;
      p_m_pAIEntityComponent->mPrev = v11;
      this->m_pAIEntityComponent.mNext = &v5->m_SafePointerList.mNode;
      v5->m_SafePointerList.mNode.mPrev = p_m_pAIEntityComponent;
    }
    v12 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
    if ( v12 )
    {
      v13 = v12->m_Flags;
      if ( (v13 & 0x4000) != 0 )
      {
        m_pComponent = v12->m_Components.p[7].m_pComponent;
      }
      else if ( v13 >= 0 )
      {
        if ( (v13 & 0x2000) != 0 )
        {
          m_pComponent = v12->m_Components.p[6].m_pComponent;
        }
        else
        {
          if ( (v13 & 0x1000) != 0 )
            ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::ActionTreeComponent::_TypeUID);
          else
            ComponentOfType = UFG::SimObject::GetComponentOfType(v12, UFG::ActionTreeComponent::_TypeUID);
          m_pComponent = ComponentOfType;
        }
      }
      else
      {
        m_pComponent = v12->m_Components.p[7].m_pComponent;
      }
    }
    p_m_pActionTreeComponent = &this->m_pActionTreeComponent;
    if ( this->m_pActionTreeComponent.m_pPointer )
    {
      v16 = p_m_pActionTreeComponent->mPrev;
      v17 = this->m_pActionTreeComponent.mNext;
      v16->mNext = v17;
      v17->mPrev = v16;
      p_m_pActionTreeComponent->mPrev = p_m_pActionTreeComponent;
      this->m_pActionTreeComponent.mNext = &this->m_pActionTreeComponent;
    }
    this->m_pActionTreeComponent.m_pPointer = m_pComponent;
    if ( m_pComponent )
    {
      v18 = m_pComponent->m_SafePointerList.mNode.mPrev;
      v18->mNext = p_m_pActionTreeComponent;
      p_m_pActionTreeComponent->mPrev = v18;
      this->m_pActionTreeComponent.mNext = &m_pComponent->m_SafePointerList.mNode;
      m_pComponent->m_SafePointerList.mNode.mPrev = p_m_pActionTreeComponent;
    }
    v19 = this->m_pActionTreeComponent.m_pPointer;
    if ( v19 )
      this->m_HasFinishedNodePreviously = ActionController::IsPlaying(
                                            (ActionController *)&v19[3],
                                            (ActionID *)&this->m_Track[1],
                                            0xFFFFFFFF,
                                            BYTE4(this->m_Track[1].mResourceOwner) != 0) == 0;
    this->m_HasStartedNode = 0;
    this->m_TimeBegan = UFG::Metrics::msInstance.mSimTime_Temp;
  }
  else
  {
    this->m_HasStartedNode = 0;
    this->m_TimeBegan = UFG::Metrics::msInstance.mSimTime_Temp;
  }
}

// File Line: 2401
// RVA: 0x38C660
char __fastcall ActionRequestAndWaitUntilPlayingTask::Update(
        ActionRequestAndWaitUntilPlayingTask *this,
        float timestep)
{
  ITrack *m_Track; // rdx
  char result; // al
  unsigned int v5; // esi
  bool v6; // di
  float v7; // xmm1_4
  bool v8; // bp
  UFG::SimComponent *m_pPointer; // rcx
  UFG::SimComponent *v10; // rcx

  m_Track = this->m_Track;
  result = this->m_HasStartedNode;
  v5 = BYTE5(m_Track[1].mResourceOwner);
  v6 = 1;
  v7 = *((float *)&m_Track[1].vfptr + 1);
  v8 = (_BYTE)v5 == 3;
  if ( result || v7 < 0.0 || (float)(UFG::Metrics::msInstance.mSimTime_Temp - this->m_TimeBegan) <= v7 )
  {
    if ( this->m_HasFinishedNodePreviously || v5 > 1 )
    {
      if ( !result )
      {
        m_pPointer = this->m_pActionTreeComponent.m_pPointer;
        if ( m_pPointer )
          this->m_HasStartedNode = ActionController::IsPlaying(
                                     (ActionController *)&m_pPointer[3],
                                     (ActionID *)&m_Track[1],
                                     0xFFFFFFFF,
                                     BYTE4(m_Track[1].mResourceOwner) != 0);
      }
      if ( this->m_HasStartedNode )
      {
        v10 = this->m_pActionTreeComponent.m_pPointer;
        if ( v10 )
          v6 = v5 <= 1
            || ActionController::IsPlaying(
                 (ActionController *)&v10[3],
                 (ActionID *)&this->m_Track[1],
                 0xFFFFFFFF,
                 BYTE4(this->m_Track[1].mResourceOwner) != 0) == 0;
      }
      else
      {
        v6 = 0;
        v8 = 1;
      }
      if ( v8 && !v6 )
        ActionRequestAndWaitUntilPlayingTask::PressActionRequest(this);
      return !v6;
    }
    else
    {
      this->m_HasFinishedNodePreviously = ActionController::IsPlaying(
                                            (ActionController *)&this->m_pActionTreeComponent.m_pPointer[3],
                                            (ActionID *)&m_Track[1],
                                            0xFFFFFFFF,
                                            BYTE4(m_Track[1].mResourceOwner) != 0) == 0;
      if ( v5 == 1 )
        ActionRequestAndWaitUntilPlayingTask::PressActionRequest(this);
      return 1;
    }
  }
  return result;
}

// File Line: 2482
// RVA: 0x37C870
void __fastcall ActionRequestAndWaitUntilPlayingTask::PressActionRequest(ActionRequestAndWaitUntilPlayingTask *this)
{
  __int64 mResourceOwner_low; // rbx
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::AICharacterControllerBaseComponent *v3; // rdx
  __int16 m_Flags; // dx
  UFG::AICharacterControllerBaseComponent *ComponentOfTypeHK; // rax
  __int64 v6; // r8
  float v7; // xmm0_4

  mResourceOwner_low = LODWORD(this->m_Track[1].mResourceOwner);
  if ( this->m_pAIEntityComponent.m_pPointer )
  {
    m_pPointer = (UFG::SimObjectCVBase *)this->m_pActionContext->mSimObject.m_pPointer;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
      {
        ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(m_pPointer);
      }
      else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      {
        ComponentOfTypeHK = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                         m_pPointer,
                                                                         UFG::AICharacterControllerBaseComponent::_TypeUID);
      }
      else
      {
        ComponentOfTypeHK = (UFG::AICharacterControllerBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                                         m_pPointer,
                                                                         UFG::AICharacterControllerBaseComponent::_TypeUID);
      }
      v3 = ComponentOfTypeHK;
    }
    else
    {
      v3 = 0i64;
    }
    v6 = 1i64 << (mResourceOwner_low & 0x3F);
    v3->m_Intention.mActionRequests.mBits[(__int64)(int)mResourceOwner_low >> 6] |= v6;
    v7 = (float)(int)0.0;
    if ( v7 >= 255.0 )
      v7 = FLOAT_255_0;
    v3->m_Intention.mActionRequestChargeTimes[mResourceOwner_low] = (int)v7;
    v3->m_Intention.mSignals |= v6;
  }
}

// File Line: 2523
// RVA: 0x3912F0
char __fastcall NodeRequestTask::Update(NodeRequestTask *this, float timeDelta)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimObjectGame *v5; // rcx
  __int16 v6; // dx

  m_pPointer = (UFG::SimObjectCVBase *)this->mContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(m_pPointer);
    }
    else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::ActiveAIEntityComponent::_TypeUID);
    }
    else
    {
      UFG::SimObject::GetComponentOfType(m_pPointer, UFG::ActiveAIEntityComponent::_TypeUID);
    }
  }
  v5 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( v5 )
  {
    v6 = v5->m_Flags;
    if ( (v6 & 0x4000) == 0 && v6 >= 0 && (v6 & 0x2000) == 0 )
    {
      if ( (v6 & 0x1000) != 0 )
      {
        UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::ActionTreeComponent::_TypeUID);
        return 1;
      }
      UFG::SimObject::GetComponentOfType(v5, UFG::ActionTreeComponent::_TypeUID);
    }
  }
  return 1;
}

// File Line: 2547
// RVA: 0x3309E0
void __fastcall NodeRequestAndWaitUntilPlayingTask::NodeRequestAndWaitUntilPlayingTask(
        NodeRequestAndWaitUntilPlayingTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pAIEntityComponent; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::ActionTreeComponent> *p_m_pActionTreeComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax

  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<NodeRequestAndWaitUntilPlayingTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&NodeRequestAndWaitUntilPlayingTask::`vftable;
  p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.mPrev = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.m_pPointer = 0i64;
  p_m_pActionTreeComponent = &this->m_pActionTreeComponent;
  this->m_pActionTreeComponent.mPrev = &this->m_pActionTreeComponent;
  this->m_pActionTreeComponent.mNext = &this->m_pActionTreeComponent;
  this->m_pActionTreeComponent.m_pPointer = 0i64;
  this->m_pActionContext = 0i64;
  if ( this->m_pAIEntityComponent.m_pPointer )
  {
    mPrev = p_m_pAIEntityComponent->mPrev;
    mNext = p_m_pAIEntityComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
    p_m_pAIEntityComponent->mNext = p_m_pAIEntityComponent;
  }
  p_m_pAIEntityComponent->m_pPointer = 0i64;
  if ( p_m_pActionTreeComponent->m_pPointer )
  {
    v6 = p_m_pActionTreeComponent->mPrev;
    v7 = p_m_pActionTreeComponent->mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    p_m_pActionTreeComponent->mPrev = p_m_pActionTreeComponent;
    p_m_pActionTreeComponent->mNext = p_m_pActionTreeComponent;
  }
  p_m_pActionTreeComponent->m_pPointer = 0i64;
  this->m_HasStartedNode = 0;
}

// File Line: 2558
// RVA: 0x339680
void __fastcall NodeRequestAndWaitUntilPlayingTask::~NodeRequestAndWaitUntilPlayingTask(
        NodeRequestAndWaitUntilPlayingTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::ActionTreeComponent> *p_m_pActionTreeComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pAIEntityComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<ITask,ITask> *v12; // rcx
  UFG::qNode<ITask,ITask> *v13; // rax

  this->vfptr = (ITaskVtbl *)&NodeRequestAndWaitUntilPlayingTask::`vftable;
  p_m_pActionTreeComponent = &this->m_pActionTreeComponent;
  if ( this->m_pActionTreeComponent.m_pPointer )
  {
    mPrev = p_m_pActionTreeComponent->mPrev;
    mNext = p_m_pActionTreeComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pActionTreeComponent->mPrev = p_m_pActionTreeComponent;
    p_m_pActionTreeComponent->mNext = p_m_pActionTreeComponent;
  }
  p_m_pActionTreeComponent->m_pPointer = 0i64;
  v5 = p_m_pActionTreeComponent->mPrev;
  v6 = p_m_pActionTreeComponent->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_m_pActionTreeComponent->mPrev = p_m_pActionTreeComponent;
  p_m_pActionTreeComponent->mNext = p_m_pActionTreeComponent;
  p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
  if ( this->m_pAIEntityComponent.m_pPointer )
  {
    v8 = p_m_pAIEntityComponent->mPrev;
    v9 = this->m_pAIEntityComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
    this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
  }
  this->m_pAIEntityComponent.m_pPointer = 0i64;
  v10 = p_m_pAIEntityComponent->mPrev;
  v11 = this->m_pAIEntityComponent.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
  this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v12 = this->mPrev;
  v13 = this->mNext;
  v12->mNext = v13;
  v13->mPrev = v12;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 2563
// RVA: 0x3470B0
void __fastcall NodeRequestAndWaitUntilPlayingTask::Begin(
        NodeRequestAndWaitUntilPlayingTask *this,
        ActionContext *action_context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::SimComponent *m_pComponent; // rdi
  UFG::SimComponent *v5; // r8
  __int16 m_Flags; // dx
  UFG::ActiveAIEntityComponent *ComponentOfTypeHK; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pAIEntityComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::SimObjectGame *v12; // rcx
  __int16 v13; // dx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActionTreeComponent> *p_m_pActionTreeComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rax

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
      v5 = ComponentOfTypeHK;
    }
    else
    {
      v5 = 0i64;
    }
    p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
    if ( this->m_pAIEntityComponent.m_pPointer )
    {
      mPrev = p_m_pAIEntityComponent->mPrev;
      mNext = this->m_pAIEntityComponent.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
      this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
    }
    this->m_pAIEntityComponent.m_pPointer = v5;
    if ( v5 )
    {
      v11 = v5->m_SafePointerList.mNode.mPrev;
      v11->mNext = p_m_pAIEntityComponent;
      p_m_pAIEntityComponent->mPrev = v11;
      this->m_pAIEntityComponent.mNext = &v5->m_SafePointerList.mNode;
      v5->m_SafePointerList.mNode.mPrev = p_m_pAIEntityComponent;
    }
    v12 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
    if ( v12 )
    {
      v13 = v12->m_Flags;
      if ( (v13 & 0x4000) != 0 )
      {
        m_pComponent = v12->m_Components.p[7].m_pComponent;
      }
      else if ( v13 >= 0 )
      {
        if ( (v13 & 0x2000) != 0 )
        {
          m_pComponent = v12->m_Components.p[6].m_pComponent;
        }
        else
        {
          if ( (v13 & 0x1000) != 0 )
            ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::ActionTreeComponent::_TypeUID);
          else
            ComponentOfType = UFG::SimObject::GetComponentOfType(v12, UFG::ActionTreeComponent::_TypeUID);
          m_pComponent = ComponentOfType;
        }
      }
      else
      {
        m_pComponent = v12->m_Components.p[7].m_pComponent;
      }
    }
    p_m_pActionTreeComponent = &this->m_pActionTreeComponent;
    if ( this->m_pActionTreeComponent.m_pPointer )
    {
      v16 = p_m_pActionTreeComponent->mPrev;
      v17 = this->m_pActionTreeComponent.mNext;
      v16->mNext = v17;
      v17->mPrev = v16;
      p_m_pActionTreeComponent->mPrev = p_m_pActionTreeComponent;
      this->m_pActionTreeComponent.mNext = &this->m_pActionTreeComponent;
    }
    this->m_pActionTreeComponent.m_pPointer = m_pComponent;
    if ( m_pComponent )
    {
      v18 = m_pComponent->m_SafePointerList.mNode.mPrev;
      v18->mNext = p_m_pActionTreeComponent;
      p_m_pActionTreeComponent->mPrev = v18;
      this->m_pActionTreeComponent.mNext = &m_pComponent->m_SafePointerList.mNode;
      m_pComponent->m_SafePointerList.mNode.mPrev = p_m_pActionTreeComponent;
    }
    this->m_HasStartedNode = 0;
    this->m_TimeBegan = UFG::Metrics::msInstance.mSimTime_Temp;
  }
  else
  {
    this->m_HasStartedNode = 0;
    this->m_TimeBegan = UFG::Metrics::msInstance.mSimTime_Temp;
  }
}

// File Line: 2580
// RVA: 0x391210
bool __fastcall NodeRequestAndWaitUntilPlayingTask::Update(NodeRequestAndWaitUntilPlayingTask *this, float timestep)
{
  ITrack *m_Track; // rdx
  bool result; // al
  float v5; // xmm1_4
  UFG::SimComponent *m_pPointer; // rcx
  bool m_HasStartedNode; // al
  bool v8; // cl
  UFG::SimComponent *v9; // rax
  ITrack *v10; // rdx

  m_Track = this->m_Track;
  result = this->m_HasStartedNode;
  v5 = *(float *)&m_Track[1].mResourceOwner;
  if ( !result )
  {
    if ( v5 >= 0.0 && (float)(UFG::Metrics::msInstance.mSimTime_Temp - this->m_TimeBegan) > v5 )
      return result;
    m_pPointer = this->m_pActionTreeComponent.m_pPointer;
    if ( m_pPointer )
      this->m_HasStartedNode = ActionController::IsPlaying(
                                 (ActionController *)&m_pPointer[3],
                                 (ActionID *)&m_Track[1],
                                 0xFFFFFFFF,
                                 BYTE4(m_Track[1].vfptr) != 0);
  }
  m_HasStartedNode = this->m_HasStartedNode;
  v8 = m_HasStartedNode;
  if ( m_HasStartedNode )
  {
    v9 = this->m_pActionTreeComponent.m_pPointer;
    if ( v9 )
    {
      v10 = this->m_Track;
      if ( !BYTE5(v10[1].vfptr) )
        return 0;
      v8 = ActionController::IsPlaying(
             (ActionController *)&v9[3],
             (ActionID *)&v10[1],
             0xFFFFFFFF,
             BYTE4(v10[1].vfptr) != 0) == 0;
    }
  }
  return !v8;
}

// File Line: 2663
// RVA: 0x331B50
void __fastcall SetCurrentEmotionTask::SetCurrentEmotionTask(SetCurrentEmotionTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pAIEntityComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax

  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<SetCurrentEmotionTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&SetCurrentEmotionTask::`vftable;
  p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.mPrev = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.m_pPointer = 0i64;
  this->m_pActionContext = 0i64;
  if ( this->m_pAIEntityComponent.m_pPointer )
  {
    mPrev = p_m_pAIEntityComponent->mPrev;
    mNext = p_m_pAIEntityComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
    p_m_pAIEntityComponent->mNext = p_m_pAIEntityComponent;
  }
  p_m_pAIEntityComponent->m_pPointer = 0i64;
}

// File Line: 2671
// RVA: 0x33ABA0
void __fastcall SetCurrentEmotionTask::~SetCurrentEmotionTask(SetCurrentEmotionTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pAIEntityComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rcx
  UFG::qNode<ITask,ITask> *v8; // rax

  this->vfptr = (ITaskVtbl *)&SetCurrentEmotionTask::`vftable;
  p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
  if ( this->m_pAIEntityComponent.m_pPointer )
  {
    mPrev = p_m_pAIEntityComponent->mPrev;
    mNext = p_m_pAIEntityComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
    p_m_pAIEntityComponent->mNext = p_m_pAIEntityComponent;
  }
  p_m_pAIEntityComponent->m_pPointer = 0i64;
  v5 = p_m_pAIEntityComponent->mPrev;
  v6 = p_m_pAIEntityComponent->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
  p_m_pAIEntityComponent->mNext = p_m_pAIEntityComponent;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v7 = this->mPrev;
  v8 = this->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 2688
// RVA: 0x392DE0
char __fastcall SetCurrentEmotionTask::Update(SetCurrentEmotionTask *this, float timestep)
{
  UFG::SimComponent *m_pPointer; // rdx

  m_pPointer = this->m_pAIEntityComponent.m_pPointer;
  if ( m_pPointer )
    HIDWORD(m_pPointer[64].m_BoundComponentHandles.mNode.mNext) = LOBYTE(this->m_Track[1].vfptr);
  return 1;
}

// File Line: 2718
// RVA: 0x331CE0
void __fastcall SetFacialEmotionTask::SetFacialEmotionTask(SetFacialEmotionTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pAIEntityComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax

  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<SetFacialEmotionTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&SetFacialEmotionTask::`vftable;
  p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.mPrev = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.m_pPointer = 0i64;
  this->m_pActionContext = 0i64;
  if ( this->m_pAIEntityComponent.m_pPointer )
  {
    mPrev = p_m_pAIEntityComponent->mPrev;
    mNext = p_m_pAIEntityComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
    p_m_pAIEntityComponent->mNext = p_m_pAIEntityComponent;
  }
  p_m_pAIEntityComponent->m_pPointer = 0i64;
}

// File Line: 2726
// RVA: 0x33AD30
void __fastcall SetFacialEmotionTask::~SetFacialEmotionTask(SetFacialEmotionTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pAIEntityComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rcx
  UFG::qNode<ITask,ITask> *v8; // rax

  this->vfptr = (ITaskVtbl *)&SetFacialEmotionTask::`vftable;
  p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
  if ( this->m_pAIEntityComponent.m_pPointer )
  {
    mPrev = p_m_pAIEntityComponent->mPrev;
    mNext = p_m_pAIEntityComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
    p_m_pAIEntityComponent->mNext = p_m_pAIEntityComponent;
  }
  p_m_pAIEntityComponent->m_pPointer = 0i64;
  v5 = p_m_pAIEntityComponent->mPrev;
  v6 = p_m_pAIEntityComponent->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
  p_m_pAIEntityComponent->mNext = p_m_pAIEntityComponent;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v7 = this->mPrev;
  v8 = this->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 2743
// RVA: 0x392E00
char __fastcall SetFacialEmotionTask::Update(SetFacialEmotionTask *this, float timestep)
{
  UFG::SimComponent *m_pPointer; // rdx

  m_pPointer = this->m_pAIEntityComponent.m_pPointer;
  if ( m_pPointer )
    LODWORD(m_pPointer[65].vfptr) = LOBYTE(this->m_Track[1].vfptr);
  return 1;
}

// File Line: 2773
// RVA: 0x3327E0
void __fastcall TurnToFaceTargetTask::TurnToFaceTargetTask(TurnToFaceTargetTask *this)
{
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<TurnToFaceTargetTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&TurnToFaceTargetTask::`vftable;
  this->m_pActionContext = 0i64;
}

// File Line: 2792
// RVA: 0x393680
char __fastcall TurnToFaceTargetTask::Update(TurnToFaceTargetTask *this, float timestep)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::SimComponent *m_pComponent; // r8
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObject *v7; // rcx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbp
  __int64 v9; // rdi
  UFG::SimObjectCVBase *v10; // rcx
  __int16 v11; // dx
  UFG::AICharacterControllerBaseComponent *v12; // rax
  UFG::AICharacterControllerBaseComponent *v13; // rbx
  float v14; // xmm2_4
  __m128 v15; // xmm3
  __m128 v16; // xmm1
  float v17; // xmm1_4
  float mMotionIntentionSpeed; // xmm0_4
  UFG::SimObjectGame *v19; // rcx
  __int16 v20; // dx
  UFG::SimComponent *v21; // r8
  UFG::SimComponent *ComponentOfType; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> **p_mNext; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v24; // rcx
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *vfptr; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v26; // rax

  m_pPointer = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
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
  v7 = this->m_pActionContext->mSimObject.m_pPointer;
  if ( v7 )
    m_pTransformNodeComponent = v7->m_pTransformNodeComponent;
  else
    m_pTransformNodeComponent = 0i64;
  v9 = 0i64;
  if ( m_pComponent )
  {
    v9 = *(_QWORD *)(56i64
                   * *(unsigned __int8 *)(LOBYTE(this->m_Track[1].vfptr) + *(_QWORD *)&m_pComponent[1].m_Flags + 8i64)
                   + *(_QWORD *)&m_pComponent[1].m_TypeUID
                   + 40);
    if ( v9 )
      v9 = *(_QWORD *)(v9 + 88);
  }
  if ( m_pTransformNodeComponent && v9 )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v9);
    if ( !UFG::IsFacingPosition(
            this->m_pActionContext->mSimObject.m_pPointer,
            (UFG::qVector3 *)(v9 + 176),
            (float)(*((float *)&this->m_Track[1].vfptr + 1) * 180.0) * 0.31830987) )
    {
      v10 = (UFG::SimObjectCVBase *)this->m_pActionContext->mSimObject.m_pPointer;
      if ( v10 )
      {
        v11 = v10->m_Flags;
        if ( (v11 & 0x4000) != 0 || v11 < 0 )
          v12 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v10);
        else
          v12 = (UFG::AICharacterControllerBaseComponent *)((v11 & 0x2000) != 0 || (v11 & 0x1000) != 0
                                                          ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                              v10,
                                                              UFG::AICharacterControllerBaseComponent::_TypeUID)
                                                          : UFG::SimObject::GetComponentOfType(
                                                              v10,
                                                              UFG::AICharacterControllerBaseComponent::_TypeUID));
        v13 = v12;
        if ( v12 )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
          v15 = (__m128)*(unsigned int *)(v9 + 180);
          v14 = *(float *)(v9 + 176) - m_pTransformNodeComponent->mWorldTransform.v3.x;
          v15.m128_f32[0] = v15.m128_f32[0] - m_pTransformNodeComponent->mWorldTransform.v3.y;
          v16 = v15;
          v16.m128_f32[0] = (float)(v15.m128_f32[0] * v15.m128_f32[0]) + (float)(v14 * v14);
          if ( v16.m128_f32[0] == 0.0 )
            v17 = 0.0;
          else
            v17 = 1.0 / _mm_sqrt_ps(v16).m128_f32[0];
          mMotionIntentionSpeed = FLOAT_0_0099999998;
          v13->m_Intention.mMotionIntentionDirection.x = v14 * v17;
          v13->m_Intention.mMotionIntentionDirection.y = v15.m128_f32[0] * v17;
          v13->m_Intention.mMotionIntentionDirection.z = v17 * 0.0;
          if ( v13->m_Intention.mMotionIntentionSpeed >= 0.0099999998 )
            mMotionIntentionSpeed = v13->m_Intention.mMotionIntentionSpeed;
          v13->m_Intention.mMotionIntentionSpeed = mMotionIntentionSpeed;
        }
      }
    }
    v19 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
    if ( v19 )
    {
      v20 = v19->m_Flags;
      if ( (v20 & 0x4000) != 0 )
      {
        v21 = v19->m_Components.p[22].m_pComponent;
      }
      else if ( v20 >= 0 )
      {
        if ( (v20 & 0x2000) != 0 || (v20 & 0x1000) != 0 )
          ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v19, UFG::AIEntityComponent::_TypeUID);
        else
          ComponentOfType = UFG::SimObject::GetComponentOfType(v19, UFG::AIEntityComponent::_TypeUID);
        v21 = ComponentOfType;
      }
      else
      {
        v21 = v19->m_Components.p[22].m_pComponent;
      }
      if ( v21 )
      {
        p_mNext = &v21[13].m_BoundComponentHandles.mNode.mNext;
        LODWORD(v21[13].m_pSimObject) = 0;
        if ( v21[14].m_SafePointerList.mNode.mPrev )
        {
          v24 = *p_mNext;
          vfptr = v21[14].vfptr;
          v24->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)vfptr;
          vfptr->__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int))v24;
          *p_mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)p_mNext;
          v21[14].vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&v21[13].m_BoundComponentHandles.mNode.mNext;
        }
        v21[14].m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v9;
        v26 = *(UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> **)(v9 + 8);
        v26->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)p_mNext;
        *p_mNext = v26;
        v21[14].vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)(v9 + 8);
        *(_QWORD *)(v9 + 8) = p_mNext;
        *(UFG::SimObject **)((char *)&v21[13].m_pSimObject + 4) = 0i64;
        HIDWORD(v21[13].m_BoundComponentHandles.mNode.mPrev) = 1070805811;
      }
    }
  }
  return 1;
}

// File Line: 2840
// RVA: 0x3555A0
void __fastcall TurnToFaceTargetTask::End(TurnToFaceTargetTask *this)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax

  m_pPointer = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[22].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::AIEntityComponent::_TypeUID);
      else
        m_pComponent = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::AIEntityComponent::_TypeUID);
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[22].m_pComponent;
    }
    if ( m_pComponent )
      LODWORD(m_pComponent[13].m_pSimObject) = -1;
  }
}

// File Line: 2859
// RVA: 0x32FB00
void __fastcall HeadTrackTargetTask::HeadTrackTargetTask(HeadTrackTargetTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pAIEntityComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax

  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<HeadTrackTargetTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&HeadTrackTargetTask::`vftable;
  p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.mPrev = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.m_pPointer = 0i64;
  this->m_pTransformNodeComponent.mPrev = &this->m_pTransformNodeComponent;
  this->m_pTransformNodeComponent.mNext = &this->m_pTransformNodeComponent;
  this->m_pTransformNodeComponent.m_pPointer = 0i64;
  this->m_pActionTreeComponent.mPrev = &this->m_pActionTreeComponent;
  this->m_pActionTreeComponent.mNext = &this->m_pActionTreeComponent;
  this->m_pActionTreeComponent.m_pPointer = 0i64;
  this->m_pActionContext = 0i64;
  if ( this->m_pAIEntityComponent.m_pPointer )
  {
    mPrev = p_m_pAIEntityComponent->mPrev;
    mNext = p_m_pAIEntityComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
    p_m_pAIEntityComponent->mNext = p_m_pAIEntityComponent;
  }
  p_m_pAIEntityComponent->m_pPointer = 0i64;
}

// File Line: 2867
// RVA: 0x338650
void __fastcall HeadTrackTargetTask::~HeadTrackTargetTask(HeadTrackTargetTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::ActionTreeComponent> *p_m_pActionTreeComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_m_pTransformNodeComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pAIEntityComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qNode<ITask,ITask> *v17; // rcx
  UFG::qNode<ITask,ITask> *v18; // rax

  this->vfptr = (ITaskVtbl *)&HeadTrackTargetTask::`vftable;
  p_m_pActionTreeComponent = &this->m_pActionTreeComponent;
  if ( this->m_pActionTreeComponent.m_pPointer )
  {
    mPrev = p_m_pActionTreeComponent->mPrev;
    mNext = p_m_pActionTreeComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pActionTreeComponent->mPrev = p_m_pActionTreeComponent;
    p_m_pActionTreeComponent->mNext = p_m_pActionTreeComponent;
  }
  p_m_pActionTreeComponent->m_pPointer = 0i64;
  v5 = p_m_pActionTreeComponent->mPrev;
  v6 = p_m_pActionTreeComponent->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_m_pActionTreeComponent->mPrev = p_m_pActionTreeComponent;
  p_m_pActionTreeComponent->mNext = p_m_pActionTreeComponent;
  p_m_pTransformNodeComponent = &this->m_pTransformNodeComponent;
  if ( this->m_pTransformNodeComponent.m_pPointer )
  {
    v8 = p_m_pTransformNodeComponent->mPrev;
    v9 = this->m_pTransformNodeComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    p_m_pTransformNodeComponent->mPrev = p_m_pTransformNodeComponent;
    this->m_pTransformNodeComponent.mNext = &this->m_pTransformNodeComponent;
  }
  this->m_pTransformNodeComponent.m_pPointer = 0i64;
  v10 = p_m_pTransformNodeComponent->mPrev;
  v11 = this->m_pTransformNodeComponent.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  p_m_pTransformNodeComponent->mPrev = p_m_pTransformNodeComponent;
  this->m_pTransformNodeComponent.mNext = &this->m_pTransformNodeComponent;
  p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
  if ( this->m_pAIEntityComponent.m_pPointer )
  {
    v13 = p_m_pAIEntityComponent->mPrev;
    v14 = this->m_pAIEntityComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
    this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
  }
  this->m_pAIEntityComponent.m_pPointer = 0i64;
  v15 = p_m_pAIEntityComponent->mPrev;
  v16 = this->m_pAIEntityComponent.mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
  this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v17 = this->mPrev;
  v18 = this->mNext;
  v17->mNext = v18;
  v18->mPrev = v17;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 2872
// RVA: 0x3462E0
void __fastcall HeadTrackTargetTask::Begin(HeadTrackTargetTask *this, ActionContext *action_context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::SimComponent *m_pComponent; // rbx
  UFG::SimComponent *v5; // r8
  __int16 m_Flags; // dx
  UFG::ActiveAIEntityComponent *ComponentOfTypeHK; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pAIEntityComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::SimObject *v12; // r8
  UFG::SimComponent *m_pTransformNodeComponent; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_m_pTransformNodeComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::SimObjectGame *v18; // rcx
  __int16 v19; // dx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActionTreeComponent> *p_m_pActionTreeComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v22; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v23; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v24; // rax

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
      v5 = ComponentOfTypeHK;
    }
    else
    {
      v5 = 0i64;
    }
    p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
    if ( this->m_pAIEntityComponent.m_pPointer )
    {
      mPrev = p_m_pAIEntityComponent->mPrev;
      mNext = this->m_pAIEntityComponent.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
      this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
    }
    this->m_pAIEntityComponent.m_pPointer = v5;
    if ( v5 )
    {
      v11 = v5->m_SafePointerList.mNode.mPrev;
      v11->mNext = p_m_pAIEntityComponent;
      p_m_pAIEntityComponent->mPrev = v11;
      this->m_pAIEntityComponent.mNext = &v5->m_SafePointerList.mNode;
      v5->m_SafePointerList.mNode.mPrev = p_m_pAIEntityComponent;
    }
    v12 = this->m_pActionContext->mSimObject.m_pPointer;
    if ( v12 )
      m_pTransformNodeComponent = v12->m_pTransformNodeComponent;
    else
      m_pTransformNodeComponent = 0i64;
    p_m_pTransformNodeComponent = &this->m_pTransformNodeComponent;
    if ( this->m_pTransformNodeComponent.m_pPointer )
    {
      v15 = p_m_pTransformNodeComponent->mPrev;
      v16 = this->m_pTransformNodeComponent.mNext;
      v15->mNext = v16;
      v16->mPrev = v15;
      p_m_pTransformNodeComponent->mPrev = p_m_pTransformNodeComponent;
      this->m_pTransformNodeComponent.mNext = &this->m_pTransformNodeComponent;
    }
    this->m_pTransformNodeComponent.m_pPointer = m_pTransformNodeComponent;
    if ( m_pTransformNodeComponent )
    {
      v17 = m_pTransformNodeComponent->m_SafePointerList.mNode.mPrev;
      v17->mNext = p_m_pTransformNodeComponent;
      p_m_pTransformNodeComponent->mPrev = v17;
      this->m_pTransformNodeComponent.mNext = &m_pTransformNodeComponent->m_SafePointerList.mNode;
      m_pTransformNodeComponent->m_SafePointerList.mNode.mPrev = p_m_pTransformNodeComponent;
    }
    v18 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
    if ( v18 )
    {
      v19 = v18->m_Flags;
      if ( (v19 & 0x4000) != 0 )
      {
        m_pComponent = v18->m_Components.p[7].m_pComponent;
      }
      else if ( v19 >= 0 )
      {
        if ( (v19 & 0x2000) != 0 )
        {
          m_pComponent = v18->m_Components.p[6].m_pComponent;
        }
        else
        {
          if ( (v19 & 0x1000) != 0 )
            ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v18, UFG::ActionTreeComponent::_TypeUID);
          else
            ComponentOfType = UFG::SimObject::GetComponentOfType(v18, UFG::ActionTreeComponent::_TypeUID);
          m_pComponent = ComponentOfType;
        }
      }
      else
      {
        m_pComponent = v18->m_Components.p[7].m_pComponent;
      }
    }
    p_m_pActionTreeComponent = &this->m_pActionTreeComponent;
    if ( this->m_pActionTreeComponent.m_pPointer )
    {
      v22 = p_m_pActionTreeComponent->mPrev;
      v23 = this->m_pActionTreeComponent.mNext;
      v22->mNext = v23;
      v23->mPrev = v22;
      p_m_pActionTreeComponent->mPrev = p_m_pActionTreeComponent;
      this->m_pActionTreeComponent.mNext = &this->m_pActionTreeComponent;
    }
    this->m_pActionTreeComponent.m_pPointer = m_pComponent;
    if ( m_pComponent )
    {
      v24 = m_pComponent->m_SafePointerList.mNode.mPrev;
      v24->mNext = p_m_pActionTreeComponent;
      p_m_pActionTreeComponent->mPrev = v24;
      this->m_pActionTreeComponent.mNext = &m_pComponent->m_SafePointerList.mNode;
      m_pComponent->m_SafePointerList.mNode.mPrev = p_m_pActionTreeComponent;
    }
  }
}

// File Line: 2886
// RVA: 0x38FA10
char __fastcall HeadTrackTargetTask::Update(HeadTrackTargetTask *this, float timestep)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::SimComponent *m_pComponent; // r8
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  __int64 v7; // rsi
  UFG::TransformNodeComponent *v8; // rsi
  UFG::SimComponent *v9; // rbp
  UFG::TransformNodeComponent *v10; // rbx
  float v11; // xmm2_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  ITrack *m_Track; // rax
  float v15; // xmm1_4
  float v16; // xmm1_4
  UFG::AIEntityComponent *v17; // rcx
  float v18; // xmm0_4
  UFG::qVector3 v2; // [rsp+20h] [rbp-28h] BYREF
  UFG::qVector3 offset; // [rsp+30h] [rbp-18h] BYREF

  if ( this->m_pAIEntityComponent.m_pPointer )
  {
    m_pPointer = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
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
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                m_pPointer,
                                UFG::TargetingSystemBaseComponent::_TypeUID);
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
    if ( m_pComponent )
    {
      v7 = *(_QWORD *)(56i64
                     * *(unsigned __int8 *)(LOBYTE(this->m_Track[1].vfptr) + *(_QWORD *)&m_pComponent[1].m_Flags + 8i64)
                     + *(_QWORD *)&m_pComponent[1].m_TypeUID
                     + 40);
      if ( v7 )
      {
        v8 = *(UFG::TransformNodeComponent **)(v7 + 88);
        if ( v8 )
        {
          v9 = this->m_pTransformNodeComponent.m_pPointer;
          if ( v9 )
          {
            UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pPointer);
            v10 = (UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pPointer;
            UFG::TransformNodeComponent::UpdateWorldTransform(v10);
            UFG::TransformNodeComponent::UpdateWorldTransform(v8);
            v11 = v8->mWorldTransform.v3.z - v10->mWorldTransform.v3.z;
            v12 = v8->mWorldTransform.v3.y - v10->mWorldTransform.v3.y;
            v2.x = v8->mWorldTransform.v3.x - v10->mWorldTransform.v3.x;
            v2.y = v12;
            v2.z = v11;
            v13 = UFG::qAngleBetween((UFG::qVector3 *)&v9[2], &v2);
            m_Track = this->m_Track;
            v15 = *((float *)&m_Track[1].vfptr + 1);
            if ( this->m_CurrentlyHeadTracking )
              v15 = v15 + 0.17453294;
            if ( COERCE_FLOAT(LODWORD(v13) & _xmm) < v15 )
            {
              v16 = *((float *)&m_Track[1].mResourceOwner + 1);
              v17 = (UFG::AIEntityComponent *)this->m_pAIEntityComponent.m_pPointer;
              offset.x = *(float *)&m_Track[1].mResourceOwner;
              v18 = *(float *)&m_Track[1].m_TrackClassNameUID;
              offset.y = v16;
              offset.z = v18;
              UFG::AIEntityComponent::SetHeadTrackingPosition(v17, v8, &offset);
              this->m_CurrentlyHeadTracking = 1;
              return 1;
            }
          }
        }
      }
    }
    LODWORD(this->m_pAIEntityComponent.m_pPointer[13].m_pSimObject) = -1;
    this->m_CurrentlyHeadTracking = 0;
  }
  return 1;
}

// File Line: 2944
// RVA: 0x3550C0
void __fastcall HeadTrackTargetTask::End(HeadTrackTargetTask *this)
{
  UFG::SimComponent *m_pPointer; // rax

  m_pPointer = this->m_pAIEntityComponent.m_pPointer;
  if ( m_pPointer )
    LODWORD(m_pPointer[13].m_pSimObject) = -1;
}

// File Line: 2960
// RVA: 0x32DB40
void __fastcall DebugDrawMyPositionTask::DebugDrawMyPositionTask(DebugDrawMyPositionTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_m_pTransformNodeComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax

  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<DebugDrawMyPositionTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&DebugDrawMyPositionTask::`vftable;
  p_m_pTransformNodeComponent = &this->m_pTransformNodeComponent;
  this->m_pTransformNodeComponent.mPrev = &this->m_pTransformNodeComponent;
  this->m_pTransformNodeComponent.mNext = &this->m_pTransformNodeComponent;
  this->m_pTransformNodeComponent.m_pPointer = 0i64;
  this->m_pActionContext = 0i64;
  if ( this->m_pTransformNodeComponent.m_pPointer )
  {
    mPrev = p_m_pTransformNodeComponent->mPrev;
    mNext = p_m_pTransformNodeComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pTransformNodeComponent->mPrev = p_m_pTransformNodeComponent;
    p_m_pTransformNodeComponent->mNext = p_m_pTransformNodeComponent;
  }
  p_m_pTransformNodeComponent->m_pPointer = 0i64;
}

// File Line: 2968
// RVA: 0x336040
void __fastcall DebugDrawMyPositionTask::~DebugDrawMyPositionTask(DebugDrawMyPositionTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_m_pTransformNodeComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rcx
  UFG::qNode<ITask,ITask> *v8; // rax

  this->vfptr = (ITaskVtbl *)&DebugDrawMyPositionTask::`vftable;
  p_m_pTransformNodeComponent = &this->m_pTransformNodeComponent;
  if ( this->m_pTransformNodeComponent.m_pPointer )
  {
    mPrev = p_m_pTransformNodeComponent->mPrev;
    mNext = p_m_pTransformNodeComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pTransformNodeComponent->mPrev = p_m_pTransformNodeComponent;
    p_m_pTransformNodeComponent->mNext = p_m_pTransformNodeComponent;
  }
  p_m_pTransformNodeComponent->m_pPointer = 0i64;
  v5 = p_m_pTransformNodeComponent->mPrev;
  v6 = p_m_pTransformNodeComponent->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_m_pTransformNodeComponent->mPrev = p_m_pTransformNodeComponent;
  p_m_pTransformNodeComponent->mNext = p_m_pTransformNodeComponent;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v7 = this->mPrev;
  v8 = this->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 2973
// RVA: 0x3444A0
void __fastcall DebugDrawMyPositionTask::Begin(DebugDrawMyPositionTask *this, ActionContext *action_context)
{
  UFG::SimObject *m_pPointer; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_m_pTransformNodeComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax

  this->m_pActionContext = action_context;
  if ( action_context )
  {
    m_pPointer = action_context->mSimObject.m_pPointer;
    if ( m_pPointer )
      m_pPointer = (UFG::SimObject *)m_pPointer->m_pTransformNodeComponent;
    p_m_pTransformNodeComponent = &this->m_pTransformNodeComponent;
    if ( this->m_pTransformNodeComponent.m_pPointer )
    {
      mPrev = p_m_pTransformNodeComponent->mPrev;
      mNext = p_m_pTransformNodeComponent->mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_m_pTransformNodeComponent->mPrev = p_m_pTransformNodeComponent;
      p_m_pTransformNodeComponent->mNext = p_m_pTransformNodeComponent;
    }
    p_m_pTransformNodeComponent->m_pPointer = (UFG::SimComponent *)m_pPointer;
    if ( m_pPointer )
    {
      v6 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)m_pPointer->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
      v6->mNext = p_m_pTransformNodeComponent;
      p_m_pTransformNodeComponent->mPrev = v6;
      p_m_pTransformNodeComponent->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&m_pPointer->m_SafePointerList;
      m_pPointer->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)p_m_pTransformNodeComponent;
    }
  }
}

// File Line: 2985
// RVA: 0x38E120
char __fastcall DebugDrawMyPositionTask::Update(DebugDrawMyPositionTask *this, float timestep)
{
  ITrack *m_Track; // rax
  UFG::SimComponent *m_pPointer; // rbx
  UFG::TransformNodeComponent *v4; // rcx
  float v5; // xmm1_4
  float v6; // xmm0_4
  Render::DebugDrawContext *Context; // rax
  UFG::qVector3 point; // [rsp+30h] [rbp-28h] BYREF
  UFG::qColour colour; // [rsp+40h] [rbp-18h] BYREF

  m_Track = this->m_Track;
  if ( !LOBYTE(m_Track[1].m_TrackClassNameUID) )
    return 1;
  m_pPointer = this->m_pTransformNodeComponent.m_pPointer;
  if ( m_pPointer )
  {
    v4 = (UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pPointer;
    colour = (UFG::qColour)m_Track[1].Expression::IMemberMap;
    UFG::TransformNodeComponent::UpdateWorldTransform(v4);
    v5 = *((float *)&m_pPointer[2].m_BoundComponentHandles.mNode.mPrev + 1);
    point.x = *(float *)&m_pPointer[2].m_BoundComponentHandles.mNode.mPrev;
    v6 = *(float *)&m_pPointer[2].m_BoundComponentHandles.mNode.mNext;
    point.y = v5;
    point.z = v6 + 0.25;
    Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
    Render::DebugDrawContext::DrawPoint(Context, &point, &colour, &UFG::qMatrix44::msIdentity, 0i64);
  }
  return 1;
}

// File Line: 3012
// RVA: 0x32DBC0
void __fastcall DebugDrawMyTargetTask::DebugDrawMyTargetTask(DebugDrawMyTargetTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *p_m_pTargetingSystemBaseComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax

  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<DebugDrawMyTargetTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&DebugDrawMyTargetTask::`vftable;
  this->m_pTransformNodeComponent.mPrev = &this->m_pTransformNodeComponent;
  this->m_pTransformNodeComponent.mNext = &this->m_pTransformNodeComponent;
  this->m_pTransformNodeComponent.m_pPointer = 0i64;
  p_m_pTargetingSystemBaseComponent = &this->m_pTargetingSystemBaseComponent;
  this->m_pTargetingSystemBaseComponent.mPrev = &this->m_pTargetingSystemBaseComponent;
  this->m_pTargetingSystemBaseComponent.mNext = &this->m_pTargetingSystemBaseComponent;
  this->m_pTargetingSystemBaseComponent.m_pPointer = 0i64;
  this->m_pActionContext = 0i64;
  if ( this->m_pTargetingSystemBaseComponent.m_pPointer )
  {
    mPrev = p_m_pTargetingSystemBaseComponent->mPrev;
    mNext = p_m_pTargetingSystemBaseComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pTargetingSystemBaseComponent->mPrev = p_m_pTargetingSystemBaseComponent;
    p_m_pTargetingSystemBaseComponent->mNext = p_m_pTargetingSystemBaseComponent;
  }
  p_m_pTargetingSystemBaseComponent->m_pPointer = 0i64;
}

// File Line: 3020
// RVA: 0x336140
void __fastcall DebugDrawMyTargetTask::~DebugDrawMyTargetTask(DebugDrawMyTargetTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *p_m_pTargetingSystemBaseComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_m_pTransformNodeComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<ITask,ITask> *v12; // rcx
  UFG::qNode<ITask,ITask> *v13; // rax

  this->vfptr = (ITaskVtbl *)&DebugDrawMyTargetTask::`vftable;
  p_m_pTargetingSystemBaseComponent = &this->m_pTargetingSystemBaseComponent;
  if ( this->m_pTargetingSystemBaseComponent.m_pPointer )
  {
    mPrev = p_m_pTargetingSystemBaseComponent->mPrev;
    mNext = p_m_pTargetingSystemBaseComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pTargetingSystemBaseComponent->mPrev = p_m_pTargetingSystemBaseComponent;
    p_m_pTargetingSystemBaseComponent->mNext = p_m_pTargetingSystemBaseComponent;
  }
  p_m_pTargetingSystemBaseComponent->m_pPointer = 0i64;
  v5 = p_m_pTargetingSystemBaseComponent->mPrev;
  v6 = p_m_pTargetingSystemBaseComponent->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_m_pTargetingSystemBaseComponent->mPrev = p_m_pTargetingSystemBaseComponent;
  p_m_pTargetingSystemBaseComponent->mNext = p_m_pTargetingSystemBaseComponent;
  p_m_pTransformNodeComponent = &this->m_pTransformNodeComponent;
  if ( this->m_pTransformNodeComponent.m_pPointer )
  {
    v8 = p_m_pTransformNodeComponent->mPrev;
    v9 = this->m_pTransformNodeComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    p_m_pTransformNodeComponent->mPrev = p_m_pTransformNodeComponent;
    this->m_pTransformNodeComponent.mNext = &this->m_pTransformNodeComponent;
  }
  this->m_pTransformNodeComponent.m_pPointer = 0i64;
  v10 = p_m_pTransformNodeComponent->mPrev;
  v11 = this->m_pTransformNodeComponent.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  p_m_pTransformNodeComponent->mPrev = p_m_pTransformNodeComponent;
  this->m_pTransformNodeComponent.mNext = &this->m_pTransformNodeComponent;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v12 = this->mPrev;
  v13 = this->mNext;
  v12->mNext = v13;
  v13->mPrev = v12;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 3025
// RVA: 0x344500
void __fastcall DebugDrawMyTargetTask::Begin(DebugDrawMyTargetTask *this, ActionContext *action_context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::SimComponent *m_pTransformNodeComponent; // rbx
  UFG::SimComponent *m_pComponent; // r8
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *p_m_pTargetingSystemBaseComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::SimObject *v12; // rcx
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_m_pTransformNodeComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax

  this->m_pActionContext = action_context;
  if ( action_context )
  {
    m_pPointer = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
    m_pTransformNodeComponent = 0i64;
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
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                m_pPointer,
                                UFG::TargetingSystemBaseComponent::_TypeUID);
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
    p_m_pTargetingSystemBaseComponent = &this->m_pTargetingSystemBaseComponent;
    if ( this->m_pTargetingSystemBaseComponent.m_pPointer )
    {
      mPrev = p_m_pTargetingSystemBaseComponent->mPrev;
      mNext = this->m_pTargetingSystemBaseComponent.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_m_pTargetingSystemBaseComponent->mPrev = p_m_pTargetingSystemBaseComponent;
      this->m_pTargetingSystemBaseComponent.mNext = &this->m_pTargetingSystemBaseComponent;
    }
    this->m_pTargetingSystemBaseComponent.m_pPointer = m_pComponent;
    if ( m_pComponent )
    {
      v11 = m_pComponent->m_SafePointerList.mNode.mPrev;
      v11->mNext = p_m_pTargetingSystemBaseComponent;
      p_m_pTargetingSystemBaseComponent->mPrev = v11;
      this->m_pTargetingSystemBaseComponent.mNext = &m_pComponent->m_SafePointerList.mNode;
      m_pComponent->m_SafePointerList.mNode.mPrev = p_m_pTargetingSystemBaseComponent;
    }
    v12 = this->m_pActionContext->mSimObject.m_pPointer;
    if ( v12 )
      m_pTransformNodeComponent = v12->m_pTransformNodeComponent;
    p_m_pTransformNodeComponent = &this->m_pTransformNodeComponent;
    if ( this->m_pTransformNodeComponent.m_pPointer )
    {
      v14 = p_m_pTransformNodeComponent->mPrev;
      v15 = this->m_pTransformNodeComponent.mNext;
      v14->mNext = v15;
      v15->mPrev = v14;
      p_m_pTransformNodeComponent->mPrev = p_m_pTransformNodeComponent;
      this->m_pTransformNodeComponent.mNext = &this->m_pTransformNodeComponent;
    }
    this->m_pTransformNodeComponent.m_pPointer = m_pTransformNodeComponent;
    if ( m_pTransformNodeComponent )
    {
      v16 = m_pTransformNodeComponent->m_SafePointerList.mNode.mPrev;
      v16->mNext = p_m_pTransformNodeComponent;
      p_m_pTransformNodeComponent->mPrev = v16;
      this->m_pTransformNodeComponent.mNext = &m_pTransformNodeComponent->m_SafePointerList.mNode;
      m_pTransformNodeComponent->m_SafePointerList.mNode.mPrev = p_m_pTransformNodeComponent;
    }
  }
}

// File Line: 3038
// RVA: 0x38E1D0
char __fastcall DebugDrawMyTargetTask::Update(DebugDrawMyTargetTask *this, float timestep)
{
  ITrack *m_Track; // rcx
  UFG::SimComponent *m_pPointer; // r9
  __int64 v5; // rdi
  UFG::TransformNodeComponent *v6; // rdi
  UFG::qColour v7; // xmm0
  UFG::TransformNodeComponent *v8; // rcx
  float y; // xmm1_4
  Render::DebugDrawContext *Context; // rax
  UFG::qColour v12; // [rsp+30h] [rbp-28h] BYREF
  UFG::qColour colour; // [rsp+40h] [rbp-18h] BYREF

  m_Track = this->m_Track;
  if ( !m_Track[1].mBreakPoint )
    return 1;
  m_pPointer = this->m_pTargetingSystemBaseComponent.m_pPointer;
  if ( !m_pPointer )
    return 1;
  v5 = *(_QWORD *)(56i64 * *(unsigned __int8 *)(LOBYTE(m_Track[1].vfptr) + *(_QWORD *)&m_pPointer[1].m_Flags + 8i64)
                 + *(_QWORD *)&m_pPointer[1].m_TypeUID
                 + 40);
  if ( v5 )
  {
    v6 = *(UFG::TransformNodeComponent **)(v5 + 88);
    if ( v6 )
    {
      v7 = *(UFG::qColour *)((char *)&m_Track[1].Expression::IMemberMap + 4);
      v8 = (UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pPointer;
      v12 = v7;
      UFG::DrawLine(v8, v6, &v12, 0.25);
      colour = *(UFG::qColour *)((char *)&this->m_Track[1].Expression::IMemberMap + 4);
      UFG::TransformNodeComponent::UpdateWorldTransform(v6);
      y = v6->mWorldTransform.v3.y;
      v12.r = v6->mWorldTransform.v3.x;
      v7.r = v6->mWorldTransform.v3.z;
      v12.g = y;
      v12.b = v7.r + 0.25;
      Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(
                                              Render::DebugDrawManager::mInstance,
                                              1u);
      Render::DebugDrawContext::DrawPoint(Context, (UFG::qVector3 *)&v12, &colour, &UFG::qMatrix44::msIdentity, 0i64);
    }
  }
  return 1;
}

// File Line: 3077
// RVA: 0x330530
void __fastcall MinimumDurationTask::MinimumDurationTask(MinimumDurationTask *this)
{
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<MinimumDurationTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&MinimumDurationTask::`vftable;
  this->m_TimeToEnd = 0.0;
}

// File Line: 3087
// RVA: 0x346CE0
void __fastcall MinimumDurationTask::Begin(MinimumDurationTask *this, ActionContext *action_context)
{
  float v3; // xmm7_4
  float v4; // xmm6_4
  float v5; // xmm0_4
  float v6; // xmm7_4
  float v7; // xmm6_4
  float mSimTime_Temp; // xmm8_4
  float v9; // xmm0_4

  v3 = ExpressionParameterFloat::operator float((ExpressionParameterFloat *)&this->m_Track[1]);
  v4 = ExpressionParameterFloat::operator float(&this->m_Track[1].mMasterRate);
  v5 = ExpressionParameterFloat::operator float((ExpressionParameterFloat *)&this->m_Track[1].mTimeBegin);
  v6 = v3 * v5;
  v7 = v4 * v5;
  if ( v6 < 0.0 || v7 < 0.0 )
  {
    this->m_TimeToEnd = -1.0;
  }
  else
  {
    mSimTime_Temp = UFG::Metrics::msInstance.mSimTime_Temp;
    v9 = v7;
    if ( v7 > v6 )
    {
      v9 = UFG::qRandom(v7 - v6, (unsigned int *)&UFG::qDefaultSeed) + v6;
      if ( v9 <= v6 )
        v9 = v6;
      if ( v9 >= v7 )
        v9 = v7;
    }
    this->m_TimeToEnd = v9 + mSimTime_Temp;
  }
}

// File Line: 3111
// RVA: 0x390A20
bool __fastcall MinimumDurationTask::Update(MinimumDurationTask *this, float timestep)
{
  float m_TimeToEnd; // xmm1_4

  m_TimeToEnd = this->m_TimeToEnd;
  return m_TimeToEnd < 0.0 || UFG::Metrics::msInstance.mSimTime_Temp < m_TimeToEnd;
}

// File Line: 3153
// RVA: 0x3317D0
void __fastcall RunLaterallyFromTargetTask::RunLaterallyFromTargetTask(RunLaterallyFromTargetTask *this)
{
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<RunLaterallyFromTargetTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&RunLaterallyFromTargetTask::`vftable;
  this->m_pAIEntityComponent.mPrev = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.m_pPointer = 0i64;
  this->m_pStimulusReceiverComponent.mPrev = &this->m_pStimulusReceiverComponent;
  this->m_pStimulusReceiverComponent.mNext = &this->m_pStimulusReceiverComponent;
  this->m_pStimulusReceiverComponent.m_pPointer = 0i64;
  this->m_pTargetingSystemBaseComponent.mPrev = &this->m_pTargetingSystemBaseComponent;
  this->m_pTargetingSystemBaseComponent.mNext = &this->m_pTargetingSystemBaseComponent;
  this->m_pTargetingSystemBaseComponent.m_pPointer = 0i64;
  this->m_LastTimeReceivedStimulus = -99999.0;
  this->m_SideToRunTo = eSIDE_NONE;
  this->m_TimeToImpactToDive = -99999.0;
  if ( !initted_1 )
  {
    RunLaterallyFromTargetTask::s_SideToRunToHysteresis.nData = 2;
    RunLaterallyFromTargetTask::s_SideToRunToHysteresis.fDomain = RunLaterallyFromTargetTask::s_SideToRunToHysteresisDistanceAway;
    RunLaterallyFromTargetTask::s_SideToRunToHysteresis.tRange = RunLaterallyFromTargetTask::s_SideToRunToHysteresisMagnitude;
    initted_1 = 1;
  }
}

// File Line: 3173
// RVA: 0x33A7C0
void __fastcall RunLaterallyFromTargetTask::~RunLaterallyFromTargetTask(RunLaterallyFromTargetTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *p_m_pTargetingSystemBaseComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::StimulusReceiverComponent> *p_m_pStimulusReceiverComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pAIEntityComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qNode<ITask,ITask> *v17; // rcx
  UFG::qNode<ITask,ITask> *v18; // rax

  this->vfptr = (ITaskVtbl *)&RunLaterallyFromTargetTask::`vftable;
  p_m_pTargetingSystemBaseComponent = &this->m_pTargetingSystemBaseComponent;
  if ( this->m_pTargetingSystemBaseComponent.m_pPointer )
  {
    mPrev = p_m_pTargetingSystemBaseComponent->mPrev;
    mNext = p_m_pTargetingSystemBaseComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pTargetingSystemBaseComponent->mPrev = p_m_pTargetingSystemBaseComponent;
    p_m_pTargetingSystemBaseComponent->mNext = p_m_pTargetingSystemBaseComponent;
  }
  p_m_pTargetingSystemBaseComponent->m_pPointer = 0i64;
  v5 = p_m_pTargetingSystemBaseComponent->mPrev;
  v6 = p_m_pTargetingSystemBaseComponent->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_m_pTargetingSystemBaseComponent->mPrev = p_m_pTargetingSystemBaseComponent;
  p_m_pTargetingSystemBaseComponent->mNext = p_m_pTargetingSystemBaseComponent;
  p_m_pStimulusReceiverComponent = &this->m_pStimulusReceiverComponent;
  if ( this->m_pStimulusReceiverComponent.m_pPointer )
  {
    v8 = p_m_pStimulusReceiverComponent->mPrev;
    v9 = this->m_pStimulusReceiverComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    p_m_pStimulusReceiverComponent->mPrev = p_m_pStimulusReceiverComponent;
    this->m_pStimulusReceiverComponent.mNext = &this->m_pStimulusReceiverComponent;
  }
  this->m_pStimulusReceiverComponent.m_pPointer = 0i64;
  v10 = p_m_pStimulusReceiverComponent->mPrev;
  v11 = this->m_pStimulusReceiverComponent.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  p_m_pStimulusReceiverComponent->mPrev = p_m_pStimulusReceiverComponent;
  this->m_pStimulusReceiverComponent.mNext = &this->m_pStimulusReceiverComponent;
  p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
  if ( this->m_pAIEntityComponent.m_pPointer )
  {
    v13 = p_m_pAIEntityComponent->mPrev;
    v14 = this->m_pAIEntityComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
    this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
  }
  this->m_pAIEntityComponent.m_pPointer = 0i64;
  v15 = p_m_pAIEntityComponent->mPrev;
  v16 = this->m_pAIEntityComponent.mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
  this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v17 = this->mPrev;
  v18 = this->mNext;
  v17->mNext = v18;
  v18->mPrev = v17;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 3178
// RVA: 0x348310
void __fastcall RunLaterallyFromTargetTask::Begin(RunLaterallyFromTargetTask *this, ActionContext *action_context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::SimComponent *v4; // r8
  __int16 m_Flags; // dx
  UFG::ActiveAIEntityComponent *ComponentOfTypeHK; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pAIEntityComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::SimObjectGame *v11; // rcx
  UFG::SimComponent *m_pComponent; // r8
  __int16 v13; // dx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::StimulusReceiverComponent> *p_m_pStimulusReceiverComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rax
  UFG::SimObjectGame *v19; // rcx
  UFG::SimComponent *v20; // r8
  __int16 v21; // dx
  UFG::SimComponent *v22; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *p_m_pTargetingSystemBaseComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v24; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v25; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v26; // rax
  ITrack *m_Track; // rax
  float v28; // xmm6_4
  float v29; // xmm7_4
  float v30; // xmm0_4

  this->m_pActionContext = action_context;
  if ( action_context )
  {
    m_pPointer = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
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
      v4 = ComponentOfTypeHK;
    }
    else
    {
      v4 = 0i64;
    }
    p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
    if ( this->m_pAIEntityComponent.m_pPointer )
    {
      mPrev = p_m_pAIEntityComponent->mPrev;
      mNext = this->m_pAIEntityComponent.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
      this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
    }
    this->m_pAIEntityComponent.m_pPointer = v4;
    if ( v4 )
    {
      v10 = v4->m_SafePointerList.mNode.mPrev;
      v10->mNext = p_m_pAIEntityComponent;
      p_m_pAIEntityComponent->mPrev = v10;
      this->m_pAIEntityComponent.mNext = &v4->m_SafePointerList.mNode;
      v4->m_SafePointerList.mNode.mPrev = p_m_pAIEntityComponent;
    }
    v11 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
    if ( v11 )
    {
      v13 = v11->m_Flags;
      if ( (v13 & 0x4000) != 0 )
      {
        m_pComponent = v11->m_Components.p[11].m_pComponent;
      }
      else if ( v13 >= 0 )
      {
        if ( (v13 & 0x2000) != 0 || (v13 & 0x1000) != 0 )
          ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::StimulusReceiverComponent::_TypeUID);
        else
          ComponentOfType = UFG::SimObject::GetComponentOfType(v11, UFG::StimulusReceiverComponent::_TypeUID);
        m_pComponent = ComponentOfType;
      }
      else
      {
        m_pComponent = v11->m_Components.p[11].m_pComponent;
      }
    }
    else
    {
      m_pComponent = 0i64;
    }
    p_m_pStimulusReceiverComponent = &this->m_pStimulusReceiverComponent;
    if ( this->m_pStimulusReceiverComponent.m_pPointer )
    {
      v16 = p_m_pStimulusReceiverComponent->mPrev;
      v17 = this->m_pStimulusReceiverComponent.mNext;
      v16->mNext = v17;
      v17->mPrev = v16;
      p_m_pStimulusReceiverComponent->mPrev = p_m_pStimulusReceiverComponent;
      this->m_pStimulusReceiverComponent.mNext = &this->m_pStimulusReceiverComponent;
    }
    this->m_pStimulusReceiverComponent.m_pPointer = m_pComponent;
    if ( m_pComponent )
    {
      v18 = m_pComponent->m_SafePointerList.mNode.mPrev;
      v18->mNext = p_m_pStimulusReceiverComponent;
      p_m_pStimulusReceiverComponent->mPrev = v18;
      this->m_pStimulusReceiverComponent.mNext = &m_pComponent->m_SafePointerList.mNode;
      m_pComponent->m_SafePointerList.mNode.mPrev = p_m_pStimulusReceiverComponent;
    }
    v19 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
    if ( v19 )
    {
      v21 = v19->m_Flags;
      if ( (v21 & 0x4000) != 0 )
      {
        v20 = v19->m_Components.p[20].m_pComponent;
      }
      else if ( v21 >= 0 )
      {
        if ( (v21 & 0x2000) != 0 || (v21 & 0x1000) != 0 )
          v22 = UFG::SimObjectGame::GetComponentOfTypeHK(v19, UFG::TargetingSystemBaseComponent::_TypeUID);
        else
          v22 = UFG::SimObject::GetComponentOfType(v19, UFG::TargetingSystemBaseComponent::_TypeUID);
        v20 = v22;
      }
      else
      {
        v20 = v19->m_Components.p[20].m_pComponent;
      }
    }
    else
    {
      v20 = 0i64;
    }
    p_m_pTargetingSystemBaseComponent = &this->m_pTargetingSystemBaseComponent;
    if ( this->m_pTargetingSystemBaseComponent.m_pPointer )
    {
      v24 = p_m_pTargetingSystemBaseComponent->mPrev;
      v25 = this->m_pTargetingSystemBaseComponent.mNext;
      v24->mNext = v25;
      v25->mPrev = v24;
      p_m_pTargetingSystemBaseComponent->mPrev = p_m_pTargetingSystemBaseComponent;
      this->m_pTargetingSystemBaseComponent.mNext = &this->m_pTargetingSystemBaseComponent;
    }
    this->m_pTargetingSystemBaseComponent.m_pPointer = v20;
    if ( v20 )
    {
      v26 = v20->m_SafePointerList.mNode.mPrev;
      v26->mNext = p_m_pTargetingSystemBaseComponent;
      p_m_pTargetingSystemBaseComponent->mPrev = v26;
      this->m_pTargetingSystemBaseComponent.mNext = &v20->m_SafePointerList.mNode;
      v20->m_SafePointerList.mNode.mPrev = p_m_pTargetingSystemBaseComponent;
    }
  }
  m_Track = this->m_Track;
  this->m_SideToRunTo = eSIDE_NONE;
  this->m_NextTimeCanSetSideToRunTo = -99999.0;
  v28 = *(float *)&m_Track[1].mResourceOwner;
  v29 = *((float *)&m_Track[1].mResourceOwner + 1);
  if ( v28 <= v29 )
    goto LABEL_51;
  v30 = UFG::qRandom(v28 - v29, (unsigned int *)&UFG::qDefaultSeed) + v29;
  if ( v30 <= v29 )
    v30 = v29;
  if ( v30 >= v28 )
LABEL_51:
    this->m_TimeToImpactToDive = v28;
  else
    this->m_TimeToImpactToDive = v30;
}

// File Line: 3250
// RVA: 0x392140
char __fastcall RunLaterallyFromTargetTask::Update(RunLaterallyFromTargetTask *this, float timestep)
{
  UFG::SimComponent *m_pPointer; // rsi
  UFG::SimComponent *v4; // r8
  UFG::TransformNodeComponent *v5; // rsi
  __int64 v6; // rdi
  __int64 v7; // rdi
  __m128 v8; // xmm5
  float v9; // xmm7_4
  float v10; // xmm8_4
  __m128 v11; // xmm2
  float v12; // xmm12_4
  float v13; // xmm13_4
  float v14; // xmm14_4
  __m128 v15; // xmm2
  __m128 v16; // xmm3
  float v17; // xmm9_4
  float v18; // xmm3_4
  float v19; // xmm2_4
  float x; // xmm9_4
  __m128 y_low; // xmm4
  float z; // xmm3_4
  __m128 v23; // xmm11
  __m128 v24; // xmm1
  float v25; // xmm10_4
  float v26; // xmm7_4
  float v27; // xmm8_4
  UFG::eLeftOrRightSide m_SideToRunTo; // r14d
  UFG::NavComponent *m_pComponent; // rdi
  __m128 v30; // xmm2
  float v31; // xmm9_4
  float Value; // xmm0_4
  UFG::eLeftOrRightSide v33; // eax
  ITrack *m_Track; // rax
  float v35; // xmm1_4
  float v36; // xmm8_4
  float v37; // xmm10_4
  float v38; // xmm11_4
  unsigned int v39; // xmm1_4
  int v40; // r15d
  UFG::SimObject *m_pSimObject; // rcx
  UFG::SimComponent *ComponentOfType; // rdx
  __int64 v43; // rcx
  bool v44; // al
  bool v45; // r14
  UFG::SimComponent *v46; // rax
  unsigned int v47; // xmm11_4
  unsigned int v48; // xmm8_4
  UFG::SimObject *v49; // rcx
  UFG::SimComponent *v50; // rdx
  __int64 v51; // rcx
  UFG::eLeftOrRightSide v52; // ecx
  ITrack *v53; // rax
  __m128 v54; // xmm1
  int v55; // xmm12_4
  int v56; // xmm13_4
  int v57; // xmm14_4
  UFG::SimObjectCVBase *v58; // rcx
  __int16 m_Flags; // dx
  UFG::AICharacterControllerBaseComponent *ComponentOfTypeHK; // rax
  float *p_mMotionIntentionSpeedRaw; // rdi
  float v62; // xmm2_4
  float v63; // xmm6_4
  float v64; // xmm7_4
  UFG::SimObjectGame *v65; // rcx
  __int16 v66; // dx
  UFG::SimComponent *v67; // rax
  UFG::SimObjectCVBase *v68; // rcx
  __int16 v69; // dx
  UFG::AICharacterControllerBaseComponent *v70; // rax
  float v72; // [rsp+30h] [rbp-D0h] BYREF
  unsigned __int64 v73; // [rsp+34h] [rbp-CCh]
  float v74; // [rsp+40h] [rbp-C0h] BYREF
  unsigned __int64 v75; // [rsp+44h] [rbp-BCh]
  UFG::qVector3 v76; // [rsp+50h] [rbp-B0h] BYREF
  float v77; // [rsp+60h] [rbp-A0h]
  UFG::HavokNavPosition npDestination; // [rsp+70h] [rbp-90h] BYREF
  char v79[16]; // [rsp+B0h] [rbp-50h] BYREF
  __int64 v80; // [rsp+190h] [rbp+90h] BYREF
  float v81; // [rsp+1A0h] [rbp+A0h]
  float v82; // [rsp+1A8h] [rbp+A8h]

  m_pPointer = this->m_pAIEntityComponent.m_pPointer;
  if ( m_pPointer )
  {
    v4 = this->m_pTargetingSystemBaseComponent.m_pPointer;
    if ( v4 )
    {
      if ( this->m_pStimulusReceiverComponent.m_pPointer )
      {
        v5 = *(UFG::TransformNodeComponent **)&m_pPointer[1].m_TypeUID;
        if ( v5 )
        {
          v6 = *(_QWORD *)(56i64
                         * *(unsigned __int8 *)(LOBYTE(this->m_Track[1].mMasterRate.text.mOffset)
                                              + *(_QWORD *)&v4[1].m_Flags
                                              + 8i64)
                         + *(_QWORD *)&v4[1].m_TypeUID
                         + 40);
          if ( v6 )
          {
            v7 = *(_QWORD *)(v6 + 88);
            if ( v7 )
            {
              UFG::TransformNodeComponent::UpdateWorldTransform(v5);
              UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v7);
              UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v7);
              v8 = (__m128)*(unsigned int *)(v7 + 256);
              v9 = *(float *)(v7 + 260);
              v10 = *(float *)(v7 + 264);
              v11 = v8;
              v11.m128_f32[0] = (float)((float)(v8.m128_f32[0] * v8.m128_f32[0]) + (float)(v9 * v9))
                              + (float)(v10 * v10);
              v77 = _mm_sqrt_ps(v11).m128_f32[0];
              if ( v77 < 1.0 )
              {
                UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v7);
                v8 = (__m128)*(unsigned int *)(v7 + 128);
                v9 = *(float *)(v7 + 132);
                v10 = *(float *)(v7 + 136);
              }
              v15 = v8;
              v12 = v5->mWorldTransform.v3.x - *(float *)(v7 + 176);
              v13 = v5->mWorldTransform.v3.y - *(float *)(v7 + 180);
              v14 = v5->mWorldTransform.v3.z - *(float *)(v7 + 184);
              v15.m128_f32[0] = (float)((float)(v8.m128_f32[0] * v8.m128_f32[0]) + (float)(v9 * v9))
                              + (float)(v10 * v10);
              if ( v15.m128_f32[0] <= 0.001 )
              {
                x = UFG::qVector3::msZero.x;
                y_low = (__m128)LODWORD(UFG::qVector3::msZero.y);
                z = UFG::qVector3::msZero.z;
              }
              else
              {
                if ( v15.m128_f32[0] == 0.0 )
                {
                  v16 = 0i64;
                }
                else
                {
                  v16 = (__m128)(unsigned int)FLOAT_1_0;
                  v16.m128_f32[0] = 1.0 / _mm_sqrt_ps(v15).m128_f32[0];
                }
                y_low = v16;
                v17 = v8.m128_f32[0] * v16.m128_f32[0];
                y_low.m128_f32[0] = v16.m128_f32[0] * v9;
                v18 = v16.m128_f32[0] * v10;
                v19 = (float)((float)(y_low.m128_f32[0] * v13) + (float)(v17 * v12)) + (float)(v18 * v14);
                x = v17 * v19;
                y_low.m128_f32[0] = y_low.m128_f32[0] * v19;
                z = v18 * v19;
              }
              v23 = v8;
              v82 = v12 - x;
              *(float *)&v80 = v13 - y_low.m128_f32[0];
              v81 = v14 - z;
              v23.m128_f32[0] = (float)(v8.m128_f32[0] * UFG::qVector3::msDirUp.z)
                              - (float)(v10 * UFG::qVector3::msDirUp.x);
              v24 = v23;
              v25 = (float)(v10 * UFG::qVector3::msDirUp.y) - (float)(v9 * UFG::qVector3::msDirUp.z);
              v26 = (float)(v9 * UFG::qVector3::msDirUp.x) - (float)(v8.m128_f32[0] * UFG::qVector3::msDirUp.y);
              v24.m128_f32[0] = (float)(v23.m128_f32[0] * v23.m128_f32[0]) + (float)(v25 * v25);
              if ( _mm_sqrt_ps(v24).m128_f32[0] > 0.001 )
              {
                v27 = v82;
                m_SideToRunTo = this->m_SideToRunTo;
                m_pComponent = 0i64;
                v30 = (__m128)(unsigned int)v80;
                y_low.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(x * x))
                                  + (float)(z * z);
                LODWORD(v31) = _mm_sqrt_ps(y_low).m128_u32[0];
                v30.m128_f32[0] = (float)((float)(*(float *)&v80 * *(float *)&v80) + (float)(v27 * v27))
                                + (float)(v81 * v81);
                LODWORD(v82) = _mm_sqrt_ps(v30).m128_u32[0];
                if ( m_SideToRunTo == eSIDE_NONE
                  || UFG::Metrics::msInstance.mSimTime_Temp >= this->m_NextTimeCanSetSideToRunTo
                  && (Value = UFG::LinearGraph<float>::GetValue(
                                &RunLaterallyFromTargetTask::s_SideToRunToHysteresis,
                                v31),
                      v82 > Value) )
                {
                  v33 = ((float)((float)((float)(v23.m128_f32[0] * *(float *)&v80) + (float)(v25 * v27))
                               + (float)(v26 * v81)) <= 0.0)
                      + 1;
                  if ( v33 != m_SideToRunTo )
                  {
                    this->m_SideToRunTo = v33;
                    this->m_NextTimeCanSetSideToRunTo = UFG::Metrics::msInstance.mSimTime_Temp + 3.0;
                  }
                }
                if ( this->m_SideToRunTo == eSIDE_RIGHT )
                {
                  LODWORD(v25) ^= _xmm[0];
                  v23.m128_i32[0] ^= _xmm[0];
                }
                m_Track = this->m_Track;
                v35 = *(float *)&m_Track[1].vfptr
                    / fsqrt((float)(v23.m128_f32[0] * v23.m128_f32[0]) + (float)(v25 * v25));
                v36 = v35 * 0.0;
                v37 = v35 * v25;
                v38 = v35 * v23.m128_f32[0];
                v81 = v38;
                *(float *)&v39 = v38 + v5->mWorldTransform.v3.y;
                v72 = v37 + v5->mWorldTransform.v3.x;
                v73 = __PAIR64__(v36 + v5->mWorldTransform.v3.z, v39);
                v40 = BYTE2(m_Track[1].mMasterRate.text.mOffset);
                m_pSimObject = this->m_pAIEntityComponent.m_pPointer->m_pSimObject;
                if ( m_pSimObject )
                  ComponentOfType = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::NavComponent::_TypeUID);
                else
                  ComponentOfType = 0i64;
                v43 = *(__int64 *)((char *)&ComponentOfType[2].m_BoundComponentHandles.mNode.mNext + 4);
                v80 = v43;
                if ( v40 )
                  HIDWORD(v80) |= 0x200u;
                else
                  HIDWORD(v80) = HIDWORD(v43) & 0xFFFFFDFF;
                v44 = UFG::NavManager::ms_pInstance->vfptr->AIRayCastHits(
                        UFG::NavManager::ms_pInstance,
                        (UFG::HavokNavPosition *)&ComponentOfType[1].m_SafePointerList.mNode.mNext,
                        (UFG::qVector3 *)&v72,
                        (UFG::NavParams *)&v80,
                        &v76);
                v45 = v44;
                if ( v44
                  && !BYTE3(this->m_Track[1].mMasterRate.text.mOffset)
                  && UFG::Metrics::msInstance.mSimTime_Temp >= this->m_NextTimeCanSetSideToRunTo )
                {
                  v46 = this->m_pAIEntityComponent.m_pPointer;
                  *(float *)&v47 = COERCE_FLOAT(LODWORD(v38) ^ _xmm[0]) + v5->mWorldTransform.v3.y;
                  *(float *)&v48 = COERCE_FLOAT(LODWORD(v36) ^ _xmm[0]) + v5->mWorldTransform.v3.z;
                  v74 = COERCE_FLOAT(LODWORD(v37) ^ _xmm[0]) + v5->mWorldTransform.v3.x;
                  v75 = __PAIR64__(v48, v47);
                  v49 = v46->m_pSimObject;
                  v50 = v49 ? UFG::SimObject::GetComponentOfType(v49, UFG::NavComponent::_TypeUID) : 0i64;
                  v51 = *(__int64 *)((char *)&v50[2].m_BoundComponentHandles.mNode.mNext + 4);
                  v80 = v51;
                  if ( v40 )
                    HIDWORD(v80) |= 0x200u;
                  else
                    HIDWORD(v80) = HIDWORD(v51) & 0xFFFFFDFF;
                  if ( !UFG::NavManager::ms_pInstance->vfptr->AIRayCastHits(
                          UFG::NavManager::ms_pInstance,
                          (UFG::HavokNavPosition *)&v50[1].m_SafePointerList.mNode.mNext,
                          (UFG::qVector3 *)&v74,
                          (UFG::NavParams *)&v80,
                          (UFG::qVector3 *)v79) )
                  {
                    v52 = (this->m_SideToRunTo != eSIDE_RIGHT) + 1;
                    v72 = v74;
                    v73 = v75;
                    if ( v52 != this->m_SideToRunTo )
                    {
                      this->m_SideToRunTo = v52;
                      this->m_NextTimeCanSetSideToRunTo = UFG::Metrics::msInstance.mSimTime_Temp + 3.0;
                    }
                  }
                }
                v53 = this->m_Track;
                if ( BYTE3(v53[1].mMasterRate.text.mOffset)
                  && v45
                  && (v54 = (__m128)LODWORD(v5->mWorldTransform.v3.y),
                      v54.m128_f32[0] = (float)((float)(v54.m128_f32[0] - v76.y) * (float)(v54.m128_f32[0] - v76.y))
                                      + (float)((float)(v5->mWorldTransform.v3.x - v76.x)
                                              * (float)(v5->mWorldTransform.v3.x - v76.x)),
                      _mm_sqrt_ps(v54).m128_f32[0] < *(float *)&v53[1].mBreakPoint) )
                {
                  v55 = LODWORD(v12) ^ _xmm[0];
                  v56 = LODWORD(v13) ^ _xmm[0];
                  v57 = LODWORD(v14) ^ _xmm[0];
                  v58 = (UFG::SimObjectCVBase *)this->m_pActionContext->mSimObject.m_pPointer;
                  if ( v58 )
                  {
                    m_Flags = v58->m_Flags;
                    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
                    {
                      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v58);
                    }
                    else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
                    {
                      ComponentOfTypeHK = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                                       v58,
                                                                                       UFG::AICharacterControllerBaseComponent::_TypeUID);
                    }
                    else
                    {
                      ComponentOfTypeHK = (UFG::AICharacterControllerBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                                                       v58,
                                                                                       UFG::AICharacterControllerBaseComponent::_TypeUID);
                    }
                    if ( ComponentOfTypeHK )
                    {
                      p_mMotionIntentionSpeedRaw = &ComponentOfTypeHK->m_Intention.mMotionIntentionSpeedRaw;
                      Intention::Set(&ComponentOfTypeHK->m_Intention, this->m_Track[1].m_TrackClassNameUID, 0.0);
                      v62 = (float)((float)(*(float *)&v56 * *(float *)&v56) + (float)(*(float *)&v55 * *(float *)&v55))
                          + (float)(*(float *)&v57 * *(float *)&v57);
                      if ( v62 == 0.0 )
                        v63 = 0.0;
                      else
                        v63 = 1.0 / fsqrt(v62);
                      p_mMotionIntentionSpeedRaw[7] = v63 * *(float *)&v57;
                      p_mMotionIntentionSpeedRaw[5] = v63 * *(float *)&v55;
                      p_mMotionIntentionSpeedRaw[6] = v63 * *(float *)&v56;
                    }
                  }
                }
                else
                {
                  v64 = multiplier * sNaturalMovementSpeeds[BYTE1(v53[1].mMasterRate.text.mOffset)];
                  v65 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
                  if ( v65 )
                  {
                    v66 = v65->m_Flags;
                    if ( (v66 & 0x4000) != 0 )
                    {
                      m_pComponent = (UFG::NavComponent *)v65->m_Components.p[36].m_pComponent;
                    }
                    else
                    {
                      if ( v66 < 0 || (v66 & 0x2000) != 0 || (v66 & 0x1000) != 0 )
                        v67 = UFG::SimObjectGame::GetComponentOfTypeHK(v65, UFG::NavComponent::_TypeUID);
                      else
                        v67 = UFG::SimObject::GetComponentOfType(v65, UFG::NavComponent::_TypeUID);
                      m_pComponent = (UFG::NavComponent *)v67;
                    }
                  }
                  npDestination.m_bValid = 0;
                  npDestination.m_vPosition = v76;
                  npDestination.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
                  *(_QWORD *)&npDestination.m_packedKey = -1i64;
                  npDestination.m_hkvMeshPosition.m_quad = _mm_unpacklo_ps(
                                                             _mm_unpacklo_ps(
                                                               (__m128)LODWORD(v76.x),
                                                               (__m128)LODWORD(v76.z)),
                                                             _mm_unpacklo_ps(
                                                               (__m128)LODWORD(v76.y),
                                                               (__m128)(unsigned int)FLOAT_1_0));
                  UFG::NavComponent::AddGoalPoint(m_pComponent, &npDestination, AiGoal_Replace_Direct, v64, 0.75);
                  if ( v77 > 0.1
                    && v82 < *((float *)&this->m_Track[1].vfptr + 1)
                    && (float)(v31 / v77) < this->m_TimeToImpactToDive )
                  {
                    v68 = (UFG::SimObjectCVBase *)this->m_pActionContext->mSimObject.m_pPointer;
                    if ( v68 )
                    {
                      v69 = v68->m_Flags;
                      if ( (v69 & 0x4000) != 0 || v69 < 0 )
                        v70 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v68);
                      else
                        v70 = (UFG::AICharacterControllerBaseComponent *)((v69 & 0x2000) != 0 || (v69 & 0x1000) != 0
                                                                        ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                            v68,
                                                                            UFG::AICharacterControllerBaseComponent::_TypeUID)
                                                                        : UFG::SimObject::GetComponentOfType(
                                                                            v68,
                                                                            UFG::AICharacterControllerBaseComponent::_TypeUID));
                      if ( v70 )
                        Intention::Set(&v70->m_Intention, gActionRequest_Dive.m_EnumValue, 0.0);
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return 1;
}

// File Line: 3481
// RVA: 0x330EB0
void __fastcall PathfindToTargetTask::PathfindToTargetTask(PathfindToTargetTask *this)
{
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<PathfindToTargetTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&PathfindToTargetTask::`vftable;
  this->m_pAIEntityComponent.mPrev = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.m_pPointer = 0i64;
  this->m_pTargetingSystemBaseComponent.mPrev = &this->m_pTargetingSystemBaseComponent;
  this->m_pTargetingSystemBaseComponent.mNext = &this->m_pTargetingSystemBaseComponent;
  this->m_pTargetingSystemBaseComponent.m_pPointer = 0i64;
  this->m_pTargetTransformNodeComponent.mPrev = &this->m_pTargetTransformNodeComponent;
  this->m_pTargetTransformNodeComponent.mNext = &this->m_pTargetTransformNodeComponent;
  this->m_pTargetTransformNodeComponent.m_pPointer = 0i64;
  this->m_pNavComponent.mPrev = &this->m_pNavComponent;
  this->m_pNavComponent.mNext = &this->m_pNavComponent;
  this->m_pNavComponent.m_pPointer = 0i64;
  this->m_NavParams.m_fRadius = 0.0;
  this->m_NavParams.m_flags = 65280;
  this->m_TimeBegan = 0.0;
}

// File Line: 3488
// RVA: 0x339C10
void __fastcall PathfindToTargetTask::~PathfindToTargetTask(PathfindToTargetTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::NavComponent> *p_m_pNavComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_m_pTargetTransformNodeComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *p_m_pTargetingSystemBaseComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pAIEntityComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v21; // rax
  UFG::qNode<ITask,ITask> *v22; // rcx
  UFG::qNode<ITask,ITask> *v23; // rax

  this->vfptr = (ITaskVtbl *)&PathfindToTargetTask::`vftable;
  p_m_pNavComponent = &this->m_pNavComponent;
  if ( this->m_pNavComponent.m_pPointer )
  {
    mPrev = p_m_pNavComponent->mPrev;
    mNext = p_m_pNavComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pNavComponent->mPrev = p_m_pNavComponent;
    p_m_pNavComponent->mNext = p_m_pNavComponent;
  }
  p_m_pNavComponent->m_pPointer = 0i64;
  v5 = p_m_pNavComponent->mPrev;
  v6 = p_m_pNavComponent->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_m_pNavComponent->mPrev = p_m_pNavComponent;
  p_m_pNavComponent->mNext = p_m_pNavComponent;
  p_m_pTargetTransformNodeComponent = &this->m_pTargetTransformNodeComponent;
  if ( this->m_pTargetTransformNodeComponent.m_pPointer )
  {
    v8 = p_m_pTargetTransformNodeComponent->mPrev;
    v9 = this->m_pTargetTransformNodeComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    p_m_pTargetTransformNodeComponent->mPrev = p_m_pTargetTransformNodeComponent;
    this->m_pTargetTransformNodeComponent.mNext = &this->m_pTargetTransformNodeComponent;
  }
  this->m_pTargetTransformNodeComponent.m_pPointer = 0i64;
  v10 = p_m_pTargetTransformNodeComponent->mPrev;
  v11 = this->m_pTargetTransformNodeComponent.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  p_m_pTargetTransformNodeComponent->mPrev = p_m_pTargetTransformNodeComponent;
  this->m_pTargetTransformNodeComponent.mNext = &this->m_pTargetTransformNodeComponent;
  p_m_pTargetingSystemBaseComponent = &this->m_pTargetingSystemBaseComponent;
  if ( this->m_pTargetingSystemBaseComponent.m_pPointer )
  {
    v13 = p_m_pTargetingSystemBaseComponent->mPrev;
    v14 = this->m_pTargetingSystemBaseComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    p_m_pTargetingSystemBaseComponent->mPrev = p_m_pTargetingSystemBaseComponent;
    this->m_pTargetingSystemBaseComponent.mNext = &this->m_pTargetingSystemBaseComponent;
  }
  this->m_pTargetingSystemBaseComponent.m_pPointer = 0i64;
  v15 = p_m_pTargetingSystemBaseComponent->mPrev;
  v16 = this->m_pTargetingSystemBaseComponent.mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  p_m_pTargetingSystemBaseComponent->mPrev = p_m_pTargetingSystemBaseComponent;
  this->m_pTargetingSystemBaseComponent.mNext = &this->m_pTargetingSystemBaseComponent;
  p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
  if ( this->m_pAIEntityComponent.m_pPointer )
  {
    v18 = p_m_pAIEntityComponent->mPrev;
    v19 = this->m_pAIEntityComponent.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
    this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
  }
  this->m_pAIEntityComponent.m_pPointer = 0i64;
  v20 = p_m_pAIEntityComponent->mPrev;
  v21 = this->m_pAIEntityComponent.mNext;
  v20->mNext = v21;
  v21->mPrev = v20;
  p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
  this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v22 = this->mPrev;
  v23 = this->mNext;
  v22->mNext = v23;
  v23->mPrev = v22;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 3493
// RVA: 0x347600
void __fastcall PathfindToTargetTask::Begin(PathfindToTargetTask *this, ActionContext *action_context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::SimComponent *v4; // rdi
  UFG::SimComponent *v6; // r8
  __int16 m_Flags; // dx
  UFG::ActiveAIEntityComponent *ComponentOfTypeHK; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pAIEntityComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::SimObjectGame *v13; // rcx
  UFG::SimComponent *m_pComponent; // r8
  __int16 v15; // dx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *p_m_pTargetingSystemBaseComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rax
  UFG::SimObjectGame *v21; // rcx
  __int16 v22; // dx
  UFG::SimComponent *v23; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::NavComponent> *p_m_pNavComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v25; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v26; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v27; // rax
  UFG::SimComponent *v28; // r8
  __int64 v29; // r8
  UFG::SimComponent *v30; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_m_pTargetTransformNodeComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v32; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v33; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v34; // rax
  UFG::SimComponent *v35; // rax
  unsigned int v36; // eax

  this->m_pActionContext = action_context;
  m_pPointer = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
  v4 = 0i64;
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
    v6 = ComponentOfTypeHK;
  }
  else
  {
    v6 = 0i64;
  }
  p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
  if ( this->m_pAIEntityComponent.m_pPointer )
  {
    mPrev = p_m_pAIEntityComponent->mPrev;
    mNext = this->m_pAIEntityComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
    this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
  }
  this->m_pAIEntityComponent.m_pPointer = v6;
  if ( v6 )
  {
    v12 = v6->m_SafePointerList.mNode.mPrev;
    v12->mNext = p_m_pAIEntityComponent;
    p_m_pAIEntityComponent->mPrev = v12;
    this->m_pAIEntityComponent.mNext = &v6->m_SafePointerList.mNode;
    v6->m_SafePointerList.mNode.mPrev = p_m_pAIEntityComponent;
  }
  v13 = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  if ( v13 )
  {
    v15 = v13->m_Flags;
    if ( (v15 & 0x4000) != 0 )
    {
      m_pComponent = v13->m_Components.p[20].m_pComponent;
    }
    else if ( v15 >= 0 )
    {
      if ( (v15 & 0x2000) != 0 || (v15 & 0x1000) != 0 )
        ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        ComponentOfType = UFG::SimObject::GetComponentOfType(v13, UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = ComponentOfType;
    }
    else
    {
      m_pComponent = v13->m_Components.p[20].m_pComponent;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  p_m_pTargetingSystemBaseComponent = &this->m_pTargetingSystemBaseComponent;
  if ( this->m_pTargetingSystemBaseComponent.m_pPointer )
  {
    v18 = p_m_pTargetingSystemBaseComponent->mPrev;
    v19 = this->m_pTargetingSystemBaseComponent.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    p_m_pTargetingSystemBaseComponent->mPrev = p_m_pTargetingSystemBaseComponent;
    this->m_pTargetingSystemBaseComponent.mNext = &this->m_pTargetingSystemBaseComponent;
  }
  this->m_pTargetingSystemBaseComponent.m_pPointer = m_pComponent;
  if ( m_pComponent )
  {
    v20 = m_pComponent->m_SafePointerList.mNode.mPrev;
    v20->mNext = p_m_pTargetingSystemBaseComponent;
    p_m_pTargetingSystemBaseComponent->mPrev = v20;
    this->m_pTargetingSystemBaseComponent.mNext = &m_pComponent->m_SafePointerList.mNode;
    m_pComponent->m_SafePointerList.mNode.mPrev = p_m_pTargetingSystemBaseComponent;
  }
  v21 = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  if ( v21 )
  {
    v22 = v21->m_Flags;
    if ( (v22 & 0x4000) != 0 )
    {
      v4 = v21->m_Components.p[36].m_pComponent;
    }
    else
    {
      if ( v22 < 0 || (v22 & 0x2000) != 0 || (v22 & 0x1000) != 0 )
        v23 = UFG::SimObjectGame::GetComponentOfTypeHK(v21, UFG::NavComponent::_TypeUID);
      else
        v23 = UFG::SimObject::GetComponentOfType(v21, UFG::NavComponent::_TypeUID);
      v4 = v23;
    }
  }
  p_m_pNavComponent = &this->m_pNavComponent;
  if ( this->m_pNavComponent.m_pPointer )
  {
    v25 = p_m_pNavComponent->mPrev;
    v26 = this->m_pNavComponent.mNext;
    v25->mNext = v26;
    v26->mPrev = v25;
    p_m_pNavComponent->mPrev = p_m_pNavComponent;
    this->m_pNavComponent.mNext = &this->m_pNavComponent;
  }
  this->m_pNavComponent.m_pPointer = v4;
  if ( v4 )
  {
    v27 = v4->m_SafePointerList.mNode.mPrev;
    v27->mNext = p_m_pNavComponent;
    p_m_pNavComponent->mPrev = v27;
    this->m_pNavComponent.mNext = &v4->m_SafePointerList.mNode;
    v4->m_SafePointerList.mNode.mPrev = p_m_pNavComponent;
  }
  v28 = this->m_pTargetingSystemBaseComponent.m_pPointer;
  this->m_TimeBegan = UFG::Metrics::msInstance.mSimTime_Temp;
  if ( v28 )
  {
    v29 = *(_QWORD *)(56i64 * *(unsigned __int8 *)(LOBYTE(this->m_Track[1].vfptr) + *(_QWORD *)&v28[1].m_Flags + 8i64)
                    + *(_QWORD *)&v28[1].m_TypeUID
                    + 40);
    if ( v29 )
    {
      v30 = *(UFG::SimComponent **)(v29 + 88);
      p_m_pTargetTransformNodeComponent = &this->m_pTargetTransformNodeComponent;
      if ( this->m_pTargetTransformNodeComponent.m_pPointer )
      {
        v32 = p_m_pTargetTransformNodeComponent->mPrev;
        v33 = this->m_pTargetTransformNodeComponent.mNext;
        v32->mNext = v33;
        v33->mPrev = v32;
        p_m_pTargetTransformNodeComponent->mPrev = p_m_pTargetTransformNodeComponent;
        this->m_pTargetTransformNodeComponent.mNext = &this->m_pTargetTransformNodeComponent;
      }
      this->m_pTargetTransformNodeComponent.m_pPointer = v30;
      if ( v30 )
      {
        v34 = v30->m_SafePointerList.mNode.mPrev;
        v34->mNext = p_m_pTargetTransformNodeComponent;
        p_m_pTargetTransformNodeComponent->mPrev = v34;
        this->m_pTargetTransformNodeComponent.mNext = &v30->m_SafePointerList.mNode;
        v30->m_SafePointerList.mNode.mPrev = p_m_pTargetTransformNodeComponent;
      }
    }
  }
  v35 = this->m_pNavComponent.m_pPointer;
  if ( v35 )
  {
    this->m_NavParams = *(UFG::NavParams *)((char *)&v35[2].m_BoundComponentHandles.mNode.mNext + 4);
    if ( BYTE4(this->m_Track[1].mResourceOwner) )
    {
      v36 = this->m_NavParams.m_flags;
      LOBYTE(this->m_NavParams.m_flags) = 0;
      this->m_NavParams.m_flags |= v36 & 0xFE;
      UFG::NavComponent::SetDestinationParams((UFG::NavComponent *)this->m_pNavComponent.m_pPointer, &this->m_NavParams);
    }
  }
}

// File Line: 3526
// RVA: 0x391600
bool __fastcall PathfindToTargetTask::Update(PathfindToTargetTask *this, float timestep)
{
  UFG::SimObject *v3; // rdi
  UFG::SimComponent *m_pTransformNodeComponent; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_m_pTargetTransformNodeComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::SimComponent *m_pPointer; // rsi
  ITrack *m_Track; // rax
  UFG::TransformNodeComponent *v11; // rcx
  float v12; // xmm1_4
  float v13; // xmm2_4
  UFG::qVector4 *v14; // rax
  UFG::NavComponent *v15; // rsi
  __m128 z_low; // xmm0
  __m128 y_low; // xmm2
  ITrack *v18; // rax
  __int64 v19; // rcx
  UFG::SimComponent *v20; // rbx
  unsigned int v21; // eax
  unsigned int m_pSimObject; // ecx
  UFG::PedKnowledgeRecord *v23; // rbx
  UFG::qVector4 row_vec4; // [rsp+30h] [rbp-68h] BYREF
  UFG::qVector4 result; // [rsp+40h] [rbp-58h] BYREF
  UFG::HavokNavPosition npDestination; // [rsp+50h] [rbp-48h] BYREF

  v3 = *(UFG::SimObject **)(56i64
                          * *(unsigned __int8 *)(LOBYTE(this->m_Track[1].vfptr)
                                               + *(_QWORD *)&this->m_pTargetingSystemBaseComponent.m_pPointer[1].m_Flags
                                               + 8i64)
                          + *(_QWORD *)&this->m_pTargetingSystemBaseComponent.m_pPointer[1].m_TypeUID
                          + 40);
  if ( v3 )
  {
    m_pTransformNodeComponent = v3->m_pTransformNodeComponent;
    p_m_pTargetTransformNodeComponent = &this->m_pTargetTransformNodeComponent;
    if ( this->m_pTargetTransformNodeComponent.m_pPointer )
    {
      mPrev = p_m_pTargetTransformNodeComponent->mPrev;
      mNext = p_m_pTargetTransformNodeComponent->mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_m_pTargetTransformNodeComponent->mPrev = p_m_pTargetTransformNodeComponent;
      p_m_pTargetTransformNodeComponent->mNext = p_m_pTargetTransformNodeComponent;
    }
    p_m_pTargetTransformNodeComponent->m_pPointer = m_pTransformNodeComponent;
    if ( m_pTransformNodeComponent )
    {
      v8 = m_pTransformNodeComponent->m_SafePointerList.mNode.mPrev;
      v8->mNext = p_m_pTargetTransformNodeComponent;
      p_m_pTargetTransformNodeComponent->mPrev = v8;
      p_m_pTargetTransformNodeComponent->mNext = &m_pTransformNodeComponent->m_SafePointerList.mNode;
      m_pTransformNodeComponent->m_SafePointerList.mNode.mPrev = p_m_pTargetTransformNodeComponent;
    }
  }
  m_pPointer = this->m_pTargetTransformNodeComponent.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Track = this->m_Track;
  v11 = (UFG::TransformNodeComponent *)this->m_pTargetTransformNodeComponent.m_pPointer;
  row_vec4.w = 1.0;
  v12 = *(float *)&m_Track[1].mBreakPoint;
  v13 = *(float *)&m_Track[1].mMasterRate.text.mOffset;
  LODWORD(row_vec4.x) = m_Track[1].m_TrackClassNameUID;
  row_vec4.y = v12;
  row_vec4.z = v13;
  UFG::TransformNodeComponent::UpdateWorldTransform(v11);
  v14 = UFG::operator*(&result, &row_vec4, (UFG::qMatrix44 *)&m_pPointer[2]);
  v15 = (UFG::NavComponent *)this->m_pNavComponent.m_pPointer;
  npDestination.m_bValid = 0;
  *(_QWORD *)&npDestination.m_packedKey = -1i64;
  z_low = (__m128)LODWORD(v14->z);
  y_low = (__m128)LODWORD(v14->y);
  npDestination.m_vPosition.x = v14->x;
  LODWORD(npDestination.m_vPosition.y) = y_low.m128_i32[0];
  LODWORD(npDestination.m_vPosition.z) = z_low.m128_i32[0];
  npDestination.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
  v18 = this->m_Track;
  v19 = BYTE2(v18[1].vfptr);
  npDestination.m_hkvMeshPosition.m_quad = _mm_unpacklo_ps(
                                             _mm_unpacklo_ps((__m128)LODWORD(npDestination.m_vPosition.x), z_low),
                                             _mm_unpacklo_ps(y_low, (__m128)(unsigned int)FLOAT_1_0));
  UFG::NavComponent::AddGoalPoint(
    v15,
    &npDestination,
    AiGoal_Replace,
    sNaturalMovementSpeeds[v19],
    *(float *)&v18[1].mResourceOwner);
  if ( !UFG::NavComponent::IsCurrentGoalProcessed(v15) )
    return 1;
  v20 = this->m_pAIEntityComponent.m_pPointer;
  v21 = 0;
  m_pSimObject = (unsigned int)v20[21].m_pSimObject;
  if ( m_pSimObject )
  {
    v23 = (UFG::PedKnowledgeRecord *)v20[21].m_BoundComponentHandles.mNode.mPrev;
    while ( v3 != v23->pSimObject.m_pPointer )
    {
      ++v21;
      ++v23;
      if ( v21 >= m_pSimObject )
        goto LABEL_12;
    }
  }
  else
  {
LABEL_12:
    v23 = &UFG::PedKnowledgeBase::ms_defaultKnowledgeRecord;
  }
  if ( UFG::NavComponent::IsDestinationUnreachable(v15) )
    *((_BYTE *)v23 + 48) &= ~4u;
  else
    *((_BYTE *)v23 + 48) |= 4u;
  v23->m_uLastPathTest = UFG::Metrics::msInstance.mSimTimeMSec;
  return !UFG::NavComponent::IsAtDestination(v15);
}

// File Line: 3589
// RVA: 0x3553A0
void __fastcall PathfindToTargetTask::End(PathfindToTargetTask *this)
{
  if ( this->m_pNavComponent.m_pPointer )
    UFG::NavComponent::SetDestinationParams((UFG::NavComponent *)this->m_pNavComponent.m_pPointer, &this->m_NavParams);
}

// File Line: 3603
// RVA: 0x330D80
void __fastcall PathfindAwayFromTargetTask::PathfindAwayFromTargetTask(PathfindAwayFromTargetTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::NavComponent> *p_m_pNavComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax

  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<PathfindAwayFromTargetTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&PathfindAwayFromTargetTask::`vftable;
  p_m_pNavComponent = &this->m_pNavComponent;
  this->m_pNavComponent.mPrev = &this->m_pNavComponent;
  this->m_pNavComponent.mNext = &this->m_pNavComponent;
  this->m_pNavComponent.m_pPointer = 0i64;
  this->m_pTargetingSystemBaseComponent.mPrev = &this->m_pTargetingSystemBaseComponent;
  this->m_pTargetingSystemBaseComponent.mNext = &this->m_pTargetingSystemBaseComponent;
  this->m_pTargetingSystemBaseComponent.m_pPointer = 0i64;
  this->m_pTargetTransformNodeComponent.mPrev = &this->m_pTargetTransformNodeComponent;
  this->m_pTargetTransformNodeComponent.mNext = &this->m_pTargetTransformNodeComponent;
  this->m_pTargetTransformNodeComponent.m_pPointer = 0i64;
  this->m_NavParams.m_fRadius = 0.0;
  this->m_NavParams.m_flags = 65280;
  this->m_pActionContext = 0i64;
  if ( this->m_pNavComponent.m_pPointer )
  {
    mPrev = p_m_pNavComponent->mPrev;
    mNext = p_m_pNavComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pNavComponent->mPrev = p_m_pNavComponent;
    p_m_pNavComponent->mNext = p_m_pNavComponent;
  }
  p_m_pNavComponent->m_pPointer = 0i64;
  this->m_LastTimeFleeDirectionChecked = -99999.0;
}

// File Line: 3613
// RVA: 0x339A40
void __fastcall PathfindAwayFromTargetTask::~PathfindAwayFromTargetTask(PathfindAwayFromTargetTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_m_pTargetTransformNodeComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *p_m_pTargetingSystemBaseComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::NavComponent> *p_m_pNavComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qNode<ITask,ITask> *v17; // rcx
  UFG::qNode<ITask,ITask> *v18; // rax

  this->vfptr = (ITaskVtbl *)&PathfindAwayFromTargetTask::`vftable;
  p_m_pTargetTransformNodeComponent = &this->m_pTargetTransformNodeComponent;
  if ( this->m_pTargetTransformNodeComponent.m_pPointer )
  {
    mPrev = p_m_pTargetTransformNodeComponent->mPrev;
    mNext = p_m_pTargetTransformNodeComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pTargetTransformNodeComponent->mPrev = p_m_pTargetTransformNodeComponent;
    p_m_pTargetTransformNodeComponent->mNext = p_m_pTargetTransformNodeComponent;
  }
  p_m_pTargetTransformNodeComponent->m_pPointer = 0i64;
  v5 = p_m_pTargetTransformNodeComponent->mPrev;
  v6 = p_m_pTargetTransformNodeComponent->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_m_pTargetTransformNodeComponent->mPrev = p_m_pTargetTransformNodeComponent;
  p_m_pTargetTransformNodeComponent->mNext = p_m_pTargetTransformNodeComponent;
  p_m_pTargetingSystemBaseComponent = &this->m_pTargetingSystemBaseComponent;
  if ( this->m_pTargetingSystemBaseComponent.m_pPointer )
  {
    v8 = p_m_pTargetingSystemBaseComponent->mPrev;
    v9 = this->m_pTargetingSystemBaseComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    p_m_pTargetingSystemBaseComponent->mPrev = p_m_pTargetingSystemBaseComponent;
    this->m_pTargetingSystemBaseComponent.mNext = &this->m_pTargetingSystemBaseComponent;
  }
  this->m_pTargetingSystemBaseComponent.m_pPointer = 0i64;
  v10 = p_m_pTargetingSystemBaseComponent->mPrev;
  v11 = this->m_pTargetingSystemBaseComponent.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  p_m_pTargetingSystemBaseComponent->mPrev = p_m_pTargetingSystemBaseComponent;
  this->m_pTargetingSystemBaseComponent.mNext = &this->m_pTargetingSystemBaseComponent;
  p_m_pNavComponent = &this->m_pNavComponent;
  if ( this->m_pNavComponent.m_pPointer )
  {
    v13 = p_m_pNavComponent->mPrev;
    v14 = this->m_pNavComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    p_m_pNavComponent->mPrev = p_m_pNavComponent;
    this->m_pNavComponent.mNext = &this->m_pNavComponent;
  }
  this->m_pNavComponent.m_pPointer = 0i64;
  v15 = p_m_pNavComponent->mPrev;
  v16 = this->m_pNavComponent.mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  p_m_pNavComponent->mPrev = p_m_pNavComponent;
  this->m_pNavComponent.mNext = &this->m_pNavComponent;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v17 = this->mPrev;
  v18 = this->mNext;
  v17->mNext = v18;
  v18->mPrev = v17;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 3618
// RVA: 0x356E80
void __fastcall PathfindAwayFromTargetTask::FindNewPath(PathfindAwayFromTargetTask *this)
{
  UFG::SimObjectGame *m_pPointer; // r8
  UFG::SimComponent *m_pComponent; // rsi
  __int16 m_Flags; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qVector4 *CurrentPosition; // rax
  float y; // xmm1_4
  float v8; // xmm2_4
  unsigned int m_NameUID; // xmm1_4
  float v10; // xmm2_4
  ITrack *m_Track; // rcx
  float v12; // xmm6_4
  UFG::SimComponent *v13; // rdi
  __m128 mPrev_high; // xmm3
  __m128 mNext_low; // xmm0
  __m128 y_low; // xmm2
  UFG::DaemonManager *v17; // rax
  float v18; // xmm0_4
  __int64 v19; // rcx
  UFG::DaemonQueryInput v20; // [rsp+20h] [rbp-B8h] BYREF
  UFG::NavParams *p_m_NavParams; // [rsp+40h] [rbp-98h]
  __int64 (__fastcall **v22)(_QWORD); // [rsp+50h] [rbp-88h]
  __int64 vfptr; // [rsp+58h] [rbp-80h]
  float z; // [rsp+60h] [rbp-78h]
  float v25; // [rsp+68h] [rbp-70h]
  float v26; // [rsp+6Ch] [rbp-6Ch]
  UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> m_BoundComponentHandles; // [rsp+70h] [rbp-68h]
  int v28; // [rsp+80h] [rbp-58h]
  UFG::HavokNavPosition v29; // [rsp+88h] [rbp-50h] BYREF
  UFG::DaemonQueryOutput output; // [rsp+C8h] [rbp-10h] BYREF
  __int64 (__fastcall **v31)(_QWORD); // [rsp+E8h] [rbp+10h]
  UFG::qVector3 v32; // [rsp+F0h] [rbp+18h]
  char v33; // [rsp+100h] [rbp+28h]
  __m128 v34; // [rsp+108h] [rbp+30h]
  __int64 v35; // [rsp+118h] [rbp+40h]
  __int64 v36; // [rsp+128h] [rbp+50h]
  __int64 v37; // [rsp+138h] [rbp+60h]

  v37 = -2i64;
  v20.m_daemonType = DaemonType_Navigation;
  *(_QWORD *)&v20.m_internalType = 3i64;
  v20.m_pOutput = 0i64;
  v20.vfptr = (UFG::DaemonQueryInputVtbl *)&UFG::FleeTraversalImmediateQuery::`vftable;
  p_m_NavParams = 0i64;
  z = UFG::qVector3::msZero.z;
  v22 = &UFG::HavokNavPosition::`vftable;
  vfptr = -1i64;
  v25 = 0.0;
  v26 = FLOAT_N1_0;
  m_BoundComponentHandles = (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0>)0i64;
  v28 = -1;
  output.m_id = DaemonType_Navigation;
  *(_QWORD *)&output.m_internalType = 3i64;
  output.vfptr = (UFG::DaemonQueryOutputVtbl *)&UFG::FleeTraversalOutput::`vftable;
  v32 = UFG::qVector3::msZero;
  v31 = &UFG::HavokNavPosition::`vftable;
  v33 = 0;
  v35 = -1i64;
  v34 = _mm_unpacklo_ps(
          _mm_unpacklo_ps((__m128)LODWORD(UFG::qVector3::msZero.x), (__m128)LODWORD(UFG::qVector3::msZero.z)),
          _mm_unpacklo_ps((__m128)LODWORD(UFG::qVector3::msZero.y), (__m128)(unsigned int)FLOAT_1_0));
  v36 = 0i64;
  m_pPointer = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[36].m_pComponent;
    }
    else
    {
      if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::NavComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::NavComponent::_TypeUID);
      m_pComponent = ComponentOfTypeHK;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  if ( ((unsigned __int8 (__fastcall *)(UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **))m_pComponent[1].m_SafePointerList.mNode.mNext[2].mPrev)(&m_pComponent[1].m_SafePointerList.mNode.mNext) )
  {
    m_NameUID = m_pComponent[1].m_NameUID;
    v10 = *(float *)&m_pComponent[1].m_Flags;
    LODWORD(vfptr) = m_pComponent[1].m_TypeUID;
    HIDWORD(vfptr) = m_NameUID;
    z = v10;
    if ( LOBYTE(m_pComponent[1].m_pSimObject) )
    {
      LOBYTE(v25) = m_pComponent[1].m_pSimObject;
      m_BoundComponentHandles = m_pComponent[1].m_BoundComponentHandles;
      vfptr = (__int64)m_pComponent[2].vfptr;
    }
    else
    {
      LOBYTE(v25) = 0;
    }
    m_Track = this->m_Track;
    v12 = *((float *)&m_Track[1].mResourceOwner + 1);
    v25 = v12;
    this->m_NavParams = *(UFG::NavParams *)((char *)&m_pComponent[2].m_BoundComponentHandles.mNode.mNext + 4);
    if ( !LOBYTE(m_Track[1].mMasterRate.expression.mOffset) )
      v26 = FLOAT_500000_0;
    p_m_NavParams = &this->m_NavParams;
    v13 = this->m_pTargetTransformNodeComponent.m_pPointer;
    if ( v13 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->m_pTargetTransformNodeComponent.m_pPointer);
      mPrev_high = (__m128)HIDWORD(v13[2].m_BoundComponentHandles.mNode.mPrev);
      mNext_low = (__m128)LODWORD(v13[2].m_BoundComponentHandles.mNode.mNext);
      v29.m_vPosition.x = *(float *)&v13[2].m_BoundComponentHandles.mNode.mPrev;
      LODWORD(v29.m_vPosition.y) = mPrev_high.m128_i32[0];
      v29.m_hkvMeshPosition.m_quad = _mm_unpacklo_ps(
                                       _mm_unpacklo_ps((__m128)LODWORD(v29.m_vPosition.x), mNext_low),
                                       _mm_unpacklo_ps(mPrev_high, (__m128)(unsigned int)FLOAT_1_0));
    }
    else
    {
      y_low = (__m128)LODWORD(this->m_pTaskOrigin.y);
      mNext_low = (__m128)LODWORD(this->m_pTaskOrigin.z);
      v29.m_vPosition.x = this->m_pTaskOrigin.x;
      LODWORD(v29.m_vPosition.y) = y_low.m128_i32[0];
      v29.m_hkvMeshPosition.m_quad = _mm_unpacklo_ps(
                                       _mm_unpacklo_ps((__m128)LODWORD(v29.m_vPosition.x), mNext_low),
                                       _mm_unpacklo_ps(y_low, (__m128)(unsigned int)FLOAT_1_0));
    }
    LODWORD(v29.m_vPosition.z) = mNext_low.m128_i32[0];
    v29.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
    v29.m_bValid = 0;
    *(_QWORD *)&v29.m_packedKey = -1i64;
    UFG::FleeTraversalImmediateQuery::AddThreat((UFG::FleeTraversalImmediateQuery *)&v20, &v29, v12);
    v17 = UFG::DaemonManager::Instance();
    UFG::DaemonManager::SubmitQuery(v17, &v20, &output);
    if ( output.m_status == Status_Completed )
    {
      this->m_pFleeDestination.x = v32.x;
      y = v32.y;
      v18 = v32.z;
    }
    else
    {
      LODWORD(this->m_pFleeDestination.x) = vfptr;
      y = *((float *)&vfptr + 1);
      v18 = z;
    }
    this->m_pFleeDestination.z = v18;
  }
  else
  {
    CurrentPosition = UFG::NavComponent::GetCurrentPosition((UFG::NavComponent *)m_pComponent);
    y = CurrentPosition->y;
    v8 = CurrentPosition->z;
    this->m_pFleeDestination.x = CurrentPosition->x;
    this->m_pFleeDestination.z = v8;
  }
  this->m_pFleeDestination.y = y;
  v19 = v36;
  if ( v36 )
  {
    --*(_DWORD *)(v36 + 40);
    if ( !*(_DWORD *)(v19 + 40) )
      (**(void (__fastcall ***)(__int64, __int64))v19)(v19, 1i64);
  }
  output.vfptr = (UFG::DaemonQueryOutputVtbl *)&UFG::DaemonQueryOutput::`vftable;
  if ( m_BoundComponentHandles.mNode.mNext )
    operator delete[](m_BoundComponentHandles.mNode.mNext);
}

// File Line: 3674
// RVA: 0x3473D0
void __fastcall PathfindAwayFromTargetTask::Begin(PathfindAwayFromTargetTask *this, ActionContext *action_context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::SimComponent *m_pComponent; // r8
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::NavComponent> *p_m_pNavComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::SimObjectGame *v11; // rcx
  UFG::SimComponent *v12; // r8
  __int16 v13; // dx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *p_m_pTargetingSystemBaseComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_m_pTargetTransformNodeComponent; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v21; // rax
  UFG::SimComponent *v22; // r9
  __int64 v23; // rcx
  UFG::SimComponent *v24; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v25; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *p_mNode; // rcx
  UFG::qVector4 *CurrentPosition; // rax
  float y; // xmm0_4
  float z; // xmm1_4

  this->m_pActionContext = action_context;
  m_pPointer = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[36].m_pComponent;
    }
    else
    {
      if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::NavComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::NavComponent::_TypeUID);
      m_pComponent = ComponentOfTypeHK;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  p_m_pNavComponent = &this->m_pNavComponent;
  if ( this->m_pNavComponent.m_pPointer )
  {
    mPrev = p_m_pNavComponent->mPrev;
    mNext = this->m_pNavComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pNavComponent->mPrev = p_m_pNavComponent;
    this->m_pNavComponent.mNext = &this->m_pNavComponent;
  }
  this->m_pNavComponent.m_pPointer = m_pComponent;
  if ( m_pComponent )
  {
    v10 = m_pComponent->m_SafePointerList.mNode.mPrev;
    v10->mNext = p_m_pNavComponent;
    p_m_pNavComponent->mPrev = v10;
    this->m_pNavComponent.mNext = &m_pComponent->m_SafePointerList.mNode;
    m_pComponent->m_SafePointerList.mNode.mPrev = p_m_pNavComponent;
  }
  v11 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
  if ( v11 )
  {
    v13 = v11->m_Flags;
    if ( (v13 & 0x4000) != 0 )
    {
      v12 = v11->m_Components.p[20].m_pComponent;
    }
    else if ( v13 >= 0 )
    {
      if ( (v13 & 0x2000) != 0 || (v13 & 0x1000) != 0 )
        ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        ComponentOfType = UFG::SimObject::GetComponentOfType(v11, UFG::TargetingSystemBaseComponent::_TypeUID);
      v12 = ComponentOfType;
    }
    else
    {
      v12 = v11->m_Components.p[20].m_pComponent;
    }
  }
  else
  {
    v12 = 0i64;
  }
  p_m_pTargetingSystemBaseComponent = &this->m_pTargetingSystemBaseComponent;
  if ( this->m_pTargetingSystemBaseComponent.m_pPointer )
  {
    v16 = p_m_pTargetingSystemBaseComponent->mPrev;
    v17 = this->m_pTargetingSystemBaseComponent.mNext;
    v16->mNext = v17;
    v17->mPrev = v16;
    p_m_pTargetingSystemBaseComponent->mPrev = p_m_pTargetingSystemBaseComponent;
    this->m_pTargetingSystemBaseComponent.mNext = &this->m_pTargetingSystemBaseComponent;
  }
  this->m_pTargetingSystemBaseComponent.m_pPointer = v12;
  if ( v12 )
  {
    v18 = v12->m_SafePointerList.mNode.mPrev;
    v18->mNext = p_m_pTargetingSystemBaseComponent;
    p_m_pTargetingSystemBaseComponent->mPrev = v18;
    this->m_pTargetingSystemBaseComponent.mNext = &v12->m_SafePointerList.mNode;
    v12->m_SafePointerList.mNode.mPrev = p_m_pTargetingSystemBaseComponent;
  }
  p_m_pTargetTransformNodeComponent = &this->m_pTargetTransformNodeComponent;
  if ( this->m_pTargetTransformNodeComponent.m_pPointer )
  {
    v20 = p_m_pTargetTransformNodeComponent->mPrev;
    v21 = this->m_pTargetTransformNodeComponent.mNext;
    v20->mNext = v21;
    v21->mPrev = v20;
    p_m_pTargetTransformNodeComponent->mPrev = p_m_pTargetTransformNodeComponent;
    this->m_pTargetTransformNodeComponent.mNext = &this->m_pTargetTransformNodeComponent;
  }
  this->m_pTargetTransformNodeComponent.m_pPointer = 0i64;
  v22 = this->m_pTargetingSystemBaseComponent.m_pPointer;
  if ( v22 )
  {
    v23 = *(_QWORD *)(56i64 * *(unsigned __int8 *)(LOBYTE(this->m_Track[1].vfptr) + *(_QWORD *)&v22[1].m_Flags + 8i64)
                    + *(_QWORD *)&v22[1].m_TypeUID
                    + 40);
    if ( v23 )
    {
      v24 = *(UFG::SimComponent **)(v23 + 88);
      this->m_pTargetTransformNodeComponent.m_pPointer = v24;
      if ( v24 )
      {
        v25 = v24->m_SafePointerList.mNode.mPrev;
        p_mNode = &v24->m_SafePointerList.mNode;
        v25->mNext = p_m_pTargetTransformNodeComponent;
        p_m_pTargetTransformNodeComponent->mPrev = v25;
        this->m_pTargetTransformNodeComponent.mNext = p_mNode;
        p_mNode->mPrev = p_m_pTargetTransformNodeComponent;
      }
    }
  }
  CurrentPosition = UFG::NavComponent::GetCurrentPosition((UFG::NavComponent *)this->m_pNavComponent.m_pPointer);
  y = CurrentPosition->y;
  z = CurrentPosition->z;
  this->m_pTaskOrigin.x = CurrentPosition->x;
  this->m_pTaskOrigin.y = y;
  this->m_pTaskOrigin.z = z;
  PathfindAwayFromTargetTask::FindNewPath(this);
}

// File Line: 3701
// RVA: 0x3913C0
char __fastcall PathfindAwayFromTargetTask::Update(PathfindAwayFromTargetTask *this, float timestep)
{
  UFG::NavComponent *m_pComponent; // rbx
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_m_pTargetTransformNodeComponent; // rdx
  __int64 v5; // r8
  UFG::SimComponent *v6; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  __int64 mResourceOwner_low; // rdi
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  __m128 z_low; // xmm0
  __m128 x_low; // xmm3
  __m128 y_low; // xmm2
  UFG::qVector4 *CurrentPosition; // rax
  UFG::TransformNodeComponent *v20; // rbx
  float *p_x; // rdi
  UFG::HavokNavPosition npDestination; // [rsp+30h] [rbp-48h] BYREF

  m_pComponent = 0i64;
  if ( !this->m_pTargetTransformNodeComponent.m_pPointer )
  {
    p_m_pTargetTransformNodeComponent = &this->m_pTargetTransformNodeComponent;
    v5 = *(_QWORD *)(56i64
                   * *(unsigned __int8 *)(LOBYTE(this->m_Track[1].vfptr)
                                        + *(_QWORD *)&this->m_pTargetingSystemBaseComponent.m_pPointer[1].m_Flags
                                        + 8i64)
                   + *(_QWORD *)&this->m_pTargetingSystemBaseComponent.m_pPointer[1].m_TypeUID
                   + 40);
    if ( v5 )
    {
      v6 = *(UFG::SimComponent **)(v5 + 88);
      if ( this->m_pTargetTransformNodeComponent.m_pPointer )
      {
        mPrev = p_m_pTargetTransformNodeComponent->mPrev;
        mNext = p_m_pTargetTransformNodeComponent->mNext;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        p_m_pTargetTransformNodeComponent->mPrev = p_m_pTargetTransformNodeComponent;
        p_m_pTargetTransformNodeComponent->mNext = p_m_pTargetTransformNodeComponent;
      }
      p_m_pTargetTransformNodeComponent->m_pPointer = v6;
      if ( v6 )
      {
        v9 = v6->m_SafePointerList.mNode.mPrev;
        v9->mNext = p_m_pTargetTransformNodeComponent;
        p_m_pTargetTransformNodeComponent->mPrev = v9;
        p_m_pTargetTransformNodeComponent->mNext = &v6->m_SafePointerList.mNode;
        v6->m_SafePointerList.mNode.mPrev = p_m_pTargetTransformNodeComponent;
      }
    }
    else
    {
      if ( this->m_pTargetTransformNodeComponent.m_pPointer )
      {
        v10 = p_m_pTargetTransformNodeComponent->mPrev;
        v11 = p_m_pTargetTransformNodeComponent->mNext;
        v10->mNext = v11;
        v11->mPrev = v10;
        p_m_pTargetTransformNodeComponent->mPrev = p_m_pTargetTransformNodeComponent;
        p_m_pTargetTransformNodeComponent->mNext = p_m_pTargetTransformNodeComponent;
      }
      p_m_pTargetTransformNodeComponent->m_pPointer = 0i64;
    }
  }
  mResourceOwner_low = LOBYTE(this->m_Track[1].mResourceOwner);
  m_pPointer = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::NavComponent *)m_pPointer->m_Components.p[36].m_pComponent;
    }
    else
    {
      if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::NavComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::NavComponent::_TypeUID);
      m_pComponent = (UFG::NavComponent *)ComponentOfTypeHK;
    }
  }
  z_low = (__m128)LODWORD(this->m_pFleeDestination.z);
  x_low = (__m128)LODWORD(this->m_pFleeDestination.x);
  y_low = (__m128)LODWORD(this->m_pFleeDestination.y);
  npDestination.m_bValid = 0;
  *(_QWORD *)&npDestination.m_packedKey = -1i64;
  LODWORD(npDestination.m_vPosition.x) = x_low.m128_i32[0];
  LODWORD(npDestination.m_vPosition.y) = y_low.m128_i32[0];
  npDestination.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
  LODWORD(npDestination.m_vPosition.z) = z_low.m128_i32[0];
  npDestination.m_hkvMeshPosition.m_quad = _mm_unpacklo_ps(
                                             _mm_unpacklo_ps(x_low, z_low),
                                             _mm_unpacklo_ps(y_low, (__m128)(unsigned int)FLOAT_1_0));
  UFG::NavComponent::AddGoalPoint(
    m_pComponent,
    &npDestination,
    AiGoal_Replace,
    sNaturalMovementSpeeds[mResourceOwner_low],
    3.0);
  if ( UFG::NavComponent::IsAtDestination(m_pComponent) )
  {
    if ( this->m_pTargetTransformNodeComponent.m_pPointer )
    {
      CurrentPosition = UFG::NavComponent::GetCurrentPosition((UFG::NavComponent *)this->m_pNavComponent.m_pPointer);
      v20 = (UFG::TransformNodeComponent *)this->m_pTargetTransformNodeComponent.m_pPointer;
      p_x = &CurrentPosition->x;
      UFG::TransformNodeComponent::UpdateWorldTransform(v20);
      if ( (float)((float)((float)((float)(v20->mWorldTransform.v3.y - p_x[1])
                                 * (float)(v20->mWorldTransform.v3.y - p_x[1]))
                         + (float)((float)(v20->mWorldTransform.v3.x - *p_x) * (float)(v20->mWorldTransform.v3.x - *p_x)))
                 + (float)((float)(v20->mWorldTransform.v3.z - p_x[2]) * (float)(v20->mWorldTransform.v3.z - p_x[2]))) < (float)(*((float *)&this->m_Track[1].mResourceOwner + 1) * *((float *)&this->m_Track[1].mResourceOwner + 1)) )
        PathfindAwayFromTargetTask::FindNewPath(this);
    }
  }
  return 1;
}

// File Line: 3809
// RVA: 0x330660
void __fastcall MoveDirectlyToTargetTask::MoveDirectlyToTargetTask(MoveDirectlyToTargetTask *this)
{
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<MoveDirectlyToTargetTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&MoveDirectlyToTargetTask::`vftable;
  this->m_pAIEntityComponent.mPrev = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.m_pPointer = 0i64;
  this->m_pTargetingSystemBaseComponent.mPrev = &this->m_pTargetingSystemBaseComponent;
  this->m_pTargetingSystemBaseComponent.mNext = &this->m_pTargetingSystemBaseComponent;
  this->m_pTargetingSystemBaseComponent.m_pPointer = 0i64;
  this->m_pTargetTransformNodeComponent.mPrev = &this->m_pTargetTransformNodeComponent;
  this->m_pTargetTransformNodeComponent.mNext = &this->m_pTargetTransformNodeComponent;
  this->m_pTargetTransformNodeComponent.m_pPointer = 0i64;
}

// File Line: 3814
// RVA: 0x339280
void __fastcall MoveDirectlyToTargetTask::~MoveDirectlyToTargetTask(MoveDirectlyToTargetTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_m_pTargetTransformNodeComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *p_m_pTargetingSystemBaseComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pAIEntityComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qNode<ITask,ITask> *v17; // rcx
  UFG::qNode<ITask,ITask> *v18; // rax

  this->vfptr = (ITaskVtbl *)&MoveDirectlyToTargetTask::`vftable;
  p_m_pTargetTransformNodeComponent = &this->m_pTargetTransformNodeComponent;
  if ( this->m_pTargetTransformNodeComponent.m_pPointer )
  {
    mPrev = p_m_pTargetTransformNodeComponent->mPrev;
    mNext = p_m_pTargetTransformNodeComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pTargetTransformNodeComponent->mPrev = p_m_pTargetTransformNodeComponent;
    p_m_pTargetTransformNodeComponent->mNext = p_m_pTargetTransformNodeComponent;
  }
  p_m_pTargetTransformNodeComponent->m_pPointer = 0i64;
  v5 = p_m_pTargetTransformNodeComponent->mPrev;
  v6 = p_m_pTargetTransformNodeComponent->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_m_pTargetTransformNodeComponent->mPrev = p_m_pTargetTransformNodeComponent;
  p_m_pTargetTransformNodeComponent->mNext = p_m_pTargetTransformNodeComponent;
  p_m_pTargetingSystemBaseComponent = &this->m_pTargetingSystemBaseComponent;
  if ( this->m_pTargetingSystemBaseComponent.m_pPointer )
  {
    v8 = p_m_pTargetingSystemBaseComponent->mPrev;
    v9 = this->m_pTargetingSystemBaseComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    p_m_pTargetingSystemBaseComponent->mPrev = p_m_pTargetingSystemBaseComponent;
    this->m_pTargetingSystemBaseComponent.mNext = &this->m_pTargetingSystemBaseComponent;
  }
  this->m_pTargetingSystemBaseComponent.m_pPointer = 0i64;
  v10 = p_m_pTargetingSystemBaseComponent->mPrev;
  v11 = this->m_pTargetingSystemBaseComponent.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  p_m_pTargetingSystemBaseComponent->mPrev = p_m_pTargetingSystemBaseComponent;
  this->m_pTargetingSystemBaseComponent.mNext = &this->m_pTargetingSystemBaseComponent;
  p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
  if ( this->m_pAIEntityComponent.m_pPointer )
  {
    v13 = p_m_pAIEntityComponent->mPrev;
    v14 = this->m_pAIEntityComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
    this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
  }
  this->m_pAIEntityComponent.m_pPointer = 0i64;
  v15 = p_m_pAIEntityComponent->mPrev;
  v16 = this->m_pAIEntityComponent.mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
  this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v17 = this->mPrev;
  v18 = this->mNext;
  v17->mNext = v18;
  v18->mPrev = v17;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 3819
// RVA: 0x346DB0
void __fastcall MoveDirectlyToTargetTask::Begin(MoveDirectlyToTargetTask *this, ActionContext *action_context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::SimComponent *m_pComponent; // rbx
  UFG::SimComponent *v6; // r8
  __int16 m_Flags; // dx
  UFG::ActiveAIEntityComponent *ComponentOfTypeHK; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pAIEntityComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::SimObjectGame *v13; // rcx
  __int16 v14; // dx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *p_m_pTargetingSystemBaseComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::SimComponent *v20; // r8
  __int64 v21; // r8
  UFG::SimComponent *v22; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_m_pTargetTransformNodeComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v24; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v25; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v26; // rax

  this->m_pActionContext = action_context;
  m_pPointer = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
  m_pComponent = 0i64;
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
    v6 = ComponentOfTypeHK;
  }
  else
  {
    v6 = 0i64;
  }
  p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
  if ( this->m_pAIEntityComponent.m_pPointer )
  {
    mPrev = p_m_pAIEntityComponent->mPrev;
    mNext = this->m_pAIEntityComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
    this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
  }
  this->m_pAIEntityComponent.m_pPointer = v6;
  if ( v6 )
  {
    v12 = v6->m_SafePointerList.mNode.mPrev;
    v12->mNext = p_m_pAIEntityComponent;
    p_m_pAIEntityComponent->mPrev = v12;
    this->m_pAIEntityComponent.mNext = &v6->m_SafePointerList.mNode;
    v6->m_SafePointerList.mNode.mPrev = p_m_pAIEntityComponent;
  }
  v13 = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  if ( v13 )
  {
    v14 = v13->m_Flags;
    if ( (v14 & 0x4000) != 0 )
    {
      m_pComponent = v13->m_Components.p[20].m_pComponent;
    }
    else if ( v14 >= 0 )
    {
      if ( (v14 & 0x2000) != 0 || (v14 & 0x1000) != 0 )
        ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        ComponentOfType = UFG::SimObject::GetComponentOfType(v13, UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = ComponentOfType;
    }
    else
    {
      m_pComponent = v13->m_Components.p[20].m_pComponent;
    }
  }
  p_m_pTargetingSystemBaseComponent = &this->m_pTargetingSystemBaseComponent;
  if ( this->m_pTargetingSystemBaseComponent.m_pPointer )
  {
    v17 = p_m_pTargetingSystemBaseComponent->mPrev;
    v18 = this->m_pTargetingSystemBaseComponent.mNext;
    v17->mNext = v18;
    v18->mPrev = v17;
    p_m_pTargetingSystemBaseComponent->mPrev = p_m_pTargetingSystemBaseComponent;
    this->m_pTargetingSystemBaseComponent.mNext = &this->m_pTargetingSystemBaseComponent;
  }
  this->m_pTargetingSystemBaseComponent.m_pPointer = m_pComponent;
  if ( m_pComponent )
  {
    v19 = m_pComponent->m_SafePointerList.mNode.mPrev;
    v19->mNext = p_m_pTargetingSystemBaseComponent;
    p_m_pTargetingSystemBaseComponent->mPrev = v19;
    this->m_pTargetingSystemBaseComponent.mNext = &m_pComponent->m_SafePointerList.mNode;
    m_pComponent->m_SafePointerList.mNode.mPrev = p_m_pTargetingSystemBaseComponent;
  }
  v20 = this->m_pTargetingSystemBaseComponent.m_pPointer;
  if ( v20 )
  {
    v21 = *(_QWORD *)(56i64 * *(unsigned __int8 *)(LOBYTE(this->m_Track[1].vfptr) + *(_QWORD *)&v20[1].m_Flags + 8i64)
                    + *(_QWORD *)&v20[1].m_TypeUID
                    + 40);
    if ( v21 )
    {
      v22 = *(UFG::SimComponent **)(v21 + 88);
      p_m_pTargetTransformNodeComponent = &this->m_pTargetTransformNodeComponent;
      if ( this->m_pTargetTransformNodeComponent.m_pPointer )
      {
        v24 = p_m_pTargetTransformNodeComponent->mPrev;
        v25 = this->m_pTargetTransformNodeComponent.mNext;
        v24->mNext = v25;
        v25->mPrev = v24;
        p_m_pTargetTransformNodeComponent->mPrev = p_m_pTargetTransformNodeComponent;
        this->m_pTargetTransformNodeComponent.mNext = &this->m_pTargetTransformNodeComponent;
      }
      this->m_pTargetTransformNodeComponent.m_pPointer = v22;
      if ( v22 )
      {
        v26 = v22->m_SafePointerList.mNode.mPrev;
        v26->mNext = p_m_pTargetTransformNodeComponent;
        p_m_pTargetTransformNodeComponent->mPrev = v26;
        this->m_pTargetTransformNodeComponent.mNext = &v22->m_SafePointerList.mNode;
        v22->m_SafePointerList.mNode.mPrev = p_m_pTargetTransformNodeComponent;
      }
    }
  }
}

// File Line: 3840
// RVA: 0x390A40
char __fastcall MoveDirectlyToTargetTask::Update(MoveDirectlyToTargetTask *this, float timestep)
{
  __int64 v3; // r8
  UFG::SimComponent *v4; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_m_pTargetTransformNodeComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rax
  unsigned int *m_pPointer; // rsi
  UFG::SimObject *v10; // rcx
  UFG::NavComponent *m_pComponent; // rdi
  UFG::SimObject *v12; // rbp
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbp
  ITrack *m_Track; // rax
  float v16; // xmm6_4
  UFG::SimObjectGame *v17; // rcx
  __int16 m_Flags; // dx
  unsigned int v19; // edx
  UFG::SimComponent *ComponentOfType; // rax
  bool v21; // zf
  __m128 v22; // xmm0
  __m128 v23; // xmm4
  __m128 v24; // xmm2
  UFG::HavokNavPosition npDestination; // [rsp+30h] [rbp-58h] BYREF

  if ( !this->m_pTargetTransformNodeComponent.m_pPointer )
  {
    v3 = *(_QWORD *)(56i64
                   * *(unsigned __int8 *)(LOBYTE(this->m_Track[1].vfptr)
                                        + *(_QWORD *)&this->m_pTargetingSystemBaseComponent.m_pPointer[1].m_Flags
                                        + 8i64)
                   + *(_QWORD *)&this->m_pTargetingSystemBaseComponent.m_pPointer[1].m_TypeUID
                   + 40);
    if ( v3 )
    {
      v4 = *(UFG::SimComponent **)(v3 + 88);
      p_m_pTargetTransformNodeComponent = &this->m_pTargetTransformNodeComponent;
      if ( this->m_pTargetTransformNodeComponent.m_pPointer )
      {
        mPrev = p_m_pTargetTransformNodeComponent->mPrev;
        mNext = p_m_pTargetTransformNodeComponent->mNext;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        p_m_pTargetTransformNodeComponent->mPrev = p_m_pTargetTransformNodeComponent;
        p_m_pTargetTransformNodeComponent->mNext = p_m_pTargetTransformNodeComponent;
      }
      p_m_pTargetTransformNodeComponent->m_pPointer = v4;
      if ( v4 )
      {
        v8 = v4->m_SafePointerList.mNode.mPrev;
        v8->mNext = p_m_pTargetTransformNodeComponent;
        p_m_pTargetTransformNodeComponent->mPrev = v8;
        p_m_pTargetTransformNodeComponent->mNext = &v4->m_SafePointerList.mNode;
        v4->m_SafePointerList.mNode.mPrev = p_m_pTargetTransformNodeComponent;
      }
    }
  }
  m_pPointer = (unsigned int *)this->m_pTargetTransformNodeComponent.m_pPointer;
  if ( !m_pPointer )
    return 1;
  if ( !this->m_pAIEntityComponent.m_pPointer )
    return 1;
  v10 = this->m_pActionContext->mSimObject.m_pPointer;
  if ( !v10 || !v10->m_pTransformNodeComponent )
    return 1;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->m_pTargetTransformNodeComponent.m_pPointer);
  m_pComponent = 0i64;
  v12 = this->m_pActionContext->mSimObject.m_pPointer;
  if ( v12 )
    m_pTransformNodeComponent = v12->m_pTransformNodeComponent;
  else
    m_pTransformNodeComponent = 0i64;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  m_Track = this->m_Track;
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(m_pTransformNodeComponent->mWorldTransform.v3.z - *((float *)m_pPointer + 46)) & _xmm) > *(float *)&m_Track[1].mResourceOwner
    || (float)((float)((float)(m_pTransformNodeComponent->mWorldTransform.v3.y - *((float *)m_pPointer + 45))
                     * (float)(m_pTransformNodeComponent->mWorldTransform.v3.y - *((float *)m_pPointer + 45)))
             + (float)((float)(m_pTransformNodeComponent->mWorldTransform.v3.x - *((float *)m_pPointer + 44))
                     * (float)(m_pTransformNodeComponent->mWorldTransform.v3.x - *((float *)m_pPointer + 44)))) > (float)(*((float *)&m_Track[1].vfptr + 1) * *((float *)&m_Track[1].vfptr + 1)) )
  {
    v16 = sNaturalMovementSpeeds[BYTE2(m_Track[1].vfptr)];
    v17 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
    if ( !v17 )
    {
LABEL_28:
      v22 = (__m128)m_pPointer[46];
      v23 = (__m128)m_pPointer[44];
      v24 = (__m128)m_pPointer[45];
      npDestination.m_bValid = 0;
      LODWORD(npDestination.m_vPosition.x) = v23.m128_i32[0];
      LODWORD(npDestination.m_vPosition.y) = v24.m128_i32[0];
      npDestination.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
      *(_QWORD *)&npDestination.m_packedKey = -1i64;
      LODWORD(npDestination.m_vPosition.z) = v22.m128_i32[0];
      npDestination.m_hkvMeshPosition.m_quad = _mm_unpacklo_ps(
                                                 _mm_unpacklo_ps(v23, v22),
                                                 _mm_unpacklo_ps(v24, (__m128)(unsigned int)FLOAT_1_0));
      UFG::NavComponent::AddGoalPoint(m_pComponent, &npDestination, AiGoal_Replace_Direct, v16, 0.30000001);
      return 1;
    }
    m_Flags = v17->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::NavComponent *)v17->m_Components.p[36].m_pComponent;
      goto LABEL_28;
    }
    if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 )
    {
      v19 = UFG::NavComponent::_TypeUID;
    }
    else
    {
      v21 = (m_Flags & 0x1000) == 0;
      v19 = UFG::NavComponent::_TypeUID;
      if ( v21 )
      {
        ComponentOfType = UFG::SimObject::GetComponentOfType(v17, UFG::NavComponent::_TypeUID);
        goto LABEL_27;
      }
    }
    ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v17, v19);
LABEL_27:
    m_pComponent = (UFG::NavComponent *)ComponentOfType;
    goto LABEL_28;
  }
  return 1;
}

// File Line: 3919
// RVA: 0x32E6B0
void __fastcall FollowTargetTask::FollowTargetTask(FollowTargetTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pAIEntityComponent; // rax
  __int64 v3; // rcx
  float *m_LastTimeSideBecameFree; // rdx
  float *p_z; // rax
  float y; // xmm1_4
  float z; // xmm2_4

  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<FollowTargetTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&FollowTargetTask::`vftable;
  p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.mPrev = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
  v3 = 0i64;
  p_m_pAIEntityComponent->m_pPointer = 0i64;
  this->m_pTransformNodeComponent.mPrev = &this->m_pTransformNodeComponent;
  this->m_pTransformNodeComponent.mNext = &this->m_pTransformNodeComponent;
  this->m_pTransformNodeComponent.m_pPointer = 0i64;
  this->m_pTargetingSystemBaseComponent.mPrev = &this->m_pTargetingSystemBaseComponent;
  this->m_pTargetingSystemBaseComponent.mNext = &this->m_pTargetingSystemBaseComponent;
  this->m_pTargetingSystemBaseComponent.m_pPointer = 0i64;
  this->m_pTargetTransformNodeComponent.mPrev = &this->m_pTargetTransformNodeComponent;
  this->m_pTargetTransformNodeComponent.mNext = &this->m_pTargetTransformNodeComponent;
  this->m_pTargetTransformNodeComponent.m_pPointer = 0i64;
  this->m_pTargetActionTreeComponent.mPrev = &this->m_pTargetActionTreeComponent;
  this->m_pTargetActionTreeComponent.mNext = &this->m_pTargetActionTreeComponent;
  this->m_pTargetActionTreeComponent.m_pPointer = 0i64;
  this->m_pTargetAIEntityComponent.mPrev = &this->m_pTargetAIEntityComponent;
  this->m_pTargetAIEntityComponent.mNext = &this->m_pTargetAIEntityComponent;
  this->m_pTargetAIEntityComponent.m_pPointer = 0i64;
  *(_QWORD *)&this->m_MovementType = 0i64;
  m_LastTimeSideBecameFree = this->m_LastTimeSideBecameFree;
  p_z = &this->m_PositionOfSide[0].z;
  do
  {
    this->m_SideIsFree[v3] = 0;
    *m_LastTimeSideBecameFree = -99999.0;
    y = UFG::qVector3::msZero.y;
    z = UFG::qVector3::msZero.z;
    *(p_z - 2) = UFG::qVector3::msZero.x;
    *(p_z - 1) = y;
    *p_z = z;
    ++v3;
    ++m_LastTimeSideBecameFree;
    p_z += 3;
  }
  while ( v3 < 3 );
  this->m_TimeToChangeMovementType = -1.0;
}

// File Line: 3935
// RVA: 0x336DC0
void __fastcall FollowTargetTask::~FollowTargetTask(FollowTargetTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::AIEntityComponent> *p_m_pTargetAIEntityComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActionTreeComponent> *p_m_pTargetActionTreeComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_m_pTargetTransformNodeComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *p_m_pTargetingSystemBaseComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v21; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_m_pTransformNodeComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v23; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v24; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v25; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v26; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pAIEntityComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v28; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v29; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v30; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v31; // rax
  UFG::qNode<ITask,ITask> *v32; // rcx
  UFG::qNode<ITask,ITask> *v33; // rax

  this->vfptr = (ITaskVtbl *)&FollowTargetTask::`vftable;
  p_m_pTargetAIEntityComponent = &this->m_pTargetAIEntityComponent;
  if ( this->m_pTargetAIEntityComponent.m_pPointer )
  {
    mPrev = p_m_pTargetAIEntityComponent->mPrev;
    mNext = p_m_pTargetAIEntityComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pTargetAIEntityComponent->mPrev = p_m_pTargetAIEntityComponent;
    p_m_pTargetAIEntityComponent->mNext = p_m_pTargetAIEntityComponent;
  }
  p_m_pTargetAIEntityComponent->m_pPointer = 0i64;
  v5 = p_m_pTargetAIEntityComponent->mPrev;
  v6 = p_m_pTargetAIEntityComponent->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_m_pTargetAIEntityComponent->mPrev = p_m_pTargetAIEntityComponent;
  p_m_pTargetAIEntityComponent->mNext = p_m_pTargetAIEntityComponent;
  p_m_pTargetActionTreeComponent = &this->m_pTargetActionTreeComponent;
  if ( this->m_pTargetActionTreeComponent.m_pPointer )
  {
    v8 = p_m_pTargetActionTreeComponent->mPrev;
    v9 = this->m_pTargetActionTreeComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    p_m_pTargetActionTreeComponent->mPrev = p_m_pTargetActionTreeComponent;
    this->m_pTargetActionTreeComponent.mNext = &this->m_pTargetActionTreeComponent;
  }
  this->m_pTargetActionTreeComponent.m_pPointer = 0i64;
  v10 = p_m_pTargetActionTreeComponent->mPrev;
  v11 = this->m_pTargetActionTreeComponent.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  p_m_pTargetActionTreeComponent->mPrev = p_m_pTargetActionTreeComponent;
  this->m_pTargetActionTreeComponent.mNext = &this->m_pTargetActionTreeComponent;
  p_m_pTargetTransformNodeComponent = &this->m_pTargetTransformNodeComponent;
  if ( this->m_pTargetTransformNodeComponent.m_pPointer )
  {
    v13 = p_m_pTargetTransformNodeComponent->mPrev;
    v14 = this->m_pTargetTransformNodeComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    p_m_pTargetTransformNodeComponent->mPrev = p_m_pTargetTransformNodeComponent;
    this->m_pTargetTransformNodeComponent.mNext = &this->m_pTargetTransformNodeComponent;
  }
  this->m_pTargetTransformNodeComponent.m_pPointer = 0i64;
  v15 = p_m_pTargetTransformNodeComponent->mPrev;
  v16 = this->m_pTargetTransformNodeComponent.mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  p_m_pTargetTransformNodeComponent->mPrev = p_m_pTargetTransformNodeComponent;
  this->m_pTargetTransformNodeComponent.mNext = &this->m_pTargetTransformNodeComponent;
  p_m_pTargetingSystemBaseComponent = &this->m_pTargetingSystemBaseComponent;
  if ( this->m_pTargetingSystemBaseComponent.m_pPointer )
  {
    v18 = p_m_pTargetingSystemBaseComponent->mPrev;
    v19 = this->m_pTargetingSystemBaseComponent.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    p_m_pTargetingSystemBaseComponent->mPrev = p_m_pTargetingSystemBaseComponent;
    this->m_pTargetingSystemBaseComponent.mNext = &this->m_pTargetingSystemBaseComponent;
  }
  this->m_pTargetingSystemBaseComponent.m_pPointer = 0i64;
  v20 = p_m_pTargetingSystemBaseComponent->mPrev;
  v21 = this->m_pTargetingSystemBaseComponent.mNext;
  v20->mNext = v21;
  v21->mPrev = v20;
  p_m_pTargetingSystemBaseComponent->mPrev = p_m_pTargetingSystemBaseComponent;
  this->m_pTargetingSystemBaseComponent.mNext = &this->m_pTargetingSystemBaseComponent;
  p_m_pTransformNodeComponent = &this->m_pTransformNodeComponent;
  if ( this->m_pTransformNodeComponent.m_pPointer )
  {
    v23 = p_m_pTransformNodeComponent->mPrev;
    v24 = this->m_pTransformNodeComponent.mNext;
    v23->mNext = v24;
    v24->mPrev = v23;
    p_m_pTransformNodeComponent->mPrev = p_m_pTransformNodeComponent;
    this->m_pTransformNodeComponent.mNext = &this->m_pTransformNodeComponent;
  }
  this->m_pTransformNodeComponent.m_pPointer = 0i64;
  v25 = p_m_pTransformNodeComponent->mPrev;
  v26 = this->m_pTransformNodeComponent.mNext;
  v25->mNext = v26;
  v26->mPrev = v25;
  p_m_pTransformNodeComponent->mPrev = p_m_pTransformNodeComponent;
  this->m_pTransformNodeComponent.mNext = &this->m_pTransformNodeComponent;
  p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
  if ( this->m_pAIEntityComponent.m_pPointer )
  {
    v28 = p_m_pAIEntityComponent->mPrev;
    v29 = this->m_pAIEntityComponent.mNext;
    v28->mNext = v29;
    v29->mPrev = v28;
    p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
    this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
  }
  this->m_pAIEntityComponent.m_pPointer = 0i64;
  v30 = p_m_pAIEntityComponent->mPrev;
  v31 = this->m_pAIEntityComponent.mNext;
  v30->mNext = v31;
  v31->mPrev = v30;
  p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
  this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v32 = this->mPrev;
  v33 = this->mNext;
  v32->mNext = v33;
  v33->mPrev = v32;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 3940
// RVA: 0x344EB0
void __fastcall FollowTargetTask::Begin(FollowTargetTask *this, ActionContext *action_context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::SimComponent *v5; // r8
  __int16 m_Flags; // dx
  UFG::ActiveAIEntityComponent *ComponentOfTypeHK; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pAIEntityComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::SimObjectGame *v12; // rcx
  UFG::SimComponent *m_pComponent; // r8
  __int16 v14; // dx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *p_m_pTargetingSystemBaseComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::SimObject *v20; // r8
  UFG::SimComponent *m_pTransformNodeComponent; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_m_pTransformNodeComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v23; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v24; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v25; // rax
  UFG::SimComponent *v26; // r8
  UFG::SimObjectCVBase *v27; // rdi
  UFG::SimComponent *v28; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_m_pTargetTransformNodeComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v30; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v31; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v32; // rax
  __int16 v33; // cx
  UFG::SimComponent *v34; // rdx
  UFG::SimComponent *v35; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActionTreeComponent> *p_m_pTargetActionTreeComponent; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v37; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v38; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v39; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *p_mNode; // rdx
  __int16 v41; // cx
  UFG::ActiveAIEntityComponent *v42; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AIEntityComponent> *p_m_pTargetAIEntityComponent; // rdx
  UFG::SimComponent *v44; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v45; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v46; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v47; // rax

  this->m_pActionContext = action_context;
  m_pPointer = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
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
    v5 = ComponentOfTypeHK;
  }
  else
  {
    v5 = 0i64;
  }
  p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
  if ( this->m_pAIEntityComponent.m_pPointer )
  {
    mPrev = p_m_pAIEntityComponent->mPrev;
    mNext = this->m_pAIEntityComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
    this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
  }
  this->m_pAIEntityComponent.m_pPointer = v5;
  if ( v5 )
  {
    v11 = v5->m_SafePointerList.mNode.mPrev;
    v11->mNext = p_m_pAIEntityComponent;
    p_m_pAIEntityComponent->mPrev = v11;
    this->m_pAIEntityComponent.mNext = &v5->m_SafePointerList.mNode;
    v5->m_SafePointerList.mNode.mPrev = p_m_pAIEntityComponent;
  }
  v12 = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  if ( v12 )
  {
    v14 = v12->m_Flags;
    if ( (v14 & 0x4000) != 0 )
    {
      m_pComponent = v12->m_Components.p[20].m_pComponent;
    }
    else if ( v14 >= 0 )
    {
      if ( (v14 & 0x2000) != 0 || (v14 & 0x1000) != 0 )
        ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        ComponentOfType = UFG::SimObject::GetComponentOfType(v12, UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = ComponentOfType;
    }
    else
    {
      m_pComponent = v12->m_Components.p[20].m_pComponent;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  p_m_pTargetingSystemBaseComponent = &this->m_pTargetingSystemBaseComponent;
  if ( this->m_pTargetingSystemBaseComponent.m_pPointer )
  {
    v17 = p_m_pTargetingSystemBaseComponent->mPrev;
    v18 = this->m_pTargetingSystemBaseComponent.mNext;
    v17->mNext = v18;
    v18->mPrev = v17;
    p_m_pTargetingSystemBaseComponent->mPrev = p_m_pTargetingSystemBaseComponent;
    this->m_pTargetingSystemBaseComponent.mNext = &this->m_pTargetingSystemBaseComponent;
  }
  this->m_pTargetingSystemBaseComponent.m_pPointer = m_pComponent;
  if ( m_pComponent )
  {
    v19 = m_pComponent->m_SafePointerList.mNode.mPrev;
    v19->mNext = p_m_pTargetingSystemBaseComponent;
    p_m_pTargetingSystemBaseComponent->mPrev = v19;
    this->m_pTargetingSystemBaseComponent.mNext = &m_pComponent->m_SafePointerList.mNode;
    m_pComponent->m_SafePointerList.mNode.mPrev = p_m_pTargetingSystemBaseComponent;
  }
  v20 = action_context->mSimObject.m_pPointer;
  if ( v20 )
    m_pTransformNodeComponent = v20->m_pTransformNodeComponent;
  else
    m_pTransformNodeComponent = 0i64;
  p_m_pTransformNodeComponent = &this->m_pTransformNodeComponent;
  if ( this->m_pTransformNodeComponent.m_pPointer )
  {
    v23 = p_m_pTransformNodeComponent->mPrev;
    v24 = this->m_pTransformNodeComponent.mNext;
    v23->mNext = v24;
    v24->mPrev = v23;
    p_m_pTransformNodeComponent->mPrev = p_m_pTransformNodeComponent;
    this->m_pTransformNodeComponent.mNext = &this->m_pTransformNodeComponent;
  }
  this->m_pTransformNodeComponent.m_pPointer = m_pTransformNodeComponent;
  if ( m_pTransformNodeComponent )
  {
    v25 = m_pTransformNodeComponent->m_SafePointerList.mNode.mPrev;
    v25->mNext = p_m_pTransformNodeComponent;
    p_m_pTransformNodeComponent->mPrev = v25;
    this->m_pTransformNodeComponent.mNext = &m_pTransformNodeComponent->m_SafePointerList.mNode;
    m_pTransformNodeComponent->m_SafePointerList.mNode.mPrev = p_m_pTransformNodeComponent;
  }
  v26 = this->m_pTargetingSystemBaseComponent.m_pPointer;
  if ( v26 )
  {
    v27 = *(UFG::SimObjectCVBase **)(56i64
                                   * *(unsigned __int8 *)(LOBYTE(this->m_Track[1].vfptr)
                                                        + *(_QWORD *)&v26[1].m_Flags
                                                        + 8i64)
                                   + *(_QWORD *)&v26[1].m_TypeUID
                                   + 40);
    if ( v27 )
    {
      v28 = v27->m_pTransformNodeComponent;
      p_m_pTargetTransformNodeComponent = &this->m_pTargetTransformNodeComponent;
      if ( this->m_pTargetTransformNodeComponent.m_pPointer )
      {
        v30 = p_m_pTargetTransformNodeComponent->mPrev;
        v31 = this->m_pTargetTransformNodeComponent.mNext;
        v30->mNext = v31;
        v31->mPrev = v30;
        p_m_pTargetTransformNodeComponent->mPrev = p_m_pTargetTransformNodeComponent;
        this->m_pTargetTransformNodeComponent.mNext = &this->m_pTargetTransformNodeComponent;
      }
      this->m_pTargetTransformNodeComponent.m_pPointer = v28;
      if ( v28 )
      {
        v32 = v28->m_SafePointerList.mNode.mPrev;
        v32->mNext = p_m_pTargetTransformNodeComponent;
        p_m_pTargetTransformNodeComponent->mPrev = v32;
        this->m_pTargetTransformNodeComponent.mNext = &v28->m_SafePointerList.mNode;
        v28->m_SafePointerList.mNode.mPrev = p_m_pTargetTransformNodeComponent;
      }
      v33 = v27->m_Flags;
      if ( (v33 & 0x4000) != 0 )
      {
        v34 = v27->m_Components.p[7].m_pComponent;
      }
      else if ( v33 >= 0 )
      {
        if ( (v33 & 0x2000) != 0 )
        {
          v34 = v27->m_Components.p[6].m_pComponent;
        }
        else
        {
          if ( (v33 & 0x1000) != 0 )
            v35 = UFG::SimObjectGame::GetComponentOfTypeHK(v27, UFG::ActionTreeComponent::_TypeUID);
          else
            v35 = UFG::SimObject::GetComponentOfType(v27, UFG::ActionTreeComponent::_TypeUID);
          v34 = v35;
        }
      }
      else
      {
        v34 = v27->m_Components.p[7].m_pComponent;
      }
      p_m_pTargetActionTreeComponent = &this->m_pTargetActionTreeComponent;
      if ( this->m_pTargetActionTreeComponent.m_pPointer )
      {
        v37 = p_m_pTargetActionTreeComponent->mPrev;
        v38 = this->m_pTargetActionTreeComponent.mNext;
        v37->mNext = v38;
        v38->mPrev = v37;
        p_m_pTargetActionTreeComponent->mPrev = p_m_pTargetActionTreeComponent;
        this->m_pTargetActionTreeComponent.mNext = &this->m_pTargetActionTreeComponent;
      }
      this->m_pTargetActionTreeComponent.m_pPointer = v34;
      if ( v34 )
      {
        v39 = v34->m_SafePointerList.mNode.mPrev;
        p_mNode = &v34->m_SafePointerList.mNode;
        v39->mNext = p_m_pTargetActionTreeComponent;
        p_m_pTargetActionTreeComponent->mPrev = v39;
        this->m_pTargetActionTreeComponent.mNext = p_mNode;
        p_mNode->mPrev = p_m_pTargetActionTreeComponent;
      }
      v41 = v27->m_Flags;
      if ( (v41 & 0x4000) != 0 || v41 < 0 )
      {
        v42 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v27);
      }
      else if ( (v41 & 0x2000) != 0 || (v41 & 0x1000) != 0 )
      {
        v42 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                v27,
                                                UFG::ActiveAIEntityComponent::_TypeUID);
      }
      else
      {
        v42 = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                v27,
                                                UFG::ActiveAIEntityComponent::_TypeUID);
      }
      p_m_pTargetAIEntityComponent = &this->m_pTargetAIEntityComponent;
      v44 = v42;
      if ( this->m_pTargetAIEntityComponent.m_pPointer )
      {
        v45 = p_m_pTargetAIEntityComponent->mPrev;
        v46 = this->m_pTargetAIEntityComponent.mNext;
        v45->mNext = v46;
        v46->mPrev = v45;
        p_m_pTargetAIEntityComponent->mPrev = p_m_pTargetAIEntityComponent;
        this->m_pTargetAIEntityComponent.mNext = &this->m_pTargetAIEntityComponent;
      }
      this->m_pTargetAIEntityComponent.m_pPointer = v44;
      if ( v44 )
      {
        v47 = v44->m_SafePointerList.mNode.mPrev;
        v47->mNext = p_m_pTargetAIEntityComponent;
        p_m_pTargetAIEntityComponent->mPrev = v47;
        this->m_pTargetAIEntityComponent.mNext = &v44->m_SafePointerList.mNode;
        v44->m_SafePointerList.mNode.mPrev = p_m_pTargetAIEntityComponent;
      }
    }
  }
  this->m_MovementType = eMoveType_None;
  this->m_TimeToChangeMovementType = -1.0;
}

// File Line: 4009
// RVA: 0x3987E0
void __fastcall FollowTargetTask::UpdateSides(FollowTargetTask *this)
{
  UFG::TransformNodeComponent *m_pPointer; // rsi
  float mSimTime_Temp; // xmm8_4
  UFG::SimComponent *v4; // rbx
  float v5; // xmm7_4
  __m128 mNext_high; // xmm6
  eFollowTargetSide v7; // r15d
  UFG::BaseCameraComponent *mCurrentCamera; // rax
  UFG::BaseCameraComponent *v9; // rax
  UFG::Camera *p_mCamera; // rax
  float v11; // xmm2_4
  __m128 v12; // xmm1
  float v13; // xmm2_4
  float v14; // xmm3_4
  float x; // xmm7_4
  float y; // xmm6_4
  float z; // xmm3_4
  eFollowTargetSide v18; // ebp
  bool *m_SideIsFree; // rbx
  UFG::qVector3 *m_PositionOfSide; // r14
  __int64 v21; // r12
  float v22; // xmm1_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm0_4
  float v26; // xmm0_4
  float v27; // xmm1_4
  float *m_LastTimeSideBecameFree; // rsi
  UFG::eConstrainToSidewalks v29; // r13d
  bool CanWalkStraightToPoint; // al
  UFG::SimComponent *v31; // rbx
  __int64 m_CurrentFollowTargetSide; // rcx
  __m128 mPrev_high; // xmm2
  float v34; // xmm3_4
  __m128 v35; // xmm0
  float v36; // xmm1_4
  float v37; // xmm3_4
  int v38; // xmm5_4
  __m128 v39; // xmm0
  int v40; // xmm4_4
  float v41; // xmm2_4
  int v42[4]; // [rsp+20h] [rbp-78h]

  m_pPointer = (UFG::TransformNodeComponent *)this->m_pTargetTransformNodeComponent.m_pPointer;
  if ( m_pPointer && this->m_pTargetAIEntityComponent.m_pPointer && this->m_pTransformNodeComponent.m_pPointer )
  {
    mSimTime_Temp = UFG::Metrics::msInstance.mSimTime_Temp;
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pPointer);
    v4 = this->m_pTargetTransformNodeComponent.m_pPointer;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v4);
    v5 = *(float *)&v4[2].m_SafePointerList.mNode.mNext;
    mNext_high = (__m128)HIDWORD(v4[2].m_SafePointerList.mNode.mNext);
    v7 = eFOLLOW_TARGET_LEFT_SIDE;
    mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
    if ( mCurrentCamera && mCurrentCamera != (UFG::BaseCameraComponent *)-80i64 )
    {
      v9 = UFG::Director::Get()->mCurrentCamera;
      if ( v9 )
        p_mCamera = &v9->mCamera;
      else
        p_mCamera = 0i64;
      mNext_high = (__m128)LODWORD(p_mCamera->mTransformation.v3.x);
      v11 = p_mCamera->mTransformation.v3.z - m_pPointer->mWorldTransform.v3.z;
      v5 = (float)(v11 * UFG::qVector3::msDirUp.y)
         - (float)((float)(p_mCamera->mTransformation.v3.y - m_pPointer->mWorldTransform.v3.y) * UFG::qVector3::msDirUp.z);
      mNext_high.m128_f32[0] = (float)((float)(mNext_high.m128_f32[0] - m_pPointer->mWorldTransform.v3.x)
                                     * UFG::qVector3::msDirUp.z)
                             - (float)(v11 * UFG::qVector3::msDirUp.x);
    }
    v12 = mNext_high;
    v12.m128_f32[0] = (float)(mNext_high.m128_f32[0] * mNext_high.m128_f32[0]) + (float)(v5 * v5);
    v13 = _mm_sqrt_ps(v12).m128_f32[0];
    if ( v13 <= 0.001 )
    {
      x = UFG::qVector3::msZero.x;
      y = UFG::qVector3::msZero.y;
      z = UFG::qVector3::msZero.z;
    }
    else
    {
      v14 = *(float *)&this->m_Track[1].mBreakPoint / v13;
      x = v5 * v14;
      y = mNext_high.m128_f32[0] * v14;
      z = v14 * 0.0;
    }
    v18 = eFOLLOW_TARGET_NO_SIDE;
    m_SideIsFree = this->m_SideIsFree;
    m_PositionOfSide = this->m_PositionOfSide;
    v21 = 2i64;
    v22 = y + m_pPointer->mWorldTransform.v3.y;
    v23 = z + m_pPointer->mWorldTransform.v3.z;
    this->m_PositionOfSide[0].x = x + m_pPointer->mWorldTransform.v3.x;
    this->m_PositionOfSide[0].y = v22;
    this->m_PositionOfSide[0].z = v23;
    v24 = m_pPointer->mWorldTransform.v3.y - y;
    v25 = m_pPointer->mWorldTransform.v3.z - z;
    this->m_PositionOfSide[1].x = m_pPointer->mWorldTransform.v3.x - x;
    this->m_PositionOfSide[1].y = v24;
    this->m_PositionOfSide[1].z = v25;
    v26 = m_pPointer->mWorldTransform.v3.y;
    v27 = m_pPointer->mWorldTransform.v3.z;
    this->m_PositionOfSide[2].x = m_pPointer->mWorldTransform.v3.x;
    m_LastTimeSideBecameFree = this->m_LastTimeSideBecameFree;
    this->m_PositionOfSide[2].y = v26;
    this->m_PositionOfSide[2].z = v27;
    v29 = *((unsigned __int8 *)&this->m_Track[1].mMasterRate.value + 4);
    do
    {
      CanWalkStraightToPoint = UFG::AIEntityComponent::CanWalkStraightToPoint(
                                 (UFG::AIEntityComponent *)this->m_pTargetAIEntityComponent.m_pPointer,
                                 m_PositionOfSide,
                                 v29,
                                 0i64);
      if ( !*m_SideIsFree && CanWalkStraightToPoint )
        *m_LastTimeSideBecameFree = mSimTime_Temp;
      *m_SideIsFree++ = CanWalkStraightToPoint;
      ++m_PositionOfSide;
      ++m_LastTimeSideBecameFree;
      --v21;
    }
    while ( v21 );
    this->m_SideIsFree[2] = 1;
    this->m_LastTimeSideBecameFree[2] = -99999.0;
    v31 = this->m_pTransformNodeComponent.m_pPointer;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v31);
    m_CurrentFollowTargetSide = this->m_CurrentFollowTargetSide;
    mPrev_high = (__m128)HIDWORD(v31[2].m_BoundComponentHandles.mNode.mPrev);
    v34 = *(float *)&v31[2].m_BoundComponentHandles.mNode.mPrev;
    v35 = mPrev_high;
    v35.m128_f32[0] = (float)((float)(v35.m128_f32[0] - this->m_PositionOfSide[0].y)
                            * (float)(v35.m128_f32[0] - this->m_PositionOfSide[0].y))
                    + (float)((float)(v34 - this->m_PositionOfSide[0].x) * (float)(v34 - this->m_PositionOfSide[0].x));
    v36 = v34 - this->m_PositionOfSide[1].x;
    v37 = v34 - this->m_PositionOfSide[2].x;
    v38 = _mm_sqrt_ps(v35).m128_u32[0];
    v39 = mPrev_high;
    v39.m128_f32[0] = mPrev_high.m128_f32[0] - this->m_PositionOfSide[1].y;
    mPrev_high.m128_f32[0] = (float)(mPrev_high.m128_f32[0] - this->m_PositionOfSide[2].y)
                           * (float)(mPrev_high.m128_f32[0] - this->m_PositionOfSide[2].y);
    v42[0] = v38;
    v39.m128_f32[0] = (float)(v39.m128_f32[0] * v39.m128_f32[0]) + (float)(v36 * v36);
    v40 = _mm_sqrt_ps(v39).m128_u32[0];
    mPrev_high.m128_f32[0] = mPrev_high.m128_f32[0] + (float)(v37 * v37);
    v42[1] = v40;
    v42[2] = _mm_sqrt_ps(mPrev_high).m128_u32[0];
    if ( (_DWORD)m_CurrentFollowTargetSide == 2 )
    {
      v41 = FLOAT_N1_0;
      if ( this->m_SideIsFree[0]
        && (float)(UFG::Metrics::msInstance.mSimTime_Temp - this->m_LastTimeSideBecameFree[0]) > 2.0 )
      {
        v18 = eFOLLOW_TARGET_LEFT_SIDE;
        v41 = *(float *)&v38;
      }
      if ( this->m_SideIsFree[1]
        && (float)(UFG::Metrics::msInstance.mSimTime_Temp - this->m_LastTimeSideBecameFree[1]) > 2.0
        && (*(float *)&v40 < v41 || v41 < 0.0) )
      {
        v18 = eFOLLOW_TARGET_RIGHT_SIDE;
      }
      goto LABEL_27;
    }
    if ( !this->m_SideIsFree[m_CurrentFollowTargetSide]
      || (float)(UFG::Metrics::msInstance.mSimTime_Temp - this->m_LastTimeSideBecameFree[m_CurrentFollowTargetSide]) <= 2.0 )
    {
      if ( (_DWORD)m_CurrentFollowTargetSide )
      {
        if ( (_DWORD)m_CurrentFollowTargetSide != 1 )
          v7 = eFOLLOW_TARGET_NO_SIDE;
      }
      else
      {
        v7 = eFOLLOW_TARGET_RIGHT_SIDE;
      }
      if ( this->m_SideIsFree[v7]
        && (float)(UFG::Metrics::msInstance.mSimTime_Temp - this->m_LastTimeSideBecameFree[v7]) > 2.0 )
      {
        this->m_CurrentFollowTargetSide = v7;
        return;
      }
      goto LABEL_27;
    }
    if ( (_DWORD)m_CurrentFollowTargetSide )
    {
      if ( (_DWORD)m_CurrentFollowTargetSide == 1 )
        v18 = eFOLLOW_TARGET_LEFT_SIDE;
    }
    else
    {
      v18 = eFOLLOW_TARGET_RIGHT_SIDE;
    }
    if ( this->m_SideIsFree[v18]
      && (float)(UFG::Metrics::msInstance.mSimTime_Temp - this->m_LastTimeSideBecameFree[v18]) > 2.0
      && (float)(*(float *)&v42[m_CurrentFollowTargetSide] - 2.0) > *(float *)&v42[v18] )
    {
LABEL_27:
      this->m_CurrentFollowTargetSide = v18;
    }
  }
}float *)&v42[v18] )
    {
LABEL_27:
      this->m_CurrentFollowTargetSide = v18;
    }
  }
}

// File Line: 4165
// RVA: 0x38ED10
char __fastcall FollowTargetTask::Update(FollowTargetTask *this, float timestep)
{
  UFG::SimComponent *m_pPointer; // rdi
  UFG::TransformNodeComponent *v4; // rbx
  __m128 mPrev_low; // xmm1
  float v6; // xmm9_4
  float v7; // xmm8_4
  unsigned int MostUsedIndex; // r8d
  float *m_Track; // rax
  float v10; // xmm7_4
  float v11; // xmm6_4
  char v12; // r14
  unsigned __int8 IsPlaying; // bp
  UFG::TransformNodeComponent *v14; // rdi
  UFG::TransformNodeComponent *v15; // rbx
  double v16; // xmm0_8
  bool v17; // al
  UFG::eMoveType m_MovementType; // ecx
  float v19; // xmm6_4
  UFG::NavComponent *m_pComponent; // rbx
  UFG::eMoveType v21; // edi
  float mSimTime_Temp; // xmm7_4
  __int64 v23; // rdi
  UFG::SimObjectGame *v24; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  float v27; // xmm3_4
  UFG::SimComponent *v28; // rbp
  UFG::SimObjectCVBase *v29; // rcx
  __int16 v30; // dx
  UFG::AICharacterControllerBaseComponent *v31; // rax
  float *v32; // rdi
  UFG::TransformNodeComponent *v33; // rbx
  float v34; // xmm3_4
  __m128 mPrev_high; // xmm4
  float v36; // xmm5_4
  __m128 v37; // xmm2
  UFG::HavokNavPosition npDestination; // [rsp+40h] [rbp-98h] BYREF
  unsigned int uid; // [rsp+E0h] [rbp+8h] BYREF

  m_pPointer = this->m_pTargetTransformNodeComponent.m_pPointer;
  if ( !m_pPointer || !this->m_pTransformNodeComponent.m_pPointer || !this->m_pTargetActionTreeComponent.m_pPointer )
    return 1;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->m_pTargetTransformNodeComponent.m_pPointer);
  v4 = (UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pPointer;
  UFG::TransformNodeComponent::UpdateWorldTransform(v4);
  mPrev_low = (__m128)LODWORD(m_pPointer[2].m_BoundComponentHandles.mNode.mPrev);
  mPrev_low.m128_f32[0] = (float)((float)(mPrev_low.m128_f32[0] - v4->mWorldTransform.v3.x)
                                * (float)(mPrev_low.m128_f32[0] - v4->mWorldTransform.v3.x))
                        + (float)((float)(*((float *)&m_pPointer[2].m_BoundComponentHandles.mNode.mPrev + 1)
                                        - v4->mWorldTransform.v3.y)
                                * (float)(*((float *)&m_pPointer[2].m_BoundComponentHandles.mNode.mPrev + 1)
                                        - v4->mWorldTransform.v3.y));
  v6 = _mm_sqrt_ps(mPrev_low).m128_f32[0];
  LODWORD(v7) = COERCE_UNSIGNED_INT(*(float *)&m_pPointer[2].m_BoundComponentHandles.mNode.mNext - v4->mWorldTransform.v3.z) & _xmm;
  if ( v6 > *((float *)&this->m_Track[1].mMasterRate.expression.mOffset + 1) )
  {
    FollowTargetTask::TeleportToTarget(this);
    return 1;
  }
  uid = UFG::qStringHashUpper32("Sprinting", -1);
  if ( (_S30 & 1) != 0 )
  {
    MostUsedIndex = mostUsedIndex_SprintingUID;
  }
  else
  {
    _S30 |= 1u;
    MostUsedIndex = GetMostUsedIndex(uid);
    mostUsedIndex_SprintingUID = MostUsedIndex;
  }
  m_Track = (float *)this->m_Track;
  v10 = m_Track[15];
  v11 = m_Track[16];
  if ( this->m_MovementType == eMoveType_None )
  {
    v10 = m_Track[17];
    v11 = m_Track[18];
  }
  v12 = 0;
  IsPlaying = ActionController::IsPlaying(
                (ActionController *)&this->m_pTargetActionTreeComponent.m_pPointer[3],
                (ActionID *)&uid,
                MostUsedIndex,
                1);
  v14 = (UFG::TransformNodeComponent *)this->m_pTargetTransformNodeComponent.m_pPointer;
  UFG::TransformNodeComponent::UpdateWorldTransform(v14);
  v15 = (UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pPointer;
  UFG::TransformNodeComponent::UpdateWorldTransform(v15);
  v16 = (float)((float)((float)(v15->mWorldTransform.v0.y * v14->mWorldTransform.v0.y)
                      + (float)(v15->mWorldTransform.v0.x * v14->mWorldTransform.v0.x))
              + (float)(v15->mWorldTransform.v0.z * v14->mWorldTransform.v0.z));
  v17 = v6 < v10 && v7 < v11;
  m_MovementType = this->m_MovementType;
  v19 = 0.0;
  m_pComponent = 0i64;
  if ( m_MovementType == eMoveType_Run && IsPlaying && v16 > -0.707 )
  {
    v21 = eMoveType_Run;
    if ( v17 )
      v12 = 1;
  }
  else
  {
    if ( v17 )
    {
      this->m_MovementType = eMoveType_None;
      goto LABEL_30;
    }
    v21 = (IsPlaying != 0) + 2;
  }
  if ( v21 > m_MovementType )
  {
    mSimTime_Temp = UFG::Metrics::msInstance.mSimTime_Temp;
    if ( this->m_TimeToChangeMovementType < 0.0 )
      this->m_TimeToChangeMovementType = UFG::GetRandomNumberInRange(
                                           *((float *)&this->m_Track[1].mMasterRate.text.mOffset + 1),
                                           *(float *)&this->m_Track[1].mMasterRate.expression.mOffset)
                                       + mSimTime_Temp;
    if ( mSimTime_Temp < this->m_TimeToChangeMovementType && this->m_MovementType )
      goto LABEL_30;
    this->m_MovementType = v21;
  }
  this->m_TimeToChangeMovementType = -1.0;
LABEL_30:
  if ( this->m_pAIEntityComponent.m_pPointer )
  {
    if ( this->m_MovementType )
    {
      FollowTargetTask::UpdateSides(this);
      v23 = 3 * ((int)this->m_CurrentFollowTargetSide + 18i64);
      v24 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
      if ( v24 )
      {
        m_Flags = v24->m_Flags;
        if ( (m_Flags & 0x4000) != 0 )
        {
          m_pComponent = (UFG::NavComponent *)v24->m_Components.p[36].m_pComponent;
        }
        else
        {
          if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
            ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v24, UFG::NavComponent::_TypeUID);
          else
            ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v24, UFG::NavComponent::_TypeUID);
          m_pComponent = (UFG::NavComponent *)ComponentOfTypeHK;
        }
      }
      v27 = sNaturalMovementSpeeds[this->m_MovementType];
      if ( v12 )
      {
        v27 = v27 - 2.0;
        if ( v27 <= 0.0 )
          v27 = 0.0;
      }
      npDestination.m_vPosition = *(UFG::qVector3 *)((char *)&this->vfptr + 4 * v23);
      npDestination.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
      npDestination.m_bValid = 0;
      *(_QWORD *)&npDestination.m_packedKey = -1i64;
      npDestination.m_hkvMeshPosition.m_quad = _mm_unpacklo_ps(
                                                 _mm_unpacklo_ps(
                                                   (__m128)LODWORD(npDestination.m_vPosition.x),
                                                   (__m128)LODWORD(npDestination.m_vPosition.z)),
                                                 _mm_unpacklo_ps(
                                                   (__m128)LODWORD(npDestination.m_vPosition.y),
                                                   (__m128)(unsigned int)FLOAT_1_0));
      UFG::NavComponent::AddGoalPoint(m_pComponent, &npDestination, AiGoal_Replace, v27, 0.30000001);
      UFG::NavComponent::IsAtDestination(m_pComponent);
    }
    else
    {
      v28 = this->m_pTargetTransformNodeComponent.m_pPointer;
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v28);
      v29 = (UFG::SimObjectCVBase *)this->m_pActionContext->mSimObject.m_pPointer;
      if ( v29 )
      {
        v30 = v29->m_Flags;
        if ( (v30 & 0x4000) != 0 || v30 < 0 )
          v31 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v29);
        else
          v31 = (UFG::AICharacterControllerBaseComponent *)((v30 & 0x2000) != 0 || (v30 & 0x1000) != 0
                                                          ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                              v29,
                                                              UFG::AICharacterControllerBaseComponent::_TypeUID)
                                                          : UFG::SimObject::GetComponentOfType(
                                                              v29,
                                                              UFG::AICharacterControllerBaseComponent::_TypeUID));
        v32 = (float *)v31;
        if ( v31 )
        {
          v33 = (UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pPointer;
          UFG::TransformNodeComponent::UpdateWorldTransform(v33);
          v34 = *(float *)&v28[2].m_BoundComponentHandles.mNode.mPrev - v33->mWorldTransform.v3.x;
          mPrev_high = (__m128)HIDWORD(v28[2].m_BoundComponentHandles.mNode.mPrev);
          mPrev_high.m128_f32[0] = mPrev_high.m128_f32[0] - v33->mWorldTransform.v3.y;
          v36 = *(float *)&v28[2].m_BoundComponentHandles.mNode.mNext - v33->mWorldTransform.v3.z;
          v37 = mPrev_high;
          v37.m128_f32[0] = (float)((float)(mPrev_high.m128_f32[0] * mPrev_high.m128_f32[0]) + (float)(v34 * v34))
                          + (float)(v36 * v36);
          if ( v37.m128_f32[0] != 0.0 )
            v19 = 1.0 / _mm_sqrt_ps(v37).m128_f32[0];
          v32[37] = v34 * v19;
          v32[38] = mPrev_high.m128_f32[0] * v19;
          v32[39] = v36 * v19;
        }
      }
    }
  }
  return 1;
}

// File Line: 4354
// RVA: 0x389A10
void __fastcall FollowTargetTask::TeleportToTarget(FollowTargetTask *this)
{
  float *m_pPointer; // r15
  UFG::SimComponent *v3; // rax
  UFG::SimComponent *v4; // rbx
  float v5; // xmm3_4
  __m128 mPrev_high; // xmm6
  float v7; // xmm4_4
  float v8; // xmm2_4
  __m128 v9; // xmm1
  float v10; // xmm5_4
  ITrack *m_Track; // rax
  float v12; // xmm7_4
  float v13; // xmm8_4
  float v14; // xmm6_4
  float v15; // xmm7_4
  char v16; // si
  UFG::eConstrainToSidewalks v17; // r12d
  float v18; // xmm0_4
  int v19; // r13d
  int v20; // edi
  float z; // xmm10_4
  float v22; // xmm12_4
  float v23; // xmm7_4
  float v24; // xmm11_4
  float v25; // xmm8_4
  float v26; // xmm13_4
  float value; // xmm6_4
  float v28; // xmm7_4
  float v29; // xmm11_4
  float v30; // xmm10_4
  float v31; // xmm8_4
  float v32; // xmm13_4
  float v33; // xmm12_4
  float v34; // xmm6_4
  float v35; // xmm5_4
  float v36; // xmm4_4
  float y; // xmm1_4
  float x; // xmm0_4
  UFG::SimObject *m_pSimObject; // rbx
  UFG::allocator::free_link *v40; // rax
  UFG::qVector3 dir; // [rsp+48h] [rbp-90h] BYREF
  UFG::qVector3 origin; // [rsp+58h] [rbp-80h] BYREF
  UFG::qVector3 point; // [rsp+68h] [rbp-70h] BYREF
  UFG::qVector3 v44; // [rsp+78h] [rbp-60h] BYREF
  UFG::allocator::free_link *v45; // [rsp+138h] [rbp+60h]

  m_pPointer = (float *)this->m_pTargetTransformNodeComponent.m_pPointer;
  if ( !m_pPointer )
    return;
  if ( !this->m_pTargetAIEntityComponent.m_pPointer )
    return;
  v3 = this->m_pTransformNodeComponent.m_pPointer;
  if ( !v3 )
    return;
  if ( !v3->m_pSimObject )
    return;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->m_pTargetTransformNodeComponent.m_pPointer);
  v4 = this->m_pTransformNodeComponent.m_pPointer;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v4);
  v5 = m_pPointer[45];
  mPrev_high = (__m128)HIDWORD(v4[2].m_BoundComponentHandles.mNode.mPrev);
  mPrev_high.m128_f32[0] = mPrev_high.m128_f32[0] - v5;
  v7 = m_pPointer[44];
  v8 = *(float *)&v4[2].m_BoundComponentHandles.mNode.mPrev - v7;
  v9 = mPrev_high;
  v9.m128_f32[0] = (float)(mPrev_high.m128_f32[0] * mPrev_high.m128_f32[0]) + (float)(v8 * v8);
  v10 = _mm_sqrt_ps(v9).m128_f32[0];
  if ( v10 <= 0.001 )
    return;
  m_Track = this->m_Track;
  v12 = m_Track[1].mMasterRate.value / v10;
  v13 = v12 * 0.0;
  v14 = mPrev_high.m128_f32[0] * v12;
  v15 = v12 * v8;
  origin = UFG::qVector3::msZero;
  dir = UFG::qVector3::msZero;
  v16 = 0;
  v17 = *((unsigned __int8 *)&m_Track[1].mMasterRate.value + 4);
  v18 = v13 + m_pPointer[46];
  point.x = v7 + v15;
  point.y = v5 + v14;
  point.z = v18;
  if ( UFG::AIEntityComponent::CanWalkStraightToPoint(
         (UFG::AIEntityComponent *)this->m_pTargetAIEntityComponent.m_pPointer,
         &point,
         v17,
         0i64) )
  {
    origin = point;
    LODWORD(dir.x) = LODWORD(v15) ^ _xmm[0];
    LODWORD(dir.y) = LODWORD(v14) ^ _xmm[0];
    LODWORD(dir.z) = LODWORD(v13) ^ _xmm[0];
    v16 = 1;
  }
  v19 = (int)(float)((float)(atan2f(v14, v15) * 32768.0) * 0.31830987);
  v20 = 1;
  while ( !v16 )
  {
    z = UFG::qVector3::msZero.z;
    v22 = UFG::qVector3::msZero.z;
    v23 = (float)((float)(unsigned __int16)((int)(float)((float)((float)v20 * 0.1) * 32767.0) + v19) * 3.1415927)
        * 0.000030517578;
    v24 = sinf(v23);
    v25 = (float)((float)(unsigned __int16)(v19 - (int)(float)((float)((float)v20 * 0.1) * 32767.0)) * 3.1415927)
        * 0.000030517578;
    v26 = sinf(v25);
    value = this->m_Track[1].mMasterRate.value;
    v28 = cosf(v23) * value;
    v29 = v24 * value;
    v30 = z * value;
    v31 = cosf(v25) * value;
    v32 = v26 * value;
    v33 = v22 * value;
    v34 = m_pPointer[46];
    v35 = m_pPointer[45];
    v36 = m_pPointer[44];
    point.x = v36 + v28;
    point.y = v35 + v29;
    point.z = v34 + v30;
    v44.x = v36 + v31;
    v44.y = v35 + v32;
    origin.x = v34 + v33;
    if ( UFG::AIEntityComponent::CanWalkStraightToPoint(
           (UFG::AIEntityComponent *)this->m_pTargetAIEntityComponent.m_pPointer,
           &point,
           v17,
           0i64) )
    {
      origin.x = point.x;
      y = point.y;
      x = point.z;
      LODWORD(dir.x) = LODWORD(v28) ^ _xmm[0];
      LODWORD(dir.y) = LODWORD(v29) ^ _xmm[0];
      LODWORD(dir.z) = LODWORD(v30) ^ _xmm[0];
LABEL_14:
      v16 = 1;
      origin.z = x;
      origin.y = y;
      goto LABEL_15;
    }
    if ( UFG::AIEntityComponent::CanWalkStraightToPoint(
           (UFG::AIEntityComponent *)this->m_pTargetAIEntityComponent.m_pPointer,
           &v44,
           v17,
           0i64) )
    {
      origin.x = v44.x;
      y = v44.y;
      x = v44.x;
      LODWORD(dir.x) = LODWORD(v31) ^ _xmm[0];
      LODWORD(dir.y) = LODWORD(v32) ^ _xmm[0];
      LODWORD(dir.z) = LODWORD(v33) ^ _xmm[0];
      goto LABEL_14;
    }
LABEL_15:
    if ( ++v20 > 10 )
    {
      if ( !v16 )
        return;
      break;
    }
  }
  m_pSimObject = this->m_pTransformNodeComponent.m_pPointer->m_pSimObject;
  v40 = UFG::qMalloc(0x90ui64, "FollowTargetTask", 0i64);
  v45 = v40;
  if ( v40 )
    UFG::TeleportEvent::TeleportEvent(
      (UFG::TeleportEvent *)v40,
      &origin,
      &dir,
      m_pSimObject->mNode.mUID,
      0,
      UFG::TeleportEvent::m_Name,
      &UFG::qVector3::msDirUp);
  UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v40);
}

// File Line: 4468
// RVA: 0x32D190
void __fastcall CircleAroundCombatantsTask::CircleAroundCombatantsTask(CircleAroundCombatantsTask *this)
{
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<CircleAroundCombatantsTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&CircleAroundCombatantsTask::`vftable;
  this->m_pAIEntityComponent.mPrev = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.m_pPointer = 0i64;
  this->m_pTransformNodeComponent.mPrev = &this->m_pTransformNodeComponent;
  this->m_pTransformNodeComponent.mNext = &this->m_pTransformNodeComponent;
  this->m_pTransformNodeComponent.m_pPointer = 0i64;
  this->m_pTargetingSystemBaseComponent.mPrev = &this->m_pTargetingSystemBaseComponent;
  this->m_pTargetingSystemBaseComponent.mNext = &this->m_pTargetingSystemBaseComponent;
  this->m_pTargetingSystemBaseComponent.m_pPointer = 0i64;
  this->m_pTargetSimObject.mPrev = &this->m_pTargetSimObject;
  this->m_pTargetSimObject.mNext = &this->m_pTargetSimObject;
  this->m_pTargetSimObject.m_pPointer = 0i64;
  this->m_pTargetTransformNodeComponent.mPrev = &this->m_pTargetTransformNodeComponent;
  this->m_pTargetTransformNodeComponent.mNext = &this->m_pTargetTransformNodeComponent;
  this->m_pTargetTransformNodeComponent.m_pPointer = 0i64;
  this->m_pTargetFormationManagerComponent.mPrev = &this->m_pTargetFormationManagerComponent;
  this->m_pTargetFormationManagerComponent.mNext = &this->m_pTargetFormationManagerComponent;
  this->m_pTargetFormationManagerComponent.m_pPointer = 0i64;
}

// File Line: 4472
// RVA: 0x335920
void __fastcall CircleAroundCombatantsTask::~CircleAroundCombatantsTask(CircleAroundCombatantsTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::FormationManagerComponent> *p_m_pTargetFormationManagerComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_m_pTargetTransformNodeComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_pTargetSimObject; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *p_m_pTargetingSystemBaseComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v21; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_m_pTransformNodeComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v23; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v24; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v25; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v26; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pAIEntityComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v28; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v29; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v30; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v31; // rax
  UFG::qNode<ITask,ITask> *v32; // rcx
  UFG::qNode<ITask,ITask> *v33; // rax

  this->vfptr = (ITaskVtbl *)&CircleAroundCombatantsTask::`vftable;
  p_m_pTargetFormationManagerComponent = &this->m_pTargetFormationManagerComponent;
  if ( this->m_pTargetFormationManagerComponent.m_pPointer )
  {
    mPrev = p_m_pTargetFormationManagerComponent->mPrev;
    mNext = p_m_pTargetFormationManagerComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pTargetFormationManagerComponent->mPrev = p_m_pTargetFormationManagerComponent;
    p_m_pTargetFormationManagerComponent->mNext = p_m_pTargetFormationManagerComponent;
  }
  p_m_pTargetFormationManagerComponent->m_pPointer = 0i64;
  v5 = p_m_pTargetFormationManagerComponent->mPrev;
  v6 = p_m_pTargetFormationManagerComponent->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_m_pTargetFormationManagerComponent->mPrev = p_m_pTargetFormationManagerComponent;
  p_m_pTargetFormationManagerComponent->mNext = p_m_pTargetFormationManagerComponent;
  p_m_pTargetTransformNodeComponent = &this->m_pTargetTransformNodeComponent;
  if ( this->m_pTargetTransformNodeComponent.m_pPointer )
  {
    v8 = p_m_pTargetTransformNodeComponent->mPrev;
    v9 = this->m_pTargetTransformNodeComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    p_m_pTargetTransformNodeComponent->mPrev = p_m_pTargetTransformNodeComponent;
    this->m_pTargetTransformNodeComponent.mNext = &this->m_pTargetTransformNodeComponent;
  }
  this->m_pTargetTransformNodeComponent.m_pPointer = 0i64;
  v10 = p_m_pTargetTransformNodeComponent->mPrev;
  v11 = this->m_pTargetTransformNodeComponent.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  p_m_pTargetTransformNodeComponent->mPrev = p_m_pTargetTransformNodeComponent;
  this->m_pTargetTransformNodeComponent.mNext = &this->m_pTargetTransformNodeComponent;
  p_m_pTargetSimObject = &this->m_pTargetSimObject;
  if ( this->m_pTargetSimObject.m_pPointer )
  {
    v13 = p_m_pTargetSimObject->mPrev;
    v14 = this->m_pTargetSimObject.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    p_m_pTargetSimObject->mPrev = p_m_pTargetSimObject;
    this->m_pTargetSimObject.mNext = &this->m_pTargetSimObject;
  }
  this->m_pTargetSimObject.m_pPointer = 0i64;
  v15 = p_m_pTargetSimObject->mPrev;
  v16 = this->m_pTargetSimObject.mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  p_m_pTargetSimObject->mPrev = p_m_pTargetSimObject;
  this->m_pTargetSimObject.mNext = &this->m_pTargetSimObject;
  p_m_pTargetingSystemBaseComponent = &this->m_pTargetingSystemBaseComponent;
  if ( this->m_pTargetingSystemBaseComponent.m_pPointer )
  {
    v18 = p_m_pTargetingSystemBaseComponent->mPrev;
    v19 = this->m_pTargetingSystemBaseComponent.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    p_m_pTargetingSystemBaseComponent->mPrev = p_m_pTargetingSystemBaseComponent;
    this->m_pTargetingSystemBaseComponent.mNext = &this->m_pTargetingSystemBaseComponent;
  }
  this->m_pTargetingSystemBaseComponent.m_pPointer = 0i64;
  v20 = p_m_pTargetingSystemBaseComponent->mPrev;
  v21 = this->m_pTargetingSystemBaseComponent.mNext;
  v20->mNext = v21;
  v21->mPrev = v20;
  p_m_pTargetingSystemBaseComponent->mPrev = p_m_pTargetingSystemBaseComponent;
  this->m_pTargetingSystemBaseComponent.mNext = &this->m_pTargetingSystemBaseComponent;
  p_m_pTransformNodeComponent = &this->m_pTransformNodeComponent;
  if ( this->m_pTransformNodeComponent.m_pPointer )
  {
    v23 = p_m_pTransformNodeComponent->mPrev;
    v24 = this->m_pTransformNodeComponent.mNext;
    v23->mNext = v24;
    v24->mPrev = v23;
    p_m_pTransformNodeComponent->mPrev = p_m_pTransformNodeComponent;
    this->m_pTransformNodeComponent.mNext = &this->m_pTransformNodeComponent;
  }
  this->m_pTransformNodeComponent.m_pPointer = 0i64;
  v25 = p_m_pTransformNodeComponent->mPrev;
  v26 = this->m_pTransformNodeComponent.mNext;
  v25->mNext = v26;
  v26->mPrev = v25;
  p_m_pTransformNodeComponent->mPrev = p_m_pTransformNodeComponent;
  this->m_pTransformNodeComponent.mNext = &this->m_pTransformNodeComponent;
  p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
  if ( this->m_pAIEntityComponent.m_pPointer )
  {
    v28 = p_m_pAIEntityComponent->mPrev;
    v29 = this->m_pAIEntityComponent.mNext;
    v28->mNext = v29;
    v29->mPrev = v28;
    p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
    this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
  }
  this->m_pAIEntityComponent.m_pPointer = 0i64;
  v30 = p_m_pAIEntityComponent->mPrev;
  v31 = this->m_pAIEntityComponent.mNext;
  v30->mNext = v31;
  v31->mPrev = v30;
  p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
  this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v32 = this->mPrev;
  v33 = this->mNext;
  v32->mNext = v33;
  v33->mPrev = v32;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 4477
// RVA: 0x3440F0
void __fastcall CircleAroundCombatantsTask::Begin(CircleAroundCombatantsTask *this, ActionContext *action_context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::SimComponent *v5; // r8
  __int16 m_Flags; // dx
  UFG::ActiveAIEntityComponent *ComponentOfTypeHK; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pAIEntityComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::SimObjectGame *v12; // rcx
  UFG::SimComponent *m_pComponent; // r8
  __int16 v14; // dx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *p_m_pTargetingSystemBaseComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::SimObject *v20; // r8
  UFG::SimComponent *m_pTransformNodeComponent; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_m_pTransformNodeComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v23; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v24; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v25; // rax
  UFG::SimComponent *v26; // rdx
  float z; // xmm2_4
  float x; // xmm0_4
  UFG::TransformNodeComponent *v29; // rsi
  UFG::TransformNodeComponent *v30; // rbx

  this->m_pActionContext = action_context;
  m_pPointer = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
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
    v5 = ComponentOfTypeHK;
  }
  else
  {
    v5 = 0i64;
  }
  p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
  if ( this->m_pAIEntityComponent.m_pPointer )
  {
    mPrev = p_m_pAIEntityComponent->mPrev;
    mNext = this->m_pAIEntityComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
    this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
  }
  this->m_pAIEntityComponent.m_pPointer = v5;
  if ( v5 )
  {
    v11 = v5->m_SafePointerList.mNode.mPrev;
    v11->mNext = p_m_pAIEntityComponent;
    p_m_pAIEntityComponent->mPrev = v11;
    this->m_pAIEntityComponent.mNext = &v5->m_SafePointerList.mNode;
    v5->m_SafePointerList.mNode.mPrev = p_m_pAIEntityComponent;
  }
  v12 = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  if ( v12 )
  {
    v14 = v12->m_Flags;
    if ( (v14 & 0x4000) != 0 )
    {
      m_pComponent = v12->m_Components.p[20].m_pComponent;
    }
    else if ( v14 >= 0 )
    {
      if ( (v14 & 0x2000) != 0 || (v14 & 0x1000) != 0 )
        ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        ComponentOfType = UFG::SimObject::GetComponentOfType(v12, UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = ComponentOfType;
    }
    else
    {
      m_pComponent = v12->m_Components.p[20].m_pComponent;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  p_m_pTargetingSystemBaseComponent = &this->m_pTargetingSystemBaseComponent;
  if ( this->m_pTargetingSystemBaseComponent.m_pPointer )
  {
    v17 = p_m_pTargetingSystemBaseComponent->mPrev;
    v18 = this->m_pTargetingSystemBaseComponent.mNext;
    v17->mNext = v18;
    v18->mPrev = v17;
    p_m_pTargetingSystemBaseComponent->mPrev = p_m_pTargetingSystemBaseComponent;
    this->m_pTargetingSystemBaseComponent.mNext = &this->m_pTargetingSystemBaseComponent;
  }
  this->m_pTargetingSystemBaseComponent.m_pPointer = m_pComponent;
  if ( m_pComponent )
  {
    v19 = m_pComponent->m_SafePointerList.mNode.mPrev;
    v19->mNext = p_m_pTargetingSystemBaseComponent;
    p_m_pTargetingSystemBaseComponent->mPrev = v19;
    this->m_pTargetingSystemBaseComponent.mNext = &m_pComponent->m_SafePointerList.mNode;
    m_pComponent->m_SafePointerList.mNode.mPrev = p_m_pTargetingSystemBaseComponent;
  }
  v20 = action_context->mSimObject.m_pPointer;
  if ( v20 )
    m_pTransformNodeComponent = v20->m_pTransformNodeComponent;
  else
    m_pTransformNodeComponent = 0i64;
  p_m_pTransformNodeComponent = &this->m_pTransformNodeComponent;
  if ( this->m_pTransformNodeComponent.m_pPointer )
  {
    v23 = p_m_pTransformNodeComponent->mPrev;
    v24 = this->m_pTransformNodeComponent.mNext;
    v23->mNext = v24;
    v24->mPrev = v23;
    p_m_pTransformNodeComponent->mPrev = p_m_pTransformNodeComponent;
    this->m_pTransformNodeComponent.mNext = &this->m_pTransformNodeComponent;
  }
  this->m_pTransformNodeComponent.m_pPointer = m_pTransformNodeComponent;
  if ( m_pTransformNodeComponent )
  {
    v25 = m_pTransformNodeComponent->m_SafePointerList.mNode.mPrev;
    v25->mNext = p_m_pTransformNodeComponent;
    p_m_pTransformNodeComponent->mPrev = v25;
    this->m_pTransformNodeComponent.mNext = &m_pTransformNodeComponent->m_SafePointerList.mNode;
    m_pTransformNodeComponent->m_SafePointerList.mNode.mPrev = p_m_pTransformNodeComponent;
  }
  v26 = this->m_pTargetingSystemBaseComponent.m_pPointer;
  if ( v26 )
    CircleAroundCombatantsTask::SetMyTarget(
      this,
      *(UFG::SimObject **)(56i64
                         * *(unsigned __int8 *)(LOBYTE(this->m_Track[1].vfptr) + *(_QWORD *)&v26[1].m_Flags + 8i64)
                         + *(_QWORD *)&v26[1].m_TypeUID
                         + 40));
  this->m_CurrentlyMoving = 0;
  z = UFG::qVector3::msZero.z;
  x = UFG::qVector3::msZero.x;
  this->m_DesiredPosition.y = UFG::qVector3::msZero.y;
  this->m_DesiredPosition.z = z;
  this->m_DesiredPosition.x = x;
  v29 = (UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pPointer;
  this->m_DesiredPositionValid = 0;
  this->m_LastTimeSinceStopped = -99999.0;
  if ( v29 && this->m_pTargetTransformNodeComponent.m_pPointer )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(v29);
    v30 = (UFG::TransformNodeComponent *)this->m_pTargetTransformNodeComponent.m_pPointer;
    UFG::TransformNodeComponent::UpdateWorldTransform(v30);
    this->m_DesiredAngle = (int)(float)((float)(atan2f(
                                                  v29->mWorldTransform.v3.y - v30->mWorldTransform.v3.y,
                                                  v29->mWorldTransform.v3.x - v30->mWorldTransform.v3.x)
                                              * 32768.0)
                                      * 0.31830987);
  }
  else
  {
    this->m_DesiredAngle = 0;
  }
  this->m_TestAngleIndex = 0;
}

// File Line: 4518
// RVA: 0x387570
void __fastcall CircleAroundCombatantsTask::SetMyTarget(
        CircleAroundCombatantsTask *this,
        UFG::SimObject *target_object)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_pTargetSimObject; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::SimObject *m_pPointer; // r8
  UFG::SimComponent *m_pTransformNodeComponent; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_m_pTargetTransformNodeComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::SimObjectGame *v13; // rcx
  UFG::SimComponent *v14; // rdx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::FormationManagerComponent> *p_m_pTargetFormationManagerComponent; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v21; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v22; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v23; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::FormationManagerComponent> *v24; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v25; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v26; // rax

  p_m_pTargetSimObject = &this->m_pTargetSimObject;
  if ( this->m_pTargetSimObject.m_pPointer )
  {
    mPrev = p_m_pTargetSimObject->mPrev;
    mNext = this->m_pTargetSimObject.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pTargetSimObject->mPrev = p_m_pTargetSimObject;
    this->m_pTargetSimObject.mNext = &this->m_pTargetSimObject;
  }
  this->m_pTargetSimObject.m_pPointer = target_object;
  if ( target_object )
  {
    v6 = target_object->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    v6->mNext = p_m_pTargetSimObject;
    p_m_pTargetSimObject->mPrev = v6;
    this->m_pTargetSimObject.mNext = &target_object->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
    target_object->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_m_pTargetSimObject;
  }
  m_pPointer = this->m_pTargetSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_pTransformNodeComponent = m_pPointer->m_pTransformNodeComponent;
    p_m_pTargetTransformNodeComponent = &this->m_pTargetTransformNodeComponent;
    if ( this->m_pTargetTransformNodeComponent.m_pPointer )
    {
      v10 = p_m_pTargetTransformNodeComponent->mPrev;
      v11 = this->m_pTargetTransformNodeComponent.mNext;
      v10->mNext = v11;
      v11->mPrev = v10;
      p_m_pTargetTransformNodeComponent->mPrev = p_m_pTargetTransformNodeComponent;
      this->m_pTargetTransformNodeComponent.mNext = &this->m_pTargetTransformNodeComponent;
    }
    this->m_pTargetTransformNodeComponent.m_pPointer = m_pTransformNodeComponent;
    if ( m_pTransformNodeComponent )
    {
      v12 = m_pTransformNodeComponent->m_SafePointerList.mNode.mPrev;
      v12->mNext = p_m_pTargetTransformNodeComponent;
      p_m_pTargetTransformNodeComponent->mPrev = v12;
      this->m_pTargetTransformNodeComponent.mNext = &m_pTransformNodeComponent->m_SafePointerList.mNode;
      m_pTransformNodeComponent->m_SafePointerList.mNode.mPrev = p_m_pTargetTransformNodeComponent;
    }
    v13 = (UFG::SimObjectGame *)this->m_pTargetSimObject.m_pPointer;
    if ( v13 )
    {
      m_Flags = v13->m_Flags;
      if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::FormationManagerComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v13, UFG::FormationManagerComponent::_TypeUID);
      v14 = ComponentOfTypeHK;
    }
    else
    {
      v14 = 0i64;
    }
    p_m_pTargetFormationManagerComponent = &this->m_pTargetFormationManagerComponent;
    if ( this->m_pTargetFormationManagerComponent.m_pPointer )
    {
      v18 = p_m_pTargetFormationManagerComponent->mPrev;
      v19 = this->m_pTargetFormationManagerComponent.mNext;
      v18->mNext = v19;
      v19->mPrev = v18;
      p_m_pTargetFormationManagerComponent->mPrev = p_m_pTargetFormationManagerComponent;
      this->m_pTargetFormationManagerComponent.mNext = &this->m_pTargetFormationManagerComponent;
    }
    this->m_pTargetFormationManagerComponent.m_pPointer = v14;
    if ( v14 )
    {
      v20 = v14->m_SafePointerList.mNode.mPrev;
      v20->mNext = p_m_pTargetFormationManagerComponent;
      p_m_pTargetFormationManagerComponent->mPrev = v20;
      this->m_pTargetFormationManagerComponent.mNext = &v14->m_SafePointerList.mNode;
      v14->m_SafePointerList.mNode.mPrev = p_m_pTargetFormationManagerComponent;
    }
  }
  else
  {
    v21 = &this->m_pTargetTransformNodeComponent;
    if ( this->m_pTargetTransformNodeComponent.m_pPointer )
    {
      v22 = v21->mPrev;
      v23 = this->m_pTargetTransformNodeComponent.mNext;
      v22->mNext = v23;
      v23->mPrev = v22;
      v21->mPrev = v21;
      this->m_pTargetTransformNodeComponent.mNext = &this->m_pTargetTransformNodeComponent;
    }
    this->m_pTargetTransformNodeComponent.m_pPointer = 0i64;
    v24 = &this->m_pTargetFormationManagerComponent;
    if ( this->m_pTargetFormationManagerComponent.m_pPointer )
    {
      v25 = v24->mPrev;
      v26 = this->m_pTargetFormationManagerComponent.mNext;
      v25->mNext = v26;
      v26->mPrev = v25;
      v24->mPrev = v24;
      this->m_pTargetFormationManagerComponent.mNext = &this->m_pTargetFormationManagerComponent;
    }
    this->m_pTargetFormationManagerComponent.m_pPointer = 0i64;
  }
}

// File Line: 4540
// RVA: 0x34F9A0
char __fastcall CircleAroundCombatantsTask::ComputeDesiredPosition(
        CircleAroundCombatantsTask *this,
        UFG::qVector3 *desiredPosition,
        UFG::HavokNavPosition *npTargetPosition,
        unsigned __int16 testAngle,
        float desiredDistance,
        float minDistance,
        float maxDistance)
{
  float v7; // r14d
  __m128 z_low; // xmm8
  __m128 v12; // xmm6
  __m128 v13; // xmm0
  float v14; // xmm11_4
  __m128 v15; // xmm7
  __m128 v16; // xmm0
  ActionContext *m_pActionContext; // rax
  __m128 v18; // xmm3
  float v19; // xmm10_4
  UFG::SimObjectGame *m_pPointer; // r8
  UFG::SimComponent *m_pComponent; // rdx
  __int16 m_Flags; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  float v24; // xmm6_4
  __m128 y_low; // xmm2
  float v26; // xmm3_4
  __m128 m_aiMeshUid; // xmm2
  float v29; // xmm4_4
  float v30; // xmm11_4
  float v31; // xmm0_4
  int value_low; // ebx
  UFG::SimObjectGame *v33; // rcx
  __int16 v34; // dx
  __m128 x_low; // xmm4
  __m128 v36; // xmm3
  __m128 v37; // xmm0
  float v38; // [rsp+30h] [rbp-B8h] BYREF
  float v39; // [rsp+34h] [rbp-B4h]
  float v40; // [rsp+38h] [rbp-B0h]
  UFG::HavokNavPosition v41; // [rsp+40h] [rbp-A8h] BYREF
  char v42; // [rsp+80h] [rbp-68h]
  __m128 v43; // [rsp+88h] [rbp-60h]
  __int64 v44; // [rsp+98h] [rbp-50h]
  __int64 v45; // [rsp+138h] [rbp+50h] BYREF
  float v46; // [rsp+160h] [rbp+78h]
  float v47; // [rsp+168h] [rbp+80h]

  if ( !this->m_pAIEntityComponent.m_pPointer )
    return 0;
  z_low = (__m128)LODWORD(UFG::qVector3::msZero.z);
  v12 = (__m128)COERCE_UNSIGNED_INT((float)testAngle);
  v12.m128_f32[0] = (float)(v12.m128_f32[0] * 3.1415927) * 0.000030517578;
  v13 = v12;
  v13.m128_f32[0] = sinf(v12.m128_f32[0]);
  v14 = v13.m128_f32[0];
  v15 = v13;
  v16 = v12;
  v16.m128_f32[0] = cosf(v12.m128_f32[0]);
  m_pActionContext = this->m_pActionContext;
  v42 = 0;
  v18 = v16;
  v19 = v16.m128_f32[0];
  z_low.m128_f32[0] = (float)(z_low.m128_f32[0] * v47) + npTargetPosition->m_vPosition.z;
  v15.m128_f32[0] = (float)(v15.m128_f32[0] * v47) + npTargetPosition->m_vPosition.y;
  v41.m_hkvMeshPosition.m_quad.m128_u64[1] = (unsigned __int64)&UFG::HavokNavPosition::`vftable;
  v44 = -1i64;
  v18.m128_f32[0] = (float)(v16.m128_f32[0] * v47) + npTargetPosition->m_vPosition.x;
  *(&v41.m_aiMeshUid + 1) = z_low.m128_i32[0];
  v41.m_aiMeshUid = v15.m128_i32[0];
  v41.m_packedKey = v18.m128_i32[0];
  v43 = _mm_unpacklo_ps(_mm_unpacklo_ps(v18, z_low), _mm_unpacklo_ps(v15, (__m128)(unsigned int)FLOAT_1_0));
  m_pPointer = (UFG::SimObjectGame *)m_pActionContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[36].m_pComponent;
    }
    else
    {
      if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::NavComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::NavComponent::_TypeUID);
      m_pComponent = ComponentOfTypeHK;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  v24 = v7;
  v45 = *(__int64 *)((char *)&m_pComponent[2].m_BoundComponentHandles.mNode.mNext + 4);
  if ( UFG::NavManager::ms_pInstance->vfptr->AIRayCastHits(
         UFG::NavManager::ms_pInstance,
         (UFG::HavokNavPosition *)&m_pComponent[1].m_SafePointerList.mNode.mNext,
         (UFG::HavokNavPosition *)&v41.m_hkvMeshPosition.m_quad.m128_u16[4],
         (UFG::NavParams *)&v45,
         (UFG::qVector3 *)&v38) )
  {
    y_low = (__m128)LODWORD(npTargetPosition->m_vPosition.y);
    y_low.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] - v39) * (float)(y_low.m128_f32[0] - v39))
                              + (float)((float)(npTargetPosition->m_vPosition.x - v38)
                                      * (float)(npTargetPosition->m_vPosition.x - v38)))
                      + (float)((float)(npTargetPosition->m_vPosition.z - v40)
                              * (float)(npTargetPosition->m_vPosition.z - v40));
    v26 = _mm_sqrt_ps(y_low).m128_f32[0];
    if ( v26 > v7 )
    {
      m_aiMeshUid = (__m128)v41.m_aiMeshUid;
      m_aiMeshUid.m128_f32[0] = (float)((float)((float)(*(float *)&v41.m_aiMeshUid - v39)
                                              * (float)(*(float *)&v41.m_aiMeshUid - v39))
                                      + (float)((float)(*(float *)&v41.m_packedKey - v38)
                                              * (float)(*(float *)&v41.m_packedKey - v38)))
                              + (float)((float)(*((float *)&v41.m_aiMeshUid + 1) - v40)
                                      * (float)(*((float *)&v41.m_aiMeshUid + 1) - v40));
      v29 = _mm_sqrt_ps(m_aiMeshUid).m128_f32[0];
      if ( v29 >= 5.0 )
        v29 = FLOAT_5_0;
      v24 = (float)(5.0 - v29) + v7;
      if ( v24 >= v47 )
        v24 = v47;
      if ( v24 < v26 )
        goto LABEL_23;
    }
    else if ( v26 < v46 )
    {
      return 0;
    }
    v24 = v26;
  }
LABEL_23:
  v30 = (float)(v14 * v24) + npTargetPosition->m_vPosition.y;
  v31 = (float)(UFG::qVector3::msZero.z * v24) + npTargetPosition->m_vPosition.z;
  desiredPosition->x = (float)(v19 * v24) + npTargetPosition->m_vPosition.x;
  desiredPosition->y = v30;
  desiredPosition->z = v31;
  value_low = LOBYTE(this->m_Track[1].mMasterRate.value);
  v33 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
  if ( v33 )
  {
    v34 = v33->m_Flags;
    if ( (v34 & 0x4000) == 0 )
    {
      if ( v34 < 0 || (v34 & 0x2000) != 0 || (v34 & 0x1000) != 0 )
        UFG::SimObjectGame::GetComponentOfTypeHK(v33, UFG::NavComponent::_TypeUID);
      else
        UFG::SimObject::GetComponentOfType(v33, UFG::NavComponent::_TypeUID);
    }
  }
  if ( !value_low )
  {
    x_low = (__m128)LODWORD(desiredPosition->x);
    v36 = (__m128)LODWORD(desiredPosition->y);
    v37 = (__m128)LODWORD(desiredPosition->z);
    v41.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
    v41.m_bValid = 0;
    *(_QWORD *)&v41.m_packedKey = -1i64;
    LODWORD(v41.m_vPosition.x) = x_low.m128_i32[0];
    LODWORD(v41.m_vPosition.y) = v36.m128_i32[0];
    LODWORD(v41.m_vPosition.z) = v37.m128_i32[0];
    v41.m_hkvMeshPosition.m_quad = _mm_unpacklo_ps(
                                     _mm_unpacklo_ps(x_low, v37),
                                     _mm_unpacklo_ps(v36, (__m128)(unsigned int)FLOAT_1_0));
    UFG::HavokNavPosition::Validate(
      &v41,
      COERCE_DOUBLE((unsigned __int64)(unsigned int)FLOAT_1_0),
      COERCE_DOUBLE((unsigned __int64)(unsigned int)FLOAT_1_0),
      0.0);
    if ( !v41.m_bValid
      || !UFG::HavokAIUtilGame::IsValidKey(v41.m_packedKey, v41.m_aiMeshUid)
      || v41.m_packedKey == -1
      || v41.m_aiMeshUid == -1
      || (unsigned int)UFG::HavokNavPosition::GetMeshMaterialFlags(&v41) == 2 )
    {
      return 0;
    }
  }
  return 1;
}

// File Line: 4656
// RVA: 0x3953C0
void __fastcall CircleAroundCombatantsTask::UpdateDesiredPosition(CircleAroundCombatantsTask *this)
{
  UFG::SimComponent *m_pPointer; // rdi
  char v2; // r14
  UFG::SimComponent *v4; // rsi
  ITrack *m_Track; // rax
  float minDistance; // xmm6_4
  float maxDistance; // xmm7_4
  float desiredDistance; // xmm8_4
  UFG::SimObjectGame *m_pSimObject; // r8
  hkVector4f *m_pComponent; // rcx
  __int16 m_Flags; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  unsigned __int16 m_DesiredAngle; // r9
  float x; // xmm1_4
  float y; // xmm0_4
  float z; // xmm1_4
  __int16 v21; // si
  unsigned __int16 v22; // si
  float v23; // xmm1_4
  float mSimTime_Temp; // xmm0_4
  float v25; // xmm0_4
  int v26; // eax
  bool v27; // zf
  float v28; // xmm0_4
  float v29; // xmm1_4
  UFG::qVector3 desiredPosition; // [rsp+38h] [rbp-29h] BYREF
  UFG::HavokNavPosition npTargetPosition; // [rsp+48h] [rbp-19h] BYREF

  m_pPointer = this->m_pTransformNodeComponent.m_pPointer;
  v2 = 0;
  if ( !m_pPointer || !this->m_pTargetTransformNodeComponent.m_pPointer )
    return;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)m_pPointer);
  v4 = this->m_pTargetTransformNodeComponent.m_pPointer;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v4);
  m_Track = this->m_Track;
  minDistance = *((float *)&m_Track[1].vfptr + 1);
  maxDistance = *(float *)&m_Track[1].mResourceOwner;
  desiredDistance = *((float *)&m_Track[1].mResourceOwner + 1);
  m_pSimObject = (UFG::SimObjectGame *)this->m_pTargetTransformNodeComponent.m_pPointer->m_pSimObject;
  if ( m_pSimObject )
  {
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (hkVector4f *)m_pSimObject->m_Components.p[36].m_pComponent;
    }
    else
    {
      if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pSimObject, UFG::NavComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::NavComponent::_TypeUID);
      m_pComponent = (hkVector4f *)ComponentOfTypeHK;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  npTargetPosition.m_bValid = 0;
  *(_QWORD *)&npTargetPosition.m_packedKey = -1i64;
  npTargetPosition.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
  npTargetPosition.m_vPosition = UFG::qVector3::msZero;
  npTargetPosition.m_hkvMeshPosition = (hkVector4f)hkvZero_13.m_quad;
  if ( !m_pComponent )
  {
    v15 = *((float *)&v4[2].m_BoundComponentHandles.mNode.mPrev + 1);
    v16 = *(float *)&v4[2].m_BoundComponentHandles.mNode.mNext;
    npTargetPosition.m_vPosition.x = *(float *)&v4[2].m_BoundComponentHandles.mNode.mPrev;
    npTargetPosition.m_vPosition.y = v15;
    npTargetPosition.m_vPosition.z = v16;
    goto LABEL_18;
  }
  v13 = m_pComponent[5].m_quad.m128_f32[3];
  v14 = m_pComponent[6].m_quad.m128_f32[0];
  LODWORD(npTargetPosition.m_vPosition.x) = m_pComponent[5].m_quad.m128_i32[2];
  npTargetPosition.m_vPosition.y = v13;
  npTargetPosition.m_vPosition.z = v14;
  if ( !m_pComponent[6].m_quad.m128_i8[8] )
  {
LABEL_18:
    npTargetPosition.m_bValid = 0;
    goto LABEL_19;
  }
  npTargetPosition.m_bValid = m_pComponent[6].m_quad.m128_i8[8];
  npTargetPosition.m_hkvMeshPosition = (hkVector4f)m_pComponent[7].m_quad;
  npTargetPosition.m_packedKey = m_pComponent[8].m_quad.m128_u32[0];
  npTargetPosition.m_aiMeshUid = m_pComponent[8].m_quad.m128_u32[1];
LABEL_19:
  UFG::HavokNavPosition::Validate(
    &npTargetPosition,
    COERCE_DOUBLE((unsigned __int64)(unsigned int)FLOAT_1_0),
    COERCE_DOUBLE((unsigned __int64)(unsigned int)FLOAT_1_0),
    0.0);
  m_DesiredAngle = this->m_DesiredAngle;
  desiredPosition = UFG::qVector3::msZero;
  if ( CircleAroundCombatantsTask::ComputeDesiredPosition(
         this,
         &desiredPosition,
         &npTargetPosition,
         m_DesiredAngle,
         desiredDistance,
         minDistance,
         maxDistance) )
  {
    x = desiredPosition.x;
    this->m_LastTimeFoundValidPosition = UFG::Metrics::msInstance.mSimTime_Temp;
    y = desiredPosition.y;
    this->m_DesiredPosition.x = x;
    z = desiredPosition.z;
    this->m_DesiredPosition.y = y;
    this->m_DesiredPosition.z = z;
    this->m_DesiredPositionValid = 1;
LABEL_28:
    this->m_LastTimeFoundValidPosition = UFG::Metrics::msInstance.mSimTime_Temp;
    return;
  }
  v21 = LOWORD(this->m_TestAngleIndex) + 1;
  desiredPosition.x = UFG::qVector3::msZero.x;
  v22 = this->m_DesiredAngle + 1228 * v21;
  desiredPosition.y = UFG::qVector3::msZero.y;
  desiredPosition.z = UFG::qVector3::msZero.z;
  if ( CircleAroundCombatantsTask::ComputeDesiredPosition(
         this,
         &desiredPosition,
         &npTargetPosition,
         v22,
         desiredDistance,
         minDistance,
         maxDistance) )
  {
    v23 = desiredPosition.y;
    this->m_TestAngleIndex = 0;
    mSimTime_Temp = UFG::Metrics::msInstance.mSimTime_Temp;
    this->m_DesiredAngle = v22;
    v2 = 1;
    this->m_LastTimeFoundValidPosition = mSimTime_Temp;
    v25 = desiredPosition.x;
    this->m_DesiredPosition.y = v23;
    this->m_DesiredPosition.x = v25;
    this->m_DesiredPosition.z = desiredPosition.z;
    this->m_DesiredPositionValid = 1;
  }
  v26 = ++this->m_TestAngleIndex;
  if ( v26 >= 10 )
    v26 = -10;
  v27 = !this->m_DesiredPositionValid;
  this->m_TestAngleIndex = v26;
  if ( v27 )
  {
    v28 = *((float *)&m_pPointer[2].m_BoundComponentHandles.mNode.mPrev + 1);
    v29 = *(float *)&m_pPointer[2].m_BoundComponentHandles.mNode.mNext;
    this->m_DesiredPosition.x = *(float *)&m_pPointer[2].m_BoundComponentHandles.mNode.mPrev;
    this->m_DesiredPosition.y = v28;
    this->m_DesiredPosition.z = v29;
    this->m_DesiredPositionValid = 1;
  }
  if ( v2 )
    goto LABEL_28;
}

// File Line: 4735
// RVA: 0x38D540
char __fastcall CircleAroundCombatantsTask::Update(CircleAroundCombatantsTask *this, float timestep)
{
  UFG::SimComponent *m_pPointer; // rcx
  UFG::SimObject *v5; // rdx
  UFG::SimComponent *v6; // r15
  UFG::TransformNodeComponent *v7; // rbx
  ITrack *m_Track; // rax
  bool m_DesiredPositionValid; // cl
  float x; // xmm3_4
  float y; // xmm2_4
  float v12; // xmm5_4
  __m128 mPrev_high; // xmm4
  float v14; // xmm14_4
  float v15; // xmm15_4
  bool v16; // r14
  UFG::NavComponent *m_pComponent; // rsi
  __m128 v18; // xmm0
  float v19; // xmm7_4
  float v20; // xmm11_4
  float v21; // xmm9_4
  __m128 v22; // xmm10
  float v23; // xmm6_4
  __m128 v24; // xmm0
  float v25; // xmm2_4
  float v26; // xmm3_4
  float v27; // xmm0_4
  float v28; // xmm1_4
  float z; // xmm1_4
  UFG::qColour *v30; // rbx
  UFG::qColour *v31; // rax
  Render::DebugDrawContext *Context; // rax
  float v33; // xmm1_4
  float v34; // xmm0_4
  Render::DebugDrawContext *v35; // rax
  float m_LastTimeSinceStopped; // xmm0_4
  float v37; // xmm0_4
  float mSimTime_Temp; // xmm6_4
  float v39; // xmm0_4
  UFG::SimObjectGame *v40; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  float v43; // xmm0_4
  float v44; // xmm0_4
  __m128 z_low; // xmm0
  __m128 x_low; // xmm3
  __m128 y_low; // xmm2
  ITrack *v48; // rax
  __int64 v49; // rcx
  int mOffset_high; // esi
  UFG::SimObjectCVBase *v51; // rcx
  __int16 v52; // dx
  UFG::AICharacterControllerBaseComponent *ComponentOfType; // rax
  float *p_mMotionIntentionSpeedRaw; // rbx
  __m128 v55; // xmm2
  float v56; // xmm7_4
  UFG::qVector3 point; // [rsp+40h] [rbp-C0h] BYREF
  UFG::qColour colour; // [rsp+50h] [rbp-B0h] BYREF
  UFG::qColour v60; // [rsp+60h] [rbp-A0h] BYREF
  UFG::HavokNavPosition npDestination; // [rsp+70h] [rbp-90h] BYREF
  float fDestinationTolerance; // [rsp+180h] [rbp+80h]

  m_pPointer = this->m_pTargetingSystemBaseComponent.m_pPointer;
  if ( m_pPointer )
  {
    v5 = *(UFG::SimObject **)(56i64
                            * *(unsigned __int8 *)(LOBYTE(this->m_Track[1].vfptr)
                                                 + *(_QWORD *)&m_pPointer[1].m_Flags
                                                 + 8i64)
                            + *(_QWORD *)&m_pPointer[1].m_TypeUID
                            + 40);
    if ( v5 != this->m_pTargetSimObject.m_pPointer )
      CircleAroundCombatantsTask::SetMyTarget(this, v5);
  }
  v6 = this->m_pTransformNodeComponent.m_pPointer;
  if ( !v6 || !this->m_pTargetTransformNodeComponent.m_pPointer || !this->m_pAIEntityComponent.m_pPointer )
    return 0;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v6);
  v7 = (UFG::TransformNodeComponent *)this->m_pTargetTransformNodeComponent.m_pPointer;
  UFG::TransformNodeComponent::UpdateWorldTransform(v7);
  m_Track = this->m_Track;
  m_DesiredPositionValid = this->m_DesiredPositionValid;
  x = v7->mWorldTransform.v3.x;
  y = v7->mWorldTransform.v3.y;
  mPrev_high = (__m128)HIDWORD(v6[2].m_BoundComponentHandles.mNode.mPrev);
  v14 = this->m_DesiredPosition.x;
  v15 = this->m_DesiredPosition.y;
  v16 = !m_DesiredPositionValid;
  m_pComponent = 0i64;
  v18 = mPrev_high;
  v22 = mPrev_high;
  v20 = *(float *)&v6[2].m_BoundComponentHandles.mNode.mNext - v7->mWorldTransform.v3.z;
  v21 = *(float *)&v6[2].m_BoundComponentHandles.mNode.mPrev - x;
  v18.m128_f32[0] = (float)((float)(mPrev_high.m128_f32[0] - y) * (float)(mPrev_high.m128_f32[0] - y))
                  + (float)(v21 * v21);
  v22.m128_f32[0] = mPrev_high.m128_f32[0] - y;
  LODWORD(v23) = _mm_sqrt_ps(v18).m128_u32[0];
  v24 = (__m128)LODWORD(v15);
  v24.m128_f32[0] = v15 - y;
  v25 = *(float *)&m_Track[1].mResourceOwner;
  v24.m128_f32[0] = (float)(v24.m128_f32[0] * v24.m128_f32[0]) + (float)((float)(v14 - x) * (float)(v14 - x));
  LODWORD(v26) = _mm_sqrt_ps(v24).m128_u32[0];
  v27 = *((float *)&m_Track[1].vfptr + 1);
  fDestinationTolerance = *(float *)&m_Track[1].mBreakPoint;
  if ( this->m_CurrentlyMoving )
  {
    if ( v26 > v27 )
      v27 = v26;
    if ( v27 >= v25 )
      v27 = *(float *)&m_Track[1].mResourceOwner;
    if ( v26 != v27 && UFG::Metrics::msInstance.mSimTime_Temp > (float)(this->m_LastTimeFoundValidPosition + 0.5) )
    {
      v16 = 1;
      goto LABEL_30;
    }
LABEL_23:
    if ( m_DesiredPositionValid )
    {
      z = this->m_DesiredPosition.z;
      v12 = *(float *)&v6[2].m_BoundComponentHandles.mNode.mPrev;
      v19 = *(float *)&v6[2].m_BoundComponentHandles.mNode.mNext;
      v16 = (float)((float)((float)((float)(mPrev_high.m128_f32[0] - v15) * v22.m128_f32[0])
                          + (float)((float)(v12 - v14) * v21))
                  + (float)((float)(v19 - z) * v20)) >= 0.0;
      if ( CircleAroundCombatantsTask::gDrawCircleAroundCombatant )
      {
        v30 = &UFG::qColour::Red;
        point.x = this->m_DesiredPosition.x;
        point.y = v15;
        point.z = z + 0.1;
        v31 = &UFG::qColour::Red;
        if ( (float)((float)((float)((float)(mPrev_high.m128_f32[0] - v15) * v22.m128_f32[0])
                           + (float)((float)(v12 - v14) * v21))
                   + (float)((float)(v19 - z) * v20)) < 0.0 )
          v31 = &UFG::qColour::Green;
        colour = *v31;
        Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(
                                                Render::DebugDrawManager::mInstance,
                                                1u);
        Render::DebugDrawContext::DrawPoint(Context, &point, &colour, &UFG::qMatrix44::msIdentity, 0i64);
        colour.r = *(float *)&v6[2].m_BoundComponentHandles.mNode.mPrev;
        if ( !v16 )
          v30 = &UFG::qColour::Green;
        point.x = this->m_DesiredPosition.x;
        v33 = *(float *)&v6[2].m_BoundComponentHandles.mNode.mNext + 0.1;
        v60 = *v30;
        v34 = *((float *)&v6[2].m_BoundComponentHandles.mNode.mPrev + 1);
        colour.b = v33;
        colour.g = v34;
        point.y = this->m_DesiredPosition.y;
        point.z = this->m_DesiredPosition.z + 0.1;
        v35 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
        Render::DebugDrawContext::DrawLine(
          v35,
          (UFG::qVector3 *)&colour,
          &point,
          &v60,
          &UFG::qMatrix44::msIdentity,
          (void (__fastcall *)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *))Render::gXRayDrawCallback,
          0);
      }
    }
    goto LABEL_30;
  }
  if ( v23 <= v27 )
    v28 = *((float *)&m_Track[1].vfptr + 1);
  else
    v28 = v23;
  if ( v28 >= v25 )
    v28 = *(float *)&m_Track[1].mResourceOwner;
  if ( v23 == v28 )
    goto LABEL_23;
  this->m_CurrentlyMoving = 1;
  v16 = 1;
LABEL_30:
  m_LastTimeSinceStopped = this->m_LastTimeSinceStopped;
  if ( m_LastTimeSinceStopped > 0.0 )
  {
    v37 = m_LastTimeSinceStopped - timestep;
    if ( v37 <= 0.0 )
      v37 = 0.0;
    this->m_LastTimeSinceStopped = v37;
  }
  if ( this->m_CurrentlyMoving && v23 > 0.1 || !this->m_DesiredPositionValid )
  {
    if ( v16 )
    {
      mSimTime_Temp = UFG::Metrics::msInstance.mSimTime_Temp;
      v39 = atan2f(v22.m128_f32[0], v21);
      this->m_LastTimeFoundValidPosition = mSimTime_Temp;
      this->m_DesiredAngle = (int)(float)((float)(v39 * 32768.0) * 0.31830987);
      CircleAroundCombatantsTask::UpdateDesiredPosition(this);
    }
    v40 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
    if ( v40 )
    {
      m_Flags = v40->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = (UFG::NavComponent *)v40->m_Components.p[36].m_pComponent;
      }
      else
      {
        if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v40, UFG::NavComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v40, UFG::NavComponent::_TypeUID);
        m_pComponent = (UFG::NavComponent *)ComponentOfTypeHK;
      }
    }
    v43 = this->m_LastTimeSinceStopped;
    if ( v43 <= 0.0 )
    {
      z_low = (__m128)LODWORD(this->m_DesiredPosition.z);
      x_low = (__m128)LODWORD(this->m_DesiredPosition.x);
      y_low = (__m128)LODWORD(this->m_DesiredPosition.y);
      npDestination.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
      v48 = this->m_Track;
      npDestination.m_bValid = 0;
      LODWORD(npDestination.m_vPosition.x) = x_low.m128_i32[0];
      LODWORD(npDestination.m_vPosition.y) = y_low.m128_i32[0];
      LODWORD(npDestination.m_vPosition.z) = z_low.m128_i32[0];
      v49 = BYTE1(v48[1].mMasterRate.text.mOffset);
      *(_QWORD *)&npDestination.m_packedKey = -1i64;
      npDestination.m_hkvMeshPosition.m_quad = _mm_unpacklo_ps(
                                                 _mm_unpacklo_ps(x_low, z_low),
                                                 _mm_unpacklo_ps(y_low, (__m128)(unsigned int)FLOAT_1_0));
      UFG::NavComponent::AddGoalPoint(
        m_pComponent,
        &npDestination,
        AiGoal_Replace,
        sNaturalMovementSpeeds[v49],
        fDestinationTolerance);
    }
    else
    {
      v44 = v43 - timestep;
      if ( v44 <= 0.0 )
        v44 = 0.0;
      this->m_LastTimeSinceStopped = v44;
    }
    if ( UFG::NavComponent::IsAtDestination(m_pComponent) )
      this->m_CurrentlyMoving = 0;
  }
  if ( !this->m_CurrentlyMoving )
  {
    if ( this->m_LastTimeSinceStopped <= 0.0 )
      this->m_LastTimeSinceStopped = 2.0;
    mOffset_high = HIDWORD(this->m_Track[1].mMasterRate.expression.mOffset);
    if ( mOffset_high != gActionRequest_INVALID.m_EnumValue )
    {
      v51 = (UFG::SimObjectCVBase *)this->m_pActionContext->mSimObject.m_pPointer;
      if ( v51 )
      {
        v52 = v51->m_Flags;
        if ( (v52 & 0x4000) != 0 || v52 < 0 )
        {
          ComponentOfType = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v51);
        }
        else if ( (v52 & 0x2000) != 0 || (v52 & 0x1000) != 0 )
        {
          ComponentOfType = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                         v51,
                                                                         UFG::AICharacterControllerBaseComponent::_TypeUID);
        }
        else
        {
          ComponentOfType = (UFG::AICharacterControllerBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                                         v51,
                                                                         UFG::AICharacterControllerBaseComponent::_TypeUID);
        }
        if ( ComponentOfType )
        {
          p_mMotionIntentionSpeedRaw = &ComponentOfType->m_Intention.mMotionIntentionSpeedRaw;
          Intention::Set(&ComponentOfType->m_Intention, mOffset_high, 0.0);
          v55 = v22;
          v55.m128_f32[0] = (float)((float)(v22.m128_f32[0] * v22.m128_f32[0]) + (float)(v21 * v21))
                          + (float)(v20 * v20);
          if ( v55.m128_f32[0] == 0.0 )
            v56 = 0.0;
          else
            v56 = 1.0 / _mm_sqrt_ps(v55).m128_f32[0];
          p_mMotionIntentionSpeedRaw[7] = v56 * v20;
          p_mMotionIntentionSpeedRaw[5] = v56 * v21;
          p_mMotionIntentionSpeedRaw[6] = v56 * v22.m128_f32[0];
        }
      }
    }
  }
  return 1;
}

// File Line: 4901
// RVA: 0x32BF50
void __fastcall AITargetingParametersTask::AITargetingParametersTask(AITargetingParametersTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pAIEntityComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax

  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<AITargetingParametersTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&AITargetingParametersTask::`vftable;
  p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.mPrev = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.m_pPointer = 0i64;
  this->m_pTargetingSystemBaseComponent.mPrev = &this->m_pTargetingSystemBaseComponent;
  this->m_pTargetingSystemBaseComponent.mNext = &this->m_pTargetingSystemBaseComponent;
  this->m_pTargetingSystemBaseComponent.m_pPointer = 0i64;
  this->m_pTargetTransformNodeComponent.mPrev = &this->m_pTargetTransformNodeComponent;
  this->m_pTargetTransformNodeComponent.mNext = &this->m_pTargetTransformNodeComponent;
  this->m_pTargetTransformNodeComponent.m_pPointer = 0i64;
  this->m_pActionContext = 0i64;
  if ( this->m_pAIEntityComponent.m_pPointer )
  {
    mPrev = p_m_pAIEntityComponent->mPrev;
    mNext = p_m_pAIEntityComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
    p_m_pAIEntityComponent->mNext = p_m_pAIEntityComponent;
  }
  p_m_pAIEntityComponent->m_pPointer = 0i64;
}

// File Line: 4909
// RVA: 0x334AF0
void __fastcall AITargetingParametersTask::~AITargetingParametersTask(AITargetingParametersTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_m_pTargetTransformNodeComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *p_m_pTargetingSystemBaseComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pAIEntityComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qNode<ITask,ITask> *v17; // rcx
  UFG::qNode<ITask,ITask> *v18; // rax

  this->vfptr = (ITaskVtbl *)&AITargetingParametersTask::`vftable;
  p_m_pTargetTransformNodeComponent = &this->m_pTargetTransformNodeComponent;
  if ( this->m_pTargetTransformNodeComponent.m_pPointer )
  {
    mPrev = p_m_pTargetTransformNodeComponent->mPrev;
    mNext = p_m_pTargetTransformNodeComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pTargetTransformNodeComponent->mPrev = p_m_pTargetTransformNodeComponent;
    p_m_pTargetTransformNodeComponent->mNext = p_m_pTargetTransformNodeComponent;
  }
  p_m_pTargetTransformNodeComponent->m_pPointer = 0i64;
  v5 = p_m_pTargetTransformNodeComponent->mPrev;
  v6 = p_m_pTargetTransformNodeComponent->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_m_pTargetTransformNodeComponent->mPrev = p_m_pTargetTransformNodeComponent;
  p_m_pTargetTransformNodeComponent->mNext = p_m_pTargetTransformNodeComponent;
  p_m_pTargetingSystemBaseComponent = &this->m_pTargetingSystemBaseComponent;
  if ( this->m_pTargetingSystemBaseComponent.m_pPointer )
  {
    v8 = p_m_pTargetingSystemBaseComponent->mPrev;
    v9 = this->m_pTargetingSystemBaseComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    p_m_pTargetingSystemBaseComponent->mPrev = p_m_pTargetingSystemBaseComponent;
    this->m_pTargetingSystemBaseComponent.mNext = &this->m_pTargetingSystemBaseComponent;
  }
  this->m_pTargetingSystemBaseComponent.m_pPointer = 0i64;
  v10 = p_m_pTargetingSystemBaseComponent->mPrev;
  v11 = this->m_pTargetingSystemBaseComponent.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  p_m_pTargetingSystemBaseComponent->mPrev = p_m_pTargetingSystemBaseComponent;
  this->m_pTargetingSystemBaseComponent.mNext = &this->m_pTargetingSystemBaseComponent;
  p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
  if ( this->m_pAIEntityComponent.m_pPointer )
  {
    v13 = p_m_pAIEntityComponent->mPrev;
    v14 = this->m_pAIEntityComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
    this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
  }
  this->m_pAIEntityComponent.m_pPointer = 0i64;
  v15 = p_m_pAIEntityComponent->mPrev;
  v16 = this->m_pAIEntityComponent.mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
  this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v17 = this->mPrev;
  v18 = this->mNext;
  v17->mNext = v18;
  v18->mPrev = v17;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 4914
// RVA: 0x343970
void __fastcall AITargetingParametersTask::Begin(AITargetingParametersTask *this, ActionContext *action_context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::SimComponent *v4; // r8
  __int16 m_Flags; // dx
  UFG::ActiveAIEntityComponent *ComponentOfTypeHK; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pAIEntityComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::SimComponent *v11; // rcx
  ITrack *m_Track; // rax
  int vfptr_high; // xmm0_4
  int mResourceOwner; // xmm1_4

  this->m_pActionContext = action_context;
  if ( action_context )
  {
    m_pPointer = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
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
      v4 = ComponentOfTypeHK;
    }
    else
    {
      v4 = 0i64;
    }
    p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
    if ( this->m_pAIEntityComponent.m_pPointer )
    {
      mPrev = p_m_pAIEntityComponent->mPrev;
      mNext = this->m_pAIEntityComponent.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
      this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
    }
    this->m_pAIEntityComponent.m_pPointer = v4;
    if ( v4 )
    {
      v10 = v4->m_SafePointerList.mNode.mPrev;
      v10->mNext = p_m_pAIEntityComponent;
      p_m_pAIEntityComponent->mPrev = v10;
      this->m_pAIEntityComponent.mNext = &v4->m_SafePointerList.mNode;
      v4->m_SafePointerList.mNode.mPrev = p_m_pAIEntityComponent;
    }
  }
  v11 = this->m_pAIEntityComponent.m_pPointer;
  if ( v11 )
  {
    m_Track = this->m_Track;
    vfptr_high = HIDWORD(m_Track[1].vfptr);
    mResourceOwner = (int)m_Track[1].mResourceOwner;
    HIDWORD(v11[65].m_SafePointerList.mNode.mPrev) = LOBYTE(m_Track[1].vfptr);
    LODWORD(v11[65].m_SafePointerList.mNode.mNext) = vfptr_high;
    HIDWORD(v11[65].m_SafePointerList.mNode.mNext) = mResourceOwner;
  }
}

// File Line: 4947
// RVA: 0x354DE0
void __fastcall AITargetingParametersTask::End(AITargetingParametersTask *this)
{
  UFG::SimComponent *m_pPointer; // rax

  m_pPointer = this->m_pAIEntityComponent.m_pPointer;
  if ( m_pPointer )
  {
    *(UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **)((char *)&m_pPointer[65].m_SafePointerList.mNode.mPrev
                                                                                       + 4) = 0i64;
    HIDWORD(m_pPointer[65].m_SafePointerList.mNode.mNext) = 0;
  }
}

// File Line: 4963
// RVA: 0x32A810
void __fastcall AIAddSupplementaryAttackTargetTask::AIAddSupplementaryAttackTargetTask(
        AIAddSupplementaryAttackTargetTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pAIEntityComponent; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *p_m_pTargetingSystemBaseComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax

  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<AIAddSupplementaryAttackTargetTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&AIAddSupplementaryAttackTargetTask::`vftable;
  p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.mPrev = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.m_pPointer = 0i64;
  p_m_pTargetingSystemBaseComponent = &this->m_pTargetingSystemBaseComponent;
  this->m_pTargetingSystemBaseComponent.mPrev = &this->m_pTargetingSystemBaseComponent;
  this->m_pTargetingSystemBaseComponent.mNext = &this->m_pTargetingSystemBaseComponent;
  this->m_pTargetingSystemBaseComponent.m_pPointer = 0i64;
  this->m_pActionContext = 0i64;
  if ( this->m_pAIEntityComponent.m_pPointer )
  {
    mPrev = p_m_pAIEntityComponent->mPrev;
    mNext = p_m_pAIEntityComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
    p_m_pAIEntityComponent->mNext = p_m_pAIEntityComponent;
  }
  p_m_pAIEntityComponent->m_pPointer = 0i64;
  if ( p_m_pTargetingSystemBaseComponent->m_pPointer )
  {
    v5 = p_m_pTargetingSystemBaseComponent->mPrev;
    v6 = p_m_pTargetingSystemBaseComponent->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    p_m_pTargetingSystemBaseComponent->mPrev = p_m_pTargetingSystemBaseComponent;
    p_m_pTargetingSystemBaseComponent->mNext = p_m_pTargetingSystemBaseComponent;
  }
  p_m_pTargetingSystemBaseComponent->m_pPointer = 0i64;
}

// File Line: 4972
// RVA: 0x333960
void __fastcall AIAddSupplementaryAttackTargetTask::~AIAddSupplementaryAttackTargetTask(
        AIAddSupplementaryAttackTargetTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *p_m_pTargetingSystemBaseComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pAIEntityComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<ITask,ITask> *v12; // rcx
  UFG::qNode<ITask,ITask> *v13; // rax

  this->vfptr = (ITaskVtbl *)&AIAddSupplementaryAttackTargetTask::`vftable;
  p_m_pTargetingSystemBaseComponent = &this->m_pTargetingSystemBaseComponent;
  if ( this->m_pTargetingSystemBaseComponent.m_pPointer )
  {
    mPrev = p_m_pTargetingSystemBaseComponent->mPrev;
    mNext = p_m_pTargetingSystemBaseComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pTargetingSystemBaseComponent->mPrev = p_m_pTargetingSystemBaseComponent;
    p_m_pTargetingSystemBaseComponent->mNext = p_m_pTargetingSystemBaseComponent;
  }
  p_m_pTargetingSystemBaseComponent->m_pPointer = 0i64;
  v5 = p_m_pTargetingSystemBaseComponent->mPrev;
  v6 = p_m_pTargetingSystemBaseComponent->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_m_pTargetingSystemBaseComponent->mPrev = p_m_pTargetingSystemBaseComponent;
  p_m_pTargetingSystemBaseComponent->mNext = p_m_pTargetingSystemBaseComponent;
  p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
  if ( this->m_pAIEntityComponent.m_pPointer )
  {
    v8 = p_m_pAIEntityComponent->mPrev;
    v9 = this->m_pAIEntityComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
    this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
  }
  this->m_pAIEntityComponent.m_pPointer = 0i64;
  v10 = p_m_pAIEntityComponent->mPrev;
  v11 = this->m_pAIEntityComponent.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
  this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v12 = this->mPrev;
  v13 = this->mNext;
  v12->mNext = v13;
  v13->mPrev = v12;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 4977
// RVA: 0x3428F0
void __fastcall AIAddSupplementaryAttackTargetTask::Begin(
        AIAddSupplementaryAttackTargetTask *this,
        ActionContext *action_context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::SimComponent *m_pComponent; // rbx
  UFG::SimComponent *v5; // r8
  __int16 m_Flags; // dx
  UFG::ActiveAIEntityComponent *ComponentOfTypeHK; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pAIEntityComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::SimObjectGame *v12; // rcx
  __int16 v13; // dx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *p_m_pTargetingSystemBaseComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rax
  UFG::SimComponent *v19; // r8
  UFG::SimObjectGame *v20; // rbx
  __int16 v21; // cx
  UFG::SimComponent *v22; // rax

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
      v5 = ComponentOfTypeHK;
    }
    else
    {
      v5 = 0i64;
    }
    p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
    if ( this->m_pAIEntityComponent.m_pPointer )
    {
      mPrev = p_m_pAIEntityComponent->mPrev;
      mNext = this->m_pAIEntityComponent.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
      this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
    }
    this->m_pAIEntityComponent.m_pPointer = v5;
    if ( v5 )
    {
      v11 = v5->m_SafePointerList.mNode.mPrev;
      v11->mNext = p_m_pAIEntityComponent;
      p_m_pAIEntityComponent->mPrev = v11;
      this->m_pAIEntityComponent.mNext = &v5->m_SafePointerList.mNode;
      v5->m_SafePointerList.mNode.mPrev = p_m_pAIEntityComponent;
    }
    v12 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
    if ( v12 )
    {
      v13 = v12->m_Flags;
      if ( (v13 & 0x4000) != 0 )
      {
        m_pComponent = v12->m_Components.p[20].m_pComponent;
      }
      else if ( v13 >= 0 )
      {
        if ( (v13 & 0x2000) != 0 || (v13 & 0x1000) != 0 )
          ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::TargetingSystemBaseComponent::_TypeUID);
        else
          ComponentOfType = UFG::SimObject::GetComponentOfType(v12, UFG::TargetingSystemBaseComponent::_TypeUID);
        m_pComponent = ComponentOfType;
      }
      else
      {
        m_pComponent = v12->m_Components.p[20].m_pComponent;
      }
    }
    p_m_pTargetingSystemBaseComponent = &this->m_pTargetingSystemBaseComponent;
    if ( this->m_pTargetingSystemBaseComponent.m_pPointer )
    {
      v16 = p_m_pTargetingSystemBaseComponent->mPrev;
      v17 = this->m_pTargetingSystemBaseComponent.mNext;
      v16->mNext = v17;
      v17->mPrev = v16;
      p_m_pTargetingSystemBaseComponent->mPrev = p_m_pTargetingSystemBaseComponent;
      this->m_pTargetingSystemBaseComponent.mNext = &this->m_pTargetingSystemBaseComponent;
    }
    this->m_pTargetingSystemBaseComponent.m_pPointer = m_pComponent;
    if ( m_pComponent )
    {
      v18 = m_pComponent->m_SafePointerList.mNode.mPrev;
      v18->mNext = p_m_pTargetingSystemBaseComponent;
      p_m_pTargetingSystemBaseComponent->mPrev = v18;
      this->m_pTargetingSystemBaseComponent.mNext = &m_pComponent->m_SafePointerList.mNode;
      m_pComponent->m_SafePointerList.mNode.mPrev = p_m_pTargetingSystemBaseComponent;
    }
  }
  if ( this->m_pAIEntityComponent.m_pPointer )
  {
    v19 = this->m_pTargetingSystemBaseComponent.m_pPointer;
    if ( v19 )
    {
      v20 = *(UFG::SimObjectGame **)(56i64
                                   * *(unsigned __int8 *)(LOBYTE(this->m_Track[1].vfptr)
                                                        + *(_QWORD *)&v19[1].m_Flags
                                                        + 8i64)
                                   + *(_QWORD *)&v19[1].m_TypeUID
                                   + 40);
      if ( v20 )
      {
        v21 = v20->m_Flags;
        if ( (v21 & 0x4000) != 0 )
        {
          v22 = v20->m_Components.p[46].m_pComponent;
        }
        else if ( v21 < 0 || (v21 & 0x2000) != 0 || (v21 & 0x1000) != 0 )
        {
          v22 = UFG::SimObjectGame::GetComponentOfTypeHK(v20, UFG::AttackRightsComponent::_TypeUID);
        }
        else
        {
          v22 = UFG::SimObject::GetComponentOfType(v20, UFG::AttackRightsComponent::_TypeUID);
        }
        if ( v22 )
          UFG::ActiveAIEntityComponent::AddSupplementaryAttackTarget(
            (UFG::ActiveAIEntityComponent *)this->m_pAIEntityComponent.m_pPointer,
            v20);
      }
    }
  }
}

// File Line: 5028
// RVA: 0x32BC30
void __fastcall AIRemoveSupplementaryAttackTargetTask::AIRemoveSupplementaryAttackTargetTask(
        AIRemoveSupplementaryAttackTargetTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pAIEntityComponent; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *p_m_pTargetingSystemBaseComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax

  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<AIRemoveSupplementaryAttackTargetTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&AIRemoveSupplementaryAttackTargetTask::`vftable;
  p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.mPrev = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.m_pPointer = 0i64;
  p_m_pTargetingSystemBaseComponent = &this->m_pTargetingSystemBaseComponent;
  this->m_pTargetingSystemBaseComponent.mPrev = &this->m_pTargetingSystemBaseComponent;
  this->m_pTargetingSystemBaseComponent.mNext = &this->m_pTargetingSystemBaseComponent;
  this->m_pTargetingSystemBaseComponent.m_pPointer = 0i64;
  this->m_pActionContext = 0i64;
  if ( this->m_pAIEntityComponent.m_pPointer )
  {
    mPrev = p_m_pAIEntityComponent->mPrev;
    mNext = p_m_pAIEntityComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
    p_m_pAIEntityComponent->mNext = p_m_pAIEntityComponent;
  }
  p_m_pAIEntityComponent->m_pPointer = 0i64;
  if ( p_m_pTargetingSystemBaseComponent->m_pPointer )
  {
    v5 = p_m_pTargetingSystemBaseComponent->mPrev;
    v6 = p_m_pTargetingSystemBaseComponent->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    p_m_pTargetingSystemBaseComponent->mPrev = p_m_pTargetingSystemBaseComponent;
    p_m_pTargetingSystemBaseComponent->mNext = p_m_pTargetingSystemBaseComponent;
  }
  p_m_pTargetingSystemBaseComponent->m_pPointer = 0i64;
}

// File Line: 5037
// RVA: 0x3348D0
void __fastcall AIRemoveSupplementaryAttackTargetTask::~AIRemoveSupplementaryAttackTargetTask(
        AIRemoveSupplementaryAttackTargetTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *p_m_pTargetingSystemBaseComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pAIEntityComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<ITask,ITask> *v12; // rcx
  UFG::qNode<ITask,ITask> *v13; // rax

  this->vfptr = (ITaskVtbl *)&AIRemoveSupplementaryAttackTargetTask::`vftable;
  p_m_pTargetingSystemBaseComponent = &this->m_pTargetingSystemBaseComponent;
  if ( this->m_pTargetingSystemBaseComponent.m_pPointer )
  {
    mPrev = p_m_pTargetingSystemBaseComponent->mPrev;
    mNext = p_m_pTargetingSystemBaseComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pTargetingSystemBaseComponent->mPrev = p_m_pTargetingSystemBaseComponent;
    p_m_pTargetingSystemBaseComponent->mNext = p_m_pTargetingSystemBaseComponent;
  }
  p_m_pTargetingSystemBaseComponent->m_pPointer = 0i64;
  v5 = p_m_pTargetingSystemBaseComponent->mPrev;
  v6 = p_m_pTargetingSystemBaseComponent->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_m_pTargetingSystemBaseComponent->mPrev = p_m_pTargetingSystemBaseComponent;
  p_m_pTargetingSystemBaseComponent->mNext = p_m_pTargetingSystemBaseComponent;
  p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
  if ( this->m_pAIEntityComponent.m_pPointer )
  {
    v8 = p_m_pAIEntityComponent->mPrev;
    v9 = this->m_pAIEntityComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
    this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
  }
  this->m_pAIEntityComponent.m_pPointer = 0i64;
  v10 = p_m_pAIEntityComponent->mPrev;
  v11 = this->m_pAIEntityComponent.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
  this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v12 = this->mPrev;
  v13 = this->mNext;
  v12->mNext = v13;
  v13->mPrev = v12;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 5042
// RVA: 0x3437A0
void __fastcall AIRemoveSupplementaryAttackTargetTask::Begin(
        AIRemoveSupplementaryAttackTargetTask *this,
        ActionContext *action_context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::SimComponent *m_pComponent; // rbx
  UFG::SimComponent *v5; // r8
  __int16 m_Flags; // dx
  UFG::ActiveAIEntityComponent *ComponentOfTypeHK; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pAIEntityComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::SimObjectGame *v12; // rcx
  __int16 v13; // dx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *p_m_pTargetingSystemBaseComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rax
  UFG::ActiveAIEntityComponent *v19; // rcx
  UFG::SimComponent *v20; // r9

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
      v5 = ComponentOfTypeHK;
    }
    else
    {
      v5 = 0i64;
    }
    p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
    if ( this->m_pAIEntityComponent.m_pPointer )
    {
      mPrev = p_m_pAIEntityComponent->mPrev;
      mNext = this->m_pAIEntityComponent.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
      this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
    }
    this->m_pAIEntityComponent.m_pPointer = v5;
    if ( v5 )
    {
      v11 = v5->m_SafePointerList.mNode.mPrev;
      v11->mNext = p_m_pAIEntityComponent;
      p_m_pAIEntityComponent->mPrev = v11;
      this->m_pAIEntityComponent.mNext = &v5->m_SafePointerList.mNode;
      v5->m_SafePointerList.mNode.mPrev = p_m_pAIEntityComponent;
    }
    v12 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
    if ( v12 )
    {
      v13 = v12->m_Flags;
      if ( (v13 & 0x4000) != 0 )
      {
        m_pComponent = v12->m_Components.p[20].m_pComponent;
      }
      else if ( v13 >= 0 )
      {
        if ( (v13 & 0x2000) != 0 || (v13 & 0x1000) != 0 )
          ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::TargetingSystemBaseComponent::_TypeUID);
        else
          ComponentOfType = UFG::SimObject::GetComponentOfType(v12, UFG::TargetingSystemBaseComponent::_TypeUID);
        m_pComponent = ComponentOfType;
      }
      else
      {
        m_pComponent = v12->m_Components.p[20].m_pComponent;
      }
    }
    p_m_pTargetingSystemBaseComponent = &this->m_pTargetingSystemBaseComponent;
    if ( this->m_pTargetingSystemBaseComponent.m_pPointer )
    {
      v16 = p_m_pTargetingSystemBaseComponent->mPrev;
      v17 = this->m_pTargetingSystemBaseComponent.mNext;
      v16->mNext = v17;
      v17->mPrev = v16;
      p_m_pTargetingSystemBaseComponent->mPrev = p_m_pTargetingSystemBaseComponent;
      this->m_pTargetingSystemBaseComponent.mNext = &this->m_pTargetingSystemBaseComponent;
    }
    this->m_pTargetingSystemBaseComponent.m_pPointer = m_pComponent;
    if ( m_pComponent )
    {
      v18 = m_pComponent->m_SafePointerList.mNode.mPrev;
      v18->mNext = p_m_pTargetingSystemBaseComponent;
      p_m_pTargetingSystemBaseComponent->mPrev = v18;
      this->m_pTargetingSystemBaseComponent.mNext = &m_pComponent->m_SafePointerList.mNode;
      m_pComponent->m_SafePointerList.mNode.mPrev = p_m_pTargetingSystemBaseComponent;
    }
  }
  v19 = (UFG::ActiveAIEntityComponent *)this->m_pAIEntityComponent.m_pPointer;
  if ( v19 )
  {
    v20 = this->m_pTargetingSystemBaseComponent.m_pPointer;
    if ( v20 )
      UFG::ActiveAIEntityComponent::RemoveSupplementaryAttackTarget(
        v19,
        *(UFG::SimObject **)(56i64
                           * *(unsigned __int8 *)(LOBYTE(this->m_Track[1].vfptr) + *(_QWORD *)&v20[1].m_Flags + 8i64)
                           + *(_QWORD *)&v20[1].m_TypeUID
                           + 40));
  }
}

// File Line: 5085
// RVA: 0x32ED60
void __fastcall GetInFormationTask::GetInFormationTask(GetInFormationTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::NavComponent> *p_m_pNavComponent; // r9
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *p_m_pTargetingSystemBaseComponent; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::FormationManagerComponent> *p_m_pTargetFormationManagerComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax

  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<GetInFormationTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&GetInFormationTask::`vftable;
  this->m_pGetInFormationNode.mPrev = &this->m_pGetInFormationNode;
  this->m_pGetInFormationNode.mNext = &this->m_pGetInFormationNode;
  this->m_pGetInFormationNode.m_pPointer = 0i64;
  p_m_pNavComponent = &this->m_pNavComponent;
  this->m_pNavComponent.mPrev = &this->m_pNavComponent;
  this->m_pNavComponent.mNext = &this->m_pNavComponent;
  this->m_pNavComponent.m_pPointer = 0i64;
  p_m_pTargetingSystemBaseComponent = &this->m_pTargetingSystemBaseComponent;
  this->m_pTargetingSystemBaseComponent.mPrev = &this->m_pTargetingSystemBaseComponent;
  this->m_pTargetingSystemBaseComponent.mNext = &this->m_pTargetingSystemBaseComponent;
  this->m_pTargetingSystemBaseComponent.m_pPointer = 0i64;
  this->m_pTargetTransformNodeComponent.mPrev = &this->m_pTargetTransformNodeComponent;
  this->m_pTargetTransformNodeComponent.mNext = &this->m_pTargetTransformNodeComponent;
  this->m_pTargetTransformNodeComponent.m_pPointer = 0i64;
  p_m_pTargetFormationManagerComponent = &this->m_pTargetFormationManagerComponent;
  this->m_pTargetFormationManagerComponent.mPrev = &this->m_pTargetFormationManagerComponent;
  this->m_pTargetFormationManagerComponent.mNext = &this->m_pTargetFormationManagerComponent;
  this->m_pTargetFormationManagerComponent.m_pPointer = 0i64;
  this->m_pTargetTargetingSystemBaseComponent.mPrev = &this->m_pTargetTargetingSystemBaseComponent;
  this->m_pTargetTargetingSystemBaseComponent.mNext = &this->m_pTargetTargetingSystemBaseComponent;
  this->m_pTargetTargetingSystemBaseComponent.m_pPointer = 0i64;
  this->m_pAIScriptInterfaceComponent.mPrev = &this->m_pAIScriptInterfaceComponent;
  this->m_pAIScriptInterfaceComponent.mNext = &this->m_pAIScriptInterfaceComponent;
  this->m_pAIScriptInterfaceComponent.m_pPointer = 0i64;
  this->m_NavParams.m_fRadius = 0.0;
  this->m_NavParams.m_flags = 65280;
  this->m_pActionContext = 0i64;
  if ( this->m_pNavComponent.m_pPointer )
  {
    mPrev = p_m_pNavComponent->mPrev;
    mNext = p_m_pNavComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pNavComponent->mPrev = p_m_pNavComponent;
    p_m_pNavComponent->mNext = p_m_pNavComponent;
  }
  p_m_pNavComponent->m_pPointer = 0i64;
  if ( p_m_pTargetingSystemBaseComponent->m_pPointer )
  {
    v6 = p_m_pTargetingSystemBaseComponent->mPrev;
    v7 = p_m_pTargetingSystemBaseComponent->mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    p_m_pTargetingSystemBaseComponent->mPrev = p_m_pTargetingSystemBaseComponent;
    p_m_pTargetingSystemBaseComponent->mNext = p_m_pTargetingSystemBaseComponent;
  }
  p_m_pTargetingSystemBaseComponent->m_pPointer = 0i64;
  if ( p_m_pTargetFormationManagerComponent->m_pPointer )
  {
    v8 = p_m_pTargetFormationManagerComponent->mPrev;
    v9 = p_m_pTargetFormationManagerComponent->mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    p_m_pTargetFormationManagerComponent->mPrev = p_m_pTargetFormationManagerComponent;
    p_m_pTargetFormationManagerComponent->mNext = p_m_pTargetFormationManagerComponent;
  }
  p_m_pTargetFormationManagerComponent->m_pPointer = 0i64;
}

// File Line: 5096
// RVA: 0x3375A0
void __fastcall GetInFormationTask::~GetInFormationTask(GetInFormationTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::AIScriptInterfaceComponent> *p_m_pAIScriptInterfaceComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *p_m_pTargetTargetingSystemBaseComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::FormationManagerComponent> *p_m_pTargetFormationManagerComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_m_pTargetTransformNodeComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v21; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *p_m_pTargetingSystemBaseComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v23; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v24; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v25; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v26; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::NavComponent> *p_m_pNavComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v28; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v29; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v30; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v31; // rax
  UFG::qSafePointer<UFG::GetInFormationNode,UFG::GetInFormationNode> *p_m_pGetInFormationNode; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInFormationNode>,UFG::qSafePointerNodeList> *v33; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInFormationNode>,UFG::qSafePointerNodeList> *v34; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInFormationNode>,UFG::qSafePointerNodeList> *v35; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInFormationNode>,UFG::qSafePointerNodeList> *v36; // rax
  UFG::qNode<ITask,ITask> *v37; // rcx
  UFG::qNode<ITask,ITask> *v38; // rax

  this->vfptr = (ITaskVtbl *)&GetInFormationTask::`vftable;
  p_m_pAIScriptInterfaceComponent = &this->m_pAIScriptInterfaceComponent;
  if ( this->m_pAIScriptInterfaceComponent.m_pPointer )
  {
    mPrev = p_m_pAIScriptInterfaceComponent->mPrev;
    mNext = p_m_pAIScriptInterfaceComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pAIScriptInterfaceComponent->mPrev = p_m_pAIScriptInterfaceComponent;
    p_m_pAIScriptInterfaceComponent->mNext = p_m_pAIScriptInterfaceComponent;
  }
  p_m_pAIScriptInterfaceComponent->m_pPointer = 0i64;
  v5 = p_m_pAIScriptInterfaceComponent->mPrev;
  v6 = p_m_pAIScriptInterfaceComponent->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_m_pAIScriptInterfaceComponent->mPrev = p_m_pAIScriptInterfaceComponent;
  p_m_pAIScriptInterfaceComponent->mNext = p_m_pAIScriptInterfaceComponent;
  p_m_pTargetTargetingSystemBaseComponent = &this->m_pTargetTargetingSystemBaseComponent;
  if ( this->m_pTargetTargetingSystemBaseComponent.m_pPointer )
  {
    v8 = p_m_pTargetTargetingSystemBaseComponent->mPrev;
    v9 = this->m_pTargetTargetingSystemBaseComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    p_m_pTargetTargetingSystemBaseComponent->mPrev = p_m_pTargetTargetingSystemBaseComponent;
    this->m_pTargetTargetingSystemBaseComponent.mNext = &this->m_pTargetTargetingSystemBaseComponent;
  }
  this->m_pTargetTargetingSystemBaseComponent.m_pPointer = 0i64;
  v10 = p_m_pTargetTargetingSystemBaseComponent->mPrev;
  v11 = this->m_pTargetTargetingSystemBaseComponent.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  p_m_pTargetTargetingSystemBaseComponent->mPrev = p_m_pTargetTargetingSystemBaseComponent;
  this->m_pTargetTargetingSystemBaseComponent.mNext = &this->m_pTargetTargetingSystemBaseComponent;
  p_m_pTargetFormationManagerComponent = &this->m_pTargetFormationManagerComponent;
  if ( this->m_pTargetFormationManagerComponent.m_pPointer )
  {
    v13 = p_m_pTargetFormationManagerComponent->mPrev;
    v14 = this->m_pTargetFormationManagerComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    p_m_pTargetFormationManagerComponent->mPrev = p_m_pTargetFormationManagerComponent;
    this->m_pTargetFormationManagerComponent.mNext = &this->m_pTargetFormationManagerComponent;
  }
  this->m_pTargetFormationManagerComponent.m_pPointer = 0i64;
  v15 = p_m_pTargetFormationManagerComponent->mPrev;
  v16 = this->m_pTargetFormationManagerComponent.mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  p_m_pTargetFormationManagerComponent->mPrev = p_m_pTargetFormationManagerComponent;
  this->m_pTargetFormationManagerComponent.mNext = &this->m_pTargetFormationManagerComponent;
  p_m_pTargetTransformNodeComponent = &this->m_pTargetTransformNodeComponent;
  if ( this->m_pTargetTransformNodeComponent.m_pPointer )
  {
    v18 = p_m_pTargetTransformNodeComponent->mPrev;
    v19 = this->m_pTargetTransformNodeComponent.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    p_m_pTargetTransformNodeComponent->mPrev = p_m_pTargetTransformNodeComponent;
    this->m_pTargetTransformNodeComponent.mNext = &this->m_pTargetTransformNodeComponent;
  }
  this->m_pTargetTransformNodeComponent.m_pPointer = 0i64;
  v20 = p_m_pTargetTransformNodeComponent->mPrev;
  v21 = this->m_pTargetTransformNodeComponent.mNext;
  v20->mNext = v21;
  v21->mPrev = v20;
  p_m_pTargetTransformNodeComponent->mPrev = p_m_pTargetTransformNodeComponent;
  this->m_pTargetTransformNodeComponent.mNext = &this->m_pTargetTransformNodeComponent;
  p_m_pTargetingSystemBaseComponent = &this->m_pTargetingSystemBaseComponent;
  if ( this->m_pTargetingSystemBaseComponent.m_pPointer )
  {
    v23 = p_m_pTargetingSystemBaseComponent->mPrev;
    v24 = this->m_pTargetingSystemBaseComponent.mNext;
    v23->mNext = v24;
    v24->mPrev = v23;
    p_m_pTargetingSystemBaseComponent->mPrev = p_m_pTargetingSystemBaseComponent;
    this->m_pTargetingSystemBaseComponent.mNext = &this->m_pTargetingSystemBaseComponent;
  }
  this->m_pTargetingSystemBaseComponent.m_pPointer = 0i64;
  v25 = p_m_pTargetingSystemBaseComponent->mPrev;
  v26 = this->m_pTargetingSystemBaseComponent.mNext;
  v25->mNext = v26;
  v26->mPrev = v25;
  p_m_pTargetingSystemBaseComponent->mPrev = p_m_pTargetingSystemBaseComponent;
  this->m_pTargetingSystemBaseComponent.mNext = &this->m_pTargetingSystemBaseComponent;
  p_m_pNavComponent = &this->m_pNavComponent;
  if ( this->m_pNavComponent.m_pPointer )
  {
    v28 = p_m_pNavComponent->mPrev;
    v29 = this->m_pNavComponent.mNext;
    v28->mNext = v29;
    v29->mPrev = v28;
    p_m_pNavComponent->mPrev = p_m_pNavComponent;
    this->m_pNavComponent.mNext = &this->m_pNavComponent;
  }
  this->m_pNavComponent.m_pPointer = 0i64;
  v30 = p_m_pNavComponent->mPrev;
  v31 = this->m_pNavComponent.mNext;
  v30->mNext = v31;
  v31->mPrev = v30;
  p_m_pNavComponent->mPrev = p_m_pNavComponent;
  this->m_pNavComponent.mNext = &this->m_pNavComponent;
  p_m_pGetInFormationNode = &this->m_pGetInFormationNode;
  if ( this->m_pGetInFormationNode.m_pPointer )
  {
    v33 = p_m_pGetInFormationNode->mPrev;
    v34 = this->m_pGetInFormationNode.mNext;
    v33->mNext = v34;
    v34->mPrev = v33;
    p_m_pGetInFormationNode->mPrev = p_m_pGetInFormationNode;
    this->m_pGetInFormationNode.mNext = &this->m_pGetInFormationNode;
  }
  this->m_pGetInFormationNode.m_pPointer = 0i64;
  v35 = p_m_pGetInFormationNode->mPrev;
  v36 = this->m_pGetInFormationNode.mNext;
  v35->mNext = v36;
  v36->mPrev = v35;
  p_m_pGetInFormationNode->mPrev = p_m_pGetInFormationNode;
  this->m_pGetInFormationNode.mNext = &this->m_pGetInFormationNode;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v37 = this->mPrev;
  v38 = this->mNext;
  v37->mNext = v38;
  v38->mPrev = v37;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 5101
// RVA: 0x361D20
void __fastcall GetInFormationTask::GetPointersToTargetsComponents(GetInFormationTask *this)
{
  UFG::GetInFormationNode *m_pPointer; // rax
  UFG::SimComponent *v3; // rcx
  UFG::SimObjectGame *v4; // rbx
  UFG::SimComponent *m_pComponent; // rdi
  UFG::SimComponent *v6; // r8
  __int16 m_Flags; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::FormationManagerComponent> *p_m_pTargetFormationManagerComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::SimComponent *m_pTransformNodeComponent; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_m_pTargetTransformNodeComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rax
  __int16 v18; // cx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *p_m_pTargetTargetingSystemBaseComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v21; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v22; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v23; // rax

  m_pPointer = this->m_pGetInFormationNode.m_pPointer;
  if ( m_pPointer )
  {
    v3 = this->m_pTargetingSystemBaseComponent.m_pPointer;
    if ( v3 )
    {
      v4 = *(UFG::SimObjectGame **)(56i64
                                  * *(unsigned __int8 *)((unsigned int)m_pPointer->m_TargetType
                                                       + *(_QWORD *)&v3[1].m_Flags
                                                       + 8i64)
                                  + *(_QWORD *)&v3[1].m_TypeUID
                                  + 40);
      m_pComponent = 0i64;
      if ( v4 )
      {
        m_Flags = v4->m_Flags;
        if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::FormationManagerComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v4, UFG::FormationManagerComponent::_TypeUID);
        v6 = ComponentOfTypeHK;
      }
      else
      {
        v6 = 0i64;
      }
      p_m_pTargetFormationManagerComponent = &this->m_pTargetFormationManagerComponent;
      if ( this->m_pTargetFormationManagerComponent.m_pPointer )
      {
        mPrev = p_m_pTargetFormationManagerComponent->mPrev;
        mNext = this->m_pTargetFormationManagerComponent.mNext;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        p_m_pTargetFormationManagerComponent->mPrev = p_m_pTargetFormationManagerComponent;
        this->m_pTargetFormationManagerComponent.mNext = &this->m_pTargetFormationManagerComponent;
      }
      this->m_pTargetFormationManagerComponent.m_pPointer = v6;
      if ( v6 )
      {
        v12 = v6->m_SafePointerList.mNode.mPrev;
        v12->mNext = p_m_pTargetFormationManagerComponent;
        p_m_pTargetFormationManagerComponent->mPrev = v12;
        this->m_pTargetFormationManagerComponent.mNext = &v6->m_SafePointerList.mNode;
        v6->m_SafePointerList.mNode.mPrev = p_m_pTargetFormationManagerComponent;
      }
      m_pTransformNodeComponent = 0i64;
      if ( v4 )
        m_pTransformNodeComponent = v4->m_pTransformNodeComponent;
      p_m_pTargetTransformNodeComponent = &this->m_pTargetTransformNodeComponent;
      if ( this->m_pTargetTransformNodeComponent.m_pPointer )
      {
        v15 = p_m_pTargetTransformNodeComponent->mPrev;
        v16 = this->m_pTargetTransformNodeComponent.mNext;
        v15->mNext = v16;
        v16->mPrev = v15;
        p_m_pTargetTransformNodeComponent->mPrev = p_m_pTargetTransformNodeComponent;
        this->m_pTargetTransformNodeComponent.mNext = &this->m_pTargetTransformNodeComponent;
      }
      this->m_pTargetTransformNodeComponent.m_pPointer = m_pTransformNodeComponent;
      if ( m_pTransformNodeComponent )
      {
        v17 = m_pTransformNodeComponent->m_SafePointerList.mNode.mPrev;
        v17->mNext = p_m_pTargetTransformNodeComponent;
        p_m_pTargetTransformNodeComponent->mPrev = v17;
        this->m_pTargetTransformNodeComponent.mNext = &m_pTransformNodeComponent->m_SafePointerList.mNode;
        m_pTransformNodeComponent->m_SafePointerList.mNode.mPrev = p_m_pTargetTransformNodeComponent;
      }
      if ( v4 )
      {
        v18 = v4->m_Flags;
        if ( (v18 & 0x4000) != 0 )
        {
          m_pComponent = v4->m_Components.p[20].m_pComponent;
        }
        else if ( v18 >= 0 )
        {
          if ( (v18 & 0x2000) != 0 || (v18 & 0x1000) != 0 )
            ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::TargetingSystemBaseComponent::_TypeUID);
          else
            ComponentOfType = UFG::SimObject::GetComponentOfType(v4, UFG::TargetingSystemBaseComponent::_TypeUID);
          m_pComponent = ComponentOfType;
        }
        else
        {
          m_pComponent = v4->m_Components.p[20].m_pComponent;
        }
      }
      p_m_pTargetTargetingSystemBaseComponent = &this->m_pTargetTargetingSystemBaseComponent;
      if ( this->m_pTargetTargetingSystemBaseComponent.m_pPointer )
      {
        v21 = p_m_pTargetTargetingSystemBaseComponent->mPrev;
        v22 = this->m_pTargetTargetingSystemBaseComponent.mNext;
        v21->mNext = v22;
        v22->mPrev = v21;
        p_m_pTargetTargetingSystemBaseComponent->mPrev = p_m_pTargetTargetingSystemBaseComponent;
        this->m_pTargetTargetingSystemBaseComponent.mNext = &this->m_pTargetTargetingSystemBaseComponent;
      }
      this->m_pTargetTargetingSystemBaseComponent.m_pPointer = m_pComponent;
      if ( m_pComponent )
      {
        v23 = m_pComponent->m_SafePointerList.mNode.mPrev;
        v23->mNext = p_m_pTargetTargetingSystemBaseComponent;
        p_m_pTargetTargetingSystemBaseComponent->mPrev = v23;
        this->m_pTargetTargetingSystemBaseComponent.mNext = &m_pComponent->m_SafePointerList.mNode;
        m_pComponent->m_SafePointerList.mNode.mPrev = p_m_pTargetTargetingSystemBaseComponent;
      }
    }
  }
}

// File Line: 5118
// RVA: 0x345330
void __fastcall GetInFormationTask::Begin(GetInFormationTask *this, ActionContext *action_context)
{
  char *v2; // rdi
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::SimComponent *m_pComponent; // r8
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::NavComponent> *p_m_pNavComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::SimObjectGame *v13; // rcx
  UFG::SimComponent *v14; // r8
  __int16 v15; // dx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *p_m_pTargetingSystemBaseComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rax
  UFG::SimObjectGame *v21; // rcx
  UFG::SimComponent *v22; // r8
  __int16 v23; // dx
  UFG::SimComponent *v24; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AIScriptInterfaceComponent> *p_m_pAIScriptInterfaceComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v26; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v27; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v28; // rax
  UFG::SimComponent *v29; // rcx
  int vfptr; // eax
  Expression::IMemberMapVtbl *v31; // r8
  Expression::IMemberMap *(__fastcall *GetResourceOwner)(Expression::IMemberMap *); // rax
  UFG::ActionTreeComponentBase *v33; // rdx
  UFG::ActionTreeComponentBase *v34; // rcx
  UFG::GetInFormationNode *v35; // r8
  UFG::qSafePointer<UFG::GetInFormationNode,UFG::GetInFormationNode> *p_m_pGetInFormationNode; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInFormationNode>,UFG::qSafePointerNodeList> *v37; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInFormationNode>,UFG::qSafePointerNodeList> *v38; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInFormationNode>,UFG::qSafePointerNodeList> *v39; // rax
  UFG::GetInFormationNode *value_uid; // [rsp+30h] [rbp+8h] BYREF

  v2 = 0i64;
  this->m_pActionContext = action_context;
  if ( action_context )
  {
    m_pPointer = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = m_pPointer->m_Components.p[36].m_pComponent;
      }
      else
      {
        if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::NavComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::NavComponent::_TypeUID);
        m_pComponent = ComponentOfTypeHK;
      }
    }
    else
    {
      m_pComponent = 0i64;
    }
    p_m_pNavComponent = &this->m_pNavComponent;
    if ( this->m_pNavComponent.m_pPointer )
    {
      mPrev = p_m_pNavComponent->mPrev;
      mNext = this->m_pNavComponent.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_m_pNavComponent->mPrev = p_m_pNavComponent;
      this->m_pNavComponent.mNext = &this->m_pNavComponent;
    }
    this->m_pNavComponent.m_pPointer = m_pComponent;
    if ( m_pComponent )
    {
      v12 = m_pComponent->m_SafePointerList.mNode.mPrev;
      v12->mNext = p_m_pNavComponent;
      p_m_pNavComponent->mPrev = v12;
      this->m_pNavComponent.mNext = &m_pComponent->m_SafePointerList.mNode;
      m_pComponent->m_SafePointerList.mNode.mPrev = p_m_pNavComponent;
    }
    v13 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
    if ( v13 )
    {
      v15 = v13->m_Flags;
      if ( (v15 & 0x4000) != 0 )
      {
        v14 = v13->m_Components.p[20].m_pComponent;
      }
      else if ( v15 >= 0 )
      {
        if ( (v15 & 0x2000) != 0 || (v15 & 0x1000) != 0 )
          ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::TargetingSystemBaseComponent::_TypeUID);
        else
          ComponentOfType = UFG::SimObject::GetComponentOfType(v13, UFG::TargetingSystemBaseComponent::_TypeUID);
        v14 = ComponentOfType;
      }
      else
      {
        v14 = v13->m_Components.p[20].m_pComponent;
      }
    }
    else
    {
      v14 = 0i64;
    }
    p_m_pTargetingSystemBaseComponent = &this->m_pTargetingSystemBaseComponent;
    if ( this->m_pTargetingSystemBaseComponent.m_pPointer )
    {
      v18 = p_m_pTargetingSystemBaseComponent->mPrev;
      v19 = this->m_pTargetingSystemBaseComponent.mNext;
      v18->mNext = v19;
      v19->mPrev = v18;
      p_m_pTargetingSystemBaseComponent->mPrev = p_m_pTargetingSystemBaseComponent;
      this->m_pTargetingSystemBaseComponent.mNext = &this->m_pTargetingSystemBaseComponent;
    }
    this->m_pTargetingSystemBaseComponent.m_pPointer = v14;
    if ( v14 )
    {
      v20 = v14->m_SafePointerList.mNode.mPrev;
      v20->mNext = p_m_pTargetingSystemBaseComponent;
      p_m_pTargetingSystemBaseComponent->mPrev = v20;
      this->m_pTargetingSystemBaseComponent.mNext = &v14->m_SafePointerList.mNode;
      v14->m_SafePointerList.mNode.mPrev = p_m_pTargetingSystemBaseComponent;
    }
    v21 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
    if ( v21 )
    {
      v23 = v21->m_Flags;
      if ( (v23 & 0x4000) != 0 )
      {
        v22 = v21->m_Components.p[5].m_pComponent;
      }
      else if ( v23 >= 0 )
      {
        if ( (v23 & 0x2000) != 0 || (v23 & 0x1000) != 0 )
          v24 = UFG::SimObjectGame::GetComponentOfTypeHK(v21, UFG::AIScriptInterfaceComponent::_TypeUID);
        else
          v24 = UFG::SimObject::GetComponentOfType(v21, UFG::AIScriptInterfaceComponent::_TypeUID);
        v22 = v24;
      }
      else
      {
        v22 = v21->m_Components.p[5].m_pComponent;
      }
    }
    else
    {
      v22 = 0i64;
    }
    p_m_pAIScriptInterfaceComponent = &this->m_pAIScriptInterfaceComponent;
    if ( this->m_pAIScriptInterfaceComponent.m_pPointer )
    {
      v26 = p_m_pAIScriptInterfaceComponent->mPrev;
      v27 = this->m_pAIScriptInterfaceComponent.mNext;
      v26->mNext = v27;
      v27->mPrev = v26;
      p_m_pAIScriptInterfaceComponent->mPrev = p_m_pAIScriptInterfaceComponent;
      this->m_pAIScriptInterfaceComponent.mNext = &this->m_pAIScriptInterfaceComponent;
    }
    this->m_pAIScriptInterfaceComponent.m_pPointer = v22;
    if ( v22 )
    {
      v28 = v22->m_SafePointerList.mNode.mPrev;
      v28->mNext = p_m_pAIScriptInterfaceComponent;
      p_m_pAIScriptInterfaceComponent->mPrev = v28;
      this->m_pAIScriptInterfaceComponent.mNext = &v22->m_SafePointerList.mNode;
      v22->m_SafePointerList.mNode.mPrev = p_m_pAIScriptInterfaceComponent;
    }
  }
  v29 = this->m_pNavComponent.m_pPointer;
  value_uid = 0i64;
  this->m_NavParams = *(UFG::NavParams *)((char *)&v29[2].m_BoundComponentHandles.mNode.mNext + 4);
  vfptr = (int)v29[3].vfptr;
  LOBYTE(v29[3].vfptr) = 0;
  LODWORD(v29[3].vfptr) |= vfptr & 0xFE;
  v31 = this->m_Track[1].vfptr;
  GetResourceOwner = v31->GetResourceOwner;
  if ( GetResourceOwner )
    v33 = (UFG::ActionTreeComponentBase *)((char *)&v31->GetResourceOwner + (_QWORD)GetResourceOwner);
  else
    v33 = 0i64;
  if ( GetResourceOwner )
    v2 = (char *)&v31->GetResourceOwner + (_QWORD)GetResourceOwner;
  v34 = action_context->mActionTreeComponentBase[v2[236]];
  if ( !v34 )
    v34 = action_context->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::GetMemoryValueImpl<UFG::GetInFormationNode *>(
    v34,
    v33,
    (ActionNodeRoot *)HIDWORD(v31->GetResourcePath),
    &value_uid);
  v35 = value_uid;
  p_m_pGetInFormationNode = &this->m_pGetInFormationNode;
  if ( this->m_pGetInFormationNode.m_pPointer )
  {
    v37 = p_m_pGetInFormationNode->mPrev;
    v38 = this->m_pGetInFormationNode.mNext;
    v37->mNext = v38;
    v38->mPrev = v37;
    p_m_pGetInFormationNode->mPrev = p_m_pGetInFormationNode;
    this->m_pGetInFormationNode.mNext = &this->m_pGetInFormationNode;
  }
  this->m_pGetInFormationNode.m_pPointer = v35;
  if ( v35 )
  {
    v39 = v35->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::GetInFormationNode>::mPrev;
    v39->mNext = p_m_pGetInFormationNode;
    p_m_pGetInFormationNode->mPrev = v39;
    this->m_pGetInFormationNode.mNext = &v35->m_SafePointerList.mNode;
    v35->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::GetInFormationNode>::mPrev = p_m_pGetInFormationNode;
  }
  GetInFormationTask::GetPointersToTargetsComponents(this);
}

// File Line: 5143
// RVA: 0x38F300
char __fastcall GetInFormationTask::Update(GetInFormationTask *this, float timestep)
{
  UFG::FormationManagerComponent *m_pPointer; // rsi
  UFG::GetInFormationNode *v4; // rdi
  __int64 m_RangeIndex; // rcx
  __int64 m_SlotIndex; // rax
  int v7; // eax
  bool v8; // r12
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // r15
  int v10; // r13d
  int v11; // ebp
  bool DesiredSpeed; // al
  UFG::GetInFormationNode *v13; // r10
  UFG::SimComponent *v14; // r11
  __int64 v15; // r9
  __int64 v16; // r8
  __int64 v17; // rdx
  char v18; // r14
  UFG::SimComponent *v19; // rax
  UFG::eMoveType v20; // edi
  UFG::SimObjectCVBase *v21; // rcx
  __int16 m_Flags; // dx
  UFG::SimObjectCharacterPropertiesComponent *v23; // rax
  bool v24; // r9
  UFG::SimObject *v25; // r8
  UFG::TransformNodeComponent *v26; // rsi
  UFG::GetInFormationNode *v27; // rax
  UFG::SimComponent *v28; // rdx
  float x; // xmm10_4
  UFG::SimObject *v30; // rcx
  float y; // xmm9_4
  float z; // xmm11_4
  __m128 x_low; // xmm6
  __m128 y_low; // xmm7
  __m128 z_low; // xmm8
  bool v36; // zf
  UFG::SimObjectCVBase *v37; // rcx
  __int16 v38; // dx
  UFG::AICharacterControllerBaseComponent *ComponentOfTypeHK; // rax
  UFG::qVector3 desired_position; // [rsp+30h] [rbp-F8h] BYREF
  UFG::HavokNavPosition npDestination; // [rsp+40h] [rbp-E8h] BYREF
  char DesiredPosition; // [rsp+130h] [rbp+8h]
  bool v44; // [rsp+140h] [rbp+18h]
  UFG::eMoveType move_type; // [rsp+148h] [rbp+20h] BYREF

  GetInFormationTask::GetPointersToTargetsComponents(this);
  m_pPointer = (UFG::FormationManagerComponent *)this->m_pTargetFormationManagerComponent.m_pPointer;
  if ( !m_pPointer )
    return 1;
  v4 = this->m_pGetInFormationNode.m_pPointer;
  if ( !v4 )
    return 1;
  m_RangeIndex = v4->m_RangeIndex;
  m_SlotIndex = v4->m_SlotIndex;
  if ( (_DWORD)m_RangeIndex != -1
    && (_DWORD)m_SlotIndex != -1
    && m_pPointer->mStateVariables.m_FormationSlot[m_RangeIndex][m_SlotIndex].m_pMember.m_pPointer == v4 )
  {
    v7 = UFG::FormationManagerComponent::GetInPositionType(m_pPointer, v4);
    v8 = m_pPointer->m_FormationFacingType == 1;
    m_pTransformNodeComponent = 0i64;
    desired_position = UFG::qVector3::msZero;
    v10 = v7;
    move_type = eMoveType_Undefined;
    v11 = 0;
    DesiredPosition = UFG::FormationManagerComponent::GetDesiredPosition(m_pPointer, v4, &desired_position);
    DesiredSpeed = UFG::FormationManagerComponent::GetDesiredSpeed(
                     (UFG::FormationManagerComponent *)this->m_pTargetFormationManagerComponent.m_pPointer,
                     this->m_pGetInFormationNode.m_pPointer,
                     &move_type);
    v13 = this->m_pGetInFormationNode.m_pPointer;
    v14 = this->m_pTargetFormationManagerComponent.m_pPointer;
    v44 = DesiredSpeed;
    if ( !v13
      || (v15 = v13->m_RangeIndex, v16 = v13->m_SlotIndex, (_DWORD)v15 == -1)
      || (_DWORD)v16 == -1
      || *((UFG::GetInFormationNode **)&v14[25 * v15 + 10].m_BoundComponentHandles.mNode.mPrev + 25 * v16) != v13 )
    {
      v18 = 0;
    }
    else
    {
      v11 = 1;
      v17 = 200 * (v16 + 8 * v15);
      if ( *(_DWORD *)((char *)&v14[10].m_SafePointerList.mNode.mNext + v17) != 3 )
        v11 = *(_DWORD *)((char *)&v14[12].m_SafePointerList.mNode.mNext + v17);
      v18 = 1;
    }
    v19 = this->m_pAIScriptInterfaceComponent.m_pPointer;
    if ( !v19 || (BYTE1(v19[32].m_BoundComponentHandles.mNode.mPrev) & 0x40) != 0 )
    {
      v20 = move_type;
    }
    else
    {
      v20 = move_type;
      if ( move_type == eMoveType_Run )
        v20 = eMoveType_Jog;
    }
    v21 = (UFG::SimObjectCVBase *)this->m_pActionContext->mSimObject.m_pPointer;
    v24 = 0;
    if ( v21 )
    {
      m_Flags = v21->m_Flags;
      if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
        v23 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v21);
      else
        v23 = (UFG::SimObjectCharacterPropertiesComponent *)((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                                           ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               v21,
                                                               UFG::SimObjectCharacterPropertiesComponent::_TypeUID)
                                                           : UFG::SimObject::GetComponentOfType(
                                                               v21,
                                                               UFG::SimObjectCharacterPropertiesComponent::_TypeUID));
      if ( v23 && v23->m_eFightingClass == eFIGHTING_CLASS_STRIKER_BRAWLER )
        v24 = 1;
    }
    v25 = this->m_pActionContext->mSimObject.m_pPointer;
    if ( v25
      && v25->m_pTransformNodeComponent
      && (v26 = (UFG::TransformNodeComponent *)this->m_pTargetTransformNodeComponent.m_pPointer) != 0i64
      && (v27 = this->m_pGetInFormationNode.m_pPointer) != 0i64
      && v27->m_AttackType == eATTACK_TYPE_MELEE
      && (v28 = this->m_pTargetTargetingSystemBaseComponent.m_pPointer) != 0i64
      && *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v28[1].m_Flags + 30i64)
                            + *(_QWORD *)&v28[1].m_TypeUID
                            + 40) == v25
      && !v24 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(v26);
      x = v26->mWorldTransform.v3.x;
      v30 = this->m_pActionContext->mSimObject.m_pPointer;
      y = v26->mWorldTransform.v3.y;
      z = v26->mWorldTransform.v3.z;
      if ( v30 )
        m_pTransformNodeComponent = v30->m_pTransformNodeComponent;
      UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
      x_low = (__m128)LODWORD(desired_position.x);
      y_low = (__m128)LODWORD(desired_position.y);
      z_low = (__m128)LODWORD(desired_position.z);
      if ( (float)((float)((float)((float)(y - m_pTransformNodeComponent->mWorldTransform.v3.y)
                                 * (float)(desired_position.y - m_pTransformNodeComponent->mWorldTransform.v3.y))
                         + (float)((float)(x - m_pTransformNodeComponent->mWorldTransform.v3.x)
                                 * (float)(desired_position.x - m_pTransformNodeComponent->mWorldTransform.v3.x)))
                 + (float)((float)(z - m_pTransformNodeComponent->mWorldTransform.v3.z)
                         * (float)(desired_position.z - m_pTransformNodeComponent->mWorldTransform.v3.z))) < 0.0 )
      {
        UFG::FormationManagerComponent::SetInPositionType(
          (UFG::FormationManagerComponent *)this->m_pTargetFormationManagerComponent.m_pPointer,
          this->m_pGetInFormationNode.m_pPointer,
          0);
        UFG::FormationManagerComponent::SetDesiredDirectionFromCurrentPosition(
          (UFG::FormationManagerComponent *)this->m_pTargetFormationManagerComponent.m_pPointer,
          this->m_pGetInFormationNode.m_pPointer);
        goto LABEL_44;
      }
    }
    else
    {
      z_low = (__m128)LODWORD(desired_position.z);
      y_low = (__m128)LODWORD(desired_position.y);
      x_low = (__m128)LODWORD(desired_position.x);
    }
    if ( v10 && DesiredPosition && v44 && v18 )
    {
      LODWORD(npDestination.m_vPosition.x) = x_low.m128_i32[0];
      LODWORD(npDestination.m_vPosition.y) = y_low.m128_i32[0];
      npDestination.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
      LODWORD(npDestination.m_vPosition.z) = z_low.m128_i32[0];
      npDestination.m_bValid = 0;
      *(_QWORD *)&npDestination.m_packedKey = -1i64;
      npDestination.m_hkvMeshPosition.m_quad = _mm_unpacklo_ps(
                                                 _mm_unpacklo_ps(x_low, z_low),
                                                 _mm_unpacklo_ps(y_low, (__m128)(unsigned int)FLOAT_1_0));
      UFG::NavComponent::AddGoalPoint(
        (UFG::NavComponent *)this->m_pNavComponent.m_pPointer,
        &npDestination,
        AiGoal_Replace,
        sNaturalMovementSpeeds[v20],
        0.5);
      if ( UFG::NavComponent::IsAtDestination((UFG::NavComponent *)this->m_pNavComponent.m_pPointer) )
        UFG::FormationManagerComponent::SetInPositionType(
          (UFG::FormationManagerComponent *)this->m_pTargetFormationManagerComponent.m_pPointer,
          this->m_pGetInFormationNode.m_pPointer,
          0);
      if ( !v11 )
        return 1;
      v36 = v20 == eMoveType_Run;
      goto LABEL_45;
    }
LABEL_44:
    v36 = !v8;
LABEL_45:
    if ( !v36 )
    {
      v37 = (UFG::SimObjectCVBase *)this->m_pActionContext->mSimObject.m_pPointer;
      if ( v37 )
      {
        v38 = v37->m_Flags;
        if ( (v38 & 0x4000) != 0 || v38 < 0 )
        {
          ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v37);
        }
        else if ( (v38 & 0x2000) != 0 || (v38 & 0x1000) != 0 )
        {
          ComponentOfTypeHK = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                           v37,
                                                                           UFG::AICharacterControllerBaseComponent::_TypeUID);
        }
        else
        {
          ComponentOfTypeHK = (UFG::AICharacterControllerBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                                           v37,
                                                                           UFG::AICharacterControllerBaseComponent::_TypeUID);
        }
        if ( ComponentOfTypeHK )
          Intention::Set(&ComponentOfTypeHK->m_Intention, gActionRequest_Focus.m_EnumValue, 0.0);
      }
    }
    return 1;
  }
  return 0;
}

// File Line: 5297
// RVA: 0x3550A0
void __fastcall GetInFormationTask::End(GetInFormationTask *this)
{
  UFG::SimComponent *m_pPointer; // rax

  m_pPointer = this->m_pNavComponent.m_pPointer;
  if ( m_pPointer )
  {
    if ( (this->m_NavParams.m_flags & 1) != 0 )
      LODWORD(m_pPointer[3].vfptr) |= 1u;
  }
}

// File Line: 5317
// RVA: 0x32F130
void __fastcall GetInPedFormationTask::GetInPedFormationTask(GetInPedFormationTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::NavComponent> *p_m_pNavComponent; // r10
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pAIEntityComponent; // r9
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *p_m_pTargetingSystemBaseComponent; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::PedFormationManagerComponent> *p_m_pTargetPedFormationManagerComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rax

  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<GetInPedFormationTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&GetInPedFormationTask::`vftable;
  this->m_pGetInPedFormationNode.mPrev = &this->m_pGetInPedFormationNode;
  this->m_pGetInPedFormationNode.mNext = &this->m_pGetInPedFormationNode;
  this->m_pGetInPedFormationNode.m_pPointer = 0i64;
  p_m_pNavComponent = &this->m_pNavComponent;
  this->m_pNavComponent.mPrev = &this->m_pNavComponent;
  this->m_pNavComponent.mNext = &this->m_pNavComponent;
  this->m_pNavComponent.m_pPointer = 0i64;
  p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.mPrev = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.m_pPointer = 0i64;
  p_m_pTargetingSystemBaseComponent = &this->m_pTargetingSystemBaseComponent;
  this->m_pTargetingSystemBaseComponent.mPrev = &this->m_pTargetingSystemBaseComponent;
  this->m_pTargetingSystemBaseComponent.mNext = &this->m_pTargetingSystemBaseComponent;
  this->m_pTargetingSystemBaseComponent.m_pPointer = 0i64;
  p_m_pTargetPedFormationManagerComponent = &this->m_pTargetPedFormationManagerComponent;
  this->m_pTargetPedFormationManagerComponent.mPrev = &this->m_pTargetPedFormationManagerComponent;
  this->m_pTargetPedFormationManagerComponent.mNext = &this->m_pTargetPedFormationManagerComponent;
  this->m_pTargetPedFormationManagerComponent.m_pPointer = 0i64;
  this->m_pActionContext = 0i64;
  if ( this->m_pNavComponent.m_pPointer )
  {
    mPrev = p_m_pNavComponent->mPrev;
    mNext = p_m_pNavComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pNavComponent->mPrev = p_m_pNavComponent;
    p_m_pNavComponent->mNext = p_m_pNavComponent;
  }
  p_m_pNavComponent->m_pPointer = 0i64;
  if ( p_m_pAIEntityComponent->m_pPointer )
  {
    v8 = p_m_pAIEntityComponent->mPrev;
    v9 = p_m_pAIEntityComponent->mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
    p_m_pAIEntityComponent->mNext = p_m_pAIEntityComponent;
  }
  p_m_pAIEntityComponent->m_pPointer = 0i64;
  if ( p_m_pTargetingSystemBaseComponent->m_pPointer )
  {
    v10 = p_m_pTargetingSystemBaseComponent->mPrev;
    v11 = p_m_pTargetingSystemBaseComponent->mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    p_m_pTargetingSystemBaseComponent->mPrev = p_m_pTargetingSystemBaseComponent;
    p_m_pTargetingSystemBaseComponent->mNext = p_m_pTargetingSystemBaseComponent;
  }
  p_m_pTargetingSystemBaseComponent->m_pPointer = 0i64;
  if ( p_m_pTargetPedFormationManagerComponent->m_pPointer )
  {
    v12 = p_m_pTargetPedFormationManagerComponent->mPrev;
    v13 = p_m_pTargetPedFormationManagerComponent->mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    p_m_pTargetPedFormationManagerComponent->mPrev = p_m_pTargetPedFormationManagerComponent;
    p_m_pTargetPedFormationManagerComponent->mNext = p_m_pTargetPedFormationManagerComponent;
  }
  p_m_pTargetPedFormationManagerComponent->m_pPointer = 0i64;
  this->m_PreviousGoalReachedThreshold = 0.0;
}

// File Line: 5331
// RVA: 0x337AF0
void __fastcall GetInPedFormationTask::~GetInPedFormationTask(GetInPedFormationTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::PedFormationManagerComponent> *p_m_pTargetPedFormationManagerComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *p_m_pTargetingSystemBaseComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pAIEntityComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::NavComponent> *p_m_pNavComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v21; // rax
  UFG::qSafePointer<UFG::GetInPedFormationNode,UFG::GetInPedFormationNode> *p_m_pGetInPedFormationNode; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInPedFormationNode>,UFG::qSafePointerNodeList> *v23; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInPedFormationNode>,UFG::qSafePointerNodeList> *v24; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInPedFormationNode>,UFG::qSafePointerNodeList> *v25; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInPedFormationNode>,UFG::qSafePointerNodeList> *v26; // rax
  UFG::qNode<ITask,ITask> *v27; // rcx
  UFG::qNode<ITask,ITask> *v28; // rax

  this->vfptr = (ITaskVtbl *)&GetInPedFormationTask::`vftable;
  p_m_pTargetPedFormationManagerComponent = &this->m_pTargetPedFormationManagerComponent;
  if ( this->m_pTargetPedFormationManagerComponent.m_pPointer )
  {
    mPrev = p_m_pTargetPedFormationManagerComponent->mPrev;
    mNext = p_m_pTargetPedFormationManagerComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pTargetPedFormationManagerComponent->mPrev = p_m_pTargetPedFormationManagerComponent;
    p_m_pTargetPedFormationManagerComponent->mNext = p_m_pTargetPedFormationManagerComponent;
  }
  p_m_pTargetPedFormationManagerComponent->m_pPointer = 0i64;
  v5 = p_m_pTargetPedFormationManagerComponent->mPrev;
  v6 = p_m_pTargetPedFormationManagerComponent->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_m_pTargetPedFormationManagerComponent->mPrev = p_m_pTargetPedFormationManagerComponent;
  p_m_pTargetPedFormationManagerComponent->mNext = p_m_pTargetPedFormationManagerComponent;
  p_m_pTargetingSystemBaseComponent = &this->m_pTargetingSystemBaseComponent;
  if ( this->m_pTargetingSystemBaseComponent.m_pPointer )
  {
    v8 = p_m_pTargetingSystemBaseComponent->mPrev;
    v9 = this->m_pTargetingSystemBaseComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    p_m_pTargetingSystemBaseComponent->mPrev = p_m_pTargetingSystemBaseComponent;
    this->m_pTargetingSystemBaseComponent.mNext = &this->m_pTargetingSystemBaseComponent;
  }
  this->m_pTargetingSystemBaseComponent.m_pPointer = 0i64;
  v10 = p_m_pTargetingSystemBaseComponent->mPrev;
  v11 = this->m_pTargetingSystemBaseComponent.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  p_m_pTargetingSystemBaseComponent->mPrev = p_m_pTargetingSystemBaseComponent;
  this->m_pTargetingSystemBaseComponent.mNext = &this->m_pTargetingSystemBaseComponent;
  p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
  if ( this->m_pAIEntityComponent.m_pPointer )
  {
    v13 = p_m_pAIEntityComponent->mPrev;
    v14 = this->m_pAIEntityComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
    this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
  }
  this->m_pAIEntityComponent.m_pPointer = 0i64;
  v15 = p_m_pAIEntityComponent->mPrev;
  v16 = this->m_pAIEntityComponent.mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
  this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
  p_m_pNavComponent = &this->m_pNavComponent;
  if ( this->m_pNavComponent.m_pPointer )
  {
    v18 = p_m_pNavComponent->mPrev;
    v19 = this->m_pNavComponent.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    p_m_pNavComponent->mPrev = p_m_pNavComponent;
    this->m_pNavComponent.mNext = &this->m_pNavComponent;
  }
  this->m_pNavComponent.m_pPointer = 0i64;
  v20 = p_m_pNavComponent->mPrev;
  v21 = this->m_pNavComponent.mNext;
  v20->mNext = v21;
  v21->mPrev = v20;
  p_m_pNavComponent->mPrev = p_m_pNavComponent;
  this->m_pNavComponent.mNext = &this->m_pNavComponent;
  p_m_pGetInPedFormationNode = &this->m_pGetInPedFormationNode;
  if ( this->m_pGetInPedFormationNode.m_pPointer )
  {
    v23 = p_m_pGetInPedFormationNode->mPrev;
    v24 = this->m_pGetInPedFormationNode.mNext;
    v23->mNext = v24;
    v24->mPrev = v23;
    p_m_pGetInPedFormationNode->mPrev = p_m_pGetInPedFormationNode;
    this->m_pGetInPedFormationNode.mNext = &this->m_pGetInPedFormationNode;
  }
  this->m_pGetInPedFormationNode.m_pPointer = 0i64;
  v25 = p_m_pGetInPedFormationNode->mPrev;
  v26 = this->m_pGetInPedFormationNode.mNext;
  v25->mNext = v26;
  v26->mPrev = v25;
  p_m_pGetInPedFormationNode->mPrev = p_m_pGetInPedFormationNode;
  this->m_pGetInPedFormationNode.mNext = &this->m_pGetInPedFormationNode;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v27 = this->mPrev;
  v28 = this->mNext;
  v27->mNext = v28;
  v28->mPrev = v27;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 5336
// RVA: 0x345660
void __fastcall GetInPedFormationTask::Begin(GetInPedFormationTask *this, ActionContext *action_context)
{
  char *v2; // rdi
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::SimComponent *m_pComponent; // r8
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::NavComponent> *p_m_pNavComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::SimObjectCVBase *v13; // rcx
  UFG::SimComponent *v14; // r8
  __int16 v15; // dx
  UFG::ActiveAIEntityComponent *ComponentOfType; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pAIEntityComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rax
  UFG::SimObjectGame *v21; // rcx
  UFG::SimComponent *v22; // r8
  __int16 v23; // dx
  UFG::SimComponent *v24; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *p_m_pTargetingSystemBaseComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v26; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v27; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v28; // rax
  ITrack *m_Track; // rax
  Expression::IMemberMapVtbl *vfptr; // r8
  Expression::IMemberMap *(__fastcall *GetResourceOwner)(Expression::IMemberMap *); // rax
  UFG::ActionTreeComponentBase *v32; // rdx
  UFG::ActionTreeComponentBase *v33; // rcx
  UFG::GetInPedFormationNode *v34; // r8
  UFG::qSafePointer<UFG::GetInPedFormationNode,UFG::GetInPedFormationNode> *p_m_pGetInPedFormationNode; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInPedFormationNode>,UFG::qSafePointerNodeList> *v36; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInPedFormationNode>,UFG::qSafePointerNodeList> *v37; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInPedFormationNode>,UFG::qSafePointerNodeList> *v38; // rax
  UFG::GroupComponent *GroupComponent; // rax
  UFG::GroupComponent *v40; // rax
  UFG::PedSpawningInfo *mOwner; // rcx
  UFG::SimObjectGame *v42; // rcx
  __int16 v43; // dx
  UFG::SimComponent *v44; // rax
  unsigned int v45; // edx
  bool v46; // zf
  UFG::GetInPedFormationNode *value_uid; // [rsp+30h] [rbp+8h] BYREF

  v2 = 0i64;
  this->m_pActionContext = action_context;
  if ( action_context )
  {
    m_pPointer = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = m_pPointer->m_Components.p[36].m_pComponent;
      }
      else
      {
        if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::NavComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::NavComponent::_TypeUID);
        m_pComponent = ComponentOfTypeHK;
      }
    }
    else
    {
      m_pComponent = 0i64;
    }
    p_m_pNavComponent = &this->m_pNavComponent;
    if ( this->m_pNavComponent.m_pPointer )
    {
      mPrev = p_m_pNavComponent->mPrev;
      mNext = this->m_pNavComponent.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_m_pNavComponent->mPrev = p_m_pNavComponent;
      this->m_pNavComponent.mNext = &this->m_pNavComponent;
    }
    this->m_pNavComponent.m_pPointer = m_pComponent;
    if ( m_pComponent )
    {
      v12 = m_pComponent->m_SafePointerList.mNode.mPrev;
      v12->mNext = p_m_pNavComponent;
      p_m_pNavComponent->mPrev = v12;
      this->m_pNavComponent.mNext = &m_pComponent->m_SafePointerList.mNode;
      m_pComponent->m_SafePointerList.mNode.mPrev = p_m_pNavComponent;
    }
    v13 = (UFG::SimObjectCVBase *)this->m_pActionContext->mSimObject.m_pPointer;
    if ( v13 )
    {
      v15 = v13->m_Flags;
      if ( (v15 & 0x4000) != 0 || v15 < 0 )
      {
        ComponentOfType = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v13);
      }
      else if ( (v15 & 0x2000) != 0 || (v15 & 0x1000) != 0 )
      {
        ComponentOfType = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            v13,
                                                            UFG::ActiveAIEntityComponent::_TypeUID);
      }
      else
      {
        ComponentOfType = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                            v13,
                                                            UFG::ActiveAIEntityComponent::_TypeUID);
      }
      v14 = ComponentOfType;
    }
    else
    {
      v14 = 0i64;
    }
    p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
    if ( this->m_pAIEntityComponent.m_pPointer )
    {
      v18 = p_m_pAIEntityComponent->mPrev;
      v19 = this->m_pAIEntityComponent.mNext;
      v18->mNext = v19;
      v19->mPrev = v18;
      p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
      this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
    }
    this->m_pAIEntityComponent.m_pPointer = v14;
    if ( v14 )
    {
      v20 = v14->m_SafePointerList.mNode.mPrev;
      v20->mNext = p_m_pAIEntityComponent;
      p_m_pAIEntityComponent->mPrev = v20;
      this->m_pAIEntityComponent.mNext = &v14->m_SafePointerList.mNode;
      v14->m_SafePointerList.mNode.mPrev = p_m_pAIEntityComponent;
    }
    v21 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
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
    p_m_pTargetingSystemBaseComponent = &this->m_pTargetingSystemBaseComponent;
    if ( this->m_pTargetingSystemBaseComponent.m_pPointer )
    {
      v26 = p_m_pTargetingSystemBaseComponent->mPrev;
      v27 = this->m_pTargetingSystemBaseComponent.mNext;
      v26->mNext = v27;
      v27->mPrev = v26;
      p_m_pTargetingSystemBaseComponent->mPrev = p_m_pTargetingSystemBaseComponent;
      this->m_pTargetingSystemBaseComponent.mNext = &this->m_pTargetingSystemBaseComponent;
    }
    this->m_pTargetingSystemBaseComponent.m_pPointer = v22;
    if ( v22 )
    {
      v28 = v22->m_SafePointerList.mNode.mPrev;
      v28->mNext = p_m_pTargetingSystemBaseComponent;
      p_m_pTargetingSystemBaseComponent->mPrev = v28;
      this->m_pTargetingSystemBaseComponent.mNext = &v22->m_SafePointerList.mNode;
      v22->m_SafePointerList.mNode.mPrev = p_m_pTargetingSystemBaseComponent;
    }
  }
  m_Track = this->m_Track;
  value_uid = 0i64;
  vfptr = m_Track[1].vfptr;
  GetResourceOwner = vfptr->GetResourceOwner;
  if ( GetResourceOwner )
    v32 = (UFG::ActionTreeComponentBase *)((char *)&vfptr->GetResourceOwner + (_QWORD)GetResourceOwner);
  else
    v32 = 0i64;
  if ( GetResourceOwner )
    v2 = (char *)&vfptr->GetResourceOwner + (_QWORD)GetResourceOwner;
  v33 = action_context->mActionTreeComponentBase[v2[236]];
  if ( !v33 )
    v33 = action_context->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::GetMemoryValueImpl<UFG::GetInPedFormationNode *>(
    v33,
    v32,
    (ActionNodeRoot *)HIDWORD(vfptr->GetResourcePath),
    (UFG::qBaseNodeVariableRB<unsigned __int64> **)&value_uid);
  v34 = value_uid;
  p_m_pGetInPedFormationNode = &this->m_pGetInPedFormationNode;
  if ( this->m_pGetInPedFormationNode.m_pPointer )
  {
    v36 = p_m_pGetInPedFormationNode->mPrev;
    v37 = this->m_pGetInPedFormationNode.mNext;
    v36->mNext = v37;
    v37->mPrev = v36;
    p_m_pGetInPedFormationNode->mPrev = p_m_pGetInPedFormationNode;
    this->m_pGetInPedFormationNode.mNext = &this->m_pGetInPedFormationNode;
  }
  this->m_pGetInPedFormationNode.m_pPointer = v34;
  if ( v34 )
  {
    v38 = v34->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::GetInPedFormationNode>::mPrev;
    v38->mNext = p_m_pGetInPedFormationNode;
    p_m_pGetInPedFormationNode->mPrev = v38;
    this->m_pGetInPedFormationNode.mNext = &v34->m_SafePointerList.mNode;
    v34->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::GetInPedFormationNode>::mPrev = p_m_pGetInPedFormationNode;
  }
  if ( this->m_pGetInPedFormationNode.m_pPointer )
  {
    GroupComponent = UFG::GroupComponent::GetGroupComponent(this->m_pActionContext->mSimObject.m_pPointer);
    if ( GroupComponent )
    {
      v40 = GroupComponent->mGroupFollower.mLeader.m_pPointer;
      if ( v40 )
      {
        mOwner = v40->mOwner;
        if ( mOwner )
        {
          v42 = (UFG::SimObjectGame *)mOwner->mSimObjectPtr.m_pPointer;
          if ( v42 )
          {
            v43 = v42->m_Flags;
            if ( (v43 & 0x4000) != 0 )
            {
              v44 = v42->m_Components.p[33].m_pComponent;
            }
            else
            {
              if ( v43 < 0 || (v43 & 0x2000) != 0 )
              {
                v45 = UFG::PedFormationManagerComponent::_TypeUID;
              }
              else
              {
                v46 = (v43 & 0x1000) == 0;
                v45 = UFG::PedFormationManagerComponent::_TypeUID;
                if ( v46 )
                {
                  v44 = UFG::SimObject::GetComponentOfType(v42, UFG::PedFormationManagerComponent::_TypeUID);
                  goto LABEL_70;
                }
              }
              v44 = UFG::SimObjectGame::GetComponentOfTypeHK(v42, v45);
            }
LABEL_70:
            UFG::qSafePointer<Creature,Creature>::operator=(
              (UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *)&this->m_pTargetPedFormationManagerComponent,
              v44);
          }
        }
      }
    }
  }
}

// File Line: 5386
// RVA: 0x38F8A0
char __fastcall GetInPedFormationTask::Update(GetInPedFormationTask *this, float timestep)
{
  UFG::PedFormationManagerComponent *m_pPointer; // rbx
  UFG::GetInPedFormationNode *v4; // rdx
  UFG::NavComponent *v5; // rbx
  float fDestinationTolerance; // xmm0_4
  UFG::qVector3 desired_waypoint; // [rsp+30h] [rbp-58h] BYREF
  UFG::HavokNavPosition npDestination; // [rsp+40h] [rbp-48h] BYREF
  float desired_speed; // [rsp+90h] [rbp+8h] BYREF

  if ( !this->m_pAIEntityComponent.m_pPointer )
    return 1;
  m_pPointer = (UFG::PedFormationManagerComponent *)this->m_pTargetPedFormationManagerComponent.m_pPointer;
  if ( m_pPointer )
  {
    if ( this->m_pGetInPedFormationNode.m_pPointer )
    {
      if ( (unsigned int)UFG::PedFormationManagerComponent::GetInPositionType(
                           (UFG::PedFormationManagerComponent *)this->m_pTargetPedFormationManagerComponent.m_pPointer,
                           this->m_pGetInPedFormationNode.m_pPointer) )
      {
        v4 = this->m_pGetInPedFormationNode.m_pPointer;
        desired_waypoint = UFG::qVector3::msZero;
        desired_speed = 0.0;
        if ( UFG::PedFormationManagerComponent::GetDesiredWaypoint(m_pPointer, v4, &desired_waypoint, &desired_speed) )
        {
          v5 = (UFG::NavComponent *)this->m_pNavComponent.m_pPointer;
          npDestination.m_bValid = 0;
          npDestination.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
          *(_QWORD *)&npDestination.m_packedKey = -1i64;
          npDestination.m_vPosition = desired_waypoint;
          npDestination.m_hkvMeshPosition.m_quad = _mm_unpacklo_ps(
                                                     _mm_unpacklo_ps(
                                                       (__m128)LODWORD(desired_waypoint.x),
                                                       (__m128)LODWORD(desired_waypoint.z)),
                                                     _mm_unpacklo_ps(
                                                       (__m128)LODWORD(desired_waypoint.y),
                                                       (__m128)(unsigned int)FLOAT_1_0));
          fDestinationTolerance = UFG::NavComponent::GetAvoidanceRadius(v5);
          UFG::NavComponent::AddGoalPoint(v5, &npDestination, AiGoal_Replace, desired_speed, fDestinationTolerance);
          if ( UFG::NavComponent::IsAtDestination((UFG::NavComponent *)this->m_pNavComponent.m_pPointer) )
            UFG::PedFormationManagerComponent::OnArrived(
              (UFG::PedFormationManagerComponent *)this->m_pTargetPedFormationManagerComponent.m_pPointer,
              this->m_pGetInPedFormationNode.m_pPointer,
              &desired_waypoint,
              desired_speed);
        }
      }
    }
  }
  return 1;
}

// File Line: 5483
// RVA: 0x32FF40
void __fastcall InvalidateFormationPositionTask::InvalidateFormationPositionTask(InvalidateFormationPositionTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pAIEntityComponent; // r9
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *p_m_pTargetingSystemBaseComponent; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::FormationManagerComponent> *p_m_pTargetFormationManagerComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax

  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<InvalidateFormationPositionTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&InvalidateFormationPositionTask::`vftable;
  p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.mPrev = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.m_pPointer = 0i64;
  p_m_pTargetingSystemBaseComponent = &this->m_pTargetingSystemBaseComponent;
  this->m_pTargetingSystemBaseComponent.mPrev = &this->m_pTargetingSystemBaseComponent;
  this->m_pTargetingSystemBaseComponent.mNext = &this->m_pTargetingSystemBaseComponent;
  this->m_pTargetingSystemBaseComponent.m_pPointer = 0i64;
  p_m_pTargetFormationManagerComponent = &this->m_pTargetFormationManagerComponent;
  this->m_pTargetFormationManagerComponent.mPrev = &this->m_pTargetFormationManagerComponent;
  this->m_pTargetFormationManagerComponent.mNext = &this->m_pTargetFormationManagerComponent;
  this->m_pTargetFormationManagerComponent.m_pPointer = 0i64;
  this->m_pActionContext = 0i64;
  if ( this->m_pAIEntityComponent.m_pPointer )
  {
    mPrev = p_m_pAIEntityComponent->mPrev;
    mNext = p_m_pAIEntityComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
    p_m_pAIEntityComponent->mNext = p_m_pAIEntityComponent;
  }
  p_m_pAIEntityComponent->m_pPointer = 0i64;
  if ( p_m_pTargetingSystemBaseComponent->m_pPointer )
  {
    v6 = p_m_pTargetingSystemBaseComponent->mPrev;
    v7 = p_m_pTargetingSystemBaseComponent->mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    p_m_pTargetingSystemBaseComponent->mPrev = p_m_pTargetingSystemBaseComponent;
    p_m_pTargetingSystemBaseComponent->mNext = p_m_pTargetingSystemBaseComponent;
  }
  p_m_pTargetingSystemBaseComponent->m_pPointer = 0i64;
  if ( p_m_pTargetFormationManagerComponent->m_pPointer )
  {
    v8 = p_m_pTargetFormationManagerComponent->mPrev;
    v9 = p_m_pTargetFormationManagerComponent->mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    p_m_pTargetFormationManagerComponent->mPrev = p_m_pTargetFormationManagerComponent;
    p_m_pTargetFormationManagerComponent->mNext = p_m_pTargetFormationManagerComponent;
  }
  p_m_pTargetFormationManagerComponent->m_pPointer = 0i64;
}

// File Line: 5494
// RVA: 0x338C60
void __fastcall InvalidateFormationPositionTask::~InvalidateFormationPositionTask(
        InvalidateFormationPositionTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::FormationManagerComponent> *p_m_pTargetFormationManagerComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *p_m_pTargetingSystemBaseComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pAIEntityComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qNode<ITask,ITask> *v17; // rcx
  UFG::qNode<ITask,ITask> *v18; // rax

  this->vfptr = (ITaskVtbl *)&InvalidateFormationPositionTask::`vftable;
  p_m_pTargetFormationManagerComponent = &this->m_pTargetFormationManagerComponent;
  if ( this->m_pTargetFormationManagerComponent.m_pPointer )
  {
    mPrev = p_m_pTargetFormationManagerComponent->mPrev;
    mNext = p_m_pTargetFormationManagerComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pTargetFormationManagerComponent->mPrev = p_m_pTargetFormationManagerComponent;
    p_m_pTargetFormationManagerComponent->mNext = p_m_pTargetFormationManagerComponent;
  }
  p_m_pTargetFormationManagerComponent->m_pPointer = 0i64;
  v5 = p_m_pTargetFormationManagerComponent->mPrev;
  v6 = p_m_pTargetFormationManagerComponent->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_m_pTargetFormationManagerComponent->mPrev = p_m_pTargetFormationManagerComponent;
  p_m_pTargetFormationManagerComponent->mNext = p_m_pTargetFormationManagerComponent;
  p_m_pTargetingSystemBaseComponent = &this->m_pTargetingSystemBaseComponent;
  if ( this->m_pTargetingSystemBaseComponent.m_pPointer )
  {
    v8 = p_m_pTargetingSystemBaseComponent->mPrev;
    v9 = this->m_pTargetingSystemBaseComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    p_m_pTargetingSystemBaseComponent->mPrev = p_m_pTargetingSystemBaseComponent;
    this->m_pTargetingSystemBaseComponent.mNext = &this->m_pTargetingSystemBaseComponent;
  }
  this->m_pTargetingSystemBaseComponent.m_pPointer = 0i64;
  v10 = p_m_pTargetingSystemBaseComponent->mPrev;
  v11 = this->m_pTargetingSystemBaseComponent.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  p_m_pTargetingSystemBaseComponent->mPrev = p_m_pTargetingSystemBaseComponent;
  this->m_pTargetingSystemBaseComponent.mNext = &this->m_pTargetingSystemBaseComponent;
  p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
  if ( this->m_pAIEntityComponent.m_pPointer )
  {
    v13 = p_m_pAIEntityComponent->mPrev;
    v14 = this->m_pAIEntityComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
    this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
  }
  this->m_pAIEntityComponent.m_pPointer = 0i64;
  v15 = p_m_pAIEntityComponent->mPrev;
  v16 = this->m_pAIEntityComponent.mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
  this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v17 = this->mPrev;
  v18 = this->mNext;
  v17->mNext = v18;
  v18->mPrev = v17;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 5499
// RVA: 0x346550
void __fastcall InvalidateFormationPositionTask::Begin(
        InvalidateFormationPositionTask *this,
        ActionContext *action_context)
{
  UFG::SimComponent *v2; // rbx
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::SimComponent *v5; // r8
  __int16 m_Flags; // dx
  UFG::ActiveAIEntityComponent *ComponentOfTypeHK; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pAIEntityComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::SimObjectGame *v12; // rcx
  UFG::SimComponent *m_pComponent; // r8
  __int16 v14; // dx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *p_m_pTargetingSystemBaseComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::SimComponent *v20; // r8
  UFG::SimObjectGame *v21; // rcx
  __int16 v22; // dx
  UFG::SimComponent *v23; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::FormationManagerComponent> *p_m_pTargetFormationManagerComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v25; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v26; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v27; // rax

  v2 = 0i64;
  this->m_pActionContext = action_context;
  if ( action_context )
  {
    m_pPointer = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
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
      v5 = ComponentOfTypeHK;
    }
    else
    {
      v5 = 0i64;
    }
    p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
    if ( this->m_pAIEntityComponent.m_pPointer )
    {
      mPrev = p_m_pAIEntityComponent->mPrev;
      mNext = this->m_pAIEntityComponent.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
      this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
    }
    this->m_pAIEntityComponent.m_pPointer = v5;
    if ( v5 )
    {
      v11 = v5->m_SafePointerList.mNode.mPrev;
      v11->mNext = p_m_pAIEntityComponent;
      p_m_pAIEntityComponent->mPrev = v11;
      this->m_pAIEntityComponent.mNext = &v5->m_SafePointerList.mNode;
      v5->m_SafePointerList.mNode.mPrev = p_m_pAIEntityComponent;
    }
    v12 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
    if ( v12 )
    {
      v14 = v12->m_Flags;
      if ( (v14 & 0x4000) != 0 )
      {
        m_pComponent = v12->m_Components.p[20].m_pComponent;
      }
      else if ( v14 >= 0 )
      {
        if ( (v14 & 0x2000) != 0 || (v14 & 0x1000) != 0 )
          ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::TargetingSystemBaseComponent::_TypeUID);
        else
          ComponentOfType = UFG::SimObject::GetComponentOfType(v12, UFG::TargetingSystemBaseComponent::_TypeUID);
        m_pComponent = ComponentOfType;
      }
      else
      {
        m_pComponent = v12->m_Components.p[20].m_pComponent;
      }
    }
    else
    {
      m_pComponent = 0i64;
    }
    p_m_pTargetingSystemBaseComponent = &this->m_pTargetingSystemBaseComponent;
    if ( this->m_pTargetingSystemBaseComponent.m_pPointer )
    {
      v17 = p_m_pTargetingSystemBaseComponent->mPrev;
      v18 = this->m_pTargetingSystemBaseComponent.mNext;
      v17->mNext = v18;
      v18->mPrev = v17;
      p_m_pTargetingSystemBaseComponent->mPrev = p_m_pTargetingSystemBaseComponent;
      this->m_pTargetingSystemBaseComponent.mNext = &this->m_pTargetingSystemBaseComponent;
    }
    this->m_pTargetingSystemBaseComponent.m_pPointer = m_pComponent;
    if ( m_pComponent )
    {
      v19 = m_pComponent->m_SafePointerList.mNode.mPrev;
      v19->mNext = p_m_pTargetingSystemBaseComponent;
      p_m_pTargetingSystemBaseComponent->mPrev = v19;
      this->m_pTargetingSystemBaseComponent.mNext = &m_pComponent->m_SafePointerList.mNode;
      m_pComponent->m_SafePointerList.mNode.mPrev = p_m_pTargetingSystemBaseComponent;
    }
  }
  v20 = this->m_pTargetingSystemBaseComponent.m_pPointer;
  if ( v20 )
  {
    v21 = *(UFG::SimObjectGame **)(56i64
                                 * *(unsigned __int8 *)(LOBYTE(this->m_Track[1].vfptr)
                                                      + *(_QWORD *)&v20[1].m_Flags
                                                      + 8i64)
                                 + *(_QWORD *)&v20[1].m_TypeUID
                                 + 40);
    if ( v21 )
    {
      v22 = v21->m_Flags;
      if ( (v22 & 0x4000) != 0 || v22 < 0 || (v22 & 0x2000) != 0 || (v22 & 0x1000) != 0 )
        v23 = UFG::SimObjectGame::GetComponentOfTypeHK(v21, UFG::FormationManagerComponent::_TypeUID);
      else
        v23 = UFG::SimObject::GetComponentOfType(v21, UFG::FormationManagerComponent::_TypeUID);
      v2 = v23;
    }
    p_m_pTargetFormationManagerComponent = &this->m_pTargetFormationManagerComponent;
    if ( this->m_pTargetFormationManagerComponent.m_pPointer )
    {
      v25 = p_m_pTargetFormationManagerComponent->mPrev;
      v26 = this->m_pTargetFormationManagerComponent.mNext;
      v25->mNext = v26;
      v26->mPrev = v25;
      p_m_pTargetFormationManagerComponent->mPrev = p_m_pTargetFormationManagerComponent;
      this->m_pTargetFormationManagerComponent.mNext = &this->m_pTargetFormationManagerComponent;
    }
    this->m_pTargetFormationManagerComponent.m_pPointer = v2;
    if ( v2 )
    {
      v27 = v2->m_SafePointerList.mNode.mPrev;
      v27->mNext = p_m_pTargetFormationManagerComponent;
      p_m_pTargetFormationManagerComponent->mPrev = v27;
      this->m_pTargetFormationManagerComponent.mNext = &v2->m_SafePointerList.mNode;
      v2->m_SafePointerList.mNode.mPrev = p_m_pTargetFormationManagerComponent;
    }
  }
}

// File Line: 5521
// RVA: 0x3904C0
char __fastcall InvalidateFormationPositionTask::Update(InvalidateFormationPositionTask *this, float timestep)
{
  if ( this->m_pAIEntityComponent.m_pPointer && this->m_pTargetFormationManagerComponent.m_pPointer )
    UFG::FormationManagerComponent::RequestInvalidatePosition(
      (UFG::FormationManagerComponent *)this->m_pTargetFormationManagerComponent.m_pPointer,
      this->m_pActionContext->mSimObject.m_pPointer);
  return 1;
}

// File Line: 5548
// RVA: 0x3302C0
void __fastcall JustPerformedRunningAttackTask::JustPerformedRunningAttackTask(JustPerformedRunningAttackTask *this)
{
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<JustPerformedRunningAttackTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&JustPerformedRunningAttackTask::`vftable;
}

// File Line: 5560
// RVA: 0x346A20
void __fastcall JustPerformedRunningAttackTask::Begin(
        JustPerformedRunningAttackTask *this,
        ActionContext *action_context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectGame *v7; // r8
  __int16 v8; // cx
  UFG::SimComponent *ComponentOfType; // rax

  m_pPointer = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
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
      v7 = *(UFG::SimObjectGame **)(56i64
                                  * *(unsigned __int8 *)(LOBYTE(this->m_Track[1].vfptr)
                                                       + *(_QWORD *)&m_pComponent[1].m_Flags
                                                       + 8i64)
                                  + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                  + 40);
      if ( v7 )
      {
        v8 = v7->m_Flags;
        if ( (v8 & 0x4000) != 0 )
        {
          ComponentOfType = v7->m_Components.p[46].m_pComponent;
        }
        else if ( v8 < 0 || (v8 & 0x2000) != 0 || (v8 & 0x1000) != 0 )
        {
          ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::AttackRightsComponent::_TypeUID);
        }
        else
        {
          ComponentOfType = UFG::SimObject::GetComponentOfType(v7, UFG::AttackRightsComponent::_TypeUID);
        }
        if ( ComponentOfType )
          *(float *)&ComponentOfType[149].m_NameUID = UFG::Metrics::msInstance.mSimTime_Temp + 3.0;
      }
    }
  }
}

// File Line: 5603
// RVA: 0x3316B0
void __fastcall RequestFormationPositionChangeTask::RequestFormationPositionChangeTask(
        RequestFormationPositionChangeTask *this)
{
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<RequestFormationPositionChangeTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&RequestFormationPositionChangeTask::`vftable;
  this->m_pTransformNodeComponent.mPrev = &this->m_pTransformNodeComponent;
  this->m_pTransformNodeComponent.mNext = &this->m_pTransformNodeComponent;
  this->m_pTransformNodeComponent.m_pPointer = 0i64;
  this->m_pTargetingSystemBaseComponent.mPrev = &this->m_pTargetingSystemBaseComponent;
  this->m_pTargetingSystemBaseComponent.mNext = &this->m_pTargetingSystemBaseComponent;
  this->m_pTargetingSystemBaseComponent.m_pPointer = 0i64;
  this->m_pTargetSimObject.mPrev = &this->m_pTargetSimObject;
  this->m_pTargetSimObject.mNext = &this->m_pTargetSimObject;
  this->m_pTargetSimObject.m_pPointer = 0i64;
  this->m_pTargetTransformNodeComponent.mPrev = &this->m_pTargetTransformNodeComponent;
  this->m_pTargetTransformNodeComponent.mNext = &this->m_pTargetTransformNodeComponent;
  this->m_pTargetTransformNodeComponent.m_pPointer = 0i64;
  this->m_pTargetFormationManagerComponent.mPrev = &this->m_pTargetFormationManagerComponent;
  this->m_pTargetFormationManagerComponent.mNext = &this->m_pTargetFormationManagerComponent;
  this->m_pTargetFormationManagerComponent.m_pPointer = 0i64;
}

// File Line: 5610
// RVA: 0x33A5C0
void __fastcall RequestFormationPositionChangeTask::~RequestFormationPositionChangeTask(
        RequestFormationPositionChangeTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::FormationManagerComponent> *p_m_pTargetFormationManagerComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_m_pTargetTransformNodeComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_pTargetSimObject; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *p_m_pTargetingSystemBaseComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v21; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_m_pTransformNodeComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v23; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v24; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v25; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v26; // rax
  UFG::qNode<ITask,ITask> *v27; // rcx
  UFG::qNode<ITask,ITask> *v28; // rax

  this->vfptr = (ITaskVtbl *)&RequestFormationPositionChangeTask::`vftable;
  p_m_pTargetFormationManagerComponent = &this->m_pTargetFormationManagerComponent;
  if ( this->m_pTargetFormationManagerComponent.m_pPointer )
  {
    mPrev = p_m_pTargetFormationManagerComponent->mPrev;
    mNext = p_m_pTargetFormationManagerComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pTargetFormationManagerComponent->mPrev = p_m_pTargetFormationManagerComponent;
    p_m_pTargetFormationManagerComponent->mNext = p_m_pTargetFormationManagerComponent;
  }
  p_m_pTargetFormationManagerComponent->m_pPointer = 0i64;
  v5 = p_m_pTargetFormationManagerComponent->mPrev;
  v6 = p_m_pTargetFormationManagerComponent->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_m_pTargetFormationManagerComponent->mPrev = p_m_pTargetFormationManagerComponent;
  p_m_pTargetFormationManagerComponent->mNext = p_m_pTargetFormationManagerComponent;
  p_m_pTargetTransformNodeComponent = &this->m_pTargetTransformNodeComponent;
  if ( this->m_pTargetTransformNodeComponent.m_pPointer )
  {
    v8 = p_m_pTargetTransformNodeComponent->mPrev;
    v9 = this->m_pTargetTransformNodeComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    p_m_pTargetTransformNodeComponent->mPrev = p_m_pTargetTransformNodeComponent;
    this->m_pTargetTransformNodeComponent.mNext = &this->m_pTargetTransformNodeComponent;
  }
  this->m_pTargetTransformNodeComponent.m_pPointer = 0i64;
  v10 = p_m_pTargetTransformNodeComponent->mPrev;
  v11 = this->m_pTargetTransformNodeComponent.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  p_m_pTargetTransformNodeComponent->mPrev = p_m_pTargetTransformNodeComponent;
  this->m_pTargetTransformNodeComponent.mNext = &this->m_pTargetTransformNodeComponent;
  p_m_pTargetSimObject = &this->m_pTargetSimObject;
  if ( this->m_pTargetSimObject.m_pPointer )
  {
    v13 = p_m_pTargetSimObject->mPrev;
    v14 = this->m_pTargetSimObject.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    p_m_pTargetSimObject->mPrev = p_m_pTargetSimObject;
    this->m_pTargetSimObject.mNext = &this->m_pTargetSimObject;
  }
  this->m_pTargetSimObject.m_pPointer = 0i64;
  v15 = p_m_pTargetSimObject->mPrev;
  v16 = this->m_pTargetSimObject.mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  p_m_pTargetSimObject->mPrev = p_m_pTargetSimObject;
  this->m_pTargetSimObject.mNext = &this->m_pTargetSimObject;
  p_m_pTargetingSystemBaseComponent = &this->m_pTargetingSystemBaseComponent;
  if ( this->m_pTargetingSystemBaseComponent.m_pPointer )
  {
    v18 = p_m_pTargetingSystemBaseComponent->mPrev;
    v19 = this->m_pTargetingSystemBaseComponent.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    p_m_pTargetingSystemBaseComponent->mPrev = p_m_pTargetingSystemBaseComponent;
    this->m_pTargetingSystemBaseComponent.mNext = &this->m_pTargetingSystemBaseComponent;
  }
  this->m_pTargetingSystemBaseComponent.m_pPointer = 0i64;
  v20 = p_m_pTargetingSystemBaseComponent->mPrev;
  v21 = this->m_pTargetingSystemBaseComponent.mNext;
  v20->mNext = v21;
  v21->mPrev = v20;
  p_m_pTargetingSystemBaseComponent->mPrev = p_m_pTargetingSystemBaseComponent;
  this->m_pTargetingSystemBaseComponent.mNext = &this->m_pTargetingSystemBaseComponent;
  p_m_pTransformNodeComponent = &this->m_pTransformNodeComponent;
  if ( this->m_pTransformNodeComponent.m_pPointer )
  {
    v23 = p_m_pTransformNodeComponent->mPrev;
    v24 = this->m_pTransformNodeComponent.mNext;
    v23->mNext = v24;
    v24->mPrev = v23;
    p_m_pTransformNodeComponent->mPrev = p_m_pTransformNodeComponent;
    this->m_pTransformNodeComponent.mNext = &this->m_pTransformNodeComponent;
  }
  this->m_pTransformNodeComponent.m_pPointer = 0i64;
  v25 = p_m_pTransformNodeComponent->mPrev;
  v26 = this->m_pTransformNodeComponent.mNext;
  v25->mNext = v26;
  v26->mPrev = v25;
  p_m_pTransformNodeComponent->mPrev = p_m_pTransformNodeComponent;
  this->m_pTransformNodeComponent.mNext = &this->m_pTransformNodeComponent;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v27 = this->mPrev;
  v28 = this->mNext;
  v27->mNext = v28;
  v28->mPrev = v27;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 5615
// RVA: 0x347D30
void __fastcall RequestFormationPositionChangeTask::Begin(
        RequestFormationPositionChangeTask *this,
        ActionContext *action_context)
{
  UFG::SimObject *m_pPointer; // r8
  UFG::SimObject *v3; // rbx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_m_pTransformNodeComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::SimObjectGame *v11; // rcx
  UFG::SimComponent *m_pComponent; // r8
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *p_m_pTargetingSystemBaseComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rax
  UFG::SimComponent *v19; // r8
  UFG::SimObject *v20; // r8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_pTargetSimObject; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v22; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v23; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v24; // rax
  UFG::SimObject *v25; // r8
  UFG::SimComponent *v26; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_m_pTargetTransformNodeComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v28; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v29; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v30; // rax
  UFG::SimObjectGame *v31; // rcx
  __int16 v32; // dx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::FormationManagerComponent> *p_m_pTargetFormationManagerComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v35; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v36; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v37; // rax
  unsigned __int8 *m_Track; // rcx
  bool v39; // zf
  int v40; // edx
  UFG::eFormationFacingType v41; // eax
  int v42; // edx
  int v43; // edx
  UFG::SimObjectGame *v44; // rcx
  __int16 v45; // dx
  UFG::AttackRightsComponent *v46; // rax
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *NextAttacker; // rax
  void *(__fastcall *vecDelDtor)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int); // rax
  UFG::SimComponent *v49; // rdi
  UFG::TransformNodeComponent *v50; // rsi
  UFG::TransformNodeComponent *v51; // rbx
  float v52; // xmm6_4
  __m128 mPrev_high; // xmm7
  float v54; // xmm8_4
  __m128 v55; // xmm2
  float v56; // xmm1_4
  UFG::TransformNodeComponent *v57; // rsi
  UFG::TransformNodeComponent *v58; // rdi
  UFG::TransformNodeComponent *v59; // rbx
  UFG::FormationPositionChangeRequest request; // [rsp+20h] [rbp-58h] BYREF

  this->m_pActionContext = action_context;
  m_pPointer = action_context->mSimObject.m_pPointer;
  v3 = 0i64;
  if ( m_pPointer )
    m_pTransformNodeComponent = m_pPointer->m_pTransformNodeComponent;
  else
    m_pTransformNodeComponent = 0i64;
  p_m_pTransformNodeComponent = &this->m_pTransformNodeComponent;
  if ( this->m_pTransformNodeComponent.m_pPointer )
  {
    mPrev = p_m_pTransformNodeComponent->mPrev;
    mNext = p_m_pTransformNodeComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pTransformNodeComponent->mPrev = p_m_pTransformNodeComponent;
    p_m_pTransformNodeComponent->mNext = p_m_pTransformNodeComponent;
  }
  p_m_pTransformNodeComponent->m_pPointer = m_pTransformNodeComponent;
  if ( m_pTransformNodeComponent )
  {
    v10 = m_pTransformNodeComponent->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
    v10->mNext = p_m_pTransformNodeComponent;
    p_m_pTransformNodeComponent->mPrev = v10;
    p_m_pTransformNodeComponent->mNext = &m_pTransformNodeComponent->m_SafePointerList.mNode;
    m_pTransformNodeComponent->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = p_m_pTransformNodeComponent;
  }
  v11 = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  if ( v11 )
  {
    m_Flags = v11->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = v11->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v11, UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = ComponentOfTypeHK;
    }
    else
    {
      m_pComponent = v11->m_Components.p[20].m_pComponent;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  p_m_pTargetingSystemBaseComponent = &this->m_pTargetingSystemBaseComponent;
  if ( this->m_pTargetingSystemBaseComponent.m_pPointer )
  {
    v16 = p_m_pTargetingSystemBaseComponent->mPrev;
    v17 = this->m_pTargetingSystemBaseComponent.mNext;
    v16->mNext = v17;
    v17->mPrev = v16;
    p_m_pTargetingSystemBaseComponent->mPrev = p_m_pTargetingSystemBaseComponent;
    this->m_pTargetingSystemBaseComponent.mNext = &this->m_pTargetingSystemBaseComponent;
  }
  this->m_pTargetingSystemBaseComponent.m_pPointer = m_pComponent;
  if ( m_pComponent )
  {
    v18 = m_pComponent->m_SafePointerList.mNode.mPrev;
    v18->mNext = p_m_pTargetingSystemBaseComponent;
    p_m_pTargetingSystemBaseComponent->mPrev = v18;
    this->m_pTargetingSystemBaseComponent.mNext = &m_pComponent->m_SafePointerList.mNode;
    m_pComponent->m_SafePointerList.mNode.mPrev = p_m_pTargetingSystemBaseComponent;
  }
  v19 = this->m_pTargetingSystemBaseComponent.m_pPointer;
  if ( v19 )
  {
    v20 = *(UFG::SimObject **)(56i64
                             * *(unsigned __int8 *)(LOBYTE(this->m_Track[1].vfptr) + *(_QWORD *)&v19[1].m_Flags + 8i64)
                             + *(_QWORD *)&v19[1].m_TypeUID
                             + 40);
    p_m_pTargetSimObject = &this->m_pTargetSimObject;
    if ( this->m_pTargetSimObject.m_pPointer )
    {
      v22 = p_m_pTargetSimObject->mPrev;
      v23 = this->m_pTargetSimObject.mNext;
      v22->mNext = v23;
      v23->mPrev = v22;
      p_m_pTargetSimObject->mPrev = p_m_pTargetSimObject;
      this->m_pTargetSimObject.mNext = &this->m_pTargetSimObject;
    }
    this->m_pTargetSimObject.m_pPointer = v20;
    if ( v20 )
    {
      v24 = v20->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
      v24->mNext = p_m_pTargetSimObject;
      p_m_pTargetSimObject->mPrev = v24;
      this->m_pTargetSimObject.mNext = &v20->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
      v20->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_m_pTargetSimObject;
    }
    v25 = this->m_pTargetSimObject.m_pPointer;
    if ( v25 )
      v26 = v25->m_pTransformNodeComponent;
    else
      v26 = 0i64;
    p_m_pTargetTransformNodeComponent = &this->m_pTargetTransformNodeComponent;
    if ( this->m_pTargetTransformNodeComponent.m_pPointer )
    {
      v28 = p_m_pTargetTransformNodeComponent->mPrev;
      v29 = this->m_pTargetTransformNodeComponent.mNext;
      v28->mNext = v29;
      v29->mPrev = v28;
      p_m_pTargetTransformNodeComponent->mPrev = p_m_pTargetTransformNodeComponent;
      this->m_pTargetTransformNodeComponent.mNext = &this->m_pTargetTransformNodeComponent;
    }
    this->m_pTargetTransformNodeComponent.m_pPointer = v26;
    if ( v26 )
    {
      v30 = v26->m_SafePointerList.mNode.mPrev;
      v30->mNext = p_m_pTargetTransformNodeComponent;
      p_m_pTargetTransformNodeComponent->mPrev = v30;
      this->m_pTargetTransformNodeComponent.mNext = &v26->m_SafePointerList.mNode;
      v26->m_SafePointerList.mNode.mPrev = p_m_pTargetTransformNodeComponent;
    }
    v31 = (UFG::SimObjectGame *)this->m_pTargetSimObject.m_pPointer;
    if ( v31 )
    {
      v32 = v31->m_Flags;
      if ( (v32 & 0x4000) != 0 || v32 < 0 || (v32 & 0x2000) != 0 || (v32 & 0x1000) != 0 )
        ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v31, UFG::FormationManagerComponent::_TypeUID);
      else
        ComponentOfType = UFG::SimObject::GetComponentOfType(v31, UFG::FormationManagerComponent::_TypeUID);
      v19 = ComponentOfType;
    }
    else
    {
      v19 = 0i64;
    }
    p_m_pTargetFormationManagerComponent = &this->m_pTargetFormationManagerComponent;
    if ( this->m_pTargetFormationManagerComponent.m_pPointer )
    {
      v35 = p_m_pTargetFormationManagerComponent->mPrev;
      v36 = this->m_pTargetFormationManagerComponent.mNext;
      v35->mNext = v36;
      v36->mPrev = v35;
      p_m_pTargetFormationManagerComponent->mPrev = p_m_pTargetFormationManagerComponent;
      this->m_pTargetFormationManagerComponent.mNext = &this->m_pTargetFormationManagerComponent;
    }
    this->m_pTargetFormationManagerComponent.m_pPointer = v19;
    if ( v19 )
    {
      v37 = v19->m_SafePointerList.mNode.mPrev;
      v37->mNext = p_m_pTargetFormationManagerComponent;
      p_m_pTargetFormationManagerComponent->mPrev = v37;
      this->m_pTargetFormationManagerComponent.mNext = &v19->m_SafePointerList.mNode;
      v19->m_SafePointerList.mNode.mPrev = p_m_pTargetFormationManagerComponent;
    }
  }
  if ( this->m_pTargetFormationManagerComponent.m_pPointer && this->m_pTransformNodeComponent.m_pPointer )
  {
    m_Track = (unsigned __int8 *)this->m_Track;
    request.m_Clockwise = 0;
    v39 = m_Track[60] == 0;
    v40 = m_Track[59];
    request.m_DesiredSpeed = m_Track[57];
    v41 = m_Track[58];
    request.m_AbsolutePosition = !v39;
    request.m_FacingType = v41;
    if ( v40 )
    {
      v42 = v40 - 1;
      if ( v42 )
      {
        v43 = v42 - 1;
        if ( v43 )
        {
          if ( v43 == 1 )
          {
            v44 = (UFG::SimObjectGame *)this->m_pTargetSimObject.m_pPointer;
            request.m_Clockwise = 0;
            if ( v44 )
            {
              v45 = v44->m_Flags;
              if ( (v45 & 0x4000) != 0 )
                v46 = (UFG::AttackRightsComponent *)v44->m_Components.p[46].m_pComponent;
              else
                v46 = (UFG::AttackRightsComponent *)(v45 < 0 || (v45 & 0x2000) != 0 || (v45 & 0x1000) != 0
                                                   ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                       v44,
                                                       UFG::AttackRightsComponent::_TypeUID)
                                                   : UFG::SimObject::GetComponentOfType(
                                                       v44,
                                                       UFG::AttackRightsComponent::_TypeUID));
            }
            else
            {
              v46 = 0i64;
            }
            if ( v46 )
            {
              NextAttacker = UFG::AttackRightsComponent::GetNextAttacker(v46, eATTACK_TYPE_MELEE, (__int64)v19);
              if ( NextAttacker )
              {
                vecDelDtor = NextAttacker[27].__vecDelDtor;
                if ( vecDelDtor )
                  v3 = (UFG::SimObject *)*((_QWORD *)vecDelDtor + 5);
              }
              if ( v3 )
              {
                if ( v3 != action_context->mSimObject.m_pPointer )
                {
                  v49 = this->m_pTransformNodeComponent.m_pPointer;
                  v50 = v3->m_pTransformNodeComponent;
                  if ( v49 )
                  {
                    if ( this->m_pTargetTransformNodeComponent.m_pPointer && v50 )
                    {
                      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v49);
                      v51 = (UFG::TransformNodeComponent *)this->m_pTargetTransformNodeComponent.m_pPointer;
                      UFG::TransformNodeComponent::UpdateWorldTransform(v51);
                      UFG::TransformNodeComponent::UpdateWorldTransform(v50);
                      mPrev_high = (__m128)HIDWORD(v49[2].m_BoundComponentHandles.mNode.mPrev);
                      v52 = *(float *)&v49[2].m_BoundComponentHandles.mNode.mPrev - v51->mWorldTransform.v3.x;
                      mPrev_high.m128_f32[0] = mPrev_high.m128_f32[0] - v51->mWorldTransform.v3.y;
                      v54 = *(float *)&v49[2].m_BoundComponentHandles.mNode.mNext - v51->mWorldTransform.v3.z;
                      v55 = mPrev_high;
                      v55.m128_f32[0] = (float)((float)(mPrev_high.m128_f32[0] * mPrev_high.m128_f32[0])
                                              + (float)(v52 * v52))
                                      + (float)(v54 * v54);
                      if ( v55.m128_f32[0] == 0.0 )
                        v56 = 0.0;
                      else
                        v56 = 1.0 / _mm_sqrt_ps(v55).m128_f32[0];
                      request.m_Clockwise = (float)((float)((float)((float)((float)((float)(v54 * v56)
                                                                                  * UFG::qVector3::msDirUp.x)
                                                                          - (float)((float)(v52 * v56)
                                                                                  * UFG::qVector3::msDirUp.z))
                                                                  * (float)(mPrev_high.m128_f32[0] * v56))
                                                          + (float)((float)((float)((float)(mPrev_high.m128_f32[0] * v56)
                                                                                  * UFG::qVector3::msDirUp.z)
                                                                          - (float)((float)(v54 * v56)
                                                                                  * UFG::qVector3::msDirUp.y))
                                                                  * (float)(v52 * v56)))
                                                  + (float)((float)((float)((float)(v52 * v56) * UFG::qVector3::msDirUp.y)
                                                                  - (float)((float)(mPrev_high.m128_f32[0] * v56)
                                                                          * UFG::qVector3::msDirUp.x))
                                                          * (float)(v54 * v56))) < 0.0;
                    }
                  }
                }
              }
            }
          }
        }
        else
        {
          v57 = (UFG::TransformNodeComponent *)this->m_pTargetTransformNodeComponent.m_pPointer;
          UFG::TransformNodeComponent::UpdateWorldTransform(v57);
          v58 = (UFG::TransformNodeComponent *)this->m_pTargetTransformNodeComponent.m_pPointer;
          UFG::TransformNodeComponent::UpdateWorldTransform(v58);
          v59 = (UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pPointer;
          UFG::TransformNodeComponent::UpdateWorldTransform(v59);
          request.m_Clockwise = (float)((float)((float)((float)(v59->mWorldTransform.v3.y - v58->mWorldTransform.v3.y)
                                                      * v57->mWorldTransform.v1.y)
                                              + (float)((float)(v59->mWorldTransform.v3.x - v58->mWorldTransform.v3.x)
                                                      * v57->mWorldTransform.v1.x))
                                      + (float)(v57->mWorldTransform.v1.z * 0.0)) < 0.0;
        }
      }
      else
      {
        request.m_Clockwise = 0;
      }
    }
    else
    {
      request.m_Clockwise = 1;
    }
    UFG::FormationManagerComponent::RequestChangePosition(
      (UFG::FormationManagerComponent *)this->m_pTargetFormationManagerComponent.m_pPointer,
      action_context->mSimObject.m_pPointer,
      &request);
  }
}

// File Line: 5751
// RVA: 0x330390
void __fastcall LeaveGroupTask::LeaveGroupTask(LeaveGroupTask *this)
{
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<LeaveGroupTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&LeaveGroupTask::`vftable;
}

// File Line: 5760
// RVA: 0x346B60
void __fastcall LeaveGroupTask::Begin(LeaveGroupTask *this, ActionContext *action_context)
{
  UFG::GroupComponent::LeaveGroup(action_context->mSimObject.m_pPointer);
}

// File Line: 5776
// RVA: 0x331A90
void __fastcall SelectSuitableVehicleTask::SelectSuitableVehicleTask(SelectSuitableVehicleTask *this)
{
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<SelectSuitableVehicleTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&SelectSuitableVehicleTask::`vftable;
  this->m_pActionContext = 0i64;
  this->m_pVehicle.mPrev = &this->m_pVehicle;
  this->m_pVehicle.mNext = &this->m_pVehicle;
  this->m_pVehicle.m_pPointer = 0i64;
}

// File Line: 5780
// RVA: 0x33AAA0
void __fastcall SelectSuitableVehicleTask::~SelectSuitableVehicleTask(SelectSuitableVehicleTask *this)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_pVehicle; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rcx
  UFG::qNode<ITask,ITask> *v8; // rax

  this->vfptr = (ITaskVtbl *)&SelectSuitableVehicleTask::`vftable;
  p_m_pVehicle = &this->m_pVehicle;
  if ( this->m_pVehicle.m_pPointer )
  {
    mPrev = p_m_pVehicle->mPrev;
    mNext = p_m_pVehicle->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pVehicle->mPrev = p_m_pVehicle;
    p_m_pVehicle->mNext = p_m_pVehicle;
  }
  p_m_pVehicle->m_pPointer = 0i64;
  v5 = p_m_pVehicle->mPrev;
  v6 = p_m_pVehicle->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_m_pVehicle->mPrev = p_m_pVehicle;
  p_m_pVehicle->mNext = p_m_pVehicle;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v7 = this->mPrev;
  v8 = this->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 5789
// RVA: 0x3485D0
void __fastcall SelectSuitableVehicleTask::Begin(SelectSuitableVehicleTask *this, ActionContext *action_context)
{
  UFG::SimObject *m_pPointer; // rax
  ITrack *m_Track; // rdx
  bool v5; // zf
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_pVehicle; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::SimObject *pVehicle; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *p_mNode; // rcx
  UFG::SelectSuitableVehicle::Params params; // [rsp+20h] [rbp-28h] BYREF

  m_pPointer = this->m_pVehicle.m_pPointer;
  this->m_pActionContext = action_context;
  params.pActionContext = action_context;
  m_Track = this->m_Track;
  params.pVehicle = m_pPointer;
  LODWORD(m_pPointer) = m_Track[1].mResourceOwner;
  v5 = BYTE4(m_Track[1].vfptr) == 0;
  params.maxSearchRadius = *(float *)&m_Track[1].vfptr;
  params.filterClassSymbol.mUID = (unsigned int)m_pPointer;
  params.ignoreMeshTest = !v5;
  UFG::SelectSuitableVehicle::SelectVehicle(&params);
  p_m_pVehicle = &this->m_pVehicle;
  if ( p_m_pVehicle->m_pPointer )
  {
    mPrev = p_m_pVehicle->mPrev;
    mNext = p_m_pVehicle->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pVehicle->mPrev = p_m_pVehicle;
    p_m_pVehicle->mNext = p_m_pVehicle;
  }
  pVehicle = params.pVehicle;
  p_m_pVehicle->m_pPointer = params.pVehicle;
  if ( pVehicle )
  {
    v10 = pVehicle->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    p_mNode = &pVehicle->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
    v10->mNext = p_m_pVehicle;
    p_m_pVehicle->mPrev = v10;
    p_m_pVehicle->mNext = p_mNode;
    p_mNode->mPrev = p_m_pVehicle;
  }
}

// File Line: 5810
// RVA: 0x392D50
char __fastcall SelectSuitableVehicleTask::Update(SelectSuitableVehicleTask *this, float timestep)
{
  ITrack *m_Track; // rdx
  bool v4; // zf
  UFG::SimObject *m_pPointer; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_pVehicle; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::SimObject *pVehicle; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *p_mNode; // rcx
  UFG::SelectSuitableVehicle::Params params; // [rsp+20h] [rbp-28h] BYREF

  m_Track = this->m_Track;
  v4 = BYTE4(m_Track[1].vfptr) == 0;
  params.pActionContext = this->m_pActionContext;
  m_pPointer = this->m_pVehicle.m_pPointer;
  params.maxSearchRadius = *(float *)&m_Track[1].vfptr;
  params.pVehicle = m_pPointer;
  params.filterClassSymbol.mUID = (unsigned int)m_Track[1].mResourceOwner;
  params.ignoreMeshTest = !v4;
  UFG::SelectSuitableVehicle::Update(&params);
  p_m_pVehicle = &this->m_pVehicle;
  if ( p_m_pVehicle->m_pPointer )
  {
    mPrev = p_m_pVehicle->mPrev;
    mNext = p_m_pVehicle->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pVehicle->mPrev = p_m_pVehicle;
    p_m_pVehicle->mNext = p_m_pVehicle;
  }
  pVehicle = params.pVehicle;
  p_m_pVehicle->m_pPointer = params.pVehicle;
  if ( pVehicle )
  {
    v10 = pVehicle->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    p_mNode = &pVehicle->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
    v10->mNext = p_m_pVehicle;
    p_m_pVehicle->mPrev = v10;
    p_m_pVehicle->mNext = p_mNode;
    p_mNode->mPrev = p_m_pVehicle;
  }
  return 1;
}

// File Line: 5832
// RVA: 0x355480
void __fastcall SelectSuitableVehicleTask::End(SelectSuitableVehicleTask *this)
{
  ITrack *m_Track; // rdx
  UFG::SimObject *m_pPointer; // rdi
  bool v3; // zf
  float v4; // xmm0_4
  unsigned int mResourceOwner; // eax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_pVehicle; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::SelectSuitableVehicle::Params params; // [rsp+20h] [rbp-28h] BYREF

  m_Track = this->m_Track;
  m_pPointer = this->m_pVehicle.m_pPointer;
  v3 = BYTE4(m_Track[1].vfptr) == 0;
  v4 = *(float *)&m_Track[1].vfptr;
  params.pActionContext = this->m_pActionContext;
  params.maxSearchRadius = v4;
  mResourceOwner = (unsigned int)m_Track[1].mResourceOwner;
  params.ignoreMeshTest = !v3;
  params.pVehicle = m_pPointer;
  params.filterClassSymbol.mUID = mResourceOwner;
  UFG::SelectSuitableVehicle::Cleanup(&params);
  p_m_pVehicle = &this->m_pVehicle;
  if ( p_m_pVehicle->m_pPointer )
  {
    mPrev = p_m_pVehicle->mPrev;
    mNext = p_m_pVehicle->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pVehicle->mPrev = p_m_pVehicle;
    p_m_pVehicle->mNext = p_m_pVehicle;
  }
  p_m_pVehicle->m_pPointer = m_pPointer;
  if ( m_pPointer )
  {
    v10 = m_pPointer->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    v10->mNext = p_m_pVehicle;
    p_m_pVehicle->mPrev = v10;
    p_m_pVehicle->mNext = &m_pPointer->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
    m_pPointer->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_m_pVehicle;
  }
}

// File Line: 5855
// RVA: 0x32E2E0
void __fastcall FireWeaponTask::FireWeaponTask(FireWeaponTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pAIEntityComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax

  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<FireWeaponTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&FireWeaponTask::`vftable;
  p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.mPrev = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
  this->m_pAIEntityComponent.m_pPointer = 0i64;
  this->m_pActionContext = 0i64;
  if ( this->m_pAIEntityComponent.m_pPointer )
  {
    mPrev = p_m_pAIEntityComponent->mPrev;
    mNext = p_m_pAIEntityComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
    p_m_pAIEntityComponent->mNext = p_m_pAIEntityComponent;
  }
  p_m_pAIEntityComponent->m_pPointer = 0i64;
}

// File Line: 5863
// RVA: 0x3368B0
void __fastcall FireWeaponTask::~FireWeaponTask(FireWeaponTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pAIEntityComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rcx
  UFG::qNode<ITask,ITask> *v8; // rax

  this->vfptr = (ITaskVtbl *)&FireWeaponTask::`vftable;
  p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
  if ( this->m_pAIEntityComponent.m_pPointer )
  {
    mPrev = p_m_pAIEntityComponent->mPrev;
    mNext = p_m_pAIEntityComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
    p_m_pAIEntityComponent->mNext = p_m_pAIEntityComponent;
  }
  p_m_pAIEntityComponent->m_pPointer = 0i64;
  v5 = p_m_pAIEntityComponent->mPrev;
  v6 = p_m_pAIEntityComponent->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
  p_m_pAIEntityComponent->mNext = p_m_pAIEntityComponent;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v7 = this->mPrev;
  v8 = this->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 5868
// RVA: 0x3449F0
void __fastcall FireWeaponTask::Begin(FireWeaponTask *this, ActionContext *action_context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::SimComponent *v4; // r8
  __int16 m_Flags; // dx
  UFG::ActiveAIEntityComponent *ComponentOfTypeHK; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *p_m_pAIEntityComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  ITrack *m_Track; // rcx
  int v12; // esi
  int v13; // edi
  float v14; // xmm7_4
  float v15; // xmm6_4
  ITrack *v16; // rcx
  float v17; // xmm0_4
  ExpressionParameterFloat *p_m_TrackClassNameUID; // rcx
  float v19; // xmm0_4
  ITrack *v20; // rcx
  float v21; // xmm0_4
  ExpressionParameterFloat *p_mResourceOwner; // rcx

  this->m_pActionContext = action_context;
  if ( action_context )
  {
    m_pPointer = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
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
      v4 = ComponentOfTypeHK;
    }
    else
    {
      v4 = 0i64;
    }
    p_m_pAIEntityComponent = &this->m_pAIEntityComponent;
    if ( this->m_pAIEntityComponent.m_pPointer )
    {
      mPrev = p_m_pAIEntityComponent->mPrev;
      mNext = this->m_pAIEntityComponent.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_m_pAIEntityComponent->mPrev = p_m_pAIEntityComponent;
      this->m_pAIEntityComponent.mNext = &this->m_pAIEntityComponent;
    }
    this->m_pAIEntityComponent.m_pPointer = v4;
    if ( v4 )
    {
      v10 = v4->m_SafePointerList.mNode.mPrev;
      v10->mNext = p_m_pAIEntityComponent;
      p_m_pAIEntityComponent->mPrev = v10;
      this->m_pAIEntityComponent.mNext = &v4->m_SafePointerList.mNode;
      v4->m_SafePointerList.mNode.mPrev = p_m_pAIEntityComponent;
    }
  }
  m_Track = this->m_Track;
  this->m_NumShotsFired = 0;
  this->m_TimeOfNextShot = -99999.0;
  this->m_TimeToLetGoOfTrigger = -1.0;
  v12 = ExpressionParameterInt::operator long((ExpressionParameterInt *)&m_Track[1]);
  v13 = ExpressionParameterInt::operator long((ExpressionParameterInt *)&this->m_Track[1].mMasterRate);
  v14 = ExpressionParameterFloat::operator float((ExpressionParameterFloat *)&this->m_Track[3].mMasterRate.expression);
  v15 = ExpressionParameterFloat::operator float((ExpressionParameterFloat *)&this->m_Track[4]);
  if ( v13 > v12 )
    v13 = v12 + UFG::qRandom(v13 - v12 + 1, (unsigned int *)&UFG::qDefaultSeed);
  v16 = this->m_Track;
  this->m_NumShotsToFire = v13;
  v17 = ExpressionParameterFloat::operator float((ExpressionParameterFloat *)&v16[1].mTimeBegin);
  p_m_TrackClassNameUID = (ExpressionParameterFloat *)&this->m_Track[2].m_TrackClassNameUID;
  this->m_MinTimeBetweenShots = v17 * v14;
  v19 = ExpressionParameterFloat::operator float(p_m_TrackClassNameUID);
  v20 = this->m_Track;
  this->m_MaxTimeBetweenShots = v19 * v14;
  if ( BYTE4(v20[4].mMasterRate.text.mOffset) )
  {
    v21 = ExpressionParameterFloat::operator float((ExpressionParameterFloat *)&v20[2].mMasterRate.value);
    p_mResourceOwner = (ExpressionParameterFloat *)&this->m_Track[3].mResourceOwner;
    this->m_MinTimeToHoldTrigger = v21 * v15;
    this->m_MaxTimeToHoldTrigger = ExpressionParameterFloat::operator float(p_mResourceOwner) * v15;
  }
  else
  {
    *(_QWORD *)&this->m_MinTimeToHoldTrigger = 0i64;
  }
}

// File Line: 5906
// RVA: 0x38EA40
bool __fastcall FireWeaponTask::Update(FireWeaponTask *this, float timestep)
{
  float m_TimeToLetGoOfTrigger; // xmm0_4
  float mSimTime_Temp; // xmm6_4
  float RandomNumberInRange; // xmm0_4
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::AICharacterControllerBaseComponent *v7; // rcx
  __int16 m_Flags; // dx
  UFG::AICharacterControllerBaseComponent *ComponentOfType; // rax
  unsigned int v10; // edx
  bool v11; // zf

  if ( !this->m_pAIEntityComponent.m_pPointer )
  {
    this->m_NumShotsToFire = -2;
    return this->m_NumShotsFired < this->m_NumShotsToFire;
  }
  m_TimeToLetGoOfTrigger = this->m_TimeToLetGoOfTrigger;
  mSimTime_Temp = UFG::Metrics::msInstance.mSimTime_Temp;
  if ( m_TimeToLetGoOfTrigger > 0.0 )
  {
    if ( UFG::Metrics::msInstance.mSimTime_Temp < m_TimeToLetGoOfTrigger )
      goto LABEL_6;
    this->m_TimeToLetGoOfTrigger = -1.0;
    goto LABEL_5;
  }
  if ( UFG::Metrics::msInstance.mSimTime_Temp >= this->m_TimeOfNextShot
    && this->m_NumShotsFired < this->m_NumShotsToFire )
  {
    if ( BYTE4(this->m_Track[4].mMasterRate.text.mOffset) )
    {
      this->m_TimeToLetGoOfTrigger = UFG::GetRandomNumberInRange(
                                       this->m_MinTimeToHoldTrigger,
                                       this->m_MaxTimeToHoldTrigger)
                                   + mSimTime_Temp;
LABEL_6:
      m_pPointer = (UFG::SimObjectCVBase *)this->m_pActionContext->mSimObject.m_pPointer;
      if ( !m_pPointer )
      {
        v7 = 0i64;
LABEL_21:
        Intention::Set(&v7->m_Intention, this->m_Track[4].mMasterRate.text.mOffset, 0.0);
        return this->m_NumShotsFired < this->m_NumShotsToFire;
      }
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
      {
        ComponentOfType = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(m_pPointer);
      }
      else
      {
        if ( (m_Flags & 0x2000) != 0 )
        {
          v10 = UFG::AICharacterControllerBaseComponent::_TypeUID;
        }
        else
        {
          v11 = (m_Flags & 0x1000) == 0;
          v10 = UFG::AICharacterControllerBaseComponent::_TypeUID;
          if ( v11 )
          {
            ComponentOfType = (UFG::AICharacterControllerBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                                           m_pPointer,
                                                                           UFG::AICharacterControllerBaseComponent::_TypeUID);
            goto LABEL_20;
          }
        }
        ComponentOfType = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                       m_pPointer,
                                                                       v10);
      }
LABEL_20:
      v7 = ComponentOfType;
      goto LABEL_21;
    }
LABEL_5:
    RandomNumberInRange = UFG::GetRandomNumberInRange(this->m_MinTimeBetweenShots, this->m_MaxTimeBetweenShots);
    ++this->m_NumShotsFired;
    this->m_TimeOfNextShot = RandomNumberInRange + mSimTime_Temp;
    goto LABEL_6;
  }
  return this->m_NumShotsFired < this->m_NumShotsToFire;
}

// File Line: 5979
// RVA: 0x32B2A0
void __fastcall AICoverSearchTask::AICoverSearchTask(AICoverSearchTask *this)
{
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<AICoverSearchTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&AICoverSearchTask::`vftable;
}

// File Line: 5991
// RVA: 0x342F60
void __fastcall AICoverSearchTask::Begin(AICoverSearchTask *this, ActionContext *action_context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 v4; // dx
  UFG::SimComponent *v5; // rax
  UFG::AICoverComponent *v6; // r15
  __int64 vfptr_low; // rbx
  UFG::SimObjectGame *v8; // rcx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rsi
  UFG::SimComponent *m_pComponent; // r8
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectGame *v13; // rdi
  UFG::allocator::free_link *v14; // rax
  UFG::allocator::free_link *v15; // rbx
  UFG::SimObject *v16; // rdx
  UFG::allocator::free_link *mNext; // rcx
  UFG::allocator::free_link *v18; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rax
  __int16 v20; // cx
  UFG::AICoverComponent *ComponentOfType; // rax
  UFG::AICoverComponent *v22; // r14
  float z; // xmm9_4
  float y; // xmm10_4
  float x; // xmm11_4
  UFG::SimObject *v26; // rax
  float v27; // xmm6_4
  float v28; // xmm7_4
  float v29; // xmm8_4
  __int16 v30; // cx
  UFG::AimingBaseComponent *v31; // rax
  __int64 mNext_low; // r13
  unsigned int v33; // esi
  unsigned int mNext_high; // edx
  unsigned int v35; // edx
  __int64 v36; // rcx
  UFG::allocator::free_link *v37; // rax
  float v38; // xmm1_4
  float v39; // xmm2_4
  UFG::qSymbolUC *v41; // rax
  char *v42; // rax
  UFG::qVector3 vAimDirection; // [rsp+28h] [rbp-B0h] BYREF
  UFG::qVector3 raycastPosition; // [rsp+38h] [rbp-A0h] BYREF
  UFG::allocator::free_link *result; // [rsp+E0h] [rbp+8h] BYREF
  UFG::allocator::free_link *v46; // [rsp+E8h] [rbp+10h]

  this->m_pActionContext = action_context;
  m_pPointer = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  if ( m_pPointer
    && ((v4 = m_pPointer->m_Flags, (v4 & 0x4000) == 0) && v4 >= 0 && (v4 & 0x2000) == 0 && (v4 & 0x1000) == 0
      ? (v5 = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::AICoverComponent::_TypeUID))
      : (v5 = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::AICoverComponent::_TypeUID)),
        (v6 = (UFG::AICoverComponent *)v5) != 0i64) )
  {
    vfptr_low = LOBYTE(this->m_Track[1].vfptr);
    v8 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
    m_pTransformNodeComponent = 0i64;
    if ( v8 )
    {
      m_Flags = v8->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = v8->m_Components.p[20].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::TargetingSystemBaseComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v8, UFG::TargetingSystemBaseComponent::_TypeUID);
        m_pComponent = ComponentOfTypeHK;
      }
      else
      {
        m_pComponent = v8->m_Components.p[20].m_pComponent;
      }
    }
    else
    {
      m_pComponent = 0i64;
    }
    v13 = *(UFG::SimObjectGame **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + vfptr_low + 8)
                                 + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                 + 40);
    if ( v13 )
    {
      v14 = UFG::qMalloc(0x78ui64, "AICoverSearchTask", 0i64);
      v15 = v14;
      result = v14;
      if ( v14 )
      {
        v46 = v14;
        v14->mNext = v14;
        v14[1].mNext = v14;
        v14[2].mNext = 0i64;
        v14[13].mNext = 0i64;
        v14[12].mNext = 0i64;
        LODWORD(v14[14].mNext) = 0;
      }
      else
      {
        v15 = 0i64;
      }
      ++LODWORD(v15[14].mNext);
      v16 = this->m_pActionContext->mSimObject.m_pPointer;
      if ( v15[2].mNext )
      {
        mNext = v15->mNext;
        v18 = v15[1].mNext;
        mNext[1].mNext = v18;
        v18->mNext = mNext;
        v15->mNext = v15;
        v15[1].mNext = v15;
      }
      v15[2].mNext = (UFG::allocator::free_link *)v16;
      if ( v16 )
      {
        mPrev = v16->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
        mPrev->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)v15;
        v15->mNext = (UFG::allocator::free_link *)mPrev;
        v15[1].mNext = (UFG::allocator::free_link *)&v16->m_SafePointerList;
        v16->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)v15;
      }
      UFG::ComputeObjectRaycastPosition(v13, &raycastPosition);
      v20 = v13->m_Flags;
      if ( (v20 & 0x4000) != 0 || v20 < 0 || (v20 & 0x2000) != 0 || (v20 & 0x1000) != 0 )
        ComponentOfType = (UFG::AICoverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                     v13,
                                                     UFG::AICoverComponent::_TypeUID);
      else
        ComponentOfType = (UFG::AICoverComponent *)UFG::SimObject::GetComponentOfType(
                                                     v13,
                                                     UFG::AICoverComponent::_TypeUID);
      v22 = ComponentOfType;
      z = raycastPosition.z;
      y = raycastPosition.y;
      x = raycastPosition.x;
      if ( ComponentOfType && UFG::AICoverComponent::IsInCover(ComponentOfType) )
      {
        v26 = v22->m_pSimTargetPopout.m_pPointer;
        if ( v26 )
          m_pTransformNodeComponent = v26->m_pTransformNodeComponent;
        UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
        v27 = m_pTransformNodeComponent->mWorldTransform.v3.x;
        v28 = m_pTransformNodeComponent->mWorldTransform.v3.y;
        v29 = m_pTransformNodeComponent->mWorldTransform.v3.z;
      }
      else
      {
        v27 = x;
        v28 = y;
        v29 = z;
      }
      v30 = v13->m_Flags;
      if ( (v30 & 0x4000) != 0 )
      {
        v31 = (UFG::AimingBaseComponent *)v13->m_Components.p[47].m_pComponent;
      }
      else if ( v30 < 0 || (v30 & 0x2000) != 0 || (v30 & 0x1000) != 0 )
      {
        v31 = (UFG::AimingBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                            v13,
                                            UFG::AimingBaseComponent::_TypeUID);
      }
      else
      {
        v31 = (UFG::AimingBaseComponent *)UFG::SimObject::GetComponentOfType(v13, UFG::AimingBaseComponent::_TypeUID);
      }
      if ( v31 )
      {
        UFG::AimingBaseComponent::GetAimDirection(v31, &vAimDirection, 0i64);
      }
      else
      {
        *(_QWORD *)&vAimDirection.x = 0i64;
        vAimDirection.z = 0.0;
      }
      mNext_low = LODWORD(v15[12].mNext);
      v33 = mNext_low + 1;
      mNext_high = HIDWORD(v15[12].mNext);
      if ( (int)mNext_low + 1 > mNext_high )
      {
        if ( mNext_high )
          v35 = 2 * mNext_high;
        else
          v35 = 1;
        for ( ; v35 < v33; v35 *= 2 )
          ;
        if ( v35 - v33 > 0x10000 )
          v35 = mNext_low + 65537;
        UFG::qArray<UFG::AICoverSearchParams::HostileTarget,0>::Reallocate(
          (UFG::qArray<UFG::AICoverSearchParams::HostileTarget,0> *)&v15[12],
          v35,
          "qArray.Add");
      }
      LODWORD(v15[12].mNext) = v33;
      v36 = 9 * mNext_low;
      v37 = v15[13].mNext;
      *((float *)&v37->mNext + v36) = v27;
      *((float *)&v37->mNext + v36 + 1) = v28;
      *((float *)&v37[1].mNext + v36) = v29;
      *((float *)&v37[1].mNext + v36 + 1) = x;
      *((float *)&v37[2].mNext + v36) = y;
      *((float *)&v37[2].mNext + v36 + 1) = z;
      v38 = vAimDirection.y;
      v39 = vAimDirection.z;
      *((_DWORD *)&v37[3].mNext + v36) = LODWORD(vAimDirection.x);
      *((float *)&v37[3].mNext + v36 + 1) = v38;
      *((float *)&v37[4].mNext + v36) = v39;
      AICoverSearchTask::AddExtraHostiles(this, (UFG::AICoverSearchParams *)v15, v13);
      LODWORD(v15[3].mNext) = HIDWORD(this->m_Track[1].vfptr);
      HIDWORD(v15[3].mNext) = HIDWORD(this->m_Track[1].vfptr);
      LODWORD(v15[4].mNext) = this->m_Track[1].mResourceOwner;
      HIDWORD(v15[4].mNext) = HIDWORD(this->m_Track[1].mResourceOwner);
      LODWORD(v15[5].mNext) = this->m_Track[1].m_TrackClassNameUID;
      HIDWORD(v15[5].mNext) = *(_DWORD *)&this->m_Track[1].mBreakPoint;
      LODWORD(v15[6].mNext) = this->m_Track[1].mMasterRate.text.mOffset;
      HIDWORD(v15[6].mNext) = HIDWORD(this->m_Track[1].mMasterRate.text.mOffset);
      LODWORD(v15[7].mNext) = this->m_Track[1].mMasterRate.expression.mOffset;
      HIDWORD(v15[7].mNext) = HIDWORD(this->m_Track[1].mMasterRate.expression.mOffset);
      *(float *)&v15[8].mNext = this->m_Track[1].mMasterRate.value;
      HIDWORD(v15[8].mNext) = *((_DWORD *)&this->m_Track[1].mMasterRate.value + 1);
      LOBYTE(v15[9].mNext) = LOBYTE(this->m_Track[1].mTimeBegin) != 0;
      HIDWORD(v15[9].mNext) = LODWORD(this->m_Track[1].mTimeEnd);
      LOBYTE(v15[10].mNext) = LOBYTE(this->m_Track[2].vfptr) != 0;
      BYTE1(v15[10].mNext) = BYTE1(this->m_Track[2].vfptr) != 0;
      BYTE2(v15[10].mNext) = BYTE2(this->m_Track[2].vfptr) != 0;
      BYTE3(v15[10].mNext) = BYTE3(this->m_Track[2].vfptr) != 0;
      HIDWORD(v15[10].mNext) = HIDWORD(this->m_Track[2].vfptr);
      LODWORD(v15[11].mNext) = this->m_Track[2].mResourceOwner;
      this->m_bSearchStarted = UFG::AICoverComponent::StartCoverSearch(v6, (UFG::AICoverSearchParams *)v15, 1);
      if ( LODWORD(v15[14].mNext)-- == 1 )
      {
        UFG::AICoverSearchParams::~AICoverSearchParams((UFG::AICoverSearchParams *)v15);
        operator delete[](v15);
      }
    }
    else
    {
      this->m_bSearchStarted = 0;
    }
  }
  else
  {
    this->m_bSearchStarted = 0;
    v41 = (UFG::qSymbolUC *)UFG::qSymbol::qSymbol(
                              (UFG::qWiseSymbol *)&result,
                              this->m_pActionContext->mSimObject.m_pPointer->m_pSceneObj->m_NameUID);
    v42 = UFG::qSymbol::as_cstr_dbg(v41);
    UFG::qPrintf(
      "AICoverSearchTask::Begin() - AICoverComponent not found.  This track should not run on a character without an AI C"
      "over Component. PropertySet: %s\n",
      v42);
  }
}

// File Line: 6097
// RVA: 0x38B5E0
bool __fastcall AICoverSearchTask::Update(AICoverSearchTask *this, float timestep)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  unsigned int v5; // edx
  bool v6; // zf

  if ( !this->m_bSearchStarted )
    return 0;
  m_pPointer = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return MEMORY[0x50] != 0i64;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 )
  {
    v5 = UFG::AICoverComponent::_TypeUID;
    return UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, v5)[1].m_SafePointerList.mNode.mNext != 0i64;
  }
  v6 = (m_Flags & 0x1000) == 0;
  v5 = UFG::AICoverComponent::_TypeUID;
  if ( !v6 )
    return UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, v5)[1].m_SafePointerList.mNode.mNext != 0i64;
  return UFG::SimObject::GetComponentOfType(m_pPointer, UFG::AICoverComponent::_TypeUID)[1].m_SafePointerList.mNode.mNext != 0i64;
}

// File Line: 6122
// RVA: 0x354CF0
void __fastcall AICoverSearchTask::End(AICoverSearchTask *this)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::AICoverComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = (UFG::AICoverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                     m_pPointer,
                                                     UFG::AICoverComponent::_TypeUID);
    else
      ComponentOfTypeHK = (UFG::AICoverComponent *)UFG::SimObject::GetComponentOfType(
                                                     m_pPointer,
                                                     UFG::AICoverComponent::_TypeUID);
    if ( ComponentOfTypeHK )
    {
      if ( ComponentOfTypeHK->m_pQuery )
        UFG::AICoverComponent::CancelQuery(ComponentOfTypeHK);
    }
  }
}

// File Line: 6145
// RVA: 0x340280
void __fastcall AICoverSearchTask::AddExtraHostiles(
        AICoverSearchTask *this,
        UFG::AICoverSearchParams *pSearchParams,
        UFG::SimObject *pIgnoreObject)
{
  UFG::SimObject *v3; // rdi
  UFG::AICoverSearchParams *v4; // rsi
  UFG::SimObject *m_pPointer; // rcx
  UFG::ActiveAIEntityComponent *v7; // r12
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rcx
  UFG::SimObjectCVBase *v9; // rcx
  __int16 m_Flags; // dx
  UFG::ActiveAIEntityComponent *ComponentOfTypeHK; // rax
  UFG::NearbyCharacterManager *v12; // r8
  __int64 **v13; // rax
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterMasterList> *mNext; // rcx
  __int64 *v15; // rdx
  __int64 i; // r14
  _QWORD *v17; // rbx
  UFG::SimObjectGame *v18; // rbx
  __int16 v19; // cx
  UFG::SimComponent *m_pComponent; // rax
  __int16 v21; // cx
  UFG::AttackRightsComponent *v22; // rax
  __int16 v23; // cx
  UFG::TargetingSystemBaseComponent *v24; // rax
  __int16 v25; // cx
  UFG::AimingBaseComponent *v26; // rdi
  UFG::SimComponent *ComponentOfType; // rax
  UFG::qArray<UFG::AICoverSearchParams::HostileTarget,0> *p_m_aHostileTargets; // rdi
  __int64 size; // rsi
  unsigned int v30; // ebx
  unsigned int capacity; // edx
  unsigned int v32; // edx
  __int64 v33; // rcx
  UFG::AICoverSearchParams::HostileTarget *p; // rax
  float x; // xmm2_4
  float y; // xmm1_4
  float z; // xmm0_4
  float v38; // xmm1_4
  float v39; // xmm2_4
  __int64 **j; // rax
  _QWORD *v41; // rdx
  __int64 *v42; // rcx
  __int64 *v43; // rax
  __int64 *v44; // rcx
  __int64 **v45; // rax
  UFG::qVector3 vAimDirection; // [rsp+28h] [rbp-38h] BYREF
  UFG::qVector3 raycastPosition; // [rsp+38h] [rbp-28h] BYREF
  __int64 *v48; // [rsp+48h] [rbp-18h] BYREF
  __int64 **v49; // [rsp+50h] [rbp-10h]

  v3 = pIgnoreObject;
  v4 = pSearchParams;
  m_pPointer = this->m_pActionContext->mSimObject.m_pPointer;
  v7 = 0i64;
  if ( m_pPointer )
    m_pTransformNodeComponent = m_pPointer->m_pTransformNodeComponent;
  else
    m_pTransformNodeComponent = 0i64;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  v9 = (UFG::SimObjectCVBase *)this->m_pActionContext->mSimObject.m_pPointer;
  if ( v9 )
  {
    m_Flags = v9->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v9);
    }
    else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            v9,
                                                            UFG::ActiveAIEntityComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                            v9,
                                                            UFG::ActiveAIEntityComponent::_TypeUID);
    }
    v7 = ComponentOfTypeHK;
  }
  v48 = (__int64 *)&v48;
  v49 = &v48;
  v12 = UFG::NearbyCharacterManager::s_pInstance;
  v13 = &v48;
  mNext = UFG::NearbyCharacterManager::s_pInstance->m_Characters[0].mNode.mNext;
  if ( mNext != (UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterMasterList> *)UFG::NearbyCharacterManager::s_pInstance )
  {
    v15 = v48;
    do
    {
      v15[1] = (__int64)&mNext[1];
      mNext[1].mPrev = (UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterMasterList> *)v15;
      mNext[1].mNext = (UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterMasterList> *)&v48;
      v15 = (__int64 *)&mNext[1];
      v48 = (__int64 *)&mNext[1];
      mNext = mNext->mNext;
    }
    while ( mNext != (UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterMasterList> *)v12 );
    v13 = v49;
  }
  for ( i = (__int64)(v13 - 2); (UFG::qVector3 *)i != &raycastPosition; i = *(_QWORD *)(i + 24) - 16i64 )
  {
    v17 = *(_QWORD **)(i + 48);
    if ( v17 )
    {
      if ( (*(unsigned __int8 (__fastcall **)(_QWORD))(*v17 + 112i64))(*(_QWORD *)(i + 48)) )
      {
        v18 = (UFG::SimObjectGame *)v17[5];
        if ( v18 != v3 && v18 != this->m_pActionContext->mSimObject.m_pPointer && v18 )
        {
          v19 = v18->m_Flags;
          if ( (v19 & 0x4000) != 0 )
          {
            m_pComponent = v18->m_Components.p[6].m_pComponent;
          }
          else if ( v19 >= 0 )
          {
            m_pComponent = (v19 & 0x2000) != 0 || (v19 & 0x1000) != 0
                         ? UFG::SimObjectGame::GetComponentOfTypeHK(v18, UFG::HealthComponent::_TypeUID)
                         : UFG::SimObject::GetComponentOfType(v18, UFG::HealthComponent::_TypeUID);
          }
          else
          {
            m_pComponent = v18->m_Components.p[6].m_pComponent;
          }
          if ( m_pComponent && !BYTE4(m_pComponent[1].m_BoundComponentHandles.mNode.mPrev) )
          {
            v21 = v18->m_Flags;
            if ( (v21 & 0x4000) != 0 )
              v22 = (UFG::AttackRightsComponent *)v18->m_Components.p[46].m_pComponent;
            else
              v22 = (UFG::AttackRightsComponent *)(v21 < 0 || (v21 & 0x2000) != 0 || (v21 & 0x1000) != 0
                                                 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                     v18,
                                                     UFG::AttackRightsComponent::_TypeUID)
                                                 : UFG::SimObject::GetComponentOfType(
                                                     v18,
                                                     UFG::AttackRightsComponent::_TypeUID));
            if ( v22 && UFG::ActiveAIEntityComponent::IsEnemyOfMine(v7, v22) )
            {
              v23 = v18->m_Flags;
              if ( (v23 & 0x4000) != 0 )
              {
                v24 = (UFG::TargetingSystemBaseComponent *)v18->m_Components.p[20].m_pComponent;
              }
              else if ( v23 >= 0 )
              {
                v24 = (UFG::TargetingSystemBaseComponent *)((v23 & 0x2000) != 0 || (v23 & 0x1000) != 0
                                                          ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                              v18,
                                                              UFG::TargetingSystemBaseComponent::_TypeUID)
                                                          : UFG::SimObject::GetComponentOfType(
                                                              v18,
                                                              UFG::TargetingSystemBaseComponent::_TypeUID));
              }
              else
              {
                v24 = (UFG::TargetingSystemBaseComponent *)v18->m_Components.p[20].m_pComponent;
              }
              if ( UFG::HasRangedWeaponEquippedWithAmmo(v24) )
              {
                v25 = v18->m_Flags;
                if ( (v25 & 0x4000) != 0 )
                {
                  v26 = (UFG::AimingBaseComponent *)v18->m_Components.p[47].m_pComponent;
                }
                else
                {
                  if ( v25 < 0 || (v25 & 0x2000) != 0 || (v25 & 0x1000) != 0 )
                    ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v18, UFG::AimingBaseComponent::_TypeUID);
                  else
                    ComponentOfType = UFG::SimObject::GetComponentOfType(v18, UFG::AimingBaseComponent::_TypeUID);
                  v26 = (UFG::AimingBaseComponent *)ComponentOfType;
                }
                UFG::ComputeObjectRaycastPosition(v18, &raycastPosition);
                if ( v26 )
                {
                  UFG::AimingBaseComponent::GetAimDirection(v26, &vAimDirection, 0i64);
                }
                else
                {
                  *(_QWORD *)&vAimDirection.x = 0i64;
                  vAimDirection.z = 0.0;
                }
                p_m_aHostileTargets = &v4->m_aHostileTargets;
                size = v4->m_aHostileTargets.size;
                v30 = size + 1;
                capacity = p_m_aHostileTargets->capacity;
                if ( (int)size + 1 > capacity )
                {
                  if ( capacity )
                    v32 = 2 * capacity;
                  else
                    v32 = 1;
                  for ( ; v32 < v30; v32 *= 2 )
                    ;
                  if ( v32 - v30 > 0x10000 )
                    v32 = size + 65537;
                  UFG::qArray<UFG::AICoverSearchParams::HostileTarget,0>::Reallocate(
                    p_m_aHostileTargets,
                    v32,
                    "qArray.Add");
                }
                p_m_aHostileTargets->size = v30;
                v33 = size;
                p = p_m_aHostileTargets->p;
                x = raycastPosition.x;
                p[v33].m_vPosition.x = raycastPosition.x;
                y = raycastPosition.y;
                p[v33].m_vPosition.y = raycastPosition.y;
                z = raycastPosition.z;
                p[v33].m_vPosition.z = raycastPosition.z;
                p[v33].m_vDirectTarget.x = x;
                p[v33].m_vDirectTarget.y = y;
                p[v33].m_vDirectTarget.z = z;
                v38 = vAimDirection.y;
                v39 = vAimDirection.z;
                p[v33].m_vAimingDirection.x = vAimDirection.x;
                p[v33].m_vAimingDirection.y = v38;
                p[v33].m_vAimingDirection.z = v39;
                v3 = pIgnoreObject;
                v4 = pSearchParams;
              }
            }
          }
        }
      }
    }
  }
  for ( j = v49 - 2; v49 - 2 != (__int64 **)&raycastPosition; j = v49 - 2 )
  {
    v41 = j + 2;
    v42 = j[2];
    v43 = j[3];
    v42[1] = (__int64)v43;
    *v43 = (__int64)v42;
    *v41 = v41;
    v41[1] = v41;
  }
  v44 = v48;
  v45 = v49;
  v48[1] = (__int64)v49;
  *v45 = v44;
}

// File Line: 6213
// RVA: 0x32AFB0
void __fastcall AICoverFaceCoverObjectTask::AICoverFaceCoverObjectTask(AICoverFaceCoverObjectTask *this)
{
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<AICoverFaceCoverObjectTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&AICoverFaceCoverObjectTask::`vftable;
}

// File Line: 6234
// RVA: 0x38B490
bool __fastcall AICoverFaceCoverObjectTask::Update(AICoverFaceCoverObjectTask *this, float timestep)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  __int64 v6; // rbx
  UFG::SimObjectCVBase *v7; // rcx
  __int16 v8; // dx
  unsigned int v10; // edx
  bool v11; // zf
  char v12[12]; // [rsp+20h] [rbp-28h] BYREF
  char v13[28]; // [rsp+2Ch] [rbp-1Ch] BYREF

  m_pPointer = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::AICoverComponent::_TypeUID);
    else
      ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::AICoverComponent::_TypeUID);
    if ( ComponentOfTypeHK )
    {
      v6 = *(_QWORD *)&ComponentOfTypeHK[1].m_TypeUID;
      if ( v6 )
      {
        if ( (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v6 + 16i64))(v6) )
        {
          (*(void (__fastcall **)(__int64, char *))(*(_QWORD *)v6 + 160i64))(v6, v12);
          (*(void (__fastcall **)(__int64, char *))(*(_QWORD *)v6 + 120i64))(v6, v13);
          v7 = (UFG::SimObjectCVBase *)this->m_pActionContext->mSimObject.m_pPointer;
          if ( v7 )
          {
            v8 = v7->m_Flags;
            if ( (v8 & 0x4000) != 0 || v8 < 0 )
            {
              UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v7);
              return 0;
            }
            if ( (v8 & 0x2000) != 0 )
            {
              v10 = UFG::ActiveAIEntityComponent::_TypeUID;
LABEL_18:
              UFG::SimObjectGame::GetComponentOfTypeHK(v7, v10);
              return 0;
            }
            v11 = (v8 & 0x1000) == 0;
            v10 = UFG::ActiveAIEntityComponent::_TypeUID;
            if ( !v11 )
              goto LABEL_18;
            UFG::SimObject::GetComponentOfType(v7, UFG::ActiveAIEntityComponent::_TypeUID);
          }
        }
      }
    }
  }
  return 0;
}

// File Line: 6290
// RVA: 0x32AE60
void __fastcall AICoverClearCoverObjectTask::AICoverClearCoverObjectTask(AICoverClearCoverObjectTask *this)
{
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<AICoverClearCoverObjectTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&AICoverClearCoverObjectTask::`vftable;
}

// File Line: 6302
// RVA: 0x342DE0
void __fastcall AICoverClearCoverObjectTask::Begin(AICoverClearCoverObjectTask *this, ActionContext *action_context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::AICoverComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = (UFG::AICoverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                     m_pPointer,
                                                     UFG::AICoverComponent::_TypeUID);
    else
      ComponentOfTypeHK = (UFG::AICoverComponent *)UFG::SimObject::GetComponentOfType(
                                                     m_pPointer,
                                                     UFG::AICoverComponent::_TypeUID);
    if ( ComponentOfTypeHK )
      UFG::AICoverComponent::ClearCoverObjects(ComponentOfTypeHK);
  }
}

// File Line: 6331
// RVA: 0x32B0D0
void __fastcall AICoverLatchTargetedObjectTask::AICoverLatchTargetedObjectTask(AICoverLatchTargetedObjectTask *this)
{
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<AICoverLatchTargetedObjectTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&AICoverLatchTargetedObjectTask::`vftable;
}

// File Line: 6343
// RVA: 0x342E70
void __fastcall AICoverLatchTargetedObjectTask::Begin(
        AICoverLatchTargetedObjectTask *this,
        ActionContext *action_context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::AICoverComponent *v6; // rbx
  ITrack *m_Track; // rax
  UFG::CoverPosition *m_pSyncCoverPosition; // rdi

  m_pPointer = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::AICoverComponent::_TypeUID);
    else
      ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::AICoverComponent::_TypeUID);
    v6 = (UFG::AICoverComponent *)ComponentOfTypeHK;
    if ( ComponentOfTypeHK )
    {
      m_Track = this->m_Track;
      switch ( LOBYTE(m_Track[1].vfptr) )
      {
        case 1:
          m_pSyncCoverPosition = v6->m_pSyncCoverPosition;
          break;
        case 2:
          m_pSyncCoverPosition = (UFG::CoverPosition *)v6->m_pProbeCoverObject;
          break;
        case 3:
          m_pSyncCoverPosition = v6->m_pTargetedCoverPosition;
          break;
        case 4:
          m_pSyncCoverPosition = v6->m_pCurrentCoverPosition;
          break;
        default:
          return;
      }
      if ( m_pSyncCoverPosition )
      {
        if ( m_pSyncCoverPosition->vfptr->IsPosition(m_pSyncCoverPosition) )
          UFG::AICoverComponent::SetSyncCoverPosition(v6, m_pSyncCoverPosition, 0);
      }
    }
  }
}

// File Line: 6378
// RVA: 0x32AD30
void __fastcall AICopReleaseArrestRightTask::AICopReleaseArrestRightTask(AICopReleaseArrestRightTask *this)
{
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<AICopReleaseArrestRightTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&AICopReleaseArrestRightTask::`vftable;
}

// File Line: 6402
// RVA: 0x354CC0
void __fastcall AICopReleaseArrestRightTask::End(AICopReleaseArrestRightTask *this)
{
  UFG::CopSystem *v2; // rax

  v2 = UFG::CopSystem::Instance();
  v2->vfptr[105].__vecDelDtor(v2, (unsigned int)this->m_pActionContext->mSimObject.m_pPointer);
}

// File Line: 6416
// RVA: 0x32ADC0
void __fastcall AICopReportInfractionTargetTask::AICopReportInfractionTargetTask(AICopReportInfractionTargetTask *this)
{
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<AICopReportInfractionTargetTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&AICopReportInfractionTargetTask::`vftable;
}

// File Line: 6428
// RVA: 0x342D00
void __fastcall AICopReportInfractionTargetTask::Begin(
        AICopReportInfractionTargetTask *this,
        ActionContext *action_context)
{
  ITrack *m_Track; // rax
  UFG::SimObjectGame *m_pPointer; // rcx
  __int64 vfptr_low; // rbx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *ComponentOfTypeHK; // rax
  __int64 v9; // rbx
  UFG::CopSystem *v10; // rax

  m_Track = this->m_Track;
  this->m_pActionContext = action_context;
  m_pPointer = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  vfptr_low = LOBYTE(m_Track[1].vfptr);
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
      v9 = *(_QWORD *)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + vfptr_low + 8)
                     + *(_QWORD *)&m_pComponent[1].m_TypeUID
                     + 40);
      if ( v9 )
      {
        v10 = UFG::CopSystem::Instance();
        ((void (__fastcall *)(UFG::CopSystem *, UFG::SimObject *, __int64))v10->vfptr[110].__vecDelDtor)(
          v10,
          this->m_pActionContext->mSimObject.m_pPointer,
          v9);
      }
    }
  }
}

// File Line: 6463
// RVA: 0x32AB40
void __fastcall AICopApplyReducedRadiusTask::AICopApplyReducedRadiusTask(AICopApplyReducedRadiusTask *this)
{
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<AICopApplyReducedRadiusTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&AICopApplyReducedRadiusTask::`vftable;
}

// File Line: 6475
// RVA: 0x342CE0
void __fastcall AICopApplyReducedRadiusTask::Begin(AICopApplyReducedRadiusTask *this, ActionContext *action_context)
{
  UFG::CopSystem *v2; // rax

  v2 = UFG::CopSystem::Instance();
  UFG::CopSystem::ApplyReducedRadius(v2);
}

// File Line: 6486
// RVA: 0x32BAA0
void __fastcall AIOverrideAvoidanceRadiusTask::AIOverrideAvoidanceRadiusTask(AIOverrideAvoidanceRadiusTask *this)
{
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<AIOverrideAvoidanceRadiusTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&AIOverrideAvoidanceRadiusTask::`vftable;
  this->m_pNavComponent.mPrev = &this->m_pNavComponent;
  this->m_pNavComponent.mNext = &this->m_pNavComponent;
  this->m_pNavComponent.m_pPointer = 0i64;
}

// File Line: 6493
// RVA: 0x3346E0
void __fastcall AIOverrideAvoidanceRadiusTask::~AIOverrideAvoidanceRadiusTask(AIOverrideAvoidanceRadiusTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::NavComponent> *p_m_pNavComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rcx
  UFG::qNode<ITask,ITask> *v8; // rax

  this->vfptr = (ITaskVtbl *)&AIOverrideAvoidanceRadiusTask::`vftable;
  p_m_pNavComponent = &this->m_pNavComponent;
  if ( this->m_pNavComponent.m_pPointer )
  {
    mPrev = p_m_pNavComponent->mPrev;
    mNext = p_m_pNavComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pNavComponent->mPrev = p_m_pNavComponent;
    p_m_pNavComponent->mNext = p_m_pNavComponent;
  }
  p_m_pNavComponent->m_pPointer = 0i64;
  v5 = p_m_pNavComponent->mPrev;
  v6 = p_m_pNavComponent->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_m_pNavComponent->mPrev = p_m_pNavComponent;
  p_m_pNavComponent->mNext = p_m_pNavComponent;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v7 = this->mPrev;
  v8 = this->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 6499
// RVA: 0x341830
char __fastcall AdjustToNavGoal(UFG::NavComponent *pNC, double radius)
{
  float v3; // xmm6_4
  UFG::NavModulePathing *m_pNavModulePathing; // rdx
  UFG::NavPath *m_pNavPath; // rdx
  __m128 v7; // xmm1
  __m128 v8; // xmm1
  __m128 v9; // xmm4
  __m128 v10; // xmm1
  float v11; // xmm6_4
  float v12; // xmm6_4
  float v13; // xmm0_4
  hkVector4f hkvPosition; // [rsp+20h] [rbp-48h] BYREF
  hkVector4f hkvNewPosition; // [rsp+30h] [rbp-38h] BYREF

  v3 = *(float *)&radius;
  if ( !pNC )
    return 0;
  m_pNavModulePathing = pNC->m_pNavModulePathing;
  if ( !m_pNavModulePathing )
    return 0;
  m_pNavPath = m_pNavModulePathing->m_pPath.m_pNavPath;
  if ( !m_pNavPath )
    return 0;
  hkvPosition.m_quad = _mm_unpacklo_ps(
                         _mm_unpacklo_ps(
                           (__m128)LODWORD(m_pNavPath->m_aWaypoints.p[m_pNavPath->m_aWaypoints.size - 1].m_navPosition.m_vPosition.x),
                           (__m128)LODWORD(m_pNavPath->m_aWaypoints.p[m_pNavPath->m_aWaypoints.size - 1].m_navPosition.m_vPosition.z)),
                         _mm_unpacklo_ps(
                           (__m128)LODWORD(m_pNavPath->m_aWaypoints.p[m_pNavPath->m_aWaypoints.size - 1].m_navPosition.m_vPosition.y),
                           (__m128)0i64));
  if ( UFG::HavokAIUtilGame::FindMeshPositionAwayFromWall(&hkvPosition, &hkvNewPosition, radius) )
  {
    v7 = _mm_sub_ps(hkvPosition.m_quad, hkvNewPosition.m_quad);
    v8 = _mm_mul_ps(v7, v7);
    v9 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)), _mm_shuffle_ps(v8, v8, 170));
    v10 = _mm_rsqrt_ps(v9);
    v11 = v3
        - _mm_andnot_ps(
            _mm_cmple_ps(v9, (__m128)0i64),
            _mm_mul_ps(
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v9, v10), v10)),
                _mm_mul_ps(*(__m128 *)_xmm, v10)),
              v9)).m128_f32[0];
    if ( v11 > 0.0 )
    {
      v12 = v11 * 0.5;
      v13 = FLOAT_0_050000001;
      if ( v12 >= 0.050000001 )
        v13 = v12;
      pNC->m_fAvoidanceRadius = v13;
    }
  }
  return 1;
}

// File Line: 6530
// RVA: 0x343630
void __fastcall AIOverrideAvoidanceRadiusTask::Begin(
        AIOverrideAvoidanceRadiusTask *this,
        ActionContext *action_context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::SimComponent *m_pComponent; // r8
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::NavComponent> *p_m_pNavComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::NavComponent *v11; // rcx
  float AvoidanceRadius; // xmm0_4
  ITrack *m_Track; // rax
  UFG::eCollisionAvoidanceType CollisionAvoidanceType; // eax
  UFG::NavComponent *v15; // rcx
  ITrack *v16; // rax
  UFG::NavComponent *v17; // rcx
  float v18; // xmm0_4

  this->m_pActionContext = action_context;
  this->m_HasAdjustedToNavGoal = 0;
  m_pPointer = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[36].m_pComponent;
    }
    else
    {
      if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::NavComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::NavComponent::_TypeUID);
      m_pComponent = ComponentOfTypeHK;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  p_m_pNavComponent = &this->m_pNavComponent;
  if ( this->m_pNavComponent.m_pPointer )
  {
    mPrev = p_m_pNavComponent->mPrev;
    mNext = this->m_pNavComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pNavComponent->mPrev = p_m_pNavComponent;
    this->m_pNavComponent.mNext = &this->m_pNavComponent;
  }
  this->m_pNavComponent.m_pPointer = m_pComponent;
  if ( m_pComponent )
  {
    v10 = m_pComponent->m_SafePointerList.mNode.mPrev;
    v10->mNext = p_m_pNavComponent;
    p_m_pNavComponent->mPrev = v10;
    this->m_pNavComponent.mNext = &m_pComponent->m_SafePointerList.mNode;
    m_pComponent->m_SafePointerList.mNode.mPrev = p_m_pNavComponent;
  }
  v11 = (UFG::NavComponent *)this->m_pNavComponent.m_pPointer;
  if ( v11 )
  {
    AvoidanceRadius = UFG::NavComponent::GetAvoidanceRadius(v11);
    m_Track = this->m_Track;
    this->m_Radius = AvoidanceRadius;
    if ( *(float *)&m_Track[1].vfptr < 0.0 )
    {
      CollisionAvoidanceType = (unsigned int)UFG::NavComponent::GetCollisionAvoidanceType((UFG::NavComponent *)this->m_pNavComponent.m_pPointer);
      v15 = (UFG::NavComponent *)this->m_pNavComponent.m_pPointer;
      this->m_CollisionAvoidanceType = CollisionAvoidanceType;
      UFG::NavComponent::SetCollisionAvoidanceType(v15, 8i64);
    }
    v16 = this->m_Track;
    if ( BYTE4(v16[1].vfptr) )
    {
      v17 = (UFG::NavComponent *)this->m_pNavComponent.m_pPointer;
      if ( v17->m_pNavModulePathing->m_pPath.m_pNavPath )
        this->m_HasAdjustedToNavGoal = AdjustToNavGoal(v17, COERCE_DOUBLE((unsigned __int64)LODWORD(this->m_Radius)));
    }
    else
    {
      v18 = *(float *)&v16[1].vfptr;
      if ( v18 > 0.0 )
        *((float *)&this->m_pNavComponent.m_pPointer[2].m_pSimObject + 1) = v18;
    }
  }
}

// File Line: 6565
// RVA: 0x38C1D0
char __fastcall AIOverrideAvoidanceRadiusTask::Update(AIOverrideAvoidanceRadiusTask *this, float timestep)
{
  UFG::NavComponent *m_pPointer; // rcx

  if ( BYTE4(this->m_Track[1].vfptr) )
  {
    if ( !this->m_HasAdjustedToNavGoal )
    {
      m_pPointer = (UFG::NavComponent *)this->m_pNavComponent.m_pPointer;
      if ( m_pPointer )
      {
        if ( m_pPointer->m_pNavModulePathing->m_pPath.m_pNavPath )
          this->m_HasAdjustedToNavGoal = AdjustToNavGoal(
                                           m_pPointer,
                                           COERCE_DOUBLE((unsigned __int64)LODWORD(this->m_Radius)));
      }
    }
  }
  return 1;
}

// File Line: 6582
// RVA: 0x354D90
void __fastcall AIOverrideAvoidanceRadiusTask::End(AIOverrideAvoidanceRadiusTask *this)
{
  ActionContext *m_pActionContext; // rax
  UFG::NavComponent *m_pPointer; // rcx

  m_pActionContext = this->m_pActionContext;
  if ( m_pActionContext )
  {
    if ( m_pActionContext->mSimObject.m_pPointer )
    {
      m_pPointer = (UFG::NavComponent *)this->m_pNavComponent.m_pPointer;
      if ( m_pPointer )
      {
        if ( *(float *)&this->m_Track[1].vfptr < 0.0 )
          UFG::NavComponent::SetCollisionAvoidanceType(m_pPointer, (unsigned int)this->m_CollisionAvoidanceType);
        HIDWORD(this->m_pNavComponent.m_pPointer[2].m_pSimObject) = LODWORD(this->m_Radius);
      }
    }
  }
}

// File Line: 6601
// RVA: 0x32F590
void __fastcall GroupStimulusTask::GroupStimulusTask(GroupStimulusTask *this)
{
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<GroupStimulusTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&GroupStimulusTask::`vftable;
}

// File Line: 6613
// RVA: 0x345A00
void __fastcall GroupStimulusTask::Begin(GroupStimulusTask *this, ActionContext *action_context)
{
  UFG::SimObject *m_pPointer; // rax
  UFG::SceneObjectProperties *m_pSceneObj; // rdx
  UFG::qPropertySet *mpWritableProperties; // rcx
  int *v7; // rax
  unsigned int v8; // r13d
  unsigned __int64 v9; // rax
  UFG::allocator::free_link *v10; // rsi
  unsigned int v11; // r15d
  ITrack *m_Track; // rax
  float v13; // xmm9_4
  int m_eFactionClass; // ebx
  float x; // xmm6_4
  float y; // xmm7_4
  float z; // xmm8_4
  UFG::SimObject *v18; // rax
  float *m_pTransformNodeComponent; // rbx
  UFG::SimObjectCVBase *v20; // rcx
  __int16 m_Flags; // dx
  UFG::SimObjectCharacterPropertiesComponent *v22; // rax
  UFG::NearbyCharacterManager *v23; // r8
  UFG::SimObject *v24; // r14
  bool *p_m_UnboundComponentHandles; // rax
  UFG::SimObject *v26; // r9
  _QWORD *v27; // rdx
  __int64 v28; // rcx
  _QWORD *v29; // rax
  UFG::NearbyCharacterManager *mNext; // rcx
  __int64 *v31; // rdx
  __int64 v32; // r14
  __int64 v33; // rcx
  __int64 v34; // rax
  __int64 v35; // rcx
  float *v36; // rbx
  __int64 v37; // r12
  bool v38; // di
  __int64 v39; // rbx
  bool v40; // al
  __int64 v41; // r12
  float v42; // edi
  UFG::eStimulusEmissionType v43; // ebx
  unsigned __int64 v44; // rax
  UFG::allocator::free_link *v45; // rax
  UFG::allocator::free_link *v46; // r15
  UFG::allocator::free_link *v47; // rcx
  __int64 v48; // rdx
  __int64 v49; // rbx
  unsigned int v50; // r15d
  unsigned __int64 v51; // rax
  UFG::allocator::free_link *v52; // rdi
  __int64 v53; // r12
  UFG::allocator::free_link *v54; // rax
  UFG::allocator::free_link *v55; // rax
  UFG::qPropertySet *v56; // rcx
  int *v57; // rax
  unsigned int v58; // ecx
  unsigned int v59; // r14d
  unsigned int v60; // ebx
  unsigned __int64 v61; // rax
  UFG::allocator::free_link *v62; // rax
  UFG::allocator::free_link *v63; // r13
  UFG::allocator::free_link *v64; // rcx
  __int64 v65; // rdx
  int v66; // r10d
  __int64 v67; // r9
  UFG::allocator::free_link *v68; // r8
  __int64 i; // rdx
  UFG::allocator::free_link *v70; // rcx
  int v71; // edx
  int v72; // ebx
  __int64 v73; // r13
  UFG::SimObject *v74; // r14
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v75; // r15
  UFG::SimComponent *ComponentOfType; // rbx
  int v77; // r12d
  UFG::TransformNodeComponent *v78; // r14
  UFG::StimulusEmitterComponent *v79; // rax
  UFG::StimulusEmitterComponent *v80; // r8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_pStimulusTarget; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v83; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v84; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v85; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *vecDelDtor; // rax
  UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,1,0> *v87; // rax
  UFG::SimObject *v88; // r8
  UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,1,0> *v89; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v90; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v91; // rax
  __int64 *v92; // rcx
  UFG::SimObject *v93; // rax
  __int64 v94; // [rsp+0h] [rbp-99h] BYREF
  unsigned int v95; // [rsp+1Ch] [rbp-7Dh]
  bool delete_simobject_upon_expiry[8]; // [rsp+20h] [rbp-79h] BYREF
  UFG::StimulusManager *v97; // [rsp+28h] [rbp-71h]
  __int64 *v98; // [rsp+30h] [rbp-69h] BYREF
  UFG::SimObject *stimulus_emitter_object; // [rsp+38h] [rbp-61h]
  UFG::StimulusParameters stimulus_parameters; // [rsp+40h] [rbp-59h] BYREF
  __int64 v101; // [rsp+58h] [rbp-41h]
  __int64 v102; // [rsp+60h] [rbp-39h]
  __int64 v103; // [rsp+100h] [rbp+67h]
  int v104; // [rsp+108h] [rbp+6Fh]
  int v105; // [rsp+110h] [rbp+77h]
  UFG::StimulusDescription *stimulus_description; // [rsp+118h] [rbp+7Fh]

  v102 = -2i64;
  v105 = 0;
  m_pPointer = action_context->mSimObject.m_pPointer;
  if ( !m_pPointer || !m_pPointer->m_pSceneObj )
  {
    mpWritableProperties = 0i64;
LABEL_6:
    if ( !mpWritableProperties )
      goto LABEL_9;
    goto LABEL_7;
  }
  m_pSceneObj = m_pPointer->m_pSceneObj;
  mpWritableProperties = m_pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
  {
    mpWritableProperties = m_pSceneObj->mpConstProperties;
    goto LABEL_6;
  }
LABEL_7:
  v7 = UFG::qPropertySet::Get<long>(
         mpWritableProperties,
         (UFG::qArray<unsigned long,0> *)((char *)&this->m_Track[1].mResourceOwner + 4),
         DEPTH_RECURSE);
  if ( v7 )
    v105 = *v7;
LABEL_9:
  *(_QWORD *)&stimulus_parameters.m_MaxStimulusDuration = 0i64;
  v8 = 0;
  *(_QWORD *)&stimulus_parameters.m_StimulusProducerOffset.z = 0i64;
  v97 = (UFG::StimulusManager *)32;
  v9 = 256i64;
  if ( !is_mul_ok(0x20ui64, 8ui64) )
    v9 = -1i64;
  v10 = UFG::qMalloc(v9, "qArray.Reallocate(Constructor)", 0i64);
  *(_QWORD *)&stimulus_parameters.m_MaxStimulusDuration = v10;
  v11 = 32;
  stimulus_parameters.m_StimulusEmissionType = 32;
  m_Track = this->m_Track;
  v13 = *((float *)&m_Track[1].vfptr + 1);
  LODWORD(stimulus_description) = LOBYTE(m_Track[1].mResourceOwner);
  m_eFactionClass = 17;
  x = UFG::qVector3::msZero.x;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  v18 = action_context->mSimObject.m_pPointer;
  stimulus_emitter_object = v18;
  if ( v18 )
  {
    m_pTransformNodeComponent = (float *)v18->m_pTransformNodeComponent;
    if ( m_pTransformNodeComponent )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(v18->m_pTransformNodeComponent);
      x = m_pTransformNodeComponent[44];
      y = m_pTransformNodeComponent[45];
      z = m_pTransformNodeComponent[46];
    }
    m_eFactionClass = 17;
  }
  v20 = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
  if ( v20 )
  {
    m_Flags = v20->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
      v22 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v20);
    else
      v22 = (UFG::SimObjectCharacterPropertiesComponent *)((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                                         ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             v20,
                                                             UFG::SimObjectCharacterPropertiesComponent::_TypeUID)
                                                         : UFG::SimObject::GetComponentOfType(
                                                             v20,
                                                             UFG::SimObjectCharacterPropertiesComponent::_TypeUID));
    if ( v22 )
      m_eFactionClass = v22->m_eFactionClass;
  }
  stimulus_emitter_object = (UFG::SimObject *)&v98;
  v23 = UFG::NearbyCharacterManager::s_pInstance;
  v24 = (UFG::SimObject *)&v98;
  p_m_UnboundComponentHandles = delete_simobject_upon_expiry;
  v98 = &v94 + 4;
  v26 = (UFG::SimObject *)v98;
  if ( delete_simobject_upon_expiry != (bool *)v98 )
  {
    do
    {
      v27 = p_m_UnboundComponentHandles + 16;
      v28 = *((_QWORD *)p_m_UnboundComponentHandles + 2);
      v29 = (_QWORD *)*((_QWORD *)p_m_UnboundComponentHandles + 3);
      *(_QWORD *)(v28 + 8) = v29;
      *v29 = v28;
      *v27 = v27;
      v27[1] = v27;
      v24 = stimulus_emitter_object;
      p_m_UnboundComponentHandles = (bool *)&stimulus_emitter_object[-1].m_UnboundComponentHandles;
    }
    while ( &stimulus_emitter_object[-1].m_UnboundComponentHandles != (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,1,0> *)v26 );
  }
  mNext = (UFG::NearbyCharacterManager *)v23->m_Characters[0].mNode.mNext;
  if ( mNext != v23 )
  {
    v31 = v98;
    do
    {
      v31[1] = (__int64)&mNext->m_Characters[1];
      mNext->m_Characters[1].mNode.mPrev = (UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterMasterList> *)v31;
      mNext->m_Characters[1].mNode.mNext = (UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterMasterList> *)&v98;
      v31 = (__int64 *)&mNext->m_Characters[1];
      v98 = (__int64 *)&mNext->m_Characters[1];
      mNext = (UFG::NearbyCharacterManager *)mNext->m_Characters[0].mNode.mNext;
    }
    while ( mNext != v23 );
    v24 = stimulus_emitter_object;
  }
  v32 = (__int64)&v24[-1].m_UnboundComponentHandles;
  *(_QWORD *)&stimulus_parameters.m_StimulusProducerOffset.x = m_eFactionClass;
  if ( (UFG::SimObject *)v32 != v26 )
  {
    do
    {
      v33 = *(_QWORD *)(v32 + 48);
      if ( v33 )
      {
        if ( (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v33 + 112i64))(v33) )
        {
          v34 = *(_QWORD *)(v32 + 48);
          if ( *(UFG::SimObject **)(v34 + 40) != stimulus_emitter_object )
          {
            v35 = *(_QWORD *)(v34 + 424);
            v36 = *(float **)(v34 + 88);
            v37 = *(_QWORD *)(v34 + 280);
            if ( v36 )
            {
              if ( v35 )
              {
                if ( v37 )
                {
                  v38 = *(_BYTE *)(v35 + 116) == 0;
                  UFG::TransformNodeComponent::UpdateWorldTransform(*(UFG::TransformNodeComponent **)(v34 + 88));
                  LOBYTE(v104) = v13 > fsqrt(
                                         (float)((float)((float)(x - v36[44]) * (float)(x - v36[44]))
                                               + (float)((float)(y - v36[45]) * (float)(y - v36[45])))
                                       + (float)((float)(z - v36[46]) * (float)(z - v36[46])));
                  v39 = *(int *)(v37 + 200);
                  v40 = UFG::GameStatTracker::Instance()->mFactionInterface.mStandings[*(_QWORD *)&stimulus_parameters.m_StimulusProducerOffset.x][v39] == (_DWORD)stimulus_description;
                  if ( v38 && (_BYTE)v104 && v40 )
                  {
                    v41 = v8;
                    LODWORD(v42) = v8 + 1;
                    if ( v8 + 1 > v11 )
                    {
                      v43 = eSTIMULUS_EMISSION_CONTINUOUS;
                      if ( v11 )
                        v43 = 2 * v11;
                      for ( ; (unsigned int)v43 < LODWORD(v42); v43 *= 2 )
                        ;
                      if ( (unsigned int)v43 <= NUM_STIMULUS_EMISSION_TYPES )
                        v43 = NUM_STIMULUS_EMISSION_TYPES;
                      if ( (unsigned int)(v43 - LODWORD(v42)) > 0x10000 )
                        v43 = v8 + 65537;
                      if ( v43 != v8 )
                      {
                        v44 = 8i64 * (unsigned int)v43;
                        if ( !is_mul_ok((unsigned int)v43, 8ui64) )
                          v44 = -1i64;
                        v45 = UFG::qMalloc(v44, "qArray.Add", 0i64);
                        v46 = v45;
                        if ( v10 )
                        {
                          if ( v8 )
                          {
                            v47 = v45;
                            v48 = v8;
                            do
                            {
                              v47->mNext = *(UFG::allocator::free_link **)((char *)v47 + (char *)v10 - (char *)v45);
                              ++v47;
                              --v48;
                            }
                            while ( v48 );
                          }
                          operator delete[](v10);
                        }
                        v10 = v46;
                        *(_QWORD *)&stimulus_parameters.m_MaxStimulusDuration = v46;
                        v11 = v43;
                        stimulus_parameters.m_StimulusEmissionType = v43;
                      }
                    }
                    ++v8;
                    stimulus_parameters.m_StimulusProducerOffset.z = v42;
                    v10[v41].mNext = (UFG::allocator::free_link *)v32;
                  }
                }
              }
            }
          }
        }
      }
      v32 = *(_QWORD *)(v32 + 24) - 16i64;
    }
    while ( (__int64 *)v32 != v98 );
  }
  v49 = 0i64;
  *(_QWORD *)delete_simobject_upon_expiry = 0i64;
  v50 = 0;
  v101 = 0i64;
  v51 = 128i64;
  if ( !is_mul_ok(0x20ui64, 4ui64) )
    v51 = -1i64;
  v52 = UFG::qMalloc(v51, "qArray.Reallocate(Constructor)", 0i64);
  *(_QWORD *)delete_simobject_upon_expiry = v52;
  v95 = 32;
  *(_QWORD *)&stimulus_parameters.m_StimulusProducerOffset.x = 0i64;
  v53 = v8;
  v101 = v8;
  if ( v8 )
  {
    do
    {
      v54 = v10[v49].mNext[6].mNext[5].mNext;
      if ( v54 )
      {
        if ( v54[10].mNext )
        {
          v55 = v54[10].mNext;
          v56 = (UFG::qPropertySet *)v55[18].mNext;
          if ( v56 || (v56 = (UFG::qPropertySet *)v55[19].mNext) != 0i64 )
          {
            v57 = UFG::qPropertySet::Get<long>(
                    v56,
                    (UFG::qArray<unsigned long,0> *)(*(_QWORD *)(v103 + 24) + 72i64),
                    DEPTH_RECURSE);
            if ( v57 )
            {
              LODWORD(stimulus_description) = *v57;
              v58 = v50;
              v59 = v50 + 1;
              if ( v50 + 1 > (unsigned int)v97 )
              {
                v60 = 1;
                if ( (_DWORD)v97 )
                  v60 = 2 * (_DWORD)v97;
                for ( ; v60 < v59; v60 *= 2 )
                  ;
                if ( v60 <= 4 )
                  v60 = 4;
                if ( v60 - v59 > 0x10000 )
                  v60 = v50 + 65537;
                if ( v60 != v50 )
                {
                  v61 = 4i64 * v60;
                  if ( !is_mul_ok(v60, 4ui64) )
                    v61 = -1i64;
                  v62 = UFG::qMalloc(v61, "qArray.Add", 0i64);
                  v63 = v62;
                  if ( v52 )
                  {
                    if ( v50 )
                    {
                      v64 = v62;
                      v65 = v50;
                      do
                      {
                        LODWORD(v64->mNext) = *(_DWORD *)((char *)&v64->mNext + (char *)v52 - (char *)v62);
                        v64 = (UFG::allocator::free_link *)((char *)v64 + 4);
                        --v65;
                      }
                      while ( v65 );
                    }
                    operator delete[](v52);
                  }
                  v52 = v63;
                  *(_QWORD *)delete_simobject_upon_expiry = v63;
                  v97 = (UFG::StimulusManager *)v60;
                  v95 = v60;
                  v58 = v50;
                }
                v49 = *(_QWORD *)&stimulus_parameters.m_StimulusProducerOffset.x;
              }
              ++v50;
              LODWORD(v101) = v59;
              *((_DWORD *)&v52->mNext + v58) = (_DWORD)stimulus_description;
            }
          }
        }
      }
      *(_QWORD *)&stimulus_parameters.m_StimulusProducerOffset.x = ++v49;
    }
    while ( v49 < v53 );
  }
  v66 = 0;
  v67 = 0i64;
  if ( v53 > 0 )
  {
    v68 = v52;
    do
    {
      for ( i = v66; i < v53; ++i )
      {
        if ( SLODWORD(v68->mNext) > *((_DWORD *)&v52->mNext + i) )
        {
          v70 = v10[v67].mNext;
          v10[v67] = v10[i];
          v10[i].mNext = v70;
          LODWORD(v70) = v68->mNext;
          LODWORD(v68->mNext) = *((_DWORD *)&v52->mNext + i);
          *((_DWORD *)&v52->mNext + i) = (_DWORD)v70;
        }
      }
      ++v66;
      ++v67;
      v68 = (UFG::allocator::free_link *)((char *)v68 + 4);
    }
    while ( v67 < v53 );
  }
  v71 = *(unsigned __int8 *)(*(_QWORD *)(v103 + 24) + 56i64);
  v104 = v71;
  v72 = 0;
  LODWORD(v103) = 0;
  v73 = 0i64;
  if ( v53 > 0 )
  {
    v74 = stimulus_emitter_object;
    do
    {
      if ( v72 + *((_DWORD *)&v52->mNext + v73) >= v105 )
        break;
      stimulus_parameters.m_StimulusEmissionType = eSTIMULUS_EMISSION_ONE_OFF;
      stimulus_parameters.m_MaxStimulusDuration = -1.0;
      stimulus_parameters.m_EmitUntilSpeedLessThan = -1.0;
      stimulus_parameters.m_StimulusProducerOffset = UFG::qVector3::msZero;
      v75 = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)v10[v73].mNext[6].mNext[5].mNext;
      v97 = UFG::StimulusManager::s_pInstance;
      stimulus_description = &UFG::g_StimulusDescriptions[v71];
      if ( v74 )
      {
        ComponentOfType = UFG::SimObject::GetComponentOfType(v74, UFG::StimulusEmitterComponent::_TypeUID);
        if ( ComponentOfType )
        {
          v77 = v104;
          do
          {
            v78 = UFG::SimObject::GetComponentOfType(
                    ComponentOfType->m_pSimObject,
                    UFG::StimulusEmitterComponent::_StimulusEmitterComponentTypeUID,
                    0,
                    ComponentOfType);
            if ( LODWORD(ComponentOfType[1].m_SafePointerList.mNode.mNext) == v77
              && BYTE4(ComponentOfType[6].m_BoundComponentHandles.mNode.mPrev)
              && ComponentOfType[8].vfptr == v75 )
            {
              UFG::Simulation::DestroySimComponent(&UFG::gSim, ComponentOfType);
            }
            ComponentOfType = v78;
          }
          while ( v78 );
          v53 = v101;
          v74 = stimulus_emitter_object;
        }
        v72 = v103;
      }
      v79 = UFG::StimulusManager::AttachStimulusEmitterComponent(
              v97,
              stimulus_description,
              &stimulus_parameters,
              v74,
              0);
      v80 = v79;
      if ( v75 && v79 )
      {
        v79->m_IsTargeted = 0;
        v79->m_StimulusTargetType = eTARGET_TYPE_INVALID;
        v79->m_pStimulusTargetingSystem.m_pSimComponent = 0i64;
        p_m_pStimulusTarget = &v79->m_pStimulusTarget;
        if ( v79->m_pStimulusTarget.m_pPointer )
        {
          mPrev = p_m_pStimulusTarget->mPrev;
          v83 = v79->m_pStimulusTarget.mNext;
          mPrev->mNext = v83;
          v83->mPrev = mPrev;
          p_m_pStimulusTarget->mPrev = p_m_pStimulusTarget;
          p_m_pStimulusTarget->mNext = p_m_pStimulusTarget;
        }
        p_m_pStimulusTarget->m_pPointer = 0i64;
        v80->m_IsTargeted = 1;
        if ( p_m_pStimulusTarget->m_pPointer )
        {
          v84 = p_m_pStimulusTarget->mPrev;
          v85 = p_m_pStimulusTarget->mNext;
          v84->mNext = v85;
          v85->mPrev = v84;
          p_m_pStimulusTarget->mPrev = p_m_pStimulusTarget;
          p_m_pStimulusTarget->mNext = p_m_pStimulusTarget;
        }
        p_m_pStimulusTarget->m_pPointer = (UFG::SimObject *)v75;
        vecDelDtor = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)v75[1].__vecDelDtor;
        vecDelDtor->mNext = p_m_pStimulusTarget;
        p_m_pStimulusTarget->mPrev = vecDelDtor;
        p_m_pStimulusTarget->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v75[1];
        v75[1].__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int))p_m_pStimulusTarget;
      }
      v72 += *((_DWORD *)&v52->mNext + v73);
      LODWORD(v103) = v72;
      ++v73;
      v71 = v104;
    }
    while ( v73 < v53 );
  }
  if ( v52 )
    operator delete[](v52);
  *(_QWORD *)delete_simobject_upon_expiry = 0i64;
  v101 = 0i64;
  v87 = &stimulus_emitter_object[-1].m_UnboundComponentHandles;
  v88 = (UFG::SimObject *)v98;
  if ( &stimulus_emitter_object[-1].m_UnboundComponentHandles != (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,1,0> *)v98 )
  {
    do
    {
      v89 = v87 + 1;
      v90 = v87[1].mNode.mPrev;
      v91 = v87[1].mNode.mNext;
      v90->mNext = v91;
      v91->mPrev = v90;
      v89->mNode.mPrev = &v89->mNode;
      v89->mNode.mNext = &v89->mNode;
      v87 = &stimulus_emitter_object[-1].m_UnboundComponentHandles;
    }
    while ( &stimulus_emitter_object[-1].m_UnboundComponentHandles != (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,1,0> *)v88 );
  }
  v92 = v98;
  v93 = stimulus_emitter_object;
  v98[1] = (__int64)stimulus_emitter_object;
  v93->vfptr = (UFG::qSafePointerNode<UFG::SimObject>Vtbl *)v92;
  v98 = (__int64 *)&v98;
  stimulus_emitter_object = (UFG::SimObject *)&v98;
  if ( v10 )
    operator delete[](v10);
}&v89->mNode;
      v87 = &stimulus_emitter_object[-1].m_Unbound

// File Line: 6784
// RVA: 0x32CCB0
void __fastcall AttackRightsScoreBonusTask::AttackRightsScoreBonusTask(AttackRightsScoreBonusTask *this)
{
  this->Task<AttackRightsScoreBonusTrack>::ITask::UFG::qNode<ITask,ITask>::mPrev = &this->UFG::qNode<ITask,ITask>;
  this->Task<AttackRightsScoreBonusTrack>::ITask::UFG::qNode<ITask,ITask>::mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<AttackRightsScoreBonusTrack>::`vftable;
  this->UFG::qNode<AttackRightsScoreBonusTask,HasAttackRequestComponentList>::mPrev = &this->UFG::qNode<AttackRightsScoreBonusTask,HasAttackRequestComponentList>;
  this->UFG::qNode<AttackRightsScoreBonusTask,HasAttackRequestComponentList>::mNext = &this->UFG::qNode<AttackRightsScoreBonusTask,HasAttackRequestComponentList>;
  this->vfptr = (ITaskVtbl *)&AttackRightsScoreBonusTask::`vftable;
}

// File Line: 6812
// RVA: 0x344040
void __fastcall AttackRightsScoreBonusTask::Begin(AttackRightsScoreBonusTask *this, ActionContext *action_context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  UFG::qNode<AttackRightsScoreBonusTask,HasAttackRequestComponentList> *p_m_Flags; // rdx
  UFG::qNode<AttackRightsScoreBonusTask,HasAttackRequestComponentList> *v7; // rax

  this->m_pActionContext = action_context;
  m_pPointer = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[35].m_pComponent;
    }
    else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::HasAttackRequestComponent::_TypeUID);
    }
    else
    {
      m_pComponent = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::HasAttackRequestComponent::_TypeUID);
    }
    if ( m_pComponent )
    {
      p_m_Flags = (UFG::qNode<AttackRightsScoreBonusTask,HasAttackRequestComponentList> *)&m_pComponent[1].m_Flags;
      v7 = *(UFG::qNode<AttackRightsScoreBonusTask,HasAttackRequestComponentList> **)&m_pComponent[1].m_Flags;
      v7->mNext = &this->UFG::qNode<AttackRightsScoreBonusTask,HasAttackRequestComponentList>;
      this->UFG::qNode<AttackRightsScoreBonusTask,HasAttackRequestComponentList>::mPrev = v7;
      this->UFG::qNode<AttackRightsScoreBonusTask,HasAttackRequestComponentList>::mNext = p_m_Flags;
      p_m_Flags->mPrev = &this->UFG::qNode<AttackRightsScoreBonusTask,HasAttackRequestComponentList>;
    }
  }
}

// File Line: 6845
// RVA: 0x332410
void __fastcall TargetActionRequestTask::TargetActionRequestTask(TargetActionRequestTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::AICharacterControllerBaseComponent> *p_m_pCharControllerComp; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax

  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<TargetActionRequestTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&TargetActionRequestTask::`vftable;
  p_m_pCharControllerComp = &this->m_pCharControllerComp;
  this->m_pCharControllerComp.mPrev = &this->m_pCharControllerComp;
  this->m_pCharControllerComp.mNext = &this->m_pCharControllerComp;
  this->m_pCharControllerComp.m_pPointer = 0i64;
  this->m_pTarget.mPrev = &this->m_pTarget;
  this->m_pTarget.mNext = &this->m_pTarget;
  this->m_pTarget.m_pPointer = 0i64;
  this->m_pActionContext = 0i64;
  if ( this->m_pCharControllerComp.m_pPointer )
  {
    mPrev = p_m_pCharControllerComp->mPrev;
    mNext = p_m_pCharControllerComp->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pCharControllerComp->mPrev = p_m_pCharControllerComp;
    p_m_pCharControllerComp->mNext = p_m_pCharControllerComp;
  }
  p_m_pCharControllerComp->m_pPointer = 0i64;
}

// File Line: 6853
// RVA: 0x33B560
void __fastcall TargetActionRequestTask::~TargetActionRequestTask(TargetActionRequestTask *this)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_pTarget; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AICharacterControllerBaseComponent> *p_m_pCharControllerComp; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<ITask,ITask> *v12; // rcx
  UFG::qNode<ITask,ITask> *v13; // rax

  this->vfptr = (ITaskVtbl *)&TargetActionRequestTask::`vftable;
  p_m_pTarget = &this->m_pTarget;
  if ( this->m_pTarget.m_pPointer )
  {
    mPrev = p_m_pTarget->mPrev;
    mNext = p_m_pTarget->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pTarget->mPrev = p_m_pTarget;
    p_m_pTarget->mNext = p_m_pTarget;
  }
  p_m_pTarget->m_pPointer = 0i64;
  v5 = p_m_pTarget->mPrev;
  v6 = p_m_pTarget->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_m_pTarget->mPrev = p_m_pTarget;
  p_m_pTarget->mNext = p_m_pTarget;
  p_m_pCharControllerComp = &this->m_pCharControllerComp;
  if ( this->m_pCharControllerComp.m_pPointer )
  {
    v8 = p_m_pCharControllerComp->mPrev;
    v9 = this->m_pCharControllerComp.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    p_m_pCharControllerComp->mPrev = p_m_pCharControllerComp;
    this->m_pCharControllerComp.mNext = &this->m_pCharControllerComp;
  }
  this->m_pCharControllerComp.m_pPointer = 0i64;
  v10 = p_m_pCharControllerComp->mPrev;
  v11 = this->m_pCharControllerComp.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  p_m_pCharControllerComp->mPrev = p_m_pCharControllerComp;
  this->m_pCharControllerComp.mNext = &this->m_pCharControllerComp;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v12 = this->mPrev;
  v13 = this->mNext;
  v12->mNext = v13;
  v13->mPrev = v12;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 6858
// RVA: 0x348910
void __fastcall TargetActionRequestTask::Begin(TargetActionRequestTask *this, ActionContext *action_context)
{
  ITrack *m_Track; // rax
  __int64 vfptr_high; // rsi
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_pTarget; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *v11; // rax
  UFG::SimObject *v12; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v15; // rax
  UFG::SimObjectCVBase *v16; // rcx
  __int16 v17; // dx
  UFG::AICharacterControllerBaseComponent *ComponentOfTypeHK; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AICharacterControllerBaseComponent> *p_m_pCharControllerComp; // rdx
  UFG::SimComponent *v20; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v21; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v22; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v23; // rax

  m_Track = this->m_Track;
  this->m_pActionContext = action_context;
  vfptr_high = HIDWORD(m_Track[1].vfptr);
  p_m_pTarget = &this->m_pTarget;
  if ( this->m_pTarget.m_pPointer )
  {
    mPrev = p_m_pTarget->mPrev;
    mNext = this->m_pTarget.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pTarget->mPrev = p_m_pTarget;
    this->m_pTarget.mNext = &this->m_pTarget;
  }
  this->m_pTarget.m_pPointer = 0i64;
  m_pPointer = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      v11 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
          ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
          : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = v11;
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    if ( m_pComponent )
    {
      v12 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + vfptr_high + 8)
                               + *(_QWORD *)&m_pComponent[1].m_TypeUID
                               + 40);
      if ( v12 )
      {
        if ( p_m_pTarget->m_pPointer )
        {
          v13 = p_m_pTarget->mPrev;
          v14 = p_m_pTarget->mNext;
          v13->mNext = v14;
          v14->mPrev = v13;
          p_m_pTarget->mPrev = p_m_pTarget;
          p_m_pTarget->mNext = p_m_pTarget;
        }
        p_m_pTarget->m_pPointer = v12;
        v15 = v12->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
        v15->mNext = p_m_pTarget;
        p_m_pTarget->mPrev = v15;
        p_m_pTarget->mNext = &v12->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
        v12->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_m_pTarget;
      }
    }
  }
  v16 = (UFG::SimObjectCVBase *)this->m_pTarget.m_pPointer;
  if ( v16 )
  {
    v17 = v16->m_Flags;
    if ( (v17 & 0x4000) != 0 || v17 < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v16);
    }
    else if ( (v17 & 0x2000) != 0 || (v17 & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                       v16,
                                                                       UFG::AICharacterControllerBaseComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::AICharacterControllerBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                                       v16,
                                                                       UFG::AICharacterControllerBaseComponent::_TypeUID);
    }
    p_m_pCharControllerComp = &this->m_pCharControllerComp;
    v20 = ComponentOfTypeHK;
    if ( this->m_pCharControllerComp.m_pPointer )
    {
      v21 = p_m_pCharControllerComp->mPrev;
      v22 = this->m_pCharControllerComp.mNext;
      v21->mNext = v22;
      v22->mPrev = v21;
      p_m_pCharControllerComp->mPrev = p_m_pCharControllerComp;
      this->m_pCharControllerComp.mNext = &this->m_pCharControllerComp;
    }
    this->m_pCharControllerComp.m_pPointer = v20;
    if ( v20 )
    {
      v23 = v20->m_SafePointerList.mNode.mPrev;
      v23->mNext = p_m_pCharControllerComp;
      p_m_pCharControllerComp->mPrev = v23;
      this->m_pCharControllerComp.mNext = &v20->m_SafePointerList.mNode;
      v20->m_SafePointerList.mNode.mPrev = p_m_pCharControllerComp;
    }
  }
  ((void (__fastcall *)(TargetActionRequestTask *))this->vfptr->Update)(this);
}

// File Line: 6883
// RVA: 0x3934F0
char __fastcall TargetActionRequestTask::Update(TargetActionRequestTask *this, float timestep)
{
  UFG::SimComponent *m_pPointer; // rdx
  ITrack *m_Track; // rax
  __int64 vfptr_low; // r9
  __int64 v5; // r8
  float v6; // xmm0_4

  m_pPointer = this->m_pCharControllerComp.m_pPointer;
  if ( m_pPointer )
  {
    m_Track = this->m_Track;
    vfptr_low = LODWORD(m_Track[1].vfptr);
    v5 = 1i64 << ((__int64)m_Track[1].vfptr & 0x3F);
    *((_QWORD *)&m_pPointer[4].m_BoundComponentHandles.mNode.mPrev + ((__int64)(int)vfptr_low >> 6)) |= v5;
    v6 = (float)(int)0.0;
    if ( v6 >= 255.0 )
      v6 = FLOAT_255_0;
    *((_BYTE *)&m_pPointer[5].m_BoundComponentHandles.mNode.mNext + vfptr_low) = (int)v6;
    m_pPointer[4].m_pSimObject = (UFG::SimObject *)((__int64)m_pPointer[4].m_pSimObject | v5);
  }
  return 1;
}

// File Line: 6913
// RVA: 0x3304A0
void __fastcall LockFormationPositionToCurrentPositionTask::LockFormationPositionToCurrentPositionTask(
        LockFormationPositionToCurrentPositionTask *this)
{
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<LockFormationPositionToCurrentPositionTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&LockFormationPositionToCurrentPositionTask::`vftable;
  this->m_pActionContext = 0i64;
}

// File Line: 6927
// RVA: 0x346B70
void __fastcall LockFormationPositionToCurrentPositionTask::Begin(
        LockFormationPositionToCurrentPositionTask *this,
        ActionContext *action_context)
{
  UFG::SimObjectGame *m_pPointer; // r8
  __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rax

  this->m_pActionContext = action_context;
  m_pPointer = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[32].m_pComponent;
    }
    else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::GetInFormationComponent::_TypeUID);
    }
    else
    {
      m_pComponent = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::GetInFormationComponent::_TypeUID);
    }
    if ( m_pComponent )
      LOBYTE(m_pComponent[1].m_Flags) = 1;
  }
}

// File Line: 6953
// RVA: 0x355250
void __fastcall LockFormationPositionToCurrentPositionTask::End(LockFormationPositionToCurrentPositionTask *this)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax

  m_pPointer = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[32].m_pComponent;
    }
    else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::GetInFormationComponent::_TypeUID);
    }
    else
    {
      m_pComponent = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::GetInFormationComponent::_TypeUID);
    }
    if ( m_pComponent )
      LOBYTE(m_pComponent[1].m_Flags) = 0;
  }
}

// File Line: 6971
// RVA: 0x32E870
void __fastcall ForceUpdateTargetingTask::ForceUpdateTargetingTask(ForceUpdateTargetingTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemPedBaseComponent> *p_m_pTargetingSystemPedBaseComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax

  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<ForceUpdateTargetingTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&ForceUpdateTargetingTask::`vftable;
  p_m_pTargetingSystemPedBaseComponent = &this->m_pTargetingSystemPedBaseComponent;
  this->m_pTargetingSystemPedBaseComponent.mPrev = &this->m_pTargetingSystemPedBaseComponent;
  this->m_pTargetingSystemPedBaseComponent.mNext = &this->m_pTargetingSystemPedBaseComponent;
  this->m_pTargetingSystemPedBaseComponent.m_pPointer = 0i64;
  this->m_pActionContext = 0i64;
  if ( this->m_pTargetingSystemPedBaseComponent.m_pPointer )
  {
    mPrev = p_m_pTargetingSystemPedBaseComponent->mPrev;
    mNext = p_m_pTargetingSystemPedBaseComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pTargetingSystemPedBaseComponent->mPrev = p_m_pTargetingSystemPedBaseComponent;
    p_m_pTargetingSystemPedBaseComponent->mNext = p_m_pTargetingSystemPedBaseComponent;
  }
  p_m_pTargetingSystemPedBaseComponent->m_pPointer = 0i64;
}

// File Line: 6979
// RVA: 0x337000
void __fastcall ForceUpdateTargetingTask::~ForceUpdateTargetingTask(ForceUpdateTargetingTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemPedBaseComponent> *p_m_pTargetingSystemPedBaseComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rcx
  UFG::qNode<ITask,ITask> *v8; // rax

  this->vfptr = (ITaskVtbl *)&ForceUpdateTargetingTask::`vftable;
  p_m_pTargetingSystemPedBaseComponent = &this->m_pTargetingSystemPedBaseComponent;
  if ( this->m_pTargetingSystemPedBaseComponent.m_pPointer )
  {
    mPrev = p_m_pTargetingSystemPedBaseComponent->mPrev;
    mNext = p_m_pTargetingSystemPedBaseComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pTargetingSystemPedBaseComponent->mPrev = p_m_pTargetingSystemPedBaseComponent;
    p_m_pTargetingSystemPedBaseComponent->mNext = p_m_pTargetingSystemPedBaseComponent;
  }
  p_m_pTargetingSystemPedBaseComponent->m_pPointer = 0i64;
  v5 = p_m_pTargetingSystemPedBaseComponent->mPrev;
  v6 = p_m_pTargetingSystemPedBaseComponent->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_m_pTargetingSystemPedBaseComponent->mPrev = p_m_pTargetingSystemPedBaseComponent;
  p_m_pTargetingSystemPedBaseComponent->mNext = p_m_pTargetingSystemPedBaseComponent;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v7 = this->mPrev;
  v8 = this->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 6983
// RVA: 0x345260
void __fastcall ForceUpdateTargetingTask::Begin(ForceUpdateTargetingTask *this, ActionContext *action_context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::SimComponent *v4; // r8
  __int16 m_Flags; // dx
  UFG::TargetingSystemPedBaseComponent *ComponentOfTypeHK; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemPedBaseComponent> *p_m_pTargetingSystemPedBaseComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax

  this->m_pActionContext = action_context;
  if ( action_context )
  {
    m_pPointer = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
      {
        ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedBaseComponent>(m_pPointer);
      }
      else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      {
        ComponentOfTypeHK = (UFG::TargetingSystemPedBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                      m_pPointer,
                                                                      UFG::TargetingSystemPedBaseComponent::_TypeUID);
      }
      else
      {
        ComponentOfTypeHK = (UFG::TargetingSystemPedBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                                      m_pPointer,
                                                                      UFG::TargetingSystemPedBaseComponent::_TypeUID);
      }
      v4 = ComponentOfTypeHK;
    }
    else
    {
      v4 = 0i64;
    }
    p_m_pTargetingSystemPedBaseComponent = &this->m_pTargetingSystemPedBaseComponent;
    if ( this->m_pTargetingSystemPedBaseComponent.m_pPointer )
    {
      mPrev = p_m_pTargetingSystemPedBaseComponent->mPrev;
      mNext = this->m_pTargetingSystemPedBaseComponent.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_m_pTargetingSystemPedBaseComponent->mPrev = p_m_pTargetingSystemPedBaseComponent;
      this->m_pTargetingSystemPedBaseComponent.mNext = &this->m_pTargetingSystemPedBaseComponent;
    }
    this->m_pTargetingSystemPedBaseComponent.m_pPointer = v4;
    if ( v4 )
    {
      v10 = v4->m_SafePointerList.mNode.mPrev;
      v10->mNext = p_m_pTargetingSystemPedBaseComponent;
      p_m_pTargetingSystemPedBaseComponent->mPrev = v10;
      this->m_pTargetingSystemPedBaseComponent.mNext = &v4->m_SafePointerList.mNode;
      v4->m_SafePointerList.mNode.mPrev = p_m_pTargetingSystemPedBaseComponent;
    }
  }
}

// File Line: 6995
// RVA: 0x38F210
char __fastcall ForceUpdateTargetingTask::Update(ForceUpdateTargetingTask *this, float timestep)
{
  UFG::SimComponent *m_pPointer; // rax

  m_pPointer = this->m_pTargetingSystemPedBaseComponent.m_pPointer;
  if ( m_pPointer )
    LOBYTE(m_pPointer[9].vfptr) = 1;
  return 1;
}

// File Line: 7013
// RVA: 0x343DC0
void __fastcall AddTargetAsDangerousEntityTask::Begin(
        AddTargetAsDangerousEntityTask *this,
        ActionContext *action_context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::ActiveAIEntityComponent *v6; // rax
  UFG::AIEntityComponent *v7; // rbx
  UFG::SimObjectGame *v8; // rcx
  __int16 v9; // dx
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
      v6 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(m_pPointer);
    else
      v6 = (UFG::ActiveAIEntityComponent *)((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                          ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                              m_pPointer,
                                              UFG::ActiveAIEntityComponent::_TypeUID)
                                          : UFG::SimObject::GetComponentOfType(
                                              m_pPointer,
                                              UFG::ActiveAIEntityComponent::_TypeUID));
    v7 = v6;
    if ( v6 )
    {
      v8 = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
      if ( v8 )
      {
        v9 = v8->m_Flags;
        if ( (v9 & 0x4000) != 0 )
        {
          m_pComponent = v8->m_Components.p[20].m_pComponent;
        }
        else if ( v9 >= 0 )
        {
          if ( (v9 & 0x2000) != 0 || (v9 & 0x1000) != 0 )
            ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                  v8,
                                  UFG::TargetingSystemBaseComponent::_TypeUID);
          else
            ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v8, UFG::TargetingSystemBaseComponent::_TypeUID);
          m_pComponent = ComponentOfTypeHK;
        }
        else
        {
          m_pComponent = v8->m_Components.p[20].m_pComponent;
        }
        if ( m_pComponent )
          UFG::AIEntityComponent::AddThreatTarget(
            v7,
            *(UFG::SimObject **)(56i64
                               * *(unsigned __int8 *)(LOBYTE(this->m_Track[1].vfptr)
                                                    + *(_QWORD *)&m_pComponent[1].m_Flags
                                                    + 8i64)
                               + *(_QWORD *)&m_pComponent[1].m_TypeUID
                               + 40),
            *((float *)&this->m_Track[1].vfptr + 1));
      }
    }
  }
}

// File Line: 7037
// RVA: 0x331C20
void __fastcall SetDriverFlagsTask::SetDriverFlagsTask(SetDriverFlagsTask *this)
{
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<SetDriverFlagsTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&SetDriverFlagsTask::`vftable;
  this->m_pAIDriverComponent.mPrev = &this->m_pAIDriverComponent;
  this->m_pAIDriverComponent.mNext = &this->m_pAIDriverComponent;
  this->m_pAIDriverComponent.m_pPointer = 0i64;
  *(_DWORD *)&this->m_PrevAvoidPeds = 0;
}

// File Line: 7045
// RVA: 0x33ACA0
void __fastcall SetDriverFlagsTask::~SetDriverFlagsTask(SetDriverFlagsTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::AiDriverComponent> *p_m_pAIDriverComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rcx
  UFG::qNode<ITask,ITask> *v8; // rax

  this->vfptr = (ITaskVtbl *)&SetDriverFlagsTask::`vftable;
  p_m_pAIDriverComponent = &this->m_pAIDriverComponent;
  if ( this->m_pAIDriverComponent.m_pPointer )
  {
    mPrev = p_m_pAIDriverComponent->mPrev;
    mNext = p_m_pAIDriverComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pAIDriverComponent->mPrev = p_m_pAIDriverComponent;
    p_m_pAIDriverComponent->mNext = p_m_pAIDriverComponent;
  }
  p_m_pAIDriverComponent->m_pPointer = 0i64;
  v5 = p_m_pAIDriverComponent->mPrev;
  v6 = p_m_pAIDriverComponent->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_m_pAIDriverComponent->mPrev = p_m_pAIDriverComponent;
  p_m_pAIDriverComponent->mNext = p_m_pAIDriverComponent;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v7 = this->mPrev;
  v8 = this->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 7050
// RVA: 0x348660
void __fastcall SetDriverFlagsTask::Begin(SetDriverFlagsTask *this, ActionContext *action_context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::UIMapBlip *m_pComponent; // rax
  const char *invokable; // rax
  UFG::SimObjectCVBase *v7; // rcx
  __int16 v8; // dx
  UFG::AiDriverComponent *ComponentOfTypeHK; // rdx
  UFG::qSafePointer<UFG::SimComponent,UFG::AiDriverComponent> *p_m_pAIDriverComponent; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::AiDriverComponent *v14; // rcx

  this->m_pActionContext = action_context;
  m_pPointer = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
      m_pComponent = (UFG::UIMapBlip *)m_pPointer->m_Components.p[44].m_pComponent;
    else
      m_pComponent = (UFG::UIMapBlip *)(m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                      ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                          m_pPointer,
                                          UFG::CharacterOccupantComponent::_TypeUID)
                                      : UFG::SimObject::GetComponentOfType(
                                          m_pPointer,
                                          UFG::CharacterOccupantComponent::_TypeUID));
    if ( m_pComponent )
    {
      invokable = SSInvokedMethod::get_invokable(m_pComponent);
      if ( invokable && (v7 = (UFG::SimObjectCVBase *)*((_QWORD *)invokable + 5)) != 0i64 )
      {
        v8 = v7->m_Flags;
        if ( (v8 & 0x4000) != 0 || v8 < 0 )
        {
          ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v7);
        }
        else if ( (v8 & 0x2000) != 0 || (v8 & 0x1000) != 0 )
        {
          ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          v7,
                                                          UFG::AiDriverComponent::_TypeUID);
        }
        else
        {
          ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                                          v7,
                                                          UFG::AiDriverComponent::_TypeUID);
        }
      }
      else
      {
        ComponentOfTypeHK = 0i64;
      }
      if ( ComponentOfTypeHK )
      {
        p_m_pAIDriverComponent = &this->m_pAIDriverComponent;
        if ( this->m_pAIDriverComponent.m_pPointer )
        {
          mPrev = p_m_pAIDriverComponent->mPrev;
          mNext = this->m_pAIDriverComponent.mNext;
          mPrev->mNext = mNext;
          mNext->mPrev = mPrev;
          p_m_pAIDriverComponent->mPrev = p_m_pAIDriverComponent;
          this->m_pAIDriverComponent.mNext = &this->m_pAIDriverComponent;
        }
        this->m_pAIDriverComponent.m_pPointer = ComponentOfTypeHK;
        v13 = ComponentOfTypeHK->m_SafePointerList.mNode.UFG::VehicleDriverInterface::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
        v13->mNext = p_m_pAIDriverComponent;
        p_m_pAIDriverComponent->mPrev = v13;
        this->m_pAIDriverComponent.mNext = &ComponentOfTypeHK->m_SafePointerList.mNode;
        ComponentOfTypeHK->m_SafePointerList.mNode.UFG::VehicleDriverInterface::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = p_m_pAIDriverComponent;
        v14 = (UFG::AiDriverComponent *)this->m_pAIDriverComponent.m_pPointer;
        this->m_PrevAvoidPeds = v14->m_bAvoidPeds;
        this->m_PrevAllowedToPass = v14->m_bAllowedToPass;
        this->m_PrevStayOffSidewalk = v14->m_bStayOffSidewalk;
        this->m_PrevRespectSpeedLimit = v14->m_bRespectSpeedLimit;
        UFG::AiDriverComponent::SetAvoidPeds(v14, LOBYTE(this->m_Track[1].vfptr) != 0);
        UFG::AiDriverComponent::SetAllowedToPass(
          (UFG::AiDriverComponent *)this->m_pAIDriverComponent.m_pPointer,
          BYTE1(this->m_Track[1].vfptr) != 0);
        UFG::AiDriverComponent::SetStayOffSidewalk(
          (UFG::AiDriverComponent *)this->m_pAIDriverComponent.m_pPointer,
          BYTE2(this->m_Track[1].vfptr) != 0);
        UFG::AiDriverComponent::SetRespectSpeedLimit(
          (UFG::AiDriverComponent *)this->m_pAIDriverComponent.m_pPointer,
          BYTE3(this->m_Track[1].vfptr) != 0);
      }
    }
  }
}

// File Line: 7084
// RVA: 0x355520
void __fastcall SetDriverFlagsTask::End(SetDriverFlagsTask *this)
{
  UFG::AiDriverComponent *m_pPointer; // rcx

  m_pPointer = (UFG::AiDriverComponent *)this->m_pAIDriverComponent.m_pPointer;
  if ( m_pPointer )
  {
    UFG::AiDriverComponent::SetAvoidPeds(m_pPointer, this->m_PrevAvoidPeds);
    UFG::AiDriverComponent::SetAllowedToPass(
      (UFG::AiDriverComponent *)this->m_pAIDriverComponent.m_pPointer,
      this->m_PrevAllowedToPass);
    UFG::AiDriverComponent::SetStayOffSidewalk(
      (UFG::AiDriverComponent *)this->m_pAIDriverComponent.m_pPointer,
      this->m_PrevStayOffSidewalk);
    UFG::AiDriverComponent::SetRespectSpeedLimit(
      (UFG::AiDriverComponent *)this->m_pAIDriverComponent.m_pPointer,
      this->m_PrevRespectSpeedLimit);
  }
}

// File Line: 7105
// RVA: 0x32CD60
void __fastcall AttackRightsSetTimeUntilNextAttackTask::AttackRightsSetTimeUntilNextAttackTask(
        AttackRightsSetTimeUntilNextAttackTask *this)
{
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<AttackRightsSetTimeUntilNextAttackTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&AttackRightsSetTimeUntilNextAttackTask::`vftable;
}

// File Line: 7126
// RVA: 0x38D320
char __fastcall AttackRightsSetTimeUntilNextAttackTask::Update(
        AttackRightsSetTimeUntilNextAttackTask *this,
        float timestep)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *v6; // rax
  UFG::SimObjectGame *v7; // r8
  __int16 v8; // cx
  UFG::SimComponent *v9; // rbx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  ITrack *m_Track; // rcx
  __int64 v12; // rsi
  float v13; // xmm7_4
  float mTimeBegin; // xmm6_4
  UFG::SimObject *v15; // rcx
  float v16; // xmm0_4

  m_pPointer = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 1;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    v6 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
       ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
       : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
    m_pComponent = v6;
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  if ( !m_pComponent )
    return 1;
  v7 = *(UFG::SimObjectGame **)(56i64
                              * *(unsigned __int8 *)(LOBYTE(this->m_Track[1].vfptr)
                                                   + *(_QWORD *)&m_pComponent[1].m_Flags
                                                   + 8i64)
                              + *(_QWORD *)&m_pComponent[1].m_TypeUID
                              + 40);
  if ( !v7 )
    return 1;
  v8 = v7->m_Flags;
  if ( (v8 & 0x4000) != 0 )
  {
    v9 = v7->m_Components.p[46].m_pComponent;
  }
  else
  {
    if ( v8 < 0 || (v8 & 0x2000) != 0 || (v8 & 0x1000) != 0 )
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::AttackRightsComponent::_TypeUID);
    else
      ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v7, UFG::AttackRightsComponent::_TypeUID);
    v9 = ComponentOfTypeHK;
  }
  if ( !v9 )
    return 1;
  m_Track = this->m_Track;
  v12 = BYTE4(m_Track[1].mResourceOwner);
  m_Track = (ITrack *)((char *)m_Track + 72);
  v13 = *(&m_Track[-1].mMasterRate.value + 1);
  mTimeBegin = m_Track[-1].mTimeBegin;
  ActionPath::GetString_DBG((ActionPath *)m_Track);
  v15 = this->m_pActionContext->mSimObject.m_pPointer;
  if ( v15 )
    UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v15->m_Name);
  v16 = mTimeBegin;
  if ( mTimeBegin > v13 )
  {
    v16 = UFG::qRandom(mTimeBegin - v13, (unsigned int *)&UFG::qDefaultSeed) + v13;
    if ( v16 <= v13 )
      v16 = v13;
    if ( v16 >= mTimeBegin )
      v16 = mTimeBegin;
  }
  if ( !LOBYTE(v9[149].m_BoundComponentHandles.mNode.mPrev) )
    *((float *)&v9[148].m_BoundComponentHandles.mNode.mPrev + v12 + 1) = v16;
  return 1;
}

// File Line: 7160
// RVA: 0x32C860
void __fastcall AttackRightsClearPreviousBestAttackerTask::AttackRightsClearPreviousBestAttackerTask(
        AttackRightsClearPreviousBestAttackerTask *this)
{
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<AttackRightsClearPreviousBestAttackerTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&AttackRightsClearPreviousBestAttackerTask::`vftable;
  this->m_pActionContext = 0i64;
}

// File Line: 7183
// RVA: 0x38CC20
char __fastcall AttackRightsClearPreviousBestAttackerTask::Update(
        AttackRightsClearPreviousBestAttackerTask *this,
        float timestep)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *v6; // rax
  UFG::SimObjectGame *v7; // r8
  __int16 v8; // cx
  UFG::AttackRightsComponent *v9; // rcx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      v6 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
         ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
         : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = v6;
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    if ( m_pComponent )
    {
      v7 = *(UFG::SimObjectGame **)(56i64
                                  * *(unsigned __int8 *)(LOBYTE(this->m_Track[1].vfptr)
                                                       + *(_QWORD *)&m_pComponent[1].m_Flags
                                                       + 8i64)
                                  + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                  + 40);
      if ( v7 )
      {
        v8 = v7->m_Flags;
        if ( (v8 & 0x4000) != 0 )
        {
          v9 = (UFG::AttackRightsComponent *)v7->m_Components.p[46].m_pComponent;
        }
        else
        {
          if ( v8 < 0 || (v8 & 0x2000) != 0 || (v8 & 0x1000) != 0 )
            ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::AttackRightsComponent::_TypeUID);
          else
            ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v7, UFG::AttackRightsComponent::_TypeUID);
          v9 = (UFG::AttackRightsComponent *)ComponentOfTypeHK;
        }
        if ( v9 )
          UFG::AttackRightsComponent::ClearPreviousBestAttacker(v9, BYTE1(this->m_Track[1].vfptr));
      }
    }
  }
  return 1;
}

// File Line: 7211
// RVA: 0x32CC10
void __fastcall AttackRightsReSortListTask::AttackRightsReSortListTask(AttackRightsReSortListTask *this)
{
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<AttackRightsReSortListTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&AttackRightsReSortListTask::`vftable;
  this->m_pActionContext = 0i64;
}

// File Line: 7234
// RVA: 0x38D1E0
char __fastcall AttackRightsReSortListTask::Update(AttackRightsReSortListTask *this, float timestep)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *v6; // rax
  UFG::SimObjectGame *v7; // r8
  __int16 v8; // cx
  UFG::AttackRightsComponent *v9; // rcx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      v6 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
         ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
         : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = v6;
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    if ( m_pComponent )
    {
      v7 = *(UFG::SimObjectGame **)(56i64
                                  * *(unsigned __int8 *)(LOBYTE(this->m_Track[1].vfptr)
                                                       + *(_QWORD *)&m_pComponent[1].m_Flags
                                                       + 8i64)
                                  + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                  + 40);
      if ( v7 )
      {
        v8 = v7->m_Flags;
        if ( (v8 & 0x4000) != 0 )
        {
          v9 = (UFG::AttackRightsComponent *)v7->m_Components.p[46].m_pComponent;
        }
        else
        {
          if ( v8 < 0 || (v8 & 0x2000) != 0 || (v8 & 0x1000) != 0 )
            ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::AttackRightsComponent::_TypeUID);
          else
            ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v7, UFG::AttackRightsComponent::_TypeUID);
          v9 = (UFG::AttackRightsComponent *)ComponentOfTypeHK;
        }
        if ( v9 )
          UFG::AttackRightsComponent::SortAttackSlots(v9, (UFG::eAttackType)BYTE1(this->m_Track[1].vfptr));
      }
    }
  }
  return 1;
}

// File Line: 7262
// RVA: 0x32C7C0
void __fastcall AttackRightsCancelAnyIncomingAttackTask::AttackRightsCancelAnyIncomingAttackTask(
        AttackRightsCancelAnyIncomingAttackTask *this)
{
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<AttackRightsCancelAnyIncomingAttackTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&AttackRightsCancelAnyIncomingAttackTask::`vftable;
  this->m_pActionContext = 0i64;
}

// File Line: 7285
// RVA: 0x38CAA0
char __fastcall AttackRightsCancelAnyIncomingAttackTask::Update(
        AttackRightsCancelAnyIncomingAttackTask *this,
        float timestep)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *v6; // rax
  UFG::SimObjectGame *v7; // r8
  __int16 v8; // cx
  UFG::AttackRightsComponent *v9; // rcx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  ITrack *m_Track; // r9
  __int64 v12; // r8
  UFG::HasAttackRequestNode *v13; // rax
  UFG::SimComponent *v14; // rax

  m_pPointer = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      v6 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
         ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
         : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = v6;
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    if ( m_pComponent )
    {
      v7 = *(UFG::SimObjectGame **)(56i64
                                  * *(unsigned __int8 *)(LOBYTE(this->m_Track[1].vfptr)
                                                       + *(_QWORD *)&m_pComponent[1].m_Flags
                                                       + 8i64)
                                  + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                  + 40);
      if ( v7 )
      {
        v8 = v7->m_Flags;
        if ( (v8 & 0x4000) != 0 )
        {
          v9 = (UFG::AttackRightsComponent *)v7->m_Components.p[46].m_pComponent;
        }
        else
        {
          if ( v8 < 0 || (v8 & 0x2000) != 0 || (v8 & 0x1000) != 0 )
            ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::AttackRightsComponent::_TypeUID);
          else
            ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v7, UFG::AttackRightsComponent::_TypeUID);
          v9 = (UFG::AttackRightsComponent *)ComponentOfTypeHK;
        }
        if ( v9 )
        {
          m_Track = this->m_Track;
          v12 = BYTE1(m_Track[1].vfptr);
          v13 = v9->m_pLastAttackRequest[BYTE1(m_Track[1].vfptr)].m_pPointer;
          if ( v13 )
          {
            v14 = v13->m_pOwner.m_pPointer;
            if ( v14 )
              *((float *)&v14[1].m_BoundComponentHandles.mNode.mPrev + BYTE1(m_Track[1].vfptr)) = UFG::Metrics::msInstance.mSimTime_Temp
                                                                                                + *((float *)&m_Track[1].vfptr
                                                                                                  + 1);
            UFG::AttackRightsComponent::FinishedAttacking(v9, v9->m_pLastAttackRequest[v12].m_pPointer);
          }
        }
      }
    }
  }
  return 1;
}

// File Line: 7314
// RVA: 0x32CB70
void __fastcall AttackRightsFormationManagerFreezeRangeSwitchesTask::AttackRightsFormationManagerFreezeRangeSwitchesTask(
        AttackRightsFormationManagerFreezeRangeSwitchesTask *this)
{
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<AttackRightsFormationManagerFreezeRangeSwitchesTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&AttackRightsFormationManagerFreezeRangeSwitchesTask::`vftable;
  this->m_pActionContext = 0i64;
}

// File Line: 7328
// RVA: 0x343F10
void __fastcall AttackRightsFormationManagerFreezeRangeSwitchesTask::Begin(
        AttackRightsFormationManagerFreezeRangeSwitchesTask *this,
        ActionContext *action_context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectGame *v7; // rcx
  __int16 v8; // dx
  UFG::SimComponent *ComponentOfType; // rax

  this->m_pActionContext = action_context;
  m_pPointer = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
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
      v7 = *(UFG::SimObjectGame **)(56i64
                                  * *(unsigned __int8 *)(LOBYTE(this->m_Track[1].vfptr)
                                                       + *(_QWORD *)&m_pComponent[1].m_Flags
                                                       + 8i64)
                                  + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                  + 40);
      if ( v7 )
      {
        v8 = v7->m_Flags;
        if ( (v8 & 0x4000) != 0 || v8 < 0 || (v8 & 0x2000) != 0 || (v8 & 0x1000) != 0 )
          ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::FormationManagerComponent::_TypeUID);
        else
          ComponentOfType = UFG::SimObject::GetComponentOfType(v7, UFG::FormationManagerComponent::_TypeUID);
        if ( ComponentOfType )
          BYTE3(ComponentOfType[109].m_BoundComponentHandles.mNode.mNext) = 1;
      }
    }
  }
}

// File Line: 7349
// RVA: 0x354E00
void __fastcall AttackRightsFormationManagerFreezeRangeSwitchesTask::End(
        AttackRightsFormationManagerFreezeRangeSwitchesTask *this)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectGame *v6; // rcx
  __int16 v7; // dx
  UFG::SimComponent *ComponentOfType; // rax

  m_pPointer = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
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
      v6 = *(UFG::SimObjectGame **)(56i64
                                  * *(unsigned __int8 *)(LOBYTE(this->m_Track[1].vfptr)
                                                       + *(_QWORD *)&m_pComponent[1].m_Flags
                                                       + 8i64)
                                  + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                  + 40);
      if ( v6 )
      {
        v7 = v6->m_Flags;
        if ( (v7 & 0x4000) != 0 || v7 < 0 || (v7 & 0x2000) != 0 || (v7 & 0x1000) != 0 )
          ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::FormationManagerComponent::_TypeUID);
        else
          ComponentOfType = UFG::SimObject::GetComponentOfType(v6, UFG::FormationManagerComponent::_TypeUID);
        if ( ComponentOfType )
          BYTE3(ComponentOfType[109].m_BoundComponentHandles.mNode.mNext) = 0;
      }
    }
  }
}

// File Line: 7372
// RVA: 0x32D450
void __fastcall CombatRegionMoveToTask::CombatRegionMoveToTask(CombatRegionMoveToTask *this)
{
  float y; // xmm1_4
  float z; // xmm2_4

  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<CombatRegionMoveToTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&CombatRegionMoveToTask::`vftable;
  this->m_bFoundDestination = 0;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->m_vDestination.x = UFG::qVector3::msZero.x;
  this->m_vDestination.y = y;
  this->m_vDestination.z = z;
  *(_WORD *)&this->m_bTraversalStarted = 0;
}

// File Line: 7400
// RVA: 0x38DC70
bool __fastcall CombatRegionMoveToTask::Update(CombatRegionMoveToTask *this, float timestep)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::NavComponent *m_pComponent; // r14
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectCVBase *v7; // rcx
  UFG::ActiveAIEntityComponent *v8; // rsi
  __int16 v9; // dx
  UFG::ActiveAIEntityComponent *ComponentOfType; // rax
  UFG::SimObjectGame *v11; // rcx
  __m128 *v12; // rdi
  __int16 v13; // dx
  UFG::SimComponent *v14; // rax
  float v15; // xmm1_4
  float v16; // xmm2_4
  UFG::CombatRegion *v17; // rax
  UFG::DaemonManager *v18; // rax
  int v19; // xmm2_4
  int v20; // xmm1_4
  float v21; // xmm0_4
  bool result; // al
  UFG::DaemonQueryOutput output; // [rsp+30h] [rbp-A8h] BYREF
  char v24; // [rsp+48h] [rbp-90h]
  __m128 v25; // [rsp+50h] [rbp-88h]
  __int64 v26; // [rsp+60h] [rbp-78h]
  UFG::DaemonQueryInput input; // [rsp+68h] [rbp-70h] BYREF
  __int64 (__fastcall **v28)(_QWORD); // [rsp+88h] [rbp-50h]
  UFG::qVector3 v29; // [rsp+90h] [rbp-48h]
  char v30; // [rsp+A0h] [rbp-38h]
  __m128 m_quad; // [rsp+A8h] [rbp-30h]
  __int64 v32; // [rsp+B8h] [rbp-20h]
  UFG::RegionComponent *mpRegion; // [rsp+C8h] [rbp-10h]
  __int64 v34; // [rsp+D0h] [rbp-8h]
  int v35; // [rsp+D8h] [rbp+0h]
  __int64 v36; // [rsp+E8h] [rbp+10h]

  v36 = -2i64;
  m_pPointer = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::NavComponent *)m_pPointer->m_Components.p[36].m_pComponent;
    }
    else
    {
      if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::NavComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::NavComponent::_TypeUID);
      m_pComponent = (UFG::NavComponent *)ComponentOfTypeHK;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  if ( this->m_bFoundDestination )
    goto LABEL_48;
  v7 = (UFG::SimObjectCVBase *)this->m_pActionContext->mSimObject.m_pPointer;
  if ( v7 )
  {
    v9 = v7->m_Flags;
    if ( (v9 & 0x4000) != 0 || v9 < 0 )
    {
      ComponentOfType = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v7);
    }
    else if ( (v9 & 0x2000) != 0 || (v9 & 0x1000) != 0 )
    {
      ComponentOfType = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          v7,
                                                          UFG::ActiveAIEntityComponent::_TypeUID);
    }
    else
    {
      ComponentOfType = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                          v7,
                                                          UFG::ActiveAIEntityComponent::_TypeUID);
    }
    v8 = ComponentOfType;
  }
  else
  {
    v8 = 0i64;
  }
  v11 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
  if ( v11 )
  {
    v13 = v11->m_Flags;
    if ( (v13 & 0x4000) != 0 )
    {
      v12 = (__m128 *)v11->m_Components.p[36].m_pComponent;
    }
    else
    {
      if ( v13 < 0 || (v13 & 0x2000) != 0 || (v13 & 0x1000) != 0 )
        v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::NavComponent::_TypeUID);
      else
        v14 = UFG::SimObject::GetComponentOfType(v11, UFG::NavComponent::_TypeUID);
      v12 = (__m128 *)v14;
    }
  }
  else
  {
    v12 = 0i64;
  }
  input.m_pOutput = 0i64;
  input.vfptr = (UFG::DaemonQueryInputVtbl *)&UFG::FindPathToRegionImmediateQuery::`vftable;
  v29 = UFG::qVector3::msZero;
  v28 = &UFG::HavokNavPosition::`vftable;
  v30 = 0;
  m_quad = hkvZero_13.m_quad;
  v32 = -1i64;
  v34 = 0i64;
  v35 = -1;
  output.m_id = DaemonType_Navigation;
  *(_QWORD *)&output.m_internalType = 2i64;
  output.vfptr = (UFG::DaemonQueryOutputVtbl *)&UFG::FindPathToRegionOutput::`vftable;
  *(float *)&v26 = UFG::qVector3::msZero.z;
  v25.m128_u64[0] = (unsigned __int64)&UFG::HavokNavPosition::`vftable;
  LOBYTE(input.vfptr) = 0;
  *(hkVector4f *)&input.m_daemonType = (hkVector4f)hkvZero_13.m_quad;
  v25.m128_u64[1] = -1i64;
  v15 = v12[5].m128_f32[3];
  v16 = v12[6].m128_f32[0];
  LODWORD(v29.x) = v12[5].m128_i32[2];
  v29.y = v15;
  v29.z = v16;
  if ( !v12[6].m128_i8[8] )
  {
    v30 = 0;
LABEL_46:
    result = 1;
    goto LABEL_47;
  }
  v30 = v12[6].m128_i8[8];
  m_quad = v12[7];
  v32 = v12[8].m128_i64[0];
  if ( !UFG::HavokAIUtilGame::IsValidKey(v32, HIDWORD(v32)) || (_DWORD)v32 == -1 || HIDWORD(v32) == -1 )
    goto LABEL_46;
  v17 = v8->m_pCombatRegion.m_pPointer;
  if ( !v17 )
  {
LABEL_43:
    result = 0;
LABEL_47:
    output.vfptr = (UFG::DaemonQueryOutputVtbl *)&UFG::DaemonQueryOutput::`vftable;
    input.vfptr = (UFG::DaemonQueryInputVtbl *)&UFG::DaemonQueryInput::`vftable;
    return result;
  }
  mpRegion = v17->mpRegion;
  v34 = (__int64)&v12[11].m128_i64[1] + 4;
  v18 = UFG::DaemonManager::Instance();
  UFG::DaemonManager::SubmitQuery(v18, &input, &output);
  if ( output.m_status != Status_Completed )
  {
    if ( CombatRegionMoveToTask::SetDestinationFromRegionCenter(this, v8->m_pCombatRegion.m_pPointer) )
      goto LABEL_44;
    UFG::qPrintf(
      "0x%8x: CombatRegionMoveToTask::Update(): Could not get combat region center destination.\n",
      this->m_pActionContext->mSimObject.m_pPointer);
    goto LABEL_43;
  }
  this->m_bFoundDestination = 1;
  v19 = v25.m128_i32[2];
  LODWORD(this->m_vDestination.x) = v25.m128_i32[2];
  v20 = v25.m128_i32[3];
  LODWORD(this->m_vDestination.y) = v25.m128_i32[3];
  v21 = *(float *)&v26;
  LODWORD(this->m_vDestination.z) = v26;
  LODWORD(v8->m_vCombatRegionMoveToVec.x) = v19;
  LODWORD(v8->m_vCombatRegionMoveToVec.y) = v20;
  v8->m_vCombatRegionMoveToVec.z = v21;
LABEL_44:
  output.vfptr = (UFG::DaemonQueryOutputVtbl *)&UFG::DaemonQueryOutput::`vftable;
  input.vfptr = (UFG::DaemonQueryInputVtbl *)&UFG::DaemonQueryInput::`vftable;
LABEL_48:
  if ( !this->m_bFoundDestination )
    return 0;
  output.m_id = LODWORD(this->m_vDestination.x);
  output.m_internalType = LODWORD(this->m_vDestination.y);
  output.m_status = LODWORD(this->m_vDestination.z);
  output.vfptr = (UFG::DaemonQueryOutputVtbl *)&UFG::HavokNavPosition::`vftable;
  v24 = 0;
  v26 = -1i64;
  v25 = _mm_unpacklo_ps(
          _mm_unpacklo_ps((__m128)(unsigned int)output.m_id, (__m128)(unsigned int)output.m_status),
          _mm_unpacklo_ps((__m128)output.m_internalType, (__m128)(unsigned int)FLOAT_1_0));
  UFG::NavComponent::AddGoalPoint(
    m_pComponent,
    (UFG::HavokNavPosition *)&output,
    AiGoal_Replace,
    sNaturalMovementSpeeds[BYTE1(this->m_Track[1].vfptr)],
    0.30000001);
  return !UFG::NavComponent::IsAtDestination(m_pComponent);
}

// File Line: 7494
// RVA: 0x3860C0
bool __fastcall CombatRegionMoveToTask::SetDestinationFromRegionCenter(
        CombatRegionMoveToTask *this,
        UFG::CombatRegion *pRegion)
{
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm0_4
  UFG::SimObject *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::ActiveAIEntityComponent *ComponentOfType; // rax
  unsigned int v9; // edx
  bool v10; // zf
  float v11; // xmm0_4
  float v12; // xmm1_4
  bool result; // al
  UFG::qVector3 out; // [rsp+30h] [rbp-28h] BYREF
  UFG::qVector3 pPos; // [rsp+40h] [rbp-18h] BYREF

  UFG::RegionComponent::GetCenter(pRegion->mpRegion, &pPos);
  if ( UFG::PlaceOnGround(&out, &pPos, 0.0, 3.0, 1.0) )
  {
    x = out.x;
    y = out.y;
    this->m_bFoundDestination = 1;
    this->m_vDestination.x = x;
    z = out.z;
    this->m_vDestination.y = y;
    this->m_vDestination.z = z;
    m_pPointer = this->m_pActionContext->mSimObject.m_pPointer;
    if ( !m_pPointer )
    {
LABEL_12:
      v11 = this->m_vDestination.y;
      v12 = this->m_vDestination.z;
      *(float *)&m_pPointer[10].mNode.mParent = this->m_vDestination.x;
      result = 1;
      *((float *)&m_pPointer[10].mNode.mParent + 1) = v11;
      *(float *)m_pPointer[10].mNode.mChild = v12;
      return result;
    }
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfType = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>((UFG::SimObjectCVBase *)m_pPointer);
    }
    else
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        v9 = UFG::ActiveAIEntityComponent::_TypeUID;
      }
      else
      {
        v10 = (m_Flags & 0x1000) == 0;
        v9 = UFG::ActiveAIEntityComponent::_TypeUID;
        if ( v10 )
        {
          ComponentOfType = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                              m_pPointer,
                                                              UFG::ActiveAIEntityComponent::_TypeUID);
          goto LABEL_11;
        }
      }
      ComponentOfType = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          (UFG::SimObjectGame *)m_pPointer,
                                                          v9);
    }
LABEL_11:
    m_pPointer = (UFG::SimObject *)ComponentOfType;
    goto LABEL_12;
  }
  return 0;
}

// File Line: 7525
// RVA: 0x348BC0
void __fastcall UpdateHijackableVehicleTargetTask::Begin(
        UpdateHijackableVehicleTargetTask *this,
        ActionContext *action_context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::TargetingSystemPedNPCCombatantComponent *ComponentOfTypeHK; // rax

  this->m_pActionContext = action_context;
  m_pPointer = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedNPCCombatantComponent>(m_pPointer);
    }
    else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::TargetingSystemPedNPCCombatantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                            m_pPointer,
                                                                            UFG::TargetingSystemPedNPCCombatantComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::TargetingSystemPedNPCCombatantComponent *)UFG::SimObject::GetComponentOfType(
                                                                            m_pPointer,
                                                                            UFG::TargetingSystemPedNPCCombatantComponent::_TypeUID);
    }
    if ( ComponentOfTypeHK )
      UFG::TargetingSystemPedNPCCombatantComponent::UpdateHijackableVehicleTarget(ComponentOfTypeHK);
  }
}

// File Line: 7568
// RVA: 0x330740
void __fastcall MoveToBetterAttackPositionTask::MoveToBetterAttackPositionTask(MoveToBetterAttackPositionTask *this)
{
  float y; // xmm1_4
  float z; // xmm2_4

  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<MoveToBetterAttackPositionTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&MoveToBetterAttackPositionTask::`vftable;
  this->m_pTargetSimObject.mPrev = &this->m_pTargetSimObject;
  this->m_pTargetSimObject.mNext = &this->m_pTargetSimObject;
  this->m_pTargetSimObject.m_pPointer = 0i64;
  this->m_pCombatRegion.mPrev = &this->m_pCombatRegion;
  this->m_pCombatRegion.mNext = &this->m_pCombatRegion;
  this->m_pCombatRegion.m_pPointer = 0i64;
  this->m_npBestPosition.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::NavPositionBase::`vftable;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->m_npBestPosition.m_vPosition.x = UFG::qVector3::msZero.x;
  this->m_npBestPosition.m_vPosition.y = y;
  this->m_npBestPosition.m_vPosition.z = z;
  this->m_npBestPosition.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
  this->m_npBestPosition.m_bValid = 0;
  this->m_npBestPosition.m_hkvMeshPosition = (hkVector4f)hkvZero_13.m_quad;
  *(_QWORD *)&this->m_npBestPosition.m_packedKey = -1i64;
}

// File Line: 7575
// RVA: 0x339400
void __fastcall MoveToBetterAttackPositionTask::~MoveToBetterAttackPositionTask(MoveToBetterAttackPositionTask *this)
{
  UFG::qSafePointer<UFG::CombatRegion,UFG::CombatRegion> *p_m_pCombatRegion; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_pTargetSimObject; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<ITask,ITask> *v12; // rcx
  UFG::qNode<ITask,ITask> *v13; // rax

  this->vfptr = (ITaskVtbl *)&MoveToBetterAttackPositionTask::`vftable;
  p_m_pCombatRegion = &this->m_pCombatRegion;
  if ( this->m_pCombatRegion.m_pPointer )
  {
    mPrev = p_m_pCombatRegion->mPrev;
    mNext = p_m_pCombatRegion->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pCombatRegion->mPrev = p_m_pCombatRegion;
    p_m_pCombatRegion->mNext = p_m_pCombatRegion;
  }
  p_m_pCombatRegion->m_pPointer = 0i64;
  v5 = p_m_pCombatRegion->mPrev;
  v6 = p_m_pCombatRegion->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_m_pCombatRegion->mPrev = p_m_pCombatRegion;
  p_m_pCombatRegion->mNext = p_m_pCombatRegion;
  p_m_pTargetSimObject = &this->m_pTargetSimObject;
  if ( this->m_pTargetSimObject.m_pPointer )
  {
    v8 = p_m_pTargetSimObject->mPrev;
    v9 = this->m_pTargetSimObject.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    p_m_pTargetSimObject->mPrev = p_m_pTargetSimObject;
    this->m_pTargetSimObject.mNext = &this->m_pTargetSimObject;
  }
  this->m_pTargetSimObject.m_pPointer = 0i64;
  v10 = p_m_pTargetSimObject->mPrev;
  v11 = this->m_pTargetSimObject.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  p_m_pTargetSimObject->mPrev = p_m_pTargetSimObject;
  this->m_pTargetSimObject.mNext = &this->m_pTargetSimObject;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v12 = this->mPrev;
  v13 = this->mNext;
  v12->mNext = v13;
  v13->mPrev = v12;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 7582
// RVA: 0x355A20
float __fastcall MoveToBetterAttackPositionTask::EvaluatePosition(
        MoveToBetterAttackPositionTask *this,
        UFG::qVector4 *vPosition,
        UFG::qVector3 *vTargetPosition,
        float fCurrentDistToTarget)
{
  __m128 y_low; // xmm0
  float v8; // xmm6_4
  UFG::SimObjectCVBase *m_pPointer; // rcx
  float v11; // xmm7_4
  __int16 m_Flags; // dx
  UFG::TargetingSystemPedBaseComponent *v13; // rax
  UFG::SimObjectGame *v14; // rcx
  __int16 v15; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  CAkScheduledItem *SimObjectWeaponPropertiesComponent; // rax
  float *v18; // rdx
  float v19; // xmm2_4
  float v20; // xmm3_4
  float v21; // xmm4_4
  float v22; // xmm3_4
  float v23; // xmm2_4
  float v24; // xmm1_4
  UFG::SimObject *v25; // rbx
  UFG::qVector3 rayStart; // [rsp+20h] [rbp-128h] BYREF
  UFG::RayCastData data; // [rsp+30h] [rbp-118h] BYREF
  UFG::SimObject *ray_hit_object; // [rsp+150h] [rbp+8h] BYREF

  y_low = (__m128)LODWORD(vPosition->y);
  v8 = 0.0;
  m_pPointer = (UFG::SimObjectCVBase *)this->m_pActionContext->mSimObject.m_pPointer;
  y_low.m128_f32[0] = (float)((float)(y_low.m128_f32[0] - vTargetPosition->y)
                            * (float)(y_low.m128_f32[0] - vTargetPosition->y))
                    + (float)((float)(vPosition->x - vTargetPosition->x) * (float)(vPosition->x - vTargetPosition->x));
  LODWORD(v11) = _mm_sqrt_ps(y_low).m128_u32[0];
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
      v13 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedBaseComponent>(m_pPointer);
    else
      v13 = (UFG::TargetingSystemPedBaseComponent *)((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                                   ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                       m_pPointer,
                                                       UFG::TargetingSystemPedBaseComponent::_TypeUID)
                                                   : UFG::SimObject::GetComponentOfType(
                                                       m_pPointer,
                                                       UFG::TargetingSystemPedBaseComponent::_TypeUID));
    if ( v13 )
    {
      v14 = (UFG::SimObjectGame *)v13->m_pTargets[(unsigned __int8)v13->m_pTargetingMap->m_Map.p[17]].m_pTarget.m_pPointer;
      if ( v14 )
      {
        v15 = v14->m_Flags;
        if ( (v15 & 0x4000) != 0 || v15 < 0 || (v15 & 0x2000) != 0 || (v15 & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v14, UFG::GunComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v14, UFG::GunComponent::_TypeUID);
        if ( ComponentOfTypeHK )
        {
          SimObjectWeaponPropertiesComponent = UFG::GunComponent::GetSimObjectWeaponPropertiesComponent((CAkChainCtx *)ComponentOfTypeHK);
          v18 = *(float **)(*(_QWORD *)&SimObjectWeaponPropertiesComponent[2].m_cmdStop.iRelativeTime
                          + 8i64 * (unsigned int)SimObjectWeaponPropertiesComponent[2].m_cmdPlay.fadeParams.iFadeOffset
                          + 8);
          v19 = v18[114];
          v20 = v18[112];
          v21 = v18[113];
          if ( v11 >= v19 )
          {
            if ( (float)((float)(v21 - v11) / (float)(v21 - v19)) > 0.0 )
              v8 = (float)(v21 - v11) / (float)(v21 - v19);
          }
          else if ( (float)((float)(v11 - v20) / (float)(v19 - v20)) > 0.0 )
          {
            v8 = (float)(v11 - v20) / (float)(v19 - v20);
          }
          if ( fCurrentDistToTarget < v20 && v11 > fCurrentDistToTarget
            || fCurrentDistToTarget > v21 && v11 < fCurrentDistToTarget )
          {
            v8 = v8 + 1.0;
          }
        }
      }
    }
  }
  data.mOutput.m_hitFraction = 1.0;
  v22 = (float)(UFG::qVector3::msDirUp.x * 1.5) + vPosition->x;
  v23 = (float)(UFG::qVector3::msDirUp.y * 1.5) + vPosition->y;
  ray_hit_object = 0i64;
  data.mInput.m_enableShapeCollectionFilter.m_bool = 0;
  data.mInput.m_filterInfo = 0;
  data.mInput.m_userData = 0i64;
  data.mOutput.m_extraInfo = -1;
  data.mOutput.m_shapeKeyIndex = 0;
  v24 = (float)(UFG::qVector3::msDirUp.z * 1.5) + vPosition->z;
  rayStart.x = v22;
  rayStart.y = v23;
  v25 = this->m_pTargetSimObject.m_pPointer;
  data.mOutput.m_shapeKeys[0] = -1;
  data.mOutput.m_rootCollidable = 0i64;
  rayStart.z = v24;
  data.mDebugName = 0i64;
  data.mCollisionModelName.mUID = -1;
  UFG::RayCastData::Init(&data, &rayStart, vTargetPosition, 0xCu);
  UFG::BasePhysicsSystem::CastRay(UFG::BasePhysicsSystem::mInstance, &data);
  if ( UFG::TargetIsVisible(&data, v25, &ray_hit_object) )
    v8 = v8 + 1.0;
  return UFG::qRandom(0.1, (unsigned int *)&UFG::qDefaultSeed) + v8;
}

// File Line: 7653
// RVA: 0x357290
void __fastcall MoveToBetterAttackPositionTask::FindNewPosition(
        MoveToBetterAttackPositionTask *this,
        UFG::NavComponent *pNavComponent,
        UFG::qVector3 *vTargetPosition)
{
  int v3; // edi
  UFG::SimObject *m_pPointer; // r14
  float v8; // xmm14_4
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // r14
  float x; // xmm3_4
  float y; // xmm2_4
  float v12; // xmm0_4
  __m128 y_low; // xmm1
  float v14; // xmm13_4
  float v15; // xmm10_4
  float v16; // xmm0_4
  ITrack *m_Track; // rax
  float v18; // xmm6_4
  float v19; // xmm8_4
  float v20; // xmm7_4
  float v21; // xmm6_4
  float v22; // xmm0_4
  UFG::CombatRegion *v23; // rcx
  float v24; // xmm9_4
  float v25; // xmm3_4
  float v26; // xmm8_4
  float v27; // xmm7_4
  float v28; // xmm0_4
  float v29; // xmm6_4
  float v30; // xmm7_4
  float v31; // xmm1_4
  float v32; // xmm8_4
  float v33; // xmm9_4
  float v34; // xmm0_4
  float v35; // xmm9_4
  float v36; // xmm3_4
  hkVector4f v37; // xmm0
  unsigned int m_packedKey; // eax
  float v39; // xmm0_4
  bool m_bValid; // al
  float v41; // xmm0_4
  hkVector4f v42; // xmm0
  unsigned int m_aiMeshUid; // eax
  UFG::qVector4 vPosition; // [rsp+20h] [rbp-C8h] BYREF
  UFG::qVector4 v45; // [rsp+30h] [rbp-B8h] BYREF
  UFG::HavokNavPosition positionEnd; // [rsp+40h] [rbp-A8h] BYREF

  v3 = 0;
  m_pPointer = this->m_pActionContext->mSimObject.m_pPointer;
  v8 = 1.0 / (float)SHIDWORD(this->m_Track[1].mResourceOwner);
  if ( m_pPointer )
    m_pTransformNodeComponent = m_pPointer->m_pTransformNodeComponent;
  else
    m_pTransformNodeComponent = 0i64;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  x = m_pTransformNodeComponent->mWorldTransform.v3.x;
  y = m_pTransformNodeComponent->mWorldTransform.v3.y;
  v12 = vTargetPosition->x;
  vPosition.w = 1.0;
  y_low = (__m128)LODWORD(vTargetPosition->y);
  vPosition.x = x;
  vPosition.y = y;
  y_low.m128_f32[0] = (float)((float)(y_low.m128_f32[0] - y) * (float)(y_low.m128_f32[0] - y))
                    + (float)((float)(v12 - x) * (float)(v12 - x));
  LODWORD(v14) = _mm_sqrt_ps(y_low).m128_u32[0];
  vPosition.z = m_pTransformNodeComponent->mWorldTransform.v3.z;
  v15 = MoveToBetterAttackPositionTask::EvaluatePosition(this, &vPosition, vTargetPosition, v14) - 0.5;
  if ( SHIDWORD(this->m_Track[1].mResourceOwner) > 0 )
  {
    do
    {
      v16 = UFG::qRandom(v8, (unsigned int *)&UFG::qDefaultSeed);
      m_Track = this->m_Track;
      v18 = *((float *)&m_Track[1].vfptr + 1);
      v19 = (float)(v16 + (float)((float)v3 * v8)) * 6.2831855;
      v20 = UFG::qRandom(*(float *)&m_Track[1].mResourceOwner - v18, (unsigned int *)&UFG::qDefaultSeed) + v18;
      v21 = sinf(v19) * v20;
      v22 = cosf(v19);
      v23 = this->m_pCombatRegion.m_pPointer;
      v24 = v22 * v20;
      v25 = (float)(v22 * v20) * m_pTransformNodeComponent->mWorldTransform.v1.w;
      v26 = (float)(v21 * m_pTransformNodeComponent->mWorldTransform.v0.y)
          + (float)((float)(v22 * v20) * m_pTransformNodeComponent->mWorldTransform.v1.y);
      v27 = (float)((float)(v22 * v20) * m_pTransformNodeComponent->mWorldTransform.v1.x)
          + (float)(v21 * m_pTransformNodeComponent->mWorldTransform.v0.x);
      v28 = v21 * m_pTransformNodeComponent->mWorldTransform.v0.z;
      v29 = v21 * m_pTransformNodeComponent->mWorldTransform.v0.w;
      v30 = (float)(v27 + (float)(m_pTransformNodeComponent->mWorldTransform.v2.x * 0.0))
          + m_pTransformNodeComponent->mWorldTransform.v3.x;
      v31 = m_pTransformNodeComponent->mWorldTransform.v2.z * 0.0;
      v32 = (float)(v26 + (float)(m_pTransformNodeComponent->mWorldTransform.v2.y * 0.0))
          + m_pTransformNodeComponent->mWorldTransform.v3.y;
      v33 = (float)(v24 * m_pTransformNodeComponent->mWorldTransform.v1.z) + v28;
      v34 = m_pTransformNodeComponent->mWorldTransform.v2.w * 0.0;
      v45.x = v30;
      v35 = (float)(v33 + v31) + m_pTransformNodeComponent->mWorldTransform.v3.z;
      v45.y = v32;
      v36 = (float)((float)(v25 + v29) + v34) + m_pTransformNodeComponent->mWorldTransform.v3.w;
      v45.z = v35;
      v45.w = v36;
      if ( !v23
        || (vPosition.x = v30,
            vPosition.y = v32,
            vPosition.z = v35,
            UFG::CombatRegion::IsHitPoint(v23, (UFG::qVector3 *)&vPosition)) )
      {
        v37.m_quad = (__m128)pNavComponent->m_navPosition.m_hkvMeshPosition;
        m_packedKey = pNavComponent->m_navPosition.m_packedKey;
        positionEnd.m_vPosition.x = v30;
        positionEnd.m_vPosition.y = v32;
        positionEnd.m_vPosition.z = v35;
        positionEnd.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
        positionEnd.m_aiMeshUid = -1;
        positionEnd.m_bValid = 0;
        positionEnd.m_hkvMeshPosition = (hkVector4f)v37.m_quad;
        positionEnd.m_packedKey = m_packedKey;
        UFG::HavokNavPosition::Validate(
          &positionEnd,
          COERCE_DOUBLE((unsigned __int64)LODWORD(FLOAT_0_1)),
          COERCE_DOUBLE((unsigned __int64)(unsigned int)FLOAT_1_0),
          0.0);
        if ( positionEnd.m_bValid
          && UFG::HavokAIUtilGame::IsValidKey(positionEnd.m_packedKey, positionEnd.m_aiMeshUid)
          && positionEnd.m_packedKey != -1
          && positionEnd.m_aiMeshUid != -1
          && !(unsigned __int8)UFG::NavComponent::AIRayCastHits(pNavComponent, &positionEnd, 0i64) )
        {
          v39 = MoveToBetterAttackPositionTask::EvaluatePosition(this, &v45, vTargetPosition, v14);
          if ( v39 > v15 )
          {
            m_bValid = positionEnd.m_bValid;
            v15 = v39;
            v41 = positionEnd.m_vPosition.x;
            this->m_npBestPosition.m_vPosition.y = positionEnd.m_vPosition.y;
            this->m_npBestPosition.m_vPosition.x = v41;
            this->m_npBestPosition.m_vPosition.z = positionEnd.m_vPosition.z;
            if ( m_bValid )
            {
              v42.m_quad = (__m128)positionEnd.m_hkvMeshPosition;
              this->m_npBestPosition.m_bValid = m_bValid;
              this->m_npBestPosition.m_packedKey = positionEnd.m_packedKey;
              m_aiMeshUid = positionEnd.m_aiMeshUid;
              this->m_npBestPosition.m_hkvMeshPosition = (hkVector4f)v42.m_quad;
              this->m_npBestPosition.m_aiMeshUid = m_aiMeshUid;
            }
            else
            {
              this->m_npBestPosition.m_bValid = 0;
            }
            this->m_bFoundPosition = 1;
          }
        }
      }
      ++v3;
    }
    while ( v3 < SHIDWORD(this->m_Track[1].mResourceOwner) );
  }
}

// File Line: 7709
// RVA: 0x3775E0
bool __fastcall MoveToBetterAttackPositionTask::MoveToNewPosition(
        MoveToBetterAttackPositionTask *this,
        UFG::NavComponent *pNavComponent)
{
  UFG::HavokNavPosition *p_m_npBestPosition; // rbx
  bool result; // al

  p_m_npBestPosition = &this->m_npBestPosition;
  ((void (__fastcall *)(UFG::HavokNavPosition *))this->m_npBestPosition.vfptr->Validate)(&this->m_npBestPosition);
  result = p_m_npBestPosition->vfptr->IsMeshPositionValid(p_m_npBestPosition);
  if ( result )
  {
    UFG::NavComponent::AddGoalPoint(pNavComponent, p_m_npBestPosition, AiGoal_Replace, 2.0, 0.5);
    return !UFG::NavComponent::IsAtDestination(pNavComponent);
  }
  return result;
}

// File Line: 7733
// RVA: 0x346FB0
void __fastcall MoveToBetterAttackPositionTask::Begin(
        MoveToBetterAttackPositionTask *this,
        ActionContext *action_context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::SimComponent *m_pComponent; // rax
  __int16 m_Flags; // dx
  UFG::CombatRegion *v6; // r8
  UFG::qSafePointer<UFG::CombatRegion,UFG::CombatRegion> *p_m_pCombatRegion; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *v10; // rax

  this->m_pActionContext = action_context;
  this->m_bFoundPosition = 0;
  m_pPointer = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[22].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::AIEntityComponent::_TypeUID);
      else
        m_pComponent = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::AIEntityComponent::_TypeUID);
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[22].m_pComponent;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  v6 = *(UFG::CombatRegion **)&m_pComponent[15].m_TypeUID;
  p_m_pCombatRegion = &this->m_pCombatRegion;
  if ( this->m_pCombatRegion.m_pPointer )
  {
    mPrev = p_m_pCombatRegion->mPrev;
    mNext = this->m_pCombatRegion.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pCombatRegion->mPrev = p_m_pCombatRegion;
    this->m_pCombatRegion.mNext = &this->m_pCombatRegion;
  }
  this->m_pCombatRegion.m_pPointer = v6;
  if ( v6 )
  {
    v10 = v6->UFG::qSafePointerNode<UFG::CombatRegion>::m_SafePointerList.UFG::qSafePointerNode<UFG::CombatRegion>::mNode.mPrev;
    v10->mNext = p_m_pCombatRegion;
    p_m_pCombatRegion->mPrev = v10;
    this->m_pCombatRegion.mNext = &v6->UFG::qSafePointerNode<UFG::CombatRegion>::m_SafePointerList.UFG::qSafePointerNode<UFG::CombatRegion>::mNode;
    v6->UFG::qSafePointerNode<UFG::CombatRegion>::m_SafePointerList.UFG::qSafePointerNode<UFG::CombatRegion>::mNode.mPrev = p_m_pCombatRegion;
  }
}

// File Line: 7747
// RVA: 0x390CC0
bool __fastcall MoveToBetterAttackPositionTask::Update(MoveToBetterAttackPositionTask *this, float timestep)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::SimComponent *v4; // rbx
  UFG::NavComponent *m_pComponent; // rdi
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectGame *v8; // rcx
  __int16 v9; // dx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::SimObjectCVBase *v11; // rcx
  UFG::qVector3 raycastPosition; // [rsp+20h] [rbp-18h] BYREF

  m_pPointer = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
  v4 = 0i64;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::NavComponent *)m_pPointer->m_Components.p[36].m_pComponent;
    }
    else
    {
      if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::NavComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::NavComponent::_TypeUID);
      m_pComponent = (UFG::NavComponent *)ComponentOfTypeHK;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  if ( !this->m_bFoundPosition )
  {
    v8 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
    if ( v8 )
    {
      v9 = v8->m_Flags;
      if ( (v9 & 0x4000) != 0 )
      {
        v4 = v8->m_Components.p[20].m_pComponent;
      }
      else if ( v9 >= 0 )
      {
        if ( (v9 & 0x2000) != 0 || (v9 & 0x1000) != 0 )
          ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::TargetingSystemBaseComponent::_TypeUID);
        else
          ComponentOfType = UFG::SimObject::GetComponentOfType(v8, UFG::TargetingSystemBaseComponent::_TypeUID);
        v4 = ComponentOfType;
      }
      else
      {
        v4 = v8->m_Components.p[20].m_pComponent;
      }
    }
    v11 = *(UFG::SimObjectCVBase **)(56i64
                                   * *(unsigned __int8 *)(LOBYTE(this->m_Track[1].vfptr)
                                                        + *(_QWORD *)&v4[1].m_Flags
                                                        + 8i64)
                                   + *(_QWORD *)&v4[1].m_TypeUID
                                   + 40);
    if ( v11 )
    {
      UFG::ComputeObjectRaycastPosition(v11, &raycastPosition);
      MoveToBetterAttackPositionTask::FindNewPosition(this, m_pComponent, &raycastPosition);
    }
  }
  return this->m_bFoundPosition && MoveToBetterAttackPositionTask::MoveToNewPosition(this, m_pComponent);
}

// File Line: 7786
// RVA: 0x330870
void __fastcall MoveToFindLineOfSightTask::MoveToFindLineOfSightTask(MoveToFindLineOfSightTask *this)
{
  float y; // xmm1_4
  float z; // xmm2_4

  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<MoveToFindLineOfSightTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&MoveToFindLineOfSightTask::`vftable;
  this->m_pTargetSimObject.mPrev = &this->m_pTargetSimObject;
  this->m_pTargetSimObject.mNext = &this->m_pTargetSimObject;
  this->m_pTargetSimObject.m_pPointer = 0i64;
  this->m_pCombatRegion.mPrev = &this->m_pCombatRegion;
  this->m_pCombatRegion.mNext = &this->m_pCombatRegion;
  this->m_pCombatRegion.m_pPointer = 0i64;
  this->m_npBestPosition.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::NavPositionBase::`vftable;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->m_npBestPosition.m_vPosition.x = UFG::qVector3::msZero.x;
  this->m_npBestPosition.m_vPosition.y = y;
  this->m_npBestPosition.m_vPosition.z = z;
  this->m_npBestPosition.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
  this->m_npBestPosition.m_bValid = 0;
  this->m_npBestPosition.m_hkvMeshPosition = (hkVector4f)hkvZero_13.m_quad;
  *(_QWORD *)&this->m_npBestPosition.m_packedKey = -1i64;
}

// File Line: 7793
// RVA: 0x3394D0
void __fastcall MoveToFindLineOfSightTask::~MoveToFindLineOfSightTask(MoveToFindLineOfSightTask *this)
{
  UFG::qSafePointer<UFG::CombatRegion,UFG::CombatRegion> *p_m_pCombatRegion; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_pTargetSimObject; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<ITask,ITask> *v12; // rcx
  UFG::qNode<ITask,ITask> *v13; // rax

  this->vfptr = (ITaskVtbl *)&MoveToFindLineOfSightTask::`vftable;
  p_m_pCombatRegion = &this->m_pCombatRegion;
  if ( this->m_pCombatRegion.m_pPointer )
  {
    mPrev = p_m_pCombatRegion->mPrev;
    mNext = p_m_pCombatRegion->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pCombatRegion->mPrev = p_m_pCombatRegion;
    p_m_pCombatRegion->mNext = p_m_pCombatRegion;
  }
  p_m_pCombatRegion->m_pPointer = 0i64;
  v5 = p_m_pCombatRegion->mPrev;
  v6 = p_m_pCombatRegion->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_m_pCombatRegion->mPrev = p_m_pCombatRegion;
  p_m_pCombatRegion->mNext = p_m_pCombatRegion;
  p_m_pTargetSimObject = &this->m_pTargetSimObject;
  if ( this->m_pTargetSimObject.m_pPointer )
  {
    v8 = p_m_pTargetSimObject->mPrev;
    v9 = this->m_pTargetSimObject.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    p_m_pTargetSimObject->mPrev = p_m_pTargetSimObject;
    this->m_pTargetSimObject.mNext = &this->m_pTargetSimObject;
  }
  this->m_pTargetSimObject.m_pPointer = 0i64;
  v10 = p_m_pTargetSimObject->mPrev;
  v11 = this->m_pTargetSimObject.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  p_m_pTargetSimObject->mPrev = p_m_pTargetSimObject;
  this->m_pTargetSimObject.mNext = &this->m_pTargetSimObject;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v12 = this->mPrev;
  v13 = this->mNext;
  v12->mNext = v13;
  v13->mPrev = v12;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 7800
// RVA: 0x377670
bool __fastcall MoveToFindLineOfSightTask::MoveToNewPosition(
        MoveToFindLineOfSightTask *this,
        UFG::NavComponent *pNavComponent)
{
  bool result; // al

  ((void (__fastcall *)(UFG::HavokNavPosition *))this->m_npBestPosition.vfptr->Validate)(&this->m_npBestPosition);
  result = this->m_npBestPosition.vfptr->IsMeshPositionValid(&this->m_npBestPosition);
  if ( result )
  {
    UFG::NavComponent::AddGoalPoint(
      pNavComponent,
      &this->m_npBestPosition,
      AiGoal_Replace,
      sNaturalMovementSpeeds[BYTE1(this->m_Track[1].vfptr)],
      0.5);
    return !UFG::NavComponent::IsAtDestination(pNavComponent);
  }
  return result;
}

// File Line: 7821
// RVA: 0x3510F0
void __fastcall MoveToFindLineOfSightTask::CreateRangedLOSQuery(MoveToFindLineOfSightTask *this)
{
  UFG::AIRangedLineOfSightQuery *m_pLOSQuery; // rcx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rsi
  UFG::AIRangedLineOfSightQuery *v4; // rcx
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::SimComponent *m_pComponent; // rax
  __int16 m_Flags; // dx
  UFG::CombatRegion *v9; // r8
  UFG::qSafePointer<UFG::CombatRegion,UFG::CombatRegion> *p_m_pCombatRegion; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::SimObjectGame *v14; // rcx
  UFG::SimComponent *v15; // r8
  __int16 v16; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObject *v18; // r8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_pTargetSimObject; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v20; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v21; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v22; // rax
  UFG::allocator::free_link *v23; // rax
  UFG::AIRangedLineOfSightQuery *v24; // rax
  UFG::AIRangedLineOfSightQuery::QueryParameters *p_m_queryParams; // rdi
  UFG::SimObject *v26; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v27; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v28; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v29; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_pTargetSimObject; // rdx
  UFG::SimObject *v31; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v32; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v33; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v34; // rax
  UFG::SimObject *v35; // rax
  float y; // xmm0_4
  float z; // xmm1_4
  UFG::allocator::free_link *outMinimumDesired; // [rsp+50h] [rbp+8h] BYREF
  float outMaximumDesired; // [rsp+58h] [rbp+10h] BYREF
  float outDesired; // [rsp+60h] [rbp+18h] BYREF

  m_pLOSQuery = this->m_pLOSQuery;
  m_pTransformNodeComponent = 0i64;
  if ( m_pLOSQuery )
  {
    if ( !m_pLOSQuery->vfptr->IsCompleted(m_pLOSQuery) )
      UFG::AIQueryManager::CancelQuery(UFG::AIQueryManager::ms_pInstance, this->m_pLOSQuery);
    v4 = this->m_pLOSQuery;
    if ( v4->m_iRefCount-- == 1 )
      v4->vfptr->__vecDelDtor(v4, 1u);
    this->m_pLOSQuery = 0i64;
  }
  this->m_pLOSQuery = 0i64;
  m_pPointer = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[22].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::AIEntityComponent::_TypeUID);
      else
        m_pComponent = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::AIEntityComponent::_TypeUID);
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[22].m_pComponent;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  v9 = *(UFG::CombatRegion **)&m_pComponent[15].m_TypeUID;
  p_m_pCombatRegion = &this->m_pCombatRegion;
  if ( this->m_pCombatRegion.m_pPointer )
  {
    mPrev = p_m_pCombatRegion->mPrev;
    mNext = this->m_pCombatRegion.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pCombatRegion->mPrev = p_m_pCombatRegion;
    this->m_pCombatRegion.mNext = &this->m_pCombatRegion;
  }
  this->m_pCombatRegion.m_pPointer = v9;
  if ( v9 )
  {
    v13 = v9->UFG::qSafePointerNode<UFG::CombatRegion>::m_SafePointerList.UFG::qSafePointerNode<UFG::CombatRegion>::mNode.mPrev;
    v13->mNext = p_m_pCombatRegion;
    p_m_pCombatRegion->mPrev = v13;
    this->m_pCombatRegion.mNext = &v9->UFG::qSafePointerNode<UFG::CombatRegion>::m_SafePointerList.UFG::qSafePointerNode<UFG::CombatRegion>::mNode;
    v9->UFG::qSafePointerNode<UFG::CombatRegion>::m_SafePointerList.UFG::qSafePointerNode<UFG::CombatRegion>::mNode.mPrev = p_m_pCombatRegion;
  }
  v14 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
  if ( v14 )
  {
    v16 = v14->m_Flags;
    if ( (v16 & 0x4000) != 0 )
    {
      v15 = v14->m_Components.p[20].m_pComponent;
    }
    else if ( v16 >= 0 )
    {
      if ( (v16 & 0x2000) != 0 || (v16 & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v14, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v14, UFG::TargetingSystemBaseComponent::_TypeUID);
      v15 = ComponentOfTypeHK;
    }
    else
    {
      v15 = v14->m_Components.p[20].m_pComponent;
    }
  }
  else
  {
    v15 = 0i64;
  }
  v18 = *(UFG::SimObject **)(56i64
                           * *(unsigned __int8 *)(*(_QWORD *)&v15[1].m_Flags + LOBYTE(this->m_Track[1].vfptr) + 8i64)
                           + *(_QWORD *)&v15[1].m_TypeUID
                           + 40);
  p_m_pTargetSimObject = &this->m_pTargetSimObject;
  if ( this->m_pTargetSimObject.m_pPointer )
  {
    v20 = p_m_pTargetSimObject->mPrev;
    v21 = this->m_pTargetSimObject.mNext;
    v20->mNext = v21;
    v21->mPrev = v20;
    p_m_pTargetSimObject->mPrev = p_m_pTargetSimObject;
    this->m_pTargetSimObject.mNext = &this->m_pTargetSimObject;
  }
  this->m_pTargetSimObject.m_pPointer = v18;
  if ( v18 )
  {
    v22 = v18->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    v22->mNext = p_m_pTargetSimObject;
    p_m_pTargetSimObject->mPrev = v22;
    this->m_pTargetSimObject.mNext = &v18->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
    v18->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_m_pTargetSimObject;
  }
  if ( this->m_pTargetSimObject.m_pPointer )
  {
    v23 = UFG::qMalloc(0x12C0ui64, UFG::gGlobalNewName, 0i64);
    outMinimumDesired = v23;
    if ( v23 )
      UFG::AIRangedLineOfSightQuery::AIRangedLineOfSightQuery((UFG::AIRangedLineOfSightQuery *)v23);
    else
      v24 = 0i64;
    this->m_pLOSQuery = v24;
    ++v24->m_iRefCount;
    p_m_queryParams = &this->m_pLOSQuery->m_queryParams;
    v26 = this->m_pActionContext->mSimObject.m_pPointer;
    if ( this->m_pLOSQuery->m_queryParams.pOwnerSimObject.m_pPointer )
    {
      v27 = p_m_queryParams->pOwnerSimObject.mPrev;
      v28 = this->m_pLOSQuery->m_queryParams.pOwnerSimObject.mNext;
      v27->mNext = v28;
      v28->mPrev = v27;
      p_m_queryParams->pOwnerSimObject.mPrev = &p_m_queryParams->pOwnerSimObject;
      p_m_queryParams->pOwnerSimObject.mNext = &p_m_queryParams->pOwnerSimObject;
    }
    p_m_queryParams->pOwnerSimObject.m_pPointer = v26;
    if ( v26 )
    {
      v29 = v26->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
      v29->mNext = &p_m_queryParams->pOwnerSimObject;
      p_m_queryParams->pOwnerSimObject.mPrev = v29;
      p_m_queryParams->pOwnerSimObject.mNext = &v26->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
      v26->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = &p_m_queryParams->pOwnerSimObject;
    }
    p_pTargetSimObject = &p_m_queryParams->pTargetSimObject;
    v31 = this->m_pTargetSimObject.m_pPointer;
    if ( p_m_queryParams->pTargetSimObject.m_pPointer )
    {
      v32 = p_pTargetSimObject->mPrev;
      v33 = p_m_queryParams->pTargetSimObject.mNext;
      v32->mNext = v33;
      v33->mPrev = v32;
      p_pTargetSimObject->mPrev = p_pTargetSimObject;
      p_m_queryParams->pTargetSimObject.mNext = &p_m_queryParams->pTargetSimObject;
    }
    p_m_queryParams->pTargetSimObject.m_pPointer = v31;
    if ( v31 )
    {
      v34 = v31->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
      v34->mNext = p_pTargetSimObject;
      p_pTargetSimObject->mPrev = v34;
      p_m_queryParams->pTargetSimObject.mNext = &v31->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
      v31->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_pTargetSimObject;
    }
    p_m_queryParams->fDistancePriority = 1.0;
    p_m_queryParams->fLineOfSightPriority = 20.0;
    p_m_queryParams->fPathPriority = 0.75;
    UFG::GetDesiredRanges(
      this->m_pActionContext->mSimObject.m_pPointer,
      (float *)&outMinimumDesired,
      &outMaximumDesired,
      &outDesired);
    LODWORD(p_m_queryParams->fMinDistance) = (_DWORD)outMinimumDesired;
    p_m_queryParams->fMaxDistance = outMaximumDesired;
    UFG::AIQueryManager::SubmitQuery(UFG::AIQueryManager::ms_pInstance, this->m_pLOSQuery);
    v35 = this->m_pTargetSimObject.m_pPointer;
    if ( v35 )
      m_pTransformNodeComponent = v35->m_pTransformNodeComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
    y = m_pTransformNodeComponent->mWorldTransform.v3.y;
    z = m_pTransformNodeComponent->mWorldTransform.v3.z;
    this->m_vLastTestPosition.x = m_pTransformNodeComponent->mWorldTransform.v3.x;
    this->m_vLastTestPosition.y = y;
    this->m_vLastTestPosition.z = z;
  }
}

// File Line: 7884
// RVA: 0x347090
void __fastcall MoveToFindLineOfSightTask::Begin(MoveToFindLineOfSightTask *this, ActionContext *action_context)
{
  this->m_pActionContext = action_context;
  this->m_bFoundPosition = 0;
  this->m_pLOSQuery = 0i64;
  MoveToFindLineOfSightTask::CreateRangedLOSQuery(this);
}

// File Line: 7898
// RVA: 0x390E40
bool __fastcall MoveToFindLineOfSightTask::Update(MoveToFindLineOfSightTask *this, float timestep)
{
  UFG::SimObject *m_pPointer; // rax
  UFG::NavComponent *ComponentOfType; // rdi
  UFG::SimObjectGame *v5; // rcx
  UFG::SimComponent *m_pComponent; // r8
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObject *v9; // r8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_pTargetSimObject; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rsi
  UFG::AIRangedLineOfSightQuery *m_pLOSQuery; // rcx
  UFG::AIRangedLineOfSightQuery *v16; // rdx
  float y; // xmm0_4
  float z; // xmm1_4
  bool v19; // zf
  UFG::SimObjectGame *v20; // rcx
  __int16 v21; // dx
  unsigned int v22; // edx
  UFG::NavComponent *v23; // rax

  m_pPointer = this->m_pTargetSimObject.m_pPointer;
  ComponentOfType = 0i64;
  if ( m_pPointer )
    goto LABEL_18;
  v5 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
  if ( v5 )
  {
    m_Flags = v5->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = v5->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v5, UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = ComponentOfTypeHK;
    }
    else
    {
      m_pComponent = v5->m_Components.p[20].m_pComponent;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  v9 = *(UFG::SimObject **)(56i64
                          * *(unsigned __int8 *)(LOBYTE(this->m_Track[1].vfptr)
                                               + *(_QWORD *)&m_pComponent[1].m_Flags
                                               + 8i64)
                          + *(_QWORD *)&m_pComponent[1].m_TypeUID
                          + 40);
  p_m_pTargetSimObject = &this->m_pTargetSimObject;
  if ( this->m_pTargetSimObject.m_pPointer )
  {
    mPrev = p_m_pTargetSimObject->mPrev;
    mNext = this->m_pTargetSimObject.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pTargetSimObject->mPrev = p_m_pTargetSimObject;
    this->m_pTargetSimObject.mNext = &this->m_pTargetSimObject;
  }
  this->m_pTargetSimObject.m_pPointer = v9;
  if ( v9 )
  {
    v13 = v9->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    v13->mNext = p_m_pTargetSimObject;
    p_m_pTargetSimObject->mPrev = v13;
    this->m_pTargetSimObject.mNext = &v9->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
    v9->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_m_pTargetSimObject;
  }
  m_pPointer = this->m_pTargetSimObject.m_pPointer;
  if ( m_pPointer )
  {
LABEL_18:
    m_pTransformNodeComponent = m_pPointer->m_pTransformNodeComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
    if ( (float)((float)((float)((float)(m_pTransformNodeComponent->mWorldTransform.v3.y - this->m_vLastTestPosition.y)
                               * (float)(m_pTransformNodeComponent->mWorldTransform.v3.y - this->m_vLastTestPosition.y))
                       + (float)((float)(m_pTransformNodeComponent->mWorldTransform.v3.x - this->m_vLastTestPosition.x)
                               * (float)(m_pTransformNodeComponent->mWorldTransform.v3.x - this->m_vLastTestPosition.x)))
               + (float)((float)(m_pTransformNodeComponent->mWorldTransform.v3.z - this->m_vLastTestPosition.z)
                       * (float)(m_pTransformNodeComponent->mWorldTransform.v3.z - this->m_vLastTestPosition.z))) > 100.0
      || !this->m_pLOSQuery && !this->m_bFoundPosition )
    {
      MoveToFindLineOfSightTask::CreateRangedLOSQuery(this);
    }
    m_pLOSQuery = this->m_pLOSQuery;
    if ( m_pLOSQuery && m_pLOSQuery->vfptr->IsCompleted(m_pLOSQuery) )
    {
      v16 = this->m_pLOSQuery;
      if ( v16->m_iBestPositionIndex >= 0 )
      {
        y = v16->m_aRangedPositions.p[v16->m_iBestPositionIndex].vGroundPosition.y;
        z = v16->m_aRangedPositions.p[v16->m_iBestPositionIndex].vGroundPosition.z;
        this->m_npBestPosition.m_vPosition.x = v16->m_aRangedPositions.p[v16->m_iBestPositionIndex].vGroundPosition.x;
        this->m_npBestPosition.m_vPosition.y = y;
        this->m_npBestPosition.m_vPosition.z = z;
        this->m_npBestPosition.m_bValid = 0;
        this->m_bFoundPosition = 1;
      }
      v19 = v16->m_iRefCount-- == 1;
      if ( v19 )
        v16->vfptr->__vecDelDtor(v16, 1u);
      this->m_pLOSQuery = 0i64;
    }
    if ( !this->m_bFoundPosition )
    {
      LOBYTE(m_pPointer) = 1;
      return (char)m_pPointer;
    }
    v20 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
    if ( !v20 )
      goto LABEL_39;
    v21 = v20->m_Flags;
    if ( (v21 & 0x4000) != 0 )
    {
      LOBYTE(m_pPointer) = MoveToFindLineOfSightTask::MoveToNewPosition(
                             this,
                             (UFG::NavComponent *)v20->m_Components.p[36].m_pComponent);
      return (char)m_pPointer;
    }
    if ( v21 < 0 || (v21 & 0x2000) != 0 )
    {
      v22 = UFG::NavComponent::_TypeUID;
    }
    else
    {
      v19 = (v21 & 0x1000) == 0;
      v22 = UFG::NavComponent::_TypeUID;
      if ( v19 )
      {
        ComponentOfType = (UFG::NavComponent *)UFG::SimObject::GetComponentOfType(v20, UFG::NavComponent::_TypeUID);
LABEL_39:
        LOBYTE(m_pPointer) = MoveToFindLineOfSightTask::MoveToNewPosition(this, ComponentOfType);
        return (char)m_pPointer;
      }
    }
    v23 = (UFG::NavComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v20, v22);
    LOBYTE(m_pPointer) = MoveToFindLineOfSightTask::MoveToNewPosition(this, v23);
  }
  return (char)m_pPointer;
}

// File Line: 7960
// RVA: 0x355340
void __fastcall MoveToFindLineOfSightTask::End(MoveToFindLineOfSightTask *this)
{
  UFG::AIRangedLineOfSightQuery *m_pLOSQuery; // rcx
  UFG::AIRangedLineOfSightQuery *v3; // rcx

  m_pLOSQuery = this->m_pLOSQuery;
  if ( m_pLOSQuery )
  {
    if ( !m_pLOSQuery->vfptr->IsCompleted(m_pLOSQuery) )
      UFG::AIQueryManager::CancelQuery(UFG::AIQueryManager::ms_pInstance, this->m_pLOSQuery);
    v3 = this->m_pLOSQuery;
    if ( v3->m_iRefCount-- == 1 )
      v3->vfptr->__vecDelDtor(v3, 1u);
    this->m_pLOSQuery = 0i64;
  }
}

// File Line: 7982
// RVA: 0x332990
void __fastcall WaitUntilAbleToPathToTargetTask::WaitUntilAbleToPathToTargetTask(WaitUntilAbleToPathToTargetTask *this)
{
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<WaitUntilAbleToPathToTargetTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&WaitUntilAbleToPathToTargetTask::`vftable;
  this->m_pTargetSimObject.mPrev = &this->m_pTargetSimObject;
  this->m_pTargetSimObject.mNext = &this->m_pTargetSimObject;
  this->m_pTargetSimObject.m_pPointer = 0i64;
  UFG::FindPathDeferredQuery::FindPathDeferredQuery(&this->m_PathQueryInput);
  this->m_PathQueryOutput.vfptr = (UFG::DaemonQueryOutputVtbl *)&UFG::DaemonQueryOutput::`vftable;
  *(_QWORD *)&this->m_PathQueryOutput.m_id = 0i64;
  this->m_PathQueryOutput.m_status = Status_Undefined;
  this->m_PathQueryOutput.vfptr = (UFG::DaemonQueryOutputVtbl *)&UFG::FindPathOutput::`vftable;
  this->m_PathQueryOutput.m_pPath.m_pNavPath = 0i64;
  this->m_NavParams.m_fRadius = 0.0;
  this->m_NavParams.m_flags = 65280;
  this->m_PendingQuery = 0;
}

// File Line: 7989
// RVA: 0x33B8A0
void __fastcall WaitUntilAbleToPathToTargetTask::~WaitUntilAbleToPathToTargetTask(
        WaitUntilAbleToPathToTargetTask *this)
{
  UFG::FindPathOutput *p_m_PathQueryOutput; // rdi
  UFG::NavPath *m_pNavPath; // rcx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_pTargetSimObject; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<ITask,ITask> *v10; // rcx
  UFG::qNode<ITask,ITask> *v11; // rax

  this->vfptr = (ITaskVtbl *)&WaitUntilAbleToPathToTargetTask::`vftable;
  p_m_PathQueryOutput = &this->m_PathQueryOutput;
  m_pNavPath = this->m_PathQueryOutput.m_pPath.m_pNavPath;
  if ( m_pNavPath )
  {
    if ( m_pNavPath->m_uRefCount-- == 1 )
      m_pNavPath->vfptr->__vecDelDtor(m_pNavPath, 1u);
  }
  p_m_PathQueryOutput->vfptr = (UFG::DaemonQueryOutputVtbl *)&UFG::DaemonQueryOutput::`vftable;
  this->m_PathQueryInput.vfptr = (UFG::DaemonQueryInputVtbl *)&UFG::DaemonQueryInput::`vftable;
  p_m_pTargetSimObject = &this->m_pTargetSimObject;
  if ( this->m_pTargetSimObject.m_pPointer )
  {
    mPrev = p_m_pTargetSimObject->mPrev;
    mNext = this->m_pTargetSimObject.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pTargetSimObject->mPrev = p_m_pTargetSimObject;
    this->m_pTargetSimObject.mNext = &this->m_pTargetSimObject;
  }
  this->m_pTargetSimObject.m_pPointer = 0i64;
  v8 = p_m_pTargetSimObject->mPrev;
  v9 = this->m_pTargetSimObject.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  p_m_pTargetSimObject->mPrev = p_m_pTargetSimObject;
  this->m_pTargetSimObject.mNext = &this->m_pTargetSimObject;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v10 = this->mPrev;
  v11 = this->mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 7994
// RVA: 0x348E80
void __fastcall WaitUntilAbleToPathToTargetTask::Begin(
        WaitUntilAbleToPathToTargetTask *this,
        ActionContext *action_context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::SimComponent *v4; // rdi
  UFG::SimComponent *m_pComponent; // r8
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObject *v8; // r8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_pTargetSimObject; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::SimObjectGame *v13; // rcx
  __int16 v14; // dx
  UFG::SimComponent *ComponentOfType; // rax
  unsigned int v16; // eax

  this->m_pActionContext = action_context;
  m_pPointer = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
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
  v8 = *(UFG::SimObject **)(56i64
                          * *(unsigned __int8 *)(LOBYTE(this->m_Track[1].vfptr)
                                               + *(_QWORD *)&m_pComponent[1].m_Flags
                                               + 8i64)
                          + *(_QWORD *)&m_pComponent[1].m_TypeUID
                          + 40);
  p_m_pTargetSimObject = &this->m_pTargetSimObject;
  if ( this->m_pTargetSimObject.m_pPointer )
  {
    mPrev = p_m_pTargetSimObject->mPrev;
    mNext = this->m_pTargetSimObject.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pTargetSimObject->mPrev = p_m_pTargetSimObject;
    this->m_pTargetSimObject.mNext = &this->m_pTargetSimObject;
  }
  this->m_pTargetSimObject.m_pPointer = v8;
  if ( v8 )
  {
    v12 = v8->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    v12->mNext = p_m_pTargetSimObject;
    p_m_pTargetSimObject->mPrev = v12;
    this->m_pTargetSimObject.mNext = &v8->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
    v8->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_m_pTargetSimObject;
  }
  v13 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
  if ( v13 )
  {
    v14 = v13->m_Flags;
    if ( (v14 & 0x4000) != 0 )
    {
      v4 = v13->m_Components.p[36].m_pComponent;
    }
    else
    {
      if ( v14 < 0 || (v14 & 0x2000) != 0 || (v14 & 0x1000) != 0 )
        ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::NavComponent::_TypeUID);
      else
        ComponentOfType = UFG::SimObject::GetComponentOfType(v13, UFG::NavComponent::_TypeUID);
      v4 = ComponentOfType;
    }
  }
  this->m_NavParams = *(UFG::NavParams *)((char *)&v4[2].m_BoundComponentHandles.mNode.mNext + 4);
  if ( BYTE1(this->m_Track[1].vfptr) )
  {
    v16 = this->m_NavParams.m_flags;
    LOBYTE(this->m_NavParams.m_flags) = 0;
    this->m_NavParams.m_flags |= v16 & 0xFE;
  }
}

// File Line: 8017
// RVA: 0x393B70
char __fastcall WaitUntilAbleToPathToTargetTask::Update(WaitUntilAbleToPathToTargetTask *this, float timestep)
{
  hkVector4f *v4; // rbx
  UFG::SimObjectGame *m_pPointer; // rcx
  hkVector4f *m_pComponent; // rdi
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectGame *v9; // rcx
  __int16 v10; // dx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::NavPath *m_pNavPath; // rax
  float v13; // xmm0_4
  float v14; // xmm1_4
  char v15; // al
  float v16; // xmm0_4
  float v17; // xmm1_4
  char v18; // al
  UFG::DaemonManager *v19; // rax

  if ( !this->m_pTargetSimObject.m_pPointer )
    return 0;
  v4 = 0i64;
  m_pPointer = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (hkVector4f *)m_pPointer->m_Components.p[36].m_pComponent;
    }
    else
    {
      if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::NavComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::NavComponent::_TypeUID);
      m_pComponent = (hkVector4f *)ComponentOfTypeHK;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  v9 = (UFG::SimObjectGame *)this->m_pTargetSimObject.m_pPointer;
  if ( v9 )
  {
    v10 = v9->m_Flags;
    if ( (v10 & 0x4000) != 0 )
    {
      v4 = (hkVector4f *)v9->m_Components.p[36].m_pComponent;
    }
    else
    {
      if ( v10 < 0 || (v10 & 0x2000) != 0 || (v10 & 0x1000) != 0 )
        ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::NavComponent::_TypeUID);
      else
        ComponentOfType = UFG::SimObject::GetComponentOfType(v9, UFG::NavComponent::_TypeUID);
      v4 = (hkVector4f *)ComponentOfType;
    }
  }
  if ( this->m_PendingQuery )
  {
    if ( this->m_PathQueryOutput.m_status == Status_Completed )
    {
      m_pNavPath = this->m_PathQueryOutput.m_pPath.m_pNavPath;
      this->m_PendingQuery = 0;
      if ( m_pNavPath->m_aWaypoints.size )
        return 0;
    }
    else if ( this->m_PathQueryOutput.m_status == Status_Failed )
    {
      this->m_PendingQuery = 0;
      return 1;
    }
  }
  else
  {
    v13 = m_pComponent[5].m_quad.m128_f32[3];
    v14 = m_pComponent[6].m_quad.m128_f32[0];
    LODWORD(this->m_PathQueryInput.m_npFrom.m_vPosition.x) = m_pComponent[5].m_quad.m128_i32[2];
    this->m_PathQueryInput.m_npFrom.m_vPosition.y = v13;
    this->m_PathQueryInput.m_npFrom.m_vPosition.z = v14;
    v15 = m_pComponent[6].m_quad.m128_i8[8];
    if ( v15 )
    {
      this->m_PathQueryInput.m_npFrom.m_bValid = v15;
      this->m_PathQueryInput.m_npFrom.m_hkvMeshPosition = (hkVector4f)m_pComponent[7].m_quad;
      this->m_PathQueryInput.m_npFrom.m_packedKey = m_pComponent[8].m_quad.m128_u32[0];
      this->m_PathQueryInput.m_npFrom.m_aiMeshUid = m_pComponent[8].m_quad.m128_u32[1];
    }
    else
    {
      this->m_PathQueryInput.m_npFrom.m_bValid = 0;
    }
    v16 = v4[5].m_quad.m128_f32[3];
    v17 = v4[6].m_quad.m128_f32[0];
    LODWORD(this->m_PathQueryInput.m_npTo.m_vPosition.x) = v4[5].m_quad.m128_i32[2];
    this->m_PathQueryInput.m_npTo.m_vPosition.y = v16;
    this->m_PathQueryInput.m_npTo.m_vPosition.z = v17;
    v18 = v4[6].m_quad.m128_i8[8];
    if ( v18 )
    {
      this->m_PathQueryInput.m_npTo.m_bValid = v18;
      this->m_PathQueryInput.m_npTo.m_hkvMeshPosition = (hkVector4f)v4[7].m_quad;
      this->m_PathQueryInput.m_npTo.m_packedKey = v4[8].m_quad.m128_u32[0];
      this->m_PathQueryInput.m_npTo.m_aiMeshUid = v4[8].m_quad.m128_u32[1];
    }
    else
    {
      this->m_PathQueryInput.m_npTo.m_bValid = 0;
    }
    if ( this->m_PathQueryInput.m_npFrom.m_bValid
      && UFG::HavokAIUtilGame::IsValidKey(
           this->m_PathQueryInput.m_npFrom.m_packedKey,
           this->m_PathQueryInput.m_npFrom.m_aiMeshUid)
      && this->m_PathQueryInput.m_npTo.m_bValid
      && UFG::HavokAIUtilGame::IsValidKey(
           this->m_PathQueryInput.m_npTo.m_packedKey,
           this->m_PathQueryInput.m_npTo.m_aiMeshUid) )
    {
      this->m_PathQueryInput.m_pNavParams = &this->m_NavParams;
      v19 = UFG::DaemonManager::Instance();
      UFG::DaemonManager::SubmitQuery(v19, &this->m_PathQueryInput, &this->m_PathQueryOutput);
      this->m_PendingQuery = 1;
    }
  }
  return 1;
}

// File Line: 8080
// RVA: 0x355650
void __fastcall WaitUntilAbleToPathToTargetTask::End(WaitUntilAbleToPathToTargetTask *this)
{
  UFG::DaemonManager *v2; // rax

  if ( this->m_PendingQuery )
  {
    v2 = UFG::DaemonManager::Instance();
    UFG::DaemonManager::CancelQuery(v2, &this->m_PathQueryInput);
    this->m_PendingQuery = 0;
  }
}

// File Line: 8096
// RVA: 0x32FCF0
void __fastcall InteractingWithVehicleHeuristicTask::InteractingWithVehicleHeuristicTask(
        InteractingWithVehicleHeuristicTask *this)
{
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<InteractingWithVehicleHeuristicTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&InteractingWithVehicleHeuristicTask::`vftable;
}

// File Line: 8104
// RVA: 0x3464C0
void __fastcall InteractingWithVehicleHeuristicTask::Begin(
        InteractingWithVehicleHeuristicTask *this,
        ActionContext *action_context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax

  this->m_pActionContext = action_context;
  m_pPointer = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[5].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::AIScriptInterfaceComponent::_TypeUID);
      else
        m_pComponent = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::AIScriptInterfaceComponent::_TypeUID);
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[5].m_pComponent;
    }
    if ( m_pComponent )
      BYTE2(m_pComponent[32].m_BoundComponentHandles.mNode.mPrev) |= 1u;
  }
}

// File Line: 8123
// RVA: 0x3550E0
void __fastcall InteractingWithVehicleHeuristicTask::End(InteractingWithVehicleHeuristicTask *this)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax

  m_pPointer = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[5].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::AIScriptInterfaceComponent::_TypeUID);
      else
        m_pComponent = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::AIScriptInterfaceComponent::_TypeUID);
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[5].m_pComponent;
    }
    if ( m_pComponent )
      BYTE2(m_pComponent[32].m_BoundComponentHandles.mNode.mPrev) &= ~1u;
  }
}

// File Line: 8138
// RVA: 0x330080
void __fastcall InvokeBehaviourTask::InvokeBehaviourTask(InvokeBehaviourTask *this)
{
  SpawnTask::SpawnTask(this);
  this->vfptr = (ITaskVtbl *)&InvokeBehaviourTask::`vftable;
  this->m_pBehaviour.mPrev = &this->m_pBehaviour;
  this->m_pBehaviour.mNext = &this->m_pBehaviour;
  this->m_pBehaviour.m_pPointer = 0i64;
  this->m_pParentBehaviour.mPrev = &this->m_pParentBehaviour;
  this->m_pParentBehaviour.mNext = &this->m_pParentBehaviour;
  this->m_pParentBehaviour.m_pPointer = 0i64;
  this->m_pBehaviourController.mPrev = &this->m_pBehaviourController;
  this->m_pBehaviourController.mNext = &this->m_pBehaviourController;
  this->m_pBehaviourController.m_pPointer = 0i64;
  this->m_InvokeResult.mId = 0;
  this->m_InvokeResult.mDesc = 0i64;
  this->m_InvokeResult.mInvokeParams.mNode = 0i64;
  *(_QWORD *)&this->m_InvokeResult.mInvokeParams.mPriority = 0i64;
  this->m_InvokeResult.mInvokeParams.mControlType = eINVOKE_AND_OWN;
  this->m_InvokeResult.mInvokeParams.mMaxWaitTime = -1.0;
  this->m_InvokeResult.mInvokeParams.mMaxLifeTime = -1.0;
  this->m_InvokeResult.mInvokeParams.mIsRootInvoke = 1;
  this->m_InvokeResult.mInvokeParams.mInvokeTask = 0i64;
  this->m_InvokeResult.mBehaviour = 0i64;
}

// File Line: 8142
// RVA: 0x338DE0
void __fastcall InvokeBehaviourTask::~InvokeBehaviourTask(InvokeBehaviourTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::BehaviourControllerComponent> *p_m_pBehaviourController; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::Behaviour,UFG::Behaviour> *p_m_pParentBehaviour; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::Behaviour>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::Behaviour>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::Behaviour>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::Behaviour>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qSafePointer<UFG::Behaviour,UFG::Behaviour> *p_m_pBehaviour; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::Behaviour>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::Behaviour>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::Behaviour>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::Behaviour>,UFG::qSafePointerNodeList> *v16; // rax

  this->vfptr = (ITaskVtbl *)&InvokeBehaviourTask::`vftable;
  p_m_pBehaviourController = &this->m_pBehaviourController;
  if ( this->m_pBehaviourController.m_pPointer )
  {
    mPrev = p_m_pBehaviourController->mPrev;
    mNext = p_m_pBehaviourController->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pBehaviourController->mPrev = p_m_pBehaviourController;
    p_m_pBehaviourController->mNext = p_m_pBehaviourController;
  }
  p_m_pBehaviourController->m_pPointer = 0i64;
  v5 = p_m_pBehaviourController->mPrev;
  v6 = p_m_pBehaviourController->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_m_pBehaviourController->mPrev = p_m_pBehaviourController;
  p_m_pBehaviourController->mNext = p_m_pBehaviourController;
  p_m_pParentBehaviour = &this->m_pParentBehaviour;
  if ( this->m_pParentBehaviour.m_pPointer )
  {
    v8 = p_m_pParentBehaviour->mPrev;
    v9 = this->m_pParentBehaviour.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    p_m_pParentBehaviour->mPrev = p_m_pParentBehaviour;
    this->m_pParentBehaviour.mNext = &this->m_pParentBehaviour;
  }
  this->m_pParentBehaviour.m_pPointer = 0i64;
  v10 = p_m_pParentBehaviour->mPrev;
  v11 = this->m_pParentBehaviour.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  p_m_pParentBehaviour->mPrev = p_m_pParentBehaviour;
  this->m_pParentBehaviour.mNext = &this->m_pParentBehaviour;
  p_m_pBehaviour = &this->m_pBehaviour;
  if ( this->m_pBehaviour.m_pPointer )
  {
    v13 = p_m_pBehaviour->mPrev;
    v14 = this->m_pBehaviour.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    p_m_pBehaviour->mPrev = p_m_pBehaviour;
    this->m_pBehaviour.mNext = &this->m_pBehaviour;
  }
  this->m_pBehaviour.m_pPointer = 0i64;
  v15 = p_m_pBehaviour->mPrev;
  v16 = this->m_pBehaviour.mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  p_m_pBehaviour->mPrev = p_m_pBehaviour;
  this->m_pBehaviour.mNext = &this->m_pBehaviour;
  SpawnTask::~SpawnTask(this);
}

// File Line: 8146
// RVA: 0x3467C0
void __fastcall InvokeBehaviourTask::Begin(InvokeBehaviourTask *this, ActionContext *context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::SimComponent *v5; // r8
  __int16 m_Flags; // dx
  UFG::BehaviourControllerComponent *ComponentOfTypeHK; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::BehaviourControllerComponent> *p_m_pBehaviourController; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::BehaviourControllerComponent *v12; // r9
  UFG::qSymbolUC *v13; // rax
  char *v14; // rax
  ITrack *m_Track; // rcx
  Expression::IMemberMapVtbl *vfptr; // rax
  Expression::IMemberMap *(__fastcall *GetResourceOwner)(Expression::IMemberMap *); // rdx
  ActionNode *v18; // r8
  UFG::eInvokeBehaviourPriorityMode mBreakPoint; // edi
  float v20; // xmm0_4
  float v21; // xmm1_4
  int m_TrackClassNameUID; // eax
  UFG::Behaviour *ParentBehaviourOfTask; // rax
  UFG::qSafePointer<UFG::Behaviour,UFG::Behaviour> *p_m_pParentBehaviour; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::Behaviour>,UFG::qSafePointerNodeList> *v25; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::Behaviour>,UFG::qSafePointerNodeList> *v26; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::Behaviour>,UFG::qSafePointerNodeList> *p_mNode; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::Behaviour>,UFG::qSafePointerNodeList> *v28; // rax
  UFG::BehaviourControllerComponent *v29; // rcx
  UFG::InvokeBehaviourResult *p_m_InvokeResult; // r8
  bool v31; // al
  int started; // eax
  UFG::Behaviour *mBehaviour; // r8
  UFG::qSafePointer<UFG::Behaviour,UFG::Behaviour> *p_m_pBehaviour; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::Behaviour>,UFG::qSafePointerNodeList> *v35; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::Behaviour>,UFG::qSafePointerNodeList> *v36; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::Behaviour>,UFG::qSafePointerNodeList> *v37; // rax
  UFG::InvokeBehaviourParams params; // [rsp+20h] [rbp-38h] BYREF
  UFG::qWiseSymbol result; // [rsp+60h] [rbp+8h] BYREF

  m_pPointer = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::BehaviourControllerComponent>(m_pPointer);
    }
    else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::BehaviourControllerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                 m_pPointer,
                                                                 UFG::BehaviourControllerComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::BehaviourControllerComponent *)UFG::SimObject::GetComponentOfType(
                                                                 m_pPointer,
                                                                 UFG::BehaviourControllerComponent::_TypeUID);
    }
    v5 = ComponentOfTypeHK;
  }
  else
  {
    v5 = 0i64;
  }
  p_m_pBehaviourController = &this->m_pBehaviourController;
  if ( this->m_pBehaviourController.m_pPointer )
  {
    mPrev = p_m_pBehaviourController->mPrev;
    mNext = this->m_pBehaviourController.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pBehaviourController->mPrev = p_m_pBehaviourController;
    this->m_pBehaviourController.mNext = &this->m_pBehaviourController;
  }
  this->m_pBehaviourController.m_pPointer = v5;
  if ( v5 )
  {
    v11 = v5->m_SafePointerList.mNode.mPrev;
    v11->mNext = p_m_pBehaviourController;
    p_m_pBehaviourController->mPrev = v11;
    this->m_pBehaviourController.mNext = &v5->m_SafePointerList.mNode;
    v5->m_SafePointerList.mNode.mPrev = p_m_pBehaviourController;
  }
  v12 = (UFG::BehaviourControllerComponent *)this->m_pBehaviourController.m_pPointer;
  if ( v12 )
  {
    m_Track = this->m_Track;
    this->m_CallingActionContext = context;
    vfptr = m_Track[1].vfptr;
    if ( vfptr )
      vfptr = (Expression::IMemberMapVtbl *)((char *)&vfptr->ResolveReferences + (_QWORD)m_Track);
    GetResourceOwner = vfptr->GetResourceOwner;
    if ( GetResourceOwner )
      v18 = (ActionNode *)((char *)&vfptr->GetResourceOwner + (_QWORD)GetResourceOwner);
    else
      v18 = 0i64;
    mBreakPoint = (unsigned __int8)m_Track[1].mBreakPoint;
    v20 = *((float *)&m_Track[1].mMasterRate.text.mOffset + 1);
    v21 = *(float *)&m_Track[1].mMasterRate.text.mOffset;
    params.mControlType = (unsigned __int8)m_Track[1].mDisable;
    m_TrackClassNameUID = m_Track[1].m_TrackClassNameUID;
    params.mMaxLifeTime = v20;
    params.mMaxWaitTime = v21;
    params.mNode = v18;
    params.mPriority = m_TrackClassNameUID;
    params.mPriorityMode = mBreakPoint;
    params.mInvokeTask = this;
    ParentBehaviourOfTask = UFG::BehaviourControllerComponent::FindParentBehaviourOfTask(v12, this);
    p_m_pParentBehaviour = &this->m_pParentBehaviour;
    if ( this->m_pParentBehaviour.m_pPointer )
    {
      v25 = p_m_pParentBehaviour->mPrev;
      v26 = this->m_pParentBehaviour.mNext;
      v25->mNext = v26;
      v26->mPrev = v25;
      p_m_pParentBehaviour->mPrev = p_m_pParentBehaviour;
      this->m_pParentBehaviour.mNext = &this->m_pParentBehaviour;
    }
    this->m_pParentBehaviour.m_pPointer = ParentBehaviourOfTask;
    if ( ParentBehaviourOfTask )
    {
      p_mNode = &ParentBehaviourOfTask->m_SafePointerList.mNode;
      v28 = ParentBehaviourOfTask->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::Behaviour>::mPrev;
      v28->mNext = p_m_pParentBehaviour;
      p_m_pParentBehaviour->mPrev = v28;
      this->m_pParentBehaviour.mNext = p_mNode;
      p_mNode->mPrev = p_m_pParentBehaviour;
    }
    v29 = (UFG::BehaviourControllerComponent *)this->m_pBehaviourController.m_pPointer;
    p_m_InvokeResult = &this->m_InvokeResult;
    v31 = this->m_pParentBehaviour.m_pPointer == 0i64;
    params.mIsRootInvoke = v31;
    if ( mBreakPoint == eINVOKE_PRIORITY_PARALLEL )
    {
      started = UFG::BehaviourControllerComponent::Arbitrate_StartRootParallel(v29, &params, p_m_InvokeResult);
    }
    else if ( v31 )
    {
      started = UFG::BehaviourControllerComponent::Arbitrate_StartRootExclusive(v29, &params, p_m_InvokeResult);
    }
    else
    {
      started = UFG::BehaviourControllerComponent::Arbitrate_StartChild(v29, &params, p_m_InvokeResult);
    }
    if ( started >= 1 )
    {
      mBehaviour = this->m_InvokeResult.mBehaviour;
      p_m_pBehaviour = &this->m_pBehaviour;
      if ( this->m_pBehaviour.m_pPointer )
      {
        v35 = p_m_pBehaviour->mPrev;
        v36 = this->m_pBehaviour.mNext;
        v35->mNext = v36;
        v36->mPrev = v35;
        p_m_pBehaviour->mPrev = p_m_pBehaviour;
        this->m_pBehaviour.mNext = &this->m_pBehaviour;
      }
      this->m_pBehaviour.m_pPointer = mBehaviour;
      if ( mBehaviour )
      {
        v37 = mBehaviour->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::Behaviour>::mPrev;
        v37->mNext = p_m_pBehaviour;
        p_m_pBehaviour->mPrev = v37;
        this->m_pBehaviour.mNext = &mBehaviour->m_SafePointerList.mNode;
        mBehaviour->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::Behaviour>::mPrev = p_m_pBehaviour;
      }
      this->m_InvokeResult.mBehaviour = 0i64;
    }
  }
  else
  {
    v13 = (UFG::qSymbolUC *)UFG::qSymbol::qSymbol(&result, context->mSimObject.m_pPointer->m_pSceneObj->m_NameUID);
    v14 = UFG::qSymbol::as_cstr_dbg(v13);
    UFG::qPrintf(
      "InvokeBehaviourTask::Begin() - BehaviourController not found.  This track should not run on a character without an"
      " AI Cover Component. PropertySet: %s\n",
      v14);
  }
}

// File Line: 8182
// RVA: 0x3904F0
char __fastcall InvokeBehaviourTask::Update(InvokeBehaviourTask *this, float timestep)
{
  UFG::BehaviourControllerComponent *m_pPointer; // r8
  UFG::Behaviour *v4; // rax
  UFG::eInvokeBehaviourState mState; // ecx
  UFG::Behaviour *v7; // rax

  m_pPointer = (UFG::BehaviourControllerComponent *)this->m_pBehaviourController.m_pPointer;
  if ( !m_pPointer )
    return 0;
  v4 = this->m_pBehaviour.m_pPointer;
  if ( !v4 )
    return 0;
  if ( v4->mParams.mControlType == eINVOKE_AND_OWN )
  {
    mState = v4->mState;
    if ( mState == eINVOKE_STATE_RUNNING )
    {
      UFG::BehaviourControllerComponent::UpdateBehaviour(m_pPointer, v4, timestep);
      v7 = this->m_pBehaviour.m_pPointer;
      if ( v7 && v7->mActionController->m_currentNode )
        return 1;
    }
    else if ( (unsigned int)(mState - 2) <= 1 )
    {
      return 1;
    }
  }
  return 0;
}

// File Line: 8224
// RVA: 0x355230
void __fastcall InvokeBehaviourTask::End(InvokeBehaviourTask *this)
{
  UFG::Behaviour *m_pPointer; // rdx

  m_pPointer = this->m_pBehaviour.m_pPointer;
  if ( m_pPointer )
  {
    if ( m_pPointer->mParams.mControlType == eINVOKE_AND_OWN )
      UFG::BehaviourControllerComponent::EndBehaviour(
        (UFG::BehaviourControllerComponent *)this->m_pBehaviourController.m_pPointer,
        m_pPointer);
  }
}

// File Line: 8255
// RVA: 0x342CA0
void __fastcall AIAwarenessEnableTask::Begin(AIAwarenessEnableTask *this, ActionContext *context)
{
  UFG::SimComponent *ComponentOfType; // rax

  ComponentOfType = UFG::SimObject::GetComponentOfType(
                      context->mSimObject.m_pPointer,
                      UFG::AIAwarenessComponent::_TypeUID);
  if ( ComponentOfType )
    LOBYTE(ComponentOfType[1].m_BoundComponentHandles.mNode.mPrev) = LOBYTE(this->m_Track[1].vfptr) != 0;
}

// File Line: 8272
// RVA: 0x342B30
void __fastcall AIAwarenessAddTargetTask::Begin(AIAwarenessAddTargetTask *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::AIAwarenessComponent *v4; // rbx
  UFG::SimComponent *m_pComponent; // rdi
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectGame *v8; // rcx
  __int16 v9; // dx
  UFG::SimComponent *ComponentOfType; // rax
  ITrack *m_Track; // rdx
  UFG::SimObject *v12; // rdi

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
  v8 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( v8 )
  {
    v9 = v8->m_Flags;
    if ( (v9 & 0x4000) != 0 || v9 < 0 || (v9 & 0x2000) != 0 || (v9 & 0x1000) != 0 )
      ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::AIAwarenessComponent::_TypeUID);
    else
      ComponentOfType = UFG::SimObject::GetComponentOfType(v8, UFG::AIAwarenessComponent::_TypeUID);
    v4 = (UFG::AIAwarenessComponent *)ComponentOfType;
  }
  this->mName = UFG::gNullQSymbol;
  m_Track = this->m_Track;
  v12 = *(UFG::SimObject **)(56i64
                           * *(unsigned __int8 *)(LOBYTE(m_Track[1].vfptr) + *(_QWORD *)&m_pComponent[1].m_Flags + 8i64)
                           + *(_QWORD *)&m_pComponent[1].m_TypeUID
                           + 40);
  if ( v12 )
  {
    UFG::AIAwarenessComponent::AddTargetSimObject(v4, v12, (UFG::AIAwareness::TargetPriority)BYTE1(m_Track[1].vfptr));
    this->mName.mUID = v12->m_Name.mUID;
    UFG::AIAwarenessComponent::LockSimObject(v4, &this->mName);
  }
}

// File Line: 8304
// RVA: 0x354C10
void __fastcall AIAwarenessAddTargetTask::End(AIAwarenessAddTargetTask *this)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::AIAwarenessComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = (UFG::AIAwarenessComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         m_pPointer,
                                                         UFG::AIAwarenessComponent::_TypeUID);
    else
      ComponentOfTypeHK = (UFG::AIAwarenessComponent *)UFG::SimObject::GetComponentOfType(
                                                         m_pPointer,
                                                         UFG::AIAwarenessComponent::_TypeUID);
    if ( ComponentOfTypeHK )
    {
      if ( this->mName.mUID != -1 )
        UFG::AIAwarenessComponent::UnlockSimObject(ComponentOfTypeHK, &this->mName);
    }
  }
}

// File Line: 8320
// RVA: 0x14B9160
__int64 dynamic_initializer_for__symHeadTracker__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("HeadTracker", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&symHeadTracker, v0);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__symHeadTracker__);
}

// File Line: 8321
// RVA: 0x14B91E0
__int64 dynamic_initializer_for__symREyeTracker__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("R_EyeTracker", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&symREyeTracker, v0);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__symREyeTracker__);
}

// File Line: 8322
// RVA: 0x14B91A0
__int64 dynamic_initializer_for__symLEyeTracker__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("L_EyeTracker", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&symLEyeTracker, v0);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__symLEyeTracker__);
}

// File Line: 8323
// RVA: 0x14B9220
__int64 dynamic_initializer_for__symSpineTracker__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("SpineTracker", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&symSpineTracker, v0);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__symSpineTracker__);
}

// File Line: 8327
// RVA: 0x346C00
void __fastcall LookAtTask::Begin(LookAtTask *this, ActionContext *context)
{
  UFG::SimComponent *ComponentOfType; // rax
  __int64 v4; // rcx
  AimConstraint *v5; // rax
  AimConstraint *mHeadTrackEffector; // rdx
  AimConstraint *mRightEyeTrackEffector; // r8
  AimConstraint *mLeftEyeTrackEffector; // r9
  AimConstraintMultiLink *mSpineTrackEffector; // r10

  this->mContext = context;
  ComponentOfType = UFG::SimObject::GetComponentOfType(
                      context->mSimObject.m_pPointer,
                      UFG::CharacterAnimationComponent::_TypeUID);
  if ( ComponentOfType )
  {
    v4 = *(_QWORD *)&ComponentOfType[2].m_TypeUID;
    if ( v4 )
    {
      v5 = (AimConstraint *)(*(_QWORD *)(v4 + 32) - 16i64);
      if ( v5 != (AimConstraint *)(v4 + 8) )
      {
        mHeadTrackEffector = this->mHeadTrackEffector;
        mRightEyeTrackEffector = this->mRightEyeTrackEffector;
        mLeftEyeTrackEffector = this->mLeftEyeTrackEffector;
        mSpineTrackEffector = this->mSpineTrackEffector;
        do
        {
          if ( !mHeadTrackEffector && v5->mName.mUID == symHeadTracker.mUID )
          {
            mHeadTrackEffector = v5;
            this->mHeadTrackEffector = v5;
          }
          if ( !mRightEyeTrackEffector && v5->mName.mUID == symREyeTracker.mUID )
          {
            mRightEyeTrackEffector = v5;
            this->mRightEyeTrackEffector = v5;
          }
          if ( !mLeftEyeTrackEffector && v5->mName.mUID == symLEyeTracker.mUID )
          {
            mLeftEyeTrackEffector = v5;
            this->mLeftEyeTrackEffector = v5;
          }
          if ( !mSpineTrackEffector && LOBYTE(this->m_Track[1].vfptr) && v5->mName.mUID == symSpineTracker.mUID )
          {
            mSpineTrackEffector = (AimConstraintMultiLink *)v5;
            this->mSpineTrackEffector = (AimConstraintMultiLink *)v5;
          }
          v5 = (AimConstraint *)&v5->mNext[-1];
        }
        while ( v5 != (AimConstraint *)(v4 + 8) );
      }
    }
  }
}

// File Line: 8376
// RVA: 0x3906A0
char __fastcall LookAtTask::Update(LookAtTask *this, float timeDelta)
{
  UFG::SimObject *m_pPointer; // rbx
  UFG::SimComponent *ComponentOfType; // rsi
  __int64 v5; // rdx
  bool IsVisualTrackingEnabled; // si
  AimConstraint *mHeadTrackEffector; // rax
  AimConstraint *mRightEyeTrackEffector; // rcx
  AimConstraint *mLeftEyeTrackEffector; // rcx
  AimConstraintMultiLink *mSpineTrackEffector; // rcx
  AimConstraint *v11; // rcx
  AimConstraint *v12; // rcx
  float v13; // eax
  float v14; // xmm1_4
  AimConstraintMultiLink *v15; // rcx
  AimConstraintMultiLink *v16; // rcx
  float v17; // eax
  float v18; // xmm1_4
  AimConstraintMultiLink *v19; // rcx
  unsigned __int8 v20; // bp
  AimConstraint *v21; // rcx
  AimConstraint *v22; // rcx
  float v23; // eax
  float v24; // xmm1_4
  AimConstraint *v25; // rcx
  AimConstraint *v26; // rcx
  float v27; // eax
  float v28; // xmm1_4
  AimConstraint *v30; // rcx
  AimConstraint *v31; // rcx

  m_pPointer = this->mContext->mSimObject.m_pPointer;
  if ( (m_pPointer->m_Flags & 0x4000) == 0 )
    return 1;
  ComponentOfType = UFG::SimObject::GetComponentOfType(
                      this->mContext->mSimObject.m_pPointer,
                      UFG::CharacterAnimationComponent::_TypeUID);
  if ( m_pPointer )
    m_pPointer = (UFG::SimObject *)UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>((UFG::SimObjectCVBase *)m_pPointer);
  if ( !ComponentOfType || !m_pPointer || !*(_QWORD *)&ComponentOfType[2].m_TypeUID )
    return 1;
  IsVisualTrackingEnabled = UFG::AIAwarenessComponent::IsVisualTrackingEnabled();
  if ( IsVisualTrackingEnabled )
  {
    if ( BYTE4(m_pPointer[1].m_pTransformNodeComponent) )
    {
      mHeadTrackEffector = this->mHeadTrackEffector;
      if ( mHeadTrackEffector )
      {
        LODWORD(mHeadTrackEffector->mXJointLimitMag) = m_pPointer[1].m_Components.size;
        LODWORD(this->mHeadTrackEffector->mYJointLimitMag) = m_pPointer[1].m_Components.capacity;
        this->mHeadTrackEffector->mZJointLimitMag = *(float *)&m_pPointer[1].m_Components.p;
        this->mHeadTrackEffector->mTrackingGain = *((float *)&m_pPointer[2].vfptr + 1);
      }
    }
    if ( BYTE5(m_pPointer[1].m_pTransformNodeComponent) )
    {
      mRightEyeTrackEffector = this->mRightEyeTrackEffector;
      if ( mRightEyeTrackEffector )
      {
        mRightEyeTrackEffector->mXJointLimitMag = *((float *)&m_pPointer[1].m_Components.p + 1);
        this->mRightEyeTrackEffector->mYJointLimitMag = *(float *)&m_pPointer[1].m_UnboundComponentHandles.mNode.mPrev;
        this->mRightEyeTrackEffector->mZJointLimitMag = *((float *)&m_pPointer[1].m_UnboundComponentHandles.mNode.mPrev
                                                        + 1);
        this->mRightEyeTrackEffector->mTrackingGain = *(float *)&m_pPointer[2].m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
      }
      if ( BYTE5(m_pPointer[1].m_pTransformNodeComponent) )
      {
        mLeftEyeTrackEffector = this->mLeftEyeTrackEffector;
        if ( mLeftEyeTrackEffector )
        {
          mLeftEyeTrackEffector->mXJointLimitMag = *((float *)&m_pPointer[1].m_Components.p + 1);
          this->mLeftEyeTrackEffector->mYJointLimitMag = *(float *)&m_pPointer[1].m_UnboundComponentHandles.mNode.mPrev;
          this->mLeftEyeTrackEffector->mZJointLimitMag = *((float *)&m_pPointer[1].m_UnboundComponentHandles.mNode.mPrev
                                                         + 1);
          this->mLeftEyeTrackEffector->mTrackingGain = *(float *)&m_pPointer[2].m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
        }
      }
    }
    if ( BYTE6(m_pPointer[1].m_pTransformNodeComponent) )
    {
      mSpineTrackEffector = this->mSpineTrackEffector;
      if ( mSpineTrackEffector )
      {
        mSpineTrackEffector->mXJointLimitMaxMag = *(float *)&m_pPointer[1].m_UnboundComponentHandles.mNode.mNext;
        this->mSpineTrackEffector->mYJointLimitMaxMag = *((float *)&m_pPointer[1].m_UnboundComponentHandles.mNode.mNext
                                                        + 1);
        this->mSpineTrackEffector->mZJointLimitMaxMag = *(float *)&m_pPointer[2].vfptr;
        LODWORD(this->mSpineTrackEffector->mXJointLimitMinMag) = LODWORD(m_pPointer[1].m_UnboundComponentHandles.mNode.mNext) ^ _xmm[0];
        LODWORD(this->mSpineTrackEffector->mYJointLimitMinMag) = HIDWORD(m_pPointer[1].m_UnboundComponentHandles.mNode.mNext) ^ _xmm[0];
        LODWORD(this->mSpineTrackEffector->mZJointLimitMinMag) = LODWORD(m_pPointer[2].vfptr) ^ _xmm[0];
        this->mSpineTrackEffector->mTrackingGain = *((float *)&m_pPointer[2].m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev
                                                   + 1);
      }
    }
  }
  v11 = this->mHeadTrackEffector;
  if ( BYTE4(m_pPointer[1].mNode.mChild[1]) )
  {
    if ( v11 )
    {
      LOBYTE(v5) = 1;
      if ( IsVisualTrackingEnabled )
        v5 = BYTE4(m_pPointer[1].m_pTransformNodeComponent);
      v11->vfptr[1].__vecDelDtor(v11, v5);
      v12 = this->mHeadTrackEffector;
      v13 = *(float *)&m_pPointer[1].mNode.mUID;
      v14 = *(float *)&m_pPointer[1].m_Name.mUID;
      v12->mTargetPointWS.y = *((float *)&m_pPointer[1].mNode.mUID + 1);
      v12->mTargetPointWS.z = v14;
      v12->mTargetPointWS.x = v13;
    }
    v15 = this->mSpineTrackEffector;
    if ( v15 )
    {
      LOBYTE(v5) = LOBYTE(this->m_Track[1].vfptr) != 0;
      if ( IsVisualTrackingEnabled )
        v5 = BYTE6(m_pPointer[1].m_pTransformNodeComponent);
      v15->vfptr[1].__vecDelDtor(v15, v5);
      v16 = this->mSpineTrackEffector;
      v17 = *(float *)&m_pPointer[1].mNode.mUID;
      v18 = *(float *)&m_pPointer[1].m_Name.mUID;
      v16->mTargetPointWS.y = *((float *)&m_pPointer[1].mNode.mUID + 1);
      v16->mTargetPointWS.z = v18;
      v16->mTargetPointWS.x = v17;
    }
  }
  else
  {
    if ( v11 )
      v11->vfptr[1].__vecDelDtor(v11, 0);
    v19 = this->mSpineTrackEffector;
    if ( v19 )
      v19->vfptr[1].__vecDelDtor(v19, 0);
  }
  if ( !LOBYTE(m_pPointer[1].m_Flags) )
  {
    v30 = this->mRightEyeTrackEffector;
    if ( v30 )
      v30->vfptr[1].__vecDelDtor(v30, 0);
    v31 = this->mLeftEyeTrackEffector;
    if ( v31 )
      v31->vfptr[1].__vecDelDtor(v31, 0);
    return 1;
  }
  v20 = 1;
  if ( IsVisualTrackingEnabled )
    v20 = BYTE5(m_pPointer[1].m_pTransformNodeComponent);
  v21 = this->mRightEyeTrackEffector;
  if ( v21 )
  {
    v21->vfptr[1].__vecDelDtor(v21, v20);
    v22 = this->mRightEyeTrackEffector;
    v23 = *(float *)&m_pPointer[1].m_pSceneObj;
    v24 = *(float *)&m_pPointer[1].m_pTransformNodeComponent;
    v22->mTargetPointWS.y = *((float *)&m_pPointer[1].m_pSceneObj + 1);
    v22->mTargetPointWS.z = v24;
    v22->mTargetPointWS.x = v23;
  }
  v25 = this->mLeftEyeTrackEffector;
  if ( v25 )
  {
    v25->vfptr[1].__vecDelDtor(v25, v20);
    v26 = this->mLeftEyeTrackEffector;
    v27 = *(float *)&m_pPointer[1].m_pSceneObj;
    v28 = *(float *)&m_pPointer[1].m_pTransformNodeComponent;
    v26->mTargetPointWS.y = *((float *)&m_pPointer[1].m_pSceneObj + 1);
    v26->mTargetPointWS.z = v28;
    v26->mTargetPointWS.x = v27;
  }
  return 1;
}

// File Line: 8506
// RVA: 0x3552E0
void __fastcall LookAtTask::End(LookAtTask *this)
{
  AimConstraint *mHeadTrackEffector; // rcx
  AimConstraint *mRightEyeTrackEffector; // rcx
  AimConstraint *mLeftEyeTrackEffector; // rcx
  AimConstraintMultiLink *mSpineTrackEffector; // rcx

  mHeadTrackEffector = this->mHeadTrackEffector;
  if ( mHeadTrackEffector )
    mHeadTrackEffector->vfptr[1].__vecDelDtor(mHeadTrackEffector, 0);
  mRightEyeTrackEffector = this->mRightEyeTrackEffector;
  if ( mRightEyeTrackEffector )
    mRightEyeTrackEffector->vfptr[1].__vecDelDtor(mRightEyeTrackEffector, 0);
  mLeftEyeTrackEffector = this->mLeftEyeTrackEffector;
  if ( mLeftEyeTrackEffector )
    mLeftEyeTrackEffector->vfptr[1].__vecDelDtor(mLeftEyeTrackEffector, 0);
  mSpineTrackEffector = this->mSpineTrackEffector;
  if ( mSpineTrackEffector )
    mSpineTrackEffector->vfptr[1].__vecDelDtor(mSpineTrackEffector, 0);
}

// File Line: 8534
// RVA: 0x348B00
void __fastcall TestPathToTargetTask::Begin(TestPathToTargetTask *this, ActionContext *context)
{
  UFG::SimObjectCharacter *m_pPointer; // rdi
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0> *p_m_AIEntityComponent; // r9
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rax

  this->m_pActionContext = context;
  m_pPointer = (UFG::SimObjectCharacter *)context->mSimObject.m_pPointer;
  UFG::RebindingComponentHandle<UFG::NavComponent,0>::Bind<UFG::SimObjectCharacter>(&this->m_navComponent, m_pPointer);
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>::Bind<UFG::SimObjectCharacter>(
    &this->m_targetingSysComponent,
    m_pPointer);
  p_m_AIEntityComponent = &this->m_AIEntityComponent;
  if ( this->m_AIEntityComponent.m_pSimComponent )
  {
    mPrev = p_m_AIEntityComponent->mPrev;
    mNext = this->m_AIEntityComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->m_AIEntityComponent.m_pSimComponent = 0i64;
LABEL_7:
    this->m_AIEntityComponent.m_pSimObject = 0i64;
    this->m_AIEntityComponent.mNext = &this->m_AIEntityComponent;
    p_m_AIEntityComponent->mPrev = p_m_AIEntityComponent;
    goto LABEL_8;
  }
  if ( this->m_AIEntityComponent.m_pSimObject
    && (p_m_AIEntityComponent->mPrev != p_m_AIEntityComponent
     || this->m_AIEntityComponent.mNext != &this->m_AIEntityComponent) )
  {
    v7 = p_m_AIEntityComponent->mPrev;
    v8 = this->m_AIEntityComponent.mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    goto LABEL_7;
  }
LABEL_8:
  this->m_AIEntityComponent.m_Changed = 1;
  this->m_AIEntityComponent.m_pSimObject = m_pPointer;
  this->m_AIEntityComponent.m_TypeUID = UFG::ActiveAIEntityComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0>::BindInternal<UFG::SimObjectCharacter>(
    &this->m_AIEntityComponent,
    m_pPointer);
  this->m_uTimeToNextPathfind = 0i64;
  this->m_bWaitingForResult = 0;
}

// File Line: 8550
// RVA: 0x393570
char __fastcall TestPathToTargetTask::Update(TestPathToTargetTask *this, float timeDelta)
{
  UFG::SimComponent *m_pSimComponent; // r10
  UFG::DaemonOutputStatus m_status; // r11d
  unsigned int m_pSimObject; // edx
  UFG::SimObject *v6; // r9
  unsigned int v7; // ecx
  UFG::PedKnowledgeRecord *mPrev; // rax
  unsigned __int64 mSimTimeMSec; // rbx

  if ( !this->m_bWaitingForResult )
  {
    if ( this->m_uTimeToNextPathfind < UFG::Metrics::msInstance.mSimTimeMSec )
      TestPathToTargetTask::StartPathTest(this);
    return 1;
  }
  m_pSimComponent = this->m_AIEntityComponent.m_pSimComponent;
  m_status = this->m_PathQueryOutput.m_status;
  m_pSimObject = (unsigned int)m_pSimComponent[21].m_pSimObject;
  v6 = *(UFG::SimObject **)(56i64
                          * *(unsigned __int8 *)(LOBYTE(this->m_Track[1].vfptr)
                                               + *(_QWORD *)&this->m_targetingSysComponent.m_pSimComponent[1].m_Flags
                                               + 8i64)
                          + *(_QWORD *)&this->m_targetingSysComponent.m_pSimComponent[1].m_TypeUID
                          + 40);
  v7 = 0;
  if ( m_pSimObject )
  {
    mPrev = (UFG::PedKnowledgeRecord *)m_pSimComponent[21].m_BoundComponentHandles.mNode.mPrev;
    while ( v6 != mPrev->pSimObject.m_pPointer )
    {
      ++v7;
      ++mPrev;
      if ( v7 >= m_pSimObject )
        goto LABEL_6;
    }
  }
  else
  {
LABEL_6:
    mPrev = &UFG::PedKnowledgeBase::ms_defaultKnowledgeRecord;
  }
  if ( m_status == Status_Failed )
  {
    this->m_bWaitingForResult = 0;
    *((_BYTE *)mPrev + 48) &= ~4u;
  }
  else
  {
    if ( m_status != Status_Completed )
      goto LABEL_12;
    this->m_bWaitingForResult = 0;
    *((_BYTE *)mPrev + 48) |= 4u;
  }
  mPrev->m_uLastPathTest = UFG::Metrics::msInstance.mSimTimeMSec;
LABEL_12:
  if ( !this->m_bWaitingForResult )
  {
    mSimTimeMSec = UFG::Metrics::msInstance.mSimTimeMSec;
    this->m_uTimeToNextPathfind = (int)UFG::qRandom(0x514u, (unsigned int *)&UFG::qDefaultSeed) + mSimTimeMSec + 700;
    return 1;
  }
  return 1;
}

// File Line: 8592
// RVA: 0x388E40
void __fastcall TestPathToTargetTask::StartPathTest(TestPathToTargetTask *this)
{
  __int64 v2; // rcx
  UFG::TransformNodeComponent *v3; // rbp
  hkVector4f *m_pSimComponent; // rcx
  UFG::HavokNavPosition *p_m_npFrom; // rdi
  float v6; // xmm0_4
  float v7; // xmm1_4
  char v8; // al
  float z; // xmm1_4
  float y; // xmm0_4
  UFG::SimComponent *v11; // rax
  UFG::DaemonManager *v12; // rax

  v2 = *(_QWORD *)(56i64
                 * *(unsigned __int8 *)(*(_QWORD *)&this->m_targetingSysComponent.m_pSimComponent[1].m_Flags + 30i64)
                 + *(_QWORD *)&this->m_targetingSysComponent.m_pSimComponent[1].m_TypeUID
                 + 40);
  if ( v2 )
  {
    v3 = *(UFG::TransformNodeComponent **)(v2 + 88);
    if ( v3 )
    {
      m_pSimComponent = (hkVector4f *)this->m_navComponent.m_pSimComponent;
      p_m_npFrom = &this->m_PathQueryInput.m_npFrom;
      v6 = m_pSimComponent[5].m_quad.m128_f32[3];
      v7 = m_pSimComponent[6].m_quad.m128_f32[0];
      LODWORD(this->m_PathQueryInput.m_npFrom.m_vPosition.x) = m_pSimComponent[5].m_quad.m128_i32[2];
      this->m_PathQueryInput.m_npFrom.m_vPosition.y = v6;
      this->m_PathQueryInput.m_npFrom.m_vPosition.z = v7;
      v8 = m_pSimComponent[6].m_quad.m128_i8[8];
      if ( v8 )
      {
        this->m_PathQueryInput.m_npFrom.m_bValid = v8;
        this->m_PathQueryInput.m_npFrom.m_hkvMeshPosition = (hkVector4f)m_pSimComponent[7].m_quad;
        this->m_PathQueryInput.m_npFrom.m_packedKey = m_pSimComponent[8].m_quad.m128_u32[0];
        this->m_PathQueryInput.m_npFrom.m_aiMeshUid = m_pSimComponent[8].m_quad.m128_u32[1];
      }
      else
      {
        this->m_PathQueryInput.m_npFrom.m_bValid = 0;
      }
      UFG::TransformNodeComponent::UpdateWorldTransform(v3);
      z = v3->mWorldTransform.v3.z;
      y = v3->mWorldTransform.v3.y;
      this->m_PathQueryInput.m_npTo.m_vPosition.x = v3->mWorldTransform.v3.x;
      this->m_PathQueryInput.m_npTo.m_vPosition.z = z;
      this->m_PathQueryInput.m_npTo.m_vPosition.y = y;
      this->m_PathQueryInput.m_npTo.m_bValid = 0;
      ((void (__fastcall *)(UFG::HavokNavPosition *))p_m_npFrom->vfptr->Validate)(&this->m_PathQueryInput.m_npFrom);
      ((void (__fastcall *)(UFG::HavokNavPosition *))this->m_PathQueryInput.m_npTo.vfptr->Validate)(&this->m_PathQueryInput.m_npTo);
      v11 = this->m_navComponent.m_pSimComponent;
      this->m_PathQueryInput.m_maxSearchIterations = -1;
      this->m_PathQueryInput.m_pNavParams = (UFG::NavParams *)((char *)&v11[2].m_BoundComponentHandles.mNode.mNext + 4);
      if ( p_m_npFrom->vfptr->IsMeshPositionValid(&this->m_PathQueryInput.m_npFrom) )
      {
        v12 = UFG::DaemonManager::Instance();
        UFG::DaemonManager::SubmitQuery(v12, &this->m_PathQueryInput, &this->m_PathQueryOutput);
        this->m_bWaitingForResult = 1;
      }
    }
  }
}

// File Line: 8619
// RVA: 0x355570
void __fastcall TestPathToTargetTask::End(TestPathToTargetTask *this)
{
  UFG::FindPathDeferredQuery *p_m_PathQueryInput; // rbx
  UFG::DaemonManager *v2; // rax

  p_m_PathQueryInput = &this->m_PathQueryInput;
  v2 = UFG::DaemonManager::Instance();
  UFG::DaemonManager::CancelQuery(v2, p_m_PathQueryInput);
}

