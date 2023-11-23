// File Line: 43
// RVA: 0x15707C0
__int64 UFG::_dynamic_initializer_for__qwsPlayTimeDilate__()
{
  UFG::qWiseSymbol::create_from_string(&qwsPlayTimeDilate_0, "PLAY_TIME_DILATE");
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__qwsPlayTimeDilate__);
}

// File Line: 44
// RVA: 0x15707F0
__int64 UFG::_dynamic_initializer_for__qwsStopTimeDilate__()
{
  UFG::qWiseSymbol::create_from_string(&qwsStopTimeDilate_0, "STOP_TIME_DILATE");
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__qwsStopTimeDilate__);
}

// File Line: 90
// RVA: 0x5C7FB0
void __fastcall UFG::UIHKSocialActionWidget::UIHKSocialActionWidget(UFG::UIHKSocialActionWidget *this)
{
  this->m_ePreviousState = eFACE_ACTION_STATE_WAITING_FOR_GREET;
  this->mPipLevel = ePipIcon_NONE;
  *(_WORD *)&this->mChanged = 256;
  this->mScreenPosChanged = 0;
  this->mScale = 1.0;
  this->mAlpha = 1.0;
  this->mClosestTargetDistance = 9999.0;
  *(_QWORD *)&this->mScreenPos.x = 0i64;
  *(_QWORD *)&this->mScreenPos.z = 0i64;
  *(_WORD *)&this->mChargeVisible = 0;
  *(_QWORD *)&this->mDuration = 0x40000000i64;
  this->mLastUpdateTime = 0.0;
  this->mActionComponent = 0i64;
  this->mActionDistance = eDISTANCE_OFF;
  UFG::qString::qString(&this->mActionType);
  UFG::qString::qString(&this->mPipActionStr);
  UFG::qString::qString(&this->mItemName);
  UFG::qString::qString(&this->mItemCaption);
  UFG::qString::qString(&this->mItemDescription);
  UFG::qString::qString(&this->mItemIcon);
  *(_QWORD *)&this->mPlayTime = 0i64;
  *(_QWORD *)&this->mChargeValue = 0i64;
  this->mGameSpeed = 50;
  *(_QWORD *)&this->mTargetSize = 30i64;
  *(_QWORD *)&this->mQuantity = 0i64;
  *(_QWORD *)&this->mMinPipsRequired = -1i64;
  this->mID = -1;
  *(_QWORD *)&this->mActionEnabled = 256i64;
  *(_WORD *)&this->mChargeHappened = 0;
  this->mHelpbarLocked = 0;
  this->mWidgetNameOnStage.pObjectInterface = 0i64;
  this->mWidgetNameOnStage.Type = VT_Undefined;
  *(_QWORD *)&this->mChargeStatus = 0i64;
}

