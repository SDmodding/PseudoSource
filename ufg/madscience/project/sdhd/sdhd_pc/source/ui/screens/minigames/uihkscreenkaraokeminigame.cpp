// File Line: 63
// RVA: 0x5C5CF0
void __fastcall UFG::UIHKScreenKaraokeMinigame::UIHKScreenKaraokeMinigame(UFG::UIHKScreenKaraokeMinigame *this)
{
  UFG::UIHKScreenKaraokeMinigame *v1; // rbx
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v2; // rax
  UFG::SimComponent *v3; // rdi
  float v4; // xmm1_4
  float v5; // xmm2_4
  hkgpIndexedMeshDefinitions::Edge *v6; // rdx
  hkgpIndexedMesh::EdgeBarrier *v7; // rcx
  UFG::qWiseSymbol *v8; // rax
  UFG::qWiseSymbol result; // [rsp+48h] [rbp+10h]

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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenKaraokeMinigame::`vftable;
  this->mBankID.mUID = -1;
  _((AMD_HD3D *)0xFFFFFFFFi64);
  v4 = UFG::qVector3::msZero.y;
  v5 = UFG::qVector3::msZero.z;
  v1->mStimulusParams.m_StimulusProducerOffset.x = UFG::qVector3::msZero.x;
  v1->mStimulusParams.m_StimulusProducerOffset.y = v4;
  v1->mStimulusParams.m_StimulusProducerOffset.z = v5;
  v1->mStimulusParams.m_StimulusEmissionType = -1;
  v1->mStimulusParams.m_MaxStimulusDuration = -1.0;
  v1->mStimulusParams.m_EmitUntilSpeedLessThan = -1.0;
  *(_WORD *)&v1->mbMusicStarted = 0;
  v1->mbMusicCalled = 0;
  UFG::UIHKScreenKaraokeMinigame::mbWon = 0;
  v1->markerIndex = 0;
  v1->mnSongs = 8;
  UFG::AudioEntity::StopAllEvents((unsigned __int64)UFG::Music::sm_instance);
  UFG::Music::sm_bRecievedMarker = 0;
  v1->minigameState = 0;
  v7 = (hkgpIndexedMesh::EdgeBarrier *)LocalPlayer;
  if ( LocalPlayer )
    v3 = UFG::SimObject::GetComponentOfType(
           (UFG::SimObject *)&LocalPlayer->vfptr,
           UFG::AIScriptInterfaceComponent::_TypeUID);
  v1->mPlayerAISIC = (UFG::AIScriptInterfaceComponent *)v3;
  if ( Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(v7, v6) )
  {
    v1->mFinished = 1;
  }
  else
  {
    v8 = UFG::qWiseSymbol::create_from_string(&result, "mg_karaoke");
    UFG::TiDo::LoadWwiseBank(v8);
    _((AMD_HD3D *)result.mUID);
    v1->mStimulusParams.m_StimulusEmissionType = 1;
  }
}

// File Line: 90
// RVA: 0x5CB330
void __fastcall UFG::UIHKScreenKaraokeMinigame::~UIHKScreenKaraokeMinigame(UFG::UIHKScreenKaraokeMinigame *this)
{
  UFG::UIHKScreenKaraokeMinigame *v1; // rbx
  UFG::UIScreenTextureManager *v2; // rax
  UFG::qWiseSymbol *v3; // rax
  UFG::qWiseSymbol result; // [rsp+48h] [rbp+10h]

  v1 = this;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenKaraokeMinigame::`vftable;
  v2 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v2, "KaraokeMinigame");
  UFG::Music::sm_bRecievedMarker = 0;
  v3 = UFG::qWiseSymbol::create_from_string(&result, "mg_karaoke");
  UFG::TiDo::UnloadWwiseBank(v3);
  _((AMD_HD3D *)result.mUID);
  _((AMD_HD3D *)v1->mBankID.mUID);
  UFG::UIHKMinigameScreen::~UIHKMinigameScreen((UFG::UIHKMinigameScreen *)&v1->vfptr);
}

