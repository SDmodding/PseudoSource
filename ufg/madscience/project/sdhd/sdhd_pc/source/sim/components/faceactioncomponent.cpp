// File Line: 48
// RVA: 0x1543E20
__int64 dynamic_initializer_for__UFG::FaceActionComponent::s_FaceActionComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::FaceActionComponent::s_FaceActionComponentList__);
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
  UFG::qNode<UFG::FaceActionComponent,UFG::FaceActionComponent> *mPrev; // rax
  bool *mbShouldConversationReset; // rax
  unsigned int *mPostInteractionConversationReference; // rcx
  __int64 v6; // rdx

  UFG::SimComponent::SimComponent(this, name_uid);
  this->mPrev = &this->UFG::qNode<UFG::FaceActionComponent,UFG::FaceActionComponent>;
  this->mNext = &this->UFG::qNode<UFG::FaceActionComponent,UFG::FaceActionComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::FaceActionComponent::`vftable;
  this->m_DebugDrawEnabled = 0;
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>(&this->mTargetingSystemBaseComponent);
  UFG::RebindingComponentHandle<UFG::StimulusReceiverComponent,0>::RebindingComponentHandle<UFG::StimulusReceiverComponent,0>(&this->mStimulusReceiverComponent);
  *(_QWORD *)&this->mFrameAITreeFirstEvaluated = 0i64;
  this->mFrameAITreeLastUpdated = 0;
  *((_BYTE *)this + 204) = 8;
  *((_BYTE *)this + 205) &= 0xFCu;
  this->mID = -1;
  *(_QWORD *)&this->mCurrentFaceAction = 18i64;
  *(_QWORD *)&this->mFaceActionSetup = 0i64;
  this->mMinigameSpeed = 80;
  this->mMinigameTargetSize = 30;
  *(_DWORD *)&this->mMinigameSetup = 0x1000000;
  this->mCurrentIcon = ePipIcon_NONE;
  *(_WORD *)&this->mPipEffectVisible = 0;
  *(_QWORD *)&this->mItemPrice = 0i64;
  this->mItemIcon = 0i64;
  this->mItemVendor = 0;
  this->mItemProp = UFG::gNullQSymbol;
  this->mLastPlayedConversationResult = eSOCIALINTERACTIONRESULT_INVALID;
  this->mConversationState = eSOCIAL_CONVERSATION_STATE_ENDED;
  UFG::qString::qString(&this->mAutoCompleteObjective);
  this->mScriptCommandDebugText = 0i64;
  this->mNumScriptCommandDebugTexts = 0;
  this->mAnimationGroupHandleContainer.m_AnimationGroupHandleList.mNode.mPrev = &this->mAnimationGroupHandleContainer.m_AnimationGroupHandleList.mNode;
  this->mAnimationGroupHandleContainer.m_AnimationGroupHandleList.mNode.mNext = &this->mAnimationGroupHandleContainer.m_AnimationGroupHandleList.mNode;
  this->mAnimationGroupHandleContainer.m_bHasBeenBound = 0;
  *(_QWORD *)&this->mSocialEffectHash = -1i64;
  this->mEffectOverride.m_pPointer = 0i64;
  this->mMinigameTimeWarpFactor = 0.1;
  this->mMinigameMotionDilation = 0.5;
  *((_BYTE *)this + 812) = *((_BYTE *)this + 812) & 0xE0 | 5;
  this->mMiniGameResult = eSOCIALINTERACTIONRESULT_INVALID;
  UFG::MeshResourceLoader::MeshResourceLoader(&this->mPropMeshLoader);
  mPrev = UFG::FaceActionComponent::s_FaceActionComponentList.mNode.mPrev;
  UFG::FaceActionComponent::s_FaceActionComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::FaceActionComponent,UFG::FaceActionComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::FaceActionComponent,UFG::FaceActionComponent> *)&UFG::FaceActionComponent::s_FaceActionComponentList;
  UFG::FaceActionComponent::s_FaceActionComponentList.mNode.mPrev = &this->UFG::qNode<UFG::FaceActionComponent,UFG::FaceActionComponent>;
  UFG::SimComponent::AddType(this, UFG::FaceActionComponent::_FaceActionComponentTypeUID, "FaceActionComponent");
  mbShouldConversationReset = this->mbShouldConversationReset;
  mPostInteractionConversationReference = this->mPostInteractionConversationReference;
  v6 = 8i64;
  do
  {
    *(mbShouldConversationReset - 8) = 0;
    *mbShouldConversationReset = 0;
    *(mPostInteractionConversationReference - 8) = 0;
    *mPostInteractionConversationReference++ = 0;
    ++mbShouldConversationReset;
    --v6;
  }
  while ( v6 );
  this->mbShouldConversationReset[2] = 1;
  this->mbShouldConversationReset[5] = 1;
  this->mbShouldConversationReset[7] = 1;
  this->mbShouldInteractionExit[1] = 1;
  *(_WORD *)&this->mbShouldInteractionExit[3] = 257;
  this->mbShouldInteractionExit[6] = 1;
  this->mSocalIconMaxSizeDist = 50.0;
  this->mSocalIconMinSizeDist = 10.0;
  this->mSocalIconScalarMultiplier = 10.0;
  UFG::qStringCopy(this->mItemName, 0x7FFFFFFF, &customCaption, -1);
  UFG::qStringCopy(this->mItemCaption, 0x7FFFFFFF, &customCaption, -1);
  UFG::qStringCopy(this->mItemDescription, 0x7FFFFFFF, &customCaption, -1);
  UFG::FaceActionComponent::SetInitialState(this);
}

// File Line: 143
// RVA: 0x51B520
void __fastcall UFG::FaceActionComponent::~FaceActionComponent(UFG::FaceActionComponent *this)
{
  UFG::qNode<UFG::FaceActionComponent,UFG::FaceActionComponent> *v2; // rsi
  UFG::qNode<UFG::FaceActionComponent,UFG::FaceActionComponent> *mPrev; // rcx
  UFG::qNode<UFG::FaceActionComponent,UFG::FaceActionComponent> *mNext; // rax
  Render::FXOverride *m_pPointer; // rax
  Render::FXOverride *v6; // rbx
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *v7; // rcx
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *v8; // rax
  UFG::qNode<UFG::FaceActionComponent,UFG::FaceActionComponent> *v9; // rcx
  UFG::qNode<UFG::FaceActionComponent,UFG::FaceActionComponent> *v10; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::FaceActionComponent::`vftable;
  if ( this->mAnimationGroupHandleContainer.m_bHasBeenBound )
    AnimationGroupHandleContainer::Unbind(&this->mAnimationGroupHandleContainer);
  UFG::FaceActionComponent::ResetState(this);
  if ( this == UFG::FaceActionComponent::s_FaceActionComponentpCurrentIterator )
    UFG::FaceActionComponent::s_FaceActionComponentpCurrentIterator = (UFG::FaceActionComponent *)&this->mPrev[-4];
  v2 = &this->UFG::qNode<UFG::FaceActionComponent,UFG::FaceActionComponent>;
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = &this->UFG::qNode<UFG::FaceActionComponent,UFG::FaceActionComponent>;
  this->mNext = &this->UFG::qNode<UFG::FaceActionComponent,UFG::FaceActionComponent>;
  UFG::MeshResourceLoader::~MeshResourceLoader(&this->mPropMeshLoader);
  m_pPointer = this->mEffectOverride.m_pPointer;
  if ( m_pPointer )
  {
    --m_pPointer->mReferenceCount;
    v6 = this->mEffectOverride.m_pPointer;
    if ( v6->mReferenceCount <= 0 )
    {
      if ( v6 )
      {
        Render::FXOverride::~FXOverride(this->mEffectOverride.m_pPointer);
        operator delete[](v6);
      }
      this->mEffectOverride.m_pPointer = 0i64;
    }
  }
  UFG::qList<AnimationGroupHandle,AnimationGroupHandleContainer,1,0>::DeleteNodes(&this->mAnimationGroupHandleContainer.m_AnimationGroupHandleList);
  UFG::qList<AnimationGroupHandle,AnimationGroupHandleContainer,1,0>::DeleteNodes(&this->mAnimationGroupHandleContainer.m_AnimationGroupHandleList);
  v7 = this->mAnimationGroupHandleContainer.m_AnimationGroupHandleList.mNode.mPrev;
  v8 = this->mAnimationGroupHandleContainer.m_AnimationGroupHandleList.mNode.mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->mAnimationGroupHandleContainer.m_AnimationGroupHandleList.mNode.mPrev = &this->mAnimationGroupHandleContainer.m_AnimationGroupHandleList.mNode;
  this->mAnimationGroupHandleContainer.m_AnimationGroupHandleList.mNode.mNext = &this->mAnimationGroupHandleContainer.m_AnimationGroupHandleList.mNode;
  UFG::qString::~qString(&this->mAutoCompleteObjective);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->mStimulusReceiverComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->mTargetingSystemBaseComponent);
  v9 = v2->mPrev;
  v10 = this->mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  v2->mPrev = v2;
  this->mNext = &this->UFG::qNode<UFG::FaceActionComponent,UFG::FaceActionComponent>;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 166
// RVA: 0x54A7A0
void __fastcall UFG::FaceActionComponent::ResetState(UFG::FaceActionComponent *this)
{
  bool mStartGame; // al
  char v3; // al

  UFG::FaceActionComponent::KillEffect(this);
  if ( this->mFaceActionEnabled )
    UFG::FaceActionComponent::KillEffect(this);
  this->mCurrentFaceAction = eFACEACTION_INVALID;
  this->mMininumRequirement = 0;
  *(_DWORD *)&this->mMinigameSetup = 0x1000000;
  this->mCurrentIcon = ePipIcon_NONE;
  this->mPipEffectVisible = 0;
  *(_WORD *)&this->mFaceActionSetup = 0;
  this->mMinigameSpeed = 125;
  this->mMinigameTargetSize = 30;
  UFG::qStringCopy(this->mItemCaption, 0x7FFFFFFF, &customCaption, -1);
  this->mItemPrice = 0;
  this->mItemIcon = 0i64;
  this->mItemVendor = 0;
  this->mItemProp = UFG::gNullQSymbol;
  this->mScriptCommandDebugText = 0i64;
  this->mNumScriptCommandDebugTexts = 0;
  this->mConversationState = eSOCIAL_CONVERSATION_STATE_INVALID;
  this->mLastPlayedConversationResult = eSOCIALINTERACTIONRESULT_INVALID;
  this->mMiniGameResult = eSOCIALINTERACTIONRESULT_INVALID;
  UFG::qString::Set(&this->mAutoCompleteObjective, &customCaption);
  mStartGame = UFG::UIHKSocialActionManager::SocialAction.mStartGame;
  if ( UFG::UIHKSocialActionManager::mThis )
    mStartGame = 0;
  UFG::UIHKSocialActionManager::SocialAction.mStartGame = mStartGame;
  UFG::FaceActionComponent::SetInitialState(this);
  v3 = *((_BYTE *)this + 204);
  *((_BYTE *)this + 812) &= 0xF5u;
  *((_BYTE *)this + 205) &= 0xFCu;
  this->mConfirmationBoxText = 0i64;
  this->mbForceIconOn = 0;
  *((_BYTE *)this + 204) = v3 & 0xE0 | 8;
}

