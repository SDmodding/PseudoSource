// File Line: 77
// RVA: 0x1554910
__int64 dynamic_initializer_for__UFG::AudioTriggerRegion::msActiveMixUid__()
{
  UFG::AudioTriggerRegion::msActiveMixUid.mUID = UFG::qWiseSymbol::get_null()->mUID;
  _((AMD_HD3D *)UFG::AudioTriggerRegion::msActiveMixUid.mUID);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::AudioTriggerRegion::msActiveMixUid__);
}

// File Line: 98
// RVA: 0x59CE00
UFG::ComponentIDDesc *__fastcall UFG::AudioTriggerRegion::GetDesc(UFG::AudioTriggerRegion *this)
{
  return &UFG::AudioTriggerRegion::_TypeIDesc;
}

// File Line: 99
// RVA: 0x1554970
__int64 dynamic_initializer_for__UFG::AudioTriggerRegion::msAudioTriggerRegions__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::AudioTriggerRegion::msAudioTriggerRegions.mTree);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::AudioTriggerRegion::msAudioTriggerRegions__);
}

// File Line: 106
// RVA: 0x1559B10
__int64 UFG::_dynamic_initializer_for__default_symbol__()
{
  default_symbol_0.mUID = UFG::qWiseSymbolUIDFromString("default", 0x811C9DC5);
  _((AMD_HD3D *)default_symbol_0.mUID);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__default_symbol__);
}

// File Line: 118
// RVA: 0x592DA0
void __fastcall UFG::AudioTriggerRegion::AudioTriggerRegion(
        UFG::AudioTriggerRegion *this,
        UFG::qSymbol *name,
        UFG::SimObject *pSimObj)
{
  unsigned int mUID; // eax

  UFG::TriggerRegion::TriggerRegion(this, name, pSimObj, 0);
  UFG::AudioEntity::AudioEntity(&this->UFG::AudioEntity);
  mUID = name->mUID;
  this->UFG::qNodeRB<UFG::AudioTriggerRegion>::mNode.mParent = 0i64;
  this->UFG::qNodeRB<UFG::AudioTriggerRegion>::mNode.mChild[0] = 0i64;
  this->UFG::qNodeRB<UFG::AudioTriggerRegion>::mNode.mChild[1] = 0i64;
  this->UFG::qNodeRB<UFG::AudioTriggerRegion>::mNode.mUID = mUID;
  this->UFG::TriggerRegion::UFG::MarkerBase::UFG::HintComponentBase::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AudioTriggerRegion::`vftable{for `UFG::TriggerRegion};
  this->UFG::AudioEntity::vfptr = (UFG::AudioEntityVtbl *)&UFG::AudioTriggerRegion::`vftable{for `UFG::AudioEntity};
  this->mTags.mNode.mPrev = &this->mTags.mNode;
  this->mTags.mNode.mNext = &this->mTags.mNode;
  UFG::RegionContainmentInfo::RegionContainmentInfo(&this->m_regionsContainingMe);
  UFG::RegionContainmentInfo::RegionContainmentInfo(&this->m_regionsIContain);
  UFG::RegionContainmentInfo::RegionContainmentInfo(&this->m_thingsIContain);
  UFG::SimComponent::AddType(this, UFG::AudioTriggerRegion::_AudioTriggerRegionTypeUID, "AudioTriggerRegion");
  UFG::AudioTriggerRegion::InitTrigger(this, pSimObj);
  this->m_name = (UFG::qSymbol)name->mUID;
  this->m_bEnableEnvironments = 0;
  UFG::AudioTriggerRegion::sm_hierarchyIsDirty = 1;
}

// File Line: 141
// RVA: 0x593EB0
void __fastcall UFG::AudioTriggerRegion::~AudioTriggerRegion(UFG::AudioTriggerRegion *this)
{
  UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *p_mTags; // rsi
  unsigned int *p_mNext; // rax
  unsigned int *i; // rbx
  _QWORD *v5; // rdx
  __int64 v6; // rcx
  _QWORD *v7; // rax
  UFG::qSymbol *p; // rcx
  UFG::qSymbol *v9; // rbx
  UFG::qSymbol *v10; // rcx
  UFG::qSymbol *v11; // rbx
  UFG::qSymbol *v12; // rcx
  UFG::qSymbol *v13; // rbx
  int v14; // edx
  hkGeometryUtils::IVertices *v15; // rcx
  int v16; // r8d
  UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> *mPrev; // rdx
  UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> *mNext; // rax

  this->UFG::TriggerRegion::UFG::MarkerBase::UFG::HintComponentBase::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AudioTriggerRegion::`vftable{for `UFG::TriggerRegion};
  this->UFG::AudioEntity::vfptr = (UFG::AudioEntityVtbl *)&UFG::AudioTriggerRegion::`vftable{for `UFG::AudioEntity};
  p_mTags = (UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)&this->mTags;
  p_mNext = (unsigned int *)&this->mTags.mNode.mNext[-1].mNext;
  for ( i = &this->UFG::qNodeRB<UFG::AudioTriggerRegion>::mNode.mUID;
        p_mNext != i;
        p_mNext = (unsigned int *)&p_mTags->mNode.mNext[-1].mNext )
  {
    v5 = p_mNext + 2;
    v6 = *((_QWORD *)p_mNext + 1);
    v7 = (_QWORD *)*((_QWORD *)p_mNext + 2);
    *(_QWORD *)(v6 + 8) = v7;
    *v7 = v6;
    *v5 = v5;
    v5[1] = v5;
    if ( v5 != (_QWORD *)8 )
      (*(void (__fastcall **)(_QWORD *, __int64))*(v5 - 1))(v5 - 1, 1i64);
  }
  p = this->m_regionsContainingMe.m_regionsContainedIn.p;
  if ( p )
  {
    v9 = p - 1;
    `eh vector destructor iterator(p, 4ui64, p[-1].mUID, (void (__fastcall *)(void *))_);
    operator delete[](v9);
  }
  this->m_regionsContainingMe.m_regionsContainedIn.p = 0i64;
  *(_QWORD *)&this->m_regionsContainingMe.m_regionsContainedIn.size = 0i64;
  v10 = this->m_regionsIContain.m_regionsContainedIn.p;
  if ( v10 )
  {
    v11 = v10 - 1;
    `eh vector destructor iterator(v10, 4ui64, v10[-1].mUID, (void (__fastcall *)(void *))_);
    operator delete[](v11);
  }
  this->m_regionsIContain.m_regionsContainedIn.p = 0i64;
  *(_QWORD *)&this->m_regionsIContain.m_regionsContainedIn.size = 0i64;
  v12 = this->m_thingsIContain.m_regionsContainedIn.p;
  if ( v12 )
  {
    v13 = v12 - 1;
    `eh vector destructor iterator(v12, 4ui64, v12[-1].mUID, (void (__fastcall *)(void *))_);
    operator delete[](v13);
  }
  this->m_thingsIContain.m_regionsContainedIn.p = 0i64;
  *(_QWORD *)&this->m_thingsIContain.m_regionsContainedIn.size = 0i64;
  UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
    (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::AudioTriggerRegion::msAudioTriggerRegions,
    (UFG::qBaseNodeVariableRB<unsigned __int64> *)&this->UFG::qNodeRB<UFG::AudioTriggerRegion>);
  UFG::AudioTriggerRegion::sm_hierarchyIsDirty = 1;
  if ( Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(v15, v14, v16) )
    UFG::AudioEntity::Shutdown(&this->UFG::AudioEntity);
  UFG::RegionContainmentInfo::~RegionContainmentInfo(&this->m_thingsIContain);
  UFG::RegionContainmentInfo::~RegionContainmentInfo(&this->m_regionsIContain);
  UFG::RegionContainmentInfo::~RegionContainmentInfo(&this->m_regionsContainingMe);
  UFG::qList<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption,1,0>::DeleteNodes(p_mTags);
  mPrev = p_mTags->mNode.mPrev;
  mNext = p_mTags->mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  p_mTags->mNode.mPrev = &p_mTags->mNode;
  p_mTags->mNode.mNext = &p_mTags->mNode;
  UFG::AudioEntity::~AudioEntity(&this->UFG::AudioEntity);
  UFG::TriggerRegion::~TriggerRegion(this);
}

// File Line: 164
// RVA: 0x5A3A60
void __fastcall UFG::AudioTriggerRegion::OnDetach(UFG::AudioTriggerRegion *this)
{
  UFG::AudioListener *v2; // r8
  int v3; // edx
  unsigned int size; // ecx
  hkGeometryUtils::IVertices *v5; // rcx
  unsigned int v6; // edx
  UFG::qSymbol *p; // r9
  unsigned int v8; // eax
  char *v9; // rax
  UFG::AudioTriggerRegionTag *i; // rdi
  unsigned int v11; // eax
  __int64 v12; // rsi
  __int64 v13; // rbp
  UFG::AudioEntity *Entity; // rax
  UFG::AudioEntity *v15; // rdi
  UFG::RegionContainmentInfo *ContainmentInfo; // r10
  __int64 v17; // rdx
  unsigned int v18; // eax
  UFG::qSymbol *v19; // r8
  unsigned int v20; // eax
  UFG::AudioTriggerRegionEvent thisEvent; // [rsp+28h] [rbp-40h] BYREF

  v2 = UFG::AudioListener::sm_pInstance;
  if ( UFG::AudioListener::sm_pInstance )
  {
    v3 = 0;
    size = UFG::AudioListener::sm_pInstance->m_containmentInfo.m_regionsContainedIn.size;
    if ( size )
    {
      while ( this->i_name.mUID != UFG::AudioListener::sm_pInstance->m_containmentInfo.m_regionsContainedIn.p[v3].mUID )
      {
        if ( ++v3 >= size )
          goto LABEL_5;
      }
    }
    else
    {
LABEL_5:
      v3 = -1;
    }
    if ( v3 != -1 )
    {
      v5 = 0i64;
      v6 = UFG::AudioListener::sm_pInstance->m_containmentInfo.m_regionsContainedIn.size;
      if ( v6 )
      {
        p = UFG::AudioListener::sm_pInstance->m_containmentInfo.m_regionsContainedIn.p;
        while ( this->i_name.mUID != p[(_QWORD)v5].mUID )
        {
          v5 = (hkGeometryUtils::IVertices *)(unsigned int)((_DWORD)v5 + 1);
          if ( (unsigned int)v5 >= v6 )
            goto LABEL_16;
        }
        if ( (_DWORD)v5 != -1 )
        {
          p[(_QWORD)v5] = p[v6 - 1];
          v8 = v2->m_containmentInfo.m_regionsContainedIn.size;
          if ( v8 > 1 )
            v2->m_containmentInfo.m_regionsContainedIn.size = v8 - 1;
          else
            v2->m_containmentInfo.m_regionsContainedIn.size = 0;
        }
      }
LABEL_16:
      if ( UFG::TiDo::sm_ambiencesInfo )
      {
        v9 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->UFG::qNamed);
        UFG::qPrintf("AudioTriggerRegion:: Lst Exit :: %s\n", v9);
      }
      for ( i = (UFG::AudioTriggerRegionTag *)&this->mTags.mNode.mNext[-1].mNext;
            i != (UFG::AudioTriggerRegionTag *)&this->UFG::qNodeRB<UFG::AudioTriggerRegion>::mNode.mUID;
            i = (UFG::AudioTriggerRegionTag *)&i->mNext[-1].mNext )
      {
        UFG::AudioTriggerRegionEvent::AudioTriggerRegionEvent(&thisEvent, 0i64, this, i);
        UFG::AudioTriggerRegion::RemoveAudioZoneListener(this, &thisEvent);
        thisEvent.vfptr = (UFG::AudioTriggerRegionEventVtbl *)&UFG::AudioTriggerRegionEvent::`vftable;
        _((AMD_HD3D *)thisEvent.mAudioModeUid.mUID);
        _((AMD_HD3D *)thisEvent.mAudioUidOnExit.mUID);
        _((AMD_HD3D *)thisEvent.mAudioUidOnEnter.mUID);
      }
      if ( Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(v5, v6, (int)v2) )
        UFG::AudioEntity::Shutdown(&this->UFG::AudioEntity);
    }
  }
  v11 = this->m_thingsIContain.m_regionsContainedIn.size;
  if ( v11 )
  {
    v12 = 0i64;
    v13 = v11;
    do
    {
      Entity = (UFG::AudioEntity *)UFG::TiDo::GetEntity(&this->m_thingsIContain.m_regionsContainedIn.p[v12]);
      v15 = Entity;
      if ( Entity )
      {
        UFG::AudioTriggerRegion::OnExited(this, Entity, 0);
        ContainmentInfo = UFG::AudioEntity::GetContainmentInfo(v15);
        v17 = 0i64;
        v18 = ContainmentInfo->m_regionsContainedIn.size;
        if ( v18 )
        {
          v19 = ContainmentInfo->m_regionsContainedIn.p;
          while ( this->i_name.mUID != v19[v17].mUID )
          {
            v17 = (unsigned int)(v17 + 1);
            if ( (unsigned int)v17 >= v18 )
              goto LABEL_34;
          }
          if ( (_DWORD)v17 != -1 )
          {
            v19[v17] = v19[v18 - 1];
            v20 = ContainmentInfo->m_regionsContainedIn.size;
            if ( v20 > 1 )
              ContainmentInfo->m_regionsContainedIn.size = v20 - 1;
            else
              ContainmentInfo->m_regionsContainedIn.size = 0;
          }
        }
      }
LABEL_34:
      ++v12;
      --v13;
    }
    while ( v13 );
  }
}

