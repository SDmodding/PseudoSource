// File Line: 28
// RVA: 0x1570B60
__int64 UFG::_dynamic_initializer_for__symGhostDLCFlow__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("DLC_Ghost", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symGhostDLCFlow, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__symGhostDLCFlow__);
}

// File Line: 29
// RVA: 0x1570C20
__int64 UFG::_dynamic_initializer_for__symNewYearDLCFlow__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("DLC_CNY", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symNewYearDLCFlow, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__symNewYearDLCFlow__);
}

// File Line: 38
// RVA: 0x1566D80
__int64 dynamic_initializer_for__UFG::UIHKScreenCaseComplete::gBiosTexturePackFilename__()
{
  UFG::qString::qString(&UFG::UIHKScreenCaseComplete::gBiosTexturePackFilename);
  return atexit(dynamic_atexit_destructor_for__UFG::UIHKScreenCaseComplete::gBiosTexturePackFilename__);
}

// File Line: 39
// RVA: 0x1567190
__int64 dynamic_initializer_for__UFG::UIHKScreenCaseComplete::mInfo__()
{
  `eh vector constructor iterator'(
    &UFG::UIHKScreenCaseComplete::mInfo,
    0x30ui64,
    5,
    (void (__fastcall *)(void *))UFG::PersistentData::String::String);
  return atexit(dynamic_atexit_destructor_for__UFG::UIHKScreenCaseComplete::mInfo__);
}

// File Line: 45
// RVA: 0x5F1960
void __fastcall UFG::UIHKScreenCaseComplete::LoadTextures(void (__fastcall *callback)(UFG::DataStreamer::Handle *, void *), void *callbackParam)
{
  void *v2; // rbx
  void (__fastcall *v3)(UFG::DataStreamer::Handle *, void *); // rdi
  UFG::UIScreenTextureManager *v4; // rax
  UFG::UIScreenTextureManager *v5; // rax

  v2 = callbackParam;
  v3 = callback;
  v4 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::QueueTexturePackLoad(
    v4,
    UFG::UIHKScreenCaseComplete::gTexturePackFilename,
    HIGH_PRIORITY,
    v3,
    v2);
  if ( UFG::UIHKScreenCaseComplete::mCaseType == 4 )
  {
    UFG::UIHKScreenCaseComplete::QueryBiosTexturePackFilename();
    v5 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::QueueTexturePackLoad(
      v5,
      UFG::UIHKScreenCaseComplete::gBiosTexturePackFilename.mData,
      HIGH_PRIORITY,
      v3,
      v2);
  }
}

// File Line: 54
// RVA: 0x5D4030
bool __fastcall UFG::UIHKScreenCaseComplete::AreTexturesLoaded()
{
  UFG::UIScreenTextureManager *v0; // rax
  bool v1; // bl
  UFG::UIScreenTextureManager *v2; // rax

  v0 = UFG::UIScreenTextureManager::Instance();
  v1 = UFG::UIScreenTextureManager::IsTexturePackLoaded(v0, UFG::UIHKScreenCaseComplete::gTexturePackFilename);
  if ( UFG::UIHKScreenCaseComplete::mCaseType != 4 )
    return v1;
  v2 = UFG::UIScreenTextureManager::Instance();
  return v1 & UFG::UIScreenTextureManager::IsTexturePackLoaded(
                v2,
                UFG::UIHKScreenCaseComplete::gBiosTexturePackFilename.mData);
}

// File Line: 64
// RVA: 0x600CF0
void UFG::UIHKScreenCaseComplete::ReleaseTextures(void)
{
  UFG::UIScreenTextureManager *v0; // rax
  UFG::UIScreenTextureManager *v1; // rax

  v0 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseTexturePack(v0, UFG::UIHKScreenCaseComplete::gTexturePackFilename);
  if ( UFG::UIHKScreenCaseComplete::mCaseType == 4 )
  {
    v1 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::ReleaseTexturePack(v1, UFG::UIHKScreenCaseComplete::gBiosTexturePackFilename.mData);
  }
  UFG::UIHKScreenCaseComplete::mCaseType = 0;
}

// File Line: 73
// RVA: 0x5FE950
void UFG::UIHKScreenCaseComplete::QueryBiosTexturePackFilename(void)
{
  UFG::ProgressionTracker *v0; // rax
  UFG::ProgressionTracker *v1; // rax
  UFG::qSymbol *v2; // rax
  const char *v3; // rdx

  v0 = UFG::ProgressionTracker::Instance();
  if ( UFG::ProgressionTracker::GetActiveFlow(v0)->mUID == UFG::symGhostDLCFlow.mUID )
  {
    UFG::qString::Set(
      &UFG::UIHKScreenCaseComplete::gBiosTexturePackFilename,
      "Data\\UI\\unlockables_texturepack_DLC_1.perm.bin");
  }
  else
  {
    v1 = UFG::ProgressionTracker::Instance();
    v2 = UFG::ProgressionTracker::GetActiveFlow(v1);
    v3 = "Data\\UI\\unlockables_texturepack_DLC_2.perm.bin";
    if ( v2->mUID != UFG::symNewYearDLCFlow.mUID )
      v3 = "Data\\UI\\unlockables_texturepack.perm.bin";
    UFG::qString::Set(&UFG::UIHKScreenCaseComplete::gBiosTexturePackFilename, v3);
  }
}

// File Line: 94
// RVA: 0x5C4A80
void __fastcall UFG::UIHKScreenCaseComplete::UIHKScreenCaseComplete(UFG::UIHKScreenCaseComplete *this)
{
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v1; // rax

  v1 = (UFG::qNode<UFG::UIScreen,UFG::UIScreen> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenCaseComplete::`vftable';
  *(_WORD *)&this->mIntroAnimComplete = 0;
  this->mFlipOut = 0;
  this->mBioTitles.pObjectInterface = 0i64;
  this->mBioTitles.Type = 0;
  this->mBioImages.pObjectInterface = 0i64;
  this->mBioImages.Type = 0;
  this->mBioIntros.pObjectInterface = 0i64;
  this->mBioIntros.Type = 0;
  this->mBioBodies.pObjectInterface = 0i64;
  this->mBioBodies.Type = 0;
  this->mBioUnlocks.pObjectInterface = 0i64;
  this->mBioUnlocks.Type = 0;
  if ( (unsigned int)(UFG::UIHKScreenCaseComplete::mCaseType - 2) <= 1 )
    UFG::ActivateInputSubMode(ISM_LIMITED, UFG::gActiveControllerNum);
}

