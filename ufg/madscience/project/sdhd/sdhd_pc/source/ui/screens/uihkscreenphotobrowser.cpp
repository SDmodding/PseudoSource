// File Line: 68
// RVA: 0x5C6CA0
void __fastcall UFG::UIHKScreenPhotoBrowser::UIHKScreenPhotoBrowser(UFG::UIHKScreenPhotoBrowser *this)
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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenPhotoBrowser::`vftable';
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
  UFG::UIHKScreenPhotoBrowser *v1; // rbx
  unsigned int v2; // eax
  UFG::UIScreenTextureManager *v3; // rax
  Illusion::Texture *v4; // rcx

  v1 = this;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenPhotoBrowser::`vftable';
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
  operator delete[](v1->mPhotoLoaded.rawData);
  v1->mPhotoLoaded.rawData = 0i64;
  v4 = v1->mTexture0;
  if ( v4 )
  {
    Illusion::Factory::QueueDelete(v4);
    v1->mTexture0 = 0i64;
  }
  UFG::UIScreen::~UIScreen((UFG::UIScreen *)&v1->vfptr);
}

// File Line: 97
// RVA: 0x635680
void __fastcall UFG::UIHKScreenPhotoBrowser::init(UFG::UIHKScreenPhotoBrowser *this, UFG::UICommandData *data)
{
  UFG::UIHKScreenPhotoBrowser *v2; // rbx
  UFG::Controller *v3; // rcx
  UFG::allocator::free_link *v4; // rax
  UFG::UIScreenRenderable *v5; // rcx
  Scaleform::GFx::Movie *v6; // rcx

  v2 = this;
  UFG::UIScreen::init((UFG::UIScreen *)&this->vfptr, data);
  v2->mRenderable = v2->mRenderable;
  if ( UFG::gInputSystem && UFG::gActiveControllerNum != -1 )
  {
    v3 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum];
    if ( !UFG::UI::gUIInputLocked )
      g_saved_gameplay_controller_mode = v3->m_ActiveMapSet;
    UFG::SetInputMode(IM_UI_ONLY, v3->mControllerIndex);
    ++UFG::UI::gUIInputLocked;
  }
  v4 = UFG::qMalloc(0xC350ui64, "PhotoBrowser", 0i64);
  v5 = v2->mRenderable;
  v2->mPhotoLoaded.rawData = v4;
  if ( v5 )
  {
    v6 = v5->m_movie.pObject;
    if ( v6 )
      Scaleform::GFx::Movie::Invoke(v6, "PhotoList_StartLoadingAnimation", 0i64, 0i64, 0);
  }
  UFG::UIHKScreenPhotoBrowser::InitialPhotoLoad(v2);
  UFG::UIHKScreenPhotoBrowser::UpdateArrows(v2);
  UFG::UIHKScreenPhotoBrowser::UpdateCounter(v2);
  v2->mState = 1;
}

// File Line: 121
// RVA: 0x5ED750
void __fastcall UFG::UIHKScreenPhotoBrowser::InitialPhotoLoad(UFG::UIHKScreenPhotoBrowser *this)
{
  UFG::UIHKScreenPhotoBrowser *v1; // rdi
  signed int v2; // ebx
  UFG::GameSaveLoad *v3; // rax
  UFG::GameSaveLoad *v4; // rax

  v1 = this;
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
    v1->mLastPicLoaded = v2;
  }
}

// File Line: 150
// RVA: 0x6125B0
void __fastcall UFG::UIHKScreenPhotoBrowser::StopLoadingAnim(UFG::UIHKScreenPhotoBrowser *this)
{
  Scaleform::GFx::Movie *v1; // rbx
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-40h]

  v1 = this->mRenderable->m_movie.pObject;
  if ( v1 )
  {
    value.pObjectInterface = 0i64;
    value.Type = 2;
    value.mValue.BValue = 0;
    Scaleform::GFx::Movie::SetVariable(v1, "mcLoadingIcon._visible", &value, 1i64);
    if ( ((unsigned int)value.Type >> 6) & 1 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        *(_QWORD *)&value.mValue.NValue);
  }
}

// File Line: 162
// RVA: 0x5F0D50
char __fastcall UFG::UIHKScreenPhotoBrowser::LoadNextPhoto(UFG::UIHKScreenPhotoBrowser *this)
{
  UFG::UIHKScreenPhotoBrowser *v1; // rdi
  signed int v2; // ebx
  UFG::GameSaveLoad *v3; // rax
  UFG::GameSaveLoad *v5; // rax

  v1 = this;
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
  v1->mLastPicLoaded = v2;
  v1->mState = 3;
  return 1;
}

