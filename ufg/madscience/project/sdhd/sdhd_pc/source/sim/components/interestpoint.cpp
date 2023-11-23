// File Line: 90
// RVA: 0x582330
signed __int64 __fastcall `anonymous namespace::GetActionMostUsedIndex_Interactions()
{
  signed __int64 result; // rax

  if ( (_S10_11 & 1) != 0 )
    return index_2;
  _S10_11 |= 1u;
  if ( (_S9_16 & 1) == 0 )
  {
    _S9_16 |= 1u;
    node_id.mUID = UFG::qStringHashUpper32("Interactions", -1);
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
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::InterestPoint::msLastUsedType__);
}

// File Line: 128
// RVA: 0x154D910
__int64 dynamic_initializer_for__UFG::InterestPoint::mspCharacterToShowPOIsFor__()
{
  UFG::InterestPoint::mspCharacterToShowPOIsFor.m_pPointer = 0i64;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::InterestPoint::mspCharacterToShowPOIsFor__);
}

// File Line: 130
// RVA: 0x154D860
__int64 dynamic_initializer_for__UFG::InterestPoint::msLookInterestPoints__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::InterestPoint::msLookInterestPoints.mTree);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::InterestPoint::msLookInterestPoints__);
}

// File Line: 131
// RVA: 0x154D8E0
__int64 dynamic_initializer_for__UFG::InterestPoint::msUseInterestPoints__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::InterestPoint::msUseInterestPoints.mTree);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::InterestPoint::msUseInterestPoints__);
}

// File Line: 133
// RVA: 0x154D7A0
__int64 dynamic_initializer_for__UFG::InterestPoint::msCellNotLoadedCanPathList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::InterestPoint::msCellNotLoadedCanPathList__);
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
    (char *)UFG::InterestPoint::msInterestPointTypePool.p,
    0xA8ui64,
    500,
    (void (__fastcall *)(void *))UFG::InterestPointType::InterestPointType);
  UFG::InterestPoint::msInterestPointTypePool.size = 0;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::InterestPoint::msInterestPointTypePool__);
}

// File Line: 141
// RVA: 0x154D820
__int64 dynamic_initializer_for__UFG::InterestPoint::msInterestPointTypeTree__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::InterestPoint::msInterestPointTypeTree.mTree);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::InterestPoint::msInterestPointTypeTree__);
}

// File Line: 277
// RVA: 0x57CC70
void __fastcall UFG::InterestPointProperties::InterestPointProperties(UFG::InterestPointProperties *this)
{
  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->mPriority = InterestPointPriority_None;
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
  UFG::TransformNodeComponent *mpXformNode; // rbx
  float y; // xmm0_4
  float z; // xmm1_4
  UFG::qVector3 *result; // rax

  if ( this->mIsPositionCached )
    return &this->mCachedPosition;
  mpXformNode = this->mpXformNode;
  UFG::TransformNodeComponent::UpdateWorldTransform(mpXformNode);
  y = mpXformNode->mWorldTransform.v3.y;
  z = mpXformNode->mWorldTransform.v3.z;
  this->mCachedPosition.x = mpXformNode->mWorldTransform.v3.x;
  result = &this->mCachedPosition;
  this->mCachedPosition.y = y;
  this->mCachedPosition.z = z;
  this->mIsPositionCached = 1;
  return result;
}

// File Line: 297
// RVA: 0x5856B0
void __fastcall UFG::InterestPointProperties::Load(
        UFG::InterestPointProperties *this,
        UFG::qPropertySet *pProps,
        component_InterestPoint *interest_point_data)
{
  UFG::qPropertySet *v6; // rax
  schema_classlist *MemImagePtr; // rbx

  v6 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         pProps,
         (UFG::qArray<unsigned long,0> *)&schema_classlist::sPropertyName,
         DEPTH_RECURSE);
  if ( v6 )
    MemImagePtr = (schema_classlist *)UFG::qPropertySet::GetMemImagePtr(v6);
  else
    MemImagePtr = 0i64;
  UFG::InterestPointProperties::LoadCommonProperties(this, pProps, interest_point_data, MemImagePtr);
  if ( interest_point_data->InterestPointType.mUID != qSymbol_look.mUID )
    UFG::InterestPointProperties::LoadUseProperties(this, pProps, interest_point_data, MemImagePtr);
}

// File Line: 311
// RVA: 0x5858B0
void __fastcall UFG::InterestPointProperties::LoadCommonProperties(
        UFG::InterestPointProperties *this,
        UFG::qPropertySet *pProps,
        component_InterestPoint *interest_point_data,
        schema_classlist *class_list_data)
{
  component_InterestPoint *v5; // r14
  UFG::InterestPointProperties *v6; // rbp
  UFG::qArray<UFG::qSymbol,0> *p_mUseClassList; // rdi
  UFG::qSymbol *p; // rcx
  UFG::qSymbol *v9; // rbx
  unsigned int v10; // esi
  __int64 mOffset; // rax
  unsigned int v12; // r12d
  UFG::qPropertyList *v13; // r14
  UFG::qSymbol *v14; // r13
  __int64 size; // r15
  unsigned int v16; // ebx
  unsigned int capacity; // edx
  unsigned int v18; // edx
  UFG::qSymbolUC v19; // [rsp+30h] [rbp-58h] BYREF
  __int64 v20; // [rsp+38h] [rbp-50h]
  UFG::qPropertyList **v21; // [rsp+40h] [rbp-48h]
  UFG::qPropertyList *v24; // [rsp+A8h] [rbp+20h] BYREF

  v20 = -2i64;
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
                                      &v19,
                                      pProps,
                                      (UFG::qArray<unsigned long,0> *)&qSymbol_InterestPointParentBone,
                                      (unsigned int *)&v24,
                                      DEPTH_RECURSE)->mUID;
  v6->mClassListIsAllowed = 0;
  p_mUseClassList = &v6->mUseClassList;
  p = v6->mUseClassList.p;
  if ( p )
  {
    v9 = p - 1;
    `eh vector destructor iterator(p, 4ui64, p[-1].mUID, (void (__fastcall *)(void *))_);
    operator delete[](v9);
  }
  v10 = 0;
  v6->mUseClassList.p = 0i64;
  *(_QWORD *)&p_mUseClassList->size = 0i64;
  if ( class_list_data )
  {
    v6->mClassListIsAllowed = class_list_data->ClassTypeIsAllowable;
    mOffset = class_list_data->ClassTypeList.mOffset;
    if ( mOffset )
    {
      v24 = (UFG::qPropertyList *)((char *)&class_list_data->ClassTypeList + mOffset);
      if ( v24 )
      {
        v12 = *(_DWORD *)(&class_list_data[3].ClassTypeIsAllowable + mOffset);
        if ( v12 > v6->mUseClassList.capacity )
          UFG::qArray<UFG::qSymbol,0>::Reallocate(&v6->mUseClassList, v12, "mUseClassList Reserve");
        if ( v12 )
        {
          v13 = v24;
          do
          {
            v14 = UFG::qPropertyList::Get<UFG::qSymbol>(v13, v10);
            size = p_mUseClassList->size;
            v16 = size + 1;
            capacity = v6->mUseClassList.capacity;
            if ( (int)size + 1 > capacity )
            {
              if ( capacity )
                v18 = 2 * capacity;
              else
                v18 = 1;
              for ( ; v18 < v16; v18 *= 2 )
                ;
              if ( v18 <= 4 )
                v18 = 4;
              if ( v18 - v16 > 0x10000 )
                v18 = size + 65537;
              UFG::qArray<UFG::qSymbol,0>::Reallocate(p_mUseClassList, v18, "mUseClassList");
            }
            p_mUseClassList->size = v16;
            v6->mUseClassList.p[size] = (UFG::qSymbol)v14->mUID;
            ++v10;
          }
          while ( v10 < v12 );
          v6 = this;
          v5 = interest_point_data;
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
void __fastcall UFG::InterestPointProperties::LoadUseProperties(
        UFG::InterestPointProperties *this,
        UFG::qPropertySet *pProps,
        component_InterestPoint *interest_point_data,
        schema_classlist *class_list_data)
{
  bool UserCanBeRecycled; // al
  unsigned int mUID; // edx
  UFG::InterestPoint::eInterestPointPriority mPriority; // eax

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
  UserCanBeRecycled = interest_point_data->UserCanBeRecycled;
  this->mPriority = InterestPointPriority_None;
  this->mUserCanBeRecycled = UserCanBeRecycled;
  mUID = interest_point_data->InterestPointPriority.mUID;
  if ( mUID == qSymbol_Critical.mUID )
  {
    this->mPriority = InterestPointPriority_Critical;
  }
  else if ( mUID == qSymbol_High.mUID )
  {
    this->mPriority = InterestPointPriority_High;
  }
  else if ( mUID == qSymbol_Medium.mUID )
  {
    this->mPriority = InterestPointPriority_Medium;
  }
  else
  {
    mPriority = this->mPriority;
    if ( mUID == qSymbol_Low.mUID )
      mPriority = InterestPointPriority_Low;
    this->mPriority = mPriority;
  }
}

// File Line: 417
// RVA: 0x15522C0
__int64 UFG::_dynamic_initializer_for__gInterestPointCachedProperties__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::gInterestPointCachedProperties.mTree);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gInterestPointCachedProperties__);
}

// File Line: 427
// RVA: 0x57DB20
void __fastcall UFG::InterestPointPropertiesHandle::~InterestPointPropertiesHandle(
        UFG::InterestPointPropertiesHandle *this)
{
  UFG::InterestPointPropertiesHandle::Set(this, 0i64, 1);
}

// File Line: 432
// RVA: 0x58B5D0
void __fastcall UFG::InterestPointPropertiesHandle::Set(
        UFG::InterestPointPropertiesHandle *this,
        UFG::InterestPointProperties *pProperties,
        bool isOwner)
{
  UFG::InterestPointProperties *mProperties; // rsi
  UFG::qSymbol *p; // rcx
  UFG::qSymbol *v8; // rbx

  mProperties = this->mProperties;
  if ( this->mProperties && this->mIsOwner )
  {
    p = mProperties->mUseClassList.p;
    if ( p )
    {
      v8 = p - 1;
      `eh vector destructor iterator(p, 4ui64, p[-1].mUID, (void (__fastcall *)(void *))_);
      operator delete[](v8);
    }
    mProperties->mUseClassList.p = 0i64;
    *(_QWORD *)&mProperties->mUseClassList.size = 0i64;
    operator delete[](mProperties);
    this->mProperties = pProperties;
    this->mIsOwner = isOwner;
  }
  else
  {
    this->mIsOwner = isOwner;
    this->mProperties = pProperties;
  }
}

// File Line: 444
// RVA: 0x585740
void __fastcall UFG::InterestPointPropertiesHandle::Load(
        UFG::InterestPointPropertiesHandle *this,
        UFG::InterestPointProperties *pCachedProperties,
        UFG::qPropertySet *pProps)
{
  UFG::qPropertySet *v5; // rax
  char *MemImagePtr; // rdi
  component_InterestPoint *v7; // r8
  UFG::qPropertySet *v8; // rax
  UFG::InterestPointProperties *v9; // rdi
  char *v10; // rbp
  UFG::allocator::free_link *v11; // rax
  UFG::InterestPointProperties *v12; // rax

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
             (UFG::qArray<unsigned long,0> *)&component_InterestPoint::sPropertyName,
             DEPTH_RECURSE);
      if ( v5 )
        MemImagePtr = UFG::qPropertySet::GetMemImagePtr(v5);
      else
        MemImagePtr = 0i64;
      v7 = (component_InterestPoint *)MemImagePtr;
    }
    else
    {
      v8 = UFG::qPropertySet::Get<UFG::qPropertySet>(
             pProps,
             (UFG::qArray<unsigned long,0> *)&component_InterestPoint::sPropertyName,
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
      UFG::InterestPointPropertiesHandle::Set(this, v9, 1);
      v7 = (component_InterestPoint *)v10;
    }
    UFG::InterestPointProperties::Load(this->mProperties, pProps, v7);
  }
}

// File Line: 503
// RVA: 0x57EF80
void __fastcall UFG::InterestPointProperties::AddToCache(
        UFG::qPropertySet *pPropertySet,
        UFG::qSymbol *interestPointTypeSymbol)
{
  unsigned int mUID; // edi
  UFG::allocator::free_link *v4; // rax
  char *MemImagePtr; // rsi
  UFG::InterestPointProperties *v6; // rax
  UFG::InterestPointProperties *v7; // rbx
  UFG::qPropertySet *v8; // rax

  mUID = interestPointTypeSymbol->mUID;
  if ( !interestPointTypeSymbol->mUID || !UFG::qBaseTreeRB::Get(&UFG::gInterestPointCachedProperties.mTree, mUID) )
  {
    v4 = UFG::qMalloc(0xA0ui64, "InterestPointProperties", 0i64);
    MemImagePtr = 0i64;
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
             pPropertySet,
             (UFG::qArray<unsigned long,0> *)&component_InterestPoint::sPropertyName,
             DEPTH_RECURSE);
      if ( v8 )
        MemImagePtr = UFG::qPropertySet::GetMemImagePtr(v8);
      v7->mNode.mUID = mUID;
      UFG::InterestPointProperties::Load(v7, pPropertySet, (component_InterestPoint *)MemImagePtr);
      UFG::qBaseTreeRB::Add(&UFG::gInterestPointCachedProperties.mTree, &v7->mNode);
    }
  }
}

// File Line: 542
// RVA: 0x57CD20
void __fastcall UFG::InterestPointType::InterestPointType(UFG::InterestPointType *this)
{
  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  `eh vector constructor iterator(
    this->mAnimBankSymbols,
    0x10ui64,
    3,
    (void (__fastcall *)(void *))UFG::qArray<UFG::qSymbolUC,0>::qArray<UFG::qSymbolUC,0>);
  this->mUseItemList.p = 0i64;
  *(_QWORD *)&this->mUseItemList.size = 0i64;
  *(_WORD *)&this->mItemListMatchesNoItem = 0;
  this->mHasBehaviourFile = 0;
  UFG::qSharedString::qSharedString(&this->mBehaviourFileName);
  this->mBehaviour = 0i64;
  this->mBehaviourInteractions = 0i64;
  this->mBehaviourConditions = 0i64;
  *(_WORD *)&this->mHasBeginningScript = 0;
  this->mHasOnReservationScript = 0;
  *(_QWORD *)&this->mBeginningScriptHash = 0i64;
  this->mOnReservationScriptHash = 0;
  this->mDescription.mUID = -1;
  this->mInterestPointTypePropertySet = 0i64;
}

// File Line: 554
// RVA: 0x582F30
void __fastcall UFG::InterestPointType::InitActionTree(UFG::InterestPointType *this)
{
  ActionNode *v2; // rax
  ActionNode *v3; // rax

  v2 = (ActionNode *)ActionNode::Load(this->mBehaviourFileName.mText);
  this->mBehaviour = v2;
  if ( v2 )
  {
    if ( (_S7_14 & 1) == 0 )
    {
      _S7_14 |= 1u;
      dword_14242E450 = UFG::qStringHashUpper32("UseConditions", -1);
    }
    this->mBehaviourConditions = (ActionNode *)((__int64 (__fastcall *)(ActionNode *, int *, _QWORD))this->mBehaviour->vfptr[1].CreateClone)(
                                                 this->mBehaviour,
                                                 &dword_14242E450,
                                                 0i64);
    if ( (_S9_16 & 1) == 0 )
    {
      _S9_16 |= 1u;
      node_id.mUID = UFG::qStringHashUpper32("Interactions", -1);
    }
    v3 = (ActionNode *)((__int64 (__fastcall *)(ActionNode *, ActionID *, _QWORD))this->mBehaviour->vfptr[1].CreateClone)(
                         this->mBehaviour,
                         &node_id,
                         0i64);
    this->mBehaviourInteractions = v3;
    if ( !v3 )
      UFG::qPrintf("Invalid POI Behaviour, no node: %s!\n", this->mBehaviourFileName.mText);
  }
  else
  {
    UFG::qPrintf("Invalid POI Behaviour: %s!\n", this->mBehaviourFileName.mText);
    this->mBehaviourConditions = 0i64;
    this->mBehaviourInteractions = 0i64;
  }
}

// File Line: 586
// RVA: 0x58AAC0
void __fastcall UFG::InterestPointType::ReadAnimBankSymbols(
        UFG::InterestPointType *this,
        UFG::qPropertySet *pInterestPointTypePropertySet)
{
  UFG::qPropertySet *v2; // rdi
  UFG::qArray<UFG::qSymbolUC,0> *mAnimBankSymbols; // rsi
  UFG::qSymbol *p_name; // r12
  __int64 v6; // rbx
  UFG::qPropertyList *v7; // rax
  UFG::qPropertyList *v8; // r13
  unsigned int mNumElements; // r14d
  unsigned int v10; // ebp
  unsigned int v11; // ebx
  __int64 size; // r15
  unsigned int v13; // edi
  unsigned int capacity; // edx
  unsigned int v15; // edx
  UFG::qSymbol name; // [rsp+38h] [rbp-50h] BYREF
  unsigned int mUID; // [rsp+3Ch] [rbp-4Ch]
  unsigned int v18; // [rsp+40h] [rbp-48h]
  UFG::qSymbol *v20; // [rsp+A0h] [rbp+18h]
  __int64 v21; // [rsp+A8h] [rbp+20h]

  v2 = pInterestPointTypePropertySet;
  `eh vector constructor iterator(&name, 4ui64, 3, (void (__fastcall *)(void *))BackInfo::BackInfo);
  name.mUID = qSymbol_AnimBankFileNames.mUID;
  mUID = qSymbol_AnimBankFileNamesMale.mUID;
  v18 = qSymbol_AnimBankFileNamesFemale.mUID;
  mAnimBankSymbols = this->mAnimBankSymbols;
  p_name = &name;
  v20 = &name;
  v6 = 3i64;
  v21 = 3i64;
  do
  {
    v7 = UFG::qPropertySet::Get<UFG::qPropertyList>(v2, (UFG::qArray<unsigned long,0> *)p_name, DEPTH_RECURSE);
    v8 = v7;
    if ( v7 )
    {
      mNumElements = v7->mNumElements;
      if ( mNumElements > mAnimBankSymbols->capacity )
        UFG::qArray<UFG::qSymbolUC,0>::Reallocate(mAnimBankSymbols, mNumElements, "qArray.Reallocate(Reserve)");
      v10 = 0;
      if ( mNumElements )
      {
        do
        {
          v11 = UFG::qPropertyList::Get<UFG::qSymbolUC>(v8, v10)->mUID;
          size = mAnimBankSymbols->size;
          v13 = size + 1;
          capacity = mAnimBankSymbols->capacity;
          if ( (int)size + 1 > capacity )
          {
            if ( capacity )
              v15 = 2 * capacity;
            else
              v15 = 1;
            for ( ; v15 < v13; v15 *= 2 )
              ;
            if ( v15 <= 4 )
              v15 = 4;
            if ( v15 - v13 > 0x10000 )
              v15 = size + 65537;
            UFG::qArray<UFG::qSymbolUC,0>::Reallocate(mAnimBankSymbols, v15, "qArray.Add");
          }
          mAnimBankSymbols->size = v13;
          mAnimBankSymbols->p[size].mUID = v11;
          ++v10;
        }
        while ( v10 < mNumElements );
        p_name = v20;
        v6 = v21;
        v2 = pInterestPointTypePropertySet;
      }
    }
    v20 = ++p_name;
    ++mAnimBankSymbols;
    v21 = --v6;
  }
  while ( v6 );
  `eh vector destructor iterator(&name, 4ui64, 3, (void (__fastcall *)(void *))_);
}

// File Line: 610
// RVA: 0x583290
void __fastcall UFG::InterestPointType::InitFromPropertySet(
        UFG::InterestPointType *this,
        UFG::qPropertySet *pInterestPointTypePropertySet)
{
  UFG::qPropertySet *v2; // r15
  UFG::qSymbol *v4; // rax
  UFG::qSymbol *v5; // rdx
  UFG::qPropertySet *v6; // rax
  char *MemImagePtr; // rax
  char *v8; // rdi
  char v9; // cl
  bool v10; // si
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
  bool *v22; // rcx
  bool v23; // al
  char *v24; // rax
  UFG::eInventoryItemEnum *p; // rcx
  __int64 v26; // rax
  __int64 v27; // rax
  bool v28; // zf
  UFG::qPropertyList *v29; // rax
  unsigned int mNumElements; // edi
  unsigned int v31; // r12d
  UFG::qSymbol *v32; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mPrev; // rax
  unsigned int m_EnumValue; // r15d
  __int64 size; // r13
  unsigned int v36; // edi
  unsigned int capacity; // edx
  unsigned int v38; // edx
  char *v39; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v40; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mNext; // rax
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+28h] [rbp-28h] BYREF
  unsigned int v44; // [rsp+A0h] [rbp+50h] BYREF
  UFG::qPropertyList *v45; // [rsp+A8h] [rbp+58h]

  if ( !pInterestPointTypePropertySet )
    return;
  v2 = pInterestPointTypePropertySet;
  this->mInterestPointTypePropertySet = pInterestPointTypePropertySet;
  v4 = UFG::qPropertySet::Get<UFG::qSymbol>(
         pInterestPointTypePropertySet,
         (UFG::qArray<unsigned long,0> *)&qSymbol_Description_17,
         DEPTH_RECURSE);
  v5 = &UFG::gNullQSymbol;
  if ( v4 )
    v5 = v4;
  this->mDescription = (UFG::qSymbol)v5->mUID;
  v6 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         v2,
         (UFG::qArray<unsigned long,0> *)&schema_interestpoint_script::sPropertyName,
         DEPTH_RECURSE);
  if ( v6 && (MemImagePtr = UFG::qPropertySet::GetMemImagePtr(v6), (v8 = MemImagePtr) != 0i64) )
  {
    v9 = *MemImagePtr;
    this->mHasBeginningScript = *MemImagePtr;
    v10 = 0;
    if ( v9 )
    {
      v11 = *((_QWORD *)MemImagePtr + 1);
      if ( v11 )
        v12 = &v8[v11 + 8];
      else
        v12 = 0i64;
      this->mBeginningScriptHash = UFG::qStringHash32(v12, 0xFFFFFFFF);
    }
    else
    {
      this->mBeginningScriptHash = 0;
    }
    v13 = v8[1];
    this->mHasEndingScript = v13;
    if ( v13 )
    {
      v14 = *((_QWORD *)v8 + 2);
      if ( v14 )
        v15 = &v8[v14 + 16];
      else
        v15 = 0i64;
      this->mEndingScriptHash = UFG::qStringHash32(v15, 0xFFFFFFFF);
    }
    else
    {
      this->mEndingScriptHash = 0;
    }
    v16 = v8[40];
    this->mHasOnReservationScript = v16;
    if ( v16 )
    {
      v17 = *((_QWORD *)v8 + 6);
      if ( v17 )
        v18 = &v8[v17 + 48];
      else
        v18 = 0i64;
      this->mOnReservationScriptHash = UFG::qStringHash32(v18, 0xFFFFFFFF);
      goto LABEL_25;
    }
  }
  else
  {
    *(_WORD *)&this->mHasBeginningScript = 0;
    v10 = 0;
    *(_QWORD *)&this->mBeginningScriptHash = 0i64;
    this->mHasOnReservationScript = 0;
  }
  this->mOnReservationScriptHash = 0;
LABEL_25:
  v19 = UFG::qPropertySet::Get<UFG::qPropertySet>(
          v2,
          (UFG::qArray<unsigned long,0> *)&component_InterestPoint::sPropertyName,
          DEPTH_RECURSE);
  if ( v19 )
    v20 = UFG::qPropertySet::GetMemImagePtr(v19);
  else
    v20 = 0i64;
  LOBYTE(v44) = 0;
  v21 = UFG::qPropertySet::Get<bool>(v2, (UFG::qArray<unsigned long,0> *)&qSymbol_HasBehaviour, DEPTH_RECURSE);
  v22 = (bool *)&v44;
  if ( v21 )
    v22 = v21;
  v23 = *v22;
  this->mHasBehaviourFile = *v22;
  if ( v23 )
  {
    v24 = UFG::qPropertySet::Get<char const *>(
            v2,
            (UFG::qArray<unsigned long,0> *)&qSymbol_BehaviourFile,
            DEPTH_RECURSE);
    UFG::qSharedString::operator=(&this->mBehaviourFileName, v24);
    UFG::InterestPointType::InitActionTree(this);
  }
  else
  {
    UFG::qSharedString::Set(&this->mBehaviourFileName, &customCaption);
  }
  p = this->mUseItemList.p;
  if ( p )
    operator delete[](p);
  this->mUseItemList.p = 0i64;
  *(_QWORD *)&this->mUseItemList.size = 0i64;
  v26 = *((_QWORD *)v20 + 8);
  if ( v26 )
  {
    v27 = v26 + 64;
    v28 = &v20[v27] == 0i64;
    v29 = (UFG::qPropertyList *)&v20[v27];
    v45 = v29;
    if ( !v28 )
    {
      mNumElements = v29->mNumElements;
      v44 = mNumElements;
      if ( mNumElements )
      {
        UFG::qArray<long,0>::Reallocate(
          (UFG::qArray<unsigned long,0> *)&this->mUseItemList,
          mNumElements,
          "mUseItemList Reserve");
        v29 = v45;
      }
      v31 = 0;
      if ( mNumElements )
      {
        do
        {
          v32 = UFG::qPropertyList::Get<UFG::qSymbol>(v29, v31);
          if ( v32->mUID == qSymbol_None.mUID )
          {
            this->mItemListMatchesNoItem = 1;
          }
          else if ( v32->mUID == qSymbol_Weapon_17.mUID )
          {
            this->mItemListMatchesWeapons = 1;
          }
          else
          {
            pTrackEnumBinding.mPrev = &pTrackEnumBinding;
            pTrackEnumBinding.mNext = &pTrackEnumBinding;
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
              mPrev = UFG::gInventoryItemTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
              UFG::gInventoryItemTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = &pTrackEnumBinding;
              pTrackEnumBinding.mPrev = mPrev;
              pTrackEnumBinding.mNext = &UFG::gInventoryItemTracksEnum.m_UnresolvedTracksEnumBindingList.mNode;
              UFG::gInventoryItemTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = &pTrackEnumBinding;
            }
            m_EnumValue = pTrackEnumBinding.m_EnumValue;
            if ( pTrackEnumBinding.m_EnumValue )
            {
              size = this->mUseItemList.size;
              v36 = size + 1;
              capacity = this->mUseItemList.capacity;
              if ( (int)size + 1 > capacity )
              {
                if ( capacity )
                  v38 = 2 * capacity;
                else
                  v38 = 1;
                for ( ; v38 < v36; v38 *= 2 )
                  ;
                if ( v38 <= 4 )
                  v38 = 4;
                if ( v38 - v36 > 0x10000 )
                  v38 = size + 65537;
                UFG::qArray<long,0>::Reallocate(
                  (UFG::qArray<unsigned long,0> *)&this->mUseItemList,
                  v38,
                  "mUseItemList");
              }
              this->mUseItemList.size = v36;
              this->mUseItemList.p[size] = m_EnumValue;
              mNumElements = v44;
            }
            else
            {
              v39 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->mInterestPointTypePropertySet->mName);
              UFG::qPrintf("Interest point with invalid item list element, check the property set for %s\n", v39);
            }
            v40 = pTrackEnumBinding.mPrev;
            mNext = pTrackEnumBinding.mNext;
            pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
            mNext->mPrev = v40;
            pTrackEnumBinding.mPrev = &pTrackEnumBinding;
            pTrackEnumBinding.mNext = &pTrackEnumBinding;
          }
          ++v31;
          v29 = v45;
        }
        while ( v31 < mNumElements );
        v2 = pInterestPointTypePropertySet;
      }
    }
  }
  if ( this->mItemListMatchesNoItem || !this->mUseItemList.size )
    v10 = 1;
  this->mItemListMatchesNoItem = v10;
  this->mNode.mUID = v2->mName.mUID;
  UFG::InterestPointType::ReadAnimBankSymbols(this, v2);
}

