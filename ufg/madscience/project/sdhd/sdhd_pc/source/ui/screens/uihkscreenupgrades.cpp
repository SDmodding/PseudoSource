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
  int *mCursorYPos; // rax
  __int64 v2; // rdx

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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenUpgrades::`vftable;
  *(_WORD *)&this->mCanUpgrade = 0;
  this->mIsKeyboardController = 0;
  this->mState = STATE_INVALID;
  mCursorYPos = this->mCursorYPos;
  v2 = 5i64;
  do
  {
    mCursorYPos[5] = 0;
    *mCursorYPos++ = 1;
    --v2;
  }
  while ( v2 );
}

// File Line: 66
// RVA: 0x5CCE70
void __fastcall UFG::UIHKScreenUpgrades::~UIHKScreenUpgrades(UFG::UIHKScreenUpgrades *this)
{
  UFG::UIHKScreenGlobalOverlay *v2; // rax
  UFG::UIScreenTextureManager *v3; // rax
  UFG::UI *v4; // rcx
  UFG::UIScreenTextureManager *v5; // rax
  UFG::UI *v6; // rcx
  unsigned int v7; // eax

  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenUpgrades::`vftable;
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
  UFG::UIHKScreenUpgrades::mMode = MODE_NORMAL;
  if ( this->mUnpauseOnExit )
    UFG::UI::UnpauseGame(v6);
  UFG::UIScreen::~UIScreen(this);
}

// File Line: 101
// RVA: 0x636D50
void __fastcall UFG::UIHKScreenUpgrades::init(UFG::UIHKScreenUpgrades *this, UFG::UICommandData *data)
{
  UFG::Controller *v4; // rcx
  bool v5; // al

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
    this->mUnpauseOnExit = 1;
    UFG::UI::PauseGame(0i64);
  }
  UFG::UIScreen::init(this, data);
  v5 = (int)UFG::UIHKScreenUpgrades::GetUpgradePointsAvailable(UFG::UIHKScreenUpgrades::mUpgradesType) > 0
    && UFG::UIHKScreenUpgrades::mUpgradesType != UPGRADES_TYPE_MELEE
    || UFG::UIHKScreenUpgrades::mMode == MODE_MODAL;
  this->mCanUpgrade = v5;
  UFG::UIHKScreenUpgrades::Flash_InitText(this);
  UFG::UIHKScreenUpgrades::Flash_Init(this);
  UFG::UIHKScreenUpgrades::PopulateHelpBar(this);
  UFG::UIHKScreenUpgrades::Flash_RefreshCursor(this);
  ((void (__fastcall *)(UFG::TiDo *, __int64))UFG::TiDo::m_pInstance->vfptr[1].Close)(UFG::TiDo::m_pInstance, 1i64);
  if ( UFG::UIHKScreenGlobalOverlay::mThis
    && UFG::UIHKScreenGlobalOverlay::mThis != (UFG::UIHKScreenGlobalOverlay *)-408i64 )
  {
    UFG::UIHK_NISOverlay::HideElement(
      &UFG::UIHKScreenGlobalOverlay::mThis->NISOverlay,
      UFG::UIHKScreenGlobalOverlay::mThis,
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
  int v1; // ecx
  UFG::GameStatTracker *v2; // rax
  int Stat; // ebx
  UFG::GameStatTracker *v5; // rax
  int v6; // ebx
  UFG::GameStatTracker *v7; // rax
  int v8; // ebx
  UFG::GameStatTracker *v9; // rax
  UFG::GameStat::Int32Stat v10; // edx
  UFG::GameStatTracker *v11; // rax
  int v12; // ebx
  UFG::GameStatTracker *v13; // rax
  int v14; // ebx

  if ( type )
  {
    v1 = type - 1;
    if ( v1 )
    {
      if ( v1 != 1 )
        return 0i64;
      v2 = UFG::GameStatTracker::Instance();
      Stat = UFG::GameStatTracker::GetStat(v2, StatueUpgradePoint);
      if ( Stat < 0 )
        return 0;
      return (unsigned int)Stat;
    }
    v5 = UFG::GameStatTracker::Instance();
    v6 = UFG::GameStatTracker::GetStat(v5, TriadUpgradePoint);
    v7 = UFG::GameStatTracker::Instance();
    v8 = v6 - UFG::GameStatTracker::GetStat(v7, TriadOffensiveStage);
    v9 = UFG::GameStatTracker::Instance();
    v10 = TriadDefensiveStage;
  }
  else
  {
    v11 = UFG::GameStatTracker::Instance();
    v12 = UFG::GameStatTracker::GetStat(v11, CopUpgradePoint);
    v13 = UFG::GameStatTracker::Instance();
    v8 = v12 - UFG::GameStatTracker::GetStat(v13, CopShootingStage);
    v9 = UFG::GameStatTracker::Instance();
    v10 = CopDrivingStage;
  }
  v14 = v8 - UFG::GameStatTracker::GetStat(v9, v10);
  if ( v14 < 0 )
    return 0;
  return (unsigned int)v14;
}

// File Line: 156
// RVA: 0x5F49A0
void __fastcall UFG::UIHKScreenUpgrades::Populate(UFG::UIHKScreenUpgrades *this)
{
  bool v2; // al

  v2 = (int)UFG::UIHKScreenUpgrades::GetUpgradePointsAvailable(UFG::UIHKScreenUpgrades::mUpgradesType) > 0
    && UFG::UIHKScreenUpgrades::mUpgradesType != UPGRADES_TYPE_MELEE
    || UFG::UIHKScreenUpgrades::mMode == MODE_MODAL;
  this->mCanUpgrade = v2;
  UFG::UIHKScreenUpgrades::Flash_InitText(this);
  UFG::UIHKScreenUpgrades::Flash_Init(this);
  UFG::UIHKScreenUpgrades::PopulateHelpBar(this);
  UFG::UIHKScreenUpgrades::Flash_RefreshCursor(this);
}

// File Line: 172
// RVA: 0x5F7140
void __fastcall UFG::UIHKScreenUpgrades::PopulateHelpBar(UFG::UIHKScreenUpgrades *this)
{
  int v2; // esi
  unsigned int v3; // r14d
  int v4; // ecx
  __int64 v5; // rax
  __int64 v6; // rdi
  __int64 v7; // rbx
  unsigned int v8; // r14d
  int v9; // ecx
  __int64 v10; // rax
  __int64 v11; // rdi
  __int64 v12; // rbx
  unsigned int v13; // r14d
  int v14; // ecx
  __int64 v15; // rax
  __int64 v16; // rdi
  __int64 v17; // rbx
  unsigned int v18; // r14d
  __int64 v19; // rax
  __int64 v20; // rbx
  UFG::UIHKScreenGlobalOverlay *v21; // rax
  UFG::UIHKHelpBarData data; // [rsp+30h] [rbp-D0h] BYREF

  UFG::UIHKHelpBarData::UIHKHelpBarData(&data);
  data.id = gUpgradesHelpBarId;
  v2 = 0;
  data.alignment = ALIGN_LEFT;
  if ( this->mCanUpgrade
    && UFG::UIHKScreenUpgrades::IsUpgradable(
         this,
         this->mCursorXPos[UFG::UIHKScreenUpgrades::mUpgradesType],
         this->mCursorYPos[UFG::UIHKScreenUpgrades::mUpgradesType]) )
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
    data.Buttons[v6] = ACCEPT_BUTTON;
    v7 = v4;
    UFG::qString::Set(&data.Captions[v7], "$COMMON_ACCEPT_UPPERCASE");
    UFG::qString::Set(&data.Icons[v7], &customCaption);
    data.MessageIds[v6] = v3;
  }
LABEL_8:
  if ( UFG::UIHKScreenUpgrades::mMode != MODE_MODAL )
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
    data.Buttons[v11] = BACK_BUTTON;
    v12 = v9;
    UFG::qString::Set(&data.Captions[v12], "$COMMON_BACK_UPPERCASE");
    UFG::qString::Set(&data.Icons[v12], &customCaption);
    data.MessageIds[v11] = v8;
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
    data.Buttons[v16] = L1R1_BUTTON;
    v17 = v14;
    UFG::qString::Set(&data.Captions[v17], "$HELPBAR_CHANGE_SECTION_UC");
    UFG::qString::Set(&data.Icons[v17], &customCaption);
    data.MessageIds[v16] = v13;
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
  data.Buttons[v2] = SELECT_BUTTON;
  v20 = v2;
  UFG::qString::Set(&data.Captions[v20], "$BUTTON_REMAP_HELP");
  UFG::qString::Set(&data.Icons[v20], &customCaption);
  data.MessageIds[v2] = v18;
LABEL_24:
  v21 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    v21 = &gGlobalOverlaySentinel;
  UFG::UIHKHelpBarWidget::Show(&v21->HelpBar, &data);
  UFG::qString::~qString(&data.CustomTexturePack);
  `eh vector destructor iterator(data.Icons, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
  `eh vector destructor iterator(data.Captions, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
}

// File Line: 194
// RVA: 0x640450
void __fastcall UFG::UIHKScreenUpgrades::update(UFG::UIHKScreenUpgrades *this, float elapsed)
{
  bool m_IsKeyboardController; // al
  Scaleform::GFx::Movie *MovieSafe; // rax

  m_IsKeyboardController = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController;
  if ( m_IsKeyboardController != this->mIsKeyboardController )
  {
    this->mIsKeyboardController = m_IsKeyboardController;
    MovieSafe = UFG::UIScreen::getMovieSafe(this);
    if ( MovieSafe )
      Scaleform::GFx::Movie::Invoke(MovieSafe, "KeyboardControllerStatusChanged", 0i64, 0i64, 0);
  }
  UFG::UIScreen::update(this, elapsed);
}

// File Line: 213
// RVA: 0x62D5F0
bool __fastcall UFG::UIHKScreenUpgrades::handleMessage(
        UFG::UIHKScreenUpgrades *this,
        unsigned int msgId,
        UFG::UIMessage *msg)
{
  UFG::UIHKScreenUpgrades::eMode v3; // r9d
  UFG::HudAudio *v7; // rcx
  UFG::UIHKScreenUpgrades::eState mState; // edx
  __int32 v9; // edx
  __int32 v10; // edx
  UFG::UIScreen *Overlay; // rax
  UFG::UIHKScreenGlobalOverlay *v12; // rcx
  UFG::UIHKScreenUpgrades::eUpgradesType MouseNewTab; // eax

  v3 = UFG::UIHKScreenUpgrades::mMode;
  if ( !this->mCanUpgrade || UFG::UIHKScreenUpgrades::mMode != MODE_MODAL )
  {
    if ( msgId == UI_HASH_BUTTON_BACK_PRESSED_30 )
    {
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xA4E5BFBD, 0i64, 0, 0i64);
      UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, 0xFFFFFFFF);
      return 1;
    }
    if ( msgId == UI_HASH_BUTTON_ACCEPT_PRESSED_30 )
    {
      v7 = UFG::HudAudio::m_instance;
      if ( !UFG::HudAudio::m_instance )
        goto LABEL_11;
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xA4E5BFBD, 0i64, 0, 0i64);
      v3 = UFG::UIHKScreenUpgrades::mMode;
    }
  }
  v7 = UFG::HudAudio::m_instance;