// File Line: 179
// RVA: 0x5F0DD0
char __fastcall UFG::UIHKScreenPhotoBrowser::LoadPrevPhoto(UFG::UIHKScreenPhotoBrowser *this)
{
  UFG::UIHKScreenPhotoBrowser *v1; // rdi
  signed int v2; // ebx
  UFG::GameSaveLoad *v3; // rax
  UFG::GameSaveLoad *v5; // rax

  v1 = this;
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
  v1->mLastPicLoaded = v2;
  v1->mState = 3;
  return 1;
}

// File Line: 196
// RVA: 0x606D00
void __fastcall UFG::UIHKScreenPhotoBrowser::SetPhoto(UFG::UIHKScreenPhotoBrowser *this, UFG::UIMessagePhotoLoaded *photo)
{
  UFG::UIMessagePhotoLoaded *v2; // rbx
  UFG::UIHKScreenPhotoBrowser *v3; // rdi
  UFG::qMemoryPool *v4; // rax

  v2 = photo;
  v3 = this;
  if ( photo )
  {
    UFG::qMemSet(this->mPhotoLoaded.rawData, 0, 0xC350u);
    UFG::qMemCopy(v3->mPhotoLoaded.rawData, v2->m_pData, v2->m_iSize);
    v3->mPhotoLoaded.size = v2->m_iSize;
    v3->mPhotoLoaded.saveFileIndex = v2->m_iPhotoNum;
  }
  v4 = UFG::qGetMemoryPool(0i64);
  UFG::qMemoryPool::GetLargeFreeBytes(v4);
}

// File Line: 220
// RVA: 0x606D70
void __fastcall UFG::UIHKScreenPhotoBrowser::SetPhotoInFlash(UFG::UIHKScreenPhotoBrowser *this)
{
  UFG::UIHKScreenPhotoBrowser *v1; // rbx
  Illusion::Texture *v2; // rcx

  v1 = this;
  v2 = this->mTexture0;
  if ( v2 )
  {
    Illusion::Factory::QueueDelete(v2);
    v1->mTexture0 = 0i64;
  }
  if ( v1->mPhotoLoaded.size )
    TargetVisibleInAIDataCondition::CreateClone((hkResourceHandle *)v1->mPhotoLoaded.rawData);
  UFG::UIScreenRenderable::replaceTexture(v1->mRenderable, "PreviewBig", v1->mTexture0);
}

// File Line: 235
// RVA: 0x63EF70
void __fastcall UFG::UIHKScreenPhotoBrowser::update(UFG::UIHKScreenPhotoBrowser *this, float elapsed)
{
  UFG::UIHKScreenPhotoBrowser *v2; // rbx

  v2 = this;
  if ( !this->mHelpShowing )
    UFG::UIHKScreenPhotoBrowser::ShowHelpBar(this);
  UFG::UIScreen::update((UFG::UIScreen *)&v2->vfptr, elapsed);
}

// File Line: 251
// RVA: 0x5FFF70
void __fastcall UFG::UIHKScreenPhotoBrowser::RefreshAfterDelete(UFG::UIHKScreenPhotoBrowser *this, int deletedIndex)
{
  UFG::UIHKScreenPhotoBrowser *v2; // rbx

  v2 = this;
  this->mLastPicLoaded = -1;
  *(_QWORD *)&this->mOffset = 0i64;
  this->mSelectedIndex = 0;
  this->mPicLoadIndex = 0;
  Scaleform::GFx::Movie::Invoke(this->mMovie, "PhotoList_Reset", 0i64, 0i64, 0);
  UFG::UIHKScreenPhotoBrowser::InitialPhotoLoad(v2);
  UFG::UIHKScreenPhotoBrowser::UpdateCounter(v2);
}