// File Line: 761
// RVA: 0x57CA30
void __fastcall UFG::InterestPoint::InterestPoint(UFG::InterestPoint *this, UFG::qSymbol *name)
{
  unsigned int mUID; // eax
  char v5; // cl

  UFG::MarkerBase::MarkerBase(this, name, 0i64, 0x10000u);
  mUID = name->mUID;
  this->UFG::qNodeRB<UFG::InterestPoint>::mNode.mParent = 0i64;
  this->UFG::qNodeRB<UFG::InterestPoint>::mNode.mChild[0] = 0i64;
  this->UFG::qNodeRB<UFG::InterestPoint>::mNode.mChild[1] = 0i64;
  this->UFG::qNodeRB<UFG::InterestPoint>::mNode.mUID = mUID;
  this->UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList>::mPrev = &this->UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList>;
  this->UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList>::mNext = &this->UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList>;
  UFG::qSafePointerNode<UFG::InterestPoint>::qSafePointerNode<UFG::InterestPoint>(&this->UFG::qSafePointerNode<UFG::InterestPoint>);
  this->UFG::GridIntrusiveNode<UFG::InterestPoint>::UFG::qNode<UFG::InterestPoint,UFG::InterestPoint>::mPrev = &this->UFG::GridIntrusiveNode<UFG::InterestPoint>;
  this->UFG::GridIntrusiveNode<UFG::InterestPoint>::UFG::qNode<UFG::InterestPoint,UFG::InterestPoint>::mNext = &this->UFG::GridIntrusiveNode<UFG::InterestPoint>;
  this->UFG::MarkerBase::UFG::HintComponentBase::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::InterestPoint::`vftable{for `UFG::MarkerBase};
  this->UFG::qSafePointerNode<UFG::InterestPoint>::vfptr = (UFG::qSafePointerNode<UFG::InterestPoint>Vtbl *)&UFG::InterestPoint::`vftable{for `UFG::qSafePointerNode<UFG::InterestPoint>};
  `eh vector constructor iterator(
    this->mAnimGroupHandles,
    0x18ui64,
    3,
    (void (__fastcall *)(void *))AnimationGroupHandleContainer::AnimationGroupHandleContainer);
  this->mReferenceSubPriority = 0;
  *(_QWORD *)&this->mMinimumDistanceToPlayerSquared = 2139095039i64;
  this->mPoiType.mUID = -1;
  this->mIsPositionCached = 0;
  this->mBoneId = -1;
  this->mpParentCharacterAnimationComponent.mPrev = &this->mpParentCharacterAnimationComponent;
  this->mpParentCharacterAnimationComponent.mNext = &this->mpParentCharacterAnimationComponent;
  this->mpParentCharacterAnimationComponent.m_pPointer = 0i64;
  *(_WORD *)&this->mFullUpdateRequired = 256;
  this->mpUser.mPrev = &this->mpUser;
  this->mpUser.mNext = &this->mpUser;
  this->mpUser.m_pPointer = 0i64;
  this->mpInterestPointUserComponent.mPrev = &this->mpInterestPointUserComponent;
  this->mpInterestPointUserComponent.mNext = &this->mpInterestPointUserComponent;
  this->mpInterestPointUserComponent.m_pPointer = 0i64;
  this->mInterestPointType = 0i64;
  this->mUseTime = -1.0;
  *(_QWORD *)&this->mCooldownTime = 0i64;
  *(_DWORD *)&this->mIsInterrupted = 50397184;
  *(_QWORD *)&this->mTimeSinceBeginUse = 0i64;
  this->mNeedsBoneFixupWhenRigAvailable = 0;
  this->mBeginningScriptInfo.mpCachedScript = 0i64;
  *(_WORD *)&this->mBeginningScriptInfo.mHasScript = 0;
  this->mEndingScriptInfo.mpCachedScript = 0i64;
  *(_WORD *)&this->mEndingScriptInfo.mHasScript = 0;
  this->mOnReservationScriptInfo.mpCachedScript = 0i64;
  *(_WORD *)&this->mOnReservationScriptInfo.mHasScript = 0;
  this->mPropertiesHandle.mProperties = 0i64;
  this->mPropertiesHandle.mIsOwner = 1;
  this->mpPedInfoUser = 0i64;
  this->mLinkObject.mPrev = &this->mLinkObject;
  this->mLinkObject.mNext = &this->mLinkObject;
  this->mLinkObject.m_pPointer = 0i64;
  UFG::SimComponent::AddType(this, UFG::InterestPoint::_InterestPointTypeUID, "InterestPoint");
  *(_QWORD *)this->mLastPriority = -1i64;
  *(_QWORD *)&this->mLastPriority[2] = -1i64;
  this->mLastSubPriority[2] = -1;
  ++UFG::InterestPoint::msNumPOIsThisFrame;
  v5 = initedTweakables;
  if ( !initedTweakables )
    v5 = 1;
  initedTweakables = v5;
  *(_WORD *)&this->mAddedToGrid = 0;
  this->mGridIndex = -1;
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
  if ( pedInfo )
    UFG::InterestPoint::EndReservation(this);
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
  __int64 v2; // r15
  AnimationGroupHandleContainer *mAnimGroupHandles; // r14
  UFG::InterestPointType *mInterestPointType; // rax
  int v5; // r12d
  __int64 v6; // rbp
  char *v7; // r15
  int v8; // eax
  int v9; // eax
  int v10; // eax
  UFG::eAnimationPriorityEnum v11; // ebx
  UFG::qSymbolUC *v12; // rsi
  UFG::allocator::free_link *v13; // rax
  AnimationGroupHandle *v14; // rax
  AnimationGroupHandle *v15; // rdi
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *mPrev; // rax
  __int64 v17; // [rsp+78h] [rbp+10h]

  v2 = 32i64;
  v17 = 32i64;
  mAnimGroupHandles = this->mAnimGroupHandles;
  do
  {
    mInterestPointType = this->mInterestPointType;
    v5 = *(_DWORD *)((char *)&mInterestPointType->mNode.mParent + v2);
    v6 = 0i64;
    if ( v5 > 0 )
    {
      v7 = (char *)mInterestPointType + v2;
      do
      {
        v8 = UFG::InterestPoint::GetPriority(this) - 1;
        if ( v8 )
        {
          v9 = v8 - 1;
          if ( v9 )
          {
            v10 = v9 - 1;
            if ( v10 )
            {
              if ( v10 == 1 )
                v11 = eANIM_PRIORITY_POI_CRITICAL;
              else
                v11 = eANIM_PRIORITY_INACTIVE_POI;
            }
            else
            {
              v11 = eANIM_PRIORITY_ACTIVE_POI;
            }
          }
          else
          {
            v11 = eANIM_PRIORITY_PREDICTIVE_POI;
          }
        }
        else
        {
          v11 = eANIM_PRIORITY_INSTANCED_POI;
        }
        v12 = (UFG::qSymbolUC *)(*((_QWORD *)v7 + 1) + 4 * v6);
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
        mPrev = mAnimGroupHandles->m_AnimationGroupHandleList.mNode.mPrev;
        mPrev->mNext = &v15->UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer>;
        v15->UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer>::mPrev = mPrev;
        v15->UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer>::mNext = &mAnimGroupHandles->m_AnimationGroupHandleList.mNode;
        mAnimGroupHandles->m_AnimationGroupHandleList.mNode.mPrev = &v15->UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer>;
        v6 = (unsigned int)(v6 + 1);
      }
      while ( (int)v6 < v5 );
      v2 = v17;
    }
    v2 += 16i64;
    v17 = v2;
    ++mAnimGroupHandles;
  }
  while ( v2 < 80 );
}

// File Line: 923
// RVA: 0x58DC80
void __fastcall UFG::InterestPoint::UpdateAnimHandles(
        UFG::InterestPoint *this,
        AnimationGroupHandleContainer *animGroupHandles,
        const float minimumDistanceToPlayerSquared,
        const bool isReferencedByPlayer,
        bool isReferencedByPedestrian,
        UFG::eAnimationPriorityEnum *lastPriority,
        unsigned __int16 *lastSubPriority)
{
  int v9; // r8d
  int v10; // ebx
  UFG::InterestPoint::eInterestPointPriority mPriority; // ecx
  __int32 v12; // ecx
  __int32 v13; // ecx
  __int32 v14; // ecx

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
      mPriority = InterestPointPriority_None;
    else
      mPriority = this->mPropertiesHandle.mProperties->mPriority;
    v12 = mPriority - 1;
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
    if ( v10 <= 2 )
    {
      if ( animGroupHandles->m_bHasBeenBound )
        AnimationGroupHandleContainer::Unbind(animGroupHandles);
      *lastPriority = -1;
      *lastSubPriority = -1;
    }
    else if ( v10 != *lastPriority || this->mReferenceSubPriority != *lastSubPriority )
    {
      AnimationGroupHandleContainer::SetAnimationPriority(
        animGroupHandles,
        (UFG::eAnimationPriorityEnum)v10,
        this->mReferenceSubPriority);
      if ( !animGroupHandles->m_bHasBeenBound )
        AnimationGroupHandleContainer::Bind(animGroupHandles);
      *lastPriority = v10;
      *lastSubPriority = this->mReferenceSubPriority;
    }
  }
}

// File Line: 991
// RVA: 0x58DDD0
void __fastcall UFG::InterestPoint::UpdateAnimHandles(UFG::InterestPoint *this)
{
  bool isReferencedByPedestrian; // r8

  isReferencedByPedestrian = this->mReferencedByMalePedestrian || this->mReferencedByFemalePedestrian;
  UFG::InterestPoint::UpdateAnimHandles(
    this,
    this->mAnimGroupHandles,
    this->mMinimumDistanceToPlayerSquared,
    this->mReferencedByPlayer != 0,
    isReferencedByPedestrian,
    this->mLastPriority,
    this->mLastSubPriority);
  UFG::InterestPoint::UpdateAnimHandles(
    this,
    &this->mAnimGroupHandles[1],
    this->mMinimumDistanceToPlayerSquared,
    this->mReferencedByPlayer != 0,
    this->mReferencedByMalePedestrian != 0,
    &this->mLastPriority[1],
    &this->mLastSubPriority[1]);
  UFG::InterestPoint::UpdateAnimHandles(
    this,
    &this->mAnimGroupHandles[2],
    this->mMinimumDistanceToPlayerSquared,
    0,
    this->mReferencedByFemalePedestrian != 0,
    &this->mLastPriority[2],
    &this->mLastSubPriority[2]);
}

// File Line: 1001
// RVA: 0x584110
char __fastcall UFG::InterestPoint::IsAvailable(
        UFG::InterestPoint *this,
        UFG::SimObjectCVBase *simObject,
        const bool ensureReferenced)
{
  bool IsFemale; // al
  UFG::GridIntrusiveNode<UFG::InterestPoint> *v5; // rsi
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *v6; // rbx
  AnimationGroup *v7; // rcx
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *v8; // rax
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> **v9; // rdi
  __int64 v10; // rbx
  AnimationGroup *v11; // rcx
  AnimationGroup *mNext; // rcx
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *v14; // rax
  UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> **p_mNext; // rdi
  __int64 v16; // rbx
  AnimationGroup *v17; // rcx

  IsFemale = UFG::IsFemale(simObject);
  v5 = &this->UFG::GridIntrusiveNode<UFG::InterestPoint>;
  v6 = this->mAnimGroupHandles[0].m_AnimationGroupHandleList.mNode.mNext - 1;
  if ( !IsFemale )
  {
    for ( ; v6 != (UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *)v5; v6 = v6[1].mNext - 1 )
    {
      mNext = (AnimationGroup *)v6[3].mNext;
      if ( !mNext || !AnimationGroup::IsStreamedIn(mNext) )
        return 0;
    }
    v14 = this->mAnimGroupHandles[1].m_AnimationGroupHandleList.mNode.mNext;
    p_mNext = &this->mAnimGroupHandles[0].m_AnimationGroupHandleList.mNode.mNext;
    v16 = (__int64)&v14[-1];
    if ( &v14[-1] != (UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *)p_mNext )
    {
      while ( 1 )
      {
        v17 = *(AnimationGroup **)(v16 + 56);
        if ( !v17 || !AnimationGroup::IsStreamedIn(v17) )
          break;
        v16 = *(_QWORD *)(v16 + 24) - 16i64;
        if ( (UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> **)v16 == p_mNext )
          return 1;
      }
      return 0;
    }
    return 1;
  }
  for ( ; v6 != (UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *)v5; v6 = v6[1].mNext - 1 )
  {
    v7 = (AnimationGroup *)v6[3].mNext;
    if ( !v7 || !AnimationGroup::IsStreamedIn(v7) )
      return 0;
  }
  v8 = this->mAnimGroupHandles[2].m_AnimationGroupHandleList.mNode.mNext;
  v9 = &this->mAnimGroupHandles[1].m_AnimationGroupHandleList.mNode.mNext;
  v10 = (__int64)&v8[-1];
  if ( &v8[-1] == (UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> *)v9 )
    return 1;
  while ( 1 )
  {
    v11 = *(AnimationGroup **)(v10 + 56);
    if ( !v11 || !AnimationGroup::IsStreamedIn(v11) )
      break;
    v10 = *(_QWORD *)(v10 + 24) - 16i64;
    if ( (UFG::qNode<AnimationGroupHandle,AnimationGroupHandleContainer> **)v10 == v9 )
      return 1;
  }
  return 0;
}

// File Line: 1033
// RVA: 0x57EEA0
UFG::InterestPointType *__fastcall UFG::InterestPoint::AddInterestPointType(UFG::qPropertySet *pInterestPointTypeProps)
{
  UFG::InterestPointType *v1; // rbx
  char *v3; // rax

  if ( UFG::InterestPoint::msInterestPointTypePool.size >= 0x1F4 )
  {
    v3 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&pInterestPointTypeProps->mName);
    UFG::qPrintf("WARNING: InterestPoint::AddInterestPointType: Pool is Full (%d) Not Adding (%s)\n", 500i64, v3);
    return 0i64;
  }
  else
  {
    v1 = &UFG::InterestPoint::msInterestPointTypePool.p[UFG::InterestPoint::msInterestPointTypePool.size++];
    UFG::InterestPointType::InitFromPropertySet(v1, pInterestPointTypeProps);
    UFG::qBaseTreeRB::Add(&UFG::InterestPoint::msInterestPointTypeTree.mTree, &v1->mNode);
    return v1;
  }
}

// File Line: 1060
// RVA: 0x58C790
void UFG::InterestPoint::StaticInit(void)
{
  UFG::qPropertySet *PropertySet; // rbx
  UFG::qPropertyList *v1; // rax
  UFG::qPropertyList *v2; // r14
  unsigned int mNumElements; // ebp
  unsigned int i; // ebx
  UFG::qSymbol *v5; // rax
  UFG::qSymbol *v6; // rdi
  UFG::qPropertySet *v7; // rax
  UFG::qPropertySet *v8; // rsi
  char *v9; // rax
  char *v10; // rax
  char *v11; // rax
  char *v12; // rax
  UFG::qArray<unsigned long,0> name; // [rsp+40h] [rbp+8h] BYREF

  UFG::qSymbol::create_from_string((UFG::qSymbol *)&name.p, "config-InterestPointTypes");
  PropertySet = UFG::PropertySetManager::GetPropertySet((UFG::qSymbol *)&name.p);
  if ( PropertySet )
  {
    UFG::qSymbol::create_from_string((UFG::qSymbol *)&name, "types");
    v1 = UFG::qPropertySet::Get<UFG::qPropertyList>(PropertySet, &name, DEPTH_RECURSE);
    v2 = v1;
    if ( v1 )
    {
      mNumElements = v1->mNumElements;
      for ( i = 0; i < mNumElements; ++i )
      {
        v5 = UFG::qPropertyList::Get<UFG::qSymbol>(v2, i);
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
    v12 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&name.p);
    UFG::qPrintf("WARNING: InterestPoint::StaticInit: Manifest File Not Found: %s\n", v12);
  }
}

// File Line: 1120
// RVA: 0x57D920
void __fastcall UFG::InterestPoint::~InterestPoint(UFG::InterestPoint *this)
{
  UFG::qSafePointerNode<UFG::ParkourHandle> *v2; // rbx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mLinkObject; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::InterestPointUserComponent> *p_mpInterestPointUserComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mpUser; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v15; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::CharacterAnimationComponent> *p_mpParentCharacterAnimationComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v21; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v22; // rax
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint> *v23; // rcx
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint> *v24; // rax
  UFG::qList<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList,1,0> *p_m_SafePointerList; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v26; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v27; // rax
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList> *v28; // rcx
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList> *v29; // rax

  this->UFG::MarkerBase::UFG::HintComponentBase::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::InterestPoint::`vftable{for `UFG::MarkerBase};
  v2 = (UFG::qSafePointerNode<UFG::ParkourHandle> *)&this->UFG::qSafePointerNode<UFG::InterestPoint>;
  this->UFG::qSafePointerNode<UFG::InterestPoint>::vfptr = (UFG::qSafePointerNode<UFG::InterestPoint>Vtbl *)&UFG::InterestPoint::`vftable{for `UFG::qSafePointerNode<UFG::InterestPoint>};
  p_mLinkObject = &this->mLinkObject;
  if ( this->mLinkObject.m_pPointer )
  {
    mPrev = p_mLinkObject->mPrev;
    mNext = p_mLinkObject->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mLinkObject->mPrev = p_mLinkObject;
    p_mLinkObject->mNext = p_mLinkObject;
  }
  p_mLinkObject->m_pPointer = 0i64;
  v6 = p_mLinkObject->mPrev;
  v7 = p_mLinkObject->mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  p_mLinkObject->mPrev = p_mLinkObject;
  p_mLinkObject->mNext = p_mLinkObject;
  UFG::InterestPointPropertiesHandle::Set(&this->mPropertiesHandle, 0i64, 1);
  p_mpInterestPointUserComponent = &this->mpInterestPointUserComponent;
  if ( this->mpInterestPointUserComponent.m_pPointer )
  {
    v9 = p_mpInterestPointUserComponent->mPrev;
    v10 = this->mpInterestPointUserComponent.mNext;
    v9->mNext = v10;
    v10->mPrev = v9;
    p_mpInterestPointUserComponent->mPrev = p_mpInterestPointUserComponent;
    this->mpInterestPointUserComponent.mNext = &this->mpInterestPointUserComponent;
  }
  this->mpInterestPointUserComponent.m_pPointer = 0i64;
  v11 = p_mpInterestPointUserComponent->mPrev;
  v12 = this->mpInterestPointUserComponent.mNext;
  v11->mNext = v12;
  v12->mPrev = v11;
  p_mpInterestPointUserComponent->mPrev = p_mpInterestPointUserComponent;
  this->mpInterestPointUserComponent.mNext = &this->mpInterestPointUserComponent;
  p_mpUser = &this->mpUser;
  if ( this->mpUser.m_pPointer )
  {
    v14 = p_mpUser->mPrev;
    v15 = this->mpUser.mNext;
    v14->mNext = v15;
    v15->mPrev = v14;
    p_mpUser->mPrev = p_mpUser;
    this->mpUser.mNext = &this->mpUser;
  }
  this->mpUser.m_pPointer = 0i64;
  v16 = p_mpUser->mPrev;
  v17 = this->mpUser.mNext;
  v16->mNext = v17;
  v17->mPrev = v16;
  p_mpUser->mPrev = p_mpUser;
  this->mpUser.mNext = &this->mpUser;
  p_mpParentCharacterAnimationComponent = &this->mpParentCharacterAnimationComponent;
  if ( this->mpParentCharacterAnimationComponent.m_pPointer )
  {
    v19 = p_mpParentCharacterAnimationComponent->mPrev;
    v20 = this->mpParentCharacterAnimationComponent.mNext;
    v19->mNext = v20;
    v20->mPrev = v19;
    p_mpParentCharacterAnimationComponent->mPrev = p_mpParentCharacterAnimationComponent;
    this->mpParentCharacterAnimationComponent.mNext = &this->mpParentCharacterAnimationComponent;
  }
  this->mpParentCharacterAnimationComponent.m_pPointer = 0i64;
  v21 = p_mpParentCharacterAnimationComponent->mPrev;
  v22 = this->mpParentCharacterAnimationComponent.mNext;
  v21->mNext = v22;
  v22->mPrev = v21;
  p_mpParentCharacterAnimationComponent->mPrev = p_mpParentCharacterAnimationComponent;
  this->mpParentCharacterAnimationComponent.mNext = &this->mpParentCharacterAnimationComponent;
  `eh vector destructor iterator(
    this->mAnimGroupHandles,
    0x18ui64,
    3,
    (void (__fastcall *)(void *))AnimationGroupHandleContainer::~AnimationGroupHandleContainer);
  v23 = this->UFG::GridIntrusiveNode<UFG::InterestPoint>::UFG::qNode<UFG::InterestPoint,UFG::InterestPoint>::mPrev;
  v24 = this->UFG::GridIntrusiveNode<UFG::InterestPoint>::UFG::qNode<UFG::InterestPoint,UFG::InterestPoint>::mNext;
  v23->mNext = v24;
  v24->mPrev = v23;
  this->UFG::GridIntrusiveNode<UFG::InterestPoint>::UFG::qNode<UFG::InterestPoint,UFG::InterestPoint>::mPrev = &this->UFG::GridIntrusiveNode<UFG::InterestPoint>;
  this->UFG::GridIntrusiveNode<UFG::InterestPoint>::UFG::qNode<UFG::InterestPoint,UFG::InterestPoint>::mNext = &this->UFG::GridIntrusiveNode<UFG::InterestPoint>;
  v2->vfptr = (UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *)&UFG::qSafePointerNode<UFG::InterestPoint>::`vftable;
  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull(v2);
  p_m_SafePointerList = &v2->m_SafePointerList;
  UFG::qList<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList,1,0>::DeleteNodes(p_m_SafePointerList);
  v26 = p_m_SafePointerList->mNode.mPrev;
  v27 = p_m_SafePointerList->mNode.mNext;
  v26->mNext = v27;
  v27->mPrev = v26;
  p_m_SafePointerList->mNode.mPrev = &p_m_SafePointerList->mNode;
  p_m_SafePointerList->mNode.mNext = &p_m_SafePointerList->mNode;
  v28 = this->UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList>::mPrev;
  v29 = this->UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList>::mNext;
  v28->mNext = v29;
  v29->mPrev = v28;
  this->UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList>::mPrev = &this->UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList>;
  this->UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList>::mNext = &this->UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList>;
  UFG::MarkerBase::~MarkerBase(this);
}

// File Line: 1126
// RVA: 0x5836B0
void UFG::InterestPoint::InitGrid(void)
{
  UFG::GridIntrusive<UFG::InterestPoint> *v0; // rbx
  float y_max; // xmm8_4
  float x; // xmm7_4
  float y; // xmm6_4
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
    x = UFG::GetWorldExtents_max()->x;
    y = UFG::GetWorldExtents_min()->y;
    v4 = UFG::GetWorldExtents_min()->x;
    v0->mGridNodes = 0i64;
    UFG::GridIntrusive<UFG::InterestPoint>::Init(v0, v4, y, x, y_max, 50.0);
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
  UFG::GridIntrusive<UFG::InterestPoint> *v2; // r8
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint> *mPrev; // rcx
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint> *mNext; // rax
  UFG::InterestPointProperties *mProperties; // rax
  UFG::SimObject *m_pSimObject; // rax
  UFG::SceneObjectProperties *m_pSceneObj; // rdi
  UFG::PedSpawnManager *Instance; // rax
  UFG::qTreeRB<UFG::InterestPoint,UFG::InterestPoint,1> *v9; // rcx
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList> *v10; // rcx
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList> *v11; // rax

  if ( this->mAddedToGrid )
  {
    UFG::InterestPoint::GetPosition(this);
    v2 = UFG::InterestPoint::mspUseInterestPointGrid;
    if ( this->mPoiType.mUID == qSymbol_look.mUID )
      v2 = UFG::InterestPoint::mspLookInterestPointGrid;
    if ( v2 )
    {
      mPrev = this->UFG::GridIntrusiveNode<UFG::InterestPoint>::UFG::qNode<UFG::InterestPoint,UFG::InterestPoint>::mPrev;
      mNext = this->UFG::GridIntrusiveNode<UFG::InterestPoint>::UFG::qNode<UFG::InterestPoint,UFG::InterestPoint>::mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      this->UFG::GridIntrusiveNode<UFG::InterestPoint>::UFG::qNode<UFG::InterestPoint,UFG::InterestPoint>::mPrev = &this->UFG::GridIntrusiveNode<UFG::InterestPoint>;
      this->UFG::GridIntrusiveNode<UFG::InterestPoint>::UFG::qNode<UFG::InterestPoint,UFG::InterestPoint>::mNext = &this->UFG::GridIntrusiveNode<UFG::InterestPoint>;
      --v2->mNodeCount;
      *(_WORD *)&this->mAddedToGrid = 256;
    }
  }
  mProperties = this->mPropertiesHandle.mProperties;
  if ( mProperties && mProperties->mSpawnAmbientUserDistance > 0.0 )
  {
    m_pSimObject = this->m_pSimObject;
    if ( m_pSimObject )
      m_pSceneObj = m_pSimObject->m_pSceneObj;
    else
      m_pSceneObj = 0i64;
    Instance = UFG::PedSpawnManager::GetInstance();
    UFG::PedSpawnManager::UnRegisterSpawningPOI(Instance, this, m_pSceneObj);
  }
  if ( this->mIsReserved )
    UFG::InterestPoint::EndReservation(this);
  v9 = &UFG::InterestPoint::msLookInterestPoints;
  if ( this->mPoiType.mUID != qSymbol_look.mUID )
    v9 = &UFG::InterestPoint::msUseInterestPoints;
  UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
    (UFG::qBaseTreeVariableRB<unsigned __int64> *)v9,
    (UFG::qBaseNodeVariableRB<unsigned __int64> *)&this->UFG::qNodeRB<UFG::InterestPoint>);
  this->mFullUpdateRequired = 0;
  v10 = this->UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList>::mPrev;
  v11 = this->UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList>::mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  this->UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList>::mPrev = &this->UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList>;
  this->UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList>::mNext = &this->UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList>;
  this->mOnDetachCalled = 1;
  UFG::InterestPoint::UpdateAnimHandles(this);
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
  int v4; // r10d
  UFG::GridIntrusiveNode<UFG::InterestPoint> *v5; // rdx
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint> *mPrev; // rcx
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint> *mNext; // rax
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint> *p_mNode; // rcx
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint> *v9; // rax

  this->mIsPositionCached = 0;
  v2 = UFG::InterestPoint::mspUseInterestPointGrid;
  if ( this->mPoiType.mUID == qSymbol_look.mUID )
    v2 = UFG::InterestPoint::mspLookInterestPointGrid;
  if ( v2 && this->mAddedToGrid && !this->mRemovedFromGrid )
  {
    v4 = (int)(float)((float)(*(float *)&this_event[2].mNext - v2->mXMin) * v2->mGridSizeInv)
       + v2->mXDim * (int)(float)((float)(*((float *)&this_event[2].mNext + 1) - v2->mYMin) * v2->mGridSizeInv);
    if ( v4 != this->mGridIndex )
    {
      v5 = &this->UFG::GridIntrusiveNode<UFG::InterestPoint>;
      mPrev = this->UFG::GridIntrusiveNode<UFG::InterestPoint>::UFG::qNode<UFG::InterestPoint,UFG::InterestPoint>::mPrev;
      mNext = v5->mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      v5->mPrev = v5;
      v5->mNext = v5;
      --v2->mNodeCount;
      p_mNode = &v2->mGridNodes[v4].mNode;
      v9 = p_mNode->mPrev;
      v9->mNext = v5;
      v5->mPrev = v9;
      v5->mNext = p_mNode;
      p_mNode->mPrev = v5;
      ++v2->mNodeCount;
      this->mGridIndex = v4;
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
  if ( this->mOnDetachCalled )
    return 0i64;
  else
    return (unsigned int)this->mPropertiesHandle.mProperties->mPriority;
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
  UFG::InterestPointProperties *mProperties; // r9
  bool mResumeIfInterrupted; // r8
  bool result; // al

  mProperties = this->mPropertiesHandle.mProperties;
  mResumeIfInterrupted = mProperties->mResumeIfInterrupted;
  result = mResumeIfInterrupted && this->mIsReserved && (this->mIsInterrupted || !this->mIsCompleted);
  *allowNoInterruptResume = !mProperties->mInitialUseOnly || mResumeIfInterrupted;
  return result;
}

// File Line: 1341
// RVA: 0x5853F0
bool __fastcall UFG::InterestPoint::IsReservationMatch(
        UFG::InterestPoint *this,
        char matchReservationFlags,
        UFG::InterestPoint::eReserveReason reserveReason)
{
  bool result; // al

  result = 0;
  if ( (matchReservationFlags & 1) != 0 )
    result = this->mIsReserved != 0;
  if ( (matchReservationFlags & 2) != 0 && (result || this->mIsInUse) )
    result = 1;
  if ( (matchReservationFlags & 0x10) != 0 && (result || this->mIsCompleted) )
    result = 1;
  if ( (matchReservationFlags & 4) != 0 && (result || this->mCooldownTime > this->mTimeSinceFinished) )
    result = 1;
  if ( (matchReservationFlags & 8) != 0 )
    return result
        || !this->mIsReserved
        && this->mActive
        && (this->mCooldownTime <= this->mTimeSinceFinished || reserveReason == ReserveReason_resume);
  return result;
}

// File Line: 1401
// RVA: 0x5822A0
char __fastcall UFG::InterestPoint::ForceUser(UFG::InterestPoint *this, UFG::SimObject *pUser)
{
  if ( this->mpUser.m_pPointer )
    UFG::InterestPoint::EndReservation(this);
  return UFG::InterestPoint::BeginReservation(this, pUser, ReserveReason_normal);
}

// File Line: 1415
// RVA: 0x58BA60
void __fastcall UFG::InterestPoint::SetUser(UFG::InterestPoint *this, UFG::SimObject *pUser)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mpUser; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax
  signed __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::InterestPointUserComponent> *p_mpInterestPointUserComponent; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v13; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v15; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::InterestPointUserComponent> *v16; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rax

  if ( pUser )
  {
    p_mpUser = &this->mpUser;
    if ( this->mpUser.m_pPointer )
    {
      mPrev = p_mpUser->mPrev;
      mNext = this->mpUser.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_mpUser->mPrev = p_mpUser;
      this->mpUser.mNext = &this->mpUser;
    }
    this->mpUser.m_pPointer = pUser;
    v6 = pUser->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    v6->mNext = p_mpUser;
    p_mpUser->mPrev = v6;
    this->mpUser.mNext = &pUser->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
    pUser->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_mpUser;
    m_Flags = pUser->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = pUser->m_Components.p[43].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = pUser->m_Components.p[12].m_pComponent;
      }
      else if ( (m_Flags & 0x1000) != 0 )
      {
        m_pComponent = 0i64;
      }
      else
      {
        m_pComponent = UFG::SimObject::GetComponentOfType(pUser, UFG::InterestPointUserComponent::_TypeUID);
      }
    }
    else
    {
      m_pComponent = 0i64;
    }
    p_mpInterestPointUserComponent = &this->mpInterestPointUserComponent;
    if ( this->mpInterestPointUserComponent.m_pPointer )
    {
      v10 = p_mpInterestPointUserComponent->mPrev;
      v11 = this->mpInterestPointUserComponent.mNext;
      v10->mNext = v11;
      v11->mPrev = v10;
      p_mpInterestPointUserComponent->mPrev = p_mpInterestPointUserComponent;
      this->mpInterestPointUserComponent.mNext = &this->mpInterestPointUserComponent;
    }
    this->mpInterestPointUserComponent.m_pPointer = m_pComponent;
    if ( m_pComponent )
    {
      v12 = m_pComponent->m_SafePointerList.mNode.mPrev;
      v12->mNext = p_mpInterestPointUserComponent;
      p_mpInterestPointUserComponent->mPrev = v12;
      this->mpInterestPointUserComponent.mNext = &m_pComponent->m_SafePointerList.mNode;
      m_pComponent->m_SafePointerList.mNode.mPrev = p_mpInterestPointUserComponent;
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
      v13->mPrev = v13;
      v13->mNext = v13;
    }
    v13->m_pPointer = 0i64;
    v16 = &this->mpInterestPointUserComponent;
    if ( this->mpInterestPointUserComponent.m_pPointer )
    {
      v17 = v16->mPrev;
      v18 = this->mpInterestPointUserComponent.mNext;
      v17->mNext = v18;
      v18->mPrev = v17;
      v16->mPrev = v16;
      this->mpInterestPointUserComponent.mNext = &this->mpInterestPointUserComponent;
    }
    this->mpInterestPointUserComponent.m_pPointer = 0i64;
  }
}

// File Line: 1433
// RVA: 0x57F470
char __fastcall UFG::InterestPoint::BeginReservation(
        UFG::InterestPoint *this,
        UFG::SimObject *pUser,
        UFG::InterestPoint::eReserveReason reserveReason)
{
  char v3; // si
  signed __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rax

  v3 = reserveReason;
  if ( !pUser )
    return 0;
  UFG::InterestPoint::SetUser(this, pUser);
  this->mIsReserved = 1;
  this->mReserveReason.mValue = v3;
  if ( this->mPoiType.mUID != qSymbol_look.mUID && this->mpUser.m_pPointer )
  {
    m_Flags = pUser->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = pUser->m_Components.p[43].m_pComponent;
      goto LABEL_12;
    }
    if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = pUser->m_Components.p[12].m_pComponent;
        goto LABEL_12;
      }
      if ( (m_Flags & 0x1000) == 0 )
      {
        m_pComponent = UFG::SimObject::GetComponentOfType(pUser, UFG::InterestPointUserComponent::_TypeUID);
LABEL_12:
        if ( m_pComponent )
        {
          LODWORD(m_pComponent[8].m_pSimObject) = UFG::gNullQSymbol;
          HIDWORD(m_pComponent[8].m_pSimObject) = UFG::gNullQSymbol;
        }
      }
    }
  }
  if ( this->mOnReservationScriptInfo.mHasScript )
  {
    if ( !this->mOnReservationScriptInfo.mScriptFired )
      UFG::InterestPoint::StartScript(this, &this->mOnReservationScriptInfo);
  }
  return 1;
}

// File Line: 1471
// RVA: 0x580C30
void __fastcall UFG::InterestPoint::EndReservation(UFG::InterestPoint *this)
{
  unsigned int mUID; // edx
  UFG::SimComponent *m_pPointer; // rcx
  UFG::InterestPointType *mInterestPointType; // rax
  UFG::SimObjectCVBase *v5; // rcx
  __int16 m_Flags; // dx
  UFG::ActiveAIEntityComponent *v7; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mpUser; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::InterestPointUserComponent> *p_mpInterestPointUserComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rax

  UFG::InterestPoint::FinishUsing(this);
  mUID = this->mPoiType.mUID;
  if ( mUID != qSymbol_look.mUID && this->mpUser.m_pPointer )
  {
    m_pPointer = this->mpInterestPointUserComponent.m_pPointer;
    if ( m_pPointer )
    {
      mInterestPointType = this->mInterestPointType;
      LODWORD(m_pPointer[8].m_pSimObject) = mUID;
      HIDWORD(m_pPointer[8].m_pSimObject) = mInterestPointType->mDescription.mUID;
    }
    v5 = (UFG::SimObjectCVBase *)this->mpUser.m_pPointer;
    if ( v5 )
    {
      m_Flags = v5->m_Flags;
      if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
        v7 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v5);
      else
        v7 = (UFG::ActiveAIEntityComponent *)((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                            ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                v5,
                                                UFG::ActiveAIEntityComponent::_TypeUID)
                                            : UFG::SimObject::GetComponentOfType(
                                                v5,
                                                UFG::ActiveAIEntityComponent::_TypeUID));
      if ( v7 )
        UFG::ActiveAIEntityComponent::RestartPoiCooldown(v7);
    }
  }
  p_mpUser = &this->mpUser;
  if ( this->mpUser.m_pPointer )
  {
    mPrev = p_mpUser->mPrev;
    mNext = this->mpUser.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mpUser->mPrev = p_mpUser;
    this->mpUser.mNext = &this->mpUser;
  }
  this->mpUser.m_pPointer = 0i64;
  p_mpInterestPointUserComponent = &this->mpInterestPointUserComponent;
  if ( this->mpInterestPointUserComponent.m_pPointer )
  {
    v12 = p_mpInterestPointUserComponent->mPrev;
    v13 = this->mpInterestPointUserComponent.mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    p_mpInterestPointUserComponent->mPrev = p_mpInterestPointUserComponent;
    this->mpInterestPointUserComponent.mNext = &this->mpInterestPointUserComponent;
  }
  this->mpInterestPointUserComponent.m_pPointer = 0i64;
  *(_DWORD *)&this->mIsInUse = 0;
  this->mIsTimedOut = 0;
  this->mIsReserved = 0;
  this->mOnReservationScriptInfo.mScriptFired = 0;
}

// File Line: 1504
// RVA: 0x57F570
void __fastcall UFG::InterestPoint::BeginUsing(UFG::InterestPoint *this)
{
  UFG::InterestPointProperties *mProperties; // rax
  float RandomNumberInRange; // xmm0_4
  UFG::InterestPointProperties *v4; // rax
  float v5; // xmm0_4

  mProperties = this->mPropertiesHandle.mProperties;
  this->mIsInUse = 1;
  RandomNumberInRange = UFG::GetRandomNumberInRange(mProperties->mUseTimeMin, mProperties->mUseTimeMax);
  v4 = this->mPropertiesHandle.mProperties;
  this->mUseTime = RandomNumberInRange;
  v5 = UFG::GetRandomNumberInRange(v4->mCoolDownTimeMin, v4->mCoolDownTimeMax);
  this->mFullUpdateRequired = 1;
  this->mBeginningScriptInfo.mScriptFired = 0;
  this->mEndingScriptInfo.mScriptFired = 0;
  *(_QWORD *)&this->mTimeSinceBeginUse = 0i64;
  this->mCooldownTime = v5;
  if ( this->mBeginningScriptInfo.mHasScript )
    UFG::InterestPoint::StartScript(this, &this->mBeginningScriptInfo);
}

// File Line: 1524
// RVA: 0x58FBD0
void __fastcall UFG::InterestPoint::UpdateInterestPointTransform(UFG::InterestPoint *this)
{
  UFG::SimComponent *m_pPointer; // rax
  Creature *v3; // rcx
  float y; // xmm1_4
  float z; // xmm0_4
  UFG::qMatrix44 transform; // [rsp+20h] [rbp-48h] BYREF

  if ( this->mBoneId >= 0 || this->mNeedsBoneFixupWhenRigAvailable )
  {
    m_pPointer = this->mpParentCharacterAnimationComponent.m_pPointer;
    if ( m_pPointer )
    {
      if ( *(_QWORD *)&m_pPointer[2].m_TypeUID && !BYTE1(m_pPointer[3].vfptr) && *(_QWORD *)&m_pPointer[1].m_Flags )
      {
        if ( this->mNeedsBoneFixupWhenRigAvailable )
          UFG::InterestPoint::SetBoneIDFromProperties(this);
        v3 = *(Creature **)&this->mpParentCharacterAnimationComponent.m_pPointer[2].m_TypeUID;
        if ( v3 )
        {
          Creature::GetTransform(v3, this->mBoneId, &transform);
          UFG::TransformNodeComponent::SetWorldTransform(this->mpXformNode, &transform);
          y = transform.v3.y;
          this->mCachedPosition.x = transform.v3.x;
          z = transform.v3.z;
          this->mCachedPosition.y = y;
          this->mCachedPosition.z = z;
        }
      }
    }
  }
}

// File Line: 1593
// RVA: 0x58FC90
void __fastcall UFG::InterestPoint::UpdateInterestPoints(float deltaTime)
{
  unsigned int mSimFrameCount; // r14d
  UFG::SimObjectCharacter *LocalPlayer; // rax
  UFG::SimComponent *m_pComponent; // rbp
  UFG::qVector3 *p_m_BoundComponentHandles; // rax
  float x; // xmm7_4
  float y; // xmm8_4
  float z; // xmm9_4
  Render::SkinningCacheNode *Head; // rax
  UFG::InterestPoint *p_mUID; // rbx
  UFG::qBaseNodeRB *p_mNode; // rdx
  UFG::SimComponentHolder *p; // rax
  UFG::qBaseTreeRB *Next; // rax
  UFG::InterestPoint *mChild; // rdi
  UFG::qVector3 *Position; // rax
  UFG::GridIntrusive<UFG::InterestPoint> *v15; // rdx
  int v16; // r9d
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint> *mPrev; // rcx
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint> *mNext; // rax
  UFG::GridIntrusive<UFG::InterestPoint> *v19; // rdx
  UFG::qList<UFG::InterestPoint,UFG::InterestPoint,1,0> *v20; // rcx
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint> *v21; // rax
  Render::SkinningCacheNode *v22; // rax
  UFG::InterestPoint *v23; // rdi
  UFG::qBaseNodeRB *v24; // rdx
  UFG::qBaseTreeRB *v25; // rax
  UFG::qBaseNodeRB **v26; // rsi
  UFG::TransformNodeComponent *mpXformNode; // rbx
  float mMinimumDistanceToPlayerSquared; // xmm0_4
  unsigned int mUID; // eax
  UFG::GridIntrusive<UFG::InterestPoint> *v30; // r9
  UFG::GridIntrusive<UFG::InterestPoint> *v31; // r8
  UFG::GridIntrusive<UFG::InterestPoint> *v32; // rdx
  int v33; // r10d
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint> *v34; // r8
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint> *v35; // rax
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint> *v36; // rcx
  UFG::GridIntrusive<UFG::InterestPoint> *v37; // rdx
  UFG::qList<UFG::InterestPoint,UFG::InterestPoint,1,0> *v38; // rcx
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint> *v39; // rax
  bool v40; // zf
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint> *v41; // rcx
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint> *v42; // rax
  int v43; // r8d
  UFG::qList<UFG::InterestPoint,UFG::InterestPoint,1,0> *v44; // rdx
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint> *v45; // rax

  mSimFrameCount = UFG::Metrics::msInstance.mSimFrameCount;
  UFG::GetLocalPlayer();
  LocalPlayer = UFG::GetLocalPlayer();
  if ( LocalPlayer )
  {
    p = LocalPlayer->m_Components.p;
    m_pComponent = p[2].m_pComponent;
    if ( m_pComponent )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)p[2].m_pComponent);
      p_m_BoundComponentHandles = (UFG::qVector3 *)&m_pComponent[2].m_BoundComponentHandles;
      goto LABEL_4;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  p_m_BoundComponentHandles = &UFG::qVector3::msZero;
LABEL_4:
  x = p_m_BoundComponentHandles->x;
  y = p_m_BoundComponentHandles->y;
  z = p_m_BoundComponentHandles->z;
  Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::InterestPoint::msLookInterestPoints);
  if ( Head )
  {
    p_mUID = (UFG::InterestPoint *)&Head[-4].mNode.mUID;
    if ( Head != (Render::SkinningCacheNode *)136 )
    {
      do
      {
        if ( p_mUID )
          p_mNode = &p_mUID->UFG::qNodeRB<UFG::InterestPoint>::mNode;
        else
          p_mNode = 0i64;
        Next = UFG::qBaseTreeRB::GetNext(&UFG::InterestPoint::msLookInterestPoints.mTree, p_mNode);
        if ( Next )
          mChild = (UFG::InterestPoint *)Next[-2].mRoot.mChild;
        else
          mChild = 0i64;
        if ( mSimFrameCount + p_mUID->m_NameUID == 120 * ((mSimFrameCount + p_mUID->m_NameUID) / 0x78) )
        {
          if ( p_mUID->mAddedToGrid )
          {
            if ( !p_mUID->mRemovedFromGrid )
            {
              Position = UFG::InterestPoint::GetPosition(p_mUID);
              v15 = UFG::InterestPoint::mspLookInterestPointGrid;
              v16 = (int)(float)((float)(Position->x - UFG::InterestPoint::mspLookInterestPointGrid->mXMin)
                               * UFG::InterestPoint::mspLookInterestPointGrid->mGridSizeInv)
                  + UFG::InterestPoint::mspLookInterestPointGrid->mXDim
                  * (int)(float)((float)(Position->y - UFG::InterestPoint::mspLookInterestPointGrid->mYMin)
                               * UFG::InterestPoint::mspLookInterestPointGrid->mGridSizeInv);
              if ( v16 != p_mUID->mGridIndex )
              {
                mPrev = p_mUID->UFG::GridIntrusiveNode<UFG::InterestPoint>::UFG::qNode<UFG::InterestPoint,UFG::InterestPoint>::mPrev;
                mNext = p_mUID->UFG::GridIntrusiveNode<UFG::InterestPoint>::UFG::qNode<UFG::InterestPoint,UFG::InterestPoint>::mNext;
                mPrev->mNext = mNext;
                mNext->mPrev = mPrev;
                --v15->mNodeCount;
                v19 = UFG::InterestPoint::mspLookInterestPointGrid;
                v20 = &UFG::InterestPoint::mspLookInterestPointGrid->mGridNodes[v16];
                p_mUID->UFG::GridIntrusiveNode<UFG::InterestPoint>::UFG::qNode<UFG::InterestPoint,UFG::InterestPoint>::mNext = &v20->mNode;
                v21 = v20->mNode.mPrev;
                p_mUID->UFG::GridIntrusiveNode<UFG::InterestPoint>::UFG::qNode<UFG::InterestPoint,UFG::InterestPoint>::mPrev = v20->mNode.mPrev;
                p_mUID->mGridIndex = v16;
                v21->mNext = &p_mUID->UFG::GridIntrusiveNode<UFG::InterestPoint>;
                v20->mNode.mPrev = &p_mUID->UFG::GridIntrusiveNode<UFG::InterestPoint>;
                ++v19->mNodeCount;
              }
            }
          }
        }
        p_mUID = mChild;
      }
      while ( mChild );
    }
  }
  v22 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::InterestPoint::msUseInterestPoints);
  if ( v22 )
  {
    v23 = (UFG::InterestPoint *)&v22[-4].mNode.mUID;
    if ( v22 != (Render::SkinningCacheNode *)136 )
    {
      while ( 1 )
      {
        if ( v23 )
          v24 = &v23->UFG::qNodeRB<UFG::InterestPoint>::mNode;
        else
          v24 = 0i64;
        v25 = UFG::qBaseTreeRB::GetNext(&UFG::InterestPoint::msUseInterestPoints.mTree, v24);
        if ( v25 )
          v26 = v25[-2].mRoot.mChild;
        else
          v26 = 0i64;
        if ( v23->mBoneId < 0 && !v23->mNeedsBoneFixupWhenRigAvailable
          || mSimFrameCount + v23->m_NameUID != 60 * ((mSimFrameCount + v23->m_NameUID) / 0x3C) )
        {
          goto LABEL_56;
        }
        UFG::InterestPoint::UpdateInterestPointTransform(v23);
        if ( !v23->mIsPositionCached )
        {
          mpXformNode = v23->mpXformNode;
          UFG::TransformNodeComponent::UpdateWorldTransform(mpXformNode);
          v23->mCachedPosition.x = mpXformNode->mWorldTransform.v3.x;
          v23->mCachedPosition.y = mpXformNode->mWorldTransform.v3.y;
          v23->mCachedPosition.z = mpXformNode->mWorldTransform.v3.z;
          v23->mIsPositionCached = 1;
        }
        if ( m_pComponent )
        {
          mMinimumDistanceToPlayerSquared = v23->mMinimumDistanceToPlayerSquared;
          if ( mMinimumDistanceToPlayerSquared >= (float)((float)((float)((float)(y - v23->mCachedPosition.y)
                                                                        * (float)(y - v23->mCachedPosition.y))
                                                                + (float)((float)(x - v23->mCachedPosition.x)
                                                                        * (float)(x - v23->mCachedPosition.x)))
                                                        + (float)((float)(z - v23->mCachedPosition.z)
                                                                * (float)(z - v23->mCachedPosition.z))) )
            mMinimumDistanceToPlayerSquared = (float)((float)((float)(y - v23->mCachedPosition.y)
                                                            * (float)(y - v23->mCachedPosition.y))
                                                    + (float)((float)(x - v23->mCachedPosition.x)
                                                            * (float)(x - v23->mCachedPosition.x)))
                                            + (float)((float)(z - v23->mCachedPosition.z)
                                                    * (float)(z - v23->mCachedPosition.z));
          v23->mMinimumDistanceToPlayerSquared = mMinimumDistanceToPlayerSquared;
          UFG::InterestPoint::UpdateAnimHandles(v23);
        }
        if ( !v23->mAddedToGrid || v23->mRemovedFromGrid )
          goto LABEL_46;
        mUID = qSymbol_look.mUID;
        v30 = UFG::InterestPoint::mspUseInterestPointGrid;
        v31 = UFG::InterestPoint::mspLookInterestPointGrid;
        v32 = UFG::InterestPoint::mspUseInterestPointGrid;
        if ( v23->mPoiType.mUID == qSymbol_look.mUID )
          v32 = UFG::InterestPoint::mspLookInterestPointGrid;
        v33 = (int)(float)((float)(v23->mCachedPosition.x - v32->mXMin) * v32->mGridSizeInv)
            + v32->mXDim * (int)(float)((float)(v23->mCachedPosition.y - v32->mYMin) * v32->mGridSizeInv);
        if ( v33 >= 0 && v33 != v23->mGridIndex )
          break;
LABEL_47:
        if ( v23->mLinkObject.m_pPointer )
        {
          if ( !v23->mAddedToGrid )
            goto LABEL_53;
          v40 = v23->mPoiType.mUID == mUID;
          v41 = v23->UFG::GridIntrusiveNode<UFG::InterestPoint>::UFG::qNode<UFG::InterestPoint,UFG::InterestPoint>::mPrev;
          v42 = v23->UFG::GridIntrusiveNode<UFG::InterestPoint>::UFG::qNode<UFG::InterestPoint,UFG::InterestPoint>::mNext;
          v23->UFG::GridIntrusiveNode<UFG::InterestPoint>::UFG::qNode<UFG::InterestPoint,UFG::InterestPoint>::mPrev = &v23->UFG::GridIntrusiveNode<UFG::InterestPoint>;
          v41->mNext = v42;
          v23->UFG::GridIntrusiveNode<UFG::InterestPoint>::UFG::qNode<UFG::InterestPoint,UFG::InterestPoint>::mNext = &v23->UFG::GridIntrusiveNode<UFG::InterestPoint>;
          if ( v40 )
            v30 = v31;
          v42->mPrev = v41;
          --v30->mNodeCount;
          *(_WORD *)&v23->mAddedToGrid = 256;
          v23->mGridIndex = -1;
        }
        else if ( !v23->mAddedToGrid )
        {
LABEL_53:
          if ( v23->mPoiType.mUID == mUID )
            v30 = v31;
          v43 = (int)(float)((float)(v23->mCachedPosition.x - v30->mXMin) * v30->mGridSizeInv)
              + v30->mXDim * (int)(float)((float)(v23->mCachedPosition.y - v30->mYMin) * v30->mGridSizeInv);
          v44 = &v30->mGridNodes[v43];
          v23->UFG::GridIntrusiveNode<UFG::InterestPoint>::UFG::qNode<UFG::InterestPoint,UFG::InterestPoint>::mNext = &v44->mNode;
          v45 = v44->mNode.mPrev;
          v23->UFG::GridIntrusiveNode<UFG::InterestPoint>::UFG::qNode<UFG::InterestPoint,UFG::InterestPoint>::mPrev = v44->mNode.mPrev;
          v23->mGridIndex = v43;
          *(_WORD *)&v23->mAddedToGrid = 1;
          v45->mNext = &v23->UFG::GridIntrusiveNode<UFG::InterestPoint>;
          v44->mNode.mPrev = &v23->UFG::GridIntrusiveNode<UFG::InterestPoint>;
          ++v30->mNodeCount;
        }
LABEL_56:
        if ( v23->mFullUpdateRequired )
          v23->mFullUpdateRequired = ((unsigned __int8 (__fastcall *)(UFG::InterestPoint *))v23->UFG::MarkerBase::UFG::HintComponentBase::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[17].__vecDelDtor)(v23) == 0;
        UFG::InterestPoint::UpdateReservation(v23);
        v23 = (UFG::InterestPoint *)v26;
        if ( !v26 )
          return;
      }
      v34 = &v23->UFG::GridIntrusiveNode<UFG::InterestPoint>;
      v35 = v23->UFG::GridIntrusiveNode<UFG::InterestPoint>::UFG::qNode<UFG::InterestPoint,UFG::InterestPoint>::mNext;
      v36 = v23->UFG::GridIntrusiveNode<UFG::InterestPoint>::UFG::qNode<UFG::InterestPoint,UFG::InterestPoint>::mPrev;
      v23->UFG::GridIntrusiveNode<UFG::InterestPoint>::UFG::qNode<UFG::InterestPoint,UFG::InterestPoint>::mPrev = &v23->UFG::GridIntrusiveNode<UFG::InterestPoint>;
      v36->mNext = v35;
      v35->mPrev = v36;
      --v32->mNodeCount;
      LODWORD(v35) = qSymbol_look;
      v37 = UFG::InterestPoint::mspUseInterestPointGrid;
      v23->UFG::GridIntrusiveNode<UFG::InterestPoint>::UFG::qNode<UFG::InterestPoint,UFG::InterestPoint>::mNext = &v23->UFG::GridIntrusiveNode<UFG::InterestPoint>;
      if ( v23->mPoiType.mUID == (_DWORD)v35 )
        v37 = UFG::InterestPoint::mspLookInterestPointGrid;
      v38 = &v37->mGridNodes[v33];
      v23->UFG::GridIntrusiveNode<UFG::InterestPoint>::UFG::qNode<UFG::InterestPoint,UFG::InterestPoint>::mNext = &v38->mNode;
      v39 = v38->mNode.mPrev;
      v34->mPrev = v38->mNode.mPrev;
      v23->mGridIndex = v33;
      v39->mNext = v34;
      v38->mNode.mPrev = v34;
      ++v37->mNodeCount;
LABEL_46:
      v30 = UFG::InterestPoint::mspUseInterestPointGrid;
      mUID = qSymbol_look.mUID;
      v31 = UFG::InterestPoint::mspLookInterestPointGrid;
      goto LABEL_47;
    }
  }
}

// File Line: 1795
// RVA: 0x590A20
void __fastcall UFG::InterestPoint::UpdateReservation(UFG::InterestPoint *this)
{
  UFG::SimObjectGame *m_pPointer; // rdx
  UFG::qVector3 *Position; // rax
  UFG::qVector3 result; // [rsp+20h] [rbp-18h] BYREF

  m_pPointer = (UFG::SimObjectGame *)this->mpUser.m_pPointer;
  if ( m_pPointer && this->mReserveReason.mValue == 2 && this->mIsReserved && !this->mIsInUse && !this->mIsCompleted )
  {
    UFG::GetPosition(&result, m_pPointer);
    Position = UFG::InterestPoint::GetPosition(this);
    if ( (float)((float)((float)((float)(result.y - Position->y) * (float)(result.y - Position->y))
                       + (float)((float)(result.x - Position->x) * (float)(result.x - Position->x)))
               + (float)((float)(result.z - Position->z) * (float)(result.z - Position->z))) > (float)(this->mPropertiesHandle.mProperties->mMaxAppealRadius * this->mPropertiesHandle.mProperties->mMaxAppealRadius) )
      UFG::InterestPoint::EndReservation(this);
  }
}

// File Line: 1814
// RVA: 0x587760
bool __fastcall UFG::InterestPoint::OnUpdate(UFG::InterestPoint *this, float deltaTime)
{
  bool v3; // al
  UFG::SimComponent *m_pPointer; // rdx
  bool v5; // cl
  float v6; // xmm0_4
  float mUseTime; // xmm1_4
  bool isPlayingOpeningBranch; // [rsp+58h] [rbp+10h] BYREF

  isPlayingOpeningBranch = 0;
  v3 = this->mTimeSinceBeginUse != 0.0 && UFG::InterestPoint::CheckOutsideForInteruption(this, &isPlayingOpeningBranch);
  m_pPointer = this->mpInterestPointUserComponent.m_pPointer;
  v5 = 1;
  if ( m_pPointer )
    v5 = LODWORD(m_pPointer[7].m_BoundComponentHandles.mNode.mNext) != 3;
  v6 = deltaTime + this->mTimeSinceBeginUse;
  this->mTimeSinceBeginUse = v6;
  if ( this->mIsInUse )
  {
    if ( v3 && !isPlayingOpeningBranch )
      this->mIsInterrupted = 1;
    if ( v5 )
    {
      mUseTime = this->mUseTime;
      if ( v6 > mUseTime && mUseTime > 0.0 )
        this->mIsTimedOut = 1;
    }
    if ( this->mIsTimedOut || v3 )
    {
      *(_WORD *)&this->mIsInUse = 256;
      if ( UFG::GetLocalPlayer() == this->mpUser.m_pPointer || this->mPropertiesHandle.mProperties->mIsAutoInteractable )
        UFG::InterestPoint::EndReservation(this);
    }
  }
  else
  {
    this->mTimeSinceFinished = deltaTime + this->mTimeSinceFinished;
  }
  return this->mCooldownTime < this->mTimeSinceFinished;
}

// File Line: 1895
// RVA: 0x57F600
bool __fastcall UFG::InterestPoint::CheckOutsideForInteruption(UFG::InterestPoint *this, bool *isPlayingOpeningBranch)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::SimComponent *m_pComponent; // rbx
  UFG::SimComponent *v6; // rax
  unsigned int ActionMostUsedIndex_Interactions; // eax
  unsigned __int8 IsPlaying; // al
  bool v9; // di

  *isPlayingOpeningBranch = 0;
  m_pPointer = (UFG::SimObjectGame *)this->mpUser.m_pPointer;
  if ( !m_pPointer )
    return 1;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[7].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[6].m_pComponent;
    }
    else
    {
      v6 = (m_Flags & 0x1000) != 0
         ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::ActionTreeComponent::_TypeUID)
         : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::ActionTreeComponent::_TypeUID);
      m_pComponent = v6;
    }
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[7].m_pComponent;
  }
  if ( !m_pComponent )
    return 1;
  if ( (_S9_16 & 1) == 0 )
  {
    _S9_16 |= 1u;
    node_id.mUID = UFG::qStringHashUpper32("Interactions", -1);
  }
  ActionMostUsedIndex_Interactions = `anonymous namespace::GetActionMostUsedIndex_Interactions();
  IsPlaying = ActionController::IsPlaying(
                (ActionController *)&m_pComponent[3],
                &node_id,
                ActionMostUsedIndex_Interactions,
                0);
  v9 = IsPlaying == 0;
  if ( !IsPlaying )
    *isPlayingOpeningBranch = ActionController::IsPlaying(
                                (ActionController *)&m_pComponent[3],
                                (ActionNodePlayable *)m_pComponent[2].m_BoundComponentHandles.mNode.mNext[1].mNext);
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
  UFG::SimObject *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *vfptr; // rcx
  UFG::InterestPointLink *v6; // rcx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mLinkObject; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax

  m_pPointer = this->mpUser.m_pPointer;
  if ( !m_pPointer )
    return;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[4].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 )
      m_pComponent = m_pPointer->m_Components.p[3].m_pComponent;
    else
      m_pComponent = (m_Flags & 0x1000) != 0
                   ? m_pPointer->m_Components.p[2].m_pComponent
                   : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TSActorComponent::_TypeUID);
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[4].m_pComponent;
  }
  if ( !m_pComponent )
    return;
  vfptr = m_pComponent[1].vfptr;
  if ( !vfptr || LODWORD(m_pComponent[1].m_SafePointerList.mNode.mPrev) != LODWORD(vfptr[1].__vecDelDtor) )
    return;
  if ( !this->mIsInUse )
    goto LABEL_18;
  if ( this->mBeginningScriptInfo.mHasScript )
  {
    if ( !this->mBeginningScriptInfo.mScriptFired )
      UFG::InterestPoint::StartScript(this, &this->mBeginningScriptInfo);
LABEL_18:
    if ( this->mBeginningScriptInfo.mHasScript
      && this->mBeginningScriptInfo.mScriptFired
      && this->mEndingScriptInfo.mHasScript
      && !this->mEndingScriptInfo.mScriptFired )
    {
      UFG::InterestPoint::StartScript(this, &this->mEndingScriptInfo);
    }
  }
  if ( this->mLinkObject.m_pPointer )
  {
    v6 = (UFG::InterestPointLink *)this->mpInterestPointUserComponent.m_pPointer;
    if ( !v6[14].mIsExclusive )
    {
      UFG::InterestPointLink::Reset(v6 + 14);
      p_mLinkObject = &this->mLinkObject;
      if ( p_mLinkObject->m_pPointer )
      {
        mPrev = p_mLinkObject->mPrev;
        mNext = p_mLinkObject->mNext;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        p_mLinkObject->mPrev = p_mLinkObject;
        p_mLinkObject->mNext = p_mLinkObject;
      }
      p_mLinkObject->m_pPointer = 0i64;
    }
  }
}

