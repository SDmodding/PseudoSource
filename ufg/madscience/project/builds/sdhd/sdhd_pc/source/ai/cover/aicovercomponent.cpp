// File Line: 29
// RVA: 0x14AEA00
__int64 dynamic_initializer_for__UFG::AICoverComponent::s_AICoverComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::AICoverComponent::s_AICoverComponentList__);
}

// File Line: 30
// RVA: 0x35D8A0
UFG::ComponentIDDesc *__fastcall UFG::AICoverComponent::GetDesc(UFG::AICoverComponent *this)
{
  return &UFG::AICoverComponent::_TypeIDesc;
}

// File Line: 73
// RVA: 0x32AEF0
void __fastcall UFG::AICoverComponent::AICoverComponent(UFG::AICoverComponent *this, unsigned int name_uid, UFG::qPropertySet *properties, bool startSuspended)
{
  UFG::AICoverComponent *v4; // rbx
  UFG::qNode<UFG::AICoverComponent,UFG::AICoverComponent> *v5; // rdx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v6; // ST28_8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v7; // ST28_8
  UFG::qNode<UFG::AICoverComponent,UFG::AICoverComponent> *v8; // rax

  v4 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name_uid);
  v5 = (UFG::qNode<UFG::AICoverComponent,UFG::AICoverComponent> *)&v4->mPrev;
  v5->mPrev = v5;
  v5->mNext = v5;
  v4->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AICoverComponent::`vftable';
  v4->m_pQuery = 0i64;
  v4->m_pCoverObject = 0i64;
  v4->m_pTargetedCoverPosition = 0i64;
  v4->m_pProbeCoverObject = 0i64;
  v4->m_ePopoutSide = 0;
  v6 = &v4->m_pSimTargetSync;
  v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  v6->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  v4->m_pSimTargetSync.m_pPointer = 0i64;
  v7 = &v4->m_pSimTargetPopout;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v7->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v4->m_pSimTargetPopout.m_pPointer = 0i64;
  v4->m_iSyncBoneID = -1;
  v8 = UFG::AICoverComponent::s_AICoverComponentList.mNode.mPrev;
  UFG::AICoverComponent::s_AICoverComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::AICoverComponent,UFG::AICoverComponent> *)&v4->mPrev;
  v5->mPrev = v8;
  v4->mNext = (UFG::qNode<UFG::AICoverComponent,UFG::AICoverComponent> *)&UFG::AICoverComponent::s_AICoverComponentList;
  UFG::AICoverComponent::s_AICoverComponentList.mNode.mPrev = (UFG::qNode<UFG::AICoverComponent,UFG::AICoverComponent> *)&v4->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v4->vfptr,
    UFG::AICoverComponent::_AICoverComponentTypeUID,
    "AICoverComponent");
}

// File Line: 90
// RVA: 0x333CB0
void __fastcall UFG::AICoverComponent::~AICoverComponent(UFG::AICoverComponent *this)
{
  UFG::AICoverComponent *v1; // rbx
  UFG::qNode<UFG::AICoverComponent,UFG::AICoverComponent> *v2; // r8
  UFG::qNode<UFG::AICoverComponent,UFG::AICoverComponent> *v3; // rcx
  UFG::qNode<UFG::AICoverComponent,UFG::AICoverComponent> *v4; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v5; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v10; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::AICoverComponent,UFG::AICoverComponent> *v15; // rcx
  UFG::qNode<UFG::AICoverComponent,UFG::AICoverComponent> *v16; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AICoverComponent::`vftable';
  UFG::AICoverComponent::CancelQuery(this);
  UFG::AICoverComponent::ClearCoverObjects(v1);
  UFG::AICoverComponent::RemoveSimTargets(v1);
  if ( v1 == UFG::AICoverComponent::s_AICoverComponentpCurrentIterator )
    UFG::AICoverComponent::s_AICoverComponentpCurrentIterator = (UFG::AICoverComponent *)&v1->mPrev[-4];
  v2 = (UFG::qNode<UFG::AICoverComponent,UFG::AICoverComponent> *)&v1->mPrev;
  v3 = v1->mPrev;
  v4 = v1->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = &v1->m_pSimTargetPopout;
  if ( v1->m_pSimTargetPopout.m_pPointer )
  {
    v6 = v5->mPrev;
    v7 = v1->m_pSimTargetPopout.mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mPrev;
    v1->m_pSimTargetPopout.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->m_pSimTargetPopout.mPrev;
  }
  v1->m_pSimTargetPopout.m_pPointer = 0i64;
  v8 = v5->mPrev;
  v9 = v1->m_pSimTargetPopout.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v1->m_pSimTargetPopout.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->m_pSimTargetPopout.mPrev;
  v10 = &v1->m_pSimTargetSync;
  if ( v1->m_pSimTargetSync.m_pPointer )
  {
    v11 = v10->mPrev;
    v12 = v1->m_pSimTargetSync.mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    v10->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v10->mPrev;
    v1->m_pSimTargetSync.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->m_pSimTargetSync.mPrev;
  }
  v1->m_pSimTargetSync.m_pPointer = 0i64;
  v13 = v10->mPrev;
  v14 = v1->m_pSimTargetSync.mNext;
  v13->mNext = v14;
  v14->mPrev = v13;
  v10->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v10->mPrev;
  v1->m_pSimTargetSync.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->m_pSimTargetSync.mPrev;
  v15 = v2->mPrev;
  v16 = v1->mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  v2->mPrev = v2;
  v1->mNext = (UFG::qNode<UFG::AICoverComponent,UFG::AICoverComponent> *)&v1->mPrev;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 101
