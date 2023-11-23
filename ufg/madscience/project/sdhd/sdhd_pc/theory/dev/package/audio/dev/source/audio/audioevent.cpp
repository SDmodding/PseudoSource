// File Line: 86
// RVA: 0x140420
void __fastcall UFG::AudioEvent::AudioEvent(
        UFG::AudioEvent *this,
        unsigned int uEventId,
        UFG::AudioEntity *pEntity,
        UFG::AudioEventController *pController,
        UFG::AudioEventInitParams *pInitParams,
        UFG::AudioEventExternalSourceInfo *pExternalInfo)
{
  UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> *v7; // r11
  UFG::qSNode<UFG::AudioEvent,UFG::AudioEvent> *v8; // rbx
  int v9; // eax
  UFG::qSList<UFG::AudioEvent,UFG::AudioEvent,1> *v10; // rcx
  UFG::AudioEntity *m_pEntity; // rcx
  UFG::qList<UFG::AudioEvent,UFG::AudioEvent,1,0> *p_m_events; // rcx
  UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> *mPrev; // rax
  __int64 v14; // [rsp+18h] [rbp-10h]

  v7 = &this->UFG::qNode<UFG::AudioEvent,UFG::AudioEvent>;
  this->mPrev = &this->UFG::qNode<UFG::AudioEvent,UFG::AudioEvent>;
  this->UFG::qNode<UFG::AudioEvent,UFG::AudioEvent>::mNext = &this->UFG::qNode<UFG::AudioEvent,UFG::AudioEvent>;
  v8 = &this->UFG::qSNode<UFG::AudioEvent,UFG::AudioEvent>;
  this->UFG::qSNode<UFG::AudioEvent,UFG::AudioEvent>::mNext = 0i64;
  this->vfptr = (UFG::AudioEventVtbl *)&UFG::AudioEvent::`vftable;
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
    this->m_InitParams = *pInitParams;
  if ( pController )
  {
    pController->m_pEvent = this;
    this->m_pController = pController;
  }
  m_pEntity = this->m_pEntity;
  if ( m_pEntity )
  {
    p_m_events = &m_pEntity->m_events;
    mPrev = p_m_events->mNode.mPrev;
    mPrev->mNext = v7;
    v7->mPrev = mPrev;
    v7->mNext = &p_m_events->mNode;
    p_m_events->mNode.mPrev = v7;
  }
}

// File Line: 108
// RVA: 0x144F60
void __fastcall UFG::AudioEvent::DoCallback(UFG::AudioEvent *this, unsigned int callbackType)
{
  UFG::AudioEntity *m_pEntity; // rdx
  void (__fastcall *m_EventPlayEndCallback)(UFG::AudioEntity *, UFG::eAudioEventCallbackType, UFG::AudioEvent *, void *); // rax
  UFG::AudioEventCallbackObject *i; // rbx

  m_pEntity = this->m_pEntity;
  if ( m_pEntity )
  {
    m_EventPlayEndCallback = this->m_InitParams.m_EventPlayEndCallback;
    if ( m_EventPlayEndCallback )
      m_EventPlayEndCallback(
        (UFG::AudioEntity *)((char *)m_pEntity + *(int *)this->m_InitParams.gap8),
        (UFG::eAudioEventCallbackType)callbackType,
        this,
        this->m_InitParams.m_EventCallbackUserData);
  }
  if ( this->m_pEntity )
  {
    for ( i = this->m_callbackObject; i; i = i->m_next )
      i->vfptr->Do(i, this, (UFG::eAudioEventCallbackType)callbackType);
  }
}

// File Line: 119
// RVA: 0x142870
void __fastcall UFG::AudioEvent::AddCallback(UFG::AudioEvent *this, UFG::AudioEventCallbackObject *eventCallback)
{
  UFG::AudioEventCallbackObject *m_callbackObject; // rax

  m_callbackObject = this->m_callbackObject;
  if ( m_callbackObject )
  {
    while ( m_callbackObject->m_next )
      m_callbackObject = m_callbackObject->m_next;
    m_callbackObject->m_next = eventCallback;
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
  UFG::AudioEventExternalSourceInfo *m_externalInfo; // rcx
  UFG::AudioEventController *m_pController; // rax
  UFG::AudioEventCallbackObject *m_callbackObject; // rdi
  UFG::AudioEventCallbackObject *v5; // rcx
  UFG::qSNode<UFG::AudioEvent,UFG::AudioEvent> *v6; // rdx
  UFG::qSList<UFG::AudioEvent,UFG::AudioEvent,1> *v7; // rcx
  UFG::qSNode<UFG::AudioEvent,UFG::AudioEvent> *mHead; // rax
  UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> *mPrev; // rcx
  UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> *mNext; // rax

  this->vfptr = (UFG::AudioEventVtbl *)&UFG::AudioEvent::`vftable;
  m_externalInfo = this->m_externalInfo;
  if ( m_externalInfo )
    m_externalInfo->vfptr->__vecDelDtor(m_externalInfo, 1u);
  m_pController = this->m_pController;
  if ( m_pController && this->m_uEventId )
  {
    if ( m_pController->m_pEvent )
      m_pController->m_pEvent = 0i64;
    this->m_pController->m_pEvent = 0i64;
    this->m_pController = 0i64;
  }
  if ( this->m_uPlayingId && (*((_BYTE *)this + 144) & 0x40) != 0 )
    UFG::AudioEvent::DoCallback(this, eAudioEventCallbackType_End);
  m_callbackObject = this->m_callbackObject;
  while ( m_callbackObject )
  {
    v5 = m_callbackObject;
    m_callbackObject = m_callbackObject->m_next;
    v5->vfptr->__vecDelDtor(v5, 1u);
  }
  this->m_callbackObject = 0i64;
  v6 = &this->UFG::qSNode<UFG::AudioEvent,UFG::AudioEvent>;
  v7 = &UFG::AudioEventManager::sm_allEventsList;
  if ( UFG::AudioEventManager::sm_allEventsList.mHead )
  {
    while ( 1 )
    {
      mHead = v7->mHead;
      if ( v7->mHead == v6 )
        break;
      v7 = (UFG::qSList<UFG::AudioEvent,UFG::AudioEvent,1> *)v7->mHead;
      if ( !mHead->mNext )
        goto LABEL_18;
    }
    v7->mHead = v6->mNext;
    v6->mNext = 0i64;
  }
LABEL_18:
  mPrev = this->mPrev;
  mNext = this->UFG::qNode<UFG::AudioEvent,UFG::AudioEvent>::mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = &this->UFG::qNode<UFG::AudioEvent,UFG::AudioEvent>;
  this->UFG::qNode<UFG::AudioEvent,UFG::AudioEvent>::mNext = &this->UFG::qNode<UFG::AudioEvent,UFG::AudioEvent>;
}

