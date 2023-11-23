// File Line: 54
// RVA: 0x339080
void __fastcall UFG::IncomingAttackInfo::~IncomingAttackInfo(UFG::IncomingAttackInfo *this)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mAttacker; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v4; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rax

  p_mAttacker = &this->mAttacker;
  if ( this->mAttacker.m_pPointer )
  {
    mPrev = p_mAttacker->mPrev;
    mNext = p_mAttacker->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mAttacker->mPrev = p_mAttacker;
    p_mAttacker->mNext = p_mAttacker;
  }
  p_mAttacker->m_pPointer = 0i64;
  v4 = p_mAttacker->mPrev;
  v5 = p_mAttacker->mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  p_mAttacker->mPrev = p_mAttacker;
  p_mAttacker->mNext = p_mAttacker;
}

// File Line: 67
// RVA: 0x382C80
void __fastcall UFG::InterestPointLink::Reset(UFG::InterestPointLink *this)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mLinkObject; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax

  p_mLinkObject = &this->mLinkObject;
  if ( this->mLinkObject.m_pPointer )
  {
    mPrev = p_mLinkObject->mPrev;
    mNext = this->mLinkObject.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mLinkObject->mPrev = p_mLinkObject;
    this->mLinkObject.mNext = &this->mLinkObject;
  }
  this->mLinkObject.m_pPointer = 0i64;
  this->mPOIUseType = ePOIUseType_Script;
  this->mIsExclusive = 0;
}

// File Line: 86
// RVA: 0x338A10
void __fastcall UFG::InterestPointUseDetails::~InterestPointUseDetails(ActionContext *this)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v4; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rax

  if ( this->mSimObject.m_pPointer )
  {
    mPrev = this->mSimObject.mPrev;
    mNext = this->mSimObject.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mSimObject.mPrev = &this->mSimObject;
    this->mSimObject.mNext = &this->mSimObject;
  }
  this->mSimObject.m_pPointer = 0i64;
  v4 = this->mSimObject.mPrev;
  v5 = this->mSimObject.mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  this->mSimObject.mPrev = &this->mSimObject;
  this->mSimObject.mNext = &this->mSimObject;
}

// File Line: 91
// RVA: 0x384C10
void __fastcall UFG::InterestPointUseDetails::Set(
        UFG::InterestPointUseDetails *this,
        UFG::InterestPoint *pInterestPoint,
        UFG::ePOIUseType poiUseType,
        UFG::qSymbol *skipIntoLabel)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *mPrev; // r10
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v6; // rax

  if ( this->mInterestPoint.m_pPointer )
  {
    mPrev = this->mInterestPoint.mPrev;
    mNext = this->mInterestPoint.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mInterestPoint.mPrev = &this->mInterestPoint;
    this->mInterestPoint.mNext = &this->mInterestPoint;
  }
  this->mInterestPoint.m_pPointer = pInterestPoint;
  if ( pInterestPoint )
  {
    v6 = pInterestPoint->UFG::qSafePointerNode<UFG::InterestPoint>::m_SafePointerList.UFG::qSafePointerNode<UFG::InterestPoint>::mNode.UFG::qSafePointerNode<UFG::InterestPoint>::mPrev;
    v6->mNext = &this->mInterestPoint;
    this->mInterestPoint.mPrev = v6;
    this->mInterestPoint.mNext = &pInterestPoint->UFG::qSafePointerNode<UFG::InterestPoint>::m_SafePointerList.UFG::qSafePointerNode<UFG::InterestPoint>::mNode;
    pInterestPoint->UFG::qSafePointerNode<UFG::InterestPoint>::m_SafePointerList.UFG::qSafePointerNode<UFG::InterestPoint>::mNode.UFG::qSafePointerNode<UFG::InterestPoint>::mPrev = &this->mInterestPoint;
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
bool __fastcall UFG::InterestPointUseDetails::operator==(
        UFG::InterestPointUseDetails *this,
        UFG::InterestPointUseDetails *rhs)
{
  return rhs->mInterestPoint.m_pPointer == this->mInterestPoint.m_pPointer
      && this->mPOIUseType == rhs->mPOIUseType
      && this->mSkipIntoLabel.mUID == rhs->mSkipIntoLabel.mUID;
}

// File Line: 114
// RVA: 0x33C210
bool __fastcall UFG::InterestPointUseDetails::operator!=(
        UFG::InterestPointUseDetails *this,
        UFG::InterestPointUseDetails *rhs)
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
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qSymbol *p_mSkipIntoLabel; // rcx

  if ( this->mInterestPoint.m_pPointer )
  {
    mPrev = this->mInterestPoint.mPrev;
    mNext = this->mInterestPoint.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mInterestPoint.mPrev = &this->mInterestPoint;
    this->mInterestPoint.mNext = &this->mInterestPoint;
  }
  p_mSkipIntoLabel = &this->mSkipIntoLabel;
  *(_QWORD *)&p_mSkipIntoLabel[-3].mUID = 0i64;
  p_mSkipIntoLabel[-1].mUID = 0;
  UFG::qSymbol::set_null(p_mSkipIntoLabel);
}

// File Line: 136
// RVA: 0x335290
void __fastcall UFG::ActiveInterestPoint::~ActiveInterestPoint(UFG::ActiveInterestPoint *this)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v4; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v5; // rax

  if ( this->mInterestPoint.m_pPointer )
  {
    mPrev = this->mInterestPoint.mPrev;
    mNext = this->mInterestPoint.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mInterestPoint.mPrev = &this->mInterestPoint;
    this->mInterestPoint.mNext = &this->mInterestPoint;
  }
  this->mInterestPoint.m_pPointer = 0i64;
  v4 = this->mInterestPoint.mPrev;
  v5 = this->mInterestPoint.mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  this->mInterestPoint.mPrev = &this->mInterestPoint;
  this->mInterestPoint.mNext = &this->mInterestPoint;
}

// File Line: 140
// RVA: 0x382930
void __fastcall UFG::ActiveInterestPoint::Reset(UFG::ActiveInterestPoint *this)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qSymbol *p_mSkipIntoLabel; // rcx

  if ( this->mInterestPoint.m_pPointer )
  {
    mPrev = this->mInterestPoint.mPrev;
    mNext = this->mInterestPoint.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mInterestPoint.mPrev = &this->mInterestPoint;
    this->mInterestPoint.mNext = &this->mInterestPoint;
  }
  p_mSkipIntoLabel = &this->mSkipIntoLabel;
  *(_QWORD *)&p_mSkipIntoLabel[-3].mUID = 0i64;
  p_mSkipIntoLabel[-1].mUID = 0;
  UFG::qSymbol::set_null(p_mSkipIntoLabel);
  this->mIsFirstUse = 1;
}

