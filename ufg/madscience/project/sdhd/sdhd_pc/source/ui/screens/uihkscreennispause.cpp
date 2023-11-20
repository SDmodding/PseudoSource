// File Line: 31
// RVA: 0x5C62C0
void __fastcall UFG::UIHKScreenNISPause::UIHKScreenNISPause(UFG::UIHKScreenNISPause *this)
{
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v1; // rax

  v1 = (UFG::qNode<UFG::UIScreen,UFG::UIScreen> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenNISPause::`vftable;
}

// File Line: 36
// RVA: 0x5CB9E0
void __fastcall UFG::UIHKScreenNISPause::~UIHKScreenNISPause(UFG::UIHKScreenNISPause *this)
{
  UFG::UIHKScreenNISPause *v1; // rdi
  UFG::UIScreenTextureManager *v2; // rax
  UFG::UIHKScreenGlobalOverlay *v3; // rcx
  UFG::UIScreen *v4; // rax
  UFG::UIHKHelpBarWidget *v5; // rbx
  unsigned int v6; // eax

  v1 = this;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenNISPause::`vftable;
  v2 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v2, "NISPause");
  UFG::UIScreenManagerBase::queueMessage(
    (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
    UI_HASH_NIS_PAUSE_SCREEN_EXIT_20,
    0xFFFFFFFF);
  ((void (__fastcall *)(UFG::TiDo *, signed __int64))UFG::TiDo::m_pInstance->vfptr[1].Close)(
    UFG::TiDo::m_pInstance,
    4i64);
  v3 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( (!UFG::UIHKScreenGlobalOverlay::mThis
     || UFG::UIHKScreenGlobalOverlay::mThis == (UFG::UIHKScreenGlobalOverlay *)-408i64
     || !UFG::UIHKScreenGlobalOverlay::mThis->NISOverlay.mActive)
    && UFG::UIHKScreenHud::mShouldRender != 1 )
  {
    UFG::UIHKScreenHud::mShouldRender = 1;
    v4 = UFG::UIScreenManagerBase::getOverlay(
           (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
           "Hud");
    if ( v4 )
      v4->mRenderable->m_shouldRender = UFG::UIHKScreenHud::mShouldRender;
    v3 = UFG::UIHKScreenGlobalOverlay::mThis;
  }
  if ( !v3 )
    v3 = &gGlobalOverlaySentinel;
  v5 = &v3->HelpBar;
  v6 = UFG::qStringHash32("NISPause", 0xFFFFFFFF);
  UFG::UIHKHelpBarWidget::Hide(v5, v6);
  --UFG::UIHK_NISOverlay::mLock;
  UFG::UIScreen::~UIScreen((UFG::UIScreen *)&v1->vfptr);
}

// File Line: 55
// RVA: 0x632E60
void __fastcall UFG::UIHKScreenNISPause::init(UFG::UIHKScreenNISPause *this, UFG::UICommandData *data)
{
  UFG::UIHKScreenNISPause *v2; // rbx
  NISManager *v3; // rax
  UFG::UI *v4; // rcx
  UFG::UIHKScreenGlobalOverlay *v5; // rdx
  UFG::UIScreen *v6; // rax
  UFG::UIHKScreenGlobalOverlay *v7; // rsi
  UFG::UIHKScreenGlobalOverlay *v8; // rax
  Scaleform::GFx::Movie *v9; // rcx
  UFG::UIHKScreenGlobalOverlay *v10; // rcx
  float v11; // xmm0_4
  UFG::OSuiteDBLogger *v12; // rax
  UFG::UIHKScreenGlobalOverlay *v13; // rax
  UFG::UIHKHelpBarWidget *v14; // rbp
  unsigned int v15; // ebx
  signed __int64 v16; // rdi
  UFG::UIHKHelpBarData dataa; // [rsp+30h] [rbp-258h]

  v2 = this;
  UFG::UIScreen::init((UFG::UIScreen *)&this->vfptr, data);
  ++UFG::UIHK_NISOverlay::mLock;
  v3 = NISManager::GetInstance();
  if ( v3 && v3->mEndCondition )
  {
    UFG::UIScreenManagerBase::queuePopScreen(
      (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
      0xFFFFFFFF);
    UFG::UI::UnpauseGame(v4);
  }
  else
  {
    UFG::UIScreenManagerBase::queueMessage(
      (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
      UI_HASH_NIS_PAUSE_SCREEN_INIT_20,
      0xFFFFFFFF);
    ((void (__fastcall *)(UFG::TiDo *, signed __int64))UFG::TiDo::m_pInstance->vfptr[1].Close)(
      UFG::TiDo::m_pInstance,
      9i64);
    v5 = UFG::UIHKScreenGlobalOverlay::mThis;
    if ( (!UFG::UIHKScreenGlobalOverlay::mThis
       || UFG::UIHKScreenGlobalOverlay::mThis == (UFG::UIHKScreenGlobalOverlay *)-408i64
       || !UFG::UIHKScreenGlobalOverlay::mThis->NISOverlay.mActive)
      && UFG::UIHKScreenHud::mShouldRender )
    {
      UFG::UIHKScreenHud::mShouldRender = 0;
      v6 = UFG::UIScreenManagerBase::getOverlay(
             (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
             "Hud");
      if ( v6 )
        v6->mRenderable->m_shouldRender = UFG::UIHKScreenHud::mShouldRender;
      v5 = UFG::UIHKScreenGlobalOverlay::mThis;
    }
    v7 = &gGlobalOverlaySentinel;
    v8 = &gGlobalOverlaySentinel;
    if ( v5 )
      v8 = v5;
    v9 = v8->mRenderable->m_movie.pObject;
    if ( v9 )
    {
      Scaleform::GFx::Movie::Invoke(v9, "Race_CountdownFinished", 0i64, 0i64, -2i64);
      v5 = UFG::UIHKScreenGlobalOverlay::mThis;
    }
    v10 = &gGlobalOverlaySentinel;
    if ( v5 )
      v10 = v5;
    v11 = UFG::UIHK_NISOverlay::GetCurtainAlpha((UFG::UIScreen *)&v10->vfptr);
    if ( v11 <= 30.0 )
      v11 = FLOAT_30_0;
    UFG::UIHKScreenNISPause::Flash_SetCurtainAlpha(v2, v11);
    v12 = UFG::OSuiteDBLogger::Instance();
    UFG::OSuiteDBLogger::FlushIfTimeoutHasElapsed(v12);
    v13 = UFG::UIHKScreenGlobalOverlay::mThis;
    if ( !UFG::UIHKScreenGlobalOverlay::mThis )
      v13 = &gGlobalOverlaySentinel;
    v14 = &v13->HelpBar;
    v15 = UFG::qStringHash32("NISPause", 0xFFFFFFFF);
    UFG::UIHKHelpBarData::UIHKHelpBarData(&dataa);
    dataa.id = v15;
    dataa.priority = 0;
    dataa.alignment = 1;
    _mm_store_si128((__m128i *)dataa.Buttons, _mm_load_si128((const __m128i *)&_xmm));
    *(_QWORD *)&dataa.Buttons[4] = 0i64;
    UFG::qString::Set(dataa.Captions, "$COMMON_RESUME_UPPERCASE");
    UFG::qString::Set(&dataa.Captions[1], &customWorldMapCaption);
    UFG::qString::Set(&dataa.Captions[2], &customWorldMapCaption);
    UFG::qString::Set(&dataa.Captions[3], &customWorldMapCaption);
    UFG::qString::Set(&dataa.Captions[4], &customWorldMapCaption);
    UFG::qString::Set(&dataa.Captions[5], &customWorldMapCaption);
    *(_QWORD *)dataa.MessageIds = 0i64;
    *(_QWORD *)&dataa.MessageIds[2] = 0i64;
    *(_QWORD *)&dataa.MessageIds[4] = 0i64;
    UFG::UIHKHelpBarWidget::Show(v14, &dataa);
    UFG::qString::~qString(&dataa.CustomTexturePack);
    `eh vector destructor iterator(dataa.Icons, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
    `eh vector destructor iterator(dataa.Captions, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
    if ( UFG::UIHKScreenGlobalOverlay::mThis )
      v7 = UFG::UIHKScreenGlobalOverlay::mThis;
    v16 = (signed __int64)&v7->HelpBar;
    *(_BYTE *)(v16 + 1) |= COERCE_FLOAT(COERCE_UNSIGNED_INT(v7->HelpBar.mYOffset - -20.0) & _xmm) > 0.001;
    *(_DWORD *)(v16 + 612) = -1046478848;
  }
}

// File Line: 94
// RVA: 0x625CF0
bool __fastcall UFG::UIHKScreenNISPause::handleMessage(UFG::UIHKScreenNISPause *this, unsigned int msgId, UFG::UIMessage *msg)
{
  UFG::UI *v4; // rcx

  if ( msgId != UI_HASH_BUTTON_START_PRESSED_30
    && (!UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController
     || msgId != UI_HASH_BUTTON_ACCEPT_PRESSED_30 && msgId != UI_HASH_MOUSE_BUTTON_LEFT_PRESSED_30)
    && msgId != UI_HASH_SAVE_OPERATION_SKIP_SAVING_9 )
  {
    return UFG::UIScreen::handleMessage((UFG::UIScreen *)&this->vfptr, msgId, msg);
  }
  UFG::UIScreenManagerBase::queuePopScreen(
    (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
    0xFFFFFFFF);
  UFG::UI::UnpauseGame(v4);
  return 1;
}

// File Line: 113
// RVA: 0x63E3B0
void __fastcall UFG::UIHKScreenNISPause::update(UFG::UIHKScreenNISPause *this, float elapsed)
{
  UFG::UIHKScreenNISPause *v2; // rbx
  UFG::UIHKScreenGlobalOverlay *v3; // rcx
  float v4; // xmm0_4

  v2 = this;
  UFG::UIScreen::update((UFG::UIScreen *)&this->vfptr, elapsed);
  v3 = &gGlobalOverlaySentinel;
  if ( UFG::UIHKScreenGlobalOverlay::mThis )
    v3 = UFG::UIHKScreenGlobalOverlay::mThis;
  v4 = UFG::UIHK_NISOverlay::GetCurtainAlpha((UFG::UIScreen *)&v3->vfptr);
  if ( v4 <= 30.0 )
    v4 = FLOAT_30_0;
  UFG::UIHKScreenNISPause::Flash_SetCurtainAlpha(v2, v4);
}

// File Line: 138
// RVA: 0x5DFEA0
void __fastcall UFG::UIHKScreenNISPause::Flash_SetCurtainAlpha(UFG::UIHKScreenNISPause *this, float alpha)
{
  Scaleform::GFx::Movie *v2; // rbx
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-50h]

  v2 = this->mRenderable->m_movie.pObject;
  value.pObjectInterface = 0i64;
  value.Type = 5;
  value.mValue.NValue = alpha;
  Scaleform::GFx::Movie::SetVariable(v2, "mc_curtain._alpha", &value, 1i64);
  if ( ((unsigned int)value.Type >> 6) & 1 )
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
      value.pObjectInterface,
      &value,
      *(_QWORD *)&value.mValue.NValue);
}

