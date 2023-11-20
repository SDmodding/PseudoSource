// File Line: 48
// RVA: 0x5C5230
void __fastcall UFG::UIHKScreenFightTutorial::UIHKScreenFightTutorial(UFG::UIHKScreenFightTutorial *this)
{
  UFG::UIHKScreenFightTutorial *v1; // rbx
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v2; // rax

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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenFightTutorial::`vftable;
  UFG::UIHKMoveSequenceData::UIHKMoveSequenceData(&this->mMoveSequence);
  v1->mInputIndex = 1;
  v1->mPendingReset = 0;
  *(_QWORD *)&v1->mResetLimit = 1065353216i64;
  v1->mHelpbarLocked = 0;
}

// File Line: 53
// RVA: 0x5CAAC0
void __fastcall UFG::UIHKScreenFightTutorial::~UIHKScreenFightTutorial(UFG::UIHKScreenFightTutorial *this)
{
  UFG::UIHKScreenFightTutorial *v1; // rbx
  UFG::UIScreenTextureManager *v2; // rax
  int v3; // eax
  UFG::UIHKScreenGlobalOverlay *v4; // rax
  int v5; // eax

  v1 = this;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenFightTutorial::`vftable;
  v2 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v2, "FightingTutorial");
  if ( v1->mHelpbarLocked )
  {
    v3 = UFG::UIHKHelpBarWidget::mLocked;
    if ( UFG::UIHKHelpBarWidget::mLocked > 0 )
      v3 = UFG::UIHKHelpBarWidget::mLocked-- - 1;
    if ( v3 < 1 )
    {
      v4 = UFG::UIHKScreenGlobalOverlay::mThis;
      if ( !UFG::UIHKScreenGlobalOverlay::mThis )
        v4 = &gGlobalOverlaySentinel;
      v4->HelpBar.mChanged = 1;
    }
    v5 = UFG::UIHKGameplayHelpWidget::mLocked;
    if ( UFG::UIHKGameplayHelpWidget::mLocked > 0 )
      v5 = UFG::UIHKGameplayHelpWidget::mLocked-- - 1;
    if ( v5 < 1 )
      UFG::UIHKScreenHud::GameplayHelp->mChanged = 1;
    v1->mHelpbarLocked = 0;
  }
  UFG::UIHKMoveSequenceData::~UIHKMoveSequenceData(&v1->mMoveSequence);
  UFG::UIScreen::~UIScreen((UFG::UIScreen *)&v1->vfptr);
}

// File Line: 61
// RVA: 0x631830
void __fastcall UFG::UIHKScreenFightTutorial::init(UFG::UIHKScreenFightTutorial *this, UFG::UICommandData *data)
{
  UFG::UIHKScreenFightTutorial *v2; // rbx
  Scaleform::GFx::Movie *v3; // rcx

  v2 = this;
  UFG::UIScreen::init((UFG::UIScreen *)&this->vfptr, data);
  v3 = v2->mRenderable->m_movie.pObject;
  if ( v3 )
  {
    Scaleform::GFx::Movie::Invoke(v3, "FightTutorial_InitSequence", 0i64, 0i64, 0);
    v2->mInputIndex = 1;
  }
  if ( !v2->mHelpbarLocked )
  {
    ++UFG::UIHKHelpBarWidget::mLocked;
    ++UFG::UIHKGameplayHelpWidget::mLocked;
    v2->mHelpbarLocked = 1;
  }
}

// File Line: 72
// RVA: 0x63CCB0
void __fastcall UFG::UIHKScreenFightTutorial::update(UFG::UIHKScreenFightTutorial *this, float elapsed)
{
  UFG::UIHKScreenFightTutorial *v2; // rbx
  float v3; // xmm6_4
  bool v4; // cf
  bool v5; // zf
  Scaleform::GFx::Movie *v6; // rcx

  v2 = this;
  UFG::UIScreen::update((UFG::UIScreen *)&this->vfptr, elapsed);
  if ( v2->mPendingReset )
  {
    v3 = elapsed + v2->mResetTimer;
    v4 = v3 < v2->mResetLimit;
    v5 = v3 == v2->mResetLimit;
    v2->mResetTimer = v3;
    if ( !v4 && !v5 )
    {
      v6 = v2->mRenderable->m_movie.pObject;
      if ( v6 )
      {
        Scaleform::GFx::Movie::Invoke(v6, "FightTutorial_InitSequence", 0i64, 0i64, 0);
        v2->mInputIndex = 1;
      }
      v2->mPendingReset = 0;
      v2->mResetTimer = 0.0;
    }
  }
}

