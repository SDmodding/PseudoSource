// File Line: 26
// RVA: 0x5F1AA0
void __fastcall UFG::UIHKScreenOptionsDisplay::LoadTextures(
        UFG::qReflectInventoryBase *callback,
        UFG::qReflectInventoryBase *callbackParam)
{
  UFG::UIScreenTextureManager *v4; // rax

  v4 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::QueueTexturePackLoad(
    v4,
    UFG::UIHKScreenOptions::gTexturePackFilename,
    HIGH_PRIORITY,
    callback,
    callbackParam);
}

// File Line: 30
// RVA: 0x5D4120
bool __fastcall UFG::UIHKScreenOptionsDisplayAdvanced::AreTexturesLoaded()
{
  UFG::UIScreenTextureManager *v0; // rax

  v0 = UFG::UIScreenTextureManager::Instance();
  return UFG::UIScreenTextureManager::IsTexturePackLoaded(v0, UFG::UIHKScreenOptions::gTexturePackFilename);
}

// File Line: 34
// RVA: 0x600DD0
void UFG::UIHKScreenOptionsGame::ReleaseTextures(void)
{
  UFG::UIScreenTextureManager *v0; // rax

  v0 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseTexturePack(v0, UFG::UIHKScreenOptions::gTexturePackFilename);
}