LABEL_11:
  mState = this->mState;
  if ( mState == STATE_INVALID )
  {
    if ( msgId == UI_HASH_BUTTON_L1_PRESSED_30 )
    {
      if ( v3 != MODE_MODAL )
      {
        if ( v7 )
          UFG::AudioEntity::CreateAndPlayEvent(v7, 0xC415B16F, 0i64, 0, 0i64);
        UFG::UIHKScreenUpgrades::ScrollPrevTab(this);
      }
      return 1;
    }
    if ( msgId == UI_HASH_BUTTON_R1_PRESSED_30 )
    {
      if ( v3 != MODE_MODAL )
      {
        if ( v7 )
          UFG::AudioEntity::CreateAndPlayEvent(v7, 0xC415B16F, 0i64, 0, 0i64);
        UFG::UIHKScreenUpgrades::ScrollNextTab(this);
      }
      return 1;
    }
    if ( msgId == UI_HASH_BUTTON_SELECT_PRESSED_30 )
    {
      this->mState = STATE_DANGER;
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x5958830u, 0i64, 0, 0i64);
      if ( UFG::UIHKScreenUpgrades::mUpgradesType )
      {
        switch ( UFG::UIHKScreenUpgrades::mUpgradesType )
        {
          case UPGRADES_TYPE_TRIAD:
            UFG::UIScreenDialogBox::createOKDialog(this, &customCaption, "$PAUSE_UPGRADES_HELP_TRIAD", 0);
            break;
          case UPGRADES_TYPE_MELEE:
            UFG::UIScreenDialogBox::createOKDialog(this, &customCaption, "$PAUSE_UPGRADES_HELP_MELEE", 0);
            break;
          case UPGRADES_TYPE_FACE:
            UFG::UIScreenDialogBox::createOKDialog(this, &customCaption, "$PAUSE_UPGRADES_HELP_FACE", 0);
            break;
          case UPGRADES_TYPE_HEALTH:
            UFG::UIScreenDialogBox::createOKDialog(this, &customCaption, "$PAUSE_UPGRADES_HELP_HEALTH", 0);
            break;
        }
      }
      else
      {
        UFG::UIScreenDialogBox::createOKDialog(this, &customCaption, "$PAUSE_UPGRADES_HELP_POLICE", 0);
      }
    }
    else
    {
      if ( msgId == UI_HASH_BUTTON_ACCEPT_PRESSED_30 )
      {
        if ( this->mCanUpgrade
          && UFG::UIHKScreenUpgrades::IsUpgradable(
               this,
               this->mCursorXPos[UFG::UIHKScreenUpgrades::mUpgradesType],
               this->mCursorYPos[UFG::UIHKScreenUpgrades::mUpgradesType]) )
        {
          this->mState = STATE_NORMAL;
          if ( UFG::HudAudio::m_instance )
            UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xF41B2F0D, 0i64, 0, 0i64);
          UFG::UIScreenDialogBox::createYesNoDialog(this, &customCaption, "$DIALOG_CONFIRMATION_1", 1, 0);
        }
        return 1;
      }
      if ( msgId == UI_HASH_DPAD_UP_PRESSED_30 || msgId == UI_HASH_THUMBSTICK_LEFT_UP_30 )
      {
        if ( UFG::UIHKScreenUpgrades::mUpgradesType != UPGRADES_TYPE_FACE )
          UFG::UIHKScreenUpgrades::MoveCursorUp(this);
        return 1;
      }
      if ( msgId == UI_HASH_DPAD_DOWN_PRESSED_30 || msgId == UI_HASH_THUMBSTICK_LEFT_DOWN_30 )
      {
        if ( UFG::UIHKScreenUpgrades::mUpgradesType != UPGRADES_TYPE_FACE )
          UFG::UIHKScreenUpgrades::MoveCursorDown(this);
        return 1;
      }
      if ( msgId == UI_HASH_DPAD_LEFT_PRESSED_30 || msgId == UI_HASH_THUMBSTICK_LEFT_LEFT_30 )
      {
        UFG::UIHKScreenUpgrades::MoveCursorLeft(this);
        return 1;
      }
      if ( msgId == UI_HASH_DPAD_RIGHT_PRESSED_30 || msgId == UI_HASH_THUMBSTICK_LEFT_RIGHT_30 )
      {
        UFG::UIHKScreenUpgrades::MoveCursorRight(this);
        return 1;
      }
    }
    Overlay = UFG::UIScreenManagerBase::getOverlay(UFG::UIScreenManager::s_instance, "GlobalOverlay");
    if ( Overlay )
    {
      v12 = UFG::UIHKScreenGlobalOverlay::mThis;
      if ( !UFG::UIHKScreenGlobalOverlay::mThis )
        v12 = &gGlobalOverlaySentinel;
      UFG::UIHKHelpBarWidget::HandleMessage(&v12->HelpBar, Overlay, msgId, msg);
    }
    if ( msgId == UI_HASH_MOUSE_MOVE_30 )
    {
      UFG::UIHKScreenUpgrades::Flash_HandleMouseMove(this, (float)SLODWORD(msg[1].vfptr), (float)SHIDWORD(msg[1].vfptr));
      return UFG::UIScreen::handleMessage(this, msgId, msg);
    }
    if ( msgId == UI_HASH_MOUSE_BUTTON_LEFT_PRESSED_30 )
    {
      UFG::UIHKScreenSaveLoad::Flash_HandleMouseClick(
        this,
        (float)SLODWORD(msg[1].vfptr),
        (float)SHIDWORD(msg[1].vfptr));
      return UFG::UIScreen::handleMessage(this, msgId, msg);
    }
    if ( msgId == UI_HASH_MOUSE_CHANGE_TAB_20 )
    {
      if ( UFG::UIHKScreenUpgrades::mMode != MODE_MODAL )
      {
        MouseNewTab = (unsigned int)UFG::UIHKScreenUpgrades::Flash_GetMouseNewTab(this);
        UFG::UIHKScreenUpgrades::SetTab(this, MouseNewTab);
        return UFG::UIScreen::handleMessage(this, msgId, msg);
      }
    }
    else if ( msgId == UI_HASH_MOUSE_WHEEL_SCROLL_30 )
    {
      if ( SLODWORD(msg[1].mPrev) > 0 )
      {
        UFG::UIHKScreenUpgrades::MoveCursorPrev(this);
        return UFG::UIScreen::handleMessage(this, msgId, msg);
      }
      UFG::UIHKScreenUpgrades::MoveCursorNext(this);
    }
    return UFG::UIScreen::handleMessage(this, msgId, msg);
  }
  v9 = mState - 1;
  if ( v9 )
  {
    v10 = v9 - 1;
    if ( v10 )
    {
      if ( v10 == 1 && msgId == UI_HASH_WIDGET_ANIM_DONE_20 )
      {
        if ( v3 == MODE_MODAL )
        {
          UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, 0xFFFFFFFF);
          this->mState = STATE_INCOMPLETE;
        }
        else
        {
          UFG::UIHKScreenUpgrades::Populate(this);
          this->mState = STATE_INVALID;
        }
        return 1;
      }
      return UFG::UIScreen::handleMessage(this, msgId, msg);
    }
    if ( msgId != UI_HASH_DIALOG_OK_30 )
      return UFG::UIScreen::handleMessage(this, msgId, msg);
    this->mState = STATE_INVALID;
  }
  else
  {
    if ( msgId == UI_HASH_DIALOG_YES_30 )
    {
      this->mState = STATE_COMPLETE;
      UFG::UIHKScreenUpgrades::ApplyUpgrade(this);
      if ( UFG::HudAudio::m_instance )
      {
        UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x9C1F87EB, 0i64, 0, 0i64);
        if ( UFG::HudAudio::m_instance )
          UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x5BC35965u, 0i64, 0, 0i64);
      }
      return 1;
    }
    if ( msgId != UI_HASH_DIALOG_NO_30 )
      return UFG::UIScreen::handleMessage(this, msgId, msg);
    this->mState = STATE_INVALID;
  }
  return 1;
}

