// File Line: 67
// RVA: 0x156E070
__int64 UFG::_dynamic_initializer_for__gUIGarageScreenDeferredTaskChannel__()
{
  UFG::ChannelObj::ChannelObj(&UFG::gUIGarageScreenDeferredTaskChannel, "EVT_UI_GARAGE_DEFERRED_TASK_CHANNEL", 0i64);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gUIGarageScreenDeferredTaskChannel__);
}

// File Line: 77
// RVA: 0x1567520
__int64 dynamic_initializer_for__UFG::UIHKScreenGarageBrowser::mVehicleOrderOverride__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::UIHKScreenGarageBrowser::mVehicleOrderOverride__);
}

// File Line: 95
// RVA: 0x5C5470
void __fastcall UFG::UIHKScreenGarageBrowser::UIHKScreenGarageBrowser(UFG::UIHKScreenGarageBrowser *this)
{
  fastdelegate::FastDelegate1<UFG::Event *,void> v2; // [rsp+38h] [rbp-20h] BYREF

  this->UFG::UIHKTaskableScreen::UFG::UIScreen::UFG::qNode<UFG::UIScreen,UFG::UIScreen>::mPrev = &this->UFG::qNode<UFG::UIScreen,UFG::UIScreen>;
  this->UFG::UIHKTaskableScreen::UFG::UIScreen::UFG::qNode<UFG::UIScreen,UFG::UIScreen>::mNext = &this->UFG::qNode<UFG::UIScreen,UFG::UIScreen>;
  this->UFG::UIHKTaskableScreen::UFG::UIScreen::vfptr = (UFG::UIScreenVtbl *)&UFG::UIScreen::`vftable;
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
  this->UFG::UIHKTaskableScreen::UFG::UIScreen::vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKTaskableScreen::`vftable;
  this->mFinished = 0;
  this->UFG::OnlineManagerObserver::UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver>::mPrev = &this->UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver>;
  this->UFG::OnlineManagerObserver::UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver>::mNext = &this->UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver>;
  this->UFG::OnlineManagerObserver::vfptr = (UFG::OnlineManagerObserverVtbl *)&UFG::OnlineManagerObserver::`vftable;
  this->UFG::UIHKTaskableScreen::UFG::UIScreen::vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenGarageBrowser::`vftable{for `UFG::UIHKTaskableScreen};
  this->UFG::OnlineManagerObserver::vfptr = (UFG::OnlineManagerObserverVtbl *)&UFG::UIHKScreenGarageBrowser::`vftable{for `UFG::OnlineManagerObserver};
  this->mHelpBarState = HELP_NONE;
  *(_QWORD *)&this->mState = 0i64;
  this->mVehicleList.p = 0i64;
  *(_QWORD *)&this->mVehicleList.size = 0i64;
  UFG::qString::qString(&this->mTexturePackToLoad);
  `eh vector constructor iterator(this->mCarTextures, 0x28ui64, 3, (void (__fastcall *)(void *))UFG::qString::qString);
  *(_QWORD *)&this->m_iTextureHandleIndex = 0i64;
  this->m_pSimObjVehicle = 0i64;
  UFG::UIHKDepthOfFieldWidget::UIHKDepthOfFieldWidget(&this->DOF);
  this->mLoadingTimeout = 0.0;
  *(_DWORD *)&this->m_bFadeOutAndTeleportPlayer = 257;
  *(_WORD *)&this->mInfoTickerViewed = 0;
  this->mCurrentVehicle = 0i64;
  v2.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::UIHKScreenGarageBrowser::HandleDeferredTask;
  v2.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)Assembly::GetRCX(this);
  UFG::EventDispatcher::Register(
    &UFG::EventDispatcher::mInstance,
    &v2,
    UFG::gUIGarageScreenDeferredTaskChannel.mUID,
    0i64,
    0);
  UFG::UIHKScreenGarageBrowser::mPlayerBackedOut = 0;
  UFG::UIHKScreenGarageBrowser::mSkipCustomization = 0;
  if ( UFG::ProgressionTracker::Instance()->mModeType == ModeType_Challenge )
    this->m_bBackbuttonEnabled = 0;
}

// File Line: 115
// RVA: 0x5CAC30
void __fastcall UFG::UIHKScreenGarageBrowser::~UIHKScreenGarageBrowser(UFG::UIHKScreenGarageBrowser *this)
{
  UFG::OnlineManagerObserver *v2; // r15
  UFG::OnlineManager *v3; // rax
  UFG::UI *v4; // rcx
  UFG::UIHKHelpBarWidget *p_HelpBar; // rbx
  unsigned int v6; // eax
  unsigned int v7; // eax
  int v8; // eax
  UFG::UIScreenTextureManager *v9; // rax
  char **p_mData; // rdi
  __int64 v11; // rsi
  const char *v12; // rbx
  UFG::UIScreenTextureManager *v13; // rax
  UFG::UIHKGarageVehicleInfo *p; // rcx
  unsigned int *p_discountPercent; // rbx
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *mPrev; // rcx
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *mNext; // rax
  fastdelegate::FastDelegate1<UFG::Event *,void> v18; // [rsp+28h] [rbp-40h] BYREF

  this->UFG::UIHKTaskableScreen::UFG::UIScreen::vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenGarageBrowser::`vftable{for `UFG::UIHKTaskableScreen};
  v2 = &this->UFG::OnlineManagerObserver;
  this->UFG::OnlineManagerObserver::vfptr = (UFG::OnlineManagerObserverVtbl *)&UFG::UIHKScreenGarageBrowser::`vftable{for `UFG::OnlineManagerObserver};
  v3 = UFG::OnlineManager::Instance();
  UFG::OSuiteManager::UnRegisterObserver(v3, v2);
  v18.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::UIHKScreenGarageBrowser::HandleDeferredTask;
  v18.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)Assembly::GetRCX(this);
  UFG::EventDispatcher::UnRegister(&UFG::EventDispatcher::mInstance, &v18, UFG::gUIGarageScreenDeferredTaskChannel.mUID);
  if ( UFG::UIHKScreenGlobalOverlay::mThis )
  {
    p_HelpBar = &UFG::UIHKScreenGlobalOverlay::mThis->HelpBar;
    v6 = UFG::qStringHash32("GARAGE", 0xFFFFFFFF);
    UFG::UIHKHelpBarWidget::Hide(p_HelpBar, v6);
  }
  if ( UFG::gInputSystem )
  {
    if ( UFG::gActiveControllerNum != -1 )
    {
      v7 = UFG::UI::gUIInputLocked;
      if ( !UFG::UI::gUIInputLocked || (--UFG::UI::gUIInputLocked, v7 == 1) )
        UFG::UI::ResetGameplayInput(v4);
    }
  }
  if ( byte_142431A14 && UFG::UIHK_PDAWidget::mInputLocked )
  {
    UFG::SetInputMode_PDA_Off(UFG::gActiveControllerNum);
    v8 = UFG::UIHKGameplayHelpWidget::mLocked;
    if ( UFG::UIHKGameplayHelpWidget::mLocked > 0 )
      v8 = --UFG::UIHKGameplayHelpWidget::mLocked;
    if ( v8 < 1 )
      UFG::UIHKScreenHud::GameplayHelp->mChanged = 1;
    --UFG::UIHK_PDAWidget::mInputLocked;
  }
  UFG::UIHKScreenHud::PDACache.state = STATE_IDLE;
  byte_142431A14 = 0;
  dword_142431A18 = 0;
  v9 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v9, "GarageBrowser");
  p_mData = &this->mCarTextures[0].mData;
  v11 = 3i64;
  do
  {
    v12 = *p_mData;
    v13 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::ReleaseTexturePack(v13, v12);
    p_mData += 5;
    --v11;
  }
  while ( v11 );
  UFG::GameCameraComponent::EndDOFOverride(DOFOverridePriority_0);
  `eh vector destructor iterator(this->mCarTextures, 0x28ui64, 3, (void (__fastcall *)(void *))UFG::qString::~qString);
  UFG::qString::~qString(&this->mTexturePackToLoad);
  p = this->mVehicleList.p;
  if ( p )
  {
    p_discountPercent = &p[-1].discountPercent;
    `eh vector destructor iterator(
      p,
      0x110ui64,
      p[-1].discountPercent,
      (void (__fastcall *)(void *))UFG::UIHKGarageVehicleInfo::~UIHKGarageVehicleInfo);
    operator delete[](p_discountPercent);
  }
  this->mVehicleList.p = 0i64;
  *(_QWORD *)&this->mVehicleList.size = 0i64;
  v2->vfptr = (UFG::OnlineManagerObserverVtbl *)&UFG::OnlineManagerObserver::`vftable;
  mPrev = v2->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = &v2->UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver>;
  v2->mNext = &v2->UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver>;
  UFG::UIScreen::~UIScreen(this);
}

// File Line: 148
// RVA: 0x6128E0
void __fastcall UFG::UIHKScreenGarageBrowser::TextureLoadedCallback(UFG::DataStreamer::Handle *handle, void *param)
{
  UFG::UIHKScreenGarageBrowser *Screen; // rax

  Screen = (UFG::UIHKScreenGarageBrowser *)UFG::UIScreenManagerBase::getScreen(
                                             UFG::UIScreenManager::s_instance,
                                             "GarageBrowser");
  if ( Screen )
    UFG::UIHKScreenGarageBrowser::LoadTextureInFlash(Screen);
}

// File Line: 158
// RVA: 0x5F12B0
void __fastcall UFG::UIHKScreenGarageBrowser::LoadTextureInFlash(UFG::UIHKScreenGarageBrowser *this)
{
  Scaleform::GFx::Movie *pObject; // rdi
  char *mData; // rbx
  UFG::qString v4; // [rsp+38h] [rbp-60h] BYREF
  Scaleform::GFx::Value pargs; // [rsp+60h] [rbp-38h] BYREF

  if ( this->mCurrentVehicle )
  {
    pObject = this->mRenderable->m_movie.pObject;
    `eh vector constructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    UFG::qString::qString(&v4);
    UFG::qString::Format(&v4, "img://%s", this->mCurrentVehicle->texture.mData);
    mData = v4.mData;
    if ( (pargs.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        pargs.mValue);
      pargs.pObjectInterface = 0i64;
    }
    pargs.Type = VT_String;
    pargs.mValue.pString = mData;
    Scaleform::GFx::Movie::Invoke(pObject, "SetTexture", 0i64, &pargs, 1u);
    UFG::qString::~qString(&v4);
    `eh vector destructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 173
// RVA: 0x5F13D0
void __fastcall UFG::UIHKScreenGarageBrowser::LoadTexturePack(UFG::UIHKScreenGarageBrowser *this)
{
  UFG::UIHKGarageVehicleInfo *mCurrentVehicle; // r8
  char *mData; // rbx
  UFG::UIScreenTextureManager *v4; // rax
  int m_iTextureHandleIndex; // eax
  char *v6; // rbx
  UFG::UIScreenTextureManager *v7; // rax

  mCurrentVehicle = this->mCurrentVehicle;
  if ( mCurrentVehicle )
  {
    UFG::qString::Format(&this->mTexturePackToLoad, "Data\\UI\\%s_TP.perm.bin", mCurrentVehicle->texture.mData);
    mData = this->mCarTextures[this->m_iPrevTextureHandleIndex].mData;
    v4 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::ReleaseTexturePack(v4, mData);
    m_iTextureHandleIndex = this->m_iTextureHandleIndex;
    this->m_iPrevTextureHandleIndex = m_iTextureHandleIndex++;
    this->m_iTextureHandleIndex = m_iTextureHandleIndex;
    if ( m_iTextureHandleIndex >= 3 )
      this->m_iTextureHandleIndex = 0;
    UFG::qString::Set(
      (UFG::qString *)((char *)this->mCarTextures + 32 * this->m_iTextureHandleIndex + 8 * this->m_iTextureHandleIndex),
      this->mTexturePackToLoad.mData,
      this->mTexturePackToLoad.mLength,
      0i64,
      0);
    v6 = this->mCarTextures[this->m_iTextureHandleIndex].mData;
    v7 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::QueueTexturePackLoad(
      v7,
      v6,
      HIGH_PRIORITY,
      (UFG::qReflectInventoryBase *)UFG::UIHKScreenGarageBrowser::TextureLoadedCallback,
      0i64);
  }
}

// File Line: 195
// RVA: 0x611270
void __fastcall UFG::UIHKScreenGarageBrowser::ShowTickerPopup(UFG::UIHKScreenGarageBrowser *this, bool isVisible)
{
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h] BYREF

  pargs.pObjectInterface = 0i64;
  pargs.Type = VT_Boolean;
  pargs.mValue.BValue = isVisible;
  Scaleform::GFx::Movie::Invoke(this->mRenderable->m_movie.pObject, "ShowTickerPopup", 0i64, &pargs, 1u);
  if ( isVisible )
    this->mInfoTickerViewed = 1;
  if ( (pargs.Type & 0x40) != 0 )
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      pargs.mValue);
}

// File Line: 205
// RVA: 0x631B90
void __fastcall UFG::UIHKScreenGarageBrowser::init(
        UFG::UIHKScreenGarageBrowser *this,
        hkgpIndexedMeshDefinitions::Edge *data)
{
  Scaleform::GFx::Movie *pObject; // rsi
  __int64 v5; // rbx
  UFG::Controller *v6; // r8
  UFG::OSuiteTickerManager *v7; // rax
  char *TickerDescription; // rbx
  hkpNullContactMgr *ContactMgr; // rax
  hkpCollidable *v10; // rdx
  hkpCollidable *v11; // r8
  hkpCollisionInput *v12; // r9
  UFG::OnlineManager *v13; // rax
  Scaleform::GFx::Value ptr; // [rsp+40h] [rbp-68h] BYREF
  char v15[16]; // [rsp+70h] [rbp-38h] BYREF
  __int64 v16; // [rsp+80h] [rbp-28h]
  int v17; // [rsp+88h] [rbp-20h]
  char *v18; // [rsp+90h] [rbp-18h]

  this->mIsRestricted = Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(0i64, data);
  UFG::UIScreen::init(this, (UFG::UICommandData *)data);
  pObject = this->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    v5 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
           Scaleform::Memory::pGlobalHeap,
           32i64);
    if ( v5 )
    {
      *(_QWORD *)v5 = &Scaleform::RefCountImplCore::`vftable;
      *(_DWORD *)(v5 + 8) = 1;
      *(_QWORD *)v5 = &Scaleform::RefCountImpl::`vftable;
      *(_QWORD *)v5 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
      *(_QWORD *)v5 = &Scaleform::RefCountBase<Scaleform::GFx::State,2>::`vftable;
      *(_QWORD *)v5 = &Scaleform::GFx::State::`vftable;
      *(_DWORD *)(v5 + 16) = 3;
      *(_QWORD *)v5 = &Scaleform::GFx::ActionControl::`vftable;
      *(_DWORD *)(v5 + 24) = 8;
    }
    else
    {
      v5 = 0i64;
    }
    if ( v5 )
    {
      *(_DWORD *)(v5 + 24) |= 2u;
      pObject->Scaleform::GFx::StateBag::vfptr->SetState(
        &pObject->Scaleform::GFx::StateBag,
        State_Filter,
        (Scaleform::GFx::State *)v5);
    }
    if ( v5 )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v5);
  }
  if ( UFG::gInputSystem && UFG::gActiveControllerNum != -1 )
  {
    v6 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum];
    if ( !UFG::UI::gUIInputLocked )
      g_saved_gameplay_controller_mode = v6->m_ActiveMapSet;
    UFG::SetInputMode(IM_UI_ONLY, v6->mControllerIndex);
    ++UFG::UI::gUIInputLocked;
  }
  if ( !UFG::UIHKScreenGlobalOverlay::mThis
    || UFG::UIHKScreenGlobalOverlay::mThis == (UFG::UIHKScreenGlobalOverlay *)-408i64
    || UFG::UIHKScreenGlobalOverlay::mThis->NISOverlay.mActive )
  {
    UFG::UIHKScreenGarageBrowser::AfterFadeToBlackInit(this);
  }
  else
  {
    this->mState = NUM_CALIBRATION_STATES|STATE_UISCALE;
    if ( UFG::UIHKScreenGlobalOverlay::mThis
      && UFG::UIHKScreenGlobalOverlay::mThis != (UFG::UIHKScreenGlobalOverlay *)-408i64 )
    {
      UFG::UIHK_NISOverlay::ShowElement(
        &UFG::UIHKScreenGlobalOverlay::mThis->NISOverlay,
        UFG::UIHKScreenGlobalOverlay::mThis,
        &UFG::UIHK_NISOverlay::m_curtains,
        0.33000001,
        0);
      UFG::UIHK_NISOverlay::m_curtains.m_mutingAudio = 0;
    }
    UFG::UIHK_NISOverlay::UpdateAudioMuteState();
  }
  UFG::UIGfxTranslator::loadDictionary(UFG::UIScreenManager::s_instance->m_translator, "ITEMS");
  `eh vector constructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  if ( (ptr.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
      ptr.pObjectInterface,
      &ptr,
      ptr.mValue);
    ptr.pObjectInterface = 0i64;
  }
  ptr.Type = VT_String;
  ptr.mValue.pString = "img://INFOCAST_CHANNEL_2";
  v7 = UFG::OSuiteTickerManager::Instance();
  TickerDescription = UFG::OSuiteTickerManager::GetTickerDescription(v7, (hkgpIndexedMeshDefinitions::Edge *)2, 1);
  if ( (v17 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v16 + 16i64))(v16, v15, v18);
    v16 = 0i64;
  }
  v17 = 6;
  v18 = TickerDescription;
  Scaleform::GFx::Movie::Invoke(this->mRenderable->m_movie.pObject, "SetTickerPopupInfo", 0i64, &ptr, 2u);
  UFG::UIHKScreenGarageBrowser::ShowTickerPopup(this, this->mInfoTickerPopupVisible);
  ContactMgr = (hkpNullContactMgr *)UFG::StoreFrontTracker::Instance();
  if ( ContactMgr )
    ContactMgr = hkpNullContactMgrFactory::createContactMgr((hkpNullContactMgrFactory *)ContactMgr, v10, v11, v12);
  this->mStore = (UFG::StoreFront *)ContactMgr;
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xF41B2F0D, 0i64, 0, 0i64);
  v13 = UFG::OnlineManager::Instance();
  UFG::OnlineManager::RegisterObserver(v13, &this->UFG::OnlineManagerObserver);
  `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 263