// File Line: 44
// RVA: 0x5C63D0
void __fastcall UFG::UIHKScreenOptionsAudio::UIHKScreenOptionsAudio(UFG::UIHKScreenOptionsAudio *this)
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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenOptionsAudio::`vftable;
  *(_QWORD *)&this->oldSFX = 0i64;
  *(_QWORD *)&this->oldDiag = 0i64;
}

// File Line: 55
// RVA: 0x633240
void __fastcall UFG::UIHKScreenOptionsAudio::init(UFG::UIHKScreenOptionsAudio *this, UFG::UICommandData *data)
{
  UFG::Controller *v3; // rcx
  Scaleform::GFx::Movie *pObject; // rsi
  UFG::GameStatTracker *v5; // rbx
  Scaleform::GFx::Value::ValueUnion v6; // xmm6_8
  double oldMusic; // xmm6_8
  double oldDiag; // xmm6_8
  double oldCar; // xmm6_8
  Scaleform::GFx::Value ptr; // [rsp+30h] [rbp-C8h] BYREF
  char v11[16]; // [rsp+60h] [rbp-98h] BYREF
  __int64 v12; // [rsp+70h] [rbp-88h]
  double v13; // [rsp+78h] [rbp-80h]
  char v14[16]; // [rsp+88h] [rbp-70h] BYREF
  __int64 v15; // [rsp+98h] [rbp-60h]
  int v16; // [rsp+A0h] [rbp-58h]
  double v17; // [rsp+A8h] [rbp-50h]
  char v18[16]; // [rsp+B8h] [rbp-40h] BYREF
  __int64 v19; // [rsp+C8h] [rbp-30h]
  int v20; // [rsp+D0h] [rbp-28h]
  double v21; // [rsp+D8h] [rbp-20h]
  __int64 v22; // [rsp+E8h] [rbp-10h]

  v22 = -2i64;
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
  (*((void (__fastcall **)(UFG::UIHKScreenOptionsAudio *))&this->vfptr[1].__vecDelDtor + 1))(this);
  pObject = this->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    v5 = UFG::GameStatTracker::Instance();
    this->oldSFX = UFG::GameStatTracker::GetStat(v5, VolumeSFX);
    this->oldMusic = UFG::GameStatTracker::GetStat(v5, VolumeMusic);
    this->oldDiag = UFG::GameStatTracker::GetStat(v5, VolumeDialogue);
    this->oldCar = UFG::GameStatTracker::GetStat(v5, VolumeCarMusic);
    `eh vector constructor iterator(&ptr, 0x30ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    v6.NValue = (double)this->oldSFX;
    if ( (ptr.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
        ptr.pObjectInterface,
        &ptr,
        ptr.mValue);
      ptr.pObjectInterface = 0i64;
    }
    ptr.Type = VT_Number;
    ptr.mValue = v6;
    oldMusic = (double)this->oldMusic;
    if ( (LOBYTE(v13) & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v12 + 16i64))(
        v12,
        v11,
        COERCE_DOUBLE(*(_QWORD *)&v13));
      v12 = 0i64;
    }
    v13 = oldMusic;
    oldDiag = (double)this->oldDiag;
    if ( (v16 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v15 + 16i64))(
        v15,
        v14,
        COERCE_DOUBLE(*(_QWORD *)&v17));
      v15 = 0i64;
    }
    v16 = 5;
    v17 = oldDiag;
    oldCar = (double)this->oldCar;
    if ( (v20 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v19 + 16i64))(
        v19,
        v18,
        COERCE_DOUBLE(*(_QWORD *)&v21));
      v19 = 0i64;
    }
    v20 = 5;
    v21 = oldCar;
    Scaleform::GFx::Movie::Invoke(pObject, "OptionList_SetValues", 0i64, &ptr, 4u);
    Scaleform::GFx::Movie::Invoke(pObject, "OptionList_PlayIntro", 0i64, 0i64, 0);
    `eh vector destructor iterator(&ptr, 0x30ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x688D286Au, 0i64, 0, 0i64);
}

// File Line: 85
// RVA: 0x6262F0
bool __fastcall UFG::UIHKScreenOptionsAudio::handleMessage(
        UFG::UIHKScreenOptionsAudio *this,
        unsigned int msgId,
        UFG::UIMessage *msg)
{
  UFG::GameStatTracker *v6; // rbp
  int v7; // edi
  const char *v8; // rcx
  UFG::TiDo *v9; // rbx
  float v10; // xmm6_4
  unsigned int v11; // eax
  UFG::TiDo *v12; // rcx
  int FlashArgsInt; // ebx
  UFG::TiDo *v15; // rdi
  int v16; // eax
  UFG::qString v17; // [rsp+28h] [rbp-40h] BYREF

  v6 = UFG::GameStatTracker::Instance();
  if ( msgId == UI_HASH_OPTIONS_VOLUME_SFX_20 )
  {
    this->mOptionChanged = 1;
    if ( msg )
    {
      UFG::qString::qString(&v17, (UFG::qString *)&msg[1]);
      v7 = UFG::qToInt32(v17.mData, 0);
      UFG::qString::~qString(&v17);
    }
    else
    {
      v7 = 0;
    }
    UFG::GameStatTracker::SetStat(v6, VolumeSFX, v7);
    v8 = "master_sfx_volume";
LABEL_6:
    v9 = UFG::TiDo::m_pInstance;
    v10 = (float)v7;
    v11 = UFG::TiDo::CalcWwiseUid(v8);
    v12 = v9;
LABEL_7:
    UFG::TiDo::SetWwiseRtpcValue(v12, v11, v10, 0xFFFFFFFFFFFFFFFFui64);
    return 1;
  }
  if ( msgId == UI_HASH_OPTIONS_VOLUME_DIALOGUE_20 )
  {
    this->mOptionChanged = 1;
    if ( msg )
    {
      UFG::qString::qString(&v17, (UFG::qString *)&msg[1]);
      v7 = UFG::qToInt32(v17.mData, 0);
      UFG::qString::~qString(&v17);
    }
    else
    {
      v7 = 0;
    }
    UFG::GameStatTracker::SetStat(v6, VolumeDialogue, v7);
    v8 = "master_dialog_volume";
    goto LABEL_6;
  }
  if ( msgId == UI_HASH_OPTIONS_VOLUME_MUSIC_20 )
  {
    this->mOptionChanged = 1;
    FlashArgsInt = UFG::UI::GetFlashArgsInt(msg);
    UFG::GameStatTracker::SetStat(v6, VolumeMusic, FlashArgsInt);
    v15 = UFG::TiDo::m_pInstance;
    v10 = (float)FlashArgsInt;
    v11 = UFG::TiDo::CalcWwiseUid("master_music_volume");
    v12 = v15;
    goto LABEL_7;
  }
  if ( msgId == UI_HASH_OPTIONS_VOLUME_CAR_MUSIC_20 )
  {
    this->mOptionChanged = 1;
    v7 = UFG::UI::GetFlashArgsInt(msg);
    UFG::GameStatTracker::SetStat(v6, VolumeCarMusic, v7);
    if ( UFG::RadioFullyControlled::sm_playerRadio )
      UFG::Radio::SetRadioVolume(UFG::RadioFullyControlled::sm_playerRadio, (float)v7);
    v8 = "master_radio_volume";
    goto LABEL_6;
  }
  if ( msgId == UI_HASH_OPTIONS_SUBTITLES_20 )
  {
    this->mOptionChanged = 1;
    v16 = UFG::UI::GetFlashArgsInt(msg);
    UFG::GameStatTracker::SetStat(v6, Subtitles, v16);
    return 1;
  }
  return UFG::UIHKScreenOptions::handleMessage(this, msgId, msg);
}

// File Line: 144
// RVA: 0x603030
void __fastcall UFG::UIHKScreenOptionsAudio::RestoreOptions(UFG::UIHKScreenOptionsAudio *this)
{
  UFG::GameStatTracker *v2; // rbx

  v2 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::SetStat(v2, VolumeSFX, this->oldSFX);
  UFG::GameStatTracker::SetStat(v2, VolumeMusic, this->oldMusic);
  UFG::GameStatTracker::SetStat(v2, VolumeDialogue, this->oldDiag);
  UFG::GameStatTracker::SetStat(v2, VolumeCarMusic, this->oldCar);
}