// File Line: 223
// RVA: 0x53DB20
void __fastcall UFG::FaceActionComponent::OnAttach(UFG::FaceActionComponent *this, UFG::SimObject *pObject)
{
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0> *p_mTargetingSystemBaseComponent; // rcx
  UFG::AIActionTreeComponent *m_pComponent; // rbx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rax
  UFG::RebindingComponentHandle<UFG::StimulusReceiverComponent,0> *p_mStimulusReceiverComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v12; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v14; // rax
  UFG::SimObject *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  __int64 v19; // rdx
  unsigned int v20; // r8d
  unsigned int v21; // r9d

  p_mTargetingSystemBaseComponent = &this->mTargetingSystemBaseComponent;
  m_pComponent = 0i64;
  if ( p_mTargetingSystemBaseComponent->m_pSimComponent )
  {
    mPrev = p_mTargetingSystemBaseComponent->mPrev;
    mNext = p_mTargetingSystemBaseComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mTargetingSystemBaseComponent->m_pSimComponent = 0i64;
LABEL_7:
    p_mTargetingSystemBaseComponent->m_pSimObject = 0i64;
    p_mTargetingSystemBaseComponent->mNext = p_mTargetingSystemBaseComponent;
    p_mTargetingSystemBaseComponent->mPrev = p_mTargetingSystemBaseComponent;
    goto LABEL_8;
  }
  if ( p_mTargetingSystemBaseComponent->m_pSimObject
    && (p_mTargetingSystemBaseComponent->mPrev != p_mTargetingSystemBaseComponent
     || p_mTargetingSystemBaseComponent->mNext != p_mTargetingSystemBaseComponent) )
  {
    v8 = p_mTargetingSystemBaseComponent->mPrev;
    v9 = p_mTargetingSystemBaseComponent->mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    goto LABEL_7;
  }
LABEL_8:
  p_mTargetingSystemBaseComponent->m_Changed = 1;
  p_mTargetingSystemBaseComponent->m_pSimObject = pObject;
  p_mTargetingSystemBaseComponent->m_TypeUID = UFG::TargetingSystemBaseComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0>::BindInternal<UFG::SimObject>(
    p_mTargetingSystemBaseComponent,
    pObject);
  p_mStimulusReceiverComponent = &this->mStimulusReceiverComponent;
  if ( this->mStimulusReceiverComponent.m_pSimComponent )
  {
    v11 = p_mStimulusReceiverComponent->mPrev;
    v12 = this->mStimulusReceiverComponent.mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    this->mStimulusReceiverComponent.m_pSimComponent = 0i64;
LABEL_14:
    this->mStimulusReceiverComponent.m_pSimObject = 0i64;
    this->mStimulusReceiverComponent.mNext = &this->mStimulusReceiverComponent;
    p_mStimulusReceiverComponent->mPrev = p_mStimulusReceiverComponent;
    goto LABEL_15;
  }
  if ( this->mStimulusReceiverComponent.m_pSimObject
    && (p_mStimulusReceiverComponent->mPrev != p_mStimulusReceiverComponent
     || this->mStimulusReceiverComponent.mNext != &this->mStimulusReceiverComponent) )
  {
    v13 = p_mStimulusReceiverComponent->mPrev;
    v14 = this->mStimulusReceiverComponent.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    goto LABEL_14;
  }
LABEL_15:
  this->mStimulusReceiverComponent.m_Changed = 1;
  this->mStimulusReceiverComponent.m_pSimObject = pObject;
  this->mStimulusReceiverComponent.m_TypeUID = UFG::StimulusReceiverComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::StimulusReceiverComponent,0>::BindInternal<UFG::SimObject>(
    &this->mStimulusReceiverComponent,
    pObject);
  m_pSimObject = this->m_pSimObject;
  if ( m_pSimObject )
  {
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      m_pComponent = (UFG::AIActionTreeComponent *)m_pSimObject->m_Components.p[19].m_pComponent;
    }
    else if ( (m_Flags & 0x2000) != 0 )
    {
      vfptr = (unsigned int)m_pSimObject[1].vfptr;
      size = m_pSimObject->m_Components.size;
      if ( vfptr < size )
      {
        v19 = (__int64)&m_pSimObject->m_Components.p[vfptr];
        while ( (*(_DWORD *)(v19 + 8) & 0xFE000000) != (UFG::AIActionTreeComponent::_TypeUID & 0xFE000000)
             || (UFG::AIActionTreeComponent::_TypeUID & ~*(_DWORD *)(v19 + 8) & 0x1FFFFFF) != 0 )
        {
          ++vfptr;
          v19 += 16i64;
          if ( vfptr >= size )
            goto LABEL_35;
        }
LABEL_26:
        m_pComponent = *(UFG::AIActionTreeComponent **)v19;
      }
    }
    else
    {
      if ( (m_Flags & 0x1000) == 0 )
      {
        m_pComponent = (UFG::AIActionTreeComponent *)UFG::SimObject::GetComponentOfType(
                                                       m_pSimObject,
                                                       UFG::AIActionTreeComponent::_TypeUID);
        goto LABEL_35;
      }
      v20 = (unsigned int)m_pSimObject[1].vfptr;
      v21 = m_pSimObject->m_Components.size;
      if ( v20 < v21 )
      {
        v19 = (__int64)&m_pSimObject->m_Components.p[v20];
        while ( (*(_DWORD *)(v19 + 8) & 0xFE000000) != (UFG::AIActionTreeComponent::_TypeUID & 0xFE000000)
             || (UFG::AIActionTreeComponent::_TypeUID & ~*(_DWORD *)(v19 + 8) & 0x1FFFFFF) != 0 )
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
  UFG::AIActionTreeComponent::EnsureTicketBoothCriticalPriority(m_pComponent);
  UFG::FaceActionComponent::SetInitialState(this);
}

// File Line: 278
// RVA: 0x5423D0
char __fastcall UFG::FaceActionComponent::OpenConfirmationDialog(UFG::FaceActionComponent *this)
{
  UFG::UIHKScreenGlobalOverlay *Instance; // rax
  UFG::UIScreen *v3; // rbx
  const char *mConfirmationBoxText; // r8

  *((_BYTE *)this + 204) &= ~2u;
  Instance = UFG::UIHKScreenGlobalOverlay::getInstance();
  v3 = Instance;
  if ( !Instance || Instance->m_skookum_dialog_active )
    return 0;
  UFG::UIHKScreenGlobalOverlay::StartSkookumDialog(Instance);
  mConfirmationBoxText = "Are you sure?";
  if ( this->mConfirmationBoxText )
    mConfirmationBoxText = this->mConfirmationBoxText;
  UFG::UIScreenDialogBox::createYesNoDialog(v3, "Social Confirmation Dialog", mConfirmationBoxText, 0, 0);
  return 1;
}

// File Line: 298
// RVA: 0x539F90
char __fastcall UFG::FaceActionComponent::IsConfirmationDialogComplete(UFG::FaceActionComponent *this)
{
  UFG::UIHKScreenGlobalOverlay *Instance; // rax
  unsigned int m_skookum_dialog_result; // ebx

  Instance = UFG::UIHKScreenGlobalOverlay::getInstance();
  if ( !Instance || !Instance->m_skookum_dialog_active || !Instance->m_skookum_dialog_finished )
    return 0;
  m_skookum_dialog_result = Instance->m_skookum_dialog_result;
  UFG::UIHKScreenGlobalOverlay::FinishSkookumDialog(Instance);
  *((_BYTE *)this + 204) &= ~2u;
  *((_BYTE *)this + 204) |= 2 * (m_skookum_dialog_result == UI_HASH_DIALOG_YES_25);
  return 1;
}

// File Line: 314
// RVA: 0x52E060
char *__fastcall UFG::FaceActionComponent::GetItemDescription(UFG::FaceActionComponent *this)
{
  UFG::SimObject *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfType; // rbx
  unsigned int v5; // edx
  unsigned int v6; // r8d
  __int64 v7; // rbx
  unsigned int vfptr; // edx
  unsigned int size; // r8d
  unsigned int v10; // edx
  unsigned int v11; // r8d
  __int64 v12; // rax
  int BuffLevel; // eax

  m_pSimObject = this->m_pSimObject;
  if ( !m_pSimObject )
    return 0i64;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) == 0 )
  {
    if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        vfptr = (unsigned int)m_pSimObject[1].vfptr;
        size = m_pSimObject->m_Components.size;
        if ( vfptr < size )
        {
          v7 = (__int64)&m_pSimObject->m_Components.p[vfptr];
          while ( (*(_DWORD *)(v7 + 8) & 0xFE000000) != (UFG::InventoryComponent::_TypeUID & 0xFE000000)
               || (UFG::InventoryComponent::_TypeUID & ~*(_DWORD *)(v7 + 8) & 0x1FFFFFF) != 0 )
          {
            ++vfptr;
            v7 += 16i64;
            if ( vfptr >= size )
            {
              ComponentOfType = 0i64;
              goto LABEL_27;
            }
          }
          goto LABEL_11;
        }
      }
      else
      {
        if ( (m_Flags & 0x1000) == 0 )
        {
          ComponentOfType = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::InventoryComponent::_TypeUID);
          goto LABEL_27;
        }
        v10 = (unsigned int)m_pSimObject[1].vfptr;
        v11 = m_pSimObject->m_Components.size;
        if ( v10 < v11 )
        {
          v7 = (__int64)&m_pSimObject->m_Components.p[v10];
          while ( (*(_DWORD *)(v7 + 8) & 0xFE000000) != (UFG::InventoryComponent::_TypeUID & 0xFE000000)
               || (UFG::InventoryComponent::_TypeUID & ~*(_DWORD *)(v7 + 8) & 0x1FFFFFF) != 0 )
          {
            ++v10;
            v7 += 16i64;
            if ( v10 >= v11 )
            {
              ComponentOfType = 0i64;
              goto LABEL_27;
            }
          }
          goto LABEL_11;
        }
      }
    }
    else
    {
      v5 = (unsigned int)m_pSimObject[1].vfptr;
      v6 = m_pSimObject->m_Components.size;
      if ( v5 < v6 )
      {
        v7 = (__int64)&m_pSimObject->m_Components.p[v5];
        while ( (*(_DWORD *)(v7 + 8) & 0xFE000000) != (UFG::InventoryComponent::_TypeUID & 0xFE000000)
             || (UFG::InventoryComponent::_TypeUID & ~*(_DWORD *)(v7 + 8) & 0x1FFFFFF) != 0 )
        {
          ++v5;
          v7 += 16i64;
          if ( v5 >= v6 )
            goto LABEL_10;
        }
LABEL_11:
        ComponentOfType = *(UFG::SimComponent **)v7;
        goto LABEL_27;
      }
    }
LABEL_10:
    ComponentOfType = 0i64;
    goto LABEL_27;
  }
  ComponentOfType = m_pSimObject->m_Components.p[39].m_pComponent;
LABEL_27:
  if ( !ComponentOfType )
    return 0i64;
  v12 = *(int *)&ComponentOfType[14].m_Flags;
  if ( !(_DWORD)v12 )
    return 0i64;
  BuffLevel = UFG::PlayerBuffTracker::GetBuffLevel(UFG::ItemProfiles::mpInstance->mProfiles[v12].mDescriptionBuff);
  if ( BuffLevel == -1 )
    return this->mItemDescription;
  else
    return (char *)UFG::ItemProfiles::GetDescription(
                     (UFG::eInventoryItemEnum)*(_DWORD *)&ComponentOfType[14].m_Flags,
                     BuffLevel);
}

// File Line: 338
// RVA: 0x542EA0
void __fastcall UFG::FaceActionComponent::ProcessIconLogic(UFG::FaceActionComponent *this)
{
  const char *mItemIcon; // rcx
  bool v3; // si
  bool v4; // di
  bool v5; // al
  char *v6; // r8
  UFG::eFaceActionEnum mCurrentFaceAction; // eax
  UFG::SimObject *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  int mCost; // esi
  UFG::InventoryComponent *m_pComponent; // rdi
  unsigned int v12; // edx
  unsigned int v13; // r8d
  __int64 v14; // rdi
  unsigned int vfptr; // edx
  unsigned int size; // r8d
  unsigned int v17; // edx
  unsigned int v18; // r8d
  UFG::eInventoryItemEnum m_SellableItem; // eax
  char *Captioning; // rax
  char *Name; // rax
  char *Description; // rax
  __int64 mInventoryItem; // rax
  int m_iQuantity; // eax
  UFG::qSymbol result; // [rsp+30h] [rbp+8h] BYREF

  mItemIcon = this->mItemIcon;
  if ( mItemIcon )
  {
    v3 = (unsigned int)UFG::qStringCompareInsensitive(mItemIcon, "boat", -1) == 0;
    v4 = (unsigned int)UFG::qStringCompareInsensitive(this->mItemIcon, "vehicle", -1) == 0;
    v5 = (unsigned int)UFG::qStringCompareInsensitive(this->mItemIcon, "clothing", -1) == 0;
    if ( v3 || v4 || v5 )
    {
      UFG::qStringCopy(this->mItemName, 0x7FFFFFFF, &customCaption, -1);
      if ( v3 || v4 )
      {
        v6 = "$SOCIAL_PARKING_ATTENDANT";
        if ( this->mCurrentFaceAction != eFACEACTION_ACCESS_STORAGE )
          v6 = "$SOCIAL_VEHICLE_VENDOR";
      }
      else
      {
        v6 = "$SOCIAL_PURCHASE_HOLD";
      }
      UFG::qStringCopy(this->mItemCaption, 0x7FFFFFFF, v6, -1);
      *((_BYTE *)this + 204) &= ~0x20u;
    }
  }
  mCurrentFaceAction = this->mCurrentFaceAction;
  switch ( mCurrentFaceAction )
  {
    case eFACEACTION_PURCHASE:
      if ( !this->mItemVendor )
        break;
      m_pSimObject = this->m_pSimObject;
      if ( !m_pSimObject )
        break;
      m_Flags = m_pSimObject->m_Flags;
      mCost = 0;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = (UFG::InventoryComponent *)m_pSimObject->m_Components.p[39].m_pComponent;
        goto LABEL_39;
      }
      if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 )
        {
          vfptr = (unsigned int)m_pSimObject[1].vfptr;
          size = m_pSimObject->m_Components.size;
          if ( vfptr < size )
          {
            v14 = (__int64)&m_pSimObject->m_Components.p[vfptr];
            while ( (*(_DWORD *)(v14 + 8) & 0xFE000000) != (UFG::InventoryComponent::_TypeUID & 0xFE000000)
                 || (UFG::InventoryComponent::_TypeUID & ~*(_DWORD *)(v14 + 8) & 0x1FFFFFF) != 0 )
            {
              ++vfptr;
              v14 += 16i64;
              if ( vfptr >= size )
              {
                m_pComponent = 0i64;
                goto LABEL_39;
              }
            }
            goto LABEL_23;
          }
        }
        else
        {
          if ( (m_Flags & 0x1000) == 0 )
          {
            m_pComponent = (UFG::InventoryComponent *)UFG::SimObject::GetComponentOfType(
                                                        m_pSimObject,
                                                        UFG::InventoryComponent::_TypeUID);
LABEL_39:
            if ( m_pComponent )
            {
              UFG::FaceActionComponent::SetIcon(this, m_pComponent->m_SellableItem);
              m_SellableItem = m_pComponent->m_SellableItem;
              if ( (unsigned int)(this->mInventoryItem - 163) > 0x13 )
              {
                if ( m_SellableItem )
                  mCost = UFG::ItemProfiles::mpInstance->mProfiles[m_pComponent->m_SellableItem].mCost;
                mCost = (int)UFG::StoreFrontTracker::GetItemPriceBasedOnClothes((float)mCost);
              }
              else if ( m_SellableItem )
              {
                mCost = UFG::ItemProfiles::mpInstance->mProfiles[m_pComponent->m_SellableItem].mCost;
              }
              this->mItemPrice = mCost;
              Captioning = (char *)UFG::ItemProfiles::GetCaptioning(m_pComponent->m_SellableItem);
              UFG::qStringCopy(this->mItemCaption, 0x7FFFFFFF, Captioning, -1);
              Name = (char *)UFG::ItemProfiles::GetName(m_pComponent->m_SellableItem);
              UFG::qStringCopy(this->mItemName, 0x7FFFFFFF, Name, -1);
              Description = (char *)UFG::ItemProfiles::GetDescription(m_pComponent->m_SellableItem, 0);
              UFG::qStringCopy(this->mItemDescription, 0x7FFFFFFF, Description, -1);
              mInventoryItem = this->mInventoryItem;
              if ( m_pComponent->m_InfiniteSellableItem && (_DWORD)mInventoryItem == m_pComponent->m_SellableItem )
                m_iQuantity = 1;
              else
                m_iQuantity = m_pComponent->m_InventoryItems[mInventoryItem].m_iQuantity;
              this->mItemQuantity = m_iQuantity;
              this->mItemProp = (UFG::qSymbol)UFG::InventoryComponent::GetSellableItemProp(m_pComponent, &result)->mUID;
            }
            break;
          }
          v17 = (unsigned int)m_pSimObject[1].vfptr;
          v18 = m_pSimObject->m_Components.size;
          if ( v17 < v18 )
          {
            v14 = (__int64)&m_pSimObject->m_Components.p[v17];
            while ( (*(_DWORD *)(v14 + 8) & 0xFE000000) != (UFG::InventoryComponent::_TypeUID & 0xFE000000)
                 || (UFG::InventoryComponent::_TypeUID & ~*(_DWORD *)(v14 + 8) & 0x1FFFFFF) != 0 )
            {
              ++v17;
              v14 += 16i64;
              if ( v17 >= v18 )
              {
                m_pComponent = 0i64;
                goto LABEL_39;
              }
            }
            goto LABEL_23;
          }
        }
      }
      else
      {
        v12 = (unsigned int)m_pSimObject[1].vfptr;
        v13 = m_pSimObject->m_Components.size;
        if ( v12 < v13 )
        {
          v14 = (__int64)&m_pSimObject->m_Components.p[v12];
          while ( (*(_DWORD *)(v14 + 8) & 0xFE000000) != (UFG::InventoryComponent::_TypeUID & 0xFE000000)
               || (UFG::InventoryComponent::_TypeUID & ~*(_DWORD *)(v14 + 8) & 0x1FFFFFF) != 0 )
          {
            ++v12;
            v14 += 16i64;
            if ( v12 >= v13 )
              goto LABEL_22;
          }
LABEL_23:
          m_pComponent = *(UFG::InventoryComponent **)v14;
          goto LABEL_39;
        }
      }
LABEL_22:
      m_pComponent = 0i64;
      goto LABEL_39;
    case eFACEACTION_ESCORT:
      this->mItemIcon = "ally";
      strcpy(this->mItemCaption, "$eFACEACTION_ESCORT");
      break;
    case eFACEACTION_FIGHT_CLUB:
      this->mItemIcon = "intimidate";
      strcpy(this->mItemCaption, "$eFACEACTION_FIGHT_CLUB");
      break;
    case eFACEACTION_BUZZER_INTERACT:
      this->mItemIcon = "harass";
      strcpy(this->mItemCaption, "$eFACEACTION_BUZZER_INTERACT");
      break;
    case eFACEACTION_HARASS:
      this->mItemIcon = "harass";
      strcpy(this->mItemCaption, "$SOCIAL_HARASS");
      break;
    default:
      if ( mCurrentFaceAction )
      {
        switch ( mCurrentFaceAction )
        {
          case eFACEACTION_FAVOR:
          case eFACEACTION_FAVOR_PACKAGE:
            goto LABEL_70;
          case eFACEACTION_DELIVER_PACKAGE:
            this->mItemIcon = "help";
            strcpy(this->mItemCaption, "$SOCIAL_DELIVER_PACKAGE");
            goto LABEL_78;
          case eFACEACTION_FLIRT:
            this->mItemIcon = "invite";
            strcpy(this->mItemCaption, "$SOCIAL_FLIRT");
            goto LABEL_78;
          case eFACEACTION_KISS:
            this->mItemIcon = "kiss";
            strcpy(this->mItemCaption, "$SOCIAL_KISS");
            goto LABEL_78;
          case eFACEACTION_OFFER_HELP:
LABEL_70:
            this->mItemIcon = "help";
            strcpy(this->mItemCaption, "$SOCIAL_OFFER_HELP");
            goto LABEL_78;
          case eFACEACTION_ALLY:
            this->mItemIcon = "ally";
            strcpy(this->mItemCaption, "$SOCIAL_ALLY");
            break;
          case eFACEACTION_INVITE:
            this->mItemIcon = "flirt";
            strcpy(this->mItemCaption, "$SOCIAL_INVITE");
            break;
          case eFACEACTION_DELIVER_MONEY:
          case eFACEACTION_INFORMANT:
            this->mItemIcon = "informant";
            strcpy(this->mItemCaption, "$SOCIAL_INFORMANT");
            break;
        }
      }
      else
      {
        this->mItemIcon = "charm";
        strcpy(this->mItemCaption, "$SOCIAL_CHARM");
      }
      break;
  }
LABEL_78:
  UFG::FaceActionComponent::ProcessPreGreetIconLogic(this, 1);
}