// RVA: 0x5D3560
void __fastcall UFG::UIHKScreenGarageBrowser::AfterFadeToBlackInit(UFG::UIHKScreenGarageBrowser *this)
{
  hkpNullContactMgr *ContactMgr; // rax
  hkpCollidable *v3; // rdx
  hkpCollidable *v4; // r8
  hkpCollisionInput *v5; // r9
  UFG::StoreFront *mStore; // rcx
  UFG::qString *StoreTitle; // rax
  UFG::qString *StoreDesc; // rax
  UFG::GameStatTracker *v9; // rax
  hkpNullContactMgr *v10; // rax
  hkpCollidable *v11; // rdx
  hkpCollidable *v12; // r8
  hkpCollisionInput *v13; // r9
  UFG::qBaseNodeRB *CameraMarker; // rax
  UFG::TransformNodeComponent *v15; // rsi
  UFG::SimObject *m_pSimObject; // rcx
  UFG::ScriptCameraComponent *ComponentOfType; // rax
  UFG::ScriptCameraComponent *v18; // rdi
  bool v19; // di
  Scaleform::GFx::Movie *pObject; // rbx
  UFG::qString result; // [rsp+38h] [rbp-60h] BYREF
  Scaleform::GFx::Value ptr; // [rsp+60h] [rbp-38h] BYREF

  ContactMgr = (hkpNullContactMgr *)UFG::StoreFrontTracker::Instance();
  if ( ContactMgr )
    ContactMgr = hkpNullContactMgrFactory::createContactMgr((hkpNullContactMgrFactory *)ContactMgr, v3, v4, v5);
  this->mStore = (UFG::StoreFront *)ContactMgr;
  UFG::StoreFront::ClosePreviewShutter((UFG::StoreFront *)ContactMgr);
  mStore = this->mStore;
  this->m_bFadeOutAndTeleportPlayer = mStore->mStoreType != StoreType_Race;
  if ( ((mStore->mStoreType - 1) & 0xFFFFFFFD) != 0 )
  {
    UFG::UIHKScreenGarageBrowser::SetStoreTitle(this, "$GARAGE_TITLE");
    UFG::UIHKScreenGarageBrowser::SetStoreDesc(this, &customCaption);
  }
  else
  {
    StoreTitle = UFG::StoreFront::GetStoreTitle(mStore, &result);
    UFG::UIHKScreenGarageBrowser::SetStoreTitle(this, StoreTitle->mData);
    UFG::qString::~qString(&result);
    StoreDesc = UFG::StoreFront::GetStoreDesc(this->mStore, &result);
    UFG::UIHKScreenGarageBrowser::SetStoreDesc(this, StoreDesc->mData);
    UFG::qString::~qString(&result);
  }
  v9 = UFG::GameStatTracker::Instance();
  if ( UFG::GameStatTracker::GetStat(v9, EnableValet) )
    UFG::UIHKScreenGarageBrowser::SetValetTitle(this, "$GARAGE_NOVALETCAR");
  UFG::UIHKScreenGarageBrowser::PopulateInventory(this);
  ((void (__fastcall *)(UFG::TiDo *, __int64))UFG::TiDo::m_pInstance->vfptr[1].Close)(UFG::TiDo::m_pInstance, 5i64);
  v10 = (hkpNullContactMgr *)UFG::StoreFrontTracker::Instance();
  if ( v10 )
    v10 = hkpNullContactMgrFactory::createContactMgr((hkpNullContactMgrFactory *)v10, v11, v12, v13);
  UFG::VendorDialogueUtils::Setup((UFG::StoreFront *)v10);
  UFG::VendorDialogueUtils::PlayStoreClerkDialogue(eStoreClerkDialogueContext_Greet, 1.0);
  if ( this->mNumItems <= 0 )
  {
    this->mState = NUM_CALIBRATION_STATES;
  }
  else
  {
    CameraMarker = UFG::StoreFront::GetCameraMarker(this->mStore);
    if ( CameraMarker )
    {
      v15 = *(UFG::TransformNodeComponent **)&CameraMarker[2].mUID;
      m_pSimObject = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
      if ( m_pSimObject )
      {
        ComponentOfType = (UFG::ScriptCameraComponent *)UFG::SimObject::GetComponentOfType(
                                                          m_pSimObject,
                                                          UFG::ScriptCameraComponent::_TypeUID);
        v18 = ComponentOfType;
        if ( ComponentOfType )
        {
          UFG::ScriptCameraComponent::SwitchToScriptCam(ComponentOfType, v15, 0, 0.0);
          ((void (__fastcall *)(UFG::ScriptCameraComponent *))v18->vfptr[15].__vecDelDtor)(v18);
        }
      }
    }
    this->mState = STATE_BRIGHTNESS;
  }
  v19 = this->mStore->mStoreType == StoreType_Retail;
  pObject = this->mRenderable->m_movie.pObject;
  `eh vector constructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  if ( (ptr.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
      ptr.pObjectInterface,
      &ptr,
      ptr.mValue);
    ptr.pObjectInterface = 0i64;
  }
  ptr.Type = VT_Boolean;
  ptr.mValue.BValue = v19;
  Scaleform::GFx::Movie::Invoke(pObject, "SetIsStore", 0i64, &ptr, 1u);
  if ( UFG::UIHKScreenGlobalOverlay::mThis
    && UFG::UIHKScreenGlobalOverlay::mThis != (UFG::UIHKScreenGlobalOverlay *)-408i64 )
  {
    UFG::UIHK_NISOverlay::HideElement(
      &UFG::UIHKScreenGlobalOverlay::mThis->NISOverlay,
      UFG::UIHKScreenGlobalOverlay::mThis,
      &UFG::UIHK_NISOverlay::m_curtains,
      1.0,
      0);
  }
  UFG::UIHK_NISOverlay::UpdateAudioMuteState();
  `eh vector destructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 337
// RVA: 0x609AF0
void __fastcall UFG::UIHKScreenGarageBrowser::SetStoreTitle(UFG::UIHKScreenGarageBrowser *this, const char *title)
{
  Scaleform::GFx::Movie *pObject; // rbx
  UFG::GameStatTracker *v4; // rax
  Scaleform::GFx::Value v5; // [rsp+20h] [rbp-11h] BYREF
  Scaleform::GFx::Value value; // [rsp+50h] [rbp+1Fh] BYREF

  pObject = this->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    value.pObjectInterface = 0i64;
    value.Type = VT_String;
    value.mValue.pString = title;
    Scaleform::GFx::Movie::SetVariable(pObject, "mcTitle.text", &value, 1i64);
    if ( ((this->mStore->mStoreType - 1) & 0xFFFFFFFD) != 0 )
    {
      v4 = UFG::GameStatTracker::Instance();
      if ( !UFG::GameStatTracker::GetStat(v4, EnableValet) )
      {
LABEL_10:
        if ( (value.Type & 0x40) != 0 )
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
            value.pObjectInterface,
            &value,
            value.mValue);
        return;
      }
      v5.pObjectInterface = 0i64;
      v5.Type = VT_Boolean;
      v5.mValue.BValue = 1;
      Scaleform::GFx::Movie::SetVariable(pObject, "mc_valet._visible", &v5, 1i64);
    }
    else
    {
      v5.pObjectInterface = 0i64;
      v5.Type = VT_Boolean;
      v5.mValue.BValue = 1;
      Scaleform::GFx::Movie::SetVariable(pObject, "mc_Money._visible", &v5, 1i64);
      if ( this->mStore->mStoreType == StoreType_Race )
        Scaleform::GFx::Movie::SetVariable(pObject, "gIsRace", &v5, 1i64);
    }
    if ( (v5.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&v5.pObjectInterface->vfptr->gap8[8])(
        v5.pObjectInterface,
        &v5,
        v5.mValue);
      v5.pObjectInterface = 0i64;
    }
    v5.Type = VT_Undefined;
    goto LABEL_10;
  }
}

