// File Line: 23
// RVA: 0x140380
void __fastcall UFG::AudioEntityRegionData::AudioEntityRegionData(UFG::AudioEntityRegionData *this, UFG::AudioEntity *parent)
{
  this->m_parent = parent;
  this->vfptr = (UFG::AudioEntityRegionDataVtbl *)&UFG::AudioEntityRegionData::`vftable';
  parent->m_pRegionData = this;
}

// File Line: 30
// RVA: 0x141130
void __fastcall UFG::AudioEntityRegionData::~AudioEntityRegionData(UFG::AudioEntityRegionData *this)
{
  this->m_parent = 0i64;
  this->vfptr = (UFG::AudioEntityRegionDataVtbl *)&UFG::AudioEntityRegionData::`vftable';
}

// File Line: 36
// RVA: 0x1465150
__int64 dynamic_initializer_for__UFG::AudioEntity::sm_environmentInfoFilter__()
{
  UFG::qString::qString(&UFG::AudioEntity::sm_environmentInfoFilter);
  return atexit(dynamic_atexit_destructor_for__UFG::AudioEntity::sm_environmentInfoFilter__);
}

// File Line: 37
// RVA: 0x1465130
__int64 dynamic_initializer_for__UFG::AudioEntity::sm_entityInfoFilter__()
{
  UFG::qString::qString(&UFG::AudioEntity::sm_entityInfoFilter);
  return atexit(dynamic_atexit_destructor_for__UFG::AudioEntity::sm_entityInfoFilter__);
}

// File Line: 58
// RVA: 0x1400C0
void __fastcall UFG::AudioEntity::AudioEntity(UFG::AudioEntity *this)
{
  UFG::AudioEntity *v1; // rbx
  UFG::qNode<UFG::AudioEntity,UFG::AudioEntity> *v2; // rax
  float v3; // xmm1_4
  float v4; // xmm2_4
  float v5; // xmm3_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm3_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm3_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  signed __int64 v15; // rax
  UFG::WwiseEnvironment::EnvironmentState *v16; // rcx
  unsigned __int16 *v17; // rdx
  UFG::AudioEntityMotionData *v18; // rax
  float v19; // xmm1_4
  float v20; // xmm2_4
  UFG::AudioEntityMotionData *v21; // rax
  float v22; // xmm1_4
  float v23; // xmm2_4
  UFG::AudioEntityMotionData *v24; // rax
  float v25; // xmm1_4
  float v26; // xmm2_4
  bool v27; // al
  UFG::qList<UFG::AudioEvent,UFG::AudioEvent,1,0> *v28; // [rsp+48h] [rbp+10h]

  v1 = this;
  v2 = (UFG::qNode<UFG::AudioEntity,UFG::AudioEntity> *)&this->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->vfptr = (UFG::AudioEntityVtbl *)&UFG::AudioEntity::`vftable';
  this->m_name = UFG::gNullQSymbol;
  this->m_bEnableEnvironments = 1;
  v3 = UFG::qMatrix44::msIdentity.v0.y;
  v4 = UFG::qMatrix44::msIdentity.v0.z;
  v5 = UFG::qMatrix44::msIdentity.v0.w;
  this->m_WorldMatrix.v0.x = UFG::qMatrix44::msIdentity.v0.x;
  this->m_WorldMatrix.v0.y = v3;
  this->m_WorldMatrix.v0.z = v4;
  this->m_WorldMatrix.v0.w = v5;
  v6 = UFG::qMatrix44::msIdentity.v1.y;
  v7 = UFG::qMatrix44::msIdentity.v1.z;
  v8 = UFG::qMatrix44::msIdentity.v1.w;
  this->m_WorldMatrix.v1.x = UFG::qMatrix44::msIdentity.v1.x;
  this->m_WorldMatrix.v1.y = v6;
  this->m_WorldMatrix.v1.z = v7;
  this->m_WorldMatrix.v1.w = v8;
  v9 = UFG::qMatrix44::msIdentity.v2.y;
  v10 = UFG::qMatrix44::msIdentity.v2.z;
  v11 = UFG::qMatrix44::msIdentity.v2.w;
  this->m_WorldMatrix.v2.x = UFG::qMatrix44::msIdentity.v2.x;
  this->m_WorldMatrix.v2.y = v9;
  this->m_WorldMatrix.v2.z = v10;
  this->m_WorldMatrix.v2.w = v11;
  v12 = UFG::qMatrix44::msIdentity.v3.y;
  v13 = UFG::qMatrix44::msIdentity.v3.z;
  v14 = UFG::qMatrix44::msIdentity.v3.w;
  this->m_WorldMatrix.v3.x = UFG::qMatrix44::msIdentity.v3.x;
  this->m_WorldMatrix.v3.y = v12;
  this->m_WorldMatrix.v3.z = v13;
  this->m_WorldMatrix.v3.w = v14;
  this->m_pMotionData = 0i64;
  this->m_pRegionData = 0i64;
  *(_QWORD *)&this->m_fLastDoppler = 0i64;
  this->m_obstruction = 0i64;
  this->m_occlusion = 0i64;
  *(_QWORD *)&this->m_environment.mDryLevel = 1065353216i64;
  v15 = 0i64;
  v16 = this->m_environment.mEnvState;
  v17 = v1->m_environment.mEnvCount;
  do
  {
    *((_DWORD *)v16 - 10) = 0;
    *v17 = 0;
    *v16 = 0;
    *((_DWORD *)v16 - 6) = 1065353216;
    v1->m_environment.mAuxSendValues[v15++] = 0i64;
    ++v17;
    ++v16;
  }
  while ( v15 < 4 );
  UFG::RegionContainmentInfo::RegionContainmentInfo(&v1->m_containmentInfo);
  v1->m_interiorCount = 0;
  v1->m_eventInfos.p = 0i64;
  *(_QWORD *)&v1->m_eventInfos.size = 0i64;
  v28 = &v1->m_events;
  v28->mNode.mPrev = &v28->mNode;
  v28->mNode.mNext = &v28->mNode;
  *(_DWORD *)&v1->m_bIsInitialized = 16777472;
  *(_WORD *)&v1->m_bPositionIsDirty = 1;
  v1->m_inDoorRegion = 0;
  v18 = v1->m_pMotionData;
  if ( v18 )
  {
    v19 = UFG::qVector3::msZero.y;
    v20 = UFG::qVector3::msZero.z;
    v18->m_vLastPosition.x = UFG::qVector3::msZero.x;
    v18->m_vLastPosition.y = v19;
    v18->m_vLastPosition.z = v20;
  }
  v21 = v1->m_pMotionData;
  if ( v21 )
  {
    v22 = UFG::qVector3::msZero.y;
    v23 = UFG::qVector3::msZero.z;
    v21->m_vCurVelocity.x = UFG::qVector3::msZero.x;
    v21->m_vCurVelocity.y = v22;
    v21->m_vCurVelocity.z = v23;
  }
  v24 = v1->m_pMotionData;
  if ( v24 )
  {
    v25 = UFG::qVector3::msZero.y;
    v26 = UFG::qVector3::msZero.z;
    v24->m_vPrevVelocity.x = UFG::qVector3::msZero.x;
    v24->m_vPrevVelocity.y = v25;
    v24->m_vPrevVelocity.z = v26;
  }
  v1->m_spreadRegionChecks = 1;
  v1->m_regionCheckFrame = UFG::Metrics::msInstance.mSimFrameCount
                         + (unsigned __int8)(UFG::qRandom(UFG::AudioEntity::sm_RegionCheckSpread, &UFG::qDefaultSeed) + 1);
  v1->m_obstruction = 0i64;
  v1->m_occlusion = 0i64;
  v27 = oddFrame;
  v1->m_oddFrame = oddFrame;
  oddFrame = v27 == 0;
  if ( UFG::TiDo::m_pInstance )
    UFG::TiDo::m_pInstance->vfptr->CreateAudioEntityRegionData(UFG::TiDo::m_pInstance, v1);
}

// File Line: 83
// RVA: 0x141050
void __fastcall UFG::AudioEntity::~AudioEntity(UFG::AudioEntity *this)
{
  UFG::AudioEntity *v1; // rdi
  UFG::AudioEntityMotionData *v2; // rdx
  UFG::AudioEntityRegionData *v3; // rcx
  UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> *v4; // rcx
  UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> *v5; // rax
  UFG::EventInfo *v6; // rcx
  UFG::qNode<UFG::AudioEntity,UFG::AudioEntity> *v7; // rdx
  UFG::qNode<UFG::AudioEntity,UFG::AudioEntity> *v8; // rcx
  UFG::qNode<UFG::AudioEntity,UFG::AudioEntity> *v9; // rax

  v1 = this;
  this->vfptr = (UFG::AudioEntityVtbl *)&UFG::AudioEntity::`vftable';
  UFG::AudioEntity::Shutdown(this);
  v2 = v1->m_pMotionData;
  if ( v2 )
  {
    UFG::qMemoryPool::Free(&g_AudioComponentPool, v2);
    v1->m_pMotionData = 0i64;
  }
  v3 = v1->m_pRegionData;
  if ( v3 )
  {
    v3->vfptr->__vecDelDtor(v3, 1u);
    v1->m_pRegionData = 0i64;
  }
  UFG::qList<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption,1,0>::DeleteNodes((UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)&v1->m_events);
  v4 = v1->m_events.mNode.mPrev;
  v5 = v1->m_events.mNode.mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  v1->m_events.mNode.mPrev = &v1->m_events.mNode;
  v1->m_events.mNode.mNext = &v1->m_events.mNode;
  v6 = v1->m_eventInfos.p;
  if ( v6 )
    operator delete[](v6);
  v1->m_eventInfos.p = 0i64;
  *(_QWORD *)&v1->m_eventInfos.size = 0i64;
  UFG::RegionContainmentInfo::~RegionContainmentInfo(&v1->m_containmentInfo);
  v7 = (UFG::qNode<UFG::AudioEntity,UFG::AudioEntity> *)&v1->mPrev;
  v8 = v1->mPrev;
  v9 = v1->mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v7->mPrev = v7;
  v7->mNext = v7;
}

