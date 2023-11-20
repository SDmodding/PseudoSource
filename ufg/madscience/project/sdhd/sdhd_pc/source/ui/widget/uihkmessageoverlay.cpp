// File Line: 90
// RVA: 0x5C97C0
void __fastcall UFG::UIHKMessageOverlay::~UIHKMessageOverlay(UFG::UIHKMessageOverlay *this)
{
  UFG::UIHKMessageOverlay *v1; // rbx
  UFG::OnlineManager *v2; // rax
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *v3; // rdx
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *v4; // rcx
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *v5; // rax

  v1 = this;
  this->vfptr = (UFG::OnlineManagerObserverVtbl *)&UFG::UIHKMessageOverlay::`vftable;
  v2 = UFG::OnlineManager::Instance();
  UFG::OSuiteManager::UnRegisterObserver(v2, (UFG::OnlineManagerObserver *)&v1->vfptr);
  v1->vfptr = (UFG::OnlineManagerObserverVtbl *)&UFG::OnlineManagerObserver::`vftable;
  v3 = (UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *)&v1->mPrev;
  v4 = v1->mPrev;
  v5 = v1->mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  v3->mPrev = v3;
  v3->mNext = v3;
}

// File Line: 104
// RVA: 0x621280
bool __fastcall UFG::UIHKMessageOverlay::handleMessage(UFG::UIHKMessageOverlay *this, UFG::UIScreen *screen, unsigned int msgId, UFG::UIMessage *msg)
{
  UFG::UIHKMessageOverlay *v4; // rbx
  int v5; // ebx
  const char *v6; // rax
  UFG::GameSaveLoad *v7; // rax
  const char *v8; // r8
  UFG::qString v10; // [rsp+48h] [rbp-30h]

  v4 = this;
  if ( msgId == UI_HASH_CORRUPT_GAME_OPTIONS_9 )
  {
    UFG::UIScreenDialogBox::createOneButtonDialog(
      0i64,
      &customWorldMapCaption,
      "$COMMON_TRC_CORRUPT_GAME_OPTIONS",
      "$COMMON_OK_UPPERCASE",
      0x6826596Cu,
      1,
      "DialogBox");
    return 0;
  }
  if ( msgId == UI_HASH_CORRUPT_PHOTO_9 )
  {
    UFG::UIScreenDialogBox::createOneButtonDialog(
      0i64,
      &customWorldMapCaption,
      "$COMMON_TRC_CORRUPT_PHOTO",
      "$COMMON_OK_UPPERCASE",
      0x6826596Cu,
      1,
      "DialogBox");
    return 0;
  }
  if ( msgId == UI_HASH_CORRUPT_SAVE_SLOT_9 )
  {
    v5 = UFG::HDDmanager::mInstance->m_iSlotNum;
    if ( v5 == 4 )
    {
      UFG::UIScreenDialogBox::createOneButtonDialog(
        0i64,
        &customWorldMapCaption,
        "$COMMON_TRC_CORRUPT_AUTOSAVE_PS3",
        "$COMMON_OK_UPPERCASE",
        0x6826596Cu,
        1,
        "DialogBox");
    }
    else
    {
      UFG::qString::qString(&v10);
      v6 = UFG::UI::LocalizeText("COMMON_TRC_CORRUPT_SAVEGAME_PS3");
      UFG::qString::Set(&v10, v6);
      UFG::qString::Format(&v10, v10.mData, (unsigned int)(v5 + 1));
      UFG::UIScreenDialogBox::createOneButtonDialog(
        0i64,
        &customWorldMapCaption,
        v10.mData,
        "$COMMON_OK_UPPERCASE",
        0x6826596Cu,
        1,
        "DialogBox");
      UFG::qString::~qString(&v10);
    }
    return 0;
  }
  if ( msgId == 1747343724 )
  {
LABEL_12:
    v7 = UFG::GameSaveLoad::Instance();
    UFG::GameSaveLoad::AbortCurrentOperation(v7);
    return 0;
  }
  if ( msgId == UI_HASH_MESSAGEOVERLAY_SKIP_SAVING_9 )
  {
    UFG::HDDmanager::mInstance->m_eSaveLoadPermission &= 0xFFFFFFFD;
    goto LABEL_12;
  }
  if ( msgId == UI_HASH_SIGNED_IN_USER_HAS_NO_ONLINE_ACCOUNT_9 )
  {
    UFG::UI::TryNISPause();
    v8 = "$COMMON_TRC_PC_SIGNED_IN_USER_HAS_NO_ONLINE_ACCOUNT";
    goto LABEL_26;
  }
  if ( msgId != UI_HASH_ACTIVE_CONTROLLER_DISCONNECTED_46 )
  {
    if ( msgId == UI_HASH_ACTIVE_CONTROLLER_RECONNECTED_46 )
      return 0;
    if ( msgId == UI_HASH_DIALOG_OK_CONTROLLER_DISCONNECTED_9 )
    {
      this->m_bDisconnectedDialogUp = 0;
      return 0;
    }
    if ( msgId != UI_HASH_MESSAGEOVERLAY_CONTENT_DOWNLOADED_STEAM_9 )
      return 0;
    v8 = "$COMMON_DLC_INSTALLED_RESTART_PC";
LABEL_26:
    UFG::UIScreenDialogBox::createOKDialog(0i64, &customWorldMapCaption, v8, 1);
    return 0;
  }
  if ( !UFG::UIScreenDialogBox::m_iDialogBoxRefCount )
    this->m_bDisconnectedDialogUp = 0;
  if ( !this->m_bDisconnectedDialogUp && UFG::UIHKMessageOverlay::HandleControllerDisconnect() )
    v4->m_bDisconnectedDialogUp = 1;
  return 0;
}