// File Line: 417
// RVA: 0x5D3EF0
void __fastcall UFG::UIHKScreenUpgrades::ApplyUpgrade(UFG::UIHKScreenUpgrades *this)
{
  UFG::GameStatTracker *v2; // rax
  UFG::GameStat::Int32Stat v3; // r8d
  UFG::GameStatTracker *v4; // rax
  UFG::GameStatTracker *v5; // rax
  UFG::GameStatTracker *v6; // rax
  UFG::GameStatTracker *v7; // rax
  UFG::GameStatTracker *v8; // rax

  UFG::UIHKScreenUpgrades::Flash_HandleUpgradeSelected(this);
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x9C1F87EB, 0i64, 0, 0i64);
  if ( UFG::UIHKScreenUpgrades::mUpgradesType )
  {
    if ( UFG::UIHKScreenUpgrades::mUpgradesType == UPGRADES_TYPE_TRIAD )
    {
      if ( this->mCursorYPos[1] <= 0 )
      {
        v6 = UFG::GameStatTracker::Instance();
        UFG::GameStatTracker::ApplyDelta(v6, TriadOffensiveStage, 1);
        v3 = TriadOffensiveStage;
      }
      else
      {
        v5 = UFG::GameStatTracker::Instance();
        UFG::GameStatTracker::ApplyDelta(v5, TriadDefensiveStage, 1);
        v3 = TriadDefensiveStage;
      }
    }
    else
    {
      if ( UFG::UIHKScreenUpgrades::mUpgradesType != UPGRADES_TYPE_MELEE )
        return;
      if ( this->mCursorYPos[2] <= 0 )
      {
        v4 = UFG::GameStatTracker::Instance();
        UFG::GameStatTracker::ApplyDelta(v4, StatueOffensiveStage, 1);
        v3 = StatueOffensiveStage;
      }
      else
      {
        v2 = UFG::GameStatTracker::Instance();
        UFG::GameStatTracker::ApplyDelta(v2, StatueDefensiveStage, 1);
        v3 = StatueDefensiveStage;
      }
    }
  }
  else if ( this->mCursorYPos[0] <= 0 )
  {
    v8 = UFG::GameStatTracker::Instance();
    UFG::GameStatTracker::ApplyDelta(v8, CopShootingStage, 1);
    v3 = CopShootingStage;
  }
  else
  {
    v7 = UFG::GameStatTracker::Instance();
    UFG::GameStatTracker::ApplyDelta(v7, CopDrivingStage, 1);
    v3 = CopDrivingStage;
  }
  UFG::UIHKScreenUpgrades::SendTelemetryData(this, UFG::UIHKScreenUpgrades::mUpgradesType, v3);
}

// File Line: 495
// RVA: 0x5E9A60
__int64 __fastcall UFG::UIHKScreenUpgrades::GetUpperTrackLevel(UFG::UIHKScreenUpgrades *this)
{
  UFG::GameStatTracker *v1; // rax
  UFG::GameStatTracker *v3; // rax
  UFG::GameStatTracker *v4; // rax
  UFG::GameStatTracker *v5; // rax
  UFG::GameStatTracker *v6; // rax

  if ( UFG::UIHKScreenUpgrades::mUpgradesType )
  {
    switch ( UFG::UIHKScreenUpgrades::mUpgradesType )
    {
      case UPGRADES_TYPE_TRIAD:
        v5 = UFG::GameStatTracker::Instance();
        return UFG::GameStatTracker::GetStat(v5, TriadOffensiveStage);
      case UPGRADES_TYPE_MELEE:
        v4 = UFG::GameStatTracker::Instance();
        return (unsigned int)UFG::GameStatTracker::GetStat(v4, StatueOffensiveStage) - 1;
      case UPGRADES_TYPE_FACE:
        v3 = UFG::GameStatTracker::Instance();
        return UFG::GameStatTracker::GetFaceLevel(v3);
      case UPGRADES_TYPE_HEALTH:
        v1 = UFG::GameStatTracker::Instance();
        return UFG::GameStatTracker::GetHealthLevel(v1);
      default:
        return 0i64;
    }
  }
  else
  {
    v6 = UFG::GameStatTracker::Instance();
    return UFG::GameStatTracker::GetStat(v6, CopShootingStage);
  }
}

// File Line: 547
// RVA: 0x5E8330
__int64 __fastcall UFG::UIHKScreenUpgrades::GetLowerTrackLevel(UFG::UIHKScreenUpgrades *this)
{
  UFG::GameStatTracker *v1; // rax
  UFG::GameStatTracker *v3; // rax
  UFG::GameStatTracker *v4; // rax
  UFG::GameStatTracker *v5; // rax

  if ( UFG::UIHKScreenUpgrades::mUpgradesType )
  {
    switch ( UFG::UIHKScreenUpgrades::mUpgradesType )
    {
      case UPGRADES_TYPE_TRIAD:
        v4 = UFG::GameStatTracker::Instance();
        return UFG::GameStatTracker::GetStat(v4, TriadDefensiveStage);
      case UPGRADES_TYPE_MELEE:
        v3 = UFG::GameStatTracker::Instance();
        return UFG::GameStatTracker::GetStat(v3, StatueDefensiveStage);
      case UPGRADES_TYPE_FACE:
        v1 = UFG::GameStatTracker::Instance();
        return UFG::GameStatTracker::GetFaceLevel(v1);
      default:
        return 0i64;
    }
  }
  else
  {
    v5 = UFG::GameStatTracker::Instance();
    return UFG::GameStatTracker::GetStat(v5, CopDrivingStage);
  }
}

// File Line: 584
// RVA: 0x5E83C0
__int64 __fastcall UFG::UIHKScreenUpgrades::GetMaxUpperTrackLevel(UFG::UIHKScreenUpgrades *this)
{
  if ( (unsigned int)UFG::UIHKScreenUpgrades::mUpgradesType < UPGRADES_TYPE_MELEE )
    return 5i64;
  if ( UFG::UIHKScreenUpgrades::mUpgradesType == UPGRADES_TYPE_MELEE )
    return 6i64;
  if ( UFG::UIHKScreenUpgrades::mUpgradesType == UPGRADES_TYPE_FACE )
    return 10i64;
  return 0i64;
}

// File Line: 627
// RVA: 0x5EE930
bool __fastcall UFG::UIHKScreenUpgrades::IsUpgradable(UFG::UIHKScreenUpgrades *this, int posX, int posY)
{
  bool v5; // bl
  int v6; // ebx
  bool result; // al

  if ( UFG::UIHKScreenUpgrades::mUpgradesType < UPGRADES_TYPE_POLICE )
    return 0;
  if ( UFG::UIHKScreenUpgrades::mUpgradesType <= UPGRADES_TYPE_TRIAD )
  {
    if ( posY )
      return (unsigned int)UFG::UIHKScreenUpgrades::GetLowerTrackLevel(this) + 1 == posX;
    else
      return (unsigned int)UFG::UIHKScreenUpgrades::GetUpperTrackLevel(this) + 1 == posX;
  }
  if ( UFG::UIHKScreenUpgrades::mUpgradesType != UPGRADES_TYPE_MELEE )
    return 0;
  if ( posY )
    return (unsigned int)UFG::UIHKScreenUpgrades::GetLowerTrackLevel(this) + 1 == posX;
  v5 = (unsigned int)UFG::UIHKScreenUpgrades::GetUpperTrackLevel(this) + 1 == posX;
  if ( posX != (unsigned int)UFG::UIHKScreenUpgrades::GetMaxUpperTrackLevel(this) )
    return v5;
  result = 0;
  if ( v5 )
  {
    if ( (unsigned int)UFG::UIHKScreenUpgrades::mUpgradesType < UPGRADES_TYPE_FACE )
      v6 = 5;
    else
      v6 = UFG::UIHKScreenUpgrades::mUpgradesType == UPGRADES_TYPE_FACE ? 10 : 0;
    if ( (unsigned int)UFG::UIHKScreenUpgrades::GetLowerTrackLevel(this) == v6 )
      return 1;
  }
  return result;
}

// File Line: 647
// RVA: 0x6041F0
void __fastcall UFG::UIHKScreenUpgrades::ScrollNextTab(UFG::UIHKScreenUpgrades *this)
{
  bool v2; // di
  __int32 v3; // ecx

  v2 = 0;
  v3 = UFG::UIHKScreenUpgrades::mUpgradesType + 1;
  if ( UFG::UIHKScreenUpgrades::mUpgradesType + 1 >= 5 )
    v3 = 0;
  UFG::UIHKScreenUpgrades::mUpgradesType = v3;
  if ( (int)UFG::UIHKScreenUpgrades::GetUpgradePointsAvailable((UFG::UIHKScreenUpgrades::eUpgradesType)v3) > 0
    && UFG::UIHKScreenUpgrades::mUpgradesType != UPGRADES_TYPE_MELEE
    || UFG::UIHKScreenUpgrades::mMode == MODE_MODAL )
  {
    v2 = 1;
  }
  this->mCanUpgrade = v2;
  UFG::UIHKScreenUpgrades::Flash_InitText(this);
  UFG::UIHKScreenUpgrades::Flash_Init(this);
  UFG::UIHKScreenUpgrades::PopulateHelpBar(this);
  UFG::UIHKScreenUpgrades::Flash_RefreshCursor(this);
}

// File Line: 660
// RVA: 0x6043C0
void __fastcall UFG::UIHKScreenUpgrades::ScrollPrevTab(UFG::UIHKScreenUpgrades *this)
{
  UFG::UIHKScreenUpgrades::eUpgradesType v2; // ecx
  bool v3; // al

  v2 = UFG::UIHKScreenUpgrades::mUpgradesType;
  if ( UFG::UIHKScreenUpgrades::mUpgradesType <= UPGRADES_TYPE_POLICE )
    v2 = NUM_UPGRADE_TYPES;
  UFG::UIHKScreenUpgrades::mUpgradesType = v2 - 1;
  v3 = (int)UFG::UIHKScreenUpgrades::GetUpgradePointsAvailable((UFG::UIHKScreenUpgrades::eUpgradesType)(v2 - 1)) > 0
    && UFG::UIHKScreenUpgrades::mUpgradesType != UPGRADES_TYPE_MELEE
    || UFG::UIHKScreenUpgrades::mMode == MODE_MODAL;
  this->mCanUpgrade = v3;
  UFG::UIHKScreenUpgrades::Flash_InitText(this);
  UFG::UIHKScreenUpgrades::Flash_Init(this);
  UFG::UIHKScreenUpgrades::PopulateHelpBar(this);
  UFG::UIHKScreenUpgrades::Flash_RefreshCursor(this);
}

