// File Line: 54
// RVA: 0x339080
void __fastcall UFG::IncomingAttackInfo::~IncomingAttackInfo(UFG::IncomingAttackInfo *this)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v1; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v2; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v3; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v4; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rax

  v1 = &this->mAttacker;
  if ( this->mAttacker.m_pPointer )
  {
    v2 = v1->mPrev;
    v3 = v1->mNext;
    v2->mNext = v3;
    v3->mPrev = v2;
    v1->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mPrev;
    v1->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mPrev;
  }
  v1->m_pPointer = 0i64;
  v4 = v1->mPrev;
  v5 = v1->mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  v1->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mPrev;
  v1->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mPrev;
}

// File Line: 67
// RVA: 0x382C80
void __fastcall UFG::InterestPointLink::Reset(UFG::InterestPointLink *this)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v1; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v3; // rax

  v1 = &this->mLinkObject;
  if ( this->mLinkObject.m_pPointer )
  {
    v2 = v1->mPrev;
    v3 = this->mLinkObject.mNext;
    v2->mNext = v3;
    v3->mPrev = v2;
    v1->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mPrev;
    this->mLinkObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->mLinkObject.mPrev;
  }
  this->mLinkObject.m_pPointer = 0i64;
  this->mPOIUseType = 2;
  this->mIsExclusive = 0;
}

// File Line: 86
// RVA: 0x338A10
void __fastcall UFG::InterestPointUseDetails::~InterestPointUseDetails(ActionContext *this)
{
  ActionContext *v1; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v2; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v3; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v4; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rax

  v1 = this;
  if ( this->mSimObject.m_pPointer )
  {
    v2 = this->mSimObject.mPrev;
    v3 = v1->mSimObject.mNext;
    v2->mNext = v3;
    v3->mPrev = v2;
    v1->mSimObject.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mSimObject.mPrev;
    v1->mSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mSimObject.mPrev;
  }
  v1->mSimObject.m_pPointer = 0i64;
  v4 = v1->mSimObject.mPrev;
  v5 = v1->mSimObject.mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  v1->mSimObject.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mSimObject.mPrev;
  v1->mSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mSimObject.mPrev;
}

// File Line: 91
// RVA: 0x384C10
void __fastcall UFG::InterestPointUseDetails::Set(UFG::InterestPointUseDetails *this, UFG::InterestPoint *pInterestPoint, UFG::ePOIUseType poiUseType, UFG::qSymbol *skipIntoLabel)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v4; // r10
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v5; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v6; // rax

  if ( this->mInterestPoint.m_pPointer )
  {
    v4 = this->mInterestPoint.mPrev;
    v5 = this->mInterestPoint.mNext;
    v4->mNext = v5;
    v5->mPrev = v4;
    this->mInterestPoint.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&this->mInterestPoint.mPrev;
    this->mInterestPoint.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&this->mInterestPoint.mPrev;
  }
  this->mInterestPoint.m_pPointer = pInterestPoint;
  if ( pInterestPoint )
  {
    v6 = pInterestPoint->m_SafePointerList.mNode.mPrev;
    v6->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&this->mInterestPoint.mPrev;
    this->mInterestPoint.mPrev = v6;
    this->mInterestPoint.mNext = &pInterestPoint->m_SafePointerList.mNode;
    pInterestPoint->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&this->mInterestPoint.mPrev;
  }
  this->mPOIUseType = poiUseType;
  this->mSkipIntoLabel = (UFG::qSymbol)skipIntoLabel->mUID;
}

// File Line: 99
// RVA: 0x36C1A0
bool __fastcall UFG::InterestPointUseDetails::IsValid(UFG::InterestPointUseDetails *this)
{
  return this->mInterestPoint.m_pPointer && this->mPOIUseType;
}

// File Line: 106
// RVA: 0x33C1F0
bool __fastcall UFG::InterestPointUseDetails::operator==(UFG::InterestPointUseDetails *this, UFG::InterestPointUseDetails *rhs)
{
  return *(_OWORD *)&this->mInterestPoint.m_pPointer == *(_OWORD *)&rhs->mInterestPoint.m_pPointer;
}

// File Line: 114
// RVA: 0x33C210
bool __fastcall UFG::InterestPointUseDetails::operator!=(UFG::InterestPointUseDetails *this, UFG::InterestPointUseDetails *rhs)
{
  char v2; // al

  if ( rhs->mInterestPoint.m_pPointer != this->mInterestPoint.m_pPointer
    || this->mPOIUseType != rhs->mPOIUseType
    || (v2 = 1, this->mSkipIntoLabel.mUID != rhs->mSkipIntoLabel.mUID) )
  {
    v2 = 0;
  }
  return v2 == 0;
}

// File Line: 120
// RVA: 0x382CC0
void __fastcall UFG::InterestPointUseDetails::Reset(UFG::InterestPointUseDetails *this)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v1; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v2; // rax
  UFG::qSymbol *v3; // rcx

  if ( this->mInterestPoint.m_pPointer )
  {
    v1 = this->mInterestPoint.mPrev;
    v2 = this->mInterestPoint.mNext;
    v1->mNext = v2;
    v2->mPrev = v1;
    this->mInterestPoint.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&this->mInterestPoint.mPrev;
    this->mInterestPoint.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&this->mInterestPoint.mPrev;
  }
  v3 = &this->mSkipIntoLabel;
  *(_QWORD *)&v3[-3].mUID = 0i64;
  v3[-1].mUID = 0;
  UFG::qSymbol::set_null(v3);
}

// File Line: 136
// RVA: 0x335290
void __fastcall UFG::ActiveInterestPoint::~ActiveInterestPoint(UFG::ActiveInterestPoint *this)
{
  UFG::ActiveInterestPoint *v1; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v2; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v3; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v4; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v5; // rax

  v1 = this;
  if ( this->mInterestPoint.m_pPointer )
  {
    v2 = this->mInterestPoint.mPrev;
    v3 = v1->mInterestPoint.mNext;
    v2->mNext = v3;
    v3->mPrev = v2;
    v1->mInterestPoint.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&v1->mInterestPoint.mPrev;
    v1->mInterestPoint.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&v1->mInterestPoint.mPrev;
  }
  v1->mInterestPoint.m_pPointer = 0i64;
  v4 = v1->mInterestPoint.mPrev;
  v5 = v1->mInterestPoint.mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  v1->mInterestPoint.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&v1->mInterestPoint.mPrev;
  v1->mInterestPoint.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&v1->mInterestPoint.mPrev;
}

// File Line: 140
// RVA: 0x382930
void __fastcall UFG::ActiveInterestPoint::Reset(UFG::ActiveInterestPoint *this)
{
  UFG::ActiveInterestPoint *v1; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v3; // rax
  UFG::qSymbol *v4; // rcx

  v1 = this;
  if ( this->mInterestPoint.m_pPointer )
  {
    v2 = this->mInterestPoint.mPrev;
    v3 = this->mInterestPoint.mNext;
    v2->mNext = v3;
    v3->mPrev = v2;
    this->mInterestPoint.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&this->mInterestPoint.mPrev;
    this->mInterestPoint.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&this->mInterestPoint.mPrev;
  }
  v4 = &this->mSkipIntoLabel;
  *(_QWORD *)&v4[-3].mUID = 0i64;
  v4[-1].mUID = 0;
  UFG::qSymbol::set_null(v4);
  v1->mIsFirstUse = 1;
}

