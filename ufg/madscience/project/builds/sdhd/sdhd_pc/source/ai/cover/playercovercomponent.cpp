// File Line: 45
// RVA: 0x335F10
void __fastcall UFG::PlayerCoverComponent::CoverObjectPosition::~CoverObjectPosition(UFG::PlayerCoverComponent::CoverObjectPosition *this)
{
  UFG::PlayerCoverComponent::CoverObjectPosition *v1; // rbx
  UFG::CoverObjectBase *v2; // rcx
  bool v3; // zf
  UFG::CoverPosition *v4; // rcx

  v1 = this;
  v2 = this->m_pCoverObject;
  if ( v2 )
  {
    v3 = v2->m_iRefCount-- == 1;
    if ( v3 )
      v2->vfptr->__vecDelDtor(v2, 1u);
    v1->m_pCoverObject = 0i64;
  }
  v4 = v1->m_pCoverPosition;
  if ( v4 )
  {
    v3 = v4->m_iRefCount-- == 1;
    if ( v3 )
      v4->vfptr->__vecDelDtor((UFG::CoverObjectBase *)&v4->vfptr, 1u);
    v1->m_pCoverPosition = 0i64;
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
  UFG::AICoverComponent::OnAttach((UFG::AICoverComponent *)&this->vfptr, object);
}

// File Line: 155
// RVA: 0x37B0A0
void __fastcall UFG::PlayerCoverComponent::OnDetach(UFG::PlayerCoverComponent *this)
{
  UFG::PlayerCoverComponent *v1; // rbx
  UFG::PlayerCoverQuery *v2; // rcx
  bool v3; // zf
  UFG::PlayerCoverQuery *v4; // rcx

  v1 = this;
  UFG::AICoverComponent::CancelQuery((UFG::AICoverComponent *)&this->vfptr);
  UFG::AICoverComponent::ClearCoverObjects((UFG::AICoverComponent *)&v1->vfptr);
  UFG::AICoverComponent::RemoveSimTargets((UFG::AICoverComponent *)&v1->vfptr);
  v2 = v1->m_pInProgressPlayerCoverQuery;
  if ( v2 )
  {
    v3 = v2->m_iRefCount-- == 1;
    if ( v3 )
      v2->vfptr->__vecDelDtor((UFG::AIQuery *)&v2->vfptr, 1u);
    v1->m_pInProgressPlayerCoverQuery = 0i64;
  }
  v4 = v1->m_pCurrentPlayerCoverQuery;
  if ( v4 )
  {
    v3 = v4->m_iRefCount-- == 1;
    if ( v3 )
      v4->vfptr->__vecDelDtor((UFG::AIQuery *)&v4->vfptr, 1u);
    v1->m_pCurrentPlayerCoverQuery = 0i64;
  }
}

// File Line: 164
// RVA: 0x364DE0
bool __fastcall UFG::PlayerCoverComponent::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SceneObjectProperties *v1; // rax
  UFG::qPropertySet *v2; // rcx

  v1 = pSceneObj;
  v2 = pSceneObj->mpWritableProperties;
  if ( !v2 )
    v2 = v1->mpConstProperties;
  return UFG::qPropertySet::GetParentFromName(
           v2,
           (UFG::qSymbol *)&SimSymX_propset_componentPlayerCover.mUID,
           DEPTH_RECURSE) != 0i64;
}

