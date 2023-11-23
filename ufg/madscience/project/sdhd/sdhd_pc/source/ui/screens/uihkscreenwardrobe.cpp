// File Line: 85
// RVA: 0x156CE30
__int64 UFG::_dynamic_initializer_for__UI_HASH_PURCHASE_ITEM__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("PURCHASE_ITEM", -1);
  UI_HASH_PURCHASE_ITEM = result;
  return result;
}

// File Line: 86
// RVA: 0x156CE10
__int64 UFG::_dynamic_initializer_for__UI_HASH_PURCHASE_AND_EQUIP_ITEM__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("PURCHASE_AND_EQUIP_ITEM", -1);
  UI_HASH_PURCHASE_AND_EQUIP_ITEM = result;
  return result;
}

// File Line: 97
// RVA: 0x156E0A0
__int64 UFG::_dynamic_initializer_for__gUIWardrobeScreenDeferredTaskChannel__()
{
  UFG::ChannelObj::ChannelObj(&UFG::gUIWardrobeScreenDeferredTaskChannel, "EVT_UI_WARDROBE_DEFERRED_TASK_CHANNEL", 0i64);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gUIWardrobeScreenDeferredTaskChannel__);
}

// File Line: 121
// RVA: 0x5C7A10
void __fastcall UFG::UIHKScreenWardrobe::UIHKScreenWardrobe(UFG::UIHKScreenWardrobe *this)
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
  this->UFG::UIHKTaskableScreen::UFG::UIScreen::vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenWardrobe::`vftable{for `UFG::UIHKTaskableScreen};
  this->UFG::OnlineManagerObserver::vfptr = (UFG::OnlineManagerObserverVtbl *)&UFG::UIHKScreenWardrobe::`vftable{for `UFG::OnlineManagerObserver};
  this->mState = STATE_INIT;
  *(_WORD *)&this->mSfxPlayed = 0;
  this->mSuspendedPlayerVehicle = 0i64;
  this->mHelpBarState = HELP_NONE;
  *(_WORD *)&this->mIsStore = 0;
  this->mIsRestricted = 0;
  *(_QWORD *)&this->mSavedTimeScale = 0i64;
  *(_QWORD *)&this->mNumCategories = 0i64;
  this->mSelectedCategory = ItemCategory_BODY;
  UFG::qString::qString(&this->mSelectedCategoryCaption);
  this->mCameraTarget = 0i64;
  this->mPlayerMark = 0i64;
  *(_DWORD *)&this->mInfoTickerTextSet = 0;
  `eh vector constructor iterator(this->mInitClothing, 4ui64, 14, (void (__fastcall *)(void *))BackInfo::BackInfo);
  v2.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::UIHKScreenWardrobe::HandleDeferredTask;
  v2.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)Assembly::GetRCX(this);
  UFG::EventDispatcher::Register(
    &UFG::EventDispatcher::mInstance,
    &v2,
    UFG::gUIWardrobeScreenDeferredTaskChannel.mUID,
    0i64,
    0);
}

// File Line: 127
// RVA: 0x5CCF50
void __fastcall UFG::UIHKScreenWardrobe::~UIHKScreenWardrobe(UFG::UIHKScreenWardrobe *this)
{
  UFG::OnlineManagerObserver *v2; // rsi
  UFG::GameStatTracker *v3; // rax
  UFG::OnlineManager *v4; // rax
  UFG::UI *v5; // rcx
  UFG::UIHKHelpBarWidget *p_HelpBar; // rdi
  unsigned int v7; // eax
  unsigned int v8; // eax
  int v9; // eax
  UFG::TimeOfDayManager *Instance; // rax
  UFG::UIScreenTextureManager *v11; // rax
  hkpNullContactMgrFactory *v12; // rax
  hkpCollidable *v13; // rdx
  hkpCollidable *v14; // r8
  hkpCollisionInput *v15; // r9
  UFG::SimObject *m_pSimObject; // rcx
  UFG::ScriptCameraComponent *ComponentOfType; // rax
  UFG::ScriptCameraComponent *v18; // rdi
  UFG::qNode<UFG::BaseCameraComponent,UFG::BaseCameraComponent> *CurrentGameCamera; // rax
  UFG::TransformNodeComponent *mCameraTarget; // rdx
  UFG::TransformNodeComponent *mPlayerMark; // rdx
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *mPrev; // rcx
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *mNext; // rax
  fastdelegate::FastDelegate1<UFG::Event *,void> v24; // [rsp+28h] [rbp-30h] BYREF

  this->UFG::UIHKTaskableScreen::UFG::UIScreen::vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenWardrobe::`vftable{for `UFG::UIHKTaskableScreen};
  v2 = &this->UFG::OnlineManagerObserver;
  this->UFG::OnlineManagerObserver::vfptr = (UFG::OnlineManagerObserverVtbl *)&UFG::UIHKScreenWardrobe::`vftable{for `UFG::OnlineManagerObserver};
  if ( this->mHasClothingChanged )
  {
    v3 = UFG::GameStatTracker::Instance();
    UFG::GameStatTracker::ApplyDelta(v3, NumClothingChanged, 1);
    UFG::UIHKScreenWardrobe::SendTelemetryData(this);
  }
  v4 = UFG::OnlineManager::Instance();
  UFG::OSuiteManager::UnRegisterObserver(v4, v2);
  v24.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::UIHKScreenWardrobe::HandleDeferredTask;
  v24.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)Assembly::GetRCX(this);
  UFG::EventDispatcher::UnRegister(
    &UFG::EventDispatcher::mInstance,
    &v24,
    UFG::gUIWardrobeScreenDeferredTaskChannel.mUID);
  if ( UFG::UIHKScreenGlobalOverlay::mThis )
  {
    p_HelpBar = &UFG::UIHKScreenGlobalOverlay::mThis->HelpBar;
    v7 = UFG::qStringHash32("STORE", 0xFFFFFFFF);
    UFG::UIHKHelpBarWidget::Hide(p_HelpBar, v7);
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
  if ( byte_142431A14 && UFG::UIHK_PDAWidget::mInputLocked )
  {
    UFG::SetInputMode_PDA_Off(UFG::gActiveControllerNum);
    v9 = UFG::UIHKGameplayHelpWidget::mLocked;
    if ( UFG::UIHKGameplayHelpWidget::mLocked > 0 )
      v9 = --UFG::UIHKGameplayHelpWidget::mLocked;
    if ( v9 < 1 )
      UFG::UIHKScreenHud::GameplayHelp->mChanged = 1;
    --UFG::UIHK_PDAWidget::mInputLocked;
  }
  UFG::UIHKScreenHud::PDACache.state = STATE_IDLE;
  byte_142431A14 = 0;
  dword_142431A18 = 0;
  UFG::NavComponent::ms_bDisableNavigation = 0;
  UFG::PedSpawnManager::SetAmbientSpawningEnable(this->mSavedFreezeStatus);
  Instance = UFG::TimeOfDayManager::GetInstance();
  TimePlotPoint::SetTimeValue(Instance, this->mSavedTimeScale);
  v11 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v11, "Wardrobe");
  v12 = (hkpNullContactMgrFactory *)UFG::StoreFrontTracker::Instance();
  if ( v12 && hkpNullContactMgrFactory::createContactMgr(v12, v13, v14, v15) && LocalPlayer )
    UFG::StoreMeshHelper::QueueSwapping(LocalPlayer);
  if ( this->mUsingScriptCamera )
  {
    m_pSimObject = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
    if ( m_pSimObject )
    {
      ComponentOfType = (UFG::ScriptCameraComponent *)UFG::SimObject::GetComponentOfType(
                                                        m_pSimObject,
                                                        UFG::ScriptCameraComponent::_TypeUID);
      v18 = ComponentOfType;
      if ( ComponentOfType )
      {
        UFG::ScriptCameraComponent::ResetDOF(ComponentOfType);
        UFG::ScriptCameraComponent::ReleaseCamera(v18, 0);
      }
    }
  }
  CurrentGameCamera = UFG::GetCurrentGameCamera();
  if ( CurrentGameCamera )
    LODWORD(CurrentGameCamera[47].mPrev) = 1;
  mCameraTarget = this->mCameraTarget;
  if ( mCameraTarget )
  {
    UFG::Simulation::DestroySimComponent(&UFG::gSim, mCameraTarget);
    this->mCameraTarget = 0i64;
  }
  mPlayerMark = this->mPlayerMark;
  if ( mPlayerMark )
  {
    UFG::Simulation::DestroySimComponent(&UFG::gSim, mPlayerMark);
    this->mPlayerMark = 0i64;
  }
  UFG::UIGfxTranslator::unloadDictionary(UFG::UIScreenManager::s_instance->m_translator, "ITEMS");
  `eh vector destructor iterator(this->mInitClothing, 4ui64, 14, (void (__fastcall *)(void *))_);
  UFG::qString::~qString(&this->mSelectedCategoryCaption);
  v2->vfptr = (UFG::OnlineManagerObserverVtbl *)&UFG::OnlineManagerObserver::`vftable;
  mPrev = v2->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = &v2->UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver>;
  v2->mNext = &v2->UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver>;
  UFG::UIScreen::~UIScreen(this);
}

// File Line: 241
// RVA: 0x636E70
void __fastcall UFG::UIHKScreenWardrobe::init(UFG::UIHKScreenWardrobe *this, hkgpIndexedMeshDefinitions::Edge *data)
{
  UFG::Controller *v4; // rcx
  UFG::TimeOfDayManager *Instance; // rax
  UFG::OSuiteTickerManager *v6; // rax
  bool v7; // bl
  char *TickerDescription; // rsi
  hkpNullContactMgrFactory *v9; // rax
  hkpCollidable *v10; // rdx
  hkpCollidable *v11; // r8
  hkpCollisionInput *v12; // r9
  hkpNullContactMgr *ContactMgr; // rax
  UFG::OnlineManager *v14; // rax
  Scaleform::GFx::Value ptr; // [rsp+40h] [rbp-68h] BYREF
  char v16[16]; // [rsp+70h] [rbp-38h] BYREF
  __int64 v17; // [rsp+80h] [rbp-28h]
  int v18; // [rsp+88h] [rbp-20h]
  char *v19; // [rsp+90h] [rbp-18h]

  this->mIsRestricted = Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(0i64, data);
  UFG::UIScreen::init(this, (UFG::UICommandData *)data);
  if ( UFG::gInputSystem && UFG::gActiveControllerNum != -1 )
  {
    v4 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum];
    if ( !UFG::UI::gUIInputLocked )
      g_saved_gameplay_controller_mode = v4->m_ActiveMapSet;
    UFG::SetInputMode(IM_UI_ONLY, v4->mControllerIndex);
    ++UFG::UI::gUIInputLocked;
  }
  UFG::NavComponent::ms_bDisableNavigation = 1;
  this->mSavedFreezeStatus = UFG::PedSpawnManager::msAmbientSpawningEnable;
  UFG::PedSpawnManager::SetAmbientSpawningEnable(0);
  this->mSavedTimeScale = UFG::TimeOfDayManager::GetInstance()->m_GameSecondsPerRealSecond;
  Instance = UFG::TimeOfDayManager::GetInstance();
  TimePlotPoint::SetTimeValue(Instance, 0.0);
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
  this->mState = NUM_CALIBRATION_STATES|STATE_UISCALE;
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
  ptr.mValue.pString = "img://INFOCAST_CHANNEL_1";
  v6 = UFG::OSuiteTickerManager::Instance();
  v7 = 1;
  TickerDescription = UFG::OSuiteTickerManager::GetTickerDescription(v6, (hkgpIndexedMeshDefinitions::Edge *)1, 1);
  if ( (v18 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v17 + 16i64))(v17, v16, v19);
    v17 = 0i64;
  }
  v18 = 6;
  v19 = TickerDescription;
  Scaleform::GFx::Movie::Invoke(this->mRenderable->m_movie.pObject, "SetTickerPopupInfo", 0i64, &ptr, 2u);
  UFG::UIHKScreenWardrobe::ShowTickerPopup(this, this->mInfoTickerPopupVisible);
  v9 = (hkpNullContactMgrFactory *)UFG::StoreFrontTracker::Instance();
  if ( !v9
    || (ContactMgr = hkpNullContactMgrFactory::createContactMgr(v9, v10, v11, v12)) == 0i64
    || LODWORD(ContactMgr[1].vfptr) != 1 )
  {
    v7 = 0;
  }
  this->mIsStore = v7;
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xF41B2F0D, 0i64, 0, 0i64);
  v14 = UFG::OnlineManager::Instance();
  UFG::OnlineManager::RegisterObserver(v14, &this->UFG::OnlineManagerObserver);
  `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 286
// RVA: 0x61E240
void __fastcall UFG::UIHKScreenWardrobe::afterFadeToBlackInit(UFG::UIHKScreenWardrobe *this)
{
  Scaleform::GFx::Movie *pObject; // r13
  UFG::qString *v3; // rdi
  hkpNullContactMgrFactory *v4; // rax
  hkpCollidable *v5; // rdx
  hkpCollidable *v6; // r8
  hkpCollisionInput *v7; // r9
  UFG::StoreFront *ContactMgr; // r15
  UFG::SimObjectCharacter *v9; // rbx
  UFG::CharacterAnimationComponent *ComponentOfTypeHK; // rax
  signed __int16 m_Flags; // cx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // r14
  float v13; // xmm3_4
  float v14; // xmm1_4
  float v15; // xmm3_4
  float v16; // xmm1_4
  __int16 v17; // cx
  UFG::VehicleOwnershipComponent *ComponentOfType; // rax
  UFG::VehicleOwnershipComponent *v19; // rbx
  UFG::SimObjectGame *OwnedVehicle; // rax
  UFG::SimObject *v21; // rbx
  __int16 v22; // dx
  UFG::SimComponent *m_pComponent; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rcx
  float v25; // xmm1_4
  int v26; // xmm2_4
  float v27; // xmm1_4
  float v28; // xmm2_4
  UFG::qString *StoreTitle; // rax
  hkpNullContactMgr *v30; // rax
  hkpCollidable *v31; // rdx
  hkpCollidable *v32; // r8
  hkpCollisionInput *v33; // r9
  UFG::qString *v34; // rax
  bool mIsStore; // bl
  unsigned int v36; // edx
  UFG::qVector3 aabbMin; // [rsp+28h] [rbp-79h] BYREF
  float v38; // [rsp+34h] [rbp-6Dh]
  UFG::qVector3 max; // [rsp+38h] [rbp-69h] BYREF
  float v40; // [rsp+44h] [rbp-5Dh]
  Scaleform::GFx::Value ptr; // [rsp+48h] [rbp-59h] BYREF
  __int64 v42; // [rsp+78h] [rbp-29h]
  UFG::qString result; // [rsp+80h] [rbp-21h] BYREF
  UFG::qString v44; // [rsp+A8h] [rbp+7h] BYREF
  UFG::qString *p_result; // [rsp+108h] [rbp+67h]
  UFG::qString *v46; // [rsp+110h] [rbp+6Fh]

  v42 = -2i64;
  pObject = this->mRenderable->m_movie.pObject;
  if ( !pObject )
    return;
  UFG::UIHKScreenWardrobe::SaveCurrentClothingAsRestore(this);
  v3 = (UFG::qString *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                         Scaleform::Memory::pGlobalHeap,
                         32i64);
  p_result = v3;
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
  v46 = v3;
  LODWORD(v3->mData) |= 2u;
  pObject->Scaleform::GFx::StateBag::vfptr->SetState(
    &pObject->Scaleform::GFx::StateBag,
    State_Filter,
    (Scaleform::GFx::State *)v3);
  v4 = (hkpNullContactMgrFactory *)UFG::StoreFrontTracker::Instance();
  if ( v4 )
    ContactMgr = (UFG::StoreFront *)hkpNullContactMgrFactory::createContactMgr(v4, v5, v6, v7);
  else
    ContactMgr = 0i64;
  UFG::UIHKScreenWardrobe::SetStoreCamera(this, ContactMgr, eCS_INTIAL);
  UFG::UIHKScreenWardrobe::PopulateCategories(this, ContactMgr);
  v9 = LocalPlayer;
  if ( LocalPlayer )
  {
    m_Flags = LocalPlayer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(LocalPlayer);
    }
    else if ( (m_Flags & 0x2000) != 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)LocalPlayer);
    }
    else if ( (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                LocalPlayer,
                                                                UFG::CharacterAnimationComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                                LocalPlayer,
                                                                UFG::CharacterAnimationComponent::_TypeUID);
    }
  }
  else
  {
    ComponentOfTypeHK = 0i64;
  }
  CharacterDamageRig::ResetDamage(ComponentOfTypeHK->mDamageRig);
  if ( v9 )
    m_pTransformNodeComponent = v9->m_pTransformNodeComponent;
  else
    m_pTransformNodeComponent = 0i64;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  v13 = m_pTransformNodeComponent->mWorldTransform.v3.z - 5.0;
  v14 = m_pTransformNodeComponent->mWorldTransform.v3.y - 5.0;
  aabbMin.x = m_pTransformNodeComponent->mWorldTransform.v3.x - 5.0;
  aabbMin.y = v14;
  aabbMin.z = v13;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  v15 = m_pTransformNodeComponent->mWorldTransform.v3.z + 5.0;
  v16 = m_pTransformNodeComponent->mWorldTransform.v3.y + 5.0;
  aabbMin.z = m_pTransformNodeComponent->mWorldTransform.v3.x + 5.0;
  v38 = v16;
  max.x = v15;
  UFG::WheeledVehicleManager::DestroyWheeledVehiclesInNISBoundingVolume(
    UFG::WheeledVehicleManager::m_Instance,
    &aabbMin,
    (UFG::qVector3 *)&aabbMin.z);
  if ( v9 )
  {
    v17 = v9->m_Flags;
    if ( (v17 & 0x4000) != 0 || v17 < 0 || (v17 & 0x2000) != 0 || (v17 & 0x1000) != 0 )
      ComponentOfType = (UFG::VehicleOwnershipComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            v9,
                                                            UFG::VehicleOwnershipComponent::_TypeUID);
    else
      ComponentOfType = (UFG::VehicleOwnershipComponent *)UFG::SimObject::GetComponentOfType(
                                                            v9,
                                                            UFG::VehicleOwnershipComponent::_TypeUID);
    v19 = ComponentOfType;
    if ( ComponentOfType )
    {
      if ( UFG::VehicleOwnershipComponent::GetOwnedVehicle(ComponentOfType) )
      {
        OwnedVehicle = (UFG::SimObjectGame *)UFG::VehicleOwnershipComponent::GetOwnedVehicle(v19);
        v21 = OwnedVehicle;
        if ( OwnedVehicle )
        {
          v22 = OwnedVehicle->m_Flags;
          if ( (v22 & 0x4000) != 0 )
          {
            m_pComponent = OwnedVehicle->m_Components.p[14].m_pComponent;
          }
          else if ( v22 >= 0 )
          {
            if ( (v22 & 0x2000) != 0 )
              m_pComponent = OwnedVehicle->m_Components.p[9].m_pComponent;
            else
              m_pComponent = (v22 & 0x1000) != 0
                           ? UFG::SimObjectGame::GetComponentOfTypeHK(
                               OwnedVehicle,
                               UFG::CompositeDrawableComponent::_TypeUID)
                           : UFG::SimObject::GetComponentOfType(OwnedVehicle, UFG::CompositeDrawableComponent::_TypeUID);
          }
          else
          {
            m_pComponent = OwnedVehicle->m_Components.p[14].m_pComponent;
          }
          if ( m_pComponent )
          {
            mNext = m_pComponent[22].m_SafePointerList.mNode.mNext;
            if ( mNext )
            {
              v25 = *((float *)&mNext[8].mPrev + 1);
              v26 = (int)mNext[8].mNext;
              max.z = *(float *)&mNext[8].mPrev;
              v40 = v25;
              LODWORD(ptr.pPrev) = v26;
              v27 = *(float *)&mNext[9].mPrev;
              v28 = *((float *)&mNext[9].mPrev + 1);
              max.x = *((float *)&mNext[8].mNext + 1);
              max.y = v27;
              max.z = v28;
              TransformAABB((UFG::qMatrix44 *)&m_pComponent[20], (UFG::qVector3 *)&max.z, &max);
              if ( aabbMin.x <= max.x
                && aabbMin.z >= max.z
                && aabbMin.y <= max.y
                && v38 >= v40
                && aabbMin.z <= max.z
                && max.x >= *(float *)&ptr.pPrev )
              {
                UFG::SimObject::Suspend(v21);
                this->mSuspendedPlayerVehicle = v21;
              }
            }
          }
        }
      }
    }
  }
  if ( this->mIsStore )
  {
    p_result = &result;
    StoreTitle = UFG::StoreFront::GetStoreTitle(ContactMgr, &result);
    UFG::UIHKScreenWardrobe::SetStoreTitle(this, StoreTitle);
    if ( this->mNumCategories )
    {
      UFG::UIHKScreenWardrobe::ShowCategorySelect(this);
    }
    else
    {
      UFG::UIHKScreenWardrobe::PopulateInventory(this);
      this->mState = STATE_VOLUME;
    }
    ((void (__fastcall *)(UFG::TiDo *, __int64))UFG::TiDo::m_pInstance->vfptr[1].Close)(UFG::TiDo::m_pInstance, 5i64);
    v30 = (hkpNullContactMgr *)UFG::StoreFrontTracker::Instance();
    if ( v30 )
      v30 = hkpNullContactMgrFactory::createContactMgr((hkpNullContactMgrFactory *)v30, v31, v32, v33);
    UFG::VendorDialogueUtils::Setup((UFG::StoreFront *)v30);
    UFG::VendorDialogueUtils::PlayStoreClerkDialogue(eStoreClerkDialogueContext_Greet, 1.0);
  }
  else
  {
    p_result = &v44;
    UFG::qString::qString(&v44, "$WARDROBE_HEADING");
    UFG::UIHKScreenWardrobe::SetStoreTitle(this, v34);
    UFG::UIHKScreenWardrobe::ShowCategorySelect(this);
  }
  `eh vector constructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  mIsStore = this->mIsStore;
  if ( (ptr.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
      ptr.pObjectInterface,
      &ptr,
      ptr.mValue);
    ptr.pObjectInterface = 0i64;
  }
  ptr.Type = VT_Boolean;
  ptr.mValue.BValue = mIsStore;
  Scaleform::GFx::Movie::Invoke(pObject, "SetIsStore", 0i64, &ptr, 1u);
  if ( this->mIsStore )
  {
    if ( UFG::HudAudio::m_instance )
    {
      v36 = -1871061836;
LABEL_65:
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, v36, 0i64, 0, 0i64);
    }
  }
  else if ( UFG::HudAudio::m_instance )
  {
    v36 = -224882297;
    goto LABEL_65;
  }
  Render::EnableLightLayer(0x30ACCAD6u, 1);
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
  UFG::UIHK_NISOverlay::UpdateAudioMuteState();
  `eh vector destructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v3);
}

