// File Line: 28
// RVA: 0x1570B60
__int64 UFG::_dynamic_initializer_for__symGhostDLCFlow__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("DLC_Ghost", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symGhostDLCFlow, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__symGhostDLCFlow__);
}

// File Line: 29
// RVA: 0x1570C20
__int64 UFG::_dynamic_initializer_for__symNewYearDLCFlow__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("DLC_CNY", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symNewYearDLCFlow, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__symNewYearDLCFlow__);
}

// File Line: 38
// RVA: 0x1566D80
__int64 dynamic_initializer_for__UFG::UIHKScreenCaseComplete::gBiosTexturePackFilename__()
{
  UFG::qString::qString(&UFG::UIHKScreenCaseComplete::gBiosTexturePackFilename);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::UIHKScreenCaseComplete::gBiosTexturePackFilename__);
}

// File Line: 39
// RVA: 0x1567190
__int64 dynamic_initializer_for__UFG::UIHKScreenCaseComplete::mInfo__()
{
  `eh vector constructor iterator(
    (char *)&UFG::UIHKScreenCaseComplete::mInfo,
    0x30ui64,
    5,
    (void (__fastcall *)(void *))UFG::PersistentData::String::String);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::UIHKScreenCaseComplete::mInfo__);
}

// File Line: 45
// RVA: 0x5F1960
void __fastcall UFG::UIHKScreenCaseComplete::LoadTextures(
        UFG::qReflectInventoryBase *callback,
        UFG::qReflectInventoryBase *callbackParam)
{
  UFG::UIScreenTextureManager *v4; // rax
  UFG::UIScreenTextureManager *v5; // rax

  v4 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::QueueTexturePackLoad(
    v4,
    UFG::UIHKScreenCaseComplete::gTexturePackFilename,
    HIGH_PRIORITY,
    callback,
    callbackParam);
  if ( UFG::UIHKScreenCaseComplete::mCaseType == CASE_TYPE_BIOS )
  {
    UFG::UIHKScreenCaseComplete::QueryBiosTexturePackFilename();
    v5 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::QueueTexturePackLoad(
      v5,
      UFG::UIHKScreenCaseComplete::gBiosTexturePackFilename.mData,
      HIGH_PRIORITY,
      callback,
      callbackParam);
  }
}

// File Line: 54
// RVA: 0x5D4030
bool __fastcall UFG::UIHKScreenCaseComplete::AreTexturesLoaded()
{
  UFG::UIScreenTextureManager *v0; // rax
  bool IsTexturePackLoaded; // bl
  UFG::UIScreenTextureManager *v2; // rax

  v0 = UFG::UIScreenTextureManager::Instance();
  IsTexturePackLoaded = UFG::UIScreenTextureManager::IsTexturePackLoaded(
                          v0,
                          UFG::UIHKScreenCaseComplete::gTexturePackFilename);
  if ( UFG::UIHKScreenCaseComplete::mCaseType != CASE_TYPE_BIOS )
    return IsTexturePackLoaded;
  v2 = UFG::UIScreenTextureManager::Instance();
  return IsTexturePackLoaded & UFG::UIScreenTextureManager::IsTexturePackLoaded(
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
  if ( UFG::UIHKScreenCaseComplete::mCaseType == CASE_TYPE_BIOS )
  {
    v1 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::ReleaseTexturePack(v1, UFG::UIHKScreenCaseComplete::gBiosTexturePackFilename.mData);
  }
  UFG::UIHKScreenCaseComplete::mCaseType = CASE_TYPE_UNKNOWN;
}

// File Line: 73
// RVA: 0x5FE950
void UFG::UIHKScreenCaseComplete::QueryBiosTexturePackFilename(void)
{
  UFG::ProgressionTracker *v0; // rax
  UFG::ProgressionTracker *v1; // rax
  UFG::qSymbol *ActiveFlow; // rax
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
    ActiveFlow = UFG::ProgressionTracker::GetActiveFlow(v1);
    v3 = "Data\\UI\\unlockables_texturepack_DLC_2.perm.bin";
    if ( ActiveFlow->mUID != UFG::symNewYearDLCFlow.mUID )
      v3 = "Data\\UI\\unlockables_texturepack.perm.bin";
    UFG::qString::Set(&UFG::UIHKScreenCaseComplete::gBiosTexturePackFilename, v3);
  }
}

// File Line: 94
// RVA: 0x5C4A80
void __fastcall UFG::UIHKScreenCaseComplete::UIHKScreenCaseComplete(UFG::UIHKScreenCaseComplete *this)
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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenCaseComplete::`vftable;
  *(_WORD *)&this->mIntroAnimComplete = 0;
  this->mFlipOut = 0;
  this->mBioTitles.pObjectInterface = 0i64;
  this->mBioTitles.Type = VT_Undefined;
  this->mBioImages.pObjectInterface = 0i64;
  this->mBioImages.Type = VT_Undefined;
  this->mBioIntros.pObjectInterface = 0i64;
  this->mBioIntros.Type = VT_Undefined;
  this->mBioBodies.pObjectInterface = 0i64;
  this->mBioBodies.Type = VT_Undefined;
  this->mBioUnlocks.pObjectInterface = 0i64;
  this->mBioUnlocks.Type = VT_Undefined;
  if ( (unsigned int)(UFG::UIHKScreenCaseComplete::mCaseType - 2) <= 1 )
    UFG::ActivateInputSubMode(ISM_LIMITED, UFG::gActiveControllerNum);
}

