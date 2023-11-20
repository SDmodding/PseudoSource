// File Line: 79
// RVA: 0x1554940
__int64 dynamic_initializer_for__UFG::AudioEmitterMarker::msAudioEmitterMarkers__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::AudioEmitterMarker::msAudioEmitterMarkers.mTree);
  return atexit(dynamic_atexit_destructor_for__UFG::AudioEmitterMarker::msAudioEmitterMarkers__);
}

// File Line: 83
// RVA: 0x15547F0
__int64 dynamic_initializer_for__UFG::AudioEmitterMarker::_TypeIDesc__()
{
  UFG::ComponentIDDesc *v0; // rax
  __int64 result; // rax

  v0 = UFG::AudioEmitterMarker::AccessComponentDesc();
  *(_DWORD *)&UFG::AudioEmitterMarker::_TypeIDesc.mBaseTypeIndex = *(_DWORD *)&v0->mBaseTypeIndex;
  UFG::AudioEmitterMarker::_TypeIDesc.mChildBitMask = v0->mChildBitMask;
  result = v0->mChildren;
  UFG::AudioEmitterMarker::_TypeIDesc.mChildren = result;
  return result;
}

// File Line: 98
// RVA: 0x592C10
void __fastcall UFG::AudioEmitterMarker::AudioEmitterMarker(UFG::AudioEmitterMarker *this, UFG::qSymbol *name, UFG::SimObject *pSimObj)
{
  UFG::qSymbol *v3; // r15
  UFG::AudioEmitterMarker *v4; // rbp

  v3 = name;
  v4 = this;
  UFG::MarkerBase::MarkerBase((UFG::MarkerBase *)&this->vfptr, name, pSimObj, 0);
  v4->mNode.mParent = 0i64;
  v4->mNode.mChild[0] = 0i64;
  v4->mNode.mChild[1] = 0i64;
  v4->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AudioEmitterMarker::`vftable';
  v4->m_contoller.m_pEvent = 0i64;
  v4->m_entity = 0i64;
  v4->m_eventId.mUID = -1;
  _((AMD_HD3D *)0xFFFFFFFFi64);
  v4->m_bankId.mUID = -1;
  _((AMD_HD3D *)0xFFFFFFFFi64);
  v4->m_rtpcName.mUID = -1;
  _((AMD_HD3D *)0xFFFFFFFFi64);
  *(_QWORD *)&v4->m_falloffDiameter2 = 1159479296i64;
  v4->m_numPlayAttempts = UFG::AudioEmitterMarker::msNumPlayAttempts;
  *((_BYTE *)v4 + 200) &= 0xF8u;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v4->vfptr,
    UFG::AudioEmitterMarker::_AudioEmitterMarkerTypeUID,
    "AudioEmitterMarker");
  v4->mNode.mUID = v3->mUID;
  UFG::qBaseTreeRB::Add(&UFG::AudioEmitterMarker::msAudioEmitterMarkers.mTree, &v4->mNode);
  UFG::qWiseSymbol::set_null(&v4->m_eventId);
  UFG::qWiseSymbol::set_null(&v4->m_bankId);
  UFG::qWiseSymbol::set_null(&v4->m_rtpcName);
  v4->m_rtpcVal = 0.0;
}

// File Line: 123
// RVA: 0x593DB0
void __fastcall UFG::AudioEmitterMarker::~AudioEmitterMarker(UFG::AudioEmitterMarker *this)
{
  UFG::AudioEmitterMarker *v1; // rbx
  UFG::AudioEvent *v2; // rcx

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AudioEmitterMarker::`vftable';
  UFG::AudioEmitterMarker::Stop(this, 0x7D0u);
  UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
    (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::AudioEmitterMarker::msAudioEmitterMarkers,
    (UFG::qBaseNodeVariableRB<unsigned __int64> *)&v1->mNode);
  _((AMD_HD3D *)v1->m_rtpcName.mUID);
  _((AMD_HD3D *)v1->m_bankId.mUID);
  _((AMD_HD3D *)v1->m_eventId.mUID);
  v2 = v1->m_contoller.m_pEvent;
  if ( v2 )
    UFG::AudioEvent::OnControllerDestroy(v2);
  UFG::MarkerBase::~MarkerBase((UFG::MarkerBase *)&v1->vfptr);
}

