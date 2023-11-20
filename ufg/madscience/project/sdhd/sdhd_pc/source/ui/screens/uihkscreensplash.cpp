// File Line: 82
// RVA: 0x5C7440
void __fastcall UFG::UIHKScreenSplash::UIHKScreenSplash(UFG::UIHKScreenSplash *this)
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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenSplash::`vftable';
  *(_QWORD *)&this->mState = 0i64;
  *(_WORD *)&this->mInAttractMode = 0;
  this->mDeviceSelected = 0;
  this->mMsgControllerIndex = -1;
  UFG::MoviePlayer::MoviePlayer(&this->HKUIMovie);
  UFG::StreamFileWrapper::SetSupressCaching_Splash(1);
}

// File Line: 90
// RVA: 0x5CC980
void __fastcall UFG::UIHKScreenSplash::~UIHKScreenSplash(UFG::UIHKScreenSplash *this)
{
  UFG::UIHKScreenSplash *v1; // rdi
  UFG::UIScreenTextureManager *v2; // rax

  v1 = this;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenSplash::`vftable';
  UFG::MoviePlayer::Close(&this->HKUIMovie);
  v2 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v2, "Splash");
  UFG::StreamFileWrapper::SetSupressCaching_Splash(0);
  UFG::MoviePlayer::~MoviePlayer(&v1->HKUIMovie);
  UFG::UIScreen::~UIScreen((UFG::UIScreen *)&v1->vfptr);
}

