// File Line: 26
// RVA: 0x5F1AA0
void __fastcall UFG::UIHKScreenOptionsDisplay::LoadTextures(void (__fastcall *callback)(UFG::DataStreamer::Handle *, void *), void *callbackParam)
{
  void *v2; // rbx
  void (__fastcall *v3)(UFG::DataStreamer::Handle *, void *); // rdi
  UFG::UIScreenTextureManager *v4; // rax

  v2 = callbackParam;
  v3 = callback;
  v4 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::QueueTexturePackLoad(
    v4,
    UFG::UIHKScreenOptions::gTexturePackFilename,
    HIGH_PRIORITY,
    v3,
    v2);
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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenOptionsAudio::`vftable;
  *(_QWORD *)&this->oldSFX = 0i64;
  *(_QWORD *)&this->oldDiag = 0i64;
}

// File Line: 55
// RVA: 0x633240
void __fastcall UFG::UIHKScreenOptionsAudio::init(UFG::UIHKScreenOptionsAudio *this, UFG::UICommandData *data)
{
  UFG::UIHKScreenOptionsAudio *v2; // rdi
  UFG::Controller *v3; // rcx
  Scaleform::GFx::Movie *v4; // rsi
  UFG::GameStatTracker *v5; // rbx
  double v6; // xmm6_8
  double v7; // xmm6_8
  double v8; // xmm6_8
  double v9; // xmm6_8
  char ptr; // [rsp+30h] [rbp-C8h]
  __int64 v11; // [rsp+40h] [rbp-B8h]
  unsigned int v12; // [rsp+48h] [rbp-B0h]
  double v13; // [rsp+50h] [rbp-A8h]
  char v14; // [rsp+60h] [rbp-98h]
  __int64 v15; // [rsp+70h] [rbp-88h]
  double v16; // [rsp+78h] [rbp-80h]
  char v17; // [rsp+88h] [rbp-70h]
  __int64 v18; // [rsp+98h] [rbp-60h]
  unsigned int v19; // [rsp+A0h] [rbp-58h]
  double v20; // [rsp+A8h] [rbp-50h]
  char v21; // [rsp+B8h] [rbp-40h]
  __int64 v22; // [rsp+C8h] [rbp-30h]
  unsigned int v23; // [rsp+D0h] [rbp-28h]
  double v24; // [rsp+D8h] [rbp-20h]
  __int64 v25; // [rsp+E8h] [rbp-10h]

  v25 = -2i64;
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
  (*((void (__fastcall **)(UFG::UIHKScreenOptionsAudio *))&v2->vfptr[1].__vecDelDtor + 1))(v2);
  v4 = v2->mRenderable->m_movie.pObject;
  if ( v4 )
  {
    v5 = UFG::GameStatTracker::Instance();
    v2->oldSFX = UFG::GameStatTracker::GetStat(v5, VolumeSFX);
    v2->oldMusic = UFG::GameStatTracker::GetStat(v5, VolumeMusic);
    v2->oldDiag = UFG::GameStatTracker::GetStat(v5, VolumeDialogue);
    v2->oldCar = UFG::GameStatTracker::GetStat(v5, VolumeCarMusic);
    `eh vector constructor iterator(&ptr, 0x30ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    v6 = (double)v2->oldSFX;
    if ( (v12 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v11 + 16i64))(
        v11,
        &ptr,
        COERCE_DOUBLE(*(_QWORD *)&v13));
      v11 = 0i64;
    }
    v12 = 5;
    v13 = v6;
    v7 = (double)v2->oldMusic;
    if ( (LODWORD(v16) >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v15 + 16i64))(
        v15,
        &v14,
        COERCE_DOUBLE(*(_QWORD *)&v16));
      v15 = 0i64;
    }
    v16 = v7;
    v8 = (double)v2->oldDiag;
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
    v9 = (double)v2->oldCar;
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
    Scaleform::GFx::Movie::Invoke(v4, "OptionList_SetValues", 0i64, (Scaleform::GFx::Value *)&ptr, 4u);
    Scaleform::GFx::Movie::Invoke(v4, "OptionList_PlayIntro", 0i64, 0i64, 0);
    `eh vector destructor iterator(&ptr, 0x30ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(
      (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
      0x688D286Au,
      0i64,
      0,
      0i64);
}

// File Line: 85
// RVA: 0x6262F0
bool __fastcall UFG::UIHKScreenOptionsAudio::handleMessage(UFG::UIHKScreenOptionsAudio *this, unsigned int msgId, UFG::UIMessage *msg)
{
  UFG::UIMessage *v3; // rbx
  unsigned int v4; // edi
  UFG::UIHKScreenOptionsAudio *v5; // rsi
  UFG::GameStatTracker *v6; // rbp
  int v7; // edi
  const char *v8; // rcx
  UFG::TiDo *v9; // rbx
  float v10; // xmm6_4
  unsigned int v11; // eax
  UFG::TiDo *v12; // rcx
  int v14; // ebx
  UFG::TiDo *v15; // rdi
  int v16; // eax
  UFG::qString v17; // [rsp+28h] [rbp-40h]

  v3 = msg;
  v4 = msgId;
  v5 = this;
  v6 = UFG::GameStatTracker::Instance();
  if ( v4 == UI_HASH_OPTIONS_VOLUME_SFX_20 )
  {
    v5->mOptionChanged = 1;
    if ( v3 )
    {
      UFG::qString::qString(&v17, (UFG::qString *)&v3[1]);
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
  if ( v4 == UI_HASH_OPTIONS_VOLUME_DIALOGUE_20 )
  {
    v5->mOptionChanged = 1;
    if ( v3 )
    {
      UFG::qString::qString(&v17, (UFG::qString *)&v3[1]);
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
  if ( v4 == UI_HASH_OPTIONS_VOLUME_MUSIC_20 )
  {
    v5->mOptionChanged = 1;
    v14 = UFG::UI::GetFlashArgsInt(v3);
    UFG::GameStatTracker::SetStat(v6, VolumeMusic, v14);
    v15 = UFG::TiDo::m_pInstance;
    v10 = (float)v14;
    v11 = UFG::TiDo::CalcWwiseUid("master_music_volume");
    v12 = v15;
    goto LABEL_7;
  }
  if ( v4 == UI_HASH_OPTIONS_VOLUME_CAR_MUSIC_20 )
  {
    v5->mOptionChanged = 1;
    v7 = UFG::UI::GetFlashArgsInt(v3);
    UFG::GameStatTracker::SetStat(v6, VolumeCarMusic, v7);
    if ( UFG::RadioFullyControlled::sm_playerRadio )
      UFG::Radio::SetRadioVolume((UFG::Radio *)&UFG::RadioFullyControlled::sm_playerRadio->vfptr, (float)v7);
    v8 = "master_radio_volume";
    goto LABEL_6;
  }
  if ( v4 == UI_HASH_OPTIONS_SUBTITLES_20 )
  {
    v5->mOptionChanged = 1;
    v16 = UFG::UI::GetFlashArgsInt(v3);
    UFG::GameStatTracker::SetStat(v6, Subtitles, v16);
    return 1;
  }
  return UFG::UIHKScreenOptions::handleMessage((UFG::UIHKScreenOptions *)&v5->vfptr, v4, v3);
}

// File Line: 144
// RVA: 0x603030
void __fastcall UFG::UIHKScreenOptionsAudio::RestoreOptions(UFG::UIHKScreenOptionsAudio *this)
{
  UFG::UIHKScreenOptionsAudio *v1; // rdi
  UFG::GameStatTracker *v2; // rbx

  v1 = this;
  v2 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::SetStat(v2, VolumeSFX, v1->oldSFX);
  UFG::GameStatTracker::SetStat(v2, VolumeMusic, v1->oldMusic);
  UFG::GameStatTracker::SetStat(v2, VolumeDialogue, v1->oldDiag);
  UFG::GameStatTracker::SetStat(v2, VolumeCarMusic, v1->oldCar);
}