// File Line: 364
// RVA: 0x60C570
void __fastcall UFG::UIHKScreenGarageBrowser::SetValetTitle(UFG::UIHKScreenGarageBrowser *this, const char *title)
{
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-40h] BYREF

  pObject = this->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    value.pObjectInterface = 0i64;
    value.Type = VT_String;
    value.mValue.pString = title;
    Scaleform::GFx::Movie::SetVariable(pObject, "mc_valet.mc_valet.txt_valet.text", &value, 1i64);
    if ( (value.Type & 0x40) != 0 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        value.mValue);
  }
}

// File Line: 378
// RVA: 0x609910
void __fastcall UFG::UIHKScreenGarageBrowser::SetStoreDesc(UFG::UIHKScreenGarageBrowser *this, const char *desc)
{
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value value; // [rsp+50h] [rbp+1Fh] BYREF

  pObject = this->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    value.pObjectInterface = 0i64;
    value.Type = VT_String;
    value.mValue.pString = desc;
    Scaleform::GFx::Movie::SetVariable(pObject, "mcDesc.text", &value, 1i64);
    if ( (value.Type & 0x40) != 0 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        value.mValue);
  }
}

// File Line: 405
// RVA: 0x605390
void __fastcall UFG::UIHKScreenGarageBrowser::SetAsValet(UFG::UIHKScreenGarageBrowser *this)
{
  UFG::GameStatTracker *v2; // rax
  UFG::UIHKGarageVehicleInfo *mCurrentVehicle; // rdi
  UFG::GameStatTracker *v4; // rax
  unsigned int i; // edx
  Scaleform::GFx::Movie *pObject; // rdi
  bool v7; // bl
  Scaleform::GFx::Value ptr; // [rsp+38h] [rbp-40h] BYREF

  if ( this->mState != NUM_CALIBRATION_STATES )
  {
    if ( this->mCurrentVehicle )
    {
      v2 = UFG::GameStatTracker::Instance();
      if ( UFG::GameStatTracker::GetStat(v2, EnableValet) && ((this->mStore->mStoreType - 1) & 0xFFFFFFFD) != 0 )
      {
        mCurrentVehicle = this->mCurrentVehicle;
        if ( mCurrentVehicle->bOwned )
        {
          v4 = UFG::GameStatTracker::Instance();
          UFG::GameStatTracker::SetStat(v4, ValetVehicle, &mCurrentVehicle->spawnObjectInfo);
          for ( i = 0; i < this->mVehicleList.size; ++i )
            this->mVehicleList.p[i].bValetVehicle = 0;
          this->mCurrentVehicle->bValetVehicle = 1;
          if ( UFG::HudAudio::m_instance )
            UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xF41B2F0D, 0i64, 0, 0i64);
          pObject = this->mRenderable->m_movie.pObject;
          if ( pObject )
          {
            `eh vector constructor iterator(
              &ptr,
              0x30ui64,
              1,
              (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
            v7 = this->mNumItems == 0;
            if ( (ptr.Type & 0x40) != 0 )
            {
              (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
                ptr.pObjectInterface,
                &ptr,
                ptr.mValue);
              ptr.pObjectInterface = 0i64;
            }
            ptr.Type = VT_Boolean;
            ptr.mValue.BValue = v7;
            Scaleform::GFx::Movie::Invoke(pObject, "VehicleList_UpdateValet", 0i64, &ptr, 1u);
            `eh vector destructor iterator(
              &ptr,
              0x30ui64,
              1,
              (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
          }
        }
        else
        {
          UFG::UIScreenDialogBox::createOKDialog(this, &customCaption, "$GARAGE_REQUIRES_PURCHASE", 1);
        }
      }
    }
  }
}

// File Line: 441
// RVA: 0x611C20
void __fastcall UFG::UIHKScreenGarageBrowser::SpawnVehicle(UFG::UIHKScreenGarageBrowser *this)
{
  UFG::UIHKGarageVehicleInfo *mCurrentVehicle; // rax
  UFG::SimObjectCVBase *v3; // rax
  UFG::SimObjectVehicle *v4; // rdi
  UFG::SimComponent *ComponentOfType; // rax
  UFG::VehicleOwnershipComponent *v6; // rax
  UFG::VehicleOwnershipComponent *v7; // rbp
  UFG::SimObject *OwnedVehicle; // rsi
  UFG::VehicleOccupantComponent *v9; // rax

  mCurrentVehicle = this->mCurrentVehicle;
  if ( mCurrentVehicle )
  {
    v3 = UFG::StoreFront::SpawnItem(this->mStore, mCurrentVehicle->storeIndex);
    v4 = (UFG::SimObjectVehicle *)v3;
    if ( v3 )
    {
      ComponentOfType = UFG::SimObject::GetComponentOfType(v3, UFG::SimObjectVehiclePropertiesComponent::_TypeUID);
      if ( ComponentOfType )
        LOBYTE(ComponentOfType[3].m_Flags) = 1;
    }
    if ( LocalPlayer )
    {
      v6 = (UFG::VehicleOwnershipComponent *)UFG::SimObject::GetComponentOfType(
                                               LocalPlayer,
                                               UFG::VehicleOwnershipComponent::_TypeUID);
      v7 = v6;
      if ( v6 )
      {
        OwnedVehicle = UFG::VehicleOwnershipComponent::GetOwnedVehicle(v6);
        UFG::VehicleOwnershipComponent::TakeOwnsership(v7, v4);
        if ( OwnedVehicle )
        {
          v9 = (UFG::VehicleOccupantComponent *)UFG::SimObject::GetComponentOfType(
                                                  OwnedVehicle,
                                                  UFG::VehicleOccupantComponent::_TypeUID);
          if ( !v9 || !(unsigned int)UFG::VehicleOccupantComponent::GetNumberOfOccupants(v9) )
            UFG::Simulation::QueueSimObjectToBeDestroyed(&UFG::gSim, OwnedVehicle);
        }
      }
    }
    this->m_pSimObjVehicle = v4;
    this->mState = STATE_VOLUME;
    this->mLoadingTimeout = 2.0;
  }
}

// File Line: 477
// RVA: 0x612CB0
void __fastcall UFG::UIHKScreenGarageBrowser::ToggleTickerPopup(UFG::UIHKScreenGarageBrowser *this)
{
  bool v2; // dl
  unsigned int v3; // edx

  v2 = !this->mInfoTickerPopupVisible;
  this->mInfoTickerPopupVisible = v2;
  UFG::UIHKScreenGarageBrowser::ShowTickerPopup(this, v2);
  UFG::UIHKScreenGarageBrowser::ShowHelpBar(this, this->mHelpBarState, this->mInfoTickerPopupVisible);
  if ( this->mInfoTickerPopupVisible )
  {
    if ( !UFG::HudAudio::m_instance )
      return;
    v3 = -1616300686;
  }
  else
  {
    if ( !UFG::HudAudio::m_instance )
      return;
    v3 = -782291096;
  }
  UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, v3, 0i64, 0, 0i64);
}

// File Line: 490
// RVA: 0x5EA8B0
void __fastcall UFG::UIHKScreenGarageBrowser::HandleDeferredTask(UFG::UIHKScreenGarageBrowser *this, UFG::Event *e)
{
  int mUserData0; // r8d
  UFG::UIHKScreenGarageBrowser *v3; // rbx
  int v4; // r8d
  UFG::UIHKGarageVehicleInfo *mCurrentVehicle; // rax
  UFG::UIHKHelpBarWidget *p_HelpBar; // rbx
  unsigned int v7; // eax

  mUserData0 = e->mUserData0;
  v3 = this;
  if ( mUserData0 )
  {
    v4 = mUserData0 - 1;
    if ( v4 )
    {
      if ( v4 == 1 )
        UFG::UIHKScreenGarageBrowser::AfterFadeToBlackExit(this);
      return;
    }
    mCurrentVehicle = this->mCurrentVehicle;
    if ( !mCurrentVehicle )
      return;
    UFG::StoreFront::PurchaseItem(this->mStore, mCurrentVehicle->storeIndex);
    if ( UFG::GameStatAction::Store::AreAllVehiclesPurchased() )
      UFG::AchievementTrophyManager::UnlockAchievementTrophy(39);
    this = v3;
  }
  UFG::UIHKScreenGarageBrowser::SpawnVehicle(this);
  if ( UFG::UIHKScreenGlobalOverlay::mThis )
  {
    p_HelpBar = &UFG::UIHKScreenGlobalOverlay::mThis->HelpBar;
    v7 = UFG::qStringHash32("GARAGE", 0xFFFFFFFF);
    UFG::UIHKHelpBarWidget::Hide(p_HelpBar, v7);
  }
}

