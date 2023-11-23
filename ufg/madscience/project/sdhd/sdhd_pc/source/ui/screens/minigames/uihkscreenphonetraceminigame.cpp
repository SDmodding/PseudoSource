// File Line: 44
// RVA: 0x15671D0
__int64 dynamic_initializer_for__UFG::UIHKScreenPhoneTraceMinigame::mNeighborhood__()
{
  UFG::qString::qString(&UFG::UIHKScreenPhoneTraceMinigame::mNeighborhood, "NP");
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::UIHKScreenPhoneTraceMinigame::mNeighborhood__);
}

// File Line: 57
// RVA: 0x5C6B60
void __fastcall UFG::UIHKScreenPhoneTraceMinigame::UIHKScreenPhoneTraceMinigame(
        UFG::UIHKScreenPhoneTraceMinigame *this)
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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenPhoneTraceMinigame::`vftable;
  UFG::UIHKDepthOfFieldWidget::UIHKDepthOfFieldWidget(&this->DOF);
  this->mSavedControllerMode = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_ActiveMapSet;
  UFG::SetInputMode(IM_UI_ONLY, UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->mControllerIndex);
  this->mbAllowControls = 0;
  this->mState = STATE_PRETRACE;
  UFG::UIHKScreenPhoneTraceMinigame::mbWon = 0;
  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(v3, v2) )
  {
    v4 = UFG::qWiseSymbol::create_from_string(&result, "mg_phone_tracing");
    UFG::TiDo::LoadWwiseBank(v4);
    _((AMD_HD3D *)result.mUID);
    this->mbMusicPlay = 0;
  }
}

// File Line: 80
// RVA: 0x5CC090
void __fastcall UFG::UIHKScreenPhoneTraceMinigame::~UIHKScreenPhoneTraceMinigame(
        UFG::UIHKScreenPhoneTraceMinigame *this)
{
  UFG::UIScreenTextureManager *v2; // rax
  hkgpIndexedMeshDefinitions::Edge *v3; // rdx
  hkgpIndexedMesh::EdgeBarrier *v4; // rcx
  UFG::qWiseSymbol *v5; // rax
  UFG::qWiseSymbol result; // [rsp+58h] [rbp+10h] BYREF
  UFG::qWiseSymbol v7; // [rsp+60h] [rbp+18h] BYREF

  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenPhoneTraceMinigame::`vftable;
  v2 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v2, "PhoneTraceMinigame");
  UFG::SetInputMode(
    this->mSavedControllerMode,
    UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->mControllerIndex);
  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(v4, v3) )
  {
    if ( (_S22_2 & 1) == 0 )
    {
      _S22_2 |= 1u;
      Set_State_minigame_mus_end_1.mUID = UFG::qWiseSymbolUIDFromString("Set_State_minigame_mus_end", 0x811C9DC5);
      _((AMD_HD3D *)Set_State_minigame_mus_end_1.mUID);
      atexit(UFG::UIHKScreenPhoneTraceMinigame::_UIHKScreenPhoneTraceMinigame_::_4_::_dynamic_atexit_destructor_for__Set_State_minigame_mus_end__);
    }
    UFG::Music::MusicEvent(Set_State_minigame_mus_end_1.mUID);
    UFG::qWiseSymbol::create_from_string(&result, "Stop_ch_start_hack");
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, result.mUID, 0i64, 0, 0i64);
    v5 = UFG::qWiseSymbol::create_from_string(&v7, "mg_phone_tracing");
    UFG::TiDo::UnloadWwiseBank(v5);
    _((AMD_HD3D *)v7.mUID);
    _((AMD_HD3D *)result.mUID);
  }
  UFG::GameCameraComponent::EndDOFOverride(DOFOverridePriority_0);
  UFG::UIHKMinigameScreen::~UIHKMinigameScreen(this);
}