// RVA: 0x3782F0
void __fastcall UFG::AICoverComponent::OnAttach(UFG::AICoverComponent *this, UFG::SimObject *object)
{
  UFG::AICoverComponent *v2; // rdi
  UFG::CharacterAnimationComponent *v3; // rbx
  UFG::SimObjectCVBase *v4; // rcx
  unsigned __int16 v5; // dx
  UFG::CharacterAnimationComponent *v6; // rax
  Creature *v7; // rcx
  signed int v8; // eax

  v2 = this;
  v3 = 0i64;
  this->m_pQuery = 0i64;
  this->m_pCoverObject = 0i64;
  this->m_pTargetedCoverPosition = 0i64;
  this->m_pProbeCoverObject = 0i64;
  this->m_pCurrentCoverPosition = 0i64;
  this->m_pSyncCoverPosition = 0i64;
  *(_QWORD *)&this->m_iHoldCoverPositionRefs = 0i64;
  this->m_ePopoutSide = 0;
  UFG::AICoverComponent::GenerateSimTargets(this);
  v4 = (UFG::SimObjectCVBase *)v2->m_pSimObject;
  if ( v4 )
  {
    v5 = v4->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v4);
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v6 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v4);
      }
      else if ( (v5 >> 12) & 1 )
      {
        v6 = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   (UFG::SimObjectGame *)&v4->vfptr,
                                                   UFG::CharacterAnimationComponent::_TypeUID);
      }
      else
      {
        v6 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                   (UFG::SimObject *)&v4->vfptr,
                                                   UFG::CharacterAnimationComponent::_TypeUID);
      }
    }
    else
    {
      v6 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v4);
    }
    v3 = v6;
  }
  if ( !(_S37 & 1) )
  {
    _S37 |= 1u;
    UFG::qSymbolUC::create_from_string(&symSync01, "Sync01");
    atexit(UFG::AICoverComponent::OnAttach_::_2_::_dynamic_atexit_destructor_for__symSync01__);
  }
  v7 = v3->mCreature;
  if ( v7 )
  {
    if ( v7->mPose.mRigHandle.mData )
      v8 = Skeleton::GetBoneID(v7->mPose.mRigHandle.mUFGSkeleton, symSync01.mUID);
    else
      v8 = -1;
    v2->m_iSyncBoneID = v8;
  }
}

// File Line: 137
// RVA: 0x379890
void __fastcall UFG::AICoverComponent::OnDetach(UFG::AICoverComponent *this)
{
  UFG::AICoverComponent *v1; // rbx

  v1 = this;
  UFG::AICoverComponent::CancelQuery(this);
  UFG::AICoverComponent::ClearCoverObjects(v1);
  UFG::AICoverComponent::RemoveSimTargets(v1);
}

// File Line: 147
// RVA: 0x364D20
bool __fastcall UFG::AICoverComponent::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SceneObjectProperties *v1; // rax
  UFG::qPropertySet *v2; // rcx

  v1 = pSceneObj;
  v2 = pSceneObj->mpWritableProperties;
  if ( !v2 )
    v2 = v1->mpConstProperties;
  return UFG::qPropertySet::GetParentFromName(v2, (UFG::qSymbol *)&SimSymX_propset_componentAICover.mUID, DEPTH_RECURSE) != 0i64;
}

// File Line: 153
// RVA: 0x37E330
UFG::SimComponent *__fastcall UFG::AICoverComponent::PropertiesOnActivate(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SceneObjectProperties *v1; // rbx
  UFG::qMemoryPool *v2; // rax
  UFG::allocator::free_link *v3; // rax
  UFG::qPropertySet *v4; // r8
  UFG::SimComponent *v5; // rax
  UFG::SimComponent *v6; // rdi
  UFG::SimObjectModifier v8; // [rsp+38h] [rbp-30h]

  v1 = pSceneObj;
  v2 = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(v2, 0xC8ui64, "AICoverComponent", 0i64, 1u);
  if ( v3 )
  {
    v4 = v1->mpWritableProperties;
    if ( !v4 )
      v4 = v1->mpConstProperties;
    UFG::AICoverComponent::AICoverComponent((UFG::AICoverComponent *)v3, v1->m_NameUID, v4, 0);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v8, v1->m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v8, v6, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v8);
  UFG::SimObjectModifier::~SimObjectModifier(&v8);
  return v6;
}

// File Line: 160
// RVA: 0x38B2A0
void __fastcall UFG::AICoverComponent::Update(UFG::AICoverComponent *this, float deltaTime)
{
  UFG::AICoverComponent *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rax
  UFG::CoverObjectBase *v6; // rcx
  unsigned int v7; // eax
  float *v8; // rax
  __int64 v9; // rax
  __int64 v10; // rdi
  bool v11; // zf
  UFG::qVector3 result; // [rsp+28h] [rbp-30h]
  char v13; // [rsp+38h] [rbp-20h]

  v2 = this;
  v3 = (UFG::SimObjectGame *)this->m_pSimObject;
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v5 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::HealthComponent::_TypeUID)) : (v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HealthComponent::_TypeUID))) : (v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HealthComponent::_TypeUID))) : (v5 = v3->m_Components.p[6].m_pComponent)) : (v5 = v3->m_Components.p[6].m_pComponent),
        v5 && !BYTE4(v5[1].m_BoundComponentHandles.mNode.mPrev)) )
  {
    UFG::AICoverComponent::ValidateCover(v2, 1);
    v6 = v2->m_pCoverObject;
    if ( v6 )
    {
      if ( (*((unsigned __int8 (__cdecl **)(UFG::CoverObjectBase *))&v6->vfptr->__vecDelDtor + 2))(v6) )
      {
        v7 = _S38;
        if ( !(_S38 & 1) )
        {
          v7 = _S38 | 1;
          _S38 |= 1u;
          kfSyncDist2 = FLOAT_0_25;
        }
        if ( !(v7 & 2) )
        {
          _S38 = v7 | 2;
          kfSyncDistMax = FLOAT_0_42249995;
        }
        UFG::AICoverComponent::GetActorPosition(v2, &result);
        v8 = (float *)v2->m_pCoverObject->vfptr->GetSyncPos(v2->m_pCoverObject, (UFG::qVector3 *)&v13);
        if ( v2->m_pCurrentCoverPosition
          || (float)((float)((float)(result.y - v8[1]) * (float)(result.y - v8[1]))
                   + (float)((float)(result.x - *v8) * (float)(result.x - *v8))) < kfSyncDist2 )
        {
          v9 = ((__int64 (__fastcall *)(UFG::CoverObjectBase *, UFG::qVector3 *, _QWORD))v2->m_pCoverObject->vfptr->GetCoverPosition)(
                 v2->m_pCoverObject,
                 &result,
                 0i64);
          v10 = v9;
          if ( v9 )
          {
            ++*(_DWORD *)(v9 + 8);
            v2->vfptr[15].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v2->vfptr, v9);
            v11 = (*(_DWORD *)(v10 + 8))-- == 1;
            if ( v11 )
              (**(void (__fastcall ***)(__int64, signed __int64))v10)(v10, 1i64);
          }
          else
          {
            v2->vfptr[15].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v2->vfptr, 0);
          }
        }
        UFG::AICoverComponent::UpdateSimTargets(v2);
      }
      else
      {
        UFG::AICoverComponent::ClearCoverObjects(v2);
      }
    }
    else
    {
      v2->vfptr[15].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v2->vfptr, 0);
    }
    UFG::AICoverComponent::SetSyncCoverPosition(v2, v2->m_pCurrentCoverPosition, 0);
  }
  else
  {
    UFG::AICoverComponent::CancelQuery(v2);
    UFG::AICoverComponent::ClearCoverObjects(v2);
  }
}

