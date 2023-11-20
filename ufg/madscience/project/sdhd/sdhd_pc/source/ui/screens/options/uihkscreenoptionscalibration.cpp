// File Line: 47
// RVA: 0x5C6530
void __fastcall UFG::UIHKScreenOptionsCalibration::UIHKScreenOptionsCalibration(UFG::UIHKScreenOptionsCalibration *this)
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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenOptionsCalibration::`vftable;
  this->m_eState = 0;
}

// File Line: 58
// RVA: 0x633710
void __fastcall UFG::UIHKScreenOptionsCalibration::init(UFG::UIHKScreenOptionsCalibration *this, UFG::UICommandData *data)
{
  UFG::UIHKScreenOptionsCalibration *v2; // rdi
  UFG::UIGfxTranslator *v3; // rsi
  UFG::GameStatTracker *v4; // rax
  UFG::GameStatTracker *v5; // rbx
  Scaleform::GFx::Movie *v6; // rdi
  double v7; // xmm6_8
  double v8; // xmm6_8
  double v9; // xmm6_8
  double v10; // xmm6_8
  double v11; // xmm6_8
  double v12; // xmm6_8
  char ptr; // [rsp+30h] [rbp-D0h]
  __int64 v14; // [rsp+40h] [rbp-C0h]
  unsigned int v15; // [rsp+48h] [rbp-B8h]
  double v16; // [rsp+50h] [rbp-B0h]
  char v17; // [rsp+60h] [rbp-A0h]
  __int64 v18; // [rsp+70h] [rbp-90h]
  unsigned int v19; // [rsp+78h] [rbp-88h]
  double v20; // [rsp+80h] [rbp-80h]
  char v21; // [rsp+90h] [rbp-70h]
  __int64 v22; // [rsp+A0h] [rbp-60h]
  unsigned int v23; // [rsp+A8h] [rbp-58h]
  double v24; // [rsp+B0h] [rbp-50h]
  char v25; // [rsp+C0h] [rbp-40h]
  __int64 v26; // [rsp+D0h] [rbp-30h]
  unsigned int v27; // [rsp+D8h] [rbp-28h]
  double v28; // [rsp+E0h] [rbp-20h]
  char v29; // [rsp+F0h] [rbp-10h]
  __int64 v30; // [rsp+100h] [rbp+0h]
  unsigned int v31; // [rsp+108h] [rbp+8h]
  long double v32; // [rsp+110h] [rbp+10h]
  char v33; // [rsp+120h] [rbp+20h]
  __int64 v34; // [rsp+130h] [rbp+30h]
  unsigned int v35; // [rsp+138h] [rbp+38h]
  double v36; // [rsp+140h] [rbp+40h]
  __int64 v37; // [rsp+150h] [rbp+50h]

  v37 = -2i64;
  v2 = this;
  UFG::UIScreen::init((UFG::UIScreen *)&this->vfptr, data);
  UFG::UIHKScreenOptionsCalibration::SetState(v2, 0);
  v3 = UFG::UIScreenManager::s_instance->m_translator;
  v4 = UFG::GameStatTracker::Instance();
  v5 = v4;
  if ( v3->mLanguage != 7 )
    UFG::GameStatTracker::SetStat(v4, Subtitles, 2);
  v6 = v2->mRenderable->m_movie.pObject;
  `eh vector constructor iterator(&ptr, 0x30ui64, 6, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  v7 = (double)(signed int)UFG::GameStatTracker::GetStat(v5, VolumeSFX);
  if ( (v15 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v14 + 16i64))(
      v14,
      &ptr,
      COERCE_DOUBLE(*(_QWORD *)&v16));
    v14 = 0i64;
  }
  v15 = 5;
  v16 = v7;
  v8 = (double)(signed int)UFG::GameStatTracker::GetStat(v5, VolumeMusic);
  if ( (v19 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v18 + 16i64))(
      v18,
      &v17,
      COERCE_DOUBLE(*(_QWORD *)&v20));
    v18 = 0i64;
  }
  v19 = 5;
  v20 = v8;
  v9 = (double)(signed int)UFG::GameStatTracker::GetStat(v5, VolumeDialogue);
  if ( (v23 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v22 + 16i64))(
      v22,
      &v21,
      COERCE_DOUBLE(*(_QWORD *)&v24));
    v22 = 0i64;
  }
  v23 = 5;
  v24 = v9;
  v10 = (double)(signed int)UFG::GameStatTracker::GetStat(v5, VolumeCarMusic);
  if ( (v27 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v26 + 16i64))(
      v26,
      &v25,
      COERCE_DOUBLE(*(_QWORD *)&v28));
    v26 = 0i64;
  }
  v27 = 5;
  v28 = v10;
  if ( v3->mLanguage == 7 )
  {
    v11 = (double)(signed int)UFG::GameStatTracker::GetStat(v5, Subtitles);
    if ( (v31 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, long double))(*(_QWORD *)v30 + 16i64))(
        v30,
        &v29,
        COERCE_LONG_DOUBLE(*(_QWORD *)&v32));
      v30 = 0i64;
    }
    v32 = v11;
  }
  else
  {
    if ( (v31 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, long double))(*(_QWORD *)v30 + 16i64))(
        v30,
        &v29,
        COERCE_LONG_DOUBLE(*(_QWORD *)&v32));
      v30 = 0i64;
    }
    v32 = DOUBLE_2_0;
  }
  v31 = 5;
  v12 = (double)(signed int)UFG::GameStatTracker::GetStat(v5, UIScale);
  if ( (v35 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v34 + 16i64))(
      v34,
      &v33,
      COERCE_DOUBLE(*(_QWORD *)&v36));
    v34 = 0i64;
  }
  v35 = 5;
  v36 = v12;
  Scaleform::GFx::Movie::Invoke(v6, "OptionList_PopulateCalibration", 0i64, (Scaleform::GFx::Value *)&ptr, 6u);
  `eh vector destructor iterator(&ptr, 0x30ui64, 6, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 107
// RVA: 0x626AD0
bool __fastcall UFG::UIHKScreenOptionsCalibration::handleMessage(UFG::UIHKScreenOptionsCalibration *this, unsigned int msgId, UFG::UIMessage *msg)
{
  UFG::UIMessage *v3; // rsi
  unsigned int v4; // ebx
  UFG::UIHKScreenOptionsCalibration *v5; // rdi
  Scaleform::GFx::Movie *v6; // rbp
  int v7; // ebx
  UFG::GameStatTracker *v8; // rax
  int v9; // ebx
  UFG::GameStatTracker *v10; // rax
  int v11; // ebx
  UFG::GameStatTracker *v12; // rax
  UFG::TiDo *v13; // rdi
  unsigned int v14; // eax
  int v15; // ebx
  UFG::GameStatTracker *v16; // rax
  UFG::TiDo *v17; // rdi
  unsigned int v18; // eax
  int v19; // ebx
  UFG::GameStatTracker *v20; // rax
  UFG::TiDo *v21; // rdi
  unsigned int v22; // eax
  int v23; // ebx
  UFG::GameStatTracker *v24; // rax
  UFG::TiDo *v25; // rdi
  unsigned int v26; // eax
  int v27; // ebx
  UFG::GameStatTracker *v28; // rax
  UFG::UIHKScreenOptionsCalibration::eCalibrationState v29; // edx
  UFG::UIHKScreenOptionsCalibration::eCalibrationState v30; // edx
  const char *v32; // rdx
  UFG::qString v33; // [rsp+38h] [rbp-40h]

  v3 = msg;
  v4 = msgId;
  v5 = this;
  v6 = this->mRenderable->m_movie.pObject;
  if ( msgId == UI_HASH_OPTION_INTRO_COMPLETE_20 )
    return 1;
  if ( msgId == UI_HASH_OPTIONS_BRIGHTNESS_20 )
  {
    UFG::qString::qString(&v33, (UFG::qString *)&msg[1]);
    v7 = UFG::qToInt32(v33.mData, 0);
    v8 = UFG::GameStatTracker::Instance();
    UFG::GameStatTracker::SetStat(v8, Gamma, v7);
    UFG::qString::~qString(&v33);
    return 1;
  }
  if ( msgId == UI_HASH_OPTIONS_SCALE_20 )
  {
    UFG::qString::qString(&v33, (UFG::qString *)&msg[1]);
    v9 = UFG::qToInt32(v33.mData, 0);
    UFG::gUIViewportScale = (float)((float)((float)v9 * 0.1) * 0.15000001) + 0.85000002;
    v10 = UFG::GameStatTracker::Instance();
    UFG::GameStatTracker::SetStat(v10, UIScale, v9);
    UFG::qString::~qString(&v33);
    return 1;
  }
  if ( msgId == UI_HASH_OPTIONS_VOLUME_SFX_20 )
  {
    UFG::qString::qString(&v33, (UFG::qString *)&msg[1]);
    v11 = UFG::qToInt32(v33.mData, 0);
    v12 = UFG::GameStatTracker::Instance();
    UFG::GameStatTracker::SetStat(v12, VolumeSFX, v11);
    v13 = UFG::TiDo::m_pInstance;
    v14 = UFG::TiDo::CalcWwiseUid("master_sfx_volume");
    UFG::TiDo::SetWwiseRtpcValue(v13, v14, (float)v11, 0xFFFFFFFFFFFFFFFFui64);
    UFG::qString::~qString(&v33);
    return 1;
  }
  if ( msgId == UI_HASH_OPTIONS_VOLUME_DIALOGUE_20 )
  {
    UFG::qString::qString(&v33, (UFG::qString *)&msg[1]);
    v15 = UFG::qToInt32(v33.mData, 0);
    v16 = UFG::GameStatTracker::Instance();
    UFG::GameStatTracker::SetStat(v16, VolumeDialogue, v15);
    v17 = UFG::TiDo::m_pInstance;
    v18 = UFG::TiDo::CalcWwiseUid("master_dialog_volume");
    UFG::TiDo::SetWwiseRtpcValue(v17, v18, (float)v15, 0xFFFFFFFFFFFFFFFFui64);
    UFG::qString::~qString(&v33);
    return 1;
  }
  if ( msgId == UI_HASH_OPTIONS_VOLUME_MUSIC_20 )
  {
    UFG::qString::qString(&v33, (UFG::qString *)&msg[1]);
    v19 = UFG::qToInt32(v33.mData, 0);
    v20 = UFG::GameStatTracker::Instance();
    UFG::GameStatTracker::SetStat(v20, VolumeMusic, v19);
    v21 = UFG::TiDo::m_pInstance;
    v22 = UFG::TiDo::CalcWwiseUid("master_music_volume");
    UFG::TiDo::SetWwiseRtpcValue(v21, v22, (float)v19, 0xFFFFFFFFFFFFFFFFui64);
    UFG::qString::~qString(&v33);
    return 1;
  }
  if ( msgId == UI_HASH_OPTIONS_VOLUME_CAR_MUSIC_20 )
  {
    UFG::qString::qString(&v33, (UFG::qString *)&msg[1]);
    v23 = UFG::qToInt32(v33.mData, 0);
    v24 = UFG::GameStatTracker::Instance();
    UFG::GameStatTracker::SetStat(v24, VolumeCarMusic, v23);
    v25 = UFG::TiDo::m_pInstance;
    v26 = UFG::TiDo::CalcWwiseUid("master_radio_volume");
    UFG::TiDo::SetWwiseRtpcValue(v25, v26, (float)v23, 0xFFFFFFFFFFFFFFFFui64);
    UFG::qString::~qString(&v33);
    return 1;
  }
  if ( msgId == UI_HASH_OPTIONS_SUBTITLES_20 )
  {
    v27 = UFG::UI::GetFlashArgsInt(msg);
    v28 = UFG::GameStatTracker::Instance();
    UFG::GameStatTracker::SetStat(v28, Subtitles, v27);
    return 1;
  }
  if ( msgId == UI_HASH_DPAD_DOWN_PRESSED_30 || msgId == UI_HASH_THUMBSTICK_LEFT_DOWN_30 )
  {
    if ( this->m_eState != 2 )
      return 1;
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        0xEDB4A8C7,
        0i64,
        0,
        0i64);
    v32 = "Calibration_ScrollDown";
    goto LABEL_55;
  }
  if ( msgId == UI_HASH_DPAD_UP_PRESSED_30 || msgId == UI_HASH_THUMBSTICK_LEFT_UP_30 )
  {
    if ( this->m_eState != 2 )
      return 1;
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        0xEDB4A8C7,
        0i64,
        0,
        0i64);
    v32 = "Calibration_ScrollUp";
LABEL_55:
    Scaleform::GFx::Movie::Invoke(v6, v32, 0i64, 0i64, 0);
    return 1;
  }
  if ( msgId == UI_HASH_DPAD_RIGHT_PRESSED_30
    || msgId == UI_HASH_DPAD_RIGHT_REPEAT_30
    || msgId == UI_HASH_THUMBSTICK_LEFT_RIGHT_30 )
  {
    if ( this->m_eState && UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        0xEDB4A8C7,
        0i64,
        0,
        0i64);
    v32 = "Calibration_GoRight";
    goto LABEL_55;
  }
  if ( msgId == UI_HASH_DPAD_LEFT_PRESSED_30
    || msgId == UI_HASH_DPAD_LEFT_REPEAT_30
    || msgId == UI_HASH_THUMBSTICK_LEFT_LEFT_30 )
  {
    if ( this->m_eState && UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        0xEDB4A8C7,
        0i64,
        0,
        0i64);
    v32 = "Calibration_GoLeft";
    goto LABEL_55;
  }
  if ( msgId == UI_HASH_BUTTON_ACCEPT_PRESSED_30 )
  {
    v29 = this->m_eState;
    if ( (signed int)v29 >= 3 )
    {
      UFG::UIHKScreenOptionsCalibration::Exit(this);
    }
    else
    {
      v30 = v29 + 1;
      this->m_eState = v30;
      UFG::UIHKScreenOptionsCalibration::SetState(this, v30);
    }
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        0x4A3D1F6Cu,
        0i64,
        0,
        0i64);
    return 1;
  }
  if ( msgId == UI_HASH_BUTTON_BACK_PRESSED_30 )
  {
    UFG::UIHKScreenOptionsCalibration::GotoPrevState(this);
    return 1;
  }
  if ( msgId == UI_HASH_MOUSE_MOVE_30 )
  {
    UFG::UIHKScreenOptionsCalibration::Flash_HandleMouseMove(
      this,
      (float)SLODWORD(msg[1].vfptr),
      (float)SHIDWORD(msg[1].vfptr));
  }
  else if ( msgId == UI_HASH_MOUSE_BUTTON_LEFT_PRESSED_30 )
  {
    UFG::UIHKScreenOptionsCalibration::Flash_HandleMouseClick(
      this,
      (float)SLODWORD(msg[1].vfptr),
      (float)SHIDWORD(msg[1].vfptr));
  }
  return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
}

// File Line: 280
// RVA: 0x5EA6A0
void __fastcall UFG::UIHKScreenOptionsCalibration::GotoPrevState(UFG::UIHKScreenOptionsCalibration *this)
{
  UFG::UIHKScreenOptionsCalibration::eCalibrationState v1; // edx
  UFG::UIHKScreenOptionsCalibration::eCalibrationState v2; // edx

  v1 = this->m_eState;
  if ( (signed int)v1 > 0 )
  {
    v2 = v1 - 1;
    this->m_eState = v2;
    UFG::UIHKScreenOptionsCalibration::SetState(this, v2);
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        0xA4E5BFBD,
        0i64,
        0,
        0i64);
  }
}

// File Line: 292
// RVA: 0x609070
void __fastcall UFG::UIHKScreenOptionsCalibration::SetState(UFG::UIHKScreenOptionsCalibration *this, UFG::UIHKScreenOptionsCalibration::eCalibrationState eState)
{
  UFG::UIHKScreenOptionsCalibration *v2; // rbx
  Scaleform::GFx::Movie *v3; // rdi
  double v4; // xmm6_8
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-50h]

  v2 = this;
  this->m_eState = eState;
  v3 = this->mRenderable->m_movie.pObject;
  `eh vector constructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  v4 = (double)(signed int)v2->m_eState;
  if ( ((unsigned int)pargs.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      *(_QWORD *)&pargs.mValue.NValue);
    pargs.pObjectInterface = 0i64;
  }
  pargs.Type = 5;
  pargs.mValue.NValue = v4;
  Scaleform::GFx::Movie::Invoke(v3, "OptionsCalibration_SetState", 0i64, &pargs, 1u);
  `eh vector destructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 304
// RVA: 0x5D78E0
void __fastcall UFG::UIHKScreenOptionsCalibration::Exit(UFG::UIHKScreenOptionsCalibration *this)
{
  UFG::UIHKScreenOptionsCalibration *v1; // rbx
  UFG::UIScreenTextureManager *v2; // rax
  UFG::GameSaveLoad *v3; // rax
  UFG::GameSaveLoad *v4; // rax
  Render::RenderOutputParams outSettings; // [rsp+30h] [rbp-E8h]
  Render::RenderOutputParams v6; // [rsp+A0h] [rbp-78h]

  v1 = this;
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(
      (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
      0xA4E5BFBD,
      0i64,
      0,
      0i64);
  UFG::UIScreenManagerBase::queuePopScreen(
    (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
    v1->mScreenUID);
  v2 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::QueueLoadAndPush(v2, "MainMenu", 0i64);
  v3 = UFG::GameSaveLoad::Instance();
  UFG::GameSaveLoad::ApplyOptions(v3);
  v4 = UFG::GameSaveLoad::Instance();
  UFG::GameSaveLoad::SaveGameOptions(v4);
  UFG::DataSynchronizer::SetOptionsDirty();
  Render::RenderOutputParams::RenderOutputParams(&outSettings);
  Render::GetCurrentDisplaySettings(&outSettings);
  Render::RenderOutputParams::RenderOutputParams(&v6);
  v6 = outSettings;
  UFG::GameStatPCDisplaySettings::SaveToXML(
    (UFG::GameStatPCDisplaySettings *)&v6,
    UFG::GameStatPCDisplaySettings::gDefaultSavePath);
}

// File Line: 328
// RVA: 0x5DB3A0
void __fastcall UFG::UIHKScreenOptionsCalibration::Flash_HandleMouseMove(UFG::UIHKScreenOptionsCalibration *this, float mouseX, float mouseY)
{
  Scaleform::GFx::Movie *v3; // rbx
  char ptr; // [rsp+40h] [rbp-88h]
  __int64 v5; // [rsp+50h] [rbp-78h]
  unsigned int v6; // [rsp+58h] [rbp-70h]
  double v7; // [rsp+60h] [rbp-68h]
  char v8; // [rsp+70h] [rbp-58h]
  __int64 v9; // [rsp+80h] [rbp-48h]
  unsigned int v10; // [rsp+88h] [rbp-40h]
  double v11; // [rsp+90h] [rbp-38h]

  v3 = this->mRenderable->m_movie.pObject;
  if ( v3 )
  {
    `eh vector constructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( (v6 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v5 + 16i64))(v5, &ptr, COERCE_DOUBLE(*(_QWORD *)&v7));
      v5 = 0i64;
    }
    v6 = 5;
    v7 = mouseX;
    if ( (v10 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v9 + 16i64))(v9, &v8, COERCE_DOUBLE(*(_QWORD *)&v11));
      v9 = 0i64;
    }
    v10 = 5;
    v11 = mouseY;
    Scaleform::GFx::Movie::Invoke(v3, "Calibration_HandleMouseMove", 0i64, (Scaleform::GFx::Value *)&ptr, 2u);
    `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 344
// RVA: 0x5DAD50
void __fastcall UFG::UIHKScreenOptionsCalibration::Flash_HandleMouseClick(UFG::UIHKScreenOptionsCalibration *this, float mouseX, float mouseY)
{
  Scaleform::GFx::Movie *v3; // rbx
  char ptr; // [rsp+40h] [rbp-88h]
  __int64 v5; // [rsp+50h] [rbp-78h]
  unsigned int v6; // [rsp+58h] [rbp-70h]
  double v7; // [rsp+60h] [rbp-68h]
  char v8; // [rsp+70h] [rbp-58h]
  __int64 v9; // [rsp+80h] [rbp-48h]
  unsigned int v10; // [rsp+88h] [rbp-40h]
  double v11; // [rsp+90h] [rbp-38h]

  v3 = this->mRenderable->m_movie.pObject;
  if ( v3 )
  {
    `eh vector constructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( (v6 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v5 + 16i64))(v5, &ptr, COERCE_DOUBLE(*(_QWORD *)&v7));
      v5 = 0i64;
    }
    v6 = 5;
    v7 = mouseX;
    if ( (v10 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v9 + 16i64))(v9, &v8, COERCE_DOUBLE(*(_QWORD *)&v11));
      v9 = 0i64;
    }
    v10 = 5;
    v11 = mouseY;
    Scaleform::GFx::Movie::Invoke(v3, "Calibration_HandleMouseClick", 0i64, (Scaleform::GFx::Value *)&ptr, 2u);
    `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