// File Line: 385
// RVA: 0x61E130
void __fastcall UFG::UIHKScreenWardrobe::afterFadeToBlackExit(UFG::UIHKScreenWardrobe *this)
{
  hkpNullContactMgr *ContactMgr; // rax
  hkpCollidable *v3; // rdx
  hkpCollidable *v4; // r8
  hkpCollisionInput *v5; // r9
  bool v6; // zf
  UFG::SimObject *mSuspendedPlayerVehicle; // rcx
  UFG::UIHKScreenGlobalOverlay *v8; // rdx
  UFG::UIHKHelpBarWidget *p_HelpBar; // rbx
  unsigned int v10; // eax
  UFG::SimComponent *ComponentOfType; // rax

  ContactMgr = (hkpNullContactMgr *)UFG::StoreFrontTracker::Instance();
  if ( ContactMgr )
    ContactMgr = hkpNullContactMgrFactory::createContactMgr((hkpNullContactMgrFactory *)ContactMgr, v3, v4, v5);
  UFG::UIHKScreenWardrobe::SetStoreCamera(this, (UFG::StoreFront *)ContactMgr, eCS_EXIT);
  v6 = !this->mIsStore;
  this->mFinished = 1;
  if ( !v6 )
  {
    UFG::VendorDialogueUtils::PlayStoreClerkDialogue(eStoreClerkDialogueContext_Exit, 1.0);
    ((void (__fastcall *)(UFG::TiDo *, __int64))UFG::TiDo::m_pInstance->vfptr[1].Close)(UFG::TiDo::m_pInstance, 4i64);
  }
  mSuspendedPlayerVehicle = this->mSuspendedPlayerVehicle;
  if ( mSuspendedPlayerVehicle )
  {
    UFG::SimObject::Restore(mSuspendedPlayerVehicle);
    this->mSuspendedPlayerVehicle = 0i64;
  }
  v8 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( UFG::UIHKScreenGlobalOverlay::mThis )
  {
    p_HelpBar = &UFG::UIHKScreenGlobalOverlay::mThis->HelpBar;
    v10 = UFG::qStringHash32("STORE", 0xFFFFFFFF);
    UFG::UIHKHelpBarWidget::Hide(p_HelpBar, v10);
    v8 = UFG::UIHKScreenGlobalOverlay::mThis;
  }
  if ( LocalPlayer )
  {
    ComponentOfType = UFG::SimObject::GetComponentOfType(LocalPlayer, UFG::ActionTreeComponent::_TypeUID);
    ActionController::Stop((ActionController *)&ComponentOfType[3]);
    v8 = UFG::UIHKScreenGlobalOverlay::mThis;
  }
  if ( v8 && v8 != (UFG::UIHKScreenGlobalOverlay *)-408i64 )
    UFG::UIHK_NISOverlay::HideElement(&v8->NISOverlay, v8, &UFG::UIHK_NISOverlay::m_curtains, 1.0, 0);
  UFG::UIHK_NISOverlay::UpdateAudioMuteState();
}

// File Line: 432
// RVA: 0x60F360
void __fastcall UFG::UIHKScreenWardrobe::ShowHelpBar(
        UFG::UIHKScreenWardrobe *this,
        UFG::UIHKScreenWardrobe::eHelpBarState eHelpState)
{
  int v4; // ecx
  __int64 v5; // rax
  __int64 v6; // rdi
  __int64 v7; // rbx
  int v8; // ecx
  __int64 v9; // rax
  __int64 v10; // rdi
  __int64 v11; // rbx
  int v12; // ecx
  __int64 i; // rax
  const char *v14; // rdx
  int v15; // ecx
  __int64 v16; // rax
  __int64 v17; // rdi
  __int64 v18; // rbx
  __int64 j; // rax
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
  UFG::UIHKHelpBarData data; // [rsp+20h] [rbp-D8h] BYREF
  __int64 v61; // [rsp+268h] [rbp+170h]

  v61 = -2i64;
  if ( UFG::UIHKScreenGlobalOverlay::mThis )
  {
    UFG::UIHKHelpBarData::UIHKHelpBarData(&data);
    data.id = UFG::qStringHash32("STORE", 0xFFFFFFFF);
    *(_QWORD *)&data.priority = 0i64;
    this->mHelpBarState = eHelpState;
    switch ( eHelpState )
    {
      case HELP_SELECT_ITEM_STORE:
        if ( !this->mIsStore && !UFG::StoreFront::IsWeiWearingAnPrefinedOutfit() )
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
          data.Buttons[v6] = ACCEPT_BUTTON;
          v7 = v4;
          UFG::qString::Set(&data.Captions[v7], "$COMMON_SELECT_UPPERCASE");
          UFG::qString::Set((UFG::qString *)&data.Captions[v7 + 5].mStringHash32, &customCaption);
          data.MessageIds[v6 - 2] = 0;
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
          data.Buttons[v10] = BUTTON1_BUTTON;
          v11 = v8;
          UFG::qString::Set(&data.Captions[v11], "$WARDROBE_SAVE_AS_OUTFIT_UPPERCASE");
          UFG::qString::Set((UFG::qString *)&data.Captions[v11 + 5].mStringHash32, &customCaption);
          data.MessageIds[v10 - 2] = 0;
LABEL_15:
          v12 = 0;
          for ( i = 0i64; i < 6; ++i )
          {
            if ( data.Buttons[i] == INVALID_BUTTON )
              goto LABEL_19;
            ++v12;
          }
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
        data.Buttons[v17] = ACCEPT_BUTTON;
        v18 = v15;
        UFG::qString::Set(&data.Captions[v18], "$COMMON_SELECT_UPPERCASE");
        UFG::qString::Set((UFG::qString *)&data.Captions[v18 + 5].mStringHash32, &customCaption);
        data.MessageIds[v17 - 2] = 0;
LABEL_25:
        v12 = 0;
        for ( j = 0i64; j < 6; ++j )
        {
          if ( data.Buttons[j] == INVALID_BUTTON )
            goto LABEL_19;
          ++v12;
        }
        goto LABEL_86;
      case HELP_SELECT_ITEM_RACE:
        v20 = 0;
        v21 = 0i64;
        while ( data.Buttons[v21] )
        {
          ++v20;
          if ( ++v21 >= 6 )
            goto LABEL_34;
        }
        v22 = v20;
        data.Buttons[v22] = ACCEPT_BUTTON;
        v23 = v20;
        UFG::qString::Set(&data.Captions[v23], "$WARDROBE_BUY_UPPERCASE");
        UFG::qString::Set((UFG::qString *)&data.Captions[v23 + 5].mStringHash32, &customCaption);
        data.MessageIds[v22 - 2] = 0;
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
        data.Buttons[v26] = BUTTON2_BUTTON;
        v27 = v24;
        UFG::qString::Set(&data.Captions[v27], "$COMMON_ZOOM_IN_UPPERCASE");
        UFG::qString::Set((UFG::qString *)&data.Captions[v27 + 5].mStringHash32, &customCaption);
        data.MessageIds[v26 - 2] = 0;
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
      case HELP_SELECT_ITEM_STORAGE:
        v29 = 0;
        v30 = 0i64;
        while ( data.Buttons[v30] )
        {
          ++v29;
          if ( ++v30 >= 6 )
            goto LABEL_48;
        }
        v31 = v29;
        data.Buttons[v31] = ACCEPT_BUTTON;
        v32 = v29;
        UFG::qString::Set(&data.Captions[v32], "$WARDROBE_WEAR_UPPERCASE");
        UFG::qString::Set((UFG::qString *)&data.Captions[v32 + 5].mStringHash32, &customCaption);
        data.MessageIds[v31 - 2] = 0;
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
        data.Buttons[v35] = BUTTON2_BUTTON;
        v36 = v33;
        UFG::qString::Set(&data.Captions[v36], "$COMMON_ZOOM_IN_UPPERCASE");
        UFG::qString::Set((UFG::qString *)&data.Captions[v36 + 5].mStringHash32, &customCaption);
        data.MessageIds[v35 - 2] = 0;
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
      case HELP_SELECT_ITEM_EMPTY:
      case HELP_SELECT_ITEM_EMPTY|HELP_SELECT_ITEM_STORE:
        v38 = 0;
        v39 = 0i64;
        while ( data.Buttons[v39] )
        {
          ++v38;
          if ( ++v39 >= 6 )
            goto LABEL_62;
        }
        v40 = v38;
        data.Buttons[v40] = ACCEPT_BUTTON;
        v41 = v38;
        UFG::qString::Set(&data.Captions[v41], "$WARDROBE_WEAR_UPPERCASE");
        UFG::qString::Set((UFG::qString *)&data.Captions[v41 + 5].mStringHash32, &customCaption);
        data.MessageIds[v40 - 2] = 0;
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
      case HELP_SELECT_ITEM_EMPTY|HELP_SELECT_ITEM_RACE:
        v43 = 0;
        v44 = 0i64;
        while ( data.Buttons[v44] )
        {
          ++v43;
          if ( ++v44 >= 6 )
            goto LABEL_71;
        }
        v45 = v43;
        data.Buttons[v45] = ACCEPT_BUTTON;
        v46 = v43;
        UFG::qString::Set(&data.Captions[v46], "$COMMON_SELECT_UPPERCASE");
        UFG::qString::Set((UFG::qString *)&data.Captions[v46 + 5].mStringHash32, &customCaption);
        data.MessageIds[v45 - 2] = 0;
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
        data.Buttons[v49] = BUTTON2_BUTTON;
        v50 = v47;
        UFG::qString::Set(&data.Captions[v50], "$WARDROBE_PREVIEW_OUTFIT");
        UFG::qString::Set((UFG::qString *)&data.Captions[v50 + 5].mStringHash32, &customCaption);
        data.MessageIds[v49 - 2] = 0;
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
      case HELP_SELECT_ITEM_EMPTY|HELP_SELECT_ITEM_STORAGE:
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
    data.Buttons[v53] = BACK_BUTTON;
    UFG::qString::Set(&data.Captions[v54], v14);
    UFG::qString::Set((UFG::qString *)&data.Captions[v54 + 5].mStringHash32, &customCaption);
    data.MessageIds[v53 - 2] = 0;
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
    data.Buttons[v57] = L1R1_BUTTON;
    v58 = v55;
    UFG::qString::Set(&data.Captions[v58], "$WARDROBE_ROTATE");
    UFG::qString::Set((UFG::qString *)&data.Captions[v58 + 5].mStringHash32, &customCaption);
    data.MessageIds[v57 - 2] = 0;
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
void __fastcall UFG::UIHKScreenWardrobe::ZoomIn(UFG::UIHKScreenWardrobe *this)
{
  hkpNullContactMgrFactory *v2; // rax
  hkpCollidable *v3; // rdx
  hkpCollidable *v4; // r8
  hkpCollisionInput *v5; // r9
  UFG::StoreFront *ContactMgr; // rdx
  Scaleform::GFx::Movie *pObject; // rbx

  v2 = (hkpNullContactMgrFactory *)UFG::StoreFrontTracker::Instance();
  if ( v2 )
    ContactMgr = (UFG::StoreFront *)hkpNullContactMgrFactory::createContactMgr(v2, v3, v4, v5);
  else
    ContactMgr = 0i64;
  pObject = this->mRenderable->m_movie.pObject;
  UFG::UIHKScreenWardrobe::SetStoreCamera(this, ContactMgr, eCS_ZOOM_IN);
  Scaleform::GFx::Movie::Invoke(pObject, "ZoomInStart", 0i64, 0i64, 0);
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x1F5AAC5Bu, 0i64, 0, 0i64);
  this->mOldHelpbarState = this->mHelpBarState;
  this->mState = STATE_BRIGHTNESS;
  UFG::UIHKScreenWardrobe::ShowHelpBar(this, HELP_SELECT_ITEM_EMPTY|HELP_SELECT_ITEM_STORAGE);
}

// File Line: 513
// RVA: 0x61DCA0
void __fastcall UFG::UIHKScreenWardrobe::ZoomOut(UFG::UIHKScreenWardrobe *this)
{
  hkpNullContactMgrFactory *v2; // rax
  hkpCollidable *v3; // rdx
  hkpCollidable *v4; // r8
  hkpCollisionInput *v5; // r9
  UFG::StoreFront *ContactMgr; // rdx
  Scaleform::GFx::Movie *pObject; // rbx
  UFG::UIHKScreenWardrobe::eHelpBarState mOldHelpbarState; // edx

  v2 = (hkpNullContactMgrFactory *)UFG::StoreFrontTracker::Instance();
  if ( v2 )
    ContactMgr = (UFG::StoreFront *)hkpNullContactMgrFactory::createContactMgr(v2, v3, v4, v5);
  else
    ContactMgr = 0i64;
  pObject = this->mRenderable->m_movie.pObject;
  UFG::UIHKScreenWardrobe::SetStoreCamera(this, ContactMgr, eCS_ZOOM_OUT);
  Scaleform::GFx::Movie::Invoke(pObject, "ZoomInEnd", 0i64, 0i64, 0);
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xFAFA25CA, 0i64, 0, 0i64);
  mOldHelpbarState = this->mOldHelpbarState;
  this->mState = STATE_VOLUME;
  UFG::UIHKScreenWardrobe::ShowHelpBar(this, mOldHelpbarState);
}

// File Line: 521
// RVA: 0x609CE0
void __fastcall UFG::UIHKScreenWardrobe::SetStoreTitle(UFG::UIHKScreenWardrobe *this, UFG::qString *a_Title)
{
  Scaleform::GFx::Movie *pObject; // rdi
  UFG::qString *v4; // rcx
  char *mData; // rsi
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-40h] BYREF

  pObject = this->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    value.pObjectInterface = 0i64;
    value.Type = VT_Undefined;
    mData = a_Title->mData;
    value.Type = VT_String;
    value.mValue.pString = mData;
    Scaleform::GFx::Movie::SetVariable(pObject, "mcTitle.text", &value, 1i64);
    if ( (value.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        value.mValue);
      value.pObjectInterface = 0i64;
    }
    value.Type = VT_Undefined;
    v4 = a_Title;
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
  Scaleform::GFx::Movie *pObject; // rdi
  UFG::qString *v4; // rcx
  char *mData; // rsi
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-40h] BYREF

  pObject = this->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    value.pObjectInterface = 0i64;
    value.Type = VT_Undefined;
    mData = a_Desc->mData;
    value.Type = VT_String;
    value.mValue.pString = mData;
    Scaleform::GFx::Movie::SetVariable(pObject, "mcDesc.htmlText", &value, 1i64);
    if ( (value.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        value.mValue);
      value.pObjectInterface = 0i64;
    }
    value.Type = VT_Undefined;
    v4 = a_Desc;
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

