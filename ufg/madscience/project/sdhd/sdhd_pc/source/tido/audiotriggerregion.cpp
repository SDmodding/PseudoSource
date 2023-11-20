// File Line: 77
// RVA: 0x1554910
__int64 dynamic_initializer_for__UFG::AudioTriggerRegion::msActiveMixUid__()
{
  UFG::AudioTriggerRegion::msActiveMixUid.mUID = UFG::qWiseSymbol::get_null()->mUID;
  _((AMD_HD3D *)UFG::AudioTriggerRegion::msActiveMixUid.mUID);
  return atexit(dynamic_atexit_destructor_for__UFG::AudioTriggerRegion::msActiveMixUid__);
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
  return atexit(dynamic_atexit_destructor_for__UFG::AudioTriggerRegion::msAudioTriggerRegions__);
}

// File Line: 106
// RVA: 0x1559B10
__int64 UFG::_dynamic_initializer_for__default_symbol__()
{
  default_symbol_0.mUID = UFG::qWiseSymbolUIDFromString("default", 0x811C9DC5);
  _((AMD_HD3D *)default_symbol_0.mUID);
  return atexit(UFG::_dynamic_atexit_destructor_for__default_symbol__);
}

// File Line: 118
// RVA: 0x592DA0
void __fastcall UFG::AudioTriggerRegion::AudioTriggerRegion(UFG::AudioTriggerRegion *this, UFG::qSymbol *name, UFG::SimObject *pSimObj)
{
  UFG::SimObject *v3; // rdi
  UFG::qSymbol *v4; // rsi
  UFG::AudioTriggerRegion *v5; // r14
  unsigned int v6; // eax
  UFG::qList<UFG::AudioTriggerRegionTag,UFG::AudioTriggerRegionTag,1,0> *v7; // [rsp+58h] [rbp+10h]

  v3 = pSimObj;
  v4 = name;
  v5 = this;
  UFG::TriggerRegion::TriggerRegion((UFG::TriggerRegion *)&this->vfptr, name, pSimObj, 0);
  UFG::AudioEntity::AudioEntity((UFG::AudioEntity *)&v5->vfptr);
  v6 = v4->mUID;
  v5->mNode.mParent = 0i64;
  v5->mNode.mChild[0] = 0i64;
  v5->mNode.mChild[1] = 0i64;
  v5->mNode.mUID = v6;
  v5->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AudioTriggerRegion::`vftable{for `UFG::TriggerRegion};
  v5->vfptr = (UFG::AudioEntityVtbl *)&UFG::AudioTriggerRegion::`vftable{for `UFG::AudioEntity};
  v7 = &v5->mTags;
  v7->mNode.mPrev = &v7->mNode;
  v7->mNode.mNext = &v7->mNode;
  UFG::RegionContainmentInfo::RegionContainmentInfo(&v5->m_regionsContainingMe);
  UFG::RegionContainmentInfo::RegionContainmentInfo(&v5->m_regionsIContain);
  UFG::RegionContainmentInfo::RegionContainmentInfo(&v5->m_thingsIContain);
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v5->vfptr,
    UFG::AudioTriggerRegion::_AudioTriggerRegionTypeUID,
    "AudioTriggerRegion");
  UFG::AudioTriggerRegion::InitTrigger(v5, v3);
  v5->m_name = (UFG::qSymbol)v4->mUID;
  v5->m_bEnableEnvironments = 0;
  UFG::AudioTriggerRegion::sm_hierarchyIsDirty = 1;
}

