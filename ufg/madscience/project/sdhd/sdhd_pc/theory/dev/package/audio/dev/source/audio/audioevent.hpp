// File Line: 55
// RVA: 0x593E30
void __fastcall UFG::AudioEventCallbackObject::~AudioEventCallbackObject(UFG::AudioEventCallbackObject *this)
{
  this->vfptr = (UFG::AudioEventCallbackObjectVtbl *)&UFG::AudioEventCallbackObject::`vftable';
}

// File Line: 121
// RVA: 0x592D40
void __fastcall UFG::AudioEventExternalSourceInfo::AudioEventExternalSourceInfo(UFG::AudioEventExternalSourceInfo *this, unsigned int numExternals)
{
  unsigned int v2; // edi
  UFG::AudioEventExternalSourceInfo *v3; // rsi

  v2 = numExternals;
  v3 = this;
  this->vfptr = (UFG::AudioEventExternalSourceInfoVtbl *)&UFG::AudioEventExternalSourceInfo::`vftable';
  this->m_externals.p = 0i64;
  *(_QWORD *)&this->m_externals.size = 0i64;
  UFG::qArray<UFG::ExternalSourceInfoNode,0>::Reallocate(
    &this->m_externals,
    numExternals,
    "qArray.Reallocate(Constructor)");
  v3->m_externals.size = v2;
  v3->m_numExternals = v2;
}

// File Line: 126
// RVA: 0x593E40
void __fastcall UFG::AudioEventExternalSourceInfo::~AudioEventExternalSourceInfo(UFG::AudioEventExternalSourceInfo *this)
{
  UFG::AudioEventExternalSourceInfo *v1; // rbx
  UFG::ExternalSourceInfoNode *v2; // rdx
  UFG::ExternalSourceInfoNode *v3; // rdx

  v1 = this;
  this->vfptr = (UFG::AudioEventExternalSourceInfoVtbl *)&UFG::AudioEventExternalSourceInfo::`vftable';
  v2 = this->m_externals.p;
  if ( v2 )
    UFG::qMemoryPool::Free(&g_AudioComponentPool, v2);
  v1->m_externals.p = 0i64;
  *(_QWORD *)&v1->m_externals.size = 0i64;
  v3 = v1->m_externals.p;
  if ( v3 )
    UFG::qMemoryPool::Free(&g_AudioComponentPool, v3);
  v1->m_externals.p = 0i64;
  *(_QWORD *)&v1->m_externals.size = 0i64;
}

// File Line: 311
// RVA: 0x141880
char *__fastcall UFG::AudioDialogEvent::operator new(unsigned __int64 size)
{
  char *v1; // rbx

  v1 = UFG::gAudioEventPool.mFreeListHead;
  if ( UFG::gAudioEventPool.mFreeListHead )
  {
    UFG::gAudioEventPool.mFreeListHead = *(char **)UFG::gAudioEventPool.mFreeListHead;
    if ( UFG::gAudioEventPool.mMostSlotsAllocated <= ++UFG::gAudioEventPool.mNumSlotsAllocated )
    {
      UFG::gAudioEventPool.mMostSlotsAllocated = UFG::gAudioEventPool.mNumSlotsAllocated;
      return v1;
    }
  }
  else
  {
    UFG::qFixedAllocator::ReportFull(&UFG::gAudioEventPool);
  }
  return v1;
}

// File Line: 331
// RVA: 0x141260
void __fastcall UFG::AudioEventController::~AudioEventController(UFG::AudioEventController *this)
{
  UFG::AudioEvent *v1; // rcx

  v1 = this->m_pEvent;
  if ( v1 )
    JUMPOUT(v1->m_pController, 0i64, UFG::AudioEvent::Destroy);
}

// File Line: 335
// RVA: 0x14A060
char __fastcall UFG::AudioEventController::Play(UFG::AudioEventController *this, unsigned int fadeInDurationMs)
{
  UFG::AudioEventController *v2; // rbx
  UFG::AudioEvent *v3; // rcx

  v2 = this;
  v3 = this->m_pEvent;
  if ( !v3 )
    return 0;
  if ( !v3->vfptr->Play(v3, 0) )
  {
    *((_BYTE *)v2->m_pEvent + 144) |= 4u;
    if ( v2->m_pEvent )
      v2->m_pEvent->m_pController = 0i64;
    v2->m_pEvent = 0i64;
    return 0;
  }
  return 1;
}

// File Line: 469
// RVA: 0x144F20
void __fastcall UFG::StopAllEventsOfIdFunctor::Do(UFG::StopAllEventsOfIdFunctor *this, UFG::AudioEvent *pAe)
{
  if ( pAe->m_uEventId == this->id )
    UFG::AudioEvent::StopAndForget(pAe, (signed int)this->fadeLength);
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
  UFG::AudioEvent::StopAndForget(pAe, (signed int)this->fadeLength);
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
  unsigned int v2; // eax

  v2 = this->playingId;
  if ( !v2 || pAe->m_uEventId == v2 )
  {
    if ( *((_BYTE *)pAe + 144) & 0x40 )
      ++this->playingCount;
  }
}

// File Line: 545
// RVA: 0x144D90
void __fastcall UFG::FindOldestEventFunctor::Do(UFG::FindOldestEventFunctor *this, UFG::AudioEvent *pAe)
{
  UFG::AudioEvent *v2; // rbx
  UFG::FindOldestEventFunctor *v3; // rdi
  float v4; // xmm6_4
  float v5; // xmm7_4
  int out_puPosition; // [rsp+50h] [rbp+8h]
  int v7; // [rsp+58h] [rbp+10h]

  v2 = pAe;
  v3 = this;
  if ( pAe->m_uEventId == this->playingId && *((_BYTE *)pAe + 144) & 0x40 )
  {
    if ( this->oldestAudioEvent )
    {
      v4 = 0.0;
      v5 = 0.0;
      if ( AK::SoundEngine::GetSourcePlayPosition(pAe->m_uPlayingId, &out_puPosition, 0) == 1 )
        v5 = (float)out_puPosition;
      if ( AK::SoundEngine::GetSourcePlayPosition(v3->oldestAudioEvent->m_uPlayingId, &v7, 0) == 1 )
        v4 = (float)v7;
      if ( v5 > v4 )
        v3->oldestAudioEvent = v2;
    }
    else
    {
      this->oldestAudioEvent = pAe;
    }
  }
}