// File Line: 536
// RVA: 0x5EC6E0
char __fastcall UFG::UIHKScreenGarageBrowser::HandleVehicleSelected(UFG::UIHKScreenGarageBrowser *this)
{
  UFG::allocator::free_link *v2; // rax
  UFG::Event *v3; // rax
  UFG::qPropertySet *Item; // rax
  unsigned int *v6; // rax
  unsigned int *v7; // rcx
  unsigned int v8; // ebx
  UFG::GameStatTracker *v9; // rax
  UFG::allocator::free_link *v10; // [rsp+50h] [rbp+8h] BYREF

  if ( !this->mCurrentVehicle || !this->mStore )
    return 0;
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x4A3D1F6Cu, 0i64, 0, 0i64);
  if ( !this->mCurrentVehicle->bOwned )
  {
    Item = UFG::StoreFront::GetItem(this->mStore, this->mSelectedIndex);
    LODWORD(v10) = 0;
    v6 = UFG::qPropertySet::Get<unsigned long>(
           Item,
           (UFG::qArray<unsigned long,0> *)&UFG::StoreItemSymbol_FaceRequired,
           DEPTH_RECURSE);
    v7 = (unsigned int *)&v10;
    if ( v6 )
      v7 = v6;
    v8 = *v7;
    v9 = UFG::GameStatTracker::Instance();
    if ( v8 <= (unsigned int)UFG::GameStatTracker::GetFaceLevel(v9) )
    {
      if ( UFG::StoreFront::CanPurchase(this->mStore, this->mCurrentVehicle->storeIndex) )
      {
        UFG::UIScreenDialogBox::createYesNoDialog(this, &customCaption, "$STORE_PURCHASE_ITEM", 0, 1);
        return 1;
      }
      UFG::VendorDialogueUtils::PlayStoreClerkDialogue(eStoreClerkDialogueContext_NoMoney, 1.0);
      UFG::UIScreenDialogBox::createOKDialog(this, &customCaption, "$STORE_INSUFFICIENT_MONEY", 0);
    }
    else
    {
      UFG::UIScreenDialogBox::createOKDialog(this, &customCaption, "$WARDROBE_FACE_TOO_LOW", 0);
      this->mState = NUM_CALIBRATION_STATES|STATE_VOLUME;
    }
    return 0;
  }
  v2 = UFG::qMalloc(0x38ui64, "UIGarageScreenDeferredTaskChannel", 0i64);
  v10 = v2;
  if ( v2 )
    UFG::Event::Event((UFG::Event *)v2, UFG::gUIGarageScreenDeferredTaskChannel.mName);
  else
    v3 = 0i64;
  v3->mUserData0 = 0i64;
  UFG::EventDispatcher::QueueEvent(&UFG::EventDispatcher::mInstance, v3);
  UFG::VendorDialogueUtils::sm_moneySpent = UFG::VendorDialogueUtils::sm_moneySpent + 10000.0;
  return 1;
}

// File Line: 581
// RVA: 0x63CD80
void __fastcall UFG::UIHKScreenGarageBrowser::update(UFG::UIHKScreenGarageBrowser *this, float elapsed)
{
  __int32 v4; // ecx
  __int32 v5; // ecx
  UFG::SimObjectVehicle *m_pSimObjVehicle; // rax
  UFG::SimComponent *m_pComponent; // rcx
  UFG::OSuiteTickerManager *v8; // rax
  float v9; // xmm0_4
  hkpNullContactMgrFactory *v10; // rax
  hkpCollidable *v11; // rdx
  hkpCollidable *v12; // r8
  hkpCollisionInput *v13; // r9
  hkpNullContactMgr *ContactMgr; // rax
  float v15; // xmm1_4
  UFG::UIHKScreenGlobalOverlay *v16; // rax
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-50h] BYREF

  v4 = this->mState - 1;
  if ( v4 )
  {
    v5 = v4 - 1;
    if ( v5 )
    {
      if ( v5 == 1 )
      {
        UFG::StoreFront::OpenPreviewShutter(this->mStore);
        this->mState = NUM_CALIBRATION_STATES|STATE_BRIGHTNESS;
        UFG::UIHKScreenGarageBrowser::Exit(this);
      }
    }
    else
    {
      m_pSimObjVehicle = this->m_pSimObjVehicle;
      if ( m_pSimObjVehicle )
        m_pComponent = m_pSimObjVehicle->m_Components.p[10].m_pComponent;
      else
        m_pComponent = 0i64;
      if ( this->mStore
        && UFG::TrueCrowdSet::Instance::IsLoaded((UFG::TrueCrowdSet::Instance *)&m_pComponent[4].m_SafePointerList.mNode.mNext) )
      {
        this->mState = STATE_UISCALE;
      }
    }
  }
  else if ( !this->mInfoTickerTextSet )
  {
    pargs.pObjectInterface = 0i64;
    v8 = UFG::OSuiteTickerManager::Instance();
    pargs.Type = VT_String;
    pargs.mValue.pString = UFG::OSuiteTickerManager::GetTickerDescription(v8, (hkgpIndexedMeshDefinitions::Edge *)2, 0);
    Scaleform::GFx::Movie::Invoke(this->mRenderable->m_movie.pObject, "SetTickerText", 0i64, &pargs, 1u);
    this->mInfoTickerTextSet = 1;
    if ( (pargs.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        pargs.mValue);
      pargs.pObjectInterface = 0i64;
    }
    pargs.Type = VT_Undefined;
  }
  v9 = UFG::VendorDialogueUtils::sm_idleTime + elapsed;
  UFG::VendorDialogueUtils::sm_idleTime = UFG::VendorDialogueUtils::sm_idleTime + elapsed;
  if ( UFG::VendorDialogueUtils::sm_playBrowse > 0 && v9 > 1.0 )
  {
    v10 = (hkpNullContactMgrFactory *)UFG::StoreFrontTracker::Instance();
    if ( v10 )
      ContactMgr = hkpNullContactMgrFactory::createContactMgr(v10, v11, v12, v13);
    else
      ContactMgr = 0i64;
    if ( LODWORD(ContactMgr[1].vfptr) == 1 )
      v15 = *(float *)&FLOAT_1_0;
    else
      v15 = FLOAT_2_0;
    UFG::VendorDialogueUtils::PlayStoreClerkDialogue(eStoreClerkDialogueContext_Browse, v15);
    UFG::VendorDialogueUtils::sm_playBrowse = 0;
  }
  if ( UFG::UIScreenManagerBase::getTopScreen(UFG::UIScreenManager::s_instance) == (UFG::qNode<UFG::UIScreen,UFG::UIScreen> **)this )
  {
    v16 = UFG::UIHKScreenGlobalOverlay::mThis;
    if ( !UFG::UIHKScreenGlobalOverlay::mThis )
      v16 = &gGlobalOverlaySentinel;
    v16->HelpBar.mChanged |= COERCE_FLOAT(COERCE_UNSIGNED_INT(v16->HelpBar.mYOffset - -20.0) & _xmm) > 0.001;
    v16->HelpBar.mYOffset = -20.0;
  }
  UFG::UIScreen::update(this, elapsed);
}

