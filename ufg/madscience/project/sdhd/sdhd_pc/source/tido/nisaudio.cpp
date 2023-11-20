// File Line: 41
// RVA: 0x596FE0
void __fastcall UFG::NISAudio::AudioEntityUpdate(UFG::NISAudio *this, float delta_sec)
{
  UFG::AudioEntity::AudioEntityUpdate((UFG::AudioEntity *)&this->vfptr, delta_sec);
}

// File Line: 46
// RVA: 0x5A6A30
void __fastcall UFG::NISAudio::PlayNISCurtainEvent(UFG::NISAudio *this, unsigned int eventId)
{
  UFG::AudioEntity::CreateAndPlayEvent(
    (UFG::AudioEntity *)&UFG::AmbienceAudio::m_instance->vfptr,
    eventId,
    0i64,
    0,
    0i64);
}

// File Line: 55
// RVA: 0x5A4CB0
void __fastcall UFG::NISAudio::Play(UFG::NISAudio *this, unsigned int eventId, UFG::AudioEventInitParams *params)
{
  UFG::AudioEvent **v3; // rdi
  UFG::AudioEventCallbackObject *v4; // rbx
  unsigned int v5; // eax

  if ( UFG::NISAudio::m_instance )
  {
    v3 = &this->m_controller.m_pEvent;
    UFG::AudioEntity::CreateEventA((UFG::AudioEntity *)&this->vfptr, eventId, &this->m_controller, params, 0i64);
    if ( *v3 )
    {
      v4 = (UFG::AudioEventCallbackObject *)UFG::gAudioEventCallbackObjectPool.mFreeListHead;
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
      if ( v4 )
      {
        v4->vfptr = (UFG::AudioEventCallbackObjectVtbl *)&UFG::AudioEventCallbackObject::`vftable';
        v4->m_next = 0i64;
        v4->vfptr = (UFG::AudioEventCallbackObjectVtbl *)&UFG::NISCallback::`vftable';
      }
      else
      {
        v4 = 0i64;
      }
      if ( *v3 )
        UFG::AudioEvent::AddCallback(*v3, v4);
      if ( *v3 && !(*v3)->vfptr->Play(*v3, 0) )
      {
        *((_BYTE *)*v3 + 144) |= 4u;
        if ( *v3 )
          (*v3)->m_pController = 0i64;
        *v3 = 0i64;
      }
    }
  }
}

// File Line: 75
// RVA: 0x59B1E0
void __fastcall UFG::NISCallback::Do(UFG::NISCallback *this, UFG::AudioEvent *audioEvent, UFG::eAudioEventCallbackType type)
{
  UFG::AudioEvent *v3; // rbx
  UFG::NISCallback *v4; // rdi
  UFG::UIHKTextOverlay *v5; // rax
  UFG::UIHKTextOverlay *v6; // rax
  UFG::UIHKTextOverlay *v7; // rax

  v3 = audioEvent;
  v4 = this;
  if ( type == 3 )
  {
    v5 = UFG::UIHKTextOverlay::getInstance();
    if ( UFG::UIHKTextOverlay::GetSubtitleAge(v5, subtitle1[1]) >= 3.0 )
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
    UFG::NISCallback::HandleSubtitleStart(v4, subtitle1, v3->m_markerCallbackInfo.m_labelHash);
  }
  else if ( type == 2 && subtitle1[0] == audioEvent->m_markerCallbackInfo.m_labelHash )
  {
    UFG::NISCallback::HandleSubtitleEnd(this, subtitle1);
  }
}

// File Line: 105
// RVA: 0x59F450
void __fastcall UFG::NISCallback::HandleSubtitleStart(UFG::NISCallback *this, unsigned int *subtitle, unsigned int labelHash)
{
  unsigned int v3; // edi
  unsigned int *v4; // rsi
  UFG::allocator::free_link *v5; // rax
  unsigned int v6; // ebx
  __int64 v7; // rax
  __int64 v8; // rbp
  UFG::UIHKTextOverlay *v9; // rax

  if ( labelHash != 1471824835 )
  {
    v3 = labelHash;
    v4 = subtitle;
    if ( UFG::SubtitleManager::sm_subtitleMode == 2
      || UFG::SubtitleManager::sm_subtitleMode == 3 && UFG::SubtitleManager::LabelIsCantonese(labelHash) )
    {
      v5 = UFG::qMalloc(0xD0ui64, "UISubtitleMessage", 0i64);
      v6 = 0;
      if ( v5 )
      {
        UFG::UISubtitleMessage::UISubtitleMessage((UFG::UISubtitleMessage *)v5, 0, v3, 0i64);
        v8 = v7;
      }
      else
      {
        v8 = 0i64;
      }
      *(_DWORD *)(v8 + 24) = 1097859072;
      v9 = UFG::UIHKTextOverlay::getInstance();
      if ( v9 )
        v6 = UFG::UIHKTextOverlay::QueueMessage(v9, (UFG::UISubtitleMessage *)v8);
      if ( !*v4 )
      {
        if ( v6 )
        {
          *v4 = v3;
          v4[1] = v6;
        }
      }
    }
  }
}

// File Line: 142
// RVA: 0x59F390
void __fastcall UFG::NISCallback::HandleSubtitleEnd(UFG::NISCallback *this, unsigned int *subtitle)
{
  unsigned int *v2; // rbx
  UFG::UIHKTextOverlay *v3; // rax
  UFG::UIHKTextOverlay *v4; // rax
  UFG::UIHKTextOverlay *v5; // rax

  v2 = subtitle;
  v3 = UFG::UIHKTextOverlay::getInstance();
  if ( UFG::UIHKTextOverlay::GetSubtitleAge(v3, v2[1]) >= 3.0 )
  {
    v5 = UFG::UIHKTextOverlay::getInstance();
    UFG::UIHKTextOverlay::KillSubtitles(v5, v2[1]);
  }
  else
  {
    v4 = UFG::UIHKTextOverlay::getInstance();
    UFG::UIHKTextOverlay::ChangeSubtitleLifetime(v4, v2[1], 2.0);
  }
  *(_QWORD *)v2 = 0i64;
}

