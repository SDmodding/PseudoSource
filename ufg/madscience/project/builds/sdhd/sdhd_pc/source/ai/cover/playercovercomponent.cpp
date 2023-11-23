// File Line: 45
// RVA: 0x335F10
void __fastcall UFG::PlayerCoverComponent::CoverObjectPosition::~CoverObjectPosition(
        UFG::PlayerCoverComponent::CoverObjectPosition *this)
{
  UFG::CoverObjectBase *m_pCoverObject; // rcx
  bool v3; // zf
  UFG::CoverPosition *m_pCoverPosition; // rcx

  m_pCoverObject = this->m_pCoverObject;
  if ( m_pCoverObject )
  {
    v3 = m_pCoverObject->m_iRefCount-- == 1;
    if ( v3 )
      m_pCoverObject->vfptr->__vecDelDtor(m_pCoverObject, 1u);
    this->m_pCoverObject = 0i64;
  }
  m_pCoverPosition = this->m_pCoverPosition;
  if ( m_pCoverPosition )
  {
    v3 = m_pCoverPosition->m_iRefCount-- == 1;
    if ( v3 )
      m_pCoverPosition->vfptr->__vecDelDtor(m_pCoverPosition, 1u);
    this->m_pCoverPosition = 0i64;
  }
}

// File Line: 81
// RVA: 0x14AD050
__int64 dynamic_initializer_for__UFG::PlayerCoverComponent::_TypeIDesc__()
{
  UFG::ComponentIDDesc *v0; // rax
  __int64 result; // rax

  v0 = UFG::PlayerCoverComponent::AccessComponentDesc();
  *(_DWORD *)&UFG::PlayerCoverComponent::_TypeIDesc.mBaseTypeIndex = *(_DWORD *)&v0->mBaseTypeIndex;
  UFG::PlayerCoverComponent::_TypeIDesc.mChildBitMask = v0->mChildBitMask;
  result = v0->mChildren;
  UFG::PlayerCoverComponent::_TypeIDesc.mChildren = result;
  return result;
}

// File Line: 147
// RVA: 0x379250
void __fastcall UFG::PlayerCoverComponent::OnAttach(UFG::PlayerCoverComponent *this, UFG::SimObject *object)
{
  this->m_pCurrentPlayerCoverQuery = 0i64;
  this->m_pInProgressPlayerCoverQuery = 0i64;
  UFG::AICoverComponent::OnAttach(this, object);
}

// File Line: 155
// RVA: 0x37B0A0
void __fastcall UFG::PlayerCoverComponent::OnDetach(UFG::PlayerCoverComponent *this)
{
  UFG::PlayerCoverQuery *m_pInProgressPlayerCoverQuery; // rcx
  bool v3; // zf
  UFG::PlayerCoverQuery *m_pCurrentPlayerCoverQuery; // rcx

  UFG::AICoverComponent::CancelQuery(this);
  UFG::AICoverComponent::ClearCoverObjects(this);
  UFG::AICoverComponent::RemoveSimTargets(this);
  m_pInProgressPlayerCoverQuery = this->m_pInProgressPlayerCoverQuery;
  if ( m_pInProgressPlayerCoverQuery )
  {
    v3 = m_pInProgressPlayerCoverQuery->m_iRefCount-- == 1;
    if ( v3 )
      m_pInProgressPlayerCoverQuery->vfptr->__vecDelDtor(m_pInProgressPlayerCoverQuery, 1u);
    this->m_pInProgressPlayerCoverQuery = 0i64;
  }
  m_pCurrentPlayerCoverQuery = this->m_pCurrentPlayerCoverQuery;
  if ( m_pCurrentPlayerCoverQuery )
  {
    v3 = m_pCurrentPlayerCoverQuery->m_iRefCount-- == 1;
    if ( v3 )
      m_pCurrentPlayerCoverQuery->vfptr->__vecDelDtor(m_pCurrentPlayerCoverQuery, 1u);
    this->m_pCurrentPlayerCoverQuery = 0i64;
  }
}

// File Line: 164
// RVA: 0x364DE0
bool __fastcall UFG::PlayerCoverComponent::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qPropertySet *mpWritableProperties; // rcx

  mpWritableProperties = pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = pSceneObj->mpConstProperties;
  return UFG::qPropertySet::GetParentFromName(
           mpWritableProperties,
           (UFG::qArray<unsigned long,0> *)&SimSymX_propset_componentPlayerCover,
           DEPTH_RECURSE) != 0i64;
}

