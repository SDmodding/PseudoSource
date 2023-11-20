// File Line: 63
// RVA: 0x5C6730
void __fastcall UFG::UIHKScreenOptionsDisplayAdvanced::UIHKScreenOptionsDisplayAdvanced(UFG::UIHKScreenOptionsDisplayAdvanced *this)
{
  UFG::UIHKScreenOptionsDisplayAdvanced *v1; // rbx
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v2; // rax

  v1 = this;
  v2 = (UFG::qNode<UFG::UIScreen,UFG::UIScreen> *)&this->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
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
  --this->mInputEnabled;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenOptions::`vftable';
  *(_QWORD *)&this->mState = 0i64;
  this->mOptionChanged = 0;
  *(_QWORD *)&this->mSavingDialogTimer = 0i64;
  this->mHelpBarName = "OPTIONS";
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenOptionsDisplayAdvanced::`vftable';
  this->mState = 0;
  Render::RenderOutputParams::RenderOutputParams(&this->mOldDisplaySettings);
  Render::RenderOutputParams::RenderOutputParams(&v1->mCurrentDisplaySettings);
  *(_WORD *)&v1->mScreensSwitched = 0;
  v1->mExitTimer = 0.0;
  v1->mDialogUID = -1;
  v1->mHelpBarName = "OPTIONS_ADVANCED";
}

