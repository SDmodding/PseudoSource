// File Line: 48
// RVA: 0x1543E20
__int64 dynamic_initializer_for__UFG::FaceActionComponent::s_FaceActionComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::FaceActionComponent::s_FaceActionComponentList__);
}

// File Line: 49
// RVA: 0x52C9E0
UFG::ComponentIDDesc *__fastcall UFG::FaceActionComponent::GetDesc(UFG::FaceActionComponent *this)
{
  return &UFG::FaceActionComponent::_TypeIDesc;
}

// File Line: 108
// RVA: 0x516F40
void __fastcall UFG::FaceActionComponent::FaceActionComponent(UFG::FaceActionComponent *this, unsigned int name_uid)
{
  UFG::FaceActionComponent *v2; // rdi
  UFG::qNode<UFG::FaceActionComponent,UFG::FaceActionComponent> *v3; // rbx
  UFG::qNode<UFG::FaceActionComponent,UFG::FaceActionComponent> *v4; // rax
  bool *v5; // rax
  unsigned int *v6; // rcx
  signed __int64 v7; // rdx
  AnimationGroupHandleContainer *v8; // [rsp+60h] [rbp+18h]

  v2 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name_uid);
  v3 = (UFG::qNode<UFG::FaceActionComponent,UFG::FaceActionComponent> *)&v2->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  v2->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::FaceActionComponent::`vftable;
  v2->m_DebugDrawEnabled = 0;
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>(&v2->mTargetingSystemBaseComponent);
  UFG::RebindingComponentHandle<UFG::StimulusReceiverComponent,0>::RebindingComponentHandle<UFG::StimulusReceiverComponent,0>(&v2->mStimulusReceiverComponent);
  *(_QWORD *)&v2->mFrameAITreeFirstEvaluated = 0i64;
  v2->mFrameAITreeLastUpdated = 0;
  *((_BYTE *)v2 + 204) = 8;
  *((_BYTE *)v2 + 205) &= 0xFCu;
  v2->mID = -1;
  *(_QWORD *)&v2->mCurrentFaceAction = 18i64;
  *(_QWORD *)&v2->mFaceActionSetup = 0i64;
  v2->mMinigameSpeed = 80;
  v2->mMinigameTargetSize = 30;
  *(_DWORD *)&v2->mMinigameSetup = 0x1000000;
  v2->mCurrentIcon = 11;
  *(_WORD *)&v2->mPipEffectVisible = 0;
  *(_QWORD *)&v2->mItemPrice = 0i64;
  v2->mItemIcon = 0i64;
  v2->mItemVendor = 0;
  v2->mItemProp = UFG::gNullQSymbol;
  v2->mLastPlayedConversationResult = 0;
  v2->mConversationState = 3;
  UFG::qString::qString(&v2->mAutoCompleteObjective);
  v2->mScriptCommandDebugText = 0i64;
  v2->mNumScriptCommandDebugTexts = 0;
  v8 = &v2->mAnimationGroupHandleContainer;
  v8->m_AnimationGroupHandleList.mNode.mPrev = &v8->m_AnimationGroupHandleList.mNode;
  v8->m_AnimationGroupHandleList.mNode.mNext = &v8->m_AnimationGroupHandleList.mNode;
  v2->mAnimationGroupHandleContainer.m_bHasBeenBound = 0;
  *(_QWORD *)&v2->mSocialEffectHash = -1i64;
  v2->mEffectOverride.m_pPointer = 0i64;
  v2->mMinigameTimeWarpFactor = 0.1;
  v2->mMinigameMotionDilation = 0.5;
  *((_BYTE *)v2 + 812) = *((_BYTE *)v2 + 812) & 0xE5 | 5;
  v2->mMiniGameResult = 0;
  UFG::MeshResourceLoader::MeshResourceLoader(&v2->mPropMeshLoader);
  v4 = UFG::FaceActionComponent::s_FaceActionComponentList.mNode.mPrev;
  UFG::FaceActionComponent::s_FaceActionComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::FaceActionComponent,UFG::FaceActionComponent> *)&v2->mPrev;
  v3->mPrev = v4;
  v2->mNext = (UFG::qNode<UFG::FaceActionComponent,UFG::FaceActionComponent> *)&UFG::FaceActionComponent::s_FaceActionComponentList;
  UFG::FaceActionComponent::s_FaceActionComponentList.mNode.mPrev = (UFG::qNode<UFG::FaceActionComponent,UFG::FaceActionComponent> *)&v2->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v2->vfptr,
    UFG::FaceActionComponent::_FaceActionComponentTypeUID,
    "FaceActionComponent");
  v5 = v2->mbShouldConversationReset;
  v6 = v2->mPostInteractionConversationReference;
  v7 = 8i64;
  do
  {
    *(v5 - 8) = 0;
    *v5 = 0;
    *(v6 - 8) = 0;
    *v6 = 0;
    ++v6;
    ++v5;
    --v7;
  }
  while ( v7 );
  v2->mbShouldConversationReset[2] = 1;
  v2->mbShouldConversationReset[5] = 1;
  v2->mbShouldConversationReset[7] = 1;
  v2->mbShouldInteractionExit[1] = 1;
  *(_WORD *)&v2->mbShouldInteractionExit[3] = 257;
  v2->mbShouldInteractionExit[6] = 1;
  v2->mSocalIconMaxSizeDist = 50.0;
  v2->mSocalIconMinSizeDist = 10.0;
  v2->mSocalIconScalarMultiplier = 10.0;
  UFG::qStringCopy(v2->mItemName, 0x7FFFFFFF, &customWorldMapCaption, -1);
  UFG::qStringCopy(v2->mItemCaption, 0x7FFFFFFF, &customWorldMapCaption, -1);
  UFG::qStringCopy(v2->mItemDescription, 0x7FFFFFFF, &customWorldMapCaption, -1);
  UFG::FaceActionComponent::SetInitialState(v2);
}

// File Line: 143
// RVA: 0x51B520
void __fastcall UFG::FaceActionComponent::~FaceActionComponent(UFG::FaceActionComponent *this)
{
  UFG::FaceActionComponent *v1; // rdi
  UFG::qNode<UFG::FaceActionComponent,UFG::FaceActionComponent> *v2; // rsi
  UFG::qNode<UFG::FaceActionComponent,UFG::FaceActionComponent> *v3; // rcx
  UFG::qNode<UFG::FaceActionComponent,UFG::FaceActionComponent> *v4; // rax
  Render::FXOverride *v5; // rax
  Render::FXOverride *v6; // rbx
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *v7; // rcx
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *v8; // rax
  UFG::qNode<UFG::FaceActionComponent,UFG::FaceActionComponent> *v9; // rcx
  UFG::qNode<UFG::FaceActionComponent,UFG::FaceActionComponent> *v10; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::FaceActionComponent::`vftable;
  if ( this->mAnimationGroupHandleContainer.m_bHasBeenBound )
    AnimationGroupHandleContainer::Unbind(&this->mAnimationGroupHandleContainer);
  UFG::FaceActionComponent::ResetState(v1);
  if ( v1 == UFG::FaceActionComponent::s_FaceActionComponentpCurrentIterator )
    UFG::FaceActionComponent::s_FaceActionComponentpCurrentIterator = (UFG::FaceActionComponent *)&v1->mPrev[-4];
  v2 = (UFG::qNode<UFG::FaceActionComponent,UFG::FaceActionComponent> *)&v1->mPrev;
  v3 = v1->mPrev;
  v4 = v1->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::MeshResourceLoader::~MeshResourceLoader(&v1->mPropMeshLoader);
  v5 = v1->mEffectOverride.m_pPointer;
  if ( v5 )
  {
    --v5->mReferenceCount;
    v6 = v1->mEffectOverride.m_pPointer;
    if ( v6->mReferenceCount <= 0 )
    {
      if ( v6 )
      {
        Render::FXOverride::~FXOverride(v1->mEffectOverride.m_pPointer);
        operator delete[](v6);
      }
      v1->mEffectOverride.m_pPointer = 0i64;
    }
  }
  UFG::qList<AnimationGroupHandle,AnimationGroupHandleContainer,1,0>::DeleteNodes(&v1->mAnimationGroupHandleContainer.m_AnimationGroupHandleList);
  UFG::qList<AnimationGroupHandle,AnimationGroupHandleContainer,1,0>::DeleteNodes(&v1->mAnimationGroupHandleContainer.m_AnimationGroupHandleList);
  v7 = v1->mAnimationGroupHandleContainer.m_AnimationGroupHandleList.mNode.mPrev;
  v8 = v1->mAnimationGroupHandleContainer.m_AnimationGroupHandleList.mNode.mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  v1->mAnimationGroupHandleContainer.m_AnimationGroupHandleList.mNode.mPrev = &v1->mAnimationGroupHandleContainer.m_AnimationGroupHandleList.mNode;
  v1->mAnimationGroupHandleContainer.m_AnimationGroupHandleList.mNode.mNext = &v1->mAnimationGroupHandleContainer.m_AnimationGroupHandleList.mNode;
  UFG::qString::~qString(&v1->mAutoCompleteObjective);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->mStimulusReceiverComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->mTargetingSystemBaseComponent);
  v9 = v2->mPrev;
  v10 = v1->mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  v2->mPrev = v2;
  v1->mNext = (UFG::qNode<UFG::FaceActionComponent,UFG::FaceActionComponent> *)&v1->mPrev;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 166
// RVA: 0x54A7A0
void __fastcall UFG::FaceActionComponent::ResetState(UFG::FaceActionComponent *this)
{
  UFG::FaceActionComponent *v1; // rbx
  bool v2; // al
  char v3; // al

  v1 = this;
  UFG::FaceActionComponent::KillEffect(this);
  if ( v1->mFaceActionEnabled == 1 )
    UFG::FaceActionComponent::KillEffect(v1);
  v1->mCurrentFaceAction = 18;
  v1->mMininumRequirement = 0;
  *(_DWORD *)&v1->mMinigameSetup = 0x1000000;
  v1->mCurrentIcon = 11;
  v1->mPipEffectVisible = 0;
  *(_WORD *)&v1->mFaceActionSetup = 0;
  v1->mMinigameSpeed = 125;
  v1->mMinigameTargetSize = 30;
  UFG::qStringCopy(v1->mItemCaption, 0x7FFFFFFF, &customWorldMapCaption, -1);
  v1->mItemPrice = 0;
  v1->mItemIcon = 0i64;
  v1->mItemVendor = 0;
  v1->mItemProp = UFG::gNullQSymbol;
  v1->mScriptCommandDebugText = 0i64;
  v1->mNumScriptCommandDebugTexts = 0;
  v1->mConversationState = 0;
  v1->mLastPlayedConversationResult = 0;
  v1->mMiniGameResult = 0;
  UFG::qString::Set(&v1->mAutoCompleteObjective, &customWorldMapCaption);
  v2 = UFG::UIHKSocialActionManager::SocialAction.mStartGame;
  if ( UFG::UIHKSocialActionManager::mThis )
    v2 = 0;
  UFG::UIHKSocialActionManager::SocialAction.mStartGame = v2;
  UFG::FaceActionComponent::SetInitialState(v1);
  v3 = *((_BYTE *)v1 + 204);
  *((_BYTE *)v1 + 812) &= 0xF5u;
  *((_BYTE *)v1 + 205) &= 0xFCu;
  v1->mConfirmationBoxText = 0i64;
  v1->mbForceIconOn = 0;
  *((_BYTE *)v1 + 204) = v3 & 0xE8 | 8;
}

// File Line: 223
// RVA: 0x53DB20
void __fastcall UFG::FaceActionComponent::OnAttach(UFG::FaceActionComponent *this, UFG::SimObject *pObject)
{
  UFG::FaceActionComponent *v2; // rsi
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0> *v3; // rcx
  UFG::AIActionTreeComponent *v4; // rbx
  UFG::SimObject *v5; // rdi
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rax
  UFG::RebindingComponentHandle<UFG::StimulusReceiverComponent,0> *v10; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v12; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v14; // rax
  UFG::SimObject *v15; // rcx
  unsigned __int16 v16; // dx
  unsigned int v17; // er8
  unsigned int v18; // er9
  signed __int64 v19; // rdx
  unsigned int v20; // er8
  unsigned int v21; // er9

  v2 = this;
  v3 = &this->mTargetingSystemBaseComponent;
  v4 = 0i64;
  v5 = pObject;
  if ( v3->m_pSimComponent )
  {
    v6 = v3->mPrev;
    v7 = v3->mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    v3->m_pSimComponent = 0i64;
LABEL_7:
    v3->m_pSimObject = 0i64;
    v3->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->mPrev;
    v3->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->mPrev;
    goto LABEL_8;
  }
  if ( v3->m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0> *)v3->mPrev != v3
     || (UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0> *)v3->mNext != v3) )
  {
    v8 = v3->mPrev;
    v9 = v3->mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    goto LABEL_7;
  }
LABEL_8:
  v3->m_Changed = 1;
  v3->m_pSimObject = v5;
  v3->m_TypeUID = UFG::TargetingSystemBaseComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>::BindInternal<UFG::SimObject>(v3, v5);
  v10 = &v2->mStimulusReceiverComponent;
  if ( v2->mStimulusReceiverComponent.m_pSimComponent )
  {
    v11 = v10->mPrev;
    v12 = v2->mStimulusReceiverComponent.mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    v2->mStimulusReceiverComponent.m_pSimComponent = 0i64;
LABEL_14:
    v2->mStimulusReceiverComponent.m_pSimObject = 0i64;
    v2->mStimulusReceiverComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->mStimulusReceiverComponent.mPrev;
    v10->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v10->mPrev;
    goto LABEL_15;
  }
  if ( v2->mStimulusReceiverComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::StimulusReceiverComponent,0> *)v10->mPrev != v10
     || (UFG::RebindingComponentHandle<UFG::StimulusReceiverComponent,0> *)v2->mStimulusReceiverComponent.mNext != &v2->mStimulusReceiverComponent) )
  {
    v13 = v10->mPrev;
    v14 = v2->mStimulusReceiverComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    goto LABEL_14;
  }
LABEL_15:
  v2->mStimulusReceiverComponent.m_Changed = 1;
  v2->mStimulusReceiverComponent.m_pSimObject = v5;
  v2->mStimulusReceiverComponent.m_TypeUID = UFG::StimulusReceiverComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::StimulusReceiverComponent,0>::BindInternal<UFG::SimObject>(
    &v2->mStimulusReceiverComponent,
    v5);
  v15 = v2->m_pSimObject;
  if ( v15 )
  {
    v16 = v15->m_Flags;
    if ( (v16 >> 14) & 1 || (v16 & 0x8000u) != 0 )
    {
      v4 = (UFG::AIActionTreeComponent *)v15->m_Components.p[19].m_pComponent;
    }
    else if ( (v16 >> 13) & 1 )
    {
      v17 = (unsigned int)v15[1].vfptr;
      v18 = v15->m_Components.size;
      if ( v17 < v18 )
      {
        v19 = (signed __int64)&v15->m_Components.p[v17];
        while ( (*(_DWORD *)(v19 + 8) & 0xFE000000) != (UFG::AIActionTreeComponent::_TypeUID & 0xFE000000)
             || UFG::AIActionTreeComponent::_TypeUID & ~*(_DWORD *)(v19 + 8) & 0x1FFFFFF )
        {
          ++v17;
          v19 += 16i64;
          if ( v17 >= v18 )
            goto LABEL_35;
        }
LABEL_26:
        v4 = *(UFG::AIActionTreeComponent **)v19;
        goto LABEL_35;
      }
    }
    else
    {
      if ( !((v16 >> 12) & 1) )
      {
        v4 = (UFG::AIActionTreeComponent *)UFG::SimObject::GetComponentOfType(v15, UFG::AIActionTreeComponent::_TypeUID);
        goto LABEL_35;
      }
      v20 = (unsigned int)v15[1].vfptr;
      v21 = v15->m_Components.size;
      if ( v20 < v21 )
      {
        v19 = (signed __int64)&v15->m_Components.p[v20];
        while ( (*(_DWORD *)(v19 + 8) & 0xFE000000) != (UFG::AIActionTreeComponent::_TypeUID & 0xFE000000)
             || UFG::AIActionTreeComponent::_TypeUID & ~*(_DWORD *)(v19 + 8) & 0x1FFFFFF )
        {
          ++v20;
          v19 += 16i64;
          if ( v20 >= v21 )
            goto LABEL_35;
        }
        goto LABEL_26;
      }
    }
  }
