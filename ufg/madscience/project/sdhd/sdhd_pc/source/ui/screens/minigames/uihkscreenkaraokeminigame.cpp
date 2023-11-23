// File Line: 63
// RVA: 0x5C5CF0
void __fastcall UFG::UIHKScreenKaraokeMinigame::UIHKScreenKaraokeMinigame(UFG::UIHKScreenKaraokeMinigame *this)
{
  UFG::AIScriptInterfaceComponent *ComponentOfType; // rdi
  float y; // xmm1_4
  float z; // xmm2_4
  hkgpIndexedMeshDefinitions::Edge *v5; // rdx
  hkgpIndexedMesh::EdgeBarrier *v6; // rcx
  UFG::qWiseSymbol *v7; // rax
  UFG::qWiseSymbol result; // [rsp+48h] [rbp+10h] BYREF

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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenKaraokeMinigame::`vftable;
  this->mBankID.mUID = -1;
  _((AMD_HD3D *)0xFFFFFFFFi64);
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->mStimulusParams.m_StimulusProducerOffset.x = UFG::qVector3::msZero.x;
  this->mStimulusParams.m_StimulusProducerOffset.y = y;
  this->mStimulusParams.m_StimulusProducerOffset.z = z;
  this->mStimulusParams.m_StimulusEmissionType = eSTIMULUS_EMISSION_NONE;
  this->mStimulusParams.m_MaxStimulusDuration = -1.0;
  this->mStimulusParams.m_EmitUntilSpeedLessThan = -1.0;
  *(_WORD *)&this->mbMusicStarted = 0;
  this->mbMusicCalled = 0;
  UFG::UIHKScreenKaraokeMinigame::mbWon = 0;
  this->markerIndex = 0;
  this->mnSongs = 8;
  UFG::AudioEntity::StopAllEvents((unsigned __int64)UFG::Music::sm_instance);
  UFG::Music::sm_bRecievedMarker = 0;
  this->minigameState = SONG_SELECTION;
  v6 = (hkgpIndexedMesh::EdgeBarrier *)LocalPlayer;
  if ( LocalPlayer )
    ComponentOfType = (UFG::AIScriptInterfaceComponent *)UFG::SimObject::GetComponentOfType(
                                                           LocalPlayer,
                                                           UFG::AIScriptInterfaceComponent::_TypeUID);
  this->mPlayerAISIC = ComponentOfType;
  if ( Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(v6, v5) )
  {
    this->mFinished = 1;
  }
  else
  {
    v7 = UFG::qWiseSymbol::create_from_string(&result, "mg_karaoke");
    UFG::TiDo::LoadWwiseBank(v7);
    _((AMD_HD3D *)result.mUID);
    this->mStimulusParams.m_StimulusEmissionType = eSTIMULUS_EMISSION_CONTINUOUS;
  }
}

// File Line: 90
// RVA: 0x5CB330
void __fastcall UFG::UIHKScreenKaraokeMinigame::~UIHKScreenKaraokeMinigame(UFG::UIHKScreenKaraokeMinigame *this)
{
  UFG::UIScreenTextureManager *v2; // rax
  UFG::qWiseSymbol *v3; // rax
  UFG::qWiseSymbol result; // [rsp+48h] [rbp+10h] BYREF

  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenKaraokeMinigame::`vftable;
  v2 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v2, "KaraokeMinigame");
  UFG::Music::sm_bRecievedMarker = 0;
  v3 = UFG::qWiseSymbol::create_from_string(&result, "mg_karaoke");
  UFG::TiDo::UnloadWwiseBank(v3);
  _((AMD_HD3D *)result.mUID);
  _((AMD_HD3D *)this->mBankID.mUID);
  UFG::UIHKMinigameScreen::~UIHKMinigameScreen(this);
}

