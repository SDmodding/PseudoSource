// File Line: 43
// RVA: 0x15707C0
__int64 UFG::_dynamic_initializer_for__qwsPlayTimeDilate__()
{
  UFG::qWiseSymbol::create_from_string(&qwsPlayTimeDilate_0, "PLAY_TIME_DILATE");
  return atexit(UFG::_dynamic_atexit_destructor_for__qwsPlayTimeDilate__);
}

// File Line: 44
// RVA: 0x15707F0
__int64 UFG::_dynamic_initializer_for__qwsStopTimeDilate__()
{
  UFG::qWiseSymbol::create_from_string(&qwsStopTimeDilate_0, "STOP_TIME_DILATE");
  return atexit(UFG::_dynamic_atexit_destructor_for__qwsStopTimeDilate__);
}

// File Line: 90
// RVA: 0x5C7FB0
void __fastcall UFG::UIHKSocialActionWidget::UIHKSocialActionWidget(UFG::UIHKSocialActionWidget *this)
{
  UFG::UIHKSocialActionWidget *v1; // rbx

  v1 = this;
  this->m_ePreviousState = 0;
  this->mPipLevel = 11;
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
  this->mActionDistance = 0;
  UFG::qString::qString(&this->mActionType);
  UFG::qString::qString(&v1->mPipActionStr);
  UFG::qString::qString(&v1->mItemName);
  UFG::qString::qString(&v1->mItemCaption);
  UFG::qString::qString(&v1->mItemDescription);
  UFG::qString::qString(&v1->mItemIcon);
  *(_QWORD *)&v1->mPlayTime = 0i64;
  *(_QWORD *)&v1->mChargeValue = 0i64;
  v1->mGameSpeed = 50;
  *(_QWORD *)&v1->mTargetSize = 30i64;
  *(_QWORD *)&v1->mQuantity = 0i64;
  *(_QWORD *)&v1->mMinPipsRequired = -1i64;
  v1->mID = -1;
  *(_QWORD *)&v1->mActionEnabled = 256i64;
  *(_WORD *)&v1->mChargeHappened = 0;
  v1->mHelpbarLocked = 0;
  v1->mWidgetNameOnStage.pObjectInterface = 0i64;
  v1->mWidgetNameOnStage.Type = 0;
  *(_QWORD *)&v1->mChargeStatus = 0i64;
}

// File Line: 95
// RVA: 0x5CD5C0
void __fastcall UFG::UIHKSocialActionWidget::~UIHKSocialActionWidget(UFG::UIHKSocialActionWidget *this)
{
  UFG::UIHKSocialActionWidget *v1; // rbx
  unsigned int v2; // eax
  bool v3; // al
  int v4; // eax

  v1 = this;
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
    if ( v1->mActionComponent->mMinigameTimeWarpFactor < 1.0 )
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
        UFG::AudioEntity::CreateAndPlayEvent(
          (UFG::AudioEntity *)&UFG::AmbienceAudio::m_instance->vfptr,
          qwsStopTimeDilate_0.mUID,
          0i64,
          0,
          0i64);
      goto LABEL_15;
    }
  }
LABEL_15:
  if ( v1->mHelpbarLocked )
  {
    v1->mHelpbarLocked = 0;
    UFG::UIHKGameplayHelpWidget::mSocialLock = 0;
    v4 = UFG::UIHKGameplayHelpWidget::mLocked;
    if ( UFG::UIHKGameplayHelpWidget::mLocked > 0 )
      v4 = UFG::UIHKGameplayHelpWidget::mLocked-- - 1;
    if ( v4 < 1 )
      UFG::UIHKScreenHud::GameplayHelp->mChanged = 1;
  }
  UFG::UIHKSocialActionWidget::mTextureLoaded = 0;
  if ( ((unsigned int)v1->mWidgetNameOnStage.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&v1->mWidgetNameOnStage.pObjectInterface->vfptr->gap8[8])(
      v1->mWidgetNameOnStage.pObjectInterface,
      &v1->mWidgetNameOnStage,
      *(_QWORD *)&v1->mWidgetNameOnStage.mValue.NValue);
    v1->mWidgetNameOnStage.pObjectInterface = 0i64;
  }
  v1->mWidgetNameOnStage.Type = 0;
  UFG::qString::~qString(&v1->mItemIcon);
  UFG::qString::~qString(&v1->mItemDescription);
  UFG::qString::~qString(&v1->mItemCaption);
  UFG::qString::~qString(&v1->mItemName);
  UFG::qString::~qString(&v1->mPipActionStr);
  UFG::qString::~qString(&v1->mActionType);
}

// File Line: 183
// RVA: 0x604EF0
void __fastcall UFG::UIHKSocialActionWidget::SetActionComponent(UFG::UIHKSocialActionWidget *this, UFG::FaceActionComponent *actionComponent, float score)
{
  bool v3; // zf
  UFG::UIHKSocialActionWidget *v4; // r14
  bool v5; // r8
  bool v6; // cl
  unsigned int v7; // er13
  const char *v8; // rbx
  char *v9; // rdi
  char *v10; // rbp
  char *v11; // rsi
  const char *v12; // r15
  const char *v13; // r12
  const char *v14; // rbx
  const char *v15; // rdi
  int v16; // eax
  int v17; // [rsp+68h] [rbp+10h]

  if ( actionComponent )
  {
    v3 = actionComponent == this->mActionComponent;
    this->mActionComponent = actionComponent;
    v4 = this;
    this->mActionChanged |= !v3;
    this->mPedChanged |= !v3;
    this->mActionChanged |= this->m_ePreviousState != actionComponent->mState;
    this->m_ePreviousState = actionComponent->mState;
    v5 = actionComponent->mMinigameEnabled;
    v6 = this->mStartGame;
    v4->mActionChanged |= v5 != v6;
    if ( v5 != v6 )
      v4->mStartGame = v5;
    v7 = actionComponent->mItemPrice;
    v8 = actionComponent->mItemIcon;
    v17 = actionComponent->mMininumRequirement;
    v9 = actionComponent->mItemName;
    v10 = UFG::FaceActionComponent::GetItemCaption(actionComponent);
    v11 = UFG::FaceActionComponent::GetItemDescription(v4->mActionComponent);
    v12 = &customWorldMapCaption;
    v4->mConversationFaceType = UFG::FaceActionComponent::GetDialogueConversationFaceAction(v4->mActionComponent);
    v13 = &customWorldMapCaption;
    if ( v8 )
      v13 = v8;
    v14 = &customWorldMapCaption;
    if ( v9 )
      v14 = v9;
    v15 = &customWorldMapCaption;
    if ( v11 )
      v15 = v11;
    if ( v10 )
      v12 = v10;
    if ( v17 != v4->mMinPipsRequired
      || v7 != v4->mItemPrice
      || (unsigned int)UFG::qStringCompare(v13, v4->mItemIcon.mData, -1)
      || (unsigned int)UFG::qStringCompare(v14, v4->mItemName.mData, -1)
      || (v16 = UFG::qStringCompare(v12, v4->mItemCaption.mData, -1)) != 0 )
    {
      LOBYTE(v16) = 1;
    }
    v4->mActionChanged |= v16;
    v4->mScore = score;
    v4->mMinPipsRequired = v17;
    v4->mItemPrice = v7;
    UFG::qString::Set(&v4->mItemIcon, v13);
    UFG::qString::Set(&v4->mItemName, v14);
    UFG::qString::Set(&v4->mItemDescription, v15);
    UFG::qString::Set(&v4->mItemCaption, v12);
  }
}

