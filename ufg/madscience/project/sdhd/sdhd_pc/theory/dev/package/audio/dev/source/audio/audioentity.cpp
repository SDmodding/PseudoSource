// File Line: 23
// RVA: 0x140380
void __fastcall UFG::AudioEntityRegionData::AudioEntityRegionData(
        UFG::AudioEntityRegionData *this,
        UFG::AudioEntity *parent)
{
  this->m_parent = parent;
  this->vfptr = (UFG::AudioEntityRegionDataVtbl *)&UFG::AudioEntityRegionData::`vftable;
  parent->m_pRegionData = this;
}

// File Line: 30
// RVA: 0x141130
void __fastcall UFG::AudioEntityRegionData::~AudioEntityRegionData(UFG::AudioEntityRegionData *this)
{
  this->m_parent = 0i64;
  this->vfptr = (UFG::AudioEntityRegionDataVtbl *)&UFG::AudioEntityRegionData::`vftable;
}

// File Line: 36
// RVA: 0x1465150
__int64 dynamic_initializer_for__UFG::AudioEntity::sm_environmentInfoFilter__()
{
  UFG::qString::qString(&UFG::AudioEntity::sm_environmentInfoFilter);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::AudioEntity::sm_environmentInfoFilter__);
}

// File Line: 37
// RVA: 0x1465130
__int64 dynamic_initializer_for__UFG::AudioEntity::sm_entityInfoFilter__()
{
  UFG::qString::qString(&UFG::AudioEntity::sm_entityInfoFilter);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::AudioEntity::sm_entityInfoFilter__);
}

// File Line: 58
// RVA: 0x1400C0
void __fastcall UFG::AudioEntity::AudioEntity(UFG::AudioEntity *this)
{
  float y; // xmm1_4
  float z; // xmm2_4
  float w; // xmm3_4
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm3_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm3_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm3_4
  __int64 v14; // rax
  UFG::WwiseEnvironment::EnvironmentState *mEnvState; // rcx
  unsigned __int16 *mEnvCount; // rdx
  UFG::AudioEntityMotionData *m_pMotionData; // rax
  float v18; // xmm1_4
  float v19; // xmm2_4
  UFG::AudioEntityMotionData *v20; // rax
  float v21; // xmm1_4
  float v22; // xmm2_4
  UFG::AudioEntityMotionData *v23; // rax
  float v24; // xmm1_4
  float v25; // xmm2_4
  bool v26; // al

  this->mPrev = &this->UFG::qNode<UFG::AudioEntity,UFG::AudioEntity>;
  this->mNext = &this->UFG::qNode<UFG::AudioEntity,UFG::AudioEntity>;
  this->vfptr = (UFG::AudioEntityVtbl *)&UFG::AudioEntity::`vftable;
  this->m_name = UFG::gNullQSymbol;
  this->m_bEnableEnvironments = 1;
  y = UFG::qMatrix44::msIdentity.v0.y;
  z = UFG::qMatrix44::msIdentity.v0.z;
  w = UFG::qMatrix44::msIdentity.v0.w;
  this->m_WorldMatrix.v0.x = UFG::qMatrix44::msIdentity.v0.x;
  this->m_WorldMatrix.v0.y = y;
  this->m_WorldMatrix.v0.z = z;
  this->m_WorldMatrix.v0.w = w;
  v5 = UFG::qMatrix44::msIdentity.v1.y;
  v6 = UFG::qMatrix44::msIdentity.v1.z;
  v7 = UFG::qMatrix44::msIdentity.v1.w;
  this->m_WorldMatrix.v1.x = UFG::qMatrix44::msIdentity.v1.x;
  this->m_WorldMatrix.v1.y = v5;
  this->m_WorldMatrix.v1.z = v6;
  this->m_WorldMatrix.v1.w = v7;
  v8 = UFG::qMatrix44::msIdentity.v2.y;
  v9 = UFG::qMatrix44::msIdentity.v2.z;
  v10 = UFG::qMatrix44::msIdentity.v2.w;
  this->m_WorldMatrix.v2.x = UFG::qMatrix44::msIdentity.v2.x;
  this->m_WorldMatrix.v2.y = v8;
  this->m_WorldMatrix.v2.z = v9;
  this->m_WorldMatrix.v2.w = v10;
  v11 = UFG::qMatrix44::msIdentity.v3.y;
  v12 = UFG::qMatrix44::msIdentity.v3.z;
  v13 = UFG::qMatrix44::msIdentity.v3.w;
  this->m_WorldMatrix.v3.x = UFG::qMatrix44::msIdentity.v3.x;
  this->m_WorldMatrix.v3.y = v11;
  this->m_WorldMatrix.v3.z = v12;
  this->m_WorldMatrix.v3.w = v13;
  this->m_pMotionData = 0i64;
  this->m_pRegionData = 0i64;
  *(_QWORD *)&this->m_fLastDoppler = 0i64;
  this->m_obstruction = 0i64;
  this->m_occlusion = 0i64;
  *(_QWORD *)&this->m_environment.mDryLevel = 1065353216i64;
  v14 = 0i64;
  mEnvState = this->m_environment.mEnvState;
  mEnvCount = this->m_environment.mEnvCount;
  do
  {
    *((_DWORD *)mEnvState - 10) = 0;
    *mEnvCount = 0;
    *mEnvState = eEnvironmentState_Inactive;
    *((_DWORD *)mEnvState - 6) = 1065353216;
    this->m_environment.mAuxSendValues[v14++] = 0i64;
    ++mEnvCount;
    ++mEnvState;
  }
  while ( v14 < 4 );
  UFG::RegionContainmentInfo::RegionContainmentInfo(&this->m_containmentInfo);
  this->m_interiorCount = 0;
  this->m_eventInfos.p = 0i64;
  *(_QWORD *)&this->m_eventInfos.size = 0i64;
  this->m_events.mNode.mPrev = &this->m_events.mNode;
  this->m_events.mNode.mNext = &this->m_events.mNode;
  *(_DWORD *)&this->m_bIsInitialized = 16777472;
  *(_WORD *)&this->m_bPositionIsDirty = 1;
  this->m_inDoorRegion = 0;
  m_pMotionData = this->m_pMotionData;
  if ( m_pMotionData )
  {
    v18 = UFG::qVector3::msZero.y;
    v19 = UFG::qVector3::msZero.z;
    m_pMotionData->m_vLastPosition.x = UFG::qVector3::msZero.x;
    m_pMotionData->m_vLastPosition.y = v18;
    m_pMotionData->m_vLastPosition.z = v19;
  }
  v20 = this->m_pMotionData;
  if ( v20 )
  {
    v21 = UFG::qVector3::msZero.y;
    v22 = UFG::qVector3::msZero.z;
    v20->m_vCurVelocity.x = UFG::qVector3::msZero.x;
    v20->m_vCurVelocity.y = v21;
    v20->m_vCurVelocity.z = v22;
  }
  v23 = this->m_pMotionData;
  if ( v23 )
  {
    v24 = UFG::qVector3::msZero.y;
    v25 = UFG::qVector3::msZero.z;
    v23->m_vPrevVelocity.x = UFG::qVector3::msZero.x;
    v23->m_vPrevVelocity.y = v24;
    v23->m_vPrevVelocity.z = v25;
  }
  this->m_spreadRegionChecks = 1;
  this->m_regionCheckFrame = UFG::Metrics::msInstance.mSimFrameCount
                           + (unsigned __int8)(UFG::qRandom(UFG::AudioEntity::sm_RegionCheckSpread, &UFG::qDefaultSeed)
                                             + 1);
  this->m_obstruction = 0i64;
  this->m_occlusion = 0i64;
  v26 = oddFrame;
  this->m_oddFrame = oddFrame;
  oddFrame = !v26;
  if ( UFG::TiDo::m_pInstance )
    UFG::TiDo::m_pInstance->vfptr->CreateAudioEntityRegionData(UFG::TiDo::m_pInstance, this);
}

// File Line: 83
// RVA: 0x141050
void __fastcall UFG::AudioEntity::~AudioEntity(UFG::AudioEntity *this)
{
  UFG::AudioEntityMotionData *m_pMotionData; // rdx
  UFG::AudioEntityRegionData *m_pRegionData; // rcx
  UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> *mPrev; // rcx
  UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> *mNext; // rax
  UFG::EventInfo *p; // rcx
  UFG::qNode<UFG::AudioEntity,UFG::AudioEntity> *v7; // rcx
  UFG::qNode<UFG::AudioEntity,UFG::AudioEntity> *v8; // rax

  this->vfptr = (UFG::AudioEntityVtbl *)&UFG::AudioEntity::`vftable;
  UFG::AudioEntity::Shutdown(this);
  m_pMotionData = this->m_pMotionData;
  if ( m_pMotionData )
  {
    UFG::qMemoryPool::Free(&g_AudioComponentPool, m_pMotionData);
    this->m_pMotionData = 0i64;
  }
  m_pRegionData = this->m_pRegionData;
  if ( m_pRegionData )
  {
    m_pRegionData->vfptr->__vecDelDtor(m_pRegionData, 1u);
    this->m_pRegionData = 0i64;
  }
  UFG::qList<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption,1,0>::DeleteNodes((UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)&this->m_events);
  mPrev = this->m_events.mNode.mPrev;
  mNext = this->m_events.mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->m_events.mNode.mPrev = &this->m_events.mNode;
  this->m_events.mNode.mNext = &this->m_events.mNode;
  p = this->m_eventInfos.p;
  if ( p )
    operator delete[](p);
  this->m_eventInfos.p = 0i64;
  *(_QWORD *)&this->m_eventInfos.size = 0i64;
  UFG::RegionContainmentInfo::~RegionContainmentInfo(&this->m_containmentInfo);
  v7 = this->mPrev;
  v8 = this->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->mPrev = &this->UFG::qNode<UFG::AudioEntity,UFG::AudioEntity>;
  this->mNext = &this->UFG::qNode<UFG::AudioEntity,UFG::AudioEntity>;
}

