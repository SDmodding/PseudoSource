// File Line: 82
// RVA: 0x5C7440
void __fastcall UFG::UIHKScreenSplash::UIHKScreenSplash(UFG::UIHKScreenSplash *this)
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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenSplash::`vftable;
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
  UFG::UIScreenTextureManager *v2; // rax

  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenSplash::`vftable;
  UFG::MoviePlayer::Close(&this->HKUIMovie);
  v2 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v2, "Splash");
  UFG::StreamFileWrapper::SetSupressCaching_Splash(0);
  UFG::MoviePlayer::~MoviePlayer(&this->HKUIMovie);
  UFG::UIScreen::~UIScreen(this);
}

// File Line: 99
// RVA: 0x636560
void __fastcall UFG::UIHKScreenSplash::init(UFG::UIHKScreenSplash *this, UFG::UICommandData *data)
{
  UFG::UIScreen::init(this, data);
  if ( UFG::UIHKScreenSplash::mUseAttractMode )
  {
    this->mInAttractMode = 1;
    UFG::UIHKScreenSplash::mUseAttractMode = 0;
  }
  if ( !this->mInAttractMode )
  {
    gUIHorizontalResolution = (float)Render::GetBackBufferTarget()->mWidth;
    gUIVerticalResolution = (float)Render::GetBackBufferTarget()->mHeight;
    gIsUIHighDef = gUIVerticalResolution >= 720.0;
    UFG::UIScreenManagerBase::setFontScale(UFG::UIScreenManager::s_instance, 1.0);
  }
  UFG::UIHKScreenSplash::PlayDemo(this);
}

// File Line: 145
// RVA: 0x63FE30
void __fastcall UFG::UIHKScreenSplash::update(UFG::UIHKScreenSplash *this, float elapsed)
{
  int v3; // edx
  hkGeometryUtils::IVertices *v4; // rcx
  int v5; // r8d
  float v6; // xmm0_4
  UFG::GameSaveLoad *v7; // rax
  UFG::GameSaveLoad *v8; // rax

  if ( this == (UFG::UIHKScreenSplash *)UFG::UIScreenManagerBase::getTopScreen(UFG::UIScreenManager::s_instance) )
  {
    if ( this->mStartMusic
      && Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(v4, v3, v5)
      && !UFG::UIHKScreenSplash::smMusicPlaying )
    {
      UFG::TiDo::GetIsInstantiated();
    }
    switch ( this->mState )
    {
      case STATE_QUEUED:
        if ( (this->HKUIMovie.mFlags & 1) != 0 )
          this->mState = STATE_WAITING;
        break;
      case STATE_WAITING:
        if ( (this->HKUIMovie.mFlags & 1) != 0 )
          UFG::UIHKScreenSplash::PlaySplash(this);
        break;
      case STATE_EXECUTING:
        v6 = elapsed + this->mPressStartTimer;
        this->mPressStartTimer = v6;
        if ( v6 > 20.0 )
        {
          UFG::UIHKScreenSplash::PlayDemo(this);
          if ( UFG::UIHKScreenSplash::smMusicPlaying )
          {
            UFG::AudioEntity::StopAllEvents((unsigned __int64)UFG::Music::sm_instance);
            UFG::UIHKScreenSplash::smMusicPlaying = 0;
            this->mStartMusic = 0;
          }
        }
        break;
      case STATE_DONE:
        UFG::UIHKScreenSplash::DoInitLoad(this);
        break;
      case STATE_SYNCED:
        v8 = UFG::GameSaveLoad::Instance();
        if ( !(unsigned int)UFG::GameSaveLoad::GetOperation(v8) && !UFG::UIScreenDialogBox::m_iDialogBoxRefCount )
        {
          UFG::DataSynchronizer::s_bPastOptionLoad = 1;
          UFG::DataSynchronizer::UpdateOptionSaveDataIfNeeded();
          this->mState = 8;
          UFG::UIHKScreenDialogBox::createSaveLoadNotificationDialog(this);
          UFG::UIHKScreenSplash::smAutoSaveDisplayed = 1;
        }
        break;
      case STATE_DONE|STATE_WAITING:
        v7 = UFG::GameSaveLoad::Instance();
        if ( !(unsigned int)UFG::GameSaveLoad::GetOperation(v7) && !UFG::UIScreenDialogBox::m_iDialogBoxRefCount )
          UFG::UIHKScreenSplash::LoadGameOptions(this);
        break;
      default:
        break;
    }
    UFG::UIScreen::update(this, elapsed);
  }
}

