// File Line: 55
// RVA: 0x593E30
void __fastcall UFG::AudioEventCallbackObject::~AudioEventCallbackObject(UFG::AudioEventCallbackObject *this)
{
  this->vfptr = (UFG::AudioEventCallbackObjectVtbl *)&UFG::AudioEventCallbackObject::`vftable;
}

// File Line: 121
// RVA: 0x592D40
void __fastcall UFG::AudioEventExternalSourceInfo::AudioEventExternalSourceInfo(
        UFG::AudioEventExternalSourceInfo *this,
        unsigned int numExternals)
{
  this->vfptr = (UFG::AudioEventExternalSourceInfoVtbl *)&UFG::AudioEventExternalSourceInfo::`vftable;
  this->m_externals.p = 0i64;
  *(_QWORD *)&this->m_externals.size = 0i64;
  UFG::qArray<UFG::ExternalSourceInfoNode,0>::Reallocate(
    &this->m_externals,
    numExternals,
    "qArray.Reallocate(Constructor)");
  this->m_externals.size = numExternals;
  this->m_numExternals = numExternals;
}

// File Line: 126
// RVA: 0x593E40
void __fastcall UFG::AudioEventExternalSourceInfo::~AudioEventExternalSourceInfo(
        UFG::AudioEventExternalSourceInfo *this)
{
  char *p; // rdx
  char *v3; // rdx

  this->vfptr = (UFG::AudioEventExternalSourceInfoVtbl *)&UFG::AudioEventExternalSourceInfo::`vftable;
  p = (char *)this->m_externals.p;
  if ( p )
    UFG::qMemoryPool::Free(&g_AudioComponentPool, p);
  this->m_externals.p = 0i64;
  *(_QWORD *)&this->m_externals.size = 0i64;
  v3 = (char *)this->m_externals.p;
  if ( v3 )
    UFG::qMemoryPool::Free(&g_AudioComponentPool, v3);
  this->m_externals.p = 0i64;
  *(_QWORD *)&this->m_externals.size = 0i64;
}

// File Line: 311
// RVA: 0x141880
char *__fastcall UFG::AudioDialogEvent::operator new(unsigned __int64 size)
{
  char *mFreeListHead; // rbx

  mFreeListHead = UFG::gAudioEventPool.mFreeListHead;
  if ( UFG::gAudioEventPool.mFreeListHead )
  {
    UFG::gAudioEventPool.mFreeListHead = *(char **)UFG::gAudioEventPool.mFreeListHead;
    if ( UFG::gAudioEventPool.mMostSlotsAllocated <= ++UFG::gAudioEventPool.mNumSlotsAllocated )
    {
      UFG::gAudioEventPool.mMostSlotsAllocated = UFG::gAudioEventPool.mNumSlotsAllocated;
      return mFreeListHead;
    }
  }
  else
  {
    UFG::qFixedAllocator::ReportFull(&UFG::gAudioEventPool);
  }
  return mFreeListHead;
}

// File Line: 331
// RVA: 0x141260
void __fastcall UFG::AudioEventController::~AudioEventController(UFG::AudioEventController *this)
{
  UFG::AudioEvent *m_pEvent; // rcx

  m_pEvent = this->m_pEvent;
  if ( m_pEvent )
  {
    if ( m_pEvent->m_pController )
      UFG::AudioEvent::Destroy(m_pEvent);
  }
}

// File Line: 335
// RVA: 0x14A060
char __fastcall UFG::AudioEventController::Play(UFG::AudioEventController *this, unsigned int fadeInDurationMs)
{
  UFG::AudioEvent *m_pEvent; // rcx

  m_pEvent = this->m_pEvent;
  if ( !m_pEvent )
    return 0;
  if ( !m_pEvent->vfptr->Play(m_pEvent, 0) )
  {
    *((_BYTE *)this->m_pEvent + 144) |= 4u;
    if ( this->m_pEvent )
      this->m_pEvent->m_pController = 0i64;
    this->m_pEvent = 0i64;
    return 0;
  }
  return 1;
}

// File Line: 469
// RVA: 0x144F20
void __fastcall UFG::StopAllEventsOfIdFunctor::Do(UFG::StopAllEventsOfIdFunctor *this, UFG::AudioEvent *pAe)
{
  if ( pAe->m_uEventId == this->id )
    UFG::AudioEvent::StopAndForget(pAe, (int)this->fadeLength);
}

// File Line: 476
// RVA: 0x144D80
void __fastcall UFG::DestroyEventFunctor::Do(UFG::DestroyEventFunctor *this, UFG::AudioEvent *pAe)
{
  UFG::AudioEvent::Destroy(pAe);
}

// File Line: 481
// RVA: 0x144F40
void __fastcall UFG::StopAndForgetFunctor::Do(UFG::StopAndForgetFunctor *this, UFG::AudioEvent *pAe)
{
  UFG::AudioEvent::StopAndForget(pAe, (int)this->fadeLength);
}

// File Line: 500
// RVA: 0x144F10
void __fastcall UFG::ResumeFunctor::Do(UFG::ResumeFunctor *this, UFG::AudioEvent *pAe)
{
  pAe->vfptr->Resume(pAe, 0);
}

// File Line: 513
// RVA: 0x144E40
void __fastcall UFG::IsIdPlayingFunctor::Do(UFG::IsIdPlayingFunctor *this, UFG::AudioEvent *pAe)
{
  unsigned int playingId; // eax

  playingId = this->playingId;
  if ( (!playingId || pAe->m_uEventId == playingId) && (*((_BYTE *)pAe + 144) & 0x40) != 0 )
    ++this->playingCount;
}

// File Line: 545
// RVA: 0x144D90
void __fastcall UFG::FindOldestEventFunctor::Do(UFG::FindOldestEventFunctor *this, UFG::AudioEvent *pAe)
{
  float v4; // xmm6_4
  float v5; // xmm7_4
  int out_puPosition; // [rsp+50h] [rbp+8h] BYREF
  int v7; // [rsp+58h] [rbp+10h] BYREF

  if ( pAe->m_uEventId == this->playingId && (*((_BYTE *)pAe + 144) & 0x40) != 0 )
  {
    if ( this->oldestAudioEvent )
    {
      v4 = 0.0;
      v5 = 0.0;
      if ( AK::SoundEngine::GetSourcePlayPosition(pAe->m_uPlayingId, &out_puPosition, 0) == AK_Success )
        v5 = (float)out_puPosition;
      if ( AK::SoundEngine::GetSourcePlayPosition(this->oldestAudioEvent->m_uPlayingId, &v7, 0) == AK_Success )
        v4 = (float)v7;
      if ( v5 > v4 )
        this->oldestAudioEvent = pAe;
    }
    else
    {
      this->oldestAudioEvent = pAe;
    }
  }
}