// File Line: 170
// RVA: 0x37E640
UFG::PlayerCoverComponent *__fastcall UFG::PlayerCoverComponent::PropertiesOnActivate(
        UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v3; // rax
  UFG::SimComponent *v4; // rbx
  UFG::qPropertySet *mpWritableProperties; // r8
  UFG::SimObjectModifier v7; // [rsp+38h] [rbp-30h] BYREF

  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0xD8ui64, "PlayerCoverComponent", 0i64, 1u);
  v4 = (UFG::SimComponent *)v3;
  if ( v3 )
  {
    mpWritableProperties = pSceneObj->mpWritableProperties;
    if ( !mpWritableProperties )
      mpWritableProperties = pSceneObj->mpConstProperties;
    UFG::AICoverComponent::AICoverComponent((UFG::AICoverComponent *)v3, pSceneObj->m_NameUID, mpWritableProperties, 0);
    v4->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::PlayerCoverComponent::`vftable;
    UFG::SimComponent::AddType(v4, UFG::PlayerCoverComponent::_PlayerCoverComponentTypeUID, "PlayerCoverComponent");
  }
  else
  {
    v4 = 0i64;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v7, pSceneObj->m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v7, v4, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v7);
  UFG::SimObjectModifier::~SimObjectModifier(&v7);
  return (UFG::PlayerCoverComponent *)v4;
}

// File Line: 178
// RVA: 0x391FF0
void __fastcall UFG::PlayerCoverComponent::Update(UFG::PlayerCoverComponent *this, float fDeltaTime)
{
  UFG::SimObject *m_pSimObject; // rax
  UFG::SimObjectGame *v4; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::PlayerCoverQuery *m_pInProgressPlayerCoverQuery; // rcx
  bool v8; // zf
  UFG::PlayerCoverQuery *m_pCurrentPlayerCoverQuery; // rcx
  UFG::PlayerCoverQuery *v10; // rcx
  UFG::PlayerCoverQuery *v11; // rcx

  m_pSimObject = this->m_pSimObject;
  if ( !m_pSimObject || (m_pSimObject->m_Flags & 0x400) == 0 )
  {
    UFG::AICoverComponent::ValidateCover(this, 0);
    v4 = (UFG::SimObjectGame *)this->m_pSimObject;
    if ( v4
      && ((m_Flags = v4->m_Flags, (m_Flags & 0x4000) == 0)
        ? (m_Flags >= 0 && (m_Flags & 0x2000) == 0 && (m_Flags & 0x1000) == 0
         ? (ComponentOfType = UFG::SimObject::GetComponentOfType(v4, UFG::CharacterOccupantComponent::_TypeUID))
         : (ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::CharacterOccupantComponent::_TypeUID)))
        : (ComponentOfType = v4->m_Components.p[44].m_pComponent),
          ComponentOfType) )
    {
      m_pInProgressPlayerCoverQuery = this->m_pInProgressPlayerCoverQuery;
      if ( m_pInProgressPlayerCoverQuery )
      {
        v8 = m_pInProgressPlayerCoverQuery->m_iRefCount-- == 1;
        if ( v8 )
          m_pInProgressPlayerCoverQuery->vfptr->__vecDelDtor(m_pInProgressPlayerCoverQuery, 1u);
        this->m_pInProgressPlayerCoverQuery = 0i64;
      }
      m_pCurrentPlayerCoverQuery = this->m_pCurrentPlayerCoverQuery;
      if ( m_pCurrentPlayerCoverQuery )
      {
        v8 = m_pCurrentPlayerCoverQuery->m_iRefCount-- == 1;
        if ( v8 )
          m_pCurrentPlayerCoverQuery->vfptr->__vecDelDtor(m_pCurrentPlayerCoverQuery, 1u);
        this->m_pCurrentPlayerCoverQuery = 0i64;
      }
    }
    else
    {
      v10 = this->m_pCurrentPlayerCoverQuery;
      if ( v10 )
      {
        UFG::AICoverQuery::ResetParkourLifetimes(v10);
        UFG::PlayerCoverComponent::UpdateCurrentCoverObject(this);
      }
      v11 = this->m_pInProgressPlayerCoverQuery;
      if ( v11 )
        UFG::AICoverQuery::ResetParkourLifetimes(v11);
      else
        UFG::PlayerCoverComponent::SubmitPlayerCoverQuery(this);
      UFG::AICoverComponent::UpdateSimTargets(this);
      UFG::AICoverComponent::SetSyncCoverPosition(this, this->m_pCurrentCoverPosition, 0);
    }
  }
}

// File Line: 237
// RVA: 0x394730
void __fastcall UFG::PlayerCoverComponent::UpdateCoverQuery(UFG::PlayerCoverComponent *this)
{
  UFG::ActiveAIEntityComponent *v2; // rax
  int v3; // xmm0_4
  UFG::PlayerCoverQuery *m_pInProgressPlayerCoverQuery; // rcx
  UFG::PlayerCoverQuery *v5; // rax
  fastdelegate::detail::GenericClass *m_pthis; // rcx
  UFG::PlayerCoverQuery *m_pCurrentPlayerCoverQuery; // rcx
  UFG::PlayerCoverQuery *v8; // rdi
  bool v9; // zf
  UFG::PlayerCoverQuery *v10; // rcx
  int v11; // [rsp+30h] [rbp+8h] BYREF

  if ( this->m_pInProgressPlayerCoverQuery )
  {
    v2 = LocalPlayer ? UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(LocalPlayer) : 0i64;
    v3 = v2->m_CurrentObjective == eAI_OBJECTIVE_FORCE_ENTER_COVER ? LODWORD(FLOAT_0_1) : LODWORD(FLOAT_0_00030000001);
    m_pInProgressPlayerCoverQuery = this->m_pInProgressPlayerCoverQuery;
    v11 = v3;
    m_pInProgressPlayerCoverQuery->vfptr->Update(m_pInProgressPlayerCoverQuery, (float *)&v11, 0);
    v5 = this->m_pInProgressPlayerCoverQuery;
    if ( v5->m_uState == 13 )
    {
      m_pthis = v5->m_queryFinishedDelegate.m_Closure.m_pthis;
      if ( m_pthis || v5->m_queryFinishedDelegate.m_Closure.m_pFunction )
        ((void (__fastcall *)(fastdelegate::detail::GenericClass *, UFG::PlayerCoverQuery *))v5->m_queryFinishedDelegate.m_Closure.m_pFunction)(
          m_pthis,
          v5);
      m_pCurrentPlayerCoverQuery = this->m_pCurrentPlayerCoverQuery;
      v8 = this->m_pInProgressPlayerCoverQuery;
      if ( m_pCurrentPlayerCoverQuery )
      {
        v9 = m_pCurrentPlayerCoverQuery->m_iRefCount-- == 1;
        if ( v9 )
          m_pCurrentPlayerCoverQuery->vfptr->__vecDelDtor(m_pCurrentPlayerCoverQuery, 1u);
        this->m_pCurrentPlayerCoverQuery = 0i64;
      }
      if ( v8 )
      {
        ++v8->m_iRefCount;
        this->m_pCurrentPlayerCoverQuery = v8;
      }
      v10 = this->m_pInProgressPlayerCoverQuery;
      if ( v10 )
      {
        v9 = v10->m_iRefCount-- == 1;
        if ( v9 )
          v10->vfptr->__vecDelDtor(v10, 1u);
        this->m_pInProgressPlayerCoverQuery = 0i64;
      }
    }
  }
}

// File Line: 261
// RVA: 0x394D70
void __fastcall UFG::PlayerCoverComponent::UpdateCurrentCoverObject(UFG::PlayerCoverComponent *this)
{
  UFG::CoverObjectBase *m_pCoverObject; // rcx
  UFG::CoverObjectBase *v3; // rcx
  bool v4; // zf
  UFG::CoverPosition *m_pCurrentCoverPosition; // rcx
  UFG::CoverObjectBase *v6; // rbx
  UFG::CoverObjectBaseVtbl *vfptr; // rbx
  UFG::qVector3 *ActorPosition; // rax
  __int64 v9; // rax
  UFG::CoverPosition *v10; // rbx
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v11; // rbx
  UFG::qVector3 *v12; // rax
  __int64 v13; // r8
  UFG::CoverObjectBase *v14; // rcx
  UFG::CoverPosition *v15; // rcx
  UFG::CoverPosition *m_pSyncCoverPosition; // rcx
  UFG::SimObjectGame *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::WorldContextComponent *m_pComponent; // rax
  UFG::qVector3 result; // [rsp+20h] [rbp-18h] BYREF

  m_pCoverObject = this->m_pCoverObject;
  if ( m_pCoverObject
    && !(*((unsigned __int8 (__fastcall **)(UFG::CoverObjectBase *))&m_pCoverObject->vfptr->__vecDelDtor + 2))(m_pCoverObject) )
  {
    v3 = this->m_pCoverObject;
    if ( v3 )
    {
      v4 = v3->m_iRefCount-- == 1;
      if ( v4 )
        v3->vfptr->__vecDelDtor(v3, 1u);
      this->m_pCoverObject = 0i64;
    }
    m_pCurrentCoverPosition = this->m_pCurrentCoverPosition;
    if ( m_pCurrentCoverPosition
      && this->m_pCoverObject
      && !((unsigned __int8 (__fastcall *)(UFG::CoverPosition *))m_pCurrentCoverPosition->vfptr->operator==)(m_pCurrentCoverPosition) )
    {
      this->vfptr[15].__vecDelDtor(this, 0);
      UFG::AICoverComponent::SetSyncCoverPosition(this, 0i64, 1);
    }
    this->vfptr[15].__vecDelDtor(this, 0);
    UFG::AICoverComponent::SetSyncCoverPosition(this, 0i64, 0);
  }
  if ( this->m_iHoldCoverPositionRefs > 0 && (v6 = this->m_pCoverObject) != 0i64 )
  {
    vfptr = v6->vfptr;
    ActorPosition = UFG::AICoverComponent::GetActorPosition(this, &result);
    v9 = ((__int64 (__fastcall *)(UFG::CoverObjectBase *, UFG::qVector3 *, _QWORD))vfptr->GetCoverPosition)(
           this->m_pCoverObject,
           ActorPosition,
           0i64);
    v10 = (UFG::CoverPosition *)v9;
    if ( v9 )
    {
      ++*(_DWORD *)(v9 + 8);
      this->vfptr[15].__vecDelDtor(this, v9);
      UFG::AICoverComponent::SetSyncCoverPosition(this, v10, 0);
      v4 = v10->m_iRefCount-- == 1;
      if ( v4 )
        v10->vfptr->__vecDelDtor(v10, 1u);
    }
  }
  else
  {
    v11 = this->vfptr;
    v12 = UFG::AICoverComponent::GetActorPosition(this, &result);
    LOBYTE(v13) = 1;
    if ( !((unsigned __int8 (__fastcall *)(UFG::PlayerCoverComponent *, UFG::qVector3 *, __int64, _QWORD))v11[17].__vecDelDtor)(
            this,
            v12,
            v13,
            0i64) )
    {
      v14 = this->m_pCoverObject;
      if ( v14 )
      {
        v4 = v14->m_iRefCount-- == 1;
        if ( v4 )
          v14->vfptr->__vecDelDtor(v14, 1u);
        this->m_pCoverObject = 0i64;
      }
      v15 = this->m_pCurrentCoverPosition;
      if ( v15
        && this->m_pCoverObject
        && !((unsigned __int8 (__fastcall *)(UFG::CoverPosition *))v15->vfptr->operator==)(v15) )
      {
        this->vfptr[15].__vecDelDtor(this, 0);
        UFG::AICoverComponent::SetSyncCoverPosition(this, 0i64, 1);
      }
      this->vfptr[15].__vecDelDtor(this, 0);
      if ( !this->m_iHoldCoverPositionRefs || !this->m_pSyncCoverPosition )
      {
        m_pSyncCoverPosition = this->m_pSyncCoverPosition;
        if ( m_pSyncCoverPosition )
        {
          v4 = m_pSyncCoverPosition->m_iRefCount-- == 1;
          if ( v4 )
            m_pSyncCoverPosition->vfptr->__vecDelDtor(m_pSyncCoverPosition, 1u);
          this->m_pSyncCoverPosition = 0i64;
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
  }
}

// File Line: 297
// RVA: 0x385140
void __fastcall UFG::PlayerCoverComponent::SetCoverObject(
        UFG::PlayerCoverComponent *this,
        UFG::CoverObjectBase *pCoverObject)
{
  UFG::CoverObjectBase *m_pCoverObject; // rcx
  UFG::CoverPosition *m_pCurrentCoverPosition; // rcx

  m_pCoverObject = this->m_pCoverObject;
  if ( m_pCoverObject )
  {
    if ( m_pCoverObject->m_iRefCount-- == 1 )
      m_pCoverObject->vfptr->__vecDelDtor(m_pCoverObject, 1u);
    this->m_pCoverObject = 0i64;
  }
  if ( pCoverObject )
  {
    this->m_pCoverObject = pCoverObject;
    ++pCoverObject->m_iRefCount;
  }
  m_pCurrentCoverPosition = this->m_pCurrentCoverPosition;
  if ( m_pCurrentCoverPosition
    && this->m_pCoverObject
    && !((unsigned __int8 (__fastcall *)(UFG::CoverPosition *))m_pCurrentCoverPosition->vfptr->operator==)(m_pCurrentCoverPosition) )
  {
    this->vfptr[15].__vecDelDtor(this, 0);
    UFG::AICoverComponent::SetSyncCoverPosition(this, 0i64, 1);
  }
}

// File Line: 327
// RVA: 0x3895A0
void __fastcall UFG::PlayerCoverComponent::SubmitPlayerCoverQuery(UFG::PlayerCoverComponent *this)
{
  UFG::allocator::free_link *v2; // rax
  UFG::allocator::free_link *v3; // rbx
  UFG::SimObject *m_pSimObject; // rdx
  UFG::allocator::free_link *mNext; // rcx
  UFG::allocator::free_link *v6; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rax
  UFG::allocator::free_link *v8; // rax
  UFG::PlayerCoverQuery *v9; // rsi
  UFG::PlayerCoverQuery *m_pInProgressPlayerCoverQuery; // rbp
  UFG::AICoverSearchParams *m_pSearchParams; // rsi
  bool v12; // zf

  if ( !this->m_pInProgressPlayerCoverQuery )
  {
    v2 = UFG::qMalloc(0x78ui64, "AICoverSearchParams", 0i64);
    v3 = v2;
    if ( v2 )
    {
      v2->mNext = v2;
      v2[1].mNext = v2;
      v2[2].mNext = 0i64;
      v2[13].mNext = 0i64;
      v2[12].mNext = 0i64;
      LODWORD(v2[14].mNext) = 0;
    }
    else
    {
      v3 = 0i64;
    }
    ++LODWORD(v3[14].mNext);
    m_pSimObject = this->m_pSimObject;
    if ( v3[2].mNext )
    {
      mNext = v3->mNext;
      v6 = v3[1].mNext;
      mNext[1].mNext = v6;
      v6->mNext = mNext;
      v3->mNext = v3;
      v3[1].mNext = v3;
    }
    v3[2].mNext = (UFG::allocator::free_link *)m_pSimObject;
    if ( m_pSimObject )
    {
      mPrev = m_pSimObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
      mPrev->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)v3;
      v3->mNext = (UFG::allocator::free_link *)mPrev;
      v3[1].mNext = (UFG::allocator::free_link *)&m_pSimObject->m_SafePointerList;
      m_pSimObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)v3;
    }
    LODWORD(v3[3].mNext) = 1091567616;
    *(UFG::allocator::free_link **)((char *)&v3[3].mNext + 4) = (UFG::allocator::free_link *)0x40000000;
    *(UFG::allocator::free_link **)((char *)&v3[4].mNext + 4) = 0i64;
    *(UFG::allocator::free_link **)((char *)&v3[5].mNext + 4) = 0i64;
    HIDWORD(v3[6].mNext) = 0;
    HIDWORD(v3[8].mNext) = 0;
    LOBYTE(v3[9].mNext) = 0;
    HIDWORD(v3[10].mNext) = -1082130432;
    LODWORD(v3[11].mNext) = 0;
    v8 = UFG::qMalloc(0x130ui64, "PlayerCoverQuery", 0i64);
    v9 = (UFG::PlayerCoverQuery *)v8;
    if ( v8 )
    {
      UFG::AICoverQuery::AICoverQuery((UFG::AICoverQuery *)v8);
      v9->vfptr = (UFG::AIQueryVtbl *)&UFG::PlayerCoverQuery::`vftable;
    }
    else
    {
      v9 = 0i64;
    }
    this->m_pInProgressPlayerCoverQuery = v9;
    ++v9->m_iRefCount;
    m_pInProgressPlayerCoverQuery = this->m_pInProgressPlayerCoverQuery;
    m_pSearchParams = m_pInProgressPlayerCoverQuery->m_pSearchParams;
    if ( m_pSearchParams )
    {
      v12 = m_pSearchParams->m_iRefCount-- == 1;
      if ( v12 )
      {
        UFG::AICoverSearchParams::~AICoverSearchParams(m_pSearchParams);
        operator delete[](m_pSearchParams);
      }
      m_pInProgressPlayerCoverQuery->m_pSearchParams = 0i64;
    }
    m_pInProgressPlayerCoverQuery->m_pSearchParams = (UFG::AICoverSearchParams *)v3;
    v12 = ++LODWORD(v3[14].mNext) == 1;
    --LODWORD(v3[14].mNext);
    if ( v12 )
    {
      UFG::AICoverSearchParams::~AICoverSearchParams((UFG::AICoverSearchParams *)v3);
      operator delete[](v3);
    }
  }
}

