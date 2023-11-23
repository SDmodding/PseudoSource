// File Line: 33
// RVA: 0x156C1F0
__int64 UFG::_dynamic_initializer_for__UI_HASH_MOUSE_MOVE_NEW_SLOT__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("MOUSE_MOVE_NEW_SLOT", -1);
  UI_HASH_MOUSE_MOVE_NEW_SLOT = result;
  return result;
}

// File Line: 60
// RVA: 0x5C6630
void __fastcall UFG::UIHKScreenOptionsDisplay::UIHKScreenOptionsDisplay(UFG::UIHKScreenOptionsDisplay *this)
{
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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenOptions::`vftable;
  *(_QWORD *)&this->UFG::UIHKScreenOptions::mState = 0i64;
  this->mOptionChanged = 0;
  *(_QWORD *)&this->mSavingDialogTimer = 0i64;
  this->mHelpBarName = "OPTIONS";
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenOptionsDisplay::`vftable;
  *(_QWORD *)&this->mState = 0i64;
  this->oldScale = 0;
  this->mAddCaptions = 0;
  Render::RenderOutputParams::RenderOutputParams(&this->mOldDisplaySettings);
  Render::RenderOutputParams::RenderOutputParams(&this->mCurrentDisplaySettings);
  *(_QWORD *)&this->mDisplayModeCount = 0i64;
  this->mTentativeDisplayModeIndex = 0;
  this->mDisplayModes = 0i64;
  this->mVideoOptionRevertTimer = 0.0;
}

// File Line: 73
// RVA: 0x633B70
void __fastcall UFG::UIHKScreenOptionsDisplay::init(UFG::UIHKScreenOptionsDisplay *this, UFG::UICommandData *data)
{
  UFG::Controller *v3; // rcx
  UFG::UIScreenVtbl *vfptr; // rax
  UFG::UIScreenRenderable *mRenderable; // rax
  Scaleform::GFx::Movie *pObject; // rdi

  UFG::UIScreen::init(this, data);
  if ( UFG::gInputSystem && UFG::gActiveControllerNum != -1 )
  {
    v3 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum];
    if ( !UFG::UI::gUIInputLocked )
      g_saved_gameplay_controller_mode = v3->m_ActiveMapSet;
    UFG::SetInputMode(IM_UI_ONLY, v3->mControllerIndex);
    ++UFG::UI::gUIInputLocked;
  }
  vfptr = this->vfptr;
  this->UFG::UIHKScreenOptions::mState = STATE_BRIGHTNESS;
  (*((void (__fastcall **)(UFG::UIHKScreenOptionsDisplay *))&vfptr[1].__vecDelDtor + 1))(this);
  mRenderable = this->mRenderable;
  pObject = mRenderable->m_movie.pObject;
  if ( pObject )
  {
    Scaleform::GFx::Movie::Invoke(mRenderable->m_movie.pObject, "EnableNonPSOptions", 0i64, 0i64, 0);
    Scaleform::GFx::Movie::Invoke(pObject, "OptionList_EnablePCOptions", 0i64, 0i64, 0);
  }
  UFG::UIHKScreenOptionsDisplay::onInit(this, 1);
}

// File Line: 97
// RVA: 0x638C10
void __fastcall UFG::UIHKScreenOptionsDisplay::onInit(UFG::UIHKScreenOptionsDisplay *this, bool addCaptions)
{
  UFG::GameStatTracker *v3; // rbx
  Scaleform::GFx::Movie *pObject; // rsi
  Scaleform::GFx::Value::ValueUnion v5; // xmm6_8
  double oldScale; // xmm6_8
  bool mEnableFullscreen; // bl
  bool mEnableVSync; // bl
  bool v9; // bl
  bool mEnable3D; // bl
  double mGlobalSetting; // xmm6_8
  bool mAddCaptions; // bl
  Scaleform::GFx::Value ptr; // [rsp+30h] [rbp-B8h] BYREF
  char v14[8]; // [rsp+60h] [rbp-88h] BYREF
  double v15; // [rsp+68h] [rbp-80h]
  __int64 v16; // [rsp+70h] [rbp-78h]
  int v17[4]; // [rsp+78h] [rbp-70h] BYREF
  __int64 v18; // [rsp+88h] [rbp-60h]
  int v19; // [rsp+90h] [rbp-58h]
  __int64 v20; // [rsp+98h] [rbp-50h]
  char v21[16]; // [rsp+A8h] [rbp-40h] BYREF
  __int64 v22; // [rsp+B8h] [rbp-30h]
  int v23; // [rsp+C0h] [rbp-28h]
  __int64 v24; // [rsp+C8h] [rbp-20h]
  char v25[16]; // [rsp+D8h] [rbp-10h] BYREF
  __int64 v26; // [rsp+E8h] [rbp+0h]
  int v27; // [rsp+F0h] [rbp+8h]
  __int64 v28; // [rsp+F8h] [rbp+10h]
  char v29[16]; // [rsp+108h] [rbp+20h] BYREF
  __int64 v30; // [rsp+118h] [rbp+30h]
  int v31; // [rsp+120h] [rbp+38h]
  __int64 v32; // [rsp+128h] [rbp+40h]
  char v33[16]; // [rsp+138h] [rbp+50h] BYREF
  __int64 v34; // [rsp+148h] [rbp+60h]
  int v35; // [rsp+150h] [rbp+68h]
  double v36; // [rsp+158h] [rbp+70h]
  char v37[16]; // [rsp+168h] [rbp+80h] BYREF
  __int64 v38; // [rsp+178h] [rbp+90h]
  int v39; // [rsp+180h] [rbp+98h]
  __int64 v40; // [rsp+188h] [rbp+A0h]
  __int64 v41; // [rsp+198h] [rbp+B0h]

  v41 = -2i64;
  this->mAddCaptions = addCaptions;
  this->mState = STATE_BRIGHTNESS;
  this->mOptionChanged = 0;
  v3 = UFG::GameStatTracker::Instance();
  this->oldGamma = UFG::GameStatTracker::GetStat(v3, Gamma);
  this->oldScale = UFG::GameStatTracker::GetStat(v3, UIScale);
  pObject = this->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    Render::GetCurrentDisplaySettings(&this->mOldDisplaySettings);
    Render::GetCurrentDisplaySettings(&this->mCurrentDisplaySettings);
    UFG::UIHKScreenOptionsDisplay::PopulateResolutionModes(this);
    `eh vector constructor iterator(&ptr, 0x30ui64, 8, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    v5.NValue = (double)this->oldGamma;
    if ( (ptr.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
        ptr.pObjectInterface,
        &ptr,
        ptr.mValue);
      ptr.pObjectInterface = 0i64;
    }
    ptr.Type = VT_Number;
    ptr.mValue = v5;
    oldScale = (double)this->oldScale;
    if ( (v17[0] & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v16 + 16i64))(
        v16,
        v14,
        COERCE_DOUBLE(*(_QWORD *)&v15));
      v16 = 0i64;
    }
    v17[0] = 5;
    v15 = oldScale;
    mEnableFullscreen = this->mOldDisplaySettings.mEnableFullscreen;
    if ( (v19 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, int *, __int64))(*(_QWORD *)v18 + 16i64))(v18, v17, v20);
      v18 = 0i64;
    }
    v19 = 2;
    LOBYTE(v20) = mEnableFullscreen;
    mEnableVSync = this->mOldDisplaySettings.mEnableVSync;
    if ( (v23 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v22 + 16i64))(v22, v21, v24);
      v22 = 0i64;
    }
    v23 = 2;
    LOBYTE(v24) = mEnableVSync;
    v9 = this->mOldDisplaySettings.mMotionBlur == MOTION_BLUR_HIGH;
    if ( (v27 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v26 + 16i64))(v26, v25, v28);
      v26 = 0i64;
    }
    v27 = 2;
    LOBYTE(v28) = v9;
    mEnable3D = this->mOldDisplaySettings.mEnable3D;
    if ( (v31 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v30 + 16i64))(v30, v29, v32);
      v30 = 0i64;
    }
    v31 = 2;
    LOBYTE(v32) = mEnable3D;
    mGlobalSetting = (double)(int)this->mOldDisplaySettings.mGlobalSetting;
    if ( (v35 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v34 + 16i64))(
        v34,
        v33,
        COERCE_DOUBLE(*(_QWORD *)&v36));
      v34 = 0i64;
    }
    v35 = 5;
    v36 = mGlobalSetting;
    mAddCaptions = this->mAddCaptions;
    if ( (v39 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v38 + 16i64))(v38, v37, v40);
      v38 = 0i64;
    }
    v39 = 2;
    LOBYTE(v40) = mAddCaptions;
    Scaleform::GFx::Movie::Invoke(pObject, "OptionList_SetValues", 0i64, &ptr, 8u);
    Scaleform::GFx::Movie::Invoke(pObject, "OptionList_PlayIntro", 0i64, 0i64, 0);
    `eh vector destructor iterator(&ptr, 0x30ui64, 8, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 136
// RVA: 0x63E5B0
void __fastcall UFG::UIHKScreenOptionsDisplay::update(UFG::UIHKScreenOptionsDisplay *this, float elapsed)
{
  float v3; // xmm1_4
  UFG::UIScreen *v4; // rax
  float v5; // xmm1_4
  UFG::UIScreen *Screen; // rax

  UFG::UIHKScreenOptions::update(this, elapsed);
  if ( this->mState == STATE_UISCALE )
  {
    v5 = this->mVideoOptionRevertTimer - elapsed;
    this->mVideoOptionRevertTimer = v5;
    if ( v5 <= 0.0 )
    {
      this->mState = STATE_BRIGHTNESS;
      Screen = UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "DialogBox");
      if ( Screen )
        UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, Screen->mScreenUID);
      UFG::UIHKScreenOptionsDisplay::RevertResolutionMode(this);
    }
  }
  else if ( this->mState == NUM_CALIBRATION_STATES )
  {
    v3 = this->mVideoOptionRevertTimer - elapsed;
    this->mVideoOptionRevertTimer = v3;
    if ( v3 <= 0.0 )
    {
      this->mState = STATE_BRIGHTNESS;
      v4 = UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "DialogBox");
      if ( v4 )
        UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, v4->mScreenUID);
      UFG::UIHKScreenOptionsDisplay::RevertFullscreenMode(this);
    }
  }
}