// File Line: 673
// RVA: 0x609F90
void __fastcall UFG::UIHKScreenUpgrades::SetTab(
        UFG::UIHKScreenUpgrades *this,
        UFG::UIHKScreenUpgrades::eUpgradesType index)
{
  bool v3; // al

  UFG::UIHKScreenUpgrades::mUpgradesType = index;
  v3 = (int)UFG::UIHKScreenUpgrades::GetUpgradePointsAvailable(index) > 0
    && UFG::UIHKScreenUpgrades::mUpgradesType != UPGRADES_TYPE_MELEE
    || UFG::UIHKScreenUpgrades::mMode == MODE_MODAL;
  this->mCanUpgrade = v3;
  UFG::UIHKScreenUpgrades::Flash_InitText(this);
  UFG::UIHKScreenUpgrades::Flash_Init(this);
  UFG::UIHKScreenUpgrades::PopulateHelpBar(this);
  UFG::UIHKScreenUpgrades::Flash_RefreshCursor(this);
}

// File Line: 680
// RVA: 0x5F1F70
void __fastcall UFG::UIHKScreenUpgrades::MoveCursorLeft(UFG::UIHKScreenUpgrades *this)
{
  char *v2; // rcx
  int v3; // eax

  v2 = (char *)this + 4 * UFG::UIHKScreenUpgrades::mUpgradesType;
  v3 = *((_DWORD *)v2 + 41);
  if ( v3 > 0 )
  {
    *((_DWORD *)v2 + 41) = v3 - 1;
    if ( !this->mCursorXPos[UFG::UIHKScreenUpgrades::mUpgradesType]
      && UFG::UIHKScreenUpgrades::mUpgradesType != UPGRADES_TYPE_FACE )
    {
      this->mCursorYPos[UFG::UIHKScreenUpgrades::mUpgradesType] = 1;
    }
    UFG::UIHKScreenUpgrades::PopulateHelpBar(this);
    UFG::UIHKScreenUpgrades::Flash_RefreshCursor(this);
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xC415B16F, 0i64, 0, 0i64);
  }
}

// File Line: 693
// RVA: 0x5F2140
void __fastcall UFG::UIHKScreenUpgrades::MoveCursorRight(UFG::UIHKScreenUpgrades *this)
{
  int v2; // r9d
  int v3; // eax
  int v4; // ecx

  v2 = this->mCursorYPos[UFG::UIHKScreenUpgrades::mUpgradesType];
  if ( !v2 )
  {
    if ( (unsigned int)UFG::UIHKScreenUpgrades::mUpgradesType >= UPGRADES_TYPE_MELEE )
    {
      if ( UFG::UIHKScreenUpgrades::mUpgradesType != UPGRADES_TYPE_MELEE )
      {
        if ( UFG::UIHKScreenUpgrades::mUpgradesType != UPGRADES_TYPE_FACE )
        {
          v3 = 0;
          goto LABEL_12;
        }
        goto LABEL_6;
      }
      v3 = 6;
      goto LABEL_12;
    }
LABEL_11:
    v3 = 5;
    goto LABEL_12;
  }
  if ( (unsigned int)UFG::UIHKScreenUpgrades::mUpgradesType < UPGRADES_TYPE_FACE )
    goto LABEL_11;
  if ( UFG::UIHKScreenUpgrades::mUpgradesType == UPGRADES_TYPE_FACE )
  {
LABEL_6:
    v3 = 10;
    goto LABEL_12;
  }
  v3 = 0;
LABEL_12:
  if ( UFG::UIHKScreenUpgrades::mUpgradesType == UPGRADES_TYPE_FACE )
    --v3;
  v4 = this->mCursorXPos[UFG::UIHKScreenUpgrades::mUpgradesType];
  if ( v4 < v3 )
  {
    this->mCursorXPos[UFG::UIHKScreenUpgrades::mUpgradesType] = v4 + 1;
    goto LABEL_19;
  }
  if ( v2 == 1 && UFG::UIHKScreenUpgrades::mUpgradesType == UPGRADES_TYPE_MELEE )
  {
    this->mCursorYPos[2] = 0;
    ++this->mCursorXPos[UFG::UIHKScreenUpgrades::mUpgradesType];
LABEL_19:
    UFG::UIHKScreenUpgrades::PopulateHelpBar(this);
    UFG::UIHKScreenUpgrades::Flash_RefreshCursor(this);
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xC415B16F, 0i64, 0, 0i64);
  }
}

// File Line: 718
// RVA: 0x5F2220
void __fastcall UFG::UIHKScreenUpgrades::MoveCursorUp(UFG::UIHKScreenUpgrades *this)
{
  char *v2; // rcx
  int v3; // edx

  v2 = (char *)this + 4 * UFG::UIHKScreenUpgrades::mUpgradesType;
  v3 = *((_DWORD *)v2 + 36);
  if ( v3 > 0 && this->mCursorXPos[UFG::UIHKScreenUpgrades::mUpgradesType] )
  {
    *((_DWORD *)v2 + 36) = v3 - 1;
    UFG::UIHKScreenUpgrades::PopulateHelpBar(this);
    UFG::UIHKScreenUpgrades::Flash_RefreshCursor(this);
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xC415B16F, 0i64, 0, 0i64);
  }
}

// File Line: 730
// RVA: 0x5F1F00
void __fastcall UFG::UIHKScreenUpgrades::MoveCursorDown(UFG::UIHKScreenUpgrades *this)
{
  if ( !this->mCursorYPos[UFG::UIHKScreenUpgrades::mUpgradesType]
    && (UFG::UIHKScreenUpgrades::mUpgradesType != UPGRADES_TYPE_MELEE || this->mCursorXPos[2] != 6) )
  {
    this->mCursorYPos[UFG::UIHKScreenUpgrades::mUpgradesType] = 1;
    UFG::UIHKScreenUpgrades::PopulateHelpBar(this);
    UFG::UIHKScreenUpgrades::Flash_RefreshCursor(this);
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xC415B16F, 0i64, 0, 0i64);
  }
}

// File Line: 747
// RVA: 0x5F2000
void __fastcall UFG::UIHKScreenUpgrades::MoveCursorNext(UFG::UIHKScreenUpgrades *this)
{
  if ( UFG::UIHKScreenUpgrades::mUpgradesType == UPGRADES_TYPE_FACE )
  {
    UFG::UIHKScreenUpgrades::MoveCursorRight(this);
  }
  else if ( this->mCursorYPos[UFG::UIHKScreenUpgrades::mUpgradesType] )
  {
    UFG::UIHKScreenUpgrades::MoveCursorRight(this);
    UFG::UIHKScreenUpgrades::MoveCursorUp(this);
  }
  else if ( UFG::UIHKScreenUpgrades::mUpgradesType != UPGRADES_TYPE_MELEE || this->mCursorXPos[2] != 6 )
  {
    this->mCursorYPos[UFG::UIHKScreenUpgrades::mUpgradesType] = 1;
    UFG::UIHKScreenUpgrades::PopulateHelpBar(this);
    UFG::UIHKScreenUpgrades::Flash_RefreshCursor(this);
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xC415B16F, 0i64, 0, 0i64);
  }
}

// File Line: 766
// RVA: 0x5F20A0
void __fastcall UFG::UIHKScreenUpgrades::MoveCursorPrev(UFG::UIHKScreenUpgrades *this)
{
  int v2; // eax

  if ( UFG::UIHKScreenUpgrades::mUpgradesType == UPGRADES_TYPE_FACE )
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
      UFG::UIHKScreenUpgrades::Flash_RefreshCursor(this);
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xC415B16F, 0i64, 0, 0i64);
    }
    else
    {
      UFG::UIHKScreenUpgrades::MoveCursorLeft(this);
      UFG::UIHKScreenUpgrades::MoveCursorDown(this);
    }
  }
}

