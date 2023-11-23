// File Line: 33
// RVA: 0x5C5800
void __fastcall UFG::UIHKScreenHackingMinigame::UIHKScreenHackingMinigame(UFG::UIHKScreenHackingMinigame *this)
{
  hkgpIndexedMeshDefinitions::Edge *v2; // rdx
  hkgpIndexedMesh::EdgeBarrier *v3; // rcx
  UFG::qWiseSymbol *v4; // rax
  UFG::qWiseSymbol result; // [rsp+48h] [rbp+10h] BYREF

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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKTaskableScreen::`vftable;
  this->mFinished = 0;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKMinigameScreen::`vftable;
  *(_QWORD *)&this->mfAlphaValue = 1109393408i64;
  ++UFG::UIHKMinigameScreen::mNumMinigameScreens;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenHackingMinigame::`vftable;
  this->mSavedControllerMode = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_ActiveMapSet;
  UFG::SetInputMode(IM_UI_ONLY, UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->mControllerIndex);
  UFG::UIHKScreenHackingMinigame::m_bWon = 0;
  *(_WORD *)&this->mbAllowControls = 0;
  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(v3, v2) )
  {
    v4 = UFG::qWiseSymbol::create_from_string(&result, "mg_cpu_hacking");
    UFG::TiDo::LoadWwiseBank(v4);
    _((AMD_HD3D *)result.mUID);
  }
}

// File Line: 48
// RVA: 0x5CAFE0
void __fastcall UFG::UIHKScreenHackingMinigame::~UIHKScreenHackingMinigame(UFG::UIHKScreenHackingMinigame *this)
{
  UFG::UIScreenTextureManager *v2; // rax
  hkgpIndexedMeshDefinitions::Edge *v3; // rdx
  hkgpIndexedMesh::EdgeBarrier *v4; // rcx
  UFG::qWiseSymbol *v5; // rax
  UFG::qWiseSymbol result; // [rsp+58h] [rbp+10h] BYREF
  UFG::qWiseSymbol v7; // [rsp+60h] [rbp+18h] BYREF

  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenHackingMinigame::`vftable;
  v2 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v2, "HackingMinigame");
  UFG::SetInputMode(
    this->mSavedControllerMode,
    UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->mControllerIndex);
  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(v4, v3) )
  {
    if ( (_S26_3 & 1) == 0 )
    {
      _S26_3 |= 1u;
      Set_State_minigame_mus_end_3.mUID = UFG::qWiseSymbolUIDFromString("Set_State_minigame_mus_end", 0x811C9DC5);
      _((AMD_HD3D *)Set_State_minigame_mus_end_3.mUID);
      atexit(UFG::UIHKScreenHackingMinigame::_UIHKScreenHackingMinigame_::_4_::_dynamic_atexit_destructor_for__Set_State_minigame_mus_end__);
    }
    UFG::Music::MusicEvent(Set_State_minigame_mus_end_3.mUID);
    UFG::qWiseSymbol::create_from_string(&result, "Stop_ch_start_hack");
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, result.mUID, 0i64, 0, 0i64);
    v5 = UFG::qWiseSymbol::create_from_string(&v7, "mg_cpu_hacking");
    UFG::TiDo::UnloadWwiseBank(v5);
    _((AMD_HD3D *)v7.mUID);
    _((AMD_HD3D *)result.mUID);
  }
  UFG::UIHKMinigameScreen::~UIHKMinigameScreen(this);
}

