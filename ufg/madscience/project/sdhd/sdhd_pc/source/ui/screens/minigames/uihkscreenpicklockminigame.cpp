// File Line: 39
// RVA: 0x5C6D60
void __fastcall UFG::UIHKScreenPickLockMinigame::UIHKScreenPickLockMinigame(UFG::UIHKScreenPickLockMinigame *this)
{
  hkgpIndexedMeshDefinitions::Edge *v1; // rdx
  hkgpIndexedMesh::EdgeBarrier *v2; // rcx
  UFG::qWiseSymbol *v3; // rax
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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenPickLockMinigame::`vftable;
  UFG::UIHKScreenPickLockMinigame::m_bWon = 0;
  this->mSavedControllerMode = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_ActiveMapSet;
  UFG::SetInputMode(IM_UI_ONLY, UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->mControllerIndex);
  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(v2, v1) )
  {
    v3 = UFG::qWiseSymbol::create_from_string(&result, "mg_lock_picking");
    UFG::TiDo::LoadWwiseBank(v3);
    _((AMD_HD3D *)result.mUID);
  }
}

// File Line: 56
// RVA: 0x5CC270
void __fastcall UFG::UIHKScreenPickLockMinigame::~UIHKScreenPickLockMinigame(UFG::UIHKScreenPickLockMinigame *this)
{
  UFG::UIScreenTextureManager *v2; // rax
  UFG::UIHKScreenGlobalOverlay *v3; // rax
  UFG::UIHKHelpBarWidget *p_HelpBar; // rdi
  unsigned int v5; // eax
  hkgpIndexedMeshDefinitions::Edge *v6; // rdx
  hkgpIndexedMesh::EdgeBarrier *v7; // rcx
  UFG::qWiseSymbol *v8; // rax
  UFG::qWiseSymbol result; // [rsp+58h] [rbp+10h] BYREF
  UFG::qWiseSymbol v10; // [rsp+60h] [rbp+18h] BYREF

  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenPickLockMinigame::`vftable;
  v2 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v2, "PickLockMinigame");
  v3 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    v3 = &gGlobalOverlaySentinel;
  p_HelpBar = &v3->HelpBar;
  v5 = UFG::qStringHash32("UIHKScreenPickLockMinigame", 0xFFFFFFFF);
  UFG::UIHKHelpBarWidget::Hide(p_HelpBar, v5);
  UFG::SetInputMode(
    this->mSavedControllerMode,
    UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->mControllerIndex);
  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(v7, v6) )
  {
    if ( (_S17_6 & 1) == 0 )
    {
      _S17_6 |= 1u;
      Set_State_minigame_mus_end.mUID = UFG::qWiseSymbolUIDFromString("Set_State_minigame_mus_end", 0x811C9DC5);
      _((AMD_HD3D *)Set_State_minigame_mus_end.mUID);
      atexit(UFG::UIHKScreenPickLockMinigame::_UIHKScreenPickLockMinigame_::_4_::_dynamic_atexit_destructor_for__Set_State_minigame_mus_end__);
    }
    UFG::Music::MusicEvent(Set_State_minigame_mus_end.mUID);
    UFG::qWiseSymbol::create_from_string(&result, "Stop_lp_motion");
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, result.mUID, 0i64, 0, 0i64);
    v8 = UFG::qWiseSymbol::create_from_string(&v10, "mg_lock_picking");
    UFG::TiDo::UnloadWwiseBank(v8);
    _((AMD_HD3D *)v10.mUID);
    _((AMD_HD3D *)result.mUID);
  }
  UFG::UIHKMinigameScreen::~UIHKMinigameScreen(this);
}

