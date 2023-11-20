// File Line: 85
// RVA: 0x156CE30
__int64 UFG::_dynamic_initializer_for__UI_HASH_PURCHASE_ITEM__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("PURCHASE_ITEM", 0xFFFFFFFF);
  UI_HASH_PURCHASE_ITEM = result;
  return result;
}

// File Line: 86
// RVA: 0x156CE10
__int64 UFG::_dynamic_initializer_for__UI_HASH_PURCHASE_AND_EQUIP_ITEM__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("PURCHASE_AND_EQUIP_ITEM", 0xFFFFFFFF);
  UI_HASH_PURCHASE_AND_EQUIP_ITEM = result;
  return result;
}

// File Line: 97
// RVA: 0x156E0A0
__int64 UFG::_dynamic_initializer_for__gUIWardrobeScreenDeferredTaskChannel__()
{
  UFG::ChannelObj::ChannelObj(&UFG::gUIWardrobeScreenDeferredTaskChannel, "EVT_UI_WARDROBE_DEFERRED_TASK_CHANNEL", 0i64);
  return atexit(UFG::_dynamic_atexit_destructor_for__gUIWardrobeScreenDeferredTaskChannel__);
}

// File Line: 121
// RVA: 0x5C7A10
void __fastcall UFG::UIHKScreenWardrobe::UIHKScreenWardrobe(UFG::UIHKScreenWardrobe *this)
{
  UFG::UIHKScreenWardrobe *v1; // rbx
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v2; // rax
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *v3; // rax
  hkSeekableStreamReader *v4; // [rsp+38h] [rbp-20h]
  void (__fastcall *v5)(UFG::UIHKScreenWardrobe *, UFG::Event *); // [rsp+40h] [rbp-18h]
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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenWardrobe::`vftable{for `UFG::UIHKTaskableScreen};
  v6->vfptr = (UFG::OnlineManagerObserverVtbl *)&UFG::UIHKScreenWardrobe::`vftable{for `UFG::OnlineManagerObserver};
  this->mState = 0;
  *(_WORD *)&this->mSfxPlayed = 0;
  this->mSuspendedPlayerVehicle = 0i64;
  this->mHelpBarState = 0;
  *(_WORD *)&this->mIsStore = 0;
  this->mIsRestricted = 0;
  *(_QWORD *)&this->mSavedTimeScale = 0i64;
  *(_QWORD *)&this->mNumCategories = 0i64;
  this->mSelectedCategory = 0;
  UFG::qString::qString(&this->mSelectedCategoryCaption);
  v1->mCameraTarget = 0i64;
  v1->mPlayerMark = 0i64;
  *(_DWORD *)&v1->mInfoTickerTextSet = 0;
  `eh vector constructor iterator(v1->mInitClothing, 4ui64, 14, (void (__fastcall *)(void *))BackInfo::BackInfo);
  v5 = UFG::UIHKScreenWardrobe::HandleDeferredTask;
  v4 = Assembly::GetRCX(v1);
  UFG::EventDispatcher::Register(
    &UFG::EventDispatcher::mInstance,
    (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v4,
    UFG::gUIWardrobeScreenDeferredTaskChannel.mUID,
    0i64,
    0);
}

// File Line: 127
// RVA: 0x5CCF50
void __fastcall UFG::UIHKScreenWardrobe::~UIHKScreenWardrobe(UFG::UIHKScreenWardrobe *this)
{
  UFG::UIHKScreenWardrobe *v1; // rbx
  UFG::OnlineManagerObserver *v2; // rsi
  UFG::GameStatTracker *v3; // rax
  UFG::OnlineManager *v4; // rax
  UFG::UI *v5; // rcx
  UFG::UIHKHelpBarWidget *v6; // rdi
  unsigned int v7; // eax
  unsigned int v8; // eax
  int v9; // eax
  UFG::TimeOfDayManager *v10; // rax
  UFG::UIScreenTextureManager *v11; // rax
  hkpNullContactMgrFactory *v12; // rax
  hkpCollidable *v13; // rdx
  hkpCollidable *v14; // r8
  hkpCollisionInput *v15; // r9
  UFG::SimObject *v16; // rcx
  UFG::ScriptCameraComponent *v17; // rax
  UFG::ScriptCameraComponent *v18; // rdi
  UFG::SimComponent *v19; // rax
  UFG::SimComponent *v20; // rdx
  UFG::SimComponent *v21; // rdx
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *v22; // rdx
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *v23; // rcx
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *v24; // rax
  hkSeekableStreamReader *v25; // [rsp+28h] [rbp-30h]
  void (__fastcall *v26)(UFG::UIHKScreenWardrobe *, UFG::Event *); // [rsp+30h] [rbp-28h]

  v1 = this;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenWardrobe::`vftable{for `UFG::UIHKTaskableScreen};
  v2 = (UFG::OnlineManagerObserver *)&this->vfptr;
  this->vfptr = (UFG::OnlineManagerObserverVtbl *)&UFG::UIHKScreenWardrobe::`vftable{for `UFG::OnlineManagerObserver};
  if ( this->mHasClothingChanged )
  {
    v3 = UFG::GameStatTracker::Instance();
    UFG::GameStatTracker::ApplyDelta(v3, NumClothingChanged, 1);
    UFG::UIHKScreenWardrobe::SendTelemetryData(v1);
  }
  v4 = UFG::OnlineManager::Instance();
  UFG::OSuiteManager::UnRegisterObserver(v4, v2);
  v26 = UFG::UIHKScreenWardrobe::HandleDeferredTask;
  v25 = Assembly::GetRCX(v1);
  UFG::EventDispatcher::UnRegister(
    &UFG::EventDispatcher::mInstance,
    (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v25,
    UFG::gUIWardrobeScreenDeferredTaskChannel.mUID);
  if ( UFG::UIHKScreenGlobalOverlay::mThis )
  {
    v6 = &UFG::UIHKScreenGlobalOverlay::mThis->HelpBar;
    v7 = UFG::qStringHash32("STORE", 0xFFFFFFFF);
    UFG::UIHKHelpBarWidget::Hide(v6, v7);
  }
  if ( UFG::gInputSystem )
  {
    if ( UFG::gActiveControllerNum != -1 )
    {
      v8 = UFG::UI::gUIInputLocked;
      if ( !UFG::UI::gUIInputLocked || (--UFG::UI::gUIInputLocked, v8 == 1) )
        UFG::UI::ResetGameplayInput(v5);
    }
  }
  if ( unk_142431A14 && UFG::UIHK_PDAWidget::mInputLocked > 0 )
  {
    UFG::SetInputMode_PDA_Off(UFG::gActiveControllerNum);
    v9 = UFG::UIHKGameplayHelpWidget::mLocked;
    if ( UFG::UIHKGameplayHelpWidget::mLocked > 0 )
      v9 = UFG::UIHKGameplayHelpWidget::mLocked-- - 1;
    if ( v9 < 1 )
      UFG::UIHKScreenHud::GameplayHelp->mChanged = 1;
    --UFG::UIHK_PDAWidget::mInputLocked;
  }
  UFG::UIHKScreenHud::PDACache.state = 0;
  unk_142431A14 = 0;
  unk_142431A18 = 0;
  UFG::NavComponent::ms_bDisableNavigation = 0;
  UFG::PedSpawnManager::SetAmbientSpawningEnable(v1->mSavedFreezeStatus);
  v10 = UFG::TimeOfDayManager::GetInstance();
  TimePlotPoint::SetTimeValue(v10, v1->mSavedTimeScale);
  v11 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v11, "Wardrobe");
  v12 = (hkpNullContactMgrFactory *)UFG::StoreFrontTracker::Instance();
  if ( v12 && hkpNullContactMgrFactory::createContactMgr(v12, v13, v14, v15) && LocalPlayer )
    UFG::StoreMeshHelper::QueueSwapping((UFG::SimObject *)&LocalPlayer->vfptr);
  if ( v1->mUsingScriptCamera )
  {
    v16 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
    if ( v16 )
    {
      v17 = (UFG::ScriptCameraComponent *)UFG::SimObject::GetComponentOfType(v16, UFG::ScriptCameraComponent::_TypeUID);
      v18 = v17;
      if ( v17 )
      {
        UFG::ScriptCameraComponent::ResetDOF(v17);
        UFG::ScriptCameraComponent::ReleaseCamera(v18, 0);
      }
    }
  }
  v19 = UFG::GetCurrentGameCamera();
  if ( v19 )
    LODWORD(v19[11].m_BoundComponentHandles.mNode.mPrev) = 1;
  v20 = (UFG::SimComponent *)&v1->mCameraTarget->vfptr;
  if ( v20 )
  {
    UFG::Simulation::DestroySimComponent(&UFG::gSim, v20);
    v1->mCameraTarget = 0i64;
  }
  v21 = (UFG::SimComponent *)&v1->mPlayerMark->vfptr;
  if ( v21 )
  {
    UFG::Simulation::DestroySimComponent(&UFG::gSim, v21);
    v1->mPlayerMark = 0i64;
  }
  UFG::UIGfxTranslator::unloadDictionary(UFG::UIScreenManager::s_instance->m_translator, "ITEMS");
  `eh vector destructor iterator(v1->mInitClothing, 4ui64, 14, (void (__fastcall *)(void *))_);
  UFG::qString::~qString(&v1->mSelectedCategoryCaption);
  v2->vfptr = (UFG::OnlineManagerObserverVtbl *)&UFG::OnlineManagerObserver::`vftable;
  v22 = (UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *)&v2->mPrev;
  v23 = v2->mPrev;
  v24 = v2->mNext;
  v23->mNext = v24;
  v24->mPrev = v23;
  v22->mPrev = v22;
  v22->mNext = v22;
  UFG::UIScreen::~UIScreen((UFG::UIScreen *)&v1->vfptr);
}

// File Line: 241
// RVA: 0x636E70
void __fastcall UFG::UIHKScreenWardrobe::init(UFG::UIHKScreenWardrobe *this, UFG::UICommandData *data)
{
  UFG::UICommandData *v2; // rbx
  UFG::UIHKScreenWardrobe *v3; // rdi
  UFG::Controller *v4; // rcx
  UFG::TimeOfDayManager *v5; // rax
  UFG::OSuiteTickerManager *v6; // rax
  char v7; // bl
  char *v8; // rsi
  hkpNullContactMgrFactory *v9; // rax
  hkpCollidable *v10; // rdx
  hkpCollidable *v11; // r8
  hkpCollisionInput *v12; // r9
  hkpNullContactMgr *v13; // rax
  UFG::OnlineManager *v14; // rax
  char ptr; // [rsp+40h] [rbp-68h]
  __int64 v16; // [rsp+50h] [rbp-58h]
  unsigned int v17; // [rsp+58h] [rbp-50h]
  const char *v18; // [rsp+60h] [rbp-48h]
  char v19; // [rsp+70h] [rbp-38h]
  __int64 v20; // [rsp+80h] [rbp-28h]
  unsigned int v21; // [rsp+88h] [rbp-20h]
  char *v22; // [rsp+90h] [rbp-18h]

  v2 = data;
  v3 = this;
  this->mIsRestricted = Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
                          0i64,
                          (hkgpIndexedMeshDefinitions::Edge *)data);
  UFG::UIScreen::init((UFG::UIScreen *)&v3->vfptr, v2);
  if ( UFG::gInputSystem && UFG::gActiveControllerNum != -1 )
  {
    v4 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum];
    if ( !UFG::UI::gUIInputLocked )
      g_saved_gameplay_controller_mode = v4->m_ActiveMapSet;
    UFG::SetInputMode(IM_UI_ONLY, v4->mControllerIndex);
    ++UFG::UI::gUIInputLocked;
  }
  UFG::NavComponent::ms_bDisableNavigation = 1;
  v3->mSavedFreezeStatus = UFG::PedSpawnManager::msAmbientSpawningEnable;
  UFG::PedSpawnManager::SetAmbientSpawningEnable(0);
  v3->mSavedTimeScale = UFG::TimeOfDayManager::GetInstance()->m_GameSecondsPerRealSecond;
  v5 = UFG::TimeOfDayManager::GetInstance();
  TimePlotPoint::SetTimeValue(v5, 0.0);
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
  v3->mState = 7;
  UFG::UIGfxTranslator::loadDictionary(UFG::UIScreenManager::s_instance->m_translator, "ITEMS");
  `eh vector constructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  if ( (v17 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v16 + 16i64))(v16, &ptr, v18);
    v16 = 0i64;
  }
  v17 = 6;
  v18 = "img://INFOCAST_CHANNEL_1";
  v6 = UFG::OSuiteTickerManager::Instance();
  v7 = 1;
  v8 = UFG::OSuiteTickerManager::GetTickerDescription(v6, 1i64, 1);
  if ( (v21 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v20 + 16i64))(v20, &v19, v22);
    v20 = 0i64;
  }
  v21 = 6;
  v22 = v8;
  Scaleform::GFx::Movie::Invoke(
    v3->mRenderable->m_movie.pObject,
    "SetTickerPopupInfo",
    0i64,
    (Scaleform::GFx::Value *)&ptr,
    2u);
  UFG::UIHKScreenWardrobe::ShowTickerPopup(v3, v3->mInfoTickerPopupVisible);
  v9 = (hkpNullContactMgrFactory *)UFG::StoreFrontTracker::Instance();
  if ( !v9
    || (v13 = hkpNullContactMgrFactory::createContactMgr(v9, v10, v11, v12)) == 0i64
    || LODWORD(v13[1].vfptr) != 1 )
  {
    v7 = 0;
  }
  v3->mIsStore = v7;
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(
      (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
      0xF41B2F0D,
      0i64,
      0,
      0i64);
  v14 = UFG::OnlineManager::Instance();
  UFG::OnlineManager::RegisterObserver(v14, (UFG::OnlineManagerObserver *)&v3->vfptr);
  `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 286
// RVA: 0x61E240
void __fastcall UFG::UIHKScreenWardrobe::afterFadeToBlackInit(UFG::UIHKScreenWardrobe *this)
{
  UFG::UIHKScreenWardrobe *v1; // rsi
  Scaleform::GFx::Movie *v2; // r13
  UFG::qString *v3; // rdi
  hkpNullContactMgrFactory *v4; // rax
  hkpCollidable *v5; // rdx
  hkpCollidable *v6; // r8
  hkpCollisionInput *v7; // r9
  UFG::StoreFront *v8; // r15
  UFG::SimObjectCharacter *v9; // rbx
  UFG::CharacterAnimationComponent *v10; // rax
  unsigned __int16 v11; // cx
  UFG::TransformNodeComponent *v12; // r14
  float v13; // xmm3_4
  float v14; // xmm1_4
  float v15; // xmm3_4
  float v16; // xmm1_4
  unsigned __int16 v17; // cx
  UFG::VehicleOwnershipComponent *v18; // rax
  UFG::VehicleOwnershipComponent *v19; // rbx
  UFG::SimObjectGame *v20; // rax
  UFG::SimObject *v21; // rbx
  unsigned __int16 v22; // dx
  UFG::SimComponent *v23; // rax
  float *v24; // rcx
  float v25; // xmm1_4
  float v26; // xmm2_4
  float v27; // xmm1_4
  float v28; // xmm2_4
  UFG::qString *v29; // rax
  hkpNullContactMgr *v30; // rax
  hkpCollidable *v31; // rdx
  hkpCollidable *v32; // r8
  hkpCollisionInput *v33; // r9
  UFG::qString *v34; // rax
  bool v35; // bl
  unsigned int v36; // edx
  UFG::qVector3 aabbMin; // [rsp+28h] [rbp-79h]
  float v38; // [rsp+34h] [rbp-6Dh]
  UFG::qVector3 max; // [rsp+38h] [rbp-69h]
  float v40; // [rsp+44h] [rbp-5Dh]
  float ptr; // [rsp+48h] [rbp-59h]
  __int64 v42; // [rsp+58h] [rbp-49h]
  unsigned int v43; // [rsp+60h] [rbp-41h]
  __int64 v44; // [rsp+68h] [rbp-39h]
  __int64 v45; // [rsp+78h] [rbp-29h]
  UFG::qString result; // [rsp+80h] [rbp-21h]
  UFG::qString v47; // [rsp+A8h] [rbp+7h]
  UFG::qString *v48; // [rsp+108h] [rbp+67h]
  UFG::qString *v49; // [rsp+110h] [rbp+6Fh]

  v45 = -2i64;
  v1 = this;
  v2 = this->mRenderable->m_movie.pObject;
  if ( !v2 )
    return;
  UFG::UIHKScreenWardrobe::SaveCurrentClothingAsRestore(this);
  v3 = (UFG::qString *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                         Scaleform::Memory::pGlobalHeap,
                         32i64);
  v48 = v3;
  if ( v3 )
  {
    v3->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&Scaleform::RefCountImplCore::`vftable;
    LODWORD(v3->mNext) = 1;
    v3->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&Scaleform::RefCountImpl::`vftable;
    v3->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
    v3->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&Scaleform::RefCountBase<Scaleform::GFx::State,2>::`vftable;
    v3->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&Scaleform::GFx::State::`vftable;
    v3->mMagic = 3;
    v3->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&Scaleform::GFx::ActionControl::`vftable;
    LODWORD(v3->mData) = 8;
  }
  else
  {
    v3 = 0i64;
  }
  v49 = v3;
  LODWORD(v3->mData) |= 2u;
  v2->vfptr->SetState((Scaleform::GFx::StateBag *)&v2->vfptr, State_Filter, (Scaleform::GFx::State *)v3);
  v4 = (hkpNullContactMgrFactory *)UFG::StoreFrontTracker::Instance();
  if ( v4 )
    v8 = (UFG::StoreFront *)hkpNullContactMgrFactory::createContactMgr(v4, v5, v6, v7);
  else
    v8 = 0i64;
  UFG::UIHKScreenWardrobe::SetStoreCamera(v1, v8, 0, (float *)v2);
  UFG::UIHKScreenWardrobe::PopulateCategories(v1, v8);
  v9 = LocalPlayer;
  if ( LocalPlayer )
  {
    v11 = LocalPlayer->m_Flags;
    if ( (v11 >> 14) & 1 )
    {
      v10 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectCVBase *)&LocalPlayer->vfptr);
    }
    else if ( (v11 & 0x8000u) == 0 )
    {
      if ( (v11 >> 13) & 1 )
      {
        v10 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)LocalPlayer);
      }
      else if ( (v11 >> 12) & 1 )
      {
        v10 = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    (UFG::SimObjectGame *)&LocalPlayer->vfptr,
                                                    UFG::CharacterAnimationComponent::_TypeUID);
      }
      else
      {
        v10 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                    (UFG::SimObject *)&LocalPlayer->vfptr,
                                                    UFG::CharacterAnimationComponent::_TypeUID);
      }
    }
    else
    {
      v10 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectCVBase *)&LocalPlayer->vfptr);
    }
  }
  else
  {
    v10 = 0i64;
  }
  CharacterDamageRig::ResetDamage(v10->mDamageRig);
  if ( v9 )
    v12 = v9->m_pTransformNodeComponent;
  else
    v12 = 0i64;
  UFG::TransformNodeComponent::UpdateWorldTransform(v12);
  v13 = v12->mWorldTransform.v3.z - 5.0;
  v14 = v12->mWorldTransform.v3.y - 5.0;
  aabbMin.x = v12->mWorldTransform.v3.x - 5.0;
  aabbMin.y = v14;
  aabbMin.z = v13;
  UFG::TransformNodeComponent::UpdateWorldTransform(v12);
  v15 = v12->mWorldTransform.v3.z + 5.0;
  v16 = v12->mWorldTransform.v3.y + 5.0;
  aabbMin.z = v12->mWorldTransform.v3.x + 5.0;
  v38 = v16;
  max.x = v15;
  UFG::WheeledVehicleManager::DestroyWheeledVehiclesInNISBoundingVolume(
    UFG::WheeledVehicleManager::m_Instance,
    &aabbMin,
    (UFG::qVector3 *)((char *)&aabbMin + 8));
  if ( v9 )
  {
    v17 = v9->m_Flags;
    if ( (v17 >> 14) & 1 )
    {
      v18 = (UFG::VehicleOwnershipComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                (UFG::SimObjectGame *)&v9->vfptr,
                                                UFG::VehicleOwnershipComponent::_TypeUID);
    }
    else if ( (v17 & 0x8000u) == 0 )
    {
      if ( (v17 >> 13) & 1 )
        v18 = (UFG::VehicleOwnershipComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  (UFG::SimObjectGame *)&v9->vfptr,
                                                  UFG::VehicleOwnershipComponent::_TypeUID);
      else
        v18 = (UFG::VehicleOwnershipComponent *)((v17 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                     (UFG::SimObjectGame *)&v9->vfptr,
                                                                     UFG::VehicleOwnershipComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v9->vfptr, UFG::VehicleOwnershipComponent::_TypeUID));
    }
    else
    {
      v18 = (UFG::VehicleOwnershipComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                (UFG::SimObjectGame *)&v9->vfptr,
                                                UFG::VehicleOwnershipComponent::_TypeUID);
    }
    v19 = v18;
    if ( v18 )
    {
      if ( UFG::VehicleOwnershipComponent::GetOwnedVehicle(v18) )
      {
        v20 = (UFG::SimObjectGame *)UFG::VehicleOwnershipComponent::GetOwnedVehicle(v19);
        v21 = (UFG::SimObject *)&v20->vfptr;
        if ( v20 )
        {
          v22 = v20->m_Flags;
          if ( (v22 >> 14) & 1 )
          {
            v23 = v20->m_Components.p[14].m_pComponent;
          }
          else if ( (v22 & 0x8000u) == 0 )
          {
            if ( (v22 >> 13) & 1 )
              v23 = v20->m_Components.p[9].m_pComponent;
            else
              v23 = (v22 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                        v20,
                                        UFG::CompositeDrawableComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                       (UFG::SimObject *)&v20->vfptr,
                                                                                       UFG::CompositeDrawableComponent::_TypeUID);
          }
          else
          {
            v23 = v20->m_Components.p[14].m_pComponent;
          }
          if ( v23 )
          {
            v24 = (float *)v23[22].m_SafePointerList.mNode.mNext;
            if ( v24 )
            {
              v25 = v24[33];
              v26 = v24[34];
              max.z = v24[32];
              v40 = v25;
              ptr = v26;
              v27 = v24[36];
              v28 = v24[37];
              max.x = v24[35];
              max.y = v27;
              max.z = v28;
              TransformAABB((UFG::qMatrix44 *)&v23[20], (UFG::qVector3 *)((char *)&max + 8), &max);
              if ( aabbMin.x <= max.x
                && aabbMin.z >= max.z
                && aabbMin.y <= max.y
                && v38 >= v40
                && aabbMin.z <= max.z
                && max.x >= ptr )
              {
                UFG::SimObject::Suspend(v21);
                v1->mSuspendedPlayerVehicle = v21;
              }
            }
          }
        }
      }
    }
  }
  if ( v1->mIsStore )
  {
    v48 = &result;
    v29 = UFG::StoreFront::GetStoreTitle(v8, &result);
    UFG::UIHKScreenWardrobe::SetStoreTitle(v1, v29);
    if ( v1->mNumCategories )
    {
      UFG::UIHKScreenWardrobe::ShowCategorySelect(v1);
    }
    else
    {
      UFG::UIHKScreenWardrobe::PopulateInventory(v1);
      v1->mState = 2;
    }
    ((void (__fastcall *)(UFG::TiDo *, signed __int64))UFG::TiDo::m_pInstance->vfptr[1].Close)(
      UFG::TiDo::m_pInstance,
      5i64);
    v30 = (hkpNullContactMgr *)UFG::StoreFrontTracker::Instance();
    if ( v30 )
      v30 = hkpNullContactMgrFactory::createContactMgr((hkpNullContactMgrFactory *)v30, v31, v32, v33);
    UFG::VendorDialogueUtils::Setup((UFG::StoreFront *)v30);
    UFG::VendorDialogueUtils::PlayStoreClerkDialogue(0, 1.0);
  }
  else
  {
    v48 = &v47;
    UFG::qString::qString(&v47, "$WARDROBE_HEADING");
    UFG::UIHKScreenWardrobe::SetStoreTitle(v1, v34);
    UFG::UIHKScreenWardrobe::ShowCategorySelect(v1);
  }
  `eh vector constructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  v35 = v1->mIsStore;
  if ( (v43 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, float *, __int64))(*(_QWORD *)v42 + 16i64))(v42, &ptr, v44);
    v42 = 0i64;
  }
  v43 = 2;
  LOBYTE(v44) = v35;
  Scaleform::GFx::Movie::Invoke(v2, "SetIsStore", 0i64, (Scaleform::GFx::Value *)&ptr, 1u);
  if ( v1->mIsStore )
  {
    if ( UFG::HudAudio::m_instance )
    {
      v36 = -1871061836;
LABEL_68:
      UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr, v36, 0i64, 0, 0i64);
      goto LABEL_69;
    }
  }
  else if ( UFG::HudAudio::m_instance )
  {
    v36 = -224882297;
    goto LABEL_68;
  }
LABEL_69:
  Render::EnableLightLayer(0x30ACCAD6u, 1);
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
  UFG::UIHK_NISOverlay::UpdateAudioMuteState();
  `eh vector destructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v3);
}