// File Line: 65
// RVA: 0x631F10
void __fastcall UFG::UIHKScreenHackingMinigame::init(UFG::UIHKScreenHackingMinigame *this, UFG::UICommandData *data)
{
  UFG::UIHKMissionProgressWidget *v3; // rax
  Scaleform::GFx::Movie *pObject; // rbx
  bool m_IsKeyboardController; // di
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h] BYREF

  UFG::UIScreen::init(this, data);
  v3 = UFG::UIHKScreenHud::MissionProgress;
  UFG::UIHKScreenHud::MissionProgress->mChanged = 1;
  v3->mData[0].Changed = 1;
  v3->mData[1].Changed = 1;
  v3->mData[2].Changed = 1;
  v3->mData[3].Changed = 1;
  pObject = this->mRenderable->m_movie.pObject;
  pargs.pObjectInterface = 0i64;
  pargs.Type = VT_Undefined;
  m_IsKeyboardController = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController;
  pargs.Type = VT_Boolean;
  pargs.mValue.BValue = m_IsKeyboardController;
  if ( pObject )
  {
    Scaleform::GFx::Movie::Invoke(pObject, "Chg_Exit", 0i64, &pargs, 1u);
    Scaleform::GFx::Movie::Invoke(pObject, "init", 0i64, &customCaption);
  }
  if ( (pargs.Type & 0x40) != 0 )
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      pargs.mValue);
}

// File Line: 84
// RVA: 0x63D0E0
void __fastcall UFG::UIHKScreenHackingMinigame::update(UFG::UIHKScreenHackingMinigame *this, float elapsed)
{
  char v3; // bl
  UFG::qWiseSymbol *v4; // rax
  bool v5; // si
  Scaleform::GFx::Movie *pObject; // rbx
  bool m_IsKeyboardController; // si
  Scaleform::GFx::Value pargs; // [rsp+40h] [rbp-40h] BYREF
  UFG::qWiseSymbol result; // [rsp+B0h] [rbp+30h] BYREF

  v3 = 0;
  if ( !UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "NISPause") )
  {
    v5 = 0;
    if ( !this->mbMusicPlay )
    {
      v4 = UFG::qWiseSymbol::create_from_string(&result, "mg_cpu_hacking");
      v3 = 1;
      if ( UFG::TiDo::BankLoaded(v4->mUID) )
        v5 = 1;
    }
    if ( (v3 & 1) != 0 )
      _((AMD_HD3D *)result.mUID);
    if ( v5 )
    {
      UFG::qWiseSymbol::create_from_string(&result, "Play_ch_start_hack");
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, result.mUID, 0i64, 0, 0i64);
      if ( (_S27_3 & 1) == 0 )
      {
        _S27_3 |= 1u;
        Set_State_minigame_mus_start_3.mUID = UFG::qWiseSymbolUIDFromString("Set_State_minigame_mus_start", 0x811C9DC5);
        _((AMD_HD3D *)Set_State_minigame_mus_start_3.mUID);
        atexit(UFG::UIHKScreenHackingMinigame::update_::_8_::_dynamic_atexit_destructor_for__Set_State_minigame_mus_start__);
      }
      UFG::Music::MusicEvent(Set_State_minigame_mus_start_3.mUID);
      this->mbMusicPlay = 1;
      _((AMD_HD3D *)result.mUID);
    }
    pObject = this->mRenderable->m_movie.pObject;
    if ( pObject )
    {
      pargs.pObjectInterface = 0i64;
      pargs.Type = VT_Undefined;
      m_IsKeyboardController = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController;
      pargs.Type = VT_Boolean;
      pargs.mValue.BValue = m_IsKeyboardController;
      Scaleform::GFx::Movie::Invoke(pObject, "Chg_Exit", 0i64, &pargs, 1u);
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
    UFG::UIHKMissionProgressWidget::Update(UFG::UIHKScreenHud::MissionProgress, this);
    UFG::UIScreen::update(this, elapsed);
  }
}