// File Line: 103
// RVA: 0x146A50
void __fastcall UFG::AudioEntity::Init(UFG::AudioEntity *this, UFG::qSymbol *object_name, UFG::qMatrix44 *transform)
{
  UFG::qMatrix44 *v3; // rbp
  UFG::qSymbolUC *v4; // rbx
  UFG::AudioEntity *v5; // rdi
  char *v6; // rax
  char *v7; // rax
  char v8; // al
  UFG::qNode<UFG::AudioEntity,UFG::AudioEntity> *v9; // rcx
  UFG::qNode<UFG::AudioEntity,UFG::AudioEntity> *v10; // rax
  UFG::AudioEntityMotionData *v11; // rax
  float v12; // xmm1_4
  float v13; // xmm2_4
  UFG::AudioEntityMotionData *v14; // rax
  float v15; // xmm1_4
  float v16; // xmm2_4
  UFG::AudioEntityMotionData *v17; // rax
  float v18; // xmm1_4
  float v19; // xmm2_4
  UFG::qVector4 v20; // xmm3
  UFG::qVector4 v21; // xmm2
  UFG::qVector4 v22; // xmm1
  UFG::qSymbol *v23; // rcx
  UFG::qSymbol *v24; // rbx
  UFG::AudioEntityRegionData *v25; // rcx
  float v26; // xmm2_4
  float v27; // xmm0_4
  UFG::AudioEntityRegionData *v28; // rcx
  float v29; // xmm6_4
  float v30; // xmm1_4
  float v31; // xmm1_4
  char *v32; // [rsp+80h] [rbp+8h]
  float v33; // [rsp+98h] [rbp+20h]

  v3 = transform;
  v4 = (UFG::qSymbolUC *)object_name;
  v5 = this;
  if ( !this->m_bIsInitialized )
  {
    v6 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0x30ui64, "AudioEntityMotionData", 0i64, 1u);
    v32 = v6;
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
    v5->m_pMotionData = (UFG::AudioEntityMotionData *)v6;
    v5->m_name.mUID = v4->mUID;
    v7 = UFG::qSymbol::as_cstr_dbg(v4);
    if ( AK::SoundEngine::RegisterGameObj((unsigned __int64)v5, v7, 1u) == 1 )
    {
      ++UFG::AudioEntityManager::sm_NumEntities;
      v9 = (UFG::qNode<UFG::AudioEntity,UFG::AudioEntity> *)&v5->mPrev;
      v10 = UFG::AudioEntityManager::sm_EntityList.mNode.mNext;
      UFG::AudioEntityManager::sm_EntityList.mNode.mNext = v9;
      v9->mPrev = (UFG::qNode<UFG::AudioEntity,UFG::AudioEntity> *)&UFG::AudioEntityManager::sm_EntityList;
      v9->mNext = v10;
      v10->mPrev = (UFG::qNode<UFG::AudioEntity,UFG::AudioEntity> *)&v5->mPrev;
      v8 = 1;
    }
    else
    {
      v8 = 0;
    }
    v5->m_bIsInitialized = v8;
    v11 = v5->m_pMotionData;
    if ( v11 )
    {
      v12 = UFG::qVector3::msZero.y;
      v13 = UFG::qVector3::msZero.z;
      v11->m_vLastPosition.x = UFG::qVector3::msZero.x;
      v11->m_vLastPosition.y = v12;
      v11->m_vLastPosition.z = v13;
    }
    v14 = v5->m_pMotionData;
    if ( v14 )
    {
      v15 = UFG::qVector3::msZero.y;
      v16 = UFG::qVector3::msZero.z;
      v14->m_vCurVelocity.x = UFG::qVector3::msZero.x;
      v14->m_vCurVelocity.y = v15;
      v14->m_vCurVelocity.z = v16;
    }
    v17 = v5->m_pMotionData;
    if ( v17 )
    {
      v18 = UFG::qVector3::msZero.y;
      v19 = UFG::qVector3::msZero.z;
      v17->m_vPrevVelocity.x = UFG::qVector3::msZero.x;
      v17->m_vPrevVelocity.y = v18;
      v17->m_vPrevVelocity.z = v19;
    }
    v20 = v3->v1;
    v21 = v3->v2;
    v22 = v3->v3;
    v5->m_WorldMatrix.v0 = v3->v0;
    v5->m_WorldMatrix.v1 = v20;
    v5->m_WorldMatrix.v2 = v21;
    v5->m_WorldMatrix.v3 = v22;
    v5->m_interiorCount = 0;
    v5->m_inDoorRegion = 0;
    *(_WORD *)&v5->m_bOcclusionIsDirty = 257;
    v5->m_fDistanceUpdateTimeAccumulator = 0.0;
    v23 = v5->m_containmentInfo.m_regionsContainedIn.p;
    if ( v23 )
    {
      v24 = v23 - 1;
      `eh vector destructor iterator'(v23, 4ui64, v23[-1].mUID, (void (__fastcall *)(void *))_);
      operator delete[](v24);
    }
    v5->m_containmentInfo.m_regionsContainedIn.p = 0i64;
    *(_QWORD *)&v5->m_containmentInfo.m_regionsContainedIn.size = 0i64;
    UFG::AudioEntity::ClearEnvironments(v5, 1);
    v25 = v5->m_pRegionData;
    if ( v25 )
    {
      v5->m_regionCheckFrame = UFG::AudioEntity::sm_RegionCheckSpread + UFG::Metrics::msInstance.mSimFrameCount;
      v5->m_bPositionIsDirty = 0;
      ((void (*)(void))v25->vfptr->CheckTriggerRegions)();
    }
    if ( UFG::AudioListener::sm_pInstance )
    {
      v5->m_bOcclusionIsDirty = 0;
      v26 = 0.0;
      v33 = 0.0;
      v27 = 0.0;
      LODWORD(v32) = 0;
      v28 = v5->m_pRegionData;
      v29 = *(float *)&FLOAT_1_0;
      if ( v28 && (v28->vfptr->FindObsOccValues(v28, &v33, (float *)&v32), v26 = v33, v27 = *(float *)&v32, v33 > 0.0) )
      {
        v30 = v33;
        if ( v33 >= 1.0 )
          v30 = *(float *)&FLOAT_1_0;
      }
      else
      {
        v30 = 0.0;
      }
      v5->m_obstruction.m_targetValue = v30;
      if ( v27 <= 0.0 )
      {
        v31 = 0.0;
      }
      else
      {
        v31 = v27;
        if ( v27 >= 1.0 )
          v31 = *(float *)&FLOAT_1_0;
      }
      v5->m_occlusion.m_targetValue = v31;
      if ( v26 <= 0.0 )
      {
        v26 = 0.0;
      }
      else if ( v26 >= 1.0 )
      {
        v26 = *(float *)&FLOAT_1_0;
      }
      v5->m_obstruction.m_currentValue = v26;
      if ( v27 <= 0.0 )
      {
        v27 = 0.0;
      }
      else if ( v27 >= 1.0 )
      {
LABEL_37:
        v5->m_occlusion.m_currentValue = v29;
        if ( !UFG::WwiseInterface::smShuttingDown )
          AK::SoundEngine::SetObjectObstructionAndOcclusion(
            (unsigned __int64)v5,
            UFG::AudioListener::sm_pInstance->m_listenerId,
            v26,
            v29);
        return;
      }
      v29 = v27;
      goto LABEL_37;
    }
  }
}

// File Line: 138
// RVA: 0x14C6D0
void __fastcall UFG::AudioEntity::Shutdown(UFG::AudioEntity *this)
{
  UFG::AudioEntity *v1; // rsi
  UFG::qNode<UFG::AudioEntity,UFG::AudioEntity> *v2; // rdx
  UFG::qNode<UFG::AudioEntity,UFG::AudioEntity> *v3; // rax
  UFG::qNode<UFG::AudioEntity,UFG::AudioEntity> *v4; // r8
  signed __int64 v5; // rbx
  UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> *v6; // rdi
  signed __int64 v7; // rbp
  _QWORD *v8; // rax
  char v9; // al
  unsigned int v10; // ecx
  char v11; // al
  UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> *v12; // rax
  UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> *v13; // rcx
  UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> *v14; // rax
  __int64 v15; // rdx
  void (__fastcall *v16)(__int64, signed __int64, signed __int64, _QWORD); // rax
  _QWORD *i; // rdi
  UFG::qSymbol *v18; // rcx
  UFG::qSymbol *v19; // rbx
  UFG::AudioEntityMotionData *v20; // rdx

  v1 = this;
  if ( this->m_bIsInitialized )
  {
    AK::SoundEngine::UnregisterGameObj((unsigned __int64)this);
    --UFG::AudioEntityManager::sm_NumEntities;
    v2 = v1->mPrev;
    v3 = v1->mNext;
    v4 = (UFG::qNode<UFG::AudioEntity,UFG::AudioEntity> *)&v1->mPrev;
    v2->mNext = v3;
    v3->mPrev = v2;
    v4->mPrev = v4;
    v4->mNext = v4;
    v5 = (signed __int64)&v1->m_events.mNode.mNext[-1].mNext;
    if ( (UFG::EventInfo **)v5 != &v1->m_eventInfos.p )
    {
      do
      {
        v6 = (UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> *)(v5 + 8);
        v7 = *(_QWORD *)(v5 + 16) - 8i64;
        if ( !(*(_BYTE *)(v5 + 144) & 8) )
        {
          v8 = *(_QWORD **)(v5 + 112);
          if ( v8 && *(_DWORD *)(v5 + 32) )
          {
            if ( *v8 )
              *v8 = 0i64;
            **(_QWORD **)(v5 + 112) = 0i64;
            *(_QWORD *)(v5 + 112) = 0i64;
          }
          v9 = *(_BYTE *)(v5 + 144);
          if ( v9 & 0x40 )
          {
            if ( v9 >= 0 )
            {
              v10 = *(_DWORD *)(v5 + 100);
              if ( v10 )
              {
                if ( !UFG::WwiseInterface::smShuttingDown )
                  AK::SoundEngine::StopPlayingID(v10, 0, AkCurveInterpolation_Linear);
              }
            }
          }
          v11 = *(_BYTE *)(v5 + 144);
          if ( !(v11 & 0x40) && v11 >= 0 )
            *(_BYTE *)(v5 + 144) = v11 | 4;
          *(_BYTE *)(v5 + 144) |= 8u;
        }
        if ( *(_QWORD *)(v5 + 104) )
        {
          v12 = *(UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> **)(v5 + 16);
          v13 = v6->mPrev;
          v13->mNext = v12;
          v12->mPrev = v13;
          v6->mPrev = v6;
          *(_QWORD *)(v5 + 16) = v5 + 8;
          v14 = UFG::AudioEventManager::sm_orphanEventList.mNode.mPrev;
          UFG::AudioEventManager::sm_orphanEventList.mNode.mPrev->mNext = v6;
          v6->mPrev = v14;
          *(_QWORD *)(v5 + 16) = &UFG::AudioEventManager::sm_orphanEventList;
          UFG::AudioEventManager::sm_orphanEventList.mNode.mPrev = (UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> *)(v5 + 8);
          v15 = *(_QWORD *)(v5 + 104);
          if ( v15 )
          {
            v16 = *(void (__fastcall **)(__int64, signed __int64, signed __int64, _QWORD))(v5 + 48);
            if ( v16 )
              v16(v15 + *(signed int *)(v5 + 56), 1i64, v5, *(_QWORD *)(v5 + 72));
          }
          if ( *(_QWORD *)(v5 + 104) )
          {
            for ( i = *(_QWORD **)(v5 + 40); i; i = (_QWORD *)i[1] )
              (*(void (__fastcall **)(_QWORD *, signed __int64, signed __int64))(*i + 8i64))(i, v5, 1i64);
          }
          *(_QWORD *)(v5 + 104) = 0i64;
        }
        v5 = v7;
      }
      while ( (UFG::EventInfo **)v7 != &v1->m_eventInfos.p );
    }
    v1->m_bIsInitialized = 0;
    v18 = v1->m_containmentInfo.m_regionsContainedIn.p;
    if ( v18 )
    {
      v19 = v18 - 1;
      `eh vector destructor iterator'(v18, 4ui64, v18[-1].mUID, (void (__fastcall *)(void *))_);
      operator delete[](v19);
    }
    v1->m_containmentInfo.m_regionsContainedIn.p = 0i64;
    *(_QWORD *)&v1->m_containmentInfo.m_regionsContainedIn.size = 0i64;
    v1->m_obstruction = 0i64;
    v1->m_occlusion = 0i64;
    UFG::AudioEntity::ClearEnvironments(v1, 0);
    v20 = v1->m_pMotionData;
    v1->m_bSetOcclusionOverride = 0;
    UFG::qMemoryPool::Free(&g_AudioComponentPool, v20);
    v1->m_pMotionData = 0i64;
  }
}

