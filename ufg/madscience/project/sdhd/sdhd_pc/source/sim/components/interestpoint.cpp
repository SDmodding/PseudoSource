// File Line: 90
// RVA: 0x582330
signed __int64 __fastcall `anonymous namespace::GetActionMostUsedIndex_Interactions()
{
  signed __int64 result; // rax

  if ( _S10_11 & 1 )
    return index_2;
  _S10_11 |= 1u;
  if ( !(_S9_16 & 1) )
  {
    _S9_16 |= 1u;
    node_id.mUID = UFG::qStringHashUpper32("Interactions", 0xFFFFFFFF);
  }
  result = GetMostUsedIndex(node_id.mUID);
  index_2 = result;
  return result;
}

// File Line: 105
// RVA: 0x154D5E0
__int64 dynamic_initializer_for__UFG::InterestPoint::_TypeIDesc__()
{
  UFG::ComponentIDDesc *v0; // rax
  __int64 result; // rax

  v0 = UFG::InterestPoint::AccessComponentDesc();
  *(_DWORD *)&UFG::InterestPoint::_TypeIDesc.mBaseTypeIndex = *(_DWORD *)&v0->mBaseTypeIndex;
  UFG::InterestPoint::_TypeIDesc.mChildBitMask = v0->mChildBitMask;
  result = v0->mChildren;
  UFG::InterestPoint::_TypeIDesc.mChildren = result;
  return result;
}

// File Line: 127
// RVA: 0x154D850
__int64 dynamic_initializer_for__UFG::InterestPoint::msLastUsedType__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::InterestPoint::msLastUsedType__);
}

// File Line: 128
// RVA: 0x154D910
__int64 dynamic_initializer_for__UFG::InterestPoint::mspCharacterToShowPOIsFor__()
{
  UFG::InterestPoint::mspCharacterToShowPOIsFor.m_pPointer = 0i64;
  return atexit(dynamic_atexit_destructor_for__UFG::InterestPoint::mspCharacterToShowPOIsFor__);
}

// File Line: 130
// RVA: 0x154D860
__int64 dynamic_initializer_for__UFG::InterestPoint::msLookInterestPoints__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::InterestPoint::msLookInterestPoints.mTree);
  return atexit(dynamic_atexit_destructor_for__UFG::InterestPoint::msLookInterestPoints__);
}

// File Line: 131
// RVA: 0x154D8E0
__int64 dynamic_initializer_for__UFG::InterestPoint::msUseInterestPoints__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::InterestPoint::msUseInterestPoints.mTree);
  return atexit(dynamic_atexit_destructor_for__UFG::InterestPoint::msUseInterestPoints__);
}

// File Line: 133
// RVA: 0x154D7A0
__int64 dynamic_initializer_for__UFG::InterestPoint::msCellNotLoadedCanPathList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::InterestPoint::msCellNotLoadedCanPathList__);
}

// File Line: 138
// RVA: 0x154D760
__int64 dynamic_initializer_for__UFG::InterestPoint::msAIHintColour__()
{
  UFG::InterestPoint::msAIHintColour = UFG::qColour::DarkViolet;
  return LODWORD(UFG::qColour::DarkViolet.a);
}

// File Line: 140
// RVA: 0x154D7C0
__int64 dynamic_initializer_for__UFG::InterestPoint::msInterestPointTypePool__()
{
  `eh vector constructor iterator(
    UFG::InterestPoint::msInterestPointTypePool.p,
    0xA8ui64,
    500,
    (void (__fastcall *)(void *))UFG::InterestPointType::InterestPointType);
  UFG::InterestPoint::msInterestPointTypePool.size = 0;
  return atexit(dynamic_atexit_destructor_for__UFG::InterestPoint::msInterestPointTypePool__);
}

// File Line: 141
// RVA: 0x154D820
__int64 dynamic_initializer_for__UFG::InterestPoint::msInterestPointTypeTree__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::InterestPoint::msInterestPointTypeTree.mTree);
  return atexit(dynamic_atexit_destructor_for__UFG::InterestPoint::msInterestPointTypeTree__);
}

// File Line: 277
// RVA: 0x57CC70
void __fastcall UFG::InterestPointProperties::InterestPointProperties(UFG::InterestPointProperties *this)
{
  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->mPriority = 0;
  this->mStartActive = 0;
  *(_QWORD *)&this->mAppeal = 0i64;
  this->mMinAppealRadius = 0.0;
  this->mGendersAllowed.mUID = -1;
  *(_QWORD *)&this->mTimeOfDayToBecomeActive = 0i64;
  this->mClassListIsAllowed = 0;
  this->mUseClassList.p = 0i64;
  *(_QWORD *)&this->mUseClassList.size = 0i64;
  this->mBoneName = UFG::gNullQSymbolUC;
  *(_DWORD *)&this->mItemFilterOn = 65792;
  *(_DWORD *)&this->mWeatherFilterIsRaining = 0x10000;
  *(_WORD *)&this->mInitialUseOnly = 0;
  this->mIgnoreCharacterCooldown = 0;
  this->mUserRelativeAngleRange = 6.2831855;
  this->mPercentChanceIsActive = 100.0;
  *(_DWORD *)&this->mRequiresSync = 16843009;
  this->mIsAutoInteractable = 0;
  *(_QWORD *)&this->mUseTimeMin = 0i64;
  *(_QWORD *)&this->mCoolDownTimeMin = 0i64;
  *(_QWORD *)&this->mMinGroupSize = -1i64;
  this->mMaxDistanceFromPlayer = -1.0;
  *(_WORD *)&this->mIsSittingConversation = 0;
}

// File Line: 286
// RVA: 0x582860
UFG::qVector3 *__fastcall UFG::InterestPoint::GetPosition(UFG::InterestPoint *this)
{
  UFG::InterestPoint *v1; // rdi
  UFG::TransformNodeComponent *v2; // rbx
  float v3; // xmm0_4
  float v4; // xmm1_4
  UFG::qVector3 *result; // rax

  v1 = this;
  if ( this->mIsPositionCached )
    return &this->mCachedPosition;
  v2 = this->mpXformNode;
  UFG::TransformNodeComponent::UpdateWorldTransform(this->mpXformNode);
  v3 = v2->mWorldTransform.v3.y;
  v4 = v2->mWorldTransform.v3.z;
  v1->mCachedPosition.x = v2->mWorldTransform.v3.x;
  result = &v1->mCachedPosition;
  v1->mCachedPosition.y = v3;
  v1->mCachedPosition.z = v4;
  v1->mIsPositionCached = 1;
  return result;
}

// File Line: 297
// RVA: 0x5856B0
void __fastcall UFG::InterestPointProperties::Load(UFG::InterestPointProperties *this, UFG::qPropertySet *pProps, component_InterestPoint *interest_point_data)
{
  UFG::qPropertySet *v3; // rsi
  component_InterestPoint *v4; // rdi
  UFG::InterestPointProperties *v5; // rbp
  UFG::qPropertySet *v6; // rax
  schema_classlist *v7; // rbx

  v3 = pProps;
  v4 = interest_point_data;
  v5 = this;
  v6 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         pProps,
         (UFG::qSymbol *)&schema_classlist::sPropertyName.mUID,
         DEPTH_RECURSE);
  if ( v6 )
    v7 = (schema_classlist *)UFG::qPropertySet::GetMemImagePtr(v6);
  else
    v7 = 0i64;
  UFG::InterestPointProperties::LoadCommonProperties(v5, v3, v4, v7);
  if ( v4->InterestPointType.mUID != qSymbol_look.mUID )
    UFG::InterestPointProperties::LoadUseProperties(v5, v3, v4, v7);
}

// File Line: 311
// RVA: 0x5858B0
void __fastcall UFG::InterestPointProperties::LoadCommonProperties(UFG::InterestPointProperties *this, UFG::qPropertySet *pProps, component_InterestPoint *interest_point_data, schema_classlist *class_list_data)
{
  schema_classlist *v4; // r15
  component_InterestPoint *v5; // r14
  UFG::InterestPointProperties *v6; // rbp
  UFG::qArray<UFG::qSymbol,0> *v7; // rdi
  UFG::qSymbol *v8; // rcx
  UFG::qSymbol *v9; // rbx
  unsigned int v10; // esi
  __int64 v11; // rax
  unsigned int v12; // er12
  UFG::qPropertyList *v13; // r14
  UFG::qSymbol *v14; // r13
  __int64 v15; // r15
  unsigned int v16; // ebx
  unsigned int v17; // edx
  unsigned int v18; // edx
  __int64 v19; // [rsp+30h] [rbp-58h]
  __int64 v20; // [rsp+38h] [rbp-50h]
  UFG::qPropertyList **v21; // [rsp+40h] [rbp-48h]
  UFG::InterestPointProperties *v22; // [rsp+90h] [rbp+8h]
  component_InterestPoint *v23; // [rsp+A0h] [rbp+18h]
  UFG::qPropertyList *v24; // [rsp+A8h] [rbp+20h]

  v23 = interest_point_data;
  v22 = this;
  v20 = -2i64;
  v4 = class_list_data;
  v5 = interest_point_data;
  v6 = this;
  this->mStartActive = interest_point_data->StartActive;
  this->mAppeal = interest_point_data->Appeal;
  this->mMinAppealRadius = interest_point_data->MinAppealRadius;
  this->mMaxAppealRadius = interest_point_data->MaxAppealRadius;
  this->mGendersAllowed.mUID = interest_point_data->GenderAllowed.mUID;
  this->mTimeOfDayToBecomeActive = interest_point_data->TimeOfDayToBecomeActiveInHours;
  this->mTimeOfDayToBecomeInactive = interest_point_data->TimeOfDayToBecomeInactiveInHours;
  v21 = &v24;
  LODWORD(v24) = UFG::gNullQSymbolUC;
  this->mBoneName = (UFG::qSymbolUC)PropertyUtils::GetWithDefault<UFG::qSymbolUC>(
                                      (UFG::qSymbolUC *)&v19,
                                      pProps,
                                      (UFG::qSymbol *)&qSymbol_InterestPointParentBone.mUID,
                                      (__int64)&v24,
                                      DEPTH_RECURSE)->mUID;
  v6->mClassListIsAllowed = 0;
  v7 = &v6->mUseClassList;
  v8 = v6->mUseClassList.p;
  if ( v8 )
  {
    v9 = v8 - 1;
    `eh vector destructor iterator(v8, 4ui64, v8[-1].mUID, (void (__fastcall *)(void *))_);
    operator delete[](v9);
  }
  v10 = 0;
  v6->mUseClassList.p = 0i64;
  *(_QWORD *)&v7->size = 0i64;
  if ( v4 )
  {
    v6->mClassListIsAllowed = v4->ClassTypeIsAllowable;
    v11 = v4->ClassTypeList.mOffset;
    if ( v11 )
    {
      v24 = (UFG::qPropertyList *)((char *)&v4->ClassTypeList + v11);
      if ( (UFG::qOffset64<UFG::qPropertyList *> *)((char *)&v4->ClassTypeList + v11) )
      {
        v12 = *(_DWORD *)(&v4[3].ClassTypeIsAllowable + v11);
        if ( v12 > v6->mUseClassList.capacity )
          UFG::qArray<UFG::qSymbol,0>::Reallocate(&v6->mUseClassList, v12, "mUseClassList Reserve");
        if ( v12 )
        {
          v13 = v24;
          do
          {
            v14 = UFG::qPropertyList::Get<UFG::qSymbol>(v13, v10);
            v15 = v7->size;
            v16 = v15 + 1;
            v17 = v6->mUseClassList.capacity;
            if ( (signed int)v15 + 1 > v17 )
            {
              if ( v17 )
                v18 = 2 * v17;
              else
                v18 = 1;
              for ( ; v18 < v16; v18 *= 2 )
                ;
              if ( v18 <= 4 )
                v18 = 4;
              if ( v18 - v16 > 0x10000 )
                v18 = v15 + 65537;
              UFG::qArray<UFG::qSymbol,0>::Reallocate(v7, v18, "mUseClassList");
            }
            v7->size = v16;
            v6->mUseClassList.p[v15] = (UFG::qSymbol)v14->mUID;
            ++v10;
          }
          while ( v10 < v12 );
          v6 = v22;
          v5 = v23;
        }
      }
    }
  }
  v6->mItemFilterOn = v5->ItemFilterOn;
  v6->mWeatherFilterOn = v5->WeatherFilterOn;
  v6->mWeatherFilterIsRaining = v5->WeatherFilterIsRaining;
  v6->mAllowRepeatedUse = v5->AllowRepeatedUse;
  v6->mAllowLeaders = v5->AllowLeaders;
  v6->mAllowFollowers = v5->AllowFollowers;
  v6->mInitialUseOnly = v5->InitialUseOnly;
  v6->mResumeIfInterrupted = v5->ResumeIfInterrupted;
  v6->mIgnoreCharacterCooldown = v5->IgnoreCharacterCooldown;
  v6->mUserRelativeAngleRange = (float)(v5->UserRelativeAngleRange * 3.1415927) * 0.0055555557;
  v6->mPercentChanceIsActive = v5->ChanceIsActive * 100.0;
}

// File Line: 373
// RVA: 0x585E70
void __fastcall UFG::InterestPointProperties::LoadUseProperties(UFG::InterestPointProperties *this, UFG::qPropertySet *pProps, component_InterestPoint *interest_point_data, schema_classlist *class_list_data)
{
  bool v4; // al
  unsigned int v5; // edx
  UFG::InterestPoint::eInterestPointPriority v6; // eax

  this->mRequiresSync = interest_point_data->RequiresSync;
  this->mPositionSyncRequired = interest_point_data->PositionSyncRequired;
  this->mRotationSyncRequired = interest_point_data->RotationSyncRequired;
  this->mAllowSocialInteraction = interest_point_data->AllowSocialInteraction;
  this->mIsAutoInteractable = interest_point_data->IsAutoInteractable;
  this->mIsSittingConversation = interest_point_data->IsSittingConversation;
  this->mIgnoreStimuli = interest_point_data->IgnoreStimuli;
  this->mUseTimeMin = interest_point_data->UseTimeMin;
  this->mUseTimeMax = interest_point_data->UseTimeMax;
  this->mCoolDownTimeMin = interest_point_data->CoolDownTimeMin;
  this->mCoolDownTimeMax = interest_point_data->CoolDownTimeMax;
  this->mMinGroupSize = interest_point_data->MinGroupSize;
  this->mMaxGroupSize = interest_point_data->MaxGroupSize;
  this->mMaxDistanceFromPlayer = interest_point_data->MaxDistanceFromPlayer;
  this->mSpawnAmbientUserDistance = interest_point_data->SpawnAmbientUserDistance;
  v4 = interest_point_data->UserCanBeRecycled;
  this->mPriority = 0;
  this->mUserCanBeRecycled = v4;
  v5 = interest_point_data->InterestPointPriority.mUID;
  if ( v5 == qSymbol_Critical.mUID )
  {
    this->mPriority = 4;
  }
  else if ( v5 == qSymbol_High.mUID )
  {
    this->mPriority = 3;
  }
  else if ( v5 == qSymbol_Medium.mUID )
  {
    this->mPriority = 2;
  }
  else
  {
    v6 = this->mPriority;
    if ( v5 == qSymbol_Low.mUID )
      v6 = 1;
    this->mPriority = v6;
  }
}

// File Line: 417
// RVA: 0x15522C0
__int64 UFG::_dynamic_initializer_for__gInterestPointCachedProperties__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::gInterestPointCachedProperties.mTree);
  return atexit(UFG::_dynamic_atexit_destructor_for__gInterestPointCachedProperties__);
}

// File Line: 427
// RVA: 0x57DB20
void __fastcall UFG::InterestPointPropertiesHandle::~InterestPointPropertiesHandle(UFG::InterestPointPropertiesHandle *this)
{
  UFG::InterestPointPropertiesHandle::Set(this, 0i64, 1);
}

// File Line: 432
// RVA: 0x58B5D0
void __fastcall UFG::InterestPointPropertiesHandle::Set(UFG::InterestPointPropertiesHandle *this, UFG::InterestPointProperties *pProperties, const bool isOwner)
{
  bool v3; // bp
  UFG::InterestPointProperties *v4; // r14
  UFG::InterestPointPropertiesHandle *v5; // rdi
  UFG::InterestPointProperties *v6; // rsi
  UFG::qSymbol *v7; // rcx
  UFG::qSymbol *v8; // rbx

  v3 = isOwner;
  v4 = pProperties;
  v5 = this;
  v6 = this->mProperties;
  if ( this->mProperties && this->mIsOwner )
  {
    v7 = v6->mUseClassList.p;
    if ( v7 )
    {
      v8 = v7 - 1;
      `eh vector destructor iterator(v7, 4ui64, v7[-1].mUID, (void (__fastcall *)(void *))_);
      operator delete[](v8);
    }
    v6->mUseClassList.p = 0i64;
    *(_QWORD *)&v6->mUseClassList.size = 0i64;
    operator delete[](v6);
    v5->mProperties = v4;
    v5->mIsOwner = v3;
  }
  else
  {
    this->mIsOwner = isOwner;
    this->mProperties = pProperties;
  }
}

// File Line: 444
// RVA: 0x585740
void __fastcall UFG::InterestPointPropertiesHandle::Load(UFG::InterestPointPropertiesHandle *this, UFG::InterestPointProperties *pCachedProperties, UFG::qPropertySet *pProps)
{
  UFG::qPropertySet *v3; // rsi
  UFG::InterestPointPropertiesHandle *v4; // rbx
  UFG::qPropertySet *v5; // rax
  char *v6; // rdi
  component_InterestPoint *v7; // r8
  UFG::qPropertySet *v8; // rax
  UFG::InterestPointProperties *v9; // rdi
  char *v10; // rbp
  UFG::allocator::free_link *v11; // rax
  UFG::InterestPointProperties *v12; // rax

  v3 = pProps;
  v4 = this;
  if ( pCachedProperties )
  {
    UFG::InterestPointPropertiesHandle::Set(this, pCachedProperties, 0);
  }
  else
  {
    if ( this->mIsOwner && this->mProperties )
    {
      v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
             pProps,
             (UFG::qSymbol *)&component_InterestPoint::sPropertyName.mUID,
             DEPTH_RECURSE);
      if ( v5 )
        v6 = UFG::qPropertySet::GetMemImagePtr(v5);
      else
        v6 = 0i64;
      v7 = (component_InterestPoint *)v6;
    }
    else
    {
      v8 = UFG::qPropertySet::Get<UFG::qPropertySet>(
             pProps,
             (UFG::qSymbol *)&component_InterestPoint::sPropertyName.mUID,
             DEPTH_RECURSE);
      v9 = 0i64;
      if ( v8 )
        v10 = UFG::qPropertySet::GetMemImagePtr(v8);
      else
        v10 = 0i64;
      v11 = UFG::qMalloc(0xA0ui64, "InterestPointProperties", 0i64);
      if ( v11 )
      {
        UFG::InterestPointProperties::InterestPointProperties((UFG::InterestPointProperties *)v11);
        v9 = v12;
      }
      UFG::InterestPointPropertiesHandle::Set(v4, v9, 1);
      v7 = (component_InterestPoint *)v10;
    }
    UFG::InterestPointProperties::Load(v4->mProperties, v3, v7);
  }
}

// File Line: 503
// RVA: 0x57EF80
void __fastcall UFG::InterestPointProperties::AddToCache(UFG::qPropertySet *pPropertySet, UFG::qSymbol *interestPointTypeSymbol)
{
  UFG::qPropertySet *v2; // rbp
  unsigned int v3; // edi
  UFG::allocator::free_link *v4; // rax
  char *v5; // rsi
  UFG::InterestPointProperties *v6; // rax
  UFG::InterestPointProperties *v7; // rbx
  UFG::qPropertySet *v8; // rax

  v2 = pPropertySet;
  v3 = interestPointTypeSymbol->mUID;
  if ( !interestPointTypeSymbol->mUID || !UFG::qBaseTreeRB::Get(&UFG::gInterestPointCachedProperties.mTree, v3) )
  {
    v4 = UFG::qMalloc(0xA0ui64, "InterestPointProperties", 0i64);
    v5 = 0i64;
    if ( v4 )
    {
      UFG::InterestPointProperties::InterestPointProperties((UFG::InterestPointProperties *)v4);
      v7 = v6;
    }
    else
    {
      v7 = 0i64;
    }
    if ( v7 )
    {
      v8 = UFG::qPropertySet::Get<UFG::qPropertySet>(
             v2,
             (UFG::qSymbol *)&component_InterestPoint::sPropertyName.mUID,
             DEPTH_RECURSE);
      if ( v8 )
        v5 = UFG::qPropertySet::GetMemImagePtr(v8);
      v7->mNode.mUID = v3;
      UFG::InterestPointProperties::Load(v7, v2, (component_InterestPoint *)v5);
      UFG::qBaseTreeRB::Add(&UFG::gInterestPointCachedProperties.mTree, &v7->mNode);
    }
  }
}

