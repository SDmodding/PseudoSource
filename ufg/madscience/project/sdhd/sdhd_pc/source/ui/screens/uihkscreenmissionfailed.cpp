// File Line: 30
// RVA: 0x1570910
__int64 UFG::_dynamic_initializer_for__start_mission_fail__()
{
  start_mission_fail_0.mUID = UFG::qWiseSymbolUIDFromString("start_mission_fail", 0x811C9DC5);
  _((AMD_HD3D *)start_mission_fail_0.mUID);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__start_mission_fail__);
}

// File Line: 31
// RVA: 0x1570990
__int64 UFG::_dynamic_initializer_for__stop_mission_fail__()
{
  stop_mission_fail_0.mUID = UFG::qWiseSymbolUIDFromString("stop_mission_fail", 0x811C9DC5);
  _((AMD_HD3D *)stop_mission_fail_0.mUID);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__stop_mission_fail__);
}

// File Line: 32
// RVA: 0x15724A0
__int64 UFG::_dynamic_initializer_for__ui_mission_fail__()
{
  ui_mission_fail.mUID = UFG::qWiseSymbolUIDFromString("ui_mission_fail", 0x811C9DC5);
  _((AMD_HD3D *)ui_mission_fail.mUID);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__ui_mission_fail__);
}

// File Line: 37
// RVA: 0x1566F50
__int64 dynamic_initializer_for__UFG::UIHKScreenMissionFailed::mData__()
{
  UFG::UIHKScreenMissionFailed::mData.vfptr = (UFG::UICommandDataVtbl *)&UFG::UIHKMissionFailedData::`vftable;
  dword_14208EB48 = 0;
  UFG::qString::qString(&stru_14208EB50);
  UFG::qString::qString(&stru_14208EB78);
  UFG::qString::qString(&stru_14208EBA0);
  byte_14208EBC8 = 1;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::UIHKScreenMissionFailed::mData__);
}

// File Line: 54
// RVA: 0x5C6220
void __fastcall UFG::UIHKScreenMissionFailed::UIHKScreenMissionFailed(UFG::UIHKScreenMissionFailed *this)
{
  this->mPrev = &this->UFG::qNode<UFG::UIScreen,UFG::UIScreen>;
  this->mNext = &this->UFG::qNode<UFG::UIScreen,UFG::UIScreen>;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIScreen::`vftable;
  this->m_screenNameHash = 0;
  this->mRenderable = 0i64;
  this->mLoadThread = 0i64;
  this->mScreenUID = -1;
  *(_QWORD *)&this->mControllerMask = 15i64;
  *(_QWORD *)&this->mPriority = 0i64;
  this->mDimToApplyType = eDIM_INVALID;
  *(_QWORD *)&this->mCurDimValue = 1120403456i64;
  this->m_screenName[0] = 0;
  --this->mInputEnabled;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenMissionFailed::`vftable;
  *(_QWORD *)&this->mState = 0i64;
  this->mSelectedOption = 1;
  this->mCanCancelMission = 0;
  UFG::UIHKDepthOfFieldWidget::UIHKDepthOfFieldWidget(&this->DoF);
}

// File Line: 60
// RVA: 0x5CB950
void __fastcall UFG::UIHKScreenMissionFailed::~UIHKScreenMissionFailed(UFG::UIHKScreenMissionFailed *this)
{
  UFG::UIScreenTextureManager *v2; // rax
  int v3; // eax
  UFG::UIHKScreenGlobalOverlay *v4; // rax

  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenMissionFailed::`vftable;
  UFG::SoundBankManager::QueueBankForUnload(&ui_mission_fail);
  v2 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v2, "Dialog_MissionFailed");
  v3 = UFG::UIHKHelpBarWidget::mLocked;
  if ( UFG::UIHKHelpBarWidget::mLocked > 0 )
    v3 = --UFG::UIHKHelpBarWidget::mLocked;
  if ( v3 < 1 )
  {
    v4 = UFG::UIHKScreenGlobalOverlay::mThis;
    if ( !UFG::UIHKScreenGlobalOverlay::mThis )
      v4 = &gGlobalOverlaySentinel;
    v4->HelpBar.mChanged = 1;
  }
  UFG::UIHKScreenMissionFailed::gIsRace = 0;
  UFG::GameCameraComponent::EndDOFOverride(DOFOverridePriority_0);
  UFG::UIScreen::~UIScreen(this);
}