// File Line: 169
// RVA: 0x6272D0
bool __fastcall UFG::UIHKScreenOptionsDisplay::handleMessage(
        UFG::UIHKScreenOptionsDisplay *this,
        unsigned int msgId,
        UFG::UIMessage *msg)
{
  UFG::GameStatTracker *v6; // r14
  int mTentativeDisplayModeIndex; // ecx
  __int64 v9; // rcx
  Render::DisplayMode *mDisplayModes; // rax
  int SelectedSlot; // eax
  int FlashArgsInt; // eax
  int v13; // eax
  bool v14; // bl
  __int64 v15; // rcx
  Render::DisplayMode *v16; // rax
  Scaleform::GFx::Movie *pObject; // rsi
  bool mEnableFullscreen; // bl
  bool mEnableVSync; // bl
  bool v20; // bl
  bool v21; // bl
  bool v22; // bl
  Render::eGlobalSetting v23; // eax
  __int64 v24; // rcx
  Render::DisplayMode *v25; // rax
  UFG::GameSaveLoad *v26; // rax
  UFG::GameSaveLoad *v27; // rax
  UFG::GameSaveLoad *v28; // rax
  UFG::UIScreenTextureManager *v29; // rax
  UFG::GameStatTracker *v30; // rax
  UFG::GameStatTracker *v31; // rax
  UFG::GameStatTracker *v32; // rax
  Render::RenderOutputParams settings; // [rsp+50h] [rbp-98h] BYREF
  __int128 v34; // [rsp+B8h] [rbp-30h]
  __int128 v35; // [rsp+C8h] [rbp-20h]
  __int128 v36; // [rsp+D8h] [rbp-10h] BYREF
  __int128 v37; // [rsp+E8h] [rbp+0h]
  __int128 v38; // [rsp+F8h] [rbp+10h]
  __int64 v39; // [rsp+108h] [rbp+20h]
  UFG::qString v40; // [rsp+118h] [rbp+30h] BYREF
  __int64 v41; // [rsp+140h] [rbp+58h]
  UFG::qString option2Text; // [rsp+148h] [rbp+60h] BYREF

  v41 = -2i64;
  v6 = UFG::GameStatTracker::Instance();
  mTentativeDisplayModeIndex = this->mTentativeDisplayModeIndex;
  if ( mTentativeDisplayModeIndex != this->mCurrentDisplayModeIndex )
  {
    if ( msgId == UI_HASH_BUTTON_ACCEPT_PRESSED_30
      || msgId == UI_HASH_BUTTON_BUTTON1_PRESSED_30
      || msgId == (_DWORD)UI_HASH_BUTTON_BUTTON2_PRESSED_30
      || msgId == UI_HASH_DPAD_UP_PRESSED_30
      || msgId == UI_HASH_DPAD_DOWN_PRESSED_30
      || msgId == UI_HASH_MOUSE_MOVE_NEW_SLOT )
    {
      if ( mTentativeDisplayModeIndex >= 0 && mTentativeDisplayModeIndex < this->mDisplayModeCount )
        UFG::GameStatTracker::Instance();
      *(_OWORD *)&settings.mDisplayMode.mBackBufferWidth = *(_OWORD *)&this->mCurrentDisplaySettings.mDisplayMode.mBackBufferWidth;
      *(_OWORD *)&settings.mDisplayMode.mAdapterUID = *(_OWORD *)&this->mCurrentDisplaySettings.mDisplayMode.mAdapterUID;
      *(_OWORD *)&settings.mEnableFullscreen = *(_OWORD *)&this->mCurrentDisplaySettings.mEnableFullscreen;
      *(_OWORD *)&settings.mDisplayMode.mScaling = *(_OWORD *)&this->mCurrentDisplaySettings.mShadowFilter;
      *(_OWORD *)&settings.mAAQuality = *(_OWORD *)&this->mCurrentDisplaySettings.mFPSLimiter;
      *(_OWORD *)&settings.mInterAxialDistance = *(_OWORD *)&this->mCurrentDisplaySettings.mLODSetting;
      *(_QWORD *)&settings.m3DDepth = *(_QWORD *)&this->mCurrentDisplaySettings.mTextureFilterQuality;
      v9 = this->mTentativeDisplayModeIndex;
      mDisplayModes = this->mDisplayModes;
      *(_OWORD *)&settings.mDisplayMode.mBackBufferWidth = *(_OWORD *)&mDisplayModes[v9].mBackBufferWidth;
      *(_OWORD *)&settings.mDisplayMode.mAdapterUID = *(_OWORD *)&mDisplayModes[v9].mAdapterUID;
      if ( UFG::UIHKScreenOptionsDisplay::ApplyRenderOptions(this, &settings) )
      {
        UFG::UIScreenManagerBase::setFontScale(UFG::UIScreenManager::s_instance, 1.0);
        UFG::UI::RefreshScreenHD(this);
        Scaleform::GFx::Movie::Invoke(this->mRenderable->m_movie.pObject, "OptionListUpdateSDText", 0i64, 0i64, 0);
        this->mState = STATE_UISCALE;
        UFG::qString::qString(&v40, "$OPTIONS_YES");
        UFG::qString::qString(&option2Text, "$OPTIONS_NO");
        UFG::UIScreenDialogBox::createTwoButtonDialog(
          this,
          &customCaption,
          "$OPTIONS_DIALOG_VIDEO_CHANGED",
          v40.mData,
          UI_HASH_DIALOG_YES_30,
          option2Text.mData,
          UI_HASH_DIALOG_NO_30,
          DIALOG_BUTTON2,
          1,
          "DialogBox");
        UFG::qString::~qString(&option2Text);
        UFG::qString::~qString(&v40);
        this->mVideoOptionRevertTimer = 15.0;
      }
      else
      {
        this->mState = NUM_CALIBRATION_STATES|STATE_BRIGHTNESS;
        UFG::qString::qString(&v40, "$COMMON_OK_UPPERCASE");
        UFG::UIScreenDialogBox::createOneButtonDialog(
          this,
          &customCaption,
          "$OPTIONS_DIALOG_INVALID_DISPLAY_SETTINGS",
          v40.mData,
          UI_HASH_DIALOG_OK_30,
          1,
          "DialogBox");
        UFG::qString::~qString(&v40);
        UFG::UIHKScreenOptionsDisplay::RevertResolutionMode(this);
      }
      return 1;
    }
    if ( msgId == UI_HASH_BUTTON_BACK_PRESSED_30 )
    {
      UFG::UIHKScreenOptionsDisplay::RevertResolutionMode(this);
      return 1;
    }
  }
  if ( msgId == UI_HASH_INTRO_COMPLETE_30 )
  {
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x688D286Au, 0i64, 0, 0i64);
    return UFG::UIScreen::handleMessage(this, msgId, msg);
  }
  if ( msgId == UI_HASH_OPTION_HIGHLIGHTED_30 )
  {
    SelectedSlot = UFG::UIHKScreenOptions::GetSelectedSlot(this);
    UFG::UIHKScreenOptionsDisplay::Flash_SetScaleCornersVisible(this, SelectedSlot == 1);
    goto LABEL_61;
  }
  if ( msgId == UI_HASH_OPTIONS_SCALE_20 )
  {
    this->mOptionChanged = 1;
    FlashArgsInt = UFG::UI::GetFlashArgsInt(msg);
    UFG::gUIViewportScale = (float)((float)((float)FlashArgsInt * 0.1) * 0.15000001) + 0.85000002;
    UFG::GameStatTracker::SetStat(v6, UIScale, FlashArgsInt);
    return 1;
  }
  if ( msgId == UI_HASH_OPTIONS_BRIGHTNESS_20 )
  {
    this->mOptionChanged = 1;
    v13 = UFG::UI::GetFlashArgsInt(msg);
    UFG::GameStatTracker::SetStat(v6, Gamma, v13);
    return 1;
  }
  if ( msgId == UI_HASH_OPTIONS_RESOLUTION_20 )
  {
    this->mOptionChanged = 1;
    this->mTentativeDisplayModeIndex = UFG::UI::GetFlashArgsInt(msg);
    return 1;
  }
  if ( msgId == UI_HASH_OPTIONS_FULLSCREEN_20 )
  {
    v14 = (unsigned int)UFG::UI::GetFlashArgsInt(msg) == 1;
    if ( this->mCurrentDisplaySettings.mEnableFullscreen != v14 )
    {
      this->mOptionChanged = 1;
      UFG::GameStatTracker::SetStat(v6, Display_IsFullscreen, v14);
      *(_OWORD *)&settings.mDisplayMode.mBackBufferWidth = *(_OWORD *)&this->mCurrentDisplaySettings.mDisplayMode.mBackBufferWidth;
      *(_OWORD *)&settings.mDisplayMode.mAdapterUID = *(_OWORD *)&this->mCurrentDisplaySettings.mDisplayMode.mAdapterUID;
      *(_OWORD *)&settings.mEnableFullscreen = *(_OWORD *)&this->mCurrentDisplaySettings.mEnableFullscreen;
      *(_OWORD *)&settings.mDisplayMode.mScaling = *(_OWORD *)&this->mCurrentDisplaySettings.mShadowFilter;
      *(_OWORD *)&settings.mAAQuality = *(_OWORD *)&this->mCurrentDisplaySettings.mFPSLimiter;
      *(_OWORD *)&settings.mInterAxialDistance = *(_OWORD *)&this->mCurrentDisplaySettings.mLODSetting;
      *(_QWORD *)&settings.m3DDepth = *(_QWORD *)&this->mCurrentDisplaySettings.mTextureFilterQuality;
      v15 = this->mTentativeDisplayModeIndex;
      v16 = this->mDisplayModes;
      *(_OWORD *)&settings.mDisplayMode.mBackBufferWidth = *(_OWORD *)&v16[v15].mBackBufferWidth;
      *(_OWORD *)&settings.mDisplayMode.mAdapterUID = *(_OWORD *)&v16[v15].mAdapterUID;
      settings.mEnableFullscreen = v14;
      if ( UFG::UIHKScreenOptionsDisplay::ApplyRenderOptions(this, &settings) )
      {
        if ( v14 )
        {
          this->mState = NUM_CALIBRATION_STATES;
          UFG::UIScreenDialogBox::createYesNoDialog(this, &customCaption, "$OPTIONS_DIALOG_VIDEO_CHANGED", 0, 1);
          this->mVideoOptionRevertTimer = 15.0;
        }
      }
      else
      {
        this->mState = NUM_CALIBRATION_STATES|STATE_BRIGHTNESS;
        UFG::UIScreenDialogBox::createOKDialog(this, &customCaption, "$OPTIONS_DIALOG_INVALID_DISPLAY_SETTINGS", 1);
        UFG::UIHKScreenOptionsDisplay::RevertFullscreenMode(this);
      }
      pObject = this->mRenderable->m_movie.pObject;
      `eh vector constructor iterator(
        &settings.mDeviceType,
        0x30ui64,
        2,
        (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      mEnableFullscreen = this->mCurrentDisplaySettings.mEnableFullscreen;
      if ( (BYTE8(v34) & 0x40) != 0 )
      {
        (*(void (__fastcall **)(_QWORD, Render::eDeviceType *, _QWORD))(*(_QWORD *)v34 + 16i64))(
          v34,
          &settings.mDeviceType,
          v35);
        *(_QWORD *)&v34 = 0i64;
      }
      DWORD2(v34) = 2;
      LOBYTE(v35) = mEnableFullscreen;
      mEnableVSync = this->mCurrentDisplaySettings.mEnableVSync;
      if ( (BYTE8(v37) & 0x40) != 0 )
      {
        (*(void (__fastcall **)(_QWORD, __int128 *, _QWORD))(*(_QWORD *)v37 + 16i64))(v37, &v36, v38);
        *(_QWORD *)&v37 = 0i64;
      }
      DWORD2(v37) = 2;
      LOBYTE(v38) = mEnableVSync;
      Scaleform::GFx::Movie::Invoke(
        pObject,
        "OptionList_SetVSyncEnabled",
        0i64,
        (Scaleform::GFx::Value *)&settings.mDeviceType,
        2u);
      `eh vector destructor iterator(
        &settings.mDeviceType,
        0x30ui64,
        2,
        (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
      return 1;
    }
    return 1;
  }
  if ( msgId == UI_HASH_OPTIONS_VSYNC_20 )
  {
    this->mOptionChanged = 1;
    v20 = (unsigned int)UFG::UI::GetFlashArgsInt(msg) == 1;
    UFG::GameStatTracker::SetStat(v6, Display_EnableVSync, v20);
    this->mCurrentDisplaySettings.mEnableVSync = v20;
  }
  else if ( msgId == UI_HASH_OPTIONS_QUALITY_MOTION_BLUR_20 )
  {
    this->mOptionChanged = 1;
    v21 = (unsigned int)UFG::UI::GetFlashArgsInt(msg) == 1;
    UFG::GameStatTracker::SetStat(v6, Display_HighQualityMotionBlur, v21);
    this->mCurrentDisplaySettings.mMotionBlur = v21 + 1;
  }
  else if ( msgId == UI_HASH_OPTIONS_ENABLE_3D_20 )
  {
    this->mOptionChanged = 1;
    v22 = (unsigned int)UFG::UI::GetFlashArgsInt(msg) == 1;
    UFG::GameStatTracker::SetStat(v6, Display_Enable3D, v22);
    this->mCurrentDisplaySettings.mEnable3D = v22;
  }
  else if ( msgId == UI_HASH_OPTIONS_GRAPHICS_LEVEL_20 )
  {
    this->mOptionChanged = 1;
    v23 = (unsigned int)UFG::UI::GetFlashArgsInt(msg);
    Render::RenderOutputParams::ChangeGlobalSetting(&this->mCurrentDisplaySettings, v23);
  }
  else
  {
    if ( msgId == (_DWORD)UI_HASH_BUTTON_BUTTON2_PRESSED_30 )
    {
      UFG::UIHKScreenOptionsDisplay::RevertResolutionMode(this);
      UFG::UIScreenDialogBox::createYesNoDialog(this, "$OPTIONS_OPTIONS_CHANGED", "$OPTIONS_SAVE_CHANGES", 1, 1);
      this->mState = NUM_CALIBRATION_STATES|STATE_VOLUME;
      return 1;
    }
    if ( msgId == UI_HASH_DIALOG_YES_30 )
    {
      if ( this->mState == (NUM_CALIBRATION_STATES|STATE_VOLUME) )
      {
        this->mOptionChanged = 0;
        if ( mTentativeDisplayModeIndex >= 0 && mTentativeDisplayModeIndex < this->mDisplayModeCount )
          UFG::GameStatTracker::Instance();
        *(_OWORD *)&settings.mDisplayMode.mBackBufferWidth = *(_OWORD *)&this->mCurrentDisplaySettings.mDisplayMode.mBackBufferWidth;
        *(_OWORD *)&settings.mDisplayMode.mAdapterUID = *(_OWORD *)&this->mCurrentDisplaySettings.mDisplayMode.mAdapterUID;
        *(_OWORD *)&settings.mEnableFullscreen = *(_OWORD *)&this->mCurrentDisplaySettings.mEnableFullscreen;
        *(_OWORD *)&settings.mDisplayMode.mScaling = *(_OWORD *)&this->mCurrentDisplaySettings.mShadowFilter;
        *(_OWORD *)&settings.mAAQuality = *(_OWORD *)&this->mCurrentDisplaySettings.mFPSLimiter;
        *(_OWORD *)&settings.mInterAxialDistance = *(_OWORD *)&this->mCurrentDisplaySettings.mLODSetting;
        *(_QWORD *)&settings.m3DDepth = *(_QWORD *)&this->mCurrentDisplaySettings.mTextureFilterQuality;
        v24 = this->mTentativeDisplayModeIndex;
        v25 = this->mDisplayModes;
        *(_OWORD *)&settings.mDisplayMode.mBackBufferWidth = *(_OWORD *)&v25[v24].mBackBufferWidth;
        *(_OWORD *)&settings.mDisplayMode.mAdapterUID = *(_OWORD *)&v25[v24].mAdapterUID;
        if ( !UFG::UIHKScreenOptionsDisplay::ApplyRenderOptions(this, &settings) )
        {
          this->mState = NUM_CALIBRATION_STATES|STATE_BRIGHTNESS;
          UFG::UIScreenDialogBox::createOKDialog(this, &customCaption, "$OPTIONS_DIALOG_INVALID_DISPLAY_SETTINGS", 1);
          UFG::UIHKScreenOptionsDisplay::RevertResolutionMode(this);
          return 1;
        }
        UFG::UIScreenManagerBase::setFontScale(UFG::UIScreenManager::s_instance, 1.0);
        UFG::UI::RefreshScreenHD(this);
        Scaleform::GFx::Movie::Invoke(this->mRenderable->m_movie.pObject, "OptionListUpdateSDText", 0i64, 0i64, 0);
        this->mState = STATE_BRIGHTNESS;
        Render::RenderOutputParams::RenderOutputParams((Render::RenderOutputParams *)&settings.mDeviceType);
        *(_OWORD *)&settings.mDeviceType = *(_OWORD *)&this->mCurrentDisplaySettings.mDisplayMode.mBackBufferWidth;
        v34 = *(_OWORD *)&this->mCurrentDisplaySettings.mDisplayMode.mAdapterUID;
        v35 = *(_OWORD *)&this->mCurrentDisplaySettings.mEnableFullscreen;
        v36 = *(_OWORD *)&this->mCurrentDisplaySettings.mShadowFilter;
        v37 = *(_OWORD *)&this->mCurrentDisplaySettings.mFPSLimiter;
        v38 = *(_OWORD *)&this->mCurrentDisplaySettings.mLODSetting;
        v39 = *(_QWORD *)&this->mCurrentDisplaySettings.mTextureFilterQuality;
        UFG::GameStatPCDisplaySettings::SaveToXML(
          (UFG::GameStatPCDisplaySettings *)&settings.mDeviceType,
          UFG::GameStatPCDisplaySettings::gDefaultSavePath);
        return 1;
      }
    }
    else if ( msgId == UI_HASH_DIALOG_NO_30 && this->mState == (NUM_CALIBRATION_STATES|STATE_VOLUME) )
    {
      ((void (__fastcall *)(UFG::UIHKScreenOptionsDisplay *))this->vfptr[1].handleMessage)(this);
      v26 = UFG::GameSaveLoad::Instance();
      UFG::GameSaveLoad::ApplyOptions(v26);
      this->mState = STATE_BRIGHTNESS;
      return 1;
    }
  }
LABEL_61:
  if ( this->mState == STATE_BRIGHTNESS )
  {
    if ( msgId == UI_HASH_BUTTON_BUTTON1_PRESSED_30 )
    {
      v29 = UFG::UIScreenTextureManager::Instance();
      UFG::UIScreenTextureManager::QueueLoadAndPush(v29, "Options_DisplayAdvanced", 0i64);
      return 1;
    }
    else
    {
      if ( msgId == UI_HASH_BUTTON_SELECT_PRESSED_30 )
      {
        v30 = UFG::GameStatTracker::Instance();
        UFG::GameStatTracker::SetStat(v30, Gamma, 50);
        v31 = UFG::GameStatTracker::Instance();
        UFG::GameStatTracker::SetStat(v31, UIScale, 10);
        v32 = UFG::GameStatTracker::Instance();
        UFG::gUIViewportScale = (float)((float)((float)(int)UFG::GameStatTracker::GetStat(v32, UIScale) * 0.1)
                                      * 0.15000001)
                              + 0.85000002;
        Render::RenderOutputParams::SetDefault(&this->mCurrentDisplaySettings);
        ((void (__fastcall *)(UFG::UIHKScreenOptionsDisplay *))this->vfptr[1].update)(this);
        UFG::UIHKScreenOptionsDisplay::Flash_RefreshValues(this);
      }
      return UFG::UIHKScreenOptions::handleMessage(this, msgId, msg);
    }
  }
  else
  {
    if ( this->mState == STATE_UISCALE )
    {
      if ( msgId == UI_HASH_DIALOG_YES_30 )
      {
        this->mState = STATE_BRIGHTNESS;
        this->mCurrentDisplayModeIndex = this->mTentativeDisplayModeIndex;
        v27 = UFG::GameSaveLoad::Instance();
        UFG::GameSaveLoad::ApplyOptions(v27);
        v28 = UFG::GameSaveLoad::Instance();
        UFG::GameSaveLoad::SaveGameOptions(v28);
        UFG::DataSynchronizer::SetOptionsDirty();
        this->mOptionChanged = 0;
        this->mOldDisplaySettings.mDisplayMode.mBackBufferWidth = this->mCurrentDisplaySettings.mDisplayMode.mBackBufferWidth;
        this->mOldDisplaySettings.mDisplayMode.mBackBufferHeight = this->mCurrentDisplaySettings.mDisplayMode.mBackBufferHeight;
        this->mOldDisplaySettings.mDisplayMode.mRefreshRateNumerator = this->mCurrentDisplaySettings.mDisplayMode.mRefreshRateNumerator;
        this->mOldDisplaySettings.mDisplayMode.mRefreshRateDenominator = this->mCurrentDisplaySettings.mDisplayMode.mRefreshRateDenominator;
        this->mOldDisplaySettings.mDisplayMode.mAdapterUID = this->mCurrentDisplaySettings.mDisplayMode.mAdapterUID;
        this->mOldDisplaySettings.mDisplayMode.mMonitorUID = this->mCurrentDisplaySettings.mDisplayMode.mMonitorUID;
        this->mOldDisplaySettings.mDisplayMode.mScaling = this->mCurrentDisplaySettings.mDisplayMode.mScaling;
        this->mOldDisplaySettings.mDisplayMode.mScanlineMode = this->mCurrentDisplaySettings.mDisplayMode.mScanlineMode;
        *(_DWORD *)&this->mOldDisplaySettings.mEnableFullscreen = *(_DWORD *)&this->mCurrentDisplaySettings.mEnableFullscreen;
        *(_DWORD *)&this->mOldDisplaySettings.mEnableCloudVolumes = *(_DWORD *)&this->mCurrentDisplaySettings.mEnableCloudVolumes;
        this->mOldDisplaySettings.mAAQuality = this->mCurrentDisplaySettings.mAAQuality;
        this->mOldDisplaySettings.mShadowRes = this->mCurrentDisplaySettings.mShadowRes;
        this->mOldDisplaySettings.mShadowFilter = this->mCurrentDisplaySettings.mShadowFilter;
        this->mOldDisplaySettings.mMotionBlur = this->mCurrentDisplaySettings.mMotionBlur;
        this->mOldDisplaySettings.mInterAxialDistance = this->mCurrentDisplaySettings.mInterAxialDistance;
        this->mOldDisplaySettings.mSSAO = this->mCurrentDisplaySettings.mSSAO;
        this->mOldDisplaySettings.mFPSLimiter = this->mCurrentDisplaySettings.mFPSLimiter;
        this->mOldDisplaySettings.mFeatureLevel = this->mCurrentDisplaySettings.mFeatureLevel;
        this->mOldDisplaySettings.m3DDepth = this->mCurrentDisplaySettings.m3DDepth;
        this->mOldDisplaySettings.m3DConvergence = this->mCurrentDisplaySettings.m3DConvergence;
        this->mOldDisplaySettings.mLODSetting = this->mCurrentDisplaySettings.mLODSetting;
        this->mOldDisplaySettings.mGlobalSetting = this->mCurrentDisplaySettings.mGlobalSetting;
        this->mOldDisplaySettings.mDeviceType = this->mCurrentDisplaySettings.mDeviceType;
        this->mOldDisplaySettings.mTimeStepSmoothingFrames = this->mCurrentDisplaySettings.mTimeStepSmoothingFrames;
        this->mOldDisplaySettings.mTextureFilterQuality = this->mCurrentDisplaySettings.mTextureFilterQuality;
        this->mOldDisplaySettings.mTextureDetailLevel = this->mCurrentDisplaySettings.mTextureDetailLevel;
        Render::RenderOutputParams::RenderOutputParams(&settings);
        *(_OWORD *)&settings.mDisplayMode.mBackBufferWidth = *(_OWORD *)&this->mCurrentDisplaySettings.mDisplayMode.mBackBufferWidth;
        *(_OWORD *)&settings.mDisplayMode.mAdapterUID = *(_OWORD *)&this->mCurrentDisplaySettings.mDisplayMode.mAdapterUID;
        *(_OWORD *)&settings.mEnableFullscreen = *(_OWORD *)&this->mCurrentDisplaySettings.mEnableFullscreen;
        *(_OWORD *)&settings.mDisplayMode.mScaling = *(_OWORD *)&this->mCurrentDisplaySettings.mShadowFilter;
        *(_OWORD *)&settings.mAAQuality = *(_OWORD *)&this->mCurrentDisplaySettings.mFPSLimiter;
        *(_OWORD *)&settings.mInterAxialDistance = *(_OWORD *)&this->mCurrentDisplaySettings.mLODSetting;
        *(_QWORD *)&settings.m3DDepth = *(_QWORD *)&this->mCurrentDisplaySettings.mTextureFilterQuality;
        UFG::GameStatPCDisplaySettings::SaveToXML(
          (UFG::GameStatPCDisplaySettings *)&settings,
          UFG::GameStatPCDisplaySettings::gDefaultSavePath);
        UFG::UIHKScreenOptionsDisplay::RefreshHighDef(this);
        return 1;
      }
      if ( msgId == UI_HASH_DIALOG_NO_30 )
      {
        this->mState = STATE_BRIGHTNESS;
        UFG::UIHKScreenOptionsDisplay::RevertResolutionMode(this);
        return 1;
      }
    }
    else if ( this->mState == NUM_CALIBRATION_STATES )
    {
      if ( msgId == UI_HASH_DIALOG_YES_30 )
      {
        this->mState = STATE_BRIGHTNESS;
        this->mOldDisplaySettings.mDisplayMode.mBackBufferWidth = this->mCurrentDisplaySettings.mDisplayMode.mBackBufferWidth;
        this->mOldDisplaySettings.mDisplayMode.mBackBufferHeight = this->mCurrentDisplaySettings.mDisplayMode.mBackBufferHeight;
        this->mOldDisplaySettings.mDisplayMode.mRefreshRateNumerator = this->mCurrentDisplaySettings.mDisplayMode.mRefreshRateNumerator;
        this->mOldDisplaySettings.mDisplayMode.mRefreshRateDenominator = this->mCurrentDisplaySettings.mDisplayMode.mRefreshRateDenominator;
        this->mOldDisplaySettings.mDisplayMode.mAdapterUID = this->mCurrentDisplaySettings.mDisplayMode.mAdapterUID;
        this->mOldDisplaySettings.mDisplayMode.mMonitorUID = this->mCurrentDisplaySettings.mDisplayMode.mMonitorUID;
        this->mOldDisplaySettings.mDisplayMode.mScaling = this->mCurrentDisplaySettings.mDisplayMode.mScaling;
        this->mOldDisplaySettings.mDisplayMode.mScanlineMode = this->mCurrentDisplaySettings.mDisplayMode.mScanlineMode;
        *(_DWORD *)&this->mOldDisplaySettings.mEnableFullscreen = *(_DWORD *)&this->mCurrentDisplaySettings.mEnableFullscreen;
        *(_DWORD *)&this->mOldDisplaySettings.mEnableCloudVolumes = *(_DWORD *)&this->mCurrentDisplaySettings.mEnableCloudVolumes;
        this->mOldDisplaySettings.mAAQuality = this->mCurrentDisplaySettings.mAAQuality;
        this->mOldDisplaySettings.mShadowRes = this->mCurrentDisplaySettings.mShadowRes;
        this->mOldDisplaySettings.mShadowFilter = this->mCurrentDisplaySettings.mShadowFilter;
        this->mOldDisplaySettings.mMotionBlur = this->mCurrentDisplaySettings.mMotionBlur;
        this->mOldDisplaySettings.mInterAxialDistance = this->mCurrentDisplaySettings.mInterAxialDistance;
        this->mOldDisplaySettings.mSSAO = this->mCurrentDisplaySettings.mSSAO;
        this->mOldDisplaySettings.mFPSLimiter = this->mCurrentDisplaySettings.mFPSLimiter;
        this->mOldDisplaySettings.mFeatureLevel = this->mCurrentDisplaySettings.mFeatureLevel;
        this->mOldDisplaySettings.m3DDepth = this->mCurrentDisplaySettings.m3DDepth;
        this->mOldDisplaySettings.m3DConvergence = this->mCurrentDisplaySettings.m3DConvergence;
        this->mOldDisplaySettings.mLODSetting = this->mCurrentDisplaySettings.mLODSetting;
        this->mOldDisplaySettings.mGlobalSetting = this->mCurrentDisplaySettings.mGlobalSetting;
        this->mOldDisplaySettings.mDeviceType = this->mCurrentDisplaySettings.mDeviceType;
        this->mOldDisplaySettings.mTimeStepSmoothingFrames = this->mCurrentDisplaySettings.mTimeStepSmoothingFrames;
        this->mOldDisplaySettings.mTextureFilterQuality = this->mCurrentDisplaySettings.mTextureFilterQuality;
        this->mOldDisplaySettings.mTextureDetailLevel = this->mCurrentDisplaySettings.mTextureDetailLevel;
        return 1;
      }
      if ( msgId == UI_HASH_DIALOG_NO_30 )
      {
        this->mState = STATE_BRIGHTNESS;
        UFG::UIHKScreenOptionsDisplay::RevertFullscreenMode(this);
        return 1;
      }
    }
    else if ( this->mState == (NUM_CALIBRATION_STATES|STATE_BRIGHTNESS) && msgId == UI_HASH_DIALOG_OK_30 )
    {
      this->mState = STATE_BRIGHTNESS;
      return 1;
    }
    return 0;
  }
}

// File Line: 484
// RVA: 0x61FEF0
void __fastcall UFG::UIHKScreenOptionsDisplay::dim(
        UFG::UIHKScreenOptionsDisplay *this,
        UFG::UIScreen::eDimType dimType,
        bool instant)
{
  Scaleform::GFx::Movie *pObject; // rcx

  UFG::UIScreen::dim(this, dimType, instant);
  pObject = this->mRenderable->m_movie.pObject;
  if ( pObject )
    Scaleform::GFx::Movie::Invoke(pObject, "dim", 0i64, 0i64, 0);
}

// File Line: 495
// RVA: 0x63B6D0
void __fastcall UFG::UIHKScreenOptionsDisplay::undim(UFG::UIHKScreenOptionsDisplay *this, bool instant)
{
  Scaleform::GFx::Movie *pObject; // rcx

  UFG::UIScreen::undim(this, instant);
  pObject = this->mRenderable->m_movie.pObject;
  if ( pObject )
    Scaleform::GFx::Movie::Invoke(pObject, "undim", 0i64, 0i64, 0);
}

// File Line: 506
// RVA: 0x5D5C40
float __fastcall UFG::UIHKScreenOptionsDisplay::ConvertScaleOption(int optionValue)
{
  return (float)((float)((float)optionValue * 0.1) * 0.15000001) + 0.85000002;
}

// File Line: 523
// RVA: 0x5D3BC0
void __fastcall UFG::UIHKScreenOptionsDisplay::ApplyOptions(UFG::UIHKScreenOptionsDisplay *this)
{
  Render::RenderOutputParams *p_mCurrentDisplaySettings; // rbx
  __int128 v2; // xmm1
  __int128 v3; // xmm1
  __int128 v4; // xmm1
  Render::RenderOutputParams v5; // [rsp+20h] [rbp-78h] BYREF

  p_mCurrentDisplaySettings = &this->mCurrentDisplaySettings;
  if ( UFG::UIHKScreenOptionsDisplay::ApplyRenderOptions(this, &this->mCurrentDisplaySettings) )
  {
    Render::RenderOutputParams::RenderOutputParams(&v5);
    v2 = *(_OWORD *)&p_mCurrentDisplaySettings->mDisplayMode.mAdapterUID;
    *(_OWORD *)&v5.mDisplayMode.mBackBufferWidth = *(_OWORD *)&p_mCurrentDisplaySettings->mDisplayMode.mBackBufferWidth;
    *(_OWORD *)&v5.mDisplayMode.mAdapterUID = v2;
    v3 = *(_OWORD *)&p_mCurrentDisplaySettings->mShadowFilter;
    *(_OWORD *)&v5.mEnableFullscreen = *(_OWORD *)&p_mCurrentDisplaySettings->mEnableFullscreen;
    *(_OWORD *)&v5.mShadowFilter = v3;
    v4 = *(_OWORD *)&p_mCurrentDisplaySettings->mLODSetting;
    *(_OWORD *)&v5.mFPSLimiter = *(_OWORD *)&p_mCurrentDisplaySettings->mFPSLimiter;
    *(_OWORD *)&v5.mLODSetting = v4;
    *(_QWORD *)&v5.mTextureFilterQuality = *(_QWORD *)&p_mCurrentDisplaySettings->mTextureFilterQuality;
    UFG::GameStatPCDisplaySettings::SaveToXML(
      (UFG::GameStatPCDisplaySettings *)&v5,
      UFG::GameStatPCDisplaySettings::gDefaultSavePath);
  }
}

// File Line: 540
// RVA: 0x6030A0
void __fastcall UFG::UIHKScreenOptionsDisplay::RestoreOptions(UFG::UIHKScreenOptionsDisplay *this)
{
  UFG::GameStatTracker *v2; // rbx

  v2 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::SetStat(v2, Gamma, this->oldGamma);
  UFG::GameStatTracker::SetStat(v2, UIScale, this->oldScale);
}

// File Line: 562
// RVA: 0x5D3D30
char __fastcall UFG::UIHKScreenOptionsDisplay::ApplyRenderOptions(
        UFG::UIHKScreenOptionsDisplay *this,
        Render::RenderOutputParams *settings)
{
  if ( !Render::ValidateDisplaySettings(settings) )
    return 0;
  this->mCurrentDisplaySettings.mDisplayMode.mBackBufferWidth = settings->mDisplayMode.mBackBufferWidth;
  this->mCurrentDisplaySettings.mDisplayMode.mBackBufferHeight = settings->mDisplayMode.mBackBufferHeight;
  this->mCurrentDisplaySettings.mDisplayMode.mRefreshRateNumerator = settings->mDisplayMode.mRefreshRateNumerator;
  this->mCurrentDisplaySettings.mDisplayMode.mRefreshRateDenominator = settings->mDisplayMode.mRefreshRateDenominator;
  this->mCurrentDisplaySettings.mDisplayMode.mAdapterUID = settings->mDisplayMode.mAdapterUID;
  this->mCurrentDisplaySettings.mDisplayMode.mMonitorUID = settings->mDisplayMode.mMonitorUID;
  this->mCurrentDisplaySettings.mDisplayMode.mScaling = settings->mDisplayMode.mScaling;
  this->mCurrentDisplaySettings.mDisplayMode.mScanlineMode = settings->mDisplayMode.mScanlineMode;
  *(_DWORD *)&this->mCurrentDisplaySettings.mEnableFullscreen = *(_DWORD *)&settings->mEnableFullscreen;
  *(_DWORD *)&this->mCurrentDisplaySettings.mEnableCloudVolumes = *(_DWORD *)&settings->mEnableCloudVolumes;
  this->mCurrentDisplaySettings.mAAQuality = settings->mAAQuality;
  this->mCurrentDisplaySettings.mShadowRes = settings->mShadowRes;
  this->mCurrentDisplaySettings.mShadowFilter = settings->mShadowFilter;
  this->mCurrentDisplaySettings.mMotionBlur = settings->mMotionBlur;
  this->mCurrentDisplaySettings.mInterAxialDistance = settings->mInterAxialDistance;
  this->mCurrentDisplaySettings.mSSAO = settings->mSSAO;
  this->mCurrentDisplaySettings.mFPSLimiter = settings->mFPSLimiter;
  this->mCurrentDisplaySettings.mFeatureLevel = settings->mFeatureLevel;
  this->mCurrentDisplaySettings.m3DDepth = settings->m3DDepth;
  this->mCurrentDisplaySettings.m3DConvergence = settings->m3DConvergence;
  this->mCurrentDisplaySettings.mLODSetting = settings->mLODSetting;
  this->mCurrentDisplaySettings.mGlobalSetting = settings->mGlobalSetting;
  this->mCurrentDisplaySettings.mDeviceType = settings->mDeviceType;
  this->mCurrentDisplaySettings.mTimeStepSmoothingFrames = settings->mTimeStepSmoothingFrames;
  this->mCurrentDisplaySettings.mTextureFilterQuality = settings->mTextureFilterQuality;
  this->mCurrentDisplaySettings.mTextureDetailLevel = settings->mTextureDetailLevel;
  Render::ApplyDisplaySettings(&this->mCurrentDisplaySettings);
  return 1;
}

// File Line: 579
// RVA: 0x6005F0
void __fastcall UFG::UIHKScreenOptionsDisplay::RefreshHighDef(UFG::UIHKScreenOptionsDisplay *this)
{
  UFG::UIHKScreenGlobalOverlay *v2; // rbx
  UFG::UIHKScreenGlobalOverlay *v3; // rcx

  gUIHorizontalResolution = (float)Render::GetBackBufferTarget()->mWidth;
  gUIVerticalResolution = (float)Render::GetBackBufferTarget()->mHeight;
  gIsUIHighDef = gUIVerticalResolution >= 720.0;
  UFG::UIScreenManagerBase::setFontScale(UFG::UIScreenManager::s_instance, 1.0);
  UFG::UI::RefreshScreenHD(this);
  Scaleform::GFx::Movie::Invoke(this->mRenderable->m_movie.pObject, "OptionListUpdateSDText", 0i64, 0i64, 0);
  v2 = &gGlobalOverlaySentinel;
  v3 = &gGlobalOverlaySentinel;
  if ( UFG::UIHKScreenGlobalOverlay::mThis )
    v3 = UFG::UIHKScreenGlobalOverlay::mThis;
  UFG::UI::RefreshScreenHD(v3);
  if ( UFG::UIHKScreenGlobalOverlay::mThis )
    v2 = UFG::UIHKScreenGlobalOverlay::mThis;
  v2->HelpBar.mChanged = 1;
}

// File Line: 600
// RVA: 0x5FA9A0
void __fastcall UFG::UIHKScreenOptionsDisplay::PopulateResolutionModes(UFG::UIHKScreenOptionsDisplay *this)
{
  Scaleform::GFx::Movie *pObject; // r13
  __int64 v3; // rdi
  int DisplayModeCount; // eax
  Render::DisplayMode *mDisplayModes; // rcx
  unsigned __int64 mDisplayModeCount; // rcx
  unsigned __int64 v7; // rax
  Render::DisplayMode *v8; // rax
  char v9; // r12
  int v10; // r15d
  Render::DisplayMode *v11; // rsi
  float v12; // xmm6_4
  unsigned int mRefreshRateDenominator; // ecx
  float v14; // xmm1_4
  float v15; // xmm0_4
  const char *v16; // rdx
  float v17; // xmm0_4
  float v18; // xmm1_4
  char *mData; // r14
  long double mCurrentDisplayModeIndex; // xmm6_8
  Render::DisplayMode filter; // [rsp+30h] [rbp-A8h] BYREF
  Scaleform::GFx::Value pargs; // [rsp+50h] [rbp-88h] BYREF
  UFG::qString v23; // [rsp+88h] [rbp-50h] BYREF
  __int64 v24; // [rsp+B0h] [rbp-28h]
  UFG::qString v25; // [rsp+B8h] [rbp-20h] BYREF
  UFG::qString v26; // [rsp+E8h] [rbp+10h] BYREF

  v24 = -2i64;
  pObject = this->mRenderable->m_movie.pObject;
  v3 = 0i64;
  Scaleform::GFx::Movie::Invoke(pObject, "OptionList_ClearResolutions", 0i64, 0i64, 0);
  memset(&filter, 0, 24);
  filter.mScaling = SCALING_MODE_NOTFILTERED;
  filter.mScanlineMode = SCANLINE_MODE_PROGRESSIVE;
  DisplayModeCount = Render::GetDisplayModeCount(&filter);
  this->mDisplayModeCount = DisplayModeCount;
  if ( DisplayModeCount < 1 )
  {
    filter.mScanlineMode = SCANLINE_MODE_NOTFILTERED;
    this->mDisplayModeCount = Render::GetDisplayModeCount(&filter);
  }
  if ( this->mDisplayModeCount >= 1 )
  {
    mDisplayModes = this->mDisplayModes;
    if ( mDisplayModes )
      operator delete[](mDisplayModes);
    mDisplayModeCount = this->mDisplayModeCount;
    v7 = 32 * mDisplayModeCount;
    if ( !is_mul_ok(mDisplayModeCount, 0x20ui64) )
      v7 = -1i64;
    v8 = (Render::DisplayMode *)UFG::qMalloc(v7, UFG::gGlobalNewName, 0i64);
    this->mDisplayModes = v8;
    Render::GetDisplayModeArray(&filter, v8);
    UFG::qString::qString(&v26);
    *(_QWORD *)&pargs.Type = 0i64;
    pargs.mValue.IValue = 0;
    v9 = 0;
    v10 = 0;
    if ( this->mDisplayModeCount <= 0 )
      goto LABEL_34;
    do
    {
      v11 = this->mDisplayModes;
      v12 = 0.0;
      mRefreshRateDenominator = v11[v3].mRefreshRateDenominator;
      if ( mRefreshRateDenominator )
        v12 = (float)(int)(v11[v3].mRefreshRateNumerator / mRefreshRateDenominator);
      UFG::qString::qString(&v23);
      v14 = (float)(int)v11[v3].mBackBufferWidth / (float)(int)v11[v3].mBackBufferHeight;
      v15 = v14 - 1.7777778;
      if ( (float)(v14 - 1.7777778) < 0.0 )
        LODWORD(v15) ^= _xmm[0];
      if ( v15 >= 0.0099999998 )
      {
        v17 = v14 - 1.6;
        if ( (float)(v14 - 1.6) < 0.0 )
          LODWORD(v17) ^= _xmm[0];
        if ( v17 >= 0.0099999998 )
        {
          v18 = v14 - 1.3333334;
          if ( v18 < 0.0 )
            LODWORD(v18) ^= _xmm[0];
          v16 = "4:3";
          if ( v18 >= 0.0099999998 )
            v16 = &customCaption;
        }
        else
        {
          v16 = "16:10";
        }
      }
      else
      {
        v16 = "16:9";
      }
      UFG::qString::Set(&v23, v16);
      v25 = v23;
      UFG::qString::Format(
        &v26,
        "%dx%dx%.0f Hz %s",
        v11[v3].mBackBufferWidth,
        v11[v3].mBackBufferHeight,
        v12,
        (const char *)&v25);
      mData = v26.mData;
      if ( (pargs.mValue.BValue & 0x40) != 0 )
      {
        (*(void (__fastcall **)(_QWORD, $41EDDC8CC4664C9FE26D4D23F9ACAEE4 *, unsigned __int64))(**(_QWORD **)&pargs.Type
                                                                                              + 16i64))(
          *(_QWORD *)&pargs.Type,
          &pargs.8,
          pargs.DataAux);
        *(_QWORD *)&pargs.Type = 0i64;
      }
      pargs.mValue.IValue = 6;
      pargs.DataAux = (unsigned __int64)mData;
      Scaleform::GFx::Movie::Invoke(pObject, "OptionList_AddResolution", 0i64, (Scaleform::GFx::Value *)&pargs.8, 1u);
      if ( v11[v3].mBackBufferWidth == this->mCurrentDisplaySettings.mDisplayMode.mBackBufferWidth
        && v11[v3].mBackBufferHeight == this->mCurrentDisplaySettings.mDisplayMode.mBackBufferHeight
        && v11[v3].mRefreshRateNumerator == this->mCurrentDisplaySettings.mDisplayMode.mRefreshRateNumerator
        && v11[v3].mRefreshRateDenominator == this->mCurrentDisplaySettings.mDisplayMode.mRefreshRateDenominator
        && v11[v3].mScaling == this->mCurrentDisplaySettings.mDisplayMode.mScaling
        && v11[v3].mScanlineMode == this->mCurrentDisplaySettings.mDisplayMode.mScanlineMode )
      {
        this->mCurrentDisplayModeIndex = v10;
        v9 = 1;
      }
      UFG::qString::~qString(&v23);
      ++v10;
      ++v3;
    }
    while ( v10 < this->mDisplayModeCount );
    if ( !v9 )
LABEL_34:
      this->mCurrentDisplayModeIndex = this->mDisplayModeCount - 1;
    pargs.pObjectInterface = 0i64;
    pargs.Type = VT_Undefined;
    mCurrentDisplayModeIndex = (double)this->mCurrentDisplayModeIndex;
    pargs.Type = VT_Number;
    pargs.mValue.NValue = mCurrentDisplayModeIndex;
    Scaleform::GFx::Movie::Invoke(pObject, "OptionList_SetResolutionIndex", 0i64, &pargs, 1u);
    this->mTentativeDisplayModeIndex = this->mCurrentDisplayModeIndex;
    if ( (pargs.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        pargs.mValue);
      pargs.pObjectInterface = 0i64;
    }
    pargs.Type = VT_Undefined;
    if ( (pargs.mValue.BValue & 0x40) != 0 )
    {
      (*(void (__fastcall **)(_QWORD, $41EDDC8CC4664C9FE26D4D23F9ACAEE4 *, unsigned __int64))(**(_QWORD **)&pargs.Type
                                                                                            + 16i64))(
        *(_QWORD *)&pargs.Type,
        &pargs.8,
        pargs.DataAux);
      *(_QWORD *)&pargs.Type = 0i64;
    }
    pargs.mValue.IValue = 0;
    UFG::qString::~qString(&v26);
  }
}

// File Line: 703
// RVA: 0x603350
void __fastcall UFG::UIHKScreenOptionsDisplay::RevertResolutionMode(UFG::UIHKScreenOptionsDisplay *this)
{
  Render::DisplayMode *mDisplayModes; // r8
  __int64 mCurrentDisplayModeIndex; // r9
  int v4; // edx

  mDisplayModes = this->mDisplayModes;
  mCurrentDisplayModeIndex = this->mCurrentDisplayModeIndex;
  this->mCurrentDisplaySettings.mDisplayMode.mBackBufferWidth = mDisplayModes[mCurrentDisplayModeIndex].mBackBufferWidth;
  this->mCurrentDisplaySettings.mDisplayMode.mBackBufferHeight = mDisplayModes[mCurrentDisplayModeIndex].mBackBufferHeight;
  this->mCurrentDisplaySettings.mDisplayMode.mRefreshRateNumerator = mDisplayModes[mCurrentDisplayModeIndex].mRefreshRateNumerator;
  this->mCurrentDisplaySettings.mDisplayMode.mRefreshRateDenominator = mDisplayModes[mCurrentDisplayModeIndex].mRefreshRateDenominator;
  this->mCurrentDisplaySettings.mDisplayMode.mAdapterUID = mDisplayModes[mCurrentDisplayModeIndex].mAdapterUID;
  this->mCurrentDisplaySettings.mDisplayMode.mMonitorUID = mDisplayModes[mCurrentDisplayModeIndex].mMonitorUID;
  this->mCurrentDisplaySettings.mDisplayMode.mScaling = mDisplayModes[mCurrentDisplayModeIndex].mScaling;
  this->mCurrentDisplaySettings.mDisplayMode.mScanlineMode = mDisplayModes[mCurrentDisplayModeIndex].mScanlineMode;
  UFG::UIHKScreenOptionsDisplay::ApplyRenderOptions(this, &this->mCurrentDisplaySettings);
  v4 = this->mCurrentDisplayModeIndex;
  this->mTentativeDisplayModeIndex = v4;
  UFG::UIHKScreenOptionsDisplay::Flash_SetResolutionModeIndex(this, v4);
  UFG::UIScreenManagerBase::setFontScale(UFG::UIScreenManager::s_instance, 1.0);
  UFG::UI::RefreshScreenHD(this);
  Scaleform::GFx::Movie::Invoke(this->mRenderable->m_movie.pObject, "OptionListUpdateSDText", 0i64, 0i64, 0);
}

// File Line: 721
// RVA: 0x6032B0
void __fastcall UFG::UIHKScreenOptionsDisplay::RevertFullscreenMode(UFG::UIHKScreenOptionsDisplay *this)
{
  UFG::GameStatTracker *v2; // rax
  __int64 mCurrentDisplayModeIndex; // rcx
  Render::DisplayMode *v4; // rcx

  v2 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::SetStat(v2, Display_IsFullscreen, 0);
  mCurrentDisplayModeIndex = this->mCurrentDisplayModeIndex;
  this->mCurrentDisplaySettings.mEnableFullscreen = 0;
  v4 = &this->mDisplayModes[mCurrentDisplayModeIndex];
  this->mCurrentDisplaySettings.mDisplayMode.mBackBufferWidth = v4->mBackBufferWidth;
  this->mCurrentDisplaySettings.mDisplayMode.mBackBufferHeight = v4->mBackBufferHeight;
  this->mCurrentDisplaySettings.mDisplayMode.mRefreshRateNumerator = v4->mRefreshRateNumerator;
  this->mCurrentDisplaySettings.mDisplayMode.mRefreshRateDenominator = v4->mRefreshRateDenominator;
  this->mCurrentDisplaySettings.mDisplayMode.mAdapterUID = v4->mAdapterUID;
  this->mCurrentDisplaySettings.mDisplayMode.mMonitorUID = v4->mMonitorUID;
  this->mCurrentDisplaySettings.mDisplayMode.mScaling = v4->mScaling;
  this->mCurrentDisplaySettings.mDisplayMode.mScanlineMode = v4->mScanlineMode;
  UFG::UIHKScreenOptionsDisplay::ApplyRenderOptions(this, &this->mCurrentDisplaySettings);
  UFG::UIHKScreenOptionsDisplay::Flash_SetFullscreenOption(this, 0);
  UFG::UIHKScreenOptionsDisplay::Flash_SetResolutionModeIndex(this, this->mCurrentDisplayModeIndex);
}

// File Line: 745
// RVA: 0x60ED00
void __fastcall UFG::UIHKScreenOptionsDisplay::ShowHelpBar(UFG::UIHKScreenOptionsDisplay *this)
{
  int v2; // esi
  unsigned int v3; // r14d
  int v4; // ecx
  __int64 v5; // rax
  __int64 v6; // rdi
  __int64 v7; // rbx
  unsigned int v8; // r14d
  int v9; // ecx
  __int64 v10; // rax
  __int64 v11; // rdi
  __int64 v12; // rbx
  unsigned int v13; // r14d
  int v14; // ecx
  __int64 v15; // rax
  __int64 v16; // rdi
  __int64 v17; // rbx
  unsigned int v18; // r14d
  __int64 v19; // rax
  __int64 v20; // rbx
  UFG::UIHKScreenGlobalOverlay *v21; // rax
  UFG::UIHKHelpBarData data; // [rsp+30h] [rbp-C8h] BYREF

  UFG::UIHKHelpBarData::UIHKHelpBarData(&data);
  data.id = UFG::qStringHash32(this->mHelpBarName, 0xFFFFFFFF);
  v2 = 0;
  *(_QWORD *)&data.priority = 0i64;
  v3 = UI_HASH_BUTTON_BACK_PRESSED_30;
  v4 = 0;
  v5 = 0i64;
  while ( data.Buttons[v5] )
  {
    ++v4;
    if ( ++v5 >= 6 )
      goto LABEL_6;
  }
  v6 = v4;
  data.Buttons[v6] = BACK_BUTTON;
  v7 = v4;
  UFG::qString::Set(&data.Captions[v7], "$COMMON_BACK_UPPERCASE");
  UFG::qString::Set((UFG::qString *)&data.Captions[v7 + 5].mStringHash32, &customCaption);
  data.MessageIds[v6 - 2] = v3;
LABEL_6:
  v8 = UI_HASH_BUTTON_BUTTON1_PRESSED_30;
  v9 = 0;
  v10 = 0i64;
  while ( data.Buttons[v10] )
  {
    ++v9;
    if ( ++v10 >= 6 )
      goto LABEL_11;
  }
  v11 = v9;
  data.Buttons[v11] = BUTTON1_BUTTON;
  v12 = v9;
  UFG::qString::Set(&data.Captions[v12], "$COMMON_ADVANCED");
  UFG::qString::Set((UFG::qString *)&data.Captions[v12 + 5].mStringHash32, &customCaption);
  data.MessageIds[v11 - 2] = v8;
LABEL_11:
  v13 = (unsigned int)UI_HASH_BUTTON_BUTTON2_PRESSED_30;
  v14 = 0;
  v15 = 0i64;
  while ( data.Buttons[v15] )
  {
    ++v14;
    if ( ++v15 >= 6 )
      goto LABEL_16;
  }
  v16 = v14;
  data.Buttons[v16] = BUTTON2_BUTTON;
  v17 = v14;
  UFG::qString::Set(&data.Captions[v17], "$OPTIONS_SAVE_GRAPHICS_LEVEL");
  UFG::qString::Set((UFG::qString *)&data.Captions[v17 + 5].mStringHash32, &customCaption);
  data.MessageIds[v16 - 2] = v13;
LABEL_16:
  v18 = UI_HASH_BUTTON_SELECT_PRESSED_30;
  v19 = 0i64;
  while ( data.Buttons[v19] )
  {
    ++v2;
    if ( ++v19 >= 6 )
      goto LABEL_21;
  }
  data.Buttons[v2] = SELECT_BUTTON;
  v20 = v2;
  UFG::qString::Set(&data.Captions[v20], "$OPTIONS_RESET_TO_DEFAULT");
  UFG::qString::Set((UFG::qString *)&data.Captions[v20 + 5].mStringHash32, &customCaption);
  data.MessageIds[v2 - 2] = v18;
LABEL_21:
  v21 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    v21 = &gGlobalOverlaySentinel;
  UFG::UIHKHelpBarWidget::Show(&v21->HelpBar, &data);
  UFG::qString::~qString((UFG::qString *)&data.MessageIds[4]);
  `eh vector destructor iterator(
    &data.Captions[5].mStringHash32,
    0x28ui64,
    6,
    (void (__fastcall *)(void *))UFG::qString::~qString);
  `eh vector destructor iterator(data.Captions, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
}

// File Line: 762
// RVA: 0x5E0840
void __fastcall UFG::UIHKScreenOptionsDisplay::Flash_SetResolutionModeIndex(
        UFG::UIHKScreenOptionsDisplay *this,
        int index)
{
  Scaleform::GFx::Movie *pObject; // rdi
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h] BYREF

  pObject = this->mRenderable->m_movie.pObject;
  pargs.pObjectInterface = 0i64;
  pargs.Type = VT_Number;
  pargs.mValue.NValue = (double)index;
  Scaleform::GFx::Movie::Invoke(pObject, "OptionList_SetResolutionIndex", 0i64, &pargs, 1u);
  if ( (pargs.Type & 0x40) != 0 )
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      pargs.mValue);
}

