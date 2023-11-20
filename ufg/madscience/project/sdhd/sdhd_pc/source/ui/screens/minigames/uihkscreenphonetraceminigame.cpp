// File Line: 44
// RVA: 0x15671D0
__int64 dynamic_initializer_for__UFG::UIHKScreenPhoneTraceMinigame::mNeighborhood__()
{
  UFG::qString::qString(&UFG::UIHKScreenPhoneTraceMinigame::mNeighborhood, "NP");
  return atexit(dynamic_atexit_destructor_for__UFG::UIHKScreenPhoneTraceMinigame::mNeighborhood__);
}

// File Line: 57
// RVA: 0x5C6B60
void __fastcall UFG::UIHKScreenPhoneTraceMinigame::UIHKScreenPhoneTraceMinigame(UFG::UIHKScreenPhoneTraceMinigame *this)
{
  UFG::UIHKScreenPhoneTraceMinigame *v1; // rbx
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
  --this->mInputEnabled;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKTaskableScreen::`vftable;
  this->mFinished = 0;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKMinigameScreen::`vftable;
  *(_QWORD *)&this->mfAlphaValue = 1109393408i64;
  ++UFG::UIHKMinigameScreen::mNumMinigameScreens;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenPhoneTraceMinigame::`vftable;
  UFG::UIHKDepthOfFieldWidget::UIHKDepthOfFieldWidget(&this->DOF);
  v1->mSavedControllerMode = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_ActiveMapSet;
  UFG::SetInputMode(IM_UI_ONLY, UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->mControllerIndex);
  v1->mbAllowControls = 0;
  v1->mState = 0;
  UFG::UIHKScreenPhoneTraceMinigame::mbWon = 0;
  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(v4, v3) )
  {
    v5 = UFG::qWiseSymbol::create_from_string(&result, "mg_phone_tracing");
    UFG::TiDo::LoadWwiseBank(v5);
    _((AMD_HD3D *)result.mUID);
    v1->mbMusicPlay = 0;
  }
}

// File Line: 80
// RVA: 0x5CC090
void __fastcall UFG::UIHKScreenPhoneTraceMinigame::~UIHKScreenPhoneTraceMinigame(UFG::UIHKScreenPhoneTraceMinigame *this)
{
  UFG::UIHKScreenPhoneTraceMinigame *v1; // rbx
  UFG::UIScreenTextureManager *v2; // rax
  hkgpIndexedMeshDefinitions::Edge *v3; // rdx
  hkgpIndexedMesh::EdgeBarrier *v4; // rcx
  UFG::qWiseSymbol *v5; // rax
  UFG::qWiseSymbol result; // [rsp+58h] [rbp+10h]
  UFG::qWiseSymbol v7; // [rsp+60h] [rbp+18h]

  v1 = this;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenPhoneTraceMinigame::`vftable;
  v2 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v2, "PhoneTraceMinigame");
  UFG::SetInputMode(
    v1->mSavedControllerMode,
    UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->mControllerIndex);
  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(v4, v3) )
  {
    if ( !(_S22_2 & 1) )
    {
      _S22_2 |= 1u;
      Set_State_minigame_mus_end_1.mUID = UFG::qWiseSymbolUIDFromString("Set_State_minigame_mus_end", 0x811C9DC5);
      _((AMD_HD3D *)Set_State_minigame_mus_end_1.mUID);
      atexit(UFG::UIHKScreenPhoneTraceMinigame::_UIHKScreenPhoneTraceMinigame_::_4_::_dynamic_atexit_destructor_for__Set_State_minigame_mus_end__);
    }
    UFG::Music::MusicEvent(Set_State_minigame_mus_end_1.mUID);
    UFG::qWiseSymbol::create_from_string(&result, "Stop_ch_start_hack");
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        result.mUID,
        0i64,
        0,
        0i64);
    v5 = UFG::qWiseSymbol::create_from_string(&v7, "mg_phone_tracing");
    UFG::TiDo::UnloadWwiseBank(v5);
    _((AMD_HD3D *)v7.mUID);
    _((AMD_HD3D *)result.mUID);
  }
  UFG::GameCameraComponent::EndDOFOverride(0);
  UFG::UIHKMinigameScreen::~UIHKMinigameScreen((UFG::UIHKMinigameScreen *)&v1->vfptr);
}

