// File Line: 30
// RVA: 0x156E1A0
__int64 UFG::_dynamic_initializer_for__mute_nis__()
{
  mute_nis.mUID = UFG::qWiseSymbolUIDFromString("mute_nis", 0x811C9DC5);
  _((AMD_HD3D *)mute_nis.mUID);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__mute_nis__);
}

// File Line: 31
// RVA: 0x15728B0
__int64 UFG::_dynamic_initializer_for__unmute_nis__()
{
  unmute_nis.mUID = UFG::qWiseSymbolUIDFromString("unmute_nis", 0x811C9DC5);
  _((AMD_HD3D *)unmute_nis.mUID);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__unmute_nis__);
}

// File Line: 33
// RVA: 0x1567530
__int64 dynamic_initializer_for__UFG::UIHK_NISOverlay::m_curtains__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::UIHK_NISOverlay::m_curtains__);
}

// File Line: 54
// RVA: 0x5CDB10
void __fastcall UFG::UIHK_NISOverlay::~UIHK_NISOverlay(UFG::UIHK_NISOverlay *this)
{
  this->vfptr = (UFG::UIHK_NISOverlayVtbl *)&UFG::UIHK_NISOverlay::`vftable;
  UFG::UIHK_NISOverlay::mLetterBoxActive = 0;
  UFG::UIHK_NISOverlay::m_curtains.m_state = STATE_CURTAIN_HIDDEN;
  UFG::UIHK_NISOverlay::m_curtains.m_mutingAudio = 0;
  UFG::qString::~qString(&this->FrameCounter.mCaption);
}

// File Line: 65
// RVA: 0x640F90
void __fastcall UFG::UIHK_NISOverlay::update(UFG::UIHK_NISOverlay *this, UFG::UIScreen *screen, float elapsed)
{
  float v5; // xmm0_4
  UFG::UIScreen *Overlay; // rax

  if ( screen )
  {
    UFG::UIHK_NISOverlay::Flash_ForceHide(this, screen, UFG::UIHK_NISOverlay::mLock > 0);
    if ( this->mSkipButtonPromptShowing )
    {
      v5 = elapsed + this->mSkipButtonTimer;
      this->mSkipButtonTimer = v5;
      if ( v5 > 2.0 )
        this->mShouldHideSkipButtonPrompt = 1;
    }
    if ( this->mShouldHideSkipButtonPrompt )
    {
      this->mShouldHideSkipButtonPrompt = 0;
      UFG::UIHK_NISOverlay::Flash_SetSkipButtonPromptVisible(this, screen, 0);
    }
    if ( UFG::UIHK_NISOverlay::m_curtains.m_state && UFG::UIHKScreenHud::mShouldRender )
    {
      UFG::UIHKScreenHud::mShouldRender = 0;
      Overlay = UFG::UIScreenManagerBase::getOverlay(UFG::UIScreenManager::s_instance, "Hud");
      if ( Overlay )
        Overlay->mRenderable->m_shouldRender = UFG::UIHKScreenHud::mShouldRender;
    }
    UFG::UIHK_NISFrameCounterWidget::Update(&this->FrameCounter, screen, elapsed);
    UFG::UIHK_NISOverlay::UpdateAudioMuteState();
  }
}

// File Line: 106
// RVA: 0x62E9E0
char __fastcall UFG::UIHK_NISOverlay::handleMessage(
        UFG::UIHK_NISOverlay *this,
        UFG::UIScreen *screen,
        unsigned int msgId,
        UFG::UIMessage *msg)
{
  NISManager *Instance; // rax
  NISManager *v10; // rax

  if ( msgId == UI_HASH_TWEEN_COMPLETE_30
    && !(unsigned int)UFG::qStringCompare((const char *)msg[1].m_commandData, "mc_curtain", -1)
    && (msg[1].m_messageType & 0xFFFFFFFB) == 0 )
  {
    if ( UFG::UIHK_NISOverlay::m_curtains.m_state == STATE_CURTAIN_FADINGTOBLACK )
    {
      UFG::UIHK_NISOverlay::ShowElement(
        this,
        screen,
        &UFG::UIHK_NISOverlay::m_curtains,
        -1.0,
        UFG::UIHK_NISOverlay::m_curtains.m_mutingAudio);
    }
    else
    {
      if ( UFG::UIHK_NISOverlay::m_curtains.m_state != STATE_CURTAIN_FADINGFROMBLACK )
        goto LABEL_9;
      UFG::UIHK_NISOverlay::HideElement(this, screen, &UFG::UIHK_NISOverlay::m_curtains, -1.0, 0);
    }
    UFG::UIScreenManagerBase::queueMessage(
      UFG::UIScreenManager::s_instance,
      UI_HASH_SCREEN_FADE_IN_COMPLETE_12,
      0xFFFFFFFF);
  }
LABEL_9:
  if ( NISManager::GetInstance()->mState != STATE_INCOMPLETE )
    goto LABEL_30;
  if ( msg->m_commandType == UICOMMAND_INPUT )
    UFG::UIInputHandler::getControllerIndex(SHIDWORD(msg[1].vfptr));
  if ( UFG::UIHK_NISOverlay::m_curtains.m_state )
    goto LABEL_29;
  if ( msgId == UI_HASH_BUTTON_START_PRESSED_30 )
  {
    UFG::UIHK_NISOverlay::Flash_SetSkipButtonPromptVisible(this, screen, 0);
    UFG::UI::TryNISPause();
    return 1;
  }
  if ( (unsigned __int8)UFG::UI::IsGamePaused()
    || UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "NISPause")
    || msgId != UI_HASH_BUTTON_ACCEPT_PRESSED_30
    && msgId != UI_HASH_MOUSE_BUTTON_LEFT_PRESSED_30
    && msgId != UI_HASH_BUTTON_BACK_PRESSED_30
    && msgId != UI_HASH_BUTTON_BUTTON1_PRESSED_30
    && msgId != (_DWORD)UI_HASH_BUTTON_BUTTON2_PRESSED_30 )
  {
LABEL_29:
    if ( msgId != UI_HASH_NIS_PAUSE_SCREEN_INIT_20 )
      return 0;
LABEL_30:
    UFG::UIHK_NISOverlay::Flash_SetSkipButtonPromptVisible(this, screen, 0);
    return 0;
  }
  Instance = NISManager::GetInstance();
  if ( NISManager::CanSkipNow(Instance) )
  {
    if ( this->mSkipButtonPromptShowing
      && (msgId == UI_HASH_BUTTON_ACCEPT_PRESSED_30 || msgId == UI_HASH_MOUSE_BUTTON_LEFT_PRESSED_30) )
    {
      v10 = NISManager::GetInstance();
      NISManager::RequestSkip(v10);
      return 1;
    }
    UFG::UIHK_NISOverlay::Flash_SetSkipButtonPromptVisible(this, screen, 1);
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
    return &UFG::UIHKScreenGlobalOverlay::mThis->NISOverlay;
  return result;
}

// File Line: 213
// RVA: 0x60D410
void __fastcall UFG::UIHK_NISOverlay::ShowElement(
        UFG::UIHK_NISOverlay *this,
        UFG::UIScreen *screen,
        UFG::UIHK_NISElement *element,
        float fadeInTime,
        bool muteAudio)
{
  UFG::UITween *v8; // rdi
  char v9; // bl
  Scaleform::GFx::Movie *pObject; // rdx
  UFG::UIHK_NISElement::eState m_state; // r9d
  UFG::allocator::free_link *v12; // rbp
  UFG::UITween *v13; // rax
  UFG::qList<UFG::UITween,UFG::UITween,1,0> *v14; // rcx
  UFG::qNode<UFG::UITween,UFG::UITween> *v15; // rax
  UFG::allocator::free_link *v16; // rbp
  UFG::UITween *v17; // rax
  UFG::qList<UFG::UITween,UFG::UITween,1,0> *p_m_activeTweens; // rcx
  UFG::qNode<UFG::UITween,UFG::UITween> *mPrev; // rax
  UFG::qString path; // [rsp+40h] [rbp-68h] BYREF

  v8 = 0i64;
  v9 = 0;
  pObject = screen->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    m_state = element->m_state;
    if ( element->m_state != STATE_CURTAIN_SHOWING )
    {
      element->m_mutingAudio = muteAudio;
      if ( fadeInTime > 0.0 )
      {
        if ( m_state != STATE_CURTAIN_FADINGTOBLACK )
        {
          UFG::UIScreenManagerBase::killTweens(UFG::UIScreenManager::s_instance, pObject);
          v16 = UFG::qMalloc(0x3E0ui64, UFG::gGlobalNewName, 0i64);
          if ( v16 )
          {
            UFG::qString::qString(&path, "mc_curtain");
            v9 = 2;
            UFG::UITween::UITween(
              (UFG::UITween *)v16,
              screen->mRenderable->m_movie.pObject,
              &path,
              fadeInTime,
              TWEEN_LINEAR);
            v8 = v17;
          }
          if ( (v9 & 2) != 0 )
            UFG::qString::~qString(&path);
          UFG::UITween::SetRange(v8, ALPHA, 0.0, 100.0);
          p_m_activeTweens = &UFG::UIScreenManager::s_instance->m_activeTweens;
          mPrev = UFG::UIScreenManager::s_instance->m_activeTweens.mNode.mPrev;
          mPrev->mNext = v8;
          v8->mPrev = mPrev;
          v8->mNext = &p_m_activeTweens->mNode;
          p_m_activeTweens->mNode.mPrev = v8;
          element->m_state = STATE_CURTAIN_FADINGTOBLACK;
        }
      }
      else
      {
        UFG::UIScreenManagerBase::killTweens(UFG::UIScreenManager::s_instance, pObject);
        v12 = UFG::qMalloc(0x3E0ui64, UFG::gGlobalNewName, 0i64);
        if ( v12 )
        {
          UFG::qString::qString(&path, "mc_curtain");
          v9 = 1;
          UFG::UITween::UITween((UFG::UITween *)v12, screen->mRenderable->m_movie.pObject, &path, 0.0, TWEEN_LINEAR);
          v8 = v13;
        }
        if ( (v9 & 1) != 0 )
          UFG::qString::~qString(&path);
        UFG::UITween::SetRange(v8, ALPHA, 0.0, 100.0);
        v14 = &UFG::UIScreenManager::s_instance->m_activeTweens;
        v15 = UFG::UIScreenManager::s_instance->m_activeTweens.mNode.mPrev;
        v15->mNext = v8;
        v8->mPrev = v15;
        v8->mNext = &v14->mNode;
        v14->mNode.mPrev = v8;
        element->m_state = STATE_CURTAIN_SHOWING;
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
      UFG::UIHK_NISOverlay::SetActive(this, 1);
    }
  }
}

// File Line: 272
// RVA: 0x5ECCE0
void __fastcall UFG::UIHK_NISOverlay::HideElement(
        UFG::UIHK_NISOverlay *this,
        UFG::UIScreen *screen,
        UFG::UIHK_NISElement *element,
        float fadeOutTime,
        bool bUseNonLinearFade)
{
  UFG::UITween *v8; // rdi
  char v9; // bl
  Scaleform::GFx::Movie *pObject; // rdx
  UFG::allocator::free_link *v11; // rbp
  UFG::UITween *v12; // rax
  UFG::UITween *v13; // r14
  UFG::qList<UFG::UITween,UFG::UITween,1,0> *v14; // rcx
  UFG::qNode<UFG::UITween,UFG::UITween> *v15; // rax
  UFG::allocator::free_link *v16; // rbp
  UFG::UITween *v17; // rax
  UFG::qList<UFG::UITween,UFG::UITween,1,0> *p_m_activeTweens; // rcx
  UFG::qNode<UFG::UITween,UFG::UITween> *mPrev; // rax
  UFG::qString path; // [rsp+40h] [rbp-68h] BYREF

  v8 = 0i64;
  v9 = 0;
  pObject = screen->mRenderable->m_movie.pObject;
  if ( pObject && element->m_state )
  {
    if ( fadeOutTime > 0.0 )
    {
      if ( element->m_state != STATE_CURTAIN_FADINGFROMBLACK )
      {
        UFG::UIScreenManagerBase::killTweens(UFG::UIScreenManager::s_instance, pObject);
        v16 = UFG::qMalloc(0x3E0ui64, UFG::gGlobalNewName, 0i64);
        if ( v16 )
        {
          UFG::qString::qString(&path, "mc_curtain");
          v9 = 2;
          UFG::UITween::UITween(
            (UFG::UITween *)v16,
            screen->mRenderable->m_movie.pObject,
            &path,
            fadeOutTime,
            bUseNonLinearFade ? TWEEN_QUAD_IN : TWEEN_LINEAR);
          v8 = v17;
        }
        if ( (v9 & 2) != 0 )
          UFG::qString::~qString(&path);
        UFG::UITween::SetRange(v8, ALPHA, 100.0, 0.0);
        p_m_activeTweens = &UFG::UIScreenManager::s_instance->m_activeTweens;
        mPrev = UFG::UIScreenManager::s_instance->m_activeTweens.mNode.mPrev;
        mPrev->mNext = v8;
        v8->mPrev = mPrev;
        v8->mNext = &p_m_activeTweens->mNode;
        p_m_activeTweens->mNode.mPrev = v8;
        element->m_state = STATE_CURTAIN_FADINGFROMBLACK;
        element->m_mutingAudio = 0;
        UFG::UIHK_NISOverlay::UpdateAudioMuteState();
        UFG::UIHK_NISOverlay::FirePostNISAudioEventQueue();
      }
    }
    else
    {
      UFG::UIScreenManagerBase::killTweens(UFG::UIScreenManager::s_instance, pObject);
      v11 = UFG::qMalloc(0x3E0ui64, UFG::gGlobalNewName, 0i64);
      if ( v11 )
      {
        UFG::qString::qString(&path, "mc_curtain");
        v9 = 1;
        UFG::UITween::UITween((UFG::UITween *)v11, screen->mRenderable->m_movie.pObject, &path, 0.0, TWEEN_LINEAR);
        v13 = v12;
      }
      else
      {
        v13 = 0i64;
      }
      if ( (v9 & 1) != 0 )
        UFG::qString::~qString(&path);
      UFG::UITween::SetRange(v13, ALPHA, 100.0, 0.0);
      v14 = &UFG::UIScreenManager::s_instance->m_activeTweens;
      v15 = UFG::UIScreenManager::s_instance->m_activeTweens.mNode.mPrev;
      v15->mNext = v13;
      v13->mPrev = v15;
      v13->mNext = &v14->mNode;
      v14->mNode.mPrev = v13;
      element->m_state = STATE_CURTAIN_HIDDEN;
      element->m_mutingAudio = 0;
      if ( UFG::UIHKScreenGlobalOverlay::mThis )
      {
        element->m_state = STATE_CURTAIN_HIDDEN;
        UFG::UIHK_NISOverlay::FirePostNISAudioEventQueue();
      }
      if ( !UFG::UIHK_NISOverlay::mLetterBoxActive && UFG::UIHK_NISOverlay::m_curtains.m_state == STATE_CURTAIN_HIDDEN )
        UFG::UIHK_NISOverlay::SetActive(this, 0);
      element->m_mutingAudio = 0;
    }
    if ( UFG::UIHK_NISOverlay::sCurtainsHiddenCallback )
      UFG::UIHK_NISOverlay::sCurtainsHiddenCallback();
  }
}

// File Line: 346
// RVA: 0x605840
void __fastcall UFG::UIHK_NISOverlay::SetCurtainStateCallbacks(
        void (__fastcall *showCallback)(),
        void (__fastcall *hideCallback)())
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
  if ( UFG::UIHKScreenGlobalOverlay::mThis
    && UFG::UIHKScreenGlobalOverlay::mThis != (UFG::UIHKScreenGlobalOverlay *)-408i64 )
  {
    UFG::UIHK_NISOverlay::ShowElement(
      &UFG::UIHKScreenGlobalOverlay::mThis->NISOverlay,
      UFG::UIHKScreenGlobalOverlay::mThis,
      &UFG::UIHK_NISOverlay::m_curtains,
      fadeInTime,
      bMuteAudio);
    UFG::UIHK_NISOverlay::m_curtains.m_mutingAudio = bMuteAudio;
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
      UFG::UIHKScreenGlobalOverlay::mThis,
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
  unsigned int v2; // r8d
  bool v5; // zf

  v2 = UFG::UIHK_NISOverlay::m_current_audio_event_index;
  if ( UFG::UIHK_NISOverlay::m_current_audio_event_index == 7 )
  {
    UFG::UIHK_NISOverlay::FirePostNISAudioEventQueue();
    v2 = UFG::UIHK_NISOverlay::m_current_audio_event_index;
  }
  v5 = UFG::UIHK_NISOverlay::m_curtains.m_state == STATE_CURTAIN_SHOWING;
  UFG::UIHK_NISOverlay::m_current_audio_event_index = v2 + 1;
  UFG::UIHK_NISOverlay::m_post_nis_hide_curtain_audio_events[v2] = event;
  if ( !v5 && !waitForNextCurtain )
    UFG::UIHK_NISOverlay::FirePostNISAudioEventQueue();
}

// File Line: 434
// RVA: 0x5D8A50
void UFG::UIHK_NISOverlay::FirePostNISAudioEventQueue(void)
{
  unsigned int i; // ebx
  UFG::NISAudio *v1; // rcx
  unsigned int v2; // edx

  if ( UFG::UIHK_NISOverlay::m_current_audio_event_index )
  {
    for ( i = 0; i < UFG::UIHK_NISOverlay::m_current_audio_event_index; ++i )
    {
      v1 = UFG::NISAudio::m_instance;
      v2 = UFG::UIHK_NISOverlay::m_post_nis_hide_curtain_audio_events[i];
      UFG::UIHK_NISOverlay::m_post_nis_hide_curtain_audio_events[i] = 0;
      UFG::NISAudio::PlayNISCurtainEvent(v1, v2);
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
  return UFG::UIHK_NISOverlay::m_curtains.m_state == STATE_CURTAIN_SHOWING;
}

// File Line: 469
// RVA: 0x5EE120
bool __fastcall UFG::UIHK_NISOverlay::IsCurtainHidden()
{
  return UFG::UIHK_NISOverlay::m_curtains.m_state == STATE_CURTAIN_HIDDEN;
}

// File Line: 475
// RVA: 0x5E72C0
float __fastcall UFG::UIHK_NISOverlay::GetCurtainAlpha(UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *pObject; // rcx
  float NValue; // xmm6_4
  Scaleform::GFx::Value pval; // [rsp+28h] [rbp-50h] BYREF

  pObject = screen->mRenderable->m_movie.pObject;
  pval.pObjectInterface = 0i64;
  pval.Type = VT_Undefined;
  Scaleform::GFx::Movie::GetVariable(pObject, &pval, "mc_curtain._alpha");
  NValue = pval.mValue.NValue;
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

// File Line: 518
// RVA: 0x6124D0
void UFG::UIHK_NISOverlay::StopAllSubtitles(void)
{
  UFG::UIHKTextOverlay *p_TextOverlay; // rbx
  UFG::UISubtitleMessage *mCurrent1; // rdx
  UFG::UIHKTextOverlay *mParent; // rcx
  UFG::UISubtitleMessage *mCurrent2; // rdx
  UFG::UIHKTextOverlay *v4; // rcx

  if ( UFG::UIHKScreenGlobalOverlay::mThis )
  {
    p_TextOverlay = &UFG::UIHKScreenGlobalOverlay::mThis->TextOverlay;
    if ( UFG::UIHKScreenGlobalOverlay::mThis != (UFG::UIHKScreenGlobalOverlay *)-144i64 )
    {
      UFG::qList<UFG::UISubtitleMessage,UFG::UISubtitleMessage,1,0>::DeleteNodes(&UFG::UIHKScreenGlobalOverlay::mThis->TextOverlay.mSubtitleQueue.mQueue);
      mCurrent1 = p_TextOverlay->mSubtitleQueue.mCurrent1;
      if ( mCurrent1 )
      {
        if ( mCurrent1->state <= (unsigned int)STATE_QUEUED )
        {
          mCurrent1->state = STATE_WAITING;
          mParent = p_TextOverlay->mSubtitleQueue.mParent;
          if ( mParent )
            UFG::UIHKTextOverlay::OnStartFadeOut(mParent, mCurrent1, 1);
        }
      }
      mCurrent2 = p_TextOverlay->mSubtitleQueue.mCurrent2;
      if ( mCurrent2 && mCurrent2->state <= (unsigned int)STATE_QUEUED )
      {
        mCurrent2->state = STATE_WAITING;
        v4 = p_TextOverlay->mSubtitleQueue.mParent;
        if ( v4 )
          UFG::UIHKTextOverlay::OnStartFadeOut(v4, mCurrent2, 2);
      }
    }
  }
}

// File Line: 528
// RVA: 0x6050E0
void __fastcall UFG::UIHK_NISOverlay::SetActive(UFG::UIHK_NISOverlay *this, bool active)
{
  bool mActive; // al
  UFG::UIScreen *Overlay; // rax
  bool v5; // zf
  UFG::UIScreen *v6; // rax
  UFG::UIHK_PDAWidget *PDA; // rdi

  mActive = this->mActive;
  if ( mActive != active )
  {
    if ( mActive )
    {
      if ( !UFG::UIHKScreenHud::mShouldRender )
      {
        UFG::UIHKScreenHud::mShouldRender = 1;
        Overlay = UFG::UIScreenManagerBase::getOverlay(UFG::UIScreenManager::s_instance, "Hud");
        if ( Overlay )
          Overlay->mRenderable->m_shouldRender = UFG::UIHKScreenHud::mShouldRender;
      }
      UFG::UIHKObjectiveFlasherWidget::mVisible = 1;
      if ( UFG::UIHK_PDAWidget::mLocked )
        --UFG::UIHK_PDAWidget::mLocked;
      this->mShouldHideSkipButtonPrompt = 1;
      v5 = !this->FrameCounter.mVisible;
      this->FrameCounter.mVisible = 0;
      this->FrameCounter.mChanged |= !v5;
      this->mActive = !this->mActive;
    }
    else
    {
      if ( UFG::UIHKScreenHud::mShouldRender )
      {
        UFG::UIHKScreenHud::mShouldRender = 0;
        v6 = UFG::UIScreenManagerBase::getOverlay(UFG::UIScreenManager::s_instance, "Hud");
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
        PDA = UFG::UIHKScreenHud::mInstance->PDA;
        if ( PDA )
        {
          UFG::UIHK_PDAWidget::ForceIdle(PDA);
          PDA->mState = STATE_IDLE;
          UFG::UIHKObjectiveFlasherWidget::mPDAStateChanged = 1;
        }
      }
      ++UFG::UIHK_PDAWidget::mLocked;
      this->mActive = !this->mActive;
    }
  }
}

// File Line: 555
// RVA: 0x61A060
void UFG::UIHK_NISOverlay::UpdateAudioMuteState(void)
{
  UFG::qWiseSymbol result; // [rsp+50h] [rbp+8h] BYREF

  if ( UFG::UIHK_NISOverlay::m_audiomuted
    || UFG::UIHK_NISOverlay::m_curtains.m_mutingAudio
    && (UFG::UIHK_NISOverlay::m_audiomuted = 1,
        UFG::qWiseSymbol::create_from_string(&result, "mute_nis"),
        UFG::AudioEntity::CreateAndPlayEvent(UFG::AmbienceAudio::m_instance, result.mUID, 0i64, 0, 0i64),
        _((AMD_HD3D *)result.mUID),
        UFG::UIHK_NISOverlay::m_audiomuted) )
  {
    if ( !UFG::UIHK_NISOverlay::m_curtains.m_mutingAudio )
    {
      UFG::qWiseSymbol::create_from_string(&result, "unmute_nis");
      UFG::AudioEntity::CreateAndPlayEvent(UFG::AmbienceAudio::m_instance, result.mUID, 0i64, 0, 0i64);
      UFG::UIHK_NISOverlay::m_audiomuted = 0;
      _((AMD_HD3D *)result.mUID);
    }
  }
}

// File Line: 580
// RVA: 0x5DAA00
void __fastcall UFG::UIHK_NISOverlay::Flash_ForceHide(UFG::UIHK_NISOverlay *this, UFG::UIScreen *screen, bool hide)
{
  Scaleform::GFx::Movie *pObject; // rdi
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-40h] BYREF

  if ( hide != isHidden )
  {
    isHidden = hide;
    pObject = screen->mRenderable->m_movie.pObject;
    value.pObjectInterface = 0i64;
    value.Type = VT_Boolean;
    value.mValue.BValue = !hide;
    Scaleform::GFx::Movie::SetVariable(pObject, "mc_curtain._visible", &value, 1i64);
    if ( (value.Type & 0x40) != 0 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        value.mValue);
  }
}

// File Line: 594
// RVA: 0x5E0C40
void __fastcall UFG::UIHK_NISOverlay::Flash_SetSkipButtonPromptVisible(
        UFG::UIHK_NISOverlay *this,
        UFG::UIScreen *screen,
        bool visible)
{
  Scaleform::GFx::Movie *pObject; // rdi
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h] BYREF

  if ( this->mSkipButtonPromptShowing != visible )
  {
    this->mSkipButtonPromptShowing = visible;
    this->mSkipButtonTimer = 0.0;
    pObject = screen->mRenderable->m_movie.pObject;
    pargs.pObjectInterface = 0i64;
    pargs.Type = VT_Boolean;
    pargs.mValue.BValue = visible;
    Scaleform::GFx::Movie::Invoke(pObject, "NIS_SetSkipButtonPromptVisible", 0i64, &pargs, 1u);
    if ( (pargs.Type & 0x40) != 0 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        pargs.mValue);
  }
}