// File Line: 75
// RVA: 0x635760
void __fastcall UFG::UIHKScreenPickLockMinigame::init(UFG::UIHKScreenPickLockMinigame *this, UFG::UICommandData *data)
{
  UFG::UIHKMissionProgressWidget *v3; // rax
  Scaleform::GFx::Movie *pObject; // rsi
  bool m_IsKeyboardController; // di
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h] BYREF

  UFG::UIScreen::init(this, data);
  v3 = UFG::UIHKScreenHud::MissionProgress;
  UFG::UIHKScreenHud::MissionProgress->mChanged = 1;
  v3->mData[0].Changed = 1;
  v3->mData[1].Changed = 1;
  v3->mData[2].Changed = 1;
  v3->mData[3].Changed = 1;
  UFG::UIHKScreenPickLockMinigame::refreshDifficulty(this);
  pObject = this->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    pargs.pObjectInterface = 0i64;
    pargs.Type = VT_Undefined;
    m_IsKeyboardController = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController;
    pargs.Type = VT_Boolean;
    pargs.mValue.BValue = m_IsKeyboardController;
    Scaleform::GFx::Movie::Invoke(pObject, "Show_PC", 0i64, &pargs, 1u);
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
  *(_QWORD *)&this->m_fRightStickY = 0i64;
  this->m_fMoveUp = 0.0;
  this->m_musicPlay = 0;
}