// File Line: 467
// RVA: 0x53C610
void __fastcall UFG::FaceActionComponent::KillEffect(UFG::FaceActionComponent *this)
{
  UFG::SimObject *m_pSimObject; // rcx
  Render::FXSimComponent *ComponentOfType; // rax
  __int16 m_Flags; // dx
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  __int64 v7; // rdx
  unsigned int v8; // r8d
  unsigned int v9; // r9d
  unsigned int v10; // r8d
  unsigned int v11; // r9d
  unsigned int v12; // r8d
  unsigned int v13; // r9d
  Render::FXOverride *m_pPointer; // rax
  Render::FXOverride *v15; // rbx

  if ( this->mEffectHandle == -1 )
    return;
  m_pSimObject = this->m_pSimObject;
  if ( !m_pSimObject )
    goto LABEL_3;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    vfptr = (unsigned int)m_pSimObject[1].vfptr;
    size = m_pSimObject->m_Components.size;
    if ( vfptr < size )
    {
      v7 = (__int64)&m_pSimObject->m_Components.p[vfptr];
      while ( (*(_DWORD *)(v7 + 8) & 0xFE000000) != (Render::FXSimComponent::_TypeUID & 0xFE000000)
           || (Render::FXSimComponent::_TypeUID & ~*(_DWORD *)(v7 + 8) & 0x1FFFFFF) != 0 )
      {
        ++vfptr;
        v7 += 16i64;
        if ( vfptr >= size )
        {
          ComponentOfType = 0i64;
          goto LABEL_34;
        }
      }
LABEL_11:
      ComponentOfType = *(Render::FXSimComponent **)v7;
      goto LABEL_34;
    }
    goto LABEL_3;
  }
  if ( m_Flags < 0 )
  {
    v8 = (unsigned int)m_pSimObject[1].vfptr;
    v9 = m_pSimObject->m_Components.size;
    if ( v8 < v9 )
    {
      v7 = (__int64)&m_pSimObject->m_Components.p[v8];
      while ( (*(_DWORD *)(v7 + 8) & 0xFE000000) != (Render::FXSimComponent::_TypeUID & 0xFE000000)
           || (Render::FXSimComponent::_TypeUID & ~*(_DWORD *)(v7 + 8) & 0x1FFFFFF) != 0 )
      {
        ++v8;
        v7 += 16i64;
        if ( v8 >= v9 )
        {
          ComponentOfType = 0i64;
          goto LABEL_34;
        }
      }
      goto LABEL_11;
    }
LABEL_3:
    ComponentOfType = 0i64;
    goto LABEL_34;
  }
  if ( (m_Flags & 0x2000) != 0 )
  {
    v10 = (unsigned int)m_pSimObject[1].vfptr;
    v11 = m_pSimObject->m_Components.size;
    if ( v10 < v11 )
    {
      v7 = (__int64)&m_pSimObject->m_Components.p[v10];
      while ( (*(_DWORD *)(v7 + 8) & 0xFE000000) != (Render::FXSimComponent::_TypeUID & 0xFE000000)
           || (Render::FXSimComponent::_TypeUID & ~*(_DWORD *)(v7 + 8) & 0x1FFFFFF) != 0 )
      {
        ++v10;
        v7 += 16i64;
        if ( v10 >= v11 )
        {
          ComponentOfType = 0i64;
          goto LABEL_34;
        }
      }
      goto LABEL_11;
    }
    goto LABEL_3;
  }
  if ( (m_Flags & 0x1000) != 0 )
  {
    v12 = (unsigned int)m_pSimObject[1].vfptr;
    v13 = m_pSimObject->m_Components.size;
    if ( v12 < v13 )
    {
      v7 = (__int64)&m_pSimObject->m_Components.p[v12];
      while ( (*(_DWORD *)(v7 + 8) & 0xFE000000) != (Render::FXSimComponent::_TypeUID & 0xFE000000)
           || (Render::FXSimComponent::_TypeUID & ~*(_DWORD *)(v7 + 8) & 0x1FFFFFF) != 0 )
      {
        ++v12;
        v7 += 16i64;
        if ( v12 >= v13 )
        {
          ComponentOfType = 0i64;
          goto LABEL_34;
        }
      }
      goto LABEL_11;
    }
    goto LABEL_3;
  }
  ComponentOfType = (Render::FXSimComponent *)UFG::SimObject::GetComponentOfType(
                                                m_pSimObject,
                                                Render::FXSimComponent::_TypeUID);
LABEL_34:
  Render::FXSimComponent::DetachEffect(ComponentOfType, this->mEffectHandle, FXKILLOPTION_ERASE_EMITTED_OBJECTS);
  this->mEffectHandle = -1;
  m_pPointer = this->mEffectOverride.m_pPointer;
  if ( m_pPointer )
  {
    --m_pPointer->mReferenceCount;
    v15 = this->mEffectOverride.m_pPointer;
    if ( v15->mReferenceCount <= 0 )
    {
      if ( v15 )
      {
        Render::FXOverride::~FXOverride(this->mEffectOverride.m_pPointer);
        operator delete[](v15);
      }
      this->mEffectOverride.m_pPointer = 0i64;
    }
    this->mEffectOverride.m_pPointer = 0i64;
  }
}ator delete[](v15);
      }
      this->mEffectOverride.m_pPointer = 0i64;
 

// File Line: 480
// RVA: 0x5435B0
void __fastcall UFG::FaceActionComponent::ProcessPreGreetIconLogic(
        UFG::FaceActionComponent *this,
        bool bTakeNISIntoConsideration)
{
  char v4; // al
  char v5; // dl
  UFG::eFaceActionState mState; // eax
  UFG::SimObject *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  unsigned int vfptr; // edx
  unsigned int size; // r9d
  UFG::SimComponentHolder *p; // rbx
  __int64 v12; // r8
  Render::FXSimComponent *m_pComponent; // rsi
  unsigned int v14; // edx
  unsigned int v15; // r9d
  unsigned int v16; // edx
  unsigned int v17; // r9d
  unsigned int v18; // edx
  unsigned int v19; // r9d
  UFG::SimObject *v20; // r8
  __int16 v21; // dx
  UFG::CharacterAnimationComponent *v22; // rcx
  UFG::CharacterAnimationComponent *ComponentOfType; // rax
  unsigned int v24; // edx
  unsigned int v25; // r9d
  UFG::SimComponentHolder *v26; // rbx
  Creature *mCreature; // rcx
  int BoneID; // ebp
  UFG::allocator::free_link *Override; // rax

  UFG::FaceActionComponent::KillEffect(this);
  if ( !bTakeNISIntoConsideration || NISManager::GetInstance()->mState == STATE_INVALID )
  {
    v4 = *((_BYTE *)this + 812);
    v5 = v4 & 1;
    if ( ((v4 & 1) != 0 || this->mMinigameSetup) && (*((_BYTE *)this + 204) & 8) == 0 && (v4 & 2) == 0 )
      strcpy(this->mItemCaption, "$SOCIAL_GREET");
    if ( (this->mbForceIconOn
       || (mState = this->mState) == eFACE_ACTION_STATE_WAITING_FOR_GREET && (v5 || this->mMinigameSetup)
       || mState == eFACE_ACTION_STATE_WAITING_FOR_CHARGE && !v5 && !this->mMinigameSetup)
      && this->mSocialEffectHash != -1
      && this->mEffectHandle == -1 )
    {
      if ( (_S22_0 & 1) == 0 )
      {
        _S22_0 |= 1u;
        UFG::qSymbolUC::create_from_string(&symHead, "Bip01 Head");
        atexit(UFG::FaceActionComponent::ProcessPreGreetIconLogic_::_13_::_dynamic_atexit_destructor_for__symHead__);
      }
      m_pSimObject = this->m_pSimObject;
      if ( m_pSimObject )
      {
        m_Flags = m_pSimObject->m_Flags;
        if ( (m_Flags & 0x4000) != 0 )
        {
          vfptr = (unsigned int)m_pSimObject[1].vfptr;
          size = m_pSimObject->m_Components.size;
          if ( vfptr < size )
          {
            p = m_pSimObject->m_Components.p;
            while ( 1 )
            {
              v12 = vfptr;
              if ( (p[vfptr].m_TypeUID & 0xFE000000) == (Render::FXSimComponent::_TypeUID & 0xFE000000)
                && (Render::FXSimComponent::_TypeUID & ~p[vfptr].m_TypeUID & 0x1FFFFFF) == 0 )
              {
                break;
              }
              if ( ++vfptr >= size )
                goto LABEL_28;
            }
LABEL_27:
            m_pComponent = (Render::FXSimComponent *)p[v12].m_pComponent;
LABEL_51:
            if ( !m_pComponent )
              return;
            v20 = this->m_pSimObject;
            if ( !v20 )
              return;
            v21 = v20->m_Flags;
            if ( (v21 & 0x4000) != 0 )
            {
              v22 = (UFG::CharacterAnimationComponent *)v20->m_Components.p[9].m_pComponent;
              if ( v22
                && ((UFG::CharacterAnimationComponent::_TypeUID ^ v22->m_TypeUID) & 0xFE000000) == 0
                && (UFG::CharacterAnimationComponent::_TypeUID & ~v22->m_TypeUID & 0x1FFFFFF) == 0 )
              {
LABEL_75:
                if ( v22 )
                {
                  mCreature = v22->mCreature;
                  if ( mCreature )
                  {
                    if ( mCreature->mPose.mRigHandle.mData )
                      BoneID = Skeleton::GetBoneID(mCreature->mPose.mRigHandle.mUFGSkeleton, symHead.mUID);
                    else
                      BoneID = -1;
                    Override = Render::FXOverride::CreateOverride("FaceActionComponent", 0i64);
                    FX::SharedPointer<Render::FXOverride>::Set(&this->mEffectOverride, (Render::FXOverride *)Override);
                    this->mEffectHandle = Render::FXSimComponent::AttachEffect(
                                            m_pComponent,
                                            this->mSocialEffectHash,
                                            BoneID,
                                            0i64);
                  }
                }
                return;
              }
LABEL_57:
              v22 = 0i64;
              goto LABEL_75;
            }
            if ( v21 < 0 )
            {
              v22 = (UFG::CharacterAnimationComponent *)v20->m_Components.p[9].m_pComponent;
              if ( v22 && ((UFG::CharacterAnimationComponent::_TypeUID ^ v22->m_TypeUID) & 0xFE000000) == 0 )
              {
                if ( (UFG::CharacterAnimationComponent::_TypeUID & ~v22->m_TypeUID & 0x1FFFFFF) != 0 )
                  v22 = 0i64;
                goto LABEL_75;
              }
              goto LABEL_57;
            }
            if ( (v21 & 0x2000) != 0 )
            {
              ComponentOfType = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)this->m_pSimObject);
            }
            else
            {
              if ( (v21 & 0x1000) != 0 )
              {
                v24 = (unsigned int)v20[1].vfptr;
                v25 = v20->m_Components.size;
                if ( v24 < v25 )
                {
                  v26 = v20->m_Components.p;
                  while ( (v26[v24].m_TypeUID & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
                       || (UFG::CharacterAnimationComponent::_TypeUID & ~v26[v24].m_TypeUID & 0x1FFFFFF) != 0 )
                  {
                    if ( ++v24 >= v25 )
                      goto LABEL_57;
                  }
                  v22 = (UFG::CharacterAnimationComponent *)v26[v24].m_pComponent;
                  goto LABEL_75;
                }
                goto LABEL_57;
              }
              ComponentOfType = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                                      this->m_pSimObject,
                                                                      UFG::CharacterAnimationComponent::_TypeUID);
            }
            v22 = ComponentOfType;
            goto LABEL_75;
          }
        }
        else if ( m_Flags >= 0 )
        {
          if ( (m_Flags & 0x2000) != 0 )
          {
            v16 = (unsigned int)m_pSimObject[1].vfptr;
            v17 = m_pSimObject->m_Components.size;
            if ( v16 < v17 )
            {
              p = m_pSimObject->m_Components.p;
              do
              {
                v12 = v16;
                if ( (p[v16].m_TypeUID & 0xFE000000) == (Render::FXSimComponent::_TypeUID & 0xFE000000)
                  && (Render::FXSimComponent::_TypeUID & ~p[v16].m_TypeUID & 0x1FFFFFF) == 0 )
                {
                  goto LABEL_27;
                }
              }
              while ( ++v16 < v17 );
            }
          }
          else
          {
            if ( (m_Flags & 0x1000) == 0 )
            {
              m_pComponent = (Render::FXSimComponent *)UFG::SimObject::GetComponentOfType(
                                                         m_pSimObject,
                                                         Render::FXSimComponent::_TypeUID);
              goto LABEL_51;
            }
            v18 = (unsigned int)m_pSimObject[1].vfptr;
            v19 = m_pSimObject->m_Components.size;
            if ( v18 < v19 )
            {
              p = m_pSimObject->m_Components.p;
              do
              {
                v12 = v18;
                if ( (p[v18].m_TypeUID & 0xFE000000) == (Render::FXSimComponent::_TypeUID & 0xFE000000)
                  && (Render::FXSimComponent::_TypeUID & ~p[v18].m_TypeUID & 0x1FFFFFF) == 0 )
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
          v14 = (unsigned int)m_pSimObject[1].vfptr;
          v15 = m_pSimObject->m_Components.size;
          if ( v14 < v15 )
          {
            p = m_pSimObject->m_Components.p;
            do
            {
              v12 = v14;
              if ( (p[v14].m_TypeUID & 0xFE000000) == (Render::FXSimComponent::_TypeUID & 0xFE000000)
                && (Render::FXSimComponent::_TypeUID & ~p[v14].m_TypeUID & 0x1FFFFFF) == 0 )
              {
                goto LABEL_27;
              }
            }
            while ( ++v14 < v15 );
          }
        }
LABEL_28:
        m_pComponent = 0i64;
        goto LABEL_51;
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
    case eINVENTORY_ITEM_PORK_BUN:
    case eINVENTORY_ITEM_FOODONSTICK_A:
    case eINVENTORY_ITEM_FOODONSTICK_B:
    case eINVENTORY_ITEM_NOODLE_BOWL:
    case eINVENTORY_ITEM_NOODLE_BOX:
    case eINVENTORY_ITEM_ICE_CREAM:
      this->mItemIcon = "porkbun";
      break;
    case eINVENTORY_ITEM_ENERGY_DRINK:
    case eINVENTORY_ITEM_COCKTAIL:
      this->mItemIcon = "drink";
      break;
    case eINVENTORY_ITEM_HAPPY_ENDING:
      this->mItemIcon = "massage";
      break;
    case eINVENTORY_ITEM_HERBAL_TEA:
      this->mItemIcon = "tea";
      break;
    case eINVENTORY_ITEM_PISTOL_SERVICE:
    case eINVENTORY_ITEM_PISTOL_45CAL:
    case eINVENTORY_ITEM_RIFLE_ASSAUL_TAC:
    case eINVENTORY_ITEM_RIFLE_ASSAULT:
    case eINVENTORY_ITEM_RIFLE_ASSAULT_DLC:
    case eINVENTORY_ITEM_SHOTGUN_ANTI_TAC:
    case eINVENTORY_ITEM_SMG_45CAL_TACLIG:
      this->mItemIcon = "gun";
      break;
    case eINVENTORY_ITEM_DEED_AB_01:
    case eINVENTORY_ITEM_DEED_KT_01:
    case eINVENTORY_ITEM_DEED_CN_01:
    case eINVENTORY_ITEM_M_APT_CENTRAL:
    case eINVENTORY_ITEM_M_APT_ABERDEEN:
    case eINVENTORY_ITEM_M_APT_KENNEDY:
      this->mItemIcon = "realestate";
      break;
    case eINVENTORY_ITEM_BRIBE_CHEAP:
    case eINVENTORY_ITEM_BRIBE_AVERAGE:
    case eINVENTORY_ITEM_BRIBE_EXPENSIVE:
      this->mItemIcon = "bribe";
      break;
    case eINVENTORY_ITEM_EXTORT_CHEAP:
    case eINVENTORY_ITEM_EXTORT_AVERAGE:
    case eINVENTORY_ITEM_EXTORT_EXPENSIVE:
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
  UFG::RebindingComponentHandle<UFG::TargetingSystemBaseComponent,0> *p_mTargetingSystemBaseComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::RebindingComponentHandle<UFG::StimulusReceiverComponent,0> *p_mStimulusReceiverComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax

  p_mTargetingSystemBaseComponent = &this->mTargetingSystemBaseComponent;
  if ( this->mTargetingSystemBaseComponent.m_pSimComponent )
  {
    mPrev = p_mTargetingSystemBaseComponent->mPrev;
    mNext = this->mTargetingSystemBaseComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mTargetingSystemBaseComponent.m_pSimComponent = 0i64;
LABEL_7:
    p_mTargetingSystemBaseComponent->m_pSimObject = 0i64;
    p_mTargetingSystemBaseComponent->mNext = p_mTargetingSystemBaseComponent;
    p_mTargetingSystemBaseComponent->mPrev = p_mTargetingSystemBaseComponent;
    goto LABEL_8;
  }
  if ( this->mTargetingSystemBaseComponent.m_pSimObject
    && (p_mTargetingSystemBaseComponent->mPrev != p_mTargetingSystemBaseComponent
     || this->mTargetingSystemBaseComponent.mNext != &this->mTargetingSystemBaseComponent) )
  {
    v5 = p_mTargetingSystemBaseComponent->mPrev;
    v6 = p_mTargetingSystemBaseComponent->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    goto LABEL_7;
  }
LABEL_8:
  p_mStimulusReceiverComponent = &this->mStimulusReceiverComponent;
  p_mTargetingSystemBaseComponent->m_Changed = 1;
  if ( this->mStimulusReceiverComponent.m_pSimComponent )
  {
    v8 = p_mStimulusReceiverComponent->mPrev;
    v9 = this->mStimulusReceiverComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    this->mStimulusReceiverComponent.m_pSimComponent = 0i64;
LABEL_14:
    this->mStimulusReceiverComponent.m_pSimObject = 0i64;
    this->mStimulusReceiverComponent.mNext = &this->mStimulusReceiverComponent;
    p_mStimulusReceiverComponent->mPrev = p_mStimulusReceiverComponent;
    goto LABEL_15;
  }
  if ( this->mStimulusReceiverComponent.m_pSimObject
    && (p_mStimulusReceiverComponent->mPrev != p_mStimulusReceiverComponent
     || this->mStimulusReceiverComponent.mNext != &this->mStimulusReceiverComponent) )
  {
    v10 = p_mStimulusReceiverComponent->mPrev;
    v11 = this->mStimulusReceiverComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    goto LABEL_14;
  }
LABEL_15:
  this->mStimulusReceiverComponent.m_Changed = 1;
  if ( this->mAnimationGroupHandleContainer.m_bHasBeenBound )
    AnimationGroupHandleContainer::Unbind(&this->mAnimationGroupHandleContainer);
  this->mCurrentIcon = ePipIcon_NONE;
  UFG::FaceActionComponent::KillEffect(this);
}

// File Line: 657
// RVA: 0x54F4D0
void __fastcall UFG::FaceActionComponent::SetupSocialForNIS(UFG::FaceActionComponent *this, bool bNISStarting)
{
  if ( bNISStarting )
  {
    if ( this->mEffectHandle != -1 )
      UFG::FaceActionComponent::KillEffect(this);
  }
  else if ( this->mEffectHandle == -1 )
  {
    UFG::FaceActionComponent::ProcessIconLogic(this);
    UFG::FaceActionComponent::ProcessPreGreetIconLogic(this, 0);
  }
}

// File Line: 669
// RVA: 0x560B50
void __fastcall UFG::FaceActionComponent::UpdateSocialIcon(UFG::FaceActionComponent *this)
{
  char v2; // al
  UFG::SimObject *m_pSimObject; // rsi
  UFG::TransformNodeComponent *v4; // rdi
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rsi
  float x; // xmm6_4
  __m128 y_low; // xmm8
  float z; // xmm7_4
  float mSocalIconMaxSizeDist; // xmm0_4
  float mSocalIconScalarMultiplier; // xmm2_4
  float v11; // xmm1_4
  float mSocalIconMinSizeDist; // xmm3_4
  Render::FXOverride *m_pPointer; // rax

  if ( !UFG::FaceActionComponent::IsFaceActionEnabled(this) )
    UFG::FaceActionComponent::KillEffect(this);
  if ( NISManager::GetInstance()->mState )
    goto LABEL_12;
  v2 = *((_BYTE *)this + 812);
  if ( ((v2 & 1) != 0 || this->mMinigameSetup) && (v2 & 2) != 0 )
    goto LABEL_12;
  if ( this->mEffectHandle == -1 )
  {
    if ( UFG::FaceActionComponent::IsFaceActionEnabled(this) )
    {
      UFG::FaceActionComponent::ProcessIconLogic(this);
    }
    else if ( !this->mbForceIconOn )
    {
      goto LABEL_12;
    }
    UFG::FaceActionComponent::ProcessPreGreetIconLogic(this, 0);
LABEL_12:
    if ( this->mEffectHandle == -1 )
      return;
  }
  m_pSimObject = this->m_pSimObject;
  v4 = 0i64;
  if ( m_pSimObject )
    m_pTransformNodeComponent = m_pSimObject->m_pTransformNodeComponent;
  else
    m_pTransformNodeComponent = 0i64;
  if ( LocalPlayer )
    v4 = LocalPlayer->m_pTransformNodeComponent;
  if ( m_pTransformNodeComponent && v4 )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
    x = m_pTransformNodeComponent->mWorldTransform.v3.x;
    y_low = (__m128)LODWORD(m_pTransformNodeComponent->mWorldTransform.v3.y);
    z = m_pTransformNodeComponent->mWorldTransform.v3.z;
    UFG::TransformNodeComponent::UpdateWorldTransform(v4);
    mSocalIconMaxSizeDist = this->mSocalIconMaxSizeDist;
    mSocalIconScalarMultiplier = *(float *)&FLOAT_1_0;
    y_low.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] - v4->mWorldTransform.v3.y)
                                      * (float)(y_low.m128_f32[0] - v4->mWorldTransform.v3.y))
                              + (float)((float)(x - v4->mWorldTransform.v3.x) * (float)(x - v4->mWorldTransform.v3.x)))
                      + (float)((float)(z - v4->mWorldTransform.v3.z) * (float)(z - v4->mWorldTransform.v3.z));
    v11 = _mm_sqrt_ps(y_low).m128_f32[0];
    if ( v11 < mSocalIconMaxSizeDist )
    {
      mSocalIconMinSizeDist = this->mSocalIconMinSizeDist;
      if ( v11 >= mSocalIconMinSizeDist )
        mSocalIconScalarMultiplier = (float)((float)((float)(v11 - mSocalIconMinSizeDist)
                                                   / (float)(mSocalIconMaxSizeDist - mSocalIconMinSizeDist))
                                           * (float)(this->mSocalIconScalarMultiplier - 1.0))
                                   + 1.0;
    }
    else
    {
      mSocalIconScalarMultiplier = this->mSocalIconScalarMultiplier;
    }
    m_pPointer = this->mEffectOverride.m_pPointer;
    if ( m_pPointer )
      m_pPointer->sizeScale = mSocalIconScalarMultiplier;
  }
}

