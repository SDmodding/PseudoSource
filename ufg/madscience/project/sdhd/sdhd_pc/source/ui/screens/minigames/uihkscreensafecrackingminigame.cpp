// File Line: 30
// RVA: 0x5C7080
void __fastcall UFG::UIHKScreenSafeCrackingMinigame::UIHKScreenSafeCrackingMinigame(
        UFG::UIHKScreenSafeCrackingMinigame *this)
{
  float y; // xmm1_4
  hkgpIndexedMeshDefinitions::Edge *v3; // rdx
  hkgpIndexedMesh::EdgeBarrier *v4; // rcx
  UFG::qWiseSymbol *v5; // rax
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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenSafeCrackingMinigame::`vftable;
  this->mSavedControllerMode = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_ActiveMapSet;
  UFG::SetInputMode(IM_UI_ONLY, UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->mControllerIndex);
  UFG::UIHKScreenSafeCrackingMinigame::m_bWon = 0;
  this->mbMusicPlay = 0;
  this->firstOut = 1;
  y = UFG::qVector2::msZero.y;
  this->g_previousVector.x = UFG::qVector2::msZero.x;
  this->g_previousVector.y = y;
  this->mbAllowControls = 0;
  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(v4, v3) )
  {
    v5 = UFG::qWiseSymbol::create_from_string(&result, "mg_safe_cracking");
    UFG::TiDo::LoadWwiseBank(v5);
    _((AMD_HD3D *)result.mUID);
  }
}

// File Line: 50
// RVA: 0x5CC4D0
void __fastcall UFG::UIHKScreenSafeCrackingMinigame::~UIHKScreenSafeCrackingMinigame(
        UFG::UIHKScreenSafeCrackingMinigame *this)
{
  UFG::UIScreenTextureManager *v2; // rax
  UFG::UIHKScreenGlobalOverlay *v3; // rax
  UFG::UIHKHelpBarWidget *p_HelpBar; // rbx
  unsigned int v5; // eax
  hkgpIndexedMeshDefinitions::Edge *v6; // rdx
  UFG::UI *v7; // rcx
  unsigned int v8; // eax
  UFG::qWiseSymbol *v9; // rax
  UFG::qWiseSymbol result; // [rsp+58h] [rbp+10h] BYREF
  UFG::qWiseSymbol v11; // [rsp+60h] [rbp+18h] BYREF

  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenSafeCrackingMinigame::`vftable;
  v2 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v2, "SafeCrackingMinigame");
  UFG::SetInputMode(
    this->mSavedControllerMode,
    UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->mControllerIndex);
  v3 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    v3 = &gGlobalOverlaySentinel;
  p_HelpBar = &v3->HelpBar;
  v5 = UFG::qStringHash32("UIHKScreenSafeCrackingMinigame", 0xFFFFFFFF);
  UFG::UIHKHelpBarWidget::Hide(p_HelpBar, v5);
  if ( UFG::gInputSystem )
  {
    if ( UFG::gActiveControllerNum != -1 )
    {
      v8 = UFG::UI::gUIInputLocked;
      if ( !UFG::UI::gUIInputLocked || (--UFG::UI::gUIInputLocked, v8 == 1) )
        UFG::UI::ResetGameplayInput(v7);
    }
  }
  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat((hkgpIndexedMesh::EdgeBarrier *)v7, v6) )
  {
    if ( (_S28_2 & 1) == 0 )
    {
      _S28_2 |= 1u;
      Set_State_minigame_mus_end_4.mUID = UFG::qWiseSymbolUIDFromString("Set_State_minigame_mus_end", 0x811C9DC5);
      _((AMD_HD3D *)Set_State_minigame_mus_end_4.mUID);
      atexit(UFG::UIHKScreenSafeCrackingMinigame::_UIHKScreenSafeCrackingMinigame_::_4_::_dynamic_atexit_destructor_for__Set_State_minigame_mus_end__);
    }
    UFG::Music::MusicEvent(Set_State_minigame_mus_end_4.mUID);
    UFG::qWiseSymbol::create_from_string(&result, "Stop_ch_start_hack");
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, result.mUID, 0i64, 0, 0i64);
    v9 = UFG::qWiseSymbol::create_from_string(&v11, "mg_safe_cracking");
    UFG::TiDo::UnloadWwiseBank(v9);
    _((AMD_HD3D *)v11.mUID);
    _((AMD_HD3D *)result.mUID);
  }
  UFG::UIHKMinigameScreen::~UIHKMinigameScreen(this);
}