// File Line: 265
// RVA: 0x6297C0
bool __fastcall UFG::UIHKScreenPhotoBrowser::handleMessage(UFG::UIHKScreenPhotoBrowser *this, unsigned int msgId, UFG::UIMessage *msg)
{
  UFG::UIMessage *v3; // r14
  unsigned int v4; // esi
  UFG::UIHKScreenPhotoBrowser *v5; // rdi
  Scaleform::GFx::Movie *v6; // r15
  int v7; // ebx
  UFG::GameStatTracker *v8; // rax
  UFG::GameSaveLoad *v9; // rax
  Scaleform::GFx::Movie *v10; // r15
  Scaleform::GFx::Movie *v11; // r15
  Scaleform::GFx::Value value; // [rsp+38h] [rbp-38h]

  v3 = msg;
  v4 = msgId;
  v5 = this;
  if ( msgId == UI_HASH_BUTTON_ACCEPT_PRESSED_30
    || msgId == UI_HASH_THUMBSTICK_LEFT_DOWN_30
    || msgId == UI_HASH_THUMBSTICK_LEFT_UP_30 )
  {
    return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
  }
  if ( msgId == UI_HASH_THUMBSTICK_LEFT_RIGHT_30 )
  {
    if ( (this->mState - 3) & 0xFFFFFFFD )
      UFG::UIHKScreenPhotoBrowser::Next(this);
    return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
  }
  if ( msgId == UI_HASH_THUMBSTICK_LEFT_LEFT_30 )
  {
    if ( (this->mState - 3) & 0xFFFFFFFD )
      UFG::UIHKScreenPhotoBrowser::Prev(this);
    return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
  }
  if ( msgId == (_DWORD)UI_HASH_BUTTON_BUTTON2_PRESSED_30 )
  {
    if ( !this->mPhotoLoaded.rawData )
      return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
    v6 = this->mRenderable->m_movie.pObject;
    value.pObjectInterface = 0i64;
    value.Type = 0;
    value.Type = 2;
    value.mValue.BValue = 0;
    Scaleform::GFx::Movie::SetVariable(v6, "mcPicPreviewMain._visible", &value, 1i64);
    UFG::UIScreenDialogBox::createYesNoDialog((UFG::UIScreen *)&v5->vfptr, "del p ti", "Delete Picture?", 0, 1);
    v5->mState = 5;
    goto LABEL_25;
  }
  if ( msgId == UI_HASH_DPAD_LEFT_PRESSED_30 || msgId == UI_HASH_BUTTON_BACK_PRESSED_30 )
    goto LABEL_38;
  if ( msgId == UI_HASH_DIALOG_YES_30 )
  {
    v7 = this->mPhotoLoaded.saveFileIndex;
    v8 = UFG::GameStatTracker::Instance();
    UFG::GameStatTracker::ApplyDelta(v8, PhotosDeleted, 1);
    v9 = UFG::GameSaveLoad::Instance();
    UFG::GameSaveLoad::DeletePhoto(v9, v7);
    UFG::UIHKScreenPhotoBrowser::RefreshAfterDelete(v5, v5->mSelectedIndex);
    v10 = v5->mRenderable->m_movie.pObject;
    value.pObjectInterface = 0i64;
    value.Type = 0;
    value.Type = 2;
    value.mValue.BValue = 1;
    Scaleform::GFx::Movie::SetVariable(v10, "mcPicPreviewMain._visible", &value, 1i64);
LABEL_25:
    if ( ((unsigned int)value.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        *(_QWORD *)&value.mValue.NValue);
      value.pObjectInterface = 0i64;
    }
    value.Type = 0;
    return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
  }
  if ( msgId == UI_HASH_DIALOG_NO_30 )
  {
    v11 = this->mRenderable->m_movie.pObject;
    value.pObjectInterface = 0i64;
    value.Type = 0;
    value.Type = 2;
    value.mValue.BValue = 1;
    Scaleform::GFx::Movie::SetVariable(v11, "mcPicPreviewMain._visible", &value, 1i64);
    v5->mState = 1;
    goto LABEL_25;
  }
  if ( msgId == UI_HASH_BUTTON_R1_PRESSED_30 )
    return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
  if ( msgId == UI_HASH_PDA_CAMERA_NO_PHOTOS_COMPLETE_20 )
  {
LABEL_38:
    UFG::UIHKScreenPhotoBrowser::SwitchToPhotoCamera(this);
    return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
  }
  if ( msgId == UI_HASH_PHOTO_LOADED_20 )
  {
    UFG::UIHKScreenPhotoBrowser::SetPhoto(this, (UFG::UIMessagePhotoLoaded *)msg);
    UFG::UIScreen::invoke((UFG::UIScreen *)&v5->vfptr, "PhotoList_ShowList");
    UFG::UIHKScreenPhotoBrowser::SetPhotoInFlash(v5);
    UFG::UIHKScreenPhotoBrowser::StopLoadingAnim(v5);
    operator delete[](v3[1].mPrev);
    v3[1].mPrev = 0i64;
    v5->mState = 1;
  }
  else if ( msgId == UI_HASH_PHOTO_DELETED_20 )
  {
    this->mState = 1;
    UFG::UIHKScreenPhotoBrowser::UpdateArrows(this);
  }
  return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
}

