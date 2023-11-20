// File Line: 67
// RVA: 0x156E070
__int64 UFG::_dynamic_initializer_for__gUIGarageScreenDeferredTaskChannel__()
{
  UFG::ChannelObj::ChannelObj(&UFG::gUIGarageScreenDeferredTaskChannel, "EVT_UI_GARAGE_DEFERRED_TASK_CHANNEL", 0i64);
  return atexit(UFG::_dynamic_atexit_destructor_for__gUIGarageScreenDeferredTaskChannel__);
}

// File Line: 77
// RVA: 0x1567520
__int64 dynamic_initializer_for__UFG::UIHKScreenGarageBrowser::mVehicleOrderOverride__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::UIHKScreenGarageBrowser::mVehicleOrderOverride__);
}

// File Line: 95
// RVA: 0x5C5470
void __fastcall UFG::UIHKScreenGarageBrowser::UIHKScreenGarageBrowser(UFG::UIHKScreenGarageBrowser *this)
{
  UFG::UIHKScreenGarageBrowser *v1; // rbx
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v2; // rax
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *v3; // rax
  hkSeekableStreamReader *v4; // [rsp+38h] [rbp-20h]
  void (__fastcall *v5)(UFG::UIHKScreenGarageBrowser *, UFG::Event *); // [rsp+40h] [rbp-18h]
  UFG::OnlineManagerObserver *v6; // [rsp+68h] [rbp+10h]

  v1 = this;
  v2 = (UFG::qNode<UFG::UIScreen,UFG::UIScreen> *)&this->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKTaskableScreen::`vftable;
  this->mFinished = 0;
  v6 = (UFG::OnlineManagerObserver *)&this->vfptr;
  v3 = (UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *)&this->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  v6->vfptr = (UFG::OnlineManagerObserverVtbl *)&UFG::OnlineManagerObserver::`vftable;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenGarageBrowser::`vftable{for `UFG::UIHKTaskableScreen};
  v6->vfptr = (UFG::OnlineManagerObserverVtbl *)&UFG::UIHKScreenGarageBrowser::`vftable{for `UFG::OnlineManagerObserver};
  this->mHelpBarState = 0;
  *(_QWORD *)&this->mState = 0i64;
  this->mVehicleList.p = 0i64;
  *(_QWORD *)&this->mVehicleList.size = 0i64;
  UFG::qString::qString(&this->mTexturePackToLoad);
  `eh vector constructor iterator(v1->mCarTextures, 0x28ui64, 3, (void (__fastcall *)(void *))UFG::qString::qString);
  *(_QWORD *)&v1->m_iTextureHandleIndex = 0i64;
  v1->m_pSimObjVehicle = 0i64;
  UFG::UIHKDepthOfFieldWidget::UIHKDepthOfFieldWidget(&v1->DOF);
  v1->mLoadingTimeout = 0.0;
  *(_DWORD *)&v1->m_bFadeOutAndTeleportPlayer = 257;
  *(_WORD *)&v1->mInfoTickerViewed = 0;
  v1->mCurrentVehicle = 0i64;
  v5 = UFG::UIHKScreenGarageBrowser::HandleDeferredTask;
  v4 = Assembly::GetRCX(v1);
  UFG::EventDispatcher::Register(
    &UFG::EventDispatcher::mInstance,
    (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v4,
    UFG::gUIGarageScreenDeferredTaskChannel.mUID,
    0i64,
    0);
  UFG::UIHKScreenGarageBrowser::mPlayerBackedOut = 0;
  UFG::UIHKScreenGarageBrowser::mSkipCustomization = 0;
  if ( UFG::ProgressionTracker::Instance()->mModeType == 2 )
    v1->m_bBackbuttonEnabled = 0;
}

// File Line: 115
// RVA: 0x5CAC30
void __fastcall UFG::UIHKScreenGarageBrowser::~UIHKScreenGarageBrowser(UFG::UIHKScreenGarageBrowser *this)
{
  UFG::UIHKScreenGarageBrowser *v1; // r14
  UFG::OnlineManagerObserver *v2; // r15
  UFG::OnlineManager *v3; // rax
  UFG::UI *v4; // rcx
  UFG::UIHKHelpBarWidget *v5; // rbx
  unsigned int v6; // eax
  unsigned int v7; // eax
  int v8; // eax
  UFG::UIScreenTextureManager *v9; // rax
  const char **v10; // rdi
  signed __int64 v11; // rsi
  const char *v12; // rbx
  UFG::UIScreenTextureManager *v13; // rax
  UFG::UIHKGarageVehicleInfo *v14; // rcx
  unsigned int *v15; // rbx
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *v16; // rdx
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *v17; // rcx
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *v18; // rax
  hkSeekableStreamReader *v19; // [rsp+28h] [rbp-40h]
  void (__fastcall *v20)(UFG::UIHKScreenGarageBrowser *, UFG::Event *); // [rsp+30h] [rbp-38h]

  v1 = this;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenGarageBrowser::`vftable{for `UFG::UIHKTaskableScreen};
  v2 = (UFG::OnlineManagerObserver *)&this->vfptr;
  this->vfptr = (UFG::OnlineManagerObserverVtbl *)&UFG::UIHKScreenGarageBrowser::`vftable{for `UFG::OnlineManagerObserver};
  v3 = UFG::OnlineManager::Instance();
  UFG::OSuiteManager::UnRegisterObserver(v3, v2);
  v20 = UFG::UIHKScreenGarageBrowser::HandleDeferredTask;
  v19 = Assembly::GetRCX(v1);
  UFG::EventDispatcher::UnRegister(
    &UFG::EventDispatcher::mInstance,
    (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v19,
    UFG::gUIGarageScreenDeferredTaskChannel.mUID);
  if ( UFG::UIHKScreenGlobalOverlay::mThis )
  {
    v5 = &UFG::UIHKScreenGlobalOverlay::mThis->HelpBar;
    v6 = UFG::qStringHash32("GARAGE", 0xFFFFFFFF);
    UFG::UIHKHelpBarWidget::Hide(v5, v6);
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
  if ( unk_142431A14 && UFG::UIHK_PDAWidget::mInputLocked > 0 )
  {
    UFG::SetInputMode_PDA_Off(UFG::gActiveControllerNum);
    v8 = UFG::UIHKGameplayHelpWidget::mLocked;
    if ( UFG::UIHKGameplayHelpWidget::mLocked > 0 )
      v8 = UFG::UIHKGameplayHelpWidget::mLocked-- - 1;
    if ( v8 < 1 )
      UFG::UIHKScreenHud::GameplayHelp->mChanged = 1;
    --UFG::UIHK_PDAWidget::mInputLocked;
  }
  UFG::UIHKScreenHud::PDACache.state = 0;
  unk_142431A14 = 0;
  unk_142431A18 = 0;
  v9 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v9, "GarageBrowser");
  v10 = (const char **)&v1->mCarTextures[0].mData;
  v11 = 3i64;
  do
  {
    v12 = *v10;
    v13 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::ReleaseTexturePack(v13, v12);
    v10 += 5;
    --v11;
  }
  while ( v11 );
  UFG::GameCameraComponent::EndDOFOverride(0);
  `eh vector destructor iterator(v1->mCarTextures, 0x28ui64, 3, (void (__fastcall *)(void *))UFG::qString::~qString);
  UFG::qString::~qString(&v1->mTexturePackToLoad);
  v14 = v1->mVehicleList.p;
  if ( v14 )
  {
    v15 = &v14[-1].discountPercent;
    `eh vector destructor iterator(
      v14,
      0x110ui64,
      v14[-1].discountPercent,
      (void (__fastcall *)(void *))UFG::UIHKGarageVehicleInfo::~UIHKGarageVehicleInfo);
    operator delete[](v15);
  }
  v1->mVehicleList.p = 0i64;
  *(_QWORD *)&v1->mVehicleList.size = 0i64;
  v2->vfptr = (UFG::OnlineManagerObserverVtbl *)&UFG::OnlineManagerObserver::`vftable;
  v16 = (UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *)&v2->mPrev;
  v17 = v2->mPrev;
  v18 = v2->mNext;
  v17->mNext = v18;
  v18->mPrev = v17;
  v16->mPrev = v16;
  v16->mNext = v16;
  UFG::UIScreen::~UIScreen((UFG::UIScreen *)&v1->vfptr);
}

// File Line: 148
// RVA: 0x6128E0
void __fastcall UFG::UIHKScreenGarageBrowser::TextureLoadedCallback(UFG::DataStreamer::Handle *handle, void *param)
{
  UFG::UIHKScreenGarageBrowser *v2; // rax

  v2 = (UFG::UIHKScreenGarageBrowser *)UFG::UIScreenManagerBase::getScreen(
                                         (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
                                         "GarageBrowser");
  if ( v2 )
    UFG::UIHKScreenGarageBrowser::LoadTextureInFlash(v2);
}

// File Line: 158
// RVA: 0x5F12B0
void __fastcall UFG::UIHKScreenGarageBrowser::LoadTextureInFlash(UFG::UIHKScreenGarageBrowser *this)
{
  UFG::UIHKScreenGarageBrowser *v1; // rbx
  Scaleform::GFx::Movie *v2; // rdi
  char *v3; // rbx
  UFG::qString v4; // [rsp+38h] [rbp-60h]
  Scaleform::GFx::Value pargs; // [rsp+60h] [rbp-38h]

  v1 = this;
  if ( this->mCurrentVehicle )
  {
    v2 = this->mRenderable->m_movie.pObject;
    `eh vector constructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    UFG::qString::qString(&v4);
    UFG::qString::Format(&v4, "img://%s", v1->mCurrentVehicle->texture.mData);
    v3 = v4.mData;
    if ( ((unsigned int)pargs.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        *(_QWORD *)&pargs.mValue.NValue);
      pargs.pObjectInterface = 0i64;
    }
    pargs.Type = 6;
    *(_QWORD *)&pargs.mValue.NValue = v3;
    Scaleform::GFx::Movie::Invoke(v2, "SetTexture", 0i64, &pargs, 1u);
    UFG::qString::~qString(&v4);
    `eh vector destructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 173
// RVA: 0x5F13D0
void __fastcall UFG::UIHKScreenGarageBrowser::LoadTexturePack(UFG::UIHKScreenGarageBrowser *this)
{
  UFG::UIHKGarageVehicleInfo *v1; // r8
  UFG::UIHKScreenGarageBrowser *v2; // rdi
  const char *v3; // rbx
  UFG::UIScreenTextureManager *v4; // rax
  signed int v5; // eax
  const char *v6; // rbx
  UFG::UIScreenTextureManager *v7; // rax

  v1 = this->mCurrentVehicle;
  v2 = this;
  if ( v1 )
  {
    UFG::qString::Format(&this->mTexturePackToLoad, "Data\\UI\\%s_TP.perm.bin", v1->texture.mData);
    v3 = v2->mCarTextures[v2->m_iPrevTextureHandleIndex].mData;
    v4 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::ReleaseTexturePack(v4, v3);
    v5 = v2->m_iTextureHandleIndex;
    v2->m_iPrevTextureHandleIndex = v5++;
    v2->m_iTextureHandleIndex = v5;
    if ( v5 >= 3 )
      v2->m_iTextureHandleIndex = 0;
    UFG::qString::Set(
      (UFG::qString *)(&v2->vfptr + v2->m_iTextureHandleIndex + 4i64 * v2->m_iTextureHandleIndex + 34),
      v2->mTexturePackToLoad.mData,
      v2->mTexturePackToLoad.mLength,
      0i64,
      0);
    v6 = v2->mCarTextures[v2->m_iTextureHandleIndex].mData;
    v7 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::QueueTexturePackLoad(
      v7,
      v6,
      HIGH_PRIORITY,
      UFG::UIHKScreenGarageBrowser::TextureLoadedCallback,
      0i64);
  }
}

// File Line: 195
// RVA: 0x611270
void __fastcall UFG::UIHKScreenGarageBrowser::ShowTickerPopup(UFG::UIHKScreenGarageBrowser *this, bool isVisible)
{
  bool v2; // di
  UFG::UIHKScreenGarageBrowser *v3; // rbx
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h]

  v2 = isVisible;
  v3 = this;
  pargs.pObjectInterface = 0i64;
  pargs.Type = 2;
  pargs.mValue.BValue = isVisible;
  Scaleform::GFx::Movie::Invoke(this->mRenderable->m_movie.pObject, "ShowTickerPopup", 0i64, &pargs, 1u);
  if ( v2 )
    v3->mInfoTickerViewed = 1;
  if ( ((unsigned int)pargs.Type >> 6) & 1 )
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      *(_QWORD *)&pargs.mValue.NValue);
}

// File Line: 205
// RVA: 0x631B90
void __usercall UFG::UIHKScreenGarageBrowser::init(UFG::UIHKScreenGarageBrowser *this@<rcx>, UFG::UICommandData *data@<rdx>, float *a3@<r13>)
{
  UFG::UICommandData *v3; // rbx
  UFG::UIHKScreenGarageBrowser *v4; // rdi
  Scaleform::GFx::Movie *v5; // rsi
  __int64 v6; // rbx
  UFG::Controller *v7; // r8
  UFG::OSuiteTickerManager *v8; // rax
  char *v9; // rbx
  hkpNullContactMgr *v10; // rax
  hkpCollidable *v11; // rdx
  hkpCollidable *v12; // r8
  hkpCollisionInput *v13; // r9
  UFG::OnlineManager *v14; // rax
  char ptr; // [rsp+40h] [rbp-68h]
  __int64 v16; // [rsp+50h] [rbp-58h]
  unsigned int v17; // [rsp+58h] [rbp-50h]
  const char *v18; // [rsp+60h] [rbp-48h]
  char v19; // [rsp+70h] [rbp-38h]
  __int64 v20; // [rsp+80h] [rbp-28h]
  unsigned int v21; // [rsp+88h] [rbp-20h]
  char *v22; // [rsp+90h] [rbp-18h]

  v3 = data;
  v4 = this;
  this->mIsRestricted = Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
                          0i64,
                          (hkgpIndexedMeshDefinitions::Edge *)data);
  UFG::UIScreen::init((UFG::UIScreen *)&v4->vfptr, v3);
  v5 = v4->mRenderable->m_movie.pObject;
  if ( v5 )
  {
    v6 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
           Scaleform::Memory::pGlobalHeap,
           32i64);
    if ( v6 )
    {
      *(_QWORD *)v6 = &Scaleform::RefCountImplCore::`vftable;
      *(_DWORD *)(v6 + 8) = 1;
      *(_QWORD *)v6 = &Scaleform::RefCountImpl::`vftable;
      *(_QWORD *)v6 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
      *(_QWORD *)v6 = &Scaleform::RefCountBase<Scaleform::GFx::State,2>::`vftable;
      *(_QWORD *)v6 = &Scaleform::GFx::State::`vftable;
      *(_DWORD *)(v6 + 16) = 3;
      *(_QWORD *)v6 = &Scaleform::GFx::ActionControl::`vftable;
      *(_DWORD *)(v6 + 24) = 8;
    }
    else
    {
      v6 = 0i64;
    }
    if ( v6 )
    {
      *(_DWORD *)(v6 + 24) |= 2u;
      v5->vfptr->SetState((Scaleform::GFx::StateBag *)&v5->vfptr, State_Filter, (Scaleform::GFx::State *)v6);
    }
    if ( v6 )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v6);
  }
  if ( UFG::gInputSystem && UFG::gActiveControllerNum != -1 )
  {
    v7 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum];
    if ( !UFG::UI::gUIInputLocked )
      g_saved_gameplay_controller_mode = v7->m_ActiveMapSet;
    UFG::SetInputMode(IM_UI_ONLY, v7->mControllerIndex);
    ++UFG::UI::gUIInputLocked;
  }
  if ( !UFG::UIHKScreenGlobalOverlay::mThis
    || UFG::UIHKScreenGlobalOverlay::mThis == (UFG::UIHKScreenGlobalOverlay *)-408i64
    || UFG::UIHKScreenGlobalOverlay::mThis->NISOverlay.mActive )
  {
    UFG::UIHKScreenGarageBrowser::AfterFadeToBlackInit(v4, a3);
  }
  else
  {
    v4->mState = 7;
    if ( UFG::UIHKScreenGlobalOverlay::mThis
      && UFG::UIHKScreenGlobalOverlay::mThis != (UFG::UIHKScreenGlobalOverlay *)-408i64 )
    {
      UFG::UIHK_NISOverlay::ShowElement(
        &UFG::UIHKScreenGlobalOverlay::mThis->NISOverlay,
        (UFG::UIScreen *)&UFG::UIHKScreenGlobalOverlay::mThis->vfptr,
        &UFG::UIHK_NISOverlay::m_curtains,
        0.33000001,
        0);
      UFG::UIHK_NISOverlay::m_curtains.m_mutingAudio = 0;
    }
    UFG::UIHK_NISOverlay::UpdateAudioMuteState();
  }
  UFG::UIGfxTranslator::loadDictionary(UFG::UIScreenManager::s_instance->m_translator, "ITEMS");
  `eh vector constructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  if ( (v17 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v16 + 16i64))(v16, &ptr, v18);
    v16 = 0i64;
  }
  v17 = 6;
  v18 = "img://INFOCAST_CHANNEL_2";
  v8 = UFG::OSuiteTickerManager::Instance();
  v9 = UFG::OSuiteTickerManager::GetTickerDescription(v8, 2i64, 1);
  if ( (v21 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v20 + 16i64))(v20, &v19, v22);
    v20 = 0i64;
  }
  v21 = 6;
  v22 = v9;
  Scaleform::GFx::Movie::Invoke(
    v4->mRenderable->m_movie.pObject,
    "SetTickerPopupInfo",
    0i64,
    (Scaleform::GFx::Value *)&ptr,
    2u);
  UFG::UIHKScreenGarageBrowser::ShowTickerPopup(v4, v4->mInfoTickerPopupVisible);
  v10 = (hkpNullContactMgr *)UFG::StoreFrontTracker::Instance();
  if ( v10 )
    v10 = hkpNullContactMgrFactory::createContactMgr((hkpNullContactMgrFactory *)v10, v11, v12, v13);
  v4->mStore = (UFG::StoreFront *)v10;
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(
      (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
      0xF41B2F0D,
      0i64,
      0,
      0i64);
  v14 = UFG::OnlineManager::Instance();
  UFG::OnlineManager::RegisterObserver(v14, (UFG::OnlineManagerObserver *)&v4->vfptr);
  `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 263
// RVA: 0x5D3560
void __usercall UFG::UIHKScreenGarageBrowser::AfterFadeToBlackInit(UFG::UIHKScreenGarageBrowser *this@<rcx>, float *a2@<r13>)
{
  UFG::UIHKScreenGarageBrowser *v2; // rbx
  hkpNullContactMgr *v3; // rax
  hkpCollidable *v4; // rdx
  hkpCollidable *v5; // r8
  hkpCollisionInput *v6; // r9
  UFG::StoreFront *v7; // rcx
  UFG::qString *v8; // rax
  UFG::qString *v9; // rax
  UFG::GameStatTracker *v10; // rax
  hkpNullContactMgr *v11; // rax
  hkpCollidable *v12; // rdx
  hkpCollidable *v13; // r8
  hkpCollisionInput *v14; // r9
  UFG::qBaseNodeRB *v15; // rax
  UFG::TransformNodeComponent *v16; // rsi
  UFG::SimObject *v17; // rcx
  UFG::ScriptCameraComponent *v18; // rax
  UFG::ScriptCameraComponent *v19; // rdi
  bool v20; // di
  Scaleform::GFx::Movie *v21; // rbx
  UFG::qString result; // [rsp+38h] [rbp-60h]
  char ptr; // [rsp+60h] [rbp-38h]
  __int64 v24; // [rsp+70h] [rbp-28h]
  unsigned int v25; // [rsp+78h] [rbp-20h]
  __int64 v26; // [rsp+80h] [rbp-18h]

  v2 = this;
  v3 = (hkpNullContactMgr *)UFG::StoreFrontTracker::Instance();
  if ( v3 )
    v3 = hkpNullContactMgrFactory::createContactMgr((hkpNullContactMgrFactory *)v3, v4, v5, v6);
  v2->mStore = (UFG::StoreFront *)v3;
  UFG::StoreFront::ClosePreviewShutter((UFG::StoreFront *)v3);
  v7 = v2->mStore;
  v2->m_bFadeOutAndTeleportPlayer = v7->mStoreType != 3;
  if ( (v7->mStoreType - 1) & 0xFFFFFFFD )
  {
    UFG::UIHKScreenGarageBrowser::SetStoreTitle(v2, "$GARAGE_TITLE");
    UFG::UIHKScreenGarageBrowser::SetStoreDesc(v2, &customWorldMapCaption);
  }
  else
  {
    v8 = UFG::StoreFront::GetStoreTitle(v7, &result);
    UFG::UIHKScreenGarageBrowser::SetStoreTitle(v2, v8->mData);
    UFG::qString::~qString(&result);
    v9 = UFG::StoreFront::GetStoreDesc(v2->mStore, &result);
    UFG::UIHKScreenGarageBrowser::SetStoreDesc(v2, v9->mData);
    UFG::qString::~qString(&result);
  }
  v10 = UFG::GameStatTracker::Instance();
  if ( (unsigned __int8)UFG::GameStatTracker::GetStat(v10, EnableValet) == 1 )
    UFG::UIHKScreenGarageBrowser::SetValetTitle(v2, "$GARAGE_NOVALETCAR");
  UFG::UIHKScreenGarageBrowser::PopulateInventory(v2);
  ((void (__fastcall *)(UFG::TiDo *, signed __int64))UFG::TiDo::m_pInstance->vfptr[1].Close)(
    UFG::TiDo::m_pInstance,
    5i64);
  v11 = (hkpNullContactMgr *)UFG::StoreFrontTracker::Instance();
  if ( v11 )
    v11 = hkpNullContactMgrFactory::createContactMgr((hkpNullContactMgrFactory *)v11, v12, v13, v14);
  UFG::VendorDialogueUtils::Setup((UFG::StoreFront *)v11);
  UFG::VendorDialogueUtils::PlayStoreClerkDialogue(0, 1.0);
  if ( v2->mNumItems <= 0 )
  {
    v2->mState = 4;
  }
  else
  {
    v15 = UFG::StoreFront::GetCameraMarker(v2->mStore);
    if ( v15 )
    {
      v16 = *(UFG::TransformNodeComponent **)&v15[2].mUID;
      v17 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
      if ( v17 )
      {
        v18 = (UFG::ScriptCameraComponent *)UFG::SimObject::GetComponentOfType(
                                              v17,
                                              UFG::ScriptCameraComponent::_TypeUID);
        v19 = v18;
        if ( v18 )
        {
          UFG::ScriptCameraComponent::SwitchToScriptCam(v18, v16, 0, 0.0, a2);
          ((void (__fastcall *)(UFG::ScriptCameraComponent *))v19->vfptr[15].__vecDelDtor)(v19);
        }
      }
    }
    v2->mState = 1;
  }
  v20 = v2->mStore->mStoreType == 1;
  v21 = v2->mRenderable->m_movie.pObject;
  `eh vector constructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  if ( (v25 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v24 + 16i64))(v24, &ptr, v26);
    v24 = 0i64;
  }
  v25 = 2;
  LOBYTE(v26) = v20;
  Scaleform::GFx::Movie::Invoke(v21, "SetIsStore", 0i64, (Scaleform::GFx::Value *)&ptr, 1u);
  if ( UFG::UIHKScreenGlobalOverlay::mThis
    && UFG::UIHKScreenGlobalOverlay::mThis != (UFG::UIHKScreenGlobalOverlay *)-408i64 )
  {
    UFG::UIHK_NISOverlay::HideElement(
      &UFG::UIHKScreenGlobalOverlay::mThis->NISOverlay,
      (UFG::UIScreen *)&UFG::UIHKScreenGlobalOverlay::mThis->vfptr,
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
  UFG::UIHKScreenGarageBrowser *v2; // rdi
  Scaleform::GFx::Movie *v3; // rbx
  UFG::GameStatTracker *v4; // rax
  Scaleform::GFx::Value v5; // [rsp+20h] [rbp-11h]
  Scaleform::GFx::Value value; // [rsp+50h] [rbp+1Fh]

  v2 = this;
  v3 = this->mRenderable->m_movie.pObject;
  if ( v3 )
  {
    value.pObjectInterface = 0i64;
    value.Type = 6;
    *(_QWORD *)&value.mValue.NValue = title;
    Scaleform::GFx::Movie::SetVariable(v3, "mcTitle.text", &value, 1i64);
    if ( (v2->mStore->mStoreType - 1) & 0xFFFFFFFD )
    {
      v4 = UFG::GameStatTracker::Instance();
      if ( (unsigned __int8)UFG::GameStatTracker::GetStat(v4, EnableValet) != 1 )
      {
LABEL_10:
        if ( ((unsigned int)value.Type >> 6) & 1 )
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
            value.pObjectInterface,
            &value,
            *(_QWORD *)&value.mValue.NValue);
        return;
      }
      v5.pObjectInterface = 0i64;
      v5.Type = 2;
      v5.mValue.BValue = 1;
      Scaleform::GFx::Movie::SetVariable(v3, "mc_valet._visible", &v5, 1i64);
    }
    else
    {
      v5.pObjectInterface = 0i64;
      v5.Type = 2;
      v5.mValue.BValue = 1;
      Scaleform::GFx::Movie::SetVariable(v3, "mc_Money._visible", &v5, 1i64);
      if ( v2->mStore->mStoreType == 3 )
        Scaleform::GFx::Movie::SetVariable(v3, "gIsRace", &v5, 1i64);
    }
    if ( ((unsigned int)v5.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&v5.pObjectInterface->vfptr->gap8[8])(
        v5.pObjectInterface,
        &v5,
        *(_QWORD *)&v5.mValue.NValue);
      v5.pObjectInterface = 0i64;
    }
    v5.Type = 0;
    goto LABEL_10;
  }
}

// File Line: 364
// RVA: 0x60C570
void __fastcall UFG::UIHKScreenGarageBrowser::SetValetTitle(UFG::UIHKScreenGarageBrowser *this, const char *title)
{
  Scaleform::GFx::Movie *v2; // rbx
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-40h]

  v2 = this->mRenderable->m_movie.pObject;
  if ( v2 )
  {
    value.pObjectInterface = 0i64;
    value.Type = 6;
    *(_QWORD *)&value.mValue.NValue = title;
    Scaleform::GFx::Movie::SetVariable(v2, "mc_valet.mc_valet.txt_valet.text", &value, 1i64);
    if ( ((unsigned int)value.Type >> 6) & 1 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        *(_QWORD *)&value.mValue.NValue);
  }
}

// File Line: 378
// RVA: 0x609910
void __fastcall UFG::UIHKScreenGarageBrowser::SetStoreDesc(UFG::UIHKScreenGarageBrowser *this, const char *desc)
{
  Scaleform::GFx::Movie *v2; // rbx
  char v3; // [rsp+20h] [rbp-11h]
  __int64 v4; // [rsp+30h] [rbp-1h]
  unsigned int v5; // [rsp+38h] [rbp+7h]
  const char *v6; // [rsp+40h] [rbp+Fh]
  Scaleform::GFx::Value value; // [rsp+50h] [rbp+1Fh]

  v2 = this->mRenderable->m_movie.pObject;
  if ( v2 )
  {
    v4 = 0i64;
    v5 = 6;
    v6 = desc;
    value.pObjectInterface = 0i64;
    value.Type = 6;
    *(_QWORD *)&value.mValue.NValue = desc;
    Scaleform::GFx::Movie::SetVariable(v2, "mcDesc.text", &value, 1i64);
    if ( ((unsigned int)value.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        *(_QWORD *)&value.mValue.NValue);
      value.pObjectInterface = 0i64;
    }
    value.Type = 0;
    if ( (v5 >> 6) & 1 )
      (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v4 + 16i64))(v4, &v3, v6);
  }
}