// File Line: 103
// RVA: 0x146A50
void __fastcall UFG::AudioEntity::Init(UFG::AudioEntity *this, UFG::qSymbolUC *object_name, UFG::qMatrix44 *transform)
{
  char *v6; // rax
  char *v7; // rax
  bool v8; // al
  UFG::qNode<UFG::AudioEntity,UFG::AudioEntity> *mNext; // rax
  UFG::AudioEntityMotionData *m_pMotionData; // rax
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::AudioEntityMotionData *v13; // rax
  float v14; // xmm1_4
  float v15; // xmm2_4
  UFG::AudioEntityMotionData *v16; // rax
  float v17; // xmm1_4
  float v18; // xmm2_4
  UFG::qVector4 v19; // xmm3
  UFG::qVector4 v20; // xmm2
  UFG::qVector4 v21; // xmm1
  UFG::qSymbol *p; // rcx
  UFG::qSymbol *v23; // rbx
  UFG::AudioEntityRegionData *m_pRegionData; // rcx
  float v25; // xmm2_4
  float v26; // xmm0_4
  UFG::AudioEntityRegionData *v27; // rcx
  float v28; // xmm6_4
  float v29; // xmm1_4
  float v30; // xmm1_4
  char *v31; // [rsp+80h] [rbp+8h] BYREF
  float v32; // [rsp+98h] [rbp+20h] BYREF

  if ( !this->m_bIsInitialized )
  {
    v6 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0x30ui64, "AudioEntityMotionData", 0i64, 1u);
    v31 = v6;
    if ( v6 )
    {
      *((_QWORD *)v6 + 3) = 0i64;
      *((_QWORD *)v6 + 4) = 0i64;
      *(_QWORD *)v6 = 0i64;
      *((_QWORD *)v6 + 1) = 0i64;
      *((_QWORD *)v6 + 5) = 0i64;
      *((_QWORD *)v6 + 2) = 0i64;
    }
    else
    {
      v6 = 0i64;
    }
    this->m_pMotionData = (UFG::AudioEntityMotionData *)v6;
    this->m_name.mUID = object_name->mUID;
    v7 = UFG::qSymbol::as_cstr_dbg(object_name);
    if ( AK::SoundEngine::RegisterGameObj((unsigned __int64)this, v7, 1u) == AK_Success )
    {
      ++UFG::AudioEntityManager::sm_NumEntities;
      mNext = UFG::AudioEntityManager::sm_EntityList.mNode.mNext;
      UFG::AudioEntityManager::sm_EntityList.mNode.mNext = &this->UFG::qNode<UFG::AudioEntity,UFG::AudioEntity>;
      this->mPrev = (UFG::qNode<UFG::AudioEntity,UFG::AudioEntity> *)&UFG::AudioEntityManager::sm_EntityList;
      this->mNext = mNext;
      mNext->mPrev = &this->UFG::qNode<UFG::AudioEntity,UFG::AudioEntity>;
      v8 = 1;
    }
    else
    {
      v8 = 0;
    }
    this->m_bIsInitialized = v8;
    m_pMotionData = this->m_pMotionData;
    if ( m_pMotionData )
    {
      y = UFG::qVector3::msZero.y;
      z = UFG::qVector3::msZero.z;
      m_pMotionData->m_vLastPosition.x = UFG::qVector3::msZero.x;
      m_pMotionData->m_vLastPosition.y = y;
      m_pMotionData->m_vLastPosition.z = z;
    }
    v13 = this->m_pMotionData;
    if ( v13 )
    {
      v14 = UFG::qVector3::msZero.y;
      v15 = UFG::qVector3::msZero.z;
      v13->m_vCurVelocity.x = UFG::qVector3::msZero.x;
      v13->m_vCurVelocity.y = v14;
      v13->m_vCurVelocity.z = v15;
    }
    v16 = this->m_pMotionData;
    if ( v16 )
    {
      v17 = UFG::qVector3::msZero.y;
      v18 = UFG::qVector3::msZero.z;
      v16->m_vPrevVelocity.x = UFG::qVector3::msZero.x;
      v16->m_vPrevVelocity.y = v17;
      v16->m_vPrevVelocity.z = v18;
    }
    v19 = transform->v1;
    v20 = transform->v2;
    v21 = transform->v3;
    this->m_WorldMatrix.v0 = transform->v0;
    this->m_WorldMatrix.v1 = v19;
    this->m_WorldMatrix.v2 = v20;
    this->m_WorldMatrix.v3 = v21;
    this->m_interiorCount = 0;
    this->m_inDoorRegion = 0;
    *(_WORD *)&this->m_bOcclusionIsDirty = 257;
    this->m_fDistanceUpdateTimeAccumulator = 0.0;
    p = this->m_containmentInfo.m_regionsContainedIn.p;
    if ( p )
    {
      v23 = p - 1;
      `eh vector destructor iterator(p, 4ui64, p[-1].mUID, (void (__fastcall *)(void *))_);
      operator delete[](v23);
    }
    this->m_containmentInfo.m_regionsContainedIn.p = 0i64;
    *(_QWORD *)&this->m_containmentInfo.m_regionsContainedIn.size = 0i64;
    UFG::AudioEntity::ClearEnvironments(this, 1);
    m_pRegionData = this->m_pRegionData;
    if ( m_pRegionData )
    {
      this->m_regionCheckFrame = UFG::AudioEntity::sm_RegionCheckSpread + UFG::Metrics::msInstance.mSimFrameCount;
      this->m_bPositionIsDirty = 0;
      m_pRegionData->vfptr->CheckTriggerRegions(m_pRegionData);
    }
    if ( UFG::AudioListener::sm_pInstance )
    {
      this->m_bOcclusionIsDirty = 0;
      v25 = 0.0;
      v32 = 0.0;
      v26 = 0.0;
      LODWORD(v31) = 0;
      v27 = this->m_pRegionData;
      v28 = *(float *)&FLOAT_1_0;
      if ( v27 && (v27->vfptr->FindObsOccValues(v27, &v32, (float *)&v31), v25 = v32, v26 = *(float *)&v31, v32 > 0.0) )
      {
        v29 = v32;
        if ( v32 >= 1.0 )
          v29 = *(float *)&FLOAT_1_0;
      }
      else
      {
        v29 = 0.0;
      }
      this->m_obstruction.m_targetValue = v29;
      if ( v26 <= 0.0 )
      {
        v30 = 0.0;
      }
      else
      {
        v30 = v26;
        if ( v26 >= 1.0 )
          v30 = *(float *)&FLOAT_1_0;
      }
      this->m_occlusion.m_targetValue = v30;
      if ( v25 <= 0.0 )
      {
        v25 = 0.0;
      }
      else if ( v25 >= 1.0 )
      {
        v25 = *(float *)&FLOAT_1_0;
      }
      this->m_obstruction.m_currentValue = v25;
      if ( v26 <= 0.0 )
      {
        v26 = 0.0;
      }
      else if ( v26 >= 1.0 )
      {
LABEL_37:
        this->m_occlusion.m_currentValue = v28;
        if ( !UFG::WwiseInterface::smShuttingDown )
          AK::SoundEngine::SetObjectObstructionAndOcclusion(
            (unsigned __int64)this,
            UFG::AudioListener::sm_pInstance->m_listenerId,
            v25,
            v28);
        return;
      }
      v28 = v26;
      goto LABEL_37;
    }
  }
}

// File Line: 138
// RVA: 0x14C6D0
void __fastcall UFG::AudioEntity::Shutdown(UFG::AudioEntity *this)
{
  UFG::qNode<UFG::AudioEntity,UFG::AudioEntity> *mPrev; // rdx
  UFG::qNode<UFG::AudioEntity,UFG::AudioEntity> *mNext; // rax
  UFG::EventInfo **p_mNext; // rbx
  UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> *v5; // rdi
  UFG::AudioEntity *p_m_pExternalSourceInfo; // rbp
  UFG::EventInfo *v7; // rax
  char v8; // al
  unsigned int v9; // ecx
  char v10; // al
  UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> *v11; // rax
  UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> *v12; // rcx
  UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> *v13; // rax
  UFG::EventInfo *v14; // rdx
  UFG::EventInfo *v15; // rax
  UFG::EventInfo *i; // rdi
  UFG::qSymbol *p; // rcx
  UFG::qSymbol *v18; // rbx
  UFG::AudioEntityMotionData *m_pMotionData; // rdx

  if ( this->m_bIsInitialized )
  {
    AK::SoundEngine::UnregisterGameObj((unsigned __int64)this);
    --UFG::AudioEntityManager::sm_NumEntities;
    mPrev = this->mPrev;
    mNext = this->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mPrev = &this->UFG::qNode<UFG::AudioEntity,UFG::AudioEntity>;
    this->mNext = &this->UFG::qNode<UFG::AudioEntity,UFG::AudioEntity>;
    p_mNext = (UFG::EventInfo **)&this->m_events.mNode.mNext[-1].mNext;
    if ( p_mNext != &this->m_eventInfos.p )
    {
      do
      {
        v5 = (UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> *)(p_mNext + 1);
        p_m_pExternalSourceInfo = (UFG::AudioEntity *)&p_mNext[2][-1].m_pExternalSourceInfo;
        if ( ((_BYTE)p_mNext[18] & 8) == 0 )
        {
          v7 = p_mNext[14];
          if ( v7 && *((_DWORD *)p_mNext + 8) )
          {
            if ( *(_QWORD *)&v7->m_eventId )
              *(_QWORD *)&v7->m_eventId = 0i64;
            *(_QWORD *)&p_mNext[14]->m_eventId = 0i64;
            p_mNext[14] = 0i64;
          }
          v8 = *((_BYTE *)p_mNext + 144);
          if ( (v8 & 0x40) != 0 && v8 >= 0 )
          {
            v9 = *((_DWORD *)p_mNext + 25);
            if ( v9 )
            {
              if ( !UFG::WwiseInterface::smShuttingDown )
                AK::SoundEngine::StopPlayingID(v9, 0, AkCurveInterpolation_Linear);
            }
          }
          v10 = *((_BYTE *)p_mNext + 144);
          if ( (v10 & 0x40) == 0 && v10 >= 0 )
            *((_BYTE *)p_mNext + 144) = v10 | 4;
          *((_BYTE *)p_mNext + 144) |= 8u;
        }
        if ( p_mNext[13] )
        {
          v11 = (UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> *)p_mNext[2];
          v12 = v5->mPrev;
          v12->mNext = v11;
          v11->mPrev = v12;
          v5->mPrev = v5;
          p_mNext[2] = (UFG::EventInfo *)(p_mNext + 1);
          v13 = UFG::AudioEventManager::sm_orphanEventList.mNode.mPrev;
          UFG::AudioEventManager::sm_orphanEventList.mNode.mPrev->mNext = v5;
          v5->mPrev = v13;
          p_mNext[2] = (UFG::EventInfo *)&UFG::AudioEventManager::sm_orphanEventList;
          UFG::AudioEventManager::sm_orphanEventList.mNode.mPrev = (UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> *)(p_mNext + 1);
          v14 = p_mNext[13];
          if ( v14 )
          {
            v15 = p_mNext[6];
            if ( v15 )
              ((void (__fastcall *)(char *, __int64, UFG::EventInfo **, UFG::EventInfo *))v15)(
                (char *)v14 + *((int *)p_mNext + 14),
                1i64,
                p_mNext,
                p_mNext[9]);
          }
          if ( p_mNext[13] )
          {
            for ( i = p_mNext[5]; i; i = (UFG::EventInfo *)i->m_pInitParams.m_EventPlayEndCallback )
              (*(void (__fastcall **)(UFG::EventInfo *, UFG::EventInfo **, __int64))(*(_QWORD *)&i->m_eventId + 8i64))(
                i,
                p_mNext,
                1i64);
          }
          p_mNext[13] = 0i64;
        }
        p_mNext = (UFG::EventInfo **)p_m_pExternalSourceInfo;
      }
      while ( p_m_pExternalSourceInfo != (UFG::AudioEntity *)&this->m_eventInfos.p );
    }
    this->m_bIsInitialized = 0;
    p = this->m_containmentInfo.m_regionsContainedIn.p;
    if ( p )
    {
      v18 = p - 1;
      `eh vector destructor iterator(p, 4ui64, p[-1].mUID, (void (__fastcall *)(void *))_);
      operator delete[](v18);
    }
    this->m_containmentInfo.m_regionsContainedIn.p = 0i64;
    *(_QWORD *)&this->m_containmentInfo.m_regionsContainedIn.size = 0i64;
    this->m_obstruction = 0i64;
    this->m_occlusion = 0i64;
    UFG::AudioEntity::ClearEnvironments(this, 0);
    m_pMotionData = this->m_pMotionData;
    this->m_bSetOcclusionOverride = 0;
    UFG::qMemoryPool::Free(&g_AudioComponentPool, m_pMotionData);
    this->m_pMotionData = 0i64;
  }
}