// File Line: 385
// RVA: 0x61E130
void __usercall UFG::UIHKScreenWardrobe::afterFadeToBlackExit(UFG::UIHKScreenWardrobe *this@<rcx>, float *a2@<r13>)
{
  UFG::UIHKScreenWardrobe *v2; // rbx
  hkpNullContactMgr *v3; // rax
  hkpCollidable *v4; // rdx
  hkpCollidable *v5; // r8
  hkpCollisionInput *v6; // r9
  bool v7; // zf
  UFG::SimObject *v8; // rcx
  UFG::UIHKScreenGlobalOverlay *v9; // rdx
  UFG::UIHKHelpBarWidget *v10; // rbx
  unsigned int v11; // eax
  UFG::SimComponent *v12; // rax

  v2 = this;
  v3 = (hkpNullContactMgr *)UFG::StoreFrontTracker::Instance();
  if ( v3 )
    v3 = hkpNullContactMgrFactory::createContactMgr((hkpNullContactMgrFactory *)v3, v4, v5, v6);
  UFG::UIHKScreenWardrobe::SetStoreCamera(v2, (UFG::StoreFront *)v3, eCS_EXIT, a2);
  v7 = v2->mIsStore == 0;
  v2->mFinished = 1;
  if ( !v7 )
  {
    UFG::VendorDialogueUtils::PlayStoreClerkDialogue(eStoreClerkDialogueContext_Exit, 1.0);
    ((void (__fastcall *)(UFG::TiDo *, signed __int64))UFG::TiDo::m_pInstance->vfptr[1].Close)(
      UFG::TiDo::m_pInstance,
      4i64);
  }
  v8 = v2->mSuspendedPlayerVehicle;
  if ( v8 )
  {
    UFG::SimObject::Restore(v8);
    v2->mSuspendedPlayerVehicle = 0i64;
  }
  v9 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( UFG::UIHKScreenGlobalOverlay::mThis )
  {
    v10 = &UFG::UIHKScreenGlobalOverlay::mThis->HelpBar;
    v11 = UFG::qStringHash32("STORE", 0xFFFFFFFF);
    UFG::UIHKHelpBarWidget::Hide(v10, v11);
    v9 = UFG::UIHKScreenGlobalOverlay::mThis;
  }
  if ( LocalPlayer )
  {
    v12 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&LocalPlayer->vfptr, UFG::ActionTreeComponent::_TypeUID);
    ActionController::Stop((ActionController *)&v12[3]);
    v9 = UFG::UIHKScreenGlobalOverlay::mThis;
  }
  if ( v9 && v9 != (UFG::UIHKScreenGlobalOverlay *)-408i64 )
    UFG::UIHK_NISOverlay::HideElement(
      &v9->NISOverlay,
      (UFG::UIScreen *)&v9->vfptr,
      &UFG::UIHK_NISOverlay::m_curtains,
      1.0,
      0);
  UFG::UIHK_NISOverlay::UpdateAudioMuteState();
}