// File Line: 1959
// RVA: 0x58C710
void __fastcall UFG::InterestPoint::StartScript(UFG::InterestPoint *this, UFG::ScriptInfo *scriptInfo)
{
  bool v2; // zf
  UFG::SimObject *m_pPointer; // rcx
  UFG::TSActor *v5; // rax
  SSInstance *v6; // rsi
  SSClass *i_class_p; // rbx
  SSCode *ScriptCode; // rax

  v2 = scriptInfo->mpCachedScript == 0i64;
  scriptInfo->mScriptFired = 1;
  if ( !v2 )
  {
    m_pPointer = this->mpUser.m_pPointer;
    if ( m_pPointer )
    {
      v5 = UFG::TSActor::FromSimObject(m_pPointer);
      v6 = v5;
      if ( v5 )
      {
        i_class_p = v5->i_class_p;
        ScriptCode = UFG::ScriptCache::GetScriptCode(scriptInfo->mpCachedScript);
        UFG::SkookumMgr::RunExternalCodeBlock(ScriptCode, i_class_p, v6, 0i64, 0i64);
      }
    }
  }
}

// File Line: 1988
// RVA: 0x57FEA0
UFG::qSymbol *__fastcall UFG::InterestPoint::ConvertTypeToPropertiesName(UFG::qSymbol *result, UFG::qSymbolUC *type)
{
  char *v4; // rbx
  char *v5; // rax
  UFG::qString v7; // [rsp+28h] [rbp-30h] BYREF

  UFG::qString::qString(&v7);
  v4 = UFG::qSymbol::as_cstr_dbg(type);
  v5 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&qSymbolX_propset_componentPOI);
  UFG::qString::Format(&v7, "%s-%s", v5, v4);
  UFG::qSymbol::create_from_string(result, v7.mData);
  UFG::qString::~qString(&v7);
  return result;
}

