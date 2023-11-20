// File Line: 30
// RVA: 0x5C7080
void __fastcall UFG::UIHKScreenSafeCrackingMinigame::UIHKScreenSafeCrackingMinigame(UFG::UIHKScreenSafeCrackingMinigame *this)
{
  UFG::UIHKScreenSafeCrackingMinigame *v1; // rbx
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v2; // rax
  float v3; // xmm1_4
  hkgpIndexedMeshDefinitions::Edge *v4; // rdx
  hkgpIndexedMesh::EdgeBarrier *v5; // rcx
  UFG::qWiseSymbol *v6; // rax
  UFG::qWiseSymbol result; // [rsp+48h] [rbp+10h]

  v1 = this;
  v2 = (UFG::qNode<UFG::UIScreen,UFG::UIScreen> *)&this->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIScreen::`vftable';
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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKTaskableScreen::`vftable';
  this->mFinished = 0;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKMinigameScreen::`vftable';
  *(_QWORD *)&this->mfAlphaValue = 1109393408i64;
  ++UFG::UIHKMinigameScreen::mNumMinigameScreens;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenSafeCrackingMinigame::`vftable';
  this->mSavedControllerMode = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_ActiveMapSet;
  UFG::SetInputMode(IM_UI_ONLY, UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->mControllerIndex);
  UFG::UIHKScreenSafeCrackingMinigame::m_bWon = 0;
  v1->mbMusicPlay = 0;
  v1->firstOut = 1;
  v3 = UFG::qVector2::msZero.y;
  v1->g_previousVector.x = UFG::qVector2::msZero.x;
  v1->g_previousVector.y = v3;
  v1->mbAllowControls = 0;
  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(v5, v4) )
  {
    v6 = UFG::qWiseSymbol::create_from_string(&result, "mg_safe_cracking");
    UFG::TiDo::LoadWwiseBank(v6);
    _((AMD_HD3D *)result.mUID);
  }
}

