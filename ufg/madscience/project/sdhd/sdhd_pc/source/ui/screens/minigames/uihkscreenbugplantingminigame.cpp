// File Line: 42
// RVA: 0x5C4810
void __fastcall UFG::UIHKScreenBugPlantingMinigame::UIHKScreenBugPlantingMinigame(
        UFG::UIHKScreenBugPlantingMinigame *this,
        hkgpIndexedMeshDefinitions::Edge *a2)
{
  hkgpIndexedMesh::EdgeBarrier *v3; // rcx
  UFG::Controller *v4; // rcx
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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenBugPlantingMinigame::`vftable;
  v3 = (hkgpIndexedMesh::EdgeBarrier *)UFG::gInputSystem;
  if ( UFG::gInputSystem && UFG::gActiveControllerNum != -1 )
  {
    v4 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum];
    if ( !UFG::UI::gUIInputLocked )
      g_saved_gameplay_controller_mode = v4->m_ActiveMapSet;
    UFG::SetInputMode(IM_UI_ONLY, v4->mControllerIndex);
    ++UFG::UI::gUIInputLocked;
  }
  UFG::UIHKScreenBugPlantingMinigame::m_bWon = 0;
  *(_WORD *)&this->mbAllowExit = 257;
  if ( UFG::UIHKScreenBugPlantingMinigame::mbBuggingOnly )
    *(_WORD *)&this->mbSwitchToCalibration = 257;
  else
    *(_WORD *)&this->mbSwitchToCalibration = 0;
  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(v3, a2) )
  {
    if ( !UFG::UIHKScreenBugPlantingMinigame::mbBuggingOnly )
    {
      v5 = UFG::qWiseSymbol::create_from_string(&result, "mg_bug_planting");
      UFG::TiDo::LoadWwiseBank(v5);
      _((AMD_HD3D *)result.mUID);
    }
    this->mMusicPlay = 0;
  }
}

// File Line: 77
// RVA: 0x5C9ED0
void __fastcall UFG::UIHKScreenBugPlantingMinigame::~UIHKScreenBugPlantingMinigame(
        UFG::UIHKScreenBugPlantingMinigame *this)
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

  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenBugPlantingMinigame::`vftable;
  v2 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v2, "BugPlantingMinigame");
  v3 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    v3 = &gGlobalOverlaySentinel;
  p_HelpBar = &v3->HelpBar;
  v5 = UFG::qStringHash32("UIHKScreenBugPlantingMinigame", 0xFFFFFFFF);
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
  UFG::UIHKScreenBugPlantingMinigame::mbBuggingOnly = 0;
  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat((hkgpIndexedMesh::EdgeBarrier *)v7, v6) )
  {
    if ( (_S19_4 & 1) == 0 )
    {
      _S19_4 |= 1u;
      Set_State_minigame_mus_end_0.mUID = UFG::qWiseSymbolUIDFromString("Set_State_minigame_mus_end", 0x811C9DC5);
      _((AMD_HD3D *)Set_State_minigame_mus_end_0.mUID);
      atexit(UFG::UIHKScreenBugPlantingMinigame::_UIHKScreenBugPlantingMinigame_::_4_::_dynamic_atexit_destructor_for__Set_State_minigame_mus_end__);
    }
    UFG::Music::MusicEvent(Set_State_minigame_mus_end_0.mUID);
    UFG::qWiseSymbol::create_from_string(&result, "Stop_ch_start_hack");
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, result.mUID, 0i64, 0, 0i64);
    v9 = UFG::qWiseSymbol::create_from_string(&v11, "mg_bug_planting");
    UFG::TiDo::UnloadWwiseBank(v9);
    _((AMD_HD3D *)v11.mUID);
    _((AMD_HD3D *)result.mUID);
  }
  UFG::UIHKMinigameScreen::~UIHKMinigameScreen(this);
}

// File Line: 99
// RVA: 0x62FEE0
void __fastcall UFG::UIHKScreenBugPlantingMinigame::init(
        UFG::UIHKScreenBugPlantingMinigame *this,
        UFG::UICommandData *data)
{
  UFG::UIHKMissionProgressWidget *v3; // rax

  UFG::UIScreen::init(this, data);
  if ( UFG::UIHKScreenBugPlantingMinigame::mbBuggingOnly )
    UFG::UIScreen::invoke(this, "setBuggingOnly");
  *(_QWORD *)&this->m_fLeftExploreX = 0i64;
  *(_QWORD *)&this->m_fRightExploreX = 0i64;
  v3 = UFG::UIHKScreenHud::MissionProgress;
  UFG::UIHKScreenHud::MissionProgress->mChanged = 1;
  v3->mData[0].Changed = 1;
  v3->mData[1].Changed = 1;
  v3->mData[2].Changed = 1;
  v3->mData[3].Changed = 1;
}