// File Line: 95
// RVA: 0x5CD5C0
void __fastcall UFG::UIHKSocialActionWidget::~UIHKSocialActionWidget(UFG::UIHKSocialActionWidget *this)
{
  unsigned int v2; // eax
  bool v3; // al
  int v4; // eax

  if ( this->mIsMidMiniGame )
  {
    if ( UFG::gInputSystem )
    {
      if ( UFG::gActiveControllerNum != -1 )
      {
        v2 = UFG::UI::gUIInputLocked;
        if ( !UFG::UI::gUIInputLocked || (--UFG::UI::gUIInputLocked, v2 == 1) )
          UFG::UI::ResetGameplayInput((UFG::UI *)this);
      }
    }
    if ( this->mActionComponent->mMinigameTimeWarpFactor < 1.0 )
    {
      if ( UFG::Metrics::msInstance.mSimTimeScaleMax <= 1.0 )
      {
        UFG::Metrics::msInstance.mSimTimeScaleInGame = UFG::Metrics::msInstance.mSimTimeScaleMax;
        if ( UFG::Metrics::msInstance.mSimTimeScaleMax == 0.0 )
        {
          v3 = 1;
          goto LABEL_13;
        }
      }
      else
      {
        UFG::Metrics::msInstance.mSimTimeScaleInGame = 1.0;
      }
      v3 = 0;
LABEL_13:
      UFG::Metrics::msInstance.mSimPausedInGame = v3;
      UFG::Metrics::msInstance.mSimTimeDeltaStep = 0.0;
      UFG::RenderWorld::AccumulationBufferPostEffect_SetEnable(0);
      if ( UFG::AmbienceAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(UFG::AmbienceAudio::m_instance, qwsStopTimeDilate_0.mUID, 0i64, 0, 0i64);
    }
  }
  if ( this->mHelpbarLocked )
  {
    this->mHelpbarLocked = 0;
    UFG::UIHKGameplayHelpWidget::mSocialLock = 0;
    v4 = UFG::UIHKGameplayHelpWidget::mLocked;
    if ( UFG::UIHKGameplayHelpWidget::mLocked > 0 )
      v4 = --UFG::UIHKGameplayHelpWidget::mLocked;
    if ( v4 < 1 )
      UFG::UIHKScreenHud::GameplayHelp->mChanged = 1;
  }
  UFG::UIHKSocialActionWidget::mTextureLoaded = 0;
  if ( (this->mWidgetNameOnStage.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&this->mWidgetNameOnStage.pObjectInterface->vfptr->gap8[8])(
      this->mWidgetNameOnStage.pObjectInterface,
      &this->mWidgetNameOnStage,
      this->mWidgetNameOnStage.mValue);
    this->mWidgetNameOnStage.pObjectInterface = 0i64;
  }
  this->mWidgetNameOnStage.Type = VT_Undefined;
  UFG::qString::~qString(&this->mItemIcon);
  UFG::qString::~qString(&this->mItemDescription);
  UFG::qString::~qString(&this->mItemCaption);
  UFG::qString::~qString(&this->mItemName);
  UFG::qString::~qString(&this->mPipActionStr);
  UFG::qString::~qString(&this->mActionType);
}

// File Line: 183
// RVA: 0x604EF0
void __fastcall UFG::UIHKSocialActionWidget::SetActionComponent(
        UFG::UIHKSocialActionWidget *this,
        UFG::FaceActionComponent *actionComponent,
        float score)
{
  bool v3; // zf
  char mMinigameEnabled; // r8
  char mStartGame; // cl
  unsigned int mItemPrice; // r13d
  const char *mItemIcon; // rbx
  char *mItemName; // rdi
  char *ItemCaption; // rbp
  char *ItemDescription; // rsi
  const char *v12; // r15
  const char *v13; // r12
  const char *v14; // rbx
  const char *v15; // rdi
  int v16; // eax
  int mMininumRequirement; // [rsp+68h] [rbp+10h]

  if ( actionComponent )
  {
    v3 = actionComponent == this->mActionComponent;
    this->mActionComponent = actionComponent;
    this->mActionChanged |= !v3;
    this->mPedChanged |= !v3;
    this->mActionChanged |= this->m_ePreviousState != actionComponent->mState;
    this->m_ePreviousState = actionComponent->mState;
    mMinigameEnabled = actionComponent->mMinigameEnabled;
    mStartGame = this->mStartGame;
    this->mActionChanged |= mMinigameEnabled != mStartGame;
    if ( mMinigameEnabled != mStartGame )
      this->mStartGame = mMinigameEnabled;
    mItemPrice = actionComponent->mItemPrice;
    mItemIcon = actionComponent->mItemIcon;
    mMininumRequirement = actionComponent->mMininumRequirement;
    mItemName = actionComponent->mItemName;
    ItemCaption = UFG::FaceActionComponent::GetItemCaption(actionComponent);
    ItemDescription = UFG::FaceActionComponent::GetItemDescription(this->mActionComponent);
    v12 = &customCaption;
    this->mConversationFaceType = UFG::FaceActionComponent::GetDialogueConversationFaceAction(this->mActionComponent);
    v13 = &customCaption;
    if ( mItemIcon )
      v13 = mItemIcon;
    v14 = &customCaption;
    if ( mItemName )
      v14 = mItemName;
    v15 = &customCaption;
    if ( ItemDescription )
      v15 = ItemDescription;
    if ( ItemCaption )
      v12 = ItemCaption;
    if ( mMininumRequirement != this->mMinPipsRequired
      || mItemPrice != this->mItemPrice
      || (unsigned int)UFG::qStringCompare(v13, this->mItemIcon.mData, -1)
      || (unsigned int)UFG::qStringCompare(v14, this->mItemName.mData, -1)
      || (v16 = UFG::qStringCompare(v12, this->mItemCaption.mData, -1)) != 0 )
    {
      LOBYTE(v16) = 1;
    }
    this->mActionChanged |= v16;
    this->mScore = score;
    this->mMinPipsRequired = mMininumRequirement;
    this->mItemPrice = mItemPrice;
    UFG::qString::Set(&this->mItemIcon, v13);
    UFG::qString::Set(&this->mItemName, v14);
    UFG::qString::Set(&this->mItemDescription, v15);
    UFG::qString::Set(&this->mItemCaption, v12);
  }
}

// File Line: 268
// RVA: 0x5F41A0
void __fastcall UFG::UIHKSocialActionWidget::PlaySuccessfulInteraction(UFG::UIHKSocialActionWidget *this)
{
  Scaleform::GFx::Movie *pObject; // rax

  if ( !this->mPlayingActionResult )
  {
    pObject = UFG::UIHKScreenHud::mInstance->mRenderable->m_movie.pObject;
    if ( pObject )
    {
      this->mPlayingActionResult = 1;
      Scaleform::GFx::Movie::Invoke(pObject, "FaceAction_playSuccessfulInteraction", 0i64, 0i64, 0);
    }
  }
}

// File Line: 390
// RVA: 0x5EAFB0
void __fastcall UFG::UIHKSocialActionWidget::HandleMessage(
        UFG::UIHKSocialActionWidget *this,
        UFG::UIScreen *screen,
        unsigned int msgId,
        UFG::UIMessage *msg)
{
  UFG::UI *v8; // rcx
  UFG::FaceActionComponent *mActionComponent; // rax
  float mMinigameTimeWarpFactor; // xmm0_4
  bool v11; // al
  Scaleform::GFx::Movie *pObject; // rsi
  UFG::qString v13; // [rsp+38h] [rbp-70h] BYREF
  Scaleform::GFx::Value value; // [rsp+60h] [rbp-48h] BYREF

  if ( this->mID != -1 )
  {
    v8 = (UFG::UI *)(unsigned int)UI_HASH_BUTTON_BUTTON2_PRESSED_30;
    if ( !this->mChargeHappened )
    {
      mActionComponent = this->mActionComponent;
      if ( mActionComponent )
      {
        if ( !mActionComponent->mMinigameSetup
          && mActionComponent->mState == eFACE_ACTION_STATE_WAITING_FOR_CHARGE
          && msgId == (_DWORD)UI_HASH_BUTTON_BUTTON2_PRESSED_30 )
        {
          this->mChargeHappened = 1;
        }
      }
    }
    if ( msgId == UI_HASH_ACTION_RESULT_DONE_20 || !this->mPlayingActionResult )
    {
      if ( !this->mPlayingTargetGame || !this->mRenderingTargetGame )
        goto LABEL_41;
      if ( msgId == (_DWORD)v8 )
      {
        this->mIsMidMiniGame = 1;
        UFG::UI::LockGameplayInput(v8);
        mMinigameTimeWarpFactor = this->mActionComponent->mMinigameTimeWarpFactor;
        if ( mMinigameTimeWarpFactor < 1.0 )
        {
          if ( mMinigameTimeWarpFactor <= 0.0 )
            mMinigameTimeWarpFactor = 0.0;
          if ( mMinigameTimeWarpFactor >= UFG::Metrics::msInstance.mSimTimeScaleMax )
            mMinigameTimeWarpFactor = UFG::Metrics::msInstance.mSimTimeScaleMax;
          UFG::Metrics::msInstance.mSimTimeScaleInGame = mMinigameTimeWarpFactor;
          UFG::Metrics::msInstance.mSimPausedInGame = mMinigameTimeWarpFactor == 0.0;
          UFG::Metrics::msInstance.mSimTimeDeltaStep = 0.0;
          UFG::RenderWorld::AccumulationBufferPostEffect_SetEnable(this->mActionComponent->mMinigameMotionDilation > 0.1);
          v8 = (UFG::UI *)UFG::AmbienceAudio::m_instance;
          if ( UFG::AmbienceAudio::m_instance )
            UFG::AudioEntity::CreateAndPlayEvent(
              UFG::AmbienceAudio::m_instance,
              qwsPlayTimeDilate_0.mUID,
              0i64,
              0,
              0i64);
        }
      }
      if ( msgId == UI_HASH_TIMED_GAME_OUTRO_DONE_20 )
        this->mChargeState = STATE_CHARGE_IDLE;
      if ( msgId != UI_HASH_TIMED_GAME_RESULT_20 || !this->mPlayingTargetGame )
        goto LABEL_41;
      this->mIsMidMiniGame = 0;
      UFG::UI::UnlockGameplayInput(v8);
      if ( this->mActionComponent->mMinigameTimeWarpFactor >= 1.0 )
      {
LABEL_32:
        UFG::qString::qString(&v13, (UFG::qString *)&msg[1]);
        if ( (unsigned int)UFG::qStringCompare(v13.mData, "SUCCESS", -1) )
        {
          if ( (unsigned int)UFG::qStringCompare(v13.mData, "FAILURE", -1) )
            goto LABEL_40;
          this->mGameResult = eSOCIALINTERACTIONRESULT_MINIGAMEFAILURE;
        }
        else
        {
          this->mGameResult = eSOCIALINTERACTIONRESULT_MINIGAMESUCCESS;
        }
        this->mActionComponent->mMiniGameResult = this->mGameResult;
        this->mChargeHappened = 1;
        pObject = screen->mRenderable->m_movie.pObject;
        if ( pObject )
        {
          value.pObjectInterface = 0i64;
          value.Type = VT_Boolean;
          value.mValue.BValue = 0;
          Scaleform::GFx::Movie::SetVariable(pObject, "mcFaceGame._visible", &value, 1i64);
          if ( (value.Type & 0x40) != 0 )
          {
            (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
              value.pObjectInterface,
              &value,
              value.mValue);
            value.pObjectInterface = 0i64;
          }
          value.Type = VT_Undefined;
          UFG::qString::~qString(&v13);
LABEL_41:
          if ( msgId == UI_HASH_ACTION_RESULT_DONE_20 )
          {
            this->mPlayingActionResult = 0;
            this->mActionChanged = 1;
            this->mShouldHideActionIcon = 1;
            UFG::qString::Set(&this->mItemIcon, &customCaption);
            this->mActionChanged = 1;
            this->mActionDistance = eDISTANCE_OFF;
            this->mPlayingActionResult = 0;
          }
          return;
        }
LABEL_40:
        UFG::qString::~qString(&v13);
        return;
      }
      if ( UFG::Metrics::msInstance.mSimTimeScaleMax <= 1.0 )
      {
        UFG::Metrics::msInstance.mSimTimeScaleInGame = UFG::Metrics::msInstance.mSimTimeScaleMax;
        if ( UFG::Metrics::msInstance.mSimTimeScaleMax == 0.0 )
        {
          v11 = 1;
          goto LABEL_30;
        }
      }
      else
      {
        UFG::Metrics::msInstance.mSimTimeScaleInGame = 1.0;
      }
      v11 = 0;
LABEL_30:
      UFG::Metrics::msInstance.mSimPausedInGame = v11;
      UFG::Metrics::msInstance.mSimTimeDeltaStep = 0.0;
      UFG::RenderWorld::AccumulationBufferPostEffect_SetEnable(0);
      if ( UFG::AmbienceAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(UFG::AmbienceAudio::m_instance, qwsStopTimeDilate_0.mUID, 0i64, 0, 0i64);
      goto LABEL_32;
    }
  }
}

// File Line: 555
// RVA: 0x617770
void __fastcall UFG::UIHKSocialActionWidget::Update(
        UFG::UIHKSocialActionWidget *this,
        UFG::UIScreen *screen,
        float elapsed,
        bool charging)
{
  UFG::FaceActionComponent *ComponentOfType; // r8
  UFG::SimComponent *m_pComponent; // rcx
  __int64 v8; // rdx
  __int64 v9; // rax
  UFG::SimObject *v10; // rcx
  UFG::FaceActionComponent *mActionComponent; // rcx
  UFG::eFaceActionState mState; // edx
  UFG::FaceActionComponent *v13; // rax
  UFG::eFaceActionState v14; // ecx
  int v15; // eax
  UFG::eDistance v16; // ecx
  float v17; // xmm0_4
  UFG::FaceActionComponent *v18; // rax
  __int32 v19; // ecx
  __int32 v20; // ecx
  float v21; // xmm0_4
  UFG::GameStatTracker *v22; // rax
  Scaleform::GFx::Movie *pObject; // r14
  UFG::FaceActionComponent *v24; // rax
  __int64 v25; // rsi
  UFG::InputActionData *v26; // rax
  float v27; // xmm6_4
  __m128 mChargeGameTimer_low; // xmm1
  int v29; // ecx
  UFG::InputActionData *v30; // rax
  float mChargeStatus; // xmm0_4
  UFG::UI *v32; // rcx
  bool v33; // al
  UFG::UIHKSocialActionWidget::eFaceChargeState mChargeState; // eax
  float mSimTime_Temp; // xmm1_4
  UFG::eDistance mActionDistance; // ecx
  __int32 v37; // ecx
  __int32 v38; // ecx
  __int32 v39; // ecx
  Scaleform::GFx::Value::ValueUnion v40; // xmm6_8
  Scaleform::GFx::Value::ValueUnion v41; // xmm6_8
  UFG::UIHKScreenHud *v42; // rax
  Scaleform::GFx::Value::ValueUnion v43; // xmm6_8
  Scaleform::GFx::Value::ValueUnion v44; // xmm6_8
  float mInitScreenX; // xmm0_4
  float mInitScreenY; // xmm1_4
  Scaleform::GFx::Value::ValueUnion v47; // xmm6_8
  Scaleform::GFx::Value::ValueUnion v48; // xmm6_8
  Scaleform::GFx::Value value; // [rsp+30h] [rbp-A8h] BYREF
  Scaleform::GFx::Value ptr; // [rsp+60h] [rbp-78h] BYREF
  __int64 v51; // [rsp+90h] [rbp-48h]
  UFG::qString v52; // [rsp+98h] [rbp-40h] BYREF

  v51 = -2i64;
  if ( this->mShouldHideActionIcon )
  {
    this->mShouldHideActionIcon = 0;
    UFG::UIHKSocialActionWidget::Flash_HideActionIcon(this, screen);
  }
  if ( this->mID == -1 )
    return;
  ComponentOfType = 0i64;
  if ( LocalPlayer )
  {
    m_pComponent = LocalPlayer->m_Components.p[20].m_pComponent;
    if ( m_pComponent )
    {
      v8 = 56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + 58i64);
      v9 = *(_QWORD *)&m_pComponent[1].m_TypeUID;
      v10 = *(UFG::SimObject **)(v8 + v9 + 40);
      if ( v10 )
      {
        if ( *(_BYTE *)(v8 + v9 + 49) )
          ComponentOfType = (UFG::FaceActionComponent *)UFG::SimObject::GetComponentOfType(
                                                          v10,
                                                          UFG::FaceActionComponent::_TypeUID);
      }
    }
  }
  if ( this->mHelpbarLocked )
    goto LABEL_19;
  mActionComponent = this->mActionComponent;
  if ( mActionComponent )
  {
    mState = mActionComponent->mState;
    if ( mState != eFACE_ACTION_STATE_COMPLETE
      && mState
      && (mState != eFACE_ACTION_STATE_WAITING_FOR_CHARGE
       || (*((_BYTE *)mActionComponent + 204) & 8) != 0
       && ((*((_BYTE *)mActionComponent + 812) & 1) != 0 || mActionComponent->mMinigameSetup)) )
    {
      this->mHelpbarLocked = 1;
      ++UFG::UIHKGameplayHelpWidget::mLocked;
    }
  }
  if ( this->mHelpbarLocked )
  {
LABEL_19:
    v13 = this->mActionComponent;
    if ( !v13
      || (v14 = v13->mState, v14 == eFACE_ACTION_STATE_COMPLETE)
      || v14 == eFACE_ACTION_STATE_WAITING_FOR_GREET
      || v14 == eFACE_ACTION_STATE_WAITING_FOR_CHARGE
      && ((*((_BYTE *)v13 + 204) & 8) == 0 || (*((_BYTE *)v13 + 812) & 1) == 0 && !v13->mMinigameSetup) )
    {
      this->mHelpbarLocked = 0;
      v15 = UFG::UIHKGameplayHelpWidget::mLocked;
      if ( UFG::UIHKGameplayHelpWidget::mLocked > 0 )
        v15 = --UFG::UIHKGameplayHelpWidget::mLocked;
      if ( v15 < 1 )
        UFG::UIHKScreenHud::GameplayHelp->mChanged = 1;
    }
  }
  v16 = eDISTANCE_OFF;
  if ( ComponentOfType )
  {
    v17 = this->mActionComponentTimer - elapsed;
    this->mActionComponentTimer = v17;
    if ( ComponentOfType != this->mActionComponent || v17 <= 0.0 )
    {
      UFG::UIHKSocialActionWidget::SetActionComponent(this, ComponentOfType, 1.0);
      this->mActionComponentTimer = UFG::UIHKSocialActionWidget::gActionComponentTimerPeriod;
    }
    if ( UFG::FaceActionComponent::IsFaceActionEnabled(this->mActionComponent) )
    {
      v18 = this->mActionComponent;
      if ( (*((_BYTE *)v18 + 812) & 1) != 0 || v18->mMinigameSetup )
        v16 = this->mActionComponent->mState == eFACE_ACTION_STATE_WAITING_FOR_GREET;
      else
        v16 = this->mActionComponent->mState == eFACE_ACTION_STATE_WAITING_FOR_CHARGE;
    }
    else
    {
      v16 = eDISTANCE_OFF;
    }
  }
  else
  {
    if ( this->mActionComponent )
      this->mActionComponent = 0i64;
    this->mChargeHappened = 0;
  }
  this->mActionChanged |= this->mActionDistance != v16;
  this->mActionDistance = v16;
  if ( v16 )
  {
    v19 = v16 - 1;
    if ( v19 )
    {
      v20 = v19 - 1;
      if ( v20 )
      {
        if ( v20 != 1 )
          goto LABEL_50;
        UFG::qString::Set(&this->mItemIcon, "sociable");
      }
    }
    this->mActionEnabled = 1;
  }
  else
  {
    this->mActionEnabled = 0;
  }
LABEL_50:
  if ( this->mPlayingActionResult )
  {
    v21 = elapsed + this->mPlayTime;
    this->mPlayTime = v21;
    if ( v21 <= 0.5 )
      return;
    this->mPlayingActionResult = 0;
    this->mPlayTime = 0.0;
  }
  v22 = UFG::GameStatTracker::Instance();
  this->mPlayerPipLevel = UFG::GameStatTracker::GetFaceLevel(v22);
  if ( screen )
  {
    pObject = screen->mRenderable->m_movie.pObject;
    if ( pObject )
    {
      this->mClosestTargetDistance = 9999.0;
      value.pObjectInterface = 0i64;
      value.Type = VT_Undefined;
      if ( this->mPlayingActionResult )
      {
LABEL_145:
        if ( (value.Type & 0x40) != 0 )
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
            value.pObjectInterface,
            &value,
            value.mValue);
        return;
      }
      v24 = this->mActionComponent;
      if ( v24 && this->mChargeHappened && v24->mState != eFACE_ACTION_STATE_WAITING_FOR_CHARGE )
        this->mChargeHappened = 0;
      if ( !this->mRenderingTargetGame || !this->mPlayingTargetGame )
        goto LABEL_95;
      v25 = (int)UFG::gActiveControllerNum;
      v26 = UFG::ActionDef_UIBackRepeat.mDataPerController[UFG::gActiveControllerNum];
      if ( v26 && v26->mActionTrue )
      {
        this->mChargeGameTimer = elapsed + this->mChargeGameTimer;
        v27 = FLOAT_2_0;
        switch ( this->mPlayerPipLevel )
        {
          case 1:
            v27 = FLOAT_2_4000001;
            break;
          case 2:
            v27 = FLOAT_2_8;
            break;
          case 3:
            v27 = FLOAT_3_2;
            break;
          case 4:
            v27 = FLOAT_2_5999999;
            break;
          case 5:
            v27 = FLOAT_4_0;
            break;
          default:
            break;
        }
        `eh vector constructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
        mChargeGameTimer_low = (__m128)LODWORD(this->mChargeGameTimer);
        mChargeGameTimer_low.m128_f32[0] = (float)(mChargeGameTimer_low.m128_f32[0] / v27) * 100.0;
        v29 = (int)mChargeGameTimer_low.m128_f32[0];
        if ( (int)mChargeGameTimer_low.m128_f32[0] != 0x80000000 && (float)v29 != mChargeGameTimer_low.m128_f32[0] )
          mChargeGameTimer_low.m128_f32[0] = (float)(v29
                                                   - (_mm_movemask_ps(_mm_unpacklo_ps(mChargeGameTimer_low, mChargeGameTimer_low)) & 1));
        LODWORD(this->mChargeStatus) = mChargeGameTimer_low.m128_i32[0];
        if ( (ptr.Type & 0x40) != 0 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, unsigned __int64))&ptr.pObjectInterface->vfptr->gap8[8])(
            ptr.pObjectInterface,
            &ptr,
            value.DataAux);
          ptr.pObjectInterface = 0i64;
        }
        ptr.Type = VT_Number;
        *(double *)&value.DataAux = mChargeGameTimer_low.m128_f32[0];
        Scaleform::GFx::Movie::Invoke(pObject, "ChargeGame_SetCharge", 0i64, &ptr, 1u);
        `eh vector destructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
      }
      v30 = UFG::ActionDef_UIBackReleased.mDataPerController[v25];
      if ( !v30 || !v30->mActionTrue )
      {
LABEL_95:
        mChargeState = this->mChargeState;
        if ( mChargeState )
        {
          if ( mChargeState == STATE_CHARGE_PLAYING )
          {
            mSimTime_Temp = UFG::Metrics::msInstance.mSimTime_Temp;
            this->mElapsedTime = (float)(UFG::Metrics::msInstance.mSimTime_Temp - this->mLastUpdateTime)
                               + this->mElapsedTime;
            this->mLastUpdateTime = mSimTime_Temp;
            if ( this->mDuration > 0.0 )
              UFG::UIHKSocialActionWidget::Flash_ShowChargeMeter(this, screen);
            if ( this->mDuration <= this->mElapsedTime )
            {
              UFG::UIHKSocialActionWidget::PlaySuccessfulInteraction(this);
              this->mChargeState = STATE_CHARGE_FINISHED;
            }
          }
        }
        else if ( this->mChargeVisible )
        {
          UFG::UIHKSocialActionWidget::Flash_HideChargeMeter(this, screen);
        }
        if ( !this->mVisible || !this->mActionChanged )
          goto LABEL_118;
        this->mActionChanged = 0;
        if ( this->mItemIcon.mLength && (mActionDistance = this->mActionDistance) != eDISTANCE_OFF )
        {
          v37 = mActionDistance - 1;
          if ( !v37 )
          {
LABEL_111:
            if ( this->mDuration >= this->mElapsedTime && (unsigned int)(this->mChargeState - 3) > 1 )
              UFG::UIHKSocialActionWidget::Flash_ShowActionIcon(this, screen);
            goto LABEL_118;
          }
          v38 = v37 - 1;
          if ( v38 )
          {
            v39 = v38 - 1;
            if ( v39 )
            {
              if ( v39 != 1 )
                goto LABEL_111;
              UFG::UIHKSocialActionWidget::Flash_HideActionIcon(this, screen);
              UFG::UIHKSocialActionWidget::Flash_ShowHelpBar(this, screen);
            }
            else
            {
              UFG::UIHKSocialActionWidget::Flash_ShowFarIcon(this, screen);
            }
          }
          else
          {
            UFG::UIHKSocialActionWidget::Flash_ShowCloseIcon(this, screen);
          }
        }
        else
        {
          UFG::UIHKSocialActionWidget::Flash_HideActionIcon(this, screen);
        }
LABEL_118:
        if ( this->mChanged )
        {
          this->mChanged = 0;
          if ( this->mVisible )
          {
            v40.NValue = (float)(this->mScale * 100.0);
            if ( (value.Type & 0x40) != 0 )
            {
              (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
                value.pObjectInterface,
                &value,
                value.mValue);
              value.pObjectInterface = 0i64;
            }
            value.Type = VT_Number;
            value.mValue = v40;
            UFG::qString::qString((UFG::qString *)&ptr, "mc_FaceAction%d._xscale", (unsigned int)this->mID);
            UFG::qString::qString((UFG::qString *)&ptr.8, "mc_FaceAction%d._yscale", (unsigned int)this->mID);
            Scaleform::GFx::Movie::SetVariable(pObject, *(const char **)&ptr.Type, &value, 1i64);
            Scaleform::GFx::Movie::SetVariable(pObject, ptr.mValue.pString, &value, 1i64);
            v41.NValue = (float)(this->mAlpha * 100.0);
            if ( (value.Type & 0x40) != 0 )
            {
              (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
                value.pObjectInterface,
                &value,
                value.mValue);
              value.pObjectInterface = 0i64;
            }
            value.Type = VT_Number;
            value.mValue = v41;
            UFG::qString::qString(&v52, "mc_FaceAction%d._alpha", (unsigned int)this->mID);
            Scaleform::GFx::Movie::SetVariable(pObject, v52.mData, &value, 1i64);
            UFG::qString::~qString(&v52);
            UFG::qString::~qString((UFG::qString *)&ptr.8);
            UFG::qString::~qString((UFG::qString *)&ptr);
          }
          else
          {
            UFG::UIHKGameplayHelpWidget::Hide(UFG::UIHKScreenHud::GameplayHelp, UI_HASH_HELPBAR_SOCIAL_20);
            v42 = UFG::UIHKScreenHud::mInstance;
            if ( UFG::UIHKScreenHud::mInstance )
            {
              *(_WORD *)&UFG::UIHKScreenHud::mInstance->MoneyPopup.mLeaveOn = 256;
              v42->MoneyPopup.mTryToHide = 1;
              v42->MoneyPopup.mForceShow = 1;
            }
          }
        }
        if ( this->mVisible && this->mScreenPosChanged )
        {
          v43.NValue = this->mScreenPos.x;
          if ( (value.Type & 0x40) != 0 )
          {
            (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
              value.pObjectInterface,
              &value,
              value.mValue);
            value.pObjectInterface = 0i64;
          }
          value.Type = VT_Number;
          value.mValue = v43;
          UFG::qString::qString((UFG::qString *)&ptr.8, "mc_FaceAction%d._x", (unsigned int)this->mID);
          Scaleform::GFx::Movie::SetVariable(pObject, ptr.mValue.pString, &value, 1i64);
          v44.NValue = this->mScreenPos.y;
          if ( (value.Type & 0x40) != 0 )
          {
            (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
              value.pObjectInterface,
              &value,
              value.mValue);
            value.pObjectInterface = 0i64;
          }
          value.Type = VT_Number;
          value.mValue = v44;
          UFG::qString::qString((UFG::qString *)&ptr, "mc_FaceAction%d._y", (unsigned int)this->mID);
          Scaleform::GFx::Movie::SetVariable(pObject, *(const char **)&ptr.Type, &value, 1i64);
          UFG::qString::~qString((UFG::qString *)&ptr);
          UFG::qString::~qString((UFG::qString *)&ptr.8);
        }
        if ( !UFG::UIHKTweakables::SocialActionFloatingTweak )
        {
          mInitScreenX = this->mInitScreenX;
          this->mScreenPosChanged |= mInitScreenX != this->mScreenPos.x;
          this->mScreenPos.x = mInitScreenX;
          mInitScreenY = this->mInitScreenY;
          this->mScreenPosChanged |= mInitScreenY != this->mScreenPos.y;
          this->mScreenPos.y = mInitScreenY;
          this->mChanged |= !this->mVisible;
          this->mChanged |= 1.0 != this->mScale;
          this->mScale = 1.0;
          this->mAlpha = 1.0;
        }
        if ( this->mRenderingTargetGame && this->mScreenPosChanged )
        {
          v47.NValue = this->mScreenPos.x;
          if ( (value.Type & 0x40) != 0 )
          {
            (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
              value.pObjectInterface,
              &value,
              value.mValue);
            value.pObjectInterface = 0i64;
          }
          value.Type = VT_Number;
          value.mValue = v47;
          Scaleform::GFx::Movie::SetVariable(pObject, "mcChargeGame._x", &value, 1i64);
          v48.NValue = this->mScreenPos.y;
          if ( (value.Type & 0x40) != 0 )
          {
            (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
              value.pObjectInterface,
              &value,
              value.mValue);
            value.pObjectInterface = 0i64;
          }
          value.Type = VT_Number;
          value.mValue = v48;
          Scaleform::GFx::Movie::SetVariable(pObject, "mcChargeGame._y", &value, 1i64);
        }
        this->mScreenPosChanged = 0;
        if ( UFG::UIHKSocialActionWidget::mTextureLoaded )
        {
          UFG::UIHKSocialActionWidget::mTextureLoaded = 0;
          UFG::UIHKSocialActionWidget::HandleTextureLoaded(this, screen);
        }
        goto LABEL_145;
      }
      `eh vector constructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      mChargeStatus = this->mChargeStatus;
      if ( mChargeStatus < 74.0 || mChargeStatus > 88.0 )
      {
        if ( (ptr.Type & 0x40) != 0 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, unsigned __int64))&ptr.pObjectInterface->vfptr->gap8[8])(
            ptr.pObjectInterface,
            &ptr,
            value.DataAux);
          ptr.pObjectInterface = 0i64;
        }
        LOBYTE(value.DataAux) = 0;
        this->mGameResult = eSOCIALINTERACTIONRESULT_MINIGAMEFAILURE;
      }
      else
      {
        if ( (ptr.Type & 0x40) != 0 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, unsigned __int64))&ptr.pObjectInterface->vfptr->gap8[8])(
            ptr.pObjectInterface,
            &ptr,
            value.DataAux);
          ptr.pObjectInterface = 0i64;
        }
        LOBYTE(value.DataAux) = 1;
        this->mGameResult = eSOCIALINTERACTIONRESULT_MINIGAMESUCCESS;
      }
      ptr.Type = VT_Boolean;
      this->mActionComponent->mMiniGameResult = this->mGameResult;
      this->mChargeHappened = 1;
      Scaleform::GFx::Movie::Invoke(pObject, "ChargeGame_SetSuccessValue", 0i64, &ptr, 1u);
      this->mChargeState = STATE_OUTRO_PLAYING;
      this->mIsMidMiniGame = 0;
      UFG::UI::UnlockGameplayInput(v32);
      if ( this->mActionComponent->mMinigameTimeWarpFactor >= 1.0 )
      {
LABEL_94:
        `eh vector destructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
        goto LABEL_95;
      }
      if ( UFG::Metrics::msInstance.mSimTimeScaleMax <= 1.0 )
      {
        UFG::Metrics::msInstance.mSimTimeScaleInGame = UFG::Metrics::msInstance.mSimTimeScaleMax;
        if ( UFG::Metrics::msInstance.mSimTimeScaleMax == 0.0 )
        {
          v33 = 1;
          goto LABEL_92;
        }
      }
      else
      {
        UFG::Metrics::msInstance.mSimTimeScaleInGame = 1.0;
      }
      v33 = 0;
LABEL_92:
      UFG::Metrics::msInstance.mSimPausedInGame = v33;
      UFG::Metrics::msInstance.mSimTimeDeltaStep = 0.0;
      UFG::RenderWorld::AccumulationBufferPostEffect_SetEnable(0);
      if ( UFG::AmbienceAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(UFG::AmbienceAudio::m_instance, qwsStopTimeDilate_0.mUID, 0i64, 0, 0i64);
      goto LABEL_94;
    }
  }
}

