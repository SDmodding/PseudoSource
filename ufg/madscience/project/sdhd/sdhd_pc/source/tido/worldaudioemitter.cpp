// File Line: 79
// RVA: 0x1554940
__int64 dynamic_initializer_for__UFG::AudioEmitterMarker::msAudioEmitterMarkers__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::AudioEmitterMarker::msAudioEmitterMarkers.mTree);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::AudioEmitterMarker::msAudioEmitterMarkers__);
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
void __fastcall UFG::AudioEmitterMarker::AudioEmitterMarker(
        UFG::AudioEmitterMarker *this,
        UFG::qSymbol *name,
        UFG::SimObject *pSimObj)
{
  UFG::MarkerBase::MarkerBase(this, name, pSimObj, 0);
  this->UFG::qNodeRB<UFG::AudioEmitterMarker>::mNode.mParent = 0i64;
  this->UFG::qNodeRB<UFG::AudioEmitterMarker>::mNode.mChild[0] = 0i64;
  this->UFG::qNodeRB<UFG::AudioEmitterMarker>::mNode.mChild[1] = 0i64;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AudioEmitterMarker::`vftable;
  this->m_contoller.m_pEvent = 0i64;
  this->m_entity = 0i64;
  this->m_eventId.mUID = -1;
  _((AMD_HD3D *)0xFFFFFFFFi64);
  this->m_bankId.mUID = -1;
  _((AMD_HD3D *)0xFFFFFFFFi64);
  this->m_rtpcName.mUID = -1;
  _((AMD_HD3D *)0xFFFFFFFFi64);
  *(_QWORD *)&this->m_falloffDiameter2 = 1159479296i64;
  this->m_numPlayAttempts = UFG::AudioEmitterMarker::msNumPlayAttempts;
  *((_BYTE *)this + 200) &= 0xF8u;
  UFG::SimComponent::AddType(this, UFG::AudioEmitterMarker::_AudioEmitterMarkerTypeUID, "AudioEmitterMarker");
  this->UFG::qNodeRB<UFG::AudioEmitterMarker>::mNode.mUID = name->mUID;
  UFG::qBaseTreeRB::Add(
    &UFG::AudioEmitterMarker::msAudioEmitterMarkers.mTree,
    &this->UFG::qNodeRB<UFG::AudioEmitterMarker>::mNode);
  UFG::qWiseSymbol::set_null(&this->m_eventId);
  UFG::qWiseSymbol::set_null(&this->m_bankId);
  UFG::qWiseSymbol::set_null(&this->m_rtpcName);
  this->m_rtpcVal = 0.0;
}

// File Line: 123
// RVA: 0x593DB0
void __fastcall UFG::AudioEmitterMarker::~AudioEmitterMarker(UFG::AudioEmitterMarker *this)
{
  UFG::AudioEvent *m_pEvent; // rcx

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AudioEmitterMarker::`vftable;
  UFG::AudioEmitterMarker::Stop(this, 0x7D0u);
  UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
    (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::AudioEmitterMarker::msAudioEmitterMarkers,
    (UFG::qBaseNodeVariableRB<unsigned __int64> *)&this->UFG::qNodeRB<UFG::AudioEmitterMarker>);
  _((AMD_HD3D *)this->m_rtpcName.mUID);
  _((AMD_HD3D *)this->m_bankId.mUID);
  _((AMD_HD3D *)this->m_eventId.mUID);
  m_pEvent = this->m_contoller.m_pEvent;
  if ( m_pEvent )
    UFG::AudioEvent::OnControllerDestroy(m_pEvent);
  UFG::MarkerBase::~MarkerBase(this);
}

// File Line: 136
// RVA: 0x59F590
void __fastcall UFG::AudioEmitterMarker::Init(UFG::AudioEmitterMarker *this)
{
  UFG::allocator::free_link *v2; // rax
  UFG::TransformNodeComponent *mpXformNode; // rbx

  if ( !this->m_entity )
  {
    v2 = UFG::qMalloc(0x140ui64, "AudioEmitter.Entity", 0i64);
    if ( v2 )
      UFG::AudioEntity::AudioEntity((UFG::AudioEntity *)v2);
    this->m_entity = (UFG::AudioEntity *)v2;
    mpXformNode = this->mpXformNode;
    UFG::TransformNodeComponent::UpdateWorldTransform(mpXformNode);
    (*(void (__fastcall **)(UFG::AudioEntity *, UFG::qSymbol *, UFG::qMatrix44 *))this->m_entity->vfptr->gap8)(
      this->m_entity,
      &this->m_pSimObject->m_Name,
      &mpXformNode->mWorldTransform);
  }
}