// File Line: 119
// RVA: 0x63BE40
void __fastcall UFG::UIHKScreenBugPlantingMinigame::update(UFG::UIHKScreenBugPlantingMinigame *this, float elapsed)
{
  int v4; // edi
  UFG::qWiseSymbol *v5; // rax
  bool v6; // si
  float v7; // xmm7_4
  UFG::InputActionData *v8; // rcx
  float mAxisPositionY; // xmm6_4
  float v10; // xmm1_4
  UFG::InputActionData *v11; // rcx
  float v12; // xmm0_4
  UFG::InputActionData *v13; // rcx
  float v14; // xmm0_4
  UFG::InputActionData *v15; // rcx
  float v16; // xmm0_4
  Scaleform::GFx::Movie *pObject; // rcx
  int NValue; // edi
  float v19; // xmm3_4
  UFG::InputActionData *v20; // rcx
  float mAxisPositionX; // xmm0_4
  float v22; // xmm0_4
  float v23; // xmm1_4
  float v24; // xmm6_4
  UFG::InputActionData *v25; // rcx
  float v26; // xmm0_4
  float v27; // xmm0_4
  float v28; // xmm1_4
  float v29; // xmm6_4
  float m_fLeftStickX; // xmm0_4
  UFG::InputActionData *v31; // rcx
  bool v32; // dl
  UFG::InputActionData *v33; // rcx
  bool v34; // al
  UFG::InputActionData *v35; // rcx
  bool v36; // al
  double v37; // xmm6_8
  double m_fLeftStickY; // xmm6_8
  double m_fRightStickX; // xmm6_8
  double m_fRightStickY; // xmm6_8
  Scaleform::GFx::Movie *v41; // rdi
  bool m_IsKeyboardController; // si
  Scaleform::GFx::Value pval; // [rsp+30h] [rbp-B8h] BYREF
  unsigned int v44; // [rsp+60h] [rbp-88h]
  __int64 v45; // [rsp+68h] [rbp-80h]
  Scaleform::GFx::Value ptr; // [rsp+70h] [rbp-78h] BYREF
  int v47; // [rsp+A0h] [rbp-48h]
  __int64 v48; // [rsp+A8h] [rbp-40h]
  char v49[16]; // [rsp+B8h] [rbp-30h] BYREF
  __int64 v50; // [rsp+C8h] [rbp-20h]
  int v51; // [rsp+D0h] [rbp-18h]
  __int64 v52; // [rsp+D8h] [rbp-10h]
  char v53[16]; // [rsp+E8h] [rbp+0h] BYREF
  __int64 v54; // [rsp+F8h] [rbp+10h]
  int v55; // [rsp+100h] [rbp+18h]
  __int64 v56; // [rsp+108h] [rbp+20h]
  char v57[16]; // [rsp+118h] [rbp+30h] BYREF
  __int64 v58; // [rsp+128h] [rbp+40h]
  int v59; // [rsp+130h] [rbp+48h]
  double v60; // [rsp+138h] [rbp+50h]
  __int64 v61; // [rsp+148h] [rbp+60h]
  void *retaddr; // [rsp+1B8h] [rbp+D0h] BYREF

  v61 = -2i64;
  v4 = 0;
  v44 = 0;
  if ( UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "NISPause") )
    return;
  v6 = 0;
  if ( !this->mMusicPlay )
  {
    v5 = UFG::qWiseSymbol::create_from_string((UFG::qWiseSymbol *)&retaddr, "mg_bug_planting");
    v4 = 1;
    v44 = 1;
    if ( UFG::TiDo::BankLoaded(v5->mUID) )
      v6 = 1;
  }
  if ( (v4 & 1) != 0 )
  {
    v44 = v4 & 0xFFFFFFFE;
    _((AMD_HD3D *)(unsigned int)retaddr);
  }
  if ( v6 )
  {
    if ( (_S20_2 & 1) == 0 )
    {
      _S20_2 |= 1u;
      Set_State_minigame_mus_start_0.mUID = UFG::qWiseSymbolUIDFromString("Set_State_minigame_mus_start", 0x811C9DC5);
      _((AMD_HD3D *)Set_State_minigame_mus_start_0.mUID);
      atexit(UFG::UIHKScreenBugPlantingMinigame::update_::_8_::_dynamic_atexit_destructor_for__Set_State_minigame_mus_start__);
    }
    UFG::Music::MusicEvent(Set_State_minigame_mus_start_0.mUID);
    this->mMusicPlay = 1;
  }
  v7 = UFG::UIHKScreenBugPlantingMinigame::calcLeftStickRotation(this);
  v8 = UFG::ActionDef_UILeftThumbstick.mDataPerController[UFG::gActiveControllerNum];
  mAxisPositionY = 0.0;
  if ( v8 )
    v10 = v8->mAxisRawX[0];
  else
    v10 = 0.0;
  this->m_fLeftStickX = v10;
  v11 = UFG::ActionDef_UILeftThumbstick.mDataPerController[UFG::gActiveControllerNum];
  if ( v11 )
    v12 = v11->mAxisRawY[0];
  else
    v12 = 0.0;
  this->m_fLeftStickY = v12;
  v13 = UFG::ActionDef_UIRightThumbstick.mDataPerController[UFG::gActiveControllerNum];
  if ( v13 )
    v14 = v13->mAxisRawX[0];
  else
    v14 = 0.0;
  this->m_fRightStickX = v14;
  v15 = UFG::ActionDef_UIRightThumbstick.mDataPerController[UFG::gActiveControllerNum];
  if ( v15 )
    v16 = v15->mAxisRawY[0];
  else
    v16 = 0.0;
  this->m_fRightStickY = v16;
  if ( UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
  {
    pObject = this->mRenderable->m_movie.pObject;
    pval.pObjectInterface = 0i64;
    pval.Type = VT_Undefined;
    if ( !Scaleform::GFx::Movie::GetVariable(pObject, &pval, "gCurrentPhase")
      || (NValue = (int)pval.mValue.NValue, (unsigned int)((int)pval.mValue.NValue - 2) > 2) )
    {
      if ( (pval.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pval.pObjectInterface->vfptr->gap8[8])(
          pval.pObjectInterface,
          &pval,
          pval.mValue);
        pval.pObjectInterface = 0i64;
      }
      pval.Type = VT_Undefined;
      m_fLeftStickX = this->m_fLeftStickX;
      v32 = 1;
      if ( m_fLeftStickX >= 0.0 )
      {
        v31 = UFG::ActionDef_UILeftRepeat.mDataPerController[UFG::gActiveControllerNum];
        if ( !v31 || !v31->mActionTrue )
          v32 = 0;
      }
      v34 = 1;
      if ( m_fLeftStickX <= 0.0 )
      {
        v33 = UFG::ActionDef_UIRightRepeat.mDataPerController[UFG::gActiveControllerNum];
        if ( !v33 || !v33->mActionTrue )
          v34 = 0;
      }
      if ( v32 )
      {
        v7 = (float)(elapsed * 540.0) * -1.0;
      }
      else if ( v34 )
      {
        v7 = elapsed * 540.0;
      }
      goto LABEL_77;
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
    v19 = UFG::gMouseBugCalibrationSpeed;
    if ( NValue == 2 )
    {
      v20 = UFG::ActionDef_Mouse.mDataPerController[UFG::gActiveControllerNum];
      if ( v20 )
        mAxisPositionX = v20->mAxisPositionX;
      else
        mAxisPositionX = 0.0;
      if ( v20 )
        mAxisPositionY = v20->mAxisPositionY;
      v22 = (float)((float)(mAxisPositionX * UFG::gMouseBugCalibrationSpeed) * elapsed) + this->m_fLeftExploreX;
      this->m_fLeftExploreX = v22;
      v23 = *(float *)&FLOAT_1_0;
      if ( v22 <= -1.0 )
      {
        v22 = FLOAT_N1_0;
      }
      else if ( v22 >= 1.0 )
      {
        v22 = *(float *)&FLOAT_1_0;
      }
      this->m_fLeftExploreX = v22;
      v24 = (float)((float)(mAxisPositionY * v19) * elapsed) + this->m_fLeftExploreY;
      this->m_fLeftExploreY = v24;
      if ( v24 <= -1.0 )
      {
        v24 = FLOAT_N1_0;
      }
      else if ( v24 >= 1.0 )
      {
        goto LABEL_44;
      }
      v23 = v24;
LABEL_44:
      this->m_fLeftExploreY = v23;
      this->m_fLeftStickX = v22;
      this->m_fLeftStickY = v23;
      goto LABEL_77;
    }
    if ( NValue == 3 )
    {
      v25 = UFG::ActionDef_Mouse.mDataPerController[UFG::gActiveControllerNum];
      if ( v25 )
        v26 = v25->mAxisPositionX;
      else
        v26 = 0.0;
      if ( v25 )
        mAxisPositionY = v25->mAxisPositionY;
      v27 = (float)((float)(v26 * UFG::gMouseBugCalibrationSpeed) * elapsed) + this->m_fRightExploreX;
      this->m_fRightExploreX = v27;
      v28 = *(float *)&FLOAT_1_0;
      if ( v27 <= -1.0 )
      {
        v27 = FLOAT_N1_0;
      }
      else if ( v27 >= 1.0 )
      {
        v27 = *(float *)&FLOAT_1_0;
      }
      this->m_fRightExploreX = v27;
      v29 = (float)((float)(mAxisPositionY * v19) * elapsed) + this->m_fRightExploreY;
      this->m_fRightExploreY = v29;
      if ( v29 <= -1.0 )
      {
        v29 = FLOAT_N1_0;
      }
      else if ( v29 >= 1.0 )
      {
        goto LABEL_60;
      }
      v28 = v29;
LABEL_60:
      this->m_fRightExploreY = v28;
      this->m_fRightStickX = v27;
      this->m_fRightStickY = v28;
    }
  }
LABEL_77:
  v35 = UFG::ActionDef_UIAcceptPressed.mDataPerController[UFG::gActiveControllerNum];
  if ( !v35 || (v36 = 1, !v35->mActionTrue) )
    v36 = 0;
  this->mbAButton = v36;
  `eh vector constructor iterator(&ptr, 0x30ui64, 5, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  v37 = this->m_fLeftStickX;
  if ( ((__int64)ptr.pPrev & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, Scaleform::GFx::Value *, Scaleform::GFx::Value *))(*(_QWORD *)v45 + 16i64))(
      v45,
      &ptr,
      ptr.pNext);
    v45 = 0i64;
  }
  LODWORD(ptr.pPrev) = 5;
  *(double *)&ptr.pNext = v37;
  m_fLeftStickY = this->m_fLeftStickY;
  if ( (v47 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(unsigned __int64, Scaleform::GFx::Value::ValueType *, __int64))(*(_QWORD *)ptr.DataAux
                                                                                          + 16i64))(
      ptr.DataAux,
      &ptr.Type,
      v48);
    ptr.DataAux = 0i64;
  }
  v47 = 5;
  v48 = *(_QWORD *)&m_fLeftStickY;
  m_fRightStickX = this->m_fRightStickX;
  if ( (v51 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v50 + 16i64))(v50, v49, v52);
    v50 = 0i64;
  }
  v51 = 5;
  v52 = *(_QWORD *)&m_fRightStickX;
  m_fRightStickY = this->m_fRightStickY;
  if ( (v55 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v54 + 16i64))(v54, v53, v56);
    v54 = 0i64;
  }
  v55 = 5;
  v56 = *(_QWORD *)&m_fRightStickY;
  if ( (v59 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v58 + 16i64))(v58, v57, COERCE_DOUBLE(*(_QWORD *)&v60));
    v58 = 0i64;
  }
  v59 = 5;
  v60 = v7;
  if ( !this->mbAllowControls )
  {
    if ( ((__int64)ptr.pPrev & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, Scaleform::GFx::Value *, Scaleform::GFx::Value *))(*(_QWORD *)v45 + 16i64))(
        v45,
        &ptr,
        ptr.pNext);
      v45 = 0i64;
    }
    LODWORD(ptr.pPrev) = 5;
    ptr.pNext = 0i64;
    if ( (v47 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(unsigned __int64, Scaleform::GFx::Value::ValueType *, __int64))(*(_QWORD *)ptr.DataAux
                                                                                            + 16i64))(
        ptr.DataAux,
        &ptr.Type,
        v48);
      ptr.DataAux = 0i64;
    }
    v47 = 5;
    v48 = 0i64;
    if ( (v51 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v50 + 16i64))(v50, v49, v52);
      v50 = 0i64;
    }
    v51 = 5;
    v52 = 0i64;
    if ( (v55 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v54 + 16i64))(v54, v53, v56);
      v54 = 0i64;
    }
    v55 = 5;
    v56 = 0i64;
    if ( (v59 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v58 + 16i64))(
        v58,
        v57,
        COERCE_DOUBLE(*(_QWORD *)&v60));
      v58 = 0i64;
    }
    v59 = 5;
    v60 = 0.0;
  }
  v41 = this->mRenderable->m_movie.pObject;
  if ( v41 )
  {
    pval.pObjectInterface = 0i64;
    pval.Type = VT_Undefined;
    m_IsKeyboardController = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController;
    pval.Type = VT_Boolean;
    pval.mValue.BValue = m_IsKeyboardController;
    Scaleform::GFx::Movie::Invoke(v41, "Show_PCCtrls", 0i64, &pval, 1u);
    Scaleform::GFx::Movie::Invoke(v41, "MainLoop", 0i64, &ptr, 5u);
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
  UFG::UIHKMissionProgressWidget::Update(UFG::UIHKScreenHud::MissionProgress, this);
  if ( UFG::UIHKScreenBugPlantingMinigame::isPlayingActionNode(
         this,
         "\\Global\\BugPlanting\\Interactions\\Anims\\Planting_to_Screwdriver") )
  {
    this->mbAllowExit = 0;
  }
  else if ( UFG::UIHKScreenBugPlantingMinigame::isPlayingActionNode(
              this,
              "\\Global\\BugPlanting\\Interactions\\Anims\\Screwdriver_CYC_2") )
  {
    this->mbAllowExit = 1;
  }
  pval.pObjectInterface = 0i64;
  pval.Type = VT_Undefined;
  if ( this->mbAllowExit )
  {
    pval.Type = VT_Boolean;
    pval.mValue.BValue = 1;
    if ( v41 )
      Scaleform::GFx::Movie::SetVariable(v41, "exit_mc._visible", &pval, 1i64);
  }
  else
  {
    pval.Type = VT_Boolean;
    pval.mValue.BValue = 0;
    if ( v41 )
      Scaleform::GFx::Movie::SetVariable(v41, "exit_mc._visible", &pval, 1i64);
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
  UFG::UIScreen::update(this, elapsed);
  `eh vector destructor iterator(&ptr, 0x30ui64, 5, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 249
// RVA: 0x6216A0
bool __fastcall UFG::UIHKScreenBugPlantingMinigame::handleMessage(
        UFG::UIHKScreenBugPlantingMinigame *this,
        hkgpIndexedMeshDefinitions::Edge *msgId,
        UFG::UIMessage *msg)
{
  unsigned int v4; // edi
  UFG::UIHKScreenBugPlantingMinigame *v5; // rbx
  Scaleform::GFx::Movie *pObject; // rcx
  unsigned int v8; // eax
  int v9; // eax
  UFG::qNode<UFG::qString,UFG::qString> *mNext; // rsi
  unsigned int v11; // edi
  UFG::HudAudio *v12; // rbx
  float v13; // xmm0_4
  UFG::qString *i; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v16; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v17; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v18; // rax
  UFG::qList<UFG::qString,UFG::qString,1,0> list; // [rsp+38h] [rbp-40h] BYREF
  UFG::qString v20; // [rsp+48h] [rbp-30h] BYREF

  v4 = (unsigned int)msgId;
  v5 = this;
  if ( (_DWORD)msgId == UI_HASH_SETBUGPLANTINGCALIBRATION_20 )
  {
    if ( (_S21_2 & 1) == 0 )
    {
      _S21_2 |= 1u;
      play_ch_start_hack.mUID = UFG::qWiseSymbolUIDFromString("play_ch_start_hack", 0x811C9DC5);
      _((AMD_HD3D *)play_ch_start_hack.mUID);
      atexit(UFG::UIHKScreenBugPlantingMinigame::handleMessage_::_5_::_dynamic_atexit_destructor_for__play_ch_start_hack__);
    }
    this = (UFG::UIHKScreenBugPlantingMinigame *)UFG::HudAudio::m_instance;
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, play_ch_start_hack.mUID, 0i64, 0, 0i64);
    v5->mbSwitchToCalibration = 1;
    v5->mbAllowExit = 0;
  }
  else if ( (_DWORD)msgId == UI_HASH_SETBUGPLANTINGSCREWING_20 )
  {
    *(_WORD *)&this->mbSwitchToCalibration = 256;
  }
  else if ( (_DWORD)msgId == UI_HASH_SETFINISHED_20 )
  {
    UFG::GameStatAction::MiniGame::Completed(MGT_BugPlant);
    UFG::UIHKScreenBugPlantingMinigame::m_bWon = 1;
LABEL_11:
    v5->mFinished = 1;
    return 1;
  }
  if ( v4 == UI_HASH_BUTTON_BACK_PRESSED_30 && v5->mbAllowExit )
  {
    pObject = v5->mRenderable->m_movie.pObject;
    if ( pObject )
    {
      Scaleform::GFx::Movie::Invoke(pObject, "stopAllAudio", 0i64, 0i64, 0);
      v5->mFinished = 1;
      return 1;
    }
    goto LABEL_11;
  }
  if ( v4 == UI_HASH_PLAYSOUND_20 )
  {
    if ( Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
           (hkgpIndexedMesh::EdgeBarrier *)this,
           msgId) )
    {
      return 1;
    }
    UFG::qString::qString(&v20, (UFG::qString *)&msg[1]);
    v8 = UFG::TiDo::CalcWwiseUid(v20.mData);
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, v8, 0i64, 0, 0i64);
    UFG::qString::~qString(&v20);
    return 1;
  }
  else if ( v4 == UI_HASH_MODIFYRTPC_20 )
  {
    if ( Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
           (hkgpIndexedMesh::EdgeBarrier *)this,
           msgId) )
    {
      return 1;
    }
    UFG::qString::qString(&v20, (UFG::qString *)&msg[1]);
    list.mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&list;
    list.mNode.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&list;
    UFG::qString::Tokenize(&v20, &list, ",", "BugPlanting.HandleMessage");
    v9 = 1;
    mNext = list.mNode.mNext;
    do
    {
      if ( mNext == (UFG::qNode<UFG::qString,UFG::qString> *)&list )
        break;
      --v9;
      mNext = mNext->mNext;
    }
    while ( v9 > 0 );
    v11 = UFG::TiDo::CalcWwiseUid((const char *)list.mNode.mNext[1].mNext);
    v12 = UFG::HudAudio::m_instance;
    v13 = UFG::qToFloat((const char *)mNext[1].mNext, 0.0);
    UFG::AudioEntity::SetRtpcValue(v12, v11, v13);
    for ( i = (UFG::qString *)list.mNode.mNext;
          (UFG::qList<UFG::qString,UFG::qString,1,0> *)list.mNode.mNext != &list;
          i = (UFG::qString *)list.mNode.mNext )
    {
      mPrev = i->mPrev;
      v16 = i->mNext;
      mPrev->mNext = v16;
      v16->mPrev = mPrev;
      i->mPrev = i;
      i->mNext = i;
      UFG::qString::~qString(i);
      operator delete[](i);
    }
    v17 = list.mNode.mPrev;
    v18 = list.mNode.mNext;
    list.mNode.mPrev->mNext = list.mNode.mNext;
    v18->mPrev = v17;
    list.mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&list;
    list.mNode.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&list;
    UFG::qString::~qString(&v20);
    return 1;
  }
  else if ( v4 == UI_HASH_ENABLECONTROLS_20 )
  {
    *(_WORD *)&v5->mbAllowExit = 257;
    return 1;
  }
  else if ( v4 == UI_HASH_DISABLECONTROLS_20 )
  {
    *(_WORD *)&v5->mbAllowExit = 0;
    return 1;
  }
  else
  {
    return UFG::UIHKMinigameScreen::handleMessage(v5, v4, msg);
  }
}