// File Line: 772
// RVA: 0x5DFF60
void __fastcall UFG::UIHKScreenOptionsDisplay::Flash_SetFullscreenOption(
        UFG::UIHKScreenOptionsDisplay *this,
        bool fullscreen)
{
  Scaleform::GFx::Movie *pObject; // rdi
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h] BYREF

  pObject = this->mRenderable->m_movie.pObject;
  pargs.pObjectInterface = 0i64;
  pargs.Type = VT_Boolean;
  pargs.mValue.BValue = fullscreen;
  Scaleform::GFx::Movie::Invoke(pObject, "OptionList_SetFullscreenOption", 0i64, &pargs, 1u);
  if ( (pargs.Type & 0x40) != 0 )
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      pargs.mValue);
}

// File Line: 782
// RVA: 0x5E0910
void __fastcall UFG::UIHKScreenOptionsDisplay::Flash_SetScaleCornersVisible(
        UFG::UIHKScreenOptionsDisplay *this,
        bool visible)
{
  Scaleform::GFx::Movie *pObject; // rdi
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-40h] BYREF

  pObject = this->mRenderable->m_movie.pObject;
  value.pObjectInterface = 0i64;
  value.Type = VT_Boolean;
  value.mValue.BValue = visible;
  Scaleform::GFx::Movie::SetVariable(pObject, "mc_uiScaleCorners._visible", &value, 1i64);
  if ( (value.Type & 0x40) != 0 )
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
      value.pObjectInterface,
      &value,
      value.mValue);
}

