// File Line: 31
// RVA: 0x5C62C0
void __fastcall UFG::UIHKScreenNISPause::UIHKScreenNISPause(UFG::UIHKScreenNISPause *this)
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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenNISPause::`vftable;
}

// File Line: 36
// RVA: 0x5CB9E0
void __fastcall UFG::UIHKScreenNISPause::~UIHKScreenNISPause(UFG::UIHKScreenNISPause *this)
{
  UFG::UIScreenTextureManager *v2; // rax
  UFG::UIHKScreenGlobalOverlay *v3; // rcx
  UFG::UIScreen *Overlay; // rax
  UFG::UIHKHelpBarWidget *p_HelpBar; // rbx
  unsigned int v6; // eax

  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenNISPause::`vftable;
  v2 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v2, "NISPause");
  UFG::UIScreenManagerBase::queueMessage(UFG::UIScreenManager::s_instance, UI_HASH_NIS_PAUSE_SCREEN_EXIT_20, 0xFFFFFFFF);
  ((void (__fastcall *)(UFG::TiDo *, __int64))UFG::TiDo::m_pInstance->vfptr[1].Close)(UFG::TiDo::m_pInstance, 4i64);
  v3 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( (!UFG::UIHKScreenGlobalOverlay::mThis
     || UFG::UIHKScreenGlobalOverlay::mThis == (UFG::UIHKScreenGlobalOverlay *)-408i64
     || !UFG::UIHKScreenGlobalOverlay::mThis->NISOverlay.mActive)
    && !UFG::UIHKScreenHud::mShouldRender )
  {
    UFG::UIHKScreenHud::mShouldRender = 1;
    Overlay = UFG::UIScreenManagerBase::getOverlay(UFG::UIScreenManager::s_instance, "Hud");
    if ( Overlay )
      Overlay->mRenderable->m_shouldRender = UFG::UIHKScreenHud::mShouldRender;
    v3 = UFG::UIHKScreenGlobalOverlay::mThis;
  }
  if ( !v3 )
    v3 = &gGlobalOverlaySentinel;
  p_HelpBar = &v3->HelpBar;
  v6 = UFG::qStringHash32("NISPause", 0xFFFFFFFF);
  UFG::UIHKHelpBarWidget::Hide(p_HelpBar, v6);
  --UFG::UIHK_NISOverlay::mLock;
  UFG::UIScreen::~UIScreen(this);
}

// File Line: 55
// RVA: 0x632E60
void __fastcall UFG::UIHKScreenNISPause::init(UFG::UIHKScreenNISPause *this, UFG::UICommandData *data)
{
  NISManager *Instance; // rax
  UFG::UI *v4; // rcx
  UFG::UIHKScreenGlobalOverlay *v5; // rdx
  UFG::UIScreen *Overlay; // rax
  UFG::UIHKScreenGlobalOverlay *v7; // rsi
  UFG::UIHKScreenGlobalOverlay *v8; // rax
  Scaleform::GFx::Movie *pObject; // rcx
  UFG::UIHKScreenGlobalOverlay *v10; // rcx
  float CurtainAlpha; // xmm0_4
  UFG::OSuiteDBLogger *v12; // rax
  UFG::UIHKScreenGlobalOverlay *v13; // rax
  UFG::UIHKHelpBarWidget *p_HelpBar; // rbp
  unsigned int v15; // ebx
  UFG::UIHKHelpBarData dataa; // [rsp+30h] [rbp-258h] BYREF

  UFG::UIScreen::init(this, data);
  ++UFG::UIHK_NISOverlay::mLock;
  Instance = NISManager::GetInstance();
  if ( Instance && Instance->mEndCondition )
  {
    UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, 0xFFFFFFFF);
    UFG::UI::UnpauseGame(v4);
  }
  else
  {
    UFG::UIScreenManagerBase::queueMessage(
      UFG::UIScreenManager::s_instance,
      UI_HASH_NIS_PAUSE_SCREEN_INIT_20,
      0xFFFFFFFF);
    ((void (__fastcall *)(UFG::TiDo *, __int64))UFG::TiDo::m_pInstance->vfptr[1].Close)(UFG::TiDo::m_pInstance, 9i64);
    v5 = UFG::UIHKScreenGlobalOverlay::mThis;
    if ( (!UFG::UIHKScreenGlobalOverlay::mThis
       || UFG::UIHKScreenGlobalOverlay::mThis == (UFG::UIHKScreenGlobalOverlay *)-408i64
       || !UFG::UIHKScreenGlobalOverlay::mThis->NISOverlay.mActive)
      && UFG::UIHKScreenHud::mShouldRender )
    {
      UFG::UIHKScreenHud::mShouldRender = 0;
      Overlay = UFG::UIScreenManagerBase::getOverlay(UFG::UIScreenManager::s_instance, "Hud");
      if ( Overlay )
        Overlay->mRenderable->m_shouldRender = UFG::UIHKScreenHud::mShouldRender;
      v5 = UFG::UIHKScreenGlobalOverlay::mThis;
    }
    v7 = &gGlobalOverlaySentinel;
    v8 = &gGlobalOverlaySentinel;
    if ( v5 )
      v8 = v5;
    pObject = v8->mRenderable->m_movie.pObject;
    if ( pObject )
    {
      Scaleform::GFx::Movie::Invoke(pObject, "Race_CountdownFinished", 0i64, 0i64, -2i64);
      v5 = UFG::UIHKScreenGlobalOverlay::mThis;
    }
    v10 = &gGlobalOverlaySentinel;
    if ( v5 )
      v10 = v5;
    CurtainAlpha = UFG::UIHK_NISOverlay::GetCurtainAlpha(v10);
    if ( CurtainAlpha <= 30.0 )
      CurtainAlpha = FLOAT_30_0;
    UFG::UIHKScreenNISPause::Flash_SetCurtainAlpha(this, CurtainAlpha);
    v12 = UFG::OSuiteDBLogger::Instance();
    UFG::OSuiteDBLogger::FlushIfTimeoutHasElapsed(v12);
    v13 = UFG::UIHKScreenGlobalOverlay::mThis;
    if ( !UFG::UIHKScreenGlobalOverlay::mThis )
      v13 = &gGlobalOverlaySentinel;
    p_HelpBar = &v13->HelpBar;
    v15 = UFG::qStringHash32("NISPause", 0xFFFFFFFF);
    UFG::UIHKHelpBarData::UIHKHelpBarData(&dataa);
    dataa.id = v15;
    dataa.priority = PRIORITY_ONE;
    dataa.alignment = ALIGN_RIGHT;
    *(__m128i *)dataa.Buttons = _mm_load_si128((const __m128i *)&_xmm);
    *(_QWORD *)&dataa.Buttons[4] = 0i64;
    UFG::qString::Set(dataa.Captions, "$COMMON_RESUME_UPPERCASE");
    UFG::qString::Set(&dataa.Captions[1], &customCaption);
    UFG::qString::Set(&dataa.Captions[2], &customCaption);
    UFG::qString::Set(&dataa.Captions[3], &customCaption);
    UFG::qString::Set(&dataa.Captions[4], &customCaption);
    UFG::qString::Set(&dataa.Captions[5], &customCaption);
    memset(dataa.MessageIds, 0, sizeof(dataa.MessageIds));
    UFG::UIHKHelpBarWidget::Show(p_HelpBar, &dataa);
    UFG::qString::~qString(&dataa.CustomTexturePack);
    `eh vector destructor iterator(dataa.Icons, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
    `eh vector destructor iterator(dataa.Captions, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
    if ( UFG::UIHKScreenGlobalOverlay::mThis )
      v7 = UFG::UIHKScreenGlobalOverlay::mThis;
    v7->HelpBar.mChanged |= COERCE_FLOAT(COERCE_UNSIGNED_INT(v7->HelpBar.mYOffset - -20.0) & _xmm) > 0.001;
    v7->HelpBar.mYOffset = -20.0;
  }
}