// File Line: 198
// RVA: 0x14CC60
void __fastcall UFG::AudioEntity::StopAndForgetAllEvents(UFG::AudioEntity *this, float ms)
{
  UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> *v2; // rbx
  UFG::EventInfo **v3; // rdi
  void **v4; // rax
  UFG::AudioEntity *v5; // rbx
  void **v6; // [rsp+20h] [rbp-18h]
  float v7; // [rsp+28h] [rbp-10h]

  v2 = this->m_events.mNode.mNext;
  v3 = &this->m_eventInfos.p;
  v4 = &UFG::StopAndForgetFunctor::`vftable';
  v7 = ms;
  v5 = (UFG::AudioEntity *)&v2[-1].mNext;
  v6 = &UFG::StopAndForgetFunctor::`vftable';
  if ( v5 != (UFG::AudioEntity *)&this->m_eventInfos.p )
  {
    while ( 1 )
    {
      ((void (__fastcall *)(void ***, UFG::AudioEntity *))*v4)(&v6, v5);
      v5 = (UFG::AudioEntity *)&v5->mNext[-1].mNext;
      if ( v5 == (UFG::AudioEntity *)v3 )
        break;
      v4 = v6;
    }
  }
}

// File Line: 210
// RVA: 0x14CCC0
void __fastcall UFG::AudioEntity::StopAndForgetEvent(UFG::AudioEntity *this, unsigned int id, float ms)
{
  UFG::EventInfo **v3; // rdi
  void **v4; // rax
  UFG::AudioEntity *v5; // rbx
  void **v6; // [rsp+20h] [rbp-18h]
  unsigned int v7; // [rsp+28h] [rbp-10h]

  v3 = &this->m_eventInfos.p;
  v4 = &UFG::StopAllEventsOfIdFunctor::`vftable';
  v5 = (UFG::AudioEntity *)&this->m_events.mNode.mNext[-1].mNext;
  v6 = &UFG::StopAllEventsOfIdFunctor::`vftable';
  v7 = id;
  if ( v5 != (UFG::AudioEntity *)&this->m_eventInfos.p )
  {
    while ( 1 )
    {
      ((void (__fastcall *)(void ***, UFG::AudioEntity *))*v4)(&v6, v5);
      v5 = (UFG::AudioEntity *)&v5->mNext[-1].mNext;
      if ( v5 == (UFG::AudioEntity *)v3 )
        break;
      v4 = v6;
    }
  }
}

// File Line: 222
// RVA: 0x1449C0
void __fastcall UFG::AudioEntity::DestroyAllEvents(UFG::AudioEntity *this)
{
  UFG::EventInfo **v1; // rdi
  void **v2; // rax
  UFG::AudioEntity *v3; // rbx
  void **v4; // [rsp+38h] [rbp+10h]

  v1 = &this->m_eventInfos.p;
  v2 = &UFG::DestroyEventFunctor::`vftable';
  v3 = (UFG::AudioEntity *)&this->m_events.mNode.mNext[-1].mNext;
  v4 = &UFG::DestroyEventFunctor::`vftable';
  if ( v3 != (UFG::AudioEntity *)&this->m_eventInfos.p )
  {
    while ( 1 )
    {
      ((void (__fastcall *)(void ***, UFG::AudioEntity *))*v2)(&v4, v3);
      v3 = (UFG::AudioEntity *)&v3->mNext[-1].mNext;
      if ( v3 == (UFG::AudioEntity *)v1 )
        break;
      v2 = v4;
    }
  }
}

// File Line: 233
// RVA: 0x143E70
__int64 __fastcall UFG::AudioEntity::CountNumPlayingEvents(UFG::AudioEntity *this)
{
  UFG::EventInfo **v1; // rdi
  void **v2; // rax
  UFG::AudioEntity *v3; // rbx
  void **v5; // [rsp+20h] [rbp-18h]
  __int64 v6; // [rsp+28h] [rbp-10h]

  v1 = &this->m_eventInfos.p;
  v2 = &UFG::IsIdPlayingFunctor::`vftable';
  v3 = (UFG::AudioEntity *)&this->m_events.mNode.mNext[-1].mNext;
  v6 = 0i64;
  v5 = &UFG::IsIdPlayingFunctor::`vftable';
  if ( v3 == (UFG::AudioEntity *)&this->m_eventInfos.p )
    return 0i64;
  while ( 1 )
  {
    ((void (__fastcall *)(void ***, UFG::AudioEntity *))*v2)(&v5, v3);
    v3 = (UFG::AudioEntity *)&v3->mNext[-1].mNext;
    if ( v3 == (UFG::AudioEntity *)v1 )
      break;
    v2 = v5;
  }
  return HIDWORD(v6);
}

// File Line: 260
// RVA: 0x14B690
void __fastcall UFG::AudioEntity::ResumeAllEvents(UFG::AudioEntity *this)
{
  UFG::EventInfo **v1; // rdi
  void **v2; // rax
  UFG::AudioEntity *v3; // rbx
  void **v4; // [rsp+38h] [rbp+10h]

  v1 = &this->m_eventInfos.p;
  v2 = &UFG::ResumeFunctor::`vftable';
  v3 = (UFG::AudioEntity *)&this->m_events.mNode.mNext[-1].mNext;
  v4 = &UFG::ResumeFunctor::`vftable';
  if ( v3 != (UFG::AudioEntity *)&this->m_eventInfos.p )
  {
    while ( 1 )
    {
      ((void (__fastcall *)(void ***, UFG::AudioEntity *))*v2)(&v4, v3);
      v3 = (UFG::AudioEntity *)&v3->mNext[-1].mNext;
      if ( v3 == (UFG::AudioEntity *)v1 )
        break;
      v2 = v4;
    }
  }
}