// File Line: 391
// RVA: 0x5F2780
char __fastcall UFG::UIHKScreenPhotoBrowser::Next(UFG::UIHKScreenPhotoBrowser *this)
{
  signed int v1; // edi
  UFG::UIHKScreenPhotoBrowser *v2; // rbx
  UFG::GameSaveLoad *v3; // rax

  v1 = ++this->mSelectedIndex;
  v2 = this;
  v3 = UFG::GameSaveLoad::Instance();
  if ( v1 <= (signed int)((unsigned __int64)UFG::GameSaveLoad::GetNumPhotosTaken(v3) - 1) )
  {
    if ( UFG::UIHKScreenPhotoBrowser::LoadNextPhoto(v2) )
      UFG::UIScreenRenderable::replaceTexture(v2->mRenderable, "PreviewBig", v2->mTexture0);
    else
      --v2->mSelectedIndex;
  }
  else
  {
    v2->mSelectedIndex = v1 - 1;
  }
  UFG::UIHKScreenPhotoBrowser::UpdateCounter(v2);
  return 1;
}

// File Line: 418
// RVA: 0x5FE290
char __fastcall UFG::UIHKScreenPhotoBrowser::Prev(UFG::UIHKScreenPhotoBrowser *this)
{
  bool v1; // sf
  UFG::UIHKScreenPhotoBrowser *v2; // rbx
  char result; // al

  v1 = this->mSelectedIndex-- - 1 < 0;
  v2 = this;
  if ( v1 )
  {
    this->mSelectedIndex = 0;
    UFG::UIHKScreenPhotoBrowser::UpdateCounter(this);
    result = 1;
  }
  else
  {
    if ( UFG::UIHKScreenPhotoBrowser::LoadPrevPhoto(this) )
      UFG::UIScreenRenderable::replaceTexture(v2->mRenderable, "PreviewBig", v2->mTexture0);
    else
      v2->mSelectedIndex = 0;
    UFG::UIHKScreenPhotoBrowser::UpdateCounter(v2);
    result = 1;
  }
  return result;
}

// File Line: 478
// RVA: 0x619F10
void __fastcall UFG::UIHKScreenPhotoBrowser::UpdateArrows(UFG::UIHKScreenPhotoBrowser *this)
{
  UFG::UIHKScreenPhotoBrowser *v1; // rbx
  Scaleform::GFx::Movie *v2; // rdx
  Scaleform::GFx::Value v3; // [rsp+20h] [rbp-11h]
  Scaleform::GFx::Value value; // [rsp+50h] [rbp+1Fh]

  v1 = this;
  if ( this->mMovie || (v2 = this->mRenderable->m_movie.pObject, (this->mMovie = v2) != 0i64) )
  {
    value.pObjectInterface = 0i64;
    value.Type = 2;
    value.mValue.BValue = 0;
    Scaleform::GFx::Movie::SetVariable(this->mMovie, "mcLeftArrow._visible", &value, 1i64);
    v3.pObjectInterface = 0i64;
    v3.Type = 2;
    v3.mValue.BValue = 0;
    Scaleform::GFx::Movie::SetVariable(v1->mMovie, "mcRightArrow._visible", &v3, 1i64);
    if ( ((unsigned int)v3.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&v3.pObjectInterface->vfptr->gap8[8])(
        v3.pObjectInterface,
        &v3,
        *(_QWORD *)&v3.mValue.NValue);
      v3.pObjectInterface = 0i64;
    }
    v3.Type = 0;
    if ( ((unsigned int)value.Type >> 6) & 1 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        *(_QWORD *)&value.mValue.NValue);
  }
}

