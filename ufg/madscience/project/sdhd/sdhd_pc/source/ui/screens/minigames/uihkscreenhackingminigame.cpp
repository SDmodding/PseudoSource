// File Line: 33
// RVA: 0x5C5800
void __fastcall UFG::UIHKScreenHackingMinigame::UIHKScreenHackingMinigame(UFG::UIHKScreenHackingMinigame *this)
{
  UFG::UIHKScreenHackingMinigame *v1; // rbx
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v2; // rax
  hkgpIndexedMeshDefinitions::Edge *v3; // rdx
  hkgpIndexedMesh::EdgeBarrier *v4; // rcx
  UFG::qWiseSymbol *v5; // rax
  UFG::qWiseSymbol result; // [rsp+48h] [rbp+10h]

  v1 = this;
  v2 = (UFG::qNode<UFG::UIScreen,UFG::UIScreen> *)&this->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIScreen::`vftable;
  this->m_screenNameHash = 0;
  this->mRenderable = 0i64;
  this->mLoadThread = 0i64;
  this->mScreenUID = -1;
  *(_QWORD *)&this->mControllerMask = 15i64;
  *(_QWORD *)&this->mPriority = 0i64;
  this->mDimToApplyType = 0;
  *(_QWORD *)&this->mCurDimValue = 1120403456i64;
  this->m_screenName[0] = 0;
  --v1->mInputEnabled;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKTaskableScreen::`vftable;
  this->mFinished = 0;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKMinigameScreen::`vftable;
  *(_QWORD *)&this->mfAlphaValue = 1109393408i64;
  ++UFG::UIHKMinigameScreen::mNumMinigameScreens;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenHackingMinigame::`vftable;
  this->mSavedControllerMode = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_ActiveMapSet;
  UFG::SetInputMode(IM_UI_ONLY, UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->mControllerIndex);
  UFG::UIHKScreenHackingMinigame::m_bWon = 0;
  *(_WORD *)&v1->mbAllowControls = 0;
  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(v4, v3) )
  {
    v5 = UFG::qWiseSymbol::create_from_string(&result, "mg_cpu_hacking");
    UFG::TiDo::LoadWwiseBank(v5);
    _((AMD_HD3D *)result.mUID);
  }
}

