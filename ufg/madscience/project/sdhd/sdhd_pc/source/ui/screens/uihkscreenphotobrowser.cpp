// File Line: 68
// RVA: 0x5C6CA0
void __fastcall UFG::UIHKScreenPhotoBrowser::UIHKScreenPhotoBrowser(UFG::UIHKScreenPhotoBrowser *this)
{
  this->mPrev = &this->UFG::qNode<UFG::UIScreen,UFG::UIScreen>;
  this->mNext = &this->UFG::qNode<UFG::UIScreen,UFG::UIScreen>;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIScreen::`vftable;
  this->m_screenNameHash = 0;
  this->UFG::UIScreen::mRenderable = 0i64;
  this->mLoadThread = 0i64;
  this->mScreenUID = -1;
  *(_QWORD *)&this->mControllerMask = 15i64;
  *(_QWORD *)&this->mPriority = 0i64;
  this->mDimToApplyType = eDIM_INVALID;
  *(_QWORD *)&this->mCurDimValue = 1120403456i64;
  this->m_screenName[0] = 0;
  --this->mInputEnabled;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenPhotoBrowser::`vftable;
  *(_QWORD *)&this->mState = 0i64;
  *(_QWORD *)&this->mOffset = 0i64;
  *(_QWORD *)&this->mLastPicLoaded = -1i64;
  this->mPicLoadIndex = 0;
  this->mMovie = 0i64;
  this->mPhotoLoaded.rawData = 0i64;
  this->mPhotoLoaded.size = 0;
  this->mPhotoLoaded.saveFileIndex = -1;
  *(_WORD *)&this->mShouldPushHUD = 1;
  this->mTexture0 = 0i64;
}

