// File Line: 29
// RVA: 0x14AEA00
__int64 dynamic_initializer_for__UFG::AICoverComponent::s_AICoverComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::AICoverComponent::s_AICoverComponentList__);
}

// File Line: 30
// RVA: 0x35D8A0
UFG::ComponentIDDesc *__fastcall UFG::AICoverComponent::GetDesc(UFG::AICoverComponent *this)
{
  return &UFG::AICoverComponent::_TypeIDesc;
}

// File Line: 73
// RVA: 0x32AEF0
void __fastcall UFG::AICoverComponent::AICoverComponent(
        UFG::AICoverComponent *this,
        unsigned int name_uid,
        UFG::qPropertySet *properties,
        bool startSuspended)
{
  UFG::qNode<UFG::AICoverComponent,UFG::AICoverComponent> *mPrev; // rax

  UFG::SimComponent::SimComponent(this, name_uid);
  this->mPrev = &this->UFG::qNode<UFG::AICoverComponent,UFG::AICoverComponent>;
  this->mNext = &this->UFG::qNode<UFG::AICoverComponent,UFG::AICoverComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AICoverComponent::`vftable;
  this->m_pQuery = 0i64;
  this->m_pCoverObject = 0i64;
  this->m_pTargetedCoverPosition = 0i64;
  this->m_pProbeCoverObject = 0i64;
  this->m_ePopoutSide = ePOPOUT_SIDE_NONE;
  this->m_pSimTargetSync.mPrev = &this->m_pSimTargetSync;
  this->m_pSimTargetSync.mNext = &this->m_pSimTargetSync;
  this->m_pSimTargetSync.m_pPointer = 0i64;
  this->m_pSimTargetPopout.mPrev = &this->m_pSimTargetPopout;
  this->m_pSimTargetPopout.mNext = &this->m_pSimTargetPopout;
  this->m_pSimTargetPopout.m_pPointer = 0i64;
  this->m_iSyncBoneID = -1;
  mPrev = UFG::AICoverComponent::s_AICoverComponentList.mNode.mPrev;
  UFG::AICoverComponent::s_AICoverComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::AICoverComponent,UFG::AICoverComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::AICoverComponent,UFG::AICoverComponent> *)&UFG::AICoverComponent::s_AICoverComponentList;
  UFG::AICoverComponent::s_AICoverComponentList.mNode.mPrev = &this->UFG::qNode<UFG::AICoverComponent,UFG::AICoverComponent>;
  UFG::SimComponent::AddType(this, UFG::AICoverComponent::_AICoverComponentTypeUID, "AICoverComponent");
}

// File Line: 90
// RVA: 0x333CB0
void __fastcall UFG::AICoverComponent::~AICoverComponent(UFG::AICoverComponent *this)
{
  UFG::qNode<UFG::AICoverComponent,UFG::AICoverComponent> *v2; // r8
  UFG::qNode<UFG::AICoverComponent,UFG::AICoverComponent> *mPrev; // rcx
  UFG::qNode<UFG::AICoverComponent,UFG::AICoverComponent> *mNext; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_pSimTargetPopout; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_pSimTargetSync; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::AICoverComponent,UFG::AICoverComponent> *v15; // rcx
  UFG::qNode<UFG::AICoverComponent,UFG::AICoverComponent> *v16; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AICoverComponent::`vftable;
  UFG::AICoverComponent::CancelQuery(this);
  UFG::AICoverComponent::ClearCoverObjects(this);
  UFG::AICoverComponent::RemoveSimTargets(this);
  if ( this == UFG::AICoverComponent::s_AICoverComponentpCurrentIterator )
    UFG::AICoverComponent::s_AICoverComponentpCurrentIterator = (UFG::AICoverComponent *)&this->mPrev[-4];
  v2 = &this->UFG::qNode<UFG::AICoverComponent,UFG::AICoverComponent>;
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = &this->UFG::qNode<UFG::AICoverComponent,UFG::AICoverComponent>;
  this->mNext = &this->UFG::qNode<UFG::AICoverComponent,UFG::AICoverComponent>;
  p_m_pSimTargetPopout = &this->m_pSimTargetPopout;
  if ( this->m_pSimTargetPopout.m_pPointer )
  {
    v6 = p_m_pSimTargetPopout->mPrev;
    v7 = this->m_pSimTargetPopout.mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    p_m_pSimTargetPopout->mPrev = p_m_pSimTargetPopout;
    this->m_pSimTargetPopout.mNext = &this->m_pSimTargetPopout;
  }
  this->m_pSimTargetPopout.m_pPointer = 0i64;
  v8 = p_m_pSimTargetPopout->mPrev;
  v9 = this->m_pSimTargetPopout.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  p_m_pSimTargetPopout->mPrev = p_m_pSimTargetPopout;
  this->m_pSimTargetPopout.mNext = &this->m_pSimTargetPopout;
  p_m_pSimTargetSync = &this->m_pSimTargetSync;
  if ( this->m_pSimTargetSync.m_pPointer )
  {
    v11 = p_m_pSimTargetSync->mPrev;
    v12 = this->m_pSimTargetSync.mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    p_m_pSimTargetSync->mPrev = p_m_pSimTargetSync;
    this->m_pSimTargetSync.mNext = &this->m_pSimTargetSync;
  }
  this->m_pSimTargetSync.m_pPointer = 0i64;
  v13 = p_m_pSimTargetSync->mPrev;
  v14 = this->m_pSimTargetSync.mNext;
  v13->mNext = v14;
  v14->mPrev = v13;
  p_m_pSimTargetSync->mPrev = p_m_pSimTargetSync;
  this->m_pSimTargetSync.mNext = &this->m_pSimTargetSync;
  v15 = v2->mPrev;
  v16 = this->mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  v2->mPrev = v2;
  this->mNext = &this->UFG::qNode<UFG::AICoverComponent,UFG::AICoverComponent>;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 101
// RVA: 0x3782F0
void __fastcall UFG::AICoverComponent::OnAttach(UFG::AICoverComponent *this, UFG::SimObject *object)
{
  UFG::CharacterAnimationComponent *v3; // rbx
  UFG::SimObjectCVBase *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::CharacterAnimationComponent *ComponentOfTypeHK; // rax
  Creature *mCreature; // rcx
  int BoneID; // eax

  v3 = 0i64;
  this->m_pQuery = 0i64;
  this->m_pCoverObject = 0i64;
  this->m_pTargetedCoverPosition = 0i64;
  this->m_pProbeCoverObject = 0i64;
  this->m_pCurrentCoverPosition = 0i64;
  this->m_pSyncCoverPosition = 0i64;
  *(_QWORD *)&this->m_iHoldCoverPositionRefs = 0i64;
  this->m_ePopoutSide = ePOPOUT_SIDE_NONE;
  UFG::AICoverComponent::GenerateSimTargets(this);
  m_pSimObject = (UFG::SimObjectCVBase *)this->m_pSimObject;
  if ( m_pSimObject )
  {
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(m_pSimObject);
    }
    else if ( (m_Flags & 0x2000) != 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)m_pSimObject);
    }
    else if ( (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                m_pSimObject,
                                                                UFG::CharacterAnimationComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                                m_pSimObject,
                                                                UFG::CharacterAnimationComponent::_TypeUID);
    }
    v3 = ComponentOfTypeHK;
  }
  if ( (_S37 & 1) == 0 )
  {
    _S37 |= 1u;
    UFG::qSymbolUC::create_from_string(&symSync01, "Sync01");
    atexit(UFG::AICoverComponent::OnAttach_::_2_::_dynamic_atexit_destructor_for__symSync01__);
  }
  mCreature = v3->mCreature;
  if ( mCreature )
  {
    if ( mCreature->mPose.mRigHandle.mData )
      BoneID = Skeleton::GetBoneID(mCreature->mPose.mRigHandle.mUFGSkeleton, symSync01.mUID);
    else
      BoneID = -1;
    this->m_iSyncBoneID = BoneID;
  }
}