// File Line: 432
// RVA: 0x60F360
void __fastcall UFG::UIHKScreenWardrobe::ShowHelpBar(UFG::UIHKScreenWardrobe *this, UFG::UIHKScreenWardrobe::eHelpBarState eHelpState)
{
  UFG::UIHKScreenWardrobe::eHelpBarState v2; // edi
  UFG::UIHKScreenWardrobe *v3; // rbx
  int v4; // ecx
  __int64 v5; // rax
  __int64 v6; // rdi
  __int64 v7; // rbx
  int v8; // ecx
  __int64 v9; // rax
  __int64 v10; // rdi
  __int64 v11; // rbx
  int v12; // ecx
  signed __int64 v13; // rax
  const char *v14; // rdx
  int v15; // ecx
  __int64 v16; // rax
  __int64 v17; // rdi
  __int64 v18; // rbx
  signed __int64 v19; // rax
  int v20; // ecx
  __int64 v21; // rax
  __int64 v22; // rdi
  __int64 v23; // rbx
  int v24; // ecx
  __int64 v25; // rax
  __int64 v26; // rdi
  __int64 v27; // rbx
  __int64 v28; // rax
  int v29; // ecx
  __int64 v30; // rax
  __int64 v31; // rdi
  __int64 v32; // rbx
  int v33; // ecx
  __int64 v34; // rax
  __int64 v35; // rdi
  __int64 v36; // rbx
  __int64 v37; // rax
  int v38; // ecx
  __int64 v39; // rax
  __int64 v40; // rdi
  __int64 v41; // rbx
  __int64 v42; // rax
  int v43; // ecx
  __int64 v44; // rax
  __int64 v45; // rdi
  __int64 v46; // rbx
  int v47; // ecx
  __int64 v48; // rax
  __int64 v49; // rdi
  __int64 v50; // rbx
  __int64 v51; // rax
  __int64 v52; // rax
  __int64 v53; // rdi
  __int64 v54; // rbx
  int v55; // ecx
  __int64 v56; // rax
  __int64 v57; // rdi
  __int64 v58; // rbx
  UFG::UIHKScreenGlobalOverlay *v59; // rax
  UFG::UIHKHelpBarData data; // [rsp+20h] [rbp-D8h]
  __int64 v61; // [rsp+268h] [rbp+170h]

  v61 = -2i64;
  v2 = eHelpState;
  v3 = this;
  if ( UFG::UIHKScreenGlobalOverlay::mThis )
  {
    UFG::UIHKHelpBarData::UIHKHelpBarData(&data);
    data.id = UFG::qStringHash32("STORE", 0xFFFFFFFF);
    *(_QWORD *)&data.priority = 0i64;
    v3->mHelpBarState = v2;
    switch ( v2 )
    {
      case 1:
        if ( !v3->mIsStore && !UFG::StoreFront::IsWeiWearingAnPrefinedOutfit() )
        {
          v4 = 0;
          v5 = 0i64;
          while ( data.Buttons[v5] )
          {
            ++v4;
            if ( ++v5 >= 6 )
              goto LABEL_10;
          }
          v6 = v4;
          data.Buttons[v6] = 1;
          v7 = v4;
          UFG::qString::Set(&data.Captions[v7], "$COMMON_SELECT_UPPERCASE");
          UFG::qString::Set((UFG::qString *)((char *)&data.Captions[v7 + 5] + 32), &customWorldMapCaption);
          *(unsigned int *)((char *)&data.Icons[5].mStringHash32 + v6 * 4) = 0;
LABEL_10:
          v8 = 0;
          v9 = 0i64;
          while ( data.Buttons[v9] )
          {
            ++v8;
            if ( ++v9 >= 6 )
              goto LABEL_15;
          }
          v10 = v8;
          data.Buttons[v10] = 3;
          v11 = v8;
          UFG::qString::Set(&data.Captions[v11], "$WARDROBE_SAVE_AS_OUTFIT_UPPERCASE");
          UFG::qString::Set((UFG::qString *)((char *)&data.Captions[v11 + 5] + 32), &customWorldMapCaption);
          *(unsigned int *)((char *)&data.Icons[5].mStringHash32 + v10 * 4) = 0;
LABEL_15:
          v12 = 0;
          v13 = 0i64;
          do
          {
            if ( data.Buttons[v13] == INVALID_BUTTON )
              goto LABEL_19;
            ++v12;
            ++v13;
          }
          while ( v13 < 6 );
          goto LABEL_86;
        }
        v15 = 0;
        v16 = 0i64;
        while ( data.Buttons[v16] )
        {
          ++v15;
          if ( ++v16 >= 6 )
            goto LABEL_25;
        }
        v17 = v15;
        data.Buttons[v17] = 1;
        v18 = v15;
        UFG::qString::Set(&data.Captions[v18], "$COMMON_SELECT_UPPERCASE");
        UFG::qString::Set((UFG::qString *)((char *)&data.Captions[v18 + 5] + 32), &customWorldMapCaption);
        *(unsigned int *)((char *)&data.Icons[5].mStringHash32 + v17 * 4) = 0;
LABEL_25:
        v12 = 0;
        v19 = 0i64;
        do
        {
          if ( data.Buttons[v19] == INVALID_BUTTON )
            goto LABEL_19;
          ++v12;
          ++v19;
        }
        while ( v19 < 6 );
        goto LABEL_86;
      case 2:
        v20 = 0;
        v21 = 0i64;
        while ( data.Buttons[v21] )
        {
          ++v20;
          if ( ++v21 >= 6 )
            goto LABEL_34;
        }
        v22 = v20;
        data.Buttons[v22] = 1;
        v23 = v20;
        UFG::qString::Set(&data.Captions[v23], "$WARDROBE_BUY_UPPERCASE");
        UFG::qString::Set((UFG::qString *)((char *)&data.Captions[v23 + 5] + 32), &customWorldMapCaption);
        *(unsigned int *)((char *)&data.Icons[5].mStringHash32 + v22 * 4) = 0;
LABEL_34:
        v24 = 0;
        v25 = 0i64;
        while ( data.Buttons[v25] )
        {
          ++v24;
          if ( ++v25 >= 6 )
            goto LABEL_39;
        }
        v26 = v24;
        data.Buttons[v26] = 4;
        v27 = v24;
        UFG::qString::Set(&data.Captions[v27], "$COMMON_ZOOM_IN_UPPERCASE");
        UFG::qString::Set((UFG::qString *)((char *)&data.Captions[v27 + 5] + 32), &customWorldMapCaption);
        *(unsigned int *)((char *)&data.Icons[5].mStringHash32 + v26 * 4) = 0;
LABEL_39:
        v12 = 0;
        v28 = 0i64;
        while ( data.Buttons[v28] )
        {
          ++v12;
          if ( ++v28 >= 6 )
            goto LABEL_86;
        }
        goto LABEL_19;
      case 3:
        v29 = 0;
        v30 = 0i64;
        while ( data.Buttons[v30] )
        {
          ++v29;
          if ( ++v30 >= 6 )
            goto LABEL_48;
        }
        v31 = v29;
        data.Buttons[v31] = 1;
        v32 = v29;
        UFG::qString::Set(&data.Captions[v32], "$WARDROBE_WEAR_UPPERCASE");
        UFG::qString::Set((UFG::qString *)((char *)&data.Captions[v32 + 5] + 32), &customWorldMapCaption);
        *(unsigned int *)((char *)&data.Icons[5].mStringHash32 + v31 * 4) = 0;
LABEL_48:
        v33 = 0;
        v34 = 0i64;
        while ( data.Buttons[v34] )
        {
          ++v33;
          if ( ++v34 >= 6 )
            goto LABEL_53;
        }
        v35 = v33;
        data.Buttons[v35] = 4;
        v36 = v33;
        UFG::qString::Set(&data.Captions[v36], "$COMMON_ZOOM_IN_UPPERCASE");
        UFG::qString::Set((UFG::qString *)((char *)&data.Captions[v36 + 5] + 32), &customWorldMapCaption);
        *(unsigned int *)((char *)&data.Icons[5].mStringHash32 + v35 * 4) = 0;
LABEL_53:
        v12 = 0;
        v37 = 0i64;
        while ( data.Buttons[v37] )
        {
          ++v12;
          if ( ++v37 >= 6 )
            goto LABEL_86;
        }
        goto LABEL_19;
      case 4:
      case 5:
        v38 = 0;
        v39 = 0i64;
        while ( data.Buttons[v39] )
        {
          ++v38;
          if ( ++v39 >= 6 )
            goto LABEL_62;
        }
        v40 = v38;
        data.Buttons[v40] = 1;
        v41 = v38;
        UFG::qString::Set(&data.Captions[v41], "$WARDROBE_WEAR_UPPERCASE");
        UFG::qString::Set((UFG::qString *)((char *)&data.Captions[v41 + 5] + 32), &customWorldMapCaption);
        *(unsigned int *)((char *)&data.Icons[5].mStringHash32 + v40 * 4) = 0;
LABEL_62:
        v12 = 0;
        v42 = 0i64;
        while ( data.Buttons[v42] )
        {
          ++v12;
          if ( ++v42 >= 6 )
            goto LABEL_86;
        }
        goto LABEL_19;
      case 6:
        v43 = 0;
        v44 = 0i64;
        while ( data.Buttons[v44] )
        {
          ++v43;
          if ( ++v44 >= 6 )
            goto LABEL_71;
        }
        v45 = v43;
        data.Buttons[v45] = 1;
        v46 = v43;
        UFG::qString::Set(&data.Captions[v46], "$COMMON_SELECT_UPPERCASE");
        UFG::qString::Set((UFG::qString *)((char *)&data.Captions[v46 + 5] + 32), &customWorldMapCaption);
        *(unsigned int *)((char *)&data.Icons[5].mStringHash32 + v45 * 4) = 0;
LABEL_71:
        v47 = 0;
        v48 = 0i64;
        while ( data.Buttons[v48] )
        {
          ++v47;
          if ( ++v48 >= 6 )
            goto LABEL_76;
        }
        v49 = v47;
        data.Buttons[v49] = 4;
        v50 = v47;
        UFG::qString::Set(&data.Captions[v50], "$WARDROBE_PREVIEW_OUTFIT");
        UFG::qString::Set((UFG::qString *)((char *)&data.Captions[v50 + 5] + 32), &customWorldMapCaption);
        *(unsigned int *)((char *)&data.Icons[5].mStringHash32 + v49 * 4) = 0;
LABEL_76:
        v12 = 0;
        v51 = 0i64;
        while ( data.Buttons[v51] )
        {
          ++v12;
          if ( ++v51 >= 6 )
            goto LABEL_86;
        }
LABEL_19:
        v14 = "$COMMON_BACK_UPPERCASE";
        goto LABEL_85;
      case 7:
        v12 = 0;
        v52 = 0i64;
        break;
      default:
        UFG::qString::~qString((UFG::qString *)&data.MessageIds[4]);
        `eh vector destructor iterator(
          &data.Captions[5].mStringHash32,
          0x28ui64,
          6,
          (void (__fastcall *)(void *))UFG::qString::~qString);
        goto LABEL_95;
    }
    while ( data.Buttons[v52] )
    {
      ++v12;
      if ( ++v52 >= 6 )
        goto LABEL_86;
    }
    v14 = "$COMMON_ZOOM_OUT_UPPERCASE";
LABEL_85:
    v53 = v12;
    v54 = v12;
    data.Buttons[v53] = 2;
    UFG::qString::Set(&data.Captions[v54], v14);
    UFG::qString::Set((UFG::qString *)((char *)&data.Captions[v54 + 5] + 32), &customWorldMapCaption);
    *(unsigned int *)((char *)&data.Icons[5].mStringHash32 + v53 * 4) = 0;
LABEL_86:
    v55 = 0;
    v56 = 0i64;
    while ( data.Buttons[v56] )
    {
      ++v55;
      if ( ++v56 >= 6 )
        goto LABEL_91;
    }
    v57 = v55;
    data.Buttons[v57] = 13;
    v58 = v55;
    UFG::qString::Set(&data.Captions[v58], "$WARDROBE_ROTATE");
    UFG::qString::Set((UFG::qString *)((char *)&data.Captions[v58 + 5] + 32), &customWorldMapCaption);
    *(unsigned int *)((char *)&data.Icons[5].mStringHash32 + v57 * 4) = 0;
LABEL_91:
    v59 = UFG::UIHKScreenGlobalOverlay::mThis;
    if ( !UFG::UIHKScreenGlobalOverlay::mThis )
      v59 = &gGlobalOverlaySentinel;
    UFG::UIHKHelpBarWidget::Show(&v59->HelpBar, &data);
    UFG::qString::~qString((UFG::qString *)&data.MessageIds[4]);
    `eh vector destructor iterator(
      &data.Captions[5].mStringHash32,
      0x28ui64,
      6,
      (void (__fastcall *)(void *))UFG::qString::~qString);
LABEL_95:
    `eh vector destructor iterator(data.Captions, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
  }
}

// File Line: 504
// RVA: 0x61DBF0
void __usercall UFG::UIHKScreenWardrobe::ZoomIn(UFG::UIHKScreenWardrobe *this@<rcx>, float *a2@<r13>)
{
  UFG::UIHKScreenWardrobe *v2; // rdi
  hkpNullContactMgrFactory *v3; // rax
  hkpCollidable *v4; // rdx
  hkpCollidable *v5; // r8
  hkpCollisionInput *v6; // r9
  UFG::StoreFront *v7; // rdx
  Scaleform::GFx::Movie *v8; // rbx

  v2 = this;
  v3 = (hkpNullContactMgrFactory *)UFG::StoreFrontTracker::Instance();
  if ( v3 )
    v7 = (UFG::StoreFront *)hkpNullContactMgrFactory::createContactMgr(v3, v4, v5, v6);
  else
    v7 = 0i64;
  v8 = v2->mRenderable->m_movie.pObject;
  UFG::UIHKScreenWardrobe::SetStoreCamera(v2, v7, eCS_ZOOM_IN, a2);
  Scaleform::GFx::Movie::Invoke(v8, "ZoomInStart", 0i64, 0i64, 0);
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(
      (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
      0x1F5AAC5Bu,
      0i64,
      0,
      0i64);
  v2->mOldHelpbarState = v2->mHelpBarState;
  v2->mState = 1;
  UFG::UIHKScreenWardrobe::ShowHelpBar(v2, HELP_SELECT_ITEM_EMPTY|HELP_SELECT_ITEM_STORAGE);
}

// File Line: 513
// RVA: 0x61DCA0
void __usercall UFG::UIHKScreenWardrobe::ZoomOut(UFG::UIHKScreenWardrobe *this@<rcx>, float *a2@<r13>)
{
  UFG::UIHKScreenWardrobe *v2; // rdi
  hkpNullContactMgrFactory *v3; // rax
  hkpCollidable *v4; // rdx
  hkpCollidable *v5; // r8
  hkpCollisionInput *v6; // r9
  UFG::StoreFront *v7; // rdx
  Scaleform::GFx::Movie *v8; // rbx
  UFG::UIHKScreenWardrobe::eHelpBarState v9; // edx

  v2 = this;
  v3 = (hkpNullContactMgrFactory *)UFG::StoreFrontTracker::Instance();
  if ( v3 )
    v7 = (UFG::StoreFront *)hkpNullContactMgrFactory::createContactMgr(v3, v4, v5, v6);
  else
    v7 = 0i64;
  v8 = v2->mRenderable->m_movie.pObject;
  UFG::UIHKScreenWardrobe::SetStoreCamera(v2, v7, eCS_ZOOM_OUT, a2);
  Scaleform::GFx::Movie::Invoke(v8, "ZoomInEnd", 0i64, 0i64, 0);
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(
      (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
      0xFAFA25CA,
      0i64,
      0,
      0i64);
  v9 = v2->mOldHelpbarState;
  v2->mState = 2;
  UFG::UIHKScreenWardrobe::ShowHelpBar(v2, v9);
}

// File Line: 521
// RVA: 0x609CE0
void __fastcall UFG::UIHKScreenWardrobe::SetStoreTitle(UFG::UIHKScreenWardrobe *this, UFG::qString *a_Title)
{
  UFG::qString *v2; // rbx
  Scaleform::GFx::Movie *v3; // rdi
  UFG::qString *v4; // rcx
  char *v5; // rsi
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-40h]

  v2 = a_Title;
  v3 = this->mRenderable->m_movie.pObject;
  if ( v3 )
  {
    value.pObjectInterface = 0i64;
    value.Type = 0;
    v5 = a_Title->mData;
    value.Type = 6;
    *(_QWORD *)&value.mValue.NValue = v5;
    Scaleform::GFx::Movie::SetVariable(v3, "mcTitle.text", &value, 1i64);
    if ( ((unsigned int)value.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        *(_QWORD *)&value.mValue.NValue);
      value.pObjectInterface = 0i64;
    }
    value.Type = 0;
    v4 = v2;
  }
  else
  {
    v4 = a_Title;
  }
  UFG::qString::~qString(v4);
}

// File Line: 534
// RVA: 0x609A10
void __fastcall UFG::UIHKScreenWardrobe::SetStoreDesc(UFG::UIHKScreenWardrobe *this, UFG::qString *a_Desc)
{
  UFG::qString *v2; // rbx
  Scaleform::GFx::Movie *v3; // rdi
  UFG::qString *v4; // rcx
  char *v5; // rsi
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-40h]

  v2 = a_Desc;
  v3 = this->mRenderable->m_movie.pObject;
  if ( v3 )
  {
    value.pObjectInterface = 0i64;
    value.Type = 0;
    v5 = a_Desc->mData;
    value.Type = 6;
    *(_QWORD *)&value.mValue.NValue = v5;
    Scaleform::GFx::Movie::SetVariable(v3, "mcDesc.htmlText", &value, 1i64);
    if ( ((unsigned int)value.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        *(_QWORD *)&value.mValue.NValue);
      value.pObjectInterface = 0i64;
    }
    value.Type = 0;
    v4 = v2;
  }
  else
  {
    v4 = a_Desc;
  }
  UFG::qString::~qString(v4);
}

// File Line: 547
// RVA: 0x611340
void __fastcall UFG::UIHKScreenWardrobe::ShowTickerPopup(UFG::UIHKScreenWardrobe *this, bool isVisible)
{
  bool v2; // di
  UFG::UIHKScreenWardrobe *v3; // rbx
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

// File Line: 557
// RVA: 0x603720
void __fastcall UFG::UIHKScreenWardrobe::SaveCurrentClothingAsRestore(UFG::UIHKScreenWardrobe *this)
{
  UFG::UIHKScreenWardrobe *v1; // rdi
  UFG::GameStatTracker *v2; // rbx

  v1 = this;
  v2 = UFG::GameStatTracker::Instance();
  v1->mInitClothing[1].mUID = UFG::GameStatTracker::GetStat(v2, CurrentLowerBody)->mValue.mUID;
  v1->mInitClothing[2].mUID = UFG::GameStatTracker::GetStat(v2, CurrentFootwear)->mValue.mUID;
  v1->mInitClothing[3].mUID = UFG::GameStatTracker::GetStat(v2, CurrentHeadgear)->mValue.mUID;
  v1->mInitClothing[4].mUID = UFG::GameStatTracker::GetStat(v2, CurrentHead)->mValue.mUID;
  v1->mInitClothing[0].mUID = UFG::GameStatTracker::GetStat(v2, CurrentBody)->mValue.mUID;
  v1->mInitClothing[5].mUID = UFG::GameStatTracker::GetStat(v2, CurrentAccessories)->mValue.mUID;
  v1->mInitClothing[6].mUID = UFG::GameStatTracker::GetStat(v2, CurrentGlasses)->mValue.mUID;
  v1->mInitClothing[7].mUID = UFG::GameStatTracker::GetStat(v2, CurrentNeck)->mValue.mUID;
  v1->mInitClothing[8].mUID = UFG::GameStatTracker::GetStat(v2, CurrentLeftWrist)->mValue.mUID;
  v1->mInitClothing[9].mUID = UFG::GameStatTracker::GetStat(v2, CurrentRightWrist)->mValue.mUID;
  v1->mInitClothing[10].mUID = UFG::GameStatTracker::GetStat(v2, CurrentOutfit)->mValue.mUID;
}

// File Line: 574
// RVA: 0x5EA950
void __fastcall UFG::UIHKScreenWardrobe::HandleDeferredTask(UFG::UIHKScreenWardrobe *this, UFG::Event *e)
{
  int v2; // er8

  v2 = e->mUserData0;
  if ( v2 )
  {
    if ( v2 == 1 )
      UFG::UIHKScreenWardrobe::afterFadeToBlackExit(this);
  }
  else
  {
    UFG::UIHKScreenWardrobe::afterFadeToBlackInit(this);
  }
}

// File Line: 599
// RVA: 0x62DB40
char __usercall UFG::UIHKScreenWardrobe::handleMessage@<al>(UFG::UIHKScreenWardrobe *this@<rcx>, unsigned int msgId@<edx>, UFG::UIMessage *msg@<r8>, float *a4@<r13>)
{
  UFG::UIMessage *v4; // r15
  unsigned int v5; // edi
  UFG::UIHKScreenWardrobe *v6; // rbx
  UFG::allocator::free_link *v7; // rax
  UFG::Event *v8; // rax
  UFG::Event *v9; // rdx
  UFG::UIHK_NISOverlay *v11; // rax
  UFG::HudAudio *v12; // rcx
  unsigned int v13; // edx
  int v14; // er14
  hkpNullContactMgrFactory *v15; // rax
  hkpCollidable *v16; // rdx
  hkpCollidable *v17; // r8
  hkpCollisionInput *v18; // r9
  UFG::StoreFront *v19; // rbp
  UFG::qPropertySet *v20; // rax
  int v21; // eax
  UFG::qPropertySet *v22; // rax
  UFG::qPropertySet *v23; // rax
  UFG::UIHK_NISOverlay *v24; // rax
  int v25; // esi
  UFG::UIHK_NISOverlay *v26; // rax
  bool v27; // zf
  UFG::UIHK_NISOverlay *v28; // rax
  UFG::StoreFront::OutfitNum v29; // eax
  UFG::allocator::free_link *v30; // rax
  UFG::Event *v31; // rax
  UFG::Event *v32; // rsi

  v4 = msg;
  v5 = msgId;
  v6 = this;
  if ( msgId == UI_HASH_GAME_OVER_20 )
    UFG::UIScreenManagerBase::queuePopScreen(
      (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
      this->mScreenUID);
  switch ( v6->mState )
  {
    case 1:
      if ( v5 == UI_HASH_BUTTON_BACK_PRESSED_30 )
        UFG::UIHKScreenWardrobe::ZoomOut(v6, a4);
      return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v6->vfptr, v5, v4);
    case 2:
      if ( UFG::UIHKScreenGlobalOverlay::mThis )
        v11 = &UFG::UIHKScreenGlobalOverlay::mThis->NISOverlay;
      else
        v11 = 0i64;
      if ( v11->mActive && v4->m_messageType <= 3 )
        return 1;
      if ( v5 == UI_HASH_PURCHASE_ITEM || v5 == UI_HASH_PURCHASE_AND_EQUIP_ITEM )
      {
        v14 = UFG::UIHKScreenWardrobe::GetSelectedTrackerIndex(v6);
        v15 = (hkpNullContactMgrFactory *)UFG::StoreFrontTracker::Instance();
        if ( v15 )
          v19 = (UFG::StoreFront *)hkpNullContactMgrFactory::createContactMgr(v15, v16, v17, v18);
        else
          v19 = 0i64;
        if ( UFG::StoreFront::PurchaseItem(v19, v14) )
        {
          v20 = UFG::StoreFront::GetItem(v19, v14);
          UFG::VendorDialogueUtils::SetLastItemPurchased(v20);
          if ( UFG::HudAudio::m_instance )
            UFG::AudioEntity::CreateAndPlayEvent(
              (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
              0xDC33EA39,
              0i64,
              0,
              0i64);
          UFG::UIHKScreenWardrobe::UpdateMoney(v6);
        }
        if ( v5 == UI_HASH_PURCHASE_AND_EQUIP_ITEM )
        {
          v21 = UFG::UIHKScreenWardrobe::GetSelectedIndex(v6);
          v22 = UFG::StoreFront::GetItem(v19, v21);
          UFG::UIHKScreenWardrobe::EquipItem(v6, v22, 1, 1, 1, 1, 0);
          UFG::UIHKScreenWardrobe::UpdateMoney(v6);
          UFG::UIHKScreenWardrobe::ShowCategorySelect(v6);
          UFG::StoreFront::CheckAchievement();
          if ( UFG::GameStatAction::Store::AreAllClothesPurchased() )
            UFG::AchievementTrophyManager::UnlockAchievementTrophy(37);
          v6->mHasClothingChanged = 1;
        }
        else
        {
          UFG::UIHKScreenWardrobe::PopulateInventory(v6);
        }
        v23 = UFG::StoreFront::GetItem(v19, v14);
        UFG::VendorDialogueUtils::sm_moneySpent = UFG::VendorDialogueUtils::sm_moneySpent
                                                + UFG::StoreFrontTracker::GetItemPriceBasedOnClothes(v23);
        UFG::VendorDialogueUtils::PlayStoreClerkDialogue(eStoreClerkDialogueContext_Sale, 1.0);
        return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v6->vfptr, v5, v4);
      }
      if ( v5 == UI_HASH_OPTION_HIGHLIGHTED_30 )
      {
        UFG::UIHKScreenWardrobe::HandleOptionHighlighted(v6);
        return 1;
      }
      if ( v5 == UI_HASH_BUTTON_BACK_PRESSED_30 )
      {
        if ( UFG::HudAudio::m_instance )
          UFG::AudioEntity::CreateAndPlayEvent(
            (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
            0xA4E5BFBD,
            0i64,
            0,
            0i64);
        UFG::UIHKScreenWardrobe::RestoreNonPurchasedEquipment(v6, 0);
        if ( v6->mNumCategories > 0 && v6->mNumItems > 0 )
        {
          UFG::UIHKScreenWardrobe::ShowCategorySelect(v6);
          return 1;
        }
        UFG::UIHKScreenWardrobe::Exit(v6);
        return 1;
      }
      if ( v5 == UI_HASH_BUTTON_ACCEPT_PRESSED_30 )
      {
        if ( UFG::HudAudio::m_instance )
          UFG::AudioEntity::CreateAndPlayEvent(
            (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
            0xCCF5DDCu,
            0i64,
            0,
            0i64);
        UFG::UIHKScreenWardrobe::HandleOptionSelected(v6);
        if ( v6->mIsStore )
          return 1;
        v6->mHasClothingChanged = 1;
        UFG::StoreFront::CheckAchievement();
        return 1;
      }
      if ( v5 == (_DWORD)UI_HASH_BUTTON_BUTTON2_PRESSED_30 )
      {
        UFG::UIHKScreenWardrobe::ZoomIn(v6, a4);
        return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v6->vfptr, v5, v4);
      }
      if ( v5 != UI_HASH_FADE_OUT_COMPLETE_30 )
        goto LABEL_39;
      return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v6->vfptr, v5, v4);
    case 3:
      if ( UFG::UIHKScreenGlobalOverlay::mThis )
        v24 = &UFG::UIHKScreenGlobalOverlay::mThis->NISOverlay;
      else
        v24 = 0i64;
      if ( v24->mActive && v4->m_messageType <= 3 )
        return 1;
      if ( v5 == UI_HASH_DIALOG_YES_30 )
      {
        UFG::StoreFront::PreviewRemoveCustomOutfit();
LABEL_68:
        UFG::UIHKScreenWardrobe::CategorySelect_HandleOptionSelected(v6);
        return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v6->vfptr, v5, v4);
      }
      if ( v5 != UI_HASH_BUTTON_ACCEPT_PRESSED_30 )
      {
        if ( v5 == UI_HASH_BUTTON_BACK_PRESSED_30 )
        {
          if ( UFG::HudAudio::m_instance )
            UFG::AudioEntity::CreateAndPlayEvent(
              (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
              0xA4E5BFBD,
              0i64,
              0,
              0i64);
          UFG::UIHKScreenWardrobe::Exit(v6);
          return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v6->vfptr, v5, v4);
        }
        if ( v5 == UI_HASH_OPTION_HIGHLIGHTED_30 )
        {
LABEL_123:
          v12 = UFG::HudAudio::m_instance;
          if ( !UFG::HudAudio::m_instance )
            return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v6->vfptr, v5, v4);
          v13 = 1706059527;
          goto LABEL_125;
        }
        if ( v5 == UI_HASH_BUTTON_BUTTON1_PRESSED_30 )
        {
          UFG::UIHKScreenWardrobe::CategorySelect_HandleSaveCustomOutfit(v6);
          return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v6->vfptr, v5, v4);
        }
        if ( v5 == UI_HASH_BUTTON_SELECT_PRESSED_30 )
        {
          if ( !v6->mIsRestricted )
            UFG::UIHKScreenWardrobe::CategorySelect_HandleToggleTickerPopup(v6);
          return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v6->vfptr, v5, v4);
        }
LABEL_39:
        if ( v5 != UI_HASH_DPAD_UP_PRESSED_30 )
        {
          if ( v5 != UI_HASH_DPAD_DOWN_PRESSED_30 && v5 != UI_HASH_THUMBSTICK_LEFT_DOWN_30 )
          {
            if ( v5 != UI_HASH_THUMBSTICK_LEFT_UP_30 )
              return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v6->vfptr, v5, v4);
          }
          else if ( v5 != UI_HASH_THUMBSTICK_LEFT_UP_30 )
          {
            v12 = UFG::HudAudio::m_instance;
            if ( !UFG::HudAudio::m_instance )
              return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v6->vfptr, v5, v4);
            v13 = 192470248;
LABEL_125:
            UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&v12->vfptr, v13, 0i64, 0, 0i64);
            return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v6->vfptr, v5, v4);
          }
        }
        v12 = UFG::HudAudio::m_instance;
        if ( !UFG::HudAudio::m_instance )
          return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v6->vfptr, v5, v4);
        v13 = 1497067691;
        goto LABEL_125;
      }
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(
          (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
          0xCCF5DDCu,
          0i64,
          0,
          0i64);
      v6->mSfxPlayed = 1;
      v25 = UFG::UIHKScreenWardrobe::GetSelectedCategory(v6);
      if ( !UFG::StoreFront::IsWeiWearingAnPrefinedOutfit() || v25 == 10 )
        goto LABEL_68;
      UFG::UIScreenDialogBox::createYesNoDialog(
        (UFG::UIScreen *)&v6->vfptr,
        &customWorldMapCaption,
        "$STORE_REMOVE_OUTFIT",
        0,
        0);
      return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v6->vfptr, v5, v4);
    case 4:
      if ( UFG::UIHKScreenGlobalOverlay::mThis )
        v26 = &UFG::UIHKScreenGlobalOverlay::mThis->NISOverlay;
      else
        v26 = 0i64;
      if ( v26->mActive )
        return 1;
      if ( v5 == UI_HASH_BUTTON_ACCEPT_PRESSED_30 )
      {
        if ( UFG::HudAudio::m_instance )
          UFG::AudioEntity::CreateAndPlayEvent(
            (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
            0xCCF5DDCu,
            0i64,
            0,
            0i64);
        UFG::UIHKScreenWardrobe::CustomOutfit_HandleOptionSelected(v6);
        UFG::UIHKScreenWardrobe::ShowCategorySelect(v6);
      }
      else
      {
        if ( v5 == UI_HASH_BUTTON_BACK_PRESSED_30 )
          goto LABEL_94;
        if ( v5 == UI_HASH_OPTION_HIGHLIGHTED_30 )
        {
          UFG::UIHKScreenWardrobe::HandleOptionHighlighted(v6);
          return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v6->vfptr, v5, v4);
        }
        if ( v5 == UI_HASH_DPAD_UP_PRESSED_30
          || v5 == UI_HASH_DPAD_DOWN_PRESSED_30
          || v5 == UI_HASH_THUMBSTICK_LEFT_DOWN_30
          || v5 == UI_HASH_THUMBSTICK_LEFT_UP_30 )
        {
          v27 = v6->mSfxPlayed == 0;
          goto LABEL_122;
        }
      }
      return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v6->vfptr, v5, v4);
    case 5:
      if ( UFG::UIHKScreenGlobalOverlay::mThis )
        v28 = &UFG::UIHKScreenGlobalOverlay::mThis->NISOverlay;
      else
        v28 = 0i64;
      if ( v28->mActive )
        return 1;
      if ( v5 == UI_HASH_DIALOG_YES_30 )
      {
        UFG::UIHKScreenWardrobe::SaveCurrentClothingAsOutfit(v6, (UFG::StoreFront::OutfitNum)v6->mSelectedIndex);
        UFG::UIHKScreenWardrobe::ShowCategorySelect(v6);
        return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v6->vfptr, v5, v4);
      }
      if ( v5 == UI_HASH_BUTTON_ACCEPT_PRESSED_30 )
      {
        if ( UFG::HudAudio::m_instance )
          UFG::AudioEntity::CreateAndPlayEvent(
            (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
            0x4A3D1F6Cu,
            0i64,
            0,
            0i64);
        v29 = (unsigned int)UFG::UIHKScreenWardrobe::GetSelectedIndex(v6);
        v6->mSelectedIndex = v29;
        if ( UFG::UIHKScreenWardrobe::IsCustomOutfitSlotInUse(v6, v29) )
        {
          UFG::UIScreenDialogBox::createYesNoDialog(
            (UFG::UIScreen *)&v6->vfptr,
            &customWorldMapCaption,
            "$WARDROBE_OVERWRITE_OUTFIT",
            0,
            0);
        }
        else
        {
          UFG::UIHKScreenWardrobe::SaveCurrentClothingAsOutfit(v6, (UFG::StoreFront::OutfitNum)v6->mSelectedIndex);
          UFG::UIHKScreenWardrobe::ShowCategorySelect(v6);
        }
        return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v6->vfptr, v5, v4);
      }
      if ( v5 == UI_HASH_BUTTON_BACK_PRESSED_30 )
      {
LABEL_94:
        if ( UFG::HudAudio::m_instance )
          UFG::AudioEntity::CreateAndPlayEvent(
            (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
            0xA4E5BFBD,
            0i64,
            0,
            0i64);
        UFG::UIHKScreenWardrobe::RestoreNonPurchasedEquipment(v6, 0);
        UFG::UIHKScreenWardrobe::ShowCategorySelect(v6);
        return 1;
      }
      if ( v5 == (_DWORD)UI_HASH_BUTTON_BUTTON2_PRESSED_30 )
      {
        UFG::UIHKScreenWardrobe::PreviewOutfit(v6);
        return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v6->vfptr, v5, v4);
      }
      if ( v5 == UI_HASH_BUTTON_BUTTON2_RELEASED_30 )
      {
        UFG::UIHKScreenWardrobe::RestoreNonPurchasedEquipment(v6, 1);
        return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v6->vfptr, v5, v4);
      }
      v27 = v5 == UI_HASH_OPTION_HIGHLIGHTED_30;
LABEL_122:
      if ( v27 )
        goto LABEL_123;
      return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v6->vfptr, v5, v4);
    case 6:
      if ( v5 != UI_HASH_DIALOG_OK_30 )
        return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v6->vfptr, v5, v4);
      v6->mState = 2;
      return 1;
    case 7:
      if ( v5 != UI_HASH_SCREEN_FADE_IN_COMPLETE_12 )
        return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v6->vfptr, v5, v4);
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(
          (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
          0xEDABFAC7,
          0i64,
          0,
          0i64);
      v7 = UFG::qMalloc(0x38ui64, "UIWardrobeScreenDeferredTaskChannel", 0i64);
      if ( v7 )
        UFG::Event::Event((UFG::Event *)v7, UFG::gUIWardrobeScreenDeferredTaskChannel.mName);
      else
        v8 = 0i64;
      v8->mUserData0 = 0i64;
      v9 = v8;
      goto LABEL_11;
    case 8:
      if ( v5 != UI_HASH_SCREEN_FADE_IN_COMPLETE_12 )
        return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v6->vfptr, v5, v4);
      v30 = UFG::qMalloc(0x38ui64, "UIWardrobeScreenDeferredTaskChannel", 0i64);
      if ( v30 )
      {
        UFG::Event::Event((UFG::Event *)v30, UFG::gUIWardrobeScreenDeferredTaskChannel.mName);
        v32 = v31;
      }
      else
      {
        v32 = 0i64;
      }
      v32->mUserData0 = 1i64;
      v9 = v32;
LABEL_11:
      UFG::EventDispatcher::QueueEvent(&UFG::EventDispatcher::mInstance, v9);
      return 1;
    default:
      return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v6->vfptr, v5, v4);
  }
}

// File Line: 941
// RVA: 0x5D4A30
void __fastcall UFG::UIHKScreenWardrobe::CategorySelect_HandleSaveCustomOutfit(UFG::UIHKScreenWardrobe *this)
{
  UFG::UIHKScreenWardrobe *v1; // rbx
  Scaleform::GFx::Movie *v2; // rcx
  hkpNullContactMgrFactory *v3; // rax
  hkpCollidable *v4; // rdx
  hkpCollidable *v5; // r8
  hkpCollisionInput *v6; // r9
  UFG::qString *v7; // rax
  UFG::qString v8; // [rsp+38h] [rbp-30h]

  v1 = this;
  if ( !this->mIsStore )
  {
    this->mState = 2;
    v2 = this->mRenderable->m_movie.pObject;
    if ( v2 )
      Scaleform::GFx::Movie::Invoke(v2, "HideCategorySelect", 0i64, 0i64, 0);
    v1->mState = 5;
    UFG::UIHKScreenWardrobe::Flash_CustomOutfit(v1);
    UFG::UIHKScreenWardrobe::PopulateCustomOutfits(v1);
    UFG::UIHKScreenWardrobe::ShowHelpBar(v1, HELP_SELECT_ITEM_EMPTY|HELP_SELECT_ITEM_RACE);
    v3 = (hkpNullContactMgrFactory *)UFG::StoreFrontTracker::Instance();
    if ( v3 )
    {
      if ( hkpNullContactMgrFactory::createContactMgr(v3, v4, v5, v6) )
      {
        UFG::qString::qString(&v8, "$WARDROBE_SAVE_OUTFIT");
        UFG::UIHKScreenWardrobe::SetStoreDesc(v1, v7);
      }
    }
  }
}

// File Line: 963
// RVA: 0x5DA540
void __fastcall UFG::UIHKScreenWardrobe::Flash_CustomOutfit(UFG::UIHKScreenWardrobe *this)
{
  Scaleform::GFx::Movie *v1; // rbx
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-40h]

  v1 = this->mRenderable->m_movie.pObject;
  if ( v1 )
  {
    value.pObjectInterface = 0i64;
    value.Type = 2;
    value.mValue.BValue = 1;
    Scaleform::GFx::Movie::SetVariable(v1, "mOutfitSave", &value, 1i64);
    if ( ((unsigned int)value.Type >> 6) & 1 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        *(_QWORD *)&value.mValue.NValue);
  }
}

// File Line: 974
// RVA: 0x5D4AF0
void __fastcall UFG::UIHKScreenWardrobe::CategorySelect_HandleToggleTickerPopup(UFG::UIHKScreenWardrobe *this)
{
  UFG::UIHKScreenWardrobe *v1; // rbx
  bool v2; // dl
  unsigned int v3; // edx

  v1 = this;
  v2 = this->mInfoTickerPopupVisible == 0;
  this->mInfoTickerPopupVisible = v2;
  UFG::UIHKScreenWardrobe::ShowTickerPopup(this, v2);
  UFG::UIHKScreenWardrobe::ShowHelpBar(v1, v1->mHelpBarState);
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

// File Line: 986
// RVA: 0x6404D0
void __usercall UFG::UIHKScreenWardrobe::update(UFG::UIHKScreenWardrobe *this@<rcx>, float elapsed@<xmm1>, float *a3@<r13>)
{
  UFG::UIHKScreenWardrobe *v3; // rbx
  float v4; // xmm0_4
  hkpNullContactMgrFactory *v5; // rax
  hkpCollidable *v6; // rdx
  hkpCollidable *v7; // r8
  hkpCollisionInput *v8; // r9
  UFG::StoreFront *v9; // rdi
  UFG::SimComponent *v10; // rax
  UFG::OSuiteTickerManager *v11; // rax
  char *v12; // rsi
  UFG::UIHKScreenWardrobe::eCameraState v13; // er8
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-50h]

  v3 = this;
  this->mSfxPlayed = 0;
  UFG::UIScreen::update((UFG::UIScreen *)&this->vfptr, elapsed);
  v4 = UFG::VendorDialogueUtils::sm_idleTime + elapsed;
  UFG::VendorDialogueUtils::sm_idleTime = v4;
  if ( v4 >= UFG::VendorDialogueUtils::sm_vendorHurryUpTimeOut )
  {
    UFG::VendorDialogueUtils::PlayStoreClerkDialogue(eStoreClerkDialogueContext_HurryUp, 1.0);
    v4 = UFG::VendorDialogueUtils::sm_idleTime;
  }
  if ( UFG::VendorDialogueUtils::sm_playBrowse > 0 && v4 > 1.0 )
  {
    UFG::VendorDialogueUtils::PlayStoreClerkDialogue(eStoreClerkDialogueContext_Browse, 1.0);
    UFG::VendorDialogueUtils::sm_playBrowse = 0;
  }
  v5 = (hkpNullContactMgrFactory *)UFG::StoreFrontTracker::Instance();
  if ( v5 )
    v9 = (UFG::StoreFront *)hkpNullContactMgrFactory::createContactMgr(v5, v6, v7, v8);
  else
    v9 = 0i64;
  if ( LocalPlayer )
  {
    v10 = UFG::SimObject::GetComponentOfType(
            (UFG::SimObject *)&LocalPlayer->vfptr,
            UFG::CharacterLookComponent::_TypeUID);
    if ( v10 )
    {
      HIDWORD(v10[2].m_BoundComponentHandles.mNode.mNext) = 0;
      UFG::CompositeLookComponent::ForceVisibleTransparency((UFG::CompositeLookComponent *)v10);
    }
  }
  if ( !v3->mInfoTickerTextSet )
  {
    pargs.pObjectInterface = 0i64;
    pargs.Type = 0;
    v11 = UFG::OSuiteTickerManager::Instance();
    v12 = UFG::OSuiteTickerManager::GetTickerDescription(v11, 1i64, 0);
    pargs.Type = 6;
    *(_QWORD *)&pargs.mValue.NValue = v12;
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
  if ( UFG::UIHKTweakables::WardrobeTuneCamera && v9 )
  {
    if ( v3->mState == 1 )
    {
      v13 = 1;
    }
    else
    {
      if ( v3->mState != 2 )
        return;
      v13 = 2;
    }
    UFG::UIHKScreenWardrobe::SetStoreCamera(v3, v9, v13, a3);
  }
}

// File Line: 1037
// RVA: 0x5FF000
void UFG::UIHKScreenWardrobe::QueuePush(void)
{
  UFG::UIScreenTextureManager *v0; // rax

  v0 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::QueueLoadAndPush(v0, "Wardrobe", 0i64);
}

// File Line: 1043
// RVA: 0x5D7B60
void __fastcall UFG::UIHKScreenWardrobe::Exit(UFG::UIHKScreenWardrobe *this)
{
  UFG::UIHKScreenWardrobe *v1; // rbx
  bool v2; // zf
  unsigned int v3; // edx

  v1 = this;
  Scaleform::GFx::Movie::Invoke(this->mRenderable->m_movie.pObject, "Animate_Outro", 0i64, 0i64, 0);
  v2 = v1->mIsStore == 0;
  v1->mState = 8;
  if ( v2 )
  {
    if ( UFG::HudAudio::m_instance )
    {
      v3 = 612995759;
      goto LABEL_6;
    }
  }
  else if ( UFG::HudAudio::m_instance )
  {
    v3 = 1844627606;
LABEL_6:
    UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr, v3, 0i64, 0, 0i64);
    goto LABEL_7;
  }
LABEL_7:
  Render::EnableLightLayer(0x30ACCAD6u, 0);
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

// File Line: 1064
// RVA: 0x5E8F90
__int64 __fastcall UFG::UIHKScreenWardrobe::GetSelectedIndex(UFG::UIHKScreenWardrobe *this)
{
  UFG::UIHKScreenWardrobe *v1; // rdi
  Scaleform::GFx::Movie *v2; // rcx
  unsigned int v4; // ebx
  Scaleform::GFx::Value pval; // [rsp+28h] [rbp-40h]

  v1 = this;
  v2 = this->mRenderable->m_movie.pObject;
  if ( !v2 )
    return 0i64;
  pval.pObjectInterface = 0i64;
  pval.Type = 0;
  Scaleform::GFx::Movie::GetVariable(v2, &pval, "SelectedIndex");
  v4 = (signed int)pval.mValue.NValue;
  if ( (signed int)pval.mValue.NValue >= v1->mNumItems )
    v4 = 0;
  if ( ((unsigned int)pval.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pval.pObjectInterface->vfptr->gap8[8])(
      pval.pObjectInterface,
      &pval,
      *(_QWORD *)&pval.mValue.NValue);
    pval.pObjectInterface = 0i64;
  }
  return v4;
}

// File Line: 1083
// RVA: 0x5E9350
__int64 __fastcall UFG::UIHKScreenWardrobe::GetSelectedTrackerIndex(UFG::UIHKScreenWardrobe *this)
{
  Scaleform::GFx::Movie *v1; // rcx
  unsigned int v3; // ebx
  Scaleform::GFx::Value pval; // [rsp+28h] [rbp-40h]

  v1 = this->mRenderable->m_movie.pObject;
  if ( !v1 )
    return 0i64;
  pval.pObjectInterface = 0i64;
  pval.Type = 0;
  Scaleform::GFx::Movie::GetVariable(v1, &pval, "TrackerIndex");
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

// File Line: 1098
// RVA: 0x5FE3F0
void __fastcall UFG::UIHKScreenWardrobe::PreviewOutfit(UFG::UIHKScreenWardrobe *this)
{
  UFG::UIHKScreenWardrobe *v1; // rbx
  hkpNullContactMgrFactory *v2; // rax
  hkpCollidable *v3; // rdx
  hkpCollidable *v4; // r8
  hkpCollisionInput *v5; // r9
  UFG::StoreFront::OutfitNum v6; // eax

  v1 = this;
  v2 = (hkpNullContactMgrFactory *)UFG::StoreFrontTracker::Instance();
  if ( v2 )
  {
    if ( hkpNullContactMgrFactory::createContactMgr(v2, v3, v4, v5) )
    {
      v6 = (unsigned int)UFG::UIHKScreenWardrobe::GetSelectedIndex(v1);
      UFG::StoreFront::EquipCustomOutfit(v6, 0, 1);
    }
  }
}

// File Line: 1110
// RVA: 0x602D60
void __fastcall UFG::UIHKScreenWardrobe::RestoreNonPurchasedEquipment(UFG::UIHKScreenWardrobe *this, bool isOutfit)
{
  bool v2; // r15
  UFG::UIHKScreenWardrobe *v3; // r14
  hkpNullContactMgrFactory *v4; // rax
  hkpCollidable *v5; // rdx
  hkpCollidable *v6; // r8
  hkpCollisionInput *v7; // r9
  UFG::GameStatTracker *v8; // rbx
  UFG::StoreFrontTracker *v9; // rax
  UFG::qPropertySet *v10; // rbx
  hkpNullContactMgrFactory *v11; // rax
  hkpCollidable *v12; // rdx
  hkpCollidable *v13; // r8
  hkpCollisionInput *v14; // r9
  UFG::qSymbol *v15; // rbx
  signed __int64 v16; // rsi
  UFG::StoreFrontTracker *v17; // rax
  UFG::qPropertySet *v18; // rdi
  hkpNullContactMgrFactory *v19; // rax
  hkpCollidable *v20; // rdx
  hkpCollidable *v21; // r8
  hkpCollisionInput *v22; // r9
  Scaleform::GFx::Movie *v23; // rbx
  void (__fastcall *pDtor)(void *); // [rsp+20h] [rbp-21h]
  __int64 v25; // [rsp+30h] [rbp-11h]
  unsigned int v26; // [rsp+38h] [rbp-9h]
  __int64 v27; // [rsp+40h] [rbp-1h]
  unsigned int ptr; // [rsp+50h] [rbp+Fh]
  unsigned int v29; // [rsp+54h] [rbp+13h]
  unsigned int v30; // [rsp+58h] [rbp+17h]
  unsigned int v31; // [rsp+5Ch] [rbp+1Bh]
  unsigned int v32; // [rsp+60h] [rbp+1Fh]
  unsigned int v33; // [rsp+64h] [rbp+23h]
  unsigned int v34; // [rsp+68h] [rbp+27h]
  unsigned int v35; // [rsp+6Ch] [rbp+2Bh]
  unsigned int v36; // [rsp+70h] [rbp+2Fh]
  unsigned int v37; // [rsp+74h] [rbp+33h]
  unsigned int v38; // [rsp+78h] [rbp+37h]

  v2 = isOutfit;
  v3 = this;
  v4 = (hkpNullContactMgrFactory *)UFG::StoreFrontTracker::Instance();
  if ( v4 && hkpNullContactMgrFactory::createContactMgr(v4, v5, v6, v7) )
  {
    v8 = UFG::GameStatTracker::Instance();
    pDtor = (void (__fastcall *)(void *))_;
    `eh vector constructor iterator(&ptr, 4ui64, 14, (void (__fastcall *)(void *))BackInfo::BackInfo);
    v29 = UFG::GameStatTracker::GetStat(v8, CurrentLowerBody)->mValue.mUID;
    v30 = UFG::GameStatTracker::GetStat(v8, CurrentFootwear)->mValue.mUID;
    v31 = UFG::GameStatTracker::GetStat(v8, CurrentHeadgear)->mValue.mUID;
    v32 = UFG::GameStatTracker::GetStat(v8, CurrentHead)->mValue.mUID;
    ptr = UFG::GameStatTracker::GetStat(v8, CurrentBody)->mValue.mUID;
    v33 = UFG::GameStatTracker::GetStat(v8, CurrentAccessories)->mValue.mUID;
    v34 = UFG::GameStatTracker::GetStat(v8, CurrentGlasses)->mValue.mUID;
    v35 = UFG::GameStatTracker::GetStat(v8, CurrentNeck)->mValue.mUID;
    v36 = UFG::GameStatTracker::GetStat(v8, CurrentLeftWrist)->mValue.mUID;
    v37 = UFG::GameStatTracker::GetStat(v8, CurrentRightWrist)->mValue.mUID;
    v38 = UFG::GameStatTracker::GetStat(v8, CurrentOutfit)->mValue.mUID;
    if ( v3->mInitClothing[10].mUID == -1 )
    {
      v15 = v3->mInitClothing;
      v16 = 14i64;
      do
      {
        v17 = UFG::StoreFrontTracker::Instance();
        v18 = UFG::StoreFrontTracker::FindItemSlow(v17, v15);
        if ( v18 )
        {
          v19 = (hkpNullContactMgrFactory *)UFG::StoreFrontTracker::Instance();
          if ( v19 )
          {
            if ( hkpNullContactMgrFactory::createContactMgr(v19, v20, v21, v22) )
              UFG::StoreFront::EquipItem(v18, 1, 0, 1, 0, 0);
          }
        }
        ++v15;
        --v16;
      }
      while ( v16 );
    }
    else
    {
      v9 = UFG::StoreFrontTracker::Instance();
      v10 = UFG::StoreFrontTracker::FindItemSlow(v9, &v3->mInitClothing[10]);
      if ( v10 )
      {
        v11 = (hkpNullContactMgrFactory *)UFG::StoreFrontTracker::Instance();
        if ( v11 )
        {
          if ( hkpNullContactMgrFactory::createContactMgr(v11, v12, v13, v14) )
            UFG::StoreFront::EquipItem(v10, 1, 0, 1, 0, 0);
        }
      }
    }
    UFG::StoreMeshHelper::QueueSwapping((UFG::SimObject *)&LocalPlayer->vfptr);
    v23 = v3->mRenderable->m_movie.pObject;
    if ( v23 )
    {
      v25 = 0i64;
      v26 = 0;
      v26 = 2;
      LOBYTE(v27) = v2;
      Scaleform::GFx::Movie::SetVariable(v23, "mOutfitSave", (Scaleform::GFx::Value *)&pDtor, 1i64);
      if ( (v26 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, void (__fastcall **)(void *), __int64))(*(_QWORD *)v25 + 16i64))(
          v25,
          &pDtor,
          v27);
        v25 = 0i64;
      }
      v26 = 0;
    }
    `eh vector destructor iterator(&ptr, 4ui64, 14, (void (__fastcall *)(void *))_);
  }
}

// File Line: 1178
// RVA: 0x603420
void __fastcall UFG::UIHKScreenWardrobe::SaveCurrentClothingAsOutfit(UFG::UIHKScreenWardrobe *this, UFG::StoreFront::OutfitNum eOutfitNum)
{
  UFG::StoreFront::OutfitNum v2; // er15
  UFG::UIHKScreenWardrobe *v3; // r13
  UFG::GameStatTracker *v4; // r14
  UFG::PersistentData::ID *v5; // r12
  UFG::GameStatTracker *v6; // rbx
  UFG::StoreFront::OutfitNum v7; // ebx
  UFG::GameStatTracker *v8; // rdi
  unsigned int v9; // esi
  _FILETIME v10; // rax
  Scaleform::GFx::Movie *v11; // rbx
  Scaleform::GFx::Value value; // [rsp+20h] [rbp-59h]
  UFG::PersistentData::ID *v13; // [rsp+50h] [rbp-29h]
  UFG::PersistentData::ID *v14; // [rsp+58h] [rbp-21h]
  UFG::PersistentData::ID *v15; // [rsp+60h] [rbp-19h]
  UFG::PersistentData::ID *v16; // [rsp+68h] [rbp-11h]
  UFG::PersistentData::ID *v17; // [rsp+70h] [rbp-9h]
  UFG::PersistentData::ID *v18; // [rsp+78h] [rbp-1h]
  UFG::PersistentData::ID *v19; // [rsp+80h] [rbp+7h]
  __int64 v20; // [rsp+88h] [rbp+Fh]
  UFG::qSymbol name; // [rsp+E0h] [rbp+67h]
  UFG::qSymbol v22; // [rsp+E8h] [rbp+6Fh]
  UFG::qWiseSymbol result; // [rsp+F0h] [rbp+77h]
  UFG::PersistentData::ID *v24; // [rsp+F8h] [rbp+7Fh]

  v20 = -2i64;
  v2 = eOutfitNum;
  v3 = this;
  v4 = UFG::GameStatTracker::Instance();
  v5 = UFG::GameStatTracker::GetStat(v4, CurrentHeadgear);
  v24 = UFG::GameStatTracker::GetStat(v4, CurrentBody);
  v17 = UFG::GameStatTracker::GetStat(v4, CurrentLowerBody);
  v18 = UFG::GameStatTracker::GetStat(v4, CurrentFootwear);
  v15 = UFG::GameStatTracker::GetStat(v4, CurrentGlasses);
  v19 = UFG::GameStatTracker::GetStat(v4, CurrentNeck);
  v13 = UFG::GameStatTracker::GetStat(v4, CurrentLeftWrist);
  v14 = UFG::GameStatTracker::GetStat(v4, CurrentRightWrist);
  v16 = UFG::GameStatTracker::GetStat(v4, CurrentAccessories);
  v6 = UFG::GameStatTracker::Instance();
  name.mUID = -1;
  name.mUID = UFG::qSymbol::qSymbol(&result, v2 + 1)->mUID;
  if ( !(unsigned int)UFG::GameStatTracker::GetStat(v6, Outfits_Body, &name) )
  {
    v7 = 0;
    while ( 1 )
    {
      v8 = UFG::GameStatTracker::Instance();
      name.mUID = -1;
      v9 = v7 + 1;
      name.mUID = UFG::qSymbol::qSymbol(&result, v7 + 1)->mUID;
      if ( !(unsigned int)UFG::GameStatTracker::GetStat(v8, Outfits_Body, &name) )
        break;
      ++v7;
      if ( v9 >= 5 )
        goto LABEL_7;
    }
    v2 = v7;
  }
LABEL_7:
  v22.mUID = -1;
  v22.mUID = UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&name, v2 + 1)->mUID;
  UFG::GameStatTracker::SetStat(v4, Outfits_Headgear, &v22, v5->mValue.mUID);
  UFG::GameStatTracker::SetStat(v4, Outfits_Body, &v22, v24->mValue.mUID);
  UFG::GameStatTracker::SetStat(v4, Outfits_LowerBody, &v22, v17->mValue.mUID);
  UFG::GameStatTracker::SetStat(v4, Outfits_Footwear, &v22, v18->mValue.mUID);
  UFG::GameStatTracker::SetStat(v4, Outfits_Glasses, &v22, v15->mValue.mUID);
  UFG::GameStatTracker::SetStat(v4, Outfits_Neck, &v22, v19->mValue.mUID);
  UFG::GameStatTracker::SetStat(v4, Outfits_LeftWrist, &v22, v13->mValue.mUID);
  UFG::GameStatTracker::SetStat(v4, Outfits_RightWrist, &v22, v14->mValue.mUID);
  UFG::GameStatTracker::SetStat(v4, Outfits_Accessories, &v22, v16->mValue.mUID);
  v10 = UFG::qGetSystemTime();
  UFG::GameStatTracker::SetStat(v4, 0, &v22, *(_QWORD *)&v10);
  v11 = v3->mRenderable->m_movie.pObject;
  if ( v11 )
  {
    value.pObjectInterface = 0i64;
    value.Type = 2;
    value.mValue.BValue = 0;
    Scaleform::GFx::Movie::SetVariable(v11, "mOutfitSave", &value, 1i64);
    if ( ((unsigned int)value.Type >> 6) & 1 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        *(_QWORD *)&value.mValue.NValue);
  }
}

// File Line: 1238
// RVA: 0x5EB550
void __fastcall UFG::UIHKScreenWardrobe::HandleOptionHighlighted(UFG::UIHKScreenWardrobe *this)
{
  UFG::UIHKScreenWardrobe *v1; // rbx
  hkpNullContactMgrFactory *v2; // rax
  hkpCollidable *v3; // rdx
  hkpCollidable *v4; // r8
  hkpCollisionInput *v5; // r9
  UFG::StoreFront *v6; // rax
  UFG::qPropertySet *v7; // rdi
  hkpNullContactMgrFactory *v8; // rax
  hkpCollidable *v9; // rdx
  hkpCollidable *v10; // r8
  hkpCollisionInput *v11; // r9
  hkpNullContactMgrFactory *v12; // rax
  hkpCollidable *v13; // rdx
  hkpCollidable *v14; // r8
  hkpCollisionInput *v15; // r9

  v1 = this;
  if ( this->mNumItems )
  {
    this->mSelectedIndex = UFG::UIHKScreenWardrobe::GetSelectedIndex(this);
    v2 = (hkpNullContactMgrFactory *)UFG::StoreFrontTracker::Instance();
    if ( v2 )
    {
      v6 = (UFG::StoreFront *)hkpNullContactMgrFactory::createContactMgr(v2, v3, v4, v5);
      if ( v6 )
      {
        if ( v1->mSelectedCategory == 11 )
        {
          UFG::StoreFront::EquipCustomOutfit((UFG::StoreFront::OutfitNum)v1->mSelectedIndex, 0, 1);
        }
        else
        {
          v7 = UFG::StoreFront::GetItem(v6, v1->mSelectedIndex);
          v8 = (hkpNullContactMgrFactory *)UFG::StoreFrontTracker::Instance();
          if ( v8 && hkpNullContactMgrFactory::createContactMgr(v8, v9, v10, v11) )
          {
            v12 = (hkpNullContactMgrFactory *)UFG::StoreFrontTracker::Instance();
            if ( v12 )
              hkpNullContactMgrFactory::createContactMgr(v12, v13, v14, v15);
            UFG::StoreFront::EquipItem(v7, 0, 1, 1, 0, 1);
          }
        }
      }
    }
    if ( v1->mIsStore )
    {
      UFG::VendorDialogueUtils::sm_playBrowse = 1;
      UFG::VendorDialogueUtils::sm_idleTime = 0.0;
    }
  }
}

// File Line: 1290
// RVA: 0x5D74F0
void __fastcall UFG::UIHKScreenWardrobe::EquipItem(UFG::UIHKScreenWardrobe *this, UFG::qPropertySet *a_pItem, bool bSaveAsRestore, bool bRefreshPlayer, bool bRemoveAnyOutfit, bool bUpdateLastEquipItem, bool bRestoringPreviousClothes)
{
  bool v7; // r14
  bool v8; // bp
  UFG::qPropertySet *v9; // rsi
  UFG::UIHKScreenWardrobe *v10; // rdi
  hkpNullContactMgrFactory *v11; // rax
  hkpCollidable *v12; // rdx
  hkpCollidable *v13; // r8
  hkpCollisionInput *v14; // r9
  UFG::StoreFront *v15; // rbx
  int v16; // ebx
  UFG::GameStatTracker *v17; // rax
  UFG::StoreFrontTracker *v18; // rax
  UFG::qPropertySet *v19; // rax
  char *v20; // rax
  UFG::qSymbol result; // [rsp+30h] [rbp-18h]

  v7 = bRefreshPlayer;
  v8 = bSaveAsRestore;
  v9 = a_pItem;
  v10 = this;
  v11 = (hkpNullContactMgrFactory *)UFG::StoreFrontTracker::Instance();
  if ( v11 )
  {
    v15 = (UFG::StoreFront *)hkpNullContactMgrFactory::createContactMgr(v11, v12, v13, v14);
    if ( v15 )
    {
      UFG::StoreFront::EquipItem(v9, 1, v7, 1, bUpdateLastEquipItem, 0);
      if ( !bRestoringPreviousClothes )
      {
        UFG::StoreFront::GetClothingBuffFromItem(v15, &result, v9);
        if ( result.mUID != -1 )
        {
          v16 = UFG::StoreFront::LookupClothingBuff(&result);
          if ( v16 )
          {
            v17 = UFG::GameStatTracker::Instance();
            if ( (unsigned int)UFG::GameStatTracker::GetStat(v17, ClothingSetBuff) == v16 )
            {
              v18 = UFG::StoreFrontTracker::Instance();
              v19 = UFG::StoreFrontTracker::FindClothingSetSlow(v18, &result);
              if ( v19 )
              {
                v20 = PropertyUtils::Get<char const *>(
                        v19,
                        (UFG::qSymbol *)&UFG::ClothingSetSymbol_ActiveDesc.mUID,
                        DEPTH_RECURSE);
                if ( v20 )
                  UFG::UIScreenDialogBox::createOKDialog((UFG::UIScreen *)&v10->vfptr, &customWorldMapCaption, v20, 0);
              }
            }
          }
        }
      }
      if ( v8 )
        UFG::UIHKScreenWardrobe::SaveCurrentClothingAsRestore(v10);
    }
  }
}

// File Line: 1334
// RVA: 0x5EB630
void __fastcall UFG::UIHKScreenWardrobe::HandleOptionSelected(UFG::UIHKScreenWardrobe *this)
{
  UFG::UIHKScreenWardrobe *v1; // rdi
  int v2; // ebp
  int v3; // ebx
  hkpNullContactMgrFactory *v4; // rax
  hkpCollidable *v5; // rdx
  hkpCollidable *v6; // r8
  hkpCollisionInput *v7; // r9
  UFG::StoreFront *v8; // rax
  UFG::StoreFront *v9; // rsi
  UFG::qPropertySet *v10; // rax
  UFG::qPropertySet *v11; // r14
  unsigned int *v12; // rax
  unsigned int *v13; // rcx
  unsigned int v14; // ebx
  UFG::GameStatTracker *v15; // rax
  UFG::qString v16; // [rsp+58h] [rbp-40h]
  int v17; // [rsp+A0h] [rbp+8h]

  v1 = this;
  if ( this->mNumItems )
  {
    v2 = UFG::UIHKScreenWardrobe::GetSelectedTrackerIndex(this);
    v3 = UFG::UIHKScreenWardrobe::GetSelectedIndex(v1);
    v4 = (hkpNullContactMgrFactory *)UFG::StoreFrontTracker::Instance();
    if ( v4 )
    {
      v8 = (UFG::StoreFront *)hkpNullContactMgrFactory::createContactMgr(v4, v5, v6, v7);
      v9 = v8;
      if ( v8 )
      {
        v10 = UFG::StoreFront::GetItem(v8, v3);
        v11 = v10;
        v17 = 0;
        v12 = UFG::qPropertySet::Get<unsigned long>(
                v10,
                (UFG::qSymbol *)&UFG::StoreItemSymbol_FaceRequired.mUID,
                DEPTH_RECURSE);
        v13 = (unsigned int *)&v17;
        if ( v12 )
          v13 = v12;
        v14 = *v13;
        v15 = UFG::GameStatTracker::Instance();
        if ( v14 <= (unsigned int)UFG::GameStatTracker::GetFaceLevel(v15) )
        {
          if ( UFG::StoreFront::IsOwned(v9, v2) )
          {
            UFG::UIHKScreenWardrobe::EquipItem(v1, v11, 1, 1, 1, 1, 0);
            UFG::UIHKScreenWardrobe::ShowCategorySelect(v1);
          }
          else if ( UFG::StoreFront::CanPurchase(v9, v2) || UFG::UIHKTweakables::WardrobeDebugFreeClothes )
          {
            UFG::UIScreenDialogBox::createTwoButtonDialog(
              (UFG::UIScreen *)&v1->vfptr,
              &customWorldMapCaption,
              "$STORE_PURCHASE_ITEM",
              "$STORE_PURCHASE_WEAR",
              UI_HASH_PURCHASE_AND_EQUIP_ITEM,
              "$CANCEL",
              UI_HASH_CANCEL_30,
              DIALOG_BUTTON1,
              0,
              "DialogBox");
          }
          else
          {
            UFG::qString::qString(&v16, "$COMMON_OK_UPPERCASE");
            UFG::UIScreenDialogBox::createOneButtonDialog(
              (UFG::UIScreen *)&v1->vfptr,
              &customWorldMapCaption,
              "$STORE_INSUFFICIENT_MONEY",
              v16.mData,
              UI_HASH_DIALOG_OK_30,
              0,
              "DialogBox");
            UFG::qString::~qString(&v16);
            UFG::VendorDialogueUtils::PlayStoreClerkDialogue(eStoreClerkDialogueContext_NoMoney, 1.0);
          }
        }
        else
        {
          UFG::qString::qString(&v16, "$COMMON_OK_UPPERCASE");
          UFG::UIScreenDialogBox::createOneButtonDialog(
            (UFG::UIScreen *)&v1->vfptr,
            &customWorldMapCaption,
            "$WARDROBE_FACE_TOO_LOW",
            v16.mData,
            UI_HASH_DIALOG_OK_30,
            0,
            "DialogBox");
          UFG::qString::~qString(&v16);
          v1->mState = 6;
        }
      }
    }
  }
}

// File Line: 1383
// RVA: 0x5EE150
bool __fastcall UFG::UIHKScreenWardrobe::IsCustomOutfitSlotInUse(UFG::UIHKScreenWardrobe *this, UFG::StoreFront::OutfitNum eOutFitNum)
{
  UFG::StoreFront::OutfitNum v2; // ebx
  UFG::GameStatTracker *v3; // rax
  UFG::GameStatTracker *v4; // rdi
  UFG::qSymbol name; // [rsp+38h] [rbp+10h]
  UFG::qWiseSymbol result; // [rsp+40h] [rbp+18h]

  v2 = eOutFitNum;
  v3 = UFG::GameStatTracker::Instance();
  name.mUID = -1;
  v4 = v3;
  name.mUID = UFG::qSymbol::qSymbol(&result, v2 + 1)->mUID;
  return (unsigned int)UFG::GameStatTracker::GetStat(v4, Outfits_Body, &name) != 0;
}

// File Line: 1400
// RVA: 0x5F6140
void __fastcall UFG::UIHKScreenWardrobe::PopulateCustomOutfits(UFG::UIHKScreenWardrobe *this)
{
  UFG::UIHKScreenWardrobe *v1; // rsi
  Scaleform::GFx::Movie *v2; // r14
  UFG::GameStatTracker *v3; // r12
  unsigned int v4; // edi
  signed __int64 v5; // r15
  UFG::GameStatTracker *v6; // rbx
  unsigned int v7; // eax
  UFG::UIGfxTranslator *v8; // rcx
  const char *v9; // rax
  unsigned __int64 v10; // rax
  unsigned int v11; // eax
  UFG::UIGfxTranslator *v12; // rcx
  const char *v13; // rax
  Scaleform::GFx::Value value; // [rsp+30h] [rbp-D0h]
  char ptr; // [rsp+60h] [rbp-A0h]
  __int64 v16; // [rsp+70h] [rbp-90h]
  unsigned int v17; // [rsp+78h] [rbp-88h]
  __int64 v18; // [rsp+80h] [rbp-80h]
  __int64 v19; // [rsp+90h] [rbp-70h]
  UFG::qString v20; // [rsp+98h] [rbp-68h]
  UFG::UIHKWardrobeItemInfo info; // [rsp+C0h] [rbp-40h]
  UFG::qSymbol name; // [rsp+2D0h] [rbp+1D0h]
  UFG::qSymbol v23; // [rsp+2D8h] [rbp+1D8h]
  UFG::qWiseSymbol result; // [rsp+2E0h] [rbp+1E0h]
  UFG::qWiseSymbol v25; // [rsp+2E8h] [rbp+1E8h]

  v19 = -2i64;
  v1 = this;
  v2 = this->mRenderable->m_movie.pObject;
  if ( v2 )
  {
    Scaleform::GFx::Movie::Invoke(v2, "gWardrobeList.Clear", 0i64, 0i64, 0);
    value.pObjectInterface = 0i64;
    value.Type = 2;
    value.mValue.BValue = 0;
    Scaleform::GFx::Movie::SetVariable(v2, "mc_Money._visible", &value, 1i64);
    v3 = UFG::GameStatTracker::Instance();
    v4 = 1;
    v5 = 5i64;
    do
    {
      UFG::UIHKWardrobeItemInfo::UIHKWardrobeItemInfo(&info);
      v6 = UFG::GameStatTracker::Instance();
      name.mUID = -1;
      name.mUID = UFG::qSymbol::qSymbol(&result, v4)->mUID;
      if ( (unsigned int)UFG::GameStatTracker::GetStat(v6, Outfits_Body, &name) )
      {
        v7 = UFG::qStringHashUpper32("STORE_OUTFIT_NUM", 0xFFFFFFFF);
        v8 = UFG::UIScreenManager::s_instance->m_translator;
        if ( !v8
          || (v9 = (const char *)v8->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v8->vfptr, v7)) == 0i64 )
        {
          v9 = "STORE_OUTFIT_NUM";
        }
        UFG::qString::Format(&info.title, v9, v4);
        v23.mUID = -1;
        v23.mUID = UFG::qSymbol::qSymbol(&v25, v4)->mUID;
        v10 = UFG::GameStatTracker::GetStat(v3, 0, &v23);
        UFG::UI::GetDateString(&v20, v10, 1);
        v11 = UFG::qStringHashUpper32("STORE_OUTFIT_SAVED_DATE", 0xFFFFFFFF);
        v12 = UFG::UIScreenManager::s_instance->m_translator;
        if ( !v12
          || (v13 = (const char *)v12->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v12->vfptr, v11)) == 0i64 )
        {
          v13 = "STORE_OUTFIT_SAVED_DATE";
        }
        UFG::qString::Format(&info.description, v13, v20.mData);
        UFG::qString::~qString(&v20);
      }
      else
      {
        UFG::qString::Set(&info.title, "$STORE_EMPTY_SLOT");
        UFG::qString::Set(&info.description, "$STORE_EMPTY_DATE");
      }
      info.bodyLocation = v1->mSelectedCategory;
      info.isOutfit = 1;
      ++v1->mNumItems;
      info.trackerIndex = v4 - 1;
      UFG::UIHKScreenWardrobe::Flash_AddItem(v1, &info);
      UFG::qString::~qString(&info.itemBuffSetDesc);
      UFG::qString::~qString(&info.itemBuffSetIcon);
      UFG::qString::~qString(&info.itemBuffSetTitle);
      UFG::qString::~qString(&info.discountPercentStr);
      UFG::qString::~qString(&info.clothingBuffSetDesc);
      UFG::qString::~qString(&info.clothingBuffSetIcon);
      UFG::qString::~qString(&info.clothingBuffSetTitle);
      UFG::qString::~qString(&info.brand);
      UFG::qString::~qString(&info.description);
      UFG::qString::~qString(&info.title);
      ++v4;
      --v5;
    }
    while ( v5 );
    `eh vector constructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( (v17 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v16 + 16i64))(v16, &ptr, v18);
      v16 = 0i64;
    }
    v17 = 5;
    v18 = 0i64;
    Scaleform::GFx::Movie::Invoke(v2, "gWardrobeList.SetSelectedIndex", 0i64, (Scaleform::GFx::Value *)&ptr, 1u);
    Scaleform::GFx::Movie::Invoke(v2, "WardrobeList_Refresh", 0i64, 0i64, 0);
    `eh vector destructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    if ( ((unsigned int)value.Type >> 6) & 1 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        *(_QWORD *)&value.mValue.NValue);
  }
}

// File Line: 1460
// RVA: 0x5F7A30
void __fastcall UFG::UIHKScreenWardrobe::PopulateInventory(UFG::UIHKScreenWardrobe *this)
{
  UFG::UIHKScreenWardrobe *v1; // r14
  hkpNullContactMgrFactory *v2; // rax
  hkpCollidable *v3; // rdx
  hkpCollidable *v4; // r8
  hkpCollisionInput *v5; // r9
  UFG::StoreFront *v6; // r13
  Scaleform::GFx::Movie *v7; // rdi
  unsigned int v8; // er12
  UFG::UIHKScreenWardrobe::eHelpBarState v9; // edx
  signed int v10; // esi
  unsigned int v11; // ebx
  UFG::GameStatTracker *v12; // rax
  UFG::GameStat::IDStat v13; // edx
  unsigned int v14; // er15
  UFG::qPropertySet *v15; // rax
  UFG::qPropertySet *v16; // rdi
  char *v17; // rax
  char *v18; // rax
  char *v19; // rsi
  char *v20; // rax
  unsigned int *v21; // rax
  UFG::qWiseSymbol *v22; // rcx
  unsigned int v23; // esi
  UFG::GameStatTracker *v24; // rax
  unsigned int v25; // eax
  unsigned int v26; // eax
  UFG::UIGfxTranslator *v27; // rcx
  const char *v28; // rax
  unsigned int v29; // eax
  UFG::UIGfxTranslator *v30; // rcx
  const char *v31; // rax
  UFG::StoreFrontTracker *v32; // rax
  UFG::qPropertySet *v33; // rax
  UFG::qPropertySet *v34; // rsi
  char *v35; // rax
  char *v36; // rax
  char *v37; // rax
  UFG::StoreFrontTracker *v38; // rax
  UFG::qPropertySet *v39; // rax
  UFG::qPropertySet *v40; // rdi
  char *v41; // rax
  char *v42; // r15
  char *v43; // rax
  char *v44; // rsi
  char *v45; // rax
  char *v46; // rdi
  bool v47; // bl
  unsigned int v48; // [rsp+30h] [rbp-D0h]
  Scaleform::GFx::Value value; // [rsp+38h] [rbp-C8h]
  char ptr; // [rsp+68h] [rbp-98h]
  __int64 v51; // [rsp+78h] [rbp-88h]
  unsigned int v52; // [rsp+80h] [rbp-80h]
  double v53; // [rsp+88h] [rbp-78h]
  UFG::qWiseSymbol *v54; // [rsp+98h] [rbp-68h]
  Scaleform::GFx::Movie *v55; // [rsp+A0h] [rbp-60h]
  UFG::qSymbol v56; // [rsp+A8h] [rbp-58h]
  UFG::qSymbol v57; // [rsp+ACh] [rbp-54h]
  __int64 v58; // [rsp+B0h] [rbp-50h]
  UFG::UIHKWardrobeItemInfo info; // [rsp+C0h] [rbp-40h]
  UFG::qSymbol clothingSetName; // [rsp+2C8h] [rbp+1C8h]
  UFG::qWiseSymbol result; // [rsp+2D0h] [rbp+1D0h]
  int v62; // [rsp+2D8h] [rbp+1D8h]

  v58 = -2i64;
  v1 = this;
  v2 = (hkpNullContactMgrFactory *)UFG::StoreFrontTracker::Instance();
  if ( v2 )
  {
    v6 = (UFG::StoreFront *)hkpNullContactMgrFactory::createContactMgr(v2, v3, v4, v5);
    if ( v6 )
    {
      v7 = v1->mRenderable->m_movie.pObject;
      v55 = v7;
      if ( v7 )
      {
        v8 = 0;
        if ( v1->mIsStore )
        {
          UFG::UIHKScreenWardrobe::UpdateMoney(v1);
          UFG::UIHKScreenWardrobe::ShowHelpBar(v1, HELP_SELECT_ITEM_RACE);
        }
        else
        {
          value.pObjectInterface = 0i64;
          value.Type = 2;
          value.mValue.BValue = 0;
          Scaleform::GFx::Movie::SetVariable(v7, "mc_Money._visible", &value, 1i64);
          v9 = 4;
          if ( v1->mSelectedCategory != 10 )
            v9 = 3;
          UFG::UIHKScreenWardrobe::ShowHelpBar(v1, v9);
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
        Scaleform::GFx::Movie::Invoke(v7, "gWardrobeList.Clear", 0i64, 0i64, 0);
        UFG::StoreFront::SetCurrentCategory(v6, v1->mSelectedCategory);
        v10 = v1->mSelectedIndex;
        v62 = v1->mSelectedIndex;
        v11 = -1;
        UFG::qSymbol::qSymbol(&result, 0);
        v12 = UFG::GameStatTracker::Instance();
        switch ( v1->mSelectedCategory )
        {
          case 0:
            v13 = 15;
            goto LABEL_22;
          case 1:
            v13 = 18;
            goto LABEL_22;
          case 2:
            v13 = 19;
            goto LABEL_22;
          case 3:
            v13 = 11;
            goto LABEL_22;
          case 5:
            v13 = 20;
            goto LABEL_22;
          case 6:
            v13 = 13;
            goto LABEL_22;
          case 7:
            v13 = 14;
            goto LABEL_22;
          case 8:
            v13 = 16;
            goto LABEL_22;
          case 9:
            v13 = 17;
            goto LABEL_22;
          case 0xA:
            v13 = 21;
LABEL_22:
            v11 = UFG::GameStatTracker::GetStat(v12, v13)->mValue.mUID;
            break;
          default:
            break;
        }
        clothingSetName.mUID = -1;
        v14 = UFG::StoreFront::GetNumItems(v6);
        v48 = v14;
        v1->mNumItems = 0;
        if ( v14 )
        {
          do
          {
            UFG::UIHKWardrobeItemInfo::UIHKWardrobeItemInfo(&info);
            v15 = UFG::StoreFront::GetItem(v6, v8);
            v16 = v15;
            if ( v15 )
            {
              if ( v15->mName.mUID == v11 )
              {
                if ( !v1->mIsStore )
                  v10 = v8;
                v62 = v10;
                info.is_equipped = 1;
              }
              v17 = PropertyUtils::Get<char const *>(
                      v15,
                      (UFG::qSymbol *)&UFG::StoreItemSymbol_Title.mUID,
                      DEPTH_RECURSE);
              if ( v17 )
                UFG::qString::Set(&info.title, v17);
              v18 = PropertyUtils::Get<char const *>(
                      v16,
                      (UFG::qSymbol *)&UFG::StoreItemSymbol_Brand.mUID,
                      DEPTH_RECURSE);
              v19 = v18;
              if ( v18 && (signed int)UFG::qStringLength(v18) > 0 )
                UFG::qString::Format(&info.brand, "clothingBrand_%s", v19);
              v20 = PropertyUtils::Get<char const *>(
                      v16,
                      (UFG::qSymbol *)&UFG::StoreItemSymbol_Description.mUID,
                      DEPTH_RECURSE);
              if ( v20 )
                UFG::qString::Set(&info.description, v20);
              info.price = (signed int)UFG::StoreFrontTracker::GetItemPriceWithoutDiscount(v16);
              info.discountPrice = (signed int)UFG::StoreFrontTracker::GetItemPriceBasedOnClothes(v16);
              info.discountPercent = (signed int)UFG::StoreFrontTracker::GetDiscount();
              result.mUID = 0;
              v21 = UFG::qPropertySet::Get<unsigned long>(
                      v16,
                      (UFG::qSymbol *)&UFG::StoreItemSymbol_FaceRequired.mUID,
                      DEPTH_RECURSE);
              v22 = &result;
              if ( v21 )
                v22 = (UFG::qWiseSymbol *)v21;
              v23 = v22->mUID;
              v24 = UFG::GameStatTracker::Instance();
              v25 = UFG::GameStatTracker::GetFaceLevel(v24);
              info.playerHasEnoughFace = v23 <= v25;
              if ( v23 > v25 )
              {
                v29 = UFG::qStringHashUpper32("WARDROBE_FACE_LEVEL", 0xFFFFFFFF);
                v30 = UFG::UIScreenManager::s_instance->m_translator;
                if ( !v30
                  || (v31 = (const char *)v30->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v30->vfptr, v29)) == 0i64 )
                {
                  v31 = "WARDROBE_FACE_LEVEL";
                }
                UFG::qString::Format(&info.discountPercentStr, v31, v23);
              }
              else if ( info.discountPercent )
              {
                UFG::qString::qString((UFG::qString *)&value);
                UFG::qString::Format((UFG::qString *)&value, "%d", info.discountPercent);
                v26 = UFG::qStringHashUpper32("WARDROBE_DISCOUNT_PERCENT", 0xFFFFFFFF);
                v27 = UFG::UIScreenManager::s_instance->m_translator;
                if ( !v27
                  || (v28 = (const char *)v27->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v27->vfptr, v26)) == 0i64 )
                {
                  v28 = "WARDROBE_DISCOUNT_PERCENT";
                }
                UFG::qString::Format(&info.discountPercentStr, v28, *(_QWORD *)&value.Type);
                UFG::qString::~qString((UFG::qString *)&value);
              }
              info.is_owned = UFG::StoreFront::IsOwned(v6, v8);
              info.bodyLocation = v1->mSelectedCategory;
              clothingSetName.mUID = UFG::StoreFront::GetItemBuffFromItem(v6, &v56, v16)->mUID;
              v32 = UFG::StoreFrontTracker::Instance();
              v33 = UFG::StoreFrontTracker::FindClothingSetSlow(v32, &clothingSetName);
              v34 = v33;
              if ( v33 )
              {
                v35 = PropertyUtils::Get<char const *>(
                        v33,
                        (UFG::qSymbol *)&UFG::ClothingSetSymbol_Title.mUID,
                        DEPTH_RECURSE);
                if ( v35 )
                  UFG::qString::Set(&info.itemBuffSetTitle, v35);
                v36 = PropertyUtils::Get<char const *>(
                        v34,
                        (UFG::qSymbol *)&UFG::ClothingSetSymbol_Icon.mUID,
                        DEPTH_RECURSE);
                if ( v36 )
                  UFG::qString::Set(&info.itemBuffSetIcon, v36);
                v37 = PropertyUtils::Get<char const *>(
                        v34,
                        (UFG::qSymbol *)&UFG::ClothingSetSymbol_Desc.mUID,
                        DEPTH_RECURSE);
                if ( v37 )
                  UFG::qString::Set(&info.itemBuffSetDesc, v37);
              }
              clothingSetName.mUID = UFG::StoreFront::GetClothingBuffFromItem(v6, &v57, v16)->mUID;
              v38 = UFG::StoreFrontTracker::Instance();
              v39 = UFG::StoreFrontTracker::FindClothingSetSlow(v38, &clothingSetName);
              v40 = v39;
              if ( v39 )
              {
                v41 = PropertyUtils::Get<char const *>(
                        v39,
                        (UFG::qSymbol *)&UFG::ClothingSetSymbol_Title.mUID,
                        DEPTH_RECURSE);
                v42 = v41;
                if ( v41 )
                  UFG::qString::Set(&info.clothingBuffSetTitle, v41);
                v43 = PropertyUtils::Get<char const *>(
                        v40,
                        (UFG::qSymbol *)&UFG::ClothingSetSymbol_Icon.mUID,
                        DEPTH_RECURSE);
                v44 = v43;
                if ( v43 )
                  UFG::qString::Set(&info.clothingBuffSetIcon, v43);
                v45 = PropertyUtils::Get<char const *>(
                        v40,
                        (UFG::qSymbol *)&UFG::ClothingSetSymbol_Desc.mUID,
                        DEPTH_RECURSE);
                v46 = v45;
                if ( v45 )
                  UFG::qString::Set(&info.clothingBuffSetDesc, v45);
                v54 = &result;
                result.mUID = clothingSetName.mUID;
                info.bHasClothingSetShoes = UFG::StoreFront::IsClothingSetItemOwned(
                                              v6,
                                              ItemCategory_FOOTWEAR,
                                              (__int64)&result);
                v54 = &result;
                result.mUID = clothingSetName.mUID;
                info.bHasClothingSetTorso = UFG::StoreFront::IsClothingSetItemOwned(v6, 0, (__int64)&result);
                v54 = &result;
                result.mUID = clothingSetName.mUID;
                info.bHasClothingSetPants = UFG::StoreFront::IsClothingSetItemOwned(
                                              v6,
                                              ItemCategory_LOWER_BODY,
                                              (__int64)&result);
                UFG::qPrintf("item is part of a clothing set %s, icon = %s, desc = %s\n", v42, v44, v46);
                v14 = v48;
              }
              ++v1->mNumItems;
              info.trackerIndex = v8;
              UFG::UIHKScreenWardrobe::Flash_AddItem(v1, &info);
              UFG::qString::~qString(&info.itemBuffSetDesc);
              UFG::qString::~qString(&info.itemBuffSetIcon);
              UFG::qString::~qString(&info.itemBuffSetTitle);
              UFG::qString::~qString(&info.discountPercentStr);
              UFG::qString::~qString(&info.clothingBuffSetDesc);
              UFG::qString::~qString(&info.clothingBuffSetIcon);
              UFG::qString::~qString(&info.clothingBuffSetTitle);
              UFG::qString::~qString(&info.brand);
              UFG::qString::~qString(&info.description);
              UFG::qString::~qString(&info.title);
              v10 = v62;
            }
            else
            {
              UFG::qString::~qString(&info.itemBuffSetDesc);
              UFG::qString::~qString(&info.itemBuffSetIcon);
              UFG::qString::~qString(&info.itemBuffSetTitle);
              UFG::qString::~qString(&info.discountPercentStr);
              UFG::qString::~qString(&info.clothingBuffSetDesc);
              UFG::qString::~qString(&info.clothingBuffSetIcon);
              UFG::qString::~qString(&info.clothingBuffSetTitle);
              UFG::qString::~qString(&info.brand);
              UFG::qString::~qString(&info.description);
              UFG::qString::~qString(&info.title);
            }
            ++v8;
          }
          while ( v8 < v14 );
          v7 = v55;
        }
        `eh vector constructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
        v47 = v1->mNumItems == 0;
        if ( (v52 >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v51 + 16i64))(
            v51,
            &ptr,
            COERCE_DOUBLE(*(_QWORD *)&v53));
          v51 = 0i64;
        }
        v52 = 2;
        LOBYTE(v53) = v47;
        Scaleform::GFx::Movie::Invoke(v7, "WardrobeList_SetIsEmpty", 0i64, (Scaleform::GFx::Value *)&ptr, 1u);
        if ( (v52 >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v51 + 16i64))(
            v51,
            &ptr,
            COERCE_DOUBLE(*(_QWORD *)&v53));
          v51 = 0i64;
        }
        v52 = 5;
        v53 = (double)v10;
        Scaleform::GFx::Movie::Invoke(v7, "gWardrobeList.SetSelectedIndex", 0i64, (Scaleform::GFx::Value *)&ptr, 1u);
        Scaleform::GFx::Movie::Invoke(v7, "WardrobeList_Refresh", 0i64, 0i64, 0);
        `eh vector destructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
      }
    }
  }
}

// File Line: 1688
// RVA: 0x5D9840
void __fastcall UFG::UIHKScreenWardrobe::Flash_AddItem(UFG::UIHKScreenWardrobe *this, UFG::UIHKWardrobeItemInfo *info)
{
  UFG::UIHKWardrobeItemInfo *v2; // rbx
  UFG::UIHKScreenWardrobe *v3; // rsi
  double v4; // xmm6_8
  __int64 v5; // rdi
  __int64 v6; // rdi
  __int64 v7; // rdi
  double v8; // xmm6_8
  double v9; // xmm6_8
  double v10; // xmm6_8
  __int64 v11; // rdi
  bool v12; // di
  bool v13; // di
  __int64 v14; // rdi
  __int64 v15; // rdi
  __int64 v16; // rdi
  double v17; // xmm6_8
  bool v18; // di
  bool v19; // di
  bool v20; // di
  bool v21; // di
  bool v22; // di
  __int64 v23; // rdi
  __int64 v24; // rdi
  __int64 v25; // rbx
  char ptr; // [rsp+30h] [rbp-B8h]
  __int64 v27; // [rsp+40h] [rbp-A8h]
  unsigned int v28; // [rsp+48h] [rbp-A0h]
  double v29; // [rsp+50h] [rbp-98h]
  char v30; // [rsp+60h] [rbp-88h]
  __int64 v31; // [rsp+68h] [rbp-80h]
  __int64 v32; // [rsp+70h] [rbp-78h]
  unsigned int v33; // [rsp+78h] [rbp-70h]
  __int64 v34; // [rsp+88h] [rbp-60h]
  unsigned int v35; // [rsp+90h] [rbp-58h]
  __int64 v36; // [rsp+98h] [rbp-50h]
  char v37; // [rsp+A8h] [rbp-40h]
  __int64 v38; // [rsp+B8h] [rbp-30h]
  unsigned int v39; // [rsp+C0h] [rbp-28h]
  __int64 v40; // [rsp+C8h] [rbp-20h]
  char v41; // [rsp+D8h] [rbp-10h]
  __int64 v42; // [rsp+E8h] [rbp+0h]
  unsigned int v43; // [rsp+F0h] [rbp+8h]
  double v44; // [rsp+F8h] [rbp+10h]
  char v45; // [rsp+108h] [rbp+20h]
  __int64 v46; // [rsp+118h] [rbp+30h]
  unsigned int v47; // [rsp+120h] [rbp+38h]
  double v48; // [rsp+128h] [rbp+40h]
  char v49; // [rsp+138h] [rbp+50h]
  __int64 v50; // [rsp+148h] [rbp+60h]
  unsigned int v51; // [rsp+150h] [rbp+68h]
  double v52; // [rsp+158h] [rbp+70h]
  char v53; // [rsp+168h] [rbp+80h]
  __int64 v54; // [rsp+178h] [rbp+90h]
  unsigned int v55; // [rsp+180h] [rbp+98h]
  __int64 v56; // [rsp+188h] [rbp+A0h]
  char v57; // [rsp+198h] [rbp+B0h]
  __int64 v58; // [rsp+1A8h] [rbp+C0h]
  unsigned int v59; // [rsp+1B0h] [rbp+C8h]
  __int64 v60; // [rsp+1B8h] [rbp+D0h]
  char v61; // [rsp+1C8h] [rbp+E0h]
  __int64 v62; // [rsp+1D8h] [rbp+F0h]
  unsigned int v63; // [rsp+1E0h] [rbp+F8h]
  __int64 v64; // [rsp+1E8h] [rbp+100h]
  char v65; // [rsp+1F8h] [rbp+110h]
  __int64 v66; // [rsp+208h] [rbp+120h]
  unsigned int v67; // [rsp+210h] [rbp+128h]
  __int64 v68; // [rsp+218h] [rbp+130h]
  char v69; // [rsp+228h] [rbp+140h]
  __int64 v70; // [rsp+238h] [rbp+150h]
  unsigned int v71; // [rsp+240h] [rbp+158h]
  __int64 v72; // [rsp+248h] [rbp+160h]
  char v73; // [rsp+258h] [rbp+170h]
  __int64 v74; // [rsp+268h] [rbp+180h]
  unsigned int v75; // [rsp+270h] [rbp+188h]
  __int64 v76; // [rsp+278h] [rbp+190h]
  char v77; // [rsp+288h] [rbp+1A0h]
  __int64 v78; // [rsp+298h] [rbp+1B0h]
  unsigned int v79; // [rsp+2A0h] [rbp+1B8h]
  __int64 v80; // [rsp+2A8h] [rbp+1C0h]
  char v81; // [rsp+2B8h] [rbp+1D0h]
  __int64 v82; // [rsp+2C8h] [rbp+1E0h]
  unsigned int v83; // [rsp+2D0h] [rbp+1E8h]
  double v84; // [rsp+2D8h] [rbp+1F0h]
  char v85; // [rsp+2E8h] [rbp+200h]
  __int64 v86; // [rsp+2F8h] [rbp+210h]
  unsigned int v87; // [rsp+300h] [rbp+218h]
  __int64 v88; // [rsp+308h] [rbp+220h]
  char v89; // [rsp+318h] [rbp+230h]
  __int64 v90; // [rsp+328h] [rbp+240h]
  unsigned int v91; // [rsp+330h] [rbp+248h]
  __int64 v92; // [rsp+338h] [rbp+250h]
  char v93; // [rsp+348h] [rbp+260h]
  __int64 v94; // [rsp+358h] [rbp+270h]
  unsigned int v95; // [rsp+360h] [rbp+278h]
  __int64 v96; // [rsp+368h] [rbp+280h]
  char v97; // [rsp+378h] [rbp+290h]
  __int64 v98; // [rsp+388h] [rbp+2A0h]
  unsigned int v99; // [rsp+390h] [rbp+2A8h]
  __int64 v100; // [rsp+398h] [rbp+2B0h]
  char v101; // [rsp+3A8h] [rbp+2C0h]
  __int64 v102; // [rsp+3B8h] [rbp+2D0h]
  unsigned int v103; // [rsp+3C0h] [rbp+2D8h]
  __int64 v104; // [rsp+3C8h] [rbp+2E0h]
  char v105; // [rsp+3D8h] [rbp+2F0h]
  __int64 v106; // [rsp+3E8h] [rbp+300h]
  unsigned int v107; // [rsp+3F0h] [rbp+308h]
  __int64 v108; // [rsp+3F8h] [rbp+310h]
  char v109; // [rsp+408h] [rbp+320h]
  __int64 v110; // [rsp+418h] [rbp+330h]
  unsigned int v111; // [rsp+420h] [rbp+338h]
  __int64 v112; // [rsp+428h] [rbp+340h]
  char v113; // [rsp+438h] [rbp+350h]
  __int64 v114; // [rsp+448h] [rbp+360h]
  unsigned int v115; // [rsp+450h] [rbp+368h]
  __int64 v116; // [rsp+458h] [rbp+370h]
  __int64 v117; // [rsp+468h] [rbp+380h]

  v117 = -2i64;
  v2 = info;
  v3 = this;
  `eh vector constructor iterator(&ptr, 0x30ui64, 23, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  v4 = (double)v2->trackerIndex;
  if ( (v28 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v27 + 16i64))(
      v27,
      &ptr,
      COERCE_DOUBLE(*(_QWORD *)&v29));
    v27 = 0i64;
  }
  v28 = 5;
  v29 = v4;
  v5 = (__int64)v2->title.mData;
  if ( (v33 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v32 + 16i64))(v32, &v30, v31);
    v32 = 0i64;
  }
  v33 = 6;
  v31 = v5;
  v6 = (__int64)v2->description.mData;
  if ( (v35 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, unsigned int *, __int64))(*(_QWORD *)v34 + 16i64))(v34, &v33, v36);
    v34 = 0i64;
  }
  v35 = 6;
  v36 = v6;
  v7 = (__int64)v2->brand.mData;
  if ( (v39 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v38 + 16i64))(v38, &v37, v40);
    v38 = 0i64;
  }
  v39 = 6;
  v40 = v7;
  v8 = (double)(signed int)v2->price;
  if ( (v43 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v42 + 16i64))(
      v42,
      &v41,
      COERCE_DOUBLE(*(_QWORD *)&v44));
    v42 = 0i64;
  }
  v43 = 5;
  v44 = v8;
  v9 = (double)(signed int)v2->discountPrice;
  if ( (v47 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v46 + 16i64))(
      v46,
      &v45,
      COERCE_DOUBLE(*(_QWORD *)&v48));
    v46 = 0i64;
  }
  v47 = 5;
  v48 = v9;
  v10 = (double)(signed int)v2->discountPercent;
  if ( (v51 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v50 + 16i64))(
      v50,
      &v49,
      COERCE_DOUBLE(*(_QWORD *)&v52));
    v50 = 0i64;
  }
  v51 = 5;
  v52 = v10;
  v11 = (__int64)v2->discountPercentStr.mData;
  if ( (v55 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v54 + 16i64))(v54, &v53, v56);
    v54 = 0i64;
  }
  v55 = 6;
  v56 = v11;
  v12 = v2->is_owned;
  if ( (v59 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v58 + 16i64))(v58, &v57, v60);
    v58 = 0i64;
  }
  v59 = 2;
  LOBYTE(v60) = v12;
  v13 = v2->is_equipped;
  if ( (v63 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v62 + 16i64))(v62, &v61, v64);
    v62 = 0i64;
  }
  v63 = 2;
  LOBYTE(v64) = v13;
  if ( (v67 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v66 + 16i64))(v66, &v65, v68);
    v66 = 0i64;
  }
  v67 = 5;
  v68 = 0i64;
  v14 = (__int64)v2->clothingBuffSetTitle.mData;
  if ( (v71 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v70 + 16i64))(v70, &v69, v72);
    v70 = 0i64;
  }
  v71 = 6;
  v72 = v14;
  v15 = (__int64)v2->clothingBuffSetIcon.mData;
  if ( (v75 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v74 + 16i64))(v74, &v73, v76);
    v74 = 0i64;
  }
  v75 = 6;
  v76 = v15;
  v16 = (__int64)v2->clothingBuffSetDesc.mData;
  if ( (v79 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v78 + 16i64))(v78, &v77, v80);
    v78 = 0i64;
  }
  v79 = 6;
  v80 = v16;
  v17 = (double)(signed int)v2->bodyLocation;
  if ( (v83 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v82 + 16i64))(
      v82,
      &v81,
      COERCE_DOUBLE(*(_QWORD *)&v84));
    v82 = 0i64;
  }
  v83 = 5;
  v84 = v17;
  v18 = v2->bHasClothingSetShoes;
  if ( (v87 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v86 + 16i64))(v86, &v85, v88);
    v86 = 0i64;
  }
  v87 = 2;
  LOBYTE(v88) = v18;
  v19 = v2->bHasClothingSetTorso;
  if ( (v91 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v90 + 16i64))(v90, &v89, v92);
    v90 = 0i64;
  }
  v91 = 2;
  LOBYTE(v92) = v19;
  v20 = v2->bHasClothingSetPants;
  if ( (v95 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v94 + 16i64))(v94, &v93, v96);
    v94 = 0i64;
  }
  v95 = 2;
  LOBYTE(v96) = v20;
  v21 = v2->playerHasEnoughFace;
  if ( (v99 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v98 + 16i64))(v98, &v97, v100);
    v98 = 0i64;
  }
  v99 = 2;
  LOBYTE(v100) = v21;
  v22 = v2->isOutfit;
  if ( (v103 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v102 + 16i64))(v102, &v101, v104);
    v102 = 0i64;
  }
  v103 = 2;
  LOBYTE(v104) = v22;
  v23 = (__int64)v2->itemBuffSetTitle.mData;
  if ( (v107 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v106 + 16i64))(v106, &v105, v108);
    v106 = 0i64;
  }
  v107 = 6;
  v108 = v23;
  v24 = (__int64)v2->itemBuffSetIcon.mData;
  if ( (v111 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v110 + 16i64))(v110, &v109, v112);
    v110 = 0i64;
  }
  v111 = 6;
  v112 = v24;
  v25 = (__int64)v2->itemBuffSetDesc.mData;
  if ( (v115 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v114 + 16i64))(v114, &v113, v116);
    v114 = 0i64;
  }
  v115 = 6;
  v116 = v25;
  Scaleform::GFx::Movie::Invoke(
    v3->mRenderable->m_movie.pObject,
    "WardrobeList_AddItem",
    0i64,
    (Scaleform::GFx::Value *)&ptr,
    0x17u);
  `eh vector destructor iterator(&ptr, 0x30ui64, 23, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 1739
// RVA: 0x609160
void __usercall UFG::UIHKScreenWardrobe::SetStoreCamera(UFG::UIHKScreenWardrobe *this@<rcx>, UFG::StoreFront *store@<rdx>, UFG::UIHKScreenWardrobe::eCameraState a_eNewCameraState@<r8d>, float *a4@<r13>)
{
  UFG::UIHKScreenWardrobe::eCameraState v4; // ebx
  UFG::StoreFront *v5; // r14
  UFG::UIHKScreenWardrobe *v6; // rsi
  UFG::SimObjectCharacter *v7; // r15
  UFG::qBaseNodeRB *v8; // rax
  UFG::TransformNodeComponent *v9; // rdi
  UFG::qMemoryPool *v10; // rax
  UFG::allocator::free_link *v11; // rax
  UFG::qBaseNodeRB *v12; // rax
  UFG::TransformNodeComponent *v13; // rdx
  UFG::SimObject *v14; // rcx
  UFG::ScriptCameraComponent *v15; // r14
  int v16; // ebx
  int v17; // ebx
  UFG::qMatrix44 *v18; // rbx
  float v19; // xmm2_4
  float v20; // xmm1_4
  float v21; // xmm1_4
  float v22; // xmm0_4
  Creature *v23; // rbx
  UFG::qSymbolUC *v24; // rax
  int v25; // eax
  float v26; // xmm8_4
  float v27; // xmm9_4
  float v28; // xmm10_4
  UFG::qSymbolUC *v29; // rax
  UFG::qSymbolUC *v30; // rax
  UFG::qSymbolUC *v31; // rax
  UFG::qSymbolUC *v32; // rax
  UFG::qSymbolUC *v33; // rax
  UFG::qSymbolUC *v34; // rax
  UFG::qSymbolUC *v35; // rax
  UFG::qSymbolUC *v36; // rax
  UFG::qSymbolUC *v37; // rax
  float v38; // xmm3_4
  __m128 v39; // xmm4
  float v40; // xmm5_4
  __m128 v41; // xmm2
  float v42; // xmm10_4
  float v43; // xmm6_4
  float v44; // xmm7_4
  float v45; // xmm10_4
  float v46; // xmm7_4
  float v47; // xmm10_4
  float v48; // xmm3_4
  __m128 v49; // xmm2
  __m128 v50; // xmm5
  float v51; // xmm1_4
  float v52; // xmm8_4
  UFG::qMatrix44 *v53; // rbx
  UFG::qVector3 eye; // [rsp+30h] [rbp-A8h]
  UFG::qVector3 look; // [rsp+40h] [rbp-98h]
  UFG::qSymbolUC v56; // [rsp+50h] [rbp-88h]
  UFG::qSymbolUC v57; // [rsp+54h] [rbp-84h]
  UFG::qSymbolUC v58; // [rsp+58h] [rbp-80h]
  UFG::qSymbolUC v59; // [rsp+5Ch] [rbp-7Ch]
  UFG::qSymbolUC v60; // [rsp+60h] [rbp-78h]
  UFG::qSymbolUC v61; // [rsp+64h] [rbp-74h]
  UFG::qSymbolUC v62; // [rsp+68h] [rbp-70h]
  UFG::qSymbolUC v63; // [rsp+6Ch] [rbp-6Ch]
  __int64 v64; // [rsp+70h] [rbp-68h]
  float v65; // [rsp+88h] [rbp-50h]
  float v66; // [rsp+8Ch] [rbp-4Ch]
  float v67; // [rsp+90h] [rbp-48h]
  UFG::qSymbolUC result[2]; // [rsp+120h] [rbp+48h]
  UFG::qSymbolUC vars0; // [rsp+130h] [rbp+58h]

  if ( store )
  {
    v64 = -2i64;
    v4 = a_eNewCameraState;
    v5 = store;
    v6 = this;
    v7 = LocalPlayer;
    if ( LocalPlayer )
    {
      v8 = UFG::StoreFront::GetCameraMarker(store);
      if ( v8 )
      {
        if ( v7->m_pTransformNodeComponent )
        {
          v9 = *(UFG::TransformNodeComponent **)&v8[2].mUID;
          if ( v9 )
          {
            UFG::TransformNodeComponent::UpdateWorldTransform(*(UFG::TransformNodeComponent **)&v8[2].mUID);
            if ( v6->mPlayerMark )
              goto LABEL_76;
            v10 = UFG::GetSimulationMemoryPool();
            v11 = UFG::qMemoryPool::Allocate(v10, 0x110ui64, "UIHKScreenWardrobe TransformNodeComponent", 0i64, 1u);
            *(_QWORD *)&result[0].mUID = v11;
            if ( v11 )
              UFG::TransformNodeComponent::TransformNodeComponent((UFG::TransformNodeComponent *)v11, 0, 0i64, 0);
            v6->mPlayerMark = (UFG::TransformNodeComponent *)v11;
            if ( v11 )
            {
LABEL_76:
              v12 = v4 == 3 ? UFG::StoreFront::GetPlayerExitMarker(v5) : UFG::StoreFront::GetPlayerMarker(v5);
              if ( v12 )
              {
                v13 = *(UFG::TransformNodeComponent **)&v12[2].mUID;
                if ( v13 )
                {
                  UFG::TransformNodeComponent::SetParent(v6->mPlayerMark, v13, 0);
                  v14 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
                  if ( v14 )
                  {
                    v15 = (UFG::ScriptCameraComponent *)UFG::SimObject::GetComponentOfType(
                                                          v14,
                                                          UFG::ScriptCameraComponent::_TypeUID);
                    if ( v15 )
                    {
                      if ( v4 )
                      {
                        v16 = v4 - 1;
                        if ( v16 )
                        {
                          v17 = v16 - 1;
                          if ( v17 )
                          {
                            if ( v17 == 1 )
                            {
                              v18 = (UFG::qMatrix44 *)v6->mPlayerMark;
                              UFG::TransformNodeComponent::UpdateWorldTransform(v6->mPlayerMark);
                              UFG::SimObjectUtility::Teleport((UFG::SimObject *)&v7->vfptr, v18 + 2);
                            }
                          }
                          else
                          {
                            UFG::TransformNodeComponent::UpdateWorldTransform(v9);
                            v19 = v9->mWorldTransform.v3.y;
                            v20 = v9->mWorldTransform.v3.z;
                            eye.x = v9->mWorldTransform.v3.x;
                            eye.y = v19;
                            eye.z = v20;
                            UFG::TransformNodeComponent::UpdateWorldTransform(v9);
                            UFG::TransformNodeComponent::UpdateWorldTransform(v9);
                            v21 = v9->mWorldTransform.v0.y + v9->mWorldTransform.v3.y;
                            v22 = v9->mWorldTransform.v0.z + v9->mWorldTransform.v3.z;
                            look.x = v9->mWorldTransform.v0.x + v9->mWorldTransform.v3.x;
                            look.y = v21;
                            look.z = v22;
LABEL_71:
                            UFG::ScriptCameraComponent::SetDesiredEyeLook(
                              v15,
                              &eye,
                              &look,
                              UFG::UIHKTweakables::WardrobeCameraDuration,
                              0);
                          }
                          goto LABEL_73;
                        }
                        v23 = *(Creature **)&UFG::SimObject::GetComponentOfType(
                                               (UFG::SimObject *)&v7->vfptr,
                                               UFG::CharacterAnimationComponent::_TypeUID)[2].m_TypeUID;
                        if ( v23 )
                        {
                          switch ( v6->mSelectedCategory )
                          {
                            case 0:
                              v31 = UFG::qSymbolUC::create_from_string(&v63, "Bip01 Spine2");
                              if ( v23->mPose.mRigHandle.mData )
                                v25 = Skeleton::GetBoneID(v23->mPose.mRigHandle.mUFGSkeleton, v31->mUID);
                              else
                                v25 = -1;
                              v26 = UFG::UIHKTweakables::WardrobeOffsetBody.x;
                              v27 = UFG::UIHKTweakables::WardrobeOffsetBody.y;
                              v28 = UFG::UIHKTweakables::WardrobeOffsetBody.z;
                              goto LABEL_65;
                            case 1:
                              v24 = UFG::qSymbolUC::create_from_string(result, "Bip01 L Calf");
                              if ( v23->mPose.mRigHandle.mData )
                                v25 = Skeleton::GetBoneID(v23->mPose.mRigHandle.mUFGSkeleton, v24->mUID);
                              else
                                v25 = -1;
                              v26 = UFG::UIHKTweakables::WardrobeOffsetLowerBody.x;
                              v27 = UFG::UIHKTweakables::WardrobeOffsetLowerBody.y;
                              v28 = UFG::UIHKTweakables::WardrobeOffsetLowerBody.z;
                              goto LABEL_65;
                            case 2:
                              v29 = UFG::qSymbolUC::create_from_string(&vars0, "Sync01");
                              if ( v23->mPose.mRigHandle.mData )
                                v25 = Skeleton::GetBoneID(v23->mPose.mRigHandle.mUFGSkeleton, v29->mUID);
                              else
                                v25 = -1;
                              v26 = UFG::UIHKTweakables::WardrobeOffsetFootwear.x;
                              v27 = UFG::UIHKTweakables::WardrobeOffsetFootwear.y;
                              v28 = UFG::UIHKTweakables::WardrobeOffsetFootwear.z;
                              goto LABEL_65;
                            case 3:
                              v30 = UFG::qSymbolUC::create_from_string(&v61, "face_ingame_jaw");
                              if ( v23->mPose.mRigHandle.mData )
                                v25 = Skeleton::GetBoneID(v23->mPose.mRigHandle.mUFGSkeleton, v30->mUID);
                              else
                                v25 = -1;
                              v26 = UFG::UIHKTweakables::WardrobeOffsetHeadgear.x;
                              v27 = UFG::UIHKTweakables::WardrobeOffsetHeadgear.y;
                              v28 = UFG::UIHKTweakables::WardrobeOffsetHeadgear.z;
                              goto LABEL_65;
                            case 5:
                              v32 = UFG::qSymbolUC::create_from_string(&v60, "Bip01 Head");
                              if ( v23->mPose.mRigHandle.mData )
                                v25 = Skeleton::GetBoneID(v23->mPose.mRigHandle.mUFGSkeleton, v32->mUID);
                              else
                                v25 = -1;
                              v26 = UFG::UIHKTweakables::WardrobeOffsetAccessories.x;
                              v27 = UFG::UIHKTweakables::WardrobeOffsetAccessories.y;
                              v28 = UFG::UIHKTweakables::WardrobeOffsetAccessories.z;
                              goto LABEL_65;
                            case 6:
                              v34 = UFG::qSymbolUC::create_from_string(&v59, "face_ingame_jaw");
                              if ( v23->mPose.mRigHandle.mData )
                                v25 = Skeleton::GetBoneID(v23->mPose.mRigHandle.mUFGSkeleton, v34->mUID);
                              else
                                v25 = -1;
                              v26 = UFG::UIHKTweakables::WardrobeOffsetGlasses.x;
                              v27 = UFG::UIHKTweakables::WardrobeOffsetGlasses.y;
                              v28 = UFG::UIHKTweakables::WardrobeOffsetGlasses.z;
                              goto LABEL_65;
                            case 7:
                              v35 = UFG::qSymbolUC::create_from_string(&v56, "Bip01 Neck");
                              if ( v23->mPose.mRigHandle.mData )
                                v25 = Skeleton::GetBoneID(v23->mPose.mRigHandle.mUFGSkeleton, v35->mUID);
                              else
                                v25 = -1;
                              v26 = UFG::UIHKTweakables::WardrobeOffsetNeck.x;
                              v27 = UFG::UIHKTweakables::WardrobeOffsetNeck.y;
                              v28 = UFG::UIHKTweakables::WardrobeOffsetNeck.z;
                              goto LABEL_65;
                            case 8:
                              v36 = UFG::qSymbolUC::create_from_string(&v62, "Bip01 L Prop");
                              if ( v23->mPose.mRigHandle.mData )
                                v25 = Skeleton::GetBoneID(v23->mPose.mRigHandle.mUFGSkeleton, v36->mUID);
                              else
                                v25 = -1;
                              v26 = UFG::UIHKTweakables::WardrobeOffsetLeftWrist.x;
                              v27 = UFG::UIHKTweakables::WardrobeOffsetLeftWrist.y;
                              v28 = UFG::UIHKTweakables::WardrobeOffsetLeftWrist.z;
                              goto LABEL_65;
                            case 9:
                              v37 = UFG::qSymbolUC::create_from_string(&v57, "Bip01 R Prop");
                              if ( v23->mPose.mRigHandle.mData )
                                v25 = Skeleton::GetBoneID(v23->mPose.mRigHandle.mUFGSkeleton, v37->mUID);
                              else
                                v25 = -1;
                              v26 = UFG::UIHKTweakables::WardrobeOffsetRightWrist.x;
                              v27 = UFG::UIHKTweakables::WardrobeOffsetRightWrist.y;
                              v28 = UFG::UIHKTweakables::WardrobeOffsetRightWrist.z;
                              goto LABEL_65;
                            case 0xA:
                              v33 = UFG::qSymbolUC::create_from_string(&v58, "Bip01 Head");
                              if ( v23->mPose.mRigHandle.mData )
                                v25 = Skeleton::GetBoneID(v23->mPose.mRigHandle.mUFGSkeleton, v33->mUID);
                              else
                                v25 = -1;
                              v26 = UFG::UIHKTweakables::WardrobeOffsetOutfit.x;
                              v27 = UFG::UIHKTweakables::WardrobeOffsetOutfit.y;
                              v28 = UFG::UIHKTweakables::WardrobeOffsetOutfit.z;
LABEL_65:
                              if ( v25 == -1 )
                                return;
                              Creature::GetTransform(v23, v25, (UFG::qMatrix44 *)&v58);
                              UFG::TransformNodeComponent::UpdateWorldTransform(v9);
                              v38 = v65 - v9->mWorldTransform.v3.x;
                              v39 = (__m128)LODWORD(v66);
                              v39.m128_f32[0] = v66 - v9->mWorldTransform.v3.y;
                              v40 = v67 - v9->mWorldTransform.v3.z;
                              v41 = v39;
                              v41.m128_f32[0] = (float)((float)(v39.m128_f32[0] * v39.m128_f32[0]) + (float)(v38 * v38))
                                              + (float)(v40 * v40);
                              v42 = v28 / COERCE_FLOAT(_mm_sqrt_ps(v41));
                              v43 = v42 * v38;
                              v44 = v42 * v39.m128_f32[0];
                              v45 = v42 * v40;
                              UFG::TransformNodeComponent::UpdateWorldTransform(v9);
                              v46 = v44 + v9->mWorldTransform.v3.y;
                              v47 = v45 + v9->mWorldTransform.v3.z;
                              eye.x = v43 + v9->mWorldTransform.v3.x;
                              eye.y = v46;
                              v48 = v65 - eye.x;
                              v49 = (__m128)LODWORD(v66);
                              v49.m128_f32[0] = v66 - v46;
                              v50 = v49;
                              v50.m128_f32[0] = (float)((float)(v49.m128_f32[0] * v49.m128_f32[0]) + (float)(v48 * v48))
                                              + (float)((float)(v67 - v47) * (float)(v67 - v47));
                              if ( v50.m128_f32[0] == 0.0 )
                                v51 = 0.0;
                              else
                                v51 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v50));
                              look.x = (float)((float)(v26 * (float)(v49.m128_f32[0] * v51)) + (float)(v27 * 0.0)) + v65;
                              look.y = (float)((float)(v26 * COERCE_FLOAT(COERCE_UNSIGNED_INT(v48 * v51) ^ _xmm[0]))
                                             + (float)(v27 * 0.0))
                                     + v66;
                              v52 = (float)((float)(v26 * 0.0) + v27) + v67;
                              look.z = v52;
                              eye.z = v52;
                              if ( v6->mSelectedCategory == 2 )
                                eye.z = v52 + UFG::UIHKTweakables::WardrobeFootEyeHeight;
                              goto LABEL_71;
                            default:
                              return;
                          }
                          return;
                        }
                      }
                      else
                      {
                        v53 = (UFG::qMatrix44 *)v6->mPlayerMark;
                        UFG::TransformNodeComponent::UpdateWorldTransform(v6->mPlayerMark);
                        UFG::SimObjectUtility::Teleport((UFG::SimObject *)&v7->vfptr, v53 + 2);
                        UFG::ScriptCameraComponent::SwitchToScriptCam(v15, v9, 0, 0.0, a4);
                        UFG::ScriptCameraComponent::SetFov(v15, UFG::UIHKTweakables::WardrobeFOV);
                        ((void (__fastcall *)(UFG::ScriptCameraComponent *))v15->vfptr[15].__vecDelDtor)(v15);
                      }
LABEL_73:
                      v6->mUsingScriptCamera = 1;
                      return;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}

// File Line: 1950
// RVA: 0x5F5010
void __fastcall UFG::UIHKScreenWardrobe::PopulateCategories(UFG::UIHKScreenWardrobe *this, UFG::StoreFront *pStore)
{
  UFG::StoreFront *v2; // rsi
  UFG::UIHKScreenWardrobe *v3; // rdi
  UFG::StoreFront::ItemCategory v4; // ebx
  char *v5; // rax
  Scaleform::GFx::Movie *v6; // rbx
  double v7; // xmm6_8
  Scaleform::GFx::Value value; // [rsp+30h] [rbp-21h]
  char ptr; // [rsp+60h] [rbp+Fh]
  __int64 v10; // [rsp+70h] [rbp+1Fh]
  unsigned int v11; // [rsp+78h] [rbp+27h]
  double v12; // [rsp+80h] [rbp+2Fh]

  if ( !pStore )
    return;
  v2 = pStore;
  v3 = this;
  v4 = 0;
  do
  {
    if ( (v4 - 4) & 0xFFFFFFF6 || v4 == 5 )
    {
      if ( v3->mIsStore )
      {
        if ( (signed int)UFG::StoreFront::GetItemCount(v2, v4) <= 0 )
          goto LABEL_11;
LABEL_10:
        v5 = UFG::StoreFront::GetCategoryHeading(v2, v4);
        UFG::UIHKScreenWardrobe::Flash_AddCategory(v3, v5);
        ++v3->mNumCategories;
        goto LABEL_11;
      }
      if ( !UFG::StoreFront::IsOwnedClothingCategoryEmpty(v2, v4) || v4 == 11 )
        goto LABEL_10;
    }
LABEL_11:
    ++v4;
  }
  while ( (signed int)v4 < 14 );
  v6 = v3->mRenderable->m_movie.pObject;
  if ( v6 )
  {
    `eh vector constructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    v7 = (double)(signed int)v3->mNumCategories;
    if ( (v11 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v10 + 16i64))(
        v10,
        &ptr,
        COERCE_DOUBLE(*(_QWORD *)&v12));
      v10 = 0i64;
    }
    v11 = 5;
    v12 = v7;
    Scaleform::GFx::Movie::Invoke(v6, "CategoryMenu_SetNumCategories", 0i64, (Scaleform::GFx::Value *)&ptr, 1u);
    if ( v3->mIsStore )
    {
      UFG::UIHKScreenWardrobe::UpdateMoney(v3);
    }
    else
    {
      value.pObjectInterface = 0i64;
      value.Type = 2;
      value.mValue.BValue = 0;
      Scaleform::GFx::Movie::SetVariable(v6, "mc_Money._visible", &value, 1i64);
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
    `eh vector destructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 2005
// RVA: 0x5D9110
void __fastcall UFG::UIHKScreenWardrobe::Flash_AddCategory(UFG::UIHKScreenWardrobe *this, const char *caption)
{
  const char *v2; // rdi
  Scaleform::GFx::Movie *v3; // rbx
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h]

  v2 = caption;
  v3 = this->mRenderable->m_movie.pObject;
  if ( v3 )
  {
    `eh vector constructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( ((unsigned int)pargs.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        *(_QWORD *)&pargs.mValue.NValue);
      pargs.pObjectInterface = 0i64;
    }
    pargs.Type = 6;
    *(_QWORD *)&pargs.mValue.NValue = v2;
    Scaleform::GFx::Movie::Invoke(v3, "CategoryMenu_AddItem", 0i64, &pargs, 1u);
    `eh vector destructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 2017
// RVA: 0x5E8BF0
__int64 __fastcall UFG::UIHKScreenWardrobe::GetSelectedCategory(UFG::UIHKScreenWardrobe *this)
{
  UFG::UIHKScreenWardrobe *v1; // rbx
  hkpNullContactMgrFactory *v2; // rax
  hkpCollidable *v3; // rdx
  hkpCollidable *v4; // r8
  hkpCollisionInput *v5; // r9
  UFG::StoreFront *v6; // rsi
  const char *v7; // rdi
  UFG::StoreFront::ItemCategory v8; // ebx
  char *v9; // rax

  v1 = this;
  v2 = (hkpNullContactMgrFactory *)UFG::StoreFrontTracker::Instance();
  if ( !v2 )
    return 0i64;
  v6 = (UFG::StoreFront *)hkpNullContactMgrFactory::createContactMgr(v2, v3, v4, v5);
  if ( !v6 )
    return 0i64;
  v7 = UFG::UIHKScreenWardrobe::GetSelectedCategoryCaption(v1);
  if ( !v7 )
    return 0i64;
  v8 = 0;
  while ( 1 )
  {
    if ( (v8 - 4) & 0xFFFFFFF6 || v8 == 5 )
    {
      v9 = UFG::StoreFront::GetCategoryHeading(v6, v8);
      if ( !(unsigned int)UFG::qStringCompare(v7, v9, -1) )
        break;
    }
    if ( (signed int)++v8 >= 14 )
      return 0i64;
  }
  return (unsigned int)v8;
}

// File Line: 2053
// RVA: 0x5E8CA0
const char *__fastcall UFG::UIHKScreenWardrobe::GetSelectedCategoryCaption(UFG::UIHKScreenWardrobe *this)
{
  Scaleform::GFx::Movie *v1; // rcx
  long double v3; // rbx
  Scaleform::GFx::Value pval; // [rsp+28h] [rbp-40h]

  v1 = this->mRenderable->m_movie.pObject;
  if ( !v1 )
    return 0i64;
  pval.pObjectInterface = 0i64;
  pval.Type = 0;
  Scaleform::GFx::Movie::GetVariable(v1, &pval, "gCategoryMenu_SelectedValue");
  if ( ((unsigned int)pval.Type >> 6) & 1 )
    v3 = *(double *)pval.mValue.pString;
  else
    v3 = pval.mValue.NValue;
  if ( ((unsigned int)pval.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pval.pObjectInterface->vfptr->gap8[8])(
      pval.pObjectInterface,
      &pval,
      *(_QWORD *)&pval.mValue.NValue);
    pval.pObjectInterface = 0i64;
  }
  return *(const char **)&v3;
}

// File Line: 2065
// RVA: 0x61B610
void __fastcall UFG::UIHKScreenWardrobe::UpdateMoney(UFG::UIHKScreenWardrobe *this)
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
  Scaleform::GFx::Movie::Invoke(v1, "SetMoney", 0i64, (Scaleform::GFx::Value *)&ptr, 3u);
  `eh vector destructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  UFG::qString::~qString(&string);
}