// File Line: 149
// RVA: 0x14AD410
__int64 dynamic_initializer_for__UFG::InterestPointUserComponent::msaPlayersLastNearest__()
{
  `eh vector constructor iterator'(
    UFG::InterestPointUserComponent::msaPlayersLastNearest.p,
    0x18ui64,
    4,
    (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>);
  UFG::InterestPointUserComponent::msaPlayersLastNearest.size = 0;
  return atexit(dynamic_atexit_destructor_for__UFG::InterestPointUserComponent::msaPlayersLastNearest__);
}

// File Line: 159
// RVA: 0x14AEB80
__int64 dynamic_initializer_for__UFG::InterestPointUserComponent::s_InterestPointUserComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::InterestPointUserComponent::s_InterestPointUserComponentList__);
}

// File Line: 160
// RVA: 0x14ACFF0
__int64 dynamic_initializer_for__UFG::InterestPointUserComponent::_TypeIDesc__()
{
  UFG::ComponentIDDesc *v0; // rax
  __int64 result; // rax

  v0 = UFG::InterestPointUserComponent::AccessComponentDesc();
  *(_DWORD *)&UFG::InterestPointUserComponent::_TypeIDesc.mBaseTypeIndex = *(_DWORD *)&v0->mBaseTypeIndex;
  UFG::InterestPointUserComponent::_TypeIDesc.mChildBitMask = v0->mChildBitMask;
  result = v0->mChildren;
  UFG::InterestPointUserComponent::_TypeIDesc.mChildren = result;
  return result;
}

// File Line: 185
// RVA: 0x32FD80
void __fastcall UFG::InterestPointUserComponent::InterestPointUserComponent(UFG::InterestPointUserComponent *this, unsigned int name_uid)
{
  UFG::InterestPointUserComponent *v2; // rsi
  UFG::qNode<UFG::InterestPointUserComponent,UFG::InterestPointUserComponent> *v3; // rdi
  UFG::InterestPointQuery *v4; // rbx
  UFG::qNode<UFG::InterestPointQuery,UFG::InterestPointQuery> *v5; // rax
  UFG::qNode<UFG::InterestPointUserComponent,UFG::InterestPointUserComponent> *v6; // rax
  UFG::qSafePointer<UFG::InterestPoint,UFG::InterestPoint> *v7; // [rsp+60h] [rbp+18h]
  signed __int64 v8; // [rsp+60h] [rbp+18h]
  UFG::InterestPointUseDetails *v9; // [rsp+60h] [rbp+18h]
  UFG::ActiveInterestPoint *v10; // [rsp+60h] [rbp+18h]
  UFG::qSafePointer<UFG::InterestPoint,UFG::InterestPoint> *v11; // [rsp+68h] [rbp+20h]
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v12; // [rsp+68h] [rbp+20h]

  v2 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name_uid);
  v3 = (UFG::qNode<UFG::InterestPointUserComponent,UFG::InterestPointUserComponent> *)&v2->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  v2->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::InterestPointUserComponent::`vftable';
  *((_BYTE *)v2 + 80) = *((_BYTE *)v2 + 80) & 0xFD | 1;
  v7 = &v2->mLastInterestPoint;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v7->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v2->mLastInterestPoint.m_pPointer = 0i64;
  UFG::RebindingComponentHandle<UFG::TargetingSystemPedBaseComponent,0>::RebindingComponentHandle<UFG::TargetingSystemPedBaseComponent,0>(&v2->mTargetingSystemPedBaseComponent);
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::RebindingComponentHandle<UFG::TransformNodeComponent,0>(&v2->mTransformNodeComponent);
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0>::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0>(&v2->mActiveAIEntityComponent);
  UFG::RebindingComponentHandle<UFG::AIScriptInterfaceComponent,0>::RebindingComponentHandle<UFG::AIScriptInterfaceComponent,0>(&v2->mAIScriptInterfaceComponent);
  UFG::RebindingComponentHandle<UFG::NavComponent,0>::RebindingComponentHandle<UFG::NavComponent,0>(&v2->mNavComponent);
  v4 = &v2->mInterestPointQuery;
  v5 = (UFG::qNode<UFG::InterestPointQuery,UFG::InterestPointQuery> *)&v2->mInterestPointQuery.mPrev;
  v5->mPrev = v5;
  v5->mNext = v5;
  UFG::qSafePointerNode<UFG::InterestPointQuery>::qSafePointerNode<UFG::InterestPointQuery>((UFG::qSafePointerNode<UFG::InterestPointQuery> *)&v2->mInterestPointQuery.vfptr);
  v4->vfptr = (UFG::qSafePointerNode<UFG::InterestPointQuery>Vtbl *)&UFG::InterestPointQuery::`vftable';
  v2->mInterestPointQuery.mNavComponent = 0i64;
  v2->mInterestPointQuery.mCandidates.p = 0i64;
  *(_QWORD *)&v2->mInterestPointQuery.mCandidates.size = 0i64;
  v2->mInterestPointQuery.mQueryState = 0;
  v11 = &v2->mInterestPointQuery.mBestInterestPoint;
  v11->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&v11->mPrev;
  v11->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&v11->mPrev;
  v4->mBestInterestPoint.m_pPointer = 0i64;
  v8 = (signed __int64)&v2->mInterestPointLink;
  *(_DWORD *)v8 = 2;
  *(_BYTE *)(v8 + 4) = 0;
  v12 = &v2->mInterestPointLink.mLinkObject;
  v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v12->mPrev;
  v12->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v12->mPrev;
  v2->mInterestPointLink.mLinkObject.m_pPointer = 0i64;
  v9 = &v2->mRequestedInterestPoint;
  v9->mInterestPoint.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&v9->mInterestPoint.mPrev;
  v9->mInterestPoint.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&v9->mInterestPoint.mPrev;
  v2->mRequestedInterestPoint.mInterestPoint.m_pPointer = 0i64;
  v2->mRequestedInterestPoint.mPOIUseType = 0;
  v2->mRequestedInterestPoint.mSkipIntoLabel.mUID = -1;
  v10 = &v2->mActiveInterestPoint;
  v10->mInterestPoint.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&v10->mInterestPoint.mPrev;
  v10->mInterestPoint.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&v10->mInterestPoint.mPrev;
  v2->mActiveInterestPoint.mInterestPoint.m_pPointer = 0i64;
  v2->mActiveInterestPoint.mPOIUseType = 0;
  v2->mActiveInterestPoint.mSkipIntoLabel.mUID = -1;
  v2->mActiveInterestPoint.mIsFirstUse = 1;
  *(_QWORD *)&v2->mLastUsedPOIType.mUID = -1i64;
  v2->mFrameCountOfLastPOIUse = 0;
  v6 = UFG::InterestPointUserComponent::s_InterestPointUserComponentList.mNode.mPrev;
  UFG::InterestPointUserComponent::s_InterestPointUserComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::InterestPointUserComponent,UFG::InterestPointUserComponent> *)&v2->mPrev;
  v3->mPrev = v6;
  v2->mNext = (UFG::qNode<UFG::InterestPointUserComponent,UFG::InterestPointUserComponent> *)&UFG::InterestPointUserComponent::s_InterestPointUserComponentList;
  UFG::InterestPointUserComponent::s_InterestPointUserComponentList.mNode.mPrev = (UFG::qNode<UFG::InterestPointUserComponent,UFG::InterestPointUserComponent> *)&v2->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v2->vfptr,
    UFG::InterestPointUserComponent::_InterestPointUserComponentTypeUID,
    "InterestPointUserComponent");
}

// File Line: 205
// RVA: 0x338A70
void __fastcall UFG::InterestPointUserComponent::~InterestPointUserComponent(UFG::InterestPointUserComponent *this)
{
  UFG::InterestPointUserComponent *v1; // rbx
  UFG::qNode<UFG::InterestPointUserComponent,UFG::InterestPointUserComponent> *v2; // rdi
  UFG::qNode<UFG::InterestPointUserComponent,UFG::InterestPointUserComponent> *v3; // rcx
  UFG::qNode<UFG::InterestPointUserComponent,UFG::InterestPointUserComponent> *v4; // rax
  UFG::ActiveInterestPoint *v5; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::InterestPointUseDetails *v10; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v15; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qSafePointer<UFG::InterestPoint,UFG::InterestPoint> *v20; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v21; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v22; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v23; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v24; // rax
  UFG::qNode<UFG::InterestPointUserComponent,UFG::InterestPointUserComponent> *v25; // rcx
  UFG::qNode<UFG::InterestPointUserComponent,UFG::InterestPointUserComponent> *v26; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::InterestPointUserComponent::`vftable';
  if ( this == UFG::InterestPointUserComponent::s_InterestPointUserComponentpCurrentIterator )
    UFG::InterestPointUserComponent::s_InterestPointUserComponentpCurrentIterator = (UFG::InterestPointUserComponent *)&this->mPrev[-4];
  v2 = (UFG::qNode<UFG::InterestPointUserComponent,UFG::InterestPointUserComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = &v1->mActiveInterestPoint;
  if ( v1->mActiveInterestPoint.mInterestPoint.m_pPointer )
  {
    v6 = v5->mInterestPoint.mPrev;
    v7 = v1->mActiveInterestPoint.mInterestPoint.mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    v5->mInterestPoint.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&v5->mInterestPoint.mPrev;
    v1->mActiveInterestPoint.mInterestPoint.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&v1->mActiveInterestPoint.mInterestPoint.mPrev;
  }
  v1->mActiveInterestPoint.mInterestPoint.m_pPointer = 0i64;
  v8 = v5->mInterestPoint.mPrev;
  v9 = v1->mActiveInterestPoint.mInterestPoint.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v5->mInterestPoint.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&v5->mInterestPoint.mPrev;
  v1->mActiveInterestPoint.mInterestPoint.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&v1->mActiveInterestPoint.mInterestPoint.mPrev;
  v10 = &v1->mRequestedInterestPoint;
  if ( v1->mRequestedInterestPoint.mInterestPoint.m_pPointer )
  {
    v11 = v10->mInterestPoint.mPrev;
    v12 = v1->mRequestedInterestPoint.mInterestPoint.mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    v10->mInterestPoint.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&v10->mInterestPoint.mPrev;
    v1->mRequestedInterestPoint.mInterestPoint.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&v1->mRequestedInterestPoint.mInterestPoint.mPrev;
  }
  v1->mRequestedInterestPoint.mInterestPoint.m_pPointer = 0i64;
  v13 = v10->mInterestPoint.mPrev;
  v14 = v1->mRequestedInterestPoint.mInterestPoint.mNext;
  v13->mNext = v14;
  v14->mPrev = v13;
  v10->mInterestPoint.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&v10->mInterestPoint.mPrev;
  v1->mRequestedInterestPoint.mInterestPoint.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&v1->mRequestedInterestPoint.mInterestPoint.mPrev;
  v15 = &v1->mInterestPointLink.mLinkObject;
  if ( v1->mInterestPointLink.mLinkObject.m_pPointer )
  {
    v16 = v15->mPrev;
    v17 = v1->mInterestPointLink.mLinkObject.mNext;
    v16->mNext = v17;
    v17->mPrev = v16;
    v15->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v15->mPrev;
    v1->mInterestPointLink.mLinkObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mInterestPointLink.mLinkObject.mPrev;
  }
  v1->mInterestPointLink.mLinkObject.m_pPointer = 0i64;
  v18 = v15->mPrev;
  v19 = v1->mInterestPointLink.mLinkObject.mNext;
  v18->mNext = v19;
  v19->mPrev = v18;
  v15->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v15->mPrev;
  v1->mInterestPointLink.mLinkObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mInterestPointLink.mLinkObject.mPrev;
  UFG::InterestPointQuery::~InterestPointQuery(&v1->mInterestPointQuery);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->mNavComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->mAIScriptInterfaceComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->mActiveAIEntityComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>(&v1->mTransformNodeComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->mTargetingSystemPedBaseComponent);
  v20 = &v1->mLastInterestPoint;
  if ( v1->mLastInterestPoint.m_pPointer )
  {
    v21 = v20->mPrev;
    v22 = v1->mLastInterestPoint.mNext;
    v21->mNext = v22;
    v22->mPrev = v21;
    v20->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&v20->mPrev;
    v1->mLastInterestPoint.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&v1->mLastInterestPoint.mPrev;
  }
  v1->mLastInterestPoint.m_pPointer = 0i64;
  v23 = v20->mPrev;
  v24 = v1->mLastInterestPoint.mNext;
  v23->mNext = v24;
  v24->mPrev = v23;
  v20->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&v20->mPrev;
  v1->mLastInterestPoint.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&v1->mLastInterestPoint.mPrev;
  v25 = v2->mPrev;
  v26 = v2->mNext;
  v25->mNext = v26;
  v26->mPrev = v25;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}rev = v25;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1-

// File Line: 216
// RVA: 0x382CF0
void __fastcall UFG::InterestPointUserComponent::Reset(UFG::InterestPointUserComponent *this)
{
  UFG::InterestPointUserComponent *v1; // rdi
  UFG::SimObjectCVBase *v2; // rcx
  UFG::SimObjectCharacterPropertiesComponent *v3; // rax
  bool v4; // cl
  UFG::InterestPoint *v5; // rbx
  UFG::qSafePointer<UFG::InterestPoint,UFG::InterestPoint> *v6; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::InterestPointQuery::Candidate *v9; // rcx
  UFG::InterestPoint **v10; // rbx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v11; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::InterestPointUseDetails *v14; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::ActiveInterestPoint *v17; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v19; // rax

  v1 = this;
  v2 = (UFG::SimObjectCVBase *)this->m_pSimObject;
  if ( v2 && (v3 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v2)) != 0i64 )
    v4 = v3->m_eGender == 2;
  else
    v4 = 0;
  v5 = v1->mLastInterestPoint.m_pPointer;
  if ( v5 )
  {
    if ( (UFG::SimObjectCharacter *)v1->m_pSimObject == LocalPlayer )
    {
      if ( !v4 )
      {
        UFG::InterestPoint::SetPlayerReference(v1->mLastInterestPoint.m_pPointer, 0);
LABEL_12:
        UFG::InterestPoint::UpdateAnimHandles(v5);
        goto LABEL_13;
      }
    }
    else if ( !v4 )
    {
      UFG::InterestPoint::SetMalePedestrianReference(v1->mLastInterestPoint.m_pPointer, 0);
      goto LABEL_12;
    }
    UFG::InterestPoint::SetFemalePedestrianReference(v1->mLastInterestPoint.m_pPointer, 0);
    goto LABEL_12;
  }
LABEL_13:
  v6 = &v1->mLastInterestPoint;
  if ( v1->mLastInterestPoint.m_pPointer )
  {
    v7 = v6->mPrev;
    v8 = v1->mLastInterestPoint.mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&v6->mPrev;
    v1->mLastInterestPoint.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&v1->mLastInterestPoint.mPrev;
  }
  v1->mLastInterestPoint.m_pPointer = 0i64;
  UFG::InterestPointQuery::End(&v1->mInterestPointQuery, 0);
  v9 = v1->mInterestPointQuery.mCandidates.p;
  if ( v9 )
  {
    v10 = &v9[-1].mInterestPoint.m_pPointer;
    `eh vector destructor iterator'(
      v9,
      0xF0ui64,
      (int)v9[-1].mInterestPoint.m_pPointer,
      (void (__fastcall *)(void *))UFG::InterestPointQuery::Candidate::~Candidate);
    operator delete[](v10);
  }
  v11 = &v1->mInterestPointLink.mLinkObject;
  v1->mInterestPointQuery.mCandidates.p = 0i64;
  *(_QWORD *)&v1->mInterestPointQuery.mCandidates.size = 0i64;
  if ( v1->mInterestPointLink.mLinkObject.m_pPointer )
  {
    v12 = v11->mPrev;
    v13 = v1->mInterestPointLink.mLinkObject.mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    v11->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v11->mPrev;
    v1->mInterestPointLink.mLinkObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mInterestPointLink.mLinkObject.mPrev;
  }
  v1->mInterestPointLink.mLinkObject.m_pPointer = 0i64;
  v14 = &v1->mRequestedInterestPoint;
  v1->mInterestPointLink.mPOIUseType = 2;
  v1->mInterestPointLink.mIsExclusive = 0;
  if ( v1->mRequestedInterestPoint.mInterestPoint.m_pPointer )
  {
    v15 = v14->mInterestPoint.mPrev;
    v16 = v1->mRequestedInterestPoint.mInterestPoint.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    v14->mInterestPoint.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&v14->mInterestPoint.mPrev;
    v1->mRequestedInterestPoint.mInterestPoint.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&v1->mRequestedInterestPoint.mInterestPoint.mPrev;
  }
  v1->mRequestedInterestPoint.mInterestPoint.m_pPointer = 0i64;
  v1->mRequestedInterestPoint.mPOIUseType = 0;
  UFG::qSymbol::set_null(&v1->mRequestedInterestPoint.mSkipIntoLabel);
  v17 = &v1->mActiveInterestPoint;
  if ( v1->mActiveInterestPoint.mInterestPoint.m_pPointer )
  {
    v18 = v17->mInterestPoint.mPrev;
    v19 = v1->mActiveInterestPoint.mInterestPoint.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    v17->mInterestPoint.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&v17->mInterestPoint.mPrev;
    v1->mActiveInterestPoint.mInterestPoint.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&v1->mActiveInterestPoint.mInterestPoint.mPrev;
  }
  v1->mActiveInterestPoint.mInterestPoint.m_pPointer = 0i64;
  v1->mActiveInterestPoint.mPOIUseType = 0;
  UFG::qSymbol::set_null(&v1->mActiveInterestPoint.mSkipIntoLabel);
  v1->mActiveInterestPoint.mIsFirstUse = 1;
  v1->mLastUsedPOIType = UFG::gNullQSymbol;
  v1->mLastUsedPOIDesc = UFG::gNullQSymbol;
}

// File Line: 231
// RVA: 0x37F0C0
UFG::SimComponent *__fastcall UFG::InterestPointUserComponent::PropertiesOnActivateNew(UFG::SceneObjectProperties *pSceneObj, bool required)
{
  UFG::SceneObjectProperties *v2; // rbx
  UFG::qMemoryPool *v3; // rax
  UFG::allocator::free_link *v4; // rax
  UFG::SimComponent *v5; // rax
  UFG::SimComponent *v6; // rdi
  UFG::SimObject *v7; // rdx
  unsigned __int16 v8; // cx
  unsigned int v9; // ebx
  UFG::SimObjectModifier v11; // [rsp+38h] [rbp-30h]

  v2 = pSceneObj;
  v3 = UFG::GetSimulationMemoryPool();
  v4 = UFG::qMemoryPool::Allocate(v3, 0x238ui64, "InterestPointUserComponent", 0i64, 1u);
  if ( v4 )
  {
    UFG::InterestPointUserComponent::InterestPointUserComponent((UFG::InterestPointUserComponent *)v4, v2->m_NameUID);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  v7 = v2->m_pSimObject;
  v8 = v7->m_Flags;
  if ( (v8 >> 14) & 1 )
  {
    v9 = 43;
  }
  else if ( (v8 & 0x8000u) == 0 && (v8 >> 13) & 1 )
  {
    v9 = 12;
  }
  else
  {
    v9 = -1;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v11, v7, 1);
  UFG::SimObjectModifier::AttachComponent(&v11, v6, v9);
  UFG::SimObjectModifier::Close(&v11);
  UFG::SimObjectModifier::~SimObjectModifier(&v11);
  return v6;
}

// File Line: 240
// RVA: 0x378E80
void __fastcall UFG::InterestPointUserComponent::OnAttach(UFG::InterestPointUserComponent *this, UFG::SimObject *object)
{
  UFG::InterestPointUserComponent *v2; // rdi
  UFG::SimObject *v3; // rbx
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0> *v4; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rax
  UFG::RebindingComponentHandle<UFG::TargetingSystemPedBaseComponent,0> *v9; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v12; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rax
  UFG::RebindingComponentHandle<UFG::AIScriptInterfaceComponent,0> *v14; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v17; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v18; // rax
  UFG::RebindingComponentHandle<UFG::NavComponent,0> *v19; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v20; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v21; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v22; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v23; // rax
  UFG::NavComponent *v24; // rax
  UFG::SceneObjectProperties *v25; // rax
  UFG::qPropertySet *v26; // rcx
  bool *v27; // rax
  char *v28; // rcx
  char v29; // [rsp+30h] [rbp+8h]

  v2 = this;
  v3 = object;
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::Bind<UFG::SimObject>(
    &this->mTransformNodeComponent,
    object);
  v4 = &v2->mActiveAIEntityComponent;
  if ( v2->mActiveAIEntityComponent.m_pSimComponent )
  {
    v5 = v4->mPrev;
    v6 = v2->mActiveAIEntityComponent.mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v2->mActiveAIEntityComponent.m_pSimComponent = 0i64;
LABEL_7:
    v2->mActiveAIEntityComponent.m_pSimObject = 0i64;
    v2->mActiveAIEntityComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->mActiveAIEntityComponent.mPrev;
    v4->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v4->mPrev;
    goto LABEL_8;
  }
  if ( v2->mActiveAIEntityComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0> *)v4->mPrev != v4
     || (UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0> *)v2->mActiveAIEntityComponent.mNext != &v2->mActiveAIEntityComponent) )
  {
    v7 = v4->mPrev;
    v8 = v2->mActiveAIEntityComponent.mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    goto LABEL_7;
  }
LABEL_8:
  v2->mActiveAIEntityComponent.m_Changed = 1;
  v2->mActiveAIEntityComponent.m_pSimObject = v3;
  v2->mActiveAIEntityComponent.m_TypeUID = UFG::ActiveAIEntityComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0>::BindInternal<UFG::SimObject>(v4, v3);
  v9 = &v2->mTargetingSystemPedBaseComponent;
  if ( v2->mTargetingSystemPedBaseComponent.m_pSimComponent )
  {
    v10 = v9->mPrev;
    v11 = v2->mTargetingSystemPedBaseComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    v2->mTargetingSystemPedBaseComponent.m_pSimComponent = 0i64;
LABEL_14:
    v2->mTargetingSystemPedBaseComponent.m_pSimObject = 0i64;
    v2->mTargetingSystemPedBaseComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->mTargetingSystemPedBaseComponent.mPrev;
    v9->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v9->mPrev;
    goto LABEL_15;
  }
  if ( v2->mTargetingSystemPedBaseComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::TargetingSystemPedBaseComponent,0> *)v9->mPrev != v9
     || (UFG::RebindingComponentHandle<UFG::TargetingSystemPedBaseComponent,0> *)v2->mTargetingSystemPedBaseComponent.mNext != &v2->mTargetingSystemPedBaseComponent) )
  {
    v12 = v9->mPrev;
    v13 = v2->mTargetingSystemPedBaseComponent.mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    goto LABEL_14;
  }
LABEL_15:
  v2->mTargetingSystemPedBaseComponent.m_Changed = 1;
  v2->mTargetingSystemPedBaseComponent.m_pSimObject = v3;
  v2->mTargetingSystemPedBaseComponent.m_TypeUID = UFG::TargetingSystemPedBaseComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::TargetingSystemPedBaseComponent,0>::BindInternal<UFG::SimObject>(
    &v2->mTargetingSystemPedBaseComponent,
    v3);
  v14 = &v2->mAIScriptInterfaceComponent;
  if ( v2->mAIScriptInterfaceComponent.m_pSimComponent )
  {
    v15 = v14->mPrev;
    v16 = v2->mAIScriptInterfaceComponent.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    v2->mAIScriptInterfaceComponent.m_pSimComponent = 0i64;
LABEL_21:
    v2->mAIScriptInterfaceComponent.m_pSimObject = 0i64;
    v2->mAIScriptInterfaceComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->mAIScriptInterfaceComponent.mPrev;
    v14->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v14->mPrev;
    goto LABEL_22;
  }
  if ( v2->mAIScriptInterfaceComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::AIScriptInterfaceComponent,0> *)v14->mPrev != v14
     || (UFG::RebindingComponentHandle<UFG::AIScriptInterfaceComponent,0> *)v2->mAIScriptInterfaceComponent.mNext != &v2->mAIScriptInterfaceComponent) )
  {
    v17 = v14->mPrev;
    v18 = v2->mAIScriptInterfaceComponent.mNext;
    v17->mNext = v18;
    v18->mPrev = v17;
    goto LABEL_21;
  }
LABEL_22:
  v2->mAIScriptInterfaceComponent.m_Changed = 1;
  v2->mAIScriptInterfaceComponent.m_pSimObject = v3;
  v2->mAIScriptInterfaceComponent.m_TypeUID = UFG::AIScriptInterfaceComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::AIScriptInterfaceComponent,0>::BindInternal<UFG::SimObject>(
    &v2->mAIScriptInterfaceComponent,
    v3);
  v19 = &v2->mNavComponent;
  if ( v2->mNavComponent.m_pSimComponent )
  {
    v20 = v19->mPrev;
    v21 = v2->mNavComponent.mNext;
    v20->mNext = v21;
    v21->mPrev = v20;
    v2->mNavComponent.m_pSimComponent = 0i64;
LABEL_28:
    v2->mNavComponent.m_pSimObject = 0i64;
    v2->mNavComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->mNavComponent.mPrev;
    v19->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v19->mPrev;
    goto LABEL_29;
  }
  if ( v2->mNavComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::NavComponent,0> *)v19->mPrev != v19
     || (UFG::RebindingComponentHandle<UFG::NavComponent,0> *)v2->mNavComponent.mNext != &v2->mNavComponent) )
  {
    v22 = v19->mPrev;
    v23 = v2->mNavComponent.mNext;
    v22->mNext = v23;
    v23->mPrev = v22;
    goto LABEL_28;
  }
LABEL_29:
  v2->mNavComponent.m_Changed = 1;
  v2->mNavComponent.m_pSimObject = v3;
  v2->mNavComponent.m_TypeUID = UFG::NavComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::NavComponent,0>::BindInternal<UFG::SimObject>(&v2->mNavComponent, v3);
  v24 = (UFG::NavComponent *)v2->mNavComponent.m_pSimComponent;
  v29 = 1;
  v2->mInterestPointQuery.mNavComponent = v24;
  v25 = v3->m_pSceneObj;
  v26 = v25->mpWritableProperties;
  if ( !v26 )
    v26 = v25->mpConstProperties;
  v27 = UFG::qPropertySet::Get<bool>(v26, (UFG::qSymbol *)&SimSym_AttractedToPOIs.mUID, DEPTH_RECURSE);
  v28 = &v29;
  if ( v27 )
    v28 = (char *)v27;
  *((_BYTE *)v2 + 80) ^= (*((_BYTE *)v2 + 80) ^ *v28) & 1;
  UFG::InterestPointUserComponent::Reset(v2);
}

// File Line: 256
// RVA: 0x37AAE0
void __fastcall UFG::InterestPointUserComponent::OnDetach(UFG::InterestPointUserComponent *this)
{
  UFG::InterestPointUserComponent *v1; // rdi
  UFG::SimObject *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::InterestPoint *v4; // rbx
  __int64 v5; // r9
  UFG::SimObjectCVBase *v6; // rcx
  UFG::SimObjectCharacterPropertiesComponent *v7; // rax
  bool v8; // cl
  UFG::InterestPoint *v9; // rbx
  UFG::qSafePointer<UFG::InterestPoint,UFG::InterestPoint> *v10; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::InterestPointQuery::Candidate *v13; // rcx
  UFG::InterestPoint **v14; // rbx
  UFG::RebindingComponentHandle<UFG::AIScriptInterfaceComponent,0> *v15; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v17; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v18; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v19; // rax
  UFG::RebindingComponentHandle<UFG::TargetingSystemPedBaseComponent,0> *v20; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v21; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v22; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v23; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v24; // rax
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0> *v25; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v26; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v27; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v28; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v29; // rax
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *v30; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v31; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v32; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v33; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v34; // rax
  UFG::RebindingComponentHandle<UFG::NavComponent,0> *v35; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v36; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v37; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v38; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v39; // rax

  v1 = this;
  v2 = *(UFG::SimObject **)(56i64
                          * *(unsigned __int8 *)(*(_QWORD *)&this->mTargetingSystemPedBaseComponent.m_pSimComponent[1].m_Flags
                                               + 34i64)
                          + *(_QWORD *)&this->mTargetingSystemPedBaseComponent.m_pSimComponent[1].m_TypeUID
                          + 40);
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = (UFG::InterestPoint *)v2->m_Components.p[25].m_pComponent;
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
        v4 = (UFG::InterestPoint *)v2->m_Components.p[10].m_pComponent;
      else
        v4 = (UFG::InterestPoint *)((v3 >> 12) & 1 ? v2->m_Components.p[3].m_pComponent : UFG::SimObject::GetComponentOfType(
                                                                                            v2,
                                                                                            UFG::InterestPoint::_TypeUID));
    }
    else
    {
      v4 = (UFG::InterestPoint *)v2->m_Components.p[25].m_pComponent;
    }
    if ( v4
      && !UFG::InterestPoint::IsReservationMatch(v4, 8u, ReserveReason_normal)
      && v4->mpUser.m_pPointer == v1->m_pSimObject )
    {
      UFG::InterestPoint::EndReservation(v4);
      UFG::TargetingSystemBaseComponent::SetTarget(
        (UFG::TargetingSystemBaseComponent *)v1->mTargetingSystemPedBaseComponent.m_pSimComponent,
        eTARGET_TYPE_POI_USE,
        0i64);
      LOBYTE(v5) = 1;
      ((void (__fastcall *)(UFG::SimComponent *, signed __int64, _QWORD, __int64, _DWORD, _QWORD, _QWORD, _QWORD))v1->mTargetingSystemPedBaseComponent.m_pSimComponent->vfptr[14].__vecDelDtor)(
        v1->mTargetingSystemPedBaseComponent.m_pSimComponent,
        26i64,
        0i64,
        v5,
        0,
        0i64,
        0i64,
        0i64);
    }
  }
  v6 = (UFG::SimObjectCVBase *)v1->m_pSimObject;
  if ( v6 && (v7 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v6)) != 0i64 )
    v8 = v7->m_eGender == 2;
  else
    v8 = 0;
  v9 = v1->mLastInterestPoint.m_pPointer;
  if ( v9 )
  {
    if ( (UFG::SimObjectCharacter *)v1->m_pSimObject == LocalPlayer )
    {
      if ( !v8 )
      {
        UFG::InterestPoint::SetPlayerReference(v1->mLastInterestPoint.m_pPointer, 0);
LABEL_26:
        UFG::InterestPoint::UpdateAnimHandles(v9);
        goto LABEL_27;
      }
    }
    else if ( !v8 )
    {
      UFG::InterestPoint::SetMalePedestrianReference(v1->mLastInterestPoint.m_pPointer, 0);
      goto LABEL_26;
    }
    UFG::InterestPoint::SetFemalePedestrianReference(v1->mLastInterestPoint.m_pPointer, 0);
    goto LABEL_26;
  }
LABEL_27:
  v10 = &v1->mLastInterestPoint;
  if ( v1->mLastInterestPoint.m_pPointer )
  {
    v11 = v10->mPrev;
    v12 = v1->mLastInterestPoint.mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    v10->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&v10->mPrev;
    v1->mLastInterestPoint.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&v1->mLastInterestPoint.mPrev;
  }
  v1->mLastInterestPoint.m_pPointer = 0i64;
  UFG::InterestPointQuery::End(&v1->mInterestPointQuery, 0);
  v13 = v1->mInterestPointQuery.mCandidates.p;
  if ( v13 )
  {
    v14 = &v13[-1].mInterestPoint.m_pPointer;
    `eh vector destructor iterator'(
      v13,
      0xF0ui64,
      (int)v13[-1].mInterestPoint.m_pPointer,
      (void (__fastcall *)(void *))UFG::InterestPointQuery::Candidate::~Candidate);
    operator delete[](v14);
  }
  v15 = &v1->mAIScriptInterfaceComponent;
  v1->mInterestPointQuery.mCandidates.p = 0i64;
  *(_QWORD *)&v1->mInterestPointQuery.mCandidates.size = 0i64;
  if ( v1->mAIScriptInterfaceComponent.m_pSimComponent )
  {
    v16 = v15->mPrev;
    v17 = v1->mAIScriptInterfaceComponent.mNext;
    v16->mNext = v17;
    v17->mPrev = v16;
    v1->mAIScriptInterfaceComponent.m_pSimComponent = 0i64;
LABEL_37:
    v1->mAIScriptInterfaceComponent.m_pSimObject = 0i64;
    v1->mAIScriptInterfaceComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mAIScriptInterfaceComponent.mPrev;
    v15->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v15->mPrev;
    goto LABEL_38;
  }
  if ( v1->mAIScriptInterfaceComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::AIScriptInterfaceComponent,0> *)v15->mPrev != v15
     || (UFG::RebindingComponentHandle<UFG::AIScriptInterfaceComponent,0> *)v1->mAIScriptInterfaceComponent.mNext != &v1->mAIScriptInterfaceComponent) )
  {
    v18 = v15->mPrev;
    v19 = v1->mAIScriptInterfaceComponent.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    goto LABEL_37;
  }