// File Line: 137
// RVA: 0x379890
void __fastcall UFG::AICoverComponent::OnDetach(UFG::AICoverComponent *this)
{
  UFG::AICoverComponent::CancelQuery(this);
  UFG::AICoverComponent::ClearCoverObjects(this);
  UFG::AICoverComponent::RemoveSimTargets(this);
}

// File Line: 147
// RVA: 0x364D20
bool __fastcall UFG::AICoverComponent::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qPropertySet *mpWritableProperties; // rcx

  mpWritableProperties = pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = pSceneObj->mpConstProperties;
  return UFG::qPropertySet::GetParentFromName(
           mpWritableProperties,
           (UFG::qArray<unsigned long,0> *)&SimSymX_propset_componentAICover,
           DEPTH_RECURSE) != 0i64;
}

// File Line: 153
// RVA: 0x37E330
UFG::SimComponent *__fastcall UFG::AICoverComponent::PropertiesOnActivate(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v3; // rax
  UFG::qPropertySet *mpWritableProperties; // r8
  UFG::SimComponent *v5; // rax
  UFG::SimComponent *v6; // rdi
  UFG::SimObjectModifier v8; // [rsp+38h] [rbp-30h] BYREF

  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0xC8ui64, "AICoverComponent", 0i64, 1u);
  if ( v3 )
  {
    mpWritableProperties = pSceneObj->mpWritableProperties;
    if ( !mpWritableProperties )
      mpWritableProperties = pSceneObj->mpConstProperties;
    UFG::AICoverComponent::AICoverComponent((UFG::AICoverComponent *)v3, pSceneObj->m_NameUID, mpWritableProperties, 0);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v8, pSceneObj->m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v8, v6, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v8);
  UFG::SimObjectModifier::~SimObjectModifier(&v8);
  return v6;
}

// File Line: 160
// RVA: 0x38B2A0
void __fastcall UFG::AICoverComponent::Update(UFG::AICoverComponent *this, float deltaTime)
{
  UFG::SimObjectGame *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::CoverObjectBase *m_pCoverObject; // rcx
  unsigned int v7; // eax
  UFG::qVector3 *v8; // rax
  __int64 v9; // rax
  __int64 v10; // rdi
  UFG::qVector3 result; // [rsp+28h] [rbp-30h] BYREF
  char v13[32]; // [rsp+38h] [rbp-20h] BYREF

  m_pSimObject = (UFG::SimObjectGame *)this->m_pSimObject;
  if ( m_pSimObject
    && ((m_Flags = m_pSimObject->m_Flags, (m_Flags & 0x4000) == 0)
      ? (m_Flags >= 0
       ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
        ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pSimObject, UFG::HealthComponent::_TypeUID))
        : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::HealthComponent::_TypeUID)))
       : (ComponentOfTypeHK = m_pSimObject->m_Components.p[6].m_pComponent))
      : (ComponentOfTypeHK = m_pSimObject->m_Components.p[6].m_pComponent),
        ComponentOfTypeHK && !BYTE4(ComponentOfTypeHK[1].m_BoundComponentHandles.mNode.mPrev)) )
  {
    UFG::AICoverComponent::ValidateCover(this, 1);
    m_pCoverObject = this->m_pCoverObject;
    if ( m_pCoverObject )
    {
      if ( (*((unsigned __int8 (__fastcall **)(UFG::CoverObjectBase *))&m_pCoverObject->vfptr->__vecDelDtor + 2))(m_pCoverObject) )
      {
        v7 = _S38;
        if ( (_S38 & 1) == 0 )
        {
          v7 = _S38 | 1;
          _S38 |= 1u;
          kfSyncDist2 = FLOAT_0_25;
        }
        if ( (v7 & 2) == 0 )
        {
          _S38 = v7 | 2;
          kfSyncDistMax = FLOAT_0_42249995;
        }
        UFG::AICoverComponent::GetActorPosition(this, &result);
        v8 = this->m_pCoverObject->vfptr->GetSyncPos(this->m_pCoverObject, v13);
        if ( this->m_pCurrentCoverPosition
          || (float)((float)((float)(result.y - v8->y) * (float)(result.y - v8->y))
                   + (float)((float)(result.x - v8->x) * (float)(result.x - v8->x))) < kfSyncDist2 )
        {
          v9 = ((__int64 (__fastcall *)(UFG::CoverObjectBase *, UFG::qVector3 *, _QWORD))this->m_pCoverObject->vfptr->GetCoverPosition)(
                 this->m_pCoverObject,
                 &result,
                 0i64);
          v10 = v9;
          if ( v9 )
          {
            ++*(_DWORD *)(v9 + 8);
            this->vfptr[15].__vecDelDtor(this, v9);
            if ( (*(_DWORD *)(v10 + 8))-- == 1 )
              (**(void (__fastcall ***)(__int64, __int64))v10)(v10, 1i64);
          }
          else
          {
            this->vfptr[15].__vecDelDtor(this, 0);
          }
        }
        UFG::AICoverComponent::UpdateSimTargets(this);
      }
      else
      {
        UFG::AICoverComponent::ClearCoverObjects(this);
      }
    }
    else
    {
      this->vfptr[15].__vecDelDtor(this, 0);
    }
    UFG::AICoverComponent::SetSyncCoverPosition(this, this->m_pCurrentCoverPosition, 0);
  }
  else
  {
    UFG::AICoverComponent::CancelQuery(this);
    UFG::AICoverComponent::ClearCoverObjects(this);
  }
}