// File Line: 557
// RVA: 0x603720
void __fastcall UFG::UIHKScreenWardrobe::SaveCurrentClothingAsRestore(UFG::UIHKScreenWardrobe *this)
{
  UFG::GameStatTracker *v2; // rbx

  v2 = UFG::GameStatTracker::Instance();
  this->mInitClothing[1].mUID = UFG::GameStatTracker::GetStat(v2, CurrentLowerBody)->mValue.mUID;
  this->mInitClothing[2].mUID = UFG::GameStatTracker::GetStat(v2, CurrentFootwear)->mValue.mUID;
  this->mInitClothing[3].mUID = UFG::GameStatTracker::GetStat(v2, CurrentHeadgear)->mValue.mUID;
  this->mInitClothing[4].mUID = UFG::GameStatTracker::GetStat(v2, CurrentHead)->mValue.mUID;
  this->mInitClothing[0].mUID = UFG::GameStatTracker::GetStat(v2, CurrentBody)->mValue.mUID;
  this->mInitClothing[5].mUID = UFG::GameStatTracker::GetStat(v2, CurrentAccessories)->mValue.mUID;
  this->mInitClothing[6].mUID = UFG::GameStatTracker::GetStat(v2, CurrentGlasses)->mValue.mUID;
  this->mInitClothing[7].mUID = UFG::GameStatTracker::GetStat(v2, CurrentNeck)->mValue.mUID;
  this->mInitClothing[8].mUID = UFG::GameStatTracker::GetStat(v2, CurrentLeftWrist)->mValue.mUID;
  this->mInitClothing[9].mUID = UFG::GameStatTracker::GetStat(v2, CurrentRightWrist)->mValue.mUID;
  this->mInitClothing[10].mUID = UFG::GameStatTracker::GetStat(v2, CurrentOutfit)->mValue.mUID;
}

// File Line: 574
// RVA: 0x5EA950
void __fastcall UFG::UIHKScreenWardrobe::HandleDeferredTask(UFG::UIHKScreenWardrobe *this, UFG::Event *e)
{
  int mUserData0; // r8d

  mUserData0 = e->mUserData0;
  if ( mUserData0 )
  {
    if ( mUserData0 == 1 )
      UFG::UIHKScreenWardrobe::afterFadeToBlackExit(this);
  }
  else
  {
    UFG::UIHKScreenWardrobe::afterFadeToBlackInit(this);
  }
}

// File Line: 599
// RVA: 0x62DB40
bool __fastcall UFG::UIHKScreenWardrobe::handleMessage(
        UFG::UIHKScreenWardrobe *this,
        unsigned int msgId,
        UFG::UIMessage *msg)
{
  UFG::allocator::free_link *v6; // rax
  UFG::Event *v7; // rax
  UFG::Event *v8; // rdx
  UFG::UIHK_NISOverlay *p_NISOverlay; // rax
  UFG::HudAudio *v11; // rcx
  unsigned int v12; // edx
  int SelectedTrackerIndex; // r14d
  hkpNullContactMgrFactory *v14; // rax
  hkpCollidable *v15; // rdx
  hkpCollidable *v16; // r8
  hkpCollisionInput *v17; // r9
  UFG::StoreFront *ContactMgr; // rbp
  UFG::qPropertySet *Item; // rax
  int SelectedIndex; // eax
  UFG::qPropertySet *v21; // rax
  UFG::qPropertySet *v22; // rax
  UFG::UIHK_NISOverlay *v23; // rax
  int SelectedCategory; // esi
  UFG::UIHK_NISOverlay *v25; // rax
  bool v26; // zf
  UFG::UIHK_NISOverlay *v27; // rax
  int v28; // eax
  UFG::allocator::free_link *v29; // rax
  UFG::Event *v30; // rax
  UFG::Event *v31; // rsi

  if ( msgId == UI_HASH_GAME_OVER_20 )
    UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, this->mScreenUID);
  switch ( this->mState )
  {
    case 1:
      if ( msgId == UI_HASH_BUTTON_BACK_PRESSED_30 )
        UFG::UIHKScreenWardrobe::ZoomOut(this);
      return UFG::UIScreen::handleMessage(this, msgId, msg);
    case 2:
      if ( UFG::UIHKScreenGlobalOverlay::mThis )
        p_NISOverlay = &UFG::UIHKScreenGlobalOverlay::mThis->NISOverlay;
      else
        p_NISOverlay = 0i64;
      if ( p_NISOverlay->mActive && msg->m_messageType <= (unsigned int)UIMESSAGE_MOUSE_INPUT )
        return 1;
      if ( msgId == UI_HASH_PURCHASE_ITEM || msgId == UI_HASH_PURCHASE_AND_EQUIP_ITEM )
      {
        SelectedTrackerIndex = UFG::UIHKScreenWardrobe::GetSelectedTrackerIndex(this);
        v14 = (hkpNullContactMgrFactory *)UFG::StoreFrontTracker::Instance();
        if ( v14 )
          ContactMgr = (UFG::StoreFront *)hkpNullContactMgrFactory::createContactMgr(v14, v15, v16, v17);
        else
          ContactMgr = 0i64;
        if ( UFG::StoreFront::PurchaseItem(ContactMgr, SelectedTrackerIndex) )
        {
          Item = UFG::StoreFront::GetItem(ContactMgr, SelectedTrackerIndex);
          UFG::VendorDialogueUtils::SetLastItemPurchased(Item);
          if ( UFG::HudAudio::m_instance )
            UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xDC33EA39, 0i64, 0, 0i64);
          UFG::UIHKScreenWardrobe::UpdateMoney(this);
        }
        if ( msgId == UI_HASH_PURCHASE_AND_EQUIP_ITEM )
        {
          SelectedIndex = UFG::UIHKScreenWardrobe::GetSelectedIndex(this);
          v21 = UFG::StoreFront::GetItem(ContactMgr, SelectedIndex);
          UFG::UIHKScreenWardrobe::EquipItem(this, v21, 1, 1, 1, 1, 0);
          UFG::UIHKScreenWardrobe::UpdateMoney(this);
          UFG::UIHKScreenWardrobe::ShowCategorySelect(this);
          UFG::StoreFront::CheckAchievement();
          if ( UFG::GameStatAction::Store::AreAllClothesPurchased() )
            UFG::AchievementTrophyManager::UnlockAchievementTrophy(37);
          this->mHasClothingChanged = 1;
        }
        else
        {
          UFG::UIHKScreenWardrobe::PopulateInventory(this);
        }
        v22 = UFG::StoreFront::GetItem(ContactMgr, SelectedTrackerIndex);
        UFG::VendorDialogueUtils::sm_moneySpent = UFG::VendorDialogueUtils::sm_moneySpent
                                                + UFG::StoreFrontTracker::GetItemPriceBasedOnClothes(v22);
        UFG::VendorDialogueUtils::PlayStoreClerkDialogue(eStoreClerkDialogueContext_Sale, 1.0);
        return UFG::UIScreen::handleMessage(this, msgId, msg);
      }
      if ( msgId == UI_HASH_OPTION_HIGHLIGHTED_30 )
      {
        UFG::UIHKScreenWardrobe::HandleOptionHighlighted(this);
        return 1;
      }
      if ( msgId == UI_HASH_BUTTON_BACK_PRESSED_30 )
      {
        if ( UFG::HudAudio::m_instance )
          UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xA4E5BFBD, 0i64, 0, 0i64);
        UFG::UIHKScreenWardrobe::RestoreNonPurchasedEquipment(this, 0);
        if ( this->mNumCategories && this->mNumItems )
        {
          UFG::UIHKScreenWardrobe::ShowCategorySelect(this);
          return 1;
        }
        UFG::UIHKScreenWardrobe::Exit(this);
        return 1;
      }
      if ( msgId == UI_HASH_BUTTON_ACCEPT_PRESSED_30 )
      {
        if ( UFG::HudAudio::m_instance )
          UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xCCF5DDCu, 0i64, 0, 0i64);
        UFG::UIHKScreenWardrobe::HandleOptionSelected(this);
        if ( this->mIsStore )
          return 1;
        this->mHasClothingChanged = 1;
        UFG::StoreFront::CheckAchievement();
        return 1;
      }
      if ( msgId == (_DWORD)UI_HASH_BUTTON_BUTTON2_PRESSED_30 )
      {
        UFG::UIHKScreenWardrobe::ZoomIn(this);
        return UFG::UIScreen::handleMessage(this, msgId, msg);
      }
      if ( msgId != UI_HASH_FADE_OUT_COMPLETE_30 )
        goto LABEL_39;
      return UFG::UIScreen::handleMessage(this, msgId, msg);
    case 3:
      if ( UFG::UIHKScreenGlobalOverlay::mThis )
        v23 = &UFG::UIHKScreenGlobalOverlay::mThis->NISOverlay;
      else
        v23 = 0i64;
      if ( v23->mActive && msg->m_messageType <= (unsigned int)UIMESSAGE_MOUSE_INPUT )
        return 1;
      if ( msgId == UI_HASH_DIALOG_YES_30 )
      {
        UFG::StoreFront::PreviewRemoveCustomOutfit();
LABEL_68:
        UFG::UIHKScreenWardrobe::CategorySelect_HandleOptionSelected(this);
        return UFG::UIScreen::handleMessage(this, msgId, msg);
      }
      if ( msgId != UI_HASH_BUTTON_ACCEPT_PRESSED_30 )
      {
        if ( msgId == UI_HASH_BUTTON_BACK_PRESSED_30 )
        {
          if ( UFG::HudAudio::m_instance )
            UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xA4E5BFBD, 0i64, 0, 0i64);
          UFG::UIHKScreenWardrobe::Exit(this);
          return UFG::UIScreen::handleMessage(this, msgId, msg);
        }
        if ( msgId == UI_HASH_OPTION_HIGHLIGHTED_30 )
        {
LABEL_123:
          v11 = UFG::HudAudio::m_instance;
          if ( !UFG::HudAudio::m_instance )
            return UFG::UIScreen::handleMessage(this, msgId, msg);
          v12 = 1706059527;
          goto LABEL_125;
        }
        if ( msgId == UI_HASH_BUTTON_BUTTON1_PRESSED_30 )
        {
          UFG::UIHKScreenWardrobe::CategorySelect_HandleSaveCustomOutfit(this);
          return UFG::UIScreen::handleMessage(this, msgId, msg);
        }
        if ( msgId == UI_HASH_BUTTON_SELECT_PRESSED_30 )
        {
          if ( !this->mIsRestricted )
            UFG::UIHKScreenWardrobe::CategorySelect_HandleToggleTickerPopup(this);
          return UFG::UIScreen::handleMessage(this, msgId, msg);
        }
LABEL_39:
        if ( msgId != UI_HASH_DPAD_UP_PRESSED_30 )
        {
          if ( msgId == UI_HASH_DPAD_DOWN_PRESSED_30 || msgId == UI_HASH_THUMBSTICK_LEFT_DOWN_30 )
          {
            if ( msgId != UI_HASH_THUMBSTICK_LEFT_UP_30 )
            {
              v11 = UFG::HudAudio::m_instance;
              if ( !UFG::HudAudio::m_instance )
                return UFG::UIScreen::handleMessage(this, msgId, msg);
              v12 = 192470248;
LABEL_125:
              UFG::AudioEntity::CreateAndPlayEvent(v11, v12, 0i64, 0, 0i64);
              return UFG::UIScreen::handleMessage(this, msgId, msg);
            }
          }
          else if ( msgId != UI_HASH_THUMBSTICK_LEFT_UP_30 )
          {
            return UFG::UIScreen::handleMessage(this, msgId, msg);
          }
        }
        v11 = UFG::HudAudio::m_instance;
        if ( !UFG::HudAudio::m_instance )
          return UFG::UIScreen::handleMessage(this, msgId, msg);
        v12 = 1497067691;
        goto LABEL_125;
      }
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xCCF5DDCu, 0i64, 0, 0i64);
      this->mSfxPlayed = 1;
      SelectedCategory = UFG::UIHKScreenWardrobe::GetSelectedCategory(this);
      if ( !UFG::StoreFront::IsWeiWearingAnPrefinedOutfit() || SelectedCategory == 10 )
        goto LABEL_68;
      UFG::UIScreenDialogBox::createYesNoDialog(this, &customCaption, "$STORE_REMOVE_OUTFIT", 0, 0);
      return UFG::UIScreen::handleMessage(this, msgId, msg);
    case 4:
      if ( UFG::UIHKScreenGlobalOverlay::mThis )
        v25 = &UFG::UIHKScreenGlobalOverlay::mThis->NISOverlay;
      else
        v25 = 0i64;
      if ( v25->mActive )
        return 1;
      if ( msgId == UI_HASH_BUTTON_ACCEPT_PRESSED_30 )
      {
        if ( UFG::HudAudio::m_instance )
          UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xCCF5DDCu, 0i64, 0, 0i64);
        UFG::UIHKScreenWardrobe::CustomOutfit_HandleOptionSelected(this);
        UFG::UIHKScreenWardrobe::ShowCategorySelect(this);
      }
      else
      {
        if ( msgId == UI_HASH_BUTTON_BACK_PRESSED_30 )
          goto LABEL_94;
        if ( msgId == UI_HASH_OPTION_HIGHLIGHTED_30 )
        {
          UFG::UIHKScreenWardrobe::HandleOptionHighlighted(this);
          return UFG::UIScreen::handleMessage(this, msgId, msg);
        }
        if ( msgId == UI_HASH_DPAD_UP_PRESSED_30
          || msgId == UI_HASH_DPAD_DOWN_PRESSED_30
          || msgId == UI_HASH_THUMBSTICK_LEFT_DOWN_30
          || msgId == UI_HASH_THUMBSTICK_LEFT_UP_30 )
        {
          v26 = !this->mSfxPlayed;
          goto LABEL_122;
        }
      }
      return UFG::UIScreen::handleMessage(this, msgId, msg);
    case 5:
      if ( UFG::UIHKScreenGlobalOverlay::mThis )
        v27 = &UFG::UIHKScreenGlobalOverlay::mThis->NISOverlay;
      else
        v27 = 0i64;
      if ( v27->mActive )
        return 1;
      if ( msgId == UI_HASH_DIALOG_YES_30 )
        goto LABEL_109;
      if ( msgId == UI_HASH_BUTTON_ACCEPT_PRESSED_30 )
      {
        if ( UFG::HudAudio::m_instance )
          UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x4A3D1F6Cu, 0i64, 0, 0i64);
        v28 = UFG::UIHKScreenWardrobe::GetSelectedIndex(this);
        this->mSelectedIndex = v28;
        if ( UFG::UIHKScreenWardrobe::IsCustomOutfitSlotInUse(this, (UFG::StoreFront::OutfitNum)v28) )
        {
          UFG::UIScreenDialogBox::createYesNoDialog(this, &customCaption, "$WARDROBE_OVERWRITE_OUTFIT", 0, 0);
        }
        else
        {
LABEL_109:
          UFG::UIHKScreenWardrobe::SaveCurrentClothingAsOutfit(this, (UFG::StoreFront::OutfitNum)this->mSelectedIndex);
          UFG::UIHKScreenWardrobe::ShowCategorySelect(this);
        }
        return UFG::UIScreen::handleMessage(this, msgId, msg);
      }
      if ( msgId == UI_HASH_BUTTON_BACK_PRESSED_30 )
      {
LABEL_94:
        if ( UFG::HudAudio::m_instance )
          UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xA4E5BFBD, 0i64, 0, 0i64);
        UFG::UIHKScreenWardrobe::RestoreNonPurchasedEquipment(this, 0);
        UFG::UIHKScreenWardrobe::ShowCategorySelect(this);
        return 1;
      }
      if ( msgId == (_DWORD)UI_HASH_BUTTON_BUTTON2_PRESSED_30 )
      {
        UFG::UIHKScreenWardrobe::PreviewOutfit(this);
        return UFG::UIScreen::handleMessage(this, msgId, msg);
      }
      if ( msgId == UI_HASH_BUTTON_BUTTON2_RELEASED_30 )
      {
        UFG::UIHKScreenWardrobe::RestoreNonPurchasedEquipment(this, 1);
        return UFG::UIScreen::handleMessage(this, msgId, msg);
      }
      v26 = msgId == UI_HASH_OPTION_HIGHLIGHTED_30;
LABEL_122:
      if ( v26 )
        goto LABEL_123;
      return UFG::UIScreen::handleMessage(this, msgId, msg);
    case 6:
      if ( msgId != UI_HASH_DIALOG_OK_30 )
        return UFG::UIScreen::handleMessage(this, msgId, msg);
      this->mState = STATE_VOLUME;
      return 1;
    case 7:
      if ( msgId != UI_HASH_SCREEN_FADE_IN_COMPLETE_12 )
        return UFG::UIScreen::handleMessage(this, msgId, msg);
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xEDABFAC7, 0i64, 0, 0i64);
      v6 = UFG::qMalloc(0x38ui64, "UIWardrobeScreenDeferredTaskChannel", 0i64);
      if ( v6 )
        UFG::Event::Event((UFG::Event *)v6, UFG::gUIWardrobeScreenDeferredTaskChannel.mName);
      else
        v7 = 0i64;
      v7->mUserData0 = 0i64;
      v8 = v7;
      goto LABEL_11;
    case 8:
      if ( msgId != UI_HASH_SCREEN_FADE_IN_COMPLETE_12 )
        return UFG::UIScreen::handleMessage(this, msgId, msg);
      v29 = UFG::qMalloc(0x38ui64, "UIWardrobeScreenDeferredTaskChannel", 0i64);
      if ( v29 )
      {
        UFG::Event::Event((UFG::Event *)v29, UFG::gUIWardrobeScreenDeferredTaskChannel.mName);
        v31 = v30;
      }
      else
      {
        v31 = 0i64;
      }
      v31->mUserData0 = 1i64;
      v8 = v31;
LABEL_11:
      UFG::EventDispatcher::QueueEvent(&UFG::EventDispatcher::mInstance, v8);
      return 1;
    default:
      return UFG::UIScreen::handleMessage(this, msgId, msg);
  }
}