// File Line: 337
// RVA: 0x62C040
bool __fastcall UFG::UIHKScreenSplash::handleMessage(
        UFG::UIHKScreenSplash *this,
        unsigned int msgId,
        UFG::UIMessage *msg)
{
  bool result; // al
  bool v7; // zf
  __int64 ControllerIndex; // rsi
  hkgpIndexedMesh::EdgeBarrier *Instance; // rax
  signed int i; // ebx
  UFG::TiDo *v11; // rax
  UFG::TiDo *v12; // rax

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
      this->mState = STATE_WAITING;
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
        v7 = msgId == UI_HASH_DIALOG_OK_CONTROLLER_DISCONNECTED_9;
LABEL_14:
        if ( v7 )
          UFG::UIHKScreenSplash::PlayDemo(this);
        goto $LN3_58;
      }
      ControllerIndex = UFG::UIInputHandler::getControllerIndex(SHIDWORD(msg[1].vfptr));
      Instance = (hkgpIndexedMesh::EdgeBarrier *)UserManager::GetInstance();
      Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
        Instance,
        (hkgpIndexedMeshDefinitions::Edge *)(unsigned int)ControllerIndex);
      for ( i = 0; i < 4; ++i )
      {
        v11 = UFG::TiDo::GetInstance();
        UFG::TiDo::UnregisterControllerForEvents(v11, i);
      }
      if ( !UFG::gInputSystem->mControllers[ControllerIndex]->m_IsKeyboardController )
      {
        v12 = UFG::TiDo::GetInstance();
        UFG::TiDo::RegisterControllerForEvents(v12, ControllerIndex);
      }
      this->mState = STATE_DONE;
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
        this->mState = STATE_EXECUTING;
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
        this->mState = STATE_DONE;
      }
      else if ( msgId == UI_HASH_DIALOG_NO_30 )
      {
        this->mState = STATE_EXECUTING;
      }
      goto $LN3_58;
    default:
$LN3_58:
      result = UFG::UIScreen::handleMessage(this, msgId, msg);
      break;
  }
  return result;
}