// File Line: 542
// RVA: 0x57CD20
void __fastcall UFG::InterestPointType::InterestPointType(UFG::InterestPointType *this)
{
  UFG::InterestPointType *v1; // rbx

  v1 = this;
  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  `eh vector constructor iterator(
    this->mAnimBankSymbols,
    0x10ui64,
    3,
    (void (__fastcall *)(void *))UFG::qArray<UFG::qSymbolUC,0>::qArray<UFG::qSymbolUC,0>);
  v1->mUseItemList.p = 0i64;
  *(_QWORD *)&v1->mUseItemList.size = 0i64;
  *(_WORD *)&v1->mItemListMatchesNoItem = 0;
  v1->mHasBehaviourFile = 0;
  UFG::qSharedString::qSharedString(&v1->mBehaviourFileName);
  v1->mBehaviour = 0i64;
  v1->mBehaviourInteractions = 0i64;
  v1->mBehaviourConditions = 0i64;
  *(_WORD *)&v1->mHasBeginningScript = 0;
  v1->mHasOnReservationScript = 0;
  *(_QWORD *)&v1->mBeginningScriptHash = 0i64;
  v1->mOnReservationScriptHash = 0;
  v1->mDescription.mUID = -1;
  v1->mInterestPointTypePropertySet = 0i64;
}

// File Line: 554
// RVA: 0x582F30
void __fastcall UFG::InterestPointType::InitActionTree(UFG::InterestPointType *this)
{
  UFG::InterestPointType *v1; // rbx
  Expression::IMemberMap *v2; // rax
  __int64 v3; // rax

  v1 = this;
  v2 = ActionNode::Load(this->mBehaviourFileName.mText);
  v1->mBehaviour = (ActionNode *)v2;
  if ( v2 )
  {
    if ( !(_S7_14 & 1) )
    {
      _S7_14 |= 1u;
      dword_14242E450 = UFG::qStringHashUpper32("UseConditions", 0xFFFFFFFF);
    }
    v1->mBehaviourConditions = (ActionNode *)((__int64 (__fastcall *)(ActionNode *, int *, _QWORD))v1->mBehaviour->vfptr[1].CreateClone)(
                                               v1->mBehaviour,
                                               &dword_14242E450,
                                               0i64);
    if ( !(_S9_16 & 1) )
    {
      _S9_16 |= 1u;
      node_id.mUID = UFG::qStringHashUpper32("Interactions", 0xFFFFFFFF);
    }
    v3 = ((__int64 (__fastcall *)(ActionNode *, ActionID *, _QWORD))v1->mBehaviour->vfptr[1].CreateClone)(
           v1->mBehaviour,
           &node_id,
           0i64);
    v1->mBehaviourInteractions = (ActionNode *)v3;
    if ( !v3 )
      UFG::qPrintf("Invalid POI Behaviour, no node: %s!\n", v1->mBehaviourFileName.mText);
  }
  else
  {
    UFG::qPrintf("Invalid POI Behaviour: %s!\n", v1->mBehaviourFileName.mText);
    v1->mBehaviourConditions = 0i64;
    v1->mBehaviourInteractions = 0i64;
  }
}

// File Line: 586
// RVA: 0x58AAC0
void __fastcall UFG::InterestPointType::ReadAnimBankSymbols(UFG::InterestPointType *this, UFG::qPropertySet *pInterestPointTypePropertySet)
{
  UFG::qPropertySet *v2; // rdi
  UFG::InterestPointType *v3; // rsi
  UFG::qArray<UFG::qSymbolUC,0> *v4; // rsi
  UFG::qSymbol *v5; // r12
  signed __int64 v6; // rbx
  UFG::qPropertyList *v7; // rax
  UFG::qPropertyList *v8; // r13
  unsigned int v9; // er14
  unsigned int v10; // ebp
  unsigned int v11; // ebx
  __int64 v12; // r15
  unsigned int v13; // edi
  unsigned int v14; // edx
  unsigned int v15; // edx
  UFG::qSymbol name; // [rsp+38h] [rbp-50h]
  unsigned int v17; // [rsp+3Ch] [rbp-4Ch]
  unsigned int v18; // [rsp+40h] [rbp-48h]
  UFG::qPropertySet *v19; // [rsp+98h] [rbp+10h]
  UFG::qSymbol *v20; // [rsp+A0h] [rbp+18h]
  signed __int64 v21; // [rsp+A8h] [rbp+20h]

  v19 = pInterestPointTypePropertySet;
  v2 = pInterestPointTypePropertySet;
  v3 = this;
  `eh vector constructor iterator(&name, 4ui64, 3, (void (__fastcall *)(void *))BackInfo::BackInfo);
  name.mUID = qSymbol_AnimBankFileNames.mUID;
  v17 = qSymbol_AnimBankFileNamesMale.mUID;
  v18 = qSymbol_AnimBankFileNamesFemale.mUID;
  v4 = v3->mAnimBankSymbols;
  v5 = &name;
  v20 = &name;
  v6 = 3i64;
  v21 = 3i64;
  do
  {
    v7 = UFG::qPropertySet::Get<UFG::qPropertyList>(v2, v5, DEPTH_RECURSE);
    v8 = v7;
    if ( v7 )
    {
      v9 = v7->mNumElements;
      if ( v9 > v4->capacity )
        UFG::qArray<UFG::qSymbolUC,0>::Reallocate(v4, v9, "qArray.Reallocate(Reserve)");
      v10 = 0;
      if ( v9 )
      {
        do
        {
          v11 = UFG::qPropertyList::Get<UFG::qSymbolUC>(v8, v10)->mUID;
          v12 = v4->size;
          v13 = v12 + 1;
          v14 = v4->capacity;
          if ( (signed int)v12 + 1 > v14 )
          {
            if ( v14 )
              v15 = 2 * v14;
            else
              v15 = 1;
            for ( ; v15 < v13; v15 *= 2 )
              ;
            if ( v15 <= 4 )
              v15 = 4;
            if ( v15 - v13 > 0x10000 )
              v15 = v12 + 65537;
            UFG::qArray<UFG::qSymbolUC,0>::Reallocate(v4, v15, "qArray.Add");
          }
          v4->size = v13;
          v4->p[v12].mUID = v11;
          ++v10;
        }
        while ( v10 < v9 );
        v5 = v20;
        v6 = v21;
        v2 = v19;
      }
    }
    ++v5;
    v20 = v5;
    ++v4;
    v21 = --v6;
  }
  while ( v6 );
  `eh vector destructor iterator(&name, 4ui64, 3, (void (__fastcall *)(void *))_);
}

// File Line: 610
// RVA: 0x583290
void __fastcall UFG::InterestPointType::InitFromPropertySet(UFG::InterestPointType *this, UFG::qPropertySet *pInterestPointTypePropertySet)
{
  UFG::qPropertySet *v2; // r15
  UFG::InterestPointType *v3; // rbx
  UFG::qSymbol *v4; // rax
  UFG::qSymbol *v5; // rdx
  UFG::qPropertySet *v6; // rax
  char *v7; // rax
  char *v8; // rdi
  char v9; // cl
  char v10; // si
  __int64 v11; // rax
  const char *v12; // rcx
  char v13; // al
  __int64 v14; // rax
  const char *v15; // rcx
  char v16; // al
  __int64 v17; // rax
  const char *v18; // rcx
  UFG::qPropertySet *v19; // rax
  char *v20; // rdi
  bool *v21; // rax
  int *v22; // rcx
  char v23; // al
  char *v24; // rax
  UFG::eInventoryItemEnum *v25; // rcx
  __int64 v26; // rax
  signed __int64 v27; // rax
  bool v28; // zf
  UFG::qPropertyList *v29; // rax
  unsigned int v30; // edi
  unsigned int v31; // er12
  UFG::qSymbol *v32; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v33; // rax
  unsigned int v34; // er15
  __int64 v35; // r13
  unsigned int v36; // edi
  unsigned int v37; // edx
  unsigned int v38; // edx
  char *v39; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v40; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v41; // rax
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+28h] [rbp-28h]
  UFG::qPropertySet *v43; // [rsp+98h] [rbp+48h]
  unsigned int v44; // [rsp+A0h] [rbp+50h]
  UFG::qPropertyList *v45; // [rsp+A8h] [rbp+58h]

  if ( !pInterestPointTypePropertySet )
    return;
  v43 = pInterestPointTypePropertySet;
  v2 = pInterestPointTypePropertySet;
  v3 = this;
  this->mInterestPointTypePropertySet = pInterestPointTypePropertySet;
  v4 = UFG::qPropertySet::Get<UFG::qSymbol>(
         pInterestPointTypePropertySet,
         (UFG::qSymbol *)&qSymbol_Description_17.mUID,
         DEPTH_RECURSE);
  v5 = &UFG::gNullQSymbol;
  if ( v4 )
    v5 = v4;
  v3->mDescription = (UFG::qSymbol)v5->mUID;
  v6 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         v2,
         (UFG::qSymbol *)&schema_interestpoint_script::sPropertyName.mUID,
         DEPTH_RECURSE);
  if ( v6 && (v7 = UFG::qPropertySet::GetMemImagePtr(v6), (v8 = v7) != 0i64) )
  {
    v9 = *v7;
    v3->mHasBeginningScript = *v7;
    v10 = 0;
    if ( v9 )
    {
      v11 = *((_QWORD *)v7 + 1);
      if ( v11 )
        v12 = &v8[v11 + 8];
      else
        v12 = 0i64;
      v3->mBeginningScriptHash = UFG::qStringHash32(v12, 0xFFFFFFFF);
    }
    else
    {
      v3->mBeginningScriptHash = 0;
    }
    v13 = v8[1];
    v3->mHasEndingScript = v13;
    if ( v13 )
    {
      v14 = *((_QWORD *)v8 + 2);
      if ( v14 )
        v15 = &v8[v14 + 16];
      else
        v15 = 0i64;
      v3->mEndingScriptHash = UFG::qStringHash32(v15, 0xFFFFFFFF);
    }
    else
    {
      v3->mEndingScriptHash = 0;
    }
    v16 = v8[40];
    v3->mHasOnReservationScript = v16;
    if ( v16 )
    {
      v17 = *((_QWORD *)v8 + 6);
      if ( v17 )
        v18 = &v8[v17 + 48];
      else
        v18 = 0i64;
      v3->mOnReservationScriptHash = UFG::qStringHash32(v18, 0xFFFFFFFF);
      goto LABEL_25;
    }
  }
  else
  {
    *(_WORD *)&v3->mHasBeginningScript = 0;
    v10 = 0;
    *(_QWORD *)&v3->mBeginningScriptHash = 0i64;
    v3->mHasOnReservationScript = 0;
  }
  v3->mOnReservationScriptHash = 0;
LABEL_25:
  v19 = UFG::qPropertySet::Get<UFG::qPropertySet>(
          v2,
          (UFG::qSymbol *)&component_InterestPoint::sPropertyName.mUID,
          DEPTH_RECURSE);
  if ( v19 )
    v20 = UFG::qPropertySet::GetMemImagePtr(v19);
  else
    v20 = 0i64;
  LOBYTE(v44) = 0;
  v21 = UFG::qPropertySet::Get<bool>(v2, (UFG::qSymbol *)&qSymbol_HasBehaviour.mUID, DEPTH_RECURSE);
  v22 = (int *)&v44;
  if ( v21 )
    v22 = (int *)v21;
  v23 = *(_BYTE *)v22;
  v3->mHasBehaviourFile = *(_BYTE *)v22;
  if ( v23 )
  {
    v24 = UFG::qPropertySet::Get<char const *>(v2, (UFG::qSymbol *)&qSymbol_BehaviourFile.mUID, DEPTH_RECURSE);
    UFG::qSharedString::operator=(&v3->mBehaviourFileName, v24);
    UFG::InterestPointType::InitActionTree(v3);
  }
  else
  {
    UFG::qSharedString::Set(&v3->mBehaviourFileName, &customWorldMapCaption);
  }
  v25 = v3->mUseItemList.p;
  if ( v25 )
    operator delete[](v25);
  v3->mUseItemList.p = 0i64;
  *(_QWORD *)&v3->mUseItemList.size = 0i64;
  v26 = *((_QWORD *)v20 + 8);
  if ( v26 )
  {
    v27 = v26 + 64;
    v28 = &v20[v27] == 0i64;
    v29 = (UFG::qPropertyList *)&v20[v27];
    v45 = v29;
    if ( !v28 )
    {
      v30 = v29->mNumElements;
      v44 = v30;
      if ( v30 )
      {
        UFG::qArray<long,0>::Reallocate((UFG::qArray<unsigned long,0> *)&v3->mUseItemList, v30, "mUseItemList Reserve");
        v29 = v45;
      }
      v31 = 0;
      if ( v30 )
      {
        do
        {
          v32 = UFG::qPropertyList::Get<UFG::qSymbol>(v29, v31);
          if ( v32->mUID == qSymbol_None.mUID )
          {
            v3->mItemListMatchesNoItem = 1;
          }
          else if ( v32->mUID == qSymbol_Weapon_17.mUID )
          {
            v3->mItemListMatchesWeapons = 1;
          }
          else
          {
            pTrackEnumBinding.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
            pTrackEnumBinding.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
            pTrackEnumBinding.m_EnumSymbol.mUID = -1;
            pTrackEnumBinding.m_EnumSymbol = (UFG::qSymbol)v32->mUID;
            *(_QWORD *)&pTrackEnumBinding.m_EnumValue = 0i64;
            pTrackEnumBinding.m_uEnumUID = 0;
            if ( UFG::gInventoryItemTracksEnum.m_enumLists.size )
            {
              TracksEnum<unsigned long>::ResolveBinding(&UFG::gInventoryItemTracksEnum, &pTrackEnumBinding);
            }
            else
            {
              v33 = UFG::gInventoryItemTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
              UFG::gInventoryItemTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
              pTrackEnumBinding.mPrev = v33;
              pTrackEnumBinding.mNext = &UFG::gInventoryItemTracksEnum.m_UnresolvedTracksEnumBindingList.mNode;
              UFG::gInventoryItemTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
            }
            v34 = pTrackEnumBinding.m_EnumValue;
            if ( pTrackEnumBinding.m_EnumValue )
            {
              v35 = v3->mUseItemList.size;
              v36 = v35 + 1;
              v37 = v3->mUseItemList.capacity;
              if ( (signed int)v35 + 1 > v37 )
              {
                if ( v37 )
                  v38 = 2 * v37;
                else
                  v38 = 1;
                for ( ; v38 < v36; v38 *= 2 )
                  ;
                if ( v38 <= 4 )
                  v38 = 4;
                if ( v38 - v36 > 0x10000 )
                  v38 = v35 + 65537;
                UFG::qArray<long,0>::Reallocate((UFG::qArray<unsigned long,0> *)&v3->mUseItemList, v38, "mUseItemList");
              }
              v3->mUseItemList.size = v36;
              v3->mUseItemList.p[v35] = v34;
              v30 = v44;
            }
            else
            {
              v39 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v3->mInterestPointTypePropertySet->mName);
              UFG::qPrintf("Interest point with invalid item list element, check the property set for %s\n", v39);
            }
            v40 = pTrackEnumBinding.mPrev;
            v41 = pTrackEnumBinding.mNext;
            pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
            v41->mPrev = v40;
            pTrackEnumBinding.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
            pTrackEnumBinding.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
          }
          ++v31;
          v29 = v45;
        }
        while ( v31 < v30 );
        v2 = v43;
      }
    }
  }
  if ( v3->mItemListMatchesNoItem || !v3->mUseItemList.size )
    v10 = 1;
  v3->mItemListMatchesNoItem = v10;
  v3->mNode.mUID = v2->mName.mUID;
  UFG::InterestPointType::ReadAnimBankSymbols(v3, v2);
}

// File Line: 761
// RVA: 0x57CA30
void __fastcall UFG::InterestPoint::InterestPoint(UFG::InterestPoint *this, UFG::qSymbol *name)
{
  UFG::qSymbol *v2; // rbx
  UFG::InterestPoint *v3; // rdi
  unsigned int v4; // eax
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList> *v5; // rax
  char v6; // cl
  UFG::GridIntrusiveNode<UFG::InterestPoint> *v7; // [rsp+58h] [rbp+10h]
  UFG::qSafePointer<UFG::SimComponent,UFG::CharacterAnimationComponent> *v8; // [rsp+58h] [rbp+10h]
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v9; // [rsp+58h] [rbp+10h]
  UFG::qSafePointer<UFG::SimComponent,UFG::InterestPointUserComponent> *v10; // [rsp+58h] [rbp+10h]
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v11; // [rsp+58h] [rbp+10h]

  v2 = name;
  v3 = this;
  UFG::MarkerBase::MarkerBase((UFG::MarkerBase *)&this->vfptr, name, 0i64, 0x10000u);
  v4 = v2->mUID;
  v3->mNode.mParent = 0i64;
  v3->mNode.mChild[0] = 0i64;
  v3->mNode.mChild[1] = 0i64;
  v3->mNode.mUID = v4;
  v5 = (UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList> *)&v3->mPrev;
  v5->mPrev = v5;
  v5->mNext = v5;
  UFG::qSafePointerNode<UFG::InterestPoint>::qSafePointerNode<UFG::InterestPoint>((UFG::qSafePointerNode<UFG::InterestPoint> *)&v3->vfptr);
  v7 = (UFG::GridIntrusiveNode<UFG::InterestPoint> *)&v3->mPrev;
  v7->mPrev = (UFG::qNode<UFG::InterestPoint,UFG::InterestPoint> *)&v7->mPrev;
  v7->mNext = (UFG::qNode<UFG::InterestPoint,UFG::InterestPoint> *)&v7->mPrev;
  v3->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::InterestPoint::`vftable{for `UFG::MarkerBase};
  v3->vfptr = (UFG::qSafePointerNode<UFG::InterestPoint>Vtbl *)&UFG::InterestPoint::`vftable{for `UFG::qSafePointerNode<UFG::InterestPoint>};
  `eh vector constructor iterator(
    v3->mAnimGroupHandles,
    0x18ui64,
    3,
    (void (__fastcall *)(void *))AnimationGroupHandleContainer::AnimationGroupHandleContainer);
  v3->mReferenceSubPriority = 0;
  *(_QWORD *)&v3->mMinimumDistanceToPlayerSquared = 2139095039i64;
  v3->mPoiType.mUID = -1;
  v3->mIsPositionCached = 0;
  v3->mBoneId = -1;
  v8 = &v3->mpParentCharacterAnimationComponent;
  v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
  v8->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
  v3->mpParentCharacterAnimationComponent.m_pPointer = 0i64;
  *(_WORD *)&v3->mFullUpdateRequired = 256;
  v9 = &v3->mpUser;
  v9->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v9->mPrev;
  v9->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v9->mPrev;
  v3->mpUser.m_pPointer = 0i64;
  v10 = &v3->mpInterestPointUserComponent;
  v10->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v10->mPrev;
  v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v10->mPrev;
  v3->mpInterestPointUserComponent.m_pPointer = 0i64;
  v3->mInterestPointType = 0i64;
  v3->mUseTime = -1.0;
  *(_QWORD *)&v3->mCooldownTime = 0i64;
  *(_DWORD *)&v3->mIsInterrupted = 50397184;
  *(_QWORD *)&v3->mTimeSinceBeginUse = 0i64;
  v3->mNeedsBoneFixupWhenRigAvailable = 0;
  v3->mBeginningScriptInfo.mpCachedScript = 0i64;
  *(_WORD *)&v3->mBeginningScriptInfo.mHasScript = 0;
  v3->mEndingScriptInfo.mpCachedScript = 0i64;
  *(_WORD *)&v3->mEndingScriptInfo.mHasScript = 0;
  v3->mOnReservationScriptInfo.mpCachedScript = 0i64;
  *(_WORD *)&v3->mOnReservationScriptInfo.mHasScript = 0;
  v3->mPropertiesHandle.mProperties = 0i64;
  v3->mPropertiesHandle.mIsOwner = 1;
  v3->mpPedInfoUser = 0i64;
  v11 = &v3->mLinkObject;
  v11->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v11->mPrev;
  v11->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v11->mPrev;
  v3->mLinkObject.m_pPointer = 0i64;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v3->vfptr,
    UFG::InterestPoint::_InterestPointTypeUID,
    "InterestPoint");
  *(_QWORD *)v3->mLastPriority = -1i64;
  *(_QWORD *)&v3->mLastPriority[2] = -1i64;
  v3->mLastSubPriority[2] = -1;
  ++UFG::InterestPoint::msNumPOIsThisFrame;
  v6 = initedTweakables;
  if ( !initedTweakables )
    v6 = 1;
  initedTweakables = v6;
  *(_WORD *)&v3->mAddedToGrid = 0;
  v3->mGridIndex = -1;
}

// File Line: 820
// RVA: 0x5826D0
_BOOL8 __fastcall UFG::InterestPoint::GetIsSittingConversation(UFG::InterestPoint *this)
{
  return this->mPropertiesHandle.mProperties->mIsSittingConversation;
}

// File Line: 824
// RVA: 0x5826C0
_BOOL8 __fastcall UFG::InterestPoint::GetIgnoreStimuli(UFG::InterestPoint *this)
{
  return this->mPropertiesHandle.mProperties->mIgnoreStimuli;
}

// File Line: 828
// RVA: 0x582A80
_BOOL8 __fastcall UFG::InterestPoint::GetWeatherFilterOn(UFG::InterestPoint *this)
{
  return this->mPropertiesHandle.mProperties->mWeatherFilterOn;
}

// File Line: 832
// RVA: 0x582A70
_BOOL8 __fastcall UFG::InterestPoint::GetWeatherFilterIsRaining(UFG::InterestPoint *this)
{
  return this->mPropertiesHandle.mProperties->mWeatherFilterIsRaining;
}

// File Line: 837
// RVA: 0x58BA10
void __fastcall UFG::InterestPoint::SetPedInfoUser(UFG::InterestPoint *this, UFG::PedSpawningInfo *pedInfo)
{
  this->mpPedInfoUser = pedInfo;
  JUMPOUT(pedInfo, 0i64, UFG::InterestPoint::EndReservation);
}

// File Line: 855
// RVA: 0x58BA30
void __fastcall UFG::InterestPoint::SetPlayerReference(UFG::InterestPoint *this, bool b)
{
  if ( b )
    ++this->mReferencedByPlayer;
  else
    --this->mReferencedByPlayer;
}

// File Line: 859
// RVA: 0x58B960
void __fastcall UFG::InterestPoint::SetMalePedestrianReference(UFG::InterestPoint *this, bool b)
{
  if ( b )
    ++this->mReferencedByMalePedestrian;
  else
    --this->mReferencedByMalePedestrian;
}

// File Line: 863
// RVA: 0x58B8F0
void __fastcall UFG::InterestPoint::SetFemalePedestrianReference(UFG::InterestPoint *this, bool b)
{
  if ( b )
    ++this->mReferencedByFemalePedestrian;
  else
    --this->mReferencedByFemalePedestrian;
}

// File Line: 868
// RVA: 0x583030
void __fastcall UFG::InterestPoint::InitAnimHandles(UFG::InterestPoint *this)
{
  UFG::InterestPoint *v1; // r13
  signed __int64 v2; // r15
  AnimationGroupHandleContainer *v3; // r14
  UFG::InterestPointType *v4; // rax
  signed int v5; // er12
  __int64 v6; // rbp
  signed __int64 v7; // r15
  int v8; // eax
  int v9; // eax
  int v10; // eax
  UFG::eAnimationPriorityEnum v11; // ebx
  UFG::qSymbolUC *v12; // rsi
  UFG::allocator::free_link *v13; // rax
  AnimationGroupHandle *v14; // rax
  AnimationGroupHandle *v15; // rdi
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *v16; // rcx
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *v17; // rax
  signed __int64 v18; // [rsp+78h] [rbp+10h]

  v1 = this;
  v2 = 32i64;
  v18 = 32i64;
  v3 = this->mAnimGroupHandles;
  do
  {
    v4 = v1->mInterestPointType;
    v5 = *(_DWORD *)((char *)&v4->mNode.mParent + v2);
    v6 = 0i64;
    if ( v5 > 0 )
    {
      v7 = (signed __int64)v4 + v2;
      do
      {
        v8 = (unsigned __int64)UFG::InterestPoint::GetPriority(v1) - 1;
        if ( v8 )
        {
          v9 = v8 - 1;
          if ( v9 )
          {
            v10 = v9 - 1;
            if ( v10 )
            {
              if ( v10 == 1 )
                v11 = 9;
              else
                v11 = 2;
            }
            else
            {
              v11 = 5;
            }
          }
          else
          {
            v11 = 4;
          }
        }
        else
        {
          v11 = 3;
        }
        v12 = (UFG::qSymbolUC *)(*(_QWORD *)(v7 + 8) + 4 * v6);
        v13 = UFG::qMalloc(0x50ui64, "AnimationGroupHandle", 0i64);
        if ( v13 )
        {
          AnimationGroupHandle::AnimationGroupHandle((AnimationGroupHandle *)v13);
          v15 = v14;
        }
        else
        {
          v15 = 0i64;
        }
        AnimationGroupHandle::Init(v15, v12, v11);
        v16 = (UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *)&v15->mPrev;
        v17 = v3->m_AnimationGroupHandleList.mNode.mPrev;
        v17->mNext = (UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *)&v15->mPrev;
        v16->mPrev = v17;
        v16->mNext = &v3->m_AnimationGroupHandleList.mNode;
        v3->m_AnimationGroupHandleList.mNode.mPrev = (UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *)&v15->mPrev;
        v6 = (unsigned int)(v6 + 1);
      }
      while ( (signed int)v6 < v5 );
      v2 = v18;
    }
    v2 += 16i64;
    v18 = v2;
    ++v3;
  }
  while ( v2 < 80 );
}

// File Line: 923
// RVA: 0x58DC80
void __fastcall UFG::InterestPoint::UpdateAnimHandles(UFG::InterestPoint *this, AnimationGroupHandleContainer *animGroupHandles, const float minimumDistanceToPlayerSquared, const bool isReferencedByPlayer, const bool isReferencedByPedestrian, UFG::eAnimationPriorityEnum *lastPriority, unsigned __int16 *lastSubPriority)
{
  AnimationGroupHandleContainer *v7; // rdi
  UFG::InterestPoint *v8; // rsi
  signed int v9; // er8
  UFG::eAnimationPriorityEnum v10; // ebx
  UFG::InterestPoint::eInterestPointPriority v11; // ecx
  int v12; // ecx
  int v13; // ecx
  int v14; // ecx

  v7 = animGroupHandles;
  v8 = this;
  if ( (UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> **)&animGroupHandles->m_AnimationGroupHandleList.mNode.mNext[-1] != &animGroupHandles[-1].m_AnimationGroupHandleList.mNode.mNext )
  {
    v9 = 2;
    if ( isReferencedByPlayer )
    {
      v10 = 5;
      if ( PLAYER_PRIORITY_DISTANCE_SQ > this->mMinimumDistanceToPlayerSquared )
        v10 = 15;
    }
    else
    {
      v10 = 2;
      if ( isReferencedByPedestrian )
        v10 = 5;
    }
    if ( this->mOnDetachCalled )
      v11 = 0;
    else
      v11 = this->mPropertiesHandle.mProperties->mPriority;
    v12 = v11 - 1;
    if ( v12 )
    {
      v13 = v12 - 1;
      if ( v13 )
      {
        v14 = v13 - 1;
        if ( v14 )
        {
          if ( v14 == 1 )
            v9 = 9;
        }
        else
        {
          v9 = 5;
        }
      }
      else
      {
        v9 = 4;
      }
    }
    else
    {
      v9 = 3;
    }
    if ( v10 <= v9 )
      v10 = v9;
    if ( (signed int)v10 <= 2 )
    {
      if ( animGroupHandles->m_bHasBeenBound )
        AnimationGroupHandleContainer::Unbind(animGroupHandles);
      *lastPriority = -1;
      *lastSubPriority = -1;
    }
    else if ( v10 != *lastPriority || v8->mReferenceSubPriority != *lastSubPriority )
    {
      AnimationGroupHandleContainer::SetAnimationPriority(animGroupHandles, v10, v8->mReferenceSubPriority);
      if ( !v7->m_bHasBeenBound )
        AnimationGroupHandleContainer::Bind(v7);
      *lastPriority = v10;
      *lastSubPriority = v8->mReferenceSubPriority;
    }
  }
}

// File Line: 991
// RVA: 0x58DDD0
void __fastcall UFG::InterestPoint::UpdateAnimHandles(UFG::InterestPoint *this)
{
  UFG::InterestPoint *v1; // rbx

  v1 = this;
  UFG::InterestPoint::UpdateAnimHandles(
    this,
    this->mAnimGroupHandles,
    this->mMinimumDistanceToPlayerSquared,
    this->mReferencedByPlayer != 0,
    *(_WORD *)&this->mReferencedByMalePedestrian != 0,
    this->mLastPriority,
    this->mLastSubPriority);
  UFG::InterestPoint::UpdateAnimHandles(
    v1,
    &v1->mAnimGroupHandles[1],
    v1->mMinimumDistanceToPlayerSquared,
    v1->mReferencedByPlayer != 0,
    v1->mReferencedByMalePedestrian != 0,
    &v1->mLastPriority[1],
    &v1->mLastSubPriority[1]);
  UFG::InterestPoint::UpdateAnimHandles(
    v1,
    &v1->mAnimGroupHandles[2],
    v1->mMinimumDistanceToPlayerSquared,
    0,
    v1->mReferencedByFemalePedestrian != 0,
    &v1->mLastPriority[2],
    &v1->mLastSubPriority[2]);
}

// File Line: 1001
// RVA: 0x584110
char __fastcall UFG::InterestPoint::IsAvailable(UFG::InterestPoint *this, UFG::SimObject *simObject, const bool ensureReferenced)
{
  UFG::InterestPoint *v3; // rdi
  bool v4; // al
  signed __int64 v5; // rsi
  signed __int64 v6; // rbx
  AnimationGroup *v7; // rcx
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *v8; // rax
  signed __int64 v9; // rdi
  signed __int64 v10; // rbx
  AnimationGroup *v11; // rcx
  AnimationGroup *v13; // rcx
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *v14; // rax
  signed __int64 v15; // rdi
  signed __int64 v16; // rbx
  AnimationGroup *v17; // rcx

  v3 = this;
  v4 = UFG::IsFemale(simObject);
  v5 = (signed __int64)&v3->mPrev;
  v6 = (signed __int64)&v3->mAnimGroupHandles[0].m_AnimationGroupHandleList.mNode.mNext[-1];
  if ( !v4 )
  {
    for ( ; v6 != v5; v6 = *(_QWORD *)(v6 + 24) - 16i64 )
    {
      v13 = *(AnimationGroup **)(v6 + 56);
      if ( !v13 || !AnimationGroup::IsStreamedIn(v13) )
        return 0;
    }
    v14 = v3->mAnimGroupHandles[1].m_AnimationGroupHandleList.mNode.mNext;
    v15 = (signed __int64)&v3->mAnimGroupHandles[0].m_AnimationGroupHandleList.mNode.mNext;
    v16 = (signed __int64)&v14[-1];
    if ( &v14[-1] != (UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *)v15 )
    {
      while ( 1 )
      {
        v17 = *(AnimationGroup **)(v16 + 56);
        if ( !v17 || !AnimationGroup::IsStreamedIn(v17) )
          break;
        v16 = *(_QWORD *)(v16 + 24) - 16i64;
        if ( v16 == v15 )
          return 1;
      }
      return 0;
    }
    return 1;
  }
  for ( ; v6 != v5; v6 = *(_QWORD *)(v6 + 24) - 16i64 )
  {
    v7 = *(AnimationGroup **)(v6 + 56);
    if ( !v7 || !AnimationGroup::IsStreamedIn(v7) )
      return 0;
  }
  v8 = v3->mAnimGroupHandles[2].m_AnimationGroupHandleList.mNode.mNext;
  v9 = (signed __int64)&v3->mAnimGroupHandles[1].m_AnimationGroupHandleList.mNode.mNext;
  v10 = (signed __int64)&v8[-1];
  if ( &v8[-1] == (UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *)v9 )
    return 1;
  while ( 1 )
  {
    v11 = *(AnimationGroup **)(v10 + 56);
    if ( !v11 || !AnimationGroup::IsStreamedIn(v11) )
      break;
    v10 = *(_QWORD *)(v10 + 24) - 16i64;
    if ( v10 == v9 )
      return 1;
  }
  return 0;
}

// File Line: 1033
// RVA: 0x57EEA0
UFG::InterestPointType *__fastcall UFG::InterestPoint::AddInterestPointType(UFG::qPropertySet *pInterestPointTypeProps)
{
  UFG::InterestPointType *v1; // rbx
  UFG::InterestPointType *result; // rax
  char *v3; // rax

  if ( UFG::InterestPoint::msInterestPointTypePool.size >= 0x1F4 )
  {
    v3 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&pInterestPointTypeProps->mName);
    UFG::qPrintf("WARNING: InterestPoint::AddInterestPointType: Pool is Full (%d) Not Adding (%s)\n", 500i64, v3);
    result = 0i64;
  }
  else
  {
    v1 = &UFG::InterestPoint::msInterestPointTypePool.p[UFG::InterestPoint::msInterestPointTypePool.size];
    ++UFG::InterestPoint::msInterestPointTypePool.size;
    UFG::InterestPointType::InitFromPropertySet(v1, pInterestPointTypeProps);
    UFG::qBaseTreeRB::Add(&UFG::InterestPoint::msInterestPointTypeTree.mTree, &v1->mNode);
    result = v1;
  }
  return result;
}