// File Line: 197
// RVA: 0x59FFE0
void __fastcall UFG::AudioTriggerRegion::InitTrigger(UFG::AudioTriggerRegion *this, UFG::SimComponent *pSimObj)
{
  UFG::SimComponent *ComponentOfType; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *p_mpRegion; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *p_mNode; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rax

  ComponentOfType = pSimObj;
  if ( pSimObj )
    ComponentOfType = UFG::SimObject::GetComponentOfType((UFG::SimObject *)pSimObj, UFG::RegionComponent::_TypeUID);
  p_mpRegion = &this->mpRegion;
  if ( this->mpRegion.m_pPointer )
  {
    mPrev = p_mpRegion->mPrev;
    mNext = this->mpRegion.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mpRegion->mPrev = p_mpRegion;
    this->mpRegion.mNext = &this->mpRegion;
  }
  this->mpRegion.m_pPointer = ComponentOfType;
  if ( ComponentOfType )
  {
    p_mNode = &ComponentOfType->m_SafePointerList.mNode;
    v8 = ComponentOfType->m_SafePointerList.mNode.mPrev;
    v8->mNext = p_mpRegion;
    p_mpRegion->mPrev = v8;
    this->mpRegion.mNext = p_mNode;
    p_mNode->mPrev = p_mpRegion;
  }
  *(_QWORD *)&this->m_occValue = 0i64;
  this->m_obsValue = 0.0;
  UFG::qBaseTreeRB::Add(
    &UFG::AudioTriggerRegion::msAudioTriggerRegions.mTree,
    &this->UFG::qNodeRB<UFG::AudioTriggerRegion>::mNode);
}

// File Line: 226
// RVA: 0x59F520
bool __fastcall UFG::AudioTriggerRegion::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qPropertySet *mpWritableProperties; // rcx

  mpWritableProperties = pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = pSceneObj->mpConstProperties;
  return UFG::qPropertySet::GetParentFromName(
           mpWritableProperties,
           (UFG::qArray<unsigned long,0> *)&TiDoSymX_propset_componentATRegion,
           DEPTH_RECURSE) != 0i64;
}

// File Line: 236
// RVA: 0x5A8520
UFG::AudioTriggerRegion *__fastcall UFG::AudioTriggerRegion::PropertiesOnActivate(
        UFG::SceneObjectProperties *pSceneObj)
{
  UFG::allocator::free_link *v2; // rbp
  UFG::SimObject *m_pSimObject; // rbx
  UFG::qSymbol *v4; // rax
  __int64 v5; // rax
  __int64 v6; // rbx
  UFG::qPropertySet *mpWritableProperties; // rcx
  bool *v8; // rax
  UFG::qPropertySet *mpConstProperties; // rcx
  UFG::qPropertyList *v10; // r14
  unsigned int mNumElements; // ebp
  unsigned int v12; // edi
  UFG::qWiseSymbol **v13; // rsi
  char *ValuePtr; // rax
  UFG::qPropertySet *v15; // rcx
  UFG::qWiseSymbol *v16; // rax
  UFG::qWiseSymbol *v17; // rcx
  UFG::qWiseSymbol *v18; // rax
  UFG::qSymbol result; // [rsp+68h] [rbp+10h] BYREF
  UFG::allocator::free_link *v21; // [rsp+70h] [rbp+18h]

  v2 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0x2F0ui64, "AudioTriggerRegion", 0i64, 1u);
  v21 = v2;
  if ( v2 )
  {
    m_pSimObject = pSceneObj->m_pSimObject;
    v4 = (UFG::qSymbol *)UFG::SceneObjectProperties::operator UFG::qSymbol const(pSceneObj, (UFG::qWiseSymbol *)&result);
    UFG::AudioTriggerRegion::AudioTriggerRegion((UFG::AudioTriggerRegion *)v2, v4, m_pSimObject);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  if ( v6 )
  {
    mpWritableProperties = pSceneObj->mpWritableProperties;
    if ( !mpWritableProperties )
      mpWritableProperties = pSceneObj->mpConstProperties;
    v8 = UFG::qPropertySet::Get<bool>(
           mpWritableProperties,
           (UFG::qArray<unsigned long,0> *)&TiDoSym_ControlEmitters,
           DEPTH_RECURSE);
    if ( v8 && *v8 )
      *(_DWORD *)(v6 + 736) |= 8u;
    mpConstProperties = pSceneObj->mpWritableProperties;
    if ( !mpConstProperties )
      mpConstProperties = pSceneObj->mpConstProperties;
    v10 = UFG::qPropertySet::Get<UFG::qPropertyList>(
            mpConstProperties,
            (UFG::qArray<unsigned long,0> *)&TiDoSym_TagList,
            DEPTH_RECURSE);
    mNumElements = v10->mNumElements;
    v12 = 0;
    if ( mNumElements )
    {
      v13 = (UFG::qWiseSymbol **)(v6 + 640);
      do
      {
        ValuePtr = UFG::qPropertyList::GetValuePtr(v10, 0x1Au, v12);
        if ( ValuePtr && *(_QWORD *)ValuePtr )
          v15 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr];
        else
          v15 = 0i64;
        v16 = UFG::AudioTriggerRegionTag::FromPropertySet(v15);
        if ( v16[6].mUID == 8 )
          *(_DWORD *)(v6 + 736) |= 1u;
        if ( v16[6].mUID == 3 )
          *(_DWORD *)(v6 + 736) |= 4u;
        if ( v16[6].mUID == 11 )
          *(_DWORD *)(v6 + 736) |= 0x10u;
        if ( v16[6].mUID == 12 )
          *(_DWORD *)(v6 + 736) |= 0x20u;
        if ( v16[7].mUID == -1435567096 )
        {
          *(_DWORD *)(v6 + 736) |= 2u;
          *(UFG::qWiseSymbol *)(v6 + 728) = v16[12];
          *(UFG::qWiseSymbol *)(v6 + 732) = v16[11];
        }
        v17 = v16 + 2;
        v18 = *v13;
        *(_QWORD *)&v18[2].mUID = v17;
        *(_QWORD *)&v17->mUID = v18;
        *(_QWORD *)&v17[2].mUID = v13;
        *v13 = v17;
        ++v12;
      }
      while ( v12 < mNumElements );
    }
    UFG::AudioTriggerRegion::CheckRegionContainment((UFG::AudioTriggerRegion *)v6, 0);
  }
  return (UFG::AudioTriggerRegion *)v6;
}

// File Line: 397
// RVA: 0x596F70
void __fastcall UFG::AudioTriggerRegion::AudioEntityUpdate(UFG::AudioTriggerRegion *this, float delta_sec)
{
  UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> *mPrev; // rbx
  UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> v5; // xmm1
  UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> v6; // xmm3
  UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> v7; // xmm2

  mPrev = this[-1].m_events.UFG::AudioEntity::mNode.UFG::AudioEntity::mPrev;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)mPrev);
  v5 = mPrev[11];
  v6 = (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0>)mPrev[9];
  v7 = mPrev[10];
  *(UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> *)&this->m_Flags = mPrev[8];
  this->m_BoundComponentHandles = v6;
  *(UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> *)&this->i_name.mUID = v7;
  *(UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> *)this->UFG::TriggerRegion::UFG::MarkerBase::UFG::qNodeRB<UFG::MarkerBase>::mNode.mChild = v5;
  UFG::AudioEntity::AudioEntityUpdate((UFG::AudioEntity *)this, delta_sec);
}

// File Line: 411
// RVA: 0x5A3D70
void __fastcall UFG::AudioTriggerRegion::OnEntered(
        UFG::AudioTriggerRegion *this,
        UFG::AudioEntity *pTriggeringEntity,
        bool listener)
{
  char *v6; // rax
  UFG::AudioTriggerRegionTag *i; // rbx
  UFG::AudioEntity *mTriggeringEntity; // rdi
  unsigned int v9; // eax
  UFG::AudioTriggerRegionEvent thisEvent; // [rsp+28h] [rbp-60h] BYREF
  bool global; // [rsp+90h] [rbp+8h] BYREF

  if ( Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(
         (hkGeometryUtils::IVertices *)this,
         (int)pTriggeringEntity,
         listener)
    && listener )
  {
    UFG::AudioEntity::Init(
      &this->UFG::AudioEntity,
      (UFG::qSymbolUC *)&this->m_pSimObject->m_Name,
      &UFG::qMatrix44::msIdentity);
  }
  if ( UFG::TiDo::sm_ambiencesInfo && listener )
  {
    v6 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->UFG::qNamed);
    UFG::qPrintf("AudioTriggerRegion:: Lst Enter :: %s\n", v6);
  }
  for ( i = (UFG::AudioTriggerRegionTag *)&this->mTags.mNode.mNext[-1].mNext;
        i != (UFG::AudioTriggerRegionTag *)&this->UFG::qNodeRB<UFG::AudioTriggerRegion>::mNode.mUID;
        i = (UFG::AudioTriggerRegionTag *)&i->mNext[-1].mNext )
  {
    UFG::AudioTriggerRegionEvent::AudioTriggerRegionEvent(&thisEvent, pTriggeringEntity, this, i);
    UFG::qWiseSymbol::operator=(&i->mAudioModeUidOnExit, &i->mAudioModeUidOnEnter);
    if ( i->mAudioType == 8 && pTriggeringEntity )
    {
      i->mAudioDryLevelOnExit = pTriggeringEntity->m_environment.mDryLevel;
      i->mAudioWetLevelOnExit = UFG::AudioEntity::GetWetLevelForEffect(pTriggeringEntity, i->mAudioUidOnEnter.mUID);
    }
    if ( i->mAudioType == 3 && pTriggeringEntity )
    {
      global = 0;
      i->mAudioRtpcValOnExit = UFG::AudioEntity::Debug_GetRtpcValue(
                                 pTriggeringEntity,
                                 i->mAudioUidOnEnter.mUID,
                                 &global);
      UFG::qWiseSymbol::operator=(&i->mAudioModeUidOnExit, &i->mAudioModeUidOnEnter);
    }
    if ( listener )
    {
      UFG::AudioTriggerRegion::ApplyAudioZoneListener(this, &thisEvent);
    }
    else
    {
      mTriggeringEntity = thisEvent.mTriggeringEntity;
      if ( thisEvent.mTriggeringEntity )
      {
        switch ( thisEvent.mAudioType )
        {
          case 1u:
            if ( UFG::AudioEventPropertyManager::Find(thisEvent.mAudioUidOnEnter.mUID) )
            {
              v9 = _S44_0;
              if ( (_S44_0 & 1) == 0 )
              {
                _S44_0 |= 1u;
                UFG::qWiseSymbol::create_from_string(&stru_14242FA88, "set_minimap_enter");
                atexit(UFG::AudioTriggerRegion::HandleIntExtForEntities_::_4_::_dynamic_atexit_destructor_for__set_minimap_enter__);
                v9 = _S44_0;
              }
              if ( (v9 & 2) == 0 )
              {
                _S44_0 = v9 | 2;
                UFG::qWiseSymbol::create_from_string(&stru_14242FA90, "set_minimap_exit");
                atexit(UFG::AudioTriggerRegion::HandleIntExtForEntities_::_4_::_dynamic_atexit_destructor_for__set_minimap_exit__);
              }
              if ( thisEvent.mAudioUidOnEnter.mUID == stru_14242FA88.mUID )
              {
                ++mTriggeringEntity->m_interiorCount;
                mTriggeringEntity->m_bOcclusionIsDirty = 1;
              }
            }
            break;
          case 3u:
            UFG::AudioEntity::SetRtpcValue(
              thisEvent.mTriggeringEntity,
              thisEvent.mAudioUidOnEnter.mUID,
              thisEvent.mAudioRtpcVal);
            break;
          case 8u:
            if ( thisEvent.mTriggeringEntity->vfptr->CanApplyEnvironment(
                   thisEvent.mTriggeringEntity,
                   &thisEvent.mAudioModeUid) )
            {
              UFG::AudioTriggerRegion::HandleEnvironmentRegionEnter(this, &thisEvent);
            }
            break;
          case 0xCu:
            thisEvent.mTriggeringEntity->m_inDoorRegion = 1;
            break;
        }
      }
    }
    thisEvent.vfptr = (UFG::AudioTriggerRegionEventVtbl *)&UFG::AudioTriggerRegionEvent::`vftable;
    _((AMD_HD3D *)thisEvent.mAudioModeUid.mUID);
    _((AMD_HD3D *)thisEvent.mAudioUidOnExit.mUID);
    _((AMD_HD3D *)thisEvent.mAudioUidOnEnter.mUID);
  }
}

// File Line: 461
// RVA: 0x5A4060
void __fastcall UFG::AudioTriggerRegion::OnExited(
        UFG::AudioTriggerRegion *this,
        UFG::AudioEntity *pTriggeringEntity,
        bool listener)
{
  char *v6; // rax
  UFG::AudioTriggerRegionTag *i; // rdi
  UFG::AudioEntity *mTriggeringEntity; // rbx
  UFG::qBaseTreeRB *v9; // rbp
  unsigned int v10; // ecx
  UFG::AudioTriggerRegionEvent thisEvent; // [rsp+28h] [rbp-60h] BYREF

  if ( UFG::TiDo::sm_ambiencesInfo && listener )
  {
    v6 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->UFG::qNamed);
    UFG::qPrintf("AudioTriggerRegion:: Lst Exit :: %s\n", v6);
  }
  for ( i = (UFG::AudioTriggerRegionTag *)&this->mTags.mNode.mNext[-1].mNext;
        i != (UFG::AudioTriggerRegionTag *)&this->UFG::qNodeRB<UFG::AudioTriggerRegion>::mNode.mUID;
        i = (UFG::AudioTriggerRegionTag *)&i->mNext[-1].mNext )
  {
    UFG::AudioTriggerRegionEvent::AudioTriggerRegionEvent(&thisEvent, pTriggeringEntity, this, i);
    if ( listener )
    {
      UFG::AudioTriggerRegion::RemoveAudioZoneListener(this, &thisEvent);
    }
    else
    {
      mTriggeringEntity = thisEvent.mTriggeringEntity;
      if ( thisEvent.mTriggeringEntity )
      {
        switch ( thisEvent.mAudioType )
        {
          case 1u:
            v9 = UFG::AudioEventPropertyManager::Find(thisEvent.mAudioUidOnEnter.mUID);
            if ( v9 )
            {
              v10 = _S44_0;
              if ( (_S44_0 & 1) == 0 )
              {
                _S44_0 |= 1u;
                UFG::qWiseSymbol::create_from_string(&stru_14242FA88, "set_minimap_enter");
                atexit(UFG::AudioTriggerRegion::HandleIntExtForEntities_::_4_::_dynamic_atexit_destructor_for__set_minimap_enter__);
                v10 = _S44_0;
              }
              if ( (v10 & 2) == 0 )
              {
                _S44_0 = v10 | 2;
                UFG::qWiseSymbol::create_from_string(&stru_14242FA90, "set_minimap_exit");
                atexit(UFG::AudioTriggerRegion::HandleIntExtForEntities_::_4_::_dynamic_atexit_destructor_for__set_minimap_exit__);
              }
              if ( HIDWORD(v9->mNULL.mChild[0][2].mChild[1]) == stru_14242FA90.mUID )
              {
                --mTriggeringEntity->m_interiorCount;
                mTriggeringEntity->m_bOcclusionIsDirty = 1;
              }
            }
            break;
          case 3u:
            UFG::AudioEntity::SetRtpcValue(
              thisEvent.mTriggeringEntity,
              thisEvent.mAudioUidOnExit.mUID,
              thisEvent.mAudioRtpcVal);
            break;
          case 8u:
            if ( thisEvent.mTriggeringEntity->m_environment.totalEnv > 0 )
              UFG::AudioTriggerRegion::HandleEnvironmentRegionExit(this, &thisEvent);
            break;
          case 0xCu:
            thisEvent.mTriggeringEntity->m_inDoorRegion = 0;
            break;
        }
      }
    }
    thisEvent.vfptr = (UFG::AudioTriggerRegionEventVtbl *)&UFG::AudioTriggerRegionEvent::`vftable;
    _((AMD_HD3D *)thisEvent.mAudioModeUid.mUID);
    _((AMD_HD3D *)thisEvent.mAudioUidOnExit.mUID);
    _((AMD_HD3D *)thisEvent.mAudioUidOnEnter.mUID);
  }
  if ( Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(
         (hkGeometryUtils::IVertices *)this,
         (int)pTriggeringEntity,
         listener)
    && listener )
  {
    UFG::AudioEntity::Shutdown(&this->UFG::AudioEntity);
  }
}