// File Line: 70
// RVA: 0x632E40
void __fastcall UFG::UIHKScreenMissionFailed::init(UFG::UIHKScreenMissionFailed *this, UFG::UICommandData *data)
{
  UFG::UIScreen::init(this, data);
  this->mState = STATE_BRIGHTNESS;
}

// File Line: 81
// RVA: 0x63E220
void __fastcall UFG::UIHKScreenMissionFailed::update(UFG::UIHKScreenMissionFailed *this, float elapsed)
{
  Scaleform::GFx::Movie *pObject; // rcx
  UFG::UIHKActionButtonWidget *v4; // rcx
  bool v5; // zf

  if ( this->mState == STATE_BRIGHTNESS && UFG::SoundBankManager::BankLoadRequestFinished(&ui_mission_fail) )
  {
    UFG::AudioEntity::CreateAndPlayEvent(UFG::AmbienceAudio::m_instance, start_mission_fail_0.mUID, 0i64, 0, 0i64);
    UFG::UIHKScreenMissionFailed::Flash_SetButtonHighlight(this, 1, 0);
    UFG::UIHKScreenMissionFailed::Flash_SetButtonHighlight(this, 2, 1);
    UFG::UIHKScreenMissionFailed::Flash_SetTitleText(this, stru_14208EB50.mData);
    UFG::UIHKScreenMissionFailed::Flash_SetBodyText(this, stru_14208EB78.mData);
    UFG::UIHKScreenMissionFailed::Flash_SetHintText(this, stru_14208EBA0.mData);
    if ( byte_14208EBC8 )
    {
      UFG::UIHKScreenMissionFailed::Flash_SetNumButtons(this, 2);
      this->mCanCancelMission = 1;
    }
    else
    {
      UFG::UIHKScreenMissionFailed::Flash_SetNumButtons(this, 1);
    }
    if ( UFG::UIHKScreenMissionFailed::gIsRace )
    {
      pObject = this->mRenderable->m_movie.pObject;
      if ( pObject )
        Scaleform::GFx::Movie::Invoke(pObject, "MissionFailed_SetRaceOptions", 0i64, 0i64, 0);
    }
    UFG::UIHKScreenMissionFailed::Flash_PlayIntro(this, dword_14208EB48);
    this->mState = STATE_VOLUME;
    if ( UFG::UIHKScreenGlobalOverlay::mThis
      && UFG::UIHKScreenGlobalOverlay::mThis != (UFG::UIHKScreenGlobalOverlay *)-408i64 )
    {
      UFG::UIHK_NISOverlay::HideElement(
        &UFG::UIHKScreenGlobalOverlay::mThis->NISOverlay,
        UFG::UIHKScreenGlobalOverlay::mThis,
        &UFG::UIHK_NISOverlay::m_curtains,
        0.0,
        0);
    }
    UFG::UIHK_NISOverlay::UpdateAudioMuteState();
    ++UFG::UIHK_NISOverlay::mLock;
    ++UFG::UIHKHelpBarWidget::mLocked;
    UFG::UIHKGameplayHelpWidget::ClearAll(UFG::UIHKScreenHud::GameplayHelp);
    v4 = UFG::UIHKScreenHud::ActionButton;
    v5 = !UFG::UIHKScreenHud::ActionButton->mVisible;
    UFG::UIHKScreenHud::ActionButton->mVisible = 0;
    v4->mChanged |= !v5;
    UFG::UIHKScreenHud::ResetWidgets();
  }
  UFG::UIScreen::update(this, elapsed);
}