// File Line: 1130
// RVA: 0x5E42E0
void __fastcall UFG::UIHKSocialActionWidget::Flash_ShowChargeMeter(
        UFG::UIHKSocialActionWidget *this,
        UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *pObject; // rdi
  float v4; // xmm6_4
  float v5; // xmm6_4
  long double mID; // xmm1_8
  Scaleform::GFx::Value value; // [rsp+38h] [rbp-80h] BYREF
  Scaleform::GFx::Value ptr; // [rsp+68h] [rbp-50h] BYREF

  if ( !this->mPlayingActionResult )
  {
    if ( screen )
    {
      pObject = screen->mRenderable->m_movie.pObject;
      if ( pObject )
      {
        v4 = this->mElapsedTime / (float)(this->mDuration + 0.0000099999997);
        if ( v4 >= 1.0 )
          v4 = *(float *)&FLOAT_1_0;
        v5 = v4 * 100.0;
        this->mChargeVisible = 1;
        `eh vector constructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
        if ( (ptr.Type & 0x40) != 0 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
            ptr.pObjectInterface,
            &ptr,
            ptr.mValue);
          ptr.pObjectInterface = 0i64;
        }
        ptr.Type = VT_Number;
        ptr.mValue.NValue = v5;
        mID = (double)this->mID;
        value.pObjectInterface = 0i64;
        value.Type = VT_Number;
        value.mValue.NValue = mID;
        Scaleform::GFx::Movie::SetVariable(pObject, "mMovieIndex", &value, 1i64);
        if ( (value.Type & 0x40) != 0 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
            value.pObjectInterface,
            &value,
            value.mValue);
          value.pObjectInterface = 0i64;
        }
        value.Type = VT_Undefined;
        Scaleform::GFx::Movie::Invoke(pObject, "FaceAction_showFaceCharge", 0i64, &ptr, 1u);
        `eh vector destructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
      }
    }
  }
}