// File Line: 613
// RVA: 0x597960
void __fastcall UFG::AudioTriggerRegion::CheckEntity(UFG::AudioEntity *pIn)
{
  float y; // xmm1_4
  float z; // xmm0_4
  Render::SkinningCacheNode *Head; // rax
  UFG::AudioTriggerRegion *p_mCachedBufferPtr; // r14
  UFG::qBaseNodeRB *p_mNode; // rdx
  UFG::qBaseTreeRB *Next; // rax
  UFG::AudioTriggerRegion *mChild; // r12
  unsigned int m_typeFlags; // eax
  UFG::RegionContainmentInfo *ContainmentInfo; // rax
  unsigned int v11; // ecx
  unsigned int size; // edx
  UFG::qSymbol *p; // rax
  bool v14; // bl
  UFG::RegionContainmentInfo *v15; // rax
  unsigned int v16; // ebp
  unsigned int v17; // edi
  UFG::RegionContainmentInfo *v18; // rsi
  unsigned int *p_mUID; // rbx
  UFG::qBaseTreeRB *v20; // rax
  UFG::qBaseNodeRB **v21; // rdx
  int v22; // eax
  char v23; // r10
  unsigned int v24; // r8d
  unsigned int v25; // ecx
  UFG::qSymbol *v26; // rax
  char v27; // al
  UFG::RegionContainmentInfo *v28; // rax
  unsigned int v29; // esi
  UFG::RegionContainmentInfo *v30; // rbp
  unsigned int v31; // edi
  unsigned int *v32; // rbx
  UFG::qBaseTreeRB *v33; // rax
  UFG::qBaseNodeRB **v34; // rdx
  int v35; // eax
  char v36; // r10
  unsigned int v37; // r8d
  unsigned int v38; // ecx
  UFG::qSymbol *v39; // rax
  char v40; // al
  UFG::qVector3 pos; // [rsp+20h] [rbp-28h] BYREF

  y = pIn->m_WorldMatrix.v3.y;
  pos.x = pIn->m_WorldMatrix.v3.x;
  z = pIn->m_WorldMatrix.v3.z;
  pos.y = y;
  pos.z = z;
  Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::AudioTriggerRegion::msAudioTriggerRegions);
  if ( Head )
  {
    p_mCachedBufferPtr = (UFG::AudioTriggerRegion *)&Head[-16].mCachedBufferPtr;
    if ( Head != (Render::SkinningCacheNode *)608 )
    {
      do
      {
        if ( p_mCachedBufferPtr )
          p_mNode = &p_mCachedBufferPtr->UFG::qNodeRB<UFG::AudioTriggerRegion>::mNode;
        else
          p_mNode = 0i64;
        Next = UFG::qBaseTreeRB::GetNext(&UFG::AudioTriggerRegion::msAudioTriggerRegions.mTree, p_mNode);
        if ( Next )
          mChild = (UFG::AudioTriggerRegion *)Next[-9].mNULL.mChild;
        else
          mChild = 0i64;
        m_typeFlags = p_mCachedBufferPtr->m_typeFlags;
        if ( (m_typeFlags & 1) != 0 || (m_typeFlags & 2) != 0 || (m_typeFlags & 4) != 0 || (m_typeFlags & 0x20) != 0 )
        {
          ContainmentInfo = UFG::AudioEntity::GetContainmentInfo(pIn);
          v11 = 0;
          size = ContainmentInfo->m_regionsContainedIn.size;
          if ( size )
          {
            p = ContainmentInfo->m_regionsContainedIn.p;
            while ( p_mCachedBufferPtr->i_name.mUID != p->mUID )
            {
              ++v11;
              ++p;
              if ( v11 >= size )
                goto LABEL_17;
            }
          }
          else
          {
LABEL_17:
            v11 = -1;
          }
          v14 = v11 != -1;
          if ( UFG::TriggerRegion::IsHitPoint(p_mCachedBufferPtr, &pos) )
          {
            if ( !v14 )
            {
              v15 = UFG::AudioEntity::GetContainmentInfo(pIn);
              v16 = p_mCachedBufferPtr->m_regionsContainingMe.m_regionsContainedIn.size;
              v17 = 0;
              v18 = v15;
              if ( v16 )
              {
                p_mUID = &p_mCachedBufferPtr->m_regionsContainingMe.m_regionsContainedIn.p->mUID;
                while ( *p_mUID )
                {
                  v20 = UFG::qBaseTreeRB::Get(&UFG::AudioTriggerRegion::msAudioTriggerRegions.mTree, *p_mUID);
                  if ( !v20 )
                    break;
                  v21 = v20[-9].mNULL.mChild;
                  if ( v20 == (UFG::qBaseTreeRB *)608 )
                    goto LABEL_31;
                  v22 = *((_DWORD *)v21 + 184);
                  if ( (v22 & 1) == 0 && (v22 & 2) == 0 && (v22 & 4) == 0 && (v22 & 0x20) == 0 )
                    goto LABEL_31;
                  v23 = 1;
LABEL_32:
                  v24 = v18->m_regionsContainedIn.size;
                  v25 = 0;
                  if ( !v24 )
                    goto LABEL_38;
                  v26 = v18->m_regionsContainedIn.p;
                  while ( *p_mUID != v26->mUID )
                  {
                    ++v25;
                    ++v26;
                    if ( v25 >= v24 )
                      goto LABEL_38;
                  }
                  if ( v25 == -1 )
                  {
LABEL_38:
                    if ( v21 && v23 )
                    {
                      v27 = 0;
                      goto LABEL_42;
                    }
                  }
                  ++v17;
                  ++p_mUID;
                  if ( v17 >= v16 )
                    goto LABEL_41;
                }
                v21 = 0i64;
LABEL_31:
                v23 = 0;
                goto LABEL_32;
              }
LABEL_41:
              v27 = 1;
LABEL_42:
              if ( v27 )
              {
                UFG::AudioTriggerRegion::SetEntered(pIn, p_mCachedBufferPtr);
                UFG::AudioTriggerRegion::OnEntered(p_mCachedBufferPtr, pIn, 0);
              }
            }
          }
          else if ( v14 )
          {
            v28 = UFG::AudioEntity::GetContainmentInfo(pIn);
            v29 = p_mCachedBufferPtr->m_regionsIContain.m_regionsContainedIn.size;
            v30 = v28;
            if ( !v29 )
            {
LABEL_67:
              v40 = 1;
LABEL_68:
              if ( v40 )
              {
                UFG::AudioTriggerRegion::SetExited(pIn, p_mCachedBufferPtr);
                UFG::AudioTriggerRegion::OnExited(p_mCachedBufferPtr, pIn, 0);
              }
              goto LABEL_70;
            }
            v31 = 0;
            v32 = &p_mCachedBufferPtr->m_regionsIContain.m_regionsContainedIn.p->mUID;
            while ( 2 )
            {
              if ( *v32
                && (v33 = UFG::qBaseTreeRB::Get(&UFG::AudioTriggerRegion::msAudioTriggerRegions.mTree, *v32)) != 0i64 )
              {
                v34 = v33[-9].mNULL.mChild;
                if ( v33 != (UFG::qBaseTreeRB *)608 )
                {
                  v35 = *((_DWORD *)v34 + 184);
                  if ( (v35 & 1) != 0 || (v35 & 2) != 0 || (v35 & 4) != 0 || (v35 & 0x20) != 0 )
                  {
                    v36 = 1;
                    goto LABEL_58;
                  }
                }
              }
              else
              {
                v34 = 0i64;
              }
              v36 = 0;
LABEL_58:
              v37 = v30->m_regionsContainedIn.size;
              v38 = 0;
              if ( v37 )
              {
                v39 = v30->m_regionsContainedIn.p;
                while ( *v32 != v39->mUID )
                {
                  ++v38;
                  ++v39;
                  if ( v38 >= v37 )
                    goto LABEL_66;
                }
                if ( v38 != -1 && v34 && v36 )
                {
                  v40 = 0;
                  goto LABEL_68;
                }
              }
LABEL_66:
              ++v31;
              ++v32;
              if ( v31 >= v29 )
                goto LABEL_67;
              continue;
            }
          }
        }
LABEL_70:
        p_mCachedBufferPtr = mChild;
      }
      while ( mChild );
    }
  }
}

// File Line: 669
// RVA: 0x5AAC80
void __fastcall UFG::AudioTriggerRegion::SetEntered(UFG::AudioEntity *pIn, UFG::AudioTriggerRegion *region)
{
  UFG::RegionContainmentInfo *ContainmentInfo; // rax
  unsigned int size; // r8d
  UFG::qArray<UFG::qSymbol,0> *p_m_regionsContainedIn; // r9
  unsigned int v7; // ebx
  unsigned int v8; // eax
  UFG::qSymbol *p; // rcx
  UFG::qSymbol *Name; // rax
  unsigned int v11; // edx
  UFG::qSymbol *v12; // rcx
  UFG::qSymbol result; // [rsp+30h] [rbp+8h] BYREF

  ContainmentInfo = UFG::AudioEntity::GetContainmentInfo(pIn);
  size = ContainmentInfo->m_regionsContainedIn.size;
  p_m_regionsContainedIn = &ContainmentInfo->m_regionsContainedIn;
  v7 = 0;
  v8 = 0;
  if ( !size )
    goto LABEL_7;
  p = p_m_regionsContainedIn->p;
  while ( region->i_name.mUID != p->mUID )
  {
    ++v8;
    ++p;
    if ( v8 >= size )
      goto LABEL_7;
  }
  if ( v8 == -1 )
LABEL_7:
    UFG::qArray<UFG::qSymbol,0>::Add(p_m_regionsContainedIn, &region->i_name, "RegionContainmentInfo.Array");
  Name = UFG::AudioEntity::GetName(pIn, &result);
  v11 = region->m_thingsIContain.m_regionsContainedIn.size;
  if ( !v11 )
    goto LABEL_14;
  v12 = region->m_thingsIContain.m_regionsContainedIn.p;
  while ( Name->mUID != v12->mUID )
  {
    ++v7;
    ++v12;
    if ( v7 >= v11 )
      goto LABEL_14;
  }
  if ( v7 == -1 )
LABEL_14:
    UFG::qArray<UFG::qSymbol,0>::Add(
      &region->m_thingsIContain.m_regionsContainedIn,
      Name,
      "RegionContainmentInfo.Array");
  pIn->m_bOcclusionIsDirty = 1;
}