// File Line: 134
// RVA: 0x625A20
bool __fastcall UFG::UIHKScreenMissionFailed::handleMessage(
        UFG::UIHKScreenMissionFailed *this,
        unsigned int msgId,
        UFG::UIMessage *msg)
{
  __int32 v6; // ecx
  __int32 v7; // ecx
  UFG::UIHKScreenMissionFailed::eResult mResult; // eax
  unsigned int v9; // edx
  unsigned int v10; // ecx
  unsigned int v11; // esi
  unsigned int v12; // ecx
  unsigned int mUID; // esi
  UFG::HudAudio *v14; // rcx
  unsigned int v15; // edx

  v6 = this->mState - 2;
  if ( !v6 )
  {
    if ( msgId != UI_HASH_BUTTON_ACCEPT_PRESSED_30 && msgId != UI_HASH_MOUSE_BUTTON_LEFT_PRESSED_30 )
    {
      if ( msgId != UI_HASH_BUTTON_BACK_PRESSED_30 || !this->mCanCancelMission )
        return UFG::UIScreen::handleMessage(this, msgId, msg);
      if ( UFG::UIHKScreenMissionFailed::gIsRace )
      {
        this->mResult = RESULT_CANCEL_MISSION;
        UFG::UIHKScreenMissionFailed::Flash_PlayOutro(this, dword_14208EB48);
        this->mState = NUM_CALIBRATION_STATES;
      }
      else
      {
        UFG::UIHKScreenMissionFailed::Flash_ConfirmCancelMission(this);
        this->mState = STATE_UISCALE;
      }
      v14 = UFG::HudAudio::m_instance;
      if ( !UFG::HudAudio::m_instance )
        return UFG::UIScreen::handleMessage(this, msgId, msg);
      v15 = 0xCBB448ED;
LABEL_42:
      UFG::AudioEntity::CreateAndPlayEvent(v14, v15, 0i64, 0, 0i64);
      return UFG::UIScreen::handleMessage(this, msgId, msg);
    }
    this->mResult = RESULT_CONTINUE_MISSION;
    UFG::UIHKScreenMissionFailed::Flash_PlayOutro(this, dword_14208EB48);
    this->mState = NUM_CALIBRATION_STATES;
    if ( UFG::UIHK_NISOverlay::m_curtains.m_state == STATE_CURTAIN_HIDDEN )
    {
      if ( UFG::UIHKScreenGlobalOverlay::mThis
        && UFG::UIHKScreenGlobalOverlay::mThis != (UFG::UIHKScreenGlobalOverlay *)-408i64 )
      {
        UFG::UIHK_NISOverlay::ShowElement(
          &UFG::UIHKScreenGlobalOverlay::mThis->NISOverlay,
          UFG::UIHKScreenGlobalOverlay::mThis,
          &UFG::UIHK_NISOverlay::m_curtains,
          1.0,
          0);
        UFG::UIHK_NISOverlay::m_curtains.m_mutingAudio = 0;
      }
      UFG::UIHK_NISOverlay::UpdateAudioMuteState();
    }
LABEL_40:
    v14 = UFG::HudAudio::m_instance;
    if ( !UFG::HudAudio::m_instance )
      return UFG::UIScreen::handleMessage(this, msgId, msg);
    v15 = 558069486;
    goto LABEL_42;
  }
  v7 = v6 - 1;
  if ( !v7 )
  {
    if ( msgId == UI_HASH_BUTTON_ACCEPT_PRESSED_30 || msgId == UI_HASH_MOUSE_BUTTON_LEFT_PRESSED_30 )
    {
      this->mResult = RESULT_CANCEL_MISSION;
    }
    else
    {
      if ( !byte_14208EBC8 || msgId != UI_HASH_BUTTON_BACK_PRESSED_30 )
        return UFG::UIScreen::handleMessage(this, msgId, msg);
      this->mResult = RESULT_CONTINUE_MISSION;
    }
    UFG::UIHKScreenMissionFailed::Flash_PlayOutro(this, dword_14208EB48);
    this->mState = NUM_CALIBRATION_STATES;
    goto LABEL_40;
  }
  if ( v7 != 1 || msgId != UI_HASH_OUTRO_COMPLETE_30 )
    return UFG::UIScreen::handleMessage(this, msgId, msg);
  mResult = this->mResult;
  if ( mResult == RESULT_CONTINUE_MISSION )
  {
    v9 = UI_HASH_DIALOG_YES_30;
  }
  else
  {
    if ( mResult != RESULT_CANCEL_MISSION )
    {
      v12 = UFG::UIHK_NISOverlay::m_current_audio_event_index;
      mUID = stop_mission_fail_0.mUID;
      if ( UFG::UIHK_NISOverlay::m_current_audio_event_index == 7 )
      {
        UFG::UIHK_NISOverlay::FirePostNISAudioEventQueue();
        v12 = UFG::UIHK_NISOverlay::m_current_audio_event_index;
      }
      UFG::UIHK_NISOverlay::m_post_nis_hide_curtain_audio_events[v12] = mUID;
      UFG::UIHK_NISOverlay::m_current_audio_event_index = v12 + 1;
      UFG::UIScreenManagerBase::queueMessage(UFG::UIScreenManager::s_instance, UI_HASH_DIALOG_NO_30, 0xFFFFFFFF);
      goto LABEL_15;
    }
    v9 = UI_HASH_DIALOG_NO_30;
  }
  UFG::UIScreenManagerBase::queueMessage(UFG::UIScreenManager::s_instance, v9, 0xFFFFFFFF);
  v10 = UFG::UIHK_NISOverlay::m_current_audio_event_index;
  v11 = stop_mission_fail_0.mUID;
  if ( UFG::UIHK_NISOverlay::m_current_audio_event_index == 7 )
  {
    UFG::UIHK_NISOverlay::FirePostNISAudioEventQueue();
    v10 = UFG::UIHK_NISOverlay::m_current_audio_event_index;
  }
  UFG::UIHK_NISOverlay::m_post_nis_hide_curtain_audio_events[v10] = v11;
  UFG::UIHK_NISOverlay::m_current_audio_event_index = v10 + 1;
LABEL_15:
  --UFG::UIHK_NISOverlay::mLock;
  UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, 0xFFFFFFFF);
  if ( UFG::UIHKScreenGlobalOverlay::mThis
    && UFG::UIHKScreenGlobalOverlay::mThis != (UFG::UIHKScreenGlobalOverlay *)-408i64 )
  {
    UFG::UIHK_NISOverlay::ShowElement(
      &UFG::UIHKScreenGlobalOverlay::mThis->NISOverlay,
      UFG::UIHKScreenGlobalOverlay::mThis,
      &UFG::UIHK_NISOverlay::m_curtains,
      0.0,
      0);
    UFG::UIHK_NISOverlay::m_curtains.m_mutingAudio = 0;
  }
  UFG::UIHK_NISOverlay::UpdateAudioMuteState();
  return UFG::UIScreen::handleMessage(this, msgId, msg);
}

