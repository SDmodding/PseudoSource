// File Line: 48
// RVA: 0x5C5230
void __fastcall UFG::UIHKScreenFightTutorial::UIHKScreenFightTutorial(UFG::UIHKScreenFightTutorial *this)
{
  this->mPrev = &this->UFG::qNode<UFG::UIScreen,UFG::UIScreen>;
  this->mNext = &this->UFG::qNode<UFG::UIScreen,UFG::UIScreen>;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIScreen::`vftable;
  this->m_screenNameHash = 0;
  this->UFG::UIScreen::mRenderable = 0i64;
  this->mLoadThread = 0i64;
  this->mScreenUID = -1;
  *(_QWORD *)&this->mControllerMask = 15i64;
  *(_QWORD *)&this->mPriority = 0i64;
  this->mDimToApplyType = eDIM_INVALID;
  *(_QWORD *)&this->mCurDimValue = 1120403456i64;
  this->m_screenName[0] = 0;
  --this->mInputEnabled;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenFightTutorial::`vftable;
  UFG::UIHKMoveSequenceData::UIHKMoveSequenceData(&this->mMoveSequence);
  this->mInputIndex = 1;
  this->mPendingReset = 0;
  *(_QWORD *)&this->mResetLimit = 1065353216i64;
  this->mHelpbarLocked = 0;
}