LABEL_38:
  v1->mAIScriptInterfaceComponent.m_Changed = 1;
  v20 = &v1->mTargetingSystemPedBaseComponent;
  if ( v1->mTargetingSystemPedBaseComponent.m_pSimComponent )
  {
    v21 = v20->mPrev;
    v22 = v1->mTargetingSystemPedBaseComponent.mNext;
    v21->mNext = v22;
    v22->mPrev = v21;
    v1->mTargetingSystemPedBaseComponent.m_pSimComponent = 0i64;
LABEL_44:
    v1->mTargetingSystemPedBaseComponent.m_pSimObject = 0i64;
    v1->mTargetingSystemPedBaseComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mTargetingSystemPedBaseComponent.mPrev;
    v20->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v20->mPrev;
    goto LABEL_45;
  }
  if ( v1->mTargetingSystemPedBaseComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::TargetingSystemPedBaseComponent,0> *)v20->mPrev != v20
     || (UFG::RebindingComponentHandle<UFG::TargetingSystemPedBaseComponent,0> *)v1->mTargetingSystemPedBaseComponent.mNext != &v1->mTargetingSystemPedBaseComponent) )
  {
    v23 = v20->mPrev;
    v24 = v1->mTargetingSystemPedBaseComponent.mNext;
    v23->mNext = v24;
    v24->mPrev = v23;
    goto LABEL_44;
  }