// File Line: 791
// RVA: 0x5DEC60
void __fastcall UFG::UIHKScreenOptionsDisplay::Flash_RefreshValues(UFG::UIHKScreenOptionsDisplay *this)
{
  Scaleform::GFx::Movie *MovieSafe; // rdi
  UFG::GameStatTracker *v3; // rax
  float Stat; // xmm6_4
  UFG::GameStatTracker *v5; // rax
  float v6; // xmm7_4
  bool mEnableFullscreen; // si
  bool mEnableVSync; // si
  bool v9; // si
  bool mEnable3D; // si
  double mGlobalSetting; // xmm6_8
  bool mAddCaptions; // bl
  Scaleform::GFx::Value ptr; // [rsp+30h] [rbp-B8h] BYREF
  char v14[8]; // [rsp+60h] [rbp-88h] BYREF
  double v15; // [rsp+68h] [rbp-80h]
  __int64 v16; // [rsp+70h] [rbp-78h]
  int v17[4]; // [rsp+78h] [rbp-70h] BYREF
  __int64 v18; // [rsp+88h] [rbp-60h]
  int v19; // [rsp+90h] [rbp-58h]
  __int64 v20; // [rsp+98h] [rbp-50h]
  char v21[16]; // [rsp+A8h] [rbp-40h] BYREF
  __int64 v22; // [rsp+B8h] [rbp-30h]
  int v23; // [rsp+C0h] [rbp-28h]
  __int64 v24; // [rsp+C8h] [rbp-20h]
  char v25[16]; // [rsp+D8h] [rbp-10h] BYREF
  __int64 v26; // [rsp+E8h] [rbp+0h]
  int v27; // [rsp+F0h] [rbp+8h]
  __int64 v28; // [rsp+F8h] [rbp+10h]
  char v29[16]; // [rsp+108h] [rbp+20h] BYREF
  __int64 v30; // [rsp+118h] [rbp+30h]
  int v31; // [rsp+120h] [rbp+38h]
  __int64 v32; // [rsp+128h] [rbp+40h]
  char v33[16]; // [rsp+138h] [rbp+50h] BYREF
  __int64 v34; // [rsp+148h] [rbp+60h]
  int v35; // [rsp+150h] [rbp+68h]
  double v36; // [rsp+158h] [rbp+70h]
  char v37[16]; // [rsp+168h] [rbp+80h] BYREF
  __int64 v38; // [rsp+178h] [rbp+90h]
  int v39; // [rsp+180h] [rbp+98h]
  __int64 v40; // [rsp+188h] [rbp+A0h]
  __int64 v41; // [rsp+198h] [rbp+B0h]

  v41 = -2i64;
  MovieSafe = UFG::UIScreen::getMovieSafe(this);
  if ( MovieSafe )
  {
    v3 = UFG::GameStatTracker::Instance();
    Stat = (float)(int)UFG::GameStatTracker::GetStat(v3, Gamma);
    v5 = UFG::GameStatTracker::Instance();
    v6 = (float)(int)UFG::GameStatTracker::GetStat(v5, UIScale);
    `eh vector constructor iterator(&ptr, 0x30ui64, 8, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( (ptr.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
        ptr.pObjectInterface,
        &ptr,
        ptr.mValue);
      ptr.pObjectInterface = 0i64;
    }
    ptr.Type = VT_Number;
    ptr.mValue.NValue = Stat;
    if ( (v17[0] & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v16 + 16i64))(
        v16,
        v14,
        COERCE_DOUBLE(*(_QWORD *)&v15));
      v16 = 0i64;
    }
    v17[0] = 5;
    v15 = v6;
    mEnableFullscreen = this->mCurrentDisplaySettings.mEnableFullscreen;
    if ( (v19 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, int *, __int64))(*(_QWORD *)v18 + 16i64))(v18, v17, v20);
      v18 = 0i64;
    }
    v19 = 2;
    LOBYTE(v20) = mEnableFullscreen;
    mEnableVSync = this->mCurrentDisplaySettings.mEnableVSync;
    if ( (v23 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v22 + 16i64))(v22, v21, v24);
      v22 = 0i64;
    }
    v23 = 2;
    LOBYTE(v24) = mEnableVSync;
    v9 = this->mCurrentDisplaySettings.mMotionBlur == MOTION_BLUR_HIGH;
    if ( (v27 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v26 + 16i64))(v26, v25, v28);
      v26 = 0i64;
    }
    v27 = 2;
    LOBYTE(v28) = v9;
    mEnable3D = this->mCurrentDisplaySettings.mEnable3D;
    if ( (v31 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v30 + 16i64))(v30, v29, v32);
      v30 = 0i64;
    }
    v31 = 2;
    LOBYTE(v32) = mEnable3D;
    mGlobalSetting = (double)(int)this->mCurrentDisplaySettings.mGlobalSetting;
    if ( (v35 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v34 + 16i64))(
        v34,
        v33,
        COERCE_DOUBLE(*(_QWORD *)&v36));
      v34 = 0i64;
    }
    v35 = 5;
    v36 = mGlobalSetting;
    mAddCaptions = this->mAddCaptions;
    if ( (v39 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v38 + 16i64))(v38, v37, v40);
      v38 = 0i64;
    }
    v39 = 2;
    LOBYTE(v40) = mAddCaptions;
    Scaleform::GFx::Movie::Invoke(MovieSafe, "OptionList_SetValues", 0i64, &ptr, 8u);
    `eh vector destructor iterator(&ptr, 0x30ui64, 8, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