// File Line: 381
// RVA: 0x385240
void __fastcall UFG::PlayerCoverComponent::SetCurrentCoverPosition(
        UFG::PlayerCoverComponent *this,
        UFG::CoverPosition *pCoverPosition)
{
  if ( pCoverPosition && !pCoverPosition->vfptr->CanUse(pCoverPosition, this->m_pSimObject) )
    UFG::PlayerCoverComponent::BootAIOffCoverPosition(this, pCoverPosition);
  UFG::AICoverComponent::SetCurrentCoverPosition(this, pCoverPosition);
  UFG::AICoverComponent::SetSyncCoverPosition(this, pCoverPosition, 0);
  UFG::AICoverComponent::SetTargetedCoverPosition(this, pCoverPosition);
}

// File Line: 399
// RVA: 0x37CEC0
UFG::PlayerCoverComponent::ProbeForPlayerCover

// File Line: 610
// RVA: 0x35BBD0
double __fastcall UFG::PlayerCoverComponent::GetCoverObjectScore(
        UFG::PlayerCoverComponent *this,
        UFG::PlayerCoverComponent::ScoredObject *scoredObject,
        UFG::PlayerCoverComponent::CoverObjectScoringParams *params)
{
  UFG::CoverObjectBase *m_pCoverObject; // rbp
  __int64 v7; // rdi
  double v8; // xmm6_8
  UFG::CoverObjectBase *v9; // rcx
  double v10; // xmm2_8
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm0_4
  double result; // xmm0_8
  float v15; // xmm0_4
  UFG::PlayerCoverComponent::ScoredObject scoredObjecta; // [rsp+20h] [rbp-38h] BYREF

  if ( !(*((unsigned __int8 (**)(void))&scoredObject->m_pCoverObject->vfptr->__vecDelDtor + 3))() )
  {
    if ( !params->m_bHigh && UFG::CoverObjectBase::IsHighCover(scoredObject->m_pCoverObject) )
      goto LABEL_15;
    if ( !params->m_bLow )
    {
      v15 = scoredObject->m_pCoverObject->vfptr->GetHeight(scoredObject->m_pCoverObject);
      if ( v15 > 0.5 && v15 < 1.6 )
        goto LABEL_15;
    }
    if ( scoredObject->m_pCoverObject->vfptr->IsCorner(scoredObject->m_pCoverObject) )
    {
      if ( BYTE4(UFG::CoverCornerHandle::Get((UFG::CoverCornerHandle *)&scoredObject->m_pCoverObject[1])->mResourceHandles.mNode.mPrev) )
      {
        if ( !params->m_bRightCorner )
        {
          *(_QWORD *)&result = LODWORD(FLOAT_N1_0);
          return result;
        }
      }
      else if ( !params->m_bLeftCorner )
      {
        goto LABEL_15;
      }
      *(float *)&result = UFG::PlayerCoverComponent::GetCoverObjectScoreCorner(this, scoredObject, params);
      return result;
    }
    if ( params->m_bLine )
    {
      *(float *)&result = UFG::PlayerCoverComponent::GetCoverObjectScoreParkourHandle(this, scoredObject, params);
      return result;
    }
LABEL_15:
    *(_QWORD *)&result = LODWORD(FLOAT_N1_0);
    return result;
  }
  m_pCoverObject = scoredObject->m_pCoverObject;
  v7 = 0i64;
  for ( *(_QWORD *)&v8 = LODWORD(FLOAT_N1_0);
        (unsigned int)v7 < LODWORD(m_pCoverObject[1].vfptr);
        v7 = (unsigned int)(v7 + 1) )
  {
    v9 = *(UFG::CoverObjectBase **)(*(_QWORD *)&m_pCoverObject[1].m_iRefCount + 8 * v7);
    scoredObjecta.m_fScore = -1.0;
    scoredObjecta.m_pCoverObject = v9;
    UFG::PlayerCoverComponent::GetCoverObjectScore(this, &scoredObjecta, params);
    *(_QWORD *)&v10 = LODWORD(scoredObjecta.m_fScore);
    if ( scoredObjecta.m_fScore > *(float *)&v8 )
    {
      x = scoredObjecta.m_vScorePosition.x;
      y = scoredObjecta.m_vScorePosition.y;
      scoredObject->m_fScore = scoredObjecta.m_fScore;
      v8 = v10;
      scoredObject->m_vScorePosition.x = x;
      z = scoredObjecta.m_vScorePosition.z;
      scoredObject->m_vScorePosition.y = y;
      scoredObject->m_vScorePosition.z = z;
    }
  }
  return v8;
}