// File Line: 224
// RVA: 0x394140
void __fastcall UFG::AICoverComponent::UpdateAll(float deltaTime)
{
  UFG::qNode<UFG::AICoverComponent,UFG::AICoverComponent> *p_mNode; // rcx
  UFG::qList<UFG::AICoverComponent,UFG::AICoverComponent,1,0> *v2; // rbx

  p_mNode = UFG::AICoverComponent::s_AICoverComponentList.mNode.mNext - 4;
  if ( (UFG::qList<UFG::AICoverComponent,UFG::AICoverComponent,1,0> *)&UFG::AICoverComponent::s_AICoverComponentList.mNode.mNext[-4] != &UFG::AICoverComponent::s_AICoverComponentList - 4 )
  {
    do
    {
      v2 = (UFG::qList<UFG::AICoverComponent,UFG::AICoverComponent,1,0> *)&p_mNode[4].mNext[-4];
      if ( ((__int64)p_mNode[2].mPrev & 3) == 1 )
        ((void (__fastcall *)(UFG::qNode<UFG::AICoverComponent,UFG::AICoverComponent> *))p_mNode->mPrev[7].mPrev)(p_mNode);
      p_mNode = &v2->mNode;
    }
    while ( v2 != &UFG::AICoverComponent::s_AICoverComponentList - 4 );
  }
}

// File Line: 236
// RVA: 0x34CC90
void __fastcall UFG::AICoverComponent::CancelQuery(UFG::AICoverComponent *this)
{
  UFG::AICoverQuery *m_pQuery; // r8
  UFG::qNode<UFG::AICoverQuery,UFG::AICoverQuery> *mPrev; // rdx
  UFG::qNode<UFG::AICoverQuery,UFG::AICoverQuery> *mNext; // rax
  UFG::qNode<UFG::AICoverQuery,UFG::AICoverQuery> *v5; // r8
  UFG::qNode<UFG::AICoverQuery,UFG::AICoverQuery> *v6; // rcx
  bool v7; // zf
  UFG::AICoverQuery *v8; // rcx

  m_pQuery = this->m_pQuery;
  if ( m_pQuery )
  {
    mPrev = m_pQuery->mPrev;
    mNext = m_pQuery->mNext;
    v5 = &m_pQuery->UFG::qNode<UFG::AICoverQuery,UFG::AICoverQuery>;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    v6 = v5 - 2;
    v5->mPrev = v5;
    v5->mNext = v5;
    if ( v5 != (UFG::qNode<UFG::AICoverQuery,UFG::AICoverQuery> *)32 )
    {
      v7 = LODWORD(v6[1].mNext)-- == 1;
      if ( v7 )
        ((void (__fastcall *)(UFG::qNode<UFG::AICoverQuery,UFG::AICoverQuery> *, __int64))v6->mPrev->mPrev)(v6, 1i64);
    }
    v8 = this->m_pQuery;
    v7 = v8->m_iRefCount-- == 1;
    if ( v7 )
      v8->vfptr->__vecDelDtor(v8, 1u);
    this->m_pQuery = 0i64;
  }
}

// File Line: 248
// RVA: 0x388CE0
char __fastcall UFG::AICoverComponent::StartCoverSearch(
        UFG::AICoverComponent *this,
        UFG::AICoverSearchParams *pSearchParams,
        bool bOverridePrevious)
{
  UFG::allocator::free_link *v6; // rax
  UFG::AICoverQuery *v7; // rax
  UFG::AICoverQuery *m_pQuery; // rbp
  UFG::AICoverSearchParams *m_pSearchParams; // rbx
  hkSeekableStreamReader *RCX; // rax
  UFG::AICoverQuery *v12; // rcx
  UFG::AICoverQuery *v13; // rax
  UFG::AIQueryManager *v14; // rdx
  UFG::qNode<UFG::AICoverQuery,UFG::AICoverQuery> *v15; // rcx
  UFG::qNode<UFG::AICoverQuery,UFG::AICoverQuery> *mPrev; // rax

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
  this->m_pQuery = v7;
  ++v7->m_iRefCount;
  m_pQuery = this->m_pQuery;
  m_pSearchParams = m_pQuery->m_pSearchParams;
  if ( m_pSearchParams )
  {
    if ( m_pSearchParams->m_iRefCount-- == 1 )
    {
      UFG::AICoverSearchParams::~AICoverSearchParams(m_pSearchParams);
      operator delete[](m_pSearchParams);
    }
    m_pQuery->m_pSearchParams = 0i64;
  }
  if ( pSearchParams )
  {
    m_pQuery->m_pSearchParams = pSearchParams;
    ++pSearchParams->m_iRefCount;
  }
  RCX = Assembly::GetRCX(this);
  v12 = this->m_pQuery;
  v12->m_queryFinishedDelegate.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::AICoverComponent::SearchCompleteCallback;
  v12->m_queryFinishedDelegate.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)RCX;
  v13 = this->m_pQuery;
  v14 = UFG::AIQueryManager::ms_pInstance;
  ++v13->m_iRefCount;
  v15 = &v13->UFG::qNode<UFG::AICoverQuery,UFG::AICoverQuery>;
  mPrev = v14->m_listpCoverQueries.mNode.mPrev;
  mPrev->mNext = v15;
  v15->mPrev = mPrev;
  v15->mNext = &v14->m_listpCoverQueries.mNode;
  v14->m_listpCoverQueries.mNode.mPrev = v15;
  return 1;
}