// File Line: 785
// RVA: 0x5DDA20
void __fastcall UFG::UIHKScreenUpgrades::Flash_InitText(UFG::UIHKScreenUpgrades *this)
{
  char *v1; // r12
  unsigned int v2; // r13d
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
  unsigned int v13; // r14d
  __int64 v14; // r15
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
  unsigned int v28; // r14d
  __int64 v29; // r15
  char *v30; // rbx
  const char *v31; // rax
  unsigned int v32; // eax
  UFG::UIGfxTranslator *v33; // rcx
  char *v34; // rbx
  const char *v35; // rax
  unsigned int v36; // eax
  UFG::UIGfxTranslator *v37; // rcx
  __int64 v38; // r15
  unsigned int v39; // eax
  UFG::UIGfxTranslator *v40; // rcx
  unsigned int v41; // eax
  UFG::UIGfxTranslator *v42; // rcx
  unsigned __int64 v43; // rdi
  unsigned int v44; // r14d
  char *v45; // rbx
  const char *v46; // rax
  unsigned int v47; // eax
  UFG::UIGfxTranslator *v48; // rcx
  char *v49; // rbx
  const char *v50; // rax
  unsigned int v51; // eax
  UFG::UIGfxTranslator *v52; // rcx
  __int64 v53; // r15
  unsigned int v54; // eax
  UFG::UIGfxTranslator *m_translator; // rcx
  unsigned int v56; // eax
  UFG::UIGfxTranslator *v57; // rcx
  unsigned __int64 v58; // rdi
  unsigned int v59; // r14d
  char *v60; // rbx
  const char *v61; // rax
  unsigned int v62; // eax
  UFG::UIGfxTranslator *v63; // rcx
  char *v64; // rbx
  const char *v65; // rax
  unsigned int v66; // eax
  UFG::UIGfxTranslator *v67; // rcx
  Scaleform::GFx::Movie *pObject; // rsi
  unsigned int v69; // ebx
  __int64 v70; // rdi
  __int64 v71; // r14
  char *v72; // rax
  char *v73; // rax
  UFG::GameStatTracker *v74; // rax
  int v75; // ebx
  UFG::GameStatTracker *v76; // rax
  int XPLevel; // edi
  UFG::GameStatTracker *v78; // rax
  UFG::GameStatTracker *v79; // rax
  int Stat; // ebx
  UFG::GameStatTracker *v81; // rax
  UFG::GameStatTracker *v82; // rax
  UFG::GameStatTracker::ThresholdType v83; // edx
  UFG::GameStatTracker *v84; // rax
  UFG::GameStatTracker *v85; // rax
  Scaleform::GFx::Value::ValueUnion v86; // xmm6_8
  Scaleform::GFx::Value::ValueUnion v87; // xmm6_8
  char *caption; // [rsp+30h] [rbp-D0h]
  Scaleform::GFx::Value v89; // [rsp+38h] [rbp-C8h] BYREF
  Scaleform::GFx::Value v90; // [rsp+68h] [rbp-98h] BYREF
  Scaleform::GFx::Value value; // [rsp+98h] [rbp-68h] BYREF
  __int64 v92; // [rsp+C8h] [rbp-38h]
  UFG::qString v93; // [rsp+D0h] [rbp-30h] BYREF
  char v94[24]; // [rsp+100h] [rbp+0h] BYREF
  char *v95[29]; // [rsp+118h] [rbp+18h]
  char ptr[24]; // [rsp+2E0h] [rbp+1E0h] BYREF
  char *str[29]; // [rsp+2F8h] [rbp+1F8h]
  unsigned int iExpTowardsNextLevel; // [rsp+530h] [rbp+430h] BYREF
  unsigned int iDiffBetweenLevels; // [rsp+538h] [rbp+438h] BYREF

  v92 = -2i64;
  `eh vector constructor iterator(ptr, 0x28ui64, 12, (void (__fastcall *)(void *))UFG::qString::qString);
  `eh vector constructor iterator(v94, 0x28ui64, 12, (void (__fastcall *)(void *))UFG::qString::qString);
  caption = &customCaption;
  v1 = &customCaption;
  v2 = 0;
  v3 = 1;
  switch ( UFG::UIHKScreenUpgrades::mUpgradesType )
  {
    case UPGRADES_TYPE_POLICE:
      v53 = 11i64;
      v2 = 11;
      caption = "$PAUSE_UPGRADES_POLICE_HEADER";
      v54 = UFG::qStringHashUpper32("PAUSE_UPGRADES_POLICE_HEADER", -1);
      m_translator = UFG::UIScreenManager::s_instance->m_translator;
      if ( !m_translator || (v1 = (char *)m_translator->vfptr[5].__vecDelDtor(m_translator, v54)) == 0i64 )
        v1 = "PAUSE_UPGRADES_POLICE_HEADER";
      v56 = UFG::qStringHashUpper32("PAUSE_POLICE_LEVEL_UPPERCASE", -1);
      v57 = UFG::UIScreenManager::s_instance->m_translator;
      if ( v57 )
        v57->vfptr[5].__vecDelDtor(v57, v56);
      v58 = 0i64;
      v59 = 1;
      do
      {
        UFG::qString::Format((UFG::qString *)&ptr[v58], "$PAUSE_POLICE_LEVEL_HEADER_%d", v59);
        v60 = str[v58 / 8];
        if ( v60 )
        {
          if ( *v60 == 36 )
            ++v60;
          v62 = UFG::qStringHashUpper32(v60, -1);
          v63 = UFG::UIScreenManager::s_instance->m_translator;
          if ( !v63 || (v61 = (const char *)v63->vfptr[5].__vecDelDtor(v63, v62)) == 0i64 )
            v61 = v60;
        }
        else
        {
          v61 = 0i64;
        }
        UFG::qString::Set((UFG::qString *)&ptr[v58], v61);
        UFG::qString::Format((UFG::qString *)&v94[v58], "$PAUSE_POLICE_LEVEL_INFO_%d", v59);
        v64 = v95[v58 / 8];
        if ( v64 )
        {
          if ( *v64 == 36 )
            ++v64;
          v66 = UFG::qStringHashUpper32(v64, -1);
          v67 = UFG::UIScreenManager::s_instance->m_translator;
          if ( !v67 || (v65 = (const char *)v67->vfptr[5].__vecDelDtor(v67, v66)) == 0i64 )
            v65 = v64;
        }
        else
        {
          v65 = 0i64;
        }
        UFG::qString::Set((UFG::qString *)&v94[v58], v65);
        ++v59;
        v58 += 40i64;
        --v53;
      }
      while ( v53 );
      goto LABEL_98;
    case UPGRADES_TYPE_TRIAD:
      v38 = 11i64;
      v2 = 11;
      caption = "$PAUSE_UPGRADES_TRIAD_HEADER";
      v39 = UFG::qStringHashUpper32("PAUSE_UPGRADES_TRIAD_HEADER", -1);
      v40 = UFG::UIScreenManager::s_instance->m_translator;
      if ( !v40 || (v1 = (char *)v40->vfptr[5].__vecDelDtor(v40, v39)) == 0i64 )
        v1 = "PAUSE_UPGRADES_TRIAD_HEADER";
      v41 = UFG::qStringHashUpper32("PAUSE_TRIAD_LEVEL_UPPERCASE", -1);
      v42 = UFG::UIScreenManager::s_instance->m_translator;
      if ( v42 )
        v42->vfptr[5].__vecDelDtor(v42, v41);
      v43 = 0i64;
      v44 = 1;
      do
      {
        UFG::qString::Format((UFG::qString *)&ptr[v43], "$PAUSE_TRIAD_LEVEL_HEADER_%d", v44);
        v45 = str[v43 / 8];
        if ( v45 )
        {
          if ( *v45 == 36 )
            ++v45;
          v47 = UFG::qStringHashUpper32(v45, -1);
          v48 = UFG::UIScreenManager::s_instance->m_translator;
          if ( !v48 || (v46 = (const char *)v48->vfptr[5].__vecDelDtor(v48, v47)) == 0i64 )
            v46 = v45;
        }
        else
        {
          v46 = 0i64;
        }
        UFG::qString::Set((UFG::qString *)&ptr[v43], v46);
        UFG::qString::Format((UFG::qString *)&v94[v43], "$PAUSE_TRIAD_LEVEL_INFO_%d", v44);
        v49 = v95[v43 / 8];
        if ( v49 )
        {
          if ( *v49 == 36 )
            ++v49;
          v51 = UFG::qStringHashUpper32(v49, -1);
          v52 = UFG::UIScreenManager::s_instance->m_translator;
          if ( !v52 || (v50 = (const char *)v52->vfptr[5].__vecDelDtor(v52, v51)) == 0i64 )
            v50 = v49;
        }
        else
        {
          v50 = 0i64;
        }
        UFG::qString::Set((UFG::qString *)&v94[v43], v50);
        ++v44;
        v43 += 40i64;
        --v38;
      }
      while ( v38 );
      goto LABEL_98;
    case UPGRADES_TYPE_MELEE:
      v2 = 12;
      caption = "$PAUSE_UPGRADES_MELEE_HEADER";
      v23 = UFG::qStringHashUpper32("PAUSE_UPGRADES_MELEE_HEADER", -1);
      v24 = UFG::UIScreenManager::s_instance->m_translator;
      if ( !v24 || (v1 = (char *)v24->vfptr[5].__vecDelDtor(v24, v23)) == 0i64 )
        v1 = "PAUSE_UPGRADES_MELEE_HEADER";
      v25 = UFG::qStringHashUpper32("PAUSE_MELEE_LEVEL_UPPERCASE", -1);
      v26 = UFG::UIScreenManager::s_instance->m_translator;
      if ( v26 )
        v26->vfptr[5].__vecDelDtor(v26, v25);
      v27 = 0i64;
      v28 = 1;
      v29 = 12i64;
      do
      {
        UFG::qString::Format((UFG::qString *)&ptr[v27], "$PAUSE_MELEE_LEVEL_HEADER_%d", v28);
        v30 = str[v27 / 8];
        if ( v30 )
        {
          if ( *v30 == 36 )
            ++v30;
          v32 = UFG::qStringHashUpper32(v30, -1);
          v33 = UFG::UIScreenManager::s_instance->m_translator;
          if ( !v33 || (v31 = (const char *)v33->vfptr[5].__vecDelDtor(v33, v32)) == 0i64 )
            v31 = v30;
        }
        else
        {
          v31 = 0i64;
        }
        UFG::qString::Set((UFG::qString *)&ptr[v27], v31);
        UFG::qString::Format((UFG::qString *)&v94[v27], "$PAUSE_MELEE_LEVEL_INFO_%d", v28);
        v34 = v95[v27 / 8];
        if ( v34 )
        {
          if ( *v34 == 36 )
            ++v34;
          v36 = UFG::qStringHashUpper32(v34, -1);
          v37 = UFG::UIScreenManager::s_instance->m_translator;
          if ( !v37 || (v35 = (const char *)v37->vfptr[5].__vecDelDtor(v37, v36)) == 0i64 )
            v35 = v34;
        }
        else
        {
          v35 = 0i64;
        }
        UFG::qString::Set((UFG::qString *)&v94[v27], v35);
        ++v28;
        v27 += 40i64;
        --v29;
      }
      while ( v29 );
LABEL_98:
      v3 = 0;
      break;
    case UPGRADES_TYPE_FACE:
      v2 = 10;
      caption = "$PAUSE_UPGRADES_FACE_HEADER";
      v8 = UFG::qStringHashUpper32("PAUSE_UPGRADES_FACE_HEADER", -1);
      v9 = UFG::UIScreenManager::s_instance->m_translator;
      if ( !v9 || (v1 = (char *)v9->vfptr[5].__vecDelDtor(v9, v8)) == 0i64 )
        v1 = "PAUSE_UPGRADES_FACE_HEADER";
      v10 = UFG::qStringHashUpper32("PAUSE_FACE_LEVEL_UPPERCASE", -1);
      v11 = UFG::UIScreenManager::s_instance->m_translator;
      if ( v11 )
        v11->vfptr[5].__vecDelDtor(v11, v10);
      v12 = 0i64;
      v13 = 1;
      v14 = 10i64;
      do
      {
        UFG::qString::Format((UFG::qString *)&ptr[v12], "$PAUSE_FACE_LEVEL_HEADER_%d", v13);
        v15 = str[v12 / 8];
        if ( v15 )
        {
          if ( *v15 == 36 )
            ++v15;
          v17 = UFG::qStringHashUpper32(v15, -1);
          v18 = UFG::UIScreenManager::s_instance->m_translator;
          if ( !v18 || (v16 = (const char *)v18->vfptr[5].__vecDelDtor(v18, v17)) == 0i64 )
            v16 = v15;
        }
        else
        {
          v16 = 0i64;
        }
        UFG::qString::Set((UFG::qString *)&ptr[v12], v16);
        UFG::qString::Format((UFG::qString *)&v94[v12], "$PAUSE_FACE_LEVEL_INFO_%d", v13);
        v19 = v95[v12 / 8];
        if ( v19 )
        {
          if ( *v19 == 36 )
            ++v19;
          v21 = UFG::qStringHashUpper32(v19, -1);
          v22 = UFG::UIScreenManager::s_instance->m_translator;
          if ( !v22 || (v20 = (const char *)v22->vfptr[5].__vecDelDtor(v22, v21)) == 0i64 )
            v20 = v19;
        }
        else
        {
          v20 = 0i64;
        }
        UFG::qString::Set((UFG::qString *)&v94[v12], v20);
        ++v13;
        v12 += 40i64;
        --v14;
      }
      while ( v14 );
      v3 = 1;
      break;
    case UPGRADES_TYPE_HEALTH:
      caption = "$PAUSE_UPGRADES_HEALTH_HEADER";
      v4 = (unsigned int)UFG::qStringHashUpper32("PAUSE_UPGRADES_HEALTH_HEADER", -1);
      v5 = UFG::UIScreenManager::s_instance->m_translator;
      if ( !v5 || (v1 = (char *)v5->vfptr[5].__vecDelDtor(v5, v4)) == 0i64 )
        v1 = "PAUSE_UPGRADES_HEALTH_HEADER";
      v6 = UFG::qStringHashUpper32("PAUSE_HEALTH_LEVEL_UPPERCASE", -1);
      v7 = UFG::UIScreenManager::s_instance->m_translator;
      if ( v7 )
        v7->vfptr[5].__vecDelDtor(v7, v6);
      break;
  }
  pObject = this->mRenderable->m_movie.pObject;
  if ( v2 )
  {
    v69 = 1;
    v70 = 0i64;
    v71 = v2;
    do
    {
      UFG::qString::qString((UFG::qString *)&v89);
      UFG::qString::qString(&v93);
      if ( v3 )
      {
        UFG::qString::Format((UFG::qString *)&v89, "mc_linearScroller.mc_slot_%d.tf_header.htmlText", v69);
        UFG::qString::Format(&v93, "mc_linearScroller.mc_slot_%d.tf_body.htmlText", v69);
      }
      else
      {
        UFG::qString::Format((UFG::qString *)&v89, "mc_branchingScroller.mc_slot_%d.tf_header.htmlText", v69);
        UFG::qString::Format(&v93, "mc_branchingScroller.mc_slot_%d.tf_body.htmlText", v69);
      }
      v72 = str[v70];
      value.pObjectInterface = 0i64;
      value.Type = VT_String;
      value.mValue.pString = v72;
      Scaleform::GFx::Movie::SetVariable(pObject, *(const char **)&v89.Type, &value, 1i64);
      if ( (value.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
          value.pObjectInterface,
          &value,
          value.mValue);
        value.pObjectInterface = 0i64;
      }
      value.Type = VT_Undefined;
      v73 = v95[v70];
      v90.pObjectInterface = 0i64;
      v90.Type = VT_String;
      v90.mValue.pString = v73;
      Scaleform::GFx::Movie::SetVariable(pObject, v93.mData, &v90, 1i64);
      if ( (v90.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&v90.pObjectInterface->vfptr->gap8[8])(
          v90.pObjectInterface,
          &v90,
          v90.mValue);
        v90.pObjectInterface = 0i64;
      }
      v90.Type = VT_Undefined;
      UFG::qString::~qString(&v93);
      UFG::qString::~qString((UFG::qString *)&v89);
      ++v69;
      v70 += 5i64;
      --v71;
    }
    while ( v71 );
  }
  UFG::UIHKScreenUpgrades::Flash_SetSelectedTab(this, caption);
  iExpTowardsNextLevel = 0;
  iDiffBetweenLevels = 100;
  if ( UFG::UIHKScreenUpgrades::mUpgradesType == UPGRADES_TYPE_POLICE )
  {
    v84 = UFG::GameStatTracker::Instance();
    Stat = UFG::GameStatTracker::GetStat(v84, CopXP);
    v85 = UFG::GameStatTracker::Instance();
    XPLevel = UFG::GameStatTracker::GetXPLevel(v85, ThresholdType_Cop, Stat);
    v82 = UFG::GameStatTracker::Instance();
    v83 = ThresholdType_Cop;
    goto LABEL_115;
  }
  if ( UFG::UIHKScreenUpgrades::mUpgradesType == UPGRADES_TYPE_TRIAD )
  {
    v79 = UFG::GameStatTracker::Instance();
    Stat = UFG::GameStatTracker::GetStat(v79, TriadXP);
    v81 = UFG::GameStatTracker::Instance();
    XPLevel = UFG::GameStatTracker::GetXPLevel(v81, ThresholdType_Triad, Stat);
    v82 = UFG::GameStatTracker::Instance();
    v83 = ThresholdType_Triad;
LABEL_115:
    iExpTowardsNextLevel = UFG::GameStatTracker::GetPercentageToNextXPLevel(v82, v83, Stat);
    goto LABEL_116;
  }
  if ( UFG::UIHKScreenUpgrades::mUpgradesType != UPGRADES_TYPE_FACE )
    goto LABEL_123;
  v74 = UFG::GameStatTracker::Instance();
  v75 = UFG::GameStatTracker::GetStat(v74, Standing);
  v76 = UFG::GameStatTracker::Instance();
  XPLevel = UFG::GameStatTracker::GetFaceLevelFromExperience(v76, v75);
  v78 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::GetPointsSinceLastLevel(v78, 29, &iExpTowardsNextLevel, &iDiffBetweenLevels);
LABEL_116:
  v89.pObjectInterface = 0i64;
  v89.Type = VT_Number;
  v89.mValue.NValue = (double)XPLevel;
  Scaleform::GFx::Movie::SetVariable(pObject, "gCurrentLevel", &v89, 1i64);
  v86.NValue = (double)(int)iExpTowardsNextLevel;
  if ( (v89.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&v89.pObjectInterface->vfptr->gap8[8])(
      v89.pObjectInterface,
      &v89,
      v89.mValue);
    v89.pObjectInterface = 0i64;
  }
  v89.Type = VT_Number;
  v89.mValue = v86;
  Scaleform::GFx::Movie::SetVariable(pObject, "gExpTowardsNextLevel", &v89, 1i64);
  v87.NValue = (double)(int)iDiffBetweenLevels;
  if ( (v89.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&v89.pObjectInterface->vfptr->gap8[8])(
      v89.pObjectInterface,
      &v89,
      v89.mValue);
    v89.pObjectInterface = 0i64;
  }
  v89.Type = VT_Number;
  v89.mValue = v87;
  Scaleform::GFx::Movie::SetVariable(pObject, "gDiffBetweenLevels", &v89, 1i64);
  if ( (v89.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&v89.pObjectInterface->vfptr->gap8[8])(
      v89.pObjectInterface,
      &v89,
      v89.mValue);
    v89.pObjectInterface = 0i64;
  }
  v89.Type = VT_Undefined;
LABEL_123:
  v90.pObjectInterface = 0i64;
  v90.Type = VT_String;
  v90.mValue.pString = v1;
  Scaleform::GFx::Movie::SetVariable(pObject, "mc_header.tf_header.htmlText", &v90, 1i64);
  if ( (v90.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&v90.pObjectInterface->vfptr->gap8[8])(
      v90.pObjectInterface,
      &v90,
      v90.mValue);
    v90.pObjectInterface = 0i64;
  }
  v90.Type = VT_Undefined;
  `eh vector destructor iterator(v94, 0x28ui64, 12, (void (__fastcall *)(void *))UFG::qString::~qString);
  `eh vector destructor iterator(ptr, 0x28ui64, 12, (void (__fastcall *)(void *))UFG::qString::~qString);
}