// File Line: 271
// RVA: 0x147CD0
bool __fastcall UFG::AudioEntity::IsPlayingId(UFG::AudioEntity *this, unsigned int id)
{
  UFG::EventInfo **v2; // rdi
  void **v3; // rax
  UFG::AudioEntity *v4; // rbx
  __int64 v5; // r8
  void **v7; // [rsp+20h] [rbp-18h]
  unsigned int v8; // [rsp+28h] [rbp-10h]
  int v9; // [rsp+2Ch] [rbp-Ch]

  v2 = &this->m_eventInfos.p;
  v3 = &UFG::IsIdPlayingFunctor::`vftable';
  v4 = (UFG::AudioEntity *)&this->m_events.mNode.mNext[-1].mNext;
  v5 = 0i64;
  v9 = 0;
  v8 = id;
  v7 = &UFG::IsIdPlayingFunctor::`vftable';
  if ( v4 != (UFG::AudioEntity *)&this->m_eventInfos.p )
  {
    while ( 1 )
    {
      ((void (__fastcall *)(void ***, UFG::AudioEntity *, __int64))*v3)(&v7, v4, v5);
      v4 = (UFG::AudioEntity *)&v4->mNext[-1].mNext;
      if ( v4 == (UFG::AudioEntity *)v2 )
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
  UFG::AudioEntity *v2; // rbx
  float v3; // xmm7_4
  UFG::AudioEntityMotionData *v4; // rdx
  bool v5; // si
  float v6; // xmm6_4
  float *v7; // rcx
  float *v8; // rax
  float *v9; // rax
  float v10; // xmm0_4
  float v11; // xmm1_4
  UFG::AudioEntityRegionData *v12; // rcx
  unsigned int v13; // er8
  __int64 v14; // rdx
  float v15; // xmm3_4
  __m128 v16; // xmm2
  float v17; // xmm6_4
  float v18; // xmm0_4
  signed __int64 v19; // rax
  UFG::WwiseEnvironment enviroDBG; // [rsp+20h] [rbp-88h]

  v2 = this;
  v3 = delta_sec;
  if ( !this->m_bIsFollowingListener && UFG::AudioListener::sm_pInstance )
  {
    v4 = (UFG::AudioEntityMotionData *)&this->m_WorldMatrix.v3;
    v5 = 0;
    if ( this->m_pMotionData )
      v4 = this->m_pMotionData;
    v6 = (float)((float)(this->m_WorldMatrix.v3.y - v4->m_vLastPosition.y)
               * (float)(this->m_WorldMatrix.v3.y - v4->m_vLastPosition.y))
       + (float)((float)(this->m_WorldMatrix.v3.x - v4->m_vLastPosition.x)
               * (float)(this->m_WorldMatrix.v3.x - v4->m_vLastPosition.x));
    ((void (*)(void))this->vfptr->UpdateVelocity)();
    v7 = &v2->m_pMotionData->m_vLastPosition.x;
    v8 = v7 + 3;
    if ( !v7 )
      v8 = &v2->m_WorldMatrix.v3.x;
    if ( (float)((float)((float)((float)(v2->m_WorldMatrix.v3.y - v8[1]) * (float)(v2->m_WorldMatrix.v3.y - v8[1]))
                       + (float)((float)(v2->m_WorldMatrix.v3.x - *v8) * (float)(v2->m_WorldMatrix.v3.x - *v8)))
               + (float)((float)(v2->m_WorldMatrix.v3.z - v8[2]) * (float)(v2->m_WorldMatrix.v3.z - v8[2]))) > 1.0 )
    {
      v2->m_bPositionIsDirty = 1;
      v9 = v7 + 3;
      if ( !v7 )
        v9 = &v2->m_WorldMatrix.v3.x;
      if ( UFG::qVector3::msZero.x == *v9 && UFG::qVector3::msZero.y == v9[1] && UFG::qVector3::msZero.z == v9[2] )
        v5 = 1;
      if ( v7 )
      {
        v10 = v2->m_WorldMatrix.v3.y;
        v11 = v2->m_WorldMatrix.v3.z;
        v7[3] = v2->m_WorldMatrix.v3.x;
        v7[4] = v10;
        v7[5] = v11;
      }
    }
    if ( v6 > 0.0099999998 )
      UFG::AudioEntity::ForcePositionUpdate(v2);
    v12 = v2->m_pRegionData;
    if ( v12
      && (!v2->m_spreadRegionChecks
       || UFG::Metrics::msInstance.mSimFrameCount >= v2->m_regionCheckFrame
       || v2->m_bOcclusionIsDirty)
      && v2->m_bPositionIsDirty )
    {
      v13 = UFG::AudioEntity::sm_RegionCheckSpread + UFG::Metrics::msInstance.mSimFrameCount;
      v2->m_bPositionIsDirty = 0;
      v2->m_regionCheckFrame = v13;
      ((void (*)(void))v12->vfptr->CheckTriggerRegions)();
    }
    if ( !v2->m_bSetOcclusionOverride )
      UFG::AudioEntity::SetObsOccValues(v2, v5);
    if ( (COERCE_FLOAT(COERCE_UNSIGNED_INT(v2->m_obstruction.m_currentValue - v2->m_obstruction.m_targetValue) & _xmm) >= 0.0000001
       || COERCE_FLOAT(COERCE_UNSIGNED_INT(v2->m_occlusion.m_currentValue - v2->m_occlusion.m_targetValue) & _xmm) >= 0.0000001)
      && !UFG::WwiseInterface::smShuttingDown )
    {
      AK::SoundEngine::SetObjectObstructionAndOcclusion(
        (unsigned __int64)v2,
        UFG::AudioListener::sm_pInstance->m_listenerId,
        v2->m_obstruction.m_currentValue,
        v2->m_occlusion.m_currentValue);
    }
    UFG::qApproach((float *)&v2->m_obstruction, v2->m_obstruction.m_targetValue, UFG::TiDo::sm_occlusionRate, v3);
    UFG::qApproach((float *)&v2->m_occlusion, v2->m_occlusion.m_targetValue, UFG::TiDo::sm_occlusionRate, v3);
    ((void (__fastcall *)(UFG::AudioEntity *, __int64, UFG::qVector3 *, UFG::qVector3 *))v2->vfptr->CalculateAndApplyDoppler)(
      v2,
      v14,
      &UFG::AudioListener::sm_pInstance->m_position,
      &UFG::AudioListener::sm_pInstance->m_velocity);
    v15 = v3 + v2->m_fDistanceUpdateTimeAccumulator;
    v2->m_fDistanceUpdateTimeAccumulator = v15;
    v16 = (__m128)LODWORD(gAudioListener[0].m_matrix.v3.y);
    v16.m128_f32[0] = (float)((float)((float)(gAudioListener[0].m_matrix.v3.y - v2->m_WorldMatrix.v3.y)
                                    * (float)(gAudioListener[0].m_matrix.v3.y - v2->m_WorldMatrix.v3.y))
                            + (float)((float)(gAudioListener[0].m_matrix.v3.x - v2->m_WorldMatrix.v3.x)
                                    * (float)(gAudioListener[0].m_matrix.v3.x - v2->m_WorldMatrix.v3.x)))
                    + (float)((float)(gAudioListener[0].m_matrix.v3.z - v2->m_WorldMatrix.v3.z)
                            * (float)(gAudioListener[0].m_matrix.v3.z - v2->m_WorldMatrix.v3.z));
    LODWORD(v17) = (unsigned __int128)_mm_sqrt_ps(v16);
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
      if ( v2->m_bIsInitialized )
        UFG::WwiseInterface::SetWwiseRtpcValue(s_uDistanceUID, v17, (unsigned __int64)v2);
      v2->m_fDistanceUpdateTimeAccumulator = 0.0;
    }
    v19 = 0i64;
    do
      enviroDBG.mVolumeOverride[v19++] = 1.0;
    while ( v19 < 4 );
    UFG::AudioEntity::UpdateEnvironments(v2, v17, v3, &enviroDBG);
    UFG::AudioEntity::Debug_Render(v2);
  }
}

// File Line: 386
// RVA: 0x145B00
void __fastcall UFG::AudioEntity::ForcePositionUpdate(UFG::AudioEntity *this)
{
  UFG::AudioEntity *v1; // rbx
  float v2; // xmm1_4
  int v3; // xmm3_4
  float v4; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm0_4
  float *v7; // rcx
  float v8; // xmm0_4
  float v9; // xmm1_4
  AkSoundPosition in_Position; // [rsp+20h] [rbp-68h]
  __int64 v11; // [rsp+70h] [rbp-18h]
  float v12; // [rsp+78h] [rbp-10h]

  v1 = this;
  if ( this->m_bIsInitialized )
  {
    v2 = this->m_WorldMatrix.v3.x;
    v3 = LODWORD(this->m_WorldMatrix.v0.y) ^ _xmm[0];
    LODWORD(v11) = LODWORD(this->m_WorldMatrix.v3.y) ^ _xmm[0];
    v4 = this->m_WorldMatrix.v3.z;
    v12 = v2;
    v5 = this->m_WorldMatrix.v0.x;
    *((float *)&v11 + 1) = v4;
    v6 = this->m_WorldMatrix.v0.z;
    *(_QWORD *)&in_Position.Position.X = v11;
    in_Position.Position.Z = v12;
    LODWORD(in_Position.Orientation.X) = v3;
    in_Position.Orientation.Y = v6;
    in_Position.Orientation.Z = v5;
    AK::SoundEngine::SetPosition((unsigned __int64)this, &in_Position);
    v7 = &v1->m_pMotionData->m_vLastPosition.x;
    if ( v7 )
    {
      v8 = v1->m_WorldMatrix.v3.y;
      v9 = v1->m_WorldMatrix.v3.z;
      *v7 = v1->m_WorldMatrix.v3.x;
      v7[1] = v8;
      v7[2] = v9;
    }
  }
}

// File Line: 400
// RVA: 0x14E7B0
void __fastcall UFG::AudioEntity::UpdateVelocity(UFG::AudioEntity *this, float delta_sec)
{
  UFG::AudioEntityMotionData *v2; // rax
  float v3; // xmm4_4
  float v4; // xmm5_4
  float v5; // xmm3_4
  UFG::AudioEntityMotionData *v6; // rax

  v2 = this->m_pMotionData;
  if ( v2 )
  {
    v3 = UFG::qVector3::msZero.x;
    v4 = UFG::qVector3::msZero.y;
    v5 = UFG::qVector3::msZero.z;
    if ( delta_sec > 0.0 )
    {
      v3 = (float)(1.0 / delta_sec) * (float)(this->m_WorldMatrix.v3.x - v2->m_vLastPosition.x);
      v4 = (float)(1.0 / delta_sec) * (float)(this->m_WorldMatrix.v3.y - v2->m_vLastPosition.y);
      v5 = (float)(1.0 / delta_sec) * (float)(this->m_WorldMatrix.v3.z - v2->m_vLastPosition.z);
    }
    if ( (float)((float)((float)((float)(v4 - v2->m_vPrevVelocity.y) * (float)(v4 - v2->m_vPrevVelocity.y))
                       + (float)((float)(v3 - v2->m_vPrevVelocity.x) * (float)(v3 - v2->m_vPrevVelocity.x)))
               + (float)((float)(v5 - v2->m_vPrevVelocity.z) * (float)(v5 - v2->m_vPrevVelocity.z))) < 2500.0 )
    {
      v2->m_vCurVelocity.x = v3;
      v2->m_vCurVelocity.y = v4;
      v2->m_vCurVelocity.z = v5;
    }
    v6 = this->m_pMotionData;
    if ( v6 )
    {
      v6->m_vPrevVelocity.x = v3;
      v6->m_vPrevVelocity.y = v4;
      v6->m_vPrevVelocity.z = v5;
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
float __fastcall UFG::AudioEntity::CalculateAndApplyDoppler(UFG::AudioEntity *this, float delta_sec, UFG::qVector3 *vListenerPos, UFG::qVector3 *vListenerVelocity)
{
  UFG::AudioEntity *v4; // rbx
  float v5; // xmm8_4
  UFG::AudioEntityMotionData *v7; // rax
  float v8; // xmm7_4
  UFG::qVector3 *v9; // rax
  __m128 v10; // xmm4
  float v11; // xmm6_4
  float v12; // xmm5_4
  __m128 v13; // xmm3
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm0_4
  float v17; // xmm6_4
  float value; // [rsp+90h] [rbp+8h]

  v4 = this;
  v5 = delta_sec;
  if ( this->m_bIsDopplerEnabled )
  {
    v7 = this->m_pMotionData;
    v8 = 0.0;
    if ( v7 )
      v9 = &v7->m_vCurVelocity;
    else
      v9 = &UFG::qVector3::msZero;
    v10 = (__m128)LODWORD(this->m_WorldMatrix.v3.x);
    v10.m128_f32[0] = v10.m128_f32[0] - vListenerPos->x;
    v11 = this->m_WorldMatrix.v3.y - vListenerPos->y;
    v12 = this->m_WorldMatrix.v3.z - vListenerPos->z;
    v13 = v10;
    v13.m128_f32[0] = (float)((float)(v10.m128_f32[0] * v10.m128_f32[0]) + (float)(v11 * v11)) + (float)(v12 * v12);
    if ( v13.m128_f32[0] <= 0.001 )
    {
      if ( COERCE_FLOAT(LODWORD(this->m_fLastDoppler) & _xmm) > 2.0 )
      {
        if ( this->m_bIsInitialized )
          UFG::WwiseInterface::SetWwiseRtpcValue(s_uDopplerUID, 0.0, (unsigned __int64)this);
        v4->m_fLastDoppler = 0.0;
      }
      return v8;
    }
    if ( v13.m128_f32[0] == 0.0 )
      v14 = 0.0;
    else
      v14 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v13));
    v8 = (float)((float)((float)(v11 * v14) * (float)(v9->y - vListenerVelocity->y))
               + (float)((float)(v10.m128_f32[0] * v14) * (float)(v9->x - vListenerVelocity->x)))
       + (float)((float)(v12 * v14) * (float)(v9->z - vListenerVelocity->z));
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
        UFG::qApproach(&value, v17, UFG::TiDo::sm_dopplerRate, v5);
        if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(v4->m_fLastDoppler - v17) & _xmm) > 2.0 )
        {
          if ( v4->m_bIsInitialized )
            UFG::WwiseInterface::SetWwiseRtpcValue(s_uDopplerUID, v17, (unsigned __int64)v4);
          v4->m_fLastDoppler = v17;
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
  bool v2; // di
  UFG::AudioEntity *v3; // rbx
  UFG::AudioEntityMotionData *v4; // rax
  float v5; // xmm1_4
  float v6; // xmm2_4
  UFG::AudioEntityMotionData *v7; // rax
  float v8; // xmm1_4
  float v9; // xmm2_4
  AkSoundPosition in_Position; // [rsp+20h] [rbp-68h]
  __int64 v11; // [rsp+70h] [rbp-18h]
  float v12; // [rsp+78h] [rbp-10h]

  v2 = bEnable;
  v3 = this;
  if ( !bEnable || this->m_bIsFollowingListener )
  {
    this->m_bIsFollowingListener = bEnable;
  }
  else
  {
    v4 = this->m_pMotionData;
    if ( v4 )
    {
      v5 = UFG::qVector3::msZero.y;
      v6 = UFG::qVector3::msZero.z;
      v4->m_vPrevVelocity.x = UFG::qVector3::msZero.x;
      v4->m_vPrevVelocity.y = v5;
      v4->m_vPrevVelocity.z = v6;
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
    v12 = gAudioListener[0].m_matrix.v3.x;
    *(_QWORD *)&in_Position.Position.X = *(_QWORD *)&gAudioListener[0].m_matrix.v3.y ^ (unsigned int)_xmm[0];
    in_Position.Position.Z = gAudioListener[0].m_matrix.v3.x;
    LODWORD(in_Position.Orientation.X) = LODWORD(gAudioListener[0].m_matrix.v0.y) ^ _xmm[0];
    in_Position.Orientation.Y = gAudioListener[0].m_matrix.v0.z;
    in_Position.Orientation.Z = gAudioListener[0].m_matrix.v0.x;
    AK::SoundEngine::SetPosition((unsigned __int64)this, &in_Position);
    v3->m_bIsFollowingListener = v2;
  }
}

// File Line: 503
// RVA: 0x144230
bool __fastcall UFG::AudioEntity::CreateEventA(UFG::AudioEntity *this, unsigned int eventId, UFG::AudioEventController *pEventController, UFG::AudioEventInitParams *pInitParams, UFG::AudioEventExternalSourceInfo *externalSourceInfo)
{
  UFG::AudioEventInitParams *v5; // rbp
  UFG::AudioEventController *v6; // r14
  unsigned int v7; // edi
  UFG::AudioEntity *v8; // rsi
  char *v9; // rax
  __int64 v10; // rax

  v5 = pInitParams;
  v6 = pEventController;
  v7 = eventId;
  v8 = this;
  if ( !this->m_bIsInitialized
    || !(unsigned __int8)AK::SoundEngine::IsInitialized()
    || !v7
    || !UFG::gAudioEventPool.mFreeListHead )
  {
    return 0;
  }
  v9 = UFG::AudioDialogEvent::operator new(0x98ui64);
  if ( v9 )
    UFG::AudioEvent::AudioEvent((UFG::AudioEvent *)v9, v7, v8, v6, v5, externalSourceInfo);
  else
    v10 = 0i64;
  return v10 != 0;
}

// File Line: 531
// RVA: 0x144180
bool __fastcall UFG::AudioEntity::CreateDialogEvent(UFG::AudioEntity *this, UFG::AudioEventController *pEventController, UFG::AudioEventInitParams *pInitParams, UFG::AudioEventExternalSourceInfo *externalSourceInfo)
{
  UFG::AudioEventExternalSourceInfo *v4; // rsi
  UFG::AudioEventInitParams *v5; // rbp
  UFG::AudioEventController *v6; // r14
  UFG::AudioEntity *v7; // rdi
  char *v8; // rax
  __int64 v9; // rax

  v4 = externalSourceInfo;
  v5 = pInitParams;
  v6 = pEventController;
  v7 = this;
  if ( !UFG::gAudioEventPool.mFreeListHead
    || !this->m_bIsInitialized
    || !(unsigned __int8)AK::SoundEngine::IsInitialized() )
  {
    return 0;
  }
  v8 = UFG::AudioDialogEvent::operator new(0x98ui64);
  if ( v8 )
    UFG::AudioDialogEvent::AudioDialogEvent((UFG::AudioDialogEvent *)v8, v7, v6, v5, v4);
  else
    v9 = 0i64;
  return v9 != 0;
}

// File Line: 555
// RVA: 0x144070
char __fastcall UFG::AudioEntity::CreateAndPlayEvent(UFG::AudioEntity *this, unsigned int eventId, UFG::AudioEventController *pEventController, UFG::AudioEventInitParams *pInitParams, unsigned int fadeInDurationMs, UFG::AudioEventExternalSourceInfo *externalSourceInfo)
{
  UFG::AudioEventController *v6; // rbx
  char result; // al

  v6 = pEventController;
  if ( this->m_bIsInitialized
    && UFG::AudioEntity::CreateEventA(this, eventId, pEventController, pInitParams, externalSourceInfo) )
  {
    result = UFG::AudioEventController::Play(v6, fadeInDurationMs);
  }
  else
  {
    result = 0;
  }
  return result;
}

// File Line: 580
// RVA: 0x1440B0
char __fastcall UFG::AudioEntity::CreateAndPlayEvent(UFG::AudioEntity *this, unsigned int eventId, UFG::AudioEventInitParams *pInitParams, unsigned int fadeInDurationMs, UFG::AudioEventExternalSourceInfo *externalSourceInfo)
{
  char v6; // bl
  UFG::AudioEventController pEventController; // [rsp+30h] [rbp-18h]
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
  bool result; // al

  if ( this->m_bIsInitialized )
    result = UFG::WwiseInterface::SetWwiseRtpcValue(rtpcId, value, (unsigned __int64)this);
  else
    result = 0;
  return result;
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
  unsigned int v3; // edi
  unsigned int v4; // esi
  AKRESULT v5; // ebx

  v3 = stateMode;
  v4 = stateId;
  v5 = 2;
  if ( (unsigned __int8)AK::SoundEngine::IsInitialized() && v4 && v3 && !UFG::WwiseInterface::smShuttingDown )
    v5 = AK::SoundEngine::SetState(v4, v3);
  return v5 == 1;
}

// File Line: 642
// RVA: 0x142B70
void __fastcall UFG::AudioEntity::ApplyEnvironment(UFG::AudioEntity *this, unsigned int envId, float volume, float dryLevel, float wetLevel, UFG::qWiseSymbol *envType)
{
  unsigned int v6; // ebp
  UFG::AudioEntity *v7; // rdi
  char v8; // r8
  signed int v9; // esi
  int v10; // edx
  signed __int64 v11; // rcx
  UFG::WwiseEnvironment *v12; // rax
  __int64 v13; // rax
  UFG::qWiseSymbol *v14; // rax
  unsigned int *v15; // r14
  unsigned int v16; // ebx
  const char *v17; // rax
  const char *v18; // rax
  UFG::qWiseSymbol result; // [rsp+20h] [rbp-38h]
  __int64 v20; // [rsp+28h] [rbp-30h]

  if ( envId )
  {
    v20 = -2i64;
    v6 = envId;
    v7 = this;
    if ( this->vfptr->CanApplyEnvironment(this, envType) )
    {
      if ( v7->m_bIsInitialized )
      {
        v8 = 0;
        v9 = 0;
        v10 = 0;
        v11 = 0i64;
        v12 = &v7->m_environment;
        while ( v6 != v12->mAuxSendValues[0].auxBusID )
        {
          ++v10;
          ++v11;
          v12 = (UFG::WwiseEnvironment *)((char *)v12 + 8);
          if ( v11 >= 4 )
          {
            v13 = v7->m_environment.totalEnv;
            if ( (signed int)v13 >= 4 )
            {
              v15 = (unsigned int *)&v7->m_environment;
              do
              {
                v16 = *v15;
                UFG::TiDo::LoadEventSymbols(UFG::TiDo::m_pInstance);
                v17 = UFG::qWiseSymbolRegistry::Get(v16);
                UFG::qPrintf("%u: %s\n", (unsigned int)v9++, v17);
                v15 += 2;
              }
              while ( v9 < 4 );
              UFG::TiDo::LoadEventSymbols(UFG::TiDo::m_pInstance);
              v18 = UFG::qWiseSymbolRegistry::Get(v6);
              UFG::qPrintf("Extra: %s\n", v18);
            }
            else
            {
              v7->m_environment.mAuxSendValues[v13].auxBusID = v6;
              v7->m_environment.mVolume[v13] = wetLevel;
              ++v7->m_environment.mEnvCount[v13];
              v7->m_environment.mEnvState[v13] = 1;
              v7->m_environment.mDryLevel = dryLevel;
              ++v7->m_environment.totalEnv;
              v14 = UFG::qSymbol::qSymbol(&result, v6);
              UFG::TiDo::LoadWwiseBank(v14);
              _((AMD_HD3D *)result.mUID);
            }
LABEL_17:
            if ( !UFG::WwiseInterface::smShuttingDown )
            {
              if ( (unsigned __int8)AK::SoundEngine::IsInitialized() )
              {
                AK::SoundEngine::SetGameObjectAuxSendValues(
                  (unsigned __int64)v7,
                  v7->m_environment.mAuxSendValues,
                  v7->m_environment.totalEnv);
                AK::SoundEngine::SetGameObjectOutputBusVolume((unsigned __int64)v7, v7->m_environment.mDryLevel);
              }
            }
            return;
          }
        }
        ++v7->m_environment.mEnvCount[v10];
        if ( wetLevel != v7->m_environment.mVolume[v10] )
          v8 = 1;
        if ( dryLevel != v7->m_environment.mDryLevel )
          v8 = 1;
        v7->m_environment.mVolume[v10] = wetLevel;
        v7->m_environment.mDryLevel = dryLevel;
        if ( v8 )
          goto LABEL_17;
      }
    }
  }
}

// File Line: 708
// RVA: 0x14B4D0
void __fastcall UFG::AudioEntity::RemoveEnvironment(UFG::AudioEntity *this, unsigned int envId, float dryLevel, float wetLevel)
{
  int v4; // eax
  int v5; // er10
  float *v6; // rax
  UFG::WwiseEnvironment *v7; // r8
  unsigned __int16 *v8; // r9
  bool v9; // zf

  v4 = this->m_environment.totalEnv;
  if ( v4 > 0 )
  {
    v5 = 0;
    if ( v4 > 0 )
    {
      v6 = (float *)this->m_environment.mEnvState;
      v7 = &this->m_environment;
      v8 = this->m_environment.mEnvCount;
      do
      {
        if ( v7->mAuxSendValues[0].auxBusID == envId || !envId )
        {
          v9 = (*v8)-- == 1;
          if ( v9 )
          {
            if ( v7->mAuxSendValues[0].auxBusID )
              *(_DWORD *)v6 = 4;
          }
          else
          {
            *(v6 - 10) = wetLevel;
            this->m_environment.mDryLevel = dryLevel;
          }
        }
        ++v5;
        ++v8;
        v7 = (UFG::WwiseEnvironment *)((char *)v7 + 8);
        ++v6;
      }
      while ( v5 < this->m_environment.totalEnv );
    }
  }
}

// File Line: 736
// RVA: 0x143B90
void __fastcall UFG::AudioEntity::ClearEnvironments(UFG::AudioEntity *this, bool clearThenSet)
{
  bool v2; // r12
  UFG::AudioEntity *v3; // rbp
  _DWORD *v4; // rdi
  unsigned __int16 *v5; // rsi
  unsigned int *v6; // rbx
  signed __int64 v7; // r15
  UFG::qWiseSymbol *v8; // r14
  unsigned int v9; // edx
  UFG::qBaseTreeRB *v10; // rax
  signed __int64 v11; // rcx
  int v12; // eax
  UFG::qWiseSymbol result; // [rsp+68h] [rbp+10h]

  v2 = clearThenSet;
  v3 = this;
  this->m_environment.mDryLevel = 1.0;
  v4 = (_DWORD *)this->m_environment.mVolume;
  v5 = this->m_environment.mEnvCount;
  v6 = (unsigned int *)&this->m_environment;
  v7 = 4i64;
  do
  {
    if ( *v6 )
    {
      v8 = UFG::qSymbol::qSymbol(&result, *v6);
      UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::TiDo::sm_audioLoadMutex);
      if ( UFG::TiDo::sm_shuttingDown )
      {
        UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::TiDo::sm_audioLoadMutex);
      }
      else
      {
        UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::TiDo::sm_audioLoadMutex);
        v9 = v8->mUID;
        if ( v8->mUID )
        {
          if ( v9 != -1 )
          {
            if ( v9 )
            {
              v10 = UFG::qBaseTreeRB::Get(&UFG::SoundBankManager::sm_soundBank_Tree.mTree, v9);
              if ( v10 )
              {
                v11 = (signed __int64)&v10[-1].mCount;
                if ( v10 != (UFG::qBaseTreeRB *)8 )
                {
                  v12 = *(_DWORD *)(v11 + 76);
                  if ( v12 )
                    *(_DWORD *)(v11 + 76) = v12 - 1;
                }
              }
            }
          }
        }
      }
      _((AMD_HD3D *)result.mUID);
    }
    v4[10] = 0;
    *(_QWORD *)v6 = 0i64;
    *v5 = 0;
    *v4 = 0;
    v3->m_environment.totalEnv = 0;
    ++v5;
    ++v4;
    v6 += 2;
    --v7;
  }
  while ( v7 );
  if ( v2 && !UFG::WwiseInterface::smShuttingDown )
  {
    if ( (unsigned __int8)AK::SoundEngine::IsInitialized() )
    {
      AK::SoundEngine::SetGameObjectAuxSendValues(
        (unsigned __int64)v3,
        v3->m_environment.mAuxSendValues,
        v3->m_environment.totalEnv);
      AK::SoundEngine::SetGameObjectOutputBusVolume((unsigned __int64)v3, v3->m_environment.mDryLevel);
    }
  }
}