// File Line: 2083
// RVA: 0x60D300
void __fastcall UFG::UIHKScreenWardrobe::ShowCategorySelect(UFG::UIHKScreenWardrobe *this)
{
  UFG::UIHKScreenWardrobe *v1; // rbx
  Scaleform::GFx::Movie *v2; // rcx
  hkpNullContactMgrFactory *v3; // rax
  hkpCollidable *v4; // rdx
  hkpCollidable *v5; // r8
  hkpCollisionInput *v6; // r9
  UFG::StoreFront *v7; // rax
  UFG::qString *v8; // rax
  UFG::qString result; // [rsp+38h] [rbp-30h]

  v1 = this;
  this->mState = 3;
  v2 = this->mRenderable->m_movie.pObject;
  if ( v2 )
  {
    Scaleform::GFx::Movie::Invoke(v2, "ShowCategorySelect", 0i64, 0i64, 0);
    UFG::UIHKScreenWardrobe::ShowHelpBar(v1, HELP_SELECT_ITEM_STORE);
    v3 = (hkpNullContactMgrFactory *)UFG::StoreFrontTracker::Instance();
    if ( v3 )
    {
      v7 = (UFG::StoreFront *)hkpNullContactMgrFactory::createContactMgr(v3, v4, v5, v6);
      if ( v7 )
      {
        if ( v1->mIsStore )
          v8 = UFG::StoreFront::GetStoreDesc(v7, &result);
        else
          UFG::qString::qString(&result, "$WARDROBE_SUBHEADING");
        UFG::UIHKScreenWardrobe::SetStoreDesc(v1, v8);
      }
    }
  }
}

