// File Line: 96
// RVA: 0x15709E0
__int64 UFG::_dynamic_initializer_for__symCNYFlow__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("DLC_CNY", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&symCNYFlow, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__symCNYFlow__);
}

// File Line: 115
// RVA: 0x5C6900
void __fastcall UFG::UIHKScreenPauseMenu::UIHKScreenPauseMenu(UFG::UIHKScreenPauseMenu *this)
{
  UFG::OnlineManagerObserver *v2; // rcx

  this->UFG::UIScreen::UFG::qNode<UFG::UIScreen,UFG::UIScreen>::mPrev = &this->UFG::qNode<UFG::UIScreen,UFG::UIScreen>;
  this->UFG::UIScreen::UFG::qNode<UFG::UIScreen,UFG::UIScreen>::mNext = &this->UFG::qNode<UFG::UIScreen,UFG::UIScreen>;
  this->UFG::UIScreen::vfptr = (UFG::UIScreenVtbl *)&UFG::UIScreen::`vftable;
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
  v2 = &this->UFG::OnlineManagerObserver;
  v2->mPrev = &v2->UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver>;
  v2->mNext = &v2->UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver>;
  v2->vfptr = (UFG::OnlineManagerObserverVtbl *)&UFG::OnlineManagerObserver::`vftable;
  this->UFG::UIScreen::vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenPauseMenu::`vftable{for `UFG::UIScreen};
  v2->vfptr = (UFG::OnlineManagerObserverVtbl *)&UFG::UIHKScreenPauseMenu::`vftable{for `UFG::OnlineManagerObserver};
  this->mState = STATE_INIT;
  this->mInfoTickerSet = 0;
  UFG::UIPropertySetMenu::UIPropertySetMenu(&this->mMenu);
  this->mMenu.vfptr = (UFG::UIPropertySetMenuVtbl *)&UFG::UIPropertySetMenuMainNav::`vftable;
  this->mConfirmationMsgId = 0;
  UFG::MoviePlayer::MoviePlayer(&this->HKUIMovie);
}

// File Line: 122
// RVA: 0x5CBE10
void __fastcall UFG::UIHKScreenPauseMenu::~UIHKScreenPauseMenu(UFG::UIHKScreenPauseMenu *this)
{
  UFG::OnlineManagerObserver *v2; // rsi
  UFG::UIScreenTextureManager *v3; // rax
  UFG::UI *v4; // rcx
  unsigned int v5; // eax
  UFG::UIHKScreenGlobalOverlay *v6; // rax
  UFG::UIHKHelpBarWidget *p_HelpBar; // rdi
  unsigned int v8; // eax
  UFG::OnlineManager *v9; // rax
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *mPrev; // rcx
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *mNext; // rax

  this->UFG::UIScreen::vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenPauseMenu::`vftable{for `UFG::UIScreen};
  v2 = &this->UFG::OnlineManagerObserver;
  this->UFG::OnlineManagerObserver::vfptr = (UFG::OnlineManagerObserverVtbl *)&UFG::UIHKScreenPauseMenu::`vftable{for `UFG::OnlineManagerObserver};
  v3 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v3, "PauseMenu");
  if ( UFG::gInputSystem )
  {
    if ( UFG::gActiveControllerNum != -1 )
    {
      v5 = UFG::UI::gUIInputLocked;
      if ( !UFG::UI::gUIInputLocked || (--UFG::UI::gUIInputLocked, v5 == 1) )
        UFG::UI::ResetGameplayInput(v4);
    }
  }
  v6 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    v6 = &gGlobalOverlaySentinel;
  p_HelpBar = &v6->HelpBar;
  v8 = UFG::qStringHash32("UIHKScreenMainMenu", 0xFFFFFFFF);
  UFG::UIHKHelpBarWidget::Hide(p_HelpBar, v8);
  UFG::UIScreenManagerBase::queueMessage(UFG::UIScreenManager::s_instance, UI_HASH_PAUSE_SCREEN_EXIT_20, 0xFFFFFFFF);
  v9 = UFG::OnlineManager::Instance();
  UFG::OSuiteManager::UnRegisterObserver(v9, v2);
  UFG::MoviePlayer::~MoviePlayer(&this->HKUIMovie);
  UFG::UIPropertySetMenu::~UIPropertySetMenu(&this->mMenu);
  v2->vfptr = (UFG::OnlineManagerObserverVtbl *)&UFG::OnlineManagerObserver::`vftable;
  mPrev = v2->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = &v2->UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver>;
  v2->mNext = &v2->UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver>;
  UFG::UIScreen::~UIScreen(this);
}

// File Line: 138
// RVA: 0x634DB0
void __fastcall UFG::UIHKScreenPauseMenu::init(UFG::UIHKScreenPauseMenu *this, UFG::UICommandData *data)
{
  Scaleform::GFx::Movie *pObject; // rdi
  bool v4; // bp
  _DWORD *v5; // rbx
  UFG::UIPropertySetMenuMainNav *p_mMenu; // rbx
  bool v7; // di
  UFG::ProgressionTracker *v8; // rax
  UFG::GameSlice *ActiveMaster; // rax
  UFG::GameSlice::Type mType; // eax
  char v11; // al
  unsigned int v12; // eax
  UFG::UIGfxTranslator *m_translator; // rcx
  const char *v14; // rdx
  unsigned int v15; // eax
  UFG::UIGfxTranslator *v16; // rcx
  const char *v17; // rdx
  UFG::ProgressionTracker *v18; // rax
  UFG::qBaseTreeRB *v19; // rax
  unsigned int v20; // eax
  UFG::UIGfxTranslator *v21; // rcx
  const char *v22; // rdx
  unsigned int v23; // eax
  UFG::UIGfxTranslator *v24; // rcx
  const char *v25; // rdx
  UFG::ProgressionTracker *v26; // rax
  unsigned int v27; // eax
  UFG::UIGfxTranslator *v28; // rcx
  const char *v29; // rdx
  unsigned int v30; // eax
  UFG::UIGfxTranslator *v31; // rcx
  const char *v32; // rdx
  signed __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::ProgressionTracker *v35; // rax
  UFG::qBaseTreeRB *v36; // rax
  unsigned int v37; // eax
  UFG::UIGfxTranslator *v38; // rcx
  const char *v39; // rdx
  UFG::ProgressionTracker *v40; // rax
  unsigned int v41; // eax
  UFG::UIGfxTranslator *v42; // rcx
  const char *v43; // rdx
  UFG::Controller *v44; // r8
  UFG::OSuiteDBLogger *v45; // rax
  UFG::OnlineManager *v46; // rax
  UFG::InputActionData *v47; // rcx
  __int64 v48[2]; // [rsp+40h] [rbp-88h] BYREF
  UFG::qString v49; // [rsp+50h] [rbp-78h] BYREF
  UFG::qString v50; // [rsp+78h] [rbp-50h] BYREF
  UFG::qSymbol result; // [rsp+D0h] [rbp+8h] BYREF
  UFG::qSymbol name; // [rsp+E0h] [rbp+18h] BYREF
  _DWORD *v53; // [rsp+E8h] [rbp+20h]

  UFG::UIScreen::init(this, data);
  this->mState = STATE_VOLUME;
  UFG::UIScreenManagerBase::queueMessage(UFG::UIScreenManager::s_instance, UI_HASH_PAUSE_SCREEN_INIT_20, 0xFFFFFFFF);
  pObject = this->mRenderable->m_movie.pObject;
  v4 = 1;
  if ( pObject )
  {
    v5 = Scaleform::Memory::pGlobalHeap->vfptr->Alloc(Scaleform::Memory::pGlobalHeap, 32i64, 0i64);
    v53 = v5;
    if ( v5 )
    {
      *(_QWORD *)v5 = &Scaleform::RefCountImplCore::`vftable;
      v5[2] = 1;
      *(_QWORD *)v5 = &Scaleform::RefCountImpl::`vftable;
      *(_QWORD *)v5 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
      *(_QWORD *)v5 = &Scaleform::RefCountBase<Scaleform::GFx::State,2>::`vftable;
      *(_QWORD *)v5 = &Scaleform::GFx::State::`vftable;
      v5[4] = 3;
      *(_QWORD *)v5 = &Scaleform::GFx::ActionControl::`vftable;
      v5[6] = 8;
    }
    else
    {
      v5 = 0i64;
    }
    if ( v5 )
    {
      v5[6] |= 2u;
      pObject->Scaleform::GFx::StateBag::vfptr->SetState(
        &pObject->Scaleform::GFx::StateBag,
        State_Filter,
        (Scaleform::GFx::State *)v5);
    }
    if ( v5 )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v5);
  }
  v48[0] = (__int64)&UFG::UIPropertySetMenuData::`vftable;
  UFG::qString::qString(&v49);
  UFG::qString::qString(&v50);
  v48[1] = (__int64)this;
  UFG::qString::Set(&v50, "PauseMenu");
  UFG::qString::Set(&v49, "UI-PauseMenu");
  p_mMenu = &this->mMenu;
  (*(void (__fastcall **)(UFG::UIPropertySetMenuMainNav *, __int64 *))this->mMenu.vfptr->gap8)(&this->mMenu, v48);
  v7 = UFG::ProgressionTracker::Instance()->mModeType == ModeType_Challenge;
  v8 = UFG::ProgressionTracker::Instance();
  ActiveMaster = UFG::ProgressionTracker::GetActiveMaster(v8);
  if ( !ActiveMaster
    || (ActiveMaster->mInternalSlice
     || (mType = ActiveMaster->mType, mType != (NUM_TYPES|TYPE_OCCLUSION|0x8))
     && mType != 10
     && mType != 9
     && mType != 6
     && mType != (NUM_TYPES|TYPE_OCCLUSION|0x4)
     && mType != 8
      ? (v11 = 0)
      : (v11 = 1),
        !v11) )
  {
    v12 = UFG::qStringHashUpper32("COMMON_CANCEL_MISSION", -1);
    m_translator = UFG::UIScreenManager::s_instance->m_translator;
    if ( !m_translator || (v14 = (const char *)m_translator->vfptr[5].__vecDelDtor(m_translator, v12)) == 0i64 )
      v14 = "COMMON_CANCEL_MISSION";
    p_mMenu->vfptr->setItemEnabled(&this->mMenu, v14, 0);
  }
  if ( !UFG::UI::IsMissionWithCheckpointsActive(0) )
  {
    v15 = UFG::qStringHashUpper32("COMMON_RESTART_CHECKPOINT", -1);
    v16 = UFG::UIScreenManager::s_instance->m_translator;
    if ( !v16 || (v17 = (const char *)v16->vfptr[5].__vecDelDtor(v16, v15)) == 0i64 )
      v17 = "COMMON_RESTART_CHECKPOINT";
    p_mMenu->vfptr->setItemEnabled(&this->mMenu, v17, 0);
  }
  UFG::qSymbol::create_from_string(&result, "M_NMC");
  v18 = UFG::ProgressionTracker::Instance();
  v19 = UFG::ProgressionTracker::Find(v18, &result, 0);
  if ( v19 && LODWORD(v19[3].mNULL.mChild[1]) != 8 && !v7 )
  {
    v20 = UFG::qStringHashUpper32("COMMON_CANCEL_MISSION", -1);
    v21 = UFG::UIScreenManager::s_instance->m_translator;
    if ( !v21 || (v22 = (const char *)v21->vfptr[5].__vecDelDtor(v21, v20)) == 0i64 )
      v22 = "COMMON_CANCEL_MISSION";
    p_mMenu->vfptr->setItemEnabled(&this->mMenu, v22, 0);
    v23 = UFG::qStringHashUpper32("PAUSE_WORLDMAP_UPPERCASE", -1);
    v24 = UFG::UIScreenManager::s_instance->m_translator;
    if ( !v24 || (v25 = (const char *)v24->vfptr[5].__vecDelDtor(v24, v23)) == 0i64 )
      v25 = "PAUSE_WORLDMAP_UPPERCASE";
    p_mMenu->vfptr->setItemEnabled(&this->mMenu, v25, 0);
  }
  v26 = UFG::ProgressionTracker::Instance();
  if ( !(unsigned __int8)UFG::ProgressionTracker::IsUICancellationAllowed(v26)
    && UFG::ProgressionTracker::Instance()->mModeType != ModeType_Challenge )
  {
    v27 = UFG::qStringHashUpper32("COMMON_CANCEL_MISSION", -1);
    v28 = UFG::UIScreenManager::s_instance->m_translator;
    if ( !v28 || (v29 = (const char *)v28->vfptr[5].__vecDelDtor(v28, v27)) == 0i64 )
      v29 = "COMMON_CANCEL_MISSION";
    p_mMenu->vfptr->setItemEnabled(&this->mMenu, v29, 0);
    if ( !v7 )
    {
      v30 = UFG::qStringHashUpper32("PAUSE_MENU_SOCIALHUB_UPPERCASE", -1);
      v31 = UFG::UIScreenManager::s_instance->m_translator;
      if ( !v31 || (v32 = (const char *)v31->vfptr[5].__vecDelDtor(v31, v30)) == 0i64 )
        v32 = "PAUSE_MENU_SOCIALHUB_UPPERCASE";
      p_mMenu->vfptr->setItemEnabled(&this->mMenu, v32, 0);
    }
  }
  if ( LocalPlayer
    && ((m_Flags = LocalPlayer->m_Flags, (m_Flags & 0x4000) == 0)
      ? (m_Flags >= 0
       ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
        ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(LocalPlayer, UFG::HealthComponent::_TypeUID))
        : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(LocalPlayer, UFG::HealthComponent::_TypeUID)))
       : (ComponentOfTypeHK = LocalPlayer->m_Components.p[6].m_pComponent))
      : (ComponentOfTypeHK = LocalPlayer->m_Components.p[6].m_pComponent),
        ComponentOfTypeHK && !(int)*((float *)&ComponentOfTypeHK[1].m_SafePointerList.mNode.mNext + 1))
    || (UFG::qSymbol::create_from_string(&name, "M_CSCH"),
        v35 = UFG::ProgressionTracker::Instance(),
        (v36 = UFG::ProgressionTracker::Find(v35, &name, 0)) != 0i64)
    && LODWORD(v36[3].mNULL.mChild[1]) == 4 )
  {
    v37 = UFG::qStringHashUpper32("PAUSE_MENU_SAVE_LOAD", -1);
    v38 = UFG::UIScreenManager::s_instance->m_translator;
    if ( !v38 || (v39 = (const char *)v38->vfptr[5].__vecDelDtor(v38, v37)) == 0i64 )
      v39 = "PAUSE_MENU_SAVE_LOAD";
    p_mMenu->vfptr->setItemEnabled(&this->mMenu, v39, 0);
  }
  v40 = UFG::ProgressionTracker::Instance();
  if ( UFG::ProgressionTracker::GetActiveFlow(v40)->mUID == symCNYFlow.mUID )
  {
    v41 = UFG::qStringHashUpper32("PAUSE_MENU_UPGRADES_UPPERCASE", -1);
    v42 = UFG::UIScreenManager::s_instance->m_translator;
    if ( !v42 || (v43 = (const char *)v42->vfptr[5].__vecDelDtor(v42, v41)) == 0i64 )
      v43 = "PAUSE_MENU_UPGRADES_UPPERCASE";
    p_mMenu->vfptr->setItemEnabled(&this->mMenu, v43, 0);
  }
  if ( UFG::gInputSystem && UFG::gActiveControllerNum != -1 )
  {
    v44 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum];
    if ( !UFG::UI::gUIInputLocked )
      g_saved_gameplay_controller_mode = v44->m_ActiveMapSet;
    UFG::SetInputMode(IM_UI_ONLY, v44->mControllerIndex);
    ++UFG::UI::gUIInputLocked;
  }
  v45 = UFG::OSuiteDBLogger::Instance();
  UFG::OSuiteDBLogger::FlushIfTimeoutHasElapsed(v45);
  UFG::UIHKScreenPauseMenu::Flash_DisplayInfo(this);
  UFG::UIHKScreenPauseMenu::UpdateHelpBar(this);
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x882D720A, 0i64, 0, 0i64);
  v46 = UFG::OnlineManager::Instance();
  UFG::OnlineManager::RegisterObserver(v46, &this->UFG::OnlineManagerObserver);
  v47 = UFG::ActionDef_UIBackRepeat.mDataPerController[UFG::gActiveControllerNum];
  if ( !v47 || !v47->mActionTrue )
    v4 = 0;
  this->mIgnoreButtonOnce = v4;
  v48[0] = (__int64)&UFG::UIPropertySetMenuData::`vftable;
  UFG::qString::~qString(&v50);
  UFG::qString::~qString(&v49);
}

// File Line: 268
// RVA: 0x61FF30
void __fastcall UFG::UIHKScreenPauseMenu::dim(
        UFG::UIHKScreenPauseMenu *this,
        UFG::UIScreen::eDimType dimType,
        bool instant)
{
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h] BYREF

  UFG::UIScreen::dim(this, eDIM_ALPHA_FULL, instant);
  pObject = this->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    pargs.pObjectInterface = 0i64;
    pargs.Type = VT_Boolean;
    pargs.mValue.BValue = 0;
    Scaleform::GFx::Movie::Invoke(pObject, "PauseMenu_ShowTicker", 0i64, &pargs, 1u);
    Scaleform::GFx::Movie::Invoke(pObject, "dim", 0i64, 0i64, 0);
    if ( (pargs.Type & 0x40) != 0 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        pargs.mValue);
  }
}

// File Line: 284
// RVA: 0x63B710
void __fastcall UFG::UIHKScreenPauseMenu::undim(UFG::UIHKScreenPauseMenu *this, bool instant)
{
  UFG::InputActionData *v3; // rcx
  bool v4; // al
  Scaleform::GFx::Movie *pObject; // rbx
  UFG::OSuiteTickerManager *v6; // rax
  hkgpIndexedMeshDefinitions::Edge *v7; // rdx
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h] BYREF

  v3 = UFG::ActionDef_UIBackRepeat.mDataPerController[UFG::gActiveControllerNum];
  if ( !v3 || (v4 = 1, !v3->mActionTrue) )
    v4 = 0;
  this->mIgnoreButtonOnce = v4;
  UFG::UIScreen::undim(this, instant);
  pObject = this->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    pargs.pObjectInterface = 0i64;
    v6 = UFG::OSuiteTickerManager::Instance();
    pargs.Type = VT_Boolean;
    pargs.mValue.BValue = UFG::OSuiteTickerManager::IsTickerAvailable(v6, v7);
    Scaleform::GFx::Movie::Invoke(pObject, "PauseMenu_ShowTicker", 0i64, &pargs, 1u);
    Scaleform::GFx::Movie::Invoke(pObject, "undim", 0i64, 0i64, 0);
    Scaleform::GFx::Movie::Invoke(pObject, "Animate_Slots", 0i64, 0i64, 0);
    if ( (pargs.Type & 0x40) != 0 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        pargs.mValue);
  }
}

// File Line: 305
// RVA: 0x638F20
void __fastcall UFG::UIHKScreenPauseMenu::outro(UFG::UIHKScreenPauseMenu *this)
{
  UFG::UIHKScreenGlobalOverlay *v1; // rax
  UFG::UIHKHelpBarWidget *p_HelpBar; // rbx
  unsigned int v3; // eax

  this->mState = STATE_UISCALE;
  UFG::UIScreen::outro(this, 0i64);
  v1 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    v1 = &gGlobalOverlaySentinel;
  p_HelpBar = &v1->HelpBar;
  v3 = UFG::qStringHash32("UIHKScreenMainMenu", 0xFFFFFFFF);
  UFG::UIHKHelpBarWidget::Hide(p_HelpBar, v3);
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xEDA8B6F1, 0i64, 0, 0i64);
}

// File Line: 317
// RVA: 0x638A80
bool __fastcall UFG::UIHKScreenPauseMenu::msgShouldPushHudOnExit(UFG::UIHKScreenPauseMenu *this, unsigned int msgId)
{
  return msgId == UI_HASH_COMPLETE_MISSION_20
      || msgId == UI_HASH_RESTART_MISSION_20
      || msgId == UI_HASH_RESTORE_CHECKPOINT_20
      || msgId == UI_HASH_CANCEL_MISSION_20
      || msgId == UI_HASH_GOD_EVERYTHING_MODE_20
      || msgId == UI_HASH_GOD_MODE_20
      || msgId == UI_HASH_DEATH_TOUCH_20
      || msgId == UI_HASH_MAX_FACE_20
      || msgId == UI_HASH_MAX_FACE_LEVEL_20
      || msgId == UI_HASH_PURGE_ALL_UPGRADES_20
      || msgId == UI_HASH_MAX_UPGRADES_20
      || msgId == UI_HASH_PLAYER_INVULNERABLE_20
      || msgId == UI_HASH_PLAYER_SUICIDE_20
      || msgId == UI_HASH_RELOAD_WEAPON_20
      || msgId == UI_HASH_UNLIMITED_AMMO_20
      || msgId == UI_HASH_FREE_AIM_MODE_TOGGLE_20
      || msgId == UI_HASH_TOGGLE_MISSION_SCORING_DISPLAY_20
      || msgId == UI_HASH_SIMULATE_STATUE_COLLECTIBLE_PICKUP_20
      || msgId == UI_HASH_INCREASE_STATUE_OFFENSIVE_LEVEL_20
      || msgId == UI_HASH_INCREASE_STATUE_DEFENSIVE_LEVEL_20
      || msgId == UI_HASH_SIMULATE_TRIAD_UPGRADE_POINT_20
      || msgId == UI_HASH_INCREASE_TRIAD_OFFENSIVE_LEVEL_20
      || msgId == UI_HASH_INCREASE_TRIAD_DEFENSIVE_LEVEL_20
      || msgId == UI_HASH_SIMULATE_COP_UPGRADE_POINT_20
      || msgId == UI_HASH_INCREASE_COP_DRIVING_LEVEL_20
      || msgId == UI_HASH_INCREASE_COP_SHOOTING_LEVEL_20
      || msgId == UI_HASH_INCREASE_HEAT_LEVEL_20
      || msgId == UI_HASH_FREE_MONEY_SMALL_20
      || msgId == UI_HASH_FREE_MONEY_LARGE_20
      || msgId == UI_HASH_RESET_PLAYER_STATE_20
      || msgId == UI_HASH_SS_SPAWN_OBJ_20
      || msgId == UI_HASH_SS_GENERIC_CALL_20
      || msgId == UI_HASH_RUNTEST_RELOAD_20
      || msgId == UI_HASH_RUNTEST_ASIS_20
      || msgId == UI_HASH_MINIGAME_TELEPORT_20
      || msgId == UI_HASH_BUGPLANT_TELEPORT_20
      || msgId == UI_HASH_LOCKPICK_TELEPORT_20
      || msgId == UI_HASH_PHONETRACE_TELEPORT_20;
}

// File Line: 363
// RVA: 0x63E740
void __fastcall UFG::UIHKScreenPauseMenu::update(UFG::UIHKScreenPauseMenu *this, float elapsed)
{
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> **TopScreen; // rax

  UFG::UIScreen::update(this, elapsed);
  if ( this->mState == (NUM_CALIBRATION_STATES|STATE_VOLUME)
    && !UFG::UIScreenManagerBase::areScreensPending(UFG::UIScreenManager::s_instance)
    && !UFG::UIScreenManagerBase::areOverlaysPending(UFG::UIScreenManager::s_instance) )
  {
    TopScreen = UFG::UIScreenManagerBase::getTopScreen(UFG::UIScreenManager::s_instance);
    if ( TopScreen )
    {
      if ( *((_DWORD *)TopScreen + 28) != this->mScreenUID )
        this->mState = STATE_BRIGHTNESS;
    }
  }
}

// File Line: 397
// RVA: 0x628A20
bool __fastcall UFG::UIHKScreenPauseMenu::handleMessage(
        UFG::UIHKScreenPauseMenu *this,
        unsigned int msgId,
        UFG::UIMessage *msg)
{
  UFG::UIScreenTextureManager *v7; // rax
  UFG::UI *v8; // rcx
  bool v9; // al
  UFG::GameSaveLoad *v10; // rax
  UFG::GameSaveLoad *v11; // rax
  UFG::UIScreenTextureManager *v12; // rax
  UFG::allocator::free_link *v13; // rax
  const char *v14; // rsi
  char *mData; // rdx
  UFG::allocator::free_link *v16; // r8
  char v17; // cl
  UFG::UIScreenTextureManager *v18; // rax
  const char *v19; // rbx
  UFG::UIScreenTextureManager *v20; // rax
  UFG::UIScreenTextureManager *v21; // rax
  UFG::UIScreenTextureManager *v22; // rax
  UFG::UIScreenTextureManager *v23; // rax
  __int64 mConfirmationMsgId; // rdx
  UFG::UIScreenTextureManager *v25; // rax
  bool v26; // cl
  bool v27; // cl
  bool v28; // zf
  UFG::UIScreenTextureManager *v29; // rax
  UFG::UI *v30; // rcx

  UFG::AudioUISystem::HandleInput("PauseMenu", msgId, 1);
  if ( msgId == UI_HASH_BUTTON_BACK_RELEASED_30 && this->mIgnoreButtonOnce )
  {
    this->mIgnoreButtonOnce = 0;
    return 1;
  }
  switch ( this->mState )
  {
    case STATE_BRIGHTNESS:
      v9 = 0;
      if ( msgId == UI_HASH_KEYBOARD_INPUT_30 )
        v9 = LOBYTE(msg[1].vfptr) == 112;
      if ( (msgId != UI_HASH_BUTTON_BACK_RELEASED_30 || this->mMenu.mState)
        && msgId != UI_HASH_BUTTON_START_PRESSED_30
        && msgId != UI_HASH_GAME_RESUME_20
        && !v9 )
      {
        if ( msgId == UI_HASH_MEMCARD_SAVE_20 )
        {
          if ( UFG::ProgressionTracker::Instance()->mModeType == ModeType_Challenge )
          {
            UFG::UIScreenDialogBox::createOKDialog(this, &customCaption, "$PAUSE_NO_SAVE_DURING_REPLAY", 0);
          }
          else
          {
            v10 = UFG::GameSaveLoad::Instance();
            UFG::GameSaveLoad::ClearGameSlotHeaderInfo(v10);
            UFG::UIHKScreenSaveLoad::queueSaveLoadCommand(this, 1, 1);
            UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, this->mScreenUID);
          }
          return 1;
        }
        if ( msgId == UI_HASH_MEMCARD_LOAD_20 )
        {
          v11 = UFG::GameSaveLoad::Instance();
          UFG::GameSaveLoad::ClearGameSlotHeaderInfo(v11);
          if ( !UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "SaveLoad") )
          {
            UFG::UIHKScreenSaveLoad::mOwner = this;
            UFG::UIHKScreenSaveLoad::mIsSave = 0;
            UFG::UIHKScreenSaveLoad::m_bFromPauseMenu = 1;
            v12 = UFG::UIScreenTextureManager::Instance();
            UFG::UIScreenTextureManager::QueueLoadAndPush(v12, "SaveLoad", 0i64);
          }
          UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, this->mScreenUID);
          return 1;
        }
        if ( msgId == UI_HASH_SCREEN_PUSH_20 )
        {
          v13 = UFG::qMalloc(0x14ui64, "UIHKScreenPauseMenu", 0i64);
          v14 = (const char *)v13;
          if ( this->mMenu.mOpDependant.mLength )
          {
            mData = this->mMenu.mOpDependant.mData;
            v16 = v13;
            do
            {
              v17 = *mData;
              v16 = (UFG::allocator::free_link *)((char *)v16 + 1);
              ++mData;
              HIBYTE(v16[-1].mNext) = v17;
            }
            while ( v17 );
          }
          this->mState = NUM_CALIBRATION_STATES|STATE_VOLUME;
          v18 = UFG::UIScreenTextureManager::Instance();
          UFG::UIScreenTextureManager::QueueLoadAndPush(v18, v14, 0i64);
LABEL_114:
          if ( (*(unsigned __int8 (__fastcall **)(UFG::UIPropertySetMenuMainNav *, _QWORD, UFG::UIMessage *))&this->mMenu.vfptr->gap8[8])(
                 &this->mMenu,
                 msgId,
                 msg) )
          {
            UFG::UIHKScreenPauseMenu::UpdateHelpBar(this);
            return 1;
          }
          return UFG::UIScreen::handleMessage(this, msgId, msg);
        }
        if ( msgId == UI_HASH_CONTROLLERS_20 )
        {
          this->mState = NUM_CALIBRATION_STATES|STATE_VOLUME;
          v19 = "Options_Controllers";
          if ( UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
            v19 = "Options_ButtonMapping";
          v20 = UFG::UIScreenTextureManager::Instance();
          UFG::UIScreenTextureManager::QueueLoadAndPush(v20, v19, 0i64);
          return 1;
        }
        if ( msgId == UI_HASH_STATS_20 )
        {
          if ( UFG::HudAudio::m_instance )
            UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x688D286Au, 0i64, 0, 0i64);
          this->mState = NUM_CALIBRATION_STATES|STATE_VOLUME;
          v21 = UFG::UIScreenTextureManager::Instance();
          UFG::UIScreenTextureManager::QueueLoadAndPush(v21, "Stats", 0i64);
          return 1;
        }
        if ( msgId == UI_HASH_FACE_UPGRADES_20 )
        {
          UFG::UIHKScreenPauseMenu::SwitchToUpgradesScreen(this, UPGRADES_TYPE_FACE);
          return 1;
        }
        if ( msgId == UI_HASH_POLICE_UPGRADES_20 )
        {
          UFG::UIHKScreenPauseMenu::SwitchToUpgradesScreen(this, UPGRADES_TYPE_POLICE);
          return 1;
        }
        if ( msgId == UI_HASH_TRIAD_UPGRADES_20 )
        {
          UFG::UIHKScreenPauseMenu::SwitchToUpgradesScreen(this, UPGRADES_TYPE_TRIAD);
          return 1;
        }
        if ( msgId == UI_HASH_MELEE_UPGRADES_20 )
        {
          UFG::UIHKScreenPauseMenu::SwitchToUpgradesScreen(this, UPGRADES_TYPE_MELEE);
          return 1;
        }
        if ( msgId == UI_HASH_HEALTH_UPGRADES_20 )
        {
          UFG::UIHKScreenPauseMenu::SwitchToUpgradesScreen(this, UPGRADES_TYPE_HEALTH);
          return 1;
        }
        if ( msgId == UI_HASH_GAMETRACKER_COLLECTIBLES_20 )
        {
          if ( UFG::HudAudio::m_instance )
            UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xCBB448ED, 0i64, 0, 0i64);
          UFG::UIHKScreenGameTracker::m_eMode = GT_MODE_COLLECTIBLES;
LABEL_61:
          this->mState = NUM_CALIBRATION_STATES|STATE_VOLUME;
          v22 = UFG::UIScreenTextureManager::Instance();
          UFG::UIScreenTextureManager::QueueLoadAndPush(v22, "GameTracker", 0i64);
          return 1;
        }
        if ( msgId == UI_HASH_GAMETRACKER_ASSETS_20 )
        {
          if ( UFG::HudAudio::m_instance )
            UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xCBB448ED, 0i64, 0, 0i64);
          UFG::UIHKScreenGameTracker::m_eMode = GT_MODE_ASSETS;
          goto LABEL_61;
        }
        if ( msgId == UI_HASH_GAMETRACKER_UPGRADES_20 )
        {
          if ( UFG::HudAudio::m_instance )
            UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xCBB448ED, 0i64, 0, 0i64);
          UFG::UIHKScreenGameTracker::m_eMode = GT_MODE_UPGRADES;
          goto LABEL_61;
        }
        if ( msgId == UI_HASH_SOCIALHUB_20 )
        {
          if ( UFG::HudAudio::m_instance )
            UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x688D286Au, 0i64, 0, 0i64);
          this->mState = NUM_CALIBRATION_STATES|STATE_VOLUME;
          UFG::UIHKScreenSocialHub::gPushedFromPauseMenu = 1;
          v23 = UFG::UIScreenTextureManager::Instance();
          UFG::UIScreenTextureManager::QueueLoadAndPush(v23, "SocialHub", 0i64);
          UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, this->mScreenUID);
          return 1;
        }
        if ( msgId == UI_HASH_MAIN_MENU_20
          || msgId == UI_HASH_CANCEL_MISSION_20
          || msgId == UI_HASH_RESTORE_CHECKPOINT_20
          || msgId == UI_HASH_RESTART_MISSION_20 )
        {
          if ( UFG::HudAudio::m_instance )
            UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xCBB448ED, 0i64, 0, 0i64);
          this->mConfirmationMsgId = msgId;
          UFG::UIScreenDialogBox::createYesNoDialog(0i64, &customCaption, "$COMMON_TRC_LOSE_UNSAVED_PROGRESS", 0, 0);
          return 1;
        }
        if ( msgId != UI_HASH_RESET_VEHICLE_20 )
        {
          if ( msgId == UI_HASH_DIALOG_NO_30 )
            return 1;
          if ( msgId == UI_HASH_DIALOG_YES_30 )
          {
            mConfirmationMsgId = this->mConfirmationMsgId;
            if ( (_DWORD)mConfirmationMsgId == UI_HASH_MAIN_MENU_20 )
            {
              UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, 0xFFFFFFFF);
              UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, 0xFFFFFFFF);
              UFG::UI::QuitGame(0i64);
              UFG::RenderWorld::SetRenderWorld(0);
              return 1;
            }
            if ( (_DWORD)mConfirmationMsgId == UI_HASH_CANCEL_MISSION_20
              || (_DWORD)mConfirmationMsgId == UI_HASH_RESTORE_CHECKPOINT_20
              || (_DWORD)mConfirmationMsgId == UI_HASH_RESTART_MISSION_20 )
            {
              (*(void (__fastcall **)(UFG::UIPropertySetMenuMainNav *, __int64, UFG::UIMessage *))&this->mMenu.vfptr->gap8[8])(
                &this->mMenu,
                mConfirmationMsgId,
                msg);
            }
            goto LABEL_11;
          }
          if ( msgId == UI_HASH_WORLD_MAP_20 )
          {
            if ( UFG::UIHKScreenGlobalOverlay::mThis
              && UFG::UIHKScreenGlobalOverlay::mThis != (UFG::UIHKScreenGlobalOverlay *)-408i64 )
            {
              UFG::UIHK_NISOverlay::ShowElement(
                &UFG::UIHKScreenGlobalOverlay::mThis->NISOverlay,
                UFG::UIHKScreenGlobalOverlay::mThis,
                &UFG::UIHK_NISOverlay::m_curtains,
                0.33000001,
                1);
              UFG::UIHK_NISOverlay::m_curtains.m_mutingAudio = 1;
            }
            UFG::UIHK_NISOverlay::UpdateAudioMuteState();
            this->mState = NUM_CALIBRATION_STATES;
            return 1;
          }
          if ( msgId == UI_HASH_GAME_LOG_20 )
          {
            if ( UFG::HudAudio::m_instance )
              UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x688D286Au, 0i64, 0, 0i64);
            this->mState = NUM_CALIBRATION_STATES|STATE_VOLUME;
            v25 = UFG::UIScreenTextureManager::Instance();
            UFG::UIScreenTextureManager::QueueLoadAndPush(v25, "GameLog", 0i64);
            return 1;
          }
          if ( msgId == UI_HASH_TRAFFIC_CHEAT_POPULATION_STATS_20 )
          {
            v26 = UFG::UIHKTweakables::TrafficAvailableVehicles;
            UFG::UIHKTweakables::TrafficPopulationStats = !UFG::UIHKTweakables::TrafficPopulationStats;
            if ( UFG::UIHKTweakables::TrafficPopulationStats )
              v26 = 0;
            UFG::UIHKTweakables::TrafficAvailableVehicles = v26;
            return 1;
          }
          if ( msgId == UI_HASH_TRAFFIC_CHEAT_AVAILABLE_VEHICLES_20 )
          {
            v27 = UFG::UIHKTweakables::TrafficPopulationStats;
            v28 = UFG::UIHKTweakables::TrafficAvailableVehicles;
            UFG::UIHKTweakables::TrafficAvailableVehicles = !UFG::UIHKTweakables::TrafficAvailableVehicles;
            if ( !v28 )
              v27 = 0;
            UFG::UIHKTweakables::TrafficPopulationStats = v27;
            return 1;
          }
          if ( msgId == UI_HASH_TRAFFIC_VEHICLE_BLIPS_20 )
          {
            UFG::UIHKTweakables::TrafficVehicleBlips = !UFG::UIHKTweakables::TrafficVehicleBlips;
            return 1;
          }
          if ( msgId == UI_HASH_FACETRACKER_20 )
          {
            this->mState = NUM_CALIBRATION_STATES|STATE_VOLUME;
            v29 = UFG::UIScreenTextureManager::Instance();
            UFG::UIScreenTextureManager::QueueLoadAndPush(v29, "FaceTracker", 0i64);
            return 1;
          }
          if ( UFG::UIHKScreenPauseMenu::msgShouldPushHudOnExit(this, msgId) )
          {
            UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, 0xFFFFFFFF);
            UFG::UI::UnpauseGame(v30);
          }
          goto LABEL_114;
        }
        UFG::HumanDriverComponent::ResetVehicle();
      }
      ((void (__fastcall *)(UFG::UIHKScreenPauseMenu *))this->UFG::UIScreen::vfptr[1].__vecDelDtor)(this);
      return 1;
    case STATE_VOLUME:
      if ( msgId == UI_HASH_INTRO_COMPLETE_30 )
      {
        if ( UFG::UIHKScreenGlobalOverlay::mThis
          && UFG::UIHKScreenGlobalOverlay::mThis != (UFG::UIHKScreenGlobalOverlay *)-408i64
          && UFG::UIHKScreenGlobalOverlay::mThis->NISOverlay.mActive )
        {
          UFG::UIHK_NISOverlay::FadeToLight();
        }
        this->mState = STATE_BRIGHTNESS;
      }
      return UFG::UIScreen::handleMessage(this, msgId, msg);
    case STATE_UISCALE:
      if ( msgId == UI_HASH_OUTRO_COMPLETE_30 )
      {
LABEL_11:
        UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, 0xFFFFFFFF);
        UFG::UI::UnpauseGame(v8);
        return 1;
      }
      return UFG::UIScreen::handleMessage(this, msgId, msg);
  }
  if ( this->mState != NUM_CALIBRATION_STATES || msgId != UI_HASH_SCREEN_FADE_IN_COMPLETE_12 )
    return UFG::UIScreen::handleMessage(this, msgId, msg);
  UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, 0xFFFFFFFF);
  UFG::UIHKScreenWorldMap::gPushedFromPauseMenu = 1;
  v7 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::QueueLoadAndPush(v7, "WorldMap", 0i64);
  return 1;
}

// File Line: 801
// RVA: 0x612740
void __fastcall UFG::UIHKScreenPauseMenu::SwitchToUpgradesScreen(
        UFG::UIHKScreenPauseMenu *this,
        UFG::UIHKScreenUpgrades::eUpgradesType type)
{
  UFG::UIScreenTextureManager *v4; // rax

  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xCBB448ED, 0i64, 0, 0i64);
  this->mState = NUM_CALIBRATION_STATES|STATE_BRIGHTNESS;
  UFG::UIHKScreenUpgrades::mUpgradesType = type;
  v4 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::QueueLoadAndPush(v4, "Upgrades", 0i64);
  UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, this->mScreenUID);
}

// File Line: 812
// RVA: 0x5F7410
void __fastcall UFG::UIHKScreenPauseMenu::PopulateInfoTicker(UFG::UIHKScreenPauseMenu *this)
{
  UFG::OSuiteTickerManager *v2; // rax
  hkgpIndexedMeshDefinitions::Edge *v3; // rdx
  UFG::OSuiteTickerManager *v4; // rax
  char *TickerDescription; // r14
  int v6; // r8d
  Scaleform::GFx::Value *p_ptr; // rcx
  Scaleform::GFx::Value pargs; // [rsp+28h] [rbp-49h] BYREF
  Scaleform::GFx::Value ptr; // [rsp+58h] [rbp-19h] BYREF
  char v10[16]; // [rsp+88h] [rbp+17h] BYREF
  __int64 v11; // [rsp+98h] [rbp+27h]
  int v12; // [rsp+A0h] [rbp+2Fh]
  char *v13; // [rsp+A8h] [rbp+37h]
  __int64 v14; // [rsp+B8h] [rbp+47h]

  v14 = -2i64;
  v2 = UFG::OSuiteTickerManager::Instance();
  if ( UFG::OSuiteTickerManager::IsTickerAvailable(v2, v3) )
  {
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
    ptr.mValue.pString = "img://INFOCAST_CHANNEL_0";
    v4 = UFG::OSuiteTickerManager::Instance();
    TickerDescription = UFG::OSuiteTickerManager::GetTickerDescription(v4, 0i64, 1);
    if ( (v12 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v11 + 16i64))(v11, v10, v13);
      v11 = 0i64;
    }
    v12 = 6;
    v13 = TickerDescription;
    Scaleform::GFx::Movie::Invoke(this->mRenderable->m_movie.pObject, "PauseMenu_AddTickerInfo", 0i64, &ptr, 2u);
    `eh vector constructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( (pargs.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        pargs.mValue);
      pargs.pObjectInterface = 0i64;
    }
    pargs.Type = VT_Boolean;
    pargs.mValue.BValue = 1;
    Scaleform::GFx::Movie::Invoke(this->mRenderable->m_movie.pObject, "PauseMenu_ShowTicker", 0i64, &pargs, 1u);
    `eh vector destructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    v6 = 2;
    p_ptr = &ptr;
  }
  else
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
    pargs.Type = VT_Boolean;
    pargs.mValue.BValue = 0;
    Scaleform::GFx::Movie::Invoke(this->mRenderable->m_movie.pObject, "PauseMenu_ShowTicker", 0i64, &pargs, 1u);
    v6 = 1;
    p_ptr = &pargs;
  }
  `eh vector destructor iterator(p_ptr, 0x30ui64, v6, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 835
// RVA: 0x5DA600
void __fastcall UFG::UIHKScreenPauseMenu::Flash_DisplayInfo(UFG::UIHKScreenPauseMenu *this)
{
  Scaleform::GFx::Movie *pObject; // rdi
  UFG::GameStatTracker *v2; // rbx
  int Stat; // eax
  unsigned int v4; // eax
  UFG::UIGfxTranslator *m_translator; // rcx
  const char *v6; // rax
  UFG::GameStatTracker *v7; // rax
  int v8; // esi
  UFG::GameStatTracker *v9; // rax
  int v10; // r14d
  UFG::GameStatTracker *v11; // rax
  int v12; // r15d
  char *mData; // rbx
  Scaleform::GFx::Value ptr; // [rsp+30h] [rbp-A8h] BYREF
  char v15[8]; // [rsp+60h] [rbp-78h] BYREF
  char v16[8]; // [rsp+68h] [rbp-70h] BYREF
  __int64 v17; // [rsp+70h] [rbp-68h]
  __int64 v18; // [rsp+78h] [rbp-60h]
  int v19; // [rsp+80h] [rbp-58h]
  double v20; // [rsp+88h] [rbp-50h]
  char v21[16]; // [rsp+98h] [rbp-40h] BYREF
  __int64 v22; // [rsp+A8h] [rbp-30h]
  int v23; // [rsp+B0h] [rbp-28h]
  double v24; // [rsp+B8h] [rbp-20h]
  __int64 v25; // [rsp+C8h] [rbp-10h]
  UFG::qString string; // [rsp+D0h] [rbp-8h] BYREF
  UFG::qString v27; // [rsp+F8h] [rbp+20h] BYREF

  v25 = -2i64;
  pObject = this->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    v2 = UFG::GameStatTracker::Instance();
    UFG::qString::qString(&string);
    Stat = UFG::GameStatTracker::GetStat(v2, Money);
    UFG::UI::FormatMoneyStr(Stat, &string);
    v4 = UFG::qStringHashUpper32("PAUSE_MONEY_FORMAT", -1);
    m_translator = UFG::UIScreenManager::s_instance->m_translator;
    if ( !m_translator || (v6 = (const char *)m_translator->vfptr[5].__vecDelDtor(m_translator, v4)) == 0i64 )
      v6 = "PAUSE_MONEY_FORMAT";
    UFG::qString::qString(&v27, v6, string.mData);
    v7 = UFG::GameStatTracker::Instance();
    v8 = UFG::GameStatTracker::GetStat(v7, Standing);
    v9 = UFG::GameStatTracker::Instance();
    v10 = UFG::GameStatTracker::GetStat(v9, CopXP);
    v11 = UFG::GameStatTracker::Instance();
    v12 = UFG::GameStatTracker::GetStat(v11, TriadXP);
    `eh vector constructor iterator(&ptr, 0x30ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    mData = v27.mData;
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
    if ( (v18 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, unsigned __int64))(*(_QWORD *)v17 + 16i64))(v17, v15, ptr.DataAux);
      v17 = 0i64;
    }
    LODWORD(v18) = 5;
    *(double *)&ptr.DataAux = (double)v8;
    if ( (v19 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v18 + 16i64))(
        v18,
        v16,
        COERCE_DOUBLE(*(_QWORD *)&v20));
      v18 = 0i64;
    }
    v19 = 5;
    v20 = (double)v10;
    if ( (v23 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v22 + 16i64))(
        v22,
        v21,
        COERCE_DOUBLE(*(_QWORD *)&v24));
      v22 = 0i64;
    }
    v23 = 5;
    v24 = (double)v12;
    Scaleform::GFx::Movie::Invoke(pObject, "PauseMenu_DisplayInfo", 0i64, &ptr, 4u);
    `eh vector destructor iterator(&ptr, 0x30ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    UFG::qString::~qString(&v27);
    UFG::qString::~qString(&string);
  }
}

// File Line: 868
// RVA: 0x61A750
void __fastcall UFG::UIHKScreenPauseMenu::UpdateHelpBar(UFG::UIHKScreenPauseMenu *this)
{
  UFG::UIHKScreenGlobalOverlay *v1; // r14
  UFG::UIHKScreenGlobalOverlay *v2; // rax
  UFG::UIHKHelpBarWidget *p_HelpBar; // r15
  unsigned int v4; // esi
  unsigned int v5; // edi
  unsigned int v6; // ebx
  UFG::UIHKHelpBarData data; // [rsp+30h] [rbp-268h] BYREF

  v1 = &gGlobalOverlaySentinel;
  v2 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    v2 = &gGlobalOverlaySentinel;
  p_HelpBar = &v2->HelpBar;
  v4 = UI_HASH_BUTTON_BACK_RELEASED_30;
  v5 = UI_HASH_BUTTON_ACCEPT_PRESSED_30;
  v6 = UFG::qStringHash32("UIHKScreenMainMenu", 0xFFFFFFFF);
  UFG::UIHKHelpBarData::UIHKHelpBarData(&data);
  data.id = v6;
  *(_QWORD *)&data.priority = 0i64;
  *(__m128i *)data.Buttons = _mm_load_si128((const __m128i *)&_xmm);
  *(_QWORD *)&data.Buttons[4] = 0i64;
  UFG::qString::Set(data.Captions, "$COMMON_ACCEPT_UPPERCASE");
  UFG::qString::Set(&data.Captions[1], "$COMMON_BACK_UPPERCASE");
  UFG::qString::Set(&data.Captions[2], &customCaption);
  UFG::qString::Set(&data.Captions[3], &customCaption);
  UFG::qString::Set(&data.Captions[4], &customCaption);
  UFG::qString::Set(&data.Captions[5], &customCaption);
  data.MessageIds[0] = v5;
  data.MessageIds[1] = v4;
  *(_QWORD *)&data.MessageIds[2] = 0i64;
  *(_QWORD *)&data.MessageIds[4] = 0i64;
  UFG::UIHKHelpBarWidget::Show(p_HelpBar, &data);
  UFG::qString::~qString(&data.CustomTexturePack);
  `eh vector destructor iterator(data.Icons, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
  `eh vector destructor iterator(data.Captions, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
  if ( UFG::UIHKScreenGlobalOverlay::mThis )
    v1 = UFG::UIHKScreenGlobalOverlay::mThis;
  v1->HelpBar.mChanged |= COERCE_FLOAT(COERCE_UNSIGNED_INT(v1->HelpBar.mYOffset - -20.0) & _xmm) > 0.001;
  v1->HelpBar.mYOffset = -20.0;
}

// File Line: 881
// RVA: 0x5F2400
void __fastcall UFG::UIHKScreenPauseMenu::NetworkSignedIn(UFG::UIHKScreenPauseMenu *this)
{
  __int64 v1; // rax

  v1 = *(_QWORD *)&this[-1].HKUIMovie.mTargetTexture.mNameUID;
  if ( v1 )
  {
    if ( *(_QWORD *)(v1 + 320) )
      UFG::UIHKScreenPauseMenu::PopulateInfoTicker((UFG::UIHKScreenPauseMenu *)((char *)this - 144));
  }
}