// File Line: 224
// RVA: 0x394140
void __fastcall UFG::AICoverComponent::UpdateAll(float deltaTime)
{
  UFG::qNode<UFG::AICoverComponent,UFG::AICoverComponent> *v1; // rcx
  UFG::qList<UFG::AICoverComponent,UFG::AICoverComponent,1,0> *v2; // rbx

  v1 = UFG::AICoverComponent::s_AICoverComponentList.mNode.mNext - 4;
  if ( (UFG::qList<UFG::AICoverComponent,UFG::AICoverComponent,1,0> *)&UFG::AICoverComponent::s_AICoverComponentList.mNode.mNext[-4] != &UFG::AICoverComponent::s_AICoverComponentList - 4 )
  {
    do
    {
      v2 = (UFG::qList<UFG::AICoverComponent,UFG::AICoverComponent,1,0> *)&v1[4].mNext[-4];
      if ( ((_QWORD)v1[2].mPrev & 3) == 1 )
        ((void (*)(void))v1->mPrev[7].mPrev)();
      v1 = &v2->mNode;
    }
    while ( v2 != &UFG::AICoverComponent::s_AICoverComponentList - 4 );
  }
}

// File Line: 236
// RVA: 0x34CC90
void __fastcall UFG::AICoverComponent::CancelQuery(UFG::AICoverComponent *this)
{
  UFG::AICoverQuery *v1; // r8
  UFG::AICoverComponent *v2; // rbx
  UFG::qNode<UFG::AICoverQuery,UFG::AICoverQuery> *v3; // rdx
  UFG::qNode<UFG::AICoverQuery,UFG::AICoverQuery> *v4; // rax
  UFG::qNode<UFG::AICoverQuery,UFG::AICoverQuery> *v5; // r8
  signed __int64 v6; // rcx
  bool v7; // zf
  UFG::AICoverQuery *v8; // rcx

  v1 = this->m_pQuery;
  v2 = this;
  if ( v1 )
  {
    v3 = v1->mPrev;
    v4 = v1->mNext;
    v5 = (UFG::qNode<UFG::AICoverQuery,UFG::AICoverQuery> *)&v1->mPrev;
    v3->mNext = v4;
    v4->mPrev = v3;
    v6 = (signed __int64)&v5[-2];
    v5->mPrev = v5;
    v5->mNext = v5;
    if ( v5 != (UFG::qNode<UFG::AICoverQuery,UFG::AICoverQuery> *)32 )
    {
      v7 = (*(_DWORD *)(v6 + 24))-- == 1;
      if ( v7 )
        (**(void (__fastcall ***)(signed __int64, signed __int64))v6)(v6, 1i64);
    }
    v8 = v2->m_pQuery;
    v7 = v8->m_iRefCount-- == 1;
    if ( v7 )
      v8->vfptr->__vecDelDtor((UFG::AIQuery *)&v8->vfptr, 1u);
    v2->m_pQuery = 0i64;
  }
}

// File Line: 248
// RVA: 0x388CE0
char __fastcall UFG::AICoverComponent::StartCoverSearch(UFG::AICoverComponent *this, UFG::AICoverSearchParams *pSearchParams, bool bOverridePrevious)
{
  UFG::AICoverSearchParams *v3; // rsi
  UFG::AICoverComponent *v4; // rdi
  UFG::allocator::free_link *v6; // rax
  UFG::AICoverQuery *v7; // rax
  UFG::AICoverQuery *v8; // rbp
  UFG::AICoverSearchParams *v9; // rbx
  bool v10; // zf
  hkSeekableStreamReader *v11; // rax
  UFG::AICoverQuery *v12; // rcx
  UFG::AICoverQuery *v13; // rax
  UFG::AIQueryManager *v14; // rdx
  UFG::qNode<UFG::AICoverQuery,UFG::AICoverQuery> *v15; // rcx
  UFG::qNode<UFG::AICoverQuery,UFG::AICoverQuery> *v16; // rax

  v3 = pSearchParams;
  v4 = this;
  if ( this->m_pQuery )
  {
    if ( !bOverridePrevious )
      return 0;
    UFG::AICoverComponent::CancelQuery(this);
  }
  v6 = UFG::qMalloc(0x130ui64, "AICoverQuery", 0i64);
  if ( v6 )
    UFG::AICoverQuery::AICoverQuery((UFG::AICoverQuery *)v6);
  else
    v7 = 0i64;
  v4->m_pQuery = v7;
  ++v7->m_iRefCount;
  v8 = v4->m_pQuery;
  v9 = v8->m_pSearchParams;
  if ( v9 )
  {
    v10 = v9->m_iRefCount-- == 1;
    if ( v10 )
    {
      UFG::AICoverSearchParams::~AICoverSearchParams(v9);
      operator delete[](v9);
    }
    v8->m_pSearchParams = 0i64;
  }
  if ( v3 )
  {
    v8->m_pSearchParams = v3;
    ++v3->m_iRefCount;
  }
  v11 = Assembly::GetRCX(v4);
  v12 = v4->m_pQuery;
  v12->m_queryFinishedDelegate.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::AICoverComponent::SearchCompleteCallback;
  v12->m_queryFinishedDelegate.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)v11;
  v13 = v4->m_pQuery;
  v14 = UFG::AIQueryManager::ms_pInstance;
  ++v13->m_iRefCount;
  v15 = (UFG::qNode<UFG::AICoverQuery,UFG::AICoverQuery> *)&v13->mPrev;
  v16 = v14->m_listpCoverQueries.mNode.mPrev;
  v16->mNext = v15;
  v15->mPrev = v16;
  v15->mNext = &v14->m_listpCoverQueries.mNode;
  v14->m_listpCoverQueries.mNode.mPrev = v15;
  return 1;
}