// File Line: 70
// RVA: 0x635AD0
void __fastcall UFG::UIHKScreenSafeCrackingMinigame::init(
        UFG::UIHKScreenSafeCrackingMinigame *this,
        UFG::UICommandData *data)
{
  UFG::UIHKMissionProgressWidget *v3; // rdx
  UFG::UIHKMissionProgressWidget *v4; // rax
  Scaleform::GFx::Movie *pObject; // rdi
  bool m_IsKeyboardController; // bl
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h] BYREF

  UFG::UIScreen::init(this, data);
  v3 = UFG::UIHKScreenHud::MissionProgress;
  UFG::UIHKScreenHud::MissionProgress->mChanged |= UFG::UIHKScreenHud::MissionProgress->mVisible;
  v3->mVisible = 0;
  v4 = UFG::UIHKScreenHud::MissionProgress;
  UFG::UIHKScreenHud::MissionProgress->mChanged = 1;
  v4->mData[0].Changed = 1;
  v4->mData[1].Changed = 1;
  v4->mData[2].Changed = 1;
  v4->mData[3].Changed = 1;
  pObject = this->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    pargs.pObjectInterface = 0i64;
    pargs.Type = VT_Undefined;
    m_IsKeyboardController = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController;
    pargs.Type = VT_Boolean;
    pargs.mValue.BValue = m_IsKeyboardController;
    Scaleform::GFx::Movie::Invoke(pObject, "Show_PCCtrls", 0i64, &pargs, 1u);
    if ( (pargs.Type & 0x40) != 0 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        pargs.mValue);
  }
}