// File Line: 987
// RVA: 0x5DD010
void __fastcall UFG::UIHKScreenUpgrades::Flash_Init(UFG::UIHKScreenUpgrades *this)
{
  Scaleform::GFx::Movie *pObject; // rbx
  UFG::GameStatTracker *v3; // rax
  bool v4; // di
  Scaleform::GFx::Value::ValueUnion v5; // xmm6_8
  Scaleform::GFx::Value::ValueUnion v6; // xmm6_8
  int v7; // edi
  int v8; // esi
  bool v9; // di
  UFG::GameStatTracker *v10; // rax
  int NumHealthShrinesCollected; // edi
  UFG::GameStatTracker *v12; // rax
  unsigned int v13; // esi
  unsigned int v14; // eax
  UFG::UIGfxTranslator *m_translator; // rcx
  const char *v16; // rax
  unsigned int v17; // eax
  UFG::UIGfxTranslator *v18; // rcx
  char *mData; // rdi
  unsigned int v20; // eax
  UFG::UIGfxTranslator *v21; // rcx
  const char *v22; // rax
  char *v23; // rdi
  const char *v24; // rax
  UFG::GameStatTracker *v25; // rax
  int Stat; // edi
  UFG::GameStatTracker *v27; // rax
  int v28; // edi
  UFG::GameStatTracker *v29; // rax
  int v30; // edi
  UFG::GameStatTracker *v31; // rax
  int v32; // edi
  UFG::GameStatTracker *v33; // rax
  int v34; // edi
  UFG::GameStatTracker *v35; // rax
  int v36; // edi
  UFG::GameStatTracker *v37; // rax
  int v38; // edi
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-49h] BYREF
  Scaleform::GFx::Value ptr; // [rsp+58h] [rbp-19h] BYREF
  UFG::qString v41; // [rsp+88h] [rbp+17h] BYREF
  __int64 v42; // [rsp+B0h] [rbp+3Fh]

  v42 = -2i64;
  pObject = this->mRenderable->m_movie.pObject;
  value.pObjectInterface = 0i64;
  value.Type = VT_Number;
  value.mValue.NValue = (double)UFG::UIHKScreenUpgrades::GetUpgradePointsAvailable(UFG::UIHKScreenUpgrades::mUpgradesType);
  Scaleform::GFx::Movie::SetVariable(pObject, "gUpgradePoints", &value, 1i64);
  if ( UFG::UIHKScreenUpgrades::mUpgradesType >= UPGRADES_TYPE_POLICE )
  {
    if ( UFG::UIHKScreenUpgrades::mUpgradesType <= UPGRADES_TYPE_TRIAD )
    {
      v4 = 1;
      goto LABEL_7;
    }
    if ( UFG::UIHKScreenUpgrades::mUpgradesType == UPGRADES_TYPE_MELEE )
    {
      v3 = UFG::GameStatTracker::Instance();
      v4 = (int)UFG::GameStatTracker::GetStat(v3, StatueOffensiveStage) > 0;
      goto LABEL_7;
    }
  }
  v4 = 0;