// File Line: 198
// RVA: 0x14CC60
void __fastcall UFG::AudioEntity::StopAndForgetAllEvents(UFG::AudioEntity *this, float ms)
{
  UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> *mNext; // rbx
  UFG::EventInfo **p_p; // rdi
  void **v4; // rax
  UFG::AudioEntity *p_mNext; // rbx
  void **v6; // [rsp+20h] [rbp-18h] BYREF
  float v7; // [rsp+28h] [rbp-10h]

  mNext = this->m_events.mNode.mNext;
  p_p = &this->m_eventInfos.p;
  v4 = &UFG::StopAndForgetFunctor::`vftable;
  v7 = ms;
  p_mNext = (UFG::AudioEntity *)&mNext[-1].mNext;
  v6 = &UFG::StopAndForgetFunctor::`vftable;
  if ( p_mNext != (UFG::AudioEntity *)&this->m_eventInfos.p )
  {
    while ( 1 )
    {
      ((void (__fastcall *)(void ***, UFG::AudioEntity *))*v4)(&v6, p_mNext);
      p_mNext = (UFG::AudioEntity *)&p_mNext->mNext[-1].mNext;
      if ( p_mNext == (UFG::AudioEntity *)p_p )
        break;
      v4 = v6;
    }
  }
}

// File Line: 210
// RVA: 0x14CCC0
void __fastcall UFG::AudioEntity::StopAndForgetEvent(UFG::AudioEntity *this, unsigned int id, float ms)
{
  UFG::EventInfo **p_p; // rdi
  void **v4; // rax
  UFG::AudioEntity *p_mNext; // rbx
  void **v6; // [rsp+20h] [rbp-18h] BYREF
  unsigned int v7; // [rsp+28h] [rbp-10h]

  p_p = &this->m_eventInfos.p;
  v4 = &UFG::StopAllEventsOfIdFunctor::`vftable;
  p_mNext = (UFG::AudioEntity *)&this->m_events.mNode.mNext[-1].mNext;
  v6 = &UFG::StopAllEventsOfIdFunctor::`vftable;
  v7 = id;
  if ( p_mNext != (UFG::AudioEntity *)&this->m_eventInfos.p )
  {
    while ( 1 )
    {
      ((void (__fastcall *)(void ***, UFG::AudioEntity *))*v4)(&v6, p_mNext);
      p_mNext = (UFG::AudioEntity *)&p_mNext->mNext[-1].mNext;
      if ( p_mNext == (UFG::AudioEntity *)p_p )
        break;
      v4 = v6;
    }
  }
}

// File Line: 222
// RVA: 0x1449C0
void __fastcall UFG::AudioEntity::DestroyAllEvents(UFG::AudioEntity *this)
{
  UFG::EventInfo **p_p; // rdi
  void **v2; // rax
  UFG::AudioEntity *p_mNext; // rbx
  void **v4; // [rsp+38h] [rbp+10h] BYREF

  p_p = &this->m_eventInfos.p;
  v2 = &UFG::DestroyEventFunctor::`vftable;
  p_mNext = (UFG::AudioEntity *)&this->m_events.mNode.mNext[-1].mNext;
  v4 = &UFG::DestroyEventFunctor::`vftable;
  if ( p_mNext != (UFG::AudioEntity *)&this->m_eventInfos.p )
  {
    while ( 1 )
    {
      ((void (__fastcall *)(void ***, UFG::AudioEntity *))*v2)(&v4, p_mNext);
      p_mNext = (UFG::AudioEntity *)&p_mNext->mNext[-1].mNext;
      if ( p_mNext == (UFG::AudioEntity *)p_p )
        break;
      v2 = v4;
    }
  }
}

// File Line: 233
// RVA: 0x143E70
__int64 __fastcall UFG::AudioEntity::CountNumPlayingEvents(UFG::AudioEntity *this)
{
  UFG::EventInfo **p_p; // rdi
  void **v2; // rax
  UFG::AudioEntity *p_mNext; // rbx
  void **v5; // [rsp+20h] [rbp-18h] BYREF
  __int64 v6; // [rsp+28h] [rbp-10h]

  p_p = &this->m_eventInfos.p;
  v2 = &UFG::IsIdPlayingFunctor::`vftable;
  p_mNext = (UFG::AudioEntity *)&this->m_events.mNode.mNext[-1].mNext;
  v6 = 0i64;
  v5 = &UFG::IsIdPlayingFunctor::`vftable;
  if ( p_mNext == (UFG::AudioEntity *)&this->m_eventInfos.p )
    return 0i64;
  while ( 1 )
  {
    ((void (__fastcall *)(void ***, UFG::AudioEntity *))*v2)(&v5, p_mNext);
    p_mNext = (UFG::AudioEntity *)&p_mNext->mNext[-1].mNext;
    if ( p_mNext == (UFG::AudioEntity *)p_p )
      break;
    v2 = v5;
  }
  return HIDWORD(v6);
}

// File Line: 260
// RVA: 0x14B690
void __fastcall UFG::AudioEntity::ResumeAllEvents(UFG::AudioEntity *this)
{
  UFG::EventInfo **p_p; // rdi
  void **v2; // rax
  UFG::AudioEntity *p_mNext; // rbx
  void **v4; // [rsp+38h] [rbp+10h] BYREF

  p_p = &this->m_eventInfos.p;
  v2 = &UFG::ResumeFunctor::`vftable;
  p_mNext = (UFG::AudioEntity *)&this->m_events.mNode.mNext[-1].mNext;
  v4 = &UFG::ResumeFunctor::`vftable;
  if ( p_mNext != (UFG::AudioEntity *)&this->m_eventInfos.p )
  {
    while ( 1 )
    {
      ((void (__fastcall *)(void ***, UFG::AudioEntity *))*v2)(&v4, p_mNext);
      p_mNext = (UFG::AudioEntity *)&p_mNext->mNext[-1].mNext;
      if ( p_mNext == (UFG::AudioEntity *)p_p )
        break;
      v2 = v4;
    }
  }
}

// File Line: 271
// RVA: 0x147CD0
bool __fastcall UFG::AudioEntity::IsPlayingId(UFG::AudioEntity *this, unsigned int id)
{
  UFG::EventInfo **p_p; // rdi
  void **v3; // rax
  UFG::AudioEntity *p_mNext; // rbx
  __int64 v5; // r8
  void **v7; // [rsp+20h] [rbp-18h] BYREF
  unsigned int v8; // [rsp+28h] [rbp-10h]
  int v9; // [rsp+2Ch] [rbp-Ch]

  p_p = &this->m_eventInfos.p;
  v3 = &UFG::IsIdPlayingFunctor::`vftable;
  p_mNext = (UFG::AudioEntity *)&this->m_events.mNode.mNext[-1].mNext;
  v5 = 0i64;
  v9 = 0;
  v8 = id;
  v7 = &UFG::IsIdPlayingFunctor::`vftable;
  if ( p_mNext != (UFG::AudioEntity *)&this->m_eventInfos.p )
  {
    while ( 1 )
    {
      ((void (__fastcall *)(void ***, UFG::AudioEntity *, __int64))*v3)(&v7, p_mNext, v5);
      p_mNext = (UFG::AudioEntity *)&p_mNext->mNext[-1].mNext;
      if ( p_mNext == (UFG::AudioEntity *)p_p )
        break;
      v3 = v7;
    }
    LODWORD(v5) = v9;
  }
  return (_DWORD)v5 != 0;
}

// File Line: 285
// RVA: 0x1465770
signed __int64 UFG::_dynamic_initializer_for__s_uDistanceUID__()
{
  signed __int64 result; // rax

  result = UFG::qStringLength("distance");
  if ( (_DWORD)result )
  {
    result = AK::SoundEngine::GetIDFromString("distance");
    s_uDistanceUID = result;
  }
  else
  {
    s_uDistanceUID = 0;
  }
  return result;
}

