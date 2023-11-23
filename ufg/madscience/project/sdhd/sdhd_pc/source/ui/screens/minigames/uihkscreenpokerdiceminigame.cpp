// File Line: 45
// RVA: 0x5C6E80
void __fastcall UFG::UIHKScreenPokerDiceMinigame::UIHKScreenPokerDiceMinigame(UFG::UIHKScreenPokerDiceMinigame *this)
{
  UFG::AIScriptInterfaceComponent *ComponentOfType; // rdi
  UFG::GameStatTracker *v3; // rax
  UFG::GameSnapshot *TimeStat; // rax
  ASymbol *v5; // rax
  UFG::TSCharacter *instance; // rax
  hkgpIndexedMeshDefinitions::Edge *v7; // rdx
  hkgpIndexedMesh::EdgeBarrier *v8; // rcx
  ASymbol *v9; // rax
  UFG::SimObject *m_pPointer; // rdi
  UFG::qWiseSymbol *v11; // rax
  UFG::qWiseSymbol *v12; // rax
  UFG::qSymbol result; // [rsp+48h] [rbp+10h] BYREF
  UFG::qSymbol v14; // [rsp+50h] [rbp+18h] BYREF

  this->mPrev = &this->UFG::qNode<UFG::UIScreen,UFG::UIScreen>;
  this->mNext = &this->UFG::qNode<UFG::UIScreen,UFG::UIScreen>;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIScreen::`vftable;
  ComponentOfType = 0i64;
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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKTaskableScreen::`vftable;
  this->mFinished = 0;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKMinigameScreen::`vftable;
  *(_QWORD *)&this->mfAlphaValue = 1109393408i64;
  ++UFG::UIHKMinigameScreen::mNumMinigameScreens;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenPokerDiceMinigame::`vftable;
  UFG::UIHKDepthOfFieldWidget::UIHKDepthOfFieldWidget(&this->DOF);
  v3 = UFG::GameStatTracker::Instance();
  TimeStat = UFG::GameStatTracker::GetTimeStat(v3, TimeSpentPlayingPokerDice);
  UFG::SimpleTimer::Resume((UFG::SimpleTimer *)TimeStat);
  *(_WORD *)&this->bRoundHasEnded = 0;
  this->mCurrentTile = 0;
  this->mbEnableProgression = 1;
  *(_WORD *)&this->mbPayoutsShown = 0;
  this->mSavedControllerMode = IM_INVALID;
  *(_QWORD *)&this->mnCurrentTotalWins = 0i64;
  this->mnCurrentProfit = 0;
  if ( LocalPlayer )
    ComponentOfType = (UFG::AIScriptInterfaceComponent *)UFG::SimObject::GetComponentOfType(
                                                           LocalPlayer,
                                                           UFG::AIScriptInterfaceComponent::_TypeUID);
  this->mPlayerAISIC = ComponentOfType;
  v5 = (ASymbol *)UFG::qSymbol::create_from_string(&result, "PokerDice1-gambleHouse:spawn");
  instance = UFG::TSCharacter::find_instance(v5);
  if ( !instance )
  {
    v9 = (ASymbol *)UFG::qSymbol::create_from_string(&v14, "PokerDice2-gambleHouse:spawn");
    instance = UFG::TSCharacter::find_instance(v9);
  }
  m_pPointer = instance->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    this->mHouseAAC = (UFG::ActorAudioComponent *)UFG::SimObject::GetComponentOfType(
                                                    instance->mpSimObj.m_pPointer,
                                                    UFG::ActorAudioComponent::_TypeUID);
    this->mHouseAISIC = (UFG::AIScriptInterfaceComponent *)UFG::SimObject::GetComponentOfType(
                                                             m_pPointer,
                                                             UFG::AIScriptInterfaceComponent::_TypeUID);
  }
  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(v8, v7) )
  {
    v11 = UFG::qWiseSymbol::create_from_string((UFG::qWiseSymbol *)&result, "mg_poker");
    UFG::TiDo::LoadWwiseBank(v11);
    _((AMD_HD3D *)result.mUID);
    v12 = UFG::qWiseSymbol::create_from_string((UFG::qWiseSymbol *)&result, "poi_gamble_mahjong");
    UFG::TiDo::LoadWwiseBank(v12);
    _((AMD_HD3D *)result.mUID);
    ((void (__fastcall *)(UFG::TiDo *, const char *, const char *))UFG::TiDo::m_pInstance->vfptr[1].UpdateListenerTriggerRegions)(
      UFG::TiDo::m_pInstance,
      "ms_minigames",
      "poker");
  }
}