// File Line: 136
// RVA: 0x59F590
void __fastcall UFG::AudioEmitterMarker::Init(UFG::AudioEmitterMarker *this)
{
  UFG::AudioEmitterMarker *v1; // rdi
  UFG::allocator::free_link *v2; // rax
  UFG::TransformNodeComponent *v3; // rbx

  v1 = this;
  if ( !this->m_entity )
  {
    v2 = UFG::qMalloc(0x140ui64, "AudioEmitter.Entity", 0i64);
    if ( v2 )
      UFG::AudioEntity::AudioEntity((UFG::AudioEntity *)v2);
    v1->m_entity = (UFG::AudioEntity *)v2;
    v3 = v1->mpXformNode;
    UFG::TransformNodeComponent::UpdateWorldTransform(v1->mpXformNode);
    (*(void (__fastcall **)(UFG::AudioEntity *, UFG::qSymbol *, UFG::qMatrix44 *))v1->m_entity->vfptr->gap8)(
      v1->m_entity,
      &v1->m_pSimObject->m_Name,
      &v3->mWorldTransform);
  }
}

// File Line: 150
// RVA: 0x5AA4B0
void __fastcall UFG::AudioEmitterMarker::Reset(UFG::AudioEmitterMarker *this)
{
  UFG::AudioEvent *v1; // rax
  UFG::AudioEmitterMarker *v2; // rbx
  UFG::AudioEvent *v3; // rcx
  UFG::AudioEntity *v4; // rcx
  UFG::AudioEntity *v5; // rcx

  v1 = this->m_contoller.m_pEvent;
  v2 = this;
  if ( v1 && (*((_BYTE *)v1 + 144) >> 6) & 1 )
  {
    if ( *((_BYTE *)this + 200) & 4 )
    {
      UFG::TiDo::UnloadWwiseBank(&this->m_bankId);
      *((_BYTE *)v2 + 200) &= 0xFBu;
    }
    v3 = v2->m_contoller.m_pEvent;
    if ( v3 && (*((_BYTE *)v3 + 144) >> 6) & 1 )
      UFG::AudioEvent::StopAndForget(v3, 0x7D0u);
    v4 = v2->m_entity;
    if ( v4 )
    {
      UFG::AudioEntity::Shutdown(v4);
      v5 = v2->m_entity;
      if ( v5 )
        v5->vfptr->__vecDelDtor(v5, 1u);
      v2->m_entity = 0i64;
    }
  }
}

// File Line: 158
// RVA: 0x5A3930
void __fastcall UFG::AudioEmitterMarker::OnAttach(UFG::AudioEmitterMarker *this, UFG::SimObject *object)
{
  UFG::TransformNodeComponent *v2; // rbx
  UFG::AudioEmitterMarker *v3; // rdi
  float v4; // xmm0_4
  float v5; // xmm1_4

  v2 = this->mpXformNode;
  v3 = this;
  if ( v2 )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(this->mpXformNode);
    v4 = v2->mWorldTransform.v3.y;
    v5 = v2->mWorldTransform.v3.z;
    v3->m_CachedPosition.x = v2->mWorldTransform.v3.x;
    v3->m_CachedPosition.y = v4;
    v3->m_CachedPosition.z = v5;
  }
}