// File Line: 675
// RVA: 0x5AAD50
void __fastcall UFG::AudioTriggerRegion::SetExited(UFG::AudioEntity *pIn, UFG::AudioTriggerRegion *region)
{
  UFG::RegionContainmentInfo *ContainmentInfo; // r9
  unsigned int size; // eax
  __int64 v6; // r8
  UFG::qSymbol *p; // rcx
  unsigned int v8; // eax
  UFG::qSymbol *Name; // rax
  unsigned int v10; // ecx
  __int64 v11; // rdx
  unsigned int mUID; // r8d
  UFG::qSymbol *i; // rax
  unsigned int v14; // eax
  UFG::qSymbol result; // [rsp+30h] [rbp+8h] BYREF

  ContainmentInfo = UFG::AudioEntity::GetContainmentInfo(pIn);
  size = ContainmentInfo->m_regionsContainedIn.size;
  v6 = 0i64;
  if ( size )
  {
    p = ContainmentInfo->m_regionsContainedIn.p;
    while ( region->i_name.mUID != p->mUID )
    {
      v6 = (unsigned int)(v6 + 1);
      ++p;
      if ( (unsigned int)v6 >= size )
        goto LABEL_10;
    }
    if ( (_DWORD)v6 != -1 )
    {
      ContainmentInfo->m_regionsContainedIn.p[v6].mUID = ContainmentInfo->m_regionsContainedIn.p[size - 1].mUID;
      v8 = ContainmentInfo->m_regionsContainedIn.size;
      if ( v8 > 1 )
        ContainmentInfo->m_regionsContainedIn.size = v8 - 1;
      else
        ContainmentInfo->m_regionsContainedIn.size = 0;
    }
  }
LABEL_10:
  Name = UFG::AudioEntity::GetName(pIn, &result);
  v10 = region->m_thingsIContain.m_regionsContainedIn.size;
  v11 = 0i64;
  if ( v10 )
  {
    mUID = Name->mUID;
    for ( i = region->m_thingsIContain.m_regionsContainedIn.p; mUID != i->mUID; ++i )
    {
      v11 = (unsigned int)(v11 + 1);
      if ( (unsigned int)v11 >= v10 )
      {
        pIn->m_bOcclusionIsDirty = 1;
        return;
      }
    }
    if ( (_DWORD)v11 != -1 )
    {
      region->m_thingsIContain.m_regionsContainedIn.p[v11].mUID = region->m_thingsIContain.m_regionsContainedIn.p[v10 - 1].mUID;
      v14 = region->m_thingsIContain.m_regionsContainedIn.size;
      if ( v14 <= 1 )
      {
        region->m_thingsIContain.m_regionsContainedIn.size = 0;
        pIn->m_bOcclusionIsDirty = 1;
        return;
      }
      region->m_thingsIContain.m_regionsContainedIn.size = v14 - 1;
    }
  }
  pIn->m_bOcclusionIsDirty = 1;
}

// File Line: 688
// RVA: 0x597F30
void __fastcall UFG::AudioTriggerRegion::CheckListener(UFG::AudioListener *pIn)
{
  float y; // xmm1_4
  float z; // xmm2_4
  char v4; // si
  Render::SkinningCacheNode *Head; // rax
  Illusion::Buffer **p_mCachedBufferPtr; // rbx
  UFG::qBaseNodeRB *v7; // rdx
  UFG::qBaseTreeRB *Next; // rax
  UFG::qBaseNodeRB **mChild; // r14
  int v10; // ecx
  unsigned int size; // edx
  bool v12; // di
  int v13; // edx
  hkGeometryUtils::IVertices *v14; // rcx
  int v15; // r8d
  char *v16; // rax
  UFG::AudioTriggerRegionTag *i; // rdi
  int v18; // ecx
  unsigned int v19; // edx
  UFG::qSymbol *p; // r8
  hkGeometryUtils::IVertices *v21; // rcx
  unsigned int v22; // edx
  unsigned int v23; // eax
  char *v24; // rax
  UFG::AudioTriggerRegionTag *j; // rdi
  UFG::qVector3 pos; // [rsp+20h] [rbp-B8h] BYREF
  __int64 v27; // [rsp+30h] [rbp-A8h]
  UFG::AudioTriggerRegionEvent thisEvent; // [rsp+38h] [rbp-A0h] BYREF
  UFG::AudioTriggerRegionEvent v29; // [rsp+70h] [rbp-68h] BYREF

  v27 = -2i64;
  y = pIn->m_triggerPosition.y;
  z = pIn->m_triggerPosition.z;
  pos.x = pIn->m_triggerPosition.x;
  pos.y = y;
  pos.z = z;
  v4 = 0;
  Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::AudioTriggerRegion::msAudioTriggerRegions);
  if ( Head )
  {
    p_mCachedBufferPtr = &Head[-16].mCachedBufferPtr;
    if ( Head != (Render::SkinningCacheNode *)608 )
    {
      while ( 1 )
      {
        v7 = (UFG::qBaseNodeRB *)(p_mCachedBufferPtr + 76);
        if ( !p_mCachedBufferPtr )
          v7 = 0i64;
        Next = UFG::qBaseTreeRB::GetNext(&UFG::AudioTriggerRegion::msAudioTriggerRegions.mTree, v7);
        mChild = Next[-9].mNULL.mChild;
        if ( !Next )
          mChild = 0i64;
        v10 = 0;
        size = pIn->m_containmentInfo.m_regionsContainedIn.size;
        if ( size )
        {
          while ( *((_DWORD *)p_mCachedBufferPtr + 16) != pIn->m_containmentInfo.m_regionsContainedIn.p[v10].mUID )
          {
            if ( ++v10 >= size )
              goto LABEL_10;
          }
        }
        else
        {
LABEL_10:
          v10 = -1;
        }
        v12 = v10 != -1;
        if ( UFG::TriggerRegion::IsHitPoint((UFG::TriggerRegion *)p_mCachedBufferPtr, &pos) )
        {
          if ( v12
            || !UFG::AudioTriggerRegion::CheckContainmentForEntry(
                  (UFG::AudioTriggerRegion *)p_mCachedBufferPtr,
                  &pIn->m_containmentInfo,
                  1) )
          {
            goto LABEL_44;
          }
          if ( Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(v14, v13, v15) )
            UFG::AudioEntity::Init(
              (UFG::AudioEntity *)(p_mCachedBufferPtr + 36),
              (UFG::qSymbolUC *)&p_mCachedBufferPtr[5]->mDebugName[20],
              &UFG::qMatrix44::msIdentity);
          if ( UFG::TiDo::sm_ambiencesInfo )
          {
            v16 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)p_mCachedBufferPtr + 16);
            UFG::qPrintf("AudioTriggerRegion:: Lst Enter :: %s\n", v16);
          }
          for ( i = (UFG::AudioTriggerRegionTag *)&p_mCachedBufferPtr[81][-1].pad1;
                i != (UFG::AudioTriggerRegionTag *)(p_mCachedBufferPtr + 79);
                i = (UFG::AudioTriggerRegionTag *)&i->mNext[-1].mNext )
          {
            UFG::AudioTriggerRegionEvent::AudioTriggerRegionEvent(
              &thisEvent,
              0i64,
              (UFG::AudioTriggerRegion *)p_mCachedBufferPtr,
              i);
            UFG::qWiseSymbol::operator=(&i->mAudioModeUidOnExit, &i->mAudioModeUidOnEnter);
            UFG::AudioTriggerRegion::ApplyAudioZoneListener((UFG::AudioTriggerRegion *)p_mCachedBufferPtr, &thisEvent);
            thisEvent.vfptr = (UFG::AudioTriggerRegionEventVtbl *)&UFG::AudioTriggerRegionEvent::`vftable;
            _((AMD_HD3D *)thisEvent.mAudioModeUid.mUID);
            _((AMD_HD3D *)thisEvent.mAudioUidOnExit.mUID);
            _((AMD_HD3D *)thisEvent.mAudioUidOnEnter.mUID);
          }
          v18 = 0;
          v19 = pIn->m_containmentInfo.m_regionsContainedIn.size;
          if ( !v19 )
            goto LABEL_25;
          while ( *((_DWORD *)p_mCachedBufferPtr + 16) != pIn->m_containmentInfo.m_regionsContainedIn.p[v18].mUID )
          {
            if ( ++v18 >= v19 )
              goto LABEL_25;
          }
          if ( v18 == -1 )
LABEL_25:
            UFG::qArray<UFG::qSymbol,0>::Add(
              &pIn->m_containmentInfo.m_regionsContainedIn,
              (UFG::qSymbol *)p_mCachedBufferPtr + 16,
              "RegionContainmentInfo.Array");
        }
        else
        {
          if ( !v12
            || !UFG::AudioTriggerRegion::CheckContainmentForExit(
                  (UFG::AudioTriggerRegion *)p_mCachedBufferPtr,
                  &pIn->m_containmentInfo,
                  1) )
          {
            goto LABEL_44;
          }
          v21 = 0i64;
          v22 = pIn->m_containmentInfo.m_regionsContainedIn.size;
          if ( v22 )
          {
            p = pIn->m_containmentInfo.m_regionsContainedIn.p;
            while ( *((_DWORD *)p_mCachedBufferPtr + 16) != p[(_QWORD)v21].mUID )
            {
              v21 = (hkGeometryUtils::IVertices *)(unsigned int)((_DWORD)v21 + 1);
              if ( (unsigned int)v21 >= v22 )
                goto LABEL_37;
            }
            if ( (_DWORD)v21 != -1 )
            {
              p[(_QWORD)v21] = p[v22 - 1];
              v23 = pIn->m_containmentInfo.m_regionsContainedIn.size;
              if ( v23 > 1 )
                pIn->m_containmentInfo.m_regionsContainedIn.size = v23 - 1;
              else
                pIn->m_containmentInfo.m_regionsContainedIn.size = 0;
            }
          }
LABEL_37:
          if ( UFG::TiDo::sm_ambiencesInfo )
          {
            v24 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)p_mCachedBufferPtr + 16);
            UFG::qPrintf("AudioTriggerRegion:: Lst Exit :: %s\n", v24);
          }
          for ( j = (UFG::AudioTriggerRegionTag *)&p_mCachedBufferPtr[81][-1].pad1;
                j != (UFG::AudioTriggerRegionTag *)(p_mCachedBufferPtr + 79);
                j = (UFG::AudioTriggerRegionTag *)&j->mNext[-1].mNext )
          {
            UFG::AudioTriggerRegionEvent::AudioTriggerRegionEvent(
              &v29,
              0i64,
              (UFG::AudioTriggerRegion *)p_mCachedBufferPtr,
              j);
            UFG::AudioTriggerRegion::RemoveAudioZoneListener((UFG::AudioTriggerRegion *)p_mCachedBufferPtr, &v29);
            v29.vfptr = (UFG::AudioTriggerRegionEventVtbl *)&UFG::AudioTriggerRegionEvent::`vftable;
            _((AMD_HD3D *)v29.mAudioModeUid.mUID);
            _((AMD_HD3D *)v29.mAudioUidOnExit.mUID);
            _((AMD_HD3D *)v29.mAudioUidOnEnter.mUID);
          }
          if ( Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(v21, v22, (int)p) )
            UFG::AudioEntity::Shutdown((UFG::AudioEntity *)(p_mCachedBufferPtr + 36));
        }
        v4 = 1;
LABEL_44:
        p_mCachedBufferPtr = (Illusion::Buffer **)mChild;
        if ( !mChild )
        {
          if ( v4 )
            UFG::TiDo::MarkAllOcclusionInfosDirty();
          return;
        }
      }
    }
  }
}