// File Line: 2032
// RVA: 0x581230
UFG::InterestPoint *__fastcall UFG::InterestPoint::FindNearestMinMaxOfType(
        UFG::qVector3 *pos,
        const bool includeActive,
        const bool includeInactive,
        UFG::qSymbol *type,
        float minDistSquared,
        float maxDistSquared,
        float *pDistSquared)
{
  UFG::InterestPoint *v7; // rsi
  float v12; // xmm6_4
  unsigned int mUID; // eax
  UFG::qBaseTreeRB *i; // rax
  UFG::InterestPoint *v15; // rbx
  UFG::qVector3 *Position; // rax
  float v17; // xmm2_4
  UFG::qBaseTreeRB *j; // rax
  __int64 v19; // rdi
  __int64 v20; // rbx
  int v21; // xmm0_4
  int v22; // xmm1_4
  float v23; // xmm2_4
  UFG::InterestPoint *result; // rax

  v7 = 0i64;
  v12 = maxDistSquared;
  mUID = qSymbol_Any.mUID;
  if ( type->mUID == qSymbol_Any.mUID || type->mUID == qSymbol_look.mUID )
  {
    for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::InterestPoint::msLookInterestPoints);
          ;
          i = UFG::qBaseTreeRB::GetNext(
                &UFG::InterestPoint::msLookInterestPoints.mTree,
                &v15->UFG::qNodeRB<UFG::InterestPoint>::mNode) )
    {
      v15 = i ? (UFG::InterestPoint *)i[-2].mRoot.mChild : 0i64;
      if ( !v15 )
        break;
      if ( (type->mUID == qSymbol_Any.mUID || type->mUID == v15->mPoiType.mUID)
        && (includeActive && v15->mActive || includeInactive && !v15->mActive) )
      {
        Position = UFG::InterestPoint::GetPosition(v15);
        v17 = (float)((float)((float)(pos->y - Position->y) * (float)(pos->y - Position->y))
                    + (float)((float)(pos->x - Position->x) * (float)(pos->x - Position->x)))
            + (float)((float)(pos->z - Position->z) * (float)(pos->z - Position->z));
        if ( v17 < v12 && v17 > minDistSquared && v17 < maxDistSquared )
        {
          v12 = (float)((float)((float)(pos->y - Position->y) * (float)(pos->y - Position->y))
                      + (float)((float)(pos->x - Position->x) * (float)(pos->x - Position->x)))
              + (float)((float)(pos->z - Position->z) * (float)(pos->z - Position->z));
          v7 = v15;
        }
      }
    }
    mUID = qSymbol_Any.mUID;
  }
  if ( type->mUID == mUID )
  {
    for ( j = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::InterestPoint::msUseInterestPoints);
          ;
          j = UFG::qBaseTreeRB::GetNext(&UFG::InterestPoint::msUseInterestPoints.mTree, (UFG::qBaseNodeRB *)(v19 + 136)) )
    {
      v19 = j ? (__int64)j[-2].mRoot.mChild : 0i64;
      if ( !v19 )
        break;
      if ( (type->mUID == qSymbol_Any.mUID || type->mUID == *(_DWORD *)(v19 + 300))
        && (includeActive && *(_BYTE *)(v19 + 430) || includeInactive && !*(_BYTE *)(v19 + 430)) )
      {
        if ( !*(_BYTE *)(v19 + 316) )
        {
          v20 = *(_QWORD *)(v19 + 104);
          UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v20);
          v21 = *(_DWORD *)(v20 + 180);
          v22 = *(_DWORD *)(v20 + 184);
          *(_DWORD *)(v19 + 304) = *(_DWORD *)(v20 + 176);
          *(_DWORD *)(v19 + 308) = v21;
          *(_DWORD *)(v19 + 312) = v22;
          *(_BYTE *)(v19 + 316) = 1;
        }
        v23 = (float)((float)((float)(pos->x - *(float *)(v19 + 304)) * (float)(pos->x - *(float *)(v19 + 304)))
                    + (float)((float)(pos->y - *(float *)(v19 + 308)) * (float)(pos->y - *(float *)(v19 + 308))))
            + (float)((float)(pos->z - *(float *)(v19 + 312)) * (float)(pos->z - *(float *)(v19 + 312)));
        if ( v23 < v12 && v23 > minDistSquared && v23 < maxDistSquared )
        {
          v12 = (float)((float)((float)(pos->x - *(float *)(v19 + 304)) * (float)(pos->x - *(float *)(v19 + 304)))
                      + (float)((float)(pos->y - *(float *)(v19 + 308)) * (float)(pos->y - *(float *)(v19 + 308))))
              + (float)((float)(pos->z - *(float *)(v19 + 312)) * (float)(pos->z - *(float *)(v19 + 312)));
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
UFG::InterestPoint *__fastcall UFG::InterestPoint::FindNearestMinOfType(
        UFG::qVector3 *pos,
        UFG::qSymbol *type,
        float minDistSquared,
        float maxDistSquared,
        float *pDistSquared)
{
  unsigned int mUID; // eax
  unsigned int v9; // edx
  UFG::InterestPoint *v10; // rsi
  UFG::qBaseTreeRB *i; // rax
  __int64 v13; // rdi
  __int64 v14; // rbx
  int v15; // xmm0_4
  int v16; // xmm1_4
  float v17; // xmm2_4
  UFG::qBaseTreeRB *j; // rax
  __int64 v19; // rdi
  __int64 v20; // rbx
  int v21; // xmm0_4
  int v22; // xmm1_4
  float v23; // xmm2_4
  UFG::InterestPoint *result; // rax

  mUID = qSymbol_Any.mUID;
  v9 = type->mUID;
  v10 = 0i64;
  if ( v9 == qSymbol_Any.mUID || v9 == qSymbol_look.mUID )
  {
    for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::InterestPoint::msLookInterestPoints);
          ;
          i = UFG::qBaseTreeRB::GetNext(
                &UFG::InterestPoint::msLookInterestPoints.mTree,
                (UFG::qBaseNodeRB *)(v13 + 136)) )
    {
      v13 = i ? (__int64)i[-2].mRoot.mChild : 0i64;
      if ( !v13 )
        break;
      if ( type->mUID == qSymbol_Any.mUID || type->mUID == *(_DWORD *)(v13 + 300) )
      {
        if ( !*(_BYTE *)(v13 + 316) )
        {
          v14 = *(_QWORD *)(v13 + 104);
          UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v14);
          v15 = *(_DWORD *)(v14 + 180);
          v16 = *(_DWORD *)(v14 + 184);
          *(_DWORD *)(v13 + 304) = *(_DWORD *)(v14 + 176);
          *(_DWORD *)(v13 + 308) = v15;
          *(_DWORD *)(v13 + 312) = v16;
          *(_BYTE *)(v13 + 316) = 1;
        }
        v17 = (float)((float)((float)(pos->y - *(float *)(v13 + 308)) * (float)(pos->y - *(float *)(v13 + 308)))
                    + (float)((float)(pos->x - *(float *)(v13 + 304)) * (float)(pos->x - *(float *)(v13 + 304))))
            + (float)((float)(pos->z - *(float *)(v13 + 312)) * (float)(pos->z - *(float *)(v13 + 312)));
        if ( v17 < maxDistSquared && v17 > minDistSquared )
        {
          maxDistSquared = (float)((float)((float)(pos->y - *(float *)(v13 + 308))
                                         * (float)(pos->y - *(float *)(v13 + 308)))
                                 + (float)((float)(pos->x - *(float *)(v13 + 304))
                                         * (float)(pos->x - *(float *)(v13 + 304))))
                         + (float)((float)(pos->z - *(float *)(v13 + 312)) * (float)(pos->z - *(float *)(v13 + 312)));
          v10 = (UFG::InterestPoint *)v13;
        }
      }
    }
    mUID = qSymbol_Any.mUID;
  }
  if ( type->mUID == mUID )
  {
    for ( j = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::InterestPoint::msUseInterestPoints);
          ;
          j = UFG::qBaseTreeRB::GetNext(&UFG::InterestPoint::msUseInterestPoints.mTree, (UFG::qBaseNodeRB *)(v19 + 136)) )
    {
      v19 = j ? (__int64)j[-2].mRoot.mChild : 0i64;
      if ( !v19 )
        break;
      if ( type->mUID == qSymbol_Any.mUID || type->mUID == *(_DWORD *)(v19 + 300) )
      {
        if ( !*(_BYTE *)(v19 + 316) )
        {
          v20 = *(_QWORD *)(v19 + 104);
          UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v20);
          v21 = *(_DWORD *)(v20 + 180);
          v22 = *(_DWORD *)(v20 + 184);
          *(_DWORD *)(v19 + 304) = *(_DWORD *)(v20 + 176);
          *(_DWORD *)(v19 + 308) = v21;
          *(_DWORD *)(v19 + 312) = v22;
          *(_BYTE *)(v19 + 316) = 1;
        }
        v23 = (float)((float)((float)(pos->x - *(float *)(v19 + 304)) * (float)(pos->x - *(float *)(v19 + 304)))
                    + (float)((float)(pos->y - *(float *)(v19 + 308)) * (float)(pos->y - *(float *)(v19 + 308))))
            + (float)((float)(pos->z - *(float *)(v19 + 312)) * (float)(pos->z - *(float *)(v19 + 312)));
        if ( v23 < maxDistSquared && v23 > minDistSquared )
        {
          maxDistSquared = (float)((float)((float)(pos->x - *(float *)(v19 + 304))
                                         * (float)(pos->x - *(float *)(v19 + 304)))
                                 + (float)((float)(pos->y - *(float *)(v19 + 308))
                                         * (float)(pos->y - *(float *)(v19 + 308))))
                         + (float)((float)(pos->z - *(float *)(v19 + 312)) * (float)(pos->z - *(float *)(v19 + 312)));
          v10 = (UFG::InterestPoint *)v19;
        }
      }
    }
  }
  result = v10;
  if ( pDistSquared )
    *pDistSquared = maxDistSquared;
  return result;
}

