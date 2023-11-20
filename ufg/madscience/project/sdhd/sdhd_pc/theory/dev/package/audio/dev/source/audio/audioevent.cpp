// File Line: 86
// RVA: 0x140420
void __fastcall UFG::AudioEvent::AudioEvent(UFG::AudioEvent *this, unsigned int uEventId, UFG::AudioEntity *pEntity, UFG::AudioEventController *pController, UFG::AudioEventInitParams *pInitParams, UFG::AudioEventExternalSourceInfo *pExternalInfo)
{
  UFG::AudioEvent *v6; // r10
  UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> *v7; // r11
  UFG::qSNode<UFG::AudioEvent,UFG::AudioEvent> *v8; // rbx
  signed int v9; // eax
  UFG::qSList<UFG::AudioEvent,UFG::AudioEvent,1> *v10; // rcx
  UFG::AudioEntity *v11; // rcx
  UFG::qList<UFG::AudioEvent,UFG::AudioEvent,1,0> *v12; // rcx
  UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> *v13; // rax
  __int64 v14; // [rsp+18h] [rbp-10h]

  v6 = this;
  v7 = (UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> *)&this->mPrev;
  v7->mPrev = v7;
  v7->mNext = v7;
  v8 = (UFG::qSNode<UFG::AudioEvent,UFG::AudioEvent> *)&this->mNext;
  this->mNext = 0i64;
  this->vfptr = (UFG::AudioEventVtbl *)&UFG::AudioEvent::`vftable';
  this->m_uEventId = uEventId;
  this->m_callbackObject = 0i64;
  LODWORD(v14) = -1;
  this->m_InitParams.m_EventPlayEndCallback = 0i64;
  *(_QWORD *)this->m_InitParams.gap8 = 0i64;
  *(_QWORD *)&this->m_InitParams.gap8[8] = v14;
  this->m_InitParams.m_EventCallbackUserData = 0i64;
  *(_QWORD *)&this->m_markerCallbackInfo.m_identifier = 0i64;
  *(_QWORD *)&this->m_markerCallbackInfo.m_labelHash = 0i64;
  *(_QWORD *)&this->m_markerCallbackInfo.m_floatParameter = 0i64;
  this->m_pEntity = pEntity;
  this->m_pController = 0i64;
  this->m_pProperties = 0i64;
  this->m_externalInfo = pExternalInfo;
  *(_QWORD *)&this->m_fTouchUpdateTimeout = 0i64;
  *((_BYTE *)this + 144) = 0;
  *((_BYTE *)this + 145) &= 0xFCu;
  *((_BYTE *)this + 145) |= 4u;
  v9 = 0x7FFFFFFF;
  v10 = &UFG::AudioEventManager::sm_allEventsList;
  if ( UFG::AudioEventManager::sm_allEventsList.mHead )
  {
    do
    {
      if ( v9 <= 0 )
        break;
      v10 = (UFG::qSList<UFG::AudioEvent,UFG::AudioEvent,1> *)v10->mHead;
      --v9;
    }
    while ( v10->mHead );
  }
  v8->mNext = v10->mHead;
  v10->mHead = v8;
  if ( pInitParams )
    v6->m_InitParams = *pInitParams;
  if ( pController )
  {
    pController->m_pEvent = v6;
    v6->m_pController = pController;
  }
  v11 = v6->m_pEntity;
  if ( v11 )
  {
    v12 = &v11->m_events;
    v13 = v12->mNode.mPrev;
    v13->mNext = v7;
    v7->mPrev = v13;
    v7->mNext = &v12->mNode;
    v12->mNode.mPrev = v7;
  }
}

// File Line: 108
// RVA: 0x144F60
void __fastcall UFG::AudioEvent::DoCallback(UFG::AudioEvent *this, UFG::eAudioEventCallbackType callbackType)
{
  UFG::eAudioEventCallbackType v2; // esi
  UFG::AudioEntity *v3; // rdx
  UFG::AudioEvent *v4; // rdi
  void (__fastcall *v5)(UFG::AudioEntity *, UFG::eAudioEventCallbackType, UFG::AudioEvent *, void *); // rax
  UFG::AudioEventCallbackObject *i; // rbx

  v2 = callbackType;
  v3 = this->m_pEntity;
  v4 = this;
  if ( v3 )
  {
    v5 = this->m_InitParams.m_EventPlayEndCallback;
    if ( v5 )
      v5(
        (UFG::AudioEntity *)((char *)v3 + *(signed int *)this->m_InitParams.gap8),
        v2,
        this,
        this->m_InitParams.m_EventCallbackUserData);
  }
  if ( v4->m_pEntity )
  {
    for ( i = v4->m_callbackObject; i; i = i->m_next )
      i->vfptr->Do(i, v4, v2);
  }
}

// File Line: 119
// RVA: 0x142870
void __fastcall UFG::AudioEvent::AddCallback(UFG::AudioEvent *this, UFG::AudioEventCallbackObject *eventCallback)
{
  UFG::AudioEventCallbackObject *v2; // rax

  v2 = this->m_callbackObject;
  if ( v2 )
  {
    while ( v2->m_next )
      v2 = v2->m_next;
    v2->m_next = eventCallback;
  }
  else
  {
    this->m_callbackObject = eventCallback;
  }
}

// File Line: 124
// RVA: 0x141150
void __fastcall UFG::AudioEvent::~AudioEvent(UFG::AudioEvent *this)
{
  UFG::AudioEvent *v1; // rbx
  UFG::AudioEventExternalSourceInfo *v2; // rcx
  UFG::AudioEventController *v3; // rax
  UFG::AudioEventCallbackObject *v4; // rdi
  UFG::AudioEventCallbackObject *v5; // rcx
  UFG::qSNode<UFG::AudioEvent,UFG::AudioEvent> *v6; // rdx
  UFG::qSList<UFG::AudioEvent,UFG::AudioEvent,1> *v7; // rcx
  UFG::qSNode<UFG::AudioEvent,UFG::AudioEvent> *v8; // rax
  UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> *v9; // rdx
  UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> *v10; // rcx
  UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> *v11; // rax

  v1 = this;
  this->vfptr = (UFG::AudioEventVtbl *)&UFG::AudioEvent::`vftable';
  v2 = this->m_externalInfo;
  if ( v2 )
    v2->vfptr->__vecDelDtor(v2, 1u);
  v3 = v1->m_pController;
  if ( v3 && v1->m_uEventId )
  {
    if ( v3->m_pEvent )
      v3->m_pEvent = 0i64;
    v1->m_pController->m_pEvent = 0i64;
    v1->m_pController = 0i64;
  }
  if ( v1->m_uPlayingId && *((_BYTE *)v1 + 144) & 0x40 )
    UFG::AudioEvent::DoCallback(v1, eAudioEventCallbackType_End);
  v4 = v1->m_callbackObject;
  while ( v4 )
  {
    v5 = v4;
    v4 = v4->m_next;
    v5->vfptr->__vecDelDtor(v5, 1u);
  }
  v1->m_callbackObject = 0i64;
  v6 = (UFG::qSNode<UFG::AudioEvent,UFG::AudioEvent> *)&v1->mNext;
  v7 = &UFG::AudioEventManager::sm_allEventsList;
  if ( UFG::AudioEventManager::sm_allEventsList.mHead )
  {
    while ( 1 )
    {
      v8 = v7->mHead;
      if ( v7->mHead == v6 )
        break;
      v7 = (UFG::qSList<UFG::AudioEvent,UFG::AudioEvent,1> *)v7->mHead;
      if ( !v8->mNext )
        goto LABEL_18;
    }
    v7->mHead = v6->mNext;
    v6->mNext = 0i64;
  }
LABEL_18:
  v9 = (UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> *)&v1->mPrev;
  v10 = v1->mPrev;
  v11 = v1->mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v9->mPrev = v9;
  v9->mNext = v9;
}

