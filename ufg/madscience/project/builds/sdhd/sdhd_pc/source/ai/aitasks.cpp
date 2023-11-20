// File Line: 102
// RVA: 0x360EF0
UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *__fastcall GetNextPathNode(UFG::TransformNodeComponent *pNode, UFG::AIMarker **ppNextMarker)
{
  UFG::TransformNodeComponent *v2; // rax
  UFG::AIMarker **v3; // rsi
  UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *v4; // rdi
  UFG::SimObjectGame *v5; // rbx
  UFG::SimComponent *v6; // rax
  unsigned __int16 v8; // cx
  UFG::SimComponent *v9; // rax

  *ppNextMarker = 0i64;
  v2 = pNode->mParent;
  v3 = ppNextMarker;
  if ( !v2 )
    return 0i64;
  v4 = pNode->mNext - 4;
  if ( v4 == (UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *)&v2->m_SafePointerList.mNode.mNext )
    return 0i64;
  v5 = (UFG::SimObjectGame *)v4[2].mNext;
  if ( !v5 )
    return 0i64;
  v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)v4[2].mNext, UFG::AIMarker::_TypeUID);
  if ( v6 )
  {
    *v3 = (UFG::AIMarker *)v6;
    return v4;
  }
  v8 = v5->m_Flags;
  if ( (v8 >> 14) & 1 )
  {
    v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::MarkerBase::_TypeUID);
  }
  else if ( (v8 & 0x8000u) == 0 )
  {
    if ( (v8 >> 13) & 1 )
      v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::MarkerBase::_TypeUID);
    else
      v9 = (v8 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::MarkerBase::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v5->vfptr, UFG::MarkerBase::_TypeUID);
  }
  else
  {
    v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::MarkerBase::_TypeUID);
  }
  if ( !v9 )
    return 0i64;
  *v3 = 0i64;
  return v4;
}

// File Line: 134
// RVA: 0x389390
void __fastcall SubmitPathPoints(UFG::NavComponent *pNC, __int64 pathName)
{
  UFG::NavComponent *v2; // rsi
  UFG::qBaseTreeRB *v3; // rax
  UFG::qBaseTreeRB *v4; // rbx
  char *v5; // rax
  __int64 v6; // rdi
  char v7; // bp
  float v8; // xmm7_4
  UFG::SimObject *v9; // rcx
  UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *v10; // rdi
  UFG::AIMarker *v11; // rbx
  float fDestinationTolerance; // xmm6_4
  int v13; // eax
  UFG::AiPathGoalMode v14; // er8
  __m128 v15; // xmm3
  __m128 v16; // xmm2
  __m128 v17; // xmm0
  UFG::HavokNavPosition npDestination; // [rsp+30h] [rbp-A8h]
  UFG::AIMarker *ppNextMarker; // [rsp+F0h] [rbp+18h]

  v2 = pNC;
  v3 = UFG::MarkerBase::GetNamed((UFG::qSymbol *)pathName);
  v4 = v3;
  if ( v3 )
  {
    v5 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)v3->mNULL.mChild[0][2].mChild);
    UFG::qPrintf("PathBegin (%s)\n", v5);
    v6 = *(_QWORD *)&v4[1].mNULL.mParent[2].mUID;
    v7 = 1;
    v8 = FLOAT_N1_0;
    v9 = *(UFG::SimObject **)(v6 - 24);
    v10 = (UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *)(v6 - 64);
    if ( v9 )
    {
      v11 = (UFG::AIMarker *)UFG::SimObject::GetComponentOfType(v9, UFG::AIMarker::_TypeUID);
      ppNextMarker = v11;
    }
    else
    {
      v11 = 0i64;
      ppNextMarker = 0i64;
    }
    while ( 1 )
    {
      fDestinationTolerance = FLOAT_N1_0;
      if ( v11 )
      {
        fDestinationTolerance = UFG::AIMarker::GetArrivalTolerance(v11, v11->m_pSimObject);
        v13 = UFG::AIMarker::GetMoveType(v11, v11->m_pSimObject);
        if ( v13 )
          v8 = sNaturalMovementSpeeds[v13];
      }
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v10);
      v14 = 2;
      v15 = (__m128)LODWORD(v10[11].mPrev);
      v16 = (__m128)HIDWORD(v10[11].mPrev);
      v17 = (__m128)LODWORD(v10[11].mNext);
      if ( v7 )
        v14 = 0;
      npDestination.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
      npDestination.m_bValid = 0;
      LODWORD(npDestination.m_vPosition.x) = v15.m128_i32[0];
      LODWORD(npDestination.m_vPosition.y) = v16.m128_i32[0];
      LODWORD(npDestination.m_vPosition.z) = v17.m128_i32[0];
      *(_QWORD *)&npDestination.m_packedKey = -1i64;
      npDestination.m_hkvMeshPosition.m_quad = _mm_unpacklo_ps(
                                                 _mm_unpacklo_ps(v15, v17),
                                                 _mm_unpacklo_ps(v16, (__m128)(unsigned int)FLOAT_1_0));
      UFG::NavComponent::AddGoalPoint(v2, &npDestination, v14, v8, fDestinationTolerance);
      v7 = 0;
      v10 = GetNextPathNode((UFG::TransformNodeComponent *)v10, &ppNextMarker);
      if ( !v10 )
        break;
      v11 = ppNextMarker;
    }
  }
}

// File Line: 182
// RVA: 0x3479F0
void __fastcall PerformScriptCommandTask::Begin(PerformScriptCommandTask *this, ActionContext *context)
{
  PerformScriptCommandTask *v2; // rdi
  UFG::SimObjectCVBase *v3; // rcx
  UFG::SimComponent *v4; // rbx
  ActionContext *v5; // rsi
  UFG::ActiveAIEntityComponent *v6; // r8
  unsigned __int16 v7; // dx
  UFG::ActiveAIEntityComponent *v8; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v9; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::SimObjectGame *v13; // rcx
  UFG::SimComponent *v14; // r8
  unsigned __int16 v15; // dx
  UFG::SimComponent *v16; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AIScriptInterfaceComponent> *v17; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rax
  UFG::SimObject *v21; // rcx
  UFG::SimComponent *v22; // rax
  unsigned __int16 v23; // dx
  UFG::qSafePointer<UFG::SimComponent,UFG::TSActorComponent> *v24; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v25; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v26; // rcx
  UFG::qList<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList,1,0> *v27; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v28; // rax
  UFG::SimObjectGame *v29; // rcx
  unsigned __int16 v30; // dx
  UFG::SimComponent *v31; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActionTreeComponent> *v32; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v33; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v34; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v35; // rax
  UFG::TSActorComponent *v36; // rcx
  UFG::TSActor *v37; // rax
  ActionController *v38; // rdx
  UFG::qNode<IFinishUpdate,IFinishUpdate> *v39; // rcx
  UFG::qNode<IFinishUpdate,IFinishUpdate> *v40; // rax
  UFG::SimComponent *v41; // rax

  v2 = this;
  this->m_pActionContext = context;
  v3 = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  v4 = 0i64;
  v5 = context;
  if ( v3 )
  {
    v7 = v3->m_Flags;
    if ( (v7 >> 14) & 1 )
    {
      v8 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v3);
    }
    else if ( (v7 & 0x8000u) == 0 )
    {
      if ( (v7 >> 13) & 1 )
      {
        v8 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               (UFG::SimObjectGame *)&v3->vfptr,
                                               UFG::ActiveAIEntityComponent::_TypeUID);
      }
      else if ( (v7 >> 12) & 1 )
      {
        v8 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               (UFG::SimObjectGame *)&v3->vfptr,
                                               UFG::ActiveAIEntityComponent::_TypeUID);
      }
      else
      {
        v8 = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                               (UFG::SimObject *)&v3->vfptr,
                                               UFG::ActiveAIEntityComponent::_TypeUID);
      }
    }
    else
    {
      v8 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v3);
    }
    v6 = v8;
  }
  else
  {
    v6 = 0i64;
  }
  v9 = &v2->m_pAIEntityComponent;
  if ( v2->m_pAIEntityComponent.m_pPointer )
  {
    v10 = v9->mPrev;
    v11 = v2->m_pAIEntityComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    v9->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
    v2->m_pAIEntityComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pAIEntityComponent.mPrev;
  }
  v2->m_pAIEntityComponent.m_pPointer = (UFG::SimComponent *)&v6->vfptr;
  if ( v6 )
  {
    v12 = v6->m_SafePointerList.mNode.mPrev;
    v12->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
    v9->mPrev = v12;
    v2->m_pAIEntityComponent.mNext = &v6->m_SafePointerList.mNode;
    v6->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
  }
  v13 = (UFG::SimObjectGame *)v5->mSimObject.m_pPointer;
  if ( v13 )
  {
    v15 = v13->m_Flags;
    if ( (v15 >> 14) & 1 )
    {
      v14 = v13->m_Components.p[5].m_pComponent;
    }
    else if ( (v15 & 0x8000u) == 0 )
    {
      if ( (v15 >> 13) & 1 )
      {
        v16 = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::AIScriptInterfaceComponent::_TypeUID);
      }
      else if ( (v15 >> 12) & 1 )
      {
        v16 = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::AIScriptInterfaceComponent::_TypeUID);
      }
      else
      {
        v16 = UFG::SimObject::GetComponentOfType(
                (UFG::SimObject *)&v13->vfptr,
                UFG::AIScriptInterfaceComponent::_TypeUID);
      }
      v14 = v16;
    }
    else
    {
      v14 = v13->m_Components.p[5].m_pComponent;
    }
  }
  else
  {
    v14 = 0i64;
  }
  v17 = &v2->m_pAIScriptInterfaceComponent;
  if ( v2->m_pAIScriptInterfaceComponent.m_pPointer )
  {
    v18 = v17->mPrev;
    v19 = v2->m_pAIScriptInterfaceComponent.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    v17->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v17->mPrev;
    v2->m_pAIScriptInterfaceComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pAIScriptInterfaceComponent.mPrev;
  }
  v2->m_pAIScriptInterfaceComponent.m_pPointer = v14;
  if ( v14 )
  {
    v20 = v14->m_SafePointerList.mNode.mPrev;
    v20->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v17->mPrev;
    v17->mPrev = v20;
    v2->m_pAIScriptInterfaceComponent.mNext = &v14->m_SafePointerList.mNode;
    v14->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v17->mPrev;
  }
  v21 = v5->mSimObject.m_pPointer;
  if ( v21 )
  {
    v23 = v21->m_Flags;
    if ( (v23 >> 14) & 1 )
    {
      v22 = v21->m_Components.p[4].m_pComponent;
    }
    else if ( (v23 & 0x8000u) == 0 )
    {
      if ( (v23 >> 13) & 1 )
      {
        v22 = v21->m_Components.p[3].m_pComponent;
      }
      else if ( (v23 >> 12) & 1 )
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
  v24 = &v2->m_pActorComponent;
  if ( v2->m_pActorComponent.m_pPointer )
  {
    v25 = v24->mPrev;
    v26 = v2->m_pActorComponent.mNext;
    v25->mNext = v26;
    v26->mPrev = v25;
    v24->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v24->mPrev;
    v2->m_pActorComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pActorComponent.mPrev;
  }
  v2->m_pActorComponent.m_pPointer = v22;
  if ( v22 )
  {
    v27 = &v22->m_SafePointerList;
    v28 = v22->m_SafePointerList.mNode.mPrev;
    v28->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v24->mPrev;
    v24->mPrev = v28;
    v2->m_pActorComponent.mNext = &v27->mNode;
    v27->mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v24->mPrev;
  }
  v29 = (UFG::SimObjectGame *)v5->mSimObject.m_pPointer;
  if ( v29 )
  {
    v30 = v29->m_Flags;
    if ( (v30 >> 14) & 1 )
    {
      v4 = v29->m_Components.p[7].m_pComponent;
    }
    else if ( (v30 & 0x8000u) == 0 )
    {
      if ( (v30 >> 13) & 1 )
      {
        v4 = v29->m_Components.p[6].m_pComponent;
      }
      else
      {
        if ( (v30 >> 12) & 1 )
          v31 = UFG::SimObjectGame::GetComponentOfTypeHK(v29, UFG::ActionTreeComponent::_TypeUID);
        else
          v31 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v29->vfptr, UFG::ActionTreeComponent::_TypeUID);
        v4 = v31;
      }
    }
    else
    {
      v4 = v29->m_Components.p[7].m_pComponent;
    }
  }
  v32 = &v2->m_pActionTreeComponent;
  if ( v2->m_pActionTreeComponent.m_pPointer )
  {
    v33 = v32->mPrev;
    v34 = v2->m_pActionTreeComponent.mNext;
    v33->mNext = v34;
    v34->mPrev = v33;
    v32->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v32->mPrev;
    v2->m_pActionTreeComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pActionTreeComponent.mPrev;
  }
  v2->m_pActionTreeComponent.m_pPointer = v4;
  if ( v4 )
  {
    v35 = v4->m_SafePointerList.mNode.mPrev;
    v35->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v32->mPrev;
    v32->mPrev = v35;
    v2->m_pActionTreeComponent.mNext = &v4->m_SafePointerList.mNode;
    v4->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v32->mPrev;
  }
  v36 = (UFG::TSActorComponent *)v2->m_pActorComponent.m_pPointer;
  if ( v36 && UFG::TSActorComponent::GetActor(v36) )
  {
    v37 = UFG::TSActorComponent::GetActor((UFG::TSActorComponent *)v2->m_pActorComponent.m_pPointer);
    v37->i_actor_flags |= 4u;
  }
  v38 = v5->mActionController;
  v39 = (UFG::qNode<IFinishUpdate,IFinishUpdate> *)&v2->mPrev;
  v40 = v38->m_FinishUpdateTasks.mNode.mPrev;
  v38 = (ActionController *)((char *)v38 + 120);
  v40->mNext = (UFG::qNode<IFinishUpdate,IFinishUpdate> *)&v2->mPrev;
  v39->mPrev = v40;
  v39->mNext = (UFG::qNode<IFinishUpdate,IFinishUpdate> *)v38;
  v38->vfptr = (Expression::IMemberMapVtbl *)&v2->mPrev;
  v41 = v2->m_pAIScriptInterfaceComponent.m_pPointer;
  if ( v41 )
    BYTE1(v41[32].m_BoundComponentHandles.mNode.mPrev) &= 0x7Fu;
}

// File Line: 204
// RVA: 0x3919A0
bool __fastcall PerformScriptCommandTask::Update(PerformScriptCommandTask *this, float timeDelta)
{
  PerformScriptCommandTask *v2; // rdi
  UFG::SimComponent *v3; // rdx
  UFG::SimComponent *v4; // r8
  UFG::NavComponent *v5; // rbx
  UFG::SimObjectGame *v6; // rcx
  UFG::NavComponent *v7; // rcx
  unsigned __int16 v8; // dx
  UFG::SimComponent *v9; // rax
  unsigned int v10; // eax
  float v11; // xmm6_4
  UFG::SimObjectGame *v12; // rcx
  unsigned __int16 v13; // dx
  unsigned int v14; // edx
  UFG::SimComponent *v15; // rax
  bool v16; // zf
  unsigned __int16 v17; // dx
  UFG::CharacterControllerInterface *v18; // rcx
  const char *v19; // rbp
  const char *v20; // rsi
  bool v21; // bl
  unsigned __int8 v22; // al
  UFG::SimComponent *v23; // rdx
  UFG::SimObjectCVBase *v24; // rcx
  UFG::AICharacterControllerBaseComponent *v25; // rbx
  unsigned __int16 v26; // dx
  UFG::AICharacterControllerBaseComponent *v27; // rax
  unsigned int v28; // edx
  UFG::SimObjectCVBase *v29; // rcx
  unsigned __int16 v30; // dx
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
  unsigned __int16 v43; // dx
  UFG::AICharacterControllerBaseComponent *v44; // rax
  UFG::AICharacterControllerBaseComponent *v45; // rsi
  UFG::TransformNodeComponent *v46; // rbx
  float v47; // xmm6_4
  float v48; // xmm8_4
  __m128 v49; // xmm3
  float v50; // xmm2_4
  float v51; // xmm0_4
  ActionID v53; // [rsp+20h] [rbp-88h]
  __int64 v54; // [rsp+28h] [rbp-80h]
  UFG::qString v55; // [rsp+30h] [rbp-78h]
  UFG::qSymbol pathName; // [rsp+B0h] [rbp+8h]
  UFG::qSymbol *action_request; // [rsp+C0h] [rbp+18h]
  ActionID node_id; // [rsp+C8h] [rbp+20h]

  v54 = -2i64;
  v2 = this;
  v3 = this->m_pAIScriptInterfaceComponent.m_pPointer;
  if ( v3 )
  {
    if ( v3[1].m_TypeUID )
    {
      v4 = this->m_pAIEntityComponent.m_pPointer;
      if ( v4 )
      {
        switch ( v3[1].m_TypeUID )
        {
          case 1u:
          case 2u:
            v11 = *((float *)&v3[1].m_BoundComponentHandles.mNode.mNext + 1);
            v12 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
            if ( !v12 )
            {
              v5 = 0i64;
              goto LABEL_29;
            }
            v17 = v12->m_Flags;
            if ( (v17 >> 14) & 1 )
              goto LABEL_21;
            if ( (v17 & 0x8000u) != 0 || (v17 >> 13) & 1 )
              goto LABEL_23;
            v16 = ((v17 >> 12) & 1) == 0;
            v14 = UFG::NavComponent::_TypeUID;
            if ( v16 )
              goto LABEL_27;
            goto LABEL_24;
          case 3u:
            v5 = 0i64;
            if ( SBYTE1(v3[32].m_BoundComponentHandles.mNode.mPrev) >= 0 )
            {
              v6 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
              if ( v6 )
              {
                v8 = v6->m_Flags;
                if ( (v8 >> 14) & 1 )
                {
                  v7 = (UFG::NavComponent *)v6->m_Components.p[36].m_pComponent;
                }
                else
                {
                  if ( (v8 & 0x8000u) == 0 )
                  {
                    if ( (v8 >> 13) & 1 )
                    {
                      v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::NavComponent::_TypeUID);
                    }
                    else if ( (v8 >> 12) & 1 )
                    {
                      v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::NavComponent::_TypeUID);
                    }
                    else
                    {
                      v9 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v6->vfptr, UFG::NavComponent::_TypeUID);
                    }
                  }
                  else
                  {
                    v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::NavComponent::_TypeUID);
                  }
                  v7 = (UFG::NavComponent *)v9;
                }
              }
              else
              {
                v7 = 0i64;
              }
              v10 = (unsigned int)v2->m_pAIScriptInterfaceComponent.m_pPointer[3].m_SafePointerList.mNode.mPrev;
              action_request = &pathName;
              pathName.mUID = v10;
              SubmitPathPoints(v7, (__int64)&pathName);
              BYTE1(v2->m_pAIScriptInterfaceComponent.m_pPointer[32].m_BoundComponentHandles.mNode.mPrev) |= 0x80u;
            }
            v11 = *((float *)&v2->m_pAIScriptInterfaceComponent.m_pPointer[1].m_BoundComponentHandles.mNode.mNext + 1);
            v12 = (UFG::SimObjectGame *)v2->m_pActionContext->mSimObject.m_pPointer;
            if ( !v12 )
              goto LABEL_29;
            v13 = v12->m_Flags;
            if ( (v13 >> 14) & 1 )
            {
LABEL_21:
              v5 = (UFG::NavComponent *)v12->m_Components.p[36].m_pComponent;
              goto LABEL_29;
            }
            if ( (v13 & 0x8000u) != 0 || (v13 >> 13) & 1 )
            {
LABEL_23:
              v14 = UFG::NavComponent::_TypeUID;
            }
            else
            {
              v16 = ((v13 >> 12) & 1) == 0;
              v14 = UFG::NavComponent::_TypeUID;
              if ( v16 )
              {
LABEL_27:
                v15 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v12->vfptr, v14);
LABEL_28:
                v5 = (UFG::NavComponent *)v15;
LABEL_29:
                UFG::NavComponent::SetDesiredSpeed(v5, v11);
                return 1;
              }
            }
LABEL_24:
            v15 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, v14);
            goto LABEL_28;
          case 4u:
            v18 = (UFG::CharacterControllerInterface *)v4[24].m_BoundComponentHandles.mNode.mPrev;
            if ( v18 )
              UFG::CharacterControllerInterface::PlayActionNode(
                v18,
                (const char *)v3[1].m_BoundComponentHandles.mNode.mPrev);
            return 1;
          case 5u:
            v19 = (const char *)v3[1].m_BoundComponentHandles.mNode.mPrev;
            v20 = (const char *)v3[2].m_BoundComponentHandles.mNode.mNext;
            v21 = LODWORD(v3[4].m_SafePointerList.mNode.mPrev) == 1;
            UFG::qString::qString(&v55);
            if ( !((_QWORD)v2->m_pAIScriptInterfaceComponent.m_pPointer[32].m_BoundComponentHandles.mNode.mPrev & 2) )
            {
              node_id.mUID = UFG::qStringHashUpper32(v20, 0xFFFFFFFF);
              v22 = ActionController::IsPlaying(
                      (ActionController *)&v2->m_pActionTreeComponent.m_pPointer[3],
                      &node_id,
                      0xFFFFFFFF,
                      1);
              v23 = v2->m_pAIScriptInterfaceComponent.m_pPointer;
              LOBYTE(v23[32].m_BoundComponentHandles.mNode.mPrev) &= 0xFDu;
              LOBYTE(v23[32].m_BoundComponentHandles.mNode.mPrev) |= 2 * (v22 & 1);
            }
            if ( (_QWORD)v2->m_pAIScriptInterfaceComponent.m_pPointer[32].m_BoundComponentHandles.mNode.mPrev & 2 )
            {
              if ( !v21
                || (v53.mUID = UFG::qStringHashUpper32(v20, 0xFFFFFFFF),
                    !ActionController::IsPlaying(
                       (ActionController *)&v2->m_pActionTreeComponent.m_pPointer[3],
                       &v53,
                       0xFFFFFFFF,
                       1)) )
              {
                LOBYTE(v2->m_pAIScriptInterfaceComponent.m_pPointer[32].m_BoundComponentHandles.mNode.mPrev) |= 4u;
              }
LABEL_58:
              UFG::qString::~qString(&v55);
              return 1;
            }
            LODWORD(action_request) = gActionRequest_Action.m_EnumValue;
            if ( !Intention::GetActionRequest(v19, (unsigned int *)&action_request) )
              goto LABEL_58;
            v24 = (UFG::SimObjectCVBase *)v2->m_pActionContext->mSimObject.m_pPointer;
            if ( !v24 )
            {
              v25 = 0i64;
LABEL_54:
              Intention::Set(&v25->m_Intention, (unsigned int)action_request, 0.0);
              goto LABEL_58;
            }
            v26 = v24->m_Flags;
            if ( (v26 >> 14) & 1 || (v26 & 0x8000u) != 0 )
            {
              v27 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v24);
            }
            else
            {
              if ( (v26 >> 13) & 1 )
              {
                v28 = UFG::AICharacterControllerBaseComponent::_TypeUID;
              }
              else
              {
                v16 = ((v26 >> 12) & 1) == 0;
                v28 = UFG::AICharacterControllerBaseComponent::_TypeUID;
                if ( v16 )
                {
                  v27 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                                     (UFG::SimObject *)&v24->vfptr,
                                                                     UFG::AICharacterControllerBaseComponent::_TypeUID);
                  goto LABEL_53;
                }
              }
              v27 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                 (UFG::SimObjectGame *)&v24->vfptr,
                                                                 v28);
            }
LABEL_53:
            v25 = v27;
            goto LABEL_54;
          case 6u:
            v29 = (UFG::SimObjectCVBase *)this->m_pActionContext->mSimObject.m_pPointer;
            if ( v29 )
            {
              v30 = v29->m_Flags;
              if ( (v30 >> 14) & 1 )
              {
                v31 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v29);
              }
              else if ( (v30 & 0x8000u) == 0 )
              {
                if ( (v30 >> 13) & 1 )
                  v31 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                     (UFG::SimObjectGame *)&v29->vfptr,
                                                                     UFG::AICharacterControllerBaseComponent::_TypeUID);
                else
                  v31 = (UFG::AICharacterControllerBaseComponent *)((v30 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                                        (UFG::SimObjectGame *)&v29->vfptr,
                                                                                        UFG::AICharacterControllerBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v29->vfptr, UFG::AICharacterControllerBaseComponent::_TypeUID));
              }
              else
              {
                v31 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v29);
              }
              if ( v31 )
              {
                v32 = *(float *)(&v2->m_pAIScriptInterfaceComponent.m_pPointer[1].m_SimObjIndex + 1);
                v33 = (__m128)*(unsigned int *)&v2->m_pAIScriptInterfaceComponent.m_pPointer[1].m_Flags;
                v34 = *(float *)&v2->m_pAIScriptInterfaceComponent.m_pPointer[1].m_pSimObject;
                v35 = v33;
                v35.m128_f32[0] = (float)((float)(v33.m128_f32[0] * v33.m128_f32[0]) + (float)(v32 * v32))
                                + (float)(v34 * v34);
                v36 = 0.0;
                if ( v35.m128_f32[0] != 0.0 )
                  v36 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v35));
                v31->m_Intention.mMotionIntentionDirection.x = v33.m128_f32[0] * v36;
                v31->m_Intention.mMotionIntentionDirection.y = v32 * v36;
                v31->m_Intention.mMotionIntentionDirection.z = v34 * v36;
              }
            }
            return 1;
          case 7u:
            v37 = *(_DWORD *)&v3[2].m_Flags;
            if ( v37 == 1 )
            {
              v38 = *(float *)&v3[1].m_Flags;
              v39 = (__m128)*(unsigned int *)(&v3[1].m_SimObjIndex + 1);
              v40 = *(float *)&v3[1].m_pSimObject;
            }
            else
            {
              if ( v37 != 6 )
                return 1;
              v41 = *(_QWORD *)&v3[2].m_TypeUID;
              if ( !v41 )
                return 1;
              UFG::TransformNodeComponent::UpdateWorldTransform(*(UFG::TransformNodeComponent **)&v3[2].m_TypeUID);
              v38 = *(float *)(v41 + 176);
              v39 = (__m128)*(unsigned int *)(v41 + 180);
              v40 = *(float *)(v41 + 184);
            }
            v42 = (UFG::SimObjectCVBase *)v2->m_pActionContext->mSimObject.m_pPointer;
            if ( v42 )
            {
              v43 = v42->m_Flags;
              if ( (v43 >> 14) & 1 )
              {
                v44 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v42);
              }
              else if ( (v43 & 0x8000u) == 0 )
              {
                if ( (v43 >> 13) & 1 )
                  v44 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                     (UFG::SimObjectGame *)&v42->vfptr,
                                                                     UFG::AICharacterControllerBaseComponent::_TypeUID);
                else
                  v44 = (UFG::AICharacterControllerBaseComponent *)((v43 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                                        (UFG::SimObjectGame *)&v42->vfptr,
                                                                                        UFG::AICharacterControllerBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v42->vfptr, UFG::AICharacterControllerBaseComponent::_TypeUID));
              }
              else
              {
                v44 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v42);
              }
              v45 = v44;
              if ( v44 )
              {
                v46 = (UFG::TransformNodeComponent *)v2->m_pActionContext->mSimObject.m_pPointer;
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
                  v50 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v49));
                v45->m_Intention.mMotionIntentionDirection.x = v47 * v50;
                v45->m_Intention.mMotionIntentionDirection.y = v39.m128_f32[0] * v50;
                v45->m_Intention.mMotionIntentionDirection.z = v48 * v50;
                v51 = FLOAT_0_0099999998;
                if ( v45->m_Intention.mMotionIntentionSpeed >= 0.0099999998 )
                  v51 = v45->m_Intention.mMotionIntentionSpeed;
                v45->m_Intention.mMotionIntentionSpeed = v51;
              }
            }
            return 1;
          default:
            return 1;
        }
      }
    }
    else if ( v3 )
    {
      return HIDWORD(v3[1].m_SafePointerList.mNode.mNext) != 0;
    }
  }
  return 0;
}eturn HIDWORD(v3[1].m_SafePointerList.mNode.mNext) != 0;
    }
  }
  return 0;
}

// File Line: 466
// RVA: 0x3581A0
void __fastcall PerformScriptCommandTask::FinishUpdate(PerformScriptCommandTask *this)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v1; // rax

  v1 = this->m_pAIEntityComponent.mPrev;
  if ( v1 )
  {
    LODWORD(v1[5].mNext) = 0;
    LODWORD(v1[28].mNext) = 0;
  }
}

// File Line: 487
// RVA: 0x3553E0
void __fastcall PerformScriptCommandTask::End(PerformScriptCommandTask *this)
{
  UFG::SimComponent *v1; // rax
  PerformScriptCommandTask *v2; // rbx
  UFG::SimComponent *v3; // rax
  UFG::TSActorComponent *v4; // rcx
  UFG::TSActor *v5; // rax
  UFG::qNode<IFinishUpdate,IFinishUpdate> *v6; // rcx
  UFG::qNode<IFinishUpdate,IFinishUpdate> *v7; // rax
  UFG::qNode<IFinishUpdate,IFinishUpdate> *v8; // rdx

  v1 = this->m_pAIEntityComponent.m_pPointer;
  v2 = this;
  if ( v1 )
    LODWORD(v1[13].m_pSimObject) = -1;
  v3 = this->m_pAIScriptInterfaceComponent.m_pPointer;
  if ( v3 )
  {
    v3[1].m_TypeUID = 0;
    LODWORD(v3[7].m_SafePointerList.mNode.mPrev) = 0;
    BYTE1(this->m_pAIScriptInterfaceComponent.m_pPointer[32].m_BoundComponentHandles.mNode.mPrev) &= 0x7Fu;
  }
  v4 = (UFG::TSActorComponent *)this->m_pActorComponent.m_pPointer;
  if ( v4
    && UFG::TSActorComponent::GetActor(v4)
    && (LODWORD(UFG::TSActorComponent::GetActor((UFG::TSActorComponent *)v2->m_pActorComponent.m_pPointer)[1].vfptr) >> 2) & 1 )
  {
    v5 = UFG::TSActorComponent::GetActor((UFG::TSActorComponent *)v2->m_pActorComponent.m_pPointer);
    v5->i_actor_flags &= 0xFFFFFFFB;
  }
  v6 = v2->mPrev;
  v7 = v2->mNext;
  v8 = (UFG::qNode<IFinishUpdate,IFinishUpdate> *)&v2->mPrev;
  v6->mNext = v7;
  v7->mPrev = v6;
  v8->mPrev = v8;
  v8->mNext = v8;
}

// File Line: 548
// RVA: 0x332AA0
void __fastcall WanderTask::WanderTask(WanderTask *this)
{
  WanderTask *v1; // rbx
  UFG::qNode<ITask,ITask> *v2; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v3; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::NavComponent> *v6; // [rsp+48h] [rbp+10h]

  v1 = this;
  v2 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<WanderTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&WanderTask::`vftable;
  v3 = &this->m_pAIEntityComponent;
  v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  this->m_pAIEntityComponent.m_pPointer = 0i64;
  v6 = &this->m_pAINavComponent;
  v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  v6->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  this->m_pAINavComponent.m_pPointer = 0i64;
  this->m_pActionContext = 0i64;
  if ( this->m_pAIEntityComponent.m_pPointer )
  {
    v4 = v3->mPrev;
    v5 = v3->mNext;
    v4->mNext = v5;
    v5->mPrev = v4;
    v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
    v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  }
  v3->m_pPointer = 0i64;
  *(_QWORD *)&v1->m_iGoalIdCounter = 0i64;
  v1->m_maxWaitOnStuck = UFG::qRandom(1.0, &UFG::qDefaultSeed) + 2.0;
}

// File Line: 559
// RVA: 0x33B980
void __fastcall WanderTask::~WanderTask(WanderTask *this)
{
  WanderTask *v1; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::NavComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<ITask,ITask> *v12; // rdx
  UFG::qNode<ITask,ITask> *v13; // rcx
  UFG::qNode<ITask,ITask> *v14; // rax

  v1 = this;
  this->vfptr = (ITaskVtbl *)&WanderTask::`vftable;
  v2 = &this->m_pAINavComponent;
  if ( this->m_pAINavComponent.m_pPointer )
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
  v7 = &v1->m_pAIEntityComponent;
  if ( v1->m_pAIEntityComponent.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v1->m_pAIEntityComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v1->m_pAIEntityComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pAIEntityComponent.mPrev;
  }
  v1->m_pAIEntityComponent.m_pPointer = 0i64;
  v10 = v7->mPrev;
  v11 = v1->m_pAIEntityComponent.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v1->m_pAIEntityComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pAIEntityComponent.mPrev;
  v1->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v12 = (UFG::qNode<ITask,ITask> *)&v1->mPrev;
  v13 = v1->mPrev;
  v14 = v1->mNext;
  v13->mNext = v14;
  v14->mPrev = v13;
  v12->mPrev = v12;
  v12->mNext = v12;
}

// File Line: 565
// RVA: 0x394840
void __fastcall WanderTask::UpdateCrosswalkUsable(WanderTask *this)
{
  WanderTask *v1; // rbx
  UFG::SimComponent *v2; // rax
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rax
  unsigned int v5; // edx
  bool v6; // zf

  v1 = this;
  v2 = this->m_pAIEntityComponent.m_pPointer;
  if ( HIBYTE(v2[20].m_BoundComponentHandles.mNode.mPrev) && LocalPlayer )
  {
    v3 = LocalPlayer->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = LocalPlayer->m_Components.p[44].m_pComponent;
    }
    else
    {
      if ( (v3 & 0x8000u) != 0 || (v3 >> 13) & 1 )
      {
        v5 = UFG::CharacterOccupantComponent::_TypeUID;
      }
      else
      {
        v6 = ((v3 >> 12) & 1) == 0;
        v5 = UFG::CharacterOccupantComponent::_TypeUID;
        if ( v6 )
        {
          v4 = UFG::SimObject::GetComponentOfType(
                 (UFG::SimObject *)&LocalPlayer->vfptr,
                 UFG::CharacterOccupantComponent::_TypeUID);
          goto LABEL_11;
        }
      }
      v4 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&LocalPlayer->vfptr, v5);
    }
LABEL_11:
    LOBYTE(v1->m_pAIEntityComponent.m_pPointer[12].m_SafePointerList.mNode.mNext) = v4 == 0i64;
    return;
  }
  LOBYTE(v2[12].m_SafePointerList.mNode.mNext) = 0;
}

// File Line: 581
// RVA: 0x349020
void __fastcall WanderTask::Begin(WanderTask *this, ActionContext *action_context)
{
  WanderTask *v2; // rdi
  UFG::SimObjectCVBase *v3; // rcx
  UFG::SimComponent *v4; // rbx
  UFG::ActiveAIEntityComponent *v5; // r8
  unsigned __int16 v6; // dx
  UFG::ActiveAIEntityComponent *v7; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v8; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::SimObjectGame *v12; // rcx
  unsigned __int16 v13; // dx
  UFG::SimComponent *v14; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::NavComponent> *v15; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rax

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
        v7 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v3);
      }
      else if ( (v6 & 0x8000u) == 0 )
      {
        if ( (v6 >> 13) & 1 )
        {
          v7 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)&v3->vfptr,
                                                 UFG::ActiveAIEntityComponent::_TypeUID);
        }
        else if ( (v6 >> 12) & 1 )
        {
          v7 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)&v3->vfptr,
                                                 UFG::ActiveAIEntityComponent::_TypeUID);
        }
        else
        {
          v7 = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                 (UFG::SimObject *)&v3->vfptr,
                                                 UFG::ActiveAIEntityComponent::_TypeUID);
        }
      }
      else
      {
        v7 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v3);
      }
      v5 = v7;
    }
    else
    {
      v5 = 0i64;
    }
    v8 = &v2->m_pAIEntityComponent;
    if ( v2->m_pAIEntityComponent.m_pPointer )
    {
      v9 = v8->mPrev;
      v10 = v2->m_pAIEntityComponent.mNext;
      v9->mNext = v10;
      v10->mPrev = v9;
      v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
      v2->m_pAIEntityComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pAIEntityComponent.mPrev;
    }
    v2->m_pAIEntityComponent.m_pPointer = (UFG::SimComponent *)&v5->vfptr;
    if ( v5 )
    {
      v11 = v5->m_SafePointerList.mNode.mPrev;
      v11->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
      v8->mPrev = v11;
      v2->m_pAIEntityComponent.mNext = &v5->m_SafePointerList.mNode;
      v5->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
    }
    v12 = (UFG::SimObjectGame *)v2->m_pActionContext->mSimObject.m_pPointer;
    if ( v12 )
    {
      v13 = v12->m_Flags;
      if ( (v13 >> 14) & 1 )
      {
        v4 = v12->m_Components.p[36].m_pComponent;
      }
      else
      {
        if ( (v13 & 0x8000u) == 0 )
        {
          if ( (v13 >> 13) & 1 )
          {
            v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::NavComponent::_TypeUID);
          }
          else if ( (v13 >> 12) & 1 )
          {
            v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::NavComponent::_TypeUID);
          }
          else
          {
            v14 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v12->vfptr, UFG::NavComponent::_TypeUID);
          }
        }
        else
        {
          v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::NavComponent::_TypeUID);
        }
        v4 = v14;
      }
    }
    v15 = &v2->m_pAINavComponent;
    if ( v2->m_pAINavComponent.m_pPointer )
    {
      v16 = v15->mPrev;
      v17 = v2->m_pAINavComponent.mNext;
      v16->mNext = v17;
      v17->mPrev = v16;
      v15->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v15->mPrev;
      v2->m_pAINavComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pAINavComponent.mPrev;
    }
    v2->m_pAINavComponent.m_pPointer = v4;
    if ( v4 )
    {
      v18 = v4->m_SafePointerList.mNode.mPrev;
      v18->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v15->mPrev;
      v15->mPrev = v18;
      v2->m_pAINavComponent.mNext = &v4->m_SafePointerList.mNode;
      v4->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v15->mPrev;
    }
    if ( v2->m_pAIEntityComponent.m_pPointer )
    {
      if ( v2->m_pAINavComponent.m_pPointer )
      {
        WanderTask::UpdateCrosswalkUsable(v2);
        WanderTask::ReCalculatePath(v2, 0);
        BYTE6(v2->m_pAIEntityComponent.m_pPointer[20].m_BoundComponentHandles.mNode.mPrev) = 0;
      }
    }
  }
}

// File Line: 613
// RVA: 0x393E10
char __fastcall WanderTask::Update(WanderTask *this, float timestep)
{
  WanderTask *v2; // rbx
  unsigned int v3; // ecx
  unsigned int v4; // eax
  unsigned int v5; // ecx
  UFG::SimComponent *v6; // rax
  bool v7; // di
  bool v8; // al

  v2 = this;
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
  v6 = v2->m_pAIEntityComponent.m_pPointer;
  if ( v6 )
  {
    if ( BYTE6(v6[20].m_BoundComponentHandles.mNode.mPrev) )
    {
      WanderTask::UpdateCrosswalkUsable(v2);
      WanderTask::ReCalculatePath(v2, 0);
      BYTE6(v2->m_pAIEntityComponent.m_pPointer[20].m_BoundComponentHandles.mNode.mPrev) = 0;
    }
    WanderTask::UpdateCrosswalkUsable(v2);
    v7 = LOBYTE(v2->m_pAIEntityComponent.m_pPointer[10].m_SafePointerList.mNode.mNext)
      && !UFG::NavComponent::HasDestination((UFG::NavComponent *)v2->m_pAINavComponent.m_pPointer);
    if ( UFG::NavComponent::IsDestinationUnreachable((UFG::NavComponent *)v2->m_pAINavComponent.m_pPointer) )
      v2->m_replanTimerOnStuck = timestep + v2->m_replanTimerOnStuck;
    else
      v2->m_replanTimerOnStuck = 0.0;
    v8 = 0;
    if ( v2->m_maxWaitOnStuck < v2->m_replanTimerOnStuck )
      v8 = 1;
    if ( !v7 && !v8 )
    {
      WanderTask::UpdatePath(v2);
      return 1;
    }
    WanderTask::ReCalculatePath(v2, v8);
  }
  return 1;
}

// File Line: 680
// RVA: 0x397790
char __fastcall WanderTask::UpdatePath(WanderTask *this)
{
  WanderTask *v1; // r14
  unsigned __int16 *v2; // rsi
  __int64 v3; // rdx
  __int64 v4; // rcx
  __int64 v5; // rax
  __int64 v6; // rax
  signed __int64 v7; // rax
  __int64 v8; // rcx
  int v9; // eax
  unsigned int v10; // er15
  int v11; // ebx
  unsigned __int16 v12; // di
  UFG::qResourceInventory *v13; // rax
  UFG::qResourceWarehouse *v14; // rax
  UFG::qResourceInventory *v15; // rax
  UFG::qResourceWarehouse *v16; // rax
  _QWORD *v17; // rax
  char *v18; // rax
  unsigned int v19; // er15
  unsigned int v20; // ebx
  __int16 v21; // di
  UFG::qResourceInventory *v22; // rax
  UFG::qResourceWarehouse *v23; // rax
  UFG::qResourceInventory *v24; // rax
  UFG::qResourceWarehouse *v25; // rax
  unsigned int v26; // edx
  __int64 v27; // rax
  __int64 v28; // rcx
  signed __int64 v29; // rax
  unsigned int v30; // er15
  unsigned int v31; // ebx
  __int16 v32; // di
  UFG::qResourceInventory *v33; // rax
  UFG::qResourceWarehouse *v34; // rax
  UFG::qResourceInventory *v35; // rax
  UFG::qResourceWarehouse *v36; // rax
  UFG::SimComponent *v37; // rax
  UFG::TransformNodeComponent *v38; // rbx
  bool v39; // r8
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v40; // rax
  float v41; // xmm1_4
  float v42; // xmm2_4
  UFG::qResourceInventory *v43; // rax
  UFG::qResourceWarehouse *v44; // rax
  UFG::qResourceInventory *v45; // rax
  UFG::qResourceWarehouse *v46; // rax
  UFG::SimComponent *v47; // rax
  signed __int64 v48; // rdi
  float *v49; // rbx
  float v50; // xmm1_4
  float v51; // xmm2_4
  unsigned int v52; // er9
  UFG::qVector3 destPos; // [rsp+30h] [rbp-69h]
  UFG::qVector3 current_position; // [rsp+40h] [rbp-59h]
  UFG::qResourceHandle v56; // [rsp+50h] [rbp-49h]
  int v57; // [rsp+70h] [rbp-29h]
  unsigned int objUID; // [rsp+74h] [rbp-25h]
  __int64 v59; // [rsp+78h] [rbp-21h]
  UFG::qResourceHandle v60; // [rsp+80h] [rbp-19h]
  int v61; // [rsp+A0h] [rbp+7h]
  int v62; // [rsp+A4h] [rbp+Bh]
  __int64 v63; // [rsp+A8h] [rbp+Fh]
  __int64 v64; // [rsp+B0h] [rbp+17h]
  float speed; // [rsp+100h] [rbp+67h]
  float elapsedTime; // [rsp+108h] [rbp+6Fh]

  v64 = -2i64;
  v1 = this;
  v2 = &this->m_pAIEntityComponent.m_pPointer[8].m_Flags;
  *((_DWORD *)v2 + 80) = UFG::Metrics::msFrameCount;
  v3 = *((_QWORD *)v2 + 5);
  if ( v3 )
  {
    if ( !v3 )
      goto LABEL_73;
    v4 = *(_QWORD *)v3 + v3;
    if ( !*(_QWORD *)v3 )
      v4 = 0i64;
    if ( (v5 = *(_QWORD *)(v4 + 40)) == 0
      || *(_WORD *)(v5 + 34) == 0
      || ((v6 = *(_QWORD *)(v3 + 8)) == 0 ? (v7 = 0i64) : (v7 = v3 + v6 + 8),
          (v8 = *(_QWORD *)(v7 + 40)) == 0
       || !*(_WORD *)(v8 + 34)
       || (v9 = *(_DWORD *)(v3 + 24), !(v9 & 2))
       || (v9 & 0x80u) != 0) )
    {
LABEL_73:
      UFG::qResourceHandle::qResourceHandle(&v60);
      v61 = 0xFFFF;
      v62 = -1;
      v63 = 0i64;
      v60.mNameUID = -1;
      v10 = *((_DWORD *)v2 + 18);
      v11 = *((_DWORD *)v2 + 21);
      v12 = v2[40];
      v63 = 0i64;
      v13 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result;
      if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result )
      {
        v14 = UFG::qResourceWarehouse::Instance();
        v13 = UFG::qResourceWarehouse::GetInventory(v14, 0x43E99F7Eu);
        `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result = v13;
      }
      UFG::qResourceHandle::Close(&v60, v13);
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
      if ( !v63 || (*(_WORD *)(v63 + 34) != 0) != 1 )
      {
        UFG::qResourceHandle::qResourceHandle(&v56);
        v57 = 0xFFFF;
        objUID = -1;
        v59 = 0i64;
        v56.mNameUID = -1;
        v17 = (_QWORD *)*((_QWORD *)v2 + 5);
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
          v27 = *((_QWORD *)v2 + 5);
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
        if ( v59 && (*(_WORD *)(v59 + 34) != 0) == 1 )
        {
          UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::_Set(
            (UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *)v2 + 1,
            v26,
            v56.mNameUID,
            (unsigned __int16)v57);
          v37 = v1->m_pAIEntityComponent.m_pPointer;
          v38 = *(UFG::TransformNodeComponent **)&v37[1].m_TypeUID;
          destPos = UFG::qVector3::msZero;
          v39 = 0;
          if ( v37 )
          {
            v40 = v37[15].vfptr;
            if ( v40 )
              v39 = v40[28].__vecDelDtor && LODWORD(v40[15].__vecDelDtor);
          }
          UFG::AISidewalkGraph::GetDestinationPointFromNode(
            (UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *)v2 + 1,
            &destPos,
            v39);
          current_position = UFG::qVector3::msZero;
          if ( v38 )
          {
            UFG::TransformNodeComponent::UpdateWorldTransform(v38);
            v41 = v38->mWorldTransform.v3.y;
            v42 = v38->mWorldTransform.v3.z;
            current_position.x = v38->mWorldTransform.v3.x;
            current_position.y = v41;
            current_position.z = v42;
          }
          UFG::SidewalkWanderData::SetDestinationPos((UFG::SidewalkWanderData *)v2, &destPos, &current_position);
        }
        else
        {
          UFG::SidewalkWanderData::ClearDestination((UFG::SidewalkWanderData *)v2);
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
  if ( *((_BYTE *)v2 + 112) != 1 || !*((_QWORD *)v2 + 5) )
  {
    v47 = v1->m_pAIEntityComponent.m_pPointer;
    v48 = (signed __int64)&v47[8].m_Flags;
    v49 = *(float **)&v47[1].m_TypeUID;
    UFG::TransformNodeComponent::UpdateWorldTransform(*(UFG::TransformNodeComponent **)&v47[1].m_TypeUID);
    v50 = v49[45];
    v51 = v49[46];
    destPos.x = v49[44];
    destPos.y = v50;
    destPos.z = v51;
    v52 = 251;
    if ( *(_BYTE *)(v48 + 240) )
      v52 = 255;
    UFG::AISidewalkGraph::FindClosestSidewalkConnection(
      &destPos,
      30.0,
      (UFG::SidewalkCommonHandle<UFG::AISidewalkEdge_Game> *)v48,
      v52);
    UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::SetToNull((UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *)(v48 + 48));
    if ( !*(_QWORD *)(v48 + 40) || !WanderTask::CalculateDestination(v1, 0) )
      return 0;
  }
  destPos.x = *((float *)v2 + 24);
  destPos.y = *((float *)v2 + 25);
  destPos.z = *((float *)v2 + 26);
  speed = FLOAT_1_5;
  if ( *((_BYTE *)v2 + 257) )
    WanderTask::HandleCrossWalk(v1, (UFG::SidewalkWanderData *)v2, &destPos, &speed);
  if ( (unsigned __int8)UFG::NavComponent::IsAtDestination((UFG::NavComponent *)v1->m_pAINavComponent.m_pPointer) )
  {
    WanderTask::CalculateDestination(v1, 0);
  }
  else
  {
    UFG::NavComponent::PreserveDestination((UFG::NavComponent *)v1->m_pAINavComponent.m_pPointer);
    speed = -6.8056469e38/*NaN*/;
    elapsedTime = FLOAT_N1_0;
    if ( UFG::NavComponent::GetCurrGoalPointInfo(
           (UFG::NavComponent *)v1->m_pAINavComponent.m_pPointer,
           &current_position,
           &destPos,
           &elapsedTime,
           (int *)&speed)
      && LODWORD(speed) == *((_DWORD *)v2 + 57) )
    {
      UFG::SidewalkWanderData::MakeLookAheadCurrent((UFG::SidewalkWanderData *)v2);
    }
    if ( !*((_BYTE *)v2 + 232) )
      WanderTask::CalculateLookAheadDestination(v1);
  }
  return 1;
}

// File Line: 796
// RVA: 0x364BB0
void __fastcall WanderTask::HandleCrossWalk(WanderTask *this, UFG::SidewalkWanderData *wanderData, UFG::qVector3 *pos, float *speed)
{
  UFG::SimComponent *v4; // rax
  float v5; // xmm0_4
  float v6; // xmm3_4
  float *v7; // rdi
  UFG::qVector3 *v8; // rbp
  UFG::SidewalkWanderData *v9; // rsi
  float *v10; // rbx
  float v11; // xmm4_4
  __m128 v12; // xmm2
  UFG::CrosswalkLanes *v13; // rcx
  float v14; // xmm1_4

  v4 = this->m_pAIEntityComponent.m_pPointer;
  v5 = UFG::qVector3::msZero.x;
  v6 = UFG::qVector3::msZero.y;
  v7 = speed;
  v8 = pos;
  v9 = wanderData;
  v10 = *(float **)&v4[1].m_TypeUID;
  v11 = UFG::qVector3::msZero.z;
  if ( v10 )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(*(UFG::TransformNodeComponent **)&v4[1].m_TypeUID);
    v5 = v10[44];
    v6 = v10[45];
    v11 = v10[46];
  }
  v12 = (__m128)LODWORD(v8->y);
  v13 = &v9->mCrosswalkLanes;
  v12.m128_f32[0] = (float)((float)((float)(v12.m128_f32[0] - v6) * (float)(v12.m128_f32[0] - v6))
                          + (float)((float)(v8->x - v5) * (float)(v8->x - v5)))
                  + (float)((float)(v8->z - v11) * (float)(v8->z - v11));
  v14 = COERCE_FLOAT(_mm_sqrt_ps(v12)) / *v7;
  if ( v9->mWaitingToCross )
  {
    if ( UFG::AISidewalkGraph::IsCrosswalkCrossable(v13, v14) )
      v9->mWaitingToCross = 0;
    else
      *v7 = 0.0;
  }
  else if ( UFG::AISidewalkGraph::IsCrosswalkCrossable(v13, 2.0) )
  {
    *v7 = 1.5;
  }
  else
  {
    *v7 = 3.95;
  }
}

// File Line: 846
// RVA: 0x37F3B0
void __fastcall WanderTask::ReCalculatePath(WanderTask *this, bool useInverseDirection)
{
  bool v2; // bp
  WanderTask *v3; // rsi
  UFG::SimComponent *v4; // rax
  UFG::SidewalkWanderData *v5; // rdi
  float *v6; // rbx
  float v7; // xmm1_4
  float v8; // xmm2_4
  unsigned int v9; // er9
  UFG::qResourceInventory *v10; // rax
  UFG::qResourceWarehouse *v11; // rax
  UFG::qVector3 pos; // [rsp+28h] [rbp-50h]
  UFG::qResourceHandle v13; // [rsp+38h] [rbp-40h]
  int v14; // [rsp+58h] [rbp-20h]
  unsigned int objUID; // [rsp+5Ch] [rbp-1Ch]
  __int64 v16; // [rsp+60h] [rbp-18h]

  v2 = useInverseDirection;
  v3 = this;
  this->m_replanTimerOnStuck = 0.0;
  this->m_maxWaitOnStuck = UFG::qRandom(1.0, &UFG::qDefaultSeed) + 2.0;
  v4 = v3->m_pAIEntityComponent.m_pPointer;
  v5 = (UFG::SidewalkWanderData *)&v4[8].m_Flags;
  v6 = *(float **)&v4[1].m_TypeUID;
  UFG::TransformNodeComponent::UpdateWorldTransform(*(UFG::TransformNodeComponent **)&v4[1].m_TypeUID);
  v7 = v6[45];
  v8 = v6[46];
  pos.x = v6[44];
  pos.y = v7;
  pos.z = v8;
  UFG::qResourceHandle::qResourceHandle(&v13);
  v14 = 0x1FFFF;
  objUID = -1;
  v16 = 0i64;
  v13.mNameUID = -1;
  v9 = 251;
  if ( v5->mAllowedToUseCrosswalks )
    v9 = 255;
  UFG::AISidewalkGraph::FindClosestSidewalkConnection(
    &pos,
    30.0,
    (UFG::SidewalkCommonHandle<UFG::AISidewalkEdge_Game> *)&v13,
    v9);
  UFG::SidewalkWanderData::ClearData(v5);
  if ( v16 )
  {
    UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::_Set(
      (UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *)v5,
      objUID,
      v13.mNameUID,
      (unsigned __int16)v14);
    UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::SetToNull(&v5->mGoals[0].mpDestinationNode);
    WanderTask::CalculateDestination(v3, v2);
  }
  v10 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result;
  if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result )
  {
    v11 = UFG::qResourceWarehouse::Instance();
    v10 = UFG::qResourceWarehouse::GetInventory(v11, 0x43E99F7Eu);
    `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result = v10;
  }
  UFG::qResourceHandle::Close(&v13, v10);
  UFG::qResourceHandle::~qResourceHandle(&v13);
}

// File Line: 888
// RVA: 0x34A770
char __fastcall WanderTask::CalculateDestination(WanderTask *this, bool useInverseDirection)
{
  UFG::SimComponent *v2; // rsi
  bool v3; // bp
  WanderTask *v4; // rdi
  signed __int64 sidewalkWanderData; // rbx
  char result; // al
  __int64 v7; // rsi
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm3_4
  UFG::AIEntityComponent *pAIEntityComponent; // r14
  bool isGroupLeader; // bp
  UFG::GroupComponent *v13; // rax
  unsigned int v14; // ecx
  UFG::SimObjectGame *v15; // rcx
  unsigned __int16 v16; // dx
  UFG::CharacterPhysicsComponent *v17; // rax
  unsigned int v18; // eax
  __m128 v19; // xmm3
  __m128 v20; // xmm2
  UFG::NavComponent *v21; // rcx
  int v22; // eax
  __m128 v23; // xmm0
  UFG::qVector3 pCurrentFacing; // [rsp+40h] [rbp-78h]
  UFG::qVector3 pDestinationPoint; // [rsp+50h] [rbp-68h]
  UFG::HavokNavPosition npDestination; // [rsp+60h] [rbp-58h]

  v2 = this->m_pAIEntityComponent.m_pPointer;
  v3 = useInverseDirection;
  v4 = this;
  sidewalkWanderData = (signed __int64)&v2[8].m_Flags;
  if ( !v2[9].m_SafePointerList.mNode.mPrev )
    return 0;
  v7 = *(_QWORD *)&v2[1].m_TypeUID;
  pDestinationPoint = UFG::qVector3::msZero;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v7);
  v8 = *(float *)(v7 + 128);
  v9 = *(float *)(v7 + 132);
  v10 = *(float *)(v7 + 136);
  pCurrentFacing.x = *(float *)(v7 + 128);
  pCurrentFacing.y = v9;
  pCurrentFacing.z = v10;
  if ( v3 )
  {
    pCurrentFacing.x = v8 * -1.0;
    pCurrentFacing.y = v9 * -1.0;
    pCurrentFacing.z = v10 * -1.0;
  }
  pAIEntityComponent = (UFG::AIEntityComponent *)v4->m_pAIEntityComponent.m_pPointer;
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
         (UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *)(sidewalkWanderData + 48),
         &pDestinationPoint,
         (UFG::qVector3 *)(v7 + 176),
         &pCurrentFacing,
         isGroupLeader,
         pAIEntityComponent,
         (UFG::SidewalkWanderData *)sidewalkWanderData) )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v7);
    UFG::SidewalkWanderData::SetDestinationPos(
      (UFG::SidewalkWanderData *)sidewalkWanderData,
      &pDestinationPoint,
      (UFG::qVector3 *)(v7 + 176));
    v14 = *(_DWORD *)(*(_QWORD *)(sidewalkWanderData + 40) + 24i64);
    *(_BYTE *)(sidewalkWanderData + 258) = 1;
    *(_BYTE *)(sidewalkWanderData + 257) = (v14 >> 2) & 1;
    *(_DWORD *)(sidewalkWanderData + 108) = ++v4->m_iGoalIdCounter;
    if ( *(_BYTE *)(sidewalkWanderData + 257) )
    {
      UFG::AISidewalkGraph::CalculateCrosswalkLanes(
        (UFG::SidewalkCommonHandle<UFG::AISidewalkEdge_Game> *)sidewalkWanderData,
        (UFG::CrosswalkLanes *)(sidewalkWanderData + 264));
      v15 = (UFG::SimObjectGame *)v4->m_pActionContext->mSimObject.m_pPointer;
      if ( v15 )
      {
        v16 = v15->m_Flags;
        if ( (v16 >> 14) & 1 )
        {
          v17 = (UFG::CharacterPhysicsComponent *)v15->m_Components.p[27].m_pComponent;
        }
        else if ( (v16 & 0x8000u) == 0 )
        {
          if ( (v16 >> 13) & 1 )
          {
            v17 = (UFG::CharacterPhysicsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      v15,
                                                      UFG::CharacterPhysicsComponent::_TypeUID);
          }
          else if ( (v16 >> 12) & 1 )
          {
            v17 = (UFG::CharacterPhysicsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      v15,
                                                      UFG::CharacterPhysicsComponent::_TypeUID);
          }
          else
          {
            v17 = (UFG::CharacterPhysicsComponent *)UFG::SimObject::GetComponentOfType(
                                                      (UFG::SimObject *)&v15->vfptr,
                                                      UFG::CharacterPhysicsComponent::_TypeUID);
          }
        }
        else
        {
          v17 = (UFG::CharacterPhysicsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    v15,
                                                    UFG::CharacterPhysicsComponent::_TypeUID);
        }
        if ( v17 )
        {
          v18 = UFG::GetTerrainTypeHash(v17);
          if ( UFG::GetTerrainTypeEnum(v18) == 2 )
            *(_BYTE *)(sidewalkWanderData + 258) = 0;
        }
      }
    }
    v19 = (__m128)*(unsigned int *)(sidewalkWanderData + 96);
    v20 = (__m128)*(unsigned int *)(sidewalkWanderData + 100);
    v21 = (UFG::NavComponent *)v4->m_pAINavComponent.m_pPointer;
    npDestination.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
    v22 = *(_DWORD *)(sidewalkWanderData + 108);
    v23 = (__m128)*(unsigned int *)(sidewalkWanderData + 104);
    LODWORD(npDestination.m_vPosition.x) = v19.m128_i32[0];
    npDestination.m_bValid = 0;
    LODWORD(npDestination.m_vPosition.y) = v20.m128_i32[0];
    LODWORD(npDestination.m_vPosition.z) = v23.m128_i32[0];
    *(_QWORD *)&npDestination.m_packedKey = -1i64;
    npDestination.m_hkvMeshPosition.m_quad = _mm_unpacklo_ps(
                                               _mm_unpacklo_ps(v19, v23),
                                               _mm_unpacklo_ps(v20, (__m128)(unsigned int)FLOAT_1_0));
    UFG::NavComponent::AddGoalPointUidHACK(v21, &npDestination, 0, 1.5, v22, 512, 1.0);
    result = 1;
  }
  else
  {
    UFG::SidewalkWanderData::ClearDestination((UFG::SidewalkWanderData *)sidewalkWanderData);
    UFG::SidewalkWanderData::ClearLookAheadDestination((UFG::SidewalkWanderData *)sidewalkWanderData);
    result = 0;
  }
  return result;
}

// File Line: 957
// RVA: 0x34B810
char __fastcall WanderTask::CalculateLookAheadDestination(WanderTask *this)
{
  WanderTask *v1; // rdi
  UFG::SimComponent *v2; // rax
  signed __int64 sidewalkWanderData; // rbx
  float v5; // xmm1_4
  float v6; // xmm2_4
  _QWORD *v7; // rax
  char *v8; // rax
  unsigned int v9; // er12
  int v10; // er14
  __int16 v11; // r15
  UFG::qResourceInventory *v12; // rax
  UFG::qResourceWarehouse *v13; // rax
  UFG::qResourceInventory *v14; // rax
  UFG::qResourceWarehouse *v15; // rax
  __int64 v16; // rax
  __int64 v17; // rcx
  signed __int64 v18; // rax
  unsigned int v19; // er12
  int v20; // er14
  __int16 v21; // r15
  UFG::qResourceInventory *v22; // rax
  UFG::qResourceWarehouse *v23; // rax
  UFG::qResourceInventory *v24; // rax
  UFG::qResourceWarehouse *v25; // rax
  float v26; // xmm3_4
  float v27; // xmm5_4
  float v28; // xmm5_4
  __m128 v29; // xmm6
  float v30; // xmm3_4
  __m128 v31; // xmm4
  float v32; // xmm2_4
  UFG::SimComponent *v33; // rax
  bool isGroupLeader; // cl
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v35; // rax
  __m128 v36; // xmm3
  __m128 v37; // xmm2
  __m128 v38; // xmm0
  int v39; // eax
  char v40; // bl
  UFG::qResourceInventory *v41; // rax
  UFG::qResourceWarehouse *v42; // rax
  UFG::qVector3 pDestinationPoint; // [rsp+40h] [rbp-98h]
  UFG::qResourceHandle pCurrentFacing; // [rsp+50h] [rbp-88h]
  float v45; // [rsp+70h] [rbp-68h]
  int v46; // [rsp+74h] [rbp-64h]
  UFG::HavokNavPosition npDestination; // [rsp+78h] [rbp-60h]
  __int64 v48; // [rsp+B8h] [rbp-20h]

  v48 = -2i64;
  v1 = this;
  v2 = this->m_pAIEntityComponent.m_pPointer;
  sidewalkWanderData = (signed __int64)&v2[8].m_Flags;
  if ( !v2[9].m_SafePointerList.mNode.mPrev )
    return 0;
  pDestinationPoint = UFG::qVector3::msZero;
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::SetToNull((UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *)&v2[10].m_TypeUID);
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::SetToNull((UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *)(sidewalkWanderData + 168));
  v5 = UFG::qVector3::msZero.y;
  v6 = UFG::qVector3::msZero.z;
  *(float *)(sidewalkWanderData + 216) = UFG::qVector3::msZero.x;
  *(float *)(sidewalkWanderData + 220) = v5;
  *(float *)(sidewalkWanderData + 224) = v6;
  *(_DWORD *)(sidewalkWanderData + 228) = -1;
  *(_BYTE *)(sidewalkWanderData + 232) = 0;
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::_Set(
    (UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *)(sidewalkWanderData + 120),
    *(_DWORD *)(sidewalkWanderData + 36),
    *(_DWORD *)(sidewalkWanderData + 24),
    *(unsigned __int16 *)(sidewalkWanderData + 32));
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::_Set(
    (UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *)(sidewalkWanderData + 168),
    *(_DWORD *)(sidewalkWanderData + 84),
    *(_DWORD *)(sidewalkWanderData + 72),
    *(unsigned __int16 *)(sidewalkWanderData + 80));
  UFG::qResourceHandle::qResourceHandle(&pCurrentFacing);
  LODWORD(v45) = 0xFFFF;
  v46 = -1;
  npDestination.vfptr = 0i64;
  pCurrentFacing.mNameUID = -1;
  v7 = *(_QWORD **)(sidewalkWanderData + 40);
  if ( *v7 )
    v8 = (char *)v7 + *v7;
  else
    v8 = 0i64;
  v9 = *((_DWORD *)v8 + 6);
  v10 = *((_DWORD *)v8 + 9);
  v11 = *((_WORD *)v8 + 16);
  npDestination.vfptr = 0i64;
  v12 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result;
  if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result )
  {
    v13 = UFG::qResourceWarehouse::Instance();
    v12 = UFG::qResourceWarehouse::GetInventory(v13, 0x43E99F7Eu);
    `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result = v12;
  }
  UFG::qResourceHandle::Close(&pCurrentFacing, v12);
  LOWORD(v45) = v11;
  v46 = v10;
  v14 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result;
  if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result )
  {
    v15 = UFG::qResourceWarehouse::Instance();
    v14 = UFG::qResourceWarehouse::GetInventory(v15, 0x43E99F7Eu);
    `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result = v14;
  }
  UFG::qResourceHandle::Init(&pCurrentFacing, 0x43E99F7Eu, v9, v14);
  if ( *(_DWORD *)(sidewalkWanderData + 84) == v46 )
  {
    v16 = *(_QWORD *)(sidewalkWanderData + 40);
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
    LOWORD(v45) = v21;
    v46 = v20;
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
  v26 = *(float *)(sidewalkWanderData + 96);
  v29 = (__m128)*(unsigned int *)(sidewalkWanderData + 100);
  v27 = *(float *)(sidewalkWanderData + 104);
  *(float *)&pCurrentFacing.mNameUID = v26;
  pCurrentFacing.mTailPad = v29.m128_i32[0];
  v45 = v27;
  v28 = v27 - *(float *)&npDestination.vfptr->Invalidate;
  v29.m128_f32[0] = v29.m128_f32[0] - *((float *)&npDestination.vfptr->Validate + 1);
  v30 = v26 - *(float *)&npDestination.vfptr->Validate;
  v31 = v29;
  v31.m128_f32[0] = (float)((float)(v29.m128_f32[0] * v29.m128_f32[0]) + (float)(v30 * v30)) + (float)(v28 * v28);
  v32 = 0.0;
  if ( v31.m128_f32[0] != 0.0 )
    v32 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v31));
  *(float *)&pCurrentFacing.mNext = v30 * v32;
  *((float *)&pCurrentFacing.mNext + 1) = v32 * v29.m128_f32[0];
  *(float *)&pCurrentFacing.mData = v32 * v28;
  v33 = v1->m_pAIEntityComponent.m_pPointer;
  isGroupLeader = 0;
  if ( v33 )
  {
    v35 = v33[15].vfptr;
    if ( v35 )
      isGroupLeader = v35[28].__vecDelDtor && LODWORD(v35[15].__vecDelDtor);
  }
  if ( !UFG::AISidewalkGraph::CalculateDestinationPoint(
          (UFG::SidewalkCommonHandle<UFG::AISidewalkEdge_Game> *)(sidewalkWanderData + 120),
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
    v40 = 0;
    goto LABEL_32;
  }
  v36 = (__m128)LODWORD(pDestinationPoint.x);
  *(float *)(sidewalkWanderData + 216) = pDestinationPoint.x;
  v37 = (__m128)LODWORD(pDestinationPoint.y);
  *(float *)(sidewalkWanderData + 220) = pDestinationPoint.y;
  v38 = (__m128)LODWORD(pDestinationPoint.z);
  *(float *)(sidewalkWanderData + 224) = pDestinationPoint.z;
  *(_BYTE *)(sidewalkWanderData + 232) = 1;
  v39 = v1->m_iGoalIdCounter + 1;
  v1->m_iGoalIdCounter = v39;
  *(_DWORD *)(sidewalkWanderData + 228) = v39;
  LODWORD(npDestination.m_vPosition.x) = v36.m128_i32[0];
  LODWORD(npDestination.m_vPosition.y) = v37.m128_i32[0];
  LODWORD(npDestination.m_vPosition.z) = v38.m128_i32[0];
  npDestination.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
  npDestination.m_bValid = 0;
  *(_QWORD *)&npDestination.m_packedKey = -1i64;
  npDestination.m_hkvMeshPosition.m_quad = _mm_unpacklo_ps(
                                             _mm_unpacklo_ps(v36, v38),
                                             _mm_unpacklo_ps(v37, (__m128)(unsigned int)FLOAT_1_0));
  UFG::NavComponent::AddGoalPointUid(
    (UFG::NavComponent *)v1->m_pAINavComponent.m_pPointer,
    &npDestination,
    AiGoal_Append,
    1.5,
    v39,
    1.0);
  v40 = 1;
LABEL_32:
  v41 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result;
  if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result )
  {
    v42 = UFG::qResourceWarehouse::Instance();
    v41 = UFG::qResourceWarehouse::GetInventory(v42, 0x43E99F7Eu);
    `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result = v41;
  }
  UFG::qResourceHandle::Close(&pCurrentFacing, v41);
  UFG::qResourceHandle::~qResourceHandle(&pCurrentFacing);
  return v40;
}

// File Line: 1041
// RVA: 0x32E530
void __fastcall FleeTask::FleeTask(FleeTask *this)
{
  FleeTask *v1; // r9
  UFG::qNode<ITask,ITask> *v2; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v3; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::NavComponent> *v4; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActorAudioComponent> *v9; // [rsp+28h] [rbp+10h]
  UFG::qSafePointer<UFG::SimComponent,UFG::AIMarker> *v10; // [rsp+28h] [rbp+10h]

  v1 = this;
  v2 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<FleeTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&FleeTask::`vftable;
  v3 = &this->m_pAIEntityComponent;
  v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  this->m_pAIEntityComponent.m_pPointer = 0i64;
  v4 = &this->m_pNavComponent;
  v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  v4->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  this->m_pNavComponent.m_pPointer = 0i64;
  v9 = &this->m_pActorAudioComponent;
  v9->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
  v9->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
  this->m_pActorAudioComponent.m_pPointer = 0i64;
  v10 = &this->m_pFleeToPoint;
  v10->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v10->mPrev;
  v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v10->mPrev;
  this->m_pFleeToPoint.m_pPointer = 0i64;
  this->m_NavParams.m_fRadius = 0.0;
  this->m_NavParams.m_flags = 65280;
  this->m_pActionContext = 0i64;
  if ( this->m_pAIEntityComponent.m_pPointer )
  {
    v5 = v3->mPrev;
    v6 = v3->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
    v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  }
  v3->m_pPointer = 0i64;
  if ( v4->m_pPointer )
  {
    v7 = v4->mPrev;
    v8 = v4->mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
    v4->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  }
  v4->m_pPointer = 0i64;
  v1->m_LastTimeInteriorStatusChanged = -99999.0;
  v1->m_CurrentlyInInterior = 0;
  v1->m_LastTimeFleeDirectionChecked = -99999.0;
}

// File Line: 1055
// RVA: 0x336B20
void __fastcall FleeTask::~FleeTask(FleeTask *this)
{
  FleeTask *v1; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::AIMarker> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActorAudioComponent> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::NavComponent> *v12; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v17; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v21; // rax
  UFG::qNode<ITask,ITask> *v22; // rdx
  UFG::qNode<ITask,ITask> *v23; // rcx
  UFG::qNode<ITask,ITask> *v24; // rax

  v1 = this;
  this->vfptr = (ITaskVtbl *)&FleeTask::`vftable;
  v2 = &this->m_pFleeToPoint;
  if ( this->m_pFleeToPoint.m_pPointer )
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
  v7 = &v1->m_pActorAudioComponent;
  if ( v1->m_pActorAudioComponent.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v1->m_pActorAudioComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v1->m_pActorAudioComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pActorAudioComponent.mPrev;
  }
  v1->m_pActorAudioComponent.m_pPointer = 0i64;
  v10 = v7->mPrev;
  v11 = v1->m_pActorAudioComponent.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v1->m_pActorAudioComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pActorAudioComponent.mPrev;
  v12 = &v1->m_pNavComponent;
  if ( v1->m_pNavComponent.m_pPointer )
  {
    v13 = v12->mPrev;
    v14 = v1->m_pNavComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v12->mPrev;
    v1->m_pNavComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pNavComponent.mPrev;
  }
  v1->m_pNavComponent.m_pPointer = 0i64;
  v15 = v12->mPrev;
  v16 = v1->m_pNavComponent.mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v12->mPrev;
  v1->m_pNavComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pNavComponent.mPrev;
  v17 = &v1->m_pAIEntityComponent;
  if ( v1->m_pAIEntityComponent.m_pPointer )
  {
    v18 = v17->mPrev;
    v19 = v1->m_pAIEntityComponent.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    v17->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v17->mPrev;
    v1->m_pAIEntityComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pAIEntityComponent.mPrev;
  }
  v1->m_pAIEntityComponent.m_pPointer = 0i64;
  v20 = v17->mPrev;
  v21 = v1->m_pAIEntityComponent.mNext;
  v20->mNext = v21;
  v21->mPrev = v20;
  v17->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v17->mPrev;
  v1->m_pAIEntityComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pAIEntityComponent.mPrev;
  v1->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v22 = (UFG::qNode<ITask,ITask> *)&v1->mPrev;
  v23 = v1->mPrev;
  v24 = v1->mNext;
  v23->mNext = v24;
  v24->mPrev = v23;
  v22->mPrev = v22;
  v22->mNext = v22;
}

// File Line: 1074
// RVA: 0x349C30
void __fastcall FleeTask::BeginInteriorFleeing(FleeTask *this)
{
  UFG::SimComponent *v1; // r15
  FleeTask *v2; // rbp
  UFG::qNode<UFG::AIMarker,UFG::AIMarker> *v3; // rbx
  float v4; // xmm6_4
  UFG::SimComponent *v5; // rsi
  float *v6; // rdi
  __m128 v7; // xmm2
  float v8; // xmm1_4
  float v9; // xmm1_4
  UFG::qSafePointer<UFG::SimComponent,UFG::AIMarker> *v10; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AIMarker> *v14; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax

  v1 = this->m_pNavComponent.m_pPointer;
  v2 = this;
  if ( v1 )
  {
    v3 = UFG::AIMarker::s_AIFleeToPointList.mNode.mNext - 7;
    v4 = FLOAT_N1_0;
    v5 = 0i64;
    if ( (UFG::qList<UFG::AIMarker,UFG::AIMarker,1,0> *)&UFG::AIMarker::s_AIFleeToPointList.mNode.mNext[-7] == &UFG::AIMarker::s_AIFleeToPointList - 7 )
      goto LABEL_22;
    do
    {
      v6 = (float *)v3[6].mNext;
      if ( v6 )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v3[6].mNext);
        v7 = (__m128)v1[1].m_NameUID;
        v8 = *(float *)&v1[1].m_TypeUID - v6[44];
        v7.m128_f32[0] = (float)((float)((float)(v7.m128_f32[0] - v6[45]) * (float)(v7.m128_f32[0] - v6[45]))
                               + (float)(v8 * v8))
                       + (float)((float)(*(float *)&v1[1].m_Flags - v6[46]) * (float)(*(float *)&v1[1].m_Flags - v6[46]));
        LODWORD(v9) = (unsigned __int128)_mm_sqrt_ps(v7);
        if ( (!v5 || v9 < v4) && v9 < 1000.0 )
        {
          v5 = (UFG::SimComponent *)v3;
          v4 = v9;
        }
      }
      v3 = v3[7].mNext - 7;
    }
    while ( v3 != (UFG::qNode<UFG::AIMarker,UFG::AIMarker> *)(&UFG::AIMarker::s_AIFleeToPointList - 7) );
    if ( v5 && v2->m_pAIEntityComponent.m_pPointer && v5[1].m_pSimObject )
    {
      v10 = &v2->m_pFleeToPoint;
      if ( v2->m_pFleeToPoint.m_pPointer )
      {
        v11 = v10->mPrev;
        v12 = v2->m_pFleeToPoint.mNext;
        v11->mNext = v12;
        v12->mPrev = v11;
        v10->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v10->mPrev;
        v2->m_pFleeToPoint.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pFleeToPoint.mPrev;
      }
      v2->m_pFleeToPoint.m_pPointer = v5;
      v13 = v5->m_SafePointerList.mNode.mPrev;
      v13->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v10->mPrev;
      v10->mPrev = v13;
      v2->m_pFleeToPoint.mNext = &v5->m_SafePointerList.mNode;
      v5->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v10->mPrev;
    }
    else
    {
LABEL_22:
      v14 = &v2->m_pFleeToPoint;
      if ( v2->m_pFleeToPoint.m_pPointer )
      {
        v15 = v14->mPrev;
        v16 = v2->m_pFleeToPoint.mNext;
        v15->mNext = v16;
        v16->mPrev = v15;
        v14->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v14->mPrev;
        v2->m_pFleeToPoint.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pFleeToPoint.mPrev;
      }
      v2->m_pFleeToPoint.m_pPointer = 0i64;
    }
  }
  if ( !v2->m_pFleeToPoint.m_pPointer )
    FleeTask::BeginExteriorFleeing(v2);
}

// File Line: 1123
// RVA: 0x3493D0
void __fastcall FleeTask::BeginExteriorFleeing(FleeTask *this)
{
  FleeTask *v1; // rdi
  UFG::SimObjectGame *v2; // r8
  UFG::SimComponent *v3; // rsi
  unsigned __int16 v4; // cx
  UFG::SimComponent *v5; // rax
  UFG::qVector4 *v6; // rax
  float v7; // xmm1_4
  float v8; // xmm2_4
  unsigned int v9; // xmm1_4
  int v10; // xmm2_4
  ITrack *v11; // rcx
  float v12; // xmm6_4
  float v13; // xmm7_4
  float v14; // xmm8_4
  __int64 v15; // rsi
  unsigned int v16; // ebx
  unsigned int v17; // edx
  unsigned __int64 v18; // rcx
  unsigned __int64 v19; // rcx
  UFG::TransformNodeComponent *v20; // rbx
  __m128 v21; // xmm2
  __m128 v22; // xmm0
  UFG::SimObjectGame *v23; // rcx
  unsigned __int16 v24; // dx
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
  __int64 v35; // r15
  __int64 v36; // rsi
  UFG::SimComponent *v37; // r14
  __int64 v38; // rax
  __int64 v39; // rbx
  int v40; // xmm6_4
  int v41; // xmm7_4
  int v42; // xmm8_4
  int v43; // xmm9_4
  __int64 v44; // r14
  unsigned int v45; // ebx
  unsigned int v46; // edx
  unsigned __int64 v47; // rcx
  UFG::DaemonManager *v48; // rax
  UFG::qVector4 *v49; // rax
  float v50; // xmm2_4
  float v51; // xmm1_4
  __int64 v52; // rcx
  UFG::HavokNavPosition navPosition; // [rsp+20h] [rbp-B8h]
  UFG::FleeTraversalImmediateQuery v54; // [rsp+60h] [rbp-78h]
  UFG::qVector3 v55; // [rsp+F0h] [rbp+18h]
  char v56; // [rsp+100h] [rbp+28h]
  __int128 v57; // [rsp+108h] [rbp+30h]
  __int64 v58; // [rsp+118h] [rbp+40h]
  __int64 v59; // [rsp+128h] [rbp+50h]
  __int64 v60; // [rsp+138h] [rbp+60h]

  v60 = -2i64;
  v1 = this;
  this->m_FailedQuery = 1;
  v54.m_pOutput = 0i64;
  v54.vfptr = (UFG::DaemonQueryInputVtbl *)&UFG::FleeTraversalImmediateQuery::`vftable;
  *(_QWORD *)(&navPosition.m_aiMeshUid + 1) = 0i64;
  *(UFG::qVector3 *)&v54.m_mode = UFG::qVector3::msZero;
  *(_QWORD *)&v54.m_daemonType = &UFG::HavokNavPosition::`vftable;
  LOBYTE(v54.mpNavParams) = 0;
  *(_QWORD *)&v54.mEscapeOrigin.m_vPosition.x = -1i64;
  *(__m128 *)&(&v54.mpNavParams)[1] = _mm_unpacklo_ps(
                                        _mm_unpacklo_ps(
                                          (__m128)LODWORD(UFG::qVector3::msZero.x),
                                          (__m128)LODWORD(UFG::qVector3::msZero.z)),
                                        _mm_unpacklo_ps(
                                          (__m128)LODWORD(UFG::qVector3::msZero.y),
                                          (__m128)(unsigned int)FLOAT_1_0));
  *(_DWORD *)&v54.mEscapeOrigin.m_bValid = 0;
  *((float *)&v54.mEscapeOrigin.m_bValid + 1) = FLOAT_N1_0;
  v54.mEscapeOrigin.m_hkvMeshPosition = 0ui64;
  v54.mEscapeOrigin.m_packedKey = -1;
  v54.mEscapeRadius = 0.0;
  *(_QWORD *)&v54.mRoadCost = 3i64;
  *(_QWORD *)(&v54.mEscapeOrigin.m_aiMeshUid + 1) = &UFG::FleeTraversalOutput::`vftable;
  v55 = UFG::qVector3::msZero;
  *(_QWORD *)&v54.mMaxSearchIterations = &UFG::HavokNavPosition::`vftable;
  v56 = 0;
  v58 = -1i64;
  v57 = *(_OWORD *)&(&v54.mpNavParams)[1];
  v59 = 0i64;
  v2 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
  if ( v2 )
  {
    v4 = v2->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v3 = v2->m_Components.p[36].m_pComponent;
    }
    else
    {
      if ( (v4 & 0x8000u) == 0 )
      {
        if ( (v4 >> 13) & 1 )
        {
          v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::NavComponent::_TypeUID);
        }
        else if ( (v4 >> 12) & 1 )
        {
          v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::NavComponent::_TypeUID);
        }
        else
        {
          v5 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::NavComponent::_TypeUID);
        }
      }
      else
      {
        v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::NavComponent::_TypeUID);
      }
      v3 = v5;
    }
  }
  else
  {
    v3 = 0i64;
  }
  if ( !((unsigned __int8 (__fastcall *)(UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **))v3[1].m_SafePointerList.mNode.mNext[2].mPrev)(&v3[1].m_SafePointerList.mNode.mNext) )
  {
    v6 = UFG::NavComponent::GetCurrentPosition((UFG::NavComponent *)v3);
    v7 = v6->y;
    v8 = v6->z;
    v1->m_FleeDestination.x = v6->x;
    v1->m_FleeDestination.z = v8;
LABEL_79:
    v1->m_FleeDestination.y = v7;
    goto LABEL_80;
  }
  v9 = v3[1].m_NameUID;
  v10 = *(_DWORD *)&v3[1].m_Flags;
  v54.m_mode = v3[1].m_TypeUID;
  *((_DWORD *)&v54.m_mode + 1) = v9;
  LODWORD(v54.m_pOutput) = v10;
  if ( LOBYTE(v3[1].m_pSimObject) )
  {
    LOBYTE(v54.mpNavParams) = v3[1].m_pSimObject;
    *(UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *)&(&v54.mpNavParams)[1] = v3[1].m_BoundComponentHandles;
    v54.mEscapeOrigin.m_vPosition.x = *(float *)&v3[2].vfptr;
    v54.mEscapeOrigin.m_vPosition.y = *((float *)&v3[2].vfptr + 1);
  }
  else
  {
    LOBYTE(v54.mpNavParams) = 0;
  }
  v11 = v1->m_Track;
  *(float *)&v54.mEscapeOrigin.m_bValid = *(float *)&v11[1].mResourceOwner - v1->m_FailedRetryCount;
  v1->m_NavParams = *(UFG::NavParams *)((char *)&v3[2].m_BoundComponentHandles.mNode.mNext + 4);
  if ( !LOBYTE(v11[1].mMasterRate.expression.mOffset) )
    *((float *)&v54.mEscapeOrigin.m_bValid + 1) = FLOAT_500000_0;
  *(_QWORD *)(&navPosition.m_aiMeshUid + 1) = (char *)v1 + 192;
  v12 = v1->m_LastFleeOrigin.x;
  v13 = v1->m_LastFleeOrigin.y;
  v14 = v1->m_LastFleeOrigin.z;
  v15 = v54.mEscapeOrigin.m_hkvMeshPosition.m_quad.m128_u32[0];
  v16 = v54.mEscapeOrigin.m_hkvMeshPosition.m_quad.m128_i32[0] + 1;
  if ( (unsigned int)(v54.mEscapeOrigin.m_hkvMeshPosition.m_quad.m128_i32[0] + 1) > v54.mEscapeOrigin.m_hkvMeshPosition.m_quad.m128_i32[1] )
  {
    if ( v54.mEscapeOrigin.m_hkvMeshPosition.m_quad.m128_i32[1] )
      v17 = 2 * v54.mEscapeOrigin.m_hkvMeshPosition.m_quad.m128_i32[1];
    else
      v17 = 1;
    for ( ; v17 < v16; v17 *= 2 )
      ;
    if ( v17 - v16 > 0x10000 )
      v17 = v54.mEscapeOrigin.m_hkvMeshPosition.m_quad.m128_i32[0] + 65537;
    UFG::qArray<UFG::FleeTraversalImmediateQuery::ThreatTarget,0>::Reallocate(
      (UFG::qArray<UFG::FleeTraversalImmediateQuery::ThreatTarget,0> *)&v54.mEscapeOrigin.m_hkvMeshPosition,
      v17,
      "qArray.Add");
  }
  v54.mEscapeOrigin.m_hkvMeshPosition.m_quad.m128_i32[0] = v16;
  v18 = v54.mEscapeOrigin.m_hkvMeshPosition.m_quad.m128_u64[1] + 80 * v15;
  *(float *)(v18 + 8) = v12;
  *(float *)(v18 + 12) = v13;
  *(float *)(v18 + 16) = v14;
  *(_BYTE *)(v18 + 24) = 0;
  *(_DWORD *)(v18 + 64) = 1120403456;
  v19 = UFG::LocalPlayerIsInCombatManager::s_pInstance->m_LastMeleeCombatTimestamp;
  if ( v19 && UFG::Metrics::msInstance.mSimTimeMSec - v19 < UFG::LocalPlayerIsInCombatManager::s_InCombatTimer )
  {
    if ( LocalPlayer )
      v20 = LocalPlayer->m_pTransformNodeComponent;
    else
      v20 = 0i64;
    if ( v20 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(v20);
      v21 = (__m128)LODWORD(v20->mWorldTransform.v3.y);
      v22 = (__m128)LODWORD(v20->mWorldTransform.v3.z);
      navPosition.m_vPosition.x = v20->mWorldTransform.v3.x;
      LODWORD(navPosition.m_vPosition.y) = v21.m128_i32[0];
      LODWORD(navPosition.m_vPosition.z) = v22.m128_i32[0];
      navPosition.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
      navPosition.m_bValid = 0;
      *(_QWORD *)&navPosition.m_packedKey = -1i64;
      navPosition.m_hkvMeshPosition.m_quad = _mm_unpacklo_ps(
                                               _mm_unpacklo_ps((__m128)LODWORD(navPosition.m_vPosition.x), v22),
                                               _mm_unpacklo_ps(v21, (__m128)(unsigned int)FLOAT_1_0));
      UFG::FleeTraversalImmediateQuery::AddThreat(&v54, &navPosition, 100.0);
    }
  }
  else
  {
    v23 = (UFG::SimObjectGame *)v1->m_pActionContext->mSimObject.m_pPointer;
    if ( v23 )
    {
      v24 = v23->m_Flags;
      if ( (v24 >> 14) & 1 )
      {
        v25 = v23->m_Components.p[20].m_pComponent;
      }
      else if ( (v24 & 0x8000u) == 0 )
      {
        if ( (v24 >> 13) & 1 )
          v26 = UFG::SimObjectGame::GetComponentOfTypeHK(v23, UFG::TargetingSystemBaseComponent::_TypeUID);
        else
          v26 = (v24 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                    v23,
                                    UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                     (UFG::SimObject *)&v23->vfptr,
                                                                                     UFG::TargetingSystemBaseComponent::_TypeUID);
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
          UFG::FleeTraversalImmediateQuery::AddThreat(&v54, &navPosition, 100.0);
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
          UFG::FleeTraversalImmediateQuery::AddThreat(&v54, &navPosition, 100.0);
        }
      }
    }
    v35 = *(unsigned int *)&v1->m_pAIEntityComponent.m_pPointer[15].m_Flags;
    if ( v35 > 0 )
    {
      v36 = 0i64;
      do
      {
        v37 = v1->m_pAIEntityComponent.m_pPointer;
        v38 = *(__int64 *)((char *)&v37[15].m_BoundComponentHandles.mNode.mNext + v36 * 8);
        if ( v38 )
          v39 = *(_QWORD *)(v38 + 88);
        else
          v39 = 0i64;
        if ( v38 && v39 )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v39);
          v40 = *(_DWORD *)(v39 + 176);
          v41 = *(_DWORD *)(v39 + 180);
          v42 = *(_DWORD *)(v39 + 184);
          v43 = (int)(&v37[16].vfptr)[v36];
          v44 = v54.mEscapeOrigin.m_hkvMeshPosition.m_quad.m128_u32[0];
          v45 = v54.mEscapeOrigin.m_hkvMeshPosition.m_quad.m128_i32[0] + 1;
          if ( (unsigned int)(v54.mEscapeOrigin.m_hkvMeshPosition.m_quad.m128_i32[0] + 1) > v54.mEscapeOrigin.m_hkvMeshPosition.m_quad.m128_i32[1] )
          {
            if ( v54.mEscapeOrigin.m_hkvMeshPosition.m_quad.m128_i32[1] )
              v46 = 2 * v54.mEscapeOrigin.m_hkvMeshPosition.m_quad.m128_i32[1];
            else
              v46 = 1;
            for ( ; v46 < v45; v46 *= 2 )
              ;
            if ( v46 - v45 > 0x10000 )
              v46 = v54.mEscapeOrigin.m_hkvMeshPosition.m_quad.m128_i32[0] + 65537;
            UFG::qArray<UFG::FleeTraversalImmediateQuery::ThreatTarget,0>::Reallocate(
              (UFG::qArray<UFG::FleeTraversalImmediateQuery::ThreatTarget,0> *)&v54.mEscapeOrigin.m_hkvMeshPosition,
              v46,
              "qArray.Add");
          }
          v54.mEscapeOrigin.m_hkvMeshPosition.m_quad.m128_i32[0] = v45;
          v47 = v54.mEscapeOrigin.m_hkvMeshPosition.m_quad.m128_u64[1] + 80 * v44;
          *(_DWORD *)(v47 + 8) = v40;
          *(_DWORD *)(v47 + 12) = v41;
          *(_DWORD *)(v47 + 16) = v42;
          *(_BYTE *)(v47 + 24) = 0;
          *(_DWORD *)(v47 + 64) = v43;
        }
        v36 += 4i64;
        --v35;
      }
      while ( v35 );
    }
  }
  v48 = UFG::DaemonManager::Instance();
  UFG::DaemonManager::SubmitQuery(
    v48,
    (UFG::DaemonQueryInput *)&v54.vfptr,
    (UFG::DaemonQueryOutput *)(&v54.mEscapeOrigin.m_aiMeshUid + 1));
  if ( v54.mThreats.size != 3 )
  {
    LODWORD(v1->m_FleeDestination.x) = v54.m_mode;
    v7 = *((float *)&v54.m_mode + 1);
    v1->m_FleeDestination.z = *(float *)&v54.m_pOutput;
    goto LABEL_79;
  }
  v1->m_FleeDestination.x = v55.x;
  v1->m_FleeDestination.y = v55.y;
  v1->m_FleeDestination.z = v55.z;
  v49 = UFG::NavComponent::GetCurrentPosition((UFG::NavComponent *)v1->m_pNavComponent.m_pPointer);
  v50 = v49->y + v1->m_LastFleeOrigin.y;
  v51 = v49->z + v1->m_LastFleeOrigin.z;
  v1->m_LastFleeOrigin.x = (float)(v1->m_LastFleeOrigin.x + v49->x) * 0.5;
  v1->m_LastFleeOrigin.y = v50 * 0.5;
  v1->m_LastFleeOrigin.z = v51 * 0.5;
  v1->m_FailedQuery = 0;
LABEL_80:
  v52 = v59;
  if ( v59 )
  {
    --*(_DWORD *)(v59 + 40);
    if ( !*(_DWORD *)(v52 + 40) )
      (**(void (__fastcall ***)(__int64, signed __int64))v52)(v52, 1i64);
  }
  *(_QWORD *)(&v54.mEscapeOrigin.m_aiMeshUid + 1) = &UFG::DaemonQueryOutput::`vftable;
  if ( v54.mEscapeOrigin.m_hkvMeshPosition.m_quad.m128_u64[1] )
    operator delete[]((void *)v54.mEscapeOrigin.m_hkvMeshPosition.m_quad.m128_u64[1]);
}

// File Line: 1225
// RVA: 0x396F80
bool __fastcall FleeTask::UpdateInteriorFleeing(FleeTask *this)
{
  FleeTask *v1; // rdi
  UFG::NavComponent *v2; // rbp
  UFG::SimComponent *v3; // rax
  UFG::SimObject *v4; // rsi
  __int64 v5; // rbx
  __m128 v6; // xmm0
  __m128 v7; // xmm2
  UFG::HavokNavPosition npDestination; // [rsp+30h] [rbp-48h]

  v1 = this;
  if ( !this->m_pAIEntityComponent.m_pPointer )
    return 0;
  v2 = (UFG::NavComponent *)this->m_pNavComponent.m_pPointer;
  if ( !v2 )
    return 0;
  v3 = this->m_pFleeToPoint.m_pPointer;
  if ( !v3 )
    return 0;
  v4 = v3[1].m_pSimObject;
  if ( !v4 )
    return 0;
  v5 = BYTE4(this->m_Track[1].vfptr);
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v4);
  v6 = (__m128)LODWORD(v4[1].mNode.mChild[1]);
  v7 = (__m128)HIDWORD(v4[1].mNode.mChild[0]);
  npDestination.m_vPosition.x = *(float *)v4[1].mNode.mChild;
  LODWORD(npDestination.m_vPosition.y) = v7.m128_i32[0];
  npDestination.m_bValid = 0;
  *(_QWORD *)&npDestination.m_packedKey = -1i64;
  npDestination.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
  LODWORD(npDestination.m_vPosition.z) = v6.m128_i32[0];
  npDestination.m_hkvMeshPosition.m_quad = _mm_unpacklo_ps(
                                             _mm_unpacklo_ps((__m128)LODWORD(npDestination.m_vPosition.x), v6),
                                             _mm_unpacklo_ps(v7, (__m128)(unsigned int)FLOAT_1_0));
  UFG::NavComponent::AddGoalPoint(v2, &npDestination, 0, sNaturalMovementSpeeds[v5], 1.5);
  return (unsigned __int8)UFG::NavComponent::IsAtDestination((UFG::NavComponent *)v1->m_pNavComponent.m_pPointer) == 0;
}

// File Line: 1250
// RVA: 0x396450
char __fastcall FleeTask::UpdateExteriorFleeing(FleeTask *this)
{
  FleeTask *v1; // rdi
  __int64 v2; // rsi
  UFG::SimObjectGame *v3; // rcx
  UFG::NavComponent *v4; // rbx
  unsigned __int16 v5; // dx
  UFG::SimComponent *v6; // rax
  __m128 v7; // xmm0
  __m128 v8; // xmm3
  __m128 v9; // xmm2
  UFG::HavokNavPosition npDestination; // [rsp+30h] [rbp-48h]

  v1 = this;
  if ( !this->m_pAIEntityComponent.m_pPointer )
    return 0;
  v2 = BYTE4(this->m_Track[1].vfptr);
  v3 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
  if ( v3 )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v4 = (UFG::NavComponent *)v3->m_Components.p[36].m_pComponent;
    }
    else
    {
      if ( (v5 & 0x8000u) == 0 )
      {
        if ( (v5 >> 13) & 1 )
        {
          v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::NavComponent::_TypeUID);
        }
        else if ( (v5 >> 12) & 1 )
        {
          v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::NavComponent::_TypeUID);
        }
        else
        {
          v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::NavComponent::_TypeUID);
        }
      }
      else
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::NavComponent::_TypeUID);
      }
      v4 = (UFG::NavComponent *)v6;
    }
  }
  else
  {
    v4 = 0i64;
  }
  v7 = (__m128)LODWORD(v1->m_FleeDestination.z);
  v8 = (__m128)LODWORD(v1->m_FleeDestination.x);
  v9 = (__m128)LODWORD(v1->m_FleeDestination.y);
  npDestination.m_bValid = 0;
  *(_QWORD *)&npDestination.m_packedKey = -1i64;
  LODWORD(npDestination.m_vPosition.x) = v8.m128_i32[0];
  LODWORD(npDestination.m_vPosition.y) = v9.m128_i32[0];
  npDestination.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
  LODWORD(npDestination.m_vPosition.z) = v7.m128_i32[0];
  npDestination.m_hkvMeshPosition.m_quad = _mm_unpacklo_ps(
                                             _mm_unpacklo_ps(v8, v7),
                                             _mm_unpacklo_ps(v9, (__m128)(unsigned int)FLOAT_1_0));
  UFG::NavComponent::AddGoalPoint(v4, &npDestination, 0, sNaturalMovementSpeeds[v2], 1.5);
  if ( (unsigned __int8)UFG::NavComponent::IsAtDestination(v4) )
  {
    FleeTask::BeginExteriorFleeing(v1);
    return 0;
  }
  return 1;
}

// File Line: 1302
// RVA: 0x356AD0
float __fastcall FleeTask::FindNearestThreat(FleeTask *this, UFG::qVector3 *pNearestPosition)
{
  float v2; // xmm6_4
  float v3; // xmm7_4
  UFG::qVector3 *v4; // r14
  float v5; // xmm8_4
  float v6; // xmm9_4
  FleeTask *v7; // rbp
  UFG::NavComponent *v8; // rcx
  UFG::qVector4 *v9; // r15
  __m128 v10; // xmm0
  UFG::SimObjectGame *v11; // r8
  unsigned __int16 v12; // cx
  UFG::SimComponent *v13; // rbx
  UFG::SimComponent *v14; // rax
  UFG::TransformNodeComponent *v15; // rdi
  __m128 v16; // xmm1
  float v17; // xmm2_4
  UFG::TransformNodeComponent *v18; // rbx
  __m128 v19; // xmm1
  float v20; // xmm2_4
  __int64 v21; // rsi
  __int64 v22; // rdi
  __int64 v23; // rcx
  UFG::TransformNodeComponent *v24; // rbx
  __m128 v25; // xmm1
  float v26; // xmm2_4
  float result; // xmm0_4

  v2 = FLOAT_N1_0;
  v3 = this->m_LastFleeOrigin.x;
  v4 = pNearestPosition;
  v5 = this->m_LastFleeOrigin.y;
  v6 = this->m_LastFleeOrigin.z;
  v7 = this;
  if ( this->m_pAIEntityComponent.m_pPointer )
  {
    v8 = (UFG::NavComponent *)this->m_pNavComponent.m_pPointer;
    if ( v8 )
    {
      v9 = UFG::NavComponent::GetCurrentPosition(v8);
      v10 = (__m128)LODWORD(v9->y);
      v11 = (UFG::SimObjectGame *)v7->m_pActionContext->mSimObject.m_pPointer;
      v10.m128_f32[0] = (float)((float)(v10.m128_f32[0] - v7->m_LastFleeOrigin.y)
                              * (float)(v10.m128_f32[0] - v7->m_LastFleeOrigin.y))
                      + (float)((float)(v9->x - v7->m_LastFleeOrigin.x) * (float)(v9->x - v7->m_LastFleeOrigin.x));
      LODWORD(v2) = (unsigned __int128)_mm_sqrt_ps(v10);
      if ( v11 )
      {
        v12 = v11->m_Flags;
        if ( (v12 >> 14) & 1 )
        {
          v13 = v11->m_Components.p[20].m_pComponent;
        }
        else if ( (v12 & 0x8000u) == 0 )
        {
          if ( (v12 >> 13) & 1 )
            v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::TargetingSystemBaseComponent::_TypeUID);
          else
            v14 = (v12 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                      v11,
                                      UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                       (UFG::SimObject *)&v11->vfptr,
                                                                                       UFG::TargetingSystemBaseComponent::_TypeUID);
          v13 = v14;
        }
        else
        {
          v13 = v11->m_Components.p[20].m_pComponent;
        }
        if ( v13 )
        {
          v15 = *(UFG::TransformNodeComponent **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v13[1].m_Flags + 37i64)
                                                + *(_QWORD *)&v13[1].m_TypeUID
                                                + 40);
          if ( v15 )
            v15 = (UFG::TransformNodeComponent *)v15->mChildren.mNode.mNext;
          if ( v15 )
          {
            UFG::TransformNodeComponent::UpdateWorldTransform(v15);
            v16 = (__m128)LODWORD(v9->y);
            v16.m128_f32[0] = (float)((float)(v16.m128_f32[0] - v15->mWorldTransform.v3.y)
                                    * (float)(v16.m128_f32[0] - v15->mWorldTransform.v3.y))
                            + (float)((float)(v9->x - v15->mWorldTransform.v3.x)
                                    * (float)(v9->x - v15->mWorldTransform.v3.x));
            LODWORD(v17) = (unsigned __int128)_mm_sqrt_ps(v16);
            if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(v9->z - v15->mWorldTransform.v3.z) & _xmm) < 3.0
              && (v2 < 0.0 || v17 < v2) )
            {
              v2 = v17;
              v3 = v15->mWorldTransform.v3.x;
              v5 = v15->mWorldTransform.v3.y;
              v6 = v15->mWorldTransform.v3.z;
            }
          }
          v18 = *(UFG::TransformNodeComponent **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v13[1].m_Flags + 30i64)
                                                + *(_QWORD *)&v13[1].m_TypeUID
                                                + 40);
          if ( v18 )
            v18 = (UFG::TransformNodeComponent *)v18->mChildren.mNode.mNext;
          if ( v18 )
          {
            UFG::TransformNodeComponent::UpdateWorldTransform(v18);
            v19 = (__m128)LODWORD(v9->y);
            v19.m128_f32[0] = (float)((float)(v19.m128_f32[0] - v18->mWorldTransform.v3.y)
                                    * (float)(v19.m128_f32[0] - v18->mWorldTransform.v3.y))
                            + (float)((float)(v9->x - v18->mWorldTransform.v3.x)
                                    * (float)(v9->x - v18->mWorldTransform.v3.x));
            LODWORD(v20) = (unsigned __int128)_mm_sqrt_ps(v19);
            if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(v9->z - v18->mWorldTransform.v3.z) & _xmm) < 3.0
              && (v2 < 0.0 || v20 < v2) )
            {
              v2 = v20;
              v3 = v18->mWorldTransform.v3.x;
              v5 = v18->mWorldTransform.v3.y;
              v6 = v18->mWorldTransform.v3.z;
            }
          }
        }
      }
      v21 = *(unsigned int *)&v7->m_pAIEntityComponent.m_pPointer[15].m_Flags;
      if ( v21 > 0 )
      {
        v22 = 0i64;
        do
        {
          v23 = *(__int64 *)((char *)&v7->m_pAIEntityComponent.m_pPointer[15].m_BoundComponentHandles.mNode.mNext + v22);
          if ( v23 )
            v24 = *(UFG::TransformNodeComponent **)(v23 + 88);
          else
            v24 = 0i64;
          if ( v23 )
          {
            if ( v24 )
            {
              UFG::TransformNodeComponent::UpdateWorldTransform(v24);
              v25 = (__m128)LODWORD(v9->y);
              v25.m128_f32[0] = (float)((float)(v25.m128_f32[0] - v24->mWorldTransform.v3.y)
                                      * (float)(v25.m128_f32[0] - v24->mWorldTransform.v3.y))
                              + (float)((float)(v9->x - v24->mWorldTransform.v3.x)
                                      * (float)(v9->x - v24->mWorldTransform.v3.x));
              LODWORD(v26) = (unsigned __int128)_mm_sqrt_ps(v25);
              if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(v9->z - v24->mWorldTransform.v3.z) & _xmm) < 3.0
                && (v2 < 0.0 || v26 < v2) )
              {
                v2 = v26;
                v3 = v24->mWorldTransform.v3.x;
                v5 = v24->mWorldTransform.v3.y;
                v6 = v24->mWorldTransform.v3.z;
              }
            }
          }
          v22 += 32i64;
          --v21;
        }
        while ( v21 );
      }
    }
  }
  result = v2;
  if ( v4 )
  {
    v4->x = v3;
    v4->y = v5;
    v4->z = v6;
  }
  return result;
}

// File Line: 1379
// RVA: 0x38A180
void __fastcall FleeTask::TurnToFaceNearestScaryThing(FleeTask *this)
{
  FleeTask *v1; // rdi
  float v2; // xmm6_4
  UFG::SimObjectCVBase *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::AICharacterControllerBaseComponent *v5; // rax
  float *v6; // rbx
  UFG::qVector4 *v7; // rax
  float v8; // xmm2_4
  __m128 v9; // xmm3
  float v10; // xmm4_4
  __m128 v11; // xmm5
  UFG::qVector3 pNearestPosition; // [rsp+20h] [rbp-28h]

  v1 = this;
  if ( this->m_pAIEntityComponent.m_pPointer )
  {
    if ( this->m_pNavComponent.m_pPointer )
    {
      pNearestPosition = UFG::qVector3::msZero;
      v2 = 0.0;
      if ( FleeTask::FindNearestThreat(this, &pNearestPosition) >= 0.0 )
      {
        v3 = (UFG::SimObjectCVBase *)v1->m_pActionContext->mSimObject.m_pPointer;
        if ( v3 )
        {
          v4 = v3->m_Flags;
          if ( (v4 >> 14) & 1 )
          {
            v5 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v3);
          }
          else if ( (v4 & 0x8000u) == 0 )
          {
            if ( (v4 >> 13) & 1 )
              v5 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                (UFG::SimObjectGame *)&v3->vfptr,
                                                                UFG::AICharacterControllerBaseComponent::_TypeUID);
            else
              v5 = (UFG::AICharacterControllerBaseComponent *)((v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                                  (UFG::SimObjectGame *)&v3->vfptr,
                                                                                  UFG::AICharacterControllerBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::AICharacterControllerBaseComponent::_TypeUID));
          }
          else
          {
            v5 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v3);
          }
          v6 = (float *)v5;
          if ( v5 )
          {
            v7 = UFG::NavComponent::GetCurrentPosition((UFG::NavComponent *)v1->m_pNavComponent.m_pPointer);
            v9 = (__m128)LODWORD(pNearestPosition.y);
            v8 = pNearestPosition.x - v7->x;
            v9.m128_f32[0] = pNearestPosition.y - v7->y;
            v10 = pNearestPosition.z - v7->z;
            v11 = v9;
            v11.m128_f32[0] = (float)((float)(v9.m128_f32[0] * v9.m128_f32[0]) + (float)(v8 * v8)) + (float)(v10 * v10);
            if ( v11.m128_f32[0] != 0.0 )
              v2 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v11));
            v6[37] = v8 * v2;
            v6[38] = v9.m128_f32[0] * v2;
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
  ITrack *v1; // rax
  bool v2; // bp
  FleeTask *v3; // rsi
  UFG::SimComponent *v4; // rax
  UFG::NavComponent *v5; // rcx
  UFG::qVector4 *v6; // rdi
  float *v7; // rbx
  __m128 v8; // xmm2
  float v9; // xmm0_4

  v1 = this->m_Track;
  v2 = this->m_CurrentlyInInterior;
  v3 = this;
  if ( BYTE1(v1[1].mMasterRate.expression.mOffset) )
  {
    this->m_CurrentlyInInterior = BYTE1(v1[1].mMasterRate.expression.mOffset) == 1;
    goto LABEL_13;
  }
  if ( v2 )
  {
    v4 = this->m_pFleeToPoint.m_pPointer;
    if ( v4 )
    {
      if ( v4[1].m_pSimObject )
      {
        v5 = (UFG::NavComponent *)this->m_pNavComponent.m_pPointer;
        if ( v5 )
        {
          v6 = UFG::NavComponent::GetCurrentPosition(v5);
          v7 = (float *)v3->m_pFleeToPoint.m_pPointer[1].m_pSimObject;
          UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v3->m_pFleeToPoint.m_pPointer[1].m_pSimObject);
          v8 = (__m128)LODWORD(v6->y);
          v9 = v6->z - v7[46];
          v8.m128_f32[0] = (float)((float)((float)(v8.m128_f32[0] - v7[45]) * (float)(v8.m128_f32[0] - v7[45]))
                                 + (float)((float)(v6->x - v7[44]) * (float)(v6->x - v7[44])))
                         + (float)(v9 * v9);
          if ( COERCE_FLOAT(_mm_sqrt_ps(v8)) >= 5.0 )
            goto LABEL_13;
        }
      }
    }
  }
  else if ( (float)(UFG::Metrics::msInstance.mSimTime_Temp - this->m_LastTimeInteriorStatusChanged) <= 2.0 )
  {
    goto LABEL_13;
  }
  v3->m_CurrentlyInInterior = BYTE4(v3->m_pActorAudioComponent.m_pPointer[5].vfptr) != 0;
LABEL_13:
  if ( v3->m_CurrentlyInInterior != v2 )
    v3->m_LastTimeInteriorStatusChanged = UFG::Metrics::msInstance.mSimTime_Temp;
}

// File Line: 1492
// RVA: 0x344BD0
void __fastcall FleeTask::Begin(FleeTask *this, ActionContext *action_context)
{
  FleeTask *v2; // rdi
  UFG::SimObjectCVBase *v3; // rcx
  UFG::ActiveAIEntityComponent *v4; // r8
  unsigned __int16 v5; // dx
  UFG::ActiveAIEntityComponent *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::SimObjectGame *v11; // rcx
  UFG::SimComponent *v12; // r8
  unsigned __int16 v13; // dx
  UFG::SimComponent *v14; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::NavComponent> *v15; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rax
  UFG::SimObjectCharacter *v19; // rcx
  UFG::ActorAudioComponent *v20; // r8
  unsigned __int16 v21; // dx
  UFG::ActorAudioComponent *v22; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActorAudioComponent> *v23; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v24; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v25; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v26; // rax
  UFG::NavComponent *v27; // rcx
  UFG::qVector4 *v28; // rax
  float v29; // xmm0_4
  float v30; // xmm1_4
  UFG::SimObject *v31; // rbx
  UFG::PedSpawnManager *v32; // rax
  UFG::SimComponent *v33; // rax

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
        v6 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v3);
      }
      else if ( (v5 & 0x8000u) == 0 )
      {
        if ( (v5 >> 13) & 1 )
        {
          v6 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)&v3->vfptr,
                                                 UFG::ActiveAIEntityComponent::_TypeUID);
        }
        else if ( (v5 >> 12) & 1 )
        {
          v6 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)&v3->vfptr,
                                                 UFG::ActiveAIEntityComponent::_TypeUID);
        }
        else
        {
          v6 = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                 (UFG::SimObject *)&v3->vfptr,
                                                 UFG::ActiveAIEntityComponent::_TypeUID);
        }
      }
      else
      {
        v6 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v3);
      }
      v4 = v6;
    }
    else
    {
      v4 = 0i64;
    }
    v7 = &v2->m_pAIEntityComponent;
    if ( v2->m_pAIEntityComponent.m_pPointer )
    {
      v8 = v7->mPrev;
      v9 = v2->m_pAIEntityComponent.mNext;
      v8->mNext = v9;
      v9->mPrev = v8;
      v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
      v2->m_pAIEntityComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pAIEntityComponent.mPrev;
    }
    v2->m_pAIEntityComponent.m_pPointer = (UFG::SimComponent *)&v4->vfptr;
    if ( v4 )
    {
      v10 = v4->m_SafePointerList.mNode.mPrev;
      v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
      v7->mPrev = v10;
      v2->m_pAIEntityComponent.mNext = &v4->m_SafePointerList.mNode;
      v4->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    }
    v11 = (UFG::SimObjectGame *)v2->m_pActionContext->mSimObject.m_pPointer;
    if ( v11 )
    {
      v13 = v11->m_Flags;
      if ( (v13 >> 14) & 1 )
      {
        v12 = v11->m_Components.p[36].m_pComponent;
      }
      else
      {
        if ( (v13 & 0x8000u) == 0 )
        {
          if ( (v13 >> 13) & 1 )
          {
            v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::NavComponent::_TypeUID);
          }
          else if ( (v13 >> 12) & 1 )
          {
            v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::NavComponent::_TypeUID);
          }
          else
          {
            v14 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v11->vfptr, UFG::NavComponent::_TypeUID);
          }
        }
        else
        {
          v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::NavComponent::_TypeUID);
        }
        v12 = v14;
      }
    }
    else
    {
      v12 = 0i64;
    }
    v15 = &v2->m_pNavComponent;
    if ( v2->m_pNavComponent.m_pPointer )
    {
      v16 = v15->mPrev;
      v17 = v2->m_pNavComponent.mNext;
      v16->mNext = v17;
      v17->mPrev = v16;
      v15->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v15->mPrev;
      v2->m_pNavComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pNavComponent.mPrev;
    }
    v2->m_pNavComponent.m_pPointer = v12;
    if ( v12 )
    {
      v18 = v12->m_SafePointerList.mNode.mPrev;
      v18->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v15->mPrev;
      v15->mPrev = v18;
      v2->m_pNavComponent.mNext = &v12->m_SafePointerList.mNode;
      v12->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v15->mPrev;
    }
    v19 = (UFG::SimObjectCharacter *)v2->m_pActionContext->mSimObject.m_pPointer;
    if ( v19 )
    {
      v21 = v19->m_Flags;
      if ( (v21 >> 14) & 1 )
      {
        v22 = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(v19);
      }
      else if ( (v21 & 0x8000u) == 0 )
      {
        if ( (v21 >> 13) & 1 )
        {
          v22 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              (UFG::SimObjectGame *)&v19->vfptr,
                                              UFG::ActorAudioComponent::_TypeUID);
        }
        else if ( (v21 >> 12) & 1 )
        {
          v22 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              (UFG::SimObjectGame *)&v19->vfptr,
                                              UFG::ActorAudioComponent::_TypeUID);
        }
        else
        {
          v22 = (UFG::ActorAudioComponent *)UFG::SimObject::GetComponentOfType(
                                              (UFG::SimObject *)&v19->vfptr,
                                              UFG::ActorAudioComponent::_TypeUID);
        }
      }
      else
      {
        v22 = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                            (UFG::SimObjectGame *)&v19->vfptr,
                                            UFG::ActorAudioComponent::_TypeUID);
      }
      v20 = v22;
    }
    else
    {
      v20 = 0i64;
    }
    v23 = &v2->m_pActorAudioComponent;
    if ( v2->m_pActorAudioComponent.m_pPointer )
    {
      v24 = v23->mPrev;
      v25 = v2->m_pActorAudioComponent.mNext;
      v24->mNext = v25;
      v25->mPrev = v24;
      v23->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v23->mPrev;
      v2->m_pActorAudioComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pActorAudioComponent.mPrev;
    }
    v2->m_pActorAudioComponent.m_pPointer = (UFG::SimComponent *)&v20->vfptr;
    if ( v20 )
    {
      v26 = v20->m_SafePointerList.mNode.mPrev;
      v26->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v23->mPrev;
      v23->mPrev = v26;
      v2->m_pActorAudioComponent.mNext = &v20->m_SafePointerList.mNode;
      v20->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v23->mPrev;
    }
  }
  v27 = (UFG::NavComponent *)v2->m_pNavComponent.m_pPointer;
  v2->m_LastTimeInteriorStatusChanged = -99999.0;
  v28 = UFG::NavComponent::GetCurrentPosition(v27);
  v29 = v28->y;
  v30 = v28->z;
  v2->m_LastFleeOrigin.x = v28->x;
  v2->m_LastFleeOrigin.y = v29;
  v2->m_LastFleeOrigin.z = v30;
  v2->m_FailedRetryCount = 0.0;
  v2->m_FailedQuery = 1;
  FleeTask::UpdateWhetherCurrentlyInInterior(v2);
  v31 = v2->m_pActionContext->mSimObject.m_pPointer;
  v32 = UFG::PedSpawnManager::GetInstance();
  v33 = UFG::PedSpawnManager::FindPedInfoFromSimObject(v32, v31);
  if ( v33 && LODWORD(v33[12].m_BoundComponentHandles.mNode.mPrev) == 1 )
    *(_DWORD *)(&v33[10].m_SimObjIndex + 1) = 4;
  if ( v2->m_CurrentlyInInterior )
    FleeTask::BeginInteriorFleeing(v2);
  else
    FleeTask::BeginExteriorFleeing(v2);
}

// File Line: 1531
// RVA: 0x38EB80
char __fastcall FleeTask::Update(FleeTask *this, float timestep)
{
  FleeTask *v2; // rdi
  bool v3; // bl
  bool v4; // al
  bool v5; // al
  bool v6; // al
  UFG::qVector4 *v7; // rax
  UFG::qVector3 pNearestPosition; // [rsp+20h] [rbp-38h]

  v2 = this;
  if ( this->m_pAIEntityComponent.m_pPointer )
  {
    v3 = this->m_CurrentlyInInterior;
    FleeTask::UpdateWhetherCurrentlyInInterior(this);
    v4 = v2->m_CurrentlyInInterior;
    if ( v3 != v4 )
    {
      if ( v4 )
        FleeTask::BeginInteriorFleeing(v2);
      else
        FleeTask::BeginExteriorFleeing(v2);
    }
    if ( v2->m_CurrentlyInInterior && v2->m_pFleeToPoint.m_pPointer )
      v5 = FleeTask::UpdateInteriorFleeing(v2);
    else
      v5 = FleeTask::UpdateExteriorFleeing(v2);
    if ( !v5 )
      FleeTask::TurnToFaceNearestScaryThing(v2);
    v6 = UFG::NavComponent::IsDestinationUnreachable((UFG::NavComponent *)v2->m_pNavComponent.m_pPointer);
    if ( v6 || v2->m_FailedQuery )
      v6 = 1;
    if ( v6 )
    {
      v2->m_FailedRetryCount = fmodf(v2->m_FailedRetryCount + 1.0, *(float *)&v2->m_Track[1].mResourceOwner);
    }
    else
    {
      if ( (float)(UFG::Metrics::msInstance.mSimTime_Temp - v2->m_LastTimeFleeDirectionChecked) <= 0.5 )
        return 1;
      v2->m_LastTimeFleeDirectionChecked = UFG::Metrics::msInstance.mSimTime_Temp;
      FleeTask::FindNearestThreat(v2, &pNearestPosition);
      v7 = UFG::NavComponent::GetCurrentPosition((UFG::NavComponent *)v2->m_pNavComponent.m_pPointer);
      if ( (float)((float)((float)((float)(v2->m_FleeDestination.y - v7->y) * (float)(pNearestPosition.y - v7->y))
                         + (float)((float)(v2->m_FleeDestination.x - v7->x) * (float)(pNearestPosition.x - v7->x)))
                 + (float)((float)(v2->m_FleeDestination.z - v7->z) * (float)(pNearestPosition.z - v7->z))) < 0.0 )
        return 1;
    }
    if ( v2->m_CurrentlyInInterior )
    {
      FleeTask::BeginInteriorFleeing(v2);
      return 1;
    }
    FleeTask::BeginExteriorFleeing(v2);
    return 1;
  }
  return 0;
}

// File Line: 1660
// RVA: 0x355000
void __fastcall FleeTask::End(FleeTask *this)
{
  FleeTask *v1; // rbx
  UFG::SimObject *v2; // r8
  unsigned __int16 v3; // cx
  UFG::InterestPointUserComponent *v4; // rax

  v1 = this;
  UFG::GroupComponent::LeaveGroup(this->m_pActionContext->mSimObject.m_pPointer);
  v2 = v1->m_pActionContext->mSimObject.m_pPointer;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = (UFG::InterestPointUserComponent *)v2->m_Components.p[43].m_pComponent;
    }
    else
    {
      if ( (v3 & 0x8000u) != 0 )
        return;
      if ( (v3 >> 13) & 1 )
      {
        v4 = (UFG::InterestPointUserComponent *)v2->m_Components.p[12].m_pComponent;
      }
      else
      {
        if ( (v3 >> 12) & 1 )
          return;
        v4 = (UFG::InterestPointUserComponent *)UFG::SimObject::GetComponentOfType(
                                                  v2,
                                                  UFG::InterestPointUserComponent::_TypeUID);
      }
    }
    if ( v4 )
      UFG::InterestPointUserComponent::StopPOI(v4);
  }
}

// File Line: 1693
// RVA: 0x32F650
void __fastcall HangOutTask::HangOutTask(HangOutTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<HangOutTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&HangOutTask::`vftable;
  v2 = &this->m_pAIEntityComponent;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  this->m_pAIEntityComponent.m_pPointer = 0i64;
  this->m_pActionContext = 0i64;
  if ( this->m_pAIEntityComponent.m_pPointer )
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

// File Line: 1701
// RVA: 0x338050
void __fastcall HangOutTask::~HangOutTask(HangOutTask *this)
{
  HangOutTask *v1; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rdx
  UFG::qNode<ITask,ITask> *v8; // rcx
  UFG::qNode<ITask,ITask> *v9; // rax

  v1 = this;
  this->vfptr = (ITaskVtbl *)&HangOutTask::`vftable;
  v2 = &this->m_pAIEntityComponent;
  if ( this->m_pAIEntityComponent.m_pPointer )
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
  v1->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v7 = (UFG::qNode<ITask,ITask> *)&v1->mPrev;
  v8 = v1->mPrev;
  v9 = v1->mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v7->mPrev = v7;
  v7->mNext = v7;
}

// File Line: 1706
// RVA: 0x348840
void __fastcall SetCurrentEmotionTask::Begin(SetFacialEmotionTask *this, ActionContext *action_context)
{
  SetFacialEmotionTask *v2; // rbx
  UFG::SimObjectCVBase *v3; // rcx
  UFG::ActiveAIEntityComponent *v4; // r8
  unsigned __int16 v5; // dx
  UFG::ActiveAIEntityComponent *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax

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
        v6 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v3);
      }
      else if ( (v5 & 0x8000u) == 0 )
      {
        if ( (v5 >> 13) & 1 )
        {
          v6 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)&v3->vfptr,
                                                 UFG::ActiveAIEntityComponent::_TypeUID);
        }
        else if ( (v5 >> 12) & 1 )
        {
          v6 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)&v3->vfptr,
                                                 UFG::ActiveAIEntityComponent::_TypeUID);
        }
        else
        {
          v6 = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                 (UFG::SimObject *)&v3->vfptr,
                                                 UFG::ActiveAIEntityComponent::_TypeUID);
        }
      }
      else
      {
        v6 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v3);
      }
      v4 = v6;
    }
    else
    {
      v4 = 0i64;
    }
    v7 = &v2->m_pAIEntityComponent;
    if ( v2->m_pAIEntityComponent.m_pPointer )
    {
      v8 = v7->mPrev;
      v9 = v2->m_pAIEntityComponent.mNext;
      v8->mNext = v9;
      v9->mPrev = v8;
      v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
      v2->m_pAIEntityComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pAIEntityComponent.mPrev;
    }
    v2->m_pAIEntityComponent.m_pPointer = (UFG::SimComponent *)&v4->vfptr;
    if ( v4 )
    {
      v10 = v4->m_SafePointerList.mNode.mPrev;
      v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
      v7->mPrev = v10;
      v2->m_pAIEntityComponent.mNext = &v4->m_SafePointerList.mNode;
      v4->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    }
  }
}

// File Line: 1742
// RVA: 0x32FC30
void __fastcall IdleTask::IdleTask(IdleTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<IdleTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&IdleTask::`vftable;
  v2 = &this->m_pAIEntityComponent;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  this->m_pAIEntityComponent.m_pPointer = 0i64;
  this->m_pActionContext = 0i64;
  if ( this->m_pAIEntityComponent.m_pPointer )
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

// File Line: 1750
// RVA: 0x3387D0
void __fastcall IdleTask::~IdleTask(IdleTask *this)
{
  IdleTask *v1; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rdx
  UFG::qNode<ITask,ITask> *v8; // rcx
  UFG::qNode<ITask,ITask> *v9; // rax

  v1 = this;
  this->vfptr = (ITaskVtbl *)&IdleTask::`vftable;
  v2 = &this->m_pAIEntityComponent;
  if ( this->m_pAIEntityComponent.m_pPointer )
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
  v1->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v7 = (UFG::qNode<ITask,ITask> *)&v1->mPrev;
  v8 = v1->mPrev;
  v9 = v1->mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v7->mPrev = v7;
  v7->mNext = v7;
}

// File Line: 1791
// RVA: 0x32E0E0
void __fastcall FacialRequestTask::FacialRequestTask(FacialRequestTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<FacialRequestTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&FacialRequestTask::`vftable;
  v2 = &this->m_pAIEntityComponent;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  this->m_pAIEntityComponent.m_pPointer = 0i64;
  this->m_pActionContext = 0i64;
  if ( this->m_pAIEntityComponent.m_pPointer )
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

// File Line: 1799
// RVA: 0x3366D0
void __fastcall FacialRequestTask::~FacialRequestTask(FacialRequestTask *this)
{
  FacialRequestTask *v1; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rdx
  UFG::qNode<ITask,ITask> *v8; // rcx
  UFG::qNode<ITask,ITask> *v9; // rax

  v1 = this;
  this->vfptr = (ITaskVtbl *)&FacialRequestTask::`vftable;
  v2 = &this->m_pAIEntityComponent;
  if ( this->m_pAIEntityComponent.m_pPointer )
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
  v1->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v7 = (UFG::qNode<ITask,ITask> *)&v1->mPrev;
  v8 = v1->mPrev;
  v9 = v1->mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v7->mPrev = v7;
  v7->mNext = v7;
}

// File Line: 1804
// RVA: 0x3448C0
void __fastcall FacialRequestTask::Begin(FacialRequestTask *this, ActionContext *action_context)
{
  UFG::SimComponent *v2; // rdi
  FacialRequestTask *v3; // rbx
  UFG::SimObjectCVBase *v4; // rcx
  UFG::ActiveAIEntityComponent *v5; // r8
  unsigned __int16 v6; // dx
  UFG::ActiveAIEntityComponent *v7; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v8; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::SimObject *v12; // rcx

  v2 = 0i64;
  v3 = this;
  this->m_pActionContext = action_context;
  this->m_fChargeTime = 0.0;
  if ( action_context )
  {
    v4 = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
    if ( v4 )
    {
      v6 = v4->m_Flags;
      if ( (v6 >> 14) & 1 )
      {
        v7 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v4);
      }
      else if ( (v6 & 0x8000u) == 0 )
      {
        if ( (v6 >> 13) & 1 )
        {
          v7 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)&v4->vfptr,
                                                 UFG::ActiveAIEntityComponent::_TypeUID);
        }
        else if ( (v6 >> 12) & 1 )
        {
          v7 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)&v4->vfptr,
                                                 UFG::ActiveAIEntityComponent::_TypeUID);
        }
        else
        {
          v7 = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                 (UFG::SimObject *)&v4->vfptr,
                                                 UFG::ActiveAIEntityComponent::_TypeUID);
        }
      }
      else
      {
        v7 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v4);
      }
      v5 = v7;
    }
    else
    {
      v5 = 0i64;
    }
    v8 = &v3->m_pAIEntityComponent;
    if ( v3->m_pAIEntityComponent.m_pPointer )
    {
      v9 = v8->mPrev;
      v10 = v3->m_pAIEntityComponent.mNext;
      v9->mNext = v10;
      v10->mPrev = v9;
      v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
      v3->m_pAIEntityComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->m_pAIEntityComponent.mPrev;
    }
    v3->m_pAIEntityComponent.m_pPointer = (UFG::SimComponent *)&v5->vfptr;
    if ( v5 )
    {
      v11 = v5->m_SafePointerList.mNode.mPrev;
      v11->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
      v8->mPrev = v11;
      v3->m_pAIEntityComponent.mNext = &v5->m_SafePointerList.mNode;
      v5->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
    }
    if ( WORD1(v3->m_Track[1].vfptr) == 1 )
    {
      v12 = v3->m_pActionContext->mSimObject.m_pPointer;
      if ( v12 )
        v2 = UFG::SimObject::GetComponentOfType(v12, UFG::AICharacterControllerBaseComponent::_TypeUID);
      v3->m_fChargeTime = (float)*((unsigned __int8 *)&v2[5].m_BoundComponentHandles.mNode.mNext
                                 + (unsigned int)SLOWORD(v3->m_Track[1].vfptr))
                        * 0.016666668;
    }
  }
  FacialRequestTask::DoIntentionSetting(v3);
}

// File Line: 1834
// RVA: 0x38EA10
char __fastcall FacialRequestTask::Update(FacialRequestTask *this, float timestep)
{
  ITrack *v2; // rax

  v2 = this->m_Track;
  if ( BYTE4(v2[1].vfptr) )
  {
    if ( WORD1(v2[1].vfptr) == 1 )
      this->m_fChargeTime = timestep + this->m_fChargeTime;
    FacialRequestTask::DoIntentionSetting(this);
  }
  return 1;
}

// File Line: 1852
// RVA: 0x352CF0
void __fastcall FacialRequestTask::DoIntentionSetting(FacialRequestTask *this)
{
  FacialRequestTask *v1; // rbx
  UFG::SimObjectCVBase *v2; // rcx
  UFG::AICharacterControllerBaseComponent *v3; // r9
  unsigned __int16 v4; // dx
  UFG::AICharacterControllerBaseComponent *v5; // rax
  __int64 v6; // r10
  float v7; // xmm0_4
  float v8; // xmm1_4

  v1 = this;
  v2 = (UFG::SimObjectCVBase *)this->m_pActionContext->mSimObject.m_pPointer;
  if ( v2 )
  {
    v4 = v2->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v2);
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
      {
        v5 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          (UFG::SimObjectGame *)&v2->vfptr,
                                                          UFG::AICharacterControllerBaseComponent::_TypeUID);
      }
      else if ( (v4 >> 12) & 1 )
      {
        v5 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          (UFG::SimObjectGame *)&v2->vfptr,
                                                          UFG::AICharacterControllerBaseComponent::_TypeUID);
      }
      else
      {
        v5 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                          (UFG::SimObject *)&v2->vfptr,
                                                          UFG::AICharacterControllerBaseComponent::_TypeUID);
      }
    }
    else
    {
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v2);
    }
    v3 = v5;
  }
  else
  {
    v3 = 0i64;
  }
  v6 = SLOWORD(v1->m_Track[1].vfptr);
  v7 = v1->m_fChargeTime * 60.0;
  v3->m_Intention.mFacialRequests.mBits[v6 >> 6] |= 1i64 << ((_QWORD)v1->m_Track[1].vfptr & 0x3F);
  v8 = (float)(signed int)v7;
  if ( v8 >= 255.0 )
    v8 = FLOAT_255_0;
  v3->m_Intention.mFacialRequestChargeTimes[v6] = (signed int)v8;
}

// File Line: 1879
// RVA: 0x32C270
void __fastcall ActionRequestTask::ActionRequestTask(ActionRequestTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<ActionRequestTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&ActionRequestTask::`vftable;
  v2 = &this->m_pAIEntityComponent;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  this->m_pAIEntityComponent.m_pPointer = 0i64;
  this->m_pActionContext = 0i64;
  if ( this->m_pAIEntityComponent.m_pPointer )
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

// File Line: 1887
// RVA: 0x334EF0
void __fastcall ActionRequestTask::~ActionRequestTask(ActionRequestTask *this)
{
  ActionRequestTask *v1; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rdx
  UFG::qNode<ITask,ITask> *v8; // rcx
  UFG::qNode<ITask,ITask> *v9; // rax

  v1 = this;
  this->vfptr = (ITaskVtbl *)&ActionRequestTask::`vftable;
  v2 = &this->m_pAIEntityComponent;
  if ( this->m_pAIEntityComponent.m_pPointer )
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
  v1->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v7 = (UFG::qNode<ITask,ITask> *)&v1->mPrev;
  v8 = v1->mPrev;
  v9 = v1->mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v7->mPrev = v7;
  v7->mNext = v7;
}

// File Line: 1892
// RVA: 0x343C50
void __fastcall ActionRequestTask::Begin(ActionRequestTask *this, ActionContext *action_context)
{
  UFG::AICharacterControllerBaseComponent *v2; // rbx
  ActionRequestTask *v3; // rdi
  UFG::SimObjectCVBase *v4; // rcx
  UFG::ActiveAIEntityComponent *v5; // r8
  unsigned __int16 v6; // dx
  UFG::ActiveAIEntityComponent *v7; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v8; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::SimObjectCVBase *v12; // rcx
  unsigned __int16 v13; // dx
  UFG::AICharacterControllerBaseComponent *v14; // rax
  unsigned int v15; // edx
  bool v16; // zf

  v2 = 0i64;
  v3 = this;
  this->m_pActionContext = action_context;
  this->m_fChargeTime = 0.0;
  if ( action_context )
  {
    v4 = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
    if ( v4 )
    {
      v6 = v4->m_Flags;
      if ( (v6 >> 14) & 1 )
      {
        v7 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v4);
      }
      else if ( (v6 & 0x8000u) == 0 )
      {
        if ( (v6 >> 13) & 1 )
        {
          v7 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)&v4->vfptr,
                                                 UFG::ActiveAIEntityComponent::_TypeUID);
        }
        else if ( (v6 >> 12) & 1 )
        {
          v7 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)&v4->vfptr,
                                                 UFG::ActiveAIEntityComponent::_TypeUID);
        }
        else
        {
          v7 = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                 (UFG::SimObject *)&v4->vfptr,
                                                 UFG::ActiveAIEntityComponent::_TypeUID);
        }
      }
      else
      {
        v7 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v4);
      }
      v5 = v7;
    }
    else
    {
      v5 = 0i64;
    }
    v8 = &v3->m_pAIEntityComponent;
    if ( v3->m_pAIEntityComponent.m_pPointer )
    {
      v9 = v8->mPrev;
      v10 = v3->m_pAIEntityComponent.mNext;
      v9->mNext = v10;
      v10->mPrev = v9;
      v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
      v3->m_pAIEntityComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->m_pAIEntityComponent.mPrev;
    }
    v3->m_pAIEntityComponent.m_pPointer = (UFG::SimComponent *)&v5->vfptr;
    if ( v5 )
    {
      v11 = v5->m_SafePointerList.mNode.mPrev;
      v11->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
      v8->mPrev = v11;
      v3->m_pAIEntityComponent.mNext = &v5->m_SafePointerList.mNode;
      v5->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
    }
    if ( WORD1(v3->m_Track[1].vfptr) == 1 )
    {
      v12 = (UFG::SimObjectCVBase *)v3->m_pActionContext->mSimObject.m_pPointer;
      if ( !v12 )
      {
LABEL_29:
        v3->m_fChargeTime = (float)(unsigned __int8)v2->m_Intention.mActionRequestChargeTimes[SLOWORD(v3->m_Track[1].vfptr)]
                          * 0.016666668;
        goto LABEL_30;
      }
      v13 = v12->m_Flags;
      if ( (v13 >> 14) & 1 || (v13 & 0x8000u) != 0 )
      {
        v14 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v12);
      }
      else
      {
        if ( (v13 >> 13) & 1 )
        {
          v15 = UFG::AICharacterControllerBaseComponent::_TypeUID;
        }
        else
        {
          v16 = ((v13 >> 12) & 1) == 0;
          v15 = UFG::AICharacterControllerBaseComponent::_TypeUID;
          if ( v16 )
          {
            v14 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                               (UFG::SimObject *)&v12->vfptr,
                                                               UFG::AICharacterControllerBaseComponent::_TypeUID);
            goto LABEL_28;
          }
        }
        v14 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                           (UFG::SimObjectGame *)&v12->vfptr,
                                                           v15);
      }
LABEL_28:
      v2 = v14;
      goto LABEL_29;
    }
  }
LABEL_30:
  ActionRequestTask::DoIntentionSetting(v3);
}

// File Line: 1922
// RVA: 0x38C860
char __fastcall ActionRequestTask::Update(ActionRequestTask *this, float timestep)
{
  ITrack *v2; // rax

  v2 = this->m_Track;
  if ( BYTE4(v2[1].vfptr) )
  {
    if ( WORD1(v2[1].vfptr) == 1 )
      this->m_fChargeTime = timestep + this->m_fChargeTime;
    ActionRequestTask::DoIntentionSetting(this);
  }
  return 1;
}

// File Line: 1940
// RVA: 0x352C00
void __fastcall ActionRequestTask::DoIntentionSetting(ActionRequestTask *this)
{
  ActionRequestTask *v1; // rbx
  UFG::SimObjectCVBase *v2; // rcx
  UFG::AICharacterControllerBaseComponent *v3; // rdx
  unsigned __int16 v4; // dx
  UFG::AICharacterControllerBaseComponent *v5; // rax
  __int64 v6; // r9
  signed __int64 v7; // r8
  float v8; // xmm0_4
  float v9; // xmm1_4

  v1 = this;
  v2 = (UFG::SimObjectCVBase *)this->m_pActionContext->mSimObject.m_pPointer;
  if ( v2 )
  {
    v4 = v2->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v2);
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
      {
        v5 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          (UFG::SimObjectGame *)&v2->vfptr,
                                                          UFG::AICharacterControllerBaseComponent::_TypeUID);
      }
      else if ( (v4 >> 12) & 1 )
      {
        v5 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          (UFG::SimObjectGame *)&v2->vfptr,
                                                          UFG::AICharacterControllerBaseComponent::_TypeUID);
      }
      else
      {
        v5 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                          (UFG::SimObject *)&v2->vfptr,
                                                          UFG::AICharacterControllerBaseComponent::_TypeUID);
      }
    }
    else
    {
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v2);
    }
    v3 = v5;
  }
  else
  {
    v3 = 0i64;
  }
  v6 = SLOWORD(v1->m_Track[1].vfptr);
  v7 = 1i64 << ((_QWORD)v1->m_Track[1].vfptr & 0x3F);
  v8 = v1->m_fChargeTime * 60.0;
  v3->m_Intention.mActionRequests.mBits[v6 >> 6] |= v7;
  v9 = (float)(signed int)v8;
  if ( v9 >= 255.0 )
    v9 = FLOAT_255_0;
  v3->m_Intention.mActionRequestChargeTimes[v6] = (signed int)v9;
  v3->m_Intention.mSignals |= v7;
}

// File Line: 1967
// RVA: 0x32C1C0
void __fastcall ActionRequestClearTask::ActionRequestClearTask(ActionRequestClearTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v2; // [rsp+28h] [rbp+10h]

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<ActionRequestClearTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&ActionRequestClearTask::`vftable;
  v2 = &this->m_pAIEntityComponent;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  this->m_pAIEntityComponent.m_pPointer = 0i64;
  this->m_pActionContext = 0i64;
}

// File Line: 1974
// RVA: 0x334DF0
void __fastcall ActionRequestClearTask::~ActionRequestClearTask(ActionRequestClearTask *this)
{
  ActionRequestClearTask *v1; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rdx
  UFG::qNode<ITask,ITask> *v8; // rcx
  UFG::qNode<ITask,ITask> *v9; // rax

  v1 = this;
  this->vfptr = (ITaskVtbl *)&ActionRequestClearTask::`vftable;
  v2 = &this->m_pAIEntityComponent;
  if ( this->m_pAIEntityComponent.m_pPointer )
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
  v1->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v7 = (UFG::qNode<ITask,ITask> *)&v1->mPrev;
  v8 = v1->mPrev;
  v9 = v1->mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v7->mPrev = v7;
  v7->mNext = v7;
}

// File Line: 1988
// RVA: 0x38C7B0
char __fastcall ActionRequestClearTask::Update(ActionRequestClearTask *this, float timestep)
{
  ActionRequestClearTask *v2; // rbx
  UFG::SimObjectCVBase *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::AICharacterControllerBaseComponent *v5; // rax
  UFG::AICharacterControllerBaseComponent *v6; // rdx
  __int64 v7; // rax

  v2 = this;
  v3 = (UFG::SimObjectCVBase *)this->m_pActionContext->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v3);
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
      {
        v5 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          (UFG::SimObjectGame *)&v3->vfptr,
                                                          UFG::AICharacterControllerBaseComponent::_TypeUID);
      }
      else if ( (v4 >> 12) & 1 )
      {
        v5 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          (UFG::SimObjectGame *)&v3->vfptr,
                                                          UFG::AICharacterControllerBaseComponent::_TypeUID);
      }
      else
      {
        v5 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                          (UFG::SimObject *)&v3->vfptr,
                                                          UFG::AICharacterControllerBaseComponent::_TypeUID);
      }
    }
    else
    {
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v3);
    }
    v6 = v5;
    if ( v5 )
    {
      v7 = SLOWORD(v2->m_Track[1].vfptr);
      v6->m_Intention.mActionRequests.mBits[v7 >> 6] &= ~(1i64 << (v7 & 0x3F));
    }
  }
  return 1;
}

// File Line: 2020
// RVA: 0x32B850
void __fastcall AIObjectiveTask::AIObjectiveTask(AIObjectiveTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<AIObjectiveTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&AIObjectiveTask::`vftable;
}

// File Line: 2032
// RVA: 0x3434F0
void __fastcall AIObjectiveTask::Begin(AIObjectiveTask *this, ActionContext *action_context)
{
  AIObjectiveTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  ActionContext *v4; // rsi
  unsigned __int16 v5; // r8
  UFG::SimComponent *v6; // rax
  UFG::SimObjectCVBase *v7; // rcx
  unsigned __int16 v8; // dx
  UFG::ActiveAIEntityComponent *v9; // rax
  UFG::ActiveAIEntityComponent *v10; // rdi
  UFG::eAIObjective v11; // ebx
  const char *v12; // rax

  if ( action_context )
  {
    v2 = this;
    v3 = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
    v4 = action_context;
    if ( v3 )
    {
      v5 = v3->m_Flags;
      if ( (v5 >> 14) & 1 )
      {
        v6 = v3->m_Components.p[7].m_pComponent;
      }
      else if ( (v5 & 0x8000u) == 0 )
      {
        if ( (v5 >> 13) & 1 )
          v6 = v3->m_Components.p[6].m_pComponent;
        else
          v6 = (v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::ActionTreeComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::ActionTreeComponent::_TypeUID);
      }
      else
      {
        v6 = v3->m_Components.p[7].m_pComponent;
      }
      if ( v6 )
      {
        v7 = (UFG::SimObjectCVBase *)v4->mSimObject.m_pPointer;
        if ( v7 )
        {
          v8 = v7->m_Flags;
          if ( (v8 >> 14) & 1 )
          {
            v9 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v7);
          }
          else if ( (v8 & 0x8000u) == 0 )
          {
            if ( (v8 >> 13) & 1 )
            {
              v9 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                     (UFG::SimObjectGame *)&v7->vfptr,
                                                     UFG::ActiveAIEntityComponent::_TypeUID);
            }
            else if ( (v8 >> 12) & 1 )
            {
              v9 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                     (UFG::SimObjectGame *)&v7->vfptr,
                                                     UFG::ActiveAIEntityComponent::_TypeUID);
            }
            else
            {
              v9 = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                     (UFG::SimObject *)&v7->vfptr,
                                                     UFG::ActiveAIEntityComponent::_TypeUID);
            }
          }
          else
          {
            v9 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v7);
          }
          v10 = v9;
          if ( v9 )
          {
            v11 = LOBYTE(v2->m_Track[1].vfptr);
            v12 = (const char *)TargetVisibleInAIDataCondition::CreateClone((hkResourceHandle *)v4->mActionController);
            UFG::ActiveAIEntityComponent::SetCurrentObjective(v10, v11, v12);
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
  UFG::qNode<ITask,ITask> *v1; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::InterestPoint> *v2; // [rsp+28h] [rbp+10h]

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<UsePOITrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&UsePOITask::`vftable;
  v2 = &this->m_pPOI;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  this->m_pPOI.m_pPointer = 0i64;
  this->m_pActionContext = 0i64;
  this->m_pFAC = 0i64;
}

// File Line: 2085
// RVA: 0x33B7A0
void __fastcall UsePOITask::~UsePOITask(UsePOITask *this)
{
  UsePOITask *v1; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::InterestPoint> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rdx
  UFG::qNode<ITask,ITask> *v8; // rcx
  UFG::qNode<ITask,ITask> *v9; // rax

  v1 = this;
  this->vfptr = (ITaskVtbl *)&UsePOITask::`vftable;
  v2 = &this->m_pPOI;
  if ( this->m_pPOI.m_pPointer )
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
  v1->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v7 = (UFG::qNode<ITask,ITask> *)&v1->mPrev;
  v8 = v1->mPrev;
  v9 = v1->mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v7->mPrev = v7;
  v7->mNext = v7;
}

// File Line: 2090
// RVA: 0x348C50
void __fastcall UsePOITask::Begin(UsePOITask *this, ActionContext *action_context)
{
  UsePOITask *v2; // rsi
  UFG::SimObjectGame *v3; // rcx
  UFG::FaceActionComponent *v4; // rdi
  UFG::SimComponent *v5; // rbx
  unsigned __int16 v6; // dx
  UFG::SimComponent *v7; // rax
  UFG::SimObjectGame *v8; // rcx
  unsigned __int16 v9; // dx
  UFG::SimComponent *v10; // rax
  UFG::SimObject *v11; // rcx
  unsigned __int16 v12; // dx
  UFG::SimComponent *v13; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::InterestPoint> *v14; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qList<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList,1,0> *v17; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rax

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
        v5 = v3->m_Components.p[20].m_pComponent;
      }
      else if ( (v6 & 0x8000u) == 0 )
      {
        if ( (v6 >> 13) & 1 )
        {
          v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        else if ( (v6 >> 12) & 1 )
        {
          v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        else
        {
          v7 = UFG::SimObject::GetComponentOfType(
                 (UFG::SimObject *)&v3->vfptr,
                 UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        v5 = v7;
      }
      else
      {
        v5 = v3->m_Components.p[20].m_pComponent;
      }
    }
    else
    {
      v5 = 0i64;
    }
    v8 = (UFG::SimObjectGame *)v2->m_pActionContext->mSimObject.m_pPointer;
    if ( v8 )
    {
      v9 = v8->m_Flags;
      if ( (v9 >> 14) & 1 )
      {
        v4 = (UFG::FaceActionComponent *)v8->m_Components.p[45].m_pComponent;
      }
      else
      {
        if ( (v9 & 0x8000u) == 0 )
        {
          if ( (v9 >> 13) & 1 )
          {
            v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::FaceActionComponent::_TypeUID);
          }
          else if ( (v9 >> 12) & 1 )
          {
            v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::FaceActionComponent::_TypeUID);
          }
          else
          {
            v10 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v8->vfptr, UFG::FaceActionComponent::_TypeUID);
          }
        }
        else
        {
          v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::FaceActionComponent::_TypeUID);
        }
        v4 = (UFG::FaceActionComponent *)v10;
      }
    }
    v2->m_pFAC = v4;
    if ( v5 )
    {
      v11 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v5[1].m_Flags + 34i64)
                               + *(_QWORD *)&v5[1].m_TypeUID
                               + 40);
      if ( v11 )
      {
        v12 = v11->m_Flags;
        if ( (v12 >> 14) & 1 )
        {
          v13 = v11->m_Components.p[25].m_pComponent;
        }
        else if ( (v12 & 0x8000u) == 0 )
        {
          if ( (v12 >> 13) & 1 )
          {
            v13 = v11->m_Components.p[10].m_pComponent;
          }
          else if ( (v12 >> 12) & 1 )
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
        v14 = &v2->m_pPOI;
        if ( v2->m_pPOI.m_pPointer )
        {
          v15 = v14->mPrev;
          v16 = v2->m_pPOI.mNext;
          v15->mNext = v16;
          v16->mPrev = v15;
          v14->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v14->mPrev;
          v2->m_pPOI.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pPOI.mPrev;
        }
        v2->m_pPOI.m_pPointer = v13;
        if ( v13 )
        {
          v17 = &v13->m_SafePointerList;
          v18 = v13->m_SafePointerList.mNode.mPrev;
          v18->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v14->mPrev;
          v14->mPrev = v18;
          v2->m_pPOI.mNext = &v17->mNode;
          v17->mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v14->mPrev;
        }
        if ( UFG::InterestPoint::IsReservationMatch(
               (UFG::InterestPoint *)v2->m_pPOI.m_pPointer,
               2u,
               ReserveReason_normal) )
        {
          v2->mTimePOIUnusedFor = FLOAT_N1_0;
        }
        else
        {
          v2->mTimePOIUnusedFor = 0.0;
        }
      }
    }
  }
}

// File Line: 2111
// RVA: 0x3939C0
char __fastcall UsePOITask::Update(UsePOITask *this, float timestep)
{
  UsePOITask *v2; // rbx
  UFG::InterestPoint *v3; // rcx
  char v4; // si
  float v5; // xmm0_4
  UFG::FaceActionComponent *v6; // rax
  UFG::FaceActionComponent *v7; // rax
  UFG::SimObjectCVBase *v8; // rcx
  unsigned __int16 v9; // dx
  UFG::AICharacterControllerBaseComponent *v10; // rax
  UFG::AICharacterControllerBaseComponent *v11; // rdi
  unsigned __int64 v12; // rax

  v2 = this;
  v3 = (UFG::InterestPoint *)this->m_pPOI.m_pPointer;
  v4 = 0;
  if ( !v3 )
    return v4;
  v5 = v2->mTimePOIUnusedFor;
  if ( v5 >= 0.0 )
  {
    if ( v5 > *(float *)&v2->m_Track[1].vfptr || UFG::InterestPoint::IsReservationMatch(v3, 2u, ReserveReason_normal) )
    {
      v2->mTimePOIUnusedFor = -1.0;
    }
    else
    {
      v6 = v2->m_pFAC;
      v4 = 1;
      v2->mTimePOIUnusedFor = timestep + v2->mTimePOIUnusedFor;
      if ( v6 )
        v6->mWaitingForPOIBlock = 1;
    }
  }
  if ( v2->mTimePOIUnusedFor >= 0.0 )
    return v4;
  v7 = v2->m_pFAC;
  if ( v7 )
    v7->mWaitingForPOIBlock = 0;
  v8 = (UFG::SimObjectCVBase *)v2->m_pActionContext->mSimObject.m_pPointer;
  if ( !v8 )
    return v4;
  v9 = v8->m_Flags;
  if ( (v9 >> 14) & 1 )
  {
    v10 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v8);
  }
  else if ( (v9 & 0x8000u) == 0 )
  {
    if ( (v9 >> 13) & 1 )
    {
      v10 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         (UFG::SimObjectGame *)&v8->vfptr,
                                                         UFG::AICharacterControllerBaseComponent::_TypeUID);
    }
    else if ( (v9 >> 12) & 1 )
    {
      v10 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         (UFG::SimObjectGame *)&v8->vfptr,
                                                         UFG::AICharacterControllerBaseComponent::_TypeUID);
    }
    else
    {
      v10 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                         (UFG::SimObject *)&v8->vfptr,
                                                         UFG::AICharacterControllerBaseComponent::_TypeUID);
    }
  }
  else
  {
    v10 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v8);
  }
  v11 = v10;
  if ( !v10 )
    return v4;
  if ( !UFG::InterestPoint::IsReservationMatch((UFG::InterestPoint *)v2->m_pPOI.m_pPointer, 2u, ReserveReason_normal) )
  {
    v12 = v11->m_Intention.mActionRequests.mBits[(signed __int64)(signed int)gActionRequest_POI_Use.m_EnumValue >> 6];
    if ( !_bittest64((const signed __int64 *)&v12, gActionRequest_POI_Use.m_EnumValue & 0x3F)
      || v11->m_Intention.mActionRequestChargeTimes[gActionRequest_POI_Use.m_EnumValue] )
    {
      return 0;
    }
  }
  if ( UFG::InterestPoint::IsReservationMatch((UFG::InterestPoint *)v2->m_pPOI.m_pPointer, 0x10u, ReserveReason_normal) )
    return 0;
  return 1;
}

// File Line: 2163
// RVA: 0x355630
void __fastcall UsePOITask::End(UsePOITask *this)
{
  UFG::FaceActionComponent *v1; // rax

  v1 = this->m_pFAC;
  if ( v1 )
    v1->mWaitingForPOIBlock = 0;
}

// File Line: 2178
// RVA: 0x330CB0
void __fastcall POIBeginTask::POIBeginTask(POIBeginTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<POIBeginTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&POIBeginTask::`vftable;
}

// File Line: 2188
// RVA: 0x347260
void __fastcall POIBeginTask::Begin(POIBeginTask *this, ActionContext *action_context)
{
  UFG::SimObjectGame *v2; // rcx
  ActionContext *v3; // rdi
  unsigned __int16 v4; // r8
  UFG::SimComponent *v5; // rdx
  UFG::SimComponent *v6; // rax
  UFG::SimObject *v7; // rcx
  unsigned __int16 v8; // dx
  UFG::InterestPoint *v9; // rbx

  if ( action_context )
  {
    v2 = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
    v3 = action_context;
    if ( v2 )
    {
      v4 = v2->m_Flags;
      if ( (v4 >> 14) & 1 )
      {
        v5 = v2->m_Components.p[20].m_pComponent;
      }
      else if ( (v4 & 0x8000u) == 0 )
      {
        if ( (v4 >> 13) & 1 )
        {
          v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        else if ( (v4 >> 12) & 1 )
        {
          v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        else
        {
          v6 = UFG::SimObject::GetComponentOfType(
                 (UFG::SimObject *)&v2->vfptr,
                 UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        v5 = v6;
      }
      else
      {
        v5 = v2->m_Components.p[20].m_pComponent;
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
              v9 = (UFG::InterestPoint *)v7->m_Components.p[10].m_pComponent;
            else
              v9 = (UFG::InterestPoint *)((v8 >> 12) & 1 ? v7->m_Components.p[3].m_pComponent : UFG::SimObject::GetComponentOfType(
                                                                                                  v7,
                                                                                                  UFG::InterestPoint::_TypeUID));
          }
          else
          {
            v9 = (UFG::InterestPoint *)v7->m_Components.p[25].m_pComponent;
          }
          if ( v9 )
          {
            if ( UFG::InterestPoint::IsReservationMatch(v9, 8u, ReserveReason_normal) )
              UFG::InterestPoint::BeginReservation(v9, v3->mSimObject.m_pPointer, ReserveReason_normal);
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
  UFG::qNode<ITask,ITask> *v1; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<CollisionAvoidanceTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&CollisionAvoidanceTask::`vftable;
  v2 = &this->m_pAIEntityComponent;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  this->m_pAIEntityComponent.m_pPointer = 0i64;
  if ( this->m_pAIEntityComponent.m_pPointer )
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

// File Line: 2227
// RVA: 0x335B60
void __fastcall CollisionAvoidanceTask::~CollisionAvoidanceTask(CollisionAvoidanceTask *this)
{
  CollisionAvoidanceTask *v1; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rdx
  UFG::qNode<ITask,ITask> *v8; // rcx
  UFG::qNode<ITask,ITask> *v9; // rax

  v1 = this;
  this->vfptr = (ITaskVtbl *)&CollisionAvoidanceTask::`vftable;
  v2 = &this->m_pAIEntityComponent;
  if ( this->m_pAIEntityComponent.m_pPointer )
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
  v1->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v7 = (UFG::qNode<ITask,ITask> *)&v1->mPrev;
  v8 = v1->mPrev;
  v9 = v1->mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v7->mPrev = v7;
  v7->mNext = v7;
}

// File Line: 2232
// RVA: 0x3443D0
void __fastcall CollisionAvoidanceTask::Begin(CollisionAvoidanceTask *this, ActionContext *action_context)
{
  CollisionAvoidanceTask *v2; // rbx
  UFG::SimObjectCVBase *v3; // rcx
  UFG::ActiveAIEntityComponent *v4; // r8
  unsigned __int16 v5; // dx
  UFG::ActiveAIEntityComponent *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax

  if ( action_context )
  {
    v2 = this;
    v3 = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
    if ( v3 )
    {
      v5 = v3->m_Flags;
      if ( (v5 >> 14) & 1 )
      {
        v6 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v3);
      }
      else if ( (v5 & 0x8000u) == 0 )
      {
        if ( (v5 >> 13) & 1 )
        {
          v6 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)&v3->vfptr,
                                                 UFG::ActiveAIEntityComponent::_TypeUID);
        }
        else if ( (v5 >> 12) & 1 )
        {
          v6 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)&v3->vfptr,
                                                 UFG::ActiveAIEntityComponent::_TypeUID);
        }
        else
        {
          v6 = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                 (UFG::SimObject *)&v3->vfptr,
                                                 UFG::ActiveAIEntityComponent::_TypeUID);
        }
      }
      else
      {
        v6 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v3);
      }
      v4 = v6;
    }
    else
    {
      v4 = 0i64;
    }
    v7 = &v2->m_pAIEntityComponent;
    if ( v2->m_pAIEntityComponent.m_pPointer )
    {
      v8 = v7->mPrev;
      v9 = v2->m_pAIEntityComponent.mNext;
      v8->mNext = v9;
      v9->mPrev = v8;
      v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
      v2->m_pAIEntityComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pAIEntityComponent.mPrev;
    }
    v2->m_pAIEntityComponent.m_pPointer = (UFG::SimComponent *)&v4->vfptr;
    if ( v4 )
    {
      v10 = v4->m_SafePointerList.mNode.mPrev;
      v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
      v7->mPrev = v10;
      v2->m_pAIEntityComponent.mNext = &v4->m_SafePointerList.mNode;
      v4->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    }
  }
}

// File Line: 2309
// RVA: 0x330FC0
void __fastcall Pathing_OverrideCollisionAvoidanceTypeTask::Pathing_OverrideCollisionAvoidanceTypeTask(Pathing_OverrideCollisionAvoidanceTypeTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::NavComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<Pathing_OverrideCollisionAvoidanceTypeTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&Pathing_OverrideCollisionAvoidanceTypeTask::`vftable;
  v2 = &this->m_pNavComponent;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  this->m_pNavComponent.m_pPointer = 0i64;
  if ( this->m_pNavComponent.m_pPointer )
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

// File Line: 2316
// RVA: 0x339DC0
void __fastcall Pathing_OverrideCollisionAvoidanceTypeTask::~Pathing_OverrideCollisionAvoidanceTypeTask(Pathing_OverrideCollisionAvoidanceTypeTask *this)
{
  Pathing_OverrideCollisionAvoidanceTypeTask *v1; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::NavComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rdx
  UFG::qNode<ITask,ITask> *v8; // rcx
  UFG::qNode<ITask,ITask> *v9; // rax

  v1 = this;
  this->vfptr = (ITaskVtbl *)&Pathing_OverrideCollisionAvoidanceTypeTask::`vftable;
  v2 = &this->m_pNavComponent;
  if ( this->m_pNavComponent.m_pPointer )
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
  v1->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v7 = (UFG::qNode<ITask,ITask> *)&v1->mPrev;
  v8 = v1->mPrev;
  v9 = v1->mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v7->mPrev = v7;
  v7->mNext = v7;
}

// File Line: 2321
// RVA: 0x347900
void __fastcall Pathing_OverrideCollisionAvoidanceTypeTask::Begin(Pathing_OverrideCollisionAvoidanceTypeTask *this, ActionContext *action_context)
{
  Pathing_OverrideCollisionAvoidanceTypeTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  UFG::SimComponent *v4; // r8
  unsigned __int16 v5; // dx
  UFG::SimComponent *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::NavComponent> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::NavComponent *v11; // rcx
  UFG::eCollisionAvoidanceType v12; // eax
  UFG::NavComponent *v13; // rcx

  v2 = this;
  v3 = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  if ( v3 )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v4 = v3->m_Components.p[36].m_pComponent;
    }
    else
    {
      if ( (v5 & 0x8000u) == 0 )
      {
        if ( (v5 >> 13) & 1 )
        {
          v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::NavComponent::_TypeUID);
        }
        else if ( (v5 >> 12) & 1 )
        {
          v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::NavComponent::_TypeUID);
        }
        else
        {
          v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::NavComponent::_TypeUID);
        }
      }
      else
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::NavComponent::_TypeUID);
      }
      v4 = v6;
    }
  }
  else
  {
    v4 = 0i64;
  }
  v7 = &v2->m_pNavComponent;
  if ( v2->m_pNavComponent.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v2->m_pNavComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v2->m_pNavComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pNavComponent.mPrev;
  }
  v2->m_pNavComponent.m_pPointer = v4;
  if ( v4 )
  {
    v10 = v4->m_SafePointerList.mNode.mPrev;
    v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v7->mPrev = v10;
    v2->m_pNavComponent.mNext = &v4->m_SafePointerList.mNode;
    v4->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  }
  v11 = (UFG::NavComponent *)v2->m_pNavComponent.m_pPointer;
  if ( v11 )
  {
    v12 = (unsigned int)UFG::NavComponent::GetCollisionAvoidanceType(v11);
    v13 = (UFG::NavComponent *)v2->m_pNavComponent.m_pPointer;
    v2->m_PrevCollisionAvoidanceType = v12;
    UFG::NavComponent::SetCollisionAvoidanceType(v13, LOBYTE(v2->m_Track[1].vfptr));
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
void __fastcall ActionRequestAndWaitUntilPlayingTask::ActionRequestAndWaitUntilPlayingTask(ActionRequestAndWaitUntilPlayingTask *this)
{
  ActionRequestAndWaitUntilPlayingTask *v1; // r9
  UFG::qNode<ITask,ITask> *v2; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v3; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::ActionTreeComponent> *v4; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rax

  v1 = this;
  v2 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<ActionRequestAndWaitUntilPlayingTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&ActionRequestAndWaitUntilPlayingTask::`vftable;
  v3 = &this->m_pAIEntityComponent;
  v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  this->m_pAIEntityComponent.m_pPointer = 0i64;
  v4 = &this->m_pActionTreeComponent;
  v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  v4->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  this->m_pActionTreeComponent.m_pPointer = 0i64;
  this->m_pActionContext = 0i64;
  if ( this->m_pAIEntityComponent.m_pPointer )
  {
    v5 = v3->mPrev;
    v6 = v3->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
    v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  }
  v3->m_pPointer = 0i64;
  if ( v4->m_pPointer )
  {
    v7 = v4->mPrev;
    v8 = v4->mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
    v4->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  }
  v4->m_pPointer = 0i64;
  *(_WORD *)&v1->m_HasFinishedNodePreviously = 0;
}

// File Line: 2374
// RVA: 0x334CB0
void __fastcall ActionRequestAndWaitUntilPlayingTask::~ActionRequestAndWaitUntilPlayingTask(ActionRequestAndWaitUntilPlayingTask *this)
{
  ActionRequestAndWaitUntilPlayingTask *v1; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::ActionTreeComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<ITask,ITask> *v12; // rdx
  UFG::qNode<ITask,ITask> *v13; // rcx
  UFG::qNode<ITask,ITask> *v14; // rax

  v1 = this;
  this->vfptr = (ITaskVtbl *)&ActionRequestAndWaitUntilPlayingTask::`vftable;
  v2 = &this->m_pActionTreeComponent;
  if ( this->m_pActionTreeComponent.m_pPointer )
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
  v7 = &v1->m_pAIEntityComponent;
  if ( v1->m_pAIEntityComponent.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v1->m_pAIEntityComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v1->m_pAIEntityComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pAIEntityComponent.mPrev;
  }
  v1->m_pAIEntityComponent.m_pPointer = 0i64;
  v10 = v7->mPrev;
  v11 = v1->m_pAIEntityComponent.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v1->m_pAIEntityComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pAIEntityComponent.mPrev;
  v1->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v12 = (UFG::qNode<ITask,ITask> *)&v1->mPrev;
  v13 = v1->mPrev;
  v14 = v1->mNext;
  v13->mNext = v14;
  v14->mPrev = v13;
  v12->mPrev = v12;
  v12->mNext = v12;
}

// File Line: 2379
// RVA: 0x343A70
void __fastcall ActionRequestAndWaitUntilPlayingTask::Begin(ActionRequestAndWaitUntilPlayingTask *this, ActionContext *action_context)
{
  ActionRequestAndWaitUntilPlayingTask *v2; // rbx
  UFG::SimObjectCVBase *v3; // rcx
  UFG::SimComponent *v4; // rdi
  UFG::ActiveAIEntityComponent *v5; // r8
  unsigned __int16 v6; // dx
  UFG::ActiveAIEntityComponent *v7; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v8; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::SimObjectGame *v12; // rcx
  unsigned __int16 v13; // dx
  UFG::SimComponent *v14; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActionTreeComponent> *v15; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rax
  UFG::SimComponent *v19; // rcx

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
        v7 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v3);
      }
      else if ( (v6 & 0x8000u) == 0 )
      {
        if ( (v6 >> 13) & 1 )
        {
          v7 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)&v3->vfptr,
                                                 UFG::ActiveAIEntityComponent::_TypeUID);
        }
        else if ( (v6 >> 12) & 1 )
        {
          v7 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)&v3->vfptr,
                                                 UFG::ActiveAIEntityComponent::_TypeUID);
        }
        else
        {
          v7 = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                 (UFG::SimObject *)&v3->vfptr,
                                                 UFG::ActiveAIEntityComponent::_TypeUID);
        }
      }
      else
      {
        v7 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v3);
      }
      v5 = v7;
    }
    else
    {
      v5 = 0i64;
    }
    v8 = &v2->m_pAIEntityComponent;
    if ( v2->m_pAIEntityComponent.m_pPointer )
    {
      v9 = v8->mPrev;
      v10 = v2->m_pAIEntityComponent.mNext;
      v9->mNext = v10;
      v10->mPrev = v9;
      v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
      v2->m_pAIEntityComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pAIEntityComponent.mPrev;
    }
    v2->m_pAIEntityComponent.m_pPointer = (UFG::SimComponent *)&v5->vfptr;
    if ( v5 )
    {
      v11 = v5->m_SafePointerList.mNode.mPrev;
      v11->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
      v8->mPrev = v11;
      v2->m_pAIEntityComponent.mNext = &v5->m_SafePointerList.mNode;
      v5->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
    }
    v12 = (UFG::SimObjectGame *)v2->m_pActionContext->mSimObject.m_pPointer;
    if ( v12 )
    {
      v13 = v12->m_Flags;
      if ( (v13 >> 14) & 1 )
      {
        v4 = v12->m_Components.p[7].m_pComponent;
      }
      else if ( (v13 & 0x8000u) == 0 )
      {
        if ( (v13 >> 13) & 1 )
        {
          v4 = v12->m_Components.p[6].m_pComponent;
        }
        else
        {
          if ( (v13 >> 12) & 1 )
            v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::ActionTreeComponent::_TypeUID);
          else
            v14 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v12->vfptr, UFG::ActionTreeComponent::_TypeUID);
          v4 = v14;
        }
      }
      else
      {
        v4 = v12->m_Components.p[7].m_pComponent;
      }
    }
    v15 = &v2->m_pActionTreeComponent;
    if ( v2->m_pActionTreeComponent.m_pPointer )
    {
      v16 = v15->mPrev;
      v17 = v2->m_pActionTreeComponent.mNext;
      v16->mNext = v17;
      v17->mPrev = v16;
      v15->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v15->mPrev;
      v2->m_pActionTreeComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pActionTreeComponent.mPrev;
    }
    v2->m_pActionTreeComponent.m_pPointer = v4;
    if ( v4 )
    {
      v18 = v4->m_SafePointerList.mNode.mPrev;
      v18->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v15->mPrev;
      v15->mPrev = v18;
      v2->m_pActionTreeComponent.mNext = &v4->m_SafePointerList.mNode;
      v4->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v15->mPrev;
    }
    v19 = v2->m_pActionTreeComponent.m_pPointer;
    if ( v19 )
      v2->m_HasFinishedNodePreviously = ActionController::IsPlaying(
                                          (ActionController *)&v19[3],
                                          (ActionID *)&v2->m_Track[1],
                                          0xFFFFFFFF,
                                          BYTE4(v2->m_Track[1].mResourceOwner) != 0) == 0;
    v2->m_HasStartedNode = 0;
    v2->m_TimeBegan = UFG::Metrics::msInstance.mSimTime_Temp;
  }
  else
  {
    this->m_HasStartedNode = 0;
    this->m_TimeBegan = UFG::Metrics::msInstance.mSimTime_Temp;
  }
}

// File Line: 2401
// RVA: 0x38C660
bool __fastcall ActionRequestAndWaitUntilPlayingTask::Update(ActionRequestAndWaitUntilPlayingTask *this, float timestep)
{
  ITrack *v2; // rdx
  bool result; // al
  ActionRequestAndWaitUntilPlayingTask *v4; // rbx
  unsigned int v5; // esi
  bool v6; // di
  float v7; // xmm1_4
  bool v8; // bp
  UFG::SimComponent *v9; // rcx
  UFG::SimComponent *v10; // rcx

  v2 = this->m_Track;
  result = this->m_HasStartedNode;
  v4 = this;
  v5 = BYTE5(v2[1].mResourceOwner);
  v6 = 1;
  v7 = *((float *)&v2[1].vfptr + 1);
  v8 = (_BYTE)v5 == 3;
  if ( result || v7 < 0.0 || (float)(UFG::Metrics::msInstance.mSimTime_Temp - this->m_TimeBegan) <= v7 )
  {
    if ( this->m_HasFinishedNodePreviously || v5 > 1 )
    {
      if ( !result )
      {
        v9 = this->m_pActionTreeComponent.m_pPointer;
        if ( v9 )
          v4->m_HasStartedNode = ActionController::IsPlaying(
                                   (ActionController *)&v9[3],
                                   (ActionID *)&v2[1],
                                   0xFFFFFFFF,
                                   BYTE4(v2[1].mResourceOwner) != 0);
      }
      if ( v4->m_HasStartedNode )
      {
        v10 = v4->m_pActionTreeComponent.m_pPointer;
        if ( v10 )
        {
          if ( v5 <= 1 )
            v6 = 1;
          else
            v6 = ActionController::IsPlaying(
                   (ActionController *)&v10[3],
                   (ActionID *)&v4->m_Track[1],
                   0xFFFFFFFF,
                   BYTE4(v4->m_Track[1].mResourceOwner) != 0) == 0;
        }
      }
      else
      {
        v6 = 0;
        v8 = 1;
      }
      if ( v8 && !v6 )
        ActionRequestAndWaitUntilPlayingTask::PressActionRequest(v4);
      result = v6 == 0;
    }
    else
    {
      this->m_HasFinishedNodePreviously = ActionController::IsPlaying(
                                            (ActionController *)&this->m_pActionTreeComponent.m_pPointer[3],
                                            (ActionID *)&v2[1],
                                            0xFFFFFFFF,
                                            BYTE4(v2[1].mResourceOwner) != 0) == 0;
      if ( v5 == 1 )
        ActionRequestAndWaitUntilPlayingTask::PressActionRequest(v4);
      result = 1;
    }
  }
  return result;
}

// File Line: 2482
// RVA: 0x37C870
void __fastcall ActionRequestAndWaitUntilPlayingTask::PressActionRequest(ActionRequestAndWaitUntilPlayingTask *this)
{
  __int64 v1; // rbx
  UFG::SimObjectCVBase *v2; // rcx
  UFG::AICharacterControllerBaseComponent *v3; // rdx
  unsigned __int16 v4; // dx
  UFG::AICharacterControllerBaseComponent *v5; // rax
  signed __int64 v6; // r8
  float v7; // xmm0_4

  v1 = LODWORD(this->m_Track[1].mResourceOwner);
  if ( this->m_pAIEntityComponent.m_pPointer )
  {
    v2 = (UFG::SimObjectCVBase *)this->m_pActionContext->mSimObject.m_pPointer;
    if ( v2 )
    {
      v4 = v2->m_Flags;
      if ( (v4 >> 14) & 1 )
      {
        v5 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v2);
      }
      else if ( (v4 & 0x8000u) == 0 )
      {
        if ( (v4 >> 13) & 1 )
        {
          v5 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            (UFG::SimObjectGame *)&v2->vfptr,
                                                            UFG::AICharacterControllerBaseComponent::_TypeUID);
        }
        else if ( (v4 >> 12) & 1 )
        {
          v5 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            (UFG::SimObjectGame *)&v2->vfptr,
                                                            UFG::AICharacterControllerBaseComponent::_TypeUID);
        }
        else
        {
          v5 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                            (UFG::SimObject *)&v2->vfptr,
                                                            UFG::AICharacterControllerBaseComponent::_TypeUID);
        }
      }
      else
      {
        v5 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v2);
      }
      v3 = v5;
    }
    else
    {
      v3 = 0i64;
    }
    v6 = 1i64 << (v1 & 0x3F);
    v3->m_Intention.mActionRequests.mBits[(signed __int64)(signed int)v1 >> 6] |= v6;
    v7 = (float)(signed int)0.0;
    if ( v7 >= 255.0 )
      v7 = FLOAT_255_0;
    v3->m_Intention.mActionRequestChargeTimes[v1] = (signed int)v7;
    v3->m_Intention.mSignals |= v6;
  }
}

// File Line: 2523
// RVA: 0x3912F0
char __fastcall NodeRequestTask::Update(NodeRequestTask *this, float timeDelta)
{
  NodeRequestTask *v2; // rbx
  UFG::SimObjectCVBase *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimObjectGame *v5; // rcx
  unsigned __int16 v6; // dx

  v2 = this;
  v3 = (UFG::SimObjectCVBase *)this->mContext->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v3);
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
      {
        UFG::SimObjectGame::GetComponentOfTypeHK(
          (UFG::SimObjectGame *)&v3->vfptr,
          UFG::ActiveAIEntityComponent::_TypeUID);
      }
      else if ( (v4 >> 12) & 1 )
      {
        UFG::SimObjectGame::GetComponentOfTypeHK(
          (UFG::SimObjectGame *)&v3->vfptr,
          UFG::ActiveAIEntityComponent::_TypeUID);
      }
      else
      {
        UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::ActiveAIEntityComponent::_TypeUID);
      }
    }
    else
    {
      UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v3);
    }
  }
  v5 = (UFG::SimObjectGame *)v2->mContext->mSimObject.m_pPointer;
  if ( v5 )
  {
    v6 = v5->m_Flags;
    if ( !((v6 >> 14) & 1) && (v6 & 0x8000u) == 0 && !((v6 >> 13) & 1) )
    {
      if ( (v6 >> 12) & 1 )
      {
        UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::ActionTreeComponent::_TypeUID);
        return 1;
      }
      UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v5->vfptr, UFG::ActionTreeComponent::_TypeUID);
    }
  }
  return 1;
}

// File Line: 2547
// RVA: 0x3309E0
void __fastcall NodeRequestAndWaitUntilPlayingTask::NodeRequestAndWaitUntilPlayingTask(NodeRequestAndWaitUntilPlayingTask *this)
{
  NodeRequestAndWaitUntilPlayingTask *v1; // r9
  UFG::qNode<ITask,ITask> *v2; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v3; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::ActionTreeComponent> *v4; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rax

  v1 = this;
  v2 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<NodeRequestAndWaitUntilPlayingTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&NodeRequestAndWaitUntilPlayingTask::`vftable;
  v3 = &this->m_pAIEntityComponent;
  v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  this->m_pAIEntityComponent.m_pPointer = 0i64;
  v4 = &this->m_pActionTreeComponent;
  v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  v4->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  this->m_pActionTreeComponent.m_pPointer = 0i64;
  this->m_pActionContext = 0i64;
  if ( this->m_pAIEntityComponent.m_pPointer )
  {
    v5 = v3->mPrev;
    v6 = v3->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
    v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  }
  v3->m_pPointer = 0i64;
  if ( v4->m_pPointer )
  {
    v7 = v4->mPrev;
    v8 = v4->mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
    v4->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  }
  v4->m_pPointer = 0i64;
  v1->m_HasStartedNode = 0;
}

// File Line: 2558
// RVA: 0x339680
void __fastcall NodeRequestAndWaitUntilPlayingTask::~NodeRequestAndWaitUntilPlayingTask(NodeRequestAndWaitUntilPlayingTask *this)
{
  NodeRequestAndWaitUntilPlayingTask *v1; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::ActionTreeComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<ITask,ITask> *v12; // rdx
  UFG::qNode<ITask,ITask> *v13; // rcx
  UFG::qNode<ITask,ITask> *v14; // rax

  v1 = this;
  this->vfptr = (ITaskVtbl *)&NodeRequestAndWaitUntilPlayingTask::`vftable;
  v2 = &this->m_pActionTreeComponent;
  if ( this->m_pActionTreeComponent.m_pPointer )
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
  v7 = &v1->m_pAIEntityComponent;
  if ( v1->m_pAIEntityComponent.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v1->m_pAIEntityComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v1->m_pAIEntityComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pAIEntityComponent.mPrev;
  }
  v1->m_pAIEntityComponent.m_pPointer = 0i64;
  v10 = v7->mPrev;
  v11 = v1->m_pAIEntityComponent.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v1->m_pAIEntityComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pAIEntityComponent.mPrev;
  v1->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v12 = (UFG::qNode<ITask,ITask> *)&v1->mPrev;
  v13 = v1->mPrev;
  v14 = v1->mNext;
  v13->mNext = v14;
  v14->mPrev = v13;
  v12->mPrev = v12;
  v12->mNext = v12;
}

// File Line: 2563
// RVA: 0x3470B0
void __fastcall NodeRequestAndWaitUntilPlayingTask::Begin(NodeRequestAndWaitUntilPlayingTask *this, ActionContext *action_context)
{
  NodeRequestAndWaitUntilPlayingTask *v2; // rbx
  UFG::SimObjectCVBase *v3; // rcx
  UFG::SimComponent *v4; // rdi
  UFG::ActiveAIEntityComponent *v5; // r8
  unsigned __int16 v6; // dx
  UFG::ActiveAIEntityComponent *v7; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v8; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::SimObjectGame *v12; // rcx
  unsigned __int16 v13; // dx
  UFG::SimComponent *v14; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActionTreeComponent> *v15; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rax

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
        v7 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v3);
      }
      else if ( (v6 & 0x8000u) == 0 )
      {
        if ( (v6 >> 13) & 1 )
        {
          v7 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)&v3->vfptr,
                                                 UFG::ActiveAIEntityComponent::_TypeUID);
        }
        else if ( (v6 >> 12) & 1 )
        {
          v7 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)&v3->vfptr,
                                                 UFG::ActiveAIEntityComponent::_TypeUID);
        }
        else
        {
          v7 = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                 (UFG::SimObject *)&v3->vfptr,
                                                 UFG::ActiveAIEntityComponent::_TypeUID);
        }
      }
      else
      {
        v7 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v3);
      }
      v5 = v7;
    }
    else
    {
      v5 = 0i64;
    }
    v8 = &v2->m_pAIEntityComponent;
    if ( v2->m_pAIEntityComponent.m_pPointer )
    {
      v9 = v8->mPrev;
      v10 = v2->m_pAIEntityComponent.mNext;
      v9->mNext = v10;
      v10->mPrev = v9;
      v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
      v2->m_pAIEntityComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pAIEntityComponent.mPrev;
    }
    v2->m_pAIEntityComponent.m_pPointer = (UFG::SimComponent *)&v5->vfptr;
    if ( v5 )
    {
      v11 = v5->m_SafePointerList.mNode.mPrev;
      v11->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
      v8->mPrev = v11;
      v2->m_pAIEntityComponent.mNext = &v5->m_SafePointerList.mNode;
      v5->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
    }
    v12 = (UFG::SimObjectGame *)v2->m_pActionContext->mSimObject.m_pPointer;
    if ( v12 )
    {
      v13 = v12->m_Flags;
      if ( (v13 >> 14) & 1 )
      {
        v4 = v12->m_Components.p[7].m_pComponent;
      }
      else if ( (v13 & 0x8000u) == 0 )
      {
        if ( (v13 >> 13) & 1 )
        {
          v4 = v12->m_Components.p[6].m_pComponent;
        }
        else
        {
          if ( (v13 >> 12) & 1 )
            v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::ActionTreeComponent::_TypeUID);
          else
            v14 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v12->vfptr, UFG::ActionTreeComponent::_TypeUID);
          v4 = v14;
        }
      }
      else
      {
        v4 = v12->m_Components.p[7].m_pComponent;
      }
    }
    v15 = &v2->m_pActionTreeComponent;
    if ( v2->m_pActionTreeComponent.m_pPointer )
    {
      v16 = v15->mPrev;
      v17 = v2->m_pActionTreeComponent.mNext;
      v16->mNext = v17;
      v17->mPrev = v16;
      v15->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v15->mPrev;
      v2->m_pActionTreeComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pActionTreeComponent.mPrev;
    }
    v2->m_pActionTreeComponent.m_pPointer = v4;
    if ( v4 )
    {
      v18 = v4->m_SafePointerList.mNode.mPrev;
      v18->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v15->mPrev;
      v15->mPrev = v18;
      v2->m_pActionTreeComponent.mNext = &v4->m_SafePointerList.mNode;
      v4->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v15->mPrev;
    }
    v2->m_HasStartedNode = 0;
    v2->m_TimeBegan = UFG::Metrics::msInstance.mSimTime_Temp;
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
  ITrack *v2; // rdx
  bool result; // al
  NodeRequestAndWaitUntilPlayingTask *v4; // rbx
  float v5; // xmm1_4
  UFG::SimComponent *v6; // rcx
  bool v7; // al
  bool v8; // cl
  UFG::SimComponent *v9; // rax
  ITrack *v10; // rdx

  v2 = this->m_Track;
  result = this->m_HasStartedNode;
  v4 = this;
  v5 = *(float *)&v2[1].mResourceOwner;
  if ( !result )
  {
    if ( v5 >= 0.0 && (float)(UFG::Metrics::msInstance.mSimTime_Temp - this->m_TimeBegan) > v5 )
      return result;
    v6 = this->m_pActionTreeComponent.m_pPointer;
    if ( v6 )
      v4->m_HasStartedNode = ActionController::IsPlaying(
                               (ActionController *)&v6[3],
                               (ActionID *)&v2[1],
                               0xFFFFFFFF,
                               BYTE4(v2[1].vfptr) != 0);
  }
  v7 = v4->m_HasStartedNode;
  v8 = 1;
  if ( !v7 )
    v8 = 0;
  if ( v7 )
  {
    v9 = v4->m_pActionTreeComponent.m_pPointer;
    if ( v9 )
    {
      v10 = v4->m_Track;
      if ( !BYTE5(v10[1].vfptr) )
        return 0;
      v8 = ActionController::IsPlaying(
             (ActionController *)&v9[3],
             (ActionID *)&v10[1],
             0xFFFFFFFF,
             BYTE4(v10[1].vfptr) != 0) == 0;
    }
  }
  return v8 == 0;
}

// File Line: 2663
// RVA: 0x331B50
void __fastcall SetCurrentEmotionTask::SetCurrentEmotionTask(SetCurrentEmotionTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<SetCurrentEmotionTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&SetCurrentEmotionTask::`vftable;
  v2 = &this->m_pAIEntityComponent;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  this->m_pAIEntityComponent.m_pPointer = 0i64;
  this->m_pActionContext = 0i64;
  if ( this->m_pAIEntityComponent.m_pPointer )
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

// File Line: 2671
// RVA: 0x33ABA0
void __fastcall SetCurrentEmotionTask::~SetCurrentEmotionTask(SetCurrentEmotionTask *this)
{
  SetCurrentEmotionTask *v1; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rdx
  UFG::qNode<ITask,ITask> *v8; // rcx
  UFG::qNode<ITask,ITask> *v9; // rax

  v1 = this;
  this->vfptr = (ITaskVtbl *)&SetCurrentEmotionTask::`vftable;
  v2 = &this->m_pAIEntityComponent;
  if ( this->m_pAIEntityComponent.m_pPointer )
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
  v1->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v7 = (UFG::qNode<ITask,ITask> *)&v1->mPrev;
  v8 = v1->mPrev;
  v9 = v1->mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v7->mPrev = v7;
  v7->mNext = v7;
}

// File Line: 2688
// RVA: 0x392DE0
char __fastcall SetCurrentEmotionTask::Update(SetCurrentEmotionTask *this, float timestep)
{
  UFG::SimComponent *v2; // rdx

  v2 = this->m_pAIEntityComponent.m_pPointer;
  if ( v2 )
    HIDWORD(v2[64].m_BoundComponentHandles.mNode.mNext) = LOBYTE(this->m_Track[1].vfptr);
  return 1;
}

// File Line: 2718
// RVA: 0x331CE0
void __fastcall SetFacialEmotionTask::SetFacialEmotionTask(SetFacialEmotionTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<SetFacialEmotionTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&SetFacialEmotionTask::`vftable;
  v2 = &this->m_pAIEntityComponent;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  this->m_pAIEntityComponent.m_pPointer = 0i64;
  this->m_pActionContext = 0i64;
  if ( this->m_pAIEntityComponent.m_pPointer )
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

// File Line: 2726
// RVA: 0x33AD30
void __fastcall SetFacialEmotionTask::~SetFacialEmotionTask(SetFacialEmotionTask *this)
{
  SetFacialEmotionTask *v1; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rdx
  UFG::qNode<ITask,ITask> *v8; // rcx
  UFG::qNode<ITask,ITask> *v9; // rax

  v1 = this;
  this->vfptr = (ITaskVtbl *)&SetFacialEmotionTask::`vftable;
  v2 = &this->m_pAIEntityComponent;
  if ( this->m_pAIEntityComponent.m_pPointer )
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
  v1->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v7 = (UFG::qNode<ITask,ITask> *)&v1->mPrev;
  v8 = v1->mPrev;
  v9 = v1->mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v7->mPrev = v7;
  v7->mNext = v7;
}

// File Line: 2743
// RVA: 0x392E00
char __fastcall SetFacialEmotionTask::Update(SetFacialEmotionTask *this, float timestep)
{
  UFG::SimComponent *v2; // rdx

  v2 = this->m_pAIEntityComponent.m_pPointer;
  if ( v2 )
    LODWORD(v2[65].vfptr) = LOBYTE(this->m_Track[1].vfptr);
  return 1;
}

// File Line: 2773
// RVA: 0x3327E0
void __fastcall TurnToFaceTargetTask::TurnToFaceTargetTask(TurnToFaceTargetTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<TurnToFaceTargetTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&TurnToFaceTargetTask::`vftable;
  this->m_pActionContext = 0i64;
}

// File Line: 2792
// RVA: 0x393680
char __fastcall TurnToFaceTargetTask::Update(TurnToFaceTargetTask *this, float timestep)
{
  TurnToFaceTargetTask *v2; // rsi
  UFG::SimObjectGame *v3; // rcx
  UFG::SimComponent *v4; // r8
  unsigned __int16 v5; // dx
  UFG::SimComponent *v6; // rax
  UFG::SimObject *v7; // rcx
  UFG::TransformNodeComponent *v8; // rbp
  __int64 v9; // rdi
  UFG::SimObjectCVBase *v10; // rcx
  unsigned __int16 v11; // dx
  UFG::AICharacterControllerBaseComponent *v12; // rax
  UFG::AICharacterControllerBaseComponent *v13; // rbx
  float v14; // xmm2_4
  __m128 v15; // xmm3
  __m128 v16; // xmm1
  float v17; // xmm1_4
  float v18; // xmm0_4
  UFG::SimObjectGame *v19; // rcx
  unsigned __int16 v20; // dx
  UFG::SimComponent *v21; // r8
  UFG::SimComponent *v22; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> **v23; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v24; // rcx
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v25; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v26; // rax

  v2 = this;
  v3 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
  if ( v3 )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v4 = v3->m_Components.p[20].m_pComponent;
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else if ( (v5 >> 12) & 1 )
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else
      {
        v6 = UFG::SimObject::GetComponentOfType(
               (UFG::SimObject *)&v3->vfptr,
               UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      v4 = v6;
    }
    else
    {
      v4 = v3->m_Components.p[20].m_pComponent;
    }
  }
  else
  {
    v4 = 0i64;
  }
  v7 = v2->m_pActionContext->mSimObject.m_pPointer;
  if ( v7 )
    v8 = v7->m_pTransformNodeComponent;
  else
    v8 = 0i64;
  v9 = 0i64;
  if ( v4 )
  {
    v9 = *(_QWORD *)(56i64 * *(unsigned __int8 *)(LOBYTE(v2->m_Track[1].vfptr) + *(_QWORD *)&v4[1].m_Flags + 8i64)
                   + *(_QWORD *)&v4[1].m_TypeUID
                   + 40);
    if ( v9 )
      v9 = *(_QWORD *)(v9 + 88);
  }
  if ( v8 && v9 )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v9);
    if ( !UFG::IsFacingPosition(
            v2->m_pActionContext->mSimObject.m_pPointer,
            (UFG::qVector3 *)(v9 + 176),
            (float)(*((float *)&v2->m_Track[1].vfptr + 1) * 180.0) * 0.31830987) )
    {
      v10 = (UFG::SimObjectCVBase *)v2->m_pActionContext->mSimObject.m_pPointer;
      if ( v10 )
      {
        v11 = v10->m_Flags;
        if ( (v11 >> 14) & 1 )
        {
          v12 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v10);
        }
        else if ( (v11 & 0x8000u) == 0 )
        {
          if ( (v11 >> 13) & 1 )
            v12 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               (UFG::SimObjectGame *)&v10->vfptr,
                                                               UFG::AICharacterControllerBaseComponent::_TypeUID);
          else
            v12 = (UFG::AICharacterControllerBaseComponent *)((v11 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                                  (UFG::SimObjectGame *)&v10->vfptr,
                                                                                  UFG::AICharacterControllerBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v10->vfptr, UFG::AICharacterControllerBaseComponent::_TypeUID));
        }
        else
        {
          v12 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v10);
        }
        v13 = v12;
        if ( v12 )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform(v8);
          v15 = (__m128)*(unsigned int *)(v9 + 180);
          v14 = *(float *)(v9 + 176) - v8->mWorldTransform.v3.x;
          v15.m128_f32[0] = v15.m128_f32[0] - v8->mWorldTransform.v3.y;
          v16 = v15;
          v16.m128_f32[0] = (float)(v15.m128_f32[0] * v15.m128_f32[0]) + (float)(v14 * v14);
          if ( v16.m128_f32[0] == 0.0 )
            v17 = 0.0;
          else
            v17 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v16));
          v18 = FLOAT_0_0099999998;
          v13->m_Intention.mMotionIntentionDirection.x = v14 * v17;
          v13->m_Intention.mMotionIntentionDirection.y = v15.m128_f32[0] * v17;
          v13->m_Intention.mMotionIntentionDirection.z = v17 * 0.0;
          if ( v13->m_Intention.mMotionIntentionSpeed >= 0.0099999998 )
            v18 = v13->m_Intention.mMotionIntentionSpeed;
          v13->m_Intention.mMotionIntentionSpeed = v18;
        }
      }
    }
    v19 = (UFG::SimObjectGame *)v2->m_pActionContext->mSimObject.m_pPointer;
    if ( v19 )
    {
      v20 = v19->m_Flags;
      if ( (v20 >> 14) & 1 )
      {
        v21 = v19->m_Components.p[22].m_pComponent;
      }
      else if ( (v20 & 0x8000u) == 0 )
      {
        if ( (v20 >> 13) & 1 )
          v22 = UFG::SimObjectGame::GetComponentOfTypeHK(v19, UFG::AIEntityComponent::_TypeUID);
        else
          v22 = (v20 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v19, UFG::AIEntityComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v19->vfptr, UFG::AIEntityComponent::_TypeUID);
        v21 = v22;
      }
      else
      {
        v21 = v19->m_Components.p[22].m_pComponent;
      }
      if ( v21 )
      {
        v23 = &v21[13].m_BoundComponentHandles.mNode.mNext;
        LODWORD(v21[13].m_pSimObject) = 0;
        if ( v21[14].m_SafePointerList.mNode.mPrev )
        {
          v24 = *v23;
          v25 = v21[14].vfptr;
          v24->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)v25;
          v25->__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int))v24;
          *v23 = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)v23;
          v21[14].vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&v21[13].m_BoundComponentHandles.mNode.mNext;
        }
        v21[14].m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v9;
        v26 = *(UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> **)(v9 + 8);
        v26->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)v23;
        *v23 = v26;
        v21[14].vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)(v9 + 8);
        *(_QWORD *)(v9 + 8) = v23;
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
  UFG::SimObjectGame *v1; // rcx
  unsigned __int16 v2; // dx
  UFG::SimComponent *v3; // rax

  v1 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
  if ( v1 )
  {
    v2 = v1->m_Flags;
    if ( (v2 >> 14) & 1 )
    {
      v3 = v1->m_Components.p[22].m_pComponent;
    }
    else if ( (v2 & 0x8000u) == 0 )
    {
      if ( (v2 >> 13) & 1 )
      {
        v3 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::AIEntityComponent::_TypeUID);
      }
      else if ( (v2 >> 12) & 1 )
      {
        v3 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::AIEntityComponent::_TypeUID);
      }
      else
      {
        v3 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v1->vfptr, UFG::AIEntityComponent::_TypeUID);
      }
    }
    else
    {
      v3 = v1->m_Components.p[22].m_pComponent;
    }
    if ( v3 )
      LODWORD(v3[13].m_pSimObject) = -1;
  }
}

// File Line: 2859
// RVA: 0x32FB00
void __fastcall HeadTrackTargetTask::HeadTrackTargetTask(HeadTrackTargetTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v5; // [rsp+28h] [rbp+10h]
  UFG::qSafePointer<UFG::SimComponent,UFG::ActionTreeComponent> *v6; // [rsp+28h] [rbp+10h]

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<HeadTrackTargetTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&HeadTrackTargetTask::`vftable;
  v2 = &this->m_pAIEntityComponent;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  this->m_pAIEntityComponent.m_pPointer = 0i64;
  v5 = &this->m_pTransformNodeComponent;
  v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v5->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  this->m_pTransformNodeComponent.m_pPointer = 0i64;
  v6 = &this->m_pActionTreeComponent;
  v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  v6->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  this->m_pActionTreeComponent.m_pPointer = 0i64;
  this->m_pActionContext = 0i64;
  if ( this->m_pAIEntityComponent.m_pPointer )
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

// File Line: 2867
// RVA: 0x338650
void __fastcall HeadTrackTargetTask::~HeadTrackTargetTask(HeadTrackTargetTask *this)
{
  HeadTrackTargetTask *v1; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::ActionTreeComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v12; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qNode<ITask,ITask> *v17; // rdx
  UFG::qNode<ITask,ITask> *v18; // rcx
  UFG::qNode<ITask,ITask> *v19; // rax

  v1 = this;
  this->vfptr = (ITaskVtbl *)&HeadTrackTargetTask::`vftable;
  v2 = &this->m_pActionTreeComponent;
  if ( this->m_pActionTreeComponent.m_pPointer )
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
  v7 = &v1->m_pTransformNodeComponent;
  if ( v1->m_pTransformNodeComponent.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v1->m_pTransformNodeComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v1->m_pTransformNodeComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pTransformNodeComponent.mPrev;
  }
  v1->m_pTransformNodeComponent.m_pPointer = 0i64;
  v10 = v7->mPrev;
  v11 = v1->m_pTransformNodeComponent.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v1->m_pTransformNodeComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pTransformNodeComponent.mPrev;
  v12 = &v1->m_pAIEntityComponent;
  if ( v1->m_pAIEntityComponent.m_pPointer )
  {
    v13 = v12->mPrev;
    v14 = v1->m_pAIEntityComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v12->mPrev;
    v1->m_pAIEntityComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pAIEntityComponent.mPrev;
  }
  v1->m_pAIEntityComponent.m_pPointer = 0i64;
  v15 = v12->mPrev;
  v16 = v1->m_pAIEntityComponent.mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v12->mPrev;
  v1->m_pAIEntityComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pAIEntityComponent.mPrev;
  v1->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v17 = (UFG::qNode<ITask,ITask> *)&v1->mPrev;
  v18 = v1->mPrev;
  v19 = v1->mNext;
  v18->mNext = v19;
  v19->mPrev = v18;
  v17->mPrev = v17;
  v17->mNext = v17;
}

// File Line: 2872
// RVA: 0x3462E0
void __fastcall HeadTrackTargetTask::Begin(HeadTrackTargetTask *this, ActionContext *action_context)
{
  HeadTrackTargetTask *v2; // rdi
  UFG::SimObjectCVBase *v3; // rcx
  UFG::SimComponent *v4; // rbx
  UFG::ActiveAIEntityComponent *v5; // r8
  unsigned __int16 v6; // dx
  UFG::ActiveAIEntityComponent *v7; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v8; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::SimObject *v12; // r8
  UFG::SimComponent *v13; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v14; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::SimObjectGame *v18; // rcx
  unsigned __int16 v19; // dx
  UFG::SimComponent *v20; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActionTreeComponent> *v21; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v22; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v23; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v24; // rax

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
        v7 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v3);
      }
      else if ( (v6 & 0x8000u) == 0 )
      {
        if ( (v6 >> 13) & 1 )
        {
          v7 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)&v3->vfptr,
                                                 UFG::ActiveAIEntityComponent::_TypeUID);
        }
        else if ( (v6 >> 12) & 1 )
        {
          v7 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)&v3->vfptr,
                                                 UFG::ActiveAIEntityComponent::_TypeUID);
        }
        else
        {
          v7 = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                 (UFG::SimObject *)&v3->vfptr,
                                                 UFG::ActiveAIEntityComponent::_TypeUID);
        }
      }
      else
      {
        v7 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v3);
      }
      v5 = v7;
    }
    else
    {
      v5 = 0i64;
    }
    v8 = &v2->m_pAIEntityComponent;
    if ( v2->m_pAIEntityComponent.m_pPointer )
    {
      v9 = v8->mPrev;
      v10 = v2->m_pAIEntityComponent.mNext;
      v9->mNext = v10;
      v10->mPrev = v9;
      v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
      v2->m_pAIEntityComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pAIEntityComponent.mPrev;
    }
    v2->m_pAIEntityComponent.m_pPointer = (UFG::SimComponent *)&v5->vfptr;
    if ( v5 )
    {
      v11 = v5->m_SafePointerList.mNode.mPrev;
      v11->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
      v8->mPrev = v11;
      v2->m_pAIEntityComponent.mNext = &v5->m_SafePointerList.mNode;
      v5->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
    }
    v12 = v2->m_pActionContext->mSimObject.m_pPointer;
    if ( v12 )
      v13 = (UFG::SimComponent *)&v12->m_pTransformNodeComponent->vfptr;
    else
      v13 = 0i64;
    v14 = &v2->m_pTransformNodeComponent;
    if ( v2->m_pTransformNodeComponent.m_pPointer )
    {
      v15 = v14->mPrev;
      v16 = v2->m_pTransformNodeComponent.mNext;
      v15->mNext = v16;
      v16->mPrev = v15;
      v14->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v14->mPrev;
      v2->m_pTransformNodeComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pTransformNodeComponent.mPrev;
    }
    v2->m_pTransformNodeComponent.m_pPointer = v13;
    if ( v13 )
    {
      v17 = v13->m_SafePointerList.mNode.mPrev;
      v17->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v14->mPrev;
      v14->mPrev = v17;
      v2->m_pTransformNodeComponent.mNext = &v13->m_SafePointerList.mNode;
      v13->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v14->mPrev;
    }
    v18 = (UFG::SimObjectGame *)v2->m_pActionContext->mSimObject.m_pPointer;
    if ( v18 )
    {
      v19 = v18->m_Flags;
      if ( (v19 >> 14) & 1 )
      {
        v4 = v18->m_Components.p[7].m_pComponent;
      }
      else if ( (v19 & 0x8000u) == 0 )
      {
        if ( (v19 >> 13) & 1 )
        {
          v4 = v18->m_Components.p[6].m_pComponent;
        }
        else
        {
          if ( (v19 >> 12) & 1 )
            v20 = UFG::SimObjectGame::GetComponentOfTypeHK(v18, UFG::ActionTreeComponent::_TypeUID);
          else
            v20 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v18->vfptr, UFG::ActionTreeComponent::_TypeUID);
          v4 = v20;
        }
      }
      else
      {
        v4 = v18->m_Components.p[7].m_pComponent;
      }
    }
    v21 = &v2->m_pActionTreeComponent;
    if ( v2->m_pActionTreeComponent.m_pPointer )
    {
      v22 = v21->mPrev;
      v23 = v2->m_pActionTreeComponent.mNext;
      v22->mNext = v23;
      v23->mPrev = v22;
      v21->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v21->mPrev;
      v2->m_pActionTreeComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pActionTreeComponent.mPrev;
    }
    v2->m_pActionTreeComponent.m_pPointer = v4;
    if ( v4 )
    {
      v24 = v4->m_SafePointerList.mNode.mPrev;
      v24->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v21->mPrev;
      v21->mPrev = v24;
      v2->m_pActionTreeComponent.mNext = &v4->m_SafePointerList.mNode;
      v4->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v21->mPrev;
    }
  }
}

// File Line: 2886
// RVA: 0x38FA10
char __fastcall HeadTrackTargetTask::Update(HeadTrackTargetTask *this, float timestep)
{
  HeadTrackTargetTask *rdi1; // rdi
  UFG::SimObjectGame *v3; // rcx
  UFG::SimComponent *v4; // r8
  unsigned __int16 v5; // dx
  UFG::SimComponent *v6; // rax
  __int64 v7; // rsi
  UFG::TransformNodeComponent *v8; // rsi
  UFG::SimComponent *v9; // rbp
  float *v10; // rbx
  float v11; // xmm2_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  float *v14; // rax
  float v15; // xmm1_4
  float v16; // xmm1_4
  UFG::AIEntityComponent *v17; // rcx
  float v18; // xmm0_4
  UFG::qVector3 v2; // [rsp+20h] [rbp-28h]
  UFG::qVector3 offset; // [rsp+30h] [rbp-18h]

  rdi1 = this;
  if ( this->m_pAIEntityComponent.m_pPointer )
  {
    v3 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
    if ( v3 )
    {
      v5 = v3->m_Flags;
      if ( (v5 >> 14) & 1 )
      {
        v4 = v3->m_Components.p[20].m_pComponent;
      }
      else if ( (v5 & 0x8000u) == 0 )
      {
        if ( (v5 >> 13) & 1 )
        {
          v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        else if ( (v5 >> 12) & 1 )
        {
          v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        else
        {
          v6 = UFG::SimObject::GetComponentOfType(
                 (UFG::SimObject *)&v3->vfptr,
                 UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        v4 = v6;
      }
      else
      {
        v4 = v3->m_Components.p[20].m_pComponent;
      }
    }
    else
    {
      v4 = 0i64;
    }
    if ( v4 )
    {
      v7 = *(_QWORD *)(56i64 * *(unsigned __int8 *)(LOBYTE(rdi1->m_Track[1].vfptr) + *(_QWORD *)&v4[1].m_Flags + 8i64)
                     + *(_QWORD *)&v4[1].m_TypeUID
                     + 40);
      if ( v7 )
      {
        v8 = *(UFG::TransformNodeComponent **)(v7 + 88);
        if ( v8 )
        {
          v9 = rdi1->m_pTransformNodeComponent.m_pPointer;
          if ( v9 )
          {
            UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)rdi1->m_pTransformNodeComponent.m_pPointer);
            v10 = (float *)rdi1->m_pTransformNodeComponent.m_pPointer;
            UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)rdi1->m_pTransformNodeComponent.m_pPointer);
            UFG::TransformNodeComponent::UpdateWorldTransform(v8);
            v11 = v8->mWorldTransform.v3.z - v10[46];
            v12 = v8->mWorldTransform.v3.y - v10[45];
            v2.x = v8->mWorldTransform.v3.x - v10[44];
            v2.y = v12;
            v2.z = v11;
            v13 = UFG::qAngleBetween((UFG::qVector3 *)&v9[2], &v2);
            v14 = (float *)rdi1->m_Track;
            v15 = v14[15];
            if ( rdi1->m_CurrentlyHeadTracking )
              v15 = v15 + 0.17453294;
            if ( COERCE_FLOAT(LODWORD(v13) & _xmm) < v15 )
            {
              v16 = v14[17];
              v17 = (UFG::AIEntityComponent *)rdi1->m_pAIEntityComponent.m_pPointer;
              offset.x = v14[16];
              v18 = v14[18];
              offset.y = v16;
              offset.z = v18;
              UFG::AIEntityComponent::SetHeadTrackingPosition(v17, v8, &offset);
              rdi1->m_CurrentlyHeadTracking = 1;
              return 1;
            }
          }
        }
      }
    }
    LODWORD(rdi1->m_pAIEntityComponent.m_pPointer[13].m_pSimObject) = -1;
    rdi1->m_CurrentlyHeadTracking = 0;
  }
  return 1;
}

// File Line: 2944
// RVA: 0x3550C0
void __fastcall HeadTrackTargetTask::End(HeadTrackTargetTask *this)
{
  UFG::SimComponent *v1; // rax

  v1 = this->m_pAIEntityComponent.m_pPointer;
  if ( v1 )
    LODWORD(v1[13].m_pSimObject) = -1;
}

// File Line: 2960
// RVA: 0x32DB40
void __fastcall DebugDrawMyPositionTask::DebugDrawMyPositionTask(DebugDrawMyPositionTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<DebugDrawMyPositionTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&DebugDrawMyPositionTask::`vftable;
  v2 = &this->m_pTransformNodeComponent;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  this->m_pTransformNodeComponent.m_pPointer = 0i64;
  this->m_pActionContext = 0i64;
  if ( this->m_pTransformNodeComponent.m_pPointer )
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

// File Line: 2968
// RVA: 0x336040
void __fastcall DebugDrawMyPositionTask::~DebugDrawMyPositionTask(DebugDrawMyPositionTask *this)
{
  DebugDrawMyPositionTask *v1; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rdx
  UFG::qNode<ITask,ITask> *v8; // rcx
  UFG::qNode<ITask,ITask> *v9; // rax

  v1 = this;
  this->vfptr = (ITaskVtbl *)&DebugDrawMyPositionTask::`vftable;
  v2 = &this->m_pTransformNodeComponent;
  if ( this->m_pTransformNodeComponent.m_pPointer )
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
  v1->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v7 = (UFG::qNode<ITask,ITask> *)&v1->mPrev;
  v8 = v1->mPrev;
  v9 = v1->mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v7->mPrev = v7;
  v7->mNext = v7;
}

// File Line: 2973
// RVA: 0x3444A0
void __fastcall DebugDrawMyPositionTask::Begin(DebugDrawMyPositionTask *this, ActionContext *action_context)
{
  UFG::SimObject *v2; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v3; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax

  this->m_pActionContext = action_context;
  if ( action_context )
  {
    v2 = action_context->mSimObject.m_pPointer;
    if ( v2 )
      v2 = (UFG::SimObject *)v2->m_pTransformNodeComponent;
    v3 = &this->m_pTransformNodeComponent;
    if ( this->m_pTransformNodeComponent.m_pPointer )
    {
      v4 = v3->mPrev;
      v5 = v3->mNext;
      v4->mNext = v5;
      v5->mPrev = v4;
      v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
      v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
    }
    v3->m_pPointer = (UFG::SimComponent *)v2;
    if ( v2 )
    {
      v6 = v2->m_SafePointerList.mNode.mPrev;
      v6->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)v3;
      v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v6;
      v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_SafePointerList;
      v2->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)v3;
    }
  }
}

// File Line: 2985
// RVA: 0x38E120
char __fastcall DebugDrawMyPositionTask::Update(DebugDrawMyPositionTask *this, float timestep)
{
  ITrack *v2; // rax
  UFG::SimComponent *v3; // rbx
  UFG::TransformNodeComponent *v4; // rcx
  float v5; // xmm1_4
  float v6; // xmm0_4
  Render::DebugDrawContext *v7; // rax
  UFG::qVector3 point; // [rsp+30h] [rbp-28h]
  UFG::qColour colour; // [rsp+40h] [rbp-18h]

  v2 = this->m_Track;
  if ( !LOBYTE(v2[1].m_TrackClassNameUID) )
    return 1;
  v3 = this->m_pTransformNodeComponent.m_pPointer;
  if ( v3 )
  {
    v4 = (UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pPointer;
    colour = (UFG::qColour)v2[1].0;
    UFG::TransformNodeComponent::UpdateWorldTransform(v4);
    v5 = *((float *)&v3[2].m_BoundComponentHandles.mNode.mPrev + 1);
    point.x = *(float *)&v3[2].m_BoundComponentHandles.mNode.mPrev;
    v6 = *(float *)&v3[2].m_BoundComponentHandles.mNode.mNext;
    point.y = v5;
    point.z = v6 + 0.25;
    v7 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
    Render::DebugDrawContext::DrawPoint(v7, &point, &colour, &UFG::qMatrix44::msIdentity, 0i64);
  }
  return 1;
}

// File Line: 3012
// RVA: 0x32DBC0
void __fastcall DebugDrawMyTargetTask::DebugDrawMyTargetTask(DebugDrawMyTargetTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v5; // [rsp+28h] [rbp+10h]

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<DebugDrawMyTargetTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&DebugDrawMyTargetTask::`vftable;
  v5 = &this->m_pTransformNodeComponent;
  v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v5->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  this->m_pTransformNodeComponent.m_pPointer = 0i64;
  v2 = &this->m_pTargetingSystemBaseComponent;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  this->m_pTargetingSystemBaseComponent.m_pPointer = 0i64;
  this->m_pActionContext = 0i64;
  if ( this->m_pTargetingSystemBaseComponent.m_pPointer )
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

// File Line: 3020
// RVA: 0x336140
void __fastcall DebugDrawMyTargetTask::~DebugDrawMyTargetTask(DebugDrawMyTargetTask *this)
{
  DebugDrawMyTargetTask *v1; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<ITask,ITask> *v12; // rdx
  UFG::qNode<ITask,ITask> *v13; // rcx
  UFG::qNode<ITask,ITask> *v14; // rax

  v1 = this;
  this->vfptr = (ITaskVtbl *)&DebugDrawMyTargetTask::`vftable;
  v2 = &this->m_pTargetingSystemBaseComponent;
  if ( this->m_pTargetingSystemBaseComponent.m_pPointer )
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
  v7 = &v1->m_pTransformNodeComponent;
  if ( v1->m_pTransformNodeComponent.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v1->m_pTransformNodeComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v1->m_pTransformNodeComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pTransformNodeComponent.mPrev;
  }
  v1->m_pTransformNodeComponent.m_pPointer = 0i64;
  v10 = v7->mPrev;
  v11 = v1->m_pTransformNodeComponent.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v1->m_pTransformNodeComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pTransformNodeComponent.mPrev;
  v1->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v12 = (UFG::qNode<ITask,ITask> *)&v1->mPrev;
  v13 = v1->mPrev;
  v14 = v1->mNext;
  v13->mNext = v14;
  v14->mPrev = v13;
  v12->mPrev = v12;
  v12->mNext = v12;
}

// File Line: 3025
// RVA: 0x344500
void __fastcall DebugDrawMyTargetTask::Begin(DebugDrawMyTargetTask *this, ActionContext *action_context)
{
  DebugDrawMyTargetTask *v2; // rdi
  UFG::SimObjectGame *v3; // rcx
  UFG::SimComponent *v4; // rbx
  UFG::SimComponent *v5; // r8
  unsigned __int16 v6; // dx
  UFG::SimComponent *v7; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *v8; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::SimObject *v12; // rcx
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v13; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax

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
        v5 = v3->m_Components.p[20].m_pComponent;
      }
      else if ( (v6 & 0x8000u) == 0 )
      {
        if ( (v6 >> 13) & 1 )
        {
          v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        else if ( (v6 >> 12) & 1 )
        {
          v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        else
        {
          v7 = UFG::SimObject::GetComponentOfType(
                 (UFG::SimObject *)&v3->vfptr,
                 UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        v5 = v7;
      }
      else
      {
        v5 = v3->m_Components.p[20].m_pComponent;
      }
    }
    else
    {
      v5 = 0i64;
    }
    v8 = &v2->m_pTargetingSystemBaseComponent;
    if ( v2->m_pTargetingSystemBaseComponent.m_pPointer )
    {
      v9 = v8->mPrev;
      v10 = v2->m_pTargetingSystemBaseComponent.mNext;
      v9->mNext = v10;
      v10->mPrev = v9;
      v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
      v2->m_pTargetingSystemBaseComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pTargetingSystemBaseComponent.mPrev;
    }
    v2->m_pTargetingSystemBaseComponent.m_pPointer = v5;
    if ( v5 )
    {
      v11 = v5->m_SafePointerList.mNode.mPrev;
      v11->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
      v8->mPrev = v11;
      v2->m_pTargetingSystemBaseComponent.mNext = &v5->m_SafePointerList.mNode;
      v5->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
    }
    v12 = v2->m_pActionContext->mSimObject.m_pPointer;
    if ( v12 )
      v4 = (UFG::SimComponent *)&v12->m_pTransformNodeComponent->vfptr;
    v13 = &v2->m_pTransformNodeComponent;
    if ( v2->m_pTransformNodeComponent.m_pPointer )
    {
      v14 = v13->mPrev;
      v15 = v2->m_pTransformNodeComponent.mNext;
      v14->mNext = v15;
      v15->mPrev = v14;
      v13->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v13->mPrev;
      v2->m_pTransformNodeComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pTransformNodeComponent.mPrev;
    }
    v2->m_pTransformNodeComponent.m_pPointer = v4;
    if ( v4 )
    {
      v16 = v4->m_SafePointerList.mNode.mPrev;
      v16->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v13->mPrev;
      v13->mPrev = v16;
      v2->m_pTransformNodeComponent.mNext = &v4->m_SafePointerList.mNode;
      v4->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v13->mPrev;
    }
  }
}

// File Line: 3038
// RVA: 0x38E1D0
char __fastcall DebugDrawMyTargetTask::Update(DebugDrawMyTargetTask *this, float timestep)
{
  DebugDrawMyTargetTask *v2; // rbx
  ITrack *v3; // rcx
  UFG::SimComponent *v4; // r9
  __int64 v5; // rdi
  __int64 v6; // rdi
  __int128 v7; // xmm0
  UFG::TransformNodeComponent *v8; // rcx
  int v9; // xmm1_4
  Render::DebugDrawContext *v10; // rax
  __int128 v12; // [rsp+30h] [rbp-28h]
  UFG::qColour colour; // [rsp+40h] [rbp-18h]

  v2 = this;
  v3 = this->m_Track;
  if ( !v3[1].mBreakPoint )
    return 1;
  v4 = v2->m_pTargetingSystemBaseComponent.m_pPointer;
  if ( !v4 )
    return 1;
  v5 = *(_QWORD *)(56i64 * *(unsigned __int8 *)(LOBYTE(v3[1].vfptr) + *(_QWORD *)&v4[1].m_Flags + 8i64)
                 + *(_QWORD *)&v4[1].m_TypeUID
                 + 40);
  if ( v5 )
  {
    v6 = *(_QWORD *)(v5 + 88);
    if ( v6 )
    {
      v7 = *(__int128 *)((char *)&v3[1].0 + 4);
      v8 = (UFG::TransformNodeComponent *)v2->m_pTransformNodeComponent.m_pPointer;
      v12 = v7;
      UFG::DrawLine(v8, (UFG::TransformNodeComponent *)v6, (UFG::qColour *)&v12, 0.25);
      colour = *(UFG::qColour *)((char *)&v2->m_Track[1].0 + 4);
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v6);
      v9 = *(_DWORD *)(v6 + 180);
      LODWORD(v12) = *(_DWORD *)(v6 + 176);
      LODWORD(v7) = *(_DWORD *)(v6 + 184);
      DWORD1(v12) = v9;
      *((float *)&v12 + 2) = *(float *)&v7 + 0.25;
      v10 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
      Render::DebugDrawContext::DrawPoint(v10, (UFG::qVector3 *)&v12, &colour, &UFG::qMatrix44::msIdentity, 0i64);
    }
  }
  return 1;
}

// File Line: 3077
// RVA: 0x330530
void __fastcall MinimumDurationTask::MinimumDurationTask(MinimumDurationTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<MinimumDurationTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&MinimumDurationTask::`vftable;
  this->m_TimeToEnd = 0.0;
}

// File Line: 3087
// RVA: 0x346CE0
void __fastcall MinimumDurationTask::Begin(MinimumDurationTask *this, ActionContext *action_context)
{
  MinimumDurationTask *v2; // rbx
  float v3; // xmm7_4
  float v4; // xmm6_4
  float v5; // xmm0_4
  float v6; // xmm7_4
  float v7; // xmm6_4
  float v8; // xmm8_4
  float v9; // xmm0_4

  v2 = this;
  v3 = ExpressionParameterFloat::operator float((ExpressionParameterFloat *)&this->m_Track[1]);
  v4 = ExpressionParameterFloat::operator float(&v2->m_Track[1].mMasterRate);
  v5 = ExpressionParameterFloat::operator float((ExpressionParameterFloat *)&v2->m_Track[1].mTimeBegin);
  v6 = v3 * v5;
  v7 = v4 * v5;
  if ( v6 < 0.0 || v7 < 0.0 )
  {
    v2->m_TimeToEnd = -1.0;
  }
  else
  {
    v8 = UFG::Metrics::msInstance.mSimTime_Temp;
    v9 = v7;
    if ( v7 > v6 )
    {
      v9 = UFG::qRandom(v7 - v6, &UFG::qDefaultSeed) + v6;
      if ( v9 <= v6 )
        v9 = v6;
      if ( v9 >= v7 )
        v9 = v7;
    }
    v2->m_TimeToEnd = v9 + v8;
  }
}

// File Line: 3111
// RVA: 0x390A20
bool __fastcall MinimumDurationTask::Update(MinimumDurationTask *this, float timestep)
{
  float v2; // xmm1_4

  v2 = this->m_TimeToEnd;
  return v2 < 0.0 || UFG::Metrics::msInstance.mSimTime_Temp < v2;
}

// File Line: 3153
// RVA: 0x3317D0
void __fastcall RunLaterallyFromTargetTask::RunLaterallyFromTargetTask(RunLaterallyFromTargetTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v2; // [rsp+28h] [rbp+10h]
  UFG::qSafePointer<UFG::SimComponent,UFG::StimulusReceiverComponent> *v3; // [rsp+28h] [rbp+10h]
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *v4; // [rsp+28h] [rbp+10h]

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<RunLaterallyFromTargetTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&RunLaterallyFromTargetTask::`vftable;
  v2 = &this->m_pAIEntityComponent;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  this->m_pAIEntityComponent.m_pPointer = 0i64;
  v3 = &this->m_pStimulusReceiverComponent;
  v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  this->m_pStimulusReceiverComponent.m_pPointer = 0i64;
  v4 = &this->m_pTargetingSystemBaseComponent;
  v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  v4->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  this->m_pTargetingSystemBaseComponent.m_pPointer = 0i64;
  this->m_LastTimeReceivedStimulus = -99999.0;
  this->m_SideToRunTo = 0;
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
  RunLaterallyFromTargetTask *v1; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::StimulusReceiverComponent> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v12; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qNode<ITask,ITask> *v17; // rdx
  UFG::qNode<ITask,ITask> *v18; // rcx
  UFG::qNode<ITask,ITask> *v19; // rax

  v1 = this;
  this->vfptr = (ITaskVtbl *)&RunLaterallyFromTargetTask::`vftable;
  v2 = &this->m_pTargetingSystemBaseComponent;
  if ( this->m_pTargetingSystemBaseComponent.m_pPointer )
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
  v7 = &v1->m_pStimulusReceiverComponent;
  if ( v1->m_pStimulusReceiverComponent.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v1->m_pStimulusReceiverComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v1->m_pStimulusReceiverComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pStimulusReceiverComponent.mPrev;
  }
  v1->m_pStimulusReceiverComponent.m_pPointer = 0i64;
  v10 = v7->mPrev;
  v11 = v1->m_pStimulusReceiverComponent.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v1->m_pStimulusReceiverComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pStimulusReceiverComponent.mPrev;
  v12 = &v1->m_pAIEntityComponent;
  if ( v1->m_pAIEntityComponent.m_pPointer )
  {
    v13 = v12->mPrev;
    v14 = v1->m_pAIEntityComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v12->mPrev;
    v1->m_pAIEntityComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pAIEntityComponent.mPrev;
  }
  v1->m_pAIEntityComponent.m_pPointer = 0i64;
  v15 = v12->mPrev;
  v16 = v1->m_pAIEntityComponent.mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v12->mPrev;
  v1->m_pAIEntityComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pAIEntityComponent.mPrev;
  v1->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v17 = (UFG::qNode<ITask,ITask> *)&v1->mPrev;
  v18 = v1->mPrev;
  v19 = v1->mNext;
  v18->mNext = v19;
  v19->mPrev = v18;
  v17->mPrev = v17;
  v17->mNext = v17;
}

// File Line: 3178
// RVA: 0x348310
void __fastcall RunLaterallyFromTargetTask::Begin(RunLaterallyFromTargetTask *this, ActionContext *action_context)
{
  RunLaterallyFromTargetTask *v2; // rbx
  UFG::SimObjectCVBase *v3; // rcx
  UFG::ActiveAIEntityComponent *v4; // r8
  unsigned __int16 v5; // dx
  UFG::ActiveAIEntityComponent *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::SimObjectGame *v11; // rcx
  UFG::SimComponent *v12; // r8
  unsigned __int16 v13; // dx
  UFG::SimComponent *v14; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::StimulusReceiverComponent> *v15; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rax
  UFG::SimObjectGame *v19; // rcx
  UFG::SimComponent *v20; // r8
  unsigned __int16 v21; // dx
  UFG::SimComponent *v22; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *v23; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v24; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v25; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v26; // rax
  ITrack *v27; // rax
  float v28; // xmm6_4
  float v29; // xmm7_4
  float v30; // xmm0_4

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
        v6 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v3);
      }
      else if ( (v5 & 0x8000u) == 0 )
      {
        if ( (v5 >> 13) & 1 )
        {
          v6 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)&v3->vfptr,
                                                 UFG::ActiveAIEntityComponent::_TypeUID);
        }
        else if ( (v5 >> 12) & 1 )
        {
          v6 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)&v3->vfptr,
                                                 UFG::ActiveAIEntityComponent::_TypeUID);
        }
        else
        {
          v6 = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                 (UFG::SimObject *)&v3->vfptr,
                                                 UFG::ActiveAIEntityComponent::_TypeUID);
        }
      }
      else
      {
        v6 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v3);
      }
      v4 = v6;
    }
    else
    {
      v4 = 0i64;
    }
    v7 = &v2->m_pAIEntityComponent;
    if ( v2->m_pAIEntityComponent.m_pPointer )
    {
      v8 = v7->mPrev;
      v9 = v2->m_pAIEntityComponent.mNext;
      v8->mNext = v9;
      v9->mPrev = v8;
      v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
      v2->m_pAIEntityComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pAIEntityComponent.mPrev;
    }
    v2->m_pAIEntityComponent.m_pPointer = (UFG::SimComponent *)&v4->vfptr;
    if ( v4 )
    {
      v10 = v4->m_SafePointerList.mNode.mPrev;
      v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
      v7->mPrev = v10;
      v2->m_pAIEntityComponent.mNext = &v4->m_SafePointerList.mNode;
      v4->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    }
    v11 = (UFG::SimObjectGame *)v2->m_pActionContext->mSimObject.m_pPointer;
    if ( v11 )
    {
      v13 = v11->m_Flags;
      if ( (v13 >> 14) & 1 )
      {
        v12 = v11->m_Components.p[11].m_pComponent;
      }
      else if ( (v13 & 0x8000u) == 0 )
      {
        if ( (v13 >> 13) & 1 )
        {
          v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::StimulusReceiverComponent::_TypeUID);
        }
        else if ( (v13 >> 12) & 1 )
        {
          v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::StimulusReceiverComponent::_TypeUID);
        }
        else
        {
          v14 = UFG::SimObject::GetComponentOfType(
                  (UFG::SimObject *)&v11->vfptr,
                  UFG::StimulusReceiverComponent::_TypeUID);
        }
        v12 = v14;
      }
      else
      {
        v12 = v11->m_Components.p[11].m_pComponent;
      }
    }
    else
    {
      v12 = 0i64;
    }
    v15 = &v2->m_pStimulusReceiverComponent;
    if ( v2->m_pStimulusReceiverComponent.m_pPointer )
    {
      v16 = v15->mPrev;
      v17 = v2->m_pStimulusReceiverComponent.mNext;
      v16->mNext = v17;
      v17->mPrev = v16;
      v15->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v15->mPrev;
      v2->m_pStimulusReceiverComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pStimulusReceiverComponent.mPrev;
    }
    v2->m_pStimulusReceiverComponent.m_pPointer = v12;
    if ( v12 )
    {
      v18 = v12->m_SafePointerList.mNode.mPrev;
      v18->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v15->mPrev;
      v15->mPrev = v18;
      v2->m_pStimulusReceiverComponent.mNext = &v12->m_SafePointerList.mNode;
      v12->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v15->mPrev;
    }
    v19 = (UFG::SimObjectGame *)v2->m_pActionContext->mSimObject.m_pPointer;
    if ( v19 )
    {
      v21 = v19->m_Flags;
      if ( (v21 >> 14) & 1 )
      {
        v20 = v19->m_Components.p[20].m_pComponent;
      }
      else if ( (v21 & 0x8000u) == 0 )
      {
        if ( (v21 >> 13) & 1 )
        {
          v22 = UFG::SimObjectGame::GetComponentOfTypeHK(v19, UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        else if ( (v21 >> 12) & 1 )
        {
          v22 = UFG::SimObjectGame::GetComponentOfTypeHK(v19, UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        else
        {
          v22 = UFG::SimObject::GetComponentOfType(
                  (UFG::SimObject *)&v19->vfptr,
                  UFG::TargetingSystemBaseComponent::_TypeUID);
        }
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
    v23 = &v2->m_pTargetingSystemBaseComponent;
    if ( v2->m_pTargetingSystemBaseComponent.m_pPointer )
    {
      v24 = v23->mPrev;
      v25 = v2->m_pTargetingSystemBaseComponent.mNext;
      v24->mNext = v25;
      v25->mPrev = v24;
      v23->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v23->mPrev;
      v2->m_pTargetingSystemBaseComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pTargetingSystemBaseComponent.mPrev;
    }
    v2->m_pTargetingSystemBaseComponent.m_pPointer = v20;
    if ( v20 )
    {
      v26 = v20->m_SafePointerList.mNode.mPrev;
      v26->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v23->mPrev;
      v23->mPrev = v26;
      v2->m_pTargetingSystemBaseComponent.mNext = &v20->m_SafePointerList.mNode;
      v20->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v23->mPrev;
    }
  }
  v27 = v2->m_Track;
  v2->m_SideToRunTo = 0;
  v2->m_NextTimeCanSetSideToRunTo = -99999.0;
  v28 = *(float *)&v27[1].mResourceOwner;
  v29 = *((float *)&v27[1].mResourceOwner + 1);
  if ( v28 <= v29 )
    goto LABEL_58;
  v30 = UFG::qRandom(v28 - v29, &UFG::qDefaultSeed) + v29;
  if ( v30 <= v29 )
    v30 = v29;
  if ( v30 >= v28 )
LABEL_58:
    v2->m_TimeToImpactToDive = v28;
  else
    v2->m_TimeToImpactToDive = v30;
}

// File Line: 3250
// RVA: 0x392140
char __fastcall RunLaterallyFromTargetTask::Update(RunLaterallyFromTargetTask *this, float timestep)
{
  UFG::SimComponent *v2; // rsi
  RunLaterallyFromTargetTask *v3; // rbx
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
  float v20; // xmm9_4
  __m128 v21; // xmm4
  float v22; // xmm3_4
  __m128 v23; // xmm11
  __m128 v24; // xmm1
  float v25; // xmm10_4
  float v26; // xmm7_4
  float v27; // xmm8_4
  UFG::eLeftOrRightSide v28; // er14
  UFG::NavComponent *v29; // rdi
  __m128 v30; // xmm2
  float v31; // xmm9_4
  float v32; // xmm0_4
  int v33; // eax
  ITrack *v34; // rax
  float v35; // xmm8_4
  float v36; // xmm0_4
  float v37; // xmm1_4
  float v38; // xmm8_4
  float v39; // xmm10_4
  float v40; // xmm11_4
  unsigned int v41; // xmm1_4
  int v42; // er15
  UFG::SimObject *v43; // rcx
  UFG::SimComponent *v44; // rdx
  __int64 v45; // rcx
  bool v46; // al
  bool v47; // r14
  UFG::SimComponent *v48; // rax
  unsigned int v49; // xmm11_4
  unsigned int v50; // xmm8_4
  UFG::SimObject *v51; // rcx
  UFG::SimComponent *v52; // rdx
  __int64 v53; // rcx
  int v54; // ecx
  ITrack *v55; // rax
  __m128 v56; // xmm1
  int v57; // xmm12_4
  int v58; // xmm13_4
  int v59; // xmm14_4
  UFG::SimObjectCVBase *v60; // rcx
  unsigned __int16 v61; // dx
  UFG::AICharacterControllerBaseComponent *v62; // rax
  float *v63; // rdi
  float v64; // xmm2_4
  float v65; // xmm6_4
  float v66; // xmm7_4
  UFG::SimObjectGame *v67; // rcx
  unsigned __int16 v68; // dx
  UFG::SimComponent *v69; // rax
  UFG::SimObjectCVBase *v70; // rcx
  unsigned __int16 v71; // dx
  UFG::AICharacterControllerBaseComponent *v72; // rax
  float v74; // [rsp+30h] [rbp-D0h]
  unsigned __int64 v75; // [rsp+34h] [rbp-CCh]
  float v76; // [rsp+40h] [rbp-C0h]
  unsigned __int64 v77; // [rsp+44h] [rbp-BCh]
  float v78; // [rsp+50h] [rbp-B0h]
  float v79; // [rsp+54h] [rbp-ACh]
  float v80; // [rsp+58h] [rbp-A8h]
  float v81; // [rsp+60h] [rbp-A0h]
  UFG::HavokNavPosition npDestination; // [rsp+70h] [rbp-90h]
  char v83; // [rsp+B0h] [rbp-50h]
  __int64 v84; // [rsp+190h] [rbp+90h]
  float v85; // [rsp+1A0h] [rbp+A0h]
  float v86; // [rsp+1A8h] [rbp+A8h]

  v2 = this->m_pAIEntityComponent.m_pPointer;
  v3 = this;
  if ( v2 )
  {
    v4 = this->m_pTargetingSystemBaseComponent.m_pPointer;
    if ( v4 )
    {
      if ( this->m_pStimulusReceiverComponent.m_pPointer )
      {
        v5 = *(UFG::TransformNodeComponent **)&v2[1].m_TypeUID;
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
              LODWORD(v81) = (unsigned __int128)_mm_sqrt_ps(v11);
              if ( v81 < 1.0 )
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
                v20 = UFG::qVector3::msZero.x;
                v21 = (__m128)LODWORD(UFG::qVector3::msZero.y);
                v22 = UFG::qVector3::msZero.z;
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
                  v16.m128_f32[0] = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v15));
                }
                v21 = v16;
                v17 = v8.m128_f32[0] * v16.m128_f32[0];
                v21.m128_f32[0] = v16.m128_f32[0] * v9;
                v18 = v16.m128_f32[0] * v10;
                v19 = (float)((float)(v21.m128_f32[0] * v13) + (float)(v17 * v12)) + (float)(v18 * v14);
                v20 = v17 * v19;
                v21.m128_f32[0] = v21.m128_f32[0] * v19;
                v22 = v18 * v19;
              }
              v23 = v8;
              v86 = v12 - v20;
              *(float *)&v84 = v13 - v21.m128_f32[0];
              v85 = v14 - v22;
              v23.m128_f32[0] = (float)(v8.m128_f32[0] * UFG::qVector3::msDirUp.z)
                              - (float)(v10 * UFG::qVector3::msDirUp.x);
              v24 = v23;
              v25 = (float)(v10 * UFG::qVector3::msDirUp.y) - (float)(v9 * UFG::qVector3::msDirUp.z);
              v26 = (float)(v9 * UFG::qVector3::msDirUp.x) - (float)(v8.m128_f32[0] * UFG::qVector3::msDirUp.y);
              v24.m128_f32[0] = (float)(v23.m128_f32[0] * v23.m128_f32[0]) + (float)(v25 * v25);
              if ( COERCE_FLOAT(_mm_sqrt_ps(v24)) > 0.001 )
              {
                v27 = v86;
                v28 = v3->m_SideToRunTo;
                v29 = 0i64;
                v30 = (__m128)(unsigned int)v84;
                v21.m128_f32[0] = (float)((float)(v21.m128_f32[0] * v21.m128_f32[0]) + (float)(v20 * v20))
                                + (float)(v22 * v22);
                LODWORD(v31) = (unsigned __int128)_mm_sqrt_ps(v21);
                v30.m128_f32[0] = (float)((float)(*(float *)&v84 * *(float *)&v84) + (float)(v27 * v27))
                                + (float)(v85 * v85);
                LODWORD(v86) = (unsigned __int128)_mm_sqrt_ps(v30);
                if ( v28 == eSIDE_NONE
                  || UFG::Metrics::msInstance.mSimTime_Temp >= v3->m_NextTimeCanSetSideToRunTo
                  && (v32 = UFG::LinearGraph<float>::GetValue(&RunLaterallyFromTargetTask::s_SideToRunToHysteresis, v31),
                      v86 > v32) )
                {
                  v33 = ((float)((float)((float)(v23.m128_f32[0] * *(float *)&v84) + (float)(v25 * v27))
                               + (float)(v26 * v85)) <= 0.0)
                      + 1;
                  if ( v33 != v28 )
                  {
                    v3->m_SideToRunTo = v33;
                    v3->m_NextTimeCanSetSideToRunTo = UFG::Metrics::msInstance.mSimTime_Temp + 3.0;
                  }
                }
                if ( v3->m_SideToRunTo == 2 )
                {
                  LODWORD(v25) ^= _xmm[0];
                  v23.m128_i32[0] ^= _xmm[0];
                }
                v34 = v3->m_Track;
                v35 = *(float *)&v34[1].vfptr / fsqrt((float)(v23.m128_f32[0] * v23.m128_f32[0]) + (float)(v25 * v25));
                v36 = v35;
                v37 = v35;
                v38 = v35 * 0.0;
                v39 = v37 * v25;
                v40 = v36 * v23.m128_f32[0];
                v85 = v40;
                *(float *)&v41 = v40 + v5->mWorldTransform.v3.y;
                v74 = v39 + v5->mWorldTransform.v3.x;
                v75 = __PAIR__(v38 + v5->mWorldTransform.v3.z, v41);
                v42 = BYTE2(v34[1].mMasterRate.text.mOffset);
                v43 = v3->m_pAIEntityComponent.m_pPointer->m_pSimObject;
                if ( v43 )
                  v44 = UFG::SimObject::GetComponentOfType(v43, UFG::NavComponent::_TypeUID);
                else
                  v44 = 0i64;
                v45 = *(__int64 *)((char *)&v44[2].m_BoundComponentHandles.mNode.mNext + 4);
                v84 = *(__int64 *)((char *)&v44[2].m_BoundComponentHandles.mNode.mNext + 4);
                if ( v42 )
                  HIDWORD(v84) |= 0x200u;
                else
                  HIDWORD(v84) = HIDWORD(v45) & 0xFFFFFDFF;
                v46 = UFG::NavManager::ms_pInstance->vfptr->AIRayCastHits(
                        UFG::NavManager::ms_pInstance,
                        (UFG::HavokNavPosition *)&v44[1].m_SafePointerList.mNode.mNext,
                        (UFG::qVector3 *)&v74,
                        (UFG::NavParams *)&v84,
                        (UFG::qVector3 *)&v78);
                v47 = v46 != 0;
                if ( v46
                  && !BYTE3(v3->m_Track[1].mMasterRate.text.mOffset)
                  && UFG::Metrics::msInstance.mSimTime_Temp >= v3->m_NextTimeCanSetSideToRunTo )
                {
                  v48 = v3->m_pAIEntityComponent.m_pPointer;
                  *(float *)&v49 = COERCE_FLOAT(LODWORD(v40) ^ _xmm[0]) + v5->mWorldTransform.v3.y;
                  *(float *)&v50 = COERCE_FLOAT(LODWORD(v38) ^ _xmm[0]) + v5->mWorldTransform.v3.z;
                  v76 = COERCE_FLOAT(LODWORD(v39) ^ _xmm[0]) + v5->mWorldTransform.v3.x;
                  v77 = __PAIR__(v50, v49);
                  v51 = v48->m_pSimObject;
                  v52 = v51 ? UFG::SimObject::GetComponentOfType(v51, UFG::NavComponent::_TypeUID) : 0i64;
                  v53 = *(__int64 *)((char *)&v52[2].m_BoundComponentHandles.mNode.mNext + 4);
                  v84 = *(__int64 *)((char *)&v52[2].m_BoundComponentHandles.mNode.mNext + 4);
                  if ( v42 )
                    HIDWORD(v84) |= 0x200u;
                  else
                    HIDWORD(v84) = HIDWORD(v53) & 0xFFFFFDFF;
                  if ( !UFG::NavManager::ms_pInstance->vfptr->AIRayCastHits(
                          UFG::NavManager::ms_pInstance,
                          (UFG::HavokNavPosition *)&v52[1].m_SafePointerList.mNode.mNext,
                          (UFG::qVector3 *)&v76,
                          (UFG::NavParams *)&v84,
                          (UFG::qVector3 *)&v83) )
                  {
                    v54 = (v3->m_SideToRunTo != 2) + 1;
                    v74 = v76;
                    v75 = v77;
                    if ( v54 != v3->m_SideToRunTo )
                    {
                      v3->m_SideToRunTo = v54;
                      v3->m_NextTimeCanSetSideToRunTo = UFG::Metrics::msInstance.mSimTime_Temp + 3.0;
                    }
                  }
                }
                v55 = v3->m_Track;
                if ( BYTE3(v55[1].mMasterRate.text.mOffset)
                  && v47
                  && (v56 = (__m128)LODWORD(v5->mWorldTransform.v3.y),
                      v56.m128_f32[0] = (float)((float)(v56.m128_f32[0] - v79) * (float)(v56.m128_f32[0] - v79))
                                      + (float)((float)(v5->mWorldTransform.v3.x - v78)
                                              * (float)(v5->mWorldTransform.v3.x - v78)),
                      COERCE_FLOAT(_mm_sqrt_ps(v56)) < *(float *)&v55[1].mBreakPoint) )
                {
                  v57 = LODWORD(v12) ^ _xmm[0];
                  v58 = LODWORD(v13) ^ _xmm[0];
                  v59 = LODWORD(v14) ^ _xmm[0];
                  v60 = (UFG::SimObjectCVBase *)v3->m_pActionContext->mSimObject.m_pPointer;
                  if ( v60 )
                  {
                    v61 = v60->m_Flags;
                    if ( (v61 >> 14) & 1 )
                    {
                      v62 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v60);
                    }
                    else if ( (v61 & 0x8000u) == 0 )
                    {
                      if ( (v61 >> 13) & 1 )
                        v62 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                           (UFG::SimObjectGame *)&v60->vfptr,
                                                                           UFG::AICharacterControllerBaseComponent::_TypeUID);
                      else
                        v62 = (UFG::AICharacterControllerBaseComponent *)((v61 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                                              (UFG::SimObjectGame *)&v60->vfptr,
                                                                                              UFG::AICharacterControllerBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v60->vfptr, UFG::AICharacterControllerBaseComponent::_TypeUID));
                    }
                    else
                    {
                      v62 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v60);
                    }
                    if ( v62 )
                    {
                      v63 = &v62->m_Intention.mMotionIntentionSpeedRaw;
                      Intention::Set(&v62->m_Intention, v3->m_Track[1].m_TrackClassNameUID, 0.0);
                      v64 = (float)((float)(*(float *)&v58 * *(float *)&v58) + (float)(*(float *)&v57 * *(float *)&v57))
                          + (float)(*(float *)&v59 * *(float *)&v59);
                      if ( v64 == 0.0 )
                        v65 = 0.0;
                      else
                        v65 = 1.0 / fsqrt(v64);
                      v63[7] = v65 * *(float *)&v59;
                      v63[5] = v65 * *(float *)&v57;
                      v63[6] = v65 * *(float *)&v58;
                    }
                  }
                }
                else
                {
                  v66 = multiplier * sNaturalMovementSpeeds[BYTE1(v55[1].mMasterRate.text.mOffset)];
                  v67 = (UFG::SimObjectGame *)v3->m_pActionContext->mSimObject.m_pPointer;
                  if ( v67 )
                  {
                    v68 = v67->m_Flags;
                    if ( (v68 >> 14) & 1 )
                    {
                      v29 = (UFG::NavComponent *)v67->m_Components.p[36].m_pComponent;
                    }
                    else
                    {
                      if ( (v68 & 0x8000u) == 0 )
                      {
                        if ( (v68 >> 13) & 1 )
                        {
                          v69 = UFG::SimObjectGame::GetComponentOfTypeHK(v67, UFG::NavComponent::_TypeUID);
                        }
                        else if ( (v68 >> 12) & 1 )
                        {
                          v69 = UFG::SimObjectGame::GetComponentOfTypeHK(v67, UFG::NavComponent::_TypeUID);
                        }
                        else
                        {
                          v69 = UFG::SimObject::GetComponentOfType(
                                  (UFG::SimObject *)&v67->vfptr,
                                  UFG::NavComponent::_TypeUID);
                        }
                      }
                      else
                      {
                        v69 = UFG::SimObjectGame::GetComponentOfTypeHK(v67, UFG::NavComponent::_TypeUID);
                      }
                      v29 = (UFG::NavComponent *)v69;
                    }
                  }
                  npDestination.m_bValid = 0;
                  npDestination.m_vPosition.x = v78;
                  npDestination.m_vPosition.y = v79;
                  npDestination.m_vPosition.z = v80;
                  npDestination.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
                  *(_QWORD *)&npDestination.m_packedKey = -1i64;
                  npDestination.m_hkvMeshPosition.m_quad = _mm_unpacklo_ps(
                                                             _mm_unpacklo_ps((__m128)LODWORD(v78), (__m128)LODWORD(v80)),
                                                             _mm_unpacklo_ps(
                                                               (__m128)LODWORD(v79),
                                                               (__m128)(unsigned int)FLOAT_1_0));
                  UFG::NavComponent::AddGoalPoint(v29, &npDestination, AiGoal_Replace_Direct, v66, 0.75);
                  if ( v81 > 0.1
                    && v86 < *((float *)&v3->m_Track[1].vfptr + 1)
                    && (float)(v31 / v81) < v3->m_TimeToImpactToDive )
                  {
                    v70 = (UFG::SimObjectCVBase *)v3->m_pActionContext->mSimObject.m_pPointer;
                    if ( v70 )
                    {
                      v71 = v70->m_Flags;
                      if ( (v71 >> 14) & 1 )
                      {
                        v72 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v70);
                      }
                      else if ( (v71 & 0x8000u) == 0 )
                      {
                        if ( (v71 >> 13) & 1 )
                          v72 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                             (UFG::SimObjectGame *)&v70->vfptr,
                                                                             UFG::AICharacterControllerBaseComponent::_TypeUID);
                        else
                          v72 = (UFG::AICharacterControllerBaseComponent *)((v71 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                                                (UFG::SimObjectGame *)&v70->vfptr,
                                                                                                UFG::AICharacterControllerBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v70->vfptr, UFG::AICharacterControllerBaseComponent::_TypeUID));
                      }
                      else
                      {
                        v72 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v70);
                      }
                      if ( v72 )
                        Intention::Set(&v72->m_Intention, gActionRequest_Dive.m_EnumValue, 0.0);
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
  UFG::qNode<ITask,ITask> *v1; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v2; // [rsp+28h] [rbp+10h]
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *v3; // [rsp+28h] [rbp+10h]
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v4; // [rsp+28h] [rbp+10h]
  UFG::qSafePointer<UFG::SimComponent,UFG::NavComponent> *v5; // [rsp+28h] [rbp+10h]

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<PathfindToTargetTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&PathfindToTargetTask::`vftable;
  v2 = &this->m_pAIEntityComponent;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  this->m_pAIEntityComponent.m_pPointer = 0i64;
  v3 = &this->m_pTargetingSystemBaseComponent;
  v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  this->m_pTargetingSystemBaseComponent.m_pPointer = 0i64;
  v4 = &this->m_pTargetTransformNodeComponent;
  v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  v4->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  this->m_pTargetTransformNodeComponent.m_pPointer = 0i64;
  v5 = &this->m_pNavComponent;
  v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v5->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  this->m_pNavComponent.m_pPointer = 0i64;
  this->m_NavParams.m_fRadius = 0.0;
  this->m_NavParams.m_flags = 65280;
  this->m_TimeBegan = 0.0;
}

// File Line: 3488
// RVA: 0x339C10
void __fastcall PathfindToTargetTask::~PathfindToTargetTask(PathfindToTargetTask *this)
{
  PathfindToTargetTask *v1; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::NavComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *v12; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v17; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v21; // rax
  UFG::qNode<ITask,ITask> *v22; // rdx
  UFG::qNode<ITask,ITask> *v23; // rcx
  UFG::qNode<ITask,ITask> *v24; // rax

  v1 = this;
  this->vfptr = (ITaskVtbl *)&PathfindToTargetTask::`vftable;
  v2 = &this->m_pNavComponent;
  if ( this->m_pNavComponent.m_pPointer )
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
  v7 = &v1->m_pTargetTransformNodeComponent;
  if ( v1->m_pTargetTransformNodeComponent.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v1->m_pTargetTransformNodeComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v1->m_pTargetTransformNodeComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pTargetTransformNodeComponent.mPrev;
  }
  v1->m_pTargetTransformNodeComponent.m_pPointer = 0i64;
  v10 = v7->mPrev;
  v11 = v1->m_pTargetTransformNodeComponent.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v1->m_pTargetTransformNodeComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pTargetTransformNodeComponent.mPrev;
  v12 = &v1->m_pTargetingSystemBaseComponent;
  if ( v1->m_pTargetingSystemBaseComponent.m_pPointer )
  {
    v13 = v12->mPrev;
    v14 = v1->m_pTargetingSystemBaseComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v12->mPrev;
    v1->m_pTargetingSystemBaseComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pTargetingSystemBaseComponent.mPrev;
  }
  v1->m_pTargetingSystemBaseComponent.m_pPointer = 0i64;
  v15 = v12->mPrev;
  v16 = v1->m_pTargetingSystemBaseComponent.mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v12->mPrev;
  v1->m_pTargetingSystemBaseComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pTargetingSystemBaseComponent.mPrev;
  v17 = &v1->m_pAIEntityComponent;
  if ( v1->m_pAIEntityComponent.m_pPointer )
  {
    v18 = v17->mPrev;
    v19 = v1->m_pAIEntityComponent.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    v17->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v17->mPrev;
    v1->m_pAIEntityComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pAIEntityComponent.mPrev;
  }
  v1->m_pAIEntityComponent.m_pPointer = 0i64;
  v20 = v17->mPrev;
  v21 = v1->m_pAIEntityComponent.mNext;
  v20->mNext = v21;
  v21->mPrev = v20;
  v17->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v17->mPrev;
  v1->m_pAIEntityComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pAIEntityComponent.mPrev;
  v1->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v22 = (UFG::qNode<ITask,ITask> *)&v1->mPrev;
  v23 = v1->mPrev;
  v24 = v1->mNext;
  v23->mNext = v24;
  v24->mPrev = v23;
  v22->mPrev = v22;
  v22->mNext = v22;
}

// File Line: 3493
// RVA: 0x347600
void __fastcall PathfindToTargetTask::Begin(PathfindToTargetTask *this, ActionContext *action_context)
{
  PathfindToTargetTask *v2; // rbx
  UFG::SimObjectCVBase *v3; // rcx
  UFG::SimComponent *v4; // rdi
  ActionContext *v5; // rsi
  UFG::ActiveAIEntityComponent *v6; // r8
  unsigned __int16 v7; // dx
  UFG::ActiveAIEntityComponent *v8; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v9; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::SimObjectGame *v13; // rcx
  UFG::SimComponent *v14; // r8
  unsigned __int16 v15; // dx
  UFG::SimComponent *v16; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *v17; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rax
  UFG::SimObjectGame *v21; // rcx
  unsigned __int16 v22; // dx
  UFG::SimComponent *v23; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::NavComponent> *v24; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v25; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v26; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v27; // rax
  UFG::SimComponent *v28; // r8
  __int64 v29; // r8
  UFG::SimComponent *v30; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v31; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v32; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v33; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v34; // rax
  UFG::SimComponent *v35; // rax
  unsigned int v36; // eax

  v2 = this;
  this->m_pActionContext = action_context;
  v3 = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
  v4 = 0i64;
  v5 = action_context;
  if ( v3 )
  {
    v7 = v3->m_Flags;
    if ( (v7 >> 14) & 1 )
    {
      v8 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v3);
    }
    else if ( (v7 & 0x8000u) == 0 )
    {
      if ( (v7 >> 13) & 1 )
      {
        v8 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               (UFG::SimObjectGame *)&v3->vfptr,
                                               UFG::ActiveAIEntityComponent::_TypeUID);
      }
      else if ( (v7 >> 12) & 1 )
      {
        v8 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               (UFG::SimObjectGame *)&v3->vfptr,
                                               UFG::ActiveAIEntityComponent::_TypeUID);
      }
      else
      {
        v8 = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                               (UFG::SimObject *)&v3->vfptr,
                                               UFG::ActiveAIEntityComponent::_TypeUID);
      }
    }
    else
    {
      v8 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v3);
    }
    v6 = v8;
  }
  else
  {
    v6 = 0i64;
  }
  v9 = &v2->m_pAIEntityComponent;
  if ( v2->m_pAIEntityComponent.m_pPointer )
  {
    v10 = v9->mPrev;
    v11 = v2->m_pAIEntityComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    v9->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
    v2->m_pAIEntityComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pAIEntityComponent.mPrev;
  }
  v2->m_pAIEntityComponent.m_pPointer = (UFG::SimComponent *)&v6->vfptr;
  if ( v6 )
  {
    v12 = v6->m_SafePointerList.mNode.mPrev;
    v12->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
    v9->mPrev = v12;
    v2->m_pAIEntityComponent.mNext = &v6->m_SafePointerList.mNode;
    v6->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
  }
  v13 = (UFG::SimObjectGame *)v5->mSimObject.m_pPointer;
  if ( v13 )
  {
    v15 = v13->m_Flags;
    if ( (v15 >> 14) & 1 )
    {
      v14 = v13->m_Components.p[20].m_pComponent;
    }
    else if ( (v15 & 0x8000u) == 0 )
    {
      if ( (v15 >> 13) & 1 )
      {
        v16 = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else if ( (v15 >> 12) & 1 )
      {
        v16 = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else
      {
        v16 = UFG::SimObject::GetComponentOfType(
                (UFG::SimObject *)&v13->vfptr,
                UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      v14 = v16;
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
  v17 = &v2->m_pTargetingSystemBaseComponent;
  if ( v2->m_pTargetingSystemBaseComponent.m_pPointer )
  {
    v18 = v17->mPrev;
    v19 = v2->m_pTargetingSystemBaseComponent.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    v17->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v17->mPrev;
    v2->m_pTargetingSystemBaseComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pTargetingSystemBaseComponent.mPrev;
  }
  v2->m_pTargetingSystemBaseComponent.m_pPointer = v14;
  if ( v14 )
  {
    v20 = v14->m_SafePointerList.mNode.mPrev;
    v20->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v17->mPrev;
    v17->mPrev = v20;
    v2->m_pTargetingSystemBaseComponent.mNext = &v14->m_SafePointerList.mNode;
    v14->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v17->mPrev;
  }
  v21 = (UFG::SimObjectGame *)v5->mSimObject.m_pPointer;
  if ( v21 )
  {
    v22 = v21->m_Flags;
    if ( (v22 >> 14) & 1 )
    {
      v4 = v21->m_Components.p[36].m_pComponent;
    }
    else
    {
      if ( (v22 & 0x8000u) == 0 )
      {
        if ( (v22 >> 13) & 1 )
        {
          v23 = UFG::SimObjectGame::GetComponentOfTypeHK(v21, UFG::NavComponent::_TypeUID);
        }
        else if ( (v22 >> 12) & 1 )
        {
          v23 = UFG::SimObjectGame::GetComponentOfTypeHK(v21, UFG::NavComponent::_TypeUID);
        }
        else
        {
          v23 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v21->vfptr, UFG::NavComponent::_TypeUID);
        }
      }
      else
      {
        v23 = UFG::SimObjectGame::GetComponentOfTypeHK(v21, UFG::NavComponent::_TypeUID);
      }
      v4 = v23;
    }
  }
  v24 = &v2->m_pNavComponent;
  if ( v2->m_pNavComponent.m_pPointer )
  {
    v25 = v24->mPrev;
    v26 = v2->m_pNavComponent.mNext;
    v25->mNext = v26;
    v26->mPrev = v25;
    v24->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v24->mPrev;
    v2->m_pNavComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pNavComponent.mPrev;
  }
  v2->m_pNavComponent.m_pPointer = v4;
  if ( v4 )
  {
    v27 = v4->m_SafePointerList.mNode.mPrev;
    v27->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v24->mPrev;
    v24->mPrev = v27;
    v2->m_pNavComponent.mNext = &v4->m_SafePointerList.mNode;
    v4->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v24->mPrev;
  }
  v28 = v2->m_pTargetingSystemBaseComponent.m_pPointer;
  v2->m_TimeBegan = UFG::Metrics::msInstance.mSimTime_Temp;
  if ( v28 )
  {
    v29 = *(_QWORD *)(56i64 * *(unsigned __int8 *)(LOBYTE(v2->m_Track[1].vfptr) + *(_QWORD *)&v28[1].m_Flags + 8i64)
                    + *(_QWORD *)&v28[1].m_TypeUID
                    + 40);
    if ( v29 )
    {
      v30 = *(UFG::SimComponent **)(v29 + 88);
      v31 = &v2->m_pTargetTransformNodeComponent;
      if ( v2->m_pTargetTransformNodeComponent.m_pPointer )
      {
        v32 = v31->mPrev;
        v33 = v2->m_pTargetTransformNodeComponent.mNext;
        v32->mNext = v33;
        v33->mPrev = v32;
        v31->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v31->mPrev;
        v2->m_pTargetTransformNodeComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pTargetTransformNodeComponent.mPrev;
      }
      v2->m_pTargetTransformNodeComponent.m_pPointer = v30;
      if ( v30 )
      {
        v34 = v30->m_SafePointerList.mNode.mPrev;
        v34->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v31->mPrev;
        v31->mPrev = v34;
        v2->m_pTargetTransformNodeComponent.mNext = &v30->m_SafePointerList.mNode;
        v30->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v31->mPrev;
      }
    }
  }
  v35 = v2->m_pNavComponent.m_pPointer;
  if ( v35 )
  {
    v2->m_NavParams = *(UFG::NavParams *)((char *)&v35[2].m_BoundComponentHandles.mNode.mNext + 4);
    if ( BYTE4(v2->m_Track[1].mResourceOwner) )
    {
      v36 = v2->m_NavParams.m_flags;
      LOBYTE(v2->m_NavParams.m_flags) = 0;
      v2->m_NavParams.m_flags |= (unsigned __int8)(v36 & 0xFE);
      UFG::NavComponent::SetDestinationParams((UFG::NavComponent *)v2->m_pNavComponent.m_pPointer, &v2->m_NavParams);
    }
  }
}

// File Line: 3526
// RVA: 0x391600
char __fastcall PathfindToTargetTask::Update(PathfindToTargetTask *this, float timestep)
{
  PathfindToTargetTask *v2; // rbx
  UFG::SimObject *v3; // rdi
  UFG::TransformNodeComponent *v4; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v5; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qMatrix44 *v9; // rsi
  float *v10; // rax
  UFG::TransformNodeComponent *v11; // rcx
  float v12; // xmm1_4
  float v13; // xmm2_4
  UFG::qVector4 *v14; // rax
  UFG::NavComponent *v15; // rsi
  __m128 v16; // xmm0
  __m128 v17; // xmm2
  ITrack *v18; // rax
  __int64 v19; // rcx
  UFG::SimComponent *v20; // rbx
  unsigned int v21; // eax
  unsigned int v22; // ecx
  UFG::PedKnowledgeRecord *v23; // rbx
  char v24; // al
  UFG::qVector4 row_vec4; // [rsp+30h] [rbp-68h]
  UFG::qVector4 result; // [rsp+40h] [rbp-58h]
  UFG::HavokNavPosition npDestination; // [rsp+50h] [rbp-48h]

  v2 = this;
  v3 = *(UFG::SimObject **)(56i64
                          * *(unsigned __int8 *)(LOBYTE(this->m_Track[1].vfptr)
                                               + *(_QWORD *)&this->m_pTargetingSystemBaseComponent.m_pPointer[1].m_Flags
                                               + 8i64)
                          + *(_QWORD *)&this->m_pTargetingSystemBaseComponent.m_pPointer[1].m_TypeUID
                          + 40);
  if ( v3 )
  {
    v4 = v3->m_pTransformNodeComponent;
    v5 = &this->m_pTargetTransformNodeComponent;
    if ( this->m_pTargetTransformNodeComponent.m_pPointer )
    {
      v6 = v5->mPrev;
      v7 = v5->mNext;
      v6->mNext = v7;
      v7->mPrev = v6;
      v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
      v5->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
    }
    v5->m_pPointer = (UFG::SimComponent *)&v4->vfptr;
    if ( v4 )
    {
      v8 = v4->m_SafePointerList.mNode.mPrev;
      v8->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
      v5->mPrev = v8;
      v5->mNext = &v4->m_SafePointerList.mNode;
      v4->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
    }
  }
  v9 = (UFG::qMatrix44 *)v2->m_pTargetTransformNodeComponent.m_pPointer;
  if ( !v9 )
    goto LABEL_21;
  v10 = (float *)v2->m_Track;
  v11 = (UFG::TransformNodeComponent *)v2->m_pTargetTransformNodeComponent.m_pPointer;
  row_vec4.w = 1.0;
  v12 = v10[19];
  v13 = v10[20];
  row_vec4.x = v10[18];
  row_vec4.y = v12;
  row_vec4.z = v13;
  UFG::TransformNodeComponent::UpdateWorldTransform(v11);
  v14 = UFG::operator*(&result, &row_vec4, v9 + 2);
  v15 = (UFG::NavComponent *)v2->m_pNavComponent.m_pPointer;
  npDestination.m_bValid = 0;
  *(_QWORD *)&npDestination.m_packedKey = -1i64;
  v16 = (__m128)LODWORD(v14->z);
  v17 = (__m128)LODWORD(v14->y);
  npDestination.m_vPosition.x = v14->x;
  LODWORD(npDestination.m_vPosition.y) = v17.m128_i32[0];
  LODWORD(npDestination.m_vPosition.z) = v16.m128_i32[0];
  npDestination.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
  v18 = v2->m_Track;
  v19 = BYTE2(v18[1].vfptr);
  npDestination.m_hkvMeshPosition.m_quad = _mm_unpacklo_ps(
                                             _mm_unpacklo_ps((__m128)LODWORD(npDestination.m_vPosition.x), v16),
                                             _mm_unpacklo_ps(v17, (__m128)(unsigned int)FLOAT_1_0));
  UFG::NavComponent::AddGoalPoint(v15, &npDestination, 0, sNaturalMovementSpeeds[v19], *(float *)&v18[1].mResourceOwner);
  if ( !UFG::NavComponent::IsCurrentGoalProcessed(v15) )
    goto LABEL_22;
  v20 = v2->m_pAIEntityComponent.m_pPointer;
  v21 = 0;
  v22 = (unsigned int)v20[21].m_pSimObject;
  if ( v22 )
  {
    v23 = (UFG::PedKnowledgeRecord *)v20[21].m_BoundComponentHandles.mNode.mPrev;
    while ( v3 != v23->pSimObject.m_pPointer )
    {
      ++v21;
      ++v23;
      if ( v21 >= v22 )
        goto LABEL_12;
    }
  }
  else
  {
LABEL_12:
    v23 = &UFG::PedKnowledgeBase::ms_defaultKnowledgeRecord;
  }
  if ( UFG::NavComponent::IsDestinationUnreachable(v15) )
    *((_BYTE *)v23 + 48) &= 0xFBu;
  else
    *((_BYTE *)v23 + 48) |= 4u;
  v23->m_uLastPathTest = UFG::Metrics::msInstance.mSimTimeMSec;
  if ( (unsigned __int8)UFG::NavComponent::IsAtDestination(v15) )
LABEL_21:
    v24 = 0;
  else
LABEL_22:
    v24 = 1;
  return v24;
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
  PathfindAwayFromTargetTask *v1; // r8
  UFG::qNode<ITask,ITask> *v2; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::NavComponent> *v3; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *v6; // [rsp+28h] [rbp+10h]
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v7; // [rsp+28h] [rbp+10h]

  v1 = this;
  v2 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<PathfindAwayFromTargetTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&PathfindAwayFromTargetTask::`vftable;
  v3 = &this->m_pNavComponent;
  v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  this->m_pNavComponent.m_pPointer = 0i64;
  v6 = &this->m_pTargetingSystemBaseComponent;
  v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  v6->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  this->m_pTargetingSystemBaseComponent.m_pPointer = 0i64;
  v7 = &this->m_pTargetTransformNodeComponent;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v7->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  this->m_pTargetTransformNodeComponent.m_pPointer = 0i64;
  this->m_NavParams.m_fRadius = 0.0;
  this->m_NavParams.m_flags = 65280;
  this->m_pActionContext = 0i64;
  if ( this->m_pNavComponent.m_pPointer )
  {
    v4 = v3->mPrev;
    v5 = v3->mNext;
    v4->mNext = v5;
    v5->mPrev = v4;
    v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
    v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  }
  v3->m_pPointer = 0i64;
  v1->m_LastTimeFleeDirectionChecked = -99999.0;
}

// File Line: 3613
// RVA: 0x339A40
void __fastcall PathfindAwayFromTargetTask::~PathfindAwayFromTargetTask(PathfindAwayFromTargetTask *this)
{
  PathfindAwayFromTargetTask *v1; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::NavComponent> *v12; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qNode<ITask,ITask> *v17; // rdx
  UFG::qNode<ITask,ITask> *v18; // rcx
  UFG::qNode<ITask,ITask> *v19; // rax

  v1 = this;
  this->vfptr = (ITaskVtbl *)&PathfindAwayFromTargetTask::`vftable;
  v2 = &this->m_pTargetTransformNodeComponent;
  if ( this->m_pTargetTransformNodeComponent.m_pPointer )
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
  v7 = &v1->m_pTargetingSystemBaseComponent;
  if ( v1->m_pTargetingSystemBaseComponent.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v1->m_pTargetingSystemBaseComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v1->m_pTargetingSystemBaseComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pTargetingSystemBaseComponent.mPrev;
  }
  v1->m_pTargetingSystemBaseComponent.m_pPointer = 0i64;
  v10 = v7->mPrev;
  v11 = v1->m_pTargetingSystemBaseComponent.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v1->m_pTargetingSystemBaseComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pTargetingSystemBaseComponent.mPrev;
  v12 = &v1->m_pNavComponent;
  if ( v1->m_pNavComponent.m_pPointer )
  {
    v13 = v12->mPrev;
    v14 = v1->m_pNavComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v12->mPrev;
    v1->m_pNavComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pNavComponent.mPrev;
  }
  v1->m_pNavComponent.m_pPointer = 0i64;
  v15 = v12->mPrev;
  v16 = v1->m_pNavComponent.mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v12->mPrev;
  v1->m_pNavComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pNavComponent.mPrev;
  v1->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v17 = (UFG::qNode<ITask,ITask> *)&v1->mPrev;
  v18 = v1->mPrev;
  v19 = v1->mNext;
  v18->mNext = v19;
  v19->mPrev = v18;
  v17->mPrev = v17;
  v17->mNext = v17;
}

// File Line: 3618
// RVA: 0x356E80
void __fastcall PathfindAwayFromTargetTask::FindNewPath(PathfindAwayFromTargetTask *this)
{
  PathfindAwayFromTargetTask *v1; // rbx
  UFG::SimObjectGame *v2; // r8
  UFG::SimComponent *v3; // rsi
  unsigned __int16 v4; // cx
  UFG::SimComponent *v5; // rax
  UFG::qVector4 *v6; // rax
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  ITrack *v11; // rcx
  float v12; // xmm6_4
  UFG::SimComponent *v13; // rdi
  __m128 v14; // xmm3
  __m128 v15; // xmm0
  __m128 v16; // xmm2
  UFG::DaemonManager *v17; // rax
  float v18; // xmm0_4
  __int64 v19; // rcx
  UFG::FleeTraversalImmediateQuery v20; // [rsp+20h] [rbp-B8h]
  __int64 v21; // [rsp+B8h] [rbp-20h]
  UFG::DaemonQueryOutput output; // [rsp+C8h] [rbp-10h]
  __int64 (__fastcall **v23)(_QWORD); // [rsp+E8h] [rbp+10h]
  UFG::qVector3 v24; // [rsp+F0h] [rbp+18h]
  char v25; // [rsp+100h] [rbp+28h]
  __m128 v26; // [rsp+108h] [rbp+30h]
  __int64 v27; // [rsp+118h] [rbp+40h]
  __int64 v28; // [rsp+128h] [rbp+50h]
  __int64 v29; // [rsp+138h] [rbp+60h]

  v29 = -2i64;
  v1 = this;
  v20.m_daemonType = 0;
  *(_QWORD *)&v20.m_internalType = 3i64;
  v20.m_pOutput = 0i64;
  v20.vfptr = (UFG::DaemonQueryInputVtbl *)&UFG::FleeTraversalImmediateQuery::`vftable;
  v20.mpNavParams = 0i64;
  v20.mEscapeOrigin.m_vPosition.z = UFG::qVector3::msZero.z;
  v20.mEscapeOrigin.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
  *(_QWORD *)&v20.mEscapeOrigin.m_vPosition.x = -1i64;
  *(_DWORD *)&v20.mEscapeOrigin.m_bValid = 0;
  *((float *)&v20.mEscapeOrigin.m_bValid + 1) = FLOAT_N1_0;
  v20.mEscapeOrigin.m_hkvMeshPosition = 0ui64;
  v20.mEscapeOrigin.m_packedKey = -1;
  output.m_id = 0;
  *(_QWORD *)&output.m_internalType = 3i64;
  output.vfptr = (UFG::DaemonQueryOutputVtbl *)&UFG::FleeTraversalOutput::`vftable;
  v24 = UFG::qVector3::msZero;
  v23 = &UFG::HavokNavPosition::`vftable;
  v25 = 0;
  v27 = -1i64;
  v26 = _mm_unpacklo_ps(
          _mm_unpacklo_ps((__m128)LODWORD(UFG::qVector3::msZero.x), (__m128)LODWORD(UFG::qVector3::msZero.z)),
          _mm_unpacklo_ps((__m128)LODWORD(UFG::qVector3::msZero.y), (__m128)(unsigned int)FLOAT_1_0));
  v28 = 0i64;
  v2 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
  if ( v2 )
  {
    v4 = v2->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v3 = v2->m_Components.p[36].m_pComponent;
    }
    else
    {
      if ( (v4 & 0x8000u) == 0 )
      {
        if ( (v4 >> 13) & 1 )
        {
          v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::NavComponent::_TypeUID);
        }
        else if ( (v4 >> 12) & 1 )
        {
          v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::NavComponent::_TypeUID);
        }
        else
        {
          v5 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::NavComponent::_TypeUID);
        }
      }
      else
      {
        v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::NavComponent::_TypeUID);
      }
      v3 = v5;
    }
  }
  else
  {
    v3 = 0i64;
  }
  if ( ((unsigned __int8 (__fastcall *)(UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **))v3[1].m_SafePointerList.mNode.mNext[2].mPrev)(&v3[1].m_SafePointerList.mNode.mNext) )
  {
    v9 = *(float *)&v3[1].m_NameUID;
    v10 = *(float *)&v3[1].m_Flags;
    LODWORD(v20.mEscapeOrigin.m_vPosition.x) = v3[1].m_TypeUID;
    v20.mEscapeOrigin.m_vPosition.y = v9;
    v20.mEscapeOrigin.m_vPosition.z = v10;
    if ( LOBYTE(v3[1].m_pSimObject) )
    {
      v20.mEscapeOrigin.m_bValid = (bool)v3[1].m_pSimObject;
      v20.mEscapeOrigin.m_hkvMeshPosition = (hkVector4f)v3[1].m_BoundComponentHandles;
      v20.mEscapeOrigin.m_vPosition.x = *(float *)&v3[2].vfptr;
      v20.mEscapeOrigin.m_vPosition.y = *((float *)&v3[2].vfptr + 1);
    }
    else
    {
      v20.mEscapeOrigin.m_bValid = 0;
    }
    v11 = v1->m_Track;
    v12 = *((float *)&v11[1].mResourceOwner + 1);
    *(_DWORD *)&v20.mEscapeOrigin.m_bValid = HIDWORD(v11[1].mResourceOwner);
    v1->m_NavParams = *(UFG::NavParams *)((char *)&v3[2].m_BoundComponentHandles.mNode.mNext + 4);
    if ( !LOBYTE(v11[1].mMasterRate.expression.mOffset) )
      *((float *)&v20.mEscapeOrigin.m_bValid + 1) = FLOAT_500000_0;
    v20.mpNavParams = &v1->m_NavParams;
    v13 = v1->m_pTargetTransformNodeComponent.m_pPointer;
    if ( v13 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v1->m_pTargetTransformNodeComponent.m_pPointer);
      v14 = (__m128)HIDWORD(v13[2].m_BoundComponentHandles.mNode.mPrev);
      v15 = (__m128)LODWORD(v13[2].m_BoundComponentHandles.mNode.mNext);
      v20.mEscapeRadius = *(float *)&v13[2].m_BoundComponentHandles.mNode.mPrev;
      LODWORD(v20.mRoadCost) = v14.m128_i32[0];
      *(__m128 *)&v20.mMaxSearchIterations = _mm_unpacklo_ps(
                                               _mm_unpacklo_ps((__m128)LODWORD(v20.mEscapeRadius), v15),
                                               _mm_unpacklo_ps(v14, (__m128)(unsigned int)FLOAT_1_0));
    }
    else
    {
      v16 = (__m128)LODWORD(v1->m_pTaskOrigin.y);
      v15 = (__m128)LODWORD(v1->m_pTaskOrigin.z);
      v20.mEscapeRadius = v1->m_pTaskOrigin.x;
      LODWORD(v20.mRoadCost) = v16.m128_i32[0];
      *(__m128 *)&v20.mMaxSearchIterations = _mm_unpacklo_ps(
                                               _mm_unpacklo_ps((__m128)LODWORD(v20.mEscapeRadius), v15),
                                               _mm_unpacklo_ps(v16, (__m128)(unsigned int)FLOAT_1_0));
    }
    v20.mThreats.size = v15.m128_i32[0];
    *(_QWORD *)(&v20.mEscapeOrigin.m_aiMeshUid + 1) = &UFG::HavokNavPosition::`vftable;
    LOBYTE(v20.mThreats.p) = 0;
    v21 = -1i64;
    UFG::FleeTraversalImmediateQuery::AddThreat(&v20, (UFG::HavokNavPosition *)((char *)&v20.mEscapeOrigin + 56), v12);
    v17 = UFG::DaemonManager::Instance();
    UFG::DaemonManager::SubmitQuery(v17, (UFG::DaemonQueryInput *)&v20.vfptr, &output);
    if ( output.m_status == 3 )
    {
      v1->m_pFleeDestination.x = v24.x;
      v7 = v24.y;
      v18 = v24.z;
    }
    else
    {
      v1->m_pFleeDestination.x = v20.mEscapeOrigin.m_vPosition.x;
      v7 = v20.mEscapeOrigin.m_vPosition.y;
      v18 = v20.mEscapeOrigin.m_vPosition.z;
    }
    v1->m_pFleeDestination.z = v18;
  }
  else
  {
    v6 = UFG::NavComponent::GetCurrentPosition((UFG::NavComponent *)v3);
    v7 = v6->y;
    v8 = v6->z;
    v1->m_pFleeDestination.x = v6->x;
    v1->m_pFleeDestination.z = v8;
  }
  v1->m_pFleeDestination.y = v7;
  v19 = v28;
  if ( v28 )
  {
    --*(_DWORD *)(v28 + 40);
    if ( !*(_DWORD *)(v19 + 40) )
      (**(void (__fastcall ***)(__int64, signed __int64))v19)(v19, 1i64);
  }
  output.vfptr = (UFG::DaemonQueryOutputVtbl *)&UFG::DaemonQueryOutput::`vftable;
  if ( v20.mEscapeOrigin.m_hkvMeshPosition.m_quad.m128_u64[1] )
    operator delete[]((void *)v20.mEscapeOrigin.m_hkvMeshPosition.m_quad.m128_u64[1]);
}

// File Line: 3674
// RVA: 0x3473D0
void __fastcall PathfindAwayFromTargetTask::Begin(PathfindAwayFromTargetTask *this, ActionContext *action_context)
{
  PathfindAwayFromTargetTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  UFG::SimComponent *v4; // r8
  unsigned __int16 v5; // dx
  UFG::SimComponent *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::NavComponent> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::SimObjectGame *v11; // rcx
  UFG::SimComponent *v12; // r8
  unsigned __int16 v13; // dx
  UFG::SimComponent *v14; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *v15; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v19; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v21; // rax
  UFG::SimComponent *v22; // r9
  __int64 v23; // rcx
  UFG::SimComponent *v24; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v25; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v26; // rcx
  UFG::qVector4 *v27; // rax
  float v28; // xmm0_4
  float v29; // xmm1_4

  v2 = this;
  this->m_pActionContext = action_context;
  v3 = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  if ( v3 )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v4 = v3->m_Components.p[36].m_pComponent;
    }
    else
    {
      if ( (v5 & 0x8000u) == 0 )
      {
        if ( (v5 >> 13) & 1 )
        {
          v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::NavComponent::_TypeUID);
        }
        else if ( (v5 >> 12) & 1 )
        {
          v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::NavComponent::_TypeUID);
        }
        else
        {
          v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::NavComponent::_TypeUID);
        }
      }
      else
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::NavComponent::_TypeUID);
      }
      v4 = v6;
    }
  }
  else
  {
    v4 = 0i64;
  }
  v7 = &v2->m_pNavComponent;
  if ( v2->m_pNavComponent.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v2->m_pNavComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v2->m_pNavComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pNavComponent.mPrev;
  }
  v2->m_pNavComponent.m_pPointer = v4;
  if ( v4 )
  {
    v10 = v4->m_SafePointerList.mNode.mPrev;
    v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v7->mPrev = v10;
    v2->m_pNavComponent.mNext = &v4->m_SafePointerList.mNode;
    v4->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  }
  v11 = (UFG::SimObjectGame *)v2->m_pActionContext->mSimObject.m_pPointer;
  if ( v11 )
  {
    v13 = v11->m_Flags;
    if ( (v13 >> 14) & 1 )
    {
      v12 = v11->m_Components.p[20].m_pComponent;
    }
    else if ( (v13 & 0x8000u) == 0 )
    {
      if ( (v13 >> 13) & 1 )
      {
        v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else if ( (v13 >> 12) & 1 )
      {
        v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else
      {
        v14 = UFG::SimObject::GetComponentOfType(
                (UFG::SimObject *)&v11->vfptr,
                UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      v12 = v14;
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
  v15 = &v2->m_pTargetingSystemBaseComponent;
  if ( v2->m_pTargetingSystemBaseComponent.m_pPointer )
  {
    v16 = v15->mPrev;
    v17 = v2->m_pTargetingSystemBaseComponent.mNext;
    v16->mNext = v17;
    v17->mPrev = v16;
    v15->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v15->mPrev;
    v2->m_pTargetingSystemBaseComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pTargetingSystemBaseComponent.mPrev;
  }
  v2->m_pTargetingSystemBaseComponent.m_pPointer = v12;
  if ( v12 )
  {
    v18 = v12->m_SafePointerList.mNode.mPrev;
    v18->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v15->mPrev;
    v15->mPrev = v18;
    v2->m_pTargetingSystemBaseComponent.mNext = &v12->m_SafePointerList.mNode;
    v12->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v15->mPrev;
  }
  v19 = &v2->m_pTargetTransformNodeComponent;
  if ( v2->m_pTargetTransformNodeComponent.m_pPointer )
  {
    v20 = v19->mPrev;
    v21 = v2->m_pTargetTransformNodeComponent.mNext;
    v20->mNext = v21;
    v21->mPrev = v20;
    v19->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v19->mPrev;
    v2->m_pTargetTransformNodeComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pTargetTransformNodeComponent.mPrev;
  }
  v2->m_pTargetTransformNodeComponent.m_pPointer = 0i64;
  v22 = v2->m_pTargetingSystemBaseComponent.m_pPointer;
  if ( v22 )
  {
    v23 = *(_QWORD *)(56i64 * *(unsigned __int8 *)(LOBYTE(v2->m_Track[1].vfptr) + *(_QWORD *)&v22[1].m_Flags + 8i64)
                    + *(_QWORD *)&v22[1].m_TypeUID
                    + 40);
    if ( v23 )
    {
      v24 = *(UFG::SimComponent **)(v23 + 88);
      v2->m_pTargetTransformNodeComponent.m_pPointer = v24;
      if ( v24 )
      {
        v25 = v24->m_SafePointerList.mNode.mPrev;
        v26 = &v24->m_SafePointerList.mNode;
        v25->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v19->mPrev;
        v19->mPrev = v25;
        v2->m_pTargetTransformNodeComponent.mNext = v26;
        v26->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v19->mPrev;
      }
    }
  }
  v27 = UFG::NavComponent::GetCurrentPosition((UFG::NavComponent *)v2->m_pNavComponent.m_pPointer);
  v28 = v27->y;
  v29 = v27->z;
  v2->m_pTaskOrigin.x = v27->x;
  v2->m_pTaskOrigin.y = v28;
  v2->m_pTaskOrigin.z = v29;
  PathfindAwayFromTargetTask::FindNewPath(v2);
}

// File Line: 3701
// RVA: 0x3913C0
char __fastcall PathfindAwayFromTargetTask::Update(PathfindAwayFromTargetTask *this, float timestep)
{
  UFG::NavComponent *v2; // rbx
  PathfindAwayFromTargetTask *v3; // rsi
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v4; // rdx
  __int64 v5; // r8
  UFG::SimComponent *v6; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  __int64 v12; // rdi
  UFG::SimObjectGame *v13; // rcx
  unsigned __int16 v14; // dx
  UFG::SimComponent *v15; // rax
  __m128 v16; // xmm0
  __m128 v17; // xmm3
  __m128 v18; // xmm2
  UFG::qVector4 *v19; // rax
  float *v20; // rbx
  float *v21; // rdi
  UFG::HavokNavPosition npDestination; // [rsp+30h] [rbp-48h]

  v2 = 0i64;
  v3 = this;
  if ( !this->m_pTargetTransformNodeComponent.m_pPointer )
  {
    v4 = &this->m_pTargetTransformNodeComponent;
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
        v7 = v4->mPrev;
        v8 = v4->mNext;
        v7->mNext = v8;
        v8->mPrev = v7;
        v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
        v4->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
      }
      v4->m_pPointer = v6;
      if ( v6 )
      {
        v9 = v6->m_SafePointerList.mNode.mPrev;
        v9->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
        v4->mPrev = v9;
        v4->mNext = &v6->m_SafePointerList.mNode;
        v6->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
      }
    }
    else
    {
      if ( this->m_pTargetTransformNodeComponent.m_pPointer )
      {
        v10 = v4->mPrev;
        v11 = v4->mNext;
        v10->mNext = v11;
        v11->mPrev = v10;
        v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
        v4->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
      }
      v4->m_pPointer = 0i64;
    }
  }
  v12 = LOBYTE(v3->m_Track[1].mResourceOwner);
  v13 = (UFG::SimObjectGame *)v3->m_pActionContext->mSimObject.m_pPointer;
  if ( v13 )
  {
    v14 = v13->m_Flags;
    if ( (v14 >> 14) & 1 )
    {
      v2 = (UFG::NavComponent *)v13->m_Components.p[36].m_pComponent;
    }
    else
    {
      if ( (v14 & 0x8000u) == 0 )
      {
        if ( (v14 >> 13) & 1 )
        {
          v15 = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::NavComponent::_TypeUID);
        }
        else if ( (v14 >> 12) & 1 )
        {
          v15 = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::NavComponent::_TypeUID);
        }
        else
        {
          v15 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v13->vfptr, UFG::NavComponent::_TypeUID);
        }
      }
      else
      {
        v15 = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::NavComponent::_TypeUID);
      }
      v2 = (UFG::NavComponent *)v15;
    }
  }
  v16 = (__m128)LODWORD(v3->m_pFleeDestination.z);
  v17 = (__m128)LODWORD(v3->m_pFleeDestination.x);
  v18 = (__m128)LODWORD(v3->m_pFleeDestination.y);
  npDestination.m_bValid = 0;
  *(_QWORD *)&npDestination.m_packedKey = -1i64;
  LODWORD(npDestination.m_vPosition.x) = v17.m128_i32[0];
  LODWORD(npDestination.m_vPosition.y) = v18.m128_i32[0];
  npDestination.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
  LODWORD(npDestination.m_vPosition.z) = v16.m128_i32[0];
  npDestination.m_hkvMeshPosition.m_quad = _mm_unpacklo_ps(
                                             _mm_unpacklo_ps(v17, v16),
                                             _mm_unpacklo_ps(v18, (__m128)(unsigned int)FLOAT_1_0));
  UFG::NavComponent::AddGoalPoint(v2, &npDestination, 0, sNaturalMovementSpeeds[v12], 3.0);
  if ( (unsigned __int8)UFG::NavComponent::IsAtDestination(v2) )
  {
    if ( v3->m_pTargetTransformNodeComponent.m_pPointer )
    {
      v19 = UFG::NavComponent::GetCurrentPosition((UFG::NavComponent *)v3->m_pNavComponent.m_pPointer);
      v20 = (float *)v3->m_pTargetTransformNodeComponent.m_pPointer;
      v21 = &v19->x;
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v3->m_pTargetTransformNodeComponent.m_pPointer);
      if ( (float)((float)((float)((float)(v20[45] - v21[1]) * (float)(v20[45] - v21[1]))
                         + (float)((float)(v20[44] - *v21) * (float)(v20[44] - *v21)))
                 + (float)((float)(v20[46] - v21[2]) * (float)(v20[46] - v21[2]))) < (float)(*((float *)&v3->m_Track[1].mResourceOwner
                                                                                             + 1)
                                                                                           * *((float *)&v3->m_Track[1].mResourceOwner
                                                                                             + 1)) )
        PathfindAwayFromTargetTask::FindNewPath(v3);
    }
  }
  return 1;
}

// File Line: 3809
// RVA: 0x330660
void __fastcall MoveDirectlyToTargetTask::MoveDirectlyToTargetTask(MoveDirectlyToTargetTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v2; // [rsp+28h] [rbp+10h]
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *v3; // [rsp+28h] [rbp+10h]
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v4; // [rsp+28h] [rbp+10h]

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<MoveDirectlyToTargetTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&MoveDirectlyToTargetTask::`vftable;
  v2 = &this->m_pAIEntityComponent;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  this->m_pAIEntityComponent.m_pPointer = 0i64;
  v3 = &this->m_pTargetingSystemBaseComponent;
  v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  this->m_pTargetingSystemBaseComponent.m_pPointer = 0i64;
  v4 = &this->m_pTargetTransformNodeComponent;
  v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  v4->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  this->m_pTargetTransformNodeComponent.m_pPointer = 0i64;
}

// File Line: 3814
// RVA: 0x339280
void __fastcall MoveDirectlyToTargetTask::~MoveDirectlyToTargetTask(MoveDirectlyToTargetTask *this)
{
  MoveDirectlyToTargetTask *v1; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v12; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qNode<ITask,ITask> *v17; // rdx
  UFG::qNode<ITask,ITask> *v18; // rcx
  UFG::qNode<ITask,ITask> *v19; // rax

  v1 = this;
  this->vfptr = (ITaskVtbl *)&MoveDirectlyToTargetTask::`vftable;
  v2 = &this->m_pTargetTransformNodeComponent;
  if ( this->m_pTargetTransformNodeComponent.m_pPointer )
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
  v7 = &v1->m_pTargetingSystemBaseComponent;
  if ( v1->m_pTargetingSystemBaseComponent.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v1->m_pTargetingSystemBaseComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v1->m_pTargetingSystemBaseComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pTargetingSystemBaseComponent.mPrev;
  }
  v1->m_pTargetingSystemBaseComponent.m_pPointer = 0i64;
  v10 = v7->mPrev;
  v11 = v1->m_pTargetingSystemBaseComponent.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v1->m_pTargetingSystemBaseComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pTargetingSystemBaseComponent.mPrev;
  v12 = &v1->m_pAIEntityComponent;
  if ( v1->m_pAIEntityComponent.m_pPointer )
  {
    v13 = v12->mPrev;
    v14 = v1->m_pAIEntityComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v12->mPrev;
    v1->m_pAIEntityComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pAIEntityComponent.mPrev;
  }
  v1->m_pAIEntityComponent.m_pPointer = 0i64;
  v15 = v12->mPrev;
  v16 = v1->m_pAIEntityComponent.mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v12->mPrev;
  v1->m_pAIEntityComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pAIEntityComponent.mPrev;
  v1->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v17 = (UFG::qNode<ITask,ITask> *)&v1->mPrev;
  v18 = v1->mPrev;
  v19 = v1->mNext;
  v18->mNext = v19;
  v19->mPrev = v18;
  v17->mPrev = v17;
  v17->mNext = v17;
}

// File Line: 3819
// RVA: 0x346DB0
void __fastcall MoveDirectlyToTargetTask::Begin(MoveDirectlyToTargetTask *this, ActionContext *action_context)
{
  MoveDirectlyToTargetTask *v2; // rdi
  UFG::SimObjectCVBase *v3; // rcx
  UFG::SimComponent *v4; // rbx
  ActionContext *v5; // rsi
  UFG::ActiveAIEntityComponent *v6; // r8
  unsigned __int16 v7; // dx
  UFG::ActiveAIEntityComponent *v8; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v9; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::SimObjectGame *v13; // rcx
  unsigned __int16 v14; // dx
  UFG::SimComponent *v15; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *v16; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::SimComponent *v20; // r8
  __int64 v21; // r8
  UFG::SimComponent *v22; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v23; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v24; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v25; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v26; // rax

  v2 = this;
  this->m_pActionContext = action_context;
  v3 = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
  v4 = 0i64;
  v5 = action_context;
  if ( v3 )
  {
    v7 = v3->m_Flags;
    if ( (v7 >> 14) & 1 )
    {
      v8 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v3);
    }
    else if ( (v7 & 0x8000u) == 0 )
    {
      if ( (v7 >> 13) & 1 )
      {
        v8 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               (UFG::SimObjectGame *)&v3->vfptr,
                                               UFG::ActiveAIEntityComponent::_TypeUID);
      }
      else if ( (v7 >> 12) & 1 )
      {
        v8 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               (UFG::SimObjectGame *)&v3->vfptr,
                                               UFG::ActiveAIEntityComponent::_TypeUID);
      }
      else
      {
        v8 = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                               (UFG::SimObject *)&v3->vfptr,
                                               UFG::ActiveAIEntityComponent::_TypeUID);
      }
    }
    else
    {
      v8 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v3);
    }
    v6 = v8;
  }
  else
  {
    v6 = 0i64;
  }
  v9 = &v2->m_pAIEntityComponent;
  if ( v2->m_pAIEntityComponent.m_pPointer )
  {
    v10 = v9->mPrev;
    v11 = v2->m_pAIEntityComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    v9->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
    v2->m_pAIEntityComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pAIEntityComponent.mPrev;
  }
  v2->m_pAIEntityComponent.m_pPointer = (UFG::SimComponent *)&v6->vfptr;
  if ( v6 )
  {
    v12 = v6->m_SafePointerList.mNode.mPrev;
    v12->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
    v9->mPrev = v12;
    v2->m_pAIEntityComponent.mNext = &v6->m_SafePointerList.mNode;
    v6->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
  }
  v13 = (UFG::SimObjectGame *)v5->mSimObject.m_pPointer;
  if ( v13 )
  {
    v14 = v13->m_Flags;
    if ( (v14 >> 14) & 1 )
    {
      v4 = v13->m_Components.p[20].m_pComponent;
    }
    else if ( (v14 & 0x8000u) == 0 )
    {
      if ( (v14 >> 13) & 1 )
      {
        v15 = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else if ( (v14 >> 12) & 1 )
      {
        v15 = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else
      {
        v15 = UFG::SimObject::GetComponentOfType(
                (UFG::SimObject *)&v13->vfptr,
                UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      v4 = v15;
    }
    else
    {
      v4 = v13->m_Components.p[20].m_pComponent;
    }
  }
  v16 = &v2->m_pTargetingSystemBaseComponent;
  if ( v2->m_pTargetingSystemBaseComponent.m_pPointer )
  {
    v17 = v16->mPrev;
    v18 = v2->m_pTargetingSystemBaseComponent.mNext;
    v17->mNext = v18;
    v18->mPrev = v17;
    v16->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v16->mPrev;
    v2->m_pTargetingSystemBaseComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pTargetingSystemBaseComponent.mPrev;
  }
  v2->m_pTargetingSystemBaseComponent.m_pPointer = v4;
  if ( v4 )
  {
    v19 = v4->m_SafePointerList.mNode.mPrev;
    v19->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v16->mPrev;
    v16->mPrev = v19;
    v2->m_pTargetingSystemBaseComponent.mNext = &v4->m_SafePointerList.mNode;
    v4->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v16->mPrev;
  }
  v20 = v2->m_pTargetingSystemBaseComponent.m_pPointer;
  if ( v20 )
  {
    v21 = *(_QWORD *)(56i64 * *(unsigned __int8 *)(LOBYTE(v2->m_Track[1].vfptr) + *(_QWORD *)&v20[1].m_Flags + 8i64)
                    + *(_QWORD *)&v20[1].m_TypeUID
                    + 40);
    if ( v21 )
    {
      v22 = *(UFG::SimComponent **)(v21 + 88);
      v23 = &v2->m_pTargetTransformNodeComponent;
      if ( v2->m_pTargetTransformNodeComponent.m_pPointer )
      {
        v24 = v23->mPrev;
        v25 = v2->m_pTargetTransformNodeComponent.mNext;
        v24->mNext = v25;
        v25->mPrev = v24;
        v23->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v23->mPrev;
        v2->m_pTargetTransformNodeComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pTargetTransformNodeComponent.mPrev;
      }
      v2->m_pTargetTransformNodeComponent.m_pPointer = v22;
      if ( v22 )
      {
        v26 = v22->m_SafePointerList.mNode.mPrev;
        v26->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v23->mPrev;
        v23->mPrev = v26;
        v2->m_pTargetTransformNodeComponent.mNext = &v22->m_SafePointerList.mNode;
        v22->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v23->mPrev;
      }
    }
  }
}

// File Line: 3840
// RVA: 0x390A40
char __fastcall MoveDirectlyToTargetTask::Update(MoveDirectlyToTargetTask *this, float timestep)
{
  MoveDirectlyToTargetTask *v2; // rbx
  __int64 v3; // r8
  UFG::SimComponent *v4; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v5; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rax
  float *v9; // rsi
  UFG::SimObject *v10; // rcx
  UFG::NavComponent *v11; // rdi
  UFG::SimObject *v12; // rbp
  UFG::TransformNodeComponent *v13; // rbp
  ITrack *v14; // rax
  float v16; // xmm6_4
  UFG::SimObjectGame *v17; // rcx
  unsigned __int16 v18; // dx
  unsigned int v19; // edx
  UFG::SimComponent *v20; // rax
  bool v21; // zf
  __m128 v22; // xmm0
  __m128 v23; // xmm4
  __m128 v24; // xmm2
  UFG::HavokNavPosition npDestination; // [rsp+30h] [rbp-58h]

  v2 = this;
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
      v5 = &this->m_pTargetTransformNodeComponent;
      if ( this->m_pTargetTransformNodeComponent.m_pPointer )
      {
        v6 = v5->mPrev;
        v7 = v5->mNext;
        v6->mNext = v7;
        v7->mPrev = v6;
        v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
        v5->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
      }
      v5->m_pPointer = v4;
      if ( v4 )
      {
        v8 = v4->m_SafePointerList.mNode.mPrev;
        v8->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
        v5->mPrev = v8;
        v5->mNext = &v4->m_SafePointerList.mNode;
        v4->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
      }
    }
  }
  v9 = (float *)v2->m_pTargetTransformNodeComponent.m_pPointer;
  if ( !v9 )
    return 1;
  if ( !v2->m_pAIEntityComponent.m_pPointer )
    return 1;
  v10 = v2->m_pActionContext->mSimObject.m_pPointer;
  if ( !v10 || !v10->m_pTransformNodeComponent )
    return 1;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v2->m_pTargetTransformNodeComponent.m_pPointer);
  v11 = 0i64;
  v12 = v2->m_pActionContext->mSimObject.m_pPointer;
  if ( v12 )
    v13 = v12->m_pTransformNodeComponent;
  else
    v13 = 0i64;
  UFG::TransformNodeComponent::UpdateWorldTransform(v13);
  v14 = v2->m_Track;
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(v13->mWorldTransform.v3.z - v9[46]) & _xmm) <= *(float *)&v14[1].mResourceOwner
    && (float)((float)((float)(v13->mWorldTransform.v3.y - v9[45]) * (float)(v13->mWorldTransform.v3.y - v9[45]))
             + (float)((float)(v13->mWorldTransform.v3.x - v9[44]) * (float)(v13->mWorldTransform.v3.x - v9[44]))) <= (float)(*((float *)&v14[1].vfptr + 1) * *((float *)&v14[1].vfptr + 1)) )
  {
    return 1;
  }
  v16 = sNaturalMovementSpeeds[BYTE2(v14[1].vfptr)];
  v17 = (UFG::SimObjectGame *)v2->m_pActionContext->mSimObject.m_pPointer;
  if ( v17 )
  {
    v18 = v17->m_Flags;
    if ( (v18 >> 14) & 1 )
    {
      v11 = (UFG::NavComponent *)v17->m_Components.p[36].m_pComponent;
      goto LABEL_28;
    }
    if ( (v18 & 0x8000u) != 0 || (v18 >> 13) & 1 )
    {
      v19 = UFG::NavComponent::_TypeUID;
    }
    else
    {
      v21 = ((v18 >> 12) & 1) == 0;
      v19 = UFG::NavComponent::_TypeUID;
      if ( v21 )
      {
        v20 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v17->vfptr, UFG::NavComponent::_TypeUID);
        goto LABEL_27;
      }
    }
    v20 = UFG::SimObjectGame::GetComponentOfTypeHK(v17, v19);
LABEL_27:
    v11 = (UFG::NavComponent *)v20;
  }
LABEL_28:
  v22 = (__m128)*((unsigned int *)v9 + 46);
  v23 = (__m128)*((unsigned int *)v9 + 44);
  v24 = (__m128)*((unsigned int *)v9 + 45);
  npDestination.m_bValid = 0;
  LODWORD(npDestination.m_vPosition.x) = v23.m128_i32[0];
  LODWORD(npDestination.m_vPosition.y) = v24.m128_i32[0];
  npDestination.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
  *(_QWORD *)&npDestination.m_packedKey = -1i64;
  LODWORD(npDestination.m_vPosition.z) = v22.m128_i32[0];
  npDestination.m_hkvMeshPosition.m_quad = _mm_unpacklo_ps(
                                             _mm_unpacklo_ps(v23, v22),
                                             _mm_unpacklo_ps(v24, (__m128)(unsigned int)FLOAT_1_0));
  UFG::NavComponent::AddGoalPoint(v11, &npDestination, AiGoal_Replace_Direct, v16, 0.30000001);
  return 1;
}

// File Line: 3919
// RVA: 0x32E6B0
void __fastcall FollowTargetTask::FollowTargetTask(FollowTargetTask *this)
{
  FollowTargetTask *v1; // r8
  UFG::qNode<ITask,ITask> *v2; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v3; // rax
  signed __int64 v4; // rcx
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v5; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v7; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActionTreeComponent> *v8; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AIEntityComponent> *v9; // rax
  _DWORD *v10; // rdx
  float *v11; // rax
  float v12; // xmm1_4
  float v13; // xmm2_4

  v1 = this;
  v2 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<FollowTargetTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&FollowTargetTask::`vftable;
  v3 = &this->m_pAIEntityComponent;
  v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  v4 = 0i64;
  v3->m_pPointer = 0i64;
  v5 = &v1->m_pTransformNodeComponent;
  v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v5->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v1->m_pTransformNodeComponent.m_pPointer = 0i64;
  v6 = &v1->m_pTargetingSystemBaseComponent;
  v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  v6->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  v1->m_pTargetingSystemBaseComponent.m_pPointer = 0i64;
  v7 = &v1->m_pTargetTransformNodeComponent;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v7->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v1->m_pTargetTransformNodeComponent.m_pPointer = 0i64;
  v8 = &v1->m_pTargetActionTreeComponent;
  v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
  v8->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
  v1->m_pTargetActionTreeComponent.m_pPointer = 0i64;
  v9 = &v1->m_pTargetAIEntityComponent;
  v9->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
  v9->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
  v1->m_pTargetAIEntityComponent.m_pPointer = 0i64;
  *(_QWORD *)&v1->m_MovementType = 0i64;
  v10 = (_DWORD *)v1->m_LastTimeSideBecameFree;
  v11 = &v1->m_PositionOfSide[0].z;
  do
  {
    v1->m_SideIsFree[v4] = 0;
    *v10 = -943501440;
    v12 = UFG::qVector3::msZero.y;
    v13 = UFG::qVector3::msZero.z;
    *(v11 - 2) = UFG::qVector3::msZero.x;
    *(v11 - 1) = v12;
    *v11 = v13;
    ++v4;
    ++v10;
    v11 += 3;
  }
  while ( v4 < 3 );
  v1->m_TimeToChangeMovementType = -1.0;
}

// File Line: 3935
// RVA: 0x336DC0
void __fastcall FollowTargetTask::~FollowTargetTask(FollowTargetTask *this)
{
  FollowTargetTask *v1; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::AIEntityComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActionTreeComponent> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v12; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *v17; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v21; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v22; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v23; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v24; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v25; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v26; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v27; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v28; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v29; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v30; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v31; // rax
  UFG::qNode<ITask,ITask> *v32; // rdx
  UFG::qNode<ITask,ITask> *v33; // rcx
  UFG::qNode<ITask,ITask> *v34; // rax

  v1 = this;
  this->vfptr = (ITaskVtbl *)&FollowTargetTask::`vftable;
  v2 = &this->m_pTargetAIEntityComponent;
  if ( this->m_pTargetAIEntityComponent.m_pPointer )
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
  v7 = &v1->m_pTargetActionTreeComponent;
  if ( v1->m_pTargetActionTreeComponent.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v1->m_pTargetActionTreeComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v1->m_pTargetActionTreeComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pTargetActionTreeComponent.mPrev;
  }
  v1->m_pTargetActionTreeComponent.m_pPointer = 0i64;
  v10 = v7->mPrev;
  v11 = v1->m_pTargetActionTreeComponent.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v1->m_pTargetActionTreeComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pTargetActionTreeComponent.mPrev;
  v12 = &v1->m_pTargetTransformNodeComponent;
  if ( v1->m_pTargetTransformNodeComponent.m_pPointer )
  {
    v13 = v12->mPrev;
    v14 = v1->m_pTargetTransformNodeComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v12->mPrev;
    v1->m_pTargetTransformNodeComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pTargetTransformNodeComponent.mPrev;
  }
  v1->m_pTargetTransformNodeComponent.m_pPointer = 0i64;
  v15 = v12->mPrev;
  v16 = v1->m_pTargetTransformNodeComponent.mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v12->mPrev;
  v1->m_pTargetTransformNodeComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pTargetTransformNodeComponent.mPrev;
  v17 = &v1->m_pTargetingSystemBaseComponent;
  if ( v1->m_pTargetingSystemBaseComponent.m_pPointer )
  {
    v18 = v17->mPrev;
    v19 = v1->m_pTargetingSystemBaseComponent.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    v17->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v17->mPrev;
    v1->m_pTargetingSystemBaseComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pTargetingSystemBaseComponent.mPrev;
  }
  v1->m_pTargetingSystemBaseComponent.m_pPointer = 0i64;
  v20 = v17->mPrev;
  v21 = v1->m_pTargetingSystemBaseComponent.mNext;
  v20->mNext = v21;
  v21->mPrev = v20;
  v17->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v17->mPrev;
  v1->m_pTargetingSystemBaseComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pTargetingSystemBaseComponent.mPrev;
  v22 = &v1->m_pTransformNodeComponent;
  if ( v1->m_pTransformNodeComponent.m_pPointer )
  {
    v23 = v22->mPrev;
    v24 = v1->m_pTransformNodeComponent.mNext;
    v23->mNext = v24;
    v24->mPrev = v23;
    v22->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v22->mPrev;
    v1->m_pTransformNodeComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pTransformNodeComponent.mPrev;
  }
  v1->m_pTransformNodeComponent.m_pPointer = 0i64;
  v25 = v22->mPrev;
  v26 = v1->m_pTransformNodeComponent.mNext;
  v25->mNext = v26;
  v26->mPrev = v25;
  v22->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v22->mPrev;
  v1->m_pTransformNodeComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pTransformNodeComponent.mPrev;
  v27 = &v1->m_pAIEntityComponent;
  if ( v1->m_pAIEntityComponent.m_pPointer )
  {
    v28 = v27->mPrev;
    v29 = v1->m_pAIEntityComponent.mNext;
    v28->mNext = v29;
    v29->mPrev = v28;
    v27->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v27->mPrev;
    v1->m_pAIEntityComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pAIEntityComponent.mPrev;
  }
  v1->m_pAIEntityComponent.m_pPointer = 0i64;
  v30 = v27->mPrev;
  v31 = v1->m_pAIEntityComponent.mNext;
  v30->mNext = v31;
  v31->mPrev = v30;
  v27->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v27->mPrev;
  v1->m_pAIEntityComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pAIEntityComponent.mPrev;
  v1->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v32 = (UFG::qNode<ITask,ITask> *)&v1->mPrev;
  v33 = v1->mPrev;
  v34 = v1->mNext;
  v33->mNext = v34;
  v34->mPrev = v33;
  v32->mPrev = v32;
  v32->mNext = v32;
}

// File Line: 3940
// RVA: 0x344EB0
void __fastcall FollowTargetTask::Begin(FollowTargetTask *this, ActionContext *action_context)
{
  FollowTargetTask *v2; // rbx
  UFG::SimObjectCVBase *v3; // rcx
  ActionContext *v4; // rdi
  UFG::ActiveAIEntityComponent *v5; // r8
  unsigned __int16 v6; // dx
  UFG::ActiveAIEntityComponent *v7; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v8; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::SimObjectGame *v12; // rcx
  UFG::SimComponent *v13; // r8
  unsigned __int16 v14; // dx
  UFG::SimComponent *v15; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *v16; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::SimObject *v20; // r8
  UFG::SimComponent *v21; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v22; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v23; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v24; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v25; // rax
  UFG::SimComponent *v26; // r8
  UFG::SimObjectCVBase *v27; // rdi
  UFG::TransformNodeComponent *v28; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v29; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v30; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v31; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v32; // rax
  unsigned __int16 v33; // cx
  UFG::SimComponent *v34; // rdx
  UFG::SimComponent *v35; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActionTreeComponent> *v36; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v37; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v38; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v39; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v40; // rdx
  unsigned __int16 v41; // cx
  UFG::ActiveAIEntityComponent *v42; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AIEntityComponent> *v43; // rdx
  UFG::ActiveAIEntityComponent *v44; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v45; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v46; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v47; // rax

  v2 = this;
  this->m_pActionContext = action_context;
  v3 = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
  v4 = action_context;
  if ( v3 )
  {
    v6 = v3->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v7 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v3);
    }
    else if ( (v6 & 0x8000u) == 0 )
    {
      if ( (v6 >> 13) & 1 )
      {
        v7 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               (UFG::SimObjectGame *)&v3->vfptr,
                                               UFG::ActiveAIEntityComponent::_TypeUID);
      }
      else if ( (v6 >> 12) & 1 )
      {
        v7 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               (UFG::SimObjectGame *)&v3->vfptr,
                                               UFG::ActiveAIEntityComponent::_TypeUID);
      }
      else
      {
        v7 = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                               (UFG::SimObject *)&v3->vfptr,
                                               UFG::ActiveAIEntityComponent::_TypeUID);
      }
    }
    else
    {
      v7 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v3);
    }
    v5 = v7;
  }
  else
  {
    v5 = 0i64;
  }
  v8 = &v2->m_pAIEntityComponent;
  if ( v2->m_pAIEntityComponent.m_pPointer )
  {
    v9 = v8->mPrev;
    v10 = v2->m_pAIEntityComponent.mNext;
    v9->mNext = v10;
    v10->mPrev = v9;
    v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
    v2->m_pAIEntityComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pAIEntityComponent.mPrev;
  }
  v2->m_pAIEntityComponent.m_pPointer = (UFG::SimComponent *)&v5->vfptr;
  if ( v5 )
  {
    v11 = v5->m_SafePointerList.mNode.mPrev;
    v11->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
    v8->mPrev = v11;
    v2->m_pAIEntityComponent.mNext = &v5->m_SafePointerList.mNode;
    v5->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
  }
  v12 = (UFG::SimObjectGame *)v4->mSimObject.m_pPointer;
  if ( v12 )
  {
    v14 = v12->m_Flags;
    if ( (v14 >> 14) & 1 )
    {
      v13 = v12->m_Components.p[20].m_pComponent;
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
      v13 = v15;
    }
    else
    {
      v13 = v12->m_Components.p[20].m_pComponent;
    }
  }
  else
  {
    v13 = 0i64;
  }
  v16 = &v2->m_pTargetingSystemBaseComponent;
  if ( v2->m_pTargetingSystemBaseComponent.m_pPointer )
  {
    v17 = v16->mPrev;
    v18 = v2->m_pTargetingSystemBaseComponent.mNext;
    v17->mNext = v18;
    v18->mPrev = v17;
    v16->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v16->mPrev;
    v2->m_pTargetingSystemBaseComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pTargetingSystemBaseComponent.mPrev;
  }
  v2->m_pTargetingSystemBaseComponent.m_pPointer = v13;
  if ( v13 )
  {
    v19 = v13->m_SafePointerList.mNode.mPrev;
    v19->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v16->mPrev;
    v16->mPrev = v19;
    v2->m_pTargetingSystemBaseComponent.mNext = &v13->m_SafePointerList.mNode;
    v13->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v16->mPrev;
  }
  v20 = v4->mSimObject.m_pPointer;
  if ( v20 )
    v21 = (UFG::SimComponent *)&v20->m_pTransformNodeComponent->vfptr;
  else
    v21 = 0i64;
  v22 = &v2->m_pTransformNodeComponent;
  if ( v2->m_pTransformNodeComponent.m_pPointer )
  {
    v23 = v22->mPrev;
    v24 = v2->m_pTransformNodeComponent.mNext;
    v23->mNext = v24;
    v24->mPrev = v23;
    v22->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v22->mPrev;
    v2->m_pTransformNodeComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pTransformNodeComponent.mPrev;
  }
  v2->m_pTransformNodeComponent.m_pPointer = v21;
  if ( v21 )
  {
    v25 = v21->m_SafePointerList.mNode.mPrev;
    v25->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v22->mPrev;
    v22->mPrev = v25;
    v2->m_pTransformNodeComponent.mNext = &v21->m_SafePointerList.mNode;
    v21->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v22->mPrev;
  }
  v26 = v2->m_pTargetingSystemBaseComponent.m_pPointer;
  if ( v26 )
  {
    v27 = *(UFG::SimObjectCVBase **)(56i64
                                   * *(unsigned __int8 *)(LOBYTE(v2->m_Track[1].vfptr)
                                                        + *(_QWORD *)&v26[1].m_Flags
                                                        + 8i64)
                                   + *(_QWORD *)&v26[1].m_TypeUID
                                   + 40);
    if ( v27 )
    {
      v28 = v27->m_pTransformNodeComponent;
      v29 = &v2->m_pTargetTransformNodeComponent;
      if ( v2->m_pTargetTransformNodeComponent.m_pPointer )
      {
        v30 = v29->mPrev;
        v31 = v2->m_pTargetTransformNodeComponent.mNext;
        v30->mNext = v31;
        v31->mPrev = v30;
        v29->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v29->mPrev;
        v2->m_pTargetTransformNodeComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pTargetTransformNodeComponent.mPrev;
      }
      v2->m_pTargetTransformNodeComponent.m_pPointer = (UFG::SimComponent *)&v28->vfptr;
      if ( v28 )
      {
        v32 = v28->m_SafePointerList.mNode.mPrev;
        v32->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v29->mPrev;
        v29->mPrev = v32;
        v2->m_pTargetTransformNodeComponent.mNext = &v28->m_SafePointerList.mNode;
        v28->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v29->mPrev;
      }
      v33 = v27->m_Flags;
      if ( (v33 >> 14) & 1 )
      {
        v34 = v27->m_Components.p[7].m_pComponent;
      }
      else if ( (v33 & 0x8000u) == 0 )
      {
        if ( (v33 >> 13) & 1 )
        {
          v34 = v27->m_Components.p[6].m_pComponent;
        }
        else
        {
          if ( (v33 >> 12) & 1 )
            v35 = UFG::SimObjectGame::GetComponentOfTypeHK(
                    (UFG::SimObjectGame *)&v27->vfptr,
                    UFG::ActionTreeComponent::_TypeUID);
          else
            v35 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v27->vfptr, UFG::ActionTreeComponent::_TypeUID);
          v34 = v35;
        }
      }
      else
      {
        v34 = v27->m_Components.p[7].m_pComponent;
      }
      v36 = &v2->m_pTargetActionTreeComponent;
      if ( v2->m_pTargetActionTreeComponent.m_pPointer )
      {
        v37 = v36->mPrev;
        v38 = v2->m_pTargetActionTreeComponent.mNext;
        v37->mNext = v38;
        v38->mPrev = v37;
        v36->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v36->mPrev;
        v2->m_pTargetActionTreeComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pTargetActionTreeComponent.mPrev;
      }
      v2->m_pTargetActionTreeComponent.m_pPointer = v34;
      if ( v34 )
      {
        v39 = v34->m_SafePointerList.mNode.mPrev;
        v40 = &v34->m_SafePointerList.mNode;
        v39->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v36->mPrev;
        v36->mPrev = v39;
        v2->m_pTargetActionTreeComponent.mNext = v40;
        v40->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v36->mPrev;
      }
      v41 = v27->m_Flags;
      if ( (v41 >> 14) & 1 )
      {
        v42 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v27);
      }
      else if ( (v41 & 0x8000u) == 0 )
      {
        if ( (v41 >> 13) & 1 )
        {
          v42 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  (UFG::SimObjectGame *)&v27->vfptr,
                                                  UFG::ActiveAIEntityComponent::_TypeUID);
        }
        else if ( (v41 >> 12) & 1 )
        {
          v42 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  (UFG::SimObjectGame *)&v27->vfptr,
                                                  UFG::ActiveAIEntityComponent::_TypeUID);
        }
        else
        {
          v42 = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                  (UFG::SimObject *)&v27->vfptr,
                                                  UFG::ActiveAIEntityComponent::_TypeUID);
        }
      }
      else
      {
        v42 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v27);
      }
      v43 = &v2->m_pTargetAIEntityComponent;
      v44 = v42;
      if ( v2->m_pTargetAIEntityComponent.m_pPointer )
      {
        v45 = v43->mPrev;
        v46 = v2->m_pTargetAIEntityComponent.mNext;
        v45->mNext = v46;
        v46->mPrev = v45;
        v43->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v43->mPrev;
        v2->m_pTargetAIEntityComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pTargetAIEntityComponent.mPrev;
      }
      v2->m_pTargetAIEntityComponent.m_pPointer = (UFG::SimComponent *)&v44->vfptr;
      if ( v44 )
      {
        v47 = v44->m_SafePointerList.mNode.mPrev;
        v47->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v43->mPrev;
        v43->mPrev = v47;
        v2->m_pTargetAIEntityComponent.mNext = &v44->m_SafePointerList.mNode;
        v44->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v43->mPrev;
      }
    }
  }
  v2->m_MovementType = 0;
  v2->m_TimeToChangeMovementType = -1.0;
}

// File Line: 4009
// RVA: 0x3987E0
void __fastcall FollowTargetTask::UpdateSides(FollowTargetTask *this)
{
  UFG::TransformNodeComponent *v1; // rsi
  FollowTargetTask *v2; // rdi
  float v3; // xmm8_4
  UFG::SimComponent *v4; // rbx
  float v5; // xmm7_4
  __m128 v6; // xmm6
  signed int v7; // er15
  UFG::BaseCameraComponent *v8; // rax
  UFG::BaseCameraComponent *v9; // rax
  signed __int64 v10; // rax
  float v11; // xmm2_4
  __m128 v12; // xmm1
  float v13; // xmm2_4
  float v14; // xmm3_4
  float v15; // xmm7_4
  float v16; // xmm6_4
  float v17; // xmm3_4
  signed int v18; // ebp
  bool *v19; // rbx
  UFG::qVector3 *v20; // r14
  signed __int64 v21; // r12
  float v22; // xmm1_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm0_4
  float v26; // xmm0_4
  float v27; // xmm1_4
  float *v28; // rsi
  UFG::eConstrainToSidewalks v29; // er13
  bool v30; // al
  UFG::SimComponent *v31; // rbx
  __int64 v32; // rcx
  __m128 v33; // xmm2
  float v34; // xmm3_4
  __m128 v35; // xmm0
  float v36; // xmm1_4
  float v37; // xmm1_4
  float v38; // xmm3_4
  int v39; // xmm5_4
  __m128 v40; // xmm0
  float v41; // xmm4_4
  float v42; // xmm2_4
  int v43; // [rsp+20h] [rbp-78h]
  float v44; // [rsp+24h] [rbp-74h]
  int v45; // [rsp+28h] [rbp-70h]

  v1 = (UFG::TransformNodeComponent *)this->m_pTargetTransformNodeComponent.m_pPointer;
  v2 = this;
  if ( v1 && this->m_pTargetAIEntityComponent.m_pPointer && this->m_pTransformNodeComponent.m_pPointer )
  {
    v3 = UFG::Metrics::msInstance.mSimTime_Temp;
    UFG::TransformNodeComponent::UpdateWorldTransform(v1);
    v4 = v2->m_pTargetTransformNodeComponent.m_pPointer;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v2->m_pTargetTransformNodeComponent.m_pPointer);
    v5 = *(float *)&v4[2].m_SafePointerList.mNode.mNext;
    v6 = (__m128)HIDWORD(v4[2].m_SafePointerList.mNode.mNext);
    v7 = 0;
    v8 = UFG::Director::Get()->mCurrentCamera;
    if ( v8 && v8 != (UFG::BaseCameraComponent *)-80i64 )
    {
      v9 = UFG::Director::Get()->mCurrentCamera;
      if ( v9 )
        v10 = (signed __int64)&v9->mCamera;
      else
        v10 = 0i64;
      v6 = (__m128)*(unsigned int *)(v10 + 176);
      v11 = *(float *)(v10 + 184) - v1->mWorldTransform.v3.z;
      v5 = (float)(v11 * UFG::qVector3::msDirUp.y)
         - (float)((float)(*(float *)(v10 + 180) - v1->mWorldTransform.v3.y) * UFG::qVector3::msDirUp.z);
      v6.m128_f32[0] = (float)((float)(v6.m128_f32[0] - v1->mWorldTransform.v3.x) * UFG::qVector3::msDirUp.z)
                     - (float)(v11 * UFG::qVector3::msDirUp.x);
    }
    v12 = v6;
    v12.m128_f32[0] = (float)(v6.m128_f32[0] * v6.m128_f32[0]) + (float)(v5 * v5);
    LODWORD(v13) = (unsigned __int128)_mm_sqrt_ps(v12);
    if ( v13 <= 0.001 )
    {
      v15 = UFG::qVector3::msZero.x;
      v16 = UFG::qVector3::msZero.y;
      v17 = UFG::qVector3::msZero.z;
    }
    else
    {
      v14 = *(float *)&v2->m_Track[1].mBreakPoint / v13;
      v15 = v5 * v14;
      v16 = v6.m128_f32[0] * v14;
      v17 = v14 * 0.0;
    }
    v18 = 2;
    v19 = v2->m_SideIsFree;
    v20 = v2->m_PositionOfSide;
    v21 = 2i64;
    v22 = v16 + v1->mWorldTransform.v3.y;
    v23 = v17 + v1->mWorldTransform.v3.z;
    v2->m_PositionOfSide[0].x = v15 + v1->mWorldTransform.v3.x;
    v2->m_PositionOfSide[0].y = v22;
    v2->m_PositionOfSide[0].z = v23;
    v24 = v1->mWorldTransform.v3.y - v16;
    v25 = v1->mWorldTransform.v3.z - v17;
    v2->m_PositionOfSide[1].x = v1->mWorldTransform.v3.x - v15;
    v2->m_PositionOfSide[1].y = v24;
    v2->m_PositionOfSide[1].z = v25;
    v26 = v1->mWorldTransform.v3.y;
    v27 = v1->mWorldTransform.v3.z;
    v2->m_PositionOfSide[2].x = v1->mWorldTransform.v3.x;
    v28 = v2->m_LastTimeSideBecameFree;
    v2->m_PositionOfSide[2].y = v26;
    v2->m_PositionOfSide[2].z = v27;
    v29 = *((unsigned __int8 *)&v2->m_Track[1].mMasterRate.value + 4);
    do
    {
      v30 = UFG::AIEntityComponent::CanWalkStraightToPoint(
              (UFG::AIEntityComponent *)v2->m_pTargetAIEntityComponent.m_pPointer,
              v20,
              v29,
              0i64);
      if ( !*v19 && v30 )
        *v28 = v3;
      *v19++ = v30;
      ++v20;
      ++v28;
      --v21;
    }
    while ( v21 );
    v2->m_SideIsFree[2] = 1;
    v2->m_LastTimeSideBecameFree[2] = -99999.0;
    v31 = v2->m_pTransformNodeComponent.m_pPointer;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v2->m_pTransformNodeComponent.m_pPointer);
    v32 = v2->m_CurrentFollowTargetSide;
    v33 = (__m128)HIDWORD(v31[2].m_BoundComponentHandles.mNode.mPrev);
    v34 = *(float *)&v31[2].m_BoundComponentHandles.mNode.mPrev;
    v35 = (__m128)HIDWORD(v31[2].m_BoundComponentHandles.mNode.mPrev);
    v36 = *(float *)&v31[2].m_BoundComponentHandles.mNode.mPrev - v2->m_PositionOfSide[0].x;
    v35.m128_f32[0] = (float)((float)(v35.m128_f32[0] - v2->m_PositionOfSide[0].y)
                            * (float)(v35.m128_f32[0] - v2->m_PositionOfSide[0].y))
                    + (float)(v36 * v36);
    v37 = v34 - v2->m_PositionOfSide[1].x;
    v38 = v34 - v2->m_PositionOfSide[2].x;
    v39 = (unsigned __int128)_mm_sqrt_ps(v35);
    v40 = v33;
    v40.m128_f32[0] = v33.m128_f32[0] - v2->m_PositionOfSide[1].y;
    v33.m128_f32[0] = (float)(v33.m128_f32[0] - v2->m_PositionOfSide[2].y)
                    * (float)(v33.m128_f32[0] - v2->m_PositionOfSide[2].y);
    v43 = v39;
    v40.m128_f32[0] = (float)(v40.m128_f32[0] * v40.m128_f32[0]) + (float)(v37 * v37);
    LODWORD(v41) = (unsigned __int128)_mm_sqrt_ps(v40);
    v33.m128_f32[0] = v33.m128_f32[0] + (float)(v38 * v38);
    v44 = v41;
    v45 = (unsigned __int128)_mm_sqrt_ps(v33);
    if ( (_DWORD)v32 == 2 )
    {
      v42 = FLOAT_N1_0;
      if ( v2->m_SideIsFree[0]
        && (float)(UFG::Metrics::msInstance.mSimTime_Temp - v2->m_LastTimeSideBecameFree[0]) > 2.0 )
      {
        v18 = 0;
        v42 = *(float *)&v39;
      }
      if ( v2->m_SideIsFree[1]
        && (float)(UFG::Metrics::msInstance.mSimTime_Temp - v2->m_LastTimeSideBecameFree[1]) > 2.0
        && (v41 < v42 || v42 < 0.0) )
      {
        v18 = 1;
      }
LABEL_27:
      v2->m_CurrentFollowTargetSide = v18;
      return;
    }
    if ( v2->m_SideIsFree[v32]
      && (float)(UFG::Metrics::msInstance.mSimTime_Temp - v2->m_LastTimeSideBecameFree[v32]) > 2.0 )
    {
      if ( (_DWORD)v32 )
      {
        if ( (_DWORD)v32 == 1 )
          v18 = 0;
      }
      else
      {
        v18 = 1;
      }
      if ( v2->m_SideIsFree[v18]
        && (float)(UFG::Metrics::msInstance.mSimTime_Temp - v2->m_LastTimeSideBecameFree[v18]) > 2.0
        && (float)(*((float *)&v43 + v32) - 2.0) > *((float *)&v43 + v18) )
      {
        goto LABEL_27;
      }
    }
    else
    {
      if ( (_DWORD)v32 )
      {
        if ( (_DWORD)v32 != 1 )
          v7 = 2;
      }
      else
      {
        v7 = 1;
      }
      if ( !v2->m_SideIsFree[v7]
        || (float)(UFG::Metrics::msInstance.mSimTime_Temp - v2->m_LastTimeSideBecameFree[v7]) <= 2.0 )
      {
        goto LABEL_27;
      }
      v2->m_CurrentFollowTargetSide = v7;
    }
  }
}

// File Line: 4165
// RVA: 0x38ED10
char __fastcall FollowTargetTask::Update(FollowTargetTask *this, float timestep)
{
  FollowTargetTask *v2; // rsi
  UFG::SimComponent *v3; // rdi
  float *v4; // rbx
  __m128 v5; // xmm1
  float v6; // xmm9_4
  float v7; // xmm8_4
  unsigned int v8; // er8
  float *v9; // rax
  float v10; // xmm7_4
  float v11; // xmm6_4
  char v12; // r14
  unsigned __int8 v13; // bp
  float *v14; // rdi
  float *v15; // rbx
  double v16; // xmm0_8
  bool v17; // al
  int v18; // ecx
  float v19; // xmm6_4
  UFG::NavComponent *v20; // rbx
  int v21; // edi
  float v22; // xmm7_4
  signed __int64 v23; // rdi
  UFG::SimObjectGame *v24; // rcx
  unsigned __int16 v25; // dx
  UFG::SimComponent *v26; // rax
  float v27; // xmm3_4
  UFG::SimComponent *v28; // rbp
  UFG::SimObjectCVBase *v29; // rcx
  unsigned __int16 v30; // dx
  UFG::AICharacterControllerBaseComponent *v31; // rax
  float *v32; // rdi
  float *v33; // rbx
  float v34; // xmm3_4
  __m128 v35; // xmm4
  float v36; // xmm5_4
  __m128 v37; // xmm2
  UFG::HavokNavPosition npDestination; // [rsp+40h] [rbp-98h]
  unsigned int uid; // [rsp+E0h] [rbp+8h]

  v2 = this;
  v3 = this->m_pTargetTransformNodeComponent.m_pPointer;
  if ( !v3 || !this->m_pTransformNodeComponent.m_pPointer || !this->m_pTargetActionTreeComponent.m_pPointer )
    return 1;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->m_pTargetTransformNodeComponent.m_pPointer);
  v4 = (float *)v2->m_pTransformNodeComponent.m_pPointer;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v2->m_pTransformNodeComponent.m_pPointer);
  v5 = (__m128)LODWORD(v3[2].m_BoundComponentHandles.mNode.mPrev);
  v5.m128_f32[0] = (float)((float)(v5.m128_f32[0] - v4[44]) * (float)(v5.m128_f32[0] - v4[44]))
                 + (float)((float)(*((float *)&v3[2].m_BoundComponentHandles.mNode.mPrev + 1) - v4[45])
                         * (float)(*((float *)&v3[2].m_BoundComponentHandles.mNode.mPrev + 1) - v4[45]));
  LODWORD(v6) = (unsigned __int128)_mm_sqrt_ps(v5);
  LODWORD(v7) = COERCE_UNSIGNED_INT(*(float *)&v3[2].m_BoundComponentHandles.mNode.mNext - v4[46]) & _xmm;
  if ( v6 > *((float *)&v2->m_Track[1].mMasterRate.expression.mOffset + 1) )
  {
    FollowTargetTask::TeleportToTarget(v2);
    return 1;
  }
  uid = UFG::qStringHashUpper32("Sprinting", 0xFFFFFFFF);
  if ( _S30 & 1 )
  {
    v8 = mostUsedIndex_SprintingUID;
  }
  else
  {
    _S30 |= 1u;
    v8 = GetMostUsedIndex(uid);
    mostUsedIndex_SprintingUID = v8;
  }
  v9 = (float *)v2->m_Track;
  v10 = v9[15];
  v11 = v9[16];
  if ( v2->m_MovementType == eMoveType_None )
  {
    v10 = v9[17];
    v11 = v9[18];
  }
  v12 = 0;
  v13 = ActionController::IsPlaying(
          (ActionController *)&v2->m_pTargetActionTreeComponent.m_pPointer[3],
          (ActionID *)&uid,
          v8,
          1);
  v14 = (float *)v2->m_pTargetTransformNodeComponent.m_pPointer;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v2->m_pTargetTransformNodeComponent.m_pPointer);
  v15 = (float *)v2->m_pTransformNodeComponent.m_pPointer;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v2->m_pTransformNodeComponent.m_pPointer);
  v16 = (float)((float)((float)(v15[33] * v14[33]) + (float)(v15[32] * v14[32])) + (float)(v15[34] * v14[34]));
  v17 = v6 < v10 && v7 < v11;
  v18 = v2->m_MovementType;
  v19 = 0.0;
  v20 = 0i64;
  if ( v18 == 3 && v13 && v16 > -0.707 )
  {
    v21 = 3;
    if ( v17 )
      v12 = 1;
  }
  else
  {
    if ( v17 )
    {
      v2->m_MovementType = 0;
      goto LABEL_30;
    }
    v21 = (v13 != 0) + 2;
  }
  if ( v21 > v18 )
  {
    v22 = UFG::Metrics::msInstance.mSimTime_Temp;
    if ( v2->m_TimeToChangeMovementType < 0.0 )
      v2->m_TimeToChangeMovementType = UFG::GetRandomNumberInRange(
                                         *((float *)&v2->m_Track[1].mMasterRate.text.mOffset + 1),
                                         *(float *)&v2->m_Track[1].mMasterRate.expression.mOffset)
                                     + v22;
    if ( v22 < v2->m_TimeToChangeMovementType && v2->m_MovementType )
      goto LABEL_30;
    v2->m_MovementType = v21;
  }
  v2->m_TimeToChangeMovementType = -1.0;
LABEL_30:
  if ( v2->m_pAIEntityComponent.m_pPointer )
  {
    if ( v2->m_MovementType )
    {
      FollowTargetTask::UpdateSides(v2);
      v23 = 3 * ((signed int)v2->m_CurrentFollowTargetSide + 18i64);
      v24 = (UFG::SimObjectGame *)v2->m_pActionContext->mSimObject.m_pPointer;
      if ( v24 )
      {
        v25 = v24->m_Flags;
        if ( (v25 >> 14) & 1 )
        {
          v20 = (UFG::NavComponent *)v24->m_Components.p[36].m_pComponent;
        }
        else
        {
          if ( (v25 & 0x8000u) == 0 )
          {
            if ( (v25 >> 13) & 1 )
            {
              v26 = UFG::SimObjectGame::GetComponentOfTypeHK(v24, UFG::NavComponent::_TypeUID);
            }
            else if ( (v25 >> 12) & 1 )
            {
              v26 = UFG::SimObjectGame::GetComponentOfTypeHK(v24, UFG::NavComponent::_TypeUID);
            }
            else
            {
              v26 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v24->vfptr, UFG::NavComponent::_TypeUID);
            }
          }
          else
          {
            v26 = UFG::SimObjectGame::GetComponentOfTypeHK(v24, UFG::NavComponent::_TypeUID);
          }
          v20 = (UFG::NavComponent *)v26;
        }
      }
      v27 = sNaturalMovementSpeeds[v2->m_MovementType];
      if ( v12 )
      {
        v27 = v27 - 2.0;
        if ( v27 <= 0.0 )
          v27 = 0.0;
      }
      npDestination.m_vPosition.x = *((float *)&v2->vfptr + v23);
      npDestination.m_vPosition.y = *((float *)&v2->vfptr + v23 + 1);
      npDestination.m_vPosition.z = *((float *)&v2->mPrev + v23);
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
      UFG::NavComponent::AddGoalPoint(v20, &npDestination, 0, v27, 0.30000001);
      UFG::NavComponent::IsAtDestination(v20);
    }
    else
    {
      v28 = v2->m_pTargetTransformNodeComponent.m_pPointer;
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v2->m_pTargetTransformNodeComponent.m_pPointer);
      v29 = (UFG::SimObjectCVBase *)v2->m_pActionContext->mSimObject.m_pPointer;
      if ( v29 )
      {
        v30 = v29->m_Flags;
        if ( (v30 >> 14) & 1 )
        {
          v31 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v29);
        }
        else if ( (v30 & 0x8000u) == 0 )
        {
          if ( (v30 >> 13) & 1 )
            v31 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               (UFG::SimObjectGame *)&v29->vfptr,
                                                               UFG::AICharacterControllerBaseComponent::_TypeUID);
          else
            v31 = (UFG::AICharacterControllerBaseComponent *)((v30 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                                  (UFG::SimObjectGame *)&v29->vfptr,
                                                                                  UFG::AICharacterControllerBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v29->vfptr, UFG::AICharacterControllerBaseComponent::_TypeUID));
        }
        else
        {
          v31 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v29);
        }
        v32 = (float *)v31;
        if ( v31 )
        {
          v33 = (float *)v2->m_pTransformNodeComponent.m_pPointer;
          UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v2->m_pTransformNodeComponent.m_pPointer);
          v34 = *(float *)&v28[2].m_BoundComponentHandles.mNode.mPrev - v33[44];
          v35 = (__m128)HIDWORD(v28[2].m_BoundComponentHandles.mNode.mPrev);
          v35.m128_f32[0] = v35.m128_f32[0] - v33[45];
          v36 = *(float *)&v28[2].m_BoundComponentHandles.mNode.mNext - v33[46];
          v37 = v35;
          v37.m128_f32[0] = (float)((float)(v35.m128_f32[0] * v35.m128_f32[0]) + (float)(v34 * v34))
                          + (float)(v36 * v36);
          if ( v37.m128_f32[0] != 0.0 )
            v19 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v37));
          v32[37] = v34 * v19;
          v32[38] = v35.m128_f32[0] * v19;
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
  FollowTargetTask *v1; // r14
  float *v2; // r15
  UFG::SimComponent *v3; // rax
  UFG::SimComponent *v4; // rbx
  float v5; // xmm3_4
  __m128 v6; // xmm6
  float v7; // xmm4_4
  float v8; // xmm2_4
  __m128 v9; // xmm1
  float v10; // xmm5_4
  ITrack *v11; // rax
  float v12; // xmm7_4
  float v13; // xmm8_4
  float v14; // xmm6_4
  float v15; // xmm7_4
  char v16; // si
  UFG::eConstrainToSidewalks v17; // er12
  float v18; // xmm0_4
  signed int v19; // er13
  signed int v20; // edi
  float v21; // xmm10_4
  float v22; // xmm12_4
  float v23; // xmm7_4
  float v24; // xmm11_4
  float v25; // xmm8_4
  float v26; // xmm13_4
  float v27; // xmm6_4
  float v28; // xmm7_4
  float v29; // xmm11_4
  float v30; // xmm10_4
  float v31; // xmm8_4
  float v32; // xmm13_4
  float v33; // xmm12_4
  float v34; // xmm6_4
  float v35; // xmm3_4
  float v36; // xmm5_4
  float v37; // xmm2_4
  float v38; // xmm4_4
  float v39; // xmm1_4
  float v40; // xmm0_4
  UFG::SimObject *v41; // rbx
  UFG::allocator::free_link *v42; // rax
  UFG::qVector3 dir; // [rsp+48h] [rbp-90h]
  UFG::qVector3 origin; // [rsp+58h] [rbp-80h]
  UFG::qVector3 point; // [rsp+68h] [rbp-70h]
  UFG::qVector3 v46; // [rsp+78h] [rbp-60h]
  UFG::allocator::free_link *v47; // [rsp+138h] [rbp+60h]

  v1 = this;
  v2 = (float *)this->m_pTargetTransformNodeComponent.m_pPointer;
  if ( !v2 )
    return;
  if ( !this->m_pTargetAIEntityComponent.m_pPointer )
    return;
  v3 = this->m_pTransformNodeComponent.m_pPointer;
  if ( !v3 )
    return;
  if ( !v3->m_pSimObject )
    return;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->m_pTargetTransformNodeComponent.m_pPointer);
  v4 = v1->m_pTransformNodeComponent.m_pPointer;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v1->m_pTransformNodeComponent.m_pPointer);
  v5 = v2[45];
  v6 = (__m128)HIDWORD(v4[2].m_BoundComponentHandles.mNode.mPrev);
  v6.m128_f32[0] = v6.m128_f32[0] - v5;
  v7 = v2[44];
  v8 = *(float *)&v4[2].m_BoundComponentHandles.mNode.mPrev - v7;
  v9 = v6;
  v9.m128_f32[0] = (float)(v6.m128_f32[0] * v6.m128_f32[0]) + (float)(v8 * v8);
  LODWORD(v10) = (unsigned __int128)_mm_sqrt_ps(v9);
  if ( v10 <= 0.001 )
    return;
  v11 = v1->m_Track;
  v12 = v11[1].mMasterRate.value / v10;
  v13 = v12 * 0.0;
  v14 = v6.m128_f32[0] * v12;
  v15 = v12 * v8;
  origin = UFG::qVector3::msZero;
  dir = UFG::qVector3::msZero;
  v16 = 0;
  v17 = *((unsigned __int8 *)&v11[1].mMasterRate.value + 4);
  v18 = v13 + v2[46];
  point.x = v7 + v15;
  point.y = v5 + v14;
  point.z = v18;
  if ( UFG::AIEntityComponent::CanWalkStraightToPoint(
         (UFG::AIEntityComponent *)v1->m_pTargetAIEntityComponent.m_pPointer,
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
  v19 = (signed int)(float)((float)(atan2f(v14, v15) * 32768.0) * 0.31830987);
  v20 = 1;
  while ( !v16 )
  {
    v21 = UFG::qVector3::msZero.z;
    v22 = UFG::qVector3::msZero.z;
    v23 = (float)((float)(unsigned __int16)((signed int)(float)((float)((float)v20 * 0.1) * 32767.0) + v19) * 3.1415927)
        * 0.000030517578;
    v24 = sinf(v23);
    v25 = (float)((float)(unsigned __int16)(v19 - (signed int)(float)((float)((float)v20 * 0.1) * 32767.0)) * 3.1415927)
        * 0.000030517578;
    v26 = sinf(v25);
    v27 = v1->m_Track[1].mMasterRate.value;
    v28 = cosf(v23) * v27;
    v29 = v24 * v27;
    v30 = v21 * v27;
    v31 = cosf(v25) * v27;
    v32 = v26 * v27;
    v33 = v22 * v27;
    v34 = v2[46];
    v35 = v2[46] + v30;
    v36 = v2[45];
    v37 = v2[45] + v29;
    v38 = v2[44];
    point.x = v2[44] + v28;
    point.y = v37;
    point.z = v35;
    v46.x = v38 + v31;
    v46.y = v36 + v32;
    origin.x = v34 + v33;
    if ( UFG::AIEntityComponent::CanWalkStraightToPoint(
           (UFG::AIEntityComponent *)v1->m_pTargetAIEntityComponent.m_pPointer,
           &point,
           v17,
           0i64) )
    {
      origin.x = point.x;
      v39 = point.y;
      v40 = point.z;
      LODWORD(dir.x) = LODWORD(v28) ^ _xmm[0];
      LODWORD(dir.y) = LODWORD(v29) ^ _xmm[0];
      LODWORD(dir.z) = LODWORD(v30) ^ _xmm[0];
LABEL_14:
      v16 = 1;
      origin.z = v40;
      origin.y = v39;
      goto LABEL_15;
    }
    if ( UFG::AIEntityComponent::CanWalkStraightToPoint(
           (UFG::AIEntityComponent *)v1->m_pTargetAIEntityComponent.m_pPointer,
           &v46,
           v17,
           0i64) )
    {
      origin.x = v46.x;
      v39 = v46.y;
      v40 = v46.x;
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
  v41 = v1->m_pTransformNodeComponent.m_pPointer->m_pSimObject;
  v42 = UFG::qMalloc(0x90ui64, "FollowTargetTask", 0i64);
  v47 = v42;
  if ( v42 )
    UFG::TeleportEvent::TeleportEvent(
      (UFG::TeleportEvent *)v42,
      &origin,
      &dir,
      v41->mNode.mUID,
      0,
      UFG::TeleportEvent::m_Name,
      &UFG::qVector3::msDirUp);
  UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v42);
}

// File Line: 4468
// RVA: 0x32D190
void __fastcall CircleAroundCombatantsTask::CircleAroundCombatantsTask(CircleAroundCombatantsTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v2; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v3; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *v4; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v5; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::FormationManagerComponent> *v7; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<CircleAroundCombatantsTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&CircleAroundCombatantsTask::`vftable;
  v2 = &this->m_pAIEntityComponent;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  this->m_pAIEntityComponent.m_pPointer = 0i64;
  v3 = &this->m_pTransformNodeComponent;
  v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  this->m_pTransformNodeComponent.m_pPointer = 0i64;
  v4 = &this->m_pTargetingSystemBaseComponent;
  v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  v4->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  this->m_pTargetingSystemBaseComponent.m_pPointer = 0i64;
  v5 = &this->m_pTargetSimObject;
  v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v5->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  this->m_pTargetSimObject.m_pPointer = 0i64;
  v6 = &this->m_pTargetTransformNodeComponent;
  v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  v6->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  this->m_pTargetTransformNodeComponent.m_pPointer = 0i64;
  v7 = &this->m_pTargetFormationManagerComponent;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v7->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  this->m_pTargetFormationManagerComponent.m_pPointer = 0i64;
}

// File Line: 4472
// RVA: 0x335920
void __fastcall CircleAroundCombatantsTask::~CircleAroundCombatantsTask(CircleAroundCombatantsTask *this)
{
  CircleAroundCombatantsTask *v1; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::FormationManagerComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v12; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *v17; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v21; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v22; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v23; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v24; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v25; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v26; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v27; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v28; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v29; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v30; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v31; // rax
  UFG::qNode<ITask,ITask> *v32; // rdx
  UFG::qNode<ITask,ITask> *v33; // rcx
  UFG::qNode<ITask,ITask> *v34; // rax

  v1 = this;
  this->vfptr = (ITaskVtbl *)&CircleAroundCombatantsTask::`vftable;
  v2 = &this->m_pTargetFormationManagerComponent;
  if ( this->m_pTargetFormationManagerComponent.m_pPointer )
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
  v7 = &v1->m_pTargetTransformNodeComponent;
  if ( v1->m_pTargetTransformNodeComponent.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v1->m_pTargetTransformNodeComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v1->m_pTargetTransformNodeComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pTargetTransformNodeComponent.mPrev;
  }
  v1->m_pTargetTransformNodeComponent.m_pPointer = 0i64;
  v10 = v7->mPrev;
  v11 = v1->m_pTargetTransformNodeComponent.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v1->m_pTargetTransformNodeComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pTargetTransformNodeComponent.mPrev;
  v12 = &v1->m_pTargetSimObject;
  if ( v1->m_pTargetSimObject.m_pPointer )
  {
    v13 = v12->mPrev;
    v14 = v1->m_pTargetSimObject.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v12->mPrev;
    v1->m_pTargetSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->m_pTargetSimObject.mPrev;
  }
  v1->m_pTargetSimObject.m_pPointer = 0i64;
  v15 = v12->mPrev;
  v16 = v1->m_pTargetSimObject.mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v12->mPrev;
  v1->m_pTargetSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->m_pTargetSimObject.mPrev;
  v17 = &v1->m_pTargetingSystemBaseComponent;
  if ( v1->m_pTargetingSystemBaseComponent.m_pPointer )
  {
    v18 = v17->mPrev;
    v19 = v1->m_pTargetingSystemBaseComponent.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    v17->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v17->mPrev;
    v1->m_pTargetingSystemBaseComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pTargetingSystemBaseComponent.mPrev;
  }
  v1->m_pTargetingSystemBaseComponent.m_pPointer = 0i64;
  v20 = v17->mPrev;
  v21 = v1->m_pTargetingSystemBaseComponent.mNext;
  v20->mNext = v21;
  v21->mPrev = v20;
  v17->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v17->mPrev;
  v1->m_pTargetingSystemBaseComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pTargetingSystemBaseComponent.mPrev;
  v22 = &v1->m_pTransformNodeComponent;
  if ( v1->m_pTransformNodeComponent.m_pPointer )
  {
    v23 = v22->mPrev;
    v24 = v1->m_pTransformNodeComponent.mNext;
    v23->mNext = v24;
    v24->mPrev = v23;
    v22->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v22->mPrev;
    v1->m_pTransformNodeComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pTransformNodeComponent.mPrev;
  }
  v1->m_pTransformNodeComponent.m_pPointer = 0i64;
  v25 = v22->mPrev;
  v26 = v1->m_pTransformNodeComponent.mNext;
  v25->mNext = v26;
  v26->mPrev = v25;
  v22->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v22->mPrev;
  v1->m_pTransformNodeComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pTransformNodeComponent.mPrev;
  v27 = &v1->m_pAIEntityComponent;
  if ( v1->m_pAIEntityComponent.m_pPointer )
  {
    v28 = v27->mPrev;
    v29 = v1->m_pAIEntityComponent.mNext;
    v28->mNext = v29;
    v29->mPrev = v28;
    v27->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v27->mPrev;
    v1->m_pAIEntityComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pAIEntityComponent.mPrev;
  }
  v1->m_pAIEntityComponent.m_pPointer = 0i64;
  v30 = v27->mPrev;
  v31 = v1->m_pAIEntityComponent.mNext;
  v30->mNext = v31;
  v31->mPrev = v30;
  v27->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v27->mPrev;
  v1->m_pAIEntityComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pAIEntityComponent.mPrev;
  v1->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v32 = (UFG::qNode<ITask,ITask> *)&v1->mPrev;
  v33 = v1->mPrev;
  v34 = v1->mNext;
  v33->mNext = v34;
  v34->mPrev = v33;
  v32->mPrev = v32;
  v32->mNext = v32;
}

// File Line: 4477
// RVA: 0x3440F0
void __fastcall CircleAroundCombatantsTask::Begin(CircleAroundCombatantsTask *this, ActionContext *action_context)
{
  CircleAroundCombatantsTask *v2; // rdi
  UFG::SimObjectCVBase *v3; // rcx
  ActionContext *v4; // rbx
  UFG::ActiveAIEntityComponent *v5; // r8
  unsigned __int16 v6; // dx
  UFG::ActiveAIEntityComponent *v7; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v8; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::SimObjectGame *v12; // rcx
  UFG::SimComponent *v13; // r8
  unsigned __int16 v14; // dx
  UFG::SimComponent *v15; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *v16; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::SimObject *v20; // r8
  UFG::SimComponent *v21; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v22; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v23; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v24; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v25; // rax
  UFG::SimComponent *v26; // rdx
  float v27; // xmm2_4
  float v28; // xmm0_4
  UFG::TransformNodeComponent *v29; // rsi
  UFG::SimComponent *v30; // rbx

  v2 = this;
  this->m_pActionContext = action_context;
  v3 = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
  v4 = action_context;
  if ( v3 )
  {
    v6 = v3->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v7 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v3);
    }
    else if ( (v6 & 0x8000u) == 0 )
    {
      if ( (v6 >> 13) & 1 )
      {
        v7 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               (UFG::SimObjectGame *)&v3->vfptr,
                                               UFG::ActiveAIEntityComponent::_TypeUID);
      }
      else if ( (v6 >> 12) & 1 )
      {
        v7 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               (UFG::SimObjectGame *)&v3->vfptr,
                                               UFG::ActiveAIEntityComponent::_TypeUID);
      }
      else
      {
        v7 = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                               (UFG::SimObject *)&v3->vfptr,
                                               UFG::ActiveAIEntityComponent::_TypeUID);
      }
    }
    else
    {
      v7 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v3);
    }
    v5 = v7;
  }
  else
  {
    v5 = 0i64;
  }
  v8 = &v2->m_pAIEntityComponent;
  if ( v2->m_pAIEntityComponent.m_pPointer )
  {
    v9 = v8->mPrev;
    v10 = v2->m_pAIEntityComponent.mNext;
    v9->mNext = v10;
    v10->mPrev = v9;
    v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
    v2->m_pAIEntityComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pAIEntityComponent.mPrev;
  }
  v2->m_pAIEntityComponent.m_pPointer = (UFG::SimComponent *)&v5->vfptr;
  if ( v5 )
  {
    v11 = v5->m_SafePointerList.mNode.mPrev;
    v11->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
    v8->mPrev = v11;
    v2->m_pAIEntityComponent.mNext = &v5->m_SafePointerList.mNode;
    v5->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
  }
  v12 = (UFG::SimObjectGame *)v4->mSimObject.m_pPointer;
  if ( v12 )
  {
    v14 = v12->m_Flags;
    if ( (v14 >> 14) & 1 )
    {
      v13 = v12->m_Components.p[20].m_pComponent;
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
      v13 = v15;
    }
    else
    {
      v13 = v12->m_Components.p[20].m_pComponent;
    }
  }
  else
  {
    v13 = 0i64;
  }
  v16 = &v2->m_pTargetingSystemBaseComponent;
  if ( v2->m_pTargetingSystemBaseComponent.m_pPointer )
  {
    v17 = v16->mPrev;
    v18 = v2->m_pTargetingSystemBaseComponent.mNext;
    v17->mNext = v18;
    v18->mPrev = v17;
    v16->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v16->mPrev;
    v2->m_pTargetingSystemBaseComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pTargetingSystemBaseComponent.mPrev;
  }
  v2->m_pTargetingSystemBaseComponent.m_pPointer = v13;
  if ( v13 )
  {
    v19 = v13->m_SafePointerList.mNode.mPrev;
    v19->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v16->mPrev;
    v16->mPrev = v19;
    v2->m_pTargetingSystemBaseComponent.mNext = &v13->m_SafePointerList.mNode;
    v13->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v16->mPrev;
  }
  v20 = v4->mSimObject.m_pPointer;
  if ( v20 )
    v21 = (UFG::SimComponent *)&v20->m_pTransformNodeComponent->vfptr;
  else
    v21 = 0i64;
  v22 = &v2->m_pTransformNodeComponent;
  if ( v2->m_pTransformNodeComponent.m_pPointer )
  {
    v23 = v22->mPrev;
    v24 = v2->m_pTransformNodeComponent.mNext;
    v23->mNext = v24;
    v24->mPrev = v23;
    v22->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v22->mPrev;
    v2->m_pTransformNodeComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pTransformNodeComponent.mPrev;
  }
  v2->m_pTransformNodeComponent.m_pPointer = v21;
  if ( v21 )
  {
    v25 = v21->m_SafePointerList.mNode.mPrev;
    v25->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v22->mPrev;
    v22->mPrev = v25;
    v2->m_pTransformNodeComponent.mNext = &v21->m_SafePointerList.mNode;
    v21->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v22->mPrev;
  }
  v26 = v2->m_pTargetingSystemBaseComponent.m_pPointer;
  if ( v26 )
    CircleAroundCombatantsTask::SetMyTarget(
      v2,
      *(UFG::SimObject **)(56i64
                         * *(unsigned __int8 *)(LOBYTE(v2->m_Track[1].vfptr) + *(_QWORD *)&v26[1].m_Flags + 8i64)
                         + *(_QWORD *)&v26[1].m_TypeUID
                         + 40));
  v2->m_CurrentlyMoving = 0;
  v27 = UFG::qVector3::msZero.z;
  v28 = UFG::qVector3::msZero.x;
  v2->m_DesiredPosition.y = UFG::qVector3::msZero.y;
  v2->m_DesiredPosition.z = v27;
  v2->m_DesiredPosition.x = v28;
  v29 = (UFG::TransformNodeComponent *)v2->m_pTransformNodeComponent.m_pPointer;
  v2->m_DesiredPositionValid = 0;
  v2->m_LastTimeSinceStopped = -99999.0;
  if ( v29 && v2->m_pTargetTransformNodeComponent.m_pPointer )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(v29);
    v30 = v2->m_pTargetTransformNodeComponent.m_pPointer;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v2->m_pTargetTransformNodeComponent.m_pPointer);
    v2->m_DesiredAngle = (signed int)(float)((float)(atan2f(
                                                       v29->mWorldTransform.v3.y
                                                     - *((float *)&v30[2].m_BoundComponentHandles.mNode.mPrev + 1),
                                                       v29->mWorldTransform.v3.x
                                                     - *(float *)&v30[2].m_BoundComponentHandles.mNode.mPrev)
                                                   * 32768.0)
                                           * 0.31830987);
  }
  else
  {
    v2->m_DesiredAngle = 0;
  }
  v2->m_TestAngleIndex = 0;
}

// File Line: 4518
// RVA: 0x387570
void __fastcall CircleAroundCombatantsTask::SetMyTarget(CircleAroundCombatantsTask *this, UFG::SimObject *target_object)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v2; // r9
  CircleAroundCombatantsTask *v3; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v4; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::SimObject *v7; // r8
  UFG::TransformNodeComponent *v8; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v9; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::SimObjectGame *v13; // rcx
  UFG::SimComponent *v14; // rdx
  unsigned __int16 v15; // dx
  UFG::SimComponent *v16; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::FormationManagerComponent> *v17; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v21; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v22; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v23; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::FormationManagerComponent> *v24; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v25; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v26; // rax

  v2 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->m_pTargetSimObject.mPrev;
  v3 = this;
  if ( this->m_pTargetSimObject.m_pPointer )
  {
    v4 = v2->mPrev;
    v5 = this->m_pTargetSimObject.mNext;
    v4->mNext = v5;
    v5->mPrev = v4;
    v2->mPrev = v2;
    this->m_pTargetSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->m_pTargetSimObject.mPrev;
  }
  this->m_pTargetSimObject.m_pPointer = target_object;
  if ( target_object )
  {
    v6 = target_object->m_SafePointerList.mNode.mPrev;
    v6->mNext = v2;
    v2->mPrev = v6;
    this->m_pTargetSimObject.mNext = &target_object->m_SafePointerList.mNode;
    target_object->m_SafePointerList.mNode.mPrev = v2;
  }
  v7 = this->m_pTargetSimObject.m_pPointer;
  if ( v7 )
  {
    v8 = v7->m_pTransformNodeComponent;
    v9 = &this->m_pTargetTransformNodeComponent;
    if ( this->m_pTargetTransformNodeComponent.m_pPointer )
    {
      v10 = v9->mPrev;
      v11 = v3->m_pTargetTransformNodeComponent.mNext;
      v10->mNext = v11;
      v11->mPrev = v10;
      v9->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
      v3->m_pTargetTransformNodeComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->m_pTargetTransformNodeComponent.mPrev;
    }
    v3->m_pTargetTransformNodeComponent.m_pPointer = (UFG::SimComponent *)&v8->vfptr;
    if ( v8 )
    {
      v12 = v8->m_SafePointerList.mNode.mPrev;
      v12->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
      v9->mPrev = v12;
      v3->m_pTargetTransformNodeComponent.mNext = &v8->m_SafePointerList.mNode;
      v8->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
    }
    v13 = (UFG::SimObjectGame *)v3->m_pTargetSimObject.m_pPointer;
    if ( v13 )
    {
      v15 = v13->m_Flags;
      if ( (v15 >> 14) & 1 )
      {
        v16 = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::FormationManagerComponent::_TypeUID);
      }
      else if ( (v15 & 0x8000u) == 0 )
      {
        if ( (v15 >> 13) & 1 )
        {
          v16 = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::FormationManagerComponent::_TypeUID);
        }
        else if ( (v15 >> 12) & 1 )
        {
          v16 = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::FormationManagerComponent::_TypeUID);
        }
        else
        {
          v16 = UFG::SimObject::GetComponentOfType(
                  (UFG::SimObject *)&v13->vfptr,
                  UFG::FormationManagerComponent::_TypeUID);
        }
      }
      else
      {
        v16 = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::FormationManagerComponent::_TypeUID);
      }
      v14 = v16;
    }
    else
    {
      v14 = 0i64;
    }
    v17 = &v3->m_pTargetFormationManagerComponent;
    if ( v3->m_pTargetFormationManagerComponent.m_pPointer )
    {
      v18 = v17->mPrev;
      v19 = v3->m_pTargetFormationManagerComponent.mNext;
      v18->mNext = v19;
      v19->mPrev = v18;
      v17->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v17->mPrev;
      v3->m_pTargetFormationManagerComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->m_pTargetFormationManagerComponent.mPrev;
    }
    v3->m_pTargetFormationManagerComponent.m_pPointer = v14;
    if ( v14 )
    {
      v20 = v14->m_SafePointerList.mNode.mPrev;
      v20->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v17->mPrev;
      v17->mPrev = v20;
      v3->m_pTargetFormationManagerComponent.mNext = &v14->m_SafePointerList.mNode;
      v14->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v17->mPrev;
    }
  }
  else
  {
    v21 = &this->m_pTargetTransformNodeComponent;
    if ( this->m_pTargetTransformNodeComponent.m_pPointer )
    {
      v22 = v21->mPrev;
      v23 = v3->m_pTargetTransformNodeComponent.mNext;
      v22->mNext = v23;
      v23->mPrev = v22;
      v21->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v21->mPrev;
      v3->m_pTargetTransformNodeComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->m_pTargetTransformNodeComponent.mPrev;
    }
    v3->m_pTargetTransformNodeComponent.m_pPointer = 0i64;
    v24 = &v3->m_pTargetFormationManagerComponent;
    if ( v3->m_pTargetFormationManagerComponent.m_pPointer )
    {
      v25 = v24->mPrev;
      v26 = v3->m_pTargetFormationManagerComponent.mNext;
      v25->mNext = v26;
      v26->mPrev = v25;
      v24->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v24->mPrev;
      v3->m_pTargetFormationManagerComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->m_pTargetFormationManagerComponent.mPrev;
    }
    v3->m_pTargetFormationManagerComponent.m_pPointer = 0i64;
  }
}

// File Line: 4540
// RVA: 0x34F9A0
char __usercall CircleAroundCombatantsTask::ComputeDesiredPosition@<al>(CircleAroundCombatantsTask *this@<rcx>, UFG::qVector3 *desiredPosition@<rdx>, UFG::HavokNavPosition *npTargetPosition@<r8>, unsigned __int16 testAngle@<r9w>, float a5@<r14d>, float desiredDistance, float minDistance, float maxDistance)
{
  UFG::HavokNavPosition *v8; // rbx
  UFG::qVector3 *v9; // rdi
  CircleAroundCombatantsTask *v10; // rsi
  __m128 v11; // xmm8
  __m128 v12; // xmm6
  __m128 v13; // xmm0
  float v14; // xmm11_4
  __m128 v15; // xmm7
  __m128 v16; // xmm0
  ActionContext *v17; // rax
  __m128 v18; // xmm3
  float v19; // xmm10_4
  UFG::SimObjectGame *v20; // r8
  UFG::SimComponent *v21; // rdx
  unsigned __int16 v22; // cx
  UFG::SimComponent *v23; // rax
  float v24; // xmm6_4
  __m128 v25; // xmm2
  float v26; // xmm3_4
  __m128 v28; // xmm2
  float v29; // xmm4_4
  float v30; // xmm11_4
  float v31; // xmm0_4
  int v32; // ebx
  UFG::SimObjectGame *v33; // rcx
  unsigned __int16 v34; // dx
  __m128 v35; // xmm4
  __m128 v36; // xmm3
  __m128 v37; // xmm0
  float v38; // [rsp+30h] [rbp-B8h]
  float v39; // [rsp+34h] [rbp-B4h]
  float v40; // [rsp+38h] [rbp-B0h]
  UFG::HavokNavPosition v41; // [rsp+40h] [rbp-A8h]
  char v42; // [rsp+80h] [rbp-68h]
  __m128 v43; // [rsp+88h] [rbp-60h]
  __int64 v44; // [rsp+98h] [rbp-50h]
  __int64 v45; // [rsp+138h] [rbp+50h]
  float v46; // [rsp+160h] [rbp+78h]
  float v47; // [rsp+168h] [rbp+80h]

  v8 = npTargetPosition;
  v9 = desiredPosition;
  v10 = this;
  if ( !this->m_pAIEntityComponent.m_pPointer )
    return 0;
  v11 = (__m128)LODWORD(UFG::qVector3::msZero.z);
  v12 = (__m128)COERCE_UNSIGNED_INT((float)testAngle);
  v12.m128_f32[0] = (float)(v12.m128_f32[0] * 3.1415927) * 0.000030517578;
  v13 = v12;
  v13.m128_f32[0] = sinf(v12.m128_f32[0]);
  v14 = v13.m128_f32[0];
  v15 = v13;
  v16 = v12;
  v16.m128_f32[0] = cosf(v12.m128_f32[0]);
  v17 = v10->m_pActionContext;
  v42 = 0;
  v18 = v16;
  v19 = v16.m128_f32[0];
  v11.m128_f32[0] = (float)(v11.m128_f32[0] * v47) + v8->m_vPosition.z;
  v15.m128_f32[0] = (float)(v15.m128_f32[0] * v47) + v8->m_vPosition.y;
  v41.m_hkvMeshPosition.m_quad.m128_u64[1] = (unsigned __int64)&UFG::HavokNavPosition::`vftable;
  v44 = -1i64;
  v18.m128_f32[0] = (float)(v16.m128_f32[0] * v47) + v8->m_vPosition.x;
  *(&v41.m_aiMeshUid + 1) = v11.m128_i32[0];
  v41.m_aiMeshUid = v15.m128_i32[0];
  v41.m_packedKey = v18.m128_i32[0];
  v43 = _mm_unpacklo_ps(_mm_unpacklo_ps(v18, v11), _mm_unpacklo_ps(v15, (__m128)(unsigned int)FLOAT_1_0));
  v20 = (UFG::SimObjectGame *)v17->mSimObject.m_pPointer;
  if ( v20 )
  {
    v22 = v20->m_Flags;
    if ( (v22 >> 14) & 1 )
    {
      v21 = v20->m_Components.p[36].m_pComponent;
    }
    else
    {
      if ( (v22 & 0x8000u) == 0 )
      {
        if ( (v22 >> 13) & 1 )
        {
          v23 = UFG::SimObjectGame::GetComponentOfTypeHK(v20, UFG::NavComponent::_TypeUID);
        }
        else if ( (v22 >> 12) & 1 )
        {
          v23 = UFG::SimObjectGame::GetComponentOfTypeHK(v20, UFG::NavComponent::_TypeUID);
        }
        else
        {
          v23 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v20->vfptr, UFG::NavComponent::_TypeUID);
        }
      }
      else
      {
        v23 = UFG::SimObjectGame::GetComponentOfTypeHK(v20, UFG::NavComponent::_TypeUID);
      }
      v21 = v23;
    }
  }
  else
  {
    v21 = 0i64;
  }
  v24 = a5;
  v45 = *(__int64 *)((char *)&v21[2].m_BoundComponentHandles.mNode.mNext + 4);
  if ( UFG::NavManager::ms_pInstance->vfptr->AIRayCastHits(
         UFG::NavManager::ms_pInstance,
         (UFG::HavokNavPosition *)&v21[1].m_SafePointerList.mNode.mNext,
         (UFG::HavokNavPosition *)&v41.m_hkvMeshPosition.m_quad.m128_u16[4],
         (UFG::NavParams *)&v45,
         (UFG::qVector3 *)&v38) )
  {
    v25 = (__m128)LODWORD(v8->m_vPosition.y);
    v25.m128_f32[0] = (float)((float)((float)(v25.m128_f32[0] - v39) * (float)(v25.m128_f32[0] - v39))
                            + (float)((float)(v8->m_vPosition.x - v38) * (float)(v8->m_vPosition.x - v38)))
                    + (float)((float)(v8->m_vPosition.z - v40) * (float)(v8->m_vPosition.z - v40));
    LODWORD(v26) = (unsigned __int128)_mm_sqrt_ps(v25);
    if ( v26 > a5 )
    {
      v28 = (__m128)v41.m_aiMeshUid;
      v28.m128_f32[0] = (float)((float)((float)(*(float *)&v41.m_aiMeshUid - v39)
                                      * (float)(*(float *)&v41.m_aiMeshUid - v39))
                              + (float)((float)(*(float *)&v41.m_packedKey - v38)
                                      * (float)(*(float *)&v41.m_packedKey - v38)))
                      + (float)((float)(*((float *)&v41.m_aiMeshUid + 1) - v40)
                              * (float)(*((float *)&v41.m_aiMeshUid + 1) - v40));
      LODWORD(v29) = (unsigned __int128)_mm_sqrt_ps(v28);
      if ( v29 >= 5.0 )
        v29 = FLOAT_5_0;
      v24 = (float)(5.0 - v29) + a5;
      if ( v24 >= v47 )
        v24 = v47;
      if ( v24 < v26 )
        goto LABEL_25;
    }
    else if ( v26 < v46 )
    {
      return 0;
    }
    v24 = v26;
  }
LABEL_25:
  v30 = (float)(v14 * v24) + v8->m_vPosition.y;
  v31 = (float)(UFG::qVector3::msZero.z * v24) + v8->m_vPosition.z;
  v9->x = (float)(v19 * v24) + v8->m_vPosition.x;
  v9->y = v30;
  v9->z = v31;
  v32 = LOBYTE(v10->m_Track[1].mMasterRate.value);
  v33 = (UFG::SimObjectGame *)v10->m_pActionContext->mSimObject.m_pPointer;
  if ( v33 )
  {
    v34 = v33->m_Flags;
    if ( !((v34 >> 14) & 1) )
    {
      if ( (v34 & 0x8000u) == 0 )
      {
        if ( (v34 >> 13) & 1 )
        {
          UFG::SimObjectGame::GetComponentOfTypeHK(v33, UFG::NavComponent::_TypeUID);
        }
        else if ( (v34 >> 12) & 1 )
        {
          UFG::SimObjectGame::GetComponentOfTypeHK(v33, UFG::NavComponent::_TypeUID);
        }
        else
        {
          UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v33->vfptr, UFG::NavComponent::_TypeUID);
        }
      }
      else
      {
        UFG::SimObjectGame::GetComponentOfTypeHK(v33, UFG::NavComponent::_TypeUID);
      }
    }
  }
  if ( !v32 )
  {
    v35 = (__m128)LODWORD(v9->x);
    v36 = (__m128)LODWORD(v9->y);
    v37 = (__m128)LODWORD(v9->z);
    v41.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
    v41.m_bValid = 0;
    *(_QWORD *)&v41.m_packedKey = -1i64;
    LODWORD(v41.m_vPosition.x) = v35.m128_i32[0];
    LODWORD(v41.m_vPosition.y) = v36.m128_i32[0];
    LODWORD(v41.m_vPosition.z) = v37.m128_i32[0];
    v41.m_hkvMeshPosition.m_quad = _mm_unpacklo_ps(
                                     _mm_unpacklo_ps(v35, v37),
                                     _mm_unpacklo_ps(v36, (__m128)(unsigned int)FLOAT_1_0));
    UFG::HavokNavPosition::Validate(&v41, 1.0, 1.0, 0.0);
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
void __usercall CircleAroundCombatantsTask::UpdateDesiredPosition(CircleAroundCombatantsTask *this@<rcx>, float a2@<r14d>)
{
  UFG::SimComponent *v2; // rdi
  CircleAroundCombatantsTask *v3; // rbx
  float *v4; // rsi
  float *v5; // rax
  float minDistance; // xmm6_4
  float maxDistance; // xmm7_4
  float desiredDistance; // xmm8_4
  UFG::SimObjectGame *v9; // r8
  hkVector4f *v10; // rcx
  unsigned __int16 v11; // cx
  UFG::SimComponent *v12; // rax
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  unsigned __int16 v17; // r9
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  __int16 v21; // si
  unsigned __int16 v22; // si
  float v23; // xmm1_4
  float v24; // xmm0_4
  float v25; // xmm0_4
  signed int v26; // eax
  bool v27; // zf
  float v28; // xmm0_4
  float v29; // xmm1_4
  UFG::qVector3 desiredPosition; // [rsp+38h] [rbp-29h]
  UFG::HavokNavPosition npTargetPosition; // [rsp+48h] [rbp-19h]

  v2 = this->m_pTransformNodeComponent.m_pPointer;
  LOBYTE(a2) = 0;
  v3 = this;
  if ( !v2 || !this->m_pTargetTransformNodeComponent.m_pPointer )
    return;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v2);
  v4 = (float *)v3->m_pTargetTransformNodeComponent.m_pPointer;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v3->m_pTargetTransformNodeComponent.m_pPointer);
  v5 = (float *)v3->m_Track;
  minDistance = v5[15];
  maxDistance = v5[16];
  desiredDistance = v5[17];
  v9 = (UFG::SimObjectGame *)v3->m_pTargetTransformNodeComponent.m_pPointer->m_pSimObject;
  if ( v9 )
  {
    v11 = v9->m_Flags;
    if ( (v11 >> 14) & 1 )
    {
      v10 = (hkVector4f *)v9->m_Components.p[36].m_pComponent;
    }
    else
    {
      if ( (v11 & 0x8000u) == 0 )
      {
        if ( (v11 >> 13) & 1 )
        {
          v12 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::NavComponent::_TypeUID);
        }
        else if ( (v11 >> 12) & 1 )
        {
          v12 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::NavComponent::_TypeUID);
        }
        else
        {
          v12 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v9->vfptr, UFG::NavComponent::_TypeUID);
        }
      }
      else
      {
        v12 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::NavComponent::_TypeUID);
      }
      v10 = (hkVector4f *)v12;
    }
  }
  else
  {
    v10 = 0i64;
  }
  npTargetPosition.m_bValid = 0;
  *(_QWORD *)&npTargetPosition.m_packedKey = -1i64;
  npTargetPosition.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
  npTargetPosition.m_vPosition = UFG::qVector3::msZero;
  npTargetPosition.m_hkvMeshPosition = (hkVector4f)hkvZero_13.m_quad;
  if ( !v10 )
  {
    v15 = v4[45];
    v16 = v4[46];
    npTargetPosition.m_vPosition.x = v4[44];
    npTargetPosition.m_vPosition.y = v15;
    npTargetPosition.m_vPosition.z = v16;
    goto LABEL_19;
  }
  v13 = v10[5].m_quad.m128_f32[3];
  v14 = v10[6].m_quad.m128_f32[0];
  npTargetPosition.m_vPosition.x = v10[5].m_quad.m128_f32[2];
  npTargetPosition.m_vPosition.y = v13;
  npTargetPosition.m_vPosition.z = v14;
  if ( !v10[6].m_quad.m128_i8[8] )
  {
LABEL_19:
    npTargetPosition.m_bValid = 0;
    goto LABEL_20;
  }
  npTargetPosition.m_bValid = v10[6].m_quad.m128_i8[8];
  npTargetPosition.m_hkvMeshPosition = (hkVector4f)v10[7].m_quad;
  npTargetPosition.m_packedKey = v10[8].m_quad.m128_u32[0];
  npTargetPosition.m_aiMeshUid = v10[8].m_quad.m128_u32[1];
LABEL_20:
  UFG::HavokNavPosition::Validate(&npTargetPosition, 1.0, 1.0, 0.0);
  v17 = v3->m_DesiredAngle;
  desiredPosition = UFG::qVector3::msZero;
  if ( CircleAroundCombatantsTask::ComputeDesiredPosition(
         v3,
         &desiredPosition,
         &npTargetPosition,
         v17,
         a2,
         desiredDistance,
         minDistance,
         maxDistance) )
  {
    v18 = desiredPosition.x;
    v3->m_LastTimeFoundValidPosition = UFG::Metrics::msInstance.mSimTime_Temp;
    v19 = desiredPosition.y;
    v3->m_DesiredPosition.x = v18;
    v20 = desiredPosition.z;
    v3->m_DesiredPosition.y = v19;
    v3->m_DesiredPosition.z = v20;
    v3->m_DesiredPositionValid = 1;
LABEL_29:
    v3->m_LastTimeFoundValidPosition = UFG::Metrics::msInstance.mSimTime_Temp;
    return;
  }
  v21 = LOWORD(v3->m_TestAngleIndex) + 1;
  desiredPosition = UFG::qVector3::msZero;
  v22 = v3->m_DesiredAngle + 1228 * v21;
  if ( CircleAroundCombatantsTask::ComputeDesiredPosition(
         v3,
         &desiredPosition,
         &npTargetPosition,
         v22,
         a2,
         desiredDistance,
         minDistance,
         maxDistance) )
  {
    v23 = desiredPosition.y;
    v3->m_TestAngleIndex = 0;
    v24 = UFG::Metrics::msInstance.mSimTime_Temp;
    v3->m_DesiredAngle = v22;
    LOBYTE(a2) = 1;
    v3->m_LastTimeFoundValidPosition = v24;
    v25 = desiredPosition.x;
    v3->m_DesiredPosition.y = v23;
    v3->m_DesiredPosition.x = v25;
    v3->m_DesiredPosition.z = desiredPosition.z;
    v3->m_DesiredPositionValid = 1;
  }
  v26 = ++v3->m_TestAngleIndex;
  if ( v26 >= 10 )
    v26 = -10;
  v27 = v3->m_DesiredPositionValid == 0;
  v3->m_TestAngleIndex = v26;
  if ( v27 )
  {
    v28 = *((float *)&v2[2].m_BoundComponentHandles.mNode.mPrev + 1);
    v29 = *(float *)&v2[2].m_BoundComponentHandles.mNode.mNext;
    v3->m_DesiredPosition.x = *(float *)&v2[2].m_BoundComponentHandles.mNode.mPrev;
    v3->m_DesiredPosition.y = v28;
    v3->m_DesiredPosition.z = v29;
    v3->m_DesiredPositionValid = 1;
  }
  if ( LOBYTE(a2) )
    goto LABEL_29;
}

// File Line: 4735
// RVA: 0x38D540
char __fastcall CircleAroundCombatantsTask::Update(CircleAroundCombatantsTask *this, float timestep)
{
  CircleAroundCombatantsTask *v2; // rdi
  UFG::SimComponent *v3; // rcx
  float v4; // xmm12_4
  UFG::SimObject *v5; // rdx
  UFG::TransformNodeComponent *v6; // r15
  float *v7; // rbx
  float *v8; // rax
  bool v9; // cl
  float v10; // xmm3_4
  float v11; // xmm2_4
  __m128 v12; // xmm4
  float v13; // xmm15_4
  bool v14; // r14
  UFG::NavComponent *v15; // rsi
  __m128 v16; // xmm0
  float v17; // xmm11_4
  float v18; // xmm9_4
  __m128 v19; // xmm10
  float v20; // xmm6_4
  __m128 v21; // xmm0
  float v22; // xmm2_4
  float v23; // xmm3_4
  float v24; // xmm0_4
  float v25; // xmm1_4
  float v26; // xmm1_4
  UFG::qColour *v27; // rbx
  UFG::qColour *v28; // rax
  Render::DebugDrawContext *v29; // rax
  float v30; // xmm1_4
  float v31; // xmm0_4
  Render::DebugDrawContext *v32; // rax
  float v33; // xmm0_4
  float v34; // xmm0_4
  float v35; // xmm6_4
  float v36; // xmm0_4
  UFG::SimObjectGame *v37; // rcx
  unsigned __int16 v38; // dx
  UFG::SimComponent *v39; // rax
  float v40; // xmm0_4
  float v41; // xmm0_4
  __m128 v42; // xmm0
  __m128 v43; // xmm3
  __m128 v44; // xmm2
  ITrack *v45; // rax
  __int64 v46; // rcx
  unsigned int v47; // esi
  UFG::SimObjectCVBase *v48; // rcx
  unsigned __int16 v49; // dx
  UFG::AICharacterControllerBaseComponent *v50; // rax
  float *v51; // rbx
  __m128 v52; // xmm2
  float v53; // xmm7_4
  UFG::qVector3 point; // [rsp+40h] [rbp-C0h]
  UFG::qColour colour; // [rsp+50h] [rbp-B0h]
  UFG::qColour v57; // [rsp+60h] [rbp-A0h]
  UFG::HavokNavPosition npDestination; // [rsp+70h] [rbp-90h]
  float fDestinationTolerance; // [rsp+180h] [rbp+80h]

  v2 = this;
  v3 = this->m_pTargetingSystemBaseComponent.m_pPointer;
  v4 = timestep;
  if ( v3 )
  {
    v5 = *(UFG::SimObject **)(56i64
                            * *(unsigned __int8 *)(LOBYTE(v2->m_Track[1].vfptr) + *(_QWORD *)&v3[1].m_Flags + 8i64)
                            + *(_QWORD *)&v3[1].m_TypeUID
                            + 40);
    if ( v5 != v2->m_pTargetSimObject.m_pPointer )
      CircleAroundCombatantsTask::SetMyTarget(v2, v5);
  }
  v6 = (UFG::TransformNodeComponent *)v2->m_pTransformNodeComponent.m_pPointer;
  if ( !v6 || !v2->m_pTargetTransformNodeComponent.m_pPointer || !v2->m_pAIEntityComponent.m_pPointer )
    return 0;
  UFG::TransformNodeComponent::UpdateWorldTransform(v6);
  v7 = (float *)v2->m_pTargetTransformNodeComponent.m_pPointer;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v2->m_pTargetTransformNodeComponent.m_pPointer);
  v8 = (float *)v2->m_Track;
  v9 = v2->m_DesiredPositionValid;
  v10 = v7[44];
  v11 = v7[45];
  v12 = (__m128)LODWORD(v6->mWorldTransform.v3.y);
  v13 = v2->m_DesiredPosition.y;
  v14 = v9 == 0;
  v15 = 0i64;
  v16 = v12;
  v19 = (__m128)LODWORD(v6->mWorldTransform.v3.y);
  v17 = v6->mWorldTransform.v3.z - v7[46];
  v18 = v6->mWorldTransform.v3.x - v10;
  v16.m128_f32[0] = (float)((float)(v12.m128_f32[0] - v11) * (float)(v12.m128_f32[0] - v11)) + (float)(v18 * v18);
  v19.m128_f32[0] = v19.m128_f32[0] - v11;
  LODWORD(v20) = (unsigned __int128)_mm_sqrt_ps(v16);
  v21 = (__m128)LODWORD(v2->m_DesiredPosition.y);
  v21.m128_f32[0] = v21.m128_f32[0] - v11;
  v22 = v8[16];
  v21.m128_f32[0] = (float)(v21.m128_f32[0] * v21.m128_f32[0])
                  + (float)((float)(v2->m_DesiredPosition.x - v10) * (float)(v2->m_DesiredPosition.x - v10));
  LODWORD(v23) = (unsigned __int128)_mm_sqrt_ps(v21);
  v24 = v8[15];
  fDestinationTolerance = v8[19];
  if ( v2->m_CurrentlyMoving )
  {
    if ( v23 > v24 )
      v24 = v23;
    if ( v24 >= v22 )
      v24 = v8[16];
    if ( v23 != v24 && UFG::Metrics::msInstance.mSimTime_Temp > (float)(v2->m_LastTimeFoundValidPosition + 0.5) )
    {
      v14 = 1;
      goto LABEL_33;
    }
LABEL_23:
    if ( v9 )
    {
      v26 = v2->m_DesiredPosition.z;
      v14 = 0;
      if ( (float)((float)((float)((float)(v12.m128_f32[0] - v13) * v19.m128_f32[0])
                         + (float)((float)(v6->mWorldTransform.v3.x - v2->m_DesiredPosition.x) * v18))
                 + (float)((float)(v6->mWorldTransform.v3.z - v26) * v17)) >= 0.0 )
        v14 = 1;
      if ( CircleAroundCombatantsTask::gDrawCircleAroundCombatant && v9 )
      {
        v27 = &UFG::qColour::Red;
        point.x = v2->m_DesiredPosition.x;
        point.y = v13;
        point.z = v26 + 0.1;
        v28 = &UFG::qColour::Red;
        if ( !v14 )
          v28 = &UFG::qColour::Green;
        colour = *v28;
        v29 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
        Render::DebugDrawContext::DrawPoint(v29, &point, &colour, &UFG::qMatrix44::msIdentity, 0i64);
        colour.r = v6->mWorldTransform.v3.x;
        if ( !v14 )
          v27 = &UFG::qColour::Green;
        point.x = v2->m_DesiredPosition.x;
        v30 = v6->mWorldTransform.v3.z + 0.1;
        v57 = *v27;
        v31 = v6->mWorldTransform.v3.y;
        colour.b = v30;
        colour.g = v31;
        point.y = v2->m_DesiredPosition.y;
        point.z = v2->m_DesiredPosition.z + 0.1;
        v32 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
        Render::DebugDrawContext::DrawLine(
          v32,
          (UFG::qVector3 *)&colour,
          &point,
          &v57,
          &UFG::qMatrix44::msIdentity,
          (void (__fastcall *)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *))Render::gXRayDrawCallback,
          0);
      }
    }
    goto LABEL_33;
  }
  if ( v20 <= v24 )
    v25 = v8[15];
  else
    v25 = v20;
  if ( v25 >= v22 )
    v25 = v8[16];
  if ( v20 == v25 )
    goto LABEL_23;
  v2->m_CurrentlyMoving = 1;
  v14 = 1;
LABEL_33:
  v33 = v2->m_LastTimeSinceStopped;
  if ( v33 > 0.0 )
  {
    v34 = v33 - v4;
    if ( v34 <= 0.0 )
      v34 = 0.0;
    v2->m_LastTimeSinceStopped = v34;
  }
  if ( v2->m_CurrentlyMoving && v20 > 0.1 || !v2->m_DesiredPositionValid )
  {
    if ( v14 )
    {
      v35 = UFG::Metrics::msInstance.mSimTime_Temp;
      v36 = atan2f(v19.m128_f32[0], v18);
      v2->m_LastTimeFoundValidPosition = v35;
      v2->m_DesiredAngle = (signed int)(float)((float)(v36 * 32768.0) * 0.31830987);
      CircleAroundCombatantsTask::UpdateDesiredPosition(v2);
    }
    v37 = (UFG::SimObjectGame *)v2->m_pActionContext->mSimObject.m_pPointer;
    if ( v37 )
    {
      v38 = v37->m_Flags;
      if ( (v38 >> 14) & 1 )
      {
        v15 = (UFG::NavComponent *)v37->m_Components.p[36].m_pComponent;
      }
      else
      {
        if ( (v38 & 0x8000u) == 0 )
        {
          if ( (v38 >> 13) & 1 )
          {
            v39 = UFG::SimObjectGame::GetComponentOfTypeHK(v37, UFG::NavComponent::_TypeUID);
          }
          else if ( (v38 >> 12) & 1 )
          {
            v39 = UFG::SimObjectGame::GetComponentOfTypeHK(v37, UFG::NavComponent::_TypeUID);
          }
          else
          {
            v39 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v37->vfptr, UFG::NavComponent::_TypeUID);
          }
        }
        else
        {
          v39 = UFG::SimObjectGame::GetComponentOfTypeHK(v37, UFG::NavComponent::_TypeUID);
        }
        v15 = (UFG::NavComponent *)v39;
      }
    }
    v40 = v2->m_LastTimeSinceStopped;
    if ( v40 <= 0.0 )
    {
      v42 = (__m128)LODWORD(v2->m_DesiredPosition.z);
      v43 = (__m128)LODWORD(v2->m_DesiredPosition.x);
      v44 = (__m128)LODWORD(v2->m_DesiredPosition.y);
      npDestination.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
      v45 = v2->m_Track;
      npDestination.m_bValid = 0;
      LODWORD(npDestination.m_vPosition.x) = v43.m128_i32[0];
      LODWORD(npDestination.m_vPosition.y) = v44.m128_i32[0];
      LODWORD(npDestination.m_vPosition.z) = v42.m128_i32[0];
      v46 = BYTE1(v45[1].mMasterRate.text.mOffset);
      *(_QWORD *)&npDestination.m_packedKey = -1i64;
      npDestination.m_hkvMeshPosition.m_quad = _mm_unpacklo_ps(
                                                 _mm_unpacklo_ps(v43, v42),
                                                 _mm_unpacklo_ps(v44, (__m128)(unsigned int)FLOAT_1_0));
      UFG::NavComponent::AddGoalPoint(v15, &npDestination, 0, sNaturalMovementSpeeds[v46], fDestinationTolerance);
    }
    else
    {
      v41 = v40 - v4;
      if ( v41 <= 0.0 )
        v41 = 0.0;
      v2->m_LastTimeSinceStopped = v41;
    }
    if ( (unsigned __int8)UFG::NavComponent::IsAtDestination(v15) )
      v2->m_CurrentlyMoving = 0;
  }
  if ( !v2->m_CurrentlyMoving )
  {
    if ( v2->m_LastTimeSinceStopped <= 0.0 )
      v2->m_LastTimeSinceStopped = 2.0;
    v47 = HIDWORD(v2->m_Track[1].mMasterRate.expression.mOffset);
    if ( v47 != gActionRequest_INVALID.m_EnumValue )
    {
      v48 = (UFG::SimObjectCVBase *)v2->m_pActionContext->mSimObject.m_pPointer;
      if ( v48 )
      {
        v49 = v48->m_Flags;
        if ( (v49 >> 14) & 1 )
        {
          v50 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v48);
        }
        else if ( (v49 & 0x8000u) == 0 )
        {
          if ( (v49 >> 13) & 1 )
            v50 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               (UFG::SimObjectGame *)&v48->vfptr,
                                                               UFG::AICharacterControllerBaseComponent::_TypeUID);
          else
            v50 = (UFG::AICharacterControllerBaseComponent *)((v49 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                                  (UFG::SimObjectGame *)&v48->vfptr,
                                                                                  UFG::AICharacterControllerBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v48->vfptr, UFG::AICharacterControllerBaseComponent::_TypeUID));
        }
        else
        {
          v50 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v48);
        }
        if ( v50 )
        {
          v51 = &v50->m_Intention.mMotionIntentionSpeedRaw;
          Intention::Set(&v50->m_Intention, v47, 0.0);
          v52 = v19;
          v52.m128_f32[0] = (float)((float)(v19.m128_f32[0] * v19.m128_f32[0]) + (float)(v18 * v18))
                          + (float)(v17 * v17);
          if ( v52.m128_f32[0] == 0.0 )
            v53 = 0.0;
          else
            v53 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v52));
          v51[7] = v53 * v17;
          v51[5] = v53 * v18;
          v51[6] = v53 * v19.m128_f32[0];
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
  UFG::qNode<ITask,ITask> *v1; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *v5; // [rsp+28h] [rbp+10h]
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v6; // [rsp+28h] [rbp+10h]

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<AITargetingParametersTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&AITargetingParametersTask::`vftable;
  v2 = &this->m_pAIEntityComponent;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  this->m_pAIEntityComponent.m_pPointer = 0i64;
  v5 = &this->m_pTargetingSystemBaseComponent;
  v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v5->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  this->m_pTargetingSystemBaseComponent.m_pPointer = 0i64;
  v6 = &this->m_pTargetTransformNodeComponent;
  v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  v6->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  this->m_pTargetTransformNodeComponent.m_pPointer = 0i64;
  this->m_pActionContext = 0i64;
  if ( this->m_pAIEntityComponent.m_pPointer )
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

// File Line: 4909
// RVA: 0x334AF0
void __fastcall AITargetingParametersTask::~AITargetingParametersTask(AITargetingParametersTask *this)
{
  AITargetingParametersTask *v1; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v12; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qNode<ITask,ITask> *v17; // rdx
  UFG::qNode<ITask,ITask> *v18; // rcx
  UFG::qNode<ITask,ITask> *v19; // rax

  v1 = this;
  this->vfptr = (ITaskVtbl *)&AITargetingParametersTask::`vftable;
  v2 = &this->m_pTargetTransformNodeComponent;
  if ( this->m_pTargetTransformNodeComponent.m_pPointer )
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
  v7 = &v1->m_pTargetingSystemBaseComponent;
  if ( v1->m_pTargetingSystemBaseComponent.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v1->m_pTargetingSystemBaseComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v1->m_pTargetingSystemBaseComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pTargetingSystemBaseComponent.mPrev;
  }
  v1->m_pTargetingSystemBaseComponent.m_pPointer = 0i64;
  v10 = v7->mPrev;
  v11 = v1->m_pTargetingSystemBaseComponent.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v1->m_pTargetingSystemBaseComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pTargetingSystemBaseComponent.mPrev;
  v12 = &v1->m_pAIEntityComponent;
  if ( v1->m_pAIEntityComponent.m_pPointer )
  {
    v13 = v12->mPrev;
    v14 = v1->m_pAIEntityComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v12->mPrev;
    v1->m_pAIEntityComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pAIEntityComponent.mPrev;
  }
  v1->m_pAIEntityComponent.m_pPointer = 0i64;
  v15 = v12->mPrev;
  v16 = v1->m_pAIEntityComponent.mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v12->mPrev;
  v1->m_pAIEntityComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pAIEntityComponent.mPrev;
  v1->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v17 = (UFG::qNode<ITask,ITask> *)&v1->mPrev;
  v18 = v1->mPrev;
  v19 = v1->mNext;
  v18->mNext = v19;
  v19->mPrev = v18;
  v17->mPrev = v17;
  v17->mNext = v17;
}

// File Line: 4914
// RVA: 0x343970
void __fastcall AITargetingParametersTask::Begin(AITargetingParametersTask *this, ActionContext *action_context)
{
  AITargetingParametersTask *v2; // rbx
  UFG::SimObjectCVBase *v3; // rcx
  UFG::ActiveAIEntityComponent *v4; // r8
  unsigned __int16 v5; // dx
  UFG::ActiveAIEntityComponent *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::SimComponent *v11; // rcx
  ITrack *v12; // rax
  int v13; // xmm0_4
  int v14; // xmm1_4

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
        v6 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v3);
      }
      else if ( (v5 & 0x8000u) == 0 )
      {
        if ( (v5 >> 13) & 1 )
        {
          v6 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)&v3->vfptr,
                                                 UFG::ActiveAIEntityComponent::_TypeUID);
        }
        else if ( (v5 >> 12) & 1 )
        {
          v6 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)&v3->vfptr,
                                                 UFG::ActiveAIEntityComponent::_TypeUID);
        }
        else
        {
          v6 = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                 (UFG::SimObject *)&v3->vfptr,
                                                 UFG::ActiveAIEntityComponent::_TypeUID);
        }
      }
      else
      {
        v6 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v3);
      }
      v4 = v6;
    }
    else
    {
      v4 = 0i64;
    }
    v7 = &v2->m_pAIEntityComponent;
    if ( v2->m_pAIEntityComponent.m_pPointer )
    {
      v8 = v7->mPrev;
      v9 = v2->m_pAIEntityComponent.mNext;
      v8->mNext = v9;
      v9->mPrev = v8;
      v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
      v2->m_pAIEntityComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pAIEntityComponent.mPrev;
    }
    v2->m_pAIEntityComponent.m_pPointer = (UFG::SimComponent *)&v4->vfptr;
    if ( v4 )
    {
      v10 = v4->m_SafePointerList.mNode.mPrev;
      v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
      v7->mPrev = v10;
      v2->m_pAIEntityComponent.mNext = &v4->m_SafePointerList.mNode;
      v4->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    }
  }
  v11 = v2->m_pAIEntityComponent.m_pPointer;
  if ( v11 )
  {
    v12 = v2->m_Track;
    v13 = HIDWORD(v12[1].vfptr);
    v14 = (int)v12[1].mResourceOwner;
    HIDWORD(v11[65].m_SafePointerList.mNode.mPrev) = LOBYTE(v12[1].vfptr);
    LODWORD(v11[65].m_SafePointerList.mNode.mNext) = v13;
    HIDWORD(v11[65].m_SafePointerList.mNode.mNext) = v14;
  }
}

// File Line: 4947
// RVA: 0x354DE0
void __fastcall AITargetingParametersTask::End(AITargetingParametersTask *this)
{
  UFG::SimComponent *v1; // rax

  v1 = this->m_pAIEntityComponent.m_pPointer;
  if ( v1 )
  {
    *(UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **)((char *)&v1[65].m_SafePointerList.mNode.mPrev
                                                                                       + 4) = 0i64;
    HIDWORD(v1[65].m_SafePointerList.mNode.mNext) = 0;
  }
}

// File Line: 4963
// RVA: 0x32A810
void __fastcall AIAddSupplementaryAttackTargetTask::AIAddSupplementaryAttackTargetTask(AIAddSupplementaryAttackTargetTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v2; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *v3; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<AIAddSupplementaryAttackTargetTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&AIAddSupplementaryAttackTargetTask::`vftable;
  v2 = &this->m_pAIEntityComponent;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  this->m_pAIEntityComponent.m_pPointer = 0i64;
  v3 = &this->m_pTargetingSystemBaseComponent;
  v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  this->m_pTargetingSystemBaseComponent.m_pPointer = 0i64;
  this->m_pActionContext = 0i64;
  if ( this->m_pAIEntityComponent.m_pPointer )
  {
    v4 = v2->mPrev;
    v5 = v2->mNext;
    v4->mNext = v5;
    v5->mPrev = v4;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  }
  v2->m_pPointer = 0i64;
  if ( v3->m_pPointer )
  {
    v6 = v3->mPrev;
    v7 = v3->mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
    v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  }
  v3->m_pPointer = 0i64;
}

// File Line: 4972
// RVA: 0x333960
void __fastcall AIAddSupplementaryAttackTargetTask::~AIAddSupplementaryAttackTargetTask(AIAddSupplementaryAttackTargetTask *this)
{
  AIAddSupplementaryAttackTargetTask *v1; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<ITask,ITask> *v12; // rdx
  UFG::qNode<ITask,ITask> *v13; // rcx
  UFG::qNode<ITask,ITask> *v14; // rax

  v1 = this;
  this->vfptr = (ITaskVtbl *)&AIAddSupplementaryAttackTargetTask::`vftable;
  v2 = &this->m_pTargetingSystemBaseComponent;
  if ( this->m_pTargetingSystemBaseComponent.m_pPointer )
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
  v7 = &v1->m_pAIEntityComponent;
  if ( v1->m_pAIEntityComponent.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v1->m_pAIEntityComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v1->m_pAIEntityComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pAIEntityComponent.mPrev;
  }
  v1->m_pAIEntityComponent.m_pPointer = 0i64;
  v10 = v7->mPrev;
  v11 = v1->m_pAIEntityComponent.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v1->m_pAIEntityComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pAIEntityComponent.mPrev;
  v1->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v12 = (UFG::qNode<ITask,ITask> *)&v1->mPrev;
  v13 = v1->mPrev;
  v14 = v1->mNext;
  v13->mNext = v14;
  v14->mPrev = v13;
  v12->mPrev = v12;
  v12->mNext = v12;
}

// File Line: 4977
// RVA: 0x3428F0
void __fastcall AIAddSupplementaryAttackTargetTask::Begin(AIAddSupplementaryAttackTargetTask *this, ActionContext *action_context)
{
  AIAddSupplementaryAttackTargetTask *v2; // rdi
  UFG::SimObjectCVBase *v3; // rcx
  UFG::SimComponent *v4; // rbx
  UFG::ActiveAIEntityComponent *v5; // r8
  unsigned __int16 v6; // dx
  UFG::ActiveAIEntityComponent *v7; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v8; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::SimObjectGame *v12; // rcx
  unsigned __int16 v13; // dx
  UFG::SimComponent *v14; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *v15; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rax
  UFG::SimComponent *v19; // r8
  UFG::SimObjectGame *v20; // rbx
  unsigned __int16 v21; // cx
  UFG::SimComponent *v22; // rax

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
        v7 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v3);
      }
      else if ( (v6 & 0x8000u) == 0 )
      {
        if ( (v6 >> 13) & 1 )
        {
          v7 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)&v3->vfptr,
                                                 UFG::ActiveAIEntityComponent::_TypeUID);
        }
        else if ( (v6 >> 12) & 1 )
        {
          v7 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)&v3->vfptr,
                                                 UFG::ActiveAIEntityComponent::_TypeUID);
        }
        else
        {
          v7 = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                 (UFG::SimObject *)&v3->vfptr,
                                                 UFG::ActiveAIEntityComponent::_TypeUID);
        }
      }
      else
      {
        v7 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v3);
      }
      v5 = v7;
    }
    else
    {
      v5 = 0i64;
    }
    v8 = &v2->m_pAIEntityComponent;
    if ( v2->m_pAIEntityComponent.m_pPointer )
    {
      v9 = v8->mPrev;
      v10 = v2->m_pAIEntityComponent.mNext;
      v9->mNext = v10;
      v10->mPrev = v9;
      v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
      v2->m_pAIEntityComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pAIEntityComponent.mPrev;
    }
    v2->m_pAIEntityComponent.m_pPointer = (UFG::SimComponent *)&v5->vfptr;
    if ( v5 )
    {
      v11 = v5->m_SafePointerList.mNode.mPrev;
      v11->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
      v8->mPrev = v11;
      v2->m_pAIEntityComponent.mNext = &v5->m_SafePointerList.mNode;
      v5->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
    }
    v12 = (UFG::SimObjectGame *)v2->m_pActionContext->mSimObject.m_pPointer;
    if ( v12 )
    {
      v13 = v12->m_Flags;
      if ( (v13 >> 14) & 1 )
      {
        v4 = v12->m_Components.p[20].m_pComponent;
      }
      else if ( (v13 & 0x8000u) == 0 )
      {
        if ( (v13 >> 13) & 1 )
        {
          v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        else if ( (v13 >> 12) & 1 )
        {
          v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        else
        {
          v14 = UFG::SimObject::GetComponentOfType(
                  (UFG::SimObject *)&v12->vfptr,
                  UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        v4 = v14;
      }
      else
      {
        v4 = v12->m_Components.p[20].m_pComponent;
      }
    }
    v15 = &v2->m_pTargetingSystemBaseComponent;
    if ( v2->m_pTargetingSystemBaseComponent.m_pPointer )
    {
      v16 = v15->mPrev;
      v17 = v2->m_pTargetingSystemBaseComponent.mNext;
      v16->mNext = v17;
      v17->mPrev = v16;
      v15->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v15->mPrev;
      v2->m_pTargetingSystemBaseComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pTargetingSystemBaseComponent.mPrev;
    }
    v2->m_pTargetingSystemBaseComponent.m_pPointer = v4;
    if ( v4 )
    {
      v18 = v4->m_SafePointerList.mNode.mPrev;
      v18->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v15->mPrev;
      v15->mPrev = v18;
      v2->m_pTargetingSystemBaseComponent.mNext = &v4->m_SafePointerList.mNode;
      v4->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v15->mPrev;
    }
  }
  if ( v2->m_pAIEntityComponent.m_pPointer )
  {
    v19 = v2->m_pTargetingSystemBaseComponent.m_pPointer;
    if ( v19 )
    {
      v20 = *(UFG::SimObjectGame **)(56i64
                                   * *(unsigned __int8 *)(LOBYTE(v2->m_Track[1].vfptr)
                                                        + *(_QWORD *)&v19[1].m_Flags
                                                        + 8i64)
                                   + *(_QWORD *)&v19[1].m_TypeUID
                                   + 40);
      if ( v20 )
      {
        v21 = v20->m_Flags;
        if ( (v21 >> 14) & 1 )
        {
          v22 = v20->m_Components.p[46].m_pComponent;
        }
        else if ( (v21 & 0x8000u) == 0 )
        {
          if ( (v21 >> 13) & 1 )
          {
            v22 = UFG::SimObjectGame::GetComponentOfTypeHK(v20, UFG::AttackRightsComponent::_TypeUID);
          }
          else if ( (v21 >> 12) & 1 )
          {
            v22 = UFG::SimObjectGame::GetComponentOfTypeHK(v20, UFG::AttackRightsComponent::_TypeUID);
          }
          else
          {
            v22 = UFG::SimObject::GetComponentOfType(
                    (UFG::SimObject *)&v20->vfptr,
                    UFG::AttackRightsComponent::_TypeUID);
          }
        }
        else
        {
          v22 = UFG::SimObjectGame::GetComponentOfTypeHK(v20, UFG::AttackRightsComponent::_TypeUID);
        }
        if ( v22 )
          UFG::ActiveAIEntityComponent::AddSupplementaryAttackTarget(
            (UFG::ActiveAIEntityComponent *)v2->m_pAIEntityComponent.m_pPointer,
            (UFG::SimObject *)&v20->vfptr);
      }
    }
  }
}

// File Line: 5028
// RVA: 0x32BC30
void __fastcall AIRemoveSupplementaryAttackTargetTask::AIRemoveSupplementaryAttackTargetTask(AIRemoveSupplementaryAttackTargetTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v2; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *v3; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<AIRemoveSupplementaryAttackTargetTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&AIRemoveSupplementaryAttackTargetTask::`vftable;
  v2 = &this->m_pAIEntityComponent;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  this->m_pAIEntityComponent.m_pPointer = 0i64;
  v3 = &this->m_pTargetingSystemBaseComponent;
  v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  this->m_pTargetingSystemBaseComponent.m_pPointer = 0i64;
  this->m_pActionContext = 0i64;
  if ( this->m_pAIEntityComponent.m_pPointer )
  {
    v4 = v2->mPrev;
    v5 = v2->mNext;
    v4->mNext = v5;
    v5->mPrev = v4;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  }
  v2->m_pPointer = 0i64;
  if ( v3->m_pPointer )
  {
    v6 = v3->mPrev;
    v7 = v3->mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
    v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  }
  v3->m_pPointer = 0i64;
}

// File Line: 5037
// RVA: 0x3348D0
void __fastcall AIRemoveSupplementaryAttackTargetTask::~AIRemoveSupplementaryAttackTargetTask(AIRemoveSupplementaryAttackTargetTask *this)
{
  AIRemoveSupplementaryAttackTargetTask *v1; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<ITask,ITask> *v12; // rdx
  UFG::qNode<ITask,ITask> *v13; // rcx
  UFG::qNode<ITask,ITask> *v14; // rax

  v1 = this;
  this->vfptr = (ITaskVtbl *)&AIRemoveSupplementaryAttackTargetTask::`vftable;
  v2 = &this->m_pTargetingSystemBaseComponent;
  if ( this->m_pTargetingSystemBaseComponent.m_pPointer )
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
  v7 = &v1->m_pAIEntityComponent;
  if ( v1->m_pAIEntityComponent.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v1->m_pAIEntityComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v1->m_pAIEntityComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pAIEntityComponent.mPrev;
  }
  v1->m_pAIEntityComponent.m_pPointer = 0i64;
  v10 = v7->mPrev;
  v11 = v1->m_pAIEntityComponent.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v1->m_pAIEntityComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pAIEntityComponent.mPrev;
  v1->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v12 = (UFG::qNode<ITask,ITask> *)&v1->mPrev;
  v13 = v1->mPrev;
  v14 = v1->mNext;
  v13->mNext = v14;
  v14->mPrev = v13;
  v12->mPrev = v12;
  v12->mNext = v12;
}

// File Line: 5042
// RVA: 0x3437A0
void __fastcall AIRemoveSupplementaryAttackTargetTask::Begin(AIRemoveSupplementaryAttackTargetTask *this, ActionContext *action_context)
{
  AIRemoveSupplementaryAttackTargetTask *v2; // rdi
  UFG::SimObjectCVBase *v3; // rcx
  UFG::SimComponent *v4; // rbx
  UFG::ActiveAIEntityComponent *v5; // r8
  unsigned __int16 v6; // dx
  UFG::ActiveAIEntityComponent *v7; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v8; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::SimObjectGame *v12; // rcx
  unsigned __int16 v13; // dx
  UFG::SimComponent *v14; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *v15; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rax
  UFG::ActiveAIEntityComponent *v19; // rcx
  UFG::SimComponent *v20; // r9

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
        v7 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v3);
      }
      else if ( (v6 & 0x8000u) == 0 )
      {
        if ( (v6 >> 13) & 1 )
        {
          v7 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)&v3->vfptr,
                                                 UFG::ActiveAIEntityComponent::_TypeUID);
        }
        else if ( (v6 >> 12) & 1 )
        {
          v7 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)&v3->vfptr,
                                                 UFG::ActiveAIEntityComponent::_TypeUID);
        }
        else
        {
          v7 = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                 (UFG::SimObject *)&v3->vfptr,
                                                 UFG::ActiveAIEntityComponent::_TypeUID);
        }
      }
      else
      {
        v7 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v3);
      }
      v5 = v7;
    }
    else
    {
      v5 = 0i64;
    }
    v8 = &v2->m_pAIEntityComponent;
    if ( v2->m_pAIEntityComponent.m_pPointer )
    {
      v9 = v8->mPrev;
      v10 = v2->m_pAIEntityComponent.mNext;
      v9->mNext = v10;
      v10->mPrev = v9;
      v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
      v2->m_pAIEntityComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pAIEntityComponent.mPrev;
    }
    v2->m_pAIEntityComponent.m_pPointer = (UFG::SimComponent *)&v5->vfptr;
    if ( v5 )
    {
      v11 = v5->m_SafePointerList.mNode.mPrev;
      v11->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
      v8->mPrev = v11;
      v2->m_pAIEntityComponent.mNext = &v5->m_SafePointerList.mNode;
      v5->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
    }
    v12 = (UFG::SimObjectGame *)v2->m_pActionContext->mSimObject.m_pPointer;
    if ( v12 )
    {
      v13 = v12->m_Flags;
      if ( (v13 >> 14) & 1 )
      {
        v4 = v12->m_Components.p[20].m_pComponent;
      }
      else if ( (v13 & 0x8000u) == 0 )
      {
        if ( (v13 >> 13) & 1 )
        {
          v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        else if ( (v13 >> 12) & 1 )
        {
          v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        else
        {
          v14 = UFG::SimObject::GetComponentOfType(
                  (UFG::SimObject *)&v12->vfptr,
                  UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        v4 = v14;
      }
      else
      {
        v4 = v12->m_Components.p[20].m_pComponent;
      }
    }
    v15 = &v2->m_pTargetingSystemBaseComponent;
    if ( v2->m_pTargetingSystemBaseComponent.m_pPointer )
    {
      v16 = v15->mPrev;
      v17 = v2->m_pTargetingSystemBaseComponent.mNext;
      v16->mNext = v17;
      v17->mPrev = v16;
      v15->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v15->mPrev;
      v2->m_pTargetingSystemBaseComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pTargetingSystemBaseComponent.mPrev;
    }
    v2->m_pTargetingSystemBaseComponent.m_pPointer = v4;
    if ( v4 )
    {
      v18 = v4->m_SafePointerList.mNode.mPrev;
      v18->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v15->mPrev;
      v15->mPrev = v18;
      v2->m_pTargetingSystemBaseComponent.mNext = &v4->m_SafePointerList.mNode;
      v4->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v15->mPrev;
    }
  }
  v19 = (UFG::ActiveAIEntityComponent *)v2->m_pAIEntityComponent.m_pPointer;
  if ( v19 )
  {
    v20 = v2->m_pTargetingSystemBaseComponent.m_pPointer;
    if ( v20 )
      UFG::ActiveAIEntityComponent::RemoveSupplementaryAttackTarget(
        v19,
        *(UFG::SimObject **)(56i64
                           * *(unsigned __int8 *)(LOBYTE(v2->m_Track[1].vfptr) + *(_QWORD *)&v20[1].m_Flags + 8i64)
                           + *(_QWORD *)&v20[1].m_TypeUID
                           + 40));
  }
}

// File Line: 5085
// RVA: 0x32ED60
void __fastcall GetInFormationTask::GetInFormationTask(GetInFormationTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::NavComponent> *v2; // r9
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *v3; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::FormationManagerComponent> *v4; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qSafePointer<UFG::GetInFormationNode,UFG::GetInFormationNode> *v11; // [rsp+28h] [rbp+10h]
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v12; // [rsp+28h] [rbp+10h]
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *v13; // [rsp+28h] [rbp+10h]
  UFG::qSafePointer<UFG::SimComponent,UFG::AIScriptInterfaceComponent> *v14; // [rsp+28h] [rbp+10h]

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<GetInFormationTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&GetInFormationTask::`vftable;
  v11 = &this->m_pGetInFormationNode;
  v11->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::GetInFormationNode>,UFG::qSafePointerNodeList> *)&v11->mPrev;
  v11->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::GetInFormationNode>,UFG::qSafePointerNodeList> *)&v11->mPrev;
  this->m_pGetInFormationNode.m_pPointer = 0i64;
  v2 = &this->m_pNavComponent;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  this->m_pNavComponent.m_pPointer = 0i64;
  v3 = &this->m_pTargetingSystemBaseComponent;
  v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  this->m_pTargetingSystemBaseComponent.m_pPointer = 0i64;
  v12 = &this->m_pTargetTransformNodeComponent;
  v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v12->mPrev;
  v12->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v12->mPrev;
  this->m_pTargetTransformNodeComponent.m_pPointer = 0i64;
  v4 = &this->m_pTargetFormationManagerComponent;
  v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  v4->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  this->m_pTargetFormationManagerComponent.m_pPointer = 0i64;
  v13 = &this->m_pTargetTargetingSystemBaseComponent;
  v13->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v13->mPrev;
  v13->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v13->mPrev;
  this->m_pTargetTargetingSystemBaseComponent.m_pPointer = 0i64;
  v14 = &this->m_pAIScriptInterfaceComponent;
  v14->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v14->mPrev;
  v14->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v14->mPrev;
  this->m_pAIScriptInterfaceComponent.m_pPointer = 0i64;
  this->m_NavParams.m_fRadius = 0.0;
  this->m_NavParams.m_flags = 65280;
  this->m_pActionContext = 0i64;
  if ( this->m_pNavComponent.m_pPointer )
  {
    v5 = v2->mPrev;
    v6 = v2->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  }
  v2->m_pPointer = 0i64;
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
  if ( v4->m_pPointer )
  {
    v9 = v4->mPrev;
    v10 = v4->mNext;
    v9->mNext = v10;
    v10->mPrev = v9;
    v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
    v4->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  }
  v4->m_pPointer = 0i64;
}

// File Line: 5096
// RVA: 0x3375A0
void __fastcall GetInFormationTask::~GetInFormationTask(GetInFormationTask *this)
{
  GetInFormationTask *v1; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::AIScriptInterfaceComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::FormationManagerComponent> *v12; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v17; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v21; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *v22; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v23; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v24; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v25; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v26; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::NavComponent> *v27; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v28; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v29; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v30; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v31; // rax
  UFG::qSafePointer<UFG::GetInFormationNode,UFG::GetInFormationNode> *v32; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInFormationNode>,UFG::qSafePointerNodeList> *v33; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInFormationNode>,UFG::qSafePointerNodeList> *v34; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInFormationNode>,UFG::qSafePointerNodeList> *v35; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInFormationNode>,UFG::qSafePointerNodeList> *v36; // rax
  UFG::qNode<ITask,ITask> *v37; // rdx
  UFG::qNode<ITask,ITask> *v38; // rcx
  UFG::qNode<ITask,ITask> *v39; // rax

  v1 = this;
  this->vfptr = (ITaskVtbl *)&GetInFormationTask::`vftable;
  v2 = &this->m_pAIScriptInterfaceComponent;
  if ( this->m_pAIScriptInterfaceComponent.m_pPointer )
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
  v7 = &v1->m_pTargetTargetingSystemBaseComponent;
  if ( v1->m_pTargetTargetingSystemBaseComponent.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v1->m_pTargetTargetingSystemBaseComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v1->m_pTargetTargetingSystemBaseComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pTargetTargetingSystemBaseComponent.mPrev;
  }
  v1->m_pTargetTargetingSystemBaseComponent.m_pPointer = 0i64;
  v10 = v7->mPrev;
  v11 = v1->m_pTargetTargetingSystemBaseComponent.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v1->m_pTargetTargetingSystemBaseComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pTargetTargetingSystemBaseComponent.mPrev;
  v12 = &v1->m_pTargetFormationManagerComponent;
  if ( v1->m_pTargetFormationManagerComponent.m_pPointer )
  {
    v13 = v12->mPrev;
    v14 = v1->m_pTargetFormationManagerComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v12->mPrev;
    v1->m_pTargetFormationManagerComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pTargetFormationManagerComponent.mPrev;
  }
  v1->m_pTargetFormationManagerComponent.m_pPointer = 0i64;
  v15 = v12->mPrev;
  v16 = v1->m_pTargetFormationManagerComponent.mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v12->mPrev;
  v1->m_pTargetFormationManagerComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pTargetFormationManagerComponent.mPrev;
  v17 = &v1->m_pTargetTransformNodeComponent;
  if ( v1->m_pTargetTransformNodeComponent.m_pPointer )
  {
    v18 = v17->mPrev;
    v19 = v1->m_pTargetTransformNodeComponent.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    v17->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v17->mPrev;
    v1->m_pTargetTransformNodeComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pTargetTransformNodeComponent.mPrev;
  }
  v1->m_pTargetTransformNodeComponent.m_pPointer = 0i64;
  v20 = v17->mPrev;
  v21 = v1->m_pTargetTransformNodeComponent.mNext;
  v20->mNext = v21;
  v21->mPrev = v20;
  v17->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v17->mPrev;
  v1->m_pTargetTransformNodeComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pTargetTransformNodeComponent.mPrev;
  v22 = &v1->m_pTargetingSystemBaseComponent;
  if ( v1->m_pTargetingSystemBaseComponent.m_pPointer )
  {
    v23 = v22->mPrev;
    v24 = v1->m_pTargetingSystemBaseComponent.mNext;
    v23->mNext = v24;
    v24->mPrev = v23;
    v22->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v22->mPrev;
    v1->m_pTargetingSystemBaseComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pTargetingSystemBaseComponent.mPrev;
  }
  v1->m_pTargetingSystemBaseComponent.m_pPointer = 0i64;
  v25 = v22->mPrev;
  v26 = v1->m_pTargetingSystemBaseComponent.mNext;
  v25->mNext = v26;
  v26->mPrev = v25;
  v22->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v22->mPrev;
  v1->m_pTargetingSystemBaseComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pTargetingSystemBaseComponent.mPrev;
  v27 = &v1->m_pNavComponent;
  if ( v1->m_pNavComponent.m_pPointer )
  {
    v28 = v27->mPrev;
    v29 = v1->m_pNavComponent.mNext;
    v28->mNext = v29;
    v29->mPrev = v28;
    v27->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v27->mPrev;
    v1->m_pNavComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pNavComponent.mPrev;
  }
  v1->m_pNavComponent.m_pPointer = 0i64;
  v30 = v27->mPrev;
  v31 = v1->m_pNavComponent.mNext;
  v30->mNext = v31;
  v31->mPrev = v30;
  v27->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v27->mPrev;
  v1->m_pNavComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pNavComponent.mPrev;
  v32 = &v1->m_pGetInFormationNode;
  if ( v1->m_pGetInFormationNode.m_pPointer )
  {
    v33 = v32->mPrev;
    v34 = v1->m_pGetInFormationNode.mNext;
    v33->mNext = v34;
    v34->mPrev = v33;
    v32->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::GetInFormationNode>,UFG::qSafePointerNodeList> *)&v32->mPrev;
    v1->m_pGetInFormationNode.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::GetInFormationNode>,UFG::qSafePointerNodeList> *)&v1->m_pGetInFormationNode.mPrev;
  }
  v1->m_pGetInFormationNode.m_pPointer = 0i64;
  v35 = v32->mPrev;
  v36 = v1->m_pGetInFormationNode.mNext;
  v35->mNext = v36;
  v36->mPrev = v35;
  v32->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::GetInFormationNode>,UFG::qSafePointerNodeList> *)&v32->mPrev;
  v1->m_pGetInFormationNode.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::GetInFormationNode>,UFG::qSafePointerNodeList> *)&v1->m_pGetInFormationNode.mPrev;
  v1->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v37 = (UFG::qNode<ITask,ITask> *)&v1->mPrev;
  v38 = v1->mPrev;
  v39 = v1->mNext;
  v38->mNext = v39;
  v39->mPrev = v38;
  v37->mPrev = v37;
  v37->mNext = v37;
}

// File Line: 5101
// RVA: 0x361D20
void __fastcall GetInFormationTask::GetPointersToTargetsComponents(GetInFormationTask *this)
{
  UFG::GetInFormationNode *v1; // rax
  GetInFormationTask *v2; // rsi
  UFG::SimComponent *v3; // rcx
  UFG::SimObjectGame *v4; // rbx
  UFG::SimComponent *v5; // rdi
  UFG::SimComponent *v6; // r8
  unsigned __int16 v7; // cx
  UFG::SimComponent *v8; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::FormationManagerComponent> *v9; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::TransformNodeComponent *v13; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v14; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rax
  unsigned __int16 v18; // cx
  UFG::SimComponent *v19; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *v20; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v21; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v22; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v23; // rax

  v1 = this->m_pGetInFormationNode.m_pPointer;
  v2 = this;
  if ( v1 )
  {
    v3 = this->m_pTargetingSystemBaseComponent.m_pPointer;
    if ( v3 )
    {
      v4 = *(UFG::SimObjectGame **)(56i64
                                  * *(unsigned __int8 *)((unsigned int)v1->m_TargetType
                                                       + *(_QWORD *)&v3[1].m_Flags
                                                       + 8i64)
                                  + *(_QWORD *)&v3[1].m_TypeUID
                                  + 40);
      v5 = 0i64;
      if ( v4 )
      {
        v7 = v4->m_Flags;
        if ( (v7 >> 14) & 1 )
        {
          v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::FormationManagerComponent::_TypeUID);
        }
        else if ( (v7 & 0x8000u) == 0 )
        {
          if ( (v7 >> 13) & 1 )
          {
            v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::FormationManagerComponent::_TypeUID);
          }
          else if ( (v7 >> 12) & 1 )
          {
            v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::FormationManagerComponent::_TypeUID);
          }
          else
          {
            v8 = UFG::SimObject::GetComponentOfType(
                   (UFG::SimObject *)&v4->vfptr,
                   UFG::FormationManagerComponent::_TypeUID);
          }
        }
        else
        {
          v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::FormationManagerComponent::_TypeUID);
        }
        v6 = v8;
      }
      else
      {
        v6 = 0i64;
      }
      v9 = &v2->m_pTargetFormationManagerComponent;
      if ( v2->m_pTargetFormationManagerComponent.m_pPointer )
      {
        v10 = v9->mPrev;
        v11 = v2->m_pTargetFormationManagerComponent.mNext;
        v10->mNext = v11;
        v11->mPrev = v10;
        v9->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
        v2->m_pTargetFormationManagerComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pTargetFormationManagerComponent.mPrev;
      }
      v2->m_pTargetFormationManagerComponent.m_pPointer = v6;
      if ( v6 )
      {
        v12 = v6->m_SafePointerList.mNode.mPrev;
        v12->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
        v9->mPrev = v12;
        v2->m_pTargetFormationManagerComponent.mNext = &v6->m_SafePointerList.mNode;
        v6->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
      }
      v13 = 0i64;
      if ( v4 )
        v13 = v4->m_pTransformNodeComponent;
      v14 = &v2->m_pTargetTransformNodeComponent;
      if ( v2->m_pTargetTransformNodeComponent.m_pPointer )
      {
        v15 = v14->mPrev;
        v16 = v2->m_pTargetTransformNodeComponent.mNext;
        v15->mNext = v16;
        v16->mPrev = v15;
        v14->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v14->mPrev;
        v2->m_pTargetTransformNodeComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pTargetTransformNodeComponent.mPrev;
      }
      v2->m_pTargetTransformNodeComponent.m_pPointer = (UFG::SimComponent *)&v13->vfptr;
      if ( v13 )
      {
        v17 = v13->m_SafePointerList.mNode.mPrev;
        v17->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v14->mPrev;
        v14->mPrev = v17;
        v2->m_pTargetTransformNodeComponent.mNext = &v13->m_SafePointerList.mNode;
        v13->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v14->mPrev;
      }
      if ( v4 )
      {
        v18 = v4->m_Flags;
        if ( (v18 >> 14) & 1 )
        {
          v5 = v4->m_Components.p[20].m_pComponent;
        }
        else if ( (v18 & 0x8000u) == 0 )
        {
          if ( (v18 >> 13) & 1 )
          {
            v19 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::TargetingSystemBaseComponent::_TypeUID);
          }
          else if ( (v18 >> 12) & 1 )
          {
            v19 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::TargetingSystemBaseComponent::_TypeUID);
          }
          else
          {
            v19 = UFG::SimObject::GetComponentOfType(
                    (UFG::SimObject *)&v4->vfptr,
                    UFG::TargetingSystemBaseComponent::_TypeUID);
          }
          v5 = v19;
        }
        else
        {
          v5 = v4->m_Components.p[20].m_pComponent;
        }
      }
      v20 = &v2->m_pTargetTargetingSystemBaseComponent;
      if ( v2->m_pTargetTargetingSystemBaseComponent.m_pPointer )
      {
        v21 = v20->mPrev;
        v22 = v2->m_pTargetTargetingSystemBaseComponent.mNext;
        v21->mNext = v22;
        v22->mPrev = v21;
        v20->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v20->mPrev;
        v2->m_pTargetTargetingSystemBaseComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pTargetTargetingSystemBaseComponent.mPrev;
      }
      v2->m_pTargetTargetingSystemBaseComponent.m_pPointer = v5;
      if ( v5 )
      {
        v23 = v5->m_SafePointerList.mNode.mPrev;
        v23->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v20->mPrev;
        v20->mPrev = v23;
        v2->m_pTargetTargetingSystemBaseComponent.mNext = &v5->m_SafePointerList.mNode;
        v5->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v20->mPrev;
      }
    }
  }
}

// File Line: 5118
// RVA: 0x345330
void __fastcall GetInFormationTask::Begin(GetInFormationTask *this, ActionContext *action_context)
{
  signed __int64 v2; // rdi
  ActionContext *v3; // rsi
  GetInFormationTask *v4; // rbx
  UFG::SimObjectGame *v5; // rcx
  UFG::SimComponent *v6; // r8
  unsigned __int16 v7; // dx
  UFG::SimComponent *v8; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::NavComponent> *v9; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::SimObjectGame *v13; // rcx
  UFG::SimComponent *v14; // r8
  unsigned __int16 v15; // dx
  UFG::SimComponent *v16; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *v17; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rax
  UFG::SimObjectGame *v21; // rcx
  UFG::SimComponent *v22; // r8
  unsigned __int16 v23; // dx
  UFG::SimComponent *v24; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AIScriptInterfaceComponent> *v25; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v26; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v27; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v28; // rax
  UFG::SimComponent *v29; // rcx
  int v30; // eax
  Expression::IMemberMapVtbl *v31; // r8
  Expression::IMemberMap *(__fastcall *v32)(Expression::IMemberMap *); // rax
  UFG::ActionTreeComponentBase *v33; // rdx
  UFG::ActionTreeComponentBase *v34; // rcx
  __int64 v35; // r8
  UFG::qSafePointer<UFG::GetInFormationNode,UFG::GetInFormationNode> *v36; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInFormationNode>,UFG::qSafePointerNodeList> *v37; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInFormationNode>,UFG::qSafePointerNodeList> *v38; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInFormationNode>,UFG::qSafePointerNodeList> *v39; // rax
  __int64 value_uid; // [rsp+30h] [rbp+8h]

  v2 = 0i64;
  v3 = action_context;
  v4 = this;
  this->m_pActionContext = action_context;
  if ( action_context )
  {
    v5 = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
    if ( v5 )
    {
      v7 = v5->m_Flags;
      if ( (v7 >> 14) & 1 )
      {
        v6 = v5->m_Components.p[36].m_pComponent;
      }
      else
      {
        if ( (v7 & 0x8000u) == 0 )
        {
          if ( (v7 >> 13) & 1 )
          {
            v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::NavComponent::_TypeUID);
          }
          else if ( (v7 >> 12) & 1 )
          {
            v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::NavComponent::_TypeUID);
          }
          else
          {
            v8 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v5->vfptr, UFG::NavComponent::_TypeUID);
          }
        }
        else
        {
          v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::NavComponent::_TypeUID);
        }
        v6 = v8;
      }
    }
    else
    {
      v6 = 0i64;
    }
    v9 = &v4->m_pNavComponent;
    if ( v4->m_pNavComponent.m_pPointer )
    {
      v10 = v9->mPrev;
      v11 = v4->m_pNavComponent.mNext;
      v10->mNext = v11;
      v11->mPrev = v10;
      v9->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
      v4->m_pNavComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->m_pNavComponent.mPrev;
    }
    v4->m_pNavComponent.m_pPointer = v6;
    if ( v6 )
    {
      v12 = v6->m_SafePointerList.mNode.mPrev;
      v12->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
      v9->mPrev = v12;
      v4->m_pNavComponent.mNext = &v6->m_SafePointerList.mNode;
      v6->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
    }
    v13 = (UFG::SimObjectGame *)v4->m_pActionContext->mSimObject.m_pPointer;
    if ( v13 )
    {
      v15 = v13->m_Flags;
      if ( (v15 >> 14) & 1 )
      {
        v14 = v13->m_Components.p[20].m_pComponent;
      }
      else if ( (v15 & 0x8000u) == 0 )
      {
        if ( (v15 >> 13) & 1 )
        {
          v16 = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        else if ( (v15 >> 12) & 1 )
        {
          v16 = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        else
        {
          v16 = UFG::SimObject::GetComponentOfType(
                  (UFG::SimObject *)&v13->vfptr,
                  UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        v14 = v16;
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
    v17 = &v4->m_pTargetingSystemBaseComponent;
    if ( v4->m_pTargetingSystemBaseComponent.m_pPointer )
    {
      v18 = v17->mPrev;
      v19 = v4->m_pTargetingSystemBaseComponent.mNext;
      v18->mNext = v19;
      v19->mPrev = v18;
      v17->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v17->mPrev;
      v4->m_pTargetingSystemBaseComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->m_pTargetingSystemBaseComponent.mPrev;
    }
    v4->m_pTargetingSystemBaseComponent.m_pPointer = v14;
    if ( v14 )
    {
      v20 = v14->m_SafePointerList.mNode.mPrev;
      v20->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v17->mPrev;
      v17->mPrev = v20;
      v4->m_pTargetingSystemBaseComponent.mNext = &v14->m_SafePointerList.mNode;
      v14->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v17->mPrev;
    }
    v21 = (UFG::SimObjectGame *)v4->m_pActionContext->mSimObject.m_pPointer;
    if ( v21 )
    {
      v23 = v21->m_Flags;
      if ( (v23 >> 14) & 1 )
      {
        v22 = v21->m_Components.p[5].m_pComponent;
      }
      else if ( (v23 & 0x8000u) == 0 )
      {
        if ( (v23 >> 13) & 1 )
        {
          v24 = UFG::SimObjectGame::GetComponentOfTypeHK(v21, UFG::AIScriptInterfaceComponent::_TypeUID);
        }
        else if ( (v23 >> 12) & 1 )
        {
          v24 = UFG::SimObjectGame::GetComponentOfTypeHK(v21, UFG::AIScriptInterfaceComponent::_TypeUID);
        }
        else
        {
          v24 = UFG::SimObject::GetComponentOfType(
                  (UFG::SimObject *)&v21->vfptr,
                  UFG::AIScriptInterfaceComponent::_TypeUID);
        }
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
    v25 = &v4->m_pAIScriptInterfaceComponent;
    if ( v4->m_pAIScriptInterfaceComponent.m_pPointer )
    {
      v26 = v25->mPrev;
      v27 = v4->m_pAIScriptInterfaceComponent.mNext;
      v26->mNext = v27;
      v27->mPrev = v26;
      v25->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v25->mPrev;
      v4->m_pAIScriptInterfaceComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->m_pAIScriptInterfaceComponent.mPrev;
    }
    v4->m_pAIScriptInterfaceComponent.m_pPointer = v22;
    if ( v22 )
    {
      v28 = v22->m_SafePointerList.mNode.mPrev;
      v28->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v25->mPrev;
      v25->mPrev = v28;
      v4->m_pAIScriptInterfaceComponent.mNext = &v22->m_SafePointerList.mNode;
      v22->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v25->mPrev;
    }
  }
  v29 = v4->m_pNavComponent.m_pPointer;
  value_uid = 0i64;
  v4->m_NavParams = *(UFG::NavParams *)((char *)&v29[2].m_BoundComponentHandles.mNode.mNext + 4);
  v30 = (int)v29[3].vfptr;
  LOBYTE(v29[3].vfptr) = 0;
  LODWORD(v29[3].vfptr) |= (unsigned __int8)(v30 & 0xFE);
  v31 = v4->m_Track[1].vfptr;
  v32 = v31->GetResourceOwner;
  if ( v32 )
    v33 = (UFG::ActionTreeComponentBase *)((char *)&v31->GetResourceOwner + (_QWORD)v32);
  else
    v33 = 0i64;
  if ( v32 )
    v2 = (signed __int64)&v31->GetResourceOwner + (_QWORD)v32;
  v34 = v3->mActionTreeComponentBase[*(char *)(v2 + 236)];
  if ( !v34 )
    v34 = v3->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::GetMemoryValueImpl<UFG::GetInFormationNode *>(
    v34,
    v33,
    (ActionNodeRoot *)HIDWORD(v31->GetResourcePath),
    (__int64)&value_uid);
  v35 = value_uid;
  v36 = &v4->m_pGetInFormationNode;
  if ( v4->m_pGetInFormationNode.m_pPointer )
  {
    v37 = v36->mPrev;
    v38 = v4->m_pGetInFormationNode.mNext;
    v37->mNext = v38;
    v38->mPrev = v37;
    v36->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::GetInFormationNode>,UFG::qSafePointerNodeList> *)&v36->mPrev;
    v4->m_pGetInFormationNode.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::GetInFormationNode>,UFG::qSafePointerNodeList> *)&v4->m_pGetInFormationNode.mPrev;
  }
  v4->m_pGetInFormationNode.m_pPointer = (UFG::GetInFormationNode *)v35;
  if ( v35 )
  {
    v39 = *(UFG::qNode<UFG::qSafePointerBase<UFG::GetInFormationNode>,UFG::qSafePointerNodeList> **)(v35 + 8);
    v39->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::GetInFormationNode>,UFG::qSafePointerNodeList> *)&v36->mPrev;
    v36->mPrev = v39;
    v4->m_pGetInFormationNode.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::GetInFormationNode>,UFG::qSafePointerNodeList> *)(v35 + 8);
    *(_QWORD *)(v35 + 8) = v36;
  }
  GetInFormationTask::GetPointersToTargetsComponents(v4);
}

// File Line: 5143
// RVA: 0x38F300
char __fastcall GetInFormationTask::Update(GetInFormationTask *this, float timestep)
{
  GetInFormationTask *v2; // rbx
  UFG::FormationManagerComponent *v3; // rsi
  UFG::GetInFormationNode *v4; // rdi
  __int64 v5; // rcx
  __int64 v6; // rax
  int v7; // eax
  bool v8; // r12
  UFG::TransformNodeComponent *v9; // r15
  int v10; // er13
  signed int v11; // ebp
  bool v12; // al
  UFG::GetInFormationNode *v13; // r10
  UFG::SimComponent *v14; // r11
  __int64 v15; // r9
  __int64 v16; // r8
  signed __int64 v17; // rdx
  char v18; // r14
  UFG::SimComponent *v19; // rax
  UFG::eMoveType v20; // edi
  UFG::SimObjectCVBase *v21; // rcx
  unsigned __int16 v22; // dx
  UFG::SimObjectCharacterPropertiesComponent *v23; // rax
  bool v24; // r9
  UFG::SimObject *v25; // r8
  UFG::TransformNodeComponent *v26; // rsi
  UFG::GetInFormationNode *v27; // rax
  UFG::SimComponent *v28; // rdx
  float v29; // xmm10_4
  UFG::SimObject *v30; // rcx
  float v31; // xmm9_4
  float v32; // xmm11_4
  __m128 v33; // xmm6
  __m128 v34; // xmm7
  __m128 v35; // xmm8
  bool v36; // zf
  UFG::SimObjectCVBase *v37; // rcx
  unsigned __int16 v38; // dx
  UFG::AICharacterControllerBaseComponent *v39; // rax
  UFG::qVector3 desired_position; // [rsp+30h] [rbp-F8h]
  UFG::HavokNavPosition npDestination; // [rsp+40h] [rbp-E8h]
  char v43; // [rsp+130h] [rbp+8h]
  bool v44; // [rsp+140h] [rbp+18h]
  UFG::eMoveType move_type; // [rsp+148h] [rbp+20h]

  v2 = this;
  GetInFormationTask::GetPointersToTargetsComponents(this);
  v3 = (UFG::FormationManagerComponent *)v2->m_pTargetFormationManagerComponent.m_pPointer;
  if ( !v3 )
    return 1;
  v4 = v2->m_pGetInFormationNode.m_pPointer;
  if ( !v4 )
    return 1;
  v5 = v4->m_RangeIndex;
  v6 = v4->m_SlotIndex;
  if ( (_DWORD)v5 != -1
    && (_DWORD)v6 != -1
    && v3->mStateVariables.m_FormationSlot[0][v6 + 8 * v5].m_pMember.m_pPointer == v4 )
  {
    v7 = UFG::FormationManagerComponent::GetInPositionType(v3, v4);
    v8 = v3->m_FormationFacingType == 1;
    v9 = 0i64;
    desired_position = UFG::qVector3::msZero;
    v10 = v7;
    move_type = -1;
    v11 = 0;
    v43 = UFG::FormationManagerComponent::GetDesiredPosition(v3, v4, &desired_position);
    v12 = UFG::FormationManagerComponent::GetDesiredSpeed(
            (UFG::FormationManagerComponent *)v2->m_pTargetFormationManagerComponent.m_pPointer,
            v2->m_pGetInFormationNode.m_pPointer,
            &move_type);
    v13 = v2->m_pGetInFormationNode.m_pPointer;
    v14 = v2->m_pTargetFormationManagerComponent.m_pPointer;
    v44 = v12;
    if ( v13
      && (v15 = v13->m_RangeIndex, v16 = v13->m_SlotIndex, (_DWORD)v15 != -1)
      && (_DWORD)v16 != -1
      && *((UFG::GetInFormationNode **)&v14[10].m_BoundComponentHandles.mNode.mPrev + 25 * (v16 + 8 * v15)) == v13 )
    {
      v11 = 1;
      v17 = 200 * (v16 + 8 * v15);
      if ( *(_DWORD *)((char *)&v14[10].m_SafePointerList.mNode.mNext + v17) != 3 )
        v11 = *(_DWORD *)((char *)&v14[12].m_SafePointerList.mNode.mNext + v17);
      v18 = 1;
    }
    else
    {
      v18 = 0;
    }
    v19 = v2->m_pAIScriptInterfaceComponent.m_pPointer;
    if ( !v19 || BYTE1(v19[32].m_BoundComponentHandles.mNode.mPrev) & 0x40 )
    {
      v20 = move_type;
    }
    else
    {
      v20 = move_type;
      if ( move_type == 3 )
        v20 = 2;
    }
    v21 = (UFG::SimObjectCVBase *)v2->m_pActionContext->mSimObject.m_pPointer;
    v24 = 0;
    if ( v21 )
    {
      v22 = v21->m_Flags;
      if ( (v22 >> 14) & 1 )
      {
        v23 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v21);
      }
      else if ( (v22 & 0x8000u) == 0 )
      {
        if ( (v22 >> 13) & 1 )
          v23 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                (UFG::SimObjectGame *)&v21->vfptr,
                                                                UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
        else
          v23 = (UFG::SimObjectCharacterPropertiesComponent *)((v22 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                                   (UFG::SimObjectGame *)&v21->vfptr,
                                                                                   UFG::SimObjectCharacterPropertiesComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v21->vfptr, UFG::SimObjectCharacterPropertiesComponent::_TypeUID));
      }
      else
      {
        v23 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v21);
      }
      if ( v23 && v23->m_eFightingClass == 5 )
        v24 = 1;
    }
    v25 = v2->m_pActionContext->mSimObject.m_pPointer;
    if ( v25
      && v25->m_pTransformNodeComponent
      && (v26 = (UFG::TransformNodeComponent *)v2->m_pTargetTransformNodeComponent.m_pPointer) != 0i64
      && (v27 = v2->m_pGetInFormationNode.m_pPointer) != 0i64
      && v27->m_AttackType == eATTACK_TYPE_MELEE
      && (v28 = v2->m_pTargetTargetingSystemBaseComponent.m_pPointer) != 0i64
      && *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v28[1].m_Flags + 30i64)
                            + *(_QWORD *)&v28[1].m_TypeUID
                            + 40) == v25
      && !v24 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(v26);
      v29 = v26->mWorldTransform.v3.x;
      v30 = v2->m_pActionContext->mSimObject.m_pPointer;
      v31 = v26->mWorldTransform.v3.y;
      v32 = v26->mWorldTransform.v3.z;
      if ( v30 )
        v9 = v30->m_pTransformNodeComponent;
      UFG::TransformNodeComponent::UpdateWorldTransform(v9);
      v33 = (__m128)LODWORD(desired_position.x);
      v34 = (__m128)LODWORD(desired_position.y);
      v35 = (__m128)LODWORD(desired_position.z);
      if ( (float)((float)((float)((float)(v31 - v9->mWorldTransform.v3.y)
                                 * (float)(desired_position.y - v9->mWorldTransform.v3.y))
                         + (float)((float)(v29 - v9->mWorldTransform.v3.x)
                                 * (float)(desired_position.x - v9->mWorldTransform.v3.x)))
                 + (float)((float)(v32 - v9->mWorldTransform.v3.z)
                         * (float)(desired_position.z - v9->mWorldTransform.v3.z))) < 0.0 )
      {
        UFG::FormationManagerComponent::SetInPositionType(
          (UFG::FormationManagerComponent *)v2->m_pTargetFormationManagerComponent.m_pPointer,
          v2->m_pGetInFormationNode.m_pPointer,
          0);
        UFG::FormationManagerComponent::SetDesiredDirectionFromCurrentPosition(
          (UFG::FormationManagerComponent *)v2->m_pTargetFormationManagerComponent.m_pPointer,
          v2->m_pGetInFormationNode.m_pPointer);
        goto LABEL_46;
      }
    }
    else
    {
      v35 = (__m128)LODWORD(desired_position.z);
      v34 = (__m128)LODWORD(desired_position.y);
      v33 = (__m128)LODWORD(desired_position.x);
    }
    if ( v10 && v43 && v44 && v18 )
    {
      LODWORD(npDestination.m_vPosition.x) = v33.m128_i32[0];
      LODWORD(npDestination.m_vPosition.y) = v34.m128_i32[0];
      npDestination.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
      LODWORD(npDestination.m_vPosition.z) = v35.m128_i32[0];
      npDestination.m_bValid = 0;
      *(_QWORD *)&npDestination.m_packedKey = -1i64;
      npDestination.m_hkvMeshPosition.m_quad = _mm_unpacklo_ps(
                                                 _mm_unpacklo_ps(v33, v35),
                                                 _mm_unpacklo_ps(v34, (__m128)(unsigned int)FLOAT_1_0));
      UFG::NavComponent::AddGoalPoint(
        (UFG::NavComponent *)v2->m_pNavComponent.m_pPointer,
        &npDestination,
        0,
        sNaturalMovementSpeeds[v20],
        0.5);
      if ( (unsigned __int8)UFG::NavComponent::IsAtDestination((UFG::NavComponent *)v2->m_pNavComponent.m_pPointer) )
        UFG::FormationManagerComponent::SetInPositionType(
          (UFG::FormationManagerComponent *)v2->m_pTargetFormationManagerComponent.m_pPointer,
          v2->m_pGetInFormationNode.m_pPointer,
          0);
      if ( !v11 )
        return 1;
      v36 = v20 == 3;
      goto LABEL_47;
    }
LABEL_46:
    v36 = v8 == 0;
LABEL_47:
    if ( !v36 )
    {
      v37 = (UFG::SimObjectCVBase *)v2->m_pActionContext->mSimObject.m_pPointer;
      if ( v37 )
      {
        v38 = v37->m_Flags;
        if ( (v38 >> 14) & 1 )
        {
          v39 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v37);
        }
        else if ( (v38 & 0x8000u) == 0 )
        {
          if ( (v38 >> 13) & 1 )
          {
            v39 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               (UFG::SimObjectGame *)&v37->vfptr,
                                                               UFG::AICharacterControllerBaseComponent::_TypeUID);
          }
          else if ( (v38 >> 12) & 1 )
          {
            v39 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               (UFG::SimObjectGame *)&v37->vfptr,
                                                               UFG::AICharacterControllerBaseComponent::_TypeUID);
          }
          else
          {
            v39 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                               (UFG::SimObject *)&v37->vfptr,
                                                               UFG::AICharacterControllerBaseComponent::_TypeUID);
          }
        }
        else
        {
          v39 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v37);
        }
        if ( v39 )
          Intention::Set(&v39->m_Intention, gActionRequest_Focus.m_EnumValue, 0.0);
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
  UFG::SimComponent *v1; // rax

  v1 = this->m_pNavComponent.m_pPointer;
  if ( v1 )
  {
    if ( this->m_NavParams.m_flags & 1 )
      LODWORD(v1[3].vfptr) |= 1u;
  }
}

// File Line: 5317
// RVA: 0x32F130
void __fastcall GetInPedFormationTask::GetInPedFormationTask(GetInPedFormationTask *this)
{
  GetInPedFormationTask *v1; // r11
  UFG::qNode<ITask,ITask> *v2; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::NavComponent> *v3; // r10
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v4; // r9
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *v5; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::PedFormationManagerComponent> *v6; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qSafePointer<UFG::GetInPedFormationNode,UFG::GetInPedFormationNode> *v15; // [rsp+28h] [rbp+10h]

  v1 = this;
  v2 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<GetInPedFormationTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&GetInPedFormationTask::`vftable;
  v15 = &this->m_pGetInPedFormationNode;
  v15->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::GetInPedFormationNode>,UFG::qSafePointerNodeList> *)&v15->mPrev;
  v15->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::GetInPedFormationNode>,UFG::qSafePointerNodeList> *)&v15->mPrev;
  this->m_pGetInPedFormationNode.m_pPointer = 0i64;
  v3 = &this->m_pNavComponent;
  v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  this->m_pNavComponent.m_pPointer = 0i64;
  v4 = &this->m_pAIEntityComponent;
  v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  v4->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  this->m_pAIEntityComponent.m_pPointer = 0i64;
  v5 = &this->m_pTargetingSystemBaseComponent;
  v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v5->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  this->m_pTargetingSystemBaseComponent.m_pPointer = 0i64;
  v6 = &this->m_pTargetPedFormationManagerComponent;
  v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  v6->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  this->m_pTargetPedFormationManagerComponent.m_pPointer = 0i64;
  this->m_pActionContext = 0i64;
  if ( this->m_pNavComponent.m_pPointer )
  {
    v7 = v3->mPrev;
    v8 = v3->mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
    v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  }
  v3->m_pPointer = 0i64;
  if ( v4->m_pPointer )
  {
    v9 = v4->mPrev;
    v10 = v4->mNext;
    v9->mNext = v10;
    v10->mPrev = v9;
    v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
    v4->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  }
  v4->m_pPointer = 0i64;
  if ( v5->m_pPointer )
  {
    v11 = v5->mPrev;
    v12 = v5->mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
    v5->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  }
  v5->m_pPointer = 0i64;
  if ( v6->m_pPointer )
  {
    v13 = v6->mPrev;
    v14 = v6->mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
    v6->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  }
  v6->m_pPointer = 0i64;
  v1->m_PreviousGoalReachedThreshold = 0.0;
}

// File Line: 5331
// RVA: 0x337AF0
void __fastcall GetInPedFormationTask::~GetInPedFormationTask(GetInPedFormationTask *this)
{
  GetInPedFormationTask *v1; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::PedFormationManagerComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v12; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::NavComponent> *v17; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v21; // rax
  UFG::qSafePointer<UFG::GetInPedFormationNode,UFG::GetInPedFormationNode> *v22; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInPedFormationNode>,UFG::qSafePointerNodeList> *v23; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInPedFormationNode>,UFG::qSafePointerNodeList> *v24; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInPedFormationNode>,UFG::qSafePointerNodeList> *v25; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInPedFormationNode>,UFG::qSafePointerNodeList> *v26; // rax
  UFG::qNode<ITask,ITask> *v27; // rdx
  UFG::qNode<ITask,ITask> *v28; // rcx
  UFG::qNode<ITask,ITask> *v29; // rax

  v1 = this;
  this->vfptr = (ITaskVtbl *)&GetInPedFormationTask::`vftable;
  v2 = &this->m_pTargetPedFormationManagerComponent;
  if ( this->m_pTargetPedFormationManagerComponent.m_pPointer )
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
  v7 = &v1->m_pTargetingSystemBaseComponent;
  if ( v1->m_pTargetingSystemBaseComponent.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v1->m_pTargetingSystemBaseComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v1->m_pTargetingSystemBaseComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pTargetingSystemBaseComponent.mPrev;
  }
  v1->m_pTargetingSystemBaseComponent.m_pPointer = 0i64;
  v10 = v7->mPrev;
  v11 = v1->m_pTargetingSystemBaseComponent.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v1->m_pTargetingSystemBaseComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pTargetingSystemBaseComponent.mPrev;
  v12 = &v1->m_pAIEntityComponent;
  if ( v1->m_pAIEntityComponent.m_pPointer )
  {
    v13 = v12->mPrev;
    v14 = v1->m_pAIEntityComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v12->mPrev;
    v1->m_pAIEntityComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pAIEntityComponent.mPrev;
  }
  v1->m_pAIEntityComponent.m_pPointer = 0i64;
  v15 = v12->mPrev;
  v16 = v1->m_pAIEntityComponent.mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v12->mPrev;
  v1->m_pAIEntityComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pAIEntityComponent.mPrev;
  v17 = &v1->m_pNavComponent;
  if ( v1->m_pNavComponent.m_pPointer )
  {
    v18 = v17->mPrev;
    v19 = v1->m_pNavComponent.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    v17->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v17->mPrev;
    v1->m_pNavComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pNavComponent.mPrev;
  }
  v1->m_pNavComponent.m_pPointer = 0i64;
  v20 = v17->mPrev;
  v21 = v1->m_pNavComponent.mNext;
  v20->mNext = v21;
  v21->mPrev = v20;
  v17->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v17->mPrev;
  v1->m_pNavComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pNavComponent.mPrev;
  v22 = &v1->m_pGetInPedFormationNode;
  if ( v1->m_pGetInPedFormationNode.m_pPointer )
  {
    v23 = v22->mPrev;
    v24 = v1->m_pGetInPedFormationNode.mNext;
    v23->mNext = v24;
    v24->mPrev = v23;
    v22->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::GetInPedFormationNode>,UFG::qSafePointerNodeList> *)&v22->mPrev;
    v1->m_pGetInPedFormationNode.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::GetInPedFormationNode>,UFG::qSafePointerNodeList> *)&v1->m_pGetInPedFormationNode.mPrev;
  }
  v1->m_pGetInPedFormationNode.m_pPointer = 0i64;
  v25 = v22->mPrev;
  v26 = v1->m_pGetInPedFormationNode.mNext;
  v25->mNext = v26;
  v26->mPrev = v25;
  v22->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::GetInPedFormationNode>,UFG::qSafePointerNodeList> *)&v22->mPrev;
  v1->m_pGetInPedFormationNode.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::GetInPedFormationNode>,UFG::qSafePointerNodeList> *)&v1->m_pGetInPedFormationNode.mPrev;
  v1->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v27 = (UFG::qNode<ITask,ITask> *)&v1->mPrev;
  v28 = v1->mPrev;
  v29 = v1->mNext;
  v28->mNext = v29;
  v29->mPrev = v28;
  v27->mPrev = v27;
  v27->mNext = v27;
}

// File Line: 5336
// RVA: 0x345660
void __fastcall GetInPedFormationTask::Begin(GetInPedFormationTask *this, ActionContext *action_context)
{
  signed __int64 v2; // rdi
  ActionContext *v3; // rsi
  GetInPedFormationTask *v4; // rbx
  UFG::SimObjectGame *v5; // rcx
  UFG::SimComponent *v6; // r8
  unsigned __int16 v7; // dx
  UFG::SimComponent *v8; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::NavComponent> *v9; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::SimObjectCVBase *v13; // rcx
  UFG::ActiveAIEntityComponent *v14; // r8
  unsigned __int16 v15; // dx
  UFG::ActiveAIEntityComponent *v16; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v17; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rax
  UFG::SimObjectGame *v21; // rcx
  UFG::SimComponent *v22; // r8
  unsigned __int16 v23; // dx
  UFG::SimComponent *v24; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *v25; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v26; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v27; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v28; // rax
  ITrack *v29; // rax
  Expression::IMemberMapVtbl *v30; // r8
  Expression::IMemberMap *(__fastcall *v31)(Expression::IMemberMap *); // rax
  UFG::ActionTreeComponentBase *v32; // rdx
  UFG::ActionTreeComponentBase *v33; // rcx
  __int64 v34; // r8
  UFG::qSafePointer<UFG::GetInPedFormationNode,UFG::GetInPedFormationNode> *v35; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInPedFormationNode>,UFG::qSafePointerNodeList> *v36; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInPedFormationNode>,UFG::qSafePointerNodeList> *v37; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::GetInPedFormationNode>,UFG::qSafePointerNodeList> *v38; // rax
  UFG::GroupComponent *v39; // rax
  UFG::GroupComponent *v40; // rax
  UFG::PedSpawningInfo *v41; // rcx
  UFG::SimObjectGame *v42; // rcx
  unsigned __int16 v43; // dx
  UFG::SimComponent *v44; // rax
  unsigned int v45; // edx
  bool v46; // zf
  __int64 value_uid; // [rsp+30h] [rbp+8h]

  v2 = 0i64;
  v3 = action_context;
  v4 = this;
  this->m_pActionContext = action_context;
  if ( action_context )
  {
    v5 = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
    if ( v5 )
    {
      v7 = v5->m_Flags;
      if ( (v7 >> 14) & 1 )
      {
        v6 = v5->m_Components.p[36].m_pComponent;
      }
      else
      {
        if ( (v7 & 0x8000u) == 0 )
        {
          if ( (v7 >> 13) & 1 )
          {
            v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::NavComponent::_TypeUID);
          }
          else if ( (v7 >> 12) & 1 )
          {
            v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::NavComponent::_TypeUID);
          }
          else
          {
            v8 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v5->vfptr, UFG::NavComponent::_TypeUID);
          }
        }
        else
        {
          v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::NavComponent::_TypeUID);
        }
        v6 = v8;
      }
    }
    else
    {
      v6 = 0i64;
    }
    v9 = &v4->m_pNavComponent;
    if ( v4->m_pNavComponent.m_pPointer )
    {
      v10 = v9->mPrev;
      v11 = v4->m_pNavComponent.mNext;
      v10->mNext = v11;
      v11->mPrev = v10;
      v9->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
      v4->m_pNavComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->m_pNavComponent.mPrev;
    }
    v4->m_pNavComponent.m_pPointer = v6;
    if ( v6 )
    {
      v12 = v6->m_SafePointerList.mNode.mPrev;
      v12->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
      v9->mPrev = v12;
      v4->m_pNavComponent.mNext = &v6->m_SafePointerList.mNode;
      v6->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
    }
    v13 = (UFG::SimObjectCVBase *)v4->m_pActionContext->mSimObject.m_pPointer;
    if ( v13 )
    {
      v15 = v13->m_Flags;
      if ( (v15 >> 14) & 1 )
      {
        v16 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v13);
      }
      else if ( (v15 & 0x8000u) == 0 )
      {
        if ( (v15 >> 13) & 1 )
        {
          v16 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  (UFG::SimObjectGame *)&v13->vfptr,
                                                  UFG::ActiveAIEntityComponent::_TypeUID);
        }
        else if ( (v15 >> 12) & 1 )
        {
          v16 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  (UFG::SimObjectGame *)&v13->vfptr,
                                                  UFG::ActiveAIEntityComponent::_TypeUID);
        }
        else
        {
          v16 = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                  (UFG::SimObject *)&v13->vfptr,
                                                  UFG::ActiveAIEntityComponent::_TypeUID);
        }
      }
      else
      {
        v16 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v13);
      }
      v14 = v16;
    }
    else
    {
      v14 = 0i64;
    }
    v17 = &v4->m_pAIEntityComponent;
    if ( v4->m_pAIEntityComponent.m_pPointer )
    {
      v18 = v17->mPrev;
      v19 = v4->m_pAIEntityComponent.mNext;
      v18->mNext = v19;
      v19->mPrev = v18;
      v17->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v17->mPrev;
      v4->m_pAIEntityComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->m_pAIEntityComponent.mPrev;
    }
    v4->m_pAIEntityComponent.m_pPointer = (UFG::SimComponent *)&v14->vfptr;
    if ( v14 )
    {
      v20 = v14->m_SafePointerList.mNode.mPrev;
      v20->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v17->mPrev;
      v17->mPrev = v20;
      v4->m_pAIEntityComponent.mNext = &v14->m_SafePointerList.mNode;
      v14->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v17->mPrev;
    }
    v21 = (UFG::SimObjectGame *)v4->m_pActionContext->mSimObject.m_pPointer;
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
    v25 = &v4->m_pTargetingSystemBaseComponent;
    if ( v4->m_pTargetingSystemBaseComponent.m_pPointer )
    {
      v26 = v25->mPrev;
      v27 = v4->m_pTargetingSystemBaseComponent.mNext;
      v26->mNext = v27;
      v27->mPrev = v26;
      v25->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v25->mPrev;
      v4->m_pTargetingSystemBaseComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->m_pTargetingSystemBaseComponent.mPrev;
    }
    v4->m_pTargetingSystemBaseComponent.m_pPointer = v22;
    if ( v22 )
    {
      v28 = v22->m_SafePointerList.mNode.mPrev;
      v28->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v25->mPrev;
      v25->mPrev = v28;
      v4->m_pTargetingSystemBaseComponent.mNext = &v22->m_SafePointerList.mNode;
      v22->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v25->mPrev;
    }
  }
  v29 = v4->m_Track;
  value_uid = 0i64;
  v30 = v29[1].vfptr;
  v31 = v30->GetResourceOwner;
  if ( v31 )
    v32 = (UFG::ActionTreeComponentBase *)((char *)&v30->GetResourceOwner + (_QWORD)v31);
  else
    v32 = 0i64;
  if ( v31 )
    v2 = (signed __int64)&v30->GetResourceOwner + (_QWORD)v31;
  v33 = v3->mActionTreeComponentBase[*(char *)(v2 + 236)];
  if ( !v33 )
    v33 = v3->mActionTreeComponentBase[1];
  UFG::ActionTreeComponentBase::GetMemoryValueImpl<UFG::GetInPedFormationNode *>(
    v33,
    v32,
    (ActionNodeRoot *)HIDWORD(v30->GetResourcePath),
    (__int64)&value_uid);
  v34 = value_uid;
  v35 = &v4->m_pGetInPedFormationNode;
  if ( v4->m_pGetInPedFormationNode.m_pPointer )
  {
    v36 = v35->mPrev;
    v37 = v4->m_pGetInPedFormationNode.mNext;
    v36->mNext = v37;
    v37->mPrev = v36;
    v35->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::GetInPedFormationNode>,UFG::qSafePointerNodeList> *)&v35->mPrev;
    v4->m_pGetInPedFormationNode.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::GetInPedFormationNode>,UFG::qSafePointerNodeList> *)&v4->m_pGetInPedFormationNode.mPrev;
  }
  v4->m_pGetInPedFormationNode.m_pPointer = (UFG::GetInPedFormationNode *)v34;
  if ( v34 )
  {
    v38 = *(UFG::qNode<UFG::qSafePointerBase<UFG::GetInPedFormationNode>,UFG::qSafePointerNodeList> **)(v34 + 8);
    v38->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::GetInPedFormationNode>,UFG::qSafePointerNodeList> *)&v35->mPrev;
    v35->mPrev = v38;
    v4->m_pGetInPedFormationNode.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::GetInPedFormationNode>,UFG::qSafePointerNodeList> *)(v34 + 8);
    *(_QWORD *)(v34 + 8) = v35;
  }
  if ( v4->m_pGetInPedFormationNode.m_pPointer )
  {
    v39 = UFG::GroupComponent::GetGroupComponent(v4->m_pActionContext->mSimObject.m_pPointer);
    if ( v39 )
    {
      v40 = v39->mGroupFollower.mLeader.m_pPointer;
      if ( v40 )
      {
        v41 = v40->mOwner;
        if ( v41 )
        {
          v42 = (UFG::SimObjectGame *)v41->mSimObjectPtr.m_pPointer;
          if ( v42 )
          {
            v43 = v42->m_Flags;
            if ( (v43 >> 14) & 1 )
            {
              v44 = v42->m_Components.p[33].m_pComponent;
            }
            else
            {
              if ( (v43 & 0x8000u) != 0 || (v43 >> 13) & 1 )
              {
                v45 = UFG::PedFormationManagerComponent::_TypeUID;
              }
              else
              {
                v46 = ((v43 >> 12) & 1) == 0;
                v45 = UFG::PedFormationManagerComponent::_TypeUID;
                if ( v46 )
                {
                  v44 = UFG::SimObject::GetComponentOfType(
                          (UFG::SimObject *)&v42->vfptr,
                          UFG::PedFormationManagerComponent::_TypeUID);
                  goto LABEL_74;
                }
              }
              v44 = UFG::SimObjectGame::GetComponentOfTypeHK(v42, v45);
            }
LABEL_74:
            UFG::qSafePointer<Creature,Creature>::operator=(
              (UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *)&v4->m_pTargetPedFormationManagerComponent,
              v44);
            return;
          }
        }
      }
    }
  }
}peHK(v42, v45);
            }
LABEL_74:
            UFG::qSafePointer<Creature,Creature>::operator=(
              (UFG::qSafePointer<UFG::SimComponent,UFG::Sim

// File Line: 5386
// RVA: 0x38F8A0
char __fastcall GetInPedFormationTask::Update(GetInPedFormationTask *this, float timestep)
{
  GetInPedFormationTask *v2; // rdi
  UFG::PedFormationManagerComponent *v3; // rbx
  UFG::GetInPedFormationNode *v4; // rdx
  UFG::NavComponent *v5; // rbx
  float fDestinationTolerance; // xmm0_4
  UFG::qVector3 desired_waypoint; // [rsp+30h] [rbp-58h]
  UFG::HavokNavPosition npDestination; // [rsp+40h] [rbp-48h]
  float desired_speed; // [rsp+90h] [rbp+8h]

  v2 = this;
  if ( !this->m_pAIEntityComponent.m_pPointer )
    return 1;
  v3 = (UFG::PedFormationManagerComponent *)this->m_pTargetPedFormationManagerComponent.m_pPointer;
  if ( v3 )
  {
    if ( this->m_pGetInPedFormationNode.m_pPointer )
    {
      if ( (unsigned int)UFG::PedFormationManagerComponent::GetInPositionType(
                           (UFG::PedFormationManagerComponent *)this->m_pTargetPedFormationManagerComponent.m_pPointer,
                           this->m_pGetInPedFormationNode.m_pPointer) )
      {
        v4 = v2->m_pGetInPedFormationNode.m_pPointer;
        desired_waypoint = UFG::qVector3::msZero;
        desired_speed = 0.0;
        if ( UFG::PedFormationManagerComponent::GetDesiredWaypoint(v3, v4, &desired_waypoint, &desired_speed) )
        {
          v5 = (UFG::NavComponent *)v2->m_pNavComponent.m_pPointer;
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
          UFG::NavComponent::AddGoalPoint(v5, &npDestination, 0, desired_speed, fDestinationTolerance);
          if ( (unsigned __int8)UFG::NavComponent::IsAtDestination((UFG::NavComponent *)v2->m_pNavComponent.m_pPointer) )
            UFG::PedFormationManagerComponent::OnArrived(
              (UFG::PedFormationManagerComponent *)v2->m_pTargetPedFormationManagerComponent.m_pPointer,
              v2->m_pGetInPedFormationNode.m_pPointer,
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
  UFG::qNode<ITask,ITask> *v1; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v2; // r9
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *v3; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::FormationManagerComponent> *v4; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<InvalidateFormationPositionTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&InvalidateFormationPositionTask::`vftable;
  v2 = &this->m_pAIEntityComponent;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  this->m_pAIEntityComponent.m_pPointer = 0i64;
  v3 = &this->m_pTargetingSystemBaseComponent;
  v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  this->m_pTargetingSystemBaseComponent.m_pPointer = 0i64;
  v4 = &this->m_pTargetFormationManagerComponent;
  v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  v4->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  this->m_pTargetFormationManagerComponent.m_pPointer = 0i64;
  this->m_pActionContext = 0i64;
  if ( this->m_pAIEntityComponent.m_pPointer )
  {
    v5 = v2->mPrev;
    v6 = v2->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  }
  v2->m_pPointer = 0i64;
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
  if ( v4->m_pPointer )
  {
    v9 = v4->mPrev;
    v10 = v4->mNext;
    v9->mNext = v10;
    v10->mPrev = v9;
    v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
    v4->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  }
  v4->m_pPointer = 0i64;
}

// File Line: 5494
// RVA: 0x338C60
void __fastcall InvalidateFormationPositionTask::~InvalidateFormationPositionTask(InvalidateFormationPositionTask *this)
{
  InvalidateFormationPositionTask *v1; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::FormationManagerComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v12; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qNode<ITask,ITask> *v17; // rdx
  UFG::qNode<ITask,ITask> *v18; // rcx
  UFG::qNode<ITask,ITask> *v19; // rax

  v1 = this;
  this->vfptr = (ITaskVtbl *)&InvalidateFormationPositionTask::`vftable;
  v2 = &this->m_pTargetFormationManagerComponent;
  if ( this->m_pTargetFormationManagerComponent.m_pPointer )
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
  v7 = &v1->m_pTargetingSystemBaseComponent;
  if ( v1->m_pTargetingSystemBaseComponent.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v1->m_pTargetingSystemBaseComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v1->m_pTargetingSystemBaseComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pTargetingSystemBaseComponent.mPrev;
  }
  v1->m_pTargetingSystemBaseComponent.m_pPointer = 0i64;
  v10 = v7->mPrev;
  v11 = v1->m_pTargetingSystemBaseComponent.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v1->m_pTargetingSystemBaseComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pTargetingSystemBaseComponent.mPrev;
  v12 = &v1->m_pAIEntityComponent;
  if ( v1->m_pAIEntityComponent.m_pPointer )
  {
    v13 = v12->mPrev;
    v14 = v1->m_pAIEntityComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v12->mPrev;
    v1->m_pAIEntityComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pAIEntityComponent.mPrev;
  }
  v1->m_pAIEntityComponent.m_pPointer = 0i64;
  v15 = v12->mPrev;
  v16 = v1->m_pAIEntityComponent.mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v12->mPrev;
  v1->m_pAIEntityComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pAIEntityComponent.mPrev;
  v1->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v17 = (UFG::qNode<ITask,ITask> *)&v1->mPrev;
  v18 = v1->mPrev;
  v19 = v1->mNext;
  v18->mNext = v19;
  v19->mPrev = v18;
  v17->mPrev = v17;
  v17->mNext = v17;
}

// File Line: 5499
// RVA: 0x346550
void __fastcall InvalidateFormationPositionTask::Begin(InvalidateFormationPositionTask *this, ActionContext *action_context)
{
  UFG::SimComponent *v2; // rbx
  InvalidateFormationPositionTask *v3; // rdi
  UFG::SimObjectCVBase *v4; // rcx
  UFG::ActiveAIEntityComponent *v5; // r8
  unsigned __int16 v6; // dx
  UFG::ActiveAIEntityComponent *v7; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v8; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::SimObjectGame *v12; // rcx
  UFG::SimComponent *v13; // r8
  unsigned __int16 v14; // dx
  UFG::SimComponent *v15; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *v16; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::SimComponent *v20; // r8
  UFG::SimObjectGame *v21; // rcx
  unsigned __int16 v22; // dx
  UFG::SimComponent *v23; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::FormationManagerComponent> *v24; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v25; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v26; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v27; // rax

  v2 = 0i64;
  v3 = this;
  this->m_pActionContext = action_context;
  if ( action_context )
  {
    v4 = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
    if ( v4 )
    {
      v6 = v4->m_Flags;
      if ( (v6 >> 14) & 1 )
      {
        v7 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v4);
      }
      else if ( (v6 & 0x8000u) == 0 )
      {
        if ( (v6 >> 13) & 1 )
        {
          v7 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)&v4->vfptr,
                                                 UFG::ActiveAIEntityComponent::_TypeUID);
        }
        else if ( (v6 >> 12) & 1 )
        {
          v7 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)&v4->vfptr,
                                                 UFG::ActiveAIEntityComponent::_TypeUID);
        }
        else
        {
          v7 = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                 (UFG::SimObject *)&v4->vfptr,
                                                 UFG::ActiveAIEntityComponent::_TypeUID);
        }
      }
      else
      {
        v7 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v4);
      }
      v5 = v7;
    }
    else
    {
      v5 = 0i64;
    }
    v8 = &v3->m_pAIEntityComponent;
    if ( v3->m_pAIEntityComponent.m_pPointer )
    {
      v9 = v8->mPrev;
      v10 = v3->m_pAIEntityComponent.mNext;
      v9->mNext = v10;
      v10->mPrev = v9;
      v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
      v3->m_pAIEntityComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->m_pAIEntityComponent.mPrev;
    }
    v3->m_pAIEntityComponent.m_pPointer = (UFG::SimComponent *)&v5->vfptr;
    if ( v5 )
    {
      v11 = v5->m_SafePointerList.mNode.mPrev;
      v11->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
      v8->mPrev = v11;
      v3->m_pAIEntityComponent.mNext = &v5->m_SafePointerList.mNode;
      v5->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
    }
    v12 = (UFG::SimObjectGame *)v3->m_pActionContext->mSimObject.m_pPointer;
    if ( v12 )
    {
      v14 = v12->m_Flags;
      if ( (v14 >> 14) & 1 )
      {
        v13 = v12->m_Components.p[20].m_pComponent;
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
        v13 = v15;
      }
      else
      {
        v13 = v12->m_Components.p[20].m_pComponent;
      }
    }
    else
    {
      v13 = 0i64;
    }
    v16 = &v3->m_pTargetingSystemBaseComponent;
    if ( v3->m_pTargetingSystemBaseComponent.m_pPointer )
    {
      v17 = v16->mPrev;
      v18 = v3->m_pTargetingSystemBaseComponent.mNext;
      v17->mNext = v18;
      v18->mPrev = v17;
      v16->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v16->mPrev;
      v3->m_pTargetingSystemBaseComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->m_pTargetingSystemBaseComponent.mPrev;
    }
    v3->m_pTargetingSystemBaseComponent.m_pPointer = v13;
    if ( v13 )
    {
      v19 = v13->m_SafePointerList.mNode.mPrev;
      v19->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v16->mPrev;
      v16->mPrev = v19;
      v3->m_pTargetingSystemBaseComponent.mNext = &v13->m_SafePointerList.mNode;
      v13->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v16->mPrev;
    }
  }
  v20 = v3->m_pTargetingSystemBaseComponent.m_pPointer;
  if ( v20 )
  {
    v21 = *(UFG::SimObjectGame **)(56i64
                                 * *(unsigned __int8 *)(LOBYTE(v3->m_Track[1].vfptr) + *(_QWORD *)&v20[1].m_Flags + 8i64)
                                 + *(_QWORD *)&v20[1].m_TypeUID
                                 + 40);
    if ( v21 )
    {
      v22 = v21->m_Flags;
      if ( (v22 >> 14) & 1 )
      {
        v23 = UFG::SimObjectGame::GetComponentOfTypeHK(v21, UFG::FormationManagerComponent::_TypeUID);
      }
      else if ( (v22 & 0x8000u) == 0 )
      {
        if ( (v22 >> 13) & 1 )
        {
          v23 = UFG::SimObjectGame::GetComponentOfTypeHK(v21, UFG::FormationManagerComponent::_TypeUID);
        }
        else if ( (v22 >> 12) & 1 )
        {
          v23 = UFG::SimObjectGame::GetComponentOfTypeHK(v21, UFG::FormationManagerComponent::_TypeUID);
        }
        else
        {
          v23 = UFG::SimObject::GetComponentOfType(
                  (UFG::SimObject *)&v21->vfptr,
                  UFG::FormationManagerComponent::_TypeUID);
        }
      }
      else
      {
        v23 = UFG::SimObjectGame::GetComponentOfTypeHK(v21, UFG::FormationManagerComponent::_TypeUID);
      }
      v2 = v23;
    }
    v24 = &v3->m_pTargetFormationManagerComponent;
    if ( v3->m_pTargetFormationManagerComponent.m_pPointer )
    {
      v25 = v24->mPrev;
      v26 = v3->m_pTargetFormationManagerComponent.mNext;
      v25->mNext = v26;
      v26->mPrev = v25;
      v24->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v24->mPrev;
      v3->m_pTargetFormationManagerComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->m_pTargetFormationManagerComponent.mPrev;
    }
    v3->m_pTargetFormationManagerComponent.m_pPointer = v2;
    if ( v2 )
    {
      v27 = v2->m_SafePointerList.mNode.mPrev;
      v27->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v24->mPrev;
      v24->mPrev = v27;
      v3->m_pTargetFormationManagerComponent.mNext = &v2->m_SafePointerList.mNode;
      v2->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v24->mPrev;
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
  UFG::qNode<ITask,ITask> *v1; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<JustPerformedRunningAttackTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&JustPerformedRunningAttackTask::`vftable;
}

// File Line: 5560
// RVA: 0x346A20
void __fastcall JustPerformedRunningAttackTask::Begin(JustPerformedRunningAttackTask *this, ActionContext *action_context)
{
  JustPerformedRunningAttackTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // r8
  UFG::SimComponent *v6; // rax
  UFG::SimObjectGame *v7; // r8
  unsigned __int16 v8; // cx
  UFG::SimComponent *v9; // rax

  v2 = this;
  v3 = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
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
      v7 = *(UFG::SimObjectGame **)(56i64
                                  * *(unsigned __int8 *)(LOBYTE(v2->m_Track[1].vfptr) + *(_QWORD *)&v5[1].m_Flags + 8i64)
                                  + *(_QWORD *)&v5[1].m_TypeUID
                                  + 40);
      if ( v7 )
      {
        v8 = v7->m_Flags;
        if ( (v8 >> 14) & 1 )
        {
          v9 = v7->m_Components.p[46].m_pComponent;
        }
        else if ( (v8 & 0x8000u) == 0 )
        {
          if ( (v8 >> 13) & 1 )
          {
            v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::AttackRightsComponent::_TypeUID);
          }
          else if ( (v8 >> 12) & 1 )
          {
            v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::AttackRightsComponent::_TypeUID);
          }
          else
          {
            v9 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::AttackRightsComponent::_TypeUID);
          }
        }
        else
        {
          v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::AttackRightsComponent::_TypeUID);
        }
        if ( v9 )
          *(float *)&v9[149].m_NameUID = UFG::Metrics::msInstance.mSimTime_Temp + 3.0;
      }
    }
  }
}

// File Line: 5603
// RVA: 0x3316B0
void __fastcall RequestFormationPositionChangeTask::RequestFormationPositionChangeTask(RequestFormationPositionChangeTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v2; // [rsp+28h] [rbp+10h]
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *v3; // [rsp+28h] [rbp+10h]
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v4; // [rsp+28h] [rbp+10h]
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v5; // [rsp+28h] [rbp+10h]
  UFG::qSafePointer<UFG::SimComponent,UFG::FormationManagerComponent> *v6; // [rsp+28h] [rbp+10h]

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<RequestFormationPositionChangeTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&RequestFormationPositionChangeTask::`vftable;
  v2 = &this->m_pTransformNodeComponent;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  this->m_pTransformNodeComponent.m_pPointer = 0i64;
  v3 = &this->m_pTargetingSystemBaseComponent;
  v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  this->m_pTargetingSystemBaseComponent.m_pPointer = 0i64;
  v4 = &this->m_pTargetSimObject;
  v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  v4->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  this->m_pTargetSimObject.m_pPointer = 0i64;
  v5 = &this->m_pTargetTransformNodeComponent;
  v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v5->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  this->m_pTargetTransformNodeComponent.m_pPointer = 0i64;
  v6 = &this->m_pTargetFormationManagerComponent;
  v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  v6->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  this->m_pTargetFormationManagerComponent.m_pPointer = 0i64;
}

// File Line: 5610
// RVA: 0x33A5C0
void __fastcall RequestFormationPositionChangeTask::~RequestFormationPositionChangeTask(RequestFormationPositionChangeTask *this)
{
  RequestFormationPositionChangeTask *v1; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::FormationManagerComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v12; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *v17; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v21; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v22; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v23; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v24; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v25; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v26; // rax
  UFG::qNode<ITask,ITask> *v27; // rdx
  UFG::qNode<ITask,ITask> *v28; // rcx
  UFG::qNode<ITask,ITask> *v29; // rax

  v1 = this;
  this->vfptr = (ITaskVtbl *)&RequestFormationPositionChangeTask::`vftable;
  v2 = &this->m_pTargetFormationManagerComponent;
  if ( this->m_pTargetFormationManagerComponent.m_pPointer )
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
  v7 = &v1->m_pTargetTransformNodeComponent;
  if ( v1->m_pTargetTransformNodeComponent.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v1->m_pTargetTransformNodeComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v1->m_pTargetTransformNodeComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pTargetTransformNodeComponent.mPrev;
  }
  v1->m_pTargetTransformNodeComponent.m_pPointer = 0i64;
  v10 = v7->mPrev;
  v11 = v1->m_pTargetTransformNodeComponent.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v1->m_pTargetTransformNodeComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pTargetTransformNodeComponent.mPrev;
  v12 = &v1->m_pTargetSimObject;
  if ( v1->m_pTargetSimObject.m_pPointer )
  {
    v13 = v12->mPrev;
    v14 = v1->m_pTargetSimObject.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v12->mPrev;
    v1->m_pTargetSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->m_pTargetSimObject.mPrev;
  }
  v1->m_pTargetSimObject.m_pPointer = 0i64;
  v15 = v12->mPrev;
  v16 = v1->m_pTargetSimObject.mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v12->mPrev;
  v1->m_pTargetSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->m_pTargetSimObject.mPrev;
  v17 = &v1->m_pTargetingSystemBaseComponent;
  if ( v1->m_pTargetingSystemBaseComponent.m_pPointer )
  {
    v18 = v17->mPrev;
    v19 = v1->m_pTargetingSystemBaseComponent.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    v17->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v17->mPrev;
    v1->m_pTargetingSystemBaseComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pTargetingSystemBaseComponent.mPrev;
  }
  v1->m_pTargetingSystemBaseComponent.m_pPointer = 0i64;
  v20 = v17->mPrev;
  v21 = v1->m_pTargetingSystemBaseComponent.mNext;
  v20->mNext = v21;
  v21->mPrev = v20;
  v17->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v17->mPrev;
  v1->m_pTargetingSystemBaseComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pTargetingSystemBaseComponent.mPrev;
  v22 = &v1->m_pTransformNodeComponent;
  if ( v1->m_pTransformNodeComponent.m_pPointer )
  {
    v23 = v22->mPrev;
    v24 = v1->m_pTransformNodeComponent.mNext;
    v23->mNext = v24;
    v24->mPrev = v23;
    v22->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v22->mPrev;
    v1->m_pTransformNodeComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pTransformNodeComponent.mPrev;
  }
  v1->m_pTransformNodeComponent.m_pPointer = 0i64;
  v25 = v22->mPrev;
  v26 = v1->m_pTransformNodeComponent.mNext;
  v25->mNext = v26;
  v26->mPrev = v25;
  v22->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v22->mPrev;
  v1->m_pTransformNodeComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pTransformNodeComponent.mPrev;
  v1->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v27 = (UFG::qNode<ITask,ITask> *)&v1->mPrev;
  v28 = v1->mPrev;
  v29 = v1->mNext;
  v28->mNext = v29;
  v29->mPrev = v28;
  v27->mPrev = v27;
  v27->mNext = v27;
}

// File Line: 5615
// RVA: 0x347D30
void __fastcall RequestFormationPositionChangeTask::Begin(RequestFormationPositionChangeTask *this, ActionContext *action_context)
{
  UFG::SimObject *v2; // r8
  UFG::SimObject *v3; // rbx
  ActionContext *v4; // r14
  RequestFormationPositionChangeTask *v5; // rbp
  UFG::TransformNodeComponent *v6; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::SimObjectGame *v11; // rcx
  UFG::SimComponent *v12; // r8
  unsigned __int16 v13; // dx
  UFG::SimComponent *v14; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *v15; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rax
  UFG::SimComponent *v19; // r8
  UFG::SimObject *v20; // r8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v21; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v22; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v23; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v24; // rax
  UFG::SimObject *v25; // r8
  UFG::SimComponent *v26; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v27; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v28; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v29; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v30; // rax
  UFG::SimObjectGame *v31; // rcx
  unsigned __int16 v32; // dx
  UFG::SimComponent *v33; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::FormationManagerComponent> *v34; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v35; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v36; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v37; // rax
  unsigned __int8 *v38; // rcx
  bool v39; // zf
  int v40; // edx
  UFG::eFormationFacingType v41; // eax
  int v42; // edx
  int v43; // edx
  UFG::SimObjectGame *v44; // rcx
  unsigned __int16 v45; // dx
  UFG::AttackRightsComponent *v46; // rax
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v47; // rax
  void *(__fastcall *v48)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int); // rax
  UFG::SimComponent *v49; // rdi
  UFG::TransformNodeComponent *v50; // rsi
  float *v51; // rbx
  float v52; // xmm6_4
  __m128 v53; // xmm7
  float v54; // xmm8_4
  __m128 v55; // xmm2
  float v56; // xmm1_4
  float *v57; // rsi
  UFG::SimComponent *v58; // rdi
  UFG::SimComponent *v59; // rbx
  UFG::FormationPositionChangeRequest request; // [rsp+20h] [rbp-58h]

  this->m_pActionContext = action_context;
  v2 = action_context->mSimObject.m_pPointer;
  v3 = 0i64;
  v4 = action_context;
  v5 = this;
  if ( v2 )
    v6 = v2->m_pTransformNodeComponent;
  else
    v6 = 0i64;
  v7 = &this->m_pTransformNodeComponent;
  if ( this->m_pTransformNodeComponent.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v7->mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v7->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  }
  v7->m_pPointer = (UFG::SimComponent *)&v6->vfptr;
  if ( v6 )
  {
    v10 = v6->m_SafePointerList.mNode.mPrev;
    v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v7->mPrev = v10;
    v7->mNext = &v6->m_SafePointerList.mNode;
    v6->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  }
  v11 = (UFG::SimObjectGame *)v4->mSimObject.m_pPointer;
  if ( v11 )
  {
    v13 = v11->m_Flags;
    if ( (v13 >> 14) & 1 )
    {
      v12 = v11->m_Components.p[20].m_pComponent;
    }
    else if ( (v13 & 0x8000u) == 0 )
    {
      if ( (v13 >> 13) & 1 )
      {
        v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else if ( (v13 >> 12) & 1 )
      {
        v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else
      {
        v14 = UFG::SimObject::GetComponentOfType(
                (UFG::SimObject *)&v11->vfptr,
                UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      v12 = v14;
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
  v15 = &v5->m_pTargetingSystemBaseComponent;
  if ( v5->m_pTargetingSystemBaseComponent.m_pPointer )
  {
    v16 = v15->mPrev;
    v17 = v5->m_pTargetingSystemBaseComponent.mNext;
    v16->mNext = v17;
    v17->mPrev = v16;
    v15->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v15->mPrev;
    v5->m_pTargetingSystemBaseComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->m_pTargetingSystemBaseComponent.mPrev;
  }
  v5->m_pTargetingSystemBaseComponent.m_pPointer = v12;
  if ( v12 )
  {
    v18 = v12->m_SafePointerList.mNode.mPrev;
    v18->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v15->mPrev;
    v15->mPrev = v18;
    v5->m_pTargetingSystemBaseComponent.mNext = &v12->m_SafePointerList.mNode;
    v12->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v15->mPrev;
  }
  v19 = v5->m_pTargetingSystemBaseComponent.m_pPointer;
  if ( v19 )
  {
    v20 = *(UFG::SimObject **)(56i64
                             * *(unsigned __int8 *)(LOBYTE(v5->m_Track[1].vfptr) + *(_QWORD *)&v19[1].m_Flags + 8i64)
                             + *(_QWORD *)&v19[1].m_TypeUID
                             + 40);
    v21 = &v5->m_pTargetSimObject;
    if ( v5->m_pTargetSimObject.m_pPointer )
    {
      v22 = v21->mPrev;
      v23 = v5->m_pTargetSimObject.mNext;
      v22->mNext = v23;
      v23->mPrev = v22;
      v21->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v21->mPrev;
      v5->m_pTargetSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->m_pTargetSimObject.mPrev;
    }
    v5->m_pTargetSimObject.m_pPointer = v20;
    if ( v20 )
    {
      v24 = v20->m_SafePointerList.mNode.mPrev;
      v24->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v21->mPrev;
      v21->mPrev = v24;
      v5->m_pTargetSimObject.mNext = &v20->m_SafePointerList.mNode;
      v20->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v21->mPrev;
    }
    v25 = v5->m_pTargetSimObject.m_pPointer;
    if ( v25 )
      v26 = (UFG::SimComponent *)&v25->m_pTransformNodeComponent->vfptr;
    else
      v26 = 0i64;
    v27 = &v5->m_pTargetTransformNodeComponent;
    if ( v5->m_pTargetTransformNodeComponent.m_pPointer )
    {
      v28 = v27->mPrev;
      v29 = v5->m_pTargetTransformNodeComponent.mNext;
      v28->mNext = v29;
      v29->mPrev = v28;
      v27->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v27->mPrev;
      v5->m_pTargetTransformNodeComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->m_pTargetTransformNodeComponent.mPrev;
    }
    v5->m_pTargetTransformNodeComponent.m_pPointer = v26;
    if ( v26 )
    {
      v30 = v26->m_SafePointerList.mNode.mPrev;
      v30->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v27->mPrev;
      v27->mPrev = v30;
      v5->m_pTargetTransformNodeComponent.mNext = &v26->m_SafePointerList.mNode;
      v26->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v27->mPrev;
    }
    v31 = (UFG::SimObjectGame *)v5->m_pTargetSimObject.m_pPointer;
    if ( v31 )
    {
      v32 = v31->m_Flags;
      if ( (v32 >> 14) & 1 )
      {
        v33 = UFG::SimObjectGame::GetComponentOfTypeHK(v31, UFG::FormationManagerComponent::_TypeUID);
      }
      else if ( (v32 & 0x8000u) == 0 )
      {
        if ( (v32 >> 13) & 1 )
        {
          v33 = UFG::SimObjectGame::GetComponentOfTypeHK(v31, UFG::FormationManagerComponent::_TypeUID);
        }
        else if ( (v32 >> 12) & 1 )
        {
          v33 = UFG::SimObjectGame::GetComponentOfTypeHK(v31, UFG::FormationManagerComponent::_TypeUID);
        }
        else
        {
          v33 = UFG::SimObject::GetComponentOfType(
                  (UFG::SimObject *)&v31->vfptr,
                  UFG::FormationManagerComponent::_TypeUID);
        }
      }
      else
      {
        v33 = UFG::SimObjectGame::GetComponentOfTypeHK(v31, UFG::FormationManagerComponent::_TypeUID);
      }
      v19 = v33;
    }
    else
    {
      v19 = 0i64;
    }
    v34 = &v5->m_pTargetFormationManagerComponent;
    if ( v5->m_pTargetFormationManagerComponent.m_pPointer )
    {
      v35 = v34->mPrev;
      v36 = v5->m_pTargetFormationManagerComponent.mNext;
      v35->mNext = v36;
      v36->mPrev = v35;
      v34->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v34->mPrev;
      v5->m_pTargetFormationManagerComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->m_pTargetFormationManagerComponent.mPrev;
    }
    v5->m_pTargetFormationManagerComponent.m_pPointer = v19;
    if ( v19 )
    {
      v37 = v19->m_SafePointerList.mNode.mPrev;
      v37->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v34->mPrev;
      v34->mPrev = v37;
      v5->m_pTargetFormationManagerComponent.mNext = &v19->m_SafePointerList.mNode;
      v19->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v34->mPrev;
    }
  }
  if ( v5->m_pTargetFormationManagerComponent.m_pPointer && v5->m_pTransformNodeComponent.m_pPointer )
  {
    v38 = (unsigned __int8 *)v5->m_Track;
    request.m_Clockwise = 0;
    v39 = v38[60] == 0;
    v40 = v38[59];
    request.m_DesiredSpeed = v38[57];
    v41 = v38[58];
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
            v44 = (UFG::SimObjectGame *)v5->m_pTargetSimObject.m_pPointer;
            request.m_Clockwise = 0;
            if ( v44 )
            {
              v45 = v44->m_Flags;
              if ( (v45 >> 14) & 1 )
              {
                v46 = (UFG::AttackRightsComponent *)v44->m_Components.p[46].m_pComponent;
              }
              else if ( (v45 & 0x8000u) == 0 )
              {
                if ( (v45 >> 13) & 1 )
                  v46 = (UFG::AttackRightsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        v44,
                                                        UFG::AttackRightsComponent::_TypeUID);
                else
                  v46 = (UFG::AttackRightsComponent *)((v45 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                           v44,
                                                                           UFG::AttackRightsComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v44->vfptr, UFG::AttackRightsComponent::_TypeUID));
              }
              else
              {
                v46 = (UFG::AttackRightsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      v44,
                                                      UFG::AttackRightsComponent::_TypeUID);
              }
            }
            else
            {
              v46 = 0i64;
            }
            if ( v46 )
            {
              v47 = UFG::AttackRightsComponent::GetNextAttacker(v46, 0, (__int64)v19);
              if ( v47 )
              {
                v48 = v47[27].__vecDelDtor;
                if ( v48 )
                  v3 = (UFG::SimObject *)*((_QWORD *)v48 + 5);
              }
              if ( v3 )
              {
                if ( v3 != v4->mSimObject.m_pPointer )
                {
                  v49 = v5->m_pTransformNodeComponent.m_pPointer;
                  v50 = v3->m_pTransformNodeComponent;
                  if ( v49 )
                  {
                    if ( v5->m_pTargetTransformNodeComponent.m_pPointer && v50 )
                    {
                      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v49);
                      v51 = (float *)v5->m_pTargetTransformNodeComponent.m_pPointer;
                      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v5->m_pTargetTransformNodeComponent.m_pPointer);
                      UFG::TransformNodeComponent::UpdateWorldTransform(v50);
                      v53 = (__m128)HIDWORD(v49[2].m_BoundComponentHandles.mNode.mPrev);
                      v52 = *(float *)&v49[2].m_BoundComponentHandles.mNode.mPrev - v51[44];
                      v53.m128_f32[0] = v53.m128_f32[0] - v51[45];
                      v54 = *(float *)&v49[2].m_BoundComponentHandles.mNode.mNext - v51[46];
                      v55 = v53;
                      v55.m128_f32[0] = (float)((float)(v53.m128_f32[0] * v53.m128_f32[0]) + (float)(v52 * v52))
                                      + (float)(v54 * v54);
                      if ( v55.m128_f32[0] == 0.0 )
                        v56 = 0.0;
                      else
                        v56 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v55));
                      request.m_Clockwise = (float)((float)((float)((float)((float)((float)(v54 * v56)
                                                                                  * UFG::qVector3::msDirUp.x)
                                                                          - (float)((float)(v52 * v56)
                                                                                  * UFG::qVector3::msDirUp.z))
                                                                  * (float)(v53.m128_f32[0] * v56))
                                                          + (float)((float)((float)((float)(v53.m128_f32[0] * v56)
                                                                                  * UFG::qVector3::msDirUp.z)
                                                                          - (float)((float)(v54 * v56)
                                                                                  * UFG::qVector3::msDirUp.y))
                                                                  * (float)(v52 * v56)))
                                                  + (float)((float)((float)((float)(v52 * v56) * UFG::qVector3::msDirUp.y)
                                                                  - (float)((float)(v53.m128_f32[0] * v56)
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
          v57 = (float *)v5->m_pTargetTransformNodeComponent.m_pPointer;
          UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v5->m_pTargetTransformNodeComponent.m_pPointer);
          v58 = v5->m_pTargetTransformNodeComponent.m_pPointer;
          UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v5->m_pTargetTransformNodeComponent.m_pPointer);
          v59 = v5->m_pTransformNodeComponent.m_pPointer;
          UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v5->m_pTransformNodeComponent.m_pPointer);
          request.m_Clockwise = (float)((float)((float)((float)(*((float *)&v59[2].m_BoundComponentHandles.mNode.mPrev
                                                                + 1)
                                                              - *((float *)&v58[2].m_BoundComponentHandles.mNode.mPrev
                                                                + 1))
                                                      * v57[37])
                                              + (float)((float)(*(float *)&v59[2].m_BoundComponentHandles.mNode.mPrev
                                                              - *(float *)&v58[2].m_BoundComponentHandles.mNode.mPrev)
                                                      * v57[36]))
                                      + (float)(v57[38] * 0.0)) < 0.0;
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
      (UFG::FormationManagerComponent *)v5->m_pTargetFormationManagerComponent.m_pPointer,
      v4->mSimObject.m_pPointer,
      &request);
  }
}

// File Line: 5751
// RVA: 0x330390
void __fastcall LeaveGroupTask::LeaveGroupTask(LeaveGroupTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
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
  UFG::qNode<ITask,ITask> *v1; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v2; // [rsp+28h] [rbp+10h]

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<SelectSuitableVehicleTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&SelectSuitableVehicleTask::`vftable;
  this->m_pActionContext = 0i64;
  v2 = &this->m_pVehicle;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  this->m_pVehicle.m_pPointer = 0i64;
}

// File Line: 5780
// RVA: 0x33AAA0
void __fastcall SelectSuitableVehicleTask::~SelectSuitableVehicleTask(SelectSuitableVehicleTask *this)
{
  SelectSuitableVehicleTask *v1; // r8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rdx
  UFG::qNode<ITask,ITask> *v8; // rcx
  UFG::qNode<ITask,ITask> *v9; // rax

  v1 = this;
  this->vfptr = (ITaskVtbl *)&SelectSuitableVehicleTask::`vftable;
  v2 = &this->m_pVehicle;
  if ( this->m_pVehicle.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  }
  v2->m_pPointer = 0i64;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v1->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v7 = (UFG::qNode<ITask,ITask> *)&v1->mPrev;
  v8 = v1->mPrev;
  v9 = v1->mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v7->mPrev = v7;
  v7->mNext = v7;
}

// File Line: 5789
// RVA: 0x3485D0
void __fastcall SelectSuitableVehicleTask::Begin(SelectSuitableVehicleTask *this, ActionContext *action_context)
{
  UFG::SimObject *v2; // rax
  ITrack *v3; // rdx
  SelectSuitableVehicleTask *v4; // rbx
  bool v5; // zf
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v6; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::SimObject *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qList<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList,1,0> *v11; // rcx
  UFG::SelectSuitableVehicle::Params params; // [rsp+20h] [rbp-28h]

  v2 = this->m_pVehicle.m_pPointer;
  this->m_pActionContext = action_context;
  params.pActionContext = action_context;
  v3 = this->m_Track;
  params.pVehicle = v2;
  v4 = this;
  LODWORD(v2) = v3[1].mResourceOwner;
  v5 = BYTE4(v3[1].vfptr) == 0;
  params.maxSearchRadius = *(float *)&v3[1].vfptr;
  params.filterClassSymbol.mUID = (unsigned int)v2;
  params.ignoreMeshTest = !v5;
  UFG::SelectSuitableVehicle::SelectVehicle(&params);
  v6 = &v4->m_pVehicle;
  if ( v6->m_pPointer )
  {
    v7 = v6->mPrev;
    v8 = v6->mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->mPrev;
    v6->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  }
  v9 = params.pVehicle;
  v6->m_pPointer = params.pVehicle;
  if ( v9 )
  {
    v10 = v9->m_SafePointerList.mNode.mPrev;
    v11 = &v9->m_SafePointerList;
    v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->mPrev;
    v6->mPrev = v10;
    v6->mNext = &v11->mNode;
    v11->mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  }
}

// File Line: 5810
// RVA: 0x392D50
char __fastcall SelectSuitableVehicleTask::Update(SelectSuitableVehicleTask *this, float timestep)
{
  ITrack *v2; // rdx
  SelectSuitableVehicleTask *v3; // rbx
  bool v4; // zf
  UFG::SimObject *v5; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v6; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::SimObject *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qList<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList,1,0> *v11; // rcx
  UFG::SelectSuitableVehicle::Params params; // [rsp+20h] [rbp-28h]

  v2 = this->m_Track;
  v3 = this;
  v4 = BYTE4(v2[1].vfptr) == 0;
  params.pActionContext = this->m_pActionContext;
  v5 = this->m_pVehicle.m_pPointer;
  params.maxSearchRadius = *(float *)&v2[1].vfptr;
  params.pVehicle = v5;
  params.filterClassSymbol.mUID = (unsigned int)v2[1].mResourceOwner;
  params.ignoreMeshTest = !v4;
  UFG::SelectSuitableVehicle::Update(&params);
  v6 = &v3->m_pVehicle;
  if ( v6->m_pPointer )
  {
    v7 = v6->mPrev;
    v8 = v6->mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->mPrev;
    v6->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  }
  v9 = params.pVehicle;
  v6->m_pPointer = params.pVehicle;
  if ( v9 )
  {
    v10 = v9->m_SafePointerList.mNode.mPrev;
    v11 = &v9->m_SafePointerList;
    v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->mPrev;
    v6->mPrev = v10;
    v6->mNext = &v11->mNode;
    v11->mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  }
  return 1;
}

// File Line: 5832
// RVA: 0x355480
void __fastcall SelectSuitableVehicleTask::End(SelectSuitableVehicleTask *this)
{
  ITrack *v1; // rdx
  UFG::SimObject *v2; // rdi
  bool v3; // zf
  float v4; // xmm0_4
  unsigned int v5; // eax
  SelectSuitableVehicleTask *v6; // rbx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v7; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::SelectSuitableVehicle::Params params; // [rsp+20h] [rbp-28h]

  v1 = this->m_Track;
  v2 = this->m_pVehicle.m_pPointer;
  v3 = BYTE4(v1[1].vfptr) == 0;
  v4 = *(float *)&v1[1].vfptr;
  params.pActionContext = this->m_pActionContext;
  params.maxSearchRadius = v4;
  v5 = (unsigned int)v1[1].mResourceOwner;
  v6 = this;
  params.ignoreMeshTest = !v3;
  params.pVehicle = v2;
  params.filterClassSymbol.mUID = v5;
  UFG::SelectSuitableVehicle::Cleanup(&params);
  v7 = &v6->m_pVehicle;
  if ( v7->m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v7->mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v7->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  }
  v7->m_pPointer = v2;
  if ( v2 )
  {
    v10 = v2->m_SafePointerList.mNode.mPrev;
    v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v7->mPrev = v10;
    v7->mNext = &v2->m_SafePointerList.mNode;
    v2->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  }
}

// File Line: 5855
// RVA: 0x32E2E0
void __fastcall FireWeaponTask::FireWeaponTask(FireWeaponTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<FireWeaponTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&FireWeaponTask::`vftable;
  v2 = &this->m_pAIEntityComponent;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  this->m_pAIEntityComponent.m_pPointer = 0i64;
  this->m_pActionContext = 0i64;
  if ( this->m_pAIEntityComponent.m_pPointer )
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

// File Line: 5863
// RVA: 0x3368B0
void __fastcall FireWeaponTask::~FireWeaponTask(FireWeaponTask *this)
{
  FireWeaponTask *v1; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rdx
  UFG::qNode<ITask,ITask> *v8; // rcx
  UFG::qNode<ITask,ITask> *v9; // rax

  v1 = this;
  this->vfptr = (ITaskVtbl *)&FireWeaponTask::`vftable;
  v2 = &this->m_pAIEntityComponent;
  if ( this->m_pAIEntityComponent.m_pPointer )
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
  v1->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v7 = (UFG::qNode<ITask,ITask> *)&v1->mPrev;
  v8 = v1->mPrev;
  v9 = v1->mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v7->mPrev = v7;
  v7->mNext = v7;
}

// File Line: 5868
// RVA: 0x3449F0
void __fastcall FireWeaponTask::Begin(FireWeaponTask *this, ActionContext *action_context)
{
  FireWeaponTask *v2; // rbx
  UFG::SimObjectCVBase *v3; // rcx
  UFG::ActiveAIEntityComponent *v4; // r8
  unsigned __int16 v5; // dx
  UFG::ActiveAIEntityComponent *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::ActiveAIEntityComponent> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  ITrack *v11; // rcx
  int v12; // esi
  int v13; // edi
  float v14; // xmm7_4
  float v15; // xmm6_4
  ITrack *v16; // rcx
  float v17; // xmm0_4
  ExpressionParameterFloat *v18; // rcx
  float v19; // xmm0_4
  ITrack *v20; // rcx
  float v21; // xmm0_4
  ExpressionParameterFloat *v22; // rcx

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
        v6 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v3);
      }
      else if ( (v5 & 0x8000u) == 0 )
      {
        if ( (v5 >> 13) & 1 )
        {
          v6 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)&v3->vfptr,
                                                 UFG::ActiveAIEntityComponent::_TypeUID);
        }
        else if ( (v5 >> 12) & 1 )
        {
          v6 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)&v3->vfptr,
                                                 UFG::ActiveAIEntityComponent::_TypeUID);
        }
        else
        {
          v6 = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                 (UFG::SimObject *)&v3->vfptr,
                                                 UFG::ActiveAIEntityComponent::_TypeUID);
        }
      }
      else
      {
        v6 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v3);
      }
      v4 = v6;
    }
    else
    {
      v4 = 0i64;
    }
    v7 = &v2->m_pAIEntityComponent;
    if ( v2->m_pAIEntityComponent.m_pPointer )
    {
      v8 = v7->mPrev;
      v9 = v2->m_pAIEntityComponent.mNext;
      v8->mNext = v9;
      v9->mPrev = v8;
      v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
      v2->m_pAIEntityComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pAIEntityComponent.mPrev;
    }
    v2->m_pAIEntityComponent.m_pPointer = (UFG::SimComponent *)&v4->vfptr;
    if ( v4 )
    {
      v10 = v4->m_SafePointerList.mNode.mPrev;
      v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
      v7->mPrev = v10;
      v2->m_pAIEntityComponent.mNext = &v4->m_SafePointerList.mNode;
      v4->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    }
  }
  v11 = v2->m_Track;
  v2->m_NumShotsFired = 0;
  v2->m_TimeOfNextShot = -99999.0;
  v2->m_TimeToLetGoOfTrigger = -1.0;
  v12 = ExpressionParameterInt::operator long((ExpressionParameterInt *)&v11[1]);
  v13 = ExpressionParameterInt::operator long((ExpressionParameterInt *)&v2->m_Track[1].mMasterRate);
  v14 = ExpressionParameterFloat::operator float((ExpressionParameterFloat *)((char *)&v2->m_Track[3].mMasterRate + 8));
  v15 = ExpressionParameterFloat::operator float((ExpressionParameterFloat *)&v2->m_Track[4]);
  if ( v13 > v12 )
    v13 = v12 + (unsigned __int64)UFG::qRandom(v13 - v12 + 1, &UFG::qDefaultSeed);
  v16 = v2->m_Track;
  v2->m_NumShotsToFire = v13;
  v17 = ExpressionParameterFloat::operator float((ExpressionParameterFloat *)&v16[1].mTimeBegin);
  v18 = (ExpressionParameterFloat *)&v2->m_Track[2].m_TrackClassNameUID;
  v2->m_MinTimeBetweenShots = v17 * v14;
  v19 = ExpressionParameterFloat::operator float(v18);
  v20 = v2->m_Track;
  v2->m_MaxTimeBetweenShots = v19 * v14;
  if ( BYTE4(v20[4].mMasterRate.text.mOffset) )
  {
    v21 = ExpressionParameterFloat::operator float((ExpressionParameterFloat *)((char *)&v20[2].mMasterRate + 16));
    v22 = (ExpressionParameterFloat *)&v2->m_Track[3].mResourceOwner;
    v2->m_MinTimeToHoldTrigger = v21 * v15;
    v2->m_MaxTimeToHoldTrigger = ExpressionParameterFloat::operator float(v22) * v15;
  }
  else
  {
    *(_QWORD *)&v2->m_MinTimeToHoldTrigger = 0i64;
  }
}

// File Line: 5906
// RVA: 0x38EA40
bool __fastcall FireWeaponTask::Update(FireWeaponTask *this, float timestep)
{
  FireWeaponTask *v2; // rbx
  float v3; // xmm0_4
  float v4; // xmm6_4
  float v5; // xmm0_4
  UFG::SimObjectCVBase *v6; // rcx
  UFG::AICharacterControllerBaseComponent *v7; // rcx
  unsigned __int16 v8; // dx
  UFG::AICharacterControllerBaseComponent *v9; // rax
  unsigned int v10; // edx
  bool v11; // zf

  v2 = this;
  if ( !this->m_pAIEntityComponent.m_pPointer )
  {
    this->m_NumShotsToFire = -2;
    return v2->m_NumShotsFired < v2->m_NumShotsToFire;
  }
  v3 = this->m_TimeToLetGoOfTrigger;
  v4 = UFG::Metrics::msInstance.mSimTime_Temp;
  if ( v3 > 0.0 )
  {
    if ( UFG::Metrics::msInstance.mSimTime_Temp < v3 )
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
                                   + v4;
LABEL_6:
      v6 = (UFG::SimObjectCVBase *)v2->m_pActionContext->mSimObject.m_pPointer;
      if ( !v6 )
      {
        v7 = 0i64;
LABEL_21:
        Intention::Set(&v7->m_Intention, v2->m_Track[4].mMasterRate.text.mOffset, 0.0);
        return v2->m_NumShotsFired < v2->m_NumShotsToFire;
      }
      v8 = v6->m_Flags;
      if ( (v8 >> 14) & 1 || (v8 & 0x8000u) != 0 )
      {
        v9 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v6);
      }
      else
      {
        if ( (v8 >> 13) & 1 )
        {
          v10 = UFG::AICharacterControllerBaseComponent::_TypeUID;
        }
        else
        {
          v11 = ((v8 >> 12) & 1) == 0;
          v10 = UFG::AICharacterControllerBaseComponent::_TypeUID;
          if ( v11 )
          {
            v9 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                              (UFG::SimObject *)&v6->vfptr,
                                                              UFG::AICharacterControllerBaseComponent::_TypeUID);
            goto LABEL_20;
          }
        }
        v9 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          (UFG::SimObjectGame *)&v6->vfptr,
                                                          v10);
      }
LABEL_20:
      v7 = v9;
      goto LABEL_21;
    }
LABEL_5:
    v5 = UFG::GetRandomNumberInRange(this->m_MinTimeBetweenShots, this->m_MaxTimeBetweenShots);
    ++v2->m_NumShotsFired;
    v2->m_TimeOfNextShot = v5 + v4;
    goto LABEL_6;
  }
  return v2->m_NumShotsFired < v2->m_NumShotsToFire;
}

// File Line: 5979
// RVA: 0x32B2A0
void __fastcall AICoverSearchTask::AICoverSearchTask(AICoverSearchTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<AICoverSearchTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&AICoverSearchTask::`vftable;
}

// File Line: 5991
// RVA: 0x342F60
void __fastcall AICoverSearchTask::Begin(AICoverSearchTask *this, ActionContext *action_context)
{
  AICoverSearchTask *v2; // rbp
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rax
  UFG::AICoverComponent *v6; // r15
  __int64 v7; // rbx
  UFG::SimObjectGame *v8; // rcx
  UFG::TransformNodeComponent *v9; // rsi
  UFG::SimComponent *v10; // r8
  unsigned __int16 v11; // dx
  UFG::SimComponent *v12; // rax
  UFG::SimObjectGame *v13; // rdi
  UFG::allocator::free_link *v14; // rax
  UFG::allocator::free_link *v15; // rbx
  UFG::SimObject *v16; // rdx
  UFG::allocator::free_link *v17; // rcx
  UFG::allocator::free_link *v18; // rax
  UFG::allocator::free_link *v19; // rax
  unsigned __int16 v20; // cx
  UFG::AICoverComponent *v21; // rax
  UFG::AICoverComponent *v22; // r14
  float v23; // xmm9_4
  float v24; // xmm10_4
  float v25; // xmm11_4
  UFG::SimObject *v26; // rax
  float v27; // xmm6_4
  float v28; // xmm7_4
  float v29; // xmm8_4
  unsigned __int16 v30; // cx
  UFG::AimingBaseComponent *v31; // rax
  __int64 v32; // r13
  unsigned int v33; // esi
  unsigned int v34; // edx
  unsigned int v35; // edx
  signed __int64 v36; // rcx
  UFG::allocator::free_link *v37; // rax
  float v38; // xmm1_4
  float v39; // xmm2_4
  bool v40; // zf
  UFG::qSymbolUC *v41; // rax
  char *v42; // rax
  UFG::qVector3 vAimDirection; // [rsp+28h] [rbp-B0h]
  UFG::qVector3 raycastPosition; // [rsp+38h] [rbp-A0h]
  UFG::allocator::free_link *result; // [rsp+E0h] [rbp+8h]
  UFG::allocator::free_link *v46; // [rsp+E8h] [rbp+10h]

  v2 = this;
  this->m_pActionContext = action_context;
  v3 = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v5 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::AICoverComponent::_TypeUID)) : (v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AICoverComponent::_TypeUID))) : (v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AICoverComponent::_TypeUID))) : (v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AICoverComponent::_TypeUID))) : (v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AICoverComponent::_TypeUID)),
        (v6 = (UFG::AICoverComponent *)v5) != 0i64) )
  {
    v7 = LOBYTE(v2->m_Track[1].vfptr);
    v8 = (UFG::SimObjectGame *)v2->m_pActionContext->mSimObject.m_pPointer;
    v9 = 0i64;
    if ( v8 )
    {
      v11 = v8->m_Flags;
      if ( (v11 >> 14) & 1 )
      {
        v10 = v8->m_Components.p[20].m_pComponent;
      }
      else if ( (v11 & 0x8000u) == 0 )
      {
        if ( (v11 >> 13) & 1 )
        {
          v12 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        else if ( (v11 >> 12) & 1 )
        {
          v12 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        else
        {
          v12 = UFG::SimObject::GetComponentOfType(
                  (UFG::SimObject *)&v8->vfptr,
                  UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        v10 = v12;
      }
      else
      {
        v10 = v8->m_Components.p[20].m_pComponent;
      }
    }
    else
    {
      v10 = 0i64;
    }
    v13 = *(UFG::SimObjectGame **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v10[1].m_Flags + v7 + 8)
                                 + *(_QWORD *)&v10[1].m_TypeUID
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
      v16 = v2->m_pActionContext->mSimObject.m_pPointer;
      if ( v15[2].mNext )
      {
        v17 = v15->mNext;
        v18 = v15[1].mNext;
        v17[1].mNext = v18;
        v18->mNext = v17;
        v15->mNext = v15;
        v15[1].mNext = v15;
      }
      v15[2].mNext = (UFG::allocator::free_link *)v16;
      if ( v16 )
      {
        v19 = (UFG::allocator::free_link *)v16->m_SafePointerList.mNode.mPrev;
        v19[1].mNext = v15;
        v15->mNext = v19;
        v15[1].mNext = (UFG::allocator::free_link *)&v16->m_SafePointerList;
        v16->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)v15;
      }
      UFG::ComputeObjectRaycastPosition((UFG::SimObject *)&v13->vfptr, &raycastPosition);
      v20 = v13->m_Flags;
      if ( (v20 >> 14) & 1 )
      {
        v21 = (UFG::AICoverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::AICoverComponent::_TypeUID);
      }
      else if ( (v20 & 0x8000u) == 0 )
      {
        if ( (v20 >> 13) & 1 )
        {
          v21 = (UFG::AICoverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::AICoverComponent::_TypeUID);
        }
        else if ( (v20 >> 12) & 1 )
        {
          v21 = (UFG::AICoverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::AICoverComponent::_TypeUID);
        }
        else
        {
          v21 = (UFG::AICoverComponent *)UFG::SimObject::GetComponentOfType(
                                           (UFG::SimObject *)&v13->vfptr,
                                           UFG::AICoverComponent::_TypeUID);
        }
      }
      else
      {
        v21 = (UFG::AICoverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::AICoverComponent::_TypeUID);
      }
      v22 = v21;
      v23 = raycastPosition.z;
      v24 = raycastPosition.y;
      v25 = raycastPosition.x;
      if ( v21 && UFG::AICoverComponent::IsInCover(v21) )
      {
        v26 = v22->m_pSimTargetPopout.m_pPointer;
        if ( v26 )
          v9 = v26->m_pTransformNodeComponent;
        UFG::TransformNodeComponent::UpdateWorldTransform(v9);
        v27 = v9->mWorldTransform.v3.x;
        v28 = v9->mWorldTransform.v3.y;
        v29 = v9->mWorldTransform.v3.z;
      }
      else
      {
        v27 = v25;
        v28 = v24;
        v29 = v23;
      }
      v30 = v13->m_Flags;
      if ( (v30 >> 14) & 1 )
      {
        v31 = (UFG::AimingBaseComponent *)v13->m_Components.p[47].m_pComponent;
      }
      else if ( (v30 & 0x8000u) == 0 )
      {
        if ( (v30 >> 13) & 1 )
        {
          v31 = (UFG::AimingBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              v13,
                                              UFG::AimingBaseComponent::_TypeUID);
        }
        else if ( (v30 >> 12) & 1 )
        {
          v31 = (UFG::AimingBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              v13,
                                              UFG::AimingBaseComponent::_TypeUID);
        }
        else
        {
          v31 = (UFG::AimingBaseComponent *)UFG::SimObject::GetComponentOfType(
                                              (UFG::SimObject *)&v13->vfptr,
                                              UFG::AimingBaseComponent::_TypeUID);
        }
      }
      else
      {
        v31 = (UFG::AimingBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                            v13,
                                            UFG::AimingBaseComponent::_TypeUID);
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
      v32 = LODWORD(v15[12].mNext);
      v33 = v32 + 1;
      v34 = HIDWORD(v15[12].mNext);
      if ( (signed int)v32 + 1 > v34 )
      {
        if ( v34 )
          v35 = 2 * v34;
        else
          v35 = 1;
        for ( ; v35 < v33; v35 *= 2 )
          ;
        if ( v35 - v33 > 0x10000 )
          v35 = v32 + 65537;
        UFG::qArray<UFG::AICoverSearchParams::HostileTarget,0>::Reallocate(
          (UFG::qArray<UFG::AICoverSearchParams::HostileTarget,0> *)&v15[12],
          v35,
          "qArray.Add");
      }
      LODWORD(v15[12].mNext) = v33;
      v36 = 9 * v32;
      v37 = v15[13].mNext;
      *((float *)&v37->mNext + v36) = v27;
      *((float *)&v37->mNext + v36 + 1) = v28;
      *((float *)&v37[1].mNext + v36) = v29;
      *((float *)&v37[1].mNext + v36 + 1) = v25;
      *((float *)&v37[2].mNext + v36) = v24;
      *((float *)&v37[2].mNext + v36 + 1) = v23;
      v38 = vAimDirection.y;
      v39 = vAimDirection.z;
      *((_DWORD *)&v37[3].mNext + v36) = LODWORD(vAimDirection.x);
      *((float *)&v37[3].mNext + v36 + 1) = v38;
      *((float *)&v37[4].mNext + v36) = v39;
      AICoverSearchTask::AddExtraHostiles(v2, (UFG::AICoverSearchParams *)v15, (UFG::SimObject *)&v13->vfptr);
      LODWORD(v15[3].mNext) = HIDWORD(v2->m_Track[1].vfptr);
      HIDWORD(v15[3].mNext) = HIDWORD(v2->m_Track[1].vfptr);
      LODWORD(v15[4].mNext) = v2->m_Track[1].mResourceOwner;
      HIDWORD(v15[4].mNext) = HIDWORD(v2->m_Track[1].mResourceOwner);
      LODWORD(v15[5].mNext) = v2->m_Track[1].m_TrackClassNameUID;
      HIDWORD(v15[5].mNext) = *(_DWORD *)&v2->m_Track[1].mBreakPoint;
      LODWORD(v15[6].mNext) = v2->m_Track[1].mMasterRate.text.mOffset;
      HIDWORD(v15[6].mNext) = HIDWORD(v2->m_Track[1].mMasterRate.text.mOffset);
      LODWORD(v15[7].mNext) = v2->m_Track[1].mMasterRate.expression.mOffset;
      HIDWORD(v15[7].mNext) = HIDWORD(v2->m_Track[1].mMasterRate.expression.mOffset);
      *(float *)&v15[8].mNext = v2->m_Track[1].mMasterRate.value;
      HIDWORD(v15[8].mNext) = *((_DWORD *)&v2->m_Track[1].mMasterRate.value + 1);
      LOBYTE(v15[9].mNext) = LOBYTE(v2->m_Track[1].mTimeBegin) != 0;
      HIDWORD(v15[9].mNext) = LODWORD(v2->m_Track[1].mTimeEnd);
      LOBYTE(v15[10].mNext) = LOBYTE(v2->m_Track[2].vfptr) != 0;
      BYTE1(v15[10].mNext) = BYTE1(v2->m_Track[2].vfptr) != 0;
      BYTE2(v15[10].mNext) = BYTE2(v2->m_Track[2].vfptr) != 0;
      BYTE3(v15[10].mNext) = BYTE3(v2->m_Track[2].vfptr) != 0;
      HIDWORD(v15[10].mNext) = HIDWORD(v2->m_Track[2].vfptr);
      LODWORD(v15[11].mNext) = v2->m_Track[2].mResourceOwner;
      v2->m_bSearchStarted = UFG::AICoverComponent::StartCoverSearch(v6, (UFG::AICoverSearchParams *)v15, 1);
      v40 = LODWORD(v15[14].mNext)-- == 1;
      if ( v40 )
      {
        UFG::AICoverSearchParams::~AICoverSearchParams((UFG::AICoverSearchParams *)v15);
        operator delete[](v15);
      }
    }
    else
    {
      v2->m_bSearchStarted = 0;
    }
  }
  else
  {
    v2->m_bSearchStarted = 0;
    v41 = (UFG::qSymbolUC *)UFG::qSymbol::qSymbol(
                              (UFG::qWiseSymbol *)&result,
                              v2->m_pActionContext->mSimObject.m_pPointer->m_pSceneObj->m_NameUID);
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
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  unsigned int v5; // edx
  bool v6; // zf

  if ( !this->m_bSearchStarted )
    return 0;
  v3 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
  if ( !v3 )
    return MEMORY[0x50] != 0i64;
  v4 = v3->m_Flags;
  if ( (v4 >> 14) & 1 || (v4 & 0x8000u) != 0 || (v4 >> 13) & 1 )
  {
    v5 = UFG::AICoverComponent::_TypeUID;
    return UFG::SimObjectGame::GetComponentOfTypeHK(v3, v5)[1].m_SafePointerList.mNode.mNext != 0i64;
  }
  v6 = ((v4 >> 12) & 1) == 0;
  v5 = UFG::AICoverComponent::_TypeUID;
  if ( !v6 )
    return UFG::SimObjectGame::GetComponentOfTypeHK(v3, v5)[1].m_SafePointerList.mNode.mNext != 0i64;
  return UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::AICoverComponent::_TypeUID)[1].m_SafePointerList.mNode.mNext != 0i64;
}

// File Line: 6122
// RVA: 0x354CF0
void __fastcall AICoverSearchTask::End(AICoverSearchTask *this)
{
  UFG::SimObjectGame *v1; // rcx
  unsigned __int16 v2; // dx
  UFG::AICoverComponent *v3; // rax

  v1 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
  if ( v1 )
  {
    v2 = v1->m_Flags;
    if ( (v2 >> 14) & 1 )
    {
      v3 = (UFG::AICoverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::AICoverComponent::_TypeUID);
    }
    else if ( (v2 & 0x8000u) == 0 )
    {
      if ( (v2 >> 13) & 1 )
      {
        v3 = (UFG::AICoverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::AICoverComponent::_TypeUID);
      }
      else if ( (v2 >> 12) & 1 )
      {
        v3 = (UFG::AICoverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::AICoverComponent::_TypeUID);
      }
      else
      {
        v3 = (UFG::AICoverComponent *)UFG::SimObject::GetComponentOfType(
                                        (UFG::SimObject *)&v1->vfptr,
                                        UFG::AICoverComponent::_TypeUID);
      }
    }
    else
    {
      v3 = (UFG::AICoverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::AICoverComponent::_TypeUID);
    }
    if ( v3 )
    {
      if ( v3->m_pQuery )
        UFG::AICoverComponent::CancelQuery(v3);
    }
  }
}

// File Line: 6145
// RVA: 0x340280
void __fastcall AICoverSearchTask::AddExtraHostiles(AICoverSearchTask *this, UFG::AICoverSearchParams *pSearchParams, UFG::SimObject *pIgnoreObject)
{
  UFG::SimObject *v3; // rdi
  UFG::AICoverSearchParams *v4; // rsi
  AICoverSearchTask *v5; // r13
  UFG::SimObject *v6; // rcx
  UFG::ActiveAIEntityComponent *v7; // r12
  UFG::TransformNodeComponent *v8; // rcx
  UFG::SimObjectCVBase *v9; // rcx
  unsigned __int16 v10; // dx
  UFG::ActiveAIEntityComponent *v11; // rax
  UFG::NearbyCharacterManager *v12; // r8
  __int64 **v13; // rax
  UFG::qVector3 *v14; // rcx
  _QWORD *v15; // rdx
  __int64 v16; // rcx
  _QWORD *v17; // rax
  UFG::NearbyCharacterManager *v18; // rcx
  __int64 *v19; // rdx
  __int64 **v20; // rax
  signed __int64 i; // r14
  _QWORD *v22; // rbx
  UFG::SimObjectGame *v23; // rbx
  unsigned __int16 v24; // cx
  UFG::SimComponent *v25; // rax
  unsigned __int16 v26; // cx
  UFG::AttackRightsComponent *v27; // rax
  unsigned __int16 v28; // cx
  UFG::TargetingSystemBaseComponent *v29; // rax
  unsigned __int16 v30; // cx
  UFG::AimingBaseComponent *v31; // rdi
  UFG::SimComponent *v32; // rax
  UFG::qArray<UFG::AICoverSearchParams::HostileTarget,0> *v33; // rdi
  signed __int64 v34; // rsi
  unsigned int v35; // ebx
  unsigned int v36; // edx
  unsigned int v37; // edx
  signed __int64 v38; // rcx
  UFG::AICoverSearchParams::HostileTarget *v39; // rax
  float v40; // xmm2_4
  float v41; // xmm1_4
  float v42; // xmm0_4
  float v43; // xmm1_4
  float v44; // xmm2_4
  __int64 j; // rax
  _QWORD *v46; // rdx
  __int64 v47; // rcx
  _QWORD *v48; // rax
  __int64 *v49; // rcx
  __int64 **v50; // rax
  UFG::qVector3 vAimDirection; // [rsp+28h] [rbp-38h]
  UFG::qVector3 raycastPosition; // [rsp+38h] [rbp-28h]
  __int64 *v53; // [rsp+48h] [rbp-18h]
  __int64 **v54; // [rsp+50h] [rbp-10h]
  UFG::AICoverSearchParams *v55; // [rsp+A8h] [rbp+48h]
  UFG::SimObject *v56; // [rsp+B0h] [rbp+50h]

  v56 = pIgnoreObject;
  v55 = pSearchParams;
  v3 = pIgnoreObject;
  v4 = pSearchParams;
  v5 = this;
  v6 = this->m_pActionContext->mSimObject.m_pPointer;
  v7 = 0i64;
  if ( v6 )
    v8 = v6->m_pTransformNodeComponent;
  else
    v8 = 0i64;
  UFG::TransformNodeComponent::UpdateWorldTransform(v8);
  v9 = (UFG::SimObjectCVBase *)v5->m_pActionContext->mSimObject.m_pPointer;
  if ( v9 )
  {
    v10 = v9->m_Flags;
    if ( (v10 >> 14) & 1 )
    {
      v11 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v9);
    }
    else if ( (v10 & 0x8000u) == 0 )
    {
      if ( (v10 >> 13) & 1 )
      {
        v11 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                (UFG::SimObjectGame *)&v9->vfptr,
                                                UFG::ActiveAIEntityComponent::_TypeUID);
      }
      else if ( (v10 >> 12) & 1 )
      {
        v11 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                (UFG::SimObjectGame *)&v9->vfptr,
                                                UFG::ActiveAIEntityComponent::_TypeUID);
      }
      else
      {
        v11 = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                (UFG::SimObject *)&v9->vfptr,
                                                UFG::ActiveAIEntityComponent::_TypeUID);
      }
    }
    else
    {
      v11 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v9);
    }
    v7 = v11;
  }
  v53 = (__int64 *)&v53;
  v54 = &v53;
  v12 = UFG::NearbyCharacterManager::s_pInstance;
  v13 = &v53;
  v14 = &raycastPosition;
  if ( &raycastPosition != &raycastPosition )
  {
    do
    {
      v15 = (_QWORD *)&v14[1].y;
      v16 = *(_QWORD *)&v14[1].y;
      v17 = (_QWORD *)v15[1];
      *(_QWORD *)(v16 + 8) = v17;
      *v17 = v16;
      *v15 = v15;
      v15[1] = v15;
      v13 = v54;
      v14 = (UFG::qVector3 *)(v54 - 2);
    }
    while ( v54 - 2 != (__int64 **)&raycastPosition );
  }
  v18 = (UFG::NearbyCharacterManager *)v12->m_Characters[0].mNode.mNext;
  if ( v18 != v12 )
  {
    v19 = v53;
    do
    {
      v20 = (__int64 **)&v18->m_Characters[1];
      v19[1] = (__int64)&v18->m_Characters[1];
      *v20 = v19;
      v20[1] = (__int64 *)&v53;
      v19 = (__int64 *)&v18->m_Characters[1];
      v53 = (__int64 *)&v18->m_Characters[1];
      v18 = (UFG::NearbyCharacterManager *)v18->m_Characters[0].mNode.mNext;
    }
    while ( v18 != v12 );
    v13 = v54;
  }
  for ( i = (signed __int64)(v13 - 2); (UFG::qVector3 *)i != &raycastPosition; i = *(_QWORD *)(i + 24) - 16i64 )
  {
    v22 = *(_QWORD **)(i + 48);
    if ( v22 )
    {
      if ( (*(unsigned __int8 (__fastcall **)(_QWORD))(*v22 + 112i64))(*(_QWORD *)(i + 48)) )
      {
        v23 = (UFG::SimObjectGame *)v22[5];
        if ( v23 != (UFG::SimObjectGame *)v3
          && v23 != (UFG::SimObjectGame *)v5->m_pActionContext->mSimObject.m_pPointer
          && v23 )
        {
          v24 = v23->m_Flags;
          if ( (v24 >> 14) & 1 )
          {
            v25 = v23->m_Components.p[6].m_pComponent;
          }
          else if ( (v24 & 0x8000u) == 0 )
          {
            if ( (v24 >> 13) & 1 )
              v25 = UFG::SimObjectGame::GetComponentOfTypeHK(v23, UFG::HealthComponent::_TypeUID);
            else
              v25 = (v24 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v23, UFG::HealthComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v23->vfptr, UFG::HealthComponent::_TypeUID);
          }
          else
          {
            v25 = v23->m_Components.p[6].m_pComponent;
          }
          if ( v25 && !BYTE4(v25[1].m_BoundComponentHandles.mNode.mPrev) )
          {
            v26 = v23->m_Flags;
            if ( (v26 >> 14) & 1 )
            {
              v27 = (UFG::AttackRightsComponent *)v23->m_Components.p[46].m_pComponent;
            }
            else if ( (v26 & 0x8000u) == 0 )
            {
              if ( (v26 >> 13) & 1 )
                v27 = (UFG::AttackRightsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      v23,
                                                      UFG::AttackRightsComponent::_TypeUID);
              else
                v27 = (UFG::AttackRightsComponent *)((v26 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                         v23,
                                                                         UFG::AttackRightsComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v23->vfptr, UFG::AttackRightsComponent::_TypeUID));
            }
            else
            {
              v27 = (UFG::AttackRightsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    v23,
                                                    UFG::AttackRightsComponent::_TypeUID);
            }
            if ( v27 && UFG::ActiveAIEntityComponent::IsEnemyOfMine(v7, v27) )
            {
              v28 = v23->m_Flags;
              if ( (v28 >> 14) & 1 )
              {
                v29 = (UFG::TargetingSystemBaseComponent *)v23->m_Components.p[20].m_pComponent;
              }
              else if ( (v28 & 0x8000u) == 0 )
              {
                if ( (v28 >> 13) & 1 )
                  v29 = (UFG::TargetingSystemBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               v23,
                                                               UFG::TargetingSystemBaseComponent::_TypeUID);
                else
                  v29 = (UFG::TargetingSystemBaseComponent *)((v28 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                                  v23,
                                                                                  UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v23->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID));
              }
              else
              {
                v29 = (UFG::TargetingSystemBaseComponent *)v23->m_Components.p[20].m_pComponent;
              }
              if ( UFG::HasRangedWeaponEquippedWithAmmo(v29) )
              {
                v30 = v23->m_Flags;
                if ( (v30 >> 14) & 1 )
                {
                  v31 = (UFG::AimingBaseComponent *)v23->m_Components.p[47].m_pComponent;
                }
                else
                {
                  if ( (v30 & 0x8000u) == 0 )
                  {
                    if ( (v30 >> 13) & 1 )
                    {
                      v32 = UFG::SimObjectGame::GetComponentOfTypeHK(v23, UFG::AimingBaseComponent::_TypeUID);
                    }
                    else if ( (v30 >> 12) & 1 )
                    {
                      v32 = UFG::SimObjectGame::GetComponentOfTypeHK(v23, UFG::AimingBaseComponent::_TypeUID);
                    }
                    else
                    {
                      v32 = UFG::SimObject::GetComponentOfType(
                              (UFG::SimObject *)&v23->vfptr,
                              UFG::AimingBaseComponent::_TypeUID);
                    }
                  }
                  else
                  {
                    v32 = UFG::SimObjectGame::GetComponentOfTypeHK(v23, UFG::AimingBaseComponent::_TypeUID);
                  }
                  v31 = (UFG::AimingBaseComponent *)v32;
                }
                UFG::ComputeObjectRaycastPosition((UFG::SimObject *)&v23->vfptr, &raycastPosition);
                if ( v31 )
                {
                  UFG::AimingBaseComponent::GetAimDirection(v31, &vAimDirection, 0i64);
                }
                else
                {
                  *(_QWORD *)&vAimDirection.x = 0i64;
                  vAimDirection.z = 0.0;
                }
                v33 = &v4->m_aHostileTargets;
                v34 = v4->m_aHostileTargets.size;
                v35 = v34 + 1;
                v36 = v33->capacity;
                if ( (signed int)v34 + 1 > v36 )
                {
                  if ( v36 )
                    v37 = 2 * v36;
                  else
                    v37 = 1;
                  for ( ; v37 < v35; v37 *= 2 )
                    ;
                  if ( v37 - v35 > 0x10000 )
                    v37 = v34 + 65537;
                  UFG::qArray<UFG::AICoverSearchParams::HostileTarget,0>::Reallocate(v33, v37, "qArray.Add");
                }
                v33->size = v35;
                v38 = v34;
                v39 = v33->p;
                v40 = raycastPosition.x;
                v39[v38].m_vPosition.x = raycastPosition.x;
                v41 = raycastPosition.y;
                v39[v38].m_vPosition.y = raycastPosition.y;
                v42 = raycastPosition.z;
                v39[v38].m_vPosition.z = raycastPosition.z;
                v39[v38].m_vDirectTarget.x = v40;
                v39[v38].m_vDirectTarget.y = v41;
                v39[v38].m_vDirectTarget.z = v42;
                v43 = vAimDirection.y;
                v44 = vAimDirection.z;
                v39[v38].m_vAimingDirection.x = vAimDirection.x;
                v39[v38].m_vAimingDirection.y = v43;
                v39[v38].m_vAimingDirection.z = v44;
                v3 = v56;
                v4 = v55;
              }
            }
          }
        }
      }
    }
  }
  for ( j = (__int64)(v54 - 2); v54 - 2 != (__int64 **)&raycastPosition; j = (__int64)(v54 - 2) )
  {
    v46 = (_QWORD *)(j + 16);
    v47 = *(_QWORD *)(j + 16);
    v48 = *(_QWORD **)(j + 24);
    *(_QWORD *)(v47 + 8) = v48;
    *v48 = v47;
    *v46 = v46;
    v46[1] = v46;
  }
  v49 = v53;
  v50 = v54;
  v53[1] = (__int64)v54;
  *v50 = v49;
}6 = v46;
    v46[1] = v46;
  }
  v49 = v53;
  v50 = v54;
  v53[1] = (__int64)v54;
  *v50 = v49;
}

// File Line: 6213
// RVA: 0x32AFB0
void __fastcall AICoverFaceCoverObjectTask::AICoverFaceCoverObjectTask(AICoverFaceCoverObjectTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<AICoverFaceCoverObjectTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&AICoverFaceCoverObjectTask::`vftable;
}

// File Line: 6234
// RVA: 0x38B490
bool __fastcall AICoverFaceCoverObjectTask::Update(AICoverFaceCoverObjectTask *this, float timestep)
{
  AICoverFaceCoverObjectTask *v2; // rdi
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rax
  __int64 v6; // rbx
  UFG::SimObjectCVBase *v7; // rcx
  unsigned __int16 v8; // dx
  unsigned int v10; // edx
  bool v11; // zf
  char v12; // [rsp+20h] [rbp-28h]
  char v13; // [rsp+2Ch] [rbp-1Ch]

  v2 = this;
  v3 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AICoverComponent::_TypeUID);
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
        v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AICoverComponent::_TypeUID);
      else
        v5 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AICoverComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::AICoverComponent::_TypeUID);
    }
    else
    {
      v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AICoverComponent::_TypeUID);
    }
    if ( v5 )
    {
      v6 = *(_QWORD *)&v5[1].m_TypeUID;
      if ( v6 )
      {
        if ( (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v6 + 16i64))(v6) )
        {
          (*(void (__fastcall **)(__int64, char *))(*(_QWORD *)v6 + 160i64))(v6, &v12);
          (*(void (__fastcall **)(__int64, char *))(*(_QWORD *)v6 + 120i64))(v6, &v13);
          v7 = (UFG::SimObjectCVBase *)v2->m_pActionContext->mSimObject.m_pPointer;
          if ( v7 )
          {
            v8 = v7->m_Flags;
            if ( (v8 >> 14) & 1 || (v8 & 0x8000u) != 0 )
            {
              UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v7);
              return 0;
            }
            if ( (v8 >> 13) & 1 )
            {
              v10 = UFG::ActiveAIEntityComponent::_TypeUID;
LABEL_20:
              UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v7->vfptr, v10);
              return 0;
            }
            v11 = ((v8 >> 12) & 1) == 0;
            v10 = UFG::ActiveAIEntityComponent::_TypeUID;
            if ( !v11 )
              goto LABEL_20;
            UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::ActiveAIEntityComponent::_TypeUID);
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
  UFG::qNode<ITask,ITask> *v1; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<AICoverClearCoverObjectTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&AICoverClearCoverObjectTask::`vftable;
}

// File Line: 6302
// RVA: 0x342DE0
void __fastcall AICoverClearCoverObjectTask::Begin(AICoverClearCoverObjectTask *this, ActionContext *action_context)
{
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::AICoverComponent *v4; // rax

  v2 = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = (UFG::AICoverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::AICoverComponent::_TypeUID);
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
      {
        v4 = (UFG::AICoverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::AICoverComponent::_TypeUID);
      }
      else if ( (v3 >> 12) & 1 )
      {
        v4 = (UFG::AICoverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::AICoverComponent::_TypeUID);
      }
      else
      {
        v4 = (UFG::AICoverComponent *)UFG::SimObject::GetComponentOfType(
                                        (UFG::SimObject *)&v2->vfptr,
                                        UFG::AICoverComponent::_TypeUID);
      }
    }
    else
    {
      v4 = (UFG::AICoverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::AICoverComponent::_TypeUID);
    }
    if ( v4 )
      UFG::AICoverComponent::ClearCoverObjects(v4);
  }
}

// File Line: 6331
// RVA: 0x32B0D0
void __fastcall AICoverLatchTargetedObjectTask::AICoverLatchTargetedObjectTask(AICoverLatchTargetedObjectTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<AICoverLatchTargetedObjectTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&AICoverLatchTargetedObjectTask::`vftable;
}

// File Line: 6343
// RVA: 0x342E70
void __fastcall AICoverLatchTargetedObjectTask::Begin(AICoverLatchTargetedObjectTask *this, ActionContext *action_context)
{
  AICoverLatchTargetedObjectTask *v2; // rdi
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rax
  UFG::AICoverComponent *v6; // rbx
  ITrack *v7; // rax
  UFG::CoverPosition *v8; // rdi

  v2 = this;
  v3 = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AICoverComponent::_TypeUID);
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
        v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AICoverComponent::_TypeUID);
      else
        v5 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AICoverComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::AICoverComponent::_TypeUID);
    }
    else
    {
      v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AICoverComponent::_TypeUID);
    }
    v6 = (UFG::AICoverComponent *)v5;
    if ( v5 )
    {
      v7 = v2->m_Track;
      switch ( LOBYTE(v7[1].vfptr) )
      {
        case 1:
          v8 = v6->m_pSyncCoverPosition;
          break;
        case 2:
          v8 = (UFG::CoverPosition *)v6->m_pProbeCoverObject;
          break;
        case 3:
          v8 = v6->m_pTargetedCoverPosition;
          break;
        case 4:
          v8 = v6->m_pCurrentCoverPosition;
          break;
        default:
          return;
      }
      if ( v8 )
      {
        if ( v8->vfptr->IsPosition((UFG::CoverObjectBase *)&v8->vfptr) )
          UFG::AICoverComponent::SetSyncCoverPosition(v6, v8, 0);
      }
    }
  }
}

// File Line: 6378
// RVA: 0x32AD30
void __fastcall AICopReleaseArrestRightTask::AICopReleaseArrestRightTask(AICopReleaseArrestRightTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<AICopReleaseArrestRightTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&AICopReleaseArrestRightTask::`vftable;
}

// File Line: 6402
// RVA: 0x354CC0
void __fastcall AICopReleaseArrestRightTask::End(AICopReleaseArrestRightTask *this)
{
  AICopReleaseArrestRightTask *v1; // rbx
  UFG::CopSystem *v2; // rax

  v1 = this;
  v2 = UFG::CopSystem::Instance();
  v2->vfptr[105].__vecDelDtor(
    (UFG::qSafePointerNode<UFG::EncounterBase> *)&v2->vfptr,
    (unsigned int)v1->m_pActionContext->mSimObject.m_pPointer);
}

// File Line: 6416
// RVA: 0x32ADC0
void __fastcall AICopReportInfractionTargetTask::AICopReportInfractionTargetTask(AICopReportInfractionTargetTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<AICopReportInfractionTargetTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&AICopReportInfractionTargetTask::`vftable;
}

// File Line: 6428
// RVA: 0x342D00
void __fastcall AICopReportInfractionTargetTask::Begin(AICopReportInfractionTargetTask *this, ActionContext *action_context)
{
  ITrack *v2; // rax
  AICopReportInfractionTargetTask *v3; // rdi
  UFG::SimObjectGame *v4; // rcx
  __int64 v5; // rbx
  unsigned __int16 v6; // dx
  UFG::SimComponent *v7; // r8
  UFG::SimComponent *v8; // rax
  __int64 v9; // rbx
  UFG::CopSystem *v10; // rax

  v2 = this->m_Track;
  this->m_pActionContext = action_context;
  v3 = this;
  v4 = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  v5 = LOBYTE(v2[1].vfptr);
  if ( v4 )
  {
    v6 = v4->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v7 = v4->m_Components.p[20].m_pComponent;
    }
    else if ( (v6 & 0x8000u) == 0 )
    {
      if ( (v6 >> 13) & 1 )
      {
        v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else if ( (v6 >> 12) & 1 )
      {
        v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else
      {
        v8 = UFG::SimObject::GetComponentOfType(
               (UFG::SimObject *)&v4->vfptr,
               UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      v7 = v8;
    }
    else
    {
      v7 = v4->m_Components.p[20].m_pComponent;
    }
    if ( v7 )
    {
      v9 = *(_QWORD *)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v7[1].m_Flags + v5 + 8)
                     + *(_QWORD *)&v7[1].m_TypeUID
                     + 40);
      if ( v9 )
      {
        v10 = UFG::CopSystem::Instance();
        ((void (__fastcall *)(UFG::CopSystem *, UFG::SimObject *, __int64))v10->vfptr[110].__vecDelDtor)(
          v10,
          v3->m_pActionContext->mSimObject.m_pPointer,
          v9);
      }
    }
  }
}

// File Line: 6463
// RVA: 0x32AB40
void __fastcall AICopApplyReducedRadiusTask::AICopApplyReducedRadiusTask(AICopApplyReducedRadiusTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
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
  UFG::qNode<ITask,ITask> *v1; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::NavComponent> *v2; // [rsp+28h] [rbp+10h]

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<AIOverrideAvoidanceRadiusTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&AIOverrideAvoidanceRadiusTask::`vftable;
  v2 = &this->m_pNavComponent;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  this->m_pNavComponent.m_pPointer = 0i64;
}

// File Line: 6493
// RVA: 0x3346E0
void __fastcall AIOverrideAvoidanceRadiusTask::~AIOverrideAvoidanceRadiusTask(AIOverrideAvoidanceRadiusTask *this)
{
  AIOverrideAvoidanceRadiusTask *v1; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::NavComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rdx
  UFG::qNode<ITask,ITask> *v8; // rcx
  UFG::qNode<ITask,ITask> *v9; // rax

  v1 = this;
  this->vfptr = (ITaskVtbl *)&AIOverrideAvoidanceRadiusTask::`vftable;
  v2 = &this->m_pNavComponent;
  if ( this->m_pNavComponent.m_pPointer )
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
  v1->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v7 = (UFG::qNode<ITask,ITask> *)&v1->mPrev;
  v8 = v1->mPrev;
  v9 = v1->mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v7->mPrev = v7;
  v7->mNext = v7;
}

// File Line: 6499
// RVA: 0x341830
char __fastcall AdjustToNavGoal(UFG::NavComponent *pNC, float radius)
{
  UFG::NavComponent *v2; // rbx
  float v3; // xmm6_4
  UFG::NavModulePathing *v5; // rdx
  UFG::NavPath *v6; // rdx
  __m128 v7; // xmm1
  __m128 v8; // xmm1
  __m128 v9; // xmm4
  __m128 v10; // xmm1
  float v11; // xmm6_4
  float v12; // xmm6_4
  float v13; // xmm0_4
  hkVector4f hkvPosition; // [rsp+20h] [rbp-48h]
  hkVector4f hkvNewPosition; // [rsp+30h] [rbp-38h]

  v2 = pNC;
  v3 = radius;
  if ( !pNC )
    return 0;
  v5 = pNC->m_pNavModulePathing;
  if ( !v5 )
    return 0;
  v6 = v5->m_pPath.m_pNavPath;
  if ( !v6 )
    return 0;
  hkvPosition.m_quad = _mm_unpacklo_ps(
                         _mm_unpacklo_ps(
                           (__m128)LODWORD(v6->m_aWaypoints.p[v6->m_aWaypoints.size - 1].m_navPosition.m_vPosition.x),
                           (__m128)LODWORD(v6->m_aWaypoints.p[v6->m_aWaypoints.size - 1].m_navPosition.m_vPosition.z)),
                         _mm_unpacklo_ps(
                           (__m128)LODWORD(v6->m_aWaypoints.p[v6->m_aWaypoints.size - 1].m_navPosition.m_vPosition.y),
                           (__m128)0i64));
  if ( UFG::HavokAIUtilGame::FindMeshPositionAwayFromWall(&hkvPosition, &hkvNewPosition, radius) )
  {
    v7 = _mm_sub_ps(hkvPosition.m_quad, hkvNewPosition.m_quad);
    v8 = _mm_mul_ps(v7, v7);
    v9 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)), _mm_shuffle_ps(v8, v8, 170));
    v10 = _mm_rsqrt_ps(v9);
    v11 = v3
        - COERCE_FLOAT(
            _mm_andnot_ps(
              _mm_cmpleps(v9, (__m128)0i64),
              _mm_mul_ps(
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v9, v10), v10)),
                  _mm_mul_ps(*(__m128 *)_xmm, v10)),
                v9)));
    if ( v11 > 0.0 )
    {
      v12 = v11 * 0.5;
      v13 = FLOAT_0_050000001;
      if ( v12 >= 0.050000001 )
        v13 = v12;
      v2->m_fAvoidanceRadius = v13;
    }
  }
  return 1;
}

// File Line: 6530
// RVA: 0x343630
void __fastcall AIOverrideAvoidanceRadiusTask::Begin(AIOverrideAvoidanceRadiusTask *this, ActionContext *action_context)
{
  AIOverrideAvoidanceRadiusTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  UFG::SimComponent *v4; // r8
  unsigned __int16 v5; // dx
  UFG::SimComponent *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::NavComponent> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::NavComponent *v11; // rcx
  float v12; // xmm0_4
  ITrack *v13; // rax
  UFG::eCollisionAvoidanceType v14; // eax
  UFG::NavComponent *v15; // rcx
  ITrack *v16; // rax
  UFG::NavComponent *v17; // rcx
  float v18; // xmm0_4

  v2 = this;
  this->m_pActionContext = action_context;
  this->m_HasAdjustedToNavGoal = 0;
  v3 = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  if ( v3 )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v4 = v3->m_Components.p[36].m_pComponent;
    }
    else
    {
      if ( (v5 & 0x8000u) == 0 )
      {
        if ( (v5 >> 13) & 1 )
        {
          v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::NavComponent::_TypeUID);
        }
        else if ( (v5 >> 12) & 1 )
        {
          v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::NavComponent::_TypeUID);
        }
        else
        {
          v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::NavComponent::_TypeUID);
        }
      }
      else
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::NavComponent::_TypeUID);
      }
      v4 = v6;
    }
  }
  else
  {
    v4 = 0i64;
  }
  v7 = &v2->m_pNavComponent;
  if ( v2->m_pNavComponent.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v2->m_pNavComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v2->m_pNavComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pNavComponent.mPrev;
  }
  v2->m_pNavComponent.m_pPointer = v4;
  if ( v4 )
  {
    v10 = v4->m_SafePointerList.mNode.mPrev;
    v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v7->mPrev = v10;
    v2->m_pNavComponent.mNext = &v4->m_SafePointerList.mNode;
    v4->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  }
  v11 = (UFG::NavComponent *)v2->m_pNavComponent.m_pPointer;
  if ( v11 )
  {
    v12 = UFG::NavComponent::GetAvoidanceRadius(v11);
    v13 = v2->m_Track;
    v2->m_Radius = v12;
    if ( *(float *)&v13[1].vfptr < 0.0 )
    {
      v14 = (unsigned int)UFG::NavComponent::GetCollisionAvoidanceType((UFG::NavComponent *)v2->m_pNavComponent.m_pPointer);
      v15 = (UFG::NavComponent *)v2->m_pNavComponent.m_pPointer;
      v2->m_CollisionAvoidanceType = v14;
      UFG::NavComponent::SetCollisionAvoidanceType(v15, 8i64);
    }
    v16 = v2->m_Track;
    if ( BYTE4(v16[1].vfptr) )
    {
      v17 = (UFG::NavComponent *)v2->m_pNavComponent.m_pPointer;
      if ( v17->m_pNavModulePathing->m_pPath.m_pNavPath )
        v2->m_HasAdjustedToNavGoal = AdjustToNavGoal(v17, v2->m_Radius);
    }
    else
    {
      v18 = *(float *)&v16[1].vfptr;
      if ( v18 > 0.0 )
        *((float *)&v2->m_pNavComponent.m_pPointer[2].m_pSimObject + 1) = v18;
    }
  }
}

// File Line: 6565
// RVA: 0x38C1D0
char __fastcall AIOverrideAvoidanceRadiusTask::Update(AIOverrideAvoidanceRadiusTask *this, float timestep)
{
  AIOverrideAvoidanceRadiusTask *v2; // rbx
  UFG::NavComponent *v3; // rcx

  v2 = this;
  if ( BYTE4(this->m_Track[1].vfptr) )
  {
    if ( !this->m_HasAdjustedToNavGoal )
    {
      v3 = (UFG::NavComponent *)this->m_pNavComponent.m_pPointer;
      if ( v3 )
      {
        if ( v3->m_pNavModulePathing->m_pPath.m_pNavPath )
          v2->m_HasAdjustedToNavGoal = AdjustToNavGoal(v3, v2->m_Radius);
      }
    }
  }
  return 1;
}

// File Line: 6582
// RVA: 0x354D90
void __fastcall AIOverrideAvoidanceRadiusTask::End(AIOverrideAvoidanceRadiusTask *this)
{
  ActionContext *v1; // rax
  AIOverrideAvoidanceRadiusTask *v2; // rbx
  UFG::NavComponent *v3; // rcx

  v1 = this->m_pActionContext;
  v2 = this;
  if ( v1 )
  {
    if ( v1->mSimObject.m_pPointer )
    {
      v3 = (UFG::NavComponent *)this->m_pNavComponent.m_pPointer;
      if ( v3 )
      {
        if ( *(float *)&v2->m_Track[1].vfptr < 0.0 )
          UFG::NavComponent::SetCollisionAvoidanceType(v3, (unsigned int)v2->m_CollisionAvoidanceType);
        HIDWORD(v2->m_pNavComponent.m_pPointer[2].m_pSimObject) = LODWORD(v2->m_Radius);
      }
    }
  }
}

// File Line: 6601
// RVA: 0x32F590
void __fastcall GroupStimulusTask::GroupStimulusTask(GroupStimulusTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<GroupStimulusTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&GroupStimulusTask::`vftable;
}

// File Line: 6613
// RVA: 0x345A00
void __fastcall GroupStimulusTask::Begin(GroupStimulusTask *this, ActionContext *action_context)
{
  ActionContext *v2; // rdi
  GroupStimulusTask *v3; // rbx
  UFG::SimObject *v4; // rax
  UFG::SceneObjectProperties *v5; // rdx
  UFG::qPropertySet *v6; // rcx
  int *v7; // rax
  unsigned int v8; // er13
  unsigned __int64 v9; // rax
  UFG::allocator::free_link *v10; // rax
  UFG::allocator::free_link *v11; // rsi
  unsigned int v12; // er15
  ITrack *v13; // rax
  float v14; // xmm9_4
  signed int v15; // ebx
  float v16; // xmm6_4
  float v17; // xmm7_4
  float v18; // xmm8_4
  UFG::SimObject *v19; // rax
  float *v20; // rbx
  UFG::SimObjectCVBase *v21; // rcx
  unsigned __int16 v22; // dx
  UFG::SimObjectCharacterPropertiesComponent *v23; // rax
  UFG::NearbyCharacterManager *v24; // r8
  UFG::SimObject *v25; // r14
  bool *v26; // rax
  UFG::SimObject *v27; // r9
  _QWORD *v28; // rdx
  __int64 v29; // rcx
  _QWORD *v30; // rax
  UFG::NearbyCharacterManager *v31; // rcx
  __int64 *v32; // rdx
  __int64 **v33; // rax
  signed __int64 v34; // r14
  __int64 v35; // rcx
  __int64 v36; // rax
  __int64 v37; // rcx
  float *v38; // rbx
  __int64 v39; // r12
  bool v40; // di
  __int64 v41; // rbx
  bool v42; // al
  __int64 v43; // r12
  float v44; // edi
  UFG::eStimulusEmissionType v45; // ebx
  unsigned __int64 v46; // rax
  UFG::allocator::free_link *v47; // rax
  UFG::allocator::free_link *v48; // r15
  UFG::allocator::free_link *v49; // rcx
  __int64 v50; // rdx
  __int64 v51; // rbx
  unsigned int v52; // er15
  unsigned __int64 v53; // rax
  UFG::allocator::free_link *v54; // rdi
  __int64 v55; // r12
  UFG::allocator::free_link *v56; // rax
  UFG::qPropertySet *v57; // rcx
  int *v58; // rax
  unsigned int v59; // ecx
  unsigned int v60; // er14
  unsigned int v61; // ebx
  unsigned __int64 v62; // rax
  UFG::allocator::free_link *v63; // rax
  UFG::allocator::free_link *v64; // r13
  UFG::allocator::free_link *v65; // rcx
  __int64 v66; // rdx
  int v67; // er10
  __int64 v68; // r9
  UFG::allocator::free_link *v69; // r8
  __int64 i; // rdx
  UFG::allocator::free_link *v71; // rcx
  __int64 v72; // rax
  int v73; // edx
  int v74; // ebx
  __int64 v75; // r13
  UFG::SimObject *v76; // r14
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v77; // r15
  UFG::SimComponent *v78; // rbx
  int v79; // er12
  UFG::TransformNodeComponent *v80; // r14
  UFG::SimComponent *v81; // rax
  UFG::SimComponent *v82; // r8
  UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *v83; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v84; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v85; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v86; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v87; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v88; // rax
  UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,1,0> *v89; // rax
  UFG::SimObject *v90; // r8
  UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,1,0> *v91; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v92; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v93; // rax
  __int64 *v94; // rcx
  UFG::SimObject *v95; // rax
  __int64 v96; // [rsp+0h] [rbp-99h]
  unsigned int v97; // [rsp+1Ch] [rbp-7Dh]
  bool delete_simobject_upon_expiry[8]; // [rsp+20h] [rbp-79h]
  UFG::StimulusManager *v99; // [rsp+28h] [rbp-71h]
  __int64 *v100; // [rsp+30h] [rbp-69h]
  UFG::SimObject *stimulus_emitter_object; // [rsp+38h] [rbp-61h]
  UFG::StimulusParameters stimulus_parameters; // [rsp+40h] [rbp-59h]
  __int64 v103; // [rsp+58h] [rbp-41h]
  __int64 v104; // [rsp+60h] [rbp-39h]
  __int64 v105; // [rsp+100h] [rbp+67h]
  int v106; // [rsp+108h] [rbp+6Fh]
  int v107; // [rsp+110h] [rbp+77h]
  UFG::StimulusDescription *stimulus_description; // [rsp+118h] [rbp+7Fh]

  v104 = -2i64;
  v2 = action_context;
  v3 = this;
  v107 = 0;
  v4 = action_context->mSimObject.m_pPointer;
  if ( !v4 || !v4->m_pSceneObj )
  {
    v6 = 0i64;
LABEL_6:
    if ( !v6 )
      goto LABEL_9;
    goto LABEL_7;
  }
  v5 = v4->m_pSceneObj;
  v6 = v5->mpWritableProperties;
  if ( !v6 )
  {
    v6 = v5->mpConstProperties;
    goto LABEL_6;
  }
LABEL_7:
  v7 = UFG::qPropertySet::Get<long>(v6, (UFG::qSymbol *)&v3->m_Track[1].mResourceOwner + 1, DEPTH_RECURSE);
  if ( v7 )
    v107 = *v7;
LABEL_9:
  *(_QWORD *)&stimulus_parameters.m_MaxStimulusDuration = 0i64;
  v8 = 0;
  *(_QWORD *)&stimulus_parameters.m_StimulusProducerOffset.z = 0i64;
  v99 = (UFG::StimulusManager *)32;
  v9 = 256i64;
  if ( !is_mul_ok(0x20ui64, 8ui64) )
    v9 = -1i64;
  v10 = UFG::qMalloc(v9, "qArray.Reallocate(Constructor)", 0i64);
  v11 = v10;
  *(_QWORD *)&stimulus_parameters.m_MaxStimulusDuration = v10;
  v12 = 32;
  stimulus_parameters.m_StimulusEmissionType = 32;
  v13 = v3->m_Track;
  v14 = *((float *)&v13[1].vfptr + 1);
  LODWORD(stimulus_description) = LOBYTE(v13[1].mResourceOwner);
  v15 = 17;
  v16 = UFG::qVector3::msZero.x;
  v17 = UFG::qVector3::msZero.y;
  v18 = UFG::qVector3::msZero.z;
  v19 = v2->mSimObject.m_pPointer;
  stimulus_emitter_object = v19;
  if ( v19 )
  {
    v20 = (float *)v19->m_pTransformNodeComponent;
    if ( v20 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(v19->m_pTransformNodeComponent);
      v16 = v20[44];
      v17 = v20[45];
      v18 = v20[46];
    }
    v15 = 17;
  }
  v21 = (UFG::SimObjectCVBase *)v2->mSimObject.m_pPointer;
  if ( v21 )
  {
    v22 = v21->m_Flags;
    if ( (v22 >> 14) & 1 )
    {
      v23 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v21);
    }
    else if ( (v22 & 0x8000u) == 0 )
    {
      if ( (v22 >> 13) & 1 )
        v23 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                              (UFG::SimObjectGame *)&v21->vfptr,
                                                              UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
      else
        v23 = (UFG::SimObjectCharacterPropertiesComponent *)((v22 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                                 (UFG::SimObjectGame *)&v21->vfptr,
                                                                                 UFG::SimObjectCharacterPropertiesComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v21->vfptr, UFG::SimObjectCharacterPropertiesComponent::_TypeUID));
    }
    else
    {
      v23 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v21);
    }
    if ( v23 )
      v15 = v23->m_eFactionClass;
  }
  stimulus_emitter_object = (UFG::SimObject *)&v100;
  v24 = UFG::NearbyCharacterManager::s_pInstance;
  v25 = (UFG::SimObject *)&v100;
  v26 = delete_simobject_upon_expiry;
  v100 = &v96 + 4;
  v27 = (UFG::SimObject *)(&v96 + 4);
  if ( delete_simobject_upon_expiry != (bool *)v100 )
  {
    do
    {
      v28 = v26 + 16;
      v29 = *((_QWORD *)v26 + 2);
      v30 = (_QWORD *)*((_QWORD *)v26 + 3);
      *(_QWORD *)(v29 + 8) = v30;
      *v30 = v29;
      *v28 = v28;
      v28[1] = v28;
      v25 = stimulus_emitter_object;
      v26 = (bool *)&stimulus_emitter_object[-1].m_UnboundComponentHandles;
    }
    while ( &stimulus_emitter_object[-1].m_UnboundComponentHandles != (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,1,0> *)v27 );
  }
  v31 = (UFG::NearbyCharacterManager *)v24->m_Characters[0].mNode.mNext;
  if ( v31 != v24 )
  {
    v32 = v100;
    do
    {
      v33 = (__int64 **)&v31->m_Characters[1];
      v32[1] = (__int64)&v31->m_Characters[1];
      *v33 = v32;
      v33[1] = (__int64 *)&v100;
      v32 = (__int64 *)&v31->m_Characters[1];
      v100 = (__int64 *)&v31->m_Characters[1];
      v31 = (UFG::NearbyCharacterManager *)v31->m_Characters[0].mNode.mNext;
    }
    while ( v31 != v24 );
    v25 = stimulus_emitter_object;
  }
  v34 = (signed __int64)&v25[-1].m_UnboundComponentHandles;
  *(_QWORD *)&stimulus_parameters.m_StimulusProducerOffset.x = v15;
  if ( (UFG::SimObject *)v34 != v27 )
  {
    do
    {
      v35 = *(_QWORD *)(v34 + 48);
      if ( v35 )
      {
        if ( (*(unsigned __int8 (**)(void))(*(_QWORD *)v35 + 112i64))() )
        {
          v36 = *(_QWORD *)(v34 + 48);
          if ( *(UFG::SimObject **)(v36 + 40) != stimulus_emitter_object )
          {
            v37 = *(_QWORD *)(v36 + 424);
            v38 = *(float **)(v36 + 88);
            v39 = *(_QWORD *)(v36 + 280);
            if ( v38 )
            {
              if ( v37 )
              {
                if ( v39 )
                {
                  v40 = *(_BYTE *)(v37 + 116) == 0;
                  UFG::TransformNodeComponent::UpdateWorldTransform(*(UFG::TransformNodeComponent **)(v36 + 88));
                  LOBYTE(v106) = v14 > fsqrt(
                                         (float)((float)((float)(v16 - v38[44]) * (float)(v16 - v38[44]))
                                               + (float)((float)(v17 - v38[45]) * (float)(v17 - v38[45])))
                                       + (float)((float)(v18 - v38[46]) * (float)(v18 - v38[46])));
                  v41 = *(signed int *)(v39 + 200);
                  v42 = UFG::GameStatTracker::Instance()->mFactionInterface.mStandings[0][v41
                                                                                        + 39i64
                                                                                        * *(_QWORD *)&stimulus_parameters.m_StimulusProducerOffset.x] == (_DWORD)stimulus_description;
                  if ( v40 && (_BYTE)v106 && v42 )
                  {
                    v43 = v8;
                    LODWORD(v44) = v8 + 1;
                    if ( v8 + 1 > v12 )
                    {
                      v45 = 1;
                      if ( v12 )
                        v45 = 2 * v12;
                      for ( ; v45 < LODWORD(v44); v45 *= 2 )
                        ;
                      if ( (unsigned int)v45 <= 2 )
                        v45 = 2;
                      if ( v45 - LODWORD(v44) > 0x10000 )
                        v45 = v8 + 65537;
                      if ( v45 != v8 )
                      {
                        v46 = 8i64 * (unsigned int)v45;
                        if ( !is_mul_ok(v45, 8ui64) )
                          v46 = -1i64;
                        v47 = UFG::qMalloc(v46, "qArray.Add", 0i64);
                        v48 = v47;
                        if ( v11 )
                        {
                          if ( v8 )
                          {
                            v49 = v47;
                            v50 = v8;
                            do
                            {
                              v49->mNext = *(UFG::allocator::free_link **)((char *)v49 + (char *)v11 - (char *)v47);
                              ++v49;
                              --v50;
                            }
                            while ( v50 );
                          }
                          operator delete[](v11);
                        }
                        v11 = v48;
                        *(_QWORD *)&stimulus_parameters.m_MaxStimulusDuration = v48;
                        v12 = v45;
                        stimulus_parameters.m_StimulusEmissionType = v45;
                      }
                    }
                    ++v8;
                    stimulus_parameters.m_StimulusProducerOffset.z = v44;
                    v11[v43].mNext = (UFG::allocator::free_link *)v34;
                  }
                }
              }
            }
          }
        }
      }
      v34 = *(_QWORD *)(v34 + 24) - 16i64;
    }
    while ( (__int64 *)v34 != v100 );
  }
  v51 = 0i64;
  *(_QWORD *)delete_simobject_upon_expiry = 0i64;
  v52 = 0;
  v103 = 0i64;
  v53 = 128i64;
  if ( !is_mul_ok(0x20ui64, 4ui64) )
    v53 = -1i64;
  v54 = UFG::qMalloc(v53, "qArray.Reallocate(Constructor)", 0i64);
  *(_QWORD *)delete_simobject_upon_expiry = v54;
  v97 = 32;
  *(_QWORD *)&stimulus_parameters.m_StimulusProducerOffset.x = 0i64;
  v55 = v8;
  v103 = v8;
  if ( (signed __int64)v8 > 0 )
  {
    do
    {
      v56 = v11[v51].mNext[6].mNext[5].mNext;
      if ( v56 && v56[10].mNext )
      {
        if ( v56 )
          v56 = v56[10].mNext;
        v57 = (UFG::qPropertySet *)v56[18].mNext;
        if ( v57 || (v57 = (UFG::qPropertySet *)v56[19].mNext) != 0i64 )
        {
          v58 = UFG::qPropertySet::Get<long>(v57, (UFG::qSymbol *)(*(_QWORD *)(v105 + 24) + 72i64), DEPTH_RECURSE);
          if ( v58 )
          {
            LODWORD(stimulus_description) = *v58;
            v59 = v52;
            v60 = v52 + 1;
            if ( v52 + 1 > (unsigned int)v99 )
            {
              v61 = 1;
              if ( (_DWORD)v99 )
                v61 = 2 * (_DWORD)v99;
              for ( ; v61 < v60; v61 *= 2 )
                ;
              if ( v61 <= 4 )
                v61 = 4;
              if ( v61 - v60 > 0x10000 )
                v61 = v52 + 65537;
              if ( v61 != v52 )
              {
                v62 = 4i64 * v61;
                if ( !is_mul_ok(v61, 4ui64) )
                  v62 = -1i64;
                v63 = UFG::qMalloc(v62, "qArray.Add", 0i64);
                v64 = v63;
                if ( v54 )
                {
                  if ( v52 )
                  {
                    v65 = v63;
                    v66 = v52;
                    do
                    {
                      LODWORD(v65->mNext) = *(_DWORD *)((char *)&v65->mNext + (char *)v54 - (char *)v63);
                      v65 = (UFG::allocator::free_link *)((char *)v65 + 4);
                      --v66;
                    }
                    while ( v66 );
                  }
                  operator delete[](v54);
                }
                v54 = v64;
                *(_QWORD *)delete_simobject_upon_expiry = v64;
                v99 = (UFG::StimulusManager *)v61;
                v97 = v61;
                v59 = v52;
              }
              v51 = *(_QWORD *)&stimulus_parameters.m_StimulusProducerOffset.x;
            }
            ++v52;
            LODWORD(v103) = v60;
            *((_DWORD *)&v54->mNext + v59) = (_DWORD)stimulus_description;
          }
        }
      }
      *(_QWORD *)&stimulus_parameters.m_StimulusProducerOffset.x = ++v51;
    }
    while ( v51 < v55 );
  }
  v67 = 0;
  v68 = 0i64;
  if ( v55 > 0 )
  {
    v69 = v54;
    do
    {
      for ( i = v67; i < v55; ++i )
      {
        if ( SLODWORD(v69->mNext) > *((_DWORD *)&v54->mNext + i) )
        {
          v71 = v11[v68].mNext;
          v11[v68] = v11[i];
          v11[i].mNext = v71;
          LODWORD(v71) = v69->mNext;
          LODWORD(v69->mNext) = *((_DWORD *)&v54->mNext + i);
          *((_DWORD *)&v54->mNext + i) = (_DWORD)v71;
        }
      }
      ++v67;
      ++v68;
      v69 = (UFG::allocator::free_link *)((char *)v69 + 4);
    }
    while ( v68 < v55 );
  }
  v72 = *(_QWORD *)(v105 + 24);
  v73 = *(unsigned __int8 *)(v72 + 56);
  v106 = *(unsigned __int8 *)(v72 + 56);
  v74 = 0;
  LODWORD(v105) = 0;
  v75 = 0i64;
  if ( v55 > 0 )
  {
    v76 = stimulus_emitter_object;
    do
    {
      if ( v74 + *((_DWORD *)&v54->mNext + v75) >= v107 )
        break;
      stimulus_parameters.m_StimulusEmissionType = 0;
      stimulus_parameters.m_MaxStimulusDuration = -1.0;
      stimulus_parameters.m_EmitUntilSpeedLessThan = -1.0;
      stimulus_parameters.m_StimulusProducerOffset = UFG::qVector3::msZero;
      v77 = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)v11[v75].mNext[6].mNext[5].mNext;
      v99 = UFG::StimulusManager::s_pInstance;
      stimulus_description = &UFG::g_StimulusDescriptions[v73];
      if ( v76 )
      {
        v78 = UFG::SimObject::GetComponentOfType(v76, UFG::StimulusEmitterComponent::_TypeUID);
        if ( v78 )
        {
          v79 = v106;
          do
          {
            v80 = UFG::SimObject::GetComponentOfType(
                    v78->m_pSimObject,
                    UFG::StimulusEmitterComponent::_StimulusEmitterComponentTypeUID,
                    0,
                    v78);
            if ( LODWORD(v78[1].m_SafePointerList.mNode.mNext) == v79
              && BYTE4(v78[6].m_BoundComponentHandles.mNode.mPrev)
              && v78[8].vfptr == v77 )
            {
              UFG::Simulation::DestroySimComponent(&UFG::gSim, v78);
            }
            v78 = (UFG::SimComponent *)&v80->vfptr;
          }
          while ( v80 );
          v55 = v103;
          v76 = stimulus_emitter_object;
        }
        v74 = v105;
      }
      v81 = UFG::StimulusManager::AttachStimulusEmitterComponent(
              v99,
              stimulus_description,
              &stimulus_parameters,
              v76,
              0);
      v82 = v81;
      if ( v77 && v81 )
      {
        BYTE4(v81[6].m_BoundComponentHandles.mNode.mPrev) = 0;
        LODWORD(v81[7].m_pSimObject) = 0;
        v81[7].m_SafePointerList.mNode.mNext = 0i64;
        v83 = &v81[7].m_BoundComponentHandles;
        if ( v81[8].vfptr )
        {
          v84 = v83->mNode.mPrev;
          v85 = v81[7].m_BoundComponentHandles.mNode.mNext;
          v84->mNext = v85;
          v85->mPrev = v84;
          v83->mNode.mPrev = &v83->mNode;
          v83->mNode.mNext = &v83->mNode;
        }
        v83[1].mNode.mPrev = 0i64;
        BYTE4(v82[6].m_BoundComponentHandles.mNode.mPrev) = 1;
        if ( v83[1].mNode.mPrev )
        {
          v86 = v83->mNode.mPrev;
          v87 = v83->mNode.mNext;
          v86->mNext = v87;
          v87->mPrev = v86;
          v83->mNode.mPrev = &v83->mNode;
          v83->mNode.mNext = &v83->mNode;
        }
        v83[1].mNode.mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)v77;
        v88 = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)v77[1].__vecDelDtor;
        v88->mNext = &v83->mNode;
        v83->mNode.mPrev = v88;
        v83->mNode.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v77[1];
        v77[1].__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int))v83;
      }
      v74 += *((_DWORD *)&v54->mNext + v75);
      LODWORD(v105) = v74;
      ++v75;
      v73 = v106;
    }
    while ( v75 < v55 );
  }
  if ( v54 )
    operator delete[](v54);
  *(_QWORD *)delete_simobject_upon_expiry = 0i64;
  v103 = 0i64;
  v89 = &stimulus_emitter_object[-1].m_UnboundComponentHandles;
  v90 = (UFG::SimObject *)v100;
  if ( &stimulus_emitter_object[-1].m_UnboundComponentHandles != (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,1,0> *)v100 )
  {
    do
    {
      v91 = v89 + 1;
      v92 = v89[1].mNode.mPrev;
      v93 = v89[1].mNode.mNext;
      v92->mNext = v93;
      v93->mPrev = v92;
      v91->mNode.mPrev = &v91->mNode;
      v91->mNode.mNext = &v91->mNode;
      v89 = &stimulus_emitter_object[-1].m_UnboundComponentHandles;
    }
    while ( &stimulus_emitter_object[-1].m_UnboundComponentHandles != (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,1,0> *)v90 );
  }
  v94 = v100;
  v95 = stimulus_emitter_object;
  v100[1] = (__int64)stimulus_emitter_object;
  v95->vfptr = (UFG::qSafePointerNode<UFG::SimObject>Vtbl *)v94;
  v100 = (__int64 *)&v100;
  stimulus_emitter_object = (UFG::SimObject *)&v100;
  if ( v11 )
    operator delete[](v11);
}&v100;
  stimulus_emitter_object = (UFG::SimObject *)&v100;
  if ( v11 )
    operator delete[](v11);
}

// File Line: 6784
// RVA: 0x32CCB0
void __fastcall AttackRightsScoreBonusTask::AttackRightsScoreBonusTask(AttackRightsScoreBonusTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax
  UFG::qNode<AttackRightsScoreBonusTask,HasAttackRequestComponentList> *v2; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<AttackRightsScoreBonusTrack>::`vftable;
  v2 = (UFG::qNode<AttackRightsScoreBonusTask,HasAttackRequestComponentList> *)&this->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->vfptr = (ITaskVtbl *)&AttackRightsScoreBonusTask::`vftable;
}

// File Line: 6812
// RVA: 0x344040
void __fastcall AttackRightsScoreBonusTask::Begin(AttackRightsScoreBonusTask *this, ActionContext *action_context)
{
  AttackRightsScoreBonusTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rax
  unsigned __int16 *v6; // rdx
  UFG::qNode<AttackRightsScoreBonusTask,HasAttackRequestComponentList> *v7; // rcx
  UFG::qNode<AttackRightsScoreBonusTask,HasAttackRequestComponentList> *v8; // rax

  v2 = this;
  this->m_pActionContext = action_context;
  v3 = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = v3->m_Components.p[35].m_pComponent;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
      {
        v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HasAttackRequestComponent::_TypeUID);
      }
      else if ( (v4 >> 12) & 1 )
      {
        v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HasAttackRequestComponent::_TypeUID);
      }
      else
      {
        v5 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::HasAttackRequestComponent::_TypeUID);
      }
    }
    else
    {
      v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HasAttackRequestComponent::_TypeUID);
    }
    if ( v5 )
    {
      v6 = &v5[1].m_Flags;
      v7 = (UFG::qNode<AttackRightsScoreBonusTask,HasAttackRequestComponentList> *)&v2->mPrev;
      v8 = *(UFG::qNode<AttackRightsScoreBonusTask,HasAttackRequestComponentList> **)&v5[1].m_Flags;
      v8->mNext = (UFG::qNode<AttackRightsScoreBonusTask,HasAttackRequestComponentList> *)&v2->mPrev;
      v7->mPrev = v8;
      v7->mNext = (UFG::qNode<AttackRightsScoreBonusTask,HasAttackRequestComponentList> *)v6;
      *(_QWORD *)v6 = (char *)v2 + 40;
    }
  }
}

// File Line: 6845
// RVA: 0x332410
void __fastcall TargetActionRequestTask::TargetActionRequestTask(TargetActionRequestTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AICharacterControllerBaseComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v5; // [rsp+28h] [rbp+10h]

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<TargetActionRequestTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&TargetActionRequestTask::`vftable;
  v2 = &this->m_pCharControllerComp;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  this->m_pCharControllerComp.m_pPointer = 0i64;
  v5 = &this->m_pTarget;
  v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v5->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  this->m_pTarget.m_pPointer = 0i64;
  this->m_pActionContext = 0i64;
  if ( this->m_pCharControllerComp.m_pPointer )
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

// File Line: 6853
// RVA: 0x33B560
void __fastcall TargetActionRequestTask::~TargetActionRequestTask(TargetActionRequestTask *this)
{
  TargetActionRequestTask *v1; // r8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AICharacterControllerBaseComponent> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<ITask,ITask> *v12; // rdx
  UFG::qNode<ITask,ITask> *v13; // rcx
  UFG::qNode<ITask,ITask> *v14; // rax

  v1 = this;
  this->vfptr = (ITaskVtbl *)&TargetActionRequestTask::`vftable;
  v2 = &this->m_pTarget;
  if ( this->m_pTarget.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  }
  v2->m_pPointer = 0i64;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v7 = &v1->m_pCharControllerComp;
  if ( v1->m_pCharControllerComp.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v1->m_pCharControllerComp.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v1->m_pCharControllerComp.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pCharControllerComp.mPrev;
  }
  v1->m_pCharControllerComp.m_pPointer = 0i64;
  v10 = v7->mPrev;
  v11 = v1->m_pCharControllerComp.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v1->m_pCharControllerComp.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pCharControllerComp.mPrev;
  v1->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v12 = (UFG::qNode<ITask,ITask> *)&v1->mPrev;
  v13 = v1->mPrev;
  v14 = v1->mNext;
  v13->mNext = v14;
  v14->mPrev = v13;
  v12->mPrev = v12;
  v12->mNext = v12;
}

// File Line: 6858
// RVA: 0x348910
void __fastcall TargetActionRequestTask::Begin(TargetActionRequestTask *this, ActionContext *action_context)
{
  ITrack *v2; // rax
  __int64 v3; // rsi
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v4; // rbx
  TargetActionRequestTask *v5; // rdi
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::SimObjectGame *v8; // rcx
  unsigned __int16 v9; // dx
  UFG::SimComponent *v10; // r8
  UFG::SimComponent *v11; // rax
  UFG::SimObject *v12; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v15; // rax
  UFG::SimObjectCVBase *v16; // rcx
  unsigned __int16 v17; // dx
  UFG::AICharacterControllerBaseComponent *v18; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AICharacterControllerBaseComponent> *v19; // rdx
  UFG::AICharacterControllerBaseComponent *v20; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v21; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v22; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v23; // rax

  v2 = this->m_Track;
  this->m_pActionContext = action_context;
  v3 = HIDWORD(v2[1].vfptr);
  v4 = &this->m_pTarget;
  v5 = this;
  if ( this->m_pTarget.m_pPointer )
  {
    v6 = v4->mPrev;
    v7 = this->m_pTarget.mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v4->mPrev;
    this->m_pTarget.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->m_pTarget.mPrev;
  }
  this->m_pTarget.m_pPointer = 0i64;
  v8 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
  if ( v8 )
  {
    v9 = v8->m_Flags;
    if ( (v9 >> 14) & 1 )
    {
      v10 = v8->m_Components.p[20].m_pComponent;
    }
    else if ( (v9 & 0x8000u) == 0 )
    {
      if ( (v9 >> 13) & 1 )
        v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        v11 = (v9 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v8->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
      v10 = v11;
    }
    else
    {
      v10 = v8->m_Components.p[20].m_pComponent;
    }
    if ( v10 )
    {
      v12 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v10[1].m_Flags + v3 + 8)
                               + *(_QWORD *)&v10[1].m_TypeUID
                               + 40);
      if ( v12 )
      {
        if ( v4->m_pPointer )
        {
          v13 = v4->mPrev;
          v14 = v4->mNext;
          v13->mNext = v14;
          v14->mPrev = v13;
          v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v4->mPrev;
          v4->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v4->mPrev;
        }
        v4->m_pPointer = v12;
        if ( v12 )
        {
          v15 = v12->m_SafePointerList.mNode.mPrev;
          v15->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v4->mPrev;
          v4->mPrev = v15;
          v4->mNext = &v12->m_SafePointerList.mNode;
          v12->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v4->mPrev;
        }
      }
    }
  }
  v16 = (UFG::SimObjectCVBase *)v5->m_pTarget.m_pPointer;
  if ( v16 )
  {
    v17 = v16->m_Flags;
    if ( (v17 >> 14) & 1 )
    {
      v18 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v16);
    }
    else if ( (v17 & 0x8000u) == 0 )
    {
      if ( (v17 >> 13) & 1 )
      {
        v18 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                           (UFG::SimObjectGame *)&v16->vfptr,
                                                           UFG::AICharacterControllerBaseComponent::_TypeUID);
      }
      else if ( (v17 >> 12) & 1 )
      {
        v18 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                           (UFG::SimObjectGame *)&v16->vfptr,
                                                           UFG::AICharacterControllerBaseComponent::_TypeUID);
      }
      else
      {
        v18 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                           (UFG::SimObject *)&v16->vfptr,
                                                           UFG::AICharacterControllerBaseComponent::_TypeUID);
      }
    }
    else
    {
      v18 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v16);
    }
    v19 = &v5->m_pCharControllerComp;
    v20 = v18;
    if ( v5->m_pCharControllerComp.m_pPointer )
    {
      v21 = v19->mPrev;
      v22 = v5->m_pCharControllerComp.mNext;
      v21->mNext = v22;
      v22->mPrev = v21;
      v19->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v19->mPrev;
      v5->m_pCharControllerComp.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->m_pCharControllerComp.mPrev;
    }
    v5->m_pCharControllerComp.m_pPointer = (UFG::SimComponent *)&v20->vfptr;
    if ( v20 )
    {
      v23 = v20->m_SafePointerList.mNode.mPrev;
      v23->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v19->mPrev;
      v19->mPrev = v23;
      v5->m_pCharControllerComp.mNext = &v20->m_SafePointerList.mNode;
      v20->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v19->mPrev;
    }
  }
  ((void (__fastcall *)(TargetActionRequestTask *))v5->vfptr->Update)(v5);
}

// File Line: 6883
// RVA: 0x3934F0
char __fastcall TargetActionRequestTask::Update(TargetActionRequestTask *this, float timestep)
{
  UFG::SimComponent *v2; // rdx
  ITrack *v3; // rax
  __int64 v4; // r9
  signed __int64 v5; // r8
  float v6; // xmm0_4

  v2 = this->m_pCharControllerComp.m_pPointer;
  if ( v2 )
  {
    v3 = this->m_Track;
    v4 = LODWORD(v3[1].vfptr);
    v5 = 1i64 << ((_QWORD)v3[1].vfptr & 0x3F);
    *((_QWORD *)&v2[4].m_BoundComponentHandles.mNode.mPrev + ((signed __int64)(signed int)v4 >> 6)) |= v5;
    v6 = (float)(signed int)0.0;
    if ( v6 >= 255.0 )
      v6 = FLOAT_255_0;
    *((_BYTE *)&v2[5].m_BoundComponentHandles.mNode.mNext + v4) = (signed int)v6;
    v2[4].m_pSimObject = (UFG::SimObject *)((_QWORD)v2[4].m_pSimObject | v5);
  }
  return 1;
}

// File Line: 6913
// RVA: 0x3304A0
void __fastcall LockFormationPositionToCurrentPositionTask::LockFormationPositionToCurrentPositionTask(LockFormationPositionToCurrentPositionTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<LockFormationPositionToCurrentPositionTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&LockFormationPositionToCurrentPositionTask::`vftable;
  this->m_pActionContext = 0i64;
}

// File Line: 6927
// RVA: 0x346B70
void __fastcall LockFormationPositionToCurrentPositionTask::Begin(LockFormationPositionToCurrentPositionTask *this, ActionContext *action_context)
{
  UFG::SimObjectGame *v2; // r8
  unsigned __int16 v3; // cx
  UFG::SimComponent *v4; // rax

  this->m_pActionContext = action_context;
  v2 = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = v2->m_Components.p[32].m_pComponent;
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
      {
        v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::GetInFormationComponent::_TypeUID);
      }
      else if ( (v3 >> 12) & 1 )
      {
        v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::GetInFormationComponent::_TypeUID);
      }
      else
      {
        v4 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::GetInFormationComponent::_TypeUID);
      }
    }
    else
    {
      v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::GetInFormationComponent::_TypeUID);
    }
    if ( v4 )
      LOBYTE(v4[1].m_Flags) = 1;
  }
}

// File Line: 6953
// RVA: 0x355250
void __fastcall LockFormationPositionToCurrentPositionTask::End(LockFormationPositionToCurrentPositionTask *this)
{
  UFG::SimObjectGame *v1; // rcx
  unsigned __int16 v2; // dx
  UFG::SimComponent *v3; // rax

  v1 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
  if ( v1 )
  {
    v2 = v1->m_Flags;
    if ( (v2 >> 14) & 1 )
    {
      v3 = v1->m_Components.p[32].m_pComponent;
    }
    else if ( (v2 & 0x8000u) == 0 )
    {
      if ( (v2 >> 13) & 1 )
      {
        v3 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::GetInFormationComponent::_TypeUID);
      }
      else if ( (v2 >> 12) & 1 )
      {
        v3 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::GetInFormationComponent::_TypeUID);
      }
      else
      {
        v3 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v1->vfptr, UFG::GetInFormationComponent::_TypeUID);
      }
    }
    else
    {
      v3 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::GetInFormationComponent::_TypeUID);
    }
    if ( v3 )
      LOBYTE(v3[1].m_Flags) = 0;
  }
}

// File Line: 6971
// RVA: 0x32E870
void __fastcall ForceUpdateTargetingTask::ForceUpdateTargetingTask(ForceUpdateTargetingTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemPedBaseComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<ForceUpdateTargetingTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&ForceUpdateTargetingTask::`vftable;
  v2 = &this->m_pTargetingSystemPedBaseComponent;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  this->m_pTargetingSystemPedBaseComponent.m_pPointer = 0i64;
  this->m_pActionContext = 0i64;
  if ( this->m_pTargetingSystemPedBaseComponent.m_pPointer )
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

// File Line: 6979
// RVA: 0x337000
void __fastcall ForceUpdateTargetingTask::~ForceUpdateTargetingTask(ForceUpdateTargetingTask *this)
{
  ForceUpdateTargetingTask *v1; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemPedBaseComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rdx
  UFG::qNode<ITask,ITask> *v8; // rcx
  UFG::qNode<ITask,ITask> *v9; // rax

  v1 = this;
  this->vfptr = (ITaskVtbl *)&ForceUpdateTargetingTask::`vftable;
  v2 = &this->m_pTargetingSystemPedBaseComponent;
  if ( this->m_pTargetingSystemPedBaseComponent.m_pPointer )
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
  v1->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v7 = (UFG::qNode<ITask,ITask> *)&v1->mPrev;
  v8 = v1->mPrev;
  v9 = v1->mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v7->mPrev = v7;
  v7->mNext = v7;
}

// File Line: 6983
// RVA: 0x345260
void __fastcall ForceUpdateTargetingTask::Begin(ForceUpdateTargetingTask *this, ActionContext *action_context)
{
  ForceUpdateTargetingTask *v2; // rbx
  UFG::SimObjectCVBase *v3; // rcx
  UFG::TargetingSystemPedBaseComponent *v4; // r8
  unsigned __int16 v5; // dx
  UFG::TargetingSystemPedBaseComponent *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemPedBaseComponent> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax

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
        v6 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedBaseComponent>(v3);
      }
      else if ( (v5 & 0x8000u) == 0 )
      {
        if ( (v5 >> 13) & 1 )
        {
          v6 = (UFG::TargetingSystemPedBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         (UFG::SimObjectGame *)&v3->vfptr,
                                                         UFG::TargetingSystemPedBaseComponent::_TypeUID);
        }
        else if ( (v5 >> 12) & 1 )
        {
          v6 = (UFG::TargetingSystemPedBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         (UFG::SimObjectGame *)&v3->vfptr,
                                                         UFG::TargetingSystemPedBaseComponent::_TypeUID);
        }
        else
        {
          v6 = (UFG::TargetingSystemPedBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                         (UFG::SimObject *)&v3->vfptr,
                                                         UFG::TargetingSystemPedBaseComponent::_TypeUID);
        }
      }
      else
      {
        v6 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedBaseComponent>(v3);
      }
      v4 = v6;
    }
    else
    {
      v4 = 0i64;
    }
    v7 = &v2->m_pTargetingSystemPedBaseComponent;
    if ( v2->m_pTargetingSystemPedBaseComponent.m_pPointer )
    {
      v8 = v7->mPrev;
      v9 = v2->m_pTargetingSystemPedBaseComponent.mNext;
      v8->mNext = v9;
      v9->mPrev = v8;
      v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
      v2->m_pTargetingSystemPedBaseComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pTargetingSystemPedBaseComponent.mPrev;
    }
    v2->m_pTargetingSystemPedBaseComponent.m_pPointer = (UFG::SimComponent *)&v4->vfptr;
    if ( v4 )
    {
      v10 = v4->m_SafePointerList.mNode.mPrev;
      v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
      v7->mPrev = v10;
      v2->m_pTargetingSystemPedBaseComponent.mNext = &v4->m_SafePointerList.mNode;
      v4->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    }
  }
}

// File Line: 6995
// RVA: 0x38F210
char __fastcall ForceUpdateTargetingTask::Update(ForceUpdateTargetingTask *this, float timestep)
{
  UFG::SimComponent *v2; // rax

  v2 = this->m_pTargetingSystemPedBaseComponent.m_pPointer;
  if ( v2 )
    LOBYTE(v2[9].vfptr) = 1;
  return 1;
}

// File Line: 7013
// RVA: 0x343DC0
void __fastcall AddTargetAsDangerousEntityTask::Begin(AddTargetAsDangerousEntityTask *this, ActionContext *action_context)
{
  AddTargetAsDangerousEntityTask *v2; // rsi
  UFG::SimObjectCVBase *v3; // rcx
  ActionContext *v4; // rdi
  unsigned __int16 v5; // r8
  UFG::ActiveAIEntityComponent *v6; // rax
  UFG::AIEntityComponent *v7; // rbx
  UFG::SimObjectGame *v8; // rcx
  unsigned __int16 v9; // dx
  UFG::SimComponent *v10; // rdx
  UFG::SimComponent *v11; // rax

  v2 = this;
  v3 = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
  v4 = action_context;
  if ( v3 )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v3);
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
        v6 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               (UFG::SimObjectGame *)&v3->vfptr,
                                               UFG::ActiveAIEntityComponent::_TypeUID);
      else
        v6 = (UFG::ActiveAIEntityComponent *)((v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                 (UFG::SimObjectGame *)&v3->vfptr,
                                                                 UFG::ActiveAIEntityComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::ActiveAIEntityComponent::_TypeUID));
    }
    else
    {
      v6 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v3);
    }
    v7 = (UFG::AIEntityComponent *)&v6->vfptr;
    if ( v6 )
    {
      v8 = (UFG::SimObjectGame *)v4->mSimObject.m_pPointer;
      if ( v8 )
      {
        v9 = v8->m_Flags;
        if ( (v9 >> 14) & 1 )
        {
          v10 = v8->m_Components.p[20].m_pComponent;
        }
        else if ( (v9 & 0x8000u) == 0 )
        {
          if ( (v9 >> 13) & 1 )
          {
            v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::TargetingSystemBaseComponent::_TypeUID);
          }
          else if ( (v9 >> 12) & 1 )
          {
            v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::TargetingSystemBaseComponent::_TypeUID);
          }
          else
          {
            v11 = UFG::SimObject::GetComponentOfType(
                    (UFG::SimObject *)&v8->vfptr,
                    UFG::TargetingSystemBaseComponent::_TypeUID);
          }
          v10 = v11;
        }
        else
        {
          v10 = v8->m_Components.p[20].m_pComponent;
        }
        if ( v10 )
          UFG::AIEntityComponent::AddThreatTarget(
            v7,
            *(UFG::SimObject **)(56i64
                               * *(unsigned __int8 *)(LOBYTE(v2->m_Track[1].vfptr) + *(_QWORD *)&v10[1].m_Flags + 8i64)
                               + *(_QWORD *)&v10[1].m_TypeUID
                               + 40),
            *((float *)&v2->m_Track[1].vfptr + 1));
      }
    }
  }
}

// File Line: 7037
// RVA: 0x331C20
void __fastcall SetDriverFlagsTask::SetDriverFlagsTask(SetDriverFlagsTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AiDriverComponent> *v2; // [rsp+28h] [rbp+10h]

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<SetDriverFlagsTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&SetDriverFlagsTask::`vftable;
  v2 = &this->m_pAIDriverComponent;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  this->m_pAIDriverComponent.m_pPointer = 0i64;
  *(_DWORD *)&this->m_PrevAvoidPeds = 0;
}

// File Line: 7045
// RVA: 0x33ACA0
void __fastcall SetDriverFlagsTask::~SetDriverFlagsTask(SetDriverFlagsTask *this)
{
  SetDriverFlagsTask *v1; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::AiDriverComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rdx
  UFG::qNode<ITask,ITask> *v8; // rcx
  UFG::qNode<ITask,ITask> *v9; // rax

  v1 = this;
  this->vfptr = (ITaskVtbl *)&SetDriverFlagsTask::`vftable;
  v2 = &this->m_pAIDriverComponent;
  if ( this->m_pAIDriverComponent.m_pPointer )
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
  v1->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v7 = (UFG::qNode<ITask,ITask> *)&v1->mPrev;
  v8 = v1->mPrev;
  v9 = v1->mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v7->mPrev = v7;
  v7->mNext = v7;
}

// File Line: 7050
// RVA: 0x348660
void __fastcall SetDriverFlagsTask::Begin(SetDriverFlagsTask *this, ActionContext *action_context)
{
  SetDriverFlagsTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rax
  const char *v6; // rax
  UFG::SimObjectCVBase *v7; // rcx
  unsigned __int16 v8; // dx
  UFG::AiDriverComponent *v9; // rdx
  UFG::qSafePointer<UFG::SimComponent,UFG::AiDriverComponent> *v10; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::AiDriverComponent *v14; // rcx

  v2 = this;
  this->m_pActionContext = action_context;
  v3 = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = v3->m_Components.p[44].m_pComponent;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
        v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterOccupantComponent::_TypeUID);
      else
        v5 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterOccupantComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::CharacterOccupantComponent::_TypeUID);
    }
    else
    {
      v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterOccupantComponent::_TypeUID);
    }
    if ( v5 )
    {
      v6 = SSInvokedMethod::get_invokable((UFG::UIMapBlip *)v5);
      if ( v6 && (v7 = (UFG::SimObjectCVBase *)*((_QWORD *)v6 + 5)) != 0i64 )
      {
        v8 = v7->m_Flags;
        if ( (v8 >> 14) & 1 )
        {
          v9 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v7);
        }
        else if ( (v8 & 0x8000u) == 0 )
        {
          if ( (v8 >> 13) & 1 )
          {
            v9 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             (UFG::SimObjectGame *)&v7->vfptr,
                                             UFG::AiDriverComponent::_TypeUID);
          }
          else if ( (v8 >> 12) & 1 )
          {
            v9 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             (UFG::SimObjectGame *)&v7->vfptr,
                                             UFG::AiDriverComponent::_TypeUID);
          }
          else
          {
            v9 = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                             (UFG::SimObject *)&v7->vfptr,
                                             UFG::AiDriverComponent::_TypeUID);
          }
        }
        else
        {
          v9 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v7);
        }
      }
      else
      {
        v9 = 0i64;
      }
      if ( v9 )
      {
        v10 = &v2->m_pAIDriverComponent;
        if ( v2->m_pAIDriverComponent.m_pPointer )
        {
          v11 = v10->mPrev;
          v12 = v2->m_pAIDriverComponent.mNext;
          v11->mNext = v12;
          v12->mPrev = v11;
          v10->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v10->mPrev;
          v2->m_pAIDriverComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pAIDriverComponent.mPrev;
        }
        v2->m_pAIDriverComponent.m_pPointer = (UFG::SimComponent *)&v9->vfptr;
        v13 = v9->m_SafePointerList.mNode.mPrev;
        v13->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v10->mPrev;
        v10->mPrev = v13;
        v2->m_pAIDriverComponent.mNext = &v9->m_SafePointerList.mNode;
        v9->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v10->mPrev;
        v14 = (UFG::AiDriverComponent *)v2->m_pAIDriverComponent.m_pPointer;
        v2->m_PrevAvoidPeds = v14->m_bAvoidPeds;
        v2->m_PrevAllowedToPass = v14->m_bAllowedToPass;
        v2->m_PrevStayOffSidewalk = v14->m_bStayOffSidewalk;
        v2->m_PrevRespectSpeedLimit = v14->m_bRespectSpeedLimit;
        UFG::AiDriverComponent::SetAvoidPeds(v14, LOBYTE(v2->m_Track[1].vfptr) != 0);
        UFG::AiDriverComponent::SetAllowedToPass(
          (UFG::AiDriverComponent *)v2->m_pAIDriverComponent.m_pPointer,
          BYTE1(v2->m_Track[1].vfptr) != 0);
        UFG::AiDriverComponent::SetStayOffSidewalk(
          (UFG::AiDriverComponent *)v2->m_pAIDriverComponent.m_pPointer,
          BYTE2(v2->m_Track[1].vfptr) != 0);
        UFG::AiDriverComponent::SetRespectSpeedLimit(
          (UFG::AiDriverComponent *)v2->m_pAIDriverComponent.m_pPointer,
          BYTE3(v2->m_Track[1].vfptr) != 0);
      }
    }
  }
}

// File Line: 7084
// RVA: 0x355520
void __fastcall SetDriverFlagsTask::End(SetDriverFlagsTask *this)
{
  SetDriverFlagsTask *v1; // rbx
  UFG::AiDriverComponent *v2; // rcx

  v1 = this;
  v2 = (UFG::AiDriverComponent *)this->m_pAIDriverComponent.m_pPointer;
  if ( v2 )
  {
    UFG::AiDriverComponent::SetAvoidPeds(v2, v1->m_PrevAvoidPeds);
    UFG::AiDriverComponent::SetAllowedToPass(
      (UFG::AiDriverComponent *)v1->m_pAIDriverComponent.m_pPointer,
      v1->m_PrevAllowedToPass);
    UFG::AiDriverComponent::SetStayOffSidewalk(
      (UFG::AiDriverComponent *)v1->m_pAIDriverComponent.m_pPointer,
      v1->m_PrevStayOffSidewalk);
    UFG::AiDriverComponent::SetRespectSpeedLimit(
      (UFG::AiDriverComponent *)v1->m_pAIDriverComponent.m_pPointer,
      v1->m_PrevRespectSpeedLimit);
  }
}

// File Line: 7105
// RVA: 0x32CD60
void __fastcall AttackRightsSetTimeUntilNextAttackTask::AttackRightsSetTimeUntilNextAttackTask(AttackRightsSetTimeUntilNextAttackTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<AttackRightsSetTimeUntilNextAttackTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&AttackRightsSetTimeUntilNextAttackTask::`vftable;
}

// File Line: 7126
// RVA: 0x38D320
char __fastcall AttackRightsSetTimeUntilNextAttackTask::Update(AttackRightsSetTimeUntilNextAttackTask *this, float timestep)
{
  AttackRightsSetTimeUntilNextAttackTask *v2; // rdi
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // r8
  UFG::SimComponent *v6; // rax
  UFG::SimObjectGame *v7; // r8
  unsigned __int16 v8; // cx
  UFG::SimComponent *v9; // rbx
  UFG::SimComponent *v10; // rax
  ITrack *v11; // rcx
  __int64 v12; // rsi
  float v13; // xmm7_4
  float v14; // xmm6_4
  UFG::qSymbolUC *v15; // rcx
  float v16; // xmm0_4

  v2 = this;
  v3 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
  if ( !v3 )
    return 1;
  v4 = v3->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    v5 = v3->m_Components.p[20].m_pComponent;
  }
  else if ( (v4 & 0x8000u) == 0 )
  {
    if ( (v4 >> 13) & 1 )
      v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
    else
      v6 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
    v5 = v6;
  }
  else
  {
    v5 = v3->m_Components.p[20].m_pComponent;
  }
  if ( !v5 )
    return 1;
  v7 = *(UFG::SimObjectGame **)(56i64
                              * *(unsigned __int8 *)(LOBYTE(v2->m_Track[1].vfptr) + *(_QWORD *)&v5[1].m_Flags + 8i64)
                              + *(_QWORD *)&v5[1].m_TypeUID
                              + 40);
  if ( !v7 )
    return 1;
  v8 = v7->m_Flags;
  if ( (v8 >> 14) & 1 )
  {
    v9 = v7->m_Components.p[46].m_pComponent;
  }
  else
  {
    if ( (v8 & 0x8000u) == 0 )
    {
      if ( (v8 >> 13) & 1 )
      {
        v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::AttackRightsComponent::_TypeUID);
      }
      else if ( (v8 >> 12) & 1 )
      {
        v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::AttackRightsComponent::_TypeUID);
      }
      else
      {
        v10 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::AttackRightsComponent::_TypeUID);
      }
    }
    else
    {
      v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::AttackRightsComponent::_TypeUID);
    }
    v9 = v10;
  }
  if ( !v9 )
    return 1;
  v11 = v2->m_Track;
  v12 = BYTE4(v11[1].mResourceOwner);
  v11 = (ITrack *)((char *)v11 + 72);
  v13 = *(&v11[-1].mMasterRate.value + 1);
  v14 = v11[-1].mTimeBegin;
  ActionPath::GetString_DBG((ActionPath *)v11);
  v15 = (UFG::qSymbolUC *)v2->m_pActionContext->mSimObject.m_pPointer;
  if ( v15 )
    UFG::qSymbol::as_cstr_dbg(v15 + 18);
  v16 = v14;
  if ( v14 > v13 )
  {
    v16 = UFG::qRandom(v14 - v13, &UFG::qDefaultSeed) + v13;
    if ( v16 <= v13 )
      v16 = v13;
    if ( v16 >= v14 )
      v16 = v14;
  }
  if ( !LOBYTE(v9[149].m_BoundComponentHandles.mNode.mPrev) )
    *((float *)&v9[148].m_BoundComponentHandles.mNode.mPrev + v12 + 1) = v16;
  return 1;
}

// File Line: 7160
// RVA: 0x32C860
void __fastcall AttackRightsClearPreviousBestAttackerTask::AttackRightsClearPreviousBestAttackerTask(AttackRightsClearPreviousBestAttackerTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<AttackRightsClearPreviousBestAttackerTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&AttackRightsClearPreviousBestAttackerTask::`vftable;
  this->m_pActionContext = 0i64;
}

// File Line: 7183
// RVA: 0x38CC20
char __fastcall AttackRightsClearPreviousBestAttackerTask::Update(AttackRightsClearPreviousBestAttackerTask *this, float timestep)
{
  AttackRightsClearPreviousBestAttackerTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // r8
  UFG::SimComponent *v6; // rax
  UFG::SimObjectGame *v7; // r8
  unsigned __int16 v8; // cx
  UFG::AttackRightsComponent *v9; // rcx
  UFG::SimComponent *v10; // rax

  v2 = this;
  v3 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
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
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        v6 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
      v5 = v6;
    }
    else
    {
      v5 = v3->m_Components.p[20].m_pComponent;
    }
    if ( v5 )
    {
      v7 = *(UFG::SimObjectGame **)(56i64
                                  * *(unsigned __int8 *)(LOBYTE(v2->m_Track[1].vfptr) + *(_QWORD *)&v5[1].m_Flags + 8i64)
                                  + *(_QWORD *)&v5[1].m_TypeUID
                                  + 40);
      if ( v7 )
      {
        v8 = v7->m_Flags;
        if ( (v8 >> 14) & 1 )
        {
          v9 = (UFG::AttackRightsComponent *)v7->m_Components.p[46].m_pComponent;
        }
        else
        {
          if ( (v8 & 0x8000u) == 0 )
          {
            if ( (v8 >> 13) & 1 )
            {
              v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::AttackRightsComponent::_TypeUID);
            }
            else if ( (v8 >> 12) & 1 )
            {
              v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::AttackRightsComponent::_TypeUID);
            }
            else
            {
              v10 = UFG::SimObject::GetComponentOfType(
                      (UFG::SimObject *)&v7->vfptr,
                      UFG::AttackRightsComponent::_TypeUID);
            }
          }
          else
          {
            v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::AttackRightsComponent::_TypeUID);
          }
          v9 = (UFG::AttackRightsComponent *)v10;
        }
        if ( v9 )
          UFG::AttackRightsComponent::ClearPreviousBestAttacker(v9, (UFG::eAttackType)BYTE1(v2->m_Track[1].vfptr));
      }
    }
  }
  return 1;
}

// File Line: 7211
// RVA: 0x32CC10
void __fastcall AttackRightsReSortListTask::AttackRightsReSortListTask(AttackRightsReSortListTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<AttackRightsReSortListTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&AttackRightsReSortListTask::`vftable;
  this->m_pActionContext = 0i64;
}

// File Line: 7234
// RVA: 0x38D1E0
char __fastcall AttackRightsReSortListTask::Update(AttackRightsReSortListTask *this, float timestep)
{
  AttackRightsReSortListTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // r8
  UFG::SimComponent *v6; // rax
  UFG::SimObjectGame *v7; // r8
  unsigned __int16 v8; // cx
  UFG::AttackRightsComponent *v9; // rcx
  UFG::SimComponent *v10; // rax

  v2 = this;
  v3 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
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
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        v6 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
      v5 = v6;
    }
    else
    {
      v5 = v3->m_Components.p[20].m_pComponent;
    }
    if ( v5 )
    {
      v7 = *(UFG::SimObjectGame **)(56i64
                                  * *(unsigned __int8 *)(LOBYTE(v2->m_Track[1].vfptr) + *(_QWORD *)&v5[1].m_Flags + 8i64)
                                  + *(_QWORD *)&v5[1].m_TypeUID
                                  + 40);
      if ( v7 )
      {
        v8 = v7->m_Flags;
        if ( (v8 >> 14) & 1 )
        {
          v9 = (UFG::AttackRightsComponent *)v7->m_Components.p[46].m_pComponent;
        }
        else
        {
          if ( (v8 & 0x8000u) == 0 )
          {
            if ( (v8 >> 13) & 1 )
            {
              v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::AttackRightsComponent::_TypeUID);
            }
            else if ( (v8 >> 12) & 1 )
            {
              v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::AttackRightsComponent::_TypeUID);
            }
            else
            {
              v10 = UFG::SimObject::GetComponentOfType(
                      (UFG::SimObject *)&v7->vfptr,
                      UFG::AttackRightsComponent::_TypeUID);
            }
          }
          else
          {
            v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::AttackRightsComponent::_TypeUID);
          }
          v9 = (UFG::AttackRightsComponent *)v10;
        }
        if ( v9 )
          UFG::AttackRightsComponent::SortAttackSlots(v9, (UFG::eAttackType)BYTE1(v2->m_Track[1].vfptr));
      }
    }
  }
  return 1;
}

// File Line: 7262
// RVA: 0x32C7C0
void __fastcall AttackRightsCancelAnyIncomingAttackTask::AttackRightsCancelAnyIncomingAttackTask(AttackRightsCancelAnyIncomingAttackTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<AttackRightsCancelAnyIncomingAttackTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&AttackRightsCancelAnyIncomingAttackTask::`vftable;
  this->m_pActionContext = 0i64;
}

// File Line: 7285
// RVA: 0x38CAA0
char __fastcall AttackRightsCancelAnyIncomingAttackTask::Update(AttackRightsCancelAnyIncomingAttackTask *this, float timestep)
{
  AttackRightsCancelAnyIncomingAttackTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // r8
  UFG::SimComponent *v6; // rax
  UFG::SimObjectGame *v7; // r8
  unsigned __int16 v8; // cx
  UFG::AttackRightsComponent *v9; // rcx
  UFG::SimComponent *v10; // rax
  ITrack *v11; // r9
  signed __int64 v12; // r8
  UFG::HasAttackRequestNode *v13; // rax
  UFG::SimComponent *v14; // rax

  v2 = this;
  v3 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
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
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        v6 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
      v5 = v6;
    }
    else
    {
      v5 = v3->m_Components.p[20].m_pComponent;
    }
    if ( v5 )
    {
      v7 = *(UFG::SimObjectGame **)(56i64
                                  * *(unsigned __int8 *)(LOBYTE(v2->m_Track[1].vfptr) + *(_QWORD *)&v5[1].m_Flags + 8i64)
                                  + *(_QWORD *)&v5[1].m_TypeUID
                                  + 40);
      if ( v7 )
      {
        v8 = v7->m_Flags;
        if ( (v8 >> 14) & 1 )
        {
          v9 = (UFG::AttackRightsComponent *)v7->m_Components.p[46].m_pComponent;
        }
        else
        {
          if ( (v8 & 0x8000u) == 0 )
          {
            if ( (v8 >> 13) & 1 )
              v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::AttackRightsComponent::_TypeUID);
            else
              v10 = (v8 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::AttackRightsComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::AttackRightsComponent::_TypeUID);
          }
          else
          {
            v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::AttackRightsComponent::_TypeUID);
          }
          v9 = (UFG::AttackRightsComponent *)v10;
        }
        if ( v9 )
        {
          v11 = v2->m_Track;
          v12 = BYTE1(v11[1].vfptr);
          v13 = v9->m_pLastAttackRequest[BYTE1(v11[1].vfptr)].m_pPointer;
          if ( v13 )
          {
            v14 = v13->m_pOwner.m_pPointer;
            if ( v14 )
              *((float *)&v14[1].m_BoundComponentHandles.mNode.mPrev + BYTE1(v11[1].vfptr)) = UFG::Metrics::msInstance.mSimTime_Temp
                                                                                            + *((float *)&v11[1].vfptr
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
void __fastcall AttackRightsFormationManagerFreezeRangeSwitchesTask::AttackRightsFormationManagerFreezeRangeSwitchesTask(AttackRightsFormationManagerFreezeRangeSwitchesTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<AttackRightsFormationManagerFreezeRangeSwitchesTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&AttackRightsFormationManagerFreezeRangeSwitchesTask::`vftable;
  this->m_pActionContext = 0i64;
}

// File Line: 7328
// RVA: 0x343F10
void __fastcall AttackRightsFormationManagerFreezeRangeSwitchesTask::Begin(AttackRightsFormationManagerFreezeRangeSwitchesTask *this, ActionContext *action_context)
{
  AttackRightsFormationManagerFreezeRangeSwitchesTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // r8
  UFG::SimComponent *v6; // rax
  UFG::SimObjectGame *v7; // rcx
  unsigned __int16 v8; // dx
  UFG::SimComponent *v9; // rax

  v2 = this;
  this->m_pActionContext = action_context;
  v3 = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
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
      v7 = *(UFG::SimObjectGame **)(56i64
                                  * *(unsigned __int8 *)(LOBYTE(v2->m_Track[1].vfptr) + *(_QWORD *)&v5[1].m_Flags + 8i64)
                                  + *(_QWORD *)&v5[1].m_TypeUID
                                  + 40);
      if ( v7 )
      {
        v8 = v7->m_Flags;
        if ( (v8 >> 14) & 1 )
        {
          v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::FormationManagerComponent::_TypeUID);
        }
        else if ( (v8 & 0x8000u) == 0 )
        {
          if ( (v8 >> 13) & 1 )
          {
            v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::FormationManagerComponent::_TypeUID);
          }
          else if ( (v8 >> 12) & 1 )
          {
            v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::FormationManagerComponent::_TypeUID);
          }
          else
          {
            v9 = UFG::SimObject::GetComponentOfType(
                   (UFG::SimObject *)&v7->vfptr,
                   UFG::FormationManagerComponent::_TypeUID);
          }
        }
        else
        {
          v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::FormationManagerComponent::_TypeUID);
        }
        if ( v9 )
          BYTE3(v9[109].m_BoundComponentHandles.mNode.mNext) = 1;
      }
    }
  }
}

// File Line: 7349
// RVA: 0x354E00
void __fastcall AttackRightsFormationManagerFreezeRangeSwitchesTask::End(AttackRightsFormationManagerFreezeRangeSwitchesTask *this)
{
  AttackRightsFormationManagerFreezeRangeSwitchesTask *v1; // rbx
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // r8
  UFG::SimComponent *v5; // rax
  UFG::SimObjectGame *v6; // rcx
  unsigned __int16 v7; // dx
  UFG::SimComponent *v8; // rax

  v1 = this;
  v2 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = v2->m_Components.p[20].m_pComponent;
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
      {
        v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else if ( (v3 >> 12) & 1 )
      {
        v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else
      {
        v5 = UFG::SimObject::GetComponentOfType(
               (UFG::SimObject *)&v2->vfptr,
               UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      v4 = v5;
    }
    else
    {
      v4 = v2->m_Components.p[20].m_pComponent;
    }
    if ( v4 )
    {
      v6 = *(UFG::SimObjectGame **)(56i64
                                  * *(unsigned __int8 *)(LOBYTE(v1->m_Track[1].vfptr) + *(_QWORD *)&v4[1].m_Flags + 8i64)
                                  + *(_QWORD *)&v4[1].m_TypeUID
                                  + 40);
      if ( v6 )
      {
        v7 = v6->m_Flags;
        if ( (v7 >> 14) & 1 )
        {
          v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::FormationManagerComponent::_TypeUID);
        }
        else if ( (v7 & 0x8000u) == 0 )
        {
          if ( (v7 >> 13) & 1 )
          {
            v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::FormationManagerComponent::_TypeUID);
          }
          else if ( (v7 >> 12) & 1 )
          {
            v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::FormationManagerComponent::_TypeUID);
          }
          else
          {
            v8 = UFG::SimObject::GetComponentOfType(
                   (UFG::SimObject *)&v6->vfptr,
                   UFG::FormationManagerComponent::_TypeUID);
          }
        }
        else
        {
          v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::FormationManagerComponent::_TypeUID);
        }
        if ( v8 )
          BYTE3(v8[109].m_BoundComponentHandles.mNode.mNext) = 0;
      }
    }
  }
}

// File Line: 7372
// RVA: 0x32D450
void __fastcall CombatRegionMoveToTask::CombatRegionMoveToTask(CombatRegionMoveToTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax
  float v2; // xmm1_4
  float v3; // xmm2_4

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<CombatRegionMoveToTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&CombatRegionMoveToTask::`vftable;
  this->m_bFoundDestination = 0;
  v2 = UFG::qVector3::msZero.y;
  v3 = UFG::qVector3::msZero.z;
  this->m_vDestination.x = UFG::qVector3::msZero.x;
  this->m_vDestination.y = v2;
  this->m_vDestination.z = v3;
  *(_WORD *)&this->m_bTraversalStarted = 0;
}

// File Line: 7400
// RVA: 0x38DC70
bool __fastcall CombatRegionMoveToTask::Update(CombatRegionMoveToTask *this, float timestep)
{
  CombatRegionMoveToTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  UFG::NavComponent *v4; // r14
  unsigned __int16 v5; // dx
  UFG::SimComponent *v6; // rax
  UFG::SimObjectCVBase *v7; // rcx
  UFG::ActiveAIEntityComponent *v8; // rsi
  unsigned __int16 v9; // dx
  UFG::ActiveAIEntityComponent *v10; // rax
  UFG::SimObjectGame *v11; // rcx
  __m128 *v12; // rdi
  unsigned __int16 v13; // dx
  UFG::SimComponent *v14; // rax
  float v15; // xmm1_4
  float v16; // xmm2_4
  UFG::CombatRegion *v17; // rax
  UFG::DaemonManager *v18; // rax
  float v19; // xmm2_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  bool result; // al
  bool v23; // al
  char v24; // cl
  UFG::DaemonQueryOutput output; // [rsp+30h] [rbp-A8h]
  char v26; // [rsp+48h] [rbp-90h]
  __m128 v27; // [rsp+50h] [rbp-88h]
  __int64 v28; // [rsp+60h] [rbp-78h]
  UFG::DaemonQueryInput input; // [rsp+68h] [rbp-70h]
  __int64 (__fastcall **v30)(_QWORD); // [rsp+88h] [rbp-50h]
  UFG::qVector3 v31; // [rsp+90h] [rbp-48h]
  char v32; // [rsp+A0h] [rbp-38h]
  __m128 v33; // [rsp+A8h] [rbp-30h]
  __int64 v34; // [rsp+B8h] [rbp-20h]
  UFG::RegionComponent *v35; // [rsp+C8h] [rbp-10h]
  __int64 *v36; // [rsp+D0h] [rbp-8h]
  int v37; // [rsp+D8h] [rbp+0h]
  __int64 v38; // [rsp+E8h] [rbp+10h]

  v38 = -2i64;
  v2 = this;
  v3 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
  if ( v3 )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v4 = (UFG::NavComponent *)v3->m_Components.p[36].m_pComponent;
    }
    else
    {
      if ( (v5 & 0x8000u) == 0 )
      {
        if ( (v5 >> 13) & 1 )
        {
          v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::NavComponent::_TypeUID);
        }
        else if ( (v5 >> 12) & 1 )
        {
          v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::NavComponent::_TypeUID);
        }
        else
        {
          v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::NavComponent::_TypeUID);
        }
      }
      else
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::NavComponent::_TypeUID);
      }
      v4 = (UFG::NavComponent *)v6;
    }
  }
  else
  {
    v4 = 0i64;
  }
  if ( v2->m_bFoundDestination )
    goto LABEL_52;
  v7 = (UFG::SimObjectCVBase *)v2->m_pActionContext->mSimObject.m_pPointer;
  if ( v7 )
  {
    v9 = v7->m_Flags;
    if ( (v9 >> 14) & 1 )
    {
      v10 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v7);
    }
    else if ( (v9 & 0x8000u) == 0 )
    {
      if ( (v9 >> 13) & 1 )
      {
        v10 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                (UFG::SimObjectGame *)&v7->vfptr,
                                                UFG::ActiveAIEntityComponent::_TypeUID);
      }
      else if ( (v9 >> 12) & 1 )
      {
        v10 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                (UFG::SimObjectGame *)&v7->vfptr,
                                                UFG::ActiveAIEntityComponent::_TypeUID);
      }
      else
      {
        v10 = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                (UFG::SimObject *)&v7->vfptr,
                                                UFG::ActiveAIEntityComponent::_TypeUID);
      }
    }
    else
    {
      v10 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v7);
    }
    v8 = v10;
  }
  else
  {
    v8 = 0i64;
  }
  v11 = (UFG::SimObjectGame *)v2->m_pActionContext->mSimObject.m_pPointer;
  if ( v11 )
  {
    v13 = v11->m_Flags;
    if ( (v13 >> 14) & 1 )
    {
      v12 = (__m128 *)v11->m_Components.p[36].m_pComponent;
    }
    else
    {
      if ( (v13 & 0x8000u) == 0 )
      {
        if ( (v13 >> 13) & 1 )
        {
          v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::NavComponent::_TypeUID);
        }
        else if ( (v13 >> 12) & 1 )
        {
          v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::NavComponent::_TypeUID);
        }
        else
        {
          v14 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v11->vfptr, UFG::NavComponent::_TypeUID);
        }
      }
      else
      {
        v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::NavComponent::_TypeUID);
      }
      v12 = (__m128 *)v14;
    }
  }
  else
  {
    v12 = 0i64;
  }
  input.m_pOutput = 0i64;
  input.vfptr = (UFG::DaemonQueryInputVtbl *)&UFG::FindPathToRegionImmediateQuery::`vftable;
  v31 = UFG::qVector3::msZero;
  v30 = &UFG::HavokNavPosition::`vftable;
  v32 = 0;
  v33 = hkvZero_13.m_quad;
  v34 = -1i64;
  v36 = 0i64;
  v37 = -1;
  output.m_id = 0;
  *(_QWORD *)&output.m_internalType = 2i64;
  output.vfptr = (UFG::DaemonQueryOutputVtbl *)&UFG::FindPathToRegionOutput::`vftable;
  *(float *)&v28 = UFG::qVector3::msZero.z;
  v27.m128_u64[0] = (unsigned __int64)&UFG::HavokNavPosition::`vftable;
  LOBYTE(input.vfptr) = 0;
  *(hkVector4f *)&input.m_daemonType = (hkVector4f)hkvZero_13.m_quad;
  v27.m128_u64[1] = -1i64;
  v15 = v12[5].m128_f32[3];
  v16 = v12[6].m128_f32[0];
  v31.x = v12[5].m128_f32[2];
  v31.y = v15;
  v31.z = v16;
  if ( !v12[6].m128_i8[8] )
  {
    v32 = 0;
LABEL_50:
    result = 1;
    goto LABEL_51;
  }
  v32 = v12[6].m128_i8[8];
  v33 = v12[7];
  v34 = v12[8].m128_i64[0];
  if ( !UFG::HavokAIUtilGame::IsValidKey(v34, HIDWORD(v34)) || (_DWORD)v34 == -1 || HIDWORD(v34) == -1 )
    goto LABEL_50;
  v17 = v8->m_pCombatRegion.m_pPointer;
  if ( !v17 )
  {
LABEL_47:
    result = 0;
LABEL_51:
    output.vfptr = (UFG::DaemonQueryOutputVtbl *)&UFG::DaemonQueryOutput::`vftable;
    input.vfptr = (UFG::DaemonQueryInputVtbl *)&UFG::DaemonQueryInput::`vftable;
    return result;
  }
  v35 = v17->mpRegion;
  v36 = (__int64 *)((char *)&v12[11].m128_i64[1] + 4);
  v18 = UFG::DaemonManager::Instance();
  UFG::DaemonManager::SubmitQuery(v18, &input, &output);
  if ( output.m_status != 3 )
  {
    if ( CombatRegionMoveToTask::SetDestinationFromRegionCenter(v2, v8->m_pCombatRegion.m_pPointer) )
      goto LABEL_48;
    UFG::qPrintf(
      "0x%8x: CombatRegionMoveToTask::Update(): Could not get combat region center destination.\n",
      v2->m_pActionContext->mSimObject.m_pPointer);
    goto LABEL_47;
  }
  v2->m_bFoundDestination = 1;
  v19 = v27.m128_f32[2];
  v2->m_vDestination.x = v27.m128_f32[2];
  v20 = v27.m128_f32[3];
  v2->m_vDestination.y = v27.m128_f32[3];
  v21 = *(float *)&v28;
  LODWORD(v2->m_vDestination.z) = v28;
  v8->m_vCombatRegionMoveToVec.x = v19;
  v8->m_vCombatRegionMoveToVec.y = v20;
  v8->m_vCombatRegionMoveToVec.z = v21;
LABEL_48:
  output.vfptr = (UFG::DaemonQueryOutputVtbl *)&UFG::DaemonQueryOutput::`vftable;
  input.vfptr = (UFG::DaemonQueryInputVtbl *)&UFG::DaemonQueryInput::`vftable;
LABEL_52:
  if ( !v2->m_bFoundDestination )
    return 0;
  output.m_id = LODWORD(v2->m_vDestination.x);
  output.m_internalType = LODWORD(v2->m_vDestination.y);
  output.m_status = LODWORD(v2->m_vDestination.z);
  output.vfptr = (UFG::DaemonQueryOutputVtbl *)&UFG::HavokNavPosition::`vftable;
  v26 = 0;
  v28 = -1i64;
  v27 = _mm_unpacklo_ps(
          _mm_unpacklo_ps((__m128)(unsigned int)output.m_id, (__m128)(unsigned int)output.m_status),
          _mm_unpacklo_ps((__m128)output.m_internalType, (__m128)(unsigned int)FLOAT_1_0));
  UFG::NavComponent::AddGoalPoint(
    v4,
    (UFG::HavokNavPosition *)&output,
    0,
    sNaturalMovementSpeeds[BYTE1(v2->m_Track[1].vfptr)],
    0.30000001);
  v23 = UFG::NavComponent::IsAtDestination(v4);
  v24 = 0;
  if ( v23 )
    v24 = 1;
  return v24 == 0;
}

// File Line: 7494
// RVA: 0x3860C0
char __fastcall CombatRegionMoveToTask::SetDestinationFromRegionCenter(CombatRegionMoveToTask *this, UFG::CombatRegion *pRegion)
{
  CombatRegionMoveToTask *v2; // rbx
  float v3; // xmm0_4
  float v4; // xmm1_4
  float v5; // xmm0_4
  float *v6; // rcx
  unsigned __int16 v7; // dx
  UFG::ActiveAIEntityComponent *v8; // rax
  unsigned int v9; // edx
  bool v10; // zf
  float v11; // xmm0_4
  float v12; // xmm1_4
  char result; // al
  UFG::qVector3 out; // [rsp+30h] [rbp-28h]
  UFG::qVector3 pPos; // [rsp+40h] [rbp-18h]

  v2 = this;
  UFG::RegionComponent::GetCenter(pRegion->mpRegion, &pPos);
  if ( UFG::PlaceOnGround(&out, &pPos, 0.0, 3.0, 1.0) )
  {
    v3 = out.x;
    v4 = out.y;
    v2->m_bFoundDestination = 1;
    v2->m_vDestination.x = v3;
    v5 = out.z;
    v2->m_vDestination.y = v4;
    v2->m_vDestination.z = v5;
    v6 = (float *)v2->m_pActionContext->mSimObject.m_pPointer;
    if ( !v6 )
    {
LABEL_12:
      v11 = v2->m_vDestination.y;
      v12 = v2->m_vDestination.z;
      v6[330] = v2->m_vDestination.x;
      result = 1;
      v6[331] = v11;
      v6[332] = v12;
      return result;
    }
    v7 = *((_WORD *)v6 + 38);
    if ( (v7 >> 14) & 1 || (v7 & 0x8000u) != 0 )
    {
      v8 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>((UFG::SimObjectCVBase *)v6);
    }
    else
    {
      if ( (v7 >> 13) & 1 )
      {
        v9 = UFG::ActiveAIEntityComponent::_TypeUID;
      }
      else
      {
        v10 = ((v7 >> 12) & 1) == 0;
        v9 = UFG::ActiveAIEntityComponent::_TypeUID;
        if ( v10 )
        {
          v8 = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                 (UFG::SimObject *)v6,
                                                 UFG::ActiveAIEntityComponent::_TypeUID);
          goto LABEL_11;
        }
      }
      v8 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)v6, v9);
    }
LABEL_11:
    v6 = (float *)v8;
    goto LABEL_12;
  }
  return 0;
}

// File Line: 7525
// RVA: 0x348BC0
void __fastcall UpdateHijackableVehicleTargetTask::Begin(UpdateHijackableVehicleTargetTask *this, ActionContext *action_context)
{
  UFG::SimObjectCVBase *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::TargetingSystemPedNPCCombatantComponent *v4; // rax

  this->m_pActionContext = action_context;
  v2 = (UFG::SimObjectCVBase *)action_context->mSimObject.m_pPointer;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedNPCCombatantComponent>(v2);
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
      {
        v4 = (UFG::TargetingSystemPedNPCCombatantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               (UFG::SimObjectGame *)&v2->vfptr,
                                                               UFG::TargetingSystemPedNPCCombatantComponent::_TypeUID);
      }
      else if ( (v3 >> 12) & 1 )
      {
        v4 = (UFG::TargetingSystemPedNPCCombatantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               (UFG::SimObjectGame *)&v2->vfptr,
                                                               UFG::TargetingSystemPedNPCCombatantComponent::_TypeUID);
      }
      else
      {
        v4 = (UFG::TargetingSystemPedNPCCombatantComponent *)UFG::SimObject::GetComponentOfType(
                                                               (UFG::SimObject *)&v2->vfptr,
                                                               UFG::TargetingSystemPedNPCCombatantComponent::_TypeUID);
      }
    }
    else
    {
      v4 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedNPCCombatantComponent>(v2);
    }
    if ( v4 )
      UFG::TargetingSystemPedNPCCombatantComponent::UpdateHijackableVehicleTarget(v4);
  }
}

// File Line: 7568
// RVA: 0x330740
void __fastcall MoveToBetterAttackPositionTask::MoveToBetterAttackPositionTask(MoveToBetterAttackPositionTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax
  float v2; // xmm1_4
  float v3; // xmm2_4
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v4; // [rsp+28h] [rbp+10h]
  UFG::qSafePointer<UFG::CombatRegion,UFG::CombatRegion> *v5; // [rsp+28h] [rbp+10h]

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<MoveToBetterAttackPositionTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&MoveToBetterAttackPositionTask::`vftable;
  v4 = &this->m_pTargetSimObject;
  v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  v4->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  this->m_pTargetSimObject.m_pPointer = 0i64;
  v5 = &this->m_pCombatRegion;
  v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v5->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  this->m_pCombatRegion.m_pPointer = 0i64;
  this->m_npBestPosition.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::NavPositionBase::`vftable;
  v2 = UFG::qVector3::msZero.y;
  v3 = UFG::qVector3::msZero.z;
  this->m_npBestPosition.m_vPosition.x = UFG::qVector3::msZero.x;
  this->m_npBestPosition.m_vPosition.y = v2;
  this->m_npBestPosition.m_vPosition.z = v3;
  this->m_npBestPosition.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
  this->m_npBestPosition.m_bValid = 0;
  this->m_npBestPosition.m_hkvMeshPosition = (hkVector4f)hkvZero_13.m_quad;
  *(_QWORD *)&this->m_npBestPosition.m_packedKey = -1i64;
}

// File Line: 7575
// RVA: 0x339400
void __fastcall MoveToBetterAttackPositionTask::~MoveToBetterAttackPositionTask(MoveToBetterAttackPositionTask *this)
{
  MoveToBetterAttackPositionTask *v1; // r8
  UFG::qSafePointer<UFG::CombatRegion,UFG::CombatRegion> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<ITask,ITask> *v12; // rdx
  UFG::qNode<ITask,ITask> *v13; // rcx
  UFG::qNode<ITask,ITask> *v14; // rax

  v1 = this;
  this->vfptr = (ITaskVtbl *)&MoveToBetterAttackPositionTask::`vftable;
  v2 = &this->m_pCombatRegion;
  if ( this->m_pCombatRegion.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  }
  v2->m_pPointer = 0i64;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v7 = &v1->m_pTargetSimObject;
  if ( v1->m_pTargetSimObject.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v1->m_pTargetSimObject.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v1->m_pTargetSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->m_pTargetSimObject.mPrev;
  }
  v1->m_pTargetSimObject.m_pPointer = 0i64;
  v10 = v7->mPrev;
  v11 = v1->m_pTargetSimObject.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v1->m_pTargetSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->m_pTargetSimObject.mPrev;
  v1->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v12 = (UFG::qNode<ITask,ITask> *)&v1->mPrev;
  v13 = v1->mPrev;
  v14 = v1->mNext;
  v13->mNext = v14;
  v14->mPrev = v13;
  v12->mPrev = v12;
  v12->mNext = v12;
}

// File Line: 7582
// RVA: 0x355A20
float __fastcall MoveToBetterAttackPositionTask::EvaluatePosition(MoveToBetterAttackPositionTask *this, UFG::qVector4 *vPosition, UFG::qVector3 *vTargetPosition, float fCurrentDistToTarget)
{
  __m128 v4; // xmm0
  MoveToBetterAttackPositionTask *v5; // rsi
  UFG::qVector3 *v6; // rdi
  UFG::qVector4 *v7; // rbx
  float v8; // xmm6_4
  float v9; // xmm8_4
  UFG::SimObjectCVBase *v10; // rcx
  float v11; // xmm7_4
  unsigned __int16 v12; // dx
  UFG::TargetingSystemPedBaseComponent *v13; // rax
  UFG::SimObjectGame *v14; // rcx
  unsigned __int16 v15; // dx
  UFG::SimComponent *v16; // rax
  CAkScheduledItem *v17; // rax
  float *v18; // rdx
  float v19; // xmm2_4
  float v20; // xmm3_4
  float v21; // xmm4_4
  float v22; // xmm3_4
  float v23; // xmm2_4
  float v24; // xmm1_4
  UFG::SimObject *v25; // rbx
  UFG::qVector3 rayStart; // [rsp+20h] [rbp-128h]
  UFG::RayCastData data; // [rsp+30h] [rbp-118h]
  UFG::SimObject *ray_hit_object; // [rsp+150h] [rbp+8h]

  v4 = (__m128)LODWORD(vPosition->y);
  v5 = this;
  v6 = vTargetPosition;
  v7 = vPosition;
  v8 = 0.0;
  v9 = fCurrentDistToTarget;
  v10 = (UFG::SimObjectCVBase *)this->m_pActionContext->mSimObject.m_pPointer;
  v4.m128_f32[0] = (float)((float)(v4.m128_f32[0] - vTargetPosition->y) * (float)(v4.m128_f32[0] - vTargetPosition->y))
                 + (float)((float)(vPosition->x - vTargetPosition->x) * (float)(vPosition->x - vTargetPosition->x));
  LODWORD(v11) = (unsigned __int128)_mm_sqrt_ps(v4);
  if ( v10 )
  {
    v12 = v10->m_Flags;
    if ( (v12 >> 14) & 1 )
    {
      v13 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedBaseComponent>(v10);
    }
    else if ( (v12 & 0x8000u) == 0 )
    {
      if ( (v12 >> 13) & 1 )
        v13 = (UFG::TargetingSystemPedBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        (UFG::SimObjectGame *)&v10->vfptr,
                                                        UFG::TargetingSystemPedBaseComponent::_TypeUID);
      else
        v13 = (UFG::TargetingSystemPedBaseComponent *)((v12 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                           (UFG::SimObjectGame *)&v10->vfptr,
                                                                           UFG::TargetingSystemPedBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v10->vfptr, UFG::TargetingSystemPedBaseComponent::_TypeUID));
    }
    else
    {
      v13 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedBaseComponent>(v10);
    }
    if ( v13 )
    {
      v14 = (UFG::SimObjectGame *)v13->m_pTargets[(unsigned __int8)v13->m_pTargetingMap->m_Map.p[17]].m_pTarget.m_pPointer;
      if ( v14 )
      {
        v15 = v14->m_Flags;
        if ( (v15 >> 14) & 1 )
        {
          v16 = UFG::SimObjectGame::GetComponentOfTypeHK(v14, UFG::GunComponent::_TypeUID);
        }
        else if ( (v15 & 0x8000u) == 0 )
        {
          if ( (v15 >> 13) & 1 )
            v16 = UFG::SimObjectGame::GetComponentOfTypeHK(v14, UFG::GunComponent::_TypeUID);
          else
            v16 = (v15 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v14, UFG::GunComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v14->vfptr, UFG::GunComponent::_TypeUID);
        }
        else
        {
          v16 = UFG::SimObjectGame::GetComponentOfTypeHK(v14, UFG::GunComponent::_TypeUID);
        }
        if ( v16 )
        {
          v17 = UFG::GunComponent::GetSimObjectWeaponPropertiesComponent((CAkChainCtx *)v16);
          v18 = *(float **)(*(_QWORD *)&v17[2].m_cmdStop.iRelativeTime
                          + 8i64 * (unsigned int)v17[2].m_cmdPlay.fadeParams.iFadeOffset
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
          if ( v9 < v20 && v11 > v9 || v9 > v21 && v11 < v9 )
            v8 = v8 + 1.0;
        }
      }
    }
  }
  data.mOutput.m_hitFraction = 1.0;
  v22 = (float)(UFG::qVector3::msDirUp.x * 1.5) + v7->x;
  v23 = (float)(UFG::qVector3::msDirUp.y * 1.5) + v7->y;
  ray_hit_object = 0i64;
  data.mInput.m_enableShapeCollectionFilter.m_bool = 0;
  data.mInput.m_filterInfo = 0;
  data.mInput.m_userData = 0i64;
  data.mOutput.m_extraInfo = -1;
  data.mOutput.m_shapeKeyIndex = 0;
  v24 = (float)(UFG::qVector3::msDirUp.z * 1.5) + v7->z;
  rayStart.x = v22;
  rayStart.y = v23;
  v25 = v5->m_pTargetSimObject.m_pPointer;
  data.mOutput.m_shapeKeys[0] = -1;
  data.mOutput.m_rootCollidable = 0i64;
  rayStart.z = v24;
  data.mDebugName = 0i64;
  data.mCollisionModelName.mUID = -1;
  UFG::RayCastData::Init(&data, &rayStart, v6, 0xCu);
  UFG::BasePhysicsSystem::CastRay(UFG::BasePhysicsSystem::mInstance, &data);
  if ( UFG::TargetIsVisible(&data, v25, &ray_hit_object) )
    v8 = v8 + 1.0;
  return UFG::qRandom(0.1, &UFG::qDefaultSeed) + v8;
}

// File Line: 7653
// RVA: 0x357290
void __fastcall MoveToBetterAttackPositionTask::FindNewPosition(MoveToBetterAttackPositionTask *this, UFG::NavComponent *pNavComponent, UFG::qVector3 *vTargetPosition)
{
  signed int v3; // edi
  UFG::qVector3 *v4; // r15
  UFG::NavComponent *v5; // rsi
  MoveToBetterAttackPositionTask *v6; // rbx
  UFG::SimObject *v7; // r14
  float v8; // xmm14_4
  UFG::TransformNodeComponent *v9; // r14
  float v10; // xmm3_4
  float v11; // xmm2_4
  float v12; // xmm0_4
  __m128 v13; // xmm1
  float v14; // xmm13_4
  float v15; // xmm10_4
  float v16; // xmm0_4
  ITrack *v17; // rax
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
  unsigned int v38; // eax
  float v39; // xmm0_4
  bool v40; // al
  float v41; // xmm0_4
  hkVector4f v42; // xmm0
  unsigned int v43; // eax
  UFG::qVector4 vPosition; // [rsp+20h] [rbp-C8h]
  UFG::qVector4 v45; // [rsp+30h] [rbp-B8h]
  UFG::HavokNavPosition positionEnd; // [rsp+40h] [rbp-A8h]

  v3 = 0;
  v4 = vTargetPosition;
  v5 = pNavComponent;
  v6 = this;
  v7 = this->m_pActionContext->mSimObject.m_pPointer;
  v8 = 1.0 / (float)SHIDWORD(this->m_Track[1].mResourceOwner);
  if ( v7 )
    v9 = v7->m_pTransformNodeComponent;
  else
    v9 = 0i64;
  UFG::TransformNodeComponent::UpdateWorldTransform(v9);
  v10 = v9->mWorldTransform.v3.x;
  v11 = v9->mWorldTransform.v3.y;
  v12 = v4->x;
  vPosition.w = 1.0;
  v13 = (__m128)LODWORD(v4->y);
  vPosition.x = v10;
  vPosition.y = v11;
  v13.m128_f32[0] = (float)((float)(v13.m128_f32[0] - v11) * (float)(v13.m128_f32[0] - v11))
                  + (float)((float)(v12 - v10) * (float)(v12 - v10));
  LODWORD(v14) = (unsigned __int128)_mm_sqrt_ps(v13);
  vPosition.z = v9->mWorldTransform.v3.z;
  v15 = MoveToBetterAttackPositionTask::EvaluatePosition(v6, &vPosition, v4, v14) - 0.5;
  if ( SHIDWORD(v6->m_Track[1].mResourceOwner) > 0 )
  {
    do
    {
      v16 = UFG::qRandom(v8, &UFG::qDefaultSeed);
      v17 = v6->m_Track;
      v18 = *((float *)&v17[1].vfptr + 1);
      v19 = (float)(v16 + (float)((float)v3 * v8)) * 6.2831855;
      v20 = UFG::qRandom(*(float *)&v17[1].mResourceOwner - v18, &UFG::qDefaultSeed) + v18;
      v21 = sinf(v19) * v20;
      v22 = cosf(v19);
      v23 = v6->m_pCombatRegion.m_pPointer;
      v24 = v22 * v20;
      v25 = (float)(v22 * v20) * v9->mWorldTransform.v1.w;
      v26 = (float)(v21 * v9->mWorldTransform.v0.y) + (float)((float)(v22 * v20) * v9->mWorldTransform.v1.y);
      v27 = (float)((float)(v22 * v20) * v9->mWorldTransform.v1.x) + (float)(v21 * v9->mWorldTransform.v0.x);
      v28 = v21 * v9->mWorldTransform.v0.z;
      v29 = v21 * v9->mWorldTransform.v0.w;
      v30 = (float)(v27 + (float)(v9->mWorldTransform.v2.x * 0.0)) + v9->mWorldTransform.v3.x;
      v31 = v9->mWorldTransform.v2.z * 0.0;
      v32 = (float)(v26 + (float)(v9->mWorldTransform.v2.y * 0.0)) + v9->mWorldTransform.v3.y;
      v33 = (float)(v24 * v9->mWorldTransform.v1.z) + v28;
      v34 = v9->mWorldTransform.v2.w * 0.0;
      v45.x = v30;
      v35 = (float)(v33 + v31) + v9->mWorldTransform.v3.z;
      v45.y = v32;
      v36 = (float)((float)(v25 + v29) + v34) + v9->mWorldTransform.v3.w;
      v45.z = v35;
      v45.w = v36;
      if ( !v23
        || (vPosition.x = v30,
            vPosition.y = v32,
            vPosition.z = v35,
            UFG::CombatRegion::IsHitPoint(v23, (UFG::qVector3 *)&vPosition)) )
      {
        v37.m_quad = (__m128)v5->m_navPosition.m_hkvMeshPosition;
        v38 = v5->m_navPosition.m_packedKey;
        positionEnd.m_vPosition.x = v30;
        positionEnd.m_vPosition.y = v32;
        positionEnd.m_vPosition.z = v35;
        positionEnd.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
        positionEnd.m_aiMeshUid = -1;
        positionEnd.m_bValid = 0;
        positionEnd.m_hkvMeshPosition = (hkVector4f)v37.m_quad;
        positionEnd.m_packedKey = v38;
        UFG::HavokNavPosition::Validate(&positionEnd, 0.1, 1.0, 0.0);
        if ( positionEnd.m_bValid )
        {
          if ( UFG::HavokAIUtilGame::IsValidKey(positionEnd.m_packedKey, positionEnd.m_aiMeshUid)
            && positionEnd.m_packedKey != -1
            && positionEnd.m_aiMeshUid != -1
            && !(unsigned __int8)UFG::NavComponent::AIRayCastHits(v5, &positionEnd, 0i64) )
          {
            v39 = MoveToBetterAttackPositionTask::EvaluatePosition(v6, &v45, v4, v14);
            if ( v39 > v15 )
            {
              v40 = positionEnd.m_bValid;
              v15 = v39;
              v41 = positionEnd.m_vPosition.x;
              v6->m_npBestPosition.m_vPosition.y = positionEnd.m_vPosition.y;
              v6->m_npBestPosition.m_vPosition.x = v41;
              v6->m_npBestPosition.m_vPosition.z = positionEnd.m_vPosition.z;
              if ( v40 )
              {
                v42.m_quad = (__m128)positionEnd.m_hkvMeshPosition;
                v6->m_npBestPosition.m_bValid = v40;
                v6->m_npBestPosition.m_packedKey = positionEnd.m_packedKey;
                v43 = positionEnd.m_aiMeshUid;
                v6->m_npBestPosition.m_hkvMeshPosition = (hkVector4f)v42.m_quad;
                v6->m_npBestPosition.m_aiMeshUid = v43;
              }
              else
              {
                v6->m_npBestPosition.m_bValid = 0;
              }
              v6->m_bFoundPosition = 1;
            }
          }
        }
      }
      ++v3;
    }
    while ( v3 < SHIDWORD(v6->m_Track[1].mResourceOwner) );
  }
}

// File Line: 7709
// RVA: 0x3775E0
bool __fastcall MoveToBetterAttackPositionTask::MoveToNewPosition(MoveToBetterAttackPositionTask *this, UFG::NavComponent *pNavComponent)
{
  UFG::HavokNavPosition *v2; // rbx
  UFG::NavComponent *v3; // rdi
  bool result; // al

  v2 = &this->m_npBestPosition;
  v3 = pNavComponent;
  ((void (__fastcall *)(UFG::HavokNavPosition *))this->m_npBestPosition.vfptr->Validate)(&this->m_npBestPosition);
  result = v2->vfptr->IsMeshPositionValid((UFG::NavPositionBase *)&v2->vfptr);
  if ( result )
  {
    UFG::NavComponent::AddGoalPoint(v3, v2, 0, 2.0, 0.5);
    result = (unsigned __int8)UFG::NavComponent::IsAtDestination(v3) == 0;
  }
  return result;
}

// File Line: 7733
// RVA: 0x346FB0
void __fastcall MoveToBetterAttackPositionTask::Begin(MoveToBetterAttackPositionTask *this, ActionContext *action_context)
{
  MoveToBetterAttackPositionTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  UFG::SimComponent *v4; // rax
  unsigned __int16 v5; // dx
  UFG::CombatRegion *v6; // r8
  UFG::qSafePointer<UFG::CombatRegion,UFG::CombatRegion> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *v10; // rax

  v2 = this;
  this->m_pActionContext = action_context;
  this->m_bFoundPosition = 0;
  v3 = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  if ( v3 )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v4 = v3->m_Components.p[22].m_pComponent;
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AIEntityComponent::_TypeUID);
      }
      else if ( (v5 >> 12) & 1 )
      {
        v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::AIEntityComponent::_TypeUID);
      }
      else
      {
        v4 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::AIEntityComponent::_TypeUID);
      }
    }
    else
    {
      v4 = v3->m_Components.p[22].m_pComponent;
    }
  }
  else
  {
    v4 = 0i64;
  }
  v6 = *(UFG::CombatRegion **)&v4[15].m_TypeUID;
  v7 = &v2->m_pCombatRegion;
  if ( v2->m_pCombatRegion.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v2->m_pCombatRegion.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v2->m_pCombatRegion.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *)&v2->m_pCombatRegion.mPrev;
  }
  v2->m_pCombatRegion.m_pPointer = v6;
  if ( v6 )
  {
    v10 = v6->m_SafePointerList.mNode.mPrev;
    v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v7->mPrev = v10;
    v2->m_pCombatRegion.mNext = &v6->m_SafePointerList.mNode;
    v6->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  }
}

// File Line: 7747
// RVA: 0x390CC0
bool __fastcall MoveToBetterAttackPositionTask::Update(MoveToBetterAttackPositionTask *this, float timestep)
{
  MoveToBetterAttackPositionTask *v2; // rsi
  UFG::SimObjectGame *v3; // rcx
  UFG::SimComponent *v4; // rbx
  UFG::NavComponent *v5; // rdi
  unsigned __int16 v6; // dx
  UFG::SimComponent *v7; // rax
  UFG::SimObjectGame *v8; // rcx
  unsigned __int16 v9; // dx
  UFG::SimComponent *v10; // rax
  UFG::SimObject *v11; // rcx
  bool result; // al
  UFG::qVector3 raycastPosition; // [rsp+20h] [rbp-18h]

  v2 = this;
  v3 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
  v4 = 0i64;
  if ( v3 )
  {
    v6 = v3->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v5 = (UFG::NavComponent *)v3->m_Components.p[36].m_pComponent;
    }
    else
    {
      if ( (v6 & 0x8000u) == 0 )
      {
        if ( (v6 >> 13) & 1 )
        {
          v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::NavComponent::_TypeUID);
        }
        else if ( (v6 >> 12) & 1 )
        {
          v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::NavComponent::_TypeUID);
        }
        else
        {
          v7 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::NavComponent::_TypeUID);
        }
      }
      else
      {
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::NavComponent::_TypeUID);
      }
      v5 = (UFG::NavComponent *)v7;
    }
  }
  else
  {
    v5 = 0i64;
  }
  if ( !v2->m_bFoundPosition )
  {
    v8 = (UFG::SimObjectGame *)v2->m_pActionContext->mSimObject.m_pPointer;
    if ( v8 )
    {
      v9 = v8->m_Flags;
      if ( (v9 >> 14) & 1 )
      {
        v4 = v8->m_Components.p[20].m_pComponent;
      }
      else if ( (v9 & 0x8000u) == 0 )
      {
        if ( (v9 >> 13) & 1 )
        {
          v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        else if ( (v9 >> 12) & 1 )
        {
          v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        else
        {
          v10 = UFG::SimObject::GetComponentOfType(
                  (UFG::SimObject *)&v8->vfptr,
                  UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        v4 = v10;
      }
      else
      {
        v4 = v8->m_Components.p[20].m_pComponent;
      }
    }
    v11 = *(UFG::SimObject **)(56i64
                             * *(unsigned __int8 *)(LOBYTE(v2->m_Track[1].vfptr) + *(_QWORD *)&v4[1].m_Flags + 8i64)
                             + *(_QWORD *)&v4[1].m_TypeUID
                             + 40);
    if ( v11 )
    {
      UFG::ComputeObjectRaycastPosition(v11, &raycastPosition);
      MoveToBetterAttackPositionTask::FindNewPosition(v2, v5, &raycastPosition);
    }
  }
  if ( v2->m_bFoundPosition )
    result = MoveToBetterAttackPositionTask::MoveToNewPosition(v2, v5);
  else
    result = 0;
  return result;
}

// File Line: 7786
// RVA: 0x330870
void __fastcall MoveToFindLineOfSightTask::MoveToFindLineOfSightTask(MoveToFindLineOfSightTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax
  float v2; // xmm1_4
  float v3; // xmm2_4
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v4; // [rsp+28h] [rbp+10h]
  UFG::qSafePointer<UFG::CombatRegion,UFG::CombatRegion> *v5; // [rsp+28h] [rbp+10h]

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<MoveToFindLineOfSightTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&MoveToFindLineOfSightTask::`vftable;
  v4 = &this->m_pTargetSimObject;
  v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  v4->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  this->m_pTargetSimObject.m_pPointer = 0i64;
  v5 = &this->m_pCombatRegion;
  v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v5->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  this->m_pCombatRegion.m_pPointer = 0i64;
  this->m_npBestPosition.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::NavPositionBase::`vftable;
  v2 = UFG::qVector3::msZero.y;
  v3 = UFG::qVector3::msZero.z;
  this->m_npBestPosition.m_vPosition.x = UFG::qVector3::msZero.x;
  this->m_npBestPosition.m_vPosition.y = v2;
  this->m_npBestPosition.m_vPosition.z = v3;
  this->m_npBestPosition.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
  this->m_npBestPosition.m_bValid = 0;
  this->m_npBestPosition.m_hkvMeshPosition = (hkVector4f)hkvZero_13.m_quad;
  *(_QWORD *)&this->m_npBestPosition.m_packedKey = -1i64;
}

// File Line: 7793
// RVA: 0x3394D0
void __fastcall MoveToFindLineOfSightTask::~MoveToFindLineOfSightTask(MoveToFindLineOfSightTask *this)
{
  MoveToFindLineOfSightTask *v1; // r8
  UFG::qSafePointer<UFG::CombatRegion,UFG::CombatRegion> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<ITask,ITask> *v12; // rdx
  UFG::qNode<ITask,ITask> *v13; // rcx
  UFG::qNode<ITask,ITask> *v14; // rax

  v1 = this;
  this->vfptr = (ITaskVtbl *)&MoveToFindLineOfSightTask::`vftable;
  v2 = &this->m_pCombatRegion;
  if ( this->m_pCombatRegion.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  }
  v2->m_pPointer = 0i64;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v7 = &v1->m_pTargetSimObject;
  if ( v1->m_pTargetSimObject.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v1->m_pTargetSimObject.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v1->m_pTargetSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->m_pTargetSimObject.mPrev;
  }
  v1->m_pTargetSimObject.m_pPointer = 0i64;
  v10 = v7->mPrev;
  v11 = v1->m_pTargetSimObject.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v1->m_pTargetSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->m_pTargetSimObject.mPrev;
  v1->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v12 = (UFG::qNode<ITask,ITask> *)&v1->mPrev;
  v13 = v1->mPrev;
  v14 = v1->mNext;
  v13->mNext = v14;
  v14->mPrev = v13;
  v12->mPrev = v12;
  v12->mNext = v12;
}

// File Line: 7800
// RVA: 0x377670
bool __fastcall MoveToFindLineOfSightTask::MoveToNewPosition(MoveToFindLineOfSightTask *this, UFG::NavComponent *pNavComponent)
{
  MoveToFindLineOfSightTask *v2; // rdi
  UFG::NavComponent *v3; // rsi
  bool result; // al

  v2 = this;
  v3 = pNavComponent;
  ((void (__fastcall *)(UFG::HavokNavPosition *))this->m_npBestPosition.vfptr->Validate)(&this->m_npBestPosition);
  result = v2->m_npBestPosition.vfptr->IsMeshPositionValid((UFG::NavPositionBase *)&v2->m_npBestPosition.vfptr);
  if ( result )
  {
    UFG::NavComponent::AddGoalPoint(
      v3,
      &v2->m_npBestPosition,
      0,
      sNaturalMovementSpeeds[BYTE1(v2->m_Track[1].vfptr)],
      0.5);
    result = (unsigned __int8)UFG::NavComponent::IsAtDestination(v3) == 0;
  }
  return result;
}

// File Line: 7821
// RVA: 0x3510F0
void __fastcall MoveToFindLineOfSightTask::CreateRangedLOSQuery(MoveToFindLineOfSightTask *this)
{
  MoveToFindLineOfSightTask *v1; // rbx
  UFG::AIRangedLineOfSightQuery *v2; // rcx
  UFG::TransformNodeComponent *v3; // rsi
  UFG::AIRangedLineOfSightQuery *v4; // rcx
  bool v5; // zf
  UFG::SimObjectGame *v6; // rcx
  UFG::SimComponent *v7; // rax
  unsigned __int16 v8; // dx
  UFG::CombatRegion *v9; // r8
  UFG::qSafePointer<UFG::CombatRegion,UFG::CombatRegion> *v10; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::SimObjectGame *v14; // rcx
  UFG::SimComponent *v15; // r8
  unsigned __int16 v16; // dx
  UFG::SimComponent *v17; // rax
  UFG::SimObject *v18; // r8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v19; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v20; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v21; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v22; // rax
  UFG::allocator::free_link *v23; // rax
  UFG::AIRangedLineOfSightQuery *v24; // rax
  signed __int64 v25; // rdi
  UFG::SimObject *v26; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v27; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v28; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v29; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v30; // rdx
  UFG::SimObject *v31; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v32; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v33; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v34; // rax
  UFG::SimObject *v35; // rax
  float v36; // xmm0_4
  float v37; // xmm1_4
  UFG::allocator::free_link *outMinimumDesired; // [rsp+50h] [rbp+8h]
  float outMaximumDesired; // [rsp+58h] [rbp+10h]
  float outDesired; // [rsp+60h] [rbp+18h]

  v1 = this;
  v2 = this->m_pLOSQuery;
  v3 = 0i64;
  if ( v2 )
  {
    if ( !((unsigned __int8 (__cdecl *)(UFG::AIRangedLineOfSightQuery *))v2->vfptr->IsCompleted)(v2) )
      UFG::AIQueryManager::CancelQuery(UFG::AIQueryManager::ms_pInstance, (UFG::AIQuery *)&v1->m_pLOSQuery->vfptr);
    v4 = v1->m_pLOSQuery;
    v5 = v4->m_iRefCount-- == 1;
    if ( v5 )
      v4->vfptr->__vecDelDtor((UFG::AIQuery *)&v4->vfptr, 1u);
    v1->m_pLOSQuery = 0i64;
  }
  v1->m_pLOSQuery = 0i64;
  v6 = (UFG::SimObjectGame *)v1->m_pActionContext->mSimObject.m_pPointer;
  if ( v6 )
  {
    v8 = v6->m_Flags;
    if ( (v8 >> 14) & 1 )
    {
      v7 = v6->m_Components.p[22].m_pComponent;
    }
    else if ( (v8 & 0x8000u) == 0 )
    {
      if ( (v8 >> 13) & 1 )
      {
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::AIEntityComponent::_TypeUID);
      }
      else if ( (v8 >> 12) & 1 )
      {
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::AIEntityComponent::_TypeUID);
      }
      else
      {
        v7 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v6->vfptr, UFG::AIEntityComponent::_TypeUID);
      }
    }
    else
    {
      v7 = v6->m_Components.p[22].m_pComponent;
    }
  }
  else
  {
    v7 = 0i64;
  }
  v9 = *(UFG::CombatRegion **)&v7[15].m_TypeUID;
  v10 = &v1->m_pCombatRegion;
  if ( v1->m_pCombatRegion.m_pPointer )
  {
    v11 = v10->mPrev;
    v12 = v1->m_pCombatRegion.mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    v10->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *)&v10->mPrev;
    v1->m_pCombatRegion.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *)&v1->m_pCombatRegion.mPrev;
  }
  v1->m_pCombatRegion.m_pPointer = v9;
  if ( v9 )
  {
    v13 = v9->m_SafePointerList.mNode.mPrev;
    v13->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *)&v10->mPrev;
    v10->mPrev = v13;
    v1->m_pCombatRegion.mNext = &v9->m_SafePointerList.mNode;
    v9->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::CombatRegion>,UFG::qSafePointerNodeList> *)&v10->mPrev;
  }
  v14 = (UFG::SimObjectGame *)v1->m_pActionContext->mSimObject.m_pPointer;
  if ( v14 )
  {
    v16 = v14->m_Flags;
    if ( (v16 >> 14) & 1 )
    {
      v15 = v14->m_Components.p[20].m_pComponent;
    }
    else if ( (v16 & 0x8000u) == 0 )
    {
      if ( (v16 >> 13) & 1 )
      {
        v17 = UFG::SimObjectGame::GetComponentOfTypeHK(v14, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else if ( (v16 >> 12) & 1 )
      {
        v17 = UFG::SimObjectGame::GetComponentOfTypeHK(v14, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else
      {
        v17 = UFG::SimObject::GetComponentOfType(
                (UFG::SimObject *)&v14->vfptr,
                UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      v15 = v17;
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
                           * *(unsigned __int8 *)(*(_QWORD *)&v15[1].m_Flags + LOBYTE(v1->m_Track[1].vfptr) + 8i64)
                           + *(_QWORD *)&v15[1].m_TypeUID
                           + 40);
  v19 = &v1->m_pTargetSimObject;
  if ( v1->m_pTargetSimObject.m_pPointer )
  {
    v20 = v19->mPrev;
    v21 = v1->m_pTargetSimObject.mNext;
    v20->mNext = v21;
    v21->mPrev = v20;
    v19->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v19->mPrev;
    v1->m_pTargetSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->m_pTargetSimObject.mPrev;
  }
  v1->m_pTargetSimObject.m_pPointer = v18;
  if ( v18 )
  {
    v22 = v18->m_SafePointerList.mNode.mPrev;
    v22->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v19->mPrev;
    v19->mPrev = v22;
    v1->m_pTargetSimObject.mNext = &v18->m_SafePointerList.mNode;
    v18->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v19->mPrev;
  }
  if ( v1->m_pTargetSimObject.m_pPointer )
  {
    v23 = UFG::qMalloc(0x12C0ui64, UFG::gGlobalNewName, 0i64);
    outMinimumDesired = v23;
    if ( v23 )
      UFG::AIRangedLineOfSightQuery::AIRangedLineOfSightQuery((UFG::AIRangedLineOfSightQuery *)v23);
    else
      v24 = 0i64;
    v1->m_pLOSQuery = v24;
    ++v24->m_iRefCount;
    v25 = (signed __int64)&v1->m_pLOSQuery->m_queryParams;
    v26 = v1->m_pActionContext->mSimObject.m_pPointer;
    if ( v1->m_pLOSQuery->m_queryParams.pOwnerSimObject.m_pPointer )
    {
      v27 = *(UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> **)v25;
      v28 = v1->m_pLOSQuery->m_queryParams.pOwnerSimObject.mNext;
      v27->mNext = v28;
      v28->mPrev = v27;
      *(_QWORD *)v25 = v25;
      *(_QWORD *)(v25 + 8) = v25;
    }
    *(_QWORD *)(v25 + 16) = v26;
    if ( v26 )
    {
      v29 = v26->m_SafePointerList.mNode.mPrev;
      v29->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)v25;
      *(_QWORD *)v25 = v29;
      *(_QWORD *)(v25 + 8) = (char *)v26 + 8;
      v26->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)v25;
    }
    v30 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)(v25 + 24);
    v31 = v1->m_pTargetSimObject.m_pPointer;
    if ( *(_QWORD *)(v25 + 40) )
    {
      v32 = v30->mPrev;
      v33 = *(UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> **)(v25 + 32);
      v32->mNext = v33;
      v33->mPrev = v32;
      v30->mPrev = v30;
      *(_QWORD *)(v25 + 32) = v25 + 24;
    }
    *(_QWORD *)(v25 + 40) = v31;
    if ( v31 )
    {
      v34 = v31->m_SafePointerList.mNode.mPrev;
      v34->mNext = v30;
      v30->mPrev = v34;
      *(_QWORD *)(v25 + 32) = (char *)v31 + 8;
      v31->m_SafePointerList.mNode.mPrev = v30;
    }
    *(_DWORD *)(v25 + 48) = 1065353216;
    *(_DWORD *)(v25 + 52) = 1101004800;
    *(_DWORD *)(v25 + 56) = 1061158912;
    UFG::GetDesiredRanges(
      v1->m_pActionContext->mSimObject.m_pPointer,
      (float *)&outMinimumDesired,
      &outMaximumDesired,
      &outDesired);
    *(_DWORD *)(v25 + 60) = (_DWORD)outMinimumDesired;
    *(float *)(v25 + 64) = outMaximumDesired;
    UFG::AIQueryManager::SubmitQuery(UFG::AIQueryManager::ms_pInstance, (UFG::AIQuery *)&v1->m_pLOSQuery->vfptr);
    v35 = v1->m_pTargetSimObject.m_pPointer;
    if ( v35 )
      v3 = v35->m_pTransformNodeComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform(v3);
    v36 = v3->mWorldTransform.v3.y;
    v37 = v3->mWorldTransform.v3.z;
    v1->m_vLastTestPosition.x = v3->mWorldTransform.v3.x;
    v1->m_vLastTestPosition.y = v36;
    v1->m_vLastTestPosition.z = v37;
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
  UFG::SimObject *v2; // rax
  UFG::NavComponent *v3; // rdi
  MoveToFindLineOfSightTask *v4; // rbx
  UFG::SimObjectGame *v5; // rcx
  UFG::SimComponent *v6; // r8
  unsigned __int16 v7; // dx
  UFG::SimComponent *v8; // rax
  UFG::SimObject *v9; // r8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v10; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::TransformNodeComponent *v14; // rsi
  UFG::AIRangedLineOfSightQuery *v15; // rcx
  UFG::AIRangedLineOfSightQuery *v16; // rdx
  float v17; // xmm0_4
  float v18; // xmm1_4
  bool v19; // zf
  UFG::SimObjectGame *v20; // rcx
  unsigned __int16 v21; // dx
  unsigned int v22; // edx
  UFG::NavComponent *v23; // rax

  v2 = this->m_pTargetSimObject.m_pPointer;
  v3 = 0i64;
  v4 = this;
  if ( v2 )
    goto LABEL_47;
  v5 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
  if ( v5 )
  {
    v7 = v5->m_Flags;
    if ( (v7 >> 14) & 1 )
    {
      v6 = v5->m_Components.p[20].m_pComponent;
    }
    else if ( (v7 & 0x8000u) == 0 )
    {
      if ( (v7 >> 13) & 1 )
      {
        v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else if ( (v7 >> 12) & 1 )
      {
        v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else
      {
        v8 = UFG::SimObject::GetComponentOfType(
               (UFG::SimObject *)&v5->vfptr,
               UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      v6 = v8;
    }
    else
    {
      v6 = v5->m_Components.p[20].m_pComponent;
    }
  }
  else
  {
    v6 = 0i64;
  }
  v9 = *(UFG::SimObject **)(56i64
                          * *(unsigned __int8 *)(LOBYTE(v4->m_Track[1].vfptr) + *(_QWORD *)&v6[1].m_Flags + 8i64)
                          + *(_QWORD *)&v6[1].m_TypeUID
                          + 40);
  v10 = &v4->m_pTargetSimObject;
  if ( v4->m_pTargetSimObject.m_pPointer )
  {
    v11 = v10->mPrev;
    v12 = v4->m_pTargetSimObject.mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    v10->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v10->mPrev;
    v4->m_pTargetSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v4->m_pTargetSimObject.mPrev;
  }
  v4->m_pTargetSimObject.m_pPointer = v9;
  if ( v9 )
  {
    v13 = v9->m_SafePointerList.mNode.mPrev;
    v13->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v10->mPrev;
    v10->mPrev = v13;
    v4->m_pTargetSimObject.mNext = &v9->m_SafePointerList.mNode;
    v9->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v10->mPrev;
  }
  v2 = v4->m_pTargetSimObject.m_pPointer;
  if ( v2 )
  {
LABEL_47:
    v14 = 0i64;
    if ( v2 )
      v14 = v2->m_pTransformNodeComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform(v14);
    if ( (float)((float)((float)((float)(v14->mWorldTransform.v3.y - v4->m_vLastTestPosition.y)
                               * (float)(v14->mWorldTransform.v3.y - v4->m_vLastTestPosition.y))
                       + (float)((float)(v14->mWorldTransform.v3.x - v4->m_vLastTestPosition.x)
                               * (float)(v14->mWorldTransform.v3.x - v4->m_vLastTestPosition.x)))
               + (float)((float)(v14->mWorldTransform.v3.z - v4->m_vLastTestPosition.z)
                       * (float)(v14->mWorldTransform.v3.z - v4->m_vLastTestPosition.z))) > 100.0
      || !v4->m_pLOSQuery && !v4->m_bFoundPosition )
    {
      MoveToFindLineOfSightTask::CreateRangedLOSQuery(v4);
    }
    v15 = v4->m_pLOSQuery;
    if ( v15 && ((unsigned __int8 (*)(void))v15->vfptr->IsCompleted)() )
    {
      v16 = v4->m_pLOSQuery;
      if ( v16->m_iBestPositionIndex >= 0 )
      {
        v17 = v16->m_aRangedPositions.p[v16->m_iBestPositionIndex].vGroundPosition.y;
        v18 = v16->m_aRangedPositions.p[v16->m_iBestPositionIndex].vGroundPosition.z;
        v4->m_npBestPosition.m_vPosition.x = v16->m_aRangedPositions.p[v16->m_iBestPositionIndex].vGroundPosition.x;
        v4->m_npBestPosition.m_vPosition.y = v17;
        v4->m_npBestPosition.m_vPosition.z = v18;
        v4->m_npBestPosition.m_bValid = 0;
        v4->m_bFoundPosition = 1;
      }
      v19 = v16->m_iRefCount-- == 1;
      if ( v19 )
        v16->vfptr->__vecDelDtor((UFG::AIQuery *)&v16->vfptr, 1u);
      v4->m_pLOSQuery = 0i64;
    }
    if ( !v4->m_bFoundPosition )
    {
      LOBYTE(v2) = 1;
      return (char)v2;
    }
    v20 = (UFG::SimObjectGame *)v4->m_pActionContext->mSimObject.m_pPointer;
    if ( !v20 )
      goto LABEL_42;
    v21 = v20->m_Flags;
    if ( (v21 >> 14) & 1 )
    {
      LOBYTE(v2) = MoveToFindLineOfSightTask::MoveToNewPosition(
                     v4,
                     (UFG::NavComponent *)v20->m_Components.p[36].m_pComponent);
      return (char)v2;
    }
    if ( (v21 & 0x8000u) != 0 || (v21 >> 13) & 1 )
    {
      v22 = UFG::NavComponent::_TypeUID;
    }
    else
    {
      v19 = ((v21 >> 12) & 1) == 0;
      v22 = UFG::NavComponent::_TypeUID;
      if ( v19 )
      {
        v3 = (UFG::NavComponent *)UFG::SimObject::GetComponentOfType(
                                    (UFG::SimObject *)&v20->vfptr,
                                    UFG::NavComponent::_TypeUID);
LABEL_42:
        LOBYTE(v2) = MoveToFindLineOfSightTask::MoveToNewPosition(v4, v3);
        return (char)v2;
      }
    }
    v23 = (UFG::NavComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v20, v22);
    LOBYTE(v2) = MoveToFindLineOfSightTask::MoveToNewPosition(v4, v23);
  }
  return (char)v2;
}

// File Line: 7960
// RVA: 0x355340
void __fastcall MoveToFindLineOfSightTask::End(MoveToFindLineOfSightTask *this)
{
  MoveToFindLineOfSightTask *v1; // rbx
  UFG::AIRangedLineOfSightQuery *v2; // rcx
  UFG::AIRangedLineOfSightQuery *v3; // rcx
  bool v4; // zf

  v1 = this;
  v2 = this->m_pLOSQuery;
  if ( v2 )
  {
    if ( !((unsigned __int8 (*)(void))v2->vfptr->IsCompleted)() )
      UFG::AIQueryManager::CancelQuery(UFG::AIQueryManager::ms_pInstance, (UFG::AIQuery *)&v1->m_pLOSQuery->vfptr);
    v3 = v1->m_pLOSQuery;
    v4 = v3->m_iRefCount-- == 1;
    if ( v4 )
      v3->vfptr->__vecDelDtor((UFG::AIQuery *)&v3->vfptr, 1u);
    v1->m_pLOSQuery = 0i64;
  }
}

// File Line: 7982
// RVA: 0x332990
void __fastcall WaitUntilAbleToPathToTargetTask::WaitUntilAbleToPathToTargetTask(WaitUntilAbleToPathToTargetTask *this)
{
  WaitUntilAbleToPathToTargetTask *v1; // rbx
  UFG::qNode<ITask,ITask> *v2; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v3; // [rsp+48h] [rbp+10h]
  signed __int64 v4; // [rsp+48h] [rbp+10h]

  v1 = this;
  v2 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<WaitUntilAbleToPathToTargetTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&WaitUntilAbleToPathToTargetTask::`vftable;
  v3 = &this->m_pTargetSimObject;
  v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  this->m_pTargetSimObject.m_pPointer = 0i64;
  UFG::FindPathDeferredQuery::FindPathDeferredQuery(&this->m_PathQueryInput);
  v4 = (signed __int64)&v1->m_PathQueryOutput;
  *(_OWORD *)v4 = (unsigned __int64)&UFG::DaemonQueryOutput::`vftable;
  *(_DWORD *)(v4 + 16) = 0;
  *(_QWORD *)v4 = &UFG::FindPathOutput::`vftable;
  v1->m_PathQueryOutput.m_pPath.m_pNavPath = 0i64;
  v1->m_NavParams.m_fRadius = 0.0;
  v1->m_NavParams.m_flags = 65280;
  v1->m_PendingQuery = 0;
}

// File Line: 7989
// RVA: 0x33B8A0
void __fastcall WaitUntilAbleToPathToTargetTask::~WaitUntilAbleToPathToTargetTask(WaitUntilAbleToPathToTargetTask *this)
{
  WaitUntilAbleToPathToTargetTask *v1; // rbx
  UFG::FindPathOutput *v2; // rdi
  UFG::NavPath *v3; // rcx
  bool v4; // zf
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v5; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<ITask,ITask> *v10; // rdx
  UFG::qNode<ITask,ITask> *v11; // rcx
  UFG::qNode<ITask,ITask> *v12; // rax

  v1 = this;
  this->vfptr = (ITaskVtbl *)&WaitUntilAbleToPathToTargetTask::`vftable;
  v2 = &this->m_PathQueryOutput;
  v3 = this->m_PathQueryOutput.m_pPath.m_pNavPath;
  if ( v3 )
  {
    v4 = v3->m_uRefCount-- == 1;
    if ( v4 )
      v3->vfptr->__vecDelDtor(v3, 1u);
  }
  v2->vfptr = (UFG::DaemonQueryOutputVtbl *)&UFG::DaemonQueryOutput::`vftable;
  v1->m_PathQueryInput.vfptr = (UFG::DaemonQueryInputVtbl *)&UFG::DaemonQueryInput::`vftable;
  v5 = &v1->m_pTargetSimObject;
  if ( v1->m_pTargetSimObject.m_pPointer )
  {
    v6 = v5->mPrev;
    v7 = v1->m_pTargetSimObject.mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mPrev;
    v1->m_pTargetSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->m_pTargetSimObject.mPrev;
  }
  v1->m_pTargetSimObject.m_pPointer = 0i64;
  v8 = v5->mPrev;
  v9 = v1->m_pTargetSimObject.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v1->m_pTargetSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->m_pTargetSimObject.mPrev;
  v1->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v10 = (UFG::qNode<ITask,ITask> *)&v1->mPrev;
  v11 = v1->mPrev;
  v12 = v1->mNext;
  v11->mNext = v12;
  v12->mPrev = v11;
  v10->mPrev = v10;
  v10->mNext = v10;
}

// File Line: 7994
// RVA: 0x348E80
void __fastcall WaitUntilAbleToPathToTargetTask::Begin(WaitUntilAbleToPathToTargetTask *this, ActionContext *action_context)
{
  WaitUntilAbleToPathToTargetTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  UFG::SimComponent *v4; // rdi
  UFG::SimComponent *v5; // r8
  unsigned __int16 v6; // dx
  UFG::SimComponent *v7; // rax
  UFG::SimObject *v8; // r8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v9; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::SimObjectGame *v13; // rcx
  unsigned __int16 v14; // dx
  UFG::SimComponent *v15; // rax
  unsigned int v16; // eax

  v2 = this;
  this->m_pActionContext = action_context;
  v3 = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  v4 = 0i64;
  if ( v3 )
  {
    v6 = v3->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v5 = v3->m_Components.p[20].m_pComponent;
    }
    else if ( (v6 & 0x8000u) == 0 )
    {
      if ( (v6 >> 13) & 1 )
      {
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else if ( (v6 >> 12) & 1 )
      {
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else
      {
        v7 = UFG::SimObject::GetComponentOfType(
               (UFG::SimObject *)&v3->vfptr,
               UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      v5 = v7;
    }
    else
    {
      v5 = v3->m_Components.p[20].m_pComponent;
    }
  }
  else
  {
    v5 = 0i64;
  }
  v8 = *(UFG::SimObject **)(56i64
                          * *(unsigned __int8 *)(LOBYTE(v2->m_Track[1].vfptr) + *(_QWORD *)&v5[1].m_Flags + 8i64)
                          + *(_QWORD *)&v5[1].m_TypeUID
                          + 40);
  v9 = &v2->m_pTargetSimObject;
  if ( v2->m_pTargetSimObject.m_pPointer )
  {
    v10 = v9->mPrev;
    v11 = v2->m_pTargetSimObject.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    v9->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v9->mPrev;
    v2->m_pTargetSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->m_pTargetSimObject.mPrev;
  }
  v2->m_pTargetSimObject.m_pPointer = v8;
  if ( v8 )
  {
    v12 = v8->m_SafePointerList.mNode.mPrev;
    v12->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v9->mPrev;
    v9->mPrev = v12;
    v2->m_pTargetSimObject.mNext = &v8->m_SafePointerList.mNode;
    v8->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v9->mPrev;
  }
  v13 = (UFG::SimObjectGame *)v2->m_pActionContext->mSimObject.m_pPointer;
  if ( v13 )
  {
    v14 = v13->m_Flags;
    if ( (v14 >> 14) & 1 )
    {
      v4 = v13->m_Components.p[36].m_pComponent;
    }
    else
    {
      if ( (v14 & 0x8000u) == 0 )
      {
        if ( (v14 >> 13) & 1 )
        {
          v15 = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::NavComponent::_TypeUID);
        }
        else if ( (v14 >> 12) & 1 )
        {
          v15 = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::NavComponent::_TypeUID);
        }
        else
        {
          v15 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v13->vfptr, UFG::NavComponent::_TypeUID);
        }
      }
      else
      {
        v15 = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::NavComponent::_TypeUID);
      }
      v4 = v15;
    }
  }
  v2->m_NavParams = *(UFG::NavParams *)((char *)&v4[2].m_BoundComponentHandles.mNode.mNext + 4);
  if ( BYTE1(v2->m_Track[1].vfptr) )
  {
    v16 = v2->m_NavParams.m_flags;
    LOBYTE(v2->m_NavParams.m_flags) = 0;
    v2->m_NavParams.m_flags |= (unsigned __int8)(v16 & 0xFE);
  }
}

// File Line: 8017
// RVA: 0x393B70
char __fastcall WaitUntilAbleToPathToTargetTask::Update(WaitUntilAbleToPathToTargetTask *this, float timestep)
{
  WaitUntilAbleToPathToTargetTask *v2; // rsi
  hkVector4f *v4; // rbx
  UFG::SimObjectGame *v5; // rcx
  hkVector4f *v6; // rdi
  unsigned __int16 v7; // dx
  UFG::SimComponent *v8; // rax
  UFG::SimObjectGame *v9; // rcx
  unsigned __int16 v10; // dx
  UFG::SimComponent *v11; // rax
  UFG::NavPath *v12; // rax
  float v13; // xmm0_4
  float v14; // xmm1_4
  char v15; // al
  float v16; // xmm0_4
  float v17; // xmm1_4
  char v18; // al
  UFG::DaemonManager *v19; // rax

  v2 = this;
  if ( !this->m_pTargetSimObject.m_pPointer )
    return 0;
  v4 = 0i64;
  v5 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
  if ( v5 )
  {
    v7 = v5->m_Flags;
    if ( (v7 >> 14) & 1 )
    {
      v6 = (hkVector4f *)v5->m_Components.p[36].m_pComponent;
    }
    else
    {
      if ( (v7 & 0x8000u) == 0 )
      {
        if ( (v7 >> 13) & 1 )
        {
          v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::NavComponent::_TypeUID);
        }
        else if ( (v7 >> 12) & 1 )
        {
          v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::NavComponent::_TypeUID);
        }
        else
        {
          v8 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v5->vfptr, UFG::NavComponent::_TypeUID);
        }
      }
      else
      {
        v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::NavComponent::_TypeUID);
      }
      v6 = (hkVector4f *)v8;
    }
  }
  else
  {
    v6 = 0i64;
  }
  v9 = (UFG::SimObjectGame *)v2->m_pTargetSimObject.m_pPointer;
  if ( v9 )
  {
    v10 = v9->m_Flags;
    if ( (v10 >> 14) & 1 )
    {
      v4 = (hkVector4f *)v9->m_Components.p[36].m_pComponent;
    }
    else
    {
      if ( (v10 & 0x8000u) == 0 )
      {
        if ( (v10 >> 13) & 1 )
        {
          v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::NavComponent::_TypeUID);
        }
        else if ( (v10 >> 12) & 1 )
        {
          v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::NavComponent::_TypeUID);
        }
        else
        {
          v11 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v9->vfptr, UFG::NavComponent::_TypeUID);
        }
      }
      else
      {
        v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::NavComponent::_TypeUID);
      }
      v4 = (hkVector4f *)v11;
    }
  }
  if ( v2->m_PendingQuery )
  {
    if ( v2->m_PathQueryOutput.m_status == 3 )
    {
      v12 = v2->m_PathQueryOutput.m_pPath.m_pNavPath;
      v2->m_PendingQuery = 0;
      if ( v12->m_aWaypoints.size )
        return 0;
    }
    else if ( v2->m_PathQueryOutput.m_status == 4 )
    {
      v2->m_PendingQuery = 0;
      return 1;
    }
  }
  else
  {
    v13 = v6[5].m_quad.m128_f32[3];
    v14 = v6[6].m_quad.m128_f32[0];
    v2->m_PathQueryInput.m_npFrom.m_vPosition.x = v6[5].m_quad.m128_f32[2];
    v2->m_PathQueryInput.m_npFrom.m_vPosition.y = v13;
    v2->m_PathQueryInput.m_npFrom.m_vPosition.z = v14;
    v15 = v6[6].m_quad.m128_i8[8];
    if ( v15 )
    {
      v2->m_PathQueryInput.m_npFrom.m_bValid = v15;
      v2->m_PathQueryInput.m_npFrom.m_hkvMeshPosition = (hkVector4f)v6[7].m_quad;
      v2->m_PathQueryInput.m_npFrom.m_packedKey = v6[8].m_quad.m128_u32[0];
      v2->m_PathQueryInput.m_npFrom.m_aiMeshUid = v6[8].m_quad.m128_u32[1];
    }
    else
    {
      v2->m_PathQueryInput.m_npFrom.m_bValid = 0;
    }
    v16 = v4[5].m_quad.m128_f32[3];
    v17 = v4[6].m_quad.m128_f32[0];
    v2->m_PathQueryInput.m_npTo.m_vPosition.x = v4[5].m_quad.m128_f32[2];
    v2->m_PathQueryInput.m_npTo.m_vPosition.y = v16;
    v2->m_PathQueryInput.m_npTo.m_vPosition.z = v17;
    v18 = v4[6].m_quad.m128_i8[8];
    if ( v18 )
    {
      v2->m_PathQueryInput.m_npTo.m_bValid = v18;
      v2->m_PathQueryInput.m_npTo.m_hkvMeshPosition = (hkVector4f)v4[7].m_quad;
      v2->m_PathQueryInput.m_npTo.m_packedKey = v4[8].m_quad.m128_u32[0];
      v2->m_PathQueryInput.m_npTo.m_aiMeshUid = v4[8].m_quad.m128_u32[1];
    }
    else
    {
      v2->m_PathQueryInput.m_npTo.m_bValid = 0;
    }
    if ( v2->m_PathQueryInput.m_npFrom.m_bValid
      && UFG::HavokAIUtilGame::IsValidKey(
           v2->m_PathQueryInput.m_npFrom.m_packedKey,
           v2->m_PathQueryInput.m_npFrom.m_aiMeshUid)
      && v2->m_PathQueryInput.m_npTo.m_bValid
      && UFG::HavokAIUtilGame::IsValidKey(
           v2->m_PathQueryInput.m_npTo.m_packedKey,
           v2->m_PathQueryInput.m_npTo.m_aiMeshUid) )
    {
      v2->m_PathQueryInput.m_pNavParams = &v2->m_NavParams;
      v19 = UFG::DaemonManager::Instance();
      UFG::DaemonManager::SubmitQuery(
        v19,
        (UFG::DaemonQueryInput *)&v2->m_PathQueryInput.vfptr,
        (UFG::DaemonQueryOutput *)&v2->m_PathQueryOutput.vfptr);
      v2->m_PendingQuery = 1;
    }
  }
  return 1;
}

// File Line: 8080
// RVA: 0x355650
void __fastcall WaitUntilAbleToPathToTargetTask::End(WaitUntilAbleToPathToTargetTask *this)
{
  WaitUntilAbleToPathToTargetTask *v1; // rdi
  UFG::DaemonManager *v2; // rax

  v1 = this;
  if ( this->m_PendingQuery )
  {
    v2 = UFG::DaemonManager::Instance();
    UFG::DaemonManager::CancelQuery(v2, (UFG::DaemonQueryInput *)&v1->m_PathQueryInput.vfptr);
    v1->m_PendingQuery = 0;
  }
}

// File Line: 8096
// RVA: 0x32FCF0
void __fastcall InteractingWithVehicleHeuristicTask::InteractingWithVehicleHeuristicTask(InteractingWithVehicleHeuristicTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<InteractingWithVehicleHeuristicTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&InteractingWithVehicleHeuristicTask::`vftable;
}

// File Line: 8104
// RVA: 0x3464C0
void __fastcall InteractingWithVehicleHeuristicTask::Begin(InteractingWithVehicleHeuristicTask *this, ActionContext *action_context)
{
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rax

  this->m_pActionContext = action_context;
  v2 = (UFG::SimObjectGame *)action_context->mSimObject.m_pPointer;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = v2->m_Components.p[5].m_pComponent;
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
      {
        v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::AIScriptInterfaceComponent::_TypeUID);
      }
      else if ( (v3 >> 12) & 1 )
      {
        v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::AIScriptInterfaceComponent::_TypeUID);
      }
      else
      {
        v4 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::AIScriptInterfaceComponent::_TypeUID);
      }
    }
    else
    {
      v4 = v2->m_Components.p[5].m_pComponent;
    }
    if ( v4 )
      BYTE2(v4[32].m_BoundComponentHandles.mNode.mPrev) |= 1u;
  }
}

// File Line: 8123
// RVA: 0x3550E0
void __fastcall InteractingWithVehicleHeuristicTask::End(InteractingWithVehicleHeuristicTask *this)
{
  UFG::SimObjectGame *v1; // rcx
  unsigned __int16 v2; // dx
  UFG::SimComponent *v3; // rax

  v1 = (UFG::SimObjectGame *)this->m_pActionContext->mSimObject.m_pPointer;
  if ( v1 )
  {
    v2 = v1->m_Flags;
    if ( (v2 >> 14) & 1 )
    {
      v3 = v1->m_Components.p[5].m_pComponent;
    }
    else if ( (v2 & 0x8000u) == 0 )
    {
      if ( (v2 >> 13) & 1 )
      {
        v3 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::AIScriptInterfaceComponent::_TypeUID);
      }
      else if ( (v2 >> 12) & 1 )
      {
        v3 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::AIScriptInterfaceComponent::_TypeUID);
      }
      else
      {
        v3 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v1->vfptr, UFG::AIScriptInterfaceComponent::_TypeUID);
      }
    }
    else
    {
      v3 = v1->m_Components.p[5].m_pComponent;
    }
    if ( v3 )
      BYTE2(v3[32].m_BoundComponentHandles.mNode.mPrev) &= 0xFEu;
  }
}

// File Line: 8138
// RVA: 0x330080
void __fastcall InvokeBehaviourTask::InvokeBehaviourTask(InvokeBehaviourTask *this)
{
  InvokeBehaviourTask *v1; // rbx
  UFG::qSafePointer<UFG::Behaviour,UFG::Behaviour> *v2; // [rsp+48h] [rbp+10h]
  UFG::qSafePointer<UFG::Behaviour,UFG::Behaviour> *v3; // [rsp+48h] [rbp+10h]
  UFG::qSafePointer<UFG::SimComponent,UFG::BehaviourControllerComponent> *v4; // [rsp+48h] [rbp+10h]

  v1 = this;
  SpawnTask::SpawnTask((SpawnTask *)&this->vfptr);
  v1->vfptr = (ITaskVtbl *)&InvokeBehaviourTask::`vftable;
  v2 = &v1->m_pBehaviour;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::Behaviour>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::Behaviour>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v1->m_pBehaviour.m_pPointer = 0i64;
  v3 = &v1->m_pParentBehaviour;
  v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::Behaviour>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::Behaviour>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  v1->m_pParentBehaviour.m_pPointer = 0i64;
  v4 = &v1->m_pBehaviourController;
  v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  v4->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  v1->m_pBehaviourController.m_pPointer = 0i64;
  v1->m_InvokeResult.mId = 0;
  v1->m_InvokeResult.mDesc = 0i64;
  v1->m_InvokeResult.mInvokeParams.mNode = 0i64;
  *(_QWORD *)&v1->m_InvokeResult.mInvokeParams.mPriority = 0i64;
  v1->m_InvokeResult.mInvokeParams.mControlType = 0;
  v1->m_InvokeResult.mInvokeParams.mMaxWaitTime = -1.0;
  v1->m_InvokeResult.mInvokeParams.mMaxLifeTime = -1.0;
  v1->m_InvokeResult.mInvokeParams.mIsRootInvoke = 1;
  v1->m_InvokeResult.mInvokeParams.mInvokeTask = 0i64;
  v1->m_InvokeResult.mBehaviour = 0i64;
}

// File Line: 8142
// RVA: 0x338DE0
void __fastcall InvokeBehaviourTask::~InvokeBehaviourTask(InvokeBehaviourTask *this)
{
  InvokeBehaviourTask *v1; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::BehaviourControllerComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::Behaviour,UFG::Behaviour> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::Behaviour>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::Behaviour>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::Behaviour>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::Behaviour>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qSafePointer<UFG::Behaviour,UFG::Behaviour> *v12; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::Behaviour>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::Behaviour>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::Behaviour>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::Behaviour>,UFG::qSafePointerNodeList> *v16; // rax

  v1 = this;
  this->vfptr = (ITaskVtbl *)&InvokeBehaviourTask::`vftable;
  v2 = &this->m_pBehaviourController;
  if ( this->m_pBehaviourController.m_pPointer )
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
  v7 = &v1->m_pParentBehaviour;
  if ( v1->m_pParentBehaviour.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v1->m_pParentBehaviour.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::Behaviour>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v1->m_pParentBehaviour.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::Behaviour>,UFG::qSafePointerNodeList> *)&v1->m_pParentBehaviour.mPrev;
  }
  v1->m_pParentBehaviour.m_pPointer = 0i64;
  v10 = v7->mPrev;
  v11 = v1->m_pParentBehaviour.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::Behaviour>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v1->m_pParentBehaviour.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::Behaviour>,UFG::qSafePointerNodeList> *)&v1->m_pParentBehaviour.mPrev;
  v12 = &v1->m_pBehaviour;
  if ( v1->m_pBehaviour.m_pPointer )
  {
    v13 = v12->mPrev;
    v14 = v1->m_pBehaviour.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::Behaviour>,UFG::qSafePointerNodeList> *)&v12->mPrev;
    v1->m_pBehaviour.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::Behaviour>,UFG::qSafePointerNodeList> *)&v1->m_pBehaviour.mPrev;
  }
  v1->m_pBehaviour.m_pPointer = 0i64;
  v15 = v12->mPrev;
  v16 = v1->m_pBehaviour.mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::Behaviour>,UFG::qSafePointerNodeList> *)&v12->mPrev;
  v1->m_pBehaviour.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::Behaviour>,UFG::qSafePointerNodeList> *)&v1->m_pBehaviour.mPrev;
  SpawnTask::~SpawnTask((SpawnTask *)&v1->vfptr);
}

// File Line: 8146
// RVA: 0x3467C0
void __fastcall InvokeBehaviourTask::Begin(InvokeBehaviourTask *this, ActionContext *context)
{
  InvokeBehaviourTask *v2; // rbx
  UFG::SimObjectCVBase *v3; // rcx
  ActionContext *v4; // rdi
  UFG::BehaviourControllerComponent *v5; // r8
  unsigned __int16 v6; // dx
  UFG::BehaviourControllerComponent *v7; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::BehaviourControllerComponent> *v8; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::BehaviourControllerComponent *v12; // r9
  UFG::qSymbolUC *v13; // rax
  char *v14; // rax
  ITrack *v15; // rcx
  Expression::IMemberMapVtbl *v16; // rax
  Expression::IMemberMap *(__fastcall *v17)(Expression::IMemberMap *); // rdx
  ActionNode *v18; // r8
  UFG::eInvokeBehaviourPriorityMode v19; // edi
  float v20; // xmm0_4
  float v21; // xmm1_4
  int v22; // eax
  UFG::Behaviour *v23; // rax
  UFG::qSafePointer<UFG::Behaviour,UFG::Behaviour> *v24; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::Behaviour>,UFG::qSafePointerNodeList> *v25; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::Behaviour>,UFG::qSafePointerNodeList> *v26; // rcx
  UFG::qList<UFG::qSafePointerBase<UFG::Behaviour>,UFG::qSafePointerNodeList,1,0> *v27; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::Behaviour>,UFG::qSafePointerNodeList> *v28; // rax
  UFG::BehaviourControllerComponent *v29; // rcx
  UFG::InvokeBehaviourResult *v30; // r8
  bool v31; // al
  signed int v32; // eax
  UFG::Behaviour *v33; // r8
  UFG::qSafePointer<UFG::Behaviour,UFG::Behaviour> *v34; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::Behaviour>,UFG::qSafePointerNodeList> *v35; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::Behaviour>,UFG::qSafePointerNodeList> *v36; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::Behaviour>,UFG::qSafePointerNodeList> *v37; // rax
  UFG::InvokeBehaviourParams params; // [rsp+20h] [rbp-38h]
  UFG::qWiseSymbol result; // [rsp+60h] [rbp+8h]

  v2 = this;
  v3 = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  v4 = context;
  if ( v3 )
  {
    v6 = v3->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v7 = UFG::SimObjectCVBase::GetComponent<UFG::BehaviourControllerComponent>(v3);
    }
    else if ( (v6 & 0x8000u) == 0 )
    {
      if ( (v6 >> 13) & 1 )
      {
        v7 = (UFG::BehaviourControllerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    (UFG::SimObjectGame *)&v3->vfptr,
                                                    UFG::BehaviourControllerComponent::_TypeUID);
      }
      else if ( (v6 >> 12) & 1 )
      {
        v7 = (UFG::BehaviourControllerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    (UFG::SimObjectGame *)&v3->vfptr,
                                                    UFG::BehaviourControllerComponent::_TypeUID);
      }
      else
      {
        v7 = (UFG::BehaviourControllerComponent *)UFG::SimObject::GetComponentOfType(
                                                    (UFG::SimObject *)&v3->vfptr,
                                                    UFG::BehaviourControllerComponent::_TypeUID);
      }
    }
    else
    {
      v7 = UFG::SimObjectCVBase::GetComponent<UFG::BehaviourControllerComponent>(v3);
    }
    v5 = v7;
  }
  else
  {
    v5 = 0i64;
  }
  v8 = &v2->m_pBehaviourController;
  if ( v2->m_pBehaviourController.m_pPointer )
  {
    v9 = v8->mPrev;
    v10 = v2->m_pBehaviourController.mNext;
    v9->mNext = v10;
    v10->mPrev = v9;
    v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
    v2->m_pBehaviourController.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pBehaviourController.mPrev;
  }
  v2->m_pBehaviourController.m_pPointer = (UFG::SimComponent *)&v5->vfptr;
  if ( v5 )
  {
    v11 = v5->m_SafePointerList.mNode.mPrev;
    v11->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
    v8->mPrev = v11;
    v2->m_pBehaviourController.mNext = &v5->m_SafePointerList.mNode;
    v5->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
  }
  v12 = (UFG::BehaviourControllerComponent *)v2->m_pBehaviourController.m_pPointer;
  if ( v12 )
  {
    v15 = v2->m_Track;
    v2->m_CallingActionContext = v4;
    v16 = v15[1].vfptr;
    if ( v16 )
      v16 = (Expression::IMemberMapVtbl *)((char *)v16 + (_QWORD)v15 + 56);
    v17 = v16->GetResourceOwner;
    if ( v17 )
      v18 = (ActionNode *)((char *)&v16->GetResourceOwner + (_QWORD)v17);
    else
      v18 = 0i64;
    v19 = (unsigned __int8)v15[1].mBreakPoint;
    v20 = *((float *)&v15[1].mMasterRate.text.mOffset + 1);
    v21 = *(float *)&v15[1].mMasterRate.text.mOffset;
    params.mControlType = (unsigned __int8)v15[1].mDisable;
    v22 = v15[1].m_TrackClassNameUID;
    params.mMaxLifeTime = v20;
    params.mMaxWaitTime = v21;
    params.mNode = v18;
    params.mPriority = v22;
    params.mPriorityMode = v19;
    params.mInvokeTask = v2;
    v23 = UFG::BehaviourControllerComponent::FindParentBehaviourOfTask(v12, v2);
    v24 = &v2->m_pParentBehaviour;
    if ( v2->m_pParentBehaviour.m_pPointer )
    {
      v25 = v24->mPrev;
      v26 = v2->m_pParentBehaviour.mNext;
      v25->mNext = v26;
      v26->mPrev = v25;
      v24->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::Behaviour>,UFG::qSafePointerNodeList> *)&v24->mPrev;
      v2->m_pParentBehaviour.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::Behaviour>,UFG::qSafePointerNodeList> *)&v2->m_pParentBehaviour.mPrev;
    }
    v2->m_pParentBehaviour.m_pPointer = v23;
    if ( v23 )
    {
      v27 = &v23->m_SafePointerList;
      v28 = v23->m_SafePointerList.mNode.mPrev;
      v28->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::Behaviour>,UFG::qSafePointerNodeList> *)&v24->mPrev;
      v24->mPrev = v28;
      v2->m_pParentBehaviour.mNext = &v27->mNode;
      v27->mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::Behaviour>,UFG::qSafePointerNodeList> *)&v24->mPrev;
    }
    v29 = (UFG::BehaviourControllerComponent *)v2->m_pBehaviourController.m_pPointer;
    v30 = &v2->m_InvokeResult;
    v31 = v2->m_pParentBehaviour.m_pPointer == 0i64;
    params.mIsRootInvoke = v2->m_pParentBehaviour.m_pPointer == 0i64;
    if ( v19 == 4 )
    {
      v32 = UFG::BehaviourControllerComponent::Arbitrate_StartRootParallel(v29, &params, v30);
    }
    else if ( v31 )
    {
      v32 = UFG::BehaviourControllerComponent::Arbitrate_StartRootExclusive(v29, &params, v30);
    }
    else
    {
      v32 = UFG::BehaviourControllerComponent::Arbitrate_StartChild(v29, &params, v30);
    }
    if ( v32 >= 1 )
    {
      v33 = v2->m_InvokeResult.mBehaviour;
      v34 = &v2->m_pBehaviour;
      if ( v2->m_pBehaviour.m_pPointer )
      {
        v35 = v34->mPrev;
        v36 = v2->m_pBehaviour.mNext;
        v35->mNext = v36;
        v36->mPrev = v35;
        v34->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::Behaviour>,UFG::qSafePointerNodeList> *)&v34->mPrev;
        v2->m_pBehaviour.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::Behaviour>,UFG::qSafePointerNodeList> *)&v2->m_pBehaviour.mPrev;
      }
      v2->m_pBehaviour.m_pPointer = v33;
      if ( v33 )
      {
        v37 = v33->m_SafePointerList.mNode.mPrev;
        v37->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::Behaviour>,UFG::qSafePointerNodeList> *)&v34->mPrev;
        v34->mPrev = v37;
        v2->m_pBehaviour.mNext = &v33->m_SafePointerList.mNode;
        v33->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::Behaviour>,UFG::qSafePointerNodeList> *)&v34->mPrev;
      }
      v2->m_InvokeResult.mBehaviour = 0i64;
    }
  }
  else
  {
    v13 = (UFG::qSymbolUC *)UFG::qSymbol::qSymbol(&result, v4->mSimObject.m_pPointer->m_pSceneObj->m_NameUID);
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
  UFG::BehaviourControllerComponent *v2; // r8
  InvokeBehaviourTask *v3; // rbx
  UFG::Behaviour *v4; // rax
  UFG::eInvokeBehaviourState v5; // ecx
  UFG::Behaviour *v7; // rax

  v2 = (UFG::BehaviourControllerComponent *)this->m_pBehaviourController.m_pPointer;
  v3 = this;
  if ( !v2 )
    return 0;
  v4 = this->m_pBehaviour.m_pPointer;
  if ( !v4 )
    return 0;
  if ( v4->mParams.mControlType == eINVOKE_AND_OWN )
  {
    v5 = v4->mState;
    if ( v5 == 1 )
    {
      UFG::BehaviourControllerComponent::UpdateBehaviour(v2, v4, timestep);
      v7 = v3->m_pBehaviour.m_pPointer;
      if ( v7 && v7->mActionController->m_currentNode )
        return 1;
    }
    else if ( (unsigned int)(v5 - 2) <= 1 )
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
  UFG::Behaviour *v1; // rdx

  v1 = this->m_pBehaviour.m_pPointer;
  if ( v1 )
  {
    if ( v1->mParams.mControlType == eINVOKE_AND_OWN )
      UFG::BehaviourControllerComponent::EndBehaviour(
        (UFG::BehaviourControllerComponent *)this->m_pBehaviourController.m_pPointer,
        v1);
  }
}

// File Line: 8255
// RVA: 0x342CA0
void __fastcall AIAwarenessEnableTask::Begin(AIAwarenessEnableTask *this, ActionContext *context)
{
  AIAwarenessEnableTask *v2; // rbx
  UFG::SimComponent *v3; // rax

  v2 = this;
  v3 = UFG::SimObject::GetComponentOfType(context->mSimObject.m_pPointer, UFG::AIAwarenessComponent::_TypeUID);
  if ( v3 )
    LOBYTE(v3[1].m_BoundComponentHandles.mNode.mPrev) = LOBYTE(v2->m_Track[1].vfptr) != 0;
}

// File Line: 8272
// RVA: 0x342B30
void __fastcall AIAwarenessAddTargetTask::Begin(AIAwarenessAddTargetTask *this, ActionContext *context)
{
  AIAwarenessAddTargetTask *v2; // rbp
  UFG::SimObjectGame *v3; // rcx
  UFG::AIAwarenessComponent *v4; // rbx
  UFG::SimComponent *v5; // rdi
  unsigned __int16 v6; // dx
  UFG::SimComponent *v7; // rax
  UFG::SimObjectGame *v8; // rcx
  unsigned __int16 v9; // dx
  UFG::SimComponent *v10; // rax
  ITrack *v11; // rdx
  UFG::SimObject *v12; // rdi

  v2 = this;
  this->mContext = context;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  v4 = 0i64;
  if ( v3 )
  {
    v6 = v3->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v5 = v3->m_Components.p[20].m_pComponent;
    }
    else if ( (v6 & 0x8000u) == 0 )
    {
      if ( (v6 >> 13) & 1 )
      {
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else if ( (v6 >> 12) & 1 )
      {
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else
      {
        v7 = UFG::SimObject::GetComponentOfType(
               (UFG::SimObject *)&v3->vfptr,
               UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      v5 = v7;
    }
    else
    {
      v5 = v3->m_Components.p[20].m_pComponent;
    }
  }
  else
  {
    v5 = 0i64;
  }
  v8 = (UFG::SimObjectGame *)v2->mContext->mSimObject.m_pPointer;
  if ( v8 )
  {
    v9 = v8->m_Flags;
    if ( (v9 >> 14) & 1 )
    {
      v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::AIAwarenessComponent::_TypeUID);
    }
    else if ( (v9 & 0x8000u) == 0 )
    {
      if ( (v9 >> 13) & 1 )
      {
        v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::AIAwarenessComponent::_TypeUID);
      }
      else if ( (v9 >> 12) & 1 )
      {
        v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::AIAwarenessComponent::_TypeUID);
      }
      else
      {
        v10 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v8->vfptr, UFG::AIAwarenessComponent::_TypeUID);
      }
    }
    else
    {
      v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::AIAwarenessComponent::_TypeUID);
    }
    v4 = (UFG::AIAwarenessComponent *)v10;
  }
  v2->mName = UFG::gNullQSymbol;
  v11 = v2->m_Track;
  v12 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(LOBYTE(v11[1].vfptr) + *(_QWORD *)&v5[1].m_Flags + 8i64)
                           + *(_QWORD *)&v5[1].m_TypeUID
                           + 40);
  if ( v12 )
  {
    UFG::AIAwarenessComponent::AddTargetSimObject(v4, v12, (UFG::AIAwareness::TargetPriority)BYTE1(v11[1].vfptr));
    v2->mName.mUID = v12->m_Name.mUID;
    UFG::AIAwarenessComponent::LockSimObject(v4, &v2->mName);
  }
}

// File Line: 8304
// RVA: 0x354C10
void __fastcall AIAwarenessAddTargetTask::End(AIAwarenessAddTargetTask *this)
{
  AIAwarenessAddTargetTask *v1; // rbx
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::AIAwarenessComponent *v4; // rax

  v1 = this;
  v2 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = (UFG::AIAwarenessComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                          v2,
                                          UFG::AIAwarenessComponent::_TypeUID);
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
      {
        v4 = (UFG::AIAwarenessComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                            v2,
                                            UFG::AIAwarenessComponent::_TypeUID);
      }
      else if ( (v3 >> 12) & 1 )
      {
        v4 = (UFG::AIAwarenessComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                            v2,
                                            UFG::AIAwarenessComponent::_TypeUID);
      }
      else
      {
        v4 = (UFG::AIAwarenessComponent *)UFG::SimObject::GetComponentOfType(
                                            (UFG::SimObject *)&v2->vfptr,
                                            UFG::AIAwarenessComponent::_TypeUID);
      }
    }
    else
    {
      v4 = (UFG::AIAwarenessComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                          v2,
                                          UFG::AIAwarenessComponent::_TypeUID);
    }
    if ( v4 )
    {
      if ( v1->mName.mUID != -1 )
        UFG::AIAwarenessComponent::UnlockSimObject(v4, &v1->mName);
    }
  }
}

// File Line: 8320
// RVA: 0x14B9160
__int64 dynamic_initializer_for__symHeadTracker__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("HeadTracker", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&symHeadTracker, v0);
  return atexit(dynamic_atexit_destructor_for__symHeadTracker__);
}

// File Line: 8321
// RVA: 0x14B91E0
__int64 dynamic_initializer_for__symREyeTracker__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("R_EyeTracker", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&symREyeTracker, v0);
  return atexit(dynamic_atexit_destructor_for__symREyeTracker__);
}

// File Line: 8322
// RVA: 0x14B91A0
__int64 dynamic_initializer_for__symLEyeTracker__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("L_EyeTracker", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&symLEyeTracker, v0);
  return atexit(dynamic_atexit_destructor_for__symLEyeTracker__);
}

// File Line: 8323
// RVA: 0x14B9220
__int64 dynamic_initializer_for__symSpineTracker__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("SpineTracker", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&symSpineTracker, v0);
  return atexit(dynamic_atexit_destructor_for__symSpineTracker__);
}

// File Line: 8327
// RVA: 0x346C00
void __fastcall LookAtTask::Begin(LookAtTask *this, ActionContext *context)
{
  LookAtTask *v2; // rbx
  UFG::SimComponent *v3; // rax
  __int64 v4; // rcx
  signed __int64 v5; // rax
  signed __int64 v6; // rdx
  signed __int64 v7; // r8
  signed __int64 v8; // r9
  signed __int64 v9; // r10

  this->mContext = context;
  v2 = this;
  v3 = UFG::SimObject::GetComponentOfType(context->mSimObject.m_pPointer, UFG::CharacterAnimationComponent::_TypeUID);
  if ( v3 )
  {
    v4 = *(_QWORD *)&v3[2].m_TypeUID;
    if ( v4 )
    {
      v5 = *(_QWORD *)(v4 + 32) - 16i64;
      if ( v5 != v4 + 8 )
      {
        v6 = (signed __int64)v2->mHeadTrackEffector;
        v7 = (signed __int64)v2->mRightEyeTrackEffector;
        v8 = (signed __int64)v2->mLeftEyeTrackEffector;
        v9 = (signed __int64)v2->mSpineTrackEffector;
        do
        {
          if ( !v6 && *(_DWORD *)(v5 + 44) == symHeadTracker.mUID )
          {
            v6 = v5;
            v2->mHeadTrackEffector = (AimConstraint *)v5;
          }
          if ( !v7 && *(_DWORD *)(v5 + 44) == symREyeTracker.mUID )
          {
            v7 = v5;
            v2->mRightEyeTrackEffector = (AimConstraint *)v5;
          }
          if ( !v8 && *(_DWORD *)(v5 + 44) == symLEyeTracker.mUID )
          {
            v8 = v5;
            v2->mLeftEyeTrackEffector = (AimConstraint *)v5;
          }
          if ( !v9 && LOBYTE(v2->m_Track[1].vfptr) && *(_DWORD *)(v5 + 44) == symSpineTracker.mUID )
          {
            v9 = v5;
            v2->mSpineTrackEffector = (AimConstraintMultiLink *)v5;
          }
          v5 = *(_QWORD *)(v5 + 24) - 16i64;
        }
        while ( v5 != v4 + 8 );
      }
    }
  }
}

// File Line: 8376
// RVA: 0x3906A0
char __fastcall LookAtTask::Update(LookAtTask *this, float timeDelta)
{
  LookAtTask *v2; // rdi
  UFG::SimObject *v3; // rbx
  UFG::SimComponent *v4; // rsi
  __int64 v5; // rdx
  bool v6; // si
  AimConstraint *v7; // rax
  AimConstraint *v8; // rcx
  AimConstraint *v9; // rcx
  AimConstraintMultiLink *v10; // rcx
  AimConstraint *v11; // rcx
  AimConstraint *v12; // rcx
  unsigned int v13; // eax
  unsigned int v14; // xmm1_4
  AimConstraintMultiLink *v15; // rcx
  AimConstraintMultiLink *v16; // rcx
  unsigned int v17; // eax
  unsigned int v18; // xmm1_4
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

  v2 = this;
  v3 = this->mContext->mSimObject.m_pPointer;
  if ( !((v3->m_Flags >> 14) & 1) )
    return 1;
  v4 = UFG::SimObject::GetComponentOfType(
         this->mContext->mSimObject.m_pPointer,
         UFG::CharacterAnimationComponent::_TypeUID);
  if ( v3 )
    v3 = (UFG::SimObject *)UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>((UFG::SimObjectCVBase *)v3);
  if ( !v4 || !v3 || !*(_QWORD *)&v4[2].m_TypeUID )
    return 1;
  v6 = UFG::AIAwarenessComponent::IsVisualTrackingEnabled();
  if ( v6 )
  {
    if ( BYTE4(v3[1].m_pTransformNodeComponent) )
    {
      v7 = v2->mHeadTrackEffector;
      if ( v7 )
      {
        LODWORD(v7->mXJointLimitMag) = v3[1].m_Components.size;
        LODWORD(v2->mHeadTrackEffector->mYJointLimitMag) = v3[1].m_Components.capacity;
        v2->mHeadTrackEffector->mZJointLimitMag = *(float *)&v3[1].m_Components.p;
        v2->mHeadTrackEffector->mTrackingGain = *((float *)&v3[2].vfptr + 1);
      }
    }
    if ( BYTE5(v3[1].m_pTransformNodeComponent) )
    {
      v8 = v2->mRightEyeTrackEffector;
      if ( v8 )
      {
        v8->mXJointLimitMag = *((float *)&v3[1].m_Components.p + 1);
        v2->mRightEyeTrackEffector->mYJointLimitMag = *(float *)&v3[1].m_UnboundComponentHandles.mNode.mPrev;
        v2->mRightEyeTrackEffector->mZJointLimitMag = *((float *)&v3[1].m_UnboundComponentHandles.mNode.mPrev + 1);
        v2->mRightEyeTrackEffector->mTrackingGain = *(float *)&v3[2].m_SafePointerList.mNode.mPrev;
      }
      if ( BYTE5(v3[1].m_pTransformNodeComponent) )
      {
        v9 = v2->mLeftEyeTrackEffector;
        if ( v9 )
        {
          v9->mXJointLimitMag = *((float *)&v3[1].m_Components.p + 1);
          v2->mLeftEyeTrackEffector->mYJointLimitMag = *(float *)&v3[1].m_UnboundComponentHandles.mNode.mPrev;
          v2->mLeftEyeTrackEffector->mZJointLimitMag = *((float *)&v3[1].m_UnboundComponentHandles.mNode.mPrev + 1);
          v2->mLeftEyeTrackEffector->mTrackingGain = *(float *)&v3[2].m_SafePointerList.mNode.mPrev;
        }
      }
    }
    if ( BYTE6(v3[1].m_pTransformNodeComponent) )
    {
      v10 = v2->mSpineTrackEffector;
      if ( v10 )
      {
        v10->mXJointLimitMaxMag = *(float *)&v3[1].m_UnboundComponentHandles.mNode.mNext;
        v2->mSpineTrackEffector->mYJointLimitMaxMag = *((float *)&v3[1].m_UnboundComponentHandles.mNode.mNext + 1);
        v2->mSpineTrackEffector->mZJointLimitMaxMag = *(float *)&v3[2].vfptr;
        LODWORD(v2->mSpineTrackEffector->mXJointLimitMinMag) = LODWORD(v3[1].m_UnboundComponentHandles.mNode.mNext) ^ _xmm[0];
        LODWORD(v2->mSpineTrackEffector->mYJointLimitMinMag) = HIDWORD(v3[1].m_UnboundComponentHandles.mNode.mNext) ^ _xmm[0];
        LODWORD(v2->mSpineTrackEffector->mZJointLimitMinMag) = LODWORD(v3[2].vfptr) ^ _xmm[0];
        v2->mSpineTrackEffector->mTrackingGain = *((float *)&v3[2].m_SafePointerList.mNode.mPrev + 1);
      }
    }
  }
  v11 = v2->mHeadTrackEffector;
  if ( BYTE4(v3[1].mNode.mChild[1]) )
  {
    if ( v11 )
    {
      LOBYTE(v5) = 1;
      if ( v6 )
        v5 = BYTE4(v3[1].m_pTransformNodeComponent);
      v11->vfptr[1].__vecDelDtor((Expression::IMemberMap *)&v11->vfptr, v5);
      v12 = v2->mHeadTrackEffector;
      v13 = v3[1].mNode.mUID;
      v14 = v3[1].m_Name.mUID;
      v12->mTargetPointWS.y = *((float *)&v3[1].mNode.mUID + 1);
      LODWORD(v12->mTargetPointWS.z) = v14;
      LODWORD(v12->mTargetPointWS.x) = v13;
    }
    v15 = v2->mSpineTrackEffector;
    if ( v15 )
    {
      LOBYTE(v5) = LOBYTE(v2->m_Track[1].vfptr) != 0;
      if ( v6 )
        v5 = BYTE6(v3[1].m_pTransformNodeComponent);
      v15->vfptr[1].__vecDelDtor((Expression::IMemberMap *)&v15->vfptr, v5);
      v16 = v2->mSpineTrackEffector;
      v17 = v3[1].mNode.mUID;
      v18 = v3[1].m_Name.mUID;
      v16->mTargetPointWS.y = *((float *)&v3[1].mNode.mUID + 1);
      LODWORD(v16->mTargetPointWS.z) = v18;
      LODWORD(v16->mTargetPointWS.x) = v17;
    }
  }
  else
  {
    if ( v11 )
      v11->vfptr[1].__vecDelDtor((Expression::IMemberMap *)&v11->vfptr, 0);
    v19 = v2->mSpineTrackEffector;
    if ( v19 )
      v19->vfptr[1].__vecDelDtor((Expression::IMemberMap *)&v19->vfptr, 0);
  }
  if ( !LOBYTE(v3[1].m_Flags) )
  {
    v30 = v2->mRightEyeTrackEffector;
    if ( v30 )
      v30->vfptr[1].__vecDelDtor((Expression::IMemberMap *)&v30->vfptr, 0);
    v31 = v2->mLeftEyeTrackEffector;
    if ( v31 )
      v31->vfptr[1].__vecDelDtor((Expression::IMemberMap *)&v31->vfptr, 0);
    return 1;
  }
  v20 = 1;
  if ( v6 )
    v20 = BYTE5(v3[1].m_pTransformNodeComponent);
  v21 = v2->mRightEyeTrackEffector;
  if ( v21 )
  {
    v21->vfptr[1].__vecDelDtor((Expression::IMemberMap *)&v21->vfptr, v20);
    v22 = v2->mRightEyeTrackEffector;
    v23 = *(float *)&v3[1].m_pSceneObj;
    v24 = *(float *)&v3[1].m_pTransformNodeComponent;
    v22->mTargetPointWS.y = *((float *)&v3[1].m_pSceneObj + 1);
    v22->mTargetPointWS.z = v24;
    v22->mTargetPointWS.x = v23;
  }
  v25 = v2->mLeftEyeTrackEffector;
  if ( v25 )
  {
    v25->vfptr[1].__vecDelDtor((Expression::IMemberMap *)&v25->vfptr, v20);
    v26 = v2->mLeftEyeTrackEffector;
    v27 = *(float *)&v3[1].m_pSceneObj;
    v28 = *(float *)&v3[1].m_pTransformNodeComponent;
    v26->mTargetPointWS.y = *((float *)&v3[1].m_pSceneObj + 1);
    v26->mTargetPointWS.z = v28;
    v26->mTargetPointWS.x = v27;
  }
  return 1;
}

// File Line: 8506
// RVA: 0x3552E0
void __fastcall LookAtTask::End(LookAtTask *this)
{
  LookAtTask *v1; // rbx
  AimConstraint *v2; // rcx
  AimConstraint *v3; // rcx
  AimConstraint *v4; // rcx
  AimConstraintMultiLink *v5; // rcx

  v1 = this;
  v2 = this->mHeadTrackEffector;
  if ( v2 )
    v2->vfptr[1].__vecDelDtor((Expression::IMemberMap *)&v2->vfptr, 0);
  v3 = v1->mRightEyeTrackEffector;
  if ( v3 )
    v3->vfptr[1].__vecDelDtor((Expression::IMemberMap *)&v3->vfptr, 0);
  v4 = v1->mLeftEyeTrackEffector;
  if ( v4 )
    v4->vfptr[1].__vecDelDtor((Expression::IMemberMap *)&v4->vfptr, 0);
  v5 = v1->mSpineTrackEffector;
  if ( v5 )
    v5->vfptr[1].__vecDelDtor((Expression::IMemberMap *)&v5->vfptr, 0);
}

// File Line: 8534
// RVA: 0x348B00
void __fastcall TestPathToTargetTask::Begin(TestPathToTargetTask *this, ActionContext *context)
{
  UFG::SimObjectCharacter *v2; // rdi
  TestPathToTargetTask *v3; // rbx
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0> *v4; // r9
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rax

  this->m_pActionContext = context;
  v2 = (UFG::SimObjectCharacter *)context->mSimObject.m_pPointer;
  v3 = this;
  UFG::RebindingComponentHandle<UFG::NavComponent,0>::Bind<UFG::SimObjectCharacter>(
    &this->m_navComponent,
    (UFG::SimObjectCharacter *)context->mSimObject.m_pPointer);
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>::Bind<UFG::SimObjectCharacter>(
    &v3->m_targetingSysComponent,
    v2);
  v4 = &v3->m_AIEntityComponent;
  if ( v3->m_AIEntityComponent.m_pSimComponent )
  {
    v5 = v4->mPrev;
    v6 = v3->m_AIEntityComponent.mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v3->m_AIEntityComponent.m_pSimComponent = 0i64;
LABEL_7:
    v3->m_AIEntityComponent.m_pSimObject = 0i64;
    v3->m_AIEntityComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->m_AIEntityComponent.mPrev;
    v4->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v4->mPrev;
    goto LABEL_8;
  }
  if ( v3->m_AIEntityComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0> *)v4->mPrev != v4
     || (UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0> *)v3->m_AIEntityComponent.mNext != &v3->m_AIEntityComponent) )
  {
    v7 = v4->mPrev;
    v8 = v3->m_AIEntityComponent.mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    goto LABEL_7;
  }
LABEL_8:
  v3->m_AIEntityComponent.m_Changed = 1;
  v3->m_AIEntityComponent.m_pSimObject = (UFG::SimObject *)&v2->vfptr;
  v3->m_AIEntityComponent.m_TypeUID = UFG::ActiveAIEntityComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0>::BindInternal<UFG::SimObjectCharacter>(
    &v3->m_AIEntityComponent,
    v2);
  v3->m_uTimeToNextPathfind = 0i64;
  v3->m_bWaitingForResult = 0;
}

// File Line: 8550
// RVA: 0x393570
char __fastcall TestPathToTargetTask::Update(TestPathToTargetTask *this, float timeDelta)
{
  TestPathToTargetTask *v2; // rdi
  UFG::SimComponent *v3; // r10
  UFG::DaemonOutputStatus v4; // er11
  unsigned int v5; // edx
  UFG::SimObject *v6; // r9
  unsigned int v7; // ecx
  UFG::PedKnowledgeRecord *v8; // rax
  unsigned __int64 v9; // rbx

  v2 = this;
  if ( !this->m_bWaitingForResult )
  {
    if ( this->m_uTimeToNextPathfind < UFG::Metrics::msInstance.mSimTimeMSec )
      TestPathToTargetTask::StartPathTest(this);
    return 1;
  }
  v3 = this->m_AIEntityComponent.m_pSimComponent;
  v4 = this->m_PathQueryOutput.m_status;
  v5 = (unsigned int)v3[21].m_pSimObject;
  v6 = *(UFG::SimObject **)(56i64
                          * *(unsigned __int8 *)(LOBYTE(this->m_Track[1].vfptr)
                                               + *(_QWORD *)&this->m_targetingSysComponent.m_pSimComponent[1].m_Flags
                                               + 8i64)
                          + *(_QWORD *)&this->m_targetingSysComponent.m_pSimComponent[1].m_TypeUID
                          + 40);
  v7 = 0;
  if ( v5 )
  {
    v8 = (UFG::PedKnowledgeRecord *)v3[21].m_BoundComponentHandles.mNode.mPrev;
    while ( v6 != v8->pSimObject.m_pPointer )
    {
      ++v7;
      ++v8;
      if ( v7 >= v5 )
        goto LABEL_6;
    }
  }
  else
  {
LABEL_6:
    v8 = &UFG::PedKnowledgeBase::ms_defaultKnowledgeRecord;
  }
  if ( v4 == 4 )
  {
    v2->m_bWaitingForResult = 0;
    *((_BYTE *)v8 + 48) &= 0xFBu;
  }
  else
  {
    if ( v4 != 3 )
      goto LABEL_12;
    v2->m_bWaitingForResult = 0;
    *((_BYTE *)v8 + 48) |= 4u;
  }
  v8->m_uLastPathTest = UFG::Metrics::msInstance.mSimTimeMSec;
LABEL_12:
  if ( !v2->m_bWaitingForResult )
  {
    v9 = UFG::Metrics::msInstance.mSimTimeMSec;
    v2->m_uTimeToNextPathfind = (signed int)UFG::qRandom(1300, &UFG::qDefaultSeed) + v9 + 700;
    return 1;
  }
  return 1;
}

// File Line: 8592
// RVA: 0x388E40
void __fastcall TestPathToTargetTask::StartPathTest(TestPathToTargetTask *this)
{
  TestPathToTargetTask *v1; // rsi
  __int64 v2; // rcx
  __int64 v3; // rbp
  hkVector4f *v4; // rcx
  UFG::HavokNavPosition *v5; // rdi
  float v6; // xmm0_4
  float v7; // xmm1_4
  char v8; // al
  signed __int64 v9; // rbx
  int v10; // xmm1_4
  int v11; // xmm0_4
  UFG::SimComponent *v12; // rax
  UFG::DaemonManager *v13; // rax

  v1 = this;
  v2 = *(_QWORD *)(56i64
                 * *(unsigned __int8 *)(*(_QWORD *)&this->m_targetingSysComponent.m_pSimComponent[1].m_Flags + 30i64)
                 + *(_QWORD *)&this->m_targetingSysComponent.m_pSimComponent[1].m_TypeUID
                 + 40);
  if ( v2 )
  {
    v3 = *(_QWORD *)(v2 + 88);
    if ( v3 )
    {
      v4 = (hkVector4f *)v1->m_navComponent.m_pSimComponent;
      v5 = &v1->m_PathQueryInput.m_npFrom;
      v6 = v4[5].m_quad.m128_f32[3];
      v7 = v4[6].m_quad.m128_f32[0];
      v5->m_vPosition.x = v4[5].m_quad.m128_f32[2];
      v5->m_vPosition.y = v6;
      v5->m_vPosition.z = v7;
      v8 = v4[6].m_quad.m128_i8[8];
      if ( v8 )
      {
        v1->m_PathQueryInput.m_npFrom.m_bValid = v8;
        v1->m_PathQueryInput.m_npFrom.m_hkvMeshPosition = (hkVector4f)v4[7].m_quad;
        v1->m_PathQueryInput.m_npFrom.m_packedKey = v4[8].m_quad.m128_u32[0];
        v1->m_PathQueryInput.m_npFrom.m_aiMeshUid = v4[8].m_quad.m128_u32[1];
      }
      else
      {
        v1->m_PathQueryInput.m_npFrom.m_bValid = 0;
      }
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v3);
      v9 = (signed __int64)&v1->m_PathQueryInput.m_npTo;
      v10 = *(_DWORD *)(v3 + 184);
      v11 = *(_DWORD *)(v3 + 180);
      *(_DWORD *)(v9 + 8) = *(_DWORD *)(v3 + 176);
      *(_DWORD *)(v9 + 16) = v10;
      *(_DWORD *)(v9 + 12) = v11;
      *(_BYTE *)(v9 + 24) = 0;
      ((void (__fastcall *)(UFG::HavokNavPosition *))v5->vfptr->Validate)(&v1->m_PathQueryInput.m_npFrom);
      ((void (__fastcall *)(UFG::HavokNavPosition *))v1->m_PathQueryInput.m_npTo.vfptr->Validate)(&v1->m_PathQueryInput.m_npTo);
      v12 = v1->m_navComponent.m_pSimComponent;
      v1->m_PathQueryInput.m_maxSearchIterations = -1;
      v1->m_PathQueryInput.m_pNavParams = (UFG::NavParams *)((char *)&v12[2].m_BoundComponentHandles.mNode.mNext + 4);
      if ( v5->vfptr->IsMeshPositionValid((UFG::NavPositionBase *)&v1->m_PathQueryInput.m_npFrom.vfptr) )
      {
        v13 = UFG::DaemonManager::Instance();
        UFG::DaemonManager::SubmitQuery(
          v13,
          (UFG::DaemonQueryInput *)&v1->m_PathQueryInput.vfptr,
          (UFG::DaemonQueryOutput *)&v1->m_PathQueryOutput.vfptr);
        v1->m_bWaitingForResult = 1;
      }
    }
  }
}

// File Line: 8619
// RVA: 0x355570
void __fastcall TestPathToTargetTask::End(TestPathToTargetTask *this)
{
  UFG::DaemonQueryInput *v1; // rbx
  UFG::DaemonManager *v2; // rax

  v1 = (UFG::DaemonQueryInput *)&this->m_PathQueryInput.vfptr;
  v2 = UFG::DaemonManager::Instance();
  UFG::DaemonManager::CancelQuery(v2, v1);
}