// File Line: 941
// RVA: 0x5D4A30
void __fastcall UFG::UIHKScreenWardrobe::CategorySelect_HandleSaveCustomOutfit(UFG::UIHKScreenWardrobe *this)
{
  Scaleform::GFx::Movie *pObject; // rcx
  hkpNullContactMgrFactory *v3; // rax
  hkpCollidable *v4; // rdx
  hkpCollidable *v5; // r8
  hkpCollisionInput *v6; // r9
  UFG::qString *v7; // rax
  UFG::qString v8; // [rsp+38h] [rbp-30h] BYREF

  if ( !this->mIsStore )
  {
    this->mState = STATE_VOLUME;
    pObject = this->mRenderable->m_movie.pObject;
    if ( pObject )
      Scaleform::GFx::Movie::Invoke(pObject, "HideCategorySelect", 0i64, 0i64, 0);
    this->mState = NUM_CALIBRATION_STATES|STATE_BRIGHTNESS;
    UFG::UIHKScreenWardrobe::Flash_CustomOutfit(this);
    UFG::UIHKScreenWardrobe::PopulateCustomOutfits(this);
    UFG::UIHKScreenWardrobe::ShowHelpBar(this, HELP_SELECT_ITEM_EMPTY|HELP_SELECT_ITEM_RACE);
    v3 = (hkpNullContactMgrFactory *)UFG::StoreFrontTracker::Instance();
    if ( v3 )
    {
      if ( hkpNullContactMgrFactory::createContactMgr(v3, v4, v5, v6) )
      {
        UFG::qString::qString(&v8, "$WARDROBE_SAVE_OUTFIT");
        UFG::UIHKScreenWardrobe::SetStoreDesc(this, v7);
      }
    }
  }
}

// File Line: 963
// RVA: 0x5DA540
void __fastcall UFG::UIHKScreenWardrobe::Flash_CustomOutfit(UFG::UIHKScreenWardrobe *this)
{
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-40h] BYREF

  pObject = this->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    value.pObjectInterface = 0i64;
    value.Type = VT_Boolean;
    value.mValue.BValue = 1;
    Scaleform::GFx::Movie::SetVariable(pObject, "mOutfitSave", &value, 1i64);
    if ( (value.Type & 0x40) != 0 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        value.mValue);
  }
}

// File Line: 974
// RVA: 0x5D4AF0
void __fastcall UFG::UIHKScreenWardrobe::CategorySelect_HandleToggleTickerPopup(UFG::UIHKScreenWardrobe *this)
{
  bool v2; // dl
  unsigned int v3; // edx

  v2 = !this->mInfoTickerPopupVisible;
  this->mInfoTickerPopupVisible = v2;
  UFG::UIHKScreenWardrobe::ShowTickerPopup(this, v2);
  UFG::UIHKScreenWardrobe::ShowHelpBar(this, this->mHelpBarState);
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

// File Line: 986
// RVA: 0x6404D0
void __fastcall UFG::UIHKScreenWardrobe::update(UFG::UIHKScreenWardrobe *this, float elapsed)
{
  float v3; // xmm0_4
  hkpNullContactMgrFactory *v4; // rax
  hkpCollidable *v5; // rdx
  hkpCollidable *v6; // r8
  hkpCollisionInput *v7; // r9
  UFG::StoreFront *ContactMgr; // rdi
  UFG::SimComponent *ComponentOfType; // rax
  UFG::OSuiteTickerManager *v10; // rax
  UFG::UIHKScreenWardrobe::eCameraState v11; // r8d
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-50h] BYREF

  this->mSfxPlayed = 0;
  UFG::UIScreen::update(this, elapsed);
  v3 = UFG::VendorDialogueUtils::sm_idleTime + elapsed;
  UFG::VendorDialogueUtils::sm_idleTime = v3;
  if ( v3 >= UFG::VendorDialogueUtils::sm_vendorHurryUpTimeOut )
  {
    UFG::VendorDialogueUtils::PlayStoreClerkDialogue(eStoreClerkDialogueContext_HurryUp, 1.0);
    v3 = UFG::VendorDialogueUtils::sm_idleTime;
  }
  if ( UFG::VendorDialogueUtils::sm_playBrowse > 0 && v3 > 1.0 )
  {
    UFG::VendorDialogueUtils::PlayStoreClerkDialogue(eStoreClerkDialogueContext_Browse, 1.0);
    UFG::VendorDialogueUtils::sm_playBrowse = 0;
  }
  v4 = (hkpNullContactMgrFactory *)UFG::StoreFrontTracker::Instance();
  if ( v4 )
    ContactMgr = (UFG::StoreFront *)hkpNullContactMgrFactory::createContactMgr(v4, v5, v6, v7);
  else
    ContactMgr = 0i64;
  if ( LocalPlayer )
  {
    ComponentOfType = UFG::SimObject::GetComponentOfType(LocalPlayer, UFG::CharacterLookComponent::_TypeUID);
    if ( ComponentOfType )
    {
      HIDWORD(ComponentOfType[2].m_BoundComponentHandles.mNode.mNext) = 0;
      UFG::CompositeLookComponent::ForceVisibleTransparency((UFG::CompositeLookComponent *)ComponentOfType);
    }
  }
  if ( !this->mInfoTickerTextSet )
  {
    pargs.pObjectInterface = 0i64;
    v10 = UFG::OSuiteTickerManager::Instance();
    pargs.Type = VT_String;
    pargs.mValue.pString = UFG::OSuiteTickerManager::GetTickerDescription(v10, (hkgpIndexedMeshDefinitions::Edge *)1, 0);
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
  if ( UFG::UIHKTweakables::WardrobeTuneCamera && ContactMgr )
  {
    if ( this->mState == STATE_BRIGHTNESS )
    {
      v11 = eCS_ZOOM_IN;
    }
    else
    {
      if ( this->mState != STATE_VOLUME )
        return;
      v11 = eCS_ZOOM_OUT;
    }
    UFG::UIHKScreenWardrobe::SetStoreCamera(this, ContactMgr, v11);
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
  bool v2; // zf
  unsigned int v3; // edx

  Scaleform::GFx::Movie::Invoke(this->mRenderable->m_movie.pObject, "Animate_Outro", 0i64, 0i64, 0);
  v2 = !this->mIsStore;
  this->mState = 8;
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
    UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, v3, 0i64, 0, 0i64);
  }
  Render::EnableLightLayer(0x30ACCAD6u, 0);
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

// File Line: 1064
// RVA: 0x5E8F90
__int64 __fastcall UFG::UIHKScreenWardrobe::GetSelectedIndex(UFG::UIHKScreenWardrobe *this)
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
  if ( (int)pval.mValue.NValue >= this->mNumItems )
    NValue = 0;
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

// File Line: 1083
// RVA: 0x5E9350
__int64 __fastcall UFG::UIHKScreenWardrobe::GetSelectedTrackerIndex(UFG::UIHKScreenWardrobe *this)
{
  Scaleform::GFx::Movie *pObject; // rcx
  unsigned int NValue; // ebx
  Scaleform::GFx::Value pval; // [rsp+28h] [rbp-40h] BYREF

  pObject = this->mRenderable->m_movie.pObject;
  if ( !pObject )
    return 0i64;
  pval.pObjectInterface = 0i64;
  pval.Type = VT_Undefined;
  Scaleform::GFx::Movie::GetVariable(pObject, &pval, "TrackerIndex");
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

// File Line: 1098
// RVA: 0x5FE3F0
void __fastcall UFG::UIHKScreenWardrobe::PreviewOutfit(UFG::UIHKScreenWardrobe *this)
{
  hkpNullContactMgrFactory *v2; // rax
  hkpCollidable *v3; // rdx
  hkpCollidable *v4; // r8
  hkpCollisionInput *v5; // r9
  UFG::StoreFront::OutfitNum SelectedIndex; // eax

  v2 = (hkpNullContactMgrFactory *)UFG::StoreFrontTracker::Instance();
  if ( v2 )
  {
    if ( hkpNullContactMgrFactory::createContactMgr(v2, v3, v4, v5) )
    {
      SelectedIndex = (unsigned int)UFG::UIHKScreenWardrobe::GetSelectedIndex(this);
      UFG::StoreFront::EquipCustomOutfit(SelectedIndex, 0, 1);
    }
  }
}

// File Line: 1110
// RVA: 0x602D60
void __fastcall UFG::UIHKScreenWardrobe::RestoreNonPurchasedEquipment(UFG::UIHKScreenWardrobe *this, bool isOutfit)
{
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
  UFG::qSymbol *mInitClothing; // rbx
  __int64 v16; // rsi
  UFG::StoreFrontTracker *v17; // rax
  UFG::qPropertySet *ItemSlow; // rdi
  hkpNullContactMgrFactory *v19; // rax
  hkpCollidable *v20; // rdx
  hkpCollidable *v21; // r8
  hkpCollisionInput *v22; // r9
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value pDtor; // [rsp+20h] [rbp-21h] BYREF
  int ptr[20]; // [rsp+50h] [rbp+Fh] BYREF

  v4 = (hkpNullContactMgrFactory *)UFG::StoreFrontTracker::Instance();
  if ( v4 && hkpNullContactMgrFactory::createContactMgr(v4, v5, v6, v7) )
  {
    v8 = UFG::GameStatTracker::Instance();
    pDtor.pPrev = (Scaleform::GFx::Value *)_;
    `eh vector constructor iterator(ptr, 4ui64, 14, (void (__fastcall *)(void *))BackInfo::BackInfo);
    ptr[1] = UFG::GameStatTracker::GetStat(v8, CurrentLowerBody)->mValue.mUID;
    ptr[2] = UFG::GameStatTracker::GetStat(v8, CurrentFootwear)->mValue.mUID;
    ptr[3] = UFG::GameStatTracker::GetStat(v8, CurrentHeadgear)->mValue.mUID;
    ptr[4] = UFG::GameStatTracker::GetStat(v8, CurrentHead)->mValue.mUID;
    ptr[0] = UFG::GameStatTracker::GetStat(v8, CurrentBody)->mValue.mUID;
    ptr[5] = UFG::GameStatTracker::GetStat(v8, CurrentAccessories)->mValue.mUID;
    ptr[6] = UFG::GameStatTracker::GetStat(v8, CurrentGlasses)->mValue.mUID;
    ptr[7] = UFG::GameStatTracker::GetStat(v8, CurrentNeck)->mValue.mUID;
    ptr[8] = UFG::GameStatTracker::GetStat(v8, CurrentLeftWrist)->mValue.mUID;
    ptr[9] = UFG::GameStatTracker::GetStat(v8, CurrentRightWrist)->mValue.mUID;
    ptr[10] = UFG::GameStatTracker::GetStat(v8, CurrentOutfit)->mValue.mUID;
    if ( this->mInitClothing[10].mUID == -1 )
    {
      mInitClothing = this->mInitClothing;
      v16 = 14i64;
      do
      {
        v17 = UFG::StoreFrontTracker::Instance();
        ItemSlow = UFG::StoreFrontTracker::FindItemSlow(v17, mInitClothing);
        if ( ItemSlow )
        {
          v19 = (hkpNullContactMgrFactory *)UFG::StoreFrontTracker::Instance();
          if ( v19 )
          {
            if ( hkpNullContactMgrFactory::createContactMgr(v19, v20, v21, v22) )
              UFG::StoreFront::EquipItem(ItemSlow, 1, 0, 1, 0, 0);
          }
        }
        ++mInitClothing;
        --v16;
      }
      while ( v16 );
    }
    else
    {
      v9 = UFG::StoreFrontTracker::Instance();
      v10 = UFG::StoreFrontTracker::FindItemSlow(v9, &this->mInitClothing[10]);
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
    UFG::StoreMeshHelper::QueueSwapping(LocalPlayer);
    pObject = this->mRenderable->m_movie.pObject;
    if ( pObject )
    {
      pDtor.pObjectInterface = 0i64;
      pDtor.Type = VT_Boolean;
      pDtor.mValue.BValue = isOutfit;
      Scaleform::GFx::Movie::SetVariable(pObject, "mOutfitSave", &pDtor, 1i64);
      if ( (pDtor.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pDtor.pObjectInterface->vfptr->gap8[8])(
          pDtor.pObjectInterface,
          &pDtor,
          pDtor.mValue);
        pDtor.pObjectInterface = 0i64;
      }
      pDtor.Type = VT_Undefined;
    }
    `eh vector destructor iterator(ptr, 4ui64, 14, (void (__fastcall *)(void *))_);
  }
}

// File Line: 1178
// RVA: 0x603420
void __fastcall UFG::UIHKScreenWardrobe::SaveCurrentClothingAsOutfit(
        UFG::UIHKScreenWardrobe *this,
        UFG::StoreFront::OutfitNum eOutfitNum)
{
  UFG::GameStatTracker *v4; // r14
  UFG::PersistentData::ID *Stat; // r12
  UFG::GameStatTracker *v6; // rbx
  UFG::StoreFront::OutfitNum v7; // ebx
  UFG::GameStatTracker *v8; // rdi
  unsigned int v9; // esi
  _FILETIME SystemTime; // rax
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value value; // [rsp+20h] [rbp-59h] BYREF
  UFG::PersistentData::ID *v13; // [rsp+50h] [rbp-29h]
  UFG::PersistentData::ID *v14; // [rsp+58h] [rbp-21h]
  UFG::PersistentData::ID *v15; // [rsp+60h] [rbp-19h]
  UFG::PersistentData::ID *v16; // [rsp+68h] [rbp-11h]
  UFG::PersistentData::ID *v17; // [rsp+70h] [rbp-9h]
  UFG::PersistentData::ID *v18; // [rsp+78h] [rbp-1h]
  UFG::PersistentData::ID *v19; // [rsp+80h] [rbp+7h]
  __int64 v20; // [rsp+88h] [rbp+Fh]
  UFG::qSymbol name; // [rsp+E0h] [rbp+67h] BYREF
  UFG::qSymbol v22; // [rsp+E8h] [rbp+6Fh] BYREF
  UFG::qWiseSymbol result; // [rsp+F0h] [rbp+77h] BYREF
  UFG::PersistentData::ID *v24; // [rsp+F8h] [rbp+7Fh]

  v20 = -2i64;
  v4 = UFG::GameStatTracker::Instance();
  Stat = UFG::GameStatTracker::GetStat(v4, CurrentHeadgear);
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
  name.mUID = UFG::qSymbol::qSymbol(&result, eOutfitNum + 1)->mUID;
  if ( !(unsigned int)UFG::GameStatTracker::GetStat(v6, Outfits_Body, &name) )
  {
    v7 = Outfit_1;
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
    eOutfitNum = v7;
  }
LABEL_7:
  v22.mUID = -1;
  v22.mUID = UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&name, eOutfitNum + 1)->mUID;
  UFG::GameStatTracker::SetStat(v4, Outfits_Headgear, &v22, Stat->mValue.mUID);
  UFG::GameStatTracker::SetStat(v4, Outfits_Body, &v22, v24->mValue.mUID);
  UFG::GameStatTracker::SetStat(v4, Outfits_LowerBody, &v22, v17->mValue.mUID);
  UFG::GameStatTracker::SetStat(v4, Outfits_Footwear, &v22, v18->mValue.mUID);
  UFG::GameStatTracker::SetStat(v4, Outfits_Glasses, &v22, v15->mValue.mUID);
  UFG::GameStatTracker::SetStat(v4, Outfits_Neck, &v22, v19->mValue.mUID);
  UFG::GameStatTracker::SetStat(v4, Outfits_LeftWrist, &v22, v13->mValue.mUID);
  UFG::GameStatTracker::SetStat(v4, Outfits_RightWrist, &v22, v14->mValue.mUID);
  UFG::GameStatTracker::SetStat(v4, Outfits_Accessories, &v22, v16->mValue.mUID);
  SystemTime = UFG::qGetSystemTime();
  UFG::GameStatTracker::SetStat(v4, Outfits_CreationDateStamp, &v22, *(_QWORD *)&SystemTime);
  pObject = this->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    value.pObjectInterface = 0i64;
    value.Type = VT_Boolean;
    value.mValue.BValue = 0;
    Scaleform::GFx::Movie::SetVariable(pObject, "mOutfitSave", &value, 1i64);
    if ( (value.Type & 0x40) != 0 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        value.mValue);
  }
}

// File Line: 1238
// RVA: 0x5EB550
void __fastcall UFG::UIHKScreenWardrobe::HandleOptionHighlighted(UFG::UIHKScreenWardrobe *this)
{
  hkpNullContactMgrFactory *v2; // rax
  hkpCollidable *v3; // rdx
  hkpCollidable *v4; // r8
  hkpCollisionInput *v5; // r9
  UFG::StoreFront *ContactMgr; // rax
  UFG::qPropertySet *Item; // rdi
  hkpNullContactMgrFactory *v8; // rax
  hkpCollidable *v9; // rdx
  hkpCollidable *v10; // r8
  hkpCollisionInput *v11; // r9
  hkpNullContactMgrFactory *v12; // rax
  hkpCollidable *v13; // rdx
  hkpCollidable *v14; // r8
  hkpCollisionInput *v15; // r9

  if ( this->mNumItems )
  {
    this->mSelectedIndex = UFG::UIHKScreenWardrobe::GetSelectedIndex(this);
    v2 = (hkpNullContactMgrFactory *)UFG::StoreFrontTracker::Instance();
    if ( v2 )
    {
      ContactMgr = (UFG::StoreFront *)hkpNullContactMgrFactory::createContactMgr(v2, v3, v4, v5);
      if ( ContactMgr )
      {
        if ( this->mSelectedCategory == ItemCategory_CUSTOM_OUTFIT )
        {
          UFG::StoreFront::EquipCustomOutfit((UFG::StoreFront::OutfitNum)this->mSelectedIndex, 0, 1);
        }
        else
        {
          Item = UFG::StoreFront::GetItem(ContactMgr, this->mSelectedIndex);
          v8 = (hkpNullContactMgrFactory *)UFG::StoreFrontTracker::Instance();
          if ( v8 && hkpNullContactMgrFactory::createContactMgr(v8, v9, v10, v11) )
          {
            v12 = (hkpNullContactMgrFactory *)UFG::StoreFrontTracker::Instance();
            if ( v12 )
              hkpNullContactMgrFactory::createContactMgr(v12, v13, v14, v15);
            UFG::StoreFront::EquipItem(Item, 0, 1, 1, 0, 1);
          }
        }
      }
    }
    if ( this->mIsStore )
    {
      UFG::VendorDialogueUtils::sm_playBrowse = 1;
      UFG::VendorDialogueUtils::sm_idleTime = 0.0;
    }
  }
}

