// File Line: 45
// RVA: 0x156E0D0
__int64 UFG::_dynamic_initializer_for__gUpgradesHelpBarId__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("upgrades_helpbar", 0xFFFFFFFF);
  gUpgradesHelpBarId = result;
  return result;
}

// File Line: 57
// RVA: 0x5C7960
void __fastcall UFG::UIHKScreenUpgrades::UIHKScreenUpgrades(UFG::UIHKScreenUpgrades *this)
{
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v1; // rax
  int *v2; // rax
  signed __int64 v3; // rdx

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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenUpgrades::`vftable';
  *(_WORD *)&this->mCanUpgrade = 0;
  this->mIsKeyboardController = 0;
  this->mState = 0;
  v2 = this->mCursorYPos;
  v3 = 5i64;
  do
  {
    v2[5] = 0;
    *v2 = 1;
    ++v2;
    --v3;
  }
  while ( v3 );
}

// File Line: 66
// RVA: 0x5CCE70
void __fastcall UFG::UIHKScreenUpgrades::~UIHKScreenUpgrades(UFG::UIHKScreenUpgrades *this)
{
  UFG::UIHKScreenUpgrades *v1; // rbx
  UFG::UIHKScreenGlobalOverlay *v2; // rax
  UFG::UIScreenTextureManager *v3; // rax
  UFG::UI *v4; // rcx
  UFG::UIScreenTextureManager *v5; // rax
  UFG::UI *v6; // rcx
  unsigned int v7; // eax

  v1 = this;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenUpgrades::`vftable';
  v2 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    v2 = &gGlobalOverlaySentinel;
  UFG::UIHKHelpBarWidget::Hide(&v2->HelpBar, gUpgradesHelpBarId);
  v3 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v3, "Upgrades");
  if ( (unsigned int)(UFG::UIHKScreenUpgrades::mMode - 1) <= 1 )
  {
    UFG::UI::UnpauseGame(v4);
  }
  else
  {
    v5 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::QueueLoadAndPush(v5, "PauseMenu", 0i64);
  }
  if ( UFG::gInputSystem )
  {
    if ( UFG::gActiveControllerNum != -1 )
    {
      v7 = UFG::UI::gUIInputLocked;
      if ( !UFG::UI::gUIInputLocked || (--UFG::UI::gUIInputLocked, v7 == 1) )
        UFG::UI::ResetGameplayInput(v6);
    }
  }
  UFG::UIHKScreenUpgrades::mMode = 0;
  if ( v1->mUnpauseOnExit )
    UFG::UI::UnpauseGame(v6);
  UFG::UIScreen::~UIScreen((UFG::UIScreen *)&v1->vfptr);
}

// File Line: 101
// RVA: 0x636D50
void __fastcall UFG::UIHKScreenUpgrades::init(UFG::UIHKScreenUpgrades *this, UFG::UICommandData *data)
{
  UFG::UIHKScreenUpgrades *v2; // rbx
  UFG::UICommandData *v3; // rdi
  UFG::Controller *v4; // rcx
  bool v5; // al

  v2 = this;
  v3 = data;
  if ( UFG::gInputSystem && UFG::gActiveControllerNum != -1 )
  {
    v4 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum];
    if ( !UFG::UI::gUIInputLocked )
      g_saved_gameplay_controller_mode = v4->m_ActiveMapSet;
    UFG::SetInputMode(IM_UI_ONLY, v4->mControllerIndex);
    ++UFG::UI::gUIInputLocked;
  }
  if ( !(unsigned __int8)UFG::UI::IsGamePaused() )
  {
    v2->mUnpauseOnExit = 1;
    UFG::UI::PauseGame(0i64);
  }
  UFG::UIScreen::init((UFG::UIScreen *)&v2->vfptr, v3);
  v5 = (signed int)UFG::UIHKScreenUpgrades::GetUpgradePointsAvailable(UFG::UIHKScreenUpgrades::mUpgradesType) > 0
    && UFG::UIHKScreenUpgrades::mUpgradesType != 2
    || UFG::UIHKScreenUpgrades::mMode == 1;
  v2->mCanUpgrade = v5;
  UFG::UIHKScreenUpgrades::Flash_InitText(v2);
  UFG::UIHKScreenUpgrades::Flash_Init(v2);
  UFG::UIHKScreenUpgrades::PopulateHelpBar(v2);
  UFG::UIHKScreenUpgrades::Flash_RefreshCursor(v2);
  ((void (__fastcall *)(UFG::TiDo *, signed __int64))UFG::TiDo::m_pInstance->vfptr[1].Close)(
    UFG::TiDo::m_pInstance,
    1i64);
  if ( UFG::UIHKScreenGlobalOverlay::mThis
    && UFG::UIHKScreenGlobalOverlay::mThis != (UFG::UIHKScreenGlobalOverlay *)-408i64 )
  {
    UFG::UIHK_NISOverlay::HideElement(
      &UFG::UIHKScreenGlobalOverlay::mThis->NISOverlay,
      (UFG::UIScreen *)&UFG::UIHKScreenGlobalOverlay::mThis->vfptr,
      &UFG::UIHK_NISOverlay::m_curtains,
      1.0,
      0);
  }
  UFG::UIHK_NISOverlay::UpdateAudioMuteState();
}

// File Line: 122
// RVA: 0x5E9990
__int64 __fastcall UFG::UIHKScreenUpgrades::GetUpgradePointsAvailable(UFG::UIHKScreenUpgrades::eUpgradesType type)
{
  __int32 v1; // ecx
  UFG::GameStatTracker *v2; // rax
  unsigned int v3; // ebx
  UFG::GameStatTracker *v5; // rax
  int v6; // ebx
  UFG::GameStatTracker *v7; // rax
  int v8; // ebx
  UFG::GameStatTracker *v9; // rax
  UFG::GameStat::Int32Stat v10; // edx
  UFG::GameStatTracker *v11; // rax
  int v12; // ebx
  UFG::GameStatTracker *v13; // rax
  unsigned int v14; // ebx

  if ( type )
  {
    v1 = type - 1;
    if ( v1 )
    {
      if ( v1 != 1 )
        return 0i64;
      v2 = UFG::GameStatTracker::Instance();
      v3 = UFG::GameStatTracker::GetStat(v2, StatueUpgradePoint);
      if ( (v3 & 0x80000000) != 0 )
        v3 = 0;
      return v3;
    }
    v5 = UFG::GameStatTracker::Instance();
    v6 = UFG::GameStatTracker::GetStat(v5, TriadUpgradePoint);
    v7 = UFG::GameStatTracker::Instance();
    v8 = v6 - (unsigned __int64)UFG::GameStatTracker::GetStat(v7, TriadOffensiveStage);
    v9 = UFG::GameStatTracker::Instance();
    v10 = 24;
  }
  else
  {
    v11 = UFG::GameStatTracker::Instance();
    v12 = UFG::GameStatTracker::GetStat(v11, CopUpgradePoint);
    v13 = UFG::GameStatTracker::Instance();
    v8 = v12 - (unsigned __int64)UFG::GameStatTracker::GetStat(v13, CopShootingStage);
    v9 = UFG::GameStatTracker::Instance();
    v10 = 27;
  }
  v14 = v8 - (unsigned __int64)UFG::GameStatTracker::GetStat(v9, v10);
  if ( (v14 & 0x80000000) != 0 )
    v14 = 0;
  return v14;
}

// File Line: 156
// RVA: 0x5F49A0
void __fastcall UFG::UIHKScreenUpgrades::Populate(UFG::UIHKScreenUpgrades *this)
{
  UFG::UIHKScreenUpgrades *v1; // rbx
  bool v2; // al

  v1 = this;
  v2 = (signed int)UFG::UIHKScreenUpgrades::GetUpgradePointsAvailable(UFG::UIHKScreenUpgrades::mUpgradesType) > 0
    && UFG::UIHKScreenUpgrades::mUpgradesType != 2
    || UFG::UIHKScreenUpgrades::mMode == 1;
  v1->mCanUpgrade = v2;
  UFG::UIHKScreenUpgrades::Flash_InitText(v1);
  UFG::UIHKScreenUpgrades::Flash_Init(v1);
  UFG::UIHKScreenUpgrades::PopulateHelpBar(v1);
  UFG::UIHKScreenUpgrades::Flash_RefreshCursor(v1);
}

// File Line: 172
// RVA: 0x5F7140
void __fastcall UFG::UIHKScreenUpgrades::PopulateHelpBar(UFG::UIHKScreenUpgrades *this)
{
  UFG::UIHKScreenUpgrades *v1; // rbx
  int v2; // esi
  unsigned int v3; // er14
  int v4; // ecx
  __int64 v5; // rax
  __int64 v6; // rdi
  __int64 v7; // rbx
  unsigned int v8; // er14
  int v9; // ecx
  __int64 v10; // rax
  __int64 v11; // rdi
  __int64 v12; // rbx
  unsigned int v13; // er14
  int v14; // ecx
  __int64 v15; // rax
  __int64 v16; // rdi
  __int64 v17; // rbx
  unsigned int v18; // er14
  __int64 v19; // rax
  __int64 v20; // rdi
  __int64 v21; // rbx
  UFG::UIHKScreenGlobalOverlay *v22; // rax
  UFG::UIHKHelpBarData data; // [rsp+30h] [rbp-C8h]

  v1 = this;
  UFG::UIHKHelpBarData::UIHKHelpBarData(&data);
  data.id = gUpgradesHelpBarId;
  v2 = 0;
  data.alignment = 0;
  if ( v1->mCanUpgrade
    && UFG::UIHKScreenUpgrades::IsUpgradable(
         v1,
         v1->mCursorXPos[UFG::UIHKScreenUpgrades::mUpgradesType],
         v1->mCursorYPos[UFG::UIHKScreenUpgrades::mUpgradesType]) )
  {
    v3 = UI_HASH_BUTTON_ACCEPT_PRESSED_30;
    v4 = 0;
    v5 = 0i64;
    while ( data.Buttons[v5] )
    {
      ++v4;
      if ( ++v5 >= 6 )
        goto LABEL_8;
    }
    v6 = v4;
    data.Buttons[v6] = 1;
    v7 = v4;
    UFG::qString::Set(&data.Captions[v7], "$COMMON_ACCEPT_UPPERCASE");
    UFG::qString::Set((UFG::qString *)((char *)&data.Captions[v7 + 5] + 32), &customWorldMapCaption);
    *(unsigned int *)((char *)&data.Icons[5].mStringHash32 + v6 * 4) = v3;
  }
LABEL_8:
  if ( UFG::UIHKScreenUpgrades::mMode != 1 )
  {
    v8 = UI_HASH_BUTTON_BACK_PRESSED_30;
    v9 = 0;
    v10 = 0i64;
    while ( data.Buttons[v10] )
    {
      ++v9;
      if ( ++v10 >= 6 )
        goto LABEL_14;
    }
    v11 = v9;
    data.Buttons[v11] = 2;
    v12 = v9;
    UFG::qString::Set(&data.Captions[v12], "$COMMON_BACK_UPPERCASE");
    UFG::qString::Set((UFG::qString *)((char *)&data.Captions[v12 + 5] + 32), &customWorldMapCaption);
    *(unsigned int *)((char *)&data.Icons[5].mStringHash32 + v11 * 4) = v8;
LABEL_14:
    v13 = UI_HASH_BUTTON_R1_PRESSED_30;
    v14 = 0;
    v15 = 0i64;
    while ( data.Buttons[v15] )
    {
      ++v14;
      if ( ++v15 >= 6 )
        goto LABEL_19;
    }
    v16 = v14;
    data.Buttons[v16] = 13;
    v17 = v14;
    UFG::qString::Set(&data.Captions[v17], "$HELPBAR_CHANGE_SECTION_UC");
    UFG::qString::Set((UFG::qString *)((char *)&data.Captions[v17 + 5] + 32), &customWorldMapCaption);
    *(unsigned int *)((char *)&data.Icons[5].mStringHash32 + v16 * 4) = v13;
  }
LABEL_19:
  v18 = UI_HASH_BUTTON_SELECT_PRESSED_30;
  v19 = 0i64;
  while ( data.Buttons[v19] )
  {
    ++v2;
    if ( ++v19 >= 6 )
      goto LABEL_24;
  }
  v20 = v2;
  data.Buttons[v20] = 6;
  v21 = v2;
  UFG::qString::Set(&data.Captions[v21], "$BUTTON_REMAP_HELP");
  UFG::qString::Set((UFG::qString *)((char *)&data.Captions[v21 + 5] + 32), &customWorldMapCaption);
  *(unsigned int *)((char *)&data.Icons[5].mStringHash32 + v20 * 4) = v18;
LABEL_24:
  v22 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    v22 = &gGlobalOverlaySentinel;
  UFG::UIHKHelpBarWidget::Show(&v22->HelpBar, &data);
  UFG::qString::~qString((UFG::qString *)&data.MessageIds[4]);
  `eh vector destructor iterator'(
    &data.Captions[5].mStringHash32,
    0x28ui64,
    6,
    (void (__fastcall *)(void *))UFG::qString::~qString);
  `eh vector destructor iterator'(data.Captions, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
}