// File Line: 2176
// RVA: 0x580FD0
UFG::InterestPoint *__fastcall UFG::InterestPoint::FindNearestMaxOfType(
        UFG::qVector3 *pos,
        UFG::qSymbol *type,
        float minDistSquared,
        float maxDistSquared,
        float *pDistSquared)
{
  float v5; // xmm6_4
  UFG::InterestPoint *v6; // rsi
  UFG::qBaseTreeRB *i; // rax
  __int64 v10; // rdi
  __int64 v11; // rbx
  int v12; // xmm0_4
  int v13; // xmm1_4
  float v14; // xmm2_4
  UFG::qBaseTreeRB *j; // rax
  __int64 v16; // rdi
  __int64 v17; // rbx
  int v18; // xmm0_4
  int v19; // xmm1_4
  float v20; // xmm2_4
  UFG::InterestPoint *result; // rax

  v5 = maxDistSquared;
  v6 = 0i64;
  if ( type->mUID != qSymbol_Any.mUID && type->mUID != qSymbol_look.mUID )
    goto LABEL_17;
  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::InterestPoint::msLookInterestPoints);
        ;
        i = UFG::qBaseTreeRB::GetNext(&UFG::InterestPoint::msLookInterestPoints.mTree, (UFG::qBaseNodeRB *)(v10 + 136)) )
  {
    v10 = i ? (__int64)i[-2].mRoot.mChild : 0i64;
    if ( !v10 )
      break;
    if ( type->mUID == qSymbol_Any.mUID || type->mUID == *(_DWORD *)(v10 + 300) )
    {
      if ( !*(_BYTE *)(v10 + 316) )
      {
        v11 = *(_QWORD *)(v10 + 104);
        UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v11);
        v12 = *(_DWORD *)(v11 + 180);
        v13 = *(_DWORD *)(v11 + 184);
        *(_DWORD *)(v10 + 304) = *(_DWORD *)(v11 + 176);
        *(_DWORD *)(v10 + 308) = v12;
        *(_DWORD *)(v10 + 312) = v13;
        *(_BYTE *)(v10 + 316) = 1;
      }
      v14 = (float)((float)((float)(pos->y - *(float *)(v10 + 308)) * (float)(pos->y - *(float *)(v10 + 308)))
                  + (float)((float)(pos->x - *(float *)(v10 + 304)) * (float)(pos->x - *(float *)(v10 + 304))))
          + (float)((float)(pos->z - *(float *)(v10 + 312)) * (float)(pos->z - *(float *)(v10 + 312)));
      if ( v14 < v5 && v14 < maxDistSquared )
      {
        v5 = (float)((float)((float)(pos->y - *(float *)(v10 + 308)) * (float)(pos->y - *(float *)(v10 + 308)))
                   + (float)((float)(pos->x - *(float *)(v10 + 304)) * (float)(pos->x - *(float *)(v10 + 304))))
           + (float)((float)(pos->z - *(float *)(v10 + 312)) * (float)(pos->z - *(float *)(v10 + 312)));
        v6 = (UFG::InterestPoint *)v10;
      }
    }
  }
  if ( type->mUID != qSymbol_look.mUID )
  {
LABEL_17:
    for ( j = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::InterestPoint::msUseInterestPoints);
          ;
          j = UFG::qBaseTreeRB::GetNext(&UFG::InterestPoint::msUseInterestPoints.mTree, (UFG::qBaseNodeRB *)(v16 + 136)) )
    {
      v16 = j ? (__int64)j[-2].mRoot.mChild : 0i64;
      if ( !v16 )
        break;
      if ( type->mUID == qSymbol_Any.mUID || type->mUID == *(_DWORD *)(v16 + 300) )
      {
        if ( !*(_BYTE *)(v16 + 316) )
        {
          v17 = *(_QWORD *)(v16 + 104);
          UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v17);
          v18 = *(_DWORD *)(v17 + 180);
          v19 = *(_DWORD *)(v17 + 184);
          *(_DWORD *)(v16 + 304) = *(_DWORD *)(v17 + 176);
          *(_DWORD *)(v16 + 308) = v18;
          *(_DWORD *)(v16 + 312) = v19;
          *(_BYTE *)(v16 + 316) = 1;
        }
        v20 = (float)((float)((float)(pos->x - *(float *)(v16 + 304)) * (float)(pos->x - *(float *)(v16 + 304)))
                    + (float)((float)(pos->y - *(float *)(v16 + 308)) * (float)(pos->y - *(float *)(v16 + 308))))
            + (float)((float)(pos->z - *(float *)(v16 + 312)) * (float)(pos->z - *(float *)(v16 + 312)));
        if ( v20 < v5 && v20 < maxDistSquared )
        {
          v5 = (float)((float)((float)(pos->x - *(float *)(v16 + 304)) * (float)(pos->x - *(float *)(v16 + 304)))
                     + (float)((float)(pos->y - *(float *)(v16 + 308)) * (float)(pos->y - *(float *)(v16 + 308))))
             + (float)((float)(pos->z - *(float *)(v16 + 312)) * (float)(pos->z - *(float *)(v16 + 312)));
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
bool __fastcall UFG::InterestPoint::IsRelevantToPropertySet(
        UFG::InterestPoint *this,
        UFG::PropertySetManager *pCharacterProperties)
{
  float v4; // xmm1_4
  float m_SecondsSinceMidnight; // xmm0_4
  UFG::InterestPointProperties *mProperties; // rax
  float v7; // xmm0_4
  float mTimeOfDayToBecomeActive; // xmm2_4
  float mTimeOfDayToBecomeInactive; // xmm1_4
  UFG::qPropertySet *ComponentData; // rax
  int mOffset_high; // ecx
  bool v13; // di
  schema_classlist *v14; // rax
  __int64 mOffset; // rcx
  UFG::qPropertyList *v16; // r14
  unsigned int mNumElements; // ebp
  unsigned int i; // esi
  UFG::qSymbol *v19; // rax
  unsigned int v20; // ecx
  UFG::qSymbol *v21; // r8
  UFG::InterestPointProperties *v22; // rax
  unsigned int size; // edx
  unsigned int mUID; // r8d
  UFG::qSymbol *p; // rax

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
    m_SecondsSinceMidnight = UFG::TimeOfDayManager::GetInstance()->m_SecondsSinceMidnight;
    mProperties = this->mPropertiesHandle.mProperties;
    v7 = m_SecondsSinceMidnight * 0.00027777778;
    mTimeOfDayToBecomeActive = mProperties->mTimeOfDayToBecomeActive;
    mTimeOfDayToBecomeInactive = mProperties->mTimeOfDayToBecomeInactive;
    if ( mTimeOfDayToBecomeActive >= mTimeOfDayToBecomeInactive )
    {
      if ( mTimeOfDayToBecomeActive <= v7 )
        goto LABEL_14;
    }
    else if ( mTimeOfDayToBecomeActive < v7 )
    {
      return 0;
    }
    if ( v7 > mTimeOfDayToBecomeInactive )
      return 0;
  }
LABEL_14:
  if ( this->mPropertiesHandle.mProperties->mGendersAllowed.mUID != qSymbol_Any.mUID )
  {
    ComponentData = UFG::PropertySetManager::GetComponentDataPtr<component_CharacterProperties>(
                      pCharacterProperties,
                      (UFG::qPropertySet *)pCharacterProperties);
    if ( ComponentData )
    {
      mOffset_high = HIDWORD(ComponentData->mParents.mOffset);
      if ( mOffset_high == UFG::gNullQSymbol.mUID
        || this->mPropertiesHandle.mProperties->mGendersAllowed.mUID != mOffset_high )
      {
        return 0;
      }
    }
  }
  if ( !this->mPropertiesHandle.mProperties->mUseClassList.size )
    return 1;
  v13 = 0;
  v14 = UFG::PropertySetManager::GetComponentDataPtr<schema_classlist>(
          pCharacterProperties,
          (UFG::qPropertySet *)pCharacterProperties);
  if ( !v14 )
    return 1;
  mOffset = v14->ClassTypeList.mOffset;
  if ( !mOffset )
    return 1;
  v16 = (UFG::qPropertyList *)((char *)&v14->ClassTypeList + mOffset);
  if ( !v16 )
    return 1;
  mNumElements = v16->mNumElements;
  for ( i = 0; i < mNumElements; ++i )
  {
    v19 = UFG::qPropertyList::Get<UFG::qSymbol>(v16, i);
    v20 = 0;
    v21 = v19;
    v22 = this->mPropertiesHandle.mProperties;
    size = v22->mUseClassList.size;
    if ( size )
    {
      mUID = v21->mUID;
      p = v22->mUseClassList.p;
      while ( mUID != p->mUID )
      {
        ++v20;
        ++p;
        if ( v20 >= size )
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
  }
  return v13 == this->mPropertiesHandle.mProperties->mClassListIsAllowed;
}

// File Line: 2416
// RVA: 0x584D70
bool __fastcall UFG::InterestPoint::IsRelevantToCharacter(
        UFG::InterestPoint *this,
        UFG::SimObjectCharacter *_pCharacter,
        UFG::InterestPoint::eReserveReason reserveReason)
{
  UFG::TargetingSystemPedBaseComponent *v5; // rax
  UFG::TransformNodeComponent *v6; // rsi
  UFG::TargetingSystemPedBaseComponent *v7; // rdi
  UFG::InterestPointUserComponent *m_pComponent; // r15
  UFG::SimObjectCharacterPropertiesComponent *pCharacterPropertiesComponent; // r12
  UFG::ActiveAIEntityComponent *pAAEC; // r13
  UFG::TargetingMap *m_pTargetingMap; // rax
  __int64 v12; // rcx
  UFG::TargetingSimObject *m_pTargets; // rax
  __int64 v14; // rcx
  bool v15; // r14
  UFG::SimObjectCharacter *LocalPlayer; // rax
  UFG::TransformNodeComponent *v17; // rsi
  float y; // xmm1_4
  float z; // xmm0_4
  UFG::SpawnPoint *pCharacterSpawnPoint; // rax
  bool IsRelevantToCharacter; // bl
  __int64 v22; // r9
  UFG::qMatrix44 *characterTransform; // [rsp+80h] [rbp-58h]
  UFG::SimObject *pSimObject; // [rsp+88h] [rbp-50h]
  UFG::qVector3 vPlayerPosition; // [rsp+90h] [rbp-48h] BYREF
  float appealScale; // [rsp+E0h] [rbp+8h] BYREF
  UFG::qVector3 *poiWorldPos; // [rsp+F8h] [rbp+20h]

  if ( this->mpPedInfoUser )
  {
    LOBYTE(v5) = 0;
  }
  else
  {
    poiWorldPos = UFG::InterestPoint::GetPosition(this);
    if ( _pCharacter && (v6 = (UFG::TransformNodeComponent *)_pCharacter->m_Components.p[2].m_pComponent) != 0i64 )
    {
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedBaseComponent>(_pCharacter);
      v7 = v5;
      if ( v5 )
      {
        m_pComponent = (UFG::InterestPointUserComponent *)_pCharacter->m_Components.p[43].m_pComponent;
        if ( m_pComponent )
        {
          v5 = (UFG::TargetingSystemPedBaseComponent *)UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(_pCharacter);
          pCharacterPropertiesComponent = (UFG::SimObjectCharacterPropertiesComponent *)v5;
          if ( v5 )
          {
            v5 = (UFG::TargetingSystemPedBaseComponent *)UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(_pCharacter);
            pAAEC = (UFG::ActiveAIEntityComponent *)v5;
            if ( v5 )
            {
              UFG::TransformNodeComponent::UpdateWorldTransform(v6);
              characterTransform = &v6->mWorldTransform;
              m_pTargetingMap = v7->m_pTargetingMap;
              LODWORD(appealScale) = (_DWORD)FLOAT_1_0;
              v12 = (unsigned __int8)m_pTargetingMap->m_Map.p[26];
              m_pTargets = v7->m_pTargets;
              v14 = v12;
              pSimObject = m_pTargets[v14].m_pTarget.m_pPointer;
              v15 = pSimObject && m_pTargets[v14].m_bLock;
              LocalPlayer = UFG::GetLocalPlayer();
              if ( LocalPlayer )
                v17 = (UFG::TransformNodeComponent *)LocalPlayer->m_Components.p[2].m_pComponent;
              else
                v17 = 0i64;
              UFG::TransformNodeComponent::UpdateWorldTransform(v17);
              y = v17->mWorldTransform.v3.y;
              vPlayerPosition.x = v17->mWorldTransform.v3.x;
              z = v17->mWorldTransform.v3.z;
              vPlayerPosition.y = y;
              vPlayerPosition.z = z;
              pCharacterSpawnPoint = UFG::GetOriginatingSpawnPoint(_pCharacter);
              IsRelevantToCharacter = UFG::InterestPoint::IsRelevantToCharacter(
                                        this,
                                        _pCharacter,
                                        v7,
                                        m_pComponent,
                                        pCharacterPropertiesComponent,
                                        pAAEC,
                                        &vPlayerPosition,
                                        pCharacterSpawnPoint,
                                        characterTransform,
                                        poiWorldPos,
                                        &appealScale,
                                        &qSymbol_use,
                                        8u,
                                        ReserveReason_resume,
                                        0);
              UFG::TargetingSystemBaseComponent::SetTarget(v7, 0x1Au, pSimObject);
              LOBYTE(v22) = 1;
              ((void (__fastcall *)(UFG::TargetingSystemPedBaseComponent *, __int64, bool, __int64, _DWORD, const char *, _QWORD, _QWORD))v7->UFG::TargetingSystemBaseComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[14].__vecDelDtor)(
                v7,
                26i64,
                v15,
                v22,
                0,
                "InterestPoint::IsRelevantToCharacter",
                0i64,
                0i64);
              LOBYTE(v5) = IsRelevantToCharacter;
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
  if ( this->mCanPathToCached.mValue != 3 )
    return (unsigned __int8)this->mCanPathToCached.mValue;
  UFG::InterestPoint::UpdateCanPathToCached(this);
  return (unsigned __int8)this->mCanPathToCached.mValue;
}

// File Line: 2554
// RVA: 0x584250
bool __fastcall UFG::InterestPoint::IsRelevantToCharacter(
        UFG::InterestPoint *this,
        UFG::SimObjectCharacter *pCharacter,
        UFG::TargetingSystemPedBaseComponent *pCharacterTargetComp,
        UFG::InterestPointUserComponent *pInterestPointUserComp,
        UFG::SimObjectCharacterPropertiesComponent *pCharacterPropertiesComponent,
        UFG::ActiveAIEntityComponent *pAAEC,
        UFG::qVector3 *vPlayerPosition,
        UFG::SpawnPoint *pCharacterSpawnPoint,
        UFG::qMatrix44 *characterTransform,
        UFG::qVector3 *poiWorldPos,
        float *appealScale,
        UFG::qSymbol *type,
        unsigned int matchReservationFlags,
        UFG::InterestPoint::eReserveReason reserveReason,
        bool bSkipChecksInPlayerRel)
{
  UFG::SimObject *m_pPointer; // rax
  UFG::SimObject *v20; // rcx
  UFG::SimObject *v21; // rcx
  ActionContext *v22; // r15
  UFG::GroupComponent *v23; // r14
  UFG::InterestPointProperties *mProperties; // rax
  int mMinGroupSize; // ebp
  int mMaxGroupSize; // ebx
  int GroupSize; // eax
  UFG::InterestPointProperties *v28; // rcx
  unsigned int mUID; // edx
  UFG::qStaticSymbol *v30; // rax
  unsigned int v31; // eax
  float v32; // xmm0_4
  float m_SecondsSinceMidnight; // xmm0_4
  UFG::InterestPointProperties *v34; // rax
  float v35; // xmm0_4
  bool IsAnyLocalPlayer; // r12
  unsigned int v37; // ecx
  float mMaxDistanceFromPlayer; // xmm2_4
  __m128 y_low; // xmm1
  UFG::qVector3 *Position; // rax
  __m128 v41; // xmm0
  float v42; // xmm10_4
  float v43; // xmm1_4
  float v44; // xmm14_4
  bool v45; // bl
  UFG::InterestPointProperties *v46; // rbx
  UFG::SimObject *m_pSimObject; // rax
  UFG::SceneObjectProperties *v48; // rcx
  UFG::SceneObjectProperties *mpParent; // rcx
  UFG::SimObject *v50; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rbx
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *Leader; // rbp
  UFG::SimObjectGame *mNext; // rcx
  UFG::ActiveAIEntityComponent *v55; // rbp
  signed __int16 v56; // cx
  UFG::ActiveAIEntityComponent *ComponentOfTypeHK; // rax
  float DefaultLoad; // xmm0_4
  unsigned int v59; // edx
  UFG::qVector3 *v60; // rax
  UFG::qMatrix44 *v61; // r12
  UFG::SidewalkWanderData *p_m_WanderData; // rbp
  UFG::TargetingSystemPedBaseComponent *v63; // rbx
  UFG::SimObject *v64; // rcx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  float x; // xmm7_4
  __m128 v67; // xmm6
  float z; // xmm8_4
  float *v69; // r14
  float *v70; // rbx
  bool *v71; // rax
  bool v72; // al
  float v73; // xmm1_4
  float v74; // xmm2_4
  char *v75; // rax
  float v76; // xmm1_4
  float y; // xmm0_4
  float v78; // xmm3_4
  float v79; // xmm1_4
  float v80; // xmm2_4
  signed __int16 v81; // cx
  UFG::SimComponent *v82; // rbx
  signed __int16 v83; // cx
  UFG::SimComponent *ComponentOfType; // rax
  ActionNodeRoot *v85; // rax
  ActionNodeRoot *v86; // rax
  ActionNode *mBehaviourConditions; // rcx
  UFG::qVector3 v2; // [rsp+20h] [rbp-B8h] BYREF
  UFG::qVector3 v1; // [rsp+30h] [rbp-A8h] BYREF
  char v90; // [rsp+E0h] [rbp+8h]

  UFG::qGetTicks();
  if ( this->mpPedInfoUser )
    return 0;
  if ( type->mUID == qSymbol_use.mUID )
  {
    if ( this->mPoiType.mUID != qSymbol_look.mUID )
      goto LABEL_7;
    return 0;
  }
  if ( type->mUID != this->mPoiType.mUID )
    return 0;
LABEL_7:
  if ( !this->mPassedActivationChance )
    return 0;
  if ( !bSkipChecksInPlayerRel && !this->mActive )
    return 0;
  m_pPointer = this->mLinkObject.m_pPointer;
  if ( m_pPointer )
  {
    v20 = pInterestPointUserComp->mInterestPointLink.mLinkObject.m_pPointer;
    if ( !v20 || v20 != m_pPointer )
      return 0;
  }
  v21 = pInterestPointUserComp->mInterestPointLink.mLinkObject.m_pPointer;
  v90 = 0;
  if ( v21 )
  {
    if ( pInterestPointUserComp->mInterestPointLink.mIsExclusive )
    {
      v90 = 1;
      if ( v21 != m_pPointer )
        return 0;
    }
  }
  if ( !UFG::InterestPoint::IsReservationMatch(this, matchReservationFlags, reserveReason)
    && this->mpUser.m_pPointer != pCharacter )
  {
    return 0;
  }
  v22 = 0i64;
  v23 = 0i64;
  if ( pAAEC )
    v23 = pAAEC->m_pGroupComponent.m_pPointer;
  mProperties = this->mPropertiesHandle.mProperties;
  mMinGroupSize = mProperties->mMinGroupSize;
  mMaxGroupSize = mProperties->mMaxGroupSize;
  if ( mMinGroupSize >= 0 || mMaxGroupSize >= 0 )
  {
    GroupSize = UFG::GroupComponent::GetGroupSize(v23);
    if ( mMinGroupSize >= 0 && GroupSize < mMinGroupSize )
      return 0;
    if ( mMaxGroupSize >= 0 && GroupSize > mMaxGroupSize )
      return 0;
  }
  if ( !bSkipChecksInPlayerRel )
  {
    v28 = this->mPropertiesHandle.mProperties;
    mUID = v28->mGendersAllowed.mUID;
    if ( mUID != qSymbol_Any.mUID )
    {
      v30 = &qSymbol_Female;
      if ( pCharacterPropertiesComponent->m_eGender == eGENDER_MALE )
        v30 = &qSymbol_Male;
      v31 = v30->mUID;
      if ( v31 == -1 || mUID != v31 )
        return 0;
    }
    v32 = v28->mTimeOfDayToBecomeActive - v28->mTimeOfDayToBecomeInactive;
    if ( v32 < 0.0 )
      LODWORD(v32) ^= _xmm[0];
    if ( v32 >= 0.001 )
    {
      m_SecondsSinceMidnight = UFG::TimeOfDayManager::GetInstance()->m_SecondsSinceMidnight;
      v34 = this->mPropertiesHandle.mProperties;
      v35 = m_SecondsSinceMidnight * 0.00027777778;
      if ( v35 > v34->mTimeOfDayToBecomeActive && v35 < v34->mTimeOfDayToBecomeInactive )
        return 0;
    }
  }
  if ( this->mPoiType.mUID != qSymbol_look.mUID
    && reserveReason == ReserveReason_normal
    && !v90
    && !this->mPropertiesHandle.mProperties->mIgnoreCharacterCooldown
    && pCharacterPropertiesComponent
    && pCharacterPropertiesComponent->m_CharacterStats[2].m_fStat > 0.0 )
  {
    return 0;
  }
  IsAnyLocalPlayer = UFG::IsAnyLocalPlayer(pCharacter);
  if ( !IsAnyLocalPlayer )
  {
    if ( v23 )
    {
      v37 = qSymbol_look.mUID;
      if ( this->mPoiType.mUID != qSymbol_look.mUID )
      {
        if ( !this->mPropertiesHandle.mProperties->mAllowFollowers )
        {
          if ( UFG::GroupComponent::IsFollower(v23) )
            return 0;
          v37 = qSymbol_look.mUID;
        }
        if ( this->mPoiType.mUID != v37
          && !this->mPropertiesHandle.mProperties->mAllowLeaders
          && UFG::GroupComponent::IsLeader(v23) )
        {
          return 0;
        }
      }
    }
  }
  if ( !bSkipChecksInPlayerRel )
  {
    mMaxDistanceFromPlayer = this->mPropertiesHandle.mProperties->mMaxDistanceFromPlayer;
    if ( mMaxDistanceFromPlayer >= 0.0 )
    {
      y_low = (__m128)LODWORD(characterTransform->v3.y);
      y_low.m128_f32[0] = (float)((float)(y_low.m128_f32[0] - vPlayerPosition->y)
                                * (float)(y_low.m128_f32[0] - vPlayerPosition->y))
                        + (float)((float)(characterTransform->v3.x - vPlayerPosition->x)
                                * (float)(characterTransform->v3.x - vPlayerPosition->x));
      if ( _mm_sqrt_ps(y_low).m128_f32[0] > mMaxDistanceFromPlayer )
        return 0;
    }
  }
  Position = UFG::InterestPoint::GetPosition(this);
  v41 = (__m128)LODWORD(characterTransform->v3.y);
  LODWORD(v42) = COERCE_UNSIGNED_INT(characterTransform->v3.z - Position->z) & _xmm;
  v43 = (float)(characterTransform->v3.x - Position->x) * (float)(characterTransform->v3.x - Position->x);
  v41.m128_f32[0] = (float)((float)(v41.m128_f32[0] - Position->y) * (float)(v41.m128_f32[0] - Position->y)) + v43;
  v44 = _mm_sqrt_ps(v41).m128_f32[0];
  v45 = v44 <= 0.5 && v42 <= 1.5;
  if ( this->mPropertiesHandle.mProperties->mInitialUseOnly && (!UFG::IsSpawning(pCharacter) || !v45) )
    return 0;
  if ( !bSkipChecksInPlayerRel )
  {
    v46 = this->mPropertiesHandle.mProperties;
    if ( v46->mWeatherFilterOn
      && v46->mWeatherFilterIsRaining != UFG::TimeOfDayManager::GetInstance()->m_WeatherState > 1.0 )
    {
      return 0;
    }
  }
  if ( !IsAnyLocalPlayer
    && v23
    && this->mPoiType.mUID != qSymbol_look.mUID
    && this->mPropertiesHandle.mProperties->mAllowFollowers )
  {
    m_pSimObject = this->m_pSimObject;
    v48 = m_pSimObject ? m_pSimObject->m_pSceneObj : 0i64;
    mpParent = v48->mpParent;
    if ( mpParent )
    {
      v50 = mpParent->m_pSimObject;
      if ( v50 )
      {
        m_Flags = v50->m_Flags;
        if ( (m_Flags & 0x4000) != 0 )
        {
          m_pComponent = v50->m_Components.p[25].m_pComponent;
        }
        else if ( m_Flags >= 0 )
        {
          if ( (m_Flags & 0x2000) != 0 )
            m_pComponent = v50->m_Components.p[10].m_pComponent;
          else
            m_pComponent = (m_Flags & 0x1000) != 0
                         ? v50->m_Components.p[3].m_pComponent
                         : UFG::SimObject::GetComponentOfType(v50, UFG::InterestPoint::_TypeUID);
        }
        else
        {
          m_pComponent = v50->m_Components.p[25].m_pComponent;
        }
        if ( m_pComponent )
        {
          Leader = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)UFG::GroupComponent::GetLeader(v23);
          if ( Leader )
          {
            mNext = (UFG::SimObjectGame *)m_pComponent[5].m_BoundComponentHandles.mNode.mNext;
            if ( !mNext || UFG::GroupComponent::GetGroupComponent(mNext) != Leader )
              return 0;
          }
        }
      }
    }
  }
  if ( pCharacter )
  {
    v56 = pCharacter->m_Flags;
    if ( (v56 & 0x4000) != 0 || v56 < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(pCharacter);
    }
    else if ( (v56 & 0x2000) != 0 || (v56 & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            pCharacter,
                                                            UFG::ActiveAIEntityComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                            pCharacter,
                                                            UFG::ActiveAIEntityComponent::_TypeUID);
    }
    v55 = ComponentOfTypeHK;
    if ( ComponentOfTypeHK )
    {
      if ( this->mpXformNode )
      {
        UFG::InterestPoint::GetPosition(this);
        DefaultLoad = UFG::Drifting_EngineState::GetDefaultLoad((PoseNode *)v55, v43);
        if ( UFG::Drifting_EngineState::GetDefaultLoad((PoseNode *)v55, v43) > DefaultLoad )
          return 0;
      }
    }
  }
  else
  {
    v55 = 0i64;
  }
  if ( !this->mPropertiesHandle.mProperties->mAllowRepeatedUse )
  {
    v59 = this->mPoiType.mUID;
    if ( v59 != qSymbol_look.mUID
      && reserveReason == ReserveReason_normal
      && !v90
      && !IsAnyLocalPlayer
      && pInterestPointUserComp->mLastUsedPOIType.mUID == v59
      && pInterestPointUserComp->mLastUsedPOIDesc.mUID == this->mInterestPointType->mDescription.mUID
      && v59 != -1 )
    {
      return 0;
    }
  }
  if ( v55->m_bCanWander && this->mpXformNode )
  {
    v60 = UFG::InterestPoint::GetPosition(this);
    v61 = characterTransform;
    p_m_WanderData = &v55->m_WanderData;
    if ( p_m_WanderData
      && p_m_WanderData->mPreviousDesiredDirectionValid
      && (float)((float)((float)(p_m_WanderData->mPreviousDesiredDirection.y * (float)(v60->y - characterTransform->v3.y))
                       + (float)(p_m_WanderData->mPreviousDesiredDirection.x * (float)(v60->x - characterTransform->v3.x)))
               + (float)(p_m_WanderData->mPreviousDesiredDirection.z * (float)(v60->z - characterTransform->v3.z))) < 0.0 )
    {
      return 0;
    }
  }
  else
  {
    v61 = characterTransform;
  }
  v63 = pCharacterTargetComp;
  if ( !UFG::InterestPoint::PassesItemFilter(this, pCharacter, pCharacterTargetComp) )
    return 0;
  if ( pCharacterSpawnPoint )
  {
    v64 = pCharacterSpawnPoint->m_pSimObject;
    if ( v64 )
    {
      m_pTransformNodeComponent = v64->m_pTransformNodeComponent;
      if ( m_pTransformNodeComponent )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform(v64->m_pTransformNodeComponent);
        x = m_pTransformNodeComponent->mWorldTransform.v3.x;
        v67 = (__m128)LODWORD(m_pTransformNodeComponent->mWorldTransform.v3.y);
        z = m_pTransformNodeComponent->mWorldTransform.v3.z;
        v69 = PropertyUtils::Get<float>(
                pCharacter->m_pSceneObj,
                (UFG::qArray<unsigned long,0> *)&qSymbol_TetherAttenuation);
        v70 = PropertyUtils::Get<float>(
                pCharacter->m_pSceneObj,
                (UFG::qArray<unsigned long,0> *)&qSymbol_TetherDistance);
        v71 = PropertyUtils::Get<bool>(
                pCharacter->m_pSceneObj,
                (UFG::qArray<unsigned long,0> *)&qSymbol_TetherDistanceIsHardLimit);
        if ( v69 && v70 && v71 )
        {
          v72 = *v71;
          v73 = *v70;
          v74 = *v69;
          if ( v72 || v74 > 0.0 )
          {
            v67.m128_f32[0] = (float)((float)((float)(v67.m128_f32[0] - poiWorldPos->y)
                                            * (float)(v67.m128_f32[0] - poiWorldPos->y))
                                    + (float)((float)(x - poiWorldPos->x) * (float)(x - poiWorldPos->x)))
                            + (float)((float)(z - poiWorldPos->z) * (float)(z - poiWorldPos->z));
            if ( v67.m128_f32[0] > (float)(v73 * v73) )
            {
              if ( v72 )
              {
                *appealScale = 0.0;
                return 0;
              }
              *appealScale = UFG::InterestPoint::GetDistanceAttenuation(_mm_sqrt_ps(v67).m128_f32[0], v73, v74);
            }
          }
          if ( *appealScale <= 0.0 )
            return 0;
        }
        else
        {
          v75 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&pCharacter->m_Name);
          UFG::qPrintf("Character %s has no tether settings\n", v75);
        }
      }
      v63 = pCharacterTargetComp;
    }
  }
  if ( this->mPoiType.mUID != qSymbol_look.mUID && reserveReason == ReserveReason_normal && !v90 )
  {
    v76 = poiWorldPos->x;
    y = poiWorldPos->y;
    v78 = v61->v0.x;
    v2.z = 0.0;
    v1.z = 0.0;
    v79 = v76 - v61->v3.x;
    v80 = v61->v0.y;
    v2.y = y - v61->v3.y;
    v2.x = v79;
    v1.x = v78;
    v1.y = v80;
    if ( (float)((float)(v2.y * v2.y) + (float)(v79 * v79)) > 1.0
      && (float)((float)(v80 * v80) + (float)(v78 * v78)) > 0.001
      && COERCE_FLOAT(COERCE_UNSIGNED_INT(UFG::qAngleBetween(&v1, &v2)) & _xmm) > (float)(this->mPropertiesHandle.mProperties->mUserRelativeAngleRange
                                                                                        * 0.5) )
    {
      return 0;
    }
  }
  if ( !bSkipChecksInPlayerRel && this->mPropertiesHandle.mProperties->mUseClassList.size )
  {
    if ( pCharacter )
    {
      v81 = pCharacter->m_Flags;
      if ( (v81 & 0x4000) == 0 && v81 >= 0 && (v81 & 0x2000) == 0 )
      {
        if ( (v81 & 0x1000) != 0 )
          UFG::SimObjectGame::GetComponentOfTypeHK(pCharacter, UFG::SimObjectPropertiesComponent::_TypeUID);
        else
          UFG::SimObject::GetComponentOfType(pCharacter, UFG::SimObjectPropertiesComponent::_TypeUID);
      }
    }
    if ( UFG::SimObjectUtility::IsClassTypeInArray(pCharacter, &this->mPropertiesHandle.mProperties->mUseClassList) != this->mPropertiesHandle.mProperties->mClassListIsAllowed )
      return 0;
  }
  if ( this->mInterestPointType->mBehaviour )
  {
    if ( v63 )
    {
      UFG::TargetingSystemBaseComponent::ClearTarget(
        v63,
        (UFG::eTargetTypeEnum)((type->mUID != qSymbol_look.mUID) + 25));
      UFG::TargetingSystemBaseComponent::SetTarget(v63, (type->mUID != qSymbol_look.mUID) + 25, this->m_pSimObject);
    }
    if ( pCharacter )
    {
      v83 = pCharacter->m_Flags;
      if ( (v83 & 0x4000) != 0 )
      {
        v82 = pCharacter->m_Components.p[7].m_pComponent;
      }
      else if ( v83 >= 0 )
      {
        if ( (v83 & 0x2000) != 0 )
        {
          v82 = pCharacter->m_Components.p[6].m_pComponent;
        }
        else
        {
          if ( (v83 & 0x1000) != 0 )
            ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(pCharacter, UFG::ActionTreeComponent::_TypeUID);
          else
            ComponentOfType = UFG::SimObject::GetComponentOfType(pCharacter, UFG::ActionTreeComponent::_TypeUID);
          v82 = ComponentOfType;
        }
      }
      else
      {
        v82 = pCharacter->m_Components.p[7].m_pComponent;
      }
      if ( !v82 )
      {
LABEL_171:
        if ( v22 )
        {
          mBehaviourConditions = this->mInterestPointType->mBehaviourConditions;
          if ( !mBehaviourConditions
            || ((__int64 (__fastcall *)(ActionNode *, ActionContext *))mBehaviourConditions->vfptr[2].GetClassNameUID)(
                 mBehaviourConditions,
                 v22) )
          {
            return this->mPoiType.mUID == qSymbol_look.mUID
                || UFG::IsAnyLocalPlayer(pCharacter)
                || v44 <= 1.0 && v42 <= 2.0
                || (unsigned int)UFG::InterestPoint::GetCanPathToCached(this) == 1;
          }
        }
        return 0;
      }
      v22 = (ActionContext *)v82[2].m_BoundComponentHandles.mNode.mNext;
    }
    else
    {
      v82 = 0i64;
    }
    if ( v82 )
    {
      v85 = (ActionNodeRoot *)this->mInterestPointType->mBehaviour->vfptr[1].GetResourceOwner(this->mInterestPointType->mBehaviour);
      if ( UFG::ActionTreeComponentBase::AllocateFor((UFG::ActionTreeComponentBase *)&v82[1], v85) )
      {
        v86 = (ActionNodeRoot *)this->mInterestPointType->mBehaviour->vfptr[1].GetResourceOwner(this->mInterestPointType->mBehaviour);
        ActionNodeRoot::Init(v86, v22);
      }
    }
    goto LABEL_171;
  }
  return this->mPoiType.mUID == qSymbol_look.mUID
      || UFG::IsAnyLocalPlayer(pCharacter)
      || v44 <= 1.0 && v42 <= 2.0
      || (unsigned int)UFG::InterestPoint::GetCanPathToCached(this) == 1;
}

// File Line: 3727
// RVA: 0x588390
bool __fastcall UFG::InterestPoint::PassesItemFilter(
        UFG::InterestPoint *this,
        UFG::SimObjectCharacter *pCharacter,
        UFG::TargetingSystemPedBaseComponent *pCharacterTargetComp)
{
  char v5; // di
  int v6; // r15d
  unsigned int v7; // esi
  int *v8; // rbp
  UFG::SimObjectProp *m_pPointer; // rbx
  __int16 m_Flags; // cx
  UFG::SimObjectWeaponPropertiesComponent *ComponentOfType; // rax
  __int16 v12; // cx
  UFG::SimComponent *m_pComponent; // rax
  int m_pSimObject; // edx
  UFG::InterestPointType *mInterestPointType; // rax
  unsigned int v16; // ecx
  unsigned int size; // r8d
  UFG::eInventoryItemEnum *p; // rax
  int v20; // [rsp+58h] [rbp+10h] BYREF
  int v21; // [rsp+5Ch] [rbp+14h]

  if ( !pCharacter || !pCharacterTargetComp )
    return 0;
  if ( !this->mPropertiesHandle.mProperties->mItemFilterOn
    || UFG::IsAnyLocalPlayer(pCharacter) && !this->mPropertiesHandle.mProperties->mItemFilterAppliesToPlayer )
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
    m_pPointer = (UFG::SimObjectProp *)pCharacterTargetComp->m_pTargets[(unsigned __int8)pCharacterTargetComp->m_pTargetingMap->m_Map.p[*v8]].m_pTarget.m_pPointer;
    if ( m_pPointer )
    {
      ++v6;
      if ( !this->mInterestPointType->mItemListMatchesWeapons )
        goto LABEL_19;
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) == 0 && m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 )
        {
          ComponentOfType = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(m_pPointer);
LABEL_18:
          if ( ComponentOfType )
          {
            v5 = 1;
            break;
          }
LABEL_19:
          v12 = m_pPointer->m_Flags;
          if ( (v12 & 0x4000) == 0 && v12 >= 0 )
          {
            if ( (v12 & 0x2000) != 0 )
              m_pComponent = m_pPointer->m_Components.p[11].m_pComponent;
            else
              m_pComponent = (v12 & 0x1000) != 0
                           ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::InventoryItemComponent::_TypeUID)
                           : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::InventoryItemComponent::_TypeUID);
            if ( m_pComponent )
            {
              m_pSimObject = (int)m_pComponent[1].m_pSimObject;
              if ( m_pSimObject )
              {
                mInterestPointType = this->mInterestPointType;
                v16 = 0;
                size = mInterestPointType->mUseItemList.size;
                if ( size )
                {
                  p = mInterestPointType->mUseItemList.p;
                  while ( m_pSimObject != *p )
                  {
                    ++v16;
                    ++p;
                    if ( v16 >= size )
                      goto LABEL_34;
                  }
                  v5 = 1;
                }
              }
            }
          }
          goto LABEL_34;
        }
        if ( (m_Flags & 0x1000) == 0 )
        {
          ComponentOfType = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                         m_pPointer,
                                                                         UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
          goto LABEL_18;
        }
      }
      ComponentOfType = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                     m_pPointer,
                                                                     UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
      goto LABEL_18;
    }
LABEL_34:
    ++v7;
    ++v8;
    if ( v7 >= 2 )
      break;
  }
  if ( this->mInterestPointType->mItemListMatchesNoItem && !v6 )
    v5 = 1;
  return v5 == this->mPropertiesHandle.mProperties->mItemListIsAllowed;
}