// File Line: 514
// RVA: 0x6126A0
void __fastcall UFG::UIHKScreenPhotoBrowser::SwitchToPhotoCamera(UFG::UIHKScreenPhotoBrowser *this)
{
  UFG::UIHKScreenGlobalOverlay *v1; // rax
  UFG::UIHKHelpBarWidget *v2; // rbx
  unsigned int v3; // eax
  UFG::UIScreenTextureManager *v4; // rax

  this->mShouldPushHUD = 0;
  if ( UFG::UIHKScreenGlobalOverlay::mThis )
  {
    this->mHelpShowing = 0;
    v1 = UFG::UIHKScreenGlobalOverlay::mThis;
    if ( !UFG::UIHKScreenGlobalOverlay::mThis )
      v1 = &gGlobalOverlaySentinel;
    v2 = &v1->HelpBar;
    v3 = UFG::qStringHash32("PHOTOBROWSER", 0xFFFFFFFF);
    UFG::UIHKHelpBarWidget::Hide(v2, v3);
  }
  if ( UFG::UIHKScreenHud::mInstance )
    UFG::UIHKScreenHud::UnHideAmmoOverlay(UFG::UIHKScreenHud::mInstance);
  UFG::UIScreenManagerBase::queuePopScreen(
    (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
    0xFFFFFFFF);
  v4 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::QueueLoadAndPush(v4, "Camera", 0i64);
}

// File Line: 529
// RVA: 0x61A560
void __fastcall UFG::UIHKScreenPhotoBrowser::UpdateCounter(UFG::UIHKScreenPhotoBrowser *this)
{
  UFG::UIHKScreenPhotoBrowser *v1; // rdi
  UFG::GameSaveLoad *v2; // rax
  int v3; // ebx
  UFG::GameSaveLoad *v4; // rax
  double v5; // xmm6_8
  Scaleform::GFx::Value pargs; // [rsp+40h] [rbp-78h]
  char v7; // [rsp+70h] [rbp-48h]
  __int64 v8; // [rsp+80h] [rbp-38h]
  unsigned int v9; // [rsp+88h] [rbp-30h]
  double v10; // [rsp+90h] [rbp-28h]

  v1 = this;
  if ( this->mMovie )
  {
    `eh vector constructor iterator'(&pargs, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    v2 = UFG::GameSaveLoad::Instance();
    if ( (unsigned int)UFG::GameSaveLoad::GetNumPhotosTaken(v2) )
      v3 = v1->mSelectedIndex + 1;
    else
      v3 = 0;
    if ( ((unsigned int)pargs.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        *(_QWORD *)&pargs.mValue.NValue);
      pargs.pObjectInterface = 0i64;
    }
    pargs.Type = 5;
    pargs.mValue.NValue = (double)v3;
    v4 = UFG::GameSaveLoad::Instance();
    v5 = (double)(signed int)UFG::GameSaveLoad::GetNumPhotosTaken(v4);
    if ( (v9 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v8 + 16i64))(v8, &v7, COERCE_DOUBLE(*(_QWORD *)&v10));
      v8 = 0i64;
    }
    v9 = 5;
    v10 = v5;
    Scaleform::GFx::Movie::Invoke(v1->mMovie, "PhotoList_SetCounter", 0i64, &pargs, 2u);
    `eh vector destructor iterator'(&pargs, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 543
// RVA: 0x60F1D0
void __fastcall UFG::UIHKScreenPhotoBrowser::ShowHelpBar(UFG::UIHKScreenPhotoBrowser *this)
{
  UFG::UIHKScreenGlobalOverlay *v1; // rax
  UFG::UIHKHelpBarWidget *v2; // rdi
  unsigned int v3; // ebx
  UFG::UIHKHelpBarData data; // [rsp+30h] [rbp-258h]

  if ( UFG::UIHKScreenGlobalOverlay::mThis
    && UFG::UIHKScreenGlobalOverlay::mThis != (UFG::UIHKScreenGlobalOverlay *)-144i64 )
  {
    this->mHelpShowing = 1;
    v1 = UFG::UIHKScreenGlobalOverlay::mThis;
    if ( !UFG::UIHKScreenGlobalOverlay::mThis )
      v1 = &gGlobalOverlaySentinel;
    v2 = &v1->HelpBar;
    v3 = UFG::qStringHash32("PHOTOBROWSER", 0xFFFFFFFF);
    UFG::UIHKHelpBarData::UIHKHelpBarData(&data);
    data.id = v3;
    data.priority = 0;
    data.alignment = 1;
    _mm_store_si128((__m128i *)data.Buttons, _mm_load_si128((const __m128i *)&_xmm));
    *(_QWORD *)&data.Buttons[4] = 0i64;
    UFG::qString::Set(data.Captions, "$HUD_CAMERA_BROWSE");
    UFG::qString::Set(&data.Captions[1], "$HUD_CAMERA_DELETE_PICTURE");
    UFG::qString::Set(&data.Captions[2], "$HUD_CAMERA_PHOTO_MODE");
    UFG::qString::Set(&data.Captions[3], &customWorldMapCaption);
    UFG::qString::Set(&data.Captions[4], &customWorldMapCaption);
    UFG::qString::Set(&data.Captions[5], &customWorldMapCaption);
    *(_QWORD *)data.MessageIds = 0i64;
    *(_QWORD *)&data.MessageIds[2] = 0i64;
    *(_QWORD *)&data.MessageIds[4] = 0i64;
    UFG::UIHKHelpBarWidget::Show(v2, &data);
    UFG::qString::~qString(&data.CustomTexturePack);
    `eh vector destructor iterator'(data.Icons, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
    `eh vector destructor iterator'(data.Captions, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
  }
}