// File Line: 141
// RVA: 0x593EB0
void __fastcall UFG::AudioTriggerRegion::~AudioTriggerRegion(UFG::AudioTriggerRegion *this)
{
  UFG::AudioTriggerRegion *v1; // rdi
  UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *v2; // rsi
  unsigned int *v3; // rax
  unsigned int *v4; // rbx
  _QWORD *v5; // rdx
  __int64 v6; // rcx
  _QWORD *v7; // rax
  UFG::qSymbol *v8; // rcx
  UFG::qSymbol *v9; // rbx
  UFG::qSymbol *v10; // rcx
  UFG::qSymbol *v11; // rbx
  UFG::qSymbol *v12; // rcx
  UFG::qSymbol *v13; // rbx
  int v14; // edx
  hkGeometryUtils::IVertices *v15; // rcx
  int v16; // er8
  UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> *v17; // rdx
  UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> *v18; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AudioTriggerRegion::`vftable{for `UFG::TriggerRegion};
  this->vfptr = (UFG::AudioEntityVtbl *)&UFG::AudioTriggerRegion::`vftable{for `UFG::AudioEntity};
  v2 = (UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)&this->mTags;
  v3 = (unsigned int *)&this->mTags.mNode.mNext[-1].mNext;
  v4 = &this->mNode.mUID;
  if ( v3 != &this->mNode.mUID )
  {
    do
    {
      v5 = v3 + 2;
      v6 = *((_QWORD *)v3 + 1);
      v7 = (_QWORD *)*((_QWORD *)v3 + 2);
      *(_QWORD *)(v6 + 8) = v7;
      *v7 = v6;
      *v5 = v5;
      v5[1] = v5;
      if ( v5 != (_QWORD *)8 )
        (*(void (__fastcall **)(_QWORD *, signed __int64))*(v5 - 1))(v5 - 1, 1i64);
      v3 = (unsigned int *)&v2->mNode.mNext[-1].mNext;
    }
    while ( v3 != v4 );
  }
  v8 = v1->m_regionsContainingMe.m_regionsContainedIn.p;
  if ( v8 )
  {
    v9 = v8 - 1;
    `eh vector destructor iterator(v8, 4ui64, v8[-1].mUID, (void (__fastcall *)(void *))_);
    operator delete[](v9);
  }
  v1->m_regionsContainingMe.m_regionsContainedIn.p = 0i64;
  *(_QWORD *)&v1->m_regionsContainingMe.m_regionsContainedIn.size = 0i64;
  v10 = v1->m_regionsIContain.m_regionsContainedIn.p;
  if ( v10 )
  {
    v11 = v10 - 1;
    `eh vector destructor iterator(v10, 4ui64, v10[-1].mUID, (void (__fastcall *)(void *))_);
    operator delete[](v11);
  }
  v1->m_regionsIContain.m_regionsContainedIn.p = 0i64;
  *(_QWORD *)&v1->m_regionsIContain.m_regionsContainedIn.size = 0i64;
  v12 = v1->m_thingsIContain.m_regionsContainedIn.p;
  if ( v12 )
  {
    v13 = v12 - 1;
    `eh vector destructor iterator(v12, 4ui64, v12[-1].mUID, (void (__fastcall *)(void *))_);
    operator delete[](v13);
  }
  v1->m_thingsIContain.m_regionsContainedIn.p = 0i64;
  *(_QWORD *)&v1->m_thingsIContain.m_regionsContainedIn.size = 0i64;
  UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
    (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::AudioTriggerRegion::msAudioTriggerRegions,
    (UFG::qBaseNodeVariableRB<unsigned __int64> *)&v1->mNode);
  UFG::AudioTriggerRegion::sm_hierarchyIsDirty = 1;
  if ( Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(v15, v14, v16) )
    UFG::AudioEntity::Shutdown((UFG::AudioEntity *)&v1->vfptr);
  UFG::RegionContainmentInfo::~RegionContainmentInfo(&v1->m_thingsIContain);
  UFG::RegionContainmentInfo::~RegionContainmentInfo(&v1->m_regionsIContain);
  UFG::RegionContainmentInfo::~RegionContainmentInfo(&v1->m_regionsContainingMe);
  UFG::qList<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption,1,0>::DeleteNodes(v2);
  v17 = v2->mNode.mPrev;
  v18 = v2->mNode.mNext;
  v17->mNext = v18;
  v18->mPrev = v17;
  v2->mNode.mPrev = &v2->mNode;
  v2->mNode.mNext = &v2->mNode;
  UFG::AudioEntity::~AudioEntity((UFG::AudioEntity *)&v1->vfptr);
  UFG::TriggerRegion::~TriggerRegion((UFG::TriggerRegion *)&v1->vfptr);
}

// File Line: 164
// RVA: 0x5A3A60
void __fastcall UFG::AudioTriggerRegion::OnDetach(UFG::AudioTriggerRegion *this)
{
  UFG::AudioTriggerRegion *v1; // rbx
  UFG::AudioListener *v2; // r8
  signed int v3; // edx
  unsigned int v4; // ecx
  hkGeometryUtils::IVertices *v5; // rcx
  unsigned int v6; // edx
  UFG::qSymbol *v7; // r9
  unsigned int v8; // eax
  char *v9; // rax
  UFG::AudioTriggerRegionTag *i; // rdi
  unsigned int v11; // eax
  __int64 v12; // rsi
  __int64 v13; // rbp
  UFG::AudioEntity *v14; // rax
  UFG::AudioEntity *v15; // rdi
  UFG::RegionContainmentInfo *v16; // rax
  UFG::RegionContainmentInfo *v17; // r10
  __int64 v18; // rdx
  unsigned int v19; // eax
  UFG::qSymbol *v20; // r8
  unsigned int v21; // eax
  UFG::AudioTriggerRegionEvent thisEvent; // [rsp+28h] [rbp-40h]

  v1 = this;
  v2 = UFG::AudioListener::sm_pInstance;
  if ( UFG::AudioListener::sm_pInstance )
  {
    v3 = 0;
    v4 = UFG::AudioListener::sm_pInstance->m_containmentInfo.m_regionsContainedIn.size;
    if ( v4 )
    {
      while ( v1->i_name.mUID != UFG::AudioListener::sm_pInstance->m_containmentInfo.m_regionsContainedIn.p[v3].mUID )
      {
        if ( ++v3 >= v4 )
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
        v7 = UFG::AudioListener::sm_pInstance->m_containmentInfo.m_regionsContainedIn.p;
        while ( v1->i_name.mUID != v7[(_QWORD)v5].mUID )
        {
          v5 = (hkGeometryUtils::IVertices *)(unsigned int)((_DWORD)v5 + 1);
          if ( (unsigned int)v5 >= v6 )
            goto LABEL_16;
        }
        if ( (_DWORD)v5 != -1 )
        {
          v7[(_QWORD)v5] = v7[v6 - 1];
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
        v9 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v1->i_name);
        UFG::qPrintf("AudioTriggerRegion:: Lst Exit :: %s\n", v9);
      }
      for ( i = (UFG::AudioTriggerRegionTag *)&v1->mTags.mNode.mNext[-1].mNext;
            i != (UFG::AudioTriggerRegionTag *)&v1->mNode.mUID;
            i = (UFG::AudioTriggerRegionTag *)&i->mNext[-1].mNext )
      {
        UFG::AudioTriggerRegionEvent::AudioTriggerRegionEvent(&thisEvent, 0i64, v1, i);
        UFG::AudioTriggerRegion::RemoveAudioZoneListener(v1, &thisEvent);
        thisEvent.vfptr = (UFG::AudioTriggerRegionEventVtbl *)&UFG::AudioTriggerRegionEvent::`vftable;
        _((AMD_HD3D *)thisEvent.mAudioModeUid.mUID);
        _((AMD_HD3D *)thisEvent.mAudioUidOnExit.mUID);
        _((AMD_HD3D *)thisEvent.mAudioUidOnEnter.mUID);
      }
      if ( Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(v5, v6, (int)v2) )
        UFG::AudioEntity::Shutdown((UFG::AudioEntity *)&v1->vfptr);
    }
  }
  v11 = v1->m_thingsIContain.m_regionsContainedIn.size;
  if ( v11 )
  {
    v12 = 0i64;
    v13 = v11;
    do
    {
      v14 = (UFG::AudioEntity *)UFG::TiDo::GetEntity(&v1->m_thingsIContain.m_regionsContainedIn.p[v12]);
      v15 = v14;
      if ( v14 )
      {
        UFG::AudioTriggerRegion::OnExited(v1, v14, 0);
        v16 = UFG::AudioEntity::GetContainmentInfo(v15);
        v17 = v16;
        v18 = 0i64;
        v19 = v16->m_regionsContainedIn.size;
        if ( v19 )
        {
          v20 = v17->m_regionsContainedIn.p;
          while ( v1->i_name.mUID != v20[v18].mUID )
          {
            v18 = (unsigned int)(v18 + 1);
            if ( (unsigned int)v18 >= v19 )
              goto LABEL_34;
          }
          if ( (_DWORD)v18 != -1 )
          {
            v20[v18] = v20[v19 - 1];
            v21 = v17->m_regionsContainedIn.size;
            if ( v21 > 1 )
              v17->m_regionsContainedIn.size = v21 - 1;
            else
              v17->m_regionsContainedIn.size = 0;
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
void __fastcall UFG::AudioTriggerRegion::InitTrigger(UFG::AudioTriggerRegion *this, UFG::SimObject *pSimObj)
{
  UFG::SimObject *v2; // rax
  UFG::AudioTriggerRegion *v3; // rbx
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *v4; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qList<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList,1,0> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rax

  v2 = pSimObj;
  v3 = this;
  if ( pSimObj )
    v2 = (UFG::SimObject *)UFG::SimObject::GetComponentOfType(pSimObj, UFG::RegionComponent::_TypeUID);
  v4 = &v3->mpRegion;
  if ( v3->mpRegion.m_pPointer )
  {
    v5 = v4->mPrev;
    v6 = v3->mpRegion.mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
    v3->mpRegion.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mpRegion.mPrev;
  }
  v3->mpRegion.m_pPointer = (UFG::SimComponent *)v2;
  if ( v2 )
  {
    v7 = &v2->m_SafePointerList;
    v8 = v2->m_SafePointerList.mNode.mPrev;
    v8->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)v4;
    v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v8;
    v3->mpRegion.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v7;
    v7->mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)v4;
  }
  *(_QWORD *)&v3->m_occValue = 0i64;
  v3->m_obsValue = 0.0;
  UFG::qBaseTreeRB::Add(&UFG::AudioTriggerRegion::msAudioTriggerRegions.mTree, &v3->mNode);
}

// File Line: 226
// RVA: 0x59F520
bool __fastcall UFG::AudioTriggerRegion::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SceneObjectProperties *v1; // rax
  UFG::qPropertySet *v2; // rcx

  v1 = pSceneObj;
  v2 = pSceneObj->mpWritableProperties;
  if ( !v2 )
    v2 = v1->mpConstProperties;
  return UFG::qPropertySet::GetParentFromName(
           v2,
           (UFG::qSymbol *)&TiDoSymX_propset_componentATRegion.mUID,
           DEPTH_RECURSE) != 0i64;
}

// File Line: 236
// RVA: 0x5A8520
UFG::AudioTriggerRegion *__fastcall UFG::AudioTriggerRegion::PropertiesOnActivate(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SceneObjectProperties *v1; // rsi
  UFG::allocator::free_link *v2; // rbp
  UFG::SimObject *v3; // rbx
  UFG::qSymbol *v4; // rax
  __int64 v5; // rax
  __int64 v6; // rbx
  UFG::qPropertySet *v7; // rcx
  bool *v8; // rax
  UFG::qPropertySet *v9; // rcx
  UFG::qPropertyList *v10; // r14
  unsigned int v11; // ebp
  unsigned int v12; // edi
  UFG::qWiseSymbol **v13; // rsi
  char *v14; // rax
  UFG::qPropertySet *v15; // rcx
  UFG::qWiseSymbol *v16; // rax
  UFG::qWiseSymbol *v17; // rcx
  UFG::qWiseSymbol *v18; // rax
  UFG::qSymbol result; // [rsp+68h] [rbp+10h]
  UFG::allocator::free_link *v21; // [rsp+70h] [rbp+18h]

  v1 = pSceneObj;
  v2 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0x2F0ui64, "AudioTriggerRegion", 0i64, 1u);
  v21 = v2;
  if ( v2 )
  {
    v3 = v1->m_pSimObject;
    v4 = UFG::SceneObjectProperties::operator UFG::qSymbol const(v1, &result);
    UFG::AudioTriggerRegion::AudioTriggerRegion((UFG::AudioTriggerRegion *)v2, v4, v3);
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
    v8 = UFG::qPropertySet::Get<bool>(v7, (UFG::qSymbol *)&TiDoSym_ControlEmitters.mUID, DEPTH_RECURSE);
    if ( v8 && *v8 )
      *(_DWORD *)(v6 + 736) |= 8u;
    v9 = v1->mpWritableProperties;
    if ( !v9 )
      v9 = v1->mpConstProperties;
    v10 = UFG::qPropertySet::Get<UFG::qPropertyList>(v9, (UFG::qSymbol *)&TiDoSym_TagList.mUID, DEPTH_RECURSE);
    v11 = v10->mNumElements;
    v12 = 0;
    if ( v11 )
    {
      v13 = (UFG::qWiseSymbol **)(v6 + 640);
      do
      {
        v14 = UFG::qPropertyList::GetValuePtr(v10, 0x1Au, v12);
        if ( v14 && *(_QWORD *)v14 )
          v15 = (UFG::qPropertySet *)&v14[*(_QWORD *)v14];
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
      while ( v12 < v11 );
    }
    UFG::AudioTriggerRegion::CheckRegionContainment((UFG::AudioTriggerRegion *)v6, 0);
  }
  return (UFG::AudioTriggerRegion *)v6;
}

// File Line: 397
// RVA: 0x596F70
void __fastcall UFG::AudioTriggerRegion::AudioEntityUpdate(UFG::AudioTriggerRegion *this, float delta_sec)
{
  UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> *v2; // rbx
  UFG::AudioTriggerRegion *v3; // rdi
  float v4; // xmm6_4
  UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> v5; // xmm1
  UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> v6; // xmm3
  UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> v7; // xmm2

  v2 = this[-1].m_events.mNode.mPrev;
  v3 = this;
  v4 = delta_sec;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this[-1].m_events.mNode.mPrev);
  v5 = v2[11];
  v6 = (UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0>)v2[9];
  v7 = v2[10];
  *(UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> *)&v3->m_Flags = v2[8];
  v3->m_BoundComponentHandles = v6;
  *(UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> *)&v3->i_name.mUID = v7;
  *(UFG::qNode<UFG::AudioEvent,UFG::AudioEvent> *)v3->mNode.mChild = v5;
  UFG::AudioEntity::AudioEntityUpdate((UFG::AudioEntity *)v3, v4);
}

// File Line: 411
// RVA: 0x5A3D70
void __fastcall UFG::AudioTriggerRegion::OnEntered(UFG::AudioTriggerRegion *this, UFG::AudioEntity *pTriggeringEntity, int listener)
{
  char v3; // r15
  UFG::AudioEntity *v4; // rbp
  UFG::AudioTriggerRegion *v5; // rsi
  char *v6; // rax
  signed __int64 i; // rbx
  UFG::AudioEntity *v8; // rdi
  unsigned int v9; // eax
  UFG::AudioTriggerRegionEvent thisEvent; // [rsp+28h] [rbp-60h]
  bool global; // [rsp+90h] [rbp+8h]

  v3 = listener;
  v4 = pTriggeringEntity;
  v5 = this;
  if ( Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(
         (hkGeometryUtils::IVertices *)this,
         (int)pTriggeringEntity,
         listener)
    && v3 )
  {
    UFG::AudioEntity::Init((UFG::AudioEntity *)&v5->vfptr, &v5->m_pSimObject->m_Name, &UFG::qMatrix44::msIdentity);
  }
  if ( UFG::TiDo::sm_ambiencesInfo && v3 )
  {
    v6 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v5->i_name);
    UFG::qPrintf("AudioTriggerRegion:: Lst Enter :: %s\n", v6);
  }
  for ( i = (signed __int64)&v5->mTags.mNode.mNext[-1].mNext;
        (unsigned int *)i != &v5->mNode.mUID;
        i = *(_QWORD *)(i + 16) - 8i64 )
  {
    UFG::AudioTriggerRegionEvent::AudioTriggerRegionEvent(&thisEvent, v4, v5, (UFG::AudioTriggerRegionTag *)i);
    UFG::qWiseSymbol::operator=((UFG::qWiseSymbol *)(i + 52), (UFG::qWiseSymbol *)(i + 36));
    if ( *(_DWORD *)(i + 24) == 8 && v4 )
    {
      *(float *)(i + 60) = v4->m_environment.mDryLevel;
      *(float *)(i + 64) = UFG::AudioEntity::GetWetLevelForEffect(v4, *(_DWORD *)(i + 28));
    }
    if ( *(_DWORD *)(i + 24) == 3 && v4 )
    {
      global = 0;
      *(float *)(i + 56) = UFG::AudioEntity::Debug_GetRtpcValue(v4, *(_DWORD *)(i + 28), &global);
      UFG::qWiseSymbol::operator=((UFG::qWiseSymbol *)(i + 52), (UFG::qWiseSymbol *)(i + 36));
    }
    if ( v3 )
    {
      UFG::AudioTriggerRegion::ApplyAudioZoneListener(v5, &thisEvent);
    }
    else
    {
      v8 = thisEvent.mTriggeringEntity;
      if ( thisEvent.mTriggeringEntity )
      {
        switch ( thisEvent.mAudioType )
        {
          case 1u:
            if ( UFG::AudioEventPropertyManager::Find(thisEvent.mAudioUidOnEnter.mUID) )
            {
              v9 = _S44_0;
              if ( !(_S44_0 & 1) )
              {
                _S44_0 |= 1u;
                UFG::qWiseSymbol::create_from_string(&stru_14242FA88, "set_minimap_enter");
                atexit(UFG::AudioTriggerRegion::HandleIntExtForEntities_::_4_::_dynamic_atexit_destructor_for__set_minimap_enter__);
                v9 = _S44_0;
              }
              if ( !(v9 & 2) )
              {
                _S44_0 = v9 | 2;
                UFG::qWiseSymbol::create_from_string(&stru_14242FA90, "set_minimap_exit");
                atexit(UFG::AudioTriggerRegion::HandleIntExtForEntities_::_4_::_dynamic_atexit_destructor_for__set_minimap_exit__);
              }
              if ( thisEvent.mAudioUidOnEnter.mUID == stru_14242FA88.mUID )
              {
                ++v8->m_interiorCount;
                v8->m_bOcclusionIsDirty = 1;
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
              UFG::AudioTriggerRegion::HandleEnvironmentRegionEnter(v5, &thisEvent);
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
}(AMD_HD3D *)thisEvent.mAudioUidOnExit.mUID);
    _((AMD_HD3D *)thisEvent.mAudioUidOnEnte

// File Line: 461
// RVA: 0x5A4060
void __fastcall UFG::AudioTriggerRegion::OnExited(UFG::AudioTriggerRegion *this, UFG::AudioEntity *pTriggeringEntity, bool listener)
{
  bool v3; // r14
  UFG::AudioEntity *v4; // r12
  UFG::AudioTriggerRegion *v5; // rsi
  char *v6; // rax
  UFG::AudioTriggerRegionTag *i; // rdi
  UFG::AudioEntity *v8; // rbx
  UFG::qBaseTreeRB *v9; // rbp
  unsigned int v10; // ecx
  UFG::AudioTriggerRegionEvent thisEvent; // [rsp+28h] [rbp-60h]

  v3 = listener;
  v4 = pTriggeringEntity;
  v5 = this;
  if ( UFG::TiDo::sm_ambiencesInfo && listener )
  {
    v6 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->i_name);
    UFG::qPrintf("AudioTriggerRegion:: Lst Exit :: %s\n", v6);
  }
  for ( i = (UFG::AudioTriggerRegionTag *)&v5->mTags.mNode.mNext[-1].mNext;
        i != (UFG::AudioTriggerRegionTag *)&v5->mNode.mUID;
        i = (UFG::AudioTriggerRegionTag *)&i->mNext[-1].mNext )
  {
    UFG::AudioTriggerRegionEvent::AudioTriggerRegionEvent(&thisEvent, v4, v5, i);
    if ( v3 )
    {
      UFG::AudioTriggerRegion::RemoveAudioZoneListener(v5, &thisEvent);
    }
    else
    {
      v8 = thisEvent.mTriggeringEntity;
      if ( thisEvent.mTriggeringEntity )
      {
        switch ( thisEvent.mAudioType )
        {
          case 1u:
            v9 = UFG::AudioEventPropertyManager::Find(thisEvent.mAudioUidOnEnter.mUID);
            if ( v9 )
            {
              v10 = _S44_0;
              if ( !(_S44_0 & 1) )
              {
                _S44_0 |= 1u;
                UFG::qWiseSymbol::create_from_string(&stru_14242FA88, "set_minimap_enter");
                atexit(UFG::AudioTriggerRegion::HandleIntExtForEntities_::_4_::_dynamic_atexit_destructor_for__set_minimap_enter__);
                v10 = _S44_0;
              }
              if ( !(v10 & 2) )
              {
                _S44_0 = v10 | 2;
                UFG::qWiseSymbol::create_from_string(&stru_14242FA90, "set_minimap_exit");
                atexit(UFG::AudioTriggerRegion::HandleIntExtForEntities_::_4_::_dynamic_atexit_destructor_for__set_minimap_exit__);
              }
              if ( HIDWORD(v9->mNULL.mChild[0][2].mChild[1]) == stru_14242FA90.mUID )
              {
                --v8->m_interiorCount;
                v8->m_bOcclusionIsDirty = 1;
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
              UFG::AudioTriggerRegion::HandleEnvironmentRegionExit(v5, &thisEvent);
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
    && v3 )
  {
    UFG::AudioEntity::Shutdown((UFG::AudioEntity *)&v5->vfptr);
  }
}

// File Line: 613
// RVA: 0x597960
void __fastcall UFG::AudioTriggerRegion::CheckEntity(UFG::AudioEntity *pIn)
{
  float v1; // xmm1_4
  UFG::AudioEntity *v2; // r15
  float v3; // xmm0_4
  Render::SkinningCacheNode *v4; // rax
  UFG::AudioTriggerRegion *v5; // r14
  UFG::qBaseNodeRB *v6; // rdx
  UFG::qBaseTreeRB *v7; // rax
  signed __int64 v8; // r12
  unsigned int v9; // eax
  UFG::RegionContainmentInfo *v10; // rax
  unsigned int v11; // ecx
  unsigned int v12; // edx
  UFG::qSymbol *v13; // rax
  bool v14; // bl
  UFG::RegionContainmentInfo *v15; // rax
  unsigned int v16; // ebp
  unsigned int v17; // edi
  UFG::RegionContainmentInfo *v18; // rsi
  unsigned int *v19; // rbx
  UFG::qBaseTreeRB *v20; // rax
  signed __int64 v21; // rdx
  int v22; // eax
  char v23; // r10
  unsigned int v24; // er8
  unsigned int v25; // ecx
  UFG::qSymbol *v26; // rax
  char v27; // al
  UFG::RegionContainmentInfo *v28; // rax
  unsigned int v29; // esi
  UFG::RegionContainmentInfo *v30; // rbp
  unsigned int v31; // edi
  unsigned int *v32; // rbx
  UFG::qBaseTreeRB *v33; // rax
  signed __int64 v34; // rdx
  int v35; // eax
  char v36; // r10
  unsigned int v37; // er8
  unsigned int v38; // ecx
  UFG::qSymbol *v39; // rax
  char v40; // al
  UFG::qVector3 pos; // [rsp+20h] [rbp-28h]

  v1 = pIn->m_WorldMatrix.v3.y;
  v2 = pIn;
  pos.x = pIn->m_WorldMatrix.v3.x;
  v3 = pIn->m_WorldMatrix.v3.z;
  pos.y = v1;
  pos.z = v3;
  v4 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::AudioTriggerRegion::msAudioTriggerRegions);
  if ( v4 )
  {
    v5 = (UFG::AudioTriggerRegion *)&v4[-16].mCachedBufferPtr;
    if ( v4 != (Render::SkinningCacheNode *)608 )
    {
      do
      {
        if ( v5 )
          v6 = &v5->mNode;
        else
          v6 = 0i64;
        v7 = UFG::qBaseTreeRB::GetNext(&UFG::AudioTriggerRegion::msAudioTriggerRegions.mTree, v6);
        if ( v7 )
          v8 = (signed __int64)v7[-9].mNULL.mChild;
        else
          v8 = 0i64;
        v9 = v5->m_typeFlags;
        if ( v9 & 1 || v9 & 2 || v9 & 4 || v9 & 0x20 )
        {
          v10 = UFG::AudioEntity::GetContainmentInfo(v2);
          v11 = 0;
          v12 = v10->m_regionsContainedIn.size;
          if ( v12 )
          {
            v13 = v10->m_regionsContainedIn.p;
            while ( v5->i_name.mUID != v13->mUID )
            {
              ++v11;
              ++v13;
              if ( v11 >= v12 )
                goto LABEL_17;
            }
          }
          else
          {
LABEL_17:
            v11 = -1;
          }
          v14 = v11 != -1;
          if ( UFG::TriggerRegion::IsHitPoint((UFG::TriggerRegion *)&v5->vfptr, &pos) )
          {
            if ( !v14 )
            {
              v15 = UFG::AudioEntity::GetContainmentInfo(v2);
              v16 = v5->m_regionsContainingMe.m_regionsContainedIn.size;
              v17 = 0;
              v18 = v15;
              if ( v16 )
              {
                v19 = &v5->m_regionsContainingMe.m_regionsContainedIn.p->mUID;
                while ( *v19 )
                {
                  v20 = UFG::qBaseTreeRB::Get(&UFG::AudioTriggerRegion::msAudioTriggerRegions.mTree, *v19);
                  if ( !v20 )
                    break;
                  v21 = (signed __int64)v20[-9].mNULL.mChild;
                  if ( v20 == (UFG::qBaseTreeRB *)608 )
                    goto LABEL_31;
                  v22 = *(_DWORD *)(v21 + 736);
                  if ( !(v22 & 1) && !(v22 & 2) && !(v22 & 4) && !(v22 & 0x20) )
                    goto LABEL_31;
                  v23 = 1;
LABEL_32:
                  v24 = v18->m_regionsContainedIn.size;
                  v25 = 0;
                  if ( !v24 )
                    goto LABEL_38;
                  v26 = v18->m_regionsContainedIn.p;
                  while ( *v19 != v26->mUID )
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
                  ++v19;
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
                UFG::AudioTriggerRegion::SetEntered(v2, v5);
                UFG::AudioTriggerRegion::OnEntered(v5, v2, 0);
              }
            }
          }
          else if ( v14 )
          {
            v28 = UFG::AudioEntity::GetContainmentInfo(v2);
            v29 = v5->m_regionsIContain.m_regionsContainedIn.size;
            v30 = v28;
            if ( !v29 || (v31 = 0, !v29) )
            {
LABEL_68:
              v40 = 1;
LABEL_69:
              if ( v40 )
              {
                UFG::AudioTriggerRegion::SetExited(v2, v5);
                UFG::AudioTriggerRegion::OnExited(v5, v2, 0);
              }
              goto LABEL_71;
            }
            v32 = &v5->m_regionsIContain.m_regionsContainedIn.p->mUID;
            while ( 2 )
            {
              if ( *v32
                && (v33 = UFG::qBaseTreeRB::Get(&UFG::AudioTriggerRegion::msAudioTriggerRegions.mTree, *v32)) != 0i64 )
              {
                v34 = (signed __int64)v33[-9].mNULL.mChild;
                if ( v33 != (UFG::qBaseTreeRB *)608 )
                {
                  v35 = *(_DWORD *)(v34 + 736);
                  if ( v35 & 1 || v35 & 2 || v35 & 4 || v35 & 0x20 )
                  {
                    v36 = 1;
                    goto LABEL_59;
                  }
                }
              }
              else
              {
                v34 = 0i64;
              }
              v36 = 0;
LABEL_59:
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
                    goto LABEL_67;
                }
                if ( v38 != -1 && v34 && v36 )
                {
                  v40 = 0;
                  goto LABEL_69;
                }
              }
LABEL_67:
              ++v31;
              ++v32;
              if ( v31 >= v29 )
                goto LABEL_68;
              continue;
            }
          }
        }
LABEL_71:
        v5 = (UFG::AudioTriggerRegion *)v8;
      }
      while ( v8 );
    }
  }
}

// File Line: 669
// RVA: 0x5AAC80
void __fastcall UFG::AudioTriggerRegion::SetEntered(UFG::AudioEntity *pIn, UFG::AudioTriggerRegion *region)
{
  UFG::AudioTriggerRegion *v2; // rbp
  UFG::AudioEntity *v3; // rdi
  UFG::RegionContainmentInfo *v4; // rax
  unsigned int v5; // er8
  UFG::qArray<UFG::qSymbol,0> *v6; // r9
  unsigned int v7; // ebx
  unsigned int v8; // eax
  UFG::qSymbol *v9; // rcx
  UFG::qSymbol *v10; // rax
  unsigned int v11; // edx
  UFG::qSymbol *v12; // rcx
  UFG::qSymbol result; // [rsp+30h] [rbp+8h]

  v2 = region;
  v3 = pIn;
  v4 = UFG::AudioEntity::GetContainmentInfo(pIn);
  v5 = v4->m_regionsContainedIn.size;
  v6 = &v4->m_regionsContainedIn;
  v7 = 0;
  v8 = 0;
  if ( !v5 )
    goto LABEL_7;
  v9 = v6->p;
  while ( v2->i_name.mUID != v9->mUID )
  {
    ++v8;
    ++v9;
    if ( v8 >= v5 )
      goto LABEL_7;
  }
  if ( v8 == -1 )
LABEL_7:
    UFG::qArray<UFG::qSymbol,0>::Add(v6, &v2->i_name, "RegionContainmentInfo.Array");
  v10 = UFG::AudioEntity::GetName(v3, &result);
  v11 = v2->m_thingsIContain.m_regionsContainedIn.size;
  if ( !v11 )
    goto LABEL_14;
  v12 = v2->m_thingsIContain.m_regionsContainedIn.p;
  while ( v10->mUID != v12->mUID )
  {
    ++v7;
    ++v12;
    if ( v7 >= v11 )
      goto LABEL_14;
  }
  if ( v7 == -1 )
LABEL_14:
    UFG::qArray<UFG::qSymbol,0>::Add(&v2->m_thingsIContain.m_regionsContainedIn, v10, "RegionContainmentInfo.Array");
  v3->m_bOcclusionIsDirty = 1;
}

// File Line: 675
// RVA: 0x5AAD50
void __fastcall UFG::AudioTriggerRegion::SetExited(UFG::AudioEntity *pIn, UFG::AudioTriggerRegion *region)
{
  UFG::AudioTriggerRegion *v2; // rdi
  UFG::AudioEntity *v3; // rbx
  UFG::RegionContainmentInfo *v4; // rax
  UFG::RegionContainmentInfo *v5; // r9
  unsigned int v6; // eax
  __int64 v7; // r8
  UFG::qSymbol *v8; // rcx
  unsigned int v9; // eax
  UFG::qSymbol *v10; // rax
  unsigned int v11; // ecx
  __int64 v12; // rdx
  unsigned int v13; // er8
  UFG::qSymbol *v14; // rax
  unsigned int v15; // eax
  UFG::qSymbol result; // [rsp+30h] [rbp+8h]

  v2 = region;
  v3 = pIn;
  v4 = UFG::AudioEntity::GetContainmentInfo(pIn);
  v5 = v4;
  v6 = v4->m_regionsContainedIn.size;
  v7 = 0i64;
  if ( v6 )
  {
    v8 = v5->m_regionsContainedIn.p;
    while ( v2->i_name.mUID != v8->mUID )
    {
      v7 = (unsigned int)(v7 + 1);
      ++v8;
      if ( (unsigned int)v7 >= v6 )
        goto LABEL_10;
    }
    if ( (_DWORD)v7 != -1 )
    {
      v5->m_regionsContainedIn.p[v7].mUID = v5->m_regionsContainedIn.p[v6 - 1].mUID;
      v9 = v5->m_regionsContainedIn.size;
      if ( v9 > 1 )
        v5->m_regionsContainedIn.size = v9 - 1;
      else
        v5->m_regionsContainedIn.size = 0;
    }
  }
LABEL_10:
  v10 = UFG::AudioEntity::GetName(v3, &result);
  v11 = v2->m_thingsIContain.m_regionsContainedIn.size;
  v12 = 0i64;
  if ( v11 )
  {
    v13 = v10->mUID;
    v14 = v2->m_thingsIContain.m_regionsContainedIn.p;
    while ( v13 != v14->mUID )
    {
      v12 = (unsigned int)(v12 + 1);
      ++v14;
      if ( (unsigned int)v12 >= v11 )
      {
        v3->m_bOcclusionIsDirty = 1;
        return;
      }
    }
    if ( (_DWORD)v12 != -1 )
    {
      v2->m_thingsIContain.m_regionsContainedIn.p[v12].mUID = v2->m_thingsIContain.m_regionsContainedIn.p[v11 - 1].mUID;
      v15 = v2->m_thingsIContain.m_regionsContainedIn.size;
      if ( v15 <= 1 )
      {
        v2->m_thingsIContain.m_regionsContainedIn.size = 0;
        v3->m_bOcclusionIsDirty = 1;
        return;
      }
      v2->m_thingsIContain.m_regionsContainedIn.size = v15 - 1;
    }
  }
  v3->m_bOcclusionIsDirty = 1;
}

// File Line: 688
// RVA: 0x597F30
void __fastcall UFG::AudioTriggerRegion::CheckListener(UFG::AudioListener *pIn)
{
  UFG::AudioListener *v1; // r15
  float v2; // xmm1_4
  float v3; // xmm2_4
  char v4; // si
  Render::SkinningCacheNode *v5; // rax
  signed __int64 v6; // rbx
  UFG::qBaseNodeRB *v7; // rdx
  UFG::qBaseTreeRB *v8; // rax
  signed __int64 v9; // r14
  unsigned int v10; // ecx
  unsigned int v11; // edx
  bool v12; // di
  int v13; // edx
  hkGeometryUtils::IVertices *v14; // rcx
  int v15; // er8
  char *v16; // rax
  UFG::AudioTriggerRegionTag *i; // rdi
  int v18; // ecx
  unsigned int v19; // edx
  UFG::qSymbol *v20; // r8
  hkGeometryUtils::IVertices *v21; // rcx
  unsigned int v22; // edx
  unsigned int v23; // eax
  char *v24; // rax
  UFG::AudioTriggerRegionTag *j; // rdi
  UFG::qVector3 pos; // [rsp+20h] [rbp-B8h]
  __int64 v27; // [rsp+30h] [rbp-A8h]
  UFG::AudioTriggerRegionEvent thisEvent; // [rsp+38h] [rbp-A0h]
  UFG::AudioTriggerRegionEvent v29; // [rsp+70h] [rbp-68h]

  v27 = -2i64;
  v1 = pIn;
  v2 = pIn->m_triggerPosition.y;
  v3 = pIn->m_triggerPosition.z;
  pos.x = pIn->m_triggerPosition.x;
  pos.y = v2;
  pos.z = v3;
  v4 = 0;
  v5 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::AudioTriggerRegion::msAudioTriggerRegions);
  if ( v5 )
  {
    v6 = (signed __int64)&v5[-16].mCachedBufferPtr;
    if ( v5 != (Render::SkinningCacheNode *)608 )
    {
      while ( 1 )
      {
        v7 = (UFG::qBaseNodeRB *)(v6 + 608);
        if ( !v6 )
          v7 = 0i64;
        v8 = UFG::qBaseTreeRB::GetNext(&UFG::AudioTriggerRegion::msAudioTriggerRegions.mTree, v7);
        v9 = (signed __int64)v8[-9].mNULL.mChild;
        if ( !v8 )
          v9 = 0i64;
        v10 = 0;
        v11 = v1->m_containmentInfo.m_regionsContainedIn.size;
        if ( v11 )
        {
          while ( *(_DWORD *)(v6 + 64) != v1->m_containmentInfo.m_regionsContainedIn.p[v10].mUID )
          {
            if ( ++v10 >= v11 )
              goto LABEL_10;
          }
        }
        else
        {
LABEL_10:
          v10 = -1;
        }
        v12 = v10 != -1;
        if ( UFG::TriggerRegion::IsHitPoint((UFG::TriggerRegion *)v6, &pos) )
        {
          if ( v12
            || !UFG::AudioTriggerRegion::CheckContainmentForEntry(
                  (UFG::AudioTriggerRegion *)v6,
                  &v1->m_containmentInfo,
                  1) )
          {
            goto LABEL_44;
          }
          if ( Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(v14, v13, v15) )
            UFG::AudioEntity::Init(
              (UFG::AudioEntity *)(v6 + 288),
              (UFG::qSymbol *)(*(_QWORD *)(v6 + 40) + 72i64),
              &UFG::qMatrix44::msIdentity);
          if ( UFG::TiDo::sm_ambiencesInfo )
          {
            v16 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)(v6 + 64));
            UFG::qPrintf("AudioTriggerRegion:: Lst Enter :: %s\n", v16);
          }
          for ( i = (UFG::AudioTriggerRegionTag *)(*(_QWORD *)(v6 + 648) - 8i64);
                i != (UFG::AudioTriggerRegionTag *)(v6 + 632);
                i = (UFG::AudioTriggerRegionTag *)&i->mNext[-1].mNext )
          {
            UFG::AudioTriggerRegionEvent::AudioTriggerRegionEvent(&thisEvent, 0i64, (UFG::AudioTriggerRegion *)v6, i);
            UFG::qWiseSymbol::operator=(&i->mAudioModeUidOnExit, &i->mAudioModeUidOnEnter);
            UFG::AudioTriggerRegion::ApplyAudioZoneListener((UFG::AudioTriggerRegion *)v6, &thisEvent);
            thisEvent.vfptr = (UFG::AudioTriggerRegionEventVtbl *)&UFG::AudioTriggerRegionEvent::`vftable;
            _((AMD_HD3D *)thisEvent.mAudioModeUid.mUID);
            _((AMD_HD3D *)thisEvent.mAudioUidOnExit.mUID);
            _((AMD_HD3D *)thisEvent.mAudioUidOnEnter.mUID);
          }
          v18 = 0;
          v19 = v1->m_containmentInfo.m_regionsContainedIn.size;
          if ( !v19 )
            goto LABEL_25;
          while ( *(_DWORD *)(v6 + 64) != v1->m_containmentInfo.m_regionsContainedIn.p[v18].mUID )
          {
            if ( ++v18 >= v19 )
              goto LABEL_25;
          }
          if ( v18 == -1 )
LABEL_25:
            UFG::qArray<UFG::qSymbol,0>::Add(
              &v1->m_containmentInfo.m_regionsContainedIn,
              (UFG::qSymbol *)(v6 + 64),
              "RegionContainmentInfo.Array");
        }
        else
        {
          if ( !v12
            || !UFG::AudioTriggerRegion::CheckContainmentForExit(
                  (UFG::AudioTriggerRegion *)v6,
                  &v1->m_containmentInfo,
                  1) )
          {
            goto LABEL_44;
          }
          v21 = 0i64;
          v22 = v1->m_containmentInfo.m_regionsContainedIn.size;
          if ( v22 )
          {
            v20 = v1->m_containmentInfo.m_regionsContainedIn.p;
            while ( *(_DWORD *)(v6 + 64) != v20[(_QWORD)v21].mUID )
            {
              v21 = (hkGeometryUtils::IVertices *)(unsigned int)((_DWORD)v21 + 1);
              if ( (unsigned int)v21 >= v22 )
                goto LABEL_37;
            }
            if ( (_DWORD)v21 != -1 )
            {
              v20[(_QWORD)v21] = v20[v22 - 1];
              v23 = v1->m_containmentInfo.m_regionsContainedIn.size;
              if ( v23 > 1 )
                v1->m_containmentInfo.m_regionsContainedIn.size = v23 - 1;
              else
                v1->m_containmentInfo.m_regionsContainedIn.size = 0;
            }
          }
LABEL_37:
          if ( UFG::TiDo::sm_ambiencesInfo )
          {
            v24 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)(v6 + 64));
            UFG::qPrintf("AudioTriggerRegion:: Lst Exit :: %s\n", v24);
          }
          for ( j = (UFG::AudioTriggerRegionTag *)(*(_QWORD *)(v6 + 648) - 8i64);
                j != (UFG::AudioTriggerRegionTag *)(v6 + 632);
                j = (UFG::AudioTriggerRegionTag *)&j->mNext[-1].mNext )
          {
            UFG::AudioTriggerRegionEvent::AudioTriggerRegionEvent(&v29, 0i64, (UFG::AudioTriggerRegion *)v6, j);
            UFG::AudioTriggerRegion::RemoveAudioZoneListener((UFG::AudioTriggerRegion *)v6, &v29);
            v29.vfptr = (UFG::AudioTriggerRegionEventVtbl *)&UFG::AudioTriggerRegionEvent::`vftable;
            _((AMD_HD3D *)v29.mAudioModeUid.mUID);
            _((AMD_HD3D *)v29.mAudioUidOnExit.mUID);
            _((AMD_HD3D *)v29.mAudioUidOnEnter.mUID);
          }
          if ( Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(v21, v22, (int)v20) )
            UFG::AudioEntity::Shutdown((UFG::AudioEntity *)(v6 + 288));
        }
        v4 = 1;
LABEL_44:
        v6 = v9;
        if ( !v9 )
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
  UFG::AudioTriggerRegion *v2; // rdi
  UFG::RegionComponent *v3; // rcx
  bool v4; // bl
  UFG::qBaseTreeRB *v5; // rax
  UFG::AudioTriggerRegion *v6; // rbx
  UFG::RegionComponent *v7; // rcx
  unsigned int v8; // edx
  unsigned int v9; // eax
  UFG::qSymbol *v10; // rcx
  unsigned int v11; // edx
  unsigned int v12; // eax
  UFG::qSymbol *v13; // rcx
  UFG::qSymbol *v14; // rdx
  UFG::qArray<UFG::qSymbol,0> *v15; // rcx
  unsigned int v16; // edx
  unsigned int v17; // eax
  UFG::qSymbol *v18; // rcx
  unsigned int v19; // edx
  unsigned int v20; // eax
  UFG::qSymbol *v21; // rcx
  UFG::qBox v22; // [rsp+20h] [rbp-30h]
  UFG::qBox pBox; // [rsp+38h] [rbp-18h]

  v2 = regionToCheck;
  v3 = (UFG::RegionComponent *)regionToCheck->mpRegion.m_pPointer;
  v4 = listSkip;
  *(_QWORD *)&pBox.mMin.x = 0i64;
  *(_QWORD *)&pBox.mMin.z = 0i64;
  *(_QWORD *)&pBox.mMax.y = 0i64;
  UFG::RegionComponent::GetBoundingBox(v3, &pBox);
  if ( v4 )
    v5 = UFG::qBaseTreeRB::GetNext(&UFG::AudioTriggerRegion::msAudioTriggerRegions.mTree, &v2->mNode);
  else
    v5 = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::AudioTriggerRegion::msAudioTriggerRegions);
  while ( 1 )
  {
    v6 = (UFG::AudioTriggerRegion *)(v5 ? v5[-9].mNULL.mChild : 0i64);
    if ( !v6 )
      break;
    if ( v6 == v2 )
      goto LABEL_48;
    v7 = (UFG::RegionComponent *)v6->mpRegion.m_pPointer;
    *(_QWORD *)&v22.mMin.x = 0i64;
    *(_QWORD *)&v22.mMin.z = 0i64;
    *(_QWORD *)&v22.mMax.y = 0i64;
    UFG::RegionComponent::GetBoundingBox(v7, &v22);
    if ( v22.mMin.x <= pBox.mMax.x
      && v22.mMax.x >= pBox.mMin.x
      && v22.mMin.y <= pBox.mMax.y
      && v22.mMax.y >= pBox.mMin.y
      && v22.mMin.z <= pBox.mMax.z
      && v22.mMax.z >= pBox.mMin.z )
    {
      if ( UFG::AudioTriggerRegion::Contains(v6, v2) == 1 )
      {
        v8 = v2->m_regionsContainingMe.m_regionsContainedIn.size;
        v9 = 0;
        if ( !v8 )
          goto LABEL_22;
        v10 = v2->m_regionsContainingMe.m_regionsContainedIn.p;
        while ( v6->i_name.mUID != v10->mUID )
        {
          ++v9;
          ++v10;
          if ( v9 >= v8 )
            goto LABEL_22;
        }
        if ( v9 == -1 )
LABEL_22:
          UFG::qArray<UFG::qSymbol,0>::Add(
            &v2->m_regionsContainingMe.m_regionsContainedIn,
            &v6->i_name,
            "RegionContainmentInfo.Array");
        v11 = v6->m_regionsIContain.m_regionsContainedIn.size;
        v12 = 0;
        if ( !v11 )
          goto LABEL_51;
        v13 = v6->m_regionsIContain.m_regionsContainedIn.p;
        while ( v2->i_name.mUID != v13->mUID )
        {
          ++v12;
          ++v13;
          if ( v12 >= v11 )
          {
            v14 = &v2->i_name;
            v15 = &v6->m_regionsIContain.m_regionsContainedIn;
            goto LABEL_45;
          }
        }
        if ( v12 == -1 )
        {
LABEL_51:
          v14 = &v2->i_name;
          v15 = &v6->m_regionsIContain.m_regionsContainedIn;
          goto LABEL_45;
        }
      }
      else if ( UFG::AudioTriggerRegion::Contains(v2, v6) == 1 )
      {
        v16 = v6->m_regionsContainingMe.m_regionsContainedIn.size;
        v17 = 0;
        if ( !v16 )
          goto LABEL_37;
        v18 = v6->m_regionsContainingMe.m_regionsContainedIn.p;
        while ( v2->i_name.mUID != v18->mUID )
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
            &v2->i_name,
            "RegionContainmentInfo.Array");
        v19 = v2->m_regionsIContain.m_regionsContainedIn.size;
        v20 = 0;
        if ( !v19 )
          goto LABEL_44;
        v21 = v2->m_regionsIContain.m_regionsContainedIn.p;
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
          v14 = &v6->i_name;
          v15 = &v2->m_regionsIContain.m_regionsContainedIn;
LABEL_45:
          UFG::qArray<UFG::qSymbol,0>::Add(v15, v14, "RegionContainmentInfo.Array");
        }
      }
      ++UFG::g_dbgPass;
      goto LABEL_48;
    }
    ++UFG::g_dbgFail;
LABEL_48:
    v5 = UFG::qBaseTreeRB::GetNext(&UFG::AudioTriggerRegion::msAudioTriggerRegions.mTree, &v6->mNode);
  }
}

// File Line: 830
// RVA: 0x155CD90
__int64 UFG::_dynamic_initializer_for__sPolyVsPolyCache__()
{
  UFG::sPolyVsPolyCache.mTree.mNULL.mParent = (UFG::qBaseNodeVariableRB<unsigned __int64> *)((unsigned __int64)&UFG::sPolyVsPolyCache.mTree.mNULL & 0xFFFFFFFFFFFFFFFEui64);
  UFG::sPolyVsPolyCache.mTree.mRoot.mParent = (UFG::qBaseNodeVariableRB<unsigned __int64> *)((unsigned __int64)&UFG::sPolyVsPolyCache.mTree.mNULL & 0xFFFFFFFFFFFFFFFEui64);
  return atexit(UFG::_dynamic_atexit_destructor_for__sPolyVsPolyCache__);
}

// File Line: 838
// RVA: 0x59C2F0
UFG::AudioTriggerRegion *__fastcall UFG::AudioTriggerRegion::FindInnermostRegionOfTypeContainingObject(UFG::AudioTriggerRegion *this, UFG::RegionContainmentInfo *objectContainment, UFG::AudioTriggerRegion::eTypeFlags type)
{
  UFG::AudioTriggerRegion::eTypeFlags v3; // er15
  signed __int64 v4; // r12
  __int64 v5; // rsi
  unsigned int v6; // ebp
  UFG::allocator::free_link *v7; // rax
  unsigned __int64 v8; // rax
  unsigned int *v9; // r13
  _QWORD *v10; // rbx
  unsigned int *v11; // rdi
  __int64 v12; // r14
  UFG::qBaseTreeRB *v13; // rax
  signed __int64 v14; // rax
  UFG::allocator::free_link *v15; // r15
  unsigned int *v16; // r14
  __int64 v17; // rcx
  __int64 v18; // rbp
  unsigned int v19; // eax
  signed __int64 v20; // rbx
  char v21; // si
  unsigned int *v22; // r11
  __int64 v23; // rdi
  __int64 v24; // rcx
  unsigned int v25; // er8
  UFG::allocator::free_link *mem; // [rsp+30h] [rbp-48h]
  __int64 v28; // [rsp+38h] [rbp-40h]
  void *ptr; // [rsp+40h] [rbp-38h]
  __int64 v30; // [rsp+88h] [rbp+10h]

  v3 = type;
  ptr = 0i64;
  v28 = 0i64;
  UFG::qArray<UFG::qSymbol,0>::Clone(&objectContainment->m_regionsContainedIn, (UFG::qArray<UFG::qSymbol,0> *)&v28);
  v4 = 0i64;
  v5 = (unsigned int)v28;
  v6 = v28;
  v7 = 0i64;
  mem = 0i64;
  if ( (_DWORD)v28 )
  {
    v8 = 8i64 * (unsigned int)v28;
    if ( !is_mul_ok((unsigned int)v28, 8ui64) )
      v8 = -1i64;
    v7 = UFG::qMalloc(v8, "qArray.Reallocate(Constructor)", 0i64);
    mem = v7;
  }
  v9 = (unsigned int *)ptr;
  if ( (_DWORD)v5 )
  {
    v10 = &v7->mNext;
    v11 = (unsigned int *)ptr;
    v12 = v5;
    do
    {
      if ( *v11
        && (v13 = UFG::qBaseTreeRB::Get(&UFG::AudioTriggerRegion::msAudioTriggerRegions.mTree, *v11)) != 0i64
        && (v14 = (signed __int64)v13[-9].mNULL.mChild) != 0
        && v3 & *(_DWORD *)(v14 + 736) )
      {
        v4 = v14;
        *v10 = v14;
      }
      else
      {
        *v11 = UFG::gNullQSymbol.mUID;
        --v6;
        *v10 = 0i64;
      }
      ++v11;
      ++v10;
      --v12;
    }
    while ( v12 );
  }
  if ( v6 > 1 && (_DWORD)v5 )
  {
    v15 = mem;
    v16 = v9;
    v17 = v5;
    v30 = v5;
    v18 = v5;
    v19 = UFG::gNullQSymbol.mUID;
    do
    {
      if ( *v16 != v19 )
      {
        v20 = (signed __int64)v15->mNext;
        v21 = 0;
        v22 = v9;
        v23 = v17;
        do
        {
          if ( *v22 != v19 )
          {
            if ( v20 )
            {
              v24 = 0i64;
              v25 = *(_DWORD *)(v20 + 688);
              if ( v25 )
              {
                while ( *v22 != *(_DWORD *)(*(_QWORD *)(v20 + 696) + 4 * v24) )
                {
                  v24 = (unsigned int)(v24 + 1);
                  if ( (unsigned int)v24 >= v25 )
                    goto LABEL_27;
                }
                if ( (_DWORD)v24 != -1 )
                {
                  *v16 = v19;
                  v15->mNext = 0i64;
                  v21 = 1;
                  v19 = UFG::gNullQSymbol.mUID;
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
          v4 = v20;
        v17 = v30;
      }
      ++v16;
      ++v15;
      --v18;
    }
    while ( v18 );
  }
  if ( mem )
    operator delete[](mem);
  if ( v9 )
  {
    `eh vector destructor iterator(v9, 4ui64, *(v9 - 1), (void (__fastcall *)(void *))_);
    operator delete[](v9 - 1);
  }
  return (UFG::AudioTriggerRegion *)v4;
}

// File Line: 913
// RVA: 0x598D20
__int64 __fastcall UFG::AudioTriggerRegion::Contains(UFG::AudioTriggerRegion *this, UFG::AudioTriggerRegion *audioRegion)
{
  UFG::AudioTriggerRegion *v2; // rsi
  UFG::AudioTriggerRegion *v3; // r13
  UFG::RegionComponent *v4; // r10
  UFG::RegionBase *v5; // rbx
  unsigned __int64 v6; // r9
  UFG::qTreeRB64<UFG::PolyVsPolyCache,UFG::PolyVsPolyCache,1> *v7; // rax
  UFG::qTreeRB64<UFG::PolyVsPolyCache,UFG::PolyVsPolyCache,1> *i; // rcx
  UFG::TransformNodeComponent *v10; // rbp
  __int64 v11; // r14
  unsigned int v12; // er12
  int v13; // edi
  __int64 v14; // rsi
  UFG::RegionBaseVtbl *v15; // rax
  float v16; // xmm2_4
  float v17; // xmm6_4
  float v18; // xmm11_4
  float v19; // xmm9_4
  float v20; // xmm7_4
  float v21; // xmm12_4
  float v22; // xmm10_4
  float v23; // xmm8_4
  unsigned int v24; // ebx
  float v25; // xmm6_4
  float v26; // xmm5_4
  float v27; // xmm4_4
  float v28; // xmm3_4
  float v29; // xmm2_4
  float v30; // xmm4_4
  unsigned int v31; // er15
  UFG::SimObject *v32; // rbx
  UFG::SimObject *v33; // rdi
  UFG::allocator::free_link *v34; // rax
  UFG::qBaseNodeVariableRB<unsigned __int64> *v35; // r8
  __int64 v36; // rdx
  __int64 v37; // rcx
  UFG::qVector3 pos; // [rsp+28h] [rbp-B0h]
  UFG::AudioTriggerRegion *v39; // [rsp+E8h] [rbp+10h]

  v39 = audioRegion;
  v2 = audioRegion;
  v3 = this;
  v4 = (UFG::RegionComponent *)audioRegion->mpRegion.m_pPointer;
  v5 = v4->mpRegion.mPtr;
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
  v10 = UFG::RegionComponent::GetXformNode(v4);
  UFG::TransformNodeComponent::UpdateWorldTransform(v10);
  LODWORD(v11) = 0;
  if ( v5->vfptr->GetType(v5) == 8 )
  {
    v12 = v5[1].mRefCount;
    v13 = 0;
    if ( v12 )
    {
      v14 = 0i64;
      v11 = v12;
      do
      {
        v15 = v5[1].vfptr;
        v16 = (float)((float)((float)(*(float *)((char *)&v15->__vecDelDtor + v14 + 4) * v10->mWorldTransform.v1.y)
                            + (float)(*(float *)((char *)&v15->__vecDelDtor + v14) * v10->mWorldTransform.v0.y))
                    + (float)(*(float *)((char *)&v15->__vecDelDtor + v14 + 8) * v10->mWorldTransform.v2.y))
            + v10->mWorldTransform.v3.y;
        v17 = (float)((float)((float)(*(float *)((char *)&v15->__vecDelDtor + v14 + 4) * v10->mWorldTransform.v1.z)
                            + (float)(*(float *)((char *)&v15->__vecDelDtor + v14) * v10->mWorldTransform.v0.z))
                    + (float)(*(float *)((char *)&v15->__vecDelDtor + v14 + 8) * v10->mWorldTransform.v2.z))
            + v10->mWorldTransform.v3.z;
        pos.x = (float)((float)((float)(*(float *)((char *)&v15->__vecDelDtor + v14) * v10->mWorldTransform.v0.x)
                              + (float)(*(float *)((char *)&v15->__vecDelDtor + v14 + 4) * v10->mWorldTransform.v1.x))
                      + (float)(*(float *)((char *)&v15->__vecDelDtor + v14 + 8) * v10->mWorldTransform.v2.x))
              + v10->mWorldTransform.v3.x;
        pos.y = v16;
        pos.z = v17;
        if ( UFG::RegionComponent::IsHitPoint((UFG::RegionComponent *)v3->mpRegion.m_pPointer, &pos) )
          ++v13;
        v14 += 12i64;
        --v11;
      }
      while ( v11 );
      v2 = v39;
    }
  }
  else
  {
    if ( v5->vfptr->GetType(v5) != 3 )
    {
LABEL_40:
      v31 = 1;
      goto LABEL_41;
    }
    v18 = *(float *)&v5[1].vfptr;
    v19 = *((float *)&v5[1].vfptr + 1);
    v20 = *(float *)&v5[1].mRefCount;
    v21 = *((float *)&v5[1].mRefCount + 1);
    v22 = *(float *)&v5[2].vfptr;
    v23 = *((float *)&v5[2].vfptr + 1);
    v13 = 0;
    v12 = 8;
    v24 = 0;
    do
    {
      if ( v24 & 4 )
        v25 = v23;
      else
        v25 = v20;
      if ( v24 & 2 )
        v26 = v22;
      else
        v26 = v19;
      if ( v24 & 1 )
        v27 = v21;
      else
        v27 = v18;
      v28 = (float)((float)((float)(v27 * v10->mWorldTransform.v0.x) + (float)(v26 * v10->mWorldTransform.v1.x))
                  + (float)(v25 * v10->mWorldTransform.v2.x))
          + v10->mWorldTransform.v3.x;
      v29 = (float)((float)((float)(v27 * v10->mWorldTransform.v0.y) + (float)(v26 * v10->mWorldTransform.v1.y))
                  + (float)(v25 * v10->mWorldTransform.v2.y))
          + v10->mWorldTransform.v3.y;
      v30 = (float)((float)((float)(v27 * v10->mWorldTransform.v0.z) + (float)(v26 * v10->mWorldTransform.v1.z))
                  + (float)(v25 * v10->mWorldTransform.v2.z))
          + v10->mWorldTransform.v3.z;
      pos.x = v28;
      pos.y = v29;
      pos.z = v30;
      if ( UFG::RegionComponent::IsHitPoint((UFG::RegionComponent *)v3->mpRegion.m_pPointer, &pos) )
        ++v13;
      ++v24;
    }
    while ( v24 < 8 );
  }
  if ( v13 == v12 )
    goto LABEL_40;
  if ( v13 )
    v31 = 2;
  else
    v31 = v11;
LABEL_41:
  v32 = v3->m_pSimObject;
  v33 = v2->m_pSimObject;
  v34 = UFG::qMalloc(0x28ui64, "PolyVsPolyCache", 0i64);
  v35 = (UFG::qBaseNodeVariableRB<unsigned __int64> *)v34;
  if ( v34 )
  {
    v36 = v32->m_Name.mUID;
    v37 = v33->m_Name.mUID;
    v34->mNext = 0i64;
    v34[1].mNext = 0i64;
    v34[2].mNext = 0i64;
    v34[3].mNext = (UFG::allocator::free_link *)(v36 | (v37 << 32));
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
  Render::SkinningCacheNode *v0; // rax
  signed __int64 v1; // rbx
  char *v2; // rcx
  char *v3; // rdi
  char *v4; // rcx
  char *v5; // rdi
  UFG::qBaseTreeRB *v6; // rax
  Render::SkinningCacheNode *v7; // rax
  UFG::AudioTriggerRegion *v8; // rbx
  UFG::qBaseTreeRB *v9; // rax

  v0 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::AudioTriggerRegion::msAudioTriggerRegions);
  v1 = (signed __int64)&v0[-16].mCachedBufferPtr;
  if ( !v0 )
    v1 = 0i64;
  while ( v1 )
  {
    v2 = *(char **)(v1 + 672);
    if ( v2 )
    {
      v3 = v2 - 4;
      `eh vector destructor iterator(v2, 4ui64, *((_DWORD *)v2 - 1), (void (__fastcall *)(void *))_);
      operator delete[](v3);
    }
    *(_QWORD *)(v1 + 672) = 0i64;
    *(_QWORD *)(v1 + 664) = 0i64;
    v4 = *(char **)(v1 + 696);
    if ( v4 )
    {
      v5 = v4 - 4;
      `eh vector destructor iterator(v4, 4ui64, *((_DWORD *)v4 - 1), (void (__fastcall *)(void *))_);
      operator delete[](v5);
    }
    *(_QWORD *)(v1 + 696) = 0i64;
    *(_QWORD *)(v1 + 688) = 0i64;
    v6 = UFG::qBaseTreeRB::GetNext(
           &UFG::AudioTriggerRegion::msAudioTriggerRegions.mTree,
           (UFG::qBaseNodeRB *)(v1 + 608));
    if ( v6 )
      v1 = (signed __int64)v6[-9].mNULL.mChild;
    else
      v1 = 0i64;
  }
  v7 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::AudioTriggerRegion::msAudioTriggerRegions);
  v8 = (UFG::AudioTriggerRegion *)&v7[-16].mCachedBufferPtr;
  if ( !v7 )
LABEL_12:
    v8 = 0i64;
  while ( v8 )
  {
    UFG::AudioTriggerRegion::CheckRegionContainment(v8, 1);
    v9 = UFG::qBaseTreeRB::GetNext(&UFG::AudioTriggerRegion::msAudioTriggerRegions.mTree, &v8->mNode);
    if ( !v9 )
      goto LABEL_12;
    v8 = (UFG::AudioTriggerRegion *)v9[-9].mNULL.mChild;
  }
  UFG::AudioTriggerRegion::sm_hierarchyIsDirty = 0;
}

// File Line: 1036
// RVA: 0x597750
char __fastcall UFG::AudioTriggerRegion::CheckContainmentForEntry(UFG::AudioTriggerRegion *this, UFG::RegionContainmentInfo *info, bool listener)
{
  unsigned int v3; // ebp
  unsigned int v4; // edi
  bool v5; // r12
  UFG::RegionContainmentInfo *v6; // r14
  UFG::AudioTriggerRegion *v7; // r15
  __int64 v8; // rsi
  UFG::qSymbol *v9; // rbx
  unsigned int v10; // edx
  UFG::qBaseTreeRB *v11; // rax
  signed __int64 v12; // r8
  int v13; // eax
  char v14; // r10
  unsigned int v15; // edx
  unsigned int v16; // eax
  UFG::qSymbol *v17; // rcx

  v3 = this->m_regionsContainingMe.m_regionsContainedIn.size;
  v4 = 0;
  v5 = listener;
  v6 = info;
  v7 = this;
  if ( !v3 )
    return 1;
  v8 = 0i64;
  while ( 1 )
  {
    v9 = v7->m_regionsContainingMe.m_regionsContainedIn.p;
    v10 = v9[v8].mUID;
    if ( !v10 || (v11 = UFG::qBaseTreeRB::Get(&UFG::AudioTriggerRegion::msAudioTriggerRegions.mTree, v10)) == 0i64 )
    {
      v12 = 0i64;
LABEL_12:
      v14 = 0;
      goto LABEL_13;
    }
    v12 = (signed __int64)v11[-9].mNULL.mChild;
    if ( v11 == (UFG::qBaseTreeRB *)608 )
      goto LABEL_12;
    v13 = *(_DWORD *)(v12 + 736);
    if ( !(v13 & 1) && !(v13 & 2) && !(v13 & 4) && !(v13 & 0x20) )
      goto LABEL_12;
    v14 = 1;
LABEL_13:
    v15 = v6->m_regionsContainedIn.size;
    v16 = 0;
    if ( v15 )
    {
      v17 = v6->m_regionsContainedIn.p;
      while ( v9[v8].mUID != v17->mUID )
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
    if ( v12 )
    {
      if ( v5 || v14 )
        return 0;
    }
LABEL_22:
    ++v4;
    ++v8;
    if ( v4 >= v3 )
      return 1;
  }
}

// File Line: 1079
// RVA: 0x597850
char __fastcall UFG::AudioTriggerRegion::CheckContainmentForExit(UFG::AudioTriggerRegion *this, UFG::RegionContainmentInfo *info, bool listener)
{
  unsigned int v3; // ebp
  bool v4; // r12
  UFG::RegionContainmentInfo *v5; // r14
  UFG::AudioTriggerRegion *v6; // r15
  unsigned int v8; // edi
  __int64 v9; // rsi
  UFG::qSymbol *v10; // rbx
  unsigned int v11; // edx
  UFG::qBaseTreeRB *v12; // rax
  signed __int64 v13; // rdx
  int v14; // eax
  char v15; // r10
  unsigned int v16; // er8
  unsigned int v17; // eax
  UFG::qSymbol *v18; // rcx

  v3 = this->m_regionsIContain.m_regionsContainedIn.size;
  v4 = listener;
  v5 = info;
  v6 = this;
  if ( !v3 )
    return 1;
  v8 = 0;
  if ( !v3 )
    return 1;
  v9 = 0i64;
  while ( 1 )
  {
    v10 = v6->m_regionsIContain.m_regionsContainedIn.p;
    v11 = v10[v9].mUID;
    if ( !v11 || (v12 = UFG::qBaseTreeRB::Get(&UFG::AudioTriggerRegion::msAudioTriggerRegions.mTree, v11)) == 0i64 )
    {
      v13 = 0i64;
LABEL_14:
      v15 = 0;
      goto LABEL_15;
    }
    v13 = (signed __int64)v12[-9].mNULL.mChild;
    if ( v12 == (UFG::qBaseTreeRB *)608 )
      goto LABEL_14;
    v14 = *(_DWORD *)(v13 + 736);
    if ( !(v14 & 1) && !(v14 & 2) && !(v14 & 4) && !(v14 & 0x20) )
      goto LABEL_14;
    v15 = 1;
LABEL_15:
    v16 = v5->m_regionsContainedIn.size;
    v17 = 0;
    if ( v16 )
    {
      v18 = v5->m_regionsContainedIn.p;
      while ( v10[v9].mUID != v18->mUID )
      {
        ++v17;
        ++v18;
        if ( v17 >= v16 )
          goto LABEL_24;
      }
      if ( v17 != -1 && v13 && (v4 || v15) )
        return 0;
    }
LABEL_24:
    ++v8;
    ++v9;
    if ( v8 >= v3 )
      return 1;
  }
}

// File Line: 1243
// RVA: 0x5967B0
void __fastcall UFG::AudioTriggerRegion::ApplyAudioZoneListener(UFG::AudioTriggerRegion *this, UFG::AudioTriggerRegionEvent *thisEvent)
{
  UFG::AudioTriggerRegion *v2; // rbx
  UFG::AudioTriggerRegion *v3; // rcx
  UFG::AudioTriggerRegionEvent *v4; // rsi
  UFG::qBaseTreeRB *v5; // rax
  UFG::qWiseSymbol *v6; // rcx
  UFG::qBaseTreeRB *v7; // rax
  unsigned int v8; // ebx
  unsigned int v9; // edi
  UFG::TiDo *v10; // rax
  UFG::TiDo *v11; // rax
  UFG::qSymbol result; // [rsp+48h] [rbp+10h]

  v2 = this;
  v3 = thisEvent->mRegionEntity;
  v4 = thisEvent;
  if ( v3 )
  {
    switch ( thisEvent->mAudioType )
    {
      case 1u:
        v5 = UFG::AudioEventPropertyManager::Find(thisEvent->mAudioUidOnEnter.mUID);
        if ( v5 )
        {
          v6 = (UFG::qWiseSymbol *)&v5->mNULL.mChild[0][2].mUID;
          if ( v6->mUID != -1 )
            UFG::SoundBankManager::QueueBankForLoad(v6);
        }
        v7 = UFG::AudioEventPropertyManager::Find(v4->mAudioUidOnEnter.mUID);
        if ( v7 && LOBYTE(v7->mNULL.mChild[0][3].mChild[0]) )
          UFG::AudioTriggerRegion::HandleRefCountedEvent(v2, v4, 1);
        else
          UFG::AudioEntity::CreateAndPlayEvent(
            (UFG::AudioEntity *)&UFG::AmbienceAudio::m_instance->vfptr,
            v4->mAudioUidOnEnter.mUID,
            0i64,
            0,
            0i64);
        break;
      case 3u:
        UFG::AudioEntity::SetRtpcValue(
          (UFG::AudioEntity *)&v3->vfptr,
          thisEvent->mAudioUidOnEnter.mUID,
          thisEvent->mAudioRtpcVal);
        break;
      case 4u:
        goto $LN8_52;
      case 5u:
        UFG::AudioEntity::SetWwiseSwitch(
          (UFG::AudioEntity *)&v3->vfptr,
          thisEvent->mAudioUidOnEnter.mUID,
          thisEvent->mAudioModeUid.mUID);
        break;
      case 7u:
        UFG::TiDo::GetInstance();
        UFG::TiDo::LoadWwiseBank(&v4->mAudioUidOnEnter);
        break;
      case 0xAu:
        UFG::TiDo::GetInstance();
        UFG::TiDo::UnloadWwiseBank(&v4->mAudioUidOnEnter);
        break;
      case 0xBu:
        UFG::qWiseSymbol::operator=(&UFG::AudioTriggerRegion::msActiveMixUid, &thisEvent->mAudioUidOnEnter);
$LN8_52:
        v8 = v4->mAudioUidOnEnter.mUID;
        v9 = v4->mAudioModeUid.mUID;
        v10 = UFG::TiDo::GetInstance();
        UFG::AudioEntity::SetWwiseState(v10, v9, v8);
        break;
      case 0xCu:
        UFG::DoorStateManager::sm_doorRegionName.mUID = UFG::AudioEntity::GetName(
                                                          (UFG::AudioEntity *)&v3->vfptr,
                                                          &result)->mUID;
        UFG::qWiseSymbol::operator=(&UFG::DoorStateManager::sm_outdoorState, &v4->mAudioUidOnExit);
        UFG::qWiseSymbol::operator=(&UFG::DoorStateManager::sm_indoorState, &v4->mAudioUidOnEnter);
        UFG::DoorStateManager::OnEnterRegion();
        break;
      default:
        break;
    }
    v11 = UFG::TiDo::GetInstance();
    v11->vfptr->OnTriggerRegionEnter(v11, v4);
  }
}

// File Line: 1377
// RVA: 0x5A9D20
void __fastcall UFG::AudioTriggerRegion::RemoveAudioZoneListener(UFG::AudioTriggerRegion *this, UFG::AudioTriggerRegionEvent *thisEvent)
{
  UFG::AudioTriggerRegion *v2; // r9
  UFG::AudioTriggerRegionEvent *v3; // rsi
  UFG::AudioTriggerRegion *v4; // rbx
  UFG::AudioEntity *v5; // r9
  UFG::qBaseTreeRB *v6; // rax
  UFG::qBaseTreeRB *v7; // rax
  UFG::qWiseSymbol *v8; // rcx
  unsigned int v9; // ebx
  unsigned int v10; // edi
  UFG::TiDo *v11; // rax
  UFG::qWiseSymbol *v12; // rax
  UFG::qWiseSymbol *v13; // rax
  UFG::TiDo *v14; // rax

  v2 = thisEvent->mRegionEntity;
  v3 = thisEvent;
  v4 = this;
  if ( v2 )
  {
    v5 = (UFG::AudioEntity *)&v2->vfptr;
    if ( v5 )
    {
      switch ( thisEvent->mAudioType )
      {
        case 1u:
          v6 = UFG::AudioEventPropertyManager::Find(thisEvent->mAudioUidOnExit.mUID);
          if ( v6 && LOBYTE(v6->mNULL.mChild[0][3].mChild[0]) )
            UFG::AudioTriggerRegion::HandleRefCountedEvent(v4, v3, 0);
          else
            UFG::AudioEntity::CreateAndPlayEvent(
              (UFG::AudioEntity *)&UFG::AmbienceAudio::m_instance->vfptr,
              v3->mAudioUidOnExit.mUID,
              0i64,
              0,
              0i64);
          v7 = UFG::AudioEventPropertyManager::Find(v3->mAudioUidOnEnter.mUID);
          if ( v7 )
          {
            v8 = (UFG::qWiseSymbol *)&v7->mNULL.mChild[0][2].mUID;
            if ( v8->mUID != -1 )
              UFG::SoundBankManager::QueueBankForUnload(v8);
          }
          break;
        case 3u:
          UFG::AudioEntity::SetRtpcValue(v5, thisEvent->mAudioUidOnExit.mUID, thisEvent->mAudioRtpcVal);
          break;
        case 4u:
          v9 = thisEvent->mAudioUidOnExit.mUID;
          v10 = thisEvent->mAudioModeUid.mUID;
          v11 = UFG::TiDo::GetInstance();
          UFG::AudioEntity::SetWwiseState(v11, v10, v9);
          break;
        case 5u:
          UFG::AudioEntity::SetWwiseSwitch(v5, thisEvent->mAudioUidOnExit.mUID, thisEvent->mAudioModeUid.mUID);
          break;
        case 7u:
          UFG::TiDo::GetInstance();
          UFG::TiDo::UnloadWwiseBank(&v3->mAudioUidOnExit);
          break;
        case 0xAu:
          UFG::TiDo::GetInstance();
          UFG::TiDo::LoadWwiseBank(&v3->mAudioUidOnExit);
          break;
        case 0xBu:
          UFG::AudioTriggerRegion::HandleMixRegionExit(this);
          break;
        case 0xCu:
          UFG::DoorStateManager::sm_doorRegionName.mUID = UFG::gNullQSymbol.mUID;
          v12 = UFG::qWiseSymbol::get_null();
          UFG::qWiseSymbol::operator=(&UFG::DoorStateManager::sm_outdoorState, v12);
          v13 = UFG::qWiseSymbol::get_null();
          UFG::qWiseSymbol::operator=(&UFG::DoorStateManager::sm_indoorState, v13);
          UFG::DoorStateManager::OnExitRegion();
          break;
        default:
          break;
      }
      v14 = UFG::TiDo::GetInstance();
      v14->vfptr->OnTriggerRegionExit(v14, v3);
    }
  }
}

// File Line: 1514
// RVA: 0x59EC10
void __fastcall UFG::AudioTriggerRegion::HandleRefCountedEvent(UFG::AudioTriggerRegion *this, UFG::AudioTriggerRegionEvent *thisEvent, bool enter)
{
  bool v3; // si
  UFG::AudioTriggerRegionEvent *v4; // rbx
  UFG::qWiseSymbol *v5; // rdx
  unsigned int v6; // eax
  UFG::qBaseTreeRB *v7; // rax
  UFG::qBaseTreeRB *v8; // rdi
  const char *v9; // rax
  int v10; // eax
  bool v11; // al
  bool v12; // al
  const char *v13; // rbx
  const char *v14; // rax
  UFG::qWiseSymbol v15; // [rsp+60h] [rbp+18h]

  v3 = enter;
  v4 = thisEvent;
  v15.mUID = -1;
  _((AMD_HD3D *)0xFFFFFFFFi64);
  v5 = &v4->mAudioUidOnEnter;
  if ( !v3 )
    v5 = &v4->mAudioUidOnExit;
  UFG::qWiseSymbol::operator=(&v15, v5);
  v6 = _S42;
  if ( !(_S42 & 1) )
  {
    _S42 |= 1u;
    UFG::qWiseSymbol::create_from_string(&set_minimap_enter, "set_minimap_enter");
    atexit(UFG::AudioTriggerRegion::HandleRefCountedEvent_::_7_::_dynamic_atexit_destructor_for__set_minimap_enter__);
    v6 = _S42;
  }
  if ( !(v6 & 2) )
  {
    _S42 = v6 | 2;
    UFG::qWiseSymbol::create_from_string(&set_minimap_exit, "set_minimap_exit");
    atexit(UFG::AudioTriggerRegion::HandleRefCountedEvent_::_7_::_dynamic_atexit_destructor_for__set_minimap_exit__);
    v6 = _S42;
  }
  if ( !(v6 & 4) )
  {
    _S42 = v6 | 4;
    UFG::qWiseSymbol::create_from_string(&set_rain_override, "set_rain_override");
    atexit(UFG::AudioTriggerRegion::HandleRefCountedEvent_::_7_::_dynamic_atexit_destructor_for__set_rain_override__);
  }
  v7 = UFG::AudioEventPropertyManager::Find(v15.mUID);
  v8 = v7;
  if ( !v3 )
  {
    if ( !--LODWORD(v7->mNULL.mParent) )
    {
      if ( UFG::TiDo::sm_ambiencesInfo )
      {
        v13 = UFG::qWiseSymbol::as_cstr_dbg((UFG::qWiseSymbol *)&v7->mNULL.mChild[0][2].mChild[1] + 1);
        v14 = UFG::qWiseSymbol::as_cstr_dbg(&v15);
        UFG::qPrintf("AudioTriggerRegion:: Triggering dynamic inverse event: %s %s\n", v14, v13);
      }
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::AmbienceAudio::m_instance->vfptr,
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
      v9 = UFG::qWiseSymbol::as_cstr_dbg(&v15);
      UFG::qPrintf("AudioTriggerRegion:: Triggering dynamic event: %s\n", v9);
    }
    UFG::AudioEntity::CreateAndPlayEvent(
      (UFG::AudioEntity *)&UFG::AmbienceAudio::m_instance->vfptr,
      v15.mUID,
      0i64,
      0,
      0i64);
  }
  ++LODWORD(v8->mNULL.mParent);
  if ( v15.mUID == set_minimap_enter.mUID )
  {
    v10 = UFG::AudioTriggerRegion::sm_interiorTransitionCount++ + 1;
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
  if ( v15.mUID == set_rain_override.mUID )
  {
    ++UFG::AudioTriggerRegion::sm_rainDrawOverride;
    if ( UFG::DoorStateManager::sm_active )
    {
      v12 = UFG::AudioTriggerRegion::sm_interiorTransitionCount > 0;
      if ( UFG::DoorStateManager::sm_inside )
      {
        if ( !v12 )
        {
          UFG::DoorStateManager::sm_inside = 0;
          UFG::DoorStateManager::SetDoorMix();
          goto LABEL_40;
        }
      }
      else if ( v12 )
      {
        UFG::DoorStateManager::sm_inside = 1;
        UFG::DoorStateManager::SetDoorMix();
        goto LABEL_40;
      }
      UFG::DoorStateManager::sm_inside = UFG::AudioTriggerRegion::sm_interiorTransitionCount > 0;
      UFG::DoorStateManager::SetDoorMix();
      goto LABEL_40;
    }
  }
LABEL_40:
  _((AMD_HD3D *)v15.mUID);
}

// File Line: 1617
// RVA: 0x59EAC0
char __fastcall UFG::AudioTriggerRegion::HandleMixRegionExit(UFG::AudioTriggerRegion *this)
{
  UFG::AudioTriggerRegion *v1; // rdi
  UFG::AudioTriggerRegion *v2; // rbx
  unsigned int v3; // edx
  UFG::AudioTriggerRegionTag *v4; // r9
  char result; // al
  UFG::TiDo *v6; // rax
  UFG::AudioTriggerRegionEvent thisEvent; // [rsp+28h] [rbp-40h]

  v1 = this;
  v2 = UFG::AudioTriggerRegion::FindInnermostRegionOfTypeContainingObject(
         this,
         &UFG::AudioListener::sm_pInstance->m_containmentInfo,
         eAudioTriggerRegionType_Mix);
  v3 = _S43_0;
  if ( !(_S43_0 & 1) )
  {
    _S43_0 |= 1u;
    UFG::qWiseSymbol::create_from_string(&ms_location, "ms_location");
    atexit(UFG::AudioTriggerRegion::HandleMixRegionExit_::_2_::_dynamic_atexit_destructor_for__ms_location__);
    v3 = _S43_0;
  }
  if ( v2
    && (v4 = (UFG::AudioTriggerRegionTag *)&v2->mTags.mNode.mNext[-1].mNext,
        v4 != (UFG::AudioTriggerRegionTag *)&v2->mNode.mUID) )
  {
    while ( v4->mAudioType != 11 || v4->mAudioModeUidOnEnter.mUID != ms_location.mUID )
    {
      v4 = (UFG::AudioTriggerRegionTag *)&v4->mNext[-1].mNext;
      if ( v4 == (UFG::AudioTriggerRegionTag *)&v2->mNode.mUID )
        goto LABEL_10;
    }
    UFG::AudioTriggerRegionEvent::AudioTriggerRegionEvent(&thisEvent, 0i64, v2, v4);
    UFG::AudioTriggerRegion::ApplyAudioZoneListener(v1, &thisEvent);
    thisEvent.vfptr = (UFG::AudioTriggerRegionEventVtbl *)&UFG::AudioTriggerRegionEvent::`vftable;
    _((AMD_HD3D *)thisEvent.mAudioModeUid.mUID);
    _((AMD_HD3D *)thisEvent.mAudioUidOnExit.mUID);
    _((AMD_HD3D *)thisEvent.mAudioUidOnEnter.mUID);
    result = 1;
  }
  else
  {
LABEL_10:
    if ( !(v3 & 2) )
    {
      _S43_0 = v3 | 2;
      UFG::qWiseSymbol::create_from_string(&gbl_exterior, "gbl_exterior");
      atexit(UFG::AudioTriggerRegion::HandleMixRegionExit_::_10_::_dynamic_atexit_destructor_for__gbl_exterior__);
    }
    v6 = UFG::TiDo::GetInstance();
    UFG::AudioEntity::SetWwiseState(v6, ms_location.mUID, gbl_exterior.mUID);
    result = 0;
  }
  return result;
}

// File Line: 1649
// RVA: 0x59E6D0
void __fastcall UFG::AudioTriggerRegion::HandleEnvironmentRegionExit(UFG::AudioTriggerRegion *this, UFG::AudioTriggerRegionEvent *thisEvent)
{
  UFG::AudioEntity *v2; // rsi
  UFG::AudioTriggerRegion *v3; // rbx
  UFG::AudioTriggerRegionEvent *v4; // rdi
  float v5; // xmm8_4
  float v6; // xmm6_4
  UFG::RegionContainmentInfo *v7; // rax
  UFG::AudioTriggerRegion *v8; // rax
  signed __int64 v9; // rbp
  signed __int64 v10; // rbx
  UFG::qSymbolUC *v11; // rax
  char *v12; // rax
  const char *v13; // rbx
  UFG::qSymbolUC *v14; // rax
  char *v15; // rax
  UFG::qSymbol result; // [rsp+68h] [rbp+10h]

  v2 = thisEvent->mTriggeringEntity;
  v3 = this;
  v4 = thisEvent;
  v5 = 0.0;
  v6 = 0.0;
  v7 = UFG::AudioEntity::GetContainmentInfo(v2);
  v8 = UFG::AudioTriggerRegion::FindInnermostRegionOfTypeContainingObject(v3, v7, eAudioTriggerRegionType_Environment);
  if ( v8 )
  {
    v9 = (signed __int64)&v8->mNode.mUID;
    v10 = (signed __int64)&v8->mTags.mNode.mNext[-1].mNext;
    if ( (unsigned int *)v10 != &v8->mNode.mUID )
    {
      do
      {
        if ( *(_DWORD *)(v10 + 24) == 8 && v4->mAudioUidOnEnter.mUID == *(_DWORD *)(v10 + 28) )
        {
          v6 = *(float *)(v10 + 48);
          v5 = *(float *)(v10 + 44);
          if ( v6 > 0.0 )
            UFG::AudioCategoryPropertyManager::SetAuxSendRtpcForEnvironment((UFG::qWiseSymbol *)(v10 + 28), v2);
        }
        v10 = *(_QWORD *)(v10 + 16) - 8i64;
      }
      while ( v10 != v9 );
    }
  }
  else
  {
    UFG::AudioCategoryPropertyManager::SetAuxSendRtpcForEnvironment((UFG::qWiseSymbol *)&default_symbol_0.mUID, v2);
  }
  if ( UFG::AudioEntity::sm_displayEnvironmentInfo )
  {
    v11 = (UFG::qSymbolUC *)UFG::AudioEntity::GetName(v4->mTriggeringEntity, &result);
    v12 = UFG::qSymbol::as_cstr_dbg(v11);
    if ( strstr(v12, UFG::AudioEntity::sm_environmentInfoFilter.mData) )
    {
      v13 = UFG::qWiseSymbol::as_cstr_dbg(&v4->mAudioUidOnEnter);
      v14 = (UFG::qSymbolUC *)UFG::AudioEntity::GetName((UFG::AudioEntity *)&v4->mRegionEntity->vfptr, &result);
      v15 = UFG::qSymbol::as_cstr_dbg(v14);
      UFG::qPrintf("AudioTriggerRegion: Exiting: %s, Removing environment: %s\n", v15, v13);
    }
  }
  UFG::AudioEntity::RemoveEnvironment(v2, v4->mAudioUidOnEnter.mUID, v5, v6);
}

// File Line: 1697
// RVA: 0x59E550
void __fastcall UFG::AudioTriggerRegion::HandleEnvironmentRegionEnter(UFG::AudioTriggerRegion *this, UFG::AudioTriggerRegionEvent *thisEvent)
{
  UFG::AudioEntity *v2; // rsi
  UFG::AudioTriggerRegion *v3; // rbx
  UFG::AudioTriggerRegionEvent *v4; // rdi
  float v5; // xmm7_4
  float wetLevel; // xmm8_4
  UFG::RegionContainmentInfo *v7; // rax
  UFG::AudioTriggerRegion *v8; // rax
  signed __int64 v9; // rbp
  signed __int64 v10; // rbx
  UFG::qSymbolUC *v11; // rax
  char *v12; // rax
  const char *v13; // rbx
  UFG::qSymbolUC *v14; // rax
  char *v15; // rax
  UFG::qSymbol result; // [rsp+78h] [rbp+10h]

  v2 = thisEvent->mTriggeringEntity;
  v3 = this;
  v4 = thisEvent;
  v5 = 0.0;
  wetLevel = 0.0;
  v7 = UFG::AudioEntity::GetContainmentInfo(v2);
  v8 = UFG::AudioTriggerRegion::FindInnermostRegionOfTypeContainingObject(v3, v7, eAudioTriggerRegionType_Environment);
  if ( v8 )
  {
    v9 = (signed __int64)&v8->mNode.mUID;
    v10 = (signed __int64)&v8->mTags.mNode.mNext[-1].mNext;
    if ( (unsigned int *)v10 != &v8->mNode.mUID )
    {
      do
      {
        if ( *(_DWORD *)(v10 + 24) == 8 )
        {
          if ( v4->mAudioUidOnEnter.mUID == *(_DWORD *)(v10 + 28) )
          {
            v5 = *(float *)(v10 + 44);
            wetLevel = *(float *)(v10 + 48);
          }
          if ( *(float *)(v10 + 48) > 0.0 )
            UFG::AudioCategoryPropertyManager::SetAuxSendRtpcForEnvironment((UFG::qWiseSymbol *)(v10 + 28), v2);
        }
        v10 = *(_QWORD *)(v10 + 16) - 8i64;
      }
      while ( v10 != v9 );
    }
  }
  else
  {
    UFG::AudioCategoryPropertyManager::SetAuxSendRtpcForEnvironment((UFG::qWiseSymbol *)&default_symbol_0.mUID, v2);
  }
  if ( UFG::AudioEntity::sm_displayEnvironmentInfo )
  {
    v11 = (UFG::qSymbolUC *)UFG::AudioEntity::GetName(v4->mTriggeringEntity, &result);
    v12 = UFG::qSymbol::as_cstr_dbg(v11);
    if ( strstr(v12, UFG::AudioEntity::sm_environmentInfoFilter.mData) )
    {
      v13 = UFG::qWiseSymbol::as_cstr_dbg(&v4->mAudioUidOnEnter);
      v14 = (UFG::qSymbolUC *)UFG::AudioEntity::GetName((UFG::AudioEntity *)&v4->mRegionEntity->vfptr, &result);
      v15 = UFG::qSymbol::as_cstr_dbg(v14);
      UFG::qPrintf("AudioTriggerRegion: Entering: %s, Adding environment: %s\n", v15, v13);
    }
  }
  UFG::AudioEntity::ApplyEnvironment(v2, v4->mAudioUidOnEnter.mUID, 1.0, v5, wetLevel, &v4->mAudioModeUid);
}

// File Line: 1815
// RVA: 0x598520
UFG::qSymbol *__fastcall UFG::AudioTriggerRegion::CheckRegionForDoors(UFG::qSymbol *result, UFG::qTreeRB<UFG::DoorNode,UFG::DoorNode,1> *doorTree)
{
  unsigned int v2; // ebx
  UFG::qSymbol *v3; // r15
  UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *v4; // r14
  Render::SkinningCacheNode *v5; // rax
  signed __int64 v6; // rsi
  UFG::qBaseNodeRB *v7; // rdx
  UFG::qBaseTreeRB *v8; // rax
  signed __int64 v9; // rbp
  UFG::qBaseTreeRB *v10; // rdi

  v2 = UFG::gNullQSymbol.mUID;
  v3 = result;
  v4 = (UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)doorTree;
  v5 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::AudioTriggerRegion::msAudioTriggerRegions);
  if ( v5 && (v6 = (signed __int64)&v5[-16].mCachedBufferPtr, v5 != (Render::SkinningCacheNode *)608) )
  {
    while ( 1 )
    {
      v7 = (UFG::qBaseNodeRB *)(v6 ? v6 + 608 : 0i64);
      v8 = UFG::qBaseTreeRB::GetNext(&UFG::AudioTriggerRegion::msAudioTriggerRegions.mTree, v7);
      v9 = (signed __int64)(v8 ? v8[-9].mNULL.mChild : 0i64);
      if ( *(_BYTE *)(v6 + 736) & 0x20 )
      {
        v10 = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(v4);
        if ( v10 )
          break;
      }
LABEL_14:
      v6 = v9;
      if ( !v9 )
        goto LABEL_15;
    }
    while ( !UFG::TriggerRegion::IsHitPoint(
               (UFG::TriggerRegion *)v6,
               (UFG::qVector3 *)((char *)&v10->mNULL.mParent + 4))
         || v2 != UFG::gNullQSymbol.mUID )
    {
      v10 = UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)v4, &v10->mRoot);
      if ( !v10 )
        goto LABEL_14;
    }
    v3->mUID = (unsigned int)v10->mNULL.mParent;
  }
  else
  {
LABEL_15:
    v3->mUID = v2;
  }
  return v3;
}

// File Line: 1848
// RVA: 0x592EA0
void __fastcall UFG::AudioTriggerRegionEvent::AudioTriggerRegionEvent(UFG::AudioTriggerRegionEvent *this, UFG::AudioEntity *triggeringEntity, UFG::AudioTriggerRegion *regionEntity, UFG::AudioTriggerRegionTag *tag)
{
  UFG::qWiseSymbol *v4; // r15
  UFG::AudioTriggerRegion *v5; // r14
  UFG::AudioEntity *v6; // rbp
  UFG::AudioTriggerRegionEvent *v7; // r12

  v4 = (UFG::qWiseSymbol *)tag;
  v5 = regionEntity;
  v6 = triggeringEntity;
  v7 = this;
  this->vfptr = (UFG::AudioTriggerRegionEventVtbl *)&UFG::AudioTriggerRegionEvent::`vftable;
  this->mAudioUidOnEnter.mUID = -1;
  _((AMD_HD3D *)0xFFFFFFFFi64);
  v7->mAudioUidOnExit.mUID = -1;
  _((AMD_HD3D *)0xFFFFFFFFi64);
  v7->mAudioModeUid.mUID = -1;
  _((AMD_HD3D *)0xFFFFFFFFi64);
  v7->mTriggeringEntity = v6;
  v7->mRegionEntity = v5;
  v7->mAudioType = v4[6].mUID;
  UFG::qWiseSymbol::operator=(&v7->mAudioUidOnEnter, v4 + 7);
  UFG::qWiseSymbol::operator=(&v7->mAudioUidOnExit, v4 + 8);
  UFG::qWiseSymbol::operator=(&v7->mAudioModeUid, v4 + 9);
  LODWORD(v7->mAudioRtpcVal) = v4[10];
  LODWORD(v7->mAudioDryLevel) = v4[11];
  LODWORD(v7->mAudioWetLevel) = v4[12];
}