// File Line: 3810
// RVA: 0x585000
bool __fastcall UFG::InterestPoint::IsRelevantToPlayer(
        UFG::InterestPoint *this,
        UFG::SimObjectCVBase *pCharacter,
        UFG::qVector3 *characterPosition)
{
  float v7; // xmm0_4
  float m_SecondsSinceMidnight; // xmm0_4
  UFG::InterestPointProperties *mProperties; // rax
  float v10; // xmm0_4
  UFG::SimObjectCharacterPropertiesComponent *v11; // rcx
  signed __int16 m_Flags; // cx
  UFG::SimObjectCharacterPropertiesComponent *ComponentOfTypeHK; // rax
  UFG::InterestPointProperties *v14; // rsi
  unsigned int mUID; // edx
  UFG::qStaticSymbol *v16; // rax
  char IsClassTypeInArray; // al
  UFG::SimObjectCharacter *LocalPlayer; // rax
  UFG::SimComponentHolder *p; // rax
  UFG::TransformNodeComponent *m_pComponent; // rdi
  __m128 y_low; // xmm7
  float v22; // xmm6_4

  if ( !this->mInterestPointType->mBehaviour || this->mpPedInfoUser || !this->mActive )
    return 0;
  v7 = this->mPropertiesHandle.mProperties->mTimeOfDayToBecomeActive
     - this->mPropertiesHandle.mProperties->mTimeOfDayToBecomeInactive;
  if ( v7 < 0.0 )
    LODWORD(v7) ^= _xmm[0];
  if ( v7 >= 0.001 )
  {
    m_SecondsSinceMidnight = UFG::TimeOfDayManager::GetInstance()->m_SecondsSinceMidnight;
    mProperties = this->mPropertiesHandle.mProperties;
    v10 = m_SecondsSinceMidnight * 0.00027777778;
    if ( v10 > mProperties->mTimeOfDayToBecomeActive && v10 < mProperties->mTimeOfDayToBecomeInactive )
      return 0;
  }
  if ( pCharacter )
  {
    m_Flags = pCharacter->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(pCharacter);
    }
    else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                          pCharacter,
                                                                          UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                          pCharacter,
                                                                          UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
    }
    v11 = ComponentOfTypeHK;
  }
  else
  {
    v11 = 0i64;
  }
  v14 = this->mPropertiesHandle.mProperties;
  mUID = v14->mGendersAllowed.mUID;
  if ( mUID != qSymbol_Any.mUID )
  {
    v16 = &qSymbol_Female;
    if ( v11->m_eGender == eGENDER_MALE )
      v16 = &qSymbol_Male;
    if ( mUID != v16->mUID )
      return 0;
  }
  if ( v14->mUseClassList.size )
  {
    IsClassTypeInArray = UFG::SimObjectUtility::IsClassTypeInArray(pCharacter, &v14->mUseClassList);
    v14 = this->mPropertiesHandle.mProperties;
    if ( IsClassTypeInArray != v14->mClassListIsAllowed )
      return 0;
  }
  if ( v14->mWeatherFilterOn
    && v14->mWeatherFilterIsRaining != UFG::TimeOfDayManager::GetInstance()->m_WeatherState > 1.0 )
  {
    return 0;
  }
  if ( this->mPropertiesHandle.mProperties->mMaxDistanceFromPlayer < 0.0 )
    return 1;
  LocalPlayer = UFG::GetLocalPlayer();
  if ( !LocalPlayer )
    return 1;
  p = LocalPlayer->m_Components.p;
  m_pComponent = (UFG::TransformNodeComponent *)p[2].m_pComponent;
  if ( !m_pComponent )
    return 1;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)p[2].m_pComponent);
  y_low = (__m128)LODWORD(characterPosition->y);
  v22 = characterPosition->x - m_pComponent->mWorldTransform.v3.x;
  y_low.m128_f32[0] = y_low.m128_f32[0] - m_pComponent->mWorldTransform.v3.y;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pComponent);
  y_low.m128_f32[0] = (float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v22 * v22);
  return _mm_sqrt_ps(y_low).m128_f32[0] <= this->mPropertiesHandle.mProperties->mMaxDistanceFromPlayer;
}n _mm_sqrt_ps(y_low).m128_f32[0] <= this->mPropertiesHandle.mPrope

