// File Line: 42
// RVA: 0x5C4810
void __fastcall UFG::UIHKScreenBugPlantingMinigame::UIHKScreenBugPlantingMinigame(UFG::UIHKScreenBugPlantingMinigame *this, hkgpIndexedMeshDefinitions::Edge *a2)
{
  UFG::UIHKScreenBugPlantingMinigame *v2; // rbx
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v3; // rax
  hkgpIndexedMesh::EdgeBarrier *v4; // rcx
  UFG::Controller *v5; // rcx
  UFG::qWiseSymbol *v6; // rax
  UFG::qWiseSymbol result; // [rsp+48h] [rbp+10h]

  v2 = this;
  v3 = (UFG::qNode<UFG::UIScreen,UFG::UIScreen> *)&this->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
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
  --v2->mInputEnabled;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKTaskableScreen::`vftable';
  this->mFinished = 0;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKMinigameScreen::`vftable';
  *(_QWORD *)&this->mfAlphaValue = 1109393408i64;
  ++UFG::UIHKMinigameScreen::mNumMinigameScreens;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenBugPlantingMinigame::`vftable';
  v4 = (hkgpIndexedMesh::EdgeBarrier *)UFG::gInputSystem;
  if ( UFG::gInputSystem && UFG::gActiveControllerNum != -1 )
  {
    v5 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum];
    if ( !UFG::UI::gUIInputLocked )
      g_saved_gameplay_controller_mode = v5->m_ActiveMapSet;
    UFG::SetInputMode(IM_UI_ONLY, v5->mControllerIndex);
    ++UFG::UI::gUIInputLocked;
  }
  UFG::UIHKScreenBugPlantingMinigame::m_bWon = 0;
  *(_WORD *)&v2->mbAllowExit = 257;
  if ( UFG::UIHKScreenBugPlantingMinigame::mbBuggingOnly )
    *(_WORD *)&v2->mbSwitchToCalibration = 257;
  else
    *(_WORD *)&v2->mbSwitchToCalibration = 0;
  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(v4, a2) )
  {
    if ( !UFG::UIHKScreenBugPlantingMinigame::mbBuggingOnly )
    {
      v6 = UFG::qWiseSymbol::create_from_string(&result, "mg_bug_planting");
      UFG::TiDo::LoadWwiseBank(v6);
      _((AMD_HD3D *)result.mUID);
    }
    v2->mMusicPlay = 0;
  }
}

// File Line: 77
// RVA: 0x5C9ED0
void __fastcall UFG::UIHKScreenBugPlantingMinigame::~UIHKScreenBugPlantingMinigame(UFG::UIHKScreenBugPlantingMinigame *this)
{
  UFG::UIHKScreenBugPlantingMinigame *v1; // rdi
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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenBugPlantingMinigame::`vftable';
  v2 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v2, "BugPlantingMinigame");
  v3 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    v3 = &gGlobalOverlaySentinel;
  v4 = &v3->HelpBar;
  v5 = UFG::qStringHash32("UIHKScreenBugPlantingMinigame", 0xFFFFFFFF);
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
  UFG::UIHKScreenBugPlantingMinigame::mbBuggingOnly = 0;
  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat((hkgpIndexedMesh::EdgeBarrier *)v7, v6) )
  {
    if ( !(_S19_4 & 1) )
    {
      _S19_4 |= 1u;
      Set_State_minigame_mus_end_0.mUID = UFG::qWiseSymbolUIDFromString("Set_State_minigame_mus_end", 0x811C9DC5);
      _((AMD_HD3D *)Set_State_minigame_mus_end_0.mUID);
      atexit(UFG::UIHKScreenBugPlantingMinigame::_UIHKScreenBugPlantingMinigame_::_4_::_dynamic_atexit_destructor_for__Set_State_minigame_mus_end__);
    }
    UFG::Music::MusicEvent(Set_State_minigame_mus_end_0.mUID);
    UFG::qWiseSymbol::create_from_string(&result, "Stop_ch_start_hack");
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        result.mUID,
        0i64,
        0,
        0i64);
    v9 = UFG::qWiseSymbol::create_from_string(&v11, "mg_bug_planting");
    UFG::TiDo::UnloadWwiseBank(v9);
    _((AMD_HD3D *)v11.mUID);
    _((AMD_HD3D *)result.mUID);
  }
  UFG::UIHKMinigameScreen::~UIHKMinigameScreen((UFG::UIHKMinigameScreen *)&v1->vfptr);
}