// File Line: 194
// RVA: 0x640450
void __fastcall UFG::UIHKScreenUpgrades::update(UFG::UIHKScreenUpgrades *this, float elapsed)
{
  UFG::UIHKScreenUpgrades *v2; // rbx
  bool v3; // al
  Scaleform::GFx::Movie *v4; // rax

  v2 = this;
  v3 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController;
  if ( v3 != this->mIsKeyboardController )
  {
    this->mIsKeyboardController = v3;
    v4 = UFG::UIScreen::getMovieSafe((UFG::UIScreen *)&this->vfptr);
    if ( v4 )
      Scaleform::GFx::Movie::Invoke(v4, "KeyboardControllerStatusChanged", 0i64, 0i64, 0);
  }
  UFG::UIScreen::update((UFG::UIScreen *)&v2->vfptr, elapsed);
}

// File Line: 213
// RVA: 0x62D5F0
bool __fastcall UFG::UIHKScreenUpgrades::handleMessage(UFG::UIHKScreenUpgrades *this, unsigned int msgId, UFG::UIMessage *msg)
{
  UFG::UIHKScreenUpgrades::eMode v3; // er9
  UFG::UIMessage *v4; // rbp
  unsigned int v5; // edi
  UFG::UIHKScreenUpgrades *v6; // rbx
  UFG::HudAudio *v7; // rcx
  UFG::UIHKScreenUpgrades::eState v8; // edx
  int v9; // edx
  int v10; // edx
  UFG::UIScreen *v11; // rax
  UFG::UIHKScreenGlobalOverlay *v12; // rcx
  int v14; // eax

  v3 = UFG::UIHKScreenUpgrades::mMode;
  v4 = msg;
  v5 = msgId;
  v6 = this;
  if ( !this->mCanUpgrade || UFG::UIHKScreenUpgrades::mMode != 1 )
  {
    if ( msgId == UI_HASH_BUTTON_BACK_PRESSED_30 )
    {
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(
          (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
          0xA4E5BFBD,
          0i64,
          0,
          0i64);
      UFG::UIScreenManagerBase::queuePopScreen(
        (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
        0xFFFFFFFF);
      return 1;
    }
    if ( msgId == UI_HASH_BUTTON_ACCEPT_PRESSED_30 )
    {
      v7 = UFG::HudAudio::m_instance;
      if ( !UFG::HudAudio::m_instance )
        goto LABEL_11;
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        0xA4E5BFBD,
        0i64,
        0,
        0i64);
      v3 = UFG::UIHKScreenUpgrades::mMode;
    }
  }
  v7 = UFG::HudAudio::m_instance;
LABEL_11:
  v8 = v6->mState;
  if ( v8 == STATE_INVALID )
  {
    if ( v5 == UI_HASH_BUTTON_L1_PRESSED_30 )
    {
      if ( v3 != 1 )
      {
        if ( v7 )
          UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&v7->vfptr, 0xC415B16F, 0i64, 0, 0i64);
        UFG::UIHKScreenUpgrades::ScrollPrevTab(v6);
      }
      return 1;
    }
    if ( v5 == UI_HASH_BUTTON_R1_PRESSED_30 )
    {
      if ( v3 != 1 )
      {
        if ( v7 )
          UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&v7->vfptr, 0xC415B16F, 0i64, 0, 0i64);
        UFG::UIHKScreenUpgrades::ScrollNextTab(v6);
      }
      return 1;
    }
    if ( v5 == UI_HASH_BUTTON_SELECT_PRESSED_30 )
    {
      v6->mState = 2;
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(
          (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
          0x5958830u,
          0i64,
          0,
          0i64);
      if ( UFG::UIHKScreenUpgrades::mUpgradesType )
      {
        switch ( UFG::UIHKScreenUpgrades::mUpgradesType )
        {
          case 1:
            UFG::UIScreenDialogBox::createOKDialog(
              (UFG::UIScreen *)&v6->vfptr,
              &customWorldMapCaption,
              "$PAUSE_UPGRADES_HELP_TRIAD",
              0);
            break;
          case 2:
            UFG::UIScreenDialogBox::createOKDialog(
              (UFG::UIScreen *)&v6->vfptr,
              &customWorldMapCaption,
              "$PAUSE_UPGRADES_HELP_MELEE",
              0);
            break;
          case 3:
            UFG::UIScreenDialogBox::createOKDialog(
              (UFG::UIScreen *)&v6->vfptr,
              &customWorldMapCaption,
              "$PAUSE_UPGRADES_HELP_FACE",
              0);
            break;
          case 4:
            UFG::UIScreenDialogBox::createOKDialog(
              (UFG::UIScreen *)&v6->vfptr,
              &customWorldMapCaption,
              "$PAUSE_UPGRADES_HELP_HEALTH",
              0);
            break;
        }
      }
      else
      {
        UFG::UIScreenDialogBox::createOKDialog(
          (UFG::UIScreen *)&v6->vfptr,
          &customWorldMapCaption,
          "$PAUSE_UPGRADES_HELP_POLICE",
          0);
      }
    }
    else
    {
      if ( v5 == UI_HASH_BUTTON_ACCEPT_PRESSED_30 )
      {
        if ( v6->mCanUpgrade
          && UFG::UIHKScreenUpgrades::IsUpgradable(
               v6,
               v6->mCursorXPos[UFG::UIHKScreenUpgrades::mUpgradesType],
               v6->mCursorYPos[UFG::UIHKScreenUpgrades::mUpgradesType]) )
        {
          v6->mState = 1;
          if ( UFG::HudAudio::m_instance )
            UFG::AudioEntity::CreateAndPlayEvent(
              (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
              0xF41B2F0D,
              0i64,
              0,
              0i64);
          UFG::UIScreenDialogBox::createYesNoDialog(
            (UFG::UIScreen *)&v6->vfptr,
            &customWorldMapCaption,
            "$DIALOG_CONFIRMATION_1",
            1,
            0);
        }
        return 1;
      }
      if ( v5 == UI_HASH_DPAD_UP_PRESSED_30 || v5 == UI_HASH_THUMBSTICK_LEFT_UP_30 )
      {
        if ( UFG::UIHKScreenUpgrades::mUpgradesType != 3 )
          UFG::UIHKScreenUpgrades::MoveCursorUp(v6);
        return 1;
      }
      if ( v5 == UI_HASH_DPAD_DOWN_PRESSED_30 || v5 == UI_HASH_THUMBSTICK_LEFT_DOWN_30 )
      {
        if ( UFG::UIHKScreenUpgrades::mUpgradesType != 3 )
          UFG::UIHKScreenUpgrades::MoveCursorDown(v6);
        return 1;
      }
      if ( v5 == UI_HASH_DPAD_LEFT_PRESSED_30 || v5 == UI_HASH_THUMBSTICK_LEFT_LEFT_30 )
      {
        UFG::UIHKScreenUpgrades::MoveCursorLeft(v6);
        return 1;
      }
      if ( v5 == UI_HASH_DPAD_RIGHT_PRESSED_30 || v5 == UI_HASH_THUMBSTICK_LEFT_RIGHT_30 )
      {
        UFG::UIHKScreenUpgrades::MoveCursorRight(v6);
        return 1;
      }
    }
    v11 = UFG::UIScreenManagerBase::getOverlay(
            (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
            "GlobalOverlay");
    if ( v11 )
    {
      v12 = UFG::UIHKScreenGlobalOverlay::mThis;
      if ( !UFG::UIHKScreenGlobalOverlay::mThis )
        v12 = &gGlobalOverlaySentinel;
      UFG::UIHKHelpBarWidget::HandleMessage(&v12->HelpBar, v11, v5, v4);
    }
    if ( v5 == UI_HASH_MOUSE_MOVE_30 )
    {
      UFG::UIHKScreenUpgrades::Flash_HandleMouseMove(v6, (float)SLODWORD(v4[1].vfptr), (float)SHIDWORD(v4[1].vfptr));
      return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v6->vfptr, v5, v4);
    }
    if ( v5 == UI_HASH_MOUSE_BUTTON_LEFT_PRESSED_30 )
    {
      UFG::UIHKScreenSaveLoad::Flash_HandleMouseClick(v6, (float)SLODWORD(v4[1].vfptr), (float)SHIDWORD(v4[1].vfptr));
      return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v6->vfptr, v5, v4);
    }
    if ( v5 == UI_HASH_MOUSE_CHANGE_TAB_20 )
    {
      if ( UFG::UIHKScreenUpgrades::mMode != 1 )
      {
        v14 = UFG::UIHKScreenUpgrades::Flash_GetMouseNewTab(v6);
        UFG::UIHKScreenUpgrades::SetTab(v6, v14);
        return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v6->vfptr, v5, v4);
      }
    }
    else if ( v5 == UI_HASH_MOUSE_WHEEL_SCROLL_30 )
    {
      if ( SLODWORD(v4[1].mPrev) > 0 )
      {
        UFG::UIHKScreenUpgrades::MoveCursorPrev(v6);
        return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v6->vfptr, v5, v4);
      }
      UFG::UIHKScreenUpgrades::MoveCursorNext(v6);
    }
    return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v6->vfptr, v5, v4);
  }
  v9 = v8 - 1;
  if ( v9 )
  {
    v10 = v9 - 1;
    if ( v10 )
    {
      if ( v10 == 1 && v5 == UI_HASH_WIDGET_ANIM_DONE_20 )
      {
        if ( v3 == 1 )
        {
          UFG::UIScreenManagerBase::queuePopScreen(
            (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
            0xFFFFFFFF);
          v6->mState = 4;
        }
        else
        {
          UFG::UIHKScreenUpgrades::Populate(v6);
          v6->mState = 0;
        }
        return 1;
      }
      return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v6->vfptr, v5, v4);
    }
    if ( v5 != UI_HASH_DIALOG_OK_30 )
      return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v6->vfptr, v5, v4);
    v6->mState = 0;
  }
  else
  {
    if ( v5 == UI_HASH_DIALOG_YES_30 )
    {
      v6->mState = 3;
      UFG::UIHKScreenUpgrades::ApplyUpgrade(v6);
      if ( UFG::HudAudio::m_instance )
      {
        UFG::AudioEntity::CreateAndPlayEvent(
          (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
          0x9C1F87EB,
          0i64,
          0,
          0i64);
        if ( UFG::HudAudio::m_instance )
          UFG::AudioEntity::CreateAndPlayEvent(
            (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
            0x5BC35965u,
            0i64,
            0,
            0i64);
      }
      return 1;
    }
    if ( v5 != UI_HASH_DIALOG_NO_30 )
      return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v6->vfptr, v5, v4);
    v6->mState = 0;
  }
  return 1;
}