// File Line: 4047
// RVA: 0x581740
UFG::InterestPoint *__fastcall UFG::InterestPoint::FindNearestRelevent(
        UFG::SimObjectCharacter *pCharacter,
        bool bIsPlayer,
        UFG::InterestPointUserComponent *pInterestPointUserComp,
        UFG::TargetingSystemPedBaseComponent *pCharacterTargetComp,
        UFG::ActiveAIEntityComponent *pAAEC,
        UFG::qMatrix44 *characterTransform,
        UFG::qVector3 *vPlayerPosition,
        UFG::qSymbol *type,
        unsigned int matchReservationFlags,
        float maxDistSquared,
        float *pDistSquared,
        UFG::qArray<UFG::InterestPointQuery::Candidate,0> *pCandidates,
        UFG::qFixedArray<UFG::InterestPoint *,4> *apNearestPOIWithBehaviour)
{
  UFG::TargetingSystemPedBaseComponent *v13; // r13
  __int64 v18; // r12
  float v19; // xmm8_4
  float v20; // xmm9_4
  unsigned int v21; // r15d
  unsigned int mUID; // eax
  __int64 v23; // r8
  UFG::TargetingSimObject *m_pTargets; // rcx
  float v25; // xmm4_4
  UFG::GridIntrusive<UFG::InterestPoint> *v26; // r14
  float y; // xmm3_4
  float mGridSizeInv; // xmm5_4
  int v29; // ebx
  int v30; // edi
  __int64 mXDim; // r10
  int v32; // r9d
  int v33; // r8d
  int mYDim; // ecx
  unsigned int v35; // edx
  __int64 v36; // r11
  __int64 v37; // rbp
  __int64 v38; // rsi
  __int64 v39; // r9
  __int64 v40; // r8
  __int64 v41; // r10
  __int64 *v42; // rax
  __int64 v43; // rcx
  __int64 v44; // rax
  __int64 v45; // r13
  UFG::InterestPoint *v46; // rsi
  __int64 p_mNext; // rbp
  UFG::qVector3 *poiWorldPos; // rbx
  int v49; // xmm7_4
  bool bSkipChecksInPlayerRel; // r11
  __int64 size; // rdx
  __int64 v52; // rax
  unsigned int v53; // r9d
  __int64 v54; // rdx
  int *v55; // r8
  __int64 v56; // rdx
  UFG::InterestPoint **v57; // r8
  float v58; // xmm0_4
  float *mProperties; // rax
  float v60; // xmm6_4
  float v61; // xmm6_4
  __int64 v62; // rdi
  unsigned int v63; // ebx
  unsigned int capacity; // edx
  unsigned int v65; // edx
  float v66; // xmm0_4
  __int64 v67; // r9
  unsigned __int8 v68; // [rsp+80h] [rbp-1F8h]
  float appealScale; // [rsp+84h] [rbp-1F4h] BYREF
  unsigned int v70; // [rsp+88h] [rbp-1F0h]
  float v71[5]; // [rsp+8Ch] [rbp-1ECh] BYREF
  UFG::InterestPoint *v72; // [rsp+A0h] [rbp-1D8h]
  __int64 v73; // [rsp+A8h] [rbp-1D0h]
  UFG::SimObject *pSimObject; // [rsp+B0h] [rbp-1C8h]
  __int64 *v75; // [rsp+B8h] [rbp-1C0h]
  UFG::SpawnPoint *pCharacterSpawnPoint; // [rsp+C0h] [rbp-1B8h]
  UFG::SimObjectCharacterPropertiesComponent *pCharacterPropertiesComponent; // [rsp+C8h] [rbp-1B0h]
  __int64 v78; // [rsp+D0h] [rbp-1A8h]
  __int64 v79[25]; // [rsp+E0h] [rbp-198h] BYREF
  int v80; // [rsp+1A8h] [rbp-D0h]

  v78 = -2i64;
  v13 = pCharacterTargetComp;
  if ( !pCharacter )
    return 0i64;
  if ( !pCharacter->m_pSceneObj )
    return 0i64;
  pCharacterPropertiesComponent = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(pCharacter);
  if ( !pCharacterPropertiesComponent )
    return 0i64;
  if ( bIsPlayer )
    pCharacterSpawnPoint = 0i64;
  else
    pCharacterSpawnPoint = UFG::GetOriginatingSpawnPoint(pCharacter);
  v18 = 0i64;
  v72 = 0i64;
  v19 = 0.0;
  v20 = maxDistSquared;
  v21 = 0;
  v70 = 0;
  pSimObject = 0i64;
  v68 = 0;
  mUID = qSymbol_look.mUID;
  if ( pInterestPointUserComp )
  {
    if ( v13 )
    {
      v23 = (unsigned __int8)v13->m_pTargetingMap->m_Map.p[(type->mUID != qSymbol_look.mUID) + 25];
      m_pTargets = v13->m_pTargets;
      pSimObject = m_pTargets[v23].m_pTarget.m_pPointer;
      if ( !pSimObject || (v68 = 1, !m_pTargets[v23].m_bLock) )
        v68 = 0;
    }
  }
  LODWORD(v25) = _mm_sqrt_ps((__m128)LODWORD(maxDistSquared)).m128_u32[0];
  v26 = UFG::InterestPoint::mspUseInterestPointGrid;
  if ( type->mUID == qSymbol_look.mUID )
    v26 = UFG::InterestPoint::mspLookInterestPointGrid;
  y = characterTransform->v3.y;
  mGridSizeInv = v26->mGridSizeInv;
  v29 = (int)(float)((float)((float)(characterTransform->v3.x - v25) - v26->mXMin) * mGridSizeInv);
  if ( v29 < 0 )
    v29 = 0;
  v30 = (int)(float)((float)((float)(characterTransform->v3.x + v25) - v26->mXMin) * mGridSizeInv);
  mXDim = v26->mXDim;
  if ( v30 >= (int)mXDim )
    v30 = mXDim - 1;
  v32 = (int)(float)((float)((float)(y - v25) - v26->mYMin) * mGridSizeInv);
  if ( v32 < 0 )
    v32 = 0;
  v33 = (int)(float)((float)((float)(y + v25) - v26->mYMin) * mGridSizeInv);
  mYDim = v26->mYDim;
  if ( v33 >= mYDim )
    v33 = mYDim - 1;
  v35 = 0;
  v80 = 0;
  if ( v32 <= v33 )
  {
    v36 = 16i64 * (v29 + v32 * (int)mXDim);
    v37 = 16 * mXDim;
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
            v79[v35] = v39;
            v35 = ++v80;
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
    v42 = v79;
    v75 = v79;
    v43 = v35;
    v73 = v35;
    do
    {
      v44 = *v42;
      v45 = v44 - 184;
      v46 = (UFG::InterestPoint *)(*(_QWORD *)(v44 + 8) - 184i64);
      if ( v46 != (UFG::InterestPoint *)(v44 - 184) )
      {
        do
        {
          p_mNext = (__int64)&v46->UFG::GridIntrusiveNode<UFG::InterestPoint>::UFG::qNode<UFG::InterestPoint,UFG::InterestPoint>::mNext[-12].mNext;
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
              if ( bIsPlayer
                && UFG::InterestPoint::IsRelevantToPlayer(v46, pCharacter, (UFG::qVector3 *)&characterTransform->v3) )
              {
                bSkipChecksInPlayerRel = 1;
                size = apNearestPOIWithBehaviour->size;
                v52 = 0i64;
                v53 = 0;
                while ( 1 )
                {
                  if ( v52 >= size )
                  {
                    v70 = v21 + 1;
                    v71[v21] = *(float *)&v49;
                    apNearestPOIWithBehaviour->size = size + 1;
                    apNearestPOIWithBehaviour->p[size] = v46;
                    v21 = v70;
                    goto LABEL_54;
                  }
                  if ( *(float *)&v49 < v71[v52] )
                    break;
                  ++v53;
                  if ( ++v52 >= 4 )
                    goto LABEL_54;
                }
                if ( (_DWORD)size == 4 )
                {
                  apNearestPOIWithBehaviour->size = 3;
                  v21 = 3;
                  v70 = 3;
                }
                v70 = v21 + 1;
                LODWORD(v54) = v21;
                if ( v21 > v53 )
                {
                  v55 = (int *)&v71[v21];
                  do
                  {
                    v54 = (unsigned int)(v54 - 1);
                    *v55-- = LODWORD(v71[v54]);
                  }
                  while ( (unsigned int)v54 > v53 );
                }
                v71[v53] = *(float *)&v49;
                v56 = apNearestPOIWithBehaviour->size++;
                if ( (unsigned int)v56 > v53 )
                {
                  v57 = &apNearestPOIWithBehaviour->p[v56];
                  do
                  {
                    v56 = (unsigned int)(v56 - 1);
                    *v57-- = apNearestPOIWithBehaviour->p[v56];
                  }
                  while ( (unsigned int)v56 > v53 );
                }
                apNearestPOIWithBehaviour->p[v53] = v46;
                v21 = v70;
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
                if ( !bIsPlayer || bSkipChecksInPlayerRel )
                {
                  if ( UFG::InterestPoint::IsRelevantToCharacter(
                         v46,
                         pCharacter,
                         pCharacterTargetComp,
                         pInterestPointUserComp,
                         pCharacterPropertiesComponent,
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
                    mProperties = (float *)v46->mPropertiesHandle.mProperties;
                    if ( v58 >= mProperties[12] )
                      v60 = (float)((float)(mProperties[11] - v58) / (float)(mProperties[11] - mProperties[12]))
                          * mProperties[10];
                    else
                      v60 = mProperties[10];
                    v61 = v60 * appealScale;
                    if ( pCandidates )
                    {
                      v62 = pCandidates->size;
                      v63 = v62 + 1;
                      capacity = pCandidates->capacity;
                      if ( (int)v62 + 1 > capacity )
                      {
                        if ( capacity )
                          v65 = 2 * capacity;
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
                      v72 = v46;
                      v20 = *(float *)&v49;
                      v19 = v61;
                    }
                  }
                }
              }
            }
          }
          v46 = (UFG::InterestPoint *)p_mNext;
        }
        while ( p_mNext != v45 );
        v43 = v73;
      }
      v42 = ++v75;
      v73 = --v43;
    }
    while ( v43 );
    mUID = qSymbol_look.mUID;
    v18 = (__int64)v72;
    v13 = pCharacterTargetComp;
  }
  if ( pDistSquared )
  {
    *pDistSquared = v20;
    mUID = qSymbol_look.mUID;
  }
  if ( v13 )
  {
    UFG::TargetingSystemBaseComponent::SetTarget(v13, (type->mUID != mUID) + 25, pSimObject);
    LOBYTE(v67) = 1;
    ((void (__fastcall *)(UFG::TargetingSystemPedBaseComponent *, _QWORD, _QWORD, __int64, _DWORD, const char *, _QWORD, _QWORD))v13->UFG::TargetingSystemBaseComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[14].__vecDelDtor)(
      v13,
      (unsigned int)(type->mUID != qSymbol_look.mUID) + 25,
      v68,
      v67,
      0,
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
  unsigned int v2; // edi
  const char *v3; // rdx
  Render::SkinningCacheNode *Head; // rax
  char *p_mUID; // rbx
  __int64 v6; // rax
  __int64 v7; // rcx
  unsigned int v8; // esi
  char *v9; // rax
  UFG::qBaseTreeRB *Next; // rax
  UFG::qBaseTreeRB *i; // rax
  __int64 v12; // rbx
  __int64 v13; // rax
  __int64 v14; // rcx
  unsigned int v15; // esi
  char *v16; // rax

  v2 = childNum;
  if ( childNum < 0 )
    v2 = -childNum;
  v3 = "greater than";
  if ( childNum >= 0 )
    v3 = "exactly";
  ADebug::print_format("InterestPoint objects with %s %u children:\n", v3, v2);
  Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::InterestPoint::msUseInterestPoints);
  if ( Head )
    p_mUID = (char *)&Head[-4].mNode.mUID;
  else
    p_mUID = 0i64;
  while ( p_mUID )
  {
    v6 = *((_QWORD *)p_mUID + 5);
    if ( v6 )
      v7 = *(_QWORD *)(v6 + 80);
    else
      v7 = 0i64;
    v8 = *(_DWORD *)(v7 + 120);
    if ( childNum >= 0 )
    {
      if ( v8 != v2 )
        goto LABEL_17;
LABEL_16:
      v9 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)p_mUID + 16);
      ADebug::print_format("  %s : %u\n", v9, v8);
      goto LABEL_17;
    }
    if ( v8 >= v2 )
      goto LABEL_16;
LABEL_17:
    Next = UFG::qBaseTreeRB::GetNext(&UFG::InterestPoint::msUseInterestPoints.mTree, (UFG::qBaseNodeRB *)(p_mUID + 136));
    if ( Next )
      p_mUID = (char *)Next[-2].mRoot.mChild;
    else
      p_mUID = 0i64;
  }
  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::InterestPoint::msLookInterestPoints);
        ;
        i = UFG::qBaseTreeRB::GetNext(&UFG::InterestPoint::msLookInterestPoints.mTree, (UFG::qBaseNodeRB *)(v12 + 136)) )
  {
    v12 = i ? (__int64)i[-2].mRoot.mChild : 0i64;
    if ( !v12 )
      break;
    v13 = *(_QWORD *)(v12 + 40);
    if ( v13 )
      v14 = *(_QWORD *)(v13 + 80);
    else
      v14 = 0i64;
    v15 = *(_DWORD *)(v14 + 120);
    if ( childNum < 0 )
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
  Render::SkinningCacheNode *Head; // rax
  UFG::InterestPoint *p_mUID; // rbx
  UFG::qVector3 *Position; // rdi
  bool v3; // al
  char v4; // cl
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList> *v5; // rcx
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList> *mPrev; // rax
  UFG::qBaseTreeRB *Next; // rax

  Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::InterestPoint::msUseInterestPoints);
  p_mUID = (UFG::InterestPoint *)&Head[-4].mNode.mUID;
  if ( !Head )
    p_mUID = 0i64;
  while ( p_mUID )
  {
    if ( p_mUID->mCanPathToCached.mValue != 1 )
    {
      if ( p_mUID->mpXformNode )
      {
        Position = UFG::InterestPoint::GetPosition(p_mUID);
        if ( ((unsigned __int8 (__fastcall *)(UFG::NavManager *, UFG::qVector3 *))UFG::NavManager::ms_pInstance->vfptr->IsInsideAIMesh)(
               UFG::NavManager::ms_pInstance,
               Position) )
        {
          p_mUID->mCanPathToCached.mValue = 1;
        }
        else
        {
          v3 = UFG::NavManager::ms_pInstance->vfptr->IsAIMeshLoadedAt(UFG::NavManager::ms_pInstance, Position);
          v4 = 2;
          if ( v3 )
            v4 = 0;
          p_mUID->mCanPathToCached.mValue = v4;
        }
      }
      else
      {
        p_mUID->mCanPathToCached.mValue = 3;
      }
      if ( p_mUID->mCanPathToCached.mValue == 2 )
      {
        v5 = &p_mUID->UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList>;
        if ( v5->mPrev == v5
          && p_mUID->UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList>::mNext == &p_mUID->UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList> )
        {
          mPrev = UFG::InterestPoint::msCellNotLoadedCanPathList.mNode.mPrev;
          UFG::InterestPoint::msCellNotLoadedCanPathList.mNode.mPrev->mNext = v5;
          v5->mPrev = mPrev;
          p_mUID->UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList>::mNext = (UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList> *)&UFG::InterestPoint::msCellNotLoadedCanPathList;
          UFG::InterestPoint::msCellNotLoadedCanPathList.mNode.mPrev = &p_mUID->UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList>;
        }
      }
    }
    Next = UFG::qBaseTreeRB::GetNext(
             &UFG::InterestPoint::msUseInterestPoints.mTree,
             &p_mUID->UFG::qNodeRB<UFG::InterestPoint>::mNode);
    if ( Next )
      p_mUID = (UFG::InterestPoint *)Next[-2].mRoot.mChild;
    else
      p_mUID = 0i64;
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
  UFG::qVector3 *Position; // rdi
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList> *v3; // rcx
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList> *mPrev; // rax

  if ( this->mpXformNode )
  {
    Position = UFG::InterestPoint::GetPosition(this);
    if ( ((unsigned __int8 (__fastcall *)(UFG::NavManager *, UFG::qVector3 *))UFG::NavManager::ms_pInstance->vfptr->IsInsideAIMesh)(
           UFG::NavManager::ms_pInstance,
           Position) )
    {
      this->mCanPathToCached.mValue = 1;
    }
    else if ( UFG::NavManager::ms_pInstance->vfptr->IsAIMeshLoadedAt(UFG::NavManager::ms_pInstance, Position) )
    {
      this->mCanPathToCached.mValue = 0;
    }
    else
    {
      this->mCanPathToCached.mValue = 2;
    }
  }
  else
  {
    this->mCanPathToCached.mValue = 3;
  }
  if ( this->mCanPathToCached.mValue == 2 )
  {
    v3 = &this->UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList>;
    if ( v3->mPrev == v3
      && this->UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList>::mNext == &this->UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList> )
    {
      mPrev = UFG::InterestPoint::msCellNotLoadedCanPathList.mNode.mPrev;
      UFG::InterestPoint::msCellNotLoadedCanPathList.mNode.mPrev->mNext = v3;
      v3->mPrev = mPrev;
      this->UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList>::mNext = (UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList> *)&UFG::InterestPoint::msCellNotLoadedCanPathList;
      UFG::InterestPoint::msCellNotLoadedCanPathList.mNode.mPrev = &this->UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList>;
    }
  }
}

// File Line: 4442
// RVA: 0x58B380
void __fastcall UFG::InterestPoint::ResetInterestPoint(UFG::InterestPoint *this)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mpUser; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::InterestPointUserComponent> *p_mpInterestPointUserComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::CharacterAnimationComponent> *p_mpParentCharacterAnimationComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::GridIntrusive<UFG::InterestPoint> *v11; // r8
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint> *v12; // rcx
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint> *v13; // rax
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList> *v14; // rcx
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList> *v15; // rax

  p_mpUser = &this->mpUser;
  this->mBeginningScriptInfo.mpCachedScript = 0i64;
  *(_WORD *)&this->mBeginningScriptInfo.mHasScript = 0;
  this->mEndingScriptInfo.mpCachedScript = 0i64;
  *(_WORD *)&this->mEndingScriptInfo.mHasScript = 0;
  this->mOnReservationScriptInfo.mpCachedScript = 0i64;
  *(_WORD *)&this->mOnReservationScriptInfo.mHasScript = 0;
  if ( this->mpUser.m_pPointer )
  {
    mPrev = p_mpUser->mPrev;
    mNext = p_mpUser->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mpUser->mPrev = p_mpUser;
    p_mpUser->mNext = p_mpUser;
  }
  p_mpUser->m_pPointer = 0i64;
  p_mpInterestPointUserComponent = &this->mpInterestPointUserComponent;
  if ( this->mpInterestPointUserComponent.m_pPointer )
  {
    v6 = p_mpInterestPointUserComponent->mPrev;
    v7 = this->mpInterestPointUserComponent.mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    p_mpInterestPointUserComponent->mPrev = p_mpInterestPointUserComponent;
    this->mpInterestPointUserComponent.mNext = &this->mpInterestPointUserComponent;
  }
  this->mpInterestPointUserComponent.m_pPointer = 0i64;
  p_mpParentCharacterAnimationComponent = &this->mpParentCharacterAnimationComponent;
  *(_QWORD *)&this->mUseTime = 0i64;
  *(_DWORD *)&this->mIsReserved = 0;
  this->mIsInterrupted = 0;
  *(_WORD *)&this->mActive = 768;
  *(_QWORD *)&this->mTimeSinceBeginUse = 0i64;
  this->mPassedActivationChance = 1;
  this->mBoneId = -1;
  if ( this->mpParentCharacterAnimationComponent.m_pPointer )
  {
    v9 = p_mpParentCharacterAnimationComponent->mPrev;
    v10 = this->mpParentCharacterAnimationComponent.mNext;
    v9->mNext = v10;
    v10->mPrev = v9;
    p_mpParentCharacterAnimationComponent->mPrev = p_mpParentCharacterAnimationComponent;
    this->mpParentCharacterAnimationComponent.mNext = &this->mpParentCharacterAnimationComponent;
  }
  this->mpParentCharacterAnimationComponent.m_pPointer = 0i64;
  if ( this->mAddedToGrid )
  {
    v11 = UFG::InterestPoint::mspUseInterestPointGrid;
    v12 = this->UFG::GridIntrusiveNode<UFG::InterestPoint>::UFG::qNode<UFG::InterestPoint,UFG::InterestPoint>::mPrev;
    v13 = this->UFG::GridIntrusiveNode<UFG::InterestPoint>::UFG::qNode<UFG::InterestPoint,UFG::InterestPoint>::mNext;
    if ( this->mPoiType.mUID == qSymbol_look.mUID )
      v11 = UFG::InterestPoint::mspLookInterestPointGrid;
    v12->mNext = v13;
    v13->mPrev = v12;
    this->UFG::GridIntrusiveNode<UFG::InterestPoint>::UFG::qNode<UFG::InterestPoint,UFG::InterestPoint>::mPrev = &this->UFG::GridIntrusiveNode<UFG::InterestPoint>;
    this->UFG::GridIntrusiveNode<UFG::InterestPoint>::UFG::qNode<UFG::InterestPoint,UFG::InterestPoint>::mNext = &this->UFG::GridIntrusiveNode<UFG::InterestPoint>;
    --v11->mNodeCount;
  }
  this->mPoiType = UFG::gNullQSymbol;
  this->mGridIndex = -1;
  *(_WORD *)&this->mAddedToGrid = 0;
  this->mFullUpdateRequired = 0;
  v14 = this->UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList>::mPrev;
  v15 = this->UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList>::mNext;
  v14->mNext = v15;
  v15->mPrev = v14;
  this->UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList>::mPrev = &this->UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList>;
  this->UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList>::mNext = &this->UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList>;
  this->mpPedInfoUser = 0i64;
}

// File Line: 4502
// RVA: 0x580F50
UFG::InterestPointType *__fastcall UFG::InterestPoint::FindInterestPointTypeR(UFG::qPropertySet *pProps)
{
  unsigned int mUID; // edx
  UFG::qPropertySet *ParentFromIdx; // rdi
  UFG::InterestPointType *result; // rax
  unsigned int v4; // ebx
  unsigned int v5; // esi

  mUID = pProps->mName.mUID;
  ParentFromIdx = pProps;
  if ( !mUID
    || (result = (UFG::InterestPointType *)UFG::qBaseTreeRB::Get(
                                             &UFG::InterestPoint::msInterestPointTypeTree.mTree,
                                             mUID)) == 0i64 )
  {
    v4 = 0;
    v5 = UFG::qPropertySet::NumParents(ParentFromIdx);
    if ( v5 )
    {
      while ( 1 )
      {
        ParentFromIdx = (UFG::qPropertySet *)UFG::qPropertySet::GetParentFromIdx(ParentFromIdx, v4);
        result = UFG::InterestPoint::FindInterestPointTypeR(ParentFromIdx);
        if ( result )
          break;
        if ( ++v4 >= v5 )
          return 0i64;
      }
    }
    else
    {
      return 0i64;
    }
  }
  return result;
}

