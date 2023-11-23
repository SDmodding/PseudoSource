// File Line: 15
// RVA: 0x1407D0
void __fastcall UFG::OneShot::OneShot(UFG::OneShot *this)
{
  UFG::AudioEntity::AudioEntity(this);
  this->UFG::qNode<UFG::OneShot,UFG::OneShot>::mPrev = &this->UFG::qNode<UFG::OneShot,UFG::OneShot>;
  this->UFG::qNode<UFG::OneShot,UFG::OneShot>::mNext = &this->UFG::qNode<UFG::OneShot,UFG::OneShot>;
  this->vfptr = (UFG::AudioEntityVtbl *)&UFG::OneShot::`vftable;
  this->m_controller.m_pEvent = 0i64;
  this->m_pOwnerHandle = 0i64;
  this->m_eventCount = 0;
}

// File Line: 26
// RVA: 0x146D70
void __fastcall UFG::OneShot::Init(UFG::OneShot *this, unsigned int index, UFG::qMatrix44 *transform)
{
  UFG::qString *v5; // rax
  UFG::qString result; // [rsp+28h] [rbp-30h] BYREF
  UFG::qSymbol object_name; // [rsp+68h] [rbp+10h] BYREF

  v5 = UFG::qString::FormatEx(&result, "OneShot_%3u", index + 100);
  UFG::qSymbol::create_from_string(&object_name, v5->mData);
  UFG::qString::~qString(&result);
  UFG::AudioEntity::Init(this, (UFG::qSymbolUC *)&object_name, transform);
  this->m_bIsDopplerEnabled = 0;
  this->m_spreadRegionChecks = 0;
  UFG::qRandom(UFG::AudioEntity::sm_RegionCheckSpread, &UFG::qDefaultSeed);
  this->m_regionCheckFrame = -1;
}

// File Line: 72
// RVA: 0x143320
void __fastcall UFG::OneShot::AudioEntityUpdate(UFG::OneShot *this, float delta_sec)
{
  UFG::qNode<UFG::OneShot,UFG::OneShot> *v2; // rcx
  UFG::qNode<UFG::OneShot,UFG::OneShot> *mPrev; // rax

  if ( this->m_controller.m_pEvent )
  {
    UFG::AudioEntity::AudioEntityUpdate(this, delta_sec);
  }
  else
  {
    v2 = &this->UFG::qNode<UFG::OneShot,UFG::OneShot>;
    if ( v2->mPrev == v2 && v2->mNext == v2 )
    {
      mPrev = UFG::OneShot::smMarkedForClearList.mNode.mPrev;
      UFG::OneShot::smMarkedForClearList.mNode.mPrev->mNext = v2;
      v2->mPrev = mPrev;
      v2->mNext = (UFG::qNode<UFG::OneShot,UFG::OneShot> *)&UFG::OneShot::smMarkedForClearList;
      UFG::OneShot::smMarkedForClearList.mNode.mPrev = v2;
    }
  }
}

// File Line: 106
// RVA: 0x14A170
char __fastcall UFG::OneShot::Play(UFG::OneShot *this, unsigned int eventId)
{
  char *v4; // rax
  __int64 v5; // rax
  UFG::AudioEvent *m_pEvent; // rcx
  UFG::AudioEvent *v7; // rax
  __int64 v9; // [rsp+48h] [rbp-30h]
  UFG::AudioEventInitParams pInitParams; // [rsp+50h] [rbp-28h] BYREF

  pInitParams.m_EventCallbackUserData = 0i64;
  LODWORD(v9) = 0;
  pInitParams.m_EventPlayEndCallback = (void (__fastcall *)(UFG::AudioEntity *, UFG::eAudioEventCallbackType, UFG::AudioEvent *, void *))UFG::OneShot::OneShotCallback;
  *(_QWORD *)pInitParams.gap8 = 0i64;
  *(_QWORD *)&pInitParams.gap8[8] = v9;
  ++this->m_eventCount;
  if ( this->m_bIsInitialized && AK::SoundEngine::IsInitialized() && eventId && UFG::gAudioEventPool.mFreeListHead )
  {
    v4 = UFG::AudioDialogEvent::operator new(0x98ui64);
    if ( v4 )
      UFG::AudioEvent::AudioEvent((UFG::AudioEvent *)v4, eventId, this, &this->m_controller, &pInitParams, 0i64);
    else
      v5 = 0i64;
    if ( v5 )
    {
      m_pEvent = this->m_controller.m_pEvent;
      if ( m_pEvent )
      {
        if ( m_pEvent->vfptr->Play(m_pEvent, 0) )
          return 1;
        *((_BYTE *)this->m_controller.m_pEvent + 144) |= 4u;
        v7 = this->m_controller.m_pEvent;
        if ( v7 )
          v7->m_pController = 0i64;
        this->m_controller.m_pEvent = 0i64;
      }
    }
  }
  return 0;
}

// File Line: 117
// RVA: 0x14CAF0
void __fastcall UFG::OneShot::Stop(UFG::OneShot *this, unsigned int fadeOutMs, unsigned int eventId)
{
  UFG::AudioEvent *m_pEvent; // rcx
  __int64 v4; // [rsp+40h] [rbp-38h]
  UFG::AudioEventInitParams pInitParams; // [rsp+48h] [rbp-30h] BYREF

  if ( eventId )
  {
    ++this->m_eventCount;
    LODWORD(v4) = 0;
    pInitParams.m_EventPlayEndCallback = (void (__fastcall *)(UFG::AudioEntity *, UFG::eAudioEventCallbackType, UFG::AudioEvent *, void *))UFG::OneShot::OneShotCallback;
    *(_QWORD *)pInitParams.gap8 = 0i64;
    pInitParams.m_EventCallbackUserData = 0i64;
    *(_QWORD *)&pInitParams.gap8[8] = v4;
    UFG::AudioEntity::CreateAndPlayEvent(this, eventId, &pInitParams, 0, 0i64);
  }
  else
  {
    m_pEvent = this->m_controller.m_pEvent;
    if ( m_pEvent )
      UFG::AudioEvent::StopAndForget(m_pEvent, fadeOutMs);
  }
}

// File Line: 142
// RVA: 0x149960
void __fastcall UFG::OneShot::OneShotCallback(
        UFG::OneShot *this,
        UFG::eAudioEventCallbackType in_eType,
        UFG::AudioEvent *in_pEvent,
        void *in_pCallbackInfo)
{
  UFG::qNode<UFG::OneShot,UFG::OneShot> *v5; // rcx
  UFG::qNode<UFG::OneShot,UFG::OneShot> *mPrev; // rax

  if ( in_eType == eAudioEventCallbackType_End && this->m_eventCount-- == 1 )
  {
    v5 = &this->UFG::qNode<UFG::OneShot,UFG::OneShot>;
    if ( v5->mPrev == v5 && v5->mNext == v5 )
    {
      mPrev = UFG::OneShot::smMarkedForClearList.mNode.mPrev;
      UFG::OneShot::smMarkedForClearList.mNode.mPrev->mNext = v5;
      v5->mPrev = mPrev;
      v5->mNext = (UFG::qNode<UFG::OneShot,UFG::OneShot> *)&UFG::OneShot::smMarkedForClearList;
      UFG::OneShot::smMarkedForClearList.mNode.mPrev = v5;
    }
  }
}