// File Line: 268
// RVA: 0x5F41A0
void __fastcall UFG::UIHKSocialActionWidget::PlaySuccessfulInteraction(UFG::UIHKSocialActionWidget *this)
{
  Scaleform::GFx::Movie *v1; // rax

  if ( !this->mPlayingActionResult )
  {
    v1 = UFG::UIHKScreenHud::mInstance->mRenderable->m_movie.pObject;
    if ( v1 )
    {
      this->mPlayingActionResult = 1;
      Scaleform::GFx::Movie::Invoke(v1, "FaceAction_playSuccessfulInteraction", 0i64, 0i64, 0);
    }
  }
}

// File Line: 390
// RVA: 0x5EAFB0
void __fastcall UFG::UIHKSocialActionWidget::HandleMessage(UFG::UIHKSocialActionWidget *this, UFG::UIScreen *screen, unsigned int msgId, UFG::UIMessage *msg)
{
  UFG::UIMessage *v4; // rsi
  unsigned int v5; // edi
  UFG::UIScreen *v6; // rbp
  UFG::UIHKSocialActionWidget *v7; // rbx
  UFG::UI *v8; // rcx
  UFG::FaceActionComponent *v9; // rax
  float v10; // xmm0_4
  bool v11; // al
  Scaleform::GFx::Movie *v12; // rsi
  UFG::qString v13; // [rsp+38h] [rbp-70h]
  Scaleform::GFx::Value value; // [rsp+60h] [rbp-48h]

  v4 = msg;
  v5 = msgId;
  v6 = screen;
  v7 = this;
  if ( this->mID != -1 )
  {
    v8 = (UFG::UI *)(unsigned int)UI_HASH_BUTTON_BUTTON2_PRESSED_30;
    if ( !v7->mChargeHappened )
    {
      v9 = v7->mActionComponent;
      if ( v9 )
      {
        if ( !v9->mMinigameSetup && v9->mState == 4 && msgId == (_DWORD)UI_HASH_BUTTON_BUTTON2_PRESSED_30 )
          v7->mChargeHappened = 1;
      }
    }
    if ( msgId == UI_HASH_ACTION_RESULT_DONE_20 || !v7->mPlayingActionResult )
    {
      if ( !v7->mPlayingTargetGame || !v7->mRenderingTargetGame )
        goto LABEL_41;
      if ( msgId == (_DWORD)v8 )
      {
        v7->mIsMidMiniGame = 1;
        UFG::UI::LockGameplayInput(v8);
        v10 = v7->mActionComponent->mMinigameTimeWarpFactor;
        if ( v10 < 1.0 )
        {
          if ( v10 <= 0.0 )
            v10 = 0.0;
          if ( v10 >= UFG::Metrics::msInstance.mSimTimeScaleMax )
            v10 = UFG::Metrics::msInstance.mSimTimeScaleMax;
          UFG::Metrics::msInstance.mSimTimeScaleInGame = v10;
          UFG::Metrics::msInstance.mSimPausedInGame = v10 == 0.0;
          UFG::Metrics::msInstance.mSimTimeDeltaStep = 0.0;
          UFG::RenderWorld::AccumulationBufferPostEffect_SetEnable(v7->mActionComponent->mMinigameMotionDilation > 0.1);
          v8 = (UFG::UI *)UFG::AmbienceAudio::m_instance;
          if ( UFG::AmbienceAudio::m_instance )
            UFG::AudioEntity::CreateAndPlayEvent(
              (UFG::AudioEntity *)&UFG::AmbienceAudio::m_instance->vfptr,
              qwsPlayTimeDilate_0.mUID,
              0i64,
              0,
              0i64);
        }
      }
      if ( v5 == UI_HASH_TIMED_GAME_OUTRO_DONE_20 )
        v7->mChargeState = 0;
      if ( v5 != UI_HASH_TIMED_GAME_RESULT_20 || !v7->mPlayingTargetGame )
        goto LABEL_41;
      v7->mIsMidMiniGame = 0;
      UFG::UI::UnlockGameplayInput(v8);
      if ( v7->mActionComponent->mMinigameTimeWarpFactor >= 1.0 )
      {
LABEL_32:
        UFG::qString::qString(&v13, (UFG::qString *)&v4[1]);
        if ( (unsigned int)UFG::qStringCompare(v13.mData, "SUCCESS", -1) )
        {
          if ( (unsigned int)UFG::qStringCompare(v13.mData, "FAILURE", -1) )
            goto LABEL_40;
          v7->mGameResult = 4;
        }
        else
        {
          v7->mGameResult = 3;
        }
        v7->mActionComponent->mMiniGameResult = v7->mGameResult;
        v7->mChargeHappened = 1;
        v12 = v6->mRenderable->m_movie.pObject;
        if ( v12 )
        {
          value.pObjectInterface = 0i64;
          value.Type = 2;
          value.mValue.BValue = 0;
          Scaleform::GFx::Movie::SetVariable(v12, "mcFaceGame._visible", &value, 1i64);
          if ( ((unsigned int)value.Type >> 6) & 1 )
          {
            (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
              value.pObjectInterface,
              &value,
              *(_QWORD *)&value.mValue.NValue);
            value.pObjectInterface = 0i64;
          }
          value.Type = 0;
          UFG::qString::~qString(&v13);
LABEL_41:
          if ( v5 == UI_HASH_ACTION_RESULT_DONE_20 )
          {
            v7->mPlayingActionResult = 0;
            v7->mActionChanged = 1;
            v7->mShouldHideActionIcon = 1;
            UFG::qString::Set(&v7->mItemIcon, &customWorldMapCaption);
            v7->mActionChanged = 1;
            v7->mActionDistance = 0;
            v7->mPlayingActionResult = 0;
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
        UFG::AudioEntity::CreateAndPlayEvent(
          (UFG::AudioEntity *)&UFG::AmbienceAudio::m_instance->vfptr,
          qwsStopTimeDilate_0.mUID,
          0i64,
          0,
          0i64);
      goto LABEL_32;
    }
  }
}

// File Line: 555
// RVA: 0x617770
void __fastcall UFG::UIHKSocialActionWidget::Update(UFG::UIHKSocialActionWidget *this, UFG::UIScreen *screen, float elapsed, bool charging)
{
  UFG::UIScreen *v4; // rdi
  UFG::UIHKSocialActionWidget *v5; // rbx
  UFG::FaceActionComponent *v6; // r8
  UFG::SimComponent *v7; // rcx
  signed __int64 v8; // rdx
  __int64 v9; // rax
  UFG::SimObject *v10; // rcx
  UFG::FaceActionComponent *v11; // rcx
  UFG::eFaceActionState v12; // edx
  UFG::FaceActionComponent *v13; // rax
  UFG::eFaceActionState v14; // ecx
  int v15; // eax
  BOOL v16; // ecx
  float v17; // xmm0_4
  UFG::FaceActionComponent *v18; // rax
  int v19; // ecx
  int v20; // ecx
  float v21; // xmm0_4
  UFG::GameStatTracker *v22; // rax
  Scaleform::GFx::Movie *v23; // r14
  UFG::FaceActionComponent *v24; // rax
  __int64 v25; // rsi
  UFG::InputActionData *v26; // rax
  float v27; // xmm6_4
  __m128 v28; // xmm1
  signed int v29; // ecx
  UFG::InputActionData *v30; // rax
  float v31; // xmm0_4
  UFG::UI *v32; // rcx
  bool v33; // al
  UFG::UIHKSocialActionWidget::eFaceChargeState v34; // eax
  float v35; // xmm1_4
  UFG::eDistance v36; // ecx
  int v37; // ecx
  int v38; // ecx
  int v39; // ecx
  double v40; // xmm6_8
  double v41; // xmm6_8
  UFG::UIHKScreenHud *v42; // rax
  double v43; // xmm6_8
  double v44; // xmm6_8
  float v45; // xmm0_4
  char v46; // al
  float v47; // xmm1_4
  char v48; // al
  char v49; // al
  double v50; // xmm6_8
  double v51; // xmm6_8
  Scaleform::GFx::Value value; // [rsp+30h] [rbp-A8h]
  char ptr; // [rsp+60h] [rbp-78h]
  UFG::qString v54; // [rsp+68h] [rbp-70h]
  __int64 v55; // [rsp+90h] [rbp-48h]
  UFG::qString v56; // [rsp+98h] [rbp-40h]

  v55 = -2i64;
  v4 = screen;
  v5 = this;
  if ( this->mShouldHideActionIcon )
  {
    this->mShouldHideActionIcon = 0;
    UFG::UIHKSocialActionWidget::Flash_HideActionIcon(this, screen);
  }
  if ( v5->mID == -1 )
    return;
  v6 = 0i64;
  if ( LocalPlayer )
  {
    v7 = LocalPlayer->m_Components.p[20].m_pComponent;
    if ( v7 )
    {
      v8 = 56i64 * *(unsigned __int8 *)(*(_QWORD *)&v7[1].m_Flags + 58i64);
      v9 = *(_QWORD *)&v7[1].m_TypeUID;
      v10 = *(UFG::SimObject **)(v8 + v9 + 40);
      if ( v10 )
      {
        if ( *(_BYTE *)(v8 + v9 + 49) )
          v6 = (UFG::FaceActionComponent *)UFG::SimObject::GetComponentOfType(v10, UFG::FaceActionComponent::_TypeUID);
      }
    }
  }
  if ( v5->mHelpbarLocked )
    goto LABEL_155;
  v11 = v5->mActionComponent;
  if ( v11 )
  {
    v12 = v11->mState;
    if ( v12 != 8
      && v12
      && (v12 != 4 || *((_BYTE *)v11 + 204) & 8 && (*((_BYTE *)v11 + 812) & 1 || v11->mMinigameSetup)) )
    {
      v5->mHelpbarLocked = 1;
      ++UFG::UIHKGameplayHelpWidget::mLocked;
    }
  }
  if ( v5->mHelpbarLocked )
  {
LABEL_155:
    v13 = v5->mActionComponent;
    if ( !v13
      || (v14 = v13->mState, v14 == 8)
      || v14 == eFACE_ACTION_STATE_WAITING_FOR_GREET
      || v14 == 4 && (!(*((_BYTE *)v13 + 204) & 8) || !(*((_BYTE *)v13 + 812) & 1) && !v13->mMinigameSetup) )
    {
      v5->mHelpbarLocked = 0;
      v15 = UFG::UIHKGameplayHelpWidget::mLocked;
      if ( UFG::UIHKGameplayHelpWidget::mLocked > 0 )
        v15 = UFG::UIHKGameplayHelpWidget::mLocked-- - 1;
      if ( v15 < 1 )
        UFG::UIHKScreenHud::GameplayHelp->mChanged = 1;
    }
  }
  v16 = 0;
  if ( v6 )
  {
    v17 = v5->mActionComponentTimer - elapsed;
    v5->mActionComponentTimer = v17;
    if ( v6 != v5->mActionComponent || v17 <= 0.0 )
    {
      UFG::UIHKSocialActionWidget::SetActionComponent(v5, v6, 1.0);
      v5->mActionComponentTimer = UFG::UIHKSocialActionWidget::gActionComponentTimerPeriod;
    }
    if ( UFG::FaceActionComponent::IsFaceActionEnabled(v5->mActionComponent) )
    {
      v18 = v5->mActionComponent;
      if ( *((_BYTE *)v18 + 812) & 1 || v18->mMinigameSetup )
        v16 = v5->mActionComponent->mState == 0;
      else
        v16 = v5->mActionComponent->mState == 4;
    }
    else
    {
      v16 = 0;
    }
  }
  else
  {
    if ( v5->mActionComponent )
      v5->mActionComponent = 0i64;
    v5->mChargeHappened = 0;
  }
  v5->mActionChanged |= v5->mActionDistance != v16;
  v5->mActionDistance = v16;
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
        UFG::qString::Set(&v5->mItemIcon, "sociable");
      }
    }
    v5->mActionEnabled = 1;
  }
  else
  {
    v5->mActionEnabled = 0;
  }
LABEL_50:
  if ( v5->mPlayingActionResult )
  {
    v21 = elapsed + v5->mPlayTime;
    v5->mPlayTime = v21;
    if ( v21 <= 0.5 )
      return;
    v5->mPlayingActionResult = 0;
    v5->mPlayTime = 0.0;
  }
  v22 = UFG::GameStatTracker::Instance();
  v5->mPlayerPipLevel = UFG::GameStatTracker::GetFaceLevel(v22);
  if ( v4 )
  {
    v23 = v4->mRenderable->m_movie.pObject;
    if ( v23 )
    {
      v5->mClosestTargetDistance = 9999.0;
      value.pObjectInterface = 0i64;
      value.Type = 0;
      if ( v5->mPlayingActionResult )
      {
LABEL_151:
        if ( ((unsigned int)value.Type >> 6) & 1 )
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
            value.pObjectInterface,
            &value,
            *(_QWORD *)&value.mValue.NValue);
        return;
      }
      v24 = v5->mActionComponent;
      if ( v24 && v5->mChargeHappened && v24->mState != 4 )
        v5->mChargeHappened = 0;
      if ( !v5->mRenderingTargetGame || !v5->mPlayingTargetGame )
        goto LABEL_95;
      v25 = (signed int)UFG::gActiveControllerNum;
      v26 = UFG::ActionDef_UIBackRepeat.mDataPerController[UFG::gActiveControllerNum];
      if ( v26 && v26->mActionTrue )
      {
        v5->mChargeGameTimer = elapsed + v5->mChargeGameTimer;
        v27 = FLOAT_2_0;
        switch ( v5->mPlayerPipLevel )
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
        v28 = (__m128)LODWORD(v5->mChargeGameTimer);
        v28.m128_f32[0] = (float)(v28.m128_f32[0] / v27) * 100.0;
        v29 = (signed int)v28.m128_f32[0];
        if ( (signed int)v28.m128_f32[0] != 0x80000000 && (float)v29 != v28.m128_f32[0] )
          v28.m128_f32[0] = (float)(v29 - (_mm_movemask_ps(_mm_unpacklo_ps(v28, v28)) & 1));
        LODWORD(v5->mChargeStatus) = v28.m128_i32[0];
        if ( (v54.mMagic >> 6) & 1 )
        {
          ((void (__fastcall *)(UFG::qNode<UFG::qString,UFG::qString> *, char *, unsigned __int64))v54.mNext->mPrev[1].mPrev)(
            v54.mNext,
            &ptr,
            value.DataAux);
          v54.mNext = 0i64;
        }
        v54.mMagic = 5;
        *(double *)&value.DataAux = v28.m128_f32[0];
        Scaleform::GFx::Movie::Invoke(v23, "ChargeGame_SetCharge", 0i64, (Scaleform::GFx::Value *)&ptr, 1u);
        `eh vector destructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
      }
      v30 = UFG::ActionDef_UIBackReleased.mDataPerController[v25];
      if ( !v30 || !v30->mActionTrue )
      {
LABEL_95:
        v34 = v5->mChargeState;
        if ( v34 )
        {
          if ( v34 == 1 )
          {
            v35 = UFG::Metrics::msInstance.mSimTime_Temp;
            v5->mElapsedTime = (float)(UFG::Metrics::msInstance.mSimTime_Temp - v5->mLastUpdateTime) + v5->mElapsedTime;
            v5->mLastUpdateTime = v35;
            if ( v5->mDuration > 0.0 )
              UFG::UIHKSocialActionWidget::Flash_ShowChargeMeter(v5, v4);
            if ( v5->mDuration <= v5->mElapsedTime )
            {
              UFG::UIHKSocialActionWidget::PlaySuccessfulInteraction(v5);
              v5->mChargeState = 3;
            }
          }
        }
        else if ( v5->mChargeVisible )
        {
          UFG::UIHKSocialActionWidget::Flash_HideChargeMeter(v5, v4);
        }
        if ( !v5->mVisible || !v5->mActionChanged )
          goto LABEL_118;
        v5->mActionChanged = 0;
        if ( v5->mItemIcon.mLength && (v36 = v5->mActionDistance) != 0 )
        {
          v37 = v36 - 1;
          if ( !v37 )
          {
LABEL_111:
            if ( v5->mDuration >= v5->mElapsedTime && (unsigned int)(v5->mChargeState - 3) > 1 )
              UFG::UIHKSocialActionWidget::Flash_ShowActionIcon(v5, v4);
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
              UFG::UIHKSocialActionWidget::Flash_HideActionIcon(v5, v4);
              UFG::UIHKSocialActionWidget::Flash_ShowHelpBar(v5, v4);
            }
            else
            {
              UFG::UIHKSocialActionWidget::Flash_ShowFarIcon(v5, v4);
            }
          }
          else
          {
            UFG::UIHKSocialActionWidget::Flash_ShowCloseIcon(v5, v4);
          }
        }
        else
        {
          UFG::UIHKSocialActionWidget::Flash_HideActionIcon(v5, v4);
        }
LABEL_118:
        if ( v5->mChanged )
        {
          v5->mChanged = 0;
          if ( v5->mVisible )
          {
            v40 = (float)(v5->mScale * 100.0);
            if ( ((unsigned int)value.Type >> 6) & 1 )
            {
              (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
                value.pObjectInterface,
                &value,
                *(_QWORD *)&value.mValue.NValue);
              value.pObjectInterface = 0i64;
            }
            value.Type = 5;
            value.mValue.NValue = v40;
            UFG::qString::qString((UFG::qString *)&ptr, "mc_FaceAction%d._xscale", (unsigned int)v5->mID);
            UFG::qString::qString(&v54, "mc_FaceAction%d._yscale", (unsigned int)v5->mID);
            Scaleform::GFx::Movie::SetVariable(v23, *(const char **)&v54.mMagic, &value, 1i64);
            Scaleform::GFx::Movie::SetVariable(v23, v54.mData, &value, 1i64);
            v41 = (float)(v5->mAlpha * 100.0);
            if ( ((unsigned int)value.Type >> 6) & 1 )
            {
              (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
                value.pObjectInterface,
                &value,
                *(_QWORD *)&value.mValue.NValue);
              value.pObjectInterface = 0i64;
            }
            value.Type = 5;
            value.mValue.NValue = v41;
            UFG::qString::qString(&v56, "mc_FaceAction%d._alpha", (unsigned int)v5->mID);
            Scaleform::GFx::Movie::SetVariable(v23, v56.mData, &value, 1i64);
            UFG::qString::~qString(&v56);
            UFG::qString::~qString(&v54);
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
        if ( v5->mVisible && v5->mScreenPosChanged )
        {
          v43 = v5->mScreenPos.x;
          if ( ((unsigned int)value.Type >> 6) & 1 )
          {
            (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
              value.pObjectInterface,
              &value,
              *(_QWORD *)&value.mValue.NValue);
            value.pObjectInterface = 0i64;
          }
          value.Type = 5;
          value.mValue.NValue = v43;
          UFG::qString::qString(&v54, "mc_FaceAction%d._x", (unsigned int)v5->mID);
          Scaleform::GFx::Movie::SetVariable(v23, v54.mData, &value, 1i64);
          v44 = v5->mScreenPos.y;
          if ( ((unsigned int)value.Type >> 6) & 1 )
          {
            (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
              value.pObjectInterface,
              &value,
              *(_QWORD *)&value.mValue.NValue);
            value.pObjectInterface = 0i64;
          }
          value.Type = 5;
          value.mValue.NValue = v44;
          UFG::qString::qString((UFG::qString *)&ptr, "mc_FaceAction%d._y", (unsigned int)v5->mID);
          Scaleform::GFx::Movie::SetVariable(v23, *(const char **)&v54.mMagic, &value, 1i64);
          UFG::qString::~qString((UFG::qString *)&ptr);
          UFG::qString::~qString(&v54);
        }
        if ( !UFG::UIHKTweakables::SocialActionFloatingTweak )
        {
          v45 = v5->mInitScreenX;
          v46 = 1;
          if ( v45 == v5->mScreenPos.x )
            v46 = 0;
          v5->mScreenPosChanged |= v46;
          v5->mScreenPos.x = v45;
          v47 = v5->mInitScreenY;
          v48 = 1;
          if ( v47 == v5->mScreenPos.y )
            v48 = 0;
          v5->mScreenPosChanged |= v48;
          v5->mScreenPos.y = v47;
          v5->mChanged |= v5->mVisible == 0;
          v49 = 1;
          if ( 1.0 == v5->mScale )
            v49 = 0;
          v5->mChanged |= v49;
          v5->mScale = 1.0;
          v5->mAlpha = 1.0;
        }
        if ( v5->mRenderingTargetGame && v5->mScreenPosChanged )
        {
          v50 = v5->mScreenPos.x;
          if ( ((unsigned int)value.Type >> 6) & 1 )
          {
            (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
              value.pObjectInterface,
              &value,
              *(_QWORD *)&value.mValue.NValue);
            value.pObjectInterface = 0i64;
          }
          value.Type = 5;
          value.mValue.NValue = v50;
          Scaleform::GFx::Movie::SetVariable(v23, "mcChargeGame._x", &value, 1i64);
          v51 = v5->mScreenPos.y;
          if ( ((unsigned int)value.Type >> 6) & 1 )
          {
            (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
              value.pObjectInterface,
              &value,
              *(_QWORD *)&value.mValue.NValue);
            value.pObjectInterface = 0i64;
          }
          value.Type = 5;
          value.mValue.NValue = v51;
          Scaleform::GFx::Movie::SetVariable(v23, "mcChargeGame._y", &value, 1i64);
        }
        v5->mScreenPosChanged = 0;
        if ( UFG::UIHKSocialActionWidget::mTextureLoaded )
        {
          UFG::UIHKSocialActionWidget::mTextureLoaded = 0;
          UFG::UIHKSocialActionWidget::HandleTextureLoaded(v5, v4);
        }
        goto LABEL_151;
      }
      `eh vector constructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      v31 = v5->mChargeStatus;
      if ( v31 < 74.0 || v31 > 88.0 )
      {
        if ( (v54.mMagic >> 6) & 1 )
        {
          ((void (__fastcall *)(UFG::qNode<UFG::qString,UFG::qString> *, char *, unsigned __int64))v54.mNext->mPrev[1].mPrev)(
            v54.mNext,
            &ptr,
            value.DataAux);
          v54.mNext = 0i64;
        }
        LOBYTE(value.DataAux) = 0;
        v5->mGameResult = 4;
      }
      else
      {
        if ( (v54.mMagic >> 6) & 1 )
        {
          ((void (__fastcall *)(UFG::qNode<UFG::qString,UFG::qString> *, char *, unsigned __int64))v54.mNext->mPrev[1].mPrev)(
            v54.mNext,
            &ptr,
            value.DataAux);
          v54.mNext = 0i64;
        }
        LOBYTE(value.DataAux) = 1;
        v5->mGameResult = 3;
      }
      v54.mMagic = 2;
      v5->mActionComponent->mMiniGameResult = v5->mGameResult;
      v5->mChargeHappened = 1;
      Scaleform::GFx::Movie::Invoke(v23, "ChargeGame_SetSuccessValue", 0i64, (Scaleform::GFx::Value *)&ptr, 1u);
      v5->mChargeState = 4;
      v5->mIsMidMiniGame = 0;
      UFG::UI::UnlockGameplayInput(v32);
      if ( v5->mActionComponent->mMinigameTimeWarpFactor >= 1.0 )
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
        UFG::AudioEntity::CreateAndPlayEvent(
          (UFG::AudioEntity *)&UFG::AmbienceAudio::m_instance->vfptr,
          qwsStopTimeDilate_0.mUID,
          0i64,
          0,
          0i64);
      goto LABEL_94;
    }
  }
}