// File Line: 744
// RVA: 0x598290
void __fastcall UFG::AudioTriggerRegion::CheckRegionContainment(UFG::AudioTriggerRegion *regionToCheck, bool listSkip)
{
  UFG::RegionComponent *m_pPointer; // rcx
  UFG::qBaseTreeRB *Next; // rax
  UFG::AudioTriggerRegion *v6; // rbx
  UFG::RegionComponent *v7; // rcx
  unsigned int size; // edx
  unsigned int v9; // eax
  UFG::qSymbol *p; // rcx
  unsigned int v11; // edx
  unsigned int v12; // eax
  UFG::qSymbol *v13; // rcx
  UFG::qNamed *v14; // rdx
  UFG::qArray<UFG::qSymbol,0> *p_m_regionsContainedIn; // rcx
  unsigned int v16; // edx
  unsigned int v17; // eax
  UFG::qSymbol *v18; // rcx
  unsigned int v19; // edx
  unsigned int v20; // eax
  UFG::qSymbol *v21; // rcx
  UFG::qBox v22; // [rsp+20h] [rbp-30h] BYREF
  UFG::qBox pBox; // [rsp+38h] [rbp-18h] BYREF

  m_pPointer = (UFG::RegionComponent *)regionToCheck->mpRegion.m_pPointer;
  memset(&pBox, 0, sizeof(pBox));
  UFG::RegionComponent::GetBoundingBox(m_pPointer, &pBox);
  if ( listSkip )
    Next = UFG::qBaseTreeRB::GetNext(
             &UFG::AudioTriggerRegion::msAudioTriggerRegions.mTree,
             &regionToCheck->UFG::qNodeRB<UFG::AudioTriggerRegion>::mNode);
  else
    Next = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::AudioTriggerRegion::msAudioTriggerRegions);
  while ( 1 )
  {
    v6 = Next ? (UFG::AudioTriggerRegion *)Next[-9].mNULL.mChild : 0i64;
    if ( !v6 )
      break;
    if ( v6 == regionToCheck )
      goto LABEL_48;
    v7 = (UFG::RegionComponent *)v6->mpRegion.m_pPointer;
    memset(&v22, 0, sizeof(v22));
    UFG::RegionComponent::GetBoundingBox(v7, &v22);
    if ( v22.mMin.x <= pBox.mMax.x
      && v22.mMax.x >= pBox.mMin.x
      && v22.mMin.y <= pBox.mMax.y
      && v22.mMax.y >= pBox.mMin.y
      && v22.mMin.z <= pBox.mMax.z
      && v22.mMax.z >= pBox.mMin.z )
    {
      if ( UFG::AudioTriggerRegion::Contains(v6, regionToCheck) == eContainmentType_FullyContained )
      {
        size = regionToCheck->m_regionsContainingMe.m_regionsContainedIn.size;
        v9 = 0;
        if ( !size )
          goto LABEL_22;
        p = regionToCheck->m_regionsContainingMe.m_regionsContainedIn.p;
        while ( v6->i_name.mUID != p->mUID )
        {
          ++v9;
          ++p;
          if ( v9 >= size )
            goto LABEL_22;
        }
        if ( v9 == -1 )
LABEL_22:
          UFG::qArray<UFG::qSymbol,0>::Add(
            &regionToCheck->m_regionsContainingMe.m_regionsContainedIn,
            &v6->i_name,
            "RegionContainmentInfo.Array");
        v11 = v6->m_regionsIContain.m_regionsContainedIn.size;
        v12 = 0;
        if ( !v11 )
          goto LABEL_29;
        v13 = v6->m_regionsIContain.m_regionsContainedIn.p;
        while ( regionToCheck->i_name.mUID != v13->mUID )
        {
          ++v12;
          ++v13;
          if ( v12 >= v11 )
          {
            v14 = &regionToCheck->UFG::qNamed;
            p_m_regionsContainedIn = &v6->m_regionsIContain.m_regionsContainedIn;
            goto LABEL_45;
          }
        }
        if ( v12 == -1 )
        {
LABEL_29:
          v14 = &regionToCheck->UFG::qNamed;
          p_m_regionsContainedIn = &v6->m_regionsIContain.m_regionsContainedIn;
          goto LABEL_45;
        }
      }
      else if ( UFG::AudioTriggerRegion::Contains(regionToCheck, v6) == eContainmentType_FullyContained )
      {
        v16 = v6->m_regionsContainingMe.m_regionsContainedIn.size;
        v17 = 0;
        if ( !v16 )
          goto LABEL_37;
        v18 = v6->m_regionsContainingMe.m_regionsContainedIn.p;
        while ( regionToCheck->i_name.mUID != v18->mUID )
        {
          ++v17;
          ++v18;
          if ( v17 >= v16 )
            goto LABEL_37;
        }
        if ( v17 == -1 )
LABEL_37:
          UFG::qArray<UFG::qSymbol,0>::Add(
            &v6->m_regionsContainingMe.m_regionsContainedIn,
            &regionToCheck->i_name,
            "RegionContainmentInfo.Array");
        v19 = regionToCheck->m_regionsIContain.m_regionsContainedIn.size;
        v20 = 0;
        if ( !v19 )
          goto LABEL_44;
        v21 = regionToCheck->m_regionsIContain.m_regionsContainedIn.p;
        while ( v6->i_name.mUID != v21->mUID )
        {
          ++v20;
          ++v21;
          if ( v20 >= v19 )
            goto LABEL_44;
        }
        if ( v20 == -1 )
        {
LABEL_44:
          v14 = &v6->UFG::qNamed;
          p_m_regionsContainedIn = &regionToCheck->m_regionsIContain.m_regionsContainedIn;
LABEL_45:
          UFG::qArray<UFG::qSymbol,0>::Add(p_m_regionsContainedIn, &v14->i_name, "RegionContainmentInfo.Array");
        }
      }
      ++UFG::g_dbgPass;
      goto LABEL_48;
    }
    ++UFG::g_dbgFail;
LABEL_48:
    Next = UFG::qBaseTreeRB::GetNext(
             &UFG::AudioTriggerRegion::msAudioTriggerRegions.mTree,
             &v6->UFG::qNodeRB<UFG::AudioTriggerRegion>::mNode);
  }
}

// File Line: 830
// RVA: 0x155CD90
__int64 UFG::_dynamic_initializer_for__sPolyVsPolyCache__()
{
  UFG::sPolyVsPolyCache.mTree.mNULL.mParent = (UFG::qBaseNodeVariableRB<unsigned __int64> *)((unsigned __int64)&UFG::sPolyVsPolyCache.mTree.mNULL & 0xFFFFFFFFFFFFFFFEui64);
  UFG::sPolyVsPolyCache.mTree.mRoot.mParent = (UFG::qBaseNodeVariableRB<unsigned __int64> *)((unsigned __int64)&UFG::sPolyVsPolyCache.mTree.mNULL & 0xFFFFFFFFFFFFFFFEui64);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sPolyVsPolyCache__);
}