// File Line: 1290
// RVA: 0x5D74F0
void __fastcall UFG::UIHKScreenWardrobe::EquipItem(
        UFG::UIHKScreenWardrobe *this,
        UFG::qPropertySet *a_pItem,
        bool bSaveAsRestore,
        bool bRefreshPlayer,
        bool bRemoveAnyOutfit,
        bool bUpdateLastEquipItem,
        bool bRestoringPreviousClothes)
{
  hkpNullContactMgrFactory *v11; // rax
  hkpCollidable *v12; // rdx
  hkpCollidable *v13; // r8
  hkpCollisionInput *v14; // r9
  UFG::StoreFront *ContactMgr; // rbx
  int v16; // ebx
  UFG::GameStatTracker *v17; // rax
  UFG::StoreFrontTracker *v18; // rax
  UFG::qPropertySet *ClothingSetSlow; // rax
  char *v20; // rax
  UFG::qSymbol result; // [rsp+30h] [rbp-18h] BYREF

  v11 = (hkpNullContactMgrFactory *)UFG::StoreFrontTracker::Instance();
  if ( v11 )
  {
    ContactMgr = (UFG::StoreFront *)hkpNullContactMgrFactory::createContactMgr(v11, v12, v13, v14);
    if ( ContactMgr )
    {
      UFG::StoreFront::EquipItem(a_pItem, 1, bRefreshPlayer, 1, bUpdateLastEquipItem, 0);
      if ( !bRestoringPreviousClothes )
      {
        UFG::StoreFront::GetClothingBuffFromItem(ContactMgr, &result, a_pItem);
        if ( result.mUID != -1 )
        {
          v16 = UFG::StoreFront::LookupClothingBuff(&result);
          if ( v16 )
          {
            v17 = UFG::GameStatTracker::Instance();
            if ( (unsigned int)UFG::GameStatTracker::GetStat(v17, ClothingSetBuff) == v16 )
            {
              v18 = UFG::StoreFrontTracker::Instance();
              ClothingSetSlow = UFG::StoreFrontTracker::FindClothingSetSlow(v18, &result);
              if ( ClothingSetSlow )
              {
                v20 = PropertyUtils::Get<char const *>(
                        ClothingSetSlow,
                        (UFG::qArray<unsigned long,0> *)&UFG::ClothingSetSymbol_ActiveDesc,
                        DEPTH_RECURSE);
                if ( v20 )
                  UFG::UIScreenDialogBox::createOKDialog(this, &customCaption, v20, 0);
              }
            }
          }
        }
      }
      if ( bSaveAsRestore )
        UFG::UIHKScreenWardrobe::SaveCurrentClothingAsRestore(this);
    }
  }
}

