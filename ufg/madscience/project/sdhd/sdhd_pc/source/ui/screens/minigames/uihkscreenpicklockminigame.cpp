// File Line: 39
// RVA: 0x5C6D60
void __fastcall UFG::UIHKScreenPickLockMinigame::UIHKScreenPickLockMinigame(UFG::UIHKScreenPickLockMinigame *this)
{
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v1; // rax
  hkgpIndexedMeshDefinitions::Edge *v2; // rdx
  hkgpIndexedMesh::EdgeBarrier *v3; // rcx
  UFG::qWiseSymbol *v4; // rax
  UFG::qWiseSymbol result; // [rsp+48h] [rbp+10h]

  v1 = (UFG::qNode<UFG::UIScreen,UFG::UIScreen> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
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
  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(v3, v2) )
  {
    v4 = UFG::qWiseSymbol::create_from_string(&result, "mg_lock_picking");
    UFG::TiDo::LoadWwiseBank(v4);
    _((AMD_HD3D *)result.mUID);
  }
}

// File Line: 56
// RVA: 0x5CC270
void __fastcall UFG::UIHKScreenPickLockMinigame::~UIHKScreenPickLockMinigame(UFG::UIHKScreenPickLockMinigame *this)
{
  UFG::UIHKScreenPickLockMinigame *v1; // rbx
  UFG::UIScreenTextureManager *v2; // rax
  UFG::UIHKScreenGlobalOverlay *v3; // rax
  UFG::UIHKHelpBarWidget *v4; // rdi
  unsigned int v5; // eax
  hkgpIndexedMeshDefinitions::Edge *v6; // rdx
  hkgpIndexedMesh::EdgeBarrier *v7; // rcx
  UFG::qWiseSymbol *v8; // rax
  UFG::qWiseSymbol result; // [rsp+58h] [rbp+10h]
  UFG::qWiseSymbol v10; // [rsp+60h] [rbp+18h]

  v1 = this;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenPickLockMinigame::`vftable;
  v2 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v2, "PickLockMinigame");
  v3 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    v3 = &gGlobalOverlaySentinel;
  v4 = &v3->HelpBar;
  v5 = UFG::qStringHash32("UIHKScreenPickLockMinigame", 0xFFFFFFFF);
  UFG::UIHKHelpBarWidget::Hide(v4, v5);
  UFG::SetInputMode(
    v1->mSavedControllerMode,
    UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->mControllerIndex);
  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(v7, v6) )
  {
    if ( !(_S17_6 & 1) )
    {
      _S17_6 |= 1u;
      Set_State_minigame_mus_end.mUID = UFG::qWiseSymbolUIDFromString("Set_State_minigame_mus_end", 0x811C9DC5);
      _((AMD_HD3D *)Set_State_minigame_mus_end.mUID);
      atexit(UFG::UIHKScreenPickLockMinigame::_UIHKScreenPickLockMinigame_::_4_::_dynamic_atexit_destructor_for__Set_State_minigame_mus_end__);
    }
    UFG::Music::MusicEvent(Set_State_minigame_mus_end.mUID);
    UFG::qWiseSymbol::create_from_string(&result, "Stop_lp_motion");
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        result.mUID,
        0i64,
        0,
        0i64);
    v8 = UFG::qWiseSymbol::create_from_string(&v10, "mg_lock_picking");
    UFG::TiDo::UnloadWwiseBank(v8);
    _((AMD_HD3D *)v10.mUID);
    _((AMD_HD3D *)result.mUID);
  }
  UFG::UIHKMinigameScreen::~UIHKMinigameScreen((UFG::UIHKMinigameScreen *)&v1->vfptr);
}

// File Line: 75
// RVA: 0x635760
void __fastcall UFG::UIHKScreenPickLockMinigame::init(UFG::UIHKScreenPickLockMinigame *this, UFG::UICommandData *data)
{
  UFG::UIHKScreenPickLockMinigame *v2; // rbx
  UFG::UIHKMissionProgressWidget *v3; // rax
  Scaleform::GFx::Movie *v4; // rsi
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
  UFG::UIHKScreenPickLockMinigame::refreshDifficulty(v2);
  v4 = v2->mRenderable->m_movie.pObject;
  if ( v4 )
  {
    pargs.pObjectInterface = 0i64;
    pargs.Type = 0;
    v5 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController;
    pargs.Type = 2;
    pargs.mValue.BValue = v5;
    Scaleform::GFx::Movie::Invoke(v4, "Show_PC", 0i64, &pargs, 1u);
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
  *(_QWORD *)&v2->m_fRightStickY = 0i64;
  v2->m_fMoveUp = 0.0;
  v2->m_musicPlay = 0;
}

// File Line: 102
// RVA: 0x63EFB0
void __fastcall UFG::UIHKScreenPickLockMinigame::update(UFG::UIHKScreenPickLockMinigame *this, float elapsed)
{
  UFG::UIHKScreenPickLockMinigame *v2; // rbx
  char v3; // di
  UFG::qWiseSymbol *v4; // rax
  bool v5; // si
  UFG::InputActionData *v6; // rcx
  float v7; // xmm0_4
  UFG::InputActionData *v8; // rcx
  float v9; // xmm0_4
  UFG::InputActionData *v10; // rax
  float v11; // xmm0_4
  float v12; // xmm0_4
  float v13; // xmm2_4
  UFG::InputActionData *v14; // rcx
  double v15; // xmm6_8
  double v16; // xmm6_8
  Scaleform::GFx::Movie *v17; // rdi
  bool v18; // si
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-B0h]
  Scaleform::GFx::Value pval; // [rsp+68h] [rbp-80h]
  __int64 v21; // [rsp+98h] [rbp-50h]
  unsigned int v22; // [rsp+A0h] [rbp-48h]
  double v23; // [rsp+A8h] [rbp-40h]
  char v24; // [rsp+B8h] [rbp-30h]
  __int64 v25; // [rsp+C8h] [rbp-20h]
  unsigned int v26; // [rsp+D0h] [rbp-18h]
  double v27; // [rsp+D8h] [rbp-10h]
  char v28; // [rsp+E8h] [rbp+0h]
  __int64 v29; // [rsp+F8h] [rbp+10h]
  unsigned int v30; // [rsp+100h] [rbp+18h]
  double v31; // [rsp+108h] [rbp+20h]
  __int64 v32; // [rsp+118h] [rbp+30h]
  void *retaddr; // [rsp+178h] [rbp+90h]

  v32 = -2i64;
  v2 = this;
  v3 = 0;
  if ( !UFG::UIScreenManagerBase::getScreen(
          (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
          "NISPause") )
  {
    v5 = 0;
    if ( !v2->m_musicPlay )
    {
      v4 = UFG::qWiseSymbol::create_from_string((UFG::qWiseSymbol *)&retaddr, "mg_lock_picking");
      v3 = 1;
      if ( (unsigned __int8)UFG::TiDo::BankLoaded(v4->mUID) )
        v5 = 1;
    }
    if ( v3 & 1 )
      _((AMD_HD3D *)(unsigned int)retaddr);
    if ( v5 )
    {
      UFG::qWiseSymbol::create_from_string((UFG::qWiseSymbol *)&retaddr, "Play_lp_motion");
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(
          (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
          (unsigned int)retaddr,
          0i64,
          0,
          0i64);
      if ( !(_S18_6 & 1) )
      {
        _S18_6 |= 1u;
        Set_State_minigame_mus_start.mUID = UFG::qWiseSymbolUIDFromString("Set_State_minigame_mus_start", 0x811C9DC5);
        _((AMD_HD3D *)Set_State_minigame_mus_start.mUID);
        atexit(UFG::UIHKScreenPickLockMinigame::update_::_8_::_dynamic_atexit_destructor_for__Set_State_minigame_mus_start__);
      }
      UFG::Music::MusicEvent(Set_State_minigame_mus_start.mUID);
      v2->m_musicPlay = 1;
      _((AMD_HD3D *)(unsigned int)retaddr);
    }
    v6 = UFG::ActionDef_UIRightThumbstick.mDataPerController[UFG::gActiveControllerNum];
    if ( v6 )
      v7 = v6->mAxisPositionY;
    else
      v7 = 0.0;
    v2->m_fRightStickY = v7;
    v8 = UFG::ActionDef_UILeftThumbstick.mDataPerController[UFG::gActiveControllerNum];
    if ( v8 )
      v9 = v8->mAxisPositionX;
    else
      v9 = 0.0;
    v2->m_fLeftStickX = v9;
    if ( UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
    {
      v10 = UFG::ActionDef_Mouse.mDataPerController[UFG::gActiveControllerNum];
      if ( v10 )
        v11 = v10->mAxisPositionY;
      else
        v11 = 0.0;
      v12 = (float)(v11 / UFG::gMousePickLockPixels) + v2->m_fMoveUp;
      v2->m_fMoveUp = v12;
      v13 = FLOAT_N1_0;
      if ( v12 <= -1.0 )
      {
        v12 = FLOAT_N1_0;
      }
      else if ( v12 >= 0.0 )
      {
        v12 = 0.0;
      }
      v2->m_fMoveUp = v12;
      v2->m_fRightStickY = v12;
      v14 = UFG::ActionDef_UIMouseAccept.mDataPerController[UFG::gActiveControllerNum];
      if ( !v14 || !v14->mActionTrue )
        v13 = 0.0;
      v2->m_fLeftStickX = v13;
    }
    `eh vector constructor iterator(
      &pval.mValue,
      0x30ui64,
      3,
      (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    v15 = v2->m_fRightStickY;
    if ( (v22 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, Scaleform::GFx::Value::ValueUnion *, double))(*(_QWORD *)v21 + 16i64))(
        v21,
        &pval.mValue,
        COERCE_DOUBLE(*(_QWORD *)&v23));
      v21 = 0i64;
    }
    v22 = 5;
    v23 = v15;
    v16 = v2->m_fLeftStickX;
    if ( (v26 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v25 + 16i64))(
        v25,
        &v24,
        COERCE_DOUBLE(*(_QWORD *)&v27));
      v25 = 0i64;
    }
    v26 = 5;
    v27 = v16;
    if ( (v30 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v29 + 16i64))(
        v29,
        &v28,
        COERCE_DOUBLE(*(_QWORD *)&v31));
      v29 = 0i64;
    }
    v30 = 5;
    v31 = elapsed;
    v17 = v2->mRenderable->m_movie.pObject;
    if ( v17 )
    {
      pargs.pObjectInterface = 0i64;
      pargs.Type = 0;
      v18 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController;
      pargs.Type = 2;
      pargs.mValue.BValue = v18;
      Scaleform::GFx::Movie::Invoke(v17, "Show_PC", 0i64, &pargs, 1u);
      Scaleform::GFx::Movie::Invoke(v17, "MainLoop", 0i64, (Scaleform::GFx::Value *)((char *)&pval + 32), 3u);
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
    pval.pObjectInterface = 0i64;
    LODWORD(pval.pPrev) = 0;
    if ( Scaleform::GFx::Movie::GetVariable(v17, &pval, "newPin") && LOBYTE(pval.pNext) == 1 )
      v2->m_fMoveUp = 0.0;
    UFG::UIHKMissionProgressWidget::Update(UFG::UIHKScreenHud::MissionProgress, (UFG::UIScreen *)&v2->vfptr);
    UFG::UIScreen::update((UFG::UIScreen *)&v2->vfptr, elapsed);
    if ( (LODWORD(pval.pPrev) >> 6) & 1 )
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
bool __fastcall UFG::UIHKScreenPickLockMinigame::handleMessage(UFG::UIHKScreenPickLockMinigame *this, __int64 msgId, UFG::UIMessage *msg)
{
  UFG::UIMessage *v3; // rbx
  bool v4; // al
  hkgpIndexedMeshDefinitions::Edge *v5; // rdx
  hkgpIndexedMesh::EdgeBarrier *v6; // rcx
  unsigned int v7; // eax
  unsigned int v8; // ebx
  UFG::Music *v9; // rdi
  float v10; // xmm0_4
  UFG::qString v11; // [rsp+38h] [rbp-30h]
  UFG::qWiseSymbol result; // [rsp+78h] [rbp+10h]

  v3 = msg;
  if ( (_DWORD)msgId == UI_HASH_SETFINISHED_20 )
    goto LABEL_2;
  if ( (_DWORD)msgId == UI_HASH_SETWON_20 )
  {
    UFG::GameStatAction::MiniGame::Completed(MGT_LockPick);
    UFG::UIHKScreenPickLockMinigame::m_bWon = 1;
    Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(v6, v5);
    v4 = 1;
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
             (hkgpIndexedMeshDefinitions::Edge *)msgId) )
      {
        return 1;
      }
      UFG::qString::qString(&v11, (UFG::qString *)&v3[1]);
      v7 = UFG::TiDo::CalcWwiseUid(v11.mData);
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr, v7, 0i64, 0, 0i64);
      UFG::qString::~qString(&v11);
      v4 = 1;
    }
    else if ( (_DWORD)msgId == UI_HASH_MODIFYRTPC_20 )
    {
      if ( Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
             (hkgpIndexedMesh::EdgeBarrier *)this,
             (hkgpIndexedMeshDefinitions::Edge *)msgId) )
      {
        return 1;
      }
      UFG::qString::qString(&v11, (UFG::qString *)&v3[1]);
      UFG::qWiseSymbol::create_from_string(&result, "minigame_progress");
      v8 = result.mUID;
      v9 = UFG::Music::sm_instance;
      v10 = UFG::qToFloat(v11.mData, 0.0);
      UFG::AudioEntity::SetRtpcValue((UFG::AudioEntity *)&v9->vfptr, v8, v10);
      _((AMD_HD3D *)result.mUID);
      UFG::qString::~qString(&v11);
      v4 = 1;
    }
    else
    {
      v4 = UFG::UIHKMinigameScreen::handleMessage((UFG::UIHKMinigameScreen *)&this->vfptr, msgId, msg);
    }
  }
  return v4;
}

// File Line: 215
// RVA: 0x639C20
void __fastcall UFG::UIHKScreenPickLockMinigame::refreshDifficulty(UFG::UIHKScreenPickLockMinigame *this)
{
  Scaleform::GFx::Movie *v1; // rbx
  double v2; // xmm6_8
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-50h]

  v1 = this->mRenderable->m_movie.pObject;
  `eh vector constructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  v2 = (double)UFG::UIHKScreenPickLockMinigame::m_iDifficulty;
  if ( ((unsigned int)pargs.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      *(_QWORD *)&pargs.mValue.NValue);
    pargs.pObjectInterface = 0i64;
  }
  pargs.Type = 5;
  pargs.mValue.NValue = v2;
  if ( v1 )
    Scaleform::GFx::Movie::Invoke(v1, "setDifficulty", 0i64, &pargs, 1u);
  `eh vector destructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