LABEL_35:
  UFG::AIActionTreeComponent::EnsureTicketBoothCriticalPriority(v4);
  UFG::FaceActionComponent::SetInitialState(v2);
}

// File Line: 278
// RVA: 0x5423D0
char __fastcall UFG::FaceActionComponent::OpenConfirmationDialog(UFG::FaceActionComponent *this)
{
  UFG::FaceActionComponent *v1; // rdi
  UFG::UIHKScreenGlobalOverlay *v2; // rax
  UFG::UIScreen *v3; // rbx
  const char *v4; // r8

  *((_BYTE *)this + 204) &= 0xFDu;
  v1 = this;
  v2 = UFG::UIHKScreenGlobalOverlay::getInstance();
  v3 = (UFG::UIScreen *)&v2->vfptr;
  if ( !v2 || v2->m_skookum_dialog_active )
    return 0;
  UFG::UIHKScreenGlobalOverlay::StartSkookumDialog(v2);
  v4 = "Are you sure?";
  if ( v1->mConfirmationBoxText )
    v4 = v1->mConfirmationBoxText;
  UFG::UIScreenDialogBox::createYesNoDialog(v3, "Social Confirmation Dialog", v4, 0, 0);
  return 1;
}

// File Line: 298
// RVA: 0x539F90
char __fastcall UFG::FaceActionComponent::IsConfirmationDialogComplete(UFG::FaceActionComponent *this)
{
  UFG::FaceActionComponent *v1; // rdi
  UFG::UIHKScreenGlobalOverlay *v2; // rax
  unsigned int v3; // ebx

  v1 = this;
  v2 = UFG::UIHKScreenGlobalOverlay::getInstance();
  if ( !v2 || !v2->m_skookum_dialog_active || !v2->m_skookum_dialog_finished )
    return 0;
  v3 = v2->m_skookum_dialog_result;
  UFG::UIHKScreenGlobalOverlay::FinishSkookumDialog(v2);
  *((_BYTE *)v1 + 204) &= 0xFDu;
  *((_BYTE *)v1 + 204) |= 2 * (v3 == UI_HASH_DIALOG_YES_25);
  return 1;
}

// File Line: 314
// RVA: 0x52E060
char *__fastcall UFG::FaceActionComponent::GetItemDescription(UFG::FaceActionComponent *this)
{
  UFG::FaceActionComponent *v1; // rdi
  UFG::SimObject *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rbx
  unsigned int v5; // edx
  unsigned int v6; // er8
  signed __int64 v7; // rbx
  unsigned int v8; // edx
  unsigned int v9; // er8
  unsigned int v10; // edx
  unsigned int v11; // er8
  __int64 v12; // rax
  int v13; // eax
  char *result; // rax

  v1 = this;
  v2 = this->m_pSimObject;
  if ( !v2 )
    return 0i64;
  v3 = v2->m_Flags;
  if ( !((v3 >> 14) & 1) )
  {
    if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
      {
        v8 = (unsigned int)v2[1].vfptr;
        v9 = v2->m_Components.size;
        if ( v8 < v9 )
        {
          v7 = (signed __int64)&v2->m_Components.p[v8];
          while ( (*(_DWORD *)(v7 + 8) & 0xFE000000) != (UFG::InventoryComponent::_TypeUID & 0xFE000000)
               || UFG::InventoryComponent::_TypeUID & ~*(_DWORD *)(v7 + 8) & 0x1FFFFFF )
          {
            ++v8;
            v7 += 16i64;
            if ( v8 >= v9 )
            {
              v4 = 0i64;
              goto LABEL_27;
            }
          }
          goto LABEL_11;
        }
      }
      else
      {
        if ( !((v3 >> 12) & 1) )
        {
          v4 = UFG::SimObject::GetComponentOfType(v2, UFG::InventoryComponent::_TypeUID);
          goto LABEL_27;
        }
        v10 = (unsigned int)v2[1].vfptr;
        v11 = v2->m_Components.size;
        if ( v10 < v11 )
        {
          v7 = (signed __int64)&v2->m_Components.p[v10];
          while ( (*(_DWORD *)(v7 + 8) & 0xFE000000) != (UFG::InventoryComponent::_TypeUID & 0xFE000000)
               || UFG::InventoryComponent::_TypeUID & ~*(_DWORD *)(v7 + 8) & 0x1FFFFFF )
          {
            ++v10;
            v7 += 16i64;
            if ( v10 >= v11 )
            {
              v4 = 0i64;
              goto LABEL_27;
            }
          }
          goto LABEL_11;
        }
      }
    }
    else
    {
      v5 = (unsigned int)v2[1].vfptr;
      v6 = v2->m_Components.size;
      if ( v5 < v6 )
      {
        v7 = (signed __int64)&v2->m_Components.p[v5];
        while ( (*(_DWORD *)(v7 + 8) & 0xFE000000) != (UFG::InventoryComponent::_TypeUID & 0xFE000000)
             || UFG::InventoryComponent::_TypeUID & ~*(_DWORD *)(v7 + 8) & 0x1FFFFFF )
        {
          ++v5;
          v7 += 16i64;
          if ( v5 >= v6 )
            goto LABEL_10;
        }
LABEL_11:
        v4 = *(UFG::SimComponent **)v7;
        goto LABEL_27;
      }
    }
LABEL_10:
    v4 = 0i64;
    goto LABEL_27;
  }
  v4 = v2->m_Components.p[39].m_pComponent;
LABEL_27:
  if ( !v4 )
    return 0i64;
  v12 = *(signed int *)&v4[14].m_Flags;
  if ( !(_DWORD)v12 )
    return 0i64;
  v13 = UFG::PlayerBuffTracker::GetBuffLevel(UFG::ItemProfiles::mpInstance->mProfiles[v12].mDescriptionBuff);
  if ( v13 == -1 )
    result = v1->mItemDescription;
  else
    result = (char *)UFG::ItemProfiles::GetDescription((UFG::eInventoryItemEnum)*(_DWORD *)&v4[14].m_Flags, v13);
  return result;
}

// File Line: 338
// RVA: 0x542EA0
void __fastcall UFG::FaceActionComponent::ProcessIconLogic(UFG::FaceActionComponent *this)
{
  UFG::FaceActionComponent *v1; // rbx
  const char *v2; // rcx
  bool v3; // si
  bool v4; // di
  bool v5; // al
  const char *v6; // r8
  UFG::eFaceActionEnum v7; // eax
  UFG::SimObject *v8; // rcx
  unsigned __int16 v9; // dx
  int v10; // esi
  UFG::InventoryComponent *v11; // rdi
  unsigned int v12; // edx
  unsigned int v13; // er8
  signed __int64 v14; // rdi
  unsigned int v15; // edx
  unsigned int v16; // er8
  unsigned int v17; // edx
  unsigned int v18; // er8
  UFG::eInventoryItemEnum v19; // eax
  const char *v20; // rax
  const char *v21; // rax
  const char *v22; // rax
  __int64 v23; // rax
  signed int v24; // eax
  UFG::qSymbol result; // [rsp+30h] [rbp+8h]

  v1 = this;
  v2 = this->mItemIcon;
  if ( v2 )
  {
    v3 = (unsigned int)UFG::qStringCompareInsensitive(v2, "boat", -1) == 0;
    v4 = (unsigned int)UFG::qStringCompareInsensitive(v1->mItemIcon, "vehicle", -1) == 0;
    v5 = (unsigned int)UFG::qStringCompareInsensitive(v1->mItemIcon, "clothing", -1) == 0;
    if ( v3 || v4 || v5 )
    {
      UFG::qStringCopy(v1->mItemName, 0x7FFFFFFF, &customWorldMapCaption, -1);
      if ( v3 || v4 )
      {
        v6 = "$SOCIAL_PARKING_ATTENDANT";
        if ( v1->mCurrentFaceAction != 7 )
          v6 = "$SOCIAL_VEHICLE_VENDOR";
      }
      else
      {
        v6 = "$SOCIAL_PURCHASE_HOLD";
      }
      UFG::qStringCopy(v1->mItemCaption, 0x7FFFFFFF, v6, -1);
      *((_BYTE *)v1 + 204) &= 0xDFu;
    }
  }
  v7 = v1->mCurrentFaceAction;
  switch ( v7 )
  {
    case 6:
      if ( !v1->mItemVendor )
        break;
      v8 = v1->m_pSimObject;
      if ( !v8 )
        break;
      v9 = v8->m_Flags;
      v10 = 0;
      if ( (v9 >> 14) & 1 )
      {
        v11 = (UFG::InventoryComponent *)v8->m_Components.p[39].m_pComponent;
        goto LABEL_39;
      }
      if ( (v9 & 0x8000u) == 0 )
      {
        if ( (v9 >> 13) & 1 )
        {
          v15 = (unsigned int)v8[1].vfptr;
          v16 = v8->m_Components.size;
          if ( v15 < v16 )
          {
            v14 = (signed __int64)&v8->m_Components.p[v15];
            while ( (*(_DWORD *)(v14 + 8) & 0xFE000000) != (UFG::InventoryComponent::_TypeUID & 0xFE000000)
                 || UFG::InventoryComponent::_TypeUID & ~*(_DWORD *)(v14 + 8) & 0x1FFFFFF )
            {
              ++v15;
              v14 += 16i64;
              if ( v15 >= v16 )
              {
                v11 = 0i64;
                goto LABEL_39;
              }
            }
            goto LABEL_23;
          }
        }
        else
        {
          if ( !((v9 >> 12) & 1) )
          {
            v11 = (UFG::InventoryComponent *)UFG::SimObject::GetComponentOfType(v8, UFG::InventoryComponent::_TypeUID);
LABEL_39:
            if ( v11 )
            {
              UFG::FaceActionComponent::SetIcon(v1, v11->m_SellableItem);
              v19 = v11->m_SellableItem;
              if ( (unsigned int)(v1->mInventoryItem - 163) > 0x13 )
              {
                if ( v19 )
                  v10 = UFG::ItemProfiles::mpInstance->mProfiles[v11->m_SellableItem].mCost;
                v10 = (signed int)UFG::StoreFrontTracker::GetItemPriceBasedOnClothes((float)v10);
              }
              else if ( v19 )
              {
                v10 = UFG::ItemProfiles::mpInstance->mProfiles[v11->m_SellableItem].mCost;
              }
              v1->mItemPrice = v10;
              v20 = UFG::ItemProfiles::GetCaptioning(v11->m_SellableItem);
              UFG::qStringCopy(v1->mItemCaption, 0x7FFFFFFF, v20, -1);
              v21 = UFG::ItemProfiles::GetName(v11->m_SellableItem);
              UFG::qStringCopy(v1->mItemName, 0x7FFFFFFF, v21, -1);
              v22 = UFG::ItemProfiles::GetDescription(v11->m_SellableItem, 0);
              UFG::qStringCopy(v1->mItemDescription, 0x7FFFFFFF, v22, -1);
              v23 = v1->mInventoryItem;
              if ( v11->m_InfiniteSellableItem && (_DWORD)v23 == v11->m_SellableItem )
                v24 = 1;
              else
                v24 = v11->m_InventoryItems[v23].m_iQuantity;
              v1->mItemQuantity = v24;
              v1->mItemProp = (UFG::qSymbol)UFG::InventoryComponent::GetSellableItemProp(v11, &result)->mUID;
            }
            break;
          }
          v17 = (unsigned int)v8[1].vfptr;
          v18 = v8->m_Components.size;
          if ( v17 < v18 )
          {
            v14 = (signed __int64)&v8->m_Components.p[v17];
            while ( (*(_DWORD *)(v14 + 8) & 0xFE000000) != (UFG::InventoryComponent::_TypeUID & 0xFE000000)
                 || UFG::InventoryComponent::_TypeUID & ~*(_DWORD *)(v14 + 8) & 0x1FFFFFF )
            {
              ++v17;
              v14 += 16i64;
              if ( v17 >= v18 )
              {
                v11 = 0i64;
                goto LABEL_39;
              }
            }
            goto LABEL_23;
          }
        }
      }
      else
      {
        v12 = (unsigned int)v8[1].vfptr;
        v13 = v8->m_Components.size;
        if ( v12 < v13 )
        {
          v14 = (signed __int64)&v8->m_Components.p[v12];
          while ( (*(_DWORD *)(v14 + 8) & 0xFE000000) != (UFG::InventoryComponent::_TypeUID & 0xFE000000)
               || UFG::InventoryComponent::_TypeUID & ~*(_DWORD *)(v14 + 8) & 0x1FFFFFF )
          {
            ++v12;
            v14 += 16i64;
            if ( v12 >= v13 )
              goto LABEL_22;
          }
LABEL_23:
          v11 = *(UFG::InventoryComponent **)v14;
          goto LABEL_39;
        }
      }
LABEL_22:
      v11 = 0i64;
      goto LABEL_39;
    case 14:
      v1->mItemIcon = "ally";
      *(_QWORD *)v1->mItemCaption = *(_QWORD *)aEfaceac_1;
      *(_QWORD *)&v1->mItemCaption[8] = 4851297499246184788i64;
      *(_DWORD *)&v1->mItemCaption[16] = 5526095;
      break;
    case 15:
      v1->mItemIcon = "intimidate";
      *(_QWORD *)v1->mItemCaption = *(_QWORD *)aEfaceac;
      *(_QWORD *)&v1->mItemCaption[8] = 5136714225142417748i64;
      *(_QWORD *)&v1->mItemCaption[16] = 18671134499099720i64;
      break;
    case 16:
      v1->mItemIcon = "harass";
      *(_QWORD *)v1->mItemCaption = *(_QWORD *)aEfaceac_0;
      *(_QWORD *)&v1->mItemCaption[8] = 6509181813537065300i64;
      *(_QWORD *)&v1->mItemCaption[16] = 4995703963699529050i64;
      *(_DWORD *)&v1->mItemCaption[24] = 1413693778;
      v1->mItemCaption[28] = 0;
      break;
    case 10:
      v1->mItemIcon = "harass";
      *(_QWORD *)v1->mItemCaption = *(_QWORD *)aSocial_5;
      *(_DWORD *)&v1->mItemCaption[8] = 1095909704;
      *(_WORD *)&v1->mItemCaption[12] = 21331;
      v1->mItemCaption[14] = 0;
      break;
    default:
      if ( v7 )
      {
        switch ( v7 )
        {
          case 2:
          case 3:
            goto LABEL_81;
          case 4:
            v1->mItemIcon = "help";
            *(_QWORD *)v1->mItemCaption = *(_QWORD *)aSocial_9;
            *(_QWORD *)&v1->mItemCaption[8] = 6868628618592666948i64;
            *(_QWORD *)&v1->mItemCaption[16] = 19500119154180432i64;
            goto LABEL_78;
          case 11:
            v1->mItemIcon = "invite";
            *(_QWORD *)v1->mItemCaption = *(_QWORD *)aSocial_1;
            *(_DWORD *)&v1->mItemCaption[8] = 1380535366;
            *(_WORD *)&v1->mItemCaption[12] = 84;
            goto LABEL_78;
          case 12:
            v1->mItemIcon = "kiss";
            *(_QWORD *)v1->mItemCaption = *(_QWORD *)aSocial_3;
            *(_DWORD *)&v1->mItemCaption[8] = 1397967179;
            v1->mItemCaption[12] = 0;
            goto LABEL_78;
          case 1:
LABEL_81:
            v1->mItemIcon = "help";
            *(_QWORD *)v1->mItemCaption = *(_QWORD *)aSocial_10;
            *(_QWORD *)&v1->mItemCaption[8] = 4992344993894385231i64;
            *(_WORD *)&v1->mItemCaption[16] = 20556;
            v1->mItemCaption[18] = 0;
            goto LABEL_78;
          case 8:
            v1->mItemIcon = "ally";
            *(_QWORD *)v1->mItemCaption = *(_QWORD *)aSocial_4;
            *(_DWORD *)&v1->mItemCaption[8] = 1498172481;
            v1->mItemCaption[12] = 0;
            break;
          case 13:
            v1->mItemIcon = "flirt";
            *(_QWORD *)v1->mItemCaption = *(_QWORD *)aSocial_6;
            *(_DWORD *)&v1->mItemCaption[8] = 1230392905;
            *(_WORD *)&v1->mItemCaption[12] = 17748;
            v1->mItemCaption[14] = 0;
            break;
          case 5:
          case 9:
            v1->mItemIcon = "informant";
            *(_QWORD *)v1->mItemCaption = *(_QWORD *)aSocial_7;
            *(_QWORD *)&v1->mItemCaption[8] = 5638873224357236297i64;
            *(_WORD *)&v1->mItemCaption[16] = 84;
            break;
        }
      }
      else
      {
        v1->mItemIcon = "charm";
        *(_QWORD *)v1->mItemCaption = *(_QWORD *)aSocial_8;
        *(_DWORD *)&v1->mItemCaption[8] = 1380010051;
        *(_WORD *)&v1->mItemCaption[12] = 77;
      }
      break;
  }
LABEL_78:
  UFG::FaceActionComponent::ProcessPreGreetIconLogic(v1, 1);
}