// File Line: 150
// RVA: 0x5AA4B0
void __fastcall UFG::AudioEmitterMarker::Reset(UFG::AudioEmitterMarker *this)
{
  UFG::AudioEvent *m_pEvent; // rax
  UFG::AudioEvent *v3; // rcx
  UFG::AudioEntity *m_entity; // rcx
  UFG::AudioEntity *v5; // rcx

  m_pEvent = this->m_contoller.m_pEvent;
  if ( m_pEvent && (*((_BYTE *)m_pEvent + 144) & 0x40) != 0 )
  {
    if ( (*((_BYTE *)this + 200) & 4) != 0 )
    {
      UFG::TiDo::UnloadWwiseBank(&this->m_bankId);
      *((_BYTE *)this + 200) &= ~4u;
    }
    v3 = this->m_contoller.m_pEvent;
    if ( v3 && (*((_BYTE *)v3 + 144) & 0x40) != 0 )
      UFG::AudioEvent::StopAndForget(v3, 2000);
    m_entity = this->m_entity;
    if ( m_entity )
    {
      UFG::AudioEntity::Shutdown(m_entity);
      v5 = this->m_entity;
      if ( v5 )
        v5->vfptr->__vecDelDtor(v5, 1u);
      this->m_entity = 0i64;
    }
  }
}

// File Line: 158
// RVA: 0x5A3930
void __fastcall UFG::AudioEmitterMarker::OnAttach(UFG::AudioEmitterMarker *this, UFG::SimObject *object)
{
  UFG::TransformNodeComponent *mpXformNode; // rbx
  float y; // xmm0_4
  float z; // xmm1_4

  mpXformNode = this->mpXformNode;
  if ( mpXformNode )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(this->mpXformNode);
    y = mpXformNode->mWorldTransform.v3.y;
    z = mpXformNode->mWorldTransform.v3.z;
    this->m_CachedPosition.x = mpXformNode->mWorldTransform.v3.x;
    this->m_CachedPosition.y = y;
    this->m_CachedPosition.z = z;
  }
}