// File Line: 719
// RVA: 0x53C1F0
bool __fastcall UFG::FaceActionComponent::IsTargetStandingSufficient(UFG::FaceActionComponent *this)
{
  UFG::SimObjectCharacter *v2; // rbx
  int mMininumRequirement; // ebx
  UFG::GameStatTracker *v4; // rax

  v2 = *(UFG::SimObjectCharacter **)(56i64
                                   * *(unsigned __int8 *)(*(_QWORD *)&this->mTargetingSystemBaseComponent.m_pSimComponent[1].m_Flags
                                                        + 58i64)
                                   + *(_QWORD *)&this->mTargetingSystemBaseComponent.m_pSimComponent[1].m_TypeUID
                                   + 40);
  if ( v2 != UFG::GetLocalPlayer() )
    return 0;
  mMininumRequirement = this->mMininumRequirement;
  v4 = UFG::GameStatTracker::Instance();
  return (int)UFG::GameStatTracker::GetFaceLevel(v4) >= mMininumRequirement;
}

// File Line: 735
// RVA: 0x52CCD0
__int64 __fastcall UFG::FaceActionComponent::GetFaceActionSuccessState(UFG::FaceActionComponent *this)
{
  UFG::eFaceActionState mState; // eax
  __int64 result; // rax

  mState = this->mState;
  if ( mState < eFACE_ACTION_STATE_GREET_INTERACTION_PLAYING )
    return 0i64;
  if ( mState <= eFACE_ACTION_STATE_WAITING_FOR_CHARGE )
    return 6 - (unsigned int)((*((_BYTE *)this + 812) & 2) != 0);
  if ( mState > eFACE_ACTION_STATE_COMPLETE )
    return 0i64;
  if ( (*((_BYTE *)this + 812) & 8) != 0 )
  {
    result = 1i64;
    if ( this->mMinigameSetup )
      return 3i64;
  }
  else
  {
    result = 2i64;
    if ( this->mMinigameSetup )
      return 4i64;
  }
  return result;
}

// File Line: 771
// RVA: 0x54E690
void __fastcall UFG::FaceActionComponent::SetState(UFG::FaceActionComponent *this, UFG::eFaceActionState e)
{
  UFG::eSocialInteractionResultEnum v2; // edi
  UFG::eFaceActionState mState; // eax
  bool IsTargetStandingSufficient; // al
  int v7; // edi
  unsigned int v8; // ecx
  UFG::AmbientConversation *DefaultConversation; // rax
  char v10; // al
  UFG::SimObject *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  unsigned int v14; // r8d
  unsigned int v15; // r9d
  __int64 v16; // rdx
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  unsigned int v19; // r8d
  unsigned int v20; // r9d
  UFG::GameStatTracker *v21; // rax
  signed int Stat; // eax
  char v23; // cl
  char v24; // al
  char v25; // al
  int v26; // eax
  unsigned int v27; // ecx
  UFG::AmbientConversation *v28; // rax
  int v29; // eax
  int v30; // eax

  v2 = eSOCIALINTERACTIONRESULT_SUCCESS;
  this->mConversationState = eSOCIAL_CONVERSATION_STATE_LOOPING;
  if ( e == eFACE_ACTION_STATE_WAITING_FOR_GREET )
  {
    *((_BYTE *)this + 812) &= ~2u;
    goto LABEL_99;
  }
  mState = this->mState;
  if ( mState == eFACE_ACTION_STATE_WAITING_FOR_GREET && e == eFACE_ACTION_STATE_WAITING_FOR_GREET_INTERACTION )
  {
    IsTargetStandingSufficient = UFG::FaceActionComponent::IsTargetStandingSufficient(this);
    *((_BYTE *)this + 812) &= ~2u;
    *((_BYTE *)this + 812) |= 2 * IsTargetStandingSufficient;
    v7 = 6 - ((*((_BYTE *)this + 812) & 2) != 0);
    v8 = this->mConversationReference[v7];
    if ( !v8 || !UFG::ConversationManager::GetConversation(v8) )
    {
      DefaultConversation = UFG::FaceActionComponent::GetDefaultConversation(
                              this,
                              (UFG::eSocialInteractionResultEnum)v7);
      if ( DefaultConversation )
        this->mConversationReference[v7] = DefaultConversation->mNode.mUID;
    }
    *((_BYTE *)this + 205) &= 0xFCu;
    goto LABEL_99;
  }
  if ( mState == eFACE_ACTION_STATE_WAITING_FOR_GREET_INTERACTION && e == eFACE_ACTION_STATE_GREET_INTERACTION_PLAYING )
  {
    UFG::FaceActionComponent::PlayConversation(
      this,
      (UFG::eSocialInteractionResultEnum)(6 - ((*((_BYTE *)this + 812) & 2) != 0)));
    goto LABEL_99;
  }
  if ( mState == eFACE_ACTION_STATE_GREET_INTERACTION_PLAYING && e == eFACE_ACTION_STATE_GREET_INTERACTION_COMPLETE )
  {
    UFG::FaceActionComponent::StopConversation(
      this,
      (UFG::eSocialInteractionResultEnum)(6 - ((*((_BYTE *)this + 812) & 2) != 0)));
    goto LABEL_99;
  }
  if ( mState == eFACE_ACTION_STATE_GREET_INTERACTION_COMPLETE && e == eFACE_ACTION_STATE_WAITING_FOR_CHARGE
    || mState == eFACE_ACTION_STATE_COMPLETE && e == eFACE_ACTION_STATE_WAITING_FOR_CHARGE
    || mState == eFACE_ACTION_STATE_WAITING_FOR_GREET && e == eFACE_ACTION_STATE_WAITING_FOR_CHARGE )
  {
    goto LABEL_24;
  }
  if ( mState == eFACE_ACTION_STATE_WAITING_FOR_CHARGE )
  {
    if ( e == eFACE_ACTION_STATE_WAITING_FOR_CHARGE )
    {
LABEL_24:
      if ( this->mMinigameSetup )
        this->mMinigameEnabled = 1;
      *((_BYTE *)this + 812) &= ~8u;
      goto LABEL_99;
    }
    if ( e == eFACE_ACTION_STATE_WAITING_FOR_CHARGE_INTERACTION )
    {
      if ( this->mMinigameSetup )
      {
        v10 = *((_BYTE *)this + 205);
        *((_BYTE *)this + 812) &= ~8u;
        this->mMinigameEnabled = 0;
        *((_BYTE *)this + 812) |= 8 * (v10 & 1);
LABEL_65:
        if ( (*((_BYTE *)this + 812) & 8) != 0 )
        {
          v26 = 3;
        }
        else
        {
          v2 = eSOCIALINTERACTIONRESULT_FAILURE;
          v26 = 4;
        }
        if ( this->mMinigameSetup )
          v2 = v26;
        v27 = this->mConversationReference[v2];
        if ( !v27 || !UFG::ConversationManager::GetConversation(v27) )
        {
          v28 = UFG::FaceActionComponent::GetDefaultConversation(this, v2);
          if ( v28 )
            this->mConversationReference[v2] = v28->mNode.mUID;
        }
        *((_BYTE *)this + 205) &= ~2u;
        goto LABEL_99;
      }
      if ( this->mCurrentFaceAction != eFACEACTION_PURCHASE )
      {
        *((_BYTE *)this + 812) |= 8u;
        goto LABEL_65;
      }
      m_pSimObject = this->m_pSimObject;
      if ( !m_pSimObject )
      {
LABEL_63:
        *((_BYTE *)this + 812) &= ~8u;
        goto LABEL_65;
      }
      m_Flags = m_pSimObject->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = m_pSimObject->m_Components.p[39].m_pComponent;
        goto LABEL_57;
      }
      if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 )
        {
          vfptr = (unsigned int)m_pSimObject[1].vfptr;
          size = m_pSimObject->m_Components.size;
          if ( vfptr < size )
          {
            v16 = (__int64)&m_pSimObject->m_Components.p[vfptr];
            while ( (*(_DWORD *)(v16 + 8) & 0xFE000000) != (UFG::InventoryComponent::_TypeUID & 0xFE000000)
                 || (UFG::InventoryComponent::_TypeUID & ~*(_DWORD *)(v16 + 8) & 0x1FFFFFF) != 0 )
            {
              ++vfptr;
              v16 += 16i64;
              if ( vfptr >= size )
              {
                m_pComponent = 0i64;
                goto LABEL_57;
              }
            }
            goto LABEL_41;
          }
        }
        else
        {
          if ( (m_Flags & 0x1000) == 0 )
          {
            m_pComponent = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::InventoryComponent::_TypeUID);
LABEL_57:
            if ( m_pComponent )
            {
              v21 = UFG::GameStatTracker::Instance();
              Stat = UFG::GameStatTracker::GetStat(v21, Money);
              *((_BYTE *)this + 812) &= ~8u;
              *((_BYTE *)this + 812) |= 8 * (Stat >= (signed int)this->mItemPrice);
              v23 = *((_BYTE *)this + 812);
              if ( (v23 & 8) == 0 )
              {
                v24 = *((_BYTE *)this + 204);
                if ( (v24 & 8) != 0 )
                  *((_BYTE *)this + 204) = v24 & 0xF7;
              }
              v25 = *((_BYTE *)this + 204);
              if ( (v25 & 4) != 0 )
                *((_BYTE *)this + 812) = v23 & ((4 * v25) | 0xF7);
              goto LABEL_65;
            }
            goto LABEL_63;
          }
          v19 = (unsigned int)m_pSimObject[1].vfptr;
          v20 = m_pSimObject->m_Components.size;
          if ( v19 < v20 )
          {
            v16 = (__int64)&m_pSimObject->m_Components.p[v19];
            while ( (*(_DWORD *)(v16 + 8) & 0xFE000000) != (UFG::InventoryComponent::_TypeUID & 0xFE000000)
                 || (UFG::InventoryComponent::_TypeUID & ~*(_DWORD *)(v16 + 8) & 0x1FFFFFF) != 0 )
            {
              ++v19;
              v16 += 16i64;
              if ( v19 >= v20 )
              {
                m_pComponent = 0i64;
                goto LABEL_57;
              }
            }
            goto LABEL_41;
          }
        }
      }
      else
      {
        v14 = (unsigned int)m_pSimObject[1].vfptr;
        v15 = m_pSimObject->m_Components.size;
        if ( v14 < v15 )
        {
          v16 = (__int64)&m_pSimObject->m_Components.p[v14];
          while ( (*(_DWORD *)(v16 + 8) & 0xFE000000) != (UFG::InventoryComponent::_TypeUID & 0xFE000000)
               || (UFG::InventoryComponent::_TypeUID & ~*(_DWORD *)(v16 + 8) & 0x1FFFFFF) != 0 )
          {
            ++v14;
            v16 += 16i64;
            if ( v14 >= v15 )
              goto LABEL_40;
          }
LABEL_41:
          m_pComponent = *(UFG::SimComponent **)v16;
          goto LABEL_57;
        }
      }