// File Line: 349
// RVA: 0x61ECD0
float __fastcall UFG::UIHKScreenBugPlantingMinigame::calcLeftStickRotation(UFG::UIHKScreenBugPlantingMinigame *this)
{
  UFG::InputActionData *v1; // rcx
  float mAxisPositionY; // xmm7_4
  __m128 mAxisPositionX_low; // xmm8
  float v4; // xmm2_4
  __m128 v5; // xmm0
  __m128 v6; // xmm2
  float v7; // xmm4_4
  float v8; // xmm8_4
  float v9; // xmm7_4
  __m128 y_low; // xmm2
  float v11; // xmm3_4
  float v12; // xmm9_4
  float v13; // xmm10_4
  float v14; // xmm0_4
  float v15; // xmm6_4

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
    v4 = v1->mAxisPositionY;
  else
    v4 = 0.0;
  if ( v1 )
    v5 = (__m128)LODWORD(v1->mAxisPositionX);
  else
    v5 = 0i64;
  v5.m128_f32[0] = (float)(v5.m128_f32[0] * v5.m128_f32[0]) + (float)(v4 * v4);
  if ( _mm_sqrt_ps(v5).m128_f32[0] <= 0.80000001 )
  {
    UFG::firstOut = 1;
    UFG::g_previousVector = UFG::qVector2::msZero;
  }
  else
  {
    v6 = mAxisPositionX_low;
    v6.m128_f32[0] = (float)(mAxisPositionX_low.m128_f32[0] * mAxisPositionX_low.m128_f32[0])
                   + (float)(mAxisPositionY * mAxisPositionY);
    if ( v6.m128_f32[0] == 0.0 )
      v7 = 0.0;
    else
      v7 = 1.0 / _mm_sqrt_ps(v6).m128_f32[0];
    v8 = mAxisPositionX_low.m128_f32[0] * v7;
    v9 = mAxisPositionY * v7;
    y_low = (__m128)LODWORD(UFG::g_previousVector.y);
    y_low.m128_f32[0] = (float)(y_low.m128_f32[0] * y_low.m128_f32[0])
                      + (float)(UFG::g_previousVector.x * UFG::g_previousVector.x);
    if ( y_low.m128_f32[0] == 0.0 )
      v11 = 0.0;
    else
      v11 = 1.0 / _mm_sqrt_ps(y_low).m128_f32[0];
    v12 = UFG::g_previousVector.x * v11;
    v13 = UFG::g_previousVector.y * v11;
    v14 = atan2f(v9, v8);
    v15 = v14 - atan2f(v13, v12);
    if ( v15 >= -3.1415927 )
    {
      if ( v15 > 3.1415927 )
        v15 = v15 + -6.2831855;
    }
    else
    {
      v15 = v15 + 6.2831855;
    }
    UFG::g_previousVector.x = v8;
    UFG::g_previousVector.y = v9;
    if ( !UFG::firstOut )
      return v15 * 57.295776;
    UFG::firstOut = 0;
  }
  return FLOAT_N1_0;
}