// File Line: 268
// RVA: 0x5A81E0
UFG::AudioEmitterMarker *__fastcall UFG::AudioEmitterMarker::PropertiesOnActivate(UFG::SceneObjectProperties *sceneObj)
{
  UFG::allocator::free_link *v2; // rsi
  UFG::SimObject *m_pSimObject; // rbx
  UFG::qSymbol *v4; // rax
  __int64 v5; // rax
  __int64 v6; // r14
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qWiseSymbol *v8; // r15
  UFG::qPropertySet *mpConstProperties; // rcx
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
  char *v25; // rax
  float v26; // xmm6_4
  float v27; // xmm7_4
  UFG::qSymbolUC *v28; // rax
  char *v29; // rax
  bool *v31; // [rsp+38h] [rbp-70h]
  UFG::qSymbol result; // [rsp+B8h] [rbp+10h] BYREF
  UFG::allocator::free_link *v33; // [rsp+C0h] [rbp+18h] BYREF
  float *v34; // [rsp+C8h] [rbp+20h]

  v2 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0xD0ui64, "AudioEmitterMarker", 0i64, 1u);
  v33 = v2;
  if ( v2 )
  {
    m_pSimObject = sceneObj->m_pSimObject;
    v4 = (UFG::qSymbol *)UFG::SceneObjectProperties::operator UFG::qSymbol const(sceneObj, (UFG::qWiseSymbol *)&result);
    UFG::AudioEmitterMarker::AudioEmitterMarker((UFG::AudioEmitterMarker *)v2, v4, m_pSimObject);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  if ( v6 )
  {
    mpWritableProperties = sceneObj->mpWritableProperties;
    if ( !mpWritableProperties )
      mpWritableProperties = sceneObj->mpConstProperties;
    v8 = UFG::qPropertySet::Get<UFG::qWiseSymbol>(
           mpWritableProperties,
           (UFG::qArray<unsigned long,0> *)&TiDoSym_EventName,
           DEPTH_RECURSE);
    mpConstProperties = sceneObj->mpWritableProperties;
    if ( !mpConstProperties )
      mpConstProperties = sceneObj->mpConstProperties;
    v10 = UFG::qPropertySet::Get<UFG::qWiseSymbol>(
            mpConstProperties,
            (UFG::qArray<unsigned long,0> *)&TiDoSym_RtpcName,
            DEPTH_RECURSE);
    v11 = sceneObj->mpWritableProperties;
    if ( !v11 )
      v11 = sceneObj->mpConstProperties;
    v12 = UFG::qPropertySet::Get<UFG::qWiseSymbol>(
            v11,
            (UFG::qArray<unsigned long,0> *)&TiDoSym_SoundBank,
            DEPTH_RECURSE);
    v13 = sceneObj->mpWritableProperties;
    if ( !v13 )
      v13 = sceneObj->mpConstProperties;
    v14 = UFG::qPropertySet::Get<float>(
            v13,
            (UFG::qArray<unsigned long,0> *)&TiDoSym_AttenuationDiameter,
            DEPTH_RECURSE);
    v34 = v14;
    v15 = sceneObj->mpWritableProperties;
    if ( !v15 )
      v15 = sceneObj->mpConstProperties;
    v16 = UFG::qPropertySet::Get<float>(v15, (UFG::qArray<unsigned long,0> *)&TiDoSym_RtpcVal, DEPTH_RECURSE);
    v17 = sceneObj->mpWritableProperties;
    if ( !v17 )
      v17 = sceneObj->mpConstProperties;
    v18 = UFG::qPropertySet::Get<bool>(v17, (UFG::qArray<unsigned long,0> *)&TiDoSym_IsTodEnabled, DEPTH_RECURSE);
    v31 = v18;
    if ( v8 )
    {
      UFG::qWiseSymbol::operator=((UFG::qWiseSymbol *)(v6 + 160), v8);
    }
    else
    {
      v19 = (UFG::qSymbolUC *)UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&v33, sceneObj->m_NameUID);
      v20 = UFG::qSymbol::as_cstr_dbg(v19);
      UFG::qPrintf("Audio Emitter has no event: %s\n", v20);
    }
    if ( v12 )
      UFG::qWiseSymbol::operator=((UFG::qWiseSymbol *)(v6 + 164), v12);
    if ( v8 && !v12 )
    {
      v21 = UFG::AudioEventPropertyManager::Find(v8->mUID);
      v22 = (UFG::qWiseSymbol *)v21->mNULL.mChild[0];
      v23 = (UFG::qSymbolUC *)UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&v33, sceneObj->m_NameUID);
      v24 = UFG::qSymbol::as_cstr_dbg(v23);
      v25 = UFG::qWiseSymbol::as_cstr_dbg(v22 + 22);
      UFG::qPrintf("Audio Emitter has no soundbank reference: %s - setting to %s using event properties \n", v24, v25);
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
      v27 = *((float *)UFG::AudioEventPropertyManager::Find(v8->mUID)->mNULL.mChild[0][3].mChild + 1);
      if ( v27 < v26 )
      {
        v28 = (UFG::qSymbolUC *)UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&v33, sceneObj->m_NameUID);
        v29 = UFG::qSymbol::as_cstr_dbg(v28);
        UFG::qPrintf("Audio Emitter overriding layer attenuation for %s, layer:%f, wwise:%f\n", v29, v26, v27);
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
  char result; // al
  char v3; // bl
  UFG::qWiseSymbol *null; // rax
  unsigned int mUID; // edx
  unsigned int v6; // ecx

  if ( this->m_numPlayAttempts )
  {
    if ( ((*((_BYTE *)this + 200) & 4) != 0
       || (UFG::TiDo::LoadWwiseBank(&this->m_bankId),
           *((_BYTE *)this + 200) |= 4u,
           UFG::SoundBankManager::BankLoaded(&this->m_bankId)))
      && (UFG::SoundBankManager::BankLoadRequestFinished(&this->m_bankId)
       || this->m_bankId.mUID == UFG::qWiseSymbol::get_null()->mUID) )
    {
      ((void (__fastcall *)(UFG::AudioEmitterMarker *))this->vfptr[17].__vecDelDtor)(this);
      v3 = UFG::AudioEntity::CreateAndPlayEvent(
             this->m_entity,
             this->m_eventId.mUID,
             &this->m_contoller,
             0i64,
             0x7D0u,
             0i64);
      null = UFG::qWiseSymbol::get_null();
      mUID = this->m_rtpcName.mUID;
      if ( mUID != null->mUID )
        UFG::AudioEntity::SetRtpcValue(this->m_entity, mUID, this->m_rtpcVal);
      v6 = UFG::Metrics::msFrameCount;
      --this->m_numPlayAttempts;
      result = v3;
      this->m_lastFramePlayCall = v6;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    if ( UFG::Metrics::msFrameCount > UFG::AudioEmitterMarker::msPlayAttemptTimeout + this->m_lastFramePlayCall )
      this->m_numPlayAttempts = UFG::AudioEmitterMarker::msNumPlayAttempts;
    return 0;
  }
  return result;
}

// File Line: 403
// RVA: 0x5A6A60
void __fastcall UFG::AudioEmitterMarker::PlayOneShot(UFG::AudioEmitterMarker *this, unsigned int eventId)
{
  UFG::AudioEntity *m_entity; // rax

  m_entity = this->m_entity;
  if ( !m_entity || !m_entity->m_bIsInitialized )
    ((void (__fastcall *)(UFG::AudioEmitterMarker *))this->vfptr[17].__vecDelDtor)(this);
  UFG::AudioEntity::CreateAndPlayEvent(this->m_entity, eventId, 0i64, 0, 0i64);
}

// File Line: 419
// RVA: 0x5AC770
void __fastcall UFG::AudioEmitterMarker::Stop(UFG::AudioEmitterMarker *this, int fadeOut)
{
  UFG::AudioEvent *m_pEvent; // rcx
  UFG::AudioEntity *m_entity; // rcx
  UFG::AudioEntity *v6; // rcx

  if ( (*((_BYTE *)this + 200) & 4) != 0 )
  {
    UFG::TiDo::UnloadWwiseBank(&this->m_bankId);
    *((_BYTE *)this + 200) &= ~4u;
  }
  m_pEvent = this->m_contoller.m_pEvent;
  if ( m_pEvent && (*((_BYTE *)m_pEvent + 144) & 0x40) != 0 )
    UFG::AudioEvent::StopAndForget(m_pEvent, fadeOut);
  m_entity = this->m_entity;
  if ( m_entity )
  {
    UFG::AudioEntity::Shutdown(m_entity);
    v6 = this->m_entity;
    if ( v6 )
      v6->vfptr->__vecDelDtor(v6, 1u);
    this->m_entity = 0i64;
  }
}

// File Line: 500
// RVA: 0x59B580
char __fastcall UFG::AudioEmitterMarker::EmitterExists(UFG::AudioEmitterMarker *marker)
{
  int v1; // edi
  Render::SkinningCacheNode *Head; // rax
  UFG::qBaseTreeRB *v3; // rbx
  UFG::qBaseNodeRB *v4; // rdx
  UFG::qBaseTreeRB *Next; // rax

  v1 = (int)marker;
  Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::AudioEmitterMarker::msAudioEmitterMarkers);
  if ( !Head )
    return 0;
  v3 = (UFG::qBaseTreeRB *)&Head[-3].mNode.8;
  if ( Head == (Render::SkinningCacheNode *)112 )
    return 0;
  while ( 1 )
  {
    v4 = v3 ? (UFG::qBaseNodeRB *)v3[1].mNULL.mChild : 0i64;
    Next = UFG::qBaseTreeRB::GetNext(&UFG::AudioEmitterMarker::msAudioEmitterMarkers.mTree, v4);
    if ( Next )
      Next = (UFG::qBaseTreeRB *)((char *)Next - 112);
    if ( (_DWORD)v3 == v1 )
      break;
    v3 = Next;
    if ( !Next )
      return 0;
  }
  return 1;
}