LABEL_7:
  if ( (value.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
      value.pObjectInterface,
      &value,
      value.mValue);
    value.pObjectInterface = 0i64;
  }
  value.Type = VT_Boolean;
  value.mValue.BValue = v4;
  Scaleform::GFx::Movie::SetVariable(pObject, "gBranchingFirstSlot", &value, 1i64);
  v5.NValue = (double)UFG::UIHKScreenUpgrades::GetUpperTrackLevel(this);
  if ( (value.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
      value.pObjectInterface,
      &value,
      value.mValue);
    value.pObjectInterface = 0i64;
  }
  value.Type = VT_Number;
  value.mValue = v5;
  Scaleform::GFx::Movie::SetVariable(pObject, "gUpperTrackLevel", &value, 1i64);
  v6.NValue = (double)UFG::UIHKScreenUpgrades::GetLowerTrackLevel(this);
  if ( (value.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
      value.pObjectInterface,
      &value,
      value.mValue);
    value.pObjectInterface = 0i64;
  }
  value.Type = VT_Number;
  value.mValue = v6;
  Scaleform::GFx::Movie::SetVariable(pObject, "gLowerTrackLevel", &value, 1i64);
  v7 = 10;
  if ( (unsigned int)UFG::UIHKScreenUpgrades::mUpgradesType < UPGRADES_TYPE_MELEE )
  {
    v8 = 5;
  }
  else if ( UFG::UIHKScreenUpgrades::mUpgradesType == UPGRADES_TYPE_MELEE )
  {
    v8 = 6;
  }
  else if ( UFG::UIHKScreenUpgrades::mUpgradesType == UPGRADES_TYPE_FACE )
  {
    v8 = 10;
  }
  else
  {
    v8 = 0;
  }
  if ( (value.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
      value.pObjectInterface,
      &value,
      value.mValue);
    value.pObjectInterface = 0i64;
  }
  value.Type = VT_Number;
  value.mValue.NValue = (double)v8;
  Scaleform::GFx::Movie::SetVariable(pObject, "gMaxUpperTrackLevel", &value, 1i64);
  if ( (unsigned int)UFG::UIHKScreenUpgrades::mUpgradesType < UPGRADES_TYPE_FACE )
  {
    v7 = 5;
  }
  else if ( UFG::UIHKScreenUpgrades::mUpgradesType != UPGRADES_TYPE_FACE )
  {
    v7 = 0;
  }
  if ( (value.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
      value.pObjectInterface,
      &value,
      value.mValue);
    value.pObjectInterface = 0i64;
  }
  value.Type = VT_Number;
  value.mValue.NValue = (double)v7;
  Scaleform::GFx::Movie::SetVariable(pObject, "gMaxLowerTrackLevel", &value, 1i64);
  v9 = UFG::UIHKScreenUpgrades::mMode == MODE_MODAL;
  if ( (value.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
      value.pObjectInterface,
      &value,
      value.mValue);
    value.pObjectInterface = 0i64;
  }
  value.Type = VT_Boolean;
  value.mValue.BValue = v9;
  Scaleform::GFx::Movie::SetVariable(pObject, "gIsModal", &value, 1i64);
  if ( UFG::UIHKScreenUpgrades::mUpgradesType == UPGRADES_TYPE_HEALTH )
  {
    v10 = UFG::GameStatTracker::Instance();
    NumHealthShrinesCollected = UFG::GameStatTracker::GetNumHealthShrinesCollected(v10);
    v12 = UFG::GameStatTracker::Instance();
    v13 = 10 * UFG::GameStatTracker::GetHealthLevel(v12);
    if ( (value.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        value.mValue);
      value.pObjectInterface = 0i64;
    }
    value.Type = VT_Number;
    value.mValue.NValue = (double)NumHealthShrinesCollected;
    Scaleform::GFx::Movie::SetVariable(pObject, "gShrinesFound", &value, 1i64);
    UFG::qString::qString(&v41);
    if ( NumHealthShrinesCollected == 1 )
    {
      v14 = UFG::qStringHashUpper32("UPGRADES_HEALTH_SHRINE_FOUND", -1);
      m_translator = UFG::UIScreenManager::s_instance->m_translator;
      if ( !m_translator || (v16 = (const char *)m_translator->vfptr[5].__vecDelDtor(m_translator, v14)) == 0i64 )
      {
        UFG::qString::Format(&v41, "UPGRADES_HEALTH_SHRINE_FOUND", 1i64);
LABEL_41:
        mData = v41.mData;
        if ( (value.Type & 0x40) != 0 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
            value.pObjectInterface,
            &value,
            value.mValue);
          value.pObjectInterface = 0i64;
        }
        value.Type = VT_String;
        value.mValue.pString = mData;
        Scaleform::GFx::Movie::SetVariable(pObject, "mc_healthUpgradeDisplay.mc_info.tf_header.text", &value, 1i64);
        v20 = UFG::qStringHashUpper32("UPGRADES_PERCENT_HEALTH_GAINED", -1);
        v21 = UFG::UIScreenManager::s_instance->m_translator;
        if ( !v21 || (v22 = (const char *)v21->vfptr[5].__vecDelDtor(v21, v20)) == 0i64 )
          v22 = "UPGRADES_PERCENT_HEALTH_GAINED";
        UFG::qString::Format(&v41, v22, v13);
        v23 = v41.mData;
        if ( (value.Type & 0x40) != 0 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
            value.pObjectInterface,
            &value,
            value.mValue);
          value.pObjectInterface = 0i64;
        }
        value.Type = VT_String;
        value.mValue.pString = v23;
        Scaleform::GFx::Movie::SetVariable(pObject, "mc_healthUpgradeDisplay.mc_info.tf_maxHealth.text", &value, 1i64);
        UFG::qString::~qString(&v41);
        goto LABEL_49;
      }
    }
    else
    {
      v17 = UFG::qStringHashUpper32("UPGRADES_HEALTH_SHRINES_FOUND", -1);
      v18 = UFG::UIScreenManager::s_instance->m_translator;
      if ( !v18 || (v16 = (const char *)v18->vfptr[5].__vecDelDtor(v18, v17)) == 0i64 )
        v16 = "UPGRADES_HEALTH_SHRINES_FOUND";
    }
    UFG::qString::Format(&v41, v16, (unsigned int)NumHealthShrinesCollected);
    goto LABEL_41;
  }