// File Line: 278
// RVA: 0x383F20
void __fastcall UFG::AICoverComponent::SearchCompleteCallback(UFG::AICoverComponent *this, UFG::AICoverQuery *pQuery)
{
  UFG::CoverPosition *m_pBestCoverPosition; // rdi
  UFG::CoverObjectBase *m_pCoverObject; // rcx
  bool v6; // zf
  UFG::CoverPosition *m_pCurrentCoverPosition; // rcx
  UFG::SimObjectGame *m_pSimObject; // rcx
  UFG::NavComponent *m_pComponent; // rax
  __int16 m_Flags; // dx
  UFG::AICoverQuery *m_pQuery; // rcx

  m_pBestCoverPosition = pQuery->m_pBestCoverPosition;
  if ( m_pBestCoverPosition && m_pBestCoverPosition->vfptr->CanUse(m_pBestCoverPosition, this->m_pSimObject) )
  {
    m_pCoverObject = this->m_pCoverObject;
    if ( m_pCoverObject )
    {
      v6 = m_pCoverObject->m_iRefCount-- == 1;
      if ( v6 )
        m_pCoverObject->vfptr->__vecDelDtor(m_pCoverObject, 1u);
      this->m_pCoverObject = 0i64;
    }
    if ( m_pBestCoverPosition->vfptr->CanUse(m_pBestCoverPosition, this->m_pSimObject) )
    {
      this->m_pCoverObject = m_pBestCoverPosition;
      ++m_pBestCoverPosition->m_iRefCount;
    }
    m_pCurrentCoverPosition = this->m_pCurrentCoverPosition;
    if ( m_pCurrentCoverPosition
      && this->m_pCoverObject
      && !((unsigned __int8 (__fastcall *)(UFG::CoverPosition *))m_pCurrentCoverPosition->vfptr->operator==)(m_pCurrentCoverPosition) )
    {
      this->vfptr[15].__vecDelDtor(this, 0);
    }
    UFG::AICoverComponent::SetTargetedCoverPosition(this, m_pBestCoverPosition);
    if ( !pQuery->m_pSearchParams->m_bUseCombatRegionDestination && pQuery->m_pFoundPath.m_pNavPath )
    {
      m_pSimObject = (UFG::SimObjectGame *)this->m_pSimObject;
      if ( m_pSimObject )
      {
        m_Flags = m_pSimObject->m_Flags;
        if ( (m_Flags & 0x4000) != 0 )
        {
          m_pComponent = (UFG::NavComponent *)m_pSimObject->m_Components.p[36].m_pComponent;
        }
        else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        {
          m_pComponent = (UFG::NavComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                m_pSimObject,
                                                UFG::NavComponent::_TypeUID);
        }
        else
        {
          m_pComponent = (UFG::NavComponent *)UFG::SimObject::GetComponentOfType(
                                                m_pSimObject,
                                                UFG::NavComponent::_TypeUID);
        }
      }
      else
      {
        m_pComponent = 0i64;
      }
      UFG::NavComponent::InjectPath(
        m_pComponent,
        &pQuery->m_npQueryCenter,
        &m_pBestCoverPosition->m_NavPosition,
        pQuery->m_pFoundPath.m_pNavPath);
    }
  }
  m_pQuery = this->m_pQuery;
  v6 = m_pQuery->m_iRefCount-- == 1;
  if ( v6 )
    m_pQuery->vfptr->__vecDelDtor(m_pQuery, 1u);
  this->m_pQuery = 0i64;
}

// File Line: 321
// RVA: 0x387DB0
void __fastcall UFG::AICoverComponent::SetTargetedCoverPosition(
        UFG::AICoverComponent *this,
        UFG::CoverPosition *pCoverPosition)
{
  UFG::CoverPosition *v2; // rbx
  UFG::SimObjectGame *m_pSimObject; // rcx
  UFG::TargetingSystemBaseComponent *m_pComponent; // rsi
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::CoverPosition *m_pTargetedCoverPosition; // rcx
  UFG::CoverPosition *v9; // rcx

  v2 = pCoverPosition;
  if ( pCoverPosition
    && (!(*((unsigned __int8 (__fastcall **)(UFG::CoverPosition *))&pCoverPosition->vfptr->__vecDelDtor + 2))(pCoverPosition)
     || !v2->vfptr->CanUse(v2, this->m_pSimObject)) )
  {
    v2 = 0i64;
  }
  if ( v2 != this->m_pTargetedCoverPosition )
  {
    m_pSimObject = (UFG::SimObjectGame *)this->m_pSimObject;
    if ( m_pSimObject )
    {
      m_Flags = m_pSimObject->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = (UFG::TargetingSystemBaseComponent *)m_pSimObject->m_Components.p[20].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                m_pSimObject,
                                UFG::TargetingSystemBaseComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                m_pSimObject,
                                UFG::TargetingSystemBaseComponent::_TypeUID);
        m_pComponent = (UFG::TargetingSystemBaseComponent *)ComponentOfTypeHK;
      }
      else
      {
        m_pComponent = (UFG::TargetingSystemBaseComponent *)m_pSimObject->m_Components.p[20].m_pComponent;
      }
    }
    else
    {
      m_pComponent = 0i64;
    }
    m_pTargetedCoverPosition = this->m_pTargetedCoverPosition;
    if ( m_pTargetedCoverPosition )
    {
      m_pTargetedCoverPosition->vfptr->RemoveUser(m_pTargetedCoverPosition);
      v9 = this->m_pTargetedCoverPosition;
      if ( v9->m_iRefCount-- == 1 )
        v9->vfptr->__vecDelDtor(v9, 1u);
      this->m_pTargetedCoverPosition = 0i64;
    }
    else
    {
      UFG::TargetingSystemBaseComponent::SetTarget(
        m_pComponent,
        eTARGET_TYPE_COVER_OBJECT,
        this->m_pSimTargetSync.m_pPointer);
      UFG::TargetingSystemBaseComponent::SetTarget(
        m_pComponent,
        eTARGET_TYPE_COVER_POPOUT,
        this->m_pSimTargetPopout.m_pPointer);
    }
    if ( v2 )
    {
      ++v2->m_iRefCount;
      v2->vfptr->AddUser(v2, this->m_pSimObject);
      this->m_pTargetedCoverPosition = v2;
    }
    else
    {
      UFG::TargetingSystemBaseComponent::SetTarget(m_pComponent, eTARGET_TYPE_COVER_OBJECT, 0i64);
      UFG::TargetingSystemBaseComponent::SetTarget(m_pComponent, eTARGET_TYPE_COVER_POPOUT, 0i64);
    }
  }
  UFG::AICoverComponent::UpdateSimTargets(this);
}