// File Line: 80
// RVA: 0x633C40
void __fastcall UFG::UIHKScreenOptionsDisplayAdvanced::init(UFG::UIHKScreenOptionsDisplayAdvanced *this, UFG::UICommandData *data)
{
  UFG::UIHKScreenOptionsDisplayAdvanced *v2; // rbx
  UFG::Controller *v3; // rcx
  signed int v4; // edi
  Scaleform::GFx::Movie *v5; // r14
  Render::eAAQuality v6; // ecx
  int v7; // ecx
  signed int v8; // esi
  Render::eShadowResolution v9; // ecx
  int v10; // ecx
  double v11; // xmm6_8
  double v12; // xmm6_8
  bool v13; // di
  bool v14; // di
  double v15; // xmm6_8
  double v16; // xmm6_8
  double v17; // xmm6_8
  double v18; // xmm6_8
  float v19; // xmm6_4
  unsigned int v20; // eax
  UFG::UIGfxTranslator *v21; // rcx
  const char *v22; // rdi
  double v23; // xmm7_8
  double v24; // xmm8_8
  double v25; // xmm9_8
  double v26; // xmm6_8
  char *v27; // rdi
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
  bool v39; // bl
  char ptr; // [rsp+30h] [rbp-B8h]
  __int64 v41; // [rsp+40h] [rbp-A8h]
  unsigned int v42; // [rsp+48h] [rbp-A0h]
  double v43; // [rsp+50h] [rbp-98h]
  char v44; // [rsp+78h] [rbp-70h]
  __int64 v45; // [rsp+88h] [rbp-60h]
  unsigned int v46; // [rsp+90h] [rbp-58h]
  double v47; // [rsp+98h] [rbp-50h]
  char v48; // [rsp+A8h] [rbp-40h]
  __int64 v49; // [rsp+B8h] [rbp-30h]
  unsigned int v50; // [rsp+C0h] [rbp-28h]
  double v51; // [rsp+C8h] [rbp-20h]
  char v52; // [rsp+D8h] [rbp-10h]
  __int64 v53; // [rsp+E8h] [rbp+0h]
  unsigned int v54; // [rsp+F0h] [rbp+8h]
  double v55; // [rsp+F8h] [rbp+10h]
  char v56; // [rsp+108h] [rbp+20h]
  __int64 v57; // [rsp+118h] [rbp+30h]
  unsigned int v58; // [rsp+120h] [rbp+38h]
  __int64 v59; // [rsp+128h] [rbp+40h]
  char v60; // [rsp+138h] [rbp+50h]
  __int64 v61; // [rsp+148h] [rbp+60h]
  unsigned int v62; // [rsp+150h] [rbp+68h]
  __int64 v63; // [rsp+158h] [rbp+70h]
  char v64; // [rsp+168h] [rbp+80h]
  __int64 v65; // [rsp+178h] [rbp+90h]
  unsigned int v66; // [rsp+180h] [rbp+98h]
  double v67; // [rsp+188h] [rbp+A0h]
  char v68; // [rsp+198h] [rbp+B0h]
  __int64 v69; // [rsp+1A8h] [rbp+C0h]
  unsigned int v70; // [rsp+1B0h] [rbp+C8h]
  double v71; // [rsp+1B8h] [rbp+D0h]
  char v72; // [rsp+1C8h] [rbp+E0h]
  __int64 v73; // [rsp+1D8h] [rbp+F0h]
  unsigned int v74; // [rsp+1E0h] [rbp+F8h]
  double v75; // [rsp+1E8h] [rbp+100h]
  char v76; // [rsp+1F8h] [rbp+110h]
  __int64 v77; // [rsp+208h] [rbp+120h]
  unsigned int v78; // [rsp+210h] [rbp+128h]
  double v79; // [rsp+218h] [rbp+130h]
  char v80; // [rsp+228h] [rbp+140h]
  __int64 v81; // [rsp+238h] [rbp+150h]
  unsigned int v82; // [rsp+240h] [rbp+158h]
  char *v83; // [rsp+248h] [rbp+160h]
  char v84; // [rsp+258h] [rbp+170h]
  __int64 v85; // [rsp+268h] [rbp+180h]
  unsigned int v86; // [rsp+270h] [rbp+188h]
  char *v87; // [rsp+278h] [rbp+190h]
  char v88; // [rsp+288h] [rbp+1A0h]
  __int64 v89; // [rsp+298h] [rbp+1B0h]
  unsigned int v90; // [rsp+2A0h] [rbp+1B8h]
  char *v91; // [rsp+2A8h] [rbp+1C0h]
  char v92; // [rsp+2B8h] [rbp+1D0h]
  __int64 v93; // [rsp+2C8h] [rbp+1E0h]
  unsigned int v94; // [rsp+2D0h] [rbp+1E8h]
  char *v95; // [rsp+2D8h] [rbp+1F0h]
  char v96; // [rsp+2E8h] [rbp+200h]
  __int64 v97; // [rsp+2F8h] [rbp+210h]
  unsigned int v98; // [rsp+300h] [rbp+218h]
  char *v99; // [rsp+308h] [rbp+220h]
  char v100; // [rsp+318h] [rbp+230h]
  __int64 v101; // [rsp+328h] [rbp+240h]
  unsigned int v102; // [rsp+330h] [rbp+248h]
  char *v103; // [rsp+338h] [rbp+250h]
  char v104; // [rsp+348h] [rbp+260h]
  __int64 v105; // [rsp+358h] [rbp+270h]
  unsigned int v106; // [rsp+360h] [rbp+278h]
  char *v107; // [rsp+368h] [rbp+280h]
  char v108; // [rsp+378h] [rbp+290h]
  __int64 v109; // [rsp+388h] [rbp+2A0h]
  unsigned int v110; // [rsp+390h] [rbp+2A8h]
  char *v111; // [rsp+398h] [rbp+2B0h]
  char v112; // [rsp+3A8h] [rbp+2C0h]
  __int64 v113; // [rsp+3B8h] [rbp+2D0h]
  unsigned int v114; // [rsp+3C0h] [rbp+2D8h]
  double v115; // [rsp+3C8h] [rbp+2E0h]
  char v116; // [rsp+3D8h] [rbp+2F0h]
  __int64 v117; // [rsp+3E8h] [rbp+300h]
  unsigned int v118; // [rsp+3F0h] [rbp+308h]
  __int64 v119; // [rsp+3F8h] [rbp+310h]
  __int64 v120; // [rsp+408h] [rbp+320h]
  UFG::qString v121; // [rsp+410h] [rbp+328h]
  UFG::qString v122; // [rsp+438h] [rbp+350h]
  UFG::qString v123; // [rsp+460h] [rbp+378h]
  UFG::qString v124; // [rsp+488h] [rbp+3A0h]
  UFG::qString v125; // [rsp+4B0h] [rbp+3C8h]
  UFG::qString result; // [rsp+4D8h] [rbp+3F0h]
  UFG::qString v127; // [rsp+500h] [rbp+418h]
  UFG::qString v128; // [rsp+528h] [rbp+440h]

  v120 = -2i64;
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
  v4 = 1;
  v2->mState = 1;
  (*((void (__fastcall **)(UFG::UIHKScreenOptionsDisplayAdvanced *))&v2->vfptr[1].__vecDelDtor + 1))(v2);
  v2->mState = 1;
  UFG::GameStatTracker::Instance();
  Render::GetCurrentDisplaySettings(&v2->mOldDisplaySettings);
  Render::GetCurrentDisplaySettings(&v2->mCurrentDisplaySettings);
  v5 = v2->mRenderable->m_movie.pObject;
  if ( v5 )
  {
    `eh vector constructor iterator'(&ptr, 0x30ui64, 21, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    v6 = v2->mOldDisplaySettings.mAAQuality;
    if ( v6 )
    {
      v7 = v6 - 1;
      if ( !v7 )
      {
        v8 = 2;
        goto LABEL_13;
      }
      if ( v7 == 1 )
      {
        v8 = 3;
LABEL_13:
        if ( (v42 >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v41 + 16i64))(
            v41,
            &ptr,
            COERCE_DOUBLE(*(_QWORD *)&v43));
          v41 = 0i64;
        }
        v42 = 5;
        v43 = (double)v8;
        v9 = v2->mOldDisplaySettings.mShadowRes;
        if ( v9 )
        {
          v10 = v9 - 1;
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
        if ( (v46 >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v45 + 16i64))(
            v45,
            &v44,
            COERCE_DOUBLE(*(_QWORD *)&v47));
          v45 = 0i64;
        }
        v46 = 5;
        v47 = (double)v4;
        v11 = (double)((v2->mOldDisplaySettings.mShadowFilter != 0) + 1);
        if ( (v50 >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v49 + 16i64))(
            v49,
            &v48,
            COERCE_DOUBLE(*(_QWORD *)&v51));
          v49 = 0i64;
        }
        v50 = 5;
        v51 = v11;
        v12 = (double)((v2->mOldDisplaySettings.mSSAO != 0) + 1);
        if ( (v54 >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v53 + 16i64))(
            v53,
            &v52,
            COERCE_DOUBLE(*(_QWORD *)&v55));
          v53 = 0i64;
        }
        v54 = 5;
        v55 = v12;
        v13 = v2->mOldDisplaySettings.mEnableFullscreen;
        if ( (v58 >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v57 + 16i64))(v57, &v56, v59);
          v57 = 0i64;
        }
        v58 = 2;
        LOBYTE(v59) = v13;
        v14 = v2->mOldDisplaySettings.mEnableVSync;
        if ( (v62 >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v61 + 16i64))(v61, &v60, v63);
          v61 = 0i64;
        }
        v62 = 2;
        LOBYTE(v63) = v14;
        v15 = (double)(v2->mOldDisplaySettings.mMotionBlur + 1);
        if ( (v66 >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v65 + 16i64))(
            v65,
            &v64,
            COERCE_DOUBLE(*(_QWORD *)&v67));
          v65 = 0i64;
        }
        v66 = 5;
        v67 = v15;
        v16 = (double)(signed int)v2->mOldDisplaySettings.mFPSLimiter;
        if ( (v70 >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v69 + 16i64))(
            v69,
            &v68,
            COERCE_DOUBLE(*(_QWORD *)&v71));
          v69 = 0i64;
        }
        v70 = 5;
        v71 = v16;
        v17 = (double)v2->mOldDisplaySettings.m3DDepth;
        if ( (v74 >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v73 + 16i64))(
            v73,
            &v72,
            COERCE_DOUBLE(*(_QWORD *)&v75));
          v73 = 0i64;
        }
        v74 = 5;
        v75 = v17;
        v18 = (double)v2->mOldDisplaySettings.m3DConvergence;
        if ( (v78 >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v77 + 16i64))(
            v77,
            &v76,
            COERCE_DOUBLE(*(_QWORD *)&v79));
          v77 = 0i64;
        }
        v78 = 5;
        v79 = v18;
        v19 = (float)(signed int)v2->mOldDisplaySettings.mDisplayMode.mRefreshRateNumerator
            / (float)(signed int)v2->mOldDisplaySettings.mDisplayMode.mRefreshRateDenominator;
        v20 = UFG::qStringHashUpper32("FPS_PARAMETER", 0xFFFFFFFF);
        v21 = UFG::UIScreenManager::s_instance->m_translator;
        if ( !v21
          || (v22 = (const char *)v21->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v21->vfptr, v20)) == 0i64 )
        {
          v22 = "FPS_PARAMETER";
        }
        v23 = v19;
        UFG::qString::FormatEx(&result, v22, v19);
        v24 = (float)(v19 * 0.5);
        UFG::qString::FormatEx(&v124, v22, v24);
        v25 = (float)(v19 * 0.33333334);
        UFG::qString::FormatEx(&v122, v22, v25);
        v26 = (float)(v19 * 0.25);
        UFG::qString::FormatEx(&v125, v22, v26);
        v27 = result.mData;
        if ( (v82 >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v81 + 16i64))(v81, &v80, v83);
          v81 = 0i64;
        }
        v82 = 6;
        v83 = v27;
        v28 = v124.mData;
        if ( (v86 >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v85 + 16i64))(v85, &v84, v87);
          v85 = 0i64;
        }
        v86 = 6;
        v87 = v28;
        v29 = v122.mData;
        if ( (v90 >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v89 + 16i64))(v89, &v88, v91);
          v89 = 0i64;
        }
        v90 = 6;
        v91 = v29;
        v30 = v125.mData;
        if ( (v94 >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v93 + 16i64))(v93, &v92, v95);
          v93 = 0i64;
        }
        v94 = 6;
        v95 = v30;
        v31 = UFG::qStringHashUpper32("FPS_DESCRIPTION", 0xFFFFFFFF);
        v32 = UFG::UIScreenManager::s_instance->m_translator;
        if ( !v32
          || (v33 = (const char *)v32->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v32->vfptr, v31)) == 0i64 )
        {
          v33 = "FPS_DESCRIPTION";
        }
        UFG::qString::FormatEx(&v121, v33, v23);
        UFG::qString::FormatEx(&v123, v33, v24);
        UFG::qString::FormatEx(&v128, v33, v25);
        UFG::qString::FormatEx(&v127, v33, v26);
        v34 = v121.mData;
        if ( (v98 >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v97 + 16i64))(v97, &v96, v99);
          v97 = 0i64;
        }
        v98 = 6;
        v99 = v34;
        v35 = v123.mData;
        if ( (v102 >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v101 + 16i64))(v101, &v100, v103);
          v101 = 0i64;
        }
        v102 = 6;
        v103 = v35;
        v36 = v128.mData;
        if ( (v106 >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v105 + 16i64))(v105, &v104, v107);
          v105 = 0i64;
        }
        v106 = 6;
        v107 = v36;
        v37 = v127.mData;
        if ( (v110 >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v109 + 16i64))(v109, &v108, v111);
          v109 = 0i64;
        }
        v110 = 6;
        v111 = v37;
        v38 = (double)(v2->mOldDisplaySettings.mLODSetting + 1);
        if ( (v114 >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v113 + 16i64))(
            v113,
            &v112,
            COERCE_DOUBLE(*(_QWORD *)&v115));
          v113 = 0i64;
        }
        v114 = 5;
        v115 = v38;
        v39 = v2->mOldDisplaySettings.mEnableLowResBuffer;
        if ( (v118 >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v117 + 16i64))(v117, &v116, v119);
          v117 = 0i64;
        }
        v118 = 2;
        LOBYTE(v119) = v39;
        Scaleform::GFx::Movie::Invoke(v5, "OptionList_SetValues", 0i64, (Scaleform::GFx::Value *)&ptr, 0x15u);
        Scaleform::GFx::Movie::Invoke(v5, "OptionList_PlayIntro", 0i64, 0i64, 0);
        if ( UFG::HudAudio::m_instance )
          UFG::AudioEntity::CreateAndPlayEvent(
            (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
            0x4A3D1F6Cu,
            0i64,
            0,
            0i64);
        UFG::qString::~qString(&v127);
        UFG::qString::~qString(&v128);
        UFG::qString::~qString(&v123);
        UFG::qString::~qString(&v121);
        UFG::qString::~qString(&v125);
        UFG::qString::~qString(&v122);
        UFG::qString::~qString(&v124);
        UFG::qString::~qString(&result);
        `eh vector destructor iterator'(&ptr, 0x30ui64, 21, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
        return;
      }
    }
    v8 = 1;
    goto LABEL_13;
  }
}