// File Line: 1060
// RVA: 0x58C790
void UFG::InterestPoint::StaticInit(void)
{
  UFG::qPropertySet *v0; // rbx
  UFG::qPropertyList *v1; // rax
  UFG::qPropertyList *v2; // r14
  unsigned int v3; // ebp
  unsigned int v4; // ebx
  UFG::qSymbol *v5; // rax
  UFG::qSymbol *v6; // rdi
  UFG::qPropertySet *v7; // rax
  UFG::qPropertySet *v8; // rsi
  char *v9; // rax
  char *v10; // rax
  char *v11; // rax
  char *v12; // rax
  UFG::qSymbol name; // [rsp+40h] [rbp+8h]
  UFG::qSymbol result; // [rsp+48h] [rbp+10h]

  UFG::qSymbol::create_from_string(&result, "config-InterestPointTypes");
  v0 = UFG::PropertySetManager::GetPropertySet(&result);
  if ( v0 )
  {
    UFG::qSymbol::create_from_string(&name, "types");
    v1 = UFG::qPropertySet::Get<UFG::qPropertyList>(v0, &name, DEPTH_RECURSE);
    v2 = v1;
    if ( v1 )
    {
      v3 = v1->mNumElements;
      v4 = 0;
      if ( v3 )
      {
        do
        {
          v5 = UFG::qPropertyList::Get<UFG::qSymbol>(v2, v4);
          v6 = v5;
          if ( v5 )
          {
            v7 = UFG::PropertySetManager::GetPropertySet(v5);
            v8 = v7;
            if ( v7 )
            {
              if ( UFG::InterestPoint::AddInterestPointType(v7) )
              {
                UFG::InterestPointProperties::AddToCache(v8, v6);
              }
              else
              {
                v9 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)v6);
                UFG::qPrintf("WARNING: InterestPoint::StaticInit: Pool is Full (%d) Not Adding (%s)\n", 500i64, v9);
              }
            }
            else
            {
              v10 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)v6);
              UFG::qPrintf("WARNING: InterestPoint::StaticInit: Interest Point Type Not Found: %s\n", v10);
            }
          }
          ++v4;
        }
        while ( v4 < v3 );
      }
    }
    else
    {
      v11 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&name);
      UFG::qPrintf("WARNING: InterestPoint::StaticInit: Property List Not Found: %s\n", v11);
    }
  }
  else
  {
    v12 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&result);
    UFG::qPrintf("WARNING: InterestPoint::StaticInit: Manifest File Not Found: %s\n", v12);
  }
}

// File Line: 1120
// RVA: 0x57D920
void __fastcall UFG::InterestPoint::~InterestPoint(UFG::InterestPoint *this)
{
  UFG::InterestPoint *v1; // rdi
  UFG::qSafePointerNode<UFG::ParkourHandle> *v2; // rbx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v3; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v4; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::InterestPointUserComponent> *v8; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v13; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v15; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::CharacterAnimationComponent> *v18; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v21; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v22; // rax
  UFG::GridIntrusiveNode<UFG::InterestPoint> *v23; // rdx
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint> *v24; // rcx
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint> *v25; // rax
  UFG::qList<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList,1,0> *v26; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v27; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v28; // rax
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList> *v29; // rdx
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList> *v30; // rcx
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList> *v31; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::InterestPoint::`vftable{for `UFG::MarkerBase};
  v2 = (UFG::qSafePointerNode<UFG::ParkourHandle> *)&this->vfptr;
  this->vfptr = (UFG::qSafePointerNode<UFG::InterestPoint>Vtbl *)&UFG::InterestPoint::`vftable{for `UFG::qSafePointerNode<UFG::InterestPoint>};
  v3 = &this->mLinkObject;
  if ( this->mLinkObject.m_pPointer )
  {
    v4 = v3->mPrev;
    v5 = v3->mNext;
    v4->mNext = v5;
    v5->mPrev = v4;
    v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->mPrev;
    v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  }
  v3->m_pPointer = 0i64;
  v6 = v3->mPrev;
  v7 = v3->mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  UFG::InterestPointPropertiesHandle::Set(&v1->mPropertiesHandle, 0i64, 1);
  v8 = &v1->mpInterestPointUserComponent;
  if ( v1->mpInterestPointUserComponent.m_pPointer )
  {
    v9 = v8->mPrev;
    v10 = v1->mpInterestPointUserComponent.mNext;
    v9->mNext = v10;
    v10->mPrev = v9;
    v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
    v1->mpInterestPointUserComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mpInterestPointUserComponent.mPrev;
  }
  v1->mpInterestPointUserComponent.m_pPointer = 0i64;
  v11 = v8->mPrev;
  v12 = v1->mpInterestPointUserComponent.mNext;
  v11->mNext = v12;
  v12->mPrev = v11;
  v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
  v1->mpInterestPointUserComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mpInterestPointUserComponent.mPrev;
  v13 = &v1->mpUser;
  if ( v1->mpUser.m_pPointer )
  {
    v14 = v13->mPrev;
    v15 = v1->mpUser.mNext;
    v14->mNext = v15;
    v15->mPrev = v14;
    v13->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v13->mPrev;
    v1->mpUser.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mpUser.mPrev;
  }
  v1->mpUser.m_pPointer = 0i64;
  v16 = v13->mPrev;
  v17 = v1->mpUser.mNext;
  v16->mNext = v17;
  v17->mPrev = v16;
  v13->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v13->mPrev;
  v1->mpUser.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mpUser.mPrev;
  v18 = &v1->mpParentCharacterAnimationComponent;
  if ( v1->mpParentCharacterAnimationComponent.m_pPointer )
  {
    v19 = v18->mPrev;
    v20 = v1->mpParentCharacterAnimationComponent.mNext;
    v19->mNext = v20;
    v20->mPrev = v19;
    v18->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v18->mPrev;
    v1->mpParentCharacterAnimationComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mpParentCharacterAnimationComponent.mPrev;
  }
  v1->mpParentCharacterAnimationComponent.m_pPointer = 0i64;
  v21 = v18->mPrev;
  v22 = v1->mpParentCharacterAnimationComponent.mNext;
  v21->mNext = v22;
  v22->mPrev = v21;
  v18->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v18->mPrev;
  v1->mpParentCharacterAnimationComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mpParentCharacterAnimationComponent.mPrev;
  `eh vector destructor iterator(
    v1->mAnimGroupHandles,
    0x18ui64,
    3,
    (void (__fastcall *)(void *))AnimationGroupHandleContainer::~AnimationGroupHandleContainer);
  v23 = (UFG::GridIntrusiveNode<UFG::InterestPoint> *)&v1->mPrev;
  v24 = v1->mPrev;
  v25 = v1->mNext;
  v24->mNext = v25;
  v25->mPrev = v24;
  v23->mPrev = (UFG::qNode<UFG::InterestPoint,UFG::InterestPoint> *)&v23->mPrev;
  v23->mNext = (UFG::qNode<UFG::InterestPoint,UFG::InterestPoint> *)&v23->mPrev;
  v2->vfptr = (UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *)&UFG::qSafePointerNode<UFG::InterestPoint>::`vftable;
  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull(v2);
  v26 = &v2->m_SafePointerList;
  UFG::qList<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList,1,0>::DeleteNodes(v26);
  v27 = v26->mNode.mPrev;
  v28 = v26->mNode.mNext;
  v27->mNext = v28;
  v28->mPrev = v27;
  v26->mNode.mPrev = &v26->mNode;
  v26->mNode.mNext = &v26->mNode;
  v29 = (UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList> *)&v1->mPrev;
  v30 = v1->mPrev;
  v31 = v1->mNext;
  v30->mNext = v31;
  v31->mPrev = v30;
  v29->mPrev = v29;
  v29->mNext = v29;
  UFG::MarkerBase::~MarkerBase((UFG::MarkerBase *)&v1->vfptr);
}

// File Line: 1126
// RVA: 0x5836B0
void UFG::InterestPoint::InitGrid(void)
{
  UFG::GridIntrusive<UFG::InterestPoint> *v0; // rbx
  float y_max; // xmm8_4
  float v2; // xmm7_4
  float v3; // xmm6_4
  float v4; // xmm1_4
  UFG::GridIntrusive<UFG::InterestPoint> *v5; // rbx
  float v6; // xmm8_4
  float v7; // xmm7_4
  float v8; // xmm6_4
  float v9; // xmm1_4

  v0 = (UFG::GridIntrusive<UFG::InterestPoint> *)UFG::qMalloc(0x30ui64, "GridIntrusive<InterestPoint>", 0i64);
  if ( v0 )
  {
    y_max = UFG::GetWorldExtents_max()->y;
    v2 = UFG::GetWorldExtents_max()->x;
    v3 = UFG::GetWorldExtents_min()->y;
    v4 = UFG::GetWorldExtents_min()->x;
    v0->mGridNodes = 0i64;
    UFG::GridIntrusive<UFG::InterestPoint>::Init(v0, v4, v3, v2, y_max, 50.0);
  }
  else
  {
    v0 = 0i64;
  }
  UFG::InterestPoint::mspUseInterestPointGrid = v0;
  v5 = (UFG::GridIntrusive<UFG::InterestPoint> *)UFG::qMalloc(0x30ui64, "GridIntrusive<InterestPoint>", 0i64);
  if ( v5 )
  {
    v6 = UFG::GetWorldExtents_max()->y;
    v7 = UFG::GetWorldExtents_max()->x;
    v8 = UFG::GetWorldExtents_min()->y;
    v9 = UFG::GetWorldExtents_min()->x;
    v5->mGridNodes = 0i64;
    UFG::GridIntrusive<UFG::InterestPoint>::Init(v5, v9, v8, v7, v6, 300.0);
    UFG::InterestPoint::mspLookInterestPointGrid = v5;
  }
  else
  {
    UFG::InterestPoint::mspLookInterestPointGrid = 0i64;
  }
}

// File Line: 1134
// RVA: 0x580B10
void UFG::InterestPoint::DeleteGrid(void)
{
  if ( UFG::InterestPoint::mspLookInterestPointGrid )
    operator delete[](UFG::InterestPoint::mspLookInterestPointGrid);
  if ( UFG::InterestPoint::mspUseInterestPointGrid )
    operator delete[](UFG::InterestPoint::mspUseInterestPointGrid);
  UFG::InterestPoint::mspUseInterestPointGrid = 0i64;
  UFG::InterestPoint::mspLookInterestPointGrid = 0i64;
}

// File Line: 1146
// RVA: 0x586C40
void __fastcall UFG::InterestPoint::OnDetach(UFG::InterestPoint *this)
{
  UFG::InterestPoint *v1; // rbx
  UFG::GridIntrusive<UFG::InterestPoint> *v2; // r8
  UFG::GridIntrusiveNode<UFG::InterestPoint> *v3; // rdx
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint> *v4; // rcx
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint> *v5; // rax
  UFG::InterestPointProperties *v6; // rax
  UFG::SimObject *v7; // rax
  UFG::SceneObjectProperties *v8; // rdi
  UFG::PedSpawnManager *v9; // rax
  UFG::qTreeRB<UFG::InterestPoint,UFG::InterestPoint,1> *v10; // rcx
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList> *v11; // rdx
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList> *v12; // rcx
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList> *v13; // rax

  v1 = this;
  if ( this->mAddedToGrid )
  {
    UFG::InterestPoint::GetPosition(this);
    v2 = UFG::InterestPoint::mspUseInterestPointGrid;
    if ( v1->mPoiType.mUID == qSymbol_look.mUID )
      v2 = UFG::InterestPoint::mspLookInterestPointGrid;
    if ( v2 )
    {
      v3 = (UFG::GridIntrusiveNode<UFG::InterestPoint> *)&v1->mPrev;
      v4 = v1->mPrev;
      v5 = v1->mNext;
      v4->mNext = v5;
      v5->mPrev = v4;
      v3->mPrev = (UFG::qNode<UFG::InterestPoint,UFG::InterestPoint> *)&v3->mPrev;
      v3->mNext = (UFG::qNode<UFG::InterestPoint,UFG::InterestPoint> *)&v3->mPrev;
      --v2->mNodeCount;
      *(_WORD *)&v1->mAddedToGrid = 256;
    }
  }
  v6 = v1->mPropertiesHandle.mProperties;
  if ( v6 && v6->mSpawnAmbientUserDistance > 0.0 )
  {
    v7 = v1->m_pSimObject;
    if ( v7 )
      v8 = v7->m_pSceneObj;
    else
      v8 = 0i64;
    v9 = UFG::PedSpawnManager::GetInstance();
    UFG::PedSpawnManager::UnRegisterSpawningPOI(v9, v1, v8);
  }
  if ( v1->mIsReserved )
    UFG::InterestPoint::EndReservation(v1);
  v10 = &UFG::InterestPoint::msLookInterestPoints;
  if ( v1->mPoiType.mUID != qSymbol_look.mUID )
    v10 = &UFG::InterestPoint::msUseInterestPoints;
  UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
    (UFG::qBaseTreeVariableRB<unsigned __int64> *)v10,
    (UFG::qBaseNodeVariableRB<unsigned __int64> *)&v1->mNode);
  v1->mFullUpdateRequired = 0;
  v11 = (UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList> *)&v1->mPrev;
  v12 = v1->mPrev;
  v13 = v1->mNext;
  v12->mNext = v13;
  v13->mPrev = v12;
  v11->mPrev = v11;
  v11->mNext = v11;
  v1->mOnDetachCalled = 1;
  UFG::InterestPoint::UpdateAnimHandles(v1);
}

// File Line: 1205
// RVA: 0x582910
float __fastcall UFG::InterestPoint::GetRawAppeal(UFG::InterestPoint *this)
{
  return this->mPropertiesHandle.mProperties->mAppeal;
}

// File Line: 1210
// RVA: 0x58CA40
void __fastcall UFG::InterestPoint::TeleportEventHandler(UFG::InterestPoint *this, UFG::Event *this_event)
{
  UFG::GridIntrusive<UFG::InterestPoint> *v2; // r8
  UFG::InterestPoint *v3; // r9
  int v4; // er10
  UFG::GridIntrusiveNode<UFG::InterestPoint> *v5; // rdx
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint> *v6; // rcx
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint> *v7; // rax
  UFG::qList<UFG::InterestPoint,UFG::InterestPoint,1,0> *v8; // rcx
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint> *v9; // rax

  this->mIsPositionCached = 0;
  v2 = UFG::InterestPoint::mspUseInterestPointGrid;
  v3 = this;
  if ( this->mPoiType.mUID == qSymbol_look.mUID )
    v2 = UFG::InterestPoint::mspLookInterestPointGrid;
  if ( v2 && this->mAddedToGrid && !this->mRemovedFromGrid )
  {
    v4 = (signed int)(float)((float)(*(float *)&this_event[2].mNext - v2->mXMin) * v2->mGridSizeInv)
       + v2->mXDim * (signed int)(float)((float)(*((float *)&this_event[2].mNext + 1) - v2->mYMin) * v2->mGridSizeInv);
    if ( v4 != this->mGridIndex )
    {
      v5 = (UFG::GridIntrusiveNode<UFG::InterestPoint> *)&this->mPrev;
      v6 = this->mPrev;
      v7 = v5->mNext;
      v6->mNext = v7;
      v7->mPrev = v6;
      v5->mPrev = (UFG::qNode<UFG::InterestPoint,UFG::InterestPoint> *)&v5->mPrev;
      v5->mNext = (UFG::qNode<UFG::InterestPoint,UFG::InterestPoint> *)&v5->mPrev;
      --v2->mNodeCount;
      v8 = &v2->mGridNodes[v4];
      v9 = v8->mNode.mPrev;
      v9->mNext = (UFG::qNode<UFG::InterestPoint,UFG::InterestPoint> *)&v5->mPrev;
      v5->mPrev = v9;
      v5->mNext = &v8->mNode;
      v8->mNode.mPrev = (UFG::qNode<UFG::InterestPoint,UFG::InterestPoint> *)&v5->mPrev;
      ++v2->mNodeCount;
      v3->mGridIndex = v4;
    }
  }
}

// File Line: 1287
// RVA: 0x582920
_BOOL8 __fastcall UFG::InterestPoint::GetRequiresSync(UFG::InterestPoint *this)
{
  return this->mPropertiesHandle.mProperties->mRequiresSync;
}

// File Line: 1293
// RVA: 0x5828E0
_BOOL8 __fastcall UFG::InterestPoint::GetPositionSyncRequired(UFG::InterestPoint *this)
{
  return this->mPropertiesHandle.mProperties->mPositionSyncRequired;
}

// File Line: 1299
// RVA: 0x582930
_BOOL8 __fastcall UFG::InterestPoint::GetRotationSyncRequired(UFG::InterestPoint *this)
{
  return this->mPropertiesHandle.mProperties->mRotationSyncRequired;
}

// File Line: 1306
// RVA: 0x5823A0
_BOOL8 __fastcall UFG::InterestPoint::GetAllowSocialInteraction(UFG::InterestPoint *this)
{
  return this->mPropertiesHandle.mProperties->mAllowSocialInteraction;
}

// File Line: 1312
// RVA: 0x5828F0
__int64 __fastcall UFG::InterestPoint::GetPriority(UFG::InterestPoint *this)
{
  __int64 result; // rax

  if ( this->mOnDetachCalled )
    result = 0i64;
  else
    result = (unsigned int)this->mPropertiesHandle.mProperties->mPriority;
  return result;
}

// File Line: 1319
// RVA: 0x584100
_BOOL8 __fastcall UFG::InterestPoint::IsAutoInteractable(UFG::InterestPoint *this)
{
  return this->mPropertiesHandle.mProperties->mIsAutoInteractable;
}

// File Line: 1325
// RVA: 0x591B60
bool __fastcall UFG::InterestPoint::WantsToResume(UFG::InterestPoint *this, bool *allowNoInterruptResume)
{
  UFG::InterestPointProperties *v2; // r9
  bool v3; // r8
  bool result; // al

  v2 = this->mPropertiesHandle.mProperties;
  v3 = v2->mResumeIfInterrupted;
  result = v3 && this->mIsReserved && (this->mIsInterrupted || !this->mIsCompleted);
  *allowNoInterruptResume = !v2->mInitialUseOnly || v3;
  return result;
}

// File Line: 1341
// RVA: 0x5853F0
bool __fastcall UFG::InterestPoint::IsReservationMatch(UFG::InterestPoint *this, unsigned int matchReservationFlags, UFG::InterestPoint::eReserveReason reserveReason)
{
  bool result; // al

  result = 0;
  if ( matchReservationFlags & 1 )
    result = this->mIsReserved != 0;
  if ( matchReservationFlags & 2 && (result || this->mIsInUse) )
    result = 1;
  if ( matchReservationFlags & 0x10 && (result || this->mIsCompleted) )
    result = 1;
  if ( matchReservationFlags & 4 && (result || this->mCooldownTime > this->mTimeSinceFinished) )
    result = 1;
  if ( matchReservationFlags & 8 )
    result = result
          || !this->mIsReserved
          && this->mActive
          && (this->mCooldownTime <= this->mTimeSinceFinished || reserveReason == 2);
  return result;
}

// File Line: 1401
// RVA: 0x5822A0
char __fastcall UFG::InterestPoint::ForceUser(UFG::InterestPoint *this, UFG::SimObject *pUser)
{
  UFG::SimObject *v2; // rdi
  UFG::InterestPoint *v3; // rbx

  v2 = pUser;
  v3 = this;
  if ( this->mpUser.m_pPointer )
    UFG::InterestPoint::EndReservation(this);
  return UFG::InterestPoint::BeginReservation(v3, v2, ReserveReason_normal);
}

// File Line: 1415
// RVA: 0x58BA60
void __fastcall UFG::InterestPoint::SetUser(UFG::InterestPoint *this, UFG::SimObject *pUser)
{
  UFG::InterestPoint *v2; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v3; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v4; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax
  unsigned __int16 v7; // cx
  UFG::SimComponent *v8; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::InterestPointUserComponent> *v9; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v13; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v15; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::InterestPointUserComponent> *v16; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rax

  v2 = this;
  if ( pUser )
  {
    v3 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->mpUser.mPrev;
    if ( this->mpUser.m_pPointer )
    {
      v4 = v3->mPrev;
      v5 = this->mpUser.mNext;
      v4->mNext = v5;
      v5->mPrev = v4;
      v3->mPrev = v3;
      this->mpUser.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->mpUser.mPrev;
    }
    this->mpUser.m_pPointer = pUser;
    v6 = pUser->m_SafePointerList.mNode.mPrev;
    v6->mNext = v3;
    v3->mPrev = v6;
    this->mpUser.mNext = &pUser->m_SafePointerList.mNode;
    pUser->m_SafePointerList.mNode.mPrev = v3;
    v7 = pUser->m_Flags;
    if ( (v7 >> 14) & 1 )
    {
      v8 = pUser->m_Components.p[43].m_pComponent;
    }
    else if ( (v7 & 0x8000u) == 0 )
    {
      if ( (v7 >> 13) & 1 )
      {
        v8 = pUser->m_Components.p[12].m_pComponent;
      }
      else if ( (v7 >> 12) & 1 )
      {
        v8 = 0i64;
      }
      else
      {
        v8 = UFG::SimObject::GetComponentOfType(pUser, UFG::InterestPointUserComponent::_TypeUID);
      }
    }
    else
    {
      v8 = 0i64;
    }
    v9 = &v2->mpInterestPointUserComponent;
    if ( v2->mpInterestPointUserComponent.m_pPointer )
    {
      v10 = v9->mPrev;
      v11 = v2->mpInterestPointUserComponent.mNext;
      v10->mNext = v11;
      v11->mPrev = v10;
      v9->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
      v2->mpInterestPointUserComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mpInterestPointUserComponent.mPrev;
    }
    v2->mpInterestPointUserComponent.m_pPointer = v8;
    if ( v8 )
    {
      v12 = v8->m_SafePointerList.mNode.mPrev;
      v12->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
      v9->mPrev = v12;
      v2->mpInterestPointUserComponent.mNext = &v8->m_SafePointerList.mNode;
      v8->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
    }
  }
  else
  {
    v13 = &this->mpUser;
    if ( this->mpUser.m_pPointer )
    {
      v14 = v13->mPrev;
      v15 = v13->mNext;
      v14->mNext = v15;
      v15->mPrev = v14;
      v13->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v13->mPrev;
      v13->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v13->mPrev;
    }
    v13->m_pPointer = 0i64;
    v16 = &v2->mpInterestPointUserComponent;
    if ( v2->mpInterestPointUserComponent.m_pPointer )
    {
      v17 = v16->mPrev;
      v18 = v2->mpInterestPointUserComponent.mNext;
      v17->mNext = v18;
      v18->mPrev = v17;
      v16->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v16->mPrev;
      v2->mpInterestPointUserComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mpInterestPointUserComponent.mPrev;
    }
    v2->mpInterestPointUserComponent.m_pPointer = 0i64;
  }
}

// File Line: 1433
// RVA: 0x57F470
char __fastcall UFG::InterestPoint::BeginReservation(UFG::InterestPoint *this, UFG::SimObject *pUser, UFG::InterestPoint::eReserveReason reserveReason)
{
  char v3; // si
  UFG::SimObject *v4; // rdi
  UFG::InterestPoint *v5; // rbx
  unsigned __int16 v7; // cx
  UFG::qSymbol *v8; // rax

  v3 = reserveReason;
  v4 = pUser;
  v5 = this;
  if ( !pUser )
    return 0;
  UFG::InterestPoint::SetUser(this, pUser);
  v5->mIsReserved = 1;
  v5->mReserveReason.mValue = v3;
  if ( v5->mPoiType.mUID != qSymbol_look.mUID && v5->mpUser.m_pPointer )
  {
    v7 = v4->m_Flags;
    if ( (v7 >> 14) & 1 )
    {
      v8 = (UFG::qSymbol *)v4->m_Components.p[43].m_pComponent;
      goto LABEL_12;
    }
    if ( (v7 & 0x8000u) == 0 )
    {
      if ( (v7 >> 13) & 1 )
      {
        v8 = (UFG::qSymbol *)v4->m_Components.p[12].m_pComponent;
        goto LABEL_12;
      }
      if ( !((v7 >> 12) & 1) )
      {
        v8 = (UFG::qSymbol *)UFG::SimObject::GetComponentOfType(v4, UFG::InterestPointUserComponent::_TypeUID);
LABEL_12:
        if ( v8 )
        {
          v8[138].mUID = UFG::gNullQSymbol.mUID;
          v8[139].mUID = UFG::gNullQSymbol.mUID;
        }
        goto LABEL_14;
      }
    }
  }
LABEL_14:
  if ( v5->mOnReservationScriptInfo.mHasScript )
  {
    if ( !v5->mOnReservationScriptInfo.mScriptFired )
      UFG::InterestPoint::StartScript(v5, &v5->mOnReservationScriptInfo);
  }
  return 1;
}

// File Line: 1471
// RVA: 0x580C30
void __fastcall UFG::InterestPoint::EndReservation(UFG::InterestPoint *this)
{
  UFG::InterestPoint *v1; // rbx
  unsigned int v2; // edx
  UFG::SimComponent *v3; // rcx
  UFG::InterestPointType *v4; // rax
  UFG::SimObjectCVBase *v5; // rcx
  unsigned __int16 v6; // dx
  UFG::ActiveAIEntityComponent *v7; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v8; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::InterestPointUserComponent> *v11; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rax

  v1 = this;
  UFG::InterestPoint::FinishUsing(this);
  v2 = v1->mPoiType.mUID;
  if ( v2 != qSymbol_look.mUID && v1->mpUser.m_pPointer )
  {
    v3 = v1->mpInterestPointUserComponent.m_pPointer;
    if ( v3 )
    {
      v4 = v1->mInterestPointType;
      LODWORD(v3[8].m_pSimObject) = v2;
      HIDWORD(v3[8].m_pSimObject) = v4->mDescription.mUID;
    }
    v5 = (UFG::SimObjectCVBase *)v1->mpUser.m_pPointer;
    if ( v5 )
    {
      v6 = v5->m_Flags;
      if ( (v6 >> 14) & 1 )
      {
        v7 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v5);
      }
      else if ( (v6 & 0x8000u) == 0 )
      {
        if ( (v6 >> 13) & 1 )
          v7 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)&v5->vfptr,
                                                 UFG::ActiveAIEntityComponent::_TypeUID);
        else
          v7 = (UFG::ActiveAIEntityComponent *)((v6 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                   (UFG::SimObjectGame *)&v5->vfptr,
                                                                   UFG::ActiveAIEntityComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v5->vfptr, UFG::ActiveAIEntityComponent::_TypeUID));
      }
      else
      {
        v7 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v5);
      }
      if ( v7 )
        UFG::ActiveAIEntityComponent::RestartPoiCooldown(v7);
    }
  }
  v8 = &v1->mpUser;
  if ( v1->mpUser.m_pPointer )
  {
    v9 = v8->mPrev;
    v10 = v1->mpUser.mNext;
    v9->mNext = v10;
    v10->mPrev = v9;
    v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v8->mPrev;
    v1->mpUser.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mpUser.mPrev;
  }
  v1->mpUser.m_pPointer = 0i64;
  v11 = &v1->mpInterestPointUserComponent;
  if ( v1->mpInterestPointUserComponent.m_pPointer )
  {
    v12 = v11->mPrev;
    v13 = v1->mpInterestPointUserComponent.mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    v11->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v11->mPrev;
    v1->mpInterestPointUserComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mpInterestPointUserComponent.mPrev;
  }
  v1->mpInterestPointUserComponent.m_pPointer = 0i64;
  *(_DWORD *)&v1->mIsInUse = 0;
  v1->mIsTimedOut = 0;
  v1->mIsReserved = 0;
  v1->mOnReservationScriptInfo.mScriptFired = 0;
}