// File Line: 682
// RVA: 0x35B750
float __fastcall UFG::PlayerCoverComponent::GetCoverObjectPositionScore(
        UFG::PlayerCoverComponent *this,
        UFG::PlayerCoverComponent::ScoredObject *scoredObject,
        UFG::PlayerCoverComponent::CoverObjectScoringParams *params)
{
  float v5; // xmm9_4
  __m128 y_low; // xmm10
  __m128 v7; // xmm1
  float v8; // xmm11_4
  float v9; // xmm6_4
  float v10; // xmm0_4
  float v11; // xmm8_4
  float v12; // xmm4_4
  __m128 z_low; // xmm2
  float v14; // xmm5_4
  __m128 v15; // xmm3
  float v16; // xmm1_4
  float v17; // xmm4_4
  float v18; // xmm2_4
  float v19; // xmm5_4
  float v20; // xmm13_4
  __m128 x_low; // xmm3
  float v22; // xmm14_4
  __m128 v23; // xmm12
  float v24; // xmm1_4
  float v25; // xmm3_4
  float v26; // xmm2_4
  bool v27; // cl
  bool v28; // al
  float v29; // xmm1_4
  __m128 v30; // xmm2
  __m128 v31; // xmm3
  float v32; // xmm7_4
  float v33; // xmm1_4
  UFG::qVector3 v35; // [rsp+20h] [rbp-D8h] BYREF
  UFG::qVector3 dest; // [rsp+30h] [rbp-C8h] BYREF
  UFG::qVector3 v1; // [rsp+40h] [rbp-B8h] BYREF

  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(scoredObject->m_vScorePosition.z - params->m_vActorPos.z) & _xmm) >= 0.30000001 )
    return FLOAT_N1_0;
  y_low = (__m128)LODWORD(scoredObject->m_vScorePosition.y);
  v5 = scoredObject->m_vScorePosition.x - params->m_vActorPos.x;
  y_low.m128_f32[0] = y_low.m128_f32[0] - params->m_vActorPos.y;
  v7 = y_low;
  v7.m128_f32[0] = (float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v5 * v5);
  v8 = _mm_sqrt_ps(v7).m128_f32[0];
  if ( v8 >= params->m_fMaxSearchDistance )
    return FLOAT_N1_0;
  v9 = 0.0;
  v1.z = (float)(1.0 / v8) * 0.0;
  v1.x = (float)(1.0 / v8) * v5;
  v1.y = (float)(1.0 / v8) * y_low.m128_f32[0];
  v10 = UFG::qAngleBetween(&v1, &params->m_vActorMotionIntention);
  v11 = 0.0;
  if ( params->m_fMotionIntentionMagnitude > 0.0 )
  {
    if ( v10 >= UFG::PlayerCoverComponent::ms_fCoverScoreMotionIntentionAngleRange )
    {
      if ( v8 > params->m_fBufferZoneSize )
      {
        UFG::qRotateVectorZ(
          &dest,
          &params->m_vActorMotionIntention,
          UFG::PlayerCoverComponent::ms_fCoverScoreMotionIntentionAngleRange);
        UFG::qRotateVectorZ(
          &v35,
          &params->m_vActorMotionIntention,
          COERCE_FLOAT(LODWORD(UFG::PlayerCoverComponent::ms_fCoverScoreMotionIntentionAngleRange) ^ _xmm[0]));
        z_low = (__m128)LODWORD(dest.z);
        v12 = (float)(dest.y * UFG::qVector3::msDirUp.z) - (float)(dest.z * UFG::qVector3::msDirUp.y);
        z_low.m128_f32[0] = (float)(dest.z * UFG::qVector3::msDirUp.x) - (float)(dest.x * UFG::qVector3::msDirUp.z);
        v15 = z_low;
        v14 = (float)(dest.x * UFG::qVector3::msDirUp.y) - (float)(dest.y * UFG::qVector3::msDirUp.x);
        v15.m128_f32[0] = (float)((float)(z_low.m128_f32[0] * z_low.m128_f32[0]) + (float)(v12 * v12))
                        + (float)(v14 * v14);
        v16 = v15.m128_f32[0] == 0.0 ? 0.0 : 1.0 / _mm_sqrt_ps(v15).m128_f32[0];
        x_low = (__m128)LODWORD(v35.x);
        v17 = v12 * v16;
        v18 = z_low.m128_f32[0] * v16;
        v19 = v14 * v16;
        v20 = (float)(v35.z * UFG::qVector3::msDirUp.y) - (float)(v35.y * UFG::qVector3::msDirUp.z);
        x_low.m128_f32[0] = (float)(v35.x * UFG::qVector3::msDirUp.z) - (float)(v35.z * UFG::qVector3::msDirUp.x);
        v23 = x_low;
        v22 = (float)(v35.y * UFG::qVector3::msDirUp.x) - (float)(v35.x * UFG::qVector3::msDirUp.y);
        v23.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(v20 * v20))
                        + (float)(v22 * v22);
        v24 = v23.m128_f32[0] == 0.0 ? 0.0 : 1.0 / _mm_sqrt_ps(v23).m128_f32[0];
        v25 = (float)((float)((float)(x_low.m128_f32[0] * v24) * y_low.m128_f32[0]) + (float)((float)(v20 * v24) * v5))
            + (float)((float)(v22 * v24) * 0.0);
        v26 = (float)((float)(v18 * y_low.m128_f32[0]) + (float)(v17 * v5)) + (float)(v19 * 0.0);
        v27 = (float)((float)((float)(dest.y * y_low.m128_f32[0]) + (float)(dest.x * v5)) + (float)(dest.z * 0.0)) > 0.0
           && v26 > 0.0
           && v26 < params->m_fBufferZoneSize;
        v28 = (float)((float)((float)(v35.y * y_low.m128_f32[0]) + (float)(v35.x * v5)) + (float)(v35.z * 0.0)) > 0.0
           && v25 > 0.0
           && v25 < params->m_fBufferZoneSize;
        if ( !v27 && !v28 )
          return FLOAT_N1_0;
      }
    }
    else
    {
      v11 = (float)(UFG::PlayerCoverComponent::ms_fCoverScoreMotionIntentionAngleRange - v10)
          / UFG::PlayerCoverComponent::ms_fCoverScoreMotionIntentionAngleRange;
    }
  }
  v30 = (__m128)LODWORD(scoredObject->m_vScorePosition.y);
  v29 = scoredObject->m_vScorePosition.x - params->m_vCameraPosition.x;
  v30.m128_f32[0] = v30.m128_f32[0] - params->m_vCameraPosition.y;
  v31 = v30;
  v31.m128_f32[0] = (float)(v30.m128_f32[0] * v30.m128_f32[0]) + (float)(v29 * v29);
  v32 = v31.m128_f32[0] == 0.0 ? 0.0 : 1.0 / _mm_sqrt_ps(v31).m128_f32[0];
  dest.z = v32 * 0.0;
  dest.x = v29 * v32;
  dest.y = v30.m128_f32[0] * v32;
  v33 = UFG::qAngleBetween(&dest, &params->m_vCameraDirection);
  if ( v33 >= 1.0471976 )
    return FLOAT_N1_0;
  if ( (float)((float)(0.52359879 - v33) * 1.9098593) >= 0.0 )
    v9 = (float)(0.52359879 - v33) * 1.9098593;
  return (float)((float)(UFG::PlayerCoverComponent::ms_fCoverScoreDistanceNumerator
                       / powf(v8, UFG::PlayerCoverComponent::ms_fCoverScoreDistancePower))
               + (float)(UFG::PlayerCoverComponent::ms_fCoverScoreMotionIntentionMultiplier * v11))
       + (float)(UFG::PlayerCoverComponent::ms_fCoverScoreCameraOrientationMultiplier * v9);
}