// File Line: 90
// RVA: 0x622F70
bool __fastcall UFG::UIHKScreenFightTutorial::handleMessage(UFG::UIHKScreenFightTutorial *this, unsigned int msgId, UFG::UIMessage *msg)
{
  int v3; // eax
  UFG::UIHKScreenGlobalOverlay *v4; // rax
  int v5; // eax

  if ( msgId == UI_HASH_GAME_UNLOADING_30 || msgId == UI_HASH_GAME_OVER_20 )
  {
    UFG::UIScreenManagerBase::queuePopOverlay(
      (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
      this->mScreenUID);
    return 0;
  }
  if ( msgId != UI_HASH_GAME_PAUSE_20 )
  {
    if ( msgId == UI_HASH_GAME_UNPAUSE_20 )
    {
      this->mRenderable->m_shouldRender = 1;
      if ( !this->mHelpbarLocked )
      {
        ++UFG::UIHKHelpBarWidget::mLocked;
        ++UFG::UIHKGameplayHelpWidget::mLocked;
        this->mHelpbarLocked = 1;
        return 0;
      }
    }
    return 0;
  }
  this->mRenderable->m_shouldRender = 0;
  if ( !this->mHelpbarLocked )
    return 0;
  v3 = UFG::UIHKHelpBarWidget::mLocked;
  if ( UFG::UIHKHelpBarWidget::mLocked > 0 )
    v3 = UFG::UIHKHelpBarWidget::mLocked-- - 1;
  if ( v3 < 1 )
  {
    v4 = UFG::UIHKScreenGlobalOverlay::mThis;
    if ( !UFG::UIHKScreenGlobalOverlay::mThis )
      v4 = &gGlobalOverlaySentinel;
    v4->HelpBar.mChanged = 1;
  }
  v5 = UFG::UIHKGameplayHelpWidget::mLocked;
  if ( UFG::UIHKGameplayHelpWidget::mLocked > 0 )
    v5 = UFG::UIHKGameplayHelpWidget::mLocked-- - 1;
  if ( v5 < 1 )
    UFG::UIHKScreenHud::GameplayHelp->mChanged = 1;
  this->mHelpbarLocked = 0;
  return 0;
}

// File Line: 140
// RVA: 0x6075C0
void __fastcall UFG::UIHKScreenFightTutorial::SetSequence(UFG::UIHKScreenFightTutorial *this, const char *moveName, UFG::UI::eButtons button1, UFG::UIHKScreenFightTutorial::eButtonAction buttonAction1, UFG::UI::eButtons button2, UFG::UIHKScreenFightTutorial::eButtonAction buttonAction2, UFG::UIHKScreenFightTutorial::eButtonSeperator buttonSeperator2, UFG::UI::eButtons button3, UFG::UIHKScreenFightTutorial::eButtonAction buttonAction3, UFG::UIHKScreenFightTutorial::eButtonSeperator buttonSeperator3, UFG::UI::eButtons button4, UFG::UIHKScreenFightTutorial::eButtonAction buttonAction4, UFG::UIHKScreenFightTutorial::eButtonSeperator buttonSeperator4, UFG::UI::eButtons button5, UFG::UIHKScreenFightTutorial::eButtonAction buttonAction5, UFG::UIHKScreenFightTutorial::eButtonSeperator buttonSeperator5)
{
  UFG::UIHKScreenFightTutorial *v16; // rdi
  UFG::UIHKScreenFightTutorial::eButtonAction v17; // esi
  UFG::UI::eButtons v18; // ebp
  char *v19; // rax
  char *v20; // rax
  char *v21; // rax
  char *v22; // rax
  char *v23; // rax
  char *v24; // rbx
  unsigned int v25; // eax
  char *v26; // rdx
  char v27; // al
  char *v28; // rax
  unsigned int v29; // eax
  char *v30; // rdx
  char v31; // al
  char *v32; // rax
  unsigned int v33; // eax
  char *v34; // rdx
  char v35; // al
  char *v36; // rax
  unsigned int v37; // eax
  char *v38; // rdx
  char v39; // al
  char *v40; // rax
  unsigned int v41; // eax
  char v42; // al
  char *v43; // rax
  const char *v44; // rbx
  int v45; // esi
  int v46; // esi
  const char *v47; // rdx
  const char *v48; // rdx
  const char *v49; // rdx
  const char *v50; // rdx
  const char *v51; // rbx
  const char *v52; // rdx
  const char *v53; // rdx
  const char *v54; // rdx
  Scaleform::GFx::Movie *v55; // rcx

  v16 = this;
  v17 = buttonAction1;
  v18 = button1;
  UFG::qString::Set(&this->mMoveSequence.moveName, moveName);
  v19 = UFG::UI::GetGamepadButtonTextureName(v18, 1);
  UFG::qString::Set(&v16->mMoveSequence.button1, v19);
  v20 = UFG::UI::GetGamepadButtonTextureName(button2, 1);
  UFG::qString::Set(&v16->mMoveSequence.button2, v20);
  v21 = UFG::UI::GetGamepadButtonTextureName(button3, 1);
  UFG::qString::Set(&v16->mMoveSequence.button3, v21);
  v22 = UFG::UI::GetGamepadButtonTextureName(button4, 1);
  UFG::qString::Set(&v16->mMoveSequence.button4, v22);
  v23 = UFG::UI::GetGamepadButtonTextureName(button5, 1);
  UFG::qString::Set(&v16->mMoveSequence.button5, v23);
  v24 = &customWorldMapCaption;
  if ( !UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
  {
    v28 = UFG::UI::GetGamepadButtonTextureName(v18, 1);
    goto LABEL_7;
  }
  v25 = UFG::UIHKScreenOptionsButtonMapping::ButtonToRemapId(v18, 0);
  v26 = &customWorldMapCaption;
  if ( v25 != REMAP_ID_INVALID_2 )
  {
    v27 = UFG::UIHKScreenOptionsButtonMapping::GetKey(v25);
    v26 = (char *)UFG::KeyToTextureName(v27);
  }
  if ( !*v26 )
  {
    v28 = UFG::UI::GetKeyboardButtonTextureNameNonRemappable(v18);
LABEL_7:
    v26 = v28;
  }
  UFG::qString::Set(&v16->mMoveSequence.button1tex, v26);
  if ( !UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
  {
    v32 = UFG::UI::GetGamepadButtonTextureName(button2, 1);
    goto LABEL_14;
  }
  v29 = UFG::UIHKScreenOptionsButtonMapping::ButtonToRemapId(button2, 0);
  v30 = &customWorldMapCaption;
  if ( v29 != REMAP_ID_INVALID_2 )
  {
    v31 = UFG::UIHKScreenOptionsButtonMapping::GetKey(v29);
    v30 = (char *)UFG::KeyToTextureName(v31);
  }
  if ( !*v30 )
  {
    v32 = UFG::UI::GetKeyboardButtonTextureNameNonRemappable(button2);
LABEL_14:
    v30 = v32;
  }
  UFG::qString::Set(&v16->mMoveSequence.button2tex, v30);
  if ( !UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
  {
    v36 = UFG::UI::GetGamepadButtonTextureName(button3, 1);
    goto LABEL_21;
  }
  v33 = UFG::UIHKScreenOptionsButtonMapping::ButtonToRemapId(button3, 0);
  v34 = &customWorldMapCaption;
  if ( v33 != REMAP_ID_INVALID_2 )
  {
    v35 = UFG::UIHKScreenOptionsButtonMapping::GetKey(v33);
    v34 = (char *)UFG::KeyToTextureName(v35);
  }
  if ( !*v34 )
  {
    v36 = UFG::UI::GetKeyboardButtonTextureNameNonRemappable(button3);
LABEL_21:
    v34 = v36;
  }
  UFG::qString::Set(&v16->mMoveSequence.button3tex, v34);
  if ( !UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
  {
    v40 = UFG::UI::GetGamepadButtonTextureName(button4, 1);
    goto LABEL_28;
  }
  v37 = UFG::UIHKScreenOptionsButtonMapping::ButtonToRemapId(button4, 0);
  v38 = &customWorldMapCaption;
  if ( v37 != REMAP_ID_INVALID_2 )
  {
    v39 = UFG::UIHKScreenOptionsButtonMapping::GetKey(v37);
    v38 = (char *)UFG::KeyToTextureName(v39);
  }
  if ( !*v38 )
  {
    v40 = UFG::UI::GetKeyboardButtonTextureNameNonRemappable(button4);
LABEL_28:
    v38 = v40;
  }
  UFG::qString::Set(&v16->mMoveSequence.button4tex, v38);
  if ( !UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
  {
    v43 = UFG::UI::GetGamepadButtonTextureName(button5, 1);
    goto LABEL_35;
  }
  v41 = UFG::UIHKScreenOptionsButtonMapping::ButtonToRemapId(button5, 0);
  if ( v41 != REMAP_ID_INVALID_2 )
  {
    v42 = UFG::UIHKScreenOptionsButtonMapping::GetKey(v41);
    v24 = (char *)UFG::KeyToTextureName(v42);
  }
  if ( !*v24 )
  {
    v43 = UFG::UI::GetKeyboardButtonTextureNameNonRemappable(button5);
LABEL_35:
    v24 = v43;
  }
  UFG::qString::Set(&v16->mMoveSequence.button5tex, v24);
  v44 = "BUTTON_ACCEPT";
  if ( v17 )
  {
    v45 = v17 - 1;
    if ( !v45 )
    {
      v47 = "inactive";
      goto LABEL_44;
    }
    v46 = v45 - 1;
    if ( !v46 )
    {
      v47 = "inactive_hold";
      goto LABEL_44;
    }
    if ( v46 == 1 )
    {
      v47 = "inactive_tap";
      goto LABEL_44;
    }
  }
  v47 = "BUTTON_ACCEPT";
LABEL_44:
  UFG::qString::Set(&v16->mMoveSequence.action1, v47);
  if ( buttonAction2 )
  {
    switch ( buttonAction2 )
    {
      case 1:
        v48 = "inactive";
        goto LABEL_52;
      case 2:
        v48 = "inactive_hold";
        goto LABEL_52;
      case 3:
        v48 = "inactive_tap";
        goto LABEL_52;
    }
  }
  v48 = "BUTTON_ACCEPT";
LABEL_52:
  UFG::qString::Set(&v16->mMoveSequence.action2, v48);
  if ( buttonAction3 )
  {
    switch ( buttonAction3 )
    {
      case 1:
        v49 = "inactive";
        goto LABEL_60;
      case 2:
        v49 = "inactive_hold";
        goto LABEL_60;
      case 3:
        v49 = "inactive_tap";
        goto LABEL_60;
    }
  }
  v49 = "BUTTON_ACCEPT";
LABEL_60:
  UFG::qString::Set(&v16->mMoveSequence.action3, v49);
  if ( buttonAction4 )
  {
    switch ( buttonAction4 )
    {
      case 1:
        v50 = "inactive";
        goto LABEL_68;
      case 2:
        v50 = "inactive_hold";
        goto LABEL_68;
      case 3:
        v50 = "inactive_tap";
        goto LABEL_68;
    }
  }
  v50 = "BUTTON_ACCEPT";
LABEL_68:
  UFG::qString::Set(&v16->mMoveSequence.action4, v50);
  if ( buttonAction5 )
  {
    switch ( buttonAction5 )
    {
      case 1:
        v44 = "inactive";
        break;
      case 2:
        v44 = "inactive_hold";
        break;
      case 3:
        v44 = "inactive_tap";
        break;
    }
  }
  UFG::qString::Set(&v16->mMoveSequence.action5, v44);
  v51 = "comma";
  if ( buttonSeperator2 )
  {
    if ( buttonSeperator2 != 1 && buttonSeperator2 == 2 )
      v52 = "plus";
    else
      v52 = "comma";
  }
  else
  {
    v52 = "invalid";
  }
  UFG::qString::Set(&v16->mMoveSequence.seperator2, v52);
  if ( buttonSeperator3 )
  {
    if ( buttonSeperator3 != 1 && buttonSeperator3 == 2 )
      v53 = "plus";
    else
      v53 = "comma";
  }
  else
  {
    v53 = "invalid";
  }
  UFG::qString::Set(&v16->mMoveSequence.seperator3, v53);
  if ( buttonSeperator4 )
  {
    if ( buttonSeperator4 != 1 && buttonSeperator4 == 2 )
      v54 = "plus";
    else
      v54 = "comma";
  }
  else
  {
    v54 = "invalid";
  }
  UFG::qString::Set(&v16->mMoveSequence.seperator4, v54);
  if ( buttonSeperator5 )
  {
    if ( buttonSeperator5 != 1 && buttonSeperator5 == 2 )
      v51 = "plus";
  }
  else
  {
    v51 = "invalid";
  }
  UFG::qString::Set(&v16->mMoveSequence.seperator5, v51);
  UFG::UIHKScreenFightTutorial::SetSequenceInFlash(v16);
  v55 = v16->mRenderable->m_movie.pObject;
  if ( v55 )
  {
    Scaleform::GFx::Movie::Invoke(v55, "FightTutorial_InitSequence", 0i64, 0i64, 0);
    v16->mInputIndex = 1;
  }
}

// File Line: 170
// RVA: 0x5ED700
void __fastcall UFG::UIHKScreenFightTutorial::InitSequence(UFG::UIHKScreenFightTutorial *this)
{
  UFG::UIHKScreenFightTutorial *v1; // rbx
  Scaleform::GFx::Movie *v2; // rcx

  v1 = this;
  v2 = this->mRenderable->m_movie.pObject;
  if ( v2 )
  {
    Scaleform::GFx::Movie::Invoke(v2, "FightTutorial_InitSequence", 0i64, 0i64, 0);
    v1->mInputIndex = 1;
  }
}

// File Line: 180
// RVA: 0x607B30
void __fastcall UFG::UIHKScreenFightTutorial::SetSequenceInFlash(UFG::UIHKScreenFightTutorial *this)
{
  UFG::UIHKScreenFightTutorial *v1; // rdi
  Scaleform::GFx::Movie *v2; // r14
  __int64 *v3; // rbx
  signed __int64 v4; // rsi
  __int64 v5; // rbx
  __int64 v6; // rbx
  __int64 v7; // rbx
  __int64 v8; // rbx
  __int64 v9; // rbx
  __int64 v10; // rbx
  __int64 v11; // rbx
  __int64 v12; // rbx
  __int64 v13; // rbx
  __int64 v14; // rbx
  __int64 v15; // rbx
  __int64 v16; // rbx
  __int64 v17; // rbx
  __int64 v18; // rbx
  __int64 v19; // rbx
  char ptr; // [rsp+30h] [rbp-B8h]
  __int64 v21; // [rsp+40h] [rbp-A8h]
  unsigned int v22; // [rsp+48h] [rbp-A0h]
  __int64 v23; // [rsp+50h] [rbp-98h]
  char v24; // [rsp+60h] [rbp-88h]
  __int64 v25; // [rsp+68h] [rbp-80h]
  __int64 v26; // [rsp+70h] [rbp-78h]
  unsigned int v27; // [rsp+78h] [rbp-70h]
  __int64 v28; // [rsp+88h] [rbp-60h]
  unsigned int v29; // [rsp+90h] [rbp-58h]
  __int64 v30; // [rsp+98h] [rbp-50h]
  char v31; // [rsp+A8h] [rbp-40h]
  __int64 v32; // [rsp+B8h] [rbp-30h]
  unsigned int v33; // [rsp+C0h] [rbp-28h]
  __int64 v34; // [rsp+C8h] [rbp-20h]
  char v35; // [rsp+D8h] [rbp-10h]
  __int64 v36; // [rsp+E8h] [rbp+0h]
  unsigned int v37; // [rsp+F0h] [rbp+8h]
  __int64 v38; // [rsp+F8h] [rbp+10h]
  char v39; // [rsp+108h] [rbp+20h]
  __int64 v40; // [rsp+118h] [rbp+30h]
  unsigned int v41; // [rsp+120h] [rbp+38h]
  __int64 v42; // [rsp+128h] [rbp+40h]
  char v43; // [rsp+138h] [rbp+50h]
  __int64 v44; // [rsp+148h] [rbp+60h]
  unsigned int v45; // [rsp+150h] [rbp+68h]
  __int64 v46; // [rsp+158h] [rbp+70h]
  char v47; // [rsp+168h] [rbp+80h]
  __int64 v48; // [rsp+178h] [rbp+90h]
  unsigned int v49; // [rsp+180h] [rbp+98h]
  __int64 v50; // [rsp+188h] [rbp+A0h]
  char v51; // [rsp+198h] [rbp+B0h]
  __int64 v52; // [rsp+1A8h] [rbp+C0h]
  unsigned int v53; // [rsp+1B0h] [rbp+C8h]
  __int64 v54; // [rsp+1B8h] [rbp+D0h]
  char v55; // [rsp+1C8h] [rbp+E0h]
  __int64 v56; // [rsp+1D8h] [rbp+F0h]
  unsigned int v57; // [rsp+1E0h] [rbp+F8h]
  __int64 v58; // [rsp+1E8h] [rbp+100h]
  char v59; // [rsp+1F8h] [rbp+110h]
  __int64 v60; // [rsp+208h] [rbp+120h]
  unsigned int v61; // [rsp+210h] [rbp+128h]
  __int64 v62; // [rsp+218h] [rbp+130h]
  char v63; // [rsp+228h] [rbp+140h]
  __int64 v64; // [rsp+238h] [rbp+150h]
  unsigned int v65; // [rsp+240h] [rbp+158h]
  __int64 v66; // [rsp+248h] [rbp+160h]
  char v67; // [rsp+258h] [rbp+170h]
  __int64 v68; // [rsp+268h] [rbp+180h]
  unsigned int v69; // [rsp+270h] [rbp+188h]
  __int64 v70; // [rsp+278h] [rbp+190h]
  char v71; // [rsp+288h] [rbp+1A0h]
  __int64 v72; // [rsp+298h] [rbp+1B0h]
  unsigned int v73; // [rsp+2A0h] [rbp+1B8h]
  __int64 v74; // [rsp+2A8h] [rbp+1C0h]
  char v75; // [rsp+2B8h] [rbp+1D0h]
  __int64 v76; // [rsp+2C8h] [rbp+1E0h]
  unsigned int v77; // [rsp+2D0h] [rbp+1E8h]
  __int64 v78; // [rsp+2D8h] [rbp+1F0h]
  __int64 v79; // [rsp+2E8h] [rbp+200h]

  v79 = -2i64;
  v1 = this;
  v2 = this->mRenderable->m_movie.pObject;
  if ( v2 )
  {
    `eh vector constructor iterator(&ptr, 0x30ui64, 15, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    v3 = &v21;
    v4 = 15i64;
    do
    {
      if ( (*((_DWORD *)v3 + 2) >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, __int64 *, __int64))(*(_QWORD *)*v3 + 16i64))(*v3, v3 - 2, v3[2]);
        *v3 = 0i64;
      }
      *((_DWORD *)v3 + 2) = 0;
      v3 += 6;
      --v4;
    }
    while ( v4 );
    v5 = (__int64)v1->mMoveSequence.moveName.mData;
    if ( (v22 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v21 + 16i64))(v21, &ptr, v23);
      v21 = 0i64;
    }
    v22 = 6;
    v23 = v5;
    if ( (unsigned int)UFG::qStringCompare(v1->mMoveSequence.button1tex.mData, &customWorldMapCaption, -1) )
    {
      v6 = (__int64)v1->mMoveSequence.button1tex.mData;
      if ( (v27 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v26 + 16i64))(v26, &v24, v25);
        v26 = 0i64;
      }
      v27 = 6;
      v25 = v6;
      v7 = (__int64)v1->mMoveSequence.action1.mData;
      if ( (v29 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, unsigned int *, __int64))(*(_QWORD *)v28 + 16i64))(v28, &v27, v30);
        v28 = 0i64;
      }
      v29 = 6;
      v30 = v7;
    }
    if ( (unsigned int)UFG::qStringCompare(v1->mMoveSequence.button2tex.mData, &customWorldMapCaption, -1) )
    {
      v8 = (__int64)v1->mMoveSequence.button2tex.mData;
      if ( (v33 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v32 + 16i64))(v32, &v31, v34);
        v32 = 0i64;
      }
      v33 = 6;
      v34 = v8;
      v9 = (__int64)v1->mMoveSequence.action2.mData;
      if ( (v37 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v36 + 16i64))(v36, &v35, v38);
        v36 = 0i64;
      }
      v37 = 6;
      v38 = v9;
      v10 = (__int64)v1->mMoveSequence.seperator2.mData;
      if ( (v41 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v40 + 16i64))(v40, &v39, v42);
        v40 = 0i64;
      }
      v41 = 6;
      v42 = v10;
    }
    if ( (unsigned int)UFG::qStringCompare(v1->mMoveSequence.button3tex.mData, &customWorldMapCaption, -1) )
    {
      v11 = (__int64)v1->mMoveSequence.button3tex.mData;
      if ( (v45 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v44 + 16i64))(v44, &v43, v46);
        v44 = 0i64;
      }
      v45 = 6;
      v46 = v11;
      v12 = (__int64)v1->mMoveSequence.action3.mData;
      if ( (v49 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v48 + 16i64))(v48, &v47, v50);
        v48 = 0i64;
      }
      v49 = 6;
      v50 = v12;
      v13 = (__int64)v1->mMoveSequence.seperator3.mData;
      if ( (v53 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v52 + 16i64))(v52, &v51, v54);
        v52 = 0i64;
      }
      v53 = 6;
      v54 = v13;
    }
    if ( (unsigned int)UFG::qStringCompare(v1->mMoveSequence.button4tex.mData, &customWorldMapCaption, -1) )
    {
      v14 = (__int64)v1->mMoveSequence.button4tex.mData;
      if ( (v57 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v56 + 16i64))(v56, &v55, v58);
        v56 = 0i64;
      }
      v57 = 6;
      v58 = v14;
      v15 = (__int64)v1->mMoveSequence.action4.mData;
      if ( (v61 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v60 + 16i64))(v60, &v59, v62);
        v60 = 0i64;
      }
      v61 = 6;
      v62 = v15;
      v16 = (__int64)v1->mMoveSequence.seperator4.mData;
      if ( (v65 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v64 + 16i64))(v64, &v63, v66);
        v64 = 0i64;
      }
      v65 = 6;
      v66 = v16;
    }
    if ( (unsigned int)UFG::qStringCompare(v1->mMoveSequence.button5tex.mData, &customWorldMapCaption, -1) )
    {
      v17 = (__int64)v1->mMoveSequence.button5tex.mData;
      if ( (v69 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v68 + 16i64))(v68, &v67, v70);
        v68 = 0i64;
      }
      v69 = 6;
      v70 = v17;
      v18 = (__int64)v1->mMoveSequence.action5.mData;
      if ( (v73 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v72 + 16i64))(v72, &v71, v74);
        v72 = 0i64;
      }
      v73 = 6;
      v74 = v18;
      v19 = (__int64)v1->mMoveSequence.seperator5.mData;
      if ( (v77 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v76 + 16i64))(v76, &v75, v78);
        v76 = 0i64;
      }
      v77 = 6;
      v78 = v19;
    }
    Scaleform::GFx::Movie::Invoke(v2, "FightTutorial_SetSequence", 0i64, (Scaleform::GFx::Value *)&ptr, 0xFu);
    `eh vector destructor iterator(&ptr, 0x30ui64, 15, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
} }
    Scaleform::GFx::Movie::Invoke(v2, "FightTutorial_SetSequence", 0i64, (Scaleform::GFx::Value *)&ptr, 0xFu);
    `eh vecto

// File Line: 275
// RVA: 0x5ED3B0
void __fastcall UFG::UIHKScreenFightTutorial::HitSuccess(UFG::UIHKScreenFightTutorial *this, int index)
{
  int v2; // edi
  Scaleform::GFx::Movie *v3; // rbx
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h]

  v2 = index;
  v3 = this->mRenderable->m_movie.pObject;
  if ( v3 )
  {
    `eh vector constructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( ((unsigned int)pargs.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        *(_QWORD *)&pargs.mValue.NValue);
      pargs.pObjectInterface = 0i64;
    }
    pargs.Type = 5;
    pargs.mValue.NValue = (double)v2;
    Scaleform::GFx::Movie::Invoke(v3, "FightTutorial_HitSuccess", 0i64, &pargs, 1u);
    `eh vector destructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 289
// RVA: 0x5ED2C0
void __fastcall UFG::UIHKScreenFightTutorial::HitFailed(UFG::UIHKScreenFightTutorial *this, int index)
{
  int v2; // esi
  UFG::UIHKScreenFightTutorial *v3; // rbx
  Scaleform::GFx::Movie *v4; // rdi
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h]

  v2 = index;
  v3 = this;
  v4 = this->mRenderable->m_movie.pObject;
  if ( v4 )
  {
    `eh vector constructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( ((unsigned int)pargs.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        *(_QWORD *)&pargs.mValue.NValue);
      pargs.pObjectInterface = 0i64;
    }
    pargs.Type = 5;
    pargs.mValue.NValue = (double)v2;
    Scaleform::GFx::Movie::Invoke(v4, "FightTutorial_HitFailed", 0i64, &pargs, 1u);
    v3->mResetTimer = 0.0;
    `eh vector destructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 306
// RVA: 0x5F4270
void UFG::UIHKScreenFightTutorial::Pop(void)
{
  UFG::UIScreenManagerBase::queuePopOverlay(
    (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
    "FightingTutorial");
}

// File Line: 312
// RVA: 0x60C660
void __fastcall UFG::UIHKScreenFightTutorial::SetVisible(UFG::UIHKScreenFightTutorial *this, bool visible)
{
  this->mRenderable->m_shouldRender = visible;
}

// File Line: 351
// RVA: 0x5E6940
signed __int64 __fastcall UFG::UIHKScreenFightTutorial::GetAction(const char *text)
{
  const char *v1; // rbx
  int v3; // eax
  unsigned int v4; // ecx

  v1 = text;
  if ( !text )
    return 0i64;
  if ( !(unsigned int)UFG::qStringCompare(text, "press", -1) )
    return 1i64;
  if ( !(unsigned int)UFG::qStringCompare(v1, "hold", -1) )
    return 2i64;
  v3 = UFG::qStringCompare(v1, "tap", -1);
  v4 = 0;
  if ( !v3 )
    v4 = 3;
  return v4;
}

// File Line: 363
// RVA: 0x5E93E0
signed __int64 __fastcall UFG::UIHKScreenFightTutorial::GetSeperator(const char *text)
{
  const char *v1; // rbx
  int v3; // eax
  unsigned int v4; // ecx

  v1 = text;
  if ( !text )
    return 0i64;
  if ( !(unsigned int)UFG::qStringCompare(text, "comma", -1) )
    return 1i64;
  v3 = UFG::qStringCompare(v1, "plus", -1);
  v4 = 0;
  if ( !v3 )
    v4 = 2;
  return v4;
}

// File Line: 374
// RVA: 0x5EE8A0
bool __fastcall UFG::UIHKScreenFightTutorial::IsSuccess(UFG::UIHKScreenFightTutorial *this)
{
  Scaleform::GFx::Movie *v1; // rcx
  bool v3; // bl
  Scaleform::GFx::Value pval; // [rsp+28h] [rbp-40h]

  v1 = this->mRenderable->m_movie.pObject;
  if ( !v1 )
    return 0;
  pval.pObjectInterface = 0i64;
  pval.Type = 0;
  Scaleform::GFx::Movie::GetVariable(v1, &pval, "gSequenceSuccessful");
  v3 = pval.mValue.BValue;
  if ( ((unsigned int)pval.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pval.pObjectInterface->vfptr->gap8[8])(
      pval.pObjectInterface,
      &pval,
      *(_QWORD *)&pval.mValue.NValue);
    pval.pObjectInterface = 0i64;
  }
  return v3;
}

// File Line: 386
// RVA: 0x5D4550
void __fastcall UFG::UIHKScreenFightTutorial::ButtonPressed(UFG::UIHKScreenFightTutorial *this, const char *buttonName)
{
  UFG::UIHKScreenFightTutorial *v2; // rbx
  const char *v3; // rdi
  int v4; // ecx
  int v5; // ecx
  int v6; // ecx
  int v7; // ecx
  const char *v8; // rcx

  v2 = this;
  v3 = buttonName;
  v4 = this->mInputIndex - 1;
  if ( !v4 )
  {
    if ( (unsigned int)UFG::qStringCompare(v2->mMoveSequence.action1.mData, "inactive", -1) )
      goto LABEL_18;
    v8 = v2->mMoveSequence.button1.mData;
    goto LABEL_16;
  }
  v5 = v4 - 1;
  if ( !v5 )
  {
    if ( (unsigned int)UFG::qStringCompare(v2->mMoveSequence.action2.mData, "inactive", -1) )
      goto LABEL_18;
    v8 = v2->mMoveSequence.button2.mData;
    goto LABEL_16;
  }
  v6 = v5 - 1;
  if ( !v6 )
  {
    if ( (unsigned int)UFG::qStringCompare(v2->mMoveSequence.action3.mData, "inactive", -1) )
      goto LABEL_18;
    v8 = v2->mMoveSequence.button3.mData;
    goto LABEL_16;
  }
  v7 = v6 - 1;
  if ( !v7 )
  {
    if ( (unsigned int)UFG::qStringCompare(v2->mMoveSequence.action4.mData, "inactive", -1) )
      goto LABEL_18;
    v8 = v2->mMoveSequence.button4.mData;
LABEL_16:
    if ( !(unsigned int)UFG::qStringCompare(v8, v3, -1) )
    {
      UFG::UIHKScreenFightTutorial::HitSuccess(v2, v2->mInputIndex);
      ++v2->mInputIndex;
      return;
    }
    goto LABEL_18;
  }
  if ( v7 == 1 )
  {
    if ( !(unsigned int)UFG::qStringCompare(v2->mMoveSequence.action5.mData, "inactive", -1) )
    {
      v8 = v2->mMoveSequence.button5.mData;
      goto LABEL_16;
    }
LABEL_18:
    UFG::UIHKScreenFightTutorial::HitFailed(v2, v2->mInputIndex);
  }
  ++v2->mInputIndex;
}

// File Line: 426
// RVA: 0x5D4400
void __fastcall UFG::UIHKScreenFightTutorial::ButtonHeld(UFG::UIHKScreenFightTutorial *this, const char *buttonName)
{
  UFG::UIHKScreenFightTutorial *v2; // rbx
  const char *v3; // rdi
  int v4; // ecx
  int v5; // ecx
  int v6; // ecx
  int v7; // ecx
  const char *v8; // rcx

  v2 = this;
  v3 = buttonName;
  v4 = this->mInputIndex - 1;
  if ( !v4 )
  {
    if ( (unsigned int)UFG::qStringCompare(v2->mMoveSequence.action1.mData, "inactive_hold", -1) )
      goto LABEL_18;
    v8 = v2->mMoveSequence.button1.mData;
    goto LABEL_16;
  }
  v5 = v4 - 1;
  if ( !v5 )
  {
    if ( (unsigned int)UFG::qStringCompare(v2->mMoveSequence.action2.mData, "inactive_hold", -1) )
      goto LABEL_18;
    v8 = v2->mMoveSequence.button2.mData;
    goto LABEL_16;
  }
  v6 = v5 - 1;
  if ( !v6 )
  {
    if ( (unsigned int)UFG::qStringCompare(v2->mMoveSequence.action3.mData, "inactive_hold", -1) )
      goto LABEL_18;
    v8 = v2->mMoveSequence.button3.mData;
    goto LABEL_16;
  }
  v7 = v6 - 1;
  if ( !v7 )
  {
    if ( (unsigned int)UFG::qStringCompare(v2->mMoveSequence.action4.mData, "inactive_hold", -1) )
      goto LABEL_18;
    v8 = v2->mMoveSequence.button4.mData;
LABEL_16:
    if ( !(unsigned int)UFG::qStringCompare(v8, v3, -1) )
    {
      UFG::UIHKScreenFightTutorial::HitSuccess(v2, v2->mInputIndex);
      ++v2->mInputIndex;
      return;
    }
    goto LABEL_18;
  }
  if ( v7 == 1 )
  {
    if ( !(unsigned int)UFG::qStringCompare(v2->mMoveSequence.action5.mData, "inactive_hold", -1) )
    {
      v8 = v2->mMoveSequence.button5.mData;
      goto LABEL_16;
    }
LABEL_18:
    UFG::UIHKScreenFightTutorial::HitFailed(v2, v2->mInputIndex);
  }
  ++v2->mInputIndex;
}