// File Line: 405
// RVA: 0x605390
void __fastcall UFG::UIHKScreenGarageBrowser::SetAsValet(UFG::UIHKScreenGarageBrowser *this)
{
  UFG::UIHKScreenGarageBrowser *v1; // rbx
  UFG::GameStatTracker *v2; // rax
  UFG::UIHKGarageVehicleInfo *v3; // rdi
  UFG::GameStatTracker *v4; // rax
  unsigned int v5; // edx
  Scaleform::GFx::Movie *v6; // rdi
  bool v7; // bl
  char ptr; // [rsp+38h] [rbp-40h]
  __int64 v9; // [rsp+48h] [rbp-30h]
  unsigned int v10; // [rsp+50h] [rbp-28h]
  __int64 v11; // [rsp+58h] [rbp-20h]

  v1 = this;
  if ( this->mState != 4 )
  {
    if ( this->mCurrentVehicle )
    {
      v2 = UFG::GameStatTracker::Instance();
      if ( (unsigned __int8)UFG::GameStatTracker::GetStat(v2, EnableValet) )
      {
        if ( (v1->mStore->mStoreType - 1) & 0xFFFFFFFD )
        {
          v3 = v1->mCurrentVehicle;
          if ( v3->bOwned )
          {
            v4 = UFG::GameStatTracker::Instance();
            UFG::GameStatTracker::SetStat(v4, ValetVehicle, &v3->spawnObjectInfo);
            v5 = 0;
            if ( v1->mVehicleList.size )
            {
              do
                v1->mVehicleList.p[v5++].bValetVehicle = 0;
              while ( v5 < v1->mVehicleList.size );
            }
            v1->mCurrentVehicle->bValetVehicle = 1;
            if ( UFG::HudAudio::m_instance )
              UFG::AudioEntity::CreateAndPlayEvent(
                (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
                0xF41B2F0D,
                0i64,
                0,
                0i64);
            v6 = v1->mRenderable->m_movie.pObject;
            if ( v6 )
            {
              `eh vector constructor iterator(
                &ptr,
                0x30ui64,
                1,
                (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
              v7 = v1->mNumItems == 0;
              if ( (v10 >> 6) & 1 )
              {
                (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v9 + 16i64))(v9, &ptr, v11);
                v9 = 0i64;
              }
              v10 = 2;
              LOBYTE(v11) = v7;
              Scaleform::GFx::Movie::Invoke(v6, "VehicleList_UpdateValet", 0i64, (Scaleform::GFx::Value *)&ptr, 1u);
              `eh vector destructor iterator(
                &ptr,
                0x30ui64,
                1,
                (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
            }
          }
          else
          {
            UFG::UIScreenDialogBox::createOKDialog(
              (UFG::UIScreen *)&v1->vfptr,
              &customWorldMapCaption,
              "$GARAGE_REQUIRES_PURCHASE",
              1);
          }
        }
      }
    }
  }
}

// File Line: 441
// RVA: 0x611C20
void __fastcall UFG::UIHKScreenGarageBrowser::SpawnVehicle(UFG::UIHKScreenGarageBrowser *this)
{
  UFG::UIHKGarageVehicleInfo *v1; // rax
  UFG::UIHKScreenGarageBrowser *v2; // rbx
  UFG::SimObjectCVBase *v3; // rax
  UFG::SimObject *v4; // rdi
  UFG::SimComponent *v5; // rax
  UFG::VehicleOwnershipComponent *v6; // rax
  UFG::VehicleOwnershipComponent *v7; // rbp
  UFG::SimObject *v8; // rsi
  UFG::VehicleOccupantComponent *v9; // rax

  v1 = this->mCurrentVehicle;
  v2 = this;
  if ( v1 )
  {
    v3 = UFG::StoreFront::SpawnItem(this->mStore, v1->storeIndex);
    v4 = (UFG::SimObject *)&v3->vfptr;
    if ( v3 )
    {
      v5 = UFG::SimObject::GetComponentOfType(
             (UFG::SimObject *)&v3->vfptr,
             UFG::SimObjectVehiclePropertiesComponent::_TypeUID);
      if ( v5 )
        LOBYTE(v5[3].m_Flags) = 1;
    }
    if ( LocalPlayer )
    {
      v6 = (UFG::VehicleOwnershipComponent *)UFG::SimObject::GetComponentOfType(
                                               (UFG::SimObject *)&LocalPlayer->vfptr,
                                               UFG::VehicleOwnershipComponent::_TypeUID);
      v7 = v6;
      if ( v6 )
      {
        v8 = UFG::VehicleOwnershipComponent::GetOwnedVehicle(v6);
        UFG::VehicleOwnershipComponent::TakeOwnsership(v7, v4);
        if ( v8 )
        {
          v9 = (UFG::VehicleOccupantComponent *)UFG::SimObject::GetComponentOfType(
                                                  v8,
                                                  UFG::VehicleOccupantComponent::_TypeUID);
          if ( !v9 || !(unsigned int)UFG::VehicleOccupantComponent::GetNumberOfOccupants(v9) )
            UFG::Simulation::QueueSimObjectToBeDestroyed(&UFG::gSim, v8);
        }
      }
    }
    v2->m_pSimObjVehicle = (UFG::SimObjectVehicle *)v4;
    v2->mState = 2;
    v2->mLoadingTimeout = 2.0;
  }
}

// File Line: 477
// RVA: 0x612CB0
void __fastcall UFG::UIHKScreenGarageBrowser::ToggleTickerPopup(UFG::UIHKScreenGarageBrowser *this)
{
  UFG::UIHKScreenGarageBrowser *v1; // rbx
  bool v2; // dl
  unsigned int v3; // edx

  v1 = this;
  v2 = this->mInfoTickerPopupVisible == 0;
  this->mInfoTickerPopupVisible = v2;
  UFG::UIHKScreenGarageBrowser::ShowTickerPopup(this, v2);
  UFG::UIHKScreenGarageBrowser::ShowHelpBar(v1, v1->mHelpBarState, v1->mInfoTickerPopupVisible);
  if ( v1->mInfoTickerPopupVisible )
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
  UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr, v3, 0i64, 0, 0i64);
}

// File Line: 490
// RVA: 0x5EA8B0
void __fastcall UFG::UIHKScreenGarageBrowser::HandleDeferredTask(UFG::UIHKScreenGarageBrowser *this, UFG::Event *e)
{
  int v2; // er8
  UFG::UIHKScreenGarageBrowser *v3; // rbx
  int v4; // er8
  UFG::UIHKGarageVehicleInfo *v5; // rax
  UFG::UIHKHelpBarWidget *v6; // rbx
  unsigned int v7; // eax

  v2 = e->mUserData0;
  v3 = this;
  if ( v2 )
  {
    v4 = v2 - 1;
    if ( v4 )
    {
      if ( v4 == 1 )
        UFG::UIHKScreenGarageBrowser::AfterFadeToBlackExit(this);
      return;
    }
    v5 = this->mCurrentVehicle;
    if ( !v5 )
      return;
    UFG::StoreFront::PurchaseItem(this->mStore, v5->storeIndex);
    if ( UFG::GameStatAction::Store::AreAllVehiclesPurchased() )
      UFG::AchievementTrophyManager::UnlockAchievementTrophy(39);
    this = v3;
  }
  UFG::UIHKScreenGarageBrowser::SpawnVehicle(this);
  if ( UFG::UIHKScreenGlobalOverlay::mThis )
  {
    v6 = &UFG::UIHKScreenGlobalOverlay::mThis->HelpBar;
    v7 = UFG::qStringHash32("GARAGE", 0xFFFFFFFF);
    UFG::UIHKHelpBarWidget::Hide(v6, v7);
  }
}

// File Line: 536
// RVA: 0x5EC6E0
char __fastcall UFG::UIHKScreenGarageBrowser::HandleVehicleSelected(UFG::UIHKScreenGarageBrowser *this)
{
  UFG::UIHKScreenGarageBrowser *v1; // rdi
  UFG::allocator::free_link *v2; // rax
  UFG::Event *v3; // rax
  UFG::qPropertySet *v5; // rax
  unsigned int *v6; // rax
  unsigned int *v7; // rcx
  unsigned int v8; // ebx
  UFG::GameStatTracker *v9; // rax
  UFG::allocator::free_link *v10; // [rsp+50h] [rbp+8h]

  v1 = this;
  if ( !this->mCurrentVehicle || !this->mStore )
    return 0;
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(
      (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
      0x4A3D1F6Cu,
      0i64,
      0,
      0i64);
  if ( !v1->mCurrentVehicle->bOwned )
  {
    v5 = UFG::StoreFront::GetItem(v1->mStore, v1->mSelectedIndex);
    LODWORD(v10) = 0;
    v6 = UFG::qPropertySet::Get<unsigned long>(
           v5,
           (UFG::qSymbol *)&UFG::StoreItemSymbol_FaceRequired.mUID,
           DEPTH_RECURSE);
    v7 = (unsigned int *)&v10;
    if ( v6 )
      v7 = v6;
    v8 = *v7;
    v9 = UFG::GameStatTracker::Instance();
    if ( v8 <= (unsigned int)UFG::GameStatTracker::GetFaceLevel(v9) )
    {
      if ( UFG::StoreFront::CanPurchase(v1->mStore, v1->mCurrentVehicle->storeIndex) )
      {
        UFG::UIScreenDialogBox::createYesNoDialog(
          (UFG::UIScreen *)&v1->vfptr,
          &customWorldMapCaption,
          "$STORE_PURCHASE_ITEM",
          0,
          1);
        return 1;
      }
      UFG::VendorDialogueUtils::PlayStoreClerkDialogue(eStoreClerkDialogueContext_NoMoney, 1.0);
      UFG::UIScreenDialogBox::createOKDialog(
        (UFG::UIScreen *)&v1->vfptr,
        &customWorldMapCaption,
        "$STORE_INSUFFICIENT_MONEY",
        0);
    }
    else
    {
      UFG::UIScreenDialogBox::createOKDialog(
        (UFG::UIScreen *)&v1->vfptr,
        &customWorldMapCaption,
        "$WARDROBE_FACE_TOO_LOW",
        0);
      v1->mState = 6;
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
  float v2; // xmm7_4
  UFG::UIHKScreenGarageBrowser *v3; // rbx
  __int32 v4; // ecx
  int v5; // ecx
  UFG::SimObjectVehicle *v6; // rax
  UFG::SimComponent *v7; // rcx
  UFG::OSuiteTickerManager *v8; // rax
  char *v9; // rdi
  float v10; // xmm0_4
  hkpNullContactMgrFactory *v11; // rax
  hkpCollidable *v12; // rdx
  hkpCollidable *v13; // r8
  hkpCollisionInput *v14; // r9
  hkpNullContactMgr *v15; // rax
  float v16; // xmm1_4
  UFG::UIHKScreenGlobalOverlay *v17; // rax
  signed __int64 v18; // rcx
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-50h]

  v2 = elapsed;
  v3 = this;
  v4 = this->mState - 1;
  if ( v4 )
  {
    v5 = v4 - 1;
    if ( v5 )
    {
      if ( v5 == 1 )
      {
        UFG::StoreFront::OpenPreviewShutter(v3->mStore);
        v3->mState = 5;
        UFG::UIHKScreenGarageBrowser::Exit(v3);
      }
    }
    else
    {
      v6 = v3->m_pSimObjVehicle;
      if ( v6 )
        v7 = v6->m_Components.p[10].m_pComponent;
      else
        v7 = 0i64;
      if ( v3->mStore
        && UFG::TrueCrowdSet::Instance::IsLoaded((UFG::TrueCrowdSet::Instance *)&v7[4].m_SafePointerList.mNode.mNext) )
      {
        v3->mState = 3;
      }
    }
  }
  else if ( !v3->mInfoTickerTextSet )
  {
    pargs.pObjectInterface = 0i64;
    pargs.Type = 0;
    v8 = UFG::OSuiteTickerManager::Instance();
    v9 = UFG::OSuiteTickerManager::GetTickerDescription(v8, 2i64, 0);
    pargs.Type = 6;
    *(_QWORD *)&pargs.mValue.NValue = v9;
    Scaleform::GFx::Movie::Invoke(v3->mRenderable->m_movie.pObject, "SetTickerText", 0i64, &pargs, 1u);
    v3->mInfoTickerTextSet = 1;
    if ( ((unsigned int)pargs.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        *(_QWORD *)&pargs.mValue.NValue);
      pargs.pObjectInterface = 0i64;
    }
    pargs.Type = 0;
  }
  v10 = UFG::VendorDialogueUtils::sm_idleTime + elapsed;
  UFG::VendorDialogueUtils::sm_idleTime = UFG::VendorDialogueUtils::sm_idleTime + elapsed;
  if ( UFG::VendorDialogueUtils::sm_playBrowse > 0 && v10 > 1.0 )
  {
    v11 = (hkpNullContactMgrFactory *)UFG::StoreFrontTracker::Instance();
    if ( v11 )
      v15 = hkpNullContactMgrFactory::createContactMgr(v11, v12, v13, v14);
    else
      v15 = 0i64;
    if ( LODWORD(v15[1].vfptr) == 1 )
      v16 = *(float *)&FLOAT_1_0;
    else
      v16 = FLOAT_2_0;
    UFG::VendorDialogueUtils::PlayStoreClerkDialogue(eStoreClerkDialogueContext_Browse, v16);
    UFG::VendorDialogueUtils::sm_playBrowse = 0;
  }
  if ( UFG::UIScreenManagerBase::getTopScreen((UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr) == (UFG::qNode<UFG::UIScreen,UFG::UIScreen> **)v3 )
  {
    v17 = UFG::UIHKScreenGlobalOverlay::mThis;
    if ( !UFG::UIHKScreenGlobalOverlay::mThis )
      v17 = &gGlobalOverlaySentinel;
    v18 = (signed __int64)&v17->HelpBar;
    *(_BYTE *)(v18 + 1) |= COERCE_FLOAT(COERCE_UNSIGNED_INT(v17->HelpBar.mYOffset - -20.0) & _xmm) > 0.001;
    *(_DWORD *)(v18 + 612) = -1046478848;
  }
  UFG::UIScreen::update((UFG::UIScreen *)&v3->vfptr, v2);
}

// File Line: 654
// RVA: 0x60E440
void __fastcall UFG::UIHKScreenGarageBrowser::ShowHelpBar(UFG::UIHKScreenGarageBrowser *this, UFG::UIHKScreenGarageBrowser::eHelpBarState eHelpState, bool isInfoTickerPopupVisible)
{
  UFG::UIHKScreenGarageBrowser *v3; // rsi
  UFG::UIHKScreenGarageBrowser::eHelpBarState v4; // eax
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
  UFG::UIHKHelpBarData data; // [rsp+30h] [rbp-C8h]

  v3 = this;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis || eHelpState == HELP_NONE )
    return;
  this->mHelpBarState = eHelpState;
  UFG::UIHKHelpBarData::UIHKHelpBarData(&data);
  data.id = UFG::qStringHash32("GARAGE", 0xFFFFFFFF);
  *(_QWORD *)&data.priority = 0i64;
  v4 = v3->mHelpBarState;
  if ( v4 == 1 )
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
    data.Buttons[v9] = 1;
    UFG::qString::Set(&data.Captions[v10], v7);
    UFG::qString::Set((UFG::qString *)((char *)&data.Captions[v10 + 5] + 32), &customWorldMapCaption);
    *(unsigned int *)((char *)&data.Icons[5].mStringHash32 + v9 * 4) = 0;
    goto LABEL_16;
  }
  if ( v4 != 4 )
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
  if ( v3->m_bBackbuttonEnabled )
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
    data.Buttons[v13] = 2;
    v14 = v11;
    UFG::qString::Set(&data.Captions[v14], "$COMMON_BACK_UPPERCASE");
    UFG::qString::Set((UFG::qString *)((char *)&data.Captions[v14 + 5] + 32), &customWorldMapCaption);
    *(unsigned int *)((char *)&data.Icons[5].mStringHash32 + v13 * 4) = 0;
  }
LABEL_22:
  if ( (v3->mHelpBarState - 2) & 0xFFFFFFFD )
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
    data.Buttons[v17] = 3;
    v18 = v15;
    UFG::qString::Set(&data.Captions[v18], "$GARAGE_CUSTOMIZE_PAINT");
    UFG::qString::Set((UFG::qString *)((char *)&data.Captions[v18 + 5] + 32), &customWorldMapCaption);
    *(unsigned int *)((char *)&data.Icons[5].mStringHash32 + v17 * 4) = 0;
  }
LABEL_28:
  if ( v3->mHelpBarState == 3 )
  {
    v19 = UFG::GameStatTracker::Instance();
    if ( (unsigned __int8)UFG::GameStatTracker::GetStat(v19, EnableValet) )
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
      data.Buttons[v22] = 4;
      v23 = v20;
      UFG::qString::Set(&data.Captions[v23], "$GARAGE_SET_VALET_UPPERCASE");
      UFG::qString::Set((UFG::qString *)((char *)&data.Captions[v23 + 5] + 32), &customWorldMapCaption);
      *(unsigned int *)((char *)&data.Icons[5].mStringHash32 + v22 * 4) = 0;
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
}tring::~qString);
  `eh vector destructor iterator(data.Captions, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qStrin

// File Line: 699
// RVA: 0x5D2F40
void __fastcall UFG::UIHKScreenGarageBrowser::AddVehicleOrderOverride(UFG::qSymbol *spawnInfo)
{
  __int64 v1; // rdi
  UFG::qSymbol *v2; // rsi
  unsigned int v3; // ebx
  unsigned int v4; // edx

  v1 = UFG::UIHKScreenGarageBrowser::mVehicleOrderOverride.size;
  v2 = spawnInfo;
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
  UFG::UIHKScreenGarageBrowser::mVehicleOrderOverride.p[v1] = (UFG::qSymbol)v2->mUID;
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
  UFG::UIHKScreenGarageBrowser *v1; // r15
  UFG::allocator::free_link *v2; // r14
  unsigned int v3; // edi
  unsigned int v4; // er12
  __int64 v5; // r13
  __int64 v6; // rbx
  __int64 v7; // rcx
  unsigned int v8; // esi
  unsigned int v9; // ebx
  unsigned __int64 v10; // rax
  UFG::allocator::free_link *v11; // rax
  UFG::allocator::free_link *v12; // r12
  UFG::allocator::free_link *v13; // rdx
  __int64 v14; // r8
  unsigned int v15; // esi
  unsigned int v16; // ebx
  unsigned int v17; // ecx
  Scaleform::GFx::Movie *v18; // rbx
  UFG::UIHKScreenGarageBrowser::eHelpBarState v19; // edx
  char ptr; // [rsp+48h] [rbp-51h]
  __int64 v21; // [rsp+58h] [rbp-41h]
  unsigned int v22; // [rsp+60h] [rbp-39h]
  __int64 v23; // [rsp+68h] [rbp-31h]
  Scaleform::GFx::Value value; // [rsp+78h] [rbp-21h]
  unsigned int itemIndexOut; // [rsp+100h] [rbp+67h]
  unsigned int v26; // [rsp+108h] [rbp+6Fh]
  __int64 v27; // [rsp+110h] [rbp+77h]
  Scaleform::GFx::Movie *v28; // [rsp+118h] [rbp+7Fh]

  v1 = this;
  if ( this->mState == 4 )
  {
    UFG::UIHKScreenGarageBrowser::ShowHelpBar(this, HELP_SELECT_ITEM_EMPTY, 0);
  }
  else if ( this->mStore )
  {
    v28 = this->mRenderable->m_movie.pObject;
    if ( v28 )
    {
      UFG::UIHKScreenGarageBrowser::ClearList(this);
      v2 = 0i64;
      v3 = 0;
      v4 = 0;
      if ( UFG::UIHKScreenGarageBrowser::mVehicleOrderOverride.size )
      {
        v5 = 0i64;
        v6 = UFG::UIHKScreenGarageBrowser::mVehicleOrderOverride.size;
        v27 = UFG::UIHKScreenGarageBrowser::mVehicleOrderOverride.size;
        do
        {
          if ( UFG::StoreFront::FindItemIndex(
                 v1->mStore,
                 &UFG::UIHKScreenGarageBrowser::mVehicleOrderOverride.p[v5],
                 &itemIndexOut) )
          {
            UFG::UIHKScreenGarageBrowser::AddItem(v1, itemIndexOut);
            v7 = v3;
            v26 = v3;
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
                v7 = v26;
              }
              v6 = v27;
            }
            ++v3;
            *((_DWORD *)&v2->mNext + v7) = itemIndexOut;
          }
          ++v5;
          v27 = --v6;
        }
        while ( v6 );
      }
      v15 = UFG::StoreFront::GetNumItems(v1->mStore);
      v1->mNumItems = 0;
      v16 = 0;
      if ( v15 )
      {
        do
        {
          v17 = 0;
          if ( !v3 )
            goto LABEL_35;
          while ( v16 != *((_DWORD *)&v2->mNext + v17) )
          {
            if ( ++v17 >= v3 )
              goto LABEL_35;
          }
          if ( v17 == -1 )
LABEL_35:
            UFG::UIHKScreenGarageBrowser::AddItem(v1, v16);
          ++v16;
        }
        while ( v16 < v15 );
      }
      `eh vector constructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      if ( v1->mNumItems )
      {
        if ( v1->mStore->mStoreType == 1 )
        {
          UFG::UIHKScreenGarageBrowser::ShowHelpBar(v1, HELP_SELECT_ITEM_STORE, 0);
          v18 = v28;
        }
        else
        {
          value.pObjectInterface = 0i64;
          value.Type = 2;
          value.mValue.BValue = 0;
          v18 = v28;
          Scaleform::GFx::Movie::SetVariable(v28, "mc_Money._visible", &value, 1i64);
          v19 = 2;
          if ( v1->mStore->mStoreType != 3 )
            v19 = 3;
          UFG::UIHKScreenGarageBrowser::ShowHelpBar(v1, v19, 0);
          if ( ((unsigned int)value.Type >> 6) & 1 )
          {
            (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
              value.pObjectInterface,
              &value,
              *(_QWORD *)&value.mValue.NValue);
            value.pObjectInterface = 0i64;
          }
          value.Type = 0;
        }
        UFG::UIHKScreenGarageBrowser::UpdateMoney(v1);
        v1->mSelectedIndex = 0;
        if ( (v22 >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v21 + 16i64))(v21, &ptr, v23);
          v21 = 0i64;
        }
        v22 = 5;
        v23 = 0i64;
        Scaleform::GFx::Movie::Invoke(v18, "gVehicleList.SetSelectedIndex", 0i64, (Scaleform::GFx::Value *)&ptr, 1u);
        Scaleform::GFx::Movie::Invoke(v18, "VehicleList_Refresh", 0i64, 0i64, 0);
      }
      else
      {
        v1->mState = 4;
        if ( (v22 >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v21 + 16i64))(v21, &ptr, v23);
          v21 = 0i64;
        }
        v22 = 2;
        LOBYTE(v23) = 1;
        Scaleform::GFx::Movie::Invoke(v28, "VehicleList_SetIsEmpty", 0i64, (Scaleform::GFx::Value *)&ptr, 1u);
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
  Scaleform::GFx::Movie *v1; // rsi
  UFG::GameStatTracker *v2; // rax
  int v3; // ebx
  UFG::GameStatTracker *v4; // rax
  signed int v5; // er14
  char *v6; // rdi
  char ptr; // [rsp+18h] [rbp-79h]
  void (__fastcall *pDtor)(void *); // [rsp+20h] [rbp-71h]
  __int64 v9; // [rsp+28h] [rbp-69h]
  unsigned int v10; // [rsp+30h] [rbp-61h]
  char *v11; // [rsp+38h] [rbp-59h]
  char v12; // [rsp+48h] [rbp-49h]
  __int64 v13; // [rsp+58h] [rbp-39h]
  unsigned int v14; // [rsp+60h] [rbp-31h]
  double v15; // [rsp+68h] [rbp-29h]
  char v16; // [rsp+78h] [rbp-19h]
  __int64 v17; // [rsp+88h] [rbp-9h]
  unsigned int v18; // [rsp+90h] [rbp-1h]
  double v19; // [rsp+98h] [rbp+7h]
  __int64 v20; // [rsp+A8h] [rbp+17h]
  UFG::qString string; // [rsp+B0h] [rbp+1Fh]

  v20 = -2i64;
  v1 = this->mRenderable->m_movie.pObject;
  v2 = UFG::GameStatTracker::Instance();
  v3 = UFG::GameStatTracker::GetStat(v2, Money);
  v4 = UFG::GameStatTracker::Instance();
  v5 = UFG::GameStatTracker::GetFaceLevel(v4);
  UFG::qString::qString(&string);
  UFG::UI::FormatMoneyStr(v3, &string);
  pDtor = (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value;
  `eh vector constructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  v6 = string.mData;
  if ( (v10 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v9 + 16i64))(v9, &ptr, v11);
    v9 = 0i64;
  }
  v10 = 6;
  v11 = v6;
  if ( (v14 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v13 + 16i64))(
      v13,
      &v12,
      COERCE_DOUBLE(*(_QWORD *)&v15));
    v13 = 0i64;
  }
  v14 = 5;
  v15 = (double)v3;
  if ( (v18 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v17 + 16i64))(
      v17,
      &v16,
      COERCE_DOUBLE(*(_QWORD *)&v19));
    v17 = 0i64;
  }
  v18 = 5;
  v19 = (double)v5;
  Scaleform::GFx::Movie::Invoke(v1, "VehicleList_SetCurrentMoney", 0i64, (Scaleform::GFx::Value *)&ptr, 3u);
  `eh vector destructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  UFG::qString::~qString(&string);
}