// File Line: 785
// RVA: 0x35BD70
float __fastcall UFG::PlayerCoverComponent::GetCoverObjectScoreCorner(
        UFG::PlayerCoverComponent *this,
        UFG::PlayerCoverComponent::ScoredObject *scoredObject,
        UFG::PlayerCoverComponent::CoverObjectScoringParams *params)
{
  float v6; // xmm1_4
  float v7; // xmm0_4
  float CoverObjectPositionScore; // xmm6_4
  float result; // xmm0_4
  int v10[4]; // [rsp+20h] [rbp-38h] BYREF
  int v11[4]; // [rsp+30h] [rbp-28h] BYREF

  scoredObject->m_pCoverObject->vfptr->GetSyncPos(scoredObject->m_pCoverObject, (UFG::qVector3 *)v10);
  v6 = *(float *)&v10[1];
  LODWORD(scoredObject->m_vScorePosition.x) = v10[0];
  v7 = *(float *)&v10[2];
  scoredObject->m_vScorePosition.y = v6;
  scoredObject->m_vScorePosition.z = v7;
  CoverObjectPositionScore = UFG::PlayerCoverComponent::GetCoverObjectPositionScore(this, scoredObject, params);
  if ( CoverObjectPositionScore < 0.0 )
    return FLOAT_N1_0;
  scoredObject->m_pCoverObject->vfptr->GetSweetSpotDir(scoredObject->m_pCoverObject, (UFG::qVector3 *)v11);
  result = (float)((float)((float)((float)(*(float *)&v11[1] * params->m_vCameraDirection.y)
                                 + (float)(*(float *)v11 * params->m_vCameraDirection.x))
                         + (float)(*(float *)&v11[2] * params->m_vCameraDirection.z))
                 * UFG::PlayerCoverComponent::ms_fCoverScoreCameraDirectionMultiplier)
         + CoverObjectPositionScore;
  if ( result <= UFG::PlayerCoverComponent::ms_fCoverScoreMinimum )
    return FLOAT_N1_0;
  scoredObject->m_fScore = result;
  return result;
}