// File Line: 278
// RVA: 0x383F20
void __fastcall UFG::AICoverComponent::SearchCompleteCallback(UFG::AICoverComponent *this, UFG::AICoverQuery *pQuery)
{
  UFG::CoverPosition *v2; // rdi
  UFG::AICoverQuery *v3; // rsi
  UFG::AICoverComponent *v4; // rbx
  UFG::CoverObjectBase *v5; // rcx
  bool v6; // zf
  UFG::CoverPosition *v7; // rcx
  UFG::SimObjectGame *v8; // rcx
  UFG::NavComponent *v9; // rax
  unsigned __int16 v10; // dx
  UFG::AICoverQuery *v11; // rcx

  v2 = pQuery->m_pBestCoverPosition;
  v3 = pQuery;
  v4 = this;
  if ( v2 && v2->vfptr->CanUse((UFG::CoverObjectBase *)&v2->vfptr, this->m_pSimObject) )
  {
    v5 = v4->m_pCoverObject;
    if ( v5 )
    {
      v6 = v5->m_iRefCount-- == 1;
      if ( v6 )
        v5->vfptr->__vecDelDtor(v5, 1u);
      v4->m_pCoverObject = 0i64;
    }
    if ( v2->vfptr->CanUse((UFG::CoverObjectBase *)&v2->vfptr, v4->m_pSimObject) )
    {
      v4->m_pCoverObject = (UFG::CoverObjectBase *)&v2->vfptr;
      ++v2->m_iRefCount;
    }
    v7 = v4->m_pCurrentCoverPosition;
    if ( v7 && v4->m_pCoverObject && !((unsigned __int8 (*)(void))v7->vfptr->operator==)() )
      v4->vfptr[15].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v4->vfptr, 0);
    UFG::AICoverComponent::SetTargetedCoverPosition(v4, v2);
    if ( !v3->m_pSearchParams->m_bUseCombatRegionDestination && v3->m_pFoundPath.m_pNavPath )
    {
      v8 = (UFG::SimObjectGame *)v4->m_pSimObject;
      if ( v8 )
      {
        v10 = v8->m_Flags;
        if ( (v10 >> 14) & 1 )
        {
          v9 = (UFG::NavComponent *)v8->m_Components.p[36].m_pComponent;
        }
        else if ( (v10 & 0x8000u) == 0 )
        {
          if ( (v10 >> 13) & 1 )
          {
            v9 = (UFG::NavComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::NavComponent::_TypeUID);
          }
          else if ( (v10 >> 12) & 1 )
          {
            v9 = (UFG::NavComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::NavComponent::_TypeUID);
          }
          else
          {
            v9 = (UFG::NavComponent *)UFG::SimObject::GetComponentOfType(
                                        (UFG::SimObject *)&v8->vfptr,
                                        UFG::NavComponent::_TypeUID);
          }
        }
        else
        {
          v9 = (UFG::NavComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::NavComponent::_TypeUID);
        }
      }
      else
      {
        v9 = 0i64;
      }
      UFG::NavComponent::InjectPath(v9, &v3->m_npQueryCenter, &v2->m_NavPosition, v3->m_pFoundPath.m_pNavPath);
    }
  }
  v11 = v4->m_pQuery;
  v6 = v11->m_iRefCount-- == 1;
  if ( v6 )
    v11->vfptr->__vecDelDtor((UFG::AIQuery *)&v11->vfptr, 1u);
  v4->m_pQuery = 0i64;
}

