// File Line: 30
// RVA: 0x1570910
__int64 UFG::_dynamic_initializer_for__start_mission_fail__()
{
  start_mission_fail_0.mUID = UFG::qWiseSymbolUIDFromString("start_mission_fail", 0x811C9DC5);
  _((AMD_HD3D *)start_mission_fail_0.mUID);
  return atexit(UFG::_dynamic_atexit_destructor_for__start_mission_fail__);
}

// File Line: 31
// RVA: 0x1570990
__int64 UFG::_dynamic_initializer_for__stop_mission_fail__()
{
  stop_mission_fail_0.mUID = UFG::qWiseSymbolUIDFromString("stop_mission_fail", 0x811C9DC5);
  _((AMD_HD3D *)stop_mission_fail_0.mUID);
  return atexit(UFG::_dynamic_atexit_destructor_for__stop_mission_fail__);
}

// File Line: 32
// RVA: 0x15724A0
__int64 UFG::_dynamic_initializer_for__ui_mission_fail__()
{
  ui_mission_fail.mUID = UFG::qWiseSymbolUIDFromString("ui_mission_fail", 0x811C9DC5);
  _((AMD_HD3D *)ui_mission_fail.mUID);
  return atexit(UFG::_dynamic_atexit_destructor_for__ui_mission_fail__);
}

// File Line: 37
// RVA: 0x1566F50
__int64 dynamic_initializer_for__UFG::UIHKScreenMissionFailed::mData__()
{
  UFG::UIHKScreenMissionFailed::mData.vfptr = (UFG::UICommandDataVtbl *)&UFG::UIHKMissionFailedData::`vftable';
  dword_14208EB48 = 0;
  UFG::qString::qString(&stru_14208EB50);
  UFG::qString::qString(&stru_14208EB78);
  UFG::qString::qString(&stru_14208EBA0);
  unk_14208EBC8 = 1;
  return atexit(dynamic_atexit_destructor_for__UFG::UIHKScreenMissionFailed::mData__);
}

// File Line: 54
// RVA: 0x5C6220
void __fastcall UFG::UIHKScreenMissionFailed::UIHKScreenMissionFailed(UFG::UIHKScreenMissionFailed *this)
{
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v1; // rax

  v1 = (UFG::qNode<UFG::UIScreen,UFG::UIScreen> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIScreen::`vftable';
  this->m_screenNameHash = 0;
  this->mRenderable = 0i64;
  this->mLoadThread = 0i64;
  this->mScreenUID = -1;
  *(_QWORD *)&this->mControllerMask = 15i64;
  *(_QWORD *)&this->mPriority = 0i64;
  this->mDimToApplyType = 0;
  *(_QWORD *)&this->mCurDimValue = 1120403456i64;
  this->m_screenName[0] = 0;
  --this->mInputEnabled;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenMissionFailed::`vftable';
  *(_QWORD *)&this->mState = 0i64;
  this->mSelectedOption = 1;
  this->mCanCancelMission = 0;
  UFG::UIHKDepthOfFieldWidget::UIHKDepthOfFieldWidget(&this->DoF);
}

// File Line: 60
// RVA: 0x5CB950
void __fastcall UFG::UIHKScreenMissionFailed::~UIHKScreenMissionFailed(UFG::UIHKScreenMissionFailed *this)
{
  UFG::UIHKScreenMissionFailed *v1; // rbx
  UFG::UIScreenTextureManager *v2; // rax
  int v3; // eax
  UFG::UIHKScreenGlobalOverlay *v4; // rax

  v1 = this;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenMissionFailed::`vftable';
  UFG::SoundBankManager::QueueBankForUnload((UFG::qWiseSymbol *)&ui_mission_fail.mUID);
  v2 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v2, "Dialog_MissionFailed");
  v3 = UFG::UIHKHelpBarWidget::mLocked;
  if ( UFG::UIHKHelpBarWidget::mLocked > 0 )
    v3 = UFG::UIHKHelpBarWidget::mLocked-- - 1;
  if ( v3 < 1 )
  {
    v4 = UFG::UIHKScreenGlobalOverlay::mThis;
    if ( !UFG::UIHKScreenGlobalOverlay::mThis )
      v4 = &gGlobalOverlaySentinel;
    v4->HelpBar.mChanged = 1;
  }
  UFG::UIHKScreenMissionFailed::gIsRace = 0;
  UFG::GameCameraComponent::EndDOFOverride(0);
  UFG::UIScreen::~UIScreen((UFG::UIScreen *)&v1->vfptr);
}