// File Line: 272
// RVA: 0x61F780
void __fastcall UFG::UIHKScreenMissionFailed::createScreen(
        bool playerDied,
        const char *titleText,
        const char *bodyText,
        const char *hintText,
        bool showRestoreCheckpointOption)
{
  UFG::UIScreenTextureManager *v7; // rax

  dword_14208EB48 = playerDied;
  UFG::qString::Set(&stru_14208EB50, titleText);
  UFG::qString::Set(&stru_14208EB78, bodyText);
  UFG::qString::Set(&stru_14208EBA0, hintText);
  byte_14208EBC8 = showRestoreCheckpointOption;
  UFG::SoundBankManager::QueueBankForLoad(&ui_mission_fail);
  v7 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::QueueLoadAndPush(v7, "Dialog_MissionFailed", 0i64);
  UFG::UIScreenManagerBase::queueMessage(UFG::UIScreenManager::s_instance, UI_HASH_GAME_OVER_20, 0xFFFFFFFF);
}

// File Line: 289
// RVA: 0x61F620
void UFG::UIHKScreenMissionFailed::createPlayerDiedDialog(void)
{
  UFG::UIScreenTextureManager *v0; // rax

  dword_14208EB48 = 1;
  UFG::qString::Set(&stru_14208EB50, "$GLOBAL_GAME_OVER_DIED");
  UFG::qString::Set(&stru_14208EB78, &customCaption);
  byte_14208EBC8 = 0;
  UFG::SoundBankManager::QueueBankForLoad(&ui_mission_fail);
  v0 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::QueueLoadAndPush(v0, "Dialog_MissionFailed", 0i64);
  UFG::UIScreenManagerBase::queueMessage(UFG::UIScreenManager::s_instance, UI_HASH_GAME_OVER_20, 0xFFFFFFFF);
}

// File Line: 305
// RVA: 0x5E17B0
void __fastcall UFG::UIHKScreenMissionFailed::Flash_SetTitleText(
        UFG::UIHKScreenMissionFailed *this,
        const char *caption)
{
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h] BYREF

  pObject = this->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    `eh vector constructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( (pargs.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        pargs.mValue);
      pargs.pObjectInterface = 0i64;
    }
    pargs.Type = VT_String;
    pargs.mValue.pString = caption;
    Scaleform::GFx::Movie::Invoke(pObject, "MissionFailed_SetTitleText", 0i64, &pargs, 1u);
    `eh vector destructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 319
// RVA: 0x5DF7F0
void __fastcall UFG::UIHKScreenMissionFailed::Flash_SetBodyText(
        UFG::UIHKScreenMissionFailed *this,
        const char *caption)
{
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h] BYREF

  pObject = this->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    `eh vector constructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( (pargs.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        pargs.mValue);
      pargs.pObjectInterface = 0i64;
    }
    pargs.Type = VT_String;
    pargs.mValue.pString = caption;
    Scaleform::GFx::Movie::Invoke(pObject, "MissionFailed_SetBodyText", 0i64, &pargs, 1u);
    `eh vector destructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 333