// File Line: 170
// RVA: 0x37E640
UFG::SimComponent *__fastcall UFG::PlayerCoverComponent::PropertiesOnActivate(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SceneObjectProperties *v1; // rdi
  UFG::qMemoryPool *v2; // rax
  UFG::allocator::free_link *v3; // rax
  UFG::SimComponent *v4; // rbx
  UFG::qPropertySet *v5; // r8
  UFG::SimObjectModifier v7; // [rsp+38h] [rbp-30h]

  v1 = pSceneObj;
  v2 = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(v2, 0xD8ui64, "PlayerCoverComponent", 0i64, 1u);
  v4 = (UFG::SimComponent *)v3;
  if ( v3 )
  {
    v5 = v1->mpWritableProperties;
    if ( !v5 )
      v5 = v1->mpConstProperties;
    UFG::AICoverComponent::AICoverComponent((UFG::AICoverComponent *)v3, v1->m_NameUID, v5, 0);
    v4->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::PlayerCoverComponent::`vftable';
    UFG::SimComponent::AddType(v4, UFG::PlayerCoverComponent::_PlayerCoverComponentTypeUID, "PlayerCoverComponent");
  }
  else
  {
    v4 = 0i64;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v7, v1->m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v7, v4, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v7);
  UFG::SimObjectModifier::~SimObjectModifier(&v7);
  return v4;
}

// File Line: 178
// RVA: 0x391FF0
void __fastcall UFG::PlayerCoverComponent::Update(UFG::PlayerCoverComponent *this, float fDeltaTime)
{
  UFG::SimObject *v2; // rax
  UFG::PlayerCoverComponent *v3; // rbx
  UFG::SimObjectGame *v4; // rcx
  unsigned __int16 v5; // dx
  UFG::SimComponent *v6; // rax
  UFG::PlayerCoverQuery *v7; // rcx
  bool v8; // zf
  UFG::PlayerCoverQuery *v9; // rcx
  UFG::AICoverQuery *v10; // rcx
  UFG::AICoverQuery *v11; // rcx

  v2 = this->m_pSimObject;
  v3 = this;
  if ( !v2 || !((v2->m_Flags >> 10) & 1) )
  {
    UFG::AICoverComponent::ValidateCover((UFG::AICoverComponent *)&this->vfptr, 0);
    v4 = (UFG::SimObjectGame *)v3->m_pSimObject;
    if ( v4
      && ((v5 = v4->m_Flags, !((v5 >> 14) & 1)) ? ((v5 & 0x8000u) == 0 ? (!((v5 >> 13) & 1) ? (!((v5 >> 12) & 1) ? (v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::CharacterOccupantComponent::_TypeUID)) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::CharacterOccupantComponent::_TypeUID))) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::CharacterOccupantComponent::_TypeUID))) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::CharacterOccupantComponent::_TypeUID))) : (v6 = v4->m_Components.p[44].m_pComponent),
          v6) )
    {
      v7 = v3->m_pInProgressPlayerCoverQuery;
      if ( v7 )
      {
        v8 = v7->m_iRefCount-- == 1;
        if ( v8 )
          v7->vfptr->__vecDelDtor((UFG::AIQuery *)&v7->vfptr, 1u);
        v3->m_pInProgressPlayerCoverQuery = 0i64;
      }
      v9 = v3->m_pCurrentPlayerCoverQuery;
      if ( v9 )
      {
        v8 = v9->m_iRefCount-- == 1;
        if ( v8 )
          v9->vfptr->__vecDelDtor((UFG::AIQuery *)&v9->vfptr, 1u);
        v3->m_pCurrentPlayerCoverQuery = 0i64;
      }
    }
    else
    {
      v10 = (UFG::AICoverQuery *)&v3->m_pCurrentPlayerCoverQuery->vfptr;
      if ( v10 )
      {
        UFG::AICoverQuery::ResetParkourLifetimes(v10);
        UFG::PlayerCoverComponent::UpdateCurrentCoverObject(v3);
      }
      v11 = (UFG::AICoverQuery *)&v3->m_pInProgressPlayerCoverQuery->vfptr;
      if ( v11 )
        UFG::AICoverQuery::ResetParkourLifetimes(v11);
      else
        UFG::PlayerCoverComponent::SubmitPlayerCoverQuery(v3);
      UFG::AICoverComponent::UpdateSimTargets((UFG::AICoverComponent *)&v3->vfptr);
      UFG::AICoverComponent::SetSyncCoverPosition((UFG::AICoverComponent *)&v3->vfptr, v3->m_pCurrentCoverPosition, 0);
    }
  }
}

// File Line: 237
// RVA: 0x394730
void __fastcall UFG::PlayerCoverComponent::UpdateCoverQuery(UFG::PlayerCoverComponent *this)
{
  UFG::PlayerCoverComponent *v1; // rbx
  UFG::ActiveAIEntityComponent *v2; // rax
  int v3; // xmm0_4
  UFG::PlayerCoverQuery *v4; // rcx
  UFG::PlayerCoverQuery *v5; // rax
  fastdelegate::detail::GenericClass *v6; // rcx
  UFG::PlayerCoverQuery *v7; // rcx
  UFG::PlayerCoverQuery *v8; // rdi
  bool v9; // zf
  UFG::PlayerCoverQuery *v10; // rcx
  int v11; // [rsp+30h] [rbp+8h]

  v1 = this;
  if ( this->m_pInProgressPlayerCoverQuery )
  {
    v2 = LocalPlayer ? UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>((UFG::SimObjectCVBase *)&LocalPlayer->vfptr) : 0i64;
    v3 = v2->m_CurrentObjective == 10 ? LODWORD(FLOAT_0_1) : LODWORD(FLOAT_0_00030000001);
    v4 = v1->m_pInProgressPlayerCoverQuery;
    v11 = v3;
    v4->vfptr->Update((UFG::AIQuery *)&v4->vfptr, (float *)&v11, 0);
    v5 = v1->m_pInProgressPlayerCoverQuery;
    if ( v5->m_uState == 13 )
    {
      v6 = v5->m_queryFinishedDelegate.m_Closure.m_pthis;
      if ( v6 || v5->m_queryFinishedDelegate.m_Closure.m_pFunction )
        ((void (__fastcall *)(fastdelegate::detail::GenericClass *, UFG::PlayerCoverQuery *))v5->m_queryFinishedDelegate.m_Closure.m_pFunction)(
          v6,
          v5);
      v7 = v1->m_pCurrentPlayerCoverQuery;
      v8 = v1->m_pInProgressPlayerCoverQuery;
      if ( v7 )
      {
        v9 = v7->m_iRefCount-- == 1;
        if ( v9 )
          v7->vfptr->__vecDelDtor((UFG::AIQuery *)&v7->vfptr, 1u);
        v1->m_pCurrentPlayerCoverQuery = 0i64;
      }
      if ( v8 )
      {
        ++v8->m_iRefCount;
        v1->m_pCurrentPlayerCoverQuery = v8;
      }
      v10 = v1->m_pInProgressPlayerCoverQuery;
      if ( v10 )
      {
        v9 = v10->m_iRefCount-- == 1;
        if ( v9 )
          v10->vfptr->__vecDelDtor((UFG::AIQuery *)&v10->vfptr, 1u);
        v1->m_pInProgressPlayerCoverQuery = 0i64;
      }
    }
  }
}

// File Line: 261
// RVA: 0x394D70
void __fastcall UFG::PlayerCoverComponent::UpdateCurrentCoverObject(UFG::PlayerCoverComponent *this)
{
  UFG::PlayerCoverComponent *v1; // rdi
  UFG::CoverObjectBase *v2; // rcx
  UFG::CoverObjectBase *v3; // rcx
  bool v4; // zf
  UFG::CoverPosition *v5; // rcx
  UFG::CoverObjectBase *v6; // rbx
  UFG::CoverObjectBaseVtbl *v7; // rbx
  UFG::qVector3 *v8; // rax
  __int64 v9; // rax
  UFG::CoverPosition *v10; // rbx
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v11; // rbx
  UFG::qVector3 *v12; // rax
  __int64 v13; // r8
  UFG::CoverObjectBase *v14; // rcx
  UFG::CoverPosition *v15; // rcx
  UFG::CoverPosition *v16; // rcx
  UFG::SimObjectGame *v17; // rcx
  unsigned __int16 v18; // dx
  UFG::WorldContextComponent *v19; // rax
  UFG::qVector3 result; // [rsp+20h] [rbp-18h]

  v1 = this;
  v2 = this->m_pCoverObject;
  if ( v2 && !(*((unsigned __int8 (**)(void))&v2->vfptr->__vecDelDtor + 2))() )
  {
    v3 = v1->m_pCoverObject;
    if ( v3 )
    {
      v4 = v3->m_iRefCount-- == 1;
      if ( v4 )
        v3->vfptr->__vecDelDtor(v3, 1u);
      v1->m_pCoverObject = 0i64;
    }
    v5 = v1->m_pCurrentCoverPosition;
    if ( v5 && v1->m_pCoverObject && !((unsigned __int8 (*)(void))v5->vfptr->operator==)() )
    {
      v1->vfptr[15].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v1->vfptr, 0);
      UFG::AICoverComponent::SetSyncCoverPosition((UFG::AICoverComponent *)&v1->vfptr, 0i64, 1);
    }
    v1->vfptr[15].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v1->vfptr, 0);
    UFG::AICoverComponent::SetSyncCoverPosition((UFG::AICoverComponent *)&v1->vfptr, 0i64, 0);
  }
  if ( v1->m_iHoldCoverPositionRefs > 0 && (v6 = v1->m_pCoverObject) != 0i64 )
  {
    v7 = v6->vfptr;
    v8 = UFG::AICoverComponent::GetActorPosition((UFG::AICoverComponent *)&v1->vfptr, &result);
    v9 = ((__int64 (__fastcall *)(UFG::CoverObjectBase *, UFG::qVector3 *, _QWORD))v7->GetCoverPosition)(
           v1->m_pCoverObject,
           v8,
           0i64);
    v10 = (UFG::CoverPosition *)v9;
    if ( v9 )
    {
      ++*(_DWORD *)(v9 + 8);
      v1->vfptr[15].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v1->vfptr, v9);
      UFG::AICoverComponent::SetSyncCoverPosition((UFG::AICoverComponent *)&v1->vfptr, v10, 0);
      v4 = v10->m_iRefCount-- == 1;
      if ( v4 )
        v10->vfptr->__vecDelDtor((UFG::CoverObjectBase *)&v10->vfptr, 1u);
    }
  }
  else
  {
    v11 = v1->vfptr;
    v12 = UFG::AICoverComponent::GetActorPosition((UFG::AICoverComponent *)&v1->vfptr, &result);
    LOBYTE(v13) = 1;
    if ( !((unsigned __int8 (__fastcall *)(UFG::PlayerCoverComponent *, UFG::qVector3 *, __int64, _QWORD))v11[17].__vecDelDtor)(
            v1,
            v12,
            v13,
            0i64) )
    {
      v14 = v1->m_pCoverObject;
      if ( v14 )
      {
        v4 = v14->m_iRefCount-- == 1;
        if ( v4 )
          v14->vfptr->__vecDelDtor(v14, 1u);
        v1->m_pCoverObject = 0i64;
      }
      v15 = v1->m_pCurrentCoverPosition;
      if ( v15 && v1->m_pCoverObject && !((unsigned __int8 (*)(void))v15->vfptr->operator==)() )
      {
        v1->vfptr[15].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v1->vfptr, 0);
        UFG::AICoverComponent::SetSyncCoverPosition((UFG::AICoverComponent *)&v1->vfptr, 0i64, 1);
      }
      v1->vfptr[15].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v1->vfptr, 0);
      if ( !v1->m_iHoldCoverPositionRefs || !v1->m_pSyncCoverPosition )
      {
        v16 = v1->m_pSyncCoverPosition;
        if ( v16 )
        {
          v4 = v16->m_iRefCount-- == 1;
          if ( v4 )
            v16->vfptr->__vecDelDtor((UFG::CoverObjectBase *)&v16->vfptr, 1u);
          v1->m_pSyncCoverPosition = 0i64;
        }
        v17 = (UFG::SimObjectGame *)v1->m_pSimObject;
        if ( v17 )
        {
          v18 = v17->m_Flags;
          if ( (v18 >> 14) & 1 )
          {
            v19 = (UFG::WorldContextComponent *)v17->m_Components.p[28].m_pComponent;
          }
          else if ( (v18 & 0x8000u) == 0 )
          {
            if ( (v18 >> 13) & 1 )
              v19 = (UFG::WorldContextComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    v17,
                                                    UFG::WorldContextComponent::_TypeUID);
            else
              v19 = (UFG::WorldContextComponent *)((v18 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                       v17,
                                                                       UFG::WorldContextComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v17->vfptr, UFG::WorldContextComponent::_TypeUID));
          }
          else
          {
            v19 = (UFG::WorldContextComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  v17,
                                                  UFG::WorldContextComponent::_TypeUID);
          }
          if ( v19 )
            UFG::WorldContextComponent::SetCoverPosition(v19, v1->m_pSyncCoverPosition);
        }
      }
    }
  }
}

// File Line: 297
// RVA: 0x385140
void __fastcall UFG::PlayerCoverComponent::SetCoverObject(UFG::PlayerCoverComponent *this, UFG::CoverObjectBase *pCoverObject)
{
  UFG::PlayerCoverComponent *v2; // rbx
  UFG::CoverObjectBase *v3; // rcx
  UFG::CoverObjectBase *v4; // rdi
  bool v5; // zf
  UFG::CoverPosition *v6; // rcx

  v2 = this;
  v3 = this->m_pCoverObject;
  v4 = pCoverObject;
  if ( v3 )
  {
    v5 = v3->m_iRefCount-- == 1;
    if ( v5 )
      v3->vfptr->__vecDelDtor(v3, 1u);
    v2->m_pCoverObject = 0i64;
  }
  if ( v4 )
  {
    v2->m_pCoverObject = v4;
    ++v4->m_iRefCount;
  }
  v6 = v2->m_pCurrentCoverPosition;
  if ( v6 && v2->m_pCoverObject && !((unsigned __int8 (*)(void))v6->vfptr->operator==)() )
  {
    v2->vfptr[15].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v2->vfptr, 0);
    UFG::AICoverComponent::SetSyncCoverPosition((UFG::AICoverComponent *)&v2->vfptr, 0i64, 1);
  }
}

// File Line: 327
// RVA: 0x3895A0
void __fastcall UFG::PlayerCoverComponent::SubmitPlayerCoverQuery(UFG::PlayerCoverComponent *this)
{
  UFG::PlayerCoverComponent *v1; // rbp
  UFG::allocator::free_link *v2; // rax
  UFG::allocator::free_link *v3; // rbx
  UFG::SimObject *v4; // rdx
  UFG::allocator::free_link *v5; // rcx
  UFG::allocator::free_link *v6; // rax
  UFG::allocator::free_link *v7; // rax
  UFG::allocator::free_link *v8; // rax
  UFG::PlayerCoverQuery *v9; // rsi
  UFG::PlayerCoverQuery *v10; // rbp
  UFG::AICoverSearchParams *v11; // rsi
  bool v12; // zf

  v1 = this;
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
    v4 = v1->m_pSimObject;
    if ( v3[2].mNext )
    {
      v5 = v3->mNext;
      v6 = v3[1].mNext;
      v5[1].mNext = v6;
      v6->mNext = v5;
      v3->mNext = v3;
      v3[1].mNext = v3;
    }
    v3[2].mNext = (UFG::allocator::free_link *)v4;
    if ( v4 )
    {
      v7 = (UFG::allocator::free_link *)v4->m_SafePointerList.mNode.mPrev;
      v7[1].mNext = v3;
      v3->mNext = v7;
      v3[1].mNext = (UFG::allocator::free_link *)&v4->m_SafePointerList;
      v4->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)v3;
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
      v9->vfptr = (UFG::AIQueryVtbl *)&UFG::PlayerCoverQuery::`vftable';
    }
    else
    {
      v9 = 0i64;
    }
    v1->m_pInProgressPlayerCoverQuery = v9;
    ++v9->m_iRefCount;
    v10 = v1->m_pInProgressPlayerCoverQuery;
    v11 = v10->m_pSearchParams;
    if ( v11 )
    {
      v12 = v11->m_iRefCount-- == 1;
      if ( v12 )
      {
        UFG::AICoverSearchParams::~AICoverSearchParams(v11);
        operator delete[](v11);
      }
      v10->m_pSearchParams = 0i64;
    }
    v10->m_pSearchParams = (UFG::AICoverSearchParams *)v3;
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
void __fastcall UFG::PlayerCoverComponent::SetCurrentCoverPosition(UFG::PlayerCoverComponent *this, UFG::CoverPosition *pCoverPosition)
{
  UFG::CoverPosition *v2; // rbx
  UFG::PlayerCoverComponent *v3; // rdi

  v2 = pCoverPosition;
  v3 = this;
  if ( pCoverPosition && !pCoverPosition->vfptr->CanUse((UFG::CoverObjectBase *)pCoverPosition, this->m_pSimObject) )
    UFG::PlayerCoverComponent::BootAIOffCoverPosition(v3, v2);
  UFG::AICoverComponent::SetCurrentCoverPosition((UFG::AICoverComponent *)&v3->vfptr, v2);
  UFG::AICoverComponent::SetSyncCoverPosition((UFG::AICoverComponent *)&v3->vfptr, v2, 0);
  UFG::AICoverComponent::SetTargetedCoverPosition((UFG::AICoverComponent *)&v3->vfptr, v2);
}

// File Line: 399
// RVA: 0x37CEC0
char __fastcall UFG::PlayerCoverComponent::ProbeForPlayerCover(UFG::PlayerCoverComponent *this, float fMinSearchDistance, float fMaxSearchDistance, float fBufferZoneSize, __int64 bLatch)
{
  UFG::PlayerCoverComponent *v5; // r13
  UFG::SimObjectCVBase *v6; // rcx
  UFG::AICharacterControllerBaseComponent *v7; // rax
  unsigned __int16 v8; // dx
  UFG::BaseCameraComponent *v9; // rdi
  int v10; // xmm2_4
  int v11; // xmm8_4
  float v12; // xmm1_4
  float v13; // xmm1_4
  float v14; // xmm8_4
  UFG::CoverPosition *v15; // rcx
  _DWORD *v16; // rax
  int v17; // xmm14_4
  int v18; // xmm13_4
  int v19; // xmm12_4
  float v20; // xmm11_4
  float v21; // xmm10_4
  float v22; // xmm9_4
  float v23; // xmm2_4
  float v24; // xmm1_4
  float v25; // xmm11_4
  float v26; // xmm10_4
  float v27; // xmm9_4
  float v28; // xmm4_4
  float v29; // xmm5_4
  float v30; // xmm2_4
  float v31; // xmm3_4
  float v32; // xmm6_4
  float v33; // xmm0_4
  float v34; // xmm15_4
  float v35; // xmm2_4
  UFG::SimObject *v36; // rbx
  __int128 v37; // xmm2
  __int128 v38; // xmm1
  __int128 v39; // xmm0
  float v40; // xmm6_4
  float v41; // xmm12_4
  float v42; // xmm2_4
  float v43; // xmm13_4
  float v44; // xmm2_4
  float v45; // xmm7_4
  float v46; // xmm14_4
  float v47; // xmm7_4
  int v48; // xmm1_4
  int v49; // xmm2_4
  float v50; // xmm0_4
  float *v51; // rdi
  float v52; // ebx
  float v53; // er15
  float v54; // xmm6_4
  unsigned int v55; // esi
  signed __int64 v56; // rax
  __int64 v57; // r12
  UFG::CoverObjectBase *v58; // r14
  __int64 v59; // r12
  UFG::CoverObjectBase *v60; // rsi
  __int64 v61; // rsi
  unsigned int v62; // edx
  signed __int64 v63; // rcx
  float v64; // xmm2_4
  __int64 v65; // r14
  unsigned int v66; // edx
  signed __int64 v67; // rcx
  float v68; // xmm2_4
  char v69; // r14
  signed __int64 v70; // r15
  UFG::CoverObjectBase *v71; // r12
  UFG::CoverObjectBase *v72; // rax
  UFG::CoverObjectBase *v73; // rsi
  float v74; // xmm8_4
  float v75; // xmm7_4
  float v76; // xmm6_4
  float *v77; // rax
  float v78; // xmm8_4
  float v79; // xmm7_4
  UFG::SimObjectGame *v80; // rcx
  UFG::SensorComponent *v81; // r14
  unsigned __int16 v82; // dx
  UFG::SimComponent *v83; // rax
  UFG::SimObjectGame *v84; // rcx
  UFG::CharacterPhysicsComponent *v85; // rax
  unsigned __int16 v86; // dx
  float v87; // xmm0_4
  UFG::CoverObjectBase *v88; // rcx
  bool v89; // zf
  __int64 v90; // rdx
  float v91; // xmm1_4
  float v92; // xmm2_4
  float v93; // xmm1_4
  unsigned int v94; // eax
  float *v95; // rcx
  float v97; // [rsp+40h] [rbp-88h]
  int v98; // [rsp+40h] [rbp-88h]
  UFG::qVector3 result; // [rsp+48h] [rbp-80h]
  UFG::PlayerCoverComponent::ScoredObject scoredObject; // [rsp+58h] [rbp-70h]
  UFG::qVector3 start; // [rsp+70h] [rbp-58h]
  int v102; // [rsp+7Ch] [rbp-4Ch]
  float v103; // [rsp+80h] [rbp-48h]
  float v104; // [rsp+84h] [rbp-44h]
  int v105; // [rsp+88h] [rbp-40h]
  int v106; // [rsp+8Ch] [rbp-3Ch]
  float v107; // [rsp+90h] [rbp-38h]
  float v108; // [rsp+94h] [rbp-34h]
  float v109; // [rsp+98h] [rbp-30h]
  int v110; // [rsp+9Ch] [rbp-2Ch]
  float v111; // [rsp+A0h] [rbp-28h]
  char v112; // [rsp+A4h] [rbp-24h]
  char v113; // [rsp+A5h] [rbp-23h]
  char v114; // [rsp+A6h] [rbp-22h]
  char v115; // [rsp+A7h] [rbp-21h]
  char v116; // [rsp+A8h] [rbp-20h]
  __int128 v117; // [rsp+B8h] [rbp-10h]
  __int128 v118; // [rsp+C8h] [rbp+0h]
  __int128 v119; // [rsp+D8h] [rbp+10h]
  __int128 v120; // [rsp+E8h] [rbp+20h]
  __int64 v121; // [rsp+F8h] [rbp+30h]
  float v122; // [rsp+1E8h] [rbp+120h]
  int v123; // [rsp+1F8h] [rbp+130h]
  float v124; // [rsp+200h] [rbp+138h]
  char v125; // [rsp+208h] [rbp+140h]
  char vars0; // [rsp+210h] [rbp+148h]
  void *retaddr; // [rsp+218h] [rbp+150h]
  char v128; // [rsp+220h] [rbp+158h]
  char v129; // [rsp+228h] [rbp+160h]
  float v130; // [rsp+230h] [rbp+168h]
  float v131; // [rsp+238h] [rbp+170h]

  v131 = fBufferZoneSize;
  v130 = fMaxSearchDistance;
  v121 = -2i64;
  v5 = this;
  if ( !this->m_pCurrentPlayerCoverQuery )
    return 0;
  UFG::AICoverComponent::GetActorPosition((UFG::AICoverComponent *)&this->vfptr, &result);
  v6 = (UFG::SimObjectCVBase *)v5->m_pSimObject;
  if ( v6 )
  {
    v8 = v6->m_Flags;
    if ( (v8 >> 14) & 1 )
    {
      v7 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v6);
    }
    else if ( (v8 & 0x8000u) == 0 )
    {
      if ( (v8 >> 13) & 1 )
      {
        v7 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          (UFG::SimObjectGame *)&v6->vfptr,
                                                          UFG::AICharacterControllerBaseComponent::_TypeUID);
      }
      else if ( (v8 >> 12) & 1 )
      {
        v7 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          (UFG::SimObjectGame *)&v6->vfptr,
                                                          UFG::AICharacterControllerBaseComponent::_TypeUID);
      }
      else
      {
        v7 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                          (UFG::SimObject *)&v6->vfptr,
                                                          UFG::AICharacterControllerBaseComponent::_TypeUID);
      }
    }
    else
    {
      v7 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v6);
    }
  }
  else
  {
    v7 = 0i64;
  }
  v97 = v7->m_Intention.mMotionIntentionDirection.x;
  HIDWORD(scoredObject.m_pCoverObject) = LODWORD(v7->m_Intention.mMotionIntentionDirection.y);
  *(float *)&scoredObject.m_pCoverObject = v7->m_Intention.mMotionIntentionDirection.z;
  scoredObject.m_fScore = v7->m_Intention.mMotionIntentionSpeed;
  v9 = UFG::Director::Get()->mCurrentCamera;
  if ( v9 )
    v9 = (UFG::BaseCameraComponent *)((char *)v9 + 80);
  v10 = LODWORD(v9->mCamera.mView.v1.y) ^ _xmm[0];
  v11 = LODWORD(v9->mCamera.mView.v1.x) ^ _xmm[0];
  v12 = (float)(*(float *)&v11 * *(float *)&v11) + (float)(*(float *)&v10 * *(float *)&v10);
  if ( v12 == 0.0 )
    v13 = 0.0;
  else
    v13 = 1.0 / fsqrt(v12);
  start.x = v13 * 0.0;
  scoredObject.m_vScorePosition.x = v13 * *(float *)&v10;
  v14 = *(float *)&v11 * v13;
  v15 = v5->m_pCurrentCoverPosition;
  if ( v15 && (*((unsigned __int8 (**)(void))&v15->vfptr->__vecDelDtor + 2))() )
  {
    v16 = (_DWORD *)v5->m_pCurrentCoverPosition->vfptr->GetWallNormal(
                      (UFG::CoverObjectBase *)&v5->m_pCurrentCoverPosition->vfptr,
                      (UFG::qVector3 *)&scoredObject);
    v17 = v16[2] ^ _xmm[0];
    v18 = v16[1] ^ _xmm[0];
    v19 = *v16 ^ _xmm[0];
    v20 = (float)(*(float *)&v18 * UFG::qVector3::msDirUp.x) - (float)(*(float *)&v19 * UFG::qVector3::msDirUp.y);
    v21 = (float)(*(float *)&v19 * UFG::qVector3::msDirUp.z) - (float)(*(float *)&v17 * UFG::qVector3::msDirUp.x);
    v22 = (float)(*(float *)&v17 * UFG::qVector3::msDirUp.y) - (float)(*(float *)&v18 * UFG::qVector3::msDirUp.z);
    v23 = (float)((float)(v22 * v22) + (float)(v21 * v21)) + (float)(v20 * v20);
    if ( v23 == 0.0 )
      v24 = 0.0;
    else
      v24 = 1.0 / fsqrt(v23);
    v25 = v20 * v24;
    v26 = v21 * v24;
    v27 = v22 * v24;
    v28 = (float)(v26 * *(float *)&v19) - (float)(v27 * *(float *)&v18);
    v29 = (float)(v27 * *(float *)&v17) - (float)(v25 * *(float *)&v19);
    v30 = (float)(v25 * *(float *)&v18) - (float)(v26 * *(float *)&v17);
    v31 = (float)((float)(v30 * v30) + (float)(v29 * v29)) + (float)(v28 * v28);
    if ( v31 == 0.0 )
      v32 = 0.0;
    else
      v32 = 1.0 / fsqrt(v31);
    v33 = v32 * v28;
    v34 = v32 * v29;
    v35 = v30 * v32;
  }
  else
  {
    v36 = v5->m_pSimObject;
    if ( v36 )
      v36 = (UFG::SimObject *)v36->m_pTransformNodeComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v36);
    v37 = *(_OWORD *)&v36[1].m_SafePointerList.mNode.mNext;
    v38 = *(_OWORD *)&v36[1].m_SafePointerWithCallbackList.mNode.mNext;
    v39 = *(_OWORD *)v36[1].mNode.mChild;
    v117 = *(_OWORD *)&v36[1].vfptr;
    v118 = v37;
    v119 = v38;
    v120 = v39;
    v33 = *((float *)&v38 + 2);
    v34 = *((float *)&v119 + 1);
    v35 = *(float *)&v38;
    v25 = *((float *)&v118 + 2);
    v26 = *((float *)&v118 + 1);
    v27 = *(float *)&v118;
    v17 = SDWORD2(v117);
    v18 = SDWORD1(v117);
    v19 = v117;
  }
  v122 = v33;
  v40 = (float)((float)(*(float *)bLatch * *(float *)&v19) + (float)(*(float *)(bLatch + 4) * v27))
      + (float)(*(float *)(bLatch + 8) * v35);
  v41 = result.x;
  v42 = (float)((float)(*(float *)bLatch * *(float *)&v18) + (float)(*(float *)(bLatch + 4) * v26))
      + (float)(*(float *)(bLatch + 8) * v34);
  v43 = result.y;
  v44 = v42 + (float)(*(float *)(bLatch + 12) * result.y);
  v45 = (float)((float)(*(float *)bLatch * *(float *)&v17) + (float)(*(float *)(bLatch + 4) * v25))
      + (float)(*(float *)(bLatch + 8) * v33);
  v46 = result.z;
  v47 = v45 + (float)(*(float *)(bLatch + 12) * result.z);
  scoredObject.m_vScorePosition.y = v40 + (float)(*(float *)(bLatch + 12) * result.x);
  scoredObject.m_vScorePosition.z = v44;
  start.x = v47;
  start.y = v97;
  start.z = *((float *)&scoredObject.m_pCoverObject + 1);
  v102 = (int)scoredObject.m_pCoverObject;
  v103 = scoredObject.m_fScore;
  v48 = LODWORD(v9->mCamera.mView.v2.y);
  v49 = LODWORD(v9->mCamera.mView.v2.z);
  v104 = v9->mCamera.mView.v2.x;
  v105 = v48;
  v106 = v49;
  v107 = v14;
  v108 = scoredObject.m_vScorePosition.x;
  v109 = v47;
  v110 = v123;
  v50 = v124;
  v111 = v124;
  v112 = (char)retaddr;
  v113 = v128;
  v114 = v129;
  v115 = LOBYTE(v130);
  v116 = LOBYTE(v131);
  v51 = 0i64;
  *(_QWORD *)&result.z = 0i64;
  v52 = 0.0;
  *(_QWORD *)&result.x = 0i64;
  v53 = 0.0;
  v54 = FLOAT_N1_0;
  v55 = 0;
  v98 = 0;
  v56 = (signed __int64)&v5->m_pCurrentPlayerCoverQuery->m_aCoverObjects;
  *(_QWORD *)&start.x = v56;
  v57 = 0i64;
  v122 = 0.0;
  if ( *(_DWORD *)v56 )
  {
    do
    {
      v58 = *(UFG::CoverObjectBase **)(*(_QWORD *)(v56 + 8) + 8 * v57);
      if ( (*((unsigned __int8 (__fastcall **)(UFG::CoverObjectBase *))&v58->vfptr->__vecDelDtor + 3))(v58)
        && (*((unsigned __int8 (__fastcall **)(UFG::CoverObjectBase *))&v58->vfptr->__vecDelDtor + 2))(v58) )
      {
        v59 = 0i64;
        if ( LODWORD(v58[1].vfptr) )
        {
          do
          {
            v60 = *(UFG::CoverObjectBase **)(*(_QWORD *)&v58[1].m_iRefCount + 8 * v59);
            if ( !v60 )
              goto LABEL_119;
            if ( !(*((unsigned __int8 (__fastcall **)(UFG::CoverObjectBase *))&v60->vfptr->__vecDelDtor + 2))(v60) )
              goto LABEL_119;
            scoredObject.m_pCoverObject = v60;
            scoredObject.m_fScore = -1.0;
            UFG::PlayerCoverComponent::GetCoverObjectScore(
              v5,
              &scoredObject,
              (UFG::PlayerCoverComponent::CoverObjectScoringParams *)&scoredObject.m_vScorePosition.y,
              v50);
            if ( v50 < 0.0 )
              goto LABEL_119;
            v61 = LODWORD(v52);
            if ( ++LODWORD(v52) > LODWORD(v53) )
            {
              v62 = 1;
              if ( v53 != 0.0 )
                v62 = 2 * LODWORD(v53);
              for ( ; v62 < LODWORD(v52); v62 *= 2 )
                ;
              if ( v62 - LODWORD(v52) > 0x10000 )
                v62 = LODWORD(v52) + 0x10000;
              UFG::qArray<UFG::PlayerCoverComponent::ScoredObject,0>::Reallocate(
                (UFG::qArray<UFG::PlayerCoverComponent::ScoredObject,0> *)&result,
                v62,
                "qArray.Add");
              v51 = *(float **)&result.z;
              v53 = result.y;
            }
            result.x = v52;
            v63 = 3 * v61;
            *(_QWORD *)&v51[2 * v63] = v58;
            v64 = scoredObject.m_fScore;
            v51[2 * v63 + 2] = scoredObject.m_fScore;
            v51[2 * v63 + 3] = scoredObject.m_vScorePosition.x;
            v51[2 * v63 + 4] = scoredObject.m_vScorePosition.y;
            v50 = scoredObject.m_vScorePosition.z;
            v51[2 * v63 + 5] = scoredObject.m_vScorePosition.z;
            if ( v64 > v54 )
            {
              v54 = v64;
              v55 = LODWORD(v52) - 1;
              v98 = LODWORD(v52) - 1;
            }
            else
            {
LABEL_119:
              v55 = v98;
            }
            v59 = (unsigned int)(v59 + 1);
          }
          while ( (unsigned int)v59 < LODWORD(v58[1].vfptr) );
        }
        *(float *)&v57 = v122;
      }
      if ( !(__int64)v58->vfptr->GetCoverObjectGroup(v58) )
      {
        if ( (*((unsigned __int8 (__fastcall **)(UFG::CoverObjectBase *))&v58->vfptr->__vecDelDtor + 2))(v58) )
        {
          scoredObject.m_pCoverObject = v58;
          scoredObject.m_fScore = -1.0;
          UFG::PlayerCoverComponent::GetCoverObjectScore(
            v5,
            &scoredObject,
            (UFG::PlayerCoverComponent::CoverObjectScoringParams *)&scoredObject.m_vScorePosition.y,
            v50);
          if ( v50 >= 0.0 )
          {
            v65 = LODWORD(v52);
            if ( ++LODWORD(v52) > LODWORD(v53) )
            {
              v66 = 1;
              if ( v53 != 0.0 )
                v66 = 2 * LODWORD(v53);
              for ( ; v66 < LODWORD(v52); v66 *= 2 )
                ;
              if ( v66 - LODWORD(v52) > 0x10000 )
                v66 = LODWORD(v52) + 0x10000;
              UFG::qArray<UFG::PlayerCoverComponent::ScoredObject,0>::Reallocate(
                (UFG::qArray<UFG::PlayerCoverComponent::ScoredObject,0> *)&result,
                v66,
                "qArray.Add");
              v51 = *(float **)&result.z;
              v53 = result.y;
            }
            result.x = v52;
            v67 = 3 * v65;
            *(_QWORD *)&v51[2 * v67] = scoredObject.m_pCoverObject;
            v68 = scoredObject.m_fScore;
            v51[2 * v67 + 2] = scoredObject.m_fScore;
            v51[2 * v67 + 3] = scoredObject.m_vScorePosition.x;
            v51[2 * v67 + 4] = scoredObject.m_vScorePosition.y;
            v50 = scoredObject.m_vScorePosition.z;
            v51[2 * v67 + 5] = scoredObject.m_vScorePosition.z;
            if ( v68 > v54 )
            {
              v54 = v68;
              v55 = LODWORD(v52) - 1;
              v98 = LODWORD(v52) - 1;
            }
          }
        }
      }
      v57 = (unsigned int)(v57 + 1);
      v122 = *(float *)&v57;
      v56 = *(_QWORD *)&start.x;
    }
    while ( (unsigned int)v57 < **(_DWORD **)&start.x );
  }
  v69 = 0;
  LOBYTE(v122) = 0;
  if ( v52 != 0.0 )
  {
    while ( !v69 )
    {
      v70 = 3i64 * v55;
      v71 = *(UFG::CoverObjectBase **)&v51[6 * v55];
      v72 = (UFG::CoverObjectBase *)((__int64 (__fastcall *)(_QWORD, float *, _QWORD))v71->vfptr->GetCoverPosition)(
                                      *(_QWORD *)&v51[6 * v55],
                                      &v51[6 * v55 + 3],
                                      0i64);
      v73 = v72;
      if ( v72 )
      {
        ++v72->m_iRefCount;
        v74 = UFG::qVector3::msAxisZ.z * 0.60000002;
        v75 = UFG::qVector3::msAxisZ.y * 0.60000002;
        v76 = UFG::qVector3::msAxisZ.x * 0.60000002;
        start.x = v41 + (float)(UFG::qVector3::msAxisZ.x * 0.60000002);
        start.y = v43 + (float)(UFG::qVector3::msAxisZ.y * 0.60000002);
        start.z = v46 + (float)(UFG::qVector3::msAxisZ.z * 0.60000002);
        v77 = (float *)v72->vfptr->GetSyncPos(v72, (UFG::qVector3 *)&scoredObject);
        v78 = v74 + v77[2];
        v79 = v75 + v77[1];
        result.x = v76 + *v77;
        result.y = v79;
        result.z = v78;
        v80 = (UFG::SimObjectGame *)v5->m_pSimObject;
        if ( v80 )
        {
          v82 = v80->m_Flags;
          if ( (v82 >> 14) & 1 )
          {
            v81 = (UFG::SensorComponent *)v80->m_Components.p[26].m_pComponent;
          }
          else if ( (v82 & 0x8000u) == 0 )
          {
            if ( (v82 >> 13) & 1 )
              v83 = UFG::SimObjectGame::GetComponentOfTypeHK(v80, UFG::SensorComponent::_TypeUID);
            else
              v83 = (v82 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v80, UFG::SensorComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v80->vfptr, UFG::SensorComponent::_TypeUID);
            v81 = (UFG::SensorComponent *)v83;
          }
          else
          {
            v81 = (UFG::SensorComponent *)v80->m_Components.p[26].m_pComponent;
          }
        }
        else
        {
          v81 = 0i64;
        }
        v84 = (UFG::SimObjectGame *)v5->m_pSimObject;
        if ( v84 )
        {
          v86 = v84->m_Flags;
          if ( (v86 >> 14) & 1 )
          {
            v85 = (UFG::CharacterPhysicsComponent *)v84->m_Components.p[27].m_pComponent;
          }
          else if ( (v86 & 0x8000u) == 0 )
          {
            if ( (v86 >> 13) & 1 )
              v85 = (UFG::CharacterPhysicsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        v84,
                                                        UFG::CharacterPhysicsComponent::_TypeUID);
            else
              v85 = (UFG::CharacterPhysicsComponent *)((v86 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                           v84,
                                                                           UFG::CharacterPhysicsComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v84->vfptr, UFG::CharacterPhysicsComponent::_TypeUID));
          }
          else
          {
            v85 = (UFG::CharacterPhysicsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      v84,
                                                      UFG::CharacterPhysicsComponent::_TypeUID);
          }
        }
        else
        {
          v85 = 0i64;
        }
        v87 = UFG::CharacterPhysicsComponent::GetRadius(v85, CP_COVER);
        if ( UFG::SensorComponent::CastSphere(v81, &UFG::qMatrix44::msIdentity, v87, 0xCu, &start, &result, 0i64) )
        {
          v69 = LOBYTE(v122);
        }
        else
        {
          if ( vars0 )
          {
            v88 = v5->m_pProbeCoverObject;
            if ( v88 )
            {
              v89 = v88->m_iRefCount-- == 1;
              if ( v89 )
                v88->vfptr->__vecDelDtor(v88, 1u);
              v5->m_pProbeCoverObject = 0i64;
            }
            v5->m_pProbeCoverObject = v73;
            ++v73->m_iRefCount;
          }
          if ( v125 )
          {
            UFG::PlayerCoverComponent::SetCoverObject(v5, v71);
            v5->vfptr[15].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v5->vfptr, (unsigned int)v73);
          }
          v69 = 1;
          LOBYTE(v122) = 1;
        }
        v89 = v73->m_iRefCount-- == 1;
        if ( v89 )
          v73->vfptr->__vecDelDtor(v73, 1u);
        if ( v69 )
          break;
      }
      v90 = (unsigned int)(LODWORD(v52) - 1);
      *(_QWORD *)&v51[2 * v70] = *(_QWORD *)&v51[6 * v90];
      v51[2 * v70 + 2] = v51[6 * v90 + 2];
      v91 = v51[6 * v90 + 4];
      v92 = v51[6 * v90 + 5];
      v51[2 * v70 + 3] = v51[6 * v90 + 3];
      v51[2 * v70 + 4] = v91;
      v51[2 * v70 + 5] = v92;
      if ( LODWORD(v52) <= 1 )
      {
        result.x = 0.0;
        break;
      }
      --LODWORD(v52);
      LODWORD(result.x) = v90;
      if ( !(_DWORD)v90 )
        break;
      v93 = FLOAT_N1_0;
      v55 = 0;
      v94 = 0;
      if ( !(_DWORD)v90 )
        break;
      v95 = v51 + 2;
      do
      {
        if ( *v95 > v93 )
        {
          v93 = *v95;
          v55 = v94;
        }
        ++v94;
        v95 += 6;
      }
      while ( v94 < (unsigned int)v90 );
    }
  }
  if ( v51 )
  {
    `eh vector destructor iterator'(v51, 0x18ui64, *((_DWORD *)v51 - 2), (void (__fastcall *)(void *))_);
    operator delete[](v51 - 2);
  }
  *(_QWORD *)&result.z = 0i64;
  *(_QWORD *)&result.x = 0i64;
  return v69;
}
      v93 = FLOAT_N1_0;
      v55 = 0;
      v94 = 0;
      if ( !(_DWORD)v90 )
        break;
      v95 = v51 + 2;
      do
      {
        if ( *v95 > v93 )
        {
          v93 = *v95;
          v55 = v94;
        }
        ++v94;


// File Line: 610
// RVA: 0x35BBD0
void __usercall UFG::PlayerCoverComponent::GetCoverObjectScore(UFG::PlayerCoverComponent *this@<rcx>, UFG::PlayerCoverComponent::ScoredObject *scoredObject@<rdx>, UFG::PlayerCoverComponent::CoverObjectScoringParams *params@<r8>, float a4@<xmm0>)
{
  UFG::PlayerCoverComponent *v4; // rdi
  UFG::PlayerCoverComponent::CoverObjectScoringParams *v5; // rsi
  UFG::PlayerCoverComponent::ScoredObject *v6; // rbx
  UFG::CoverObjectBase *v7; // rbp
  __int64 v8; // rdi
  float v9; // xmm6_4
  UFG::CoverObjectBase *v10; // rcx
  float v11; // xmm2_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  UFG::PlayerCoverComponent::ScoredObject scoredObjecta; // [rsp+20h] [rbp-38h]
  UFG::PlayerCoverComponent *v16; // [rsp+60h] [rbp+8h]

  v16 = this;
  v4 = this;
  v5 = params;
  v6 = scoredObject;
  if ( (*((unsigned __int8 (**)(void))&scoredObject->m_pCoverObject->vfptr->__vecDelDtor + 3))() )
  {
    v7 = v6->m_pCoverObject;
    v8 = 0i64;
    v9 = FLOAT_N1_0;
    if ( LODWORD(v6->m_pCoverObject[1].vfptr) )
    {
      do
      {
        v10 = *(UFG::CoverObjectBase **)(*(_QWORD *)&v7[1].m_iRefCount + 8 * v8);
        scoredObjecta.m_fScore = -1.0;
        scoredObjecta.m_pCoverObject = v10;
        UFG::PlayerCoverComponent::GetCoverObjectScore(v16, &scoredObjecta, v5);
        v11 = scoredObjecta.m_fScore;
        if ( scoredObjecta.m_fScore > v9 )
        {
          v12 = scoredObjecta.m_vScorePosition.x;
          v13 = scoredObjecta.m_vScorePosition.y;
          v6->m_fScore = scoredObjecta.m_fScore;
          v9 = v11;
          v6->m_vScorePosition.x = v12;
          v14 = scoredObjecta.m_vScorePosition.z;
          v6->m_vScorePosition.y = v13;
          v6->m_vScorePosition.z = v14;
        }
        v8 = (unsigned int)(v8 + 1);
      }
      while ( (unsigned int)v8 < LODWORD(v7[1].vfptr) );
    }
  }
  else if ( v5->m_bHigh || !UFG::CoverObjectBase::IsHighCover(v6->m_pCoverObject, a4) )
  {
    if ( v5->m_bLow || (((void (*)(void))v6->m_pCoverObject->vfptr->GetHeight)(), a4 <= 0.5) || a4 >= 1.6 )
    {
      if ( ((unsigned __int8 (*)(void))v6->m_pCoverObject->vfptr->IsCorner)() )
      {
        if ( *(_BYTE *)(UFG::CoverCornerHandle::Get((UFG::CoverCornerHandle *)&v6->m_pCoverObject[1]) + 36) )
        {
          if ( !v5->m_bRightCorner )
            return;
        }
        else if ( !v5->m_bLeftCorner )
        {
          return;
        }
        UFG::PlayerCoverComponent::GetCoverObjectScoreCorner(v4, v6, v5);
        return;
      }
      if ( v5->m_bLine )
        UFG::PlayerCoverComponent::GetCoverObjectScoreParkourHandle(v4, v6, v5);
    }
  }
}

// File Line: 682
// RVA: 0x35B750
float __fastcall UFG::PlayerCoverComponent::GetCoverObjectPositionScore(UFG::PlayerCoverComponent *this, UFG::PlayerCoverComponent::ScoredObject *scoredObject, UFG::PlayerCoverComponent::CoverObjectScoringParams *params)
{
  UFG::PlayerCoverComponent::CoverObjectScoringParams *v3; // rbx
  UFG::PlayerCoverComponent::ScoredObject *v4; // rdi
  float v5; // xmm9_4
  __m128 v6; // xmm10
  __m128 v7; // xmm1
  float v8; // xmm11_4
  float v9; // xmm6_4
  float v10; // xmm0_4
  float v11; // xmm8_4
  float v12; // xmm4_4
  __m128 v13; // xmm2
  float v14; // xmm5_4
  __m128 v15; // xmm3
  float v16; // xmm1_4
  float v17; // xmm4_4
  float v18; // xmm2_4
  float v19; // xmm5_4
  float v20; // xmm13_4
  __m128 v21; // xmm3
  float v22; // xmm14_4
  __m128 v23; // xmm12
  float v24; // xmm1_4
  float v25; // xmm3_4
  float v26; // xmm2_4
  bool v27; // cl
  char v28; // al
  float v29; // xmm1_4
  __m128 v30; // xmm2
  __m128 v31; // xmm3
  float v32; // xmm7_4
  float v33; // xmm1_4
  UFG::qVector3 v35; // [rsp+20h] [rbp-D8h]
  UFG::qVector3 dest; // [rsp+30h] [rbp-C8h]
  UFG::qVector3 v1; // [rsp+40h] [rbp-B8h]

  v3 = params;
  v4 = scoredObject;
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(scoredObject->m_vScorePosition.z - params->m_vActorPos.z) & _xmm) >= 0.30000001 )
    return FLOAT_N1_0;
  v6 = (__m128)LODWORD(scoredObject->m_vScorePosition.y);
  v5 = scoredObject->m_vScorePosition.x - params->m_vActorPos.x;
  v6.m128_f32[0] = v6.m128_f32[0] - params->m_vActorPos.y;
  v7 = v6;
  v7.m128_f32[0] = (float)(v6.m128_f32[0] * v6.m128_f32[0]) + (float)(v5 * v5);
  LODWORD(v8) = (unsigned __int128)_mm_sqrt_ps(v7);
  if ( v8 >= params->m_fMaxSearchDistance )
    return FLOAT_N1_0;
  v9 = 0.0;
  v1.z = (float)(1.0 / v8) * 0.0;
  v1.x = (float)(1.0 / v8) * v5;
  v1.y = (float)(1.0 / v8) * v6.m128_f32[0];
  v10 = UFG::qAngleBetween(&v1, &params->m_vActorMotionIntention);
  v11 = 0.0;
  if ( v3->m_fMotionIntentionMagnitude > 0.0 )
  {
    if ( v10 >= UFG::PlayerCoverComponent::ms_fCoverScoreMotionIntentionAngleRange )
    {
      if ( v8 > v3->m_fBufferZoneSize )
      {
        UFG::qRotateVectorZ(
          &dest,
          &v3->m_vActorMotionIntention,
          UFG::PlayerCoverComponent::ms_fCoverScoreMotionIntentionAngleRange);
        UFG::qRotateVectorZ(
          &v35,
          &v3->m_vActorMotionIntention,
          COERCE_FLOAT(LODWORD(UFG::PlayerCoverComponent::ms_fCoverScoreMotionIntentionAngleRange) ^ _xmm[0]));
        v13 = (__m128)LODWORD(dest.z);
        v12 = (float)(dest.y * UFG::qVector3::msDirUp.z) - (float)(dest.z * UFG::qVector3::msDirUp.y);
        v13.m128_f32[0] = (float)(dest.z * UFG::qVector3::msDirUp.x) - (float)(dest.x * UFG::qVector3::msDirUp.z);
        v15 = v13;
        v14 = (float)(dest.x * UFG::qVector3::msDirUp.y) - (float)(dest.y * UFG::qVector3::msDirUp.x);
        v15.m128_f32[0] = (float)((float)(v13.m128_f32[0] * v13.m128_f32[0]) + (float)(v12 * v12)) + (float)(v14 * v14);
        v16 = v15.m128_f32[0] == 0.0 ? 0.0 : 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v15));
        v21 = (__m128)LODWORD(v35.x);
        v17 = v12 * v16;
        v18 = v13.m128_f32[0] * v16;
        v19 = v14 * v16;
        v20 = (float)(v35.z * UFG::qVector3::msDirUp.y) - (float)(v35.y * UFG::qVector3::msDirUp.z);
        v21.m128_f32[0] = (float)(v35.x * UFG::qVector3::msDirUp.z) - (float)(v35.z * UFG::qVector3::msDirUp.x);
        v23 = v21;
        v22 = (float)(v35.y * UFG::qVector3::msDirUp.x) - (float)(v35.x * UFG::qVector3::msDirUp.y);
        v23.m128_f32[0] = (float)((float)(v21.m128_f32[0] * v21.m128_f32[0]) + (float)(v20 * v20)) + (float)(v22 * v22);
        v24 = v23.m128_f32[0] == 0.0 ? 0.0 : 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v23));
        v25 = (float)((float)((float)(v21.m128_f32[0] * v24) * v6.m128_f32[0]) + (float)((float)(v20 * v24) * v5))
            + (float)((float)(v22 * v24) * 0.0);
        v26 = (float)((float)(v18 * v6.m128_f32[0]) + (float)(v17 * v5)) + (float)(v19 * 0.0);
        v27 = (float)((float)((float)(dest.y * v6.m128_f32[0]) + (float)(dest.x * v5)) + (float)(dest.z * 0.0)) > 0.0
           && v26 > 0.0
           && v26 < v3->m_fBufferZoneSize;
        v28 = (float)((float)((float)(v35.y * v6.m128_f32[0]) + (float)(v35.x * v5)) + (float)(v35.z * 0.0)) <= 0.0
           || v25 <= 0.0
           || v25 >= v3->m_fBufferZoneSize ? 0 : 1;
        if ( !(v27 | (unsigned __int8)v28) )
          return FLOAT_N1_0;
      }
    }
    else
    {
      v11 = (float)(UFG::PlayerCoverComponent::ms_fCoverScoreMotionIntentionAngleRange - v10)
          / UFG::PlayerCoverComponent::ms_fCoverScoreMotionIntentionAngleRange;
    }
  }
  v30 = (__m128)LODWORD(v4->m_vScorePosition.y);
  v29 = v4->m_vScorePosition.x - v3->m_vCameraPosition.x;
  v30.m128_f32[0] = v30.m128_f32[0] - v3->m_vCameraPosition.y;
  v31 = v30;
  v31.m128_f32[0] = (float)(v30.m128_f32[0] * v30.m128_f32[0]) + (float)(v29 * v29);
  v32 = v31.m128_f32[0] == 0.0 ? 0.0 : 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v31));
  dest.z = v32 * 0.0;
  dest.x = v29 * v32;
  dest.y = v30.m128_f32[0] * v32;
  v33 = UFG::qAngleBetween(&dest, &v3->m_vCameraDirection);
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
float __fastcall UFG::PlayerCoverComponent::GetCoverObjectScoreCorner(UFG::PlayerCoverComponent *this, UFG::PlayerCoverComponent::ScoredObject *scoredObject, UFG::PlayerCoverComponent::CoverObjectScoringParams *params)
{
  UFG::PlayerCoverComponent *v3; // rbx
  UFG::PlayerCoverComponent::ScoredObject *v4; // rdi
  UFG::PlayerCoverComponent::CoverObjectScoringParams *v5; // rsi
  int v6; // xmm1_4
  int v7; // xmm0_4
  float v8; // xmm6_4
  float result; // xmm0_4
  float v10; // [rsp+20h] [rbp-38h]
  int v11; // [rsp+24h] [rbp-34h]
  int v12; // [rsp+28h] [rbp-30h]
  float v13; // [rsp+30h] [rbp-28h]
  float v14; // [rsp+34h] [rbp-24h]
  float v15; // [rsp+38h] [rbp-20h]

  v3 = this;
  v4 = scoredObject;
  v5 = params;
  scoredObject->m_pCoverObject->vfptr->GetSyncPos(scoredObject->m_pCoverObject, (UFG::qVector3 *)&v10);
  v6 = v11;
  v4->m_vScorePosition.x = v10;
  v7 = v12;
  LODWORD(v4->m_vScorePosition.y) = v6;
  LODWORD(v4->m_vScorePosition.z) = v7;
  v8 = UFG::PlayerCoverComponent::GetCoverObjectPositionScore(v3, v4, v5);
  if ( v8 < 0.0 )
    return FLOAT_N1_0;
  v4->m_pCoverObject->vfptr->GetSweetSpotDir(v4->m_pCoverObject, (UFG::qVector3 *)&v13);
  result = (float)((float)((float)((float)(v14 * v5->m_vCameraDirection.y) + (float)(v13 * v5->m_vCameraDirection.x))
                         + (float)(v15 * v5->m_vCameraDirection.z))
                 * UFG::PlayerCoverComponent::ms_fCoverScoreCameraDirectionMultiplier)
         + v8;
  if ( result <= UFG::PlayerCoverComponent::ms_fCoverScoreMinimum )
    return FLOAT_N1_0;
  v4->m_fScore = result;
  return result;
}

// File Line: 814
// RVA: 0x35BE50
float __fastcall UFG::PlayerCoverComponent::GetCoverObjectScoreParkourHandle(UFG::PlayerCoverComponent *this, UFG::PlayerCoverComponent::ScoredObject *scoredObject, UFG::PlayerCoverComponent::CoverObjectScoringParams *params)
{
  UFG::CoverObjectParkour *v3; // rbp
  UFG::PlayerCoverComponent::ScoredObject *v4; // rdi
  UFG::PlayerCoverComponent *v5; // rbx
  UFG::PlayerCoverComponent::CoverObjectScoringParams *v6; // rsi
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm0_4
  float fDirectionLength; // ST20_4
  float v11; // xmm6_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  UFG::qVector3 result; // [rsp+30h] [rbp-48h]
  UFG::PlayerCoverComponent::ScoredObject scoredObjecta; // [rsp+40h] [rbp-38h]

  v3 = (UFG::CoverObjectParkour *)scoredObject->m_pCoverObject;
  v4 = scoredObject;
  v5 = this;
  v6 = params;
  UFG::CoverObjectParkour::GetClosestParkourSync(
    (UFG::CoverObjectParkour *)scoredObject->m_pCoverObject,
    &result,
    &params->m_vActorPos);
  v7 = result.y;
  v4->m_vScorePosition.x = result.x;
  v8 = result.z;
  v4->m_vScorePosition.y = v7;
  v4->m_vScorePosition.z = v8;
  v9 = UFG::PlayerCoverComponent::GetCoverObjectPositionScore(v5, v4, v6);
  fDirectionLength = v6->m_fMaxSearchDistance;
  v11 = v9;
  scoredObjecta.m_pCoverObject = 0i64;
  scoredObjecta.m_fScore = -1.0;
  UFG::CoverObjectParkour::GetClosestParkourSyncInDirection(
    v3,
    &result,
    &v6->m_vActorPos,
    &v6->m_vActorMotionIntention,
    fDirectionLength);
  scoredObjecta.m_vScorePosition = result;
  v12 = UFG::PlayerCoverComponent::GetCoverObjectPositionScore(v5, &scoredObjecta, v6);
  if ( v12 > v11 )
  {
    v13 = scoredObjecta.m_vScorePosition.x;
    v11 = v12;
    v4->m_fScore = scoredObjecta.m_fScore;
    v14 = scoredObjecta.m_vScorePosition.y;
    v4->m_vScorePosition.x = v13;
    v15 = scoredObjecta.m_vScorePosition.z;
    v4->m_vScorePosition.y = v14;
    v4->m_vScorePosition.z = v15;
    v4->m_pCoverObject = (UFG::CoverObjectBase *)&v3->vfptr;
  }
  if ( v11 < 0.0 )
    return FLOAT_N1_0;
  v4->m_pCoverObject->vfptr->GetSweetSpotDir(v4->m_pCoverObject, &result);
  v16 = (float)((float)((float)((float)(result.y * v6->m_vCameraDirection.y)
                              + (float)(result.x * v6->m_vCameraDirection.x))
                      + (float)(result.z * v6->m_vCameraDirection.z))
              * UFG::PlayerCoverComponent::ms_fCoverScoreCameraDirectionMultiplier)
      + v11;
  if ( v16 <= UFG::PlayerCoverComponent::ms_fCoverScoreMinimum )
    return FLOAT_N1_0;
  v4->m_fScore = v16;
  return v16;
}

// File Line: 864
// RVA: 0x37CC40
char __fastcall UFG::PlayerCoverComponent::ProbeForCover(UFG::PlayerCoverComponent *this, UFG::qVector3 *vProbePos, bool bLatch, bool bStoreProbeCoverObject)
{
  bool v4; // di
  UFG::qVector3 *v5; // rsi
  UFG::PlayerCoverComponent::CoverObjectPosition *v6; // rbp
  unsigned int v7; // ebx
  unsigned int v8; // er15
  UFG::PlayerCoverQuery *v9; // r13
  unsigned int v10; // er12
  UFG::CoverObjectBase *v11; // r14
  __int64 v12; // rax
  __int64 v13; // rsi
  __int64 v14; // rdi
  unsigned int v15; // edx
  UFG::PlayerCoverComponent::CoverObjectPosition *v16; // rdi
  UFG::CoverObjectBase *v17; // rcx
  bool v18; // zf
  UFG::CoverPosition *v19; // rcx
  int v20; // eax
  char result; // al
  UFG::qArray<UFG::PlayerCoverComponent::CoverObjectPosition,0> aCoverObjectPositions; // [rsp+28h] [rbp-70h]
  UFG::PlayerCoverComponent *v23; // [rsp+A0h] [rbp+8h]
  UFG::qVector3 *v24; // [rsp+A8h] [rbp+10h]
  bool v25; // [rsp+B0h] [rbp+18h]
  bool v26; // [rsp+B8h] [rbp+20h]

  v26 = bStoreProbeCoverObject;
  v25 = bLatch;
  v24 = vProbePos;
  v23 = this;
  v4 = bStoreProbeCoverObject;
  v5 = vProbePos;
  if ( !this->m_pCurrentPlayerCoverQuery )
    return 0;
  v6 = 0i64;
  aCoverObjectPositions.p = 0i64;
  v7 = 0;
  aCoverObjectPositions.size = 0;
  v8 = 0;
  aCoverObjectPositions.capacity = 0;
  v9 = this->m_pCurrentPlayerCoverQuery;
  v10 = 0;
  if ( v9->m_aCoverObjects.size <= 0 )
  {
LABEL_37:
    if ( v6 )
    {
      `eh vector destructor iterator'(
        v6,
        0x10ui64,
        (int)v6[-1].m_pCoverPosition,
        (void (__fastcall *)(void *))UFG::PlayerCoverComponent::CoverObjectPosition::~CoverObjectPosition);
      operator delete[](&v6[-1].m_pCoverPosition);
    }
    aCoverObjectPositions.p = 0i64;
    *(_QWORD *)&aCoverObjectPositions.size = 0i64;
    return 0;
  }
  do
  {
    v11 = v9->m_aCoverObjects.p[v10];
    if ( !(__int64)v11->vfptr->GetCoverObjectGroup(v9->m_aCoverObjects.p[v10])
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
        if ( !v25 && !v4 )
        {
          v18 = (*(_DWORD *)(v12 + 8))-- == 1;
          if ( v18 )
            (**(void (__fastcall ***)(__int64, signed __int64))v12)(v12, 1i64);
          goto LABEL_34;
        }
        v14 = v7++;
        if ( v7 > v8 )
        {
          v15 = 1;
          if ( v8 )
            v15 = 2 * v8;
          for ( ; v15 < v7; v15 *= 2 )
            ;
          if ( v15 - v7 > 0x10000 )
            v15 = v7 + 0x10000;
          UFG::qArray<UFG::PlayerCoverComponent::CoverObjectPosition,0>::Reallocate(
            &aCoverObjectPositions,
            v15,
            "qArray.Add");
          v6 = aCoverObjectPositions.p;
          v8 = aCoverObjectPositions.capacity;
        }
        aCoverObjectPositions.size = v7;
        v16 = &v6[v14];
        v17 = v16->m_pCoverObject;
        if ( v16->m_pCoverObject )
        {
          v18 = v17->m_iRefCount-- == 1;
          if ( v18 )
            v17->vfptr->__vecDelDtor(v17, 1u);
          v16->m_pCoverObject = 0i64;
        }
        v16->m_pCoverObject = v11;
        ++v11->m_iRefCount;
        v19 = v16->m_pCoverPosition;
        if ( v19 )
        {
          v18 = v19->m_iRefCount-- == 1;
          if ( v18 )
            v19->vfptr->__vecDelDtor((UFG::CoverObjectBase *)&v19->vfptr, 1u);
          v16->m_pCoverPosition = 0i64;
        }
        v16->m_pCoverPosition = (UFG::CoverPosition *)v13;
        v20 = *(_DWORD *)(v13 + 8);
        *(_DWORD *)(v13 + 8) = v20;
        if ( !v20 )
          (**(void (__fastcall ***)(__int64, signed __int64))v13)(v13, 1i64);
        v4 = v26;
      }
      v5 = v24;
    }
    ++v10;
  }
  while ( v10 < v9->m_aCoverObjects.size );
  if ( !v7 )
    goto LABEL_37;
  UFG::PlayerCoverComponent::SelectBestCoverPosition(v23, &aCoverObjectPositions, v25, v4);