LABEL_45:
  v1->mTargetingSystemPedBaseComponent.m_Changed = 1;
  v25 = &v1->mActiveAIEntityComponent;
  if ( v1->mActiveAIEntityComponent.m_pSimComponent )
  {
    v26 = v25->mPrev;
    v27 = v1->mActiveAIEntityComponent.mNext;
    v26->mNext = v27;
    v27->mPrev = v26;
    v1->mActiveAIEntityComponent.m_pSimComponent = 0i64;
LABEL_51:
    v1->mActiveAIEntityComponent.m_pSimObject = 0i64;
    v1->mActiveAIEntityComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mActiveAIEntityComponent.mPrev;
    v25->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v25->mPrev;
    goto LABEL_52;
  }
  if ( v1->mActiveAIEntityComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0> *)v25->mPrev != v25
     || (UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0> *)v1->mActiveAIEntityComponent.mNext != &v1->mActiveAIEntityComponent) )
  {
    v28 = v25->mPrev;
    v29 = v1->mActiveAIEntityComponent.mNext;
    v28->mNext = v29;
    v29->mPrev = v28;
    goto LABEL_51;
  }
LABEL_52:
  v1->mActiveAIEntityComponent.m_Changed = 1;
  v30 = &v1->mTransformNodeComponent;
  if ( v1->mTransformNodeComponent.m_pSimComponent )
  {
    v31 = v30->mPrev;
    v32 = v1->mTransformNodeComponent.mNext;
    v31->mNext = v32;
    v32->mPrev = v31;
    v1->mTransformNodeComponent.m_pSimComponent = 0i64;
LABEL_58:
    v1->mTransformNodeComponent.m_pSimObject = 0i64;
    v1->mTransformNodeComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mTransformNodeComponent.mPrev;
    v30->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v30->mPrev;
    goto LABEL_59;
  }
  if ( v1->mTransformNodeComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)v30->mPrev != v30
     || (UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)v1->mTransformNodeComponent.mNext != &v1->mTransformNodeComponent) )
  {
    v33 = v30->mPrev;
    v34 = v1->mTransformNodeComponent.mNext;
    v33->mNext = v34;
    v34->mPrev = v33;
    goto LABEL_58;
  }