// File Line: 98
// RVA: 0x6353F0
void __fastcall UFG::UIHKScreenPhoneTraceMinigame::init(UFG::UIHKScreenPhoneTraceMinigame *this, UFG::UICommandData *data)
{
  UFG::UIHKScreenPhoneTraceMinigame *v2; // rbx
  Scaleform::GFx::Movie *v3; // rbx
  char *v4; // rdi
  double v5; // xmm6_8
  double v6; // xmm6_8
  bool v7; // di
  Scaleform::GFx::Value pargs; // [rsp+30h] [rbp-C8h]
  Render::DepthOfField::Focus v9; // [rsp+60h] [rbp-98h]
  char ptr; // [rsp+78h] [rbp-80h]
  __int64 v11; // [rsp+88h] [rbp-70h]
  unsigned int v12; // [rsp+90h] [rbp-68h]
  char *v13; // [rsp+98h] [rbp-60h]
  char v14; // [rsp+A8h] [rbp-50h]
  __int64 v15; // [rsp+B8h] [rbp-40h]
  unsigned int v16; // [rsp+C0h] [rbp-38h]
  double v17; // [rsp+C8h] [rbp-30h]
  char v18; // [rsp+D8h] [rbp-20h]
  __int64 v19; // [rsp+E8h] [rbp-10h]
  unsigned int v20; // [rsp+F0h] [rbp-8h]
  double v21; // [rsp+F8h] [rbp+0h]
  __int64 v22; // [rsp+108h] [rbp+10h]

  v22 = -2i64;
  v2 = this;
  UFG::UIScreen::init((UFG::UIScreen *)&this->vfptr, data);
  Render::DepthOfField::Focus::Focus(&v9);
  v9.mFocalDistance = FLOAT_N2_0;
  v9.mInFocusRange = FLOAT_10_0;
  v9.mNearBlurRadius = FLOAT_2_0;
  LODWORD(v9.mNearRange) = (_DWORD)FLOAT_1_0;
  *(_QWORD *)&v9.mFarRange = __PAIR__(LODWORD(FLOAT_20_0), LODWORD(FLOAT_10_0));
  v2->DOF.mFocus.mFocalDistance = FLOAT_N2_0;
  v2->DOF.mFocus.mInFocusRange = FLOAT_10_0;
  LODWORD(v2->DOF.mFocus.mNearRange) = (_DWORD)FLOAT_1_0;
  v2->DOF.mFocus.mNearBlurRadius = FLOAT_2_0;
  v2->DOF.mFocus.mFarRange = FLOAT_10_0;
  v2->DOF.mFocus.mFarBlurRadius = FLOAT_20_0;
  v3 = v2->mRenderable->m_movie.pObject;
  `eh vector constructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  v4 = UFG::UIHKScreenPhoneTraceMinigame::mNeighborhood.mData;
  if ( (v12 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v11 + 16i64))(v11, &ptr, v13);
    v11 = 0i64;
  }
  v12 = 6;
  v13 = v4;
  v5 = UFG::UIHKScreenPhoneTraceMinigame::xSolution;
  if ( (v16 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v15 + 16i64))(
      v15,
      &v14,
      COERCE_DOUBLE(*(_QWORD *)&v17));
    v15 = 0i64;
  }
  v16 = 5;
  v17 = v5;
  v6 = UFG::UIHKScreenPhoneTraceMinigame::ySolution;
  if ( (v20 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v19 + 16i64))(
      v19,
      &v18,
      COERCE_DOUBLE(*(_QWORD *)&v21));
    v19 = 0i64;
  }
  v20 = 5;
  v21 = v6;
  if ( v3 )
  {
    pargs.pObjectInterface = 0i64;
    pargs.Type = 0;
    v7 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController;
    pargs.Type = 2;
    pargs.mValue.BValue = v7;
    Scaleform::GFx::Movie::Invoke(v3, "Show_PCCtrls", 0i64, &pargs, 1u);
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
  `eh vector destructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 129
// RVA: 0x63E930
void __fastcall UFG::UIHKScreenPhoneTraceMinigame::update(UFG::UIHKScreenPhoneTraceMinigame *this, float elapsed)
{
  float v2; // xmm7_4
  UFG::UIHKScreenPhoneTraceMinigame *v3; // rbx
  char v4; // di
  UFG::UIHKScreenPhoneTraceMinigame::eState v5; // eax
  UFG::qWiseSymbol *v6; // rax
  bool v7; // si
  Scaleform::GFx::Movie *v8; // rdi
  bool v9; // r14
  int v10; // er8
  Scaleform::GFx::Value *v11; // rcx
  UFG::InputActionData *v12; // rcx
  float v13; // xmm0_4
  float v14; // xmm1_4
  UFG::InputActionData *v15; // rcx
  float v16; // xmm1_4
  unsigned int v17; // edx
  UFG::InputActionData *v18; // rax
  float v19; // xmm1_4
  UFG::InputActionData *v20; // rcx
  UFG::InputActionData *v21; // rax
  UFG::InputActionData *v22; // rax
  bool v23; // al
  UFG::InputActionData *v24; // rcx
  char v25; // al
  double v26; // xmm6_8
  double v27; // xmm6_8
  bool v28; // di
  bool v29; // di
  Scaleform::GFx::Movie *v30; // rdi
  bool v31; // r14
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-B0h]
  unsigned int ptr; // [rsp+68h] [rbp-80h]
  double v34; // [rsp+70h] [rbp-78h]
  __int64 v35; // [rsp+78h] [rbp-70h]
  Scaleform::GFx::Value v36; // [rsp+88h] [rbp-60h]
  char v37; // [rsp+B8h] [rbp-30h]
  __int64 v38; // [rsp+C8h] [rbp-20h]
  unsigned int v39; // [rsp+D0h] [rbp-18h]
  double v40; // [rsp+D8h] [rbp-10h]
  char v41; // [rsp+E8h] [rbp+0h]
  __int64 v42; // [rsp+F8h] [rbp+10h]
  unsigned int v43; // [rsp+100h] [rbp+18h]
  __int64 v44; // [rsp+108h] [rbp+20h]
  int v45; // [rsp+118h] [rbp+30h]
  __int64 v46; // [rsp+128h] [rbp+40h]
  unsigned int v47; // [rsp+130h] [rbp+48h]
  __int64 v48; // [rsp+138h] [rbp+50h]
  char v49; // [rsp+148h] [rbp+60h]
  __int64 v50; // [rsp+158h] [rbp+70h]
  unsigned int v51; // [rsp+160h] [rbp+78h]
  double v52; // [rsp+168h] [rbp+80h]
  __int64 v53; // [rsp+178h] [rbp+90h]
  void *retaddr; // [rsp+1D8h] [rbp+F0h]

  v53 = -2i64;
  v2 = elapsed;
  v3 = this;
  v4 = 0;
  if ( !UFG::UIScreenManagerBase::getScreen(
          (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
          "NISPause") )
  {
    v5 = v3->mState;
    if ( v5 )
    {
      if ( v5 != 1 )
      {
LABEL_67:
        UFG::UIScreen::update((UFG::UIScreen *)&v3->vfptr, v2);
        return;
      }
      v12 = UFG::ActionDef_UILeftThumbstick.mDataPerController[UFG::gActiveControllerNum];
      v13 = 0.0;
      if ( v12 )
        v14 = v12->mAxisPositionX;
      else
        v14 = 0.0;
      v3->mfLeftStickX = v14;
      v15 = UFG::ActionDef_UILeftThumbstick.mDataPerController[UFG::gActiveControllerNum];
      if ( v15 )
        v16 = v15->mAxisPositionY;
      else
        v16 = 0.0;
      v3->mfLeftStickY = v16;
      v17 = UFG::gActiveControllerNum;
      if ( UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
      {
        v18 = UFG::ActionDef_Mouse.mDataPerController[UFG::gActiveControllerNum];
        if ( v18 )
          v19 = v18->mAxisPositionX;
        else
          v19 = 0.0;
        v3->mfLeftStickX = v19 * UFG::gMouseExplorationMultiplier;
        v20 = UFG::ActionDef_Mouse.mDataPerController[UFG::gActiveControllerNum];
        if ( v20 )
          v13 = v20->mAxisPositionY;
        v3->mfLeftStickY = v13 * UFG::gMouseExplorationMultiplier;
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
      v3->mbAButton = v23;
      v24 = UFG::ActionDef_UIButton1Pressed.mDataPerController[UFG::gActiveControllerNum];
      if ( !v24 || (v25 = 1, !v24->mActionTrue) )
        v25 = 0;
      v3->mbXButton = v25;
      `eh vector constructor iterator(&v36, 0x30ui64, 5, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      v26 = v3->mfLeftStickX;
      if ( ((unsigned int)v36.Type >> 6) & 1 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&v36.pObjectInterface->vfptr->gap8[8])(
          v36.pObjectInterface,
          &v36,
          *(_QWORD *)&v36.mValue.NValue);
        v36.pObjectInterface = 0i64;
      }
      v36.Type = 5;
      v36.mValue.NValue = v26;
      v27 = v3->mfLeftStickY;
      if ( (v39 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v38 + 16i64))(
          v38,
          &v37,
          COERCE_DOUBLE(*(_QWORD *)&v40));
        v38 = 0i64;
      }
      v39 = 5;
      v40 = v27;
      v28 = v3->mbAButton;
      if ( (v43 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v42 + 16i64))(v42, &v41, v44);
        v42 = 0i64;
      }
      v43 = 2;
      LOBYTE(v44) = v28;
      v29 = v3->mbXButton;
      if ( (v47 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, int *, __int64))(*(_QWORD *)v46 + 16i64))(v46, &v45, v48);
        v46 = 0i64;
      }
      v47 = 2;
      LOBYTE(v48) = v29;
      if ( (v51 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v50 + 16i64))(
          v50,
          &v49,
          COERCE_DOUBLE(*(_QWORD *)&v52));
        v50 = 0i64;
      }
      v51 = 5;
      v52 = v2;
      v30 = v3->mRenderable->m_movie.pObject;
      if ( v30 && v3->mProgressionState != 1 )
      {
        pargs.pObjectInterface = 0i64;
        pargs.Type = 0;
        v31 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController;
        pargs.Type = 2;
        pargs.mValue.BValue = v31;
        Scaleform::GFx::Movie::Invoke(v30, "Show_PCCtrls", 0i64, &pargs, 1u);
        Scaleform::GFx::Movie::Invoke(v30, "phoneTraceMainLoop", 0i64, &v36, 5u);
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
      v10 = 5;
      v11 = &v36;
    }
    else
    {
      v7 = 0;
      if ( !v3->mbMusicPlay )
      {
        v6 = UFG::qWiseSymbol::create_from_string((UFG::qWiseSymbol *)&retaddr, "mg_phone_tracing");
        v4 = 1;
        if ( (unsigned __int8)UFG::TiDo::BankLoaded(v6->mUID) )
          v7 = 1;
      }
      if ( v4 & 1 )
        _((AMD_HD3D *)(unsigned int)retaddr);
      if ( v7 )
      {
        if ( !(_S23_2 & 1) )
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
          UFG::AudioEntity::CreateAndPlayEvent(
            (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
            (unsigned int)retaddr,
            0i64,
            0,
            0i64);
        v3->mbMusicPlay = 1;
        _((AMD_HD3D *)(unsigned int)retaddr);
      }
      v8 = v3->mRenderable->m_movie.pObject;
      `eh vector constructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      if ( (ptr >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, unsigned int *, double))(*(_QWORD *)v35 + 16i64))(
          v35,
          &ptr,
          COERCE_DOUBLE(*(_QWORD *)&v34));
        v35 = 0i64;
      }
      ptr = 5;
      v34 = elapsed;
      if ( v8 && v3->mProgressionState != 1 )
      {
        pargs.pObjectInterface = 0i64;
        pargs.Type = 0;
        v9 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController;
        pargs.Type = 2;
        pargs.mValue.BValue = v9;
        Scaleform::GFx::Movie::Invoke(v8, "Show_PCCtrls", 0i64, &pargs, 1u);
        Scaleform::GFx::Movie::Invoke(v8, "preTraceMainLoop", 0i64, (Scaleform::GFx::Value *)&ptr, 1u);
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
      v10 = 1;
      v11 = (Scaleform::GFx::Value *)&ptr;
    }
    `eh vector destructor iterator(v11, 0x30ui64, v10, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    goto LABEL_67;
  }
}

// File Line: 202
// RVA: 0x629360
bool __fastcall UFG::UIHKScreenPhoneTraceMinigame::handleMessage(UFG::UIHKScreenPhoneTraceMinigame *this, unsigned int msgId, UFG::UIMessage *msg)
{
  UFG::UIMessage *v3; // r14
  unsigned int v4; // ebx
  UFG::UIHKScreenPhoneTraceMinigame *v5; // rdi
  UFG::UIHKScreenPhoneTraceMinigame::eState v6; // eax
  Scaleform::GFx::Movie *v7; // rsi
  Scaleform::GFx::Movie *v8; // rsi
  Scaleform::GFx::Movie *v9; // rbx
  int v10; // edx
  hkGeometryUtils::IVertices *v11; // rcx
  int v12; // er8
  unsigned int v13; // eax
  Scaleform::GFx::Movie *v14; // rbx
  int v15; // edx
  hkGeometryUtils::IVertices *v16; // rcx
  int v17; // er8
  unsigned int v18; // eax
  unsigned int v20; // eax
  char ptr; // [rsp+38h] [rbp-38h]
  __int64 v22; // [rsp+48h] [rbp-28h]
  char *name; // [rsp+50h] [rbp-20h]
  long double v24; // [rsp+58h] [rbp-18h]

  v3 = msg;
  v4 = msgId;
  v5 = this;
  if ( msgId == UI_HASH_BUTTON_BACK_PRESSED_30 && this->mbAllowControls )
    UFG::UIHKMinigameScreen::handleExiting((UFG::UIHKMinigameScreen *)&this->vfptr);
  v6 = v5->mState;
  if ( v6 )
  {
    if ( v6 == 1 )
    {
      if ( v4 == UI_HASH_SETWON_20 )
      {
        UFG::UIHKScreenPhoneTraceMinigame::mbWon = 1;
        return 1;
      }
      if ( v4 == UI_HASH_SETFINISHED_20 )
      {
        UFG::UIScreenManagerBase::queuePopScreen(
          (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
          0xFFFFFFFF);
        if ( UFG::UIHKScreenPhoneTraceMinigame::mbWon )
          UFG::GameStatAction::MiniGame::Completed(MGT_PhoneTrace);
      }
    }
    goto LABEL_45;
  }
  if ( v4 == UI_HASH_BUTTON_ACCEPT_PRESSED_30 )
  {
    v7 = v5->mRenderable->m_movie.pObject;
    `eh vector constructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( ((unsigned int)name >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, long double))(*(_QWORD *)v22 + 16i64))(
        v22,
        &ptr,
        COERCE_LONG_DOUBLE(*(_QWORD *)&v24));
      v22 = 0i64;
    }
    LODWORD(name) = 2;
    LOBYTE(v24) = 1;
    if ( v7 )
      Scaleform::GFx::Movie::Invoke(v7, "scanningNeighborhood", 0i64, (Scaleform::GFx::Value *)&ptr, 1u);
LABEL_16:
    `eh vector destructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    goto LABEL_17;
  }
  if ( v4 == UI_HASH_BUTTON_ACCEPT_RELEASED_30 )
  {
    v8 = v5->mRenderable->m_movie.pObject;
    `eh vector constructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( ((unsigned int)name >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, long double))(*(_QWORD *)v22 + 16i64))(
        v22,
        &ptr,
        COERCE_LONG_DOUBLE(*(_QWORD *)&v24));
      v22 = 0i64;
    }
    LODWORD(name) = 2;
    LOBYTE(v24) = 0;
    if ( v8 )
      Scaleform::GFx::Movie::Invoke(v8, "scanningNeighborhood", 0i64, (Scaleform::GFx::Value *)&ptr, 1u);
    goto LABEL_16;
  }
