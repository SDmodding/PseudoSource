// File Line: 47
// RVA: 0x5C6530
void __fastcall UFG::UIHKScreenOptionsCalibration::UIHKScreenOptionsCalibration(
        UFG::UIHKScreenOptionsCalibration *this)
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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenOptionsCalibration::`vftable;
  this->m_eState = STATE_INIT;
}

// File Line: 58
// RVA: 0x633710
void __fastcall UFG::UIHKScreenOptionsCalibration::init(
        UFG::UIHKScreenOptionsCalibration *this,
        UFG::UICommandData *data)
{
  UFG::UIGfxTranslator *m_translator; // rsi
  UFG::GameStatTracker *v4; // rax
  UFG::GameStatTracker *v5; // rbx
  Scaleform::GFx::Movie *pObject; // rdi
  Scaleform::GFx::Value::ValueUnion v7; // xmm6_8
  double Stat; // xmm6_8
  double v9; // xmm6_8
  double v10; // xmm6_8
  double v11; // xmm6_8
  double v12; // xmm6_8
  Scaleform::GFx::Value ptr; // [rsp+30h] [rbp-D0h] BYREF
  char v14[16]; // [rsp+60h] [rbp-A0h] BYREF
  __int64 v15; // [rsp+70h] [rbp-90h]
  int v16; // [rsp+78h] [rbp-88h]
  double v17; // [rsp+80h] [rbp-80h]
  char v18[16]; // [rsp+90h] [rbp-70h] BYREF
  __int64 v19; // [rsp+A0h] [rbp-60h]
  int v20; // [rsp+A8h] [rbp-58h]
  double v21; // [rsp+B0h] [rbp-50h]
  char v22[16]; // [rsp+C0h] [rbp-40h] BYREF
  __int64 v23; // [rsp+D0h] [rbp-30h]
  int v24; // [rsp+D8h] [rbp-28h]
  double v25; // [rsp+E0h] [rbp-20h]
  char v26[16]; // [rsp+F0h] [rbp-10h] BYREF
  __int64 v27; // [rsp+100h] [rbp+0h]
  int v28; // [rsp+108h] [rbp+8h]
  long double v29; // [rsp+110h] [rbp+10h]
  char v30[16]; // [rsp+120h] [rbp+20h] BYREF
  __int64 v31; // [rsp+130h] [rbp+30h]
  int v32; // [rsp+138h] [rbp+38h]
  double v33; // [rsp+140h] [rbp+40h]
  __int64 v34; // [rsp+150h] [rbp+50h]

  v34 = -2i64;
  UFG::UIScreen::init(this, data);
  UFG::UIHKScreenOptionsCalibration::SetState(this, STATE_INIT);
  m_translator = UFG::UIScreenManager::s_instance->m_translator;
  v4 = UFG::GameStatTracker::Instance();
  v5 = v4;
  if ( m_translator->mLanguage != eLang_English )
    UFG::GameStatTracker::SetStat(v4, Subtitles, 2);
  pObject = this->mRenderable->m_movie.pObject;
  `eh vector constructor iterator(&ptr, 0x30ui64, 6, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  v7.NValue = (double)(int)UFG::GameStatTracker::GetStat(v5, VolumeSFX);
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
  Stat = (double)(int)UFG::GameStatTracker::GetStat(v5, VolumeMusic);
  if ( (v16 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v15 + 16i64))(v15, v14, COERCE_DOUBLE(*(_QWORD *)&v17));
    v15 = 0i64;
  }
  v16 = 5;
  v17 = Stat;
  v9 = (double)(int)UFG::GameStatTracker::GetStat(v5, VolumeDialogue);
  if ( (v20 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v19 + 16i64))(v19, v18, COERCE_DOUBLE(*(_QWORD *)&v21));
    v19 = 0i64;
  }
  v20 = 5;
  v21 = v9;
  v10 = (double)(int)UFG::GameStatTracker::GetStat(v5, VolumeCarMusic);
  if ( (v24 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v23 + 16i64))(v23, v22, COERCE_DOUBLE(*(_QWORD *)&v25));
    v23 = 0i64;
  }
  v24 = 5;
  v25 = v10;
  if ( m_translator->mLanguage == eLang_English )
  {
    v11 = (double)(int)UFG::GameStatTracker::GetStat(v5, Subtitles);
    if ( (v28 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, long double))(*(_QWORD *)v27 + 16i64))(
        v27,
        v26,
        COERCE_LONG_DOUBLE(*(_QWORD *)&v29));
      v27 = 0i64;
    }
    v29 = v11;
  }
  else
  {
    if ( (v28 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, long double))(*(_QWORD *)v27 + 16i64))(
        v27,
        v26,
        COERCE_LONG_DOUBLE(*(_QWORD *)&v29));
      v27 = 0i64;
    }
    v29 = DOUBLE_2_0;
  }
  v28 = 5;
  v12 = (double)(int)UFG::GameStatTracker::GetStat(v5, UIScale);
  if ( (v32 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v31 + 16i64))(v31, v30, COERCE_DOUBLE(*(_QWORD *)&v33));
    v31 = 0i64;
  }
  v32 = 5;
  v33 = v12;
  Scaleform::GFx::Movie::Invoke(pObject, "OptionList_PopulateCalibration", 0i64, &ptr, 6u);
  `eh vector destructor iterator(&ptr, 0x30ui64, 6, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 107
// RVA: 0x626AD0
bool __fastcall UFG::UIHKScreenOptionsCalibration::handleMessage(
        UFG::UIHKScreenOptionsCalibration *this,
        unsigned int msgId,
        UFG::UIMessage *msg)
{
  Scaleform::GFx::Movie *pObject; // rbp
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
  int FlashArgsInt; // ebx
  UFG::GameStatTracker *v28; // rax
  UFG::UIHKScreenOptionsCalibration::eCalibrationState m_eState; // edx
  UFG::UIHKScreenOptionsCalibration::eCalibrationState v30; // edx
  const char *v32; // rdx
  UFG::qString v33; // [rsp+38h] [rbp-40h] BYREF

  pObject = this->mRenderable->m_movie.pObject;
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
    FlashArgsInt = UFG::UI::GetFlashArgsInt(msg);
    v28 = UFG::GameStatTracker::Instance();
    UFG::GameStatTracker::SetStat(v28, Subtitles, FlashArgsInt);
    return 1;
  }
  if ( msgId == UI_HASH_DPAD_DOWN_PRESSED_30 || msgId == UI_HASH_THUMBSTICK_LEFT_DOWN_30 )
  {
    if ( this->m_eState != STATE_VOLUME )
      return 1;
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xEDB4A8C7, 0i64, 0, 0i64);
    v32 = "Calibration_ScrollDown";
    goto LABEL_55;
  }
  if ( msgId == UI_HASH_DPAD_UP_PRESSED_30 || msgId == UI_HASH_THUMBSTICK_LEFT_UP_30 )
  {
    if ( this->m_eState != STATE_VOLUME )
      return 1;
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xEDB4A8C7, 0i64, 0, 0i64);
    v32 = "Calibration_ScrollUp";
LABEL_55:
    Scaleform::GFx::Movie::Invoke(pObject, v32, 0i64, 0i64, 0);
    return 1;
  }
  if ( msgId == UI_HASH_DPAD_RIGHT_PRESSED_30
    || msgId == UI_HASH_DPAD_RIGHT_REPEAT_30
    || msgId == UI_HASH_THUMBSTICK_LEFT_RIGHT_30 )
  {
    if ( this->m_eState && UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xEDB4A8C7, 0i64, 0, 0i64);
    v32 = "Calibration_GoRight";
    goto LABEL_55;
  }
  if ( msgId == UI_HASH_DPAD_LEFT_PRESSED_30
    || msgId == UI_HASH_DPAD_LEFT_REPEAT_30
    || msgId == UI_HASH_THUMBSTICK_LEFT_LEFT_30 )
  {
    if ( this->m_eState && UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xEDB4A8C7, 0i64, 0, 0i64);
    v32 = "Calibration_GoLeft";
    goto LABEL_55;
  }
  if ( msgId == UI_HASH_BUTTON_ACCEPT_PRESSED_30 )
  {
    m_eState = this->m_eState;
    if ( m_eState >= STATE_UISCALE )
    {
      UFG::UIHKScreenOptionsCalibration::Exit(this);
    }
    else
    {
      v30 = m_eState + 1;
      this->m_eState = v30;
      UFG::UIHKScreenOptionsCalibration::SetState(this, v30);
    }
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x4A3D1F6Cu, 0i64, 0, 0i64);
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
  return UFG::UIScreen::handleMessage(this, msgId, msg);
}

// File Line: 280
// RVA: 0x5EA6A0
void __fastcall UFG::UIHKScreenOptionsCalibration::GotoPrevState(UFG::UIHKScreenOptionsCalibration *this)
{
  UFG::UIHKScreenOptionsCalibration::eCalibrationState m_eState; // edx
  UFG::UIHKScreenOptionsCalibration::eCalibrationState v2; // edx

  m_eState = this->m_eState;
  if ( m_eState > STATE_INIT )
  {
    v2 = m_eState - 1;
    this->m_eState = v2;
    UFG::UIHKScreenOptionsCalibration::SetState(this, v2);
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xA4E5BFBD, 0i64, 0, 0i64);
  }
}

// File Line: 292
// RVA: 0x609070
void __fastcall UFG::UIHKScreenOptionsCalibration::SetState(
        UFG::UIHKScreenOptionsCalibration *this,
        UFG::UIHKScreenOptionsCalibration::eCalibrationState eState)
{
  Scaleform::GFx::Movie *pObject; // rdi
  Scaleform::GFx::Value::ValueUnion v4; // xmm6_8
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-50h] BYREF

  this->m_eState = eState;
  pObject = this->mRenderable->m_movie.pObject;
  `eh vector constructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  v4.NValue = (double)(int)this->m_eState;
  if ( (pargs.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      pargs.mValue);
    pargs.pObjectInterface = 0i64;
  }
  pargs.Type = VT_Number;
  pargs.mValue = v4;
  Scaleform::GFx::Movie::Invoke(pObject, "OptionsCalibration_SetState", 0i64, &pargs, 1u);
  `eh vector destructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 304
// RVA: 0x5D78E0
void __fastcall UFG::UIHKScreenOptionsCalibration::Exit(UFG::UIHKScreenOptionsCalibration *this)
{
  UFG::UIScreenTextureManager *v2; // rax
  UFG::GameSaveLoad *v3; // rax
  UFG::GameSaveLoad *v4; // rax
  Render::RenderOutputParams outSettings; // [rsp+30h] [rbp-E8h] BYREF
  Render::RenderOutputParams v6; // [rsp+A0h] [rbp-78h] BYREF

  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xA4E5BFBD, 0i64, 0, 0i64);
  UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, this->mScreenUID);
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
void __fastcall UFG::UIHKScreenOptionsCalibration::Flash_HandleMouseMove(
        UFG::UIHKScreenOptionsCalibration *this,
        float mouseX,
        float mouseY)
{
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value ptr; // [rsp+40h] [rbp-88h] BYREF
  char v5[16]; // [rsp+70h] [rbp-58h] BYREF
  __int64 v6; // [rsp+80h] [rbp-48h]
  int v7; // [rsp+88h] [rbp-40h]
  double v8; // [rsp+90h] [rbp-38h]

  pObject = this->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    `eh vector constructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( (ptr.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
        ptr.pObjectInterface,
        &ptr,
        ptr.mValue);
      ptr.pObjectInterface = 0i64;
    }
    ptr.Type = VT_Number;
    ptr.mValue.NValue = mouseX;
    if ( (v7 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v6 + 16i64))(v6, v5, COERCE_DOUBLE(*(_QWORD *)&v8));
      v6 = 0i64;
    }
    v7 = 5;
    v8 = mouseY;
    Scaleform::GFx::Movie::Invoke(pObject, "Calibration_HandleMouseMove", 0i64, &ptr, 2u);
    `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 344
// RVA: 0x5DAD50
void __fastcall UFG::UIHKScreenOptionsCalibration::Flash_HandleMouseClick(
        UFG::UIHKScreenOptionsCalibration *this,
        float mouseX,
        float mouseY)
{
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value ptr; // [rsp+40h] [rbp-88h] BYREF
  char v5[16]; // [rsp+70h] [rbp-58h] BYREF
  __int64 v6; // [rsp+80h] [rbp-48h]
  int v7; // [rsp+88h] [rbp-40h]
  double v8; // [rsp+90h] [rbp-38h]

  pObject = this->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    `eh vector constructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( (ptr.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
        ptr.pObjectInterface,
        &ptr,
        ptr.mValue);
      ptr.pObjectInterface = 0i64;
    }
    ptr.Type = VT_Number;
    ptr.mValue.NValue = mouseX;
    if ( (v7 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v6 + 16i64))(v6, v5, COERCE_DOUBLE(*(_QWORD *)&v8));
      v6 = 0i64;
    }
    v7 = 5;
    v8 = mouseY;
    Scaleform::GFx::Movie::Invoke(pObject, "Calibration_HandleMouseClick", 0i64, &ptr, 2u);
    `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

