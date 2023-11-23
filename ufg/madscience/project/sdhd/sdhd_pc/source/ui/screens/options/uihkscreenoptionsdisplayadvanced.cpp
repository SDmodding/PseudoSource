// File Line: 63
// RVA: 0x5C6730
void __fastcall UFG::UIHKScreenOptionsDisplayAdvanced::UIHKScreenOptionsDisplayAdvanced(
        UFG::UIHKScreenOptionsDisplayAdvanced *this)
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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenOptionsDisplayAdvanced::`vftable;
  this->mState = STATE_INIT;
  Render::RenderOutputParams::RenderOutputParams(&this->mOldDisplaySettings);
  Render::RenderOutputParams::RenderOutputParams(&this->mCurrentDisplaySettings);
  *(_WORD *)&this->mScreensSwitched = 0;
  this->mExitTimer = 0.0;
  this->mDialogUID = -1;
  this->mHelpBarName = "OPTIONS_ADVANCED";
}

// File Line: 80
// RVA: 0x633C40
void __fastcall UFG::UIHKScreenOptionsDisplayAdvanced::init(
        UFG::UIHKScreenOptionsDisplayAdvanced *this,
        UFG::UICommandData *data)
{
  UFG::Controller *v3; // rcx
  int v4; // edi
  Scaleform::GFx::Movie *pObject; // r14
  Render::eAAQuality mAAQuality; // ecx
  __int32 v7; // ecx
  int v8; // esi
  Render::eShadowResolution mShadowRes; // ecx
  __int32 v10; // ecx
  double v11; // xmm6_8
  double v12; // xmm6_8
  bool mEnableFullscreen; // di
  bool mEnableVSync; // di
  double v15; // xmm6_8
  double mFPSLimiter; // xmm6_8
  double m3DDepth; // xmm6_8
  double m3DConvergence; // xmm6_8
  float v19; // xmm6_4
  unsigned int v20; // eax
  UFG::UIGfxTranslator *m_translator; // rcx
  const char *v22; // rdi
  double v23; // xmm7_8
  double v24; // xmm8_8
  double v25; // xmm9_8
  double v26; // xmm6_8
  char *mData; // rdi
  char *v28; // rdi
  char *v29; // rdi
  char *v30; // rdi
  unsigned int v31; // eax
  UFG::UIGfxTranslator *v32; // rcx
  const char *v33; // rdi
  char *v34; // rdi
  char *v35; // rdi
  char *v36; // rdi
  char *v37; // rdi
  double v38; // xmm6_8
  bool mEnableLowResBuffer; // bl
  Scaleform::GFx::Value ptr; // [rsp+30h] [rbp-B8h] BYREF
  char v41[16]; // [rsp+78h] [rbp-70h] BYREF
  __int64 v42; // [rsp+88h] [rbp-60h]
  int v43; // [rsp+90h] [rbp-58h]
  double v44; // [rsp+98h] [rbp-50h]
  char v45[16]; // [rsp+A8h] [rbp-40h] BYREF
  __int64 v46; // [rsp+B8h] [rbp-30h]
  int v47; // [rsp+C0h] [rbp-28h]
  double v48; // [rsp+C8h] [rbp-20h]
  char v49[16]; // [rsp+D8h] [rbp-10h] BYREF
  __int64 v50; // [rsp+E8h] [rbp+0h]
  int v51; // [rsp+F0h] [rbp+8h]
  double v52; // [rsp+F8h] [rbp+10h]
  char v53[16]; // [rsp+108h] [rbp+20h] BYREF
  __int64 v54; // [rsp+118h] [rbp+30h]
  int v55; // [rsp+120h] [rbp+38h]
  __int64 v56; // [rsp+128h] [rbp+40h]
  char v57[16]; // [rsp+138h] [rbp+50h] BYREF
  __int64 v58; // [rsp+148h] [rbp+60h]
  int v59; // [rsp+150h] [rbp+68h]
  __int64 v60; // [rsp+158h] [rbp+70h]
  char v61[16]; // [rsp+168h] [rbp+80h] BYREF
  __int64 v62; // [rsp+178h] [rbp+90h]
  int v63; // [rsp+180h] [rbp+98h]
  double v64; // [rsp+188h] [rbp+A0h]
  char v65[16]; // [rsp+198h] [rbp+B0h] BYREF
  __int64 v66; // [rsp+1A8h] [rbp+C0h]
  int v67; // [rsp+1B0h] [rbp+C8h]
  double v68; // [rsp+1B8h] [rbp+D0h]
  char v69[16]; // [rsp+1C8h] [rbp+E0h] BYREF
  __int64 v70; // [rsp+1D8h] [rbp+F0h]
  int v71; // [rsp+1E0h] [rbp+F8h]
  double v72; // [rsp+1E8h] [rbp+100h]
  char v73[16]; // [rsp+1F8h] [rbp+110h] BYREF
  __int64 v74; // [rsp+208h] [rbp+120h]
  int v75; // [rsp+210h] [rbp+128h]
  double v76; // [rsp+218h] [rbp+130h]
  char v77[16]; // [rsp+228h] [rbp+140h] BYREF
  __int64 v78; // [rsp+238h] [rbp+150h]
  int v79; // [rsp+240h] [rbp+158h]
  char *v80; // [rsp+248h] [rbp+160h]
  char v81[16]; // [rsp+258h] [rbp+170h] BYREF
  __int64 v82; // [rsp+268h] [rbp+180h]
  int v83; // [rsp+270h] [rbp+188h]
  char *v84; // [rsp+278h] [rbp+190h]
  char v85[16]; // [rsp+288h] [rbp+1A0h] BYREF
  __int64 v86; // [rsp+298h] [rbp+1B0h]
  int v87; // [rsp+2A0h] [rbp+1B8h]
  char *v88; // [rsp+2A8h] [rbp+1C0h]
  char v89[16]; // [rsp+2B8h] [rbp+1D0h] BYREF
  __int64 v90; // [rsp+2C8h] [rbp+1E0h]
  int v91; // [rsp+2D0h] [rbp+1E8h]
  char *v92; // [rsp+2D8h] [rbp+1F0h]
  char v93[16]; // [rsp+2E8h] [rbp+200h] BYREF
  __int64 v94; // [rsp+2F8h] [rbp+210h]
  int v95; // [rsp+300h] [rbp+218h]
  char *v96; // [rsp+308h] [rbp+220h]
  char v97[16]; // [rsp+318h] [rbp+230h] BYREF
  __int64 v98; // [rsp+328h] [rbp+240h]
  int v99; // [rsp+330h] [rbp+248h]
  char *v100; // [rsp+338h] [rbp+250h]
  char v101[16]; // [rsp+348h] [rbp+260h] BYREF
  __int64 v102; // [rsp+358h] [rbp+270h]
  int v103; // [rsp+360h] [rbp+278h]
  char *v104; // [rsp+368h] [rbp+280h]
  char v105[16]; // [rsp+378h] [rbp+290h] BYREF
  __int64 v106; // [rsp+388h] [rbp+2A0h]
  int v107; // [rsp+390h] [rbp+2A8h]
  char *v108; // [rsp+398h] [rbp+2B0h]
  char v109[16]; // [rsp+3A8h] [rbp+2C0h] BYREF
  __int64 v110; // [rsp+3B8h] [rbp+2D0h]
  int v111; // [rsp+3C0h] [rbp+2D8h]
  double v112; // [rsp+3C8h] [rbp+2E0h]
  char v113[16]; // [rsp+3D8h] [rbp+2F0h] BYREF
  __int64 v114; // [rsp+3E8h] [rbp+300h]
  int v115; // [rsp+3F0h] [rbp+308h]
  __int64 v116; // [rsp+3F8h] [rbp+310h]
  __int64 v117; // [rsp+408h] [rbp+320h]
  UFG::qString v118; // [rsp+410h] [rbp+328h] BYREF
  UFG::qString v119; // [rsp+438h] [rbp+350h] BYREF
  UFG::qString v120; // [rsp+460h] [rbp+378h] BYREF
  UFG::qString v121; // [rsp+488h] [rbp+3A0h] BYREF
  UFG::qString v122; // [rsp+4B0h] [rbp+3C8h] BYREF
  UFG::qString result; // [rsp+4D8h] [rbp+3F0h] BYREF
  UFG::qString v124; // [rsp+500h] [rbp+418h] BYREF
  UFG::qString v125; // [rsp+528h] [rbp+440h] BYREF

  v117 = -2i64;
  UFG::UIScreen::init(this, data);
  if ( UFG::gInputSystem && UFG::gActiveControllerNum != -1 )
  {
    v3 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum];
    if ( !UFG::UI::gUIInputLocked )
      g_saved_gameplay_controller_mode = v3->m_ActiveMapSet;
    UFG::SetInputMode(IM_UI_ONLY, v3->mControllerIndex);
    ++UFG::UI::gUIInputLocked;
  }
  v4 = 1;
  this->UFG::UIHKScreenOptions::mState = STATE_BRIGHTNESS;
  (*((void (__fastcall **)(UFG::UIHKScreenOptionsDisplayAdvanced *))&this->vfptr[1].__vecDelDtor + 1))(this);
  this->mState = STATE_BRIGHTNESS;
  UFG::GameStatTracker::Instance();
  Render::GetCurrentDisplaySettings(&this->mOldDisplaySettings);
  Render::GetCurrentDisplaySettings(&this->mCurrentDisplaySettings);
  pObject = this->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    `eh vector constructor iterator(&ptr, 0x30ui64, 21, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    mAAQuality = this->mOldDisplaySettings.mAAQuality;
    if ( mAAQuality )
    {
      v7 = mAAQuality - 1;
      if ( !v7 )
      {
        v8 = 2;
        goto LABEL_13;
      }
      if ( v7 == 1 )
      {
        v8 = 3;
LABEL_13:
        if ( (ptr.Type & 0x40) != 0 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
            ptr.pObjectInterface,
            &ptr,
            ptr.mValue);
          ptr.pObjectInterface = 0i64;
        }
        ptr.Type = VT_Number;
        ptr.mValue.NValue = (double)v8;
        mShadowRes = this->mOldDisplaySettings.mShadowRes;
        if ( mShadowRes )
        {
          v10 = mShadowRes - 1;
          if ( v10 )
          {
            if ( v10 == 1 )
              v4 = 3;
          }
          else
          {
            v4 = 2;
          }
        }
        if ( (v43 & 0x40) != 0 )
        {
          (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v42 + 16i64))(
            v42,
            v41,
            COERCE_DOUBLE(*(_QWORD *)&v44));
          v42 = 0i64;
        }
        v43 = 5;
        v44 = (double)v4;
        v11 = (double)((this->mOldDisplaySettings.mShadowFilter != SHADOW_FILTER_NORMAL) + 1);
        if ( (v47 & 0x40) != 0 )
        {
          (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v46 + 16i64))(
            v46,
            v45,
            COERCE_DOUBLE(*(_QWORD *)&v48));
          v46 = 0i64;
        }
        v47 = 5;
        v48 = v11;
        v12 = (double)((this->mOldDisplaySettings.mSSAO != SSAO_NORMAL) + 1);
        if ( (v51 & 0x40) != 0 )
        {
          (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v50 + 16i64))(
            v50,
            v49,
            COERCE_DOUBLE(*(_QWORD *)&v52));
          v50 = 0i64;
        }
        v51 = 5;
        v52 = v12;
        mEnableFullscreen = this->mOldDisplaySettings.mEnableFullscreen;
        if ( (v55 & 0x40) != 0 )
        {
          (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v54 + 16i64))(v54, v53, v56);
          v54 = 0i64;
        }
        v55 = 2;
        LOBYTE(v56) = mEnableFullscreen;
        mEnableVSync = this->mOldDisplaySettings.mEnableVSync;
        if ( (v59 & 0x40) != 0 )
        {
          (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v58 + 16i64))(v58, v57, v60);
          v58 = 0i64;
        }
        v59 = 2;
        LOBYTE(v60) = mEnableVSync;
        v15 = (double)(this->mOldDisplaySettings.mMotionBlur + 1);
        if ( (v63 & 0x40) != 0 )
        {
          (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v62 + 16i64))(
            v62,
            v61,
            COERCE_DOUBLE(*(_QWORD *)&v64));
          v62 = 0i64;
        }
        v63 = 5;
        v64 = v15;
        mFPSLimiter = (double)(int)this->mOldDisplaySettings.mFPSLimiter;
        if ( (v67 & 0x40) != 0 )
        {
          (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v66 + 16i64))(
            v66,
            v65,
            COERCE_DOUBLE(*(_QWORD *)&v68));
          v66 = 0i64;
        }
        v67 = 5;
        v68 = mFPSLimiter;
        m3DDepth = (double)this->mOldDisplaySettings.m3DDepth;
        if ( (v71 & 0x40) != 0 )
        {
          (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v70 + 16i64))(
            v70,
            v69,
            COERCE_DOUBLE(*(_QWORD *)&v72));
          v70 = 0i64;
        }
        v71 = 5;
        v72 = m3DDepth;
        m3DConvergence = (double)this->mOldDisplaySettings.m3DConvergence;
        if ( (v75 & 0x40) != 0 )
        {
          (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v74 + 16i64))(
            v74,
            v73,
            COERCE_DOUBLE(*(_QWORD *)&v76));
          v74 = 0i64;
        }
        v75 = 5;
        v76 = m3DConvergence;
        v19 = (float)(int)this->mOldDisplaySettings.mDisplayMode.mRefreshRateNumerator
            / (float)(int)this->mOldDisplaySettings.mDisplayMode.mRefreshRateDenominator;
        v20 = UFG::qStringHashUpper32("FPS_PARAMETER", -1);
        m_translator = UFG::UIScreenManager::s_instance->m_translator;
        if ( !m_translator || (v22 = (const char *)m_translator->vfptr[5].__vecDelDtor(m_translator, v20)) == 0i64 )
          v22 = "FPS_PARAMETER";
        v23 = v19;
        UFG::qString::FormatEx(&result, v22, v19);
        v24 = (float)(v19 * 0.5);
        UFG::qString::FormatEx(&v121, v22, v24);
        v25 = (float)(v19 * 0.33333334);
        UFG::qString::FormatEx(&v119, v22, v25);
        v26 = (float)(v19 * 0.25);
        UFG::qString::FormatEx(&v122, v22, v26);
        mData = result.mData;
        if ( (v79 & 0x40) != 0 )
        {
          (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v78 + 16i64))(v78, v77, v80);
          v78 = 0i64;
        }
        v79 = 6;
        v80 = mData;
        v28 = v121.mData;
        if ( (v83 & 0x40) != 0 )
        {
          (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v82 + 16i64))(v82, v81, v84);
          v82 = 0i64;
        }
        v83 = 6;
        v84 = v28;
        v29 = v119.mData;
        if ( (v87 & 0x40) != 0 )
        {
          (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v86 + 16i64))(v86, v85, v88);
          v86 = 0i64;
        }
        v87 = 6;
        v88 = v29;
        v30 = v122.mData;
        if ( (v91 & 0x40) != 0 )
        {
          (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v90 + 16i64))(v90, v89, v92);
          v90 = 0i64;
        }
        v91 = 6;
        v92 = v30;
        v31 = UFG::qStringHashUpper32("FPS_DESCRIPTION", -1);
        v32 = UFG::UIScreenManager::s_instance->m_translator;
        if ( !v32 || (v33 = (const char *)v32->vfptr[5].__vecDelDtor(v32, v31)) == 0i64 )
          v33 = "FPS_DESCRIPTION";
        UFG::qString::FormatEx(&v118, v33, v23);
        UFG::qString::FormatEx(&v120, v33, v24);
        UFG::qString::FormatEx(&v125, v33, v25);
        UFG::qString::FormatEx(&v124, v33, v26);
        v34 = v118.mData;
        if ( (v95 & 0x40) != 0 )
        {
          (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v94 + 16i64))(v94, v93, v96);
          v94 = 0i64;
        }
        v95 = 6;
        v96 = v34;
        v35 = v120.mData;
        if ( (v99 & 0x40) != 0 )
        {
          (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v98 + 16i64))(v98, v97, v100);
          v98 = 0i64;
        }
        v99 = 6;
        v100 = v35;
        v36 = v125.mData;
        if ( (v103 & 0x40) != 0 )
        {
          (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v102 + 16i64))(v102, v101, v104);
          v102 = 0i64;
        }
        v103 = 6;
        v104 = v36;
        v37 = v124.mData;
        if ( (v107 & 0x40) != 0 )
        {
          (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v106 + 16i64))(v106, v105, v108);
          v106 = 0i64;
        }
        v107 = 6;
        v108 = v37;
        v38 = (double)(this->mOldDisplaySettings.mLODSetting + 1);
        if ( (v111 & 0x40) != 0 )
        {
          (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v110 + 16i64))(
            v110,
            v109,
            COERCE_DOUBLE(*(_QWORD *)&v112));
          v110 = 0i64;
        }
        v111 = 5;
        v112 = v38;
        mEnableLowResBuffer = this->mOldDisplaySettings.mEnableLowResBuffer;
        if ( (v115 & 0x40) != 0 )
        {
          (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v114 + 16i64))(v114, v113, v116);
          v114 = 0i64;
        }
        v115 = 2;
        LOBYTE(v116) = mEnableLowResBuffer;
        Scaleform::GFx::Movie::Invoke(pObject, "OptionList_SetValues", 0i64, &ptr, 0x15u);
        Scaleform::GFx::Movie::Invoke(pObject, "OptionList_PlayIntro", 0i64, 0i64, 0);
        if ( UFG::HudAudio::m_instance )
          UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x4A3D1F6Cu, 0i64, 0, 0i64);
        UFG::qString::~qString(&v124);
        UFG::qString::~qString(&v125);
        UFG::qString::~qString(&v120);
        UFG::qString::~qString(&v118);
        UFG::qString::~qString(&v122);
        UFG::qString::~qString(&v119);
        UFG::qString::~qString(&v121);
        UFG::qString::~qString(&result);
        `eh vector destructor iterator(&ptr, 0x30ui64, 21, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
        return;
      }
    }
    v8 = 1;
    goto LABEL_13;
  }
}

// File Line: 154
// RVA: 0x63E6A0
void __fastcall UFG::UIHKScreenOptionsDisplayAdvanced::update(
        UFG::UIHKScreenOptionsDisplayAdvanced *this,
        float elapsed)
{
  float v3; // xmm2_4
  unsigned int mDialogUID; // edx

  UFG::UIHKScreenOptions::update(this, elapsed);
  if ( this->mState == (NUM_CALIBRATION_STATES|STATE_BRIGHTNESS) )
  {
    if ( (v3 = this->mExitTimer - elapsed, this->mExitTimer = v3, v3 <= 0.0)
      && !UFG::SectionChooser::AreAnyLoadsPending()
      || this->mExitTimer < -10.0 )
    {
      mDialogUID = this->mDialogUID;
      if ( mDialogUID != -1 )
        UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, mDialogUID);
      if ( !this->mScreensSwitched )
      {
        UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, this->mScreenUID);
        this->mScreensSwitched = 1;
      }
    }
  }
}

// File Line: 178
// RVA: 0x628030
bool __fastcall UFG::UIHKScreenOptionsDisplayAdvanced::handleMessage(
        UFG::UIHKScreenOptionsDisplayAdvanced *this,
        unsigned int msgId,
        UFG::UIMessage *msg)
{
  UFG::GameStatTracker *v6; // r15
  int v8; // ebx
  int v9; // r14d
  int v10; // r14d
  int v11; // r14d
  int FlashArgsInt; // eax
  int v13; // eax
  int v14; // eax
  Render::eShadowResolution v15; // ebx
  int v16; // eax
  BOOL v17; // ebx
  int v18; // eax
  BOOL v19; // ebx
  bool v20; // bl
  int v21; // eax
  Render::eMotionBlur v22; // ebx
  Render::eFPSLimiter v23; // ebx
  UFG::GameSaveLoad *v24; // rax
  UFG::GameSaveLoad *v25; // rax
  UFG::GameSaveLoad *v26; // rax
  UFG::qString v27; // [rsp+38h] [rbp-40h] BYREF

  v6 = UFG::GameStatTracker::Instance();
  if ( msgId == UI_HASH_INTRO_COMPLETE_30 )
    return UFG::UIScreen::handleMessage(this, msgId, msg);
  if ( msgId == UI_HASH_OPTIONS_QUALITY_AA_20 )
  {
    this->mOptionChanged = 1;
    this->mExitDelayNeeded = 1;
    v8 = 0;
    if ( msg )
    {
      UFG::qString::qString(&v27, (UFG::qString *)&msg[1]);
      v9 = UFG::qToInt32(v27.mData, 0);
      UFG::qString::~qString(&v27);
    }
    else
    {
      v9 = 0;
    }
    v10 = v9 - 1;
    if ( v10 )
    {
      v11 = v10 - 1;
      if ( v11 )
      {
        if ( v11 == 1 )
          v8 = 2;
      }
      else
      {
        v8 = 1;
      }
    }
    UFG::GameStatTracker::SetStat(v6, Display_AAQuality, v8);
    this->mCurrentDisplaySettings.mAAQuality = v8;
    goto LABEL_56;
  }
  if ( msgId == UI_HASH_OPTIONS_HIGH_RES_TEXTURES_20 )
  {
    this->mOptionChanged = 1;
    this->mExitDelayNeeded = 1;
    FlashArgsInt = UFG::UI::GetFlashArgsInt(msg);
    UFG::GameStatTracker::SetStat(v6, Display_HighResTextures, FlashArgsInt == 2);
    goto LABEL_56;
  }
  if ( msgId == UI_HASH_OPTIONS_SHADOW_RESOLUTION_20 )
  {
    this->mOptionChanged = 1;
    this->mExitDelayNeeded = 1;
    v13 = UFG::UI::GetFlashArgsInt(msg) - 1;
    if ( v13 )
    {
      v14 = v13 - 1;
      if ( !v14 )
      {
        v15 = SHADOW_RES_NORMAL;
        goto LABEL_22;
      }
      if ( v14 == 1 )
      {
        v15 = SHADOW_RES_HIGH;
LABEL_22:
        UFG::GameStatTracker::SetStat(v6, Display_ShadowResolution, v15 != SHADOW_RES_OFF);
        this->mCurrentDisplaySettings.mShadowRes = v15;
        goto LABEL_56;
      }
    }
    v15 = SHADOW_RES_OFF;
    goto LABEL_22;
  }
  if ( msgId == UI_HASH_OPTIONS_SHADOW_FILTERING_20 )
  {
    this->mOptionChanged = 1;
    this->mExitDelayNeeded = 1;
    v16 = UFG::UI::GetFlashArgsInt(msg);
    v17 = v16 != 1;
    UFG::GameStatTracker::SetStat(v6, Display_ShadowFiltering, v16 != 1);
    this->mCurrentDisplaySettings.mShadowFilter = v17;
  }
  else if ( msgId == UI_HASH_OPTIONS_SSAO_20 )
  {
    this->mOptionChanged = 1;
    this->mExitDelayNeeded = 1;
    v18 = UFG::UI::GetFlashArgsInt(msg);
    v19 = v18 != 1;
    UFG::GameStatTracker::SetStat(v6, Display_SSAO, v18 != 1);
    this->mCurrentDisplaySettings.mSSAO = v19;
  }
  else if ( msgId == UI_HASH_OPTIONS_VSYNC_20 )
  {
    this->mOptionChanged = 1;
    this->mExitDelayNeeded = 1;
    v20 = (unsigned int)UFG::UI::GetFlashArgsInt(msg) == 2;
    UFG::GameStatTracker::SetStat(v6, Display_EnableVSync, v20);
    this->mCurrentDisplaySettings.mEnableVSync = v20;
  }
  else if ( msgId == UI_HASH_OPTIONS_QUALITY_MOTION_BLUR_20 )
  {
    this->mOptionChanged = 1;
    this->mExitDelayNeeded = 1;
    v21 = UFG::UI::GetFlashArgsInt(msg);
    v22 = v21 - 1;
    UFG::GameStatTracker::SetStat(v6, Display_HighQualityMotionBlur, v21 != 1);
    this->mCurrentDisplaySettings.mMotionBlur = v22;
  }
  else if ( msgId == UI_HASH_OPTIONS_FPS_LIMITER_20 )
  {
    this->mOptionChanged = 1;
    this->mExitDelayNeeded = 1;
    v23 = (unsigned int)UFG::UI::GetFlashArgsInt(msg);
    UFG::GameStatTracker::SetStat(v6, Display_FPSLimiter, v23 != FPS_LIMITER_OFF);
    this->mCurrentDisplaySettings.mFPSLimiter = v23;
  }
  else if ( msgId == UI_HASH_OPTIONS_3D_DEPTH_20 )
  {
    this->mOptionChanged = 1;
    this->mExitDelayNeeded = 1;
    this->mCurrentDisplaySettings.m3DDepth = UFG::UI::GetFlashArgsInt(msg);
  }
  else if ( msgId == UI_HASH_OPTIONS_3D_CONVERGENCE_20 )
  {
    this->mOptionChanged = 1;
    this->mExitDelayNeeded = 1;
    this->mCurrentDisplaySettings.m3DConvergence = UFG::UI::GetFlashArgsInt(msg);
  }
  else if ( msgId == UI_HASH_OPTIONS_WORLD_DENSITY_20 )
  {
    this->mOptionChanged = 1;
    this->mExitDelayNeeded = 1;
    this->mCurrentDisplaySettings.mLODSetting = UFG::UI::GetFlashArgsInt(msg) - 1;
  }
  else if ( msgId == UI_HASH_OPTIONS_LOW_RES_BUFFERS_20 )
  {
    this->mOptionChanged = 1;
    this->mCurrentDisplaySettings.mEnableLowResBuffer = (unsigned int)UFG::UI::GetFlashArgsInt(msg) == 2;
  }
  else if ( msgId == UI_HASH_OPTION_DISABLED_30 )
  {
    UFG::UIScreenDialogBox::createOKDialog(this, &customCaption, "$UI_OPTION_VSYCN_LOCKED", 0);
  }
  else
  {
    if ( msgId == UI_HASH_BUTTON_BUTTON1_PRESSED_30 )
    {
      if ( (unsigned int)UFG::FlowController::GetCurrentState(&UFG::gFlowController) == uidGameStateFE_13 )
        UFG::UIHKScreenOptionsDisplayAdvanced::StartBenchmark(this);
      return 1;
    }
    if ( msgId == (_DWORD)UI_HASH_BUTTON_BUTTON2_PRESSED_30 )
    {
      UFG::UIScreenDialogBox::createYesNoDialog(this, "$OPTIONS_OPTIONS_CHANGED", "$OPTIONS_SAVE_CHANGES", 1, 1);
      this->mState = STATE_UISCALE;
      return 1;
    }
    if ( msgId == UI_HASH_DIALOG_YES_30 )
    {
      if ( this->mState == STATE_UISCALE )
      {
        v24 = UFG::GameSaveLoad::Instance();
        UFG::GameSaveLoad::ApplyOptions(v24);
        v25 = UFG::GameSaveLoad::Instance();
        UFG::GameSaveLoad::SaveGameOptions(v25);
        UFG::DataSynchronizer::SetOptionsDirty();
        ((void (__fastcall *)(UFG::UIHKScreenOptionsDisplayAdvanced *))this->vfptr[1].update)(this);
        this->mOptionChanged = 0;
        goto LABEL_52;
      }
    }
    else if ( msgId == UI_HASH_DIALOG_NO_30 && this->mState == STATE_UISCALE )
    {
      ((void (__fastcall *)(UFG::UIHKScreenOptionsDisplayAdvanced *))this->vfptr[1].handleMessage)(this);
      v26 = UFG::GameSaveLoad::Instance();
      UFG::GameSaveLoad::ApplyOptions(v26);
      this->mState = STATE_BRIGHTNESS;
      return 1;
    }
  }
LABEL_56:
  if ( this->mState != STATE_BRIGHTNESS )
  {
    if ( this->mState != STATE_VOLUME )
    {
      if ( this->mState == NUM_CALIBRATION_STATES && msgId == UI_HASH_DIALOG_OK_30 )
      {
        this->mState = STATE_BRIGHTNESS;
        return 1;
      }
      return 0;
    }
    if ( msgId != UI_HASH_DIALOG_OK_30 )
      return 0;
LABEL_52:
    this->mState = STATE_BRIGHTNESS;
    return 1;
  }
  return UFG::UIHKScreenOptions::handleMessage(this, msgId, msg);
}

// File Line: 375
// RVA: 0x5D3C50
void __fastcall UFG::UIHKScreenOptionsDisplayAdvanced::ApplyOptions(UFG::UIHKScreenOptionsDisplayAdvanced *this)
{
  Render::RenderOutputParams *p_mCurrentDisplaySettings; // rdi
  __int128 v3; // xmm1
  __int128 v4; // xmm1
  __int128 v5; // xmm1
  Render::RenderOutputParams v6; // [rsp+20h] [rbp-78h] BYREF

  p_mCurrentDisplaySettings = &this->mCurrentDisplaySettings;
  Render::RenderOutputParams::ChangeGlobalSetting(&this->mCurrentDisplaySettings, GRAPHICS_CUSTOM);
  if ( UFG::UIHKScreenOptionsDisplayAdvanced::ApplyRenderOptions(this, p_mCurrentDisplaySettings) )
  {
    Render::RenderOutputParams::RenderOutputParams(&v6);
    v3 = *(_OWORD *)&p_mCurrentDisplaySettings->mDisplayMode.mAdapterUID;
    *(_OWORD *)&v6.mDisplayMode.mBackBufferWidth = *(_OWORD *)&p_mCurrentDisplaySettings->mDisplayMode.mBackBufferWidth;
    *(_OWORD *)&v6.mDisplayMode.mAdapterUID = v3;
    v4 = *(_OWORD *)&p_mCurrentDisplaySettings->mShadowFilter;
    *(_OWORD *)&v6.mEnableFullscreen = *(_OWORD *)&p_mCurrentDisplaySettings->mEnableFullscreen;
    *(_OWORD *)&v6.mShadowFilter = v4;
    v5 = *(_OWORD *)&p_mCurrentDisplaySettings->mLODSetting;
    *(_OWORD *)&v6.mFPSLimiter = *(_OWORD *)&p_mCurrentDisplaySettings->mFPSLimiter;
    *(_OWORD *)&v6.mLODSetting = v5;
    *(_QWORD *)&v6.mTextureFilterQuality = *(_QWORD *)&p_mCurrentDisplaySettings->mTextureFilterQuality;
    UFG::GameStatPCDisplaySettings::SaveToXML(
      (UFG::GameStatPCDisplaySettings *)&v6,
      UFG::GameStatPCDisplaySettings::gDefaultSavePath);
  }
}

// File Line: 402
// RVA: 0x5D3E10
char __fastcall UFG::UIHKScreenOptionsDisplayAdvanced::ApplyRenderOptions(
        UFG::UIHKScreenOptionsDisplayAdvanced *this,
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

// File Line: 427
// RVA: 0x5D7A40
void __fastcall UFG::UIHKScreenOptionsDisplayAdvanced::Exit(UFG::UIHKScreenOptionsDisplayAdvanced *this)
{
  bool v2; // zf

  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xA4E5BFBD, 0i64, 0, 0i64);
  v2 = !this->mExitDelayNeeded;
  this->mState = NUM_CALIBRATION_STATES|STATE_BRIGHTNESS;
  if ( v2 )
  {
    this->mExitTimer = 0.0;
  }
  else
  {
    this->mExitTimer = 3.0;
    this->mDialogUID = UFG::UIScreenDialogBox::createZeroButtonDialog(
                         this,
                         &customCaption,
                         "$LOADING_PLEASE_WAIT",
                         0,
                         "DialogBox");
  }
}

// File Line: 500
// RVA: 0x611DB0
void __fastcall UFG::UIHKScreenOptionsDisplayAdvanced::StartBenchmark(UFG::UIHKScreenOptionsDisplayAdvanced *this)
{
  UFG::UI *v1; // rcx
  unsigned int v2; // ebx
  UFG::GameState *GameStateObj; // rax

  UFG::FlowController::GetCurrentState(&UFG::gFlowController);
  UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, 0xFFFFFFFF);
  UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, 0xFFFFFFFF);
  UFG::UI::UnpauseGame(v1);
  v2 = uidGameStateLoadGame_13;
  if ( !(unsigned int)UFG::FlowController::RequestSetNewState(&UFG::gFlowController, uidGameStateLoadGame_13) )
  {
    UFG::qStringCopy(gameSetup, 100, "gameSetupGame_Calibration", -1);
    GameStateObj = UFG::FlowController::GetGameStateObj(&UFG::gFlowController, v2);
    if ( GameStateObj )
      UFG::qString::Set(&GameStateObj->mGameStateUserDataStr, gameSetup);
  }
}

// File Line: 532
// RVA: 0x60EFA0
void __fastcall UFG::UIHKScreenOptionsDisplayAdvanced::ShowHelpBar(UFG::UIHKScreenOptionsDisplayAdvanced *this)
{
  int v2; // esi
  unsigned int v3; // ebp
  int v4; // ecx
  __int64 v5; // rax
  __int64 v6; // rdi
  __int64 v7; // rbx
  unsigned int v8; // ebp
  int v9; // ecx
  __int64 v10; // rax
  __int64 v11; // rdi
  __int64 v12; // rbx
  unsigned int v13; // ebp
  __int64 v14; // rax
  __int64 v15; // rbx
  UFG::UIHKScreenGlobalOverlay *v16; // rax
  UFG::UIHKHelpBarData data; // [rsp+30h] [rbp-258h] BYREF

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
  UFG::qString::Set(&data.Icons[v7], &customCaption);
  data.MessageIds[v6] = v3;
LABEL_6:
  if ( (unsigned int)UFG::FlowController::GetCurrentState(&UFG::gFlowController) == uidGameStateFE_13 )
  {
    v8 = UI_HASH_BUTTON_BUTTON1_PRESSED_30;
    v9 = 0;
    v10 = 0i64;
    while ( data.Buttons[v10] )
    {
      ++v9;
      if ( ++v10 >= 6 )
        goto LABEL_12;
    }
    v11 = v9;
    data.Buttons[v11] = BUTTON1_BUTTON;
    v12 = v9;
    UFG::qString::Set(&data.Captions[v12], "$OPTIONS_BENCHMARK_MODE");
    UFG::qString::Set(&data.Icons[v12], &customCaption);
    data.MessageIds[v11] = v8;
  }
LABEL_12:
  v13 = (unsigned int)UI_HASH_BUTTON_BUTTON2_PRESSED_30;
  v14 = 0i64;
  while ( data.Buttons[v14] )
  {
    ++v2;
    if ( ++v14 >= 6 )
      goto LABEL_17;
  }
  data.Buttons[v2] = BUTTON2_BUTTON;
  v15 = v2;
  UFG::qString::Set(&data.Captions[v15], "$OPTIONS_SAVE_ADVANCED_DISPLAY");
  UFG::qString::Set(&data.Icons[v15], &customCaption);
  data.MessageIds[v2] = v13;
LABEL_17:
  v16 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    v16 = &gGlobalOverlaySentinel;
  UFG::UIHKHelpBarWidget::Show(&v16->HelpBar, &data);
  UFG::qString::~qString(&data.CustomTexturePack);
  `eh vector destructor iterator(data.Icons, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
  `eh vector destructor iterator(data.Captions, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
}