// File Line: 360
// RVA: 0x3851C0
void __fastcall UFG::AICoverComponent::SetCurrentCoverPosition(
        UFG::AICoverComponent *this,
        UFG::CoverPosition *pCoverPosition)
{
  UFG::CoverPosition *m_pCurrentCoverPosition; // rcx

  if ( this->m_pCurrentCoverPosition )
  {
    if ( pCoverPosition
      && (!pCoverPosition->m_NavPosition.m_bValid
       || !UFG::HavokAIUtilGame::IsValidKey(
             pCoverPosition->m_NavPosition.m_packedKey,
             pCoverPosition->m_NavPosition.m_aiMeshUid)) )
    {
      UFG::CoverPosition::SetNavPosition(pCoverPosition, &this->m_pCurrentCoverPosition->m_NavPosition);
    }
    m_pCurrentCoverPosition = this->m_pCurrentCoverPosition;
    if ( m_pCurrentCoverPosition->m_iRefCount-- == 1 )
      m_pCurrentCoverPosition->vfptr->__vecDelDtor(m_pCurrentCoverPosition, 1u);
    this->m_pCurrentCoverPosition = 0i64;
  }
  if ( pCoverPosition )
  {
    this->m_pCurrentCoverPosition = pCoverPosition;
    ++pCoverPosition->m_iRefCount;
  }
}

// File Line: 399
// RVA: 0x387C00
void __fastcall UFG::AICoverComponent::SetSyncCoverPosition(
        UFG::AICoverComponent *this,
        UFG::CoverPosition *pSyncCoverPosition,
        bool bIgnoreHoldPosition)
{
  UFG::CoverPosition *m_pSyncCoverPosition; // rcx
  UFG::SimObjectGame *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::WorldContextComponent *m_pComponent; // rax

  if ( bIgnoreHoldPosition
    || !this->m_iHoldCoverPositionRefs
    || !this->m_pSyncCoverPosition
    || this->m_iAllowHoldCoverPositionUpdateRefs > 0
    && pSyncCoverPosition
    && (*((unsigned __int8 (__fastcall **)(UFG::CoverPosition *))&pSyncCoverPosition->vfptr[1].__vecDelDtor + 1))(pSyncCoverPosition) )
  {
    m_pSyncCoverPosition = this->m_pSyncCoverPosition;
    if ( m_pSyncCoverPosition )
    {
      if ( m_pSyncCoverPosition->m_iRefCount-- == 1 )
        m_pSyncCoverPosition->vfptr->__vecDelDtor(m_pSyncCoverPosition, 1u);
      this->m_pSyncCoverPosition = 0i64;
    }
    if ( pSyncCoverPosition )
    {
      this->m_pSyncCoverPosition = pSyncCoverPosition;
      ++pSyncCoverPosition->m_iRefCount;
    }
    m_pSimObject = (UFG::SimObjectGame *)this->m_pSimObject;
    if ( m_pSimObject )
    {
      m_Flags = m_pSimObject->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = (UFG::WorldContextComponent *)m_pSimObject->m_Components.p[28].m_pComponent;
      }
      else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      {
        m_pComponent = (UFG::WorldContextComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                       m_pSimObject,
                                                       UFG::WorldContextComponent::_TypeUID);
      }
      else
      {
        m_pComponent = (UFG::WorldContextComponent *)UFG::SimObject::GetComponentOfType(
                                                       m_pSimObject,
                                                       UFG::WorldContextComponent::_TypeUID);
      }
      if ( m_pComponent )
        UFG::WorldContextComponent::SetCoverPosition(m_pComponent, this->m_pSyncCoverPosition);
    }
  }
}

// File Line: 431
// RVA: 0x35B720
UFG::CoverPosition *__fastcall UFG::AICoverComponent::GetCoverObjectFromEnum(
        UFG::AICoverComponent *this,
        UFG::eCoverComponentObjectEnum eObjectType)
{
  int v2; // edx
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
  char dest[264]; // [rsp+20h] [rbp-108h] BYREF
  UFG::qSymbol result; // [rsp+130h] [rbp+8h] BYREF
  UFG::qSymbol symbolName; // [rsp+138h] [rbp+10h] BYREF

  UFG::AICoverComponent::RemoveSimTargets(this);
  UFG::qSPrintf(dest, "CoverObject_%d", this->m_pSimObject->mNode.mUID);
  UFG::qSymbol::create_from_string(&result, dest);
  UFG::AICoverComponent::GenerateSimTarget(this, &result, &this->m_pSimTargetSync);
  UFG::qSPrintf(dest, "CoverPopout_%d", this->m_pSimObject->mNode.mUID);
  UFG::qSymbol::create_from_string(&symbolName, dest);
  UFG::AICoverComponent::GenerateSimTarget(this, &symbolName, &this->m_pSimTargetPopout);
}