// File Line: 654
// RVA: 0x60E440
void __fastcall UFG::UIHKScreenGarageBrowser::ShowHelpBar(
        UFG::UIHKScreenGarageBrowser *this,
        UFG::UIHKScreenGarageBrowser::eHelpBarState eHelpState,
        bool isInfoTickerPopupVisible)
{
  UFG::UIHKScreenGarageBrowser::eHelpBarState mHelpBarState; // eax
  int v5; // ecx
  __int64 v6; // rax
  const char *v7; // rdx
  __int64 v8; // rax
  __int64 v9; // rdi
  __int64 v10; // rbx
  int v11; // ecx
  __int64 v12; // rax
  __int64 v13; // rdi
  __int64 v14; // rbx
  int v15; // ecx
  __int64 v16; // rax
  __int64 v17; // rdi
  __int64 v18; // rbx
  UFG::GameStatTracker *v19; // rax
  int v20; // ecx
  __int64 v21; // rax
  __int64 v22; // rdi
  __int64 v23; // rbx
  UFG::UIHKScreenGlobalOverlay *v24; // rax
  UFG::UIHKHelpBarData data; // [rsp+30h] [rbp-C8h] BYREF

  if ( !UFG::UIHKScreenGlobalOverlay::mThis || eHelpState == HELP_NONE )
    return;
  this->mHelpBarState = eHelpState;
  UFG::UIHKHelpBarData::UIHKHelpBarData(&data);
  data.id = UFG::qStringHash32("GARAGE", 0xFFFFFFFF);
  *(_QWORD *)&data.priority = 0i64;
  mHelpBarState = this->mHelpBarState;
  if ( mHelpBarState == HELP_SELECT_ITEM_STORE )
  {
    v5 = 0;
    v6 = 0i64;
    while ( data.Buttons[v6] )
    {
      ++v5;
      if ( ++v6 >= 6 )
        goto LABEL_16;
    }
    v7 = "$WARDROBE_BUY_UPPERCASE";
LABEL_15:
    v9 = v5;
    v10 = v5;
    data.Buttons[v9] = ACCEPT_BUTTON;
    UFG::qString::Set(&data.Captions[v10], v7);
    UFG::qString::Set((UFG::qString *)&data.Captions[v10 + 5].mStringHash32, &customCaption);
    data.MessageIds[v9 - 2] = 0;
    goto LABEL_16;
  }
  if ( mHelpBarState != HELP_SELECT_ITEM_EMPTY )
  {
    v5 = 0;
    v8 = 0i64;
    while ( data.Buttons[v8] )
    {
      ++v5;
      if ( ++v8 >= 6 )
        goto LABEL_16;
    }
    v7 = "$COMMON_SELECT_UPPERCASE";
    goto LABEL_15;
  }
LABEL_16:
  if ( this->m_bBackbuttonEnabled )
  {
    v11 = 0;
    v12 = 0i64;
    while ( data.Buttons[v12] )
    {
      ++v11;
      if ( ++v12 >= 6 )
        goto LABEL_22;
    }
    v13 = v11;
    data.Buttons[v13] = BACK_BUTTON;
    v14 = v11;
    UFG::qString::Set(&data.Captions[v14], "$COMMON_BACK_UPPERCASE");
    UFG::qString::Set((UFG::qString *)&data.Captions[v14 + 5].mStringHash32, &customCaption);
    data.MessageIds[v13 - 2] = 0;
  }
LABEL_22:
  if ( ((this->mHelpBarState - 2) & 0xFFFFFFFD) != 0 )
  {
    v15 = 0;
    v16 = 0i64;
    while ( data.Buttons[v16] )
    {
      ++v15;
      if ( ++v16 >= 6 )
        goto LABEL_28;
    }
    v17 = v15;
    data.Buttons[v17] = BUTTON1_BUTTON;
    v18 = v15;
    UFG::qString::Set(&data.Captions[v18], "$GARAGE_CUSTOMIZE_PAINT");
    UFG::qString::Set((UFG::qString *)&data.Captions[v18 + 5].mStringHash32, &customCaption);
    data.MessageIds[v17 - 2] = 0;
  }
LABEL_28:
  if ( this->mHelpBarState == HELP_SELECT_ITEM_STORAGE )
  {
    v19 = UFG::GameStatTracker::Instance();
    if ( UFG::GameStatTracker::GetStat(v19, EnableValet) )
    {
      v20 = 0;
      v21 = 0i64;
      while ( data.Buttons[v21] )
      {
        ++v20;
        if ( ++v21 >= 6 )
          goto LABEL_35;
      }
      v22 = v20;
      data.Buttons[v22] = BUTTON2_BUTTON;
      v23 = v20;
      UFG::qString::Set(&data.Captions[v23], "$GARAGE_SET_VALET_UPPERCASE");
      UFG::qString::Set((UFG::qString *)&data.Captions[v23 + 5].mStringHash32, &customCaption);
      data.MessageIds[v22 - 2] = 0;
    }
  }
LABEL_35:
  v24 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    v24 = &gGlobalOverlaySentinel;
  UFG::UIHKHelpBarWidget::Show(&v24->HelpBar, &data);
  UFG::qString::~qString((UFG::qString *)&data.MessageIds[4]);
  `eh vector destructor iterator(
    &data.Captions[5].mStringHash32,
    0x28ui64,
    6,
    (void (__fastcall *)(void *))UFG::qString::~qString);
  `eh vector destructor iterator(data.Captions, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
}

// File Line: 699
// RVA: 0x5D2F40
void __fastcall UFG::UIHKScreenGarageBrowser::AddVehicleOrderOverride(UFG::qSymbol *spawnInfo)
{
  __int64 size; // rdi
  unsigned int v3; // ebx
  unsigned int v4; // edx

  size = UFG::UIHKScreenGarageBrowser::mVehicleOrderOverride.size;
  v3 = UFG::UIHKScreenGarageBrowser::mVehicleOrderOverride.size + 1;
  if ( UFG::UIHKScreenGarageBrowser::mVehicleOrderOverride.size + 1 > UFG::UIHKScreenGarageBrowser::mVehicleOrderOverride.capacity )
  {
    if ( UFG::UIHKScreenGarageBrowser::mVehicleOrderOverride.capacity )
      v4 = 2 * UFG::UIHKScreenGarageBrowser::mVehicleOrderOverride.capacity;
    else
      v4 = 1;
    for ( ; v4 < v3; v4 *= 2 )
      ;
    if ( v4 <= 4 )
      v4 = 4;
    if ( v4 - v3 > 0x10000 )
      v4 = UFG::UIHKScreenGarageBrowser::mVehicleOrderOverride.size + 65537;
    UFG::qArray<UFG::qSymbol,0>::Reallocate(&UFG::UIHKScreenGarageBrowser::mVehicleOrderOverride, v4, "qArray.Add");
  }
  UFG::UIHKScreenGarageBrowser::mVehicleOrderOverride.size = v3;
  UFG::UIHKScreenGarageBrowser::mVehicleOrderOverride.p[size] = (UFG::qSymbol)spawnInfo->mUID;
}

// File Line: 705
// RVA: 0x5D5AC0
void UFG::UIHKScreenGarageBrowser::ClearVehicleOrderOverride(void)
{
  UFG::qSymbol *v0; // rbx

  if ( UFG::UIHKScreenGarageBrowser::mVehicleOrderOverride.p )
  {
    v0 = UFG::UIHKScreenGarageBrowser::mVehicleOrderOverride.p - 1;
    `eh vector destructor iterator(
      UFG::UIHKScreenGarageBrowser::mVehicleOrderOverride.p,
      4ui64,
      UFG::UIHKScreenGarageBrowser::mVehicleOrderOverride.p[-1].mUID,
      (void (__fastcall *)(void *))_);
    operator delete[](v0);
  }
  UFG::UIHKScreenGarageBrowser::mVehicleOrderOverride.p = 0i64;
  *(_QWORD *)&UFG::UIHKScreenGarageBrowser::mVehicleOrderOverride.size = 0i64;
}

// File Line: 711
// RVA: 0x5F7640
void __fastcall UFG::UIHKScreenGarageBrowser::PopulateInventory(UFG::UIHKScreenGarageBrowser *this)
{
  UFG::allocator::free_link *v2; // r14
  unsigned int v3; // edi
  unsigned int v4; // r12d
  __int64 v5; // r13
  __int64 size; // rbx
  __int64 v7; // rcx
  unsigned int v8; // esi
  unsigned int v9; // ebx
  unsigned __int64 v10; // rax
  UFG::allocator::free_link *v11; // rax
  UFG::allocator::free_link *v12; // r12
  UFG::allocator::free_link *v13; // rdx
  __int64 v14; // r8
  unsigned int NumItems; // esi
  unsigned int i; // ebx
  unsigned int v17; // ecx
  Scaleform::GFx::Movie *v18; // rbx
  UFG::UIHKScreenGarageBrowser::eHelpBarState v19; // edx
  Scaleform::GFx::Value ptr; // [rsp+48h] [rbp-51h] BYREF
  Scaleform::GFx::Value value; // [rsp+78h] [rbp-21h] BYREF
  unsigned int itemIndexOut; // [rsp+100h] [rbp+67h] BYREF
  unsigned int v23; // [rsp+108h] [rbp+6Fh]
  __int64 v24; // [rsp+110h] [rbp+77h]
  Scaleform::GFx::Movie *pObject; // [rsp+118h] [rbp+7Fh]

  if ( this->mState == NUM_CALIBRATION_STATES )
  {
    UFG::UIHKScreenGarageBrowser::ShowHelpBar(this, HELP_SELECT_ITEM_EMPTY, 0);
  }
  else if ( this->mStore )
  {
    pObject = this->mRenderable->m_movie.pObject;
    if ( pObject )
    {
      UFG::UIHKScreenGarageBrowser::ClearList(this);
      v2 = 0i64;
      v3 = 0;
      v4 = 0;
      if ( UFG::UIHKScreenGarageBrowser::mVehicleOrderOverride.size )
      {
        v5 = 0i64;
        size = UFG::UIHKScreenGarageBrowser::mVehicleOrderOverride.size;
        v24 = UFG::UIHKScreenGarageBrowser::mVehicleOrderOverride.size;
        do
        {
          if ( UFG::StoreFront::FindItemIndex(
                 this->mStore,
                 &UFG::UIHKScreenGarageBrowser::mVehicleOrderOverride.p[v5],
                 &itemIndexOut) )
          {
            UFG::UIHKScreenGarageBrowser::AddItem(this, itemIndexOut);
            v7 = v3;
            v23 = v3;
            v8 = v3 + 1;
            if ( v3 + 1 > v4 )
            {
              v9 = 1;
              if ( v4 )
                v9 = 2 * v4;
              for ( ; v9 < v8; v9 *= 2 )
                ;
              if ( v9 <= 4 )
                v9 = 4;
              if ( v9 - v8 > 0x10000 )
                v9 = v3 + 65537;
              if ( v9 != v3 )
              {
                v10 = 4i64 * v9;
                if ( !is_mul_ok(v9, 4ui64) )
                  v10 = -1i64;
                v11 = UFG::qMalloc(v10, "qArray.Add", 0i64);
                v12 = v11;
                if ( v2 )
                {
                  if ( v3 )
                  {
                    v13 = v11;
                    v14 = v3;
                    do
                    {
                      LODWORD(v13->mNext) = *(_DWORD *)((char *)&v13->mNext + (char *)v2 - (char *)v11);
                      v13 = (UFG::allocator::free_link *)((char *)v13 + 4);
                      --v14;
                    }
                    while ( v14 );
                  }
                  operator delete[](v2);
                }
                v2 = v12;
                v4 = v9;
                v7 = v23;
              }
              size = v24;
            }
            ++v3;
            *((_DWORD *)&v2->mNext + v7) = itemIndexOut;
          }
          ++v5;
          v24 = --size;
        }
        while ( size );
      }
      NumItems = UFG::StoreFront::GetNumItems(this->mStore);
      this->mNumItems = 0;
      for ( i = 0; i < NumItems; ++i )
      {
        v17 = 0;
        if ( v3 )
        {
          while ( i != *((_DWORD *)&v2->mNext + v17) )
          {
            if ( ++v17 >= v3 )
              goto LABEL_35;
          }
          if ( v17 != -1 )
            continue;
        }
LABEL_35:
        UFG::UIHKScreenGarageBrowser::AddItem(this, i);
      }
      `eh vector constructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      if ( this->mNumItems )
      {
        if ( this->mStore->mStoreType == StoreType_Retail )
        {
          UFG::UIHKScreenGarageBrowser::ShowHelpBar(this, HELP_SELECT_ITEM_STORE, 0);
          v18 = pObject;
        }
        else
        {
          value.pObjectInterface = 0i64;
          value.Type = VT_Boolean;
          value.mValue.BValue = 0;
          v18 = pObject;
          Scaleform::GFx::Movie::SetVariable(pObject, "mc_Money._visible", &value, 1i64);
          v19 = HELP_SELECT_ITEM_RACE;
          if ( this->mStore->mStoreType != StoreType_Race )
            v19 = HELP_SELECT_ITEM_STORAGE;
          UFG::UIHKScreenGarageBrowser::ShowHelpBar(this, v19, 0);
          if ( (value.Type & 0x40) != 0 )
          {
            (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
              value.pObjectInterface,
              &value,
              value.mValue);
            value.pObjectInterface = 0i64;
          }
          value.Type = VT_Undefined;
        }
        UFG::UIHKScreenGarageBrowser::UpdateMoney(this);
        this->mSelectedIndex = 0;
        if ( (ptr.Type & 0x40) != 0 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
            ptr.pObjectInterface,
            &ptr,
            ptr.mValue);
          ptr.pObjectInterface = 0i64;
        }
        ptr.Type = VT_Number;
        ptr.mValue.pString = 0i64;
        Scaleform::GFx::Movie::Invoke(v18, "gVehicleList.SetSelectedIndex", 0i64, &ptr, 1u);
        Scaleform::GFx::Movie::Invoke(v18, "VehicleList_Refresh", 0i64, 0i64, 0);
      }
      else
      {
        this->mState = NUM_CALIBRATION_STATES;
        if ( (ptr.Type & 0x40) != 0 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
            ptr.pObjectInterface,
            &ptr,
            ptr.mValue);
          ptr.pObjectInterface = 0i64;
        }
        ptr.Type = VT_Boolean;
        ptr.mValue.BValue = 1;
        Scaleform::GFx::Movie::Invoke(pObject, "VehicleList_SetIsEmpty", 0i64, &ptr, 1u);
      }
      `eh vector destructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
      if ( v2 )
        operator delete[](v2);
    }
  }
}

// File Line: 791
// RVA: 0x61B480
void __fastcall UFG::UIHKScreenGarageBrowser::UpdateMoney(UFG::UIHKScreenGarageBrowser *this)
{
  Scaleform::GFx::Movie *pObject; // rsi
  UFG::GameStatTracker *v2; // rax
  int Stat; // ebx
  UFG::GameStatTracker *v4; // rax
  int FaceLevel; // r14d
  char *mData; // rdi
  Scaleform::GFx::Value ptr; // [rsp+18h] [rbp-79h] BYREF
  char v8[16]; // [rsp+48h] [rbp-49h] BYREF
  __int64 v9; // [rsp+58h] [rbp-39h]
  int v10; // [rsp+60h] [rbp-31h]
  double v11; // [rsp+68h] [rbp-29h]
  char v12[16]; // [rsp+78h] [rbp-19h] BYREF
  __int64 v13; // [rsp+88h] [rbp-9h]
  int v14; // [rsp+90h] [rbp-1h]
  double v15; // [rsp+98h] [rbp+7h]
  __int64 v16; // [rsp+A8h] [rbp+17h]
  UFG::qString string; // [rsp+B0h] [rbp+1Fh] BYREF

  v16 = -2i64;
  pObject = this->mRenderable->m_movie.pObject;
  v2 = UFG::GameStatTracker::Instance();
  Stat = UFG::GameStatTracker::GetStat(v2, Money);
  v4 = UFG::GameStatTracker::Instance();
  FaceLevel = UFG::GameStatTracker::GetFaceLevel(v4);
  UFG::qString::qString(&string);
  UFG::UI::FormatMoneyStr(Stat, &string);
  ptr.pNext = (Scaleform::GFx::Value *)Scaleform::GFx::Value::~Value;
  `eh vector constructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  mData = string.mData;
  if ( (ptr.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
      ptr.pObjectInterface,
      &ptr,
      ptr.mValue);
    ptr.pObjectInterface = 0i64;
  }
  ptr.Type = VT_String;
  ptr.mValue.pString = mData;
  if ( (v10 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v9 + 16i64))(v9, v8, COERCE_DOUBLE(*(_QWORD *)&v11));
    v9 = 0i64;
  }
  v10 = 5;
  v11 = (double)Stat;
  if ( (v14 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v13 + 16i64))(v13, v12, COERCE_DOUBLE(*(_QWORD *)&v15));
    v13 = 0i64;
  }
  v14 = 5;
  v15 = (double)FaceLevel;
  Scaleform::GFx::Movie::Invoke(pObject, "VehicleList_SetCurrentMoney", 0i64, &ptr, 3u);
  `eh vector destructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  UFG::qString::~qString(&string);
}

// File Line: 807
// RVA: 0x5D1FA0
void __fastcall UFG::UIHKScreenGarageBrowser::AddItem(UFG::UIHKScreenGarageBrowser *this, int storeItemIdx)
{
  UFG::qPropertySet *Item; // rbx
  UFG::qSymbol *v5; // rax
  char *v6; // rax
  char *v7; // rax
  char *v8; // rax
  unsigned int *v9; // rax
  UFG::UIHKGarageVehicleInfo **v10; // rcx
  unsigned int v11; // esi
  UFG::GameStatTracker *v12; // rax
  unsigned int FaceLevel; // eax
  unsigned int v14; // eax
  UFG::UIGfxTranslator *v15; // rcx
  const char *v16; // rax
  unsigned int v17; // eax
  UFG::UIGfxTranslator *m_translator; // rcx
  const char *v19; // rax
  char *v20; // rax
  const char *v21; // rdi
  char *v22; // rax
  const char *VehicleTierString; // rax
  const char *v24; // rbx
  UFG::GameStatTracker *v25; // rax
  UFG::PersistentData::ID *Stat; // rax
  char v27; // cl
  UFG::UIHKGarageVehicleInfo *v28; // rax
  UFG::UIHKGarageVehicleInfo *v29; // rax
  UFG::UIHKGarageVehicleInfo __that; // [rsp+20h] [rbp-C8h] BYREF
  __int64 v31; // [rsp+138h] [rbp+50h]
  UFG::UIHKGarageVehicleInfo v32; // [rsp+148h] [rbp+60h] BYREF
  UFG::UIHKGarageVehicleInfo *v33; // [rsp+278h] [rbp+190h] BYREF

  *(_QWORD *)&__that.price = -2i64;
  Item = UFG::StoreFront::GetItem(this->mStore, storeItemIdx);
  if ( Item )
  {
    __that.spawnObjectInfo.mUID = -1;
    UFG::qString::qString(&__that.title);
    UFG::qString::qString(&__that.description);
    UFG::qString::qString(&__that.discountPercentStr);
    UFG::qString::qString((UFG::qString *)&__that.discountPercentStr.mMagic);
    UFG::qString::qString((UFG::qString *)&__that.texture.mMagic);
    UFG::qString::qString((UFG::qString *)&__that.brandTexture.mMagic);
    *(_QWORD *)&__that.tier.mMagic = 0i64;
    LODWORD(__that.tier.mData) = 0;
    __that.tier.mStringHash32 = 0;
    LOWORD(__that.tier.mStringHashUpper32) = 0;
    BYTE2(__that.tier.mStringHashUpper32) = 0;
    HIDWORD(__that.tier.mData) = storeItemIdx;
    LOBYTE(__that.tier.mStringHashUpper32) = UFG::StoreFront::IsOwned(this->mStore, storeItemIdx);
    v5 = UFG::qPropertySet::Get<UFG::qSymbol>(
           Item,
           (UFG::qArray<unsigned long,0> *)&UFG::StoreItemSymbol_SpawnObjectInfo,
           DEPTH_RECURSE);
    if ( v5 )
      __that.spawnObjectInfo = (UFG::qSymbol)v5->mUID;
    v6 = UFG::qPropertySet::Get<char const *>(
           Item,
           (UFG::qArray<unsigned long,0> *)&UFG::StoreItemSymbol_Title,
           DEPTH_RECURSE);
    if ( v6 )
      UFG::qString::Set(&__that.title, v6);
    v7 = UFG::qPropertySet::Get<char const *>(
           Item,
           (UFG::qArray<unsigned long,0> *)&UFG::StoreItemSymbol_Description,
           DEPTH_RECURSE);
    if ( v7 )
      UFG::qString::Set(&__that.description, v7);
    v8 = UFG::qPropertySet::Get<char const *>(
           Item,
           (UFG::qArray<unsigned long,0> *)&UFG::StoreItemSymbol_Texture,
           DEPTH_RECURSE);
    if ( v8 )
      UFG::qString::Set((UFG::qString *)&__that.discountPercentStr.mMagic, v8);
    __that.tier.mMagic = (int)UFG::StoreFrontTracker::GetItemPriceWithoutDiscount(Item);
    __that.tier.mLength = (int)UFG::StoreFrontTracker::GetItemPriceBasedOnClothes(Item);
    __that.tier.mStringHash32 = (int)UFG::StoreFrontTracker::GetDiscount();
    LODWORD(v33) = 0;
    v9 = UFG::qPropertySet::Get<unsigned long>(
           Item,
           (UFG::qArray<unsigned long,0> *)&UFG::StoreItemSymbol_FaceRequired,
           DEPTH_RECURSE);
    v10 = &v33;
    if ( v9 )
      v10 = (UFG::UIHKGarageVehicleInfo **)v9;
    v11 = *(_DWORD *)v10;
    v12 = UFG::GameStatTracker::Instance();
    FaceLevel = UFG::GameStatTracker::GetFaceLevel(v12);
    BYTE2(__that.tier.mStringHashUpper32) = v11 <= FaceLevel;
    if ( v11 > FaceLevel )
    {
      v17 = UFG::qStringHashUpper32("WARDROBE_FACE_LEVEL", -1);
      m_translator = UFG::UIScreenManager::s_instance->m_translator;
      if ( !m_translator || (v19 = (const char *)m_translator->vfptr[5].__vecDelDtor(m_translator, v17)) == 0i64 )
        v19 = "WARDROBE_FACE_LEVEL";
      UFG::qString::Format(&__that.discountPercentStr, v19, v11);
    }
    else if ( __that.tier.mStringHash32 )
    {
      UFG::qString::qString((UFG::qString *)&__that.faceValue);
      UFG::qString::Format((UFG::qString *)&__that.faceValue, "%d", __that.tier.mStringHash32);
      v14 = UFG::qStringHashUpper32("WARDROBE_DISCOUNT_PERCENT", -1);
      v15 = UFG::UIScreenManager::s_instance->m_translator;
      if ( !v15 || (v16 = (const char *)v15->vfptr[5].__vecDelDtor(v15, v14)) == 0i64 )
        v16 = "WARDROBE_DISCOUNT_PERCENT";
      UFG::qString::Format(&__that.discountPercentStr, v16, v31);
      UFG::qString::~qString((UFG::qString *)&__that.faceValue);
    }
    v20 = PropertyUtils::Get<char const *>(
            Item,
            (UFG::qArray<unsigned long,0> *)&UFG::StoreItemSymbol_Brand,
            DEPTH_RECURSE);
    v21 = v20;
    if ( v20 && (int)UFG::qStringLength(v20) > 0 )
      UFG::qString::Set((UFG::qString *)&__that.texture.mMagic, v21);
    v22 = PropertyUtils::Get<char const *>(
            Item,
            (UFG::qArray<unsigned long,0> *)&UFG::StoreItemSymbol_Tier,
            DEPTH_RECURSE);
    VehicleTierString = UFG::UIHKScreenGarageBrowser::GetVehicleTierString(this, v22);
    v24 = VehicleTierString;
    if ( VehicleTierString && (int)UFG::qStringLength(VehicleTierString) > 0 )
      UFG::qString::Set((UFG::qString *)&__that.brandTexture.mMagic, v24);
    v25 = UFG::GameStatTracker::Instance();
    Stat = UFG::GameStatTracker::GetStat(v25, ValetVehicle);
    v27 = BYTE1(__that.tier.mStringHashUpper32);
    if ( Stat->mValue.mUID == __that.spawnObjectInfo.mUID )
      v27 = 1;
    BYTE1(__that.tier.mStringHashUpper32) = v27;
    ++this->mNumItems;
    v33 = &v32;
    UFG::UIHKGarageVehicleInfo::UIHKGarageVehicleInfo(&v32, &__that);
    UFG::UIHKScreenGarageBrowser::Flash_AddItem(this, v28);
    v33 = &v32;
    UFG::UIHKGarageVehicleInfo::UIHKGarageVehicleInfo(&v32, &__that);
    UFG::UIHKScreenGarageBrowser::AddToList(this, v29);
    UFG::qString::~qString((UFG::qString *)&__that.brandTexture.mMagic);
    UFG::qString::~qString((UFG::qString *)&__that.texture.mMagic);
    UFG::qString::~qString((UFG::qString *)&__that.discountPercentStr.mMagic);
    UFG::qString::~qString(&__that.discountPercentStr);
    UFG::qString::~qString(&__that.description);
    UFG::qString::~qString(&__that.title);
  }
}

// File Line: 904
// RVA: 0x5D9400
void __fastcall UFG::UIHKScreenGarageBrowser::Flash_AddItem(
        UFG::UIHKScreenGarageBrowser *this,
        UFG::UIHKGarageVehicleInfo *info)
{
  Scaleform::GFx::Value::ValueUnion v4; // xmm6_8
  char *mData; // rdi
  char *v6; // rdi
  char *v7; // rdi
  double price; // xmm6_8
  double discountPrice; // xmm6_8
  double discountPercent; // xmm6_8
  char *v11; // rdi
  char *v12; // rdi
  bool bOwned; // di
  bool bValetVehicle; // di
  char *v15; // rdi
  bool playerHasEnoughFace; // di
  Scaleform::GFx::Value ptr; // [rsp+30h] [rbp-B8h] BYREF
  char v18[8]; // [rsp+60h] [rbp-88h] BYREF
  char *v19; // [rsp+68h] [rbp-80h]
  __int64 v20; // [rsp+70h] [rbp-78h]
  int v21[4]; // [rsp+78h] [rbp-70h] BYREF
  __int64 v22; // [rsp+88h] [rbp-60h]
  int v23; // [rsp+90h] [rbp-58h]
  char *v24; // [rsp+98h] [rbp-50h]
  char v25[16]; // [rsp+A8h] [rbp-40h] BYREF
  __int64 v26; // [rsp+B8h] [rbp-30h]
  int v27; // [rsp+C0h] [rbp-28h]
  char *v28; // [rsp+C8h] [rbp-20h]
  char v29[16]; // [rsp+D8h] [rbp-10h] BYREF
  __int64 v30; // [rsp+E8h] [rbp+0h]
  int v31; // [rsp+F0h] [rbp+8h]
  double v32; // [rsp+F8h] [rbp+10h]
  char v33[16]; // [rsp+108h] [rbp+20h] BYREF
  __int64 v34; // [rsp+118h] [rbp+30h]
  int v35; // [rsp+120h] [rbp+38h]
  double v36; // [rsp+128h] [rbp+40h]
  char v37[16]; // [rsp+138h] [rbp+50h] BYREF
  __int64 v38; // [rsp+148h] [rbp+60h]
  int v39; // [rsp+150h] [rbp+68h]
  double v40; // [rsp+158h] [rbp+70h]
  char v41[16]; // [rsp+168h] [rbp+80h] BYREF
  __int64 v42; // [rsp+178h] [rbp+90h]
  int v43; // [rsp+180h] [rbp+98h]
  char *v44; // [rsp+188h] [rbp+A0h]
  char v45[16]; // [rsp+198h] [rbp+B0h] BYREF
  __int64 v46; // [rsp+1A8h] [rbp+C0h]
  int v47; // [rsp+1B0h] [rbp+C8h]
  char *v48; // [rsp+1B8h] [rbp+D0h]
  char v49[16]; // [rsp+1C8h] [rbp+E0h] BYREF
  __int64 v50; // [rsp+1D8h] [rbp+F0h]
  int v51; // [rsp+1E0h] [rbp+F8h]
  __int64 v52; // [rsp+1E8h] [rbp+100h]
  char v53[16]; // [rsp+1F8h] [rbp+110h] BYREF
  __int64 v54; // [rsp+208h] [rbp+120h]
  int v55; // [rsp+210h] [rbp+128h]
  __int64 v56; // [rsp+218h] [rbp+130h]
  char v57[16]; // [rsp+228h] [rbp+140h] BYREF
  __int64 v58; // [rsp+238h] [rbp+150h]
  int v59; // [rsp+240h] [rbp+158h]
  char *v60; // [rsp+248h] [rbp+160h]
  char v61[16]; // [rsp+258h] [rbp+170h] BYREF
  __int64 v62; // [rsp+268h] [rbp+180h]
  int v63; // [rsp+270h] [rbp+188h]
  __int64 v64; // [rsp+278h] [rbp+190h]
  __int64 v65; // [rsp+288h] [rbp+1A0h]

  v65 = -2i64;
  `eh vector constructor iterator(&ptr, 0x30ui64, 13, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  v4.NValue = (double)(int)info->storeIndex;
  if ( (ptr.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
      ptr.pObjectInterface,
      &ptr,
      ptr.mValue);
    ptr.pObjectInterface = 0i64;
  }
  ptr.Type = VT_Number;
  ptr.mValue = v4;
  mData = info->title.mData;
  if ( (v21[0] & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v20 + 16i64))(v20, v18, v19);
    v20 = 0i64;
  }
  v21[0] = 6;
  v19 = mData;
  v6 = info->description.mData;
  if ( (v23 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, int *, char *))(*(_QWORD *)v22 + 16i64))(v22, v21, v24);
    v22 = 0i64;
  }
  v23 = 6;
  v24 = v6;
  v7 = info->texture.mData;
  if ( (v27 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v26 + 16i64))(v26, v25, v28);
    v26 = 0i64;
  }
  v27 = 6;
  v28 = v7;
  price = (double)(int)info->price;
  if ( (v31 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v30 + 16i64))(v30, v29, COERCE_DOUBLE(*(_QWORD *)&v32));
    v30 = 0i64;
  }
  v31 = 5;
  v32 = price;
  discountPrice = (double)(int)info->discountPrice;
  if ( (v35 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v34 + 16i64))(v34, v33, COERCE_DOUBLE(*(_QWORD *)&v36));
    v34 = 0i64;
  }
  v35 = 5;
  v36 = discountPrice;
  discountPercent = (double)(int)info->discountPercent;
  if ( (v39 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v38 + 16i64))(v38, v37, COERCE_DOUBLE(*(_QWORD *)&v40));
    v38 = 0i64;
  }
  v39 = 5;
  v40 = discountPercent;
  v11 = info->discountPercentStr.mData;
  if ( (v43 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v42 + 16i64))(v42, v41, v44);
    v42 = 0i64;
  }
  v43 = 6;
  v44 = v11;
  v12 = info->tier.mData;
  if ( (v47 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v46 + 16i64))(v46, v45, v48);
    v46 = 0i64;
  }
  v47 = 6;
  v48 = v12;
  bOwned = info->bOwned;
  if ( (v51 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v50 + 16i64))(v50, v49, v52);
    v50 = 0i64;
  }
  v51 = 2;
  LOBYTE(v52) = bOwned;
  bValetVehicle = info->bValetVehicle;
  if ( (v55 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v54 + 16i64))(v54, v53, v56);
    v54 = 0i64;
  }
  v55 = 2;
  LOBYTE(v56) = bValetVehicle;
  v15 = info->brandTexture.mData;
  if ( (v59 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v58 + 16i64))(v58, v57, v60);
    v58 = 0i64;
  }
  v59 = 6;
  v60 = v15;
  playerHasEnoughFace = info->playerHasEnoughFace;
  if ( (v63 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v62 + 16i64))(v62, v61, v64);
    v62 = 0i64;
  }
  v63 = 2;
  LOBYTE(v64) = playerHasEnoughFace;
  Scaleform::GFx::Movie::Invoke(this->mRenderable->m_movie.pObject, "VehicleList_AddItem", 0i64, &ptr, 0xDu);
  `eh vector destructor iterator(&ptr, 0x30ui64, 13, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  UFG::qString::~qString(&info->tier);
  UFG::qString::~qString(&info->brandTexture);
  UFG::qString::~qString(&info->texture);
  UFG::qString::~qString(&info->discountPercentStr);
  UFG::qString::~qString(&info->description);
  UFG::qString::~qString(&info->title);
}

// File Line: 928
// RVA: 0x5D2DF0
void __fastcall UFG::UIHKScreenGarageBrowser::AddToList(
        UFG::UIHKScreenGarageBrowser *this,
        UFG::UIHKGarageVehicleInfo *vehicle)
{
  UFG::qArray<UFG::UIHKGarageVehicleInfo,0> *p_mVehicleList; // rsi
  __int64 size; // rbp
  unsigned int v5; // ebx
  unsigned int capacity; // edx
  unsigned int v7; // edx

  p_mVehicleList = &this->mVehicleList;
  size = this->mVehicleList.size;
  v5 = size + 1;
  capacity = this->mVehicleList.capacity;
  if ( (int)size + 1 > capacity )
  {
    if ( capacity )
      v7 = 2 * capacity;
    else
      v7 = 1;
    for ( ; v7 < v5; v7 *= 2 )
      ;
    if ( v7 - v5 > 0x10000 )
      v7 = size + 65537;
    UFG::qArray<UFG::UIHKGarageVehicleInfo,0>::Reallocate(&this->mVehicleList, v7, "qArray.Add");
  }
  p_mVehicleList->size = v5;
  UFG::UIHKGarageVehicleInfo::operator=(&p_mVehicleList->p[size], vehicle);
  UFG::qString::~qString(&vehicle->tier);
  UFG::qString::~qString(&vehicle->brandTexture);
  UFG::qString::~qString(&vehicle->texture);
  UFG::qString::~qString(&vehicle->discountPercentStr);
  UFG::qString::~qString(&vehicle->description);
  UFG::qString::~qString(&vehicle->title);
}

// File Line: 934
// RVA: 0x6235D0
bool __fastcall UFG::UIHKScreenGarageBrowser::handleMessage(
        UFG::UIHKScreenGarageBrowser *this,
        unsigned int msgId,
        UFG::UIMessage *msg)
{
  UFG::UIMessage *v3; // r14
  unsigned int v4; // ebx
  UFG::UIHKScreenGarageBrowser *v5; // rdi
  Scaleform::GFx::Movie *pObject; // rbp
  int SelectedIndex; // eax
  UFG::UIHKScreenGarageBrowser::eState mState; // edx
  char v10; // al
  char v11; // cl
  UFG::allocator::free_link *v12; // rax
  UFG::Event *v13; // rax
  UFG::Event *v14; // rsi
  UFG::allocator::free_link *v15; // rax
  UFG::Event *v16; // rax
  UFG::Event *v17; // rsi

  v3 = msg;
  v4 = msgId;
  v5 = this;
  pObject = this->mRenderable->m_movie.pObject;
  if ( msgId == UI_HASH_INTRO_COMPLETE_30 )
    return UFG::UIScreen::handleMessage(this, msgId, msg);
  if ( msgId == UI_HASH_GAME_OVER_20 )
  {
    UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, this->mScreenUID);
  }
  else if ( msgId == UI_HASH_OPTION_HIGHLIGHTED_30 )
  {
    if ( this->mState == NUM_CALIBRATION_STATES )
      return 0;
    SelectedIndex = UFG::UIHKScreenGarageBrowser::GetSelectedIndex(this);
    v5->mSelectedIndex = SelectedIndex;
    v5->mCurrentVehicle = &v5->mVehicleList.p[SelectedIndex];
    UFG::UIHKScreenGarageBrowser::LoadTexturePack(v5);
  }
  mState = v5->mState;
  if ( mState == STATE_VOLUME )
    goto LABEL_64;
  switch ( v5->mState )
  {
    case 6:
      if ( v4 == UI_HASH_DIALOG_OK_30 )
      {
        v5->mState = STATE_BRIGHTNESS;
        return 1;
      }
      goto LABEL_64;
    case 7:
      if ( v4 != UI_HASH_SCREEN_FADE_IN_COMPLETE_12 )
        goto LABEL_64;
      if ( UFG::HudAudio::m_instance )
      {
        UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xEDABFAC7, 0i64, 0, 0i64);
        if ( UFG::HudAudio::m_instance )
          UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xC59A6DDC, 0i64, 0, 0i64);
      }
      UFG::UIHKScreenGarageBrowser::AfterFadeToBlackInit(v5);
      return 1;
    case 8:
      if ( v4 != UI_HASH_SCREEN_FADE_IN_COMPLETE_12 )
        goto LABEL_64;
      v15 = UFG::qMalloc(0x38ui64, "UIGarageScreenDeferredTaskChannel", 0i64);
      if ( v15 )
      {
        UFG::Event::Event((UFG::Event *)v15, UFG::gUIGarageScreenDeferredTaskChannel.mName);
        v17 = v16;
      }
      else
      {
        v17 = 0i64;
      }
      v17->mUserData0 = 2i64;
      UFG::EventDispatcher::QueueEvent(&UFG::EventDispatcher::mInstance, v17);
      return 1;
    default:
      if ( (UFG::UIHK_NISOverlay::m_curtains.m_state & 0xFFFFFFFD) == 0 )
      {
        if ( v4 == UI_HASH_BUTTON_ACCEPT_PRESSED_30 )
        {
          if ( mState != NUM_CALIBRATION_STATES )
          {
            v10 = UFG::UIHKScreenGarageBrowser::HandleVehicleSelected(v5);
            v11 = UFG::UIHKScreenGarageBrowser::mSkipCustomization;
            if ( v10 )
              v11 = 1;
            UFG::UIHKScreenGarageBrowser::mSkipCustomization = v11;
            return 1;
          }
          return 0;
        }
        if ( v4 == UI_HASH_BUTTON_BUTTON1_PRESSED_30 )
        {
          if ( mState != NUM_CALIBRATION_STATES )
          {
            UFG::UIHKScreenGarageBrowser::HandleVehicleSelected(v5);
            return 1;
          }
          return 0;
        }
        if ( v4 == UI_HASH_DIALOG_YES_30 )
        {
          v12 = UFG::qMalloc(0x38ui64, "UIGarageScreenDeferredTaskChannel", 0i64);
          if ( v12 )
          {
            UFG::Event::Event((UFG::Event *)v12, UFG::gUIGarageScreenDeferredTaskChannel.mName);
            v14 = v13;
          }
          else
          {
            v14 = 0i64;
          }
          v14->mUserData0 = 1i64;
          UFG::EventDispatcher::QueueEvent(&UFG::EventDispatcher::mInstance, v14);
          UFG::VendorDialogueUtils::sm_moneySpent = UFG::VendorDialogueUtils::sm_moneySpent + 10000.0;
          goto LABEL_64;
        }
        if ( v4 == UI_HASH_DIALOG_NO_30 || v4 == UI_HASH_DIALOG_OK_30 )
        {
          UFG::UIHKScreenGarageBrowser::mSkipCustomization = 0;
          goto LABEL_64;
        }
        if ( v4 == UI_HASH_DPAD_DOWN_PRESSED_30 || v4 == UI_HASH_THUMBSTICK_LEFT_DOWN_30 )
        {
          Scaleform::GFx::Movie::Invoke(pObject, "VehicleList_ScrollNext", 0i64, 0i64, 0);
          UFG::VendorDialogueUtils::sm_playBrowse = 1;
          UFG::VendorDialogueUtils::sm_idleTime = 0.0;
          if ( v5->mNumItems > 1 && UFG::HudAudio::m_instance )
            UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xB78DCE8u, 0i64, 0, 0i64);
          goto LABEL_64;
        }
        if ( v4 == UI_HASH_DPAD_UP_PRESSED_30 || v4 == UI_HASH_THUMBSTICK_LEFT_UP_30 )
        {
          Scaleform::GFx::Movie::Invoke(pObject, "VehicleList_ScrollPrev", 0i64, 0i64, 0);
          UFG::VendorDialogueUtils::sm_playBrowse = 1;
          UFG::VendorDialogueUtils::sm_idleTime = 0.0;
          if ( v5->mNumItems > 1 && UFG::HudAudio::m_instance )
            UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x593B70ABu, 0i64, 0, 0i64);
          goto LABEL_64;
        }
        if ( v4 == (_DWORD)UI_HASH_BUTTON_BUTTON2_PRESSED_30 )
        {
          UFG::UIHKScreenGarageBrowser::SetAsValet(v5);
          goto LABEL_64;
        }
        if ( v4 == UI_HASH_BUTTON_BACK_PRESSED_30 )
        {
          if ( !v5->m_bBackbuttonEnabled )
            goto LABEL_64;
          UFG::UIHKScreenGarageBrowser::mPlayerBackedOut = 1;
          if ( UFG::HudAudio::m_instance )
            UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xA4E5BFBD, 0i64, 0, 0i64);
LABEL_45:
          UFG::UIHKScreenGarageBrowser::Exit(v5);
          goto LABEL_64;
        }
        if ( v4 == UI_HASH_BUTTON_SELECT_PRESSED_30 )
        {
          if ( !v5->mIsRestricted )
            UFG::UIHKScreenGarageBrowser::ToggleTickerPopup(v5);
          goto LABEL_64;
        }
        if ( mState == (NUM_CALIBRATION_STATES|STATE_BRIGHTNESS) && v4 == UI_HASH_PARKADE_OPEN_20 )
          goto LABEL_45;
      }
LABEL_64:
      msg = v3;
      msgId = v4;
      this = v5;
      return UFG::UIScreen::handleMessage(this, msgId, msg);
  }
}

// File Line: 1120
// RVA: 0x5D7820
void __fastcall UFG::UIHKScreenGarageBrowser::Exit(UFG::UIHKScreenGarageBrowser *this)
{
  UFG::UIScreen::invoke(this, "Animate_Outro");
  this->mState = 8;
  if ( UFG::UIHKScreenGlobalOverlay::mThis
    && UFG::UIHKScreenGlobalOverlay::mThis != (UFG::UIHKScreenGlobalOverlay *)-408i64 )
  {
    UFG::UIHK_NISOverlay::ShowElement(
      &UFG::UIHKScreenGlobalOverlay::mThis->NISOverlay,
      UFG::UIHKScreenGlobalOverlay::mThis,
      &UFG::UIHK_NISOverlay::m_curtains,
      1.0,
      0);
    UFG::UIHK_NISOverlay::m_curtains.m_mutingAudio = 0;
  }
  UFG::UIHK_NISOverlay::UpdateAudioMuteState();
}

// File Line: 1131
// RVA: 0x5D3460
void __fastcall UFG::UIHKScreenGarageBrowser::AfterFadeToBlackExit(UFG::UIHKScreenGarageBrowser *this)
{
  UFG::SimObjectVehicle *m_pSimObjVehicle; // rdx
  UFG::SimObject *m_pSimObject; // rcx
  UFG::ScriptCameraComponent *ComponentOfType; // rax
  UFG::UIHKHelpBarWidget *p_HelpBar; // rbx
  unsigned int v6; // eax

  UFG::VendorDialogueUtils::PlayStoreClerkDialogue(eStoreClerkDialogueContext_Exit, 1.0);
  if ( this->m_bFadeOutAndTeleportPlayer )
  {
    m_pSimObjVehicle = this->m_pSimObjVehicle;
    if ( m_pSimObjVehicle )
      UFG::VehicleUtility::PlaceCharacterInVehicle(LocalPlayer, m_pSimObjVehicle, eTARGET_TYPE_VEHICLE_DRIVER, 0, 0, 1);
  }
  ((void (__fastcall *)(UFG::TiDo *, __int64))UFG::TiDo::m_pInstance->vfptr[1].Close)(UFG::TiDo::m_pInstance, 4i64);
  m_pSimObject = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( m_pSimObject )
  {
    ComponentOfType = (UFG::ScriptCameraComponent *)UFG::SimObject::GetComponentOfType(
                                                      m_pSimObject,
                                                      UFG::ScriptCameraComponent::_TypeUID);
    if ( ComponentOfType )
      UFG::ScriptCameraComponent::ReleaseCamera(ComponentOfType, 0);
  }
  this->mFinished = 1;
  if ( UFG::UIHKScreenGlobalOverlay::mThis )
  {
    p_HelpBar = &UFG::UIHKScreenGlobalOverlay::mThis->HelpBar;
    v6 = UFG::qStringHash32("GARAGE", 0xFFFFFFFF);
    UFG::UIHKHelpBarWidget::Hide(p_HelpBar, v6);
    if ( UFG::UIHKScreenGlobalOverlay::mThis )
    {
      if ( UFG::UIHKScreenGlobalOverlay::mThis != (UFG::UIHKScreenGlobalOverlay *)-408i64 )
        UFG::UIHK_NISOverlay::HideElement(
          &UFG::UIHKScreenGlobalOverlay::mThis->NISOverlay,
          UFG::UIHKScreenGlobalOverlay::mThis,
          &UFG::UIHK_NISOverlay::m_curtains,
          1.0,
          0);
    }
  }
  UFG::UIHK_NISOverlay::UpdateAudioMuteState();
}

// File Line: 1164
// RVA: 0x5E8E40
__int64 __fastcall UFG::UIHKScreenGarageBrowser::GetSelectedIndex(UFG::UIHKScreenGarageBrowser *this)
{
  Scaleform::GFx::Movie *pObject; // rcx
  unsigned int NValue; // ebx
  Scaleform::GFx::Value pval; // [rsp+28h] [rbp-40h] BYREF

  pObject = this->mRenderable->m_movie.pObject;
  if ( !pObject )
    return 0i64;
  pval.pObjectInterface = 0i64;
  pval.Type = VT_Undefined;
  Scaleform::GFx::Movie::GetVariable(pObject, &pval, "SelectedIndex");
  NValue = (int)pval.mValue.NValue;
  if ( (pval.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pval.pObjectInterface->vfptr->gap8[8])(
      pval.pObjectInterface,
      &pval,
      pval.mValue);
    pval.pObjectInterface = 0i64;
  }
  return NValue;
}

// File Line: 1184
// RVA: 0x5FEFE0
void UFG::UIHKScreenGarageBrowser::QueuePush(void)
{
  UFG::UIScreenTextureManager *v0; // rax

  v0 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::QueueLoadAndPush(v0, "GarageBrowser", 0i64);
}

// File Line: 1190
// RVA: 0x5D5700
void __fastcall UFG::UIHKScreenGarageBrowser::ClearList(UFG::UIHKScreenGarageBrowser *this)
{
  UFG::UIHKGarageVehicleInfo *p; // rcx
  unsigned int *p_discountPercent; // rbx

  Scaleform::GFx::Movie::Invoke(this->mRenderable->m_movie.pObject, "VehicleList_Clear", 0i64, 0i64, 0);
  p = this->mVehicleList.p;
  if ( p )
  {
    p_discountPercent = &p[-1].discountPercent;
    `eh vector destructor iterator(
      p,
      0x110ui64,
      p[-1].discountPercent,
      (void (__fastcall *)(void *))UFG::UIHKGarageVehicleInfo::~UIHKGarageVehicleInfo);
    operator delete[](p_discountPercent);
  }
  this->mVehicleList.p = 0i64;
  *(_QWORD *)&this->mVehicleList.size = 0i64;
}