// File Line: 97
// RVA: 0x6323F0
void __fastcall UFG::UIHKScreenKaraokeMinigame::init(UFG::UIHKScreenKaraokeMinigame *this, UFG::UICommandData *data)
{
  UFG::UIHKScreenKaraokeMinigame *v2; // rsi
  Scaleform::GFx::Movie *v3; // r14
  unsigned int v4; // edi
  UFG::qSymbol *v5; // rbx
  UFG::GameStatTracker *v6; // rax
  signed int v7; // ebx
  Scaleform::GFx::Value pargs; // [rsp+8h] [rbp-69h]
  char ptr; // [rsp+38h] [rbp-39h]
  __int64 v10; // [rsp+48h] [rbp-29h]
  unsigned int v11; // [rsp+50h] [rbp-21h]
  double v12; // [rsp+58h] [rbp-19h]
  char v13; // [rsp+68h] [rbp-9h]
  __int64 v14; // [rsp+78h] [rbp+7h]
  unsigned int v15; // [rsp+80h] [rbp+Fh]
  double v16; // [rsp+88h] [rbp+17h]
  __int64 v17; // [rsp+98h] [rbp+27h]
  UFG::qWiseSymbol result; // [rsp+D8h] [rbp+67h]

  v17 = -2i64;
  v2 = this;
  UFG::UIScreen::init((UFG::UIScreen *)&this->vfptr, data);
  v3 = v2->mRenderable->m_movie.pObject;
  UFG::UIHKScreenKaraokeMinigame::initSongList(v2);
  UFG::UIHKScreenKaraokeMinigame::mbInstrumentalSection = 1;
  v4 = 0;
  if ( v2->mnSongs )
  {
    do
    {
      v5 = (UFG::qSymbol *)UFG::qSymbol::qSymbol(&result, v4);
      v6 = UFG::GameStatTracker::Instance();
      v7 = UFG::GameStatTracker::GetStat(v6, 0, v5);
      *(_QWORD *)&pargs.Type = Scaleform::GFx::Value::~Value;
      `eh vector constructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      if ( (v11 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v10 + 16i64))(
          v10,
          &ptr,
          COERCE_DOUBLE(*(_QWORD *)&v12));
        v10 = 0i64;
      }
      v11 = 5;
      v12 = (double)(signed int)v4;
      if ( (v15 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v14 + 16i64))(
          v14,
          &v13,
          COERCE_DOUBLE(*(_QWORD *)&v16));
        v14 = 0i64;
      }
      v15 = 5;
      v16 = (double)v7;
      Scaleform::GFx::Movie::Invoke(v3, "initHighScores", 0i64, (Scaleform::GFx::Value *)&ptr, 2u);
      `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
      ++v4;
    }
    while ( v4 < v2->mnSongs );
  }
  *(_QWORD *)&pargs.Type = Scaleform::GFx::Value::~Value;
  `eh vector constructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  if ( ((unsigned int)pargs.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      *(_QWORD *)&pargs.mValue.NValue);
    pargs.pObjectInterface = 0i64;
  }
  pargs.mValue.NValue = 0.0;
  Scaleform::GFx::Movie::Invoke(v3, "highlightSelected", 0i64, &pargs, 1u);
  `eh vector destructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 124
// RVA: 0x63D870
void __fastcall UFG::UIHKScreenKaraokeMinigame::update(UFG::UIHKScreenKaraokeMinigame *this, float elapsed)
{
  float v2; // xmm7_4
  UFG::UIHKScreenKaraokeMinigame *v3; // rbx
  UFG::InputActionData *v4; // rcx
  float v5; // xmm0_4
  float v6; // xmm1_4
  UFG::InputActionData *v7; // rcx
  UFG::InputActionData *v8; // rcx
  char v9; // al
  UFG::InputActionData *v10; // rcx
  char v11; // al
  UFG::InputActionData *v12; // rcx
  char v13; // al
  UFG::InputActionData *v14; // rcx
  char v15; // al
  UFG::InputActionData *v16; // rax
  UFG::InputActionData *v17; // rcx
  UFG::InputActionData *v18; // rcx
  hkgpIndexedMeshDefinitions::Edge *v19; // rdx
  double v20; // xmm6_8
  double v21; // xmm6_8
  UFG::Controller *v22; // rcx
  bool v23; // di
  Scaleform::GFx::Movie *v24; // rdi
  unsigned int v25; // eax
  Scaleform::GFx::Value pval; // [rsp+30h] [rbp-B8h]
  char ptr; // [rsp+60h] [rbp-88h]
  double v28; // [rsp+68h] [rbp-80h]
  __int64 v29; // [rsp+70h] [rbp-78h]
  unsigned int v30; // [rsp+78h] [rbp-70h]
  __int64 v31; // [rsp+88h] [rbp-60h]
  unsigned int v32; // [rsp+90h] [rbp-58h]
  double v33; // [rsp+98h] [rbp-50h]
  char v34; // [rsp+A8h] [rbp-40h]
  __int64 v35; // [rsp+B8h] [rbp-30h]
  unsigned int v36; // [rsp+C0h] [rbp-28h]
  double v37; // [rsp+C8h] [rbp-20h]
  char v38; // [rsp+D8h] [rbp-10h]
  __int64 v39; // [rsp+E8h] [rbp+0h]
  unsigned int v40; // [rsp+F0h] [rbp+8h]
  __int64 v41; // [rsp+F8h] [rbp+10h]
  __int64 v42; // [rsp+108h] [rbp+20h]

  v42 = -2i64;
  v2 = elapsed;
  v3 = this;
  if ( !UFG::UIScreenManagerBase::getScreen(
          (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
          "NISPause") )
  {
    v4 = UFG::ActionDef_UILeftThumbstick.mDataPerController[UFG::gActiveControllerNum];
    v5 = 0.0;
    if ( v4 )
      v6 = v4->mAxisPositionX;
    else
      v6 = 0.0;
    v3->m_fLeftStickX = v6;
    v7 = UFG::ActionDef_UILeftThumbstick.mDataPerController[UFG::gActiveControllerNum];
    if ( v7 )
      v5 = v7->mAxisPositionY;
    v3->m_fLeftStickY = v5;
    v8 = UFG::ActionDef_UIAcceptPressed.mDataPerController[UFG::gActiveControllerNum];
    if ( !v8 || (v9 = 1, !v8->mActionTrue) )
      v9 = 0;
    v3->mbAButton = v9;
    v10 = UFG::ActionDef_UIBackPressed.mDataPerController[UFG::gActiveControllerNum];
    if ( !v10 || (v11 = 1, !v10->mActionTrue) )
      v11 = 0;
    v3->mbBButton = v11;
    v12 = UFG::ActionDef_UIButton1Pressed.mDataPerController[UFG::gActiveControllerNum];
    if ( !v12 || (v13 = 1, !v12->mActionTrue) )
      v13 = 0;
    v3->mbXButton = v13;
    v14 = UFG::ActionDef_UIButton2Pressed.mDataPerController[UFG::gActiveControllerNum];
    if ( !v14 || (v15 = 1, !v14->mActionTrue) )
      v15 = 0;
    v3->mbYButton = v15;
    if ( UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
    {
      v16 = UFG::ActionDef_UIUpRepeat.mDataPerController[UFG::gActiveControllerNum];
      if ( v16 && v16->mActionTrue )
        v5 = FLOAT_N1_0;
      v3->m_fLeftStickY = v5;
      v17 = UFG::ActionDef_UIDownRepeat.mDataPerController[UFG::gActiveControllerNum];
      if ( v17 && v17->mActionTrue )
        v5 = *(float *)&FLOAT_1_0;
      v3->m_fLeftStickY = v5;
      v18 = UFG::ActionDef_UIShiftRepeat.mDataPerController[UFG::gActiveControllerNum];
      if ( !v18 || !v18->mActionTrue )
        v3->m_fLeftStickY = v5 * 0.5;
    }
    `eh vector constructor iterator(&ptr, 0x30ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    v20 = v3->m_fLeftStickX;
    if ( (v30 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v29 + 16i64))(
        v29,
        &ptr,
        COERCE_DOUBLE(*(_QWORD *)&v28));
      v29 = 0i64;
    }
    v30 = 5;
    v28 = v20;
    v21 = v3->m_fLeftStickY;
    if ( (v32 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, unsigned int *, double))(*(_QWORD *)v31 + 16i64))(
        v31,
        &v30,
        COERCE_DOUBLE(*(_QWORD *)&v33));
      v31 = 0i64;
    }
    v32 = 5;
    v33 = v21;
    if ( (v36 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v35 + 16i64))(
        v35,
        &v34,
        COERCE_DOUBLE(*(_QWORD *)&v37));
      v35 = 0i64;
    }
    v36 = 5;
    v37 = v2;
    v22 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum];
    v23 = v22->m_IsKeyboardController;
    if ( (v40 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v39 + 16i64))(v39, &v38, v41);
      v39 = 0i64;
    }
    v40 = 2;
    LOBYTE(v41) = v23;
    v24 = v3->mRenderable->m_movie.pObject;
    if ( v3->minigameState == 1 )
    {
      Scaleform::GFx::Movie::Invoke(v24, "mainLoop", 0i64, (Scaleform::GFx::Value *)&ptr, 4u);
      pval.pObjectInterface = 0i64;
      pval.Type = 0;
      Scaleform::GFx::Movie::GetVariable(v24, &pval, "gInstrumental");
      UFG::UIHKScreenKaraokeMinigame::mbInstrumentalSection = pval.mValue.BValue;
      if ( UFG::Music::sm_bRecievedMarker )
      {
        Scaleform::GFx::Movie::Invoke(v24, "phraseSignal", 0i64, 0i64, 0);
        UFG::Music::sm_bRecievedMarker = 0;
      }
      if ( ((unsigned int)pval.Type >> 6) & 1 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pval.pObjectInterface->vfptr->gap8[8])(
          pval.pObjectInterface,
          &pval,
          *(_QWORD *)&pval.mValue.NValue);
        pval.pObjectInterface = 0i64;
      }
      pval.Type = 0;
    }
    if ( v3->mbMusicStarted )
    {
      if ( !((unsigned int (__cdecl *)(UFG::Music *))UFG::Music::sm_instance->vfptr->CountNumPlayingEvents)(UFG::Music::sm_instance) )
      {
        v3->minigameState = 2;
        UFG::UIHKScreenKaraokeMinigame::stopAllStimuli(v3);
        `eh vector constructor iterator(&pval, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
        if ( ((unsigned int)pval.Type >> 6) & 1 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pval.pObjectInterface->vfptr->gap8[8])(
            pval.pObjectInterface,
            &pval,
            *(_QWORD *)&pval.mValue.NValue);
          pval.pObjectInterface = 0i64;
        }
        pval.Type = 5;
        pval.mValue.NValue = DOUBLE_2_0;
        Scaleform::GFx::Movie::Invoke(v24, "setState", 0i64, &pval, 1u);
        UFG::TiDo::UnloadWwiseBank(&v3->mBankID);
        v3->mbMusicStarted = 0;
        `eh vector destructor iterator(&pval, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
      }
    }
    else
    {
      UFG::Music::sm_bIsObjectActiveDirty = 1;
      if ( Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
             (hkgpIndexedMesh::EdgeBarrier *)v22,
             v19)
        || !UFG::Music::sm_bIsObjectActive )
      {
        if ( (unsigned __int8)UFG::TiDo::BankLoaded(v3->mBankID.mUID) && !v3->mbMusicCalled )
        {
          v25 = UFG::TiDo::CalcWwiseUid(UFG::gKaraokeMusicTrackNames[v3->mSongIndex]);
          UFG::Music::MusicEvent(v25);
          v3->mbMusicCalled = 1;
        }
      }
      else
      {
        v3->mbMusicStarted = 1;
        v3->minigameState = 1;
      }
    }
    UFG::UIScreen::update((UFG::UIScreen *)&v3->vfptr, v2);
    `eh vector destructor iterator(&ptr, 0x30ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 218
// RVA: 0x6241D0
char __fastcall UFG::UIHKScreenKaraokeMinigame::handleMessage(UFG::UIHKScreenKaraokeMinigame *this, __int64 msgId, UFG::UIMessage *msg)
{
  UFG::UIMessage *v3; // r13
  unsigned int v4; // er14
  UFG::UIHKScreenKaraokeMinigame *v5; // rsi
  UFG::UIHKScreenKaraokeMinigame::State v6; // eax
  Scaleform::GFx::Movie *v7; // r15
  const char *v8; // rdx
  unsigned int v9; // eax
  __int64 v10; // rax
  UFG::qSymbol *v11; // rbx
  UFG::GameStatTracker *v12; // rax
  UFG::qWiseSymbol *v14; // rax
  UFG::AIScriptInterfaceComponent *v15; // rcx
  Scaleform::GFx::Movie *v16; // rcx
  signed int v17; // ebx
  UFG::qNode<UFG::qString,UFG::qString> *v18; // rsi
  unsigned int v19; // edi
  UFG::Music *v20; // rbx
  signed int v21; // eax
  UFG::qString *i; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v23; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v24; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v25; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v26; // rax
  UFG::AIScriptInterfaceComponent *v27; // rcx
  UFG::AIScriptInterfaceComponent *v28; // rcx
  UFG::AIScriptInterfaceComponent *v29; // rcx
  UFG::AIScriptInterfaceComponent *v30; // rcx
  UFG::AIScriptInterfaceComponent *v31; // rcx
  unsigned int v32; // eax
  UFG::eStimulusType v33; // edx
  UFG::eStimulusType v34; // edx
  unsigned int v35; // eax
  Scaleform::GFx::Movie *v36; // rcx
  unsigned int v37; // edx
  UFG::qList<UFG::qString,UFG::qString,1,0> list; // [rsp+8h] [rbp-69h]
  char ptr; // [rsp+18h] [rbp-59h]
  UFG::AudioEventExternalSourceInfo *externalSourceInfo; // [rsp+20h] [rbp-51h]
  __int64 v41; // [rsp+28h] [rbp-49h]
  unsigned int v42; // [rsp+30h] [rbp-41h]
  double v43; // [rsp+38h] [rbp-39h]
  Scaleform::GFx::Value pval; // [rsp+48h] [rbp-29h]
  UFG::qString v45; // [rsp+78h] [rbp+7h]
  __int64 v46; // [rsp+A0h] [rbp+2Fh]
  UFG::qSymbol result; // [rsp+D8h] [rbp+67h]

  v46 = -2i64;
  v3 = msg;
  v4 = msgId;
  v5 = this;
  v6 = this->minigameState;
  if ( v6 == SONG_SELECTION )
  {
    v7 = this->mRenderable->m_movie.pObject;
    if ( (_DWORD)msgId == UI_HASH_DPAD_DOWN_PRESSED_30 || (_DWORD)msgId == UI_HASH_THUMBSTICK_LEFT_DOWN_30 )
    {
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(
          (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
          0xC415B16F,
          0i64,
          0,
          0i64);
      v8 = "highlightNext";
    }
    else
    {
      if ( (_DWORD)msgId != UI_HASH_DPAD_UP_PRESSED_30 && (_DWORD)msgId != UI_HASH_THUMBSTICK_LEFT_UP_30 )
      {
LABEL_13:
        if ( v4 == UI_HASH_BUTTON_BACK_PRESSED_30 )
        {
          if ( UFG::HudAudio::m_instance )
            UFG::AudioEntity::CreateAndPlayEvent(
              (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
              0xA4E5BFBD,
              0i64,
              0,
              0i64);
          v5->mFinished = 1;
          return UFG::UIHKMinigameScreen::handleMessage((UFG::UIHKMinigameScreen *)&v5->vfptr, v4, v3);
        }
        if ( v4 == UI_HASH_BUTTON_ACCEPT_PRESSED_30 )
        {
          pval.pObjectInterface = 0i64;
          pval.Type = 0;
          v5->mSongIndex = 0;
          Scaleform::GFx::Movie::GetVariable(v7, &pval, "gTargetSong");
          v9 = (signed int)pval.mValue.NValue;
          v5->mSongIndex = (signed int)pval.mValue.NValue;
          UFG::qString::qString(&v45, "Song%d", v9);
          v11 = UFG::qSymbol::create_from_string(&result, *(const char **)(v10 + 24));
          v12 = UFG::GameStatTracker::Instance();
          LOBYTE(v11) = UFG::GameStatTracker::GetStat(v12, KaraokeSongs, v11);
          UFG::qString::~qString(&v45);
          if ( !(_BYTE)v11 )
          {
            if ( UFG::HudAudio::m_instance )
              UFG::AudioEntity::CreateAndPlayEvent(
                (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
                0x9E75334E,
                0i64,
                0,
                0i64);
            v14 = UFG::qWiseSymbol::create_from_string(
                    (UFG::qWiseSymbol *)&result,
                    UFG::gKaraokeSoundbankNames[v5->mSongIndex]);
            UFG::qWiseSymbol::operator=(&v5->mBankID, v14);
            _((AMD_HD3D *)result.mUID);
            UFG::TiDo::LoadWwiseBank(&v5->mBankID);
            v5->mbSongSelected = 1;
            externalSourceInfo = (UFG::AudioEventExternalSourceInfo *)Scaleform::GFx::Value::~Value;
            `eh vector constructor iterator(
              &ptr,
              0x30ui64,
              1,
              (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
            if ( (v42 >> 6) & 1 )
            {
              (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v41 + 16i64))(
                v41,
                &ptr,
                COERCE_DOUBLE(*(_QWORD *)&v43));
              v41 = 0i64;
            }
            v42 = 5;
            v43 = DOUBLE_1_0;
            Scaleform::GFx::Movie::Invoke(v7, "setState", 0i64, (Scaleform::GFx::Value *)&ptr, 1u);
            UFG::AIScriptInterfaceComponent::BeginCommandActionRequest(v5->mPlayerAISIC);
            if ( UFG::AIScriptInterfaceComponent::GiveCommand(v5->mPlayerAISIC, eSCRIPT_COMMAND_SUBMIT_ACTION_REQUEST) )
            {
              UFG::AIScriptInterfaceComponent::AddArgument(v5->mPlayerAISIC, "KaraokeSongPicked");
              UFG::AIScriptInterfaceComponent::AddArgument(v5->mPlayerAISIC, "Walking_back");
            }
            v15 = v5->mPlayerAISIC;
            if ( v15 )
              UFG::AIScriptInterfaceComponent::StartHoldingActionRequest(v15, "KaraokeInstrumental2");
            `eh vector destructor iterator(
              &ptr,
              0x30ui64,
              1,
              (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
            if ( ((unsigned int)pval.Type >> 6) & 1 )
            {
              (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pval.pObjectInterface->vfptr->gap8[8])(
                pval.pObjectInterface,
                &pval,
                *(_QWORD *)&pval.mValue.NValue);
              pval.pObjectInterface = 0i64;
            }
            pval.Type = 0;
            return UFG::UIHKMinigameScreen::handleMessage((UFG::UIHKMinigameScreen *)&v5->vfptr, v4, v3);
          }
          if ( ((unsigned int)pval.Type >> 6) & 1 )
          {
            (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pval.pObjectInterface->vfptr->gap8[8])(
              pval.pObjectInterface,
              &pval,
              *(_QWORD *)&pval.mValue.NValue);
            pval.pObjectInterface = 0i64;
          }
          pval.Type = 0;
          return 1;
        }
        return UFG::UIHKMinigameScreen::handleMessage((UFG::UIHKMinigameScreen *)&v5->vfptr, v4, v3);
      }
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(
          (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
          0xC415B16F,
          0i64,
          0,
          0i64);
      v8 = "highlightPrevious";
    }
    Scaleform::GFx::Movie::Invoke(v7, v8, 0i64, 0i64, 0);
    goto LABEL_13;
  }
  if ( v6 != 1 )
  {
    if ( (_DWORD)msgId == UI_HASH_BUTTON_BACK_PRESSED_30 )
    {
      UFG::UIHKScreenKaraokeMinigame::mbWon = 1;
      this->mFinished = 1;
      return UFG::UIHKMinigameScreen::handleMessage((UFG::UIHKMinigameScreen *)&v5->vfptr, v4, v3);
    }
    if ( (_DWORD)msgId == UI_HASH_PLAYSOUND_20 )
    {
      UFG::qString::qString(&v45, (UFG::qString *)&msg[1]);
      v35 = UFG::TiDo::CalcWwiseUid(v45.mData);
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr, v35, 0i64, 0, 0i64);
      UFG::qString::~qString(&v45);
      return 1;
    }
    if ( (_DWORD)msgId != UI_HASH_SETTUTORIAL1_20 )
      return UFG::UIHKMinigameScreen::handleMessage((UFG::UIHKMinigameScreen *)&v5->vfptr, v4, v3);
    v36 = this->mRenderable->m_movie.pObject;
    v41 = 0i64;
    v42 = 0;
    Scaleform::GFx::Movie::GetVariable(v36, (Scaleform::GFx::Value *)&ptr, "gScore");
    v37 = (signed int)v43;
    if ( !(signed int)v43 )
      v37 = 111;
    LODWORD(UFG::UIHKScreenKaraokeMinigame::mScore) = v37;
    UFG::GameStatAction::MiniGame::KaraokeSongCompleted(v5->mSongIndex, v37, v5->mnSongs);
    goto LABEL_84;
  }
  v16 = this->mRenderable->m_movie.pObject;
  if ( (_DWORD)msgId != UI_HASH_MODIFYRTPC_20 )
  {
    if ( (_DWORD)msgId == UI_HASH_KARAOKEINSTRUM1_20 )
    {
      v27 = v5->mPlayerAISIC;
      if ( v27 )
        UFG::AIScriptInterfaceComponent::StartHoldingActionRequest(v27, "KaraokeInstrumental1");
      return UFG::UIHKMinigameScreen::handleMessage((UFG::UIHKMinigameScreen *)&v5->vfptr, v4, v3);
    }
    if ( (_DWORD)msgId == UI_HASH_KARAOKEINSTRUM2_20 )
    {
      v28 = v5->mPlayerAISIC;
      if ( v28 )
        UFG::AIScriptInterfaceComponent::StartHoldingActionRequest(v28, "KaraokeInstrumental2");
      return UFG::UIHKMinigameScreen::handleMessage((UFG::UIHKMinigameScreen *)&v5->vfptr, v4, v3);
    }
    if ( (_DWORD)msgId == UI_HASH_KARAOKEINSTRUM3_20 )
    {
      v29 = v5->mPlayerAISIC;
      if ( v29 )
        UFG::AIScriptInterfaceComponent::StartHoldingActionRequest(v29, "KaraokeInstrumental3");
      return UFG::UIHKMinigameScreen::handleMessage((UFG::UIHKMinigameScreen *)&v5->vfptr, v4, v3);
    }
    if ( (_DWORD)msgId == UI_HASH_KARAOKEINSTRUMGUITAR_20 )
    {
      v30 = v5->mPlayerAISIC;
      if ( v30 )
        UFG::AIScriptInterfaceComponent::StartHoldingActionRequest(v30, "KaraokeInstrumentalGuitar");
      return UFG::UIHKMinigameScreen::handleMessage((UFG::UIHKMinigameScreen *)&v5->vfptr, v4, v3);
    }
    if ( (_DWORD)msgId == UI_HASH_KARAOKEINSTRUMOFF_20 )
    {
      v31 = v5->mPlayerAISIC;
      if ( v31 )
        UFG::AIScriptInterfaceComponent::StopHoldingAllActionRequests(v31);
      return UFG::UIHKMinigameScreen::handleMessage((UFG::UIHKMinigameScreen *)&v5->vfptr, v4, v3);
    }
    if ( (_DWORD)msgId == UI_HASH_PLAYSOUND_20 )
    {
      UFG::qString::qString(&v45, (UFG::qString *)&msg[1]);
      v32 = UFG::TiDo::CalcWwiseUid(v45.mData);
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr, v32, 0i64, 0, 0i64);
      UFG::qString::~qString(&v45);
      return 1;
    }
    if ( (_DWORD)msgId == UI_HASH_BUTTON_BACK_PRESSED_30 )
    {
      UFG::AudioEntity::StopAllEvents((unsigned __int64)UFG::Music::sm_instance);
      UFG::TiDo::UnloadWwiseBank(&v5->mBankID);
      UFG::UIHKScreenKaraokeMinigame::stopAllStimuli(v5);
      v5->mFinished = 1;
      return UFG::UIHKMinigameScreen::handleMessage((UFG::UIHKMinigameScreen *)&v5->vfptr, v4, v3);
    }
    if ( (_DWORD)msgId != UI_HASH_SENDSTIMULUS_20 )
      return UFG::UIHKMinigameScreen::handleMessage((UFG::UIHKMinigameScreen *)&v5->vfptr, v4, v3);
    v41 = 0i64;
    v42 = 0;
    Scaleform::GFx::Movie::GetVariable(v16, (Scaleform::GFx::Value *)&ptr, "gStimulus");
    switch ( (signed int)v43 )
    {
      case 0:
        UFG::StimulusManager::BeginStimulus(
          UFG::StimulusManager::s_pInstance,
          eSTIMULUS_KARAOKE_SINGING_PERFECT,
          &v5->mStimulusParams,
          (UFG::SimObject *)&LocalPlayer->vfptr);
        v33 = 93;
        goto LABEL_71;
      case 1:
        UFG::StimulusManager::BeginStimulus(
          UFG::StimulusManager::s_pInstance,
          eSTIMULUS_KARAOKE_SINGING_GOOD,
          &v5->mStimulusParams,
          (UFG::SimObject *)&LocalPlayer->vfptr);
        UFG::StimulusManager::EndStimulus(
          UFG::StimulusManager::s_pInstance,
          eSTIMULUS_KARAOKE_SINGING_BAD,
          (UFG::SimObject *)&LocalPlayer->vfptr);
        v34 = 95;
LABEL_72:
        UFG::StimulusManager::EndStimulus(UFG::StimulusManager::s_pInstance, v34, (UFG::SimObject *)&LocalPlayer->vfptr);
        break;
      case 2:
        UFG::StimulusManager::BeginStimulus(
          UFG::StimulusManager::s_pInstance,
          eSTIMULUS_KARAOKE_SINGING_BAD,
          &v5->mStimulusParams,
          (UFG::SimObject *)&LocalPlayer->vfptr);
        v33 = 95;
LABEL_71:
        UFG::StimulusManager::EndStimulus(UFG::StimulusManager::s_pInstance, v33, (UFG::SimObject *)&LocalPlayer->vfptr);
        v34 = 94;
        goto LABEL_72;
    }
LABEL_84:
    if ( (v42 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v41 + 16i64))(
        v41,
        &ptr,
        COERCE_DOUBLE(*(_QWORD *)&v43));
      v41 = 0i64;
    }
    v42 = 0;
    return UFG::UIHKMinigameScreen::handleMessage((UFG::UIHKMinigameScreen *)&v5->vfptr, v4, v3);
  }
  if ( Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
         (hkgpIndexedMesh::EdgeBarrier *)v16,
         (hkgpIndexedMeshDefinitions::Edge *)msgId) )
  {
    return 1;
  }
  UFG::qString::qString(&v45, (UFG::qString *)&v3[1]);
  UFG::qString::Tokenize(&v45, &list, ",", "Karaoke.HandleMessage");
  v17 = 1;
  v18 = list.mNode.mNext;
  do
  {
    if ( v18 == (UFG::qNode<UFG::qString,UFG::qString> *)&list )
      break;
    --v17;
    v18 = v18->mNext;
  }
  while ( v17 > 0 );
  v19 = UFG::TiDo::CalcWwiseUid((const char *)list.mNode.mNext[1].mNext);
  v20 = UFG::Music::sm_instance;
  v21 = UFG::qToInt32((const char *)v18[1].mNext, 0);
  UFG::AudioEntity::SetRtpcValue((UFG::AudioEntity *)&v20->vfptr, v19, (float)v21);
  for ( i = (UFG::qString *)list.mNode.mNext;
        (UFG::qList<UFG::qString,UFG::qString,1,0> *)list.mNode.mNext != &list;
        i = (UFG::qString *)list.mNode.mNext )
  {
    v23 = i->mPrev;
    v24 = i->mNext;
    v23->mNext = v24;
    v24->mPrev = v23;
    i->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&i->mPrev;
    i->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&i->mPrev;
    UFG::qString::~qString(i);
    operator delete[](i);
  }
  v25 = list.mNode.mPrev;
  v26 = list.mNode.mNext;
  list.mNode.mPrev->mNext = list.mNode.mNext;
  v26->mPrev = v25;
  UFG::qString::~qString(&v45);
  return 1;
}

// File Line: 431
// RVA: 0x6383D0
void __fastcall UFG::UIHKScreenKaraokeMinigame::initSongList(UFG::UIHKScreenKaraokeMinigame *this)
{
  UFG::UIHKScreenKaraokeMinigame *v1; // rsi
  Scaleform::GFx::Movie *v2; // r14
  unsigned int v3; // ebx
  __int64 v4; // rax
  UFG::GameStatTracker *v5; // rax
  bool v6; // di
  double v7; // xmm6_8
  bool v8; // di
  char ptr; // [rsp+30h] [rbp-A8h]
  __int64 v10; // [rsp+40h] [rbp-98h]
  unsigned int v11; // [rsp+48h] [rbp-90h]
  double v12; // [rsp+50h] [rbp-88h]
  double v13; // [rsp+58h] [rbp-80h]
  char v14; // [rsp+60h] [rbp-78h]
  char v15; // [rsp+68h] [rbp-70h]
  __int64 v16; // [rsp+70h] [rbp-68h]
  __int64 v17; // [rsp+78h] [rbp-60h]
  unsigned int v18; // [rsp+80h] [rbp-58h]
  double v19; // [rsp+88h] [rbp-50h]
  char v20; // [rsp+98h] [rbp-40h]
  __int64 v21; // [rsp+A8h] [rbp-30h]
  unsigned int v22; // [rsp+B0h] [rbp-28h]
  __int64 v23; // [rsp+B8h] [rbp-20h]
  __int64 v24; // [rsp+C8h] [rbp-10h]
  UFG::qString v25; // [rsp+D0h] [rbp-8h]
  UFG::qSymbol result; // [rsp+138h] [rbp+60h]

  v24 = -2i64;
  v1 = this;
  `eh vector constructor iterator(&ptr, 0x30ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  v2 = v1->mRenderable->m_movie.pObject;
  v3 = 0;
  if ( v1->mnSongs )
  {
    do
    {
      UFG::qString::qString(&v25, "Song%d", v3);
      UFG::qSymbol::create_from_string(&result, *(const char **)(v4 + 24));
      UFG::qString::~qString(&v25);
      v5 = UFG::GameStatTracker::Instance();
      v6 = UFG::GameStatTracker::GetStat(v5, KaraokeSongs, &result);
      if ( (v11 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v10 + 16i64))(
          v10,
          &ptr,
          COERCE_DOUBLE(*(_QWORD *)&v12));
        v10 = 0i64;
      }
      v11 = 5;
      v12 = (double)(signed int)v3;
      if ( ((unsigned int)v17 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v16 + 16i64))(
          v16,
          &v14,
          COERCE_DOUBLE(*(_QWORD *)&v13));
        v16 = 0i64;
      }
      LODWORD(v17) = 5;
      v13 = (double)v6;
      v7 = (double)(signed int)v1->mnSongs;
      if ( (v18 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v17 + 16i64))(
          v17,
          &v15,
          COERCE_DOUBLE(*(_QWORD *)&v19));
        v17 = 0i64;
      }
      v18 = 5;
      v19 = v7;
      v8 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController;
      if ( (v22 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v21 + 16i64))(v21, &v20, v23);
        v21 = 0i64;
      }
      v22 = 2;
      LOBYTE(v23) = v8;
      Scaleform::GFx::Movie::Invoke(v2, "initSongSelection", 0i64, (Scaleform::GFx::Value *)&ptr, 4u);
      ++v3;
    }
    while ( v3 < v1->mnSongs );
  }
  `eh vector destructor iterator(&ptr, 0x30ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 450
// RVA: 0x63B350
void __fastcall UFG::UIHKScreenKaraokeMinigame::stopAllStimuli(UFG::UIHKScreenKaraokeMinigame *this)
{
  UFG::StimulusManager::EndStimulus(
    UFG::StimulusManager::s_pInstance,
    eSTIMULUS_KARAOKE_SINGING_BAD,
    (UFG::SimObject *)&LocalPlayer->vfptr);
  UFG::StimulusManager::EndStimulus(
    UFG::StimulusManager::s_pInstance,
    eSTIMULUS_KARAOKE_SINGING_GOOD,
    (UFG::SimObject *)&LocalPlayer->vfptr);
  UFG::StimulusManager::EndStimulus(
    UFG::StimulusManager::s_pInstance,
    eSTIMULUS_KARAOKE_SINGING_PERFECT,
    (UFG::SimObject *)&LocalPlayer->vfptr);
}