// File Line: 766
// RVA: 0x14C0B0
void __fastcall UFG::AudioEntity::SetObstructionAndOcclusionTargets(UFG::AudioEntity *this, float obstruction, float occlusion, bool forceToTargetVals)
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
  JUMPOUT(UFG::WwiseInterface::smShuttingDown, 0, AK::SoundEngine::StopAll);
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
  bool v2; // di
  UFG::AudioEntity *v3; // rbx
  float v4; // xmm1_4
  UFG::AudioEntityRegionData *v5; // rcx
  float v6; // xmm2_4
  float obstruction; // [rsp+40h] [rbp+18h]
  float occlusion; // [rsp+48h] [rbp+20h]

  v2 = forceToTargetVals;
  v3 = this;
  if ( UFG::AudioListener::sm_pInstance
    && (forceToTargetVals || this->m_bOcclusionIsDirty && !this->m_bSetOcclusionOverride) )
  {
    v4 = 0.0;
    this->m_bOcclusionIsDirty = 0;
    v5 = this->m_pRegionData;
    v6 = 0.0;
    obstruction = 0.0;
    occlusion = 0.0;
    if ( v5 )
    {
      v5->vfptr->FindObsOccValues(v5, &obstruction, &occlusion);
      v4 = obstruction;
      v6 = occlusion;
    }
    UFG::AudioEntity::SetObstructionAndOcclusionTargets(v3, v4, v6, v2);
  }
}