LABEL_49:
  `eh vector constructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  if ( UFG::UIHKScreenUpgrades::mUpgradesType )
  {
    switch ( UFG::UIHKScreenUpgrades::mUpgradesType )
    {
      case UPGRADES_TYPE_TRIAD:
        if ( (ptr.Type & 0x40) != 0 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
            ptr.pObjectInterface,
            &ptr,
            ptr.mValue);
          ptr.pObjectInterface = 0i64;
        }
        v24 = "triad";
        break;
      case UPGRADES_TYPE_MELEE:
        if ( (ptr.Type & 0x40) != 0 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
            ptr.pObjectInterface,
            &ptr,
            ptr.mValue);
          ptr.pObjectInterface = 0i64;
        }
        v24 = "melee";
        break;
      case UPGRADES_TYPE_FACE:
        if ( (ptr.Type & 0x40) != 0 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
            ptr.pObjectInterface,
            &ptr,
            ptr.mValue);
          ptr.pObjectInterface = 0i64;
        }
        v24 = "face";
        break;
      case UPGRADES_TYPE_HEALTH:
        if ( (ptr.Type & 0x40) != 0 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
            ptr.pObjectInterface,
            &ptr,
            ptr.mValue);
          ptr.pObjectInterface = 0i64;
        }
        v24 = "health";
        break;
      default:
        goto LABEL_70;
    }
  }
  else
  {
    if ( (ptr.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
        ptr.pObjectInterface,
        &ptr,
        ptr.mValue);
      ptr.pObjectInterface = 0i64;
    }
    v24 = "police";
  }
  ptr.Type = VT_String;
  ptr.mValue.pString = v24;
LABEL_70:
  v25 = UFG::GameStatTracker::Instance();
  Stat = UFG::GameStatTracker::GetStat(v25, CopUpgradePoint);
  v27 = UFG::GameStatTracker::Instance();
  v28 = Stat - UFG::GameStatTracker::GetStat(v27, CopShootingStage);
  v29 = UFG::GameStatTracker::Instance();
  v30 = v28 - UFG::GameStatTracker::GetStat(v29, CopDrivingStage);
  if ( v30 < 0 )
    v30 = 0;
  if ( (value.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
      value.pObjectInterface,
      &value,
      value.mValue);
    value.pObjectInterface = 0i64;
  }
  value.Type = VT_Number;
  value.mValue.NValue = (double)v30;
  Scaleform::GFx::Movie::SetVariable(pObject, "gPoliceUpgradePoints", &value, 1i64);
  v31 = UFG::GameStatTracker::Instance();
  v32 = UFG::GameStatTracker::GetStat(v31, TriadUpgradePoint);
  v33 = UFG::GameStatTracker::Instance();
  v34 = v32 - UFG::GameStatTracker::GetStat(v33, TriadOffensiveStage);
  v35 = UFG::GameStatTracker::Instance();
  v36 = v34 - UFG::GameStatTracker::GetStat(v35, TriadDefensiveStage);
  if ( v36 < 0 )
    v36 = 0;
  if ( (value.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
      value.pObjectInterface,
      &value,
      value.mValue);
    value.pObjectInterface = 0i64;
  }
  value.Type = VT_Number;
  value.mValue.NValue = (double)v36;
  Scaleform::GFx::Movie::SetVariable(pObject, "gTriadUpgradePoints", &value, 1i64);
  v37 = UFG::GameStatTracker::Instance();
  v38 = UFG::GameStatTracker::GetStat(v37, StatueUpgradePoint);
  if ( v38 < 0 )
    v38 = 0;
  if ( (value.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
      value.pObjectInterface,
      &value,
      value.mValue);
    value.pObjectInterface = 0i64;
  }
  value.Type = VT_Number;
  value.mValue.NValue = (double)v38;
  Scaleform::GFx::Movie::SetVariable(pObject, "gMeleeUpgradePoints", &value, 1i64);
  Scaleform::GFx::Movie::Invoke(pObject, "Init", 0i64, &ptr, 1u);
  `eh vector destructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  if ( (value.Type & 0x40) != 0 )
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
      value.pObjectInterface,
      &value,
      value.mValue);
}

// File Line: 1099
// RVA: 0x5DEAC0
void __fastcall UFG::UIHKScreenUpgrades::Flash_RefreshCursor(UFG::UIHKScreenUpgrades *this)
{
  Scaleform::GFx::Movie *pObject; // rdi
  UFG::UIHKScreenUpgrades::eUpgradesType v3; // ecx
  Scaleform::GFx::Value::ValueUnion v4; // xmm6_8
  double v5; // xmm6_8
  bool v6; // bl
  Scaleform::GFx::Value ptr; // [rsp+28h] [rbp-59h] BYREF
  char v8[16]; // [rsp+58h] [rbp-29h] BYREF
  __int64 v9; // [rsp+68h] [rbp-19h]
  int v10; // [rsp+70h] [rbp-11h]
  double v11; // [rsp+78h] [rbp-9h]
  char v12[16]; // [rsp+88h] [rbp+7h] BYREF
  __int64 v13; // [rsp+98h] [rbp+17h]
  int v14; // [rsp+A0h] [rbp+1Fh]
  __int64 v15; // [rsp+A8h] [rbp+27h]
  __int64 v16; // [rsp+B8h] [rbp+37h]

  v16 = -2i64;
  pObject = this->mRenderable->m_movie.pObject;
  `eh vector constructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  v3 = UFG::UIHKScreenUpgrades::mUpgradesType;
  v4.NValue = (double)this->mCursorXPos[UFG::UIHKScreenUpgrades::mUpgradesType];
  if ( (ptr.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
      ptr.pObjectInterface,
      &ptr,
      ptr.mValue);
    ptr.pObjectInterface = 0i64;
    v3 = UFG::UIHKScreenUpgrades::mUpgradesType;
  }
  ptr.Type = VT_Number;
  ptr.mValue = v4;
  v5 = (double)this->mCursorYPos[v3];
  if ( (v10 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v9 + 16i64))(v9, v8, COERCE_DOUBLE(*(_QWORD *)&v11));
    v9 = 0i64;
    v3 = UFG::UIHKScreenUpgrades::mUpgradesType;
  }
  v10 = 5;
  v11 = v5;
  v6 = this->mCanUpgrade && UFG::UIHKScreenUpgrades::IsUpgradable(this, this->mCursorXPos[v3], this->mCursorYPos[v3]);
  if ( (v14 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v13 + 16i64))(v13, v12, v15);
    v13 = 0i64;
  }
  v14 = 2;
  LOBYTE(v15) = v6;
  Scaleform::GFx::Movie::Invoke(pObject, "SetCursorPos", 0i64, &ptr, 3u);
  `eh vector destructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 1115
// RVA: 0x5DB770
void __fastcall UFG::UIHKScreenUpgrades::Flash_HandleUpgradeSelected(UFG::UIHKScreenUpgrades *this)
{
  Scaleform::GFx::Movie *pObject; // rdi
  Scaleform::GFx::Value::ValueUnion v3; // xmm6_8
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-50h] BYREF

  pObject = this->mRenderable->m_movie.pObject;
  `eh vector constructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  v3.NValue = (double)this->mCursorYPos[UFG::UIHKScreenUpgrades::mUpgradesType];
  if ( (pargs.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      pargs.mValue);
    pargs.pObjectInterface = 0i64;
  }
  pargs.Type = VT_Number;
  pargs.mValue = v3;
  Scaleform::GFx::Movie::Invoke(pObject, "HandleUpgradeSelected", 0i64, &pargs, 1u);
  `eh vector destructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 1127
// RVA: 0x5E0B70
void __fastcall UFG::UIHKScreenUpgrades::Flash_SetSelectedTab(UFG::UIHKScreenUpgrades *this, const char *caption)
{
  Scaleform::GFx::Movie *pObject; // rdi
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h] BYREF

  pObject = this->mRenderable->m_movie.pObject;
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
  Scaleform::GFx::Movie::Invoke(pObject, "TabMenuWidgetList_JumpToItem", 0i64, &pargs, 1u);
  `eh vector destructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 1183
// RVA: 0x5DAAD0
__int64 __fastcall UFG::UIHKScreenUpgrades::Flash_GetMouseNewTab(UFG::UIHKScreenUpgrades *this)
{
  Scaleform::GFx::Movie *pObject; // rcx
  unsigned int NValue; // ebx
  Scaleform::GFx::Value pval; // [rsp+28h] [rbp-40h] BYREF

  pObject = this->mRenderable->m_movie.pObject;
  if ( !pObject )
    return 0i64;
  pval.pObjectInterface = 0i64;
  pval.Type = VT_Undefined;
  Scaleform::GFx::Movie::GetVariable(pObject, &pval, "gMouseNewTab");
  NValue = (int)pval.mValue.NValue;
  if ( (pval.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pval.pObjectInterface->vfptr->gap8[8])(
      pval.pObjectInterface,
      &pval,
      pval.mValue);
    pval.pObjectInterface = 0i64;
  }
  return NValue;
}

// File Line: 1196
// RVA: 0x604970
void __fastcall UFG::UIHKScreenUpgrades::SendTelemetryData(
        UFG::UIHKScreenUpgrades *this,
        UFG::UIHKScreenUpgrades::eUpgradesType type,
        UFG::GameStat::Int32Stat itemHash32)
{
  UFG::OSuiteDBLogger *v5; // rsi
  int v6; // ebx
  const char *v7; // rdx
  char *p_result; // rcx
  int mUID; // ebx
  UFG::GameStatTracker *v10; // rax
  int Stat; // edi
  int v12; // ebx
  UFG::qSymbol result; // [rsp+20h] [rbp-98h] BYREF
  char v14; // [rsp+24h] [rbp-94h] BYREF
  char dest[128]; // [rsp+30h] [rbp-88h] BYREF
  char v16; // [rsp+D8h] [rbp+20h] BYREF

  v5 = UFG::OSuiteDBLogger::Instance();
  if ( UFG::OSuiteDBLogger::CreateMetric(v5, "PlayerUpgrade") )
  {
    if ( type )
    {
      v6 = type - 1;
      if ( v6 )
      {
        if ( v6 != 1 )
          return;
        v7 = "Melee";
        p_result = &v16;
      }
      else
      {
        v7 = "Triad";
        p_result = &v14;
      }
    }
    else
    {
      v7 = "Cop";
      p_result = (char *)&result;
    }
    mUID = UFG::qSymbol::create_from_string((UFG::qSymbol *)p_result, v7)->mUID;
    UFG::qSPrintf(dest, 128, "i32_%s", "Type");
    OSuite::ZMetric::SetProperty(v5->m_pMetric, dest, mUID);
    v10 = UFG::GameStatTracker::Instance();
    Stat = UFG::GameStatTracker::GetStat(v10, itemHash32);
    v12 = UFG::GameStat::GetSymbol(itemHash32)->mUID;
    UFG::qSPrintf(dest, 128, "i32_%s", "StageType");
    OSuite::ZMetric::SetProperty(v5->m_pMetric, dest, v12);
    UFG::qSPrintf(dest, 128, "i32_%s", "StageLevel");
    OSuite::ZMetric::SetProperty(v5->m_pMetric, dest, Stat);
    UFG::OSuiteDBLogger::SubmitMetric(v5, 1);
  }
}