// File Line: 48
// RVA: 0x5CAFE0
void __fastcall UFG::UIHKScreenHackingMinigame::~UIHKScreenHackingMinigame(UFG::UIHKScreenHackingMinigame *this)
{
  UFG::UIHKScreenHackingMinigame *v1; // rbx
  UFG::UIScreenTextureManager *v2; // rax
  hkgpIndexedMeshDefinitions::Edge *v3; // rdx
  hkgpIndexedMesh::EdgeBarrier *v4; // rcx
  UFG::qWiseSymbol *v5; // rax
  UFG::qWiseSymbol result; // [rsp+58h] [rbp+10h]
  UFG::qWiseSymbol v7; // [rsp+60h] [rbp+18h]

  v1 = this;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenHackingMinigame::`vftable;
  v2 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v2, "HackingMinigame");
  UFG::SetInputMode(
    v1->mSavedControllerMode,
    UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->mControllerIndex);
  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(v4, v3) )
  {
    if ( !(_S26_3 & 1) )
    {
      _S26_3 |= 1u;
      Set_State_minigame_mus_end_3.mUID = UFG::qWiseSymbolUIDFromString("Set_State_minigame_mus_end", 0x811C9DC5);
      _((AMD_HD3D *)Set_State_minigame_mus_end_3.mUID);
      atexit(UFG::UIHKScreenHackingMinigame::_UIHKScreenHackingMinigame_::_4_::_dynamic_atexit_destructor_for__Set_State_minigame_mus_end__);
    }
    UFG::Music::MusicEvent(Set_State_minigame_mus_end_3.mUID);
    UFG::qWiseSymbol::create_from_string(&result, "Stop_ch_start_hack");
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        result.mUID,
        0i64,
        0,
        0i64);
    v5 = UFG::qWiseSymbol::create_from_string(&v7, "mg_cpu_hacking");
    UFG::TiDo::UnloadWwiseBank(v5);
    _((AMD_HD3D *)v7.mUID);
    _((AMD_HD3D *)result.mUID);
  }
  UFG::UIHKMinigameScreen::~UIHKMinigameScreen((UFG::UIHKMinigameScreen *)&v1->vfptr);
}

// File Line: 65
// RVA: 0x631F10
void __fastcall UFG::UIHKScreenHackingMinigame::init(UFG::UIHKScreenHackingMinigame *this, UFG::UICommandData *data)
{
  UFG::UIHKScreenHackingMinigame *v2; // rbx
  UFG::UIHKMissionProgressWidget *v3; // rax
  Scaleform::GFx::Movie *v4; // rbx
  bool v5; // di
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h]

  v2 = this;
  UFG::UIScreen::init((UFG::UIScreen *)&this->vfptr, data);
  v3 = UFG::UIHKScreenHud::MissionProgress;
  UFG::UIHKScreenHud::MissionProgress->mChanged = 1;
  v3->mData[0].Changed = 1;
  v3->mData[1].Changed = 1;
  v3->mData[2].Changed = 1;
  v3->mData[3].Changed = 1;
  v4 = v2->mRenderable->m_movie.pObject;
  pargs.pObjectInterface = 0i64;
  pargs.Type = 0;
  v5 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController;
  pargs.Type = 2;
  pargs.mValue.BValue = v5;
  if ( v4 )
  {
    Scaleform::GFx::Movie::Invoke(v4, "Chg_Exit", 0i64, &pargs, 1u);
    Scaleform::GFx::Movie::Invoke(v4, "init", 0i64, &customWorldMapCaption);
  }
  if ( ((unsigned int)pargs.Type >> 6) & 1 )
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      *(_QWORD *)&pargs.mValue.NValue);
}

// File Line: 84
// RVA: 0x63D0E0
void __fastcall UFG::UIHKScreenHackingMinigame::update(UFG::UIHKScreenHackingMinigame *this, float elapsed)
{
  UFG::UIHKScreenHackingMinigame *v2; // rdi
  char v3; // bl
  UFG::qWiseSymbol *v4; // rax
  bool v5; // si
  Scaleform::GFx::Movie *v6; // rbx
  bool v7; // si
  Scaleform::GFx::Value pargs; // [rsp+40h] [rbp-40h]
  UFG::qWiseSymbol result; // [rsp+B0h] [rbp+30h]

  v2 = this;
  v3 = 0;
  if ( !UFG::UIScreenManagerBase::getScreen(
          (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
          "NISPause") )
  {
    v5 = 0;
    if ( !v2->mbMusicPlay )
    {
      v4 = UFG::qWiseSymbol::create_from_string(&result, "mg_cpu_hacking");
      v3 = 1;
      if ( (unsigned __int8)UFG::TiDo::BankLoaded(v4->mUID) )
        v5 = 1;
    }
    if ( v3 & 1 )
      _((AMD_HD3D *)result.mUID);
    if ( v5 )
    {
      UFG::qWiseSymbol::create_from_string(&result, "Play_ch_start_hack");
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(
          (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
          result.mUID,
          0i64,
          0,
          0i64);
      if ( !(_S27_3 & 1) )
      {
        _S27_3 |= 1u;
        Set_State_minigame_mus_start_3.mUID = UFG::qWiseSymbolUIDFromString("Set_State_minigame_mus_start", 0x811C9DC5);
        _((AMD_HD3D *)Set_State_minigame_mus_start_3.mUID);
        atexit(UFG::UIHKScreenHackingMinigame::update_::_8_::_dynamic_atexit_destructor_for__Set_State_minigame_mus_start__);
      }
      UFG::Music::MusicEvent(Set_State_minigame_mus_start_3.mUID);
      v2->mbMusicPlay = 1;
      _((AMD_HD3D *)result.mUID);
    }
    v6 = v2->mRenderable->m_movie.pObject;
    if ( v6 )
    {
      pargs.pObjectInterface = 0i64;
      pargs.Type = 0;
      v7 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController;
      pargs.Type = 2;
      pargs.mValue.BValue = v7;
      Scaleform::GFx::Movie::Invoke(v6, "Chg_Exit", 0i64, &pargs, 1u);
      Scaleform::GFx::Movie::Invoke(v6, "mainLoop", 0i64, 0i64, 0);
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
    UFG::UIHKMissionProgressWidget::Update(UFG::UIHKScreenHud::MissionProgress, (UFG::UIScreen *)&v2->vfptr);
    UFG::UIScreen::update((UFG::UIScreen *)&v2->vfptr, elapsed);
  }
}

// File Line: 114
// RVA: 0x623BA0
char __fastcall UFG::UIHKScreenHackingMinigame::handleMessage(UFG::UIHKScreenHackingMinigame *this, unsigned int msgId, UFG::UIMessage *msg)
{
  UFG::UIHKScreenHackingMinigame *v3; // rbx
  unsigned int v4; // eax
  Scaleform::GFx::Movie *v6; // rcx
  Scaleform::GFx::Movie *v7; // rcx
  Scaleform::GFx::Movie *v8; // rcx
  Scaleform::GFx::Movie *v9; // rcx
  int v10; // edx
  hkGeometryUtils::IVertices *v11; // rcx
  int v12; // er8
  unsigned int v13; // eax
  Scaleform::GFx::Movie *v14; // rcx
  int v15; // edx
  hkGeometryUtils::IVertices *v16; // rcx
  int v17; // er8
  unsigned int v18; // eax
  UFG::qString v19; // [rsp+38h] [rbp-38h]

  v3 = this;
  if ( msgId == UI_HASH_PLAYSOUND_20 )
  {
    UFG::qString::qString(&v19, (UFG::qString *)&msg[1]);
    v4 = UFG::TiDo::CalcWwiseUid(v19.mData);
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr, v4, 0i64, 0, 0i64);
    UFG::qString::~qString(&v19);
    return 1;
  }
  if ( msgId == UI_HASH_SETWON_20 )
  {
    UFG::GameStatAction::MiniGame::Completed(MGT_Hacking);
    UFG::UIHKScreenHackingMinigame::m_bWon = 1;
    v3->mFinished = 1;
    return 1;
  }
  if ( msgId == UI_HASH_ENABLECONTROLS_20 )
  {
    this->mbAllowControls = 1;
    return 1;
  }
  if ( msgId == UI_HASH_DISABLECONTROLS_20 )
  {
    this->mbAllowControls = 0;
    return 1;
  }
  if ( msgId == UI_HASH_BUTTON_BACK_PRESSED_30 )
  {
    this->mFinished = 1;
    return 1;
  }
  if ( !this->mbAllowControls )
    return UFG::UIHKMinigameScreen::handleMessage((UFG::UIHKMinigameScreen *)&v3->vfptr, msgId, msg);
  if ( msgId == UI_HASH_THUMBSTICK_LEFT_UP_30 || msgId == UI_HASH_DPAD_UP_PRESSED_30 )
  {
    v14 = this->mRenderable->m_movie.pObject;
    if ( v14 )
    {
      *(_QWORD *)&v19.mMagic = 0i64;
      LODWORD(v19.mData) = 0;
      Scaleform::GFx::Movie::Invoke(v14, "leftStickUp", 0i64, &customWorldMapCaption);
      if ( Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(v16, v15, v17) )
      {
        v18 = UFG::TiDo::CalcWwiseUid("Play_ch_nav");
        if ( UFG::HudAudio::m_instance )
          UFG::AudioEntity::CreateAndPlayEvent(
            (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
            v18,
            0i64,
            0,
            0i64);
      }
      goto LABEL_38;
    }
    return UFG::UIHKMinigameScreen::handleMessage((UFG::UIHKMinigameScreen *)&v3->vfptr, msgId, msg);
  }
  if ( msgId == UI_HASH_THUMBSTICK_LEFT_DOWN_30 || msgId == UI_HASH_DPAD_DOWN_PRESSED_30 )
  {
    v9 = this->mRenderable->m_movie.pObject;
    if ( v9 )
    {
      *(_QWORD *)&v19.mMagic = 0i64;
      LODWORD(v19.mData) = 0;
      Scaleform::GFx::Movie::Invoke(v9, "leftStickDown", 0i64, &customWorldMapCaption);
      if ( Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(v11, v10, v12) )
      {
        v13 = UFG::TiDo::CalcWwiseUid("Play_ch_nav");
        if ( UFG::HudAudio::m_instance )
          UFG::AudioEntity::CreateAndPlayEvent(
            (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
            v13,
            0i64,
            0,
            0i64);
      }
      goto LABEL_38;
    }
    return UFG::UIHKMinigameScreen::handleMessage((UFG::UIHKMinigameScreen *)&v3->vfptr, msgId, msg);
  }
  if ( msgId == UI_HASH_THUMBSTICK_LEFT_LEFT_30 || msgId == UI_HASH_DPAD_LEFT_PRESSED_30 )
  {
    v8 = this->mRenderable->m_movie.pObject;
    if ( v8 )
    {
      *(_QWORD *)&v19.mMagic = 0i64;
      LODWORD(v19.mData) = 0;
      Scaleform::GFx::Movie::Invoke(v8, "leftStickLeft", 0i64, &customWorldMapCaption);
      goto LABEL_38;
    }
    return UFG::UIHKMinigameScreen::handleMessage((UFG::UIHKMinigameScreen *)&v3->vfptr, msgId, msg);
  }
  if ( msgId == UI_HASH_THUMBSTICK_LEFT_RIGHT_30 || msgId == UI_HASH_DPAD_RIGHT_PRESSED_30 )
  {
    v7 = this->mRenderable->m_movie.pObject;
    if ( v7 )
    {
      *(_QWORD *)&v19.mMagic = 0i64;
      LODWORD(v19.mData) = 0;
      Scaleform::GFx::Movie::Invoke(v7, "leftStickRight", 0i64, &customWorldMapCaption);
      goto LABEL_38;
    }
    return UFG::UIHKMinigameScreen::handleMessage((UFG::UIHKMinigameScreen *)&v3->vfptr, msgId, msg);
  }
  if ( msgId != UI_HASH_BUTTON_ACCEPT_PRESSED_30 )
    return UFG::UIHKMinigameScreen::handleMessage((UFG::UIHKMinigameScreen *)&v3->vfptr, msgId, msg);
  v6 = this->mRenderable->m_movie.pObject;
  if ( !v6 )
    return UFG::UIHKMinigameScreen::handleMessage((UFG::UIHKMinigameScreen *)&v3->vfptr, msgId, msg);
  *(_QWORD *)&v19.mMagic = 0i64;
  LODWORD(v19.mData) = 0;
  Scaleform::GFx::Movie::Invoke(v6, "processCode", 0i64, &customWorldMapCaption);
LABEL_38:
  if ( (LODWORD(v19.mData) >> 6) & 1 )
  {
    (*(void (__fastcall **)(_QWORD, UFG::qString *, _QWORD))(**(_QWORD **)&v19.mMagic + 16i64))(
      *(_QWORD *)&v19.mMagic,
      &v19,
      *(_QWORD *)&v19.mStringHash32);
    *(_QWORD *)&v19.mMagic = 0i64;
  }
  LODWORD(v19.mData) = 0;
  return 1;
}