// File Line: 814
// RVA: 0x35BE50
float __fastcall UFG::PlayerCoverComponent::GetCoverObjectScoreParkourHandle(
        UFG::PlayerCoverComponent *this,
        UFG::PlayerCoverComponent::ScoredObject *scoredObject,
        UFG::PlayerCoverComponent::CoverObjectScoringParams *params)
{
  UFG::CoverObjectParkour *m_pCoverObject; // rbp
  float y; // xmm1_4
  float z; // xmm0_4
  float CoverObjectPositionScore; // xmm0_4
  float v10; // xmm6_4
  float v11; // xmm0_4
  float x; // xmm1_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  float fDirectionLength; // [rsp+20h] [rbp-58h]
  UFG::qVector3 result; // [rsp+30h] [rbp-48h] BYREF
  UFG::PlayerCoverComponent::ScoredObject scoredObjecta; // [rsp+40h] [rbp-38h] BYREF

  m_pCoverObject = (UFG::CoverObjectParkour *)scoredObject->m_pCoverObject;
  UFG::CoverObjectParkour::GetClosestParkourSync(
    (UFG::CoverObjectParkour *)scoredObject->m_pCoverObject,
    &result,
    &params->m_vActorPos);
  y = result.y;
  scoredObject->m_vScorePosition.x = result.x;
  z = result.z;
  scoredObject->m_vScorePosition.y = y;
  scoredObject->m_vScorePosition.z = z;
  CoverObjectPositionScore = UFG::PlayerCoverComponent::GetCoverObjectPositionScore(this, scoredObject, params);
  fDirectionLength = params->m_fMaxSearchDistance;
  v10 = CoverObjectPositionScore;
  scoredObjecta.m_pCoverObject = 0i64;
  scoredObjecta.m_fScore = -1.0;
  UFG::CoverObjectParkour::GetClosestParkourSyncInDirection(
    m_pCoverObject,
    &result,
    &params->m_vActorPos,
    &params->m_vActorMotionIntention,
    fDirectionLength);
  scoredObjecta.m_vScorePosition = result;
  v11 = UFG::PlayerCoverComponent::GetCoverObjectPositionScore(this, &scoredObjecta, params);
  if ( v11 > v10 )
  {
    x = scoredObjecta.m_vScorePosition.x;
    v10 = v11;
    scoredObject->m_fScore = scoredObjecta.m_fScore;
    v13 = scoredObjecta.m_vScorePosition.y;
    scoredObject->m_vScorePosition.x = x;
    v14 = scoredObjecta.m_vScorePosition.z;
    scoredObject->m_vScorePosition.y = v13;
    scoredObject->m_vScorePosition.z = v14;
    scoredObject->m_pCoverObject = m_pCoverObject;
  }
  if ( v10 < 0.0 )
    return FLOAT_N1_0;
  scoredObject->m_pCoverObject->vfptr->GetSweetSpotDir(scoredObject->m_pCoverObject, &result);
  v15 = (float)((float)((float)((float)(result.y * params->m_vCameraDirection.y)
                              + (float)(result.x * params->m_vCameraDirection.x))
                      + (float)(result.z * params->m_vCameraDirection.z))
              * UFG::PlayerCoverComponent::ms_fCoverScoreCameraDirectionMultiplier)
      + v10;
  if ( v15 <= UFG::PlayerCoverComponent::ms_fCoverScoreMinimum )
    return FLOAT_N1_0;
  scoredObject->m_fScore = v15;
  return v15;
}