// File Line: 1504
// RVA: 0x57F570
void __fastcall UFG::InterestPoint::BeginUsing(UFG::InterestPoint *this)
{
  UFG::InterestPointProperties *v1; // rax
  UFG::InterestPoint *v2; // rbx
  float v3; // xmm0_4
  UFG::InterestPointProperties *v4; // rax
  float v5; // xmm0_4

  v1 = this->mPropertiesHandle.mProperties;
  this->mIsInUse = 1;
  v2 = this;
  v3 = UFG::GetRandomNumberInRange(v1->mUseTimeMin, v1->mUseTimeMax);
  v4 = v2->mPropertiesHandle.mProperties;
  v2->mUseTime = v3;
  v5 = UFG::GetRandomNumberInRange(v4->mCoolDownTimeMin, v4->mCoolDownTimeMax);
  v2->mFullUpdateRequired = 1;
  v2->mBeginningScriptInfo.mScriptFired = 0;
  v2->mEndingScriptInfo.mScriptFired = 0;
  *(_QWORD *)&v2->mTimeSinceBeginUse = 0i64;
  v2->mCooldownTime = v5;
  if ( v2->mBeginningScriptInfo.mHasScript )
    UFG::InterestPoint::StartScript(v2, &v2->mBeginningScriptInfo);
}

// File Line: 1524
// RVA: 0x58FBD0
void __fastcall UFG::InterestPoint::UpdateInterestPointTransform(UFG::InterestPoint *this)
{
  UFG::InterestPoint *v1; // rbx
  UFG::SimComponent *v2; // rax
  Creature *v3; // rcx
  float v4; // xmm1_4
  float v5; // xmm0_4
  UFG::qMatrix44 transform; // [rsp+20h] [rbp-48h]

  v1 = this;
  if ( this->mBoneId >= 0 || this->mNeedsBoneFixupWhenRigAvailable )
  {
    v2 = this->mpParentCharacterAnimationComponent.m_pPointer;
    if ( v2 )
    {
      if ( *(_QWORD *)&v2[2].m_TypeUID && !BYTE1(v2[3].vfptr) && *(_QWORD *)&v2[1].m_Flags )
      {
        if ( this->mNeedsBoneFixupWhenRigAvailable )
          UFG::InterestPoint::SetBoneIDFromProperties(this);
        v3 = *(Creature **)&v1->mpParentCharacterAnimationComponent.m_pPointer[2].m_TypeUID;
        if ( v3 )
        {
          Creature::GetTransform(v3, v1->mBoneId, &transform);
          UFG::TransformNodeComponent::SetWorldTransform(v1->mpXformNode, &transform);
          v4 = transform.v3.y;
          v1->mCachedPosition.x = transform.v3.x;
          v5 = transform.v3.z;
          v1->mCachedPosition.y = v4;
          v1->mCachedPosition.z = v5;
        }
      }
    }
  }
}

// File Line: 1593
// RVA: 0x58FC90
void __fastcall UFG::InterestPoint::UpdateInterestPoints(float deltaTime)
{
  unsigned int v1; // er14
  UFG::SimObjectCharacter *v2; // rax
  UFG::SimComponent *v3; // rbp
  UFG::qVector3 *v4; // rax
  float v5; // xmm7_4
  float v6; // xmm8_4
  float v7; // xmm9_4
  Render::SkinningCacheNode *v8; // rax
  UFG::InterestPoint *v9; // rbx
  UFG::qBaseNodeRB *v10; // rdx
  UFG::SimComponentHolder *v11; // rax
  UFG::qBaseTreeRB *v12; // rax
  signed __int64 v13; // rdi
  UFG::qVector3 *v14; // rax
  UFG::GridIntrusive<UFG::InterestPoint> *v15; // rdx
  int v16; // er9
  UFG::GridIntrusiveNode<UFG::InterestPoint> *v17; // r8
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint> *v18; // rcx
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint> *v19; // rax
  UFG::GridIntrusive<UFG::InterestPoint> *v20; // rdx
  UFG::qList<UFG::InterestPoint,UFG::InterestPoint,1,0> *v21; // rcx
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint> *v22; // rax
  Render::SkinningCacheNode *v23; // rax
  signed __int64 v24; // rdi
  UFG::qBaseNodeRB *v25; // rdx
  UFG::qBaseTreeRB *v26; // rax
  signed __int64 v27; // rsi
  _DWORD *v28; // rbx
  float v29; // xmm0_4
  unsigned int v30; // eax
  UFG::GridIntrusive<UFG::InterestPoint> *v31; // r9
  UFG::GridIntrusive<UFG::InterestPoint> *v32; // r8
  UFG::GridIntrusive<UFG::InterestPoint> *v33; // rdx
  int v34; // er10
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint> *v35; // r8
  _QWORD *v36; // rax
  __int64 v37; // rcx
  UFG::GridIntrusive<UFG::InterestPoint> *v38; // rdx
  UFG::qList<UFG::InterestPoint,UFG::InterestPoint,1,0> *v39; // rcx
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint> *v40; // rax
  bool v41; // zf
  _QWORD *v42; // rdx
  __int64 v43; // rcx
  _QWORD *v44; // rax
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint> **v45; // rcx
  int v46; // er8
  UFG::qList<UFG::InterestPoint,UFG::InterestPoint,1,0> *v47; // rdx
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint> *v48; // rax

  v1 = UFG::Metrics::msInstance.mSimFrameCount;
  UFG::GetLocalPlayer();
  v2 = UFG::GetLocalPlayer();
  if ( v2 )
  {
    v11 = v2->m_Components.p;
    v3 = v11[2].m_pComponent;
    if ( v3 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v11[2].m_pComponent);
      v4 = (UFG::qVector3 *)&v3[2].m_BoundComponentHandles;
      goto LABEL_4;
    }
  }
  else
  {
    v3 = 0i64;
  }
  v4 = &UFG::qVector3::msZero;
LABEL_4:
  v5 = v4->x;
  v6 = v4->y;
  v7 = v4->z;
  v8 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::InterestPoint::msLookInterestPoints);
  if ( v8 )
  {
    v9 = (UFG::InterestPoint *)&v8[-4].mNode.mUID;
    if ( v8 != (Render::SkinningCacheNode *)136 )
    {
      do
      {
        if ( v9 )
          v10 = &v9->mNode;
        else
          v10 = 0i64;
        v12 = UFG::qBaseTreeRB::GetNext(&UFG::InterestPoint::msLookInterestPoints.mTree, v10);
        if ( v12 )
          v13 = (signed __int64)v12[-2].mRoot.mChild;
        else
          v13 = 0i64;
        if ( v1 + v9->m_NameUID == 120 * ((v1 + v9->m_NameUID) / 0x78) )
        {
          if ( v9->mAddedToGrid )
          {
            if ( !v9->mRemovedFromGrid )
            {
              v14 = UFG::InterestPoint::GetPosition(v9);
              v15 = UFG::InterestPoint::mspLookInterestPointGrid;
              v16 = (signed int)(float)((float)(v14->x - UFG::InterestPoint::mspLookInterestPointGrid->mXMin)
                                      * UFG::InterestPoint::mspLookInterestPointGrid->mGridSizeInv)
                  + UFG::InterestPoint::mspLookInterestPointGrid->mXDim
                  * (signed int)(float)((float)(v14->y - UFG::InterestPoint::mspLookInterestPointGrid->mYMin)
                                      * UFG::InterestPoint::mspLookInterestPointGrid->mGridSizeInv);
              if ( v16 != v9->mGridIndex )
              {
                v17 = (UFG::GridIntrusiveNode<UFG::InterestPoint> *)&v9->mPrev;
                v18 = v9->mPrev;
                v19 = v9->mNext;
                v18->mNext = v19;
                v19->mPrev = v18;
                --v15->mNodeCount;
                v20 = UFG::InterestPoint::mspLookInterestPointGrid;
                v21 = &UFG::InterestPoint::mspLookInterestPointGrid->mGridNodes[v16];
                v17->mNext = &v21->mNode;
                v22 = v21->mNode.mPrev;
                v17->mPrev = v21->mNode.mPrev;
                v9->mGridIndex = v16;
                v22->mNext = (UFG::qNode<UFG::InterestPoint,UFG::InterestPoint> *)&v9->mPrev;
                v21->mNode.mPrev = (UFG::qNode<UFG::InterestPoint,UFG::InterestPoint> *)&v9->mPrev;
                ++v20->mNodeCount;
              }
            }
          }
        }
        v9 = (UFG::InterestPoint *)v13;
      }
      while ( v13 );
    }
  }
  v23 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::InterestPoint::msUseInterestPoints);
  if ( v23 )
  {
    v24 = (signed __int64)&v23[-4].mNode.mUID;
    if ( v23 != (Render::SkinningCacheNode *)136 )
    {
      while ( 1 )
      {
        if ( v24 )
          v25 = (UFG::qBaseNodeRB *)(v24 + 136);
        else
          v25 = 0i64;
        v26 = UFG::qBaseTreeRB::GetNext(&UFG::InterestPoint::msUseInterestPoints.mTree, v25);
        if ( v26 )
          v27 = (signed __int64)v26[-2].mRoot.mChild;
        else
          v27 = 0i64;
        if ( *(_DWORD *)(v24 + 320) < 0 && !*(_BYTE *)(v24 + 440)
          || v1 + *(_DWORD *)(v24 + 28) != 60 * ((v1 + *(_DWORD *)(v24 + 28)) / 0x3C) )
        {
          goto LABEL_56;
        }
        UFG::InterestPoint::UpdateInterestPointTransform((UFG::InterestPoint *)v24);
        if ( !*(_BYTE *)(v24 + 316) )
        {
          v28 = *(_DWORD **)(v24 + 104);
          UFG::TransformNodeComponent::UpdateWorldTransform(*(UFG::TransformNodeComponent **)(v24 + 104));
          *(_DWORD *)(v24 + 304) = v28[44];
          *(_DWORD *)(v24 + 308) = v28[45];
          *(_DWORD *)(v24 + 312) = v28[46];
          *(_BYTE *)(v24 + 316) = 1;
        }
        if ( v3 )
        {
          v29 = *(float *)(v24 + 292);
          if ( v29 >= (float)((float)((float)((float)(v6 - *(float *)(v24 + 308)) * (float)(v6 - *(float *)(v24 + 308)))
                                    + (float)((float)(v5 - *(float *)(v24 + 304)) * (float)(v5 - *(float *)(v24 + 304))))
                            + (float)((float)(v7 - *(float *)(v24 + 312)) * (float)(v7 - *(float *)(v24 + 312)))) )
            v29 = (float)((float)((float)(v6 - *(float *)(v24 + 308)) * (float)(v6 - *(float *)(v24 + 308)))
                        + (float)((float)(v5 - *(float *)(v24 + 304)) * (float)(v5 - *(float *)(v24 + 304))))
                + (float)((float)(v7 - *(float *)(v24 + 312)) * (float)(v7 - *(float *)(v24 + 312)));
          *(float *)(v24 + 292) = v29;
          UFG::InterestPoint::UpdateAnimHandles((UFG::InterestPoint *)v24);
        }
        if ( !*(_BYTE *)(v24 + 356) || *(_BYTE *)(v24 + 357) )
          goto LABEL_46;
        v30 = qSymbol_look.mUID;
        v31 = UFG::InterestPoint::mspUseInterestPointGrid;
        v32 = UFG::InterestPoint::mspLookInterestPointGrid;
        v33 = UFG::InterestPoint::mspUseInterestPointGrid;
        if ( *(_DWORD *)(v24 + 300) == qSymbol_look.mUID )
          v33 = UFG::InterestPoint::mspLookInterestPointGrid;
        v34 = (signed int)(float)((float)(*(float *)(v24 + 304) - v33->mXMin) * v33->mGridSizeInv)
            + v33->mXDim * (signed int)(float)((float)(*(float *)(v24 + 308) - v33->mYMin) * v33->mGridSizeInv);
        if ( v34 >= 0 && v34 != *(_DWORD *)(v24 + 352) )
          break;
LABEL_47:
        if ( *(_QWORD *)(v24 + 536) )
        {
          if ( !*(_BYTE *)(v24 + 356) )
            goto LABEL_53;
          v41 = *(_DWORD *)(v24 + 300) == v30;
          v42 = (_QWORD *)(v24 + 184);
          v43 = *(_QWORD *)(v24 + 184);
          v44 = *(_QWORD **)(v24 + 192);
          *v42 = v42;
          *(_QWORD *)(v43 + 8) = v44;
          v42[1] = v42;
          if ( v41 )
            v31 = v32;
          *v44 = v43;
          --v31->mNodeCount;
          *(_WORD *)(v24 + 356) = 256;
          *(_DWORD *)(v24 + 352) = -1;
        }
        else if ( !*(_BYTE *)(v24 + 356) )
        {
LABEL_53:
          if ( *(_DWORD *)(v24 + 300) == v30 )
            v31 = v32;
          v45 = (UFG::qNode<UFG::InterestPoint,UFG::InterestPoint> **)(v24 + 184);
          v46 = (signed int)(float)((float)(*(float *)(v24 + 304) - v31->mXMin) * v31->mGridSizeInv)
              + v31->mXDim * (signed int)(float)((float)(*(float *)(v24 + 308) - v31->mYMin) * v31->mGridSizeInv);
          v47 = &v31->mGridNodes[v46];
          v45[1] = &v47->mNode;
          v48 = v47->mNode.mPrev;
          *v45 = v47->mNode.mPrev;
          *(_DWORD *)(v24 + 352) = v46;
          *(_WORD *)(v24 + 356) = 1;
          v48->mNext = (UFG::qNode<UFG::InterestPoint,UFG::InterestPoint> *)(v24 + 184);
          v47->mNode.mPrev = (UFG::qNode<UFG::InterestPoint,UFG::InterestPoint> *)(v24 + 184);
          ++v31->mNodeCount;
          goto LABEL_56;
        }
LABEL_56:
        if ( *(_BYTE *)(v24 + 358) )
          *(_BYTE *)(v24 + 358) = (*(unsigned __int8 (__fastcall **)(signed __int64))(*(_QWORD *)v24 + 136i64))(v24) == 0;
        UFG::InterestPoint::UpdateReservation((UFG::InterestPoint *)v24);
        v24 = v27;
        if ( !v27 )
          return;
      }
      v35 = (UFG::qNode<UFG::InterestPoint,UFG::InterestPoint> *)(v24 + 184);
      v36 = *(_QWORD **)(v24 + 192);
      v37 = *(_QWORD *)(v24 + 184);
      v35->mPrev = v35;
      *(_QWORD *)(v37 + 8) = v36;
      *v36 = v37;
      --v33->mNodeCount;
      LODWORD(v36) = qSymbol_look;
      v38 = UFG::InterestPoint::mspUseInterestPointGrid;
      v35->mNext = v35;
      if ( *(_DWORD *)(v24 + 300) == (_DWORD)v36 )
        v38 = UFG::InterestPoint::mspLookInterestPointGrid;
      v39 = &v38->mGridNodes[v34];
      *(_QWORD *)(v24 + 192) = v39;
      v40 = v39->mNode.mPrev;
      v35->mPrev = v39->mNode.mPrev;
      *(_DWORD *)(v24 + 352) = v34;
      v40->mNext = v35;
      v39->mNode.mPrev = v35;
      ++v38->mNodeCount;
LABEL_46:
      v31 = UFG::InterestPoint::mspUseInterestPointGrid;
      v30 = qSymbol_look.mUID;
      v32 = UFG::InterestPoint::mspLookInterestPointGrid;
      goto LABEL_47;
    }
  }
}

// File Line: 1795
// RVA: 0x590A20
void __fastcall UFG::InterestPoint::UpdateReservation(UFG::InterestPoint *this)
{
  UFG::SimObject *v1; // rdx
  UFG::InterestPoint *v2; // rbx
  UFG::qVector3 *v3; // rax
  UFG::qVector3 result; // [rsp+20h] [rbp-18h]

  v1 = this->mpUser.m_pPointer;
  v2 = this;
  if ( v1 && this->mReserveReason.mValue == 2 && this->mIsReserved && !*(_WORD *)&this->mIsInUse )
  {
    UFG::GetPosition(&result, v1);
    v3 = UFG::InterestPoint::GetPosition(v2);
    if ( (float)((float)((float)((float)(result.y - v3->y) * (float)(result.y - v3->y))
                       + (float)((float)(result.x - v3->x) * (float)(result.x - v3->x)))
               + (float)((float)(result.z - v3->z) * (float)(result.z - v3->z))) > (float)(v2->mPropertiesHandle.mProperties->mMaxAppealRadius
                                                                                         * v2->mPropertiesHandle.mProperties->mMaxAppealRadius) )
      UFG::InterestPoint::EndReservation(v2);
  }
}

// File Line: 1814
// RVA: 0x587760
bool __fastcall UFG::InterestPoint::OnUpdate(UFG::InterestPoint *this, float deltaTime)
{
  UFG::InterestPoint *v2; // rbx
  bool v3; // al
  UFG::SimComponent *v4; // rdx
  char v5; // cl
  float v6; // xmm0_4
  float v7; // xmm1_4
  bool isPlayingOpeningBranch; // [rsp+58h] [rbp+10h]

  v2 = this;
  isPlayingOpeningBranch = 0;
  v3 = this->mTimeSinceBeginUse != 0.0 && UFG::InterestPoint::CheckOutsideForInteruption(this, &isPlayingOpeningBranch);
  v4 = v2->mpInterestPointUserComponent.m_pPointer;
  v5 = 1;
  if ( v4 )
  {
    v5 = 1;
    if ( LODWORD(v4[7].m_BoundComponentHandles.mNode.mNext) == 3 )
      v5 = 0;
  }
  v6 = deltaTime + v2->mTimeSinceBeginUse;
  v2->mTimeSinceBeginUse = v6;
  if ( v2->mIsInUse )
  {
    if ( v3 && !isPlayingOpeningBranch )
      v2->mIsInterrupted = 1;
    if ( v5 )
    {
      v7 = v2->mUseTime;
      if ( v6 > v7 && v7 > 0.0 )
        v2->mIsTimedOut = 1;
    }
    if ( v2->mIsTimedOut || v3 )
    {
      *(_WORD *)&v2->mIsInUse = 256;
      if ( UFG::GetLocalPlayer() == (UFG::SimObjectCharacter *)v2->mpUser.m_pPointer
        || v2->mPropertiesHandle.mProperties->mIsAutoInteractable )
      {
        UFG::InterestPoint::EndReservation(v2);
      }
    }
  }
  else
  {
    v2->mTimeSinceFinished = deltaTime + v2->mTimeSinceFinished;
  }
  return v2->mCooldownTime < v2->mTimeSinceFinished;
}