// File Line: 74
// RVA: 0x5CC1C0
void __fastcall UFG::UIHKScreenPhotoBrowser::~UIHKScreenPhotoBrowser(UFG::UIHKScreenPhotoBrowser *this)
{
  unsigned int v2; // eax
  UFG::UIScreenTextureManager *v3; // rax
  Illusion::Texture *mTexture0; // rcx

  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenPhotoBrowser::`vftable;
  if ( UFG::gInputSystem )
  {
    if ( UFG::gActiveControllerNum != -1 )
    {
      v2 = UFG::UI::gUIInputLocked;
      if ( !UFG::UI::gUIInputLocked || (--UFG::UI::gUIInputLocked, v2 == 1) )
        UFG::UI::ResetGameplayInput((UFG::UI *)this);
    }
  }
  v3 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v3, "PhotoBrowser");
  operator delete[](this->mPhotoLoaded.rawData);
  this->mPhotoLoaded.rawData = 0i64;
  mTexture0 = this->mTexture0;
  if ( mTexture0 )
  {
    Illusion::Factory::QueueDelete(mTexture0);
    this->mTexture0 = 0i64;
  }
  UFG::UIScreen::~UIScreen(this);
}

// File Line: 97
// RVA: 0x635680
void __fastcall UFG::UIHKScreenPhotoBrowser::init(UFG::UIHKScreenPhotoBrowser *this, UFG::UICommandData *data)
{
  UFG::Controller *v3; // rcx
  UFG::allocator::free_link *v4; // rax
  UFG::UIScreenRenderable *mRenderable; // rcx
  Scaleform::GFx::Movie *pObject; // rcx

  UFG::UIScreen::init(this, data);
  this->mRenderable = this->UFG::UIScreen::mRenderable;
  if ( UFG::gInputSystem && UFG::gActiveControllerNum != -1 )
  {
    v3 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum];
    if ( !UFG::UI::gUIInputLocked )
      g_saved_gameplay_controller_mode = v3->m_ActiveMapSet;
    UFG::SetInputMode(IM_UI_ONLY, v3->mControllerIndex);
    ++UFG::UI::gUIInputLocked;
  }
  v4 = UFG::qMalloc(0xC350ui64, "PhotoBrowser", 0i64);
  mRenderable = this->mRenderable;
  this->mPhotoLoaded.rawData = v4;
  if ( mRenderable )
  {
    pObject = mRenderable->m_movie.pObject;
    if ( pObject )
      Scaleform::GFx::Movie::Invoke(pObject, "PhotoList_StartLoadingAnimation", 0i64, 0i64, 0);
  }
  UFG::UIHKScreenPhotoBrowser::InitialPhotoLoad(this);
  UFG::UIHKScreenPhotoBrowser::UpdateArrows(this);
  UFG::UIHKScreenPhotoBrowser::UpdateCounter(this);
  this->mState = STATE_NORMAL;
}

// File Line: 121
// RVA: 0x5ED750
void __fastcall UFG::UIHKScreenPhotoBrowser::InitialPhotoLoad(UFG::UIHKScreenPhotoBrowser *this)
{
  int v2; // ebx
  UFG::GameSaveLoad *v3; // rax
  UFG::GameSaveLoad *v4; // rax

  v2 = this->mLastPicLoaded + 1;
  if ( v2 < 1 )
  {
    while ( 1 )
    {
      v3 = UFG::GameSaveLoad::Instance();
      if ( UFG::GameSaveLoad::DoesPhotoExists(v3, v2) )
        break;
      if ( ++v2 >= 1 )
        return;
    }
    v4 = UFG::GameSaveLoad::Instance();
    UFG::GameSaveLoad::LoadPhoto(v4, v2);
    this->mLastPicLoaded = v2;
  }
}

// File Line: 150
// RVA: 0x6125B0
void __fastcall UFG::UIHKScreenPhotoBrowser::StopLoadingAnim(UFG::UIHKScreenPhotoBrowser *this)
{
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-40h] BYREF

  pObject = this->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    value.pObjectInterface = 0i64;
    value.Type = VT_Boolean;
    value.mValue.BValue = 0;
    Scaleform::GFx::Movie::SetVariable(pObject, "mcLoadingIcon._visible", &value, 1i64);
    if ( (value.Type & 0x40) != 0 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        value.mValue);
  }
}

// File Line: 162
// RVA: 0x5F0D50
char __fastcall UFG::UIHKScreenPhotoBrowser::LoadNextPhoto(UFG::UIHKScreenPhotoBrowser *this)
{
  int v2; // ebx
  UFG::GameSaveLoad *v3; // rax
  UFG::GameSaveLoad *v5; // rax

  v2 = this->mPhotoLoaded.saveFileIndex + 1;
  if ( v2 >= 1 )
    return 0;
  while ( 1 )
  {
    v3 = UFG::GameSaveLoad::Instance();
    if ( UFG::GameSaveLoad::DoesPhotoExists(v3, v2) )
      break;
    if ( ++v2 >= 1 )
      return 0;
  }
  v5 = UFG::GameSaveLoad::Instance();
  UFG::GameSaveLoad::LoadPhoto(v5, v2);
  this->mLastPicLoaded = v2;
  this->mState = STATE_COMPLETE;
  return 1;
}

// File Line: 179
// RVA: 0x5F0DD0
char __fastcall UFG::UIHKScreenPhotoBrowser::LoadPrevPhoto(UFG::UIHKScreenPhotoBrowser *this)
{
  int v2; // ebx
  UFG::GameSaveLoad *v3; // rax
  UFG::GameSaveLoad *v5; // rax

  v2 = this->mLastPicLoaded - 1;
  if ( v2 < 0 )
    return 0;
  while ( 1 )
  {
    v3 = UFG::GameSaveLoad::Instance();
    if ( UFG::GameSaveLoad::DoesPhotoExists(v3, v2) )
      break;
    if ( --v2 < 0 )
      return 0;
  }
  v5 = UFG::GameSaveLoad::Instance();
  UFG::GameSaveLoad::LoadPhoto(v5, v2);
  this->mLastPicLoaded = v2;
  this->mState = STATE_COMPLETE;
  return 1;
}

// File Line: 196
// RVA: 0x606D00
void __fastcall UFG::UIHKScreenPhotoBrowser::SetPhoto(
        UFG::UIHKScreenPhotoBrowser *this,
        UFG::UIMessagePhotoLoaded *photo)
{
  UFG::qMemoryPool *MemoryPool; // rax

  if ( photo )
  {
    UFG::qMemSet(this->mPhotoLoaded.rawData, 0, 0xC350u);
    UFG::qMemCopy(this->mPhotoLoaded.rawData, photo->m_pData, photo->m_iSize);
    this->mPhotoLoaded.size = photo->m_iSize;
    this->mPhotoLoaded.saveFileIndex = photo->m_iPhotoNum;
  }
  MemoryPool = (UFG::qMemoryPool *)UFG::qGetMemoryPool(0i64);
  UFG::qMemoryPool::GetLargeFreeBytes(MemoryPool);
}

// File Line: 220
// RVA: 0x606D70
void __fastcall UFG::UIHKScreenPhotoBrowser::SetPhotoInFlash(UFG::UIHKScreenPhotoBrowser *this)
{
  Illusion::Texture *mTexture0; // rcx

  mTexture0 = this->mTexture0;
  if ( mTexture0 )
  {
    Illusion::Factory::QueueDelete(mTexture0);
    this->mTexture0 = 0i64;
  }
  if ( this->mPhotoLoaded.size )
    TargetVisibleInAIDataCondition::CreateClone((hkResourceHandle *)this->mPhotoLoaded.rawData);
  UFG::UIScreenRenderable::replaceTexture(this->mRenderable, "PreviewBig", this->mTexture0);
}

// File Line: 235
// RVA: 0x63EF70
void __fastcall UFG::UIHKScreenPhotoBrowser::update(UFG::UIHKScreenPhotoBrowser *this, float elapsed)
{
  if ( !this->mHelpShowing )
    UFG::UIHKScreenPhotoBrowser::ShowHelpBar(this);
  UFG::UIScreen::update(this, elapsed);
}

// File Line: 251
// RVA: 0x5FFF70
void __fastcall UFG::UIHKScreenPhotoBrowser::RefreshAfterDelete(UFG::UIHKScreenPhotoBrowser *this, int deletedIndex)
{
  this->mLastPicLoaded = -1;
  *(_QWORD *)&this->mOffset = 0i64;
  this->mSelectedIndex = 0;
  this->mPicLoadIndex = 0;
  Scaleform::GFx::Movie::Invoke(this->mMovie, "PhotoList_Reset", 0i64, 0i64, 0);
  UFG::UIHKScreenPhotoBrowser::InitialPhotoLoad(this);
  UFG::UIHKScreenPhotoBrowser::UpdateCounter(this);
}

// File Line: 265
// RVA: 0x6297C0
bool __fastcall UFG::UIHKScreenPhotoBrowser::handleMessage(
        UFG::UIHKScreenPhotoBrowser *this,
        unsigned int msgId,
        UFG::UIMessagePhotoLoaded *msg)
{
  Scaleform::GFx::Movie *pObject; // r15
  int saveFileIndex; // ebx
  UFG::GameStatTracker *v8; // rax
  UFG::GameSaveLoad *v9; // rax
  Scaleform::GFx::Movie *v10; // r15
  Scaleform::GFx::Movie *v11; // r15
  Scaleform::GFx::Value value; // [rsp+38h] [rbp-38h] BYREF

  if ( msgId == UI_HASH_BUTTON_ACCEPT_PRESSED_30
    || msgId == UI_HASH_THUMBSTICK_LEFT_DOWN_30
    || msgId == UI_HASH_THUMBSTICK_LEFT_UP_30 )
  {
    return UFG::UIScreen::handleMessage(this, msgId, msg);
  }
  if ( msgId == UI_HASH_THUMBSTICK_LEFT_RIGHT_30 )
  {
    if ( ((this->mState - 3) & 0xFFFFFFFD) != 0 )
      UFG::UIHKScreenPhotoBrowser::Next(this);
    return UFG::UIScreen::handleMessage(this, msgId, msg);
  }
  if ( msgId == UI_HASH_THUMBSTICK_LEFT_LEFT_30 )
  {
    if ( ((this->mState - 3) & 0xFFFFFFFD) != 0 )
      UFG::UIHKScreenPhotoBrowser::Prev(this);
    return UFG::UIScreen::handleMessage(this, msgId, msg);
  }
  if ( msgId == (_DWORD)UI_HASH_BUTTON_BUTTON2_PRESSED_30 )
  {
    if ( !this->mPhotoLoaded.rawData )
      return UFG::UIScreen::handleMessage(this, msgId, msg);
    pObject = this->mRenderable->m_movie.pObject;
    value.pObjectInterface = 0i64;
    value.Type = VT_Boolean;
    value.mValue.BValue = 0;
    Scaleform::GFx::Movie::SetVariable(pObject, "mcPicPreviewMain._visible", &value, 1i64);
    UFG::UIScreenDialogBox::createYesNoDialog(this, "del p ti", "Delete Picture?", 0, 1);
    this->mState = STATE_ANIMATE_COMPLETE;
    goto LABEL_19;
  }
  if ( msgId == UI_HASH_DPAD_LEFT_PRESSED_30 || msgId == UI_HASH_BUTTON_BACK_PRESSED_30 )
    goto LABEL_24;
  if ( msgId == UI_HASH_DIALOG_YES_30 )
  {
    saveFileIndex = this->mPhotoLoaded.saveFileIndex;
    v8 = UFG::GameStatTracker::Instance();
    UFG::GameStatTracker::ApplyDelta(v8, PhotosDeleted, 1);
    v9 = UFG::GameSaveLoad::Instance();
    UFG::GameSaveLoad::DeletePhoto(v9, saveFileIndex);
    UFG::UIHKScreenPhotoBrowser::RefreshAfterDelete(this, this->mSelectedIndex);
    v10 = this->mRenderable->m_movie.pObject;
    value.pObjectInterface = 0i64;
    value.Type = VT_Boolean;
    value.mValue.BValue = 1;
    Scaleform::GFx::Movie::SetVariable(v10, "mcPicPreviewMain._visible", &value, 1i64);
LABEL_19:
    if ( (value.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        value.mValue);
      value.pObjectInterface = 0i64;
    }
    value.Type = VT_Undefined;
    return UFG::UIScreen::handleMessage(this, msgId, msg);
  }
  if ( msgId == UI_HASH_DIALOG_NO_30 )
  {
    v11 = this->mRenderable->m_movie.pObject;
    value.pObjectInterface = 0i64;
    value.Type = VT_Boolean;
    value.mValue.BValue = 1;
    Scaleform::GFx::Movie::SetVariable(v11, "mcPicPreviewMain._visible", &value, 1i64);
    this->mState = STATE_NORMAL;
    goto LABEL_19;
  }
  if ( msgId == UI_HASH_BUTTON_R1_PRESSED_30 )
    return UFG::UIScreen::handleMessage(this, msgId, msg);
  if ( msgId == UI_HASH_PDA_CAMERA_NO_PHOTOS_COMPLETE_20 )
  {
LABEL_24:
    UFG::UIHKScreenPhotoBrowser::SwitchToPhotoCamera(this);
    return UFG::UIScreen::handleMessage(this, msgId, msg);
  }
  if ( msgId == UI_HASH_PHOTO_LOADED_20 )
  {
    UFG::UIHKScreenPhotoBrowser::SetPhoto(this, msg);
    UFG::UIScreen::invoke(this, "PhotoList_ShowList");
    UFG::UIHKScreenPhotoBrowser::SetPhotoInFlash(this);
    UFG::UIHKScreenPhotoBrowser::StopLoadingAnim(this);
    operator delete[](msg->m_pData);
    msg->m_pData = 0i64;
    this->mState = STATE_NORMAL;
  }
  else if ( msgId == UI_HASH_PHOTO_DELETED_20 )
  {
    this->mState = STATE_NORMAL;
    UFG::UIHKScreenPhotoBrowser::UpdateArrows(this);
  }
  return UFG::UIScreen::handleMessage(this, msgId, msg);
}

// File Line: 391
// RVA: 0x5F2780
char __fastcall UFG::UIHKScreenPhotoBrowser::Next(UFG::UIHKScreenPhotoBrowser *this)
{
  int v1; // edi
  UFG::GameSaveLoad *v3; // rax

  v1 = ++this->mSelectedIndex;
  v3 = UFG::GameSaveLoad::Instance();
  if ( v1 <= UFG::GameSaveLoad::GetNumPhotosTaken(v3) - 1 )
  {
    if ( UFG::UIHKScreenPhotoBrowser::LoadNextPhoto(this) )
      UFG::UIScreenRenderable::replaceTexture(this->mRenderable, "PreviewBig", this->mTexture0);
    else
      --this->mSelectedIndex;
  }
  else
  {
    this->mSelectedIndex = v1 - 1;
  }
  UFG::UIHKScreenPhotoBrowser::UpdateCounter(this);
  return 1;
}

// File Line: 418
// RVA: 0x5FE290
char __fastcall UFG::UIHKScreenPhotoBrowser::Prev(UFG::UIHKScreenPhotoBrowser *this)
{
  if ( --this->mSelectedIndex < 0 )
  {
    this->mSelectedIndex = 0;
    UFG::UIHKScreenPhotoBrowser::UpdateCounter(this);
    return 1;
  }
  else
  {
    if ( UFG::UIHKScreenPhotoBrowser::LoadPrevPhoto(this) )
      UFG::UIScreenRenderable::replaceTexture(this->mRenderable, "PreviewBig", this->mTexture0);
    else
      this->mSelectedIndex = 0;
    UFG::UIHKScreenPhotoBrowser::UpdateCounter(this);
    return 1;
  }
}

// File Line: 478
// RVA: 0x619F10
void __fastcall UFG::UIHKScreenPhotoBrowser::UpdateArrows(UFG::UIHKScreenPhotoBrowser *this)
{
  Scaleform::GFx::Movie *pObject; // rdx
  Scaleform::GFx::Value v3; // [rsp+20h] [rbp-19h] BYREF
  Scaleform::GFx::Value value; // [rsp+50h] [rbp+17h] BYREF

  if ( this->mMovie || (pObject = this->UFG::UIScreen::mRenderable->m_movie.pObject, (this->mMovie = pObject) != 0i64) )
  {
    *(_QWORD *)&value.Type = 0i64;
    value.mValue.IValue = 2;
    LOBYTE(value.DataAux) = 0;
    Scaleform::GFx::Movie::SetVariable(this->mMovie, "mcLeftArrow._visible", (Scaleform::GFx::Value *)&value.8, 1i64);
    *(_QWORD *)&v3.Type = 0i64;
    v3.mValue.IValue = 2;
    LOBYTE(v3.DataAux) = 0;
    Scaleform::GFx::Movie::SetVariable(this->mMovie, "mcRightArrow._visible", (Scaleform::GFx::Value *)&v3.8, 1i64);
    if ( (v3.mValue.BValue & 0x40) != 0 )
    {
      (*(void (__fastcall **)(_QWORD, $41EDDC8CC4664C9FE26D4D23F9ACAEE4 *, unsigned __int64))(**(_QWORD **)&v3.Type
                                                                                            + 16i64))(
        *(_QWORD *)&v3.Type,
        &v3.8,
        v3.DataAux);
      *(_QWORD *)&v3.Type = 0i64;
    }
    v3.mValue.IValue = 0;
    if ( (value.mValue.BValue & 0x40) != 0 )
      (*(void (__fastcall **)(_QWORD, $41EDDC8CC4664C9FE26D4D23F9ACAEE4 *, unsigned __int64))(**(_QWORD **)&value.Type
                                                                                            + 16i64))(
        *(_QWORD *)&value.Type,
        &value.8,
        value.DataAux);
  }
}

// File Line: 514
// RVA: 0x6126A0
void __fastcall UFG::UIHKScreenPhotoBrowser::SwitchToPhotoCamera(UFG::UIHKScreenPhotoBrowser *this)
{
  UFG::UIHKScreenGlobalOverlay *v1; // rax
  UFG::UIHKHelpBarWidget *p_HelpBar; // rbx
  unsigned int v3; // eax
  UFG::UIScreenTextureManager *v4; // rax

  this->mShouldPushHUD = 0;
  if ( UFG::UIHKScreenGlobalOverlay::mThis )
  {
    this->mHelpShowing = 0;
    v1 = UFG::UIHKScreenGlobalOverlay::mThis;
    if ( !UFG::UIHKScreenGlobalOverlay::mThis )
      v1 = &gGlobalOverlaySentinel;
    p_HelpBar = &v1->HelpBar;
    v3 = UFG::qStringHash32("PHOTOBROWSER", 0xFFFFFFFF);
    UFG::UIHKHelpBarWidget::Hide(p_HelpBar, v3);
  }
  if ( UFG::UIHKScreenHud::mInstance )
    UFG::UIHKScreenHud::UnHideAmmoOverlay(UFG::UIHKScreenHud::mInstance);
  UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, 0xFFFFFFFF);
  v4 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::QueueLoadAndPush(v4, "Camera", 0i64);
}

// File Line: 529
// RVA: 0x61A560
void __fastcall UFG::UIHKScreenPhotoBrowser::UpdateCounter(UFG::UIHKScreenPhotoBrowser *this)
{
  UFG::GameSaveLoad *v2; // rax
  int v3; // ebx
  UFG::GameSaveLoad *v4; // rax
  double NumPhotosTaken; // xmm6_8
  Scaleform::GFx::Value pargs; // [rsp+40h] [rbp-78h] BYREF
  char v7[16]; // [rsp+70h] [rbp-48h] BYREF
  __int64 v8; // [rsp+80h] [rbp-38h]
  int v9; // [rsp+88h] [rbp-30h]
  double v10; // [rsp+90h] [rbp-28h]

  if ( this->mMovie )
  {
    `eh vector constructor iterator(&pargs, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    v2 = UFG::GameSaveLoad::Instance();
    if ( UFG::GameSaveLoad::GetNumPhotosTaken(v2) )
      v3 = this->mSelectedIndex + 1;
    else
      v3 = 0;
    if ( (pargs.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        pargs.mValue);
      pargs.pObjectInterface = 0i64;
    }
    pargs.Type = VT_Number;
    pargs.mValue.NValue = (double)v3;
    v4 = UFG::GameSaveLoad::Instance();
    NumPhotosTaken = (double)UFG::GameSaveLoad::GetNumPhotosTaken(v4);
    if ( (v9 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v8 + 16i64))(v8, v7, COERCE_DOUBLE(*(_QWORD *)&v10));
      v8 = 0i64;
    }
    v9 = 5;
    v10 = NumPhotosTaken;
    Scaleform::GFx::Movie::Invoke(this->mMovie, "PhotoList_SetCounter", 0i64, &pargs, 2u);
    `eh vector destructor iterator(&pargs, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 543
// RVA: 0x60F1D0
void __fastcall UFG::UIHKScreenPhotoBrowser::ShowHelpBar(UFG::UIHKScreenPhotoBrowser *this)
{
  UFG::UIHKScreenGlobalOverlay *v1; // rax
  UFG::UIHKHelpBarWidget *p_HelpBar; // rdi
  unsigned int v3; // ebx
  UFG::UIHKHelpBarData data; // [rsp+30h] [rbp-258h] BYREF

  if ( UFG::UIHKScreenGlobalOverlay::mThis
    && UFG::UIHKScreenGlobalOverlay::mThis != (UFG::UIHKScreenGlobalOverlay *)-144i64 )
  {
    this->mHelpShowing = 1;
    v1 = UFG::UIHKScreenGlobalOverlay::mThis;
    if ( !UFG::UIHKScreenGlobalOverlay::mThis )
      v1 = &gGlobalOverlaySentinel;
    p_HelpBar = &v1->HelpBar;
    v3 = UFG::qStringHash32("PHOTOBROWSER", 0xFFFFFFFF);
    UFG::UIHKHelpBarData::UIHKHelpBarData(&data);
    data.id = v3;
    data.priority = PRIORITY_ONE;
    data.alignment = ALIGN_RIGHT;
    *(__m128i *)data.Buttons = _mm_load_si128((const __m128i *)&_xmm);
    *(_QWORD *)&data.Buttons[4] = 0i64;
    UFG::qString::Set(data.Captions, "$HUD_CAMERA_BROWSE");
    UFG::qString::Set(&data.Captions[1], "$HUD_CAMERA_DELETE_PICTURE");
    UFG::qString::Set(&data.Captions[2], "$HUD_CAMERA_PHOTO_MODE");
    UFG::qString::Set(&data.Captions[3], &customCaption);
    UFG::qString::Set(&data.Captions[4], &customCaption);
    UFG::qString::Set(&data.Captions[5], &customCaption);
    memset(data.MessageIds, 0, sizeof(data.MessageIds));
    UFG::UIHKHelpBarWidget::Show(p_HelpBar, &data);
    UFG::qString::~qString(&data.CustomTexturePack);
    `eh vector destructor iterator(data.Icons, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
    `eh vector destructor iterator(data.Captions, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
  }
}

