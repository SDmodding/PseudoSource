// File Line: 45
// RVA: 0x5C9820
void __fastcall UFG::UIHKMinigameScreen::~UIHKMinigameScreen(UFG::UIHKMinigameScreen *this)
{
  UFG::UIHKMinigameScreen *v1; // rbx
  int v2; // eax

  v1 = this;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKMinigameScreen::`vftable';
  if ( unk_142431A14 && UFG::UIHK_PDAWidget::mInputLocked )
  {
    UFG::SetInputMode_PDA_Off(UFG::gActiveControllerNum);
    v2 = UFG::UIHKGameplayHelpWidget::mLocked;
    if ( UFG::UIHKGameplayHelpWidget::mLocked > 0 )
      v2 = UFG::UIHKGameplayHelpWidget::mLocked-- - 1;
    if ( v2 < 1 )
      UFG::UIHKScreenHud::GameplayHelp->mChanged = 1;
    --UFG::UIHK_PDAWidget::mInputLocked;
  }
  UFG::UIHKScreenHud::PDACache.state = 0;
  unk_142431A14 = 0;
  unk_142431A18 = 0;
  --UFG::UIHKMinigameScreen::mNumMinigameScreens;
  UFG::UIScreen::~UIScreen((UFG::UIScreen *)&v1->vfptr);
}

// File Line: 54
// RVA: 0x63E5A0
void __fastcall UFG::UIHKMinigameScreen::update(UFG::UIHKScreenStats *this, float elapsed)
{
  UFG::UIScreen::update((UFG::UIScreen *)&this->vfptr, elapsed);
}

// File Line: 60
// RVA: 0x6214A0
bool __fastcall UFG::UIHKMinigameScreen::handleMessage(UFG::UIHKMinigameScreen *this, unsigned int msgId, UFG::UIMessage *msg)
{
  bool result; // al

  if ( msgId == UI_HASH_BUTTON_START_PRESSED_30 )
  {
    if ( (unsigned int)UFG::FlowController::GetCurrentState(&UFG::gFlowController) == uidGameStateInGame_13
      && !(unsigned __int8)UFG::UI::IsGamePaused()
      && !UFG::UIScreenManagerBase::getScreen(
            (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
            "NISPause") )
    {
      UFG::UI::PauseGame("NISPause");
      return 1;
    }
    return 1;
  }
  if ( msgId == UI_HASH_CLEANUPMINIGAME_20 || msgId == UI_HASH_GAME_OVER_20 )
  {
    UFG::UIScreenManagerBase::queuePopScreen(
      (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
      this->mScreenUID);
    return 1;
  }
  if ( msgId == UI_HASH_SETFINISHED_20 )
  {
    this->mFinished = 1;
    result = 1;
  }
  else if ( msgId == UI_HASH_RESUME_20 )
  {
    this->mProgressionState = 0;
    result = 1;
  }
  else
  {
    result = UFG::UIScreen::handleMessage((UFG::UIScreen *)&this->vfptr, msgId, msg);
  }
  return result;
}

// File Line: 100
// RVA: 0x620F70
void __fastcall UFG::UIHKMinigameScreen::handleExiting(UFG::UIHKMinigameScreen *this)
{
  UFG::UIHKMinigameScreen *v1; // rdi
  int v2; // eax
  unsigned int v3; // esi
  unsigned int v4; // ebp
  UFG::allocator::free_link *v5; // rax
  __int64 v6; // rax
  __int64 v7; // rbx
  UFG::allocator::free_link *v8; // rax
  __int64 v9; // rax
  signed int v10; // eax

  v1 = this;
  this->mProgressionState = 1;
  v2 = UFG::qStringCompare(this->m_screenName, "PhoneTraceMinigame", -1);
  v3 = UI_HASH_RESUME_20;
  if ( v2 )
  {
    v4 = UI_HASH_SETFINISHED_20;
    v8 = UFG::qMemoryPool::Allocate(
           &gScaleformMemoryPool,
           0x128ui64,
           "UIScreenDialogBox::createTwoButtonDialog",
           0i64,
           1u);
    if ( v8 )
    {
      UFG::UIScreenDialogBox::UIScreenDialogBoxData::UIScreenDialogBoxData((UFG::UIScreenDialogBox::UIScreenDialogBoxData *)v8);
      v7 = v9;
    }
    else
    {
      v7 = 0i64;
    }
  }
  else
  {
    v4 = UI_HASH_CLEANUPMINIGAME_20;
    v5 = UFG::qMemoryPool::Allocate(
           &gScaleformMemoryPool,
           0x128ui64,
           "UIScreenDialogBox::createTwoButtonDialog",
           0i64,
           1u);
    if ( v5 )
    {
      UFG::UIScreenDialogBox::UIScreenDialogBoxData::UIScreenDialogBoxData((UFG::UIScreenDialogBox::UIScreenDialogBoxData *)v5);
      v7 = v6;
    }
    else
    {
      v7 = 0i64;
    }
  }
  UFG::qString::Set((UFG::qString *)(v7 + 248), "DialogBox");
  *(_DWORD *)(v7 + 16) = 2;
  *(_QWORD *)(v7 + 8) = v1;
  UFG::qString::Set((UFG::qString *)(v7 + 24), &customWorldMapCaption);
  UFG::qString::Set((UFG::qString *)(v7 + 64), "$MINIGAME_CONFIRM_EXIT");
  *(_DWORD *)(v7 + 20) = 2;
  *(_DWORD *)(v7 + 104) = v4;
  UFG::qString::Set((UFG::qString *)(v7 + 120), "$COMMON_OK");
  *(_DWORD *)(v7 + 108) = v3;
  UFG::qString::Set((UFG::qString *)(v7 + 160), "$COMMON_CANCEL");
  *(_DWORD *)(v7 + 288) = (signed int)gUIHorizontalResolution;
  v10 = (signed int)gUIVerticalResolution;
  *(_BYTE *)(v7 + 244) = 0;
  *(_DWORD *)(v7 + 292) = v10;
  UFG::UIScreenManagerBase::queuePushScreen(
    (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
    *(const char **)(v7 + 272),
    -1)->m_commandData = (UFG::UICommandData *)v7;
}