// File Line: 288
// RVA: 0x142D80
void __fastcall UFG::AudioEntity::AudioEntityUpdate(UFG::AudioEntity *this, float delta_sec)
{
  float *p_x; // rdx
  bool v5; // si
  float v6; // xmm6_4
  UFG::AudioEntityMotionData *m_pMotionData; // rcx
  UFG::qVector4 *p_m_vLastPositionChecked; // rax
  UFG::qVector4 *v9; // rax
  float y; // xmm0_4
  float z; // xmm1_4
  UFG::AudioEntityRegionData *m_pRegionData; // rcx
  unsigned int v13; // r8d
  __int64 v14; // rdx
  float v15; // xmm3_4
  __m128 y_low; // xmm2
  float v17; // xmm6_4
  float v18; // xmm0_4
  __int64 i; // rax
  UFG::WwiseEnvironment enviroDBG; // [rsp+20h] [rbp-88h] BYREF

  if ( !this->m_bIsFollowingListener && UFG::AudioListener::sm_pInstance )
  {
    p_x = &this->m_WorldMatrix.v3.x;
    v5 = 0;
    if ( this->m_pMotionData )
      p_x = &this->m_pMotionData->m_vLastPosition.x;
    v6 = (float)((float)(this->m_WorldMatrix.v3.y - p_x[1]) * (float)(this->m_WorldMatrix.v3.y - p_x[1]))
       + (float)((float)(this->m_WorldMatrix.v3.x - *p_x) * (float)(this->m_WorldMatrix.v3.x - *p_x));
    ((void (__fastcall *)(UFG::AudioEntity *))this->vfptr->UpdateVelocity)(this);
    m_pMotionData = this->m_pMotionData;
    p_m_vLastPositionChecked = (UFG::qVector4 *)&m_pMotionData->m_vLastPositionChecked;
    if ( !m_pMotionData )
      p_m_vLastPositionChecked = &this->m_WorldMatrix.v3;
    if ( (float)((float)((float)((float)(this->m_WorldMatrix.v3.y - p_m_vLastPositionChecked->y)
                               * (float)(this->m_WorldMatrix.v3.y - p_m_vLastPositionChecked->y))
                       + (float)((float)(this->m_WorldMatrix.v3.x - p_m_vLastPositionChecked->x)
                               * (float)(this->m_WorldMatrix.v3.x - p_m_vLastPositionChecked->x)))
               + (float)((float)(this->m_WorldMatrix.v3.z - p_m_vLastPositionChecked->z)
                       * (float)(this->m_WorldMatrix.v3.z - p_m_vLastPositionChecked->z))) > 1.0 )
    {
      this->m_bPositionIsDirty = 1;
      v9 = (UFG::qVector4 *)&m_pMotionData->m_vLastPositionChecked;
      if ( !m_pMotionData )
        v9 = &this->m_WorldMatrix.v3;
      if ( UFG::qVector3::msZero.x == v9->x && UFG::qVector3::msZero.y == v9->y && UFG::qVector3::msZero.z == v9->z )
        v5 = 1;
      if ( m_pMotionData )
      {
        y = this->m_WorldMatrix.v3.y;
        z = this->m_WorldMatrix.v3.z;
        m_pMotionData->m_vLastPositionChecked.x = this->m_WorldMatrix.v3.x;
        m_pMotionData->m_vLastPositionChecked.y = y;
        m_pMotionData->m_vLastPositionChecked.z = z;
      }
    }
    if ( v6 > 0.0099999998 )
      UFG::AudioEntity::ForcePositionUpdate(this);
    m_pRegionData = this->m_pRegionData;
    if ( m_pRegionData
      && (!this->m_spreadRegionChecks
       || UFG::Metrics::msInstance.mSimFrameCount >= this->m_regionCheckFrame
       || this->m_bOcclusionIsDirty)
      && this->m_bPositionIsDirty )
    {
      v13 = UFG::AudioEntity::sm_RegionCheckSpread + UFG::Metrics::msInstance.mSimFrameCount;
      this->m_bPositionIsDirty = 0;
      this->m_regionCheckFrame = v13;
      m_pRegionData->vfptr->CheckTriggerRegions(m_pRegionData);
    }
    if ( !this->m_bSetOcclusionOverride )
      UFG::AudioEntity::SetObsOccValues(this, v5);
    if ( (COERCE_FLOAT(COERCE_UNSIGNED_INT(this->m_obstruction.m_currentValue - this->m_obstruction.m_targetValue) & _xmm) >= 0.0000001
       || COERCE_FLOAT(COERCE_UNSIGNED_INT(this->m_occlusion.m_currentValue - this->m_occlusion.m_targetValue) & _xmm) >= 0.0000001)
      && !UFG::WwiseInterface::smShuttingDown )
    {
      AK::SoundEngine::SetObjectObstructionAndOcclusion(
        (unsigned __int64)this,
        UFG::AudioListener::sm_pInstance->m_listenerId,
        this->m_obstruction.m_currentValue,
        this->m_occlusion.m_currentValue);
    }
    UFG::qApproach(
      (float *)&this->m_obstruction,
      this->m_obstruction.m_targetValue,
      UFG::TiDo::sm_occlusionRate,
      delta_sec);
    UFG::qApproach((float *)&this->m_occlusion, this->m_occlusion.m_targetValue, UFG::TiDo::sm_occlusionRate, delta_sec);
    ((void (__fastcall *)(UFG::AudioEntity *, __int64, UFG::qVector3 *, UFG::qVector3 *))this->vfptr->CalculateAndApplyDoppler)(
      this,
      v14,
      &UFG::AudioListener::sm_pInstance->m_position,
      &UFG::AudioListener::sm_pInstance->m_velocity);
    v15 = delta_sec + this->m_fDistanceUpdateTimeAccumulator;
    this->m_fDistanceUpdateTimeAccumulator = v15;
    y_low = (__m128)LODWORD(gAudioListener[0].m_matrix.v3.y);
    y_low.m128_f32[0] = (float)((float)((float)(gAudioListener[0].m_matrix.v3.y - this->m_WorldMatrix.v3.y)
                                      * (float)(gAudioListener[0].m_matrix.v3.y - this->m_WorldMatrix.v3.y))
                              + (float)((float)(gAudioListener[0].m_matrix.v3.x - this->m_WorldMatrix.v3.x)
                                      * (float)(gAudioListener[0].m_matrix.v3.x - this->m_WorldMatrix.v3.x)))
                      + (float)((float)(gAudioListener[0].m_matrix.v3.z - this->m_WorldMatrix.v3.z)
                              * (float)(gAudioListener[0].m_matrix.v3.z - this->m_WorldMatrix.v3.z));
    v17 = _mm_sqrt_ps(y_low).m128_f32[0];
    if ( v17 >= 25.0 )
    {
      if ( v17 >= 50.0 )
        v18 = FLOAT_0_5;
      else
        v18 = (float)((float)(v17 - 25.0) * 0.5) * 0.039999999;
    }
    else
    {
      v18 = 0.0;
    }
    if ( v15 > v18 )
    {
      if ( this->m_bIsInitialized )
        UFG::WwiseInterface::SetWwiseRtpcValue(s_uDistanceUID, v17, (unsigned __int64)this);
      this->m_fDistanceUpdateTimeAccumulator = 0.0;
    }
    for ( i = 0i64; i < 4; ++i )
      enviroDBG.mVolumeOverride[i] = 1.0;
    UFG::AudioEntity::UpdateEnvironments(this, v17, delta_sec, &enviroDBG);
    UFG::AudioEntity::Debug_Render(this);
  }
}

// File Line: 386
// RVA: 0x145B00
void __fastcall UFG::AudioEntity::ForcePositionUpdate(UFG::AudioEntity *this)
{
  float x; // xmm1_4
  int v3; // xmm3_4
  float z; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm0_4
  UFG::AudioEntityMotionData *m_pMotionData; // rcx
  float y; // xmm0_4
  float v9; // xmm1_4
  AkSoundPosition in_Position; // [rsp+20h] [rbp-68h] BYREF
  __int64 v11; // [rsp+70h] [rbp-18h]
  float v12; // [rsp+78h] [rbp-10h]

  if ( this->m_bIsInitialized )
  {
    x = this->m_WorldMatrix.v3.x;
    v3 = LODWORD(this->m_WorldMatrix.v0.y) ^ _xmm[0];
    LODWORD(v11) = LODWORD(this->m_WorldMatrix.v3.y) ^ _xmm[0];
    z = this->m_WorldMatrix.v3.z;
    v12 = x;
    v5 = this->m_WorldMatrix.v0.x;
    *((float *)&v11 + 1) = z;
    v6 = this->m_WorldMatrix.v0.z;
    *(_QWORD *)&in_Position.Position.X = v11;
    in_Position.Position.Z = v12;
    LODWORD(in_Position.Orientation.X) = v3;
    in_Position.Orientation.Y = v6;
    in_Position.Orientation.Z = v5;
    AK::SoundEngine::SetPosition((unsigned __int64)this, &in_Position);
    m_pMotionData = this->m_pMotionData;
    if ( m_pMotionData )
    {
      y = this->m_WorldMatrix.v3.y;
      v9 = this->m_WorldMatrix.v3.z;
      m_pMotionData->m_vLastPosition.x = this->m_WorldMatrix.v3.x;
      m_pMotionData->m_vLastPosition.y = y;
      m_pMotionData->m_vLastPosition.z = v9;
    }
  }
}

// File Line: 400
// RVA: 0x14E7B0
void __fastcall UFG::AudioEntity::UpdateVelocity(UFG::AudioEntity *this, float delta_sec)
{
  UFG::AudioEntityMotionData *m_pMotionData; // rax
  float x; // xmm4_4
  float y; // xmm5_4
  float z; // xmm3_4
  UFG::AudioEntityMotionData *v6; // rax

  m_pMotionData = this->m_pMotionData;
  if ( m_pMotionData )
  {
    x = UFG::qVector3::msZero.x;
    y = UFG::qVector3::msZero.y;
    z = UFG::qVector3::msZero.z;
    if ( delta_sec > 0.0 )
    {
      x = (float)(1.0 / delta_sec) * (float)(this->m_WorldMatrix.v3.x - m_pMotionData->m_vLastPosition.x);
      y = (float)(1.0 / delta_sec) * (float)(this->m_WorldMatrix.v3.y - m_pMotionData->m_vLastPosition.y);
      z = (float)(1.0 / delta_sec) * (float)(this->m_WorldMatrix.v3.z - m_pMotionData->m_vLastPosition.z);
    }
    if ( (float)((float)((float)((float)(y - m_pMotionData->m_vPrevVelocity.y)
                               * (float)(y - m_pMotionData->m_vPrevVelocity.y))
                       + (float)((float)(x - m_pMotionData->m_vPrevVelocity.x)
                               * (float)(x - m_pMotionData->m_vPrevVelocity.x)))
               + (float)((float)(z - m_pMotionData->m_vPrevVelocity.z) * (float)(z - m_pMotionData->m_vPrevVelocity.z))) < 2500.0 )
    {
      m_pMotionData->m_vCurVelocity.x = x;
      m_pMotionData->m_vCurVelocity.y = y;
      m_pMotionData->m_vCurVelocity.z = z;
    }
    v6 = this->m_pMotionData;
    if ( v6 )
    {
      v6->m_vPrevVelocity.x = x;
      v6->m_vPrevVelocity.y = y;
      v6->m_vPrevVelocity.z = z;
    }
  }
}

// File Line: 425
// RVA: 0x14657B0
signed __int64 UFG::_dynamic_initializer_for__s_uDopplerUID__()
{
  signed __int64 result; // rax

  result = UFG::qStringLength("doppler_shift");
  if ( (_DWORD)result )
  {
    result = AK::SoundEngine::GetIDFromString("doppler_shift");
    s_uDopplerUID = result;
  }
  else
  {
    s_uDopplerUID = 0;
  }
  return result;
}