// File Line: 864
// RVA: 0x37CC40
bool __fastcall UFG::PlayerCoverComponent::ProbeForCover(
        UFG::PlayerCoverComponent *this,
        UFG::qVector3 *vProbePos,
        bool bLatch,
        bool bStoreProbeCoverObject)
{
  bool v4; // di
  UFG::qVector3 *v5; // rsi
  UFG::PlayerCoverComponent::CoverObjectPosition *p; // rbp
  unsigned int v7; // ebx
  unsigned int capacity; // r15d
  UFG::PlayerCoverQuery *m_pCurrentPlayerCoverQuery; // r13
  unsigned int v10; // r12d
  UFG::CoverObjectBase *v11; // r14
  __int64 v12; // rax
  __int64 v13; // rsi
  __int64 v14; // rdi
  unsigned int v15; // edx
  UFG::PlayerCoverComponent::CoverObjectPosition *v16; // rdi
  UFG::CoverObjectBase *m_pCoverObject; // rcx
  bool v18; // zf
  UFG::CoverPosition *m_pCoverPosition; // rcx
  int v20; // eax
  bool result; // al
  UFG::qArray<UFG::PlayerCoverComponent::CoverObjectPosition,0> aCoverObjectPositions; // [rsp+28h] [rbp-70h] BYREF

  v4 = bStoreProbeCoverObject;
  v5 = vProbePos;
  if ( !this->m_pCurrentPlayerCoverQuery )
    return 0;
  p = 0i64;
  aCoverObjectPositions.p = 0i64;
  v7 = 0;
  aCoverObjectPositions.size = 0;
  capacity = 0;
  aCoverObjectPositions.capacity = 0;
  m_pCurrentPlayerCoverQuery = this->m_pCurrentPlayerCoverQuery;
  v10 = 0;
  if ( !m_pCurrentPlayerCoverQuery->m_aCoverObjects.size )
  {
LABEL_37:
    if ( p )
    {
      `eh vector destructor iterator(
        p,
        0x10ui64,
        (int)p[-1].m_pCoverPosition,
        (void (__fastcall *)(void *))UFG::PlayerCoverComponent::CoverObjectPosition::~CoverObjectPosition);
      operator delete[](&p[-1].m_pCoverPosition);
    }
    aCoverObjectPositions.p = 0i64;
    *(_QWORD *)&aCoverObjectPositions.size = 0i64;
    return 0;
  }
  do
  {
    v11 = m_pCurrentPlayerCoverQuery->m_aCoverObjects.p[v10];
    if ( !v11->vfptr->GetCoverObjectGroup(v11)
      && (*((unsigned __int8 (__fastcall **)(UFG::CoverObjectBase *))&v11->vfptr->__vecDelDtor + 2))(v11) )
    {
      v12 = ((__int64 (__fastcall *)(UFG::CoverObjectBase *, UFG::qVector3 *, _QWORD))v11->vfptr->GetCoverPosition)(
              v11,
              v5,
              0i64);
      v13 = v12;
      if ( v12 )
      {
        ++*(_DWORD *)(v12 + 8);
        if ( !bLatch && !v4 )
        {
          v18 = (*(_DWORD *)(v12 + 8))-- == 1;
          if ( v18 )
            (**(void (__fastcall ***)(__int64, __int64))v12)(v12, 1i64);
          goto LABEL_34;
        }
        v14 = v7++;
        if ( v7 > capacity )
        {
          v15 = 1;
          if ( capacity )
            v15 = 2 * capacity;
          for ( ; v15 < v7; v15 *= 2 )
            ;
          if ( v15 - v7 > 0x10000 )
            v15 = v7 + 0x10000;
          UFG::qArray<UFG::PlayerCoverComponent::CoverObjectPosition,0>::Reallocate(
            &aCoverObjectPositions,
            v15,
            "qArray.Add");
          p = aCoverObjectPositions.p;
          capacity = aCoverObjectPositions.capacity;
        }
        aCoverObjectPositions.size = v7;
        v16 = &p[v14];
        m_pCoverObject = v16->m_pCoverObject;
        if ( v16->m_pCoverObject )
        {
          v18 = m_pCoverObject->m_iRefCount-- == 1;
          if ( v18 )
            m_pCoverObject->vfptr->__vecDelDtor(m_pCoverObject, 1u);
          v16->m_pCoverObject = 0i64;
        }
        v16->m_pCoverObject = v11;
        ++v11->m_iRefCount;
        m_pCoverPosition = v16->m_pCoverPosition;
        if ( m_pCoverPosition )
        {
          v18 = m_pCoverPosition->m_iRefCount-- == 1;
          if ( v18 )
            m_pCoverPosition->vfptr->__vecDelDtor(m_pCoverPosition, 1u);
          v16->m_pCoverPosition = 0i64;
        }
        v16->m_pCoverPosition = (UFG::CoverPosition *)v13;
        v20 = *(_DWORD *)(v13 + 8);
        *(_DWORD *)(v13 + 8) = v20;
        if ( !v20 )
          (**(void (__fastcall ***)(__int64, __int64))v13)(v13, 1i64);
        v4 = bStoreProbeCoverObject;
      }
      v5 = vProbePos;
    }
    ++v10;
  }
  while ( v10 < m_pCurrentPlayerCoverQuery->m_aCoverObjects.size );
  if ( !v7 )
    goto LABEL_37;
  UFG::PlayerCoverComponent::SelectBestCoverPosition(this, &aCoverObjectPositions, bLatch, v4);
LABEL_34:
  if ( p )
  {
    `eh vector destructor iterator(
      p,
      0x10ui64,
      (int)p[-1].m_pCoverPosition,
      (void (__fastcall *)(void *))UFG::PlayerCoverComponent::CoverObjectPosition::~CoverObjectPosition);
    operator delete[](&p[-1].m_pCoverPosition);
  }
  result = 1;
  aCoverObjectPositions.p = 0i64;
  *(_QWORD *)&aCoverObjectPositions.size = 0i64;
  return result;
}

// File Line: 916
// RVA: 0x3840B0
void __fastcall UFG::PlayerCoverComponent::SelectBestCoverPosition(
        UFG::PlayerCoverComponent *this,
        UFG::qArray<UFG::PlayerCoverComponent::CoverObjectPosition,0> *aCoverObjectPositions,
        bool bLatch,
        bool bStoreProbeCoverObject)
{
  UFG::CoverObjectBase *m_pProbeCoverObject; // rcx
  UFG::CoverPosition *m_pCoverPosition; // rbx
  bool v10; // zf
  UFG::CoverPosition *v11; // rdx
  UFG::SimObjectGame *m_pSimObject; // rcx
  float *m_pComponent; // r14
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  float v16; // xmm6_4
  int v17; // ebx
  int v18; // r15d
  UFG::CoverObjectBase *m_pCoverObject; // rcx
  UFG::PlayerCoverComponent::CoverObjectPosition *v20; // rdi
  float *v21; // rax
  UFG::PlayerCoverComponent::CoverObjectPosition *v22; // rbx
  UFG::CoverObjectBase *v23; // rcx
  UFG::CoverObjectBase *v24; // rdi
  UFG::qVector3 v25; // [rsp+20h] [rbp-48h] BYREF

  if ( aCoverObjectPositions->size == 1 )
  {
    if ( bStoreProbeCoverObject )
    {
      m_pProbeCoverObject = this->m_pProbeCoverObject;
      m_pCoverPosition = aCoverObjectPositions->p->m_pCoverPosition;
      if ( m_pProbeCoverObject )
      {
        v10 = m_pProbeCoverObject->m_iRefCount-- == 1;
        if ( v10 )
          m_pProbeCoverObject->vfptr->__vecDelDtor(m_pProbeCoverObject, 1u);
        this->m_pProbeCoverObject = 0i64;
      }
      if ( m_pCoverPosition )
      {
        this->m_pProbeCoverObject = m_pCoverPosition;
        ++m_pCoverPosition->m_iRefCount;
      }
    }
    if ( bLatch )
    {
      UFG::PlayerCoverComponent::SetCoverObject(this, aCoverObjectPositions->p->m_pCoverObject);
      v11 = aCoverObjectPositions->p->m_pCoverPosition;
LABEL_40:
      this->vfptr[15].__vecDelDtor(this, (unsigned int)v11);
    }
  }
  else
  {
    m_pSimObject = (UFG::SimObjectGame *)this->m_pSimObject;
    if ( m_pSimObject )
    {
      m_Flags = m_pSimObject->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = (float *)m_pSimObject->m_Components.p[7].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 )
        {
          m_pComponent = (float *)m_pSimObject->m_Components.p[6].m_pComponent;
        }
        else
        {
          if ( (m_Flags & 0x1000) != 0 )
            ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                  m_pSimObject,
                                  UFG::ActionTreeComponent::_TypeUID);
          else
            ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::ActionTreeComponent::_TypeUID);
          m_pComponent = (float *)ComponentOfTypeHK;
        }
      }
      else
      {
        m_pComponent = (float *)m_pSimObject->m_Components.p[7].m_pComponent;
      }
    }
    else
    {
      m_pComponent = 0i64;
    }
    v16 = FLOAT_3_4028235e38;
    v17 = 0;
    v18 = 0;
    if ( aCoverObjectPositions->size )
    {
      while ( 1 )
      {
        m_pCoverObject = this->m_pCoverObject;
        v20 = &aCoverObjectPositions->p[v17];
        if ( m_pCoverObject )
        {
          if ( UFG::CoverObjectBase::IsAnyLineOrCornerShared(m_pCoverObject, v20->m_pCoverPosition) )
            break;
        }
        v21 = (float *)v20->m_pCoverPosition->vfptr->GetWallNormal(v20->m_pCoverPosition, &v25);
        if ( (float)((float)((float)(v21[1] * m_pComponent[140]) + (float)(m_pComponent[139] * *v21))
                   + (float)(v21[2] * m_pComponent[141])) < v16 )
        {
          v18 = v17;
          v16 = (float)((float)(v21[1] * m_pComponent[140]) + (float)(m_pComponent[139] * *v21))
              + (float)(v21[2] * m_pComponent[141]);
        }
        if ( ++v17 >= aCoverObjectPositions->size )
          goto LABEL_31;
      }
      v18 = v17;
    }
