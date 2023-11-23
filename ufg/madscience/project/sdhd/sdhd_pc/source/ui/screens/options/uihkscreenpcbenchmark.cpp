// File Line: 47
// RVA: 0xA40DC0
void __fastcall UFG::UIHKScreenPCBenchmark::UIHKScreenPCBenchmark(UFG::UIHKScreenPCBenchmark *this)
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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenPCBenchmark::`vftable;
}

// File Line: 58
// RVA: 0xA40FA0
void __fastcall UFG::UIHKScreenPCBenchmark::init(UFG::UIHKScreenPCBenchmark *this, UFG::UICommandData *data)
{
  UFG::UI *v3; // rcx
  Scaleform::GFx::Movie *pObject; // rdi
  const char *v5; // rsi
  char *mData; // rbx
  char *v7; // rbx
  char *v8; // rbx
  float v9; // xmm6_4
  double mBackBufferWidth; // xmm7_8
  double mBackBufferHeight; // xmm7_8
  double mAAQuality; // xmm7_8
  double mShadowRes; // xmm7_8
  double mShadowFilter; // xmm7_8
  double mSSAO; // xmm7_8
  double mEnableVSync; // xmm7_8
  double v17; // xmm7_8
  double mFPSLimiter; // xmm7_8
  char *v19; // rbx
  char *v20; // rbx
  char *v21; // rbx
  char *v22; // rbx
  double v23; // xmm6_8
  UFG::BenchmarkHelper::BenchmarkResult result; // [rsp+30h] [rbp-B8h] BYREF
  Scaleform::GFx::Value ptr; // [rsp+40h] [rbp-A8h] BYREF
  int v26; // [rsp+70h] [rbp-78h] BYREF
  char *v27; // [rsp+78h] [rbp-70h]
  char v28[16]; // [rsp+88h] [rbp-60h] BYREF
  __int64 v29; // [rsp+98h] [rbp-50h]
  int v30; // [rsp+A0h] [rbp-48h]
  char *v31; // [rsp+A8h] [rbp-40h]
  char v32[16]; // [rsp+B8h] [rbp-30h] BYREF
  __int64 v33; // [rsp+C8h] [rbp-20h]
  int v34; // [rsp+D0h] [rbp-18h]
  double v35; // [rsp+D8h] [rbp-10h]
  char v36[16]; // [rsp+E8h] [rbp+0h] BYREF
  __int64 v37; // [rsp+F8h] [rbp+10h]
  int v38; // [rsp+100h] [rbp+18h]
  double v39; // [rsp+108h] [rbp+20h]
  char v40[16]; // [rsp+118h] [rbp+30h] BYREF
  __int64 v41; // [rsp+128h] [rbp+40h]
  int v42; // [rsp+130h] [rbp+48h]
  double v43; // [rsp+138h] [rbp+50h]
  char v44[16]; // [rsp+148h] [rbp+60h] BYREF
  __int64 v45; // [rsp+158h] [rbp+70h]
  int v46; // [rsp+160h] [rbp+78h]
  double v47; // [rsp+168h] [rbp+80h]
  char v48[16]; // [rsp+178h] [rbp+90h] BYREF
  __int64 v49; // [rsp+188h] [rbp+A0h]
  int v50; // [rsp+190h] [rbp+A8h]
  double v51; // [rsp+198h] [rbp+B0h]
  char v52[16]; // [rsp+1A8h] [rbp+C0h] BYREF
  __int64 v53; // [rsp+1B8h] [rbp+D0h]
  int v54; // [rsp+1C0h] [rbp+D8h]
  double v55; // [rsp+1C8h] [rbp+E0h]
  char v56[16]; // [rsp+1D8h] [rbp+F0h] BYREF
  __int64 v57; // [rsp+1E8h] [rbp+100h]
  int v58; // [rsp+1F0h] [rbp+108h]
  double v59; // [rsp+1F8h] [rbp+110h]
  char v60[16]; // [rsp+208h] [rbp+120h] BYREF
  __int64 v61; // [rsp+218h] [rbp+130h]
  int v62; // [rsp+220h] [rbp+138h]
  double v63; // [rsp+228h] [rbp+140h]
  char v64[16]; // [rsp+238h] [rbp+150h] BYREF
  __int64 v65; // [rsp+248h] [rbp+160h]
  int v66; // [rsp+250h] [rbp+168h]
  double v67; // [rsp+258h] [rbp+170h]
  char v68[16]; // [rsp+268h] [rbp+180h] BYREF
  __int64 v69; // [rsp+278h] [rbp+190h]
  int v70; // [rsp+280h] [rbp+198h]
  double v71; // [rsp+288h] [rbp+1A0h]
  char v72[16]; // [rsp+298h] [rbp+1B0h] BYREF
  __int64 v73; // [rsp+2A8h] [rbp+1C0h]
  int v74; // [rsp+2B0h] [rbp+1C8h]
  char *v75; // [rsp+2B8h] [rbp+1D0h]
  char v76[16]; // [rsp+2C8h] [rbp+1E0h] BYREF
  __int64 v77; // [rsp+2D8h] [rbp+1F0h]
  int v78; // [rsp+2E0h] [rbp+1F8h]
  char *v79; // [rsp+2E8h] [rbp+200h]
  char v80[16]; // [rsp+2F8h] [rbp+210h] BYREF
  __int64 v81; // [rsp+308h] [rbp+220h]
  int v82; // [rsp+310h] [rbp+228h]
  char *v83; // [rsp+318h] [rbp+230h]
  char v84[16]; // [rsp+328h] [rbp+240h] BYREF
  __int64 v85; // [rsp+338h] [rbp+250h]
  int v86; // [rsp+340h] [rbp+258h]
  char *v87; // [rsp+348h] [rbp+260h]
  char v88[16]; // [rsp+358h] [rbp+270h] BYREF
  __int64 v89; // [rsp+368h] [rbp+280h]
  int v90; // [rsp+370h] [rbp+288h]
  char *v91; // [rsp+378h] [rbp+290h]
  char v92[16]; // [rsp+388h] [rbp+2A0h] BYREF
  __int64 v93; // [rsp+398h] [rbp+2B0h]
  int v94; // [rsp+3A0h] [rbp+2B8h]
  double v95; // [rsp+3A8h] [rbp+2C0h]
  __int64 v96; // [rsp+3B8h] [rbp+2D0h]
  Render::RenderOutputParams outSettings; // [rsp+3C8h] [rbp+2E0h] BYREF
  UFG::qString v98; // [rsp+438h] [rbp+350h] BYREF
  UFG::qString v99; // [rsp+460h] [rbp+378h] BYREF
  UFG::qString v100; // [rsp+488h] [rbp+3A0h] BYREF
  UFG::qString v101; // [rsp+4B0h] [rbp+3C8h] BYREF
  UFG::qString v102; // [rsp+4D8h] [rbp+3F0h] BYREF
  UFG::qString v103; // [rsp+500h] [rbp+418h] BYREF
  UFG::qString v104; // [rsp+528h] [rbp+440h] BYREF

  v96 = -2i64;
  UFG::UIScreen::init(this, data);
  UFG::UI::LockGameplayInput(v3);
  UFG::UIHK_NISOverlay::HideCurtains(0.0, 0);
  UFG::BenchmarkHelper::GetLastResults(&UFG::BenchmarkHelper::gBenchmarkHelper, &result);
  pObject = this->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    v5 = UFG::UI::LocalizeText("$FPS_PARAMETER");
    UFG::qString::FormatEx(&v100, v5, result.averageFPS);
    UFG::qString::FormatEx(&v99, v5, result.maxFPS);
    UFG::qString::FormatEx(&v101, v5, result.minFPS);
    `eh vector constructor iterator(&ptr, 0x30ui64, 19, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    mData = v100.mData;
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
    v7 = v99.mData;
    if ( (v26 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(unsigned __int64, int *, char *))(*(_QWORD *)ptr.DataAux + 16i64))(ptr.DataAux, &v26, v27);
      ptr.DataAux = 0i64;
    }
    v26 = 6;
    v27 = v7;
    v8 = v101.mData;
    if ( (v30 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v29 + 16i64))(v29, v28, v31);
      v29 = 0i64;
    }
    v30 = 6;
    v31 = v8;
    Render::RenderOutputParams::RenderOutputParams(&outSettings);
    Render::GetCurrentDisplaySettings(&outSettings);
    v9 = (float)(int)outSettings.mDisplayMode.mRefreshRateNumerator
       / (float)(int)outSettings.mDisplayMode.mRefreshRateDenominator;
    mBackBufferWidth = (double)(int)outSettings.mDisplayMode.mBackBufferWidth;
    if ( (v34 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v33 + 16i64))(
        v33,
        v32,
        COERCE_DOUBLE(*(_QWORD *)&v35));
      v33 = 0i64;
    }
    v34 = 5;
    v35 = mBackBufferWidth;
    mBackBufferHeight = (double)(int)outSettings.mDisplayMode.mBackBufferHeight;
    if ( (v38 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v37 + 16i64))(
        v37,
        v36,
        COERCE_DOUBLE(*(_QWORD *)&v39));
      v37 = 0i64;
    }
    v38 = 5;
    v39 = mBackBufferHeight;
    if ( (v42 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v41 + 16i64))(
        v41,
        v40,
        COERCE_DOUBLE(*(_QWORD *)&v43));
      v41 = 0i64;
    }
    v42 = 5;
    v43 = v9;
    mAAQuality = (double)(int)outSettings.mAAQuality;
    if ( (v46 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v45 + 16i64))(
        v45,
        v44,
        COERCE_DOUBLE(*(_QWORD *)&v47));
      v45 = 0i64;
    }
    v46 = 5;
    v47 = mAAQuality;
    mShadowRes = (double)(int)outSettings.mShadowRes;
    if ( (v50 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v49 + 16i64))(
        v49,
        v48,
        COERCE_DOUBLE(*(_QWORD *)&v51));
      v49 = 0i64;
    }
    v50 = 5;
    v51 = mShadowRes;
    mShadowFilter = (double)(int)outSettings.mShadowFilter;
    if ( (v54 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v53 + 16i64))(
        v53,
        v52,
        COERCE_DOUBLE(*(_QWORD *)&v55));
      v53 = 0i64;
    }
    v54 = 5;
    v55 = mShadowFilter;
    mSSAO = (double)(int)outSettings.mSSAO;
    if ( (v58 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v57 + 16i64))(
        v57,
        v56,
        COERCE_DOUBLE(*(_QWORD *)&v59));
      v57 = 0i64;
    }
    v58 = 5;
    v59 = mSSAO;
    mEnableVSync = (double)outSettings.mEnableVSync;
    if ( (v62 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v61 + 16i64))(
        v61,
        v60,
        COERCE_DOUBLE(*(_QWORD *)&v63));
      v61 = 0i64;
    }
    v62 = 5;
    v63 = mEnableVSync;
    v17 = (double)(outSettings.mMotionBlur == MOTION_BLUR_HIGH);
    if ( (v66 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v65 + 16i64))(
        v65,
        v64,
        COERCE_DOUBLE(*(_QWORD *)&v67));
      v65 = 0i64;
    }
    v66 = 5;
    v67 = v17;
    mFPSLimiter = (double)(int)outSettings.mFPSLimiter;
    if ( (v70 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v69 + 16i64))(
        v69,
        v68,
        COERCE_DOUBLE(*(_QWORD *)&v71));
      v69 = 0i64;
    }
    v70 = 5;
    v71 = mFPSLimiter;
    UFG::qString::FormatEx(&v98, v5, v9);
    UFG::qString::FormatEx(&v104, v5, (float)(v9 * 0.5));
    UFG::qString::FormatEx(&v102, v5, (float)(v9 * 0.33333334));
    UFG::qString::FormatEx(&v103, v5, (float)(v9 * 0.25));
    v19 = v98.mData;
    if ( (v74 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v73 + 16i64))(v73, v72, v75);
      v73 = 0i64;
    }
    v74 = 6;
    v75 = v19;
    v20 = v104.mData;
    if ( (v78 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v77 + 16i64))(v77, v76, v79);
      v77 = 0i64;
    }
    v78 = 6;
    v79 = v20;
    v21 = v102.mData;
    if ( (v82 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v81 + 16i64))(v81, v80, v83);
      v81 = 0i64;
    }
    v82 = 6;
    v83 = v21;
    v22 = v103.mData;
    if ( (v86 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v85 + 16i64))(v85, v84, v87);
      v85 = 0i64;
    }
    v86 = 6;
    v87 = v22;
    if ( (v90 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v89 + 16i64))(v89, v88, v91);
      v89 = 0i64;
    }
    v90 = 6;
    v91 = Render::gVideoCardDesc;
    v23 = (double)(Render::gVideoMemory >> 20);
    if ( (v94 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v93 + 16i64))(
        v93,
        v92,
        COERCE_DOUBLE(*(_QWORD *)&v95));
      v93 = 0i64;
    }
    v94 = 5;
    v95 = v23;
    Scaleform::GFx::Movie::Invoke(pObject, "SetBenchmarkValues", 0i64, &ptr, 0x13u);
    if ( gAutoBenchmarkMode )
      gGameQuitEvent = 1;
    UFG::qString::~qString(&v103);
    UFG::qString::~qString(&v102);
    UFG::qString::~qString(&v104);
    UFG::qString::~qString(&v98);
    `eh vector destructor iterator(&ptr, 0x30ui64, 19, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    UFG::qString::~qString(&v101);
    UFG::qString::~qString(&v99);
    UFG::qString::~qString(&v100);
  }
}

// File Line: 137
// RVA: 0xA40EA0
char __fastcall UFG::UIHKScreenPCBenchmark::handleMessage(
        UFG::UIHKScreenPCBenchmark *this,
        unsigned int msgId,
        UFG::UIMessage *msg)
{
  Scaleform::GFx::Movie *pObject; // rdi
  const char *v5; // rdx

  pObject = this->mRenderable->m_movie.pObject;
  if ( msgId == UI_HASH_BUTTON_BACK_PRESSED_43 )
  {
    UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, 0xFFFFFFFF);
    UFG::UI::QuitGame(0i64);
    return 1;
  }
  if ( msgId == UI_HASH_DPAD_DOWN_PRESSED_43
    || msgId == UI_HASH_DPAD_DOWN_REPEAT_43
    || msgId == UI_HASH_THUMBSTICK_LEFT_DOWN_43 )
  {
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xEDB4A8C7, 0i64, 0, 0i64);
    if ( !pObject )
      return 1;
    v5 = "ScrollDown";
    goto LABEL_18;
  }
  if ( msgId != UI_HASH_DPAD_UP_PRESSED_43
    && msgId != UI_HASH_DPAD_UP_REPEAT_43
    && msgId != UI_HASH_THUMBSTICK_LEFT_UP_43 )
  {
    return UFG::UIScreen::handleMessage(this, msgId, msg);
  }
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xEDB4A8C7, 0i64, 0, 0i64);
  if ( pObject )
  {
    v5 = "ScrollUp";
LABEL_18:
    Scaleform::GFx::Movie::Invoke(pObject, v5, 0i64, 0i64, 0);
  }
  return 1;
}

