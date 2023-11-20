// File Line: 96
// RVA: 0x15709E0
__int64 UFG::_dynamic_initializer_for__symCNYFlow__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("DLC_CNY", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&symCNYFlow, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__symCNYFlow__);
}

// File Line: 115
// RVA: 0x5C6900
void __fastcall UFG::UIHKScreenPauseMenu::UIHKScreenPauseMenu(UFG::UIHKScreenPauseMenu *this)
{
  UFG::UIHKScreenPauseMenu *v1; // rdi
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v2; // rax
  UFG::OnlineManagerObserver *v3; // rcx
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *v4; // rax

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
  v3 = (UFG::OnlineManagerObserver *)&this->vfptr;
  v4 = (UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *)&v3->mPrev;
  v4->mPrev = v4;
  v4->mNext = v4;
  v3->vfptr = (UFG::OnlineManagerObserverVtbl *)&UFG::OnlineManagerObserver::`vftable;
  v1->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenPauseMenu::`vftable{for `UFG::UIScreen};
  v3->vfptr = (UFG::OnlineManagerObserverVtbl *)&UFG::UIHKScreenPauseMenu::`vftable{for `UFG::OnlineManagerObserver};
  v1->mState = 0;
  v1->mInfoTickerSet = 0;
  UFG::UIPropertySetMenu::UIPropertySetMenu((UFG::UIPropertySetMenu *)&v1->mMenu.vfptr);
  v1->mMenu.vfptr = (UFG::UIPropertySetMenuVtbl *)&UFG::UIPropertySetMenuMainNav::`vftable;
  v1->mConfirmationMsgId = 0;
  UFG::MoviePlayer::MoviePlayer(&v1->HKUIMovie);
}

// File Line: 122
// RVA: 0x5CBE10
void __fastcall UFG::UIHKScreenPauseMenu::~UIHKScreenPauseMenu(UFG::UIHKScreenPauseMenu *this)
{
  UFG::UIHKScreenPauseMenu *v1; // rbx
  UFG::OnlineManagerObserver *v2; // rsi
  UFG::UIScreenTextureManager *v3; // rax
  UFG::UI *v4; // rcx
  unsigned int v5; // eax
  UFG::UIHKScreenGlobalOverlay *v6; // rax
  UFG::UIHKHelpBarWidget *v7; // rdi
  unsigned int v8; // eax
  UFG::OnlineManager *v9; // rax
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *v10; // rdx
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *v11; // rcx
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *v12; // rax

  v1 = this;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenPauseMenu::`vftable{for `UFG::UIScreen};
  v2 = (UFG::OnlineManagerObserver *)&this->vfptr;
  this->vfptr = (UFG::OnlineManagerObserverVtbl *)&UFG::UIHKScreenPauseMenu::`vftable{for `UFG::OnlineManagerObserver};
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
  v7 = &v6->HelpBar;
  v8 = UFG::qStringHash32("UIHKScreenMainMenu", 0xFFFFFFFF);
  UFG::UIHKHelpBarWidget::Hide(v7, v8);
  UFG::UIScreenManagerBase::queueMessage(
    (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
    UI_HASH_PAUSE_SCREEN_EXIT_20,
    0xFFFFFFFF);
  v9 = UFG::OnlineManager::Instance();
  UFG::OSuiteManager::UnRegisterObserver(v9, v2);
  UFG::MoviePlayer::~MoviePlayer(&v1->HKUIMovie);
  UFG::UIPropertySetMenu::~UIPropertySetMenu((UFG::UIPropertySetMenu *)&v1->mMenu.vfptr);
  v2->vfptr = (UFG::OnlineManagerObserverVtbl *)&UFG::OnlineManagerObserver::`vftable;
  v10 = (UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *)&v2->mPrev;
  v11 = v2->mPrev;
  v12 = v2->mNext;
  v11->mNext = v12;
  v12->mPrev = v11;
  v10->mPrev = v10;
  v10->mNext = v10;
  UFG::UIScreen::~UIScreen((UFG::UIScreen *)&v1->vfptr);
}

// File Line: 138
// RVA: 0x634DB0
void __fastcall UFG::UIHKScreenPauseMenu::init(UFG::UIHKScreenPauseMenu *this, UFG::UICommandData *data)
{
  UFG::UIHKScreenPauseMenu *v2; // rsi
  Scaleform::GFx::Movie *v3; // rdi
  char v4; // bp
  _DWORD *v5; // rbx
  signed __int64 v6; // rbx
  bool v7; // di
  UFG::ProgressionTracker *v8; // rax
  UFG::GameSlice *v9; // rax
  UFG::GameSlice::Type v10; // eax
  char v11; // al
  unsigned int v12; // eax
  UFG::UIGfxTranslator *v13; // rcx
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
  unsigned __int16 v33; // dx
  UFG::SimComponent *v34; // rax
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
  void **v48; // [rsp+40h] [rbp-88h]
  UFG::UIHKScreenPauseMenu *v49; // [rsp+48h] [rbp-80h]
  UFG::qString v50; // [rsp+50h] [rbp-78h]
  UFG::qString v51; // [rsp+78h] [rbp-50h]
  UFG::qSymbol result; // [rsp+D0h] [rbp+8h]
  UFG::qSymbol name; // [rsp+E0h] [rbp+18h]
  _DWORD *v54; // [rsp+E8h] [rbp+20h]

  v2 = this;
  UFG::UIScreen::init((UFG::UIScreen *)&this->vfptr, data);
  v2->mState = 2;
  UFG::UIScreenManagerBase::queueMessage(
    (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
    UI_HASH_PAUSE_SCREEN_INIT_20,
    0xFFFFFFFF);
  v3 = v2->mRenderable->m_movie.pObject;
  v4 = 1;
  if ( v3 )
  {
    v5 = (_DWORD *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(Scaleform::Memory::pGlobalHeap, 32ui64, 0i64);
    v54 = v5;
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
      v3->vfptr->SetState((Scaleform::GFx::StateBag *)&v3->vfptr, State_Filter, (Scaleform::GFx::State *)v5);
    }
    if ( v5 )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v5);
  }
  v48 = &UFG::UIPropertySetMenuData::`vftable;
  UFG::qString::qString(&v50);
  UFG::qString::qString(&v51);
  v49 = v2;
  UFG::qString::Set(&v51, "PauseMenu");
  UFG::qString::Set(&v50, "UI-PauseMenu");
  v6 = (signed __int64)&v2->mMenu;
  (*(void (__fastcall **)(UFG::UIPropertySetMenuMainNav *, void ***))v2->mMenu.vfptr->gap8)(&v2->mMenu, &v48);
  v7 = UFG::ProgressionTracker::Instance()->mModeType == 2;
  v8 = UFG::ProgressionTracker::Instance();
  v9 = UFG::ProgressionTracker::GetActiveMaster(v8);
  if ( !v9
    || (v9->mInternalSlice || (v10 = v9->mType, v10 != 11) && v10 != 10 && v10 != 9 && v10 != 6 && v10 != 7 && v10 != 8 ? (v11 = 0) : (v11 = 1),
        !v11) )
  {
    v12 = UFG::qStringHashUpper32("COMMON_CANCEL_MISSION", 0xFFFFFFFF);
    v13 = UFG::UIScreenManager::s_instance->m_translator;
    if ( !v13
      || (v14 = (const char *)v13->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v13->vfptr, v12)) == 0i64 )
    {
      v14 = "COMMON_CANCEL_MISSION";
    }
    (*(void (__fastcall **)(UFG::UIPropertySetMenuMainNav *, const char *, _QWORD))(*(_QWORD *)v6 + 24i64))(
      &v2->mMenu,
      v14,
      0i64);
  }
  if ( !UFG::UI::IsMissionWithCheckpointsActive(0) )
  {
    v15 = UFG::qStringHashUpper32("COMMON_RESTART_CHECKPOINT", 0xFFFFFFFF);
    v16 = UFG::UIScreenManager::s_instance->m_translator;
    if ( !v16
      || (v17 = (const char *)v16->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v16->vfptr, v15)) == 0i64 )
    {
      v17 = "COMMON_RESTART_CHECKPOINT";
    }
    (*(void (__fastcall **)(UFG::UIPropertySetMenuMainNav *, const char *, _QWORD))(*(_QWORD *)v6 + 24i64))(
      &v2->mMenu,
      v17,
      0i64);
  }
  UFG::qSymbol::create_from_string(&result, "M_NMC");
  v18 = UFG::ProgressionTracker::Instance();
  v19 = UFG::ProgressionTracker::Find(v18, &result, 0);
  if ( v19 && LODWORD(v19[3].mNULL.mChild[1]) != 8 && !v7 )
  {
    v20 = UFG::qStringHashUpper32("COMMON_CANCEL_MISSION", 0xFFFFFFFF);
    v21 = UFG::UIScreenManager::s_instance->m_translator;
    if ( !v21
      || (v22 = (const char *)v21->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v21->vfptr, v20)) == 0i64 )
    {
      v22 = "COMMON_CANCEL_MISSION";
    }
    (*(void (__fastcall **)(UFG::UIPropertySetMenuMainNav *, const char *, _QWORD))(*(_QWORD *)v6 + 24i64))(
      &v2->mMenu,
      v22,
      0i64);
    v23 = UFG::qStringHashUpper32("PAUSE_WORLDMAP_UPPERCASE", 0xFFFFFFFF);
    v24 = UFG::UIScreenManager::s_instance->m_translator;
    if ( !v24
      || (v25 = (const char *)v24->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v24->vfptr, v23)) == 0i64 )
    {
      v25 = "PAUSE_WORLDMAP_UPPERCASE";
    }
    (*(void (__fastcall **)(UFG::UIPropertySetMenuMainNav *, const char *, _QWORD))(*(_QWORD *)v6 + 24i64))(
      &v2->mMenu,
      v25,
      0i64);
  }
  v26 = UFG::ProgressionTracker::Instance();
  if ( !(unsigned __int8)UFG::ProgressionTracker::IsUICancellationAllowed(v26)
    && UFG::ProgressionTracker::Instance()->mModeType != 2 )
  {
    v27 = UFG::qStringHashUpper32("COMMON_CANCEL_MISSION", 0xFFFFFFFF);
    v28 = UFG::UIScreenManager::s_instance->m_translator;
    if ( !v28
      || (v29 = (const char *)v28->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v28->vfptr, v27)) == 0i64 )
    {
      v29 = "COMMON_CANCEL_MISSION";
    }
    (*(void (__fastcall **)(UFG::UIPropertySetMenuMainNav *, const char *, _QWORD))(*(_QWORD *)v6 + 24i64))(
      &v2->mMenu,
      v29,
      0i64);
    if ( !v7 )
    {
      v30 = UFG::qStringHashUpper32("PAUSE_MENU_SOCIALHUB_UPPERCASE", 0xFFFFFFFF);
      v31 = UFG::UIScreenManager::s_instance->m_translator;
      if ( !v31
        || (v32 = (const char *)v31->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v31->vfptr, v30)) == 0i64 )
      {
        v32 = "PAUSE_MENU_SOCIALHUB_UPPERCASE";
      }
      (*(void (__fastcall **)(UFG::UIPropertySetMenuMainNav *, const char *, _QWORD))(*(_QWORD *)v6 + 24i64))(
        &v2->mMenu,
        v32,
        0i64);
    }
  }
  if ( LocalPlayer
    && ((v33 = LocalPlayer->m_Flags, !((v33 >> 14) & 1)) ? ((v33 & 0x8000u) == 0 ? (!((v33 >> 13) & 1) ? (!((v33 >> 12) & 1) ? (v34 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&LocalPlayer->vfptr, UFG::HealthComponent::_TypeUID)) : (v34 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&LocalPlayer->vfptr, UFG::HealthComponent::_TypeUID))) : (v34 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&LocalPlayer->vfptr, UFG::HealthComponent::_TypeUID))) : (v34 = LocalPlayer->m_Components.p[6].m_pComponent)) : (v34 = LocalPlayer->m_Components.p[6].m_pComponent),
        v34 && !(signed int)*((float *)&v34[1].m_SafePointerList.mNode.mNext + 1))
    || (UFG::qSymbol::create_from_string(&name, "M_CSCH"),
        v35 = UFG::ProgressionTracker::Instance(),
        (v36 = UFG::ProgressionTracker::Find(v35, &name, 0)) != 0i64)
    && LODWORD(v36[3].mNULL.mChild[1]) == 4 )
  {
    v37 = UFG::qStringHashUpper32("PAUSE_MENU_SAVE_LOAD", 0xFFFFFFFF);
    v38 = UFG::UIScreenManager::s_instance->m_translator;
    if ( !v38
      || (v39 = (const char *)v38->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v38->vfptr, v37)) == 0i64 )
    {
      v39 = "PAUSE_MENU_SAVE_LOAD";
    }
    (*(void (__fastcall **)(UFG::UIPropertySetMenuMainNav *, const char *, _QWORD))(*(_QWORD *)v6 + 24i64))(
      &v2->mMenu,
      v39,
      0i64);
  }
  v40 = UFG::ProgressionTracker::Instance();
  if ( UFG::ProgressionTracker::GetActiveFlow(v40)->mUID == symCNYFlow.mUID )
  {
    v41 = UFG::qStringHashUpper32("PAUSE_MENU_UPGRADES_UPPERCASE", 0xFFFFFFFF);
    v42 = UFG::UIScreenManager::s_instance->m_translator;
    if ( !v42
      || (v43 = (const char *)v42->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v42->vfptr, v41)) == 0i64 )
    {
      v43 = "PAUSE_MENU_UPGRADES_UPPERCASE";
    }
    (*(void (__fastcall **)(UFG::UIPropertySetMenuMainNav *, const char *, _QWORD))(*(_QWORD *)v6 + 24i64))(
      &v2->mMenu,
      v43,
      0i64);
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
  UFG::UIHKScreenPauseMenu::Flash_DisplayInfo(v2);
  UFG::UIHKScreenPauseMenu::UpdateHelpBar(v2);
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(
      (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
      0x882D720A,
      0i64,
      0,
      0i64);
  v46 = UFG::OnlineManager::Instance();
  UFG::OnlineManager::RegisterObserver(v46, (UFG::OnlineManagerObserver *)&v2->vfptr);
  v47 = UFG::ActionDef_UIBackRepeat.mDataPerController[UFG::gActiveControllerNum];
  if ( !v47 || !v47->mActionTrue )
    v4 = 0;
  v2->mIgnoreButtonOnce = v4;
  v48 = &UFG::UIPropertySetMenuData::`vftable;
  UFG::qString::~qString(&v51);
  UFG::qString::~qString(&v50);
}

// File Line: 268
// RVA: 0x61FF30
void __fastcall UFG::UIHKScreenPauseMenu::dim(UFG::UIHKScreenPauseMenu *this, UFG::UIScreen::eDimType dimType, bool instant)
{
  UFG::UIHKScreenPauseMenu *v3; // rbx
  Scaleform::GFx::Movie *v4; // rbx
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h]

  v3 = this;
  UFG::UIScreen::dim((UFG::UIScreen *)&this->vfptr, eDIM_ALPHA_FULL, instant);
  v4 = v3->mRenderable->m_movie.pObject;
  if ( v4 )
  {
    pargs.pObjectInterface = 0i64;
    pargs.Type = 2;
    pargs.mValue.BValue = 0;
    Scaleform::GFx::Movie::Invoke(v4, "PauseMenu_ShowTicker", 0i64, &pargs, 1u);
    Scaleform::GFx::Movie::Invoke(v4, "dim", 0i64, 0i64, 0);
    if ( ((unsigned int)pargs.Type >> 6) & 1 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        *(_QWORD *)&pargs.mValue.NValue);
  }
}

// File Line: 284
// RVA: 0x63B710
void __fastcall UFG::UIHKScreenPauseMenu::undim(UFG::UIHKScreenPauseMenu *this, bool instant)
{
  UFG::UIHKScreenPauseMenu *v2; // rbx
  UFG::InputActionData *v3; // rcx
  char v4; // al
  Scaleform::GFx::Movie *v5; // rbx
  UFG::OSuiteTickerManager *v6; // rax
  hkgpIndexedMeshDefinitions::Edge *v7; // rdx
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h]

  v2 = this;
  v3 = UFG::ActionDef_UIBackRepeat.mDataPerController[UFG::gActiveControllerNum];
  if ( !v3 || (v4 = 1, !v3->mActionTrue) )
    v4 = 0;
  v2->mIgnoreButtonOnce = v4;
  UFG::UIScreen::undim((UFG::UIScreen *)&v2->vfptr, instant);
  v5 = v2->mRenderable->m_movie.pObject;
  if ( v5 )
  {
    pargs.pObjectInterface = 0i64;
    v6 = UFG::OSuiteTickerManager::Instance();
    pargs.Type = 2;
    pargs.mValue.BValue = UFG::OSuiteTickerManager::IsTickerAvailable(v6, v7) != 0;
    Scaleform::GFx::Movie::Invoke(v5, "PauseMenu_ShowTicker", 0i64, &pargs, 1u);
    Scaleform::GFx::Movie::Invoke(v5, "undim", 0i64, 0i64, 0);
    Scaleform::GFx::Movie::Invoke(v5, "Animate_Slots", 0i64, 0i64, 0);
    if ( ((unsigned int)pargs.Type >> 6) & 1 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        *(_QWORD *)&pargs.mValue.NValue);
  }
}

// File Line: 305
// RVA: 0x638F20
void __fastcall UFG::UIHKScreenPauseMenu::outro(UFG::UIHKScreenPauseMenu *this)
{
  UFG::UIHKScreenGlobalOverlay *v1; // rax
  UFG::UIHKHelpBarWidget *v2; // rbx
  unsigned int v3; // eax

  this->mState = 3;
  UFG::UIScreen::outro((UFG::UIScreen *)&this->vfptr, 0i64);
  v1 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    v1 = &gGlobalOverlaySentinel;
  v2 = &v1->HelpBar;
  v3 = UFG::qStringHash32("UIHKScreenMainMenu", 0xFFFFFFFF);
  UFG::UIHKHelpBarWidget::Hide(v2, v3);
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(
      (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
      0xEDA8B6F1,
      0i64,
      0,
      0i64);
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
  UFG::UIHKScreenPauseMenu *v2; // rbx
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> **v3; // rax

  v2 = this;
  UFG::UIScreen::update((UFG::UIScreen *)&this->vfptr, elapsed);
  if ( v2->mState == 6
    && !UFG::UIScreenManagerBase::areScreensPending((UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr)
    && !UFG::UIScreenManagerBase::areOverlaysPending((UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr) )
  {
    v3 = UFG::UIScreenManagerBase::getTopScreen((UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr);
    if ( v3 )
    {
      if ( *((_DWORD *)v3 + 28) != v2->mScreenUID )
        v2->mState = 1;
    }
  }
}

// File Line: 397
// RVA: 0x628A20
bool __fastcall UFG::UIHKScreenPauseMenu::handleMessage(UFG::UIHKScreenPauseMenu *this, unsigned int msgId, UFG::UIMessage *msg)
{
  UFG::UIHKScreenPauseMenu *v3; // rdi
  UFG::UIMessage *v4; // rbp
  unsigned int v5; // ebx
  UFG::UIScreenTextureManager *v7; // rax
  UFG::UI *v8; // rcx
  bool v9; // al
  UFG::GameSaveLoad *v10; // rax
  UFG::GameSaveLoad *v11; // rax
  UFG::UIScreenTextureManager *v12; // rax
  UFG::allocator::free_link *v13; // rax
  const char *v14; // rsi
  char *v15; // rdx
  UFG::allocator::free_link *v16; // r8
  char v17; // cl
  UFG::UIScreenTextureManager *v18; // rax
  const char *v19; // rbx
  UFG::UIScreenTextureManager *v20; // rax
  UFG::UIScreenTextureManager *v21; // rax
  UFG::UIScreenTextureManager *v22; // rax
  UFG::UIScreenTextureManager *v23; // rax
  __int64 v24; // rdx
  UFG::UI *v25; // rcx
  UFG::UIScreenTextureManager *v26; // rax
  bool v27; // cl
  bool v28; // cl
  bool v29; // zf
  UFG::UIScreenTextureManager *v30; // rax
  UFG::UI *v31; // rcx

  v3 = this;
  v4 = msg;
  v5 = msgId;
  UFG::AudioUISystem::HandleInput("PauseMenu", msgId, 1);
  if ( v5 == UI_HASH_BUTTON_BACK_RELEASED_30 && v3->mIgnoreButtonOnce )
  {
    v3->mIgnoreButtonOnce = 0;
    return 1;
  }
  switch ( v3->mState )
  {
    case 1:
      v9 = 0;
      if ( v5 == UI_HASH_KEYBOARD_INPUT_30 )
        v9 = LOBYTE(v4[1].vfptr) == 112;
      if ( (v5 != UI_HASH_BUTTON_BACK_RELEASED_30 || v3->mMenu.mState)
        && v5 != UI_HASH_BUTTON_START_PRESSED_30
        && v5 != UI_HASH_GAME_RESUME_20
        && !v9 )
      {
        if ( v5 == UI_HASH_MEMCARD_SAVE_20 )
        {
          if ( UFG::ProgressionTracker::Instance()->mModeType == 2 )
          {
            UFG::UIScreenDialogBox::createOKDialog(
              (UFG::UIScreen *)&v3->vfptr,
              &customWorldMapCaption,
              "$PAUSE_NO_SAVE_DURING_REPLAY",
              0);
          }
          else
          {
            v10 = UFG::GameSaveLoad::Instance();
            UFG::GameSaveLoad::ClearGameSlotHeaderInfo(v10);
            UFG::UIHKScreenSaveLoad::queueSaveLoadCommand((UFG::UIScreen *)&v3->vfptr, 1, 1);
            UFG::UIScreenManagerBase::queuePopScreen(
              (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
              v3->mScreenUID);
          }
          return 1;
        }
        if ( v5 == UI_HASH_MEMCARD_LOAD_20 )
        {
          v11 = UFG::GameSaveLoad::Instance();
          UFG::GameSaveLoad::ClearGameSlotHeaderInfo(v11);
          if ( !UFG::UIScreenManagerBase::getScreen(
                  (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
                  "SaveLoad") )
          {
            UFG::UIHKScreenSaveLoad::mOwner = (UFG::UIScreen *)&v3->vfptr;
            UFG::UIHKScreenSaveLoad::mIsSave = 0;
            UFG::UIHKScreenSaveLoad::m_bFromPauseMenu = 1;
            v12 = UFG::UIScreenTextureManager::Instance();
            UFG::UIScreenTextureManager::QueueLoadAndPush(v12, "SaveLoad", 0i64);
          }
          UFG::UIScreenManagerBase::queuePopScreen(
            (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
            v3->mScreenUID);
          return 1;
        }
        if ( v5 == UI_HASH_SCREEN_PUSH_20 )
        {
          v13 = UFG::qMalloc(0x14ui64, "UIHKScreenPauseMenu", 0i64);
          v14 = (const char *)v13;
          if ( v3->mMenu.mOpDependant.mLength )
          {
            v15 = v3->mMenu.mOpDependant.mData;
            v16 = v13;
            do
            {
              v17 = *v15;
              v16 = (UFG::allocator::free_link *)((char *)v16 + 1);
              ++v15;
              HIBYTE(v16[-1].mNext) = v17;
            }
            while ( v17 );
          }
          v3->mState = 6;
          v18 = UFG::UIScreenTextureManager::Instance();
          UFG::UIScreenTextureManager::QueueLoadAndPush(v18, v14, 0i64);
LABEL_115:
          if ( (*(unsigned __int8 (__fastcall **)(UFG::UIPropertySetMenuMainNav *, _QWORD, UFG::UIMessage *))&v3->mMenu.vfptr->gap8[8])(
                 &v3->mMenu,
                 v5,
                 v4) )
          {
            UFG::UIHKScreenPauseMenu::UpdateHelpBar(v3);
            return 1;
          }
          return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v3->vfptr, v5, v4);
        }
        if ( v5 == UI_HASH_CONTROLLERS_20 )
        {
          v3->mState = 6;
          v19 = "Options_Controllers";
          if ( UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
            v19 = "Options_ButtonMapping";
          v20 = UFG::UIScreenTextureManager::Instance();
          UFG::UIScreenTextureManager::QueueLoadAndPush(v20, v19, 0i64);
          return 1;
        }
        if ( v5 == UI_HASH_STATS_20 )
        {
          if ( UFG::HudAudio::m_instance )
            UFG::AudioEntity::CreateAndPlayEvent(
              (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
              0x688D286Au,
              0i64,
              0,
              0i64);
          v3->mState = 6;
          v21 = UFG::UIScreenTextureManager::Instance();
          UFG::UIScreenTextureManager::QueueLoadAndPush(v21, "Stats", 0i64);
          return 1;
        }
        if ( v5 == UI_HASH_FACE_UPGRADES_20 )
        {
          UFG::UIHKScreenPauseMenu::SwitchToUpgradesScreen(v3, UPGRADES_TYPE_FACE);
          return 1;
        }
        if ( v5 == UI_HASH_POLICE_UPGRADES_20 )
        {
          UFG::UIHKScreenPauseMenu::SwitchToUpgradesScreen(v3, 0);
          return 1;
        }
        if ( v5 == UI_HASH_TRIAD_UPGRADES_20 )
        {
          UFG::UIHKScreenPauseMenu::SwitchToUpgradesScreen(v3, UPGRADES_TYPE_TRIAD);
          return 1;
        }
        if ( v5 == UI_HASH_MELEE_UPGRADES_20 )
        {
          UFG::UIHKScreenPauseMenu::SwitchToUpgradesScreen(v3, UPGRADES_TYPE_MELEE);
          return 1;
        }
        if ( v5 == UI_HASH_HEALTH_UPGRADES_20 )
        {
          UFG::UIHKScreenPauseMenu::SwitchToUpgradesScreen(v3, UPGRADES_TYPE_HEALTH);
          return 1;
        }
        if ( v5 == UI_HASH_GAMETRACKER_COLLECTIBLES_20 )
        {
          if ( UFG::HudAudio::m_instance )
            UFG::AudioEntity::CreateAndPlayEvent(
              (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
              0xCBB448ED,
              0i64,
              0,
              0i64);
          UFG::UIHKScreenGameTracker::m_eMode = 0;
LABEL_61:
          v3->mState = 6;
          v22 = UFG::UIScreenTextureManager::Instance();
          UFG::UIScreenTextureManager::QueueLoadAndPush(v22, "GameTracker", 0i64);
          return 1;
        }
        if ( v5 == UI_HASH_GAMETRACKER_ASSETS_20 )
        {
          if ( UFG::HudAudio::m_instance )
            UFG::AudioEntity::CreateAndPlayEvent(
              (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
              0xCBB448ED,
              0i64,
              0,
              0i64);
          UFG::UIHKScreenGameTracker::m_eMode = 1;
          goto LABEL_61;
        }
        if ( v5 == UI_HASH_GAMETRACKER_UPGRADES_20 )
        {
          if ( UFG::HudAudio::m_instance )
            UFG::AudioEntity::CreateAndPlayEvent(
              (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
              0xCBB448ED,
              0i64,
              0,
              0i64);
          UFG::UIHKScreenGameTracker::m_eMode = 2;
          goto LABEL_61;
        }
        if ( v5 == UI_HASH_SOCIALHUB_20 )
        {
          if ( UFG::HudAudio::m_instance )
            UFG::AudioEntity::CreateAndPlayEvent(
              (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
              0x688D286Au,
              0i64,
              0,
              0i64);
          v3->mState = 6;
          UFG::UIHKScreenSocialHub::gPushedFromPauseMenu = 1;
          v23 = UFG::UIScreenTextureManager::Instance();
          UFG::UIScreenTextureManager::QueueLoadAndPush(v23, "SocialHub", 0i64);
          UFG::UIScreenManagerBase::queuePopScreen(
            (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
            v3->mScreenUID);
          return 1;
        }
        if ( v5 == UI_HASH_MAIN_MENU_20
          || v5 == UI_HASH_CANCEL_MISSION_20
          || v5 == UI_HASH_RESTORE_CHECKPOINT_20
          || v5 == UI_HASH_RESTART_MISSION_20 )
        {
          if ( UFG::HudAudio::m_instance )
            UFG::AudioEntity::CreateAndPlayEvent(
              (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
              0xCBB448ED,
              0i64,
              0,
              0i64);
          v3->mConfirmationMsgId = v5;
          UFG::UIScreenDialogBox::createYesNoDialog(
            0i64,
            &customWorldMapCaption,
            "$COMMON_TRC_LOSE_UNSAVED_PROGRESS",
            0,
            0);
          return 1;
        }
        if ( v5 != UI_HASH_RESET_VEHICLE_20 )
        {
          if ( v5 == UI_HASH_DIALOG_NO_30 )
            return 1;
          if ( v5 == UI_HASH_DIALOG_YES_30 )
          {
            v24 = v3->mConfirmationMsgId;
            if ( (_DWORD)v24 == UI_HASH_MAIN_MENU_20 )
            {
              UFG::UIScreenManagerBase::queuePopScreen(
                (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
                0xFFFFFFFF);
              UFG::UIScreenManagerBase::queuePopScreen(
                (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
                0xFFFFFFFF);
              UFG::UI::QuitGame(0i64);
              UFG::RenderWorld::SetRenderWorld(0);
            }
            else
            {
              if ( (_DWORD)v24 == UI_HASH_CANCEL_MISSION_20
                || (_DWORD)v24 == UI_HASH_RESTORE_CHECKPOINT_20
                || (_DWORD)v24 == UI_HASH_RESTART_MISSION_20 )
              {
                (*(void (__fastcall **)(UFG::UIPropertySetMenuMainNav *, __int64, UFG::UIMessage *))&v3->mMenu.vfptr->gap8[8])(
                  &v3->mMenu,
                  v24,
                  v4);
              }
              UFG::UIScreenManagerBase::queuePopScreen(
                (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
                0xFFFFFFFF);
              UFG::UI::UnpauseGame(v25);
            }
            return 1;
          }
          if ( v5 == UI_HASH_WORLD_MAP_20 )
          {
            if ( UFG::UIHKScreenGlobalOverlay::mThis
              && UFG::UIHKScreenGlobalOverlay::mThis != (UFG::UIHKScreenGlobalOverlay *)-408i64 )
            {
              UFG::UIHK_NISOverlay::ShowElement(
                &UFG::UIHKScreenGlobalOverlay::mThis->NISOverlay,
                (UFG::UIScreen *)&UFG::UIHKScreenGlobalOverlay::mThis->vfptr,
                &UFG::UIHK_NISOverlay::m_curtains,
                0.33000001,
                1);
              UFG::UIHK_NISOverlay::m_curtains.m_mutingAudio = 1;
            }
            UFG::UIHK_NISOverlay::UpdateAudioMuteState();
            v3->mState = 4;
            return 1;
          }
          if ( v5 == UI_HASH_GAME_LOG_20 )
          {
            if ( UFG::HudAudio::m_instance )
              UFG::AudioEntity::CreateAndPlayEvent(
                (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
                0x688D286Au,
                0i64,
                0,
                0i64);
            v3->mState = 6;
            v26 = UFG::UIScreenTextureManager::Instance();
            UFG::UIScreenTextureManager::QueueLoadAndPush(v26, "GameLog", 0i64);
            return 1;
          }
          if ( v5 == UI_HASH_TRAFFIC_CHEAT_POPULATION_STATS_20 )
          {
            v27 = UFG::UIHKTweakables::TrafficAvailableVehicles;
            UFG::UIHKTweakables::TrafficPopulationStats = UFG::UIHKTweakables::TrafficPopulationStats == 0;
            if ( UFG::UIHKTweakables::TrafficPopulationStats == 1 )
              v27 = 0;
            UFG::UIHKTweakables::TrafficAvailableVehicles = v27;
            return 1;
          }
          if ( v5 == UI_HASH_TRAFFIC_CHEAT_AVAILABLE_VEHICLES_20 )
          {
            v28 = UFG::UIHKTweakables::TrafficPopulationStats;
            v29 = UFG::UIHKTweakables::TrafficAvailableVehicles != 0;
            UFG::UIHKTweakables::TrafficAvailableVehicles = UFG::UIHKTweakables::TrafficAvailableVehicles == 0;
            if ( !v29 )
              v28 = 0;
            UFG::UIHKTweakables::TrafficPopulationStats = v28;
            return 1;
          }
          if ( v5 == UI_HASH_TRAFFIC_VEHICLE_BLIPS_20 )
          {
            UFG::UIHKTweakables::TrafficVehicleBlips = UFG::UIHKTweakables::TrafficVehicleBlips == 0;
            return 1;
          }
          if ( v5 == UI_HASH_FACETRACKER_20 )
          {
            v3->mState = 6;
            v30 = UFG::UIScreenTextureManager::Instance();
            UFG::UIScreenTextureManager::QueueLoadAndPush(v30, "FaceTracker", 0i64);
            return 1;
          }
          if ( UFG::UIHKScreenPauseMenu::msgShouldPushHudOnExit(v3, v5) )
          {
            UFG::UIScreenManagerBase::queuePopScreen(
              (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
              0xFFFFFFFF);
            UFG::UI::UnpauseGame(v31);
          }
          goto LABEL_115;
        }
        UFG::HumanDriverComponent::ResetVehicle();
      }
      ((void (__fastcall *)(UFG::UIHKScreenPauseMenu *))v3->vfptr[1].__vecDelDtor)(v3);
      return 1;
    case 2:
      if ( v5 == UI_HASH_INTRO_COMPLETE_30 )
      {
        if ( UFG::UIHKScreenGlobalOverlay::mThis
          && UFG::UIHKScreenGlobalOverlay::mThis != (UFG::UIHKScreenGlobalOverlay *)-408i64
          && UFG::UIHKScreenGlobalOverlay::mThis->NISOverlay.mActive )
        {
          UFG::UIHK_NISOverlay::FadeToLight();
        }
        v3->mState = 1;
      }
      return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v3->vfptr, v5, v4);
    case 3:
      if ( v5 == UI_HASH_OUTRO_COMPLETE_30 )
      {
        UFG::UIScreenManagerBase::queuePopScreen(
          (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
          0xFFFFFFFF);
        UFG::UI::UnpauseGame(v8);
        return 1;
      }
      return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v3->vfptr, v5, v4);
  }
  if ( v3->mState != 4 || v5 != UI_HASH_SCREEN_FADE_IN_COMPLETE_12 )
    return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v3->vfptr, v5, v4);
  UFG::UIScreenManagerBase::queuePopScreen(
    (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
    0xFFFFFFFF);
  UFG::UIHKScreenWorldMap::gPushedFromPauseMenu = 1;
  v7 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::QueueLoadAndPush(v7, "WorldMap", 0i64);
  return 1;
}

// File Line: 801
// RVA: 0x612740
void __fastcall UFG::UIHKScreenPauseMenu::SwitchToUpgradesScreen(UFG::UIHKScreenPauseMenu *this, UFG::UIHKScreenUpgrades::eUpgradesType type)
{
  UFG::UIHKScreenPauseMenu *v2; // rbx
  UFG::UIHKScreenUpgrades::eUpgradesType v3; // edi
  UFG::UIScreenTextureManager *v4; // rax

  v2 = this;
  v3 = type;
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(
      (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
      0xCBB448ED,
      0i64,
      0,
      0i64);
  v2->mState = 5;
  UFG::UIHKScreenUpgrades::mUpgradesType = v3;
  v4 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::QueueLoadAndPush(v4, "Upgrades", 0i64);
  UFG::UIScreenManagerBase::queuePopScreen(
    (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
    v2->mScreenUID);
}

// File Line: 812
// RVA: 0x5F7410
void __fastcall UFG::UIHKScreenPauseMenu::PopulateInfoTicker(UFG::UIHKScreenPauseMenu *this)
{
  UFG::UIHKScreenPauseMenu *v1; // rsi
  UFG::OSuiteTickerManager *v2; // rax
  hkgpIndexedMeshDefinitions::Edge *v3; // rdx
  UFG::OSuiteTickerManager *v4; // rax
  char *v5; // r14
  int v6; // er8
  Scaleform::GFx::Value *v7; // rcx
  Scaleform::GFx::Value pargs; // [rsp+28h] [rbp-49h]
  char ptr; // [rsp+58h] [rbp-19h]
  __int64 v10; // [rsp+68h] [rbp-9h]
  unsigned int v11; // [rsp+70h] [rbp-1h]
  const char *v12; // [rsp+78h] [rbp+7h]
  char v13; // [rsp+88h] [rbp+17h]
  __int64 v14; // [rsp+98h] [rbp+27h]
  unsigned int v15; // [rsp+A0h] [rbp+2Fh]
  char *v16; // [rsp+A8h] [rbp+37h]
  __int64 v17; // [rsp+B8h] [rbp+47h]

  v17 = -2i64;
  v1 = this;
  v2 = UFG::OSuiteTickerManager::Instance();
  if ( UFG::OSuiteTickerManager::IsTickerAvailable(v2, v3) )
  {
    `eh vector constructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( (v11 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v10 + 16i64))(v10, &ptr, v12);
      v10 = 0i64;
    }
    v11 = 6;
    v12 = "img://INFOCAST_CHANNEL_0";
    v4 = UFG::OSuiteTickerManager::Instance();
    v5 = UFG::OSuiteTickerManager::GetTickerDescription(v4, 0i64, 1);
    if ( (v15 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v14 + 16i64))(v14, &v13, v16);
      v14 = 0i64;
    }
    v15 = 6;
    v16 = v5;
    Scaleform::GFx::Movie::Invoke(
      v1->mRenderable->m_movie.pObject,
      "PauseMenu_AddTickerInfo",
      0i64,
      (Scaleform::GFx::Value *)&ptr,
      2u);
    `eh vector constructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( ((unsigned int)pargs.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        *(_QWORD *)&pargs.mValue.NValue);
      pargs.pObjectInterface = 0i64;
    }
    pargs.Type = 2;
    pargs.mValue.BValue = 1;
    Scaleform::GFx::Movie::Invoke(v1->mRenderable->m_movie.pObject, "PauseMenu_ShowTicker", 0i64, &pargs, 1u);
    `eh vector destructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    v6 = 2;
    v7 = (Scaleform::GFx::Value *)&ptr;
  }
  else
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
    pargs.Type = 2;
    pargs.mValue.BValue = 0;
    Scaleform::GFx::Movie::Invoke(v1->mRenderable->m_movie.pObject, "PauseMenu_ShowTicker", 0i64, &pargs, 1u);
    v6 = 1;
    v7 = &pargs;
  }
  `eh vector destructor iterator(v7, 0x30ui64, v6, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 835
// RVA: 0x5DA600
void __fastcall UFG::UIHKScreenPauseMenu::Flash_DisplayInfo(UFG::UIHKScreenPauseMenu *this)
{
  Scaleform::GFx::Movie *v1; // rdi
  UFG::GameStatTracker *v2; // rbx
  int v3; // eax
  unsigned int v4; // eax
  UFG::UIGfxTranslator *v5; // rcx
  const char *v6; // rax
  UFG::GameStatTracker *v7; // rax
  signed int v8; // esi
  UFG::GameStatTracker *v9; // rax
  signed int v10; // er14
  UFG::GameStatTracker *v11; // rax
  signed int v12; // er15
  char *v13; // rbx
  char ptr; // [rsp+30h] [rbp-A8h]
  __int64 v15; // [rsp+40h] [rbp-98h]
  unsigned int v16; // [rsp+48h] [rbp-90h]
  char *v17; // [rsp+50h] [rbp-88h]
  double v18; // [rsp+58h] [rbp-80h]
  char v19; // [rsp+60h] [rbp-78h]
  char v20; // [rsp+68h] [rbp-70h]
  __int64 v21; // [rsp+70h] [rbp-68h]
  __int64 v22; // [rsp+78h] [rbp-60h]
  unsigned int v23; // [rsp+80h] [rbp-58h]
  double v24; // [rsp+88h] [rbp-50h]
  char v25; // [rsp+98h] [rbp-40h]
  __int64 v26; // [rsp+A8h] [rbp-30h]
  unsigned int v27; // [rsp+B0h] [rbp-28h]
  double v28; // [rsp+B8h] [rbp-20h]
  __int64 v29; // [rsp+C8h] [rbp-10h]
  UFG::qString string; // [rsp+D0h] [rbp-8h]
  UFG::qString v31; // [rsp+F8h] [rbp+20h]

  v29 = -2i64;
  v1 = this->mRenderable->m_movie.pObject;
  if ( v1 )
  {
    v2 = UFG::GameStatTracker::Instance();
    UFG::qString::qString(&string);
    v3 = UFG::GameStatTracker::GetStat(v2, Money);
    UFG::UI::FormatMoneyStr(v3, &string);
    v4 = UFG::qStringHashUpper32("PAUSE_MONEY_FORMAT", 0xFFFFFFFF);
    v5 = UFG::UIScreenManager::s_instance->m_translator;
    if ( !v5 || (v6 = (const char *)v5->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v5->vfptr, v4)) == 0i64 )
      v6 = "PAUSE_MONEY_FORMAT";
    UFG::qString::qString(&v31, v6, string.mData);
    v7 = UFG::GameStatTracker::Instance();
    v8 = UFG::GameStatTracker::GetStat(v7, Standing);
    v9 = UFG::GameStatTracker::Instance();
    v10 = UFG::GameStatTracker::GetStat(v9, CopXP);
    v11 = UFG::GameStatTracker::Instance();
    v12 = UFG::GameStatTracker::GetStat(v11, TriadXP);
    `eh vector constructor iterator(&ptr, 0x30ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    v13 = v31.mData;
    if ( (v16 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v15 + 16i64))(v15, &ptr, v17);
      v15 = 0i64;
    }
    v16 = 6;
    v17 = v13;
    if ( ((unsigned int)v22 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v21 + 16i64))(
        v21,
        &v19,
        COERCE_DOUBLE(*(_QWORD *)&v18));
      v21 = 0i64;
    }
    LODWORD(v22) = 5;
    v18 = (double)v8;
    if ( (v23 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v22 + 16i64))(
        v22,
        &v20,
        COERCE_DOUBLE(*(_QWORD *)&v24));
      v22 = 0i64;
    }
    v23 = 5;
    v24 = (double)v10;
    if ( (v27 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v26 + 16i64))(
        v26,
        &v25,
        COERCE_DOUBLE(*(_QWORD *)&v28));
      v26 = 0i64;
    }
    v27 = 5;
    v28 = (double)v12;
    Scaleform::GFx::Movie::Invoke(v1, "PauseMenu_DisplayInfo", 0i64, (Scaleform::GFx::Value *)&ptr, 4u);
    `eh vector destructor iterator(&ptr, 0x30ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    UFG::qString::~qString(&v31);
    UFG::qString::~qString(&string);
  }
}

// File Line: 868
// RVA: 0x61A750
void __fastcall UFG::UIHKScreenPauseMenu::UpdateHelpBar(UFG::UIHKScreenPauseMenu *this)
{
  UFG::UIHKScreenGlobalOverlay *v1; // r14
  UFG::UIHKScreenGlobalOverlay *v2; // rax
  UFG::UIHKHelpBarWidget *v3; // r15
  unsigned int v4; // esi
  unsigned int v5; // edi
  unsigned int v6; // ebx
  signed __int64 v7; // rbp
  UFG::UIHKHelpBarData data; // [rsp+30h] [rbp-268h]

  v1 = &gGlobalOverlaySentinel;
  v2 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    v2 = &gGlobalOverlaySentinel;
  v3 = &v2->HelpBar;
  v4 = UI_HASH_BUTTON_BACK_RELEASED_30;
  v5 = UI_HASH_BUTTON_ACCEPT_PRESSED_30;
  v6 = UFG::qStringHash32("UIHKScreenMainMenu", 0xFFFFFFFF);
  UFG::UIHKHelpBarData::UIHKHelpBarData(&data);
  data.id = v6;
  *(_QWORD *)&data.priority = 0i64;
  _mm_store_si128((__m128i *)data.Buttons, _mm_load_si128((const __m128i *)&_xmm));
  *(_QWORD *)&data.Buttons[4] = 0i64;
  UFG::qString::Set(data.Captions, "$COMMON_ACCEPT_UPPERCASE");
  UFG::qString::Set(&data.Captions[1], "$COMMON_BACK_UPPERCASE");
  UFG::qString::Set(&data.Captions[2], &customWorldMapCaption);
  UFG::qString::Set(&data.Captions[3], &customWorldMapCaption);
  UFG::qString::Set(&data.Captions[4], &customWorldMapCaption);
  UFG::qString::Set(&data.Captions[5], &customWorldMapCaption);
  data.MessageIds[0] = v5;
  data.MessageIds[1] = v4;
  *(_QWORD *)&data.MessageIds[2] = 0i64;
  *(_QWORD *)&data.MessageIds[4] = 0i64;
  UFG::UIHKHelpBarWidget::Show(v3, &data);
  UFG::qString::~qString(&data.CustomTexturePack);
  `eh vector destructor iterator(data.Icons, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
  `eh vector destructor iterator(data.Captions, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
  if ( UFG::UIHKScreenGlobalOverlay::mThis )
    v1 = UFG::UIHKScreenGlobalOverlay::mThis;
  v7 = (signed __int64)&v1->HelpBar;
  *(_BYTE *)(v7 + 1) |= COERCE_FLOAT(COERCE_UNSIGNED_INT(v1->HelpBar.mYOffset - -20.0) & _xmm) > 0.001;
  *(_DWORD *)(v7 + 612) = -1046478848;
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