// File Line: 428
// RVA: 0x1438C0
float __fastcall UFG::AudioEntity::CalculateAndApplyDoppler(
        UFG::AudioEntity *this,
        float delta_sec,
        UFG::qVector3 *vListenerPos,
        UFG::qVector3 *vListenerVelocity)
{
  UFG::AudioEntityMotionData *m_pMotionData; // rax
  float v8; // xmm7_4
  UFG::qVector3 *p_m_vCurVelocity; // rax
  __m128 x_low; // xmm4
  float v11; // xmm6_4
  float v12; // xmm5_4
  __m128 v13; // xmm3
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm0_4
  float v17; // xmm6_4
  float value; // [rsp+90h] [rbp+8h] BYREF

  if ( this->m_bIsDopplerEnabled )
  {
    m_pMotionData = this->m_pMotionData;
    v8 = 0.0;
    if ( m_pMotionData )
      p_m_vCurVelocity = &m_pMotionData->m_vCurVelocity;
    else
      p_m_vCurVelocity = &UFG::qVector3::msZero;
    x_low = (__m128)LODWORD(this->m_WorldMatrix.v3.x);
    x_low.m128_f32[0] = x_low.m128_f32[0] - vListenerPos->x;
    v11 = this->m_WorldMatrix.v3.y - vListenerPos->y;
    v12 = this->m_WorldMatrix.v3.z - vListenerPos->z;
    v13 = x_low;
    v13.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(v11 * v11)) + (float)(v12 * v12);
    if ( v13.m128_f32[0] <= 0.001 )
    {
      if ( COERCE_FLOAT(LODWORD(this->m_fLastDoppler) & _xmm) > 2.0 )
      {
        if ( this->m_bIsInitialized )
          UFG::WwiseInterface::SetWwiseRtpcValue(s_uDopplerUID, 0.0, (unsigned __int64)this);
        this->m_fLastDoppler = 0.0;
      }
      return v8;
    }
    if ( v13.m128_f32[0] == 0.0 )
      v14 = 0.0;
    else
      v14 = 1.0 / _mm_sqrt_ps(v13).m128_f32[0];
    v8 = (float)((float)((float)(v11 * v14) * (float)(p_m_vCurVelocity->y - vListenerVelocity->y))
               + (float)((float)(x_low.m128_f32[0] * v14) * (float)(p_m_vCurVelocity->x - vListenerVelocity->x)))
       + (float)((float)(v12 * v14) * (float)(p_m_vCurVelocity->z - vListenerVelocity->z));
    if ( (float)(v8 + 343.14001) <= 0.0 )
      v15 = FLOAT_16_0;
    else
      v15 = 343.14001 / (float)(v8 + 343.14001);
    v16 = (float)(logf(v15) * 1200.0) * 3.321928;
    if ( v16 <= -4800.0 )
    {
      v16 = FLOAT_N4800_0;
    }
    else
    {
      v17 = FLOAT_4800_0;
      if ( v16 >= 4800.0 )
      {
LABEL_20:
        UFG::qApproach(&value, v17, UFG::TiDo::sm_dopplerRate, delta_sec);
        if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(this->m_fLastDoppler - v17) & _xmm) > 2.0 )
        {
          if ( this->m_bIsInitialized )
            UFG::WwiseInterface::SetWwiseRtpcValue(s_uDopplerUID, v17, (unsigned __int64)this);
          this->m_fLastDoppler = v17;
        }
        return v8;
      }
    }
    v17 = v16;
    goto LABEL_20;
  }
  if ( COERCE_FLOAT(LODWORD(this->m_fLastDoppler) & _xmm) > 2.0 )
    this->m_fLastDoppler = 0.0;
  return 0.0;
}

// File Line: 476
// RVA: 0x14C1F0
void __fastcall UFG::AudioEntity::SetShouldFollowListener(UFG::AudioEntity *this, bool bEnable)
{
  UFG::AudioEntityMotionData *m_pMotionData; // rax
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::AudioEntityMotionData *v7; // rax
  float v8; // xmm1_4
  float v9; // xmm2_4
  AkSoundPosition in_Position; // [rsp+20h] [rbp-68h] BYREF
  __int64 v11; // [rsp+70h] [rbp-18h]
  float x; // [rsp+78h] [rbp-10h]

  if ( !bEnable || this->m_bIsFollowingListener )
  {
    this->m_bIsFollowingListener = bEnable;
  }
  else
  {
    m_pMotionData = this->m_pMotionData;
    if ( m_pMotionData )
    {
      y = UFG::qVector3::msZero.y;
      z = UFG::qVector3::msZero.z;
      m_pMotionData->m_vPrevVelocity.x = UFG::qVector3::msZero.x;
      m_pMotionData->m_vPrevVelocity.y = y;
      m_pMotionData->m_vPrevVelocity.z = z;
    }
    v7 = this->m_pMotionData;
    if ( v7 )
    {
      v8 = UFG::qVector3::msZero.y;
      v9 = UFG::qVector3::msZero.z;
      v7->m_vCurVelocity.x = UFG::qVector3::msZero.x;
      v7->m_vCurVelocity.y = v8;
      v7->m_vCurVelocity.z = v9;
    }
    v11 = *(_QWORD *)&gAudioListener[0].m_matrix.v3.y ^ (unsigned int)_xmm[0];
    x = gAudioListener[0].m_matrix.v3.x;
    *(_QWORD *)&in_Position.Position.X = v11;
    in_Position.Position.Z = gAudioListener[0].m_matrix.v3.x;
    LODWORD(in_Position.Orientation.X) = LODWORD(gAudioListener[0].m_matrix.v0.y) ^ _xmm[0];
    in_Position.Orientation.Y = gAudioListener[0].m_matrix.v0.z;
    in_Position.Orientation.Z = gAudioListener[0].m_matrix.v0.x;
    AK::SoundEngine::SetPosition((unsigned __int64)this, &in_Position);
    this->m_bIsFollowingListener = bEnable;
  }
}

// File Line: 503
// RVA: 0x144230
bool __fastcall UFG::AudioEntity::CreateEventA(
        UFG::AudioEntity *this,
        unsigned int eventId,
        UFG::AudioEventController *pEventController,
        UFG::AudioEventInitParams *pInitParams,
        UFG::AudioEventExternalSourceInfo *externalSourceInfo)
{
  char *v9; // rax
  __int64 v10; // rax

  if ( !this->m_bIsInitialized || !AK::SoundEngine::IsInitialized() || !eventId || !UFG::gAudioEventPool.mFreeListHead )
    return 0;
  v9 = UFG::AudioDialogEvent::operator new(0x98ui64);
  if ( v9 )
    UFG::AudioEvent::AudioEvent((UFG::AudioEvent *)v9, eventId, this, pEventController, pInitParams, externalSourceInfo);
  else
    v10 = 0i64;
  return v10 != 0;
}

// File Line: 531
// RVA: 0x144180
bool __fastcall UFG::AudioEntity::CreateDialogEvent(
        UFG::AudioEntity *this,
        UFG::AudioEventController *pEventController,
        UFG::AudioEventInitParams *pInitParams,
        UFG::AudioEventExternalSourceInfo *externalSourceInfo)
{
  char *v8; // rax
  __int64 v9; // rax

  if ( !UFG::gAudioEventPool.mFreeListHead || !this->m_bIsInitialized || !AK::SoundEngine::IsInitialized() )
    return 0;
  v8 = UFG::AudioDialogEvent::operator new(0x98ui64);
  if ( v8 )
    UFG::AudioDialogEvent::AudioDialogEvent(
      (UFG::AudioDialogEvent *)v8,
      this,
      pEventController,
      pInitParams,
      externalSourceInfo);
  else
    v9 = 0i64;
  return v9 != 0;
}

// File Line: 555
// RVA: 0x144070
char __fastcall UFG::AudioEntity::CreateAndPlayEvent(
        UFG::AudioEntity *this,
        unsigned int eventId,
        UFG::AudioEventController *pEventController,
        UFG::AudioEventInitParams *pInitParams,
        unsigned int fadeInDurationMs,
        UFG::AudioEventExternalSourceInfo *externalSourceInfo)
{
  if ( this->m_bIsInitialized
    && UFG::AudioEntity::CreateEventA(this, eventId, pEventController, pInitParams, externalSourceInfo) )
  {
    return UFG::AudioEventController::Play(pEventController, fadeInDurationMs);
  }
  else
  {
    return 0;
  }
}

// File Line: 580
// RVA: 0x1440B0
char __fastcall UFG::AudioEntity::CreateAndPlayEvent(
        UFG::AudioEntity *this,
        unsigned int eventId,
        UFG::AudioEventInitParams *pInitParams,
        unsigned int fadeInDurationMs,
        UFG::AudioEventExternalSourceInfo *externalSourceInfo)
{
  char v6; // bl
  UFG::AudioEventController pEventController; // [rsp+30h] [rbp-18h] BYREF
  __int64 v8; // [rsp+38h] [rbp-10h]

  v8 = -2i64;
  if ( !this->m_bIsInitialized )
    return 0;
  pEventController.m_pEvent = 0i64;
  if ( UFG::AudioEntity::CreateEventA(this, eventId, &pEventController, pInitParams, externalSourceInfo) )
  {
    *((_BYTE *)pEventController.m_pEvent + 145) |= 4u;
    if ( pEventController.m_pEvent )
    {
      if ( pEventController.m_pEvent->vfptr->Play(pEventController.m_pEvent, 0) )
      {
        v6 = 1;
        if ( pEventController.m_pEvent )
        {
          pEventController.m_pEvent->m_pController = 0i64;
          pEventController.m_pEvent = 0i64;
        }
        goto LABEL_12;
      }
      *((_BYTE *)pEventController.m_pEvent + 144) |= 4u;
      if ( pEventController.m_pEvent )
        pEventController.m_pEvent->m_pController = 0i64;
      pEventController.m_pEvent = 0i64;
    }
  }
  v6 = 0;
LABEL_12:
  if ( pEventController.m_pEvent )
  {
    if ( pEventController.m_pEvent->m_pController )
      UFG::AudioEvent::Destroy(pEventController.m_pEvent);
  }
  return v6;
}

// File Line: 612
// RVA: 0x14C150
bool __fastcall UFG::AudioEntity::SetRtpcValue(UFG::AudioEntity *this, unsigned int rtpcId, float value)
{
  return this->m_bIsInitialized && UFG::WwiseInterface::SetWwiseRtpcValue(rtpcId, value, (unsigned __int64)this);
}

// File Line: 622
// RVA: 0x14C570
bool __fastcall UFG::AudioEntity::SetWwiseSwitch(UFG::AudioEntity *this, unsigned int switchId, unsigned int typeId)
{
  return UFG::WwiseInterface::SetWwiseSwitch(switchId, typeId, (unsigned __int64)this);
}

// File Line: 632
// RVA: 0x14C4B0
bool __fastcall UFG::AudioEntity::SetWwiseState(UFG::TiDo *this, unsigned int stateId, unsigned int stateMode)
{
  AKRESULT v5; // ebx

  v5 = AK_Fail;
  if ( AK::SoundEngine::IsInitialized() && stateId && stateMode && !UFG::WwiseInterface::smShuttingDown )
    v5 = AK::SoundEngine::SetState(stateId, stateMode);
  return v5 == AK_Success;
}