// File Line: 91
// RVA: 0x5CC3E0
void __fastcall UFG::UIHKScreenPokerDiceMinigame::~UIHKScreenPokerDiceMinigame(UFG::UIHKScreenPokerDiceMinigame *this)
{
  UFG::UIScreenTextureManager *v2; // rax
  UFG::GameStatTracker *v3; // rax
  UFG::GameSnapshot *TimeStat; // rax
  hkgpIndexedMeshDefinitions::Edge *v5; // rdx
  hkgpIndexedMesh::EdgeBarrier *v6; // rcx
  UFG::qWiseSymbol *v7; // rax
  UFG::qWiseSymbol *v8; // rax
  UFG::qWiseSymbol result; // [rsp+48h] [rbp+10h] BYREF

  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenPokerDiceMinigame::`vftable;
  v2 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v2, "PokerDiceMinigame");
  v3 = UFG::GameStatTracker::Instance();
  TimeStat = UFG::GameStatTracker::GetTimeStat(v3, TimeSpentPlayingPokerDice);
  UFG::PersistentData::Time::EndTimer(TimeStat->mTimes);
  UFG::UIHKScreenPokerDiceMinigame::miLimit = 5000;
  UFG::UIHKScreenPokerDiceMinigame::mbMissionMode = 0;
  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(v6, v5) )
  {
    v7 = UFG::qWiseSymbol::create_from_string(&result, "mg_poker");
    UFG::TiDo::UnloadWwiseBank(v7);
    _((AMD_HD3D *)result.mUID);
    v8 = UFG::qWiseSymbol::create_from_string(&result, "poi_gamble_mahjong");
    UFG::TiDo::UnloadWwiseBank(v8);
    _((AMD_HD3D *)result.mUID);
    ((void (__fastcall *)(UFG::TiDo *, const char *, const char *))UFG::TiDo::m_pInstance->vfptr[1].UpdateListenerTriggerRegions)(
      UFG::TiDo::m_pInstance,
      "ms_minigames",
      "none");
  }
  UFG::GameCameraComponent::EndDOFOverride(DOFOverridePriority_0);
  UFG::UIHKMinigameScreen::~UIHKMinigameScreen(this);
}

// File Line: 108
// RVA: 0x635890
void __fastcall UFG::UIHKScreenPokerDiceMinigame::init(
        UFG::UIHKScreenPokerDiceMinigame *this,
        UFG::UICommandData *data)
{
  Scaleform::GFx::Movie *pObject; // rdi
  UFG::GameStatTracker *v4; // rax
  int Stat; // ebx
  double v6; // xmm6_8
  bool v7; // bl
  bool m_IsKeyboardController; // bl
  UFG::UIHKInfoPopupWidget *v9; // rcx
  Scaleform::GFx::Value pargs; // [rsp+30h] [rbp-D0h] BYREF
  Scaleform::GFx::Value ptr; // [rsp+60h] [rbp-A0h] BYREF
  char v12[16]; // [rsp+90h] [rbp-70h] BYREF
  __int64 v13; // [rsp+A0h] [rbp-60h]
  __int64 v14; // [rsp+A8h] [rbp-58h]
  double v15; // [rsp+B0h] [rbp-50h]
  char v16[16]; // [rsp+C0h] [rbp-40h] BYREF
  __int64 v17; // [rsp+D0h] [rbp-30h]
  __int64 v18; // [rsp+D8h] [rbp-28h]
  __int64 v19; // [rsp+E0h] [rbp-20h]
  __int64 v20; // [rsp+F0h] [rbp-10h]

  v20 = -2i64;
  UFG::UIScreen::init(this, data);
  pObject = this->mRenderable->m_movie.pObject;
  v4 = UFG::GameStatTracker::Instance();
  Stat = UFG::GameStatTracker::GetStat(v4, Money);
  `eh vector constructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  if ( (ptr.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
      ptr.pObjectInterface,
      &ptr,
      ptr.mValue);
    ptr.pObjectInterface = 0i64;
  }
  ptr.Type = VT_Number;
  ptr.mValue.NValue = (double)Stat;
  v6 = (double)UFG::UIHKScreenPokerDiceMinigame::miLimit;
  if ( (v14 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v13 + 16i64))(v13, v12, COERCE_DOUBLE(*(_QWORD *)&v15));
    v13 = 0i64;
  }
  LODWORD(v14) = 5;
  v15 = v6;
  v7 = UFG::UIHKScreenPokerDiceMinigame::mbMissionMode;
  if ( (v18 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v17 + 16i64))(v17, v16, v19);
    v17 = 0i64;
  }
  LODWORD(v18) = 2;
  LOBYTE(v19) = v7;
  if ( pObject )
  {
    pargs.pObjectInterface = 0i64;
    pargs.Type = VT_Undefined;
    m_IsKeyboardController = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController;
    pargs.Type = VT_Boolean;
    pargs.mValue.BValue = m_IsKeyboardController;
    Scaleform::GFx::Movie::Invoke(pObject, "Show_PC", 0i64, &pargs, 1u);
    Scaleform::GFx::Movie::Invoke(pObject, "init", 0i64, &ptr, 3u);
    if ( (pargs.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        pargs.mValue);
      pargs.pObjectInterface = 0i64;
    }
    pargs.Type = VT_Undefined;
  }
  v9 = UFG::UIHKScreenHud::InfoPopup;
  if ( (unsigned int)(UFG::UIHKScreenHud::InfoPopup->mState - 4) <= 1 )
    UFG::UIHKScreenHud::InfoPopup->mState = STATE_IDLE;
  if ( v9->mState )
    v9->mState = STATE_ROOT_MENU;
  `eh vector destructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 133
// RVA: 0x63F440
void __fastcall UFG::UIHKScreenPokerDiceMinigame::update(UFG::UIHKScreenPokerDiceMinigame *this, float elapsed)
{
  Scaleform::GFx::Movie *pObject; // rdi
  bool m_IsKeyboardController; // si
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-50h] BYREF

  if ( !UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "NISPause") )
  {
    pObject = this->mRenderable->m_movie.pObject;
    if ( pObject )
    {
      pargs.pObjectInterface = 0i64;
      pargs.Type = VT_Undefined;
      m_IsKeyboardController = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController;
      pargs.Type = VT_Boolean;
      pargs.mValue.BValue = m_IsKeyboardController;
      Scaleform::GFx::Movie::Invoke(pObject, "Show_PC", 0i64, &pargs, 1u);
      Scaleform::GFx::Movie::Invoke(pObject, "mainLoop", 0i64, 0i64, 0);
      if ( (pargs.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
          pargs.pObjectInterface,
          &pargs,
          pargs.mValue);
        pargs.pObjectInterface = 0i64;
      }
      pargs.Type = VT_Undefined;
    }
    UFG::UIScreen::update(this, elapsed);
    UFG::UIHKInfoPopupWidget::Update(UFG::UIHKScreenHud::InfoPopup, this, elapsed);
  }
}

// File Line: 156
// RVA: 0x629C30
_BOOL8 __fastcall UFG::UIHKScreenPokerDiceMinigame::handleMessage(
        UFG::UIHKScreenPokerDiceMinigame *this,
        unsigned int msgId,
        UFG::UIMessage *msg)
{
  Scaleform::GFx::Movie *pObject; // r15
  int NValue; // r13d
  hkgpIndexedMeshDefinitions::Edge *v8; // rdx
  hkgpIndexedMesh::EdgeBarrier *v9; // rcx
  bool v10; // bl
  unsigned int v11; // eax
  unsigned int v12; // eax
  int v13; // ebx
  UFG::GameStatTracker *v14; // rax
  int v15; // edi
  UFG::GameStatTracker *v16; // rax
  UFG::qSymbol *v17; // rbx
  UFG::qSymbol *v18; // rax
  UFG::InputActionData *v19; // rcx
  UFG::InputActionData *v20; // rcx
  int v21; // ebx
  UFG::GameStatTracker *v22; // rax
  int v23; // edi
  UFG::GameStatTracker *v24; // rax
  UFG::qSymbol *v25; // rbx
  UFG::qSymbol *v26; // rax
  Scaleform::GFx::Value *p_ptr; // rcx
  UFG::GameStatTracker *v28; // rax
  int v29; // r13d
  UFG::GameStatTracker *v30; // rax
  int Stat; // edi
  UFG::GameStatTracker *v32; // rax
  int v33; // edi
  UFG::GameStatTracker *v34; // rax
  UFG::GameStatTracker *v35; // rax
  UFG::GameStatTracker *v36; // rax
  UFG::OSuiteLeaderboardManager *v37; // rax
  UFG::OSuiteLeaderboardData *LeaderboardDataUsingLeaderboardName; // rax
  UFG::qSymbol *v39; // rbx
  UFG::qSymbol *v40; // rax
  UFG::GameStatTracker *v41; // rax
  UFG::GameStatTracker *v42; // rax
  int v43; // edi
  UFG::OSuiteLeaderboardManager *v44; // rax
  UFG::OSuiteLeaderboardData *v45; // rax
  int v46; // ebx
  UFG::GameStatTracker *v47; // rax
  int v48; // edi
  UFG::GameStatTracker *v49; // rax
  int v50; // edi
  UFG::GameStatTracker *v51; // rax
  UFG::GameStatTracker *v52; // rax
  UFG::qSymbol *v53; // rbx
  UFG::qSymbol *v54; // rax
  UFG::GameStatTracker *v55; // rax
  UFG::GameStatTracker *v56; // rax
  int v57; // edi
  UFG::OSuiteLeaderboardManager *v58; // rax
  UFG::OSuiteLeaderboardData *v59; // rax
  SSClass *v60; // rbx
  ASymbol *v61; // rdi
  __int64 v62; // rax
  Scaleform::GFx::Value v64; // [rsp+30h] [rbp-A9h] BYREF
  Scaleform::GFx::Value ptr; // [rsp+60h] [rbp-79h] BYREF
  Scaleform::GFx::Value pval; // [rsp+90h] [rbp-49h] BYREF
  UFG::qSymbol v67; // [rsp+C0h] [rbp-19h] BYREF
  Scaleform::GFx::Value v68; // [rsp+C8h] [rbp-11h] BYREF
  __int64 v69; // [rsp+F8h] [rbp+1Fh]
  UFG::qSymbol result; // [rsp+140h] [rbp+67h] BYREF
  __int64 v71; // [rsp+158h] [rbp+7Fh] BYREF

  v69 = -2i64;
  pObject = this->mRenderable->m_movie.pObject;
  pval.pObjectInterface = 0i64;
  pval.Type = VT_Undefined;
  Scaleform::GFx::Movie::GetVariable(pObject, &pval, "g_nGameStatus");
  NValue = (int)pval.mValue.NValue;
  v68.pObjectInterface = 0i64;
  v68.Type = VT_Undefined;
  Scaleform::GFx::Movie::GetVariable(pObject, &v68, "gbAllowControls");
  if ( !pObject )
  {
    v10 = UFG::UIScreen::handleMessage(this, msgId, msg);
    goto LABEL_112;
  }
  if ( msgId == UI_HASH_PLAYSOUND_20 )
  {
    if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(v9, v8) )
    {
      UFG::qString::qString((UFG::qString *)&v64, (UFG::qString *)&msg[1]);
      v11 = UFG::TiDo::CalcWwiseUid(*(const char **)&v64.Type);
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, v11, 0i64, 0, 0i64);
      UFG::qString::~qString((UFG::qString *)&v64);
    }
    goto LABEL_111;
  }
  if ( msgId != UI_HASH_PLAYDIALOGUE_20 )
  {
    if ( msgId == UI_HASH_SETFINISHED_20 )
    {
      Scaleform::GFx::Movie::GetVariable(pObject, &pval, "g_nPocketMoney");
      v13 = (int)pval.mValue.NValue;
      v14 = UFG::GameStatTracker::Instance();
      v15 = UFG::GameStatTracker::GetStat(v14, Money) - v13;
      v16 = UFG::GameStatTracker::Instance();
      UFG::GameStatTracker::SetStat(v16, Money, v13);
      v17 = UFG::qSymbol::create_from_string(&result, "Exit");
      v18 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&v71, "PokerDice");
      UFG::GameStatAction::Money::SendTransactionTelemetry(v18, v17, v15);
      this->mFinished = 1;
      goto LABEL_111;
    }
    if ( msgId == UI_HASH_DPAD_LEFT_PRESSED_30 || msgId == UI_HASH_THUMBSTICK_LEFT_LEFT_30 )
    {
      if ( !v68.mValue.BValue || this->mbKidnapperCase || NValue )
        goto LABEL_111;
      `eh vector constructor iterator(&v64, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      ptr.pObjectInterface = 0i64;
      ptr.Type = VT_Number;
      ptr.mValue.NValue = DOUBLE_N1_0;
      Scaleform::GFx::Value::operator=(&v64, &ptr);
      if ( (ptr.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
          ptr.pObjectInterface,
          &ptr,
          ptr.mValue);
        ptr.pObjectInterface = 0i64;
      }
      ptr.Type = VT_Undefined;
      Scaleform::GFx::Movie::Invoke(pObject, "adjustBet", 0i64, &v64, 1u);
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x6A29BF1Du, 0i64, 0, 0i64);
    }
    else
    {
      if ( msgId != UI_HASH_DPAD_RIGHT_PRESSED_30 && msgId != UI_HASH_THUMBSTICK_LEFT_RIGHT_30 )
      {
        if ( msgId == UI_HASH_BUTTON_ACCEPT_PRESSED_30 )
        {
          v19 = UFG::ActionDef_UIR2Repeat.mDataPerController[UFG::gActiveControllerNum];
          if ( !v19 || !v19->mActionTrue )
          {
            v20 = UFG::ActionDef_UIL2Repeat.mDataPerController[UFG::gActiveControllerNum];
            if ( !v20 || !v20->mActionTrue )
            {
              if ( !v68.mValue.BValue || !this->mbEnableProgression )
                goto LABEL_111;
              if ( NValue == -1 )
              {
                UFG::UIScreenDialogBox::createOKDialog(this, &customCaption, "$HUD_MINIGAME_INSUFFICIENT_MONEY", 0);
                goto LABEL_111;
              }
              if ( (unsigned int)NValue <= 2 )
              {
                if ( this->mbPayoutsShown )
                  UFG::UIHKScreenPokerDiceMinigame::hideShowPayouts(this, pObject);
                if ( !NValue )
                {
                  *(_WORD *)&this->bRoundHasEnded = 256;
                  if ( UFG::HudAudio::m_instance )
                    UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x1666C41Eu, 0i64, 0, 0i64);
                  if ( !this->mbKidnapperCase )
                  {
                    v64.pObjectInterface = 0i64;
                    v64.Type = VT_Undefined;
                    Scaleform::GFx::Movie::GetVariable(pObject, &v64, "g_nPocketMoney");
                    v21 = (int)v64.mValue.NValue;
                    v22 = UFG::GameStatTracker::Instance();
                    v23 = UFG::GameStatTracker::GetStat(v22, Money) - v21;
                    v24 = UFG::GameStatTracker::Instance();
                    UFG::GameStatTracker::SetStat(v24, Money, v21);
                    v25 = UFG::qSymbol::create_from_string(&result, "Bet");
                    v26 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&v71, "PokerDice");
                    UFG::GameStatAction::Money::SendTransactionTelemetry(v26, v25, v23);
                    if ( (v64.Type & 0x40) != 0 )
                    {
                      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&v64.pObjectInterface->vfptr->gap8[8])(
                        v64.pObjectInterface,
                        &v64,
                        v64.mValue);
                      v64.pObjectInterface = 0i64;
                    }
                    v64.Type = VT_Undefined;
                  }
                  goto LABEL_40;
                }
                if ( (unsigned int)(NValue - 1) > 1 || this->mCurrentTile == 5 )
                {
LABEL_40:
                  Scaleform::GFx::Movie::Invoke(pObject, "setTransitionMode", 0i64, 0i64, 0);
                  `eh vector constructor iterator(
                    &ptr,
                    0x30ui64,
                    1,
                    (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
                  v64.pObjectInterface = 0i64;
                  v64.Type = VT_Number;
                  v64.mValue.NValue = (double)(NValue + 1);
                  Scaleform::GFx::Value::operator=(&ptr, &v64);
                  if ( (v64.Type & 0x40) != 0 )
                  {
                    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&v64.pObjectInterface->vfptr->gap8[8])(
                      v64.pObjectInterface,
                      &v64,
                      v64.mValue);
                    v64.pObjectInterface = 0i64;
                  }
                  v64.Type = VT_Undefined;
                  Scaleform::GFx::Movie::Invoke(pObject, "setState", 0i64, &ptr, 1u);
                  UFG::AIScriptInterfaceComponent::BeginCommandActionRequest(this->mPlayerAISIC);
                  if ( UFG::AIScriptInterfaceComponent::GiveCommand(
                         this->mPlayerAISIC,
                         eSCRIPT_COMMAND_SUBMIT_ACTION_REQUEST) )
                  {
                    UFG::AIScriptInterfaceComponent::AddArgument(this->mPlayerAISIC, "PokerDiceDrawTiles1");
                    UFG::AIScriptInterfaceComponent::AddArgument(this->mPlayerAISIC, "DrawTiles1");
                  }
                  UFG::AIScriptInterfaceComponent::BeginCommandActionRequest(this->mHouseAISIC);
                  if ( UFG::AIScriptInterfaceComponent::GiveCommand(
                         this->mHouseAISIC,
                         eSCRIPT_COMMAND_SUBMIT_ACTION_REQUEST) )
                  {
                    UFG::AIScriptInterfaceComponent::AddArgument(this->mHouseAISIC, "PokerDiceDrawTiles2");
                    UFG::AIScriptInterfaceComponent::AddArgument(this->mHouseAISIC, "DrawTiles2");
                  }
                  p_ptr = &ptr;
                  goto LABEL_110;
                }
LABEL_93:
                v10 = UFG::UIHKMinigameScreen::handleMessage(this, msgId, msg);
                goto LABEL_112;
              }
              v64.pObjectInterface = 0i64;
              v64.Type = VT_Undefined;
              Scaleform::GFx::Movie::GetVariable(pObject, &v64, "gameComplete_mc._visible");
              if ( v64.mValue.BValue )
              {
                Scaleform::GFx::Movie::Invoke(pObject, "resetGame", 0i64, &customCaption);
                UFG::AIScriptInterfaceComponent::BeginCommandActionRequest(this->mHouseAISIC);
                if ( UFG::AIScriptInterfaceComponent::GiveCommand(
                       this->mHouseAISIC,
                       eSCRIPT_COMMAND_SUBMIT_ACTION_REQUEST) )
                {
                  UFG::AIScriptInterfaceComponent::AddArgument(this->mHouseAISIC, "PokerDiceMix");
                  UFG::AIScriptInterfaceComponent::AddArgument(this->mHouseAISIC, "Mix");
                }
                UFG::AIScriptInterfaceComponent::BeginCommandActionRequest(this->mPlayerAISIC);
                if ( UFG::AIScriptInterfaceComponent::GiveCommand(
                       this->mPlayerAISIC,
                       eSCRIPT_COMMAND_SUBMIT_ACTION_REQUEST) )
                {
                  UFG::AIScriptInterfaceComponent::AddArgument(this->mPlayerAISIC, "PokerDiceMix");
                  UFG::AIScriptInterfaceComponent::AddArgument(this->mPlayerAISIC, "Mix");
                }
              }
              if ( (v64.Type & 0x40) != 0 )
              {
                (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&v64.pObjectInterface->vfptr->gap8[8])(
                  v64.pObjectInterface,
                  &v64,
                  v64.mValue);
                v64.pObjectInterface = 0i64;
              }
LABEL_54:
              v64.Type = VT_Undefined;
              goto LABEL_111;
            }
          }
        }
        if ( msgId == UI_HASH_BUTTON_BACK_PRESSED_30 )
        {
          v64.pObjectInterface = 0i64;
          v64.Type = VT_Undefined;
          if ( v68.mValue.BValue && this->mbEnableProgression )
          {
            if ( UFG::HudAudio::m_instance )
              UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xA4E5BFBD, 0i64, 0, 0i64);
            UFG::UIHKMinigameScreen::handleExiting(this);
            goto LABEL_54;
          }
        }
        else
        {
          if ( msgId == UI_HASH_BUTTON_BUTTON1_PRESSED_30 )
          {
            if ( v68.mValue.BValue && NValue > 0 && this->mbEnableProgression )
              UFG::UIHKScreenPokerDiceMinigame::hideShowPayouts(this, pObject);
            goto LABEL_93;
          }
          if ( msgId == UI_HASH_POKERDICEWIN_20 )
          {
            v28 = UFG::GameStatTracker::Instance();
            result.mUID = UFG::GameStatTracker::GetStat(v28, Money);
            UFG::AIScriptInterfaceComponent::BeginCommandActionRequest(this->mHouseAISIC);
            if ( UFG::AIScriptInterfaceComponent::GiveCommand(this->mHouseAISIC, eSCRIPT_COMMAND_SUBMIT_ACTION_REQUEST) )
            {
              UFG::AIScriptInterfaceComponent::AddArgument(this->mHouseAISIC, "PokerDiceLose");
              UFG::AIScriptInterfaceComponent::AddArgument(this->mHouseAISIC, "Lose");
            }
            ptr.pObjectInterface = 0i64;
            ptr.Type = VT_Undefined;
            Scaleform::GFx::Movie::GetVariable(pObject, &ptr, "g_nPocketMoney");
            v29 = (int)ptr.mValue.NValue;
            if ( UFG::HudAudio::m_instance )
              UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x1234D1F7u, 0i64, 0, 0i64);
            v30 = UFG::GameStatTracker::Instance();
            Stat = UFG::GameStatTracker::GetStat(v30, Money);
            v32 = UFG::GameStatTracker::Instance();
            UFG::GameStatTracker::SetStat(v32, Money, v29);
            v33 = Stat - v29;
            if ( v33 < 0 )
              v33 = -v33;
            v34 = UFG::GameStatTracker::Instance();
            UFG::GameStatTracker::ApplyDelta(v34, TotalCashEarned, v33);
            v35 = UFG::GameStatTracker::Instance();
            UFG::GameStatTracker::ApplyDelta(v35, GamblingEarnings, v33);
            v36 = UFG::GameStatTracker::Instance();
            UFG::GameStatTracker::ApplyDelta(v36, PokerDicePlayed, 1);
            UFG::OnlineEventManager::PostEvent((UFG::OnlineEventManager::Event)4, 1);
            v37 = UFG::OSuiteLeaderboardManager::Instance();
            LeaderboardDataUsingLeaderboardName = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(
                                                    v37,
                                                    "StatAwardsMogul");
            UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(LeaderboardDataUsingLeaderboardName, v33);
            v39 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&v71, "Winning");
            v40 = UFG::qSymbol::create_from_string(&v67, "PokerDice");
            UFG::GameStatAction::Money::SendTransactionTelemetry(v40, v39, v33);
            v41 = UFG::GameStatTracker::Instance();
            LODWORD(v39) = UFG::GameStatTracker::GetStat(v41, GamblingLoss);
            v42 = UFG::GameStatTracker::Instance();
            v43 = UFG::GameStatTracker::GetStat(v42, GamblingEarnings) - (_DWORD)v39;
            v44 = UFG::OSuiteLeaderboardManager::Instance();
            v45 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v44, "StatAwardsGambler");
            UFG::DataSynchronizer::SetMaxToGlobalSnapshot(v45, v43);
            *(_WORD *)&this->bRoundHasEnded = 1;
            ++this->mnCurrentTotalWins;
            v64.pObjectInterface = 0i64;
            v64.Type = VT_Undefined;
            Scaleform::GFx::Movie::GetVariable(pObject, &v64, "g_nBet");
            this->mnCurrentProfit += v29 - (int)v64.mValue.NValue - result.mUID;
            if ( (v64.Type & 0x40) != 0 )
            {
              (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&v64.pObjectInterface->vfptr->gap8[8])(
                v64.pObjectInterface,
                &v64,
                v64.mValue);
              v64.pObjectInterface = 0i64;
            }
            v64.Type = VT_Undefined;
            if ( (ptr.Type & 0x40) != 0 )
            {
              (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
                ptr.pObjectInterface,
                &ptr,
                ptr.mValue);
              ptr.pObjectInterface = 0i64;
            }
            ptr.Type = VT_Undefined;
            goto LABEL_93;
          }
          if ( msgId != UI_HASH_POKERDICELOSE_20 )
          {
            if ( msgId == UI_HASH_HOUSEHOLDS_20 )
            {
              v60 = SSBrain::get_class("PokerDice");
              v71 = 0i64;
              v61 = ASymbol::create((ASymbol *)&result, "house_holds_tiles", 0xFFFFFFFF, ATerm_long);
              v62 = (__int64)v60->vfptr->get_metaclass(v60);
              (*(void (__fastcall **)(__int64, ASymbol *, __int64 *, bool, _QWORD, _QWORD))(*(_QWORD *)(v62 + 8) + 104i64))(
                v62 + 8,
                v61,
                &v71,
                v71 != 0,
                0i64,
                0i64);
            }
            goto LABEL_93;
          }
          UFG::AIScriptInterfaceComponent::BeginCommandActionRequest(this->mHouseAISIC);
          if ( UFG::AIScriptInterfaceComponent::GiveCommand(this->mHouseAISIC, eSCRIPT_COMMAND_SUBMIT_ACTION_REQUEST) )
          {
            UFG::AIScriptInterfaceComponent::AddArgument(this->mHouseAISIC, "PokerDiceWin");
            UFG::AIScriptInterfaceComponent::AddArgument(this->mHouseAISIC, "Win");
          }
          v64.pObjectInterface = 0i64;
          v64.Type = VT_Undefined;
          Scaleform::GFx::Movie::GetVariable(pObject, &v64, "g_nPocketMoney");
          v46 = (int)v64.mValue.NValue;
          if ( UFG::HudAudio::m_instance )
            UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x7D608E0Cu, 0i64, 0, 0i64);
          v47 = UFG::GameStatTracker::Instance();
          v48 = UFG::GameStatTracker::GetStat(v47, Money);
          v49 = UFG::GameStatTracker::Instance();
          UFG::GameStatTracker::SetStat(v49, Money, v46);
          v50 = v48 - v46;
          if ( v50 < 0 )
            v50 = -v50;
          v51 = UFG::GameStatTracker::Instance();
          UFG::GameStatTracker::ApplyDelta(v51, GamblingLoss, v50);
          v52 = UFG::GameStatTracker::Instance();
          UFG::GameStatTracker::ApplyDelta(v52, PokerDicePlayed, 1);
          UFG::OnlineEventManager::PostEvent((UFG::OnlineEventManager::Event)4, 1);
          v53 = UFG::qSymbol::create_from_string(&result, "Lost");
          v54 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&v71, "PokerDice");
          UFG::GameStatAction::Money::SendTransactionTelemetry(v54, v53, v50);
          v55 = UFG::GameStatTracker::Instance();
          LODWORD(v53) = UFG::GameStatTracker::GetStat(v55, GamblingLoss);
          v56 = UFG::GameStatTracker::Instance();
          v57 = UFG::GameStatTracker::GetStat(v56, GamblingEarnings) - (_DWORD)v53;
          v58 = UFG::OSuiteLeaderboardManager::Instance();
          v59 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v58, "StatAwardsGambler");
          UFG::DataSynchronizer::SetMaxToGlobalSnapshot(v59, v57);
          *(_WORD *)&this->bRoundHasEnded = 1;
          ++this->mnCurrentTotalLosses;
          ptr.pObjectInterface = 0i64;
          ptr.Type = VT_Undefined;
          Scaleform::GFx::Movie::GetVariable(pObject, &ptr, "g_nBet");
          this->mnCurrentProfit -= (int)ptr.mValue.NValue;
          if ( (ptr.Type & 0x40) != 0 )
          {
            (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
              ptr.pObjectInterface,
              &ptr,
              ptr.mValue);
            ptr.pObjectInterface = 0i64;
          }
          ptr.Type = VT_Undefined;
          if ( (v64.Type & 0x40) != 0 )
          {
            (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&v64.pObjectInterface->vfptr->gap8[8])(
              v64.pObjectInterface,
              &v64,
              v64.mValue);
            v64.pObjectInterface = 0i64;
          }
        }
        v64.Type = VT_Undefined;
        goto LABEL_93;
      }
      if ( !v68.mValue.BValue || this->mbKidnapperCase || NValue )
        goto LABEL_111;
      `eh vector constructor iterator(&v64, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      ptr.pObjectInterface = 0i64;
      ptr.Type = VT_Number;
      ptr.mValue.NValue = DOUBLE_1_0;
      Scaleform::GFx::Value::operator=(&v64, &ptr);
      if ( (ptr.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
          ptr.pObjectInterface,
          &ptr,
          ptr.mValue);
        ptr.pObjectInterface = 0i64;
      }
      ptr.Type = VT_Undefined;
      Scaleform::GFx::Movie::Invoke(pObject, "adjustBet", 0i64, &v64, 1u);
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x6A29BF1Du, 0i64, 0, 0i64);
    }
    p_ptr = &v64;
LABEL_110:
    `eh vector destructor iterator(p_ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    goto LABEL_111;
  }
  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(v9, v8) )
  {
    UFG::qString::qString((UFG::qString *)&v64, (UFG::qString *)&msg[1]);
    if ( this->mHouseAAC )
    {
      v12 = UFG::TiDo::CalcWwiseUid("play_mission");
      UFG::ActorAudioComponent::QueueSpeechExternalMission(this->mHouseAAC, v12, *(const char **)&v64.Type, 0i64, 5u, 0);
    }
    UFG::qString::~qString((UFG::qString *)&v64);
    goto LABEL_93;
  }
LABEL_111:
  v10 = 1;
LABEL_112:
  if ( (v68.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&v68.pObjectInterface->vfptr->gap8[8])(
      v68.pObjectInterface,
      &v68,
      v68.mValue);
    v68.pObjectInterface = 0i64;
  }
  v68.Type = VT_Undefined;
  if ( (pval.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pval.pObjectInterface->vfptr->gap8[8])(
      pval.pObjectInterface,
      &pval,
      pval.mValue);
    pval.pObjectInterface = 0i64;
  }
  return v10;
}

// File Line: 476
// RVA: 0x638940
void __fastcall UFG::UIHKScreenPokerDiceMinigame::lockSelectedTile(
        UFG::UIHKScreenPokerDiceMinigame *this,
        int selectedTile)
{
  Scaleform::GFx::Movie *pObject; // rdi
  __int64 v4; // [rsp+48h] [rbp-1h]
  __int64 v5; // [rsp+50h] [rbp+7h]
  Scaleform::GFx::Value::ValueUnion v6; // [rsp+58h] [rbp+Fh]
  unsigned __int64 ptr; // [rsp+60h] [rbp+17h]
  Scaleform::GFx::Value v8; // [rsp+68h] [rbp+1Fh] BYREF

  pObject = this->mRenderable->m_movie.pObject;
  `eh vector constructor iterator(&v8, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  v4 = 0i64;
  LODWORD(v5) = 5;
  v6.NValue = (double)selectedTile;
  if ( (v8.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&v8.pObjectInterface->vfptr->gap8[8])(
      v8.pObjectInterface,
      &v8,
      v8.mValue);
    v8.pObjectInterface = 0i64;
  }
  v8.Type = v5;
  v8.mValue = v6;
  v8.DataAux = ptr;
  LODWORD(v5) = 0;
  if ( pObject )
    Scaleform::GFx::Movie::Invoke(pObject, "lockSelectedDie", 0i64, &v8, 1u);
  `eh vector destructor iterator(&v8, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 488
// RVA: 0x639D00
void __fastcall UFG::UIHKScreenPokerDiceMinigame::refreshGameData(UFG::UIHKScreenPokerDiceMinigame *this)
{
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value pval; // [rsp+28h] [rbp-38h] BYREF

  pObject = this->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    pval.pObjectInterface = 0i64;
    pval.Type = VT_Undefined;
    Scaleform::GFx::Movie::GetVariable(pObject, &pval, "outPlayerHand0");
    this->mPlayerHandArray[0] = (int)pval.mValue.NValue;
    Scaleform::GFx::Movie::GetVariable(pObject, &pval, "outPlayerHand1");
    this->mPlayerHandArray[1] = (int)pval.mValue.NValue;
    Scaleform::GFx::Movie::GetVariable(pObject, &pval, "outPlayerHand2");
    this->mPlayerHandArray[2] = (int)pval.mValue.NValue;
    Scaleform::GFx::Movie::GetVariable(pObject, &pval, "outPlayerHand3");
    this->mPlayerHandArray[3] = (int)pval.mValue.NValue;
    Scaleform::GFx::Movie::GetVariable(pObject, &pval, "outPlayerHand4");
    this->mPlayerHandArray[4] = (int)pval.mValue.NValue;
    Scaleform::GFx::Movie::GetVariable(pObject, &pval, "outHouseHand0");
    this->mHouseHandArray[0] = (int)pval.mValue.NValue;
    Scaleform::GFx::Movie::GetVariable(pObject, &pval, "outHouseHand1");
    this->mHouseHandArray[1] = (int)pval.mValue.NValue;
    Scaleform::GFx::Movie::GetVariable(pObject, &pval, "outHouseHand2");
    this->mHouseHandArray[2] = (int)pval.mValue.NValue;
    Scaleform::GFx::Movie::GetVariable(pObject, &pval, "outHouseHand3");
    this->mHouseHandArray[3] = (int)pval.mValue.NValue;
    Scaleform::GFx::Movie::GetVariable(pObject, &pval, "outHouseHand4");
    this->mHouseHandArray[4] = (int)pval.mValue.NValue;
    Scaleform::GFx::Movie::GetVariable(pObject, &pval, "outPlayerHeld0");
    this->mPlayerHeldArray[0] = pval.mValue.BValue;
    Scaleform::GFx::Movie::GetVariable(pObject, &pval, "outPlayerHeld1");
    this->mPlayerHeldArray[1] = pval.mValue.BValue;
    Scaleform::GFx::Movie::GetVariable(pObject, &pval, "outPlayerHeld2");
    this->mPlayerHeldArray[2] = pval.mValue.BValue;
    Scaleform::GFx::Movie::GetVariable(pObject, &pval, "outPlayerHeld3");
    this->mPlayerHeldArray[3] = pval.mValue.BValue;
    Scaleform::GFx::Movie::GetVariable(pObject, &pval, "outPlayerHeld4");
    this->mPlayerHeldArray[4] = pval.mValue.BValue;
    Scaleform::GFx::Movie::GetVariable(pObject, &pval, "outHouseHeld0");
    this->mHouseHeldArray[0] = pval.mValue.BValue;
    Scaleform::GFx::Movie::GetVariable(pObject, &pval, "outHouseHeld1");
    this->mHouseHeldArray[1] = pval.mValue.BValue;
    Scaleform::GFx::Movie::GetVariable(pObject, &pval, "outHouseHeld2");
    this->mHouseHeldArray[2] = pval.mValue.BValue;
    Scaleform::GFx::Movie::GetVariable(pObject, &pval, "outHouseHeld3");
    this->mHouseHeldArray[3] = pval.mValue.BValue;
    Scaleform::GFx::Movie::GetVariable(pObject, &pval, "outHouseHeld4");
    this->mHouseHeldArray[4] = pval.mValue.BValue;
    Scaleform::GFx::Movie::GetVariable(pObject, &pval, "g_nSelectedDie");
    if ( (pval.Type & 0x40) != 0 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pval.pObjectInterface->vfptr->gap8[8])(
        pval.pObjectInterface,
        &pval,
        pval.mValue);
  }
}

// File Line: 549
// RVA: 0x63A480
void __fastcall UFG::UIHKScreenPokerDiceMinigame::setAcceptButtonCoords(
        UFG::UIHKScreenPokerDiceMinigame *this,
        UFG::qVector3 *buttonPos,
        int tileNum)
{
  signed int m_flashHeight; // r9d
  UFG::BaseCameraComponent *mCurrentCamera; // rcx
  UFG::Camera *p_mCamera; // rcx
  Scaleform::GFx::Movie *pObject; // rbx
  char v10[16]; // [rsp+30h] [rbp-B8h] BYREF
  __int64 v11; // [rsp+40h] [rbp-A8h]
  Scaleform::GFx::Value::ValueType v12; // [rsp+48h] [rbp-A0h]
  Scaleform::GFx::Value::ValueUnion v13; // [rsp+50h] [rbp-98h]
  unsigned __int64 v14; // [rsp+58h] [rbp-90h]
  char v15[8]; // [rsp+60h] [rbp-88h] BYREF
  double y; // [rsp+68h] [rbp-80h]
  __int64 v17; // [rsp+70h] [rbp-78h]
  UFG::qVector3 result; // [rsp+78h] [rbp-70h] BYREF
  Scaleform::GFx::Value ptr; // [rsp+88h] [rbp-60h] BYREF
  char v20[16]; // [rsp+B8h] [rbp-30h] BYREF
  __int64 v21; // [rsp+C8h] [rbp-20h]
  float x; // [rsp+D0h] [rbp-18h]
  double v23; // [rsp+D8h] [rbp-10h]
  __int64 v24; // [rsp+E0h] [rbp-8h]
  char v25[16]; // [rsp+E8h] [rbp+0h] BYREF
  __int64 v26; // [rsp+F8h] [rbp+10h]
  Scaleform::GFx::Value::ValueType v27; // [rsp+100h] [rbp+18h]
  Scaleform::GFx::Value::ValueUnion v28; // [rsp+108h] [rbp+20h]
  unsigned __int64 v29; // [rsp+110h] [rbp+28h]
  __int64 v30; // [rsp+118h] [rbp+30h]
  UFG::qVector2 viewport_scale; // [rsp+148h] [rbp+60h] BYREF
  void *is_on_screen; // [rsp+158h] [rbp+70h] BYREF

  v30 = -2i64;
  m_flashHeight = UFG::UIScreenManager::s_instance->m_flashHeight;
  viewport_scale.x = (float)(int)UFG::UIScreenManager::s_instance->m_flashWidth;
  viewport_scale.y = (float)m_flashHeight;
  LOBYTE(is_on_screen) = 0;
  mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
  if ( mCurrentCamera )
    p_mCamera = &mCurrentCamera->mCamera;
  else
    p_mCamera = 0i64;
  UFG::Camera::GetScreenCoord(p_mCamera, &result, buttonPos, &viewport_scale, (bool *)&is_on_screen);
  pObject = this->mRenderable->m_movie.pObject;
  this->mCurrentTile = tileNum;
  `eh vector constructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  v11 = 0i64;
  v12 = VT_Number;
  v13.NValue = result.x;
  if ( (ptr.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
      ptr.pObjectInterface,
      &ptr,
      ptr.mValue);
    ptr.pObjectInterface = 0i64;
  }
  ptr.Type = v12;
  ptr.mValue = v13;
  ptr.DataAux = v14;
  v12 = VT_Undefined;
  v17 = 0i64;
  LODWORD(result.x) = 5;
  y = result.y;
  if ( (LOBYTE(x) & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v21 + 16i64))(v21, v20, COERCE_DOUBLE(*(_QWORD *)&v23));
    v21 = 0i64;
  }
  x = result.x;
  v23 = y;
  v24 = v17;
  if ( (LOBYTE(result.x) & 0x40) != 0 )
  {
    v21 = v17;
    (*(void (__fastcall **)(__int64, char *))(*(_QWORD *)v17 + 8i64))(v17, v20);
  }
  if ( (LOBYTE(result.x) & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v17 + 16i64))(v17, v15, COERCE_DOUBLE(*(_QWORD *)&y));
    v17 = 0i64;
  }
  result.x = 0.0;
  v11 = 0i64;
  v12 = VT_Number;
  v13.NValue = (double)tileNum;
  if ( (v27 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, Scaleform::GFx::Value::ValueUnion))(*(_QWORD *)v26 + 16i64))(v26, v25, v28);
    v26 = 0i64;
  }
  v27 = v12;
  v28 = v13;
  v29 = v14;
  if ( (v12 & 0x40) != 0 )
  {
    v26 = v11;
    (*(void (__fastcall **)(__int64, char *))(*(_QWORD *)v11 + 8i64))(v11, v25);
  }
  if ( (v12 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, Scaleform::GFx::Value::ValueUnion))(*(_QWORD *)v11 + 16i64))(v11, v10, v13);
    v11 = 0i64;
  }
  v12 = VT_Undefined;
  if ( pObject )
    Scaleform::GFx::Movie::Invoke(pObject, "setAcceptButtonPos", 0i64, &ptr, 3u);
  `eh vector destructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}ector destructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 572
// RVA: 0x620020
void __fastcall UFG::UIHKScreenPokerDiceMinigame::enableProgression(
        UFG::UIHKScreenPokerDiceMinigame *this,
        bool bEnableProgression,
        bool bControlsOnly)
{
  Scaleform::GFx::Movie *pObject; // rdi
  bool mbEnableProgression; // si
  int mControllerIndex; // edx
  UFG::eHKControllerInputMode mSavedControllerMode; // ecx
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-40h] BYREF

  this->mbEnableProgression = bEnableProgression;
  pObject = this->mRenderable->m_movie.pObject;
  value.pObjectInterface = 0i64;
  value.Type = VT_Undefined;
  mbEnableProgression = this->mbEnableProgression;
  value.Type = VT_Boolean;
  value.mValue.BValue = mbEnableProgression;
  if ( pObject )
    Scaleform::GFx::Movie::SetVariable(pObject, "gameComplete_mc.endbtn._visible", &value, 1i64);
  if ( this->mbEnableProgression )
  {
    if ( !bControlsOnly )
      UFG::UIHKScreenPokerDiceMinigame::bypassIntroScreens(this, pObject);
    mControllerIndex = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->mControllerIndex;
    mSavedControllerMode = this->mSavedControllerMode;
  }
  else
  {
    this->mSavedControllerMode = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_ActiveMapSet;
    mControllerIndex = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->mControllerIndex;
    mSavedControllerMode = IM_UI_ONLY;
  }
  UFG::SetInputMode(mSavedControllerMode, mControllerIndex);
  if ( (value.Type & 0x40) != 0 )
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
      value.pObjectInterface,
      &value,
      value.mValue);
}

// File Line: 602
// RVA: 0x61E840
void __fastcall UFG::UIHKScreenPokerDiceMinigame::bypassIntroScreens(
        UFG::UIHKScreenPokerDiceMinigame *this,
        Scaleform::GFx::Movie *movie)
{
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-40h] BYREF

  this->mbKidnapperCase = 1;
  value.pObjectInterface = 0i64;
  value.Type = VT_Boolean;
  value.mValue.BValue = 1;
  Scaleform::GFx::Movie::SetVariable(movie, "gbKidnapperCase", &value, 1i64);
  Scaleform::GFx::Movie::Invoke(movie, "resetGame", 0i64, &customCaption, -2i64);
  UFG::AIScriptInterfaceComponent::BeginCommandActionRequest(this->mPlayerAISIC);
  if ( UFG::AIScriptInterfaceComponent::GiveCommand(this->mPlayerAISIC, eSCRIPT_COMMAND_SUBMIT_ACTION_REQUEST) )
  {
    UFG::AIScriptInterfaceComponent::AddArgument(this->mPlayerAISIC, "Freerun");
    UFG::AIScriptInterfaceComponent::AddArgument(this->mPlayerAISIC, "Initial");
  }
  if ( (value.Type & 0x40) != 0 )
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
      value.pObjectInterface,
      &value,
      value.mValue);
}

// File Line: 620
// RVA: 0x62FCD0
void __fastcall UFG::UIHKScreenPokerDiceMinigame::hideShowPayouts(
        UFG::UIHKScreenPokerDiceMinigame *this,
        Scaleform::GFx::Movie *movie)
{
  bool v3; // al
  unsigned int v4; // edx

  Scaleform::GFx::Movie::Invoke(movie, "showHidePayouts", 0i64, &customCaption);
  v3 = !this->mbPayoutsShown;
  this->mbPayoutsShown = v3;
  if ( v3 )
  {
    if ( !UFG::HudAudio::m_instance )
      return;
    v4 = -1176679901;
  }
  else
  {
    if ( !UFG::HudAudio::m_instance )
      return;
    v4 = -1528447043;
  }
  UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, v4, 0i64, 0, 0i64);
}