// File Line: 1334
// RVA: 0x5EB630
void __fastcall UFG::UIHKScreenWardrobe::HandleOptionSelected(UFG::UIHKScreenWardrobe *this)
{
  int SelectedTrackerIndex; // ebp
  int SelectedIndex; // ebx
  hkpNullContactMgrFactory *v4; // rax
  hkpCollidable *v5; // rdx
  hkpCollidable *v6; // r8
  hkpCollisionInput *v7; // r9
  UFG::StoreFront *ContactMgr; // rax
  UFG::StoreFront *v9; // rsi
  UFG::qPropertySet *Item; // r14
  unsigned int *v11; // rax
  unsigned int *v12; // rcx
  unsigned int v13; // ebx
  UFG::GameStatTracker *v14; // rax
  UFG::qString v15; // [rsp+58h] [rbp-40h] BYREF
  int v16; // [rsp+A0h] [rbp+8h] BYREF

  if ( this->mNumItems )
  {
    SelectedTrackerIndex = UFG::UIHKScreenWardrobe::GetSelectedTrackerIndex(this);
    SelectedIndex = UFG::UIHKScreenWardrobe::GetSelectedIndex(this);
    v4 = (hkpNullContactMgrFactory *)UFG::StoreFrontTracker::Instance();
    if ( v4 )
    {
      ContactMgr = (UFG::StoreFront *)hkpNullContactMgrFactory::createContactMgr(v4, v5, v6, v7);
      v9 = ContactMgr;
      if ( ContactMgr )
      {
        Item = UFG::StoreFront::GetItem(ContactMgr, SelectedIndex);
        v16 = 0;
        v11 = UFG::qPropertySet::Get<unsigned long>(
                Item,
                (UFG::qArray<unsigned long,0> *)&UFG::StoreItemSymbol_FaceRequired,
                DEPTH_RECURSE);
        v12 = (unsigned int *)&v16;
        if ( v11 )
          v12 = v11;
        v13 = *v12;
        v14 = UFG::GameStatTracker::Instance();
        if ( v13 <= (unsigned int)UFG::GameStatTracker::GetFaceLevel(v14) )
        {
          if ( UFG::StoreFront::IsOwned(v9, SelectedTrackerIndex) )
          {
            UFG::UIHKScreenWardrobe::EquipItem(this, Item, 1, 1, 1, 1, 0);
            UFG::UIHKScreenWardrobe::ShowCategorySelect(this);
          }
          else if ( UFG::StoreFront::CanPurchase(v9, SelectedTrackerIndex)
                 || UFG::UIHKTweakables::WardrobeDebugFreeClothes )
          {
            UFG::UIScreenDialogBox::createTwoButtonDialog(
              this,
              &customCaption,
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
            UFG::qString::qString(&v15, "$COMMON_OK_UPPERCASE");
            UFG::UIScreenDialogBox::createOneButtonDialog(
              this,
              &customCaption,
              "$STORE_INSUFFICIENT_MONEY",
              v15.mData,
              UI_HASH_DIALOG_OK_30,
              0,
              "DialogBox");
            UFG::qString::~qString(&v15);
            UFG::VendorDialogueUtils::PlayStoreClerkDialogue(eStoreClerkDialogueContext_NoMoney, 1.0);
          }
        }
        else
        {
          UFG::qString::qString(&v15, "$COMMON_OK_UPPERCASE");
          UFG::UIScreenDialogBox::createOneButtonDialog(
            this,
            &customCaption,
            "$WARDROBE_FACE_TOO_LOW",
            v15.mData,
            UI_HASH_DIALOG_OK_30,
            0,
            "DialogBox");
          UFG::qString::~qString(&v15);
          this->mState = NUM_CALIBRATION_STATES|STATE_VOLUME;
        }
      }
    }
  }
}

// File Line: 1383
// RVA: 0x5EE150
bool __fastcall UFG::UIHKScreenWardrobe::IsCustomOutfitSlotInUse(
        UFG::UIHKScreenWardrobe *this,
        UFG::StoreFront::OutfitNum eOutFitNum)
{
  UFG::GameStatTracker *v3; // rax
  UFG::GameStatTracker *v4; // rdi
  UFG::qSymbol name; // [rsp+38h] [rbp+10h] BYREF
  UFG::qWiseSymbol result; // [rsp+40h] [rbp+18h] BYREF

  v3 = UFG::GameStatTracker::Instance();
  name.mUID = -1;
  v4 = v3;
  name.mUID = UFG::qSymbol::qSymbol(&result, eOutFitNum + 1)->mUID;
  return (unsigned int)UFG::GameStatTracker::GetStat(v4, Outfits_Body, &name) != 0;
}

// File Line: 1400
// RVA: 0x5F6140
void __fastcall UFG::UIHKScreenWardrobe::PopulateCustomOutfits(UFG::UIHKScreenWardrobe *this)
{
  Scaleform::GFx::Movie *pObject; // r14
  UFG::GameStatTracker *v3; // r12
  unsigned int v4; // edi
  __int64 v5; // r15
  UFG::GameStatTracker *v6; // rbx
  unsigned int v7; // eax
  UFG::UIGfxTranslator *m_translator; // rcx
  const char *v9; // rax
  unsigned __int64 Stat; // rax
  unsigned int v11; // eax
  UFG::UIGfxTranslator *v12; // rcx
  const char *v13; // rax
  Scaleform::GFx::Value value; // [rsp+30h] [rbp-D0h] BYREF
  Scaleform::GFx::Value ptr; // [rsp+60h] [rbp-A0h] BYREF
  __int64 v16; // [rsp+90h] [rbp-70h]
  UFG::qString v17; // [rsp+98h] [rbp-68h] BYREF
  UFG::UIHKWardrobeItemInfo info; // [rsp+C0h] [rbp-40h] BYREF
  UFG::qSymbol name; // [rsp+2D0h] [rbp+1D0h] BYREF
  UFG::qSymbol v20; // [rsp+2D8h] [rbp+1D8h] BYREF
  UFG::qWiseSymbol result; // [rsp+2E0h] [rbp+1E0h] BYREF
  UFG::qWiseSymbol v22; // [rsp+2E8h] [rbp+1E8h] BYREF

  v16 = -2i64;
  pObject = this->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    Scaleform::GFx::Movie::Invoke(pObject, "gWardrobeList.Clear", 0i64, 0i64, 0);
    value.pObjectInterface = 0i64;
    value.Type = VT_Boolean;
    value.mValue.BValue = 0;
    Scaleform::GFx::Movie::SetVariable(pObject, "mc_Money._visible", &value, 1i64);
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
        v7 = UFG::qStringHashUpper32("STORE_OUTFIT_NUM", -1);
        m_translator = UFG::UIScreenManager::s_instance->m_translator;
        if ( !m_translator || (v9 = (const char *)m_translator->vfptr[5].__vecDelDtor(m_translator, v7)) == 0i64 )
          v9 = "STORE_OUTFIT_NUM";
        UFG::qString::Format(&info.title, v9, v4);
        v20.mUID = -1;
        v20.mUID = UFG::qSymbol::qSymbol(&v22, v4)->mUID;
        Stat = UFG::GameStatTracker::GetStat(v3, Outfits_CreationDateStamp, &v20);
        UFG::UI::GetDateString(&v17, Stat, 1);
        v11 = UFG::qStringHashUpper32("STORE_OUTFIT_SAVED_DATE", -1);
        v12 = UFG::UIScreenManager::s_instance->m_translator;
        if ( !v12 || (v13 = (const char *)v12->vfptr[5].__vecDelDtor(v12, v11)) == 0i64 )
          v13 = "STORE_OUTFIT_SAVED_DATE";
        UFG::qString::Format(&info.description, v13, v17.mData);
        UFG::qString::~qString(&v17);
      }
      else
      {
        UFG::qString::Set(&info.title, "$STORE_EMPTY_SLOT");
        UFG::qString::Set(&info.description, "$STORE_EMPTY_DATE");
      }
      info.bodyLocation = this->mSelectedCategory;
      info.isOutfit = 1;
      ++this->mNumItems;
      info.trackerIndex = v4 - 1;
      UFG::UIHKScreenWardrobe::Flash_AddItem(this, &info);
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
    Scaleform::GFx::Movie::Invoke(pObject, "gWardrobeList.SetSelectedIndex", 0i64, &ptr, 1u);
    Scaleform::GFx::Movie::Invoke(pObject, "WardrobeList_Refresh", 0i64, 0i64, 0);
    `eh vector destructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    if ( (value.Type & 0x40) != 0 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        value.mValue);
  }
}

// File Line: 1460
// RVA: 0x5F7A30
void __fastcall UFG::UIHKScreenWardrobe::PopulateInventory(UFG::UIHKScreenWardrobe *this)
{
  hkpNullContactMgrFactory *v2; // rax
  hkpCollidable *v3; // rdx
  hkpCollidable *v4; // r8
  hkpCollisionInput *v5; // r9
  UFG::StoreFront *ContactMgr; // r13
  Scaleform::GFx::Movie *pObject; // rdi
  unsigned int v8; // r12d
  UFG::UIHKScreenWardrobe::eHelpBarState v9; // edx
  int mSelectedIndex; // esi
  unsigned int mUID; // ebx
  UFG::GameStatTracker *v12; // rax
  UFG::GameStat::IDStat v13; // edx
  unsigned int NumItems; // r15d
  UFG::qPropertySet *Item; // rax
  UFG::qPropertySet *v16; // rdi
  char *v17; // rax
  char *v18; // rax
  const char *v19; // rsi
  char *v20; // rax
  unsigned int *v21; // rax
  UFG::qWiseSymbol *p_result; // rcx
  unsigned int v23; // esi
  UFG::GameStatTracker *v24; // rax
  unsigned int FaceLevel; // eax
  unsigned int v26; // eax
  UFG::UIGfxTranslator *v27; // rcx
  const char *v28; // rax
  unsigned int v29; // eax
  UFG::UIGfxTranslator *m_translator; // rcx
  const char *v31; // rax
  UFG::StoreFrontTracker *v32; // rax
  UFG::qPropertySet *ClothingSetSlow; // rax
  UFG::qPropertySet *v34; // rsi
  char *v35; // rax
  char *v36; // rax
  char *v37; // rax
  UFG::StoreFrontTracker *v38; // rax
  UFG::qPropertySet *v39; // rax
  UFG::qPropertySet *v40; // rdi
  char *v41; // rax
  const char *v42; // r15
  char *v43; // rax
  const char *v44; // rsi
  char *v45; // rax
  const char *v46; // rdi
  bool v47; // bl
  unsigned int v48; // [rsp+30h] [rbp-D0h]
  Scaleform::GFx::Value value; // [rsp+38h] [rbp-C8h] BYREF
  Scaleform::GFx::Value ptr; // [rsp+68h] [rbp-98h] BYREF
  UFG::qWiseSymbol *v51; // [rsp+98h] [rbp-68h]
  Scaleform::GFx::Movie *v52; // [rsp+A0h] [rbp-60h]
  UFG::qSymbol v53; // [rsp+A8h] [rbp-58h] BYREF
  UFG::qSymbol v54; // [rsp+ACh] [rbp-54h] BYREF
  __int64 v55; // [rsp+B0h] [rbp-50h]
  UFG::UIHKWardrobeItemInfo info; // [rsp+C0h] [rbp-40h] BYREF
  UFG::qSymbol clothingSetName; // [rsp+2C8h] [rbp+1C8h] BYREF
  UFG::qWiseSymbol result; // [rsp+2D0h] [rbp+1D0h] BYREF
  int v59; // [rsp+2D8h] [rbp+1D8h]

  v55 = -2i64;
  v2 = (hkpNullContactMgrFactory *)UFG::StoreFrontTracker::Instance();
  if ( v2 )
  {
    ContactMgr = (UFG::StoreFront *)hkpNullContactMgrFactory::createContactMgr(v2, v3, v4, v5);
    if ( ContactMgr )
    {
      pObject = this->mRenderable->m_movie.pObject;
      v52 = pObject;
      if ( pObject )
      {
        v8 = 0;
        if ( this->mIsStore )
        {
          UFG::UIHKScreenWardrobe::UpdateMoney(this);
          UFG::UIHKScreenWardrobe::ShowHelpBar(this, HELP_SELECT_ITEM_RACE);
        }
        else
        {
          value.pObjectInterface = 0i64;
          value.Type = VT_Boolean;
          value.mValue.BValue = 0;
          Scaleform::GFx::Movie::SetVariable(pObject, "mc_Money._visible", &value, 1i64);
          v9 = HELP_SELECT_ITEM_EMPTY;
          if ( this->mSelectedCategory != ItemCategory_OUTFIT )
            v9 = HELP_SELECT_ITEM_STORAGE;
          UFG::UIHKScreenWardrobe::ShowHelpBar(this, v9);
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
        Scaleform::GFx::Movie::Invoke(pObject, "gWardrobeList.Clear", 0i64, 0i64, 0);
        UFG::StoreFront::SetCurrentCategory(ContactMgr, this->mSelectedCategory);
        mSelectedIndex = this->mSelectedIndex;
        v59 = mSelectedIndex;
        mUID = -1;
        UFG::qSymbol::qSymbol(&result, 0);
        v12 = UFG::GameStatTracker::Instance();
        switch ( this->mSelectedCategory )
        {
          case ItemCategory_BODY:
            v13 = CurrentBody;
            goto LABEL_22;
          case ItemCategory_LOWER_BODY:
            v13 = CurrentLowerBody;
            goto LABEL_22;
          case ItemCategory_FOOTWEAR:
            v13 = CurrentFootwear;
            goto LABEL_22;
          case ItemCategory_HEADGEAR:
            v13 = CurrentHeadgear;
            goto LABEL_22;
          case ItemCategory_ACCESSORIES:
            v13 = CurrentAccessories;
            goto LABEL_22;
          case ItemCategory_GLASSES:
            v13 = CurrentGlasses;
            goto LABEL_22;
          case ItemCategory_NECK:
            v13 = CurrentNeck;
            goto LABEL_22;
          case ItemCategory_LEFTWRIST:
            v13 = CurrentLeftWrist;
            goto LABEL_22;
          case ItemCategory_RIGHTWRIST:
            v13 = CurrentRightWrist;
            goto LABEL_22;
          case ItemCategory_OUTFIT:
            v13 = CurrentOutfit;
LABEL_22:
            mUID = UFG::GameStatTracker::GetStat(v12, v13)->mValue.mUID;
            break;
          default:
            break;
        }
        clothingSetName.mUID = -1;
        NumItems = UFG::StoreFront::GetNumItems(ContactMgr);
        v48 = NumItems;
        this->mNumItems = 0;
        if ( NumItems )
        {
          do
          {
            UFG::UIHKWardrobeItemInfo::UIHKWardrobeItemInfo(&info);
            Item = UFG::StoreFront::GetItem(ContactMgr, v8);
            v16 = Item;
            if ( Item )
            {
              if ( Item->mName.mUID == mUID )
              {
                if ( !this->mIsStore )
                  mSelectedIndex = v8;
                v59 = mSelectedIndex;
                info.is_equipped = 1;
              }
              v17 = PropertyUtils::Get<char const *>(
                      Item,
                      (UFG::qArray<unsigned long,0> *)&UFG::StoreItemSymbol_Title,
                      DEPTH_RECURSE);
              if ( v17 )
                UFG::qString::Set(&info.title, v17);
              v18 = PropertyUtils::Get<char const *>(
                      v16,
                      (UFG::qArray<unsigned long,0> *)&UFG::StoreItemSymbol_Brand,
                      DEPTH_RECURSE);
              v19 = v18;
              if ( v18 && (int)UFG::qStringLength(v18) > 0 )
                UFG::qString::Format(&info.brand, "clothingBrand_%s", v19);
              v20 = PropertyUtils::Get<char const *>(
                      v16,
                      (UFG::qArray<unsigned long,0> *)&UFG::StoreItemSymbol_Description,
                      DEPTH_RECURSE);
              if ( v20 )
                UFG::qString::Set(&info.description, v20);
              info.price = (int)UFG::StoreFrontTracker::GetItemPriceWithoutDiscount(v16);
              info.discountPrice = (int)UFG::StoreFrontTracker::GetItemPriceBasedOnClothes(v16);
              info.discountPercent = (int)UFG::StoreFrontTracker::GetDiscount();
              result.mUID = 0;
              v21 = UFG::qPropertySet::Get<unsigned long>(
                      v16,
                      (UFG::qArray<unsigned long,0> *)&UFG::StoreItemSymbol_FaceRequired,
                      DEPTH_RECURSE);
              p_result = &result;
              if ( v21 )
                p_result = (UFG::qWiseSymbol *)v21;
              v23 = p_result->mUID;
              v24 = UFG::GameStatTracker::Instance();
              FaceLevel = UFG::GameStatTracker::GetFaceLevel(v24);
              info.playerHasEnoughFace = v23 <= FaceLevel;
              if ( v23 > FaceLevel )
              {
                v29 = UFG::qStringHashUpper32("WARDROBE_FACE_LEVEL", -1);
                m_translator = UFG::UIScreenManager::s_instance->m_translator;
                if ( !m_translator
                  || (v31 = (const char *)m_translator->vfptr[5].__vecDelDtor(m_translator, v29)) == 0i64 )
                {
                  v31 = "WARDROBE_FACE_LEVEL";
                }
                UFG::qString::Format(&info.discountPercentStr, v31, v23);
              }
              else if ( info.discountPercent )
              {
                UFG::qString::qString((UFG::qString *)&value);
                UFG::qString::Format((UFG::qString *)&value, "%d", info.discountPercent);
                v26 = UFG::qStringHashUpper32("WARDROBE_DISCOUNT_PERCENT", -1);
                v27 = UFG::UIScreenManager::s_instance->m_translator;
                if ( !v27 || (v28 = (const char *)v27->vfptr[5].__vecDelDtor(v27, v26)) == 0i64 )
                  v28 = "WARDROBE_DISCOUNT_PERCENT";
                UFG::qString::Format(&info.discountPercentStr, v28, *(_QWORD *)&value.Type);
                UFG::qString::~qString((UFG::qString *)&value);
              }
              info.is_owned = UFG::StoreFront::IsOwned(ContactMgr, v8);
              info.bodyLocation = this->mSelectedCategory;
              clothingSetName.mUID = UFG::StoreFront::GetItemBuffFromItem(ContactMgr, &v53, v16)->mUID;
              v32 = UFG::StoreFrontTracker::Instance();
              ClothingSetSlow = UFG::StoreFrontTracker::FindClothingSetSlow(v32, &clothingSetName);
              v34 = ClothingSetSlow;
              if ( ClothingSetSlow )
              {
                v35 = PropertyUtils::Get<char const *>(
                        ClothingSetSlow,
                        (UFG::qArray<unsigned long,0> *)&UFG::ClothingSetSymbol_Title,
                        DEPTH_RECURSE);
                if ( v35 )
                  UFG::qString::Set(&info.itemBuffSetTitle, v35);
                v36 = PropertyUtils::Get<char const *>(
                        v34,
                        (UFG::qArray<unsigned long,0> *)&UFG::ClothingSetSymbol_Icon,
                        DEPTH_RECURSE);
                if ( v36 )
                  UFG::qString::Set(&info.itemBuffSetIcon, v36);
                v37 = PropertyUtils::Get<char const *>(
                        v34,
                        (UFG::qArray<unsigned long,0> *)&UFG::ClothingSetSymbol_Desc,
                        DEPTH_RECURSE);
                if ( v37 )
                  UFG::qString::Set(&info.itemBuffSetDesc, v37);
              }
              clothingSetName.mUID = UFG::StoreFront::GetClothingBuffFromItem(ContactMgr, &v54, v16)->mUID;
              v38 = UFG::StoreFrontTracker::Instance();
              v39 = UFG::StoreFrontTracker::FindClothingSetSlow(v38, &clothingSetName);
              v40 = v39;
              if ( v39 )
              {
                v41 = PropertyUtils::Get<char const *>(
                        v39,
                        (UFG::qArray<unsigned long,0> *)&UFG::ClothingSetSymbol_Title,
                        DEPTH_RECURSE);
                v42 = v41;
                if ( v41 )
                  UFG::qString::Set(&info.clothingBuffSetTitle, v41);
                v43 = PropertyUtils::Get<char const *>(
                        v40,
                        (UFG::qArray<unsigned long,0> *)&UFG::ClothingSetSymbol_Icon,
                        DEPTH_RECURSE);
                v44 = v43;
                if ( v43 )
                  UFG::qString::Set(&info.clothingBuffSetIcon, v43);
                v45 = PropertyUtils::Get<char const *>(
                        v40,
                        (UFG::qArray<unsigned long,0> *)&UFG::ClothingSetSymbol_Desc,
                        DEPTH_RECURSE);
                v46 = v45;
                if ( v45 )
                  UFG::qString::Set(&info.clothingBuffSetDesc, v45);
                v51 = &result;
                result.mUID = clothingSetName.mUID;
                info.bHasClothingSetShoes = UFG::StoreFront::IsClothingSetItemOwned(
                                              ContactMgr,
                                              ItemCategory_FOOTWEAR,
                                              &result);
                v51 = &result;
                result.mUID = clothingSetName.mUID;
                info.bHasClothingSetTorso = UFG::StoreFront::IsClothingSetItemOwned(
                                              ContactMgr,
                                              ItemCategory_BODY,
                                              &result);
                v51 = &result;
                result.mUID = clothingSetName.mUID;
                info.bHasClothingSetPants = UFG::StoreFront::IsClothingSetItemOwned(
                                              ContactMgr,
                                              ItemCategory_LOWER_BODY,
                                              &result);
                UFG::qPrintf("item is part of a clothing set %s, icon = %s, desc = %s\n", v42, v44, v46);
                NumItems = v48;
              }
              ++this->mNumItems;
              info.trackerIndex = v8;
              UFG::UIHKScreenWardrobe::Flash_AddItem(this, &info);
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
              mSelectedIndex = v59;
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
          while ( v8 < NumItems );
          pObject = v52;
        }
        `eh vector constructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
        v47 = this->mNumItems == 0;
        if ( (ptr.Type & 0x40) != 0 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
            ptr.pObjectInterface,
            &ptr,
            ptr.mValue);
          ptr.pObjectInterface = 0i64;
        }
        ptr.Type = VT_Boolean;
        ptr.mValue.BValue = v47;
        Scaleform::GFx::Movie::Invoke(pObject, "WardrobeList_SetIsEmpty", 0i64, &ptr, 1u);
        if ( (ptr.Type & 0x40) != 0 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
            ptr.pObjectInterface,
            &ptr,
            ptr.mValue);
          ptr.pObjectInterface = 0i64;
        }
        ptr.Type = VT_Number;
        ptr.mValue.NValue = (double)mSelectedIndex;
        Scaleform::GFx::Movie::Invoke(pObject, "gWardrobeList.SetSelectedIndex", 0i64, &ptr, 1u);
        Scaleform::GFx::Movie::Invoke(pObject, "WardrobeList_Refresh", 0i64, 0i64, 0);
        `eh vector destructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
      }
    }
  }
}

// File Line: 1688
// RVA: 0x5D9840
void __fastcall UFG::UIHKScreenWardrobe::Flash_AddItem(UFG::UIHKScreenWardrobe *this, UFG::UIHKWardrobeItemInfo *info)
{
  Scaleform::GFx::Value::ValueUnion v4; // xmm6_8
  char *mData; // rdi
  char *v6; // rdi
  char *v7; // rdi
  double price; // xmm6_8
  double discountPrice; // xmm6_8
  double discountPercent; // xmm6_8
  char *v11; // rdi
  bool is_owned; // di
  bool is_equipped; // di
  char *v14; // rdi
  char *v15; // rdi
  char *v16; // rdi
  double bodyLocation; // xmm6_8
  bool bHasClothingSetShoes; // di
  bool bHasClothingSetTorso; // di
  bool bHasClothingSetPants; // di
  bool playerHasEnoughFace; // di
  bool isOutfit; // di
  char *v23; // rdi
  char *v24; // rdi
  char *v25; // rbx
  Scaleform::GFx::Value ptr; // [rsp+30h] [rbp-B8h] BYREF
  char v27[8]; // [rsp+60h] [rbp-88h] BYREF
  char *v28; // [rsp+68h] [rbp-80h]
  __int64 v29; // [rsp+70h] [rbp-78h]
  int v30[4]; // [rsp+78h] [rbp-70h] BYREF
  __int64 v31; // [rsp+88h] [rbp-60h]
  int v32; // [rsp+90h] [rbp-58h]
  char *v33; // [rsp+98h] [rbp-50h]
  char v34[16]; // [rsp+A8h] [rbp-40h] BYREF
  __int64 v35; // [rsp+B8h] [rbp-30h]
  int v36; // [rsp+C0h] [rbp-28h]
  char *v37; // [rsp+C8h] [rbp-20h]
  char v38[16]; // [rsp+D8h] [rbp-10h] BYREF
  __int64 v39; // [rsp+E8h] [rbp+0h]
  int v40; // [rsp+F0h] [rbp+8h]
  double v41; // [rsp+F8h] [rbp+10h]
  char v42[16]; // [rsp+108h] [rbp+20h] BYREF
  __int64 v43; // [rsp+118h] [rbp+30h]
  int v44; // [rsp+120h] [rbp+38h]
  double v45; // [rsp+128h] [rbp+40h]
  char v46[16]; // [rsp+138h] [rbp+50h] BYREF
  __int64 v47; // [rsp+148h] [rbp+60h]
  int v48; // [rsp+150h] [rbp+68h]
  double v49; // [rsp+158h] [rbp+70h]
  char v50[16]; // [rsp+168h] [rbp+80h] BYREF
  __int64 v51; // [rsp+178h] [rbp+90h]
  int v52; // [rsp+180h] [rbp+98h]
  char *v53; // [rsp+188h] [rbp+A0h]
  char v54[16]; // [rsp+198h] [rbp+B0h] BYREF
  __int64 v55; // [rsp+1A8h] [rbp+C0h]
  int v56; // [rsp+1B0h] [rbp+C8h]
  __int64 v57; // [rsp+1B8h] [rbp+D0h]
  char v58[16]; // [rsp+1C8h] [rbp+E0h] BYREF
  __int64 v59; // [rsp+1D8h] [rbp+F0h]
  int v60; // [rsp+1E0h] [rbp+F8h]
  __int64 v61; // [rsp+1E8h] [rbp+100h]
  char v62[16]; // [rsp+1F8h] [rbp+110h] BYREF
  __int64 v63; // [rsp+208h] [rbp+120h]
  int v64; // [rsp+210h] [rbp+128h]
  __int64 v65; // [rsp+218h] [rbp+130h]
  char v66[16]; // [rsp+228h] [rbp+140h] BYREF
  __int64 v67; // [rsp+238h] [rbp+150h]
  int v68; // [rsp+240h] [rbp+158h]
  char *v69; // [rsp+248h] [rbp+160h]
  char v70[16]; // [rsp+258h] [rbp+170h] BYREF
  __int64 v71; // [rsp+268h] [rbp+180h]
  int v72; // [rsp+270h] [rbp+188h]
  char *v73; // [rsp+278h] [rbp+190h]
  char v74[16]; // [rsp+288h] [rbp+1A0h] BYREF
  __int64 v75; // [rsp+298h] [rbp+1B0h]
  int v76; // [rsp+2A0h] [rbp+1B8h]
  char *v77; // [rsp+2A8h] [rbp+1C0h]
  char v78[16]; // [rsp+2B8h] [rbp+1D0h] BYREF
  __int64 v79; // [rsp+2C8h] [rbp+1E0h]
  int v80; // [rsp+2D0h] [rbp+1E8h]
  double v81; // [rsp+2D8h] [rbp+1F0h]
  char v82[16]; // [rsp+2E8h] [rbp+200h] BYREF
  __int64 v83; // [rsp+2F8h] [rbp+210h]
  int v84; // [rsp+300h] [rbp+218h]
  __int64 v85; // [rsp+308h] [rbp+220h]
  char v86[16]; // [rsp+318h] [rbp+230h] BYREF
  __int64 v87; // [rsp+328h] [rbp+240h]
  int v88; // [rsp+330h] [rbp+248h]
  __int64 v89; // [rsp+338h] [rbp+250h]
  char v90[16]; // [rsp+348h] [rbp+260h] BYREF
  __int64 v91; // [rsp+358h] [rbp+270h]
  int v92; // [rsp+360h] [rbp+278h]
  __int64 v93; // [rsp+368h] [rbp+280h]
  char v94[16]; // [rsp+378h] [rbp+290h] BYREF
  __int64 v95; // [rsp+388h] [rbp+2A0h]
  int v96; // [rsp+390h] [rbp+2A8h]
  __int64 v97; // [rsp+398h] [rbp+2B0h]
  char v98[16]; // [rsp+3A8h] [rbp+2C0h] BYREF
  __int64 v99; // [rsp+3B8h] [rbp+2D0h]
  int v100; // [rsp+3C0h] [rbp+2D8h]
  __int64 v101; // [rsp+3C8h] [rbp+2E0h]
  char v102[16]; // [rsp+3D8h] [rbp+2F0h] BYREF
  __int64 v103; // [rsp+3E8h] [rbp+300h]
  int v104; // [rsp+3F0h] [rbp+308h]
  char *v105; // [rsp+3F8h] [rbp+310h]
  char v106[16]; // [rsp+408h] [rbp+320h] BYREF
  __int64 v107; // [rsp+418h] [rbp+330h]
  int v108; // [rsp+420h] [rbp+338h]
  char *v109; // [rsp+428h] [rbp+340h]
  char v110[16]; // [rsp+438h] [rbp+350h] BYREF
  __int64 v111; // [rsp+448h] [rbp+360h]
  int v112; // [rsp+450h] [rbp+368h]
  char *v113; // [rsp+458h] [rbp+370h]
  __int64 v114; // [rsp+468h] [rbp+380h]

  v114 = -2i64;
  `eh vector constructor iterator(&ptr, 0x30ui64, 23, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  v4.NValue = (double)info->trackerIndex;
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
  if ( (v30[0] & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v29 + 16i64))(v29, v27, v28);
    v29 = 0i64;
  }
  v30[0] = 6;
  v28 = mData;
  v6 = info->description.mData;
  if ( (v32 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, int *, char *))(*(_QWORD *)v31 + 16i64))(v31, v30, v33);
    v31 = 0i64;
  }
  v32 = 6;
  v33 = v6;
  v7 = info->brand.mData;
  if ( (v36 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v35 + 16i64))(v35, v34, v37);
    v35 = 0i64;
  }
  v36 = 6;
  v37 = v7;
  price = (double)(int)info->price;
  if ( (v40 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v39 + 16i64))(v39, v38, COERCE_DOUBLE(*(_QWORD *)&v41));
    v39 = 0i64;
  }
  v40 = 5;
  v41 = price;
  discountPrice = (double)(int)info->discountPrice;
  if ( (v44 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v43 + 16i64))(v43, v42, COERCE_DOUBLE(*(_QWORD *)&v45));
    v43 = 0i64;
  }
  v44 = 5;
  v45 = discountPrice;
  discountPercent = (double)(int)info->discountPercent;
  if ( (v48 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v47 + 16i64))(v47, v46, COERCE_DOUBLE(*(_QWORD *)&v49));
    v47 = 0i64;
  }
  v48 = 5;
  v49 = discountPercent;
  v11 = info->discountPercentStr.mData;
  if ( (v52 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v51 + 16i64))(v51, v50, v53);
    v51 = 0i64;
  }
  v52 = 6;
  v53 = v11;
  is_owned = info->is_owned;
  if ( (v56 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v55 + 16i64))(v55, v54, v57);
    v55 = 0i64;
  }
  v56 = 2;
  LOBYTE(v57) = is_owned;
  is_equipped = info->is_equipped;
  if ( (v60 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v59 + 16i64))(v59, v58, v61);
    v59 = 0i64;
  }
  v60 = 2;
  LOBYTE(v61) = is_equipped;
  if ( (v64 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v63 + 16i64))(v63, v62, v65);
    v63 = 0i64;
  }
  v64 = 5;
  v65 = 0i64;
  v14 = info->clothingBuffSetTitle.mData;
  if ( (v68 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v67 + 16i64))(v67, v66, v69);
    v67 = 0i64;
  }
  v68 = 6;
  v69 = v14;
  v15 = info->clothingBuffSetIcon.mData;
  if ( (v72 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v71 + 16i64))(v71, v70, v73);
    v71 = 0i64;
  }
  v72 = 6;
  v73 = v15;
  v16 = info->clothingBuffSetDesc.mData;
  if ( (v76 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v75 + 16i64))(v75, v74, v77);
    v75 = 0i64;
  }
  v76 = 6;
  v77 = v16;
  bodyLocation = (double)(int)info->bodyLocation;
  if ( (v80 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v79 + 16i64))(v79, v78, COERCE_DOUBLE(*(_QWORD *)&v81));
    v79 = 0i64;
  }
  v80 = 5;
  v81 = bodyLocation;
  bHasClothingSetShoes = info->bHasClothingSetShoes;
  if ( (v84 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v83 + 16i64))(v83, v82, v85);
    v83 = 0i64;
  }
  v84 = 2;
  LOBYTE(v85) = bHasClothingSetShoes;
  bHasClothingSetTorso = info->bHasClothingSetTorso;
  if ( (v88 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v87 + 16i64))(v87, v86, v89);
    v87 = 0i64;
  }
  v88 = 2;
  LOBYTE(v89) = bHasClothingSetTorso;
  bHasClothingSetPants = info->bHasClothingSetPants;
  if ( (v92 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v91 + 16i64))(v91, v90, v93);
    v91 = 0i64;
  }
  v92 = 2;
  LOBYTE(v93) = bHasClothingSetPants;
  playerHasEnoughFace = info->playerHasEnoughFace;
  if ( (v96 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v95 + 16i64))(v95, v94, v97);
    v95 = 0i64;
  }
  v96 = 2;
  LOBYTE(v97) = playerHasEnoughFace;
  isOutfit = info->isOutfit;
  if ( (v100 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v99 + 16i64))(v99, v98, v101);
    v99 = 0i64;
  }
  v100 = 2;
  LOBYTE(v101) = isOutfit;
  v23 = info->itemBuffSetTitle.mData;
  if ( (v104 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v103 + 16i64))(v103, v102, v105);
    v103 = 0i64;
  }
  v104 = 6;
  v105 = v23;
  v24 = info->itemBuffSetIcon.mData;
  if ( (v108 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v107 + 16i64))(v107, v106, v109);
    v107 = 0i64;
  }
  v108 = 6;
  v109 = v24;
  v25 = info->itemBuffSetDesc.mData;
  if ( (v112 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v111 + 16i64))(v111, v110, v113);
    v111 = 0i64;
  }
  v112 = 6;
  v113 = v25;
  Scaleform::GFx::Movie::Invoke(this->mRenderable->m_movie.pObject, "WardrobeList_AddItem", 0i64, &ptr, 0x17u);
  `eh vector destructor iterator(&ptr, 0x30ui64, 23, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 1739
// RVA: 0x609160
void __fastcall UFG::UIHKScreenWardrobe::SetStoreCamera(
        UFG::UIHKScreenWardrobe *this,
        UFG::StoreFront *store,
        UFG::UIHKScreenWardrobe::eCameraState a_eNewCameraState)
{
  UFG::SimObjectCharacter *v6; // r15
  UFG::qBaseNodeRB *CameraMarker; // rax
  UFG::TransformNodeComponent *v8; // rdi
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v10; // rax
  UFG::qBaseNodeRB *v11; // rax
  UFG::TransformNodeComponent *v12; // rdx
  UFG::SimObject *m_pSimObject; // rcx
  UFG::ScriptCameraComponent *ComponentOfType; // r14
  int v15; // ebx
  int v16; // ebx
  UFG::TransformNodeComponent *v17; // rbx
  float y; // xmm2_4
  float z; // xmm1_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  Creature *v22; // rbx
  UFG::qSymbolUC *v23; // rax
  int BoneID; // eax
  float x; // xmm8_4
  float v26; // xmm9_4
  float v27; // xmm10_4
  UFG::qSymbolUC *v28; // rax
  UFG::qSymbolUC *v29; // rax
  UFG::qSymbolUC *v30; // rax
  UFG::qSymbolUC *v31; // rax
  UFG::qSymbolUC *v32; // rax
  UFG::qSymbolUC *v33; // rax
  UFG::qSymbolUC *v34; // rax
  UFG::qSymbolUC *v35; // rax
  UFG::qSymbolUC *v36; // rax
  float v37; // xmm3_4
  __m128 y_low; // xmm4
  float v39; // xmm5_4
  __m128 v40; // xmm2
  float v41; // xmm10_4
  float v42; // xmm6_4
  float v43; // xmm7_4
  float v44; // xmm10_4
  float v45; // xmm7_4
  float v46; // xmm10_4
  float v47; // xmm3_4
  __m128 v48; // xmm2
  __m128 v49; // xmm5
  float v50; // xmm1_4
  float v51; // xmm8_4
  UFG::TransformNodeComponent *mPlayerMark; // rbx
  UFG::qVector3 eye; // [rsp+30h] [rbp-A8h] BYREF
  UFG::qVector3 look; // [rsp+40h] [rbp-98h] BYREF
  UFG::qSymbolUC v55; // [rsp+50h] [rbp-88h] BYREF
  UFG::qSymbolUC v56; // [rsp+54h] [rbp-84h] BYREF
  UFG::qMatrix44 v57[2]; // [rsp+58h] [rbp-80h] BYREF
  UFG::qSymbolUC result[2]; // [rsp+120h] [rbp+48h] BYREF
  UFG::qSymbolUC vars0; // [rsp+130h] [rbp+58h] BYREF

  if ( store )
  {
    *(_QWORD *)&v57[0].v1.z = -2i64;
    v6 = LocalPlayer;
    if ( LocalPlayer )
    {
      CameraMarker = UFG::StoreFront::GetCameraMarker(store);
      if ( CameraMarker )
      {
        if ( v6->m_pTransformNodeComponent )
        {
          v8 = *(UFG::TransformNodeComponent **)&CameraMarker[2].mUID;
          if ( v8 )
          {
            UFG::TransformNodeComponent::UpdateWorldTransform(*(UFG::TransformNodeComponent **)&CameraMarker[2].mUID);
            if ( this->mPlayerMark )
              goto LABEL_10;
            SimulationMemoryPool = UFG::GetSimulationMemoryPool();
            v10 = UFG::qMemoryPool::Allocate(
                    SimulationMemoryPool,
                    0x110ui64,
                    "UIHKScreenWardrobe TransformNodeComponent",
                    0i64,
                    1u);
            *(_QWORD *)&result[0].mUID = v10;
            if ( v10 )
              UFG::TransformNodeComponent::TransformNodeComponent((UFG::TransformNodeComponent *)v10, 0, 0i64, 0);
            this->mPlayerMark = (UFG::TransformNodeComponent *)v10;
            if ( v10 )
            {
LABEL_10:
              v11 = a_eNewCameraState == eCS_EXIT
                  ? UFG::StoreFront::GetPlayerExitMarker(store)
                  : UFG::StoreFront::GetPlayerMarker(store);
              if ( v11 )
              {
                v12 = *(UFG::TransformNodeComponent **)&v11[2].mUID;
                if ( v12 )
                {
                  UFG::TransformNodeComponent::SetParent(this->mPlayerMark, v12, eInheritXform_Full);
                  m_pSimObject = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
                  if ( m_pSimObject )
                  {
                    ComponentOfType = (UFG::ScriptCameraComponent *)UFG::SimObject::GetComponentOfType(
                                                                      m_pSimObject,
                                                                      UFG::ScriptCameraComponent::_TypeUID);
                    if ( ComponentOfType )
                    {
                      if ( a_eNewCameraState == eCS_INTIAL )
                      {
                        mPlayerMark = this->mPlayerMark;
                        UFG::TransformNodeComponent::UpdateWorldTransform(mPlayerMark);
                        UFG::SimObjectUtility::Teleport(v6, &mPlayerMark->mWorldTransform);
                        UFG::ScriptCameraComponent::SwitchToScriptCam(ComponentOfType, v8, 0, 0.0);
                        UFG::ScriptCameraComponent::SetFov(ComponentOfType, UFG::UIHKTweakables::WardrobeFOV);
                        ((void (__fastcall *)(UFG::ScriptCameraComponent *))ComponentOfType->vfptr[15].__vecDelDtor)(ComponentOfType);
                        goto LABEL_73;
                      }
                      v15 = a_eNewCameraState - 1;
                      if ( v15 )
                      {
                        v16 = v15 - 1;
                        if ( v16 )
                        {
                          if ( v16 == 1 )
                          {
                            v17 = this->mPlayerMark;
                            UFG::TransformNodeComponent::UpdateWorldTransform(v17);
                            UFG::SimObjectUtility::Teleport(v6, &v17->mWorldTransform);
                          }
                          goto LABEL_73;
                        }
                        UFG::TransformNodeComponent::UpdateWorldTransform(v8);
                        y = v8->mWorldTransform.v3.y;
                        z = v8->mWorldTransform.v3.z;
                        eye.x = v8->mWorldTransform.v3.x;
                        eye.y = y;
                        eye.z = z;
                        UFG::TransformNodeComponent::UpdateWorldTransform(v8);
                        UFG::TransformNodeComponent::UpdateWorldTransform(v8);
                        v20 = v8->mWorldTransform.v0.y + v8->mWorldTransform.v3.y;
                        v21 = v8->mWorldTransform.v0.z + v8->mWorldTransform.v3.z;
                        look.x = v8->mWorldTransform.v0.x + v8->mWorldTransform.v3.x;
                        look.y = v20;
                        look.z = v21;
                      }
                      else
                      {
                        v22 = *(Creature **)&UFG::SimObject::GetComponentOfType(
                                               v6,
                                               UFG::CharacterAnimationComponent::_TypeUID)[2].m_TypeUID;
                        if ( !v22 )
                        {
LABEL_73:
                          this->mUsingScriptCamera = 1;
                          return;
                        }
                        switch ( this->mSelectedCategory )
                        {
                          case ItemCategory_BODY:
                            v30 = UFG::qSymbolUC::create_from_string((UFG::qSymbolUC *)&v57[0].v1.y, "Bip01 Spine2");
                            if ( v22->mPose.mRigHandle.mData )
                              BoneID = Skeleton::GetBoneID(v22->mPose.mRigHandle.mUFGSkeleton, v30->mUID);
                            else
                              BoneID = -1;
                            x = UFG::UIHKTweakables::WardrobeOffsetBody.x;
                            v26 = UFG::UIHKTweakables::WardrobeOffsetBody.y;
                            v27 = UFG::UIHKTweakables::WardrobeOffsetBody.z;
                            goto LABEL_65;
                          case ItemCategory_LOWER_BODY:
                            v23 = UFG::qSymbolUC::create_from_string(result, "Bip01 L Calf");
                            if ( v22->mPose.mRigHandle.mData )
                              BoneID = Skeleton::GetBoneID(v22->mPose.mRigHandle.mUFGSkeleton, v23->mUID);
                            else
                              BoneID = -1;
                            x = UFG::UIHKTweakables::WardrobeOffsetLowerBody.x;
                            v26 = UFG::UIHKTweakables::WardrobeOffsetLowerBody.y;
                            v27 = UFG::UIHKTweakables::WardrobeOffsetLowerBody.z;
                            goto LABEL_65;
                          case ItemCategory_FOOTWEAR:
                            v28 = UFG::qSymbolUC::create_from_string(&vars0, "Sync01");
                            if ( v22->mPose.mRigHandle.mData )
                              BoneID = Skeleton::GetBoneID(v22->mPose.mRigHandle.mUFGSkeleton, v28->mUID);
                            else
                              BoneID = -1;
                            x = UFG::UIHKTweakables::WardrobeOffsetFootwear.x;
                            v26 = UFG::UIHKTweakables::WardrobeOffsetFootwear.y;
                            v27 = UFG::UIHKTweakables::WardrobeOffsetFootwear.z;
                            goto LABEL_65;
                          case ItemCategory_HEADGEAR:
                            v29 = UFG::qSymbolUC::create_from_string((UFG::qSymbolUC *)&v57[0].v0.w, "face_ingame_jaw");
                            if ( v22->mPose.mRigHandle.mData )
                              BoneID = Skeleton::GetBoneID(v22->mPose.mRigHandle.mUFGSkeleton, v29->mUID);
                            else
                              BoneID = -1;
                            x = UFG::UIHKTweakables::WardrobeOffsetHeadgear.x;
                            v26 = UFG::UIHKTweakables::WardrobeOffsetHeadgear.y;
                            v27 = UFG::UIHKTweakables::WardrobeOffsetHeadgear.z;
                            goto LABEL_65;
                          case ItemCategory_ACCESSORIES:
                            v31 = UFG::qSymbolUC::create_from_string((UFG::qSymbolUC *)&v57[0].v0.z, "Bip01 Head");
                            if ( v22->mPose.mRigHandle.mData )
                              BoneID = Skeleton::GetBoneID(v22->mPose.mRigHandle.mUFGSkeleton, v31->mUID);
                            else
                              BoneID = -1;
                            x = UFG::UIHKTweakables::WardrobeOffsetAccessories.x;
                            v26 = UFG::UIHKTweakables::WardrobeOffsetAccessories.y;
                            v27 = UFG::UIHKTweakables::WardrobeOffsetAccessories.z;
                            goto LABEL_65;
                          case ItemCategory_GLASSES:
                            v33 = UFG::qSymbolUC::create_from_string((UFG::qSymbolUC *)&v57[0].v0.y, "face_ingame_jaw");
                            if ( v22->mPose.mRigHandle.mData )
                              BoneID = Skeleton::GetBoneID(v22->mPose.mRigHandle.mUFGSkeleton, v33->mUID);
                            else
                              BoneID = -1;
                            x = UFG::UIHKTweakables::WardrobeOffsetGlasses.x;
                            v26 = UFG::UIHKTweakables::WardrobeOffsetGlasses.y;
                            v27 = UFG::UIHKTweakables::WardrobeOffsetGlasses.z;
                            goto LABEL_65;
                          case ItemCategory_NECK:
                            v34 = UFG::qSymbolUC::create_from_string(&v55, "Bip01 Neck");
                            if ( v22->mPose.mRigHandle.mData )
                              BoneID = Skeleton::GetBoneID(v22->mPose.mRigHandle.mUFGSkeleton, v34->mUID);
                            else
                              BoneID = -1;
                            x = UFG::UIHKTweakables::WardrobeOffsetNeck.x;
                            v26 = UFG::UIHKTweakables::WardrobeOffsetNeck.y;
                            v27 = UFG::UIHKTweakables::WardrobeOffsetNeck.z;
                            goto LABEL_65;
                          case ItemCategory_LEFTWRIST:
                            v35 = UFG::qSymbolUC::create_from_string((UFG::qSymbolUC *)&v57[0].v1, "Bip01 L Prop");
                            if ( v22->mPose.mRigHandle.mData )
                              BoneID = Skeleton::GetBoneID(v22->mPose.mRigHandle.mUFGSkeleton, v35->mUID);
                            else
                              BoneID = -1;
                            x = UFG::UIHKTweakables::WardrobeOffsetLeftWrist.x;
                            v26 = UFG::UIHKTweakables::WardrobeOffsetLeftWrist.y;
                            v27 = UFG::UIHKTweakables::WardrobeOffsetLeftWrist.z;
                            goto LABEL_65;
                          case ItemCategory_RIGHTWRIST:
                            v36 = UFG::qSymbolUC::create_from_string(&v56, "Bip01 R Prop");
                            if ( v22->mPose.mRigHandle.mData )
                              BoneID = Skeleton::GetBoneID(v22->mPose.mRigHandle.mUFGSkeleton, v36->mUID);
                            else
                              BoneID = -1;
                            x = UFG::UIHKTweakables::WardrobeOffsetRightWrist.x;
                            v26 = UFG::UIHKTweakables::WardrobeOffsetRightWrist.y;
                            v27 = UFG::UIHKTweakables::WardrobeOffsetRightWrist.z;
                            goto LABEL_65;
                          case ItemCategory_OUTFIT:
                            v32 = UFG::qSymbolUC::create_from_string((UFG::qSymbolUC *)v57, "Bip01 Head");
                            if ( v22->mPose.mRigHandle.mData )
                              BoneID = Skeleton::GetBoneID(v22->mPose.mRigHandle.mUFGSkeleton, v32->mUID);
                            else
                              BoneID = -1;
                            x = UFG::UIHKTweakables::WardrobeOffsetOutfit.x;
                            v26 = UFG::UIHKTweakables::WardrobeOffsetOutfit.y;
                            v27 = UFG::UIHKTweakables::WardrobeOffsetOutfit.z;
LABEL_65:
                            if ( BoneID == -1 )
                              return;
                            Creature::GetTransform(v22, BoneID, v57);
                            UFG::TransformNodeComponent::UpdateWorldTransform(v8);
                            v37 = v57[0].v3.x - v8->mWorldTransform.v3.x;
                            y_low = (__m128)LODWORD(v57[0].v3.y);
                            y_low.m128_f32[0] = v57[0].v3.y - v8->mWorldTransform.v3.y;
                            v39 = v57[0].v3.z - v8->mWorldTransform.v3.z;
                            v40 = y_low;
                            v40.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v37 * v37))
                                            + (float)(v39 * v39);
                            v41 = v27 / _mm_sqrt_ps(v40).m128_f32[0];
                            v42 = v41 * v37;
                            v43 = v41 * y_low.m128_f32[0];
                            v44 = v41 * v39;
                            UFG::TransformNodeComponent::UpdateWorldTransform(v8);
                            v45 = v43 + v8->mWorldTransform.v3.y;
                            v46 = v44 + v8->mWorldTransform.v3.z;
                            eye.x = v42 + v8->mWorldTransform.v3.x;
                            eye.y = v45;
                            v47 = v57[0].v3.x - eye.x;
                            v48 = (__m128)LODWORD(v57[0].v3.y);
                            v48.m128_f32[0] = v57[0].v3.y - v45;
                            v49 = v48;
                            v49.m128_f32[0] = (float)((float)(v48.m128_f32[0] * v48.m128_f32[0]) + (float)(v47 * v47))
                                            + (float)((float)(v57[0].v3.z - v46) * (float)(v57[0].v3.z - v46));
                            if ( v49.m128_f32[0] == 0.0 )
                              v50 = 0.0;
                            else
                              v50 = 1.0 / _mm_sqrt_ps(v49).m128_f32[0];
                            look.x = (float)((float)(x * (float)(v48.m128_f32[0] * v50)) + (float)(v26 * 0.0))
                                   + v57[0].v3.x;
                            look.y = (float)((float)(x * COERCE_FLOAT(COERCE_UNSIGNED_INT(v47 * v50) ^ _xmm[0]))
                                           + (float)(v26 * 0.0))
                                   + v57[0].v3.y;
                            v51 = (float)((float)(x * 0.0) + v26) + v57[0].v3.z;
                            look.z = v51;
                            eye.z = v51;
                            if ( this->mSelectedCategory == ItemCategory_FOOTWEAR )
                              eye.z = v51 + UFG::UIHKTweakables::WardrobeFootEyeHeight;
                            break;
                          default:
                            return;
                        }
                      }
                      UFG::ScriptCameraComponent::SetDesiredEyeLook(
                        ComponentOfType,
                        &eye,
                        &look,
                        UFG::UIHKTweakables::WardrobeCameraDuration,
                        0);
                      goto LABEL_73;
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
  int i; // ebx
  char *CategoryHeading; // rax
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value::ValueUnion v7; // xmm6_8
  Scaleform::GFx::Value value; // [rsp+30h] [rbp-21h] BYREF
  Scaleform::GFx::Value ptr; // [rsp+60h] [rbp+Fh] BYREF

  if ( !pStore )
    return;
  for ( i = 0; i < 14; ++i )
  {
    if ( ((i - 4) & 0xFFFFFFF6) != 0 || i == 5 )
    {
      if ( this->mIsStore )
      {
        if ( (int)UFG::StoreFront::GetItemCount(pStore, (UFG::StoreFront::ItemCategory)i) <= 0 )
          continue;
LABEL_10:
        CategoryHeading = UFG::StoreFront::GetCategoryHeading(pStore, i);
        UFG::UIHKScreenWardrobe::Flash_AddCategory(this, CategoryHeading);
        ++this->mNumCategories;
        continue;
      }
      if ( !UFG::StoreFront::IsOwnedClothingCategoryEmpty(pStore, (UFG::StoreFront::ItemCategory)i) || i == 11 )
        goto LABEL_10;
    }
  }
  pObject = this->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    `eh vector constructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    v7.NValue = (double)(int)this->mNumCategories;
    if ( (ptr.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
        ptr.pObjectInterface,
        &ptr,
        ptr.mValue);
      ptr.pObjectInterface = 0i64;
    }
    ptr.Type = VT_Number;
    ptr.mValue = v7;
    Scaleform::GFx::Movie::Invoke(pObject, "CategoryMenu_SetNumCategories", 0i64, &ptr, 1u);
    if ( this->mIsStore )
    {
      UFG::UIHKScreenWardrobe::UpdateMoney(this);
    }
    else
    {
      value.pObjectInterface = 0i64;
      value.Type = VT_Boolean;
      value.mValue.BValue = 0;
      Scaleform::GFx::Movie::SetVariable(pObject, "mc_Money._visible", &value, 1i64);
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
    `eh vector destructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 2005
// RVA: 0x5D9110
void __fastcall UFG::UIHKScreenWardrobe::Flash_AddCategory(UFG::UIHKScreenWardrobe *this, const char *caption)
{
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h] BYREF

  pObject = this->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    `eh vector constructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( (pargs.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        pargs.mValue);
      pargs.pObjectInterface = 0i64;
    }
    pargs.Type = VT_String;
    pargs.mValue.pString = caption;
    Scaleform::GFx::Movie::Invoke(pObject, "CategoryMenu_AddItem", 0i64, &pargs, 1u);
    `eh vector destructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 2017
// RVA: 0x5E8BF0
__int64 __fastcall UFG::UIHKScreenWardrobe::GetSelectedCategory(UFG::UIHKScreenWardrobe *this)
{
  hkpNullContactMgrFactory *v2; // rax
  hkpCollidable *v3; // rdx
  hkpCollidable *v4; // r8
  hkpCollisionInput *v5; // r9
  UFG::StoreFront *ContactMgr; // rsi
  const char *SelectedCategoryCaption; // rdi
  unsigned int v8; // ebx
  char *CategoryHeading; // rax

  v2 = (hkpNullContactMgrFactory *)UFG::StoreFrontTracker::Instance();
  if ( !v2 )
    return 0i64;
  ContactMgr = (UFG::StoreFront *)hkpNullContactMgrFactory::createContactMgr(v2, v3, v4, v5);
  if ( !ContactMgr )
    return 0i64;
  SelectedCategoryCaption = UFG::UIHKScreenWardrobe::GetSelectedCategoryCaption(this);
  if ( !SelectedCategoryCaption )
    return 0i64;
  v8 = 0;
  while ( 1 )
  {
    if ( ((v8 - 4) & 0xFFFFFFF6) != 0 || v8 == 5 )
    {
      CategoryHeading = UFG::StoreFront::GetCategoryHeading(ContactMgr, v8);
      if ( !(unsigned int)UFG::qStringCompare(SelectedCategoryCaption, CategoryHeading, -1) )
        break;
    }
    if ( (int)++v8 >= 14 )
      return 0i64;
  }
  return v8;
}

// File Line: 2053
// RVA: 0x5E8CA0
const char *__fastcall UFG::UIHKScreenWardrobe::GetSelectedCategoryCaption(UFG::UIHKScreenWardrobe *this)
{
  Scaleform::GFx::Movie *pObject; // rcx
  Scaleform::GFx::Value::ValueUnion mValue; // rbx
  Scaleform::GFx::Value pval; // [rsp+28h] [rbp-40h] BYREF

  pObject = this->mRenderable->m_movie.pObject;
  if ( !pObject )
    return 0i64;
  pval.pObjectInterface = 0i64;
  pval.Type = VT_Undefined;
  Scaleform::GFx::Movie::GetVariable(pObject, &pval, "gCategoryMenu_SelectedValue");
  if ( (pval.Type & 0x40) != 0 )
    mValue = *(Scaleform::GFx::Value::ValueUnion *)pval.mValue.pString;
  else
    mValue = pval.mValue;
  if ( (pval.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pval.pObjectInterface->vfptr->gap8[8])(
      pval.pObjectInterface,
      &pval,
      pval.mValue);
    pval.pObjectInterface = 0i64;
  }
  return mValue.pString;
}

// File Line: 2065
// RVA: 0x61B610
void __fastcall UFG::UIHKScreenWardrobe::UpdateMoney(UFG::UIHKScreenWardrobe *this)
{
  Scaleform::GFx::Movie *pObject; // rsi
  UFG::GameStatTracker *v2; // rax
  int Stat; // ebx
  UFG::GameStatTracker *v4; // rax
  int FaceLevel; // r14d
  Scaleform::GFx::Value::ValueUnion v6; // rdi
  Scaleform::GFx::Value v7; // [rsp+30h] [rbp-79h] BYREF
  int v8[4]; // [rsp+60h] [rbp-49h] BYREF
  __int64 v9; // [rsp+70h] [rbp-39h]
  int v10; // [rsp+78h] [rbp-31h]
  double v11; // [rsp+80h] [rbp-29h]
  int v12[4]; // [rsp+90h] [rbp-19h] BYREF
  __int64 v13; // [rsp+A0h] [rbp-9h]
  __int64 v14; // [rsp+A8h] [rbp-1h]
  UFG::qString string; // [rsp+B0h] [rbp+7h] BYREF
  Scaleform::GFx::Value::ValueUnion v16; // [rsp+E0h] [rbp+37h]

  *(_QWORD *)&string.mMagic = -2i64;
  pObject = this->mRenderable->m_movie.pObject;
  v2 = UFG::GameStatTracker::Instance();
  Stat = UFG::GameStatTracker::GetStat(v2, Money);
  v4 = UFG::GameStatTracker::Instance();
  FaceLevel = UFG::GameStatTracker::GetFaceLevel(v4);
  UFG::qString::qString((UFG::qString *)&string.mData);
  UFG::UI::FormatMoneyStr(Stat, (UFG::qString *)&string.mData);
  `eh vector constructor iterator(&v7, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  v6 = v16;
  if ( (v7.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&v7.pObjectInterface->vfptr->gap8[8])(
      v7.pObjectInterface,
      &v7,
      v7.mValue);
    v7.pObjectInterface = 0i64;
  }
  v7.Type = VT_String;
  v7.mValue = v6;
  if ( (v10 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, int *, double))(*(_QWORD *)v9 + 16i64))(v9, v8, COERCE_DOUBLE(*(_QWORD *)&v11));
    v9 = 0i64;
  }
  v10 = 5;
  v11 = (double)Stat;
  if ( (v14 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, int *, UFG::qNode<UFG::qString,UFG::qString> *))(*(_QWORD *)v13 + 16i64))(
      v13,
      v12,
      string.mPrev);
    v13 = 0i64;
  }
  LODWORD(v14) = 5;
  *(double *)&string.mPrev = (double)FaceLevel;
  Scaleform::GFx::Movie::Invoke(pObject, "SetMoney", 0i64, &v7, 3u);
  `eh vector destructor iterator(&v7, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  UFG::qString::~qString((UFG::qString *)&string.mData);
}

// File Line: 2083
// RVA: 0x60D300
void __fastcall UFG::UIHKScreenWardrobe::ShowCategorySelect(UFG::UIHKScreenWardrobe *this)
{
  Scaleform::GFx::Movie *pObject; // rcx
  hkpNullContactMgrFactory *v3; // rax
  hkpCollidable *v4; // rdx
  hkpCollidable *v5; // r8
  hkpCollisionInput *v6; // r9
  UFG::StoreFront *ContactMgr; // rax
  UFG::qString *StoreDesc; // rax
  UFG::qString result; // [rsp+38h] [rbp-30h] BYREF

  this->mState = STATE_UISCALE;
  pObject = this->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    Scaleform::GFx::Movie::Invoke(pObject, "ShowCategorySelect", 0i64, 0i64, 0);
    UFG::UIHKScreenWardrobe::ShowHelpBar(this, HELP_SELECT_ITEM_STORE);
    v3 = (hkpNullContactMgrFactory *)UFG::StoreFrontTracker::Instance();
    if ( v3 )
    {
      ContactMgr = (UFG::StoreFront *)hkpNullContactMgrFactory::createContactMgr(v3, v4, v5, v6);
      if ( ContactMgr )
      {
        if ( this->mIsStore )
          StoreDesc = UFG::StoreFront::GetStoreDesc(ContactMgr, &result);
        else
          UFG::qString::qString(&result, "$WARDROBE_SUBHEADING");
        UFG::UIHKScreenWardrobe::SetStoreDesc(this, StoreDesc);
      }
    }
  }
}

// File Line: 2125
// RVA: 0x5D4940
void __fastcall UFG::UIHKScreenWardrobe::CategorySelect_HandleOptionSelected(UFG::UIHKScreenWardrobe *this)
{
  const char *SelectedCategoryCaption; // rax
  Scaleform::GFx::Movie *pObject; // rcx
  hkpNullContactMgrFactory *v4; // rax
  hkpCollidable *v5; // rdx
  hkpCollidable *v6; // r8
  hkpCollisionInput *v7; // r9
  UFG::StoreFront *ContactMgr; // rax
  char *CategoryHeading; // rax
  UFG::qString *v10; // rax
  UFG::qString v11; // [rsp+38h] [rbp-30h] BYREF

  this->mSelectedCategory = UFG::UIHKScreenWardrobe::GetSelectedCategory(this);
  SelectedCategoryCaption = UFG::UIHKScreenWardrobe::GetSelectedCategoryCaption(this);
  UFG::qString::Set(&this->mSelectedCategoryCaption, SelectedCategoryCaption);
  this->mState = STATE_VOLUME;
  pObject = this->mRenderable->m_movie.pObject;
  if ( pObject )
    Scaleform::GFx::Movie::Invoke(pObject, "HideCategorySelect", 0i64, 0i64, 0);
  v4 = (hkpNullContactMgrFactory *)UFG::StoreFrontTracker::Instance();
  if ( v4 )
  {
    ContactMgr = (UFG::StoreFront *)hkpNullContactMgrFactory::createContactMgr(v4, v5, v6, v7);
    if ( ContactMgr )
    {
      CategoryHeading = UFG::StoreFront::GetCategoryHeading(ContactMgr, this->mSelectedCategory);
      UFG::qString::qString(&v11, CategoryHeading);
      UFG::UIHKScreenWardrobe::SetStoreDesc(this, v10);
    }
  }
  if ( this->mSelectedCategory == ItemCategory_CUSTOM_OUTFIT )
  {
    this->mState = NUM_CALIBRATION_STATES;
    UFG::UIHKScreenWardrobe::PopulateCustomOutfits(this);
    UFG::UIHKScreenWardrobe::ShowHelpBar(this, HELP_SELECT_ITEM_EMPTY|HELP_SELECT_ITEM_STORE);
  }
  else
  {
    UFG::UIHKScreenWardrobe::PopulateInventory(this);
  }
}

// File Line: 2152
// RVA: 0x5D5E30
void __fastcall UFG::UIHKScreenWardrobe::CustomOutfit_HandleOptionSelected(UFG::UIHKScreenWardrobe *this)
{
  int SelectedIndex; // eax
  UFG::GameStatTracker *v3; // rax
  UFG::eClothingBuffEnum Stat; // eax
  UFG::StoreFrontTracker *v5; // rax
  UFG::qPropertySet *ClothingSetSlow; // rax
  char *v7; // rax
  UFG::qSymbol result; // [rsp+30h] [rbp+8h] BYREF

  if ( this->mNumItems )
  {
    SelectedIndex = UFG::UIHKScreenWardrobe::GetSelectedIndex(this);
    this->mSelectedIndex = SelectedIndex;
    UFG::StoreFront::EquipCustomOutfit((UFG::StoreFront::OutfitNum)SelectedIndex, 1, 1);
    UFG::StoreFront::CheckAchievement();
    UFG::UIHKScreenWardrobe::SaveCurrentClothingAsRestore(this);
    v3 = UFG::GameStatTracker::Instance();
    Stat = (unsigned int)UFG::GameStatTracker::GetStat(v3, ClothingSetBuff);
    if ( Stat )
    {
      UFG::StoreFront::LookupClothingBuffSymbol(&result, Stat);
      v5 = UFG::StoreFrontTracker::Instance();
      ClothingSetSlow = UFG::StoreFrontTracker::FindClothingSetSlow(v5, &result);
      if ( ClothingSetSlow )
      {
        v7 = PropertyUtils::Get<char const *>(
               ClothingSetSlow,
               (UFG::qArray<unsigned long,0> *)&UFG::ClothingSetSymbol_ActiveDesc,
               DEPTH_RECURSE);
        if ( v7 )
          UFG::UIScreenDialogBox::createOKDialog(this, &customCaption, v7, 0);
      }
    }
  }
}

// File Line: 2176
// RVA: 0x604AC0
void __fastcall UFG::UIHKScreenWardrobe::SendTelemetryData(UFG::UIHKScreenWardrobe *this)
{
  UFG::GameStatTracker *v1; // rsi
  bool IsWeiWearingAnPrefinedOutfit; // bl
  UFG::OSuiteDBLogger *v3; // rdi
  UFG::PersistentData::ID *Stat; // rax
  const char *v5; // r9
  int mUID; // ebx
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
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *mPrev; // rcx
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *mNext; // rax
  __int64 v19; // rcx
  UFG::NameValueColumnType *v20; // rax
  __int64 v21; // [rsp+18h] [rbp-49h] BYREF
  UFG::NameValueColumnType *v22; // [rsp+20h] [rbp-41h]
  char dest[128]; // [rsp+28h] [rbp-39h] BYREF
  __int64 v24; // [rsp+A8h] [rbp+47h]

  v24 = -2i64;
  v1 = UFG::GameStatTracker::Instance();
  v22 = (UFG::NameValueColumnType *)&v21;
  IsWeiWearingAnPrefinedOutfit = UFG::StoreFront::IsWeiWearingAnPrefinedOutfit();
  v3 = UFG::OSuiteDBLogger::Instance();
  if ( UFG::OSuiteDBLogger::CreateMetric(v3, "ChangeClothes") )
  {
    UFG::qSPrintf(dest, 128, "i32_%s", "IsPredefinedOutfit");
    OSuite::ZMetric::SetProperty(v3->m_pMetric, dest, IsWeiWearingAnPrefinedOutfit);
    if ( IsWeiWearingAnPrefinedOutfit )
    {
      Stat = UFG::GameStatTracker::GetStat(v1, CurrentOutfit);
      v5 = "PredefinedOutfit";
    }
    else
    {
      mUID = UFG::GameStatTracker::GetStat(v1, CurrentHeadgear)->mValue.mUID;
      UFG::qSPrintf(dest, 128, "i32_%s", "Headgear");
      OSuite::ZMetric::SetProperty(v3->m_pMetric, dest, mUID);
      v7 = UFG::GameStatTracker::GetStat(v1, CurrentHead)->mValue.mUID;
      UFG::qSPrintf(dest, 128, "i32_%s", "Head");
      OSuite::ZMetric::SetProperty(v3->m_pMetric, dest, v7);
      v8 = UFG::GameStatTracker::GetStat(v1, CurrentGlasses)->mValue.mUID;
      UFG::qSPrintf(dest, 128, "i32_%s", "Glasses");
      OSuite::ZMetric::SetProperty(v3->m_pMetric, dest, v8);
      v9 = UFG::GameStatTracker::GetStat(v1, CurrentNeck)->mValue.mUID;
      UFG::qSPrintf(dest, 128, "i32_%s", "Neck");
      OSuite::ZMetric::SetProperty(v3->m_pMetric, dest, v9);
      v10 = UFG::GameStatTracker::GetStat(v1, CurrentBody)->mValue.mUID;
      UFG::qSPrintf(dest, 128, "i32_%s", "Body");
      OSuite::ZMetric::SetProperty(v3->m_pMetric, dest, v10);
      v11 = UFG::GameStatTracker::GetStat(v1, CurrentLeftWrist)->mValue.mUID;
      UFG::qSPrintf(dest, 128, "i32_%s", "LeftWrist");
      OSuite::ZMetric::SetProperty(v3->m_pMetric, dest, v11);
      v12 = UFG::GameStatTracker::GetStat(v1, CurrentRightWrist)->mValue.mUID;
      UFG::qSPrintf(dest, 128, "i32_%s", "RightWrist");
      OSuite::ZMetric::SetProperty(v3->m_pMetric, dest, v12);
      v13 = UFG::GameStatTracker::GetStat(v1, CurrentLowerBody)->mValue.mUID;
      UFG::qSPrintf(dest, 128, "i32_%s", "LowerBody");
      OSuite::ZMetric::SetProperty(v3->m_pMetric, dest, v13);
      v14 = UFG::GameStatTracker::GetStat(v1, CurrentFootwear)->mValue.mUID;
      UFG::qSPrintf(dest, 128, "i32_%s", "Footwear");
      OSuite::ZMetric::SetProperty(v3->m_pMetric, dest, v14);
      Stat = UFG::GameStatTracker::GetStat(v1, CurrentAccessories);
      v5 = "Accessories";
    }
    v15 = Stat->mValue.mUID;
    UFG::qSPrintf(dest, 128, "i32_%s", v5);
    OSuite::ZMetric::SetProperty(v3->m_pMetric, dest, v15);
    UFG::OSuiteDBLogger::SubmitMetric(v3, 1);
  }
  for ( i = v22; v22 != (UFG::NameValueColumnType *)&v21; i = v22 )
  {
    mPrev = i->mPrev;
    mNext = i->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    i->mPrev = i;
    i->mNext = i;
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
void __fastcall UFG::UIHKScreenWardrobe::NetworkSignedIn(
        UFG::UIHKScreenWardrobe *this,
        hkgpIndexedMeshDefinitions::Edge *a2)
{
  __int64 v3; // rax
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h] BYREF

  v3 = *(_QWORD *)&this[-1].mInitClothing[1].mUID;
  if ( v3 && *(_QWORD *)(v3 + 320) && Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(0i64, a2) )
  {
    this->m_screenName[26] = 1;
    BYTE1(this->mDimType) = 0;
    UFG::UIHKScreenWardrobe::ShowTickerPopup((UFG::UIHKScreenWardrobe *)((char *)this - 152), 0);
    UFG::UIHKScreenWardrobe::ShowHelpBar(
      (UFG::UIHKScreenWardrobe *)((char *)this - 152),
      *(UFG::UIHKScreenWardrobe::eHelpBarState *)&this->m_screenName[16]);
    pargs.pObjectInterface = 0i64;
    pargs.Type = VT_String;
    pargs.mValue.pString = &customCaption;
    Scaleform::GFx::Movie::Invoke(
      *(Scaleform::GFx::Movie **)(*(_QWORD *)&this[-1].mInitClothing[1].mUID + 320i64),
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