// File Line: 321
// RVA: 0x387DB0
void __fastcall UFG::AICoverComponent::SetTargetedCoverPosition(UFG::AICoverComponent *this, UFG::CoverPosition *pCoverPosition)
{
  UFG::CoverPosition *v2; // rbx
  UFG::AICoverComponent *v3; // rdi
  UFG::SimObjectGame *v4; // rcx
  UFG::TargetingSystemBaseComponent *v5; // rsi
  unsigned __int16 v6; // dx
  UFG::SimComponent *v7; // rax
  UFG::CoverPosition *v8; // rcx
  UFG::CoverPosition *v9; // rcx
  bool v10; // zf

  v2 = pCoverPosition;
  v3 = this;
  if ( pCoverPosition
    && (!(*((unsigned __int8 (__fastcall **)(UFG::CoverPosition *))&pCoverPosition->vfptr->__vecDelDtor + 2))(pCoverPosition)
     || !v2->vfptr->CanUse((UFG::CoverObjectBase *)&v2->vfptr, v3->m_pSimObject)) )
  {
    v2 = 0i64;
  }
  if ( v2 != v3->m_pTargetedCoverPosition )
  {
    v4 = (UFG::SimObjectGame *)v3->m_pSimObject;
    if ( v4 )
    {
      v6 = v4->m_Flags;
      if ( (v6 >> 14) & 1 )
      {
        v5 = (UFG::TargetingSystemBaseComponent *)v4->m_Components.p[20].m_pComponent;
      }
      else if ( (v6 & 0x8000u) == 0 )
      {
        if ( (v6 >> 13) & 1 )
        {
          v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        else if ( (v6 >> 12) & 1 )
        {
          v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        else
        {
          v7 = UFG::SimObject::GetComponentOfType(
                 (UFG::SimObject *)&v4->vfptr,
                 UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        v5 = (UFG::TargetingSystemBaseComponent *)v7;
      }
      else
      {
        v5 = (UFG::TargetingSystemBaseComponent *)v4->m_Components.p[20].m_pComponent;
      }
    }
    else
    {
      v5 = 0i64;
    }
    v8 = v3->m_pTargetedCoverPosition;
    if ( v8 )
    {
      ((void (*)(void))v8->vfptr->RemoveUser)();
      v9 = v3->m_pTargetedCoverPosition;
      v10 = v9->m_iRefCount-- == 1;
      if ( v10 )
        v9->vfptr->__vecDelDtor((UFG::CoverObjectBase *)&v9->vfptr, 1u);
      v3->m_pTargetedCoverPosition = 0i64;
    }
    else
    {
      UFG::TargetingSystemBaseComponent::SetTarget(v5, eTARGET_TYPE_COVER_OBJECT, v3->m_pSimTargetSync.m_pPointer);
      UFG::TargetingSystemBaseComponent::SetTarget(v5, eTARGET_TYPE_COVER_POPOUT, v3->m_pSimTargetPopout.m_pPointer);
    }
    if ( v2 )
    {
      ++v2->m_iRefCount;
      v2->vfptr->AddUser((UFG::CoverObjectBase *)&v2->vfptr, v3->m_pSimObject);
      v3->m_pTargetedCoverPosition = v2;
    }
    else
    {
      UFG::TargetingSystemBaseComponent::SetTarget(v5, eTARGET_TYPE_COVER_OBJECT, 0i64);
      UFG::TargetingSystemBaseComponent::SetTarget(v5, eTARGET_TYPE_COVER_POPOUT, 0i64);
    }
  }
  UFG::AICoverComponent::UpdateSimTargets(v3);
}

// File Line: 360
// RVA: 0x3851C0
void __fastcall UFG::AICoverComponent::SetCurrentCoverPosition(UFG::AICoverComponent *this, UFG::CoverPosition *pCoverPosition)
{
  UFG::CoverPosition *v2; // rbx
  UFG::AICoverComponent *v3; // rdi
  UFG::CoverPosition *v4; // rcx
  bool v5; // zf

  v2 = pCoverPosition;
  v3 = this;
  if ( this->m_pCurrentCoverPosition )
  {
    if ( pCoverPosition
      && (!pCoverPosition->m_NavPosition.m_bValid
       || !UFG::HavokAIUtilGame::IsValidKey(
             pCoverPosition->m_NavPosition.m_packedKey,
             pCoverPosition->m_NavPosition.m_aiMeshUid)) )
    {
      UFG::CoverPosition::SetNavPosition(v2, &v3->m_pCurrentCoverPosition->m_NavPosition);
    }
    v4 = v3->m_pCurrentCoverPosition;
    v5 = v4->m_iRefCount-- == 1;
    if ( v5 )
      v4->vfptr->__vecDelDtor((UFG::CoverObjectBase *)&v4->vfptr, 1u);
    v3->m_pCurrentCoverPosition = 0i64;
  }
  if ( v2 )
  {
    v3->m_pCurrentCoverPosition = v2;
    ++v2->m_iRefCount;
  }
}

// File Line: 399
// RVA: 0x387C00
void __fastcall UFG::AICoverComponent::SetSyncCoverPosition(UFG::AICoverComponent *this, UFG::CoverPosition *pSyncCoverPosition, bool bIgnoreHoldPosition)
{
  UFG::CoverPosition *v3; // rdi
  UFG::AICoverComponent *v4; // rbx
  UFG::CoverPosition *v5; // rcx
  bool v6; // zf
  UFG::SimObjectGame *v7; // rcx
  unsigned __int16 v8; // dx
  UFG::WorldContextComponent *v9; // rax

  v3 = pSyncCoverPosition;
  v4 = this;
  if ( bIgnoreHoldPosition
    || !this->m_iHoldCoverPositionRefs
    || !this->m_pSyncCoverPosition
    || this->m_iAllowHoldCoverPositionUpdateRefs > 0
    && pSyncCoverPosition
    && (*((unsigned __int8 (__fastcall **)(UFG::CoverPosition *))&pSyncCoverPosition->vfptr[1].__vecDelDtor + 1))(pSyncCoverPosition) )
  {
    v5 = v4->m_pSyncCoverPosition;
    if ( v5 )
    {
      v6 = v5->m_iRefCount-- == 1;
      if ( v6 )
        v5->vfptr->__vecDelDtor((UFG::CoverObjectBase *)&v5->vfptr, 1u);
      v4->m_pSyncCoverPosition = 0i64;
    }
    if ( v3 )
    {
      v4->m_pSyncCoverPosition = v3;
      ++v3->m_iRefCount;
    }
    v7 = (UFG::SimObjectGame *)v4->m_pSimObject;
    if ( v7 )
    {
      v8 = v7->m_Flags;
      if ( (v8 >> 14) & 1 )
      {
        v9 = (UFG::WorldContextComponent *)v7->m_Components.p[28].m_pComponent;
      }
      else if ( (v8 & 0x8000u) == 0 )
      {
        if ( (v8 >> 13) & 1 )
        {
          v9 = (UFG::WorldContextComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               v7,
                                               UFG::WorldContextComponent::_TypeUID);
        }
        else if ( (v8 >> 12) & 1 )
        {
          v9 = (UFG::WorldContextComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               v7,
                                               UFG::WorldContextComponent::_TypeUID);
        }
        else
        {
          v9 = (UFG::WorldContextComponent *)UFG::SimObject::GetComponentOfType(
                                               (UFG::SimObject *)&v7->vfptr,
                                               UFG::WorldContextComponent::_TypeUID);
        }
      }
      else
      {
        v9 = (UFG::WorldContextComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             v7,
                                             UFG::WorldContextComponent::_TypeUID);
      }
      if ( v9 )
        UFG::WorldContextComponent::SetCoverPosition(v9, v4->m_pSyncCoverPosition);
    }
  }
}

// File Line: 431
// RVA: 0x35B720
UFG::CoverPosition *__fastcall UFG::AICoverComponent::GetCoverObjectFromEnum(UFG::AICoverComponent *this, UFG::eCoverComponentObjectEnum eObjectType)
{
  __int32 v2; // edx
  int v3; // edx
  int v4; // edx

  v2 = eObjectType - 1;
  if ( !v2 )
    return this->m_pSyncCoverPosition;
  v3 = v2 - 1;
  if ( !v3 )
    return (UFG::CoverPosition *)this->m_pProbeCoverObject;
  v4 = v3 - 1;
  if ( !v4 )
    return this->m_pTargetedCoverPosition;
  if ( v4 == 1 )
    return this->m_pCurrentCoverPosition;
  return 0i64;
}

// File Line: 454
// RVA: 0x359520
void __fastcall UFG::AICoverComponent::GenerateSimTargets(UFG::AICoverComponent *this)
{
  UFG::AICoverComponent *v1; // rbx
  char dest; // [rsp+20h] [rbp-108h]
  UFG::qSymbol result; // [rsp+130h] [rbp+8h]
  UFG::qSymbol symbolName; // [rsp+138h] [rbp+10h]

  v1 = this;
  UFG::AICoverComponent::RemoveSimTargets(this);
  UFG::qSPrintf(&dest, "CoverObject_%d", v1->m_pSimObject->mNode.mUID);
  UFG::qSymbol::create_from_string(&result, &dest);
  UFG::AICoverComponent::GenerateSimTarget(v1, &result, &v1->m_pSimTargetSync);
  UFG::qSPrintf(&dest, "CoverPopout_%d", v1->m_pSimObject->mNode.mUID);
  UFG::qSymbol::create_from_string(&symbolName, &dest);
  UFG::AICoverComponent::GenerateSimTarget(v1, &symbolName, &v1->m_pSimTargetPopout);
}

// File Line: 470
// RVA: 0x3593D0
void __fastcall UFG::AICoverComponent::GenerateSimTarget(UFG::AICoverComponent *this, UFG::qSymbol *symbolName, UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *destPointer)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v3; // rbx
  UFG::SimObject *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qMemoryPool *v9; // rax
  UFG::allocator::free_link *v10; // rsi
  unsigned int v11; // edi
  unsigned int v12; // eax
  UFG::SimComponent *v13; // rax
  UFG::SimComponent *v14; // rsi
  UFG::SimObject *v15; // rdx
  unsigned __int16 v16; // cx
  UFG::SimObjectModifier v17; // [rsp+38h] [rbp-30h]

  v3 = destPointer;
  v4 = UFG::Simulation::CreateSimObject(&UFG::gSim, symbolName);
  if ( v3->m_pPointer )
  {
    v5 = v3->mPrev;
    v6 = v3->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->mPrev;
    v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  }
  v3->m_pPointer = v4;
  if ( v4 )
  {
    v7 = &v4->m_SafePointerList.mNode;
    v8 = v4->m_SafePointerList.mNode.mPrev;
    v8->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->mPrev;
    v3->mPrev = v8;
    v3->mNext = v7;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  }
  v9 = UFG::GetSimulationMemoryPool();
  v10 = UFG::qMemoryPool::Allocate(v9, 0x110ui64, "CoverObjectBase Sim Target TransformNodeComponent", 0i64, 1u);
  v11 = -1;
  if ( v10 )
  {
    v12 = UFG::qStringHash32("TransformNodeComponent", 0xFFFFFFFF);
    UFG::TransformNodeComponent::TransformNodeComponent((UFG::TransformNodeComponent *)v10, v12, 0i64, 0);
    v14 = v13;
  }
  else
  {
    v14 = 0i64;
  }
  v15 = v3->m_pPointer;
  v16 = v15->m_Flags;
  if ( (v16 >> 14) & 1 || (v16 & 0x8000u) != 0 || (v16 >> 13) & 1 )
  {
    v11 = 2;
  }
  else if ( (v16 >> 12) & 1 )
  {
    v11 = 1;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v17, v15, 1);
  UFG::SimObjectModifier::AttachComponent(&v17, v14, v11);
  UFG::SimObjectModifier::Close(&v17);
  UFG::SimObjectModifier::~SimObjectModifier(&v17);
}

// File Line: 479
// RVA: 0x398D00
void __fastcall UFG::AICoverComponent::UpdateSimTargets(UFG::AICoverComponent *this)
{
  UFG::AICoverComponent *v1; // rbx
  UFG::CoverPosition *v2; // rcx
  UFG::SimObject *v3; // rdx
  UFG::SimObject *v4; // rdi
  UFG::qVector3 *v5; // rax
  UFG::qVector3 vPosition; // [rsp+20h] [rbp-28h]
  char v7; // [rsp+30h] [rbp-18h]

  v1 = this;
  v2 = this->m_pTargetedCoverPosition;
  if ( v2 )
  {
    ((void (*)(void))v2->vfptr->UpdateTransforms)();
    v1->m_pTargetedCoverPosition->vfptr->GetSyncPos(
      (UFG::CoverObjectBase *)&v1->m_pTargetedCoverPosition->vfptr,
      &vPosition);
    v3 = v1->m_pSimTargetSync.m_pPointer;
    if ( v3 )
      UFG::AimingNPCComponent::updateSimTarget(v1, v3, &vPosition);
    v4 = v1->m_pSimTargetPopout.m_pPointer;
    if ( v4 )
    {
      v5 = v1->m_pTargetedCoverPosition->vfptr->GetFiringPosition(
             (UFG::CoverObjectBase *)&v1->m_pTargetedCoverPosition->vfptr,
             (UFG::qVector3 *)&v7);
      UFG::AimingNPCComponent::updateSimTarget(v1, v4, v5);
    }
  }
}

// File Line: 499
// RVA: 0x398C70
void __fastcall UFG::AimingNPCComponent::updateSimTarget(UFG::AICoverComponent *this, UFG::SimObject *pSimObj, UFG::qVector3 *vPosition)
{
  UFG::TransformNodeComponent *v3; // rcx
  UFG::qVector4 v4; // xmm2
  float v5; // xmm0_4
  float v6; // xmm1_4
  float v7; // xmm0_4
  UFG::qMatrix44 m; // [rsp+20h] [rbp-48h]

  if ( pSimObj )
    v3 = pSimObj->m_pTransformNodeComponent;
  else
    v3 = 0i64;
  v4 = 0i64;
  v4.x = (float)1;
  m.v0 = v4;
  m.v3 = (UFG::qVector4)_mm_shuffle_ps((__m128)v4, (__m128)v4, 21);
  m.v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v4, (__m128)v4, 81);
  v5 = vPosition->x;
  m.v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v4, (__m128)v4, 69);
  v6 = vPosition->y;
  m.v3.x = v5;
  v7 = vPosition->z;
  m.v3.y = v6;
  m.v3.z = v7;
  LODWORD(m.v3.w) = (_DWORD)FLOAT_1_0;
  UFG::TransformNodeComponent::SetWorldTransform(v3, &m);
}

// File Line: 512
// RVA: 0x381400
void __fastcall UFG::AICoverComponent::RemoveSimTargets(UFG::AICoverComponent *this)
{
  UFG::SimObject *v1; // rdx
  UFG::AICoverComponent *v2; // rbx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v3; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v4; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rax
  UFG::SimObject *v6; // rdx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax

  v1 = this->m_pSimTargetSync.m_pPointer;
  v2 = this;
  if ( v1 )
  {
    UFG::Simulation::DestroySimObject(&UFG::gSim, v1);
    v3 = &v2->m_pSimTargetSync;
    if ( v2->m_pSimTargetSync.m_pPointer )
    {
      v4 = v3->mPrev;
      v5 = v2->m_pSimTargetSync.mNext;
      v4->mNext = v5;
      v5->mPrev = v4;
      v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->mPrev;
      v2->m_pSimTargetSync.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->m_pSimTargetSync.mPrev;
    }
    v2->m_pSimTargetSync.m_pPointer = 0i64;
  }
  v6 = v2->m_pSimTargetPopout.m_pPointer;
  if ( v6 )
  {
    UFG::Simulation::DestroySimObject(&UFG::gSim, v6);
    v7 = &v2->m_pSimTargetPopout;
    if ( v2->m_pSimTargetPopout.m_pPointer )
    {
      v8 = v7->mPrev;
      v9 = v2->m_pSimTargetPopout.mNext;
      v8->mNext = v9;
      v9->mPrev = v8;
      v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v7->mPrev;
      v2->m_pSimTargetPopout.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->m_pSimTargetPopout.mPrev;
    }
    v2->m_pSimTargetPopout.m_pPointer = 0i64;
  }
}

// File Line: 527
// RVA: 0x34F190
void __fastcall UFG::AICoverComponent::ClearCoverObjects(UFG::AICoverComponent *this)
{
  UFG::AICoverComponent *v1; // rbx
  UFG::CoverObjectBase *v2; // rcx
  bool v3; // zf
  UFG::CoverPosition *v4; // rcx
  UFG::CoverPosition *v5; // rcx
  UFG::SimObjectGame *v6; // rcx
  unsigned __int16 v7; // dx
  UFG::WorldContextComponent *v8; // rax
  UFG::CoverObjectBase *v9; // rcx

  v1 = this;
  v2 = this->m_pCoverObject;
  if ( v2 )
  {
    v3 = v2->m_iRefCount-- == 1;
    if ( v3 )
      v2->vfptr->__vecDelDtor(v2, 1u);
    v1->m_pCoverObject = 0i64;
  }
  v4 = v1->m_pCurrentCoverPosition;
  if ( v4 && v1->m_pCoverObject && !((unsigned __int8 (*)(void))v4->vfptr->operator==)() )
    v1->vfptr[15].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v1->vfptr, 0);
  v1->vfptr[15].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v1->vfptr, 0);
  v5 = v1->m_pSyncCoverPosition;
  if ( v5 )
  {
    v3 = v5->m_iRefCount-- == 1;
    if ( v3 )
      v5->vfptr->__vecDelDtor((UFG::CoverObjectBase *)&v5->vfptr, 1u);
    v1->m_pSyncCoverPosition = 0i64;
  }
  v6 = (UFG::SimObjectGame *)v1->m_pSimObject;
  if ( v6 )
  {
    v7 = v6->m_Flags;
    if ( (v7 >> 14) & 1 )
    {
      v8 = (UFG::WorldContextComponent *)v6->m_Components.p[28].m_pComponent;
    }
    else if ( (v7 & 0x8000u) == 0 )
    {
      if ( (v7 >> 13) & 1 )
        v8 = (UFG::WorldContextComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             v6,
                                             UFG::WorldContextComponent::_TypeUID);
      else
        v8 = (UFG::WorldContextComponent *)((v7 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               v6,
                                                               UFG::WorldContextComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v6->vfptr, UFG::WorldContextComponent::_TypeUID));
    }
    else
    {
      v8 = (UFG::WorldContextComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           v6,
                                           UFG::WorldContextComponent::_TypeUID);
    }
    if ( v8 )
      UFG::WorldContextComponent::SetCoverPosition(v8, v1->m_pSyncCoverPosition);
  }
  UFG::AICoverComponent::SetTargetedCoverPosition(v1, 0i64);
  v9 = v1->m_pProbeCoverObject;
  if ( v9 )
  {
    v3 = v9->m_iRefCount-- == 1;
    if ( v3 )
      v9->vfptr->__vecDelDtor(v9, 1u);
    v1->m_pProbeCoverObject = 0i64;
  }
}