// File Line: 1155
// RVA: 0x5DBC20
void __fastcall UFG::UIHKSocialActionWidget::Flash_HideChargeMeter(
        UFG::UIHKSocialActionWidget *this,
        UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *pObject; // rbx
  long double mID; // xmm0_8
  Scaleform::GFx::Value v5; // [rsp+38h] [rbp-40h] BYREF

  if ( screen )
  {
    pObject = screen->mRenderable->m_movie.pObject;
    if ( pObject )
    {
      this->mChargeVisible = 0;
      mID = (double)this->mID;
      v5.pObjectInterface = 0i64;
      v5.Type = VT_Number;
      v5.mValue.NValue = mID;
      Scaleform::GFx::Movie::SetVariable(pObject, "mMovieIndex", &v5, 1i64);
      if ( (v5.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&v5.pObjectInterface->vfptr->gap8[8])(
          v5.pObjectInterface,
          &v5,
          v5.mValue);
        v5.pObjectInterface = 0i64;
      }
      v5.Type = VT_Undefined;
      Scaleform::GFx::Movie::Invoke(pObject, "FaceAction_hideFaceCharge", 0i64, 0i64, 0);
      this->mPlayingActionResult = 0;
    }
  }
}

// File Line: 1173
// RVA: 0x5E49F0
void __fastcall UFG::UIHKSocialActionWidget::Flash_ShowHelpBar(
        UFG::UIHKSocialActionWidget *this,
        UFG::UIScreen *screen)
{
  char *mData; // rbx
  const char *caption0; // rax
  __int64 v5; // rdx
  UFG::UIGfxTranslator *m_translator; // rcx
  UFG::FaceActionComponent *mActionComponent; // rcx
  UFG::UIHKScreenHud *v8; // rax
  UFG::eInventoryItemEnum mInventoryItem; // ecx

  mData = this->mItemCaption.mData;
  if ( mData )
  {
    if ( *mData == 36 )
      ++mData;
    v5 = (unsigned int)UFG::qStringHashUpper32(mData, -1);
    m_translator = UFG::UIScreenManager::s_instance->m_translator;
    if ( !m_translator || (caption0 = (const char *)m_translator->vfptr[5].__vecDelDtor(m_translator, v5)) == 0i64 )
      caption0 = mData;
  }
  else
  {
    caption0 = 0i64;
  }
  UFG::UIHKGameplayHelpWidget::Show(
    UFG::UIHKScreenHud::GameplayHelp,
    UI_HASH_HELPBAR_SOCIAL_20,
    2u,
    BUTTON2_BUTTON,
    caption0,
    INVALID_BUTTON,
    &customCaption);
  mActionComponent = this->mActionComponent;
  if ( this->mConversationFaceType == eFACEACTION_PURCHASE )
  {
    if ( mActionComponent )
    {
      if ( this->mItemPrice )
      {
        v8 = UFG::UIHKScreenHud::mInstance;
        if ( UFG::UIHKScreenHud::mInstance )
        {
          mInventoryItem = mActionComponent->mInventoryItem;
          if ( mInventoryItem )
          {
            if ( mInventoryItem != eINVENTORY_ITEM_BET_STANDARD )
            {
              *(_WORD *)&UFG::UIHKScreenHud::mInstance->MoneyPopup.mForceShow = 257;
              v8->MoneyPopup.mLeaveOnChanged = 1;
            }
          }
        }
      }
    }
  }
}