// File Line: 87
// RVA: 0x63F590
void __fastcall UFG::UIHKScreenSafeCrackingMinigame::update(UFG::UIHKScreenSafeCrackingMinigame *this, float elapsed)
{
  char v4; // bl
  UFG::qWiseSymbol *v5; // rax
  bool v6; // si
  float v7; // xmm6_4
  char v8; // bl
  UFG::InputActionData *v9; // rax
  float v10; // xmm1_4
  UFG::InputActionData *v11; // rax
  char v12; // cl
  UFG::InputActionData *v13; // rax
  bool v14; // al
  double v15; // xmm0_8
  Scaleform::GFx::Movie *pObject; // rbx
  bool m_IsKeyboardController; // si
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-69h] BYREF
  __int64 v19; // [rsp+68h] [rbp-39h]
  int v20; // [rsp+70h] [rbp-31h]
  __int64 v21; // [rsp+78h] [rbp-29h]
  char v22[16]; // [rsp+88h] [rbp-19h] BYREF
  __int64 v23; // [rsp+98h] [rbp-9h]
  int v24; // [rsp+A0h] [rbp-1h]
  __int64 v25; // [rsp+A8h] [rbp+7h]
  __int64 v26; // [rsp+B8h] [rbp+17h]
  void *retaddr; // [rsp+118h] [rbp+77h] BYREF

  v26 = -2i64;
  v4 = 0;
  if ( UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "NISPause") )
    return;
  v6 = 0;
  if ( !this->mbMusicPlay )
  {
    v5 = UFG::qWiseSymbol::create_from_string((UFG::qWiseSymbol *)&retaddr, "mg_safe_cracking");
    v4 = 1;
    if ( UFG::TiDo::BankLoaded(v5->mUID) )
      v6 = 1;
  }
  if ( (v4 & 1) != 0 )
    _((AMD_HD3D *)(unsigned int)retaddr);
  if ( v6 )
  {
    if ( (_S29_0 & 1) == 0 )
    {
      _S29_0 |= 1u;
      Set_State_minigame_mus_start_4.mUID = UFG::qWiseSymbolUIDFromString("Set_State_minigame_mus_start", 0x811C9DC5);
      _((AMD_HD3D *)Set_State_minigame_mus_start_4.mUID);
      atexit(UFG::UIHKScreenSafeCrackingMinigame::update_::_8_::_dynamic_atexit_destructor_for__Set_State_minigame_mus_start__);
    }
    UFG::Music::MusicEvent(Set_State_minigame_mus_start_4.mUID);
    UFG::qWiseSymbol::create_from_string((UFG::qWiseSymbol *)&retaddr, "Play_ch_start_hack");
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, (unsigned int)retaddr, 0i64, 0, 0i64);
    this->mbMusicPlay = 1;
    _((AMD_HD3D *)(unsigned int)retaddr);
  }
  v7 = UFG::UIHKScreenSafeCrackingMinigame::calcLeftStickRotation(this);
  v8 = 0;
  if ( UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
  {
    v9 = UFG::ActionDef_UILeftThumbstick.mDataPerController[UFG::gActiveControllerNum];
    if ( v9 )
    {
      v10 = v9->mAxisRawX[0];
      if ( v10 < 0.0 )
        goto LABEL_21;
    }
    else
    {
      v10 = 0.0;
    }
    v11 = UFG::ActionDef_UILeftRepeat.mDataPerController[UFG::gActiveControllerNum];
    if ( !v11 || !v11->mActionTrue )
    {
      v12 = 0;
      goto LABEL_22;
    }
LABEL_21:
    v12 = 1;
LABEL_22:
    v14 = 1;
    if ( v10 <= 0.0 )
    {
      v13 = UFG::ActionDef_UIRightRepeat.mDataPerController[UFG::gActiveControllerNum];
      if ( !v13 || !v13->mActionTrue )
        v14 = 0;
    }
    if ( v12 )
    {
      v7 = (float)(elapsed * 180.0) * -1.0;
    }
    else if ( v14 )
    {
      v7 = elapsed * 180.0;
    }
    v8 = 1;
  }
  `eh vector constructor iterator(
    &pargs.mValue,
    0x30ui64,
    2,
    (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  if ( this->mbAllowControls )
  {
    if ( (v20 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, Scaleform::GFx::Value::ValueUnion *, __int64))(*(_QWORD *)v19 + 16i64))(
        v19,
        &pargs.mValue,
        v21);
      v19 = 0i64;
    }
    v15 = v7;
  }
  else
  {
    if ( (v20 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, Scaleform::GFx::Value::ValueUnion *, __int64))(*(_QWORD *)v19 + 16i64))(
        v19,
        &pargs.mValue,
        v21);
      v19 = 0i64;
    }
    v15 = 0.0;
  }
  v21 = *(_QWORD *)&v15;
  v20 = 5;
  if ( (v24 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v23 + 16i64))(v23, v22, v25);
    v23 = 0i64;
  }
  v24 = 2;
  LOBYTE(v25) = v8;
  pObject = this->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    LODWORD(pargs.pPrev) = 0;
    m_IsKeyboardController = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController;
    LODWORD(pargs.pPrev) = 2;
    LOBYTE(pargs.pNext) = m_IsKeyboardController;
    Scaleform::GFx::Movie::Invoke(pObject, "Show_PCCtrls", 0i64, &pargs, 1u);
    Scaleform::GFx::Movie::Invoke(pObject, "mainLoop", 0i64, (Scaleform::GFx::Value *)&pargs.mValue, 2u);
    if ( ((__int64)pargs.pPrev & 0x40) != 0 )
      (*(void (__fastcall **)(_QWORD, Scaleform::GFx::Value *, Scaleform::GFx::Value *))(MEMORY[0] + 16))(
        0i64,
        &pargs,
        pargs.pNext);
    LODWORD(pargs.pPrev) = 0;
  }
  UFG::UIHKMissionProgressWidget::Update(UFG::UIHKScreenHud::MissionProgress, this);
  UFG::UIScreen::update(this, elapsed);
  `eh vector destructor iterator(
    &pargs.mValue,
    0x30ui64,
    2,
    (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 149
// RVA: 0x62AA20
bool __fastcall UFG::UIHKScreenSafeCrackingMinigame::handleMessage(
        UFG::UIHKScreenSafeCrackingMinigame *this,
        unsigned int msgId,
        UFG::UIMessage *msg)
{
  unsigned int v4; // eax
  UFG::qString v6; // [rsp+38h] [rbp-30h] BYREF

  if ( msgId == UI_HASH_PLAYSOUND_20 )
  {
    UFG::qString::qString(&v6, (UFG::qString *)&msg[1]);
    v4 = UFG::TiDo::CalcWwiseUid(v6.mData);
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, v4, 0i64, 0, 0i64);
    UFG::qString::~qString(&v6);
    return 1;
  }
  else if ( msgId == UI_HASH_ENABLECONTROLS_20 )
  {
    this->mbAllowControls = 1;
    return 1;
  }
  else if ( msgId == UI_HASH_DISABLECONTROLS_20 )
  {
    this->mbAllowControls = 0;
    return 1;
  }
  else if ( msgId == UI_HASH_BUTTON_BACK_PRESSED_30 )
  {
    this->mFinished = 1;
    return 1;
  }
  else if ( msgId == UI_HASH_SETWON_20 )
  {
    UFG::GameStatAction::MiniGame::Completed(MGT_SafeCrack);
    UFG::UIHKScreenSafeCrackingMinigame::m_bWon = 1;
    this->mFinished = 1;
    return 1;
  }
  else
  {
    return UFG::UIHKMinigameScreen::handleMessage(this, msgId, msg);
  }
}

// File Line: 204
// RVA: 0x61EEA0
float __fastcall UFG::UIHKScreenSafeCrackingMinigame::calcLeftStickRotation(UFG::UIHKScreenSafeCrackingMinigame *this)
{
  UFG::InputActionData *v1; // rdx
  float mAxisPositionY; // xmm8_4
  __m128 mAxisPositionX_low; // xmm9
  float v5; // xmm1_4
  __m128 v6; // xmm0
  __m128 v7; // xmm1
  float v8; // xmm2_4
  float v9; // xmm4_4
  float v10; // xmm9_4
  float v11; // xmm8_4
  __m128 x_low; // xmm2
  __m128 v13; // xmm1
  float v14; // xmm3_4
  float v15; // xmm0_4
  float v16; // xmm6_4
  float y; // xmm2_4

  v1 = UFG::ActionDef_UILeftThumbstick.mDataPerController[UFG::gActiveControllerNum];
  if ( v1 )
    mAxisPositionY = v1->mAxisPositionY;
  else
    mAxisPositionY = 0.0;
  if ( v1 )
    mAxisPositionX_low = (__m128)LODWORD(v1->mAxisPositionX);
  else
    mAxisPositionX_low = 0i64;
  if ( v1 )
    v5 = v1->mAxisPositionY;
  else
    v5 = 0.0;
  if ( v1 )
    v6 = (__m128)LODWORD(v1->mAxisPositionX);
  else
    v6 = 0i64;
  v6.m128_f32[0] = (float)(v6.m128_f32[0] * v6.m128_f32[0]) + (float)(v5 * v5);
  if ( _mm_sqrt_ps(v6).m128_f32[0] <= 0.80000001 )
  {
    this->firstOut = 1;
    y = UFG::qVector2::msZero.y;
    this->g_previousVector.x = UFG::qVector2::msZero.x;
    this->g_previousVector.y = y;
  }
  else
  {
    v7 = mAxisPositionX_low;
    v7.m128_f32[0] = (float)(mAxisPositionX_low.m128_f32[0] * mAxisPositionX_low.m128_f32[0])
                   + (float)(mAxisPositionY * mAxisPositionY);
    if ( v7.m128_f32[0] == 0.0 )
      v8 = 0.0;
    else
      v8 = 1.0 / _mm_sqrt_ps(v7).m128_f32[0];
    v9 = this->g_previousVector.y;
    v10 = mAxisPositionX_low.m128_f32[0] * v8;
    v11 = mAxisPositionY * v8;
    x_low = (__m128)LODWORD(this->g_previousVector.x);
    v13 = x_low;
    v13.m128_f32[0] = (float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(v9 * v9);
    if ( v13.m128_f32[0] == 0.0 )
      v14 = 0.0;
    else
      v14 = 1.0 / _mm_sqrt_ps(v13).m128_f32[0];
    this->g_previousVector.x = x_low.m128_f32[0] * v14;
    this->g_previousVector.y = v9 * v14;
    v15 = atan2f(v11, v10);
    v16 = v15 - atan2f(this->g_previousVector.y, this->g_previousVector.x);
    if ( v16 >= -3.1415927 )
    {
      if ( v16 > 3.1415927 )
        v16 = v16 + -6.2831855;
    }
    else
    {
      v16 = v16 + 6.2831855;
    }
    this->g_previousVector.x = v10;
    this->g_previousVector.y = v11;
    if ( !this->firstOut )
      return v16 * 57.295776;
    this->firstOut = 0;
  }
  return 0.0;
}