LABEL_59:
  v1->mTransformNodeComponent.m_Changed = 1;
  v35 = &v1->mNavComponent;
  if ( v1->mNavComponent.m_pSimComponent )
  {
    v36 = v35->mPrev;
    v37 = v1->mNavComponent.mNext;
    v36->mNext = v37;
    v37->mPrev = v36;
    v1->mNavComponent.m_pSimComponent = 0i64;
LABEL_65:
    v1->mNavComponent.m_pSimObject = 0i64;
    v1->mNavComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mNavComponent.mPrev;
    v35->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v35->mPrev;
    goto LABEL_66;
  }
  if ( v1->mNavComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::NavComponent,0> *)v35->mPrev != v35
     || (UFG::RebindingComponentHandle<UFG::NavComponent,0> *)v1->mNavComponent.mNext != &v1->mNavComponent) )
  {
    v38 = v35->mPrev;
    v39 = v1->mNavComponent.mNext;
    v38->mNext = v39;
    v39->mPrev = v38;
    goto LABEL_65;
  }
LABEL_66:
  v1->mNavComponent.m_Changed = 1;
}omponentHandle<UFG::NavComp

// File Line: 357
// RVA: 0x3970B0
void __fastcall UFG::InterestPointUserComponent::UpdateLookAtPOITarget(UFG::InterestPointUserComponent *this)
{
  UFG::InterestPointUserComponent *v1; // rsi
  signed __int64 v2; // r8
  UFG::SimComponent *v3; // rbx
  UFG::SimObjectCharacter *v4; // rdi
  UFG::InterestPoint *v5; // rax
  UFG::SimComponent *v6; // rdi
  unsigned __int8 v7; // cl
  signed __int64 v8; // rbx

  v1 = this;
  v2 = *(_QWORD *)&this->mTargetingSystemPedBaseComponent.m_pSimComponent[1].m_TypeUID
     + 56i64
     * *(unsigned __int8 *)(*(_QWORD *)&this->mTargetingSystemPedBaseComponent.m_pSimComponent[1].m_Flags + 33i64);
  if ( !*(_QWORD *)(v2 + 40) || !*(_BYTE *)(v2 + 49) )
  {
    v3 = this->mTransformNodeComponent.m_pSimComponent;
    v4 = (UFG::SimObjectCharacter *)this->m_pSimObject;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->mTransformNodeComponent.m_pSimComponent);
    v5 = UFG::InterestPoint::FindNearestRelevent(
           v4,
           0,
           v1,
           (UFG::TargetingSystemPedBaseComponent *)v1->mTargetingSystemPedBaseComponent.m_pSimComponent,
           (UFG::ActiveAIEntityComponent *)v1->mActiveAIEntityComponent.m_pSimComponent,
           (UFG::qMatrix44 *)&v3[2],
           &UFG::InterestPointUserComponent::msPlayerPosition,
           (UFG::qSymbol *)&qSymbol_look.mUID,
           0xFFFFFFFF,
           UFG::TargetingSystemPedBaseComponent::ms_TargetingParameters.m_fMaxPOITargetingRange
         * UFG::TargetingSystemPedBaseComponent::ms_TargetingParameters.m_fMaxPOITargetingRange,
           0i64,
           0i64,
           0i64);
    if ( v5 )
    {
      UFG::TargetingSystemBaseComponent::SetTarget(
        (UFG::TargetingSystemBaseComponent *)v1->mTargetingSystemPedBaseComponent.m_pSimComponent,
        eTARGET_TYPE_POI_LOOK_AT,
        v5->m_pSimObject);
    }
    else
    {
      v6 = v1->mTargetingSystemPedBaseComponent.m_pSimComponent;
      v7 = *(_BYTE *)(*(_QWORD *)&v6[1].m_Flags + 33i64);
      if ( v7 )
      {
        v8 = 56i64 * v7;
        UFG::TargetingSimObject::SetTarget((UFG::TargetingSimObject *)(v8 + *(_QWORD *)&v6[1].m_TypeUID), 0i64);
        UFG::TargetingSimObject::SetLock((UFG::TargetingSimObject *)(v8 + *(_QWORD *)&v6[1].m_TypeUID), 0);
      }
    }
  }
}