// RVA: 0x5E01D0
void __fastcall UFG::UIHKScreenMissionFailed::Flash_SetHintText(
        UFG::UIHKScreenMissionFailed *this,
        const char *caption)
{
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h] BYREF

  pObject = this->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    `eh vector constructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( (pargs.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        pargs.mValue);
      pargs.pObjectInterface = 0i64;
    }
    pargs.Type = VT_String;
    pargs.mValue.pString = caption;
    Scaleform::GFx::Movie::Invoke(pObject, "MissionFailed_SetHintText", 0i64, &pargs, 1u);
    `eh vector destructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 347
// RVA: 0x5DE6F0
void __fastcall UFG::UIHKScreenMissionFailed::Flash_PlayIntro(UFG::UIHKScreenMissionFailed *this, int reason)
{
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h] BYREF

  pObject = this->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    `eh vector constructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( (pargs.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        pargs.mValue);
      pargs.pObjectInterface = 0i64;
    }
    pargs.Type = VT_Number;
    pargs.mValue.NValue = (double)reason;
    Scaleform::GFx::Movie::Invoke(pObject, "MissionFailed_PlayIntro", 0i64, &pargs, 1u);
    `eh vector destructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 361
// RVA: 0x5DE7D0
void __fastcall UFG::UIHKScreenMissionFailed::Flash_PlayOutro(UFG::UIHKScreenMissionFailed *this, int reason)
{
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h] BYREF

  pObject = this->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    `eh vector constructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( (pargs.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        pargs.mValue);
      pargs.pObjectInterface = 0i64;
    }
    pargs.Type = VT_Number;
    pargs.mValue.NValue = (double)reason;
    Scaleform::GFx::Movie::Invoke(pObject, "MissionFailed_PlayOutro", 0i64, &pargs, 1u);
    `eh vector destructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 375
// RVA: 0x5E03F0
void __fastcall UFG::UIHKScreenMissionFailed::Flash_SetNumButtons(UFG::UIHKScreenMissionFailed *this, int numButtons)
{
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h] BYREF

  pObject = this->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    `eh vector constructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( (pargs.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        pargs.mValue);
      pargs.pObjectInterface = 0i64;
    }
    pargs.Type = VT_Number;
    pargs.mValue.NValue = (double)numButtons;
    Scaleform::GFx::Movie::Invoke(pObject, "MissionFailed_SetNumButtons", 0i64, &pargs, 1u);
    `eh vector destructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 391
// RVA: 0x5DF8D0
void __fastcall UFG::UIHKScreenMissionFailed::Flash_SetButtonHighlight(
        UFG::UIHKScreenMissionFailed *this,
        int button,
        bool isHighlight)
{
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value pargs; // [rsp+40h] [rbp-68h] BYREF
  char v7[16]; // [rsp+70h] [rbp-38h] BYREF
  __int64 v8; // [rsp+80h] [rbp-28h]
  int v9; // [rsp+88h] [rbp-20h]
  __int64 v10; // [rsp+90h] [rbp-18h]

  pObject = this->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    `eh vector constructor iterator(&pargs, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( (pargs.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        pargs.mValue);
      pargs.pObjectInterface = 0i64;
    }
    pargs.Type = VT_Number;
    pargs.mValue.NValue = (double)button;
    if ( (v9 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v8 + 16i64))(v8, v7, v10);
      v8 = 0i64;
    }
    v9 = 2;
    LOBYTE(v10) = isHighlight;
    Scaleform::GFx::Movie::Invoke(pObject, "MissionFailed_SetButtonHighlight", 0i64, &pargs, 2u);
    `eh vector destructor iterator(&pargs, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 420
// RVA: 0x5DA500
void __fastcall UFG::UIHKScreenMissionFailed::Flash_ConfirmCancelMission(UFG::UIHKScreenMissionFailed *this)
{
  Scaleform::GFx::Movie *pObject; // rcx

  pObject = this->mRenderable->m_movie.pObject;
  if ( pObject )
    Scaleform::GFx::Movie::Invoke(pObject, "MissionFailed_ConfirmCancelMission", 0i64, 0i64, 0);
}