// File Line: 642
// RVA: 0x142B70
void __fastcall UFG::AudioEntity::ApplyEnvironment(
        UFG::AudioEntity *this,
        unsigned int envId,
        float volume,
        float dryLevel,
        float wetLevel,
        UFG::qWiseSymbol *envType)
{
  char v8; // r8
  int v9; // esi
  int v10; // edx
  __int64 v11; // rcx
  UFG::WwiseEnvironment *p_m_environment; // rax
  __int64 totalEnv; // rax
  UFG::qWiseSymbol *v14; // rax
  UFG::WwiseEnvironment *v15; // r14
  unsigned int auxBusID; // ebx
  const char *v17; // rax
  const char *v18; // rax
  UFG::qWiseSymbol result; // [rsp+20h] [rbp-38h] BYREF
  __int64 v20; // [rsp+28h] [rbp-30h]

  if ( envId )
  {
    v20 = -2i64;
    if ( this->vfptr->CanApplyEnvironment(this, envType) && this->m_bIsInitialized )
    {
      v8 = 0;
      v9 = 0;
      v10 = 0;
      v11 = 0i64;
      p_m_environment = &this->m_environment;
      while ( envId != p_m_environment->mAuxSendValues[0].auxBusID )
      {
        ++v10;
        ++v11;
        p_m_environment = (UFG::WwiseEnvironment *)((char *)p_m_environment + 8);
        if ( v11 >= 4 )
        {
          totalEnv = this->m_environment.totalEnv;
          if ( (int)totalEnv >= 4 )
          {
            v15 = &this->m_environment;
            do
            {
              auxBusID = v15->mAuxSendValues[0].auxBusID;
              UFG::TiDo::LoadEventSymbols(UFG::TiDo::m_pInstance);
              v17 = UFG::qWiseSymbolRegistry::Get(auxBusID);
              UFG::qPrintf("%u: %s\n", (unsigned int)v9++, v17);
              v15 = (UFG::WwiseEnvironment *)((char *)v15 + 8);
            }
            while ( v9 < 4 );
            UFG::TiDo::LoadEventSymbols(UFG::TiDo::m_pInstance);
            v18 = UFG::qWiseSymbolRegistry::Get(envId);
            UFG::qPrintf("Extra: %s\n", v18);
          }
          else
          {
            this->m_environment.mAuxSendValues[totalEnv].auxBusID = envId;
            this->m_environment.mVolume[totalEnv] = wetLevel;
            ++this->m_environment.mEnvCount[totalEnv];
            this->m_environment.mEnvState[totalEnv] = eEnvironmentState_Loading;
            this->m_environment.mDryLevel = dryLevel;
            ++this->m_environment.totalEnv;
            v14 = UFG::qSymbol::qSymbol(&result, envId);
            UFG::TiDo::LoadWwiseBank(v14);
            _((AMD_HD3D *)result.mUID);
          }
LABEL_17:
          if ( !UFG::WwiseInterface::smShuttingDown && AK::SoundEngine::IsInitialized() )
          {
            AK::SoundEngine::SetGameObjectAuxSendValues(
              (unsigned __int64)this,
              this->m_environment.mAuxSendValues,
              this->m_environment.totalEnv);
            AK::SoundEngine::SetGameObjectOutputBusVolume((unsigned __int64)this, this->m_environment.mDryLevel);
          }
          return;
        }
      }
      ++this->m_environment.mEnvCount[v10];
      if ( wetLevel != this->m_environment.mVolume[v10] )
        v8 = 1;
      if ( dryLevel != this->m_environment.mDryLevel )
        v8 = 1;
      this->m_environment.mVolume[v10] = wetLevel;
      this->m_environment.mDryLevel = dryLevel;
      if ( v8 )
        goto LABEL_17;
    }
  }
}

// File Line: 708
// RVA: 0x14B4D0
void __fastcall UFG::AudioEntity::RemoveEnvironment(
        UFG::AudioEntity *this,
        unsigned int envId,
        float dryLevel,
        float wetLevel)
{
  int v4; // r10d
  UFG::WwiseEnvironment::EnvironmentState *mEnvState; // rax
  UFG::WwiseEnvironment *p_m_environment; // r8
  unsigned __int16 *mEnvCount; // r9

  if ( this->m_environment.totalEnv > 0 )
  {
    v4 = 0;
    mEnvState = this->m_environment.mEnvState;
    p_m_environment = &this->m_environment;
    mEnvCount = this->m_environment.mEnvCount;
    do
    {
      if ( p_m_environment->mAuxSendValues[0].auxBusID == envId || !envId )
      {
        if ( (*mEnvCount)-- == 1 )
        {
          if ( p_m_environment->mAuxSendValues[0].auxBusID )
            *mEnvState = eEnvironmentState_FadeOut;
        }
        else
        {
          *((float *)mEnvState - 10) = wetLevel;
          this->m_environment.mDryLevel = dryLevel;
        }
      }
      ++v4;
      ++mEnvCount;
      p_m_environment = (UFG::WwiseEnvironment *)((char *)p_m_environment + 8);
      ++mEnvState;
    }
    while ( v4 < this->m_environment.totalEnv );
  }
}

// File Line: 736
// RVA: 0x143B90
void __fastcall UFG::AudioEntity::ClearEnvironments(UFG::AudioEntity *this, bool clearThenSet)
{
  float *mVolume; // rdi
  unsigned __int16 *mEnvCount; // rsi
  UFG::WwiseEnvironment *p_m_environment; // rbx
  __int64 v7; // r15
  UFG::qWiseSymbol *v8; // r14
  unsigned int mUID; // edx
  UFG::qBaseTreeRB *v10; // rax
  int *p_mCount; // rcx
  int v12; // eax
  UFG::qWiseSymbol result; // [rsp+68h] [rbp+10h] BYREF

  this->m_environment.mDryLevel = 1.0;
  mVolume = this->m_environment.mVolume;
  mEnvCount = this->m_environment.mEnvCount;
  p_m_environment = &this->m_environment;
  v7 = 4i64;
  do
  {
    if ( p_m_environment->mAuxSendValues[0].auxBusID )
    {
      v8 = UFG::qSymbol::qSymbol(&result, p_m_environment->mAuxSendValues[0].auxBusID);
      UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::TiDo::sm_audioLoadMutex);
      if ( UFG::TiDo::sm_shuttingDown )
      {
        UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::TiDo::sm_audioLoadMutex);
      }
      else
      {
        UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::TiDo::sm_audioLoadMutex);
        mUID = v8->mUID;
        if ( v8->mUID )
        {
          if ( mUID != -1 )
          {
            if ( mUID )
            {
              v10 = UFG::qBaseTreeRB::Get(&UFG::SoundBankManager::sm_soundBank_Tree.mTree, mUID);
              if ( v10 )
              {
                p_mCount = &v10[-1].mCount;
                if ( v10 != (UFG::qBaseTreeRB *)8 )
                {
                  v12 = p_mCount[19];
                  if ( v12 )
                    p_mCount[19] = v12 - 1;
                }
              }
            }
          }
        }
      }
      _((AMD_HD3D *)result.mUID);
    }
    mVolume[10] = 0.0;
    p_m_environment->mAuxSendValues[0] = 0i64;
    *mEnvCount = 0;
    *mVolume = 0.0;
    this->m_environment.totalEnv = 0;
    ++mEnvCount;
    ++mVolume;
    p_m_environment = (UFG::WwiseEnvironment *)((char *)p_m_environment + 8);
    --v7;
  }
  while ( v7 );
  if ( clearThenSet && !UFG::WwiseInterface::smShuttingDown && AK::SoundEngine::IsInitialized() )
  {
    AK::SoundEngine::SetGameObjectAuxSendValues(
      (unsigned __int64)this,
      this->m_environment.mAuxSendValues,
      this->m_environment.totalEnv);
    AK::SoundEngine::SetGameObjectOutputBusVolume((unsigned __int64)this, this->m_environment.mDryLevel);
  }
}

// File Line: 766
// RVA: 0x14C0B0
void __fastcall UFG::AudioEntity::SetObstructionAndOcclusionTargets(
        UFG::AudioEntity *this,
        float obstruction,
        float occlusion,
        bool forceToTargetVals)
{
  float v4; // xmm3_4
  float v5; // xmm4_4
  float v6; // xmm4_4

  v4 = *(float *)&FLOAT_1_0;
  if ( obstruction <= 0.0 )
  {
    v5 = 0.0;
  }
  else
  {
    v5 = obstruction;
    if ( obstruction >= 1.0 )
      v5 = *(float *)&FLOAT_1_0;
  }
  this->m_obstruction.m_targetValue = v5;
  if ( occlusion <= 0.0 )
  {
    v6 = 0.0;
  }
  else
  {
    v6 = occlusion;
    if ( occlusion >= 1.0 )
      v6 = *(float *)&FLOAT_1_0;
  }
  this->m_occlusion.m_targetValue = v6;
  if ( forceToTargetVals )
  {
    if ( obstruction <= 0.0 )
    {
      obstruction = 0.0;
    }
    else if ( obstruction >= 1.0 )
    {
      obstruction = *(float *)&FLOAT_1_0;
    }
    this->m_obstruction.m_currentValue = obstruction;
    if ( occlusion <= 0.0 )
    {
      occlusion = 0.0;
    }
    else if ( occlusion >= 1.0 )
    {
LABEL_19:
      this->m_occlusion.m_currentValue = v4;
      if ( !UFG::WwiseInterface::smShuttingDown )
        AK::SoundEngine::SetObjectObstructionAndOcclusion(
          (unsigned __int64)this,
          UFG::AudioListener::sm_pInstance->m_listenerId,
          obstruction,
          v4);
      return;
    }
    v4 = occlusion;
    goto LABEL_19;
  }
}

// File Line: 808
// RVA: 0x14CB60
void __fastcall UFG::AudioEntity::StopAllEvents(unsigned __int64 objectId)
{
  if ( !UFG::WwiseInterface::smShuttingDown )
    AK::SoundEngine::StopAll(objectId);
}

// File Line: 862
// RVA: 0x144B80
float __fastcall UFG::AudioEntity::Distance2ToListener(UFG::AudioEntity *this, unsigned int listenerId)
{
  UFG::Audio3DListener *v2; // rax

  if ( listenerId >= 8 )
    v2 = 0i64;
  else
    v2 = &gAudioListener[listenerId];
  return (float)((float)((float)(v2->m_matrix.v3.y - this->m_WorldMatrix.v3.y)
                       * (float)(v2->m_matrix.v3.y - this->m_WorldMatrix.v3.y))
               + (float)((float)(v2->m_matrix.v3.x - this->m_WorldMatrix.v3.x)
                       * (float)(v2->m_matrix.v3.x - this->m_WorldMatrix.v3.x)))
       + (float)((float)(v2->m_matrix.v3.z - this->m_WorldMatrix.v3.z)
               * (float)(v2->m_matrix.v3.z - this->m_WorldMatrix.v3.z));
}