// File Line: 376
// RVA: 0x399020
void __fastcall UFG::InterestPointUserComponent::UpdateUsePOITarget(UFG::InterestPointUserComponent *this, bool bIsPlayer, UFG::qFixedArray<UFG::InterestPoint *,4> *apClosestPOIWithBehaviour)
{
  UFG::InterestPointQuery *v3; // rsi
  bool v4; // r14
  UFG::InterestPointUserComponent *v5; // rdi
  UFG::qFixedArray<UFG::InterestPoint *,4> *apNearestPOIWithBehaviour; // rbp
  UFG::InterestPointQuery::Candidate *v7; // rcx
  char *v8; // rbx
  UFG::SimComponent *v9; // rbx
  UFG::SimObjectCharacter *v10; // r15
  UFG::qMatrix44 *characterTransform; // rbx
  float maxDistSquared; // xmm6_4
  bool v13; // al
  UFG::qArray<UFG::InterestPointQuery::Candidate,0> *pCandidates; // rcx
  UFG::InterestPoint *v15; // rax
  UFG::NavComponent *v16; // rdx

  v3 = &this->mInterestPointQuery;
  v4 = bIsPlayer;
  v5 = this;
  apNearestPOIWithBehaviour = apClosestPOIWithBehaviour;
  UFG::InterestPointQuery::End(&this->mInterestPointQuery, 0);
  v7 = v3->mCandidates.p;
  if ( v7 )
  {
    v8 = (char *)&v7[-1].mInterestPoint.m_pPointer;
    `eh vector destructor iterator'(
      v7,
      0xF0ui64,
      (int)v7[-1].mInterestPoint.m_pPointer,
      (void (__fastcall *)(void *))UFG::InterestPointQuery::Candidate::~Candidate);
    operator delete[](v8);
  }
  v3->mCandidates.p = 0i64;
  *(_QWORD *)&v3->mCandidates.size = 0i64;
  v9 = v5->mTransformNodeComponent.m_pSimComponent;
  v10 = (UFG::SimObjectCharacter *)v5->m_pSimObject;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v5->mTransformNodeComponent.m_pSimComponent);
  characterTransform = (UFG::qMatrix44 *)&v9[2];
  maxDistSquared = UFG::TargetingSystemPedBaseComponent::ms_TargetingParameters.m_fMaxPOITargetingRange
                 * UFG::TargetingSystemPedBaseComponent::ms_TargetingParameters.m_fMaxPOITargetingRange;
  v13 = UFG::InterestPoint::IsTraversalsEnabled();
  pCandidates = &v5->mInterestPointQuery.mCandidates;
  if ( !v13 )
    pCandidates = 0i64;
  v15 = UFG::InterestPoint::FindNearestRelevent(
          v10,
          v4,
          v5,
          (UFG::TargetingSystemPedBaseComponent *)v5->mTargetingSystemPedBaseComponent.m_pSimComponent,
          (UFG::ActiveAIEntityComponent *)v5->mActiveAIEntityComponent.m_pSimComponent,
          characterTransform,
          &UFG::InterestPointUserComponent::msPlayerPosition,
          (UFG::qSymbol *)&qSymbol_use.mUID,
          8u,
          maxDistSquared,
          0i64,
          pCandidates,
          apNearestPOIWithBehaviour);
  if ( v5->mNavComponent.m_Changed )
  {
    v16 = (UFG::NavComponent *)v5->mNavComponent.m_pSimComponent;
    v5->mNavComponent.m_Changed = 0;
    v5->mInterestPointQuery.mNavComponent = v16;
  }
  UFG::InterestPointQuery::Start(v3, v15);
}

// File Line: 451
// RVA: 0x397430
void __fastcall UFG::InterestPointUserComponent::UpdatePOIReferences(UFG::InterestPointUserComponent *this, UFG::InterestPoint *pNew, UFG::InterestPoint *pOld, bool bIsPlayer, bool bIsFemale)
{
  bool v5; // bp
  UFG::InterestPoint *v6; // rbx
  UFG::InterestPoint *v7; // rsi

  if ( pNew != pOld )
  {
    v5 = bIsPlayer;
    v6 = pOld;
    v7 = pNew;
    if ( !pNew )
      goto LABEL_10;
    if ( bIsPlayer )
    {
      if ( !bIsFemale )
      {
        UFG::InterestPoint::SetPlayerReference(pNew, 1);
LABEL_9:
        UFG::InterestPoint::UpdateAnimHandles(v7);
LABEL_10:
        if ( !v6 )
          return;
        if ( v5 )
        {
          if ( !bIsFemale )
          {
            UFG::InterestPoint::SetPlayerReference(v6, 0);
LABEL_17:
            UFG::InterestPoint::UpdateAnimHandles(v6);
            return;
          }
        }
        else if ( !bIsFemale )
        {
          UFG::InterestPoint::SetMalePedestrianReference(v6, 0);
          goto LABEL_17;
        }
        UFG::InterestPoint::SetFemalePedestrianReference(v6, 0);
        goto LABEL_17;
      }
    }
    else if ( !bIsFemale )
    {
      UFG::InterestPoint::SetMalePedestrianReference(pNew, 1);
      goto LABEL_9;
    }
    UFG::InterestPoint::SetFemalePedestrianReference(pNew, 1);
    goto LABEL_9;
  }
}

// File Line: 493
// RVA: 0x38FE70
void __fastcall UFG::InterestPointUserComponent::Update(UFG::InterestPointUserComponent *this, float delta_sec)
{
  UFG::InterestPointUserComponent *v2; // rdi
  UFG::SimObjectCharacter *v3; // rbp
  bool v4; // r12
  UFG::SimComponent *v5; // rbx
  float v6; // xmm1_4
  float v7; // xmm2_4
  char v8; // r13
  UFG::SimComponent *v9; // r14
  UFG::SimObject *v10; // rcx
  __int64 v11; // rax
  signed __int64 v12; // rdx
  bool v13; // r15
  char v14; // si
  unsigned __int16 v15; // dx
  UFG::InterestPoint *v16; // rbx
  UFG::SimObject *v17; // rdx
  UFG::SimComponent *v18; // r14
  unsigned __int8 v19; // cl
  signed __int64 v20; // rbx
  unsigned __int8 v21; // cl
  signed __int64 v22; // rbx
  char v23; // r14
  bool v24; // al
  UFG::SimComponent *v25; // rax
  unsigned __int16 v26; // cx
  UFG::SimComponent *v27; // rax
  char v28; // al
  unsigned int v29; // er8
  char v30; // cl
  char v31; // bl
  UFG::InterestPointQuery::QueryState v32; // eax
  UFG::SimObject *v33; // rcx
  UFG::InterestPoint *v34; // rbx
  unsigned __int16 v35; // dx
  UFG::SimObjectCVBase *v36; // rcx
  UFG::SimObjectCharacterPropertiesComponent *v37; // rax
  bool bIsFemale; // cl
  UFG::qSafePointer<UFG::InterestPoint,UFG::InterestPoint> *v39; // rdi
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v40; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v41; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v42; // rax
  __int64 v43; // rbx
  __int64 v44; // rbp
  UFG::InterestPoint *v45; // rdi
  __int64 v46; // rsi
  UFG::InterestPoint **v47; // rdi
  UFG::InterestPoint *v48; // rbx
  unsigned int v49; // er8
  __int64 v50; // r9
  UFG::qSafePointer<UFG::InterestPoint,UFG::InterestPoint> *v51; // rdx
  UFG::InterestPoint *v52; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v53; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v54; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v55; // rax
  UFG::qFixedArray<UFG::InterestPoint *,4> apClosestPOIWithBehaviour; // [rsp+38h] [rbp-50h]
  unsigned int v57; // [rsp+90h] [rbp+8h]

  v2 = this;
  v57 = UFG::Metrics::msInstance.mSimFrameCount;
  v3 = (UFG::SimObjectCharacter *)this->m_pSimObject;
  if ( v3 && v3 == LocalPlayer )
  {
    v4 = 1;
    v5 = this->mTransformNodeComponent.m_pSimComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->mTransformNodeComponent.m_pSimComponent);
    v6 = *((float *)&v5[2].m_BoundComponentHandles.mNode.mPrev + 1);
    v7 = *(float *)&v5[2].m_BoundComponentHandles.mNode.mNext;
    UFG::InterestPointUserComponent::msPlayerPosition.x = *(float *)&v5[2].m_BoundComponentHandles.mNode.mPrev;
    UFG::InterestPointUserComponent::msPlayerPosition.y = v6;
    UFG::InterestPointUserComponent::msPlayerPosition.z = v7;
  }
  else
  {
    v4 = 0;
  }
  v8 = 0;
  v9 = v2->mTargetingSystemPedBaseComponent.m_pSimComponent;
  v10 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v9[1].m_Flags + 34i64)
                           + *(_QWORD *)&v9[1].m_TypeUID
                           + 40);
  v11 = *(_QWORD *)&v9[1].m_Flags;
  v12 = *(_QWORD *)&v9[1].m_TypeUID + 56i64 * *(unsigned __int8 *)(v11 + 34);
  v13 = *(_QWORD *)(v12 + 40) && *(_BYTE *)(v12 + 49);
  v14 = 1;
  if ( v10 )
  {
    v8 = 1;
    v15 = v10->m_Flags;
    if ( (v15 >> 14) & 1 )
    {
      v16 = (UFG::InterestPoint *)v10->m_Components.p[25].m_pComponent;
    }
    else if ( (v15 & 0x8000u) == 0 )
    {
      if ( (v15 >> 13) & 1 )
      {
        v16 = (UFG::InterestPoint *)v10->m_Components.p[10].m_pComponent;
      }
      else if ( (v15 >> 12) & 1 )
      {
        v16 = (UFG::InterestPoint *)v10->m_Components.p[3].m_pComponent;
      }
      else
      {
        v16 = (UFG::InterestPoint *)UFG::SimObject::GetComponentOfType(v10, UFG::InterestPoint::_TypeUID);
      }
    }
    else
    {
      v16 = (UFG::InterestPoint *)v10->m_Components.p[25].m_pComponent;
    }
    if ( v16 )
    {
      if ( !UFG::InterestPoint::IsReservationMatch(v16, 8u, ReserveReason_normal) )
      {
        v17 = v2->m_pSimObject;
        if ( v16->mpUser.m_pPointer != v17 )
        {
          if ( v13 )
            UFG::InterestPoint::ForceUser(v16, v17);
          else
            v8 = 0;
        }
      }
      goto LABEL_30;
    }
    v8 = 0;
    v18 = v2->mTargetingSystemPedBaseComponent.m_pSimComponent;
    v19 = *(_BYTE *)(*(_QWORD *)&v18[1].m_Flags + 34i64);
    if ( v19 )
    {
      v20 = 56i64 * v19;
      UFG::TargetingSimObject::SetTarget((UFG::TargetingSimObject *)(v20 + *(_QWORD *)&v18[1].m_TypeUID), 0i64);
      UFG::TargetingSimObject::SetLock((UFG::TargetingSimObject *)(v20 + *(_QWORD *)&v18[1].m_TypeUID), 0);
    }
    v9 = v2->mTargetingSystemPedBaseComponent.m_pSimComponent;
    v11 = *(_QWORD *)&v9[1].m_Flags;
  }
  v21 = *(_BYTE *)(v11 + 35);
  if ( v21 )
  {
    v22 = 56i64 * v21;
    UFG::TargetingSimObject::SetTarget((UFG::TargetingSimObject *)(v22 + *(_QWORD *)&v9[1].m_TypeUID), 0i64);
    UFG::TargetingSimObject::SetLock((UFG::TargetingSimObject *)(v22 + *(_QWORD *)&v9[1].m_TypeUID), 0);
  }
LABEL_30:
  v23 = 0;
  v24 = UFG::InterestPointUserComponent::msPlayerInVehicle;
  if ( v4 )
    v24 = 0;
  UFG::InterestPointUserComponent::msPlayerInVehicle = v24;
  if ( *((_BYTE *)v2 + 80) & 1 )
  {
    if ( v4 )
    {
      if ( v8 && v13 )
        goto LABEL_55;
    }
    else if ( v8 )
    {
      goto LABEL_55;
    }
    v25 = v2->mAIScriptInterfaceComponent.m_pSimComponent;
    if ( !v25 || HIDWORD(v25[1].m_SafePointerList.mNode.mNext) <= 0 )
    {
      if ( v3
        && ((v26 = v3->m_Flags, !((v26 >> 14) & 1)) ? ((v26 & 0x8000u) == 0 ? (!((v26 >> 13) & 1) ? (!((v26 >> 12) & 1) ? (v27 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::CharacterOccupantComponent::_TypeUID)) : (v27 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v3->vfptr, UFG::CharacterOccupantComponent::_TypeUID))) : (v27 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v3->vfptr, UFG::CharacterOccupantComponent::_TypeUID))) : (v27 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v3->vfptr, UFG::CharacterOccupantComponent::_TypeUID))) : (v27 = v3->m_Components.p[44].m_pComponent),
            v27) )
      {
        v28 = UFG::InterestPointUserComponent::msPlayerInVehicle;
        if ( v4 )
          v28 = 1;
        UFG::InterestPointUserComponent::msPlayerInVehicle = v28;
      }
      else
      {
        v23 = 1;
      }
    }
  }
LABEL_55:
  v29 = v3->mNode.mUID;
  if ( UFG::InterestPointUserComponent::msPlayerInVehicle
    || !(*((_BYTE *)v2 + 80) & 2)
    && !v4
    && (v29 + v57) % UFG::InterestPointUserComponent::msInterestPointUseTargetUpdateFrequency_NPC )
  {
    v30 = 0;
    if ( UFG::InterestPointUserComponent::msPlayerInVehicle )
      goto LABEL_64;
  }
  else
  {
    v30 = 1;
  }
  if ( !v4 && !((v29 + v57) % UFG::InterestPointUserComponent::msInterestPointLookAtTargetUpdateFrequency_NPC) )
  {
    v31 = 1;
    goto LABEL_65;
  }
LABEL_64:
  v31 = 0;
LABEL_65:
  apClosestPOIWithBehaviour.size = 0;
  if ( v23 )
  {
    *((_BYTE *)v2 + 80) &= 0xFDu;
    if ( v2->mInterestPointQuery.mQueryState != 1 && v30 )
      UFG::InterestPointUserComponent::UpdateUsePOITarget(v2, v4, &apClosestPOIWithBehaviour);
    if ( v31 )
      UFG::InterestPointUserComponent::UpdateLookAtPOITarget(v2);
    if ( v2->mInterestPointQuery.mQueryState == 1 )
      UFG::InterestPointQuery::Update(&v2->mInterestPointQuery);
    v32 = v2->mInterestPointQuery.mQueryState;
    if ( v32 )
    {
      if ( v32 == 3 )
      {
        UFG::TargetingSystemBaseComponent::SetTarget(
          (UFG::TargetingSystemBaseComponent *)v2->mTargetingSystemPedBaseComponent.m_pSimComponent,
          eTARGET_TYPE_POI_USE,
          v2->mInterestPointQuery.mBestInterestPoint.m_pPointer->m_pSimObject);
        UFG::InterestPointQuery::End(&v2->mInterestPointQuery, 0);
      }
      else if ( v32 == 2 )
      {
        UFG::TargetingSystemBaseComponent::ClearTarget(
          (UFG::TargetingSystemBaseComponent *)v2->mTargetingSystemPedBaseComponent.m_pSimComponent,
          eTARGET_TYPE_POI_USE);
        UFG::InterestPointQuery::End(&v2->mInterestPointQuery, 0);
      }
    }
  }
  else
  {
    if ( !v8 || !v30 )
      v14 = 0;
    *((_BYTE *)v2 + 80) ^= (*((_BYTE *)v2 + 80) ^ (*((_BYTE *)v2 + 80) | 2 * v14)) & 2;
  }
  v33 = *(UFG::SimObject **)(56i64
                           * *(unsigned __int8 *)(*(_QWORD *)&v2->mTargetingSystemPedBaseComponent.m_pSimComponent[1].m_Flags
                                                + 34i64)
                           + *(_QWORD *)&v2->mTargetingSystemPedBaseComponent.m_pSimComponent[1].m_TypeUID
                           + 40);
  if ( v33 )
  {
    v35 = v33->m_Flags;
    if ( (v35 >> 14) & 1 )
    {
      v34 = (UFG::InterestPoint *)v33->m_Components.p[25].m_pComponent;
    }
    else if ( (v35 & 0x8000u) == 0 )
    {
      if ( (v35 >> 13) & 1 )
      {
        v34 = (UFG::InterestPoint *)v33->m_Components.p[10].m_pComponent;
      }
      else if ( (v35 >> 12) & 1 )
      {
        v34 = (UFG::InterestPoint *)v33->m_Components.p[3].m_pComponent;
      }
      else
      {
        v34 = (UFG::InterestPoint *)UFG::SimObject::GetComponentOfType(v33, UFG::InterestPoint::_TypeUID);
      }
    }
    else
    {
      v34 = (UFG::InterestPoint *)v33->m_Components.p[25].m_pComponent;
    }
  }
  else
  {
    v34 = 0i64;
  }
  v36 = (UFG::SimObjectCVBase *)v2->m_pSimObject;
  if ( v36 && (v37 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v36)) != 0i64 )
    bIsFemale = v37->m_eGender == 2;
  else
    bIsFemale = 0;
  UFG::InterestPointUserComponent::UpdatePOIReferences(
    v2,
    v34,
    v2->mLastInterestPoint.m_pPointer,
    v2->m_pSimObject == (UFG::SimObject *)LocalPlayer,
    bIsFemale);
  v39 = &v2->mLastInterestPoint;
  if ( v39->m_pPointer )
  {
    v40 = v39->mPrev;
    v41 = v39->mNext;
    v40->mNext = v41;
    v41->mPrev = v40;
    v39->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&v39->mPrev;
    v39->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&v39->mPrev;
  }
  v39->m_pPointer = v34;
  if ( v34 )
  {
    v42 = v34->m_SafePointerList.mNode.mPrev;
    v42->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&v39->mPrev;
    v39->mPrev = v42;
    v39->mNext = &v34->m_SafePointerList.mNode;
    v34->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&v39->mPrev;
  }
  if ( v4 )
  {
    v43 = 0i64;
    v44 = apClosestPOIWithBehaviour.size;
    if ( (signed __int64)apClosestPOIWithBehaviour.size > 0 )
    {
      do
      {
        v45 = apClosestPOIWithBehaviour.p[v43];
        if ( v45 )
        {
          UFG::InterestPoint::SetPlayerReference(apClosestPOIWithBehaviour.p[v43], 1);
          UFG::InterestPoint::UpdateAnimHandles(v45);
        }
        ++v43;
      }
      while ( v43 < v44 );
    }
    v46 = UFG::InterestPointUserComponent::msaPlayersLastNearest.size;
    if ( (signed __int64)UFG::InterestPointUserComponent::msaPlayersLastNearest.size > 0 )
    {
      v47 = &UFG::InterestPointUserComponent::msaPlayersLastNearest.p[0].m_pPointer;
      do
      {
        v48 = *v47;
        if ( *v47 )
        {
          UFG::InterestPoint::SetPlayerReference(*v47, 0);
          UFG::InterestPoint::UpdateAnimHandles(v48);
        }
        v47 += 3;
        --v46;
      }
      while ( v46 );
    }
    v49 = 0;
    UFG::InterestPointUserComponent::msaPlayersLastNearest.size = 0;
    v50 = 0i64;
    if ( v44 > 0 )
    {
      while ( 1 )
      {
        v51 = &UFG::InterestPointUserComponent::msaPlayersLastNearest.p[v49];
        UFG::InterestPointUserComponent::msaPlayersLastNearest.size = v49 + 1;
        v52 = apClosestPOIWithBehaviour.p[v50];
        if ( v51->m_pPointer )
        {
          v53 = v51->mPrev;
          v54 = v51->mNext;
          v53->mNext = v54;
          v54->mPrev = v53;
          v51->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&v51->mPrev;
          v51->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&v51->mPrev;
        }
        v51->m_pPointer = v52;
        if ( v52 )
        {
          v55 = v52->m_SafePointerList.mNode.mPrev;
          v55->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&v51->mPrev;
          v51->mPrev = v55;
          v51->mNext = &v52->m_SafePointerList.mNode;
          v52->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&v51->mPrev;
        }
        if ( ++v50 >= v44 )
          break;
        v49 = UFG::InterestPointUserComponent::msaPlayersLastNearest.size;
      }
    }
  }
}

// File Line: 678
// RVA: 0x3992B0
void __fastcall UFG::InterestPointUserComponent::UsePOI(UFG::InterestPointUserComponent *this, UFG::InterestPoint *pInterestPoint, UFG::ePOIUseType poiUseType, UFG::qSymbol *skipIntoLabel)
{
  UFG::InterestPoint *v4; // r14
  UFG::InterestPointUserComponent *v5; // rbp
  UFG::InterestPointUseDetails *v6; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v9; // rax
  unsigned int v10; // ecx
  UFG::SimObject *v11; // rsi
  UFG::SimObjectCharacter *v12; // rbx
  UFG::InterestPoint *v13; // rdi
  bool bIsFemale; // al

  if ( pInterestPoint )
  {
    v4 = pInterestPoint;
    v5 = this;
    if ( this->mTargetingSystemPedBaseComponent.m_pSimComponent )
    {
      v6 = &this->mRequestedInterestPoint;
      if ( this->mRequestedInterestPoint.mInterestPoint.m_pPointer )
      {
        v7 = v6->mInterestPoint.mPrev;
        v8 = v6->mInterestPoint.mNext;
        v7->mNext = v8;
        v8->mPrev = v7;
        v6->mInterestPoint.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&v6->mInterestPoint.mPrev;
        v6->mInterestPoint.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&v6->mInterestPoint.mPrev;
      }
      v6->mInterestPoint.m_pPointer = pInterestPoint;
      v9 = pInterestPoint->m_SafePointerList.mNode.mPrev;
      v9->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&v6->mInterestPoint.mPrev;
      v6->mInterestPoint.mPrev = v9;
      v6->mInterestPoint.mNext = &pInterestPoint->m_SafePointerList.mNode;
      pInterestPoint->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&v6->mInterestPoint.mPrev;
      v6->mPOIUseType = poiUseType;
      v10 = skipIntoLabel->mUID;
      v6->mSkipIntoLabel = (UFG::qSymbol)skipIntoLabel->mUID;
      if ( v5->mActiveInterestPoint.mInterestPoint.m_pPointer != v6->mInterestPoint.m_pPointer
        || poiUseType != v5->mActiveInterestPoint.mPOIUseType
        || v10 != v5->mActiveInterestPoint.mSkipIntoLabel.mUID )
      {
        if ( UFG::InterestPoint::ForceUser(pInterestPoint, v5->m_pSimObject) )
        {
          UFG::TargetingSystemBaseComponent::SetTarget(
            (UFG::TargetingSystemBaseComponent *)v5->mTargetingSystemPedBaseComponent.m_pSimComponent,
            eTARGET_TYPE_POI_USE,
            v4->m_pSimObject);
          v11 = v5->m_pSimObject;
          v12 = LocalPlayer;
          v13 = v5->mLastInterestPoint.m_pPointer;
          bIsFemale = UFG::IsFemale(v5->m_pSimObject);
          UFG::InterestPointUserComponent::UpdatePOIReferences(v5, v4, v13, v11 == (UFG::SimObject *)v12, bIsFemale);
          UFG::qSafePointer<UFG::InterestPoint,UFG::InterestPoint>::operator=(&v5->mLastInterestPoint, v4);
          v5->mFrameCountOfLastPOIUse = UFG::Metrics::msInstance.mSimFrameCount;
        }
        else
        {
          UFG::InterestPointUseDetails::Reset(v6);
        }
      }
    }
  }
}

// File Line: 717
// RVA: 0x3892D0
void __fastcall UFG::InterestPointUserComponent::StopPOI(UFG::InterestPointUserComponent *this, __int64 a2, __int64 a3, __int64 a4)
{
  UFG::InterestPointUserComponent *v4; // rbx
  UFG::SimComponent *v5; // rcx
  int v6; // ST20_4
  UFG::InterestPointUseDetails *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v9; // rax

  v4 = this;
  v5 = this->mTargetingSystemPedBaseComponent.m_pSimComponent;
  if ( v5 )
  {
    v6 = 0;
    LOBYTE(a4) = 1;
    ((void (__fastcall *)(UFG::SimComponent *, signed __int64, _QWORD, __int64, int, const char *, _QWORD, _QWORD))v5->vfptr[14].__vecDelDtor)(
      v5,
      26i64,
      0i64,
      a4,
      v6,
      "InterestPointUserComponent::StopPOI",
      0i64,
      0i64);
  }
  v7 = &v4->mRequestedInterestPoint;
  if ( v4->mRequestedInterestPoint.mInterestPoint.m_pPointer )
  {
    v8 = v7->mInterestPoint.mPrev;
    v9 = v4->mRequestedInterestPoint.mInterestPoint.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mInterestPoint.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&v7->mInterestPoint.mPrev;
    v4->mRequestedInterestPoint.mInterestPoint.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *)&v4->mRequestedInterestPoint.mInterestPoint.mPrev;
  }
  v4->mRequestedInterestPoint.mInterestPoint.m_pPointer = 0i64;
  v4->mRequestedInterestPoint.mPOIUseType = 0;
  UFG::qSymbol::set_null(&v4->mRequestedInterestPoint.mSkipIntoLabel);
}

// File Line: 733
// RVA: 0x3871F0
void __fastcall UFG::InterestPointUserComponent::SetLinkObject(UFG::InterestPointUserComponent *this, UFG::SimObject *pSimObjLinker, UFG::ePOIUseType poiUseType, const bool exclusive)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v4; // r11
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // r10
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rax

  v4 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->mInterestPointLink.mLinkObject.mPrev;
  if ( this->mInterestPointLink.mLinkObject.m_pPointer )
  {
    v5 = v4->mPrev;
    v6 = this->mInterestPointLink.mLinkObject.mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v4->mPrev = v4;
    this->mInterestPointLink.mLinkObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->mInterestPointLink.mLinkObject.mPrev;
  }
  this->mInterestPointLink.mLinkObject.m_pPointer = pSimObjLinker;
  if ( pSimObjLinker )
  {
    v7 = pSimObjLinker->m_SafePointerList.mNode.mPrev;
    v7->mNext = v4;
    v4->mPrev = v7;
    this->mInterestPointLink.mLinkObject.mNext = &pSimObjLinker->m_SafePointerList.mNode;
    pSimObjLinker->m_SafePointerList.mNode.mPrev = v4;
  }
  this->mInterestPointLink.mPOIUseType = poiUseType;
  this->mInterestPointLink.mIsExclusive = exclusive;
}