// File Line: 470
// RVA: 0x3593D0
void __fastcall UFG::AICoverComponent::GenerateSimTarget(
        UFG::AICoverComponent *this,
        UFG::qSymbol *symbolName,
        UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *destPointer)
{
  UFG::SimObject *SimObject; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *p_mNode; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v10; // rsi
  unsigned int v11; // edi
  unsigned int v12; // eax
  UFG::SimComponent *v13; // rax
  UFG::SimComponent *v14; // rsi
  UFG::SimObject *m_pPointer; // rdx
  __int16 m_Flags; // cx
  UFG::SimObjectModifier v17; // [rsp+38h] [rbp-30h] BYREF

  SimObject = UFG::Simulation::CreateSimObject(&UFG::gSim, symbolName);
  if ( destPointer->m_pPointer )
  {
    mPrev = destPointer->mPrev;
    mNext = destPointer->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    destPointer->mPrev = destPointer;
    destPointer->mNext = destPointer;
  }
  destPointer->m_pPointer = SimObject;
  if ( SimObject )
  {
    p_mNode = &SimObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
    v8 = SimObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    v8->mNext = destPointer;
    destPointer->mPrev = v8;
    destPointer->mNext = p_mNode;
    p_mNode->mPrev = destPointer;
  }
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v10 = UFG::qMemoryPool::Allocate(
          SimulationMemoryPool,
          0x110ui64,
          "CoverObjectBase Sim Target TransformNodeComponent",
          0i64,
          1u);
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
  m_pPointer = destPointer->m_pPointer;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 )
  {
    v11 = 2;
  }
  else if ( (m_Flags & 0x1000) != 0 )
  {
    v11 = 1;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v17, m_pPointer, 1);
  UFG::SimObjectModifier::AttachComponent(&v17, v14, v11);
  UFG::SimObjectModifier::Close(&v17);
  UFG::SimObjectModifier::~SimObjectModifier(&v17);
}

// File Line: 479
// RVA: 0x398D00
void __fastcall UFG::AICoverComponent::UpdateSimTargets(UFG::AICoverComponent *this)
{
  UFG::CoverPosition *m_pTargetedCoverPosition; // rcx
  UFG::SimObject *m_pPointer; // rdx
  UFG::SimObject *v4; // rdi
  UFG::qVector3 *v5; // rax
  UFG::qVector3 vPosition; // [rsp+20h] [rbp-28h] BYREF
  char v7[24]; // [rsp+30h] [rbp-18h] BYREF

  m_pTargetedCoverPosition = this->m_pTargetedCoverPosition;
  if ( m_pTargetedCoverPosition )
  {
    ((void (*)(void))m_pTargetedCoverPosition->vfptr->UpdateTransforms)();
    this->m_pTargetedCoverPosition->vfptr->GetSyncPos(this->m_pTargetedCoverPosition, &vPosition);
    m_pPointer = this->m_pSimTargetSync.m_pPointer;
    if ( m_pPointer )
      UFG::AimingNPCComponent::updateSimTarget(this, m_pPointer, &vPosition);
    v4 = this->m_pSimTargetPopout.m_pPointer;
    if ( v4 )
    {
      v5 = this->m_pTargetedCoverPosition->vfptr->GetFiringPosition(this->m_pTargetedCoverPosition, v7);
      UFG::AimingNPCComponent::updateSimTarget(this, v4, v5);
    }
  }
}

// File Line: 499
// RVA: 0x398C70
void __fastcall UFG::AimingNPCComponent::updateSimTarget(
        UFG::AICoverComponent *this,
        UFG::SimObject *pSimObj,
        UFG::qVector3 *vPosition)
{
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rcx
  UFG::qVector4 v4; // xmm2
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm0_4
  UFG::qMatrix44 m; // [rsp+20h] [rbp-48h] BYREF

  if ( pSimObj )
    m_pTransformNodeComponent = pSimObj->m_pTransformNodeComponent;
  else
    m_pTransformNodeComponent = 0i64;
  v4 = 0i64;
  v4.x = (float)1;
  m.v0 = v4;
  m.v3 = (UFG::qVector4)_mm_shuffle_ps((__m128)v4, (__m128)v4, 21);
  m.v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v4, (__m128)v4, 81);
  x = vPosition->x;
  m.v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v4, (__m128)v4, 69);
  y = vPosition->y;
  m.v3.x = x;
  z = vPosition->z;
  m.v3.y = y;
  m.v3.z = z;
  LODWORD(m.v3.w) = (_DWORD)FLOAT_1_0;
  UFG::TransformNodeComponent::SetWorldTransform(m_pTransformNodeComponent, &m);
}

// File Line: 512
// RVA: 0x381400
void __fastcall UFG::AICoverComponent::RemoveSimTargets(UFG::AICoverComponent *this)
{
  UFG::SimObject *m_pPointer; // rdx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_pSimTargetSync; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::SimObject *v6; // rdx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_pSimTargetPopout; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax

  m_pPointer = this->m_pSimTargetSync.m_pPointer;
  if ( m_pPointer )
  {
    UFG::Simulation::DestroySimObject(&UFG::gSim, m_pPointer);
    p_m_pSimTargetSync = &this->m_pSimTargetSync;
    if ( this->m_pSimTargetSync.m_pPointer )
    {
      mPrev = p_m_pSimTargetSync->mPrev;
      mNext = this->m_pSimTargetSync.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_m_pSimTargetSync->mPrev = p_m_pSimTargetSync;
      this->m_pSimTargetSync.mNext = &this->m_pSimTargetSync;
    }
    this->m_pSimTargetSync.m_pPointer = 0i64;
  }
  v6 = this->m_pSimTargetPopout.m_pPointer;
  if ( v6 )
  {
    UFG::Simulation::DestroySimObject(&UFG::gSim, v6);
    p_m_pSimTargetPopout = &this->m_pSimTargetPopout;
    if ( this->m_pSimTargetPopout.m_pPointer )
    {
      v8 = p_m_pSimTargetPopout->mPrev;
      v9 = this->m_pSimTargetPopout.mNext;
      v8->mNext = v9;
      v9->mPrev = v8;
      p_m_pSimTargetPopout->mPrev = p_m_pSimTargetPopout;
      this->m_pSimTargetPopout.mNext = &this->m_pSimTargetPopout;
    }
    this->m_pSimTargetPopout.m_pPointer = 0i64;
  }
}