// File Line: 103
// RVA: 0x5CA140
void __fastcall UFG::UIHKScreenCaseComplete::~UIHKScreenCaseComplete(UFG::UIHKScreenCaseComplete *this)
{
  UFG::qString *v2; // rbx
  unsigned int v3; // eax
  UFG::UIScreenTextureManager *v4; // rax

  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenCaseComplete::`vftable;
  v2 = &UFG::UIHKScreenCaseComplete::mInfo;
  do
  {
    UFG::qString::Set(v2, &customCaption);
    LOBYTE(v2[1].mPrev) = 0;
    v2 = (UFG::qString *)((char *)v2 + 48);
  }
  while ( (__int64)v2 < (__int64)&UI_HASH_BUTTON_SELECT_RELEASED_30 );
  UFG::UIHKScreenCaseComplete::mNumInfo = 0;
  if ( (unsigned int)(UFG::UIHKScreenCaseComplete::mCaseType - 1) <= 1 )
  {
    v3 = UFG::TiDo::CalcWwiseUid("Stop_camera_upload");
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, v3, 0i64, 0, 0i64);
  }
  if ( UFG::UIHKScreenCaseComplete::mCaseType != CASE_TYPE_BIOS )
    UFG::UIHKScreenHud::ClearPDACache();
  v4 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v4, "CaseComplete");
  if ( UFG::UIHKScreenCamera::sPhotoTarget )
  {
    Illusion::DeleteTarget((AMD_HD3D *)UFG::UIHKScreenCamera::sPhotoTarget, 1);
    UFG::UIHKScreenCamera::sPhotoTarget = 0i64;
  }
  UFG::DeactivateInputSubMode(ISM_LIMITED, UFG::gActiveControllerNum);
  if ( (this->mBioUnlocks.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&this->mBioUnlocks.pObjectInterface->vfptr->gap8[8])(
      this->mBioUnlocks.pObjectInterface,
      &this->mBioUnlocks,
      this->mBioUnlocks.mValue);
    this->mBioUnlocks.pObjectInterface = 0i64;
  }
  this->mBioUnlocks.Type = VT_Undefined;
  if ( (this->mBioBodies.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&this->mBioBodies.pObjectInterface->vfptr->gap8[8])(
      this->mBioBodies.pObjectInterface,
      &this->mBioBodies,
      this->mBioBodies.mValue);
    this->mBioBodies.pObjectInterface = 0i64;
  }
  this->mBioBodies.Type = VT_Undefined;
  if ( (this->mBioIntros.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&this->mBioIntros.pObjectInterface->vfptr->gap8[8])(
      this->mBioIntros.pObjectInterface,
      &this->mBioIntros,
      this->mBioIntros.mValue);
    this->mBioIntros.pObjectInterface = 0i64;
  }
  this->mBioIntros.Type = VT_Undefined;
  if ( (this->mBioImages.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&this->mBioImages.pObjectInterface->vfptr->gap8[8])(
      this->mBioImages.pObjectInterface,
      &this->mBioImages,
      this->mBioImages.mValue);
    this->mBioImages.pObjectInterface = 0i64;
  }
  this->mBioImages.Type = VT_Undefined;
  if ( (this->mBioTitles.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&this->mBioTitles.pObjectInterface->vfptr->gap8[8])(
      this->mBioTitles.pObjectInterface,
      &this->mBioTitles,
      this->mBioTitles.mValue);
    this->mBioTitles.pObjectInterface = 0i64;
  }
  this->mBioTitles.Type = VT_Undefined;
  UFG::UIScreen::~UIScreen(this);
}

// File Line: 126
// RVA: 0x630050
void __fastcall UFG::UIHKScreenCaseComplete::init(UFG::UIHKScreenCaseComplete *this, UFG::UICommandData *data)
{
  UFG::UIScreen::init(this, data);
  *(_WORD *)&this->mIntroAnimComplete = 0;
  this->mFlipOut = 0;
  if ( UFG::UIHKScreenCaseComplete::mCaseType == CASE_TYPE_BIOS )
  {
    UFG::UIHKScreenCaseComplete::Bind(this);
    UFG::UIHKScreenCaseComplete::PopulateArrays(this);
  }
  UFG::UIHKScreenCaseComplete::Flash_Init(this);
}

// File Line: 149
// RVA: 0x6219E0
bool __fastcall UFG::UIHKScreenCaseComplete::handleMessage(
        UFG::UIHKScreenCaseComplete *this,
        unsigned int msgId,
        UFG::UIMessage *msg)
{
  unsigned int v7; // eax
  UFG::HudAudio *v8; // rcx
  unsigned int v9; // edx
  unsigned int v10; // eax
  unsigned int BiosIndex; // eax
  bool v12; // r14
  bool v13; // al
  bool mInBio; // r14
  bool v15; // al
  UFG::qString v16; // [rsp+20h] [rbp-21h] BYREF
  Scaleform::GFx::Value pargs; // [rsp+50h] [rbp+Fh] BYREF

  if ( msgId == UI_HASH_GAME_OVER_20 )
  {
    UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, this->mScreenUID);
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
      UFG::AudioEntity::CreateAndPlayEvent(v8, v9, 0i64, 0, 0i64);
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
    UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, this->mScreenUID);
    goto LABEL_22;
  }
  if ( msgId == UI_HASH_PDA_CAMERA_DESTROY_20 )
  {
    if ( UFG::UIHKScreenCaseComplete::mCaseType != CASE_TYPE_BIOS )
      goto LABEL_55;
    UFG::UIHKScreenHud::ClearPDACache();
    UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, this->mScreenUID);
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
    if ( UFG::UIHKScreenCaseComplete::mCaseType == CASE_TYPE_BIOS )
    {
      if ( msgId == UI_HASH_DPAD_UP_PRESSED_30 || msgId == UI_HASH_DPAD_UP_REPEAT_30 )
      {
        if ( !this->mInBio && v8 )
          UFG::AudioEntity::CreateAndPlayEvent(v8, 0x4F717979u, 0i64, 0, 0i64);
        *(_QWORD *)&v16.mMagic = 0i64;
        LODWORD(v16.mData) = 0;
        mInBio = this->mInBio;
        LODWORD(v16.mData) = 2;
        LOBYTE(v16.mStringHash32) = mInBio;
        v15 = this->mInBio;
        pargs.pObjectInterface = 0i64;
        pargs.Type = VT_Boolean;
        pargs.mValue.BValue = v15;
        Scaleform::GFx::Movie::Invoke(this->mRenderable->m_movie.pObject, "BiosList_ScrollUp", 0i64, &pargs, 1u);
        if ( (pargs.Type & 0x40) != 0 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
            pargs.pObjectInterface,
            &pargs,
            pargs.mValue);
          pargs.pObjectInterface = 0i64;
        }
        pargs.Type = VT_Undefined;
        goto LABEL_52;
      }
      if ( msgId == UI_HASH_DPAD_DOWN_PRESSED_30 || msgId == UI_HASH_DPAD_DOWN_REPEAT_30 )
      {
        if ( !this->mInBio && v8 )
          UFG::AudioEntity::CreateAndPlayEvent(v8, 0x4F717979u, 0i64, 0, 0i64);
        *(_QWORD *)&v16.mMagic = 0i64;
        LODWORD(v16.mData) = 0;
        v12 = this->mInBio;
        LODWORD(v16.mData) = 2;
        LOBYTE(v16.mStringHash32) = v12;
        v13 = this->mInBio;
        pargs.pObjectInterface = 0i64;
        pargs.Type = VT_Boolean;
        pargs.mValue.BValue = v13;
        Scaleform::GFx::Movie::Invoke(this->mRenderable->m_movie.pObject, "BiosList_ScrollDown", 0i64, &pargs, 1u);
        if ( (pargs.Type & 0x40) != 0 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
            pargs.pObjectInterface,
            &pargs,
            pargs.mValue);
          pargs.pObjectInterface = 0i64;
        }
        pargs.Type = VT_Undefined;
        goto LABEL_52;
      }
      if ( msgId == UI_HASH_BUTTON_ACCEPT_RELEASED_30 )
      {
        if ( !this->mInBio )
        {
          BiosIndex = UFG::UIHKScreenCaseComplete::GetBiosIndex(this);
          *(_QWORD *)&v16.mMagic = 0i64;
          LODWORD(v16.mData) = 0;
          this->mBioUnlocks.pObjectInterface->vfptr->GetElement(
            this->mBioUnlocks.pObjectInterface,
            (void *)this->mBioUnlocks.mValue.pString,
            BiosIndex,
            (Scaleform::GFx::Value *)&v16);
          if ( LOBYTE(v16.mStringHash32) == 1 )
          {
            if ( UFG::HudAudio::m_instance )
              UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x9E75334E, 0i64, 0, 0i64);
            Scaleform::GFx::Movie::Invoke(this->mRenderable->m_movie.pObject, "Bios_Select", 0i64, 0i64, 0);
            this->mInBio = 1;
          }
LABEL_52:
          if ( ((__int64)v16.mData & 0x40) != 0 )
          {
            (*(void (__fastcall **)(_QWORD, UFG::qString *, _QWORD))(**(_QWORD **)&v16.mMagic + 16i64))(
              *(_QWORD *)&v16.mMagic,
              &v16,
              *(_QWORD *)&v16.mStringHash32);
            *(_QWORD *)&v16.mMagic = 0i64;
          }
          LODWORD(v16.mData) = 0;
        }
        return UFG::UIScreen::handleMessage(this, msgId, msg);
      }
      if ( msgId != UI_HASH_BUTTON_BACK_RELEASED_30 )
        return UFG::UIScreen::handleMessage(this, msgId, msg);
      if ( this->mInBio )
      {
        if ( v8 )
          UFG::AudioEntity::CreateAndPlayEvent(v8, 0x4AAC5E6Bu, 0i64, 0, 0i64);
        Scaleform::GFx::Movie::Invoke(this->mRenderable->m_movie.pObject, "Bios_Back", 0i64, 0i64, 0);
        this->mInBio = 0;
        return UFG::UIScreen::handleMessage(this, msgId, msg);
      }
LABEL_57:
      UFG::UIHKScreenCaseComplete::Flash_FlipOut(this);
      return UFG::UIScreen::handleMessage(this, msgId, msg);
    }
LABEL_55:
    if ( !this->mIntroAnimComplete || msgId != UI_HASH_BUTTON_ACCEPT_RELEASED_30 )
      return UFG::UIScreen::handleMessage(this, msgId, msg);
    goto LABEL_57;
  }
  UFG::qString::qString(&v16, (UFG::qString *)&msg[1]);
  v10 = UFG::TiDo::CalcWwiseUid(v16.mData);
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, v10, 0i64, 0, 0i64);
  UFG::qString::~qString(&v16);
  return 1;
}

// File Line: 258
// RVA: 0x5D1E70
void __fastcall UFG::UIHKScreenCaseComplete::AddInfo(const char *caption, bool completed)
{
  int v3; // edx

  if ( UFG::UIHKScreenCaseComplete::mNumInfo < 5 )
  {
    UFG::qString::Set(
      (UFG::qString *)((char *)&UFG::UIHKScreenCaseComplete::mInfo + 48 * UFG::UIHKScreenCaseComplete::mNumInfo),
      caption);
    v3 = UFG::UIHKScreenCaseComplete::mNumInfo + 1;
    *((_BYTE *)&UFG::UIHKScreenCaseComplete::mInfo + 48 * UFG::UIHKScreenCaseComplete::mNumInfo + 40) = completed;
    UFG::UIHKScreenCaseComplete::mNumInfo = v3;
  }
}

// File Line: 298
// RVA: 0x5DBF70
void __fastcall UFG::UIHKScreenCaseComplete::Flash_Init(UFG::UIHKScreenCaseComplete *this)
{
  Scaleform::GFx::Movie *pObject; // r14
  int v3; // edi
  _BYTE *v4; // rbx
  __int64 v5; // rsi
  char v6; // si
  Scaleform::GFx::Value pargs; // [rsp+30h] [rbp-B8h] BYREF
  Scaleform::GFx::Value ptr; // [rsp+60h] [rbp-88h] BYREF
  int v9; // [rsp+90h] [rbp-58h]
  __int64 v10; // [rsp+98h] [rbp-50h]
  char v11[16]; // [rsp+A8h] [rbp-40h] BYREF
  __int64 v12; // [rsp+B8h] [rbp-30h]
  int v13; // [rsp+C0h] [rbp-28h]
  __int64 v14; // [rsp+C8h] [rbp-20h]
  __int64 v15; // [rsp+D8h] [rbp-10h]

  v15 = -2i64;
  if ( UFG::UIHKScreenCaseComplete::mCaseType == CASE_TYPE_PHOTO )
    UFG::UIScreenRenderable::replaceTexture(
      this->mRenderable,
      "ScreenshotData",
      UFG::UIHKScreenCamera::sPhotoTarget->mTargetTexture[0]);
  pObject = this->mRenderable->m_movie.pObject;
  pargs.pObjectInterface = 0i64;
  pargs.Type = VT_Number;
  pargs.mValue.NValue = (double)(int)UFG::UIHKScreenCaseComplete::mCaseType;
  Scaleform::GFx::Movie::Invoke(pObject, "Init_Case", 0i64, &pargs, 1u);
  `eh vector constructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  v3 = 0;
  if ( UFG::UIHKScreenCaseComplete::mNumInfo > 0 )
  {
    v4 = &unk_142431DE8;
    do
    {
      if ( (ptr.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value *))&ptr.pObjectInterface->vfptr->gap8[8])(
          ptr.pObjectInterface,
          &ptr,
          ptr.pNext);
        ptr.pObjectInterface = 0i64;
      }
      ptr.Type = VT_Number;
      *(double *)&ptr.pNext = (double)v3;
      v5 = *((_QWORD *)v4 - 2);
      if ( (v9 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(unsigned __int64, Scaleform::GFx::Value::ValueType *, __int64))(*(_QWORD *)ptr.DataAux
                                                                                              + 16i64))(
          ptr.DataAux,
          &ptr.Type,
          v10);
        ptr.DataAux = 0i64;
      }
      v9 = 6;
      v10 = v5;
      v6 = *v4;
      if ( (v13 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v12 + 16i64))(v12, v11, v14);
        v12 = 0i64;
      }
      v13 = 2;
      LOBYTE(v14) = v6;
      Scaleform::GFx::Movie::Invoke(pObject, "Set_Info", 0i64, &ptr, 3u);
      ++v3;
      v4 += 48;
    }
    while ( v3 < UFG::UIHKScreenCaseComplete::mNumInfo );
  }
  `eh vector destructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  if ( (pargs.Type & 0x40) != 0 )
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      pargs.mValue);
}

// File Line: 324
// RVA: 0x5DA960
void __fastcall UFG::UIHKScreenCaseComplete::Flash_FlipOut(UFG::UIHKScreenCaseComplete *this)
{
  unsigned int v2; // eax

  if ( !this->mFlipOut )
  {
    v2 = UFG::TiDo::CalcWwiseUid("Stop_camera_upload");
    if ( UFG::HudAudio::m_instance )
    {
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, v2, 0i64, 0, 0i64);
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x374BF97Au, 0i64, 0, 0i64);
    }
    Scaleform::GFx::Movie::Invoke(this->mRenderable->m_movie.pObject, "Animate_FlipOut", 0i64, 0i64, 0);
    this->mFlipOut = 1;
  }
}

// File Line: 350
// RVA: 0x5D4180
void __fastcall UFG::UIHKScreenCaseComplete::Bind(UFG::UIHKScreenCaseComplete *this)
{
  Scaleform::GFx::Movie *pObject; // rbx

  pObject = this->mRenderable->m_movie.pObject;
  Scaleform::GFx::Movie::GetVariable(pObject, &this->mBioTitles, "gBioTitles");
  Scaleform::GFx::Movie::GetVariable(pObject, &this->mBioImages, "gBioImages");
  Scaleform::GFx::Movie::GetVariable(pObject, &this->mBioIntros, "gBioIntros");
  Scaleform::GFx::Movie::GetVariable(pObject, &this->mBioBodies, "gBioBodies");
  Scaleform::GFx::Movie::GetVariable(pObject, &this->mBioUnlocks, "gBioUnlocks");
}

// File Line: 363
// RVA: 0x5D55C0
void __fastcall UFG::UIHKScreenCaseComplete::ClearArrays(UFG::UIHKScreenCaseComplete *this)
{
  this->mBioTitles.pObjectInterface->vfptr->RemoveElements(
    this->mBioTitles.pObjectInterface,
    (void *)this->mBioTitles.mValue.pString,
    0,
    -1);
  this->mBioImages.pObjectInterface->vfptr->RemoveElements(
    this->mBioImages.pObjectInterface,
    (void *)this->mBioImages.mValue.pString,
    0,
    -1);
  this->mBioIntros.pObjectInterface->vfptr->RemoveElements(
    this->mBioIntros.pObjectInterface,
    (void *)this->mBioIntros.mValue.pString,
    0,
    -1);
  this->mBioBodies.pObjectInterface->vfptr->RemoveElements(
    this->mBioBodies.pObjectInterface,
    (void *)this->mBioBodies.mValue.pString,
    0,
    -1);
  this->mBioUnlocks.pObjectInterface->vfptr->RemoveElements(
    this->mBioUnlocks.pObjectInterface,
    (void *)this->mBioUnlocks.mValue.pString,
    0,
    -1);
}

// File Line: 373
// RVA: 0x5F4CB0
void __fastcall UFG::UIHKScreenCaseComplete::PopulateArrays(UFG::UIHKScreenCaseComplete *this)
{
  unsigned int v2; // ebx
  unsigned int v3; // r14d
  UFG::ProgressionTracker *v4; // rax
  UFG::ProgressionTracker *v5; // rax
  unsigned int i; // edi
  char *mData; // rcx
  char *v8; // rcx
  char *v9; // rcx
  char *v10; // rcx
  UFG::GameStatTracker *v11; // rax
  UFG::GameStatTracker *v12; // rax
  UFG::GameSaveLoad *v13; // rax
  UFG::GameStatTracker *v14; // rax
  UFG::PersistentData::MapBool *j; // rdi
  UFG::qSymbol *v16; // rax
  bool Status; // al
  char v18[16]; // [rsp+20h] [rbp-C8h] BYREF
  __int64 v19; // [rsp+30h] [rbp-B8h]
  int v20; // [rsp+38h] [rbp-B0h]
  char *v21; // [rsp+40h] [rbp-A8h]
  char v22[16]; // [rsp+50h] [rbp-98h] BYREF
  __int64 v23; // [rsp+60h] [rbp-88h]
  int v24; // [rsp+68h] [rbp-80h] BYREF
  char *v25; // [rsp+70h] [rbp-78h]
  __int64 v26; // [rsp+78h] [rbp-70h]
  int v27; // [rsp+80h] [rbp-68h]
  char *v28; // [rsp+88h] [rbp-60h]
  char v29[16]; // [rsp+98h] [rbp-50h] BYREF
  __int64 v30; // [rsp+A8h] [rbp-40h]
  int v31; // [rsp+B0h] [rbp-38h]
  char *v32; // [rsp+B8h] [rbp-30h]
  __int64 v33; // [rsp+C8h] [rbp-20h]
  UFG::qString v34; // [rsp+D0h] [rbp-18h] BYREF
  UFG::qString result; // [rsp+F8h] [rbp+10h] BYREF
  UFG::qString v36; // [rsp+120h] [rbp+38h] BYREF
  UFG::qString v37; // [rsp+148h] [rbp+60h] BYREF
  UFG::qWiseSymbol vars0; // [rsp+1A0h] [rbp+B8h] BYREF

  v33 = -2i64;
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
  UFG::UIHKScreenCaseComplete::ClearArrays(this);
  for ( i = v2; i <= v3; ++i )
  {
    mData = UFG::qString::FormatEx(&result, "$UNLOCKABLE_BIO_TITLE_%d", i)->mData;
    v23 = 0i64;
    v24 = 6;
    v25 = mData;
    this->mBioTitles.pObjectInterface->vfptr->PushBack(
      this->mBioTitles.pObjectInterface,
      (void *)this->mBioTitles.mValue.pString,
      (Scaleform::GFx::Value *)v22);
    if ( (v24 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v23 + 16i64))(v23, v22, v25);
      v23 = 0i64;
    }
    v24 = 0;
    UFG::qString::~qString(&result);
    v8 = UFG::qString::FormatEx(&v37, "Unlockables_Attachment_%02d", i)->mData;
    v26 = 0i64;
    v27 = 6;
    v28 = v8;
    this->mBioImages.pObjectInterface->vfptr->PushBack(
      this->mBioImages.pObjectInterface,
      (void *)this->mBioImages.mValue.pString,
      (Scaleform::GFx::Value *)&v24);
    if ( (v27 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, int *, char *))(*(_QWORD *)v26 + 16i64))(v26, &v24, v28);
      v26 = 0i64;
    }
    v27 = 0;
    UFG::qString::~qString(&v37);
    v9 = UFG::qString::FormatEx(&v36, "$UNLOCKABLE_BIO_INTRO_%d", i)->mData;
    v30 = 0i64;
    v31 = 6;
    v32 = v9;
    this->mBioIntros.pObjectInterface->vfptr->PushBack(
      this->mBioIntros.pObjectInterface,
      (void *)this->mBioIntros.mValue.pString,
      (Scaleform::GFx::Value *)v29);
    if ( (v31 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v30 + 16i64))(v30, v29, v32);
      v30 = 0i64;
    }
    v31 = 0;
    UFG::qString::~qString(&v36);
    v10 = UFG::qString::FormatEx(&v34, "$UNLOCKABLE_BIO_%d", i)->mData;
    v19 = 0i64;
    v20 = 6;
    v21 = v10;
    this->mBioBodies.pObjectInterface->vfptr->PushBack(
      this->mBioBodies.pObjectInterface,
      (void *)this->mBioBodies.mValue.pString,
      (Scaleform::GFx::Value *)v18);
    if ( (v20 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v19 + 16i64))(v19, v18, v21);
      v19 = 0i64;
    }
    v20 = 0;
    UFG::qString::~qString(&v34);
  }
  v11 = UFG::GameStatTracker::Instance();
  if ( UFG::GameStatTracker::GetStat(v11, Collectible_Bio_New) )
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
    Status = UFG::PersistentData::MapBool::GetStatus(j, v16);
    v19 = 0i64;
    v20 = 2;
    LOBYTE(v21) = Status;
    this->mBioUnlocks.pObjectInterface->vfptr->PushBack(
      this->mBioUnlocks.pObjectInterface,
      (void *)this->mBioUnlocks.mValue.pString,
      (Scaleform::GFx::Value *)v18);
    if ( (v20 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v19 + 16i64))(v19, v18, v21);
      v19 = 0i64;
    }
    v20 = 0;
  }
}

// File Line: 411
// RVA: 0x5E6B20
__int64 __fastcall UFG::UIHKScreenCaseComplete::GetBiosIndex(UFG::UIHKScreenCaseComplete *this)
{
  Scaleform::GFx::Movie *pObject; // rcx
  double NValue; // xmm6_8
  Scaleform::GFx::Value pval; // [rsp+28h] [rbp-50h] BYREF

  pObject = this->mRenderable->m_movie.pObject;
  pval.pObjectInterface = 0i64;
  pval.Type = VT_ConvertNumber;
  pval.mValue.pString = 0i64;
  Scaleform::GFx::Movie::GetVariable(pObject, &pval, "gBiosIndex");
  if ( (pval.Type & 0x8F) == 5 )
  {
    NValue = pval.mValue.NValue;
    if ( (pval.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pval.pObjectInterface->vfptr->gap8[8])(
        pval.pObjectInterface,
        &pval,
        pval.mValue);
      pval.pObjectInterface = 0i64;
    }
    return (unsigned int)(int)NValue;
  }
  else
  {
    if ( (pval.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pval.pObjectInterface->vfptr->gap8[8])(
        pval.pObjectInterface,
        &pval,
        pval.mValue);
      pval.pObjectInterface = 0i64;
    }
    return (unsigned int)(int)0.0;
  }
}