// File Line: 146
// RVA: 0x149E50
char __fastcall UFG::AudioEvent::Play(UFG::AudioEvent *this, unsigned int fadeInDurationMs)
{
  int v2; // esi
  UFG::AudioEvent *v3; // rbx
  unsigned int v5; // edx
  UFG::qBaseTreeRB *v6; // rax
  UFG::qBaseNodeRB *v7; // rdi
  unsigned int v8; // edx
  UFG::qBaseTreeRB *v9; // rax
  signed __int64 v10; // rax
  unsigned int v11; // edx
  UFG::qBaseTreeRB *v12; // rax
  signed __int64 v13; // rax
  unsigned int v14; // edx
  UFG::qBaseTreeRB *v15; // rax
  UFG::AudioEvent *v16; // rax
  UFG::AudioEventProperties *v17; // rcx
  UFG::AudioEventPropertyData *v18; // rdx
  unsigned int v19; // eax
  UFG::AudioEventProperties *v20; // rax
  UFG::AudioEventPropertyData *v21; // rax

  v2 = fadeInDurationMs;
  v3 = this;
  if ( UFG::WwiseInterface::smLoadScreen )
  {
    *((_BYTE *)this + 144) |= 0x10u;
    return 1;
  }
  v5 = this->m_uEventId;
  if ( v5 )
  {
    v6 = UFG::qBaseTreeRB::Get(&UFG::AudioEventPropertyManager::mDatabase.mTree, v5);
    if ( v6 )
    {
      v7 = v6->mNULL.mChild[0];
      v8 = v7[2].mUID;
      if ( v8 )
      {
        v9 = UFG::qBaseTreeRB::Get(&UFG::SoundBankManager::sm_soundBank_Tree.mTree, v8);
        if ( v9 )
        {
          v10 = (signed __int64)&v9[-1].mCount;
          if ( v10 )
          {
            if ( *(_DWORD *)(v10 + 76) != 0 )
            {
              v11 = v7[2].mUID;
              if ( v11 )
              {
                v12 = UFG::qBaseTreeRB::Get(&UFG::SoundBankManager::sm_soundBank_Tree.mTree, v11);
                if ( v12 )
                {
                  v13 = (signed __int64)&v12[-1].mCount;
                  if ( v13 )
                  {
                    if ( (*(_DWORD *)(v13 + 112) - 2) & 0xFFFFFFFB )
                    {
                      *((_BYTE *)v3 + 144) |= 0x20u;
                      return 1;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  v14 = v3->m_uEventId;
  if ( v14 )
    v15 = UFG::qBaseTreeRB::Get(&UFG::AudioEventPropertyManager::mDatabase.mTree, v14);
  else
    v15 = 0i64;
  v3->m_pProperties = (UFG::AudioEventProperties *)v15;
  if ( v15 )
  {
    if ( SHIDWORD(v15->mNULL.mChild[0][3].mParent) > 0
      && (signed int)UFG::AudioEventManager::CountIdPlaying(v3->m_uEventId) >= v3->m_pProperties->mData->maxSimultaneous )
    {
      v16 = UFG::AudioEventManager::FindOldestEvent(v3->m_uEventId);
      if ( v16 )
      {
        v17 = v16->m_pProperties;
        if ( v17 )
        {
          v18 = v17->mData;
          if ( v18->stopEventName.mUID )
            v16->m_fTouchUpdateTimeout = v18->timeDelay;
        }
      }
      return 0;
    }
    if ( v3->m_pProperties->mData->dontOcclude )
    {
      v3->m_pEntity->m_bSetOcclusionOverride = 1;
      UFG::AudioEntity::SetObstructionAndOcclusionTargets(v3->m_pEntity, 0.0, 0.0, 1);
    }
  }
  if ( UFG::TiDo::IsEventEnabled(UFG::TiDo::m_pInstance, v3->m_uEventId) )
    v19 = (unsigned __int64)UFG::WwiseInterface::PlayEvent(v3);
  else
    v19 = 0;
  v3->m_uPlayingId = v19;
  if ( !v19 )
    return 0;
  *((_BYTE *)v3 + 144) |= 0x40u;
  UFG::AudioEvent::DoCallback(v3, 0);
  v20 = v3->m_pProperties;
  if ( v20 )
  {
    v21 = v20->mData;
    if ( v21->stopEventName.mUID )
      v3->m_fTouchUpdateTimeout = v21->timeDelay;
  }
  if ( v2 )
  {
    AK::SoundEngine::ExecuteActionOnEvent(
      v3->m_uEventId,
      AkActionOnEventType_Pause,
      (unsigned __int64)v3->m_pEntity,
      0,
      AkCurveInterpolation_Linear,
      0);
    AK::SoundEngine::ExecuteActionOnEvent(
      v3->m_uEventId,
      AkActionOnEventType_Resume,
      (unsigned __int64)v3->m_pEntity,
      v2,
      AkCurveInterpolation_Linear,
      0);
  }
  return 1;
}

// File Line: 224
// RVA: 0x149D70
void __fastcall UFG::AudioEvent::Pause(UFG::AudioEvent *this, unsigned int fadeOutDurationMs)
{
  UFG::AudioEvent *v2; // rbx

  v2 = this;
  if ( *((_BYTE *)this + 144) & 0x40 )
  {
    AK::SoundEngine::ExecuteActionOnEvent(
      this->m_uEventId,
      AkActionOnEventType_Pause,
      (unsigned __int64)this->m_pEntity,
      fadeOutDurationMs,
      AkCurveInterpolation_Linear,
      0);
    *((_BYTE *)v2 + 145) |= 1u;
  }
}

// File Line: 233
// RVA: 0x14B640
void __fastcall UFG::AudioEvent::Resume(UFG::AudioEvent *this, unsigned int fadeInDurationMs)
{
  UFG::AudioEvent *v2; // rbx

  v2 = this;
  if ( *((_BYTE *)this + 145) & 1 )
  {
    AK::SoundEngine::ExecuteActionOnEvent(
      this->m_uEventId,
      AkActionOnEventType_Resume,
      (unsigned __int64)this->m_pEntity,
      fadeInDurationMs,
      AkCurveInterpolation_Linear,
      0);
    *((_BYTE *)v2 + 145) &= 0xFEu;
  }
}

// File Line: 242
// RVA: 0x14B920
void __fastcall UFG::AudioEvent::Seek(UFG::AudioEvent *this, float percent)
{
  AK::SoundEngine::SeekOnEvent(this->m_uEventId, (unsigned __int64)this->m_pEntity, percent, 0);
}

// File Line: 247
// RVA: 0x14B940
void __fastcall UFG::AudioEvent::SeekMS(UFG::AudioEvent *this, int timeMs)
{
  AK::SoundEngine::SeekOnEvent(this->m_uEventId, (unsigned __int64)this->m_pEntity, timeMs, 0);
}

// File Line: 258
// RVA: 0x14B6F0
char __fastcall UFG::AudioEvent::ReusePlay(UFG::AudioEvent *this, unsigned int uEventId)
{
  char v2; // al
  UFG::qBaseTreeRB *v3; // rdi
  UFG::AudioEvent *v4; // rbx
  char result; // al
  UFG::qBaseTreeRB *v6; // rax
  unsigned int v7; // edx
  UFG::qBaseTreeRB *v8; // rax
  signed __int64 v9; // rax
  unsigned int v10; // eax
  unsigned int v11; // edx
  UFG::qBaseNodeRB *v12; // rax

  *((_BYTE *)this + 144) &= 0xC2u;
  v2 = *((_BYTE *)this + 144);
  v3 = 0i64;
  this->m_pProperties = 0i64;
  *(_QWORD *)&this->m_fTouchUpdateTimeout = 0i64;
  this->m_uEventId = uEventId;
  v4 = this;
  if ( UFG::WwiseInterface::smLoadScreen )
  {
    *((_BYTE *)this + 144) = v2 | 0x10;
    result = 1;
  }
  else if ( uEventId
         && (v6 = UFG::qBaseTreeRB::Get(&UFG::AudioEventPropertyManager::mDatabase.mTree, uEventId)) != 0i64
         && (v7 = v6->mNULL.mChild[0][2].mUID) != 0
         && (v8 = UFG::qBaseTreeRB::Get(&UFG::SoundBankManager::sm_soundBank_Tree.mTree, v7)) != 0i64
         && (v9 = (signed __int64)&v8[-1].mCount) != 0
         && *(_DWORD *)(v9 + 76) > 0u )
  {
    *((_BYTE *)v4 + 144) |= 0x20u;
    result = 1;
  }
  else
  {
    UFG::AudioEvent::DoCallback(v4, 0);
    if ( UFG::TiDo::IsEventEnabled(UFG::TiDo::m_pInstance, v4->m_uEventId)
      && (v10 = (unsigned __int64)UFG::WwiseInterface::PlayEvent(v4)) != 0 )
    {
      v11 = v4->m_uEventId;
      *((_BYTE *)v4 + 144) |= 0x40u;
      v4->m_uPlayingId = v10;
      if ( v11 )
        v3 = UFG::qBaseTreeRB::Get(&UFG::AudioEventPropertyManager::mDatabase.mTree, v11);
      v4->m_pProperties = (UFG::AudioEventProperties *)v3;
      if ( v3 )
      {
        v12 = v3->mNULL.mChild[0];
        if ( HIDWORD(v12[2].mChild[1]) )
          v4->m_fTouchUpdateTimeout = *((float *)&v12[2].mUID + 1);
      }
      result = 1;
    }
    else
    {
      *((_BYTE *)v4 + 144) &= 0xBFu;
      result = 0;
    }
  }
  return result;
}

// File Line: 307
// RVA: 0x14CB70
char __fastcall UFG::AudioEvent::StopAndForget(UFG::AudioEvent *this, unsigned int durationMs)
{
  UFG::AudioEventController *v2; // rax
  int v3; // edi
  UFG::AudioEvent *v4; // rbx
  char v5; // al
  UFG::AudioEventProperties *v6; // rax
  unsigned int v7; // edx
  unsigned int v8; // ecx

  v2 = this->m_pController;
  v3 = durationMs;
  v4 = this;
  if ( v2 && this->m_uEventId )
  {
    if ( v2->m_pEvent )
      v2->m_pEvent = 0i64;
    this->m_pController->m_pEvent = 0i64;
    this->m_pController = 0i64;
  }
  v5 = *((_BYTE *)this + 144);
  if ( v5 >= 0 )
  {
    if ( v5 & 0x40 )
    {
      *((_BYTE *)this + 144) = v5 | 0x80;
      v6 = this->m_pProperties;
      if ( !v6
        || (v7 = v6->mData->stopEventName.mUID) == 0
        || !UFG::AudioEntity::CreateAndPlayEvent(this->m_pEntity, v7, 0i64, 0, 0i64) )
      {
        if ( !v3
          || AK::SoundEngine::ExecuteActionOnEvent(
               v4->m_uEventId,
               0,
               (unsigned __int64)v4->m_pEntity,
               v3,
               AkCurveInterpolation_Linear,
               0) != 1 )
        {
          v8 = v4->m_uPlayingId;
          if ( v8 )
          {
            if ( !UFG::WwiseInterface::smShuttingDown )
            {
              AK::SoundEngine::StopPlayingID(v8, 0, AkCurveInterpolation_Linear);
              return 1;
            }
          }
        }
      }
    }
    else
    {
      *((_BYTE *)this + 144) = v5 | 4;
    }
  }
  return 1;
}

// File Line: 343
// RVA: 0x1448F0
void __fastcall UFG::AudioEvent::Destroy(UFG::AudioEvent *this)
{
  UFG::AudioEvent *v1; // rbx
  UFG::AudioEventController *v2; // rax
  char v3; // al
  unsigned int v4; // ecx
  char v5; // al

  v1 = this;
  if ( !(*((_BYTE *)this + 144) & 8) )
  {
    v2 = this->m_pController;
    if ( v2 && this->m_uEventId )
    {
      if ( v2->m_pEvent )
        v2->m_pEvent = 0i64;
      this->m_pController->m_pEvent = 0i64;
      this->m_pController = 0i64;
    }
    v3 = *((_BYTE *)this + 144);
    if ( v3 & 0x40 )
    {
      if ( v3 >= 0 )
      {
        v4 = this->m_uPlayingId;
        if ( v4 )
        {
          if ( !UFG::WwiseInterface::smShuttingDown )
            AK::SoundEngine::StopPlayingID(v4, 0, AkCurveInterpolation_Linear);
        }
      }
    }
    v5 = *((_BYTE *)v1 + 144);
    if ( !(v5 & 0x40) && v5 >= 0 )
      *((_BYTE *)v1 + 144) = v5 | 4;
    *((_BYTE *)v1 + 144) |= 8u;
  }
}

// File Line: 364
// RVA: 0x149850
void __fastcall UFG::AudioEvent::OnControllerDestroy(UFG::AudioEvent *this)
{
  JUMPOUT(this->m_pController, 0i64, UFG::AudioEvent::Destroy);
}

// File Line: 399
// RVA: 0x14CD70
void __fastcall UFG::AudioEvent::TouchUpdate(UFG::AudioEvent *this)
{
  UFG::AudioEventProperties *v1; // rax
  UFG::AudioEventPropertyData *v2; // rdx

  v1 = this->m_pProperties;
  if ( v1 )
  {
    v2 = v1->mData;
    if ( v2->stopEventName.mUID )
      this->m_fTouchUpdateTimeout = v2->timeDelay;
  }
}

// File Line: 407
// RVA: 0x14A330
void __fastcall UFG::AudioEvent::PoolUpdate(UFG::AudioEvent *this)
{
  char v1; // al
  UFG::AudioEvent *v2; // rbx
  bool v3; // zf
  unsigned int v4; // edx
  UFG::qBaseTreeRB *v5; // rax
  unsigned int v6; // edx
  UFG::qBaseTreeRB *v7; // rax
  signed __int64 v8; // rax
  UFG::AudioEventProperties *v9; // rax
  UFG::AudioEventPropertyData *v10; // rcx
  unsigned int v11; // edx
  UFG::AudioEventProperties *v12; // rcx
  bool v13; // al
  char v14; // dl

  v1 = *((_BYTE *)this + 144);
  v2 = this;
  if ( !(v1 & 4) )
  {
    v3 = this->m_pProperties == 0i64;
    this->m_fTimeActive = UFG::Metrics::msInstance.mSimTimeDelta + this->m_fTimeActive;
    if ( !v3 )
      this->m_fTouchUpdateTimeout = this->m_fTouchUpdateTimeout - UFG::Metrics::msInstance.mSimTimeDelta;
    if ( v1 & 0x10 && !UFG::WwiseInterface::smLoadScreen )
    {
      this->vfptr->Play(this, 0);
      *((_BYTE *)v2 + 144) &= 0xEFu;
    }
    if ( *((_BYTE *)v2 + 144) & 0x20 )
    {
      v4 = v2->m_uEventId;
      if ( v4 )
      {
        v5 = UFG::qBaseTreeRB::Get(&UFG::AudioEventPropertyManager::mDatabase.mTree, v4);
        if ( v5 )
        {
          v6 = v5->mNULL.mChild[0][2].mUID;
          if ( !v6
            || (v7 = UFG::qBaseTreeRB::Get(&UFG::SoundBankManager::sm_soundBank_Tree.mTree, v6)) == 0i64
            || (v8 = (signed __int64)&v7[-1].mCount) == 0
            || !((*(_DWORD *)(v8 + 112) - 2) & 0xFFFFFFFB) )
          {
            v2->vfptr->Play(v2, 0);
            *((_BYTE *)v2 + 144) &= 0xDFu;
          }
        }
      }
    }
    v9 = v2->m_pProperties;
    if ( v9 )
    {
      if ( v2->m_fTouchUpdateTimeout < 0.0 )
      {
        v10 = v9->mData;
        v11 = v10->stopEventName.mUID;
        if ( v11 )
        {
          if ( !v10->refCounted )
          {
            UFG::AudioEvent::ReusePlay(v2, v11);
            *((_BYTE *)v2 + 145) |= 2u;
          }
        }
      }
    }
    v12 = v2->m_pProperties;
    v13 = v12 && v12->mData->stopEventName.mUID;
    v14 = *((_BYTE *)v2 + 144);
    if ( (v14 & 1 || v13 && v2->m_fTouchUpdateTimeout < -0.25)
      && (v13 && *((_BYTE *)v2 + 145) & 2 || !v12 || !v13 || !v12) )
    {
      *((_BYTE *)v2 + 144) = v14 & 0x3F;
      UFG::AudioEvent::DoCallback(v2, eAudioEventCallbackType_End);
    }
    if ( *((_BYTE *)v2 + 144) & 2 )
    {
      UFG::AudioEvent::DoCallback(v2, eAudioEventCallbackType_Marker);
      *((_BYTE *)v2 + 144) &= 0xFDu;
    }
  }
}

// File Line: 473
// RVA: 0x145D40
float __fastcall UFG::AudioEvent::GetElapsedTime(UFG::AudioEvent *this)
{
  float result; // xmm0_4
  int out_puPosition; // [rsp+30h] [rbp+8h]

  if ( AK::SoundEngine::GetSourcePlayPosition(this->m_uPlayingId, &out_puPosition, 0) == 1 )
    result = (float)out_puPosition;
  else
    result = 0.0;
  return result;
}

// File Line: 482
// RVA: 0x145D70
bool __fastcall UFG::AudioEvent::GetElapsedTime(UFG::AudioEvent *this, float *result, bool extrapolate)
{
  float *v3; // rbx
  AKRESULT v4; // eax
  int out_puPosition; // [rsp+30h] [rbp+8h]

  v3 = result;
  v4 = AK::SoundEngine::GetSourcePlayPosition(this->m_uPlayingId, &out_puPosition, extrapolate);
  if ( v4 == 1 )
    *v3 = (float)out_puPosition;
  else
    LOBYTE(v4) = 0;
  return v4;
}

// File Line: 502
// RVA: 0x140070
void __fastcall UFG::AudioDialogEvent::AudioDialogEvent(UFG::AudioDialogEvent *this, UFG::AudioEntity *pEntity, UFG::AudioEventController *pController, UFG::AudioEventInitParams *pInitParams, UFG::AudioEventExternalSourceInfo *externalSourceInfo)
{
  UFG::AudioDialogEvent *v5; // rbx

  v5 = this;
  UFG::AudioEvent::AudioEvent(
    (UFG::AudioEvent *)&this->vfptr,
    1u,
    pEntity,
    pController,
    pInitParams,
    externalSourceInfo);
  v5->vfptr = (UFG::AudioEventVtbl *)&UFG::AudioDialogEvent::`vftable';
  v5->m_uPlayingId = 0;
}

// File Line: 515
// RVA: 0x149DC0
char __fastcall UFG::AudioDialogEvent::Play(UFG::AudioDialogEvent *this, unsigned int fadeInDurationMs)
{
  UFG::AudioDialogEvent *v2; // rdi
  char result; // al
  unsigned int v4; // ebx
  UFG::AudioEventProperties *v5; // rax
  UFG::AudioEventPropertyData *v6; // rcx

  v2 = this;
  if ( UFG::WwiseInterface::smLoadScreen )
  {
    *((_BYTE *)&this->0 + 144) |= 0x10u;
    result = 1;
  }
  else if ( this->m_uPlayingId
         && (UFG::AudioEvent::DoCallback((UFG::AudioEvent *)&this->vfptr, 0),
             v4 = v2->m_uPlayingId,
             AK::SoundEngine::DynamicSequence::Play(v2->m_uPlayingId, 0, AkCurveInterpolation_Linear),
             AK::SoundEngine::DynamicSequence::Close(v4),
             v4) )
  {
    v5 = v2->m_pProperties;
    *((_BYTE *)&v2->0 + 144) |= 0x40u;
    if ( v5 )
    {
      v6 = v5->mData;
      if ( v6->stopEventName.mUID )
        v2->m_fTouchUpdateTimeout = v6->timeDelay;
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

// File Line: 539
// RVA: 0x144FE0
__int64 __fastcall UFG::AudioDialogEvent::Enqueue(UFG::AudioDialogEvent *this, UFG::DialogArgList *args, unsigned int msDelay)
{
  unsigned int v3; // esi
  UFG::AudioDialogEvent *v4; // rdi
  unsigned int v5; // ebx
  unsigned int v6; // eax
  unsigned int v7; // eax
  void **v9; // [rsp+38h] [rbp-30h]
  unsigned int in_aArgumentValues; // [rsp+40h] [rbp-28h]
  unsigned int v11; // [rsp+44h] [rbp-24h]
  unsigned int v12; // [rsp+48h] [rbp-20h]
  unsigned int v13; // [rsp+4Ch] [rbp-1Ch]
  unsigned int v14; // [rsp+50h] [rbp-18h]
  unsigned int v15; // [rsp+54h] [rbp-14h]
  unsigned int in_uNumArguments; // [rsp+58h] [rbp-10h]
  unsigned int eventId; // [rsp+5Ch] [rbp-Ch]

  v3 = msDelay;
  v4 = this;
  v9 = &UFG::DialogArgList::`vftable';
  in_aArgumentValues = args->m_args[0];
  v11 = args->m_args[1];
  v12 = args->m_args[2];
  v13 = args->m_args[3];
  v14 = args->m_args[4];
  v15 = args->m_args[5];
  in_uNumArguments = args->m_nArgs;
  eventId = args->m_uDialogEventId;
  UFG::ArgumentSequencerBase::ms_instance->vfptr->SequenceArgs(
    UFG::ArgumentSequencerBase::ms_instance,
    (UFG::DialogArgList *)&v9);
  v5 = 0;
  if ( UFG::TiDo::IsEventEnabled(UFG::TiDo::m_pInstance, eventId) )
  {
    if ( AK::SoundEngine::DynamicDialogue::ResolveDialogueEvent(eventId, &in_aArgumentValues, in_uNumArguments, 0) )
    {
      if ( v4->m_uPlayingId
        || (v6 = AK::SoundEngine::DynamicSequence::Open(
                   (unsigned __int64)v4->m_pEntity,
                   0x10005u,
                   UFG::WwiseInterface::WwiseEndEventCallback,
                   v4,
                   0),
            (v4->m_uPlayingId = v6) != 0) )
      {
        if ( UFG::TiDo::IsEventEnabled(UFG::TiDo::m_pInstance, eventId)
          && (unsigned __int8)AK::SoundEngine::IsInitialized() )
        {
          v7 = AK::SoundEngine::DynamicDialogue::ResolveDialogueEvent(eventId, &in_aArgumentValues, in_uNumArguments, 0);
          v5 = UFG::WwiseInterface::Enqueue(v4, v7, v3);
        }
      }
    }
  }
  return v5;
}

// File Line: 559
// RVA: 0x145220
unsigned int __fastcall UFG::AudioDialogEvent::EnqueueExternal(UFG::AudioDialogEvent *this, unsigned int nodeId, UFG::AudioEventExternalSourceInfo *info, unsigned int msDelay)
{
  unsigned int v4; // edi
  UFG::AudioEventExternalSourceInfo *v5; // rsi
  unsigned int v6; // ebp
  UFG::AudioDialogEvent *v7; // rbx
  unsigned int v8; // ecx
  unsigned int result; // eax

  v4 = msDelay;
  v5 = info;
  v6 = nodeId;
  v7 = this;
  if ( !this->m_uPlayingId )
    this->m_uPlayingId = AK::SoundEngine::DynamicSequence::Open(
                           (unsigned __int64)this->m_pEntity,
                           0x10005u,
                           UFG::WwiseInterface::WwiseEndEventCallback,
                           this,
                           0);
  v8 = v7->m_uPlayingId;
  if ( v8 )
    result = UFG::WwiseInterface::EnqueueExternal(v8, v6, v5, v4);
  else
    result = 0;
  return result;
}

// File Line: 583
// RVA: 0x14655C0
__int64 UFG::_dynamic_initializer_for__gAudioEventCallbackObjectPool__()
{
  UFG::qFixedAllocator::qFixedAllocator(&UFG::gAudioEventCallbackObjectPool);
  return atexit(UFG::_dynamic_atexit_destructor_for__gAudioEventCallbackObjectPool__);
}

// File Line: 584
// RVA: 0x14655E0
__int64 UFG::_dynamic_initializer_for__gAudioEventPool__()
{
  UFG::qFixedAllocator::qFixedAllocator(&UFG::gAudioEventPool);
  return atexit(UFG::_dynamic_atexit_destructor_for__gAudioEventPool__);
}

// File Line: 586
// RVA: 0x14652C0
__int64 dynamic_initializer_for__UFG::AudioEventManager::sm_orphanEventList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::AudioEventManager::sm_orphanEventList__);
}

// File Line: 587
// RVA: 0x1465060
__int64 dynamic_initializer_for__UFG::AudioEventManager::sm_allEventsList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::AudioEventManager::sm_allEventsList__);
}

// File Line: 608
// RVA: 0x14E5A0
void __fastcall UFG::AudioEventManager::UpdateEventList(UFG::qList<UFG::AudioEvent,UFG::AudioEvent,1,0> *events)
{
  UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> **v1; // rdi
  UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> **v2; // rbx
  char v3; // al
  UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> **v4; // rcx

  v1 = &events[-1].mNode.mNext;
  v2 = &events->mNode.mNext[-1].mNext;
  if ( v2 != &events[-1].mNode.mNext )
  {
    do
    {
      if ( v2[13] )
        UFG::AudioEvent::PoolUpdate((UFG::AudioEvent *)v2);
      v3 = *((_BYTE *)v2 + 144);
      if ( v3 & 4 || v3 & 1 && *((float *)v2 + 34) <= 0.0 )
      {
        v4 = v2;
        v2 = &v2[2][-1].mNext;
        if ( v4 )
          ((void (__fastcall *)(UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> **, signed __int64))(*v4)->mPrev)(v4, 1i64);
      }
      else
      {
        v2 = &v2[2][-1].mNext;
      }
    }
    while ( v2 != v1 );
  }
}

// File Line: 667
// RVA: 0x143E00
__int64 __fastcall UFG::AudioEventManager::CountIdPlaying(unsigned int id)
{
  void **v1; // rax
  UFG::qSNode<UFG::AudioEvent,UFG::AudioEvent> *v2; // rbx
  UFG::qSNode<UFG::AudioEvent,UFG::AudioEvent> *v3; // rbx
  void **v5; // [rsp+20h] [rbp-18h]
  unsigned int v6; // [rsp+28h] [rbp-10h]
  unsigned int v7; // [rsp+2Ch] [rbp-Ch]

  v1 = &UFG::IsIdPlayingFunctor::`vftable';
  v7 = 0;
  v5 = &UFG::IsIdPlayingFunctor::`vftable';
  v6 = id;
  if ( !UFG::AudioEventManager::sm_allEventsList.mHead )
    return 0i64;
  v2 = UFG::AudioEventManager::sm_allEventsList.mHead - 3;
  if ( UFG::AudioEventManager::sm_allEventsList.mHead == (UFG::qSNode<UFG::AudioEvent,UFG::AudioEvent> *)24 )
    return 0i64;
  while ( 1 )
  {
    ((void (__fastcall *)(void ***, UFG::qSNode<UFG::AudioEvent,UFG::AudioEvent> *))*v1)(&v5, v2);
    v3 = v2[3].mNext;
    if ( !v3 )
      break;
    v2 = v3 - 3;
    if ( !v2 )
      break;
    v1 = v5;
  }
  return v7;
}

// File Line: 677
// RVA: 0x1457F0
UFG::AudioEvent *__fastcall UFG::AudioEventManager::FindOldestEvent(unsigned int id)
{
  void **v1; // rax
  UFG::qSNode<UFG::AudioEvent,UFG::AudioEvent> *v2; // rbx
  UFG::qSNode<UFG::AudioEvent,UFG::AudioEvent> *v3; // rbx
  void **v5; // [rsp+20h] [rbp-28h]
  unsigned int v6; // [rsp+28h] [rbp-20h]
  __int64 v7; // [rsp+30h] [rbp-18h]

  v1 = &UFG::FindOldestEventFunctor::`vftable';
  v7 = 0i64;
  v5 = &UFG::FindOldestEventFunctor::`vftable';
  v6 = id;
  if ( !UFG::AudioEventManager::sm_allEventsList.mHead )
    return 0i64;
  v2 = UFG::AudioEventManager::sm_allEventsList.mHead - 3;
  if ( UFG::AudioEventManager::sm_allEventsList.mHead == (UFG::qSNode<UFG::AudioEvent,UFG::AudioEvent> *)24 )
    return 0i64;
  while ( 1 )
  {
    ((void (__fastcall *)(void ***, UFG::qSNode<UFG::AudioEvent,UFG::AudioEvent> *))*v1)(&v5, v2);
    v3 = v2[3].mNext;
    if ( !v3 )
      break;
    v2 = v3 - 3;
    if ( !v2 )
      break;
    v1 = v5;
  }
  return (UFG::AudioEvent *)v7;
}