// File Line: 838
// RVA: 0x59C2F0
UFG::qBaseNodeRB **__fastcall UFG::AudioTriggerRegion::FindInnermostRegionOfTypeContainingObject(
        UFG::AudioTriggerRegion *this,
        UFG::RegionContainmentInfo *objectContainment,
        UFG::AudioTriggerRegion::eTypeFlags type)
{
  UFG::qBaseNodeRB **v4; // r12
  __int64 size; // rsi
  unsigned int v6; // ebp
  UFG::allocator::free_link *v7; // rax
  unsigned __int64 v8; // rax
  UFG::qSymbol *p; // r13
  UFG::allocator::free_link *v10; // rbx
  UFG::qSymbol *v11; // rdi
  __int64 v12; // r14
  UFG::qBaseTreeRB *v13; // rax
  UFG::qBaseNodeRB **mChild; // rax
  UFG::allocator::free_link *v15; // r15
  UFG::qSymbol *v16; // r14
  __int64 v17; // rcx
  __int64 v18; // rbp
  unsigned int mUID; // eax
  UFG::allocator::free_link *mNext; // rbx
  char v21; // si
  UFG::qSymbol *v22; // r11
  __int64 v23; // rdi
  __int64 v24; // rcx
  unsigned int v25; // r8d
  UFG::allocator::free_link *mem; // [rsp+30h] [rbp-48h]
  UFG::qArray<UFG::qSymbol,0> v28; // [rsp+38h] [rbp-40h] BYREF
  __int64 v29; // [rsp+88h] [rbp+10h]

  v28.p = 0i64;
  *(_QWORD *)&v28.size = 0i64;
  UFG::qArray<UFG::qSymbol,0>::Clone(&objectContainment->m_regionsContainedIn, &v28);
  v4 = 0i64;
  size = v28.size;
  v6 = v28.size;
  v7 = 0i64;
  mem = 0i64;
  if ( v28.size )
  {
    v8 = 8i64 * v28.size;
    if ( !is_mul_ok(v28.size, 8ui64) )
      v8 = -1i64;
    v7 = UFG::qMalloc(v8, "qArray.Reallocate(Constructor)", 0i64);
    mem = v7;
  }
  p = v28.p;
  if ( (_DWORD)size )
  {
    v10 = v7;
    v11 = v28.p;
    v12 = size;
    do
    {
      if ( v11->mUID
        && (v13 = UFG::qBaseTreeRB::Get(&UFG::AudioTriggerRegion::msAudioTriggerRegions.mTree, v11->mUID)) != 0i64
        && (mChild = v13[-9].mNULL.mChild) != 0i64
        && (type & (_DWORD)mChild[92]) != 0 )
      {
        v4 = mChild;
        v10->mNext = (UFG::allocator::free_link *)mChild;
      }
      else
      {
        v11->mUID = UFG::gNullQSymbol.mUID;
        --v6;
        v10->mNext = 0i64;
      }
      ++v11;
      ++v10;
      --v12;
    }
    while ( v12 );
  }
  if ( v6 > 1 && (_DWORD)size )
  {
    v15 = mem;
    v16 = p;
    v17 = size;
    v29 = size;
    v18 = size;
    mUID = UFG::gNullQSymbol.mUID;
    do
    {
      if ( v16->mUID != mUID )
      {
        mNext = v15->mNext;
        v21 = 0;
        v22 = p;
        v23 = v17;
        do
        {
          if ( v22->mUID != mUID )
          {
            if ( mNext )
            {
              v24 = 0i64;
              v25 = (unsigned int)mNext[86].mNext;
              if ( v25 )
              {
                while ( v22->mUID != *((_DWORD *)&mNext[87].mNext->mNext + v24) )
                {
                  v24 = (unsigned int)(v24 + 1);
                  if ( (unsigned int)v24 >= v25 )
                    goto LABEL_27;
                }
                if ( (_DWORD)v24 != -1 )
                {
                  v16->mUID = mUID;
                  v15->mNext = 0i64;
                  v21 = 1;
                  mUID = UFG::gNullQSymbol.mUID;
                }
              }
            }
          }
LABEL_27:
          ++v22;
          --v23;
        }
        while ( v23 );
        if ( !v21 )
          v4 = (UFG::qBaseNodeRB **)mNext;
        v17 = v29;
      }
      ++v16;
      ++v15;
      --v18;
    }
    while ( v18 );
  }
  if ( mem )
    operator delete[](mem);
  if ( p )
  {
    `eh vector destructor iterator(p, 4ui64, p[-1].mUID, (void (__fastcall *)(void *))_);
    operator delete[](&p[-1]);
  }
  return v4;
}

// File Line: 913
// RVA: 0x598D20
__int64 __fastcall UFG::AudioTriggerRegion::Contains(
        UFG::AudioTriggerRegion *this,
        UFG::AudioTriggerRegion *audioRegion)
{
  UFG::AudioTriggerRegion *v2; // rsi
  UFG::RegionComponent *m_pPointer; // r10
  UFG::RegionBase *mPtr; // rbx
  unsigned __int64 v6; // r9
  UFG::qTreeRB64<UFG::PolyVsPolyCache,UFG::PolyVsPolyCache,1> *v7; // rax
  UFG::qTreeRB64<UFG::PolyVsPolyCache,UFG::PolyVsPolyCache,1> *i; // rcx
  UFG::TransformNodeComponent *XformNode; // rbp
  unsigned int mRefCount; // r12d
  int v12; // edi
  __int64 v13; // rsi
  __int64 v14; // r14
  UFG::RegionBaseVtbl *vfptr; // rax
  float v16; // xmm2_4
  float v17; // xmm6_4
  float v18; // xmm11_4
  float v19; // xmm9_4
  float v20; // xmm7_4
  float v21; // xmm12_4
  float v22; // xmm10_4
  float v23; // xmm8_4
  unsigned int j; // ebx
  float v25; // xmm6_4
  float v26; // xmm5_4
  float v27; // xmm4_4
  float v28; // xmm3_4
  float v29; // xmm2_4
  float v30; // xmm4_4
  unsigned int v31; // r15d
  UFG::SimObject *m_pSimObject; // rbx
  UFG::SimObject *v33; // rdi
  UFG::allocator::free_link *v34; // rax
  UFG::qBaseNodeVariableRB<unsigned __int64> *v35; // r8
  __int64 mUID; // rdx
  __int64 v37; // rcx
  UFG::qVector3 pos; // [rsp+28h] [rbp-B0h] BYREF

  v2 = audioRegion;
  m_pPointer = (UFG::RegionComponent *)audioRegion->mpRegion.m_pPointer;
  mPtr = m_pPointer->mpRegion.mPtr;
  v6 = this->m_pSimObject->m_Name.mUID | ((unsigned __int64)audioRegion->m_pSimObject->m_Name.mUID << 32);
  if ( v6 )
  {
    v7 = &UFG::sPolyVsPolyCache;
    while ( v7 == &UFG::sPolyVsPolyCache || v7->mTree.mRoot.mUID != v6 )
    {
      if ( v6 > v7->mTree.mRoot.mUID )
        v7 = (UFG::qTreeRB64<UFG::PolyVsPolyCache,UFG::PolyVsPolyCache,1> *)v7->mTree.mRoot.mChild[1];
      else
        v7 = (UFG::qTreeRB64<UFG::PolyVsPolyCache,UFG::PolyVsPolyCache,1> *)v7->mTree.mRoot.mChild[0];
      if ( v7 == (UFG::qTreeRB64<UFG::PolyVsPolyCache,UFG::PolyVsPolyCache,1> *)&UFG::sPolyVsPolyCache.mTree.mNULL )
        goto LABEL_15;
    }
    for ( i = (UFG::qTreeRB64<UFG::PolyVsPolyCache,UFG::PolyVsPolyCache,1> *)v7->mTree.mRoot.mChild[0];
          i;
          i = (UFG::qTreeRB64<UFG::PolyVsPolyCache,UFG::PolyVsPolyCache,1> *)i->mTree.mRoot.mChild[0] )
    {
      if ( i->mTree.mRoot.mUID != v6 )
        break;
      v7 = i;
    }
    if ( v7 )
      return LODWORD(v7->mTree.mNULL.mParent);
  }
LABEL_15:
  XformNode = (UFG::TransformNodeComponent *)UFG::RegionComponent::GetXformNode(m_pPointer);
  UFG::TransformNodeComponent::UpdateWorldTransform(XformNode);
  if ( mPtr->vfptr->GetType(mPtr) == RegionType_polygon )
  {
    mRefCount = mPtr[1].mRefCount;
    v12 = 0;
    if ( mRefCount )
    {
      v13 = 0i64;
      v14 = mRefCount;
      do
      {
        vfptr = mPtr[1].vfptr;
        v16 = (float)((float)((float)(*(float *)((char *)&vfptr->__vecDelDtor + v13 + 4)
                                    * XformNode->mWorldTransform.v1.y)
                            + (float)(*(float *)((char *)&vfptr->__vecDelDtor + v13) * XformNode->mWorldTransform.v0.y))
                    + (float)(*(float *)((char *)&vfptr->__vecDelDtor + v13 + 8) * XformNode->mWorldTransform.v2.y))
            + XformNode->mWorldTransform.v3.y;
        v17 = (float)((float)((float)(*(float *)((char *)&vfptr->__vecDelDtor + v13 + 4)
                                    * XformNode->mWorldTransform.v1.z)
                            + (float)(*(float *)((char *)&vfptr->__vecDelDtor + v13) * XformNode->mWorldTransform.v0.z))
                    + (float)(*(float *)((char *)&vfptr->__vecDelDtor + v13 + 8) * XformNode->mWorldTransform.v2.z))
            + XformNode->mWorldTransform.v3.z;
        pos.x = (float)((float)((float)(*(float *)((char *)&vfptr->__vecDelDtor + v13) * XformNode->mWorldTransform.v0.x)
                              + (float)(*(float *)((char *)&vfptr->__vecDelDtor + v13 + 4)
                                      * XformNode->mWorldTransform.v1.x))
                      + (float)(*(float *)((char *)&vfptr->__vecDelDtor + v13 + 8) * XformNode->mWorldTransform.v2.x))
              + XformNode->mWorldTransform.v3.x;
        pos.y = v16;
        pos.z = v17;
        if ( UFG::RegionComponent::IsHitPoint((UFG::RegionComponent *)this->mpRegion.m_pPointer, &pos) )
          ++v12;
        v13 += 12i64;
        --v14;
      }
      while ( v14 );
      v2 = audioRegion;
    }
  }
  else
  {
    if ( mPtr->vfptr->GetType(mPtr) != RegionType_box )
    {
LABEL_40:
      v31 = 1;
      goto LABEL_41;
    }
    v18 = *(float *)&mPtr[1].vfptr;
    v19 = *((float *)&mPtr[1].vfptr + 1);
    v20 = *(float *)&mPtr[1].mRefCount;
    v21 = *((float *)&mPtr[1].mRefCount + 1);
    v22 = *(float *)&mPtr[2].vfptr;
    v23 = *((float *)&mPtr[2].vfptr + 1);
    v12 = 0;
    mRefCount = 8;
    for ( j = 0; j < 8; ++j )
    {
      if ( (j & 4) != 0 )
        v25 = v23;
      else
        v25 = v20;
      if ( (j & 2) != 0 )
        v26 = v22;
      else
        v26 = v19;
      if ( (j & 1) != 0 )
        v27 = v21;
      else
        v27 = v18;
      v28 = (float)((float)((float)(v27 * XformNode->mWorldTransform.v0.x)
                          + (float)(v26 * XformNode->mWorldTransform.v1.x))
                  + (float)(v25 * XformNode->mWorldTransform.v2.x))
          + XformNode->mWorldTransform.v3.x;
      v29 = (float)((float)((float)(v27 * XformNode->mWorldTransform.v0.y)
                          + (float)(v26 * XformNode->mWorldTransform.v1.y))
                  + (float)(v25 * XformNode->mWorldTransform.v2.y))
          + XformNode->mWorldTransform.v3.y;
      v30 = (float)((float)((float)(v27 * XformNode->mWorldTransform.v0.z)
                          + (float)(v26 * XformNode->mWorldTransform.v1.z))
                  + (float)(v25 * XformNode->mWorldTransform.v2.z))
          + XformNode->mWorldTransform.v3.z;
      pos.x = v28;
      pos.y = v29;
      pos.z = v30;
      if ( UFG::RegionComponent::IsHitPoint((UFG::RegionComponent *)this->mpRegion.m_pPointer, &pos) )
        ++v12;
    }
  }
  if ( v12 == mRefCount )
    goto LABEL_40;
  if ( v12 )
    v31 = 2;
  else
    v31 = 0;
LABEL_41:
  m_pSimObject = this->m_pSimObject;
  v33 = v2->m_pSimObject;
  v34 = UFG::qMalloc(0x28ui64, "PolyVsPolyCache", 0i64);
  v35 = (UFG::qBaseNodeVariableRB<unsigned __int64> *)v34;
  if ( v34 )
  {
    mUID = m_pSimObject->m_Name.mUID;
    v37 = v33->m_Name.mUID;
    v34->mNext = 0i64;
    v34[1].mNext = 0i64;
    v34[2].mNext = 0i64;
    v34[3].mNext = (UFG::allocator::free_link *)(mUID | (v37 << 32));
    LODWORD(v34[4].mNext) = v31;
  }
  else
  {
    v35 = 0i64;
  }
  UFG::qBaseTreeVariableRB<unsigned __int64>::Add(&UFG::sPolyVsPolyCache.mTree, v35);
  return v31;
}

// File Line: 1011
// RVA: 0x5B01F0
void UFG::AudioTriggerRegion::UpdateContainmentHierarchy(void)
{
  Render::SkinningCacheNode *Head; // rax
  UFG::qBaseNodeRB *p_mCachedBufferPtr; // rbx
  UFG::qBaseNodeRB *mParent; // rcx
  char *v3; // rdi
  char *v4; // rcx
  char *v5; // rdi
  UFG::qBaseTreeRB *Next; // rax
  Render::SkinningCacheNode *v7; // rax
  UFG::AudioTriggerRegion *mChild; // rbx
  UFG::qBaseTreeRB *v9; // rax

  Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::AudioTriggerRegion::msAudioTriggerRegions);
  p_mCachedBufferPtr = (UFG::qBaseNodeRB *)&Head[-16].mCachedBufferPtr;
  if ( !Head )
    p_mCachedBufferPtr = 0i64;
  while ( p_mCachedBufferPtr )
  {
    mParent = p_mCachedBufferPtr[21].mParent;
    if ( mParent )
    {
      v3 = (char *)(&mParent[-1].mUID + 1);
      `eh vector destructor iterator(mParent, 4ui64, *(&mParent[-1].mUID + 1), (void (__fastcall *)(void *))_);
      operator delete[](v3);
    }
    p_mCachedBufferPtr[21].mParent = 0i64;
    *(_QWORD *)&p_mCachedBufferPtr[20].mUID = 0i64;
    v4 = *(char **)&p_mCachedBufferPtr[21].mUID;
    if ( v4 )
    {
      v5 = v4 - 4;
      `eh vector destructor iterator(v4, 4ui64, *((_DWORD *)v4 - 1), (void (__fastcall *)(void *))_);
      operator delete[](v5);
    }
    *(_QWORD *)&p_mCachedBufferPtr[21].mUID = 0i64;
    p_mCachedBufferPtr[21].mChild[1] = 0i64;
    Next = UFG::qBaseTreeRB::GetNext(&UFG::AudioTriggerRegion::msAudioTriggerRegions.mTree, p_mCachedBufferPtr + 19);
    if ( Next )
      p_mCachedBufferPtr = (UFG::qBaseNodeRB *)Next[-9].mNULL.mChild;
    else
      p_mCachedBufferPtr = 0i64;
  }
  v7 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::AudioTriggerRegion::msAudioTriggerRegions);
  mChild = (UFG::AudioTriggerRegion *)&v7[-16].mCachedBufferPtr;
  if ( !v7 )
LABEL_12:
    mChild = 0i64;
  while ( mChild )
  {
    UFG::AudioTriggerRegion::CheckRegionContainment(mChild, 1);
    v9 = UFG::qBaseTreeRB::GetNext(
           &UFG::AudioTriggerRegion::msAudioTriggerRegions.mTree,
           &mChild->UFG::qNodeRB<UFG::AudioTriggerRegion>::mNode);
    if ( !v9 )
      goto LABEL_12;
    mChild = (UFG::AudioTriggerRegion *)v9[-9].mNULL.mChild;
  }
  UFG::AudioTriggerRegion::sm_hierarchyIsDirty = 0;
}

// File Line: 1036
// RVA: 0x597750
char __fastcall UFG::AudioTriggerRegion::CheckContainmentForEntry(
        UFG::AudioTriggerRegion *this,
        UFG::RegionContainmentInfo *info,
        bool listener)
{
  unsigned int size; // ebp
  int v4; // edi
  __int64 i; // rsi
  UFG::qSymbol *p; // rbx
  unsigned int mUID; // edx
  UFG::qBaseTreeRB *v11; // rax
  UFG::qBaseNodeRB **mChild; // r8
  int v13; // eax
  char v14; // r10
  unsigned int v15; // edx
  unsigned int v16; // eax
  UFG::qSymbol *v17; // rcx

  size = this->m_regionsContainingMe.m_regionsContainedIn.size;
  v4 = 0;
  if ( !size )
    return 1;
  for ( i = 0i64; ; ++i )
  {
    p = this->m_regionsContainingMe.m_regionsContainedIn.p;
    mUID = p[i].mUID;
    if ( !mUID || (v11 = UFG::qBaseTreeRB::Get(&UFG::AudioTriggerRegion::msAudioTriggerRegions.mTree, mUID)) == 0i64 )
    {
      mChild = 0i64;
LABEL_12:
      v14 = 0;
      goto LABEL_13;
    }
    mChild = v11[-9].mNULL.mChild;
    if ( v11 == (UFG::qBaseTreeRB *)608 )
      goto LABEL_12;
    v13 = *((_DWORD *)mChild + 184);
    if ( (v13 & 1) == 0 && (v13 & 2) == 0 && (v13 & 4) == 0 && (v13 & 0x20) == 0 )
      goto LABEL_12;
    v14 = 1;
LABEL_13:
    v15 = info->m_regionsContainedIn.size;
    v16 = 0;
    if ( v15 )
    {
      v17 = info->m_regionsContainedIn.p;
      while ( p[i].mUID != v17->mUID )
      {
        ++v16;
        ++v17;
        if ( v16 >= v15 )
          goto LABEL_19;
      }
      if ( v16 != -1 )
        goto LABEL_22;
    }
LABEL_19:
    if ( mChild && (listener || v14) )
      break;
LABEL_22:
    if ( ++v4 >= size )
      return 1;
  }
  return 0;
}

// File Line: 1079
// RVA: 0x597850
char __fastcall UFG::AudioTriggerRegion::CheckContainmentForExit(
        UFG::AudioTriggerRegion *this,
        UFG::RegionContainmentInfo *info,
        bool listener)
{
  unsigned int size; // ebp
  int v8; // edi
  __int64 i; // rsi
  UFG::qSymbol *p; // rbx
  unsigned int mUID; // edx
  UFG::qBaseTreeRB *v12; // rax
  UFG::qBaseNodeRB **mChild; // rdx
  int v14; // eax
  char v15; // r10
  unsigned int v16; // r8d
  unsigned int v17; // eax
  UFG::qSymbol *v18; // rcx

  size = this->m_regionsIContain.m_regionsContainedIn.size;
  if ( !size )
    return 1;
  v8 = 0;
  for ( i = 0i64; ; ++i )
  {
    p = this->m_regionsIContain.m_regionsContainedIn.p;
    mUID = p[i].mUID;
    if ( !mUID || (v12 = UFG::qBaseTreeRB::Get(&UFG::AudioTriggerRegion::msAudioTriggerRegions.mTree, mUID)) == 0i64 )
    {
      mChild = 0i64;
LABEL_14:
      v15 = 0;
      goto LABEL_15;
    }
    mChild = v12[-9].mNULL.mChild;
    if ( v12 == (UFG::qBaseTreeRB *)608 )
      goto LABEL_14;
    v14 = *((_DWORD *)mChild + 184);
    if ( (v14 & 1) == 0 && (v14 & 2) == 0 && (v14 & 4) == 0 && (v14 & 0x20) == 0 )
      goto LABEL_14;
    v15 = 1;
LABEL_15:
    v16 = info->m_regionsContainedIn.size;
    v17 = 0;
    if ( v16 )
    {
      v18 = info->m_regionsContainedIn.p;
      while ( p[i].mUID != v18->mUID )
      {
        ++v17;
        ++v18;
        if ( v17 >= v16 )
          goto LABEL_24;
      }
      if ( v17 != -1 && mChild && (listener || v15) )
        break;
    }
LABEL_24:
    if ( ++v8 >= size )
      return 1;
  }
  return 0;
}

// File Line: 1243
// RVA: 0x5967B0
void __fastcall UFG::AudioTriggerRegion::ApplyAudioZoneListener(
        UFG::AudioTriggerRegion *this,
        UFG::AudioTriggerRegionEvent *thisEvent)
{
  UFG::AudioTriggerRegion *mRegionEntity; // rcx
  UFG::qBaseTreeRB *v5; // rax
  UFG::qWiseSymbol *p_mUID; // rcx
  UFG::qBaseTreeRB *v7; // rax
  unsigned int mUID; // ebx
  unsigned int v9; // edi
  UFG::TiDo *Instance; // rax
  UFG::TiDo *v11; // rax
  UFG::qSymbol result; // [rsp+48h] [rbp+10h] BYREF

  mRegionEntity = thisEvent->mRegionEntity;
  if ( mRegionEntity )
  {
    switch ( thisEvent->mAudioType )
    {
      case 1u:
        v5 = UFG::AudioEventPropertyManager::Find(thisEvent->mAudioUidOnEnter.mUID);
        if ( v5 )
        {
          p_mUID = (UFG::qWiseSymbol *)&v5->mNULL.mChild[0][2].mUID;
          if ( p_mUID->mUID != -1 )
            UFG::SoundBankManager::QueueBankForLoad(p_mUID);
        }
        v7 = UFG::AudioEventPropertyManager::Find(thisEvent->mAudioUidOnEnter.mUID);
        if ( v7 && LOBYTE(v7->mNULL.mChild[0][3].mChild[0]) )
          UFG::AudioTriggerRegion::HandleRefCountedEvent(this, thisEvent, 1);
        else
          UFG::AudioEntity::CreateAndPlayEvent(
            UFG::AmbienceAudio::m_instance,
            thisEvent->mAudioUidOnEnter.mUID,
            0i64,
            0,
            0i64);
        break;
      case 3u:
        UFG::AudioEntity::SetRtpcValue(
          &mRegionEntity->UFG::AudioEntity,
          thisEvent->mAudioUidOnEnter.mUID,
          thisEvent->mAudioRtpcVal);
        break;
      case 4u:
        goto $LN8_52;
      case 5u:
        UFG::AudioEntity::SetWwiseSwitch(
          &mRegionEntity->UFG::AudioEntity,
          thisEvent->mAudioUidOnEnter.mUID,
          thisEvent->mAudioModeUid.mUID);
        break;
      case 7u:
        UFG::TiDo::GetInstance();
        UFG::TiDo::LoadWwiseBank(&thisEvent->mAudioUidOnEnter);
        break;
      case 0xAu:
        UFG::TiDo::GetInstance();
        UFG::TiDo::UnloadWwiseBank(&thisEvent->mAudioUidOnEnter);
        break;
      case 0xBu:
        UFG::qWiseSymbol::operator=(&UFG::AudioTriggerRegion::msActiveMixUid, &thisEvent->mAudioUidOnEnter);
$LN8_52:
        mUID = thisEvent->mAudioUidOnEnter.mUID;
        v9 = thisEvent->mAudioModeUid.mUID;
        Instance = UFG::TiDo::GetInstance();
        UFG::AudioEntity::SetWwiseState(Instance, v9, mUID);
        break;
      case 0xCu:
        UFG::DoorStateManager::sm_doorRegionName.mUID = UFG::AudioEntity::GetName(
                                                          &mRegionEntity->UFG::AudioEntity,
                                                          &result)->mUID;
        UFG::qWiseSymbol::operator=(&UFG::DoorStateManager::sm_outdoorState, &thisEvent->mAudioUidOnExit);
        UFG::qWiseSymbol::operator=(&UFG::DoorStateManager::sm_indoorState, &thisEvent->mAudioUidOnEnter);
        UFG::DoorStateManager::OnEnterRegion();
        break;
      default:
        break;
    }
    v11 = UFG::TiDo::GetInstance();
    v11->vfptr->OnTriggerRegionEnter(v11, thisEvent);
  }
}

// File Line: 1377
// RVA: 0x5A9D20
void __fastcall UFG::AudioTriggerRegion::RemoveAudioZoneListener(
        UFG::AudioTriggerRegion *this,
        UFG::AudioTriggerRegionEvent *thisEvent)
{
  UFG::AudioTriggerRegion *mRegionEntity; // r9
  UFG::AudioEntity *v5; // r9
  UFG::qBaseTreeRB *v6; // rax
  UFG::qBaseTreeRB *v7; // rax
  UFG::qWiseSymbol *p_mUID; // rcx
  unsigned int mUID; // ebx
  unsigned int v10; // edi
  UFG::TiDo *Instance; // rax
  UFG::qWiseSymbol *null; // rax
  UFG::qWiseSymbol *v13; // rax
  UFG::TiDo *v14; // rax

  mRegionEntity = thisEvent->mRegionEntity;
  if ( mRegionEntity )
  {
    v5 = &mRegionEntity->UFG::AudioEntity;
    if ( v5 )
    {
      switch ( thisEvent->mAudioType )
      {
        case 1u:
          v6 = UFG::AudioEventPropertyManager::Find(thisEvent->mAudioUidOnExit.mUID);
          if ( v6 && LOBYTE(v6->mNULL.mChild[0][3].mChild[0]) )
            UFG::AudioTriggerRegion::HandleRefCountedEvent(this, thisEvent, 0);
          else
            UFG::AudioEntity::CreateAndPlayEvent(
              UFG::AmbienceAudio::m_instance,
              thisEvent->mAudioUidOnExit.mUID,
              0i64,
              0,
              0i64);
          v7 = UFG::AudioEventPropertyManager::Find(thisEvent->mAudioUidOnEnter.mUID);
          if ( v7 )
          {
            p_mUID = (UFG::qWiseSymbol *)&v7->mNULL.mChild[0][2].mUID;
            if ( p_mUID->mUID != -1 )
              UFG::SoundBankManager::QueueBankForUnload(p_mUID);
          }
          break;
        case 3u:
          UFG::AudioEntity::SetRtpcValue(v5, thisEvent->mAudioUidOnExit.mUID, thisEvent->mAudioRtpcVal);
          break;
        case 4u:
          mUID = thisEvent->mAudioUidOnExit.mUID;
          v10 = thisEvent->mAudioModeUid.mUID;
          Instance = UFG::TiDo::GetInstance();
          UFG::AudioEntity::SetWwiseState(Instance, v10, mUID);
          break;
        case 5u:
          UFG::AudioEntity::SetWwiseSwitch(v5, thisEvent->mAudioUidOnExit.mUID, thisEvent->mAudioModeUid.mUID);
          break;
        case 7u:
          UFG::TiDo::GetInstance();
          UFG::TiDo::UnloadWwiseBank(&thisEvent->mAudioUidOnExit);
          break;
        case 0xAu:
          UFG::TiDo::GetInstance();
          UFG::TiDo::LoadWwiseBank(&thisEvent->mAudioUidOnExit);
          break;
        case 0xBu:
          UFG::AudioTriggerRegion::HandleMixRegionExit(this);
          break;
        case 0xCu:
          UFG::DoorStateManager::sm_doorRegionName.mUID = UFG::gNullQSymbol.mUID;
          null = UFG::qWiseSymbol::get_null();
          UFG::qWiseSymbol::operator=(&UFG::DoorStateManager::sm_outdoorState, null);
          v13 = UFG::qWiseSymbol::get_null();
          UFG::qWiseSymbol::operator=(&UFG::DoorStateManager::sm_indoorState, v13);
          UFG::DoorStateManager::OnExitRegion();
          break;
        default:
          break;
      }
      v14 = UFG::TiDo::GetInstance();
      v14->vfptr->OnTriggerRegionExit(v14, thisEvent);
    }
  }
}

// File Line: 1514
// RVA: 0x59EC10
void __fastcall UFG::AudioTriggerRegion::HandleRefCountedEvent(
        UFG::AudioTriggerRegion *this,
        UFG::AudioTriggerRegionEvent *thisEvent,
        bool enter)
{
  UFG::qWiseSymbol *p_mAudioUidOnEnter; // rdx
  unsigned int v6; // eax
  UFG::qBaseTreeRB *v7; // rax
  UFG::qBaseTreeRB *v8; // rdi
  char *v9; // rax
  int v10; // eax
  bool v11; // al
  char *v12; // rbx
  char *v13; // rax
  UFG::qWiseSymbol v14; // [rsp+60h] [rbp+18h] BYREF

  v14.mUID = -1;
  _((AMD_HD3D *)0xFFFFFFFFi64);
  p_mAudioUidOnEnter = &thisEvent->mAudioUidOnEnter;
  if ( !enter )
    p_mAudioUidOnEnter = &thisEvent->mAudioUidOnExit;
  UFG::qWiseSymbol::operator=(&v14, p_mAudioUidOnEnter);
  v6 = _S42;
  if ( (_S42 & 1) == 0 )
  {
    _S42 |= 1u;
    UFG::qWiseSymbol::create_from_string(&set_minimap_enter, "set_minimap_enter");
    atexit(UFG::AudioTriggerRegion::HandleRefCountedEvent_::_7_::_dynamic_atexit_destructor_for__set_minimap_enter__);
    v6 = _S42;
  }
  if ( (v6 & 2) == 0 )
  {
    _S42 = v6 | 2;
    UFG::qWiseSymbol::create_from_string(&set_minimap_exit, "set_minimap_exit");
    atexit(UFG::AudioTriggerRegion::HandleRefCountedEvent_::_7_::_dynamic_atexit_destructor_for__set_minimap_exit__);
    v6 = _S42;
  }
  if ( (v6 & 4) == 0 )
  {
    _S42 = v6 | 4;
    UFG::qWiseSymbol::create_from_string(&set_rain_override, "set_rain_override");
    atexit(UFG::AudioTriggerRegion::HandleRefCountedEvent_::_7_::_dynamic_atexit_destructor_for__set_rain_override__);
  }
  v7 = UFG::AudioEventPropertyManager::Find(v14.mUID);
  v8 = v7;
  if ( !enter )
  {
    if ( !--LODWORD(v7->mNULL.mParent) )
    {
      if ( UFG::TiDo::sm_ambiencesInfo )
      {
        v12 = UFG::qWiseSymbol::as_cstr_dbg((UFG::qWiseSymbol *)&v7->mNULL.mChild[0][2].mChild[1] + 1);
        v13 = UFG::qWiseSymbol::as_cstr_dbg(&v14);
        UFG::qPrintf("AudioTriggerRegion:: Triggering dynamic inverse event: %s %s\n", v13, v12);
      }
      UFG::AudioEntity::CreateAndPlayEvent(
        UFG::AmbienceAudio::m_instance,
        HIDWORD(v8->mNULL.mChild[0][2].mChild[1]),
        0i64,
        0,
        0i64);
    }
    if ( HIDWORD(v8->mNULL.mChild[0][2].mChild[1]) == set_minimap_exit.mUID
      && UFG::AudioTriggerRegion::sm_interiorTransitionCount > 0 )
    {
      --UFG::AudioTriggerRegion::sm_interiorTransitionCount;
      UFG::DoorStateManager::HandleInOutTransition();
    }
    if ( HIDWORD(v8->mNULL.mChild[0][2].mChild[1]) == set_rain_override.mUID
      && UFG::AudioTriggerRegion::sm_rainDrawOverride > 0 )
    {
      --UFG::AudioTriggerRegion::sm_rainDrawOverride;
      UFG::DoorStateManager::HandleInOutTransition();
    }
    goto LABEL_40;
  }
  if ( !LODWORD(v7->mNULL.mParent) )
  {
    if ( UFG::TiDo::sm_ambiencesInfo )
    {
      v9 = UFG::qWiseSymbol::as_cstr_dbg(&v14);
      UFG::qPrintf("AudioTriggerRegion:: Triggering dynamic event: %s\n", v9);
    }
    UFG::AudioEntity::CreateAndPlayEvent(UFG::AmbienceAudio::m_instance, v14.mUID, 0i64, 0, 0i64);
  }
  ++LODWORD(v8->mNULL.mParent);
  if ( v14.mUID == set_minimap_enter.mUID )
  {
    v10 = ++UFG::AudioTriggerRegion::sm_interiorTransitionCount;
    if ( UFG::DoorStateManager::sm_active )
    {
      v11 = v10 > 0;
      if ( UFG::DoorStateManager::sm_inside )
      {
        UFG::DoorStateManager::sm_inside = 0;
        if ( !v11 )
          goto LABEL_21;
      }
      else if ( v11 )
      {
        UFG::DoorStateManager::sm_inside = 1;
LABEL_21:
        UFG::DoorStateManager::SetDoorMix();
        goto LABEL_22;
      }
      UFG::DoorStateManager::sm_inside = v11;
      goto LABEL_21;
    }
  }
LABEL_22:
  if ( v14.mUID == set_rain_override.mUID )
  {
    ++UFG::AudioTriggerRegion::sm_rainDrawOverride;
    if ( UFG::DoorStateManager::sm_active )
    {
      if ( UFG::DoorStateManager::sm_inside )
      {
        if ( UFG::AudioTriggerRegion::sm_interiorTransitionCount <= 0 )
        {
          UFG::DoorStateManager::sm_inside = 0;
          UFG::DoorStateManager::SetDoorMix();
          goto LABEL_40;
        }
      }
      else if ( UFG::AudioTriggerRegion::sm_interiorTransitionCount > 0 )
      {
        UFG::DoorStateManager::sm_inside = 1;
        UFG::DoorStateManager::SetDoorMix();
        goto LABEL_40;
      }
      UFG::DoorStateManager::sm_inside = UFG::AudioTriggerRegion::sm_interiorTransitionCount > 0;
      UFG::DoorStateManager::SetDoorMix();
    }
  }
LABEL_40:
  _((AMD_HD3D *)v14.mUID);
}

// File Line: 1617
// RVA: 0x59EAC0
char __fastcall UFG::AudioTriggerRegion::HandleMixRegionExit(UFG::AudioTriggerRegion *this)
{
  UFG::AudioTriggerRegion *InnermostRegionOfTypeContainingObject; // rbx
  unsigned int v3; // edx
  UFG::AudioTriggerRegionTag *p_mNext; // r9
  UFG::TiDo *Instance; // rax
  UFG::AudioTriggerRegionEvent thisEvent; // [rsp+28h] [rbp-40h] BYREF

  InnermostRegionOfTypeContainingObject = (UFG::AudioTriggerRegion *)UFG::AudioTriggerRegion::FindInnermostRegionOfTypeContainingObject(
                                                                       this,
                                                                       &UFG::AudioListener::sm_pInstance->m_containmentInfo,
                                                                       eAudioTriggerRegionType_Mix);
  v3 = _S43_0;
  if ( (_S43_0 & 1) == 0 )
  {
    _S43_0 |= 1u;
    UFG::qWiseSymbol::create_from_string(&ms_location, "ms_location");
    atexit(UFG::AudioTriggerRegion::HandleMixRegionExit_::_2_::_dynamic_atexit_destructor_for__ms_location__);
    v3 = _S43_0;
  }
  if ( !InnermostRegionOfTypeContainingObject
    || (p_mNext = (UFG::AudioTriggerRegionTag *)&InnermostRegionOfTypeContainingObject->mTags.mNode.mNext[-1].mNext,
        p_mNext == (UFG::AudioTriggerRegionTag *)&InnermostRegionOfTypeContainingObject->UFG::qNodeRB<UFG::AudioTriggerRegion>::mNode.mUID) )
  {
LABEL_10:
    if ( (v3 & 2) == 0 )
    {
      _S43_0 = v3 | 2;
      UFG::qWiseSymbol::create_from_string(&gbl_exterior, "gbl_exterior");
      atexit(UFG::AudioTriggerRegion::HandleMixRegionExit_::_10_::_dynamic_atexit_destructor_for__gbl_exterior__);
    }
    Instance = UFG::TiDo::GetInstance();
    UFG::AudioEntity::SetWwiseState(Instance, ms_location.mUID, gbl_exterior.mUID);
    return 0;
  }
  else
  {
    while ( p_mNext->mAudioType != 11 || p_mNext->mAudioModeUidOnEnter.mUID != ms_location.mUID )
    {
      p_mNext = (UFG::AudioTriggerRegionTag *)&p_mNext->mNext[-1].mNext;
      if ( p_mNext == (UFG::AudioTriggerRegionTag *)&InnermostRegionOfTypeContainingObject->UFG::qNodeRB<UFG::AudioTriggerRegion>::mNode.mUID )
        goto LABEL_10;
    }
    UFG::AudioTriggerRegionEvent::AudioTriggerRegionEvent(
      &thisEvent,
      0i64,
      InnermostRegionOfTypeContainingObject,
      p_mNext);
    UFG::AudioTriggerRegion::ApplyAudioZoneListener(this, &thisEvent);
    thisEvent.vfptr = (UFG::AudioTriggerRegionEventVtbl *)&UFG::AudioTriggerRegionEvent::`vftable;
    _((AMD_HD3D *)thisEvent.mAudioModeUid.mUID);
    _((AMD_HD3D *)thisEvent.mAudioUidOnExit.mUID);
    _((AMD_HD3D *)thisEvent.mAudioUidOnEnter.mUID);
    return 1;
  }
}