// File Line: 1047
// RVA: 0x14C020
void __fastcall UFG::AudioEntity::SetObsOccValues(UFG::AudioEntity *this, bool forceToTargetVals)
{
  float v4; // xmm1_4
  UFG::AudioEntityRegionData *m_pRegionData; // rcx
  float v6; // xmm2_4
  float obstruction; // [rsp+40h] [rbp+18h] BYREF
  float occlusion; // [rsp+48h] [rbp+20h] BYREF

  if ( UFG::AudioListener::sm_pInstance
    && (forceToTargetVals || this->m_bOcclusionIsDirty && !this->m_bSetOcclusionOverride) )
  {
    v4 = 0.0;
    this->m_bOcclusionIsDirty = 0;
    m_pRegionData = this->m_pRegionData;
    v6 = 0.0;
    obstruction = 0.0;
    occlusion = 0.0;
    if ( m_pRegionData )
    {
      m_pRegionData->vfptr->FindObsOccValues(m_pRegionData, &obstruction, &occlusion);
      v4 = obstruction;
      v6 = occlusion;
    }
    UFG::AudioEntity::SetObstructionAndOcclusionTargets(this, v4, v6, forceToTargetVals);
  }
}

// File Line: 1083
// RVA: 0x14E050
void __fastcall UFG::AudioEntity::UpdateEnvironments(
        UFG::AudioEntity *this,
        float distanceToListener,
        float delta_sec,
        UFG::WwiseEnvironment *enviroDBG)
{
  __int64 v6; // r14
  __int64 v7; // r13
  float *p_fControlValue; // rbp
  float *mVolumeOverride; // r15
  UFG::WwiseEnvironment *p_m_environment; // r12
  UFG::WwiseEnvironment::EnvironmentState *mEnvState; // rdi
  UFG::qBaseTreeRB *v12; // rax
  int *p_mCount; // rax
  bool v14; // si
  float v15; // xmm6_4
  unsigned int mUID; // eax
  float v17; // xmm2_4
  float v18; // xmm1_4
  bool v19; // al
  UFG::qBaseTreeRB *v20; // rax
  int *v21; // rcx
  int v22; // eax
  __int64 v23; // rsi
  unsigned __int16 *v24; // r10
  _DWORD *v25; // rdx
  AkAuxSendValue *v26; // r9
  unsigned __int64 v27; // r8
  unsigned __int16 *v28; // r10
  float *v29; // r9
  AkAuxSendValue *v30; // rcx
  __int64 v31; // r11
  int v32; // esi
  int v33; // [rsp+20h] [rbp-E8h]
  UFG::qWiseSymbol v34; // [rsp+24h] [rbp-E4h] BYREF
  unsigned __int16 *v35; // [rsp+28h] [rbp-E0h]
  float *mVolume; // [rsp+30h] [rbp-D8h]
  UFG::AudioEntity *v37; // [rsp+38h] [rbp-D0h]
  float value; // [rsp+40h] [rbp-C8h] BYREF
  AkAuxSendValue *v39; // [rsp+48h] [rbp-C0h]
  UFG::qWiseSymbol result; // [rsp+50h] [rbp-B8h] BYREF
  __int64 v41; // [rsp+58h] [rbp-B0h]
  char v42; // [rsp+110h] [rbp+8h]

  v41 = -2i64;
  if ( this->m_environment.totalEnv <= 0 )
    return;
  v42 = 0;
  v33 = 0;
  v6 = 0i64;
  v7 = 3i64;
  v39 = &this->m_environment.mAuxSendValues[1];
  v37 = (UFG::AudioEntity *)&this->m_environment.mVolume[1];
  v35 = &this->m_environment.mEnvCount[1];
  p_fControlValue = &this->m_environment.mAuxSendValues[0].fControlValue;
  mVolume = this->m_environment.mVolume;
  mVolumeOverride = this->m_environment.mVolumeOverride;
  p_m_environment = &this->m_environment;
  mEnvState = this->m_environment.mEnvState;
  do
  {
    UFG::qSymbol::qSymbol(&result, p_m_environment->mAuxSendValues[0].auxBusID);
    v14 = !result.mUID
       || (v12 = UFG::qBaseTreeRB::Get(&UFG::SoundBankManager::sm_soundBank_Tree.mTree, result.mUID)) == 0i64
       || (p_mCount = &v12[-1].mCount) == 0i64
       || ((p_mCount[28] - 2) & 0xFFFFFFFB) == 0;
    if ( *mEnvState == eEnvironmentState_Loading && v14 )
      *mEnvState = eEnvironmentState_FadeIn;
    v15 = 0.0;
    UFG::qSymbol::qSymbol(&v34, p_m_environment->mAuxSendValues[0].auxBusID);
    mUID = v34.mUID;
    if ( *mEnvState == eEnvironmentState_FadeIn )
    {
      *mVolumeOverride = 1.0;
      if ( mUID == qwsTunnel.mUID )
        v15 = *(float *)&FLOAT_1_0;
      else
        v15 = 0.0;
    }
    if ( *mEnvState == eEnvironmentState_FadeOut )
    {
      *mVolumeOverride = 0.0;
      if ( mUID != qwsTunnel.mUID )
        goto LABEL_21;
      v15 = FLOAT_2_0;
    }
    else if ( v15 <= 0.0 )
    {
LABEL_21:
      v17 = FLOAT_10000_0;
      goto LABEL_22;
    }
    v17 = 1.0 / v15;
LABEL_22:
    if ( v14 )
      v18 = *mVolumeOverride * *mVolume;
    else
      v18 = 0.0;
    value = *p_fControlValue;
    v19 = UFG::qApproach(&value, v18, v17, delta_sec);
    if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(value - *p_fControlValue) & _xmm) > 0.001 )
    {
      *p_fControlValue = value;
      v42 = 1;
    }
    if ( !v19 )
      goto LABEL_32;
    if ( *mEnvState == eEnvironmentState_FadeIn )
    {
      *mEnvState = eEnvironmentState_Active;
LABEL_48:
      v32 = v33;
      goto LABEL_49;
    }
    if ( *mEnvState == eEnvironmentState_FadeOut )
    {
      *mEnvState = eEnvironmentState_FadeOutFinished;
    }
    else
    {
LABEL_32:
      if ( *mEnvState != eEnvironmentState_FadeOutFinished )
        goto LABEL_48;
    }
    v42 = 1;
    UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::TiDo::sm_audioLoadMutex);
    if ( UFG::TiDo::sm_shuttingDown )
    {
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::TiDo::sm_audioLoadMutex);
    }
    else
    {
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::TiDo::sm_audioLoadMutex);
      if ( v34.mUID - 1 <= 0xFFFFFFFD )
      {
        v20 = UFG::qBaseTreeRB::Get(&UFG::SoundBankManager::sm_soundBank_Tree.mTree, v34.mUID);
        if ( v20 )
        {
          v21 = &v20[-1].mCount;
          if ( v20 != (UFG::qBaseTreeRB *)8 )
          {
            v22 = v21[19];
            if ( v22 )
              v21[19] = v22 - 1;
          }
        }
      }
    }
    v23 = v6;
    if ( v6 < 3 )
    {
      if ( v7 >= 4 )
      {
        v24 = v35;
        v25 = v37;
        v26 = v39;
        v27 = ((unsigned __int64)(-1 - v6) >> 2) + 1;
        v23 = v6 + 4 * v27;
        do
        {
          v26[-1].auxBusID = v26->auxBusID;
          v26[-1].fControlValue = v26->fControlValue;
          *(v25 - 1) = *v25;
          *(v24 - 1) = *v24;
          v25[9] = v25[10];
          v25[3] = v25[4];
          v26->auxBusID = v26[1].auxBusID;
          v26->fControlValue = v26[1].fControlValue;
          *v25 = v25[1];
          *v24 = v24[1];
          v25[10] = v25[11];
          v25[4] = v25[5];
          v26[1].auxBusID = v26[2].auxBusID;
          v26[1].fControlValue = v26[2].fControlValue;
          v25[1] = v25[2];
          v24[1] = v24[2];
          v25[11] = v25[12];
          v25[5] = v25[6];
          v26[2].auxBusID = v26[3].auxBusID;
          v26[2].fControlValue = v26[3].fControlValue;
          v25[2] = v25[3];
          v24[2] = v24[3];
          v25[12] = v25[13];
          v25[6] = v25[7];
          v24 += 4;
          v25 += 4;
          v26 += 4;
          --v27;
        }
        while ( v27 );
      }
      if ( v23 < 3 )
      {
        v28 = &this->m_environment.mEnvCount[v23];
        v29 = &this->m_environment.mVolume[v23];
        v30 = &this->m_environment.mAuxSendValues[v23];
        v31 = 3 - v23;
        do
        {
          v30->auxBusID = v30[1].auxBusID;
          v30->fControlValue = v30[1].fControlValue;
          *v29 = v29[1];
          *v28 = v28[1];
          v29[10] = v29[11];
          v29[4] = v29[5];
          ++v28;
          ++v29;
          ++v30;
          --v31;
        }
        while ( v31 );
      }
    }
    this->m_environment.mAuxSendValues[3] = 0i64;
    this->m_environment.mVolume[3] = 0.0;
    this->m_environment.mEnvCount[3] = 0;
    this->m_environment.mEnvState[3] = eEnvironmentState_Inactive;
    this->m_environment.mVolumeOverride[3] = 0.0;
    v32 = v33 - 1;
    --v6;
    --v35;
    --mEnvState;
    --mVolumeOverride;
    --mVolume;
    v37 = (UFG::AudioEntity *)((char *)v37 - 4);
    p_m_environment = (UFG::WwiseEnvironment *)((char *)p_m_environment - 8);
    p_fControlValue -= 2;
    --v39;
    ++v7;
    --this->m_environment.totalEnv;
LABEL_49:
    _((AMD_HD3D *)v34.mUID);
    _((AMD_HD3D *)result.mUID);
    v33 = v32 + 1;
    ++v6;
    ++v35;
    ++mEnvState;
    ++mVolumeOverride;
    ++mVolume;
    v37 = (UFG::AudioEntity *)((char *)v37 + 4);
    p_m_environment = (UFG::WwiseEnvironment *)((char *)p_m_environment + 8);
    p_fControlValue += 2;
    ++v39;
    --v7;
  }
  while ( v32 + 1 < this->m_environment.totalEnv );
  if ( v42 && !UFG::WwiseInterface::smShuttingDown && AK::SoundEngine::IsInitialized() )
  {
    AK::SoundEngine::SetGameObjectAuxSendValues(
      (unsigned __int64)this,
      this->m_environment.mAuxSendValues,
      this->m_environment.totalEnv);
    AK::SoundEngine::SetGameObjectOutputBusVolume((unsigned __int64)this, this->m_environment.mDryLevel);
  }
}