// File Line: 99
// RVA: 0x636560
void __fastcall UFG::UIHKScreenSplash::init(UFG::UIHKScreenSplash *this, UFG::UICommandData *data)
{
  UFG::UIHKScreenSplash *v2; // rbx

  v2 = this;
  UFG::UIScreen::init((UFG::UIScreen *)&this->vfptr, data);
  if ( UFG::UIHKScreenSplash::mUseAttractMode )
  {
    v2->mInAttractMode = 1;
    UFG::UIHKScreenSplash::mUseAttractMode = 0;
  }
  if ( !v2->mInAttractMode )
  {
    gUIHorizontalResolution = (float)Render::GetBackBufferTarget()->mWidth;
    gUIVerticalResolution = (float)Render::GetBackBufferTarget()->mHeight;
    gIsUIHighDef = gUIVerticalResolution >= 720.0;
    UFG::UIScreenManagerBase::setFontScale((UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr, 1.0);
  }
  UFG::UIHKScreenSplash::PlayDemo(v2);
}

// File Line: 145
// RVA: 0x63FE30
void __fastcall UFG::UIHKScreenSplash::update(UFG::UIHKScreenSplash *this, float elapsed)
{
  UFG::UIHKScreenSplash *v2; // rbx
  int v3; // edx
  hkGeometryUtils::IVertices *v4; // rcx
  int v5; // er8
  float v6; // xmm0_4
  UFG::GameSaveLoad *v7; // rax
  UFG::GameSaveLoad *v8; // rax

  v2 = this;
  if ( this == (UFG::UIHKScreenSplash *)UFG::UIScreenManagerBase::getTopScreen((UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr) )
  {
    if ( v2->mStartMusic
      && Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(v4, v3, v5)
      && !UFG::UIHKScreenSplash::smMusicPlaying )
    {
      UFG::TiDo::GetIsInstantiated();
    }
    switch ( v2->mState )
    {
      case 1:
        if ( v2->HKUIMovie.mFlags & 1 )
          v2->mState = 2;
        break;
      case 2:
        if ( v2->HKUIMovie.mFlags & 1 )
          UFG::UIHKScreenSplash::PlaySplash(v2);
        break;
      case 3:
        v6 = elapsed + v2->mPressStartTimer;
        v2->mPressStartTimer = v6;
        if ( v6 > 20.0 )
        {
          UFG::UIHKScreenSplash::PlayDemo(v2);
          if ( UFG::UIHKScreenSplash::smMusicPlaying )
          {
            UFG::AudioEntity::StopAllEvents((unsigned __int64)UFG::Music::sm_instance);
            UFG::UIHKScreenSplash::smMusicPlaying = 0;
            v2->mStartMusic = 0;
          }
        }
        break;
      case 4:
        UFG::UIHKScreenSplash::DoInitLoad(v2);
        break;
      case 5:
        v8 = UFG::GameSaveLoad::Instance();
        if ( !(unsigned int)UFG::GameSaveLoad::GetOperation(v8) && UFG::UIScreenDialogBox::m_iDialogBoxRefCount <= 0 )
        {
          UFG::DataSynchronizer::s_bPastOptionLoad = 1;
          UFG::DataSynchronizer::UpdateOptionSaveDataIfNeeded();
          v2->mState = 8;
          UFG::UIHKScreenDialogBox::createSaveLoadNotificationDialog((UFG::UIScreen *)&v2->vfptr);
          UFG::UIHKScreenSplash::smAutoSaveDisplayed = 1;
        }
        break;
      case 6:
        v7 = UFG::GameSaveLoad::Instance();
        if ( !(unsigned int)UFG::GameSaveLoad::GetOperation(v7) && UFG::UIScreenDialogBox::m_iDialogBoxRefCount <= 0 )
          UFG::UIHKScreenSplash::LoadGameOptions(v2);
        break;
      default:
        break;
    }
    UFG::UIScreen::update((UFG::UIScreen *)&v2->vfptr, elapsed);
  }
}

// File Line: 337
// RVA: 0x62C040
bool __fastcall UFG::UIHKScreenSplash::handleMessage(UFG::UIHKScreenSplash *this, unsigned int msgId, UFG::UIMessage *msg)
{
  UFG::UIMessage *v3; // rsi
  unsigned int v4; // ebx
  UFG::UIHKScreenSplash *v5; // rdi
  bool result; // al
  bool v7; // zf
  __int64 v8; // rsi
  hkgpIndexedMesh::EdgeBarrier *v9; // rax
  int v10; // ebx
  UFG::TiDo *v11; // rax
  UFG::TiDo *v12; // rax

  v3 = msg;
  v4 = msgId;
  v5 = this;
  switch ( this->mState )
  {
    case 1:
      if ( msgId != UI_HASH_BUTTON_ACCEPT_PRESSED_30
        && msgId != UI_HASH_BUTTON_BACK_PRESSED_30
        && msgId != UI_HASH_BUTTON_BUTTON1_PRESSED_30
        && msgId != (_DWORD)UI_HASH_BUTTON_BUTTON2_PRESSED_30
        && msgId != UI_HASH_MOUSE_BUTTON_LEFT_PRESSED_30 )
      {
        goto LABEL_13;
      }
      this->mState = 2;
      this->mStartMusic = 1;
      result = 1;
      break;
    case 2:
      if ( msgId != UI_HASH_BUTTON_ACCEPT_PRESSED_30
        && msgId != UI_HASH_BUTTON_BACK_PRESSED_30
        && msgId != UI_HASH_BUTTON_BUTTON1_PRESSED_30
        && msgId != (_DWORD)UI_HASH_BUTTON_BUTTON2_PRESSED_30
        && msgId != UI_HASH_MOUSE_BUTTON_LEFT_PRESSED_30 )
      {
LABEL_13:
        v7 = msgId == UI_HASH_DIALOG_OK_CONTROLLER_DISCONNECTED_9;
        goto LABEL_14;
      }
      UFG::UIHKScreenSplash::PlaySplash(this);
      result = 1;
      break;
    case 3:
      if ( msgId != UI_HASH_BUTTON_START_PRESSED_30
        && msgId != UI_HASH_BUTTON_ACCEPT_PRESSED_30
        && !UFG::UIHKScreenSplash::IsKeyboardAndMouseContinue(this, msgId, msg) )
      {
        v7 = v4 == UI_HASH_DIALOG_OK_CONTROLLER_DISCONNECTED_9;
LABEL_14:
        if ( v7 )
          UFG::UIHKScreenSplash::PlayDemo(v5);
        goto $LN3_58;
      }
      v8 = UFG::UIInputHandler::getControllerIndex(HIDWORD(v3[1].vfptr));
      v9 = (hkgpIndexedMesh::EdgeBarrier *)UserManager::GetInstance();
      Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
        v9,
        (hkgpIndexedMeshDefinitions::Edge *)(unsigned int)v8);
      v10 = 0;
      do
      {
        v11 = UFG::TiDo::GetInstance();
        UFG::TiDo::UnregisterControllerForEvents(v11, v10++);
      }
      while ( v10 < 4 );
      if ( !UFG::gInputSystem->mControllers[v8]->m_IsKeyboardController )
      {
        v12 = UFG::TiDo::GetInstance();
        UFG::TiDo::RegisterControllerForEvents(v12, v8);
      }
      v5->mState = 4;
      result = 1;
      break;
    case 4:
      if ( msgId == UI_HASH_DIALOG_OK_NOT_SIGNED_IN_20 )
      {
        UFG::UIHKScreenSplash::DoInitLoad(this);
        result = 1;
      }
      else
      {
        if ( msgId != UI_HASH_DIALOG_CANCEL_NOT_SIGNED_IN_20 )
          goto $LN3_58;
        this->mState = 3;
        result = 1;
      }
      break;
    case 8:
      if ( msgId != UI_HASH_DIALOG_OK_AUTOSAVE_20 )
        goto $LN3_58;
      UFG::UIHKScreenSplash::Exit(this);
      result = 1;
      break;
    case 0xA:
      if ( msgId == UI_HASH_DIALOG_YES_30 )
      {
        this->mState = 4;
      }
      else if ( msgId == UI_HASH_DIALOG_NO_30 )
      {
        this->mState = 3;
      }
      goto $LN3_58;
    default:
$LN3_58:
      result = UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
      break;
  }
  return result;
}

// File Line: 658
// RVA: 0x5EE3E0
bool __fastcall UFG::UIHKScreenSplash::IsKeyboardAndMouseContinue(UFG::UIHKScreenSplash *this, unsigned int msgId, UFG::UIMessage *msg)
{
  UFG::UIMessage::UIMessageType v3; // ecx
  bool result; // al

  result = 0;
  if ( UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
  {
    v3 = msg->m_messageType;
    if ( !(v3 & 0xFFFFFFFD) || v3 == 3 && msgId != UI_HASH_MOUSE_MOVE_30 )
      result = 1;
  }
  return result;
}

// File Line: 711
// RVA: 0x607360
void __fastcall UFG::UIHKScreenSplash::SetScreenVisible(UFG::UIHKScreenSplash *this, bool visible)
{
  bool v2; // bl
  Scaleform::GFx::Movie *v3; // rsi
  bool v4; // di
  const char *v5; // rdx
  char *v6; // rbx
  __int64 v7; // rdi
  __int64 v8; // rdx
  UFG::UIGfxTranslator *v9; // rcx
  Scaleform::GFx::Value pargs; // [rsp+30h] [rbp-B8h]
  char v11; // [rsp+60h] [rbp-88h]
  __int64 v12; // [rsp+68h] [rbp-80h]
  __int64 v13; // [rsp+70h] [rbp-78h]
  unsigned int ptr; // [rsp+78h] [rbp-70h]
  __int64 v15; // [rsp+88h] [rbp-60h]
  unsigned int v16; // [rsp+90h] [rbp-58h]
  long double v17; // [rsp+98h] [rbp-50h]
  char v18; // [rsp+A8h] [rbp-40h]
  __int64 v19; // [rsp+B8h] [rbp-30h]
  unsigned int v20; // [rsp+C0h] [rbp-28h]
  __int64 v21; // [rsp+C8h] [rbp-20h]
  __int64 v22; // [rsp+D8h] [rbp-10h]
  UFG::qString v23; // [rsp+E0h] [rbp-8h]

  v22 = -2i64;
  v2 = visible;
  v3 = this->mRenderable->m_movie.pObject;
  if ( v3 )
  {
    v4 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController;
    `eh vector constructor iterator'(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( (v16 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, unsigned int *, long double))(*(_QWORD *)v15 + 16i64))(
        v15,
        &ptr,
        COERCE_LONG_DOUBLE(*(_QWORD *)&v17));
      v15 = 0i64;
    }
    v16 = 5;
    v17 = DOUBLE_1_0;
    if ( (v20 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v19 + 16i64))(v19, &v18, v21);
      v19 = 0i64;
    }
    v20 = 5;
    v21 = 0i64;
    Scaleform::GFx::Movie::Invoke(v3, "SetVersionText", 0i64, (Scaleform::GFx::Value *)&ptr, 2u);
    `eh vector constructor iterator'(&pargs, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( ((unsigned int)pargs.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        *(_QWORD *)&pargs.mValue.NValue);
      pargs.pObjectInterface = 0i64;
    }
    pargs.Type = 2;
    pargs.mValue.BValue = v2;
    v5 = "SPLASH_PRESS_START_DURANGO";
    if ( v4 == 1 )
      v5 = "SPLASH_PRESS_START_PC";
    UFG::qString::qString(&v23, v5);
    v6 = v23.mData;
    if ( v23.mData )
    {
      if ( *v23.mData == 36 )
        v6 = v23.mData + 1;
      v8 = (unsigned int)UFG::qStringHashUpper32(v6, 0xFFFFFFFF);
      v9 = UFG::UIScreenManager::s_instance->m_translator;
      if ( !v9 || (v7 = (__int64)v9->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v9->vfptr, v8)) == 0 )
        v7 = (__int64)v6;
    }
    else
    {
      v7 = 0i64;
    }
    if ( (ptr >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v13 + 16i64))(v13, &v11, v12);
      v13 = 0i64;
    }
    ptr = 6;
    v12 = v7;
    Scaleform::GFx::Movie::Invoke(v3, "SetVisible", 0i64, &pargs, 2u);
    UFG::qString::~qString(&v23);
    `eh vector destructor iterator'(&pargs, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    `eh vector destructor iterator'(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 743
// RVA: 0x5F3FA0
void __fastcall UFG::UIHKScreenSplash::PlayDemo(UFG::UIHKScreenSplash *this)
{
  UFG::UIHKScreenSplash *v1; // rdi
  UFG::GameStatTracker *v2; // rax
  signed int v3; // eax

  v1 = this;
  this->mState = 1;
  UFG::MoviePlayer::Close(&this->HKUIMovie);
  UFG::MoviePlayer::Init(&v1->HKUIMovie, UFG::UIHKScreenSplash::gDemoMovieFile, 0i64, 0x28u);
  v2 = UFG::GameStatTracker::Instance();
  v3 = UFG::GameStatTracker::GetStat(v2, VolumeSFX);
  UFG::MoviePlayer::SetAudioVolume(&v1->HKUIMovie, 0, (signed int)(float)((float)v3 * 2000.0));
  UFG::UIHKScreenSplash::SetScreenVisible(v1, 0);
}

// File Line: 769
// RVA: 0x5F4100
void __fastcall UFG::UIHKScreenSplash::PlaySplash(UFG::UIHKScreenSplash *this)
{
  UFG::UIHKScreenSplash *v1; // rdi
  UFG::GameStatTracker *v2; // rax
  signed int v3; // eax

  v1 = this;
  this->mState = 3;
  UFG::MoviePlayer::Close(&this->HKUIMovie);
  UFG::MoviePlayer::Init(&v1->HKUIMovie, UFG::UIHKScreenSplash::gMainMovieFile, 0i64, 0x24u);
  v2 = UFG::GameStatTracker::Instance();
  v3 = UFG::GameStatTracker::GetStat(v2, VolumeSFX);
  UFG::MoviePlayer::SetAudioVolume(&v1->HKUIMovie, 0, (signed int)(float)((float)v3 * 2000.0));
  UFG::UIHKScreenSplash::SetScreenVisible(v1, 1);
  v1->mPressStartTimer = 0.0;
}

// File Line: 786
// RVA: 0x5F0A70
void __fastcall UFG::UIHKScreenSplash::LoadGameOptions(UFG::UIHKScreenSplash *this)
{
  UFG::UIHKScreenSplash *v1; // rbx
  UFG::GameStatTracker *v2; // rax
  UFG::GameStatTracker *v3; // rax
  UFG::CachedLeaderboardManager *v4; // rax
  UFG::OSuiteManager *v5; // rax
  UFG::GameSaveLoad *v6; // rax

  v1 = this;
  v2 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::Initialize(v2);
  v3 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::Reset(v3, 1);
  UFG::StatGameManager::FinishCurrentStats(UFG::StatGameManager::sInstance);
  v4 = UFG::CachedLeaderboardManager::Instance();
  UFG::CachedLeaderboardManager::ClearCachedLeaderboards(v4);
  v5 = UFG::OSuiteManager::Instance();
  v5->m_bOSuiteFriendsUpdated = 0;
  v5->m_rOSuiteFriendsUpdateTimer = 0.0;
  UFG::DataSynchronizer::m_bIsOptionSaveDataSynchronized = 0;
  UFG::DataSynchronizer::s_bPastOptionLoad = 0;
  if ( UFG::HDDmanager::mInstance->m_eSaveLoadPermission & 1 )
  {
    v6 = UFG::GameSaveLoad::Instance();
    UFG::GameSaveLoad::LoadGameOptions(v6);
  }
  v1->mState = 5;
}

// File Line: 818
// RVA: 0x5D6F00
void __fastcall UFG::UIHKScreenSplash::DoInitLoad(UFG::UIHKScreenSplash *this)
{
  UFG::UIHKScreenSplash *v1; // rbx
  UFG::GameSaveLoad *v2; // rax

  v1 = this;
  if ( UFG::HDDmanager::mInstance->m_eSaveLoadPermission & 1 )
  {
    v2 = UFG::GameSaveLoad::Instance();
    UFG::GameSaveLoad::LoadSaveDataFileList(v2);
    v1->mState = 6;
  }
  else
  {
    this->mState = 6;
  }
}

// File Line: 842
// RVA: 0x5D7AD0
void __fastcall UFG::UIHKScreenSplash::Exit(UFG::UIHKScreenSplash *this)
{
  UFG::UIHKScreenSplash *v1; // rbx
  UFG::UIScreenTextureManager *v2; // rax
  UFG::UIScreenTextureManager *v3; // rax

  v1 = this;
  this->mState = 11;
  UFG::MoviePlayer::Close(&this->HKUIMovie);
  UFG::UIScreenManagerBase::queuePopScreen(
    (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
    v1->mScreenUID);
  if ( UFG::GameSaveLoad::Instance()->m_GameSlotHeaderInfo[5].m_State == 5
    && UFG::HDDmanager::mInstance->m_eSaveLoadPermission & 1 )
  {
    v2 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::QueueLoadAndPush(v2, "MainMenu", 0i64);
  }
  else
  {
    v3 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::QueueLoadAndPush(v3, "Options_Calibration", 0i64);
  }
}