// File Line: 417
// RVA: 0x5D3EF0
void __fastcall UFG::UIHKScreenUpgrades::ApplyUpgrade(UFG::UIHKScreenUpgrades *this)
{
  UFG::UIHKScreenUpgrades *v1; // rbx
  UFG::GameStatTracker *v2; // rax
  UFG::GameStat::Int32Stat v3; // er8
  UFG::GameStatTracker *v4; // rax
  UFG::GameStatTracker *v5; // rax
  UFG::GameStatTracker *v6; // rax
  UFG::GameStatTracker *v7; // rax
  UFG::GameStatTracker *v8; // rax

  v1 = this;
  UFG::UIHKScreenUpgrades::Flash_HandleUpgradeSelected(this);
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(
      (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
      0x9C1F87EB,
      0i64,
      0,
      0i64);
  if ( UFG::UIHKScreenUpgrades::mUpgradesType )
  {
    if ( UFG::UIHKScreenUpgrades::mUpgradesType == 1 )
    {
      if ( v1->mCursorYPos[1] <= 0 )
      {
        v6 = UFG::GameStatTracker::Instance();
        UFG::GameStatTracker::ApplyDelta(v6, TriadOffensiveStage, 1);
        v3 = 25;
      }
      else
      {
        v5 = UFG::GameStatTracker::Instance();
        UFG::GameStatTracker::ApplyDelta(v5, TriadDefensiveStage, 1);
        v3 = 24;
      }
    }
    else
    {
      if ( UFG::UIHKScreenUpgrades::mUpgradesType != 2 )
        return;
      if ( v1->mCursorYPos[2] <= 0 )
      {
        v4 = UFG::GameStatTracker::Instance();
        UFG::GameStatTracker::ApplyDelta(v4, StatueOffensiveStage, 1);
        v3 = 23;
      }
      else
      {
        v2 = UFG::GameStatTracker::Instance();
        UFG::GameStatTracker::ApplyDelta(v2, StatueDefensiveStage, 1);
        v3 = 22;
      }
    }
  }
  else if ( v1->mCursorYPos[0] <= 0 )
  {
    v8 = UFG::GameStatTracker::Instance();
    UFG::GameStatTracker::ApplyDelta(v8, CopShootingStage, 1);
    v3 = 28;
  }
  else
  {
    v7 = UFG::GameStatTracker::Instance();
    UFG::GameStatTracker::ApplyDelta(v7, CopDrivingStage, 1);
    v3 = 27;
  }
  UFG::UIHKScreenUpgrades::SendTelemetryData(v1, UFG::UIHKScreenUpgrades::mUpgradesType, v3);
}

// File Line: 495
// RVA: 0x5E9A60
__int64 __fastcall UFG::UIHKScreenUpgrades::GetUpperTrackLevel(UFG::UIHKScreenUpgrades *this)
{
  UFG::GameStatTracker *v1; // rax
  __int64 result; // rax
  UFG::GameStatTracker *v3; // rax
  UFG::GameStatTracker *v4; // rax
  UFG::GameStatTracker *v5; // rax
  UFG::GameStatTracker *v6; // rax

  if ( UFG::UIHKScreenUpgrades::mUpgradesType )
  {
    switch ( UFG::UIHKScreenUpgrades::mUpgradesType )
    {
      case 1:
        v5 = UFG::GameStatTracker::Instance();
        result = UFG::GameStatTracker::GetStat(v5, TriadOffensiveStage);
        break;
      case 2:
        v4 = UFG::GameStatTracker::Instance();
        result = (unsigned int)UFG::GameStatTracker::GetStat(v4, StatueOffensiveStage) - 1;
        break;
      case 3:
        v3 = UFG::GameStatTracker::Instance();
        result = UFG::GameStatTracker::GetFaceLevel(v3);
        break;
      case 4:
        v1 = UFG::GameStatTracker::Instance();
        result = UFG::GameStatTracker::GetHealthLevel(v1);
        break;
      default:
        result = 0i64;
        break;
    }
  }
  else
  {
    v6 = UFG::GameStatTracker::Instance();
    result = UFG::GameStatTracker::GetStat(v6, CopShootingStage);
  }
  return result;
}

// File Line: 547
// RVA: 0x5E8330
__int64 __fastcall UFG::UIHKScreenUpgrades::GetLowerTrackLevel(UFG::UIHKScreenUpgrades *this)
{
  UFG::GameStatTracker *v1; // rax
  __int64 result; // rax
  UFG::GameStatTracker *v3; // rax
  UFG::GameStatTracker *v4; // rax
  UFG::GameStatTracker *v5; // rax

  if ( UFG::UIHKScreenUpgrades::mUpgradesType )
  {
    switch ( UFG::UIHKScreenUpgrades::mUpgradesType )
    {
      case 1:
        v4 = UFG::GameStatTracker::Instance();
        result = UFG::GameStatTracker::GetStat(v4, TriadDefensiveStage);
        break;
      case 2:
        v3 = UFG::GameStatTracker::Instance();
        result = UFG::GameStatTracker::GetStat(v3, StatueDefensiveStage);
        break;
      case 3:
        v1 = UFG::GameStatTracker::Instance();
        result = UFG::GameStatTracker::GetFaceLevel(v1);
        break;
      default:
        result = 0i64;
        break;
    }
  }
  else
  {
    v5 = UFG::GameStatTracker::Instance();
    result = UFG::GameStatTracker::GetStat(v5, CopDrivingStage);
  }
  return result;
}

// File Line: 584
// RVA: 0x5E83C0
signed __int64 __fastcall UFG::UIHKScreenUpgrades::GetMaxUpperTrackLevel(UFG::UIHKScreenUpgrades *this)
{
  switch ( UFG::UIHKScreenUpgrades::mUpgradesType )
  {
    case 0:
    case 1:
      return 5i64;
    case 2:
      return 6i64;
    case 3:
      return 10i64;
  }
  return 0i64;
}

// File Line: 627
// RVA: 0x5EE930
bool __fastcall UFG::UIHKScreenUpgrades::IsUpgradable(UFG::UIHKScreenUpgrades *this, int posX, int posY)
{
  int v3; // esi
  UFG::UIHKScreenUpgrades *v4; // rdi
  bool v5; // bl
  signed int v6; // ebx
  _BOOL8 v7; // rax

  v3 = posX;
  v4 = this;
  if ( (signed int)UFG::UIHKScreenUpgrades::mUpgradesType < 0 )
    goto LABEL_26;
  if ( (signed int)UFG::UIHKScreenUpgrades::mUpgradesType <= 1 )
  {
    if ( posY )
      v7 = (unsigned int)UFG::UIHKScreenUpgrades::GetLowerTrackLevel(this) + 1 == posX;
    else
      v7 = (unsigned int)UFG::UIHKScreenUpgrades::GetUpperTrackLevel(this) + 1 == posX;
    return v7;
  }
  if ( UFG::UIHKScreenUpgrades::mUpgradesType != 2 )
  {
LABEL_26:
    LOBYTE(v7) = 0;
    return v7;
  }
  if ( posY )
  {
    v5 = (unsigned int)UFG::UIHKScreenUpgrades::GetLowerTrackLevel(this) + 1 == posX;
    goto LABEL_18;
  }
  v5 = (unsigned int)UFG::UIHKScreenUpgrades::GetUpperTrackLevel(this) + 1 == posX;
  if ( v3 != (unsigned int)UFG::UIHKScreenUpgrades::GetMaxUpperTrackLevel(v4) )
  {
LABEL_18:
    LOBYTE(v7) = v5;
    return v7;
  }
  LOBYTE(v7) = v5
            && (UFG::UIHKScreenUpgrades::mUpgradesType == UPGRADES_TYPE_POLICE
             || UFG::UIHKScreenUpgrades::mUpgradesType == 1
             || UFG::UIHKScreenUpgrades::mUpgradesType == 2 ? (v6 = 5) : UFG::UIHKScreenUpgrades::mUpgradesType == 3 ? (v6 = 10) : (v6 = 0),
                (unsigned int)UFG::UIHKScreenUpgrades::GetLowerTrackLevel(v4) == v6);
  return v7;
}

// File Line: 647
// RVA: 0x6041F0
void __fastcall UFG::UIHKScreenUpgrades::ScrollNextTab(UFG::UIHKScreenUpgrades *this)
{
  UFG::UIHKScreenUpgrades *v1; // rbx
  char v2; // di
  __int32 v3; // ecx

  v1 = this;
  v2 = 0;
  v3 = UFG::UIHKScreenUpgrades::mUpgradesType + 1;
  if ( UFG::UIHKScreenUpgrades::mUpgradesType + 1 >= 5 )
    v3 = 0;
  UFG::UIHKScreenUpgrades::mUpgradesType = v3;
  if ( (signed int)UFG::UIHKScreenUpgrades::GetUpgradePointsAvailable((UFG::UIHKScreenUpgrades::eUpgradesType)v3) > 0
    && UFG::UIHKScreenUpgrades::mUpgradesType != 2
    || UFG::UIHKScreenUpgrades::mMode == 1 )
  {
    v2 = 1;
  }
  v1->mCanUpgrade = v2;
  UFG::UIHKScreenUpgrades::Flash_InitText(v1);
  UFG::UIHKScreenUpgrades::Flash_Init(v1);
  UFG::UIHKScreenUpgrades::PopulateHelpBar(v1);
  UFG::UIHKScreenUpgrades::Flash_RefreshCursor(v1);
}

// File Line: 660
// RVA: 0x6043C0
void __fastcall UFG::UIHKScreenUpgrades::ScrollPrevTab(UFG::UIHKScreenUpgrades *this)
{
  UFG::UIHKScreenUpgrades *v1; // rbx
  UFG::UIHKScreenUpgrades::eUpgradesType v2; // ecx
  bool v3; // al

  v1 = this;
  v2 = UFG::UIHKScreenUpgrades::mUpgradesType;
  if ( (signed int)UFG::UIHKScreenUpgrades::mUpgradesType <= 0 )
    v2 = 5;
  UFG::UIHKScreenUpgrades::mUpgradesType = v2 - 1;
  v3 = (signed int)UFG::UIHKScreenUpgrades::GetUpgradePointsAvailable((UFG::UIHKScreenUpgrades::eUpgradesType)(v2 - 1)) > 0
    && UFG::UIHKScreenUpgrades::mUpgradesType != 2
    || UFG::UIHKScreenUpgrades::mMode == 1;
  v1->mCanUpgrade = v3;
  UFG::UIHKScreenUpgrades::Flash_InitText(v1);
  UFG::UIHKScreenUpgrades::Flash_Init(v1);
  UFG::UIHKScreenUpgrades::PopulateHelpBar(v1);
  UFG::UIHKScreenUpgrades::Flash_RefreshCursor(v1);
}

// File Line: 673
// RVA: 0x609F90
void __fastcall UFG::UIHKScreenUpgrades::SetTab(UFG::UIHKScreenUpgrades *this, int index)
{
  UFG::UIHKScreenUpgrades *v2; // rbx
  bool v3; // al

  v2 = this;
  UFG::UIHKScreenUpgrades::mUpgradesType = index;
  v3 = (signed int)UFG::UIHKScreenUpgrades::GetUpgradePointsAvailable((UFG::UIHKScreenUpgrades::eUpgradesType)index) > 0
    && UFG::UIHKScreenUpgrades::mUpgradesType != 2
    || UFG::UIHKScreenUpgrades::mMode == 1;
  v2->mCanUpgrade = v3;
  UFG::UIHKScreenUpgrades::Flash_InitText(v2);
  UFG::UIHKScreenUpgrades::Flash_Init(v2);
  UFG::UIHKScreenUpgrades::PopulateHelpBar(v2);
  UFG::UIHKScreenUpgrades::Flash_RefreshCursor(v2);
}

// File Line: 680
// RVA: 0x5F1F70
void __fastcall UFG::UIHKScreenUpgrades::MoveCursorLeft(UFG::UIHKScreenUpgrades *this)
{
  UFG::UIHKScreenUpgrades *v1; // rbx
  char *v2; // rcx
  int v3; // eax

  v1 = this;
  v2 = (char *)this + 4 * UFG::UIHKScreenUpgrades::mUpgradesType;
  v3 = *((_DWORD *)v2 + 41);
  if ( v3 > 0 )
  {
    *((_DWORD *)v2 + 41) = v3 - 1;
    if ( !v1->mCursorXPos[UFG::UIHKScreenUpgrades::mUpgradesType] && UFG::UIHKScreenUpgrades::mUpgradesType != 3 )
      v1->mCursorYPos[UFG::UIHKScreenUpgrades::mUpgradesType] = 1;
    UFG::UIHKScreenUpgrades::PopulateHelpBar(v1);
    UFG::UIHKScreenUpgrades::Flash_RefreshCursor(v1);
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        0xC415B16F,
        0i64,
        0,
        0i64);
  }
}