// File Line: 536
// RVA: 0x389360
void __fastcall UFG::AICoverComponent::StopUsingObject(UFG::AICoverComponent *this, UFG::CoverObjectBase *pCoverObject)
{
  UFG::AICoverComponent *v2; // rbx
  UFG::CoverObjectBase *v3; // rcx

  if ( pCoverObject )
  {
    v2 = this;
    v3 = this->m_pCoverObject;
    if ( v3 )
    {
      if ( UFG::CoverObjectBase::IsAnyLineOrCornerShared(v3, pCoverObject) )
        UFG::AICoverComponent::ClearCoverObjects(v2);
    }
  }
}

// File Line: 544
// RVA: 0x36ABF0
char __fastcall UFG::AICoverComponent::IsInCover(UFG::AICoverComponent *this)
{
  UFG::SimObjectGame *v1; // rcx
  unsigned __int16 v2; // dx
  UFG::SimComponent *v3; // rbx
  UFG::SimComponent *v4; // rax
  unsigned int v5; // eax
  unsigned int v6; // eax
  char result; // al

  v1 = (UFG::SimObjectGame *)this->m_pSimObject;
  if ( !v1 )
    goto LABEL_23;
  v2 = v1->m_Flags;
  if ( (v2 >> 14) & 1 )
  {
    v3 = v1->m_Components.p[7].m_pComponent;
  }
  else if ( (v2 & 0x8000u) == 0 )
  {
    if ( (v2 >> 13) & 1 )
    {
      v3 = v1->m_Components.p[6].m_pComponent;
    }
    else
    {
      v4 = (v2 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::ActionTreeComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v1->vfptr, UFG::ActionTreeComponent::_TypeUID);
      v3 = v4;
    }
  }
  else
  {
    v3 = v1->m_Components.p[7].m_pComponent;
  }
  if ( !v3 )
    goto LABEL_23;
  v5 = _S41;
  if ( !(_S41 & 1) )
  {
    _S41 |= 1u;
    coverUID.mUID = UFG::qStringHashUpper32("Cover", 0xFFFFFFFF);
    v5 = _S41;
  }
  if ( v5 & 2 )
  {
    v6 = mostUsedIndex_CoverUID;
  }
  else
  {
    _S41 = v5 | 2;
    v6 = GetMostUsedIndex(coverUID.mUID);
    mostUsedIndex_CoverUID = v6;
  }
  if ( ActionController::IsPlaying((ActionController *)&v3[3], &coverUID, v6, 1) )
    result = 1;
  else
LABEL_23:
    result = 0;
  return result;
}