// File Line: 382
// RVA: 0x638700
bool __fastcall UFG::UIHKScreenBugPlantingMinigame::isPlayingActionNode(
        UFG::UIHKScreenBugPlantingMinigame *this,
        const char *nodeName)
{
  signed __int16 m_Flags; // r8
  UFG::SimComponent *m_pComponent; // rbx
  UFG::SimComponent *v5; // rax
  bool IsPlayingFullPath; // bl
  int mCount; // edx
  ActionPath animPath; // [rsp+28h] [rbp-20h] BYREF

  if ( !LocalPlayer )
    return 0;
  m_Flags = LocalPlayer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = LocalPlayer->m_Components.p[7].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 )
    {
      m_pComponent = LocalPlayer->m_Components.p[6].m_pComponent;
    }
    else
    {
      v5 = (m_Flags & 0x1000) != 0
         ? UFG::SimObjectGame::GetComponentOfTypeHK(LocalPlayer, UFG::ActionTreeComponent::_TypeUID)
         : UFG::SimObject::GetComponentOfType(LocalPlayer, UFG::ActionTreeComponent::_TypeUID);
      m_pComponent = v5;
    }
  }
  else
  {
    m_pComponent = LocalPlayer->m_Components.p[7].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  animPath.mPath.mCount = 0;
  animPath.mPath.mData.mOffset = 0i64;
  ActionPath::Append(&animPath, nodeName);
  IsPlayingFullPath = ActionController::IsPlayingFullPath((ActionController *)&m_pComponent[3], &animPath, 1);
  mCount = animPath.mPath.mCount;
  if ( animPath.mPath.mCount >= 0 )
  {
    if ( animPath.mPath.mData.mOffset )
    {
      if ( (UFG::qOffset64<ActionID *> *)((char *)&animPath.mPath.mData + animPath.mPath.mData.mOffset) )
      {
        operator delete[]((char *)&animPath.mPath.mData + animPath.mPath.mData.mOffset);
        mCount = animPath.mPath.mCount;
      }
    }
    animPath.mPath.mData.mOffset = 0i64;
    animPath.mPath.mCount = mCount & 0x80000000;
  }
  return IsPlayingFullPath;
}