// File Line: 2125
// RVA: 0x5D4940
void __fastcall UFG::UIHKScreenWardrobe::CategorySelect_HandleOptionSelected(UFG::UIHKScreenWardrobe *this)
{
  UFG::UIHKScreenWardrobe *v1; // rbx
  const char *v2; // rax
  Scaleform::GFx::Movie *v3; // rcx
  hkpNullContactMgrFactory *v4; // rax
  hkpCollidable *v5; // rdx
  hkpCollidable *v6; // r8
  hkpCollisionInput *v7; // r9
  UFG::StoreFront *v8; // rax
  char *v9; // rax
  UFG::qString *v10; // rax
  UFG::qString v11; // [rsp+38h] [rbp-30h]

  v1 = this;
  this->mSelectedCategory = UFG::UIHKScreenWardrobe::GetSelectedCategory(this);
  v2 = UFG::UIHKScreenWardrobe::GetSelectedCategoryCaption(v1);
  UFG::qString::Set(&v1->mSelectedCategoryCaption, v2);
  v1->mState = 2;
  v3 = v1->mRenderable->m_movie.pObject;
  if ( v3 )
    Scaleform::GFx::Movie::Invoke(v3, "HideCategorySelect", 0i64, 0i64, 0);
  v4 = (hkpNullContactMgrFactory *)UFG::StoreFrontTracker::Instance();
  if ( v4 )
  {
    v8 = (UFG::StoreFront *)hkpNullContactMgrFactory::createContactMgr(v4, v5, v6, v7);
    if ( v8 )
    {
      v9 = UFG::StoreFront::GetCategoryHeading(v8, v1->mSelectedCategory);
      UFG::qString::qString(&v11, v9);
      UFG::UIHKScreenWardrobe::SetStoreDesc(v1, v10);
    }
  }
  if ( v1->mSelectedCategory == 11 )
  {
    v1->mState = 4;
    UFG::UIHKScreenWardrobe::PopulateCustomOutfits(v1);
    UFG::UIHKScreenWardrobe::ShowHelpBar(v1, HELP_SELECT_ITEM_EMPTY|HELP_SELECT_ITEM_STORE);
  }
  else
  {
    UFG::UIHKScreenWardrobe::PopulateInventory(v1);
  }
}