// File Line: 807
// RVA: 0x5D1FA0
void __fastcall UFG::UIHKScreenGarageBrowser::AddItem(UFG::UIHKScreenGarageBrowser *this, unsigned int storeItemIdx)
{
  int v2; // esi
  UFG::UIHKScreenGarageBrowser *v3; // r14
  UFG::qPropertySet *v4; // rbx
  UFG::qSymbol *v5; // rax
  char *v6; // rax
  char *v7; // rax
  char *v8; // rax
  unsigned int *v9; // rax
  UFG::UIHKGarageVehicleInfo **v10; // rcx
  unsigned int v11; // esi
  UFG::GameStatTracker *v12; // rax
  unsigned int v13; // eax
  unsigned int v14; // eax
  UFG::UIGfxTranslator *v15; // rcx
  const char *v16; // rax
  unsigned int v17; // eax
  UFG::UIGfxTranslator *v18; // rcx
  const char *v19; // rax
  char *v20; // rax
  const char *v21; // rdi
  char *v22; // rax
  const char *v23; // rax
  const char *v24; // rbx
  UFG::GameStatTracker *v25; // rax
  UFG::PersistentData::ID *v26; // rax
  char v27; // cl
  UFG::UIHKGarageVehicleInfo *v28; // rax
  UFG::UIHKGarageVehicleInfo *v29; // rax
  UFG::UIHKGarageVehicleInfo __that; // [rsp+20h] [rbp-C8h]
  __int64 v31; // [rsp+138h] [rbp+50h]
  UFG::UIHKGarageVehicleInfo v32; // [rsp+148h] [rbp+60h]
  UFG::UIHKGarageVehicleInfo *v33; // [rsp+278h] [rbp+190h]

  *(_QWORD *)&__that.price = -2i64;
  v2 = storeItemIdx;
  v3 = this;
  v4 = UFG::StoreFront::GetItem(this->mStore, storeItemIdx);
  if ( v4 )
  {
    __that.spawnObjectInfo.mUID = -1;
    UFG::qString::qString(&__that.title);
    UFG::qString::qString(&__that.description);
    UFG::qString::qString(&__that.discountPercentStr);
    UFG::qString::qString((UFG::qString *)((char *)&__that.discountPercentStr + 16));
    UFG::qString::qString((UFG::qString *)((char *)&__that.texture + 16));
    UFG::qString::qString((UFG::qString *)((char *)&__that.brandTexture + 16));
    *(_QWORD *)&__that.tier.mMagic = 0i64;
    __that.tier.mData = 0i64;
    __that.tier.mStringHash32 = 0;
    LOWORD(__that.tier.mStringHashUpper32) = 0;
    BYTE2(__that.tier.mStringHashUpper32) = 0;
    HIDWORD(__that.tier.mData) = v2;
    LOBYTE(__that.tier.mStringHashUpper32) = UFG::StoreFront::IsOwned(v3->mStore, v2);
    v5 = UFG::qPropertySet::Get<UFG::qSymbol>(
           v4,
           (UFG::qSymbol *)&UFG::StoreItemSymbol_SpawnObjectInfo.mUID,
           DEPTH_RECURSE);
    if ( v5 )
      __that.spawnObjectInfo = (UFG::qSymbol)v5->mUID;
    v6 = UFG::qPropertySet::Get<char const *>(v4, (UFG::qSymbol *)&UFG::StoreItemSymbol_Title.mUID, DEPTH_RECURSE);
    if ( v6 )
      UFG::qString::Set(&__that.title, v6);
    v7 = UFG::qPropertySet::Get<char const *>(v4, (UFG::qSymbol *)&UFG::StoreItemSymbol_Description.mUID, DEPTH_RECURSE);
    if ( v7 )
      UFG::qString::Set(&__that.description, v7);
    v8 = UFG::qPropertySet::Get<char const *>(v4, (UFG::qSymbol *)&UFG::StoreItemSymbol_Texture.mUID, DEPTH_RECURSE);
    if ( v8 )
      UFG::qString::Set((UFG::qString *)((char *)&__that.discountPercentStr + 16), v8);
    __that.tier.mMagic = (signed int)UFG::StoreFrontTracker::GetItemPriceWithoutDiscount(v4);
    __that.tier.mLength = (signed int)UFG::StoreFrontTracker::GetItemPriceBasedOnClothes(v4);
    __that.tier.mStringHash32 = (signed int)UFG::StoreFrontTracker::GetDiscount();
    LODWORD(v33) = 0;
    v9 = UFG::qPropertySet::Get<unsigned long>(
           v4,
           (UFG::qSymbol *)&UFG::StoreItemSymbol_FaceRequired.mUID,
           DEPTH_RECURSE);
    v10 = &v33;
    if ( v9 )
      v10 = (UFG::UIHKGarageVehicleInfo **)v9;
    v11 = *(_DWORD *)v10;
    v12 = UFG::GameStatTracker::Instance();
    v13 = UFG::GameStatTracker::GetFaceLevel(v12);
    BYTE2(__that.tier.mStringHashUpper32) = v11 <= v13;
    if ( v11 > v13 )
    {
      v17 = UFG::qStringHashUpper32("WARDROBE_FACE_LEVEL", 0xFFFFFFFF);
      v18 = UFG::UIScreenManager::s_instance->m_translator;
      if ( !v18
        || (v19 = (const char *)v18->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v18->vfptr, v17)) == 0i64 )
      {
        v19 = "WARDROBE_FACE_LEVEL";
      }
      UFG::qString::Format(&__that.discountPercentStr, v19, v11);
    }
    else if ( __that.tier.mStringHash32 )
    {
      UFG::qString::qString((UFG::qString *)&__that.faceValue);
      UFG::qString::Format((UFG::qString *)&__that.faceValue, "%d", __that.tier.mStringHash32);
      v14 = UFG::qStringHashUpper32("WARDROBE_DISCOUNT_PERCENT", 0xFFFFFFFF);
      v15 = UFG::UIScreenManager::s_instance->m_translator;
      if ( !v15
        || (v16 = (const char *)v15->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v15->vfptr, v14)) == 0i64 )
      {
        v16 = "WARDROBE_DISCOUNT_PERCENT";
      }
      UFG::qString::Format(&__that.discountPercentStr, v16, v31);
      UFG::qString::~qString((UFG::qString *)&__that.faceValue);
    }
    v20 = PropertyUtils::Get<char const *>(v4, (UFG::qSymbol *)&UFG::StoreItemSymbol_Brand.mUID, DEPTH_RECURSE);
    v21 = v20;
    if ( v20 && (signed int)UFG::qStringLength(v20) > 0 )
      UFG::qString::Set((UFG::qString *)((char *)&__that.texture + 16), v21);
    v22 = PropertyUtils::Get<char const *>(v4, (UFG::qSymbol *)&UFG::StoreItemSymbol_Tier.mUID, DEPTH_RECURSE);
    v23 = UFG::UIHKScreenGarageBrowser::GetVehicleTierString(v3, v22);
    v24 = v23;
    if ( v23 && (signed int)UFG::qStringLength(v23) > 0 )
      UFG::qString::Set((UFG::qString *)((char *)&__that.brandTexture + 16), v24);
    v25 = UFG::GameStatTracker::Instance();
    v26 = UFG::GameStatTracker::GetStat(v25, ValetVehicle);
    v27 = BYTE1(__that.tier.mStringHashUpper32);
    if ( v26->mValue.mUID == __that.spawnObjectInfo.mUID )
      v27 = 1;
    BYTE1(__that.tier.mStringHashUpper32) = v27;
    ++v3->mNumItems;
    v33 = &v32;
    UFG::UIHKGarageVehicleInfo::UIHKGarageVehicleInfo(&v32, &__that);
    UFG::UIHKScreenGarageBrowser::Flash_AddItem(v3, v28);
    v33 = &v32;
    UFG::UIHKGarageVehicleInfo::UIHKGarageVehicleInfo(&v32, &__that);
    UFG::UIHKScreenGarageBrowser::AddToList(v3, v29);
    UFG::qString::~qString((UFG::qString *)((char *)&__that.brandTexture + 16));
    UFG::qString::~qString((UFG::qString *)((char *)&__that.texture + 16));
    UFG::qString::~qString((UFG::qString *)((char *)&__that.discountPercentStr + 16));
    UFG::qString::~qString(&__that.discountPercentStr);
    UFG::qString::~qString(&__that.description);
    UFG::qString::~qString(&__that.title);
  }
}