// File Line: 103
// RVA: 0x5CA140
void __fastcall UFG::UIHKScreenCaseComplete::~UIHKScreenCaseComplete(UFG::UIHKScreenCaseComplete *this)
{
  UFG::UIHKScreenCaseComplete *v1; // rdi
  UFG::qString *v2; // rbx
  unsigned int v3; // eax
  UFG::UIScreenTextureManager *v4; // rax

  v1 = this;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenCaseComplete::`vftable';
  v2 = &UFG::UIHKScreenCaseComplete::mInfo;
  do
  {
    UFG::qString::Set(v2, &customWorldMapCaption);
    LOBYTE(v2[1].mPrev) = 0;
    v2 = (UFG::qString *)((char *)v2 + 48);
  }
  while ( (signed __int64)v2 < (signed __int64)&UI_HASH_BUTTON_SELECT_RELEASED_30 );
  UFG::UIHKScreenCaseComplete::mNumInfo = 0;
  if ( (unsigned int)(UFG::UIHKScreenCaseComplete::mCaseType - 1) <= 1 )
  {
    v3 = UFG::TiDo::CalcWwiseUid("Stop_camera_upload");
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr, v3, 0i64, 0, 0i64);
  }
  if ( UFG::UIHKScreenCaseComplete::mCaseType != 4 )
    UFG::UIHKScreenHud::ClearPDACache();
  v4 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v4, "CaseComplete");
  if ( UFG::UIHKScreenCamera::sPhotoTarget )
  {
    Illusion::DeleteTarget(UFG::UIHKScreenCamera::sPhotoTarget, 1);
    UFG::UIHKScreenCamera::sPhotoTarget = 0i64;
  }
  UFG::DeactivateInputSubMode(ISM_LIMITED, UFG::gActiveControllerNum);
  if ( ((unsigned int)v1->mBioUnlocks.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&v1->mBioUnlocks.pObjectInterface->vfptr->gap8[8])(
      v1->mBioUnlocks.pObjectInterface,
      &v1->mBioUnlocks,
      *(_QWORD *)&v1->mBioUnlocks.mValue.NValue);
    v1->mBioUnlocks.pObjectInterface = 0i64;
  }
  v1->mBioUnlocks.Type = 0;
  if ( ((unsigned int)v1->mBioBodies.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&v1->mBioBodies.pObjectInterface->vfptr->gap8[8])(
      v1->mBioBodies.pObjectInterface,
      &v1->mBioBodies,
      *(_QWORD *)&v1->mBioBodies.mValue.NValue);
    v1->mBioBodies.pObjectInterface = 0i64;
  }
  v1->mBioBodies.Type = 0;
  if ( ((unsigned int)v1->mBioIntros.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&v1->mBioIntros.pObjectInterface->vfptr->gap8[8])(
      v1->mBioIntros.pObjectInterface,
      &v1->mBioIntros,
      *(_QWORD *)&v1->mBioIntros.mValue.NValue);
    v1->mBioIntros.pObjectInterface = 0i64;
  }
  v1->mBioIntros.Type = 0;
  if ( ((unsigned int)v1->mBioImages.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&v1->mBioImages.pObjectInterface->vfptr->gap8[8])(
      v1->mBioImages.pObjectInterface,
      &v1->mBioImages,
      *(_QWORD *)&v1->mBioImages.mValue.NValue);
    v1->mBioImages.pObjectInterface = 0i64;
  }
  v1->mBioImages.Type = 0;
  if ( ((unsigned int)v1->mBioTitles.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&v1->mBioTitles.pObjectInterface->vfptr->gap8[8])(
      v1->mBioTitles.pObjectInterface,
      &v1->mBioTitles,
      *(_QWORD *)&v1->mBioTitles.mValue.NValue);
    v1->mBioTitles.pObjectInterface = 0i64;
  }
  v1->mBioTitles.Type = 0;
  UFG::UIScreen::~UIScreen((UFG::UIScreen *)&v1->vfptr);
}

// File Line: 126
// RVA: 0x630050
void __fastcall UFG::UIHKScreenCaseComplete::init(UFG::UIHKScreenCaseComplete *this, UFG::UICommandData *data)
{
  UFG::UIHKScreenCaseComplete *v2; // rbx

  v2 = this;
  UFG::UIScreen::init((UFG::UIScreen *)&this->vfptr, data);
  *(_WORD *)&v2->mIntroAnimComplete = 0;
  v2->mFlipOut = 0;
  if ( UFG::UIHKScreenCaseComplete::mCaseType == 4 )
  {
    UFG::UIHKScreenCaseComplete::Bind(v2);
    UFG::UIHKScreenCaseComplete::PopulateArrays(v2);
  }
  UFG::UIHKScreenCaseComplete::Flash_Init(v2);
}

// File Line: 149
// RVA: 0x6219E0
char __fastcall UFG::UIHKScreenCaseComplete::handleMessage(UFG::UIHKScreenCaseComplete *this, unsigned int msgId, UFG::UIMessage *msg)
{
  UFG::UIMessage *v3; // r15
  unsigned int v4; // esi
  UFG::UIHKScreenCaseComplete *v5; // rdi
  unsigned int v7; // eax
  UFG::HudAudio *v8; // rcx
  unsigned int v9; // edx
  unsigned int v10; // eax
  unsigned int v11; // eax
  UFG::UIScreenRenderable *v12; // rax
  bool v13; // r14
  bool v14; // al
  UFG::UIScreenRenderable *v15; // rax
  bool v16; // r14
  bool v17; // al
  UFG::UIScreenRenderable *v18; // rax
  UFG::qString v19; // [rsp+20h] [rbp-21h]
  Scaleform::GFx::Value pargs; // [rsp+50h] [rbp+Fh]

  v3 = msg;
  v4 = msgId;
  v5 = this;
  if ( msgId == UI_HASH_GAME_OVER_20 )
  {
    UFG::UIScreenManagerBase::queuePopScreen(
      (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
      this->mScreenUID);
    return 0;
  }
  if ( msgId == UI_HASH_INTRO_COMPLETE_30 )
  {
    if ( (unsigned int)(UFG::UIHKScreenCaseComplete::mCaseType - 1) <= 1 )
    {
      v7 = UFG::TiDo::CalcWwiseUid("Play_camera_upload");
      v8 = UFG::HudAudio::m_instance;
      if ( !UFG::HudAudio::m_instance )
        goto LABEL_23;
      v9 = v7;
LABEL_21:
      UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&v8->vfptr, v9, 0i64, 0, 0i64);
      goto LABEL_22;
    }
    goto LABEL_22;
  }
  if ( msgId == UI_HASH_INTRO_ANIM_COMPLETE_30 )
  {
    this->mIntroAnimComplete = 1;
    goto LABEL_22;
  }
  if ( msgId == UI_HASH_OUTRO_COMPLETE_30 )
  {
    UFG::UIScreenManagerBase::queuePopScreen(
      (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
      this->mScreenUID);
    goto LABEL_22;
  }
  if ( msgId == UI_HASH_PDA_CAMERA_DESTROY_20 )
  {
    if ( UFG::UIHKScreenCaseComplete::mCaseType != 4 )
      goto LABEL_59;
    UFG::UIHKScreenHud::ClearPDACache();
    UFG::UIScreenManagerBase::queuePopScreen(
      (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
      v5->mScreenUID);
    goto LABEL_22;
  }
  if ( msgId != UI_HASH_PLAYSOUND_20 )
  {
    if ( msgId == UI_HASH_BUTTON_ACCEPT_RELEASED_30 )
    {
      v8 = UFG::HudAudio::m_instance;
      if ( !UFG::HudAudio::m_instance )
        goto LABEL_23;
      v9 = 1740120221;
      goto LABEL_21;
    }
LABEL_22:
    v8 = UFG::HudAudio::m_instance;
LABEL_23:
    if ( UFG::UIHKScreenCaseComplete::mCaseType == 4 )
    {
      if ( v4 == UI_HASH_DPAD_UP_PRESSED_30 || v4 == UI_HASH_DPAD_UP_REPEAT_30 )
      {
        if ( !v5->mInBio && v8 )
          UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&v8->vfptr, 0x4F717979u, 0i64, 0, 0i64);
        *(_QWORD *)&v19.mMagic = 0i64;
        LODWORD(v19.mData) = 0;
        v16 = v5->mInBio;
        LODWORD(v19.mData) = 2;
        LOBYTE(v19.mStringHash32) = v16;
        v17 = v5->mInBio;
        pargs.pObjectInterface = 0i64;
        pargs.Type = 2;
        pargs.mValue.BValue = v17;
        v18 = v5->mRenderable;
        LODWORD(v19.mPrev) = 1;
        Scaleform::GFx::Movie::Invoke(v18->m_movie.pObject, "BiosList_ScrollUp", 0i64, &pargs, 1u);
        if ( ((unsigned int)pargs.Type >> 6) & 1 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
            pargs.pObjectInterface,
            &pargs,
            *(_QWORD *)&pargs.mValue.NValue);
          pargs.pObjectInterface = 0i64;
        }
        pargs.Type = 0;
        goto LABEL_56;
      }
      if ( v4 == UI_HASH_DPAD_DOWN_PRESSED_30 || v4 == UI_HASH_DPAD_DOWN_REPEAT_30 )
      {
        if ( !v5->mInBio && v8 )
          UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&v8->vfptr, 0x4F717979u, 0i64, 0, 0i64);
        *(_QWORD *)&v19.mMagic = 0i64;
        LODWORD(v19.mData) = 0;
        v13 = v5->mInBio;
        LODWORD(v19.mData) = 2;
        LOBYTE(v19.mStringHash32) = v13;
        v14 = v5->mInBio;
        pargs.pObjectInterface = 0i64;
        pargs.Type = 2;
        pargs.mValue.BValue = v14;
        v15 = v5->mRenderable;
        LODWORD(v19.mPrev) = 1;
        Scaleform::GFx::Movie::Invoke(v15->m_movie.pObject, "BiosList_ScrollDown", 0i64, &pargs, 1u);
        if ( ((unsigned int)pargs.Type >> 6) & 1 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
            pargs.pObjectInterface,
            &pargs,
            *(_QWORD *)&pargs.mValue.NValue);
          pargs.pObjectInterface = 0i64;
        }
        pargs.Type = 0;
        goto LABEL_56;
      }
      if ( v4 == UI_HASH_BUTTON_ACCEPT_RELEASED_30 )
      {
        if ( !v5->mInBio )
        {
          v11 = UFG::UIHKScreenCaseComplete::GetBiosIndex(v5);
          *(_QWORD *)&v19.mMagic = 0i64;
          LODWORD(v19.mData) = 0;
          v5->mBioUnlocks.pObjectInterface->vfptr->GetElement(
            v5->mBioUnlocks.pObjectInterface,
            v5->mBioUnlocks.mValue.pStringManaged,
            v11,
            (Scaleform::GFx::Value *)&v19);
          if ( LOBYTE(v19.mStringHash32) == 1 )
          {
            if ( UFG::HudAudio::m_instance )
              UFG::AudioEntity::CreateAndPlayEvent(
                (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
                0x9E75334E,
                0i64,
                0,
                0i64);
            v12 = v5->mRenderable;
            LODWORD(v19.mPrev) = 0;
            Scaleform::GFx::Movie::Invoke(v12->m_movie.pObject, "Bios_Select", 0i64, 0i64, 0);
            v5->mInBio = 1;
          }
LABEL_56:
          if ( (LODWORD(v19.mData) >> 6) & 1 )
          {
            (*(void (__fastcall **)(_QWORD, UFG::qString *, _QWORD))(**(_QWORD **)&v19.mMagic + 16i64))(
              *(_QWORD *)&v19.mMagic,
              &v19,
              *(_QWORD *)&v19.mStringHash32);
            *(_QWORD *)&v19.mMagic = 0i64;
          }
          LODWORD(v19.mData) = 0;
        }
        return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
      }
      if ( v4 != UI_HASH_BUTTON_BACK_RELEASED_30 )
        return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
      if ( v5->mInBio )
      {
        if ( v8 )
          UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&v8->vfptr, 0x4AAC5E6Bu, 0i64, 0, 0i64);
        Scaleform::GFx::Movie::Invoke(v5->mRenderable->m_movie.pObject, "Bios_Back", 0i64, 0i64, 0);
        v5->mInBio = 0;
        return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
      }
LABEL_61:
      UFG::UIHKScreenCaseComplete::Flash_FlipOut(v5);
      return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
    }
LABEL_59:
    if ( !v5->mIntroAnimComplete || v4 != UI_HASH_BUTTON_ACCEPT_RELEASED_30 )
      return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
    goto LABEL_61;
  }
  UFG::qString::qString(&v19, (UFG::qString *)&msg[1]);
  v10 = UFG::TiDo::CalcWwiseUid(v19.mData);
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr, v10, 0i64, 0, 0i64);
  UFG::qString::~qString(&v19);
  return 1;
}

// File Line: 258
// RVA: 0x5D1E70
void __fastcall UFG::UIHKScreenCaseComplete::AddInfo(const char *caption, bool completed)
{
  bool v2; // bl
  int v3; // edx

  v2 = completed;
  if ( UFG::UIHKScreenCaseComplete::mNumInfo < 5 )
  {
    UFG::qString::Set(
      (UFG::qString *)((char *)&UFG::UIHKScreenCaseComplete::mInfo + 48 * UFG::UIHKScreenCaseComplete::mNumInfo),
      caption);
    v3 = UFG::UIHKScreenCaseComplete::mNumInfo + 1;
    *((_BYTE *)&UFG::UIHKScreenCaseComplete::mInfo + 48 * UFG::UIHKScreenCaseComplete::mNumInfo + 40) = v2;
    UFG::UIHKScreenCaseComplete::mNumInfo = v3;
  }
}

// File Line: 298
// RVA: 0x5DBF70
void __fastcall UFG::UIHKScreenCaseComplete::Flash_Init(UFG::UIHKScreenCaseComplete *this)
{
  UFG::UIHKScreenCaseComplete *v1; // rbx
  Scaleform::GFx::Movie *v2; // r14
  signed int v3; // edi
  _BYTE *v4; // rbx
  __int64 v5; // rsi
  char v6; // si
  Scaleform::GFx::Value pargs; // [rsp+30h] [rbp-B8h]
  char ptr; // [rsp+60h] [rbp-88h]
  double v9; // [rsp+68h] [rbp-80h]
  __int64 v10; // [rsp+70h] [rbp-78h]
  unsigned int v11; // [rsp+78h] [rbp-70h]
  __int64 v12; // [rsp+88h] [rbp-60h]
  unsigned int v13; // [rsp+90h] [rbp-58h]
  __int64 v14; // [rsp+98h] [rbp-50h]
  char v15; // [rsp+A8h] [rbp-40h]
  __int64 v16; // [rsp+B8h] [rbp-30h]
  unsigned int v17; // [rsp+C0h] [rbp-28h]
  __int64 v18; // [rsp+C8h] [rbp-20h]
  __int64 v19; // [rsp+D8h] [rbp-10h]

  v19 = -2i64;
  v1 = this;
  if ( UFG::UIHKScreenCaseComplete::mCaseType == 1 )
    UFG::UIScreenRenderable::replaceTexture(
      this->mRenderable,
      "ScreenshotData",
      UFG::UIHKScreenCamera::sPhotoTarget->mTargetTexture[0]);
  v2 = v1->mRenderable->m_movie.pObject;
  pargs.pObjectInterface = 0i64;
  pargs.Type = 5;
  pargs.mValue.NValue = (double)(signed int)UFG::UIHKScreenCaseComplete::mCaseType;
  Scaleform::GFx::Movie::Invoke(v2, "Init_Case", 0i64, &pargs, 1u);
  `eh vector constructor iterator'(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  v3 = 0;
  if ( UFG::UIHKScreenCaseComplete::mNumInfo > 0 )
  {
    v4 = &unk_142431DE8;
    do
    {
      if ( (v11 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v10 + 16i64))(
          v10,
          &ptr,
          COERCE_DOUBLE(*(_QWORD *)&v9));
        v10 = 0i64;
      }
      v11 = 5;
      v9 = (double)v3;
      v5 = *((_QWORD *)v4 - 2);
      if ( (v13 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, unsigned int *, __int64))(*(_QWORD *)v12 + 16i64))(v12, &v11, v14);
        v12 = 0i64;
      }
      v13 = 6;
      v14 = v5;
      v6 = *v4;
      if ( (v17 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v16 + 16i64))(v16, &v15, v18);
        v16 = 0i64;
      }
      v17 = 2;
      LOBYTE(v18) = v6;
      Scaleform::GFx::Movie::Invoke(v2, "Set_Info", 0i64, (Scaleform::GFx::Value *)&ptr, 3u);
      ++v3;
      v4 += 48;
    }
    while ( v3 < UFG::UIHKScreenCaseComplete::mNumInfo );
  }
  `eh vector destructor iterator'(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  if ( ((unsigned int)pargs.Type >> 6) & 1 )
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      *(_QWORD *)&pargs.mValue.NValue);
}

// File Line: 324
// RVA: 0x5DA960
void __fastcall UFG::UIHKScreenCaseComplete::Flash_FlipOut(UFG::UIHKScreenCaseComplete *this)
{
  UFG::UIHKScreenCaseComplete *v1; // rbx
  unsigned int v2; // eax

  v1 = this;
  if ( !this->mFlipOut )
  {
    v2 = UFG::TiDo::CalcWwiseUid("Stop_camera_upload");
    if ( UFG::HudAudio::m_instance )
    {
      UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr, v2, 0i64, 0, 0i64);
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(
          (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
          0x374BF97Au,
          0i64,
          0,
          0i64);
    }
    Scaleform::GFx::Movie::Invoke(v1->mRenderable->m_movie.pObject, "Animate_FlipOut", 0i64, 0i64, 0);
    v1->mFlipOut = 1;
  }
}

// File Line: 350
// RVA: 0x5D4180
void __fastcall UFG::UIHKScreenCaseComplete::Bind(UFG::UIHKScreenCaseComplete *this)
{
  UFG::UIHKScreenCaseComplete *v1; // rdi
  Scaleform::GFx::Movie *v2; // rbx

  v1 = this;
  v2 = this->mRenderable->m_movie.pObject;
  Scaleform::GFx::Movie::GetVariable(v2, &this->mBioTitles, "gBioTitles");
  Scaleform::GFx::Movie::GetVariable(v2, &v1->mBioImages, "gBioImages");
  Scaleform::GFx::Movie::GetVariable(v2, &v1->mBioIntros, "gBioIntros");
  Scaleform::GFx::Movie::GetVariable(v2, &v1->mBioBodies, "gBioBodies");
  Scaleform::GFx::Movie::GetVariable(v2, &v1->mBioUnlocks, "gBioUnlocks");
}

// File Line: 363
// RVA: 0x5D55C0
void __fastcall UFG::UIHKScreenCaseComplete::ClearArrays(UFG::UIHKScreenCaseComplete *this)
{
  UFG::UIHKScreenCaseComplete *v1; // rbx

  v1 = this;
  this->mBioTitles.pObjectInterface->vfptr->RemoveElements(
    this->mBioTitles.pObjectInterface,
    *(void **)&this->mBioTitles.mValue.NValue,
    0,
    -1);
  v1->mBioImages.pObjectInterface->vfptr->RemoveElements(
    v1->mBioImages.pObjectInterface,
    v1->mBioImages.mValue.pStringManaged,
    0,
    -1);
  v1->mBioIntros.pObjectInterface->vfptr->RemoveElements(
    v1->mBioIntros.pObjectInterface,
    v1->mBioIntros.mValue.pStringManaged,
    0,
    -1);
  v1->mBioBodies.pObjectInterface->vfptr->RemoveElements(
    v1->mBioBodies.pObjectInterface,
    v1->mBioBodies.mValue.pStringManaged,
    0,
    -1);
  v1->mBioUnlocks.pObjectInterface->vfptr->RemoveElements(
    v1->mBioUnlocks.pObjectInterface,
    v1->mBioUnlocks.mValue.pStringManaged,
    0,
    -1);
}

// File Line: 373
// RVA: 0x5F4CB0
void __fastcall UFG::UIHKScreenCaseComplete::PopulateArrays(UFG::UIHKScreenCaseComplete *this)
{
  UFG::UIHKScreenCaseComplete *v1; // rsi
  unsigned int v2; // ebx
  unsigned int v3; // er14
  UFG::ProgressionTracker *v4; // rax
  UFG::ProgressionTracker *v5; // rax
  unsigned int i; // edi
  char *v7; // rcx
  char *v8; // rcx
  char *v9; // rcx
  char *v10; // rcx
  UFG::GameStatTracker *v11; // rax
  UFG::GameStatTracker *v12; // rax
  UFG::GameSaveLoad *v13; // rax
  UFG::GameStatTracker *v14; // rax
  UFG::PersistentData::MapBool *j; // rdi
  UFG::qSymbol *v16; // rax
  bool v17; // al
  char v18; // [rsp+20h] [rbp-C8h]
  __int64 v19; // [rsp+30h] [rbp-B8h]
  unsigned int v20; // [rsp+38h] [rbp-B0h]
  char *v21; // [rsp+40h] [rbp-A8h]
  char v22; // [rsp+50h] [rbp-98h]
  __int64 v23; // [rsp+60h] [rbp-88h]
  unsigned int v24; // [rsp+68h] [rbp-80h]
  char *v25; // [rsp+70h] [rbp-78h]
  __int64 v26; // [rsp+78h] [rbp-70h]
  unsigned int v27; // [rsp+80h] [rbp-68h]
  char *v28; // [rsp+88h] [rbp-60h]
  char v29; // [rsp+98h] [rbp-50h]
  __int64 v30; // [rsp+A8h] [rbp-40h]
  unsigned int v31; // [rsp+B0h] [rbp-38h]
  char *v32; // [rsp+B8h] [rbp-30h]
  __int64 v33; // [rsp+C8h] [rbp-20h]
  UFG::qString v34; // [rsp+D0h] [rbp-18h]
  UFG::qString result; // [rsp+F8h] [rbp+10h]
  UFG::qString v36; // [rsp+120h] [rbp+38h]
  UFG::qString v37; // [rsp+148h] [rbp+60h]
  UFG::qWiseSymbol vars0; // [rsp+1A0h] [rbp+B8h]

  v33 = -2i64;
  v1 = this;
  v2 = 1;
  v3 = 30;
  v4 = UFG::ProgressionTracker::Instance();
  if ( UFG::ProgressionTracker::GetActiveFlow(v4)->mUID == UFG::symGhostDLCFlow.mUID )
  {
    v2 = 31;
    v3 = 37;
  }
  else
  {
    v5 = UFG::ProgressionTracker::Instance();
    if ( UFG::ProgressionTracker::GetActiveFlow(v5)->mUID == UFG::symNewYearDLCFlow.mUID )
    {
      v2 = 38;
      v3 = 45;
    }
  }
  UFG::UIHKScreenCaseComplete::ClearArrays(v1);
  for ( i = v2; i <= v3; ++i )
  {
    v7 = UFG::qString::FormatEx(&result, "$UNLOCKABLE_BIO_TITLE_%d", i)->mData;
    v23 = 0i64;
    v24 = 6;
    v25 = v7;
    v1->mBioTitles.pObjectInterface->vfptr->PushBack(
      v1->mBioTitles.pObjectInterface,
      v1->mBioTitles.mValue.pStringManaged,
      (Scaleform::GFx::Value *)&v22);
    if ( (v24 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v23 + 16i64))(v23, &v22, v25);
      v23 = 0i64;
    }
    v24 = 0;
    UFG::qString::~qString(&result);
    v8 = UFG::qString::FormatEx(&v37, "Unlockables_Attachment_%02d", i)->mData;
    v26 = 0i64;
    v27 = 6;
    v28 = v8;
    v1->mBioImages.pObjectInterface->vfptr->PushBack(
      v1->mBioImages.pObjectInterface,
      v1->mBioImages.mValue.pStringManaged,
      (Scaleform::GFx::Value *)&v24);
    if ( (v27 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, unsigned int *, char *))(*(_QWORD *)v26 + 16i64))(v26, &v24, v28);
      v26 = 0i64;
    }
    v27 = 0;
    UFG::qString::~qString(&v37);
    v9 = UFG::qString::FormatEx(&v36, "$UNLOCKABLE_BIO_INTRO_%d", i)->mData;
    v30 = 0i64;
    v31 = 6;
    v32 = v9;
    v1->mBioIntros.pObjectInterface->vfptr->PushBack(
      v1->mBioIntros.pObjectInterface,
      v1->mBioIntros.mValue.pStringManaged,
      (Scaleform::GFx::Value *)&v29);
    if ( (v31 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v30 + 16i64))(v30, &v29, v32);
      v30 = 0i64;
    }
    v31 = 0;
    UFG::qString::~qString(&v36);
    v10 = UFG::qString::FormatEx(&v34, "$UNLOCKABLE_BIO_%d", i)->mData;
    v19 = 0i64;
    v20 = 6;
    v21 = v10;
    v1->mBioBodies.pObjectInterface->vfptr->PushBack(
      v1->mBioBodies.pObjectInterface,
      v1->mBioBodies.mValue.pStringManaged,
      (Scaleform::GFx::Value *)&v18);
    if ( (v20 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v19 + 16i64))(v19, &v18, v21);
      v19 = 0i64;
    }
    v20 = 0;
    UFG::qString::~qString(&v34);
  }
  v11 = UFG::GameStatTracker::Instance();
  if ( (unsigned __int8)UFG::GameStatTracker::GetStat(v11, Collectible_Bio_New) )
  {
    v12 = UFG::GameStatTracker::Instance();
    UFG::GameStatTracker::SetStat(v12, Collectible_Bio_New, 0);
    v13 = UFG::GameSaveLoad::Instance();
    UFG::GameSaveLoad::SaveAutoGameSlot(v13);
  }
  v14 = UFG::GameStatTracker::Instance();
  for ( j = UFG::GameStatTracker::GetMapBool(v14, Collectible_Bio); v2 <= v3; ++v2 )
  {
    v16 = (UFG::qSymbol *)UFG::qSymbol::qSymbol(&vars0, v2);
    v17 = UFG::PersistentData::MapBool::GetStatus(j, v16);
    v19 = 0i64;
    v20 = 2;
    LOBYTE(v21) = v17;
    v1->mBioUnlocks.pObjectInterface->vfptr->PushBack(
      v1->mBioUnlocks.pObjectInterface,
      v1->mBioUnlocks.mValue.pStringManaged,
      (Scaleform::GFx::Value *)&v18);
    if ( (v20 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v19 + 16i64))(v19, &v18, v21);
      v19 = 0i64;
    }
    v20 = 0;
  }
}

// File Line: 411
// RVA: 0x5E6B20
__int64 __fastcall UFG::UIHKScreenCaseComplete::GetBiosIndex(UFG::UIHKScreenCaseComplete *this)
{
  Scaleform::GFx::Movie *v1; // rcx
  double v2; // xmm6_8
  __int64 result; // rax
  Scaleform::GFx::Value pval; // [rsp+28h] [rbp-50h]

  v1 = this->mRenderable->m_movie.pObject;
  pval.pObjectInterface = 0i64;
  pval.Type = 133;
  pval.mValue.NValue = 0.0;
  Scaleform::GFx::Movie::GetVariable(v1, &pval, "gBiosIndex");
  if ( (pval.Type & 0x8F) == 5 )
  {
    v2 = pval.mValue.NValue;
    if ( ((unsigned int)pval.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pval.pObjectInterface->vfptr->gap8[8])(
        pval.pObjectInterface,
        &pval,
        *(_QWORD *)&pval.mValue.NValue);
      pval.pObjectInterface = 0i64;
    }
    result = (unsigned int)(signed int)v2;
  }
  else
  {
    if ( ((unsigned int)pval.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pval.pObjectInterface->vfptr->gap8[8])(
        pval.pObjectInterface,
        &pval,
        *(_QWORD *)&pval.mValue.NValue);
      pval.pObjectInterface = 0i64;
    }
    result = (unsigned int)(signed int)0.0;
  }
  return result;
}