// File Line: 467
// RVA: 0x53C610
void __fastcall UFG::FaceActionComponent::KillEffect(UFG::FaceActionComponent *this)
{
  UFG::FaceActionComponent *v1; // rdi
  UFG::SimObject *v2; // rcx
  Render::FXSimComponent *v3; // rax
  unsigned __int16 v4; // dx
  unsigned int v5; // er8
  unsigned int v6; // er9
  signed __int64 v7; // rdx
  unsigned int v8; // er8
  unsigned int v9; // er9
  unsigned int v10; // er8
  unsigned int v11; // er9
  unsigned int v12; // er8
  unsigned int v13; // er9
  Render::FXOverride *v14; // rax
  Render::FXOverride *v15; // rbx

  v1 = this;
  if ( this->mEffectHandle == -1 )
    return;
  v2 = this->m_pSimObject;
  if ( !v2 )
    goto LABEL_3;
  v4 = v2->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    v5 = (unsigned int)v2[1].vfptr;
    v6 = v2->m_Components.size;
    if ( v5 < v6 )
    {
      v7 = (signed __int64)&v2->m_Components.p[v5];
      while ( (*(_DWORD *)(v7 + 8) & 0xFE000000) != (Render::FXSimComponent::_TypeUID & 0xFE000000)
           || Render::FXSimComponent::_TypeUID & ~*(_DWORD *)(v7 + 8) & 0x1FFFFFF )
      {
        ++v5;
        v7 += 16i64;
        if ( v5 >= v6 )
        {
          v3 = 0i64;
          goto LABEL_34;
        }
      }
LABEL_11:
      v3 = *(Render::FXSimComponent **)v7;
      goto LABEL_34;
    }
    goto LABEL_3;
  }
  if ( (v4 & 0x8000u) != 0 )
  {
    v8 = (unsigned int)v2[1].vfptr;
    v9 = v2->m_Components.size;
    if ( v8 < v9 )
    {
      v7 = (signed __int64)&v2->m_Components.p[v8];
      while ( (*(_DWORD *)(v7 + 8) & 0xFE000000) != (Render::FXSimComponent::_TypeUID & 0xFE000000)
           || Render::FXSimComponent::_TypeUID & ~*(_DWORD *)(v7 + 8) & 0x1FFFFFF )
      {
        ++v8;
        v7 += 16i64;
        if ( v8 >= v9 )
        {
          v3 = 0i64;
          goto LABEL_34;
        }
      }
      goto LABEL_11;
    }
LABEL_3:
    v3 = 0i64;
    goto LABEL_34;
  }
  if ( (v4 >> 13) & 1 )
  {
    v10 = (unsigned int)v2[1].vfptr;
    v11 = v2->m_Components.size;
    if ( v10 < v11 )
    {
      v7 = (signed __int64)&v2->m_Components.p[v10];
      while ( (*(_DWORD *)(v7 + 8) & 0xFE000000) != (Render::FXSimComponent::_TypeUID & 0xFE000000)
           || Render::FXSimComponent::_TypeUID & ~*(_DWORD *)(v7 + 8) & 0x1FFFFFF )
      {
        ++v10;
        v7 += 16i64;
        if ( v10 >= v11 )
        {
          v3 = 0i64;
          goto LABEL_34;
        }
      }
      goto LABEL_11;
    }
    goto LABEL_3;
  }
  if ( (v4 >> 12) & 1 )
  {
    v12 = (unsigned int)v2[1].vfptr;
    v13 = v2->m_Components.size;
    if ( v12 < v13 )
    {
      v7 = (signed __int64)&v2->m_Components.p[v12];
      while ( (*(_DWORD *)(v7 + 8) & 0xFE000000) != (Render::FXSimComponent::_TypeUID & 0xFE000000)
           || Render::FXSimComponent::_TypeUID & ~*(_DWORD *)(v7 + 8) & 0x1FFFFFF )
      {
        ++v12;
        v7 += 16i64;
        if ( v12 >= v13 )
        {
          v3 = 0i64;
          goto LABEL_34;
        }
      }
      goto LABEL_11;
    }
    goto LABEL_3;
  }
  v3 = (Render::FXSimComponent *)UFG::SimObject::GetComponentOfType(v2, Render::FXSimComponent::_TypeUID);
LABEL_34:
  Render::FXSimComponent::DetachEffect(v3, v1->mEffectHandle, FXKILLOPTION_ERASE_EMITTED_OBJECTS);
  v1->mEffectHandle = -1;
  v14 = v1->mEffectOverride.m_pPointer;
  if ( v14 )
  {
    --v14->mReferenceCount;
    v15 = v1->mEffectOverride.m_pPointer;
    if ( v15->mReferenceCount <= 0 )
    {
      if ( v15 )
      {
        Render::FXOverride::~FXOverride(v1->mEffectOverride.m_pPointer);
        operator delete[](v15);
      }
      v1->mEffectOverride.m_pPointer = 0i64;
    }
    v1->mEffectOverride.m_pPointer = 0i64;
  }
}

// File Line: 480
// RVA: 0x5435B0
void __fastcall UFG::FaceActionComponent::ProcessPreGreetIconLogic(UFG::FaceActionComponent *this, bool bTakeNISIntoConsideration)
{
  bool v2; // bl
  UFG::FaceActionComponent *v3; // rdi
  char v4; // al
  char v5; // dl
  UFG::eFaceActionState v6; // eax
  UFG::SimObject *v7; // rcx
  unsigned __int16 v8; // dx
  unsigned int v9; // edx
  unsigned int v10; // er9
  UFG::SimComponentHolder *v11; // rbx
  signed __int64 v12; // r8
  Render::FXSimComponent *v13; // rsi
  unsigned int v14; // edx
  unsigned int v15; // er9
  unsigned int v16; // edx
  unsigned int v17; // er9
  unsigned int v18; // edx
  unsigned int v19; // er9
  UFG::SimObject *v20; // r8
  unsigned __int16 v21; // dx
  UFG::CharacterAnimationComponent *v22; // rcx
  UFG::CharacterAnimationComponent *v23; // rax
  unsigned int v24; // edx
  unsigned int v25; // er9
  UFG::SimComponentHolder *v26; // rbx
  Creature *v27; // rcx
  int v28; // ebp
  UFG::allocator::free_link *v29; // rax
  Render::FXOverride *fxOverride; // ST20_8

  v2 = bTakeNISIntoConsideration;
  v3 = this;
  UFG::FaceActionComponent::KillEffect(this);
  if ( !v2 || NISManager::GetInstance()->mState == STATE_INVALID )
  {
    v4 = *((_BYTE *)v3 + 812);
    v5 = v4 & 1;
    if ( (v4 & 1 || v3->mMinigameSetup) && !(*((_BYTE *)v3 + 204) & 8) && !(v4 & 2) )
    {
      *(_QWORD *)v3->mItemCaption = *(_QWORD *)aSocial_2;
      *(_DWORD *)&v3->mItemCaption[8] = 1162170951;
      *(_WORD *)&v3->mItemCaption[12] = 84;
    }
    if ( v3->mbForceIconOn
      || (v6 = v3->mState) == 0 && (v5 || v3->mMinigameSetup)
      || v6 == 4 && !v5 && !v3->mMinigameSetup )
    {
      if ( v3->mSocialEffectHash != -1 && v3->mEffectHandle == -1 )
      {
        if ( !(_S22_0 & 1) )
        {
          _S22_0 |= 1u;
          UFG::qSymbolUC::create_from_string(&symHead, "Bip01 Head");
          atexit(UFG::FaceActionComponent::ProcessPreGreetIconLogic_::_13_::_dynamic_atexit_destructor_for__symHead__);
        }
        v7 = v3->m_pSimObject;
        if ( v7 )
        {
          v8 = v7->m_Flags;
          if ( (v8 >> 14) & 1 )
          {
            v9 = (unsigned int)v7[1].vfptr;
            v10 = v7->m_Components.size;
            if ( v9 < v10 )
            {
              v11 = v7->m_Components.p;
              while ( 1 )
              {
                v12 = v9;
                if ( (v11[v9].m_TypeUID & 0xFE000000) == (Render::FXSimComponent::_TypeUID & 0xFE000000)
                  && !(Render::FXSimComponent::_TypeUID & ~v11[v9].m_TypeUID & 0x1FFFFFF) )
                {
                  break;
                }
                if ( ++v9 >= v10 )
                  goto LABEL_28;
              }
LABEL_27:
              v13 = (Render::FXSimComponent *)v11[v12].m_pComponent;
LABEL_51:
              if ( !v13 )
                return;
              v20 = v3->m_pSimObject;
              if ( !v20 )
                return;
              v21 = v20->m_Flags;
              if ( (v21 >> 14) & 1 )
              {
                v22 = (UFG::CharacterAnimationComponent *)v20->m_Components.p[9].m_pComponent;
                if ( v22
                  && !((UFG::CharacterAnimationComponent::_TypeUID ^ v22->m_TypeUID) & 0xFE000000)
                  && !(UFG::CharacterAnimationComponent::_TypeUID & ~v22->m_TypeUID & 0x1FFFFFF) )
                {
LABEL_75:
                  if ( v22 )
                  {
                    v27 = v22->mCreature;
                    if ( v27 )
                    {
                      if ( v27->mPose.mRigHandle.mData )
                        v28 = Skeleton::GetBoneID(v27->mPose.mRigHandle.mUFGSkeleton, symHead.mUID);
                      else
                        v28 = -1;
                      v29 = Render::FXOverride::CreateOverride("FaceActionComponent", 0i64);
                      FX::SharedPointer<Render::FXOverride>::Set(&v3->mEffectOverride, (Render::FXOverride *)v29);
                      fxOverride = v3->mEffectOverride.m_pPointer;
                      v3->mEffectHandle = Render::FXSimComponent::AttachEffect(v13, v3->mSocialEffectHash, v28, 0i64);
                    }
                  }
                  return;
                }
LABEL_57:
                v22 = 0i64;
                goto LABEL_75;
              }
              if ( (v21 & 0x8000u) != 0 )
              {
                v22 = (UFG::CharacterAnimationComponent *)v20->m_Components.p[9].m_pComponent;
                if ( v22 && !((UFG::CharacterAnimationComponent::_TypeUID ^ v22->m_TypeUID) & 0xFE000000) )
                {
                  if ( UFG::CharacterAnimationComponent::_TypeUID & ~v22->m_TypeUID & 0x1FFFFFF )
                    v22 = 0i64;
                  goto LABEL_75;
                }
                goto LABEL_57;
              }
              if ( (v21 >> 13) & 1 )
              {
                v23 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v3->m_pSimObject);
              }
              else
              {
                if ( (v21 >> 12) & 1 )
                {
                  v24 = (unsigned int)v20[1].vfptr;
                  v25 = v20->m_Components.size;
                  if ( v24 < v25 )
                  {
                    v26 = v20->m_Components.p;
                    while ( (v26[v24].m_TypeUID & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
                         || UFG::CharacterAnimationComponent::_TypeUID & ~v26[v24].m_TypeUID & 0x1FFFFFF )
                    {
                      if ( ++v24 >= v25 )
                        goto LABEL_57;
                    }
                    v22 = (UFG::CharacterAnimationComponent *)v26[v24].m_pComponent;
                    goto LABEL_75;
                  }
                  goto LABEL_57;
                }
                v23 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                            v3->m_pSimObject,
                                                            UFG::CharacterAnimationComponent::_TypeUID);
              }
              v22 = v23;
              goto LABEL_75;
            }
          }
          else if ( (v8 & 0x8000u) == 0 )
          {
            if ( (v8 >> 13) & 1 )
            {
              v16 = (unsigned int)v7[1].vfptr;
              v17 = v7->m_Components.size;
              if ( v16 < v17 )
              {
                v11 = v7->m_Components.p;
                do
                {
                  v12 = v16;
                  if ( (v11[v16].m_TypeUID & 0xFE000000) == (Render::FXSimComponent::_TypeUID & 0xFE000000)
                    && !(Render::FXSimComponent::_TypeUID & ~v11[v16].m_TypeUID & 0x1FFFFFF) )
                  {
                    goto LABEL_27;
                  }
                }
                while ( ++v16 < v17 );
              }
            }
            else
            {
              if ( !((v8 >> 12) & 1) )
              {
                v13 = (Render::FXSimComponent *)UFG::SimObject::GetComponentOfType(v7, Render::FXSimComponent::_TypeUID);
                goto LABEL_51;
              }
              v18 = (unsigned int)v7[1].vfptr;
              v19 = v7->m_Components.size;
              if ( v18 < v19 )
              {
                v11 = v7->m_Components.p;
                do
                {
                  v12 = v18;
                  if ( (v11[v18].m_TypeUID & 0xFE000000) == (Render::FXSimComponent::_TypeUID & 0xFE000000)
                    && !(Render::FXSimComponent::_TypeUID & ~v11[v18].m_TypeUID & 0x1FFFFFF) )
                  {
                    goto LABEL_27;
                  }
                }
                while ( ++v18 < v19 );
              }
            }
          }
          else
          {
            v14 = (unsigned int)v7[1].vfptr;
            v15 = v7->m_Components.size;
            if ( v14 < v15 )
            {
              v11 = v7->m_Components.p;
              do
              {
                v12 = v14;
                if ( (v11[v14].m_TypeUID & 0xFE000000) == (Render::FXSimComponent::_TypeUID & 0xFE000000)
                  && !(Render::FXSimComponent::_TypeUID & ~v11[v14].m_TypeUID & 0x1FFFFFF) )
                {
                  goto LABEL_27;
                }
              }
              while ( ++v14 < v15 );
            }
          }
LABEL_28:
          v13 = 0i64;
          goto LABEL_51;
        }
      }
    }
  }
}

// File Line: 518
// RVA: 0x556B40
void __fastcall UFG::FaceActionComponent::ToggleGreetIcon(UFG::FaceActionComponent *this, bool bEnable)
{
  this->mbForceIconOn = bEnable;
}

// File Line: 523
// RVA: 0x54D6C0
void __fastcall UFG::FaceActionComponent::SetIcon(UFG::FaceActionComponent *this, UFG::eInventoryItemEnum item)
{
  this->mInventoryItem = item;
  switch ( item )
  {
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 26:
      this->mItemIcon = "porkbun";
      break;
    case 27:
    case 83:
      this->mItemIcon = "drink";
      break;
    case 28:
      this->mItemIcon = "massage";
      break;
    case 31:
      this->mItemIcon = "tea";
      break;
    case 34:
    case 36:
    case 41:
    case 42:
    case 43:
    case 52:
    case 57:
      this->mItemIcon = "gun";
      break;
    case 74:
    case 75:
    case 76:
    case 97:
    case 98:
    case 99:
      this->mItemIcon = "realestate";
      break;
    case 80:
    case 81:
    case 82:
      this->mItemIcon = "bribe";
      break;
    case 101:
    case 102:
    case 103:
      this->mItemIcon = "extort";
      break;
    default:
      this->mItemIcon = "purchase";
      break;
  }
}

// File Line: 628
// RVA: 0x540340
void __fastcall UFG::FaceActionComponent::OnDetach(UFG::FaceActionComponent *this)
{
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0> *v1; // r8
  UFG::FaceActionComponent *v2; // rbx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v3; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v4; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::RebindingComponentHandle<UFG::StimulusReceiverComponent,0> *v7; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax

  v1 = &this->mTargetingSystemBaseComponent;
  v2 = this;
  if ( this->mTargetingSystemBaseComponent.m_pSimComponent )
  {
    v3 = v1->mPrev;
    v4 = this->mTargetingSystemBaseComponent.mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    this->mTargetingSystemBaseComponent.m_pSimComponent = 0i64;
LABEL_7:
    v1->m_pSimObject = 0i64;
    v1->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
    v1->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
    goto LABEL_8;
  }
  if ( this->mTargetingSystemBaseComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0> *)v1->mPrev != v1
     || (UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0> *)this->mTargetingSystemBaseComponent.mNext != &this->mTargetingSystemBaseComponent) )
  {
    v5 = v1->mPrev;
    v6 = v1->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    goto LABEL_7;
  }
