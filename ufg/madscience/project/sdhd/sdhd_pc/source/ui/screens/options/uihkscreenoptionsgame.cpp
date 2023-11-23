// File Line: 66
// RVA: 0x5C6820
void __fastcall UFG::UIHKScreenOptionsGame::UIHKScreenOptionsGame(UFG::UIHKScreenOptionsGame *this)
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
  UFG::Controller *v3; // rcx
  Scaleform::GFx::Movie *pObject; // rsi
  UFG::GameStatTracker *v5; // rbx
  UFG::GameSaveLoad *v6; // rax
  Scaleform::GFx::Value::ValueUnion v7; // xmm6_8
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
  double oldGameInput; // xmm7_8
  double v22; // xmm7_8
  double v23; // xmm7_8
  double v24; // xmm6_8
  Scaleform::GFx::Value ptr; // [rsp+30h] [rbp-C8h] BYREF
  char v26[16]; // [rsp+60h] [rbp-98h] BYREF
  __int64 v27; // [rsp+70h] [rbp-88h]
  double v28; // [rsp+78h] [rbp-80h]
  char v29[16]; // [rsp+88h] [rbp-70h] BYREF
  __int64 v30; // [rsp+98h] [rbp-60h]
  int v31; // [rsp+A0h] [rbp-58h]
  double v32; // [rsp+A8h] [rbp-50h]
  char v33[16]; // [rsp+B8h] [rbp-40h] BYREF
  __int64 v34; // [rsp+C8h] [rbp-30h]
  int v35; // [rsp+D0h] [rbp-28h]
  double v36; // [rsp+D8h] [rbp-20h]
  char v37[16]; // [rsp+E8h] [rbp-10h] BYREF
  __int64 v38; // [rsp+F8h] [rbp+0h]
  int v39; // [rsp+100h] [rbp+8h]
  double v40; // [rsp+108h] [rbp+10h]
  char v41[16]; // [rsp+118h] [rbp+20h] BYREF
  __int64 v42; // [rsp+128h] [rbp+30h]
  int v43; // [rsp+130h] [rbp+38h]
  double v44; // [rsp+138h] [rbp+40h]
  char v45[16]; // [rsp+148h] [rbp+50h] BYREF
  __int64 v46; // [rsp+158h] [rbp+60h]
  int v47; // [rsp+160h] [rbp+68h]
  double v48; // [rsp+168h] [rbp+70h]
  char v49[16]; // [rsp+178h] [rbp+80h] BYREF
  __int64 v50; // [rsp+188h] [rbp+90h]
  int v51; // [rsp+190h] [rbp+98h]
  double v52; // [rsp+198h] [rbp+A0h]
  char v53[16]; // [rsp+1A8h] [rbp+B0h] BYREF
  __int64 v54; // [rsp+1B8h] [rbp+C0h]
  int v55; // [rsp+1C0h] [rbp+C8h]
  double v56; // [rsp+1C8h] [rbp+D0h]
  char v57[16]; // [rsp+1D8h] [rbp+E0h] BYREF
  __int64 v58; // [rsp+1E8h] [rbp+F0h]
  int v59; // [rsp+1F0h] [rbp+F8h]
  double v60; // [rsp+1F8h] [rbp+100h]
  char v61[16]; // [rsp+208h] [rbp+110h] BYREF
  __int64 v62; // [rsp+218h] [rbp+120h]
  int v63; // [rsp+220h] [rbp+128h]
  double v64; // [rsp+228h] [rbp+130h]
  char v65[16]; // [rsp+238h] [rbp+140h] BYREF
  __int64 v66; // [rsp+248h] [rbp+150h]
  int v67; // [rsp+250h] [rbp+158h]
  double v68; // [rsp+258h] [rbp+160h]
  char v69[16]; // [rsp+268h] [rbp+170h] BYREF
  __int64 v70; // [rsp+278h] [rbp+180h]
  int v71; // [rsp+280h] [rbp+188h]
  double v72; // [rsp+288h] [rbp+190h]
  char v73[16]; // [rsp+298h] [rbp+1A0h] BYREF
  __int64 v74; // [rsp+2A8h] [rbp+1B0h]
  int v75; // [rsp+2B0h] [rbp+1B8h]
  double v76; // [rsp+2B8h] [rbp+1C0h]
  char v77[16]; // [rsp+2C8h] [rbp+1D0h] BYREF
  __int64 v78; // [rsp+2D8h] [rbp+1E0h]
  int v79; // [rsp+2E0h] [rbp+1E8h]
  double v80; // [rsp+2E8h] [rbp+1F0h]
  char v81[16]; // [rsp+2F8h] [rbp+200h] BYREF
  __int64 v82; // [rsp+308h] [rbp+210h]
  int v83; // [rsp+310h] [rbp+218h]
  double v84; // [rsp+318h] [rbp+220h]
  char v85[16]; // [rsp+328h] [rbp+230h] BYREF
  __int64 v86; // [rsp+338h] [rbp+240h]
  int v87; // [rsp+340h] [rbp+248h]
  double v88; // [rsp+348h] [rbp+250h]
  char v89[16]; // [rsp+358h] [rbp+260h] BYREF
  __int64 v90; // [rsp+368h] [rbp+270h]
  int v91; // [rsp+370h] [rbp+278h]
  double v92; // [rsp+378h] [rbp+280h]
  __int64 v93; // [rsp+388h] [rbp+290h]

  v93 = -2i64;
  UFG::UIScreen::init(this, data);
  if ( UFG::gInputSystem && UFG::gActiveControllerNum != -1 )
  {
    v3 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum];
    if ( !UFG::UI::gUIInputLocked )
      g_saved_gameplay_controller_mode = v3->m_ActiveMapSet;
    UFG::SetInputMode(IM_UI_ONLY, v3->mControllerIndex);
    ++UFG::UI::gUIInputLocked;
  }
  this->mState = STATE_BRIGHTNESS;
  (*((void (__fastcall **)(UFG::UIHKScreenOptionsGame *))&this->vfptr[1].__vecDelDtor + 1))(this);
  pObject = this->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    Scaleform::GFx::Movie::Invoke(pObject, "OptionList_EnablePCOptions", 0i64, 0i64, 0);
    v5 = UFG::GameStatTracker::Instance();
    this->oldSubtitles = UFG::GameStatTracker::GetStat(v5, Subtitles);
    this->oldVibration = UFG::GameStatTracker::GetStat(v5, Vibration);
    this->oldGameHints = UFG::GameStatTracker::GetStat(v5, GameHints);
    this->oldContextHelp = UFG::GameStatTracker::GetStat(v5, ContextHelp);
    this->oldHud = UFG::GameStatTracker::GetStat(v5, HudEnable);
    this->oldInvertY = UFG::GameStatTracker::GetStat(v5, YAxisInverted);
    this->oldInvertX = UFG::GameStatTracker::GetStat(v5, XAxisInverted);
    this->oldAimPitch = UFG::GameStatTracker::GetStat(v5, AimSpeedPitch);
    this->oldAimYaw = UFG::GameStatTracker::GetStat(v5, AimSpeedYaw);
    this->oldAimSoftLock = UFG::GameStatTracker::GetStat(v5, AimSoftLockEnabled);
    this->oldCameraPitch = UFG::GameStatTracker::GetStat(v5, CameraSpeedPitch);
    this->oldCameraYaw = UFG::GameStatTracker::GetStat(v5, CameraSpeedYaw);
    this->oldDisableSocial = UFG::GameStatTracker::GetStat(v5, OptionsDisableSocial);
    this->oldGPSArrows = UFG::GameStatTracker::GetStat(v5, GPSArrows);
    v6 = UFG::GameSaveLoad::Instance();
    this->oldGameInput = UFG::GameSaveLoad::GetKeyboardSwapMode(v6);
    this->oldMouseFreeLook = UFG::GameStatTracker::GetStat(v5, CameraFreeLook);
    this->oldMouseInputRaw = UFG::GameStatTracker::GetStat(v5, PCMouseInputRaw);
    this->oldMouseSensitivity = UFG::GameStatTracker::GetStat(v5, PCMouseSensitivity);
    `eh vector constructor iterator(&ptr, 0x30ui64, 18, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    v7.NValue = (double)(this->oldSubtitles - 1);
    if ( (ptr.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
        ptr.pObjectInterface,
        &ptr,
        ptr.mValue);
      ptr.pObjectInterface = 0i64;
    }
    ptr.Type = VT_Number;
    ptr.mValue = v7;
    v8 = (double)(2 - this->oldVibration);
    if ( (LOBYTE(v28) & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v27 + 16i64))(
        v27,
        v26,
        COERCE_DOUBLE(*(_QWORD *)&v28));
      v27 = 0i64;
    }
    v28 = v8;
    v9 = (double)(2 - this->oldGameHints);
    if ( (v31 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v30 + 16i64))(
        v30,
        v29,
        COERCE_DOUBLE(*(_QWORD *)&v32));
      v30 = 0i64;
    }
    v31 = 5;
    v32 = v9;
    v10 = (double)(2 - this->oldContextHelp);
    if ( (v35 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v34 + 16i64))(
        v34,
        v33,
        COERCE_DOUBLE(*(_QWORD *)&v36));
      v34 = 0i64;
    }
    v35 = 5;
    v36 = v10;
    v11 = (double)(2 - this->oldHud);
    if ( (v39 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v38 + 16i64))(
        v38,
        v37,
        COERCE_DOUBLE(*(_QWORD *)&v40));
      v38 = 0i64;
    }
    v39 = 5;
    v40 = v11;
    v12 = (double)(this->oldInvertY + 1);
    if ( (v43 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v42 + 16i64))(
        v42,
        v41,
        COERCE_DOUBLE(*(_QWORD *)&v44));
      v42 = 0i64;
    }
    v43 = 5;
    v44 = v12;
    v13 = (double)(this->oldInvertX + 1);
    if ( (v47 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v46 + 16i64))(
        v46,
        v45,
        COERCE_DOUBLE(*(_QWORD *)&v48));
      v46 = 0i64;
    }
    v47 = 5;
    v48 = v13;
    v14 = (float)(this->oldAimPitch * 10.0);
    if ( (v51 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v50 + 16i64))(
        v50,
        v49,
        COERCE_DOUBLE(*(_QWORD *)&v52));
      v50 = 0i64;
    }
    v51 = 5;
    v52 = v14;
    v15 = (float)(this->oldAimYaw * 10.0);
    if ( (v55 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v54 + 16i64))(
        v54,
        v53,
        COERCE_DOUBLE(*(_QWORD *)&v56));
      v54 = 0i64;
    }
    v55 = 5;
    v56 = v15;
    v16 = (double)(2 - this->oldAimSoftLock);
    if ( (v59 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v58 + 16i64))(
        v58,
        v57,
        COERCE_DOUBLE(*(_QWORD *)&v60));
      v58 = 0i64;
    }
    v59 = 5;
    v60 = v16;
    v17 = (float)(this->oldCameraPitch * 10.0);
    if ( (v63 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v62 + 16i64))(
        v62,
        v61,
        COERCE_DOUBLE(*(_QWORD *)&v64));
      v62 = 0i64;
    }
    v63 = 5;
    v64 = v17;
    v18 = (float)(this->oldCameraYaw * 10.0);
    if ( (v67 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v66 + 16i64))(
        v66,
        v65,
        COERCE_DOUBLE(*(_QWORD *)&v68));
      v66 = 0i64;
    }
    v67 = 5;
    v68 = v18;
    v19 = (double)(2 - this->oldDisableSocial);
    if ( (v71 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v70 + 16i64))(
        v70,
        v69,
        COERCE_DOUBLE(*(_QWORD *)&v72));
      v70 = 0i64;
    }
    v71 = 5;
    v72 = v19;
    v20 = (double)(2 - this->oldGPSArrows);
    if ( (v75 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v74 + 16i64))(
        v74,
        v73,
        COERCE_DOUBLE(*(_QWORD *)&v76));
      v74 = 0i64;
    }
    v75 = 5;
    v76 = v20;
    oldGameInput = (double)this->oldGameInput;
    if ( (v79 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v78 + 16i64))(
        v78,
        v77,
        COERCE_DOUBLE(*(_QWORD *)&v80));
      v78 = 0i64;
    }
    v79 = 5;
    v80 = oldGameInput;
    v22 = (double)(2 - this->oldMouseFreeLook);
    if ( (v83 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v82 + 16i64))(
        v82,
        v81,
        COERCE_DOUBLE(*(_QWORD *)&v84));
      v82 = 0i64;
    }
    v83 = 5;
    v84 = v22;
    v23 = (double)(2 - this->oldMouseInputRaw);
    if ( (v87 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v86 + 16i64))(
        v86,
        v85,
        COERCE_DOUBLE(*(_QWORD *)&v88));
      v86 = 0i64;
    }
    v87 = 5;
    v88 = v23;
    v24 = (float)(this->oldMouseSensitivity * 10.0);
    if ( (v91 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v90 + 16i64))(
        v90,
        v89,
        COERCE_DOUBLE(*(_QWORD *)&v92));
      v90 = 0i64;
    }
    v91 = 5;
    v92 = v24;
    Scaleform::GFx::Movie::Invoke(pObject, "OptionList_SetValues", 0i64, &ptr, 0x12u);
    `eh vector destructor iterator(&ptr, 0x30ui64, 18, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
  (*((void (__fastcall **)(UFG::UIHKScreenOptionsGame *))&this->vfptr[1].__vecDelDtor + 1))(this);
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x688D286Au, 0i64, 0, 0i64);
}