// File Line: 527
// RVA: 0x34F190
void __fastcall UFG::AICoverComponent::ClearCoverObjects(UFG::AICoverComponent *this)
{
  UFG::CoverObjectBase *m_pCoverObject; // rcx
  bool v3; // zf
  UFG::CoverPosition *m_pCurrentCoverPosition; // rcx
  UFG::CoverPosition *m_pSyncCoverPosition; // rcx
  UFG::SimObjectGame *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::WorldContextComponent *m_pComponent; // rax
  UFG::CoverObjectBase *m_pProbeCoverObject; // rcx

  m_pCoverObject = this->m_pCoverObject;
  if ( m_pCoverObject )
  {
    v3 = m_pCoverObject->m_iRefCount-- == 1;
    if ( v3 )
      m_pCoverObject->vfptr->__vecDelDtor(m_pCoverObject, 1u);
    this->m_pCoverObject = 0i64;
  }
  m_pCurrentCoverPosition = this->m_pCurrentCoverPosition;
  if ( m_pCurrentCoverPosition
    && this->m_pCoverObject
    && !((unsigned __int8 (__fastcall *)(UFG::CoverPosition *))m_pCurrentCoverPosition->vfptr->operator==)(m_pCurrentCoverPosition) )
  {
    this->vfptr[15].__vecDelDtor(this, 0);
  }
  this->vfptr[15].__vecDelDtor(this, 0);
  m_pSyncCoverPosition = this->m_pSyncCoverPosition;
  if ( m_pSyncCoverPosition )
  {
    v3 = m_pSyncCoverPosition->m_iRefCount-- == 1;
    if ( v3 )
      m_pSyncCoverPosition->vfptr->__vecDelDtor(m_pSyncCoverPosition, 1u);
    this->m_pSyncCoverPosition = 0i64;
  }
  m_pSimObject = (UFG::SimObjectGame *)this->m_pSimObject;
  if ( m_pSimObject )
  {
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
      m_pComponent = (UFG::WorldContextComponent *)m_pSimObject->m_Components.p[28].m_pComponent;
    else
      m_pComponent = (UFG::WorldContextComponent *)(m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                                  ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      m_pSimObject,
                                                      UFG::WorldContextComponent::_TypeUID)
                                                  : UFG::SimObject::GetComponentOfType(
                                                      m_pSimObject,
                                                      UFG::WorldContextComponent::_TypeUID));
    if ( m_pComponent )
      UFG::WorldContextComponent::SetCoverPosition(m_pComponent, this->m_pSyncCoverPosition);
  }
  UFG::AICoverComponent::SetTargetedCoverPosition(this, 0i64);
  m_pProbeCoverObject = this->m_pProbeCoverObject;
  if ( m_pProbeCoverObject )
  {
    v3 = m_pProbeCoverObject->m_iRefCount-- == 1;
    if ( v3 )
      m_pProbeCoverObject->vfptr->__vecDelDtor(m_pProbeCoverObject, 1u);
    this->m_pProbeCoverObject = 0i64;
  }
}

// File Line: 536
// RVA: 0x389360
void __fastcall UFG::AICoverComponent::StopUsingObject(UFG::AICoverComponent *this, UFG::CoverObjectBase *pCoverObject)
{
  UFG::CoverObjectBase *m_pCoverObject; // rcx

  if ( pCoverObject )
  {
    m_pCoverObject = this->m_pCoverObject;
    if ( m_pCoverObject )
    {
      if ( UFG::CoverObjectBase::IsAnyLineOrCornerShared(m_pCoverObject, pCoverObject) )
        UFG::AICoverComponent::ClearCoverObjects(this);
    }
  }
}

// File Line: 544
// RVA: 0x36ABF0
bool __fastcall UFG::AICoverComponent::IsInCover(UFG::AICoverComponent *this)
{
  UFG::SimObjectGame *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rbx
  UFG::SimComponent *v4; // rax
  unsigned int v5; // eax
  unsigned int MostUsedIndex; // eax

  m_pSimObject = (UFG::SimObjectGame *)this->m_pSimObject;
  if ( !m_pSimObject )
    return 0;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pSimObject->m_Components.p[7].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 )
    {
      m_pComponent = m_pSimObject->m_Components.p[6].m_pComponent;
    }
    else
    {
      v4 = (m_Flags & 0x1000) != 0
         ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pSimObject, UFG::ActionTreeComponent::_TypeUID)
         : UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::ActionTreeComponent::_TypeUID);
      m_pComponent = v4;
    }
  }
  else
  {
    m_pComponent = m_pSimObject->m_Components.p[7].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  v5 = _S41;
  if ( (_S41 & 1) == 0 )
  {
    _S41 |= 1u;
    coverUID.mUID = UFG::qStringHashUpper32("Cover", -1);
    v5 = _S41;
  }
  if ( (v5 & 2) != 0 )
  {
    MostUsedIndex = mostUsedIndex_CoverUID;
  }
  else
  {
    _S41 = v5 | 2;
    MostUsedIndex = GetMostUsedIndex(coverUID.mUID);
    mostUsedIndex_CoverUID = MostUsedIndex;
  }
  return ActionController::IsPlaying((ActionController *)&m_pComponent[3], &coverUID, MostUsedIndex, 1) != 0;
}