// File Line: 70
// RVA: 0x632E40
void __fastcall UFG::UIHKScreenMissionFailed::init(UFG::UIHKScreenMissionFailed *this, UFG::UICommandData *data)
{
  UFG::UIHKScreenMissionFailed *v2; // rbx

  v2 = this;
  UFG::UIScreen::init((UFG::UIScreen *)&this->vfptr, data);
  v2->mState = 1;
}

// File Line: 81
// RVA: 0x63E220
void __fastcall UFG::UIHKScreenMissionFailed::update(UFG::UIHKScreenMissionFailed *this, float elapsed)
{
  UFG::UIHKScreenMissionFailed *v2; // rbx
  Scaleform::GFx::Movie *v3; // rcx
  UFG::UIHKActionButtonWidget *v4; // rcx
  bool v5; // zf

  v2 = this;
  if ( this->mState == 1 && UFG::SoundBankManager::BankLoadRequestFinished((UFG::qWiseSymbol *)&ui_mission_fail.mUID) )
  {
    UFG::AudioEntity::CreateAndPlayEvent(
      (UFG::AudioEntity *)&UFG::AmbienceAudio::m_instance->vfptr,
      start_mission_fail_0.mUID,
      0i64,
      0,
      0i64);
    UFG::UIHKScreenMissionFailed::Flash_SetButtonHighlight(v2, 1, 0);
    UFG::UIHKScreenMissionFailed::Flash_SetButtonHighlight(v2, 2, 1);
    UFG::UIHKScreenMissionFailed::Flash_SetTitleText(v2, stru_14208EB50.mData);
    UFG::UIHKScreenMissionFailed::Flash_SetBodyText(v2, stru_14208EB78.mData);
    UFG::UIHKScreenMissionFailed::Flash_SetHintText(v2, stru_14208EBA0.mData);
    if ( unk_14208EBC8 )
    {
      UFG::UIHKScreenMissionFailed::Flash_SetNumButtons(v2, 2);
      v2->mCanCancelMission = 1;
    }
    else
    {
      UFG::UIHKScreenMissionFailed::Flash_SetNumButtons(v2, 1);
    }
    if ( UFG::UIHKScreenMissionFailed::gIsRace )
    {
      v3 = v2->mRenderable->m_movie.pObject;
      if ( v3 )
        Scaleform::GFx::Movie::Invoke(v3, "MissionFailed_SetRaceOptions", 0i64, 0i64, 0);
    }
    UFG::UIHKScreenMissionFailed::Flash_PlayIntro(v2, dword_14208EB48);
    v2->mState = 2;
    if ( UFG::UIHKScreenGlobalOverlay::mThis
      && UFG::UIHKScreenGlobalOverlay::mThis != (UFG::UIHKScreenGlobalOverlay *)-408i64 )
    {
      UFG::UIHK_NISOverlay::HideElement(
        &UFG::UIHKScreenGlobalOverlay::mThis->NISOverlay,
        (UFG::UIScreen *)&UFG::UIHKScreenGlobalOverlay::mThis->vfptr,
        &UFG::UIHK_NISOverlay::m_curtains,
        0.0,
        0);
    }
    UFG::UIHK_NISOverlay::UpdateAudioMuteState();
    ++UFG::UIHK_NISOverlay::mLock;
    ++UFG::UIHKHelpBarWidget::mLocked;
    UFG::UIHKGameplayHelpWidget::ClearAll(UFG::UIHKScreenHud::GameplayHelp);
    v4 = UFG::UIHKScreenHud::ActionButton;
    v5 = UFG::UIHKScreenHud::ActionButton->mVisible == 0;
    UFG::UIHKScreenHud::ActionButton->mVisible = 0;
    v4->mChanged |= !v5;
    UFG::UIHKScreenHud::ResetWidgets();
  }
  UFG::UIScreen::update((UFG::UIScreen *)&v2->vfptr, elapsed);
}

