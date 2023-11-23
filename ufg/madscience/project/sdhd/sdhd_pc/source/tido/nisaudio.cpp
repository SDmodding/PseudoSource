// File Line: 41
// RVA: 0x596FE0
// attributes: thunk
void __fastcall UFG::NISAudio::AudioEntityUpdate(UFG::NISAudio *this, float delta_sec)
{
  UFG::AudioEntity::AudioEntityUpdate(this, delta_sec);
}

// File Line: 46
// RVA: 0x5A6A30
void __fastcall UFG::NISAudio::PlayNISCurtainEvent(UFG::NISAudio *this, unsigned int eventId)
{
  UFG::AudioEntity::CreateAndPlayEvent(UFG::AmbienceAudio::m_instance, eventId, 0i64, 0, 0i64);
}

// File Line: 55
// RVA: 0x5A4CB0
void __fastcall UFG::NISAudio::Play(UFG::NISAudio *this, unsigned int eventId, UFG::AudioEventInitParams *params)
{
  UFG::AudioEventController *p_m_controller; // rdi
  UFG::AudioEventCallbackObject *mFreeListHead; // rbx
  unsigned int v5; // eax

  if ( UFG::NISAudio::m_instance )
  {
    p_m_controller = &this->m_controller;
    UFG::AudioEntity::CreateEventA(this, eventId, &this->m_controller, params, 0i64);
    if ( p_m_controller->m_pEvent )
    {
      mFreeListHead = (UFG::AudioEventCallbackObject *)UFG::gAudioEventCallbackObjectPool.mFreeListHead;
      if ( UFG::gAudioEventCallbackObjectPool.mFreeListHead )
      {
        UFG::gAudioEventCallbackObjectPool.mFreeListHead = *(char **)UFG::gAudioEventCallbackObjectPool.mFreeListHead;
        v5 = UFG::gAudioEventCallbackObjectPool.mNumSlotsAllocated + 1;
        UFG::gAudioEventCallbackObjectPool.mNumSlotsAllocated = v5;
        if ( UFG::gAudioEventCallbackObjectPool.mMostSlotsAllocated <= v5 )
          UFG::gAudioEventCallbackObjectPool.mMostSlotsAllocated = v5;
      }
      else
      {
        UFG::qFixedAllocator::ReportFull(&UFG::gAudioEventCallbackObjectPool);
      }
      if ( mFreeListHead )
      {
        mFreeListHead->vfptr = (UFG::AudioEventCallbackObjectVtbl *)&UFG::AudioEventCallbackObject::`vftable;
        mFreeListHead->m_next = 0i64;
        mFreeListHead->vfptr = (UFG::AudioEventCallbackObjectVtbl *)&UFG::NISCallback::`vftable;
      }
      else
      {
        mFreeListHead = 0i64;
      }
      if ( p_m_controller->m_pEvent )
        UFG::AudioEvent::AddCallback(p_m_controller->m_pEvent, mFreeListHead);
      if ( p_m_controller->m_pEvent && !p_m_controller->m_pEvent->vfptr->Play(p_m_controller->m_pEvent, 0) )
      {
        *((_BYTE *)p_m_controller->m_pEvent + 144) |= 4u;
        if ( p_m_controller->m_pEvent )
          p_m_controller->m_pEvent->m_pController = 0i64;
        p_m_controller->m_pEvent = 0i64;
      }
    }
  }
}

// File Line: 75
// RVA: 0x59B1E0
void __fastcall UFG::NISCallback::Do(
        UFG::NISCallback *this,
        UFG::AudioEvent *audioEvent,
        UFG::eAudioEventCallbackType type)
{
  UFG::UIHKTextOverlay *Instance; // rax
  UFG::UIHKTextOverlay *v6; // rax
  UFG::UIHKTextOverlay *v7; // rax

  if ( type == eAudioEventCallbackType_Marker )
  {
    Instance = UFG::UIHKTextOverlay::getInstance();
    if ( UFG::UIHKTextOverlay::GetSubtitleAge(Instance, subtitle1[1]) >= 3.0 )
    {
      v7 = UFG::UIHKTextOverlay::getInstance();
      UFG::UIHKTextOverlay::KillSubtitles(v7, subtitle1[1]);
    }
    else
    {
      v6 = UFG::UIHKTextOverlay::getInstance();
      UFG::UIHKTextOverlay::ChangeSubtitleLifetime(v6, subtitle1[1], 2.0);
    }
    *(_QWORD *)subtitle1 = 0i64;
    UFG::NISCallback::HandleSubtitleStart(this, subtitle1, audioEvent->m_markerCallbackInfo.m_labelHash);
  }
  else if ( type == eAudioEventCallbackType_End && subtitle1[0] == audioEvent->m_markerCallbackInfo.m_labelHash )
  {
    UFG::NISCallback::HandleSubtitleEnd(this, subtitle1);
  }
}

// File Line: 105
// RVA: 0x59F450
void __fastcall UFG::NISCallback::HandleSubtitleStart(
        UFG::NISCallback *this,
        unsigned int *subtitle,
        unsigned int labelHash)
{
  UFG::allocator::free_link *v5; // rax
  unsigned int v6; // ebx
  __int64 v7; // rax
  __int64 v8; // rbp
  UFG::UIHKTextOverlay *Instance; // rax

  if ( labelHash != 1471824835
    && (UFG::SubtitleManager::sm_subtitleMode == eSubtitleMode_On
     || UFG::SubtitleManager::sm_subtitleMode == eSubtitleMode_Cantonese
     && UFG::SubtitleManager::LabelIsCantonese(labelHash)) )
  {
    v5 = UFG::qMalloc(0xD0ui64, "UISubtitleMessage", 0i64);
    v6 = 0;
    if ( v5 )
    {
      UFG::UISubtitleMessage::UISubtitleMessage((UFG::UISubtitleMessage *)v5, TYPE_SUBTITLE_TEXT, labelHash, 0i64);
      v8 = v7;
    }
    else
    {
      v8 = 0i64;
    }
    *(_DWORD *)(v8 + 24) = 1097859072;
    Instance = UFG::UIHKTextOverlay::getInstance();
    if ( Instance )
      v6 = UFG::UIHKTextOverlay::QueueMessage(Instance, (UFG::UISubtitleMessage *)v8);
    if ( !*subtitle )
    {
      if ( v6 )
      {
        *subtitle = labelHash;
        subtitle[1] = v6;
      }
    }
  }
}

// File Line: 142
// RVA: 0x59F390
void __fastcall UFG::NISCallback::HandleSubtitleEnd(UFG::NISCallback *this, unsigned int *subtitle)
{
  UFG::UIHKTextOverlay *Instance; // rax
  UFG::UIHKTextOverlay *v4; // rax
  UFG::UIHKTextOverlay *v5; // rax

  Instance = UFG::UIHKTextOverlay::getInstance();
  if ( UFG::UIHKTextOverlay::GetSubtitleAge(Instance, subtitle[1]) >= 3.0 )
  {
    v5 = UFG::UIHKTextOverlay::getInstance();
    UFG::UIHKTextOverlay::KillSubtitles(v5, subtitle[1]);
  }
  else
  {
    v4 = UFG::UIHKTextOverlay::getInstance();
    UFG::UIHKTextOverlay::ChangeSubtitleLifetime(v4, subtitle[1], 2.0);
  }
  *(_QWORD *)subtitle = 0i64;
}