// File Line: 53
// RVA: 0x5CAAC0
void __fastcall UFG::UIHKScreenFightTutorial::~UIHKScreenFightTutorial(UFG::UIHKScreenFightTutorial *this)
{
  UFG::UIScreenTextureManager *v2; // rax
  int v3; // eax
  UFG::UIHKScreenGlobalOverlay *v4; // rax
  int v5; // eax

  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenFightTutorial::`vftable;
  v2 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v2, "FightingTutorial");
  if ( this->mHelpbarLocked )
  {
    v3 = UFG::UIHKHelpBarWidget::mLocked;
    if ( UFG::UIHKHelpBarWidget::mLocked > 0 )
      v3 = --UFG::UIHKHelpBarWidget::mLocked;
    if ( v3 < 1 )
    {
      v4 = UFG::UIHKScreenGlobalOverlay::mThis;
      if ( !UFG::UIHKScreenGlobalOverlay::mThis )
        v4 = &gGlobalOverlaySentinel;
      v4->HelpBar.mChanged = 1;
    }
    v5 = UFG::UIHKGameplayHelpWidget::mLocked;
    if ( UFG::UIHKGameplayHelpWidget::mLocked > 0 )
      v5 = --UFG::UIHKGameplayHelpWidget::mLocked;
    if ( v5 < 1 )
      UFG::UIHKScreenHud::GameplayHelp->mChanged = 1;
    this->mHelpbarLocked = 0;
  }
  UFG::UIHKMoveSequenceData::~UIHKMoveSequenceData(&this->mMoveSequence);
  UFG::UIScreen::~UIScreen(this);
}

// File Line: 61
// RVA: 0x631830
void __fastcall UFG::UIHKScreenFightTutorial::init(UFG::UIHKScreenFightTutorial *this, UFG::UICommandData *data)
{
  Scaleform::GFx::Movie *pObject; // rcx

  UFG::UIScreen::init(this, data);
  pObject = this->UFG::UIScreen::mRenderable->m_movie.pObject;
  if ( pObject )
  {
    Scaleform::GFx::Movie::Invoke(pObject, "FightTutorial_InitSequence", 0i64, 0i64, 0);
    this->mInputIndex = 1;
  }
  if ( !this->mHelpbarLocked )
  {
    ++UFG::UIHKHelpBarWidget::mLocked;
    ++UFG::UIHKGameplayHelpWidget::mLocked;
    this->mHelpbarLocked = 1;
  }
}

// File Line: 72
// RVA: 0x63CCB0
void __fastcall UFG::UIHKScreenFightTutorial::update(UFG::UIHKScreenFightTutorial *this, float elapsed)
{
  float v3; // xmm6_4
  bool v4; // cc
  Scaleform::GFx::Movie *pObject; // rcx

  UFG::UIScreen::update(this, elapsed);
  if ( this->mPendingReset )
  {
    v3 = elapsed + this->mResetTimer;
    v4 = v3 <= this->mResetLimit;
    this->mResetTimer = v3;
    if ( !v4 )
    {
      pObject = this->UFG::UIScreen::mRenderable->m_movie.pObject;
      if ( pObject )
      {
        Scaleform::GFx::Movie::Invoke(pObject, "FightTutorial_InitSequence", 0i64, 0i64, 0);
        this->mInputIndex = 1;
      }
      this->mPendingReset = 0;
      this->mResetTimer = 0.0;
    }
  }
}

// File Line: 90
// RVA: 0x622F70
bool __fastcall UFG::UIHKScreenFightTutorial::handleMessage(
        UFG::UIHKScreenFightTutorial *this,
        unsigned int msgId,
        UFG::UIMessage *msg)
{
  int v3; // eax
  UFG::UIHKScreenGlobalOverlay *v4; // rax
  int v5; // eax

  if ( msgId == UI_HASH_GAME_UNLOADING_30 || msgId == UI_HASH_GAME_OVER_20 )
  {
    UFG::UIScreenManagerBase::queuePopOverlay(UFG::UIScreenManager::s_instance, this->mScreenUID);
    return 0;
  }
  if ( msgId != UI_HASH_GAME_PAUSE_20 )
  {
    if ( msgId == UI_HASH_GAME_UNPAUSE_20 )
    {
      this->UFG::UIScreen::mRenderable->m_shouldRender = 1;
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
  this->UFG::UIScreen::mRenderable->m_shouldRender = 0;
  if ( !this->mHelpbarLocked )
    return 0;
  v3 = UFG::UIHKHelpBarWidget::mLocked;
  if ( UFG::UIHKHelpBarWidget::mLocked > 0 )
    v3 = --UFG::UIHKHelpBarWidget::mLocked;
  if ( v3 < 1 )
  {
    v4 = UFG::UIHKScreenGlobalOverlay::mThis;
    if ( !UFG::UIHKScreenGlobalOverlay::mThis )
      v4 = &gGlobalOverlaySentinel;
    v4->HelpBar.mChanged = 1;
  }
  v5 = UFG::UIHKGameplayHelpWidget::mLocked;
  if ( UFG::UIHKGameplayHelpWidget::mLocked > 0 )
    v5 = --UFG::UIHKGameplayHelpWidget::mLocked;
  if ( v5 < 1 )
    UFG::UIHKScreenHud::GameplayHelp->mChanged = 1;
  this->mHelpbarLocked = 0;
  return 0;
}

// File Line: 140
// RVA: 0x6075C0
void __fastcall UFG::UIHKScreenFightTutorial::SetSequence(
        UFG::UIHKScreenFightTutorial *this,
        const char *moveName,
        UFG::UI::eButtons button1,
        UFG::UIHKScreenFightTutorial::eButtonAction buttonAction1,
        UFG::UI::eButtons button2,
        UFG::UIHKScreenFightTutorial::eButtonAction buttonAction2,
        UFG::UIHKScreenFightTutorial::eButtonSeperator buttonSeperator2,
        UFG::UI::eButtons button3,
        UFG::UIHKScreenFightTutorial::eButtonAction buttonAction3,
        UFG::UIHKScreenFightTutorial::eButtonSeperator buttonSeperator3,
        UFG::UI::eButtons button4,
        UFG::UIHKScreenFightTutorial::eButtonAction buttonAction4,
        UFG::UIHKScreenFightTutorial::eButtonSeperator buttonSeperator4,
        UFG::UI::eButtons button5,
        UFG::UIHKScreenFightTutorial::eButtonAction buttonAction5,
        UFG::UIHKScreenFightTutorial::eButtonSeperator buttonSeperator5)
{
  char *GamepadButtonTextureName; // rax
  char *v20; // rax
  char *v21; // rax
  char *v22; // rax
  char *v23; // rax
  char *v24; // rbx
  unsigned int v25; // eax
  char *v26; // rdx
  char Key; // al
  char *KeyboardButtonTextureNameNonRemappable; // rax
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
  Scaleform::GFx::Movie *pObject; // rcx

  UFG::qString::Set(&this->mMoveSequence.moveName, moveName);
  GamepadButtonTextureName = UFG::UI::GetGamepadButtonTextureName(button1, 1);
  UFG::qString::Set(&this->mMoveSequence.button1, GamepadButtonTextureName);
  v20 = UFG::UI::GetGamepadButtonTextureName(button2, 1);
  UFG::qString::Set(&this->mMoveSequence.button2, v20);
  v21 = UFG::UI::GetGamepadButtonTextureName(button3, 1);
  UFG::qString::Set(&this->mMoveSequence.button3, v21);
  v22 = UFG::UI::GetGamepadButtonTextureName(button4, 1);
  UFG::qString::Set(&this->mMoveSequence.button4, v22);
  v23 = UFG::UI::GetGamepadButtonTextureName(button5, 1);
  UFG::qString::Set(&this->mMoveSequence.button5, v23);
  v24 = &customCaption;
  if ( !UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
  {
    KeyboardButtonTextureNameNonRemappable = UFG::UI::GetGamepadButtonTextureName(button1, 1);
    goto LABEL_7;
  }
  v25 = UFG::UIHKScreenOptionsButtonMapping::ButtonToRemapId(button1, RemapContext_OnFoot);
  v26 = &customCaption;
  if ( v25 != REMAP_ID_INVALID_2 )
  {
    Key = UFG::UIHKScreenOptionsButtonMapping::GetKey(v25);
    v26 = (char *)UFG::KeyToTextureName(Key);
  }
  if ( !*v26 )
  {
    KeyboardButtonTextureNameNonRemappable = UFG::UI::GetKeyboardButtonTextureNameNonRemappable(button1);
LABEL_7:
    v26 = KeyboardButtonTextureNameNonRemappable;
  }
  UFG::qString::Set(&this->mMoveSequence.button1tex, v26);
  if ( !UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
  {
    v32 = UFG::UI::GetGamepadButtonTextureName(button2, 1);
    goto LABEL_14;
  }
  v29 = UFG::UIHKScreenOptionsButtonMapping::ButtonToRemapId(button2, RemapContext_OnFoot);
  v30 = &customCaption;
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
  UFG::qString::Set(&this->mMoveSequence.button2tex, v30);
  if ( !UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
  {
    v36 = UFG::UI::GetGamepadButtonTextureName(button3, 1);
    goto LABEL_21;
  }
  v33 = UFG::UIHKScreenOptionsButtonMapping::ButtonToRemapId(button3, RemapContext_OnFoot);
  v34 = &customCaption;
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
  UFG::qString::Set(&this->mMoveSequence.button3tex, v34);
  if ( !UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
  {
    v40 = UFG::UI::GetGamepadButtonTextureName(button4, 1);
    goto LABEL_28;
  }
  v37 = UFG::UIHKScreenOptionsButtonMapping::ButtonToRemapId(button4, RemapContext_OnFoot);
  v38 = &customCaption;
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
  UFG::qString::Set(&this->mMoveSequence.button4tex, v38);
  if ( !UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
  {
    v43 = UFG::UI::GetGamepadButtonTextureName(button5, 1);
    goto LABEL_35;
  }
  v41 = UFG::UIHKScreenOptionsButtonMapping::ButtonToRemapId(button5, RemapContext_OnFoot);
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
  UFG::qString::Set(&this->mMoveSequence.button5tex, v24);
  v44 = "BUTTON_ACCEPT";
  if ( buttonAction1 )
  {
    v45 = buttonAction1 - 1;
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
  UFG::qString::Set(&this->mMoveSequence.action1, v47);
  if ( buttonAction2 )
  {
    switch ( buttonAction2 )
    {
      case BUTTON_ACTION_PRESS:
        v48 = "inactive";
        goto LABEL_52;
      case BUTTON_ACTION_HOLD:
        v48 = "inactive_hold";
        goto LABEL_52;
      case BUTTON_ACTION_TAP:
        v48 = "inactive_tap";
        goto LABEL_52;
    }
  }
  v48 = "BUTTON_ACCEPT";
LABEL_52:
  UFG::qString::Set(&this->mMoveSequence.action2, v48);
  if ( buttonAction3 )
  {
    switch ( buttonAction3 )
    {
      case BUTTON_ACTION_PRESS:
        v49 = "inactive";
        goto LABEL_60;
      case BUTTON_ACTION_HOLD:
        v49 = "inactive_hold";
        goto LABEL_60;
      case BUTTON_ACTION_TAP:
        v49 = "inactive_tap";
        goto LABEL_60;
    }
  }
  v49 = "BUTTON_ACCEPT";
LABEL_60:
  UFG::qString::Set(&this->mMoveSequence.action3, v49);
  if ( buttonAction4 )
  {
    switch ( buttonAction4 )
    {
      case BUTTON_ACTION_PRESS:
        v50 = "inactive";
        goto LABEL_68;
      case BUTTON_ACTION_HOLD:
        v50 = "inactive_hold";
        goto LABEL_68;
      case BUTTON_ACTION_TAP:
        v50 = "inactive_tap";
        goto LABEL_68;
    }
  }
  v50 = "BUTTON_ACCEPT";
LABEL_68:
  UFG::qString::Set(&this->mMoveSequence.action4, v50);
  if ( buttonAction5 )
  {
    switch ( buttonAction5 )
    {
      case BUTTON_ACTION_PRESS:
        v44 = "inactive";
        break;
      case BUTTON_ACTION_HOLD:
        v44 = "inactive_hold";
        break;
      case BUTTON_ACTION_TAP:
        v44 = "inactive_tap";
        break;
    }
  }
  UFG::qString::Set(&this->mMoveSequence.action5, v44);
  v51 = "comma";
  if ( buttonSeperator2 )
  {
    if ( buttonSeperator2 == BUTTON_SEPERATOR_PLUS )
      v52 = "plus";
    else
      v52 = "comma";
  }
  else
  {
    v52 = "invalid";
  }
  UFG::qString::Set(&this->mMoveSequence.seperator2, v52);
  if ( buttonSeperator3 )
  {
    if ( buttonSeperator3 == BUTTON_SEPERATOR_PLUS )
      v53 = "plus";
    else
      v53 = "comma";
  }
  else
  {
    v53 = "invalid";
  }
  UFG::qString::Set(&this->mMoveSequence.seperator3, v53);
  if ( buttonSeperator4 )
  {
    if ( buttonSeperator4 == BUTTON_SEPERATOR_PLUS )
      v54 = "plus";
    else
      v54 = "comma";
  }
  else
  {
    v54 = "invalid";
  }
  UFG::qString::Set(&this->mMoveSequence.seperator4, v54);
  if ( buttonSeperator5 )
  {
    if ( buttonSeperator5 == BUTTON_SEPERATOR_PLUS )
      v51 = "plus";
  }
  else
  {
    v51 = "invalid";
  }
  UFG::qString::Set(&this->mMoveSequence.seperator5, v51);
  UFG::UIHKScreenFightTutorial::SetSequenceInFlash(this);
  pObject = this->UFG::UIScreen::mRenderable->m_movie.pObject;
  if ( pObject )
  {
    Scaleform::GFx::Movie::Invoke(pObject, "FightTutorial_InitSequence", 0i64, 0i64, 0);
    this->mInputIndex = 1;
  }
}

// File Line: 170
// RVA: 0x5ED700
void __fastcall UFG::UIHKScreenFightTutorial::InitSequence(UFG::UIHKScreenFightTutorial *this)
{
  Scaleform::GFx::Movie *pObject; // rcx

  pObject = this->UFG::UIScreen::mRenderable->m_movie.pObject;
  if ( pObject )
  {
    Scaleform::GFx::Movie::Invoke(pObject, "FightTutorial_InitSequence", 0i64, 0i64, 0);
    this->mInputIndex = 1;
  }
}

// File Line: 180
// RVA: 0x607B30
void __fastcall UFG::UIHKScreenFightTutorial::SetSequenceInFlash(UFG::UIHKScreenFightTutorial *this)
{
  Scaleform::GFx::Movie *pObject; // r14
  Scaleform::GFx::Value::ObjectInterface **p_pObjectInterface; // rbx
  __int64 v4; // rsi
  char *mData; // rbx
  char *v6; // rbx
  char *v7; // rbx
  char *v8; // rbx
  char *v9; // rbx
  char *v10; // rbx
  char *v11; // rbx
  char *v12; // rbx
  char *v13; // rbx
  char *v14; // rbx
  char *v15; // rbx
  char *v16; // rbx
  char *v17; // rbx
  char *v18; // rbx
  char *v19; // rbx
  Scaleform::GFx::Value ptr; // [rsp+30h] [rbp-B8h] BYREF
  char v21[8]; // [rsp+60h] [rbp-88h] BYREF
  char *v22; // [rsp+68h] [rbp-80h]
  __int64 v23; // [rsp+70h] [rbp-78h]
  int v24[4]; // [rsp+78h] [rbp-70h] BYREF
  __int64 v25; // [rsp+88h] [rbp-60h]
  int v26; // [rsp+90h] [rbp-58h]
  char *v27; // [rsp+98h] [rbp-50h]
  char v28[16]; // [rsp+A8h] [rbp-40h] BYREF
  __int64 v29; // [rsp+B8h] [rbp-30h]
  int v30; // [rsp+C0h] [rbp-28h]
  char *v31; // [rsp+C8h] [rbp-20h]
  char v32[16]; // [rsp+D8h] [rbp-10h] BYREF
  __int64 v33; // [rsp+E8h] [rbp+0h]
  int v34; // [rsp+F0h] [rbp+8h]
  char *v35; // [rsp+F8h] [rbp+10h]
  char v36[16]; // [rsp+108h] [rbp+20h] BYREF
  __int64 v37; // [rsp+118h] [rbp+30h]
  int v38; // [rsp+120h] [rbp+38h]
  char *v39; // [rsp+128h] [rbp+40h]
  char v40[16]; // [rsp+138h] [rbp+50h] BYREF
  __int64 v41; // [rsp+148h] [rbp+60h]
  int v42; // [rsp+150h] [rbp+68h]
  char *v43; // [rsp+158h] [rbp+70h]
  char v44[16]; // [rsp+168h] [rbp+80h] BYREF
  __int64 v45; // [rsp+178h] [rbp+90h]
  int v46; // [rsp+180h] [rbp+98h]
  char *v47; // [rsp+188h] [rbp+A0h]
  char v48[16]; // [rsp+198h] [rbp+B0h] BYREF
  __int64 v49; // [rsp+1A8h] [rbp+C0h]
  int v50; // [rsp+1B0h] [rbp+C8h]
  char *v51; // [rsp+1B8h] [rbp+D0h]
  char v52[16]; // [rsp+1C8h] [rbp+E0h] BYREF
  __int64 v53; // [rsp+1D8h] [rbp+F0h]
  int v54; // [rsp+1E0h] [rbp+F8h]
  char *v55; // [rsp+1E8h] [rbp+100h]
  char v56[16]; // [rsp+1F8h] [rbp+110h] BYREF
  __int64 v57; // [rsp+208h] [rbp+120h]
  int v58; // [rsp+210h] [rbp+128h]
  char *v59; // [rsp+218h] [rbp+130h]
  char v60[16]; // [rsp+228h] [rbp+140h] BYREF
  __int64 v61; // [rsp+238h] [rbp+150h]
  int v62; // [rsp+240h] [rbp+158h]
  char *v63; // [rsp+248h] [rbp+160h]
  char v64[16]; // [rsp+258h] [rbp+170h] BYREF
  __int64 v65; // [rsp+268h] [rbp+180h]
  int v66; // [rsp+270h] [rbp+188h]
  char *v67; // [rsp+278h] [rbp+190h]
  char v68[16]; // [rsp+288h] [rbp+1A0h] BYREF
  __int64 v69; // [rsp+298h] [rbp+1B0h]
  int v70; // [rsp+2A0h] [rbp+1B8h]
  char *v71; // [rsp+2A8h] [rbp+1C0h]
  char v72[16]; // [rsp+2B8h] [rbp+1D0h] BYREF
  __int64 v73; // [rsp+2C8h] [rbp+1E0h]
  int v74; // [rsp+2D0h] [rbp+1E8h]
  char *v75; // [rsp+2D8h] [rbp+1F0h]
  __int64 v76; // [rsp+2E8h] [rbp+200h]

  v76 = -2i64;
  pObject = this->UFG::UIScreen::mRenderable->m_movie.pObject;
  if ( pObject )
  {
    `eh vector constructor iterator(&ptr, 0x30ui64, 15, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    p_pObjectInterface = &ptr.pObjectInterface;
    v4 = 15i64;
    do
    {
      if ( ((_DWORD)p_pObjectInterface[1] & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value::ObjectInterface **, Scaleform::GFx::Value::ObjectInterface *))&(*p_pObjectInterface)->vfptr->gap8[8])(
          *p_pObjectInterface,
          p_pObjectInterface - 2,
          p_pObjectInterface[2]);
        *p_pObjectInterface = 0i64;
      }
      *((_DWORD *)p_pObjectInterface + 2) = 0;
      p_pObjectInterface += 6;
      --v4;
    }
    while ( v4 );
    mData = this->mMoveSequence.moveName.mData;
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
    if ( (unsigned int)UFG::qStringCompare(this->mMoveSequence.button1tex.mData, &customCaption, -1) )
    {
      v6 = this->mMoveSequence.button1tex.mData;
      if ( (v24[0] & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v23 + 16i64))(v23, v21, v22);
        v23 = 0i64;
      }
      v24[0] = 6;
      v22 = v6;
      v7 = this->mMoveSequence.action1.mData;
      if ( (v26 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, int *, char *))(*(_QWORD *)v25 + 16i64))(v25, v24, v27);
        v25 = 0i64;
      }
      v26 = 6;
      v27 = v7;
    }
    if ( (unsigned int)UFG::qStringCompare(this->mMoveSequence.button2tex.mData, &customCaption, -1) )
    {
      v8 = this->mMoveSequence.button2tex.mData;
      if ( (v30 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v29 + 16i64))(v29, v28, v31);
        v29 = 0i64;
      }
      v30 = 6;
      v31 = v8;
      v9 = this->mMoveSequence.action2.mData;
      if ( (v34 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v33 + 16i64))(v33, v32, v35);
        v33 = 0i64;
      }
      v34 = 6;
      v35 = v9;
      v10 = this->mMoveSequence.seperator2.mData;
      if ( (v38 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v37 + 16i64))(v37, v36, v39);
        v37 = 0i64;
      }
      v38 = 6;
      v39 = v10;
    }
    if ( (unsigned int)UFG::qStringCompare(this->mMoveSequence.button3tex.mData, &customCaption, -1) )
    {
      v11 = this->mMoveSequence.button3tex.mData;
      if ( (v42 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v41 + 16i64))(v41, v40, v43);
        v41 = 0i64;
      }
      v42 = 6;
      v43 = v11;
      v12 = this->mMoveSequence.action3.mData;
      if ( (v46 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v45 + 16i64))(v45, v44, v47);
        v45 = 0i64;
      }
      v46 = 6;
      v47 = v12;
      v13 = this->mMoveSequence.seperator3.mData;
      if ( (v50 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v49 + 16i64))(v49, v48, v51);
        v49 = 0i64;
      }
      v50 = 6;
      v51 = v13;
    }
    if ( (unsigned int)UFG::qStringCompare(this->mMoveSequence.button4tex.mData, &customCaption, -1) )
    {
      v14 = this->mMoveSequence.button4tex.mData;
      if ( (v54 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v53 + 16i64))(v53, v52, v55);
        v53 = 0i64;
      }
      v54 = 6;
      v55 = v14;
      v15 = this->mMoveSequence.action4.mData;
      if ( (v58 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v57 + 16i64))(v57, v56, v59);
        v57 = 0i64;
      }
      v58 = 6;
      v59 = v15;
      v16 = this->mMoveSequence.seperator4.mData;
      if ( (v62 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v61 + 16i64))(v61, v60, v63);
        v61 = 0i64;
      }
      v62 = 6;
      v63 = v16;
    }
    if ( (unsigned int)UFG::qStringCompare(this->mMoveSequence.button5tex.mData, &customCaption, -1) )
    {
      v17 = this->mMoveSequence.button5tex.mData;
      if ( (v66 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v65 + 16i64))(v65, v64, v67);
        v65 = 0i64;
      }
      v66 = 6;
      v67 = v17;
      v18 = this->mMoveSequence.action5.mData;
      if ( (v70 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v69 + 16i64))(v69, v68, v71);
        v69 = 0i64;
      }
      v70 = 6;
      v71 = v18;
      v19 = this->mMoveSequence.seperator5.mData;
      if ( (v74 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v73 + 16i64))(v73, v72, v75);
        v73 = 0i64;
      }
      v74 = 6;
      v75 = v19;
    }
    Scaleform::GFx::Movie::Invoke(pObject, "FightTutorial_SetSequence", 0i64, &ptr, 0xFu);
    `eh vector destructor iterator(&ptr, 0x30ui64, 15, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 275
// RVA: 0x5ED3B0
void __fastcall UFG::UIHKScreenFightTutorial::HitSuccess(UFG::UIHKScreenFightTutorial *this, int index)
{
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h] BYREF

  pObject = this->UFG::UIScreen::mRenderable->m_movie.pObject;
  if ( pObject )
  {
    `eh vector constructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( (pargs.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        pargs.mValue);
      pargs.pObjectInterface = 0i64;
    }
    pargs.Type = VT_Number;
    pargs.mValue.NValue = (double)index;
    Scaleform::GFx::Movie::Invoke(pObject, "FightTutorial_HitSuccess", 0i64, &pargs, 1u);
    `eh vector destructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 289
// RVA: 0x5ED2C0
void __fastcall UFG::UIHKScreenFightTutorial::HitFailed(UFG::UIHKScreenFightTutorial *this, int index)
{
  Scaleform::GFx::Movie *pObject; // rdi
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h] BYREF

  pObject = this->UFG::UIScreen::mRenderable->m_movie.pObject;
  if ( pObject )
  {
    `eh vector constructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( (pargs.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        pargs.mValue);
      pargs.pObjectInterface = 0i64;
    }
    pargs.Type = VT_Number;
    pargs.mValue.NValue = (double)index;
    Scaleform::GFx::Movie::Invoke(pObject, "FightTutorial_HitFailed", 0i64, &pargs, 1u);
    this->mResetTimer = 0.0;
    `eh vector destructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 306
// RVA: 0x5F4270
void UFG::UIHKScreenFightTutorial::Pop(void)
{
  UFG::UIScreenManagerBase::queuePopOverlay(UFG::UIScreenManager::s_instance, "FightingTutorial");
}

// File Line: 312
// RVA: 0x60C660
void __fastcall UFG::UIHKScreenFightTutorial::SetVisible(UFG::UIHKScreenFightTutorial *this, bool visible)
{
  this->UFG::UIScreen::mRenderable->m_shouldRender = visible;
}

// File Line: 351
// RVA: 0x5E6940
__int64 __fastcall UFG::UIHKScreenFightTutorial::GetAction(const char *text)
{
  int v3; // eax
  unsigned int v4; // ecx

  if ( !text )
    return 0i64;
  if ( !(unsigned int)UFG::qStringCompare(text, "press", -1) )
    return 1i64;
  if ( !(unsigned int)UFG::qStringCompare(text, "hold", -1) )
    return 2i64;
  v3 = UFG::qStringCompare(text, "tap", -1);
  v4 = 0;
  if ( !v3 )
    return 3;
  return v4;
}

// File Line: 363
// RVA: 0x5E93E0
__int64 __fastcall UFG::UIHKScreenFightTutorial::GetSeperator(const char *text)
{
  int v3; // eax
  unsigned int v4; // ecx

  if ( !text )
    return 0i64;
  if ( !(unsigned int)UFG::qStringCompare(text, "comma", -1) )
    return 1i64;
  v3 = UFG::qStringCompare(text, "plus", -1);
  v4 = 0;
  if ( !v3 )
    return 2;
  return v4;
}

// File Line: 374
// RVA: 0x5EE8A0
bool __fastcall UFG::UIHKScreenFightTutorial::IsSuccess(UFG::UIHKScreenFightTutorial *this)
{
  Scaleform::GFx::Movie *pObject; // rcx
  bool BValue; // bl
  Scaleform::GFx::Value pval; // [rsp+28h] [rbp-40h] BYREF

  pObject = this->UFG::UIScreen::mRenderable->m_movie.pObject;
  if ( !pObject )
    return 0;
  pval.pObjectInterface = 0i64;
  pval.Type = VT_Undefined;
  Scaleform::GFx::Movie::GetVariable(pObject, &pval, "gSequenceSuccessful");
  BValue = pval.mValue.BValue;
  if ( (pval.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pval.pObjectInterface->vfptr->gap8[8])(
      pval.pObjectInterface,
      &pval,
      pval.mValue);
    pval.pObjectInterface = 0i64;
  }
  return BValue;
}

// File Line: 386
// RVA: 0x5D4550
void __fastcall UFG::UIHKScreenFightTutorial::ButtonPressed(UFG::UIHKScreenFightTutorial *this, const char *buttonName)
{
  int v4; // ecx
  int v5; // ecx
  int v6; // ecx
  int v7; // ecx
  char *mData; // rcx

  v4 = this->mInputIndex - 1;
  if ( !v4 )
  {
    if ( (unsigned int)UFG::qStringCompare(this->mMoveSequence.action1.mData, "inactive", -1) )
      goto LABEL_18;
    mData = this->mMoveSequence.button1.mData;
    goto LABEL_16;
  }
  v5 = v4 - 1;
  if ( !v5 )
  {
    if ( (unsigned int)UFG::qStringCompare(this->mMoveSequence.action2.mData, "inactive", -1) )
      goto LABEL_18;
    mData = this->mMoveSequence.button2.mData;
    goto LABEL_16;
  }
  v6 = v5 - 1;
  if ( !v6 )
  {
    if ( (unsigned int)UFG::qStringCompare(this->mMoveSequence.action3.mData, "inactive", -1) )
      goto LABEL_18;
    mData = this->mMoveSequence.button3.mData;
    goto LABEL_16;
  }
  v7 = v6 - 1;
  if ( !v7 )
  {
    if ( (unsigned int)UFG::qStringCompare(this->mMoveSequence.action4.mData, "inactive", -1) )
      goto LABEL_18;
    mData = this->mMoveSequence.button4.mData;
LABEL_16:
    if ( !(unsigned int)UFG::qStringCompare(mData, buttonName, -1) )
    {
      UFG::UIHKScreenFightTutorial::HitSuccess(this, this->mInputIndex);
      ++this->mInputIndex;
      return;
    }
    goto LABEL_18;
  }
  if ( v7 == 1 )
  {
    if ( !(unsigned int)UFG::qStringCompare(this->mMoveSequence.action5.mData, "inactive", -1) )
    {
      mData = this->mMoveSequence.button5.mData;
      goto LABEL_16;
    }
LABEL_18:
    UFG::UIHKScreenFightTutorial::HitFailed(this, this->mInputIndex);
  }
  ++this->mInputIndex;
}

// File Line: 426
// RVA: 0x5D4400
void __fastcall UFG::UIHKScreenFightTutorial::ButtonHeld(UFG::UIHKScreenFightTutorial *this, const char *buttonName)
{
  int v4; // ecx
  int v5; // ecx
  int v6; // ecx
  int v7; // ecx
  char *mData; // rcx

  v4 = this->mInputIndex - 1;
  if ( !v4 )
  {
    if ( (unsigned int)UFG::qStringCompare(this->mMoveSequence.action1.mData, "inactive_hold", -1) )
      goto LABEL_18;
    mData = this->mMoveSequence.button1.mData;
    goto LABEL_16;
  }
  v5 = v4 - 1;
  if ( !v5 )
  {
    if ( (unsigned int)UFG::qStringCompare(this->mMoveSequence.action2.mData, "inactive_hold", -1) )
      goto LABEL_18;
    mData = this->mMoveSequence.button2.mData;
    goto LABEL_16;
  }
  v6 = v5 - 1;
  if ( !v6 )
  {
    if ( (unsigned int)UFG::qStringCompare(this->mMoveSequence.action3.mData, "inactive_hold", -1) )
      goto LABEL_18;
    mData = this->mMoveSequence.button3.mData;
    goto LABEL_16;
  }
  v7 = v6 - 1;
  if ( !v7 )
  {
    if ( (unsigned int)UFG::qStringCompare(this->mMoveSequence.action4.mData, "inactive_hold", -1) )
      goto LABEL_18;
    mData = this->mMoveSequence.button4.mData;
LABEL_16:
    if ( !(unsigned int)UFG::qStringCompare(mData, buttonName, -1) )
    {
      UFG::UIHKScreenFightTutorial::HitSuccess(this, this->mInputIndex);
      ++this->mInputIndex;
      return;
    }
    goto LABEL_18;
  }
  if ( v7 == 1 )
  {
    if ( !(unsigned int)UFG::qStringCompare(this->mMoveSequence.action5.mData, "inactive_hold", -1) )
    {
      mData = this->mMoveSequence.button5.mData;
      goto LABEL_16;
    }
LABEL_18:
    UFG::UIHKScreenFightTutorial::HitFailed(this, this->mInputIndex);
  }
  ++this->mInputIndex;
}