// File Line: 693
// RVA: 0x5F2140
void __fastcall UFG::UIHKScreenUpgrades::MoveCursorRight(UFG::UIHKScreenUpgrades *this)
{
  UFG::UIHKScreenUpgrades *v1; // rbx
  int v2; // er9
  signed int v3; // eax
  int v4; // ecx

  v1 = this;
  v2 = this->mCursorYPos[UFG::UIHKScreenUpgrades::mUpgradesType];
  if ( !v2 )
  {
    if ( UFG::UIHKScreenUpgrades::mUpgradesType && UFG::UIHKScreenUpgrades::mUpgradesType != 1 )
    {
      if ( UFG::UIHKScreenUpgrades::mUpgradesType != 2 )
      {
        if ( UFG::UIHKScreenUpgrades::mUpgradesType != 3 )
        {
          v3 = 0;
          goto LABEL_15;
        }
        goto LABEL_7;
      }
      v3 = 6;
      goto LABEL_15;
    }
LABEL_14:
    v3 = 5;
    goto LABEL_15;
  }
  if ( UFG::UIHKScreenUpgrades::mUpgradesType == UPGRADES_TYPE_POLICE
    || UFG::UIHKScreenUpgrades::mUpgradesType == 1
    || UFG::UIHKScreenUpgrades::mUpgradesType == 2 )
  {
    goto LABEL_14;
  }
  if ( UFG::UIHKScreenUpgrades::mUpgradesType == 3 )
  {
LABEL_7:
    v3 = 10;
    goto LABEL_15;
  }
  v3 = 0;
LABEL_15:
  if ( UFG::UIHKScreenUpgrades::mUpgradesType == 3 )
    --v3;
  v4 = this->mCursorXPos[UFG::UIHKScreenUpgrades::mUpgradesType];
  if ( v4 < v3 )
  {
    v1->mCursorXPos[UFG::UIHKScreenUpgrades::mUpgradesType] = v4 + 1;
    goto LABEL_22;
  }
  if ( v2 == 1 && UFG::UIHKScreenUpgrades::mUpgradesType == 2 )
  {
    v1->mCursorYPos[2] = 0;
    ++v1->mCursorXPos[UFG::UIHKScreenUpgrades::mUpgradesType];
LABEL_22:
    UFG::UIHKScreenUpgrades::PopulateHelpBar(v1);
    UFG::UIHKScreenUpgrades::Flash_RefreshCursor(v1);
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        0xC415B16F,
        0i64,
        0,
        0i64);
  }
}

// File Line: 718
// RVA: 0x5F2220
void __fastcall UFG::UIHKScreenUpgrades::MoveCursorUp(UFG::UIHKScreenUpgrades *this)
{
  UFG::UIHKScreenUpgrades *v1; // rbx
  char *v2; // rcx
  int v3; // edx

  v1 = this;
  v2 = (char *)this + 4 * UFG::UIHKScreenUpgrades::mUpgradesType;
  v3 = *((_DWORD *)v2 + 36);
  if ( v3 > 0 && v1->mCursorXPos[UFG::UIHKScreenUpgrades::mUpgradesType] )
  {
    *((_DWORD *)v2 + 36) = v3 - 1;
    UFG::UIHKScreenUpgrades::PopulateHelpBar(v1);
    UFG::UIHKScreenUpgrades::Flash_RefreshCursor(v1);
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        0xC415B16F,
        0i64,
        0,
        0i64);
  }
}

// File Line: 730
// RVA: 0x5F1F00
void __fastcall UFG::UIHKScreenUpgrades::MoveCursorDown(UFG::UIHKScreenUpgrades *this)
{
  UFG::UIHKScreenUpgrades *v1; // rbx

  v1 = this;
  if ( !this->mCursorYPos[UFG::UIHKScreenUpgrades::mUpgradesType]
    && (UFG::UIHKScreenUpgrades::mUpgradesType != 2 || this->mCursorXPos[2] != 6) )
  {
    this->mCursorYPos[UFG::UIHKScreenUpgrades::mUpgradesType] = 1;
    UFG::UIHKScreenUpgrades::PopulateHelpBar(this);
    UFG::UIHKScreenUpgrades::Flash_RefreshCursor(v1);
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        0xC415B16F,
        0i64,
        0,
        0i64);
  }
}

// File Line: 747
// RVA: 0x5F2000
void __fastcall UFG::UIHKScreenUpgrades::MoveCursorNext(UFG::UIHKScreenUpgrades *this)
{
  UFG::UIHKScreenUpgrades *v1; // rbx

  v1 = this;
  if ( UFG::UIHKScreenUpgrades::mUpgradesType == 3 )
  {
    UFG::UIHKScreenUpgrades::MoveCursorRight(this);
  }
  else if ( this->mCursorYPos[UFG::UIHKScreenUpgrades::mUpgradesType] )
  {
    UFG::UIHKScreenUpgrades::MoveCursorRight(this);
    UFG::UIHKScreenUpgrades::MoveCursorUp(v1);
  }
  else if ( UFG::UIHKScreenUpgrades::mUpgradesType != 2 || this->mCursorXPos[2] != 6 )
  {
    this->mCursorYPos[UFG::UIHKScreenUpgrades::mUpgradesType] = 1;
    UFG::UIHKScreenUpgrades::PopulateHelpBar(this);
    UFG::UIHKScreenUpgrades::Flash_RefreshCursor(v1);
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        0xC415B16F,
        0i64,
        0,
        0i64);
  }
}

