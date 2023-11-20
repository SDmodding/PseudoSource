// File Line: 47
// RVA: 0xA40DC0
void __fastcall UFG::UIHKScreenPCBenchmark::UIHKScreenPCBenchmark(UFG::UIHKScreenPCBenchmark *this)
{
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v1; // rax

  v1 = (UFG::qNode<UFG::UIScreen,UFG::UIScreen> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenPCBenchmark::`vftable;
}

// File Line: 58
// RVA: 0xA40FA0
void __usercall UFG::UIHKScreenPCBenchmark::init(UFG::UIHKScreenPCBenchmark *this@<rcx>, UFG::UICommandData *data@<rdx>, float a3@<xmm0>)
{
  UFG::UIHKScreenPCBenchmark *v3; // rbx
  UFG::UI *v4; // rcx
  Scaleform::GFx::Movie *v5; // rdi
  const char *v6; // rsi
  char *v7; // rbx
  char *v8; // rbx
  char *v9; // rbx
  float v10; // xmm6_4
  double v11; // xmm7_8
  double v12; // xmm7_8
  double v13; // xmm7_8
  double v14; // xmm7_8
  double v15; // xmm7_8
  double v16; // xmm7_8
  double v17; // xmm7_8
  double v18; // xmm7_8
  double v19; // xmm7_8
  char *v20; // rbx
  char *v21; // rbx
  char *v22; // rbx
  char *v23; // rbx
  double v24; // xmm6_8
  UFG::BenchmarkHelper::BenchmarkResult result; // [rsp+30h] [rbp-B8h]
  char ptr; // [rsp+40h] [rbp-A8h]
  __int64 v27; // [rsp+50h] [rbp-98h]
  unsigned int v28; // [rsp+58h] [rbp-90h]
  char *v29; // [rsp+60h] [rbp-88h]
  __int64 v30; // [rsp+68h] [rbp-80h]
  unsigned int v31; // [rsp+70h] [rbp-78h]
  char *v32; // [rsp+78h] [rbp-70h]
  char v33; // [rsp+88h] [rbp-60h]
  __int64 v34; // [rsp+98h] [rbp-50h]
  unsigned int v35; // [rsp+A0h] [rbp-48h]
  char *v36; // [rsp+A8h] [rbp-40h]
  char v37; // [rsp+B8h] [rbp-30h]
  __int64 v38; // [rsp+C8h] [rbp-20h]
  unsigned int v39; // [rsp+D0h] [rbp-18h]
  double v40; // [rsp+D8h] [rbp-10h]
  char v41; // [rsp+E8h] [rbp+0h]
  __int64 v42; // [rsp+F8h] [rbp+10h]
  unsigned int v43; // [rsp+100h] [rbp+18h]
  double v44; // [rsp+108h] [rbp+20h]
  char v45; // [rsp+118h] [rbp+30h]
  __int64 v46; // [rsp+128h] [rbp+40h]
  unsigned int v47; // [rsp+130h] [rbp+48h]
  double v48; // [rsp+138h] [rbp+50h]
  char v49; // [rsp+148h] [rbp+60h]
  __int64 v50; // [rsp+158h] [rbp+70h]
  unsigned int v51; // [rsp+160h] [rbp+78h]
  double v52; // [rsp+168h] [rbp+80h]
  char v53; // [rsp+178h] [rbp+90h]
  __int64 v54; // [rsp+188h] [rbp+A0h]
  unsigned int v55; // [rsp+190h] [rbp+A8h]
  double v56; // [rsp+198h] [rbp+B0h]
  char v57; // [rsp+1A8h] [rbp+C0h]
  __int64 v58; // [rsp+1B8h] [rbp+D0h]
  unsigned int v59; // [rsp+1C0h] [rbp+D8h]
  double v60; // [rsp+1C8h] [rbp+E0h]
  char v61; // [rsp+1D8h] [rbp+F0h]
  __int64 v62; // [rsp+1E8h] [rbp+100h]
  unsigned int v63; // [rsp+1F0h] [rbp+108h]
  double v64; // [rsp+1F8h] [rbp+110h]
  char v65; // [rsp+208h] [rbp+120h]
  __int64 v66; // [rsp+218h] [rbp+130h]
  unsigned int v67; // [rsp+220h] [rbp+138h]
  double v68; // [rsp+228h] [rbp+140h]
  char v69; // [rsp+238h] [rbp+150h]
  __int64 v70; // [rsp+248h] [rbp+160h]
  unsigned int v71; // [rsp+250h] [rbp+168h]
  double v72; // [rsp+258h] [rbp+170h]
  char v73; // [rsp+268h] [rbp+180h]
  __int64 v74; // [rsp+278h] [rbp+190h]
  unsigned int v75; // [rsp+280h] [rbp+198h]
  double v76; // [rsp+288h] [rbp+1A0h]
  char v77; // [rsp+298h] [rbp+1B0h]
  __int64 v78; // [rsp+2A8h] [rbp+1C0h]
  unsigned int v79; // [rsp+2B0h] [rbp+1C8h]
  char *v80; // [rsp+2B8h] [rbp+1D0h]
  char v81; // [rsp+2C8h] [rbp+1E0h]
  __int64 v82; // [rsp+2D8h] [rbp+1F0h]
  unsigned int v83; // [rsp+2E0h] [rbp+1F8h]
  char *v84; // [rsp+2E8h] [rbp+200h]
  char v85; // [rsp+2F8h] [rbp+210h]
  __int64 v86; // [rsp+308h] [rbp+220h]
  unsigned int v87; // [rsp+310h] [rbp+228h]
  char *v88; // [rsp+318h] [rbp+230h]
  char v89; // [rsp+328h] [rbp+240h]
  __int64 v90; // [rsp+338h] [rbp+250h]
  unsigned int v91; // [rsp+340h] [rbp+258h]
  char *v92; // [rsp+348h] [rbp+260h]
  char v93; // [rsp+358h] [rbp+270h]
  __int64 v94; // [rsp+368h] [rbp+280h]
  unsigned int v95; // [rsp+370h] [rbp+288h]
  char *v96; // [rsp+378h] [rbp+290h]
  char v97; // [rsp+388h] [rbp+2A0h]
  __int64 v98; // [rsp+398h] [rbp+2B0h]
  unsigned int v99; // [rsp+3A0h] [rbp+2B8h]
  double v100; // [rsp+3A8h] [rbp+2C0h]
  __int64 v101; // [rsp+3B8h] [rbp+2D0h]
  Render::RenderOutputParams outSettings; // [rsp+3C8h] [rbp+2E0h]
  UFG::qString v103; // [rsp+438h] [rbp+350h]
  UFG::qString v104; // [rsp+460h] [rbp+378h]
  UFG::qString v105; // [rsp+488h] [rbp+3A0h]
  UFG::qString v106; // [rsp+4B0h] [rbp+3C8h]
  UFG::qString v107; // [rsp+4D8h] [rbp+3F0h]
  UFG::qString v108; // [rsp+500h] [rbp+418h]
  UFG::qString v109; // [rsp+528h] [rbp+440h]

  v101 = -2i64;
  v3 = this;
  UFG::UIScreen::init((UFG::UIScreen *)&this->vfptr, data, a3);
  UFG::UI::LockGameplayInput(v4);
  UFG::UIHK_NISOverlay::HideCurtains(0.0, 0);
  UFG::BenchmarkHelper::GetLastResults(&UFG::BenchmarkHelper::gBenchmarkHelper, &result);
  v5 = v3->mRenderable->m_movie.pObject;
  if ( v5 )
  {
    v6 = UFG::UI::LocalizeText(asc_1417E6158);
    UFG::qString::FormatEx(&v105, v6, result.averageFPS);
    UFG::qString::FormatEx(&v104, v6, result.maxFPS);
    UFG::qString::FormatEx(&v106, v6, result.minFPS);
    `eh vector constructor iterator(&ptr, 0x30ui64, 19, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    v7 = v105.mData;
    if ( (v28 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v27 + 16i64))(v27, &ptr, v29);
      v27 = 0i64;
    }
    v28 = 6;
    v29 = v7;
    v8 = v104.mData;
    if ( (v31 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, unsigned int *, char *))(*(_QWORD *)v30 + 16i64))(v30, &v31, v32);
      v30 = 0i64;
    }
    v31 = 6;
    v32 = v8;
    v9 = v106.mData;
    if ( (v35 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v34 + 16i64))(v34, &v33, v36);
      v34 = 0i64;
    }
    v35 = 6;
    v36 = v9;
    Render::RenderOutputParams::RenderOutputParams(&outSettings);
    Render::GetCurrentDisplaySettings(&outSettings);
    v10 = (float)(signed int)outSettings.mDisplayMode.mRefreshRateNumerator
        / (float)(signed int)outSettings.mDisplayMode.mRefreshRateDenominator;
    v11 = (double)(signed int)outSettings.mDisplayMode.mBackBufferWidth;
    if ( (v39 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v38 + 16i64))(
        v38,
        &v37,
        COERCE_DOUBLE(*(_QWORD *)&v40));
      v38 = 0i64;
    }
    v39 = 5;
    v40 = v11;
    v12 = (double)(signed int)outSettings.mDisplayMode.mBackBufferHeight;
    if ( (v43 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v42 + 16i64))(
        v42,
        &v41,
        COERCE_DOUBLE(*(_QWORD *)&v44));
      v42 = 0i64;
    }
    v43 = 5;
    v44 = v12;
    if ( (v47 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v46 + 16i64))(
        v46,
        &v45,
        COERCE_DOUBLE(*(_QWORD *)&v48));
      v46 = 0i64;
    }
    v47 = 5;
    v48 = v10;
    v13 = (double)(signed int)outSettings.mAAQuality;
    if ( (v51 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v50 + 16i64))(
        v50,
        &v49,
        COERCE_DOUBLE(*(_QWORD *)&v52));
      v50 = 0i64;
    }
    v51 = 5;
    v52 = v13;
    v14 = (double)(signed int)outSettings.mShadowRes;
    if ( (v55 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v54 + 16i64))(
        v54,
        &v53,
        COERCE_DOUBLE(*(_QWORD *)&v56));
      v54 = 0i64;
    }
    v55 = 5;
    v56 = v14;
    v15 = (double)(signed int)outSettings.mShadowFilter;
    if ( (v59 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v58 + 16i64))(
        v58,
        &v57,
        COERCE_DOUBLE(*(_QWORD *)&v60));
      v58 = 0i64;
    }
    v59 = 5;
    v60 = v15;
    v16 = (double)(signed int)outSettings.mSSAO;
    if ( (v63 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v62 + 16i64))(
        v62,
        &v61,
        COERCE_DOUBLE(*(_QWORD *)&v64));
      v62 = 0i64;
    }
    v63 = 5;
    v64 = v16;
    v17 = (double)outSettings.mEnableVSync;
    if ( (v67 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v66 + 16i64))(
        v66,
        &v65,
        COERCE_DOUBLE(*(_QWORD *)&v68));
      v66 = 0i64;
    }
    v67 = 5;
    v68 = v17;
    v18 = (double)(outSettings.mMotionBlur == 2);
    if ( (v71 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v70 + 16i64))(
        v70,
        &v69,
        COERCE_DOUBLE(*(_QWORD *)&v72));
      v70 = 0i64;
    }
    v71 = 5;
    v72 = v18;
    v19 = (double)(signed int)outSettings.mFPSLimiter;
    if ( (v75 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v74 + 16i64))(
        v74,
        &v73,
        COERCE_DOUBLE(*(_QWORD *)&v76));
      v74 = 0i64;
    }
    v75 = 5;
    v76 = v19;
    UFG::qString::FormatEx(&v103, v6, v10);
    UFG::qString::FormatEx(&v109, v6, (float)(v10 * 0.5));
    UFG::qString::FormatEx(&v107, v6, (float)(v10 * 0.33333334));
    UFG::qString::FormatEx(&v108, v6, (float)(v10 * 0.25));
    v20 = v103.mData;
    if ( (v79 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v78 + 16i64))(v78, &v77, v80);
      v78 = 0i64;
    }
    v79 = 6;
    v80 = v20;
    v21 = v109.mData;
    if ( (v83 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v82 + 16i64))(v82, &v81, v84);
      v82 = 0i64;
    }
    v83 = 6;
    v84 = v21;
    v22 = v107.mData;
    if ( (v87 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v86 + 16i64))(v86, &v85, v88);
      v86 = 0i64;
    }
    v87 = 6;
    v88 = v22;
    v23 = v108.mData;
    if ( (v91 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v90 + 16i64))(v90, &v89, v92);
      v90 = 0i64;
    }
    v91 = 6;
    v92 = v23;
    if ( (v95 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v94 + 16i64))(v94, &v93, v96);
      v94 = 0i64;
    }
    v95 = 6;
    v96 = Render::gVideoCardDesc;
    v24 = (double)(Render::gVideoMemory >> 20);
    if ( (v99 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v98 + 16i64))(
        v98,
        &v97,
        COERCE_DOUBLE(*(_QWORD *)&v100));
      v98 = 0i64;
    }
    v99 = 5;
    v100 = v24;
    Scaleform::GFx::Movie::Invoke(v5, "SetBenchmarkValues", 0i64, (Scaleform::GFx::Value *)&ptr, 0x13u);
    if ( gAutoBenchmarkMode )
      gGameQuitEvent = 1;
    UFG::qString::~qString(&v108);
    UFG::qString::~qString(&v107);
    UFG::qString::~qString(&v109);
    UFG::qString::~qString(&v103);
    `eh vector destructor iterator(&ptr, 0x30ui64, 19, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    UFG::qString::~qString(&v106);
    UFG::qString::~qString(&v104);
    UFG::qString::~qString(&v105);
  }
}

// File Line: 137
// RVA: 0xA40EA0
bool __fastcall UFG::UIHKScreenPCBenchmark::handleMessage(UFG::UIHKScreenPCBenchmark *this, unsigned int msgId, UFG::UIMessage *msg)
{
  Scaleform::GFx::Movie *v3; // rdi
  const char *v5; // rdx

  v3 = this->mRenderable->m_movie.pObject;
  if ( msgId == UI_HASH_BUTTON_BACK_PRESSED_43 )
  {
    UFG::UIScreenManagerBase::queuePopScreen(
      (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
      0xFFFFFFFF);
    UFG::UI::QuitGame(0i64);
    return 1;
  }
  if ( msgId == UI_HASH_DPAD_DOWN_PRESSED_43
    || msgId == UI_HASH_DPAD_DOWN_REPEAT_43
    || msgId == UI_HASH_THUMBSTICK_LEFT_DOWN_43 )
  {
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        0xEDB4A8C7,
        0i64,
        0,
        0i64);
    if ( !v3 )
      return 1;
    v5 = "ScrollDown";
    goto LABEL_18;
  }
  if ( msgId != UI_HASH_DPAD_UP_PRESSED_43
    && msgId != UI_HASH_DPAD_UP_REPEAT_43
    && msgId != UI_HASH_THUMBSTICK_LEFT_UP_43 )
  {
    return UFG::UIScreen::handleMessage((UFG::UIScreen *)&this->vfptr, msgId, msg);
  }
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(
      (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
      0xEDB4A8C7,
      0i64,
      0,
      0i64);
  if ( v3 )
  {
    v5 = "ScrollUp";
LABEL_18:
    Scaleform::GFx::Movie::Invoke(v3, v5, 0i64, 0i64, 0);
  }
  return 1;
}