LABEL_40:
      m_pComponent = 0i64;
      goto LABEL_57;
    }
  }
  if ( mState != eFACE_ACTION_STATE_WAITING_FOR_CHARGE_INTERACTION )
    goto LABEL_85;
  if ( e == eFACE_ACTION_STATE_CHARGE_INTERACTION_COMPLETE )
    goto LABEL_99;
  if ( e == eFACE_ACTION_STATE_CHARGE_INTERACTION_PLAYING )
  {
    if ( (*((_BYTE *)this + 812) & 8) != 0 )
    {
      v29 = 3;
    }
    else
    {
      v2 = eSOCIALINTERACTIONRESULT_FAILURE;
      v29 = 4;
    }
    if ( this->mMinigameSetup )
      v2 = v29;
    UFG::FaceActionComponent::PlayConversation(this, v2);
  }
  else
  {
LABEL_85:
    if ( mState == eFACE_ACTION_STATE_CHARGE_INTERACTION_PLAYING && e == eFACE_ACTION_STATE_CHARGE_INTERACTION_COMPLETE )
    {
      if ( (*((_BYTE *)this + 812) & 8) != 0 )
      {
        v30 = 3;
      }
      else
      {
        v2 = eSOCIALINTERACTIONRESULT_FAILURE;
        v30 = 4;
      }
      if ( this->mMinigameSetup )
        v2 = v30;
      UFG::FaceActionComponent::StopConversation(this, v2);
    }
    else if ( mState == eFACE_ACTION_STATE_CHARGE_INTERACTION_COMPLETE && e == eFACE_ACTION_STATE_COMPLETE
           || mState == eFACE_ACTION_STATE_GREET_INTERACTION_COMPLETE && e == eFACE_ACTION_STATE_COMPLETE
           || mState == eFACE_ACTION_STATE_CHARGE_INTERACTION_COMPLETE && e == eFACE_ACTION_STATE_WAITING_FOR_CHARGE )
    {
      this->mConversationState = eSOCIAL_CONVERSATION_STATE_ENDED;
    }
  }
LABEL_99:
  if ( this->mState != e )
    this->mTimeInState = 0.0;
  this->mState = e;
  if ( e == eFACE_ACTION_STATE_COMPLETE )
    *((_BYTE *)this + 812) &= ~2u;
  UFG::FaceActionComponent::ProcessIconLogic(this);
}

// File Line: 1010
// RVA: 0x55AF00
void __fastcall UFG::FaceActionComponent::Update(UFG::FaceActionComponent *this, float deltaTime)
{
  float v3; // xmm1_4
  UFG::eFaceActionState mState; // eax
  UFG::StreamedResourceComponent *m_pComponent; // rdi
  int v6; // edx
  char v7; // cl
  int v8; // edx
  char v9; // al
  bool v10; // zf
  char v11; // al
  char v12; // al
  unsigned int mUID; // edx
  UFG::qPropertySet *PropertySet; // rbp
  UFG::SimObject *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  unsigned int vfptr; // edx
  unsigned int size; // r9d
  UFG::SimComponentHolder *p; // rsi
  UFG::MeshResourceLoader *p_mPropMeshLoader; // rbx
  UFG::qSymbol priority; // [rsp+58h] [rbp+10h] BYREF

  v3 = deltaTime + this->mTimeInState;
  this->mTimeInState = v3;
  mState = this->mState;
  m_pComponent = 0i64;
  if ( mState == eFACE_ACTION_STATE_GREET_INTERACTION_COMPLETE )
  {
    if ( !this->mbShouldInteractionExit[(int)UFG::FaceActionComponent::GetFaceActionSuccessState(this)] )
    {
      v9 = *((_BYTE *)this + 812);
      if ( (v9 & 1) == 0 && !this->mMinigameSetup || (v10 = (v9 & 2) == 0, v11 = 1, v10) )
        v11 = 0;
      v6 = -(v11 != 0);
      goto LABEL_21;
    }
LABEL_15:
    v8 = 8;
LABEL_22:
    UFG::FaceActionComponent::SetState(this, (UFG::eFaceActionState)v8);
    goto LABEL_23;
  }
  if ( mState == eFACE_ACTION_STATE_CHARGE_INTERACTION_COMPLETE && v3 >= 0.5 )
  {
    if ( !this->mbShouldInteractionExit[(int)UFG::FaceActionComponent::GetFaceActionSuccessState(this)] )
    {
      v7 = *((_BYTE *)this + 812);
      if ( ((v7 & 1) == 0 && !this->mMinigameSetup || (v7 & 2) == 0) && ((v7 & 1) != 0 || this->mMinigameSetup)
        || (v8 = 4, (*((_BYTE *)this + 204) & 0x10) != 0) )
      {
        v8 = 0;
      }
      goto LABEL_22;
    }
    if ( (*((_BYTE *)this + 812) & 0x10) != 0 )
    {
      LOBYTE(v6) = ~(*((_BYTE *)this + 204) >> 2);
LABEL_21:
      v8 = v6 & 4;
      goto LABEL_22;
    }
    goto LABEL_15;
  }
LABEL_23:
  v12 = *((_BYTE *)this + 812);
  if ( ((v12 & 1) != 0 || this->mMinigameSetup) && (v12 & 2) != 0 )
    UFG::FaceActionComponent::UpdateSocialLogic(this);
  UFG::FaceActionComponent::UpdateAnimBankStreamingForFaceAction(this);
  UFG::FaceActionComponent::UpdateSocialIcon(this);
  if ( this->mCurrentFaceAction != eFACEACTION_PURCHASE || (mUID = this->mItemProp.mUID, mUID == UFG::gNullQSymbol.mUID) )
  {
    this->mItemProp = UFG::gNullQSymbol;
    UFG::MeshResourceLoader::Unload(&this->mPropMeshLoader);
  }
  else if ( !this->mPropMeshLoader.mResourceCount && mUID != SimSym_INVALID.mUID )
  {
    PropertySet = UFG::PropertySetManager::GetPropertySet(&this->mItemProp);
    if ( PropertySet )
    {
      m_pSimObject = this->m_pSimObject;
      if ( m_pSimObject )
      {
        m_Flags = m_pSimObject->m_Flags;
        if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
        {
          m_pComponent = (UFG::StreamedResourceComponent *)m_pSimObject->m_Components.p[10].m_pComponent;
        }
        else if ( (m_Flags & 0x2000) != 0 )
        {
          m_pComponent = (UFG::StreamedResourceComponent *)m_pSimObject->m_Components.p[7].m_pComponent;
        }
        else if ( (m_Flags & 0x1000) != 0 )
        {
          vfptr = (unsigned int)m_pSimObject[1].vfptr;
          size = m_pSimObject->m_Components.size;
          if ( vfptr < size )
          {
            p = m_pSimObject->m_Components.p;
            while ( (p[vfptr].m_TypeUID & 0xFE000000) != (UFG::StreamedResourceComponent::_TypeUID & 0xFE000000)
                 || (UFG::StreamedResourceComponent::_TypeUID & ~p[vfptr].m_TypeUID & 0x1FFFFFF) != 0 )
            {
              if ( ++vfptr >= size )
                goto LABEL_47;
            }
            m_pComponent = (UFG::StreamedResourceComponent *)p[vfptr].m_pComponent;
          }
        }
        else
        {
          m_pComponent = (UFG::StreamedResourceComponent *)UFG::SimObject::GetComponentOfType(
                                                             m_pSimObject,
                                                             UFG::StreamedResourceComponent::_TypeUID);
        }
      }
LABEL_47:
      p_mPropMeshLoader = &this->mPropMeshLoader;
      UFG::MeshResourceLoader::Unload(p_mPropMeshLoader);
      priority.mUID = UFG::StreamedResourceComponent::GetSpawnPriority(m_pComponent, 0i64)->mUID;
      UFG::MeshResourceLoader::Init(p_mPropMeshLoader, PropertySet, &priority.mUID, 0);
      UFG::MeshResourceLoader::PopulateTrueCrowdInstanceFromPropertySet(p_mPropMeshLoader, 1);
      UFG::MeshResourceLoader::QueueLoad(p_mPropMeshLoader);
    }
  }
}