// File Line: 1193
// RVA: 0x5E3E60
void __fastcall UFG::UIHKSocialActionWidget::Flash_ShowActionIcon(
        UFG::UIHKSocialActionWidget *this,
        UFG::UIScreen *screen)
{
  unsigned int mUID; // ebx
  const char *v4; // rax
  const char *v5; // rsi
  int v6; // ecx
  __int64 v7; // rax
  __int64 v8; // rbx
  int v9; // ecx
  __int64 v10; // rax
  __int64 v11; // rbx
  UFG::FaceActionComponent *mActionComponent; // rcx
  UFG::UIHKScreenHud *v13; // rax
  UFG::eInventoryItemEnum mInventoryItem; // edx
  UFG::UIHKGameplayHelpData data; // [rsp+50h] [rbp-A8h] BYREF
  UFG::qSymbol type; // [rsp+150h] [rbp+58h] BYREF

  if ( !screen || !screen->mRenderable->m_movie.pObject )
    return;
  mUID = qSymbol_Chat_20.mUID;
  if ( (unsigned int)UFG::qStringCompare(this->mItemIcon.mData, "porkbun", -1) )
  {
    if ( (unsigned int)UFG::qStringCompare(this->mItemIcon.mData, "tea", -1) )
    {
      if ( (unsigned int)UFG::qStringCompare(this->mItemIcon.mData, "massage", -1) )
      {
        if ( (unsigned int)UFG::qStringCompare(this->mItemIcon.mData, "extort", -1) )
        {
          if ( (unsigned int)UFG::qStringCompare(this->mItemIcon.mData, "bribe", -1) )
          {
            if ( (unsigned int)UFG::qStringCompare(this->mItemIcon.mData, "purchase", -1) )
            {
              if ( (unsigned int)UFG::qStringCompare(this->mItemIcon.mData, "realestate", -1) )
              {
                if ( (unsigned int)UFG::qStringCompare(this->mItemIcon.mData, "clothing", -1) )
                {
                  if ( (unsigned int)UFG::qStringCompare(this->mItemIcon.mData, "gun", -1) )
                  {
                    if ( (unsigned int)UFG::qStringCompare(this->mItemIcon.mData, "drink", -1) )
                    {
                      if ( !(unsigned int)UFG::qStringCompare(this->mItemIcon.mData, "informant", -1) )
                        mUID = qSymbol_Informant_20.mUID;
                    }
                    else
                    {
                      mUID = qSymbol_Drink_20.mUID;
                    }
                  }
                  else
                  {
                    mUID = qSymbol_Weapon_20.mUID;
                  }
                }
                else
                {
                  mUID = qSymbol_Clothing_20.mUID;
                }
              }
              else
              {
                mUID = qSymbol_Purchase_20.mUID;
              }
            }
            else
            {
              mUID = qSymbol_Purchase_20.mUID;
            }
          }
          else
          {
            mUID = qSymbol_Bribe_20.mUID;
          }
        }
        else
        {
          mUID = qSymbol_Extortion_20.mUID;
        }
      }
      else
      {
        mUID = qSymbol_Massage_20.mUID;
      }
    }
    else
    {
      mUID = qSymbol_Tea_20.mUID;
    }
  }
  else
  {
    mUID = qSymbol_Food_20.mUID;
  }
  type.mUID = mUID;
  if ( !this->mItemDescription.mLength || !UFG::UIHKScreenHud::InfoPopup )
  {
    v4 = UFG::UI::LocalizeText(this->mItemCaption.mData);
    v5 = v4;
    if ( mUID == qSymbol_Informant_20.mUID || mUID == qSymbol_Chat_20.mUID )
    {
      UFG::UIHKGameplayHelpData::UIHKGameplayHelpData(&data);
      data.id = UI_HASH_HELPBAR_SOCIAL_20;
      data.priority = 2;
      v9 = 0;
      v10 = 0i64;
      while ( data.Buttons[v10] )
      {
        ++v9;
        if ( ++v10 >= 2 )
          goto LABEL_44;
      }
      data.Buttons[v9] = BUTTON2_BUTTON;
      v11 = v9;
      UFG::qString::Set(&data.Captions[v11], v5);
      UFG::qString::Set((UFG::qString *)&data.Captions[v11 + 1].mStringHash32, &customCaption);
LABEL_44:
      UFG::qString::Set((UFG::qString *)&data.Captions[1].mStringHash32, "Icon_Interact");
      UFG::UIHKGameplayHelpWidget::Show(UFG::UIHKScreenHud::GameplayHelp, &data);
      UFG::qString::~qString((UFG::qString *)data.ChargeAnimState);
      `eh vector destructor iterator(
        &data.Captions[1].mStringHash32,
        0x28ui64,
        2,
        (void (__fastcall *)(void *))UFG::qString::~qString);
    }
    else
    {
      if ( mUID != qSymbol_Purchase_20.mUID && mUID != qSymbol_Clothing_20.mUID )
        goto LABEL_28;
      UFG::UIHKGameplayHelpData::UIHKGameplayHelpData(&data);
      data.id = UI_HASH_HELPBAR_SOCIAL_20;
      data.priority = 2;
      v6 = 0;
      v7 = 0i64;
      while ( data.Buttons[v7] )
      {
        ++v6;
        if ( ++v7 >= 2 )
          goto LABEL_38;
      }
      data.Buttons[v6] = BUTTON2_BUTTON;
      v8 = v6;
      UFG::qString::Set(&data.Captions[v8], v5);
      UFG::qString::Set((UFG::qString *)&data.Captions[v8 + 1].mStringHash32, &customCaption);
LABEL_38:
      UFG::qString::Set((UFG::qString *)&data.Captions[1].mStringHash32, "Icon_Purchase");
      UFG::UIHKGameplayHelpWidget::Show(UFG::UIHKScreenHud::GameplayHelp, &data);
      UFG::qString::~qString((UFG::qString *)data.ChargeAnimState);
      `eh vector destructor iterator(
        &data.Captions[1].mStringHash32,
        0x28ui64,
        2,
        (void (__fastcall *)(void *))UFG::qString::~qString);
    }
    `eh vector destructor iterator(data.Captions, 0x28ui64, 2, (void (__fastcall *)(void *))UFG::qString::~qString);
    goto LABEL_46;
  }
  UFG::UIHKInfoPopupWidget::ShowPurchaseInfo(
    UFG::UIHKScreenHud::InfoPopup,
    this->mItemName.mData,
    this->mItemDescription.mData,
    this->mItemPrice,
    &type);
  v4 = UFG::UI::LocalizeText(this->mItemCaption.mData);
LABEL_28:
  UFG::UIHKGameplayHelpWidget::Show(
    UFG::UIHKScreenHud::GameplayHelp,
    UI_HASH_HELPBAR_SOCIAL_20,
    2u,
    BUTTON2_BUTTON,
    v4,
    INVALID_BUTTON,
    &customCaption);
LABEL_46:
  mActionComponent = this->mActionComponent;
  if ( this->mConversationFaceType == eFACEACTION_PURCHASE )
  {
    if ( mActionComponent )
    {
      if ( this->mItemPrice )
      {
        v13 = UFG::UIHKScreenHud::mInstance;
        if ( UFG::UIHKScreenHud::mInstance )
        {
          mInventoryItem = mActionComponent->mInventoryItem;
          if ( mInventoryItem )
          {
            if ( mInventoryItem != eINVENTORY_ITEM_BET_STANDARD )
            {
              *(_WORD *)&UFG::UIHKScreenHud::mInstance->MoneyPopup.mForceShow = 257;
              v13->MoneyPopup.mLeaveOnChanged = 1;
            }
          }
        }
      }
    }
  }
}

// File Line: 1332
// RVA: 0x5E4490
void __fastcall UFG::UIHKSocialActionWidget::Flash_ShowCloseIcon(
        UFG::UIHKSocialActionWidget *this,
        UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *pObject; // rdi
  char *mData; // rsi
  char *v5; // rsi
  double mPipLevel; // xmm6_8
  long double mID; // xmm0_8
  Scaleform::GFx::Value value; // [rsp+30h] [rbp-B8h] BYREF
  Scaleform::GFx::Value ptr; // [rsp+60h] [rbp-88h] BYREF
  int v10; // [rsp+90h] [rbp-58h]
  char *v11; // [rsp+98h] [rbp-50h]
  char v12[16]; // [rsp+A8h] [rbp-40h] BYREF
  __int64 v13; // [rsp+B8h] [rbp-30h]
  int v14; // [rsp+C0h] [rbp-28h]
  double v15; // [rsp+C8h] [rbp-20h]
  __int64 v16; // [rsp+D8h] [rbp-10h]

  if ( screen )
  {
    v16 = -2i64;
    pObject = screen->mRenderable->m_movie.pObject;
    if ( pObject )
    {
      if ( this->mActionEnabled )
        UFG::UIHKSocialActionWidget::SetPipAction(this);
      `eh vector constructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      mData = this->mItemIcon.mData;
      if ( (ptr.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value *))&ptr.pObjectInterface->vfptr->gap8[8])(
          ptr.pObjectInterface,
          &ptr,
          ptr.pNext);
        ptr.pObjectInterface = 0i64;
      }
      ptr.Type = VT_String;
      ptr.pNext = (Scaleform::GFx::Value *)mData;
      v5 = this->mPipActionStr.mData;
      if ( (v10 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(unsigned __int64, Scaleform::GFx::Value::ValueType *, char *))(*(_QWORD *)ptr.DataAux
                                                                                             + 16i64))(
          ptr.DataAux,
          &ptr.Type,
          v11);
        ptr.DataAux = 0i64;
      }
      v10 = 6;
      v11 = v5;
      mPipLevel = (double)(int)this->mPipLevel;
      if ( (v14 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v13 + 16i64))(
          v13,
          v12,
          COERCE_DOUBLE(*(_QWORD *)&v15));
        v13 = 0i64;
      }
      v14 = 5;
      v15 = mPipLevel;
      mID = (double)this->mID;
      value.pObjectInterface = 0i64;
      value.Type = VT_Number;
      value.mValue.NValue = mID;
      Scaleform::GFx::Movie::SetVariable(pObject, "mMovieIndex", &value, 1i64);
      if ( (value.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
          value.pObjectInterface,
          &value,
          value.mValue);
        value.pObjectInterface = 0i64;
      }
      value.Type = VT_Undefined;
      Scaleform::GFx::Movie::Invoke(pObject, "FaceAction_showCloseIcon", 0i64, &ptr, 3u);
      `eh vector destructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    }
  }
}

// File Line: 1358
// RVA: 0x606DF0
void __fastcall UFG::UIHKSocialActionWidget::SetPipAction(UFG::UIHKSocialActionWidget *this)
{
  __int64 v1; // rbx
  int v3; // r8d
  const char *v4; // rdx
  const char *v5; // rdx
  UFG::qString v6; // [rsp+38h] [rbp-30h] BYREF
  __int64 v7; // [rsp+60h] [rbp-8h]

  v7 = v1;
  UFG::qString::qString(&v6, &customCaption);
  if ( this->mMinPipsRequired <= this->mPlayerPipLevel )
  {
    v3 = 2;
    v4 = "on";
  }
  else
  {
    v3 = 3;
    v4 = "off";
  }
  UFG::qString::append(&v6, v4, v3);
  switch ( this->mMinPipsRequired )
  {
    case 1:
      v5 = "1";
      break;
    case 2:
      v5 = "2";
      break;
    case 3:
      v5 = "3";
      break;
    case 4:
      v5 = "4";
      break;
    case 5:
      v5 = "5";
      break;
    default:
      v5 = "0";
      break;
  }
  UFG::qString::append(&v6, v5, 1);
  UFG::qString::Set(&this->mPipActionStr, v6.mData, v6.mLength, 0i64, 0);
  UFG::qString::~qString(&v6);
}

// File Line: 1435
// RVA: 0x5E47D0
void __fastcall UFG::UIHKSocialActionWidget::Flash_ShowFarIcon(
        UFG::UIHKSocialActionWidget *this,
        UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *pObject; // rdi
  char *mData; // rsi
  char *v5; // rsi
  double mPipLevel; // xmm6_8
  long double mID; // xmm0_8
  Scaleform::GFx::Value value; // [rsp+30h] [rbp-B8h] BYREF
  Scaleform::GFx::Value ptr; // [rsp+60h] [rbp-88h] BYREF
  int v10; // [rsp+90h] [rbp-58h]
  char *v11; // [rsp+98h] [rbp-50h]
  char v12[16]; // [rsp+A8h] [rbp-40h] BYREF
  __int64 v13; // [rsp+B8h] [rbp-30h]
  int v14; // [rsp+C0h] [rbp-28h]
  double v15; // [rsp+C8h] [rbp-20h]
  __int64 v16; // [rsp+D8h] [rbp-10h]

  if ( screen )
  {
    v16 = -2i64;
    pObject = screen->mRenderable->m_movie.pObject;
    if ( pObject )
    {
      if ( this->mActionEnabled )
        UFG::UIHKSocialActionWidget::SetPipAction(this);
      `eh vector constructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      mData = this->mItemIcon.mData;
      if ( (ptr.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value *))&ptr.pObjectInterface->vfptr->gap8[8])(
          ptr.pObjectInterface,
          &ptr,
          ptr.pNext);
        ptr.pObjectInterface = 0i64;
      }
      ptr.Type = VT_String;
      ptr.pNext = (Scaleform::GFx::Value *)mData;
      v5 = this->mPipActionStr.mData;
      if ( (v10 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(unsigned __int64, Scaleform::GFx::Value::ValueType *, char *))(*(_QWORD *)ptr.DataAux
                                                                                             + 16i64))(
          ptr.DataAux,
          &ptr.Type,
          v11);
        ptr.DataAux = 0i64;
      }
      v10 = 6;
      v11 = v5;
      mPipLevel = (double)(int)this->mPipLevel;
      if ( (v14 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v13 + 16i64))(
          v13,
          v12,
          COERCE_DOUBLE(*(_QWORD *)&v15));
        v13 = 0i64;
      }
      v14 = 5;
      v15 = mPipLevel;
      mID = (double)this->mID;
      value.pObjectInterface = 0i64;
      value.Type = VT_Number;
      value.mValue.NValue = mID;
      Scaleform::GFx::Movie::SetVariable(pObject, "mMovieIndex", &value, 1i64);
      if ( (value.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
          value.pObjectInterface,
          &value,
          value.mValue);
        value.pObjectInterface = 0i64;
      }
      value.Type = VT_Undefined;
      Scaleform::GFx::Movie::Invoke(pObject, "FaceAction_showFarIcon", 0i64, &ptr, 3u);
      `eh vector destructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    }
  }
}

// File Line: 1460
// RVA: 0x5DBA80
void __fastcall UFG::UIHKSocialActionWidget::Flash_HideActionIcon(
        UFG::UIHKSocialActionWidget *this,
        UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *pObject; // rdi
  UFG::UIHKScreenHud *v4; // rax
  UFG::UIHKInfoPopupWidget::eState mState; // ecx
  long double mID; // xmm0_8
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-38h] BYREF

  if ( screen )
  {
    pObject = screen->mRenderable->m_movie.pObject;
    if ( pObject )
    {
      if ( !this->mID )
      {
        UFG::UIHKGameplayHelpWidget::Hide(UFG::UIHKScreenHud::GameplayHelp, UI_HASH_HELPBAR_SOCIAL_20);
        v4 = UFG::UIHKScreenHud::mInstance;
        if ( UFG::UIHKScreenHud::mInstance )
        {
          *(_WORD *)&UFG::UIHKScreenHud::mInstance->MoneyPopup.mLeaveOn = 256;
          v4->MoneyPopup.mTryToHide = 1;
          v4->MoneyPopup.mForceShow = 1;
        }
        if ( this->mItemDescription.mLength )
        {
          if ( UFG::UIHKScreenHud::InfoPopup )
          {
            mState = UFG::UIHKScreenHud::InfoPopup->mState;
            if ( mState )
            {
              if ( mState != STATE_OUTGOING_CALL )
                UFG::UIHKScreenHud::InfoPopup->mState = STATE_INCOMING_CALL;
            }
          }
        }
        if ( this->mPedChanged )
        {
          this->mPedChanged = 0;
          value.pObjectInterface = 0i64;
          value.Type = VT_Boolean;
          value.mValue.BValue = 0;
          Scaleform::GFx::Movie::SetVariable(pObject, "mc_FaceAction0._visible", &value, 1i64);
          if ( (value.Type & 0x40) != 0 )
          {
            (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
              value.pObjectInterface,
              &value,
              value.mValue);
            value.pObjectInterface = 0i64;
          }
          value.Type = VT_Undefined;
        }
      }
      mID = (double)this->mID;
      value.pObjectInterface = 0i64;
      value.Type = VT_Number;
      value.mValue.NValue = mID;
      Scaleform::GFx::Movie::SetVariable(pObject, "mMovieIndex", &value, 1i64);
      if ( (value.Type & 0x40) != 0 )
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
          value.pObjectInterface,
          &value,
          value.mValue);
    }
  }
}

// File Line: 1533
// RVA: 0x5EC340
void __fastcall UFG::UIHKSocialActionWidget::HandleTextureLoaded(
        UFG::UIHKSocialActionWidget *this,
        UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *pObject; // rcx

  if ( screen )
  {
    pObject = screen->mRenderable->m_movie.pObject;
    if ( pObject )
      Scaleform::GFx::Movie::Invoke(pObject, "handleTextureLoaded", 0i64, 0i64, 0);
  }
}