// File Line: 154
// RVA: 0x63E6A0
void __fastcall UFG::UIHKScreenOptionsDisplayAdvanced::update(UFG::UIHKScreenOptionsDisplayAdvanced *this, float elapsed)
{
  UFG::UIHKScreenOptionsDisplayAdvanced *v2; // rbx
  float v3; // xmm2_4
  unsigned int v4; // edx

  v2 = this;
  UFG::UIHKScreenOptions::update((UFG::UIHKScreenOptions *)&this->vfptr, elapsed);
  if ( v2->mState == 5 )
  {
    if ( (v3 = v2->mExitTimer - elapsed, v2->mExitTimer = v3, v3 <= 0.0) && !UFG::SectionChooser::AreAnyLoadsPending()
      || v2->mExitTimer < -10.0 )
    {
      v4 = v2->mDialogUID;
      if ( v4 != -1 )
        UFG::UIScreenManagerBase::queuePopScreen(
          (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
          v4);
      if ( !v2->mScreensSwitched )
      {
        UFG::UIScreenManagerBase::queuePopScreen(
          (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
          v2->mScreenUID);
        v2->mScreensSwitched = 1;
      }
    }
  }
}

// File Line: 178
// RVA: 0x628030
bool __fastcall UFG::UIHKScreenOptionsDisplayAdvanced::handleMessage(UFG::UIHKScreenOptionsDisplayAdvanced *this, unsigned int msgId, UFG::UIMessage *msg)
{
  UFG::UIMessage *v3; // rbp
  unsigned int v4; // esi
  UFG::UIHKScreenOptionsDisplayAdvanced *v5; // rdi
  UFG::GameStatTracker *v6; // r15
  int v8; // ebx
  int v9; // er14
  int v10; // er14
  int v11; // er14
  int v12; // eax
  int v13; // eax
  int v14; // eax
  signed int v15; // ebx
  int v16; // eax
  BOOL v17; // ebx
  int v18; // eax
  BOOL v19; // ebx
  bool v20; // bl
  int v21; // eax
  int v22; // ebx
  Render::eFPSLimiter v23; // ebx
  UFG::GameSaveLoad *v24; // rax
  UFG::GameSaveLoad *v25; // rax
  UFG::GameSaveLoad *v26; // rax
  UFG::qString v27; // [rsp+38h] [rbp-40h]

  v3 = msg;
  v4 = msgId;
  v5 = this;
  v6 = UFG::GameStatTracker::Instance();
  if ( v4 == UI_HASH_INTRO_COMPLETE_30 )
    return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
  if ( v4 == UI_HASH_OPTIONS_QUALITY_AA_20 )
  {
    v5->mOptionChanged = 1;
    v5->mExitDelayNeeded = 1;
    v8 = 0;
    if ( v3 )
    {
      UFG::qString::qString(&v27, (UFG::qString *)&v3[1]);
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
    v5->mCurrentDisplaySettings.mAAQuality = v8;
    goto LABEL_56;
  }
  if ( v4 == UI_HASH_OPTIONS_HIGH_RES_TEXTURES_20 )
  {
    v5->mOptionChanged = 1;
    v5->mExitDelayNeeded = 1;
    v12 = UFG::UI::GetFlashArgsInt(v3);
    UFG::GameStatTracker::SetStat(v6, Display_HighResTextures, v12 == 2);
    goto LABEL_56;
  }
  if ( v4 == UI_HASH_OPTIONS_SHADOW_RESOLUTION_20 )
  {
    v5->mOptionChanged = 1;
    v5->mExitDelayNeeded = 1;
    v13 = (unsigned __int64)UFG::UI::GetFlashArgsInt(v3) - 1;
    if ( v13 )
    {
      v14 = v13 - 1;
      if ( !v14 )
      {
        v15 = 1;
        goto LABEL_22;
      }
      if ( v14 == 1 )
      {
        v15 = 2;
LABEL_22:
        UFG::GameStatTracker::SetStat(v6, Display_ShadowResolution, v15 != 0);
        v5->mCurrentDisplaySettings.mShadowRes = v15;
        goto LABEL_56;
      }
    }
    v15 = 0;
    goto LABEL_22;
  }
  if ( v4 == UI_HASH_OPTIONS_SHADOW_FILTERING_20 )
  {
    v5->mOptionChanged = 1;
    v5->mExitDelayNeeded = 1;
    v16 = UFG::UI::GetFlashArgsInt(v3);
    v17 = v16 != 1;
    UFG::GameStatTracker::SetStat(v6, Display_ShadowFiltering, v16 != 1);
    v5->mCurrentDisplaySettings.mShadowFilter = v17;
  }
  else if ( v4 == UI_HASH_OPTIONS_SSAO_20 )
  {
    v5->mOptionChanged = 1;
    v5->mExitDelayNeeded = 1;
    v18 = UFG::UI::GetFlashArgsInt(v3);
    v19 = v18 != 1;
    UFG::GameStatTracker::SetStat(v6, Display_SSAO, v18 != 1);
    v5->mCurrentDisplaySettings.mSSAO = v19;
  }
  else if ( v4 == UI_HASH_OPTIONS_VSYNC_20 )
  {
    v5->mOptionChanged = 1;
    v5->mExitDelayNeeded = 1;
    v20 = (unsigned int)UFG::UI::GetFlashArgsInt(v3) == 2;
    UFG::GameStatTracker::SetStat(v6, Display_EnableVSync, v20);
    v5->mCurrentDisplaySettings.mEnableVSync = v20;
  }
  else if ( v4 == UI_HASH_OPTIONS_QUALITY_MOTION_BLUR_20 )
  {
    v5->mOptionChanged = 1;
    v5->mExitDelayNeeded = 1;
    v21 = UFG::UI::GetFlashArgsInt(v3);
    v22 = v21 - 1;
    UFG::GameStatTracker::SetStat(v6, Display_HighQualityMotionBlur, v21 != 1);
    v5->mCurrentDisplaySettings.mMotionBlur = v22;
  }
  else if ( v4 == UI_HASH_OPTIONS_FPS_LIMITER_20 )
  {
    v5->mOptionChanged = 1;
    v5->mExitDelayNeeded = 1;
    v23 = (unsigned int)UFG::UI::GetFlashArgsInt(v3);
    UFG::GameStatTracker::SetStat(v6, Display_FPSLimiter, v23 != 0);
    v5->mCurrentDisplaySettings.mFPSLimiter = v23;
  }
  else if ( v4 == UI_HASH_OPTIONS_3D_DEPTH_20 )
  {
    v5->mOptionChanged = 1;
    v5->mExitDelayNeeded = 1;
    v5->mCurrentDisplaySettings.m3DDepth = UFG::UI::GetFlashArgsInt(v3);
  }
  else if ( v4 == UI_HASH_OPTIONS_3D_CONVERGENCE_20 )
  {
    v5->mOptionChanged = 1;
    v5->mExitDelayNeeded = 1;
    v5->mCurrentDisplaySettings.m3DConvergence = UFG::UI::GetFlashArgsInt(v3);
  }
  else if ( v4 == UI_HASH_OPTIONS_WORLD_DENSITY_20 )
  {
    v5->mOptionChanged = 1;
    v5->mExitDelayNeeded = 1;
    v5->mCurrentDisplaySettings.mLODSetting = (unsigned __int64)UFG::UI::GetFlashArgsInt(v3) - 1;
  }
  else if ( v4 == UI_HASH_OPTIONS_LOW_RES_BUFFERS_20 )
  {
    v5->mOptionChanged = 1;
    v5->mCurrentDisplaySettings.mEnableLowResBuffer = (unsigned int)UFG::UI::GetFlashArgsInt(v3) == 2;
  }
  else if ( v4 == UI_HASH_OPTION_DISABLED_30 )
  {
    UFG::UIScreenDialogBox::createOKDialog(
      (UFG::UIScreen *)&v5->vfptr,
      &customWorldMapCaption,
      "$UI_OPTION_VSYCN_LOCKED",
      0);
  }
  else
  {
    if ( v4 == UI_HASH_BUTTON_BUTTON1_PRESSED_30 )
    {
      if ( (unsigned int)UFG::FlowController::GetCurrentState(&UFG::gFlowController) == uidGameStateFE_13 )
        UFG::UIHKScreenOptionsDisplayAdvanced::StartBenchmark(v5);
      return 1;
    }
    if ( v4 == (_DWORD)UI_HASH_BUTTON_BUTTON2_PRESSED_30 )
    {
      UFG::UIScreenDialogBox::createYesNoDialog(
        (UFG::UIScreen *)&v5->vfptr,
        "$OPTIONS_OPTIONS_CHANGED",
        "$OPTIONS_SAVE_CHANGES",
        1,
        1);
      v5->mState = 3;
      return 1;
    }
    if ( v4 == UI_HASH_DIALOG_YES_30 )
    {
      if ( v5->mState == 3 )
      {
        v24 = UFG::GameSaveLoad::Instance();
        UFG::GameSaveLoad::ApplyOptions(v24);
        v25 = UFG::GameSaveLoad::Instance();
        UFG::GameSaveLoad::SaveGameOptions(v25);
        UFG::DataSynchronizer::SetOptionsDirty();
        ((void (__fastcall *)(UFG::UIHKScreenOptionsDisplayAdvanced *))v5->vfptr[1].update)(v5);
        v5->mOptionChanged = 0;
        goto LABEL_52;
      }
    }
    else if ( v4 == UI_HASH_DIALOG_NO_30 && v5->mState == 3 )
    {
      ((void (__fastcall *)(UFG::UIHKScreenOptionsDisplayAdvanced *))v5->vfptr[1].handleMessage)(v5);
      v26 = UFG::GameSaveLoad::Instance();
      UFG::GameSaveLoad::ApplyOptions(v26);
      v5->mState = 1;
      return 1;
    }
  }
LABEL_56:
  if ( v5->mState != 1 )
  {
    if ( v5->mState != 2 )
    {
      if ( v5->mState == 4 && v4 == UI_HASH_DIALOG_OK_30 )
      {
        v5->mState = 1;
        return 1;
      }
      return 0;
    }
    if ( v4 != UI_HASH_DIALOG_OK_30 )
      return 0;
LABEL_52:
    v5->mState = 1;
    return 1;
  }
  return UFG::UIHKScreenOptions::handleMessage((UFG::UIHKScreenOptions *)&v5->vfptr, v4, v3);
}

// File Line: 375
// RVA: 0x5D3C50
void __fastcall UFG::UIHKScreenOptionsDisplayAdvanced::ApplyOptions(UFG::UIHKScreenOptionsDisplayAdvanced *this)
{
  Render::RenderOutputParams *v1; // rdi
  UFG::UIHKScreenOptionsDisplayAdvanced *v2; // rbx
  __int128 v3; // xmm1
  __int128 v4; // xmm1
  __int128 v5; // xmm1
  Render::RenderOutputParams v6; // [rsp+20h] [rbp-78h]

  v1 = &this->mCurrentDisplaySettings;
  v2 = this;
  Render::RenderOutputParams::ChangeGlobalSetting(&this->mCurrentDisplaySettings, 0);
  if ( UFG::UIHKScreenOptionsDisplayAdvanced::ApplyRenderOptions(v2, v1) )
  {
    Render::RenderOutputParams::RenderOutputParams(&v6);
    v3 = *(_OWORD *)&v1->mDisplayMode.mAdapterUID;
    *(_OWORD *)&v6.mDisplayMode.mBackBufferWidth = *(_OWORD *)&v1->mDisplayMode.mBackBufferWidth;
    *(_OWORD *)&v6.mDisplayMode.mAdapterUID = v3;
    v4 = *(_OWORD *)&v1->mShadowFilter;
    *(_OWORD *)&v6.mEnableFullscreen = *(_OWORD *)&v1->mEnableFullscreen;
    *(_OWORD *)&v6.mShadowFilter = v4;
    v5 = *(_OWORD *)&v1->mLODSetting;
    *(_OWORD *)&v6.mFPSLimiter = *(_OWORD *)&v1->mFPSLimiter;
    *(_OWORD *)&v6.mLODSetting = v5;
    *(_QWORD *)&v6.mTextureFilterQuality = *(_QWORD *)&v1->mTextureFilterQuality;
    UFG::GameStatPCDisplaySettings::SaveToXML(
      (UFG::GameStatPCDisplaySettings *)&v6,
      UFG::GameStatPCDisplaySettings::gDefaultSavePath);
  }
}

// File Line: 402
// RVA: 0x5D3E10
char __fastcall UFG::UIHKScreenOptionsDisplayAdvanced::ApplyRenderOptions(UFG::UIHKScreenOptionsDisplayAdvanced *this, Render::RenderOutputParams *settings)
{
  UFG::UIHKScreenOptionsDisplayAdvanced *v2; // rdi
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

// File Line: 427
// RVA: 0x5D7A40
void __fastcall UFG::UIHKScreenOptionsDisplayAdvanced::Exit(UFG::UIHKScreenOptionsDisplayAdvanced *this)
{
  UFG::UIHKScreenOptionsDisplayAdvanced *v1; // rbx
  bool v2; // zf

  v1 = this;
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(
      (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
      0xA4E5BFBD,
      0i64,
      0,
      0i64);
  v2 = v1->mExitDelayNeeded == 0;
  v1->mState = 5;
  if ( v2 )
  {
    v1->mExitTimer = 0.0;
  }
  else
  {
    v1->mExitTimer = 3.0;
    v1->mDialogUID = UFG::UIScreenDialogBox::createZeroButtonDialog(
                       (UFG::UIScreen *)&v1->vfptr,
                       &customWorldMapCaption,
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
  UFG::GameState *v3; // rax

  UFG::FlowController::GetCurrentState(&UFG::gFlowController);
  UFG::UIScreenManagerBase::queuePopScreen(
    (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
    0xFFFFFFFF);
  UFG::UIScreenManagerBase::queuePopScreen(
    (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
    0xFFFFFFFF);
  UFG::UI::UnpauseGame(v1);
  v2 = uidGameStateLoadGame_13;
  if ( !(unsigned int)UFG::FlowController::RequestSetNewState(&UFG::gFlowController, uidGameStateLoadGame_13) )
  {
    UFG::qStringCopy(gameSetup, 100, "gameSetupGame_Calibration", -1);
    v3 = UFG::FlowController::GetGameStateObj(&UFG::gFlowController, v2);
    if ( v3 )
      UFG::qString::Set(&v3->mGameStateUserDataStr, gameSetup);
  }
}

// File Line: 532
// RVA: 0x60EFA0
void __fastcall UFG::UIHKScreenOptionsDisplayAdvanced::ShowHelpBar(UFG::UIHKScreenOptionsDisplayAdvanced *this)
{
  UFG::UIHKScreenOptionsDisplayAdvanced *v1; // rbx
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
  __int64 v15; // rdi
  __int64 v16; // rbx
  UFG::UIHKScreenGlobalOverlay *v17; // rax
  UFG::UIHKHelpBarData data; // [rsp+30h] [rbp-258h]

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
  UFG::qString::Set(&data.Icons[v7], &customWorldMapCaption);
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
    data.Buttons[v11] = 3;
    v12 = v9;
    UFG::qString::Set(&data.Captions[v12], "$OPTIONS_BENCHMARK_MODE");
    UFG::qString::Set(&data.Icons[v12], &customWorldMapCaption);
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
  v15 = v2;
  data.Buttons[v15] = 4;
  v16 = v2;
  UFG::qString::Set(&data.Captions[v16], "$OPTIONS_SAVE_ADVANCED_DISPLAY");
  UFG::qString::Set(&data.Icons[v16], &customWorldMapCaption);
  data.MessageIds[v15] = v13;
LABEL_17:
  v17 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    v17 = &gGlobalOverlaySentinel;
  UFG::UIHKHelpBarWidget::Show(&v17->HelpBar, &data);
  UFG::qString::~qString(&data.CustomTexturePack);
  `eh vector destructor iterator'(data.Icons, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
  `eh vector destructor iterator'(data.Captions, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
}