LABEL_8:
  v7 = &v2->mStimulusReceiverComponent;
  v1->m_Changed = 1;
  if ( v2->mStimulusReceiverComponent.m_pSimComponent )
  {
    v8 = v7->mPrev;
    v9 = v2->mStimulusReceiverComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v2->mStimulusReceiverComponent.m_pSimComponent = 0i64;
LABEL_14:
    v2->mStimulusReceiverComponent.m_pSimObject = 0i64;
    v2->mStimulusReceiverComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->mStimulusReceiverComponent.mPrev;
    v7->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v7->mPrev;
    goto LABEL_15;
  }
  if ( v2->mStimulusReceiverComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::StimulusReceiverComponent,0> *)v7->mPrev != v7
     || (UFG::RebindingComponentHandle<UFG::StimulusReceiverComponent,0> *)v2->mStimulusReceiverComponent.mNext != &v2->mStimulusReceiverComponent) )
  {
    v10 = v7->mPrev;
    v11 = v2->mStimulusReceiverComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    goto LABEL_14;
  }
LABEL_15:
  v2->mStimulusReceiverComponent.m_Changed = 1;
  if ( v2->mAnimationGroupHandleContainer.m_bHasBeenBound )
    AnimationGroupHandleContainer::Unbind(&v2->mAnimationGroupHandleContainer);
  v2->mCurrentIcon = 11;
  UFG::FaceActionComponent::KillEffect(v2);
}

// File Line: 657
// RVA: 0x54F4D0
void __fastcall UFG::FaceActionComponent::SetupSocialForNIS(UFG::FaceActionComponent *this, bool bNISStarting)
{
  UFG::FaceActionComponent *v2; // rbx

  v2 = this;
  if ( bNISStarting )
  {
    if ( this->mEffectHandle != -1 )
      UFG::FaceActionComponent::KillEffect(this);
  }
  else if ( this->mEffectHandle == -1 )
  {
    UFG::FaceActionComponent::ProcessIconLogic(this);
    UFG::FaceActionComponent::ProcessPreGreetIconLogic(v2, 0);
  }
}

// File Line: 669
// RVA: 0x560B50
void __fastcall UFG::FaceActionComponent::UpdateSocialIcon(UFG::FaceActionComponent *this)
{
  UFG::FaceActionComponent *v1; // rbx
  char v2; // al
  UFG::SimObject *v3; // rsi
  UFG::TransformNodeComponent *v4; // rdi
  UFG::TransformNodeComponent *v5; // rsi
  float v6; // xmm6_4
  __m128 v7; // xmm8
  float v8; // xmm7_4
  float v9; // xmm0_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm3_4
  Render::FXOverride *v13; // rax

  v1 = this;
  if ( !UFG::FaceActionComponent::IsFaceActionEnabled(this) )
    UFG::FaceActionComponent::KillEffect(v1);
  if ( NISManager::GetInstance()->mState )
    goto LABEL_12;
  v2 = *((_BYTE *)v1 + 812);
  if ( v2 & 1 || v1->mMinigameSetup )
  {
    if ( v2 & 2 )
      goto LABEL_12;
  }
  if ( v1->mEffectHandle == -1 )
  {
    if ( UFG::FaceActionComponent::IsFaceActionEnabled(v1) )
    {
      UFG::FaceActionComponent::ProcessIconLogic(v1);
    }
    else if ( !v1->mbForceIconOn )
    {
      goto LABEL_12;
    }
    UFG::FaceActionComponent::ProcessPreGreetIconLogic(v1, 0);
LABEL_12:
    if ( v1->mEffectHandle == -1 )
      return;
  }
  v3 = v1->m_pSimObject;
  v4 = 0i64;
  if ( v3 )
    v5 = v3->m_pTransformNodeComponent;
  else
    v5 = 0i64;
  if ( LocalPlayer )
    v4 = LocalPlayer->m_pTransformNodeComponent;
  if ( v5 && v4 )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(v5);
    v6 = v5->mWorldTransform.v3.x;
    v7 = (__m128)LODWORD(v5->mWorldTransform.v3.y);
    v8 = v5->mWorldTransform.v3.z;
    UFG::TransformNodeComponent::UpdateWorldTransform(v4);
    v9 = v1->mSocalIconMaxSizeDist;
    v10 = *(float *)&FLOAT_1_0;
    v7.m128_f32[0] = (float)((float)((float)(v7.m128_f32[0] - v4->mWorldTransform.v3.y)
                                   * (float)(v7.m128_f32[0] - v4->mWorldTransform.v3.y))
                           + (float)((float)(v6 - v4->mWorldTransform.v3.x) * (float)(v6 - v4->mWorldTransform.v3.x)))
                   + (float)((float)(v8 - v4->mWorldTransform.v3.z) * (float)(v8 - v4->mWorldTransform.v3.z));
    LODWORD(v11) = (unsigned __int128)_mm_sqrt_ps(v7);
    if ( v11 < v9 )
    {
      v12 = v1->mSocalIconMinSizeDist;
      if ( v11 >= v12 )
        v10 = (float)((float)((float)(v11 - v12) / (float)(v9 - v12)) * (float)(v1->mSocalIconScalarMultiplier - 1.0))
            + 1.0;
    }
    else
    {
      v10 = v1->mSocalIconScalarMultiplier;
    }
    v13 = v1->mEffectOverride.m_pPointer;
    if ( v13 )
      v13->sizeScale = v10;
  }
}

// File Line: 719
// RVA: 0x53C1F0
bool __fastcall UFG::FaceActionComponent::IsTargetStandingSufficient(UFG::FaceActionComponent *this)
{
  UFG::FaceActionComponent *v1; // rdi
  UFG::SimObjectCharacter *v2; // rbx
  signed int v3; // ebx
  UFG::GameStatTracker *v4; // rax

  v1 = this;
  v2 = *(UFG::SimObjectCharacter **)(56i64
                                   * *(unsigned __int8 *)(*(_QWORD *)&this->mTargetingSystemBaseComponent.m_pSimComponent[1].m_Flags
                                                        + 58i64)
                                   + *(_QWORD *)&this->mTargetingSystemBaseComponent.m_pSimComponent[1].m_TypeUID
                                   + 40);
  if ( v2 != UFG::GetLocalPlayer() )
    return 0;
  v3 = v1->mMininumRequirement;
  v4 = UFG::GameStatTracker::Instance();
  return (signed int)UFG::GameStatTracker::GetFaceLevel(v4) >= v3;
}

// File Line: 735
// RVA: 0x52CCD0
signed __int64 __fastcall UFG::FaceActionComponent::GetFaceActionSuccessState(UFG::FaceActionComponent *this)
{
  UFG::eFaceActionState v1; // eax
  signed __int64 result; // rax

  v1 = this->mState;
  if ( (signed int)v1 < 2 )
    return 0i64;
  if ( (signed int)v1 <= 4 )
    return 6 - (unsigned int)((*((_BYTE *)this + 812) & 2) != 0);
  if ( (signed int)v1 > 8 )
    return 0i64;
  if ( *((_BYTE *)this + 812) & 8 )
  {
    result = 1i64;
    if ( this->mMinigameSetup )
      result = 3i64;
  }
  else
  {
    result = 2i64;
    if ( this->mMinigameSetup )
      result = 4i64;
  }
  return result;
}

// File Line: 771
// RVA: 0x54E690
void __fastcall UFG::FaceActionComponent::SetState(UFG::FaceActionComponent *this, UFG::eFaceActionState e)
{
  UFG::eSocialInteractionResultEnum v2; // edi
  UFG::eFaceActionState v3; // esi
  UFG::FaceActionComponent *v4; // rbx
  UFG::eFaceActionState v5; // eax
  bool v6; // al
  int v7; // edi
  unsigned int v8; // ecx
  UFG::AmbientConversation *v9; // rax
  char v10; // al
  UFG::SimObject *v11; // rcx
  unsigned __int16 v12; // dx
  UFG::SimComponent *v13; // rax
  unsigned int v14; // er8
  unsigned int v15; // er9
  signed __int64 v16; // rdx
  unsigned int v17; // er8
  unsigned int v18; // er9
  unsigned int v19; // er8
  unsigned int v20; // er9
  UFG::GameStatTracker *v21; // rax
  signed int v22; // eax
  char v23; // cl
  char v24; // al
  char v25; // al
  signed int v26; // eax
  unsigned int v27; // ecx
  UFG::AmbientConversation *v28; // rax
  signed int v29; // eax
  signed int v30; // eax

  v2 = 1;
  v3 = e;
  v4 = this;
  this->mConversationState = 1;
  if ( e == eFACE_ACTION_STATE_WAITING_FOR_GREET )
  {
    *((_BYTE *)this + 812) &= 0xFDu;
    goto LABEL_99;
  }
  v5 = this->mState;
  if ( v5 == eFACE_ACTION_STATE_WAITING_FOR_GREET && e == 1 )
  {
    v6 = UFG::FaceActionComponent::IsTargetStandingSufficient(this);
    *((_BYTE *)v4 + 812) &= 0xFDu;
    *((_BYTE *)v4 + 812) |= 2 * v6;
    v7 = 6 - ((*((_BYTE *)v4 + 812) & 2) != 0);
    v8 = v4->mConversationReference[v7];
    if ( !v8 || !UFG::ConversationManager::GetConversation(v8) )
    {
      v9 = UFG::FaceActionComponent::GetDefaultConversation(v4, (UFG::eSocialInteractionResultEnum)v7);
      if ( v9 )
        v4->mConversationReference[v7] = v9->mNode.mUID;
    }
    *((_BYTE *)v4 + 205) &= 0xFCu;
    goto LABEL_99;
  }
  if ( v5 == 1 && e == 2 )
  {
    UFG::FaceActionComponent::PlayConversation(
      this,
      (UFG::eSocialInteractionResultEnum)(6 - ((*((_BYTE *)this + 812) & 2) != 0)));
    goto LABEL_99;
  }
  if ( v5 == 2 && e == 3 )
  {
    UFG::FaceActionComponent::StopConversation(
      this,
      (UFG::eSocialInteractionResultEnum)(6 - ((*((_BYTE *)this + 812) & 2) != 0)));
    goto LABEL_99;
  }
  if ( v5 == 3 && e == 4 || v5 == 8 && e == 4 || v5 == eFACE_ACTION_STATE_WAITING_FOR_GREET && e == 4 )
    goto LABEL_24;
  if ( v5 == 4 )
  {
    if ( e == 4 )
    {
LABEL_24:
      if ( this->mMinigameSetup )
        this->mMinigameEnabled = 1;
      *((_BYTE *)this + 812) &= 0xF7u;
      goto LABEL_99;
    }
    if ( e == 5 )
    {
      if ( this->mMinigameSetup )
      {
        v10 = *((_BYTE *)this + 205);
        *((_BYTE *)this + 812) &= 0xF7u;
        this->mMinigameEnabled = 0;
        *((_BYTE *)this + 812) |= 8 * (v10 & 1);
LABEL_65:
        if ( *((_BYTE *)v4 + 812) & 8 )
        {
          v26 = 3;
        }
        else
        {
          v2 = 2;
          v26 = 4;
        }
        if ( v4->mMinigameSetup )
          v2 = v26;
        v27 = v4->mConversationReference[v2];
        if ( !v27 || !UFG::ConversationManager::GetConversation(v27) )
        {
          v28 = UFG::FaceActionComponent::GetDefaultConversation(v4, v2);
          if ( v28 )
            v4->mConversationReference[v2] = v28->mNode.mUID;
        }
        *((_BYTE *)v4 + 205) &= 0xFDu;
        goto LABEL_99;
      }
      if ( this->mCurrentFaceAction != 6 )
      {
        *((_BYTE *)this + 812) |= 8u;
        goto LABEL_65;
      }
      v11 = this->m_pSimObject;
      if ( !v11 )
      {
LABEL_63:
        *((_BYTE *)v4 + 812) &= 0xF7u;
        goto LABEL_65;
      }
      v12 = v11->m_Flags;
      if ( (v12 >> 14) & 1 )
      {
        v13 = v11->m_Components.p[39].m_pComponent;
        goto LABEL_57;
      }
      if ( (v12 & 0x8000u) == 0 )
      {
        if ( (v12 >> 13) & 1 )
        {
          v17 = (unsigned int)v11[1].vfptr;
          v18 = v11->m_Components.size;
          if ( v17 < v18 )
          {
            v16 = (signed __int64)&v11->m_Components.p[v17];
            while ( (*(_DWORD *)(v16 + 8) & 0xFE000000) != (UFG::InventoryComponent::_TypeUID & 0xFE000000)
                 || UFG::InventoryComponent::_TypeUID & ~*(_DWORD *)(v16 + 8) & 0x1FFFFFF )
            {
              ++v17;
              v16 += 16i64;
              if ( v17 >= v18 )
              {
                v13 = 0i64;
                goto LABEL_57;
              }
            }
            goto LABEL_41;
          }
        }
        else
        {
          if ( !((v12 >> 12) & 1) )
          {
            v13 = UFG::SimObject::GetComponentOfType(v11, UFG::InventoryComponent::_TypeUID);
LABEL_57:
            if ( v13 )
            {
              v21 = UFG::GameStatTracker::Instance();
              v22 = UFG::GameStatTracker::GetStat(v21, Money);
              *((_BYTE *)v4 + 812) &= 0xF7u;
              *((_BYTE *)v4 + 812) |= 8 * (v22 >= (signed int)v4->mItemPrice);
              v23 = *((_BYTE *)v4 + 812);
              if ( !(v23 & 8) )
              {
                v24 = *((_BYTE *)v4 + 204);
                if ( v24 & 8 )
                  *((_BYTE *)v4 + 204) = v24 & 0xF7;
              }
              v25 = *((_BYTE *)v4 + 204);
              if ( v25 & 4 )
                *((_BYTE *)v4 + 812) = v23 & (4 * v25 | 0xF7);
              goto LABEL_65;
            }
            goto LABEL_63;
          }
          v19 = (unsigned int)v11[1].vfptr;
          v20 = v11->m_Components.size;
          if ( v19 < v20 )
          {
            v16 = (signed __int64)&v11->m_Components.p[v19];
            while ( (*(_DWORD *)(v16 + 8) & 0xFE000000) != (UFG::InventoryComponent::_TypeUID & 0xFE000000)
                 || UFG::InventoryComponent::_TypeUID & ~*(_DWORD *)(v16 + 8) & 0x1FFFFFF )
            {
              ++v19;
              v16 += 16i64;
              if ( v19 >= v20 )
              {
                v13 = 0i64;
                goto LABEL_57;
              }
            }
            goto LABEL_41;
          }
        }
      }
      else
      {
        v14 = (unsigned int)v11[1].vfptr;
        v15 = v11->m_Components.size;
        if ( v14 < v15 )
        {
          v16 = (signed __int64)&v11->m_Components.p[v14];
          while ( (*(_DWORD *)(v16 + 8) & 0xFE000000) != (UFG::InventoryComponent::_TypeUID & 0xFE000000)
               || UFG::InventoryComponent::_TypeUID & ~*(_DWORD *)(v16 + 8) & 0x1FFFFFF )
          {
            ++v14;
            v16 += 16i64;
            if ( v14 >= v15 )
              goto LABEL_40;
          }
LABEL_41:
          v13 = *(UFG::SimComponent **)v16;
          goto LABEL_57;
        }
      }
LABEL_40:
      v13 = 0i64;
      goto LABEL_57;
    }
  }
  if ( v5 != 5 )
    goto LABEL_106;
  if ( e == 7 )
    goto LABEL_99;
  if ( e != 6 )
  {
LABEL_106:
    if ( v5 != 6 || e != 7 )
    {
      if ( v5 == 7 && e == 8 || v5 == 3 && e == 8 || v5 == 7 && e == 4 )
        this->mConversationState = 3;
    }
    else
    {
      if ( *((_BYTE *)this + 812) & 8 )
      {
        v30 = 3;
      }
      else
      {
        v2 = 2;
        v30 = 4;
      }
      if ( this->mMinigameSetup )
        v2 = v30;
      UFG::FaceActionComponent::StopConversation(this, v2);
    }
  }
  else
  {
    if ( *((_BYTE *)this + 812) & 8 )
    {
      v29 = 3;
    }
    else
    {
      v2 = 2;
      v29 = 4;
    }
    if ( this->mMinigameSetup )
      v2 = v29;
    UFG::FaceActionComponent::PlayConversation(this, v2);
  }
LABEL_99:
  if ( v4->mState != v3 )
    v4->mTimeInState = 0.0;
  v4->mState = v3;
  if ( v3 == 8 )
    *((_BYTE *)v4 + 812) &= 0xFDu;
  UFG::FaceActionComponent::ProcessIconLogic(v4);
}

