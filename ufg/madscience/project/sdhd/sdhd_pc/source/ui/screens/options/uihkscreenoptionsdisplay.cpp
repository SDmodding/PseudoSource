// File Line: 33
// RVA: 0x156C1F0
__int64 UFG::_dynamic_initializer_for__UI_HASH_MOUSE_MOVE_NEW_SLOT__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("MOUSE_MOVE_NEW_SLOT", 0xFFFFFFFF);
  UI_HASH_MOUSE_MOVE_NEW_SLOT = result;
  return result;
}

// File Line: 60
// RVA: 0x5C6630
void __fastcall UFG::UIHKScreenOptionsDisplay::UIHKScreenOptionsDisplay(UFG::UIHKScreenOptionsDisplay *this)
{
  UFG::UIHKScreenOptionsDisplay *v1; // rbx
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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenOptions::`vftable;
  *(_QWORD *)&this->mState = 0i64;
  this->mOptionChanged = 0;
  *(_QWORD *)&this->mSavingDialogTimer = 0i64;
  this->mHelpBarName = "OPTIONS";
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenOptionsDisplay::`vftable;
  *(_QWORD *)&this->mState = 0i64;
  this->oldScale = 0;
  this->mAddCaptions = 0;
  Render::RenderOutputParams::RenderOutputParams(&this->mOldDisplaySettings);
  Render::RenderOutputParams::RenderOutputParams(&v1->mCurrentDisplaySettings);
  *(_QWORD *)&v1->mDisplayModeCount = 0i64;
  v1->mTentativeDisplayModeIndex = 0;
  v1->mDisplayModes = 0i64;
  v1->mVideoOptionRevertTimer = 0.0;
}

// File Line: 73
// RVA: 0x633B70
void __fastcall UFG::UIHKScreenOptionsDisplay::init(UFG::UIHKScreenOptionsDisplay *this, UFG::UICommandData *data)
{
  UFG::UIHKScreenOptionsDisplay *v2; // rbx
  UFG::Controller *v3; // rcx
  UFG::UIScreenVtbl *v4; // rax
  UFG::UIScreenRenderable *v5; // rax
  Scaleform::GFx::Movie *v6; // rdi

  v2 = this;
  UFG::UIScreen::init((UFG::UIScreen *)&this->vfptr, data);
  if ( UFG::gInputSystem && UFG::gActiveControllerNum != -1 )
  {
    v3 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum];
    if ( !UFG::UI::gUIInputLocked )
      g_saved_gameplay_controller_mode = v3->m_ActiveMapSet;
    UFG::SetInputMode(IM_UI_ONLY, v3->mControllerIndex);
    ++UFG::UI::gUIInputLocked;
  }
  v4 = v2->vfptr;
  v2->mState = 1;
  (*((void (__fastcall **)(UFG::UIHKScreenOptionsDisplay *))&v4[1].__vecDelDtor + 1))(v2);
  v5 = v2->mRenderable;
  v6 = v5->m_movie.pObject;
  if ( v6 )
  {
    Scaleform::GFx::Movie::Invoke(v5->m_movie.pObject, "EnableNonPSOptions", 0i64, 0i64, 0);
    Scaleform::GFx::Movie::Invoke(v6, "OptionList_EnablePCOptions", 0i64, 0i64, 0);
  }
  UFG::UIHKScreenOptionsDisplay::onInit(v2, 1);
}