// File Line: 134
// RVA: 0x625A20
bool __fastcall UFG::UIHKScreenMissionFailed::handleMessage(UFG::UIHKScreenMissionFailed *this, unsigned int msgId, UFG::UIMessage *msg)
{
  UFG::UIHKScreenMissionFailed *v3; // rbx
  UFG::UIMessage *v4; // rbp
  unsigned int v5; // edi
  __int32 v6; // ecx
  int v7; // ecx
  UFG::UIHKScreenMissionFailed::eResult v8; // eax
  unsigned int v9; // edx
  unsigned int v10; // ecx
  unsigned int v11; // esi
  unsigned int v12; // ecx
  unsigned int v13; // esi
  UFG::HudAudio *v14; // rcx
  unsigned int v15; // edx

  v3 = this;
  v4 = msg;
  v5 = msgId;
  v6 = this->mState - 2;
  if ( !v6 )
  {
    if ( msgId != UI_HASH_BUTTON_ACCEPT_PRESSED_30 && msgId != UI_HASH_MOUSE_BUTTON_LEFT_PRESSED_30 )
    {
      if ( msgId != UI_HASH_BUTTON_BACK_PRESSED_30 || !v3->mCanCancelMission )
        return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v3->vfptr, v5, v4);
      if ( UFG::UIHKScreenMissionFailed::gIsRace )
      {
        v3->mResult = 2;
        UFG::UIHKScreenMissionFailed::Flash_PlayOutro(v3, dword_14208EB48);
        v3->mState = 4;
      }
      else
      {
        UFG::UIHKScreenMissionFailed::Flash_ConfirmCancelMission(v3);
        v3->mState = 3;
      }
      v14 = UFG::HudAudio::m_instance;
      if ( !UFG::HudAudio::m_instance )
        return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v3->vfptr, v5, v4);
      v15 = 0xCBB448ED;
LABEL_42:
      UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&v14->vfptr, v15, 0i64, 0, 0i64);
      return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v3->vfptr, v5, v4);
    }
    v3->mResult = 1;
    UFG::UIHKScreenMissionFailed::Flash_PlayOutro(v3, dword_14208EB48);
    v3->mState = 4;
    if ( UFG::UIHK_NISOverlay::m_curtains.m_state == STATE_CURTAIN_HIDDEN )
    {
      if ( UFG::UIHKScreenGlobalOverlay::mThis
        && UFG::UIHKScreenGlobalOverlay::mThis != (UFG::UIHKScreenGlobalOverlay *)-408i64 )
      {
        UFG::UIHK_NISOverlay::ShowElement(
          &UFG::UIHKScreenGlobalOverlay::mThis->NISOverlay,
          (UFG::UIScreen *)&UFG::UIHKScreenGlobalOverlay::mThis->vfptr,
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
      return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v3->vfptr, v5, v4);
    v15 = 558069486;
    goto LABEL_42;
  }
  v7 = v6 - 1;
  if ( !v7 )
  {
    if ( msgId == UI_HASH_BUTTON_ACCEPT_PRESSED_30 || msgId == UI_HASH_MOUSE_BUTTON_LEFT_PRESSED_30 )
    {
      v3->mResult = 2;
    }
    else
    {
      if ( !unk_14208EBC8 || msgId != UI_HASH_BUTTON_BACK_PRESSED_30 )
        return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v3->vfptr, v5, v4);
      v3->mResult = 1;
    }
    UFG::UIHKScreenMissionFailed::Flash_PlayOutro(v3, dword_14208EB48);
    v3->mState = 4;
    goto LABEL_40;
  }
  if ( v7 != 1 || msgId != UI_HASH_OUTRO_COMPLETE_30 )
    return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v3->vfptr, v5, v4);
  v8 = v3->mResult;
  if ( v8 == 1 )
  {
    v9 = UI_HASH_DIALOG_YES_30;
  }
  else
  {
    if ( v8 != 2 )
    {
      v12 = UFG::UIHK_NISOverlay::m_current_audio_event_index;
      v13 = stop_mission_fail_0.mUID;
      if ( UFG::UIHK_NISOverlay::m_current_audio_event_index == 7 )
      {
        UFG::UIHK_NISOverlay::FirePostNISAudioEventQueue();
        v12 = UFG::UIHK_NISOverlay::m_current_audio_event_index;
      }
      UFG::UIHK_NISOverlay::m_post_nis_hide_curtain_audio_events[v12] = v13;
      UFG::UIHK_NISOverlay::m_current_audio_event_index = v12 + 1;
      UFG::UIScreenManagerBase::queueMessage(
        (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
        UI_HASH_DIALOG_NO_30,
        0xFFFFFFFF);
      goto LABEL_15;
    }
    v9 = UI_HASH_DIALOG_NO_30;
  }
  UFG::UIScreenManagerBase::queueMessage(
    (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
    v9,
    0xFFFFFFFF);
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
  UFG::UIScreenManagerBase::queuePopScreen(
    (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
    0xFFFFFFFF);
  if ( UFG::UIHKScreenGlobalOverlay::mThis
    && UFG::UIHKScreenGlobalOverlay::mThis != (UFG::UIHKScreenGlobalOverlay *)-408i64 )
  {
    UFG::UIHK_NISOverlay::ShowElement(
      &UFG::UIHKScreenGlobalOverlay::mThis->NISOverlay,
      (UFG::UIScreen *)&UFG::UIHKScreenGlobalOverlay::mThis->vfptr,
      &UFG::UIHK_NISOverlay::m_curtains,
      0.0,
      0);
    UFG::UIHK_NISOverlay::m_curtains.m_mutingAudio = 0;
  }
  UFG::UIHK_NISOverlay::UpdateAudioMuteState();
  return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v3->vfptr, v5, v4);
}

// File Line: 272
// RVA: 0x61F780
void __fastcall UFG::UIHKScreenMissionFailed::createScreen(bool playerDied, const char *titleText, const char *bodyText, const char *hintText, bool showRestoreCheckpointOption)
{
  const char *v5; // rdi
  const char *v6; // rbx
  UFG::UIScreenTextureManager *v7; // rax

  v5 = hintText;
  v6 = bodyText;
  dword_14208EB48 = playerDied != 0;
  UFG::qString::Set(&stru_14208EB50, titleText);
  UFG::qString::Set(&stru_14208EB78, v6);
  UFG::qString::Set(&stru_14208EBA0, v5);
  unk_14208EBC8 = showRestoreCheckpointOption;
  UFG::SoundBankManager::QueueBankForLoad((UFG::qWiseSymbol *)&ui_mission_fail.mUID);
  v7 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::QueueLoadAndPush(v7, "Dialog_MissionFailed", 0i64);
  UFG::UIScreenManagerBase::queueMessage(
    (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
    UI_HASH_GAME_OVER_20,
    0xFFFFFFFF);
}

// File Line: 289
// RVA: 0x61F620
void UFG::UIHKScreenMissionFailed::createPlayerDiedDialog(void)
{
  UFG::UIScreenTextureManager *v0; // rax

  dword_14208EB48 = 1;
  UFG::qString::Set(&stru_14208EB50, "$GLOBAL_GAME_OVER_DIED");
  UFG::qString::Set(&stru_14208EB78, &customWorldMapCaption);
  unk_14208EBC8 = 0;
  UFG::SoundBankManager::QueueBankForLoad((UFG::qWiseSymbol *)&ui_mission_fail.mUID);
  v0 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::QueueLoadAndPush(v0, "Dialog_MissionFailed", 0i64);
  UFG::UIScreenManagerBase::queueMessage(
    (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
    UI_HASH_GAME_OVER_20,
    0xFFFFFFFF);
}

// File Line: 305
// RVA: 0x5E17B0
void __fastcall UFG::UIHKScreenMissionFailed::Flash_SetTitleText(UFG::UIHKScreenMissionFailed *this, const char *caption)
{
  const char *v2; // rdi
  Scaleform::GFx::Movie *v3; // rbx
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h]

  v2 = caption;
  v3 = this->mRenderable->m_movie.pObject;
  if ( v3 )
  {
    `eh vector constructor iterator'(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( ((unsigned int)pargs.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        *(_QWORD *)&pargs.mValue.NValue);
      pargs.pObjectInterface = 0i64;
    }
    pargs.Type = 6;
    *(_QWORD *)&pargs.mValue.NValue = v2;
    Scaleform::GFx::Movie::Invoke(v3, "MissionFailed_SetTitleText", 0i64, &pargs, 1u);
    `eh vector destructor iterator'(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 319
// RVA: 0x5DF7F0
void __fastcall UFG::UIHKScreenMissionFailed::Flash_SetBodyText(UFG::UIHKScreenMissionFailed *this, const char *caption)
{
  const char *v2; // rdi
  Scaleform::GFx::Movie *v3; // rbx
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h]

  v2 = caption;
  v3 = this->mRenderable->m_movie.pObject;
  if ( v3 )
  {
    `eh vector constructor iterator'(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( ((unsigned int)pargs.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        *(_QWORD *)&pargs.mValue.NValue);
      pargs.pObjectInterface = 0i64;
    }
    pargs.Type = 6;
    *(_QWORD *)&pargs.mValue.NValue = v2;
    Scaleform::GFx::Movie::Invoke(v3, "MissionFailed_SetBodyText", 0i64, &pargs, 1u);
    `eh vector destructor iterator'(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 333
// RVA: 0x5E01D0
void __fastcall UFG::UIHKScreenMissionFailed::Flash_SetHintText(UFG::UIHKScreenMissionFailed *this, const char *caption)
{
  const char *v2; // rdi
  Scaleform::GFx::Movie *v3; // rbx
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h]

  v2 = caption;
  v3 = this->mRenderable->m_movie.pObject;
  if ( v3 )
  {
    `eh vector constructor iterator'(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( ((unsigned int)pargs.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        *(_QWORD *)&pargs.mValue.NValue);
      pargs.pObjectInterface = 0i64;
    }
    pargs.Type = 6;
    *(_QWORD *)&pargs.mValue.NValue = v2;
    Scaleform::GFx::Movie::Invoke(v3, "MissionFailed_SetHintText", 0i64, &pargs, 1u);
    `eh vector destructor iterator'(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 347
// RVA: 0x5DE6F0
void __fastcall UFG::UIHKScreenMissionFailed::Flash_PlayIntro(UFG::UIHKScreenMissionFailed *this, int reason)
{
  int v2; // edi
  Scaleform::GFx::Movie *v3; // rbx
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h]

  v2 = reason;
  v3 = this->mRenderable->m_movie.pObject;
  if ( v3 )
  {
    `eh vector constructor iterator'(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( ((unsigned int)pargs.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        *(_QWORD *)&pargs.mValue.NValue);
      pargs.pObjectInterface = 0i64;
    }
    pargs.Type = 5;
    pargs.mValue.NValue = (double)v2;
    Scaleform::GFx::Movie::Invoke(v3, "MissionFailed_PlayIntro", 0i64, &pargs, 1u);
    `eh vector destructor iterator'(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 361
// RVA: 0x5DE7D0
void __fastcall UFG::UIHKScreenMissionFailed::Flash_PlayOutro(UFG::UIHKScreenMissionFailed *this, int reason)
{
  int v2; // edi
  Scaleform::GFx::Movie *v3; // rbx
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h]

  v2 = reason;
  v3 = this->mRenderable->m_movie.pObject;
  if ( v3 )
  {
    `eh vector constructor iterator'(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( ((unsigned int)pargs.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        *(_QWORD *)&pargs.mValue.NValue);
      pargs.pObjectInterface = 0i64;
    }
    pargs.Type = 5;
    pargs.mValue.NValue = (double)v2;
    Scaleform::GFx::Movie::Invoke(v3, "MissionFailed_PlayOutro", 0i64, &pargs, 1u);
    `eh vector destructor iterator'(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 375
// RVA: 0x5E03F0
void __fastcall UFG::UIHKScreenMissionFailed::Flash_SetNumButtons(UFG::UIHKScreenMissionFailed *this, int numButtons)
{
  int v2; // edi
  Scaleform::GFx::Movie *v3; // rbx
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h]

  v2 = numButtons;
  v3 = this->mRenderable->m_movie.pObject;
  if ( v3 )
  {
    `eh vector constructor iterator'(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( ((unsigned int)pargs.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        *(_QWORD *)&pargs.mValue.NValue);
      pargs.pObjectInterface = 0i64;
    }
    pargs.Type = 5;
    pargs.mValue.NValue = (double)v2;
    Scaleform::GFx::Movie::Invoke(v3, "MissionFailed_SetNumButtons", 0i64, &pargs, 1u);
    `eh vector destructor iterator'(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 391
// RVA: 0x5DF8D0
void __fastcall UFG::UIHKScreenMissionFailed::Flash_SetButtonHighlight(UFG::UIHKScreenMissionFailed *this, int button, bool isHighlight)
{
  bool v3; // si
  int v4; // edi
  Scaleform::GFx::Movie *v5; // rbx
  Scaleform::GFx::Value pargs; // [rsp+40h] [rbp-68h]
  char v7; // [rsp+70h] [rbp-38h]
  __int64 v8; // [rsp+80h] [rbp-28h]
  unsigned int v9; // [rsp+88h] [rbp-20h]
  __int64 v10; // [rsp+90h] [rbp-18h]

  v3 = isHighlight;
  v4 = button;
  v5 = this->mRenderable->m_movie.pObject;
  if ( v5 )
  {
    `eh vector constructor iterator'(&pargs, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( ((unsigned int)pargs.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        *(_QWORD *)&pargs.mValue.NValue);
      pargs.pObjectInterface = 0i64;
    }
    pargs.Type = 5;
    pargs.mValue.NValue = (double)v4;
    if ( (v9 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v8 + 16i64))(v8, &v7, v10);
      v8 = 0i64;
    }
    v9 = 2;
    LOBYTE(v10) = v3;
    Scaleform::GFx::Movie::Invoke(v5, "MissionFailed_SetButtonHighlight", 0i64, &pargs, 2u);
    `eh vector destructor iterator'(&pargs, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 420
// RVA: 0x5DA500
void __fastcall UFG::UIHKScreenMissionFailed::Flash_ConfirmCancelMission(UFG::UIHKScreenMissionFailed *this)
{
  Scaleform::GFx::Movie *v1; // rcx

  v1 = this->mRenderable->m_movie.pObject;
  if ( v1 )
    Scaleform::GFx::Movie::Invoke(v1, "MissionFailed_ConfirmCancelMission", 0i64, 0i64, 0);
}