// File Line: 1010
// RVA: 0x55AF00
void __fastcall UFG::FaceActionComponent::Update(UFG::FaceActionComponent *this, float deltaTime)
{
  UFG::FaceActionComponent *v2; // rbx
  float v3; // xmm1_4
  UFG::eFaceActionState v4; // eax
  UFG::StreamedResourceComponent *v5; // rdi
  unsigned int v6; // edx
  char v7; // cl
  int v8; // edx
  char v9; // al
  bool v10; // zf
  char v11; // al
  char v12; // al
  unsigned int v13; // edx
  UFG::qPropertySet *v14; // rbp
  UFG::SimObject *v15; // rcx
  unsigned __int16 v16; // dx
  unsigned int v17; // edx
  unsigned int v18; // er9
  UFG::SimComponentHolder *v19; // rsi
  UFG::MeshResourceLoader *v20; // rbx
  UFG::qSymbol priority; // [rsp+58h] [rbp+10h]

  v2 = this;
  v3 = deltaTime + this->mTimeInState;
  this->mTimeInState = v3;
  v4 = this->mState;
  v5 = 0i64;
  if ( v4 == 3 )
  {
    if ( !this->mbShouldInteractionExit[(signed int)UFG::FaceActionComponent::GetFaceActionSuccessState(this)] )
    {
      v9 = *((_BYTE *)v2 + 812);
      if ( !(v9 & 1) && !v2->mMinigameSetup || (v10 = (v9 & 2) == 0, v11 = 1, v10) )
        v11 = 0;
      v6 = -(v11 != 0);
      goto LABEL_21;
    }
LABEL_15:
    v8 = 8;
LABEL_22:
    UFG::FaceActionComponent::SetState(v2, (UFG::eFaceActionState)v8);
    goto LABEL_23;
  }
  if ( v4 == 7 && v3 >= 0.5 )
  {
    if ( !this->mbShouldInteractionExit[(signed int)UFG::FaceActionComponent::GetFaceActionSuccessState(this)] )
    {
      v7 = *((_BYTE *)v2 + 812);
      if ( (!(v7 & 1) && !v2->mMinigameSetup || !(v7 & 2)) && (v7 & 1 || v2->mMinigameSetup)
        || (v8 = 4, *((_BYTE *)v2 + 204) & 0x10) )
      {
        v8 = 0;
      }
      goto LABEL_22;
    }
    if ( *((_BYTE *)v2 + 812) & 0x10 )
    {
      v6 = ~((unsigned int)*((unsigned __int8 *)v2 + 204) >> 2);
LABEL_21:
      v8 = v6 & 4;
      goto LABEL_22;
    }
    goto LABEL_15;
  }
LABEL_23:
  v12 = *((_BYTE *)v2 + 812);
  if ( v12 & 1 || v2->mMinigameSetup )
  {
    if ( v12 & 2 )
      UFG::FaceActionComponent::UpdateSocialLogic(v2);
  }
  UFG::FaceActionComponent::UpdateAnimBankStreamingForFaceAction(v2);
  UFG::FaceActionComponent::UpdateSocialIcon(v2);
  if ( v2->mCurrentFaceAction != 6 || (v13 = v2->mItemProp.mUID, v13 == UFG::gNullQSymbol.mUID) )
  {
    v2->mItemProp = UFG::gNullQSymbol;
    UFG::MeshResourceLoader::Unload(&v2->mPropMeshLoader);
  }
  else if ( v2->mPropMeshLoader.mResourceCount <= 0 && v13 != SimSym_INVALID.mUID )
  {
    v14 = UFG::PropertySetManager::GetPropertySet(&v2->mItemProp);
    if ( v14 )
    {
      v15 = v2->m_pSimObject;
      if ( v15 )
      {
        v16 = v15->m_Flags;
        if ( (v16 >> 14) & 1 || (v16 & 0x8000u) != 0 )
        {
          v5 = (UFG::StreamedResourceComponent *)v15->m_Components.p[10].m_pComponent;
        }
        else if ( (v16 >> 13) & 1 )
        {
          v5 = (UFG::StreamedResourceComponent *)v15->m_Components.p[7].m_pComponent;
        }
        else if ( (v16 >> 12) & 1 )
        {
          v17 = (unsigned int)v15[1].vfptr;
          v18 = v15->m_Components.size;
          if ( v17 < v18 )
          {
            v19 = v15->m_Components.p;
            while ( (v19[v17].m_TypeUID & 0xFE000000) != (UFG::StreamedResourceComponent::_TypeUID & 0xFE000000)
                 || UFG::StreamedResourceComponent::_TypeUID & ~v19[v17].m_TypeUID & 0x1FFFFFF )
            {
              if ( ++v17 >= v18 )
                goto LABEL_47;
            }
            v5 = (UFG::StreamedResourceComponent *)v19[v17].m_pComponent;
          }
        }
        else
        {
          v5 = (UFG::StreamedResourceComponent *)UFG::SimObject::GetComponentOfType(
                                                   v15,
                                                   UFG::StreamedResourceComponent::_TypeUID);
        }
      }
LABEL_47:
      v20 = &v2->mPropMeshLoader;
      UFG::MeshResourceLoader::Unload(v20);
      priority.mUID = UFG::StreamedResourceComponent::GetSpawnPriority(v5, 0i64)->mUID;
      UFG::MeshResourceLoader::Init(v20, v14, (__int64)&priority, 0);
      UFG::MeshResourceLoader::PopulateTrueCrowdInstanceFromPropertySet(v20, 1);
      UFG::MeshResourceLoader::QueueLoad(v20);
    }
  }
}

// File Line: 1119
// RVA: 0x53A570
char __fastcall UFG::FaceActionComponent::IsFaceActionEnabled(UFG::FaceActionComponent *this)
{
  UFG::SimComponent *v1; // rdx
  UFG::FaceActionComponent *v2; // rbx
  UFG::eFaceActionState v3; // ecx
  signed int v4; // eax
  float *v5; // r8
  char v6; // al
  bool v7; // di
  signed __int64 v8; // rdx
  float v9; // xmm0_4
  UFG::CopSystem *v10; // rax
  char result; // al

  v1 = this->mStimulusReceiverComponent.m_pSimComponent;
  v2 = this;
  v3 = this->mState;
  v4 = 56;
  if ( v3 == eFACE_ACTION_STATE_WAITING_FOR_GREET )
    v4 = 33;
  v5 = (float *)*((_QWORD *)&v1[1].m_BoundComponentHandles.mNode.mPrev + v4);
  v6 = *((_BYTE *)v2 + 812) & 1;
  v7 = (v6 || v2->mMinigameSetup) && v3 || !v6 && !v2->mMinigameSetup && v3 != 4;
  if ( !v2->mFaceActionEnabled || v2->mFaceActionEnableBlock || v2->mWaitingForPOIBlock )
    goto LABEL_29;
  if ( *((_BYTE *)v2 + 204) < 0 && !v7 )
  {
    v8 = *(_QWORD *)&v2->mTargetingSystemBaseComponent.m_pSimComponent[1].m_TypeUID
       + 56i64 * *(unsigned __int8 *)(*(_QWORD *)&v2->mTargetingSystemBaseComponent.m_pSimComponent[1].m_Flags + 34i64);
    if ( !*(_QWORD *)(v8 + 40) || !*(_BYTE *)(v8 + 49) )
    {
      if ( !v5 )
        goto LABEL_29;
      v9 = (float)SLODWORD(UFG::Metrics::msInstance.mSimTimeMSec);
      if ( (UFG::Metrics::msInstance.mSimTimeMSec & 0x8000000000000000ui64) != 0i64 )
        v9 = v9 + 1.8446744e19;
      if ( (float)((float)(v9 * 0.001) - *v5) >= s_fSocialRequiresPOITimeout )
        goto LABEL_29;
    }
  }
  v10 = UFG::CopSystem::Instance();
  if ( !((unsigned int (__fastcall *)(UFG::CopSystem *))v10->vfptr[89].__vecDelDtor)(v10)
    && (UFG::FaceActionComponent::GetEvaluatedRecently(v2) || v7) )
  {
    result = 1;
  }
  else
  {
LABEL_29:
    result = 0;
  }
  return result;
}

// File Line: 1148
// RVA: 0x52CCA0
bool __fastcall UFG::FaceActionComponent::GetEvaluatedRecently(UFG::FaceActionComponent *this)
{
  return this->mFrameAITreeLastEvaluated - this->mFrameAITreeFirstEvaluated > s_iFrameCountBuffer
      && this->mFrameAITreeLastUpdated - this->mFrameAITreeLastEvaluated < s_iFrameCountBuffer;
}

// File Line: 1160
// RVA: 0x54D2F0
void __fastcall UFG::FaceActionComponent::SetFrameAITreeUpdated(UFG::FaceActionComponent *this)
{
  this->mFrameAITreeLastUpdated = UFG::Metrics::msInstance.mSimFrameCount;
}

// File Line: 1164
// RVA: 0x54D2B0
void __fastcall UFG::FaceActionComponent::SetFrameAITreeEvaluated(UFG::FaceActionComponent *this, bool bEval)
{
  unsigned int v2; // edx

  if ( bEval )
  {
    v2 = UFG::Metrics::msInstance.mSimFrameCount;
    this->mFrameAITreeLastUpdated = UFG::Metrics::msInstance.mSimFrameCount;
    if ( v2 - this->mFrameAITreeLastEvaluated >= s_iFrameCountBuffer )
      this->mFrameAITreeFirstEvaluated = v2;
    this->mFrameAITreeLastEvaluated = v2;
  }
  else
  {
    *(_QWORD *)&this->mFrameAITreeFirstEvaluated = 0i64;
  }
}

// File Line: 1181
// RVA: 0x560D00
void __fastcall UFG::FaceActionComponent::UpdateSocialLogic(UFG::FaceActionComponent *this)
{
  UFG::SimObject *v1; // rax
  UFG::FaceActionComponent *v2; // rbx
  UFG::SimObjectCharacter *v3; // rax
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rax
  unsigned int v6; // er9
  unsigned int v7; // er10
  signed __int64 v8; // rdx
  unsigned int v9; // er9
  unsigned int v10; // er10
  UFG::SimObject *v11; // rcx
  char v12; // al
  __int64 v13; // [rsp+20h] [rbp-18h]

  v1 = this->m_pSimObject;
  v2 = this;
  if ( v1 && (v1->m_Flags >> 10) & 1 )
    return;
  v3 = UFG::GetLocalPlayer();
  if ( !v3 )
    return;
  v4 = v3->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    v5 = v3->m_Components.p[20].m_pComponent;
    goto LABEL_24;
  }
  if ( (v4 & 0x8000u) != 0 )
  {
    v5 = v3->m_Components.p[20].m_pComponent;
    goto LABEL_24;
  }
  if ( (v4 >> 13) & 1 )
  {
    v6 = v3->mComponentTableEntryCount;
    v7 = v3->m_Components.size;
    if ( v6 < v7 )
    {
      v8 = (signed __int64)&v3->m_Components.p[v6];
      while ( (*(_DWORD *)(v8 + 8) & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
           || UFG::TargetingSystemBaseComponent::_TypeUID & ~*(_DWORD *)(v8 + 8) & 0x1FFFFFF )
      {
        ++v6;
        v8 += 16i64;
        if ( v6 >= v7 )
        {
          v5 = 0i64;
          goto LABEL_24;
        }
      }
LABEL_15:
      v5 = *(UFG::SimComponent **)v8;
      goto LABEL_24;
    }
LABEL_22:
    v5 = 0i64;
    goto LABEL_24;
  }
  if ( (v4 >> 12) & 1 )
  {
    v9 = v3->mComponentTableEntryCount;
    v10 = v3->m_Components.size;
    if ( v9 < v10 )
    {
      v8 = (signed __int64)&v3->m_Components.p[v9];
      while ( (*(_DWORD *)(v8 + 8) & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
           || UFG::TargetingSystemBaseComponent::_TypeUID & ~*(_DWORD *)(v8 + 8) & 0x1FFFFFF )
      {
        ++v9;
        v8 += 16i64;
        if ( v9 >= v10 )
          goto LABEL_22;
      }
      goto LABEL_15;
    }
    goto LABEL_22;
  }
  v5 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
LABEL_24:
  if ( v5 )
  {
    v11 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v5[1].m_Flags + 58i64)
                             + *(_QWORD *)&v5[1].m_TypeUID
                             + 40);
    if ( v11 == v2->m_pSimObject )
      v2->mID = v11->mNode.mUID;
  }
  if ( UFG::FaceMeterComponent::msShowDebug && v2->mCurrentFaceAction != 18 )
  {
    LODWORD(v13) = v2->mMininumRequirement;
    UFG::DrawDebugText(
      v2->m_pSimObject->m_pTransformNodeComponent,
      &UFG::qColour::Green,
      "[%s] - %d",
      v2->mMininumRequirement,
      (__int64)UFG::FaceActionEnumNames[v2->mCurrentFaceAction],
      v13);
  }
  v12 = UFG::FaceActionComponent::IsFaceActionEnabled(v2);
  UFG::FaceActionComponent::UpdatePipIcon(v2, v12 != 0);
}

// File Line: 1510
// RVA: 0x5608D0
void __fastcall UFG::FaceActionComponent::UpdatePipIcon(UFG::FaceActionComponent *this, bool visible)
{
  UFG::FaceActionComponent *v2; // rbx
  UFG::SimObject *v3; // rax
  UFG::FaceActionComponent::PipIconEnum v4; // eax

  v2 = this;
  if ( this->mPipEffectVisible != visible )
  {
    this->mPipEffectVisible = visible;
    if ( !visible )
    {
      this->mCurrentIcon = 11;
      return;
    }
    if ( this->mCurrentIcon != 11 )
    {
      v4 = (unsigned int)UFG::FaceActionComponent::GetCurrentPipIcon(this);
      if ( v2->mCurrentIcon == v4 )
        return;
      goto LABEL_10;
    }
    if ( !this->mHidden )
    {
      v3 = this->m_pSimObject;
      if ( (!v3 || !((v3->m_Flags >> 10) & 1)) && this->mCurrentFaceAction != 18 )
      {
        v4 = (unsigned int)UFG::FaceActionComponent::GetCurrentPipIcon(this);
LABEL_10:
        v2->mCurrentIcon = 11;
        if ( v4 != 11 )
          v2->mCurrentIcon = v4;
        return;
      }
    }
  }
}

// File Line: 1545
// RVA: 0x527C00
void __fastcall UFG::FaceActionComponent::FaceActionEnable(UFG::FaceActionComponent *this, bool bEnable)
{
  bool v2; // al
  bool v3; // di
  UFG::FaceActionComponent *v4; // rbx

  v2 = this->mFaceActionEnabled;
  v3 = bEnable;
  v4 = this;
  if ( v2 != 1 || bEnable )
  {
    if ( v2 || !bEnable )
    {
      this->mFaceActionEnabled = bEnable;
    }
    else
    {
      UFG::FaceActionComponent::ProcessIconLogic(this);
      v4->mFaceActionEnabled = v3;
    }
  }
  else
  {
    UFG::FaceActionComponent::KillEffect(this);
    v4->mFaceActionEnabled = v3;
  }
}

// File Line: 1566
// RVA: 0x154CB50
__int64 UFG::_dynamic_initializer_for__symAnimationStreamingForFaceAction__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("AnimBankStreamingForFaceAction", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symAnimationStreamingForFaceAction, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__symAnimationStreamingForFaceAction__);
}