// File Line: 2152
// RVA: 0x5D5E30
void __fastcall UFG::UIHKScreenWardrobe::CustomOutfit_HandleOptionSelected(UFG::UIHKScreenWardrobe *this)
{
  UFG::UIHKScreenWardrobe *v1; // rbx
  UFG::StoreFront::OutfitNum v2; // eax
  UFG::GameStatTracker *v3; // rax
  UFG::eClothingBuffEnum v4; // eax
  UFG::StoreFrontTracker *v5; // rax
  UFG::qPropertySet *v6; // rax
  char *v7; // rax
  UFG::qSymbol result; // [rsp+30h] [rbp+8h]

  v1 = this;
  if ( this->mNumItems )
  {
    v2 = UFG::UIHKScreenWardrobe::GetSelectedIndex(this);
    v1->mSelectedIndex = v2;
    UFG::StoreFront::EquipCustomOutfit(v2, 1, 1);
    UFG::StoreFront::CheckAchievement();
    UFG::UIHKScreenWardrobe::SaveCurrentClothingAsRestore(v1);
    v3 = UFG::GameStatTracker::Instance();
    v4 = (unsigned int)UFG::GameStatTracker::GetStat(v3, ClothingSetBuff);
    if ( v4 )
    {
      UFG::StoreFront::LookupClothingBuffSymbol(&result, v4);
      v5 = UFG::StoreFrontTracker::Instance();
      v6 = UFG::StoreFrontTracker::FindClothingSetSlow(v5, &result);
      if ( v6 )
      {
        v7 = PropertyUtils::Get<char const *>(
               v6,
               (UFG::qSymbol *)&UFG::ClothingSetSymbol_ActiveDesc.mUID,
               DEPTH_RECURSE);
        if ( v7 )
          UFG::UIScreenDialogBox::createOKDialog((UFG::UIScreen *)&v1->vfptr, &customWorldMapCaption, v7, 0);
      }
    }
  }
}