// File Line: 142
// RVA: 0x6284E0
bool __fastcall UFG::UIHKScreenOptionsGame::handleMessage(
        UFG::UIHKScreenOptionsGame *this,
        unsigned int msgId,
        UFG::UIMessage *msg)
{
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
  int FlashArgsInt; // eax
  int v25; // eax
  int v26; // eax
  bool v27; // r8
  int v28; // eax
  int v29; // eax
  int v30; // eax
  bool v31; // r8
  bool v32; // r8
  UFG::GameStat::BoolStat v33; // edx
  int v34; // ebx
  int v35; // eax
  bool v36; // r8
  int v37; // eax
  UFG::qString v38; // [rsp+28h] [rbp-40h] BYREF
  UFG::OneShotHandle pHandle; // [rsp+88h] [rbp+20h] BYREF

  v6 = UFG::GameStatTracker::Instance();
  if ( msgId != UI_HASH_OPTIONS_SUBTITLES_20 )
  {
    if ( msgId == UI_HASH_OPTIONS_VIBRATION_20 )
    {
      this->mOptionChanged = 1;
      if ( msg )
      {
        UFG::qString::qString(&v38, (UFG::qString *)&msg[1]);
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
    if ( msgId == UI_HASH_OPTIONS_GAME_HINTS_20 )
    {
      this->mOptionChanged = 1;
      v14 = UFG::UI::GetFlashArgsInt(msg) - 1;
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
    if ( msgId == UI_HASH_OPTIONS_CONTEXT_HELP_20 )
    {
      this->mOptionChanged = 1;
      v16 = UFG::UI::GetFlashArgsInt(msg) - 1;
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
    if ( msgId == UI_HASH_OPTIONS_HUD_20 )
    {
      this->mOptionChanged = 1;
      v18 = UFG::UI::GetFlashArgsInt(msg) - 1;
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
    if ( msgId == UI_HASH_OPTIONS_INVERT_Y_20 )
    {
      this->mOptionChanged = 1;
      v20 = UFG::UI::GetFlashArgsInt(msg) - 1;
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
    if ( msgId == UI_HASH_OPTIONS_INVERT_X_20 )
    {
      this->mOptionChanged = 1;
      v22 = UFG::UI::GetFlashArgsInt(msg) - 1;
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
    if ( msgId == UI_HASH_OPTIONS_AIM_PITCH_20 )
    {
      this->mOptionChanged = 1;
      FlashArgsInt = UFG::UI::GetFlashArgsInt(msg);
      UFG::GameStatTracker::SetStat(v6, AimSpeedPitch, (float)FlashArgsInt * 0.1);
      return 1;
    }
    if ( msgId == UI_HASH_OPTIONS_AIM_YAW_20 )
    {
      this->mOptionChanged = 1;
      v25 = UFG::UI::GetFlashArgsInt(msg);
      UFG::GameStatTracker::SetStat(v6, AimSpeedYaw, (float)v25 * 0.1);
      return 1;
    }
    if ( msgId == UI_HASH_OPTIONS_AIM_SOFT_LOCK_20 )
    {
      this->mOptionChanged = 1;
      v26 = UFG::UI::GetFlashArgsInt(msg) - 1;
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
    if ( msgId == UI_HASH_OPTIONS_CAMERA_PITCH_20 )
    {
      this->mOptionChanged = 1;
      v28 = UFG::UI::GetFlashArgsInt(msg);
      UFG::GameStatTracker::SetStat(v6, CameraSpeedPitch, (float)v28 * 0.1);
      return 1;
    }
    if ( msgId == UI_HASH_OPTIONS_CAMERA_YAW_20 )
    {
      this->mOptionChanged = 1;
      v29 = UFG::UI::GetFlashArgsInt(msg);
      UFG::GameStatTracker::SetStat(v6, CameraSpeedYaw, (float)v29 * 0.1);
      return 1;
    }
    if ( msgId == UI_HASH_OPTIONS_CAMERA_FREE_LOOK_20 )
    {
      this->mOptionChanged = 1;
      v30 = UFG::UI::GetFlashArgsInt(msg) - 1;
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
    if ( msgId == UI_HASH_OPTIONS_DISABLE_SOCIAL_20 )
    {
      this->mOptionChanged = 1;
      v32 = (unsigned int)UFG::UI::GetFlashArgsInt(msg) == 1;
      v33 = OptionsDisableSocial;
    }
    else
    {
      if ( msgId != UI_HASH_OPTIONS_GPS_ARROWS_20 )
      {
        if ( msgId == UI_HASH_OPTIONS_GAME_INPUT_20 )
        {
          this->mOptionChanged = 1;
          v34 = UFG::UI::GetFlashArgsInt(msg);
          UFG::GameStatTracker::SetStat(v6, PCKeyboardSwapMode, v34 != 0);
          UFG::GameStatTracker::SetStat(v6, PCKeyboardSwapModeExtended, v34 + 1);
        }
        else
        {
          if ( msgId == UI_HASH_OPTIONS_MOUSE_INPUT_RAW_20 )
          {
            this->mOptionChanged = 1;
            v35 = UFG::UI::GetFlashArgsInt(msg) - 1;
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
          if ( msgId == UI_HASH_OPTIONS_MOUSE_SENSITIVITY_20 )
          {
            this->mOptionChanged = 1;
            v37 = UFG::UI::GetFlashArgsInt(msg);
            UFG::GameStatTracker::SetStat(v6, PCMouseSensitivity, (float)v37 * 0.1);
            return 1;
          }
        }
        return UFG::UIHKScreenOptions::handleMessage(this, msgId, msg);
      }
      this->mOptionChanged = 1;
      v32 = (unsigned int)UFG::UI::GetFlashArgsInt(msg) == 1;
      v33 = GPSArrows;
    }
    UFG::GameStatTracker::SetStat(v6, v33, v32);
    return UFG::UIHKScreenOptions::handleMessage(this, msgId, msg);
  }
  this->mOptionChanged = 1;
  if ( msg )
  {
    UFG::qString::qString(&v38, (UFG::qString *)&msg[1]);
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
  UFG::GameStatTracker *v2; // rbx

  v2 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::SetStat(v2, Subtitles, this->oldSubtitles);
  UFG::GameStatTracker::SetStat(v2, Vibration, this->oldVibration);
  UFG::GameStatTracker::SetStat(v2, GameHints, this->oldGameHints);
  UFG::GameStatTracker::SetStat(v2, ContextHelp, this->oldContextHelp);
  UFG::GameStatTracker::SetStat(v2, HudEnable, this->oldHud);
  UFG::GameStatTracker::SetStat(v2, YAxisInverted, this->oldInvertY);
  UFG::GameStatTracker::SetStat(v2, XAxisInverted, this->oldInvertX);
  UFG::GameStatTracker::SetStat(v2, AimSpeedPitch, this->oldAimPitch);
  UFG::GameStatTracker::SetStat(v2, AimSpeedYaw, this->oldAimYaw);
  UFG::GameStatTracker::SetStat(v2, AimSoftLockEnabled, this->oldAimSoftLock);
  UFG::GameStatTracker::SetStat(v2, CameraSpeedPitch, this->oldCameraPitch);
  UFG::GameStatTracker::SetStat(v2, CameraSpeedYaw, this->oldCameraYaw);
  UFG::GameStatTracker::SetStat(v2, OptionsDisableSocial, this->oldDisableSocial);
  UFG::GameStatTracker::SetStat(v2, GPSArrows, this->oldGPSArrows);
  UFG::GameStatTracker::SetStat(v2, PCKeyboardSwapMode, this->oldGameInput != 0);
  UFG::GameStatTracker::SetStat(v2, PCKeyboardSwapModeExtended, this->oldGameInput + 1);
  UFG::GameStatTracker::SetStat(v2, CameraFreeLook, this->oldMouseFreeLook);
  UFG::GameStatTracker::SetStat(v2, PCMouseInputRaw, this->oldMouseInputRaw);
  UFG::GameStatTracker::SetStat(v2, PCMouseSensitivity, this->oldMouseSensitivity);
}