// File Line: 562
// RVA: 0x399400
void __fastcall UFG::AICoverComponent::ValidateCover(UFG::AICoverComponent *this, bool bCheckNavPosition)
{
  UFG::CoverPosition *m_pTargetedCoverPosition; // rcx
  UFG::CoverObjectBase *m_pCoverObject; // rcx
  UFG::CoverObjectBase *v6; // rcx
  UFG::CoverPosition *m_pCurrentCoverPosition; // rcx
  UFG::CoverPosition *v9; // rcx
  UFG::CoverPosition *m_pSyncCoverPosition; // rcx
  UFG::AICoverQuery *m_pQuery; // rcx

  m_pTargetedCoverPosition = this->m_pTargetedCoverPosition;
  if ( m_pTargetedCoverPosition )
  {
    if ( (*((unsigned __int8 (__fastcall **)(UFG::CoverPosition *))&m_pTargetedCoverPosition->vfptr->__vecDelDtor + 2))(m_pTargetedCoverPosition) )
    {
      if ( bCheckNavPosition )
      {
        UFG::CoverPosition::ValidateNavPosition(this->m_pTargetedCoverPosition);
        if ( !this->m_pTargetedCoverPosition->m_NavPosition.vfptr->IsMeshPositionValid(&this->m_pTargetedCoverPosition->m_NavPosition) )
        {
          UFG::AICoverComponent::ClearCoverObjects(this);
          return;
        }
      }
    }
    else
    {
      UFG::AICoverComponent::SetTargetedCoverPosition(this, 0i64);
    }
  }
  m_pCoverObject = this->m_pCoverObject;
  if ( m_pCoverObject
    && !(*((unsigned __int8 (__fastcall **)(UFG::CoverObjectBase *))&m_pCoverObject->vfptr->__vecDelDtor + 2))(m_pCoverObject) )
  {
    v6 = this->m_pCoverObject;
    if ( v6 )
    {
      if ( v6->m_iRefCount-- == 1 )
        v6->vfptr->__vecDelDtor(v6, 1u);
      this->m_pCoverObject = 0i64;
    }
    m_pCurrentCoverPosition = this->m_pCurrentCoverPosition;
    if ( m_pCurrentCoverPosition
      && this->m_pCoverObject
      && !((unsigned __int8 (__fastcall *)(UFG::CoverPosition *))m_pCurrentCoverPosition->vfptr->operator==)(m_pCurrentCoverPosition) )
    {
      this->vfptr[15].__vecDelDtor(this, 0);
    }
  }
  v9 = this->m_pCurrentCoverPosition;
  if ( v9 && !(*((unsigned __int8 (__fastcall **)(UFG::CoverPosition *))&v9->vfptr->__vecDelDtor + 2))(v9) )
    this->vfptr[15].__vecDelDtor(this, 0);
  m_pSyncCoverPosition = this->m_pSyncCoverPosition;
  if ( m_pSyncCoverPosition
    && !(*((unsigned __int8 (__fastcall **)(UFG::CoverPosition *))&m_pSyncCoverPosition->vfptr->__vecDelDtor + 2))(m_pSyncCoverPosition) )
  {
    UFG::AICoverComponent::SetSyncCoverPosition(this, 0i64, 1);
  }
  m_pQuery = this->m_pQuery;
  if ( m_pQuery )
    UFG::AICoverQuery::ResetParkourLifetimes(m_pQuery);
}

// File Line: 606
// RVA: 0x359640
UFG::qVector3 *__fastcall UFG::AICoverComponent::GetActorPosition(UFG::AICoverComponent *this, UFG::qVector3 *result)
{
  UFG::SimObjectCVBase *m_pSimObject; // rcx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  UFG::CharacterAnimationComponent *ComponentOfTypeHK; // rax
  __int16 m_Flags; // dx
  Creature *mCreature; // rcx
  UFG::qVector3 *v9; // rax
  float y; // xmm1_4
  float z; // xmm0_4
  UFG::SimObject *v12; // rax
  UFG::qMatrix44 transform; // [rsp+20h] [rbp-48h] BYREF

  if ( UFG::AICoverComponent::IsInCover(this) )
  {
    m_pSimObject = (UFG::SimObjectCVBase *)this->m_pSimObject;
    m_pTransformNodeComponent = 0i64;
    if ( m_pSimObject )
    {
      m_Flags = m_pSimObject->m_Flags;
      if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
      {
        ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(m_pSimObject);
      }
      else if ( (m_Flags & 0x2000) != 0 )
      {
        ComponentOfTypeHK = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)m_pSimObject);
      }
      else if ( (m_Flags & 0x1000) != 0 )
      {
        ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                  m_pSimObject,
                                                                  UFG::CharacterAnimationComponent::_TypeUID);
      }
      else
      {
        ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                                  m_pSimObject,
                                                                  UFG::CharacterAnimationComponent::_TypeUID);
      }
    }
    else
    {
      ComponentOfTypeHK = 0i64;
    }
    mCreature = ComponentOfTypeHK->mCreature;
    if ( mCreature )
    {
      Creature::GetTransform(mCreature, this->m_iSyncBoneID, &transform);
      v9 = result;
      y = transform.v3.y;
      result->x = transform.v3.x;
      z = transform.v3.z;
      result->y = y;
      result->z = z;
      return v9;
    }
    v12 = this->m_pSimObject;
    if ( v12 )
      m_pTransformNodeComponent = v12->m_pTransformNodeComponent;
  }
  else
  {
    m_pTransformNodeComponent = (UFG::TransformNodeComponent *)this->m_pSimObject;
    if ( m_pTransformNodeComponent )
      m_pTransformNodeComponent = (UFG::TransformNodeComponent *)m_pTransformNodeComponent->mChildren.mNode.mNext;
  }
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  result->x = m_pTransformNodeComponent->mWorldTransform.v3.x;
  result->y = m_pTransformNodeComponent->mWorldTransform.v3.y;
  result->z = m_pTransformNodeComponent->mWorldTransform.v3.z;
  return result;
}

