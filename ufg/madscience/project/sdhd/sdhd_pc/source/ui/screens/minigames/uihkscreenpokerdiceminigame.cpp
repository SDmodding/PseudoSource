// File Line: 45
// RVA: 0x5C6E80
void __fastcall UFG::UIHKScreenPokerDiceMinigame::UIHKScreenPokerDiceMinigame(UFG::UIHKScreenPokerDiceMinigame *this)
{
  UFG::UIHKScreenPokerDiceMinigame *v1; // rbx
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v2; // rax
  UFG::SimComponent *v3; // rdi
  UFG::GameStatTracker *v4; // rax
  UFG::PersistentData::Time *v5; // rax
  UFG::qSymbol *v6; // rax
  UFG::TSCharacter *v7; // rax
  hkgpIndexedMeshDefinitions::Edge *v8; // rdx
  hkgpIndexedMesh::EdgeBarrier *v9; // rcx
  UFG::qSymbol *v10; // rax
  UFG::SimObject *v11; // rdi
  UFG::qWiseSymbol *v12; // rax
  UFG::qWiseSymbol *v13; // rax
  UFG::qSymbol result; // [rsp+48h] [rbp+10h]
  UFG::qSymbol v15; // [rsp+50h] [rbp+18h]

  v1 = this;
  v2 = (UFG::qNode<UFG::UIScreen,UFG::UIScreen> *)&this->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIScreen::`vftable;
  v3 = 0i64;
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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKTaskableScreen::`vftable;
  this->mFinished = 0;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKMinigameScreen::`vftable;
  *(_QWORD *)&this->mfAlphaValue = 1109393408i64;
  ++UFG::UIHKMinigameScreen::mNumMinigameScreens;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenPokerDiceMinigame::`vftable;
  UFG::UIHKDepthOfFieldWidget::UIHKDepthOfFieldWidget(&this->DOF);
  v4 = UFG::GameStatTracker::Instance();
  v5 = UFG::GameStatTracker::GetTimeStat(v4, TimeSpentPlayingPokerDice);
  UFG::SimpleTimer::Resume(&v5->mTimer);
  *(_WORD *)&v1->bRoundHasEnded = 0;
  v1->mCurrentTile = 0;
  v1->mbEnableProgression = 1;
  *(_WORD *)&v1->mbPayoutsShown = 0;
  v1->mSavedControllerMode = 0;
  *(_QWORD *)&v1->mnCurrentTotalWins = 0i64;
  v1->mnCurrentProfit = 0;
  if ( LocalPlayer )
    v3 = UFG::SimObject::GetComponentOfType(
           (UFG::SimObject *)&LocalPlayer->vfptr,
           UFG::AIScriptInterfaceComponent::_TypeUID);
  v1->mPlayerAISIC = (UFG::AIScriptInterfaceComponent *)v3;
  v6 = UFG::qSymbol::create_from_string(&result, "PokerDice1-gambleHouse:spawn");
  v7 = UFG::TSCharacter::find_instance(v6);
  if ( !v7 )
  {
    v10 = UFG::qSymbol::create_from_string(&v15, "PokerDice2-gambleHouse:spawn");
    v7 = UFG::TSCharacter::find_instance(v10);
  }
  v11 = v7->mpSimObj.m_pPointer;
  if ( v11 )
  {
    v1->mHouseAAC = (UFG::ActorAudioComponent *)UFG::SimObject::GetComponentOfType(
                                                  v7->mpSimObj.m_pPointer,
                                                  UFG::ActorAudioComponent::_TypeUID);
    v1->mHouseAISIC = (UFG::AIScriptInterfaceComponent *)UFG::SimObject::GetComponentOfType(
                                                           v11,
                                                           UFG::AIScriptInterfaceComponent::_TypeUID);
  }
  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(v9, v8) )
  {
    v12 = UFG::qWiseSymbol::create_from_string((UFG::qWiseSymbol *)&result, "mg_poker");
    UFG::TiDo::LoadWwiseBank(v12);
    _((AMD_HD3D *)result.mUID);
    v13 = UFG::qWiseSymbol::create_from_string((UFG::qWiseSymbol *)&result, "poi_gamble_mahjong");
    UFG::TiDo::LoadWwiseBank(v13);
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
  UFG::UIHKScreenPokerDiceMinigame *v1; // rbx
  UFG::UIScreenTextureManager *v2; // rax
  UFG::GameStatTracker *v3; // rax
  UFG::PersistentData::Time *v4; // rax
  hkgpIndexedMeshDefinitions::Edge *v5; // rdx
  hkgpIndexedMesh::EdgeBarrier *v6; // rcx
  UFG::qWiseSymbol *v7; // rax
  UFG::qWiseSymbol *v8; // rax
  UFG::qWiseSymbol result; // [rsp+48h] [rbp+10h]

  v1 = this;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenPokerDiceMinigame::`vftable;
  v2 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v2, "PokerDiceMinigame");
  v3 = UFG::GameStatTracker::Instance();
  v4 = UFG::GameStatTracker::GetTimeStat(v3, TimeSpentPlayingPokerDice);
  UFG::PersistentData::Time::EndTimer(v4);
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
  UFG::GameCameraComponent::EndDOFOverride(0);
  UFG::UIHKMinigameScreen::~UIHKMinigameScreen((UFG::UIHKMinigameScreen *)&v1->vfptr);
}

// File Line: 108
// RVA: 0x635890
void __fastcall UFG::UIHKScreenPokerDiceMinigame::init(UFG::UIHKScreenPokerDiceMinigame *this, UFG::UICommandData *data)
{
  UFG::UIHKScreenPokerDiceMinigame *v2; // rbx
  Scaleform::GFx::Movie *v3; // rdi
  UFG::GameStatTracker *v4; // rax
  signed int v5; // ebx
  double v6; // xmm6_8
  bool v7; // bl
  bool v8; // bl
  UFG::UIHKInfoPopupWidget *v9; // rcx
  Scaleform::GFx::Value pargs; // [rsp+30h] [rbp-C8h]
  char ptr; // [rsp+60h] [rbp-98h]
  __int64 v12; // [rsp+70h] [rbp-88h]
  double v13; // [rsp+78h] [rbp-80h]
  char v14; // [rsp+88h] [rbp-70h]
  __int64 v15; // [rsp+98h] [rbp-60h]
  unsigned int v16; // [rsp+A0h] [rbp-58h]
  double v17; // [rsp+A8h] [rbp-50h]
  char v18; // [rsp+B8h] [rbp-40h]
  __int64 v19; // [rsp+C8h] [rbp-30h]
  unsigned int v20; // [rsp+D0h] [rbp-28h]
  __int64 v21; // [rsp+D8h] [rbp-20h]
  __int64 v22; // [rsp+E8h] [rbp-10h]

  v22 = -2i64;
  v2 = this;
  UFG::UIScreen::init((UFG::UIScreen *)&this->vfptr, data);
  v3 = v2->mRenderable->m_movie.pObject;
  v4 = UFG::GameStatTracker::Instance();
  v5 = UFG::GameStatTracker::GetStat(v4, Money);
  `eh vector constructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  if ( (LODWORD(v13) >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v12 + 16i64))(
      v12,
      &ptr,
      COERCE_DOUBLE(*(_QWORD *)&v13));
    v12 = 0i64;
  }
  v13 = (double)v5;
  v6 = (double)UFG::UIHKScreenPokerDiceMinigame::miLimit;
  if ( (v16 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v15 + 16i64))(
      v15,
      &v14,
      COERCE_DOUBLE(*(_QWORD *)&v17));
    v15 = 0i64;
  }
  v16 = 5;
  v17 = v6;
  v7 = UFG::UIHKScreenPokerDiceMinigame::mbMissionMode;
  if ( (v20 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v19 + 16i64))(v19, &v18, v21);
    v19 = 0i64;
  }
  v20 = 2;
  LOBYTE(v21) = v7;
  if ( v3 )
  {
    pargs.pObjectInterface = 0i64;
    pargs.Type = 0;
    v8 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController;
    pargs.Type = 2;
    pargs.mValue.BValue = v8;
    Scaleform::GFx::Movie::Invoke(v3, "Show_PC", 0i64, &pargs, 1u);
    Scaleform::GFx::Movie::Invoke(v3, "init", 0i64, (Scaleform::GFx::Value *)&ptr, 3u);
    if ( ((unsigned int)pargs.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        *(_QWORD *)&pargs.mValue.NValue);
      pargs.pObjectInterface = 0i64;
    }
    pargs.Type = 0;
  }
  v9 = UFG::UIHKScreenHud::InfoPopup;
  if ( (unsigned int)(UFG::UIHKScreenHud::InfoPopup->mState - 4) <= 1 )
    UFG::UIHKScreenHud::InfoPopup->mState = 0;
  if ( v9->mState )
    v9->mState = 1;
  `eh vector destructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 133
// RVA: 0x63F440
void __fastcall UFG::UIHKScreenPokerDiceMinigame::update(UFG::UIHKScreenPokerDiceMinigame *this, float elapsed)
{
  UFG::UIHKScreenPokerDiceMinigame *v2; // rbx
  Scaleform::GFx::Movie *v3; // rdi
  bool v4; // si
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-50h]

  v2 = this;
  if ( !UFG::UIScreenManagerBase::getScreen(
          (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
          "NISPause") )
  {
    v3 = v2->mRenderable->m_movie.pObject;
    if ( v3 )
    {
      pargs.pObjectInterface = 0i64;
      pargs.Type = 0;
      v4 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController;
      pargs.Type = 2;
      pargs.mValue.BValue = v4;
      Scaleform::GFx::Movie::Invoke(v3, "Show_PC", 0i64, &pargs, 1u);
      Scaleform::GFx::Movie::Invoke(v3, "mainLoop", 0i64, 0i64, 0);
      if ( ((unsigned int)pargs.Type >> 6) & 1 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
          pargs.pObjectInterface,
          &pargs,
          *(_QWORD *)&pargs.mValue.NValue);
        pargs.pObjectInterface = 0i64;
      }
      pargs.Type = 0;
    }
    UFG::UIScreen::update((UFG::UIScreen *)&v2->vfptr, elapsed);
    UFG::UIHKInfoPopupWidget::Update(UFG::UIHKScreenHud::InfoPopup, (UFG::UIScreen *)&v2->vfptr, elapsed);
  }
}

// File Line: 156
// RVA: 0x629C30
_BOOL8 __fastcall UFG::UIHKScreenPokerDiceMinigame::handleMessage(UFG::UIHKScreenPokerDiceMinigame *this, unsigned int msgId, UFG::UIMessage *msg)
{
  UFG::UIMessage *v3; // r12
  unsigned int v4; // er14
  UFG::UIHKScreenPokerDiceMinigame *v5; // rsi
  Scaleform::GFx::Movie *v6; // r15
  signed int v7; // er13
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
  UFG::qString *v27; // rcx
  UFG::GameStatTracker *v28; // rax
  int v29; // er13
  UFG::GameStatTracker *v30; // rax
  int v31; // edi
  UFG::GameStatTracker *v32; // rax
  int v33; // edi
  UFG::GameStatTracker *v34; // rax
  UFG::GameStatTracker *v35; // rax
  UFG::GameStatTracker *v36; // rax
  UFG::OSuiteLeaderboardManager *v37; // rax
  UFG::OSuiteLeaderboardData *v38; // rax
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
  UFG::qString v64; // [rsp+30h] [rbp-A9h]
  char ptr; // [rsp+60h] [rbp-79h]
  __int64 v66; // [rsp+70h] [rbp-69h]
  unsigned int v67; // [rsp+78h] [rbp-61h]
  double v68; // [rsp+80h] [rbp-59h]
  Scaleform::GFx::Value pval; // [rsp+90h] [rbp-49h]
  UFG::qSymbol v70; // [rsp+C0h] [rbp-19h]
  Scaleform::GFx::Value v71; // [rsp+C8h] [rbp-11h]
  __int64 v72; // [rsp+F8h] [rbp+1Fh]
  UFG::qSymbol result; // [rsp+140h] [rbp+67h]
  UFG::qSymbol v74; // [rsp+158h] [rbp+7Fh]

  v72 = -2i64;
  v3 = msg;
  v4 = msgId;
  v5 = this;
  v6 = this->mRenderable->m_movie.pObject;
  pval.pObjectInterface = 0i64;
  pval.Type = 0;
  Scaleform::GFx::Movie::GetVariable(v6, &pval, "g_nGameStatus");
  v7 = (signed int)pval.mValue.NValue;
  v71.pObjectInterface = 0i64;
  v71.Type = 0;
  Scaleform::GFx::Movie::GetVariable(v6, &v71, "gbAllowControls");
  if ( !v6 )
  {
    v10 = UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
    goto LABEL_114;
  }
  if ( v4 == UI_HASH_PLAYSOUND_20 )
  {
    if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(v9, v8) )
    {
      UFG::qString::qString(&v64, (UFG::qString *)&v3[1]);
      v11 = UFG::TiDo::CalcWwiseUid(v64.mData);
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr, v11, 0i64, 0, 0i64);
      UFG::qString::~qString(&v64);
    }
    goto LABEL_113;
  }
  if ( v4 != UI_HASH_PLAYDIALOGUE_20 )
  {
    if ( v4 == UI_HASH_SETFINISHED_20 )
    {
      Scaleform::GFx::Movie::GetVariable(v6, &pval, "g_nPocketMoney");
      v13 = (signed int)pval.mValue.NValue;
      v14 = UFG::GameStatTracker::Instance();
      v15 = (unsigned __int64)UFG::GameStatTracker::GetStat(v14, Money) - v13;
      v16 = UFG::GameStatTracker::Instance();
      UFG::GameStatTracker::SetStat(v16, Money, v13);
      v17 = UFG::qSymbol::create_from_string(&result, "Exit");
      v18 = UFG::qSymbol::create_from_string(&v74, "PokerDice");
      UFG::GameStatAction::Money::SendTransactionTelemetry(v18, v17, v15);
      v5->mFinished = 1;
      goto LABEL_113;
    }
    if ( v4 == UI_HASH_DPAD_LEFT_PRESSED_30 || v4 == UI_HASH_THUMBSTICK_LEFT_LEFT_30 )
    {
      if ( !v71.mValue.BValue || v5->mbKidnapperCase || v7 )
        goto LABEL_113;
      `eh vector constructor iterator(&v64, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      v66 = 0i64;
      v67 = 5;
      v68 = DOUBLE_N1_0;
      Scaleform::GFx::Value::operator=((Scaleform::GFx::Value *)&v64, (Scaleform::GFx::Value *)&ptr);
      if ( (v67 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v66 + 16i64))(
          v66,
          &ptr,
          COERCE_DOUBLE(*(_QWORD *)&v68));
        v66 = 0i64;
      }
      v67 = 0;
      Scaleform::GFx::Movie::Invoke(v6, "adjustBet", 0i64, (Scaleform::GFx::Value *)&v64, 1u);
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(
          (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
          0x6A29BF1Du,
          0i64,
          0,
          0i64);
    }
    else
    {
      if ( v4 != UI_HASH_DPAD_RIGHT_PRESSED_30 && v4 != UI_HASH_THUMBSTICK_LEFT_RIGHT_30 )
      {
        if ( v4 == UI_HASH_BUTTON_ACCEPT_PRESSED_30 )
        {
          v19 = UFG::ActionDef_UIR2Repeat.mDataPerController[UFG::gActiveControllerNum];
          if ( !v19 || !v19->mActionTrue )
          {
            v20 = UFG::ActionDef_UIL2Repeat.mDataPerController[UFG::gActiveControllerNum];
            if ( !v20 || !v20->mActionTrue )
            {
              if ( !v71.mValue.BValue || !v5->mbEnableProgression )
                goto LABEL_113;
              if ( v7 == -1 )
              {
                UFG::UIScreenDialogBox::createOKDialog(
                  (UFG::UIScreen *)&v5->vfptr,
                  &customWorldMapCaption,
                  "$HUD_MINIGAME_INSUFFICIENT_MONEY",
                  0);
                goto LABEL_113;
              }
              if ( (unsigned int)v7 <= 2 )
              {
                if ( v5->mbPayoutsShown )
                  UFG::UIHKScreenPokerDiceMinigame::hideShowPayouts(v5, v6);
                if ( !v7 )
                {
                  *(_WORD *)&v5->bRoundHasEnded = 256;
                  if ( UFG::HudAudio::m_instance )
                    UFG::AudioEntity::CreateAndPlayEvent(
                      (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
                      0x1666C41Eu,
                      0i64,
                      0,
                      0i64);
                  if ( !v5->mbKidnapperCase )
                  {
                    *(_QWORD *)&v64.mMagic = 0i64;
                    LODWORD(v64.mData) = 0;
                    Scaleform::GFx::Movie::GetVariable(v6, (Scaleform::GFx::Value *)&v64, "g_nPocketMoney");
                    v21 = (signed int)*(double *)&v64.mStringHash32;
                    v22 = UFG::GameStatTracker::Instance();
                    v23 = (unsigned __int64)UFG::GameStatTracker::GetStat(v22, Money) - v21;
                    v24 = UFG::GameStatTracker::Instance();
                    UFG::GameStatTracker::SetStat(v24, Money, v21);
                    v25 = UFG::qSymbol::create_from_string(&result, "Bet");
                    v26 = UFG::qSymbol::create_from_string(&v74, "PokerDice");
                    UFG::GameStatAction::Money::SendTransactionTelemetry(v26, v25, v23);
                    if ( (LODWORD(v64.mData) >> 6) & 1 )
                    {
                      (*(void (__fastcall **)(_QWORD, UFG::qString *, _QWORD))(**(_QWORD **)&v64.mMagic + 16i64))(
                        *(_QWORD *)&v64.mMagic,
                        &v64,
                        *(_QWORD *)&v64.mStringHash32);
                      *(_QWORD *)&v64.mMagic = 0i64;
                    }
                    LODWORD(v64.mData) = 0;
                  }
                  goto LABEL_40;
                }
                if ( (unsigned int)(v7 - 1) > 1 || v5->mCurrentTile == 5 )
                {
LABEL_40:
                  Scaleform::GFx::Movie::Invoke(v6, "setTransitionMode", 0i64, 0i64, 0);
                  `eh vector constructor iterator(
                    &ptr,
                    0x30ui64,
                    1,
                    (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
                  *(_QWORD *)&v64.mMagic = 0i64;
                  LODWORD(v64.mData) = 5;
                  *(double *)&v64.mStringHash32 = (double)(v7 + 1);
                  Scaleform::GFx::Value::operator=((Scaleform::GFx::Value *)&ptr, (Scaleform::GFx::Value *)&v64);
                  if ( (LODWORD(v64.mData) >> 6) & 1 )
                  {
                    (*(void (__fastcall **)(_QWORD, UFG::qString *, _QWORD))(**(_QWORD **)&v64.mMagic + 16i64))(
                      *(_QWORD *)&v64.mMagic,
                      &v64,
                      *(_QWORD *)&v64.mStringHash32);
                    *(_QWORD *)&v64.mMagic = 0i64;
                  }
                  LODWORD(v64.mData) = 0;
                  Scaleform::GFx::Movie::Invoke(v6, "setState", 0i64, (Scaleform::GFx::Value *)&ptr, 1u);
                  UFG::AIScriptInterfaceComponent::BeginCommandActionRequest(v5->mPlayerAISIC);
                  if ( UFG::AIScriptInterfaceComponent::GiveCommand(
                         v5->mPlayerAISIC,
                         eSCRIPT_COMMAND_SUBMIT_ACTION_REQUEST) )
                  {
                    UFG::AIScriptInterfaceComponent::AddArgument(v5->mPlayerAISIC, "PokerDiceDrawTiles1");
                    UFG::AIScriptInterfaceComponent::AddArgument(v5->mPlayerAISIC, "DrawTiles1");
                  }
                  UFG::AIScriptInterfaceComponent::BeginCommandActionRequest(v5->mHouseAISIC);
                  if ( UFG::AIScriptInterfaceComponent::GiveCommand(
                         v5->mHouseAISIC,
                         eSCRIPT_COMMAND_SUBMIT_ACTION_REQUEST) )
                  {
                    UFG::AIScriptInterfaceComponent::AddArgument(v5->mHouseAISIC, "PokerDiceDrawTiles2");
                    UFG::AIScriptInterfaceComponent::AddArgument(v5->mHouseAISIC, "DrawTiles2");
                  }
                  v27 = (UFG::qString *)&ptr;
                  goto LABEL_112;
                }
LABEL_95:
                v10 = UFG::UIHKMinigameScreen::handleMessage((UFG::UIHKMinigameScreen *)&v5->vfptr, v4, v3);
                goto LABEL_114;
              }
              *(_QWORD *)&v64.mMagic = 0i64;
              LODWORD(v64.mData) = 0;
              Scaleform::GFx::Movie::GetVariable(v6, (Scaleform::GFx::Value *)&v64, "gameComplete_mc._visible");
              if ( LOBYTE(v64.mStringHash32) )
              {
                Scaleform::GFx::Movie::Invoke(v6, "resetGame", 0i64, &customWorldMapCaption);
                UFG::AIScriptInterfaceComponent::BeginCommandActionRequest(v5->mHouseAISIC);
                if ( UFG::AIScriptInterfaceComponent::GiveCommand(
                       v5->mHouseAISIC,
                       eSCRIPT_COMMAND_SUBMIT_ACTION_REQUEST) )
                {
                  UFG::AIScriptInterfaceComponent::AddArgument(v5->mHouseAISIC, "PokerDiceMix");
                  UFG::AIScriptInterfaceComponent::AddArgument(v5->mHouseAISIC, "Mix");
                }
                UFG::AIScriptInterfaceComponent::BeginCommandActionRequest(v5->mPlayerAISIC);
                if ( UFG::AIScriptInterfaceComponent::GiveCommand(
                       v5->mPlayerAISIC,
                       eSCRIPT_COMMAND_SUBMIT_ACTION_REQUEST) )
                {
                  UFG::AIScriptInterfaceComponent::AddArgument(v5->mPlayerAISIC, "PokerDiceMix");
                  UFG::AIScriptInterfaceComponent::AddArgument(v5->mPlayerAISIC, "Mix");
                }
              }
              if ( (LODWORD(v64.mData) >> 6) & 1 )
              {
                (*(void (__fastcall **)(_QWORD, UFG::qString *, _QWORD))(**(_QWORD **)&v64.mMagic + 16i64))(
                  *(_QWORD *)&v64.mMagic,
                  &v64,
                  *(_QWORD *)&v64.mStringHash32);
                *(_QWORD *)&v64.mMagic = 0i64;
              }
LABEL_54:
              LODWORD(v64.mData) = 0;
              goto LABEL_113;
            }
          }
        }
        if ( v4 == UI_HASH_BUTTON_BACK_PRESSED_30 )
        {
          *(_QWORD *)&v64.mMagic = 0i64;
          LODWORD(v64.mData) = 0;
          if ( v71.mValue.BValue && v5->mbEnableProgression )
          {
            if ( UFG::HudAudio::m_instance )
              UFG::AudioEntity::CreateAndPlayEvent(
                (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
                0xA4E5BFBD,
                0i64,
                0,
                0i64);
            UFG::UIHKMinigameScreen::handleExiting((UFG::UIHKMinigameScreen *)&v5->vfptr);
            if ( (LODWORD(v64.mData) >> 6) & 1 )
            {
              (*(void (__fastcall **)(_QWORD, UFG::qString *, _QWORD))(**(_QWORD **)&v64.mMagic + 16i64))(
                *(_QWORD *)&v64.mMagic,
                &v64,
                *(_QWORD *)&v64.mStringHash32);
              *(_QWORD *)&v64.mMagic = 0i64;
              LODWORD(v64.mData) = 0;
              goto LABEL_113;
            }
            goto LABEL_54;
          }
          if ( (LODWORD(v64.mData) >> 6) & 1 )
          {
            (*(void (__fastcall **)(_QWORD, UFG::qString *, _QWORD))(**(_QWORD **)&v64.mMagic + 16i64))(
              *(_QWORD *)&v64.mMagic,
              &v64,
              *(_QWORD *)&v64.mStringHash32);
            *(_QWORD *)&v64.mMagic = 0i64;
            LODWORD(v64.mData) = 0;
            goto LABEL_95;
          }
        }
        else
        {
          if ( v4 == UI_HASH_BUTTON_BUTTON1_PRESSED_30 )
          {
            if ( v71.mValue.BValue && v7 > 0 && v5->mbEnableProgression )
              UFG::UIHKScreenPokerDiceMinigame::hideShowPayouts(v5, v6);
            goto LABEL_95;
          }
          if ( v4 == UI_HASH_POKERDICEWIN_20 )
          {
            v28 = UFG::GameStatTracker::Instance();
            result.mUID = UFG::GameStatTracker::GetStat(v28, Money);
            UFG::AIScriptInterfaceComponent::BeginCommandActionRequest(v5->mHouseAISIC);
            if ( UFG::AIScriptInterfaceComponent::GiveCommand(v5->mHouseAISIC, eSCRIPT_COMMAND_SUBMIT_ACTION_REQUEST) )
            {
              UFG::AIScriptInterfaceComponent::AddArgument(v5->mHouseAISIC, "PokerDiceLose");
              UFG::AIScriptInterfaceComponent::AddArgument(v5->mHouseAISIC, "Lose");
            }
            v66 = 0i64;
            v67 = 0;
            Scaleform::GFx::Movie::GetVariable(v6, (Scaleform::GFx::Value *)&ptr, "g_nPocketMoney");
            v29 = (signed int)v68;
            if ( UFG::HudAudio::m_instance )
              UFG::AudioEntity::CreateAndPlayEvent(
                (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
                0x1234D1F7u,
                0i64,
                0,
                0i64);
            v30 = UFG::GameStatTracker::Instance();
            v31 = UFG::GameStatTracker::GetStat(v30, Money);
            v32 = UFG::GameStatTracker::Instance();
            UFG::GameStatTracker::SetStat(v32, Money, v29);
            v33 = v31 - v29;
            if ( v33 < 0 )
              v33 = -v33;
            v34 = UFG::GameStatTracker::Instance();
            UFG::GameStatTracker::ApplyDelta(v34, TotalCashEarned, v33);
            v35 = UFG::GameStatTracker::Instance();
            UFG::GameStatTracker::ApplyDelta(v35, GamblingEarnings, v33);
            v36 = UFG::GameStatTracker::Instance();
            UFG::GameStatTracker::ApplyDelta(v36, PokerDicePlayed, 1);
            UFG::OnlineEventManager::PostEvent((UFG::OnlineEventManager::Event)4u, 1);
            v37 = UFG::OSuiteLeaderboardManager::Instance();
            v38 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v37, "StatAwardsMogul");
            UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(v38, v33);
            v39 = UFG::qSymbol::create_from_string(&v74, "Winning");
            v40 = UFG::qSymbol::create_from_string(&v70, "PokerDice");
            UFG::GameStatAction::Money::SendTransactionTelemetry(v40, v39, v33);
            v41 = UFG::GameStatTracker::Instance();
            LODWORD(v39) = UFG::GameStatTracker::GetStat(v41, GamblingLoss);
            v42 = UFG::GameStatTracker::Instance();
            v43 = (unsigned __int64)UFG::GameStatTracker::GetStat(v42, GamblingEarnings) - (_DWORD)v39;
            v44 = UFG::OSuiteLeaderboardManager::Instance();
            v45 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v44, "StatAwardsGambler");
            UFG::DataSynchronizer::SetMaxToGlobalSnapshot(v45, v43);
            *(_WORD *)&v5->bRoundHasEnded = 1;
            ++v5->mnCurrentTotalWins;
            *(_QWORD *)&v64.mMagic = 0i64;
            LODWORD(v64.mData) = 0;
            Scaleform::GFx::Movie::GetVariable(v6, (Scaleform::GFx::Value *)&v64, "g_nBet");
            v5->mnCurrentProfit += v29 - (signed int)*(double *)&v64.mStringHash32 - result.mUID;
            if ( (LODWORD(v64.mData) >> 6) & 1 )
            {
              (*(void (__fastcall **)(_QWORD, UFG::qString *, _QWORD))(**(_QWORD **)&v64.mMagic + 16i64))(
                *(_QWORD *)&v64.mMagic,
                &v64,
                *(_QWORD *)&v64.mStringHash32);
              *(_QWORD *)&v64.mMagic = 0i64;
            }
            LODWORD(v64.mData) = 0;
            if ( (v67 >> 6) & 1 )
            {
              (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v66 + 16i64))(
                v66,
                &ptr,
                COERCE_DOUBLE(*(_QWORD *)&v68));
              v66 = 0i64;
            }
            v67 = 0;
            goto LABEL_95;
          }
          if ( v4 != UI_HASH_POKERDICELOSE_20 )
          {
            if ( v4 == UI_HASH_HOUSEHOLDS_20 )
            {
              v60 = SSBrain::get_class("PokerDice");
              *(_QWORD *)&v74.mUID = 0i64;
              v61 = ASymbol::create((ASymbol *)&result, "house_holds_tiles", 0xFFFFFFFF, ATerm_long);
              v62 = (__int64)v60->vfptr->get_metaclass((SSClassDescBase *)&v60->vfptr);
              (*(void (__fastcall **)(__int64, ASymbol *, UFG::qSymbol *, bool, _QWORD, _QWORD))(*(_QWORD *)(v62 + 8)
                                                                                               + 104i64))(
                v62 + 8,
                v61,
                &v74,
                *(_QWORD *)&v74.mUID != 0i64,
                0i64,
                0i64);
            }
            goto LABEL_95;
          }
          UFG::AIScriptInterfaceComponent::BeginCommandActionRequest(v5->mHouseAISIC);
          if ( UFG::AIScriptInterfaceComponent::GiveCommand(v5->mHouseAISIC, eSCRIPT_COMMAND_SUBMIT_ACTION_REQUEST) )
          {
            UFG::AIScriptInterfaceComponent::AddArgument(v5->mHouseAISIC, "PokerDiceWin");
            UFG::AIScriptInterfaceComponent::AddArgument(v5->mHouseAISIC, "Win");
          }
          *(_QWORD *)&v64.mMagic = 0i64;
          LODWORD(v64.mData) = 0;
          Scaleform::GFx::Movie::GetVariable(v6, (Scaleform::GFx::Value *)&v64, "g_nPocketMoney");
          v46 = (signed int)*(double *)&v64.mStringHash32;
          if ( UFG::HudAudio::m_instance )
            UFG::AudioEntity::CreateAndPlayEvent(
              (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
              0x7D608E0Cu,
              0i64,
              0,
              0i64);
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
          UFG::OnlineEventManager::PostEvent((UFG::OnlineEventManager::Event)4u, 1);
          v53 = UFG::qSymbol::create_from_string(&result, "Lost");
          v54 = UFG::qSymbol::create_from_string(&v74, "PokerDice");
          UFG::GameStatAction::Money::SendTransactionTelemetry(v54, v53, v50);
          v55 = UFG::GameStatTracker::Instance();
          LODWORD(v53) = UFG::GameStatTracker::GetStat(v55, GamblingLoss);
          v56 = UFG::GameStatTracker::Instance();
          v57 = (unsigned __int64)UFG::GameStatTracker::GetStat(v56, GamblingEarnings) - (_DWORD)v53;
          v58 = UFG::OSuiteLeaderboardManager::Instance();
          v59 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v58, "StatAwardsGambler");
          UFG::DataSynchronizer::SetMaxToGlobalSnapshot(v59, v57);
          *(_WORD *)&v5->bRoundHasEnded = 1;
          ++v5->mnCurrentTotalLosses;
          v66 = 0i64;
          v67 = 0;
          Scaleform::GFx::Movie::GetVariable(v6, (Scaleform::GFx::Value *)&ptr, "g_nBet");
          v5->mnCurrentProfit -= (signed int)v68;
          if ( (v67 >> 6) & 1 )
          {
            (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v66 + 16i64))(
              v66,
              &ptr,
              COERCE_DOUBLE(*(_QWORD *)&v68));
            v66 = 0i64;
          }
          v67 = 0;
          if ( (LODWORD(v64.mData) >> 6) & 1 )
          {
            (*(void (__fastcall **)(_QWORD, UFG::qString *, _QWORD))(**(_QWORD **)&v64.mMagic + 16i64))(
              *(_QWORD *)&v64.mMagic,
              &v64,
              *(_QWORD *)&v64.mStringHash32);
            *(_QWORD *)&v64.mMagic = 0i64;
          }
        }
        LODWORD(v64.mData) = 0;
        goto LABEL_95;
      }
      if ( !v71.mValue.BValue || v5->mbKidnapperCase || v7 )
        goto LABEL_113;
      `eh vector constructor iterator(&v64, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      v66 = 0i64;
      v67 = 5;
      v68 = DOUBLE_1_0;
      Scaleform::GFx::Value::operator=((Scaleform::GFx::Value *)&v64, (Scaleform::GFx::Value *)&ptr);
      if ( (v67 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v66 + 16i64))(
          v66,
          &ptr,
          COERCE_DOUBLE(*(_QWORD *)&v68));
        v66 = 0i64;
      }
      v67 = 0;
      Scaleform::GFx::Movie::Invoke(v6, "adjustBet", 0i64, (Scaleform::GFx::Value *)&v64, 1u);
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(
          (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
          0x6A29BF1Du,
          0i64,
          0,
          0i64);
    }
    v27 = &v64;
LABEL_112:
    `eh vector destructor iterator(v27, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    goto LABEL_113;
  }
  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(v9, v8) )
  {
    UFG::qString::qString(&v64, (UFG::qString *)&v3[1]);
    if ( v5->mHouseAAC )
    {
      v12 = UFG::TiDo::CalcWwiseUid("play_mission");
      UFG::ActorAudioComponent::QueueSpeechExternalMission(v5->mHouseAAC, v12, v64.mData, 0i64, 5u, 0);
    }
    UFG::qString::~qString(&v64);
    goto LABEL_95;
  }
LABEL_113:
  v10 = 1;
LABEL_114:
  if ( ((unsigned int)v71.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&v71.pObjectInterface->vfptr->gap8[8])(
      v71.pObjectInterface,
      &v71,
      *(_QWORD *)&v71.mValue.NValue);
    v71.pObjectInterface = 0i64;
  }
  v71.Type = 0;
  if ( ((unsigned int)pval.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pval.pObjectInterface->vfptr->gap8[8])(
      pval.pObjectInterface,
      &pval,
      *(_QWORD *)&pval.mValue.NValue);
    pval.pObjectInterface = 0i64;
  }
  return v10;
}al,
      *(_QWORD *)&pval.mValue.NValue);
    pval.pObjectInterface = 0i64;
  }
  return v10;
}

// File Line: 476
// RVA: 0x638940
void __fastcall UFG::UIHKScreenPokerDiceMinigame::lockSelectedTile(UFG::UIHKScreenPokerDiceMinigame *this, unsigned int selectedTile)
{
  signed int v2; // ebx
  Scaleform::GFx::Movie *v3; // rdi
  char v4; // [rsp+30h] [rbp-11h]
  __int64 v5; // [rsp+40h] [rbp-1h]
  unsigned int v6; // [rsp+48h] [rbp+7h]
  double v7; // [rsp+50h] [rbp+Fh]
  __int64 v8; // [rsp+58h] [rbp+17h]
  char ptr; // [rsp+60h] [rbp+1Fh]
  __int64 v10; // [rsp+70h] [rbp+2Fh]
  unsigned int v11; // [rsp+78h] [rbp+37h]
  double v12; // [rsp+80h] [rbp+3Fh]
  __int64 v13; // [rsp+88h] [rbp+47h]

  v2 = selectedTile;
  v3 = this->mRenderable->m_movie.pObject;
  `eh vector constructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  v5 = 0i64;
  v6 = 5;
  v7 = (double)v2;
  if ( (v11 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v10 + 16i64))(
      v10,
      &ptr,
      COERCE_DOUBLE(*(_QWORD *)&v12));
    v10 = 0i64;
  }
  v11 = v6;
  v12 = v7;
  v13 = v8;
  if ( (v6 >> 6) & 1 )
  {
    v10 = v5;
    (*(void (__fastcall **)(__int64, char *))(*(_QWORD *)v5 + 8i64))(v5, &ptr);
  }
  if ( (v6 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v5 + 16i64))(v5, &v4, COERCE_DOUBLE(*(_QWORD *)&v7));
    v5 = 0i64;
  }
  v6 = 0;
  if ( v3 )
    Scaleform::GFx::Movie::Invoke(v3, "lockSelectedDie", 0i64, (Scaleform::GFx::Value *)&ptr, 1u);
  `eh vector destructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 488
// RVA: 0x639D00
void __fastcall UFG::UIHKScreenPokerDiceMinigame::refreshGameData(UFG::UIHKScreenPokerDiceMinigame *this)
{
  UFG::UIHKScreenPokerDiceMinigame *v1; // rdi
  Scaleform::GFx::Movie *v2; // rbx
  Scaleform::GFx::Value pval; // [rsp+28h] [rbp-38h]

  v1 = this;
  v2 = this->mRenderable->m_movie.pObject;
  if ( v2 )
  {
    pval.pObjectInterface = 0i64;
    pval.Type = 0;
    Scaleform::GFx::Movie::GetVariable(v2, &pval, "outPlayerHand0");
    v1->mPlayerHandArray[0] = (signed int)pval.mValue.NValue;
    Scaleform::GFx::Movie::GetVariable(v2, &pval, "outPlayerHand1");
    v1->mPlayerHandArray[1] = (signed int)pval.mValue.NValue;
    Scaleform::GFx::Movie::GetVariable(v2, &pval, "outPlayerHand2");
    v1->mPlayerHandArray[2] = (signed int)pval.mValue.NValue;
    Scaleform::GFx::Movie::GetVariable(v2, &pval, "outPlayerHand3");
    v1->mPlayerHandArray[3] = (signed int)pval.mValue.NValue;
    Scaleform::GFx::Movie::GetVariable(v2, &pval, "outPlayerHand4");
    v1->mPlayerHandArray[4] = (signed int)pval.mValue.NValue;
    Scaleform::GFx::Movie::GetVariable(v2, &pval, "outHouseHand0");
    v1->mHouseHandArray[0] = (signed int)pval.mValue.NValue;
    Scaleform::GFx::Movie::GetVariable(v2, &pval, "outHouseHand1");
    v1->mHouseHandArray[1] = (signed int)pval.mValue.NValue;
    Scaleform::GFx::Movie::GetVariable(v2, &pval, "outHouseHand2");
    v1->mHouseHandArray[2] = (signed int)pval.mValue.NValue;
    Scaleform::GFx::Movie::GetVariable(v2, &pval, "outHouseHand3");
    v1->mHouseHandArray[3] = (signed int)pval.mValue.NValue;
    Scaleform::GFx::Movie::GetVariable(v2, &pval, "outHouseHand4");
    v1->mHouseHandArray[4] = (signed int)pval.mValue.NValue;
    Scaleform::GFx::Movie::GetVariable(v2, &pval, "outPlayerHeld0");
    v1->mPlayerHeldArray[0] = pval.mValue.BValue;
    Scaleform::GFx::Movie::GetVariable(v2, &pval, "outPlayerHeld1");
    v1->mPlayerHeldArray[1] = pval.mValue.BValue;
    Scaleform::GFx::Movie::GetVariable(v2, &pval, "outPlayerHeld2");
    v1->mPlayerHeldArray[2] = pval.mValue.BValue;
    Scaleform::GFx::Movie::GetVariable(v2, &pval, "outPlayerHeld3");
    v1->mPlayerHeldArray[3] = pval.mValue.BValue;
    Scaleform::GFx::Movie::GetVariable(v2, &pval, "outPlayerHeld4");
    v1->mPlayerHeldArray[4] = pval.mValue.BValue;
    Scaleform::GFx::Movie::GetVariable(v2, &pval, "outHouseHeld0");
    v1->mHouseHeldArray[0] = pval.mValue.BValue;
    Scaleform::GFx::Movie::GetVariable(v2, &pval, "outHouseHeld1");
    v1->mHouseHeldArray[1] = pval.mValue.BValue;
    Scaleform::GFx::Movie::GetVariable(v2, &pval, "outHouseHeld2");
    v1->mHouseHeldArray[2] = pval.mValue.BValue;
    Scaleform::GFx::Movie::GetVariable(v2, &pval, "outHouseHeld3");
    v1->mHouseHeldArray[3] = pval.mValue.BValue;
    Scaleform::GFx::Movie::GetVariable(v2, &pval, "outHouseHeld4");
    v1->mHouseHeldArray[4] = pval.mValue.BValue;
    Scaleform::GFx::Movie::GetVariable(v2, &pval, "g_nSelectedDie");
    if ( ((unsigned int)pval.Type >> 6) & 1 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pval.pObjectInterface->vfptr->gap8[8])(
        pval.pObjectInterface,
        &pval,
        *(_QWORD *)&pval.mValue.NValue);
  }
}

// File Line: 549
// RVA: 0x63A480
void __fastcall UFG::UIHKScreenPokerDiceMinigame::setAcceptButtonCoords(UFG::UIHKScreenPokerDiceMinigame *this, UFG::qVector3 *buttonPos, int tileNum)
{
  int v3; // esi
  UFG::qVector3 *v4; // rbx
  UFG::UIHKScreenPokerDiceMinigame *v5; // rdi
  signed int v6; // er9
  UFG::BaseCameraComponent *v7; // rcx
  UFG::Camera *v8; // rcx
  Scaleform::GFx::Movie *v9; // rbx
  char v10; // [rsp+30h] [rbp-B8h]
  __int64 v11; // [rsp+40h] [rbp-A8h]
  unsigned int v12; // [rsp+48h] [rbp-A0h]
  double v13; // [rsp+50h] [rbp-98h]
  __int64 v14; // [rsp+58h] [rbp-90h]
  char v15; // [rsp+60h] [rbp-88h]
  double v16; // [rsp+68h] [rbp-80h]
  __int64 v17; // [rsp+70h] [rbp-78h]
  UFG::qVector3 result; // [rsp+78h] [rbp-70h]
  char ptr; // [rsp+88h] [rbp-60h]
  __int64 v20; // [rsp+98h] [rbp-50h]
  unsigned int v21; // [rsp+A0h] [rbp-48h]
  double v22; // [rsp+A8h] [rbp-40h]
  __int64 v23; // [rsp+B0h] [rbp-38h]
  char v24; // [rsp+B8h] [rbp-30h]
  __int64 v25; // [rsp+C8h] [rbp-20h]
  float v26; // [rsp+D0h] [rbp-18h]
  double v27; // [rsp+D8h] [rbp-10h]
  __int64 v28; // [rsp+E0h] [rbp-8h]
  char v29; // [rsp+E8h] [rbp+0h]
  __int64 v30; // [rsp+F8h] [rbp+10h]
  unsigned int v31; // [rsp+100h] [rbp+18h]
  double v32; // [rsp+108h] [rbp+20h]
  __int64 v33; // [rsp+110h] [rbp+28h]
  __int64 v34; // [rsp+118h] [rbp+30h]
  UFG::qVector2 viewport_scale; // [rsp+148h] [rbp+60h]
  char is_on_screen; // [rsp+158h] [rbp+70h]

  v34 = -2i64;
  v3 = tileNum;
  v4 = buttonPos;
  v5 = this;
  v6 = UFG::UIScreenManager::s_instance->m_flashHeight;
  viewport_scale.x = (float)(signed int)UFG::UIScreenManager::s_instance->m_flashWidth;
  viewport_scale.y = (float)v6;
  is_on_screen = 0;
  v7 = UFG::Director::Get()->mCurrentCamera;
  if ( v7 )
    v8 = &v7->mCamera;
  else
    v8 = 0i64;
  UFG::Camera::GetScreenCoord(v8, &result, v4, &viewport_scale, (bool *)&is_on_screen);
  v9 = v5->mRenderable->m_movie.pObject;
  v5->mCurrentTile = v3;
  `eh vector constructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  v11 = 0i64;
  v12 = 5;
  v13 = result.x;
  if ( (v21 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v20 + 16i64))(
      v20,
      &ptr,
      COERCE_DOUBLE(*(_QWORD *)&v22));
    v20 = 0i64;
  }
  v21 = v12;
  v22 = v13;
  v23 = v14;
  if ( (v12 >> 6) & 1 )
  {
    v20 = v11;
    (*(void (__fastcall **)(__int64, char *))(*(_QWORD *)v11 + 8i64))(v11, &ptr);
  }
  if ( (v12 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v11 + 16i64))(
      v11,
      &v10,
      COERCE_DOUBLE(*(_QWORD *)&v13));
    v11 = 0i64;
  }
  v12 = 0;
  v17 = 0i64;
  LODWORD(result.x) = 5;
  v16 = result.y;
  if ( (LODWORD(v26) >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v25 + 16i64))(
      v25,
      &v24,
      COERCE_DOUBLE(*(_QWORD *)&v27));
    v25 = 0i64;
  }
  v26 = result.x;
  v27 = v16;
  v28 = v17;
  if ( (LODWORD(result.x) >> 6) & 1 )
  {
    v25 = v17;
    (*(void (__fastcall **)(__int64, char *))(*(_QWORD *)v17 + 8i64))(v17, &v24);
  }
  if ( (LODWORD(result.x) >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v17 + 16i64))(
      v17,
      &v15,
      COERCE_DOUBLE(*(_QWORD *)&v16));
    v17 = 0i64;
  }
  result.x = 0.0;
  v11 = 0i64;
  v12 = 5;
  v13 = (double)v3;
  if ( (v31 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v30 + 16i64))(
      v30,
      &v29,
      COERCE_DOUBLE(*(_QWORD *)&v32));
    v30 = 0i64;
  }
  v31 = v12;
  v32 = v13;
  v33 = v14;
  if ( (v12 >> 6) & 1 )
  {
    v30 = v11;
    (*(void (__fastcall **)(__int64, char *))(*(_QWORD *)v11 + 8i64))(v11, &v29);
  }
  if ( (v12 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v11 + 16i64))(
      v11,
      &v10,
      COERCE_DOUBLE(*(_QWORD *)&v13));
    v11 = 0i64;
  }
  v12 = 0;
  if ( v9 )
    Scaleform::GFx::Movie::Invoke(v9, "setAcceptButtonPos", 0i64, (Scaleform::GFx::Value *)&ptr, 3u);
  `eh vector destructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 572
// RVA: 0x620020
void __fastcall UFG::UIHKScreenPokerDiceMinigame::enableProgression(UFG::UIHKScreenPokerDiceMinigame *this, bool bEnableProgression, bool bControlsOnly)
{
  bool v3; // bp
  UFG::UIHKScreenPokerDiceMinigame *v4; // rbx
  Scaleform::GFx::Movie *v5; // rdi
  bool v6; // si
  int v7; // edx
  UFG::eHKControllerInputMode v8; // ecx
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-40h]

  v3 = bControlsOnly;
  v4 = this;
  this->mbEnableProgression = bEnableProgression;
  v5 = this->mRenderable->m_movie.pObject;
  value.pObjectInterface = 0i64;
  value.Type = 0;
  v6 = this->mbEnableProgression;
  value.Type = 2;
  value.mValue.BValue = v6;
  if ( v5 )
    Scaleform::GFx::Movie::SetVariable(v5, "gameComplete_mc.endbtn._visible", &value, 1i64);
  if ( v4->mbEnableProgression )
  {
    if ( !v3 )
      UFG::UIHKScreenPokerDiceMinigame::bypassIntroScreens(v4, v5);
    v7 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->mControllerIndex;
    v8 = v4->mSavedControllerMode;
  }
  else
  {
    v4->mSavedControllerMode = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_ActiveMapSet;
    v7 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->mControllerIndex;
    v8 = 8;
  }
  UFG::SetInputMode(v8, v7);
  if ( ((unsigned int)value.Type >> 6) & 1 )
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
      value.pObjectInterface,
      &value,
      *(_QWORD *)&value.mValue.NValue);
}

// File Line: 602
// RVA: 0x61E840
void __fastcall UFG::UIHKScreenPokerDiceMinigame::bypassIntroScreens(UFG::UIHKScreenPokerDiceMinigame *this, Scaleform::GFx::Movie *movie)
{
  Scaleform::GFx::Movie *v2; // rdi
  UFG::UIHKScreenPokerDiceMinigame *v3; // rbx
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-40h]

  v2 = movie;
  v3 = this;
  this->mbKidnapperCase = 1;
  value.pObjectInterface = 0i64;
  value.Type = 2;
  value.mValue.BValue = 1;
  Scaleform::GFx::Movie::SetVariable(movie, "gbKidnapperCase", &value, 1i64);
  Scaleform::GFx::Movie::Invoke(v2, "resetGame", 0i64, &customWorldMapCaption, -2i64);
  UFG::AIScriptInterfaceComponent::BeginCommandActionRequest(v3->mPlayerAISIC);
  if ( UFG::AIScriptInterfaceComponent::GiveCommand(v3->mPlayerAISIC, eSCRIPT_COMMAND_SUBMIT_ACTION_REQUEST) )
  {
    UFG::AIScriptInterfaceComponent::AddArgument(v3->mPlayerAISIC, "Freerun");
    UFG::AIScriptInterfaceComponent::AddArgument(v3->mPlayerAISIC, "Initial");
  }
  if ( ((unsigned int)value.Type >> 6) & 1 )
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
      value.pObjectInterface,
      &value,
      *(_QWORD *)&value.mValue.NValue);
}

// File Line: 620
// RVA: 0x62FCD0
void __fastcall UFG::UIHKScreenPokerDiceMinigame::hideShowPayouts(UFG::UIHKScreenPokerDiceMinigame *this, Scaleform::GFx::Movie *movie)
{
  UFG::UIHKScreenPokerDiceMinigame *v2; // rbx
  bool v3; // al
  unsigned int v4; // edx

  v2 = this;
  Scaleform::GFx::Movie::Invoke(movie, "showHidePayouts", 0i64, &customWorldMapCaption);
  v3 = v2->mbPayoutsShown == 0;
  v2->mbPayoutsShown = v3;
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
  UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr, v4, 0i64, 0, 0i64);
}