// File Line: 1242
// RVA: 0x144420
float __fastcall UFG::AudioEntity::Debug_GetRtpcValue(UFG::AudioEntity *this, unsigned int rtpcId, bool *global)
{
  float result; // xmm0_4
  float out_rfValue[6]; // [rsp+20h] [rbp-18h] BYREF
  AK::SoundEngine::Query::RTPCValue_type io_rValueType; // [rsp+58h] [rbp+20h] BYREF

  out_rfValue[0] = 0.0;
  io_rValueType = RTPCValue_GameObject;
  AK::SoundEngine::Query::GetRTPCValue(rtpcId, (unsigned __int64)this, out_rfValue, &io_rValueType);
  result = out_rfValue[0];
  *global = io_rValueType == RTPCValue_Global;
  return result;
}

// File Line: 1260
// RVA: 0x14657F0
__int64 UFG::_dynamic_initializer_for__velocity__()
{
  velocity.mUID = UFG::qWiseSymbolUIDFromString("velocity", 0x811C9DC5);
  _((AMD_HD3D *)velocity.mUID);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__velocity__);
}

// File Line: 1263
// RVA: 0x144490
void __fastcall UFG::AudioEntity::Debug_Render(UFG::AudioEntity *this)
{
  UFG::qSymbolUC *Name; // rax
  char *v3; // rax
  Render::DebugDrawContext *Context; // rbp
  UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> **p_mNext; // rbx
  UFG::EventInfo **i; // rdi
  __int64 (__fastcall **v7)(); // rax
  UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> **v8; // rbx
  __int64 v9[3]; // [rsp+38h] [rbp-70h] BYREF
  __int64 (__fastcall **v10)(); // [rsp+50h] [rbp-58h] BYREF
  UFG::qString v11; // [rsp+58h] [rbp-50h] BYREF
  int v12; // [rsp+80h] [rbp-28h]
  UFG::qSymbol v13; // [rsp+B8h] [rbp+10h] BYREF

  if ( UFG::AudioEntity::sm_debugInfo )
  {
    if ( !UFG::AudioEntity::sm_entityInfoFilter.mLength
      || (Name = (UFG::qSymbolUC *)UFG::AudioEntity::GetName(this, &v13),
          v3 = UFG::qSymbol::as_cstr_dbg(Name),
          strstr(v3, UFG::AudioEntity::sm_entityInfoFilter.mData)) )
    {
      Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(
                                              Render::DebugDrawManager::mInstance,
                                              1u);
      Render::DebugDrawContext::DrawAxes(Context, &this->m_WorldMatrix, 0.2, 0, 0i64);
      Render::DebugDrawContext::DrawText(
        Context,
        (UFG::qVector3 *)&this->m_WorldMatrix.v3,
        &UFG::qColour::Green,
        "%s",
        &customCaption);
      v10 = &`UFG::AudioEntity::Debug_Render::`11::BuildEventDebugString::`vftable;
      UFG::qString::qString(&v11);
      v12 = 0;
      p_mNext = &this->m_events.mNode.mNext[-1].mNext;
      for ( i = &this->m_eventInfos.p;
            p_mNext != (UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> **)i;
            p_mNext = &p_mNext[2][-1].mNext )
      {
        ((void (__fastcall *)(__int64 (__fastcall ***)(), UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> **))*v10)(
          &v10,
          p_mNext);
      }
      v7 = &`UFG::AudioEntity::Debug_Render::`12::RenderDebugSphere::`vftable;
      v9[0] = (__int64)&`UFG::AudioEntity::Debug_Render::`12::RenderDebugSphere::`vftable;
      v9[2] = (__int64)this;
      v9[1] = (__int64)Context;
      v8 = &this->m_events.mNode.mNext[-1].mNext;
      if ( v8 != (UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> **)i )
      {
        while ( 1 )
        {
          ((void (__fastcall *)(__int64 *, UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> **))*v7)(v9, v8);
          v8 = &v8[2][-1].mNext;
          if ( v8 == (UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> **)i )
            break;
          v7 = (__int64 (__fastcall **)())v9[0];
        }
      }
      Render::DebugDrawContext::DrawText(
        Context,
        (UFG::qVector3 *)&this->m_WorldMatrix.v3,
        &UFG::qColour::Green,
        "%s",
        v11.mData);
      UFG::qString::~qString(&v11);
    }
  }
}

// File Line: 1286
// RVA: 0x144C30
void __fastcall UFG::AudioEntity::Debug_Render_::_11_::BuildEventDebugString::Do(UFG::AudioEvent *pAe, __int64 a2)
{
  unsigned __int64 v4; // rdx
  float v5; // xmm8_4
  float v6; // xmm7_4
  double v7; // xmm6_8
  UFG::qSymbolUC *Name; // rax
  char *v9; // rax
  unsigned int v10; // ebx
  const char *v11; // rax
  __int64 v12; // r8
  UFG::qString v13; // [rsp+38h] [rbp-60h] BYREF
  UFG::qSymbol result; // [rsp+A0h] [rbp+8h] BYREF
  int v15; // [rsp+A8h] [rbp+10h] BYREF

  if ( !LODWORD(pAe->m_InitParams.m_EventPlayEndCallback) )
  {
    v4 = *(_QWORD *)(a2 + 104);
    v5 = *(float *)(v4 + 120);
    v6 = *(float *)(v4 + 128);
    *(float *)&result.mUID = 0.0;
    v15 = 2;
    AK::SoundEngine::Query::GetRTPCValue(
      velocity.mUID,
      v4,
      (float *)&result.mUID,
      (AK::SoundEngine::Query::RTPCValue_type *)&v15);
    v7 = *(float *)&result.mUID;
    Name = (UFG::qSymbolUC *)UFG::AudioEntity::GetName(*(UFG::AudioEntity **)(a2 + 104), &result);
    v9 = UFG::qSymbol::as_cstr_dbg(Name);
    UFG::qString::FormatEx(&v13, "%s obs: %f, occ %f\n vel %f", v9, v5, v6, v7, -2i64);
    UFG::qString::append((UFG::qString *)&pAe->UFG::qNode<UFG::AudioEvent,UFG::AudioEvent>, v13.mData, v13.mLength);
    UFG::qString::~qString(&v13);
  }
  v10 = *(_DWORD *)(a2 + 32);
  UFG::TiDo::LoadEventSymbols(UFG::TiDo::m_pInstance);
  v11 = UFG::qWiseSymbolRegistry::Get(v10);
  v12 = -1i64;
  do
    ++v12;
  while ( v11[v12] );
  UFG::qString::append((UFG::qString *)&pAe->UFG::qNode<UFG::AudioEvent,UFG::AudioEvent>, v11, v12);
  UFG::qString::append((UFG::qString *)&pAe->UFG::qNode<UFG::AudioEvent,UFG::AudioEvent>, "\n", 1u);
  ++LODWORD(pAe->m_InitParams.m_EventPlayEndCallback);
}

// File Line: 1323
// RVA: 0x144E70
void __fastcall UFG::AudioEntity::Debug_Render_::_12_::RenderDebugSphere::Do(UFG::AudioEvent *pAe, __int64 a2)
{
  bool v2; // zf
  unsigned int v3; // edx
  UFG::qBaseTreeRB *v5; // rax
  UFG::qColour *v6; // r9
  float v7; // xmm2_4
  UFG::qBaseTreeRB *v8; // rax

  v2 = (*(_BYTE *)(a2 + 144) & 0x40) == 0;
  v3 = *(_DWORD *)(a2 + 32);
  if ( v2 )
  {
    if ( v3 && (v8 = UFG::qBaseTreeRB::Get(&UFG::AudioEventPropertyManager::mDatabase.mTree, v3)) != 0i64 )
      v7 = *((float *)v8->mNULL.mChild[0][3].mChild + 1);
    else
      v7 = 0.0;
    v6 = &UFG::qColour::Black;
  }
  else if ( v3 && (v5 = UFG::qBaseTreeRB::Get(&UFG::AudioEventPropertyManager::mDatabase.mTree, v3)) != 0i64 )
  {
    v6 = &UFG::qColour::ForestGreen;
    v7 = *((float *)v5->mNULL.mChild[0][3].mChild + 1);
  }
  else
  {
    v7 = 0.0;
    v6 = &UFG::qColour::ForestGreen;
  }
  Render::DebugDrawContext::DrawSphere(
    (Render::DebugDrawContext *)pAe->mPrev,
    (UFG::qVector3 *)&pAe->UFG::qNode<UFG::AudioEvent,UFG::AudioEvent>::mNext[5],
    v7,
    v6,
    &UFG::qMatrix44::msIdentity,
    0i64);
}

// File Line: 1353
// RVA: 0x146870
float __fastcall UFG::AudioEntity::GetWetLevelForEffect(UFG::AudioEntity *this, unsigned int id)
{
  float result; // xmm0_4

  result = 0.0;
  if ( this->m_environment.mAuxSendValues[0].auxBusID == id )
    result = this->m_environment.mVolume[0];
  if ( this->m_environment.mAuxSendValues[1].auxBusID == id )
    result = this->m_environment.mVolume[1];
  if ( this->m_environment.mAuxSendValues[2].auxBusID == id )
    result = this->m_environment.mVolume[2];
  if ( this->m_environment.mAuxSendValues[3].auxBusID == id )
    return this->m_environment.mVolume[3];
  return result;
}

// File Line: 1403
// RVA: 0x145C50
UFG::RegionContainmentInfo *__fastcall UFG::AudioEntity::GetContainmentInfo(UFG::AudioEntity *this)
{
  return &this->m_containmentInfo;
}

// File Line: 1410
// RVA: 0x143B30
void __fastcall UFG::AudioEntity::ClearContainmentInfo(UFG::AudioEntity *this)
{
  UFG::qSymbol *p; // rcx
  UFG::qSymbol *v3; // rbx

  p = this->m_containmentInfo.m_regionsContainedIn.p;
  if ( p )
  {
    v3 = p - 1;
    `eh vector destructor iterator(p, 4ui64, p[-1].mUID, (void (__fastcall *)(void *))_);
    operator delete[](v3);
  }
  this->m_containmentInfo.m_regionsContainedIn.p = 0i64;
  *(_QWORD *)&this->m_containmentInfo.m_regionsContainedIn.size = 0i64;
}