// File Line: 904
// RVA: 0x5D9400
void __fastcall UFG::UIHKScreenGarageBrowser::Flash_AddItem(UFG::UIHKScreenGarageBrowser *this, UFG::UIHKGarageVehicleInfo *info)
{
  UFG::UIHKGarageVehicleInfo *v2; // rbx
  UFG::UIHKScreenGarageBrowser *v3; // rsi
  double v4; // xmm6_8
  __int64 v5; // rdi
  __int64 v6; // rdi
  __int64 v7; // rdi
  double v8; // xmm6_8
  double v9; // xmm6_8
  double v10; // xmm6_8
  __int64 v11; // rdi
  __int64 v12; // rdi
  bool v13; // di
  bool v14; // di
  __int64 v15; // rdi
  bool v16; // di
  char ptr; // [rsp+30h] [rbp-B8h]
  __int64 v18; // [rsp+40h] [rbp-A8h]
  unsigned int v19; // [rsp+48h] [rbp-A0h]
  double v20; // [rsp+50h] [rbp-98h]
  char v21; // [rsp+60h] [rbp-88h]
  __int64 v22; // [rsp+68h] [rbp-80h]
  __int64 v23; // [rsp+70h] [rbp-78h]
  unsigned int v24; // [rsp+78h] [rbp-70h]
  __int64 v25; // [rsp+88h] [rbp-60h]
  unsigned int v26; // [rsp+90h] [rbp-58h]
  __int64 v27; // [rsp+98h] [rbp-50h]
  char v28; // [rsp+A8h] [rbp-40h]
  __int64 v29; // [rsp+B8h] [rbp-30h]
  unsigned int v30; // [rsp+C0h] [rbp-28h]
  __int64 v31; // [rsp+C8h] [rbp-20h]
  char v32; // [rsp+D8h] [rbp-10h]
  __int64 v33; // [rsp+E8h] [rbp+0h]
  unsigned int v34; // [rsp+F0h] [rbp+8h]
  double v35; // [rsp+F8h] [rbp+10h]
  char v36; // [rsp+108h] [rbp+20h]
  __int64 v37; // [rsp+118h] [rbp+30h]
  unsigned int v38; // [rsp+120h] [rbp+38h]
  double v39; // [rsp+128h] [rbp+40h]
  char v40; // [rsp+138h] [rbp+50h]
  __int64 v41; // [rsp+148h] [rbp+60h]
  unsigned int v42; // [rsp+150h] [rbp+68h]
  double v43; // [rsp+158h] [rbp+70h]
  char v44; // [rsp+168h] [rbp+80h]
  __int64 v45; // [rsp+178h] [rbp+90h]
  unsigned int v46; // [rsp+180h] [rbp+98h]
  __int64 v47; // [rsp+188h] [rbp+A0h]
  char v48; // [rsp+198h] [rbp+B0h]
  __int64 v49; // [rsp+1A8h] [rbp+C0h]
  unsigned int v50; // [rsp+1B0h] [rbp+C8h]
  __int64 v51; // [rsp+1B8h] [rbp+D0h]
  char v52; // [rsp+1C8h] [rbp+E0h]
  __int64 v53; // [rsp+1D8h] [rbp+F0h]
  unsigned int v54; // [rsp+1E0h] [rbp+F8h]
  __int64 v55; // [rsp+1E8h] [rbp+100h]
  char v56; // [rsp+1F8h] [rbp+110h]
  __int64 v57; // [rsp+208h] [rbp+120h]
  unsigned int v58; // [rsp+210h] [rbp+128h]
  __int64 v59; // [rsp+218h] [rbp+130h]
  char v60; // [rsp+228h] [rbp+140h]
  __int64 v61; // [rsp+238h] [rbp+150h]
  unsigned int v62; // [rsp+240h] [rbp+158h]
  __int64 v63; // [rsp+248h] [rbp+160h]
  char v64; // [rsp+258h] [rbp+170h]
  __int64 v65; // [rsp+268h] [rbp+180h]
  unsigned int v66; // [rsp+270h] [rbp+188h]
  __int64 v67; // [rsp+278h] [rbp+190h]
  __int64 v68; // [rsp+288h] [rbp+1A0h]

  v68 = -2i64;
  v2 = info;
  v3 = this;
  `eh vector constructor iterator(&ptr, 0x30ui64, 13, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  v4 = (double)(signed int)v2->storeIndex;
  if ( (v19 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v18 + 16i64))(
      v18,
      &ptr,
      COERCE_DOUBLE(*(_QWORD *)&v20));
    v18 = 0i64;
  }
  v19 = 5;
  v20 = v4;
  v5 = (__int64)v2->title.mData;
  if ( (v24 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v23 + 16i64))(v23, &v21, v22);
    v23 = 0i64;
  }
  v24 = 6;
  v22 = v5;
  v6 = (__int64)v2->description.mData;
  if ( (v26 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, unsigned int *, __int64))(*(_QWORD *)v25 + 16i64))(v25, &v24, v27);
    v25 = 0i64;
  }
  v26 = 6;
  v27 = v6;
  v7 = (__int64)v2->texture.mData;
  if ( (v30 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v29 + 16i64))(v29, &v28, v31);
    v29 = 0i64;
  }
  v30 = 6;
  v31 = v7;
  v8 = (double)(signed int)v2->price;
  if ( (v34 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v33 + 16i64))(
      v33,
      &v32,
      COERCE_DOUBLE(*(_QWORD *)&v35));
    v33 = 0i64;
  }
  v34 = 5;
  v35 = v8;
  v9 = (double)(signed int)v2->discountPrice;
  if ( (v38 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v37 + 16i64))(
      v37,
      &v36,
      COERCE_DOUBLE(*(_QWORD *)&v39));
    v37 = 0i64;
  }
  v38 = 5;
  v39 = v9;
  v10 = (double)(signed int)v2->discountPercent;
  if ( (v42 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v41 + 16i64))(
      v41,
      &v40,
      COERCE_DOUBLE(*(_QWORD *)&v43));
    v41 = 0i64;
  }
  v42 = 5;
  v43 = v10;
  v11 = (__int64)v2->discountPercentStr.mData;
  if ( (v46 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v45 + 16i64))(v45, &v44, v47);
    v45 = 0i64;
  }
  v46 = 6;
  v47 = v11;
  v12 = (__int64)v2->tier.mData;
  if ( (v50 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v49 + 16i64))(v49, &v48, v51);
    v49 = 0i64;
  }
  v50 = 6;
  v51 = v12;
  v13 = v2->bOwned;
  if ( (v54 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v53 + 16i64))(v53, &v52, v55);
    v53 = 0i64;
  }
  v54 = 2;
  LOBYTE(v55) = v13;
  v14 = v2->bValetVehicle;
  if ( (v58 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v57 + 16i64))(v57, &v56, v59);
    v57 = 0i64;
  }
  v58 = 2;
  LOBYTE(v59) = v14;
  v15 = (__int64)v2->brandTexture.mData;
  if ( (v62 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v61 + 16i64))(v61, &v60, v63);
    v61 = 0i64;
  }
  v62 = 6;
  v63 = v15;
  v16 = v2->playerHasEnoughFace;
  if ( (v66 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v65 + 16i64))(v65, &v64, v67);
    v65 = 0i64;
  }
  v66 = 2;
  LOBYTE(v67) = v16;
  Scaleform::GFx::Movie::Invoke(
    v3->mRenderable->m_movie.pObject,
    "VehicleList_AddItem",
    0i64,
    (Scaleform::GFx::Value *)&ptr,
    0xDu);
  `eh vector destructor iterator(&ptr, 0x30ui64, 13, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  UFG::qString::~qString(&v2->tier);
  UFG::qString::~qString(&v2->brandTexture);
  UFG::qString::~qString(&v2->texture);
  UFG::qString::~qString(&v2->discountPercentStr);
  UFG::qString::~qString(&v2->description);
  UFG::qString::~qString(&v2->title);
}

// File Line: 928
// RVA: 0x5D2DF0
void __fastcall UFG::UIHKScreenGarageBrowser::AddToList(UFG::UIHKScreenGarageBrowser *this, UFG::UIHKGarageVehicleInfo *vehicle)
{
  UFG::UIHKGarageVehicleInfo *v2; // rdi
  UFG::qArray<UFG::UIHKGarageVehicleInfo,0> *v3; // rsi
  __int64 v4; // rbp
  unsigned int v5; // ebx
  unsigned int v6; // edx
  unsigned int v7; // edx

  v2 = vehicle;
  v3 = &this->mVehicleList;
  v4 = this->mVehicleList.size;
  v5 = v4 + 1;
  v6 = this->mVehicleList.capacity;
  if ( (signed int)v4 + 1 > v6 )
  {
    if ( v6 )
      v7 = 2 * v6;
    else
      v7 = 1;
    for ( ; v7 < v5; v7 *= 2 )
      ;
    if ( v7 - v5 > 0x10000 )
      v7 = v4 + 65537;
    UFG::qArray<UFG::UIHKGarageVehicleInfo,0>::Reallocate(&this->mVehicleList, v7, "qArray.Add");
  }
  v3->size = v5;
  UFG::UIHKGarageVehicleInfo::operator=(&v3->p[v4], v2);
  UFG::qString::~qString(&v2->tier);
  UFG::qString::~qString(&v2->brandTexture);
  UFG::qString::~qString(&v2->texture);
  UFG::qString::~qString(&v2->discountPercentStr);
  UFG::qString::~qString(&v2->description);
  UFG::qString::~qString(&v2->title);
}

// File Line: 934
// RVA: 0x6235D0
bool __usercall UFG::UIHKScreenGarageBrowser::handleMessage@<al>(UFG::UIHKScreenGarageBrowser *this@<rcx>, unsigned int msgId@<edx>, UFG::UIMessage *msg@<r8>, float *a4@<r13>)
{
  UFG::UIMessage *v4; // r14
  unsigned int v5; // ebx
  UFG::UIHKScreenGarageBrowser *v6; // rdi
  Scaleform::GFx::Movie *v7; // rbp
  int v9; // eax
  UFG::UIHKScreenGarageBrowser::eState v10; // edx
  char v11; // al
  char v12; // cl
  UFG::allocator::free_link *v13; // rax
  UFG::Event *v14; // rax
  UFG::Event *v15; // rsi
  UFG::allocator::free_link *v16; // rax
  UFG::Event *v17; // rax
  UFG::Event *v18; // rsi

  v4 = msg;
  v5 = msgId;
  v6 = this;
  v7 = this->mRenderable->m_movie.pObject;
  if ( msgId == UI_HASH_INTRO_COMPLETE_30 )
    return UFG::UIScreen::handleMessage((UFG::UIScreen *)&this->vfptr, msgId, msg);
  if ( msgId == UI_HASH_GAME_OVER_20 )
  {
    UFG::UIScreenManagerBase::queuePopScreen(
      (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
      this->mScreenUID);
  }
  else if ( msgId == UI_HASH_OPTION_HIGHLIGHTED_30 )
  {
    if ( this->mState == 4 )
      return 0;
    v9 = UFG::UIHKScreenGarageBrowser::GetSelectedIndex(this);
    v6->mSelectedIndex = v9;
    v6->mCurrentVehicle = &v6->mVehicleList.p[v9];
    UFG::UIHKScreenGarageBrowser::LoadTexturePack(v6);
  }
  v10 = v6->mState;
  if ( v6->mState == 2 )
    goto LABEL_64;
  if ( v6->mState == 6 )
  {
    if ( v5 == UI_HASH_DIALOG_OK_30 )
    {
      v6->mState = 1;
      return 1;
    }
    goto LABEL_64;
  }
  if ( v6->mState != 7 )
  {
    if ( v6->mState != 8 )
    {
      if ( !(UFG::UIHK_NISOverlay::m_curtains.m_state & 0xFFFFFFFD) )
      {
        if ( v5 == UI_HASH_BUTTON_ACCEPT_PRESSED_30 )
        {
          if ( v10 != 4 )
          {
            v11 = UFG::UIHKScreenGarageBrowser::HandleVehicleSelected(v6);
            v12 = UFG::UIHKScreenGarageBrowser::mSkipCustomization;
            if ( v11 )
              v12 = 1;
            UFG::UIHKScreenGarageBrowser::mSkipCustomization = v12;
            return 1;
          }
          return 0;
        }
        if ( v5 == UI_HASH_BUTTON_BUTTON1_PRESSED_30 )
        {
          if ( v10 != 4 )
          {
            UFG::UIHKScreenGarageBrowser::HandleVehicleSelected(v6);
            return 1;
          }
          return 0;
        }
        if ( v5 == UI_HASH_DIALOG_YES_30 )
        {
          v13 = UFG::qMalloc(0x38ui64, "UIGarageScreenDeferredTaskChannel", 0i64);
          if ( v13 )
          {
            UFG::Event::Event((UFG::Event *)v13, UFG::gUIGarageScreenDeferredTaskChannel.mName);
            v15 = v14;
          }
          else
          {
            v15 = 0i64;
          }
          v15->mUserData0 = 1i64;
          UFG::EventDispatcher::QueueEvent(&UFG::EventDispatcher::mInstance, v15);
          UFG::VendorDialogueUtils::sm_moneySpent = UFG::VendorDialogueUtils::sm_moneySpent + 10000.0;
        }
        else if ( v5 != UI_HASH_DIALOG_NO_30 && v5 != UI_HASH_DIALOG_OK_30 )
        {
          if ( v5 == UI_HASH_DPAD_DOWN_PRESSED_30 || v5 == UI_HASH_THUMBSTICK_LEFT_DOWN_30 )
          {
            Scaleform::GFx::Movie::Invoke(v7, "VehicleList_ScrollNext", 0i64, 0i64, 0);
            UFG::VendorDialogueUtils::sm_playBrowse = 1;
            UFG::VendorDialogueUtils::sm_idleTime = 0.0;
            if ( v6->mNumItems > 1 && UFG::HudAudio::m_instance )
              UFG::AudioEntity::CreateAndPlayEvent(
                (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
                0xB78DCE8u,
                0i64,
                0,
                0i64);
          }
          else if ( v5 == UI_HASH_DPAD_UP_PRESSED_30 || v5 == UI_HASH_THUMBSTICK_LEFT_UP_30 )
          {
            Scaleform::GFx::Movie::Invoke(v7, "VehicleList_ScrollPrev", 0i64, 0i64, 0);
            UFG::VendorDialogueUtils::sm_playBrowse = 1;
            UFG::VendorDialogueUtils::sm_idleTime = 0.0;
            if ( v6->mNumItems > 1 && UFG::HudAudio::m_instance )
              UFG::AudioEntity::CreateAndPlayEvent(
                (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
                0x593B70ABu,
                0i64,
                0,
                0i64);
          }
          else if ( v5 == (_DWORD)UI_HASH_BUTTON_BUTTON2_PRESSED_30 )
          {
            UFG::UIHKScreenGarageBrowser::SetAsValet(v6);
          }
          else if ( v5 == UI_HASH_BUTTON_BACK_PRESSED_30 )
          {
            if ( v6->m_bBackbuttonEnabled )
            {
              UFG::UIHKScreenGarageBrowser::mPlayerBackedOut = 1;
              if ( UFG::HudAudio::m_instance )
                UFG::AudioEntity::CreateAndPlayEvent(
                  (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
                  0xA4E5BFBD,
                  0i64,
                  0,
                  0i64);
              UFG::UIHKScreenGarageBrowser::Exit(v6);
            }
          }
          else if ( v5 == UI_HASH_BUTTON_SELECT_PRESSED_30 )
          {
            if ( !v6->mIsRestricted )
              UFG::UIHKScreenGarageBrowser::ToggleTickerPopup(v6);
          }
          else if ( v10 == 5 && v5 == UI_HASH_PARKADE_OPEN_20 )
          {
            UFG::UIHKScreenGarageBrowser::Exit(v6);
          }
        }
        else
        {
          UFG::UIHKScreenGarageBrowser::mSkipCustomization = 0;
        }
      }
      goto LABEL_64;
    }
    if ( v5 == UI_HASH_SCREEN_FADE_IN_COMPLETE_12 )
    {
      v16 = UFG::qMalloc(0x38ui64, "UIGarageScreenDeferredTaskChannel", 0i64);
      if ( v16 )
      {
        UFG::Event::Event((UFG::Event *)v16, UFG::gUIGarageScreenDeferredTaskChannel.mName);
        v18 = v17;
      }
      else
      {
        v18 = 0i64;
      }
      v18->mUserData0 = 2i64;
      UFG::EventDispatcher::QueueEvent(&UFG::EventDispatcher::mInstance, v18);
      return 1;
    }
LABEL_64:
    msg = v4;
    msgId = v5;
    this = v6;
    return UFG::UIScreen::handleMessage((UFG::UIScreen *)&this->vfptr, msgId, msg);
  }
  if ( v5 != UI_HASH_SCREEN_FADE_IN_COMPLETE_12 )
    goto LABEL_64;
  if ( UFG::HudAudio::m_instance )
  {
    UFG::AudioEntity::CreateAndPlayEvent(
      (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
      0xEDABFAC7,
      0i64,
      0,
      0i64);
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        0xC59A6DDC,
        0i64,
        0,
        0i64);
  }
  UFG::UIHKScreenGarageBrowser::AfterFadeToBlackInit(v6, a4);
  return 1;
}

// File Line: 1120
// RVA: 0x5D7820
void __fastcall UFG::UIHKScreenGarageBrowser::Exit(UFG::UIHKScreenGarageBrowser *this)
{
  UFG::UIHKScreenGarageBrowser *v1; // rbx

  v1 = this;
  UFG::UIScreen::invoke((UFG::UIScreen *)&this->vfptr, "Animate_Outro");
  v1->mState = 8;
  if ( UFG::UIHKScreenGlobalOverlay::mThis
    && UFG::UIHKScreenGlobalOverlay::mThis != (UFG::UIHKScreenGlobalOverlay *)-408i64 )
  {
    UFG::UIHK_NISOverlay::ShowElement(
      &UFG::UIHKScreenGlobalOverlay::mThis->NISOverlay,
      (UFG::UIScreen *)&UFG::UIHKScreenGlobalOverlay::mThis->vfptr,
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
  UFG::UIHKScreenGarageBrowser *v1; // rbx
  UFG::SimObjectVehicle *v2; // rdx
  UFG::SimObject *v3; // rcx
  UFG::ScriptCameraComponent *v4; // rax
  UFG::UIHKHelpBarWidget *v5; // rbx
  unsigned int v6; // eax

  v1 = this;
  UFG::VendorDialogueUtils::PlayStoreClerkDialogue(eStoreClerkDialogueContext_Exit, 1.0);
  if ( v1->m_bFadeOutAndTeleportPlayer )
  {
    v2 = v1->m_pSimObjVehicle;
    if ( v2 )
      UFG::VehicleUtility::PlaceCharacterInVehicle(LocalPlayer, v2, eTARGET_TYPE_VEHICLE_DRIVER, 0, 0, 1);
  }
  ((void (__fastcall *)(UFG::TiDo *, signed __int64))UFG::TiDo::m_pInstance->vfptr[1].Close)(
    UFG::TiDo::m_pInstance,
    4i64);
  v3 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( v3 )
  {
    v4 = (UFG::ScriptCameraComponent *)UFG::SimObject::GetComponentOfType(v3, UFG::ScriptCameraComponent::_TypeUID);
    if ( v4 )
      UFG::ScriptCameraComponent::ReleaseCamera(v4, 0);
  }
  v1->mFinished = 1;
  if ( UFG::UIHKScreenGlobalOverlay::mThis )
  {
    v5 = &UFG::UIHKScreenGlobalOverlay::mThis->HelpBar;
    v6 = UFG::qStringHash32("GARAGE", 0xFFFFFFFF);
    UFG::UIHKHelpBarWidget::Hide(v5, v6);
    if ( UFG::UIHKScreenGlobalOverlay::mThis )
    {
      if ( UFG::UIHKScreenGlobalOverlay::mThis != (UFG::UIHKScreenGlobalOverlay *)-408i64 )
        UFG::UIHK_NISOverlay::HideElement(
          &UFG::UIHKScreenGlobalOverlay::mThis->NISOverlay,
          (UFG::UIScreen *)&UFG::UIHKScreenGlobalOverlay::mThis->vfptr,
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
  Scaleform::GFx::Movie *v1; // rcx
  unsigned int v3; // ebx
  Scaleform::GFx::Value pval; // [rsp+28h] [rbp-40h]

  v1 = this->mRenderable->m_movie.pObject;
  if ( !v1 )
    return 0i64;
  pval.pObjectInterface = 0i64;
  pval.Type = 0;
  Scaleform::GFx::Movie::GetVariable(v1, &pval, "SelectedIndex");
  v3 = (signed int)pval.mValue.NValue;
  if ( ((unsigned int)pval.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pval.pObjectInterface->vfptr->gap8[8])(
      pval.pObjectInterface,
      &pval,
      *(_QWORD *)&pval.mValue.NValue);
    pval.pObjectInterface = 0i64;
  }
  return v3;
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
  UFG::UIHKScreenGarageBrowser *v1; // rdi
  UFG::UIHKGarageVehicleInfo *v2; // rcx
  unsigned int *v3; // rbx

  v1 = this;
  Scaleform::GFx::Movie::Invoke(this->mRenderable->m_movie.pObject, "VehicleList_Clear", 0i64, 0i64, 0);
  v2 = v1->mVehicleList.p;
  if ( v2 )
  {
    v3 = &v2[-1].discountPercent;
    `eh vector destructor iterator(
      v2,
      0x110ui64,
      v2[-1].discountPercent,
      (void (__fastcall *)(void *))UFG::UIHKGarageVehicleInfo::~UIHKGarageVehicleInfo);
    operator delete[](v3);
  }
  v1->mVehicleList.p = 0i64;
  *(_QWORD *)&v1->mVehicleList.size = 0i64;
}

// File Line: 1198
// RVA: 0x5E9AF0
const char *__fastcall UFG::UIHKScreenGarageBrowser::GetVehicleTierString(UFG::UIHKScreenGarageBrowser *this, const char *tierId)
{
  const char *v2; // rbx
  const char *result; // rax

  v2 = tierId;
  if ( !tierId )
    goto LABEL_15;
  if ( !(unsigned int)UFG::qStringCompare(tierId, "Class A", -1) )
    return "$VEHICLE_TIER_CLASSA";
  if ( !(unsigned int)UFG::qStringCompare(v2, "Class B", -1) )
    return "$VEHICLE_TIER_CLASSB";
  if ( !(unsigned int)UFG::qStringCompare(v2, "Class C", -1) )
    return "$VEHICLE_TIER_CLASSC";
  if ( !(unsigned int)UFG::qStringCompare(v2, "Class D", -1) )
    return "$VEHICLE_TIER_CLASSD";
  if ( (unsigned int)UFG::qStringCompare(v2, "Class E", -1) )
LABEL_15:
    result = 0i64;
  else
    result = "$VEHICLE_TIER_CLASSE";
  return result;
}

// File Line: 1226
// RVA: 0x5F2290
void __fastcall UFG::UIHKScreenGarageBrowser::NetworkSignedIn(UFG::UIHKScreenGarageBrowser *this, hkgpIndexedMeshDefinitions::Edge *a2)
{
  UFG::UIHKScreenGarageBrowser *v2; // rdi
  __int64 v3; // rax
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h]

  v2 = this;
  v3 = *(_QWORD *)&this[-1].m_iTextureHandleIndex;
  if ( v3 && *(_QWORD *)(v3 + 320) && Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(0i64, a2) )
  {
    BYTE1(v2->mCarTextures[0].mMagic) = 1;
    HIBYTE(v2->mCarTextures[0].mNext) = 0;
    UFG::UIHKScreenGarageBrowser::ShowTickerPopup((UFG::UIHKScreenGarageBrowser *)((char *)v2 - 152), 0);
    UFG::UIHKScreenGarageBrowser::ShowHelpBar(
      (UFG::UIHKScreenGarageBrowser *)((char *)v2 - 152),
      *(UFG::UIHKScreenGarageBrowser::eHelpBarState *)v2->m_screenName,
      HIBYTE(v2->mCarTextures[0].mNext));
    pargs.pObjectInterface = 0i64;
    pargs.Type = 6;
    *(_QWORD *)&pargs.mValue.NValue = &customWorldMapCaption;
    Scaleform::GFx::Movie::Invoke(
      *(Scaleform::GFx::Movie **)(*(_QWORD *)&v2[-1].m_iTextureHandleIndex + 320i64),
      "SetTickerText",
      0i64,
      &pargs,
      1u);
    if ( ((unsigned int)pargs.Type >> 6) & 1 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        *(_QWORD *)&pargs.mValue.NValue);
  }
}