// File Line: 4557
// RVA: 0x588B60
void __fastcall UFG::InterestPoint::PropertiesLoad(UFG::InterestPoint *this, UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qPropertySet *v4; // rdi
  UFG::qPropertySet *v5; // rax
  char *MemImagePtr; // rax
  unsigned int v7; // eax
  UFG::qTreeRB<UFG::InterestPoint,UFG::InterestPoint,1> *v8; // rcx
  UFG::InterestPointType *InterestPointTypeR; // rax
  UFG::qPropertySet *ParentFromIdx; // rax
  UFG::PedSpawnManager *Instance; // rax
  UFG::qVector3 *Position; // rax
  UFG::GridIntrusive<UFG::InterestPoint> *v13; // r9
  int v14; // r8d
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint> *p_mNode; // rdx
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint> *mPrev; // rax

  if ( this->m_pSimObject )
    UFG::InterestPoint::ResetInterestPoint(this);
  else
    UFG::MarkerBase::Initialize(this, pSceneObj->m_pSimObject);
  v4 = PropertyUtils::Get<UFG::qPropertySet>(pSceneObj, (UFG::qArray<unsigned long,0> *)&qSymbolX_propset_componentPOI);
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         v4,
         (UFG::qArray<unsigned long,0> *)&component_InterestPoint::sPropertyName,
         DEPTH_RECURSE);
  if ( v5 )
  {
    MemImagePtr = UFG::qPropertySet::GetMemImagePtr(v5);
    if ( MemImagePtr )
    {
      v7 = *(_DWORD *)MemImagePtr;
      v8 = &UFG::InterestPoint::msLookInterestPoints;
      this->mPoiType.mUID = v7;
      if ( v7 != qSymbol_look.mUID )
        v8 = &UFG::InterestPoint::msUseInterestPoints;
      UFG::qBaseTreeRB::Add(&v8->mTree, &this->UFG::qNodeRB<UFG::InterestPoint>::mNode);
      if ( this->mPoiType.mUID != -1 )
      {
        InterestPointTypeR = UFG::InterestPoint::FindInterestPointTypeR(v4);
        this->mInterestPointType = InterestPointTypeR;
        if ( !InterestPointTypeR )
        {
          ParentFromIdx = (UFG::qPropertySet *)UFG::qPropertySet::GetParentFromIdx(v4, 0);
          this->mInterestPointType = UFG::InterestPoint::AddInterestPointType(ParentFromIdx);
        }
        UFG::InterestPoint::LoadStaticProperties(this, v4);
        UFG::InterestPoint::InitBasePOI(this, pSceneObj);
        if ( this->mPoiType.mUID != qSymbol_look.mUID )
        {
          UFG::InterestPoint::InitUsePOI(this, v4);
          if ( this->mPropertiesHandle.mProperties->mSpawnAmbientUserDistance > 0.0 )
          {
            Instance = UFG::PedSpawnManager::GetInstance();
            UFG::PedSpawnManager::RegisterSpawningPOI(Instance, this, pSceneObj);
          }
        }
        UFG::InterestPoint::UpdateInterestPointTransform(this);
        Position = UFG::InterestPoint::GetPosition(this);
        v13 = UFG::InterestPoint::mspUseInterestPointGrid;
        if ( this->mPoiType.mUID == qSymbol_look.mUID )
          v13 = UFG::InterestPoint::mspLookInterestPointGrid;
        v14 = (int)(float)((float)(Position->x - v13->mXMin) * v13->mGridSizeInv)
            + v13->mXDim * (int)(float)((float)(Position->y - v13->mYMin) * v13->mGridSizeInv);
        p_mNode = &v13->mGridNodes[v14].mNode;
        mPrev = p_mNode->mPrev;
        mPrev->mNext = &this->UFG::GridIntrusiveNode<UFG::InterestPoint>;
        this->UFG::GridIntrusiveNode<UFG::InterestPoint>::UFG::qNode<UFG::InterestPoint,UFG::InterestPoint>::mPrev = mPrev;
        this->UFG::GridIntrusiveNode<UFG::InterestPoint>::UFG::qNode<UFG::InterestPoint,UFG::InterestPoint>::mNext = p_mNode;
        p_mNode->mPrev = &this->UFG::GridIntrusiveNode<UFG::InterestPoint>;
        ++v13->mNodeCount;
        this->mGridIndex = v14;
        *(_WORD *)&this->mAddedToGrid = 1;
        UFG::InterestPoint::InitAnimHandles(this);
      }
    }
  }
}

// File Line: 4653
// RVA: 0x585DF0
void __fastcall UFG::InterestPoint::LoadStaticProperties(UFG::InterestPoint *this, UFG::qPropertySet *pProps)
{
  int mNumProperties; // ebx
  UFG::qBaseTreeRB *v5; // rdi
  int v6; // eax
  unsigned int v7; // edx

  mNumProperties = pProps->mNumProperties;
  v5 = 0i64;
  v6 = UFG::qPropertySet::NumParents(pProps);
  if ( !mNumProperties && v6 == 1 )
  {
    v7 = *(_DWORD *)&UFG::qPropertySet::GetParentFromIdx(pProps, 0)->mDebugName[12];
    if ( v7 )
      v5 = UFG::qBaseTreeRB::Get(&UFG::gInterestPointCachedProperties.mTree, v7);
  }
  UFG::InterestPointPropertiesHandle::Load(&this->mPropertiesHandle, (UFG::InterestPointProperties *)v5, pProps);
}

// File Line: 4686
// RVA: 0x58B860
void __fastcall UFG::InterestPoint::SetBoneIDFromProperties(UFG::InterestPoint *this)
{
  UFG::SimComponent *m_pPointer; // rcx
  __int64 v3; // rcx
  int BoneID; // eax
  UFG::SimComponent *v5; // rax

  m_pPointer = this->mpParentCharacterAnimationComponent.m_pPointer;
  if ( m_pPointer )
  {
    v3 = *(_QWORD *)&m_pPointer[2].m_TypeUID;
    if ( v3 )
    {
      if ( *(_QWORD *)(v3 + 440) )
        BoneID = Skeleton::GetBoneID(*(Skeleton **)(v3 + 480), this->mPropertiesHandle.mProperties->mBoneName.mUID);
      else
        BoneID = -1;
      this->mBoneId = BoneID;
      v5 = this->mpParentCharacterAnimationComponent.m_pPointer;
      this->mNeedsBoneFixupWhenRigAvailable = BYTE1(v5[3].vfptr) || !*(_QWORD *)&v5[1].m_Flags;
    }
    else
    {
      this->mNeedsBoneFixupWhenRigAvailable = 1;
    }
  }
}

// File Line: 4709
// RVA: 0x583160
void __fastcall UFG::InterestPoint::InitBasePOI(UFG::InterestPoint *this, UFG::SceneObjectProperties *pSceneObj)
{
  UFG::InterestPointProperties *mProperties; // r8
  UFG::SimObjectCVBase *m_pSimObject; // rcx
  UFG::SimComponent *v5; // r8
  __int16 m_Flags; // dx
  UFG::CharacterAnimationComponent *ComponentOfTypeHK; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::CharacterAnimationComponent> *p_mpParentCharacterAnimationComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::InterestPointProperties *v12; // rdi

  mProperties = this->mPropertiesHandle.mProperties;
  this->mActive = mProperties->mStartActive;
  if ( mProperties->mBoneName.mUID != -1 )
  {
    m_pSimObject = (UFG::SimObjectCVBase *)pSceneObj->mpParent->m_pSimObject;
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
      v5 = ComponentOfTypeHK;
    }
    else
    {
      v5 = 0i64;
    }
    p_mpParentCharacterAnimationComponent = &this->mpParentCharacterAnimationComponent;
    if ( this->mpParentCharacterAnimationComponent.m_pPointer )
    {
      mPrev = p_mpParentCharacterAnimationComponent->mPrev;
      mNext = this->mpParentCharacterAnimationComponent.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_mpParentCharacterAnimationComponent->mPrev = p_mpParentCharacterAnimationComponent;
      this->mpParentCharacterAnimationComponent.mNext = &this->mpParentCharacterAnimationComponent;
    }
    this->mpParentCharacterAnimationComponent.m_pPointer = v5;
    if ( v5 )
    {
      v11 = v5->m_SafePointerList.mNode.mPrev;
      v11->mNext = p_mpParentCharacterAnimationComponent;
      p_mpParentCharacterAnimationComponent->mPrev = v11;
      this->mpParentCharacterAnimationComponent.mNext = &v5->m_SafePointerList.mNode;
      v5->m_SafePointerList.mNode.mPrev = p_mpParentCharacterAnimationComponent;
    }
    UFG::InterestPoint::SetBoneIDFromProperties(this);
  }
  v12 = this->mPropertiesHandle.mProperties;
  this->mPassedActivationChance = v12->mPercentChanceIsActive >= 100.0
                               || UFG::qRandom(100.0, (unsigned int *)&UFG::qDefaultSeed) < v12->mPercentChanceIsActive;
}

// File Line: 4735
// RVA: 0x583DD0
void __fastcall UFG::InterestPoint::InitUsePOI(UFG::InterestPoint *this, UFG::qPropertySet *pProps)
{
  UFG::InterestPointType *mInterestPointType; // rax
  char *v3; // rsi
  char mHasBeginningScript; // r8
  char mHasEndingScript; // cl
  char mHasOnReservationScript; // dl
  UFG::qPropertySet *v9; // rax
  char *MemImagePtr; // rdi
  __int64 v11; // rax
  const char *v12; // rdx
  __int64 v13; // rax
  char *v14; // rcx
  __int64 v15; // rax
  const char *v16; // rdx
  __int64 v17; // rax
  char *v18; // rcx
  __int64 v19; // rax
  const char *v20; // rdx
  __int64 v21; // rax

  mInterestPointType = this->mInterestPointType;
  v3 = 0i64;
  this->mUseTime = -1.0;
  *(_QWORD *)&this->mCooldownTime = 0i64;
  this->mIsInterrupted = 0;
  mHasBeginningScript = mInterestPointType->mHasBeginningScript;
  this->mBeginningScriptInfo.mHasScript = mHasBeginningScript;
  mHasEndingScript = mInterestPointType->mHasEndingScript;
  this->mEndingScriptInfo.mHasScript = mHasEndingScript;
  mHasOnReservationScript = mInterestPointType->mHasOnReservationScript;
  this->mOnReservationScriptInfo.mHasScript = mHasOnReservationScript;
  if ( mHasBeginningScript || mHasEndingScript || mHasOnReservationScript )
  {
    v9 = UFG::qPropertySet::Get<UFG::qPropertySet>(
           pProps,
           (UFG::qArray<unsigned long,0> *)&schema_interestpoint_script::sPropertyName,
           DEPTH_RECURSE);
    if ( v9 )
      MemImagePtr = UFG::qPropertySet::GetMemImagePtr(v9);
    else
      MemImagePtr = 0i64;
    if ( this->mBeginningScriptInfo.mHasScript )
    {
      v11 = *((_QWORD *)MemImagePtr + 3);
      if ( v11 )
        v12 = &MemImagePtr[v11 + 24];
      else
        v12 = 0i64;
      v13 = *((_QWORD *)MemImagePtr + 1);
      if ( v13 )
        v14 = &MemImagePtr[v13 + 8];
      else
        v14 = 0i64;
      this->mBeginningScriptInfo.mpCachedScript = (UFG::ScriptCache::Script *)UFG::ScriptCache::GetScript(
                                                                                v14,
                                                                                v12,
                                                                                0i64,
                                                                                0i64);
    }
    if ( this->mEndingScriptInfo.mHasScript )
    {
      v15 = *((_QWORD *)MemImagePtr + 4);
      if ( v15 )
        v16 = &MemImagePtr[v15 + 32];
      else
        v16 = 0i64;
      v17 = *((_QWORD *)MemImagePtr + 2);
      if ( v17 )
        v18 = &MemImagePtr[v17 + 16];
      else
        v18 = 0i64;
      this->mEndingScriptInfo.mpCachedScript = (UFG::ScriptCache::Script *)UFG::ScriptCache::GetScript(
                                                                             v18,
                                                                             v16,
                                                                             0i64,
                                                                             0i64);
    }
    if ( this->mOnReservationScriptInfo.mHasScript )
    {
      v19 = *((_QWORD *)MemImagePtr + 7);
      if ( v19 )
        v20 = &MemImagePtr[v19 + 56];
      else
        v20 = 0i64;
      v21 = *((_QWORD *)MemImagePtr + 6);
      if ( v21 )
        v3 = &MemImagePtr[v21 + 48];
      this->mOnReservationScriptInfo.mpCachedScript = (UFG::ScriptCache::Script *)UFG::ScriptCache::GetScript(
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
  UFG::qPropertySet *WritablePersistentProperties; // rax
  UFG::qPropertySet *v5; // rax

  WritablePersistentProperties = UFG::SceneObjectProperties::GetWritablePersistentProperties(pSceneObj);
  UFG::qPropertySet::RemovePropertyByName(
    WritablePersistentProperties,
    (UFG::qArray<unsigned long,0> *)&qSymbolX_propset_componentPOI);
  v5 = UFG::SceneObjectProperties::GetWritablePersistentProperties(pSceneObj);
  UFG::InterestPoint::PropertiesAppendProperty(v5, (UFG::qSymbolUC *)&this->mPoiType);
}

// File Line: 4857
// RVA: 0x58A360
UFG::InterestPoint *__fastcall UFG::InterestPoint::PropertiesOnActivate(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v3; // rbp
  UFG::qSymbol *v4; // rax
  __int64 v5; // rax
  __int64 v6; // rdi
  UFG::qSymbol result; // [rsp+68h] [rbp+10h] BYREF
  UFG::allocator::free_link *v9; // [rsp+70h] [rbp+18h]

  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x220ui64, "InterestPoint", 0i64, 1u);
  v9 = v3;
  if ( v3 )
  {
    v4 = (UFG::qSymbol *)UFG::SceneObjectProperties::operator UFG::qSymbol const(pSceneObj, (UFG::qWiseSymbol *)&result);
    UFG::InterestPoint::InterestPoint((UFG::InterestPoint *)v3, v4);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  (*(void (__fastcall **)(__int64, UFG::SceneObjectProperties *))(*(_QWORD *)v6 + 96i64))(v6, pSceneObj);
  return (UFG::InterestPoint *)v6;
}

// File Line: 4874
// RVA: 0x588970
UFG::qPropertySet *__fastcall UFG::InterestPoint::PropertiesAppendProperty(
        UFG::qPropertySet *pProps,
        UFG::qSymbolUC *type)
{
  UFG::qPropertySet *ContainedSet; // rdi
  UFG::qSymbol *v5; // rax
  UFG::qPropertySet *PropertySet; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+18h] BYREF

  ContainedSet = UFG::qPropertySet::CreateContainedSet(&qSymbolX_propset_componentPOI, "InterestPointProps");
  v5 = UFG::InterestPoint::ConvertTypeToPropertiesName(&result, type);
  PropertySet = UFG::PropertySetManager::GetPropertySet(v5);
  UFG::PSWrapper::AppendParentLocal(ContainedSet, PropertySet);
  UFG::qPropertySet::Set<UFG::qPropertySet>(
    pProps,
    (UFG::qArray<unsigned long,0> *)&qSymbolX_propset_componentPOI,
    ContainedSet);
  return ContainedSet;
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
  unsigned int mUID; // ebx
  UFG::qBaseTreeRB *v2; // rax
  UFG::qBaseNodeRB **result; // rax
  UFG::qBaseTreeRB *v4; // rax

  mUID = name->mUID;
  if ( !name->mUID )
    return 0i64;
  v2 = UFG::qBaseTreeRB::Get(&UFG::InterestPoint::msUseInterestPoints.mTree, mUID);
  if ( !v2 || (result = v2[-2].mRoot.mChild) == 0i64 )
  {
    v4 = UFG::qBaseTreeRB::Get(&UFG::InterestPoint::msLookInterestPoints.mTree, mUID);
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
  UFG::InterestPoint *p_mNext; // rbx
  UFG::qList<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList,1,0> *v2; // rdi
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList> *v3; // rbx
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList> *mPrev; // rdx
  UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList> *mNext; // rcx

  v0 = 0;
  p_mNext = (UFG::InterestPoint *)&UFG::InterestPoint::msCellNotLoadedCanPathList.mNode.mNext[-11].mNext;
  if ( &UFG::InterestPoint::msCellNotLoadedCanPathList.mNode.mNext[-11].mNext != (UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList> **)((char *)&UFG::InterestPoint::msCellNotLoadedCanPathList - 168) )
  {
    do
    {
      v2 = (UFG::qList<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList,1,0> *)&p_mNext->UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList>::mNext[-11].mNext;
      UFG::InterestPoint::UpdateCanPathToCached(p_mNext);
      ++v0;
      if ( p_mNext->mCanPathToCached.mValue != 2 )
      {
        v3 = &p_mNext->UFG::qNode<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList>;
        mPrev = v3->mPrev;
        mNext = v3->mNext;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        v3->mPrev = v3;
        v3->mNext = v3;
      }
      p_mNext = (UFG::InterestPoint *)v2;
    }
    while ( v2 != (UFG::qList<UFG::InterestPoint,UFG::InterestPoint_CellNotLoadedCanPathList,1,0> *)((char *)&UFG::InterestPoint::msCellNotLoadedCanPathList - 168) );
  }
  return v0;
}

// File Line: 5144
// RVA: 0x582760
UFG::qBaseNodeRB *__fastcall UFG::InterestPoint::GetParent(UFG::InterestPoint *this)
{
  UFG::SimObject *m_pSimObject; // rax
  UFG::qBaseNodeRB *result; // rax

  m_pSimObject = this->m_pSimObject;
  if ( m_pSimObject )
    m_pSimObject = (UFG::SimObject *)m_pSimObject->m_pSceneObj;
  result = (UFG::qBaseNodeRB *)m_pSimObject->m_UnboundComponentHandles.mNode.mPrev;
  if ( result )
    return result[1].mChild[0];
  return result;
}

// File Line: 5157
// RVA: 0x582780
UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *__fastcall UFG::InterestPoint::GetParentObject(
        UFG::InterestPoint *this)
{
  UFG::SimObject *m_pSimObject; // rdi
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rdi
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rbx
  __int16 v4; // cx
  UFG::SimComponent *v5; // rax

  m_pSimObject = this->m_pSimObject;
  if ( m_pSimObject )
    m_pSimObject = (UFG::SimObject *)m_pSimObject->m_pSceneObj;
  mPrev = m_pSimObject->m_UnboundComponentHandles.mNode.mPrev;
  if ( !mPrev )
    return 0i64;
  while ( 1 )
  {
    mNext = mPrev[2].mNext;
    if ( !mNext )
      break;
    v4 = WORD2(mNext[4].mNext);
    if ( (v4 & 0x4000) != 0 )
    {
      v5 = (UFG::SimComponent *)mNext[6].mNext[25].mPrev;
    }
    else if ( v4 >= 0 )
    {
      if ( (v4 & 0x2000) != 0 )
        v5 = (UFG::SimComponent *)mNext[6].mNext[10].mPrev;
      else
        v5 = (v4 & 0x1000) != 0
           ? (UFG::SimComponent *)mNext[6].mNext[3].mPrev
           : UFG::SimObject::GetComponentOfType((UFG::SimObject *)mPrev[2].mNext, UFG::InterestPoint::_TypeUID);
    }
    else
    {
      v5 = (UFG::SimComponent *)mNext[6].mNext[25].mPrev;
    }
    if ( !v5 )
      break;
    mPrev = mPrev[7].mPrev;
    if ( !mPrev )
      return 0i64;
  }
  return mNext;
}

// File Line: 5178
// RVA: 0x5824A0
UFG::SimObject *__fastcall UFG::InterestPoint::GetChild(UFG::InterestPoint *this, unsigned int index)
{
  int v2; // edi
  unsigned int v5; // esi
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *SceneObj; // rax
  UFG::SimObject *ChildAsSimObject; // rax
  UFG::SimObject *v8; // rbx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax

  v2 = 0;
  v5 = 0;
  if ( !LODWORD(UFG::SimComponent::GetSceneObj(this)[7].mNext) )
    return 0i64;
  while ( 1 )
  {
    SceneObj = UFG::SimComponent::GetSceneObj(this);
    ChildAsSimObject = UFG::SceneObjectProperties::GetChildAsSimObject((UFG::SceneObjectProperties *)SceneObj, v5);
    v8 = ChildAsSimObject;
    if ( !ChildAsSimObject )
      goto LABEL_15;
    m_Flags = ChildAsSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = ChildAsSimObject->m_Components.p[25].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
        m_pComponent = ChildAsSimObject->m_Components.p[10].m_pComponent;
      else
        m_pComponent = (m_Flags & 0x1000) != 0
                     ? ChildAsSimObject->m_Components.p[3].m_pComponent
                     : UFG::SimObject::GetComponentOfType(ChildAsSimObject, UFG::InterestPoint::_TypeUID);
    }
    else
    {
      m_pComponent = ChildAsSimObject->m_Components.p[25].m_pComponent;
    }
    if ( !m_pComponent )
      goto LABEL_15;
    if ( v2 == index )
      return v8;
    ++v2;
LABEL_15:
    if ( ++v5 >= LODWORD(UFG::SimComponent::GetSceneObj(this)[7].mNext) )
      return 0i64;
  }
}

// File Line: 5200
// RVA: 0x5823F0
UFG::SimObject *__fastcall UFG::InterestPoint::GetChild(UFG::InterestPoint *this, UFG::qSymbol *childName)
{
  int v2; // ebx
  unsigned int v5; // edi
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *SceneObj; // rax
  UFG::SimObject *ChildAsSimObject; // rbp
  UFG::SceneObjectProperties *m_pSceneObj; // rcx
  bool v9; // al
  UFG::qSymbol result; // [rsp+60h] [rbp+18h] BYREF

  v2 = 0;
  v5 = 0;
  if ( !LODWORD(UFG::SimComponent::GetSceneObj(this)[7].mNext) )
    return 0i64;
  while ( 1 )
  {
    SceneObj = UFG::SimComponent::GetSceneObj(this);
    ChildAsSimObject = UFG::SceneObjectProperties::GetChildAsSimObject((UFG::SceneObjectProperties *)SceneObj, v5);
    m_pSceneObj = ChildAsSimObject->m_pSceneObj;
    v9 = 0;
    if ( m_pSceneObj )
    {
      v2 |= 1u;
      if ( UFG::SceneObjectProperties::operator UFG::qSymbol const(m_pSceneObj, (UFG::qWiseSymbol *)&result)->mUID == childName->mUID )
        v9 = 1;
    }
    if ( (v2 & 1) != 0 )
      v2 &= ~1u;
    if ( v9 )
      break;
    if ( ++v5 >= LODWORD(UFG::SimComponent::GetSceneObj(this)[7].mNext) )
      return 0i64;
  }
  return ChildAsSimObject;
}

// File Line: 5214
// RVA: 0x58B670
void __fastcall UFG::InterestPoint::SetActive(UFG::InterestPoint *this, bool val, bool applyToChildren)
{
  unsigned int i; // ebx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *SceneObj; // rax
  UFG::SimObject *ChildAsSimObject; // rax
  __int16 m_Flags; // dx
  UFG::InterestPoint *m_pComponent; // rax

  this->mActive = val;
  if ( !val )
    UFG::InterestPoint::EndReservation(this);
  if ( applyToChildren )
  {
    for ( i = 0; i < LODWORD(UFG::SimComponent::GetSceneObj(this)[7].mNext); ++i )
    {
      SceneObj = UFG::SimComponent::GetSceneObj(this);
      ChildAsSimObject = UFG::SceneObjectProperties::GetChildAsSimObject((UFG::SceneObjectProperties *)SceneObj, i);
      if ( ChildAsSimObject )
      {
        m_Flags = ChildAsSimObject->m_Flags;
        if ( (m_Flags & 0x4000) != 0 )
        {
          m_pComponent = (UFG::InterestPoint *)ChildAsSimObject->m_Components.p[25].m_pComponent;
        }
        else if ( m_Flags >= 0 )
        {
          if ( (m_Flags & 0x2000) != 0 )
          {
            m_pComponent = (UFG::InterestPoint *)ChildAsSimObject->m_Components.p[10].m_pComponent;
          }
          else if ( (m_Flags & 0x1000) != 0 )
          {
            m_pComponent = (UFG::InterestPoint *)ChildAsSimObject->m_Components.p[3].m_pComponent;
          }
          else
          {
            m_pComponent = (UFG::InterestPoint *)UFG::SimObject::GetComponentOfType(
                                                   ChildAsSimObject,
                                                   UFG::InterestPoint::_TypeUID);
          }
        }
        else
        {
          m_pComponent = (UFG::InterestPoint *)ChildAsSimObject->m_Components.p[25].m_pComponent;
        }
        if ( m_pComponent )
          UFG::InterestPoint::SetActive(m_pComponent, val, applyToChildren);
      }
    }
  }
}