// File Line: 766
// RVA: 0x5F20A0
void __fastcall UFG::UIHKScreenUpgrades::MoveCursorPrev(UFG::UIHKScreenUpgrades *this)
{
  UFG::UIHKScreenUpgrades *v1; // rbx
  int v2; // eax

  v1 = this;
  if ( UFG::UIHKScreenUpgrades::mUpgradesType == 3 )
  {
    UFG::UIHKScreenUpgrades::MoveCursorLeft(this);
  }
  else
  {
    v2 = this->mCursorYPos[UFG::UIHKScreenUpgrades::mUpgradesType];
    if ( v2 > 0 && this->mCursorXPos[UFG::UIHKScreenUpgrades::mUpgradesType] )
    {
      this->mCursorYPos[UFG::UIHKScreenUpgrades::mUpgradesType] = v2 - 1;
      UFG::UIHKScreenUpgrades::PopulateHelpBar(this);
      UFG::UIHKScreenUpgrades::Flash_RefreshCursor(v1);
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(
          (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
          0xC415B16F,
          0i64,
          0,
          0i64);
    }
    else
    {
      UFG::UIHKScreenUpgrades::MoveCursorLeft(this);
      UFG::UIHKScreenUpgrades::MoveCursorDown(v1);
    }
  }
}

// File Line: 785
// RVA: 0x5DDA20
void __fastcall UFG::UIHKScreenUpgrades::Flash_InitText(UFG::UIHKScreenUpgrades *this)
{
  char *v1; // r12
  unsigned int v2; // er13
  char v3; // r15
  __int64 v4; // rdx
  UFG::UIGfxTranslator *v5; // rcx
  unsigned int v6; // eax
  UFG::UIGfxTranslator *v7; // rcx
  unsigned int v8; // eax
  UFG::UIGfxTranslator *v9; // rcx
  unsigned int v10; // eax
  UFG::UIGfxTranslator *v11; // rcx
  unsigned __int64 v12; // rdi
  unsigned int v13; // er14
  signed __int64 v14; // r15
  char *v15; // rbx
  const char *v16; // rax
  unsigned int v17; // eax
  UFG::UIGfxTranslator *v18; // rcx
  char *v19; // rbx
  const char *v20; // rax
  unsigned int v21; // eax
  UFG::UIGfxTranslator *v22; // rcx
  unsigned int v23; // eax
  UFG::UIGfxTranslator *v24; // rcx
  unsigned int v25; // eax
  UFG::UIGfxTranslator *v26; // rcx
  unsigned __int64 v27; // rdi
  unsigned int v28; // er14
  signed __int64 v29; // r15
  char *v30; // rbx
  const char *v31; // rax
  unsigned int v32; // eax
  UFG::UIGfxTranslator *v33; // rcx
  char *v34; // rbx
  const char *v35; // rax
  unsigned int v36; // eax
  UFG::UIGfxTranslator *v37; // rcx
  signed __int64 v38; // r15
  unsigned int v39; // eax
  UFG::UIGfxTranslator *v40; // rcx
  unsigned int v41; // eax
  UFG::UIGfxTranslator *v42; // rcx
  unsigned __int64 v43; // rdi
  unsigned int v44; // er14
  char *v45; // rbx
  const char *v46; // rax
  unsigned int v47; // eax
  UFG::UIGfxTranslator *v48; // rcx
  char *v49; // rbx
  const char *v50; // rax
  unsigned int v51; // eax
  UFG::UIGfxTranslator *v52; // rcx
  signed __int64 v53; // r15
  unsigned int v54; // eax
  UFG::UIGfxTranslator *v55; // rcx
  unsigned int v56; // eax
  UFG::UIGfxTranslator *v57; // rcx
  unsigned __int64 v58; // rdi
  unsigned int v59; // er14
  char *v60; // rbx
  const char *v61; // rax
  unsigned int v62; // eax
  UFG::UIGfxTranslator *v63; // rcx
  char *v64; // rbx
  const char *v65; // rax
  unsigned int v66; // eax
  UFG::UIGfxTranslator *v67; // rcx
  Scaleform::GFx::Movie *v68; // rsi
  unsigned int v69; // ebx
  __int64 v70; // rdi
  __int64 v71; // r14
  const char *v72; // rdx
  char *v73; // rax
  char *v74; // rax
  UFG::GameStatTracker *v75; // rax
  int v76; // ebx
  UFG::GameStatTracker *v77; // rax
  signed int v78; // edi
  UFG::GameStatTracker *v79; // rax
  UFG::GameStatTracker *v80; // rax
  int v81; // ebx
  UFG::GameStatTracker *v82; // rax
  UFG::GameStatTracker *v83; // rax
  UFG::GameStatTracker::ThresholdType v84; // edx
  UFG::GameStatTracker *v85; // rax
  UFG::GameStatTracker *v86; // rax
  double v87; // xmm6_8
  double v88; // xmm6_8
  char *caption; // [rsp+30h] [rbp-D0h]
  UFG::qString v90; // [rsp+38h] [rbp-C8h]
  Scaleform::GFx::Value v91; // [rsp+68h] [rbp-98h]
  Scaleform::GFx::Value value; // [rsp+98h] [rbp-68h]
  __int64 v93; // [rsp+C8h] [rbp-38h]
  UFG::qString v94; // [rsp+D0h] [rbp-30h]
  char v95[24]; // [rsp+100h] [rbp+0h]
  char *v96; // [rsp+118h] [rbp+18h]
  char ptr[24]; // [rsp+2E0h] [rbp+1E0h]
  char *str; // [rsp+2F8h] [rbp+1F8h]
  UFG::UIHKScreenUpgrades *v99; // [rsp+520h] [rbp+420h]
  char v100; // [rsp+528h] [rbp+428h]
  unsigned int iExpTowardsNextLevel; // [rsp+530h] [rbp+430h]
  unsigned int iDiffBetweenLevels; // [rsp+538h] [rbp+438h]

  v99 = this;
  v93 = -2i64;
  `eh vector constructor iterator'(ptr, 0x28ui64, 12, (void (__fastcall *)(void *))UFG::qString::qString);
  `eh vector constructor iterator'(v95, 0x28ui64, 12, (void (__fastcall *)(void *))UFG::qString::qString);
  caption = &customWorldMapCaption;
  v1 = &customWorldMapCaption;
  v2 = 0;
  v3 = 1;
  switch ( UFG::UIHKScreenUpgrades::mUpgradesType )
  {
    case 0:
      v53 = 11i64;
      v2 = 11;
      v100 = 0;
      caption = "$PAUSE_UPGRADES_POLICE_HEADER";
      v54 = UFG::qStringHashUpper32("PAUSE_UPGRADES_POLICE_HEADER", 0xFFFFFFFF);
      v55 = UFG::UIScreenManager::s_instance->m_translator;
      if ( !v55 || (v1 = (char *)v55->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v55->vfptr, v54)) == 0i64 )
        v1 = "PAUSE_UPGRADES_POLICE_HEADER";
      v56 = UFG::qStringHashUpper32("PAUSE_POLICE_LEVEL_UPPERCASE", 0xFFFFFFFF);
      v57 = UFG::UIScreenManager::s_instance->m_translator;
      if ( v57 )
        v57->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v57->vfptr, v56);
      v58 = 0i64;
      v59 = 1;
      do
      {
        UFG::qString::Format((UFG::qString *)&ptr[v58], "$PAUSE_POLICE_LEVEL_HEADER_%d", v59);
        v60 = (&str)[v58 / 8];
        if ( v60 )
        {
          if ( *v60 == 36 )
            ++v60;
          v62 = UFG::qStringHashUpper32(v60, 0xFFFFFFFF);
          v63 = UFG::UIScreenManager::s_instance->m_translator;
          if ( !v63
            || (v61 = (const char *)v63->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v63->vfptr, v62)) == 0i64 )
          {
            v61 = v60;
          }
        }
        else
        {
          v61 = 0i64;
        }
        UFG::qString::Set((UFG::qString *)&ptr[v58], v61);
        UFG::qString::Format((UFG::qString *)&v95[v58], "$PAUSE_POLICE_LEVEL_INFO_%d", v59);
        v64 = (&v96)[v58 / 8];
        if ( v64 )
        {
          if ( *v64 == 36 )
            ++v64;
          v66 = UFG::qStringHashUpper32(v64, 0xFFFFFFFF);
          v67 = UFG::UIScreenManager::s_instance->m_translator;
          if ( !v67
            || (v65 = (const char *)v67->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v67->vfptr, v66)) == 0i64 )
          {
            v65 = v64;
          }
        }
        else
        {
          v65 = 0i64;
        }
        UFG::qString::Set((UFG::qString *)&v95[v58], v65);
        ++v59;
        v58 += 40i64;
        --v53;
      }
      while ( v53 );
      goto LABEL_98;
    case 1:
      v38 = 11i64;
      v2 = 11;
      v100 = 0;
      caption = "$PAUSE_UPGRADES_TRIAD_HEADER";
      v39 = UFG::qStringHashUpper32("PAUSE_UPGRADES_TRIAD_HEADER", 0xFFFFFFFF);
      v40 = UFG::UIScreenManager::s_instance->m_translator;
      if ( !v40 || (v1 = (char *)v40->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v40->vfptr, v39)) == 0i64 )
        v1 = "PAUSE_UPGRADES_TRIAD_HEADER";
      v41 = UFG::qStringHashUpper32("PAUSE_TRIAD_LEVEL_UPPERCASE", 0xFFFFFFFF);
      v42 = UFG::UIScreenManager::s_instance->m_translator;
      if ( v42 )
        v42->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v42->vfptr, v41);
      v43 = 0i64;
      v44 = 1;
      do
      {
        UFG::qString::Format((UFG::qString *)&ptr[v43], "$PAUSE_TRIAD_LEVEL_HEADER_%d", v44);
        v45 = (&str)[v43 / 8];
        if ( v45 )
        {
          if ( *v45 == 36 )
            ++v45;
          v47 = UFG::qStringHashUpper32(v45, 0xFFFFFFFF);
          v48 = UFG::UIScreenManager::s_instance->m_translator;
          if ( !v48
            || (v46 = (const char *)v48->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v48->vfptr, v47)) == 0i64 )
          {
            v46 = v45;
          }
        }
        else
        {
          v46 = 0i64;
        }
        UFG::qString::Set((UFG::qString *)&ptr[v43], v46);
        UFG::qString::Format((UFG::qString *)&v95[v43], "$PAUSE_TRIAD_LEVEL_INFO_%d", v44);
        v49 = (&v96)[v43 / 8];
        if ( v49 )
        {
          if ( *v49 == 36 )
            ++v49;
          v51 = UFG::qStringHashUpper32(v49, 0xFFFFFFFF);
          v52 = UFG::UIScreenManager::s_instance->m_translator;
          if ( !v52
            || (v50 = (const char *)v52->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v52->vfptr, v51)) == 0i64 )
          {
            v50 = v49;
          }
        }
        else
        {
          v50 = 0i64;
        }
        UFG::qString::Set((UFG::qString *)&v95[v43], v50);
        ++v44;
        v43 += 40i64;
        --v38;
      }
      while ( v38 );
      goto LABEL_98;
    case 2:
      v2 = 12;
      v100 = 0;
      caption = "$PAUSE_UPGRADES_MELEE_HEADER";
      v23 = UFG::qStringHashUpper32("PAUSE_UPGRADES_MELEE_HEADER", 0xFFFFFFFF);
      v24 = UFG::UIScreenManager::s_instance->m_translator;
      if ( !v24 || (v1 = (char *)v24->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v24->vfptr, v23)) == 0i64 )
        v1 = "PAUSE_UPGRADES_MELEE_HEADER";
      v25 = UFG::qStringHashUpper32("PAUSE_MELEE_LEVEL_UPPERCASE", 0xFFFFFFFF);
      v26 = UFG::UIScreenManager::s_instance->m_translator;
      if ( v26 )
        v26->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v26->vfptr, v25);
      v27 = 0i64;
      v28 = 1;
      v29 = 12i64;
      do
      {
        UFG::qString::Format((UFG::qString *)&ptr[v27], "$PAUSE_MELEE_LEVEL_HEADER_%d", v28);
        v30 = (&str)[v27 / 8];
        if ( v30 )
        {
          if ( *v30 == 36 )
            ++v30;
          v32 = UFG::qStringHashUpper32(v30, 0xFFFFFFFF);
          v33 = UFG::UIScreenManager::s_instance->m_translator;
          if ( !v33
            || (v31 = (const char *)v33->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v33->vfptr, v32)) == 0i64 )
          {
            v31 = v30;
          }
        }
        else
        {
          v31 = 0i64;
        }
        UFG::qString::Set((UFG::qString *)&ptr[v27], v31);
        UFG::qString::Format((UFG::qString *)&v95[v27], "$PAUSE_MELEE_LEVEL_INFO_%d", v28);
        v34 = (&v96)[v27 / 8];
        if ( v34 )
        {
          if ( *v34 == 36 )
            ++v34;
          v36 = UFG::qStringHashUpper32(v34, 0xFFFFFFFF);
          v37 = UFG::UIScreenManager::s_instance->m_translator;
          if ( !v37
            || (v35 = (const char *)v37->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v37->vfptr, v36)) == 0i64 )
          {
            v35 = v34;
          }
        }
        else
        {
          v35 = 0i64;
        }
        UFG::qString::Set((UFG::qString *)&v95[v27], v35);
        ++v28;
        v27 += 40i64;
        --v29;
      }
      while ( v29 );