// File Line: 562
// RVA: 0x399400
void __fastcall UFG::AICoverComponent::ValidateCover(UFG::AICoverComponent *this, bool bCheckNavPosition)
{
  UFG::AICoverComponent *v2; // rbx
  UFG::CoverPosition *v3; // rcx
  bool v4; // di
  UFG::CoverObjectBase *v5; // rcx
  UFG::CoverObjectBase *v6; // rcx
  bool v7; // zf
  UFG::CoverPosition *v8; // rcx
  UFG::CoverPosition *v9; // rcx
  UFG::CoverPosition *v10; // rcx
  UFG::AICoverQuery *v11; // rcx

  v2 = this;
  v3 = this->m_pTargetedCoverPosition;
  v4 = bCheckNavPosition;
  if ( v3 )
  {
    if ( (*((unsigned __int8 (**)(void))&v3->vfptr->__vecDelDtor + 2))() )
    {
      if ( v4 )
      {
        UFG::CoverPosition::ValidateNavPosition(v2->m_pTargetedCoverPosition);
        if ( !((unsigned __int8 (*)(void))v2->m_pTargetedCoverPosition->m_NavPosition.vfptr->IsMeshPositionValid)() )
        {
          UFG::AICoverComponent::ClearCoverObjects(v2);
          return;
        }
      }
    }
    else
    {
      UFG::AICoverComponent::SetTargetedCoverPosition(v2, 0i64);
    }
  }
  v5 = v2->m_pCoverObject;
  if ( v5 && !(*((unsigned __int8 (**)(void))&v5->vfptr->__vecDelDtor + 2))() )
  {
    v6 = v2->m_pCoverObject;
    if ( v6 )
    {
      v7 = v6->m_iRefCount-- == 1;
      if ( v7 )
        v6->vfptr->__vecDelDtor(v6, 1u);
      v2->m_pCoverObject = 0i64;
    }
    v8 = v2->m_pCurrentCoverPosition;
    if ( v8 && v2->m_pCoverObject && !((unsigned __int8 (*)(void))v8->vfptr->operator==)() )
      v2->vfptr[15].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v2->vfptr, 0);
  }
  v9 = v2->m_pCurrentCoverPosition;
  if ( v9 && !(*((unsigned __int8 (**)(void))&v9->vfptr->__vecDelDtor + 2))() )
    v2->vfptr[15].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v2->vfptr, 0);
  v10 = v2->m_pSyncCoverPosition;
  if ( v10 && !(*((unsigned __int8 (**)(void))&v10->vfptr->__vecDelDtor + 2))() )
    UFG::AICoverComponent::SetSyncCoverPosition(v2, 0i64, 1);
  v11 = v2->m_pQuery;
  if ( v11 )
    UFG::AICoverQuery::ResetParkourLifetimes(v11);
}