// File Line: 2176
// RVA: 0x604AC0
void __fastcall UFG::UIHKScreenWardrobe::SendTelemetryData(UFG::UIHKScreenWardrobe *this)
{
  UFG::GameStatTracker *v1; // rsi
  bool v2; // bl
  UFG::OSuiteDBLogger *v3; // rdi
  UFG::PersistentData::ID *v4; // rax
  const char *v5; // r9
  int v6; // ebx
  int v7; // ebx
  int v8; // ebx
  int v9; // ebx
  int v10; // ebx
  int v11; // ebx
  int v12; // ebx
  int v13; // ebx
  int v14; // ebx
  int v15; // ebx
  UFG::NameValueColumnType *i; // rbx
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v17; // rcx
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v18; // rax
  __int64 v19; // rcx
  UFG::NameValueColumnType *v20; // rax
  __int64 v21; // [rsp+18h] [rbp-49h]
  UFG::NameValueColumnType *v22; // [rsp+20h] [rbp-41h]
  char dest; // [rsp+28h] [rbp-39h]
  __int64 v24; // [rsp+A8h] [rbp+47h]

  v24 = -2i64;
  v1 = UFG::GameStatTracker::Instance();
  v22 = (UFG::NameValueColumnType *)&v21;
  v2 = UFG::StoreFront::IsWeiWearingAnPrefinedOutfit();
  v3 = UFG::OSuiteDBLogger::Instance();
  if ( UFG::OSuiteDBLogger::CreateMetric(v3, "ChangeClothes") )
  {
    UFG::qSPrintf(&dest, 128, "i32_%s", "IsPredefinedOutfit");
    OSuite::ZMetric::SetProperty(v3->m_pMetric, &dest, v2 != 0);
    if ( v2 )
    {
      v4 = UFG::GameStatTracker::GetStat(v1, CurrentOutfit);
      v5 = "PredefinedOutfit";
    }
    else
    {
      v6 = UFG::GameStatTracker::GetStat(v1, CurrentHeadgear)->mValue.mUID;
      UFG::qSPrintf(&dest, 128, "i32_%s", "Headgear");
      OSuite::ZMetric::SetProperty(v3->m_pMetric, &dest, v6);
      v7 = UFG::GameStatTracker::GetStat(v1, CurrentHead)->mValue.mUID;
      UFG::qSPrintf(&dest, 128, "i32_%s", "Head");
      OSuite::ZMetric::SetProperty(v3->m_pMetric, &dest, v7);
      v8 = UFG::GameStatTracker::GetStat(v1, CurrentGlasses)->mValue.mUID;
      UFG::qSPrintf(&dest, 128, "i32_%s", "Glasses");
      OSuite::ZMetric::SetProperty(v3->m_pMetric, &dest, v8);
      v9 = UFG::GameStatTracker::GetStat(v1, CurrentNeck)->mValue.mUID;
      UFG::qSPrintf(&dest, 128, "i32_%s", "Neck");
      OSuite::ZMetric::SetProperty(v3->m_pMetric, &dest, v9);
      v10 = UFG::GameStatTracker::GetStat(v1, CurrentBody)->mValue.mUID;
      UFG::qSPrintf(&dest, 128, "i32_%s", "Body");
      OSuite::ZMetric::SetProperty(v3->m_pMetric, &dest, v10);
      v11 = UFG::GameStatTracker::GetStat(v1, CurrentLeftWrist)->mValue.mUID;
      UFG::qSPrintf(&dest, 128, "i32_%s", "LeftWrist");
      OSuite::ZMetric::SetProperty(v3->m_pMetric, &dest, v11);
      v12 = UFG::GameStatTracker::GetStat(v1, CurrentRightWrist)->mValue.mUID;
      UFG::qSPrintf(&dest, 128, "i32_%s", "RightWrist");
      OSuite::ZMetric::SetProperty(v3->m_pMetric, &dest, v12);
      v13 = UFG::GameStatTracker::GetStat(v1, CurrentLowerBody)->mValue.mUID;
      UFG::qSPrintf(&dest, 128, "i32_%s", "LowerBody");
      OSuite::ZMetric::SetProperty(v3->m_pMetric, &dest, v13);
      v14 = UFG::GameStatTracker::GetStat(v1, CurrentFootwear)->mValue.mUID;
      UFG::qSPrintf(&dest, 128, "i32_%s", "Footwear");
      OSuite::ZMetric::SetProperty(v3->m_pMetric, &dest, v14);
      v4 = UFG::GameStatTracker::GetStat(v1, CurrentAccessories);
      v5 = "Accessories";
    }
    v15 = v4->mValue.mUID;
    UFG::qSPrintf(&dest, 128, "i32_%s", v5);
    OSuite::ZMetric::SetProperty(v3->m_pMetric, &dest, v15);
    UFG::OSuiteDBLogger::SubmitMetric(v3, 1);
  }
  for ( i = v22; v22 != (UFG::NameValueColumnType *)&v21; i = v22 )
  {
    v17 = i->mPrev;
    v18 = i->mNext;
    v17->mNext = v18;
    v18->mPrev = v17;
    i->mPrev = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)&i->mPrev;
    i->mNext = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)&i->mPrev;
    UFG::NameValueColumnType::~NameValueColumnType(i);
    operator delete[](i);
  }
  v19 = v21;
  v20 = v22;
  *(_QWORD *)(v21 + 8) = v22;
  v20->mPrev = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)v19;
}