// File Line: 1130
// RVA: 0x5E42E0
void __fastcall UFG::UIHKSocialActionWidget::Flash_ShowChargeMeter(UFG::UIHKSocialActionWidget *this, UFG::UIScreen *screen)
{
  UFG::UIHKSocialActionWidget *v2; // rbx
  Scaleform::GFx::Movie *v3; // rdi
  float v4; // xmm6_4
  float v5; // xmm6_4
  long double v6; // xmm1_8
  Scaleform::GFx::Value value; // [rsp+38h] [rbp-80h]
  char ptr; // [rsp+68h] [rbp-50h]
  __int64 v9; // [rsp+78h] [rbp-40h]
  unsigned int v10; // [rsp+80h] [rbp-38h]
  double v11; // [rsp+88h] [rbp-30h]

  v2 = this;
  if ( !this->mPlayingActionResult )
  {
    if ( screen )
    {
      v3 = screen->mRenderable->m_movie.pObject;
      if ( v3 )
      {
        v4 = this->mElapsedTime / (float)(this->mDuration + 0.0000099999997);
        if ( v4 >= 1.0 )
          v4 = *(float *)&FLOAT_1_0;
        v5 = v4 * 100.0;
        this->mChargeVisible = 1;
        `eh vector constructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
        if ( (v10 >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v9 + 16i64))(
            v9,
            &ptr,
            COERCE_DOUBLE(*(_QWORD *)&v11));
          v9 = 0i64;
        }
        v10 = 5;
        v11 = v5;
        v6 = (double)v2->mID;
        value.pObjectInterface = 0i64;
        value.Type = 5;
        value.mValue.NValue = v6;
        Scaleform::GFx::Movie::SetVariable(v3, "mMovieIndex", &value, 1i64);
        if ( ((unsigned int)value.Type >> 6) & 1 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
            value.pObjectInterface,
            &value,
            *(_QWORD *)&value.mValue.NValue);
          value.pObjectInterface = 0i64;
        }
        value.Type = 0;
        Scaleform::GFx::Movie::Invoke(v3, "FaceAction_showFaceCharge", 0i64, (Scaleform::GFx::Value *)&ptr, 1u);
        `eh vector destructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
      }
    }
  }
}

