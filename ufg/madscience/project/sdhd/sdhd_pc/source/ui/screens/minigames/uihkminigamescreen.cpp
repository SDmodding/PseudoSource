// File Line: 45
// RVA: 0x5C9820
void __fastcall UFG::UIHKMinigameScreen::~UIHKMinigameScreen(UFG::UIHKMinigameScreen *this)
{
  int v2; // eax

  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKMinigameScreen::`vftable;
  if ( byte_142431A14 && UFG::UIHK_PDAWidget::mInputLocked )
  {
    UFG::SetInputMode_PDA_Off(UFG::gActiveControllerNum);
    v2 = UFG::UIHKGameplayHelpWidget::mLocked;
    if ( UFG::UIHKGameplayHelpWidget::mLocked > 0 )
      v2 = --UFG::UIHKGameplayHelpWidget::mLocked;
    if ( v2 < 1 )
      UFG::UIHKScreenHud::GameplayHelp->mChanged = 1;
    --UFG::UIHK_PDAWidget::mInputLocked;
  }
  UFG::UIHKScreenHud::PDACache.state = STATE_IDLE;
  byte_142431A14 = 0;
  dword_142431A18 = 0;
  --UFG::UIHKMinigameScreen::mNumMinigameScreens;
  UFG::UIScreen::~UIScreen(this);
}

// File Line: 54
// RVA: 0x63E5A0
// attributes: thunk
void __fastcall UFG::UIHKMinigameScreen::update(UFG::UIHKScreenStats *this, float elapsed)
{
  UFG::UIScreen::update(this, elapsed);
}

// File Line: 60
// RVA: 0x6214A0
bool __fastcall UFG::UIHKMinigameScreen::handleMessage(
        UFG::UIHKMinigameScreen *this,
        unsigned int msgId,
        UFG::UIMessage *msg)
{
  if ( msgId == UI_HASH_BUTTON_START_PRESSED_30 )
  {
    if ( (unsigned int)UFG::FlowController::GetCurrentState(&UFG::gFlowController) == uidGameStateInGame_13
      && !(unsigned __int8)UFG::UI::IsGamePaused()
      && !UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "NISPause") )
    {
      UFG::UI::PauseGame("NISPause");
      return 1;
    }
    return 1;
  }
  if ( msgId == UI_HASH_CLEANUPMINIGAME_20 || msgId == UI_HASH_GAME_OVER_20 )
  {
    UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, this->mScreenUID);
    return 1;
  }
  if ( msgId == UI_HASH_SETFINISHED_20 )
  {
    this->mFinished = 1;
    return 1;
  }
  else if ( msgId == UI_HASH_RESUME_20 )
  {
    this->mProgressionState = RUNNING;
    return 1;
  }
  else
  {
    return UFG::UIScreen::handleMessage(this, msgId, msg);
  }
}

// File Line: 100
// RVA: 0x620F70
void __fastcall UFG::UIHKMinigameScreen::handleExiting(UFG::UIHKMinigameScreen *this)
{
  int v2; // eax
  unsigned int v3; // esi
  unsigned int v4; // ebp
  UFG::allocator::free_link *v5; // rax
  __int64 v6; // rbx
  __int64 v7; // rax
  int v8; // eax

  this->mProgressionState = EXIT_BOX;
  v2 = UFG::qStringCompare(this->m_screenName, "PhoneTraceMinigame", -1);
  v3 = UI_HASH_RESUME_20;
  if ( v2 )
  {
    v4 = UI_HASH_SETFINISHED_20;
    v5 = UFG::qMemoryPool::Allocate(
           &gScaleformMemoryPool,
           0x128ui64,
           "UIScreenDialogBox::createTwoButtonDialog",
           0i64,
           1u);
    if ( !v5 )
    {
      v6 = 0i64;
      goto LABEL_7;
    }
    goto LABEL_5;
  }
  v4 = UI_HASH_CLEANUPMINIGAME_20;
  v5 = UFG::qMemoryPool::Allocate(
         &gScaleformMemoryPool,
         0x128ui64,
         "UIScreenDialogBox::createTwoButtonDialog",
         0i64,
         1u);
  if ( v5 )
  {
LABEL_5:
    UFG::UIScreenDialogBox::UIScreenDialogBoxData::UIScreenDialogBoxData((UFG::UIScreenDialogBox::UIScreenDialogBoxData *)v5);
    v6 = v7;
    goto LABEL_7;
  }
  v6 = 0i64;
LABEL_7:
  UFG::qString::Set((UFG::qString *)(v6 + 248), "DialogBox");
  *(_DWORD *)(v6 + 16) = 2;
  *(_QWORD *)(v6 + 8) = this;
  UFG::qString::Set((UFG::qString *)(v6 + 24), &customCaption);
  UFG::qString::Set((UFG::qString *)(v6 + 64), "$MINIGAME_CONFIRM_EXIT");
  *(_DWORD *)(v6 + 20) = 2;
  *(_DWORD *)(v6 + 104) = v4;
  UFG::qString::Set((UFG::qString *)(v6 + 120), "$COMMON_OK");
  *(_DWORD *)(v6 + 108) = v3;
  UFG::qString::Set((UFG::qString *)(v6 + 160), "$COMMON_CANCEL");
  *(_DWORD *)(v6 + 288) = (int)gUIHorizontalResolution;
  v8 = (int)gUIVerticalResolution;
  *(_BYTE *)(v6 + 244) = 0;
  *(_DWORD *)(v6 + 292) = v8;
  UFG::UIScreenManagerBase::queuePushScreen(UFG::UIScreenManager::s_instance, *(const char **)(v6 + 272), -1)->m_commandData = (UFG::UICommandData *)v6;
}