// File Line: 268
// RVA: 0x5A81E0
UFG::AudioEmitterMarker *__fastcall UFG::AudioEmitterMarker::PropertiesOnActivate(UFG::SceneObjectProperties *sceneObj)
{
  UFG::SceneObjectProperties *v1; // rbp
  UFG::allocator::free_link *v2; // rsi
  UFG::SimObject *v3; // rbx
  UFG::qSymbol *v4; // rax
  __int64 v5; // rax
  __int64 v6; // r14
  UFG::qPropertySet *v7; // rcx
  UFG::qWiseSymbol *v8; // r15
  UFG::qPropertySet *v9; // rcx
  UFG::qWiseSymbol *v10; // r13
  UFG::qPropertySet *v11; // rcx
  UFG::qWiseSymbol *v12; // rbx
  UFG::qPropertySet *v13; // rcx
  float *v14; // rdi
  UFG::qPropertySet *v15; // rcx
  float *v16; // r12
  UFG::qPropertySet *v17; // rcx
  bool *v18; // rsi
  UFG::qSymbolUC *v19; // rax
  char *v20; // rax
  UFG::qBaseTreeRB *v21; // rsi
  UFG::qWiseSymbol *v22; // rdi
  UFG::qSymbolUC *v23; // rax
  char *v24; // rbx
  const char *v25; // rax
  float v26; // xmm6_4
  __int128 v27; // xmm7
  UFG::qSymbolUC *v28; // rax
  char *v29; // rax
  bool *v31; // [rsp+38h] [rbp-70h]
  UFG::qSymbol result; // [rsp+B8h] [rbp+10h]
  UFG::allocator::free_link *v33; // [rsp+C0h] [rbp+18h]
  float *v34; // [rsp+C8h] [rbp+20h]

  v1 = sceneObj;
  v2 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0xD0ui64, "AudioEmitterMarker", 0i64, 1u);
  v33 = v2;
  if ( v2 )
  {
    v3 = v1->m_pSimObject;
    v4 = UFG::SceneObjectProperties::operator UFG::qSymbol const(v1, &result);
    UFG::AudioEmitterMarker::AudioEmitterMarker((UFG::AudioEmitterMarker *)v2, v4, v3);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  if ( v6 )
  {
    v7 = v1->mpWritableProperties;
    if ( !v7 )
      v7 = v1->mpConstProperties;
    v8 = UFG::qPropertySet::Get<UFG::qWiseSymbol>(v7, (UFG::qSymbol *)&TiDoSym_EventName.mUID, DEPTH_RECURSE);
    v9 = v1->mpWritableProperties;
    if ( !v9 )
      v9 = v1->mpConstProperties;
    v10 = UFG::qPropertySet::Get<UFG::qWiseSymbol>(v9, (UFG::qSymbol *)&TiDoSym_RtpcName.mUID, DEPTH_RECURSE);
    v11 = v1->mpWritableProperties;
    if ( !v11 )
      v11 = v1->mpConstProperties;
    v12 = UFG::qPropertySet::Get<UFG::qWiseSymbol>(v11, (UFG::qSymbol *)&TiDoSym_SoundBank.mUID, DEPTH_RECURSE);
    v13 = v1->mpWritableProperties;
    if ( !v13 )
      v13 = v1->mpConstProperties;
    v14 = UFG::qPropertySet::Get<float>(v13, (UFG::qSymbol *)&TiDoSym_AttenuationDiameter.mUID, DEPTH_RECURSE);
    v34 = v14;
    v15 = v1->mpWritableProperties;
    if ( !v15 )
      v15 = v1->mpConstProperties;
    v16 = UFG::qPropertySet::Get<float>(v15, (UFG::qSymbol *)&TiDoSym_RtpcVal.mUID, DEPTH_RECURSE);
    v17 = v1->mpWritableProperties;
    if ( !v17 )
      v17 = v1->mpConstProperties;
    v18 = UFG::qPropertySet::Get<bool>(v17, (UFG::qSymbol *)&TiDoSym_IsTodEnabled.mUID, DEPTH_RECURSE);
    v31 = v18;
    if ( v8 )
    {
      UFG::qWiseSymbol::operator=((UFG::qWiseSymbol *)(v6 + 160), v8);
    }
    else
    {
      v19 = (UFG::qSymbolUC *)UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&v33, v1->m_NameUID);
      v20 = UFG::qSymbol::as_cstr_dbg(v19);
      UFG::qPrintf("Audio Emitter has no event: '%s'\n", v20);
    }
    if ( v12 )
      UFG::qWiseSymbol::operator=((UFG::qWiseSymbol *)(v6 + 164), v12);
    if ( v8 && !v12 )
    {
      v21 = UFG::AudioEventPropertyManager::Find(v8->mUID);
      v22 = (UFG::qWiseSymbol *)v21->mNULL.mChild[0];
      v23 = (UFG::qSymbolUC *)UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&v33, v1->m_NameUID);
      v24 = UFG::qSymbol::as_cstr_dbg(v23);
      v25 = UFG::qWiseSymbol::as_cstr_dbg(v22 + 22);
      UFG::qPrintf("Audio Emitter has no soundbank reference: '%s' - setting to %s using event properties \n", v24, v25);
      UFG::qWiseSymbol::operator=((UFG::qWiseSymbol *)(v6 + 164), (UFG::qWiseSymbol *)&v21->mNULL.mChild[0][2].mUID);
      v14 = v34;
      v18 = v31;
    }
    if ( v10 )
      UFG::qWiseSymbol::operator=((UFG::qWiseSymbol *)(v6 + 168), v10);
    if ( v16 )
      *(float *)(v6 + 172) = *v16;
    v26 = *v14;
    if ( *v14 <= 0.0 )
    {
      v27 = HIDWORD(UFG::AudioEventPropertyManager::Find(v8->mUID)->mNULL.mChild[0][3].mChild[0]);
      if ( *(float *)&v27 < v26 )
      {
        v28 = (UFG::qSymbolUC *)UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&v33, v1->m_NameUID);
        v29 = UFG::qSymbol::as_cstr_dbg(v28);
        UFG::qPrintf(
          "Audio Emitter overriding layer attenuation for %s, layer:%f, wwise:%f\n",
          v29,
          v26,
          *(float *)&v27);
      }
    }
    *(float *)(v6 + 176) = *v14 * *v14;
    *(_BYTE *)(v6 + 200) ^= (*v18 ^ *(_BYTE *)(v6 + 200)) & 1;
  }
  return (UFG::AudioEmitterMarker *)v6;
}