LABEL_34:
  if ( v6 )
  {
    `eh vector destructor iterator'(
      v6,
      0x10ui64,
      (int)v6[-1].m_pCoverPosition,
      (void (__fastcall *)(void *))UFG::PlayerCoverComponent::CoverObjectPosition::~CoverObjectPosition);
    operator delete[](&v6[-1].m_pCoverPosition);
  }
  result = 1;
  aCoverObjectPositions.p = 0i64;
  *(_QWORD *)&aCoverObjectPositions.size = 0i64;
  return result;
}

// File Line: 916
// RVA: 0x3840B0
void __fastcall UFG::PlayerCoverComponent::SelectBestCoverPosition(UFG::PlayerCoverComponent *this, UFG::qArray<UFG::PlayerCoverComponent::CoverObjectPosition,0> *aCoverObjectPositions, bool bLatch, bool bStoreProbeCoverObject)
{
  bool v4; // r12
  bool v5; // r13
  UFG::qArray<UFG::PlayerCoverComponent::CoverObjectPosition,0> *v6; // rbp
  UFG::PlayerCoverComponent *v7; // rsi
  UFG::CoverObjectBase *v8; // rcx
  UFG::CoverPosition *v9; // rbx
  bool v10; // zf
  UFG::CoverPosition *v11; // rdx
  UFG::SimObjectGame *v12; // rcx
  float *v13; // r14
  unsigned __int16 v14; // dx
  UFG::SimComponent *v15; // rax
  float v16; // xmm6_4
  int v17; // ebx
  int v18; // er15
  UFG::CoverObjectBase *v19; // rcx
  signed __int64 v20; // rdi
  float *v21; // rax
  signed __int64 v22; // rbx
  UFG::CoverObjectBase *v23; // rcx
  UFG::CoverObjectBase *v24; // rdi
  char v25; // [rsp+20h] [rbp-48h]

  v4 = bStoreProbeCoverObject;
  v5 = bLatch;
  v6 = aCoverObjectPositions;
  v7 = this;
  if ( aCoverObjectPositions->size == 1 )
  {
    if ( bStoreProbeCoverObject )
    {
      v8 = this->m_pProbeCoverObject;
      v9 = aCoverObjectPositions->p->m_pCoverPosition;
      if ( v8 )
      {
        v10 = v8->m_iRefCount-- == 1;
        if ( v10 )
          v8->vfptr->__vecDelDtor(v8, 1u);
        v7->m_pProbeCoverObject = 0i64;
      }
      if ( v9 )
      {
        v7->m_pProbeCoverObject = (UFG::CoverObjectBase *)&v9->vfptr;
        ++v9->m_iRefCount;
      }
    }
    if ( v5 )
    {
      UFG::PlayerCoverComponent::SetCoverObject(v7, v6->p->m_pCoverObject);
      v11 = v6->p->m_pCoverPosition;
LABEL_40:
      v7->vfptr[15].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v7->vfptr, (unsigned int)v11);
      return;
    }
  }
  else
  {
    v12 = (UFG::SimObjectGame *)this->m_pSimObject;
    if ( v12 )
    {
      v14 = v12->m_Flags;
      if ( (v14 >> 14) & 1 )
      {
        v13 = (float *)v12->m_Components.p[7].m_pComponent;
      }
      else if ( (v14 & 0x8000u) == 0 )
      {
        if ( (v14 >> 13) & 1 )
        {
          v13 = (float *)v12->m_Components.p[6].m_pComponent;
        }
        else
        {
          if ( (v14 >> 12) & 1 )
            v15 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::ActionTreeComponent::_TypeUID);
          else
            v15 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v12->vfptr, UFG::ActionTreeComponent::_TypeUID);
          v13 = (float *)v15;
        }
      }
      else
      {
        v13 = (float *)v12->m_Components.p[7].m_pComponent;
      }
    }
    else
    {
      v13 = 0i64;
    }
    v16 = FLOAT_3_4028235e38;
    v17 = 0;
    v18 = 0;
    if ( v6->size )
    {
      while ( 1 )
      {
        v19 = v7->m_pCoverObject;
        v20 = (signed __int64)&v6->p[v17];
        if ( v19 )
        {
          if ( UFG::CoverObjectBase::IsAnyLineOrCornerShared(v19, *(UFG::CoverObjectBase **)(v20 + 8)) )
            break;
        }
        v21 = (float *)(*(__int64 (__fastcall **)(_QWORD, char *))(**(_QWORD **)(v20 + 8) + 160i64))(
                         *(_QWORD *)(v20 + 8),
                         &v25);
        if ( (float)((float)((float)(v21[1] * v13[140]) + (float)(v13[139] * *v21)) + (float)(v21[2] * v13[141])) < v16 )
        {
          v18 = v17;
          v16 = (float)((float)(v21[1] * v13[140]) + (float)(v13[139] * *v21)) + (float)(v21[2] * v13[141]);
        }
        if ( ++v17 >= v6->size )
          goto LABEL_31;
      }
      v18 = v17;
    }
LABEL_31:
    v22 = (signed __int64)&v6->p[v18];
    if ( v4 )
    {
      v23 = v7->m_pProbeCoverObject;
      v24 = *(UFG::CoverObjectBase **)(v22 + 8);
      if ( v23 )
      {
        v10 = v23->m_iRefCount-- == 1;
        if ( v10 )
          v23->vfptr->__vecDelDtor(v23, 1u);
        v7->m_pProbeCoverObject = 0i64;
      }
      if ( v24 )
      {
        v7->m_pProbeCoverObject = v24;
        ++v24->m_iRefCount;
      }
    }
    if ( v5 )
    {
      UFG::PlayerCoverComponent::SetCoverObject(v7, *(UFG::CoverObjectBase **)v22);
      v11 = *(UFG::CoverPosition **)(v22 + 8);
      goto LABEL_40;
    }
  }
}

// File Line: 981
// RVA: 0x34A030
void __fastcall UFG::PlayerCoverComponent::BootAIOffCoverPosition(UFG::PlayerCoverComponent *this, UFG::CoverPosition *pCoverPosition)
{
  UFG::CoverPosition *v2; // rsi
  UFG::qNode<UFG::AICoverComponent,UFG::AICoverComponent> *v3; // rcx
  UFG::qList<UFG::AICoverComponent,UFG::AICoverComponent,1,0> *v4; // rbx

  v2 = pCoverPosition;
  v3 = UFG::AICoverComponent::s_AICoverComponentList.mNode.mNext - 4;
  if ( (UFG::qList<UFG::AICoverComponent,UFG::AICoverComponent,1,0> *)&UFG::AICoverComponent::s_AICoverComponentList.mNode.mNext[-4] != &UFG::AICoverComponent::s_AICoverComponentList - 4 )
  {
    do
    {
      v4 = (UFG::qList<UFG::AICoverComponent,UFG::AICoverComponent,1,0> *)&v3[4].mNext[-4];
      ((void (__fastcall *)(UFG::qNode<UFG::AICoverComponent,UFG::AICoverComponent> *, UFG::CoverPosition *))v3->mPrev[8].mPrev)(
        v3,
        v2);
      v3 = &v4->mNode;
    }
    while ( v4 != &UFG::AICoverComponent::s_AICoverComponentList - 4 );
  }
}

