// File Line: 15
// RVA: 0x1407D0
void __fastcall UFG::OneShot::OneShot(UFG::OneShot *this)
{
  UFG::OneShot *v1; // rbx
  UFG::qNode<UFG::OneShot,UFG::OneShot> *v2; // rax

  v1 = this;
  UFG::AudioEntity::AudioEntity((UFG::AudioEntity *)&this->vfptr);
  v2 = (UFG::qNode<UFG::OneShot,UFG::OneShot> *)&v1->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  v1->vfptr = (UFG::AudioEntityVtbl *)&UFG::OneShot::`vftable;
  v1->m_controller.m_pEvent = 0i64;
  v1->m_pOwnerHandle = 0i64;
  v1->m_eventCount = 0;
}

// File Line: 26
// RVA: 0x146D70
void __fastcall UFG::OneShot::Init(UFG::OneShot *this, unsigned int index, UFG::qMatrix44 *transform)
{
  UFG::qMatrix44 *v3; // rbx
  UFG::OneShot *v4; // rdi
  UFG::qString *v5; // rax
  UFG::qString result; // [rsp+28h] [rbp-30h]
  UFG::qSymbol object_name; // [rsp+68h] [rbp+10h]

  v3 = transform;
  v4 = this;
  v5 = UFG::qString::FormatEx(&result, "OneShot_%3u", index + 100);
  UFG::qSymbol::create_from_string(&object_name, v5->mData);
  UFG::qString::~qString(&result);
  UFG::AudioEntity::Init((UFG::AudioEntity *)&v4->vfptr, &object_name, v3);
  v4->m_bIsDopplerEnabled = 0;
  v4->m_spreadRegionChecks = 0;
  UFG::qRandom(UFG::AudioEntity::sm_RegionCheckSpread, &UFG::qDefaultSeed);
  v4->m_regionCheckFrame = -1;
}

// File Line: 72
// RVA: 0x143320
void __fastcall UFG::OneShot::AudioEntityUpdate(UFG::OneShot *this, float delta_sec)
{
  UFG::qNode<UFG::OneShot,UFG::OneShot> *v2; // rcx
  UFG::qNode<UFG::OneShot,UFG::OneShot> *v3; // rax

  if ( this->m_controller.m_pEvent )
  {
    UFG::AudioEntity::AudioEntityUpdate((UFG::AudioEntity *)&this->vfptr, delta_sec);
  }
  else
  {
    v2 = (UFG::qNode<UFG::OneShot,UFG::OneShot> *)&this->mPrev;
    if ( v2->mPrev == v2 && v2->mNext == v2 )
    {
      v3 = UFG::OneShot::smMarkedForClearList.mNode.mPrev;
      UFG::OneShot::smMarkedForClearList.mNode.mPrev->mNext = v2;
      v2->mPrev = v3;
      v2->mNext = (UFG::qNode<UFG::OneShot,UFG::OneShot> *)&UFG::OneShot::smMarkedForClearList;
      UFG::OneShot::smMarkedForClearList.mNode.mPrev = v2;
    }
  }
}

// File Line: 106
// RVA: 0x14A170
char __fastcall UFG::OneShot::Play(UFG::OneShot *this, unsigned int eventId)
{
  unsigned int v2; // esi
  UFG::OneShot *v3; // rdi
  char *v4; // rax
  __int64 v5; // rax
  UFG::AudioEvent *v6; // rcx
  UFG::AudioEvent *v7; // rax
  __int64 v9; // [rsp+48h] [rbp-30h]
  UFG::AudioEventInitParams pInitParams; // [rsp+50h] [rbp-28h]

  v2 = eventId;
  v3 = this;
  pInitParams.m_EventCallbackUserData = 0i64;
  LODWORD(v9) = 0;
  pInitParams.m_EventPlayEndCallback = (void (__fastcall *)(UFG::AudioEntity *, UFG::eAudioEventCallbackType, UFG::AudioEvent *, void *))UFG::OneShot::OneShotCallback;
  *(_QWORD *)pInitParams.gap8 = 0i64;
  *(_QWORD *)&pInitParams.gap8[8] = v9;
  ++this->m_eventCount;
  if ( this->m_bIsInitialized
    && (unsigned __int8)AK::SoundEngine::IsInitialized()
    && v2
    && UFG::gAudioEventPool.mFreeListHead )
  {
    v4 = UFG::AudioDialogEvent::operator new(0x98ui64);
    if ( v4 )
      UFG::AudioEvent::AudioEvent(
        (UFG::AudioEvent *)v4,
        v2,
        (UFG::AudioEntity *)&v3->vfptr,
        &v3->m_controller,
        &pInitParams,
        0i64);
    else
      v5 = 0i64;
    if ( v5 != 0 )
    {
      v6 = v3->m_controller.m_pEvent;
      if ( v6 )
      {
        if ( v6->vfptr->Play(v6, 0) )
          return 1;
        *((_BYTE *)v3->m_controller.m_pEvent + 144) |= 4u;
        v7 = v3->m_controller.m_pEvent;
        if ( v7 )
          v7->m_pController = 0i64;
        v3->m_controller.m_pEvent = 0i64;
      }
    }
  }
  return 0;
}

// File Line: 117
// RVA: 0x14CAF0
void __fastcall UFG::OneShot::Stop(UFG::OneShot *this, unsigned int fadeOutMs, unsigned int eventId)
{
  UFG::AudioEvent *v3; // rcx
  __int64 v4; // [rsp+40h] [rbp-38h]
  UFG::AudioEventInitParams pInitParams; // [rsp+48h] [rbp-30h]

  if ( eventId )
  {
    ++this->m_eventCount;
    LODWORD(v4) = 0;
    pInitParams.m_EventPlayEndCallback = (void (__fastcall *)(UFG::AudioEntity *, UFG::eAudioEventCallbackType, UFG::AudioEvent *, void *))UFG::OneShot::OneShotCallback;
    *(_QWORD *)pInitParams.gap8 = 0i64;
    pInitParams.m_EventCallbackUserData = 0i64;
    *(_QWORD *)&pInitParams.gap8[8] = v4;
    UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&this->vfptr, eventId, &pInitParams, 0, 0i64);
  }
  else
  {
    v3 = this->m_controller.m_pEvent;
    if ( v3 )
      UFG::AudioEvent::StopAndForget(v3, fadeOutMs);
  }
}

// File Line: 142
// RVA: 0x149960
void __fastcall UFG::OneShot::OneShotCallback(UFG::OneShot *this, UFG::eAudioEventCallbackType in_eType, UFG::AudioEvent *in_pEvent, void *in_pCallbackInfo)
{
  bool v4; // zf
  UFG::qNode<UFG::OneShot,UFG::OneShot> *v5; // rcx
  UFG::qNode<UFG::OneShot,UFG::OneShot> *v6; // rax

  if ( in_eType == 2 )
  {
    v4 = this->m_eventCount-- == 1;
    if ( v4 )
    {
      v5 = (UFG::qNode<UFG::OneShot,UFG::OneShot> *)&this->mPrev;
      if ( v5->mPrev == v5 && v5->mNext == v5 )
      {
        v6 = UFG::OneShot::smMarkedForClearList.mNode.mPrev;
        UFG::OneShot::smMarkedForClearList.mNode.mPrev->mNext = v5;
        v5->mPrev = v6;
        v5->mNext = (UFG::qNode<UFG::OneShot,UFG::OneShot> *)&UFG::OneShot::smMarkedForClearList;
        UFG::OneShot::smMarkedForClearList.mNode.mPrev = v5;
      }
    }
  }
}