// File Line: 97
// RVA: 0x6323F0
void __fastcall UFG::UIHKScreenKaraokeMinigame::init(UFG::UIHKScreenKaraokeMinigame *this, UFG::UICommandData *data)
{
  Scaleform::GFx::Movie *pObject; // r14
  int i; // edi
  UFG::qSymbol *v5; // rbx
  UFG::GameStatTracker *v6; // rax
  int Stat; // ebx
  Scaleform::GFx::Value pargs; // [rsp+8h] [rbp-69h] BYREF
  Scaleform::GFx::Value ptr; // [rsp+38h] [rbp-39h] BYREF
  char v10[16]; // [rsp+68h] [rbp-9h] BYREF
  __int64 v11; // [rsp+78h] [rbp+7h]
  int v12; // [rsp+80h] [rbp+Fh]
  double v13; // [rsp+88h] [rbp+17h]
  __int64 v14; // [rsp+98h] [rbp+27h]
  UFG::qWiseSymbol result; // [rsp+D8h] [rbp+67h] BYREF

  v14 = -2i64;
  UFG::UIScreen::init(this, data);
  pObject = this->mRenderable->m_movie.pObject;
  UFG::UIHKScreenKaraokeMinigame::initSongList(this);
  UFG::UIHKScreenKaraokeMinigame::mbInstrumentalSection = 1;
  for ( i = 0; i < this->mnSongs; ++i )
  {
    v5 = (UFG::qSymbol *)UFG::qSymbol::qSymbol(&result, i);
    v6 = UFG::GameStatTracker::Instance();
    Stat = UFG::GameStatTracker::GetStat(v6, KaraokeScores, v5);
    *(_QWORD *)&pargs.Type = Scaleform::GFx::Value::~Value;
    `eh vector constructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( (ptr.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
        ptr.pObjectInterface,
        &ptr,
        ptr.mValue);
      ptr.pObjectInterface = 0i64;
    }
    ptr.Type = VT_Number;
    ptr.mValue.NValue = (double)i;
    if ( (v12 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v11 + 16i64))(
        v11,
        v10,
        COERCE_DOUBLE(*(_QWORD *)&v13));
      v11 = 0i64;
    }
    v12 = 5;
    v13 = (double)Stat;
    Scaleform::GFx::Movie::Invoke(pObject, "initHighScores", 0i64, &ptr, 2u);
    `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
  *(_QWORD *)&pargs.Type = Scaleform::GFx::Value::~Value;
  `eh vector constructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  if ( (pargs.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      pargs.mValue);
    pargs.pObjectInterface = 0i64;
  }
  pargs.mValue.pString = 0i64;
  Scaleform::GFx::Movie::Invoke(pObject, "highlightSelected", 0i64, &pargs, 1u);
  `eh vector destructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 124
// RVA: 0x63D870
void __fastcall UFG::UIHKScreenKaraokeMinigame::update(UFG::UIHKScreenKaraokeMinigame *this, float elapsed)
{
  UFG::InputActionData *v4; // rcx
  float mAxisPositionY; // xmm0_4
  float mAxisPositionX; // xmm1_4
  UFG::InputActionData *v7; // rcx
  UFG::InputActionData *v8; // rcx
  bool v9; // al
  UFG::InputActionData *v10; // rcx
  bool v11; // al
  UFG::InputActionData *v12; // rcx
  bool v13; // al
  UFG::InputActionData *v14; // rcx
  bool v15; // al
  UFG::InputActionData *v16; // rax
  UFG::InputActionData *v17; // rcx
  UFG::InputActionData *v18; // rcx
  hkgpIndexedMeshDefinitions::Edge *v19; // rdx
  double m_fLeftStickX; // xmm6_8
  double m_fLeftStickY; // xmm6_8
  UFG::Controller *v22; // rcx
  bool m_IsKeyboardController; // di
  Scaleform::GFx::Movie *pObject; // rdi
  unsigned int v25; // eax
  Scaleform::GFx::Value pval; // [rsp+30h] [rbp-B8h] BYREF
  Scaleform::GFx::Value ptr; // [rsp+60h] [rbp-88h] BYREF
  int v28; // [rsp+90h] [rbp-58h]
  double v29; // [rsp+98h] [rbp-50h]
  char v30[16]; // [rsp+A8h] [rbp-40h] BYREF
  __int64 v31; // [rsp+B8h] [rbp-30h]
  int v32; // [rsp+C0h] [rbp-28h]
  double v33; // [rsp+C8h] [rbp-20h]
  char v34[16]; // [rsp+D8h] [rbp-10h] BYREF
  __int64 v35; // [rsp+E8h] [rbp+0h]
  int v36; // [rsp+F0h] [rbp+8h]
  __int64 v37; // [rsp+F8h] [rbp+10h]
  __int64 v38; // [rsp+108h] [rbp+20h]

  v38 = -2i64;
  if ( !UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "NISPause") )
  {
    v4 = UFG::ActionDef_UILeftThumbstick.mDataPerController[UFG::gActiveControllerNum];
    mAxisPositionY = 0.0;
    if ( v4 )
      mAxisPositionX = v4->mAxisPositionX;
    else
      mAxisPositionX = 0.0;
    this->m_fLeftStickX = mAxisPositionX;
    v7 = UFG::ActionDef_UILeftThumbstick.mDataPerController[UFG::gActiveControllerNum];
    if ( v7 )
      mAxisPositionY = v7->mAxisPositionY;
    this->m_fLeftStickY = mAxisPositionY;
    v8 = UFG::ActionDef_UIAcceptPressed.mDataPerController[UFG::gActiveControllerNum];
    if ( !v8 || (v9 = 1, !v8->mActionTrue) )
      v9 = 0;
    this->mbAButton = v9;
    v10 = UFG::ActionDef_UIBackPressed.mDataPerController[UFG::gActiveControllerNum];
    if ( !v10 || (v11 = 1, !v10->mActionTrue) )
      v11 = 0;
    this->mbBButton = v11;
    v12 = UFG::ActionDef_UIButton1Pressed.mDataPerController[UFG::gActiveControllerNum];
    if ( !v12 || (v13 = 1, !v12->mActionTrue) )
      v13 = 0;
    this->mbXButton = v13;
    v14 = UFG::ActionDef_UIButton2Pressed.mDataPerController[UFG::gActiveControllerNum];
    if ( !v14 || (v15 = 1, !v14->mActionTrue) )
      v15 = 0;
    this->mbYButton = v15;
    if ( UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
    {
      v16 = UFG::ActionDef_UIUpRepeat.mDataPerController[UFG::gActiveControllerNum];
      if ( v16 && v16->mActionTrue )
        mAxisPositionY = FLOAT_N1_0;
      this->m_fLeftStickY = mAxisPositionY;
      v17 = UFG::ActionDef_UIDownRepeat.mDataPerController[UFG::gActiveControllerNum];
      if ( v17 && v17->mActionTrue )
        mAxisPositionY = *(float *)&FLOAT_1_0;
      this->m_fLeftStickY = mAxisPositionY;
      v18 = UFG::ActionDef_UIShiftRepeat.mDataPerController[UFG::gActiveControllerNum];
      if ( !v18 || !v18->mActionTrue )
        this->m_fLeftStickY = mAxisPositionY * 0.5;
    }
    `eh vector constructor iterator(&ptr, 0x30ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    m_fLeftStickX = this->m_fLeftStickX;
    if ( (ptr.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value *))&ptr.pObjectInterface->vfptr->gap8[8])(
        ptr.pObjectInterface,
        &ptr,
        ptr.pNext);
      ptr.pObjectInterface = 0i64;
    }
    ptr.Type = VT_Number;
    *(double *)&ptr.pNext = m_fLeftStickX;
    m_fLeftStickY = this->m_fLeftStickY;
    if ( (v28 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(unsigned __int64, Scaleform::GFx::Value::ValueType *, double))(*(_QWORD *)ptr.DataAux
                                                                                           + 16i64))(
        ptr.DataAux,
        &ptr.Type,
        COERCE_DOUBLE(*(_QWORD *)&v29));
      ptr.DataAux = 0i64;
    }
    v28 = 5;
    v29 = m_fLeftStickY;
    if ( (v32 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v31 + 16i64))(
        v31,
        v30,
        COERCE_DOUBLE(*(_QWORD *)&v33));
      v31 = 0i64;
    }
    v32 = 5;
    v33 = elapsed;
    v22 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum];
    m_IsKeyboardController = v22->m_IsKeyboardController;
    if ( (v36 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v35 + 16i64))(v35, v34, v37);
      v35 = 0i64;
    }
    v36 = 2;
    LOBYTE(v37) = m_IsKeyboardController;
    pObject = this->mRenderable->m_movie.pObject;
    if ( this->minigameState == SINGING )
    {
      Scaleform::GFx::Movie::Invoke(pObject, "mainLoop", 0i64, &ptr, 4u);
      pval.pObjectInterface = 0i64;
      pval.Type = VT_Undefined;
      Scaleform::GFx::Movie::GetVariable(pObject, &pval, "gInstrumental");
      UFG::UIHKScreenKaraokeMinigame::mbInstrumentalSection = pval.mValue.BValue;
      if ( UFG::Music::sm_bRecievedMarker )
      {
        Scaleform::GFx::Movie::Invoke(pObject, "phraseSignal", 0i64, 0i64, 0);
        UFG::Music::sm_bRecievedMarker = 0;
      }
      if ( (pval.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pval.pObjectInterface->vfptr->gap8[8])(
          pval.pObjectInterface,
          &pval,
          pval.mValue);
        pval.pObjectInterface = 0i64;
      }
      pval.Type = VT_Undefined;
    }
    if ( this->mbMusicStarted )
    {
      if ( !UFG::Music::sm_instance->vfptr->CountNumPlayingEvents(UFG::Music::sm_instance) )
      {
        this->minigameState = SCORE;
        UFG::UIHKScreenKaraokeMinigame::stopAllStimuli(this);
        `eh vector constructor iterator(&pval, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
        if ( (pval.Type & 0x40) != 0 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pval.pObjectInterface->vfptr->gap8[8])(
            pval.pObjectInterface,
            &pval,
            pval.mValue);
          pval.pObjectInterface = 0i64;
        }
        pval.Type = VT_Number;
        pval.mValue.NValue = DOUBLE_2_0;
        Scaleform::GFx::Movie::Invoke(pObject, "setState", 0i64, &pval, 1u);
        UFG::TiDo::UnloadWwiseBank(&this->mBankID);
        this->mbMusicStarted = 0;
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
        if ( UFG::TiDo::BankLoaded(this->mBankID.mUID) && !this->mbMusicCalled )
        {
          v25 = UFG::TiDo::CalcWwiseUid(UFG::gKaraokeMusicTrackNames[this->mSongIndex]);
          UFG::Music::MusicEvent(v25);
          this->mbMusicCalled = 1;
        }
      }
      else
      {
        this->mbMusicStarted = 1;
        this->minigameState = SINGING;
      }
    }
    UFG::UIScreen::update(this, elapsed);
    `eh vector destructor iterator(&ptr, 0x30ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 218
// RVA: 0x6241D0
bool __fastcall UFG::UIHKScreenKaraokeMinigame::handleMessage(
        UFG::UIHKScreenKaraokeMinigame *this,
        hkgpIndexedMeshDefinitions::Edge *msgId,
        UFG::UIMessage *msg)
{
  unsigned int v4; // r14d
  UFG::UIHKScreenKaraokeMinigame::State minigameState; // eax
  Scaleform::GFx::Movie *pObject; // r15
  const char *v8; // rdx
  unsigned int NValue; // eax
  __int64 v10; // rax
  UFG::qSymbol *v11; // rbx
  UFG::GameStatTracker *v12; // rax
  UFG::qWiseSymbol *v14; // rax
  UFG::AIScriptInterfaceComponent *mPlayerAISIC; // rcx
  Scaleform::GFx::Movie *v16; // rcx
  int v17; // ebx
  UFG::qNode<UFG::qString,UFG::qString> *mNext; // rsi
  unsigned int v19; // edi
  UFG::Music *v20; // rbx
  int v21; // eax
  UFG::qString *i; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rdx
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
  UFG::qList<UFG::qString,UFG::qString,1,0> list; // [rsp+8h] [rbp-69h] BYREF
  Scaleform::GFx::Value ptr; // [rsp+18h] [rbp-59h] BYREF
  Scaleform::GFx::Value pval; // [rsp+48h] [rbp-29h] BYREF
  UFG::qString v41; // [rsp+78h] [rbp+7h] BYREF
  __int64 v42; // [rsp+A0h] [rbp+2Fh]
  UFG::qSymbol result; // [rsp+D8h] [rbp+67h] BYREF

  v42 = -2i64;
  v4 = (unsigned int)msgId;
  minigameState = this->minigameState;
  if ( minigameState == SONG_SELECTION )
  {
    pObject = this->mRenderable->m_movie.pObject;
    if ( (_DWORD)msgId == UI_HASH_DPAD_DOWN_PRESSED_30 || (_DWORD)msgId == UI_HASH_THUMBSTICK_LEFT_DOWN_30 )
    {
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xC415B16F, 0i64, 0, 0i64);
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
            UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xA4E5BFBD, 0i64, 0, 0i64);
          this->mFinished = 1;
          return UFG::UIHKMinigameScreen::handleMessage(this, v4, msg);
        }
        if ( v4 == UI_HASH_BUTTON_ACCEPT_PRESSED_30 )
        {
          pval.pObjectInterface = 0i64;
          pval.Type = VT_Undefined;
          this->mSongIndex = 0;
          Scaleform::GFx::Movie::GetVariable(pObject, &pval, "gTargetSong");
          NValue = (int)pval.mValue.NValue;
          this->mSongIndex = (int)pval.mValue.NValue;
          UFG::qString::qString(&v41, "Song%d", NValue);
          v11 = UFG::qSymbol::create_from_string(&result, *(const char **)(v10 + 24));
          v12 = UFG::GameStatTracker::Instance();
          LOBYTE(v11) = UFG::GameStatTracker::GetStat(v12, KaraokeSongs, v11);
          UFG::qString::~qString(&v41);
          if ( !(_BYTE)v11 )
          {
            if ( UFG::HudAudio::m_instance )
              UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x9E75334E, 0i64, 0, 0i64);
            v14 = UFG::qWiseSymbol::create_from_string(
                    (UFG::qWiseSymbol *)&result,
                    UFG::gKaraokeSoundbankNames[this->mSongIndex]);
            UFG::qWiseSymbol::operator=(&this->mBankID, v14);
            _((AMD_HD3D *)result.mUID);
            UFG::TiDo::LoadWwiseBank(&this->mBankID);
            this->mbSongSelected = 1;
            ptr.pNext = (Scaleform::GFx::Value *)Scaleform::GFx::Value::~Value;
            `eh vector constructor iterator(
              &ptr,
              0x30ui64,
              1,
              (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
            if ( (ptr.Type & 0x40) != 0 )
            {
              (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
                ptr.pObjectInterface,
                &ptr,
                ptr.mValue);
              ptr.pObjectInterface = 0i64;
            }
            ptr.Type = VT_Number;
            ptr.mValue.NValue = DOUBLE_1_0;
            Scaleform::GFx::Movie::Invoke(pObject, "setState", 0i64, &ptr, 1u);
            UFG::AIScriptInterfaceComponent::BeginCommandActionRequest(this->mPlayerAISIC);
            if ( UFG::AIScriptInterfaceComponent::GiveCommand(this->mPlayerAISIC, eSCRIPT_COMMAND_SUBMIT_ACTION_REQUEST) )
            {
              UFG::AIScriptInterfaceComponent::AddArgument(this->mPlayerAISIC, "KaraokeSongPicked");
              UFG::AIScriptInterfaceComponent::AddArgument(this->mPlayerAISIC, "Walking_back");
            }
            mPlayerAISIC = this->mPlayerAISIC;
            if ( mPlayerAISIC )
              UFG::AIScriptInterfaceComponent::StartHoldingActionRequest(mPlayerAISIC, "KaraokeInstrumental2");
            `eh vector destructor iterator(
              &ptr,
              0x30ui64,
              1,
              (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
            if ( (pval.Type & 0x40) != 0 )
            {
              (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pval.pObjectInterface->vfptr->gap8[8])(
                pval.pObjectInterface,
                &pval,
                pval.mValue);
              pval.pObjectInterface = 0i64;
            }
            pval.Type = VT_Undefined;
            return UFG::UIHKMinigameScreen::handleMessage(this, v4, msg);
          }
          if ( (pval.Type & 0x40) != 0 )
          {
            (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pval.pObjectInterface->vfptr->gap8[8])(
              pval.pObjectInterface,
              &pval,
              pval.mValue);
            pval.pObjectInterface = 0i64;
          }
          pval.Type = VT_Undefined;
          return 1;
        }
        return UFG::UIHKMinigameScreen::handleMessage(this, v4, msg);
      }
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xC415B16F, 0i64, 0, 0i64);
      v8 = "highlightPrevious";
    }
    Scaleform::GFx::Movie::Invoke(pObject, v8, 0i64, 0i64, 0);
    goto LABEL_13;
  }
  if ( minigameState != SINGING )
  {
    if ( (_DWORD)msgId == UI_HASH_BUTTON_BACK_PRESSED_30 )
    {
      UFG::UIHKScreenKaraokeMinigame::mbWon = 1;
      this->mFinished = 1;
      return UFG::UIHKMinigameScreen::handleMessage(this, v4, msg);
    }
    if ( (_DWORD)msgId == UI_HASH_PLAYSOUND_20 )
    {
      UFG::qString::qString(&v41, (UFG::qString *)&msg[1]);
      v35 = UFG::TiDo::CalcWwiseUid(v41.mData);
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, v35, 0i64, 0, 0i64);
      goto LABEL_61;
    }
    if ( (_DWORD)msgId != UI_HASH_SETTUTORIAL1_20 )
      return UFG::UIHKMinigameScreen::handleMessage(this, v4, msg);
    v36 = this->mRenderable->m_movie.pObject;
    ptr.pObjectInterface = 0i64;
    ptr.Type = VT_Undefined;
    Scaleform::GFx::Movie::GetVariable(v36, &ptr, "gScore");
    v37 = (int)ptr.mValue.NValue;
    if ( !(int)ptr.mValue.NValue )
      v37 = 111;
    LODWORD(UFG::UIHKScreenKaraokeMinigame::mScore) = v37;
    UFG::GameStatAction::MiniGame::KaraokeSongCompleted(this->mSongIndex, v37, this->mnSongs);
    goto LABEL_84;
  }
  v16 = this->mRenderable->m_movie.pObject;
  if ( (_DWORD)msgId != UI_HASH_MODIFYRTPC_20 )
  {
    if ( (_DWORD)msgId == UI_HASH_KARAOKEINSTRUM1_20 )
    {
      v27 = this->mPlayerAISIC;
      if ( v27 )
        UFG::AIScriptInterfaceComponent::StartHoldingActionRequest(v27, "KaraokeInstrumental1");
      return UFG::UIHKMinigameScreen::handleMessage(this, v4, msg);
    }
    if ( (_DWORD)msgId == UI_HASH_KARAOKEINSTRUM2_20 )
    {
      v28 = this->mPlayerAISIC;
      if ( v28 )
        UFG::AIScriptInterfaceComponent::StartHoldingActionRequest(v28, "KaraokeInstrumental2");
      return UFG::UIHKMinigameScreen::handleMessage(this, v4, msg);
    }
    if ( (_DWORD)msgId == UI_HASH_KARAOKEINSTRUM3_20 )
    {
      v29 = this->mPlayerAISIC;
      if ( v29 )
        UFG::AIScriptInterfaceComponent::StartHoldingActionRequest(v29, "KaraokeInstrumental3");
      return UFG::UIHKMinigameScreen::handleMessage(this, v4, msg);
    }
    if ( (_DWORD)msgId == UI_HASH_KARAOKEINSTRUMGUITAR_20 )
    {
      v30 = this->mPlayerAISIC;
      if ( v30 )
        UFG::AIScriptInterfaceComponent::StartHoldingActionRequest(v30, "KaraokeInstrumentalGuitar");
      return UFG::UIHKMinigameScreen::handleMessage(this, v4, msg);
    }
    if ( (_DWORD)msgId == UI_HASH_KARAOKEINSTRUMOFF_20 )
    {
      v31 = this->mPlayerAISIC;
      if ( v31 )
        UFG::AIScriptInterfaceComponent::StopHoldingAllActionRequests(v31);
      return UFG::UIHKMinigameScreen::handleMessage(this, v4, msg);
    }
    if ( (_DWORD)msgId == UI_HASH_PLAYSOUND_20 )
    {
      UFG::qString::qString(&v41, (UFG::qString *)&msg[1]);
      v32 = UFG::TiDo::CalcWwiseUid(v41.mData);
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, v32, 0i64, 0, 0i64);
LABEL_61:
      UFG::qString::~qString(&v41);
      return 1;
    }
    if ( (_DWORD)msgId == UI_HASH_BUTTON_BACK_PRESSED_30 )
    {
      UFG::AudioEntity::StopAllEvents((unsigned __int64)UFG::Music::sm_instance);
      UFG::TiDo::UnloadWwiseBank(&this->mBankID);
      UFG::UIHKScreenKaraokeMinigame::stopAllStimuli(this);
      this->mFinished = 1;
      return UFG::UIHKMinigameScreen::handleMessage(this, v4, msg);
    }
    if ( (_DWORD)msgId != UI_HASH_SENDSTIMULUS_20 )
      return UFG::UIHKMinigameScreen::handleMessage(this, v4, msg);
    ptr.pObjectInterface = 0i64;
    ptr.Type = VT_Undefined;
    Scaleform::GFx::Movie::GetVariable(v16, &ptr, "gStimulus");
    switch ( (int)ptr.mValue.NValue )
    {
      case 0:
        UFG::StimulusManager::BeginStimulus(
          UFG::StimulusManager::s_pInstance,
          eSTIMULUS_KARAOKE_SINGING_PERFECT,
          &this->mStimulusParams,
          LocalPlayer);
        v33 = eSTIMULUS_KARAOKE_SINGING_BAD;
        goto LABEL_71;
      case 1:
        UFG::StimulusManager::BeginStimulus(
          UFG::StimulusManager::s_pInstance,
          eSTIMULUS_KARAOKE_SINGING_GOOD,
          &this->mStimulusParams,
          LocalPlayer);
        UFG::StimulusManager::EndStimulus(UFG::StimulusManager::s_pInstance, eSTIMULUS_KARAOKE_SINGING_BAD, LocalPlayer);
        v34 = eSTIMULUS_KARAOKE_SINGING_PERFECT;
LABEL_72:
        UFG::StimulusManager::EndStimulus(UFG::StimulusManager::s_pInstance, v34, LocalPlayer);
        break;
      case 2:
        UFG::StimulusManager::BeginStimulus(
          UFG::StimulusManager::s_pInstance,
          eSTIMULUS_KARAOKE_SINGING_BAD,
          &this->mStimulusParams,
          LocalPlayer);
        v33 = eSTIMULUS_KARAOKE_SINGING_PERFECT;
LABEL_71:
        UFG::StimulusManager::EndStimulus(UFG::StimulusManager::s_pInstance, v33, LocalPlayer);
        v34 = eSTIMULUS_KARAOKE_SINGING_GOOD;
        goto LABEL_72;
    }
LABEL_84:
    if ( (ptr.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
        ptr.pObjectInterface,
        &ptr,
        ptr.mValue);
      ptr.pObjectInterface = 0i64;
    }
    ptr.Type = VT_Undefined;
    return UFG::UIHKMinigameScreen::handleMessage(this, v4, msg);
  }
  if ( Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat((hkgpIndexedMesh::EdgeBarrier *)v16, msgId) )
    return 1;
  UFG::qString::qString(&v41, (UFG::qString *)&msg[1]);
  UFG::qString::Tokenize(&v41, &list, ",", "Karaoke.HandleMessage");
  v17 = 1;
  mNext = list.mNode.mNext;
  do
  {
    if ( mNext == (UFG::qNode<UFG::qString,UFG::qString> *)&list )
      break;
    --v17;
    mNext = mNext->mNext;
  }
  while ( v17 > 0 );
  v19 = UFG::TiDo::CalcWwiseUid((const char *)list.mNode.mNext[1].mNext);
  v20 = UFG::Music::sm_instance;
  v21 = UFG::qToInt32((const char *)mNext[1].mNext, 0);
  UFG::AudioEntity::SetRtpcValue(v20, v19, (float)v21);
  for ( i = (UFG::qString *)list.mNode.mNext;
        (UFG::qList<UFG::qString,UFG::qString,1,0> *)list.mNode.mNext != &list;
        i = (UFG::qString *)list.mNode.mNext )
  {
    mPrev = i->mPrev;
    v24 = i->mNext;
    mPrev->mNext = v24;
    v24->mPrev = mPrev;
    i->mPrev = i;
    i->mNext = i;
    UFG::qString::~qString(i);
    operator delete[](i);
  }
  v25 = list.mNode.mPrev;
  v26 = list.mNode.mNext;
  list.mNode.mPrev->mNext = list.mNode.mNext;
  v26->mPrev = v25;
  UFG::qString::~qString(&v41);
  return 1;
}

// File Line: 431
// RVA: 0x6383D0
void __fastcall UFG::UIHKScreenKaraokeMinigame::initSongList(UFG::UIHKScreenKaraokeMinigame *this)
{
  Scaleform::GFx::Movie *pObject; // r14
  unsigned int i; // ebx
  __int64 v4; // rax
  UFG::GameStatTracker *v5; // rax
  bool Stat; // di
  double mnSongs; // xmm6_8
  bool m_IsKeyboardController; // di
  Scaleform::GFx::Value ptr; // [rsp+30h] [rbp-A8h] BYREF
  char v10[8]; // [rsp+60h] [rbp-78h] BYREF
  char v11[8]; // [rsp+68h] [rbp-70h] BYREF
  __int64 v12; // [rsp+70h] [rbp-68h]
  __int64 v13; // [rsp+78h] [rbp-60h]
  int v14; // [rsp+80h] [rbp-58h]
  double v15; // [rsp+88h] [rbp-50h]
  char v16[16]; // [rsp+98h] [rbp-40h] BYREF
  __int64 v17; // [rsp+A8h] [rbp-30h]
  int v18; // [rsp+B0h] [rbp-28h]
  __int64 v19; // [rsp+B8h] [rbp-20h]
  __int64 v20; // [rsp+C8h] [rbp-10h]
  UFG::qString v21; // [rsp+D0h] [rbp-8h] BYREF
  UFG::qSymbol result; // [rsp+138h] [rbp+60h] BYREF

  v20 = -2i64;
  `eh vector constructor iterator(&ptr, 0x30ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  pObject = this->mRenderable->m_movie.pObject;
  for ( i = 0; i < this->mnSongs; ++i )
  {
    UFG::qString::qString(&v21, "Song%d", i);
    UFG::qSymbol::create_from_string(&result, *(const char **)(v4 + 24));
    UFG::qString::~qString(&v21);
    v5 = UFG::GameStatTracker::Instance();
    Stat = UFG::GameStatTracker::GetStat(v5, KaraokeSongs, &result);
    if ( (ptr.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
        ptr.pObjectInterface,
        &ptr,
        ptr.mValue);
      ptr.pObjectInterface = 0i64;
    }
    ptr.Type = VT_Number;
    ptr.mValue.NValue = (double)(int)i;
    if ( (v13 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, unsigned __int64))(*(_QWORD *)v12 + 16i64))(v12, v10, ptr.DataAux);
      v12 = 0i64;
    }
    LODWORD(v13) = 5;
    *(double *)&ptr.DataAux = (double)Stat;
    mnSongs = (double)(int)this->mnSongs;
    if ( (v14 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v13 + 16i64))(
        v13,
        v11,
        COERCE_DOUBLE(*(_QWORD *)&v15));
      v13 = 0i64;
    }
    v14 = 5;
    v15 = mnSongs;
    m_IsKeyboardController = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController;
    if ( (v18 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v17 + 16i64))(v17, v16, v19);
      v17 = 0i64;
    }
    v18 = 2;
    LOBYTE(v19) = m_IsKeyboardController;
    Scaleform::GFx::Movie::Invoke(pObject, "initSongSelection", 0i64, &ptr, 4u);
  }
  `eh vector destructor iterator(&ptr, 0x30ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 450
// RVA: 0x63B350
void __fastcall UFG::UIHKScreenKaraokeMinigame::stopAllStimuli(UFG::UIHKScreenKaraokeMinigame *this)
{
  UFG::StimulusManager::EndStimulus(UFG::StimulusManager::s_pInstance, eSTIMULUS_KARAOKE_SINGING_BAD, LocalPlayer);
  UFG::StimulusManager::EndStimulus(UFG::StimulusManager::s_pInstance, eSTIMULUS_KARAOKE_SINGING_GOOD, LocalPlayer);
  UFG::StimulusManager::EndStimulus(UFG::StimulusManager::s_pInstance, eSTIMULUS_KARAOKE_SINGING_PERFECT, LocalPlayer);
}