// File Line: 1649
// RVA: 0x59E6D0
void __fastcall UFG::AudioTriggerRegion::HandleEnvironmentRegionExit(
        UFG::AudioTriggerRegion *this,
        UFG::AudioTriggerRegionEvent *thisEvent)
{
  UFG::AudioEntity *mTriggeringEntity; // rsi
  float v5; // xmm8_4
  float v6; // xmm6_4
  UFG::RegionContainmentInfo *ContainmentInfo; // rax
  UFG::qBaseNodeRB **InnermostRegionOfTypeContainingObject; // rax
  UFG::qBaseNodeRB **v9; // rbp
  __int64 p_mUID; // rbx
  UFG::qSymbolUC *Name; // rax
  char *v12; // rax
  char *v13; // rbx
  UFG::qSymbolUC *v14; // rax
  char *v15; // rax
  UFG::qSymbol result; // [rsp+68h] [rbp+10h] BYREF

  mTriggeringEntity = thisEvent->mTriggeringEntity;
  v5 = 0.0;
  v6 = 0.0;
  ContainmentInfo = UFG::AudioEntity::GetContainmentInfo(mTriggeringEntity);
  InnermostRegionOfTypeContainingObject = UFG::AudioTriggerRegion::FindInnermostRegionOfTypeContainingObject(
                                            this,
                                            ContainmentInfo,
                                            eAudioTriggerRegionType_Environment);
  if ( InnermostRegionOfTypeContainingObject )
  {
    v9 = InnermostRegionOfTypeContainingObject + 79;
    p_mUID = (__int64)&InnermostRegionOfTypeContainingObject[81][-1].mUID;
    if ( (UFG::qBaseNodeRB **)p_mUID != InnermostRegionOfTypeContainingObject + 79 )
    {
      do
      {
        if ( *(_DWORD *)(p_mUID + 24) == 8 && thisEvent->mAudioUidOnEnter.mUID == *(_DWORD *)(p_mUID + 28) )
        {
          v6 = *(float *)(p_mUID + 48);
          v5 = *(float *)(p_mUID + 44);
          if ( v6 > 0.0 )
            UFG::AudioCategoryPropertyManager::SetAuxSendRtpcForEnvironment(
              (UFG::qWiseSymbol *)(p_mUID + 28),
              mTriggeringEntity);
        }
        p_mUID = *(_QWORD *)(p_mUID + 16) - 8i64;
      }
      while ( (UFG::qBaseNodeRB **)p_mUID != v9 );
    }
  }
  else
  {
    UFG::AudioCategoryPropertyManager::SetAuxSendRtpcForEnvironment(&default_symbol_0, mTriggeringEntity);
  }
  if ( UFG::AudioEntity::sm_displayEnvironmentInfo )
  {
    Name = (UFG::qSymbolUC *)UFG::AudioEntity::GetName(thisEvent->mTriggeringEntity, &result);
    v12 = UFG::qSymbol::as_cstr_dbg(Name);
    if ( strstr(v12, UFG::AudioEntity::sm_environmentInfoFilter.mData) )
    {
      v13 = UFG::qWiseSymbol::as_cstr_dbg(&thisEvent->mAudioUidOnEnter);
      v14 = (UFG::qSymbolUC *)UFG::AudioEntity::GetName(&thisEvent->mRegionEntity->UFG::AudioEntity, &result);
      v15 = UFG::qSymbol::as_cstr_dbg(v14);
      UFG::qPrintf("AudioTriggerRegion: Exiting: %s, Removing environment: %s\n", v15, v13);
    }
  }
  UFG::AudioEntity::RemoveEnvironment(mTriggeringEntity, thisEvent->mAudioUidOnEnter.mUID, v5, v6);
}