// File Line: 597
// RVA: 0x5EC1A0
char __fastcall UFG::UIHKMessageOverlay::HandleSigninChange()
{
  UFG::UIScreen *v0; // rbx

  v0 = UFG::UIScreenManagerBase::getScreen(
         (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
         "Splash");
  UFG::UIScreenManagerBase::getTopScreen((UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr);
  if ( v0
    || (unsigned int)UFG::FlowController::GetCurrentState(&UFG::gFlowController) == uidGameStateInGame_13
    && ((unsigned __int8)UFG::UI::IsGamePaused()
     || UFG::UIScreenManagerBase::getScreen(
          (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
          "NISPause")
     || UFG::UI::PauseGame("NISPause"))
    || (unsigned int)UFG::FlowController::GetCurrentState(&UFG::gFlowController) == uidGameStateFE_13 )
  {
    return 1;
  }
  UFG::UIHKScreenHud::mHandleSigninChange = 1;
  return 0;
}

// File Line: 660
// RVA: 0x5EA6F0
char __fastcall UFG::UIHKMessageOverlay::HandleControllerDisconnect()
{
  int v0; // ebx
  UFG::UIScreen *v1; // rax
  bool v2; // al
  UFG::UIScreen *v3; // rax
  UFG::UIScreen *v4; // rax
  char result; // al
  UFG::UIScreen *v6; // rax

  if ( UFG::UIHK_NISOverlay::m_curtains.m_state )
  {
    UFG::UI::gHandleControllerDisconnectHack = 1;
    result = 0;
  }
  else
  {
    if ( UFG::UI::TryNISPause() )
    {
      v6 = UFG::UIScreenManagerBase::getScreen(
             (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
             "SaveLoad");
      if ( v6 && *(_DWORD *)v6[1].m_screenName != -1 )
      {
LABEL_17:
        UFG::UI::gHandleControllerDisconnectHack = 1;
        return 0;
      }
    }
    else
    {
      v0 = UFG::FlowController::GetCurrentState(&UFG::gFlowController);
      v1 = UFG::UIScreenManagerBase::getScreen(
             (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
             "SaveLoad");
      v2 = v1 && *(_DWORD *)v1[1].m_screenName != -1;
      if ( v0 == uidGameStateLoadGame_13 || v0 == uidGameStateRestoreCheckpoint_13 || v2 )
        goto LABEL_17;
      if ( v0 == uidGameStateFE_13 && UFG::UIScreenManager::s_instance )
      {
        if ( !UFG::UIScreenManagerBase::getTopScreen((UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr) )
          goto LABEL_17;
        v3 = UFG::UIScreenManagerBase::getScreen(
               (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
               "MainMenu");
        if ( v3 )
        {
          if ( BYTE2(v3[4].m_screenNameHash) )
            goto LABEL_17;
        }
        v4 = UFG::UIScreenManagerBase::getScreen(
               (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
               "Splash");
        if ( v4 )
        {
          if ( LODWORD(v4[1].vfptr) == 11 )
            goto LABEL_17;
        }
      }
    }
    UFG::UIScreenDialogBox::createOneButtonDialog(
      0i64,
      &customWorldMapCaption,
      "$COMMON_ACTIVE_CONTROLLER_DISCONNECTED",
      "$COMMON_OK",
      UI_HASH_DIALOG_OK_CONTROLLER_DISCONNECTED_9,
      1,
      "DialogBox");
    result = 1;
  }
  return result;
}