// File Line: 114
// RVA: 0x623BA0
bool __fastcall UFG::UIHKScreenHackingMinigame::handleMessage(
        UFG::UIHKScreenHackingMinigame *this,
        unsigned int msgId,
        UFG::UIMessage *msg)
{
  unsigned int v4; // eax
  Scaleform::GFx::Movie *v6; // rcx
  Scaleform::GFx::Movie *v7; // rcx
  Scaleform::GFx::Movie *v8; // rcx
  Scaleform::GFx::Movie *v9; // rcx
  int v10; // edx
  hkGeometryUtils::IVertices *v11; // rcx
  int v12; // r8d
  unsigned int v13; // eax
  Scaleform::GFx::Movie *pObject; // rcx
  int v15; // edx
  hkGeometryUtils::IVertices *v16; // rcx
  int v17; // r8d
  unsigned int v18; // eax
  UFG::qString v19; // [rsp+38h] [rbp-38h] BYREF

  if ( msgId != UI_HASH_PLAYSOUND_20 )
  {
    if ( msgId == UI_HASH_SETWON_20 )
    {
      UFG::GameStatAction::MiniGame::Completed(MGT_Hacking);
      UFG::UIHKScreenHackingMinigame::m_bWon = 1;
      this->mFinished = 1;
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
    if ( this->mbAllowControls )
    {
      if ( msgId == UI_HASH_THUMBSTICK_LEFT_UP_30 || msgId == UI_HASH_DPAD_UP_PRESSED_30 )
      {
        pObject = this->mRenderable->m_movie.pObject;
        if ( pObject )
        {
          *(_QWORD *)&v19.mMagic = 0i64;
          LODWORD(v19.mData) = 0;
          Scaleform::GFx::Movie::Invoke(pObject, "leftStickUp", 0i64, &customCaption);
          if ( Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(v16, v15, v17) )
          {
            v18 = UFG::TiDo::CalcWwiseUid("Play_ch_nav");
            if ( UFG::HudAudio::m_instance )
              UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, v18, 0i64, 0, 0i64);
          }
          goto LABEL_38;
        }
      }
      else if ( msgId == UI_HASH_THUMBSTICK_LEFT_DOWN_30 || msgId == UI_HASH_DPAD_DOWN_PRESSED_30 )
      {
        v9 = this->mRenderable->m_movie.pObject;
        if ( v9 )
        {
          *(_QWORD *)&v19.mMagic = 0i64;
          LODWORD(v19.mData) = 0;
          Scaleform::GFx::Movie::Invoke(v9, "leftStickDown", 0i64, &customCaption);
          if ( Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(v11, v10, v12) )
          {
            v13 = UFG::TiDo::CalcWwiseUid("Play_ch_nav");
            if ( UFG::HudAudio::m_instance )
              UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, v13, 0i64, 0, 0i64);
          }
          goto LABEL_38;
        }
      }
      else if ( msgId == UI_HASH_THUMBSTICK_LEFT_LEFT_30 || msgId == UI_HASH_DPAD_LEFT_PRESSED_30 )
      {
        v8 = this->mRenderable->m_movie.pObject;
        if ( v8 )
        {
          *(_QWORD *)&v19.mMagic = 0i64;
          LODWORD(v19.mData) = 0;
          Scaleform::GFx::Movie::Invoke(v8, "leftStickLeft", 0i64, &customCaption);
          goto LABEL_38;
        }
      }
      else if ( msgId == UI_HASH_THUMBSTICK_LEFT_RIGHT_30 || msgId == UI_HASH_DPAD_RIGHT_PRESSED_30 )
      {
        v7 = this->mRenderable->m_movie.pObject;
        if ( v7 )
        {
          *(_QWORD *)&v19.mMagic = 0i64;
          LODWORD(v19.mData) = 0;
          Scaleform::GFx::Movie::Invoke(v7, "leftStickRight", 0i64, &customCaption);
          goto LABEL_38;
        }
      }
      else if ( msgId == UI_HASH_BUTTON_ACCEPT_PRESSED_30 )
      {
        v6 = this->mRenderable->m_movie.pObject;
        if ( v6 )
        {
          *(_QWORD *)&v19.mMagic = 0i64;
          LODWORD(v19.mData) = 0;
          Scaleform::GFx::Movie::Invoke(v6, "processCode", 0i64, &customCaption);
LABEL_38:
          LODWORD(v19.mData) = 0;
          return 1;
        }
      }
    }
    return UFG::UIHKMinigameScreen::handleMessage(this, msgId, msg);
  }
  UFG::qString::qString(&v19, (UFG::qString *)&msg[1]);
  v4 = UFG::TiDo::CalcWwiseUid(v19.mData);
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, v4, 0i64, 0, 0i64);
  UFG::qString::~qString(&v19);
  return 1;
}