// File Line: 1083
// RVA: 0x14E050
void __fastcall UFG::AudioEntity::UpdateEnvironments(UFG::AudioEntity *this, float distanceToListener, float delta_sec, UFG::WwiseEnvironment *enviroDBG)
{
  float v4; // xmm11_4
  UFG::AudioEntity *v5; // rbx
  int v6; // eax
  signed __int64 v7; // r14
  signed __int64 v8; // r13
  float *v9; // rbp
  float *v10; // r15
  unsigned int *v11; // r12
  UFG::WwiseEnvironment::EnvironmentState *v12; // rdi
  UFG::qBaseTreeRB *v13; // rax
  signed __int64 v14; // rax
  bool v15; // si
  float v16; // xmm6_4
  unsigned int v17; // eax
  float v18; // xmm2_4
  float v19; // xmm1_4
  bool v20; // al
  UFG::qBaseTreeRB *v21; // rax
  signed __int64 v22; // rcx
  int v23; // eax
  signed __int64 v24; // rsi
  unsigned __int16 *v25; // r10
  _DWORD *v26; // rdx
  AkAuxSendValue *v27; // r9
  unsigned __int64 v28; // r8
  unsigned __int16 *v29; // r10
  _DWORD *v30; // r9
  AkAuxSendValue *v31; // rcx
  signed __int64 v32; // r11
  int v33; // esi
  int v34; // [rsp+20h] [rbp-E8h]
  UFG::qWiseSymbol v35; // [rsp+24h] [rbp-E4h]
  unsigned __int16 *v36; // [rsp+28h] [rbp-E0h]
  float *v37; // [rsp+30h] [rbp-D8h]
  UFG::AudioEntity *v38; // [rsp+38h] [rbp-D0h]
  float value; // [rsp+40h] [rbp-C8h]
  AkAuxSendValue *v40; // [rsp+48h] [rbp-C0h]
  UFG::qWiseSymbol result; // [rsp+50h] [rbp-B8h]
  __int64 v42; // [rsp+58h] [rbp-B0h]
  char v43; // [rsp+110h] [rbp+8h]

  v42 = -2i64;
  v4 = delta_sec;
  v5 = this;
  v6 = this->m_environment.totalEnv;
  if ( v6 <= 0 )
    return;
  v43 = 0;
  v34 = 0;
  v7 = 0i64;
  if ( v6 <= 0 )
    return;
  v8 = 3i64;
  v40 = &this->m_environment.mAuxSendValues[1];
  v38 = (UFG::AudioEntity *)((char *)this + 172);
  v36 = &this->m_environment.mEnvCount[1];
  v9 = &this->m_environment.mAuxSendValues[0].fControlValue;
  v37 = this->m_environment.mVolume;
  v10 = this->m_environment.mVolumeOverride;
  v11 = (unsigned int *)&this->m_environment;
  v12 = this->m_environment.mEnvState;
  do
  {
    UFG::qSymbol::qSymbol(&result, *v11);
    if ( result.mUID
      && (v13 = UFG::qBaseTreeRB::Get(&UFG::SoundBankManager::sm_soundBank_Tree.mTree, result.mUID)) != 0i64
      && (v14 = (signed __int64)&v13[-1].mCount) != 0 )
    {
      v15 = ((*(_DWORD *)(v14 + 112) - 2) & 0xFFFFFFFB) == 0;
    }
    else
    {
      v15 = 1;
    }
    if ( *v12 == 1 && v15 )
      *v12 = 2;
    v16 = 0.0;
    UFG::qSymbol::qSymbol(&v35, *v11);
    v17 = v35.mUID;
    if ( *v12 == 2 )
    {
      *v10 = 1.0;
      if ( v17 == qwsTunnel.mUID )
        v16 = *(float *)&FLOAT_1_0;
      else
        v16 = 0.0;
    }
    if ( *v12 == 4 )
    {
      *v10 = 0.0;
      if ( v17 != qwsTunnel.mUID )
        goto LABEL_21;
      v16 = FLOAT_2_0;
    }
    else if ( v16 <= 0.0 )
    {
LABEL_21:
      v18 = FLOAT_10000_0;
      goto LABEL_22;
    }
    v18 = 1.0 / v16;
LABEL_22:
    if ( v15 )
      v19 = *v10 * *v37;
    else
      v19 = 0.0;
    value = *v9;
    v20 = UFG::qApproach(&value, v19, v18, v4);
    if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(value - *v9) & _xmm) > 0.001 )
    {
      *v9 = value;
      v43 = 1;
    }
    if ( !v20 )
      goto LABEL_56;
    if ( *v12 == 2 )
    {
      *v12 = 3;
LABEL_48:
      v33 = v34;
      goto LABEL_49;
    }
    if ( *v12 == 4 )
    {
      *v12 = 5;
    }
    else
    {
LABEL_56:
      if ( *v12 != 5 )
        goto LABEL_48;
    }
    v43 = 1;
    UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::TiDo::sm_audioLoadMutex);
    if ( UFG::TiDo::sm_shuttingDown )
    {
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::TiDo::sm_audioLoadMutex);
    }
    else
    {
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::TiDo::sm_audioLoadMutex);
      if ( v35.mUID - 1 <= 0xFFFFFFFD )
      {
        v21 = UFG::qBaseTreeRB::Get(&UFG::SoundBankManager::sm_soundBank_Tree.mTree, v35.mUID);
        if ( v21 )
        {
          v22 = (signed __int64)&v21[-1].mCount;
          if ( v21 != (UFG::qBaseTreeRB *)8 )
          {
            v23 = *(_DWORD *)(v22 + 76);
            if ( v23 )
              *(_DWORD *)(v22 + 76) = v23 - 1;
          }
        }
      }
    }
    v24 = v7;
    if ( v7 < 3 )
    {
      if ( v8 >= 4 )
      {
        v25 = v36;
        v26 = v38;
        v27 = v40;
        v28 = ((unsigned __int64)(-1 - v7) >> 2) + 1;
        v24 = v7 + 4 * v28;
        do
        {
          v27[-1].auxBusID = v27->auxBusID;
          v27[-1].fControlValue = v27->fControlValue;
          *(v26 - 1) = *v26;
          *(v25 - 1) = *v25;
          v26[9] = v26[10];
          v26[3] = v26[4];
          v27->auxBusID = v27[1].auxBusID;
          v27->fControlValue = v27[1].fControlValue;
          *v26 = v26[1];
          *v25 = v25[1];
          v26[10] = v26[11];
          v26[4] = v26[5];
          v27[1].auxBusID = v27[2].auxBusID;
          v27[1].fControlValue = v27[2].fControlValue;
          v26[1] = v26[2];
          v25[1] = v25[2];
          v26[11] = v26[12];
          v26[5] = v26[6];
          v27[2].auxBusID = v27[3].auxBusID;
          v27[2].fControlValue = v27[3].fControlValue;
          v26[2] = v26[3];
          v25[2] = v25[3];
          v26[12] = v26[13];
          v26[6] = v26[7];
          v25 += 4;
          v26 += 4;
          v27 += 4;
          --v28;
        }
        while ( v28 );
      }
      if ( v24 < 3 )
      {
        v29 = &v5->m_environment.mEnvCount[v24];
        v30 = (_DWORD *)&v5->m_environment.mVolume[v24];
        v31 = &v5->m_environment.mAuxSendValues[v24];
        v32 = 3 - v24;
        do
        {
          v31->auxBusID = v31[1].auxBusID;
          v31->fControlValue = v31[1].fControlValue;
          *v30 = v30[1];
          *v29 = v29[1];
          v30[10] = v30[11];
          v30[4] = v30[5];
          ++v29;
          ++v30;
          ++v31;
          --v32;
        }
        while ( v32 );
      }
    }
    v5->m_environment.mAuxSendValues[3] = 0i64;
    v5->m_environment.mVolume[3] = 0.0;
    v5->m_environment.mEnvCount[3] = 0;
    v5->m_environment.mEnvState[3] = 0;
    v5->m_environment.mVolumeOverride[3] = 0.0;
    v33 = v34 - 1;
    --v7;
    --v36;
    --v12;
    --v10;
    --v37;
    v38 = (UFG::AudioEntity *)((char *)v38 - 4);
    v11 -= 2;
    v9 -= 2;
    --v40;
    ++v8;
    --v5->m_environment.totalEnv;