// File Line: 2208
// RVA: 0x5F2480
void __fastcall UFG::UIHKScreenWardrobe::NetworkSignedIn(UFG::UIHKScreenWardrobe *this, hkgpIndexedMeshDefinitions::Edge *a2)
{
  UFG::UIHKScreenWardrobe *v2; // rdi
  __int64 v3; // rax
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h]

  v2 = this;
  v3 = *(_QWORD *)&this[-1].mInitClothing[1].mUID;
  if ( v3 && *(_QWORD *)(v3 + 320) && Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(0i64, a2) )
  {
    v2->m_screenName[26] = 1;
    BYTE1(v2->mDimType) = 0;
    UFG::UIHKScreenWardrobe::ShowTickerPopup((UFG::UIHKScreenWardrobe *)((char *)v2 - 152), 0);
    UFG::UIHKScreenWardrobe::ShowHelpBar(
      (UFG::UIHKScreenWardrobe *)((char *)v2 - 152),
      *(UFG::UIHKScreenWardrobe::eHelpBarState *)&v2->m_screenName[16]);
    pargs.pObjectInterface = 0i64;
    pargs.Type = 6;
    *(_QWORD *)&pargs.mValue.NValue = &customWorldMapCaption;
    Scaleform::GFx::Movie::Invoke(
      *(Scaleform::GFx::Movie **)(*(_QWORD *)&v2[-1].mInitClothing[1].mUID + 320i64),
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