// File Line: 99
// RVA: 0x62FEE0
void __fastcall UFG::UIHKScreenBugPlantingMinigame::init(UFG::UIHKScreenBugPlantingMinigame *this, UFG::UICommandData *data)
{
  UFG::UIHKScreenBugPlantingMinigame *v2; // rbx
  UFG::UIHKMissionProgressWidget *v3; // rax

  v2 = this;
  UFG::UIScreen::init((UFG::UIScreen *)&this->vfptr, data);
  if ( UFG::UIHKScreenBugPlantingMinigame::mbBuggingOnly )
    UFG::UIScreen::invoke((UFG::UIScreen *)&v2->vfptr, "setBuggingOnly");
  *(_QWORD *)&v2->m_fLeftExploreX = 0i64;
  *(_QWORD *)&v2->m_fRightExploreX = 0i64;
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
  float v2; // xmm8_4
  UFG::UIHKScreenBugPlantingMinigame *v3; // rbx
  signed int v4; // edi
  UFG::qWiseSymbol *v5; // rax
  bool v6; // si
  float v7; // xmm7_4
  UFG::InputActionData *v8; // rcx
  float v9; // xmm6_4
  float v10; // xmm1_4
  UFG::InputActionData *v11; // rcx
  float v12; // xmm0_4
  UFG::InputActionData *v13; // rcx
  float v14; // xmm0_4
  UFG::InputActionData *v15; // rcx
  float v16; // xmm0_4
  Scaleform::GFx::Movie *v17; // rcx
  signed int v18; // edi
  float v19; // xmm3_4
  UFG::InputActionData *v20; // rcx
  float v21; // xmm0_4
  float v22; // xmm0_4
  float v23; // xmm1_4
  float v24; // xmm6_4
  UFG::InputActionData *v25; // rcx
  float v26; // xmm0_4
  float v27; // xmm0_4
  float v28; // xmm1_4
  float v29; // xmm6_4
  float v30; // xmm0_4
  UFG::InputActionData *v31; // rcx
  bool v32; // dl
  UFG::InputActionData *v33; // rcx
  bool v34; // al
  UFG::InputActionData *v35; // rcx
  char v36; // al
  double v37; // xmm6_8
  double v38; // xmm6_8
  double v39; // xmm6_8
  double v40; // xmm6_8
  Scaleform::GFx::Movie *v41; // rdi
  bool v42; // si
  Scaleform::GFx::Value pval; // [rsp+30h] [rbp-B8h]
  unsigned int v44; // [rsp+60h] [rbp-88h]
  __int64 v45; // [rsp+68h] [rbp-80h]
  unsigned int ptr; // [rsp+70h] [rbp-78h]
  __int64 v47; // [rsp+78h] [rbp-70h]
  char v48; // [rsp+88h] [rbp-60h]
  __int64 v49; // [rsp+98h] [rbp-50h]
  unsigned int v50; // [rsp+A0h] [rbp-48h]
  __int64 v51; // [rsp+A8h] [rbp-40h]
  char v52; // [rsp+B8h] [rbp-30h]
  __int64 v53; // [rsp+C8h] [rbp-20h]
  unsigned int v54; // [rsp+D0h] [rbp-18h]
  __int64 v55; // [rsp+D8h] [rbp-10h]
  char v56; // [rsp+E8h] [rbp+0h]
  __int64 v57; // [rsp+F8h] [rbp+10h]
  unsigned int v58; // [rsp+100h] [rbp+18h]
  __int64 v59; // [rsp+108h] [rbp+20h]
  char v60; // [rsp+118h] [rbp+30h]
  __int64 v61; // [rsp+128h] [rbp+40h]
  unsigned int v62; // [rsp+130h] [rbp+48h]
  double v63; // [rsp+138h] [rbp+50h]
  __int64 v64; // [rsp+148h] [rbp+60h]
  void *retaddr; // [rsp+1B8h] [rbp+D0h]

  v64 = -2i64;
  v2 = elapsed;
  v3 = this;
  v4 = 0;
  v44 = 0;
  if ( UFG::UIScreenManagerBase::getScreen(
         (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
         "NISPause") )
  {
    return;
  }
  v6 = 0;
  if ( !v3->mMusicPlay )
  {
    v5 = UFG::qWiseSymbol::create_from_string((UFG::qWiseSymbol *)&retaddr, "mg_bug_planting");
    v4 = 1;
    v44 = 1;
    if ( (unsigned __int8)UFG::TiDo::BankLoaded(v5->mUID) )
      v6 = 1;
  }
  if ( v4 & 1 )
  {
    v44 = v4 & 0xFFFFFFFE;
    _((AMD_HD3D *)(unsigned int)retaddr);
  }
  if ( v6 )
  {
    if ( !(_S20_2 & 1) )
    {
      _S20_2 |= 1u;
      Set_State_minigame_mus_start_0.mUID = UFG::qWiseSymbolUIDFromString("Set_State_minigame_mus_start", 0x811C9DC5);
      _((AMD_HD3D *)Set_State_minigame_mus_start_0.mUID);
      atexit(UFG::UIHKScreenBugPlantingMinigame::update_::_8_::_dynamic_atexit_destructor_for__Set_State_minigame_mus_start__);
    }
    UFG::Music::MusicEvent(Set_State_minigame_mus_start_0.mUID);
    v3->mMusicPlay = 1;
  }
  v7 = UFG::UIHKScreenBugPlantingMinigame::calcLeftStickRotation(v3);
  v8 = UFG::ActionDef_UILeftThumbstick.mDataPerController[UFG::gActiveControllerNum];
  v9 = 0.0;
  if ( v8 )
    v10 = v8->mAxisRawX[0];
  else
    v10 = 0.0;
  v3->m_fLeftStickX = v10;
  v11 = UFG::ActionDef_UILeftThumbstick.mDataPerController[UFG::gActiveControllerNum];
  if ( v11 )
    v12 = v11->mAxisRawY[0];
  else
    v12 = 0.0;
  v3->m_fLeftStickY = v12;
  v13 = UFG::ActionDef_UIRightThumbstick.mDataPerController[UFG::gActiveControllerNum];
  if ( v13 )
    v14 = v13->mAxisRawX[0];
  else
    v14 = 0.0;
  v3->m_fRightStickX = v14;
  v15 = UFG::ActionDef_UIRightThumbstick.mDataPerController[UFG::gActiveControllerNum];
  if ( v15 )
    v16 = v15->mAxisRawY[0];
  else
    v16 = 0.0;
  v3->m_fRightStickY = v16;
  if ( UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
  {
    v17 = v3->mRenderable->m_movie.pObject;
    pval.pObjectInterface = 0i64;
    pval.Type = 0;
    if ( !Scaleform::GFx::Movie::GetVariable(v17, &pval, "gCurrentPhase")
      || (v18 = (signed int)pval.mValue.NValue, (unsigned int)((signed int)pval.mValue.NValue - 2) > 2) )
    {
      if ( ((unsigned int)pval.Type >> 6) & 1 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pval.pObjectInterface->vfptr->gap8[8])(
          pval.pObjectInterface,
          &pval,
          *(_QWORD *)&pval.mValue.NValue);
        pval.pObjectInterface = 0i64;
      }
      pval.Type = 0;
      v30 = v3->m_fLeftStickX;
      v32 = 1;
      if ( v30 >= 0.0 )
      {
        v31 = UFG::ActionDef_UILeftRepeat.mDataPerController[UFG::gActiveControllerNum];
        if ( !v31 || !v31->mActionTrue )
          v32 = 0;
      }
      v34 = 1;
      if ( v30 <= 0.0 )
      {
        v33 = UFG::ActionDef_UIRightRepeat.mDataPerController[UFG::gActiveControllerNum];
        if ( !v33 || !v33->mActionTrue )
          v34 = 0;
      }
      if ( v32 )
      {
        v7 = (float)(v2 * 540.0) * -1.0;
      }
      else if ( v34 )
      {
        v7 = v2 * 540.0;
      }
      goto LABEL_77;
    }
    if ( ((unsigned int)pval.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pval.pObjectInterface->vfptr->gap8[8])(
        pval.pObjectInterface,
        &pval,
        *(_QWORD *)&pval.mValue.NValue);
      pval.pObjectInterface = 0i64;
    }
    pval.Type = 0;
    v19 = UFG::gMouseBugCalibrationSpeed;
    if ( v18 == 2 )
    {
      v20 = UFG::ActionDef_Mouse.mDataPerController[UFG::gActiveControllerNum];
      if ( v20 )
        v21 = v20->mAxisPositionX;
      else
        v21 = 0.0;
      if ( v20 )
        v9 = v20->mAxisPositionY;
      v22 = (float)((float)(v21 * UFG::gMouseBugCalibrationSpeed) * v2) + v3->m_fLeftExploreX;
      v3->m_fLeftExploreX = v22;
      v23 = *(float *)&FLOAT_1_0;
      if ( v22 <= -1.0 )
      {
        v22 = FLOAT_N1_0;
      }
      else if ( v22 >= 1.0 )
      {
        v22 = *(float *)&FLOAT_1_0;
      }
      v3->m_fLeftExploreX = v22;
      v24 = (float)((float)(v9 * v19) * v2) + v3->m_fLeftExploreY;
      v3->m_fLeftExploreY = v24;
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
      v3->m_fLeftExploreY = v23;
      v3->m_fLeftStickX = v22;
      v3->m_fLeftStickY = v23;
      goto LABEL_77;
    }
    if ( v18 == 3 )
    {
      v25 = UFG::ActionDef_Mouse.mDataPerController[UFG::gActiveControllerNum];
      if ( v25 )
        v26 = v25->mAxisPositionX;
      else
        v26 = 0.0;
      if ( v25 )
        v9 = v25->mAxisPositionY;
      v27 = (float)((float)(v26 * UFG::gMouseBugCalibrationSpeed) * v2) + v3->m_fRightExploreX;
      v3->m_fRightExploreX = v27;
      v28 = *(float *)&FLOAT_1_0;
      if ( v27 <= -1.0 )
      {
        v27 = FLOAT_N1_0;
      }
      else if ( v27 >= 1.0 )
      {
        v27 = *(float *)&FLOAT_1_0;
      }
      v3->m_fRightExploreX = v27;
      v29 = (float)((float)(v9 * v19) * v2) + v3->m_fRightExploreY;
      v3->m_fRightExploreY = v29;
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
      v3->m_fRightExploreY = v28;
      v3->m_fRightStickX = v27;
      v3->m_fRightStickY = v28;
      goto LABEL_77;
    }
  }
LABEL_77:
  v35 = UFG::ActionDef_UIAcceptPressed.mDataPerController[UFG::gActiveControllerNum];
  if ( !v35 || (v36 = 1, !v35->mActionTrue) )
    v36 = 0;
  v3->mbAButton = v36;
  `eh vector constructor iterator'(&ptr, 0x30ui64, 5, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  v37 = v3->m_fLeftStickX;
  if ( (ptr >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, unsigned int *, __int64))(*(_QWORD *)v45 + 16i64))(v45, &ptr, v47);
    v45 = 0i64;
  }
  ptr = 5;
  v47 = *(_QWORD *)&v37;
  v38 = v3->m_fLeftStickY;
  if ( (v50 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v49 + 16i64))(v49, &v48, v51);
    v49 = 0i64;
  }
  v50 = 5;
  v51 = *(_QWORD *)&v38;
  v39 = v3->m_fRightStickX;
  if ( (v54 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v53 + 16i64))(v53, &v52, v55);
    v53 = 0i64;
  }
  v54 = 5;
  v55 = *(_QWORD *)&v39;
  v40 = v3->m_fRightStickY;
  if ( (v58 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v57 + 16i64))(v57, &v56, v59);
    v57 = 0i64;
  }
  v58 = 5;
  v59 = *(_QWORD *)&v40;
  if ( (v62 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v61 + 16i64))(
      v61,
      &v60,
      COERCE_DOUBLE(*(_QWORD *)&v63));
    v61 = 0i64;
  }
  v62 = 5;
  v63 = v7;
  if ( !v3->mbAllowControls )
  {
    if ( (ptr >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, unsigned int *, __int64))(*(_QWORD *)v45 + 16i64))(v45, &ptr, v47);
      v45 = 0i64;
    }
    ptr = 5;
    v47 = 0i64;
    if ( (v50 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v49 + 16i64))(v49, &v48, v51);
      v49 = 0i64;
    }
    v50 = 5;
    v51 = 0i64;
    if ( (v54 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v53 + 16i64))(v53, &v52, v55);
      v53 = 0i64;
    }
    v54 = 5;
    v55 = 0i64;
    if ( (v58 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v57 + 16i64))(v57, &v56, v59);
      v57 = 0i64;
    }
    v58 = 5;
    v59 = 0i64;
    if ( (v62 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v61 + 16i64))(
        v61,
        &v60,
        COERCE_DOUBLE(*(_QWORD *)&v63));
      v61 = 0i64;
    }
    v62 = 5;
    v63 = 0.0;
  }
  v41 = v3->mRenderable->m_movie.pObject;
  if ( v41 )
  {
    pval.pObjectInterface = 0i64;
    pval.Type = 0;
    v42 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController;
    pval.Type = 2;
    pval.mValue.BValue = v42;
    Scaleform::GFx::Movie::Invoke(v41, "Show_PCCtrls", 0i64, &pval, 1u);
    Scaleform::GFx::Movie::Invoke(v41, "MainLoop", 0i64, (Scaleform::GFx::Value *)&ptr, 5u);
    if ( ((unsigned int)pval.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pval.pObjectInterface->vfptr->gap8[8])(
        pval.pObjectInterface,
        &pval,
        *(_QWORD *)&pval.mValue.NValue);
      pval.pObjectInterface = 0i64;
    }
    pval.Type = 0;
  }
  UFG::UIHKMissionProgressWidget::Update(UFG::UIHKScreenHud::MissionProgress, (UFG::UIScreen *)&v3->vfptr);
  if ( UFG::UIHKScreenBugPlantingMinigame::isPlayingActionNode(
         v3,
         "\\Global\\BugPlanting\\Interactions\\Anims\\Planting_to_Screwdriver") )
  {
    v3->mbAllowExit = 0;
  }
  else if ( UFG::UIHKScreenBugPlantingMinigame::isPlayingActionNode(
              v3,
              "\\Global\\BugPlanting\\Interactions\\Anims\\Screwdriver_CYC_2") )
  {
    v3->mbAllowExit = 1;
  }
  pval.pObjectInterface = 0i64;
  pval.Type = 0;
  if ( v3->mbAllowExit )
  {
    if ( ((unsigned int)pval.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pval.pObjectInterface->vfptr->gap8[8])(
        pval.pObjectInterface,
        &pval,
        *(_QWORD *)&pval.mValue.NValue);
      pval.pObjectInterface = 0i64;
    }
    pval.Type = 2;
    pval.mValue.BValue = 1;
    if ( v41 )
      Scaleform::GFx::Movie::SetVariable(v41, "exit_mc._visible", &pval, 1i64);
  }
  else
  {
    if ( ((unsigned int)pval.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pval.pObjectInterface->vfptr->gap8[8])(
        pval.pObjectInterface,
        &pval,
        *(_QWORD *)&pval.mValue.NValue);
      pval.pObjectInterface = 0i64;
    }
    pval.Type = 2;
    pval.mValue.BValue = 0;
    if ( v41 )
      Scaleform::GFx::Movie::SetVariable(v41, "exit_mc._visible", &pval, 1i64);
  }
  if ( ((unsigned int)pval.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pval.pObjectInterface->vfptr->gap8[8])(
      pval.pObjectInterface,
      &pval,
      *(_QWORD *)&pval.mValue.NValue);
    pval.pObjectInterface = 0i64;
  }
  pval.Type = 0;
  UFG::UIScreen::update((UFG::UIScreen *)&v3->vfptr, v2);
  `eh vector destructor iterator'(&ptr, 0x30ui64, 5, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 249
// RVA: 0x6216A0
bool __fastcall UFG::UIHKScreenBugPlantingMinigame::handleMessage(UFG::UIHKScreenBugPlantingMinigame *this, __int64 msgId, UFG::UIMessage *msg)
{
  UFG::UIMessage *v3; // rsi
  unsigned int v4; // edi
  UFG::UIHKScreenBugPlantingMinigame *v5; // rbx
  bool result; // al
  Scaleform::GFx::Movie *v7; // rcx
  unsigned int v8; // eax
  signed int v9; // eax
  UFG::qNode<UFG::qString,UFG::qString> *v10; // rsi
  unsigned int v11; // edi
  UFG::HudAudio *v12; // rbx
  float v13; // xmm0_4
  UFG::qString *i; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v15; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v16; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v17; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v18; // rax
  UFG::qList<UFG::qString,UFG::qString,1,0> list; // [rsp+38h] [rbp-40h]
  UFG::qString v20; // [rsp+48h] [rbp-30h]

  v3 = msg;
  v4 = msgId;
  v5 = this;
  if ( (_DWORD)msgId == UI_HASH_SETBUGPLANTINGCALIBRATION_20 )
  {
    if ( !(_S21_2 & 1) )
    {
      _S21_2 |= 1u;
      play_ch_start_hack.mUID = UFG::qWiseSymbolUIDFromString("play_ch_start_hack", 0x811C9DC5);
      _((AMD_HD3D *)play_ch_start_hack.mUID);
      atexit(UFG::UIHKScreenBugPlantingMinigame::handleMessage_::_5_::_dynamic_atexit_destructor_for__play_ch_start_hack__);
    }
    this = (UFG::UIHKScreenBugPlantingMinigame *)UFG::HudAudio::m_instance;
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        play_ch_start_hack.mUID,
        0i64,
        0,
        0i64);
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
    v7 = v5->mRenderable->m_movie.pObject;
    if ( v7 )
    {
      Scaleform::GFx::Movie::Invoke(v7, "stopAllAudio", 0i64, 0i64, 0);
      v5->mFinished = 1;
      return 1;
    }
    goto LABEL_11;
  }
  if ( v4 == UI_HASH_PLAYSOUND_20 )
  {
    if ( Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
           (hkgpIndexedMesh::EdgeBarrier *)this,
           (hkgpIndexedMeshDefinitions::Edge *)msgId) )
    {
      return 1;
    }
    UFG::qString::qString(&v20, (UFG::qString *)&v3[1]);
    v8 = UFG::TiDo::CalcWwiseUid(v20.mData);
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr, v8, 0i64, 0, 0i64);
    UFG::qString::~qString(&v20);
    result = 1;
  }
  else if ( v4 == UI_HASH_MODIFYRTPC_20 )
  {
    if ( Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
           (hkgpIndexedMesh::EdgeBarrier *)this,
           (hkgpIndexedMeshDefinitions::Edge *)msgId) )
    {
      return 1;
    }
    UFG::qString::qString(&v20, (UFG::qString *)&v3[1]);
    list.mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&list;
    list.mNode.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&list;
    UFG::qString::Tokenize(&v20, &list, ",", "BugPlanting.HandleMessage");
    v9 = 1;
    v10 = list.mNode.mNext;
    do
    {
      if ( v10 == (UFG::qNode<UFG::qString,UFG::qString> *)&list )
        break;
      --v9;
      v10 = v10->mNext;
    }
    while ( v9 > 0 );
    v11 = UFG::TiDo::CalcWwiseUid((const char *)list.mNode.mNext[1].mNext);
    v12 = UFG::HudAudio::m_instance;
    v13 = UFG::qToFloat((const char *)v10[1].mNext, 0.0);
    UFG::AudioEntity::SetRtpcValue((UFG::AudioEntity *)&v12->vfptr, v11, v13);
    for ( i = (UFG::qString *)list.mNode.mNext;
          (UFG::qList<UFG::qString,UFG::qString,1,0> *)list.mNode.mNext != &list;
          i = (UFG::qString *)list.mNode.mNext )
    {
      v15 = i->mPrev;
      v16 = i->mNext;
      v15->mNext = v16;
      v16->mPrev = v15;
      i->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&i->mPrev;
      i->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&i->mPrev;
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
    result = 1;
  }
  else if ( v4 == UI_HASH_ENABLECONTROLS_20 )
  {
    *(_WORD *)&v5->mbAllowExit = 257;
    result = 1;
  }
  else if ( v4 == UI_HASH_DISABLECONTROLS_20 )
  {
    *(_WORD *)&v5->mbAllowExit = 0;
    result = 1;
  }
  else
  {
    result = UFG::UIHKMinigameScreen::handleMessage((UFG::UIHKMinigameScreen *)&v5->vfptr, v4, v3);
  }
  return result;
}