// File Line: 149
// RVA: 0x14AD410
__int64 dynamic_initializer_for__UFG::InterestPointUserComponent::msaPlayersLastNearest__()
{
  `eh vector constructor iterator(
    (char *)UFG::InterestPointUserComponent::msaPlayersLastNearest.p,
    0x18ui64,
    4,
    (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>::qSafePointer<UFG::SimObject,UFG::SimObjectCharacter>);
  UFG::InterestPointUserComponent::msaPlayersLastNearest.size = 0;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::InterestPointUserComponent::msaPlayersLastNearest__);
}

// File Line: 159
// RVA: 0x14AEB80
__int64 dynamic_initializer_for__UFG::InterestPointUserComponent::s_InterestPointUserComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::InterestPointUserComponent::s_InterestPointUserComponentList__);
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
void __fastcall UFG::InterestPointUserComponent::InterestPointUserComponent(
        UFG::InterestPointUserComponent *this,
        unsigned int name_uid)
{
  UFG::qNode<UFG::InterestPointUserComponent,UFG::InterestPointUserComponent> *mPrev; // rax

  UFG::SimComponent::SimComponent(this, name_uid);
  this->mPrev = &this->UFG::qNode<UFG::InterestPointUserComponent,UFG::InterestPointUserComponent>;
  this->mNext = &this->UFG::qNode<UFG::InterestPointUserComponent,UFG::InterestPointUserComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::InterestPointUserComponent::`vftable;
  *((_BYTE *)this + 80) = *((_BYTE *)this + 80) & 0xFC | 1;
  this->mLastInterestPoint.mPrev = &this->mLastInterestPoint;
  this->mLastInterestPoint.mNext = &this->mLastInterestPoint;
  this->mLastInterestPoint.m_pPointer = 0i64;
  UFG::RebindingComponentHandle<UFG::TargetingSystemPedBaseComponent,0>::RebindingComponentHandle<UFG::TargetingSystemPedBaseComponent,0>(&this->mTargetingSystemPedBaseComponent);
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::RebindingComponentHandle<UFG::TransformNodeComponent,0>(&this->mTransformNodeComponent);
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0>::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0>(&this->mActiveAIEntityComponent);
  UFG::RebindingComponentHandle<UFG::AIScriptInterfaceComponent,0>::RebindingComponentHandle<UFG::AIScriptInterfaceComponent,0>(&this->mAIScriptInterfaceComponent);
  UFG::RebindingComponentHandle<UFG::NavComponent,0>::RebindingComponentHandle<UFG::NavComponent,0>(&this->mNavComponent);
  this->mInterestPointQuery.mPrev = &this->mInterestPointQuery.UFG::qNode<UFG::InterestPointQuery,UFG::InterestPointQuery>;
  this->mInterestPointQuery.mNext = &this->mInterestPointQuery.UFG::qNode<UFG::InterestPointQuery,UFG::InterestPointQuery>;
  UFG::qSafePointerNode<UFG::InterestPointQuery>::qSafePointerNode<UFG::InterestPointQuery>(&this->mInterestPointQuery);
  this->mInterestPointQuery.vfptr = (UFG::qSafePointerNode<UFG::InterestPointQuery>Vtbl *)&UFG::InterestPointQuery::`vftable;
  this->mInterestPointQuery.mNavComponent = 0i64;
  this->mInterestPointQuery.mCandidates.p = 0i64;
  *(_QWORD *)&this->mInterestPointQuery.mCandidates.size = 0i64;
  this->mInterestPointQuery.mQueryState = QueryState_None;
  this->mInterestPointQuery.mBestInterestPoint.mPrev = &this->mInterestPointQuery.mBestInterestPoint;
  this->mInterestPointQuery.mBestInterestPoint.mNext = &this->mInterestPointQuery.mBestInterestPoint;
  this->mInterestPointQuery.mBestInterestPoint.m_pPointer = 0i64;
  this->mInterestPointLink.mPOIUseType = ePOIUseType_Script;
  this->mInterestPointLink.mIsExclusive = 0;
  this->mInterestPointLink.mLinkObject.mPrev = &this->mInterestPointLink.mLinkObject;
  this->mInterestPointLink.mLinkObject.mNext = &this->mInterestPointLink.mLinkObject;
  this->mInterestPointLink.mLinkObject.m_pPointer = 0i64;
  this->mRequestedInterestPoint.mInterestPoint.mPrev = &this->mRequestedInterestPoint.mInterestPoint;
  this->mRequestedInterestPoint.mInterestPoint.mNext = &this->mRequestedInterestPoint.mInterestPoint;
  this->mRequestedInterestPoint.mInterestPoint.m_pPointer = 0i64;
  this->mRequestedInterestPoint.mPOIUseType = ePOIUseType_None;
  this->mRequestedInterestPoint.mSkipIntoLabel.mUID = -1;
  this->mActiveInterestPoint.mInterestPoint.mPrev = &this->mActiveInterestPoint.mInterestPoint;
  this->mActiveInterestPoint.mInterestPoint.mNext = &this->mActiveInterestPoint.mInterestPoint;
  this->mActiveInterestPoint.mInterestPoint.m_pPointer = 0i64;
  this->mActiveInterestPoint.mPOIUseType = ePOIUseType_None;
  this->mActiveInterestPoint.mSkipIntoLabel.mUID = -1;
  this->mActiveInterestPoint.mIsFirstUse = 1;
  *(_QWORD *)&this->mLastUsedPOIType.mUID = -1i64;
  this->mFrameCountOfLastPOIUse = 0;
  mPrev = UFG::InterestPointUserComponent::s_InterestPointUserComponentList.mNode.mPrev;
  UFG::InterestPointUserComponent::s_InterestPointUserComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::InterestPointUserComponent,UFG::InterestPointUserComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::InterestPointUserComponent,UFG::InterestPointUserComponent> *)&UFG::InterestPointUserComponent::s_InterestPointUserComponentList;
  UFG::InterestPointUserComponent::s_InterestPointUserComponentList.mNode.mPrev = &this->UFG::qNode<UFG::InterestPointUserComponent,UFG::InterestPointUserComponent>;
  UFG::SimComponent::AddType(
    this,
    UFG::InterestPointUserComponent::_InterestPointUserComponentTypeUID,
    "InterestPointUserComponent");
}

// File Line: 205
// RVA: 0x338A70
void __fastcall UFG::InterestPointUserComponent::~InterestPointUserComponent(UFG::InterestPointUserComponent *this)
{
  UFG::qNode<UFG::InterestPointUserComponent,UFG::InterestPointUserComponent> *v2; // rdi
  UFG::qNode<UFG::InterestPointUserComponent,UFG::InterestPointUserComponent> *mPrev; // rcx
  UFG::qNode<UFG::InterestPointUserComponent,UFG::InterestPointUserComponent> *mNext; // rax
  UFG::ActiveInterestPoint *p_mActiveInterestPoint; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::InterestPointUseDetails *p_mRequestedInterestPoint; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mLinkObject; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qSafePointer<UFG::InterestPoint,UFG::InterestPoint> *p_mLastInterestPoint; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v21; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v22; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v23; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v24; // rax
  UFG::qNode<UFG::InterestPointUserComponent,UFG::InterestPointUserComponent> *v25; // rcx
  UFG::qNode<UFG::InterestPointUserComponent,UFG::InterestPointUserComponent> *v26; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::InterestPointUserComponent::`vftable;
  if ( this == UFG::InterestPointUserComponent::s_InterestPointUserComponentpCurrentIterator )
    UFG::InterestPointUserComponent::s_InterestPointUserComponentpCurrentIterator = (UFG::InterestPointUserComponent *)&this->mPrev[-4];
  v2 = &this->UFG::qNode<UFG::InterestPointUserComponent,UFG::InterestPointUserComponent>;
  mPrev = this->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  p_mActiveInterestPoint = &this->mActiveInterestPoint;
  if ( this->mActiveInterestPoint.mInterestPoint.m_pPointer )
  {
    v6 = p_mActiveInterestPoint->mInterestPoint.mPrev;
    v7 = this->mActiveInterestPoint.mInterestPoint.mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    p_mActiveInterestPoint->mInterestPoint.mPrev = &p_mActiveInterestPoint->mInterestPoint;
    this->mActiveInterestPoint.mInterestPoint.mNext = &this->mActiveInterestPoint.mInterestPoint;
  }
  this->mActiveInterestPoint.mInterestPoint.m_pPointer = 0i64;
  v8 = p_mActiveInterestPoint->mInterestPoint.mPrev;
  v9 = this->mActiveInterestPoint.mInterestPoint.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  p_mActiveInterestPoint->mInterestPoint.mPrev = &p_mActiveInterestPoint->mInterestPoint;
  this->mActiveInterestPoint.mInterestPoint.mNext = &this->mActiveInterestPoint.mInterestPoint;
  p_mRequestedInterestPoint = &this->mRequestedInterestPoint;
  if ( this->mRequestedInterestPoint.mInterestPoint.m_pPointer )
  {
    v11 = p_mRequestedInterestPoint->mInterestPoint.mPrev;
    v12 = this->mRequestedInterestPoint.mInterestPoint.mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    p_mRequestedInterestPoint->mInterestPoint.mPrev = &p_mRequestedInterestPoint->mInterestPoint;
    this->mRequestedInterestPoint.mInterestPoint.mNext = &this->mRequestedInterestPoint.mInterestPoint;
  }
  this->mRequestedInterestPoint.mInterestPoint.m_pPointer = 0i64;
  v13 = p_mRequestedInterestPoint->mInterestPoint.mPrev;
  v14 = this->mRequestedInterestPoint.mInterestPoint.mNext;
  v13->mNext = v14;
  v14->mPrev = v13;
  p_mRequestedInterestPoint->mInterestPoint.mPrev = &p_mRequestedInterestPoint->mInterestPoint;
  this->mRequestedInterestPoint.mInterestPoint.mNext = &this->mRequestedInterestPoint.mInterestPoint;
  p_mLinkObject = &this->mInterestPointLink.mLinkObject;
  if ( this->mInterestPointLink.mLinkObject.m_pPointer )
  {
    v16 = p_mLinkObject->mPrev;
    v17 = this->mInterestPointLink.mLinkObject.mNext;
    v16->mNext = v17;
    v17->mPrev = v16;
    p_mLinkObject->mPrev = p_mLinkObject;
    this->mInterestPointLink.mLinkObject.mNext = &this->mInterestPointLink.mLinkObject;
  }
  this->mInterestPointLink.mLinkObject.m_pPointer = 0i64;
  v18 = p_mLinkObject->mPrev;
  v19 = this->mInterestPointLink.mLinkObject.mNext;
  v18->mNext = v19;
  v19->mPrev = v18;
  p_mLinkObject->mPrev = p_mLinkObject;
  this->mInterestPointLink.mLinkObject.mNext = &this->mInterestPointLink.mLinkObject;
  UFG::InterestPointQuery::~InterestPointQuery(&this->mInterestPointQuery);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->mNavComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->mAIScriptInterfaceComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->mActiveAIEntityComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>(&this->mTransformNodeComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->mTargetingSystemPedBaseComponent);
  p_mLastInterestPoint = &this->mLastInterestPoint;
  if ( this->mLastInterestPoint.m_pPointer )
  {
    v21 = p_mLastInterestPoint->mPrev;
    v22 = this->mLastInterestPoint.mNext;
    v21->mNext = v22;
    v22->mPrev = v21;
    p_mLastInterestPoint->mPrev = p_mLastInterestPoint;
    this->mLastInterestPoint.mNext = &this->mLastInterestPoint;
  }
  this->mLastInterestPoint.m_pPointer = 0i64;
  v23 = p_mLastInterestPoint->mPrev;
  v24 = this->mLastInterestPoint.mNext;
  v23->mNext = v24;
  v24->mPrev = v23;
  p_mLastInterestPoint->mPrev = p_mLastInterestPoint;
  this->mLastInterestPoint.mNext = &this->mLastInterestPoint;
  v25 = v2->mPrev;
  v26 = v2->mNext;
  v25->mNext = v26;
  v26->mPrev = v25;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 216
// RVA: 0x382CF0
void __fastcall UFG::InterestPointUserComponent::Reset(UFG::InterestPointUserComponent *this)
{
  UFG::SimObjectCVBase *m_pSimObject; // rcx
  UFG::SimObjectCharacterPropertiesComponent *v3; // rax
  bool v4; // cl
  UFG::InterestPoint *m_pPointer; // rbx
  UFG::qSafePointer<UFG::InterestPoint,UFG::InterestPoint> *p_mLastInterestPoint; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::InterestPointQuery::Candidate *p; // rcx
  UFG::InterestPoint **p_m_pPointer; // rbx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mLinkObject; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::InterestPointUseDetails *p_mRequestedInterestPoint; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::ActiveInterestPoint *p_mActiveInterestPoint; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v19; // rax

  m_pSimObject = (UFG::SimObjectCVBase *)this->m_pSimObject;
  v4 = m_pSimObject
    && (v3 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(m_pSimObject)) != 0i64
    && v3->m_eGender == eGENDER_FEMALE;
  m_pPointer = this->mLastInterestPoint.m_pPointer;
  if ( m_pPointer )
  {
    if ( this->m_pSimObject == LocalPlayer )
    {
      if ( !v4 )
      {
        UFG::InterestPoint::SetPlayerReference(this->mLastInterestPoint.m_pPointer, 0);
LABEL_12:
        UFG::InterestPoint::UpdateAnimHandles(m_pPointer);
        goto LABEL_13;
      }
    }
    else if ( !v4 )
    {
      UFG::InterestPoint::SetMalePedestrianReference(this->mLastInterestPoint.m_pPointer, 0);
      goto LABEL_12;
    }
    UFG::InterestPoint::SetFemalePedestrianReference(this->mLastInterestPoint.m_pPointer, 0);
    goto LABEL_12;
  }
LABEL_13:
  p_mLastInterestPoint = &this->mLastInterestPoint;
  if ( this->mLastInterestPoint.m_pPointer )
  {
    mPrev = p_mLastInterestPoint->mPrev;
    mNext = this->mLastInterestPoint.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mLastInterestPoint->mPrev = p_mLastInterestPoint;
    this->mLastInterestPoint.mNext = &this->mLastInterestPoint;
  }
  this->mLastInterestPoint.m_pPointer = 0i64;
  UFG::InterestPointQuery::End(&this->mInterestPointQuery, QueryState_None);
  p = this->mInterestPointQuery.mCandidates.p;
  if ( p )
  {
    p_m_pPointer = &p[-1].mInterestPoint.m_pPointer;
    `eh vector destructor iterator(
      p,
      0xF0ui64,
      (int)p[-1].mInterestPoint.m_pPointer,
      (void (__fastcall *)(void *))UFG::InterestPointQuery::Candidate::~Candidate);
    operator delete[](p_m_pPointer);
  }
  p_mLinkObject = &this->mInterestPointLink.mLinkObject;
  this->mInterestPointQuery.mCandidates.p = 0i64;
  *(_QWORD *)&this->mInterestPointQuery.mCandidates.size = 0i64;
  if ( this->mInterestPointLink.mLinkObject.m_pPointer )
  {
    v12 = p_mLinkObject->mPrev;
    v13 = this->mInterestPointLink.mLinkObject.mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    p_mLinkObject->mPrev = p_mLinkObject;
    this->mInterestPointLink.mLinkObject.mNext = &this->mInterestPointLink.mLinkObject;
  }
  this->mInterestPointLink.mLinkObject.m_pPointer = 0i64;
  p_mRequestedInterestPoint = &this->mRequestedInterestPoint;
  this->mInterestPointLink.mPOIUseType = ePOIUseType_Script;
  this->mInterestPointLink.mIsExclusive = 0;
  if ( this->mRequestedInterestPoint.mInterestPoint.m_pPointer )
  {
    v15 = p_mRequestedInterestPoint->mInterestPoint.mPrev;
    v16 = this->mRequestedInterestPoint.mInterestPoint.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    p_mRequestedInterestPoint->mInterestPoint.mPrev = &p_mRequestedInterestPoint->mInterestPoint;
    this->mRequestedInterestPoint.mInterestPoint.mNext = &this->mRequestedInterestPoint.mInterestPoint;
  }
  this->mRequestedInterestPoint.mInterestPoint.m_pPointer = 0i64;
  this->mRequestedInterestPoint.mPOIUseType = ePOIUseType_None;
  UFG::qSymbol::set_null(&this->mRequestedInterestPoint.mSkipIntoLabel);
  p_mActiveInterestPoint = &this->mActiveInterestPoint;
  if ( this->mActiveInterestPoint.mInterestPoint.m_pPointer )
  {
    v18 = p_mActiveInterestPoint->mInterestPoint.mPrev;
    v19 = this->mActiveInterestPoint.mInterestPoint.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    p_mActiveInterestPoint->mInterestPoint.mPrev = &p_mActiveInterestPoint->mInterestPoint;
    this->mActiveInterestPoint.mInterestPoint.mNext = &this->mActiveInterestPoint.mInterestPoint;
  }
  this->mActiveInterestPoint.mInterestPoint.m_pPointer = 0i64;
  this->mActiveInterestPoint.mPOIUseType = ePOIUseType_None;
  UFG::qSymbol::set_null(&this->mActiveInterestPoint.mSkipIntoLabel);
  this->mActiveInterestPoint.mIsFirstUse = 1;
  this->mLastUsedPOIType = UFG::gNullQSymbol;
  this->mLastUsedPOIDesc = UFG::gNullQSymbol;
}

// File Line: 231
// RVA: 0x37F0C0
UFG::InterestPointUserComponent *__fastcall UFG::InterestPointUserComponent::PropertiesOnActivateNew(
        UFG::SceneObjectProperties *pSceneObj,
        bool required)
{
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v4; // rax
  UFG::SimComponent *v5; // rax
  UFG::SimComponent *v6; // rdi
  UFG::SimObject *m_pSimObject; // rdx
  __int16 m_Flags; // cx
  unsigned int v9; // ebx
  UFG::SimObjectModifier v11; // [rsp+38h] [rbp-30h] BYREF

  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v4 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x238ui64, "InterestPointUserComponent", 0i64, 1u);
  if ( v4 )
  {
    UFG::InterestPointUserComponent::InterestPointUserComponent(
      (UFG::InterestPointUserComponent *)v4,
      pSceneObj->m_NameUID);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  m_pSimObject = pSceneObj->m_pSimObject;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    v9 = 43;
  }
  else if ( m_Flags >= 0 && (m_Flags & 0x2000) != 0 )
  {
    v9 = 12;
  }
  else
  {
    v9 = -1;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v11, m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v11, v6, v9);
  UFG::SimObjectModifier::Close(&v11);
  UFG::SimObjectModifier::~SimObjectModifier(&v11);
  return (UFG::InterestPointUserComponent *)v6;
}

// File Line: 240
// RVA: 0x378E80
void __fastcall UFG::InterestPointUserComponent::OnAttach(
        UFG::InterestPointUserComponent *this,
        UFG::SimObject *object)
{
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0> *p_mActiveAIEntityComponent; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rax
  UFG::RebindingComponentHandle<UFG::TargetingSystemPedBaseComponent,0> *p_mTargetingSystemPedBaseComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v12; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rax
  UFG::RebindingComponentHandle<UFG::AIScriptInterfaceComponent,0> *p_mAIScriptInterfaceComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v17; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v18; // rax
  UFG::RebindingComponentHandle<UFG::NavComponent,0> *p_mNavComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v20; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v21; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v22; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v23; // rax
  UFG::NavComponent *m_pSimComponent; // rax
  UFG::SceneObjectProperties *m_pSceneObj; // rax
  UFG::qPropertySet *mpWritableProperties; // rcx
  bool *v27; // rax
  char *v28; // rcx
  char v29; // [rsp+30h] [rbp+8h] BYREF

  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::Bind<UFG::SimObject>(
    &this->mTransformNodeComponent,
    object);
  p_mActiveAIEntityComponent = &this->mActiveAIEntityComponent;
  if ( this->mActiveAIEntityComponent.m_pSimComponent )
  {
    mPrev = p_mActiveAIEntityComponent->mPrev;
    mNext = this->mActiveAIEntityComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mActiveAIEntityComponent.m_pSimComponent = 0i64;
LABEL_7:
    this->mActiveAIEntityComponent.m_pSimObject = 0i64;
    this->mActiveAIEntityComponent.mNext = &this->mActiveAIEntityComponent;
    p_mActiveAIEntityComponent->mPrev = p_mActiveAIEntityComponent;
    goto LABEL_8;
  }
  if ( this->mActiveAIEntityComponent.m_pSimObject
    && (p_mActiveAIEntityComponent->mPrev != p_mActiveAIEntityComponent
     || this->mActiveAIEntityComponent.mNext != &this->mActiveAIEntityComponent) )
  {
    v7 = p_mActiveAIEntityComponent->mPrev;
    v8 = this->mActiveAIEntityComponent.mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    goto LABEL_7;
  }
LABEL_8:
  this->mActiveAIEntityComponent.m_Changed = 1;
  this->mActiveAIEntityComponent.m_pSimObject = object;
  this->mActiveAIEntityComponent.m_TypeUID = UFG::ActiveAIEntityComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0>::BindInternal<UFG::SimObject>(
    p_mActiveAIEntityComponent,
    object);
  p_mTargetingSystemPedBaseComponent = &this->mTargetingSystemPedBaseComponent;
  if ( this->mTargetingSystemPedBaseComponent.m_pSimComponent )
  {
    v10 = p_mTargetingSystemPedBaseComponent->mPrev;
    v11 = this->mTargetingSystemPedBaseComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    this->mTargetingSystemPedBaseComponent.m_pSimComponent = 0i64;
LABEL_14:
    this->mTargetingSystemPedBaseComponent.m_pSimObject = 0i64;
    this->mTargetingSystemPedBaseComponent.mNext = &this->mTargetingSystemPedBaseComponent;
    p_mTargetingSystemPedBaseComponent->mPrev = p_mTargetingSystemPedBaseComponent;
    goto LABEL_15;
  }
  if ( this->mTargetingSystemPedBaseComponent.m_pSimObject
    && (p_mTargetingSystemPedBaseComponent->mPrev != p_mTargetingSystemPedBaseComponent
     || this->mTargetingSystemPedBaseComponent.mNext != &this->mTargetingSystemPedBaseComponent) )
  {
    v12 = p_mTargetingSystemPedBaseComponent->mPrev;
    v13 = this->mTargetingSystemPedBaseComponent.mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    goto LABEL_14;
  }
LABEL_15:
  this->mTargetingSystemPedBaseComponent.m_Changed = 1;
  this->mTargetingSystemPedBaseComponent.m_pSimObject = object;
  this->mTargetingSystemPedBaseComponent.m_TypeUID = UFG::TargetingSystemPedBaseComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::TargetingSystemPedBaseComponent,0>::BindInternal<UFG::SimObject>(
    &this->mTargetingSystemPedBaseComponent,
    object);
  p_mAIScriptInterfaceComponent = &this->mAIScriptInterfaceComponent;
  if ( this->mAIScriptInterfaceComponent.m_pSimComponent )
  {
    v15 = p_mAIScriptInterfaceComponent->mPrev;
    v16 = this->mAIScriptInterfaceComponent.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    this->mAIScriptInterfaceComponent.m_pSimComponent = 0i64;
LABEL_21:
    this->mAIScriptInterfaceComponent.m_pSimObject = 0i64;
    this->mAIScriptInterfaceComponent.mNext = &this->mAIScriptInterfaceComponent;
    p_mAIScriptInterfaceComponent->mPrev = p_mAIScriptInterfaceComponent;
    goto LABEL_22;
  }
  if ( this->mAIScriptInterfaceComponent.m_pSimObject
    && (p_mAIScriptInterfaceComponent->mPrev != p_mAIScriptInterfaceComponent
     || this->mAIScriptInterfaceComponent.mNext != &this->mAIScriptInterfaceComponent) )
  {
    v17 = p_mAIScriptInterfaceComponent->mPrev;
    v18 = this->mAIScriptInterfaceComponent.mNext;
    v17->mNext = v18;
    v18->mPrev = v17;
    goto LABEL_21;
  }
LABEL_22:
  this->mAIScriptInterfaceComponent.m_Changed = 1;
  this->mAIScriptInterfaceComponent.m_pSimObject = object;
  this->mAIScriptInterfaceComponent.m_TypeUID = UFG::AIScriptInterfaceComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::AIScriptInterfaceComponent,0>::BindInternal<UFG::SimObject>(
    &this->mAIScriptInterfaceComponent,
    object);
  p_mNavComponent = &this->mNavComponent;
  if ( this->mNavComponent.m_pSimComponent )
  {
    v20 = p_mNavComponent->mPrev;
    v21 = this->mNavComponent.mNext;
    v20->mNext = v21;
    v21->mPrev = v20;
    this->mNavComponent.m_pSimComponent = 0i64;
LABEL_28:
    this->mNavComponent.m_pSimObject = 0i64;
    this->mNavComponent.mNext = &this->mNavComponent;
    p_mNavComponent->mPrev = p_mNavComponent;
    goto LABEL_29;
  }
  if ( this->mNavComponent.m_pSimObject
    && (p_mNavComponent->mPrev != p_mNavComponent || this->mNavComponent.mNext != &this->mNavComponent) )
  {
    v22 = p_mNavComponent->mPrev;
    v23 = this->mNavComponent.mNext;
    v22->mNext = v23;
    v23->mPrev = v22;
    goto LABEL_28;
  }
LABEL_29:
  this->mNavComponent.m_Changed = 1;
  this->mNavComponent.m_pSimObject = object;
  this->mNavComponent.m_TypeUID = UFG::NavComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::NavComponent,0>::BindInternal<UFG::SimObject>(&this->mNavComponent, object);
  m_pSimComponent = (UFG::NavComponent *)this->mNavComponent.m_pSimComponent;
  v29 = 1;
  this->mInterestPointQuery.mNavComponent = m_pSimComponent;
  m_pSceneObj = object->m_pSceneObj;
  mpWritableProperties = m_pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = m_pSceneObj->mpConstProperties;
  v27 = UFG::qPropertySet::Get<bool>(
          mpWritableProperties,
          (UFG::qArray<unsigned long,0> *)&SimSym_AttractedToPOIs,
          DEPTH_RECURSE);
  v28 = &v29;
  if ( v27 )
    v28 = (char *)v27;
  *((_BYTE *)this + 80) ^= (*((_BYTE *)this + 80) ^ *v28) & 1;
  UFG::InterestPointUserComponent::Reset(this);
});
  v28 = &v29;
  if ( v27 )
    v28 = (char *)v27;
  *

// File Line: 256
// RVA: 0x37AAE0
void __fastcall UFG::InterestPointUserComponent::OnDetach(UFG::InterestPointUserComponent *this)
{
  UFG::SimObject *v2; // rcx
  __int16 m_Flags; // dx
  UFG::InterestPoint *m_pComponent; // rbx
  __int64 v5; // r9
  UFG::SimObjectCVBase *m_pSimObject; // rcx
  UFG::SimObjectCharacterPropertiesComponent *v7; // rax
  bool v8; // cl
  UFG::InterestPoint *m_pPointer; // rbx
  UFG::qSafePointer<UFG::InterestPoint,UFG::InterestPoint> *p_mLastInterestPoint; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::InterestPointQuery::Candidate *p; // rcx
  UFG::InterestPoint **p_m_pPointer; // rbx
  UFG::RebindingComponentHandle<UFG::AIScriptInterfaceComponent,0> *p_mAIScriptInterfaceComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v17; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v18; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v19; // rax
  UFG::RebindingComponentHandle<UFG::TargetingSystemPedBaseComponent,0> *p_mTargetingSystemPedBaseComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v21; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v22; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v23; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v24; // rax
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0> *p_mActiveAIEntityComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v26; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v27; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v28; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v29; // rax
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *p_mTransformNodeComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v31; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v32; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v33; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v34; // rax
  UFG::RebindingComponentHandle<UFG::NavComponent,0> *p_mNavComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v36; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v37; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v38; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v39; // rax

  v2 = *(UFG::SimObject **)(56i64
                          * *(unsigned __int8 *)(*(_QWORD *)&this->mTargetingSystemPedBaseComponent.m_pSimComponent[1].m_Flags
                                               + 34i64)
                          + *(_QWORD *)&this->mTargetingSystemPedBaseComponent.m_pSimComponent[1].m_TypeUID
                          + 40);
  if ( v2 )
  {
    m_Flags = v2->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::InterestPoint *)v2->m_Components.p[25].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
        m_pComponent = (UFG::InterestPoint *)v2->m_Components.p[10].m_pComponent;
      else
        m_pComponent = (UFG::InterestPoint *)((m_Flags & 0x1000) != 0
                                            ? v2->m_Components.p[3].m_pComponent
                                            : UFG::SimObject::GetComponentOfType(v2, UFG::InterestPoint::_TypeUID));
    }
    else
    {
      m_pComponent = (UFG::InterestPoint *)v2->m_Components.p[25].m_pComponent;
    }
    if ( m_pComponent
      && !UFG::InterestPoint::IsReservationMatch(m_pComponent, 8u, ReserveReason_normal)
      && m_pComponent->mpUser.m_pPointer == this->m_pSimObject )
    {
      UFG::InterestPoint::EndReservation(m_pComponent);
      UFG::TargetingSystemBaseComponent::SetTarget(
        (UFG::TargetingSystemBaseComponent *)this->mTargetingSystemPedBaseComponent.m_pSimComponent,
        eTARGET_TYPE_POI_USE,
        0i64);
      LOBYTE(v5) = 1;
      ((void (__fastcall *)(UFG::SimComponent *, __int64, _QWORD, __int64, _DWORD, _QWORD, _QWORD, _QWORD))this->mTargetingSystemPedBaseComponent.m_pSimComponent->vfptr[14].__vecDelDtor)(
        this->mTargetingSystemPedBaseComponent.m_pSimComponent,
        26i64,
        0i64,
        v5,
        0,
        0i64,
        0i64,
        0i64);
    }
  }
  m_pSimObject = (UFG::SimObjectCVBase *)this->m_pSimObject;
  v8 = m_pSimObject
    && (v7 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(m_pSimObject)) != 0i64
    && v7->m_eGender == eGENDER_FEMALE;
  m_pPointer = this->mLastInterestPoint.m_pPointer;
  if ( m_pPointer )
  {
    if ( this->m_pSimObject == LocalPlayer )
    {
      if ( !v8 )
      {
        UFG::InterestPoint::SetPlayerReference(this->mLastInterestPoint.m_pPointer, 0);
LABEL_26:
        UFG::InterestPoint::UpdateAnimHandles(m_pPointer);
        goto LABEL_27;
      }
    }
    else if ( !v8 )
    {
      UFG::InterestPoint::SetMalePedestrianReference(this->mLastInterestPoint.m_pPointer, 0);
      goto LABEL_26;
    }
    UFG::InterestPoint::SetFemalePedestrianReference(this->mLastInterestPoint.m_pPointer, 0);
    goto LABEL_26;
  }
LABEL_27:
  p_mLastInterestPoint = &this->mLastInterestPoint;
  if ( this->mLastInterestPoint.m_pPointer )
  {
    mPrev = p_mLastInterestPoint->mPrev;
    mNext = this->mLastInterestPoint.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mLastInterestPoint->mPrev = p_mLastInterestPoint;
    this->mLastInterestPoint.mNext = &this->mLastInterestPoint;
  }
  this->mLastInterestPoint.m_pPointer = 0i64;
  UFG::InterestPointQuery::End(&this->mInterestPointQuery, QueryState_None);
  p = this->mInterestPointQuery.mCandidates.p;
  if ( p )
  {
    p_m_pPointer = &p[-1].mInterestPoint.m_pPointer;
    `eh vector destructor iterator(
      p,
      0xF0ui64,
      (int)p[-1].mInterestPoint.m_pPointer,
      (void (__fastcall *)(void *))UFG::InterestPointQuery::Candidate::~Candidate);
    operator delete[](p_m_pPointer);
  }
  p_mAIScriptInterfaceComponent = &this->mAIScriptInterfaceComponent;
  this->mInterestPointQuery.mCandidates.p = 0i64;
  *(_QWORD *)&this->mInterestPointQuery.mCandidates.size = 0i64;
  if ( this->mAIScriptInterfaceComponent.m_pSimComponent )
  {
    v16 = p_mAIScriptInterfaceComponent->mPrev;
    v17 = this->mAIScriptInterfaceComponent.mNext;
    v16->mNext = v17;
    v17->mPrev = v16;
    this->mAIScriptInterfaceComponent.m_pSimComponent = 0i64;
LABEL_37:
    this->mAIScriptInterfaceComponent.m_pSimObject = 0i64;
    this->mAIScriptInterfaceComponent.mNext = &this->mAIScriptInterfaceComponent;
    p_mAIScriptInterfaceComponent->mPrev = p_mAIScriptInterfaceComponent;
    goto LABEL_38;
  }
  if ( this->mAIScriptInterfaceComponent.m_pSimObject
    && (p_mAIScriptInterfaceComponent->mPrev != p_mAIScriptInterfaceComponent
     || this->mAIScriptInterfaceComponent.mNext != &this->mAIScriptInterfaceComponent) )
  {
    v18 = p_mAIScriptInterfaceComponent->mPrev;
    v19 = this->mAIScriptInterfaceComponent.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    goto LABEL_37;
  }
LABEL_38:
  this->mAIScriptInterfaceComponent.m_Changed = 1;
  p_mTargetingSystemPedBaseComponent = &this->mTargetingSystemPedBaseComponent;
  if ( this->mTargetingSystemPedBaseComponent.m_pSimComponent )
  {
    v21 = p_mTargetingSystemPedBaseComponent->mPrev;
    v22 = this->mTargetingSystemPedBaseComponent.mNext;
    v21->mNext = v22;
    v22->mPrev = v21;
    this->mTargetingSystemPedBaseComponent.m_pSimComponent = 0i64;
LABEL_44:
    this->mTargetingSystemPedBaseComponent.m_pSimObject = 0i64;
    this->mTargetingSystemPedBaseComponent.mNext = &this->mTargetingSystemPedBaseComponent;
    p_mTargetingSystemPedBaseComponent->mPrev = p_mTargetingSystemPedBaseComponent;
    goto LABEL_45;
  }
  if ( this->mTargetingSystemPedBaseComponent.m_pSimObject
    && (p_mTargetingSystemPedBaseComponent->mPrev != p_mTargetingSystemPedBaseComponent
     || this->mTargetingSystemPedBaseComponent.mNext != &this->mTargetingSystemPedBaseComponent) )
  {
    v23 = p_mTargetingSystemPedBaseComponent->mPrev;
    v24 = this->mTargetingSystemPedBaseComponent.mNext;
    v23->mNext = v24;
    v24->mPrev = v23;
    goto LABEL_44;
  }
LABEL_45:
  this->mTargetingSystemPedBaseComponent.m_Changed = 1;
  p_mActiveAIEntityComponent = &this->mActiveAIEntityComponent;
  if ( this->mActiveAIEntityComponent.m_pSimComponent )
  {
    v26 = p_mActiveAIEntityComponent->mPrev;
    v27 = this->mActiveAIEntityComponent.mNext;
    v26->mNext = v27;
    v27->mPrev = v26;
    this->mActiveAIEntityComponent.m_pSimComponent = 0i64;
LABEL_51:
    this->mActiveAIEntityComponent.m_pSimObject = 0i64;
    this->mActiveAIEntityComponent.mNext = &this->mActiveAIEntityComponent;
    p_mActiveAIEntityComponent->mPrev = p_mActiveAIEntityComponent;
    goto LABEL_52;
  }
  if ( this->mActiveAIEntityComponent.m_pSimObject
    && (p_mActiveAIEntityComponent->mPrev != p_mActiveAIEntityComponent
     || this->mActiveAIEntityComponent.mNext != &this->mActiveAIEntityComponent) )
  {
    v28 = p_mActiveAIEntityComponent->mPrev;
    v29 = this->mActiveAIEntityComponent.mNext;
    v28->mNext = v29;
    v29->mPrev = v28;
    goto LABEL_51;
  }
LABEL_52:
  this->mActiveAIEntityComponent.m_Changed = 1;
  p_mTransformNodeComponent = &this->mTransformNodeComponent;
  if ( this->mTransformNodeComponent.m_pSimComponent )
  {
    v31 = p_mTransformNodeComponent->mPrev;
    v32 = this->mTransformNodeComponent.mNext;
    v31->mNext = v32;
    v32->mPrev = v31;
    this->mTransformNodeComponent.m_pSimComponent = 0i64;
LABEL_58:
    this->mTransformNodeComponent.m_pSimObject = 0i64;
    this->mTransformNodeComponent.mNext = &this->mTransformNodeComponent;
    p_mTransformNodeComponent->mPrev = p_mTransformNodeComponent;
    goto LABEL_59;
  }
  if ( this->mTransformNodeComponent.m_pSimObject
    && (p_mTransformNodeComponent->mPrev != p_mTransformNodeComponent
     || this->mTransformNodeComponent.mNext != &this->mTransformNodeComponent) )
  {
    v33 = p_mTransformNodeComponent->mPrev;
    v34 = this->mTransformNodeComponent.mNext;
    v33->mNext = v34;
    v34->mPrev = v33;
    goto LABEL_58;
  }
LABEL_59:
  this->mTransformNodeComponent.m_Changed = 1;
  p_mNavComponent = &this->mNavComponent;
  if ( this->mNavComponent.m_pSimComponent )
  {
    v36 = p_mNavComponent->mPrev;
    v37 = this->mNavComponent.mNext;
    v36->mNext = v37;
    v37->mPrev = v36;
    this->mNavComponent.m_pSimComponent = 0i64;
LABEL_65:
    this->mNavComponent.m_pSimObject = 0i64;
    this->mNavComponent.mNext = &this->mNavComponent;
    p_mNavComponent->mPrev = p_mNavComponent;
    goto LABEL_66;
  }
  if ( this->mNavComponent.m_pSimObject
    && (p_mNavComponent->mPrev != p_mNavComponent || this->mNavComponent.mNext != &this->mNavComponent) )
  {
    v38 = p_mNavComponent->mPrev;
    v39 = this->mNavComponent.mNext;
    v38->mNext = v39;
    v39->mPrev = v38;
    goto LABEL_65;
  }
LABEL_66:
  this->mNavComponent.m_Changed = 1;
}

// File Line: 357
// RVA: 0x3970B0
void __fastcall UFG::InterestPointUserComponent::UpdateLookAtPOITarget(UFG::InterestPointUserComponent *this)
{
  __int64 v2; // r8
  UFG::TransformNodeComponent *m_pSimComponent; // rbx
  UFG::SimObjectCharacter *m_pSimObject; // rdi
  UFG::InterestPoint *NearestRelevent; // rax
  UFG::SimComponent *v6; // rdi
  unsigned __int8 v7; // cl
  __int64 v8; // rbx

  v2 = *(_QWORD *)&this->mTargetingSystemPedBaseComponent.m_pSimComponent[1].m_TypeUID
     + 56i64
     * *(unsigned __int8 *)(*(_QWORD *)&this->mTargetingSystemPedBaseComponent.m_pSimComponent[1].m_Flags + 33i64);
  if ( !*(_QWORD *)(v2 + 40) || !*(_BYTE *)(v2 + 49) )
  {
    m_pSimComponent = (UFG::TransformNodeComponent *)this->mTransformNodeComponent.m_pSimComponent;
    m_pSimObject = (UFG::SimObjectCharacter *)this->m_pSimObject;
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pSimComponent);
    NearestRelevent = UFG::InterestPoint::FindNearestRelevent(
                        m_pSimObject,
                        0,
                        this,
                        (UFG::TargetingSystemPedBaseComponent *)this->mTargetingSystemPedBaseComponent.m_pSimComponent,
                        (UFG::ActiveAIEntityComponent *)this->mActiveAIEntityComponent.m_pSimComponent,
                        &m_pSimComponent->mWorldTransform,
                        &UFG::InterestPointUserComponent::msPlayerPosition,
                        &qSymbol_look,
                        0xFFFFFFFF,
                        UFG::TargetingSystemPedBaseComponent::ms_TargetingParameters.m_fMaxPOITargetingRange
                      * UFG::TargetingSystemPedBaseComponent::ms_TargetingParameters.m_fMaxPOITargetingRange,
                        0i64,
                        0i64,
                        0i64);
    if ( NearestRelevent )
    {
      UFG::TargetingSystemBaseComponent::SetTarget(
        (UFG::TargetingSystemBaseComponent *)this->mTargetingSystemPedBaseComponent.m_pSimComponent,
        eTARGET_TYPE_POI_LOOK_AT,
        NearestRelevent->m_pSimObject);
    }
    else
    {
      v6 = this->mTargetingSystemPedBaseComponent.m_pSimComponent;
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
void __fastcall UFG::InterestPointUserComponent::UpdateUsePOITarget(
        UFG::InterestPointUserComponent *this,
        bool bIsPlayer,
        UFG::qFixedArray<UFG::InterestPoint *,4> *apClosestPOIWithBehaviour)
{
  UFG::InterestPointQuery *p_mInterestPointQuery; // rsi
  UFG::InterestPointQuery::Candidate *p; // rcx
  UFG::InterestPoint **p_m_pPointer; // rbx
  UFG::TransformNodeComponent *m_pSimComponent; // rbx
  UFG::SimObjectCharacter *m_pSimObject; // r15
  UFG::qMatrix44 *characterTransform; // rbx
  float maxDistSquared; // xmm6_4
  bool IsTraversalsEnabled; // al
  UFG::qArray<UFG::InterestPointQuery::Candidate,0> *pCandidates; // rcx
  UFG::InterestPoint *NearestRelevent; // rax
  UFG::NavComponent *v16; // rdx

  p_mInterestPointQuery = &this->mInterestPointQuery;
  UFG::InterestPointQuery::End(&this->mInterestPointQuery, QueryState_None);
  p = p_mInterestPointQuery->mCandidates.p;
  if ( p )
  {
    p_m_pPointer = &p[-1].mInterestPoint.m_pPointer;
    `eh vector destructor iterator(
      p,
      0xF0ui64,
      (int)p[-1].mInterestPoint.m_pPointer,
      (void (__fastcall *)(void *))UFG::InterestPointQuery::Candidate::~Candidate);
    operator delete[](p_m_pPointer);
  }
  p_mInterestPointQuery->mCandidates.p = 0i64;
  *(_QWORD *)&p_mInterestPointQuery->mCandidates.size = 0i64;
  m_pSimComponent = (UFG::TransformNodeComponent *)this->mTransformNodeComponent.m_pSimComponent;
  m_pSimObject = (UFG::SimObjectCharacter *)this->m_pSimObject;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pSimComponent);
  characterTransform = &m_pSimComponent->mWorldTransform;
  maxDistSquared = UFG::TargetingSystemPedBaseComponent::ms_TargetingParameters.m_fMaxPOITargetingRange
                 * UFG::TargetingSystemPedBaseComponent::ms_TargetingParameters.m_fMaxPOITargetingRange;
  IsTraversalsEnabled = UFG::InterestPoint::IsTraversalsEnabled();
  pCandidates = &this->mInterestPointQuery.mCandidates;
  if ( !IsTraversalsEnabled )
    pCandidates = 0i64;
  NearestRelevent = UFG::InterestPoint::FindNearestRelevent(
                      m_pSimObject,
                      bIsPlayer,
                      this,
                      (UFG::TargetingSystemPedBaseComponent *)this->mTargetingSystemPedBaseComponent.m_pSimComponent,
                      (UFG::ActiveAIEntityComponent *)this->mActiveAIEntityComponent.m_pSimComponent,
                      characterTransform,
                      &UFG::InterestPointUserComponent::msPlayerPosition,
                      &qSymbol_use,
                      8u,
                      maxDistSquared,
                      0i64,
                      pCandidates,
                      apClosestPOIWithBehaviour);
  if ( this->mNavComponent.m_Changed )
  {
    v16 = (UFG::NavComponent *)this->mNavComponent.m_pSimComponent;
    this->mNavComponent.m_Changed = 0;
    this->mInterestPointQuery.mNavComponent = v16;
  }
  UFG::InterestPointQuery::Start(p_mInterestPointQuery, NearestRelevent);
}

// File Line: 451
// RVA: 0x397430
void __fastcall UFG::InterestPointUserComponent::UpdatePOIReferences(
        UFG::InterestPointUserComponent *this,
        UFG::InterestPoint *pNew,
        UFG::InterestPoint *pOld,
        bool bIsPlayer,
        bool bIsFemale)
{
  if ( pNew != pOld )
  {
    if ( !pNew )
      goto LABEL_10;
    if ( bIsPlayer )
    {
      if ( !bIsFemale )
      {
        UFG::InterestPoint::SetPlayerReference(pNew, 1);
LABEL_9:
        UFG::InterestPoint::UpdateAnimHandles(pNew);
LABEL_10:
        if ( !pOld )
          return;
        if ( bIsPlayer )
        {
          if ( !bIsFemale )
          {
            UFG::InterestPoint::SetPlayerReference(pOld, 0);
LABEL_17:
            UFG::InterestPoint::UpdateAnimHandles(pOld);
            return;
          }
        }
        else if ( !bIsFemale )
        {
          UFG::InterestPoint::SetMalePedestrianReference(pOld, 0);
          goto LABEL_17;
        }
        UFG::InterestPoint::SetFemalePedestrianReference(pOld, 0);
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
  UFG::SimObjectCharacter *m_pSimObject; // rbp
  bool v4; // r12
  UFG::SimComponent *m_pSimComponent; // rbx
  float v6; // xmm1_4
  float v7; // xmm2_4
  char v8; // r13
  UFG::SimComponent *v9; // r14
  UFG::SimObject *v10; // rcx
  __int64 v11; // rax
  __int64 v12; // rdx
  bool v13; // r15
  char v14; // si
  __int16 m_Flags; // dx
  UFG::InterestPoint *m_pComponent; // rbx
  UFG::SimObject *v17; // rdx
  UFG::SimComponent *v18; // r14
  unsigned __int8 v19; // cl
  __int64 v20; // rbx
  unsigned __int8 v21; // cl
  __int64 v22; // rbx
  char v23; // r14
  bool v24; // al
  UFG::SimComponent *v25; // rax
  __int16 v26; // cx
  UFG::SimComponent *ComponentOfType; // rax
  char v28; // al
  unsigned int mUID; // r8d
  char v30; // cl
  char v31; // bl
  UFG::InterestPointQuery::QueryState mQueryState; // eax
  UFG::SimObject *v33; // rcx
  UFG::InterestPoint *v34; // rbx
  __int16 v35; // dx
  UFG::SimObjectCVBase *v36; // rcx
  UFG::SimObjectCharacterPropertiesComponent *v37; // rax
  bool bIsFemale; // cl
  UFG::qSafePointer<UFG::InterestPoint,UFG::InterestPoint> *p_mLastInterestPoint; // rdi
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v42; // rax
  __int64 v43; // rbx
  __int64 size; // rbp
  UFG::InterestPoint *v45; // rdi
  __int64 v46; // rsi
  UFG::InterestPoint **p_m_pPointer; // rdi
  UFG::InterestPoint *v48; // rbx
  unsigned int v49; // r8d
  __int64 v50; // r9
  UFG::qSafePointer<UFG::InterestPoint,UFG::InterestPoint> *v51; // rdx
  UFG::InterestPoint *v52; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v53; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v54; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v55; // rax
  UFG::qFixedArray<UFG::InterestPoint *,4> apClosestPOIWithBehaviour; // [rsp+38h] [rbp-50h] BYREF
  unsigned int mSimFrameCount; // [rsp+90h] [rbp+8h]

  mSimFrameCount = UFG::Metrics::msInstance.mSimFrameCount;
  m_pSimObject = (UFG::SimObjectCharacter *)this->m_pSimObject;
  if ( m_pSimObject && m_pSimObject == LocalPlayer )
  {
    v4 = 1;
    m_pSimComponent = this->mTransformNodeComponent.m_pSimComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)m_pSimComponent);
    v6 = *((float *)&m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev + 1);
    v7 = *(float *)&m_pSimComponent[2].m_BoundComponentHandles.mNode.mNext;
    UFG::InterestPointUserComponent::msPlayerPosition.x = *(float *)&m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev;
    UFG::InterestPointUserComponent::msPlayerPosition.y = v6;
    UFG::InterestPointUserComponent::msPlayerPosition.z = v7;
  }
  else
  {
    v4 = 0;
  }
  v8 = 0;
  v9 = this->mTargetingSystemPedBaseComponent.m_pSimComponent;
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
    m_Flags = v10->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::InterestPoint *)v10->m_Components.p[25].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = (UFG::InterestPoint *)v10->m_Components.p[10].m_pComponent;
      }
      else if ( (m_Flags & 0x1000) != 0 )
      {
        m_pComponent = (UFG::InterestPoint *)v10->m_Components.p[3].m_pComponent;
      }
      else
      {
        m_pComponent = (UFG::InterestPoint *)UFG::SimObject::GetComponentOfType(v10, UFG::InterestPoint::_TypeUID);
      }
    }
    else
    {
      m_pComponent = (UFG::InterestPoint *)v10->m_Components.p[25].m_pComponent;
    }
    if ( m_pComponent )
    {
      if ( !UFG::InterestPoint::IsReservationMatch(m_pComponent, 8u, ReserveReason_normal) )
      {
        v17 = this->m_pSimObject;
        if ( m_pComponent->mpUser.m_pPointer != v17 )
        {
          if ( v13 )
            UFG::InterestPoint::ForceUser(m_pComponent, v17);
          else
            v8 = 0;
        }
      }
      goto LABEL_30;
    }
    v8 = 0;
    v18 = this->mTargetingSystemPedBaseComponent.m_pSimComponent;
    v19 = *(_BYTE *)(*(_QWORD *)&v18[1].m_Flags + 34i64);
    if ( v19 )
    {
      v20 = 56i64 * v19;
      UFG::TargetingSimObject::SetTarget((UFG::TargetingSimObject *)(v20 + *(_QWORD *)&v18[1].m_TypeUID), 0i64);
      UFG::TargetingSimObject::SetLock((UFG::TargetingSimObject *)(v20 + *(_QWORD *)&v18[1].m_TypeUID), 0);
    }
    v9 = this->mTargetingSystemPedBaseComponent.m_pSimComponent;
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
  if ( (*((_BYTE *)this + 80) & 1) != 0 )
  {
    if ( v4 )
    {
      if ( v8 && v13 )
        goto LABEL_54;
    }
    else if ( v8 )
    {
      goto LABEL_54;
    }
    v25 = this->mAIScriptInterfaceComponent.m_pSimComponent;
    if ( !v25 || !HIDWORD(v25[1].m_SafePointerList.mNode.mNext) )
    {
      if ( m_pSimObject
        && ((v26 = m_pSimObject->m_Flags, (v26 & 0x4000) == 0)
          ? (v26 >= 0 && (v26 & 0x2000) == 0 && (v26 & 0x1000) == 0
           ? (ComponentOfType = UFG::SimObject::GetComponentOfType(
                                  m_pSimObject,
                                  UFG::CharacterOccupantComponent::_TypeUID))
           : (ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(
                                  m_pSimObject,
                                  UFG::CharacterOccupantComponent::_TypeUID)))
          : (ComponentOfType = m_pSimObject->m_Components.p[44].m_pComponent),
            ComponentOfType) )
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
LABEL_54:
  mUID = m_pSimObject->mNode.mUID;
  if ( UFG::InterestPointUserComponent::msPlayerInVehicle
    || (*((_BYTE *)this + 80) & 2) == 0
    && !v4
    && (mUID + mSimFrameCount) % UFG::InterestPointUserComponent::msInterestPointUseTargetUpdateFrequency_NPC )
  {
    v30 = 0;
    if ( UFG::InterestPointUserComponent::msPlayerInVehicle )
      goto LABEL_63;
  }
  else
  {
    v30 = 1;
  }
  if ( !v4
    && !((mUID + mSimFrameCount) % UFG::InterestPointUserComponent::msInterestPointLookAtTargetUpdateFrequency_NPC) )
  {
    v31 = 1;
    goto LABEL_64;
  }
LABEL_63:
  v31 = 0;
LABEL_64:
  apClosestPOIWithBehaviour.size = 0;
  if ( v23 )
  {
    *((_BYTE *)this + 80) &= ~2u;
    if ( this->mInterestPointQuery.mQueryState != QueryState_InProgress && v30 )
      UFG::InterestPointUserComponent::UpdateUsePOITarget(this, v4, &apClosestPOIWithBehaviour);
    if ( v31 )
      UFG::InterestPointUserComponent::UpdateLookAtPOITarget(this);
    if ( this->mInterestPointQuery.mQueryState == QueryState_InProgress )
      UFG::InterestPointQuery::Update(&this->mInterestPointQuery);
    mQueryState = this->mInterestPointQuery.mQueryState;
    if ( mQueryState )
    {
      if ( mQueryState == QueryState_Succeeded )
      {
        UFG::TargetingSystemBaseComponent::SetTarget(
          (UFG::TargetingSystemBaseComponent *)this->mTargetingSystemPedBaseComponent.m_pSimComponent,
          eTARGET_TYPE_POI_USE,
          this->mInterestPointQuery.mBestInterestPoint.m_pPointer->m_pSimObject);
        UFG::InterestPointQuery::End(&this->mInterestPointQuery, QueryState_None);
      }
      else if ( mQueryState == QueryState_Failed )
      {
        UFG::TargetingSystemBaseComponent::ClearTarget(
          (UFG::TargetingSystemBaseComponent *)this->mTargetingSystemPedBaseComponent.m_pSimComponent,
          eTARGET_TYPE_POI_USE);
        UFG::InterestPointQuery::End(&this->mInterestPointQuery, QueryState_None);
      }
    }
  }
  else
  {
    if ( !v8 || !v30 )
      v14 = 0;
    *((_BYTE *)this + 80) ^= (*((_BYTE *)this + 80) ^ (*((_BYTE *)this + 80) | (2 * v14))) & 2;
  }
  v33 = *(UFG::SimObject **)(56i64
                           * *(unsigned __int8 *)(*(_QWORD *)&this->mTargetingSystemPedBaseComponent.m_pSimComponent[1].m_Flags
                                                + 34i64)
                           + *(_QWORD *)&this->mTargetingSystemPedBaseComponent.m_pSimComponent[1].m_TypeUID
                           + 40);
  if ( v33 )
  {
    v35 = v33->m_Flags;
    if ( (v35 & 0x4000) != 0 )
    {
      v34 = (UFG::InterestPoint *)v33->m_Components.p[25].m_pComponent;
    }
    else if ( v35 >= 0 )
    {
      if ( (v35 & 0x2000) != 0 )
      {
        v34 = (UFG::InterestPoint *)v33->m_Components.p[10].m_pComponent;
      }
      else if ( (v35 & 0x1000) != 0 )
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
  v36 = (UFG::SimObjectCVBase *)this->m_pSimObject;
  bIsFemale = v36
           && (v37 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v36)) != 0i64
           && v37->m_eGender == eGENDER_FEMALE;
  UFG::InterestPointUserComponent::UpdatePOIReferences(
    this,
    v34,
    this->mLastInterestPoint.m_pPointer,
    this->m_pSimObject == LocalPlayer,
    bIsFemale);
  p_mLastInterestPoint = &this->mLastInterestPoint;
  if ( p_mLastInterestPoint->m_pPointer )
  {
    mPrev = p_mLastInterestPoint->mPrev;
    mNext = p_mLastInterestPoint->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mLastInterestPoint->mPrev = p_mLastInterestPoint;
    p_mLastInterestPoint->mNext = p_mLastInterestPoint;
  }
  p_mLastInterestPoint->m_pPointer = v34;
  if ( v34 )
  {
    v42 = v34->UFG::qSafePointerNode<UFG::InterestPoint>::m_SafePointerList.UFG::qSafePointerNode<UFG::InterestPoint>::mNode.UFG::qSafePointerNode<UFG::InterestPoint>::mPrev;
    v42->mNext = p_mLastInterestPoint;
    p_mLastInterestPoint->mPrev = v42;
    p_mLastInterestPoint->mNext = &v34->UFG::qSafePointerNode<UFG::InterestPoint>::m_SafePointerList.UFG::qSafePointerNode<UFG::InterestPoint>::mNode;
    v34->UFG::qSafePointerNode<UFG::InterestPoint>::m_SafePointerList.UFG::qSafePointerNode<UFG::InterestPoint>::mNode.UFG::qSafePointerNode<UFG::InterestPoint>::mPrev = p_mLastInterestPoint;
  }
  if ( v4 )
  {
    v43 = 0i64;
    size = apClosestPOIWithBehaviour.size;
    if ( apClosestPOIWithBehaviour.size )
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
      while ( v43 < size );
    }
    v46 = UFG::InterestPointUserComponent::msaPlayersLastNearest.size;
    if ( UFG::InterestPointUserComponent::msaPlayersLastNearest.size )
    {
      p_m_pPointer = &UFG::InterestPointUserComponent::msaPlayersLastNearest.p[0].m_pPointer;
      do
      {
        v48 = *p_m_pPointer;
        if ( *p_m_pPointer )
        {
          UFG::InterestPoint::SetPlayerReference(*p_m_pPointer, 0);
          UFG::InterestPoint::UpdateAnimHandles(v48);
        }
        p_m_pPointer += 3;
        --v46;
      }
      while ( v46 );
    }
    v49 = 0;
    UFG::InterestPointUserComponent::msaPlayersLastNearest.size = 0;
    v50 = 0i64;
    if ( size > 0 )
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
          v51->mPrev = v51;
          v51->mNext = v51;
        }
        v51->m_pPointer = v52;
        if ( v52 )
        {
          v55 = v52->UFG::qSafePointerNode<UFG::InterestPoint>::m_SafePointerList.UFG::qSafePointerNode<UFG::InterestPoint>::mNode.UFG::qSafePointerNode<UFG::InterestPoint>::mPrev;
          v55->mNext = v51;
          v51->mPrev = v55;
          v51->mNext = &v52->UFG::qSafePointerNode<UFG::InterestPoint>::m_SafePointerList.UFG::qSafePointerNode<UFG::InterestPoint>::mNode;
          v52->UFG::qSafePointerNode<UFG::InterestPoint>::m_SafePointerList.UFG::qSafePointerNode<UFG::InterestPoint>::mNode.UFG::qSafePointerNode<UFG::InterestPoint>::mPrev = v51;
        }
        if ( ++v50 >= size )
          break;
        v49 = UFG::InterestPointUserComponent::msaPlayersLastNearest.size;
      }
    }
  }
}

// File Line: 678
// RVA: 0x3992B0
void __fastcall UFG::InterestPointUserComponent::UsePOI(
        UFG::InterestPointUserComponent *this,
        UFG::InterestPoint *pInterestPoint,
        UFG::ePOIUseType poiUseType,
        UFG::qSymbol *skipIntoLabel)
{
  UFG::InterestPointUseDetails *p_mRequestedInterestPoint; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *v9; // rax
  unsigned int mUID; // ecx
  UFG::SimObjectCVBase *m_pSimObject; // rsi
  UFG::SimObjectCharacter *v12; // rbx
  UFG::InterestPoint *m_pPointer; // rdi
  bool bIsFemale; // al

  if ( pInterestPoint && this->mTargetingSystemPedBaseComponent.m_pSimComponent )
  {
    p_mRequestedInterestPoint = &this->mRequestedInterestPoint;
    if ( this->mRequestedInterestPoint.mInterestPoint.m_pPointer )
    {
      mPrev = p_mRequestedInterestPoint->mInterestPoint.mPrev;
      mNext = p_mRequestedInterestPoint->mInterestPoint.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_mRequestedInterestPoint->mInterestPoint.mPrev = &p_mRequestedInterestPoint->mInterestPoint;
      p_mRequestedInterestPoint->mInterestPoint.mNext = &p_mRequestedInterestPoint->mInterestPoint;
    }
    p_mRequestedInterestPoint->mInterestPoint.m_pPointer = pInterestPoint;
    v9 = pInterestPoint->UFG::qSafePointerNode<UFG::InterestPoint>::m_SafePointerList.UFG::qSafePointerNode<UFG::InterestPoint>::mNode.UFG::qSafePointerNode<UFG::InterestPoint>::mPrev;
    v9->mNext = &p_mRequestedInterestPoint->mInterestPoint;
    p_mRequestedInterestPoint->mInterestPoint.mPrev = v9;
    p_mRequestedInterestPoint->mInterestPoint.mNext = &pInterestPoint->UFG::qSafePointerNode<UFG::InterestPoint>::m_SafePointerList.UFG::qSafePointerNode<UFG::InterestPoint>::mNode;
    pInterestPoint->UFG::qSafePointerNode<UFG::InterestPoint>::m_SafePointerList.UFG::qSafePointerNode<UFG::InterestPoint>::mNode.UFG::qSafePointerNode<UFG::InterestPoint>::mPrev = &p_mRequestedInterestPoint->mInterestPoint;
    p_mRequestedInterestPoint->mPOIUseType = poiUseType;
    mUID = skipIntoLabel->mUID;
    p_mRequestedInterestPoint->mSkipIntoLabel = (UFG::qSymbol)skipIntoLabel->mUID;
    if ( this->mActiveInterestPoint.mInterestPoint.m_pPointer != p_mRequestedInterestPoint->mInterestPoint.m_pPointer
      || poiUseType != this->mActiveInterestPoint.mPOIUseType
      || mUID != this->mActiveInterestPoint.mSkipIntoLabel.mUID )
    {
      if ( UFG::InterestPoint::ForceUser(pInterestPoint, this->m_pSimObject) )
      {
        UFG::TargetingSystemBaseComponent::SetTarget(
          (UFG::TargetingSystemBaseComponent *)this->mTargetingSystemPedBaseComponent.m_pSimComponent,
          eTARGET_TYPE_POI_USE,
          pInterestPoint->m_pSimObject);
        m_pSimObject = (UFG::SimObjectCVBase *)this->m_pSimObject;
        v12 = LocalPlayer;
        m_pPointer = this->mLastInterestPoint.m_pPointer;
        bIsFemale = UFG::IsFemale(m_pSimObject);
        UFG::InterestPointUserComponent::UpdatePOIReferences(
          this,
          pInterestPoint,
          m_pPointer,
          m_pSimObject == v12,
          bIsFemale);
        UFG::qSafePointer<UFG::InterestPoint,UFG::InterestPoint>::operator=(&this->mLastInterestPoint, pInterestPoint);
        this->mFrameCountOfLastPOIUse = UFG::Metrics::msInstance.mSimFrameCount;
      }
      else
      {
        UFG::InterestPointUseDetails::Reset(p_mRequestedInterestPoint);
      }
    }
  }
}

// File Line: 717
// RVA: 0x3892D0
void __fastcall UFG::InterestPointUserComponent::StopPOI(
        UFG::InterestPointUserComponent *this,
        __int64 a2,
        __int64 a3,
        __int64 a4)
{
  UFG::SimComponent *m_pSimComponent; // rcx
  UFG::InterestPointUseDetails *p_mRequestedInterestPoint; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::InterestPoint>,UFG::qSafePointerNodeList> *mNext; // rax

  m_pSimComponent = this->mTargetingSystemPedBaseComponent.m_pSimComponent;
  if ( m_pSimComponent )
  {
    LOBYTE(a4) = 1;
    ((void (__fastcall *)(UFG::SimComponent *, __int64, _QWORD, __int64, _DWORD, const char *, _QWORD, _QWORD))m_pSimComponent->vfptr[14].__vecDelDtor)(
      m_pSimComponent,
      26i64,
      0i64,
      a4,
      0,
      "InterestPointUserComponent::StopPOI",
      0i64,
      0i64);
  }
  p_mRequestedInterestPoint = &this->mRequestedInterestPoint;
  if ( this->mRequestedInterestPoint.mInterestPoint.m_pPointer )
  {
    mPrev = p_mRequestedInterestPoint->mInterestPoint.mPrev;
    mNext = this->mRequestedInterestPoint.mInterestPoint.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mRequestedInterestPoint->mInterestPoint.mPrev = &p_mRequestedInterestPoint->mInterestPoint;
    this->mRequestedInterestPoint.mInterestPoint.mNext = &this->mRequestedInterestPoint.mInterestPoint;
  }
  this->mRequestedInterestPoint.mInterestPoint.m_pPointer = 0i64;
  this->mRequestedInterestPoint.mPOIUseType = ePOIUseType_None;
  UFG::qSymbol::set_null(&this->mRequestedInterestPoint.mSkipIntoLabel);
}

// File Line: 733
// RVA: 0x3871F0
void __fastcall UFG::InterestPointUserComponent::SetLinkObject(
        UFG::InterestPointUserComponent *this,
        UFG::SimObject *pSimObjLinker,
        UFG::ePOIUseType poiUseType,
        bool exclusive)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mLinkObject; // r11
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // r10
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rax

  p_mLinkObject = &this->mInterestPointLink.mLinkObject;
  if ( this->mInterestPointLink.mLinkObject.m_pPointer )
  {
    mPrev = p_mLinkObject->mPrev;
    mNext = this->mInterestPointLink.mLinkObject.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mLinkObject->mPrev = p_mLinkObject;
    this->mInterestPointLink.mLinkObject.mNext = &this->mInterestPointLink.mLinkObject;
  }
  this->mInterestPointLink.mLinkObject.m_pPointer = pSimObjLinker;
  if ( pSimObjLinker )
  {
    v7 = pSimObjLinker->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    v7->mNext = p_mLinkObject;
    p_mLinkObject->mPrev = v7;
    this->mInterestPointLink.mLinkObject.mNext = &pSimObjLinker->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
    pSimObjLinker->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_mLinkObject;
  }
  this->mInterestPointLink.mPOIUseType = poiUseType;
  this->mInterestPointLink.mIsExclusive = exclusive;
}