LABEL_98:
      v3 = v100;
      break;
    case 3:
      v2 = 10;
      caption = "$PAUSE_UPGRADES_FACE_HEADER";
      v8 = UFG::qStringHashUpper32("PAUSE_UPGRADES_FACE_HEADER", 0xFFFFFFFF);
      v9 = UFG::UIScreenManager::s_instance->m_translator;
      if ( !v9 || (v1 = (char *)v9->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v9->vfptr, v8)) == 0i64 )
        v1 = "PAUSE_UPGRADES_FACE_HEADER";
      v10 = UFG::qStringHashUpper32("PAUSE_FACE_LEVEL_UPPERCASE", 0xFFFFFFFF);
      v11 = UFG::UIScreenManager::s_instance->m_translator;
      if ( v11 )
        v11->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v11->vfptr, v10);
      v12 = 0i64;
      v13 = 1;
      v14 = 10i64;
      do
      {
        UFG::qString::Format((UFG::qString *)&ptr[v12], "$PAUSE_FACE_LEVEL_HEADER_%d", v13);
        v15 = (&str)[v12 / 8];
        if ( v15 )
        {
          if ( *v15 == 36 )
            ++v15;
          v17 = UFG::qStringHashUpper32(v15, 0xFFFFFFFF);
          v18 = UFG::UIScreenManager::s_instance->m_translator;
          if ( !v18
            || (v16 = (const char *)v18->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v18->vfptr, v17)) == 0i64 )
          {
            v16 = v15;
          }
        }
        else
        {
          v16 = 0i64;
        }
        UFG::qString::Set((UFG::qString *)&ptr[v12], v16);
        UFG::qString::Format((UFG::qString *)&v95[v12], "$PAUSE_FACE_LEVEL_INFO_%d", v13);
        v19 = (&v96)[v12 / 8];
        if ( v19 )
        {
          if ( *v19 == 36 )
            ++v19;
          v21 = UFG::qStringHashUpper32(v19, 0xFFFFFFFF);
          v22 = UFG::UIScreenManager::s_instance->m_translator;
          if ( !v22
            || (v20 = (const char *)v22->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v22->vfptr, v21)) == 0i64 )
          {
            v20 = v19;
          }
        }
        else
        {
          v20 = 0i64;
        }
        UFG::qString::Set((UFG::qString *)&v95[v12], v20);
        ++v13;
        v12 += 40i64;
        --v14;
      }
      while ( v14 );
      v3 = 1;
      break;
    case 4:
      caption = "$PAUSE_UPGRADES_HEALTH_HEADER";
      v4 = (unsigned int)UFG::qStringHashUpper32("PAUSE_UPGRADES_HEALTH_HEADER", 0xFFFFFFFF);
      v5 = UFG::UIScreenManager::s_instance->m_translator;
      if ( !v5 || (v1 = (char *)v5->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v5->vfptr, v4)) == 0i64 )
        v1 = "PAUSE_UPGRADES_HEALTH_HEADER";
      v6 = UFG::qStringHashUpper32("PAUSE_HEALTH_LEVEL_UPPERCASE", 0xFFFFFFFF);
      v7 = UFG::UIScreenManager::s_instance->m_translator;
      if ( v7 )
        v7->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v7->vfptr, v6);
      break;
  }
  v68 = v99->mRenderable->m_movie.pObject;
  if ( v2 )
  {
    v69 = 1;
    v70 = 0i64;
    v71 = v2;
    do
    {
      UFG::qString::qString(&v90);
      UFG::qString::qString(&v94);
      if ( v3 )
      {
        UFG::qString::Format(&v90, "mc_linearScroller.mc_slot_%d.tf_header.htmlText", v69);
        v72 = "mc_linearScroller.mc_slot_%d.tf_body.htmlText";
      }
      else
      {
        UFG::qString::Format(&v90, "mc_branchingScroller.mc_slot_%d.tf_header.htmlText", v69);
        v72 = "mc_branchingScroller.mc_slot_%d.tf_body.htmlText";
      }
      UFG::qString::Format(&v94, v72, v69);
      v73 = (&str)[v70];
      value.pObjectInterface = 0i64;
      value.Type = 6;
      *(_QWORD *)&value.mValue.NValue = v73;
      Scaleform::GFx::Movie::SetVariable(v68, v90.mData, &value, 1i64);
      if ( ((unsigned int)value.Type >> 6) & 1 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
          value.pObjectInterface,
          &value,
          *(_QWORD *)&value.mValue.NValue);
        value.pObjectInterface = 0i64;
      }
      value.Type = 0;
      v74 = (&v96)[v70];
      v91.pObjectInterface = 0i64;
      v91.Type = 6;
      *(_QWORD *)&v91.mValue.NValue = v74;
      Scaleform::GFx::Movie::SetVariable(v68, v94.mData, &v91, 1i64);
      if ( ((unsigned int)v91.Type >> 6) & 1 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&v91.pObjectInterface->vfptr->gap8[8])(
          v91.pObjectInterface,
          &v91,
          *(_QWORD *)&v91.mValue.NValue);
        v91.pObjectInterface = 0i64;
      }
      v91.Type = 0;
      UFG::qString::~qString(&v94);
      UFG::qString::~qString(&v90);
      ++v69;
      v70 += 5i64;
      --v71;
    }
    while ( v71 );
  }
  UFG::UIHKScreenUpgrades::Flash_SetSelectedTab(v99, caption);
  iExpTowardsNextLevel = 0;
  iDiffBetweenLevels = 100;
  if ( UFG::UIHKScreenUpgrades::mUpgradesType == UPGRADES_TYPE_POLICE )
  {
    v85 = UFG::GameStatTracker::Instance();
    v81 = UFG::GameStatTracker::GetStat(v85, CopXP);
    v86 = UFG::GameStatTracker::Instance();
    v78 = UFG::GameStatTracker::GetXPLevel(v86, 0, v81);
    v83 = UFG::GameStatTracker::Instance();
    v84 = 0;
    goto LABEL_115;
  }
  if ( UFG::UIHKScreenUpgrades::mUpgradesType == 1 )
  {
    v80 = UFG::GameStatTracker::Instance();
    v81 = UFG::GameStatTracker::GetStat(v80, TriadXP);
    v82 = UFG::GameStatTracker::Instance();
    v78 = UFG::GameStatTracker::GetXPLevel(v82, ThresholdType_Triad, v81);
    v83 = UFG::GameStatTracker::Instance();
    v84 = 1;
LABEL_115:
    iExpTowardsNextLevel = UFG::GameStatTracker::GetPercentageToNextXPLevel(v83, v84, v81);
    goto LABEL_116;
  }
  if ( UFG::UIHKScreenUpgrades::mUpgradesType != UPGRADES_TYPE_FACE )
    goto LABEL_123;
  v75 = UFG::GameStatTracker::Instance();
  v76 = UFG::GameStatTracker::GetStat(v75, Standing);
  v77 = UFG::GameStatTracker::Instance();
  v78 = UFG::GameStatTracker::GetFaceLevelFromExperience(v77, v76);
  v79 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::GetPointsSinceLastLevel(v79, Standing, &iExpTowardsNextLevel, &iDiffBetweenLevels);
LABEL_116:
  *(_QWORD *)&v90.mMagic = 0i64;
  LODWORD(v90.mData) = 5;
  *(double *)&v90.mStringHash32 = (double)v78;
  Scaleform::GFx::Movie::SetVariable(v68, "gCurrentLevel", (Scaleform::GFx::Value *)&v90, 1i64);
  v87 = (double)(signed int)iExpTowardsNextLevel;
  if ( (LODWORD(v90.mData) >> 6) & 1 )
  {
    (*(void (__fastcall **)(_QWORD, UFG::qString *, _QWORD))(**(_QWORD **)&v90.mMagic + 16i64))(
      *(_QWORD *)&v90.mMagic,
      &v90,
      *(_QWORD *)&v90.mStringHash32);
    *(_QWORD *)&v90.mMagic = 0i64;
  }
  LODWORD(v90.mData) = 5;
  *(double *)&v90.mStringHash32 = v87;
  Scaleform::GFx::Movie::SetVariable(v68, "gExpTowardsNextLevel", (Scaleform::GFx::Value *)&v90, 1i64);
  v88 = (double)(signed int)iDiffBetweenLevels;
  if ( (LODWORD(v90.mData) >> 6) & 1 )
  {
    (*(void (__fastcall **)(_QWORD, UFG::qString *, _QWORD))(**(_QWORD **)&v90.mMagic + 16i64))(
      *(_QWORD *)&v90.mMagic,
      &v90,
      *(_QWORD *)&v90.mStringHash32);
    *(_QWORD *)&v90.mMagic = 0i64;
  }
  LODWORD(v90.mData) = 5;
  *(double *)&v90.mStringHash32 = v88;
  Scaleform::GFx::Movie::SetVariable(v68, "gDiffBetweenLevels", (Scaleform::GFx::Value *)&v90, 1i64);
  if ( (LODWORD(v90.mData) >> 6) & 1 )
  {
    (*(void (__fastcall **)(_QWORD, UFG::qString *, _QWORD))(**(_QWORD **)&v90.mMagic + 16i64))(
      *(_QWORD *)&v90.mMagic,
      &v90,
      *(_QWORD *)&v90.mStringHash32);
    *(_QWORD *)&v90.mMagic = 0i64;
  }
  LODWORD(v90.mData) = 0;