LABEL_17:
  if ( v5->mbAllowControls )
  {
    if ( v4 == UI_HASH_THUMBSTICK_LEFT_UP_30 || v4 == UI_HASH_DPAD_UP_PRESSED_30 )
    {
      v14 = v5->mRenderable->m_movie.pObject;
      if ( v14 )
      {
        `eh vector constructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
        if ( ((unsigned int)name >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, char *, long double))(*(_QWORD *)v22 + 16i64))(
            v22,
            &ptr,
            COERCE_LONG_DOUBLE(*(_QWORD *)&v24));
          v22 = 0i64;
        }
        LODWORD(name) = 5;
        v24 = DOUBLE_N1_0;
        Scaleform::GFx::Movie::Invoke(v14, "moveSelector", 0i64, (Scaleform::GFx::Value *)&ptr, 1u);
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
        goto LABEL_35;
      }
      return 1;
    }
    if ( v4 == UI_HASH_THUMBSTICK_LEFT_DOWN_30 || v4 == UI_HASH_DPAD_DOWN_PRESSED_30 )
    {
      v9 = v5->mRenderable->m_movie.pObject;
      if ( v9 )
      {
        `eh vector constructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
        if ( ((unsigned int)name >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, char *, long double))(*(_QWORD *)v22 + 16i64))(
            v22,
            &ptr,
            COERCE_LONG_DOUBLE(*(_QWORD *)&v24));
          v22 = 0i64;
        }
        LODWORD(name) = 5;
        v24 = DOUBLE_1_0;
        Scaleform::GFx::Movie::Invoke(v9, "moveSelector", 0i64, (Scaleform::GFx::Value *)&ptr, 1u);
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
LABEL_35:
        `eh vector destructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
        return 1;
      }
      return 1;
    }
  }
  if ( v4 == UI_HASH_SETWON_20 )
  {
    v5->mState = 1;
    return 1;
  }
LABEL_45:
  if ( v4 == UI_HASH_PLAYSOUND_20 )
  {
    UFG::qString::qString((UFG::qString *)&ptr, (UFG::qString *)&v3[1]);
    v20 = UFG::TiDo::CalcWwiseUid(name);
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr, v20, 0i64, 0, 0i64);
    UFG::qString::~qString((UFG::qString *)&ptr);
    return 1;
  }
  if ( v4 == UI_HASH_SETFAILED_20 )
  {
    UFG::UIHKScreenPhoneTraceMinigame::mbWon = 0;
    UFG::UIScreenManagerBase::queuePopScreen(
      (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
      0xFFFFFFFF);
    return 1;
  }
  if ( v4 == UI_HASH_ENABLECONTROLS_20 )
  {
    v5->mbAllowControls = 1;
  }
  else if ( v4 == UI_HASH_DISABLECONTROLS_20 )
  {
    v5->mbAllowControls = 0;
  }
  return UFG::UIHKMinigameScreen::handleMessage((UFG::UIHKMinigameScreen *)&v5->vfptr, v4, v3);
}

// File Line: 335
// RVA: 0x620220
void __fastcall UFG::UIHKScreenPhoneTraceMinigame::fail(UFG::UIHKScreenPhoneTraceMinigame *this)
{
  UFG::UIHKScreenPhoneTraceMinigame *v1; // rbx
  Scaleform::GFx::Movie *v2; // rcx

  v1 = this;
  if ( this->mProgressionState == 1 )
    UFG::UIScreenManagerBase::queuePopScreen(
      (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
      0xFFFFFFFF);
  v2 = v1->mRenderable->m_movie.pObject;
  if ( v2 )
    Scaleform::GFx::Movie::Invoke(v2, "external_fail", 0i64, 0i64, 0);
}