// File Line: 94
// RVA: 0x625CF0
bool __fastcall UFG::UIHKScreenNISPause::handleMessage(
        UFG::UIHKScreenNISPause *this,
        unsigned int msgId,
        UFG::UIMessage *msg)
{
  UFG::UI *v4; // rcx

  if ( msgId != UI_HASH_BUTTON_START_PRESSED_30
    && (!UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController
     || msgId != UI_HASH_BUTTON_ACCEPT_PRESSED_30 && msgId != UI_HASH_MOUSE_BUTTON_LEFT_PRESSED_30)
    && msgId != UI_HASH_SAVE_OPERATION_SKIP_SAVING_9 )
  {
    return UFG::UIScreen::handleMessage(this, msgId, msg);
  }
  UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, 0xFFFFFFFF);
  UFG::UI::UnpauseGame(v4);
  return 1;
}

// File Line: 113
// RVA: 0x63E3B0
void __fastcall UFG::UIHKScreenNISPause::update(UFG::UIHKScreenNISPause *this, float elapsed)
{
  UFG::UIHKScreenGlobalOverlay *v3; // rcx
  float CurtainAlpha; // xmm0_4

  UFG::UIScreen::update(this, elapsed);
  v3 = &gGlobalOverlaySentinel;
  if ( UFG::UIHKScreenGlobalOverlay::mThis )
    v3 = UFG::UIHKScreenGlobalOverlay::mThis;
  CurtainAlpha = UFG::UIHK_NISOverlay::GetCurtainAlpha(v3);
  if ( CurtainAlpha <= 30.0 )
    CurtainAlpha = FLOAT_30_0;
  UFG::UIHKScreenNISPause::Flash_SetCurtainAlpha(this, CurtainAlpha);
}

// File Line: 138
// RVA: 0x5DFEA0
void __fastcall UFG::UIHKScreenNISPause::Flash_SetCurtainAlpha(UFG::UIHKScreenNISPause *this, float alpha)
{
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-50h] BYREF

  pObject = this->mRenderable->m_movie.pObject;
  value.pObjectInterface = 0i64;
  value.Type = VT_Number;
  value.mValue.NValue = alpha;
  Scaleform::GFx::Movie::SetVariable(pObject, "mc_curtain._alpha", &value, 1i64);
  if ( (value.Type & 0x40) != 0 )
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
      value.pObjectInterface,
      &value,
      value.mValue);
}