LABEL_31:
    v22 = &aCoverObjectPositions->p[v18];
    if ( bStoreProbeCoverObject )
    {
      v23 = this->m_pProbeCoverObject;
      v24 = v22->m_pCoverPosition;
      if ( v23 )
      {
        v10 = v23->m_iRefCount-- == 1;
        if ( v10 )
          v23->vfptr->__vecDelDtor(v23, 1u);
        this->m_pProbeCoverObject = 0i64;
      }
      if ( v24 )
      {
        this->m_pProbeCoverObject = v24;
        ++v24->m_iRefCount;
      }
    }
    if ( bLatch )
    {
      UFG::PlayerCoverComponent::SetCoverObject(this, v22->m_pCoverObject);
      v11 = v22->m_pCoverPosition;
      goto LABEL_40;
    }
  }
}

// File Line: 981
// RVA: 0x34A030
void __fastcall UFG::PlayerCoverComponent::BootAIOffCoverPosition(
        UFG::PlayerCoverComponent *this,
        UFG::CoverPosition *pCoverPosition)
{
  UFG::qNode<UFG::AICoverComponent,UFG::AICoverComponent> *p_mNode; // rcx
  UFG::qList<UFG::AICoverComponent,UFG::AICoverComponent,1,0> *v4; // rbx

  p_mNode = UFG::AICoverComponent::s_AICoverComponentList.mNode.mNext - 4;
  if ( (UFG::qList<UFG::AICoverComponent,UFG::AICoverComponent,1,0> *)&UFG::AICoverComponent::s_AICoverComponentList.mNode.mNext[-4] != &UFG::AICoverComponent::s_AICoverComponentList - 4 )
  {
    do
    {
      v4 = (UFG::qList<UFG::AICoverComponent,UFG::AICoverComponent,1,0> *)&p_mNode[4].mNext[-4];
      ((void (__fastcall *)(UFG::qNode<UFG::AICoverComponent,UFG::AICoverComponent> *, UFG::CoverPosition *))p_mNode->mPrev[8].mPrev)(
        p_mNode,
        pCoverPosition);
      p_mNode = &v4->mNode;
    }
    while ( v4 != &UFG::AICoverComponent::s_AICoverComponentList - 4 );
  }
}