// File Line: 98
// RVA: 0x6353F0
void __fastcall UFG::UIHKScreenPhoneTraceMinigame::init(
        UFG::UIHKScreenPhoneTraceMinigame *this,
        UFG::UICommandData *data)
{
  Scaleform::GFx::Movie *pObject; // rbx
  char *mData; // rdi
  double v5; // xmm6_8
  double v6; // xmm6_8
  bool m_IsKeyboardController; // di
  Scaleform::GFx::Value pargs; // [rsp+30h] [rbp-C8h] BYREF
  Render::DepthOfField::Focus v9; // [rsp+60h] [rbp-98h] BYREF
  Scaleform::GFx::Value ptr; // [rsp+78h] [rbp-80h] BYREF
  char v11[16]; // [rsp+A8h] [rbp-50h] BYREF
  __int64 v12; // [rsp+B8h] [rbp-40h]
  int v13; // [rsp+C0h] [rbp-38h]
  double v14; // [rsp+C8h] [rbp-30h]
  char v15[16]; // [rsp+D8h] [rbp-20h] BYREF
  __int64 v16; // [rsp+E8h] [rbp-10h]
  int v17; // [rsp+F0h] [rbp-8h]
  double v18; // [rsp+F8h] [rbp+0h]
  __int64 v19; // [rsp+108h] [rbp+10h]

  v19 = -2i64;
  UFG::UIScreen::init(this, data);
  Render::DepthOfField::Focus::Focus(&v9);
  v9.mFocalDistance = FLOAT_N2_0;
  v9.mInFocusRange = FLOAT_10_0;
  v9.mNearBlurRadius = FLOAT_2_0;
  LODWORD(v9.mNearRange) = (_DWORD)FLOAT_1_0;
  *(_QWORD *)&v9.mFarRange = __PAIR64__(LODWORD(FLOAT_20_0), LODWORD(FLOAT_10_0));
  this->DOF.mFocus.mFocalDistance = FLOAT_N2_0;
  this->DOF.mFocus.mInFocusRange = FLOAT_10_0;
  LODWORD(this->DOF.mFocus.mNearRange) = (_DWORD)FLOAT_1_0;
  this->DOF.mFocus.mNearBlurRadius = FLOAT_2_0;
  this->DOF.mFocus.mFarRange = FLOAT_10_0;
  this->DOF.mFocus.mFarBlurRadius = FLOAT_20_0;
  pObject = this->mRenderable->m_movie.pObject;
  `eh vector constructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  mData = UFG::UIHKScreenPhoneTraceMinigame::mNeighborhood.mData;
  if ( (ptr.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
      ptr.pObjectInterface,
      &ptr,
      ptr.mValue);
    ptr.pObjectInterface = 0i64;
  }
  ptr.Type = VT_String;
  ptr.mValue.pString = mData;
  v5 = UFG::UIHKScreenPhoneTraceMinigame::xSolution;
  if ( (v13 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v12 + 16i64))(v12, v11, COERCE_DOUBLE(*(_QWORD *)&v14));
    v12 = 0i64;
  }
  v13 = 5;
  v14 = v5;
  v6 = UFG::UIHKScreenPhoneTraceMinigame::ySolution;
  if ( (v17 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v16 + 16i64))(v16, v15, COERCE_DOUBLE(*(_QWORD *)&v18));
    v16 = 0i64;
  }
  v17 = 5;
  v18 = v6;
  if ( pObject )
  {
    pargs.pObjectInterface = 0i64;
    pargs.Type = VT_Undefined;
    m_IsKeyboardController = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController;
    pargs.Type = VT_Boolean;
    pargs.mValue.BValue = m_IsKeyboardController;
    Scaleform::GFx::Movie::Invoke(pObject, "Show_PCCtrls", 0i64, &pargs, 1u);
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
  `eh vector destructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 129
// RVA: 0x63E930
void __fastcall UFG::UIHKScreenPhoneTraceMinigame::update(UFG::UIHKScreenPhoneTraceMinigame *this, float elapsed)
{
  char v4; // di
  UFG::UIHKScreenPhoneTraceMinigame::eState mState; // eax
  UFG::qWiseSymbol *v6; // rax
  bool v7; // si
  Scaleform::GFx::Movie *v8; // rdi
  bool v9; // r14
  int v10; // r8d
  Scaleform::GFx::Value *p_ptr; // rcx
  UFG::InputActionData *v12; // rcx
  float v13; // xmm0_4
  float mAxisPositionX; // xmm1_4
  UFG::InputActionData *v15; // rcx
  float mAxisPositionY; // xmm1_4
  unsigned int v17; // edx
  UFG::InputActionData *v18; // rax
  float v19; // xmm1_4
  UFG::InputActionData *v20; // rcx
  UFG::InputActionData *v21; // rax
  UFG::InputActionData *v22; // rax
  bool v23; // al
  UFG::InputActionData *v24; // rcx
  bool v25; // al
  Scaleform::GFx::Value::ValueUnion v26; // xmm6_8
  double mfLeftStickY; // xmm6_8
  bool mbAButton; // di
  bool mbXButton; // di
  Scaleform::GFx::Movie *pObject; // rdi
  bool m_IsKeyboardController; // r14
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-B0h] BYREF
  int ptr; // [rsp+68h] [rbp-80h] BYREF
  double v34; // [rsp+70h] [rbp-78h]
  __int64 v35; // [rsp+78h] [rbp-70h]
  Scaleform::GFx::Value v36; // [rsp+88h] [rbp-60h] BYREF
  char v37[16]; // [rsp+B8h] [rbp-30h] BYREF
  __int64 v38; // [rsp+C8h] [rbp-20h]
  int v39; // [rsp+D0h] [rbp-18h]
  double v40; // [rsp+D8h] [rbp-10h]
  char v41[16]; // [rsp+E8h] [rbp+0h] BYREF
  __int64 v42; // [rsp+F8h] [rbp+10h]
  int v43; // [rsp+100h] [rbp+18h]
  __int64 v44; // [rsp+108h] [rbp+20h]
  int v45[4]; // [rsp+118h] [rbp+30h] BYREF
  __int64 v46; // [rsp+128h] [rbp+40h]
  int v47; // [rsp+130h] [rbp+48h]
  __int64 v48; // [rsp+138h] [rbp+50h]
  char v49[8]; // [rsp+148h] [rbp+60h] BYREF
  __int64 v50; // [rsp+158h] [rbp+70h]
  int v51; // [rsp+160h] [rbp+78h]
  double v52; // [rsp+168h] [rbp+80h]
  __int64 v53; // [rsp+178h] [rbp+90h]
  void *retaddr; // [rsp+1D8h] [rbp+F0h] BYREF

  v53 = -2i64;
  v4 = 0;
  if ( !UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "NISPause") )
  {
    mState = this->mState;
    if ( mState )
    {
      if ( mState != STATE_TRACE )
      {
LABEL_63:
        UFG::UIScreen::update(this, elapsed);
        return;
      }
      v12 = UFG::ActionDef_UILeftThumbstick.mDataPerController[UFG::gActiveControllerNum];
      v13 = 0.0;
      if ( v12 )
        mAxisPositionX = v12->mAxisPositionX;
      else
        mAxisPositionX = 0.0;
      this->mfLeftStickX = mAxisPositionX;
      v15 = UFG::ActionDef_UILeftThumbstick.mDataPerController[UFG::gActiveControllerNum];
      if ( v15 )
        mAxisPositionY = v15->mAxisPositionY;
      else
        mAxisPositionY = 0.0;
      this->mfLeftStickY = mAxisPositionY;
      v17 = UFG::gActiveControllerNum;
      if ( UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
      {
        v18 = UFG::ActionDef_Mouse.mDataPerController[UFG::gActiveControllerNum];
        if ( v18 )
          v19 = v18->mAxisPositionX;
        else
          v19 = 0.0;
        this->mfLeftStickX = v19 * UFG::gMouseExplorationMultiplier;
        v20 = UFG::ActionDef_Mouse.mDataPerController[UFG::gActiveControllerNum];
        if ( v20 )
          v13 = v20->mAxisPositionY;
        this->mfLeftStickY = v13 * UFG::gMouseExplorationMultiplier;
        v17 = UFG::gActiveControllerNum;
      }
      v21 = UFG::ActionDef_UIAcceptPressed.mDataPerController[v17];
      v23 = 1;
      if ( !v21 || !v21->mActionTrue )
      {
        v22 = UFG::ActionDef_UIMouseAccept.mDataPerController[v17];
        if ( !v22 || !v22->mActionTrue )
          v23 = 0;
      }
      this->mbAButton = v23;
      v24 = UFG::ActionDef_UIButton1Pressed.mDataPerController[UFG::gActiveControllerNum];
      if ( !v24 || (v25 = 1, !v24->mActionTrue) )
        v25 = 0;
      this->mbXButton = v25;
      `eh vector constructor iterator(&v36, 0x30ui64, 5, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      v26.NValue = this->mfLeftStickX;
      if ( (v36.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&v36.pObjectInterface->vfptr->gap8[8])(
          v36.pObjectInterface,
          &v36,
          v36.mValue);
        v36.pObjectInterface = 0i64;
      }
      v36.Type = VT_Number;
      v36.mValue = v26;
      mfLeftStickY = this->mfLeftStickY;
      if ( (v39 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v38 + 16i64))(
          v38,
          v37,
          COERCE_DOUBLE(*(_QWORD *)&v40));
        v38 = 0i64;
      }
      v39 = 5;
      v40 = mfLeftStickY;
      mbAButton = this->mbAButton;
      if ( (v43 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v42 + 16i64))(v42, v41, v44);
        v42 = 0i64;
      }
      v43 = 2;
      LOBYTE(v44) = mbAButton;
      mbXButton = this->mbXButton;
      if ( (v47 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, int *, __int64))(*(_QWORD *)v46 + 16i64))(v46, v45, v48);
        v46 = 0i64;
      }
      v47 = 2;
      LOBYTE(v48) = mbXButton;
      if ( (v51 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v50 + 16i64))(
          v50,
          v49,
          COERCE_DOUBLE(*(_QWORD *)&v52));
        v50 = 0i64;
      }
      v51 = 5;
      v52 = elapsed;
      pObject = this->mRenderable->m_movie.pObject;
      if ( pObject && this->mProgressionState != EXIT_BOX )
      {
        pargs.pObjectInterface = 0i64;
        pargs.Type = VT_Undefined;
        m_IsKeyboardController = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController;
        pargs.Type = VT_Boolean;
        pargs.mValue.BValue = m_IsKeyboardController;
        Scaleform::GFx::Movie::Invoke(pObject, "Show_PCCtrls", 0i64, &pargs, 1u);
        Scaleform::GFx::Movie::Invoke(pObject, "phoneTraceMainLoop", 0i64, &v36, 5u);
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
      v10 = 5;
      p_ptr = &v36;
    }
    else
    {
      v7 = 0;
      if ( !this->mbMusicPlay )
      {
        v6 = UFG::qWiseSymbol::create_from_string((UFG::qWiseSymbol *)&retaddr, "mg_phone_tracing");
        v4 = 1;
        if ( UFG::TiDo::BankLoaded(v6->mUID) )
          v7 = 1;
      }
      if ( (v4 & 1) != 0 )
        _((AMD_HD3D *)(unsigned int)retaddr);
      if ( v7 )
      {
        if ( (_S23_2 & 1) == 0 )
        {
          _S23_2 |= 1u;
          Set_State_minigame_mus_start_1.mUID = UFG::qWiseSymbolUIDFromString(
                                                  "Set_State_minigame_mus_start",
                                                  0x811C9DC5);
          _((AMD_HD3D *)Set_State_minigame_mus_start_1.mUID);
          atexit(UFG::UIHKScreenPhoneTraceMinigame::update_::_11_::_dynamic_atexit_destructor_for__Set_State_minigame_mus_start__);
        }
        UFG::Music::MusicEvent(Set_State_minigame_mus_start_1.mUID);
        UFG::qWiseSymbol::create_from_string((UFG::qWiseSymbol *)&retaddr, "Play_ch_start_hack");
        if ( UFG::HudAudio::m_instance )
          UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, (unsigned int)retaddr, 0i64, 0, 0i64);
        this->mbMusicPlay = 1;
        _((AMD_HD3D *)(unsigned int)retaddr);
      }
      v8 = this->mRenderable->m_movie.pObject;
      `eh vector constructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      if ( (ptr & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, int *, double))(*(_QWORD *)v35 + 16i64))(
          v35,
          &ptr,
          COERCE_DOUBLE(*(_QWORD *)&v34));
        v35 = 0i64;
      }
      ptr = 5;
      v34 = elapsed;
      if ( v8 && this->mProgressionState != EXIT_BOX )
      {
        pargs.pObjectInterface = 0i64;
        pargs.Type = VT_Undefined;
        v9 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController;
        pargs.Type = VT_Boolean;
        pargs.mValue.BValue = v9;
        Scaleform::GFx::Movie::Invoke(v8, "Show_PCCtrls", 0i64, &pargs, 1u);
        Scaleform::GFx::Movie::Invoke(v8, "preTraceMainLoop", 0i64, (Scaleform::GFx::Value *)&ptr, 1u);
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
      v10 = 1;
      p_ptr = (Scaleform::GFx::Value *)&ptr;
    }
    `eh vector destructor iterator(p_ptr, 0x30ui64, v10, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    goto LABEL_63;
  }
}

// File Line: 202
// RVA: 0x629360
bool __fastcall UFG::UIHKScreenPhoneTraceMinigame::handleMessage(
        UFG::UIHKScreenPhoneTraceMinigame *this,
        unsigned int msgId,
        UFG::UIMessage *msg)
{
  UFG::UIHKScreenPhoneTraceMinigame::eState mState; // eax
  Scaleform::GFx::Movie *pObject; // rsi
  Scaleform::GFx::Movie *v8; // rsi
  Scaleform::GFx::Movie *v9; // rbx
  int v10; // edx
  hkGeometryUtils::IVertices *v11; // rcx
  int v12; // r8d
  unsigned int v13; // eax
  Scaleform::GFx::Movie *v14; // rbx
  int v15; // edx
  hkGeometryUtils::IVertices *v16; // rcx
  int v17; // r8d
  unsigned int v18; // eax
  unsigned int v20; // eax
  Scaleform::GFx::Value ptr; // [rsp+38h] [rbp-38h] BYREF

  if ( msgId == UI_HASH_BUTTON_BACK_PRESSED_30 && this->mbAllowControls )
    UFG::UIHKMinigameScreen::handleExiting(this);
  mState = this->mState;
  if ( mState )
  {
    if ( mState == STATE_TRACE )
    {
      if ( msgId == UI_HASH_SETWON_20 )
      {
        UFG::UIHKScreenPhoneTraceMinigame::mbWon = 1;
        return 1;
      }
      if ( msgId == UI_HASH_SETFINISHED_20 )
      {
        UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, 0xFFFFFFFF);
        if ( UFG::UIHKScreenPhoneTraceMinigame::mbWon )
          UFG::GameStatAction::MiniGame::Completed(MGT_PhoneTrace);
      }
    }
    goto LABEL_45;
  }
  if ( msgId == UI_HASH_BUTTON_ACCEPT_PRESSED_30 )
  {
    pObject = this->mRenderable->m_movie.pObject;
    `eh vector constructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( (ptr.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
        ptr.pObjectInterface,
        &ptr,
        ptr.mValue);
      ptr.pObjectInterface = 0i64;
    }
    ptr.Type = VT_Boolean;
    ptr.mValue.BValue = 1;
    if ( pObject )
      Scaleform::GFx::Movie::Invoke(pObject, "scanningNeighborhood", 0i64, &ptr, 1u);
LABEL_16:
    `eh vector destructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    goto LABEL_17;
  }
  if ( msgId == UI_HASH_BUTTON_ACCEPT_RELEASED_30 )
  {
    v8 = this->mRenderable->m_movie.pObject;
    `eh vector constructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( (ptr.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
        ptr.pObjectInterface,
        &ptr,
        ptr.mValue);
      ptr.pObjectInterface = 0i64;
    }
    ptr.Type = VT_Boolean;
    ptr.mValue.BValue = 0;
    if ( v8 )
      Scaleform::GFx::Movie::Invoke(v8, "scanningNeighborhood", 0i64, &ptr, 1u);
    goto LABEL_16;
  }