// File Line: 349
// RVA: 0x61ECD0
float __fastcall UFG::UIHKScreenBugPlantingMinigame::calcLeftStickRotation(UFG::UIHKScreenBugPlantingMinigame *this)
{
  UFG::InputActionData *v1; // rcx
  float v2; // xmm7_4
  __m128 v3; // xmm8
  float v4; // xmm2_4
  __m128 v5; // xmm0
  __m128 v6; // xmm2
  float v7; // xmm4_4
  float v8; // xmm8_4
  float v9; // xmm7_4
  __m128 v10; // xmm2
  float v11; // xmm3_4
  float v12; // xmm9_4
  float v13; // xmm10_4
  float v14; // xmm0_4
  float v15; // xmm6_4

  v1 = UFG::ActionDef_UILeftThumbstick.mDataPerController[UFG::gActiveControllerNum];
  if ( v1 )
    v2 = v1->mAxisPositionY;
  else
    v2 = 0.0;
  if ( v1 )
    v3 = (__m128)LODWORD(v1->mAxisPositionX);
  else
    v3 = 0i64;
  if ( v1 )
    v4 = v1->mAxisPositionY;
  else
    v4 = 0.0;
  if ( v1 )
    v5 = (__m128)LODWORD(v1->mAxisPositionX);
  else
    v5 = 0i64;
  v5.m128_f32[0] = (float)(v5.m128_f32[0] * v5.m128_f32[0]) + (float)(v4 * v4);
  if ( COERCE_FLOAT(_mm_sqrt_ps(v5)) <= 0.80000001 )
  {
    UFG::firstOut = 1;
    UFG::g_previousVector = UFG::qVector2::msZero;
  }
  else
  {
    v6 = v3;
    v6.m128_f32[0] = (float)(v3.m128_f32[0] * v3.m128_f32[0]) + (float)(v2 * v2);
    if ( v6.m128_f32[0] == 0.0 )
      v7 = 0.0;
    else
      v7 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v6));
    v8 = v3.m128_f32[0] * v7;
    v9 = v2 * v7;
    v10 = (__m128)LODWORD(UFG::g_previousVector.y);
    v10.m128_f32[0] = (float)(v10.m128_f32[0] * v10.m128_f32[0])
                    + (float)(UFG::g_previousVector.x * UFG::g_previousVector.x);
    if ( v10.m128_f32[0] == 0.0 )
      v11 = 0.0;
    else
      v11 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v10));
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
bool __fastcall UFG::UIHKScreenBugPlantingMinigame::isPlayingActionNode(UFG::UIHKScreenBugPlantingMinigame *this, const char *nodeName)
{
  const char *v2; // rdi
  unsigned __int16 v3; // r8
  UFG::SimComponent *v4; // rbx
  UFG::SimComponent *v5; // rax
  bool v6; // bl
  int v7; // edx
  ActionPath animPath; // [rsp+28h] [rbp-20h]

  v2 = nodeName;
  if ( !LocalPlayer )
    return 0;
  v3 = LocalPlayer->m_Flags;
  if ( (v3 >> 14) & 1 )
  {
    v4 = LocalPlayer->m_Components.p[7].m_pComponent;
  }
  else if ( (v3 & 0x8000u) == 0 )
  {
    if ( (v3 >> 13) & 1 )
    {
      v4 = LocalPlayer->m_Components.p[6].m_pComponent;
    }
    else
    {
      v5 = (v3 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                              (UFG::SimObjectGame *)&LocalPlayer->vfptr,
                              UFG::ActionTreeComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                      (UFG::SimObject *)&LocalPlayer->vfptr,
                                                                      UFG::ActionTreeComponent::_TypeUID);
      v4 = v5;
    }
  }
  else
  {
    v4 = LocalPlayer->m_Components.p[7].m_pComponent;
  }
  if ( !v4 )
    return 0;
  animPath.mPath.mCount = 0;
  animPath.mPath.mData.mOffset = 0i64;
  ActionPath::Append(&animPath, v2);
  v6 = ActionController::IsPlayingFullPath((ActionController *)&v4[3], &animPath, 1);
  v7 = animPath.mPath.mCount;
  if ( animPath.mPath.mCount >= 0 )
  {
    if ( animPath.mPath.mData.mOffset )
    {
      if ( (UFG::qOffset64<ActionID *> *)((char *)&animPath.mPath.mData + animPath.mPath.mData.mOffset) )
      {
        operator delete[]((char *)&animPath.mPath.mData + animPath.mPath.mData.mOffset);
        v7 = animPath.mPath.mCount;
      }
    }
    animPath.mPath.mData.mOffset = 0i64;
    animPath.mPath.mCount = v7 & 0x80000000;
  }
  return v6;
}