// File Line: 97
// RVA: 0x638C10
void __fastcall UFG::UIHKScreenOptionsDisplay::onInit(UFG::UIHKScreenOptionsDisplay *this, bool addCaptions)
{
  UFG::UIHKScreenOptionsDisplay *v2; // rdi
  UFG::GameStatTracker *v3; // rbx
  Scaleform::GFx::Movie *v4; // rsi
  double v5; // xmm6_8
  double v6; // xmm6_8
  bool v7; // bl
  bool v8; // bl
  bool v9; // bl
  bool v10; // bl
  double v11; // xmm6_8
  bool v12; // bl
  char ptr; // [rsp+30h] [rbp-B8h]
  __int64 v14; // [rsp+40h] [rbp-A8h]
  unsigned int v15; // [rsp+48h] [rbp-A0h]
  double v16; // [rsp+50h] [rbp-98h]
  char v17; // [rsp+60h] [rbp-88h]
  double v18; // [rsp+68h] [rbp-80h]
  __int64 v19; // [rsp+70h] [rbp-78h]
  unsigned int v20; // [rsp+78h] [rbp-70h]
  __int64 v21; // [rsp+88h] [rbp-60h]
  unsigned int v22; // [rsp+90h] [rbp-58h]
  __int64 v23; // [rsp+98h] [rbp-50h]
  char v24; // [rsp+A8h] [rbp-40h]
  __int64 v25; // [rsp+B8h] [rbp-30h]
  unsigned int v26; // [rsp+C0h] [rbp-28h]
  __int64 v27; // [rsp+C8h] [rbp-20h]
  char v28; // [rsp+D8h] [rbp-10h]
  __int64 v29; // [rsp+E8h] [rbp+0h]
  unsigned int v30; // [rsp+F0h] [rbp+8h]
  __int64 v31; // [rsp+F8h] [rbp+10h]
  char v32; // [rsp+108h] [rbp+20h]
  __int64 v33; // [rsp+118h] [rbp+30h]
  unsigned int v34; // [rsp+120h] [rbp+38h]
  __int64 v35; // [rsp+128h] [rbp+40h]
  char v36; // [rsp+138h] [rbp+50h]
  __int64 v37; // [rsp+148h] [rbp+60h]
  unsigned int v38; // [rsp+150h] [rbp+68h]
  double v39; // [rsp+158h] [rbp+70h]
  char v40; // [rsp+168h] [rbp+80h]
  __int64 v41; // [rsp+178h] [rbp+90h]
  unsigned int v42; // [rsp+180h] [rbp+98h]
  __int64 v43; // [rsp+188h] [rbp+A0h]
  __int64 v44; // [rsp+198h] [rbp+B0h]

  v44 = -2i64;
  v2 = this;
  this->mAddCaptions = addCaptions;
  this->mState = 1;
  this->mOptionChanged = 0;
  v3 = UFG::GameStatTracker::Instance();
  v2->oldGamma = UFG::GameStatTracker::GetStat(v3, Gamma);
  v2->oldScale = UFG::GameStatTracker::GetStat(v3, UIScale);
  v4 = v2->mRenderable->m_movie.pObject;
  if ( v4 )
  {
    Render::GetCurrentDisplaySettings(&v2->mOldDisplaySettings);
    Render::GetCurrentDisplaySettings(&v2->mCurrentDisplaySettings);
    UFG::UIHKScreenOptionsDisplay::PopulateResolutionModes(v2);
    `eh vector constructor iterator(&ptr, 0x30ui64, 8, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    v5 = (double)v2->oldGamma;
    if ( (v15 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v14 + 16i64))(
        v14,
        &ptr,
        COERCE_DOUBLE(*(_QWORD *)&v16));
      v14 = 0i64;
    }
    v15 = 5;
    v16 = v5;
    v6 = (double)v2->oldScale;
    if ( (v20 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v19 + 16i64))(
        v19,
        &v17,
        COERCE_DOUBLE(*(_QWORD *)&v18));
      v19 = 0i64;
    }
    v20 = 5;
    v18 = v6;
    v7 = v2->mOldDisplaySettings.mEnableFullscreen;
    if ( (v22 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, unsigned int *, __int64))(*(_QWORD *)v21 + 16i64))(v21, &v20, v23);
      v21 = 0i64;
    }
    v22 = 2;
    LOBYTE(v23) = v7;
    v8 = v2->mOldDisplaySettings.mEnableVSync;
    if ( (v26 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v25 + 16i64))(v25, &v24, v27);
      v25 = 0i64;
    }
    v26 = 2;
    LOBYTE(v27) = v8;
    v9 = v2->mOldDisplaySettings.mMotionBlur == 2;
    if ( (v30 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v29 + 16i64))(v29, &v28, v31);
      v29 = 0i64;
    }
    v30 = 2;
    LOBYTE(v31) = v9;
    v10 = v2->mOldDisplaySettings.mEnable3D;
    if ( (v34 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v33 + 16i64))(v33, &v32, v35);
      v33 = 0i64;
    }
    v34 = 2;
    LOBYTE(v35) = v10;
    v11 = (double)(signed int)v2->mOldDisplaySettings.mGlobalSetting;
    if ( (v38 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v37 + 16i64))(
        v37,
        &v36,
        COERCE_DOUBLE(*(_QWORD *)&v39));
      v37 = 0i64;
    }
    v38 = 5;
    v39 = v11;
    v12 = v2->mAddCaptions;
    if ( (v42 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v41 + 16i64))(v41, &v40, v43);
      v41 = 0i64;
    }
    v42 = 2;
    LOBYTE(v43) = v12;
    Scaleform::GFx::Movie::Invoke(v4, "OptionList_SetValues", 0i64, (Scaleform::GFx::Value *)&ptr, 8u);
    Scaleform::GFx::Movie::Invoke(v4, "OptionList_PlayIntro", 0i64, 0i64, 0);
    `eh vector destructor iterator(&ptr, 0x30ui64, 8, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 136
// RVA: 0x63E5B0
void __fastcall UFG::UIHKScreenOptionsDisplay::update(UFG::UIHKScreenOptionsDisplay *this, float elapsed)
{
  UFG::UIHKScreenOptionsDisplay *v2; // rbx
  float v3; // xmm1_4
  UFG::UIScreen *v4; // rax
  float v5; // xmm1_4
  UFG::UIScreen *v6; // rax

  v2 = this;
  UFG::UIHKScreenOptions::update((UFG::UIHKScreenOptions *)&this->vfptr, elapsed);
  if ( v2->mState == 3 )
  {
    v5 = v2->mVideoOptionRevertTimer - elapsed;
    v2->mVideoOptionRevertTimer = v5;
    if ( v5 <= 0.0 )
    {
      v2->mState = 1;
      v6 = UFG::UIScreenManagerBase::getScreen(
             (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
             "DialogBox");
      if ( v6 )
        UFG::UIScreenManagerBase::queuePopScreen(
          (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
          v6->mScreenUID);
      UFG::UIHKScreenOptionsDisplay::RevertResolutionMode(v2);
    }
  }
  else if ( v2->mState == 4 )
  {
    v3 = v2->mVideoOptionRevertTimer - elapsed;
    v2->mVideoOptionRevertTimer = v3;
    if ( v3 <= 0.0 )
    {
      v2->mState = 1;
      v4 = UFG::UIScreenManagerBase::getScreen(
             (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
             "DialogBox");
      if ( v4 )
        UFG::UIScreenManagerBase::queuePopScreen(
          (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
          v4->mScreenUID);
      UFG::UIHKScreenOptionsDisplay::RevertFullscreenMode(v2);
    }
  }
}

// File Line: 169
// RVA: 0x6272D0
bool __fastcall UFG::UIHKScreenOptionsDisplay::handleMessage(UFG::UIHKScreenOptionsDisplay *this, unsigned int msgId, UFG::UIMessage *msg)
{
  UFG::UIMessage *v3; // r15
  unsigned int v4; // esi
  UFG::UIHKScreenOptionsDisplay *v5; // rdi
  UFG::GameStatTracker *v6; // r14
  int v7; // ecx
  bool result; // al
  signed __int64 v9; // rcx
  Render::DisplayMode *v10; // rax
  __int128 v11; // xmm0
  int v12; // eax
  int v13; // eax
  int v14; // eax
  bool v15; // bl
  signed __int64 v16; // rcx
  Render::DisplayMode *v17; // rax
  Scaleform::GFx::Movie *v18; // rsi
  bool v19; // bl
  bool v20; // bl
  bool v21; // bl
  bool v22; // bl
  bool v23; // bl
  Render::eGlobalSetting v24; // eax
  signed __int64 v25; // rcx
  Render::DisplayMode *v26; // rax
  __int128 v27; // xmm0
  UFG::GameSaveLoad *v28; // rax
  UFG::GameSaveLoad *v29; // rax
  UFG::GameSaveLoad *v30; // rax
  UFG::UIScreenTextureManager *v31; // rax
  UFG::GameStatTracker *v32; // rax
  UFG::GameStatTracker *v33; // rax
  UFG::GameStatTracker *v34; // rax
  Render::RenderOutputParams settings; // [rsp+50h] [rbp-98h]
  __int128 v36; // [rsp+B8h] [rbp-30h]
  __int128 v37; // [rsp+C8h] [rbp-20h]
  __int128 v38; // [rsp+D8h] [rbp-10h]
  __int128 v39; // [rsp+E8h] [rbp+0h]
  __int128 v40; // [rsp+F8h] [rbp+10h]
  __int64 v41; // [rsp+108h] [rbp+20h]
  UFG::qString v42; // [rsp+118h] [rbp+30h]
  __int64 v43; // [rsp+140h] [rbp+58h]
  UFG::qString option2Text; // [rsp+148h] [rbp+60h]

  v43 = -2i64;
  v3 = msg;
  v4 = msgId;
  v5 = this;
  v6 = UFG::GameStatTracker::Instance();
  v7 = v5->mTentativeDisplayModeIndex;
  if ( v7 != v5->mCurrentDisplayModeIndex )
  {
    if ( v4 == UI_HASH_BUTTON_ACCEPT_PRESSED_30
      || v4 == UI_HASH_BUTTON_BUTTON1_PRESSED_30
      || v4 == (_DWORD)UI_HASH_BUTTON_BUTTON2_PRESSED_30
      || v4 == UI_HASH_DPAD_UP_PRESSED_30
      || v4 == UI_HASH_DPAD_DOWN_PRESSED_30
      || v4 == UI_HASH_MOUSE_MOVE_NEW_SLOT )
    {
      if ( v7 >= 0 && v7 < v5->mDisplayModeCount )
        UFG::GameStatTracker::Instance();
      *(_OWORD *)&settings.mDisplayMode.mBackBufferWidth = *(_OWORD *)&v5->mCurrentDisplaySettings.mDisplayMode.mBackBufferWidth;
      *(_OWORD *)&settings.mDisplayMode.mAdapterUID = *(_OWORD *)&v5->mCurrentDisplaySettings.mDisplayMode.mAdapterUID;
      *(_OWORD *)&settings.mEnableFullscreen = *(_OWORD *)&v5->mCurrentDisplaySettings.mEnableFullscreen;
      *(_OWORD *)&settings.mDisplayMode.mScaling = *(_OWORD *)&v5->mCurrentDisplaySettings.mShadowFilter;
      *(_OWORD *)&settings.mAAQuality = *(_OWORD *)&v5->mCurrentDisplaySettings.mFPSLimiter;
      *(_OWORD *)&settings.mInterAxialDistance = *(_OWORD *)&v5->mCurrentDisplaySettings.mLODSetting;
      *(_QWORD *)&settings.m3DDepth = *(_QWORD *)&v5->mCurrentDisplaySettings.mTextureFilterQuality;
      v9 = v5->mTentativeDisplayModeIndex;
      v10 = v5->mDisplayModes;
      *(_OWORD *)&settings.mDisplayMode.mBackBufferWidth = *(_OWORD *)&v10[v9].mBackBufferWidth;
      *(_OWORD *)&settings.mDisplayMode.mAdapterUID = *(_OWORD *)&v10[v9].mAdapterUID;
      if ( UFG::UIHKScreenOptionsDisplay::ApplyRenderOptions(v5, &settings) )
      {
        v11 = COERCE_UNSIGNED_INT((float)(signed int)v5->mCurrentDisplaySettings.mDisplayMode.mBackBufferHeight);
        UFG::UIScreenManagerBase::setFontScale(
          (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
          1.0);
        UFG::UI::RefreshScreenHD((UFG::UIScreen *)&v5->vfptr);
        Scaleform::GFx::Movie::Invoke(v5->mRenderable->m_movie.pObject, "OptionListUpdateSDText", 0i64, 0i64, 0);
        v5->mState = 3;
        UFG::qString::qString(&v42, "$OPTIONS_YES");
        UFG::qString::qString(&option2Text, "$OPTIONS_NO");
        UFG::UIScreenDialogBox::createTwoButtonDialog(
          (UFG::UIScreen *)&v5->vfptr,
          &customWorldMapCaption,
          "$OPTIONS_DIALOG_VIDEO_CHANGED",
          v42.mData,
          UI_HASH_DIALOG_YES_30,
          option2Text.mData,
          UI_HASH_DIALOG_NO_30,
          DIALOG_BUTTON2,
          1,
          "DialogBox");
        UFG::qString::~qString(&option2Text);
        UFG::qString::~qString(&v42);
        v5->mVideoOptionRevertTimer = 15.0;
      }
      else
      {
        v5->mState = 5;
        UFG::qString::qString(&v42, "$COMMON_OK_UPPERCASE");
        UFG::UIScreenDialogBox::createOneButtonDialog(
          (UFG::UIScreen *)&v5->vfptr,
          &customWorldMapCaption,
          "$OPTIONS_DIALOG_INVALID_DISPLAY_SETTINGS",
          v42.mData,
          UI_HASH_DIALOG_OK_30,
          1,
          "DialogBox");
        UFG::qString::~qString(&v42);
        UFG::UIHKScreenOptionsDisplay::RevertResolutionMode(v5);
      }
      return 1;
    }
    if ( v4 == UI_HASH_BUTTON_BACK_PRESSED_30 )
    {
      UFG::UIHKScreenOptionsDisplay::RevertResolutionMode(v5);
      return 1;
    }
  }
  if ( v4 == UI_HASH_INTRO_COMPLETE_30 )
  {
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        0x688D286Au,
        0i64,
        0,
        0i64);
    return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
  }
  if ( v4 == UI_HASH_OPTION_HIGHLIGHTED_30 )
  {
    v12 = UFG::UIHKScreenOptions::GetSelectedSlot((UFG::UIHKScreenOptions *)&v5->vfptr);
    UFG::UIHKScreenOptionsDisplay::Flash_SetScaleCornersVisible(v5, v12 == 1);
    goto LABEL_61;
  }
  if ( v4 == UI_HASH_OPTIONS_SCALE_20 )
  {
    v5->mOptionChanged = 1;
    v13 = UFG::UI::GetFlashArgsInt(v3);
    UFG::gUIViewportScale = (float)((float)((float)v13 * 0.1) * 0.15000001) + 0.85000002;
    UFG::GameStatTracker::SetStat(v6, UIScale, v13);
    return 1;
  }
  if ( v4 == UI_HASH_OPTIONS_BRIGHTNESS_20 )
  {
    v5->mOptionChanged = 1;
    v14 = UFG::UI::GetFlashArgsInt(v3);
    UFG::GameStatTracker::SetStat(v6, Gamma, v14);
    return 1;
  }
  if ( v4 == UI_HASH_OPTIONS_RESOLUTION_20 )
  {
    v5->mOptionChanged = 1;
    v5->mTentativeDisplayModeIndex = UFG::UI::GetFlashArgsInt(v3);
    return 1;
  }
  if ( v4 == UI_HASH_OPTIONS_FULLSCREEN_20 )
  {
    v15 = (unsigned int)UFG::UI::GetFlashArgsInt(v3) == 1;
    if ( v5->mCurrentDisplaySettings.mEnableFullscreen != v15 )
    {
      v5->mOptionChanged = 1;
      UFG::GameStatTracker::SetStat(v6, Display_IsFullscreen, v15);
      *(_OWORD *)&settings.mDisplayMode.mBackBufferWidth = *(_OWORD *)&v5->mCurrentDisplaySettings.mDisplayMode.mBackBufferWidth;
      *(_OWORD *)&settings.mDisplayMode.mAdapterUID = *(_OWORD *)&v5->mCurrentDisplaySettings.mDisplayMode.mAdapterUID;
      *(_OWORD *)&settings.mEnableFullscreen = *(_OWORD *)&v5->mCurrentDisplaySettings.mEnableFullscreen;
      *(_OWORD *)&settings.mDisplayMode.mScaling = *(_OWORD *)&v5->mCurrentDisplaySettings.mShadowFilter;
      *(_OWORD *)&settings.mAAQuality = *(_OWORD *)&v5->mCurrentDisplaySettings.mFPSLimiter;
      *(_OWORD *)&settings.mInterAxialDistance = *(_OWORD *)&v5->mCurrentDisplaySettings.mLODSetting;
      *(_QWORD *)&settings.m3DDepth = *(_QWORD *)&v5->mCurrentDisplaySettings.mTextureFilterQuality;
      v16 = v5->mTentativeDisplayModeIndex;
      v17 = v5->mDisplayModes;
      *(_OWORD *)&settings.mDisplayMode.mBackBufferWidth = *(_OWORD *)&v17[v16].mBackBufferWidth;
      *(_OWORD *)&settings.mDisplayMode.mAdapterUID = *(_OWORD *)&v17[v16].mAdapterUID;
      settings.mEnableFullscreen = v15;
      if ( UFG::UIHKScreenOptionsDisplay::ApplyRenderOptions(v5, &settings) )
      {
        if ( v15 )
        {
          v5->mState = 4;
          UFG::UIScreenDialogBox::createYesNoDialog(
            (UFG::UIScreen *)&v5->vfptr,
            &customWorldMapCaption,
            "$OPTIONS_DIALOG_VIDEO_CHANGED",
            0,
            1);
          v5->mVideoOptionRevertTimer = 15.0;
        }
      }
      else
      {
        v5->mState = 5;
        UFG::UIScreenDialogBox::createOKDialog(
          (UFG::UIScreen *)&v5->vfptr,
          &customWorldMapCaption,
          "$OPTIONS_DIALOG_INVALID_DISPLAY_SETTINGS",
          1);
        UFG::UIHKScreenOptionsDisplay::RevertFullscreenMode(v5);
      }
      v18 = v5->mRenderable->m_movie.pObject;
      `eh vector constructor iterator(
        &settings.mDeviceType,
        0x30ui64,
        2,
        (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      v19 = v5->mCurrentDisplaySettings.mEnableFullscreen;
      if ( (DWORD2(v36) >> 6) & 1 )
      {
        (*(void (__fastcall **)(_QWORD, Render::eDeviceType *, _QWORD))(*(_QWORD *)v36 + 16i64))(
          v36,
          &settings.mDeviceType,
          v37);
        *(_QWORD *)&v36 = 0i64;
      }
      DWORD2(v36) = 2;
      LOBYTE(v37) = v19;
      v20 = v5->mCurrentDisplaySettings.mEnableVSync;
      if ( (DWORD2(v39) >> 6) & 1 )
      {
        (*(void (__fastcall **)(_QWORD, __int128 *, _QWORD))(*(_QWORD *)v39 + 16i64))(v39, &v38, v40);
        *(_QWORD *)&v39 = 0i64;
      }
      DWORD2(v39) = 2;
      LOBYTE(v40) = v20;
      Scaleform::GFx::Movie::Invoke(
        v18,
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
  if ( v4 == UI_HASH_OPTIONS_VSYNC_20 )
  {
    v5->mOptionChanged = 1;
    v21 = (unsigned int)UFG::UI::GetFlashArgsInt(v3) == 1;
    UFG::GameStatTracker::SetStat(v6, Display_EnableVSync, v21);
    v5->mCurrentDisplaySettings.mEnableVSync = v21;
  }
  else if ( v4 == UI_HASH_OPTIONS_QUALITY_MOTION_BLUR_20 )
  {
    v5->mOptionChanged = 1;
    v22 = (unsigned int)UFG::UI::GetFlashArgsInt(v3) == 1;
    UFG::GameStatTracker::SetStat(v6, Display_HighQualityMotionBlur, v22);
    v5->mCurrentDisplaySettings.mMotionBlur = (v22 != 0) + 1;
  }
  else if ( v4 == UI_HASH_OPTIONS_ENABLE_3D_20 )
  {
    v5->mOptionChanged = 1;
    v23 = (unsigned int)UFG::UI::GetFlashArgsInt(v3) == 1;
    UFG::GameStatTracker::SetStat(v6, Display_Enable3D, v23);
    v5->mCurrentDisplaySettings.mEnable3D = v23;
  }
  else if ( v4 == UI_HASH_OPTIONS_GRAPHICS_LEVEL_20 )
  {
    v5->mOptionChanged = 1;
    v24 = (unsigned int)UFG::UI::GetFlashArgsInt(v3);
    Render::RenderOutputParams::ChangeGlobalSetting(&v5->mCurrentDisplaySettings, v24);
  }
  else
  {
    if ( v4 == (_DWORD)UI_HASH_BUTTON_BUTTON2_PRESSED_30 )
    {
      UFG::UIHKScreenOptionsDisplay::RevertResolutionMode(v5);
      UFG::UIScreenDialogBox::createYesNoDialog(
        (UFG::UIScreen *)&v5->vfptr,
        "$OPTIONS_OPTIONS_CHANGED",
        "$OPTIONS_SAVE_CHANGES",
        1,
        1);
      v5->mState = 6;
      return 1;
    }
    if ( v4 == UI_HASH_DIALOG_YES_30 )
    {
      if ( v5->mState == 6 )
      {
        v5->mOptionChanged = 0;
        if ( v7 >= 0 && v7 < v5->mDisplayModeCount )
          UFG::GameStatTracker::Instance();
        *(_OWORD *)&settings.mDisplayMode.mBackBufferWidth = *(_OWORD *)&v5->mCurrentDisplaySettings.mDisplayMode.mBackBufferWidth;
        *(_OWORD *)&settings.mDisplayMode.mAdapterUID = *(_OWORD *)&v5->mCurrentDisplaySettings.mDisplayMode.mAdapterUID;
        *(_OWORD *)&settings.mEnableFullscreen = *(_OWORD *)&v5->mCurrentDisplaySettings.mEnableFullscreen;
        *(_OWORD *)&settings.mDisplayMode.mScaling = *(_OWORD *)&v5->mCurrentDisplaySettings.mShadowFilter;
        *(_OWORD *)&settings.mAAQuality = *(_OWORD *)&v5->mCurrentDisplaySettings.mFPSLimiter;
        *(_OWORD *)&settings.mInterAxialDistance = *(_OWORD *)&v5->mCurrentDisplaySettings.mLODSetting;
        *(_QWORD *)&settings.m3DDepth = *(_QWORD *)&v5->mCurrentDisplaySettings.mTextureFilterQuality;
        v25 = v5->mTentativeDisplayModeIndex;
        v26 = v5->mDisplayModes;
        *(_OWORD *)&settings.mDisplayMode.mBackBufferWidth = *(_OWORD *)&v26[v25].mBackBufferWidth;
        *(_OWORD *)&settings.mDisplayMode.mAdapterUID = *(_OWORD *)&v26[v25].mAdapterUID;
        if ( !UFG::UIHKScreenOptionsDisplay::ApplyRenderOptions(v5, &settings) )
        {
          v5->mState = 5;
          UFG::UIScreenDialogBox::createOKDialog(
            (UFG::UIScreen *)&v5->vfptr,
            &customWorldMapCaption,
            "$OPTIONS_DIALOG_INVALID_DISPLAY_SETTINGS",
            1);
          UFG::UIHKScreenOptionsDisplay::RevertResolutionMode(v5);
          return 1;
        }
        v27 = COERCE_UNSIGNED_INT((float)(signed int)v5->mCurrentDisplaySettings.mDisplayMode.mBackBufferHeight);
        UFG::UIScreenManagerBase::setFontScale(
          (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
          1.0);
        UFG::UI::RefreshScreenHD((UFG::UIScreen *)&v5->vfptr);
        Scaleform::GFx::Movie::Invoke(v5->mRenderable->m_movie.pObject, "OptionListUpdateSDText", 0i64, 0i64, 0);
        v5->mState = 1;
        Render::RenderOutputParams::RenderOutputParams((Render::RenderOutputParams *)((char *)&settings + 88));
        *(_OWORD *)&settings.mDeviceType = *(_OWORD *)&v5->mCurrentDisplaySettings.mDisplayMode.mBackBufferWidth;
        v36 = *(_OWORD *)&v5->mCurrentDisplaySettings.mDisplayMode.mAdapterUID;
        v37 = *(_OWORD *)&v5->mCurrentDisplaySettings.mEnableFullscreen;
        v38 = *(_OWORD *)&v5->mCurrentDisplaySettings.mShadowFilter;
        v39 = *(_OWORD *)&v5->mCurrentDisplaySettings.mFPSLimiter;
        v40 = *(_OWORD *)&v5->mCurrentDisplaySettings.mLODSetting;
        v41 = *(_QWORD *)&v5->mCurrentDisplaySettings.mTextureFilterQuality;
        UFG::GameStatPCDisplaySettings::SaveToXML(
          (UFG::GameStatPCDisplaySettings *)&settings.mDeviceType,
          UFG::GameStatPCDisplaySettings::gDefaultSavePath);
        return 1;
      }
    }
    else if ( v4 == UI_HASH_DIALOG_NO_30 && v5->mState == 6 )
    {
      ((void (__fastcall *)(UFG::UIHKScreenOptionsDisplay *))v5->vfptr[1].handleMessage)(v5);
      v28 = UFG::GameSaveLoad::Instance();
      UFG::GameSaveLoad::ApplyOptions(v28);
      v5->mState = 1;
      return 1;
    }
  }
LABEL_61:
  if ( v5->mState == 1 )
  {
    if ( v4 == UI_HASH_BUTTON_BUTTON1_PRESSED_30 )
    {
      v31 = UFG::UIScreenTextureManager::Instance();
      UFG::UIScreenTextureManager::QueueLoadAndPush(v31, "Options_DisplayAdvanced", 0i64);
      result = 1;
    }
    else
    {
      if ( v4 == UI_HASH_BUTTON_SELECT_PRESSED_30 )
      {
        v32 = UFG::GameStatTracker::Instance();
        UFG::GameStatTracker::SetStat(v32, Gamma, 50);
        v33 = UFG::GameStatTracker::Instance();
        UFG::GameStatTracker::SetStat(v33, UIScale, 10);
        v34 = UFG::GameStatTracker::Instance();
        UFG::gUIViewportScale = (float)((float)((float)(signed int)UFG::GameStatTracker::GetStat(v34, UIScale) * 0.1)
                                      * 0.15000001)
                              + 0.85000002;
        Render::RenderOutputParams::SetDefault(&v5->mCurrentDisplaySettings);
        ((void (__fastcall *)(UFG::UIHKScreenOptionsDisplay *))v5->vfptr[1].update)(v5);
        UFG::UIHKScreenOptionsDisplay::Flash_RefreshValues(v5);
      }
      result = UFG::UIHKScreenOptions::handleMessage((UFG::UIHKScreenOptions *)&v5->vfptr, v4, v3);
    }
  }
  else
  {
    if ( v5->mState == 3 )
    {
      if ( v4 == UI_HASH_DIALOG_YES_30 )
      {
        v5->mState = 1;
        v5->mCurrentDisplayModeIndex = v5->mTentativeDisplayModeIndex;
        v29 = UFG::GameSaveLoad::Instance();
        UFG::GameSaveLoad::ApplyOptions(v29);
        v30 = UFG::GameSaveLoad::Instance();
        UFG::GameSaveLoad::SaveGameOptions(v30);
        UFG::DataSynchronizer::SetOptionsDirty();
        v5->mOptionChanged = 0;
        v5->mOldDisplaySettings.mDisplayMode.mBackBufferWidth = v5->mCurrentDisplaySettings.mDisplayMode.mBackBufferWidth;
        v5->mOldDisplaySettings.mDisplayMode.mBackBufferHeight = v5->mCurrentDisplaySettings.mDisplayMode.mBackBufferHeight;
        v5->mOldDisplaySettings.mDisplayMode.mRefreshRateNumerator = v5->mCurrentDisplaySettings.mDisplayMode.mRefreshRateNumerator;
        v5->mOldDisplaySettings.mDisplayMode.mRefreshRateDenominator = v5->mCurrentDisplaySettings.mDisplayMode.mRefreshRateDenominator;
        v5->mOldDisplaySettings.mDisplayMode.mAdapterUID = v5->mCurrentDisplaySettings.mDisplayMode.mAdapterUID;
        v5->mOldDisplaySettings.mDisplayMode.mMonitorUID = v5->mCurrentDisplaySettings.mDisplayMode.mMonitorUID;
        v5->mOldDisplaySettings.mDisplayMode.mScaling = v5->mCurrentDisplaySettings.mDisplayMode.mScaling;
        v5->mOldDisplaySettings.mDisplayMode.mScanlineMode = v5->mCurrentDisplaySettings.mDisplayMode.mScanlineMode;
        *(_DWORD *)&v5->mOldDisplaySettings.mEnableFullscreen = *(_DWORD *)&v5->mCurrentDisplaySettings.mEnableFullscreen;
        *(_DWORD *)&v5->mOldDisplaySettings.mEnableCloudVolumes = *(_DWORD *)&v5->mCurrentDisplaySettings.mEnableCloudVolumes;
        v5->mOldDisplaySettings.mAAQuality = v5->mCurrentDisplaySettings.mAAQuality;
        v5->mOldDisplaySettings.mShadowRes = v5->mCurrentDisplaySettings.mShadowRes;
        v5->mOldDisplaySettings.mShadowFilter = v5->mCurrentDisplaySettings.mShadowFilter;
        v5->mOldDisplaySettings.mMotionBlur = v5->mCurrentDisplaySettings.mMotionBlur;
        v5->mOldDisplaySettings.mInterAxialDistance = v5->mCurrentDisplaySettings.mInterAxialDistance;
        v5->mOldDisplaySettings.mSSAO = v5->mCurrentDisplaySettings.mSSAO;
        v5->mOldDisplaySettings.mFPSLimiter = v5->mCurrentDisplaySettings.mFPSLimiter;
        v5->mOldDisplaySettings.mFeatureLevel = v5->mCurrentDisplaySettings.mFeatureLevel;
        v5->mOldDisplaySettings.m3DDepth = v5->mCurrentDisplaySettings.m3DDepth;
        v5->mOldDisplaySettings.m3DConvergence = v5->mCurrentDisplaySettings.m3DConvergence;
        v5->mOldDisplaySettings.mLODSetting = v5->mCurrentDisplaySettings.mLODSetting;
        v5->mOldDisplaySettings.mGlobalSetting = v5->mCurrentDisplaySettings.mGlobalSetting;
        v5->mOldDisplaySettings.mDeviceType = v5->mCurrentDisplaySettings.mDeviceType;
        v5->mOldDisplaySettings.mTimeStepSmoothingFrames = v5->mCurrentDisplaySettings.mTimeStepSmoothingFrames;
        v5->mOldDisplaySettings.mTextureFilterQuality = v5->mCurrentDisplaySettings.mTextureFilterQuality;
        v5->mOldDisplaySettings.mTextureDetailLevel = v5->mCurrentDisplaySettings.mTextureDetailLevel;
        Render::RenderOutputParams::RenderOutputParams(&settings);
        *(_OWORD *)&settings.mDisplayMode.mBackBufferWidth = *(_OWORD *)&v5->mCurrentDisplaySettings.mDisplayMode.mBackBufferWidth;
        *(_OWORD *)&settings.mDisplayMode.mAdapterUID = *(_OWORD *)&v5->mCurrentDisplaySettings.mDisplayMode.mAdapterUID;
        *(_OWORD *)&settings.mEnableFullscreen = *(_OWORD *)&v5->mCurrentDisplaySettings.mEnableFullscreen;
        *(_OWORD *)&settings.mDisplayMode.mScaling = *(_OWORD *)&v5->mCurrentDisplaySettings.mShadowFilter;
        *(_OWORD *)&settings.mAAQuality = *(_OWORD *)&v5->mCurrentDisplaySettings.mFPSLimiter;
        *(_OWORD *)&settings.mInterAxialDistance = *(_OWORD *)&v5->mCurrentDisplaySettings.mLODSetting;
        *(_QWORD *)&settings.m3DDepth = *(_QWORD *)&v5->mCurrentDisplaySettings.mTextureFilterQuality;
        UFG::GameStatPCDisplaySettings::SaveToXML(
          (UFG::GameStatPCDisplaySettings *)&settings,
          UFG::GameStatPCDisplaySettings::gDefaultSavePath);
        UFG::UIHKScreenOptionsDisplay::RefreshHighDef(v5);
        return 1;
      }
      if ( v4 == UI_HASH_DIALOG_NO_30 )
      {
        v5->mState = 1;
        UFG::UIHKScreenOptionsDisplay::RevertResolutionMode(v5);
        return 1;
      }
    }
    else if ( v5->mState == 4 )
    {
      if ( v4 == UI_HASH_DIALOG_YES_30 )
      {
        v5->mState = 1;
        v5->mOldDisplaySettings.mDisplayMode.mBackBufferWidth = v5->mCurrentDisplaySettings.mDisplayMode.mBackBufferWidth;
        v5->mOldDisplaySettings.mDisplayMode.mBackBufferHeight = v5->mCurrentDisplaySettings.mDisplayMode.mBackBufferHeight;
        v5->mOldDisplaySettings.mDisplayMode.mRefreshRateNumerator = v5->mCurrentDisplaySettings.mDisplayMode.mRefreshRateNumerator;
        v5->mOldDisplaySettings.mDisplayMode.mRefreshRateDenominator = v5->mCurrentDisplaySettings.mDisplayMode.mRefreshRateDenominator;
        v5->mOldDisplaySettings.mDisplayMode.mAdapterUID = v5->mCurrentDisplaySettings.mDisplayMode.mAdapterUID;
        v5->mOldDisplaySettings.mDisplayMode.mMonitorUID = v5->mCurrentDisplaySettings.mDisplayMode.mMonitorUID;
        v5->mOldDisplaySettings.mDisplayMode.mScaling = v5->mCurrentDisplaySettings.mDisplayMode.mScaling;
        v5->mOldDisplaySettings.mDisplayMode.mScanlineMode = v5->mCurrentDisplaySettings.mDisplayMode.mScanlineMode;
        *(_DWORD *)&v5->mOldDisplaySettings.mEnableFullscreen = *(_DWORD *)&v5->mCurrentDisplaySettings.mEnableFullscreen;
        *(_DWORD *)&v5->mOldDisplaySettings.mEnableCloudVolumes = *(_DWORD *)&v5->mCurrentDisplaySettings.mEnableCloudVolumes;
        v5->mOldDisplaySettings.mAAQuality = v5->mCurrentDisplaySettings.mAAQuality;
        v5->mOldDisplaySettings.mShadowRes = v5->mCurrentDisplaySettings.mShadowRes;
        v5->mOldDisplaySettings.mShadowFilter = v5->mCurrentDisplaySettings.mShadowFilter;
        v5->mOldDisplaySettings.mMotionBlur = v5->mCurrentDisplaySettings.mMotionBlur;
        v5->mOldDisplaySettings.mInterAxialDistance = v5->mCurrentDisplaySettings.mInterAxialDistance;
        v5->mOldDisplaySettings.mSSAO = v5->mCurrentDisplaySettings.mSSAO;
        v5->mOldDisplaySettings.mFPSLimiter = v5->mCurrentDisplaySettings.mFPSLimiter;
        v5->mOldDisplaySettings.mFeatureLevel = v5->mCurrentDisplaySettings.mFeatureLevel;
        v5->mOldDisplaySettings.m3DDepth = v5->mCurrentDisplaySettings.m3DDepth;
        v5->mOldDisplaySettings.m3DConvergence = v5->mCurrentDisplaySettings.m3DConvergence;
        v5->mOldDisplaySettings.mLODSetting = v5->mCurrentDisplaySettings.mLODSetting;
        v5->mOldDisplaySettings.mGlobalSetting = v5->mCurrentDisplaySettings.mGlobalSetting;
        v5->mOldDisplaySettings.mDeviceType = v5->mCurrentDisplaySettings.mDeviceType;
        v5->mOldDisplaySettings.mTimeStepSmoothingFrames = v5->mCurrentDisplaySettings.mTimeStepSmoothingFrames;
        v5->mOldDisplaySettings.mTextureFilterQuality = v5->mCurrentDisplaySettings.mTextureFilterQuality;
        v5->mOldDisplaySettings.mTextureDetailLevel = v5->mCurrentDisplaySettings.mTextureDetailLevel;
        return 1;
      }
      if ( v4 == UI_HASH_DIALOG_NO_30 )
      {
        v5->mState = 1;
        UFG::UIHKScreenOptionsDisplay::RevertFullscreenMode(v5);
        return 1;
      }
    }
    else if ( v5->mState == 5 && v4 == UI_HASH_DIALOG_OK_30 )
    {
      v5->mState = 1;
      return 1;
    }
    result = 0;
  }
  return result;
}

// File Line: 484
// RVA: 0x61FEF0
void __fastcall UFG::UIHKScreenOptionsDisplay::dim(UFG::UIHKScreenOptionsDisplay *this, UFG::UIScreen::eDimType dimType, bool instant)
{
  UFG::UIHKScreenOptionsDisplay *v3; // rbx
  Scaleform::GFx::Movie *v4; // rcx

  v3 = this;
  UFG::UIScreen::dim((UFG::UIScreen *)&this->vfptr, dimType, instant);
  v4 = v3->mRenderable->m_movie.pObject;
  if ( v4 )
    Scaleform::GFx::Movie::Invoke(v4, "dim", 0i64, 0i64, 0);
}

// File Line: 495
// RVA: 0x63B6D0
void __fastcall UFG::UIHKScreenOptionsDisplay::undim(UFG::UIHKScreenOptionsDisplay *this, bool instant)
{
  UFG::UIHKScreenOptionsDisplay *v2; // rbx
  Scaleform::GFx::Movie *v3; // rcx

  v2 = this;
  UFG::UIScreen::undim((UFG::UIScreen *)&this->vfptr, instant);
  v3 = v2->mRenderable->m_movie.pObject;
  if ( v3 )
    Scaleform::GFx::Movie::Invoke(v3, "undim", 0i64, 0i64, 0);
}

// File Line: 506
// RVA: 0x5D5C40
float __fastcall UFG::UIHKScreenOptionsDisplay::ConvertScaleOption(unsigned int optionValue)
{
  return (float)((float)((float)(signed int)optionValue * 0.1) * 0.15000001) + 0.85000002;
}

// File Line: 523
// RVA: 0x5D3BC0
void __fastcall UFG::UIHKScreenOptionsDisplay::ApplyOptions(UFG::UIHKScreenOptionsDisplay *this)
{
  Render::RenderOutputParams *v1; // rbx
  __int128 v2; // xmm1
  __int128 v3; // xmm1
  __int128 v4; // xmm1
  Render::RenderOutputParams v5; // [rsp+20h] [rbp-78h]

  v1 = &this->mCurrentDisplaySettings;
  if ( UFG::UIHKScreenOptionsDisplay::ApplyRenderOptions(this, &this->mCurrentDisplaySettings) )
  {
    Render::RenderOutputParams::RenderOutputParams(&v5);
    v2 = *(_OWORD *)&v1->mDisplayMode.mAdapterUID;
    *(_OWORD *)&v5.mDisplayMode.mBackBufferWidth = *(_OWORD *)&v1->mDisplayMode.mBackBufferWidth;
    *(_OWORD *)&v5.mDisplayMode.mAdapterUID = v2;
    v3 = *(_OWORD *)&v1->mShadowFilter;
    *(_OWORD *)&v5.mEnableFullscreen = *(_OWORD *)&v1->mEnableFullscreen;
    *(_OWORD *)&v5.mShadowFilter = v3;
    v4 = *(_OWORD *)&v1->mLODSetting;
    *(_OWORD *)&v5.mFPSLimiter = *(_OWORD *)&v1->mFPSLimiter;
    *(_OWORD *)&v5.mLODSetting = v4;
    *(_QWORD *)&v5.mTextureFilterQuality = *(_QWORD *)&v1->mTextureFilterQuality;
    UFG::GameStatPCDisplaySettings::SaveToXML(
      (UFG::GameStatPCDisplaySettings *)&v5,
      UFG::GameStatPCDisplaySettings::gDefaultSavePath);
  }
}

// File Line: 540
// RVA: 0x6030A0
void __fastcall UFG::UIHKScreenOptionsDisplay::RestoreOptions(UFG::UIHKScreenOptionsDisplay *this)
{
  UFG::UIHKScreenOptionsDisplay *v1; // rdi
  UFG::GameStatTracker *v2; // rbx

  v1 = this;
  v2 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::SetStat(v2, Gamma, v1->oldGamma);
  UFG::GameStatTracker::SetStat(v2, UIScale, v1->oldScale);
}

// File Line: 562
// RVA: 0x5D3D30
char __fastcall UFG::UIHKScreenOptionsDisplay::ApplyRenderOptions(UFG::UIHKScreenOptionsDisplay *this, Render::RenderOutputParams *settings)
{
  UFG::UIHKScreenOptionsDisplay *v2; // rdi
  Render::RenderOutputParams *v3; // rbx
  Render::RenderOutputParams *v4; // rcx

  v2 = this;
  v3 = settings;
  if ( !Render::ValidateDisplaySettings(settings) )
    return 0;
  v4 = &v2->mCurrentDisplaySettings;
  v4->mDisplayMode.mBackBufferWidth = v3->mDisplayMode.mBackBufferWidth;
  v4->mDisplayMode.mBackBufferHeight = v3->mDisplayMode.mBackBufferHeight;
  v4->mDisplayMode.mRefreshRateNumerator = v3->mDisplayMode.mRefreshRateNumerator;
  v4->mDisplayMode.mRefreshRateDenominator = v3->mDisplayMode.mRefreshRateDenominator;
  v4->mDisplayMode.mAdapterUID = v3->mDisplayMode.mAdapterUID;
  v4->mDisplayMode.mMonitorUID = v3->mDisplayMode.mMonitorUID;
  v4->mDisplayMode.mScaling = v3->mDisplayMode.mScaling;
  v4->mDisplayMode.mScanlineMode = v3->mDisplayMode.mScanlineMode;
  *(_DWORD *)&v4->mEnableFullscreen = *(_DWORD *)&v3->mEnableFullscreen;
  *(_DWORD *)&v4->mEnableCloudVolumes = *(_DWORD *)&v3->mEnableCloudVolumes;
  v4->mAAQuality = v3->mAAQuality;
  v4->mShadowRes = v3->mShadowRes;
  v4->mShadowFilter = v3->mShadowFilter;
  v4->mMotionBlur = v3->mMotionBlur;
  v4->mInterAxialDistance = v3->mInterAxialDistance;
  v4->mSSAO = v3->mSSAO;
  v4->mFPSLimiter = v3->mFPSLimiter;
  v4->mFeatureLevel = v3->mFeatureLevel;
  v4->m3DDepth = v3->m3DDepth;
  v4->m3DConvergence = v3->m3DConvergence;
  v4->mLODSetting = v3->mLODSetting;
  v4->mGlobalSetting = v3->mGlobalSetting;
  v4->mDeviceType = v3->mDeviceType;
  v4->mTimeStepSmoothingFrames = v3->mTimeStepSmoothingFrames;
  v4->mTextureFilterQuality = v3->mTextureFilterQuality;
  v4->mTextureDetailLevel = v3->mTextureDetailLevel;
  Render::ApplyDisplaySettings(&v2->mCurrentDisplaySettings);
  return 1;
}

// File Line: 579
// RVA: 0x6005F0
void __fastcall UFG::UIHKScreenOptionsDisplay::RefreshHighDef(UFG::UIHKScreenOptionsDisplay *this)
{
  UFG::UIHKScreenOptionsDisplay *v1; // rbx
  UFG::UIHKScreenGlobalOverlay *v2; // rbx
  UFG::UIHKScreenGlobalOverlay *v3; // rcx

  v1 = this;
  gUIHorizontalResolution = (float)Render::GetBackBufferTarget()->mWidth;
  gUIVerticalResolution = (float)Render::GetBackBufferTarget()->mHeight;
  gIsUIHighDef = gUIVerticalResolution >= 720.0;
  UFG::UIScreenManagerBase::setFontScale((UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr, 1.0);
  UFG::UI::RefreshScreenHD((UFG::UIScreen *)&v1->vfptr);
  Scaleform::GFx::Movie::Invoke(v1->mRenderable->m_movie.pObject, "OptionListUpdateSDText", 0i64, 0i64, 0);
  v2 = &gGlobalOverlaySentinel;
  v3 = &gGlobalOverlaySentinel;
  if ( UFG::UIHKScreenGlobalOverlay::mThis )
    v3 = UFG::UIHKScreenGlobalOverlay::mThis;
  UFG::UI::RefreshScreenHD((UFG::UIScreen *)&v3->vfptr);
  if ( UFG::UIHKScreenGlobalOverlay::mThis )
    v2 = UFG::UIHKScreenGlobalOverlay::mThis;
  v2->HelpBar.mChanged = 1;
}

// File Line: 600
// RVA: 0x5FA9A0
void __fastcall UFG::UIHKScreenOptionsDisplay::PopulateResolutionModes(UFG::UIHKScreenOptionsDisplay *this)
{
  UFG::UIHKScreenOptionsDisplay *v1; // rbx
  Scaleform::GFx::Movie *v2; // r13
  __int64 v3; // rdi
  signed int v4; // eax
  Render::DisplayMode *v5; // rcx
  unsigned __int64 v6; // rcx
  unsigned __int64 v7; // rax
  Render::DisplayMode *v8; // rax
  char v9; // r12
  int v10; // er15
  Render::DisplayMode *v11; // rsi
  float v12; // xmm6_4
  unsigned int v13; // ecx
  float v14; // xmm1_4
  float v15; // xmm0_4
  const char *v16; // rdx
  float v17; // xmm0_4
  float v18; // xmm1_4
  char *v19; // r14
  long double v20; // xmm6_8
  Render::DisplayMode filter; // [rsp+30h] [rbp-A8h]
  Scaleform::GFx::Value pargs; // [rsp+50h] [rbp-88h]
  UFG::qString v23; // [rsp+88h] [rbp-50h]
  __int64 v24; // [rsp+B0h] [rbp-28h]
  UFG::qString v25; // [rsp+B8h] [rbp-20h]
  UFG::qString v26; // [rsp+E8h] [rbp+10h]

  v24 = -2i64;
  v1 = this;
  v2 = this->mRenderable->m_movie.pObject;
  v3 = 0i64;
  Scaleform::GFx::Movie::Invoke(this->mRenderable->m_movie.pObject, "OptionList_ClearResolutions", 0i64, 0i64, 0);
  *(_QWORD *)&filter.mBackBufferWidth = 0i64;
  *(_QWORD *)&filter.mRefreshRateNumerator = 0i64;
  *(_QWORD *)&filter.mAdapterUID = 0i64;
  filter.mScaling = -1;
  filter.mScanlineMode = 1;
  v4 = Render::GetDisplayModeCount(&filter);
  v1->mDisplayModeCount = v4;
  if ( v4 < 1 )
  {
    filter.mScanlineMode = -1;
    v1->mDisplayModeCount = Render::GetDisplayModeCount(&filter);
  }
  if ( v1->mDisplayModeCount >= 1 )
  {
    v5 = v1->mDisplayModes;
    if ( v5 )
      operator delete[](v5);
    v6 = v1->mDisplayModeCount;
    v7 = 32 * v6;
    if ( !is_mul_ok(v6, 0x20ui64) )
      v7 = -1i64;
    v8 = (Render::DisplayMode *)UFG::qMalloc(v7, UFG::gGlobalNewName, 0i64);
    v1->mDisplayModes = v8;
    Render::GetDisplayModeArray(&filter, v8);
    UFG::qString::qString(&v26);
    *(_QWORD *)&pargs.Type = 0i64;
    pargs.mValue.IValue = 0;
    v9 = 0;
    v10 = 0;
    if ( v1->mDisplayModeCount <= 0 )
      goto LABEL_42;
    do
    {
      v11 = v1->mDisplayModes;
      v12 = 0.0;
      v13 = v11[v3].mRefreshRateDenominator;
      if ( v13 )
        v12 = (float)(signed int)(v11[v3].mRefreshRateNumerator / v13);
      UFG::qString::qString(&v23);
      v14 = (float)(signed int)v11[v3].mBackBufferWidth / (float)(signed int)v11[v3].mBackBufferHeight;
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
            v16 = &customWorldMapCaption;
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
      UFG::qString::Format(&v26, "%dx%dx%.0f Hz %s", v11[v3].mBackBufferWidth, v11[v3].mBackBufferHeight, v12, &v25);
      v19 = v26.mData;
      if ( ((unsigned int)pargs.mValue.IValue >> 6) & 1 )
      {
        (*(void (__fastcall **)(_QWORD, $41EDDC8CC4664C9FE26D4D23F9ACAEE4 *, unsigned __int64))(**(_QWORD **)&pargs.Type
                                                                                              + 16i64))(
          *(_QWORD *)&pargs.Type,
          &pargs.8,
          pargs.DataAux);
        *(_QWORD *)&pargs.Type = 0i64;
      }
      pargs.mValue.IValue = 6;
      pargs.DataAux = (unsigned __int64)v19;
      Scaleform::GFx::Movie::Invoke(
        v2,
        "OptionList_AddResolution",
        0i64,
        (Scaleform::GFx::Value *)((char *)&pargs + 8),
        1u);
      if ( v11[v3].mBackBufferWidth == v1->mCurrentDisplaySettings.mDisplayMode.mBackBufferWidth
        && v11[v3].mBackBufferHeight == v1->mCurrentDisplaySettings.mDisplayMode.mBackBufferHeight
        && v11[v3].mRefreshRateNumerator == v1->mCurrentDisplaySettings.mDisplayMode.mRefreshRateNumerator
        && v11[v3].mRefreshRateDenominator == v1->mCurrentDisplaySettings.mDisplayMode.mRefreshRateDenominator
        && v11[v3].mScaling == v1->mCurrentDisplaySettings.mDisplayMode.mScaling
        && v11[v3].mScanlineMode == v1->mCurrentDisplaySettings.mDisplayMode.mScanlineMode )
      {
        v1->mCurrentDisplayModeIndex = v10;
        v9 = 1;
      }
      UFG::qString::~qString(&v23);
      ++v10;
      ++v3;
    }
    while ( v10 < v1->mDisplayModeCount );
    if ( !v9 )
LABEL_42:
      v1->mCurrentDisplayModeIndex = v1->mDisplayModeCount - 1;
    pargs.pObjectInterface = 0i64;
    pargs.Type = 0;
    v20 = (double)v1->mCurrentDisplayModeIndex;
    pargs.Type = 5;
    pargs.mValue.NValue = v20;
    Scaleform::GFx::Movie::Invoke(v2, "OptionList_SetResolutionIndex", 0i64, &pargs, 1u);
    v1->mTentativeDisplayModeIndex = v1->mCurrentDisplayModeIndex;
    if ( ((unsigned int)pargs.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        *(_QWORD *)&pargs.mValue.NValue);
      pargs.pObjectInterface = 0i64;
    }
    pargs.Type = 0;
    if ( ((unsigned int)pargs.mValue.IValue >> 6) & 1 )
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
  Render::DisplayMode *v1; // r8
  Render::RenderOutputParams *v2; // rdx
  signed __int64 v3; // r9
  UFG::UIHKScreenOptionsDisplay *v4; // rbx
  int v5; // edx
  __int128 v6; // xmm0

  v1 = this->mDisplayModes;
  v2 = &this->mCurrentDisplaySettings;
  v3 = this->mCurrentDisplayModeIndex;
  v4 = this;
  v2->mDisplayMode.mBackBufferWidth = v1[v3].mBackBufferWidth;
  v2->mDisplayMode.mBackBufferHeight = v1[v3].mBackBufferHeight;
  v2->mDisplayMode.mRefreshRateNumerator = v1[v3].mRefreshRateNumerator;
  v2->mDisplayMode.mRefreshRateDenominator = v1[v3].mRefreshRateDenominator;
  v2->mDisplayMode.mAdapterUID = v1[v3].mAdapterUID;
  v2->mDisplayMode.mMonitorUID = v1[v3].mMonitorUID;
  v2->mDisplayMode.mScaling = v1[v3].mScaling;
  v2->mDisplayMode.mScanlineMode = v1[v3].mScanlineMode;
  UFG::UIHKScreenOptionsDisplay::ApplyRenderOptions(this, &this->mCurrentDisplaySettings);
  v5 = v4->mCurrentDisplayModeIndex;
  v4->mTentativeDisplayModeIndex = v5;
  UFG::UIHKScreenOptionsDisplay::Flash_SetResolutionModeIndex(v4, v5);
  v6 = COERCE_UNSIGNED_INT((float)(signed int)v4->mCurrentDisplaySettings.mDisplayMode.mBackBufferHeight);
  UFG::UIScreenManagerBase::setFontScale((UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr, 1.0);
  UFG::UI::RefreshScreenHD((UFG::UIScreen *)&v4->vfptr);
  Scaleform::GFx::Movie::Invoke(v4->mRenderable->m_movie.pObject, "OptionListUpdateSDText", 0i64, 0i64, 0);
}

// File Line: 721
// RVA: 0x6032B0
void __fastcall UFG::UIHKScreenOptionsDisplay::RevertFullscreenMode(UFG::UIHKScreenOptionsDisplay *this)
{
  UFG::UIHKScreenOptionsDisplay *v1; // rbx
  UFG::GameStatTracker *v2; // rax
  __int64 v3; // rcx
  Render::RenderOutputParams *v4; // rdx
  Render::DisplayMode *v5; // rcx

  v1 = this;
  v2 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::SetStat(v2, Display_IsFullscreen, 0);
  v3 = v1->mCurrentDisplayModeIndex;
  v1->mCurrentDisplaySettings.mEnableFullscreen = 0;
  v4 = &v1->mCurrentDisplaySettings;
  v5 = &v1->mDisplayModes[v3];
  v4->mDisplayMode.mBackBufferWidth = v5->mBackBufferWidth;
  v4->mDisplayMode.mBackBufferHeight = v5->mBackBufferHeight;
  v4->mDisplayMode.mRefreshRateNumerator = v5->mRefreshRateNumerator;
  v4->mDisplayMode.mRefreshRateDenominator = v5->mRefreshRateDenominator;
  v4->mDisplayMode.mAdapterUID = v5->mAdapterUID;
  v4->mDisplayMode.mMonitorUID = v5->mMonitorUID;
  v4->mDisplayMode.mScaling = v5->mScaling;
  v4->mDisplayMode.mScanlineMode = v5->mScanlineMode;
  UFG::UIHKScreenOptionsDisplay::ApplyRenderOptions(v1, &v1->mCurrentDisplaySettings);
  UFG::UIHKScreenOptionsDisplay::Flash_SetFullscreenOption(v1, 0);
  UFG::UIHKScreenOptionsDisplay::Flash_SetResolutionModeIndex(v1, v1->mCurrentDisplayModeIndex);
}

// File Line: 745
// RVA: 0x60ED00
void __fastcall UFG::UIHKScreenOptionsDisplay::ShowHelpBar(UFG::UIHKScreenOptionsDisplay *this)
{
  UFG::UIHKScreenOptionsDisplay *v1; // rbx
  int v2; // esi
  unsigned int v3; // er14
  int v4; // ecx
  __int64 v5; // rax
  __int64 v6; // rdi
  __int64 v7; // rbx
  unsigned int v8; // er14
  int v9; // ecx
  __int64 v10; // rax
  __int64 v11; // rdi
  __int64 v12; // rbx
  unsigned int v13; // er14
  int v14; // ecx
  __int64 v15; // rax
  __int64 v16; // rdi
  __int64 v17; // rbx
  unsigned int v18; // er14
  __int64 v19; // rax
  __int64 v20; // rdi
  __int64 v21; // rbx
  UFG::UIHKScreenGlobalOverlay *v22; // rax
  UFG::UIHKHelpBarData data; // [rsp+30h] [rbp-C8h]

  v1 = this;
  UFG::UIHKHelpBarData::UIHKHelpBarData(&data);
  data.id = UFG::qStringHash32(v1->mHelpBarName, 0xFFFFFFFF);
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
  data.Buttons[v6] = 2;
  v7 = v4;
  UFG::qString::Set(&data.Captions[v7], "$COMMON_BACK_UPPERCASE");
  UFG::qString::Set((UFG::qString *)((char *)&data.Captions[v7 + 5] + 32), &customWorldMapCaption);
  *(unsigned int *)((char *)&data.Icons[5].mStringHash32 + v6 * 4) = v3;
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
  data.Buttons[v11] = 3;
  v12 = v9;
  UFG::qString::Set(&data.Captions[v12], "$COMMON_ADVANCED");
  UFG::qString::Set((UFG::qString *)((char *)&data.Captions[v12 + 5] + 32), &customWorldMapCaption);
  *(unsigned int *)((char *)&data.Icons[5].mStringHash32 + v11 * 4) = v8;
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
  data.Buttons[v16] = 4;
  v17 = v14;
  UFG::qString::Set(&data.Captions[v17], "$OPTIONS_SAVE_GRAPHICS_LEVEL");
  UFG::qString::Set((UFG::qString *)((char *)&data.Captions[v17 + 5] + 32), &customWorldMapCaption);
  *(unsigned int *)((char *)&data.Icons[5].mStringHash32 + v16 * 4) = v13;
LABEL_16:
  v18 = UI_HASH_BUTTON_SELECT_PRESSED_30;
  v19 = 0i64;
  while ( data.Buttons[v19] )
  {
    ++v2;
    if ( ++v19 >= 6 )
      goto LABEL_21;
  }
  v20 = v2;
  data.Buttons[v20] = 6;
  v21 = v2;
  UFG::qString::Set(&data.Captions[v21], "$OPTIONS_RESET_TO_DEFAULT");
  UFG::qString::Set((UFG::qString *)((char *)&data.Captions[v21 + 5] + 32), &customWorldMapCaption);
  *(unsigned int *)((char *)&data.Icons[5].mStringHash32 + v20 * 4) = v18;
LABEL_21:
  v22 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    v22 = &gGlobalOverlaySentinel;
  UFG::UIHKHelpBarWidget::Show(&v22->HelpBar, &data);
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
void __fastcall UFG::UIHKScreenOptionsDisplay::Flash_SetResolutionModeIndex(UFG::UIHKScreenOptionsDisplay *this, int index)
{
  Scaleform::GFx::Movie *v2; // rdi
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h]

  v2 = this->mRenderable->m_movie.pObject;
  pargs.pObjectInterface = 0i64;
  pargs.Type = 5;
  pargs.mValue.NValue = (double)index;
  Scaleform::GFx::Movie::Invoke(v2, "OptionList_SetResolutionIndex", 0i64, &pargs, 1u);
  if ( ((unsigned int)pargs.Type >> 6) & 1 )
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      *(_QWORD *)&pargs.mValue.NValue);
}

// File Line: 772
// RVA: 0x5DFF60
void __fastcall UFG::UIHKScreenOptionsDisplay::Flash_SetFullscreenOption(UFG::UIHKScreenOptionsDisplay *this, bool fullscreen)
{
  Scaleform::GFx::Movie *v2; // rdi
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h]

  v2 = this->mRenderable->m_movie.pObject;
  pargs.pObjectInterface = 0i64;
  pargs.Type = 2;
  pargs.mValue.BValue = fullscreen;
  Scaleform::GFx::Movie::Invoke(v2, "OptionList_SetFullscreenOption", 0i64, &pargs, 1u);
  if ( ((unsigned int)pargs.Type >> 6) & 1 )
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      *(_QWORD *)&pargs.mValue.NValue);
}

// File Line: 782
// RVA: 0x5E0910
void __fastcall UFG::UIHKScreenOptionsDisplay::Flash_SetScaleCornersVisible(UFG::UIHKScreenOptionsDisplay *this, bool visible)
{
  Scaleform::GFx::Movie *v2; // rdi
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-40h]

  v2 = this->mRenderable->m_movie.pObject;
  value.pObjectInterface = 0i64;
  value.Type = 2;
  value.mValue.BValue = visible;
  Scaleform::GFx::Movie::SetVariable(v2, "mc_uiScaleCorners._visible", &value, 1i64);
  if ( ((unsigned int)value.Type >> 6) & 1 )
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
      value.pObjectInterface,
      &value,
      *(_QWORD *)&value.mValue.NValue);
}

// File Line: 791
// RVA: 0x5DEC60
void __fastcall UFG::UIHKScreenOptionsDisplay::Flash_RefreshValues(UFG::UIHKScreenOptionsDisplay *this)
{
  UFG::UIHKScreenOptionsDisplay *v1; // rbx
  Scaleform::GFx::Movie *v2; // rdi
  UFG::GameStatTracker *v3; // rax
  __int128 v4; // xmm6
  UFG::GameStatTracker *v5; // rax
  __int128 v6; // xmm7
  bool v7; // si
  bool v8; // si
  bool v9; // si
  bool v10; // si
  double v11; // xmm6_8
  bool v12; // bl
  char ptr; // [rsp+30h] [rbp-B8h]
  __int64 v14; // [rsp+40h] [rbp-A8h]
  unsigned int v15; // [rsp+48h] [rbp-A0h]
  double v16; // [rsp+50h] [rbp-98h]
  char v17; // [rsp+60h] [rbp-88h]
  double v18; // [rsp+68h] [rbp-80h]
  __int64 v19; // [rsp+70h] [rbp-78h]
  unsigned int v20; // [rsp+78h] [rbp-70h]
  __int64 v21; // [rsp+88h] [rbp-60h]
  unsigned int v22; // [rsp+90h] [rbp-58h]
  __int64 v23; // [rsp+98h] [rbp-50h]
  char v24; // [rsp+A8h] [rbp-40h]
  __int64 v25; // [rsp+B8h] [rbp-30h]
  unsigned int v26; // [rsp+C0h] [rbp-28h]
  __int64 v27; // [rsp+C8h] [rbp-20h]
  char v28; // [rsp+D8h] [rbp-10h]
  __int64 v29; // [rsp+E8h] [rbp+0h]
  unsigned int v30; // [rsp+F0h] [rbp+8h]
  __int64 v31; // [rsp+F8h] [rbp+10h]
  char v32; // [rsp+108h] [rbp+20h]
  __int64 v33; // [rsp+118h] [rbp+30h]
  unsigned int v34; // [rsp+120h] [rbp+38h]
  __int64 v35; // [rsp+128h] [rbp+40h]
  char v36; // [rsp+138h] [rbp+50h]
  __int64 v37; // [rsp+148h] [rbp+60h]
  unsigned int v38; // [rsp+150h] [rbp+68h]
  double v39; // [rsp+158h] [rbp+70h]
  char v40; // [rsp+168h] [rbp+80h]
  __int64 v41; // [rsp+178h] [rbp+90h]
  unsigned int v42; // [rsp+180h] [rbp+98h]
  __int64 v43; // [rsp+188h] [rbp+A0h]
  __int64 v44; // [rsp+198h] [rbp+B0h]

  v44 = -2i64;
  v1 = this;
  v2 = UFG::UIScreen::getMovieSafe((UFG::UIScreen *)&this->vfptr);
  if ( v2 )
  {
    v3 = UFG::GameStatTracker::Instance();
    v4 = COERCE_UNSIGNED_INT((float)(signed int)UFG::GameStatTracker::GetStat(v3, Gamma));
    v5 = UFG::GameStatTracker::Instance();
    v6 = COERCE_UNSIGNED_INT((float)(signed int)UFG::GameStatTracker::GetStat(v5, UIScale));
    `eh vector constructor iterator(&ptr, 0x30ui64, 8, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( (v15 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v14 + 16i64))(
        v14,
        &ptr,
        COERCE_DOUBLE(*(_QWORD *)&v16));
      v14 = 0i64;
    }
    v15 = 5;
    v16 = *(float *)&v4;
    if ( (v20 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v19 + 16i64))(
        v19,
        &v17,
        COERCE_DOUBLE(*(_QWORD *)&v18));
      v19 = 0i64;
    }
    v20 = 5;
    v18 = *(float *)&v6;
    v7 = v1->mCurrentDisplaySettings.mEnableFullscreen;
    if ( (v22 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, unsigned int *, __int64))(*(_QWORD *)v21 + 16i64))(v21, &v20, v23);
      v21 = 0i64;
    }
    v22 = 2;
    LOBYTE(v23) = v7;
    v8 = v1->mCurrentDisplaySettings.mEnableVSync;
    if ( (v26 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v25 + 16i64))(v25, &v24, v27);
      v25 = 0i64;
    }
    v26 = 2;
    LOBYTE(v27) = v8;
    v9 = v1->mCurrentDisplaySettings.mMotionBlur == 2;
    if ( (v30 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v29 + 16i64))(v29, &v28, v31);
      v29 = 0i64;
    }
    v30 = 2;
    LOBYTE(v31) = v9;
    v10 = v1->mCurrentDisplaySettings.mEnable3D;
    if ( (v34 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v33 + 16i64))(v33, &v32, v35);
      v33 = 0i64;
    }
    v34 = 2;
    LOBYTE(v35) = v10;
    v11 = (double)(signed int)v1->mCurrentDisplaySettings.mGlobalSetting;
    if ( (v38 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v37 + 16i64))(
        v37,
        &v36,
        COERCE_DOUBLE(*(_QWORD *)&v39));
      v37 = 0i64;
    }
    v38 = 5;
    v39 = v11;
    v12 = v1->mAddCaptions;
    if ( (v42 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v41 + 16i64))(v41, &v40, v43);
      v41 = 0i64;
    }
    v42 = 2;
    LOBYTE(v43) = v12;
    Scaleform::GFx::Movie::Invoke(v2, "OptionList_SetValues", 0i64, (Scaleform::GFx::Value *)&ptr, 8u);
    `eh vector destructor iterator(&ptr, 0x30ui64, 8, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