LABEL_17:
  if ( this->mbAllowControls )
  {
    if ( msgId == UI_HASH_THUMBSTICK_LEFT_UP_30 || msgId == UI_HASH_DPAD_UP_PRESSED_30 )
    {
      v14 = this->mRenderable->m_movie.pObject;
      if ( v14 )
      {
        `eh vector constructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
        if ( (ptr.Type & 0x40) != 0 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
            ptr.pObjectInterface,
            &ptr,
            ptr.mValue);
          ptr.pObjectInterface = 0i64;
        }
        ptr.Type = VT_Number;
        ptr.mValue.NValue = DOUBLE_N1_0;
        Scaleform::GFx::Movie::Invoke(v14, "moveSelector", 0i64, &ptr, 1u);
        if ( Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(v16, v15, v17) )
        {
          v18 = UFG::TiDo::CalcWwiseUid("Play_ch_nav");
          if ( UFG::HudAudio::m_instance )
            UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, v18, 0i64, 0, 0i64);
        }
        goto LABEL_35;
      }
      return 1;
    }
    if ( msgId == UI_HASH_THUMBSTICK_LEFT_DOWN_30 || msgId == UI_HASH_DPAD_DOWN_PRESSED_30 )
    {
      v9 = this->mRenderable->m_movie.pObject;
      if ( v9 )
      {
        `eh vector constructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
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
        Scaleform::GFx::Movie::Invoke(v9, "moveSelector", 0i64, &ptr, 1u);
        if ( Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(v11, v10, v12) )
        {
          v13 = UFG::TiDo::CalcWwiseUid("Play_ch_nav");
          if ( UFG::HudAudio::m_instance )
            UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, v13, 0i64, 0, 0i64);
        }
LABEL_35:
        `eh vector destructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
        return 1;
      }
      return 1;
    }
  }
  if ( msgId == UI_HASH_SETWON_20 )
  {
    this->mState = STATE_TRACE;
    return 1;
  }
LABEL_45:
  if ( msgId == UI_HASH_PLAYSOUND_20 )
  {
    UFG::qString::qString((UFG::qString *)&ptr, (UFG::qString *)&msg[1]);
    v20 = UFG::TiDo::CalcWwiseUid(*(const char **)&ptr.Type);
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, v20, 0i64, 0, 0i64);
    UFG::qString::~qString((UFG::qString *)&ptr);
    return 1;
  }
  if ( msgId == UI_HASH_SETFAILED_20 )
  {
    UFG::UIHKScreenPhoneTraceMinigame::mbWon = 0;
    UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, 0xFFFFFFFF);
    return 1;
  }
  if ( msgId == UI_HASH_ENABLECONTROLS_20 )
  {
    this->mbAllowControls = 1;
  }
  else if ( msgId == UI_HASH_DISABLECONTROLS_20 )
  {
    this->mbAllowControls = 0;
  }
  return UFG::UIHKMinigameScreen::handleMessage(this, msgId, msg);
}

// File Line: 335
// RVA: 0x620220
void __fastcall UFG::UIHKScreenPhoneTraceMinigame::fail(UFG::UIHKScreenPhoneTraceMinigame *this)
{
  Scaleform::GFx::Movie *pObject; // rcx

  if ( this->mProgressionState == EXIT_BOX )
    UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, 0xFFFFFFFF);
  pObject = this->mRenderable->m_movie.pObject;
  if ( pObject )
    Scaleform::GFx::Movie::Invoke(pObject, "external_fail", 0i64, 0i64, 0);
}