// File Line: 102
// RVA: 0x63EFB0
void __fastcall UFG::UIHKScreenPickLockMinigame::update(UFG::UIHKScreenPickLockMinigame *this, float elapsed)
{
  char v3; // di
  UFG::qWiseSymbol *v4; // rax
  bool v5; // si
  UFG::InputActionData *v6; // rcx
  float mAxisPositionY; // xmm0_4
  UFG::InputActionData *v8; // rcx
  float mAxisPositionX; // xmm0_4
  UFG::InputActionData *v10; // rax
  float v11; // xmm0_4
  float v12; // xmm0_4
  float v13; // xmm2_4
  UFG::InputActionData *v14; // rcx
  double m_fRightStickY; // xmm6_8
  double m_fLeftStickX; // xmm6_8
  Scaleform::GFx::Movie *pObject; // rdi
  bool m_IsKeyboardController; // si
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-B0h] BYREF
  Scaleform::GFx::Value pval; // [rsp+68h] [rbp-80h] BYREF
  __int64 v21; // [rsp+98h] [rbp-50h]
  int v22; // [rsp+A0h] [rbp-48h]
  double v23; // [rsp+A8h] [rbp-40h]
  char v24[16]; // [rsp+B8h] [rbp-30h] BYREF
  __int64 v25; // [rsp+C8h] [rbp-20h]
  int v26; // [rsp+D0h] [rbp-18h]
  double v27; // [rsp+D8h] [rbp-10h]
  char v28[16]; // [rsp+E8h] [rbp+0h] BYREF
  __int64 v29; // [rsp+F8h] [rbp+10h]
  int v30; // [rsp+100h] [rbp+18h]
  double v31; // [rsp+108h] [rbp+20h]
  __int64 v32; // [rsp+118h] [rbp+30h]
  void *retaddr; // [rsp+178h] [rbp+90h] BYREF

  v32 = -2i64;
  v3 = 0;
  if ( !UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "NISPause") )
  {
    v5 = 0;
    if ( !this->m_musicPlay )
    {
      v4 = UFG::qWiseSymbol::create_from_string((UFG::qWiseSymbol *)&retaddr, "mg_lock_picking");
      v3 = 1;
      if ( UFG::TiDo::BankLoaded(v4->mUID) )
        v5 = 1;
    }
    if ( (v3 & 1) != 0 )
      _((AMD_HD3D *)(unsigned int)retaddr);
    if ( v5 )
    {
      UFG::qWiseSymbol::create_from_string((UFG::qWiseSymbol *)&retaddr, "Play_lp_motion");
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, (unsigned int)retaddr, 0i64, 0, 0i64);
      if ( (_S18_6 & 1) == 0 )
      {
        _S18_6 |= 1u;
        Set_State_minigame_mus_start.mUID = UFG::qWiseSymbolUIDFromString("Set_State_minigame_mus_start", 0x811C9DC5);
        _((AMD_HD3D *)Set_State_minigame_mus_start.mUID);
        atexit(UFG::UIHKScreenPickLockMinigame::update_::_8_::_dynamic_atexit_destructor_for__Set_State_minigame_mus_start__);
      }
      UFG::Music::MusicEvent(Set_State_minigame_mus_start.mUID);
      this->m_musicPlay = 1;
      _((AMD_HD3D *)(unsigned int)retaddr);
    }
    v6 = UFG::ActionDef_UIRightThumbstick.mDataPerController[UFG::gActiveControllerNum];
    if ( v6 )
      mAxisPositionY = v6->mAxisPositionY;
    else
      mAxisPositionY = 0.0;
    this->m_fRightStickY = mAxisPositionY;
    v8 = UFG::ActionDef_UILeftThumbstick.mDataPerController[UFG::gActiveControllerNum];
    if ( v8 )
      mAxisPositionX = v8->mAxisPositionX;
    else
      mAxisPositionX = 0.0;
    this->m_fLeftStickX = mAxisPositionX;
    if ( UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
    {
      v10 = UFG::ActionDef_Mouse.mDataPerController[UFG::gActiveControllerNum];
      if ( v10 )
        v11 = v10->mAxisPositionY;
      else
        v11 = 0.0;
      v12 = (float)(v11 / UFG::gMousePickLockPixels) + this->m_fMoveUp;
      this->m_fMoveUp = v12;
      v13 = FLOAT_N1_0;
      if ( v12 <= -1.0 )
      {
        v12 = FLOAT_N1_0;
      }
      else if ( v12 >= 0.0 )
      {
        v12 = 0.0;
      }
      this->m_fMoveUp = v12;
      this->m_fRightStickY = v12;
      v14 = UFG::ActionDef_UIMouseAccept.mDataPerController[UFG::gActiveControllerNum];
      if ( !v14 || !v14->mActionTrue )
        v13 = 0.0;
      this->m_fLeftStickX = v13;
    }
    `eh vector constructor iterator(
      &pval.mValue,
      0x30ui64,
      3,
      (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    m_fRightStickY = this->m_fRightStickY;
    if ( (v22 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, Scaleform::GFx::Value::ValueUnion *, double))(*(_QWORD *)v21 + 16i64))(
        v21,
        &pval.mValue,
        COERCE_DOUBLE(*(_QWORD *)&v23));
      v21 = 0i64;
    }
    v22 = 5;
    v23 = m_fRightStickY;
    m_fLeftStickX = this->m_fLeftStickX;
    if ( (v26 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v25 + 16i64))(
        v25,
        v24,
        COERCE_DOUBLE(*(_QWORD *)&v27));
      v25 = 0i64;
    }
    v26 = 5;
    v27 = m_fLeftStickX;
    if ( (v30 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v29 + 16i64))(
        v29,
        v28,
        COERCE_DOUBLE(*(_QWORD *)&v31));
      v29 = 0i64;
    }
    v30 = 5;
    v31 = elapsed;
    pObject = this->mRenderable->m_movie.pObject;
    if ( pObject )
    {
      pargs.pObjectInterface = 0i64;
      pargs.Type = VT_Undefined;
      m_IsKeyboardController = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController;
      pargs.Type = VT_Boolean;
      pargs.mValue.BValue = m_IsKeyboardController;
      Scaleform::GFx::Movie::Invoke(pObject, "Show_PC", 0i64, &pargs, 1u);
      Scaleform::GFx::Movie::Invoke(pObject, "MainLoop", 0i64, (Scaleform::GFx::Value *)&pval.mValue, 3u);
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
    pval.pObjectInterface = 0i64;
    LODWORD(pval.pPrev) = 0;
    if ( Scaleform::GFx::Movie::GetVariable(pObject, &pval, "newPin") && LOBYTE(pval.pNext) == 1 )
      this->m_fMoveUp = 0.0;
    UFG::UIHKMissionProgressWidget::Update(UFG::UIHKScreenHud::MissionProgress, this);
    UFG::UIScreen::update(this, elapsed);
    if ( ((__int64)pval.pPrev & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value *))&pval.pObjectInterface->vfptr->gap8[8])(
        pval.pObjectInterface,
        &pval,
        pval.pNext);
      pval.pObjectInterface = 0i64;
    }
    LODWORD(pval.pPrev) = 0;
    `eh vector destructor iterator(
      &pval.mValue,
      0x30ui64,
      3,
      (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 163
// RVA: 0x629AF0
bool __fastcall UFG::UIHKScreenPickLockMinigame::handleMessage(
        UFG::UIHKScreenPickLockMinigame *this,
        hkgpIndexedMeshDefinitions::Edge *msgId,
        UFG::UIMessage *msg)
{
  hkgpIndexedMeshDefinitions::Edge *v5; // rdx
  hkgpIndexedMesh::EdgeBarrier *v6; // rcx
  unsigned int v7; // eax
  unsigned int mUID; // ebx
  UFG::Music *v9; // rdi
  float v10; // xmm0_4
  UFG::qString v11; // [rsp+38h] [rbp-30h] BYREF
  UFG::qWiseSymbol result; // [rsp+78h] [rbp+10h] BYREF

  if ( (_DWORD)msgId == UI_HASH_SETFINISHED_20 )
    goto LABEL_2;
  if ( (_DWORD)msgId == UI_HASH_SETWON_20 )
  {
    UFG::GameStatAction::MiniGame::Completed(MGT_LockPick);
    UFG::UIHKScreenPickLockMinigame::m_bWon = 1;
    Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(v6, v5);
    return 1;
  }
  else
  {
    if ( (_DWORD)msgId == UI_HASH_BUTTON_BACK_PRESSED_30 )
    {
LABEL_2:
      this->mFinished = 1;
      return 1;
    }
    if ( (_DWORD)msgId == UI_HASH_PLAYSOUND_20 )
    {
      if ( Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
             (hkgpIndexedMesh::EdgeBarrier *)this,
             msgId) )
      {
        return 1;
      }
      UFG::qString::qString(&v11, (UFG::qString *)&msg[1]);
      v7 = UFG::TiDo::CalcWwiseUid(v11.mData);
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, v7, 0i64, 0, 0i64);
      UFG::qString::~qString(&v11);
      return 1;
    }
    else if ( (_DWORD)msgId == UI_HASH_MODIFYRTPC_20 )
    {
      if ( Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
             (hkgpIndexedMesh::EdgeBarrier *)this,
             msgId) )
      {
        return 1;
      }
      UFG::qString::qString(&v11, (UFG::qString *)&msg[1]);
      UFG::qWiseSymbol::create_from_string(&result, "minigame_progress");
      mUID = result.mUID;
      v9 = UFG::Music::sm_instance;
      v10 = UFG::qToFloat(v11.mData, 0.0);
      UFG::AudioEntity::SetRtpcValue(v9, mUID, v10);
      _((AMD_HD3D *)result.mUID);
      UFG::qString::~qString(&v11);
      return 1;
    }
    else
    {
      return UFG::UIHKMinigameScreen::handleMessage(this, (unsigned int)msgId, msg);
    }
  }
}

// File Line: 215
// RVA: 0x639C20
void __fastcall UFG::UIHKScreenPickLockMinigame::refreshDifficulty(UFG::UIHKScreenPickLockMinigame *this)
{
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value::ValueUnion v2; // xmm6_8
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-50h] BYREF

  pObject = this->mRenderable->m_movie.pObject;
  `eh vector constructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  v2.NValue = (double)UFG::UIHKScreenPickLockMinigame::m_iDifficulty;
  if ( (pargs.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      pargs.mValue);
    pargs.pObjectInterface = 0i64;
  }
  pargs.Type = VT_Number;
  pargs.mValue = v2;
  if ( pObject )
    Scaleform::GFx::Movie::Invoke(pObject, "setDifficulty", 0i64, &pargs, 1u);
  `eh vector destructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