// File Line: 50
// RVA: 0x5CC4D0
void __fastcall UFG::UIHKScreenSafeCrackingMinigame::~UIHKScreenSafeCrackingMinigame(UFG::UIHKScreenSafeCrackingMinigame *this)
{
  UFG::UIHKScreenSafeCrackingMinigame *v1; // rdi
  UFG::UIScreenTextureManager *v2; // rax
  UFG::UIHKScreenGlobalOverlay *v3; // rax
  UFG::UIHKHelpBarWidget *v4; // rbx
  unsigned int v5; // eax
  hkgpIndexedMeshDefinitions::Edge *v6; // rdx
  UFG::UI *v7; // rcx
  unsigned int v8; // eax
  UFG::qWiseSymbol *v9; // rax
  UFG::qWiseSymbol result; // [rsp+58h] [rbp+10h]
  UFG::qWiseSymbol v11; // [rsp+60h] [rbp+18h]

  v1 = this;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenSafeCrackingMinigame::`vftable';
  v2 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v2, "SafeCrackingMinigame");
  UFG::SetInputMode(
    v1->mSavedControllerMode,
    UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->mControllerIndex);
  v3 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    v3 = &gGlobalOverlaySentinel;
  v4 = &v3->HelpBar;
  v5 = UFG::qStringHash32("UIHKScreenSafeCrackingMinigame", 0xFFFFFFFF);
  UFG::UIHKHelpBarWidget::Hide(v4, v5);
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
    if ( !(_S28_2 & 1) )
    {
      _S28_2 |= 1u;
      Set_State_minigame_mus_end_4.mUID = UFG::qWiseSymbolUIDFromString("Set_State_minigame_mus_end", 0x811C9DC5);
      _((AMD_HD3D *)Set_State_minigame_mus_end_4.mUID);
      atexit(UFG::UIHKScreenSafeCrackingMinigame::_UIHKScreenSafeCrackingMinigame_::_4_::_dynamic_atexit_destructor_for__Set_State_minigame_mus_end__);
    }
    UFG::Music::MusicEvent(Set_State_minigame_mus_end_4.mUID);
    UFG::qWiseSymbol::create_from_string(&result, "Stop_ch_start_hack");
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        result.mUID,
        0i64,
        0,
        0i64);
    v9 = UFG::qWiseSymbol::create_from_string(&v11, "mg_safe_cracking");
    UFG::TiDo::UnloadWwiseBank(v9);
    _((AMD_HD3D *)v11.mUID);
    _((AMD_HD3D *)result.mUID);
  }
  UFG::UIHKMinigameScreen::~UIHKMinigameScreen((UFG::UIHKMinigameScreen *)&v1->vfptr);
}

// File Line: 70
// RVA: 0x635AD0
void __fastcall UFG::UIHKScreenSafeCrackingMinigame::init(UFG::UIHKScreenSafeCrackingMinigame *this, UFG::UICommandData *data)
{
  UFG::UIHKScreenSafeCrackingMinigame *v2; // rbx
  UFG::UIHKMissionProgressWidget *v3; // rdx
  UFG::UIHKMissionProgressWidget *v4; // rax
  Scaleform::GFx::Movie *v5; // rdi
  bool v6; // bl
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h]

  v2 = this;
  UFG::UIScreen::init((UFG::UIScreen *)&this->vfptr, data);
  v3 = UFG::UIHKScreenHud::MissionProgress;
  v3->mChanged |= UFG::UIHKScreenHud::MissionProgress->mVisible != 0;
  v3->mVisible = 0;
  v4 = UFG::UIHKScreenHud::MissionProgress;
  UFG::UIHKScreenHud::MissionProgress->mChanged = 1;
  v4->mData[0].Changed = 1;
  v4->mData[1].Changed = 1;
  v4->mData[2].Changed = 1;
  v4->mData[3].Changed = 1;
  v5 = v2->mRenderable->m_movie.pObject;
  if ( v5 )
  {
    pargs.pObjectInterface = 0i64;
    pargs.Type = 0;
    v6 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController;
    pargs.Type = 2;
    pargs.mValue.BValue = v6;
    Scaleform::GFx::Movie::Invoke(v5, "Show_PCCtrls", 0i64, &pargs, 1u);
    if ( ((unsigned int)pargs.Type >> 6) & 1 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        *(_QWORD *)&pargs.mValue.NValue);
  }
}

// File Line: 87
// RVA: 0x63F590
void __fastcall UFG::UIHKScreenSafeCrackingMinigame::update(UFG::UIHKScreenSafeCrackingMinigame *this, float elapsed)
{
  float v2; // xmm7_4
  UFG::UIHKScreenSafeCrackingMinigame *v3; // rdi
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
  unsigned int v15; // eax
  double v16; // xmm0_8
  Scaleform::GFx::Movie *v17; // rbx
  bool v18; // si
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-69h]
  __int64 v21; // [rsp+68h] [rbp-39h]
  unsigned int v22; // [rsp+70h] [rbp-31h]
  __int64 v23; // [rsp+78h] [rbp-29h]
  char v24; // [rsp+88h] [rbp-19h]
  __int64 v25; // [rsp+98h] [rbp-9h]
  unsigned int v26; // [rsp+A0h] [rbp-1h]
  __int64 v27; // [rsp+A8h] [rbp+7h]
  __int64 v28; // [rsp+B8h] [rbp+17h]
  void *retaddr; // [rsp+118h] [rbp+77h]

  v28 = -2i64;
  v2 = elapsed;
  v3 = this;
  v4 = 0;
  if ( UFG::UIScreenManagerBase::getScreen(
         (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
         "NISPause") )
  {
    return;
  }
  v6 = 0;
  if ( !v3->mbMusicPlay )
  {
    v5 = UFG::qWiseSymbol::create_from_string((UFG::qWiseSymbol *)&retaddr, "mg_safe_cracking");
    v4 = 1;
    if ( (unsigned __int8)UFG::TiDo::BankLoaded(v5->mUID) )
      v6 = 1;
  }
  if ( v4 & 1 )
    _((AMD_HD3D *)(unsigned int)retaddr);
  if ( v6 )
  {
    if ( !(_S29_0 & 1) )
    {
      _S29_0 |= 1u;
      Set_State_minigame_mus_start_4.mUID = UFG::qWiseSymbolUIDFromString("Set_State_minigame_mus_start", 0x811C9DC5);
      _((AMD_HD3D *)Set_State_minigame_mus_start_4.mUID);
      atexit(UFG::UIHKScreenSafeCrackingMinigame::update_::_8_::_dynamic_atexit_destructor_for__Set_State_minigame_mus_start__);
    }
    UFG::Music::MusicEvent(Set_State_minigame_mus_start_4.mUID);
    UFG::qWiseSymbol::create_from_string((UFG::qWiseSymbol *)&retaddr, "Play_ch_start_hack");
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        (unsigned int)retaddr,
        0i64,
        0,
        0i64);
    v3->mbMusicPlay = 1;
    _((AMD_HD3D *)(unsigned int)retaddr);
  }
  v7 = UFG::UIHKScreenSafeCrackingMinigame::calcLeftStickRotation(v3);
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
      v7 = (float)(v2 * 180.0) * -1.0;
    }
    else if ( v14 )
    {
      v7 = v2 * 180.0;
    }
    v8 = 1;
  }
  `eh vector constructor iterator'(
    &pargs.mValue,
    0x30ui64,
    2,
    (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  v15 = v22 >> 6;
  if ( v3->mbAllowControls )
  {
    if ( v15 & 1 )
    {
      (*(void (__fastcall **)(__int64, Scaleform::GFx::Value::ValueUnion *, __int64))(*(_QWORD *)v21 + 16i64))(
        v21,
        &pargs.mValue,
        v23);
      v21 = 0i64;
    }
    v16 = v7;
  }
  else
  {
    if ( v15 & 1 )
    {
      (*(void (__fastcall **)(__int64, Scaleform::GFx::Value::ValueUnion *, __int64))(*(_QWORD *)v21 + 16i64))(
        v21,
        &pargs.mValue,
        v23);
      v21 = 0i64;
    }
    v16 = 0.0;
  }
  v23 = *(_QWORD *)&v16;
  v22 = 5;
  if ( (v26 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v25 + 16i64))(v25, &v24, v27);
    v25 = 0i64;
  }
  v26 = 2;
  LOBYTE(v27) = v8;
  v17 = v3->mRenderable->m_movie.pObject;
  if ( v17 )
  {
    LODWORD(pargs.pPrev) = 0;
    v18 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController;
    LODWORD(pargs.pPrev) = 2;
    LOBYTE(pargs.pNext) = v18;
    Scaleform::GFx::Movie::Invoke(v17, "Show_PCCtrls", 0i64, &pargs, 1u);
    Scaleform::GFx::Movie::Invoke(v17, "mainLoop", 0i64, (Scaleform::GFx::Value *)((char *)&pargs + 32), 2u);
    if ( (LODWORD(pargs.pPrev) >> 6) & 1 )
      (*(void (__fastcall **)(_QWORD, Scaleform::GFx::Value *, Scaleform::GFx::Value *))(MEMORY[0] + 16))(
        0i64,
        &pargs,
        pargs.pNext);
    LODWORD(pargs.pPrev) = 0;
  }
  UFG::UIHKMissionProgressWidget::Update(UFG::UIHKScreenHud::MissionProgress, (UFG::UIScreen *)&v3->vfptr);
  UFG::UIScreen::update((UFG::UIScreen *)&v3->vfptr, v2);
  `eh vector destructor iterator'(
    &pargs.mValue,
    0x30ui64,
    2,
    (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 149
// RVA: 0x62AA20
bool __fastcall UFG::UIHKScreenSafeCrackingMinigame::handleMessage(UFG::UIHKScreenSafeCrackingMinigame *this, unsigned int msgId, UFG::UIMessage *msg)
{
  UFG::UIHKScreenSafeCrackingMinigame *v3; // rbx
  unsigned int v4; // eax
  bool result; // al
  UFG::qString v6; // [rsp+38h] [rbp-30h]

  v3 = this;
  if ( msgId == UI_HASH_PLAYSOUND_20 )
  {
    UFG::qString::qString(&v6, (UFG::qString *)&msg[1]);
    v4 = UFG::TiDo::CalcWwiseUid(v6.mData);
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr, v4, 0i64, 0, 0i64);
    UFG::qString::~qString(&v6);
    result = 1;
  }
  else if ( msgId == UI_HASH_ENABLECONTROLS_20 )
  {
    this->mbAllowControls = 1;
    result = 1;
  }
  else if ( msgId == UI_HASH_DISABLECONTROLS_20 )
  {
    this->mbAllowControls = 0;
    result = 1;
  }
  else if ( msgId == UI_HASH_BUTTON_BACK_PRESSED_30 )
  {
    this->mFinished = 1;
    result = 1;
  }
  else if ( msgId == UI_HASH_SETWON_20 )
  {
    UFG::GameStatAction::MiniGame::Completed(MGT_SafeCrack);
    UFG::UIHKScreenSafeCrackingMinigame::m_bWon = 1;
    v3->mFinished = 1;
    result = 1;
  }
  else
  {
    result = UFG::UIHKMinigameScreen::handleMessage((UFG::UIHKMinigameScreen *)&this->vfptr, msgId, msg);
  }
  return result;
}

// File Line: 204
// RVA: 0x61EEA0
float __fastcall UFG::UIHKScreenSafeCrackingMinigame::calcLeftStickRotation(UFG::UIHKScreenSafeCrackingMinigame *this)
{
  UFG::InputActionData *v1; // rdx
  UFG::UIHKScreenSafeCrackingMinigame *v2; // rbx
  float v3; // xmm8_4
  __m128 v4; // xmm9
  float v5; // xmm1_4
  __m128 v6; // xmm0
  __m128 v7; // xmm1
  float v8; // xmm2_4
  float v9; // xmm4_4
  float v10; // xmm9_4
  float v11; // xmm8_4
  __m128 v12; // xmm2
  __m128 v13; // xmm1
  float v14; // xmm3_4
  float v15; // xmm0_4
  float v16; // xmm6_4
  float v18; // xmm2_4

  v1 = UFG::ActionDef_UILeftThumbstick.mDataPerController[UFG::gActiveControllerNum];
  v2 = this;
  if ( v1 )
    v3 = v1->mAxisPositionY;
  else
    v3 = 0.0;
  if ( v1 )
    v4 = (__m128)LODWORD(v1->mAxisPositionX);
  else
    v4 = 0i64;
  if ( v1 )
    v5 = v1->mAxisPositionY;
  else
    v5 = 0.0;
  if ( v1 )
    v6 = (__m128)LODWORD(v1->mAxisPositionX);
  else
    v6 = 0i64;
  v6.m128_f32[0] = (float)(v6.m128_f32[0] * v6.m128_f32[0]) + (float)(v5 * v5);
  if ( COERCE_FLOAT(_mm_sqrt_ps(v6)) <= 0.80000001 )
  {
    this->firstOut = 1;
    v18 = UFG::qVector2::msZero.y;
    this->g_previousVector.x = UFG::qVector2::msZero.x;
    this->g_previousVector.y = v18;
  }
  else
  {
    v7 = v4;
    v7.m128_f32[0] = (float)(v4.m128_f32[0] * v4.m128_f32[0]) + (float)(v3 * v3);
    if ( v7.m128_f32[0] == 0.0 )
      v8 = 0.0;
    else
      v8 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v7));
    v9 = this->g_previousVector.y;
    v10 = v4.m128_f32[0] * v8;
    v11 = v3 * v8;
    v12 = (__m128)LODWORD(this->g_previousVector.x);
    v13 = v12;
    v13.m128_f32[0] = (float)(v12.m128_f32[0] * v12.m128_f32[0]) + (float)(v9 * v9);
    if ( v13.m128_f32[0] == 0.0 )
      v14 = 0.0;
    else
      v14 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v13));
    this->g_previousVector.x = v12.m128_f32[0] * v14;
    this->g_previousVector.y = v9 * v14;
    v15 = atan2f(v11, v10);
    v16 = v15 - atan2f(v2->g_previousVector.y, v2->g_previousVector.x);
    if ( v16 >= -3.1415927 )
    {
      if ( v16 > 3.1415927 )
        v16 = v16 + -6.2831855;
    }
    else
    {
      v16 = v16 + 6.2831855;
    }
    v2->g_previousVector.x = v10;
    v2->g_previousVector.y = v11;
    if ( !v2->firstOut )
      return v16 * 57.295776;
    v2->firstOut = 0;
  }
  return 0.0;
}