LABEL_123:
  v91.pObjectInterface = 0i64;
  v91.Type = 6;
  *(_QWORD *)&v91.mValue.NValue = v1;
  Scaleform::GFx::Movie::SetVariable(v68, "mc_header.tf_header.htmlText", &v91, 1i64);
  if ( ((unsigned int)v91.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&v91.pObjectInterface->vfptr->gap8[8])(
      v91.pObjectInterface,
      &v91,
      *(_QWORD *)&v91.mValue.NValue);
    v91.pObjectInterface = 0i64;
  }
  v91.Type = 0;
  `eh vector destructor iterator'(v95, 0x28ui64, 12, (void (__fastcall *)(void *))UFG::qString::~qString);
  `eh vector destructor iterator'(ptr, 0x28ui64, 12, (void (__fastcall *)(void *))UFG::qString::~qString);
}

// File Line: 987
// RVA: 0x5DD010
void __fastcall UFG::UIHKScreenUpgrades::Flash_Init(UFG::UIHKScreenUpgrades *this)
{
  UFG::UIHKScreenUpgrades *v1; // rsi
  Scaleform::GFx::Movie *v2; // rbx
  UFG::GameStatTracker *v3; // rax
  char v4; // di
  double v5; // xmm6_8
  double v6; // xmm6_8
  signed int v7; // edi
  signed int v8; // esi
  bool v9; // di
  UFG::GameStatTracker *v10; // rax
  signed int v11; // edi
  UFG::GameStatTracker *v12; // rax
  unsigned int v13; // esi
  unsigned int v14; // eax
  UFG::UIGfxTranslator *v15; // rcx
  const char *v16; // rax
  unsigned int v17; // eax
  UFG::UIGfxTranslator *v18; // rcx
  char *v19; // rdi
  unsigned int v20; // eax
  UFG::UIGfxTranslator *v21; // rcx
  const char *v22; // rax
  char *v23; // rdi
  const char *v24; // rax
  UFG::GameStatTracker *v25; // rax
  int v26; // edi
  UFG::GameStatTracker *v27; // rax
  int v28; // edi
  UFG::GameStatTracker *v29; // rax
  signed int v30; // edi
  UFG::GameStatTracker *v31; // rax
  int v32; // edi
  UFG::GameStatTracker *v33; // rax
  int v34; // edi
  UFG::GameStatTracker *v35; // rax
  signed int v36; // edi
  UFG::GameStatTracker *v37; // rax
  signed int v38; // edi
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-49h]
  char ptr; // [rsp+58h] [rbp-19h]
  __int64 v41; // [rsp+68h] [rbp-9h]
  unsigned int v42; // [rsp+70h] [rbp-1h]
  const char *v43; // [rsp+78h] [rbp+7h]
  UFG::qString v44; // [rsp+88h] [rbp+17h]
  __int64 v45; // [rsp+B0h] [rbp+3Fh]

  v45 = -2i64;
  v1 = this;
  v2 = this->mRenderable->m_movie.pObject;
  value.pObjectInterface = 0i64;
  value.Type = 5;
  value.mValue.NValue = (double)UFG::UIHKScreenUpgrades::GetUpgradePointsAvailable(UFG::UIHKScreenUpgrades::mUpgradesType);
  Scaleform::GFx::Movie::SetVariable(v2, "gUpgradePoints", &value, 1i64);
  if ( (signed int)UFG::UIHKScreenUpgrades::mUpgradesType >= 0 )
  {
    if ( (signed int)UFG::UIHKScreenUpgrades::mUpgradesType <= 1 )
    {
      v4 = 1;
      goto LABEL_7;
    }
    if ( UFG::UIHKScreenUpgrades::mUpgradesType == 2 )
    {
      v3 = UFG::GameStatTracker::Instance();
      v4 = (signed int)UFG::GameStatTracker::GetStat(v3, StatueOffensiveStage) > 0;
      goto LABEL_7;
    }
  }
  v4 = 0;
LABEL_7:
  if ( ((unsigned int)value.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
      value.pObjectInterface,
      &value,
      *(_QWORD *)&value.mValue.NValue);
    value.pObjectInterface = 0i64;
  }
  value.Type = 2;
  value.mValue.BValue = v4;
  Scaleform::GFx::Movie::SetVariable(v2, "gBranchingFirstSlot", &value, 1i64);
  v5 = (double)UFG::UIHKScreenUpgrades::GetUpperTrackLevel(v1);
  if ( ((unsigned int)value.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
      value.pObjectInterface,
      &value,
      *(_QWORD *)&value.mValue.NValue);
    value.pObjectInterface = 0i64;
  }
  value.Type = 5;
  value.mValue.NValue = v5;
  Scaleform::GFx::Movie::SetVariable(v2, "gUpperTrackLevel", &value, 1i64);
  v6 = (double)UFG::UIHKScreenUpgrades::GetLowerTrackLevel(v1);
  if ( ((unsigned int)value.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
      value.pObjectInterface,
      &value,
      *(_QWORD *)&value.mValue.NValue);
    value.pObjectInterface = 0i64;
  }
  value.Type = 5;
  value.mValue.NValue = v6;
  Scaleform::GFx::Movie::SetVariable(v2, "gLowerTrackLevel", &value, 1i64);
  v7 = 10;
  if ( UFG::UIHKScreenUpgrades::mUpgradesType && UFG::UIHKScreenUpgrades::mUpgradesType != 1 )
  {
    if ( UFG::UIHKScreenUpgrades::mUpgradesType == 2 )
    {
      v8 = 6;
    }
    else if ( UFG::UIHKScreenUpgrades::mUpgradesType == 3 )
    {
      v8 = 10;
    }
    else
    {
      v8 = 0;
    }
  }
  else
  {
    v8 = 5;
  }
  if ( ((unsigned int)value.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
      value.pObjectInterface,
      &value,
      *(_QWORD *)&value.mValue.NValue);
    value.pObjectInterface = 0i64;
  }
  value.Type = 5;
  value.mValue.NValue = (double)v8;
  Scaleform::GFx::Movie::SetVariable(v2, "gMaxUpperTrackLevel", &value, 1i64);
  if ( UFG::UIHKScreenUpgrades::mUpgradesType
    && UFG::UIHKScreenUpgrades::mUpgradesType != 1
    && UFG::UIHKScreenUpgrades::mUpgradesType != 2 )
  {
    if ( UFG::UIHKScreenUpgrades::mUpgradesType != 3 )
      v7 = 0;
  }
  else
  {
    v7 = 5;
  }
  if ( ((unsigned int)value.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
      value.pObjectInterface,
      &value,
      *(_QWORD *)&value.mValue.NValue);
    value.pObjectInterface = 0i64;
  }
  value.Type = 5;
  value.mValue.NValue = (double)v7;
  Scaleform::GFx::Movie::SetVariable(v2, "gMaxLowerTrackLevel", &value, 1i64);
  v9 = UFG::UIHKScreenUpgrades::mMode == 1;
  if ( ((unsigned int)value.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
      value.pObjectInterface,
      &value,
      *(_QWORD *)&value.mValue.NValue);
    value.pObjectInterface = 0i64;
  }
  value.Type = 2;
  value.mValue.BValue = v9;
  Scaleform::GFx::Movie::SetVariable(v2, "gIsModal", &value, 1i64);
  if ( UFG::UIHKScreenUpgrades::mUpgradesType == 4 )
  {
    v10 = UFG::GameStatTracker::Instance();
    v11 = UFG::GameStatTracker::GetNumHealthShrinesCollected(v10);
    v12 = UFG::GameStatTracker::Instance();
    v13 = 10 * (unsigned __int64)UFG::GameStatTracker::GetHealthLevel(v12);
    if ( ((unsigned int)value.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        *(_QWORD *)&value.mValue.NValue);
      value.pObjectInterface = 0i64;
    }
    value.Type = 5;
    value.mValue.NValue = (double)v11;
    Scaleform::GFx::Movie::SetVariable(v2, "gShrinesFound", &value, 1i64);
    UFG::qString::qString(&v44);
    if ( v11 == 1 )
    {
      v14 = UFG::qStringHashUpper32("UPGRADES_HEALTH_SHRINE_FOUND", 0xFFFFFFFF);
      v15 = UFG::UIScreenManager::s_instance->m_translator;
      if ( !v15
        || (v16 = (const char *)v15->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v15->vfptr, v14)) == 0i64 )
      {
        v16 = "UPGRADES_HEALTH_SHRINE_FOUND";
      }
    }
    else
    {
      v17 = UFG::qStringHashUpper32("UPGRADES_HEALTH_SHRINES_FOUND", 0xFFFFFFFF);
      v18 = UFG::UIScreenManager::s_instance->m_translator;
      if ( !v18
        || (v16 = (const char *)v18->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v18->vfptr, v17)) == 0i64 )
      {
        v16 = "UPGRADES_HEALTH_SHRINES_FOUND";
      }
    }
    UFG::qString::Format(&v44, v16, (unsigned int)v11);
    v19 = v44.mData;
    if ( ((unsigned int)value.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        *(_QWORD *)&value.mValue.NValue);
      value.pObjectInterface = 0i64;
    }
    value.Type = 6;
    *(_QWORD *)&value.mValue.NValue = v19;
    Scaleform::GFx::Movie::SetVariable(v2, "mc_healthUpgradeDisplay.mc_info.tf_header.text", &value, 1i64);
    v20 = UFG::qStringHashUpper32("UPGRADES_PERCENT_HEALTH_GAINED", 0xFFFFFFFF);
    v21 = UFG::UIScreenManager::s_instance->m_translator;
    if ( !v21
      || (v22 = (const char *)v21->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v21->vfptr, v20)) == 0i64 )
    {
      v22 = "UPGRADES_PERCENT_HEALTH_GAINED";
    }
    UFG::qString::Format(&v44, v22, v13);
    v23 = v44.mData;
    if ( ((unsigned int)value.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        *(_QWORD *)&value.mValue.NValue);
      value.pObjectInterface = 0i64;
    }
    value.Type = 6;
    *(_QWORD *)&value.mValue.NValue = v23;
    Scaleform::GFx::Movie::SetVariable(v2, "mc_healthUpgradeDisplay.mc_info.tf_maxHealth.text", &value, 1i64);
    UFG::qString::~qString(&v44);
  }
  `eh vector constructor iterator'(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  if ( UFG::UIHKScreenUpgrades::mUpgradesType )
  {
    switch ( UFG::UIHKScreenUpgrades::mUpgradesType )
    {
      case 1:
        if ( (v42 >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v41 + 16i64))(v41, &ptr, v43);
          v41 = 0i64;
        }
        v24 = "triad";
        break;
      case 2:
        if ( (v42 >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v41 + 16i64))(v41, &ptr, v43);
          v41 = 0i64;
        }
        v24 = "melee";
        break;
      case 3:
        if ( (v42 >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v41 + 16i64))(v41, &ptr, v43);
          v41 = 0i64;
        }
        v24 = "face";
        break;
      case 4:
        if ( (v42 >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v41 + 16i64))(v41, &ptr, v43);
          v41 = 0i64;
        }
        v24 = "health";
        break;
      default:
        goto LABEL_72;
    }
  }
  else
  {
    if ( (v42 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v41 + 16i64))(v41, &ptr, v43);
      v41 = 0i64;
    }
    v24 = "police";
  }
  v42 = 6;
  v43 = v24;
LABEL_72:
  v25 = UFG::GameStatTracker::Instance();
  v26 = UFG::GameStatTracker::GetStat(v25, CopUpgradePoint);
  v27 = UFG::GameStatTracker::Instance();
  v28 = v26 - (unsigned __int64)UFG::GameStatTracker::GetStat(v27, CopShootingStage);
  v29 = UFG::GameStatTracker::Instance();
  v30 = v28 - (unsigned __int64)UFG::GameStatTracker::GetStat(v29, CopDrivingStage);
  if ( v30 < 0 )
    v30 = 0;
  if ( ((unsigned int)value.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
      value.pObjectInterface,
      &value,
      *(_QWORD *)&value.mValue.NValue);
    value.pObjectInterface = 0i64;
  }
  value.Type = 5;
  value.mValue.NValue = (double)v30;
  Scaleform::GFx::Movie::SetVariable(v2, "gPoliceUpgradePoints", &value, 1i64);
  v31 = UFG::GameStatTracker::Instance();
  v32 = UFG::GameStatTracker::GetStat(v31, TriadUpgradePoint);
  v33 = UFG::GameStatTracker::Instance();
  v34 = v32 - (unsigned __int64)UFG::GameStatTracker::GetStat(v33, TriadOffensiveStage);
  v35 = UFG::GameStatTracker::Instance();
  v36 = v34 - (unsigned __int64)UFG::GameStatTracker::GetStat(v35, TriadDefensiveStage);
  if ( v36 < 0 )
    v36 = 0;
  if ( ((unsigned int)value.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
      value.pObjectInterface,
      &value,
      *(_QWORD *)&value.mValue.NValue);
    value.pObjectInterface = 0i64;
  }
  value.Type = 5;
  value.mValue.NValue = (double)v36;
  Scaleform::GFx::Movie::SetVariable(v2, "gTriadUpgradePoints", &value, 1i64);
  v37 = UFG::GameStatTracker::Instance();
  v38 = UFG::GameStatTracker::GetStat(v37, StatueUpgradePoint);
  if ( v38 < 0 )
    v38 = 0;
  if ( ((unsigned int)value.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
      value.pObjectInterface,
      &value,
      *(_QWORD *)&value.mValue.NValue);
    value.pObjectInterface = 0i64;
  }
  value.Type = 5;
  value.mValue.NValue = (double)v38;
  Scaleform::GFx::Movie::SetVariable(v2, "gMeleeUpgradePoints", &value, 1i64);
  Scaleform::GFx::Movie::Invoke(v2, "Init", 0i64, (Scaleform::GFx::Value *)&ptr, 1u);
  `eh vector destructor iterator'(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  if ( ((unsigned int)value.Type >> 6) & 1 )
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
      value.pObjectInterface,
      &value,
      *(_QWORD *)&value.mValue.NValue);
}