// File Line: 658
// RVA: 0x5EE3E0
bool __fastcall UFG::UIHKScreenSplash::IsKeyboardAndMouseContinue(
        UFG::UIHKScreenSplash *this,
        unsigned int msgId,
        UFG::UIMessage *msg)
{
  UFG::UIMessage::UIMessageType m_messageType; // ecx
  bool result; // al

  result = 0;
  if ( UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
  {
    m_messageType = msg->m_messageType;
    if ( (m_messageType & 0xFFFFFFFD) == 0 || m_messageType == UIMESSAGE_MOUSE_INPUT && msgId != UI_HASH_MOUSE_MOVE_30 )
      return 1;
  }
  return result;
}

// File Line: 711
// RVA: 0x607360
void __fastcall UFG::UIHKScreenSplash::SetScreenVisible(UFG::UIHKScreenSplash *this, bool visible)
{
  Scaleform::GFx::Movie *pObject; // rsi
  bool m_IsKeyboardController; // di
  const char *v5; // rdx
  char *mData; // rbx
  __int64 v7; // rdi
  __int64 v8; // rdx
  UFG::UIGfxTranslator *m_translator; // rcx
  Scaleform::GFx::Value pargs; // [rsp+30h] [rbp-B8h] BYREF
  char v11[8]; // [rsp+60h] [rbp-88h] BYREF
  __int64 v12; // [rsp+68h] [rbp-80h]
  __int64 v13; // [rsp+70h] [rbp-78h]
  Scaleform::GFx::Value ptr; // [rsp+78h] [rbp-70h] BYREF
  char v15[16]; // [rsp+A8h] [rbp-40h] BYREF
  __int64 v16; // [rsp+B8h] [rbp-30h]
  int v17; // [rsp+C0h] [rbp-28h]
  __int64 v18; // [rsp+C8h] [rbp-20h]
  __int64 v19; // [rsp+D8h] [rbp-10h]
  UFG::qString v20; // [rsp+E0h] [rbp-8h] BYREF

  v19 = -2i64;
  pObject = this->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    m_IsKeyboardController = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController;
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
    ptr.mValue.NValue = DOUBLE_1_0;
    if ( (v17 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v16 + 16i64))(v16, v15, v18);
      v16 = 0i64;
    }
    v17 = 5;
    v18 = 0i64;
    Scaleform::GFx::Movie::Invoke(pObject, "SetVersionText", 0i64, &ptr, 2u);
    `eh vector constructor iterator(&pargs, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( (pargs.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        pargs.mValue);
      pargs.pObjectInterface = 0i64;
    }
    pargs.Type = VT_Boolean;
    pargs.mValue.BValue = visible;
    v5 = "SPLASH_PRESS_START_DURANGO";
    if ( m_IsKeyboardController )
      v5 = "SPLASH_PRESS_START_PC";
    UFG::qString::qString(&v20, v5);
    mData = v20.mData;
    if ( v20.mData )
    {
      if ( *v20.mData == 36 )
        mData = v20.mData + 1;
      v8 = (unsigned int)UFG::qStringHashUpper32(mData, -1);
      m_translator = UFG::UIScreenManager::s_instance->m_translator;
      if ( !m_translator || (v7 = (__int64)m_translator->vfptr[5].__vecDelDtor(m_translator, v8)) == 0 )
        v7 = (__int64)mData;
    }
    else
    {
      v7 = 0i64;
    }
    if ( ((__int64)ptr.pPrev & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v13 + 16i64))(v13, v11, v12);
      v13 = 0i64;
    }
    LODWORD(ptr.pPrev) = 6;
    v12 = v7;
    Scaleform::GFx::Movie::Invoke(pObject, "SetVisible", 0i64, &pargs, 2u);
    UFG::qString::~qString(&v20);
    `eh vector destructor iterator(&pargs, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 743
// RVA: 0x5F3FA0
void __fastcall UFG::UIHKScreenSplash::PlayDemo(UFG::UIHKScreenSplash *this)
{
  UFG::GameStatTracker *v2; // rax
  int Stat; // eax

  this->mState = STATE_QUEUED;
  UFG::MoviePlayer::Close(&this->HKUIMovie);
  UFG::MoviePlayer::Init(&this->HKUIMovie, UFG::UIHKScreenSplash::gDemoMovieFile, 0i64, 0x28u);
  v2 = UFG::GameStatTracker::Instance();
  Stat = UFG::GameStatTracker::GetStat(v2, VolumeSFX);
  UFG::MoviePlayer::SetAudioVolume(&this->HKUIMovie, 0, (int)(float)((float)Stat * 2000.0));
  UFG::UIHKScreenSplash::SetScreenVisible(this, 0);
}

// File Line: 769
// RVA: 0x5F4100
void __fastcall UFG::UIHKScreenSplash::PlaySplash(UFG::UIHKScreenSplash *this)
{
  UFG::GameStatTracker *v2; // rax
  int Stat; // eax

  this->mState = STATE_EXECUTING;
  UFG::MoviePlayer::Close(&this->HKUIMovie);
  UFG::MoviePlayer::Init(&this->HKUIMovie, UFG::UIHKScreenSplash::gMainMovieFile, 0i64, 0x24u);
  v2 = UFG::GameStatTracker::Instance();
  Stat = UFG::GameStatTracker::GetStat(v2, VolumeSFX);
  UFG::MoviePlayer::SetAudioVolume(&this->HKUIMovie, 0, (int)(float)((float)Stat * 2000.0));
  UFG::UIHKScreenSplash::SetScreenVisible(this, 1);
  this->mPressStartTimer = 0.0;
}

// File Line: 786
// RVA: 0x5F0A70
void __fastcall UFG::UIHKScreenSplash::LoadGameOptions(UFG::UIHKScreenSplash *this)
{
  UFG::GameStatTracker *v2; // rax
  UFG::GameStatTracker *v3; // rax
  UFG::CachedLeaderboardManager *v4; // rax
  UFG::OSuiteManager *v5; // rax
  UFG::GameSaveLoad *v6; // rax

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
  if ( (UFG::HDDmanager::mInstance->m_eSaveLoadPermission & 1) != 0 )
  {
    v6 = UFG::GameSaveLoad::Instance();
    UFG::GameSaveLoad::LoadGameOptions(v6);
  }
  this->mState = STATE_SYNCED;
}

// File Line: 818
// RVA: 0x5D6F00
void __fastcall UFG::UIHKScreenSplash::DoInitLoad(UFG::UIHKScreenSplash *this)
{
  UFG::GameSaveLoad *v2; // rax

  if ( (UFG::HDDmanager::mInstance->m_eSaveLoadPermission & 1) != 0 )
  {
    v2 = UFG::GameSaveLoad::Instance();
    UFG::GameSaveLoad::LoadSaveDataFileList(v2);
    this->mState = STATE_DONE|STATE_WAITING;
  }
  else
  {
    this->mState = STATE_DONE|STATE_WAITING;
  }
}

// File Line: 842
// RVA: 0x5D7AD0
void __fastcall UFG::UIHKScreenSplash::Exit(UFG::UIHKScreenSplash *this)
{
  UFG::UIScreenTextureManager *v2; // rax
  UFG::UIScreenTextureManager *v3; // rax

  this->mState = STATE_EXECUTING|0x8;
  UFG::MoviePlayer::Close(&this->HKUIMovie);
  UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, this->mScreenUID);
  if ( UFG::GameSaveLoad::Instance()->m_GameSlotHeaderInfo[5].m_State == SAVE_GAME_HEADER_STATE_VALID
    && (UFG::HDDmanager::mInstance->m_eSaveLoadPermission & 1) != 0 )
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

