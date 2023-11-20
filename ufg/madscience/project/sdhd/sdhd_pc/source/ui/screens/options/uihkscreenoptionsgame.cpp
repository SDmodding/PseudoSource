// File Line: 66
// RVA: 0x5C6820
void __fastcall UFG::UIHKScreenOptionsGame::UIHKScreenOptionsGame(UFG::UIHKScreenOptionsGame *this)
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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenOptions::`vftable;
  *(_QWORD *)&this->mState = 0i64;
  this->mOptionChanged = 0;
  *(_QWORD *)&this->mSavingDialogTimer = 0i64;
  this->mHelpBarName = "OPTIONS";
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenOptionsGame::`vftable;
  *(_QWORD *)&this->oldSubtitles = 0i64;
  *(_WORD *)&this->oldInvertY = 0;
  *(_QWORD *)&this->oldAimPitch = 0i64;
  this->oldAimSoftLock = 0;
  *(_QWORD *)&this->oldCameraPitch = 0i64;
  *(_WORD *)&this->oldDisableSocial = 0;
  this->oldGameInput = 0;
  *(_WORD *)&this->oldMouseFreeLook = 0;
  this->oldMouseSensitivity = 0.0;
}

// File Line: 77
// RVA: 0x634570
void __fastcall UFG::UIHKScreenOptionsGame::init(UFG::UIHKScreenOptionsGame *this, UFG::UICommandData *data)
{
  UFG::UIHKScreenOptionsGame *v2; // rdi
  UFG::Controller *v3; // rcx
  Scaleform::GFx::Movie *v4; // rsi
  UFG::GameStatTracker *v5; // rbx
  UFG::GameSaveLoad *v6; // rax
  double v7; // xmm6_8
  double v8; // xmm6_8
  double v9; // xmm6_8
  double v10; // xmm6_8
  double v11; // xmm6_8
  double v12; // xmm6_8
  double v13; // xmm6_8
  double v14; // xmm7_8
  double v15; // xmm7_8
  double v16; // xmm7_8
  double v17; // xmm7_8
  double v18; // xmm7_8
  double v19; // xmm7_8
  double v20; // xmm7_8
  double v21; // xmm7_8
  double v22; // xmm7_8
  double v23; // xmm7_8
  double v24; // xmm6_8
  char ptr; // [rsp+30h] [rbp-C8h]
  __int64 v26; // [rsp+40h] [rbp-B8h]
  unsigned int v27; // [rsp+48h] [rbp-B0h]
  double v28; // [rsp+50h] [rbp-A8h]
  char v29; // [rsp+60h] [rbp-98h]
  __int64 v30; // [rsp+70h] [rbp-88h]
  double v31; // [rsp+78h] [rbp-80h]
  char v32; // [rsp+88h] [rbp-70h]
  __int64 v33; // [rsp+98h] [rbp-60h]
  unsigned int v34; // [rsp+A0h] [rbp-58h]
  double v35; // [rsp+A8h] [rbp-50h]
  char v36; // [rsp+B8h] [rbp-40h]
  __int64 v37; // [rsp+C8h] [rbp-30h]
  unsigned int v38; // [rsp+D0h] [rbp-28h]
  double v39; // [rsp+D8h] [rbp-20h]
  char v40; // [rsp+E8h] [rbp-10h]
  __int64 v41; // [rsp+F8h] [rbp+0h]
  unsigned int v42; // [rsp+100h] [rbp+8h]
  double v43; // [rsp+108h] [rbp+10h]
  char v44; // [rsp+118h] [rbp+20h]
  __int64 v45; // [rsp+128h] [rbp+30h]
  unsigned int v46; // [rsp+130h] [rbp+38h]
  double v47; // [rsp+138h] [rbp+40h]
  char v48; // [rsp+148h] [rbp+50h]
  __int64 v49; // [rsp+158h] [rbp+60h]
  unsigned int v50; // [rsp+160h] [rbp+68h]
  double v51; // [rsp+168h] [rbp+70h]
  char v52; // [rsp+178h] [rbp+80h]
  __int64 v53; // [rsp+188h] [rbp+90h]
  unsigned int v54; // [rsp+190h] [rbp+98h]
  double v55; // [rsp+198h] [rbp+A0h]
  char v56; // [rsp+1A8h] [rbp+B0h]
  __int64 v57; // [rsp+1B8h] [rbp+C0h]
  unsigned int v58; // [rsp+1C0h] [rbp+C8h]
  double v59; // [rsp+1C8h] [rbp+D0h]
  char v60; // [rsp+1D8h] [rbp+E0h]
  __int64 v61; // [rsp+1E8h] [rbp+F0h]
  unsigned int v62; // [rsp+1F0h] [rbp+F8h]
  double v63; // [rsp+1F8h] [rbp+100h]
  char v64; // [rsp+208h] [rbp+110h]
  __int64 v65; // [rsp+218h] [rbp+120h]
  unsigned int v66; // [rsp+220h] [rbp+128h]
  double v67; // [rsp+228h] [rbp+130h]
  char v68; // [rsp+238h] [rbp+140h]
  __int64 v69; // [rsp+248h] [rbp+150h]
  unsigned int v70; // [rsp+250h] [rbp+158h]
  double v71; // [rsp+258h] [rbp+160h]
  char v72; // [rsp+268h] [rbp+170h]
  __int64 v73; // [rsp+278h] [rbp+180h]
  unsigned int v74; // [rsp+280h] [rbp+188h]
  double v75; // [rsp+288h] [rbp+190h]
  char v76; // [rsp+298h] [rbp+1A0h]
  __int64 v77; // [rsp+2A8h] [rbp+1B0h]
  unsigned int v78; // [rsp+2B0h] [rbp+1B8h]
  double v79; // [rsp+2B8h] [rbp+1C0h]
  char v80; // [rsp+2C8h] [rbp+1D0h]
  __int64 v81; // [rsp+2D8h] [rbp+1E0h]
  unsigned int v82; // [rsp+2E0h] [rbp+1E8h]
  double v83; // [rsp+2E8h] [rbp+1F0h]
  char v84; // [rsp+2F8h] [rbp+200h]
  __int64 v85; // [rsp+308h] [rbp+210h]
  unsigned int v86; // [rsp+310h] [rbp+218h]
  double v87; // [rsp+318h] [rbp+220h]
  char v88; // [rsp+328h] [rbp+230h]
  __int64 v89; // [rsp+338h] [rbp+240h]
  unsigned int v90; // [rsp+340h] [rbp+248h]
  double v91; // [rsp+348h] [rbp+250h]
  char v92; // [rsp+358h] [rbp+260h]
  __int64 v93; // [rsp+368h] [rbp+270h]
  unsigned int v94; // [rsp+370h] [rbp+278h]
  double v95; // [rsp+378h] [rbp+280h]
  __int64 v96; // [rsp+388h] [rbp+290h]

  v96 = -2i64;
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
  v2->mState = 1;
  (*((void (__fastcall **)(UFG::UIHKScreenOptionsGame *))&v2->vfptr[1].__vecDelDtor + 1))(v2);
  v4 = v2->mRenderable->m_movie.pObject;
  if ( v4 )
  {
    Scaleform::GFx::Movie::Invoke(v4, "OptionList_EnablePCOptions", 0i64, 0i64, 0);
    v5 = UFG::GameStatTracker::Instance();
    v2->oldSubtitles = UFG::GameStatTracker::GetStat(v5, Subtitles);
    v2->oldVibration = UFG::GameStatTracker::GetStat(v5, Vibration);
    v2->oldGameHints = UFG::GameStatTracker::GetStat(v5, GameHints);
    v2->oldContextHelp = UFG::GameStatTracker::GetStat(v5, ContextHelp);
    v2->oldHud = UFG::GameStatTracker::GetStat(v5, HudEnable);
    v2->oldInvertY = UFG::GameStatTracker::GetStat(v5, YAxisInverted);
    v2->oldInvertX = UFG::GameStatTracker::GetStat(v5, XAxisInverted);
    v2->oldAimPitch = UFG::GameStatTracker::GetStat(v5, AimSpeedPitch);
    v2->oldAimYaw = UFG::GameStatTracker::GetStat(v5, AimSpeedYaw);
    v2->oldAimSoftLock = UFG::GameStatTracker::GetStat(v5, AimSoftLockEnabled);
    v2->oldCameraPitch = UFG::GameStatTracker::GetStat(v5, CameraSpeedPitch);
    v2->oldCameraYaw = UFG::GameStatTracker::GetStat(v5, CameraSpeedYaw);
    v2->oldDisableSocial = UFG::GameStatTracker::GetStat(v5, OptionsDisableSocial);
    v2->oldGPSArrows = UFG::GameStatTracker::GetStat(v5, GPSArrows);
    v6 = UFG::GameSaveLoad::Instance();
    v2->oldGameInput = UFG::GameSaveLoad::GetKeyboardSwapMode(v6);
    v2->oldMouseFreeLook = UFG::GameStatTracker::GetStat(v5, CameraFreeLook);
    v2->oldMouseInputRaw = UFG::GameStatTracker::GetStat(v5, PCMouseInputRaw);
    v2->oldMouseSensitivity = UFG::GameStatTracker::GetStat(v5, PCMouseSensitivity);
    `eh vector constructor iterator(&ptr, 0x30ui64, 18, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    v7 = (double)(v2->oldSubtitles - 1);
    if ( (v27 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v26 + 16i64))(
        v26,
        &ptr,
        COERCE_DOUBLE(*(_QWORD *)&v28));
      v26 = 0i64;
    }
    v27 = 5;
    v28 = v7;
    v8 = (double)(2 - (v2->oldVibration != 0));
    if ( (LODWORD(v31) >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v30 + 16i64))(
        v30,
        &v29,
        COERCE_DOUBLE(*(_QWORD *)&v31));
      v30 = 0i64;
    }
    v31 = v8;
    v9 = (double)(2 - (v2->oldGameHints != 0));
    if ( (v34 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v33 + 16i64))(
        v33,
        &v32,
        COERCE_DOUBLE(*(_QWORD *)&v35));
      v33 = 0i64;
    }
    v34 = 5;
    v35 = v9;
    v10 = (double)(2 - (v2->oldContextHelp != 0));
    if ( (v38 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v37 + 16i64))(
        v37,
        &v36,
        COERCE_DOUBLE(*(_QWORD *)&v39));
      v37 = 0i64;
    }
    v38 = 5;
    v39 = v10;
    v11 = (double)(2 - (v2->oldHud != 0));
    if ( (v42 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v41 + 16i64))(
        v41,
        &v40,
        COERCE_DOUBLE(*(_QWORD *)&v43));
      v41 = 0i64;
    }
    v42 = 5;
    v43 = v11;
    v12 = (double)((v2->oldInvertY != 0) + 1);
    if ( (v46 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v45 + 16i64))(
        v45,
        &v44,
        COERCE_DOUBLE(*(_QWORD *)&v47));
      v45 = 0i64;
    }
    v46 = 5;
    v47 = v12;
    v13 = (double)((v2->oldInvertX != 0) + 1);
    if ( (v50 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v49 + 16i64))(
        v49,
        &v48,
        COERCE_DOUBLE(*(_QWORD *)&v51));
      v49 = 0i64;
    }
    v50 = 5;
    v51 = v13;
    v14 = (float)(v2->oldAimPitch * 10.0);
    if ( (v54 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v53 + 16i64))(
        v53,
        &v52,
        COERCE_DOUBLE(*(_QWORD *)&v55));
      v53 = 0i64;
    }
    v54 = 5;
    v55 = v14;
    v15 = (float)(v2->oldAimYaw * 10.0);
    if ( (v58 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v57 + 16i64))(
        v57,
        &v56,
        COERCE_DOUBLE(*(_QWORD *)&v59));
      v57 = 0i64;
    }
    v58 = 5;
    v59 = v15;
    v16 = (double)(2 - (v2->oldAimSoftLock != 0));
    if ( (v62 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v61 + 16i64))(
        v61,
        &v60,
        COERCE_DOUBLE(*(_QWORD *)&v63));
      v61 = 0i64;
    }
    v62 = 5;
    v63 = v16;
    v17 = (float)(v2->oldCameraPitch * 10.0);
    if ( (v66 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v65 + 16i64))(
        v65,
        &v64,
        COERCE_DOUBLE(*(_QWORD *)&v67));
      v65 = 0i64;
    }
    v66 = 5;
    v67 = v17;
    v18 = (float)(v2->oldCameraYaw * 10.0);
    if ( (v70 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v69 + 16i64))(
        v69,
        &v68,
        COERCE_DOUBLE(*(_QWORD *)&v71));
      v69 = 0i64;
    }
    v70 = 5;
    v71 = v18;
    v19 = (double)(2 - (v2->oldDisableSocial != 0));
    if ( (v74 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v73 + 16i64))(
        v73,
        &v72,
        COERCE_DOUBLE(*(_QWORD *)&v75));
      v73 = 0i64;
    }
    v74 = 5;
    v75 = v19;
    v20 = (double)(2 - (v2->oldGPSArrows != 0));
    if ( (v78 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v77 + 16i64))(
        v77,
        &v76,
        COERCE_DOUBLE(*(_QWORD *)&v79));
      v77 = 0i64;
    }
    v78 = 5;
    v79 = v20;
    v21 = (double)v2->oldGameInput;
    if ( (v82 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v81 + 16i64))(
        v81,
        &v80,
        COERCE_DOUBLE(*(_QWORD *)&v83));
      v81 = 0i64;
    }
    v82 = 5;
    v83 = v21;
    v22 = (double)(2 - (v2->oldMouseFreeLook != 0));
    if ( (v86 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v85 + 16i64))(
        v85,
        &v84,
        COERCE_DOUBLE(*(_QWORD *)&v87));
      v85 = 0i64;
    }
    v86 = 5;
    v87 = v22;
    v23 = (double)(2 - (v2->oldMouseInputRaw != 0));
    if ( (v90 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v89 + 16i64))(
        v89,
        &v88,
        COERCE_DOUBLE(*(_QWORD *)&v91));
      v89 = 0i64;
    }
    v90 = 5;
    v91 = v23;
    v24 = (float)(v2->oldMouseSensitivity * 10.0);
    if ( (v94 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v93 + 16i64))(
        v93,
        &v92,
        COERCE_DOUBLE(*(_QWORD *)&v95));
      v93 = 0i64;
    }
    v94 = 5;
    v95 = v24;
    Scaleform::GFx::Movie::Invoke(v4, "OptionList_SetValues", 0i64, (Scaleform::GFx::Value *)&ptr, 0x12u);
    `eh vector destructor iterator(&ptr, 0x30ui64, 18, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
  (*((void (__fastcall **)(UFG::UIHKScreenOptionsGame *))&v2->vfptr[1].__vecDelDtor + 1))(v2);
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(
      (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
      0x688D286Au,
      0i64,
      0,
      0i64);
}

// File Line: 142
// RVA: 0x6284E0
bool __fastcall UFG::UIHKScreenOptionsGame::handleMessage(UFG::UIHKScreenOptionsGame *this, unsigned int msgId, UFG::UIMessage *msg)
{
  UFG::UIMessage *v3; // rbp
  unsigned int v4; // esi
  UFG::UIHKScreenOptionsGame *v5; // r14
  UFG::GameStatTracker *v6; // rdi
  int v7; // esi
  UFG::GameStatTracker *v8; // rax
  int v10; // ebx
  int v11; // ebx
  UFG::GameSaveLoad *v12; // rax
  unsigned int v13; // eax
  int v14; // eax
  bool v15; // r8
  int v16; // eax
  bool v17; // r8
  int v18; // eax
  bool v19; // r8
  int v20; // eax
  bool v21; // r8
  int v22; // eax
  bool v23; // r8
  signed int v24; // eax
  signed int v25; // eax
  int v26; // eax
  bool v27; // r8
  signed int v28; // eax
  signed int v29; // eax
  int v30; // eax
  bool v31; // r8
  bool v32; // r8
  UFG::GameStat::BoolStat v33; // edx
  int v34; // ebx
  int v35; // eax
  bool v36; // r8
  signed int v37; // eax
  UFG::qString v38; // [rsp+28h] [rbp-40h]
  UFG::OneShotHandle pHandle; // [rsp+88h] [rbp+20h]

  v3 = msg;
  v4 = msgId;
  v5 = this;
  v6 = UFG::GameStatTracker::Instance();
  if ( v4 != UI_HASH_OPTIONS_SUBTITLES_20 )
  {
    if ( v4 == UI_HASH_OPTIONS_VIBRATION_20 )
    {
      v5->mOptionChanged = 1;
      if ( v3 )
      {
        UFG::qString::qString(&v38, (UFG::qString *)&v3[1]);
        v10 = UFG::qToInt32(v38.mData, 0);
        UFG::qString::~qString(&v38);
      }
      else
      {
        v10 = 0;
      }
      v11 = v10 - 1;
      if ( v11 )
      {
        if ( v11 == 1 )
          UFG::GameStatTracker::SetStat(v6, Vibration, 0);
      }
      else
      {
        UFG::GameStatTracker::SetStat(v6, Vibration, 1);
        v12 = UFG::GameSaveLoad::Instance();
        UFG::GameSaveLoad::ApplyRumble(v12);
        pHandle.m_pOneShot = 0i64;
        UFG::OneShotPool::GetOneShotHandle(&pHandle, &UFG::qMatrix44::msIdentity);
        if ( UFG::OneShotHandle::IsValid(&pHandle) )
        {
          v13 = UFG::TiDo::CalcWwiseUid("Play_motion_hit_medium");
          UFG::OneShot::Play(pHandle.m_pOneShot, v13);
        }
        UFG::OneShotHandle::Release(&pHandle);
      }
      return 1;
    }
    if ( v4 == UI_HASH_OPTIONS_GAME_HINTS_20 )
    {
      v5->mOptionChanged = 1;
      v14 = (unsigned __int64)UFG::UI::GetFlashArgsInt(v3) - 1;
      if ( !v14 )
      {
        v15 = 1;
        goto LABEL_22;
      }
      if ( v14 == 1 )
      {
        v15 = 0;
LABEL_22:
        UFG::GameStatTracker::SetStat(v6, GameHints, v15);
        return 1;
      }
      return 1;
    }
    if ( v4 == UI_HASH_OPTIONS_CONTEXT_HELP_20 )
    {
      v5->mOptionChanged = 1;
      v16 = (unsigned __int64)UFG::UI::GetFlashArgsInt(v3) - 1;
      if ( v16 )
      {
        if ( v16 != 1 )
          return 1;
        v17 = 0;
      }
      else
      {
        v17 = 1;
      }
      UFG::GameStatTracker::SetStat(v6, ContextHelp, v17);
      return 1;
    }
    if ( v4 == UI_HASH_OPTIONS_HUD_20 )
    {
      v5->mOptionChanged = 1;
      v18 = (unsigned __int64)UFG::UI::GetFlashArgsInt(v3) - 1;
      if ( v18 )
      {
        if ( v18 != 1 )
          return 1;
        v19 = 0;
      }
      else
      {
        v19 = 1;
      }
      UFG::GameStatTracker::SetStat(v6, HudEnable, v19);
      return 1;
    }
    if ( v4 == UI_HASH_OPTIONS_INVERT_Y_20 )
    {
      v5->mOptionChanged = 1;
      v20 = (unsigned __int64)UFG::UI::GetFlashArgsInt(v3) - 1;
      if ( v20 )
      {
        if ( v20 != 1 )
          return 1;
        v21 = 1;
      }
      else
      {
        v21 = 0;
      }
      UFG::GameStatTracker::SetStat(v6, YAxisInverted, v21);
      return 1;
    }
    if ( v4 == UI_HASH_OPTIONS_INVERT_X_20 )
    {
      v5->mOptionChanged = 1;
      v22 = (unsigned __int64)UFG::UI::GetFlashArgsInt(v3) - 1;
      if ( v22 )
      {
        if ( v22 != 1 )
          return 1;
        v23 = 1;
      }
      else
      {
        v23 = 0;
      }
      UFG::GameStatTracker::SetStat(v6, XAxisInverted, v23);
      return 1;
    }
    if ( v4 == UI_HASH_OPTIONS_AIM_PITCH_20 )
    {
      v5->mOptionChanged = 1;
      v24 = UFG::UI::GetFlashArgsInt(v3);
      UFG::GameStatTracker::SetStat(v6, AimSpeedPitch, (float)v24 * 0.1);
      return 1;
    }
    if ( v4 == UI_HASH_OPTIONS_AIM_YAW_20 )
    {
      v5->mOptionChanged = 1;
      v25 = UFG::UI::GetFlashArgsInt(v3);
      UFG::GameStatTracker::SetStat(v6, AimSpeedYaw, (float)v25 * 0.1);
      return 1;
    }
    if ( v4 == UI_HASH_OPTIONS_AIM_SOFT_LOCK_20 )
    {
      v5->mOptionChanged = 1;
      v26 = (unsigned __int64)UFG::UI::GetFlashArgsInt(v3) - 1;
      if ( v26 )
      {
        if ( v26 != 1 )
          return 1;
        v27 = 0;
      }
      else
      {
        v27 = 1;
      }
      UFG::GameStatTracker::SetStat(v6, AimSoftLockEnabled, v27);
      return 1;
    }
    if ( v4 == UI_HASH_OPTIONS_CAMERA_PITCH_20 )
    {
      v5->mOptionChanged = 1;
      v28 = UFG::UI::GetFlashArgsInt(v3);
      UFG::GameStatTracker::SetStat(v6, CameraSpeedPitch, (float)v28 * 0.1);
      return 1;
    }
    if ( v4 == UI_HASH_OPTIONS_CAMERA_YAW_20 )
    {
      v5->mOptionChanged = 1;
      v29 = UFG::UI::GetFlashArgsInt(v3);
      UFG::GameStatTracker::SetStat(v6, CameraSpeedYaw, (float)v29 * 0.1);
      return 1;
    }
    if ( v4 == UI_HASH_OPTIONS_CAMERA_FREE_LOOK_20 )
    {
      v5->mOptionChanged = 1;
      v30 = (unsigned __int64)UFG::UI::GetFlashArgsInt(v3) - 1;
      if ( v30 )
      {
        if ( v30 != 1 )
          return 1;
        v31 = 0;
      }
      else
      {
        v31 = 1;
      }
      UFG::GameStatTracker::SetStat(v6, CameraFreeLook, v31);
      return 1;
    }
    if ( v4 == UI_HASH_OPTIONS_DISABLE_SOCIAL_20 )
    {
      v5->mOptionChanged = 1;
      v32 = (unsigned int)UFG::UI::GetFlashArgsInt(v3) == 1;
      v33 = 43;
    }
    else
    {
      if ( v4 != UI_HASH_OPTIONS_GPS_ARROWS_20 )
      {
        if ( v4 == UI_HASH_OPTIONS_GAME_INPUT_20 )
        {
          v5->mOptionChanged = 1;
          v34 = UFG::UI::GetFlashArgsInt(v3);
          UFG::GameStatTracker::SetStat(v6, PCKeyboardSwapMode, v34 != 0);
          UFG::GameStatTracker::SetStat(v6, PCKeyboardSwapModeExtended, v34 + 1);
        }
        else
        {
          if ( v4 == UI_HASH_OPTIONS_MOUSE_INPUT_RAW_20 )
          {
            v5->mOptionChanged = 1;
            v35 = (unsigned __int64)UFG::UI::GetFlashArgsInt(v3) - 1;
            if ( v35 )
            {
              if ( v35 != 1 )
                return 1;
              v36 = 0;
            }
            else
            {
              v36 = 1;
            }
            UFG::GameStatTracker::SetStat(v6, PCMouseInputRaw, v36);
            return 1;
          }
          if ( v4 == UI_HASH_OPTIONS_MOUSE_SENSITIVITY_20 )
          {
            v5->mOptionChanged = 1;
            v37 = UFG::UI::GetFlashArgsInt(v3);
            UFG::GameStatTracker::SetStat(v6, PCMouseSensitivity, (float)v37 * 0.1);
            return 1;
          }
        }
        return UFG::UIHKScreenOptions::handleMessage((UFG::UIHKScreenOptions *)&v5->vfptr, v4, v3);
      }
      v5->mOptionChanged = 1;
      v32 = (unsigned int)UFG::UI::GetFlashArgsInt(v3) == 1;
      v33 = 44;
    }
    UFG::GameStatTracker::SetStat(v6, v33, v32);
    return UFG::UIHKScreenOptions::handleMessage((UFG::UIHKScreenOptions *)&v5->vfptr, v4, v3);
  }
  v5->mOptionChanged = 1;
  if ( v3 )
  {
    UFG::qString::qString(&v38, (UFG::qString *)&v3[1]);
    v7 = UFG::qToInt32(v38.mData, 0);
    UFG::qString::~qString(&v38);
  }
  else
  {
    v7 = 0;
  }
  v8 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::SetStat(v8, Subtitles, v7 + 1);
  return 1;
}

// File Line: 395
// RVA: 0x6030F0
void __fastcall UFG::UIHKScreenOptionsGame::RestoreOptions(UFG::UIHKScreenOptionsGame *this)
{
  UFG::UIHKScreenOptionsGame *v1; // rdi
  UFG::GameStatTracker *v2; // rbx

  v1 = this;
  v2 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::SetStat(v2, Subtitles, v1->oldSubtitles);
  UFG::GameStatTracker::SetStat(v2, Vibration, v1->oldVibration);
  UFG::GameStatTracker::SetStat(v2, GameHints, v1->oldGameHints);
  UFG::GameStatTracker::SetStat(v2, ContextHelp, v1->oldContextHelp);
  UFG::GameStatTracker::SetStat(v2, HudEnable, v1->oldHud);
  UFG::GameStatTracker::SetStat(v2, YAxisInverted, v1->oldInvertY);
  UFG::GameStatTracker::SetStat(v2, XAxisInverted, v1->oldInvertX);
  UFG::GameStatTracker::SetStat(v2, AimSpeedPitch, v1->oldAimPitch);
  UFG::GameStatTracker::SetStat(v2, AimSpeedYaw, v1->oldAimYaw);
  UFG::GameStatTracker::SetStat(v2, AimSoftLockEnabled, v1->oldAimSoftLock);
  UFG::GameStatTracker::SetStat(v2, CameraSpeedPitch, v1->oldCameraPitch);
  UFG::GameStatTracker::SetStat(v2, CameraSpeedYaw, v1->oldCameraYaw);
  UFG::GameStatTracker::SetStat(v2, OptionsDisableSocial, v1->oldDisableSocial);
  UFG::GameStatTracker::SetStat(v2, GPSArrows, v1->oldGPSArrows);
  UFG::GameStatTracker::SetStat(v2, PCKeyboardSwapMode, v1->oldGameInput != 0);
  UFG::GameStatTracker::SetStat(v2, PCKeyboardSwapModeExtended, v1->oldGameInput + 1);
  UFG::GameStatTracker::SetStat(v2, CameraFreeLook, v1->oldMouseFreeLook);
  UFG::GameStatTracker::SetStat(v2, PCMouseInputRaw, v1->oldMouseInputRaw);
  UFG::GameStatTracker::SetStat(v2, PCMouseSensitivity, v1->oldMouseSensitivity);
}