// File Line: 1155
// RVA: 0x5DBC20
void __fastcall UFG::UIHKSocialActionWidget::Flash_HideChargeMeter(UFG::UIHKSocialActionWidget *this, UFG::UIScreen *screen)
{
  UFG::UIHKSocialActionWidget *v2; // rdi
  Scaleform::GFx::Movie *v3; // rbx
  double v4; // xmm0_8
  char v5; // [rsp+38h] [rbp-40h]
  __int64 v6; // [rsp+48h] [rbp-30h]
  unsigned int v7; // [rsp+50h] [rbp-28h]
  double v8; // [rsp+58h] [rbp-20h]

  if ( screen )
  {
    v2 = this;
    v3 = screen->mRenderable->m_movie.pObject;
    if ( v3 )
    {
      this->mChargeVisible = 0;
      v4 = (double)this->mID;
      v6 = 0i64;
      v7 = 5;
      v8 = v4;
      Scaleform::GFx::Movie::SetVariable(v3, "mMovieIndex", (Scaleform::GFx::Value *)&v5, 1i64);
      if ( (v7 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v6 + 16i64))(
          v6,
          &v5,
          COERCE_DOUBLE(*(_QWORD *)&v8));
        v6 = 0i64;
      }
      v7 = 0;
      Scaleform::GFx::Movie::Invoke(v3, "FaceAction_hideFaceCharge", 0i64, 0i64, 0);
      v2->mPlayingActionResult = 0;
    }
  }
}