// File Line: 354
// RVA: 0x5A4B90
char __fastcall UFG::AudioEmitterMarker::Play(UFG::AudioEmitterMarker *this)
{
  UFG::AudioEmitterMarker *v1; // rdi
  char result; // al
  char v3; // bl
  UFG::qWiseSymbol *v4; // rax
  unsigned int v5; // edx
  unsigned int v6; // ecx

  v1 = this;
  if ( this->m_numPlayAttempts )
  {
    if ( (*((_BYTE *)this + 200) & 4
       || (UFG::TiDo::LoadWwiseBank(&this->m_bankId),
           *((_BYTE *)v1 + 200) |= 4u,
           UFG::SoundBankManager::BankLoaded(&v1->m_bankId)))
      && (UFG::SoundBankManager::BankLoadRequestFinished(&v1->m_bankId)
       || v1->m_bankId.mUID == UFG::qWiseSymbol::get_null()->mUID) )
    {
      ((void (__fastcall *)(UFG::AudioEmitterMarker *))v1->vfptr[17].__vecDelDtor)(v1);
      v3 = UFG::AudioEntity::CreateAndPlayEvent(v1->m_entity, v1->m_eventId.mUID, &v1->m_contoller, 0i64, 0x7D0u, 0i64);
      v4 = UFG::qWiseSymbol::get_null();
      v5 = v1->m_rtpcName.mUID;
      if ( v5 != v4->mUID )
        UFG::AudioEntity::SetRtpcValue(v1->m_entity, v5, v1->m_rtpcVal);
      v6 = UFG::Metrics::msFrameCount;
      --v1->m_numPlayAttempts;
      result = v3;
      v1->m_lastFramePlayCall = v6;
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    if ( UFG::Metrics::msFrameCount > UFG::AudioEmitterMarker::msPlayAttemptTimeout + this->m_lastFramePlayCall )
      this->m_numPlayAttempts = UFG::AudioEmitterMarker::msNumPlayAttempts;
    result = 0;
  }
  return result;
}

// File Line: 403
// RVA: 0x5A6A60
void __fastcall UFG::AudioEmitterMarker::PlayOneShot(UFG::AudioEmitterMarker *this, unsigned int eventId)
{
  UFG::AudioEntity *v2; // rax
  unsigned int v3; // edi
  UFG::AudioEmitterMarker *v4; // rbx

  v2 = this->m_entity;
  v3 = eventId;
  v4 = this;
  if ( !v2 || !v2->m_bIsInitialized )
    ((void (*)(void))this->vfptr[17].__vecDelDtor)();
  UFG::AudioEntity::CreateAndPlayEvent(v4->m_entity, v3, 0i64, 0, 0i64);
}

// File Line: 419
// RVA: 0x5AC770
void __fastcall UFG::AudioEmitterMarker::Stop(UFG::AudioEmitterMarker *this, unsigned int fadeOut)
{
  unsigned int v2; // edi
  UFG::AudioEmitterMarker *v3; // rbx
  UFG::AudioEvent *v4; // rcx
  UFG::AudioEntity *v5; // rcx
  UFG::AudioEntity *v6; // rcx

  v2 = fadeOut;
  v3 = this;
  if ( *((_BYTE *)this + 200) & 4 )
  {
    UFG::TiDo::UnloadWwiseBank(&this->m_bankId);
    *((_BYTE *)v3 + 200) &= 0xFBu;
  }
  v4 = v3->m_contoller.m_pEvent;
  if ( v4 && (*((_BYTE *)v4 + 144) >> 6) & 1 )
    UFG::AudioEvent::StopAndForget(v4, v2);
  v5 = v3->m_entity;
  if ( v5 )
  {
    UFG::AudioEntity::Shutdown(v5);
    v6 = v3->m_entity;
    if ( v6 )
      v6->vfptr->__vecDelDtor(v6, 1u);
    v3->m_entity = 0i64;
  }
}

// File Line: 500
// RVA: 0x59B580
char __fastcall UFG::AudioEmitterMarker::EmitterExists(UFG::AudioEmitterMarker *marker)
{
  int v1; // edi
  Render::SkinningCacheNode *v2; // rax
  signed __int64 v3; // rbx
  UFG::qBaseNodeRB *v4; // rdx
  UFG::qBaseTreeRB *v5; // rax

  v1 = (signed int)marker;
  v2 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::AudioEmitterMarker::msAudioEmitterMarkers);
  if ( !v2 )
    return 0;
  v3 = (signed __int64)&v2[-3].mNode.8;
  if ( v2 == (Render::SkinningCacheNode *)112 )
    return 0;
  while ( 1 )
  {
    v4 = (UFG::qBaseNodeRB *)(v3 ? v3 + 112 : 0i64);
    v5 = UFG::qBaseTreeRB::GetNext(&UFG::AudioEmitterMarker::msAudioEmitterMarkers.mTree, v4);
    if ( v5 )
      v5 = (UFG::qBaseTreeRB *)((char *)v5 - 112);
    if ( (_DWORD)v3 == v1 )
      break;
    v3 = (signed __int64)v5;
    if ( !v5 )
      return 0;
  }
  return 1;
}