// File Line: 1697
// RVA: 0x59E550
void __fastcall UFG::AudioTriggerRegion::HandleEnvironmentRegionEnter(
        UFG::AudioTriggerRegion *this,
        UFG::AudioTriggerRegionEvent *thisEvent)
{
  UFG::AudioEntity *mTriggeringEntity; // rsi
  float v5; // xmm7_4
  float wetLevel; // xmm8_4
  UFG::RegionContainmentInfo *ContainmentInfo; // rax
  UFG::qBaseNodeRB **InnermostRegionOfTypeContainingObject; // rax
  UFG::qBaseNodeRB **v9; // rbp
  __int64 p_mUID; // rbx
  UFG::qSymbolUC *Name; // rax
  char *v12; // rax
  char *v13; // rbx
  UFG::qSymbolUC *v14; // rax
  char *v15; // rax
  UFG::qSymbol result; // [rsp+78h] [rbp+10h] BYREF

  mTriggeringEntity = thisEvent->mTriggeringEntity;
  v5 = 0.0;
  wetLevel = 0.0;
  ContainmentInfo = UFG::AudioEntity::GetContainmentInfo(mTriggeringEntity);
  InnermostRegionOfTypeContainingObject = UFG::AudioTriggerRegion::FindInnermostRegionOfTypeContainingObject(
                                            this,
                                            ContainmentInfo,
                                            eAudioTriggerRegionType_Environment);
  if ( InnermostRegionOfTypeContainingObject )
  {
    v9 = InnermostRegionOfTypeContainingObject + 79;
    p_mUID = (__int64)&InnermostRegionOfTypeContainingObject[81][-1].mUID;
    if ( (UFG::qBaseNodeRB **)p_mUID != InnermostRegionOfTypeContainingObject + 79 )
    {
      do
      {
        if ( *(_DWORD *)(p_mUID + 24) == 8 )
        {
          if ( thisEvent->mAudioUidOnEnter.mUID == *(_DWORD *)(p_mUID + 28) )
          {
            v5 = *(float *)(p_mUID + 44);
            wetLevel = *(float *)(p_mUID + 48);
          }
          if ( *(float *)(p_mUID + 48) > 0.0 )
            UFG::AudioCategoryPropertyManager::SetAuxSendRtpcForEnvironment(
              (UFG::qWiseSymbol *)(p_mUID + 28),
              mTriggeringEntity);
        }
        p_mUID = *(_QWORD *)(p_mUID + 16) - 8i64;
      }
      while ( (UFG::qBaseNodeRB **)p_mUID != v9 );
    }
  }
  else
  {
    UFG::AudioCategoryPropertyManager::SetAuxSendRtpcForEnvironment(&default_symbol_0, mTriggeringEntity);
  }
  if ( UFG::AudioEntity::sm_displayEnvironmentInfo )
  {
    Name = (UFG::qSymbolUC *)UFG::AudioEntity::GetName(thisEvent->mTriggeringEntity, &result);
    v12 = UFG::qSymbol::as_cstr_dbg(Name);
    if ( strstr(v12, UFG::AudioEntity::sm_environmentInfoFilter.mData) )
    {
      v13 = UFG::qWiseSymbol::as_cstr_dbg(&thisEvent->mAudioUidOnEnter);
      v14 = (UFG::qSymbolUC *)UFG::AudioEntity::GetName(&thisEvent->mRegionEntity->UFG::AudioEntity, &result);
      v15 = UFG::qSymbol::as_cstr_dbg(v14);
      UFG::qPrintf("AudioTriggerRegion: Entering: %s, Adding environment: %s\n", v15, v13);
    }
  }
  UFG::AudioEntity::ApplyEnvironment(
    mTriggeringEntity,
    thisEvent->mAudioUidOnEnter.mUID,
    1.0,
    v5,
    wetLevel,
    &thisEvent->mAudioModeUid);
}

// File Line: 1815
// RVA: 0x598520
UFG::qSymbol *__fastcall UFG::AudioTriggerRegion::CheckRegionForDoors(
        UFG::qSymbol *result,
        UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *doorTree)
{
  unsigned int mUID; // ebx
  Render::SkinningCacheNode *Head; // rax
  UFG::TriggerRegion *p_mCachedBufferPtr; // rsi
  UFG::qBaseNodeRB *v7; // rdx
  UFG::qBaseTreeRB *Next; // rax
  __int64 v9; // rbp
  UFG::qBaseTreeRB *v10; // rdi

  mUID = UFG::gNullQSymbol.mUID;
  Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::AudioTriggerRegion::msAudioTriggerRegions);
  if ( !Head
    || (p_mCachedBufferPtr = (UFG::TriggerRegion *)&Head[-16].mCachedBufferPtr, Head == (Render::SkinningCacheNode *)608) )
  {
LABEL_15:
    result->mUID = mUID;
  }
  else
  {
    while ( 1 )
    {
      v7 = p_mCachedBufferPtr ? (UFG::qBaseNodeRB *)&p_mCachedBufferPtr[2].m_Flags : 0i64;
      Next = UFG::qBaseTreeRB::GetNext(&UFG::AudioTriggerRegion::msAudioTriggerRegions.mTree, v7);
      v9 = Next ? (__int64)Next[-9].mNULL.mChild : 0i64;
      if ( ((__int64)p_mCachedBufferPtr[2].UFG::qNode<UFG::TriggerRegion,CullInfo>::mPrev & 0x20) != 0 )
      {
        v10 = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(doorTree);
        if ( v10 )
          break;
      }
LABEL_14:
      p_mCachedBufferPtr = (UFG::TriggerRegion *)v9;
      if ( !v9 )
        goto LABEL_15;
    }
    while ( !UFG::TriggerRegion::IsHitPoint(p_mCachedBufferPtr, (UFG::qVector3 *)((char *)&v10->mNULL.mParent + 4))
         || mUID != UFG::gNullQSymbol.mUID )
    {
      v10 = UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)doorTree, &v10->mRoot);
      if ( !v10 )
        goto LABEL_14;
    }
    result->mUID = (unsigned int)v10->mNULL.mParent;
  }
  return result;
}

// File Line: 1848
// RVA: 0x592EA0
void __fastcall UFG::AudioTriggerRegionEvent::AudioTriggerRegionEvent(
        UFG::AudioTriggerRegionEvent *this,
        UFG::AudioEntity *triggeringEntity,
        UFG::AudioTriggerRegion *regionEntity,
        UFG::AudioTriggerRegionTag *tag)
{
  this->vfptr = (UFG::AudioTriggerRegionEventVtbl *)&UFG::AudioTriggerRegionEvent::`vftable;
  this->mAudioUidOnEnter.mUID = -1;
  _((AMD_HD3D *)0xFFFFFFFFi64);
  this->mAudioUidOnExit.mUID = -1;
  _((AMD_HD3D *)0xFFFFFFFFi64);
  this->mAudioModeUid.mUID = -1;
  _((AMD_HD3D *)0xFFFFFFFFi64);
  this->mTriggeringEntity = triggeringEntity;
  this->mRegionEntity = regionEntity;
  this->mAudioType = tag->mAudioType;
  UFG::qWiseSymbol::operator=(&this->mAudioUidOnEnter, &tag->mAudioUidOnEnter);
  UFG::qWiseSymbol::operator=(&this->mAudioUidOnExit, &tag->mAudioUidOnExit);
  UFG::qWiseSymbol::operator=(&this->mAudioModeUid, &tag->mAudioModeUidOnEnter);
  this->mAudioRtpcVal = tag->mAudioRtpcValOnEnter;
  this->mAudioDryLevel = tag->mAudioDryLevelOnEnter;
  this->mAudioWetLevel = tag->mAudioWetLevelOnEnter;
}