// File Line: 1198
// RVA: 0x5E9AF0
const char *__fastcall UFG::UIHKScreenGarageBrowser::GetVehicleTierString(
        UFG::UIHKScreenGarageBrowser *this,
        const char *tierId)
{
  if ( !tierId )
    return 0i64;
  if ( !(unsigned int)UFG::qStringCompare(tierId, "Class A", -1) )
    return "$VEHICLE_TIER_CLASSA";
  if ( !(unsigned int)UFG::qStringCompare(tierId, "Class B", -1) )
    return "$VEHICLE_TIER_CLASSB";
  if ( !(unsigned int)UFG::qStringCompare(tierId, "Class C", -1) )
    return "$VEHICLE_TIER_CLASSC";
  if ( !(unsigned int)UFG::qStringCompare(tierId, "Class D", -1) )
    return "$VEHICLE_TIER_CLASSD";
  if ( (unsigned int)UFG::qStringCompare(tierId, "Class E", -1) )
    return 0i64;
  else
    return "$VEHICLE_TIER_CLASSE";
}

// File Line: 1226
// RVA: 0x5F2290
void __fastcall UFG::UIHKScreenGarageBrowser::NetworkSignedIn(
        UFG::UIHKScreenGarageBrowser *this,
        hkgpIndexedMeshDefinitions::Edge *a2)
{
  __int64 v3; // rax
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h] BYREF

  v3 = *(_QWORD *)&this[-1].m_iTextureHandleIndex;
  if ( v3 && *(_QWORD *)(v3 + 320) && Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(0i64, a2) )
  {
    BYTE1(this->mCarTextures[0].mMagic) = 1;
    HIBYTE(this->mCarTextures[0].mNext) = 0;
    UFG::UIHKScreenGarageBrowser::ShowTickerPopup((UFG::UIHKScreenGarageBrowser *)((char *)this - 152), 0);
    UFG::UIHKScreenGarageBrowser::ShowHelpBar(
      (UFG::UIHKScreenGarageBrowser *)((char *)this - 152),
      *(UFG::UIHKScreenGarageBrowser::eHelpBarState *)this->m_screenName,
      HIBYTE(this->mCarTextures[0].mNext));
    pargs.pObjectInterface = 0i64;
    pargs.Type = VT_String;
    pargs.mValue.pString = &customCaption;
    Scaleform::GFx::Movie::Invoke(
      *(Scaleform::GFx::Movie **)(*(_QWORD *)&this[-1].m_iTextureHandleIndex + 320i64),
      "SetTickerText",
      0i64,
      &pargs,
      1u);
    if ( (pargs.Type & 0x40) != 0 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        pargs.mValue);
  }
}