// File Line: 1119
// RVA: 0x53A570
bool __fastcall UFG::FaceActionComponent::IsFaceActionEnabled(UFG::FaceActionComponent *this)
{
  UFG::SimComponent *m_pSimComponent; // rdx
  UFG::eFaceActionState mState; // ecx
  int v4; // eax
  float *v5; // r8
  char v6; // al
  bool v7; // di
  __int64 v8; // rdx
  float mSimTimeMSec_low; // xmm0_4
  UFG::CopSystem *v10; // rax

  m_pSimComponent = this->mStimulusReceiverComponent.m_pSimComponent;
  mState = this->mState;
  v4 = 56;
  if ( mState == eFACE_ACTION_STATE_WAITING_FOR_GREET )
    v4 = 33;
  v5 = (float *)*((_QWORD *)&m_pSimComponent[1].m_BoundComponentHandles.mNode.mPrev + v4);
  v6 = *((_BYTE *)this + 812) & 1;
  v7 = (v6 || this->mMinigameSetup) && mState
    || !v6 && !this->mMinigameSetup && mState != eFACE_ACTION_STATE_WAITING_FOR_CHARGE;
  if ( !this->mFaceActionEnabled || this->mFaceActionEnableBlock || this->mWaitingForPOIBlock )
    return 0;
  if ( *((char *)this + 204) < 0 && !v7 )
  {
    v8 = *(_QWORD *)&this->mTargetingSystemBaseComponent.m_pSimComponent[1].m_TypeUID
       + 56i64
       * *(unsigned __int8 *)(*(_QWORD *)&this->mTargetingSystemBaseComponent.m_pSimComponent[1].m_Flags + 34i64);
    if ( !*(_QWORD *)(v8 + 40) || !*(_BYTE *)(v8 + 49) )
    {
      if ( !v5 )
        return 0;
      mSimTimeMSec_low = (float)SLODWORD(UFG::Metrics::msInstance.mSimTimeMSec);
      if ( (UFG::Metrics::msInstance.mSimTimeMSec & 0x8000000000000000ui64) != 0i64 )
        mSimTimeMSec_low = mSimTimeMSec_low + 1.8446744e19;
      if ( (float)((float)(mSimTimeMSec_low * 0.001) - *v5) >= s_fSocialRequiresPOITimeout )
        return 0;
    }
  }
  v10 = UFG::CopSystem::Instance();
  return !((unsigned int (__fastcall *)(UFG::CopSystem *))v10->vfptr[89].__vecDelDtor)(v10)
      && (UFG::FaceActionComponent::GetEvaluatedRecently(this) || v7);
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
  unsigned int mSimFrameCount; // edx

  if ( bEval )
  {
    mSimFrameCount = UFG::Metrics::msInstance.mSimFrameCount;
    this->mFrameAITreeLastUpdated = UFG::Metrics::msInstance.mSimFrameCount;
    if ( mSimFrameCount - this->mFrameAITreeLastEvaluated >= s_iFrameCountBuffer )
      this->mFrameAITreeFirstEvaluated = mSimFrameCount;
    this->mFrameAITreeLastEvaluated = mSimFrameCount;
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
  UFG::SimObject *m_pSimObject; // rax
  UFG::SimObjectCharacter *LocalPlayer; // rax
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  unsigned int mComponentTableEntryCount; // r9d
  unsigned int size; // r10d
  __int64 v8; // rdx
  unsigned int v9; // r9d
  unsigned int v10; // r10d
  UFG::SimObject *v11; // rcx
  bool IsFaceActionEnabled; // al
  int mMininumRequirement; // [rsp+20h] [rbp-18h]

  m_pSimObject = this->m_pSimObject;
  if ( m_pSimObject && (m_pSimObject->m_Flags & 0x400) != 0 )
    return;
  LocalPlayer = UFG::GetLocalPlayer();
  if ( !LocalPlayer )
    return;
  m_Flags = LocalPlayer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = LocalPlayer->m_Components.p[20].m_pComponent;
    goto LABEL_24;
  }
  if ( m_Flags < 0 )
  {
    m_pComponent = LocalPlayer->m_Components.p[20].m_pComponent;
    goto LABEL_24;
  }
  if ( (m_Flags & 0x2000) != 0 )
  {
    mComponentTableEntryCount = LocalPlayer->mComponentTableEntryCount;
    size = LocalPlayer->m_Components.size;
    if ( mComponentTableEntryCount < size )
    {
      v8 = (__int64)&LocalPlayer->m_Components.p[mComponentTableEntryCount];
      while ( (*(_DWORD *)(v8 + 8) & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
           || (UFG::TargetingSystemBaseComponent::_TypeUID & ~*(_DWORD *)(v8 + 8) & 0x1FFFFFF) != 0 )
      {
        ++mComponentTableEntryCount;
        v8 += 16i64;
        if ( mComponentTableEntryCount >= size )
        {
          m_pComponent = 0i64;
          goto LABEL_24;
        }
      }
LABEL_15:
      m_pComponent = *(UFG::SimComponent **)v8;
      goto LABEL_24;
    }
LABEL_22:
    m_pComponent = 0i64;
    goto LABEL_24;
  }
  if ( (m_Flags & 0x1000) != 0 )
  {
    v9 = LocalPlayer->mComponentTableEntryCount;
    v10 = LocalPlayer->m_Components.size;
    if ( v9 < v10 )
    {
      v8 = (__int64)&LocalPlayer->m_Components.p[v9];
      while ( (*(_DWORD *)(v8 + 8) & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
           || (UFG::TargetingSystemBaseComponent::_TypeUID & ~*(_DWORD *)(v8 + 8) & 0x1FFFFFF) != 0 )
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
  m_pComponent = UFG::SimObject::GetComponentOfType(LocalPlayer, UFG::TargetingSystemBaseComponent::_TypeUID);
LABEL_24:
  if ( m_pComponent )
  {
    v11 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + 58i64)
                             + *(_QWORD *)&m_pComponent[1].m_TypeUID
                             + 40);
    if ( v11 == this->m_pSimObject )
      this->mID = v11->mNode.mUID;
  }
  if ( UFG::FaceMeterComponent::msShowDebug && this->mCurrentFaceAction != eFACEACTION_INVALID )
  {
    mMininumRequirement = this->mMininumRequirement;
    UFG::DrawDebugText(
      this->m_pSimObject->m_pTransformNodeComponent,
      &UFG::qColour::Green,
      "[%s] - %d",
      (__int64)UFG::FaceActionEnumNames[this->mCurrentFaceAction],
      mMininumRequirement);
  }
  IsFaceActionEnabled = UFG::FaceActionComponent::IsFaceActionEnabled(this);
  UFG::FaceActionComponent::UpdatePipIcon(this, IsFaceActionEnabled);
}

// File Line: 1510
// RVA: 0x5608D0
void __fastcall UFG::FaceActionComponent::UpdatePipIcon(UFG::FaceActionComponent *this, bool visible)
{
  UFG::SimObject *m_pSimObject; // rax
  UFG::FaceActionComponent::PipIconEnum CurrentPipIcon; // eax

  if ( this->mPipEffectVisible != visible )
  {
    this->mPipEffectVisible = visible;
    if ( !visible )
    {
      this->mCurrentIcon = ePipIcon_NONE;
      return;
    }
    if ( this->mCurrentIcon != ePipIcon_NONE )
    {
      CurrentPipIcon = (unsigned int)UFG::FaceActionComponent::GetCurrentPipIcon(this);
      if ( this->mCurrentIcon == CurrentPipIcon )
        return;
      goto LABEL_10;
    }
    if ( !this->mHidden )
    {
      m_pSimObject = this->m_pSimObject;
      if ( (!m_pSimObject || (m_pSimObject->m_Flags & 0x400) == 0) && this->mCurrentFaceAction != eFACEACTION_INVALID )
      {
        CurrentPipIcon = (unsigned int)UFG::FaceActionComponent::GetCurrentPipIcon(this);
LABEL_10:
        this->mCurrentIcon = ePipIcon_NONE;
        if ( CurrentPipIcon != ePipIcon_NONE )
          this->mCurrentIcon = CurrentPipIcon;
      }
    }
  }
}

// File Line: 1545
// RVA: 0x527C00
void __fastcall UFG::FaceActionComponent::FaceActionEnable(UFG::FaceActionComponent *this, bool bEnable)
{
  bool mFaceActionEnabled; // al

  mFaceActionEnabled = this->mFaceActionEnabled;
  if ( !mFaceActionEnabled || bEnable )
  {
    if ( mFaceActionEnabled || !bEnable )
    {
      this->mFaceActionEnabled = bEnable;
    }
    else
    {
      UFG::FaceActionComponent::ProcessIconLogic(this);
      this->mFaceActionEnabled = bEnable;
    }
  }
  else
  {
    UFG::FaceActionComponent::KillEffect(this);
    this->mFaceActionEnabled = bEnable;
  }
}

// File Line: 1566
// RVA: 0x154CB50
__int64 UFG::_dynamic_initializer_for__symAnimationStreamingForFaceAction__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("AnimBankStreamingForFaceAction", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symAnimationStreamingForFaceAction, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__symAnimationStreamingForFaceAction__);
}

// File Line: 1569
// RVA: 0x55E3A0
void __fastcall UFG::FaceActionComponent::UpdateAnimBankStreamingForFaceAction(UFG::FaceActionComponent *this)
{
  bool v2; // r14
  UFG::SimObjectCharacter *LocalPlayer; // rax
  UFG::SimObjectCharacter *v4; // rdi
  unsigned int v5; // ebx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  unsigned int v8; // r8d
  unsigned int v9; // r9d
  UFG::SimComponentHolder *p; // rbp
  __int64 v11; // rdx
  unsigned int mComponentTableEntryCount; // r8d
  unsigned int size; // r9d
  unsigned int v14; // r8d
  unsigned int v15; // r9d
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rdi
  UFG::SimObject *m_pSimObject; // rax
  UFG::TransformNodeComponent *v18; // rbp
  float v19; // xmm0_4
  UFG::SimObject *v20; // rax
  AnimationGroupHandleContainer *p_mAnimationGroupHandleContainer; // r14
  UFG::qPropertySet *PropertySet; // rax
  UFG::qPropertySet *v23; // rbp
  const char *v24; // rdi
  UFG::qPropertyList *v25; // rax
  UFG::qPropertyList *v26; // rbp
  unsigned int mNumElements; // esi
  const char *v28; // rax
  UFG::qSymbolUC *v29; // rax
  UFG::qString v30; // [rsp+28h] [rbp-40h] BYREF
  UFG::qArray<unsigned long,0> result; // [rsp+70h] [rbp+8h] BYREF

  if ( (_S23_1 & 1) == 0 )
  {
    _S23_1 |= 1u;
    s_fStreamInDistanceSquared = FLOAT_25_0;
  }
  v2 = 0;
  LocalPlayer = UFG::GetLocalPlayer();
  v4 = LocalPlayer;
  v5 = 0;
  if ( LocalPlayer )
  {
    m_Flags = LocalPlayer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = LocalPlayer->m_Components.p[44].m_pComponent;
LABEL_30:
      if ( !m_pComponent )
      {
        m_pTransformNodeComponent = v4->m_pTransformNodeComponent;
        if ( m_pTransformNodeComponent )
        {
          m_pSimObject = this->m_pSimObject;
          if ( m_pSimObject )
          {
            v18 = m_pSimObject->m_pTransformNodeComponent;
            if ( v18 )
            {
              UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
              UFG::TransformNodeComponent::UpdateWorldTransform(v18);
              v19 = v18->mWorldTransform.v3.y - m_pTransformNodeComponent->mWorldTransform.v3.y;
              v2 = s_fStreamInDistanceSquared >= (float)((float)((float)(v18->mWorldTransform.v3.x
                                                                       - m_pTransformNodeComponent->mWorldTransform.v3.x)
                                                               * (float)(v18->mWorldTransform.v3.x
                                                                       - m_pTransformNodeComponent->mWorldTransform.v3.x))
                                                       + (float)(v19 * v19));
            }
          }
        }
      }
      goto LABEL_35;
    }
    if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        mComponentTableEntryCount = LocalPlayer->mComponentTableEntryCount;
        size = LocalPlayer->m_Components.size;
        if ( mComponentTableEntryCount < size )
        {
          p = LocalPlayer->m_Components.p;
          do
          {
            v11 = mComponentTableEntryCount;
            if ( (p[mComponentTableEntryCount].m_TypeUID & 0xFE000000) == (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
              && (UFG::CharacterOccupantComponent::_TypeUID & ~p[mComponentTableEntryCount].m_TypeUID & 0x1FFFFFF) == 0 )
            {
              goto LABEL_13;
            }
          }
          while ( ++mComponentTableEntryCount < size );
        }
      }
      else
      {
        if ( (m_Flags & 0x1000) == 0 )
        {
          m_pComponent = UFG::SimObject::GetComponentOfType(LocalPlayer, UFG::CharacterOccupantComponent::_TypeUID);
          goto LABEL_30;
        }
        v14 = LocalPlayer->mComponentTableEntryCount;
        v15 = LocalPlayer->m_Components.size;
        if ( v14 < v15 )
        {
          p = LocalPlayer->m_Components.p;
          do
          {
            v11 = v14;
            if ( (p[v14].m_TypeUID & 0xFE000000) == (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
              && (UFG::CharacterOccupantComponent::_TypeUID & ~p[v14].m_TypeUID & 0x1FFFFFF) == 0 )
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
      v8 = LocalPlayer->mComponentTableEntryCount;
      v9 = LocalPlayer->m_Components.size;
      if ( v8 < v9 )
      {
        p = LocalPlayer->m_Components.p;
        while ( 1 )
        {
          v11 = v8;
          if ( (p[v8].m_TypeUID & 0xFE000000) == (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
            && (UFG::CharacterOccupantComponent::_TypeUID & ~p[v8].m_TypeUID & 0x1FFFFFF) == 0 )
          {
            break;
          }
          if ( ++v8 >= v9 )
            goto LABEL_14;
        }
LABEL_13:
        m_pComponent = p[v11].m_pComponent;
        goto LABEL_30;
      }
    }
LABEL_14:
    m_pComponent = 0i64;
    goto LABEL_30;
  }
LABEL_35:
  v20 = this->m_pSimObject;
  if ( v20 && (v20->m_Flags & 0x400) != 0 || this->mCurrentFaceAction == eFACEACTION_INVALID || !v2 )
  {
    if ( this->mAnimationGroupHandleContainer.m_bHasBeenBound )
      AnimationGroupHandleContainer::Unbind(&this->mAnimationGroupHandleContainer);
  }
  else if ( !this->mAnimationGroupHandleContainer.m_bHasBeenBound )
  {
    p_mAnimationGroupHandleContainer = &this->mAnimationGroupHandleContainer;
    UFG::qList<AnimationGroupHandle,AnimationGroupHandleContainer,1,0>::DeleteNodes(&this->mAnimationGroupHandleContainer.m_AnimationGroupHandleList);
    PropertySet = UFG::PropertySetManager::GetPropertySet(&SimSymX_propset_componentFaceAction);
    v23 = UFG::qPropertySet::Get<UFG::qPropertySet>(
            PropertySet,
            (UFG::qArray<unsigned long,0> *)&UFG::symAnimationStreamingForFaceAction,
            DEPTH_RECURSE);
    if ( (UFG::gFaceActionTracksEnum.m_enumLists.size & 0x80000000) != 0 )
      v24 = 0i64;
    else
      v24 = (*UFG::gFaceActionTracksEnum.m_enumLists.p)->m_enumName.p[this->mCurrentFaceAction];
    UFG::qSymbol::create_from_string((UFG::qSymbol *)&result, v24);
    v25 = UFG::qPropertySet::Get<UFG::qPropertyList>(v23, &result, DEPTH_RECURSE);
    v26 = v25;
    if ( v25 )
    {
      mNumElements = v25->mNumElements;
      if ( mNumElements )
      {
        do
        {
          v28 = UFG::qPropertyList::Get<char const *>(v26, v5);
          if ( v28 )
          {
            UFG::qString::qString(&v30, v28);
            UFG::qString::MakeUpper(&v30);
            v29 = UFG::qSymbolUC::create_from_string((UFG::qSymbolUC *)&result.p, v30.mData);
            AnimationGroupHandleContainer::Add(p_mAnimationGroupHandleContainer, v29, eANIM_PRIORITY_SOCIAL);
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
        while ( v5 < mNumElements );
      }
      AnimationGroupHandleContainer::Bind(p_mAnimationGroupHandleContainer);
    }
    else
    {
      UFG::qPrintf("WARNING: no ABK list found for face action: %s\n", v24);
    }
  }
}

// File Line: 1667
// RVA: 0x52C650
__int64 __fastcall UFG::FaceActionComponent::GetCurrentPipIcon(UFG::FaceActionComponent *this)
{
  UFG::SimObject *m_pSimObject; // rcx
  UFG::GameStatTracker *v3; // rax
  int FaceLevel; // eax
  int mMininumRequirement; // ecx
  __int64 result; // rax

  if ( this->mHidden )
    return 11i64;
  m_pSimObject = this->m_pSimObject;
  if ( m_pSimObject )
  {
    if ( (m_pSimObject->m_Flags & 0x400) != 0 )
      return 11i64;
  }
  if ( this->mCurrentFaceAction == eFACEACTION_INVALID )
    return 11i64;
  if ( m_pSimObject && (m_pSimObject->m_Flags & 0x400) != 0
    || !this->mFaceActionSetup
    || (v3 = UFG::GameStatTracker::Instance(),
        FaceLevel = UFG::GameStatTracker::GetFaceLevel(v3),
        this->mCurrentFaceAction == eFACEACTION_INVALID)
    || (mMininumRequirement = this->mMininumRequirement, FaceLevel < mMininumRequirement) )
  {
    switch ( this->mMininumRequirement )
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
  switch ( mMininumRequirement )
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
bool __fastcall UFG::FaceActionComponent::IsFaceActionAvailable(
        UFG::FaceActionComponent *this,
        UFG::eFaceActionEnum eAction,
        bool bCheckSetup)
{
  UFG::SimObject *m_pSimObject; // rax

  m_pSimObject = this->m_pSimObject;
  return (!m_pSimObject || (m_pSimObject->m_Flags & 0x400) == 0)
      && (!bCheckSetup || this->mFaceActionSetup)
      && eAction != eFACEACTION_INVALID
      && (eAction == eFACEACTION_ANY || this->mCurrentFaceAction == eAction);
}

// File Line: 1775
// RVA: 0x53A6A0
bool __fastcall UFG::FaceActionComponent::IsFaceActionRequirementMet(UFG::FaceActionComponent *this)
{
  UFG::SimObject *m_pSimObject; // rax
  UFG::GameStatTracker *v3; // rax
  int FaceLevel; // eax
  bool result; // al

  m_pSimObject = this->m_pSimObject;
  result = 0;
  if ( (!m_pSimObject || (m_pSimObject->m_Flags & 0x400) == 0) && this->mFaceActionSetup )
  {
    v3 = UFG::GameStatTracker::Instance();
    FaceLevel = UFG::GameStatTracker::GetFaceLevel(v3);
    if ( this->mCurrentFaceAction != eFACEACTION_INVALID && FaceLevel >= this->mMininumRequirement )
      return 1;
  }
  return result;
}

// File Line: 1795
// RVA: 0x53CA70
__int64 __fastcall UFG::FaceActionComponent::LookupFaceAction(UFG::qSymbol *sym)
{
  unsigned int v1; // edx
  UFG::qStaticSymbol *v2; // rax

  v1 = 0;
  v2 = UFG::FaceActionEnumSymbols;
  while ( sym->mUID != v2->mUID )
  {
    ++v2;
    ++v1;
    if ( (__int64)v2 >= (__int64)&UFG::qStaticSymbol_eINVENTORY_ITEM_EMPTY_POP_CAN )
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
    if ( (__int64)v2 >= (__int64)&UFG::qStaticSymbol_eCLOTHINGBUFF_SHARPSHOOTER )
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
    if ( (__int64)v2 >= (__int64)&UFG::qStaticSymbol_eCLOTHINGBUFF_TRIADXP_2 )
      return 0i64;
  }
  return v1;
}

// File Line: 1843
// RVA: 0x54C670
void __fastcall UFG::FaceActionComponent::SetConversationState(
        UFG::FaceActionComponent *this,
        UFG::eSocialConversationStateEnum conversationState)
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
  UFG::qPropertySet *mpWritableProperties; // rcx

  mpWritableProperties = pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = pSceneObj->mpConstProperties;
  return UFG::qPropertySet::GetParentFromName(
           mpWritableProperties,
           (UFG::qArray<unsigned long,0> *)&SimSymX_propset_componentFaceAction,
           DEPTH_RECURSE) != 0i64;
}

// File Line: 1891
// RVA: 0x544F30
// attributes: thunk
UFG::FaceActionComponent *__fastcall UFG::FaceActionComponent::PropertiesOnActivate(
        UFG::SceneObjectProperties *pSceneObj)
{
  return UFG::FaceActionComponent::CreateFaceActionComponent(pSceneObj);
}

// File Line: 1896
// RVA: 0x5247E0
UFG::FaceActionComponent *__fastcall UFG::FaceActionComponent::CreateFaceActionComponent(
        UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v3; // rax
  UFG::SimComponent *v4; // rax
  UFG::SimComponent *v5; // rdi
  UFG::SimObject *m_pSimObject; // rdx
  unsigned int v7; // ebx
  UFG::SimObjectModifier v9; // [rsp+38h] [rbp-30h] BYREF

  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x520ui64, "FaceActionComponent", 0i64, 1u);
  if ( v3 )
  {
    UFG::FaceActionComponent::FaceActionComponent((UFG::FaceActionComponent *)v3, pSceneObj->m_NameUID);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  m_pSimObject = pSceneObj->m_pSimObject;
  if ( (m_pSimObject->m_Flags & 0x4000) != 0 )
    v7 = 45;
  else
    v7 = -1;
  UFG::SimObjectModifier::SimObjectModifier(&v9, m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v9, v5, v7);
  UFG::SimObjectModifier::Close(&v9);
  UFG::SimObjectModifier::~SimObjectModifier(&v9);
  v5->vfptr[12].__vecDelDtor(v5, (unsigned int)pSceneObj);
  return (UFG::FaceActionComponent *)v5;
}

// File Line: 1908
// RVA: 0x543A60
void __fastcall UFG::FaceActionComponent::PropertiesLoad(
        UFG::FaceActionComponent *this,
        UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qPropertySet *mpWritableProperties; // rsi
  UFG::qSymbol *v4; // r15
  bool *v5; // r14
  bool *v6; // r13
  float *v7; // rbp
  float *v8; // r12
  char *v9; // rdi
  UFG::qArray<unsigned long,0> *v10; // rax
  UFG::qArray<unsigned long,0> *v11; // rax
  UFG::qArray<unsigned long,0> *v12; // rax
  UFG::qSymbol *v13; // rax
  unsigned int mUID; // eax
  const char *v15; // rax
  UFG::eFaceActionEnum mCurrentFaceAction; // esi
  UFG::eFaceActionEnum v17; // ecx
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
  int *v30; // [rsp+48h] [rbp-A0h]
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
  UFG::qWiseSymbol result; // [rsp+F8h] [rbp+10h] BYREF
  UFG::qWiseSymbol v44; // [rsp+100h] [rbp+18h] BYREF
  UFG::qWiseSymbol v45; // [rsp+108h] [rbp+20h] BYREF

  mpWritableProperties = pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = pSceneObj->mpConstProperties;
  v4 = UFG::qPropertySet::Get<UFG::qSymbol>(
         mpWritableProperties,
         (UFG::qArray<unsigned long,0> *)&SimSym_FaceAction,
         DEPTH_RECURSE);
  if ( !v4 )
    return;
  v30 = (int *)UFG::qPropertySet::Get<unsigned long>(
                 mpWritableProperties,
                 (UFG::qArray<unsigned long,0> *)&SimSym_PipsRequired,
                 DEPTH_RECURSE);
  v32 = UFG::qPropertySet::Get<bool>(
          mpWritableProperties,
          (UFG::qArray<unsigned long,0> *)&SimSym_Hidden,
          DEPTH_RECURSE);
  v5 = UFG::qPropertySet::Get<bool>(
         mpWritableProperties,
         (UFG::qArray<unsigned long,0> *)&SimSym_RemoveOnCompletion,
         DEPTH_RECURSE);
  v36 = UFG::qPropertySet::Get<bool>(
          mpWritableProperties,
          (UFG::qArray<unsigned long,0> *)&SimSym_MinigameSetup,
          DEPTH_RECURSE);
  v38 = UFG::qPropertySet::Get<bool>(
          mpWritableProperties,
          (UFG::qArray<unsigned long,0> *)&SimSym_MinigameEnabled,
          DEPTH_RECURSE);
  v34 = UFG::qPropertySet::Get<bool>(
          mpWritableProperties,
          (UFG::qArray<unsigned long,0> *)&SimSym_FaceActionEnabled,
          DEPTH_RECURSE);
  v6 = UFG::qPropertySet::Get<bool>(
         mpWritableProperties,
         (UFG::qArray<unsigned long,0> *)&SimSym_RequiresGreet,
         DEPTH_RECURSE);
  v41 = UFG::qPropertySet::Get<bool>(
          mpWritableProperties,
          (UFG::qArray<unsigned long,0> *)&SimSym_RequiresCharge,
          DEPTH_RECURSE);
  v35 = UFG::qPropertySet::Get<bool>(
          mpWritableProperties,
          (UFG::qArray<unsigned long,0> *)&SimSym_CycleBackToGreet,
          DEPTH_RECURSE);
  v29 = UFG::qPropertySet::Get<bool>(
          mpWritableProperties,
          (UFG::qArray<unsigned long,0> *)&SimSym_UseConfirmationDialog,
          DEPTH_RECURSE);
  v27 = UFG::qPropertySet::Get<bool>(
          mpWritableProperties,
          (UFG::qArray<unsigned long,0> *)&SimSym_AutoCharge,
          DEPTH_RECURSE);
  v37 = UFG::qPropertySet::Get<bool>(
          mpWritableProperties,
          (UFG::qArray<unsigned long,0> *)&SimSym_RequiresInteractionAreaCheck,
          DEPTH_RECURSE);
  v39 = UFG::qPropertySet::Get<bool>(
          mpWritableProperties,
          (UFG::qArray<unsigned long,0> *)&SimSym_RequiresPOIUsage,
          DEPTH_RECURSE);
  v31 = UFG::qPropertySet::Get<bool>(
          mpWritableProperties,
          (UFG::qArray<unsigned long,0> *)&SimSym_InteractionPointSyncOverride,
          DEPTH_RECURSE);
  v40 = UFG::qPropertySet::Get<unsigned long>(
          mpWritableProperties,
          (UFG::qArray<unsigned long,0> *)&SimSym_MinigameSpeed,
          DEPTH_RECURSE);
  v7 = UFG::qPropertySet::Get<float>(
         mpWritableProperties,
         (UFG::qArray<unsigned long,0> *)&SimSym_MinigameTimeWarpFactor,
         DEPTH_RECURSE);
  v8 = UFG::qPropertySet::Get<float>(
         mpWritableProperties,
         (UFG::qArray<unsigned long,0> *)&SimSym_MinigameMotionDilation,
         DEPTH_RECURSE);
  v42 = UFG::qPropertySet::Get<unsigned long>(
          mpWritableProperties,
          (UFG::qArray<unsigned long,0> *)&SimSym_MinigameTargetSize,
          DEPTH_RECURSE);
  v9 = UFG::qPropertySet::Get<char const *>(
         mpWritableProperties,
         (UFG::qArray<unsigned long,0> *)&SimSym_InteractionCaption,
         DEPTH_RECURSE);
  str = UFG::qPropertySet::Get<char const *>(
          mpWritableProperties,
          (UFG::qArray<unsigned long,0> *)&SimSym_SocialEffectName,
          DEPTH_RECURSE);
  v10 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::qSymbol(&result, 0xA06513B2);
  v25 = UFG::qPropertySet::Get<float>(mpWritableProperties, v10, DEPTH_RECURSE);
  v11 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::qSymbol(&v44, 0x5AC951FEu);
  v26 = UFG::qPropertySet::Get<float>(mpWritableProperties, v11, DEPTH_RECURSE);
  v12 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::qSymbol(&v45, 0x6D41E8F0u);
  v28 = UFG::qPropertySet::Get<float>(mpWritableProperties, v12, DEPTH_RECURSE);
  this->mConfirmationBoxText = UFG::qPropertySet::Get<char const *>(
                                 mpWritableProperties,
                                 (UFG::qArray<unsigned long,0> *)&SimSym_ConfirmationBoxText,
                                 DEPTH_RECURSE);
  if ( UFG::qPropertySet::Get<UFG::qSymbol>(
         mpWritableProperties,
         (UFG::qArray<unsigned long,0> *)&SimSym_SellableItem,
         DEPTH_RECURSE) )
  {
    this->mItemVendor = 1;
  }
  else
  {
    v13 = UFG::qPropertySet::Get<UFG::qSymbol>(
            mpWritableProperties,
            (UFG::qArray<unsigned long,0> *)&SimSym_InventoryType,
            DEPTH_RECURSE);
    if ( v13 )
    {
      mUID = v13->mUID;
      if ( qSymbol_Vehicle_16.mUID == mUID )
      {
        v15 = "vehicle";
      }
      else if ( qSymbol_Boat_16.mUID == mUID )
      {
        v15 = "boat";
      }
      else
      {
        if ( qSymbol_Clothes_16.mUID != mUID )
          goto LABEL_14;
        v15 = "clothing";
      }
      this->mItemIcon = v15;
    }
  }
LABEL_14:
  if ( v7 && v8 )
  {
    this->mMinigameTimeWarpFactor = *v7;
    this->mMinigameMotionDilation = *v8;
  }
  if ( v6 )
    *((_BYTE *)this + 812) ^= (*((_BYTE *)this + 812) ^ *v6) & 1;
  if ( v41 )
    *((_BYTE *)this + 812) ^= (*((_BYTE *)this + 812) ^ (4 * *v41)) & 4;
  if ( v5 )
    *((_BYTE *)this + 812) ^= (*((_BYTE *)this + 812) ^ (16 * !*v5)) & 0x10;
  if ( v27 )
    *((_BYTE *)this + 204) ^= (*((_BYTE *)this + 204) ^ (8 * *v27)) & 8;
  *((_BYTE *)this + 204) &= ~0x10u;
  if ( v35 )
    *((_BYTE *)this + 204) ^= (*((_BYTE *)this + 204) ^ (16 * *v35)) & 0x10;
  *((_BYTE *)this + 204) &= ~4u;
  if ( v29 )
    *((_BYTE *)this + 204) |= 4u;
  if ( v39 )
    *((_BYTE *)this + 204) = *((_BYTE *)this + 204) & 0x7F | (*v39 << 7);
  mCurrentFaceAction = this->mCurrentFaceAction;
  v17 = eFACEACTION_CHARM;
  v18 = UFG::FaceActionEnumSymbols;
  while ( v4->mUID != v18->mUID )
  {
    ++v18;
    ++v17;
    if ( (__int64)v18 >= (__int64)&UFG::qStaticSymbol_eINVENTORY_ITEM_EMPTY_POP_CAN )
    {
      v17 = eFACEACTION_INVALID;
      break;
    }
  }
  this->mCurrentFaceAction = v17;
  if ( v31 )
    v19 = *v31;
  else
    v19 = (unsigned int)(v17 - 3) <= 3;
  *((_BYTE *)this + 204) &= ~0x20u;
  v20 = (char)v37;
  *((_BYTE *)this + 204) |= 32 * v19;
  v21 = *((_BYTE *)this + 204);
  if ( v37 )
    v20 = *v37;
  this->mFaceActionSetup = 1;
  this->mLastPlayedConversationResult = eSOCIALINTERACTIONRESULT_INVALID;
  this->mMiniGameResult = eSOCIALINTERACTIONRESULT_INVALID;
  this->mConversationState = eSOCIAL_CONVERSATION_STATE_INVALID;
  *((_BYTE *)this + 204) = v21 ^ (v21 ^ (v20 << 6)) & 0x40;
  this->mSocialEffectHash = UFG::qStringHashUpper32(str, -1);
  if ( v25 )
    this->mSocalIconMinSizeDist = *v25;
  if ( v26 )
    this->mSocalIconMaxSizeDist = *v26;
  if ( v28 )
    this->mSocalIconScalarMultiplier = *v28;
  v22 = this->mCurrentFaceAction;
  this->mConversationFaceType = v22;
  if ( v22 != mCurrentFaceAction )
    AnimationGroupHandleContainer::Unbind(&this->mAnimationGroupHandleContainer);
  this->mMininumRequirement = *v30;
  this->mHidden = *v32;
  if ( v5 )
    this->mbRemoveOnCompletion = *v5;
  if ( v34 )
    UFG::FaceActionComponent::FaceActionEnable(this, *v34);
  if ( v36 )
    this->mMinigameSetup = *v36;
  if ( v38 )
    this->mMinigameEnabled = *v38;
  if ( v40 )
    this->mMinigameSpeed = *v40;
  if ( v42 )
    this->mMinigameTargetSize = *v42;
  UFG::FaceActionComponent::ProcessIconLogic(this);
  if ( v9 && *v9 )
  {
    v23 = (char *)this - v9;
    do
    {
      v24 = *v9++;
      v9[v23 + 263] = v24;
    }
    while ( v24 );
  }
  UFG::FaceActionComponent::SetInitialState(this);
}

// File Line: 2057
// RVA: 0x54D850
void __fastcall UFG::FaceActionComponent::SetInitialState(UFG::FaceActionComponent *this)
{
  char v1; // al
  unsigned int mState; // edx
  char v3; // al
  int v4; // r8d
  UFG::eSocialConversationStateEnum mConversationState; // eax

  v1 = *((_BYTE *)this + 812);
  if ( (v1 & 2) == 0 && ((v1 & 1) != 0 || this->mMinigameSetup) )
  {
    this->mConversationState = eSOCIAL_CONVERSATION_STATE_LOOPING;
    *((_BYTE *)this + 812) = v1 & 0xFD;
    if ( this->mState )
      this->mTimeInState = 0.0;
    this->mState = eFACE_ACTION_STATE_WAITING_FOR_GREET;
    UFG::FaceActionComponent::ProcessIconLogic(this);
  }
  else
  {
    mState = this->mState;
    v3 = v1 | 2;
    this->mConversationState = eSOCIAL_CONVERSATION_STATE_LOOPING;
    *((_BYTE *)this + 812) = v3;
    if ( mState <= 8 && (v4 = 281, _bittest(&v4, mState)) )
    {
      if ( this->mMinigameSetup )
        this->mMinigameEnabled = 1;
      *((_BYTE *)this + 812) = v3 & 0xF7;
    }
    else
    {
      mConversationState = this->mConversationState;
      if ( mState == 7 )
        mConversationState = eSOCIAL_CONVERSATION_STATE_ENDED;
      this->mConversationState = mConversationState;
    }
    if ( mState != 4 )
      this->mTimeInState = 0.0;
    this->mState = eFACE_ACTION_STATE_WAITING_FOR_CHARGE;
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
bool __fastcall UFG::FaceActionComponent::HasInteractionSucceeded(UFG::FaceActionComponent *this)
{
  UFG::eFaceActionState mState; // eax
  int v2; // eax

  mState = this->mState;
  if ( mState < eFACE_ACTION_STATE_GREET_INTERACTION_PLAYING )
    return 0;
  if ( mState <= eFACE_ACTION_STATE_WAITING_FOR_CHARGE )
  {
    v2 = 6 - ((*((_BYTE *)this + 812) & 2) != 0);
  }
  else
  {
    if ( mState > eFACE_ACTION_STATE_COMPLETE )
      return 0;
    if ( (*((_BYTE *)this + 812) & 8) != 0 )
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
  return v2 && this->mbShouldInteractionExit[(int)UFG::FaceActionComponent::GetFaceActionSuccessState(this)];
}

// File Line: 2095
// RVA: 0x552720
void __fastcall UFG::FaceActionComponent::StopAllConversations(UFG::FaceActionComponent *this)
{
  unsigned int *mPostInteractionConversationReference; // rbx
  __int64 v2; // rdi
  unsigned int v3; // edx
  UFG::qBaseTreeRB *v4; // rax
  _BOOL8 v5; // rdx
  UFG::qBaseTreeRB *v6; // rax
  _BOOL8 v7; // rdx

  mPostInteractionConversationReference = this->mPostInteractionConversationReference;
  v2 = 8i64;
  do
  {
    v3 = *(mPostInteractionConversationReference - 8);
    if ( v3 )
    {
      v4 = UFG::qBaseTreeRB::Get(&UFG::ConversationManager::sm_conversationDb.mTree, v3);
      if ( v4 )
      {
        if ( v4 != (UFG::qBaseTreeRB *)8 )
          UFG::Conversation::ForceFinish((UFG::Conversation *)&v4[-1].mCount, v5);
      }
    }
    if ( *mPostInteractionConversationReference )
    {
      v6 = UFG::qBaseTreeRB::Get(
             &UFG::ConversationManager::sm_conversationDb.mTree,
             *mPostInteractionConversationReference);
      if ( v6 )
      {
        if ( v6 != (UFG::qBaseTreeRB *)8 )
          UFG::Conversation::ForceFinish((UFG::Conversation *)&v6[-1].mCount, v7);
      }
    }
    ++mPostInteractionConversationReference;
    --v2;
  }
  while ( v2 );
}

// File Line: 2114
// RVA: 0x53C0E0
bool __fastcall UFG::FaceActionComponent::IsSocialConversationActive(
        UFG::FaceActionComponent *this,
        UFG::eSocialInteractionResultEnum interactionResult)
{
  unsigned int v2; // edx
  UFG::qBaseTreeRB *v3; // rax
  int *p_mCount; // rax
  int v6; // ebx
  unsigned int *i; // rdi
  UFG::qBaseTreeRB *v8; // rax
  int *v9; // rax

  if ( interactionResult )
  {
    v2 = this->mConversationReference[interactionResult];
    return v2
        && (v3 = UFG::qBaseTreeRB::Get(&UFG::ConversationManager::sm_conversationDb.mTree, v2)) != 0i64
        && (p_mCount = &v3[-1].mCount) != 0i64
        && (p_mCount[12] == 1 || p_mCount[13] == 1);
  }
  else
  {
    v6 = 0;
    for ( i = this->mConversationReference; ; ++i )
    {
      if ( *i )
      {
        v8 = UFG::qBaseTreeRB::Get(&UFG::ConversationManager::sm_conversationDb.mTree, *i);
        if ( v8 )
        {
          v9 = &v8[-1].mCount;
          if ( v9 )
          {
            if ( v9[12] == 1 || v9[13] == 1 )
              break;
          }
        }
      }
      if ( ++v6 >= 8 )
        return 0;
    }
    return 1;
  }
}

// File Line: 2146
// RVA: 0x54FD20
bool __fastcall UFG::FaceActionComponent::SocialConversationHasActionRequests(
        UFG::FaceActionComponent *this,
        UFG::eSocialInteractionResultEnum interactionResult)
{
  unsigned int v2; // edx
  UFG::qBaseTreeRB *v3; // rax
  int *p_mCount; // rax
  int v6; // ebx
  unsigned int *i; // rdi
  UFG::qBaseTreeRB *v8; // rax

  if ( interactionResult == eSOCIALINTERACTIONRESULT_INVALID )
  {
    v6 = 0;
    for ( i = this->mConversationReference; ; ++i )
    {
      if ( *i )
      {
        v8 = UFG::qBaseTreeRB::Get(&UFG::ConversationManager::sm_conversationDb.mTree, *i);
        if ( v8 )
        {
          p_mCount = &v8[-1].mCount;
          if ( p_mCount )
          {
            if ( p_mCount[12] == 1 )
              break;
          }
        }
      }
      if ( ++v6 >= 8 )
        return 0;
    }
    return (p_mCount[42] & 0x40) != 0;
  }
  v2 = this->mConversationReference[interactionResult];
  if ( v2 )
  {
    v3 = UFG::qBaseTreeRB::Get(&UFG::ConversationManager::sm_conversationDb.mTree, v2);
    if ( v3 )
    {
      p_mCount = &v3[-1].mCount;
      if ( p_mCount )
        return (p_mCount[42] & 0x40) != 0;
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
__int64 __fastcall UFG::FaceActionComponent::GetConversationTopic(
        UFG::FaceActionComponent *this,
        UFG::eSocialInteractionResultEnum interactionResult)
{
  UFG::eInventoryItemEnum mInventoryItem; // eax
  unsigned int v4; // ecx
  __int64 result; // rax
  UFG::eInventoryItemEnum v6; // eax
  unsigned int v7; // ecx
  UFG::eFaceActionEnum mCurrentFaceAction; // ecx
  const char *mItemIcon; // rcx

  switch ( interactionResult )
  {
    case eSOCIALINTERACTIONRESULT_GREETSUCCESS:
      if ( (unsigned int)(this->mCurrentFaceAction - 6) <= 1 )
      {
        mInventoryItem = this->mInventoryItem;
        v4 = 34;
        if ( (unsigned int)(mInventoryItem - 163) <= 0x13 )
          return 52;
        return v4;
      }
      return 23i64;
    case eSOCIALINTERACTIONRESULT_GREETFAILURE:
      if ( (unsigned int)(this->mCurrentFaceAction - 6) > 1 )
        return 24i64;
      v6 = this->mInventoryItem;
      v7 = 35;
      if ( (unsigned int)(v6 - 163) <= 0x13 )
        return 60;
      return v7;
    case eSOCIALINTERACTIONRESULT_FAILURE:
      if ( (unsigned int)(this->mCurrentFaceAction - 6) <= 1 )
      {
        if ( (unsigned int)(this->mInventoryItem - 163) > 0x13 )
          return 35i64;
        else
          return 62 - (unsigned int)((*((_BYTE *)this + 204) & 2) != 0);
      }
      return 24i64;
    case eSOCIALINTERACTIONRESULT_SUCCESS:
      mCurrentFaceAction = this->mCurrentFaceAction;
      if ( (unsigned int)(mCurrentFaceAction - 6) <= 1 )
      {
        mItemIcon = this->mItemIcon;
        if ( !mItemIcon
          || (unsigned int)UFG::qStringCompareInsensitive(mItemIcon, "vehicle", -1)
          && (unsigned int)UFG::qStringCompareInsensitive(this->mItemIcon, "clothing", -1) )
        {
          switch ( this->mInventoryItem )
          {
            case eINVENTORY_ITEM_PORK_BUN:
              result = 14i64;
              break;
            case eINVENTORY_ITEM_FOODONSTICK_A:
              result = 17i64;
              break;
            case eINVENTORY_ITEM_FOODONSTICK_B:
              result = 19i64;
              break;
            case eINVENTORY_ITEM_NOODLE_BOWL:
              result = 13i64;
              break;
            case eINVENTORY_ITEM_NOODLE_BOX:
              result = 58i64;
              break;
            case eINVENTORY_ITEM_FISH_BALLS:
              result = 63i64;
              break;
            case eINVENTORY_ITEM_SPICY_SQUID:
              result = 59i64;
              break;
            case eINVENTORY_ITEM_DIM_SUM:
              result = 64i64;
              break;
            case eINVENTORY_ITEM_ICE_CREAM:
              result = 18i64;
              break;
            case eINVENTORY_ITEM_ENERGY_DRINK:
              result = 16i64;
              break;
            case eINVENTORY_ITEM_HAPPY_ENDING:
              result = 66i64;
              break;
            case eINVENTORY_ITEM_HAPPY_ENDING_2:
            case eINVENTORY_ITEM_HAPPY_ENDING_3:
              result = 21i64;
              break;
            case eINVENTORY_ITEM_HERBAL_TEA:
              result = 15i64;
              break;
            case eINVENTORY_ITEM_BRIBE_CHEAP:
            case eINVENTORY_ITEM_BRIBE_AVERAGE:
            case eINVENTORY_ITEM_BRIBE_EXPENSIVE:
            case eINVENTORY_ITEM_EXTORT_CHEAP:
            case eINVENTORY_ITEM_EXTORT_AVERAGE:
            case eINVENTORY_ITEM_EXTORT_EXPENSIVE:
              result = 4i64;
              break;
            case eINVENTORY_ITEM_FISHWRAPPED:
            case eINVENTORY_ITEM_MEATWRAPPED:
              result = 20i64;
              break;
            case eINVENTORY_ITEM_NP_SAFEHOUSEITEM_01:
            case eINVENTORY_ITEM_NP_SAFEHOUSEITEM_02:
            case eINVENTORY_ITEM_NP_SAFEHOUSEITEM_03:
            case eINVENTORY_ITEM_NP_SAFEHOUSEITEM_04:
            case eINVENTORY_ITEM_NP_SAFEHOUSEITEM_05:
            case eINVENTORY_ITEM_CN_SAFEHOUSEITEM_01:
            case eINVENTORY_ITEM_CN_SAFEHOUSEITEM_02:
            case eINVENTORY_ITEM_CN_SAFEHOUSEITEM_03:
            case eINVENTORY_ITEM_CN_SAFEHOUSEITEM_04:
            case eINVENTORY_ITEM_CN_SAFEHOUSEITEM_05:
            case eINVENTORY_ITEM_AB_SAFEHOUSEITEM_01:
            case eINVENTORY_ITEM_AB_SAFEHOUSEITEM_02:
            case eINVENTORY_ITEM_AB_SAFEHOUSEITEM_03:
            case eINVENTORY_ITEM_AB_SAFEHOUSEITEM_04:
            case eINVENTORY_ITEM_AB_SAFEHOUSEITEM_05:
            case eINVENTORY_ITEM_KT_SAFEHOUSEITEM_01:
            case eINVENTORY_ITEM_KT_SAFEHOUSEITEM_02:
            case eINVENTORY_ITEM_KT_SAFEHOUSEITEM_03:
            case eINVENTORY_ITEM_KT_SAFEHOUSEITEM_04:
            case eINVENTORY_ITEM_KT_SAFEHOUSEITEM_05:
              result = 51i64;
              break;
            default:
              result = 12i64;
              break;
          }
        }
        else
        {
          return 67i64;
        }
      }
      else if ( mCurrentFaceAction )
      {
        switch ( mCurrentFaceAction )
        {
          case eFACEACTION_OFFER_HELP:
            return 37i64;
          case eFACEACTION_FAVOR:
            return 38i64;
          case eFACEACTION_FAVOR_PACKAGE:
            return 39i64;
          case eFACEACTION_DELIVER_PACKAGE:
            return 40i64;
          case eFACEACTION_ALLY:
            return 41i64;
          case eFACEACTION_INFORMANT:
            return 42i64;
          case eFACEACTION_HARASS:
            return 43i64;
          case eFACEACTION_FLIRT:
            return 44i64;
          case eFACEACTION_KISS:
            return 46i64;
          case eFACEACTION_INVITE:
            return 47i64;
          case eFACEACTION_ESCORT:
            return 48i64;
          case eFACEACTION_FIGHT_CLUB:
            return 49i64;
          default:
            result = 23i64;
            if ( mCurrentFaceAction == eFACEACTION_BUZZER_INTERACT )
              return 50i64;
            break;
        }
      }
      else
      {
        return 36i64;
      }
      break;
    default:
      return 23i64;
  }
  return result;
}

// File Line: 2445
// RVA: 0x52C880
UFG::AmbientConversation *__fastcall UFG::FaceActionComponent::GetDefaultConversation(
        UFG::FaceActionComponent *this,
        UFG::eSocialInteractionResultEnum interactionResult)
{
  UFG::eConversationTopic ConversationTopic; // esi
  unsigned int ConversationId; // eax
  UFG::AmbientConversation *v6; // rax
  UFG::AmbientConversation *v7; // rbx
  UFG::SimObjectCharacter *LocalPlayer; // rax

  ConversationTopic = (unsigned int)UFG::FaceActionComponent::GetConversationTopic(this, interactionResult);
  if ( ConversationTopic == eConversationTopic_Invalid )
    return 0i64;
  ConversationId = UFG::ConversationManager::GetConversationId();
  v6 = UFG::ConversationManager::AddAmbientConversation(ConversationId);
  v7 = v6;
  if ( v6 )
  {
    v6->m_topic = ConversationTopic;
    LocalPlayer = UFG::GetLocalPlayer();
    UFG::AmbientConversation::SetupLines(v7, this->m_pSimObject, LocalPlayer);
    UFG::Conversation::SetContainsActionRequests(v7);
  }
  return v7;
}

// File Line: 2487
// RVA: 0x5426C0
void __fastcall UFG::FaceActionComponent::PlayConversation(
        UFG::FaceActionComponent *this,
        UFG::eSocialInteractionResultEnum interactionResult)
{
  char *v4; // r14
  unsigned int v5; // edx
  UFG::qBaseTreeRB *v6; // rax
  UFG::Conversation *p_mCount; // rbx
  UFG::AmbientConversation *DefaultConversation; // rax

  v4 = (char *)this + 4 * interactionResult;
  v5 = *((_DWORD *)v4 + 154);
  if ( v5 && (v6 = UFG::qBaseTreeRB::Get(&UFG::ConversationManager::sm_conversationDb.mTree, v5)) != 0i64 )
    p_mCount = (UFG::Conversation *)&v6[-1].mCount;
  else
    p_mCount = 0i64;
  if ( p_mCount )
    goto LABEL_8;
  DefaultConversation = UFG::FaceActionComponent::GetDefaultConversation(this, interactionResult);
  p_mCount = DefaultConversation;
  if ( DefaultConversation )
  {
    *((_DWORD *)v4 + 154) = DefaultConversation->mNode.mUID;
LABEL_8:
    UFG::ConversationManager::InterruptPlayerConversations(eInterruptType_Social, 1, this->m_pSimObject);
    UFG::Conversation::Start(p_mCount);
  }
  this->mLastPlayedConversationResult = interactionResult;
}

// File Line: 2516
// RVA: 0x5527A0
void __fastcall UFG::FaceActionComponent::StopConversation(
        UFG::FaceActionComponent *this,
        UFG::eSocialInteractionResultEnum interactionResult)
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
void __fastcall UFG::FaceActionComponent::PlayPostInteractionConversation(
        UFG::FaceActionComponent *this,
        UFG::eSocialInteractionResultEnum interactionResult)
{
  unsigned int v4; // edx
  UFG::qBaseTreeRB *v5; // rax

  v4 = this->mPostInteractionConversationReference[interactionResult];
  if ( v4 )
  {
    v5 = UFG::qBaseTreeRB::Get(&UFG::ConversationManager::sm_conversationDb.mTree, v4);
    if ( v5 )
    {
      if ( v5 != (UFG::qBaseTreeRB *)8 )
        UFG::Conversation::Start((UFG::Conversation *)&v5[-1].mCount);
    }
    this->mLastPlayedConversationResult = interactionResult;
  }
  else
  {
    this->mLastPlayedConversationResult = interactionResult;
  }
}

// File Line: 2550
// RVA: 0x552860
void __fastcall UFG::FaceActionComponent::StopPostInteractionConversation(
        UFG::FaceActionComponent *this,
        UFG::eSocialInteractionResultEnum interactionResult)
{
  unsigned int v3; // edx
  UFG::qBaseTreeRB *v4; // rax

  v3 = this->mPostInteractionConversationReference[interactionResult];
  if ( v3 )
  {
    v4 = UFG::qBaseTreeRB::Get(&UFG::ConversationManager::sm_conversationDb.mTree, v3);
    if ( v4 )
    {
      if ( v4 != (UFG::qBaseTreeRB *)8 )
        UFG::Conversation::Stop((UFG::Conversation *)&v4[-1].mCount, 0);
    }
    this->mConversationState = eSOCIAL_CONVERSATION_STATE_EXIT;
    this->mLastPlayedConversationResult = eSOCIALINTERACTIONRESULT_INVALID;
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
void __fastcall UFG::FaceActionComponent::SetShouldInteractionExit(
        UFG::FaceActionComponent *this,
        UFG::eSocialInteractionResultEnum interactionResult,
        bool bExitCondition)
{
  this->mbShouldInteractionExit[interactionResult] = bExitCondition;
}

// File Line: 2582
// RVA: 0x54FAD0
_BOOL8 __fastcall UFG::FaceActionComponent::ShouldInteractionExit(
        UFG::FaceActionComponent *this,
        UFG::eSocialInteractionResultEnum interactionResult)
{
  return this->mbShouldInteractionExit[interactionResult];
}

// File Line: 2587
// RVA: 0x54E670
void __fastcall UFG::FaceActionComponent::SetShouldConversationReset(
        UFG::FaceActionComponent *this,
        UFG::eSocialInteractionResultEnum interactionResult,
        bool bResetCondition)
{
  this->mbShouldConversationReset[interactionResult] = bResetCondition;
}

// File Line: 2592
// RVA: 0x54F930
_BOOL8 __fastcall UFG::FaceActionComponent::ShouldConversationReset(
        UFG::FaceActionComponent *this,
        UFG::eSocialInteractionResultEnum interactionResult)
{
  return this->mbShouldConversationReset[interactionResult];
}

// File Line: 2597
// RVA: 0x54C630
void __fastcall UFG::FaceActionComponent::SetConversationReference(
        UFG::FaceActionComponent *this,
        UFG::eSocialInteractionResultEnum interactionResult,
        UFG::Conversation *pConversation)
{
  __int64 v5; // rbx

  v5 = interactionResult;
  UFG::Conversation::SetContainsActionRequests(pConversation);
  this->mConversationReference[v5] = pConversation->mNode.mUID;
}

// File Line: 2603
// RVA: 0x522D60
void __fastcall UFG::FaceActionComponent::ClearConversationReferences(UFG::FaceActionComponent *this)
{
  unsigned int *mPostInteractionConversationReference; // rax
  __int64 v2; // rcx

  mPostInteractionConversationReference = this->mPostInteractionConversationReference;
  v2 = 8i64;
  do
  {
    *(mPostInteractionConversationReference - 8) = 0;
    *mPostInteractionConversationReference++ = 0;
    --v2;
  }
  while ( v2 );
}

// File Line: 2614
// RVA: 0x52C150
UFG::Conversation *__fastcall UFG::FaceActionComponent::GetConversationReference(
        UFG::FaceActionComponent *this,
        UFG::eSocialInteractionResultEnum interactionResult)
{
  unsigned int v2; // edx
  UFG::qBaseTreeRB *v3; // rax

  v2 = this->mConversationReference[interactionResult];
  if ( v2 && (v3 = UFG::qBaseTreeRB::Get(&UFG::ConversationManager::sm_conversationDb.mTree, v2)) != 0i64 )
    return (UFG::Conversation *)&v3[-1].mCount;
  else
    return 0i64;
}

// File Line: 2631
// RVA: 0x54E550
void __fastcall UFG::FaceActionComponent::SetPostInteractionConversationReference(
        UFG::FaceActionComponent *this,
        UFG::eSocialInteractionResultEnum interactionResult,
        UFG::Conversation *pConversation)
{
  this->mPostInteractionConversationReference[interactionResult] = pConversation->mNode.mUID;
}

// File Line: 2636
// RVA: 0x52F5F0
UFG::Conversation *__fastcall UFG::FaceActionComponent::GetPostInteractionConversationReference(
        UFG::FaceActionComponent *this,
        UFG::eSocialInteractionResultEnum interactionResult)
{
  unsigned int v2; // edx
  UFG::qBaseTreeRB *v3; // rax

  v2 = this->mPostInteractionConversationReference[interactionResult];
  if ( v2 && (v3 = UFG::qBaseTreeRB::Get(&UFG::ConversationManager::sm_conversationDb.mTree, v2)) != 0i64 )
    return (UFG::Conversation *)&v3[-1].mCount;
  else
    return 0i64;
}

// File Line: 2647
// RVA: 0x53BEF0
_BOOL8 __fastcall UFG::FaceActionComponent::IsPostInteractionConversationValid(
        UFG::FaceActionComponent *this,
        UFG::eSocialInteractionResultEnum interactionResult)
{
  return this->mPostInteractionConversationReference[interactionResult] != 0;
}

// File Line: 2652
// RVA: 0x52E250
UFG::Conversation *__fastcall UFG::FaceActionComponent::GetLastPlayedConversation(UFG::FaceActionComponent *this)
{
  unsigned int v1; // edx
  UFG::qBaseTreeRB *v2; // rax

  v1 = this->mConversationReference[this->mLastPlayedConversationResult];
  if ( v1 && (v2 = UFG::qBaseTreeRB::Get(&UFG::ConversationManager::sm_conversationDb.mTree, v1)) != 0i64 )
    return (UFG::Conversation *)&v2[-1].mCount;
  else
    return 0i64;
}