// File Line: 1173
// RVA: 0x5E49F0
void __fastcall UFG::UIHKSocialActionWidget::Flash_ShowHelpBar(UFG::UIHKSocialActionWidget *this, UFG::UIScreen *screen)
{
  char *v2; // rbx
  UFG::UIHKSocialActionWidget *v3; // rdi
  const char *caption0; // rax
  __int64 v5; // rdx
  UFG::UIGfxTranslator *v6; // rcx
  UFG::FaceActionComponent *v7; // rcx
  UFG::UIHKScreenHud *v8; // rax
  UFG::eInventoryItemEnum v9; // ecx

  v2 = this->mItemCaption.mData;
  v3 = this;
  if ( v2 )
  {
    if ( *v2 == 36 )
      ++v2;
    v5 = (unsigned int)UFG::qStringHashUpper32(v2, 0xFFFFFFFF);
    v6 = UFG::UIScreenManager::s_instance->m_translator;
    if ( !v6
      || (caption0 = (const char *)v6->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v6->vfptr, v5)) == 0i64 )
    {
      caption0 = v2;
    }
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
    0,
    &customWorldMapCaption);
  v7 = v3->mActionComponent;
  if ( v3->mConversationFaceType == 6 )
  {
    if ( v7 )
    {
      if ( v3->mItemPrice )
      {
        v8 = UFG::UIHKScreenHud::mInstance;
        if ( UFG::UIHKScreenHud::mInstance )
        {
          v9 = v7->mInventoryItem;
          if ( v9 )
          {
            if ( v9 != 137 )
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
void __fastcall UFG::UIHKSocialActionWidget::Flash_ShowActionIcon(UFG::UIHKSocialActionWidget *this, UFG::UIScreen *screen)
{
  UFG::UIHKSocialActionWidget *v2; // rdi
  unsigned int v3; // ebx
  const char *v4; // rax
  const char *v5; // rsi
  int v6; // ecx
  __int64 v7; // rax
  __int64 v8; // rbx
  int v9; // ecx
  __int64 v10; // rax
  __int64 v11; // rbx
  UFG::FaceActionComponent *v12; // rcx
  UFG::UIHKScreenHud *v13; // rax
  UFG::eInventoryItemEnum v14; // edx
  UFG::UIHKGameplayHelpData data; // [rsp+50h] [rbp-A8h]
  UFG::qSymbol type; // [rsp+150h] [rbp+58h]

  if ( !screen )
    return;
  v2 = this;
  if ( !screen->mRenderable->m_movie.pObject )
    return;
  v3 = qSymbol_Chat_20.mUID;
  if ( (unsigned int)UFG::qStringCompare(this->mItemIcon.mData, "porkbun", -1) )
  {
    if ( (unsigned int)UFG::qStringCompare(v2->mItemIcon.mData, "tea", -1) )
    {
      if ( (unsigned int)UFG::qStringCompare(v2->mItemIcon.mData, "massage", -1) )
      {
        if ( (unsigned int)UFG::qStringCompare(v2->mItemIcon.mData, "extort", -1) )
        {
          if ( (unsigned int)UFG::qStringCompare(v2->mItemIcon.mData, "bribe", -1) )
          {
            if ( (unsigned int)UFG::qStringCompare(v2->mItemIcon.mData, "purchase", -1) )
            {
              if ( (unsigned int)UFG::qStringCompare(v2->mItemIcon.mData, "realestate", -1) )
              {
                if ( (unsigned int)UFG::qStringCompare(v2->mItemIcon.mData, "clothing", -1) )
                {
                  if ( (unsigned int)UFG::qStringCompare(v2->mItemIcon.mData, "gun", -1) )
                  {
                    if ( (unsigned int)UFG::qStringCompare(v2->mItemIcon.mData, "drink", -1) )
                    {
                      if ( !(unsigned int)UFG::qStringCompare(v2->mItemIcon.mData, "informant", -1) )
                        v3 = qSymbol_Informant_20.mUID;
                    }
                    else
                    {
                      v3 = qSymbol_Drink_20.mUID;
                    }
                  }
                  else
                  {
                    v3 = qSymbol_Weapon_20.mUID;
                  }
                }
                else
                {
                  v3 = qSymbol_Clothing_20.mUID;
                }
              }
              else
              {
                v3 = qSymbol_Purchase_20.mUID;
              }
            }
            else
            {
              v3 = qSymbol_Purchase_20.mUID;
            }
          }
          else
          {
            v3 = qSymbol_Bribe_20.mUID;
          }
        }
        else
        {
          v3 = qSymbol_Extortion_20.mUID;
        }
      }
      else
      {
        v3 = qSymbol_Massage_20.mUID;
      }
    }
    else
    {
      v3 = qSymbol_Tea_20.mUID;
    }
  }
  else
  {
    v3 = qSymbol_Food_20.mUID;
  }
  type.mUID = v3;
  if ( !v2->mItemDescription.mLength || !UFG::UIHKScreenHud::InfoPopup )
  {
    v4 = UFG::UI::LocalizeText(v2->mItemCaption.mData);
    v5 = v4;
    if ( v3 == qSymbol_Informant_20.mUID || v3 == qSymbol_Chat_20.mUID )
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
      data.Buttons[v9] = 4;
      v11 = v9;
      UFG::qString::Set(&data.Captions[v11], v5);
      UFG::qString::Set((UFG::qString *)((char *)&data.Captions[v11 + 1] + 32), &customWorldMapCaption);
LABEL_44:
      UFG::qString::Set((UFG::qString *)((char *)&data.Captions[1] + 32), "Icon_Interact");
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
      if ( v3 != qSymbol_Purchase_20.mUID && v3 != qSymbol_Clothing_20.mUID )
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
      data.Buttons[v6] = 4;
      v8 = v6;
      UFG::qString::Set(&data.Captions[v8], v5);
      UFG::qString::Set((UFG::qString *)((char *)&data.Captions[v8 + 1] + 32), &customWorldMapCaption);
LABEL_38:
      UFG::qString::Set((UFG::qString *)((char *)&data.Captions[1] + 32), "Icon_Purchase");
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
    v2->mItemName.mData,
    v2->mItemDescription.mData,
    v2->mItemPrice,
    &type);
  v4 = UFG::UI::LocalizeText(v2->mItemCaption.mData);
LABEL_28:
  UFG::UIHKGameplayHelpWidget::Show(
    UFG::UIHKScreenHud::GameplayHelp,
    UI_HASH_HELPBAR_SOCIAL_20,
    2u,
    BUTTON2_BUTTON,
    v4,
    0,
    &customWorldMapCaption);
LABEL_46:
  v12 = v2->mActionComponent;
  if ( v2->mConversationFaceType == 6 )
  {
    if ( v12 )
    {
      if ( v2->mItemPrice )
      {
        v13 = UFG::UIHKScreenHud::mInstance;
        if ( UFG::UIHKScreenHud::mInstance )
        {
          v14 = v12->mInventoryItem;
          if ( v14 )
          {
            if ( v14 != 137 )
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
void __fastcall UFG::UIHKSocialActionWidget::Flash_ShowCloseIcon(UFG::UIHKSocialActionWidget *this, UFG::UIScreen *screen)
{
  UFG::UIHKSocialActionWidget *v2; // rbx
  Scaleform::GFx::Movie *v3; // rdi
  __int64 v4; // rsi
  __int64 v5; // rsi
  double v6; // xmm6_8
  long double v7; // xmm0_8
  Scaleform::GFx::Value value; // [rsp+30h] [rbp-B8h]
  char ptr; // [rsp+60h] [rbp-88h]
  __int64 v10; // [rsp+68h] [rbp-80h]
  __int64 v11; // [rsp+70h] [rbp-78h]
  unsigned int v12; // [rsp+78h] [rbp-70h]
  __int64 v13; // [rsp+88h] [rbp-60h]
  unsigned int v14; // [rsp+90h] [rbp-58h]
  __int64 v15; // [rsp+98h] [rbp-50h]
  char v16; // [rsp+A8h] [rbp-40h]
  __int64 v17; // [rsp+B8h] [rbp-30h]
  unsigned int v18; // [rsp+C0h] [rbp-28h]
  double v19; // [rsp+C8h] [rbp-20h]
  __int64 v20; // [rsp+D8h] [rbp-10h]

  if ( screen )
  {
    v20 = -2i64;
    v2 = this;
    v3 = screen->mRenderable->m_movie.pObject;
    if ( v3 )
    {
      if ( this->mActionEnabled )
        UFG::UIHKSocialActionWidget::SetPipAction(this);
      `eh vector constructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      v4 = (__int64)v2->mItemIcon.mData;
      if ( (v12 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v11 + 16i64))(v11, &ptr, v10);
        v11 = 0i64;
      }
      v12 = 6;
      v10 = v4;
      v5 = (__int64)v2->mPipActionStr.mData;
      if ( (v14 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, unsigned int *, __int64))(*(_QWORD *)v13 + 16i64))(v13, &v12, v15);
        v13 = 0i64;
      }
      v14 = 6;
      v15 = v5;
      v6 = (double)(signed int)v2->mPipLevel;
      if ( (v18 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v17 + 16i64))(
          v17,
          &v16,
          COERCE_DOUBLE(*(_QWORD *)&v19));
        v17 = 0i64;
      }
      v18 = 5;
      v19 = v6;
      v7 = (double)v2->mID;
      value.pObjectInterface = 0i64;
      value.Type = 5;
      value.mValue.NValue = v7;
      Scaleform::GFx::Movie::SetVariable(v3, "mMovieIndex", &value, 1i64);
      if ( ((unsigned int)value.Type >> 6) & 1 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
          value.pObjectInterface,
          &value,
          *(_QWORD *)&value.mValue.NValue);
        value.pObjectInterface = 0i64;
      }
      value.Type = 0;
      Scaleform::GFx::Movie::Invoke(v3, "FaceAction_showCloseIcon", 0i64, (Scaleform::GFx::Value *)&ptr, 3u);
      `eh vector destructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    }
  }
}

// File Line: 1358
// RVA: 0x606DF0
void __usercall UFG::UIHKSocialActionWidget::SetPipAction(UFG::UIHKSocialActionWidget *this@<rcx>, __int64 a2@<rbx>)
{
  UFG::UIHKSocialActionWidget *v2; // rbx
  unsigned int v3; // er8
  const char *v4; // rdx
  const char *v5; // rdx
  UFG::qString v6; // [rsp+38h] [rbp-30h]
  __int64 v7; // [rsp+60h] [rbp-8h]

  v7 = a2;
  v2 = this;
  UFG::qString::qString(&v6, &customWorldMapCaption);
  if ( v2->mMinPipsRequired <= v2->mPlayerPipLevel )
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
  switch ( v2->mMinPipsRequired )
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
  UFG::qString::append(&v6, v5, 1u);
  UFG::qString::Set(&v2->mPipActionStr, v6.mData, v6.mLength, 0i64, 0);
  UFG::qString::~qString(&v6);
}

// File Line: 1435
// RVA: 0x5E47D0
void __fastcall UFG::UIHKSocialActionWidget::Flash_ShowFarIcon(UFG::UIHKSocialActionWidget *this, UFG::UIScreen *screen)
{
  UFG::UIHKSocialActionWidget *v2; // rbx
  Scaleform::GFx::Movie *v3; // rdi
  __int64 v4; // rsi
  __int64 v5; // rsi
  double v6; // xmm6_8
  long double v7; // xmm0_8
  Scaleform::GFx::Value value; // [rsp+30h] [rbp-B8h]
  char ptr; // [rsp+60h] [rbp-88h]
  __int64 v10; // [rsp+68h] [rbp-80h]
  __int64 v11; // [rsp+70h] [rbp-78h]
  unsigned int v12; // [rsp+78h] [rbp-70h]
  __int64 v13; // [rsp+88h] [rbp-60h]
  unsigned int v14; // [rsp+90h] [rbp-58h]
  __int64 v15; // [rsp+98h] [rbp-50h]
  char v16; // [rsp+A8h] [rbp-40h]
  __int64 v17; // [rsp+B8h] [rbp-30h]
  unsigned int v18; // [rsp+C0h] [rbp-28h]
  double v19; // [rsp+C8h] [rbp-20h]
  __int64 v20; // [rsp+D8h] [rbp-10h]

  if ( screen )
  {
    v20 = -2i64;
    v2 = this;
    v3 = screen->mRenderable->m_movie.pObject;
    if ( v3 )
    {
      if ( this->mActionEnabled )
        UFG::UIHKSocialActionWidget::SetPipAction(this);
      `eh vector constructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      v4 = (__int64)v2->mItemIcon.mData;
      if ( (v12 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v11 + 16i64))(v11, &ptr, v10);
        v11 = 0i64;
      }
      v12 = 6;
      v10 = v4;
      v5 = (__int64)v2->mPipActionStr.mData;
      if ( (v14 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, unsigned int *, __int64))(*(_QWORD *)v13 + 16i64))(v13, &v12, v15);
        v13 = 0i64;
      }
      v14 = 6;
      v15 = v5;
      v6 = (double)(signed int)v2->mPipLevel;
      if ( (v18 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v17 + 16i64))(
          v17,
          &v16,
          COERCE_DOUBLE(*(_QWORD *)&v19));
        v17 = 0i64;
      }
      v18 = 5;
      v19 = v6;
      v7 = (double)v2->mID;
      value.pObjectInterface = 0i64;
      value.Type = 5;
      value.mValue.NValue = v7;
      Scaleform::GFx::Movie::SetVariable(v3, "mMovieIndex", &value, 1i64);
      if ( ((unsigned int)value.Type >> 6) & 1 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
          value.pObjectInterface,
          &value,
          *(_QWORD *)&value.mValue.NValue);
        value.pObjectInterface = 0i64;
      }
      value.Type = 0;
      Scaleform::GFx::Movie::Invoke(v3, "FaceAction_showFarIcon", 0i64, (Scaleform::GFx::Value *)&ptr, 3u);
      `eh vector destructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    }
  }
}

// File Line: 1460
// RVA: 0x5DBA80
void __fastcall UFG::UIHKSocialActionWidget::Flash_HideActionIcon(UFG::UIHKSocialActionWidget *this, UFG::UIScreen *screen)
{
  UFG::UIHKSocialActionWidget *v2; // rbx
  Scaleform::GFx::Movie *v3; // rdi
  UFG::UIHKScreenHud *v4; // rax
  UFG::UIHKInfoPopupWidget::eState v5; // ecx
  long double v6; // xmm0_8
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-38h]

  if ( screen )
  {
    v2 = this;
    v3 = screen->mRenderable->m_movie.pObject;
    if ( v3 )
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
        if ( v2->mItemDescription.mLength )
        {
          if ( UFG::UIHKScreenHud::InfoPopup )
          {
            v5 = UFG::UIHKScreenHud::InfoPopup->mState;
            if ( v5 )
            {
              if ( v5 != 5 )
                UFG::UIHKScreenHud::InfoPopup->mState = 4;
            }
          }
        }
        if ( v2->mPedChanged )
        {
          v2->mPedChanged = 0;
          value.pObjectInterface = 0i64;
          value.Type = 2;
          value.mValue.BValue = 0;
          Scaleform::GFx::Movie::SetVariable(v3, "mc_FaceAction0._visible", &value, 1i64);
          if ( ((unsigned int)value.Type >> 6) & 1 )
          {
            (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
              value.pObjectInterface,
              &value,
              *(_QWORD *)&value.mValue.NValue);
            value.pObjectInterface = 0i64;
          }
          value.Type = 0;
        }
      }
      v6 = (double)v2->mID;
      value.pObjectInterface = 0i64;
      value.Type = 5;
      value.mValue.NValue = v6;
      Scaleform::GFx::Movie::SetVariable(v3, "mMovieIndex", &value, 1i64);
      if ( ((unsigned int)value.Type >> 6) & 1 )
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
          value.pObjectInterface,
          &value,
          *(_QWORD *)&value.mValue.NValue);
    }
  }
}

// File Line: 1533
// RVA: 0x5EC340
void __fastcall UFG::UIHKSocialActionWidget::HandleTextureLoaded(UFG::UIHKSocialActionWidget *this, UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *v2; // rcx

  if ( screen )
  {
    v2 = screen->mRenderable->m_movie.pObject;
    if ( v2 )
      Scaleform::GFx::Movie::Invoke(v2, "handleTextureLoaded", 0i64, 0i64, 0);
  }
}

