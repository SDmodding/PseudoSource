// File Line: 30
// RVA: 0x156E1A0
__int64 UFG::_dynamic_initializer_for__mute_nis__()
{
  mute_nis.mUID = UFG::qWiseSymbolUIDFromString("mute_nis", 0x811C9DC5);
  _((AMD_HD3D *)mute_nis.mUID);
  return atexit(UFG::_dynamic_atexit_destructor_for__mute_nis__);
}

// File Line: 31
// RVA: 0x15728B0
__int64 UFG::_dynamic_initializer_for__unmute_nis__()
{
  unmute_nis.mUID = UFG::qWiseSymbolUIDFromString("unmute_nis", 0x811C9DC5);
  _((AMD_HD3D *)unmute_nis.mUID);
  return atexit(UFG::_dynamic_atexit_destructor_for__unmute_nis__);
}

// File Line: 33
// RVA: 0x1567530
__int64 dynamic_initializer_for__UFG::UIHK_NISOverlay::m_curtains__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::UIHK_NISOverlay::m_curtains__);
}

// File Line: 54
// RVA: 0x5CDB10
void __fastcall UFG::UIHK_NISOverlay::~UIHK_NISOverlay(UFG::UIHK_NISOverlay *this)
{
  this->vfptr = (UFG::UIHK_NISOverlayVtbl *)&UFG::UIHK_NISOverlay::`vftable;
  UFG::UIHK_NISOverlay::mLetterBoxActive = 0;
  UFG::UIHK_NISOverlay::m_curtains.m_state = 0;
  UFG::UIHK_NISOverlay::m_curtains.m_mutingAudio = 0;
  UFG::qString::~qString(&this->FrameCounter.mCaption);
}

// File Line: 65
// RVA: 0x640F90
void __fastcall UFG::UIHK_NISOverlay::update(UFG::UIHK_NISOverlay *this, UFG::UIScreen *screen, float elapsed)
{
  UFG::UIScreen *v3; // rdi
  UFG::UIHK_NISOverlay *v4; // rbx
  float v5; // xmm0_4
  UFG::UIScreen *v6; // rax

  if ( screen )
  {
    v3 = screen;
    v4 = this;
    UFG::UIHK_NISOverlay::Flash_ForceHide(this, screen, UFG::UIHK_NISOverlay::mLock > 0);
    if ( v4->mSkipButtonPromptShowing )
    {
      v5 = elapsed + v4->mSkipButtonTimer;
      v4->mSkipButtonTimer = v5;
      if ( v5 > 2.0 )
        v4->mShouldHideSkipButtonPrompt = 1;
    }
    if ( v4->mShouldHideSkipButtonPrompt )
    {
      v4->mShouldHideSkipButtonPrompt = 0;
      UFG::UIHK_NISOverlay::Flash_SetSkipButtonPromptVisible(v4, v3, 0);
    }
    if ( UFG::UIHK_NISOverlay::m_curtains.m_state && UFG::UIHKScreenHud::mShouldRender )
    {
      UFG::UIHKScreenHud::mShouldRender = 0;
      v6 = UFG::UIScreenManagerBase::getOverlay(
             (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
             "Hud");
      if ( v6 )
        v6->mRenderable->m_shouldRender = UFG::UIHKScreenHud::mShouldRender;
    }
    UFG::UIHK_NISFrameCounterWidget::Update(&v4->FrameCounter, v3, elapsed);
    UFG::UIHK_NISOverlay::UpdateAudioMuteState();
  }
}

// File Line: 106
// RVA: 0x62E9E0
char __fastcall UFG::UIHK_NISOverlay::handleMessage(UFG::UIHK_NISOverlay *this, UFG::UIScreen *screen, unsigned int msgId, UFG::UIMessage *msg)
{
  UFG::UIMessage *v4; // rbp
  unsigned int v5; // ebx
  UFG::UIScreen *v6; // rsi
  UFG::UIHK_NISOverlay *v7; // rdi
  NISManager *v9; // rax
  NISManager *v10; // rax

  v4 = msg;
  v5 = msgId;
  v6 = screen;
  v7 = this;
  if ( msgId == UI_HASH_TWEEN_COMPLETE_30
    && !(unsigned int)UFG::qStringCompare((const char *)msg[1].m_commandData, "mc_curtain", -1)
    && !(v4[1].m_messageType & 0xFFFFFFFB) )
  {
    if ( UFG::UIHK_NISOverlay::m_curtains.m_state == 1 )
    {
      UFG::UIHK_NISOverlay::ShowElement(
        v7,
        v6,
        &UFG::UIHK_NISOverlay::m_curtains,
        -1.0,
        UFG::UIHK_NISOverlay::m_curtains.m_mutingAudio);
    }
    else
    {
      if ( UFG::UIHK_NISOverlay::m_curtains.m_state != 3 )
        goto LABEL_9;
      UFG::UIHK_NISOverlay::HideElement(v7, v6, &UFG::UIHK_NISOverlay::m_curtains, -1.0, 0);
    }
    UFG::UIScreenManagerBase::queueMessage(
      (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
      UI_HASH_SCREEN_FADE_IN_COMPLETE_12,
      0xFFFFFFFF);
  }
LABEL_9:
  if ( NISManager::GetInstance()->mState != 4 )
    goto LABEL_30;
  if ( v4->m_commandType == 6 )
    UFG::UIInputHandler::getControllerIndex(HIDWORD(v4[1].vfptr));
  if ( UFG::UIHK_NISOverlay::m_curtains.m_state )
    goto LABEL_34;
  if ( v5 == UI_HASH_BUTTON_START_PRESSED_30 )
  {
    UFG::UIHK_NISOverlay::Flash_SetSkipButtonPromptVisible(v7, v6, 0);
    UFG::UI::TryNISPause();
    return 1;
  }
  if ( (unsigned __int8)UFG::UI::IsGamePaused()
    || UFG::UIScreenManagerBase::getScreen(
         (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
         "NISPause")
    || v5 != UI_HASH_BUTTON_ACCEPT_PRESSED_30
    && v5 != UI_HASH_MOUSE_BUTTON_LEFT_PRESSED_30
    && v5 != UI_HASH_BUTTON_BACK_PRESSED_30
    && v5 != UI_HASH_BUTTON_BUTTON1_PRESSED_30
    && v5 != (_DWORD)UI_HASH_BUTTON_BUTTON2_PRESSED_30 )
  {
LABEL_34:
    if ( v5 != UI_HASH_NIS_PAUSE_SCREEN_INIT_20 )
      return 0;
LABEL_30:
    UFG::UIHK_NISOverlay::Flash_SetSkipButtonPromptVisible(v7, v6, 0);
    return 0;
  }
  v9 = NISManager::GetInstance();
  if ( NISManager::CanSkipNow(v9) )
  {
    if ( v7->mSkipButtonPromptShowing
      && (v5 == UI_HASH_BUTTON_ACCEPT_PRESSED_30 || v5 == UI_HASH_MOUSE_BUTTON_LEFT_PRESSED_30) )
    {
      v10 = NISManager::GetInstance();
      NISManager::RequestSkip(v10);
      return 1;
    }
    UFG::UIHK_NISOverlay::Flash_SetSkipButtonPromptVisible(v7, v6, 1);
  }
  return 1;
}

// File Line: 202
// RVA: 0x620880
UFG::UIHK_NISOverlay *__fastcall UFG::UIHK_NISOverlay::getInstance()
{
  UFG::UIHK_NISOverlay *result; // rax

  result = (UFG::UIHK_NISOverlay *)UFG::UIHKScreenGlobalOverlay::mThis;
  if ( UFG::UIHKScreenGlobalOverlay::mThis )
    result = &UFG::UIHKScreenGlobalOverlay::mThis->NISOverlay;
  return result;
}

// File Line: 213
// RVA: 0x60D410
void __fastcall UFG::UIHK_NISOverlay::ShowElement(UFG::UIHK_NISOverlay *this, UFG::UIScreen *screen, UFG::UIHK_NISElement *element, float fadeInTime, bool muteAudio)
{
  UFG::UIHK_NISElement *v5; // rsi
  UFG::UIScreen *v6; // r14
  UFG::UIHK_NISOverlay *v7; // r15
  UFG::UITween *v8; // rdi
  char v9; // bl
  Scaleform::GFx::Movie *v10; // rdx
  UFG::UIHK_NISElement::eState v11; // er9
  UFG::allocator::free_link *v12; // rbp
  UFG::UITween *v13; // rax
  UFG::qNode<UFG::UITween,UFG::UITween> *v14; // rcx
  UFG::qNode<UFG::UITween,UFG::UITween> *v15; // rax
  UFG::allocator::free_link *v16; // rbp
  UFG::UITween *v17; // rax
  UFG::qNode<UFG::UITween,UFG::UITween> *v18; // rcx
  UFG::qNode<UFG::UITween,UFG::UITween> *v19; // rax
  UFG::qString path; // [rsp+40h] [rbp-68h]

  v5 = element;
  v6 = screen;
  v7 = this;
  v8 = 0i64;
  v9 = 0;
  v10 = screen->mRenderable->m_movie.pObject;
  if ( v10 )
  {
    v11 = element->m_state;
    if ( element->m_state != 2 )
    {
      element->m_mutingAudio = muteAudio;
      if ( fadeInTime > 0.0 )
      {
        if ( v11 != 1 )
        {
          UFG::UIScreenManagerBase::killTweens(
            (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
            v10);
          v16 = UFG::qMalloc(0x3E0ui64, UFG::gGlobalNewName, 0i64);
          if ( v16 )
          {
            UFG::qString::qString(&path, "mc_curtain");
            v9 = 2;
            UFG::UITween::UITween((UFG::UITween *)v16, v6->mRenderable->m_movie.pObject, &path, fadeInTime, 0);
            v8 = v17;
          }
          if ( v9 & 2 )
            UFG::qString::~qString(&path);
          UFG::UITween::SetRange(v8, ALPHA, 0.0, 100.0);
          v18 = &UFG::UIScreenManager::s_instance->m_activeTweens.mNode;
          v19 = UFG::UIScreenManager::s_instance->m_activeTweens.mNode.mPrev;
          v19->mNext = (UFG::qNode<UFG::UITween,UFG::UITween> *)&v8->mPrev;
          v8->mPrev = v19;
          v8->mNext = v18;
          v18->mPrev = (UFG::qNode<UFG::UITween,UFG::UITween> *)&v8->mPrev;
          v5->m_state = 1;
        }
      }
      else
      {
        UFG::UIScreenManagerBase::killTweens((UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr, v10);
        v12 = UFG::qMalloc(0x3E0ui64, UFG::gGlobalNewName, 0i64);
        if ( v12 )
        {
          UFG::qString::qString(&path, "mc_curtain");
          v9 = 1;
          UFG::UITween::UITween((UFG::UITween *)v12, v6->mRenderable->m_movie.pObject, &path, 0.0, 0);
          v8 = v13;
        }
        if ( v9 & 1 )
          UFG::qString::~qString(&path);
        UFG::UITween::SetRange(v8, ALPHA, 0.0, 100.0);
        v14 = &UFG::UIScreenManager::s_instance->m_activeTweens.mNode;
        v15 = UFG::UIScreenManager::s_instance->m_activeTweens.mNode.mPrev;
        v15->mNext = (UFG::qNode<UFG::UITween,UFG::UITween> *)&v8->mPrev;
        v8->mPrev = v15;
        v8->mNext = v14;
        v14->mPrev = (UFG::qNode<UFG::UITween,UFG::UITween> *)&v8->mPrev;
        v5->m_state = 2;
        if ( UFG::UIHK_NISOverlay::sCurtainsShownCallback )
        {
          UFG::UIHK_NISOverlay::sCurtainsShownCallback();
          if ( fadeInTime == -1.0 )
          {
            UFG::LoadingLogic::SetForceLoadScreenOn(&UFG::gLoadingLogic);
            UFG::LoadingLogic::SetAllowLoadScreen(&UFG::gLoadingLogic, 0);
          }
        }
      }
      UFG::UIHK_NISOverlay::SetActive(v7, 1);
    }
  }
}

// File Line: 272
// RVA: 0x5ECCE0
void __fastcall UFG::UIHK_NISOverlay::HideElement(UFG::UIHK_NISOverlay *this, UFG::UIScreen *screen, UFG::UIHK_NISElement *element, float fadeOutTime, bool bUseNonLinearFade)
{
  UFG::UIHK_NISElement *v5; // rsi
  UFG::UIScreen *v6; // r14
  UFG::UIHK_NISOverlay *v7; // r15
  UFG::UITween *v8; // rdi
  char v9; // bl
  Scaleform::GFx::Movie *v10; // rdx
  UFG::allocator::free_link *v11; // rbp
  UFG::UITween *v12; // rax
  UFG::UITween *v13; // r14
  UFG::qNode<UFG::UITween,UFG::UITween> *v14; // rcx
  UFG::qNode<UFG::UITween,UFG::UITween> *v15; // rax
  UFG::allocator::free_link *v16; // rbp
  UFG::UITween *v17; // rax
  UFG::qNode<UFG::UITween,UFG::UITween> *v18; // rcx
  UFG::qNode<UFG::UITween,UFG::UITween> *v19; // rax
  UFG::qString path; // [rsp+40h] [rbp-68h]

  v5 = element;
  v6 = screen;
  v7 = this;
  v8 = 0i64;
  v9 = 0;
  v10 = screen->mRenderable->m_movie.pObject;
  if ( v10 && element->m_state )
  {
    if ( fadeOutTime > 0.0 )
    {
      if ( element->m_state != 3 )
      {
        UFG::UIScreenManagerBase::killTweens((UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr, v10);
        v16 = UFG::qMalloc(0x3E0ui64, UFG::gGlobalNewName, 0i64);
        if ( v16 )
        {
          UFG::qString::qString(&path, "mc_curtain");
          v9 = 2;
          UFG::UITween::UITween(
            (UFG::UITween *)v16,
            v6->mRenderable->m_movie.pObject,
            &path,
            fadeOutTime,
            (UFG::UITween::eTweenType)(bUseNonLinearFade != 0 ? 4 : 0));
          v8 = v17;
        }
        if ( v9 & 2 )
          UFG::qString::~qString(&path);
        UFG::UITween::SetRange(v8, ALPHA, 100.0, 0.0);
        v18 = &UFG::UIScreenManager::s_instance->m_activeTweens.mNode;
        v19 = UFG::UIScreenManager::s_instance->m_activeTweens.mNode.mPrev;
        v19->mNext = (UFG::qNode<UFG::UITween,UFG::UITween> *)&v8->mPrev;
        v8->mPrev = v19;
        v8->mNext = v18;
        v18->mPrev = (UFG::qNode<UFG::UITween,UFG::UITween> *)&v8->mPrev;
        v5->m_state = 3;
        v5->m_mutingAudio = 0;
        UFG::UIHK_NISOverlay::UpdateAudioMuteState();
        UFG::UIHK_NISOverlay::FirePostNISAudioEventQueue();
      }
    }
    else
    {
      UFG::UIScreenManagerBase::killTweens((UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr, v10);
      v11 = UFG::qMalloc(0x3E0ui64, UFG::gGlobalNewName, 0i64);
      if ( v11 )
      {
        UFG::qString::qString(&path, "mc_curtain");
        v9 = 1;
        UFG::UITween::UITween((UFG::UITween *)v11, v6->mRenderable->m_movie.pObject, &path, 0.0, 0);
        v13 = v12;
      }
      else
      {
        v13 = 0i64;
      }
      if ( v9 & 1 )
        UFG::qString::~qString(&path);
      UFG::UITween::SetRange(v13, ALPHA, 100.0, 0.0);
      v14 = &UFG::UIScreenManager::s_instance->m_activeTweens.mNode;
      v15 = UFG::UIScreenManager::s_instance->m_activeTweens.mNode.mPrev;
      v15->mNext = (UFG::qNode<UFG::UITween,UFG::UITween> *)&v13->mPrev;
      v13->mPrev = v15;
      v13->mNext = v14;
      v14->mPrev = (UFG::qNode<UFG::UITween,UFG::UITween> *)&v13->mPrev;
      v5->m_state = 0;
      v5->m_mutingAudio = 0;
      if ( UFG::UIHKScreenGlobalOverlay::mThis )
      {
        v5->m_state = 0;
        UFG::UIHK_NISOverlay::FirePostNISAudioEventQueue();
      }
      if ( !UFG::UIHK_NISOverlay::mLetterBoxActive && UFG::UIHK_NISOverlay::m_curtains.m_state == STATE_CURTAIN_HIDDEN )
        UFG::UIHK_NISOverlay::SetActive(v7, 0);
      v5->m_mutingAudio = 0;
    }
    if ( UFG::UIHK_NISOverlay::sCurtainsHiddenCallback )
      UFG::UIHK_NISOverlay::sCurtainsHiddenCallback();
  }
}

// File Line: 346
// RVA: 0x605840
void __fastcall UFG::UIHK_NISOverlay::SetCurtainStateCallbacks(void (__fastcall *showCallback)(), void (__fastcall *hideCallback)())
{
  UFG::UIHK_NISOverlay::sCurtainsShownCallback = showCallback;
  UFG::UIHK_NISOverlay::sCurtainsHiddenCallback = hideCallback;
}

// File Line: 353
// RVA: 0x610B70
void UFG::UIHK_NISOverlay::ShowLetterBox(void)
{
  if ( UFG::UIHKScreenGlobalOverlay::mThis )
  {
    if ( UFG::UIHKScreenGlobalOverlay::mThis != (UFG::UIHKScreenGlobalOverlay *)-408i64 )
    {
      UFG::UIHK_NISOverlay::mLetterBoxActive = 1;
      UFG::UIHK_NISOverlay::SetActive(&UFG::UIHKScreenGlobalOverlay::mThis->NISOverlay, 1);
    }
  }
}

// File Line: 364
// RVA: 0x5ED0B0
void UFG::UIHK_NISOverlay::HideLetterBox(void)
{
  if ( UFG::UIHKScreenGlobalOverlay::mThis
    && UFG::UIHKScreenGlobalOverlay::mThis != (UFG::UIHKScreenGlobalOverlay *)-408i64 )
  {
    UFG::UIHK_NISOverlay::mLetterBoxActive = 0;
    if ( UFG::UIHK_NISOverlay::m_curtains.m_state == STATE_CURTAIN_HIDDEN )
      UFG::UIHK_NISOverlay::SetActive(&UFG::UIHKScreenGlobalOverlay::mThis->NISOverlay, 0);
  }
}

// File Line: 379
// RVA: 0x60D3C0
void __fastcall UFG::UIHK_NISOverlay::ShowCurtains(float fadeInTime, bool bMuteAudio)
{
  bool v2; // bl

  v2 = bMuteAudio;
  if ( UFG::UIHKScreenGlobalOverlay::mThis
    && UFG::UIHKScreenGlobalOverlay::mThis != (UFG::UIHKScreenGlobalOverlay *)-408i64 )
  {
    UFG::UIHK_NISOverlay::ShowElement(
      &UFG::UIHKScreenGlobalOverlay::mThis->NISOverlay,
      (UFG::UIScreen *)&UFG::UIHKScreenGlobalOverlay::mThis->vfptr,
      &UFG::UIHK_NISOverlay::m_curtains,
      fadeInTime,
      bMuteAudio);
    UFG::UIHK_NISOverlay::m_curtains.m_mutingAudio = v2;
  }
  UFG::UIHK_NISOverlay::UpdateAudioMuteState();
}

// File Line: 391
// RVA: 0x5ECCA0
void __fastcall UFG::UIHK_NISOverlay::HideCurtains(float fadeOutTime, bool bUseNonLinearFade)
{
  if ( UFG::UIHKScreenGlobalOverlay::mThis
    && UFG::UIHKScreenGlobalOverlay::mThis != (UFG::UIHKScreenGlobalOverlay *)-408i64 )
  {
    UFG::UIHK_NISOverlay::HideElement(
      &UFG::UIHKScreenGlobalOverlay::mThis->NISOverlay,
      (UFG::UIScreen *)&UFG::UIHKScreenGlobalOverlay::mThis->vfptr,
      &UFG::UIHK_NISOverlay::m_curtains,
      fadeOutTime,
      bUseNonLinearFade);
  }
  UFG::UIHK_NISOverlay::UpdateAudioMuteState();
}

// File Line: 402
// RVA: 0x606F10
void __fastcall UFG::UIHK_NISOverlay::SetPostNISHideCurtainsAudioEvent(unsigned int event, bool waitForNextCurtain)
{
  unsigned int v2; // er8
  bool v3; // bl
  unsigned int v4; // edi
  bool v5; // zf

  v2 = UFG::UIHK_NISOverlay::m_current_audio_event_index;
  v3 = waitForNextCurtain;
  v4 = event;
  if ( UFG::UIHK_NISOverlay::m_current_audio_event_index == 7 )
  {
    UFG::UIHK_NISOverlay::FirePostNISAudioEventQueue();
    v2 = UFG::UIHK_NISOverlay::m_current_audio_event_index;
  }
  v5 = UFG::UIHK_NISOverlay::m_curtains.m_state == 2;
  UFG::UIHK_NISOverlay::m_current_audio_event_index = v2 + 1;
  UFG::UIHK_NISOverlay::m_post_nis_hide_curtain_audio_events[v2] = v4;
  if ( !v5 && !v3 )
    UFG::UIHK_NISOverlay::FirePostNISAudioEventQueue();
}

// File Line: 434
// RVA: 0x5D8A50
void UFG::UIHK_NISOverlay::FirePostNISAudioEventQueue(void)
{
  unsigned int v0; // ebx
  UFG::NISAudio *v1; // rcx
  unsigned int v2; // edx

  if ( UFG::UIHK_NISOverlay::m_current_audio_event_index )
  {
    v0 = 0;
    if ( UFG::UIHK_NISOverlay::m_current_audio_event_index )
    {
      do
      {
        v1 = UFG::NISAudio::m_instance;
        v2 = UFG::UIHK_NISOverlay::m_post_nis_hide_curtain_audio_events[v0];
        UFG::UIHK_NISOverlay::m_post_nis_hide_curtain_audio_events[v0] = 0;
        UFG::NISAudio::PlayNISCurtainEvent(v1, v2);
        ++v0;
      }
      while ( v0 < UFG::UIHK_NISOverlay::m_current_audio_event_index );
    }
    UFG::UIHK_NISOverlay::m_current_audio_event_index = 0;
  }
}

// File Line: 452
// RVA: 0x5EE130
bool __fastcall UFG::UIHK_NISOverlay::IsCurtainStable()
{
  return (UFG::UIHK_NISOverlay::m_curtains.m_state & 0xFFFFFFFD) == 0;
}

// File Line: 463
// RVA: 0x5EE140
bool __fastcall UFG::UIHK_NISOverlay::IsCurtainVisible()
{
  return UFG::UIHK_NISOverlay::m_curtains.m_state == 2;
}

// File Line: 469
// RVA: 0x5EE120
bool __fastcall UFG::UIHK_NISOverlay::IsCurtainHidden()
{
  return UFG::UIHK_NISOverlay::m_curtains.m_state == 0;
}

// File Line: 475
// RVA: 0x5E72C0
float __fastcall UFG::UIHK_NISOverlay::GetCurtainAlpha(UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *v1; // rcx
  float v2; // xmm6_4
  Scaleform::GFx::Value pval; // [rsp+28h] [rbp-50h]

  v1 = screen->mRenderable->m_movie.pObject;
  pval.pObjectInterface = 0i64;
  pval.Type = 0;
  Scaleform::GFx::Movie::GetVariable(v1, &pval, "mc_curtain._alpha");
  v2 = pval.mValue.NValue;
  if ( ((unsigned int)pval.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pval.pObjectInterface->vfptr->gap8[8])(
      pval.pObjectInterface,
      &pval,
      *(_QWORD *)&pval.mValue.NValue);
    pval.pObjectInterface = 0i64;
  }
  return v2;
}

// File Line: 518
// RVA: 0x6124D0
void UFG::UIHK_NISOverlay::StopAllSubtitles(void)
{
  UFG::UIHKTextOverlay *v0; // rbx
  UFG::UISubtitleMessage *v1; // rdx
  UFG::UIHKTextOverlay *v2; // rcx
  UFG::UISubtitleMessage *v3; // rdx
  UFG::UIHKTextOverlay *v4; // rcx

  if ( UFG::UIHKScreenGlobalOverlay::mThis )
  {
    v0 = &UFG::UIHKScreenGlobalOverlay::mThis->TextOverlay;
    if ( UFG::UIHKScreenGlobalOverlay::mThis != (UFG::UIHKScreenGlobalOverlay *)-144i64 )
    {
      UFG::qList<UFG::UISubtitleMessage,UFG::UISubtitleMessage,1,0>::DeleteNodes(&UFG::UIHKScreenGlobalOverlay::mThis->TextOverlay.mSubtitleQueue.mQueue);
      v1 = v0->mSubtitleQueue.mCurrent1;
      if ( v1 )
      {
        if ( v1->state <= 1u )
        {
          v1->state = 2;
          v2 = v0->mSubtitleQueue.mParent;
          if ( v2 )
            UFG::UIHKTextOverlay::OnStartFadeOut(v2, v1, 1);
        }
      }
      v3 = v0->mSubtitleQueue.mCurrent2;
      if ( v3 && v3->state <= 1u )
      {
        v3->state = 2;
        v4 = v0->mSubtitleQueue.mParent;
        if ( v4 )
          UFG::UIHKTextOverlay::OnStartFadeOut(v4, v3, 2);
      }
    }
  }
}

// File Line: 528
// RVA: 0x6050E0
void __fastcall UFG::UIHK_NISOverlay::SetActive(UFG::UIHK_NISOverlay *this, bool active)
{
  bool v2; // al
  UFG::UIHK_NISOverlay *v3; // rbx
  UFG::UIScreen *v4; // rax
  bool v5; // zf
  UFG::UIScreen *v6; // rax
  UFG::UIHK_PDAWidget *v7; // rdi

  v2 = this->mActive;
  v3 = this;
  if ( v2 != active )
  {
    if ( v2 )
    {
      if ( UFG::UIHKScreenHud::mShouldRender != 1 )
      {
        UFG::UIHKScreenHud::mShouldRender = 1;
        v4 = UFG::UIScreenManagerBase::getOverlay(
               (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
               "Hud");
        if ( v4 )
          v4->mRenderable->m_shouldRender = UFG::UIHKScreenHud::mShouldRender;
      }
      UFG::UIHKObjectiveFlasherWidget::mVisible = 1;
      if ( UFG::UIHK_PDAWidget::mLocked )
        --UFG::UIHK_PDAWidget::mLocked;
      v3->mShouldHideSkipButtonPrompt = 1;
      v5 = v3->FrameCounter.mVisible == 0;
      v3->FrameCounter.mVisible = 0;
      v3->FrameCounter.mChanged |= !v5;
      v3->mActive = v3->mActive == 0;
    }
    else
    {
      if ( UFG::UIHKScreenHud::mShouldRender )
      {
        UFG::UIHKScreenHud::mShouldRender = 0;
        v6 = UFG::UIScreenManagerBase::getOverlay(
               (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
               "Hud");
        if ( v6 )
          v6->mRenderable->m_shouldRender = UFG::UIHKScreenHud::mShouldRender;
      }
      if ( UFG::UIHKScreenGlobalOverlay::mThis
        && UFG::UIHKScreenGlobalOverlay::mThis != (UFG::UIHKScreenGlobalOverlay *)-144i64 )
      {
        UFG::UIHKTextOverlay::HideMissionObjectives(&UFG::UIHKScreenGlobalOverlay::mThis->TextOverlay);
      }
      UFG::UIHKObjectiveFlasherWidget::mVisible = 0;
      UFG::UIHK_NISOverlay::StopAllSubtitles();
      if ( UFG::UIHKScreenHud::mInstance )
      {
        v7 = UFG::UIHKScreenHud::mInstance->PDA;
        if ( v7 )
        {
          UFG::UIHK_PDAWidget::ForceIdle(v7);
          v7->mState = 0;
          UFG::UIHKObjectiveFlasherWidget::mPDAStateChanged = 1;
        }
      }
      ++UFG::UIHK_PDAWidget::mLocked;
      v3->mActive = v3->mActive == 0;
    }
  }
}

// File Line: 555
// RVA: 0x61A060
void UFG::UIHK_NISOverlay::UpdateAudioMuteState(void)
{
  UFG::qWiseSymbol result; // [rsp+50h] [rbp+8h]

  if ( UFG::UIHK_NISOverlay::m_audiomuted
    || UFG::UIHK_NISOverlay::m_curtains.m_mutingAudio
    && (UFG::UIHK_NISOverlay::m_audiomuted = 1,
        UFG::qWiseSymbol::create_from_string(&result, "mute_nis"),
        UFG::AudioEntity::CreateAndPlayEvent(
          (UFG::AudioEntity *)&UFG::AmbienceAudio::m_instance->vfptr,
          result.mUID,
          0i64,
          0,
          0i64),
        _((AMD_HD3D *)result.mUID),
        UFG::UIHK_NISOverlay::m_audiomuted) )
  {
    if ( !UFG::UIHK_NISOverlay::m_curtains.m_mutingAudio )
    {
      UFG::qWiseSymbol::create_from_string(&result, "unmute_nis");
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::AmbienceAudio::m_instance->vfptr,
        result.mUID,
        0i64,
        0,
        0i64);
      UFG::UIHK_NISOverlay::m_audiomuted = 0;
      _((AMD_HD3D *)result.mUID);
    }
  }
}

// File Line: 580
// RVA: 0x5DAA00
void __fastcall UFG::UIHK_NISOverlay::Flash_ForceHide(UFG::UIHK_NISOverlay *this, UFG::UIScreen *screen, bool hide)
{
  Scaleform::GFx::Movie *v3; // rdi
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-40h]

  if ( hide != isHidden )
  {
    isHidden = hide;
    v3 = screen->mRenderable->m_movie.pObject;
    value.pObjectInterface = 0i64;
    value.Type = 2;
    value.mValue.BValue = hide == 0;
    Scaleform::GFx::Movie::SetVariable(v3, "mc_curtain._visible", &value, 1i64);
    if ( ((unsigned int)value.Type >> 6) & 1 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        *(_QWORD *)&value.mValue.NValue);
  }
}

// File Line: 594
// RVA: 0x5E0C40
void __fastcall UFG::UIHK_NISOverlay::Flash_SetSkipButtonPromptVisible(UFG::UIHK_NISOverlay *this, UFG::UIScreen *screen, bool visible)
{
  Scaleform::GFx::Movie *v3; // rdi
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h]

  if ( this->mSkipButtonPromptShowing != visible )
  {
    this->mSkipButtonPromptShowing = visible;
    this->mSkipButtonTimer = 0.0;
    v3 = screen->mRenderable->m_movie.pObject;
    pargs.pObjectInterface = 0i64;
    pargs.Type = 2;
    pargs.mValue.BValue = visible;
    Scaleform::GFx::Movie::Invoke(v3, "NIS_SetSkipButtonPromptVisible", 0i64, &pargs, 1u);
    if ( ((unsigned int)pargs.Type >> 6) & 1 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        *(_QWORD *)&pargs.mValue.NValue);
  }
}