// File Line: 1895
// RVA: 0x57F600
bool __fastcall UFG::InterestPoint::CheckOutsideForInteruption(UFG::InterestPoint *this, bool *isPlayingOpeningBranch)
{
  bool *v2; // rsi
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // r8
  UFG::SimComponent *v5; // rbx
  UFG::SimComponent *v6; // rax
  unsigned int v7; // eax
  unsigned __int8 v8; // al
  bool v9; // di

  v2 = isPlayingOpeningBranch;
  *isPlayingOpeningBranch = 0;
  v3 = (UFG::SimObjectGame *)this->mpUser.m_pPointer;
  if ( !v3 )
    return 1;
  v4 = v3->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    v5 = v3->m_Components.p[7].m_pComponent;
  }
  else if ( (v4 & 0x8000u) == 0 )
  {
    if ( (v4 >> 13) & 1 )
    {
      v5 = v3->m_Components.p[6].m_pComponent;
    }
    else
    {
      v6 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::ActionTreeComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::ActionTreeComponent::_TypeUID);
      v5 = v6;
    }
  }
  else
  {
    v5 = v3->m_Components.p[7].m_pComponent;
  }
  if ( !v5 )
    return 1;
  if ( !(_S9_16 & 1) )
  {
    _S9_16 |= 1u;
    node_id.mUID = UFG::qStringHashUpper32("Interactions", 0xFFFFFFFF);
  }
  v7 = `anonymous namespace::GetActionMostUsedIndex_Interactions();
  v8 = ActionController::IsPlaying((ActionController *)&v5[3], &node_id, v7, 0);
  v9 = v8 == 0;
  if ( !v8 )
    *v2 = ActionController::IsPlaying(
            (ActionController *)&v5[3],
            (ActionNode *)v5[2].m_BoundComponentHandles.mNode.mNext[1].mNext);
  return v9;
}

// File Line: 1918
// RVA: 0x582680
float __fastcall UFG::InterestPoint::GetDistanceAttenuation(float dist, float referenceDist, float factor)
{
  float v3; // xmm1_4
  float result; // xmm0_4

  if ( dist <= referenceDist )
    dist = referenceDist;
  v3 = referenceDist / (float)((float)((float)(dist - referenceDist) * factor) + referenceDist);
  if ( v3 <= 0.0 )
    return 0.0;
  result = *(float *)&FLOAT_1_0;
  if ( v3 < 1.0 )
    return v3;
  return result;
}

// File Line: 1926
// RVA: 0x581EB0
void __fastcall UFG::InterestPoint::FinishUsing(UFG::InterestPoint *this)
{
  UFG::InterestPoint *v1; // rbx
  UFG::SimObject *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rax
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v5; // rcx
  UFG::InterestPointLink *v6; // rcx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v7; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax

  v1 = this;
  v2 = this->mpUser.m_pPointer;
  if ( !v2 )
    return;
  v3 = v2->m_Flags;
  if ( (v3 >> 14) & 1 )
  {
    v4 = v2->m_Components.p[4].m_pComponent;
  }
  else if ( (v3 & 0x8000u) == 0 )
  {
    if ( (v3 >> 13) & 1 )
      v4 = v2->m_Components.p[3].m_pComponent;
    else
      v4 = (v3 >> 12) & 1 ? v2->m_Components.p[2].m_pComponent : UFG::SimObject::GetComponentOfType(
                                                                   v2,
                                                                   UFG::TSActorComponent::_TypeUID);
  }
  else
  {
    v4 = v2->m_Components.p[4].m_pComponent;
  }
  if ( !v4 )
    return;
  v5 = v4[1].vfptr;
  if ( !v5 || LODWORD(v4[1].m_SafePointerList.mNode.mPrev) != LODWORD(v5[1].__vecDelDtor) )
    return;
  if ( !v1->mIsInUse )
    goto LABEL_18;
  if ( v1->mBeginningScriptInfo.mHasScript )
  {
    if ( !v1->mBeginningScriptInfo.mScriptFired )
      UFG::InterestPoint::StartScript(v1, &v1->mBeginningScriptInfo);
LABEL_18:
    if ( v1->mBeginningScriptInfo.mHasScript
      && v1->mBeginningScriptInfo.mScriptFired
      && v1->mEndingScriptInfo.mHasScript
      && !v1->mEndingScriptInfo.mScriptFired )
    {
      UFG::InterestPoint::StartScript(v1, &v1->mEndingScriptInfo);
    }
  }
  if ( v1->mLinkObject.m_pPointer )
  {
    v6 = (UFG::InterestPointLink *)v1->mpInterestPointUserComponent.m_pPointer;
    if ( !v6[14].mIsExclusive )
    {
      UFG::InterestPointLink::Reset(v6 + 14);
      v7 = &v1->mLinkObject;
      if ( v7->m_pPointer )
      {
        v8 = v7->mPrev;
        v9 = v7->mNext;
        v8->mNext = v9;
        v9->mPrev = v8;
        v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v7->mPrev;
        v7->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v7->mPrev;
      }
      v7->m_pPointer = 0i64;
    }
  }
}

// File Line: 1959
// RVA: 0x58C710
void __fastcall UFG::InterestPoint::StartScript(UFG::InterestPoint *this, UFG::ScriptInfo *scriptInfo)
{
  bool v2; // zf
  UFG::ScriptInfo *v3; // rdi
  UFG::SimObject *v4; // rcx
  UFG::TSActor *v5; // rax
  SSInstance *v6; // rsi
  SSClass *v7; // rbx
  SSCode *v8; // rax

  v2 = scriptInfo->mpCachedScript == 0i64;
  v3 = scriptInfo;
  scriptInfo->mScriptFired = 1;
  if ( !v2 )
  {
    v4 = this->mpUser.m_pPointer;
    if ( v4 )
    {
      v5 = UFG::TSActor::FromSimObject(v4);
      v6 = (SSInstance *)&v5->vfptr;
      if ( v5 )
      {
        v7 = v5->i_class_p;
        v8 = UFG::ScriptCache::GetScriptCode(v3->mpCachedScript);
        UFG::SkookumMgr::RunExternalCodeBlock(v8, v7, v6, 0i64, 0i64);
      }
    }
  }
}

// File Line: 1988
// RVA: 0x57FEA0
UFG::qSymbol *__fastcall UFG::InterestPoint::ConvertTypeToPropertiesName(UFG::qSymbol *result, UFG::qSymbol *type)
{
  UFG::qSymbol *v2; // rbx
  UFG::qSymbol *v3; // rdi
  char *v4; // rbx
  char *v5; // rax
  UFG::qString v7; // [rsp+28h] [rbp-30h]

  v2 = type;
  v3 = result;
  UFG::qString::qString(&v7);
  v4 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)v2);
  v5 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&qSymbolX_propset_componentPOI);
  UFG::qString::Format(&v7, "%s-%s", v5, v4, -2i64);
  UFG::qSymbol::create_from_string(v3, v7.mData);
  UFG::qString::~qString(&v7);
  return v3;
}

// File Line: 2032
// RVA: 0x581230
UFG::InterestPoint *__fastcall UFG::InterestPoint::FindNearestMinMaxOfType(UFG::qVector3 *pos, const bool includeActive, const bool includeInactive, UFG::qSymbol *type, float minDistSquared, float maxDistSquared, float *pDistSquared)
{
  UFG::InterestPoint *v7; // rsi
  UFG::qSymbol *v8; // r14
  bool v9; // bp
  UFG::qVector3 *v10; // r12
  bool v11; // r15
  float v12; // xmm6_4
  unsigned int v13; // eax
  UFG::qBaseTreeRB *i; // rax
  UFG::InterestPoint *v15; // rbx
  UFG::qVector3 *v16; // rax
  float v17; // xmm2_4
  UFG::qBaseTreeRB *j; // rax
  signed __int64 v19; // rdi
  _DWORD *v20; // rbx
  int v21; // xmm0_4
  int v22; // xmm1_4
  float v23; // xmm2_4
  UFG::InterestPoint *result; // rax

  v7 = 0i64;
  v8 = type;
  v9 = includeInactive;
  v10 = pos;
  v11 = includeActive;
  v12 = maxDistSquared;
  v13 = qSymbol_Any.mUID;
  if ( type->mUID == qSymbol_Any.mUID || type->mUID == qSymbol_look.mUID )
  {
    for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::InterestPoint::msLookInterestPoints);
          ;
          i = UFG::qBaseTreeRB::GetNext(&UFG::InterestPoint::msLookInterestPoints.mTree, &v15->mNode) )
    {
      v15 = (UFG::InterestPoint *)(i ? i[-2].mRoot.mChild : 0i64);
      if ( !v15 )
        break;
      if ( (v8->mUID == qSymbol_Any.mUID || v8->mUID == v15->mPoiType.mUID)
        && (v11 && v15->mActive || v9 && !v15->mActive) )
      {
        v16 = UFG::InterestPoint::GetPosition(v15);
        v17 = (float)((float)((float)(v10->y - v16->y) * (float)(v10->y - v16->y))
                    + (float)((float)(v10->x - v16->x) * (float)(v10->x - v16->x)))
            + (float)((float)(v10->z - v16->z) * (float)(v10->z - v16->z));
        if ( v17 < v12 && v17 > minDistSquared && v17 < maxDistSquared )
        {
          v12 = (float)((float)((float)(v10->y - v16->y) * (float)(v10->y - v16->y))
                      + (float)((float)(v10->x - v16->x) * (float)(v10->x - v16->x)))
              + (float)((float)(v10->z - v16->z) * (float)(v10->z - v16->z));
          v7 = v15;
        }
      }
    }
    v13 = qSymbol_Any.mUID;
  }
  if ( v8->mUID == v13 )
  {
    for ( j = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::InterestPoint::msUseInterestPoints);
          ;
          j = UFG::qBaseTreeRB::GetNext(&UFG::InterestPoint::msUseInterestPoints.mTree, (UFG::qBaseNodeRB *)(v19 + 136)) )
    {
      v19 = (signed __int64)(j ? j[-2].mRoot.mChild : 0i64);
      if ( !v19 )
        break;
      if ( (v8->mUID == qSymbol_Any.mUID || v8->mUID == *(_DWORD *)(v19 + 300))
        && (v11 && *(_BYTE *)(v19 + 430) || v9 && !*(_BYTE *)(v19 + 430)) )
      {
        if ( !*(_BYTE *)(v19 + 316) )
        {
          v20 = *(_DWORD **)(v19 + 104);
          UFG::TransformNodeComponent::UpdateWorldTransform(*(UFG::TransformNodeComponent **)(v19 + 104));
          v21 = v20[45];
          v22 = v20[46];
          *(_DWORD *)(v19 + 304) = v20[44];
          *(_DWORD *)(v19 + 308) = v21;
          *(_DWORD *)(v19 + 312) = v22;
          *(_BYTE *)(v19 + 316) = 1;
        }
        v23 = (float)((float)((float)(v10->x - *(float *)(v19 + 304)) * (float)(v10->x - *(float *)(v19 + 304)))
                    + (float)((float)(v10->y - *(float *)(v19 + 308)) * (float)(v10->y - *(float *)(v19 + 308))))
            + (float)((float)(v10->z - *(float *)(v19 + 312)) * (float)(v10->z - *(float *)(v19 + 312)));
        if ( v23 < v12 && v23 > minDistSquared && v23 < maxDistSquared )
        {
          v12 = (float)((float)((float)(v10->x - *(float *)(v19 + 304)) * (float)(v10->x - *(float *)(v19 + 304)))
                      + (float)((float)(v10->y - *(float *)(v19 + 308)) * (float)(v10->y - *(float *)(v19 + 308))))
              + (float)((float)(v10->z - *(float *)(v19 + 312)) * (float)(v10->z - *(float *)(v19 + 312)));
          v7 = (UFG::InterestPoint *)v19;
        }
      }
    }
  }
  result = v7;
  if ( pDistSquared )
    *pDistSquared = v12;
  return result;
}

// File Line: 2107
// RVA: 0x5814E0
UFG::InterestPoint *__fastcall UFG::InterestPoint::FindNearestMinOfType(UFG::qVector3 *pos, UFG::qSymbol *type, float minDistSquared, float maxDistSquared, float *pDistSquared)
{
  unsigned int v5; // eax
  float v6; // xmm6_4
  float v7; // xmm7_4
  UFG::qSymbol *v8; // r14
  unsigned int v9; // edx
  UFG::InterestPoint *v10; // rsi
  UFG::qVector3 *v11; // rbp
  UFG::qBaseTreeRB *i; // rax
  signed __int64 v13; // rdi
  _DWORD *v14; // rbx
  int v15; // xmm0_4
  int v16; // xmm1_4
  float v17; // xmm2_4
  UFG::qBaseTreeRB *j; // rax
  signed __int64 v19; // rdi
  _DWORD *v20; // rbx
  int v21; // xmm0_4
  int v22; // xmm1_4
  float v23; // xmm2_4
  UFG::InterestPoint *result; // rax

  v5 = qSymbol_Any.mUID;
  v6 = maxDistSquared;
  v7 = minDistSquared;
  v8 = type;
  v9 = type->mUID;
  v10 = 0i64;
  v11 = pos;
  if ( v9 == qSymbol_Any.mUID || v9 == qSymbol_look.mUID )
  {
    for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::InterestPoint::msLookInterestPoints);
          ;
          i = UFG::qBaseTreeRB::GetNext(
                &UFG::InterestPoint::msLookInterestPoints.mTree,
                (UFG::qBaseNodeRB *)(v13 + 136)) )
    {
      v13 = (signed __int64)(i ? i[-2].mRoot.mChild : 0i64);
      if ( !v13 )
        break;
      if ( v8->mUID == qSymbol_Any.mUID || v8->mUID == *(_DWORD *)(v13 + 300) )
      {
        if ( !*(_BYTE *)(v13 + 316) )
        {
          v14 = *(_DWORD **)(v13 + 104);
          UFG::TransformNodeComponent::UpdateWorldTransform(*(UFG::TransformNodeComponent **)(v13 + 104));
          v15 = v14[45];
          v16 = v14[46];
          *(_DWORD *)(v13 + 304) = v14[44];
          *(_DWORD *)(v13 + 308) = v15;
          *(_DWORD *)(v13 + 312) = v16;
          *(_BYTE *)(v13 + 316) = 1;
        }
        v17 = (float)((float)((float)(v11->y - *(float *)(v13 + 308)) * (float)(v11->y - *(float *)(v13 + 308)))
                    + (float)((float)(v11->x - *(float *)(v13 + 304)) * (float)(v11->x - *(float *)(v13 + 304))))
            + (float)((float)(v11->z - *(float *)(v13 + 312)) * (float)(v11->z - *(float *)(v13 + 312)));
        if ( v17 < v6 && v17 > v7 )
        {
          v6 = (float)((float)((float)(v11->y - *(float *)(v13 + 308)) * (float)(v11->y - *(float *)(v13 + 308)))
                     + (float)((float)(v11->x - *(float *)(v13 + 304)) * (float)(v11->x - *(float *)(v13 + 304))))
             + (float)((float)(v11->z - *(float *)(v13 + 312)) * (float)(v11->z - *(float *)(v13 + 312)));
          v10 = (UFG::InterestPoint *)v13;
        }
      }
    }
    v5 = qSymbol_Any.mUID;
  }
  if ( v8->mUID == v5 )
  {
    for ( j = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::InterestPoint::msUseInterestPoints);
          ;
          j = UFG::qBaseTreeRB::GetNext(&UFG::InterestPoint::msUseInterestPoints.mTree, (UFG::qBaseNodeRB *)(v19 + 136)) )
    {
      v19 = (signed __int64)(j ? j[-2].mRoot.mChild : 0i64);
      if ( !v19 )
        break;
      if ( v8->mUID == qSymbol_Any.mUID || v8->mUID == *(_DWORD *)(v19 + 300) )
      {
        if ( !*(_BYTE *)(v19 + 316) )
        {
          v20 = *(_DWORD **)(v19 + 104);
          UFG::TransformNodeComponent::UpdateWorldTransform(*(UFG::TransformNodeComponent **)(v19 + 104));
          v21 = v20[45];
          v22 = v20[46];
          *(_DWORD *)(v19 + 304) = v20[44];
          *(_DWORD *)(v19 + 308) = v21;
          *(_DWORD *)(v19 + 312) = v22;
          *(_BYTE *)(v19 + 316) = 1;
        }
        v23 = (float)((float)((float)(v11->x - *(float *)(v19 + 304)) * (float)(v11->x - *(float *)(v19 + 304)))
                    + (float)((float)(v11->y - *(float *)(v19 + 308)) * (float)(v11->y - *(float *)(v19 + 308))))
            + (float)((float)(v11->z - *(float *)(v19 + 312)) * (float)(v11->z - *(float *)(v19 + 312)));
        if ( v23 < v6 && v23 > v7 )
        {
          v6 = (float)((float)((float)(v11->x - *(float *)(v19 + 304)) * (float)(v11->x - *(float *)(v19 + 304)))
                     + (float)((float)(v11->y - *(float *)(v19 + 308)) * (float)(v11->y - *(float *)(v19 + 308))))
             + (float)((float)(v11->z - *(float *)(v19 + 312)) * (float)(v11->z - *(float *)(v19 + 312)));
          v10 = (UFG::InterestPoint *)v19;
        }
      }
    }
  }
  result = v10;
  if ( pDistSquared )
    *pDistSquared = v6;
  return result;
}

// File Line: 2176
// RVA: 0x580FD0
UFG::InterestPoint *__fastcall UFG::InterestPoint::FindNearestMaxOfType(UFG::qVector3 *pos, UFG::qSymbol *type, float minDistSquared, float maxDistSquared, float *pDistSquared)
{
  float v5; // xmm6_4
  UFG::InterestPoint *v6; // rsi
  UFG::qSymbol *v7; // r14
  UFG::qVector3 *v8; // rbp
  UFG::qBaseTreeRB *i; // rax
  signed __int64 v10; // rdi
  _DWORD *v11; // rbx
  int v12; // xmm0_4
  int v13; // xmm1_4
  float v14; // xmm2_4
  UFG::qBaseTreeRB *j; // rax
  signed __int64 v16; // rdi
  _DWORD *v17; // rbx
  int v18; // xmm0_4
  int v19; // xmm1_4
  float v20; // xmm2_4
  UFG::InterestPoint *result; // rax

  v5 = maxDistSquared;
  v6 = 0i64;
  v7 = type;
  v8 = pos;
  if ( type->mUID != qSymbol_Any.mUID && type->mUID != qSymbol_look.mUID )
    goto LABEL_34;
  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::InterestPoint::msLookInterestPoints);
        ;
        i = UFG::qBaseTreeRB::GetNext(&UFG::InterestPoint::msLookInterestPoints.mTree, (UFG::qBaseNodeRB *)(v10 + 136)) )
  {
    v10 = (signed __int64)(i ? i[-2].mRoot.mChild : 0i64);
    if ( !v10 )
      break;
    if ( v7->mUID == qSymbol_Any.mUID || v7->mUID == *(_DWORD *)(v10 + 300) )
    {
      if ( !*(_BYTE *)(v10 + 316) )
      {
        v11 = *(_DWORD **)(v10 + 104);
        UFG::TransformNodeComponent::UpdateWorldTransform(*(UFG::TransformNodeComponent **)(v10 + 104));
        v12 = v11[45];
        v13 = v11[46];
        *(_DWORD *)(v10 + 304) = v11[44];
        *(_DWORD *)(v10 + 308) = v12;
        *(_DWORD *)(v10 + 312) = v13;
        *(_BYTE *)(v10 + 316) = 1;
      }
      v14 = (float)((float)((float)(v8->y - *(float *)(v10 + 308)) * (float)(v8->y - *(float *)(v10 + 308)))
                  + (float)((float)(v8->x - *(float *)(v10 + 304)) * (float)(v8->x - *(float *)(v10 + 304))))
          + (float)((float)(v8->z - *(float *)(v10 + 312)) * (float)(v8->z - *(float *)(v10 + 312)));
      if ( v14 < v5 && v14 < maxDistSquared )
      {
        v5 = (float)((float)((float)(v8->y - *(float *)(v10 + 308)) * (float)(v8->y - *(float *)(v10 + 308)))
                   + (float)((float)(v8->x - *(float *)(v10 + 304)) * (float)(v8->x - *(float *)(v10 + 304))))
           + (float)((float)(v8->z - *(float *)(v10 + 312)) * (float)(v8->z - *(float *)(v10 + 312)));
        v6 = (UFG::InterestPoint *)v10;
      }
    }
  }
  if ( v7->mUID != qSymbol_look.mUID )
  {
LABEL_34:
    for ( j = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::InterestPoint::msUseInterestPoints);
          ;
          j = UFG::qBaseTreeRB::GetNext(&UFG::InterestPoint::msUseInterestPoints.mTree, (UFG::qBaseNodeRB *)(v16 + 136)) )
    {
      v16 = (signed __int64)(j ? j[-2].mRoot.mChild : 0i64);
      if ( !v16 )
        break;
      if ( v7->mUID == qSymbol_Any.mUID || v7->mUID == *(_DWORD *)(v16 + 300) )
      {
        if ( !*(_BYTE *)(v16 + 316) )
        {
          v17 = *(_DWORD **)(v16 + 104);
          UFG::TransformNodeComponent::UpdateWorldTransform(*(UFG::TransformNodeComponent **)(v16 + 104));
          v18 = v17[45];
          v19 = v17[46];
          *(_DWORD *)(v16 + 304) = v17[44];
          *(_DWORD *)(v16 + 308) = v18;
          *(_DWORD *)(v16 + 312) = v19;
          *(_BYTE *)(v16 + 316) = 1;
        }
        v20 = (float)((float)((float)(v8->x - *(float *)(v16 + 304)) * (float)(v8->x - *(float *)(v16 + 304)))
                    + (float)((float)(v8->y - *(float *)(v16 + 308)) * (float)(v8->y - *(float *)(v16 + 308))))
            + (float)((float)(v8->z - *(float *)(v16 + 312)) * (float)(v8->z - *(float *)(v16 + 312)));
        if ( v20 < v5 && v20 < maxDistSquared )
        {
          v5 = (float)((float)((float)(v8->x - *(float *)(v16 + 304)) * (float)(v8->x - *(float *)(v16 + 304)))
                     + (float)((float)(v8->y - *(float *)(v16 + 308)) * (float)(v8->y - *(float *)(v16 + 308))))
             + (float)((float)(v8->z - *(float *)(v16 + 312)) * (float)(v8->z - *(float *)(v16 + 312)));
          v6 = (UFG::InterestPoint *)v16;
        }
      }
    }
  }
  result = v6;
  if ( pDistSquared )
    *pDistSquared = v5;
  return result;
}

// File Line: 2232
// RVA: 0x585230
char __fastcall UFG::InterestPoint::IsRelevantToPropertySet(UFG::InterestPoint *this, UFG::qPropertySet *pCharacterProperties)
{
  UFG::qPropertySet *v2; // rsi
  UFG::InterestPoint *v3; // rbx
  float v4; // xmm1_4
  __int128 v5; // xmm0
  UFG::InterestPointProperties *v6; // rax
  float v7; // xmm0_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  char result; // al
  UFG::qPropertySet *v11; // rax
  int v12; // ecx
  bool v13; // di
  UFG::qPropertySet *v14; // rax
  __int64 v15; // rcx
  UFG::qPropertyList *v16; // r14
  unsigned int v17; // ebp
  unsigned int v18; // esi
  UFG::qSymbol *v19; // rax
  unsigned int v20; // ecx
  UFG::qSymbol *v21; // r8
  UFG::InterestPointProperties *v22; // rax
  unsigned int v23; // edx
  unsigned int v24; // er8
  UFG::qSymbol *v25; // rax

  v2 = pCharacterProperties;
  v3 = this;
  if ( !this->mActive
    || this->mLinkObject.m_pPointer
    || this->mpPedInfoUser
    || this->mIsReserved
    || this->mCooldownTime > this->mTimeSinceFinished )
  {
    return 0;
  }
  v4 = this->mPropertiesHandle.mProperties->mTimeOfDayToBecomeActive
     - this->mPropertiesHandle.mProperties->mTimeOfDayToBecomeInactive;
  if ( v4 < 0.0 )
    LODWORD(v4) ^= _xmm[0];
  if ( v4 >= 0.001 )
  {
    v5 = LODWORD(UFG::TimeOfDayManager::GetInstance()->m_SecondsSinceMidnight);
    v6 = v3->mPropertiesHandle.mProperties;
    v7 = *(float *)&v5 * 0.00027777778;
    v8 = v6->mTimeOfDayToBecomeActive;
    v9 = v6->mTimeOfDayToBecomeInactive;
    if ( v8 >= v9 )
    {
      if ( v8 <= v7 )
        goto LABEL_14;
    }
    else if ( v8 < v7 )
    {
      return 0;
    }
    if ( v7 > v9 )
      return 0;
  }
LABEL_14:
  if ( v3->mPropertiesHandle.mProperties->mGendersAllowed.mUID != qSymbol_Any.mUID )
  {
    v11 = UFG::PropertySetManager::GetComponentDataPtr<component_CharacterProperties>(
            (UFG::PropertySetManager *)v2,
            pCharacterProperties);
    if ( v11 )
    {
      v12 = HIDWORD(v11->mParents.mOffset);
      if ( v12 == UFG::gNullQSymbol.mUID || v3->mPropertiesHandle.mProperties->mGendersAllowed.mUID != v12 )
        return 0;
    }
  }
  if ( !v3->mPropertiesHandle.mProperties->mUseClassList.size )
    goto LABEL_35;
  v13 = 0;
  v14 = UFG::PropertySetManager::GetComponentDataPtr<schema_classlist>(
          (UFG::PropertySetManager *)v2,
          pCharacterProperties);
  if ( !v14 )
    goto LABEL_35;
  v15 = v14->mOwner.mOffset;
  if ( !v15 )
    goto LABEL_35;
  v16 = (UFG::qPropertyList *)((char *)&v14->mOwner + v15);
  if ( !v16 )
    goto LABEL_35;
  v17 = v16->mNumElements;
  v18 = 0;
  if ( v17 )
  {
    do
    {
      v19 = UFG::qPropertyList::Get<UFG::qSymbol>(v16, v18);
      v20 = 0;
      v21 = v19;
      v22 = v3->mPropertiesHandle.mProperties;
      v23 = v22->mUseClassList.size;
      if ( v23 )
      {
        v24 = v21->mUID;
        v25 = v22->mUseClassList.p;
        while ( v24 != v25->mUID )
        {
          ++v20;
          ++v25;
          if ( v20 >= v23 )
            goto LABEL_27;
        }
      }
      else
      {
LABEL_27:
        v20 = -1;
      }
      v13 = v20 != -1;
      if ( v20 != -1 )
        break;
      ++v18;
    }
    while ( v18 < v17 );
  }
  if ( v13 ^ v3->mPropertiesHandle.mProperties->mClassListIsAllowed )
    result = 0;
  else
LABEL_35:
    result = 1;
  return result;
}

// File Line: 2416
// RVA: 0x584D70
bool __fastcall UFG::InterestPoint::IsRelevantToCharacter(UFG::InterestPoint *this, UFG::SimObject *_pCharacter, UFG::InterestPoint::eReserveReason reserveReason)
{
  UFG::SimObjectCVBase *v3; // rbx
  UFG::InterestPoint *v4; // rbp
  UFG::TargetingSystemPedBaseComponent *v5; // rax
  UFG::TransformNodeComponent *v6; // rsi
  UFG::TargetingSystemPedBaseComponent *v7; // rdi
  UFG::InterestPointUserComponent *v8; // r15
  UFG::SimObjectCharacterPropertiesComponent *pCharacterPropertiesComponent; // r12
  UFG::ActiveAIEntityComponent *pAAEC; // r13
  UFG::TargetingMap *v11; // rax
  signed __int64 v12; // rcx
  UFG::TargetingSimObject *v13; // rax
  signed __int64 v14; // rcx
  bool v15; // r14
  UFG::SimObjectCharacter *v16; // rax
  UFG::TransformNodeComponent *v17; // rsi
  float v18; // xmm1_4
  float v19; // xmm0_4
  UFG::SpawnPoint *pCharacterSpawnPoint; // rax
  char v21; // bl
  __int64 v22; // r9
  UFG::SimObjectCharacterPropertiesComponent *ST20_8_18; // ST20_8
  UFG::qMatrix44 *characterTransform; // [rsp+80h] [rbp-58h]
  UFG::SimObject *pSimObject; // [rsp+88h] [rbp-50h]
  UFG::qVector3 vPlayerPosition; // [rsp+90h] [rbp-48h]
  float appealScale; // [rsp+E0h] [rbp+8h]
  UFG::qVector3 *poiWorldPos; // [rsp+F8h] [rbp+20h]

  v3 = (UFG::SimObjectCVBase *)_pCharacter;
  v4 = this;
  if ( this->mpPedInfoUser )
  {
    LOBYTE(v5) = 0;
  }
  else
  {
    poiWorldPos = UFG::InterestPoint::GetPosition(this);
    if ( v3 && (v6 = (UFG::TransformNodeComponent *)v3->m_Components.p[2].m_pComponent) != 0i64 )
    {
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedBaseComponent>(v3);
      v7 = v5;
      if ( v5 )
      {
        v8 = (UFG::InterestPointUserComponent *)v3->m_Components.p[43].m_pComponent;
        if ( v8 )
        {
          v5 = (UFG::TargetingSystemPedBaseComponent *)UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v3);
          pCharacterPropertiesComponent = (UFG::SimObjectCharacterPropertiesComponent *)v5;
          if ( v5 )
          {
            v5 = (UFG::TargetingSystemPedBaseComponent *)UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v3);
            pAAEC = (UFG::ActiveAIEntityComponent *)v5;
            if ( v5 )
            {
              UFG::TransformNodeComponent::UpdateWorldTransform(v6);
              characterTransform = &v6->mWorldTransform;
              v11 = v7->m_pTargetingMap;
              appealScale = *(float *)&FLOAT_1_0;
              v12 = (unsigned __int8)v11->m_Map.p[26];
              v13 = v7->m_pTargets;
              v14 = v12;
              pSimObject = v13[v14].m_pTarget.m_pPointer;
              v15 = pSimObject && v13[v14].m_bLock;
              v16 = UFG::GetLocalPlayer();
              if ( v16 )
                v17 = (UFG::TransformNodeComponent *)v16->m_Components.p[2].m_pComponent;
              else
                v17 = 0i64;
              UFG::TransformNodeComponent::UpdateWorldTransform(v17);
              v18 = v17->mWorldTransform.v3.y;
              vPlayerPosition.x = v17->mWorldTransform.v3.x;
              v19 = v17->mWorldTransform.v3.z;
              vPlayerPosition.y = v18;
              vPlayerPosition.z = v19;
              pCharacterSpawnPoint = (UFG::SpawnPoint *)UFG::GetOriginatingSpawnPoint((UFG::SimObject *)&v3->vfptr);
              v21 = UFG::InterestPoint::IsRelevantToCharacter(
                      v4,
                      (UFG::SimObject *)&v3->vfptr,
                      v7,
                      v8,
                      pCharacterPropertiesComponent,
                      pAAEC,
                      &vPlayerPosition,
                      pCharacterSpawnPoint,
                      characterTransform,
                      poiWorldPos,
                      &appealScale,
                      (UFG::qSymbol *)&qSymbol_use.mUID,
                      8u,
                      ReserveReason_resume,
                      0);
              UFG::TargetingSystemBaseComponent::SetTarget(
                (UFG::TargetingSystemBaseComponent *)&v7->vfptr,
                eTARGET_TYPE_POI_USE,
                pSimObject);
              LOBYTE(v22) = 1;
              LODWORD(ST20_8_18) = 0;
              ((void (__fastcall *)(UFG::TargetingSystemPedBaseComponent *, signed __int64, bool, __int64, UFG::SimObjectCharacterPropertiesComponent *, const char *, _QWORD, _QWORD))v7->vfptr[14].__vecDelDtor)(
                v7,
                26i64,
                v15,
                v22,
                ST20_8_18,
                "InterestPoint::IsRelevantToCharacter",
                0i64,
                0i64);
              LOBYTE(v5) = v21;
            }
          }
        }
        else
        {
          LOBYTE(v5) = 0;
        }
      }
    }
    else
    {
      LOBYTE(v5) = 0;
    }
  }
  return (char)v5;
}

// File Line: 2502
// RVA: 0x5823B0
__int64 __fastcall UFG::InterestPoint::GetCanPathToCached(UFG::InterestPoint *this)
{
  UFG::InterestPoint *v1; // rbx

  v1 = this;
  if ( this->mCanPathToCached.mValue != 3 )
    return (unsigned __int8)this->mCanPathToCached.mValue;
  UFG::InterestPoint::UpdateCanPathToCached(this);
  return (unsigned __int8)v1->mCanPathToCached.mValue;
}

// File Line: 2554
// RVA: 0x584250
char __fastcall UFG::InterestPoint::IsRelevantToCharacter(UFG::InterestPoint *this, UFG::SimObject *pCharacter, UFG::TargetingSystemPedBaseComponent *pCharacterTargetComp, UFG::InterestPointUserComponent *pInterestPointUserComp, UFG::SimObjectCharacterPropertiesComponent *pCharacterPropertiesComponent, UFG::ActiveAIEntityComponent *pAAEC, UFG::qVector3 *vPlayerPosition, UFG::SpawnPoint *pCharacterSpawnPoint, UFG::qMatrix44 *characterTransform, UFG::qVector3 *poiWorldPos, float *appealScale, UFG::qSymbol *type, unsigned int matchReservationFlags, UFG::InterestPoint::eReserveReason reserveReason, bool bSkipChecksInPlayerRel)
{
  UFG::InterestPointUserComponent *v15; // r13
  UFG::SimObject *v16; // rsi
  UFG::InterestPoint *v17; // rdi
  UFG::SimObject *v19; // rax
  UFG::SimObject *v20; // rcx
  UFG::SimObject *v21; // rcx
  ActionContext *v22; // r15
  UFG::GroupComponent *v23; // r14
  UFG::InterestPointProperties *v24; // rax
  int v25; // ebp
  int v26; // ebx
  int v27; // eax
  UFG::InterestPointProperties *v28; // rcx
  unsigned int v29; // edx
  UFG::qStaticSymbol *v30; // rax
  unsigned int v31; // eax
  float v32; // xmm0_4
  __int128 v33; // xmm0
  UFG::InterestPointProperties *v34; // rax
  float v35; // xmm0_4
  bool v36; // r12
  unsigned int v37; // ecx
  float v38; // xmm2_4
  __m128 v39; // xmm1
  UFG::qVector3 *v40; // rax
  __m128 v41; // xmm0
  float v42; // xmm10_4
  float v43; // xmm1_4
  float v44; // xmm14_4
  bool v45; // bl
  UFG::InterestPointProperties *v46; // rbx
  UFG::SimObject *v47; // rax
  UFG::SceneObjectProperties *v48; // rcx
  UFG::SceneObjectProperties *v49; // rcx
  UFG::SimObject *v50; // rcx
  unsigned __int16 v51; // dx
  UFG::SimComponent *v52; // rbx
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v53; // rbp
  UFG::SimObject *v54; // rcx
  UFG::ActiveAIEntityComponent *v55; // rbp
  unsigned __int16 v56; // cx
  UFG::ActiveAIEntityComponent *v57; // rax
  float v58; // xmm0_4
  unsigned int v59; // edx
  UFG::qVector3 *v60; // rax
  UFG::qMatrix44 *v61; // r12
  signed __int64 v62; // rbp
  UFG::TargetingSystemBaseComponent *v63; // rbx
  _BOOL8 v64; // rdx
  __int64 v65; // r8
  __int64 v66; // r9
  UFG::SimObject *v67; // rcx
  UFG::TransformNodeComponent *v68; // rbx
  float v69; // xmm7_4
  __m128 v70; // xmm6
  float v71; // xmm8_4
  UFG::qPropertySet *v72; // r14
  UFG::qPropertySet *v73; // rbx
  UFG::qPropertySet *v74; // rax
  char v75; // al
  float v76; // xmm1_4
  float v77; // xmm2_4
  char *v78; // rax
  float v79; // xmm1_4
  float v80; // xmm0_4
  float v81; // xmm3_4
  float v82; // xmm1_4
  float v83; // xmm2_4
  unsigned __int16 v84; // cx
  char v85; // al
  UFG::SimComponent *v86; // rbx
  unsigned __int16 v87; // cx
  UFG::SimComponent *v88; // rax
  ActionNodeRoot *v89; // rax
  __int64 v90; // rdx
  __int64 v91; // r8
  __int64 v92; // r9
  ActionNodeRoot *v93; // rax
  ActionNode *v94; // rcx
  UFG::qVector3 v2; // [rsp+20h] [rbp-B8h]
  UFG::qVector3 v1; // [rsp+30h] [rbp-A8h]
  char v97; // [rsp+E0h] [rbp+8h]
  UFG::TargetingSystemPedBaseComponent *pCharacterTargetCompa; // [rsp+F0h] [rbp+18h]

  pCharacterTargetCompa = pCharacterTargetComp;
  v15 = pInterestPointUserComp;
  v16 = pCharacter;
  v17 = this;
  UFG::qGetTicks();
  if ( v17->mpPedInfoUser )
    return 0;
  if ( type->mUID == qSymbol_use.mUID )
  {
    if ( v17->mPoiType.mUID != qSymbol_look.mUID )
      goto LABEL_7;
    return 0;
  }
  if ( type->mUID != v17->mPoiType.mUID )
    return 0;
LABEL_7:
  if ( !v17->mPassedActivationChance )
    return 0;
  if ( !bSkipChecksInPlayerRel && !v17->mActive )
    return 0;
  v19 = v17->mLinkObject.m_pPointer;
  if ( v19 )
  {
    v20 = v15->mInterestPointLink.mLinkObject.m_pPointer;
    if ( !v20 || v20 != v19 )
      return 0;
  }
  v21 = v15->mInterestPointLink.mLinkObject.m_pPointer;
  v97 = 0;
  if ( v21 )
  {
    if ( v15->mInterestPointLink.mIsExclusive )
    {
      v97 = 1;
      if ( v21 != v19 )
        return 0;
    }
  }
  if ( !UFG::InterestPoint::IsReservationMatch(v17, matchReservationFlags, reserveReason)
    && v17->mpUser.m_pPointer != v16 )
  {
    return 0;
  }
  v22 = 0i64;
  v23 = 0i64;
  if ( pAAEC )
    v23 = pAAEC->m_pGroupComponent.m_pPointer;
  v24 = v17->mPropertiesHandle.mProperties;
  v25 = v24->mMinGroupSize;
  v26 = v24->mMaxGroupSize;
  if ( v25 >= 0 || v26 >= 0 )
  {
    v27 = UFG::GroupComponent::GetGroupSize(v23);
    if ( v25 >= 0 && v27 < v25 )
      return 0;
    if ( v26 >= 0 && v27 > v26 )
      return 0;
  }
  if ( !bSkipChecksInPlayerRel )
  {
    v28 = v17->mPropertiesHandle.mProperties;
    v29 = v28->mGendersAllowed.mUID;
    if ( v29 != qSymbol_Any.mUID )
    {
      v30 = &qSymbol_Female;
      if ( pCharacterPropertiesComponent->m_eGender == 1 )
        v30 = &qSymbol_Male;
      v31 = v30->mUID;
      if ( v31 == -1 || v29 != v31 )
        return 0;
    }
    v32 = v28->mTimeOfDayToBecomeActive - v28->mTimeOfDayToBecomeInactive;
    if ( v32 < 0.0 )
      LODWORD(v32) ^= _xmm[0];
    if ( v32 >= 0.001 )
    {
      v33 = LODWORD(UFG::TimeOfDayManager::GetInstance()->m_SecondsSinceMidnight);
      v34 = v17->mPropertiesHandle.mProperties;
      v35 = *(float *)&v33 * 0.00027777778;
      if ( v35 > v34->mTimeOfDayToBecomeActive && v35 < v34->mTimeOfDayToBecomeInactive )
        return 0;
    }
  }
  if ( v17->mPoiType.mUID != qSymbol_look.mUID
    && reserveReason == 1
    && !v97
    && !v17->mPropertiesHandle.mProperties->mIgnoreCharacterCooldown
    && pCharacterPropertiesComponent
    && pCharacterPropertiesComponent->m_CharacterStats[2].m_fStat > 0.0 )
  {
    return 0;
  }
  v36 = UFG::IsAnyLocalPlayer(v16);
  if ( !v36 )
  {
    if ( v23 )
    {
      v37 = qSymbol_look.mUID;
      if ( v17->mPoiType.mUID != qSymbol_look.mUID )
      {
        if ( !v17->mPropertiesHandle.mProperties->mAllowFollowers )
        {
          if ( (unsigned __int8)UFG::GroupComponent::IsFollower(v23) )
            return 0;
          v37 = qSymbol_look.mUID;
        }
        if ( v17->mPoiType.mUID != v37
          && !v17->mPropertiesHandle.mProperties->mAllowLeaders
          && UFG::GroupComponent::IsLeader(v23) )
        {
          return 0;
        }
      }
    }
  }
  if ( !bSkipChecksInPlayerRel )
  {
    v38 = v17->mPropertiesHandle.mProperties->mMaxDistanceFromPlayer;
    if ( v38 >= 0.0 )
    {
      v39 = (__m128)LODWORD(characterTransform->v3.y);
      v39.m128_f32[0] = (float)((float)(v39.m128_f32[0] - vPlayerPosition->y)
                              * (float)(v39.m128_f32[0] - vPlayerPosition->y))
                      + (float)((float)(characterTransform->v3.x - vPlayerPosition->x)
                              * (float)(characterTransform->v3.x - vPlayerPosition->x));
      if ( COERCE_FLOAT(_mm_sqrt_ps(v39)) > v38 )
        return 0;
    }
  }
  v40 = UFG::InterestPoint::GetPosition(v17);
  v41 = (__m128)LODWORD(characterTransform->v3.y);
  LODWORD(v42) = COERCE_UNSIGNED_INT(characterTransform->v3.z - v40->z) & _xmm;
  v43 = (float)(characterTransform->v3.x - v40->x) * (float)(characterTransform->v3.x - v40->x);
  v41.m128_f32[0] = (float)((float)(v41.m128_f32[0] - v40->y) * (float)(v41.m128_f32[0] - v40->y)) + v43;
  LODWORD(v44) = (unsigned __int128)_mm_sqrt_ps(v41);
  v45 = v44 <= 0.5 && v42 <= 1.5;
  if ( v17->mPropertiesHandle.mProperties->mInitialUseOnly && (!UFG::IsSpawning(v16) || !v45) )
    return 0;
  if ( !bSkipChecksInPlayerRel )
  {
    v46 = v17->mPropertiesHandle.mProperties;
    if ( v46->mWeatherFilterOn )
    {
      if ( v46->mWeatherFilterIsRaining != 1.0 < UFG::TimeOfDayManager::GetInstance()->m_WeatherState )
        return 0;
    }
  }
  if ( !v36 && v23 && v17->mPoiType.mUID != qSymbol_look.mUID && v17->mPropertiesHandle.mProperties->mAllowFollowers )
  {
    v47 = v17->m_pSimObject;
    v48 = v47 ? v47->m_pSceneObj : 0i64;
    v49 = v48->mpParent;
    if ( v49 )
    {
      v50 = v49->m_pSimObject;
      if ( v50 )
      {
        v51 = v50->m_Flags;
        if ( (v51 >> 14) & 1 )
        {
          v52 = v50->m_Components.p[25].m_pComponent;
        }
        else if ( (v51 & 0x8000u) == 0 )
        {
          if ( (v51 >> 13) & 1 )
            v52 = v50->m_Components.p[10].m_pComponent;
          else
            v52 = (v51 >> 12) & 1 ? v50->m_Components.p[3].m_pComponent : UFG::SimObject::GetComponentOfType(
                                                                            v50,
                                                                            UFG::InterestPoint::_TypeUID);
        }
        else
        {
          v52 = v50->m_Components.p[25].m_pComponent;
        }
        if ( v52 )
        {
          v53 = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)UFG::GroupComponent::GetLeader(v23);
          if ( v53 )
          {
            v54 = (UFG::SimObject *)v52[5].m_BoundComponentHandles.mNode.mNext;
            if ( !v54 || UFG::GroupComponent::GetGroupComponent(v54) != v53 )
              return 0;
          }
        }
      }
    }
  }
  if ( v16 )
  {
    v56 = v16->m_Flags;
    if ( (v56 >> 14) & 1 )
    {
      v57 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>((UFG::SimObjectCVBase *)v16);
    }
    else if ( (v56 & 0x8000u) == 0 )
    {
      if ( (v56 >> 13) & 1 )
      {
        v57 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                (UFG::SimObjectGame *)v16,
                                                UFG::ActiveAIEntityComponent::_TypeUID);
      }
      else if ( (v56 >> 12) & 1 )
      {
        v57 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                (UFG::SimObjectGame *)v16,
                                                UFG::ActiveAIEntityComponent::_TypeUID);
      }
      else
      {
        v57 = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                v16,
                                                UFG::ActiveAIEntityComponent::_TypeUID);
      }
    }
    else
    {
      v57 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>((UFG::SimObjectCVBase *)v16);
    }
    v55 = v57;
    if ( v57 )
    {
      if ( v17->mpXformNode )
      {
        UFG::InterestPoint::GetPosition(v17);
        v58 = UFG::Drifting_EngineState::GetDefaultLoad((PoseNode *)v55, v43);
        if ( UFG::Drifting_EngineState::GetDefaultLoad((PoseNode *)v55, v43) > v58 )
          return 0;
      }
    }
  }
  else
  {
    v55 = 0i64;
  }
  if ( !v17->mPropertiesHandle.mProperties->mAllowRepeatedUse )
  {
    v59 = v17->mPoiType.mUID;
    if ( v59 != qSymbol_look.mUID
      && reserveReason == 1
      && !v97
      && !v36
      && v15->mLastUsedPOIType.mUID == v59
      && v15->mLastUsedPOIDesc.mUID == v17->mInterestPointType->mDescription.mUID
      && v59 != -1 )
    {
      return 0;
    }
  }
  if ( v55->m_bCanWander && v17->mpXformNode )
  {
    v60 = UFG::InterestPoint::GetPosition(v17);
    v61 = characterTransform;
    v62 = (signed __int64)&v55->m_WanderData;
    if ( v62
      && *(_BYTE *)(v62 + 256)
      && (float)((float)((float)(*(float *)(v62 + 248) * (float)(v60->y - characterTransform->v3.y))
                       + (float)(*(float *)(v62 + 244) * (float)(v60->x - characterTransform->v3.x)))
               + (float)(*(float *)(v62 + 252) * (float)(v60->z - characterTransform->v3.z))) < 0.0 )
    {
      return 0;
    }
  }
  else
  {
    v61 = characterTransform;
  }
  v63 = (UFG::TargetingSystemBaseComponent *)&pCharacterTargetCompa->vfptr;
  if ( !UFG::InterestPoint::PassesItemFilter(v17, v16, pCharacterTargetCompa) )
    return 0;
  if ( pCharacterSpawnPoint )
  {
    v67 = pCharacterSpawnPoint->m_pSimObject;
    if ( v67 )
    {
      v68 = v67->m_pTransformNodeComponent;
      if ( v68 )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform(v67->m_pTransformNodeComponent);
        v69 = v68->mWorldTransform.v3.x;
        v70 = (__m128)LODWORD(v68->mWorldTransform.v3.y);
        v71 = v68->mWorldTransform.v3.z;
        v72 = PropertyUtils::Get<float>(v16->m_pSceneObj, (UFG::qSymbol *)&qSymbol_TetherAttenuation.mUID);
        v73 = PropertyUtils::Get<float>(v16->m_pSceneObj, (UFG::qSymbol *)&qSymbol_TetherDistance.mUID);
        v74 = PropertyUtils::Get<bool>(v16->m_pSceneObj, (UFG::qSymbol *)&qSymbol_TetherDistanceIsHardLimit.mUID);
        if ( v72 && v73 && v74 )
        {
          v75 = v74->mFlags;
          v76 = *(float *)&v73->mFlags;
          v77 = *(float *)&v72->mFlags;
          if ( v75 || v77 > 0.0 )
          {
            v70.m128_f32[0] = (float)((float)((float)(v70.m128_f32[0] - poiWorldPos->y)
                                            * (float)(v70.m128_f32[0] - poiWorldPos->y))
                                    + (float)((float)(v69 - poiWorldPos->x) * (float)(v69 - poiWorldPos->x)))
                            + (float)((float)(v71 - poiWorldPos->z) * (float)(v71 - poiWorldPos->z));
            if ( v70.m128_f32[0] > (float)(v76 * v76) )
            {
              if ( v75 )
              {
                *appealScale = 0.0;
                return 0;
              }
              *appealScale = UFG::InterestPoint::GetDistanceAttenuation(COERCE_FLOAT(_mm_sqrt_ps(v70)), v76, v77);
            }
          }
          if ( *appealScale <= 0.0 )
            return 0;
        }
        else
        {
          v78 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v16->m_Name);
          UFG::qPrintf("Character %s has no tether settings\n", v78);
        }
      }
      v63 = (UFG::TargetingSystemBaseComponent *)&pCharacterTargetCompa->vfptr;
    }
  }
  if ( v17->mPoiType.mUID != qSymbol_look.mUID && reserveReason == 1 && !v97 )
  {
    v79 = poiWorldPos->x;
    v80 = poiWorldPos->y;
    v81 = v61->v0.x;
    v2.z = 0.0;
    v1.z = 0.0;
    v82 = v79 - v61->v3.x;
    v83 = v61->v0.y;
    v2.y = v80 - v61->v3.y;
    v2.x = v82;
    v1.x = v81;
    v1.y = v83;
    if ( (float)((float)(v2.y * v2.y) + (float)(v82 * v82)) > 1.0
      && (float)((float)(v83 * v83) + (float)(v81 * v81)) > 0.001
      && COERCE_FLOAT(COERCE_UNSIGNED_INT(UFG::qAngleBetween(&v1, &v2)) & _xmm) > (float)(v17->mPropertiesHandle.mProperties->mUserRelativeAngleRange
                                                                                        * 0.5) )
    {
      return 0;
    }
  }
  if ( !bSkipChecksInPlayerRel && v17->mPropertiesHandle.mProperties->mUseClassList.size > 0 )
  {
    if ( v16 )
    {
      v84 = v16->m_Flags;
      if ( !((v84 >> 14) & 1) && (v84 & 0x8000u) == 0 && !((v84 >> 13) & 1) )
      {
        if ( (v84 >> 12) & 1 )
          UFG::SimObjectGame::GetComponentOfTypeHK(
            (UFG::SimObjectGame *)v16,
            UFG::SimObjectPropertiesComponent::_TypeUID);
        else
          UFG::SimObject::GetComponentOfType(v16, UFG::SimObjectPropertiesComponent::_TypeUID);
      }
    }
    v85 = UFG::SimObjectUtility::IsClassTypeInArray(v16, &v17->mPropertiesHandle.mProperties->mUseClassList);
    v64 = v17->mPropertiesHandle.mProperties->mClassListIsAllowed;
    LOBYTE(v64) = v85 ^ v64;
    if ( (_BYTE)v64 )
      return 0;
  }
  if ( v17->mInterestPointType->mBehaviour )
  {
    if ( v63 )
    {
      UFG::TargetingSystemBaseComponent::ClearTarget(
        v63,
        (UFG::eTargetTypeEnum)((type->mUID != qSymbol_look.mUID) + 25));
      UFG::TargetingSystemBaseComponent::SetTarget(
        v63,
        (UFG::eTargetTypeEnum)((type->mUID != qSymbol_look.mUID) + 25),
        v17->m_pSimObject);
    }
    if ( v16 )
    {
      v87 = v16->m_Flags;
      if ( (v87 >> 14) & 1 )
      {
        v86 = v16->m_Components.p[7].m_pComponent;
      }
      else if ( (v87 & 0x8000u) == 0 )
      {
        if ( (v87 >> 13) & 1 )
        {
          v86 = v16->m_Components.p[6].m_pComponent;
        }
        else
        {
          if ( (v87 >> 12) & 1 )
            v88 = UFG::SimObjectGame::GetComponentOfTypeHK(
                    (UFG::SimObjectGame *)v16,
                    UFG::ActionTreeComponent::_TypeUID);
          else
            v88 = UFG::SimObject::GetComponentOfType(v16, UFG::ActionTreeComponent::_TypeUID);
          v86 = v88;
        }
      }
      else
      {
        v86 = v16->m_Components.p[7].m_pComponent;
      }
      if ( !v86 )
      {
LABEL_173:
        if ( v22 )
        {
          v94 = v17->mInterestPointType->mBehaviourConditions;
          if ( !v94 || ((__int64 (__fastcall *)(ActionNode *, ActionContext *))v94->vfptr[2].GetClassNameUID)(v94, v22) )
            goto LABEL_176;
        }
        return 0;
      }
      v22 = (ActionContext *)v86[2].m_BoundComponentHandles.mNode.mNext;
    }
    else
    {
      v86 = 0i64;
    }
    if ( v86 )
    {
      v89 = (ActionNodeRoot *)((__int64 (__cdecl *)(ActionNode *, _BOOL8, __int64, __int64))v17->mInterestPointType->mBehaviour->vfptr[1].GetResourceOwner)(
                                v17->mInterestPointType->mBehaviour,
                                v64,
                                v65,
                                v66);
      if ( UFG::ActionTreeComponentBase::AllocateFor((UFG::ActionTreeComponentBase *)&v86[1], v89) )
      {
        v93 = (ActionNodeRoot *)((__int64 (__cdecl *)(ActionNode *, __int64, __int64, __int64))v17->mInterestPointType->mBehaviour->vfptr[1].GetResourceOwner)(
                                  v17->mInterestPointType->mBehaviour,
                                  v90,
                                  v91,
                                  v92);
        ActionNodeRoot::Init(v93, v22);
      }
    }
    goto LABEL_173;
  }
LABEL_176:
  if ( v17->mPoiType.mUID != qSymbol_look.mUID
    && !UFG::IsAnyLocalPlayer(v16)
    && (v44 > 1.0 || v42 > 2.0)
    && (unsigned int)UFG::InterestPoint::GetCanPathToCached(v17) != 1 )
  {
    return 0;
  }
  return 1;
}

// File Line: 3727
// RVA: 0x588390
bool __fastcall UFG::InterestPoint::PassesItemFilter(UFG::InterestPoint *this, UFG::SimObject *pCharacter, UFG::TargetingSystemPedBaseComponent *pCharacterTargetComp)
{
  UFG::TargetingSystemPedBaseComponent *v3; // r13
  UFG::InterestPoint *v4; // r14
  char v5; // di
  int v6; // er15
  unsigned int v7; // esi
  int *v8; // rbp
  UFG::SimObjectProp *v9; // rbx
  unsigned __int16 v10; // cx
  UFG::SimObjectWeaponPropertiesComponent *v11; // rax
  unsigned __int16 v12; // cx
  UFG::SimComponent *v13; // rax
  int v14; // edx
  UFG::InterestPointType *v15; // rax
  unsigned int v16; // ecx
  unsigned int v17; // er8
  UFG::eInventoryItemEnum *v18; // rax
  bool result; // al
  int v20; // [rsp+58h] [rbp+10h]
  int v21; // [rsp+5Ch] [rbp+14h]

  v3 = pCharacterTargetComp;
  v4 = this;
  if ( !pCharacter || !pCharacterTargetComp )
    return 0;
  if ( !this->mPropertiesHandle.mProperties->mItemFilterOn
    || UFG::IsAnyLocalPlayer(pCharacter) && !v4->mPropertiesHandle.mProperties->mItemFilterAppliesToPlayer )
  {
    return 1;
  }
  v5 = 0;
  v20 = 17;
  v21 = 18;
  v6 = 0;
  v7 = 0;
  v8 = &v20;
  while ( !v5 )
  {
    v9 = (UFG::SimObjectProp *)v3->m_pTargets[(unsigned __int8)v3->m_pTargetingMap->m_Map.p[*v8]].m_pTarget.m_pPointer;
    if ( v9 )
    {
      ++v6;
      if ( v4->mInterestPointType->mItemListMatchesWeapons )
      {
        v10 = v9->m_Flags;
        if ( (v10 >> 14) & 1 )
        {
          v11 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             (UFG::SimObjectGame *)&v9->vfptr,
                                                             UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
        }
        else if ( (v10 & 0x8000u) == 0 )
        {
          if ( (v10 >> 13) & 1 )
            v11 = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v9);
          else
            v11 = (UFG::SimObjectWeaponPropertiesComponent *)((v10 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                                  (UFG::SimObjectGame *)&v9->vfptr,
                                                                                  UFG::SimObjectWeaponPropertiesComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v9->vfptr, UFG::SimObjectWeaponPropertiesComponent::_TypeUID));
        }
        else
        {
          v11 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             (UFG::SimObjectGame *)&v9->vfptr,
                                                             UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
        }
        if ( v11 )
        {
          v5 = 1;
          break;
        }
      }
      v12 = v9->m_Flags;
      if ( !((v12 >> 14) & 1) && (v12 & 0x8000u) == 0 )
      {
        if ( (v12 >> 13) & 1 )
          v13 = v9->m_Components.p[11].m_pComponent;
        else
          v13 = (v12 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                    (UFG::SimObjectGame *)&v9->vfptr,
                                    UFG::InventoryItemComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                               (UFG::SimObject *)&v9->vfptr,
                                                                               UFG::InventoryItemComponent::_TypeUID);
        if ( v13 )
        {
          v14 = (int)v13[1].m_pSimObject;
          if ( v14 )
          {
            v15 = v4->mInterestPointType;
            v16 = 0;
            v17 = v15->mUseItemList.size;
            if ( v17 )
            {
              v18 = v15->mUseItemList.p;
              while ( v14 != *v18 )
              {
                ++v16;
                ++v18;
                if ( v16 >= v17 )
                  goto LABEL_35;
              }
              v5 = 1;
            }
          }
        }
      }
    }
LABEL_35:
    ++v7;
    ++v8;
    if ( v7 >= 2 )
      break;
  }
  if ( v4->mInterestPointType->mItemListMatchesNoItem && !v6 )
    v5 = 1;
  result = 1;
  if ( (unsigned __int8)v5 ^ v4->mPropertiesHandle.mProperties->mItemListIsAllowed )
    result = 0;
  return result;
}

// File Line: 3810
// RVA: 0x585000
char __fastcall UFG::InterestPoint::IsRelevantToPlayer(UFG::InterestPoint *this, UFG::SimObject *pCharacter, UFG::qVector3 *characterPosition)
{
  UFG::qVector3 *v3; // rbp
  UFG::SimObjectCVBase *v4; // rdi
  UFG::InterestPoint *v5; // rbx
  char result; // al
  float v7; // xmm0_4
  __int128 v8; // xmm0
  UFG::InterestPointProperties *v9; // rax
  float v10; // xmm0_4
  UFG::SimObjectCharacterPropertiesComponent *v11; // rcx
  unsigned __int16 v12; // cx
  UFG::SimObjectCharacterPropertiesComponent *v13; // rax
  UFG::InterestPointProperties *v14; // rsi
  unsigned int v15; // edx
  UFG::qStaticSymbol *v16; // rax
  char v17; // al
  UFG::SimObjectCharacter *v18; // rax
  UFG::SimComponentHolder *v19; // rax
  UFG::TransformNodeComponent *v20; // rdi
  __m128 v21; // xmm7
  float v22; // xmm6_4

  v3 = characterPosition;
  v4 = (UFG::SimObjectCVBase *)pCharacter;
  v5 = this;
  if ( !this->mInterestPointType->mBehaviour || this->mpPedInfoUser || !this->mActive )
    return 0;
  v7 = this->mPropertiesHandle.mProperties->mTimeOfDayToBecomeActive
     - this->mPropertiesHandle.mProperties->mTimeOfDayToBecomeInactive;
  if ( v7 < 0.0 )
    LODWORD(v7) ^= _xmm[0];
  if ( v7 >= 0.001 )
  {
    v8 = LODWORD(UFG::TimeOfDayManager::GetInstance()->m_SecondsSinceMidnight);
    v9 = v5->mPropertiesHandle.mProperties;
    v10 = *(float *)&v8 * 0.00027777778;
    if ( v10 > v9->mTimeOfDayToBecomeActive && v10 < v9->mTimeOfDayToBecomeInactive )
      return 0;
  }
  if ( v4 )
  {
    v12 = v4->m_Flags;
    if ( (v12 >> 14) & 1 )
    {
      v13 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v4);
    }
    else if ( (v12 & 0x8000u) == 0 )
    {
      if ( (v12 >> 13) & 1 )
      {
        v13 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                              (UFG::SimObjectGame *)&v4->vfptr,
                                                              UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
      }
      else if ( (v12 >> 12) & 1 )
      {
        v13 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                              (UFG::SimObjectGame *)&v4->vfptr,
                                                              UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
      }
      else
      {
        v13 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                              (UFG::SimObject *)&v4->vfptr,
                                                              UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
      }
    }
    else
    {
      v13 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v4);
    }
    v11 = v13;
  }
  else
  {
    v11 = 0i64;
  }
  v14 = v5->mPropertiesHandle.mProperties;
  v15 = v14->mGendersAllowed.mUID;
  if ( v15 != qSymbol_Any.mUID )
  {
    v16 = &qSymbol_Female;
    if ( v11->m_eGender == 1 )
      v16 = &qSymbol_Male;
    if ( v15 != v16->mUID )
      goto LABEL_39;
  }
  if ( v14->mUseClassList.size )
  {
    v17 = UFG::SimObjectUtility::IsClassTypeInArray((UFG::SimObject *)&v4->vfptr, &v14->mUseClassList);
    v14 = v5->mPropertiesHandle.mProperties;
    if ( (unsigned __int8)v17 ^ v14->mClassListIsAllowed )
      goto LABEL_39;
  }
  if ( v14->mWeatherFilterOn
    && v14->mWeatherFilterIsRaining != 1.0 < UFG::TimeOfDayManager::GetInstance()->m_WeatherState )
  {
    goto LABEL_39;
  }
  if ( v5->mPropertiesHandle.mProperties->mMaxDistanceFromPlayer < 0.0 )
    goto LABEL_40;
  v18 = UFG::GetLocalPlayer();
  if ( !v18 )
    goto LABEL_40;
  v19 = v18->m_Components.p;
  v20 = (UFG::TransformNodeComponent *)v19[2].m_pComponent;
  if ( !v20 )
    goto LABEL_40;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v19[2].m_pComponent);
  v21 = (__m128)LODWORD(v3->y);
  v22 = v3->x - v20->mWorldTransform.v3.x;
  v21.m128_f32[0] = v21.m128_f32[0] - v20->mWorldTransform.v3.y;
  UFG::TransformNodeComponent::UpdateWorldTransform(v20);
  v21.m128_f32[0] = (float)(v21.m128_f32[0] * v21.m128_f32[0]) + (float)(v22 * v22);
  if ( COERCE_FLOAT(_mm_sqrt_ps(v21)) > v5->mPropertiesHandle.mProperties->mMaxDistanceFromPlayer )
LABEL_39:
    result = 0;
  else
LABEL_40:
    result = 1;
  return result;
}

// File Line: 4047
// RVA: 0x581740
UFG::InterestPoint *__fastcall UFG::InterestPoint::FindNearestRelevent(UFG::SimObjectCharacter *pCharacter, bool bIsPlayer, UFG::InterestPointUserComponent *pInterestPointUserComp, UFG::TargetingSystemPedBaseComponent *pCharacterTargetComp, UFG::ActiveAIEntityComponent *pAAEC, UFG::qMatrix44 *characterTransform, UFG::qVector3 *vPlayerPosition, UFG::qSymbol *type, unsigned int matchReservationFlags, float maxDistSquared, float *pDistSquared, UFG::qArray<UFG::InterestPointQuery::Candidate,0> *pCandidates, UFG::qFixedArray<UFG::InterestPoint *,4> *apNearestPOIWithBehaviour)
{
  UFG::TargetingSystemPedBaseComponent *v13; // r13
  UFG::InterestPointUserComponent *v14; // rsi
  bool v15; // bl
  UFG::SimObjectCharacter *v16; // rdi
  __int64 v18; // r12
  float v19; // xmm8_4
  float v20; // xmm9_4
  unsigned int v21; // er15
  unsigned int v22; // eax
  signed __int64 v23; // r8
  UFG::TargetingSimObject *v24; // rcx
  float v25; // xmm4_4
  UFG::GridIntrusive<UFG::InterestPoint> *v26; // r14
  float v27; // xmm3_4
  float v28; // xmm5_4
  signed int v29; // ebx
  signed int v30; // edi
  __int64 v31; // r10
  signed int v32; // er9
  int v33; // er8
  int v34; // ecx
  unsigned int v35; // edx
  signed __int64 v36; // r11
  signed __int64 v37; // rbp
  __int64 v38; // rsi
  __int64 v39; // r9
  signed __int64 v40; // r8
  __int64 v41; // r10
  __int64 *v42; // rax
  __int64 v43; // rcx
  __int64 v44; // rax
  signed __int64 v45; // r13
  UFG::InterestPoint *v46; // rsi
  signed __int64 v47; // rbp
  UFG::qVector3 *poiWorldPos; // rbx
  int v49; // xmm7_4
  bool bSkipChecksInPlayerRel; // r11
  __int64 v51; // rdx
  __int64 v52; // rax
  unsigned int v53; // er9
  __int64 v54; // rdx
  int *v55; // r8
  __int64 v56; // rdx
  UFG::InterestPoint **v57; // r8
  float v58; // xmm0_4
  float *v59; // rax
  float v60; // xmm6_4
  float v61; // xmm6_4
  __int64 v62; // rdi
  unsigned int v63; // ebx
  unsigned int v64; // edx
  unsigned int v65; // edx
  float v66; // xmm0_4
  __int64 v67; // r9
  UFG::SimObjectCharacterPropertiesComponent *pCharacterPropertiesComponent; // [rsp+20h] [rbp-258h]
  unsigned __int8 v69; // [rsp+80h] [rbp-1F8h]
  float appealScale; // [rsp+84h] [rbp-1F4h]
  unsigned int v71; // [rsp+88h] [rbp-1F0h]
  int v72[5]; // [rsp+8Ch] [rbp-1ECh]
  UFG::InterestPoint *v73; // [rsp+A0h] [rbp-1D8h]
  __int64 v74; // [rsp+A8h] [rbp-1D0h]
  UFG::SimObject *pSimObject; // [rsp+B0h] [rbp-1C8h]
  __int64 *v76; // [rsp+B8h] [rbp-1C0h]
  UFG::SpawnPoint *pCharacterSpawnPoint; // [rsp+C0h] [rbp-1B8h]
  UFG::SimObjectCharacterPropertiesComponent *v78; // [rsp+C8h] [rbp-1B0h]
  __int64 v79; // [rsp+D0h] [rbp-1A8h]
  __int64 v80[25]; // [rsp+E0h] [rbp-198h]
  int v81; // [rsp+1A8h] [rbp-D0h]
  UFG::SimObjectCharacter *pCharactera; // [rsp+280h] [rbp+8h]
  bool v83; // [rsp+288h] [rbp+10h]
  UFG::InterestPointUserComponent *pInterestPointUserCompa; // [rsp+290h] [rbp+18h]
  UFG::TargetingSystemPedBaseComponent *pCharacterTargetCompa; // [rsp+298h] [rbp+20h]

  pCharacterTargetCompa = pCharacterTargetComp;
  pInterestPointUserCompa = pInterestPointUserComp;
  v83 = bIsPlayer;
  pCharactera = pCharacter;
  v79 = -2i64;
  v13 = pCharacterTargetComp;
  v14 = pInterestPointUserComp;
  v15 = bIsPlayer;
  v16 = pCharacter;
  if ( !pCharacter )
    return 0i64;
  if ( !pCharacter->m_pSceneObj )
    return 0i64;
  v78 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>((UFG::SimObjectCVBase *)&pCharacter->vfptr);
  if ( !v78 )
    return 0i64;
  if ( v15 )
    pCharacterSpawnPoint = 0i64;
  else
    pCharacterSpawnPoint = (UFG::SpawnPoint *)UFG::GetOriginatingSpawnPoint((UFG::SimObject *)&v16->vfptr);
  v18 = 0i64;
  v73 = 0i64;
  v19 = 0.0;
  v20 = maxDistSquared;
  v21 = 0;
  v71 = 0;
  pSimObject = 0i64;
  v69 = 0;
  v22 = qSymbol_look.mUID;
  if ( v14 )
  {
    if ( v13 )
    {
      v23 = (unsigned __int8)v13->m_pTargetingMap->m_Map.p[(type->mUID != qSymbol_look.mUID) + 25];
      v24 = v13->m_pTargets;
      pSimObject = v24[v23].m_pTarget.m_pPointer;
      if ( !pSimObject || (v69 = 1, !v24[v23].m_bLock) )
        v69 = 0;
    }
  }
  LODWORD(v25) = (unsigned __int128)_mm_sqrt_ps((__m128)LODWORD(maxDistSquared));
  v26 = UFG::InterestPoint::mspUseInterestPointGrid;
  if ( type->mUID == qSymbol_look.mUID )
    v26 = UFG::InterestPoint::mspLookInterestPointGrid;
  v27 = characterTransform->v3.y;
  v28 = v26->mGridSizeInv;
  v29 = (signed int)(float)((float)((float)(characterTransform->v3.x - v25) - v26->mXMin) * v28);
  if ( v29 < 0 )
    v29 = 0;
  v30 = (signed int)(float)((float)((float)(characterTransform->v3.x + v25) - v26->mXMin) * v28);
  v31 = v26->mXDim;
  if ( v30 >= (signed int)v31 )
    v30 = v31 - 1;
  v32 = (signed int)(float)((float)((float)(v27 - v25) - v26->mYMin) * v28);
  if ( v32 < 0 )
    v32 = 0;
  v33 = (signed int)(float)((float)((float)(v27 + v25) - v26->mYMin) * v28);
  v34 = v26->mYDim;
  if ( v33 >= v34 )
    v33 = v34 - 1;
  v35 = 0;
  v81 = 0;
  if ( v32 <= v33 )
  {
    v36 = 16i64 * (v29 + v32 * (signed int)v31);
    v37 = 16 * v31;
    v38 = (unsigned int)(v33 - v32 + 1);
    do
    {
      if ( v29 <= v30 )
      {
        v39 = (__int64)v26->mGridNodes + v36;
        v40 = v39 - 184;
        v41 = (unsigned int)(v30 - v29 + 1);
        do
        {
          if ( *(_QWORD *)(v40 + 192) - 184i64 != v40 )
          {
            v80[v35] = v39;
            v35 = v81++ + 1;
          }
          v39 += 16i64;
          v40 += 16i64;
          --v41;
        }
        while ( v41 );
      }
      v36 += v37;
      --v38;
    }
    while ( v38 );
  }
  if ( v35 )
  {
    v42 = v80;
    v76 = v80;
    v43 = v35;
    v74 = v35;
    do
    {
      v44 = *v42;
      v45 = v44 - 184;
      v46 = (UFG::InterestPoint *)(*(_QWORD *)(v44 + 8) - 184i64);
      if ( v46 != (UFG::InterestPoint *)(v44 - 184) )
      {
        do
        {
          v47 = (signed __int64)&v46->mNext[-12].mNext;
          if ( v46->mPoiType.mUID != -1 )
          {
            poiWorldPos = UFG::InterestPoint::GetPosition(v46);
            *(float *)&v49 = (float)((float)((float)(characterTransform->v3.x - poiWorldPos->x)
                                           * (float)(characterTransform->v3.x - poiWorldPos->x))
                                   + (float)((float)(characterTransform->v3.y - poiWorldPos->y)
                                           * (float)(characterTransform->v3.y - poiWorldPos->y)))
                           + (float)((float)(characterTransform->v3.z - poiWorldPos->z)
                                   * (float)(characterTransform->v3.z - poiWorldPos->z));
            if ( *(float *)&v49 < maxDistSquared )
            {
              if ( v83
                && UFG::InterestPoint::IsRelevantToPlayer(
                     v46,
                     (UFG::SimObject *)&pCharactera->vfptr,
                     (UFG::qVector3 *)&characterTransform->v3) )
              {
                bSkipChecksInPlayerRel = 1;
                v51 = apNearestPOIWithBehaviour->size;
                v52 = 0i64;
                v53 = 0;
                while ( 1 )
                {
                  if ( v52 >= v51 )
                  {
                    v71 = v21 + 1;
                    v72[v21] = v49;
                    apNearestPOIWithBehaviour->size = v51 + 1;
                    apNearestPOIWithBehaviour->p[v51] = v46;
                    v21 = v71;
                    goto LABEL_54;
                  }
                  if ( *(float *)&v49 < *(float *)&v72[v52] )
                    break;
                  ++v53;
                  if ( ++v52 >= 4 )
                    goto LABEL_54;
                }
                if ( (_DWORD)v51 == 4 )
                {
                  apNearestPOIWithBehaviour->size = 3;
                  v21 = 3;
                  v71 = 3;
                }
                v71 = v21 + 1;
                LODWORD(v54) = v21;
                if ( v21 > v53 )
                {
                  v55 = &v72[v21];
                  do
                  {
                    v54 = (unsigned int)(v54 - 1);
                    *v55 = v72[v54];
                    --v55;
                  }
                  while ( (unsigned int)v54 > v53 );
                }
                v72[v53] = v49;
                v56 = ++apNearestPOIWithBehaviour->size - 1;
                if ( (unsigned int)v56 > v53 )
                {
                  v57 = &apNearestPOIWithBehaviour->p[v56];
                  do
                  {
                    v56 = (unsigned int)(v56 - 1);
                    *v57 = apNearestPOIWithBehaviour->p[v56];
                    --v57;
                  }
                  while ( (unsigned int)v56 > v53 );
                }
                apNearestPOIWithBehaviour->p[v53] = v46;
                v21 = v71;
              }
              else
              {
                bSkipChecksInPlayerRel = 0;
              }
LABEL_54:
              if ( *(float *)&v49 < (float)(v46->mPropertiesHandle.mProperties->mMaxAppealRadius
                                          * v46->mPropertiesHandle.mProperties->mMaxAppealRadius) )
              {
                appealScale = 1.0;
                if ( (!v83 || bSkipChecksInPlayerRel)
                  && UFG::InterestPoint::IsRelevantToCharacter(
                       v46,
                       (UFG::SimObject *)&pCharactera->vfptr,
                       pCharacterTargetCompa,
                       pInterestPointUserCompa,
                       v78,
                       pAAEC,
                       vPlayerPosition,
                       pCharacterSpawnPoint,
                       characterTransform,
                       poiWorldPos,
                       &appealScale,
                       type,
                       matchReservationFlags,
                       ReserveReason_normal,
                       bSkipChecksInPlayerRel) )
                {
                  v58 = fsqrt(*(float *)&v49);
                  v59 = (float *)v46->mPropertiesHandle.mProperties;
                  if ( v58 >= v59[12] )
                    v60 = (float)((float)(v59[11] - v58) / (float)(v59[11] - v59[12])) * v59[10];
                  else
                    v60 = v59[10];
                  v61 = v60 * appealScale;
                  if ( pCandidates )
                  {
                    v62 = pCandidates->size;
                    v63 = v62 + 1;
                    v64 = pCandidates->capacity;
                    if ( (signed int)v62 + 1 > v64 )
                    {
                      if ( v64 )
                        v65 = 2 * v64;
                      else
                        v65 = 1;
                      for ( ; v65 < v63; v65 *= 2 )
                        ;
                      if ( v65 - v63 > 0x10000 )
                        v65 = v62 + 65537;
                      UFG::qArray<UFG::InterestPointQuery::Candidate,0>::Reallocate(
                        pCandidates,
                        v65,
                        "InterestPointQuery::Candidate");
                    }
                    pCandidates->size = v63;
                    UFG::InterestPointQuery::Candidate::Init(&pCandidates->p[v62], v46, v61);
                  }
                  v66 = v19 - v61;
                  if ( (float)(v19 - v61) < 0.0 )
                    LODWORD(v66) ^= _xmm[0];
                  if ( v66 < 0.001 && *(float *)&v49 < v20 || v19 < v61 )
                  {
                    v73 = v46;
                    v20 = *(float *)&v49;
                    v19 = v61;
                  }
                }
              }
            }
          }
          v46 = (UFG::InterestPoint *)v47;
        }
        while ( v47 != v45 );
        v43 = v74;
      }
      v42 = v76 + 1;
      ++v76;
      v74 = --v43;
    }
    while ( v43 );
    v22 = qSymbol_look.mUID;
    v18 = (__int64)v73;
    v13 = pCharacterTargetCompa;
  }
  if ( pDistSquared )
  {
    *pDistSquared = v20;
    v22 = qSymbol_look.mUID;
  }
  if ( v13 )
  {
    UFG::TargetingSystemBaseComponent::SetTarget(
      (UFG::TargetingSystemBaseComponent *)&v13->vfptr,
      (UFG::eTargetTypeEnum)((type->mUID != v22) + 25),
      pSimObject);
    LODWORD(pCharacterPropertiesComponent) = 0;
    LOBYTE(v67) = 1;
    ((void (__fastcall *)(UFG::TargetingSystemPedBaseComponent *, _QWORD, _QWORD, __int64, UFG::SimObjectCharacterPropertiesComponent *, const char *, _QWORD, _QWORD))v13->vfptr[14].__vecDelDtor)(
      v13,
      (unsigned int)(type->mUID != qSymbol_look.mUID) + 25,
      v69,
      v67,
      pCharacterPropertiesComponent,
      "InterestPoint::FindNearestRelevent",
      0i64,
      0i64);
  }
  return (UFG::InterestPoint *)v18;
}

// File Line: 4315
// RVA: 0x585560
void __fastcall UFG::InterestPoint::ListParents(int childNum)
{
  int v1; // ebp
  unsigned int v2; // edi
  const char *v3; // rdx
  Render::SkinningCacheNode *v4; // rax
  signed __int64 v5; // rbx
  __int64 v6; // rax
  __int64 v7; // rcx
  unsigned int v8; // esi
  char *v9; // rax
  UFG::qBaseTreeRB *v10; // rax
  UFG::qBaseTreeRB *i; // rax
  signed __int64 v12; // rbx
  __int64 v13; // rax
  __int64 v14; // rcx
  unsigned int v15; // esi
  char *v16; // rax

  v1 = childNum;
  v2 = childNum;
  if ( childNum < 0 )
    v2 = -childNum;
  v3 = "greater than";
  if ( childNum >= 0 )
    v3 = "exactly";
  ADebug::print_format("InterestPoint objects with %s %u children:\n", v3, v2);
  v4 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::InterestPoint::msUseInterestPoints);
  if ( v4 )
    v5 = (signed __int64)&v4[-4].mNode.mUID;
  else
    v5 = 0i64;
  while ( v5 )
  {
    v6 = *(_QWORD *)(v5 + 40);
    if ( v6 )
      v7 = *(_QWORD *)(v6 + 80);
    else
      v7 = 0i64;
    v8 = *(_DWORD *)(v7 + 120);
    if ( v1 >= 0 )
    {
      if ( v8 != v2 )
        goto LABEL_17;
LABEL_16:
      v9 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)(v5 + 64));
      ADebug::print_format("  %s : %u\n", v9, v8);
      goto LABEL_17;
    }
    if ( v8 >= v2 )
      goto LABEL_16;
LABEL_17:
    v10 = UFG::qBaseTreeRB::GetNext(&UFG::InterestPoint::msUseInterestPoints.mTree, (UFG::qBaseNodeRB *)(v5 + 136));
    if ( v10 )
      v5 = (signed __int64)v10[-2].mRoot.mChild;
    else
      v5 = 0i64;
  }
  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::InterestPoint::msLookInterestPoints);
        ;
        i = UFG::qBaseTreeRB::GetNext(&UFG::InterestPoint::msLookInterestPoints.mTree, (UFG::qBaseNodeRB *)(v12 + 136)) )
  {
    v12 = (signed __int64)(i ? i[-2].mRoot.mChild : 0i64);
    if ( !v12 )
      break;
    v13 = *(_QWORD *)(v12 + 40);
    if ( v13 )
      v14 = *(_QWORD *)(v13 + 80);
    else
      v14 = 0i64;
    v15 = *(_DWORD *)(v14 + 120);
    if ( v1 < 0 )
    {
      if ( v15 < v2 )
        continue;
LABEL_32:
      v16 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)(v12 + 64));
      ADebug::print_format("  %s : %u\n", v16, v15);
      continue;
    }
    if ( v15 == v2 )
      goto LABEL_32;
  }
}

// File Line: 4350
// RVA: 0x582170
void UFG::InterestPoint::ForceUpdateCanPathTo(void)
{
  Render::SkinningCacheNode *v0; // rax
  UFG::InterestPoint *v1; // rbx
  UFG::qVector3 *v2; // rdi
  bool v3; // al
  char v4; // cl
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList> *v5; // rcx
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList> *v6; // rax
  UFG::qBaseTreeRB *v7; // rax

  v0 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::InterestPoint::msUseInterestPoints);
  v1 = (UFG::InterestPoint *)&v0[-4].mNode.mUID;
  if ( !v0 )
    v1 = 0i64;
  while ( v1 )
  {
    if ( v1->mCanPathToCached.mValue != 1 )
    {
      if ( v1->mpXformNode )
      {
        v2 = UFG::InterestPoint::GetPosition(v1);
        if ( ((unsigned __int8 (__fastcall *)(UFG::NavManager *, UFG::qVector3 *))UFG::NavManager::ms_pInstance->vfptr->IsInsideAIMesh)(
               UFG::NavManager::ms_pInstance,
               v2) )
        {
          v1->mCanPathToCached.mValue = 1;
        }
        else
        {
          v3 = UFG::NavManager::ms_pInstance->vfptr->IsAIMeshLoadedAt(UFG::NavManager::ms_pInstance, v2);
          v4 = 2;
          if ( v3 )
            v4 = 0;
          v1->mCanPathToCached.mValue = v4;
        }
      }
      else
      {
        v1->mCanPathToCached.mValue = 3;
      }
      if ( v1->mCanPathToCached.mValue == 2 )
      {
        v5 = (UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList> *)&v1->mPrev;
        if ( v5->mPrev == v5
          && (UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList> **)v1->mNext == &v1->mPrev )
        {
          v6 = UFG::InterestPoint::msCellNotLoadedCanPathList.mNode.mPrev;
          UFG::InterestPoint::msCellNotLoadedCanPathList.mNode.mPrev->mNext = v5;
          v5->mPrev = v6;
          v1->mNext = (UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList> *)&UFG::InterestPoint::msCellNotLoadedCanPathList;
          UFG::InterestPoint::msCellNotLoadedCanPathList.mNode.mPrev = (UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList> *)&v1->mPrev;
        }
      }
    }
    v7 = UFG::qBaseTreeRB::GetNext(&UFG::InterestPoint::msUseInterestPoints.mTree, &v1->mNode);
    if ( v7 )
      v1 = (UFG::InterestPoint *)v7[-2].mRoot.mChild;
    else
      v1 = 0i64;
  }
}

// File Line: 4382
// RVA: 0x582940
float __fastcall UFG::InterestPoint::GetSpawnAmbientUserDistance(UFG::InterestPoint *this)
{
  return this->mPropertiesHandle.mProperties->mSpawnAmbientUserDistance;
}

// File Line: 4394
// RVA: 0x58DF10
void __fastcall UFG::InterestPoint::UpdateCanPathToCached(UFG::InterestPoint *this)
{
  UFG::InterestPoint *v1; // rbx
  UFG::qVector3 *v2; // rdi
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList> *v3; // rcx
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList> *v4; // rax

  v1 = this;
  if ( this->mpXformNode )
  {
    v2 = UFG::InterestPoint::GetPosition(this);
    if ( ((unsigned __int8 (__fastcall *)(UFG::NavManager *, UFG::qVector3 *))UFG::NavManager::ms_pInstance->vfptr->IsInsideAIMesh)(
           UFG::NavManager::ms_pInstance,
           v2) )
    {
      v1->mCanPathToCached.mValue = 1;
    }
    else if ( UFG::NavManager::ms_pInstance->vfptr->IsAIMeshLoadedAt(UFG::NavManager::ms_pInstance, v2) )
    {
      v1->mCanPathToCached.mValue = 0;
    }
    else
    {
      v1->mCanPathToCached.mValue = 2;
    }
  }
  else
  {
    this->mCanPathToCached.mValue = 3;
  }
  if ( v1->mCanPathToCached.mValue == 2 )
  {
    v3 = (UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList> *)&v1->mPrev;
    if ( v3->mPrev == v3
      && (UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList> **)v1->mNext == &v1->mPrev )
    {
      v4 = UFG::InterestPoint::msCellNotLoadedCanPathList.mNode.mPrev;
      UFG::InterestPoint::msCellNotLoadedCanPathList.mNode.mPrev->mNext = v3;
      v3->mPrev = v4;
      v1->mNext = (UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList> *)&UFG::InterestPoint::msCellNotLoadedCanPathList;
      UFG::InterestPoint::msCellNotLoadedCanPathList.mNode.mPrev = (UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList> *)&v1->mPrev;
    }
  }
}

// File Line: 4442
// RVA: 0x58B380
void __fastcall UFG::InterestPoint::ResetInterestPoint(UFG::InterestPoint *this)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v1; // rdx
  UFG::InterestPoint *v2; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::InterestPointUserComponent> *v5; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::CharacterAnimationComponent> *v8; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::GridIntrusive<UFG::InterestPoint> *v11; // r8
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint> *v12; // rcx
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint> *v13; // rax
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList> *v14; // rdx
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList> *v15; // rcx
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList> *v16; // rax

  v1 = &this->mpUser;
  v2 = this;
  this->mBeginningScriptInfo.mpCachedScript = 0i64;
  *(_WORD *)&this->mBeginningScriptInfo.mHasScript = 0;
  this->mEndingScriptInfo.mpCachedScript = 0i64;
  *(_WORD *)&this->mEndingScriptInfo.mHasScript = 0;
  this->mOnReservationScriptInfo.mpCachedScript = 0i64;
  *(_WORD *)&this->mOnReservationScriptInfo.mHasScript = 0;
  if ( this->mpUser.m_pPointer )
  {
    v3 = v1->mPrev;
    v4 = v1->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v1->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mPrev;
    v1->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mPrev;
  }
  v1->m_pPointer = 0i64;
  v5 = &v2->mpInterestPointUserComponent;
  if ( v2->mpInterestPointUserComponent.m_pPointer )
  {
    v6 = v5->mPrev;
    v7 = v2->mpInterestPointUserComponent.mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
    v2->mpInterestPointUserComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mpInterestPointUserComponent.mPrev;
  }
  v2->mpInterestPointUserComponent.m_pPointer = 0i64;
  v8 = &v2->mpParentCharacterAnimationComponent;
  *(_QWORD *)&v2->mUseTime = 0i64;
  *(_DWORD *)&v2->mIsReserved = 0;
  v2->mIsInterrupted = 0;
  *(_WORD *)&v2->mActive = 768;
  *(_QWORD *)&v2->mTimeSinceBeginUse = 0i64;
  v2->mPassedActivationChance = 1;
  v2->mBoneId = -1;
  if ( v2->mpParentCharacterAnimationComponent.m_pPointer )
  {
    v9 = v8->mPrev;
    v10 = v2->mpParentCharacterAnimationComponent.mNext;
    v9->mNext = v10;
    v10->mPrev = v9;
    v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
    v2->mpParentCharacterAnimationComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mpParentCharacterAnimationComponent.mPrev;
  }
  v2->mpParentCharacterAnimationComponent.m_pPointer = 0i64;
  if ( v2->mAddedToGrid )
  {
    v11 = UFG::InterestPoint::mspUseInterestPointGrid;
    v12 = v2->mPrev;
    v13 = v2->mNext;
    if ( v2->mPoiType.mUID == qSymbol_look.mUID )
      v11 = UFG::InterestPoint::mspLookInterestPointGrid;
    v12->mNext = v13;
    v13->mPrev = v12;
    v2->mPrev = (UFG::qNode<UFG::InterestPoint,UFG::InterestPoint> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::InterestPoint,UFG::InterestPoint> *)&v2->mPrev;
    --v11->mNodeCount;
  }
  v14 = (UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList> *)&v2->mPrev;
  v2->mPoiType = UFG::gNullQSymbol;
  v2->mGridIndex = -1;
  *(_WORD *)&v2->mAddedToGrid = 0;
  v2->mFullUpdateRequired = 0;
  v15 = v2->mPrev;
  v16 = v2->mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  v14->mPrev = v14;
  v14->mNext = v14;
  v2->mpPedInfoUser = 0i64;
}

// File Line: 4502
// RVA: 0x580F50
UFG::InterestPointType *__fastcall UFG::InterestPoint::FindInterestPointTypeR(UFG::qPropertySet *pProps)
{
  unsigned int v1; // edx
  UFG::qPropertySet *v2; // rdi
  UFG::InterestPointType *result; // rax
  unsigned int v4; // ebx
  unsigned int v5; // esi
  UFG::qPropertySet *v6; // rax

  v1 = pProps->mName.mUID;
  v2 = pProps;
  if ( !v1
    || (result = (UFG::InterestPointType *)UFG::qBaseTreeRB::Get(&UFG::InterestPoint::msInterestPointTypeTree.mTree, v1)) == 0i64 )
  {
    v4 = 0;
    v5 = UFG::qPropertySet::NumParents(v2);
    if ( v5 )
    {
      while ( 1 )
      {
        v6 = (UFG::qPropertySet *)UFG::qPropertySet::GetParentFromIdx(v2, v4);
        v2 = v6;
        result = UFG::InterestPoint::FindInterestPointTypeR(v6);
        if ( result )
          break;
        if ( ++v4 >= v5 )
          goto LABEL_6;
      }
    }
    else
    {
LABEL_6:
      result = 0i64;
    }
  }
  return result;
}

// File Line: 4557
// RVA: 0x588B60
void __fastcall UFG::InterestPoint::PropertiesLoad(UFG::InterestPoint *this, UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SceneObjectProperties *v2; // rsi
  UFG::InterestPoint *v3; // rbx
  UFG::qPropertySet *v4; // rax
  UFG::qPropertySet *v5; // rdi
  UFG::qPropertySet *v6; // rax
  char *v7; // rax
  unsigned int v8; // eax
  UFG::qTreeRB<UFG::InterestPoint,UFG::InterestPoint,1> *v9; // rcx
  UFG::InterestPointType *v10; // rax
  UFG::qPropertySet *v11; // rax
  UFG::PedSpawnManager *v12; // rax
  UFG::qVector3 *v13; // rax
  UFG::GridIntrusive<UFG::InterestPoint> *v14; // r9
  UFG::GridIntrusiveNode<UFG::InterestPoint> *v15; // rcx
  int v16; // er8
  UFG::qList<UFG::InterestPoint,UFG::InterestPoint,1,0> *v17; // rdx
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint> *v18; // rax

  v2 = pSceneObj;
  v3 = this;
  if ( this->m_pSimObject )
    UFG::InterestPoint::ResetInterestPoint(this);
  else
    UFG::MarkerBase::Initialize((UFG::MarkerBase *)&this->vfptr, pSceneObj->m_pSimObject);
  v4 = PropertyUtils::Get<UFG::qPropertySet>(v2, (UFG::qSymbol *)&qSymbolX_propset_componentPOI.mUID);
  v5 = v4;
  v6 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         v4,
         (UFG::qSymbol *)&component_InterestPoint::sPropertyName.mUID,
         DEPTH_RECURSE);
  if ( v6 )
  {
    v7 = UFG::qPropertySet::GetMemImagePtr(v6);
    if ( v7 )
    {
      v8 = *(_DWORD *)v7;
      v9 = &UFG::InterestPoint::msLookInterestPoints;
      v3->mPoiType.mUID = v8;
      if ( v8 != qSymbol_look.mUID )
        v9 = &UFG::InterestPoint::msUseInterestPoints;
      UFG::qBaseTreeRB::Add(&v9->mTree, &v3->mNode);
      if ( v3->mPoiType.mUID != -1 )
      {
        v10 = UFG::InterestPoint::FindInterestPointTypeR(v5);
        v3->mInterestPointType = v10;
        if ( !v10 )
        {
          v11 = (UFG::qPropertySet *)UFG::qPropertySet::GetParentFromIdx(v5, 0);
          v3->mInterestPointType = UFG::InterestPoint::AddInterestPointType(v11);
        }
        UFG::InterestPoint::LoadStaticProperties(v3, v5);
        UFG::InterestPoint::InitBasePOI(v3, v2);
        if ( v3->mPoiType.mUID != qSymbol_look.mUID )
        {
          UFG::InterestPoint::InitUsePOI(v3, v5);
          if ( v3->mPropertiesHandle.mProperties->mSpawnAmbientUserDistance > 0.0 )
          {
            v12 = UFG::PedSpawnManager::GetInstance();
            UFG::PedSpawnManager::RegisterSpawningPOI(v12, v3, v2);
          }
        }
        UFG::InterestPoint::UpdateInterestPointTransform(v3);
        v13 = UFG::InterestPoint::GetPosition(v3);
        v14 = UFG::InterestPoint::mspUseInterestPointGrid;
        if ( v3->mPoiType.mUID == qSymbol_look.mUID )
          v14 = UFG::InterestPoint::mspLookInterestPointGrid;
        v15 = (UFG::GridIntrusiveNode<UFG::InterestPoint> *)&v3->mPrev;
        v16 = (signed int)(float)((float)(v13->x - v14->mXMin) * v14->mGridSizeInv)
            + v14->mXDim * (signed int)(float)((float)(v13->y - v14->mYMin) * v14->mGridSizeInv);
        v17 = &v14->mGridNodes[v16];
        v18 = v17->mNode.mPrev;
        v18->mNext = (UFG::qNode<UFG::InterestPoint,UFG::InterestPoint> *)&v3->mPrev;
        v15->mPrev = v18;
        v15->mNext = &v17->mNode;
        v17->mNode.mPrev = (UFG::qNode<UFG::InterestPoint,UFG::InterestPoint> *)&v3->mPrev;
        ++v14->mNodeCount;
        v3->mGridIndex = v16;
        *(_WORD *)&v3->mAddedToGrid = 1;
        UFG::InterestPoint::InitAnimHandles(v3);
      }
    }
  }
}

// File Line: 4653
// RVA: 0x585DF0
void __fastcall UFG::InterestPoint::LoadStaticProperties(UFG::InterestPoint *this, UFG::qPropertySet *pProps)
{
  int v2; // ebx
  UFG::InterestPoint *v3; // rbp
  UFG::qPropertySet *v4; // rsi
  UFG::qBaseTreeRB *v5; // rdi
  int v6; // eax
  unsigned int v7; // edx

  v2 = pProps->mNumProperties;
  v3 = this;
  v4 = pProps;
  v5 = 0i64;
  v6 = UFG::qPropertySet::NumParents(pProps);
  if ( !v2 && v6 == 1 )
  {
    v7 = *(_DWORD *)&UFG::qPropertySet::GetParentFromIdx(v4, 0)->mDebugName[12];
    if ( v7 )
      v5 = UFG::qBaseTreeRB::Get(&UFG::gInterestPointCachedProperties.mTree, v7);
  }
  UFG::InterestPointPropertiesHandle::Load(&v3->mPropertiesHandle, (UFG::InterestPointProperties *)v5, v4);
}

// File Line: 4686
// RVA: 0x58B860
void __fastcall UFG::InterestPoint::SetBoneIDFromProperties(UFG::InterestPoint *this)
{
  UFG::InterestPoint *v1; // rbx
  UFG::SimComponent *v2; // rcx
  __int64 v3; // rcx
  signed int v4; // eax
  UFG::SimComponent *v5; // rax

  v1 = this;
  v2 = this->mpParentCharacterAnimationComponent.m_pPointer;
  if ( v2 )
  {
    v3 = *(_QWORD *)&v2[2].m_TypeUID;
    if ( v3 )
    {
      if ( *(_QWORD *)(v3 + 440) )
        v4 = Skeleton::GetBoneID(*(Skeleton **)(v3 + 480), v1->mPropertiesHandle.mProperties->mBoneName.mUID);
      else
        v4 = -1;
      v1->mBoneId = v4;
      v5 = v1->mpParentCharacterAnimationComponent.m_pPointer;
      v1->mNeedsBoneFixupWhenRigAvailable = BYTE1(v5[3].vfptr) || !*(_QWORD *)&v5[1].m_Flags;
    }
    else
    {
      v1->mNeedsBoneFixupWhenRigAvailable = 1;
    }
  }
}

// File Line: 4709
// RVA: 0x583160
void __fastcall UFG::InterestPoint::InitBasePOI(UFG::InterestPoint *this, UFG::SceneObjectProperties *pSceneObj)
{
  UFG::InterestPointProperties *v2; // r8
  UFG::InterestPoint *v3; // rbx
  UFG::SimObjectCVBase *v4; // rcx
  UFG::CharacterAnimationComponent *v5; // r8
  unsigned __int16 v6; // dx
  UFG::CharacterAnimationComponent *v7; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::CharacterAnimationComponent> *v8; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::InterestPointProperties *v12; // rdi

  v2 = this->mPropertiesHandle.mProperties;
  v3 = this;
  this->mActive = v2->mStartActive;
  if ( v2->mBoneName.mUID != -1 )
  {
    v4 = (UFG::SimObjectCVBase *)pSceneObj->mpParent->m_pSimObject;
    if ( v4 )
    {
      v6 = v4->m_Flags;
      if ( (v6 >> 14) & 1 )
      {
        v7 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v4);
      }
      else if ( (v6 & 0x8000u) == 0 )
      {
        if ( (v6 >> 13) & 1 )
        {
          v7 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v4);
        }
        else if ( (v6 >> 12) & 1 )
        {
          v7 = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                     (UFG::SimObjectGame *)&v4->vfptr,
                                                     UFG::CharacterAnimationComponent::_TypeUID);
        }
        else
        {
          v7 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                     (UFG::SimObject *)&v4->vfptr,
                                                     UFG::CharacterAnimationComponent::_TypeUID);
        }
      }
      else
      {
        v7 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v4);
      }
      v5 = v7;
    }
    else
    {
      v5 = 0i64;
    }
    v8 = &v3->mpParentCharacterAnimationComponent;
    if ( v3->mpParentCharacterAnimationComponent.m_pPointer )
    {
      v9 = v8->mPrev;
      v10 = v3->mpParentCharacterAnimationComponent.mNext;
      v9->mNext = v10;
      v10->mPrev = v9;
      v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
      v3->mpParentCharacterAnimationComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mpParentCharacterAnimationComponent.mPrev;
    }
    v3->mpParentCharacterAnimationComponent.m_pPointer = (UFG::SimComponent *)&v5->vfptr;
    if ( v5 )
    {
      v11 = v5->m_SafePointerList.mNode.mPrev;
      v11->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
      v8->mPrev = v11;
      v3->mpParentCharacterAnimationComponent.mNext = &v5->m_SafePointerList.mNode;
      v5->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
    }
    UFG::InterestPoint::SetBoneIDFromProperties(v3);
  }
  v12 = v3->mPropertiesHandle.mProperties;
  if ( v12->mPercentChanceIsActive >= 100.0 )
    v3->mPassedActivationChance = 1;
  else
    v3->mPassedActivationChance = UFG::qRandom(100.0, &UFG::qDefaultSeed) < v12->mPercentChanceIsActive;
}

// File Line: 4735
// RVA: 0x583DD0
void __fastcall UFG::InterestPoint::InitUsePOI(UFG::InterestPoint *this, UFG::qPropertySet *pProps)
{
  UFG::InterestPointType *v2; // rax
  const char *v3; // rsi
  char v4; // r8
  UFG::InterestPoint *v5; // rbx
  bool v6; // cl
  UFG::qPropertySet *v7; // r9
  bool v8; // dl
  UFG::qPropertySet *v9; // rax
  char *v10; // rdi
  __int64 v11; // rax
  const char *v12; // rdx
  __int64 v13; // rax
  const char *v14; // rcx
  __int64 v15; // rax
  const char *v16; // rdx
  __int64 v17; // rax
  const char *v18; // rcx
  __int64 v19; // rax
  const char *v20; // rdx
  __int64 v21; // rax
  unsigned int v22; // [rsp+40h] [rbp+8h]

  v2 = this->mInterestPointType;
  v3 = 0i64;
  this->mUseTime = -1.0;
  *(_QWORD *)&this->mCooldownTime = 0i64;
  this->mIsInterrupted = 0;
  v4 = v2->mHasBeginningScript;
  v5 = this;
  this->mBeginningScriptInfo.mHasScript = v4;
  v6 = v2->mHasEndingScript;
  v7 = pProps;
  v5->mEndingScriptInfo.mHasScript = v6;
  v8 = v2->mHasOnReservationScript;
  v5->mOnReservationScriptInfo.mHasScript = v8;
  if ( v4 || v6 || v8 )
  {
    v9 = UFG::qPropertySet::Get<UFG::qPropertySet>(
           v7,
           (UFG::qSymbol *)&schema_interestpoint_script::sPropertyName.mUID,
           DEPTH_RECURSE);
    if ( v9 )
      v10 = UFG::qPropertySet::GetMemImagePtr(v9);
    else
      v10 = 0i64;
    if ( v5->mBeginningScriptInfo.mHasScript )
    {
      v11 = *((_QWORD *)v10 + 3);
      if ( v11 )
        v12 = &v10[v11 + 24];
      else
        v12 = 0i64;
      v13 = *((_QWORD *)v10 + 1);
      if ( v13 )
        v14 = &v10[v13 + 8];
      else
        v14 = 0i64;
      v22 = v5->mInterestPointType->mBeginningScriptHash;
      v5->mBeginningScriptInfo.mpCachedScript = (UFG::ScriptCache::Script *)UFG::ScriptCache::GetScript(
                                                                              v14,
                                                                              v12,
                                                                              0i64,
                                                                              0i64);
    }
    if ( v5->mEndingScriptInfo.mHasScript )
    {
      v15 = *((_QWORD *)v10 + 4);
      if ( v15 )
        v16 = &v10[v15 + 32];
      else
        v16 = 0i64;
      v17 = *((_QWORD *)v10 + 2);
      if ( v17 )
        v18 = &v10[v17 + 16];
      else
        v18 = 0i64;
      v22 = v5->mInterestPointType->mEndingScriptHash;
      v5->mEndingScriptInfo.mpCachedScript = (UFG::ScriptCache::Script *)UFG::ScriptCache::GetScript(
                                                                           v18,
                                                                           v16,
                                                                           0i64,
                                                                           0i64);
    }
    if ( v5->mOnReservationScriptInfo.mHasScript )
    {
      v19 = *((_QWORD *)v10 + 7);
      if ( v19 )
        v20 = &v10[v19 + 56];
      else
        v20 = 0i64;
      v21 = *((_QWORD *)v10 + 6);
      if ( v21 )
        v3 = &v10[v21 + 48];
      v22 = v5->mInterestPointType->mOnReservationScriptHash;
      v5->mOnReservationScriptInfo.mpCachedScript = (UFG::ScriptCache::Script *)UFG::ScriptCache::GetScript(
                                                                                  v3,
                                                                                  v20,
                                                                                  0i64,
                                                                                  0i64);
    }
  }
}

// File Line: 4828
// RVA: 0x58AA70
void __fastcall UFG::InterestPoint::PropertiesSave(UFG::InterestPoint *this, UFG::SceneObjectProperties *pSceneObj)
{
  UFG::InterestPoint *v2; // rbx
  UFG::SceneObjectProperties *v3; // rdi
  UFG::qPropertySet *v4; // rax
  UFG::qPropertySet *v5; // rax

  v2 = this;
  v3 = pSceneObj;
  v4 = UFG::SceneObjectProperties::GetWritablePersistentProperties(pSceneObj);
  UFG::qPropertySet::RemovePropertyByName(v4, (UFG::qSymbol *)&qSymbolX_propset_componentPOI.mUID);
  v5 = UFG::SceneObjectProperties::GetWritablePersistentProperties(v3);
  UFG::InterestPoint::PropertiesAppendProperty(v5, &v2->mPoiType);
}

// File Line: 4857
// RVA: 0x58A360
UFG::InterestPoint *__fastcall UFG::InterestPoint::PropertiesOnActivate(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SceneObjectProperties *v1; // rsi
  UFG::qMemoryPool *v2; // rax
  UFG::allocator::free_link *v3; // rbp
  UFG::qSymbol *v4; // rax
  __int64 v5; // rax
  __int64 v6; // rdi
  UFG::qSymbol result; // [rsp+68h] [rbp+10h]
  UFG::allocator::free_link *v9; // [rsp+70h] [rbp+18h]

  v1 = pSceneObj;
  v2 = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(v2, 0x220ui64, "InterestPoint", 0i64, 1u);
  v9 = v3;
  if ( v3 )
  {
    v4 = UFG::SceneObjectProperties::operator UFG::qSymbol const(v1, &result);
    UFG::InterestPoint::InterestPoint((UFG::InterestPoint *)v3, v4);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  (*(void (__fastcall **)(__int64, UFG::SceneObjectProperties *))(*(_QWORD *)v6 + 96i64))(v6, v1);
  return (UFG::InterestPoint *)v6;
}

// File Line: 4874
// RVA: 0x588970
UFG::qPropertySet *__fastcall UFG::InterestPoint::PropertiesAppendProperty(UFG::qPropertySet *pProps, UFG::qSymbol *type)
{
  UFG::qSymbol *v2; // rbx
  UFG::qPropertySet *v3; // rsi
  UFG::qPropertySet *v4; // rdi
  UFG::qSymbol *v5; // rax
  UFG::qPropertySet *v6; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+18h]

  v2 = type;
  v3 = pProps;
  v4 = UFG::qPropertySet::CreateContainedSet((UFG::qSymbol *)&qSymbolX_propset_componentPOI.mUID, "InterestPointProps");
  v5 = UFG::InterestPoint::ConvertTypeToPropertiesName(&result, v2);
  v6 = UFG::PropertySetManager::GetPropertySet(v5);
  UFG::PSWrapper::AppendParentLocal(v4, v6);
  UFG::qPropertySet::Set<UFG::qPropertySet>(v3, (UFG::qSymbol *)&qSymbolX_propset_componentPOI.mUID, v4);
  return v4;
}

// File Line: 4935
// RVA: 0x585550
_BOOL8 __fastcall UFG::InterestPoint::IsTraversalsEnabled()
{
  return UFG::InterestPoint::msTraversalsEnabled;
}

// File Line: 5013
// RVA: 0x5826E0
UFG::qBaseNodeRB **__fastcall UFG::InterestPoint::GetNamed(UFG::qSymbol *name)
{
  unsigned int v1; // ebx
  UFG::qBaseTreeRB *v2; // rax
  UFG::qBaseNodeRB **result; // rax
  UFG::qBaseTreeRB *v4; // rax

  v1 = name->mUID;
  if ( !name->mUID )
    return 0i64;
  v2 = UFG::qBaseTreeRB::Get(&UFG::InterestPoint::msUseInterestPoints.mTree, v1);
  if ( !v2 || (result = v2[-2].mRoot.mChild) == 0i64 )
  {
    v4 = UFG::qBaseTreeRB::Get(&UFG::InterestPoint::msLookInterestPoints.mTree, v1);
    if ( v4 )
      return v4[-2].mRoot.mChild;
    return 0i64;
  }
  return result;
}

// File Line: 5097
// RVA: 0x57E5E0
__int64 __fastcall UFG::InterestPoint::AISectionLoadedCallback()
{
  unsigned int v0; // esi
  UFG::InterestPoint *v1; // rbx
  UFG::qList<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList,1,0> *v2; // rdi
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList> *v3; // rbx
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList> *v4; // rdx
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList> *v5; // rcx

  v0 = 0;
  v1 = (UFG::InterestPoint *)&UFG::InterestPoint::msCellNotLoadedCanPathList.mNode.mNext[-11].mNext;
  if ( &UFG::InterestPoint::msCellNotLoadedCanPathList.mNode.mNext[-11].mNext != (UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList> **)((char *)&UFG::InterestPoint::msCellNotLoadedCanPathList - 168) )
  {
    do
    {
      v2 = (UFG::qList<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList,1,0> *)&v1->mNext[-11].mNext;
      UFG::InterestPoint::UpdateCanPathToCached(v1);
      ++v0;
      if ( v1->mCanPathToCached.mValue != 2 )
      {
        v3 = (UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList> *)&v1->mPrev;
        v4 = v3->mPrev;
        v5 = v3->mNext;
        v4->mNext = v5;
        v5->mPrev = v4;
        v3->mPrev = v3;
        v3->mNext = v3;
      }
      v1 = (UFG::InterestPoint *)v2;
    }
    while ( v2 != (UFG::qList<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList,1,0> *)((char *)&UFG::InterestPoint::msCellNotLoadedCanPathList - 168) );
  }
  return v0;
}

// File Line: 5144
// RVA: 0x582760
UFG::qBaseNodeRB *__fastcall UFG::InterestPoint::GetParent(UFG::InterestPoint *this)
{
  UFG::SimObject *v1; // rax
  UFG::qBaseNodeRB *result; // rax

  v1 = this->m_pSimObject;
  if ( v1 )
    v1 = (UFG::SimObject *)v1->m_pSceneObj;
  result = (UFG::qBaseNodeRB *)v1->m_UnboundComponentHandles.mNode.mPrev;
  if ( result )
    result = result[1].mChild[0];
  return result;
}

// File Line: 5157
// RVA: 0x582780
UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *__fastcall UFG::InterestPoint::GetParentObject(UFG::InterestPoint *this)
{
  UFG::SimObject *v1; // rdi
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v2; // rdi
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v3; // rbx
  unsigned __int16 v4; // cx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rax

  v1 = this->m_pSimObject;
  if ( v1 )
    v1 = (UFG::SimObject *)v1->m_pSceneObj;
  v2 = v1->m_UnboundComponentHandles.mNode.mPrev;
  if ( !v2 )
    return 0i64;
  while ( 1 )
  {
    v3 = v2[2].mNext;
    if ( !v3 )
      break;
    v4 = WORD2(v3[4].mNext);
    if ( (v4 >> 14) & 1 )
    {
      v5 = v3[6].mNext[25].mPrev;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
        v5 = v3[6].mNext[10].mPrev;
      else
        v5 = (v4 >> 12) & 1 ? v3[6].mNext[3].mPrev : UFG::SimObject::GetComponentOfType(
                                                       (UFG::SimObject *)v2[2].mNext,
                                                       UFG::InterestPoint::_TypeUID);
    }
    else
    {
      v5 = v3[6].mNext[25].mPrev;
    }
    if ( !v5 )
      break;
    v2 = v2[7].mPrev;
    if ( !v2 )
      return 0i64;
  }
  return v3;
}

// File Line: 5178
// RVA: 0x5824A0
UFG::SimObject *__fastcall UFG::InterestPoint::GetChild(UFG::InterestPoint *this, unsigned int index)
{
  int v2; // edi
  unsigned int v3; // er14
  UFG::InterestPoint *v4; // rbp
  unsigned int v5; // esi
  UFG::SceneObjectProperties *v6; // rax
  UFG::SimObject *v7; // rax
  UFG::SimObject *v8; // rbx
  unsigned __int16 v9; // dx
  UFG::SimComponent *v10; // rax

  v2 = 0;
  v3 = index;
  v4 = this;
  v5 = 0;
  if ( UFG::SimComponent::GetSceneObj((UFG::SimComponent *)&this->vfptr)->mChildren.mCount <= 0 )
    return 0i64;
  while ( 1 )
  {
    v6 = UFG::SimComponent::GetSceneObj((UFG::SimComponent *)&v4->vfptr);
    v7 = UFG::SceneObjectProperties::GetChildAsSimObject(v6, v5);
    v8 = v7;
    if ( !v7 )
      goto LABEL_15;
    v9 = v7->m_Flags;
    if ( (v9 >> 14) & 1 )
    {
      v10 = v7->m_Components.p[25].m_pComponent;
    }
    else if ( (v9 & 0x8000u) == 0 )
    {
      if ( (v9 >> 13) & 1 )
        v10 = v7->m_Components.p[10].m_pComponent;
      else
        v10 = (v9 >> 12) & 1 ? v7->m_Components.p[3].m_pComponent : UFG::SimObject::GetComponentOfType(
                                                                      v7,
                                                                      UFG::InterestPoint::_TypeUID);
    }
    else
    {
      v10 = v7->m_Components.p[25].m_pComponent;
    }
    if ( !v10 )
      goto LABEL_15;
    if ( v2 == v3 )
      return v8;
    ++v2;
LABEL_15:
    if ( ++v5 >= UFG::SimComponent::GetSceneObj((UFG::SimComponent *)&v4->vfptr)->mChildren.mCount )
      return 0i64;
  }
}

// File Line: 5200
// RVA: 0x5823F0
UFG::SimObject *__fastcall UFG::InterestPoint::GetChild(UFG::InterestPoint *this, UFG::qSymbol *childName)
{
  int v2; // ebx
  UFG::qSymbol *v3; // r14
  UFG::InterestPoint *v4; // rsi
  unsigned int v5; // edi
  UFG::SceneObjectProperties *v6; // rax
  UFG::SimObject *v7; // rbp
  UFG::SceneObjectProperties *v8; // rcx
  bool v9; // al
  UFG::qSymbol result; // [rsp+60h] [rbp+18h]

  v2 = 0;
  v3 = childName;
  v4 = this;
  v5 = 0;
  if ( UFG::SimComponent::GetSceneObj((UFG::SimComponent *)&this->vfptr)->mChildren.mCount <= 0 )
    return 0i64;
  while ( 1 )
  {
    v6 = UFG::SimComponent::GetSceneObj((UFG::SimComponent *)&v4->vfptr);
    v7 = UFG::SceneObjectProperties::GetChildAsSimObject(v6, v5);
    v8 = v7->m_pSceneObj;
    v9 = 0;
    if ( v8 )
    {
      v2 |= 1u;
      if ( UFG::SceneObjectProperties::operator UFG::qSymbol const(v8, &result)->mUID == v3->mUID )
        v9 = 1;
    }
    if ( v2 & 1 )
      v2 &= 0xFFFFFFFE;
    if ( v9 )
      break;
    if ( ++v5 >= UFG::SimComponent::GetSceneObj((UFG::SimComponent *)&v4->vfptr)->mChildren.mCount )
      return 0i64;
  }
  return v7;
}

// File Line: 5214
// RVA: 0x58B670
void __fastcall UFG::InterestPoint::SetActive(UFG::InterestPoint *this, bool val, bool applyToChildren)
{
  bool v3; // bp
  bool v4; // si
  UFG::InterestPoint *v5; // rdi
  unsigned int i; // ebx
  UFG::SceneObjectProperties *v7; // rax
  UFG::SimObject *v8; // rax
  unsigned __int16 v9; // dx
  UFG::InterestPoint *v10; // rax

  v3 = applyToChildren;
  v4 = val;
  v5 = this;
  this->mActive = val;
  if ( !val )
    UFG::InterestPoint::EndReservation(this);
  if ( v3 )
  {
    for ( i = 0; i < UFG::SimComponent::GetSceneObj((UFG::SimComponent *)&v5->vfptr)->mChildren.mCount; ++i )
    {
      v7 = UFG::SimComponent::GetSceneObj((UFG::SimComponent *)&v5->vfptr);
      v8 = UFG::SceneObjectProperties::GetChildAsSimObject(v7, i);
      if ( v8 )
      {
        v9 = v8->m_Flags;
        if ( (v9 >> 14) & 1 )
        {
          v10 = (UFG::InterestPoint *)v8->m_Components.p[25].m_pComponent;
        }
        else if ( (v9 & 0x8000u) == 0 )
        {
          if ( (v9 >> 13) & 1 )
          {
            v10 = (UFG::InterestPoint *)v8->m_Components.p[10].m_pComponent;
          }
          else if ( (v9 >> 12) & 1 )
          {
            v10 = (UFG::InterestPoint *)v8->m_Components.p[3].m_pComponent;
          }
          else
          {
            v10 = (UFG::InterestPoint *)UFG::SimObject::GetComponentOfType(v8, UFG::InterestPoint::_TypeUID);
          }
        }
        else
        {
          v10 = (UFG::InterestPoint *)v8->m_Components.p[25].m_pComponent;
        }
        if ( v10 )
          UFG::InterestPoint::SetActive(v10, v4, v3);
      }
    }
  }
}