LABEL_49:
    _((AMD_HD3D *)v35.mUID);
    _((AMD_HD3D *)result.mUID);
    v34 = v33 + 1;
    ++v7;
    ++v36;
    ++v12;
    ++v10;
    ++v37;
    v38 = (UFG::AudioEntity *)((char *)v38 + 4);
    v11 += 2;
    v9 += 2;
    ++v40;
    --v8;
  }
  while ( v33 + 1 < v5->m_environment.totalEnv );
  if ( v43 && !UFG::WwiseInterface::smShuttingDown )
  {
    if ( (unsigned __int8)AK::SoundEngine::IsInitialized() )
    {
      AK::SoundEngine::SetGameObjectAuxSendValues(
        (unsigned __int64)v5,
        v5->m_environment.mAuxSendValues,
        v5->m_environment.totalEnv);
      AK::SoundEngine::SetGameObjectOutputBusVolume((unsigned __int64)v5, v5->m_environment.mDryLevel);
    }
  }
}

// File Line: 1242
// RVA: 0x144420
float __fastcall UFG::AudioEntity::Debug_GetRtpcValue(UFG::AudioEntity *this, unsigned int rtpcId, bool *global)
{
  bool *v3; // rbx
  float result; // xmm0_4
  float out_rfValue; // [rsp+20h] [rbp-18h]
  AK::SoundEngine::Query::RTPCValue_type io_rValueType; // [rsp+58h] [rbp+20h]

  v3 = global;
  out_rfValue = 0.0;
  io_rValueType = 2;
  AK::SoundEngine::Query::GetRTPCValue(rtpcId, (unsigned __int64)this, &out_rfValue, &io_rValueType);
  result = out_rfValue;
  *v3 = io_rValueType == 1;
  return result;
}