// File Line: 146
// RVA: 0x149E50
char __fastcall UFG::AudioEvent::Play(UFG::AudioEvent *this, int fadeInDurationMs)
{
  unsigned int m_uEventId; // edx
  UFG::qBaseTreeRB *v6; // rax
  UFG::qBaseNodeRB *v7; // rdi
  unsigned int mUID; // edx
  UFG::qBaseTreeRB *v9; // rax
  int *p_mCount; // rax
  unsigned int v11; // edx
  UFG::qBaseTreeRB *v12; // rax
  int *v13; // rax
  unsigned int v14; // edx
  UFG::AudioEventProperties *v15; // rax
  UFG::AudioEvent *OldestEvent; // rax
  UFG::AudioEventProperties *m_pProperties; // rcx
  UFG::AudioEventPropertyData *mData; // rdx
  unsigned int v19; // eax
  UFG::AudioEventProperties *v20; // rax
  UFG::AudioEventPropertyData *v21; // rax

  if ( UFG::WwiseInterface::smLoadScreen )
  {
    *((_BYTE *)this + 144) |= 0x10u;
    return 1;
  }
  m_uEventId = this->m_uEventId;
  if ( m_uEventId )
  {
    v6 = UFG::qBaseTreeRB::Get(&UFG::AudioEventPropertyManager::mDatabase.mTree, m_uEventId);
    if ( v6 )
    {
      v7 = v6->mNULL.mChild[0];
      mUID = v7[2].mUID;
      if ( mUID )
      {
        v9 = UFG::qBaseTreeRB::Get(&UFG::SoundBankManager::sm_soundBank_Tree.mTree, mUID);
        if ( v9 )
        {
          p_mCount = &v9[-1].mCount;
          if ( p_mCount )
          {
            if ( p_mCount[19] )
            {
              v11 = v7[2].mUID;
              if ( v11 )
              {
                v12 = UFG::qBaseTreeRB::Get(&UFG::SoundBankManager::sm_soundBank_Tree.mTree, v11);
                if ( v12 )
                {
                  v13 = &v12[-1].mCount;
                  if ( v13 )
                  {
                    if ( ((v13[28] - 2) & 0xFFFFFFFB) != 0 )
                    {
                      *((_BYTE *)this + 144) |= 0x20u;
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
  v14 = this->m_uEventId;
  if ( v14 )
    v15 = (UFG::AudioEventProperties *)UFG::qBaseTreeRB::Get(&UFG::AudioEventPropertyManager::mDatabase.mTree, v14);
  else
    v15 = 0i64;
  this->m_pProperties = v15;
  if ( v15 )
  {
    if ( v15->mData->maxSimultaneous > 0
      && (int)UFG::AudioEventManager::CountIdPlaying(this->m_uEventId) >= this->m_pProperties->mData->maxSimultaneous )
    {
      OldestEvent = UFG::AudioEventManager::FindOldestEvent(this->m_uEventId);
      if ( OldestEvent )
      {
        m_pProperties = OldestEvent->m_pProperties;
        if ( m_pProperties )
        {
          mData = m_pProperties->mData;
          if ( mData->stopEventName.mUID )
            OldestEvent->m_fTouchUpdateTimeout = mData->timeDelay;
        }
      }
      return 0;
    }
    if ( this->m_pProperties->mData->dontOcclude )
    {
      this->m_pEntity->m_bSetOcclusionOverride = 1;
      UFG::AudioEntity::SetObstructionAndOcclusionTargets(this->m_pEntity, 0.0, 0.0, 1);
    }
  }
  if ( UFG::TiDo::IsEventEnabled(UFG::TiDo::m_pInstance, this->m_uEventId) )
    v19 = (unsigned int)UFG::WwiseInterface::PlayEvent(this);
  else
    v19 = 0;
  this->m_uPlayingId = v19;
  if ( !v19 )
    return 0;
  *((_BYTE *)this + 144) |= 0x40u;
  UFG::AudioEvent::DoCallback(this, 0);
  v20 = this->m_pProperties;
  if ( v20 )
  {
    v21 = v20->mData;
    if ( v21->stopEventName.mUID )
      this->m_fTouchUpdateTimeout = v21->timeDelay;
  }
  if ( fadeInDurationMs )
  {
    AK::SoundEngine::ExecuteActionOnEvent(
      this->m_uEventId,
      AkActionOnEventType_Pause,
      (unsigned __int64)this->m_pEntity,
      0,
      AkCurveInterpolation_Linear,
      0);
    AK::SoundEngine::ExecuteActionOnEvent(
      this->m_uEventId,
      AkActionOnEventType_Resume,
      (unsigned __int64)this->m_pEntity,
      fadeInDurationMs,
      AkCurveInterpolation_Linear,
      0);
  }
  return 1;
}

// File Line: 224
// RVA: 0x149D70
void __fastcall UFG::AudioEvent::Pause(UFG::AudioEvent *this, int fadeOutDurationMs)
{
  if ( (*((_BYTE *)this + 144) & 0x40) != 0 )
  {
    AK::SoundEngine::ExecuteActionOnEvent(
      this->m_uEventId,
      AkActionOnEventType_Pause,
      (unsigned __int64)this->m_pEntity,
      fadeOutDurationMs,
      AkCurveInterpolation_Linear,
      0);
    *((_BYTE *)this + 145) |= 1u;
  }
}

// File Line: 233
// RVA: 0x14B640
void __fastcall UFG::AudioEvent::Resume(UFG::AudioEvent *this, int fadeInDurationMs)
{
  if ( (*((_BYTE *)this + 145) & 1) != 0 )
  {
    AK::SoundEngine::ExecuteActionOnEvent(
      this->m_uEventId,
      AkActionOnEventType_Resume,
      (unsigned __int64)this->m_pEntity,
      fadeInDurationMs,
      AkCurveInterpolation_Linear,
      0);
    *((_BYTE *)this + 145) &= ~1u;
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
  UFG::AudioEventProperties *v3; // rdi
  UFG::qBaseTreeRB *v6; // rax
  unsigned int mUID; // edx
  UFG::qBaseTreeRB *v8; // rax
  int *p_mCount; // rax
  unsigned int v10; // eax
  unsigned int m_uEventId; // edx
  UFG::AudioEventPropertyData *mData; // rax

  *((_BYTE *)this + 144) &= 0xC2u;
  v2 = *((_BYTE *)this + 144);
  v3 = 0i64;
  this->m_pProperties = 0i64;
  *(_QWORD *)&this->m_fTouchUpdateTimeout = 0i64;
  this->m_uEventId = uEventId;
  if ( UFG::WwiseInterface::smLoadScreen )
  {
    *((_BYTE *)this + 144) = v2 | 0x10;
    return 1;
  }
  else if ( uEventId
         && (v6 = UFG::qBaseTreeRB::Get(&UFG::AudioEventPropertyManager::mDatabase.mTree, uEventId)) != 0i64
         && (mUID = v6->mNULL.mChild[0][2].mUID) != 0
         && (v8 = UFG::qBaseTreeRB::Get(&UFG::SoundBankManager::sm_soundBank_Tree.mTree, mUID)) != 0i64
         && (p_mCount = &v8[-1].mCount) != 0i64
         && p_mCount[19] )
  {
    *((_BYTE *)this + 144) |= 0x20u;
    return 1;
  }
  else
  {
    UFG::AudioEvent::DoCallback(this, 0);
    if ( UFG::TiDo::IsEventEnabled(UFG::TiDo::m_pInstance, this->m_uEventId)
      && (v10 = (unsigned int)UFG::WwiseInterface::PlayEvent(this)) != 0 )
    {
      m_uEventId = this->m_uEventId;
      *((_BYTE *)this + 144) |= 0x40u;
      this->m_uPlayingId = v10;
      if ( m_uEventId )
        v3 = (UFG::AudioEventProperties *)UFG::qBaseTreeRB::Get(
                                            &UFG::AudioEventPropertyManager::mDatabase.mTree,
                                            m_uEventId);
      this->m_pProperties = v3;
      if ( v3 )
      {
        mData = v3->mData;
        if ( mData->stopEventName.mUID )
          this->m_fTouchUpdateTimeout = mData->timeDelay;
      }
      return 1;
    }
    else
    {
      *((_BYTE *)this + 144) &= ~0x40u;
      return 0;
    }
  }
}

// File Line: 307
// RVA: 0x14CB70
char __fastcall UFG::AudioEvent::StopAndForget(UFG::AudioEvent *this, int durationMs)
{
  UFG::AudioEventController *m_pController; // rax
  char v5; // al
  UFG::AudioEventProperties *m_pProperties; // rax
  unsigned int mUID; // edx
  unsigned int m_uPlayingId; // ecx

  m_pController = this->m_pController;
  if ( m_pController && this->m_uEventId )
  {
    if ( m_pController->m_pEvent )
      m_pController->m_pEvent = 0i64;
    this->m_pController->m_pEvent = 0i64;
    this->m_pController = 0i64;
  }
  v5 = *((_BYTE *)this + 144);
  if ( v5 >= 0 )
  {
    if ( (v5 & 0x40) != 0 )
    {
      *((_BYTE *)this + 144) = v5 | 0x80;
      m_pProperties = this->m_pProperties;
      if ( (!m_pProperties
         || (mUID = m_pProperties->mData->stopEventName.mUID) == 0
         || !UFG::AudioEntity::CreateAndPlayEvent(this->m_pEntity, mUID, 0i64, 0, 0i64))
        && (!durationMs
         || AK::SoundEngine::ExecuteActionOnEvent(
              this->m_uEventId,
              AkActionOnEventType_Stop,
              (unsigned __int64)this->m_pEntity,
              durationMs,
              AkCurveInterpolation_Linear,
              0) != AK_Success) )
      {
        m_uPlayingId = this->m_uPlayingId;
        if ( m_uPlayingId )
        {
          if ( !UFG::WwiseInterface::smShuttingDown )
          {
            AK::SoundEngine::StopPlayingID(m_uPlayingId, 0, AkCurveInterpolation_Linear);
            return 1;
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
  UFG::AudioEventController *m_pController; // rax
  char v3; // al
  unsigned int m_uPlayingId; // ecx
  char v5; // al

  if ( (*((_BYTE *)this + 144) & 8) == 0 )
  {
    m_pController = this->m_pController;
    if ( m_pController && this->m_uEventId )
    {
      if ( m_pController->m_pEvent )
        m_pController->m_pEvent = 0i64;
      this->m_pController->m_pEvent = 0i64;
      this->m_pController = 0i64;
    }
    v3 = *((_BYTE *)this + 144);
    if ( (v3 & 0x40) != 0 && v3 >= 0 )
    {
      m_uPlayingId = this->m_uPlayingId;
      if ( m_uPlayingId )
      {
        if ( !UFG::WwiseInterface::smShuttingDown )
          AK::SoundEngine::StopPlayingID(m_uPlayingId, 0, AkCurveInterpolation_Linear);
      }
    }
    v5 = *((_BYTE *)this + 144);
    if ( (v5 & 0x40) == 0 && v5 >= 0 )
      *((_BYTE *)this + 144) = v5 | 4;
    *((_BYTE *)this + 144) |= 8u;
  }
}

// File Line: 364
// RVA: 0x149850
void __fastcall UFG::AudioEvent::OnControllerDestroy(UFG::AudioEvent *this)
{
  if ( this->m_pController )
    UFG::AudioEvent::Destroy(this);
}

// File Line: 399
// RVA: 0x14CD70
void __fastcall UFG::AudioEvent::TouchUpdate(UFG::AudioEvent *this)
{
  UFG::AudioEventProperties *m_pProperties; // rax
  UFG::AudioEventPropertyData *mData; // rdx

  m_pProperties = this->m_pProperties;
  if ( m_pProperties )
  {
    mData = m_pProperties->mData;
    if ( mData->stopEventName.mUID )
      this->m_fTouchUpdateTimeout = mData->timeDelay;
  }
}

// File Line: 407
// RVA: 0x14A330
void __fastcall UFG::AudioEvent::PoolUpdate(UFG::AudioEvent *this)
{
  char v1; // al
  bool v3; // zf
  unsigned int m_uEventId; // edx
  UFG::qBaseTreeRB *v5; // rax
  unsigned int mUID; // edx
  UFG::qBaseTreeRB *v7; // rax
  int *p_mCount; // rax
  UFG::AudioEventProperties *m_pProperties; // rax
  UFG::AudioEventPropertyData *mData; // rcx
  unsigned int v11; // edx
  UFG::AudioEventProperties *v12; // rcx
  bool v13; // al
  char v14; // dl

  v1 = *((_BYTE *)this + 144);
  if ( (v1 & 4) == 0 )
  {
    v3 = this->m_pProperties == 0i64;
    this->m_fTimeActive = UFG::Metrics::msInstance.mSimTimeDelta + this->m_fTimeActive;
    if ( !v3 )
      this->m_fTouchUpdateTimeout = this->m_fTouchUpdateTimeout - UFG::Metrics::msInstance.mSimTimeDelta;
    if ( (v1 & 0x10) != 0 && !UFG::WwiseInterface::smLoadScreen )
    {
      this->vfptr->Play(this, 0);
      *((_BYTE *)this + 144) &= ~0x10u;
    }
    if ( (*((_BYTE *)this + 144) & 0x20) != 0 )
    {
      m_uEventId = this->m_uEventId;
      if ( m_uEventId )
      {
        v5 = UFG::qBaseTreeRB::Get(&UFG::AudioEventPropertyManager::mDatabase.mTree, m_uEventId);
        if ( v5 )
        {
          mUID = v5->mNULL.mChild[0][2].mUID;
          if ( !mUID
            || (v7 = UFG::qBaseTreeRB::Get(&UFG::SoundBankManager::sm_soundBank_Tree.mTree, mUID)) == 0i64
            || (p_mCount = &v7[-1].mCount) == 0i64
            || ((p_mCount[28] - 2) & 0xFFFFFFFB) == 0 )
          {
            this->vfptr->Play(this, 0);
            *((_BYTE *)this + 144) &= ~0x20u;
          }
        }
      }
    }
    m_pProperties = this->m_pProperties;
    if ( m_pProperties )
    {
      if ( this->m_fTouchUpdateTimeout < 0.0 )
      {
        mData = m_pProperties->mData;
        v11 = mData->stopEventName.mUID;
        if ( v11 )
        {
          if ( !mData->refCounted )
          {
            UFG::AudioEvent::ReusePlay(this, v11);
            *((_BYTE *)this + 145) |= 2u;
          }
        }
      }
    }
    v12 = this->m_pProperties;
    v13 = v12 && v12->mData->stopEventName.mUID;
    v14 = *((_BYTE *)this + 144);
    if ( ((v14 & 1) != 0 || v13 && this->m_fTouchUpdateTimeout < -0.25)
      && (v13 && (*((_BYTE *)this + 145) & 2) != 0 || !v12 || !v13) )
    {
      *((_BYTE *)this + 144) = v14 & 0x3F;
      UFG::AudioEvent::DoCallback(this, 2u);
    }
    if ( (*((_BYTE *)this + 144) & 2) != 0 )
    {
      UFG::AudioEvent::DoCallback(this, 3u);
      *((_BYTE *)this + 144) &= ~2u;
    }
  }
}

// File Line: 473
// RVA: 0x145D40
float __fastcall UFG::AudioEvent::GetElapsedTime(UFG::AudioEvent *this)
{
  int out_puPosition; // [rsp+30h] [rbp+8h] BYREF

  if ( AK::SoundEngine::GetSourcePlayPosition(this->m_uPlayingId, &out_puPosition, 0) == AK_Success )
    return (float)out_puPosition;
  else
    return 0.0;
}

// File Line: 482
// RVA: 0x145D70
bool __fastcall UFG::AudioEvent::GetElapsedTime(UFG::AudioEvent *this, float *result, bool extrapolate)
{
  AKRESULT SourcePlayPosition; // eax
  int out_puPosition; // [rsp+30h] [rbp+8h] BYREF

  SourcePlayPosition = AK::SoundEngine::GetSourcePlayPosition(this->m_uPlayingId, &out_puPosition, extrapolate);
  if ( SourcePlayPosition == AK_Success )
    *result = (float)out_puPosition;
  else
    LOBYTE(SourcePlayPosition) = 0;
  return SourcePlayPosition;
}

// File Line: 502
// RVA: 0x140070
void __fastcall UFG::AudioDialogEvent::AudioDialogEvent(
        UFG::AudioDialogEvent *this,
        UFG::AudioEntity *pEntity,
        UFG::AudioEventController *pController,
        UFG::AudioEventInitParams *pInitParams,
        UFG::AudioEventExternalSourceInfo *externalSourceInfo)
{
  UFG::AudioEvent::AudioEvent(this, 1u, pEntity, pController, pInitParams, externalSourceInfo);
  this->vfptr = (UFG::AudioEventVtbl *)&UFG::AudioDialogEvent::`vftable;
  this->m_uPlayingId = 0;
}

// File Line: 515
// RVA: 0x149DC0
char __fastcall UFG::AudioDialogEvent::Play(UFG::AudioDialogEvent *this, unsigned int fadeInDurationMs)
{
  unsigned int m_uPlayingId; // ebx
  UFG::AudioEventProperties *m_pProperties; // rax
  UFG::AudioEventPropertyData *mData; // rcx

  if ( UFG::WwiseInterface::smLoadScreen )
  {
    *((_BYTE *)&this->UFG::AudioEvent + 144) |= 0x10u;
    return 1;
  }
  else if ( this->m_uPlayingId
         && (UFG::AudioEvent::DoCallback(this, 0),
             m_uPlayingId = this->m_uPlayingId,
             AK::SoundEngine::DynamicSequence::Play(m_uPlayingId, 0, AkCurveInterpolation_Linear),
             AK::SoundEngine::DynamicSequence::Close(m_uPlayingId),
             m_uPlayingId) )
  {
    m_pProperties = this->m_pProperties;
    *((_BYTE *)&this->UFG::AudioEvent + 144) |= 0x40u;
    if ( m_pProperties )
    {
      mData = m_pProperties->mData;
      if ( mData->stopEventName.mUID )
        this->m_fTouchUpdateTimeout = mData->timeDelay;
    }
    return 1;
  }
  else
  {
    return 0;
  }
}

// File Line: 539
// RVA: 0x144FE0
__int64 __fastcall UFG::AudioDialogEvent::Enqueue(
        UFG::AudioDialogEvent *this,
        UFG::DialogArgList *args,
        unsigned int msDelay)
{
  unsigned int v5; // ebx
  unsigned int v6; // eax
  unsigned int v7; // eax
  void **v9; // [rsp+38h] [rbp-30h] BYREF
  unsigned int in_aArgumentValues[6]; // [rsp+40h] [rbp-28h] BYREF
  unsigned int in_uNumArguments; // [rsp+58h] [rbp-10h]
  unsigned int eventId; // [rsp+5Ch] [rbp-Ch]

  v9 = &UFG::DialogArgList::`vftable;
  in_aArgumentValues[0] = args->m_args[0];
  in_aArgumentValues[1] = args->m_args[1];
  in_aArgumentValues[2] = args->m_args[2];
  in_aArgumentValues[3] = args->m_args[3];
  in_aArgumentValues[4] = args->m_args[4];
  in_aArgumentValues[5] = args->m_args[5];
  in_uNumArguments = args->m_nArgs;
  eventId = args->m_uDialogEventId;
  UFG::ArgumentSequencerBase::ms_instance->vfptr->SequenceArgs(
    UFG::ArgumentSequencerBase::ms_instance,
    (UFG::DialogArgList *)&v9);
  v5 = 0;
  if ( UFG::TiDo::IsEventEnabled(UFG::TiDo::m_pInstance, eventId) )
  {
    if ( AK::SoundEngine::DynamicDialogue::ResolveDialogueEvent(eventId, in_aArgumentValues, in_uNumArguments, 0) )
    {
      if ( this->m_uPlayingId
        || (v6 = AK::SoundEngine::DynamicSequence::Open(
                   (unsigned __int64)this->m_pEntity,
                   0x10005u,
                   UFG::WwiseInterface::WwiseEndEventCallback,
                   this,
                   DynamicSequenceType_SampleAccurate),
            (this->m_uPlayingId = v6) != 0) )
      {
        if ( UFG::TiDo::IsEventEnabled(UFG::TiDo::m_pInstance, eventId) && AK::SoundEngine::IsInitialized() )
        {
          v7 = AK::SoundEngine::DynamicDialogue::ResolveDialogueEvent(eventId, in_aArgumentValues, in_uNumArguments, 0);
          return UFG::WwiseInterface::Enqueue(this, v7, msDelay);
        }
      }
    }
  }
  return v5;
}

// File Line: 559
// RVA: 0x145220
unsigned int __fastcall UFG::AudioDialogEvent::EnqueueExternal(
        UFG::AudioDialogEvent *this,
        unsigned int nodeId,
        UFG::AudioEventExternalSourceInfo *info,
        unsigned int msDelay)
{
  unsigned int m_uPlayingId; // ecx

  if ( !this->m_uPlayingId )
    this->m_uPlayingId = AK::SoundEngine::DynamicSequence::Open(
                           (unsigned __int64)this->m_pEntity,
                           0x10005u,
                           UFG::WwiseInterface::WwiseEndEventCallback,
                           this,
                           DynamicSequenceType_SampleAccurate);
  m_uPlayingId = this->m_uPlayingId;
  if ( m_uPlayingId )
    return UFG::WwiseInterface::EnqueueExternal(m_uPlayingId, nodeId, info, msDelay);
  else
    return 0;
}

// File Line: 583
// RVA: 0x14655C0
__int64 UFG::_dynamic_initializer_for__gAudioEventCallbackObjectPool__()
{
  UFG::qFixedAllocator::qFixedAllocator(&UFG::gAudioEventCallbackObjectPool);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gAudioEventCallbackObjectPool__);
}

// File Line: 584
// RVA: 0x14655E0
__int64 UFG::_dynamic_initializer_for__gAudioEventPool__()
{
  UFG::qFixedAllocator::qFixedAllocator(&UFG::gAudioEventPool);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gAudioEventPool__);
}

// File Line: 586
// RVA: 0x14652C0
__int64 dynamic_initializer_for__UFG::AudioEventManager::sm_orphanEventList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::AudioEventManager::sm_orphanEventList__);
}

// File Line: 587
// RVA: 0x1465060
__int64 dynamic_initializer_for__UFG::AudioEventManager::sm_allEventsList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::AudioEventManager::sm_allEventsList__);
}

// File Line: 608
// RVA: 0x14E5A0
void __fastcall UFG::AudioEventManager::UpdateEventList(UFG::qList<UFG::AudioEvent,UFG::AudioEvent,1,0> *events)
{
  UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> **p_mNext; // rdi
  UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> **v2; // rbx
  char v3; // al
  UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> **v4; // rcx

  p_mNext = &events[-1].mNode.mNext;
  v2 = &events->mNode.mNext[-1].mNext;
  if ( v2 != &events[-1].mNode.mNext )
  {
    do
    {
      if ( v2[13] )
        UFG::AudioEvent::PoolUpdate((UFG::AudioEvent *)v2);
      v3 = *((_BYTE *)v2 + 144);
      if ( (v3 & 4) != 0 || (v3 & 1) != 0 && *((float *)v2 + 34) <= 0.0 )
      {
        v4 = v2;
        v2 = &v2[2][-1].mNext;
        if ( v4 )
          ((void (__fastcall *)(UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> **, __int64))(*v4)->mPrev)(v4, 1i64);
      }
      else
      {
        v2 = &v2[2][-1].mNext;
      }
    }
    while ( v2 != p_mNext );
  }
}

// File Line: 667
// RVA: 0x143E00
__int64 __fastcall UFG::AudioEventManager::CountIdPlaying(unsigned int id)
{
  void **v1; // rax
  UFG::qSNode<UFG::AudioEvent,UFG::AudioEvent> *v2; // rbx
  UFG::qSNode<UFG::AudioEvent,UFG::AudioEvent> *mNext; // rbx
  void **v5; // [rsp+20h] [rbp-18h] BYREF
  unsigned int v6; // [rsp+28h] [rbp-10h]
  unsigned int v7; // [rsp+2Ch] [rbp-Ch]

  v1 = &UFG::IsIdPlayingFunctor::`vftable;
  v7 = 0;
  v5 = &UFG::IsIdPlayingFunctor::`vftable;
  v6 = id;
  if ( !UFG::AudioEventManager::sm_allEventsList.mHead )
    return 0i64;
  v2 = UFG::AudioEventManager::sm_allEventsList.mHead - 3;
  if ( UFG::AudioEventManager::sm_allEventsList.mHead == (UFG::qSNode<UFG::AudioEvent,UFG::AudioEvent> *)24 )
    return 0i64;
  while ( 1 )
  {
    ((void (__fastcall *)(void ***, UFG::qSNode<UFG::AudioEvent,UFG::AudioEvent> *))*v1)(&v5, v2);
    mNext = v2[3].mNext;
    if ( !mNext )
      break;
    v2 = mNext - 3;
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
  UFG::qSNode<UFG::AudioEvent,UFG::AudioEvent> *mNext; // rbx
  void **v5; // [rsp+20h] [rbp-28h] BYREF
  unsigned int v6; // [rsp+28h] [rbp-20h]
  __int64 v7; // [rsp+30h] [rbp-18h]

  v1 = &UFG::FindOldestEventFunctor::`vftable;
  v7 = 0i64;
  v5 = &UFG::FindOldestEventFunctor::`vftable;
  v6 = id;
  if ( !UFG::AudioEventManager::sm_allEventsList.mHead )
    return 0i64;
  v2 = UFG::AudioEventManager::sm_allEventsList.mHead - 3;
  if ( UFG::AudioEventManager::sm_allEventsList.mHead == (UFG::qSNode<UFG::AudioEvent,UFG::AudioEvent> *)24 )
    return 0i64;
  while ( 1 )
  {
    ((void (__fastcall *)(void ***, UFG::qSNode<UFG::AudioEvent,UFG::AudioEvent> *))*v1)(&v5, v2);
    mNext = v2[3].mNext;
    if ( !mNext )
      break;
    v2 = mNext - 3;
    if ( !v2 )
      break;
    v1 = v5;
  }
  return (UFG::AudioEvent *)v7;
}