// File Line: 606
// RVA: 0x359640
UFG::qVector3 *__fastcall UFG::AICoverComponent::GetActorPosition(UFG::AICoverComponent *this, UFG::qVector3 *result)
{
  UFG::qVector3 *v2; // rdi
  UFG::AICoverComponent *v3; // rsi
  UFG::SimObjectCVBase *v4; // rcx
  UFG::TransformNodeComponent *v5; // rbx
  UFG::CharacterAnimationComponent *v6; // rax
  unsigned __int16 v7; // dx
  Creature *v8; // rcx
  UFG::qVector3 *v9; // rax
  float v10; // xmm1_4
  float v11; // xmm0_4
  UFG::SimObject *v12; // rax
  UFG::qMatrix44 transform; // [rsp+20h] [rbp-48h]

  v2 = result;
  v3 = this;
  if ( UFG::AICoverComponent::IsInCover(this) )
  {
    v4 = (UFG::SimObjectCVBase *)v3->m_pSimObject;
    v5 = 0i64;
    if ( v4 )
    {
      v7 = v4->m_Flags;
      if ( (v7 >> 14) & 1 )
      {
        v6 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v4);
      }
      else if ( (v7 & 0x8000u) == 0 )
      {
        if ( (v7 >> 13) & 1 )
        {
          v6 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v4);
        }
        else if ( (v7 >> 12) & 1 )
        {
          v6 = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                     (UFG::SimObjectGame *)&v4->vfptr,
                                                     UFG::CharacterAnimationComponent::_TypeUID);
        }
        else
        {
          v6 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                     (UFG::SimObject *)&v4->vfptr,
                                                     UFG::CharacterAnimationComponent::_TypeUID);
        }
      }
      else
      {
        v6 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v4);
      }
    }
    else
    {
      v6 = 0i64;
    }
    v8 = v6->mCreature;
    if ( v8 )
    {
      Creature::GetTransform(v8, v3->m_iSyncBoneID, &transform);
      v9 = v2;
      v10 = transform.v3.y;
      v2->x = transform.v3.x;
      v11 = transform.v3.z;
      v2->y = v10;
      v2->z = v11;
      return v9;
    }
    v12 = v3->m_pSimObject;
    if ( v12 )
      v5 = v12->m_pTransformNodeComponent;
  }
  else
  {
    v5 = (UFG::TransformNodeComponent *)v3->m_pSimObject;
    if ( v5 )
      v5 = (UFG::TransformNodeComponent *)v5->mChildren.mNode.mNext;
  }
  UFG::TransformNodeComponent::UpdateWorldTransform(v5);
  v2->x = v5->mWorldTransform.v3.x;
  v2->y = v5->mWorldTransform.v3.y;
  v2->z = v5->mWorldTransform.v3.z;
  return v2;
}