// File Line: 1569
// RVA: 0x55E3A0
void __fastcall UFG::FaceActionComponent::UpdateAnimBankStreamingForFaceAction(UFG::FaceActionComponent *this)
{
  UFG::FaceActionComponent *v1; // rsi
  bool v2; // r14
  UFG::SimObjectCharacter *v3; // rax
  UFG::SimObjectCharacter *v4; // rdi
  unsigned int v5; // ebx
  unsigned __int16 v6; // dx
  UFG::SimComponent *v7; // rax
  unsigned int v8; // er8
  unsigned int v9; // er9
  UFG::SimComponentHolder *v10; // rbp
  signed __int64 v11; // rdx
  unsigned int v12; // er8
  unsigned int v13; // er9
  unsigned int v14; // er8
  unsigned int v15; // er9
  UFG::TransformNodeComponent *v16; // rdi
  UFG::SimObject *v17; // rax
  UFG::TransformNodeComponent *v18; // rbp
  float v19; // xmm0_4
  UFG::SimObject *v20; // rax
  AnimationGroupHandleContainer *v21; // r14
  UFG::qPropertySet *v22; // rax
  UFG::qPropertySet *v23; // rbp
  const char *v24; // rdi
  UFG::qPropertyList *v25; // rax
  UFG::qPropertyList *v26; // rbp
  unsigned int v27; // esi
  const char *v28; // rax
  UFG::qSymbolUC *v29; // rax
  UFG::qString v30; // [rsp+28h] [rbp-40h]
  UFG::qSymbol result; // [rsp+70h] [rbp+8h]
  UFG::qSymbolUC v32; // [rsp+78h] [rbp+10h]

  v1 = this;
  if ( !(_S23_1 & 1) )
  {
    _S23_1 |= 1u;
    s_fStreamInDistanceSquared = FLOAT_25_0;
  }
  v2 = 0;
  v3 = UFG::GetLocalPlayer();
  v4 = v3;
  v5 = 0;
  if ( v3 )
  {
    v6 = v3->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v7 = v3->m_Components.p[44].m_pComponent;
LABEL_30:
      if ( !v7 )
      {
        v16 = v4->m_pTransformNodeComponent;
        if ( v16 )
        {
          v17 = v1->m_pSimObject;
          if ( v17 )
          {
            v18 = v17->m_pTransformNodeComponent;
            if ( v18 )
            {
              UFG::TransformNodeComponent::UpdateWorldTransform(v16);
              UFG::TransformNodeComponent::UpdateWorldTransform(v18);
              v19 = v18->mWorldTransform.v3.y - v16->mWorldTransform.v3.y;
              v2 = s_fStreamInDistanceSquared >= (float)((float)((float)(v18->mWorldTransform.v3.x
                                                                       - v16->mWorldTransform.v3.x)
                                                               * (float)(v18->mWorldTransform.v3.x
                                                                       - v16->mWorldTransform.v3.x))
                                                       + (float)(v19 * v19));
            }
          }
        }
      }
      goto LABEL_35;
    }
    if ( (v6 & 0x8000u) == 0 )
    {
      if ( (v6 >> 13) & 1 )
      {
        v12 = v3->mComponentTableEntryCount;
        v13 = v3->m_Components.size;
        if ( v12 < v13 )
        {
          v10 = v3->m_Components.p;
          do
          {
            v11 = v12;
            if ( (v10[v12].m_TypeUID & 0xFE000000) == (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
              && !(UFG::CharacterOccupantComponent::_TypeUID & ~v10[v12].m_TypeUID & 0x1FFFFFF) )
            {
              goto LABEL_13;
            }
          }
          while ( ++v12 < v13 );
        }
      }
      else
      {
        if ( !((v6 >> 12) & 1) )
        {
          v7 = UFG::SimObject::GetComponentOfType(
                 (UFG::SimObject *)&v3->vfptr,
                 UFG::CharacterOccupantComponent::_TypeUID);
          goto LABEL_30;
        }
        v14 = v3->mComponentTableEntryCount;
        v15 = v3->m_Components.size;
        if ( v14 < v15 )
        {
          v10 = v3->m_Components.p;
          do
          {
            v11 = v14;
            if ( (v10[v14].m_TypeUID & 0xFE000000) == (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
              && !(UFG::CharacterOccupantComponent::_TypeUID & ~v10[v14].m_TypeUID & 0x1FFFFFF) )
            {
              goto LABEL_13;
            }
          }
          while ( ++v14 < v15 );
        }
      }
    }
    else
    {
      v8 = v3->mComponentTableEntryCount;
      v9 = v3->m_Components.size;
      if ( v8 < v9 )
      {
        v10 = v3->m_Components.p;
        while ( 1 )
        {
          v11 = v8;
          if ( (v10[v8].m_TypeUID & 0xFE000000) == (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
            && !(UFG::CharacterOccupantComponent::_TypeUID & ~v10[v8].m_TypeUID & 0x1FFFFFF) )
          {
            break;
          }
          if ( ++v8 >= v9 )
            goto LABEL_14;
        }
LABEL_13:
        v7 = v10[v11].m_pComponent;
        goto LABEL_30;
      }
    }
LABEL_14:
    v7 = 0i64;
    goto LABEL_30;
  }
LABEL_35:
  v20 = v1->m_pSimObject;
  if ( v20 && (v20->m_Flags >> 10) & 1 || v1->mCurrentFaceAction == 18 || !v2 )
  {
    if ( v1->mAnimationGroupHandleContainer.m_bHasBeenBound )
      AnimationGroupHandleContainer::Unbind(&v1->mAnimationGroupHandleContainer);
  }
  else if ( !v1->mAnimationGroupHandleContainer.m_bHasBeenBound )
  {
    v21 = &v1->mAnimationGroupHandleContainer;
    UFG::qList<AnimationGroupHandle,AnimationGroupHandleContainer,1,0>::DeleteNodes(&v1->mAnimationGroupHandleContainer.m_AnimationGroupHandleList);
    v22 = UFG::PropertySetManager::GetPropertySet((UFG::qSymbol *)&SimSymX_propset_componentFaceAction.mUID);
    v23 = UFG::qPropertySet::Get<UFG::qPropertySet>(
            v22,
            (UFG::qSymbol *)&UFG::symAnimationStreamingForFaceAction.mUID,
            DEPTH_RECURSE);
    if ( (UFG::gFaceActionTracksEnum.m_enumLists.size & 0x80000000) != 0 )
      v24 = 0i64;
    else
      v24 = (*UFG::gFaceActionTracksEnum.m_enumLists.p)->m_enumName.p[v1->mCurrentFaceAction];
    UFG::qSymbol::create_from_string(&result, v24);
    v25 = UFG::qPropertySet::Get<UFG::qPropertyList>(v23, &result, DEPTH_RECURSE);
    v26 = v25;
    if ( v25 )
    {
      v27 = v25->mNumElements;
      if ( v27 )
      {
        do
        {
          v28 = UFG::qPropertyList::Get<char const *>(v26, v5);
          if ( v28 )
          {
            UFG::qString::qString(&v30, v28);
            UFG::qString::MakeUpper(&v30);
            v29 = UFG::qSymbolUC::create_from_string(&v32, v30.mData);
            AnimationGroupHandleContainer::Add(v21, v29, eANIM_PRIORITY_SOCIAL);
            UFG::qString::~qString(&v30);
          }
          else
          {
            UFG::qPrintf(
              "FaceActionComponent::UpdateAnimBankStreamingForFaceAction: Could Not Find ABK Name for Face Action Type: %s\n",
              v24);
          }
          ++v5;
        }
        while ( v5 < v27 );
      }
      AnimationGroupHandleContainer::Bind(v21);
    }
    else
    {
      UFG::qPrintf("WARNING: no ABK list found for face action: %s\n", v24);
    }
  }
}

// File Line: 1667
// RVA: 0x52C650
signed __int64 __fastcall UFG::FaceActionComponent::GetCurrentPipIcon(UFG::FaceActionComponent *this)
{
  UFG::FaceActionComponent *v1; // rbx
  UFG::SimObject *v2; // rcx
  UFG::GameStatTracker *v3; // rax
  int v4; // eax
  int v5; // ecx
  signed __int64 result; // rax

  v1 = this;
  if ( this->mHidden )
    return 11i64;
  v2 = this->m_pSimObject;
  if ( v2 )
  {
    if ( (v2->m_Flags >> 10) & 1 )
      return 11i64;
  }
  if ( v1->mCurrentFaceAction == 18 )
    return 11i64;
  if ( v2 && (v2->m_Flags >> 10) & 1
    || !v1->mFaceActionSetup
    || (v3 = UFG::GameStatTracker::Instance(), v4 = UFG::GameStatTracker::GetFaceLevel(v3), v1->mCurrentFaceAction == 18)
    || (v5 = v1->mMininumRequirement, v4 < v5) )
  {
    switch ( v1->mMininumRequirement )
    {
      case 1:
        return 1i64;
      case 2:
        return 3i64;
      case 3:
        return 5i64;
      case 4:
        return 7i64;
      case 5:
        return 9i64;
    }
    return 11i64;
  }
  switch ( v5 )
  {
    case 0:
      result = 0i64;
      break;
    case 1:
      result = 2i64;
      break;
    case 2:
      result = 4i64;
      break;
    case 3:
      result = 6i64;
      break;
    case 4:
      result = 8i64;
      break;
    case 5:
      result = 10i64;
      break;
    default:
      return 11i64;
  }
  return result;
}

// File Line: 1745
// RVA: 0x53A530
bool __fastcall UFG::FaceActionComponent::IsFaceActionAvailable(UFG::FaceActionComponent *this, UFG::eFaceActionEnum eAction, bool bCheckSetup)
{
  UFG::SimObject *v3; // rax

  v3 = this->m_pSimObject;
  return (!v3 || !((v3->m_Flags >> 10) & 1))
      && (!bCheckSetup || this->mFaceActionSetup)
      && eAction != 18
      && (eAction == 17 || this->mCurrentFaceAction == eAction);
}

// File Line: 1775
// RVA: 0x53A6A0
bool __fastcall UFG::FaceActionComponent::IsFaceActionRequirementMet(UFG::FaceActionComponent *this)
{
  UFG::SimObject *v1; // rax
  UFG::FaceActionComponent *v2; // rbx
  UFG::GameStatTracker *v3; // rax
  int v4; // eax
  bool result; // al

  v1 = this->m_pSimObject;
  v2 = this;
  result = 0;
  if ( !v1 || !((v1->m_Flags >> 10) & 1) )
  {
    if ( this->mFaceActionSetup )
    {
      v3 = UFG::GameStatTracker::Instance();
      v4 = UFG::GameStatTracker::GetFaceLevel(v3);
      if ( v2->mCurrentFaceAction != 18 && v4 >= v2->mMininumRequirement )
        result = 1;
    }
  }
  return result;
}

// File Line: 1795
// RVA: 0x53CA70
signed __int64 __fastcall UFG::FaceActionComponent::LookupFaceAction(UFG::qSymbol *sym)
{
  unsigned int v1; // edx
  UFG::qStaticSymbol *v2; // rax

  v1 = 0;
  v2 = UFG::FaceActionEnumSymbols;
  while ( sym->mUID != v2->mUID )
  {
    ++v2;
    ++v1;
    if ( (signed __int64)v2 >= (signed __int64)&UFG::qStaticSymbol_eINVENTORY_ITEM_EMPTY_POP_CAN )
      return 18i64;
  }
  return v1;
}

// File Line: 1815
// RVA: 0x53CAA0
__int64 __fastcall UFG::FaceActionComponent::LookupSocialInteraction(UFG::qSymbol *sym)
{
  unsigned int v1; // edx
  UFG::qStaticSymbol *v2; // rax

  v1 = 0;
  v2 = UFG::SocialInteractionEnumSymbols;
  while ( sym->mUID != v2->mUID )
  {
    ++v2;
    ++v1;
    if ( (signed __int64)v2 >= (signed __int64)&UFG::qStaticSymbol_eCLOTHINGBUFF_SHARPSHOOTER )
      return 0i64;
  }
  return v1;
}

// File Line: 1829
// RVA: 0x53CA40
__int64 __fastcall UFG::FaceActionComponent::LookupConversationState(UFG::qSymbol *sym)
{
  unsigned int v1; // edx
  UFG::qStaticSymbol *v2; // rax

  v1 = 0;
  v2 = UFG::ConversationStateEnumSymbols;
  while ( sym->mUID != v2->mUID )
  {
    ++v2;
    ++v1;
    if ( (signed __int64)v2 >= (signed __int64)&UFG::qStaticSymbol_eCLOTHINGBUFF_TRIADXP_2 )
      return 0i64;
  }
  return v1;
}

// File Line: 1843
// RVA: 0x54C670
void __fastcall UFG::FaceActionComponent::SetConversationState(UFG::FaceActionComponent *this, UFG::eSocialConversationStateEnum conversationState)
{
  this->mConversationState = conversationState;
}

// File Line: 1848
// RVA: 0x52C190
__int64 __fastcall UFG::FaceActionComponent::GetConversationState(UFG::FaceActionComponent *this)
{
  return (unsigned int)this->mConversationState;
}

// File Line: 1885
// RVA: 0x535620
bool __fastcall UFG::FaceActionComponent::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SceneObjectProperties *v1; // rax
  UFG::qPropertySet *v2; // rcx

  v1 = pSceneObj;
  v2 = pSceneObj->mpWritableProperties;
  if ( !v2 )
    v2 = v1->mpConstProperties;
  return UFG::qPropertySet::GetParentFromName(
           v2,
           (UFG::qSymbol *)&SimSymX_propset_componentFaceAction.mUID,
           DEPTH_RECURSE) != 0i64;
}

// File Line: 1891
// RVA: 0x544F30
UFG::SimComponent *__fastcall UFG::FaceActionComponent::PropertiesOnActivate(UFG::SceneObjectProperties *pSceneObj)
{
  return UFG::FaceActionComponent::CreateFaceActionComponent(pSceneObj);
}

// File Line: 1896
// RVA: 0x5247E0
UFG::SimComponent *__fastcall UFG::FaceActionComponent::CreateFaceActionComponent(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SceneObjectProperties *v1; // rsi
  UFG::qMemoryPool *v2; // rax
  UFG::allocator::free_link *v3; // rax
  UFG::SimComponent *v4; // rax
  UFG::SimComponent *v5; // rdi
  UFG::SimObject *v6; // rdx
  unsigned int v7; // ebx
  UFG::SimObjectModifier v9; // [rsp+38h] [rbp-30h]

  v1 = pSceneObj;
  v2 = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(v2, 0x520ui64, "FaceActionComponent", 0i64, 1u);
  if ( v3 )
  {
    UFG::FaceActionComponent::FaceActionComponent((UFG::FaceActionComponent *)v3, v1->m_NameUID);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  v6 = v1->m_pSimObject;
  if ( (v6->m_Flags >> 14) & 1 )
    v7 = 45;
  else
    v7 = -1;
  UFG::SimObjectModifier::SimObjectModifier(&v9, v6, 1);
  UFG::SimObjectModifier::AttachComponent(&v9, v5, v7);
  UFG::SimObjectModifier::Close(&v9);
  UFG::SimObjectModifier::~SimObjectModifier(&v9);
  v5->vfptr[12].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v5->vfptr, (unsigned int)v1);
  return v5;
}

// File Line: 1908
// RVA: 0x543A60
void __fastcall UFG::FaceActionComponent::PropertiesLoad(UFG::FaceActionComponent *this, UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qPropertySet *v2; // rsi
  UFG::FaceActionComponent *v3; // rbx
  UFG::qSymbol *v4; // r15
  bool *v5; // r14
  bool *v6; // r13
  float *v7; // rbp
  float *v8; // r12
  char *v9; // rdi
  UFG::qSymbol *v10; // rax
  UFG::qSymbol *v11; // rax
  UFG::qSymbol *v12; // rax
  UFG::qSymbol *v13; // rax
  unsigned int v14; // eax
  const char *v15; // rax
  UFG::eFaceActionEnum v16; // esi
  signed int v17; // ecx
  UFG::qStaticSymbol *v18; // rax
  bool v19; // cl
  char v20; // al
  char v21; // cl
  UFG::eFaceActionEnum v22; // eax
  signed __int64 v23; // rcx
  char v24; // al
  float *v25; // [rsp+20h] [rbp-C8h]
  float *v26; // [rsp+28h] [rbp-C0h]
  bool *v27; // [rsp+30h] [rbp-B8h]
  float *v28; // [rsp+38h] [rbp-B0h]
  bool *v29; // [rsp+40h] [rbp-A8h]
  unsigned int *v30; // [rsp+48h] [rbp-A0h]
  bool *v31; // [rsp+50h] [rbp-98h]
  bool *v32; // [rsp+58h] [rbp-90h]
  const char *str; // [rsp+60h] [rbp-88h]
  bool *v34; // [rsp+68h] [rbp-80h]
  bool *v35; // [rsp+70h] [rbp-78h]
  bool *v36; // [rsp+78h] [rbp-70h]
  bool *v37; // [rsp+80h] [rbp-68h]
  bool *v38; // [rsp+88h] [rbp-60h]
  bool *v39; // [rsp+90h] [rbp-58h]
  unsigned int *v40; // [rsp+98h] [rbp-50h]
  bool *v41; // [rsp+A0h] [rbp-48h]
  unsigned int *v42; // [rsp+A8h] [rbp-40h]
  UFG::qWiseSymbol result; // [rsp+F8h] [rbp+10h]
  UFG::qWiseSymbol v44; // [rsp+100h] [rbp+18h]
  UFG::qWiseSymbol v45; // [rsp+108h] [rbp+20h]

  v2 = pSceneObj->mpWritableProperties;
  v3 = this;
  if ( !v2 )
    v2 = pSceneObj->mpConstProperties;
  v4 = UFG::qPropertySet::Get<UFG::qSymbol>(v2, (UFG::qSymbol *)&SimSym_FaceAction.mUID, DEPTH_RECURSE);
  if ( !v4 )
    return;
  v30 = UFG::qPropertySet::Get<unsigned long>(v2, (UFG::qSymbol *)&SimSym_PipsRequired.mUID, DEPTH_RECURSE);
  v32 = UFG::qPropertySet::Get<bool>(v2, (UFG::qSymbol *)&SimSym_Hidden.mUID, DEPTH_RECURSE);
  v5 = UFG::qPropertySet::Get<bool>(v2, (UFG::qSymbol *)&SimSym_RemoveOnCompletion.mUID, DEPTH_RECURSE);
  v36 = UFG::qPropertySet::Get<bool>(v2, (UFG::qSymbol *)&SimSym_MinigameSetup.mUID, DEPTH_RECURSE);
  v38 = UFG::qPropertySet::Get<bool>(v2, (UFG::qSymbol *)&SimSym_MinigameEnabled.mUID, DEPTH_RECURSE);
  v34 = UFG::qPropertySet::Get<bool>(v2, (UFG::qSymbol *)&SimSym_FaceActionEnabled.mUID, DEPTH_RECURSE);
  v6 = UFG::qPropertySet::Get<bool>(v2, (UFG::qSymbol *)&SimSym_RequiresGreet.mUID, DEPTH_RECURSE);
  v41 = UFG::qPropertySet::Get<bool>(v2, (UFG::qSymbol *)&SimSym_RequiresCharge.mUID, DEPTH_RECURSE);
  v35 = UFG::qPropertySet::Get<bool>(v2, (UFG::qSymbol *)&SimSym_CycleBackToGreet.mUID, DEPTH_RECURSE);
  v29 = UFG::qPropertySet::Get<bool>(v2, (UFG::qSymbol *)&SimSym_UseConfirmationDialog.mUID, DEPTH_RECURSE);
  v27 = UFG::qPropertySet::Get<bool>(v2, (UFG::qSymbol *)&SimSym_AutoCharge.mUID, DEPTH_RECURSE);
  v37 = UFG::qPropertySet::Get<bool>(v2, (UFG::qSymbol *)&SimSym_RequiresInteractionAreaCheck.mUID, DEPTH_RECURSE);
  v39 = UFG::qPropertySet::Get<bool>(v2, (UFG::qSymbol *)&SimSym_RequiresPOIUsage.mUID, DEPTH_RECURSE);
  v31 = UFG::qPropertySet::Get<bool>(v2, (UFG::qSymbol *)&SimSym_InteractionPointSyncOverride.mUID, DEPTH_RECURSE);
  v40 = UFG::qPropertySet::Get<unsigned long>(v2, (UFG::qSymbol *)&SimSym_MinigameSpeed.mUID, DEPTH_RECURSE);
  v7 = UFG::qPropertySet::Get<float>(v2, (UFG::qSymbol *)&SimSym_MinigameTimeWarpFactor.mUID, DEPTH_RECURSE);
  v8 = UFG::qPropertySet::Get<float>(v2, (UFG::qSymbol *)&SimSym_MinigameMotionDilation.mUID, DEPTH_RECURSE);
  v42 = UFG::qPropertySet::Get<unsigned long>(v2, (UFG::qSymbol *)&SimSym_MinigameTargetSize.mUID, DEPTH_RECURSE);
  v9 = UFG::qPropertySet::Get<char const *>(v2, (UFG::qSymbol *)&SimSym_InteractionCaption.mUID, DEPTH_RECURSE);
  str = UFG::qPropertySet::Get<char const *>(v2, (UFG::qSymbol *)&SimSym_SocialEffectName.mUID, DEPTH_RECURSE);
  v10 = (UFG::qSymbol *)UFG::qSymbol::qSymbol(&result, 0xA06513B2);
  v25 = UFG::qPropertySet::Get<float>(v2, v10, DEPTH_RECURSE);
  v11 = (UFG::qSymbol *)UFG::qSymbol::qSymbol(&v44, 0x5AC951FEu);
  v26 = UFG::qPropertySet::Get<float>(v2, v11, DEPTH_RECURSE);
  v12 = (UFG::qSymbol *)UFG::qSymbol::qSymbol(&v45, 0x6D41E8F0u);
  v28 = UFG::qPropertySet::Get<float>(v2, v12, DEPTH_RECURSE);
  v3->mConfirmationBoxText = UFG::qPropertySet::Get<char const *>(
                               v2,
                               (UFG::qSymbol *)&SimSym_ConfirmationBoxText.mUID,
                               DEPTH_RECURSE);
  if ( UFG::qPropertySet::Get<UFG::qSymbol>(v2, (UFG::qSymbol *)&SimSym_SellableItem.mUID, DEPTH_RECURSE) )
  {
    v3->mItemVendor = 1;
  }
  else
  {
    v13 = UFG::qPropertySet::Get<UFG::qSymbol>(v2, (UFG::qSymbol *)&SimSym_InventoryType.mUID, DEPTH_RECURSE);
    if ( v13 )
    {
      v14 = v13->mUID;
      if ( qSymbol_Vehicle_16.mUID == v14 )
      {
        v15 = "vehicle";
      }
      else if ( qSymbol_Boat_16.mUID == v14 )
      {
        v15 = "boat";
      }
      else
      {
        if ( qSymbol_Clothes_16.mUID != v14 )
          goto LABEL_14;
        v15 = "clothing";
      }
      v3->mItemIcon = v15;
      goto LABEL_14;
    }
  }
LABEL_14:
  if ( v7 && v8 )
  {
    v3->mMinigameTimeWarpFactor = *v7;
    v3->mMinigameMotionDilation = *v8;
  }
  if ( v6 )
    *((_BYTE *)v3 + 812) ^= (*((_BYTE *)v3 + 812) ^ *v6) & 1;
  if ( v41 )
    *((_BYTE *)v3 + 812) ^= (*((_BYTE *)v3 + 812) ^ 4 * *v41) & 4;
  if ( v5 )
    *((_BYTE *)v3 + 812) ^= (*((_BYTE *)v3 + 812) ^ 16 * (*v5 == 0)) & 0x10;
  if ( v27 )
    *((_BYTE *)v3 + 204) ^= (*((_BYTE *)v3 + 204) ^ 8 * *v27) & 8;
  *((_BYTE *)v3 + 204) &= 0xEFu;
  if ( v35 )
    *((_BYTE *)v3 + 204) ^= (*((_BYTE *)v3 + 204) ^ 16 * *v35) & 0x10;
  *((_BYTE *)v3 + 204) &= 0xFBu;
  if ( v29 )
    *((_BYTE *)v3 + 204) |= 4u;
  if ( v39 )
    *((_BYTE *)v3 + 204) = *((_BYTE *)v3 + 204) & 0x7F | (*v39 << 7);
  v16 = v3->mCurrentFaceAction;
  v17 = 0;
  v18 = UFG::FaceActionEnumSymbols;
  while ( v4->mUID != v18->mUID )
  {
    ++v18;
    ++v17;
    if ( (signed __int64)v18 >= (signed __int64)&UFG::qStaticSymbol_eINVENTORY_ITEM_EMPTY_POP_CAN )
    {
      v17 = 18;
      break;
    }
  }
  v3->mCurrentFaceAction = v17;
  if ( v31 )
    v19 = *v31;
  else
    v19 = (unsigned int)(v17 - 3) <= 3;
  *((_BYTE *)v3 + 204) &= 0xDFu;
  v20 = (char)v37;
  *((_BYTE *)v3 + 204) |= 32 * v19;
  v21 = *((_BYTE *)v3 + 204);
  if ( v37 )
    v20 = *v37;
  v3->mFaceActionSetup = 1;
  v3->mLastPlayedConversationResult = 0;
  v3->mMiniGameResult = 0;
  v3->mConversationState = 0;
  *((_BYTE *)v3 + 204) = v21 ^ (v21 ^ (v20 << 6)) & 0x40;
  v3->mSocialEffectHash = UFG::qStringHashUpper32(str, 0xFFFFFFFF);
  if ( v25 )
    v3->mSocalIconMinSizeDist = *v25;
  if ( v26 )
    v3->mSocalIconMaxSizeDist = *v26;
  if ( v28 )
    v3->mSocalIconScalarMultiplier = *v28;
  v22 = v3->mCurrentFaceAction;
  v3->mConversationFaceType = v22;
  if ( v22 != v16 )
    AnimationGroupHandleContainer::Unbind(&v3->mAnimationGroupHandleContainer);
  v3->mMininumRequirement = *v30;
  v3->mHidden = *v32;
  if ( v5 )
    v3->mbRemoveOnCompletion = *v5;
  if ( v34 )
    UFG::FaceActionComponent::FaceActionEnable(v3, *v34);
  if ( v36 )
    v3->mMinigameSetup = *v36;
  if ( v38 )
    v3->mMinigameEnabled = *v38;
  if ( v40 )
    v3->mMinigameSpeed = *v40;
  if ( v42 )
    v3->mMinigameTargetSize = *v42;
  UFG::FaceActionComponent::ProcessIconLogic(v3);
  if ( v9 && *v9 )
  {
    v23 = (char *)v3 - v9;
    do
    {
      v24 = *v9++;
      v9[v23 + 263] = v24;
    }
    while ( v24 );
  }
  UFG::FaceActionComponent::SetInitialState(v3);
}

// File Line: 2057
// RVA: 0x54D850
void __fastcall UFG::FaceActionComponent::SetInitialState(UFG::FaceActionComponent *this)
{
  char v1; // al
  unsigned int v2; // edx
  char v3; // al
  signed int v4; // er8
  UFG::eSocialConversationStateEnum v5; // eax

  v1 = *((_BYTE *)this + 812);
  if ( !(v1 & 2) && (v1 & 1 || this->mMinigameSetup) )
  {
    this->mConversationState = 1;
    *((_BYTE *)this + 812) = v1 & 0xFD;
    if ( this->mState )
      this->mTimeInState = 0.0;
    this->mState = 0;
    UFG::FaceActionComponent::ProcessIconLogic(this);
  }
  else
  {
    v2 = this->mState;
    v3 = v1 | 2;
    this->mConversationState = 1;
    *((_BYTE *)this + 812) = v3;
    if ( v2 <= 8 && (v4 = 281, _bittest(&v4, v2)) )
    {
      if ( this->mMinigameSetup )
        this->mMinigameEnabled = 1;
      *((_BYTE *)this + 812) = v3 & 0xF7;
    }
    else
    {
      v5 = this->mConversationState;
      if ( v2 == 7 )
        v5 = 3;
      this->mConversationState = v5;
    }
    if ( v2 != 4 )
      this->mTimeInState = 0.0;
    this->mState = 4;
    UFG::FaceActionComponent::ProcessIconLogic(this);
  }
}

// File Line: 2080
// RVA: 0x52E050
char *__fastcall UFG::FaceActionComponent::GetItemCaption(UFG::FaceActionComponent *this)
{
  return this->mItemCaption;
}

// File Line: 2085
// RVA: 0x535960
char __fastcall UFG::FaceActionComponent::HasInteractionSucceeded(UFG::FaceActionComponent *this)
{
  UFG::eFaceActionState v1; // eax
  int v2; // eax

  v1 = this->mState;
  if ( (signed int)v1 < 2 )
    return 0;
  if ( (signed int)v1 <= 4 )
  {
    v2 = 6 - ((*((_BYTE *)this + 812) & 2) != 0);
  }
  else
  {
    if ( (signed int)v1 > 8 )
      return 0;
    if ( *((_BYTE *)this + 812) & 8 )
    {
      v2 = 1;
      if ( this->mMinigameSetup )
        v2 = 3;
    }
    else
    {
      v2 = 2;
      if ( this->mMinigameSetup )
        v2 = 4;
    }
  }
  if ( v2 && this->mbShouldInteractionExit[(signed int)UFG::FaceActionComponent::GetFaceActionSuccessState(this)] )
    return 1;
  return 0;
}

// File Line: 2095
// RVA: 0x552720
void __fastcall UFG::FaceActionComponent::StopAllConversations(UFG::FaceActionComponent *this)
{
  unsigned int *v1; // rbx
  signed __int64 v2; // rdi
  unsigned int v3; // edx
  UFG::qBaseTreeRB *v4; // rax
  _BOOL8 v5; // rdx
  UFG::qBaseTreeRB *v6; // rax
  _BOOL8 v7; // rdx

  v1 = this->mPostInteractionConversationReference;
  v2 = 8i64;
  do
  {
    v3 = *(v1 - 8);
    if ( v3 )
    {
      v4 = UFG::qBaseTreeRB::Get(&UFG::ConversationManager::sm_conversationDb.mTree, v3);
      if ( v4 )
      {
        if ( v4 != (UFG::qBaseTreeRB *)8 )
          UFG::Conversation::ForceFinish((UFG::Conversation *)&v4[-1].mCount, v5);
      }
    }
    if ( *v1 )
    {
      v6 = UFG::qBaseTreeRB::Get(&UFG::ConversationManager::sm_conversationDb.mTree, *v1);
      if ( v6 )
      {
        if ( v6 != (UFG::qBaseTreeRB *)8 )
          UFG::Conversation::ForceFinish((UFG::Conversation *)&v6[-1].mCount, v7);
      }
    }
    ++v1;
    --v2;
  }
  while ( v2 );
}

// File Line: 2114
// RVA: 0x53C0E0
bool __fastcall UFG::FaceActionComponent::IsSocialConversationActive(UFG::FaceActionComponent *this, UFG::eSocialInteractionResultEnum interactionResult)
{
  unsigned int v2; // edx
  UFG::qBaseTreeRB *v3; // rax
  signed __int64 v4; // rax
  bool result; // al
  signed int v6; // ebx
  unsigned int *v7; // rdi
  UFG::qBaseTreeRB *v8; // rax
  signed __int64 v9; // rax

  if ( interactionResult )
  {
    v2 = this->mConversationReference[interactionResult];
    if ( v2
      && (v3 = UFG::qBaseTreeRB::Get(&UFG::ConversationManager::sm_conversationDb.mTree, v2)) != 0i64
      && (v4 = (signed __int64)&v3[-1].mCount) != 0 )
    {
      result = *(_DWORD *)(v4 + 48) == 1 || *(_DWORD *)(v4 + 52) == 1;
    }
    else
    {
LABEL_16:
      result = 0;
    }
  }
  else
  {
    v6 = 0;
    v7 = this->mConversationReference;
    while ( 1 )
    {
      if ( *v7 )
      {
        v8 = UFG::qBaseTreeRB::Get(&UFG::ConversationManager::sm_conversationDb.mTree, *v7);
        if ( v8 )
        {
          v9 = (signed __int64)&v8[-1].mCount;
          if ( v9 )
          {
            if ( *(_DWORD *)(v9 + 48) == 1 || *(_DWORD *)(v9 + 52) == 1 )
              break;
          }
        }
      }
      ++v6;
      ++v7;
      if ( v6 >= 8 )
        goto LABEL_16;
    }
    result = 1;
  }
  return result;
}

// File Line: 2146
// RVA: 0x54FD20
bool __fastcall UFG::FaceActionComponent::SocialConversationHasActionRequests(UFG::FaceActionComponent *this, UFG::eSocialInteractionResultEnum interactionResult)
{
  unsigned int v2; // edx
  UFG::qBaseTreeRB *v3; // rax
  signed __int64 v4; // rax
  signed int v6; // ebx
  unsigned int *v7; // rdi
  UFG::qBaseTreeRB *v8; // rax

  if ( interactionResult == eSOCIALINTERACTIONRESULT_INVALID )
  {
    v6 = 0;
    v7 = this->mConversationReference;
    while ( 1 )
    {
      if ( *v7 )
      {
        v8 = UFG::qBaseTreeRB::Get(&UFG::ConversationManager::sm_conversationDb.mTree, *v7);
        if ( v8 )
        {
          v4 = (signed __int64)&v8[-1].mCount;
          if ( v4 )
          {
            if ( *(_DWORD *)(v4 + 48) == 1 )
              break;
          }
        }
      }
      ++v6;
      ++v7;
      if ( v6 >= 8 )
        return 0;
    }
    return (*(_BYTE *)(v4 + 168) >> 6) & 1;
  }
  v2 = this->mConversationReference[interactionResult];
  if ( v2 )
  {
    v3 = UFG::qBaseTreeRB::Get(&UFG::ConversationManager::sm_conversationDb.mTree, v2);
    if ( v3 )
    {
      v4 = (signed __int64)&v3[-1].mCount;
      if ( v4 )
        return (*(_BYTE *)(v4 + 168) >> 6) & 1;
    }
  }
  return 0;
}

// File Line: 2190
// RVA: 0x53C0D0
bool __fastcall UFG::FaceActionComponent::IsSafehouseItemVendor(UFG::eInventoryItemEnum e)
{
  return (unsigned int)(e - 163) <= 0x13;
}

// File Line: 2223
// RVA: 0x52C1A0
signed __int64 __fastcall UFG::FaceActionComponent::GetConversationTopic(UFG::FaceActionComponent *this, UFG::eSocialInteractionResultEnum interactionResult)
{
  UFG::FaceActionComponent *v2; // rbx
  UFG::eInventoryItemEnum v3; // eax
  unsigned int v4; // ecx
  signed __int64 result; // rax
  UFG::eInventoryItemEnum v6; // eax
  unsigned int v7; // ecx
  UFG::eFaceActionEnum v8; // ecx
  const char *v9; // rcx

  v2 = this;
  switch ( interactionResult )
  {
    case 5:
      if ( (unsigned int)(this->mCurrentFaceAction - 6) <= 1 )
      {
        v3 = this->mInventoryItem;
        v4 = 34;
        if ( (unsigned int)(v3 - 163) <= 0x13 )
          v4 = 52;
        return v4;
      }
      return 23i64;
    case 6:
      if ( (unsigned int)(this->mCurrentFaceAction - 6) > 1 )
        return 24i64;
      v6 = this->mInventoryItem;
      v7 = 35;
      if ( (unsigned int)(v6 - 163) <= 0x13 )
        v7 = 60;
      result = v7;
      break;
    case 2:
      if ( (unsigned int)(this->mCurrentFaceAction - 6) <= 1 )
      {
        if ( (unsigned int)(this->mInventoryItem - 163) > 0x13 )
          result = 35i64;
        else
          result = 62 - (unsigned int)((*((_BYTE *)this + 204) & 2) != 0);
        return result;
      }
      return 24i64;
    case 1:
      v8 = this->mCurrentFaceAction;
      if ( (unsigned int)(v8 - 6) <= 1 )
      {
        v9 = v2->mItemIcon;
        if ( !v9
          || (unsigned int)UFG::qStringCompareInsensitive(v9, "vehicle", -1)
          && (unsigned int)UFG::qStringCompareInsensitive(v2->mItemIcon, "clothing", -1) )
        {
          switch ( v2->mInventoryItem )
          {
            case 0x12:
              result = 14i64;
              break;
            case 0x13:
              result = 17i64;
              break;
            case 0x14:
              result = 19i64;
              break;
            case 0x15:
              result = 13i64;
              break;
            case 0x16:
              result = 58i64;
              break;
            case 0x17:
              result = 63i64;
              break;
            case 0x18:
              result = 59i64;
              break;
            case 0x19:
              result = 64i64;
              break;
            case 0x1A:
              result = 18i64;
              break;
            case 0x1B:
              result = 16i64;
              break;
            case 0x1C:
              result = 66i64;
              break;
            case 0x1D:
            case 0x1E:
              result = 21i64;
              break;
            case 0x1F:
              result = 15i64;
              break;
            case 0x50:
            case 0x51:
            case 0x52:
            case 0x65:
            case 0x66:
            case 0x67:
              result = 4i64;
              break;
            case 0x97:
            case 0x98:
              result = 20i64;
              break;
            case 0xA3:
            case 0xA4:
            case 0xA5:
            case 0xA6:
            case 0xA7:
            case 0xA8:
            case 0xA9:
            case 0xAA:
            case 0xAB:
            case 0xAC:
            case 0xAD:
            case 0xAE:
            case 0xAF:
            case 0xB0:
            case 0xB1:
            case 0xB2:
            case 0xB3:
            case 0xB4:
            case 0xB5:
            case 0xB6:
              result = 51i64;
              break;
            default:
              result = 12i64;
              break;
          }
        }
        else
        {
          result = 67i64;
        }
      }
      else if ( v8 )
      {
        switch ( v8 )
        {
          case 1:
            result = 37i64;
            break;
          case 2:
            result = 38i64;
            break;
          case 3:
            result = 39i64;
            break;
          case 4:
            result = 40i64;
            break;
          case 8:
            result = 41i64;
            break;
          case 9:
            result = 42i64;
            break;
          case 10:
            result = 43i64;
            break;
          case 11:
            result = 44i64;
            break;
          case 12:
            result = 46i64;
            break;
          case 13:
            result = 47i64;
            break;
          case 14:
            result = 48i64;
            break;
          case 15:
            result = 49i64;
            break;
          default:
            result = 23i64;
            if ( v8 == 16 )
              result = 50i64;
            break;
        }
      }
      else
      {
        result = 36i64;
      }
      break;
    default:
      return 23i64;
  }
  return result;
}

// File Line: 2445
// RVA: 0x52C880
UFG::AmbientConversation *__fastcall UFG::FaceActionComponent::GetDefaultConversation(UFG::FaceActionComponent *this, UFG::eSocialInteractionResultEnum interactionResult)
{
  UFG::FaceActionComponent *v2; // rdi
  UFG::eConversationTopic v3; // esi
  unsigned int v5; // eax
  UFG::AmbientConversation *v6; // rax
  UFG::AmbientConversation *v7; // rbx
  UFG::SimObjectCharacter *v8; // rax

  v2 = this;
  v3 = (unsigned int)UFG::FaceActionComponent::GetConversationTopic(this, interactionResult);
  if ( v3 == 67 )
    return 0i64;
  v5 = UFG::ConversationManager::GetConversationId();
  v6 = UFG::ConversationManager::AddAmbientConversation(v5);
  v7 = v6;
  if ( v6 )
  {
    v6->m_topic = v3;
    v8 = UFG::GetLocalPlayer();
    UFG::AmbientConversation::SetupLines(v7, v2->m_pSimObject, (UFG::SimObject *)&v8->vfptr);
    UFG::Conversation::SetContainsActionRequests((UFG::Conversation *)&v7->vfptr);
  }
  return v7;
}

// File Line: 2487
// RVA: 0x5426C0
void __fastcall UFG::FaceActionComponent::PlayConversation(UFG::FaceActionComponent *this, UFG::eSocialInteractionResultEnum interactionResult)
{
  UFG::eSocialInteractionResultEnum v2; // esi
  UFG::FaceActionComponent *v3; // rdi
  char *v4; // r14
  unsigned int v5; // edx
  UFG::qBaseTreeRB *v6; // rax
  UFG::Conversation *v7; // rbx
  UFG::AmbientConversation *v8; // rax

  v2 = interactionResult;
  v3 = this;
  v4 = (char *)this + 4 * interactionResult;
  v5 = *((_DWORD *)v4 + 154);
  if ( v5 && (v6 = UFG::qBaseTreeRB::Get(&UFG::ConversationManager::sm_conversationDb.mTree, v5)) != 0i64 )
    v7 = (UFG::Conversation *)&v6[-1].mCount;
  else
    v7 = 0i64;
  if ( v7 )
    goto LABEL_8;
  v8 = UFG::FaceActionComponent::GetDefaultConversation(v3, v2);
  v7 = (UFG::Conversation *)&v8->vfptr;
  if ( v8 )
  {
    *((_DWORD *)v4 + 154) = v8->mNode.mUID;
LABEL_8:
    UFG::ConversationManager::InterruptPlayerConversations(eInterruptType_Social, 1, v3->m_pSimObject);
    UFG::Conversation::Start(v7);
  }
  v3->mLastPlayedConversationResult = v2;
}

// File Line: 2516
// RVA: 0x5527A0
void __fastcall UFG::FaceActionComponent::StopConversation(UFG::FaceActionComponent *this, UFG::eSocialInteractionResultEnum interactionResult)
{
  unsigned int v2; // edx
  UFG::qBaseTreeRB *v3; // rax

  v2 = this->mConversationReference[interactionResult];
  if ( v2 )
  {
    v3 = UFG::qBaseTreeRB::Get(&UFG::ConversationManager::sm_conversationDb.mTree, v2);
    if ( v3 )
    {
      if ( v3 != (UFG::qBaseTreeRB *)8 )
        UFG::Conversation::Stop((UFG::Conversation *)&v3[-1].mCount, 0);
    }
  }
  UFG::ConversationManager::ResumePlayerConversations(eInterruptType_Social);
}

// File Line: 2531
// RVA: 0x542760
void __fastcall UFG::FaceActionComponent::PlayPostInteractionConversation(UFG::FaceActionComponent *this, UFG::eSocialInteractionResultEnum interactionResult)
{
  UFG::eSocialInteractionResultEnum v2; // ebx
  UFG::FaceActionComponent *v3; // rdi
  unsigned int v4; // edx
  UFG::qBaseTreeRB *v5; // rax

  v2 = interactionResult;
  v3 = this;
  v4 = this->mPostInteractionConversationReference[interactionResult];
  if ( v4 )
  {
    v5 = UFG::qBaseTreeRB::Get(&UFG::ConversationManager::sm_conversationDb.mTree, v4);
    if ( v5 )
    {
      if ( v5 != (UFG::qBaseTreeRB *)8 )
        UFG::Conversation::Start((UFG::Conversation *)&v5[-1].mCount);
    }
    v3->mLastPlayedConversationResult = v2;
  }
  else
  {
    this->mLastPlayedConversationResult = v2;
  }
}

// File Line: 2550
// RVA: 0x552860
void __fastcall UFG::FaceActionComponent::StopPostInteractionConversation(UFG::FaceActionComponent *this, UFG::eSocialInteractionResultEnum interactionResult)
{
  UFG::FaceActionComponent *v2; // rbx
  unsigned int v3; // edx
  UFG::qBaseTreeRB *v4; // rax

  v2 = this;
  v3 = this->mPostInteractionConversationReference[interactionResult];
  if ( v3 )
  {
    v4 = UFG::qBaseTreeRB::Get(&UFG::ConversationManager::sm_conversationDb.mTree, v3);
    if ( v4 )
    {
      if ( v4 != (UFG::qBaseTreeRB *)8 )
        UFG::Conversation::Stop((UFG::Conversation *)&v4[-1].mCount, 0);
    }
    v2->mConversationState = 2;
    v2->mLastPlayedConversationResult = 0;
  }
}

// File Line: 2572
// RVA: 0x52CC50
__int64 __fastcall UFG::FaceActionComponent::GetDialogueConversationFaceAction(UFG::FaceActionComponent *this)
{
  return (unsigned int)this->mConversationFaceType;
}

// File Line: 2577
// RVA: 0x54E680
void __fastcall UFG::FaceActionComponent::SetShouldInteractionExit(UFG::FaceActionComponent *this, UFG::eSocialInteractionResultEnum interactionResult, bool bExitCondition)
{
  this->mbShouldInteractionExit[interactionResult] = bExitCondition;
}

// File Line: 2582
// RVA: 0x54FAD0
_BOOL8 __fastcall UFG::FaceActionComponent::ShouldInteractionExit(UFG::FaceActionComponent *this, UFG::eSocialInteractionResultEnum interactionResult)
{
  return this->mbShouldInteractionExit[interactionResult];
}

// File Line: 2587
// RVA: 0x54E670
void __fastcall UFG::FaceActionComponent::SetShouldConversationReset(UFG::FaceActionComponent *this, UFG::eSocialInteractionResultEnum interactionResult, bool bResetCondition)
{
  this->mbShouldConversationReset[interactionResult] = bResetCondition;
}

// File Line: 2592
// RVA: 0x54F930
_BOOL8 __fastcall UFG::FaceActionComponent::ShouldConversationReset(UFG::FaceActionComponent *this, UFG::eSocialInteractionResultEnum interactionResult)
{
  return this->mbShouldConversationReset[interactionResult];
}

// File Line: 2597
// RVA: 0x54C630
void __fastcall UFG::FaceActionComponent::SetConversationReference(UFG::FaceActionComponent *this, UFG::eSocialInteractionResultEnum interactionResult, UFG::Conversation *pConversation)
{
  UFG::FaceActionComponent *v3; // rdi
  UFG::Conversation *v4; // rsi
  __int64 v5; // rbx

  v3 = this;
  v4 = pConversation;
  v5 = interactionResult;
  UFG::Conversation::SetContainsActionRequests(pConversation);
  v3->mConversationReference[v5] = v4->mNode.mUID;
}

// File Line: 2603
// RVA: 0x522D60
void __fastcall UFG::FaceActionComponent::ClearConversationReferences(UFG::FaceActionComponent *this)
{
  unsigned int *v1; // rax
  signed __int64 v2; // rcx

  v1 = this->mPostInteractionConversationReference;
  v2 = 8i64;
  do
  {
    *(v1 - 8) = 0;
    *v1 = 0;
    ++v1;
    --v2;
  }
  while ( v2 );
}

// File Line: 2614
// RVA: 0x52C150
UFG::Conversation *__fastcall UFG::FaceActionComponent::GetConversationReference(UFG::FaceActionComponent *this, UFG::eSocialInteractionResultEnum interactionResult)
{
  unsigned int v2; // edx
  UFG::qBaseTreeRB *v3; // rax
  UFG::Conversation *result; // rax

  v2 = this->mConversationReference[interactionResult];
  if ( v2 && (v3 = UFG::qBaseTreeRB::Get(&UFG::ConversationManager::sm_conversationDb.mTree, v2)) != 0i64 )
    result = (UFG::Conversation *)&v3[-1].mCount;
  else
    result = 0i64;
  return result;
}

// File Line: 2631
// RVA: 0x54E550
void __fastcall UFG::FaceActionComponent::SetPostInteractionConversationReference(UFG::FaceActionComponent *this, UFG::eSocialInteractionResultEnum interactionResult, UFG::Conversation *pConversation)
{
  this->mPostInteractionConversationReference[interactionResult] = pConversation->mNode.mUID;
}

// File Line: 2636
// RVA: 0x52F5F0
UFG::Conversation *__fastcall UFG::FaceActionComponent::GetPostInteractionConversationReference(UFG::FaceActionComponent *this, UFG::eSocialInteractionResultEnum interactionResult)
{
  unsigned int v2; // edx
  UFG::qBaseTreeRB *v3; // rax
  UFG::Conversation *result; // rax

  v2 = this->mPostInteractionConversationReference[interactionResult];
  if ( v2 && (v3 = UFG::qBaseTreeRB::Get(&UFG::ConversationManager::sm_conversationDb.mTree, v2)) != 0i64 )
    result = (UFG::Conversation *)&v3[-1].mCount;
  else
    result = 0i64;
  return result;
}

// File Line: 2647
// RVA: 0x53BEF0
_BOOL8 __fastcall UFG::FaceActionComponent::IsPostInteractionConversationValid(UFG::FaceActionComponent *this, UFG::eSocialInteractionResultEnum interactionResult)
{
  return this->mPostInteractionConversationReference[interactionResult] != 0;
}

// File Line: 2652
// RVA: 0x52E250
UFG::Conversation *__fastcall UFG::FaceActionComponent::GetLastPlayedConversation(UFG::FaceActionComponent *this)
{
  unsigned int v1; // edx
  UFG::qBaseTreeRB *v2; // rax
  UFG::Conversation *result; // rax

  v1 = this->mConversationReference[this->mLastPlayedConversationResult];
  if ( v1 && (v2 = UFG::qBaseTreeRB::Get(&UFG::ConversationManager::sm_conversationDb.mTree, v1)) != 0i64 )
    result = (UFG::Conversation *)&v2[-1].mCount;
  else
    result = 0i64;
  return result;
}