// File Line: 1260
// RVA: 0x14657F0
__int64 UFG::_dynamic_initializer_for__velocity__()
{
  velocity.mUID = UFG::qWiseSymbolUIDFromString("velocity", 0x811C9DC5);
  _((AMD_HD3D *)velocity.mUID);
  return atexit(UFG::_dynamic_atexit_destructor_for__velocity__);
}

// File Line: 1263
// RVA: 0x144490
void __fastcall UFG::AudioEntity::Debug_Render(UFG::AudioEntity *this)
{
  UFG::AudioEntity *v1; // rsi
  UFG::qSymbolUC *v2; // rax
  char *v3; // rax
  Render::DebugDrawContext *v4; // rbp
  signed __int64 v5; // rbx
  signed __int64 i; // rdi
  __int64 (__fastcall **v7)(); // rax
  signed __int64 v8; // rbx
  __int64 (__fastcall **v9)(); // [rsp+38h] [rbp-70h]
  Render::DebugDrawContext *v10; // [rsp+40h] [rbp-68h]
  UFG::AudioEntity *v11; // [rsp+48h] [rbp-60h]
  __int64 (__fastcall **v12)(); // [rsp+50h] [rbp-58h]
  UFG::qString v13; // [rsp+58h] [rbp-50h]
  int v14; // [rsp+80h] [rbp-28h]
  __int64 v15; // [rsp+B8h] [rbp+10h]

  v1 = this;
  if ( UFG::AudioEntity::sm_debugInfo )
  {
    if ( !UFG::AudioEntity::sm_entityInfoFilter.mLength
      || (v2 = (UFG::qSymbolUC *)UFG::AudioEntity::GetName(this, (UFG::qSymbol *)&v15),
          v3 = UFG::qSymbol::as_cstr_dbg(v2),
          strstr(v3, UFG::AudioEntity::sm_entityInfoFilter.mData)) )
    {
      v4 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
      Render::DebugDrawContext::DrawAxes(v4, &v1->m_WorldMatrix, 0.2, 0, 0i64);
      Render::DebugDrawContext::DrawText(
        v4,
        (UFG::qVector3 *)&v1->m_WorldMatrix.v3,
        &UFG::qColour::Green,
        "%s",
        &customWorldMapCaption);
      v12 = &`UFG::AudioEntity::Debug_Render'::`11'::BuildEventDebugString::`vftable';
      UFG::qString::qString(&v13);
      v14 = 0;
      v5 = (signed __int64)&v1->m_events.mNode.mNext[-1].mNext;
      for ( i = (signed __int64)&v1->m_eventInfos.p; v5 != i; v5 = *(_QWORD *)(v5 + 16) - 8i64 )
        ((void (__fastcall *)(__int64 (__fastcall ***)(), signed __int64))*v12)(&v12, v5);
      v7 = &`UFG::AudioEntity::Debug_Render'::`12'::RenderDebugSphere::`vftable';
      v9 = &`UFG::AudioEntity::Debug_Render'::`12'::RenderDebugSphere::`vftable';
      v11 = v1;
      v10 = v4;
      v8 = (signed __int64)&v1->m_events.mNode.mNext[-1].mNext;
      if ( v8 != i )
      {
        while ( 1 )
        {
          ((void (__fastcall *)(__int64 (__fastcall ***)(), signed __int64))*v7)(&v9, v8);
          v8 = *(_QWORD *)(v8 + 16) - 8i64;
          if ( v8 == i )
            break;
          v7 = v9;
        }
      }
      Render::DebugDrawContext::DrawText(
        v4,
        (UFG::qVector3 *)&v1->m_WorldMatrix.v3,
        &UFG::qColour::Green,
        "%s",
        v13.mData);
      UFG::qString::~qString(&v13);
    }
  }
}

// File Line: 1286
// RVA: 0x144C30
void __fastcall UFG::AudioEntity::Debug_Render_::_11_::BuildEventDebugString::Do(UFG::AudioEvent *pAe, __int64 a2)
{
  __int64 v2; // rbx
  UFG::AudioEvent *v3; // rdi
  unsigned __int64 v4; // rdx
  float v5; // xmm8_4
  float v6; // xmm7_4
  double v7; // xmm6_8
  UFG::qSymbolUC *v8; // rax
  char *v9; // rax
  unsigned int v10; // ebx
  const char *v11; // rax
  signed __int64 v12; // r8
  UFG::qString v13; // [rsp+38h] [rbp-60h]
  UFG::qSymbol result; // [rsp+A0h] [rbp+8h]
  int v15; // [rsp+A8h] [rbp+10h]

  v2 = a2;
  v3 = pAe;
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
    v8 = (UFG::qSymbolUC *)UFG::AudioEntity::GetName(*(UFG::AudioEntity **)(v2 + 104), &result);
    v9 = UFG::qSymbol::as_cstr_dbg(v8);
    UFG::qString::FormatEx(&v13, "%s obs: %f, occ %f\n vel %f", v9, v5, v6, v7, -2i64);
    UFG::qString::append((UFG::qString *)&v3->mPrev, v13.mData, v13.mLength);
    UFG::qString::~qString(&v13);
  }
  v10 = *(_DWORD *)(v2 + 32);
  UFG::TiDo::LoadEventSymbols(UFG::TiDo::m_pInstance);
  v11 = UFG::qWiseSymbolRegistry::Get(v10);
  v12 = -1i64;
  do
    ++v12;
  while ( v11[v12] );
  UFG::qString::append((UFG::qString *)&v3->mPrev, v11, v12);
  UFG::qString::append((UFG::qString *)&v3->mPrev, "\n", 1u);
  ++LODWORD(v3->m_InitParams.m_EventPlayEndCallback);
}

// File Line: 1323
// RVA: 0x144E70
void __fastcall UFG::AudioEntity::Debug_Render_::_12_::RenderDebugSphere::Do(UFG::AudioEvent *pAe, __int64 a2)
{
  bool v2; // zf
  unsigned int v3; // edx
  UFG::AudioEvent *v4; // rbx
  UFG::qBaseTreeRB *v5; // rax
  UFG::qColour *v6; // r9
  float v7; // xmm2_4
  UFG::qBaseTreeRB *v8; // rax

  v2 = (*(_BYTE *)(a2 + 144) & 0x40) == 0;
  v3 = *(_DWORD *)(a2 + 32);
  v4 = pAe;
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
    (Render::DebugDrawContext *)v4->mPrev,
    (UFG::qVector3 *)&v4->mNext[5],
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
    result = this->m_environment.mVolume[3];
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
  UFG::AudioEntity *v1; // rdi
  UFG::qSymbol *v2; // rcx
  UFG::qSymbol *v3; // rbx

  v1 = this;
  v2 = this->m_containmentInfo.m_regionsContainedIn.p;
  if ( v2 )
  {
    v3 = v2 - 1;
    `eh vector destructor iterator'(v2, 4ui64, v2[-1].mUID, (void (__fastcall *)(void *))_);
    operator delete[](v3);
  }
  v1->m_containmentInfo.m_regionsContainedIn.p = 0i64;
  *(_QWORD *)&v1->m_containmentInfo.m_regionsContainedIn.size = 0i64;
}