// File Line: 1099
// RVA: 0x5DEAC0
void __fastcall UFG::UIHKScreenUpgrades::Flash_RefreshCursor(UFG::UIHKScreenUpgrades *this)
{
  UFG::UIHKScreenUpgrades *v1; // rbx
  Scaleform::GFx::Movie *v2; // rdi
  UFG::UIHKScreenUpgrades::eUpgradesType v3; // ecx
  double v4; // xmm6_8
  double v5; // xmm6_8
  bool v6; // bl
  char ptr; // [rsp+28h] [rbp-59h]
  __int64 v8; // [rsp+38h] [rbp-49h]
  unsigned int v9; // [rsp+40h] [rbp-41h]
  double v10; // [rsp+48h] [rbp-39h]
  char v11; // [rsp+58h] [rbp-29h]
  __int64 v12; // [rsp+68h] [rbp-19h]
  unsigned int v13; // [rsp+70h] [rbp-11h]
  double v14; // [rsp+78h] [rbp-9h]
  char v15; // [rsp+88h] [rbp+7h]
  __int64 v16; // [rsp+98h] [rbp+17h]
  unsigned int v17; // [rsp+A0h] [rbp+1Fh]
  __int64 v18; // [rsp+A8h] [rbp+27h]
  __int64 v19; // [rsp+B8h] [rbp+37h]

  v19 = -2i64;
  v1 = this;
  v2 = this->mRenderable->m_movie.pObject;
  `eh vector constructor iterator'(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  v3 = UFG::UIHKScreenUpgrades::mUpgradesType;
  v4 = (double)v1->mCursorXPos[UFG::UIHKScreenUpgrades::mUpgradesType];
  if ( (v9 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v8 + 16i64))(v8, &ptr, COERCE_DOUBLE(*(_QWORD *)&v10));
    v8 = 0i64;
    v3 = UFG::UIHKScreenUpgrades::mUpgradesType;
  }
  v9 = 5;
  v10 = v4;
  v5 = (double)v1->mCursorYPos[v3];
  if ( (v13 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v12 + 16i64))(
      v12,
      &v11,
      COERCE_DOUBLE(*(_QWORD *)&v14));
    v12 = 0i64;
    v3 = UFG::UIHKScreenUpgrades::mUpgradesType;
  }
  v13 = 5;
  v14 = v5;
  v6 = v1->mCanUpgrade && UFG::UIHKScreenUpgrades::IsUpgradable(v1, v1->mCursorXPos[v3], v1->mCursorYPos[v3]);
  if ( (v17 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v16 + 16i64))(v16, &v15, v18);
    v16 = 0i64;
  }
  v17 = 2;
  LOBYTE(v18) = v6;
  Scaleform::GFx::Movie::Invoke(v2, "SetCursorPos", 0i64, (Scaleform::GFx::Value *)&ptr, 3u);
  `eh vector destructor iterator'(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 1115
// RVA: 0x5DB770
void __fastcall UFG::UIHKScreenUpgrades::Flash_HandleUpgradeSelected(UFG::UIHKScreenUpgrades *this)
{
  UFG::UIHKScreenUpgrades *v1; // rbx
  Scaleform::GFx::Movie *v2; // rdi
  double v3; // xmm6_8
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-50h]

  v1 = this;
  v2 = this->mRenderable->m_movie.pObject;
  `eh vector constructor iterator'(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  v3 = (double)v1->mCursorYPos[UFG::UIHKScreenUpgrades::mUpgradesType];
  if ( ((unsigned int)pargs.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      *(_QWORD *)&pargs.mValue.NValue);
    pargs.pObjectInterface = 0i64;
  }
  pargs.Type = 5;
  pargs.mValue.NValue = v3;
  Scaleform::GFx::Movie::Invoke(v2, "HandleUpgradeSelected", 0i64, &pargs, 1u);
  `eh vector destructor iterator'(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 1127
// RVA: 0x5E0B70
void __fastcall UFG::UIHKScreenUpgrades::Flash_SetSelectedTab(UFG::UIHKScreenUpgrades *this, const char *caption)
{
  const char *v2; // rbx
  Scaleform::GFx::Movie *v3; // rdi
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h]

  v2 = caption;
  v3 = this->mRenderable->m_movie.pObject;
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
  Scaleform::GFx::Movie::Invoke(v3, "TabMenuWidgetList_JumpToItem", 0i64, &pargs, 1u);
  `eh vector destructor iterator'(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 1183
// RVA: 0x5DAAD0
__int64 __fastcall UFG::UIHKScreenUpgrades::Flash_GetMouseNewTab(UFG::UIHKScreenUpgrades *this)
{
  Scaleform::GFx::Movie *v1; // rcx
  unsigned int v3; // ebx
  Scaleform::GFx::Value pval; // [rsp+28h] [rbp-40h]

  v1 = this->mRenderable->m_movie.pObject;
  if ( !v1 )
    return 0i64;
  pval.pObjectInterface = 0i64;
  pval.Type = 0;
  Scaleform::GFx::Movie::GetVariable(v1, &pval, "gMouseNewTab");
  v3 = (signed int)pval.mValue.NValue;
  if ( ((unsigned int)pval.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pval.pObjectInterface->vfptr->gap8[8])(
      pval.pObjectInterface,
      &pval,
      *(_QWORD *)&pval.mValue.NValue);
    pval.pObjectInterface = 0i64;
  }
  return v3;
}

// File Line: 1196
// RVA: 0x604970
void __fastcall UFG::UIHKScreenUpgrades::SendTelemetryData(UFG::UIHKScreenUpgrades *this, UFG::UIHKScreenUpgrades::eUpgradesType type, UFG::GameStat::Int32Stat itemHash32)
{
  UFG::GameStat::Int32Stat v3; // ebp
  UFG::UIHKScreenUpgrades::eUpgradesType v4; // ebx
  UFG::OSuiteDBLogger *v5; // rsi
  int v6; // ebx
  const char *v7; // rdx
  char *v8; // rcx
  int v9; // ebx
  UFG::GameStatTracker *v10; // rax
  int v11; // edi
  int v12; // ebx
  UFG::qSymbol result; // [rsp+20h] [rbp-98h]
  char v14; // [rsp+24h] [rbp-94h]
  char dest; // [rsp+30h] [rbp-88h]
  char v16; // [rsp+D8h] [rbp+20h]

  v3 = itemHash32;
  v4 = type;
  v5 = UFG::OSuiteDBLogger::Instance();
  if ( UFG::OSuiteDBLogger::CreateMetric(v5, "PlayerUpgrade") )
  {
    if ( v4 )
    {
      v6 = v4 - 1;
      if ( v6 )
      {
        if ( v6 != 1 )
          return;
        v7 = "Melee";
        v8 = &v16;
      }
      else
      {
        v7 = "Triad";
        v8 = &v14;
      }
    }
    else
    {
      v7 = "Cop";
      v8 = (char *)&result;
    }
    v9 = UFG::qSymbol::create_from_string((UFG::qSymbol *)v8, v7)->mUID;
    UFG::qSPrintf(&dest, 128, "i32_%s", "Type");
    OSuite::ZMetric::SetProperty(v5->m_pMetric, &dest, v9);
    v10 = UFG::GameStatTracker::Instance();
    v11 = UFG::GameStatTracker::GetStat(v10, v3);
    v12 = UFG::GameStat::GetSymbol(v3)->mUID;
    UFG::qSPrintf(&dest, 128, "i32_%s", "StageType");
    OSuite::ZMetric::SetProperty(v5->m_pMetric, &dest, v12);
    UFG::qSPrintf(&dest, 128, "i32_%s", "StageLevel");
    OSuite::ZMetric::SetProperty(v5->m_pMetric, &dest, v11);
    UFG::OSuiteDBLogger::SubmitMetric(v5, 1);
  }
}

