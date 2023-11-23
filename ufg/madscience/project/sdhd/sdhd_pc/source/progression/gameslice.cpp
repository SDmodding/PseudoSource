// File Line: 59
// RVA: 0x151BDD0
__int64 UFG::_dynamic_initializer_for__GameSliceTypeSym_CASE__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("CASE", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&GameSliceTypeSym_CASE, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__GameSliceTypeSym_CASE__);
}

// File Line: 196
// RVA: 0x48AA20
void __fastcall UFG::GameSlice::GameSlice(UFG::GameSlice *this, const char *name)
{
  unsigned int mUID; // r8d
  UFG::qSymbol result; // [rsp+50h] [rbp+18h] BYREF

  mUID = UFG::qSymbol::create_from_string(&result, name)->mUID;
  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->mNode.mUID = mUID;
  UFG::qSharedString::qSharedString(&this->mName, name);
  UFG::qSharedString::qSharedString(&this->mTitle);
  UFG::qSharedString::qSharedString(&this->mScriptClassName);
  this->mPDATriggerParameters = 0i64;
  UFG::qSharedString::qSharedString(&this->mNisPath);
  this->mNisSceneSettings = 0i64;
  *(_WORD *)&this->mNisPostFadeIn = 1;
  UFG::qSharedString::qSharedString(&this->mGamePlayState);
  UFG::qSharedString::qSharedString(&this->mGeoState);
  UFG::qSharedString::qSharedString(&this->mLightingState);
  UFG::qSharedString::qSharedString(&this->mMissionFlowState);
  UFG::qSharedString::qSharedString(&this->mObjectiveBlipState);
  UFG::qSharedString::qSharedString(&this->mEncounterState);
  UFG::qSharedString::qSharedString(&this->mAssetState);
  UFG::qSharedString::qSharedString(&this->mPresentationState);
  UFG::qSharedString::qSharedString(&this->mAudioOverride);
  UFG::qSharedString::qSharedString(&this->mSaveGameNameOverride);
  *(_QWORD *)&this->mLayerName.mUID = -1i64;
  *(_QWORD *)&this->mRestoreLocationMarker.mUID = -1i64;
  *(_QWORD *)&this->mRestoreWeapon.mUID = -1i64;
  *(_QWORD *)&this->mVehicleMarkerRange = -1082130432i64;
  this->mCompleteLocationMarker.mUID = -1;
  this->mMinimumDependentsRequired = 0;
  this->mMaxHeatLevel = -1;
  this->mMinPipLevel = 0;
  this->mFaceActionType = 18;
  *(_WORD *)&this->mAutosave = 257;
  this->mRepeatableInterval = 0;
  this->mScriptBinaryFileSize = 0i64;
  this->mScript = 0i64;
  this->mExclusiveChild = 0i64;
  this->mState = STATE_LOCKED;
  *(_QWORD *)&this->mType = 1i64;
  this->mCompletionStatusTimestamp = 0i64;
  this->mIsTODRestricted = 0;
  this->mTODActive = -1.0;
  this->mTODInactive = -1.0;
  this->mTODRestore = -1.0;
  *(_DWORD *)&this->mTODBypassPrompt = 0;
  *(_WORD *)&this->mDisableCopScoring = 0;
  this->mFailTimeout = 100i64;
  *(_QWORD *)&this->mEnabled = 0x10000i64;
  *(_QWORD *)&this->mHoldCurtain = 0i64;
  *(_DWORD *)&this->mDeferRestartIfInsideRegion = 1;
  this->mStatsId = 0;
  this->mDLCProductId = UFG::gNullQSymbol;
  this->mSceneSettings = 0i64;
  *(_QWORD *)&this->mCleanupPending = 0i64;
  this->mpParent = 0i64;
  *(_QWORD *)&this->mDependents.mCount = 0i64;
  this->mDependents.mppArray = 0i64;
  *(_QWORD *)&this->mChildren.mCount = 0i64;
  this->mChildren.mppArray = 0i64;
  UFG::PropertySetHandle::PropertySetHandle(&this->mRewardsProperties);
  UFG::PropertySetHandle::PropertySetHandle(&this->mRepeatedRewardsProperties);
  this->mpDependentMission = 0i64;
  this->mpLastActiveSublice = 0i64;
  this->mpCollection = 0i64;
  *(_WORD *)&this->mCollectionHighPriority = 0;
  *(_QWORD *)&this->mSprinkleCharacter1Override.mUID = -1i64;
  this->mSubsetModeType.mUID = -1;
  this->mpRestoredVehicle.mPrev = &this->mpRestoredVehicle;
  this->mpRestoredVehicle.mNext = &this->mpRestoredVehicle;
  this->mpRestoredVehicle.m_pPointer = 0i64;
  *(_QWORD *)&this->mBorrowedActors.mCount = 0i64;
  this->mBorrowedActors.mppArray = 0i64;
  this->mMissionStates.mNode.mPrev = &this->mMissionStates.mNode;
  this->mMissionStates.mNode.mNext = &this->mMissionStates.mNode;
  *(_QWORD *)&this->mReEnableSlices.mCount = 0i64;
  this->mReEnableSlices.mppArray = 0i64;
  *(_QWORD *)&this->mStateDisplaySeconds = 1110704128i64;
  this->maMasks[0] = 0i64;
  this->maMasks[1] = 0i64;
}

// File Line: 202
// RVA: 0x490320
void __fastcall UFG::GameSlice::~GameSlice(UFG::GameSlice *this)
{
  UFG::GameSlice::CompletionStatus v2; // edx
  UFG::GameSliceMasks **maMasks; // rdi
  __int64 v4; // rbp
  void **v5; // rbx
  UFG::PDATriggerParameters *mPDATriggerParameters; // rbx
  UFG::qNode<UFG::MissionWorkStatus,UFG::MissionWorkStatus> *mPrev; // rcx
  UFG::qNode<UFG::MissionWorkStatus,UFG::MissionWorkStatus> *mNext; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mpRestoredVehicle; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rax

  v2 = STATUS_DISABLE;
  if ( this->mState == STATE_STARTED )
    v2 = 3;
  UFG::GameSlice::End(this, v2);
  maMasks = this->maMasks;
  v4 = 2i64;
  do
  {
    v5 = (void **)*maMasks;
    if ( *maMasks )
    {
      operator delete[](v5[3]);
      operator delete[](v5);
      *maMasks = 0i64;
    }
    ++maMasks;
    --v4;
  }
  while ( v4 );
  mPDATriggerParameters = this->mPDATriggerParameters;
  if ( mPDATriggerParameters )
  {
    UFG::qString::~qString(&mPDATriggerParameters->mObjectiveName);
    UFG::qString::~qString(&mPDATriggerParameters->mContactName);
    operator delete[](mPDATriggerParameters);
    this->mPDATriggerParameters = 0i64;
  }
  operator delete[](this->mReEnableSlices.mppArray);
  UFG::qList<UFG::PopUpMessage,UFG::PopUpMessage,1,0>::DeleteNodes(&this->mMissionStates);
  mPrev = this->mMissionStates.mNode.mPrev;
  mNext = this->mMissionStates.mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mMissionStates.mNode.mPrev = &this->mMissionStates.mNode;
  this->mMissionStates.mNode.mNext = &this->mMissionStates.mNode;
  operator delete[](this->mBorrowedActors.mppArray);
  p_mpRestoredVehicle = &this->mpRestoredVehicle;
  if ( this->mpRestoredVehicle.m_pPointer )
  {
    v10 = p_mpRestoredVehicle->mPrev;
    v11 = this->mpRestoredVehicle.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    p_mpRestoredVehicle->mPrev = p_mpRestoredVehicle;
    this->mpRestoredVehicle.mNext = &this->mpRestoredVehicle;
  }
  this->mpRestoredVehicle.m_pPointer = 0i64;
  v12 = p_mpRestoredVehicle->mPrev;
  v13 = this->mpRestoredVehicle.mNext;
  v12->mNext = v13;
  v13->mPrev = v12;
  p_mpRestoredVehicle->mPrev = p_mpRestoredVehicle;
  this->mpRestoredVehicle.mNext = &this->mpRestoredVehicle;
  UFG::PropertySetHandle::~PropertySetHandle(&this->mRepeatedRewardsProperties);
  UFG::PropertySetHandle::~PropertySetHandle(&this->mRewardsProperties);
  operator delete[](this->mChildren.mppArray);
  operator delete[](this->mDependents.mppArray);
  UFG::qSharedString::~qSharedString(&this->mSaveGameNameOverride);
  UFG::qSharedString::~qSharedString(&this->mAudioOverride);
  UFG::qSharedString::~qSharedString(&this->mPresentationState);
  UFG::qSharedString::~qSharedString(&this->mAssetState);
  UFG::qSharedString::~qSharedString(&this->mEncounterState);
  UFG::qSharedString::~qSharedString(&this->mObjectiveBlipState);
  UFG::qSharedString::~qSharedString(&this->mMissionFlowState);
  UFG::qSharedString::~qSharedString(&this->mLightingState);
  UFG::qSharedString::~qSharedString(&this->mGeoState);
  UFG::qSharedString::~qSharedString(&this->mGamePlayState);
  UFG::qSharedString::~qSharedString(&this->mNisPath);
  UFG::qSharedString::~qSharedString(&this->mScriptClassName);
  UFG::qSharedString::~qSharedString(&this->mTitle);
  UFG::qSharedString::~qSharedString(&this->mName);
}

// File Line: 250
// RVA: 0x4BBD40
void __fastcall UFG::GameSlice::SetCollection(UFG::GameSlice *this, UFG::qString *collectionName, bool highPriority)
{
  char *mData; // rbx
  UFG::qSymbol *v6; // r14
  char *v7; // rbx
  unsigned int mUID; // eax
  UFG::qSymbol result; // [rsp+60h] [rbp+18h] BYREF

  mData = collectionName->mData;
  if ( (_S19_1 & 1) == 0 )
  {
    _S19_1 |= 1u;
    UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
    atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
  }
  UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
  v6 = UFG::qSymbol::create_from_string(&result, mData);
  if ( !v6->mUID || (v7 = (char *)UFG::qBaseTreeRB::Get(&stru_14240A1D8, v6->mUID)) == 0i64 )
  {
    v7 = (char *)UFG::qMalloc(0x38ui64, "GameSliceCollection", 0i64);
    if ( v7 )
    {
      mUID = v6->mUID;
      *(_QWORD *)v7 = 0i64;
      *((_QWORD *)v7 + 1) = 0i64;
      *((_QWORD *)v7 + 2) = 0i64;
      *((_DWORD *)v7 + 6) = mUID;
      *((_DWORD *)v7 + 8) = mUID;
      *((_QWORD *)v7 + 5) = 0i64;
      *((_QWORD *)v7 + 6) = 0i64;
    }
    else
    {
      v7 = 0i64;
    }
    UFG::qBaseTreeRB::Add(&stru_14240A1D8, (UFG::qBaseNodeRB *)v7);
  }
  this->mpCollection = (UFG::GameSliceCollection *)v7;
  this->mCollectionHighPriority = highPriority;
  if ( highPriority )
    qSet<UFG::SceneObjectProperties,UFG::qSymbol,qCompareLogical<UFG::qSymbol>>::Append(
      (qSet<UFG::SceneObjectProperties,UFG::qSymbol,qCompareLogical<UFG::qSymbol> > *)(v7 + 40),
      (UFG::SceneObjectProperties *)this,
      "GameSliceCollection::AddHighPrioritySlice");
}

// File Line: 284
// RVA: 0x4A1D20
UFG::qSymbol *__fastcall UFG::GameSlice::GetCancelLocationMarker(UFG::GameSlice *this)
{
  UFG::GameSlice *mpLastActiveSublice; // rcx
  UFG::qSymbol *result; // rax

  mpLastActiveSublice = this->mpLastActiveSublice;
  if ( !mpLastActiveSublice )
    return &this->mCancelLocationMarker;
  result = UFG::GameSlice::GetCancelLocationMarker(mpLastActiveSublice);
  if ( result->mUID == -1 )
    return &this->mCancelLocationMarker;
  return result;
}

// File Line: 320
// RVA: 0x492B80
void __fastcall UFG::GameSlice::AddDependency(UFG::GameSlice *this, const char *pName)
{
  UFG::qSymbol *v4; // rdi
  UFG::qBaseTreeRB *v5; // rbx
  UFG::allocator::free_link *v6; // rax
  UFG::qBaseTreeRB *v7; // rax
  UFG::qString v8; // [rsp+28h] [rbp-40h] BYREF
  UFG::qSymbol result; // [rsp+70h] [rbp+8h] BYREF
  UFG::allocator::free_link *v10; // [rsp+80h] [rbp+18h]

  if ( (_S19_1 & 1) == 0 )
  {
    _S19_1 |= 1u;
    UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
    atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
  }
  UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
  v4 = UFG::qSymbol::create_from_string(&result, pName);
  if ( (!v4->mUID || (v5 = UFG::qBaseTreeRB::Get(&stru_14240A190, v4->mUID)) == 0i64)
    && (!v4->mUID || (v5 = UFG::qBaseTreeRB::Get(&stru_14240A100, v4->mUID)) == 0i64) )
  {
    if ( v4->mUID )
      v5 = UFG::qBaseTreeRB::Get(&stru_14240A148, v4->mUID);
    else
      v5 = 0i64;
  }
  if ( !v5 )
  {
    UFG::qString::qString(&v8, pName);
    if ( (_S19_1 & 1) == 0 )
    {
      _S19_1 |= 1u;
      UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
      atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
    }
    UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
    v6 = UFG::qMalloc(0x240ui64, "GameSlice", 0i64);
    v10 = v6;
    if ( v6 )
    {
      UFG::GameSlice::GameSlice((UFG::GameSlice *)v6, v8.mData);
      v5 = v7;
    }
    else
    {
      v5 = 0i64;
    }
    UFG::qBaseTreeRB::Add(&stru_14240A190, &v5->mRoot);
    byte_14240B986 = 1;
    UFG::qString::~qString(&v8);
  }
  qSet<UFG::SceneObjectProperties,UFG::qSymbol,qCompareLogical<UFG::qSymbol>>::Append(
    (qSet<UFG::SceneObjectProperties,UFG::qSymbol,qCompareLogical<UFG::qSymbol> > *)&this->mDependents,
    (UFG::SceneObjectProperties *)v5,
    "GameSlice::mDependents");
}

// File Line: 378
// RVA: 0x492A10
UFG::qBaseTreeRB *__fastcall UFG::GameSlice::AddChild(UFG::GameSlice *this, UFG::qString *pName)
{
  char *mData; // rbx
  UFG::qSymbol *v5; // rdi
  UFG::qBaseTreeRB *v6; // rbx
  UFG::allocator::free_link *v7; // rax
  UFG::qBaseTreeRB *v8; // rax
  UFG::qSymbol result; // [rsp+50h] [rbp+8h] BYREF
  UFG::allocator::free_link *v11; // [rsp+58h] [rbp+10h]

  mData = pName->mData;
  if ( (_S19_1 & 1) == 0 )
  {
    _S19_1 |= 1u;
    UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
    atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
  }
  UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
  v5 = UFG::qSymbol::create_from_string(&result, mData);
  if ( (!v5->mUID || (v6 = UFG::qBaseTreeRB::Get(&stru_14240A190, v5->mUID)) == 0i64)
    && (!v5->mUID || (v6 = UFG::qBaseTreeRB::Get(&stru_14240A100, v5->mUID)) == 0i64) )
  {
    if ( v5->mUID )
      v6 = UFG::qBaseTreeRB::Get(&stru_14240A148, v5->mUID);
    else
      v6 = 0i64;
  }
  if ( !v6 )
  {
    if ( (_S19_1 & 1) == 0 )
    {
      _S19_1 |= 1u;
      UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
      atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
    }
    UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
    v7 = UFG::qMalloc(0x240ui64, "GameSlice", 0i64);
    v11 = v7;
    if ( v7 )
    {
      UFG::GameSlice::GameSlice((UFG::GameSlice *)v7, pName->mData);
      v6 = v8;
    }
    else
    {
      v6 = 0i64;
    }
    UFG::qBaseTreeRB::Add(&stru_14240A190, &v6->mRoot);
    byte_14240B986 = 1;
  }
  qSet<UFG::SceneObjectProperties,UFG::qSymbol,qCompareLogical<UFG::qSymbol>>::Append(
    (qSet<UFG::SceneObjectProperties,UFG::qSymbol,qCompareLogical<UFG::qSymbol> > *)&this->mChildren,
    (UFG::SceneObjectProperties *)v6,
    "GameSlice::mChildren");
  v6[5].mRoot.mChild[0] = &this->mNode;
  return v6;
}

// File Line: 392
// RVA: 0x4938D0
void __fastcall UFG::GameSlice::AddReEnableSlice(UFG::GameSlice *this, UFG::qString *pName)
{
  char *mData; // rbx
  UFG::qSymbol *v5; // rdi
  UFG::qBaseTreeRB *v6; // rbx
  UFG::allocator::free_link *v7; // rax
  UFG::qBaseTreeRB *v8; // rax
  UFG::qSymbol result; // [rsp+50h] [rbp+8h] BYREF
  UFG::allocator::free_link *v10; // [rsp+58h] [rbp+10h]

  mData = pName->mData;
  if ( (_S19_1 & 1) == 0 )
  {
    _S19_1 |= 1u;
    UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
    atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
  }
  UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
  v5 = UFG::qSymbol::create_from_string(&result, mData);
  if ( (!v5->mUID || (v6 = UFG::qBaseTreeRB::Get(&stru_14240A190, v5->mUID)) == 0i64)
    && (!v5->mUID || (v6 = UFG::qBaseTreeRB::Get(&stru_14240A100, v5->mUID)) == 0i64) )
  {
    if ( v5->mUID )
      v6 = UFG::qBaseTreeRB::Get(&stru_14240A148, v5->mUID);
    else
      v6 = 0i64;
  }
  if ( !v6 )
  {
    if ( (_S19_1 & 1) == 0 )
    {
      _S19_1 |= 1u;
      UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
      atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
    }
    UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
    v7 = UFG::qMalloc(0x240ui64, "GameSlice", 0i64);
    v10 = v7;
    if ( v7 )
    {
      UFG::GameSlice::GameSlice((UFG::GameSlice *)v7, pName->mData);
      v6 = v8;
    }
    else
    {
      v6 = 0i64;
    }
    UFG::qBaseTreeRB::Add(&stru_14240A190, &v6->mRoot);
    byte_14240B986 = 1;
  }
  qSet<UFG::SceneObjectProperties,UFG::qSymbol,qCompareLogical<UFG::qSymbol>>::Append(
    (qSet<UFG::SceneObjectProperties,UFG::qSymbol,qCompareLogical<UFG::qSymbol> > *)&this->mReEnableSlices,
    (UFG::SceneObjectProperties *)v6,
    "GameSlice::mReEnableSlices");
}

// File Line: 403
// RVA: 0x4A5BE0
UFG::GameSlice *__fastcall UFG::GameSlice::GetParent(UFG::GameSlice *this)
{
  return this->mpParent;
}

// File Line: 435
// RVA: 0x4A22B0
UFG::GameSlice *__fastcall UFG::GameSlice::GetDependentRecursive(
        UFG::GameSlice *this,
        UFG::GameSlice::Type type,
        int *depth)
{
  __int64 mCount; // rdi
  UFG::GameSlice *v4; // rsi
  UFG::GameSlice *v5; // rax
  __int64 v6; // r9
  UFG::GameSlice **mppArray; // rax
  UFG::GameSlice *v8; // r10
  int v9; // ebp
  __int64 v10; // rbx
  UFG::GameSlice **v11; // rax
  UFG::GameSlice *DependentRecursive; // rax
  UFG::GameSlice::Type v15; // [rsp+58h] [rbp+10h]
  int deptha; // [rsp+68h] [rbp+20h] BYREF

  v15 = type;
  mCount = this->mDependents.mCount;
  v4 = 0i64;
  v5 = this;
  v6 = 0i64;
  if ( this->mDependents.mCount )
  {
    mppArray = this->mDependents.mppArray;
    while ( 1 )
    {
      v8 = *mppArray;
      if ( (*mppArray)->mType == type )
        break;
      ++v6;
      ++mppArray;
      if ( v6 >= mCount )
      {
        v5 = this;
        goto LABEL_6;
      }
    }
    *depth = 1;
    return v8;
  }
  else
  {
LABEL_6:
    v9 = 0x7FFFFFFF;
    v10 = 0i64;
    if ( this->mDependents.mCount )
    {
      do
      {
        v11 = v5->mDependents.mppArray;
        deptha = 0x7FFFFFFF;
        DependentRecursive = UFG::GameSlice::GetDependentRecursive(v11[v10], type, &deptha);
        if ( deptha < v9 )
        {
          v9 = deptha;
          v4 = DependentRecursive;
        }
        type = v15;
        v5 = this;
        ++v10;
      }
      while ( v10 < mCount );
      if ( v4 )
        *depth = v9 + 1;
    }
    return v4;
  }
}

// File Line: 472
// RVA: 0x4A5600
__int64 __fastcall UFG::GameSlice::GetNumChildren(UFG::GameSlice *this)
{
  return this->mChildren.mCount;
}

// File Line: 477
// RVA: 0x4A1F50
UFG::GameSlice *__fastcall UFG::GameSlice::GetChild(UFG::GameSlice *this, int index)
{
  return this->mChildren.mppArray[index];
}

// File Line: 535
// RVA: 0x4A1050
UFG::GameSlice::ForceLock

// File Line: 566
// RVA: 0x4C5C50
void __fastcall UFG::GameSlice::UpdateCleanupPending(UFG::GameSlice *this)
{
  __int32 v2; // ecx
  __int32 v3; // ecx
  __int32 v4; // ecx

  v2 = this->mCleanupPending - 1;
  if ( v2 )
  {
    v3 = v2 - 1;
    if ( v3 )
    {
      v4 = v3 - 1;
      if ( v4 )
      {
        if ( v4 == 1 )
          this->mCleanupPending = CLEANUP_NONE;
        else
          this->mCleanupCount = 0;
      }
      else
      {
        UFG::GameSlice::_DisableLayer(this);
        this->mCleanupPending = CLEANUP_LAYER_CLEANUP;
      }
    }
    else
    {
      this->mCleanupPending = CLEANUP_LAYER_PENDING;
    }
  }
  else
  {
    if ( UFG::Metrics::msInstance.mSimTimeDelta > 0.0 )
      ++this->mCleanupCount;
    UFG::qPrintChannel::Print(
      &UFG::gPrintChannel_HK_Progression,
      OUTPUT_LEVEL_DEBUG,
      "[GameSlice]: (%s) Cleanup count is (%d)\n");
  }
}

// File Line: 713
// RVA: 0x4C9850
void __fastcall UFG::GameSlice::_SimulateComplete(UFG::GameSlice *this, bool simulateRewards)
{
  __int64 mCount; // rax
  UFG::GameSlice **mppArray; // rbx
  UFG::GameSlice **i; // rbp
  __int64 v7; // rax
  UFG::GameSlice **v8; // rbx
  UFG::GameSlice **j; // rbp
  bool v10; // zf

  mCount = (int)this->mDependents.mCount;
  if ( (_DWORD)mCount )
  {
    mppArray = this->mDependents.mppArray;
    for ( i = &mppArray[mCount]; mppArray < i; ++mppArray )
    {
      if ( (*mppArray)->mState != STATE_COMPLETED )
        UFG::GameSlice::_SimulateComplete(*mppArray, simulateRewards);
    }
  }
  v7 = (int)this->mChildren.mCount;
  if ( (_DWORD)v7 )
  {
    v8 = this->mChildren.mppArray;
    for ( j = &v8[v7]; v8 < j; ++v8 )
    {
      if ( (*v8)->mState != STATE_COMPLETED )
        UFG::GameSlice::_SimulateComplete(*v8, simulateRewards);
    }
  }
  if ( !this->mCompletionCount )
  {
    v10 = this->mState == STATE_COMPLETED;
    this->mCompletionStatus = 2;
    this->mCompletionStatusTimestamp = UFG::Metrics::msInstance.mSimTimeMSec;
    if ( !v10 && simulateRewards )
      UFG::GameSlice::_HandleCompletionRewards(this, DoNotShowReward);
    ++this->mCompletionCount;
    this->mState = STATE_COMPLETED;
  }
  this->mDirty = 1;
}

// File Line: 769
// RVA: 0x4C60A0
void __fastcall UFG::GameSlice::UpdateDependency(UFG::GameSlice *this)
{
  UFG::GameSlice *v1; // rbx
  __int64 mCount; // rax
  UFG::GameSlice::State v3; // ebp
  UFG::GameSlice **mppArray; // rsi
  UFG::GameSlice **v5; // rax
  UFG::GameSlice *v6; // rdi
  int mState; // esi
  __int64 v8; // r8
  __int64 v9; // r9
  UFG::GameSlice::CompletionStatus v10; // edx
  UFG::GameSlice *mpParent; // rcx
  UFG::GameSlice *v12; // rcx
  char v13; // r8
  __int64 v14; // rax
  UFG::GameSlice **v15; // rsi
  UFG::GameSlice **v16; // rdx
  UFG::GameSlice *v17; // rdi
  int v18; // eax
  UFG::GameSliceCollection *mpCollection; // rax
  __int64 v20; // rdi
  __int64 v21; // rdx
  UFG::GameSlice **v22; // rcx
  UFG::GameSlice *v23; // rsi
  int v24; // edi
  __int64 v25; // r8
  __int64 v26; // r9
  UFG::GameSlice::CompletionStatus v27; // edx
  UFG::GameSlice *v28; // rcx
  UFG::GameSlice *v29; // rcx
  __int64 mRepeatableInterval; // rax
  unsigned __int64 mCompletionStatusTimestamp; // rdx
  UFG::GameSlice::State v32; // edi
  UFG::GameSlice *v33; // rax
  UFG::GameSlice *v34; // rcx
  UFG::GameSlice *v35; // rcx
  __int64 v36; // [rsp+28h] [rbp-20h]
  __int64 v37; // [rsp+30h] [rbp-18h]
  UFG::GameSlice **v38; // [rsp+50h] [rbp+8h]
  char v39; // [rsp+50h] [rbp+8h]
  int v40; // [rsp+58h] [rbp+10h]
  UFG::GameSlice **v41; // [rsp+60h] [rbp+18h]
  __int64 v42; // [rsp+60h] [rbp+18h]

  v1 = this;
  LOBYTE(this) = this->mState == STATE_COMPLETED;
  v40 = (int)this;
  mCount = (int)v1->mDependents.mCount;
  v3 = STATE_LOCKED;
  if ( (_DWORD)mCount )
  {
    mppArray = v1->mDependents.mppArray;
    v5 = &mppArray[mCount];
    v38 = v5;
    if ( mppArray < v5 )
    {
      do
      {
        v6 = *mppArray;
        if ( (*mppArray)->mDirty )
        {
          UFG::GameSlice::UpdateDependency(*mppArray);
          v5 = v38;
        }
        if ( v6->mState == STATE_COMPLETED || v6->mOptional || v6->mCompletionCount > 0 )
          ++v3;
        ++mppArray;
      }
      while ( mppArray < v5 );
      LODWORD(this) = v40;
    }
    if ( v3 < v1->mMinimumDependentsRequired )
    {
      mState = v1->mState;
      if ( mState )
      {
        UFG::ProgressionTracker::Instance()->mDirty = 1;
        if ( v1->mScript )
          UFG::ProgressionTriggerComponent::DisableTrigger(v1, 0);
        v1->mState = STATE_LOCKED;
        if ( !v1->mRepeatableInterval )
          v1->mCompletionCount = 0;
        v10 = STATUS_DISABLE;
        if ( mState >= 4 )
          v10 = 3;
        UFG::GameSlice::End(v1, v10, v8, v9, -2i64, v36, v37);
        if ( v1->mExclusive || v1->mRandomExclusive )
        {
          if ( ((mState - 2) & 0xFFFFFFFD) == 0 && v1->mExclusiveChild == v1 )
          {
            v1->mExclusiveChild = 0i64;
            mpParent = v1->mpParent;
            if ( mpParent )
              UFG::GameSlice::_MarkExclusiveChild(mpParent, 0i64);
          }
          if ( v1->mState == STATE_STARTED )
          {
            v1->mExclusiveChild = v1;
            v12 = v1->mpParent;
            if ( v12 )
              UFG::GameSlice::_MarkExclusiveChild(v12, v1);
            v1->mRequiresSave = 0;
          }
          if ( v1->mState == STATE_COMPLETED && v1->mExclusive && v1->mPersistent )
            v1->mRequiresSave = 1;
        }
      }
      v1->mCompletionCount = 0;
      goto LABEL_114;
    }
    v3 = STATE_LOCKED;
  }
  v13 = 1;
  v39 = 1;
  v14 = (int)v1->mChildren.mCount;
  if ( !(_DWORD)v14 )
  {
LABEL_50:
    if ( (_BYTE)this )
      goto LABEL_82;
    mpCollection = v1->mpCollection;
    if ( !mpCollection )
      goto LABEL_82;
    if ( v1->mCollectionHighPriority )
      goto LABEL_82;
    v20 = 0i64;
    v21 = mpCollection->mHighPrioritySlices.mCount;
    v42 = v21;
    if ( !mpCollection->mHighPrioritySlices.mCount )
      goto LABEL_82;
    while ( 1 )
    {
      v22 = v1->mpCollection->mHighPrioritySlices.mppArray;
      v23 = v22[v20];
      if ( v23->mDirty )
      {
        UFG::GameSlice::UpdateDependency(v22[v20]);
        v21 = v42;
      }
      if ( (unsigned int)(v23->mState - 1) <= 6 )
        break;
      if ( ++v20 >= v21 )
      {
        LOBYTE(this) = v40;
        v13 = v39;
        goto LABEL_82;
      }
    }
    v24 = v1->mState;
    if ( v24 )
    {
      UFG::ProgressionTracker::Instance()->mDirty = 1;
      if ( v1->mScript )
        UFG::ProgressionTriggerComponent::DisableTrigger(v1, 0);
      v1->mState = STATE_LOCKED;
      if ( !v1->mRepeatableInterval )
        v1->mCompletionCount = 0;
      v27 = STATUS_DISABLE;
      if ( v24 >= 4 )
        v27 = 3;
      UFG::GameSlice::End(v1, v27, v25, v26, -2i64, v36, v37);
      if ( v1->mExclusive || v1->mRandomExclusive )
      {
        if ( ((v24 - 2) & 0xFFFFFFFD) == 0 && v1->mExclusiveChild == v1 )
        {
          v1->mExclusiveChild = 0i64;
          v28 = v1->mpParent;
          if ( v28 )
            UFG::GameSlice::_MarkExclusiveChild(v28, 0i64);
        }
        if ( v1->mState == STATE_STARTED )
        {
          v1->mExclusiveChild = v1;
          v29 = v1->mpParent;
          if ( v29 )
            UFG::GameSlice::_MarkExclusiveChild(v29, v1);
          v1->mRequiresSave = 0;
        }
        if ( v1->mState == STATE_COMPLETED && v1->mExclusive && v1->mPersistent )
          v1->mRequiresSave = 1;
      }
    }
    v1->mCompletionCount = 0;
    goto LABEL_114;
  }
  v13 = 0;
  v39 = 0;
  LOBYTE(this) = 1;
  v40 = (int)this;
  v15 = v1->mChildren.mppArray;
  v16 = &v15[v14];
  v41 = v16;
  if ( v15 >= v16 )
    goto LABEL_82;
  do
  {
    v17 = *v15;
    if ( (*v15)->mDirty )
    {
      UFG::GameSlice::UpdateDependency(*v15);
      LODWORD(this) = v40;
      v16 = v41;
      v13 = v39;
    }
    v18 = v17->mState;
    if ( v18 < 1 && v17->mCompletionCount <= 0 )
    {
      LODWORD(this) = (unsigned __int8)this;
      if ( !v17->mOptional )
        LODWORD(this) = 0;
      goto LABEL_47;
    }
    v13 = 1;
    v39 = 1;
    if ( v18 != 8 && !v17->mOptional )
    {
      LOBYTE(this) = 0;
LABEL_47:
      v40 = (int)this;
    }
    ++v15;
  }
  while ( v15 < v16 );
  if ( v13 )
    goto LABEL_50;
LABEL_82:
  mRepeatableInterval = v1->mRepeatableInterval;
  if ( !(_DWORD)mRepeatableInterval || v1->mCompletionStatus != 2 || v1->mCleanupPending )
    goto LABEL_89;
  mCompletionStatusTimestamp = v1->mCompletionStatusTimestamp;
  if ( !mCompletionStatusTimestamp )
  {
    UFG::GameSlice::ForceLock(v1, 0);
    v1->mDirty = 0;
    v1->mCompletionStatus = STATUS_DISABLE;
    v1->mCompletionStatusTimestamp = UFG::Metrics::msInstance.mSimTimeMSec;
    return;
  }
  if ( UFG::Metrics::msInstance.mSimTimeMSec > mCompletionStatusTimestamp + mRepeatableInterval )
  {
    UFG::GameSlice::ForceLock(v1, 0);
  }
  else
  {
LABEL_89:
    if ( v13 )
    {
      if ( (_BYTE)this )
      {
        v3 = STATE_COMPLETED;
      }
      else if ( UFG::GameSlice::_IsUnlockAllowed(v1) )
      {
        v32 = v1->mState;
        if ( ((v32 - 2) & 0xFFFFFFFD) != 0 && v32 != STATE_UNLOCKED )
        {
          if ( (_S19_1 & 1) == 0 )
          {
            _S19_1 |= 1u;
            UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
            atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
          }
          UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
          byte_14240B986 = 1;
          v1->mpLastActiveSublice = 0i64;
          UFG::GameSlice::Unlock(v1, STATE_UNLOCKED);
          v33 = v1->mpParent;
          if ( v33 )
            v33->mpLastActiveSublice = v1;
          if ( v1->mExclusive || v1->mRandomExclusive )
          {
            if ( ((v32 - 2) & 0xFFFFFFFD) == 0 && v1->mExclusiveChild == v1 )
            {
              v1->mExclusiveChild = 0i64;
              v34 = v1->mpParent;
              if ( v34 )
                UFG::GameSlice::_MarkExclusiveChild(v34, 0i64);
            }
            if ( v1->mState == STATE_STARTED )
            {
              v1->mExclusiveChild = v1;
              v35 = v1->mpParent;
              if ( v35 )
                UFG::GameSlice::_MarkExclusiveChild(v35, v1);
              v1->mRequiresSave = 0;
            }
            if ( v1->mState == STATE_COMPLETED && v1->mExclusive )
            {
              if ( v1->mPersistent )
                v1->mRequiresSave = 1;
            }
          }
        }
        goto LABEL_114;
      }
    }
    UFG::GameSlice::SetState(v1, v3);
  }
LABEL_114:
  v1->mDirty = 0;
}

// File Line: 933
// RVA: 0x4AA820
_BOOL8 __fastcall UFG::GameSlice::HasProgressionTrigger(UFG::GameSlice *this)
{
  return this->mTriggerObjectName.mUID != -1
      || (int)this->mChildren.mCount > 0 && (*this->mChildren.mppArray)->mTriggerObjectName.mUID != -1
      || this->mPDATriggerParameters != 0i64;
}

// File Line: 993
// RVA: 0x4BDD50
void __fastcall UFG::GameSlice::SetWaitingForTrigger(UFG::GameSlice *this, char isWaiting, bool turnLayerOn)
{
  bool v6; // cc

  while ( 1 )
  {
    if ( !isWaiting && turnLayerOn )
    {
      UFG::GameSlice::_EnableLayer(this);
      UFG::ProgressionTracker::Instance()->mDirty = 1;
    }
    v6 = (signed int)this->mChildren.mCount < 1;
    this->mWaitingForTrigger = isWaiting;
    if ( v6 )
      break;
    this = *this->mChildren.mppArray;
  }
}

// File Line: 1016
// RVA: 0x4AD130
_BOOL8 __fastcall UFG::GameSlice::IsWaitingForTrigger(UFG::GameSlice *this)
{
  UFG::GameSlice *i; // rax

  for ( i = this->mpParent; i; i = i->mpParent )
    this = i;
  return this->mWaitingForTrigger != 0;
}

// File Line: 1044
// RVA: 0x4C9440
bool __fastcall UFG::GameSlice::_IsChildOf(UFG::GameSlice *this, UFG::GameSlice *pSlice)
{
  bool result; // al
  UFG::GameSlice *mpParent; // rcx

  result = 1;
  if ( this != pSlice )
  {
    mpParent = this->mpParent;
    if ( !mpParent || !UFG::GameSlice::_IsChildOf(mpParent, pSlice) )
      return 0;
  }
  return result;
}

// File Line: 1061
// RVA: 0x4C9470
char __fastcall UFG::GameSlice::_IsDisableWaiting(UFG::GameSlice *this)
{
  UFG::GameSlice *v2; // rbx
  unsigned __int64 mCompletionStatusTimestamp; // rcx
  float mSimTimeMSec_low; // xmm1_4
  unsigned __int64 mFailTimeout; // rax
  float v6; // xmm0_4
  UFG::GameSlice *mpParent; // rcx
  bool IsDeferredRestartIfInsideRegion; // al

  v2 = this;
  if ( this )
  {
    while ( v2->mpParent )
      v2 = v2->mpParent;
    if ( v2->mCompletionStatus == STATUS_ENABLE )
    {
      mpParent = this->mpParent;
      if ( mpParent )
        IsDeferredRestartIfInsideRegion = UFG::GameSlice::IsDeferredRestartIfInsideRegion(mpParent);
      else
        IsDeferredRestartIfInsideRegion = this->mDeferRestartIfInsideRegion != 0;
      if ( IsDeferredRestartIfInsideRegion )
        UFG::ProgressionTriggerComponent::ActiveateOnlyAfterExitFromRegion(v2);
      v2->mCompletionStatus = 3;
      goto LABEL_19;
    }
    if ( v2->mCompletionStatus == 3 )
    {
      mCompletionStatusTimestamp = v2->mCompletionStatusTimestamp;
      if ( mCompletionStatusTimestamp )
      {
        mSimTimeMSec_low = (float)SLODWORD(UFG::Metrics::msInstance.mSimTimeMSec);
        if ( (UFG::Metrics::msInstance.mSimTimeMSec & 0x8000000000000000ui64) != 0i64 )
          mSimTimeMSec_low = mSimTimeMSec_low + 1.8446744e19;
        mFailTimeout = v2->mFailTimeout;
        v6 = (float)((int)mCompletionStatusTimestamp + (int)mFailTimeout);
        if ( (__int64)(mCompletionStatusTimestamp + mFailTimeout) < 0 )
          v6 = v6 + 1.8446744e19;
        if ( mSimTimeMSec_low < v6 )
          return 1;
      }
      v2->mCompletionStatus = STATUS_DISABLE;
LABEL_19:
      v2->mCompletionStatusTimestamp = UFG::Metrics::msInstance.mSimTimeMSec;
      return 1;
    }
  }
  return 0;
}

// File Line: 1117
// RVA: 0x4AB9E0
bool __fastcall UFG::GameSlice::IsAllowedAtThisTimeOfDay(UFG::GameSlice *this)
{
  UFG::GameSlice *v1; // rbx
  UFG::TimeOfDayManager *Instance; // rax
  float mTODActive; // xmm2_4
  float mTODInactive; // xmm1_4
  float m_SecondsSinceMidnight; // xmm0_4

  v1 = this;
  if ( this->mState == STATE_STARTED )
    return 1;
  while ( v1->mpParent )
    v1 = v1->mpParent;
  if ( !v1->mIsTODRestricted )
    return 1;
  Instance = UFG::TimeOfDayManager::GetInstance();
  mTODActive = v1->mTODActive;
  mTODInactive = v1->mTODInactive;
  m_SecondsSinceMidnight = Instance->m_SecondsSinceMidnight;
  if ( mTODActive >= mTODInactive )
  {
    if ( m_SecondsSinceMidnight >= mTODActive )
      return 1;
  }
  else if ( m_SecondsSinceMidnight < mTODActive )
  {
    return 0;
  }
  return m_SecondsSinceMidnight <= mTODInactive;
}

// File Line: 1154
// RVA: 0x4ABF30
bool __fastcall UFG::GameSlice::IsEnabledForCurrentMode(UFG::GameSlice *this)
{
  UFG::GameSlice *mpParent; // rcx

  if ( (_S19_1 & 1) == 0 )
  {
    _S19_1 |= 1u;
    UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
    atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
  }
  UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
  mpParent = this->mpParent;
  if ( mpParent )
    return mpParent->mSubsetModeType.mUID == unk_14240B998;
  else
    return this->mSubsetModeType.mUID == unk_14240B998;
}

// File Line: 1168
// RVA: 0x4C9560
bool __fastcall UFG::GameSlice::_IsUnlockAllowed(UFG::GameSlice *this)
{
  UFG::ProgressionTracker *v3; // rax
  UFG::GameSlice *mpActiveMaster; // rdi
  UFG::GameSliceMasks *v5; // rcx
  bool v6; // si
  UFG::GameSliceMasks *v7; // rcx
  bool v8; // al
  bool v9; // zf
  unsigned int mUID; // eax
  UFG::ProgressionTracker *v11; // rax
  UFG::GameSlice *v12; // rsi
  UFG::GameSliceMasks *v13; // rcx
  bool v14; // di
  UFG::GameSliceMasks *v15; // rcx
  UFG::GameSlice *mpParent; // rcx
  UFG::ProgressionTracker *v17; // rax
  UFG::GameSlice *v18; // rdi
  UFG::GameSlice *v19; // rcx
  UFG::GameSlice *v20; // rcx

  switch ( this->mType )
  {
    case 0:
      return 0;
    case 1:
    case 2:
      return 1;
    case 3:
      if ( UFG::GameSlice::_IsDisableWaiting(this) || !UFG::GameSlice::IsEnabledForCurrentMode(this) )
        return 0;
      v3 = UFG::ProgressionTracker::Instance();
      mpActiveMaster = v3->mpActiveMaster;
      if ( this == mpActiveMaster )
        return 1;
      v5 = this->maMasks[0];
      v6 = !v5 || UFG::GameSliceMasks::IsSet(v5, v3->mpActiveMaster);
      v7 = this->maMasks[1];
      v8 = !v7 || !UFG::GameSliceMasks::IsSet(v7, mpActiveMaster);
      v9 = !v6;
      return !v9 && v8;
    case 4:
      if ( !UFG::GameSlice::IsEnabledForCurrentMode(this) )
        return 0;
      mUID = UFG::GameStatTracker::Instance()->mpSnapshots[0]->mIDs[29].mValue.mUID;
      if ( this->mpCollection )
      {
        if ( this->mCollectionHighPriority && mUID != -1 && mUID != this->mpDependentMission->mNode.mUID )
          return 0;
      }
      if ( !UFG::GameSlice::IsAllowedAtThisTimeOfDay(this) )
        return 0;
      v11 = UFG::ProgressionTracker::Instance();
      v12 = v11->mpActiveMaster;
      v13 = this->maMasks[0];
      v14 = !v13 || UFG::GameSliceMasks::IsSet(v13, v11->mpActiveMaster);
      v15 = this->maMasks[1];
      v8 = !v15 || !UFG::GameSliceMasks::IsSet(v15, v12);
      v9 = !v14;
      return !v9 && v8;
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 0xA:
    case 0xB:
      if ( !UFG::GameSlice::_IsDisableWaiting(this) && UFG::GameSlice::IsEnabledForCurrentMode(this) )
        goto LABEL_35;
      return 0;
    default:
LABEL_35:
      mpParent = this;
      if ( this->mpParent )
        mpParent = this->mpParent;
      if ( !mpParent->mTODBypassPrompt || UFG::GameSlice::IsAllowedAtThisTimeOfDay(this) )
      {
        if ( (_S19_1 & 1) == 0 )
        {
          _S19_1 |= 1u;
          UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
          atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
        }
        UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
        if ( !byte_14240B987 )
        {
          if ( (v17 = UFG::ProgressionTracker::Instance(), (v18 = v17->mpActiveMaster) == 0i64)
            || this == v18
            || (v19 = this->mpParent) != 0i64 && UFG::GameSlice::_IsChildOf(v19, v17->mpActiveMaster)
            || gGameSliceTypePriority[this->mType] > gGameSliceTypePriority[v18->mType] )
          {
            v20 = this->mpParent;
            if ( !v20 || v20->mState != STATE_COMPLETED && !UFG::GameSlice::IsRunningExclusiveChild(v20, this) )
              return 1;
          }
        }
      }
      return 0;
  }
}

// File Line: 1329
// RVA: 0x4ACBD0
bool __fastcall UFG::GameSlice::IsRewardPropertyRaceType(UFG::GameSlice *this)
{
  UFG::qPropertySet *RewardsProperties; // rbx
  UFG::qArray<unsigned long,0> *v2; // rax
  UFG::qSymbol *v3; // rax
  UFG::qSymbol *v4; // rcx
  UFG::qSymbol result; // [rsp+38h] [rbp+10h] BYREF

  RewardsProperties = UFG::GameSlice::GetRewardsProperties(this);
  if ( !RewardsProperties )
    return 0;
  v2 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(&result, "GamesliceType");
  v3 = UFG::qPropertySet::Get<UFG::qSymbol>(RewardsProperties, v2, DEPTH_RECURSE);
  v4 = &UFG::gNullQSymbol;
  if ( v3 )
    v4 = v3;
  return v4->mUID == qSymbol_Race_14.mUID;
}

// File Line: 1346
// RVA: 0x4ACC60
char __fastcall UFG::GameSlice::IsRunningExclusiveChild(UFG::GameSlice *this, UFG::GameSlice *pChild)
{
  UFG::GameSlice *mExclusiveChild; // rax
  __int64 mCount; // rbx
  __int64 v5; // r9
  __int64 v6; // r8
  UFG::GameSlice **i; // r10
  __int64 v8; // rcx
  UFG::GameSlice **mppArray; // rax

  mExclusiveChild = this->mExclusiveChild;
  if ( !mExclusiveChild || !pChild || mExclusiveChild == pChild )
    return 0;
  mCount = (int)mExclusiveChild->mDependents.mCount;
  v5 = 0i64;
  if ( mCount <= 0 )
    return 0;
  v6 = (int)pChild->mDependents.mCount;
  for ( i = mExclusiveChild->mDependents.mppArray; ; ++i )
  {
    v8 = 0i64;
    if ( v6 > 0 )
      break;
LABEL_11:
    if ( ++v5 >= mCount )
      return 0;
  }
  mppArray = pChild->mDependents.mppArray;
  while ( *mppArray != *i )
  {
    ++v8;
    ++mppArray;
    if ( v8 >= v6 )
      goto LABEL_11;
  }
  return 1;
}

// File Line: 1371
// RVA: 0x4C9260
void __fastcall UFG::GameSlice::_EnableLayer(UFG::GameSlice *this)
{
  unsigned int mUID; // eax
  UFG::qBaseTreeRB *Layer; // rax
  UFG::qSymbol name; // [rsp+30h] [rbp+8h] BYREF

  if ( !this->mLayerEnabledByMe )
  {
    mUID = this->mLayerName.mUID;
    this->mLayerEnabledByMe = 1;
    name.mUID = mUID;
    Layer = UFG::Scene::FindLayer(&UFG::Scene::msDefault, &name);
    if ( Layer )
      UFG::SceneLayer::EnableActivate((UFG::SceneLayer *)Layer, 1, PERSISTENT, 0);
  }
}

// File Line: 1392
// RVA: 0x4C9210
void __fastcall UFG::GameSlice::_DisableLayer(UFG::GameSlice *this)
{
  unsigned int mUID; // eax
  UFG::qBaseTreeRB *Layer; // rax
  UFG::qSymbol name; // [rsp+30h] [rbp+8h] BYREF

  if ( this->mLayerEnabledByMe )
  {
    mUID = this->mLayerName.mUID;
    this->mLayerEnabledByMe = 0;
    name.mUID = mUID;
    Layer = UFG::Scene::FindLayer(&UFG::Scene::msDefault, &name);
    if ( Layer )
      UFG::SceneLayer::EnableActivate((UFG::SceneLayer *)Layer, 0, PERSISTENT, 0);
  }
}

// File Line: 1418
// RVA: 0x4BEF50
void __fastcall UFG::GameSlice::Start(UFG::GameSlice *this)
{
  bool v2; // zf
  __int64 mType; // rbx
  UFG::ProgressionTracker *v4; // rax
  __int64 v5; // rbx
  UFG::ProgressionTracker *v6; // rax
  UFG::GameSlice *mpParent; // rcx

  if ( !this->mScript )
  {
    v2 = this->mCountedStats == 0;
    this->mCompletionStatus = STATUS_DISABLE;
    this->mCompletionStatusTimestamp = UFG::Metrics::msInstance.mSimTimeMSec;
    if ( v2 )
    {
      UFG::qPrintChannel::Print(
        &UFG::gPrintChannel_HK_Progression,
        OUTPUT_LEVEL_DEBUG,
        "[Progression]: ScriptObjective starting for (%s)\n");
      UFG::ProgressionTracker::Instance();
      mType = this->mType;
      v4 = UFG::ProgressionTracker::Instance();
      ++v4->gActiveGameSlices[mType];
      if ( !this->mpParent && this->mType > TYPE_CULL )
      {
        UFG::ProgressionTracker::Instance();
        v5 = this->mType;
        v6 = UFG::ProgressionTracker::Instance();
        ++v6->gActiveContainers[v5];
      }
      this->mCountedStats = 1;
    }
    if ( this->mDeferStartIfInsideRegion
      && (unsigned int)UFG::FlowController::GetCurrentState(&UFG::gFlowController) == uidGameStateInGame_9 )
    {
      mpParent = this->mpParent;
      if ( !mpParent )
        mpParent = this;
      UFG::ProgressionTriggerComponent::ActiveateOnlyAfterExitFromRegion(mpParent);
    }
    UFG::ProgressionTriggerComponent::EnableTrigger(this);
  }
}

// File Line: 1471
// RVA: 0x4BF760
void __fastcall UFG::GameSlice::StartScript(UFG::GameSlice *this)
{
  __int64 v2; // rbx
  SSActorClass *v3; // rsi
  SSInstance *v4; // rax
  UFG::SSGameSlice *v5; // rax
  UFG::GameSlice *mpParent; // rax
  UFG::SSGameSlice *mScript; // rax
  SSInstance *v8; // r8
  UFG::SSGameSlice *v9; // rcx
  SSActor *v10; // r8
  __int64 mCount; // rsi
  UFG::GameSlice *v12; // rdx
  SSInstance *args_pp; // [rsp+60h] [rbp+8h] BYREF

  v2 = 0i64;
  if ( !this->mScript )
  {
    v3 = (SSActorClass *)SSBrain::get_class(this->mScriptClassName.mText);
    if ( v3 )
    {
      UFG::qPrintChannel::Print(
        &UFG::gPrintChannel_HK_Progression,
        OUTPUT_LEVEL_DEBUG,
        "[Progression]: StartScript (%s)\n");
      v4 = (SSInstance *)AMemory::c_malloc_func(0xA0ui64, "SSGameSlice");
      args_pp = v4;
      if ( v4 )
        UFG::SSGameSlice::SSGameSlice((UFG::SSGameSlice *)v4, this, (ASymbol *)&this->mNode.mUID, v3, 1);
      else
        v5 = 0i64;
      this->mScript = v5;
      ++v5->i_ref_count;
      mpParent = this->mpParent;
      if ( mpParent )
      {
        mScript = mpParent->mScript;
        v8 = &mScript->SSActor;
        if ( !mScript )
          v8 = 0i64;
        this->mScript->vfptr->set_data_by_name(&this->mScript->SSActor, (ASymbol *)&qSymbol_i_gameslice_data, v8);
      }
      SSInstance::call_default_constructor(&this->mScript->SSActor);
      if ( !this->mpParent )
      {
        v9 = this->mScript;
        v10 = &v9->SSActor;
        if ( !v9 )
          v10 = 0i64;
        v9->SSActor::SSDataInstance::SSInstance::SSObjectBase::vfptr->set_data_by_name(
          &v9->SSActor,
          (ASymbol *)&qSymbol_i_gameslice_data,
          v10);
      }
      SSActor::enable_behavior(&this->mScript->SSActor, 1);
      args_pp = 0i64;
      SSInstance::coroutine_call(
        &this->mScript->SSActor,
        (ASymbol *)&qSymbol__gameslice_main_private,
        &args_pp,
        0,
        1,
        0.0,
        0i64,
        0i64);
      if ( this->mScript )
        this->mCleanupPending = CLEANUP_NONE;
    }
  }
  mCount = this->mChildren.mCount;
  if ( this->mChildren.mCount )
  {
    do
    {
      v12 = this->mChildren.mppArray[v2];
      if ( (unsigned int)(v12->mState - 1) <= 6 )
        UFG::GameSliceStreamer::RequestStream(
          UFG::GameSliceStreamer::mspInstance,
          (UFG::qNode<UFG::GameSliceStreamer::StreamRequest,UFG::GameSliceStreamer::StreamRequest> *)v12);
      ++v2;
    }
    while ( v2 < mCount );
  }
}

// File Line: 1552
// RVA: 0x4C1960
void __fastcall UFG::GameSlice::StopDrivenVehicle(UFG::GameSlice *this)
{
  signed __int16 m_Flags; // dx
  UFG::CharacterOccupantComponent *m_pComponent; // rax
  UFG::SimObjectGame *CurrentVehicle; // rax
  __int16 v4; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx

  if ( this->mVehicleSuperStop && LocalPlayer )
  {
    m_Flags = LocalPlayer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
      m_pComponent = (UFG::CharacterOccupantComponent *)LocalPlayer->m_Components.p[44].m_pComponent;
    else
      m_pComponent = (UFG::CharacterOccupantComponent *)(m_Flags < 0
                                                      || (m_Flags & 0x2000) != 0
                                                      || (m_Flags & 0x1000) != 0
                                                       ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                           LocalPlayer,
                                                           UFG::CharacterOccupantComponent::_TypeUID)
                                                       : UFG::SimObject::GetComponentOfType(
                                                           LocalPlayer,
                                                           UFG::CharacterOccupantComponent::_TypeUID));
    if ( m_pComponent )
    {
      CurrentVehicle = (UFG::SimObjectGame *)UFG::CharacterOccupantComponent::GetCurrentVehicle(m_pComponent);
      if ( CurrentVehicle )
      {
        v4 = CurrentVehicle->m_Flags;
        if ( (v4 & 0x4000) == 0 )
        {
          if ( v4 >= 0 )
          {
            if ( (v4 & 0x2000) != 0 )
              return;
            if ( (v4 & 0x1000) != 0 )
              ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                    CurrentVehicle,
                                    UFG::PhysicsMoverInterface::_TypeUID);
            else
              ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                    CurrentVehicle,
                                    UFG::PhysicsMoverInterface::_TypeUID);
          }
          else
          {
            ComponentOfTypeHK = CurrentVehicle->m_Components.p[34].m_pComponent;
          }
          if ( ComponentOfTypeHK )
          {
            mPrev = ComponentOfTypeHK[10].m_SafePointerList.mNode.mPrev;
            if ( mPrev )
              HIDWORD(mPrev[37].mNext) |= 8u;
          }
        }
      }
    }
  }
}

// File Line: 1581
// RVA: 0x4BE5C0
void __fastcall UFG::GameSlice::SetupTimeAndWeather(UFG::GameSlice *this, bool immediate)
{
  UFG::SceneSettings *mSceneSettings; // rax
  float v5; // xmm6_4
  UFG::TimeOfDayManager *Instance; // rdi
  UFG::SceneSettings *v7; // rax
  float mWeatherOverrideIntensity; // xmm1_4
  bool mWeatherOverrideLock; // si
  float mWeatherOverrideWetness; // xmm1_4
  float mTimeOverrideInSeconds; // xmm1_4

  mSceneSettings = this->mSceneSettings;
  if ( mSceneSettings )
  {
    v5 = 0.0;
    if ( mSceneSettings->mTimeOverrideInSeconds >= 0.0 || mSceneSettings->mWeatherOverrideIntensity >= 0.0 )
    {
      if ( UFG::UIHK_NISOverlay::IsCurtainVisible() )
      {
        Instance = UFG::TimeOfDayManager::GetInstance();
        v7 = this->mSceneSettings;
        mWeatherOverrideIntensity = v7->mWeatherOverrideIntensity;
        if ( mWeatherOverrideIntensity >= 0.0 )
        {
          mWeatherOverrideLock = v7->mWeatherOverrideLock;
          if ( immediate || mWeatherOverrideLock )
            UFG::TimeOfDayManager::SetWeather(Instance, mWeatherOverrideIntensity);
          else
            UFG::TimeOfDayManager::SetWeatherTarget(Instance, mWeatherOverrideIntensity);
          mWeatherOverrideWetness = this->mSceneSettings->mWeatherOverrideWetness;
          if ( mWeatherOverrideWetness >= 0.0 )
            UFG::TimeOfDayManager::SetSurfaceWetnessOverride(
              Instance,
              mWeatherOverrideWetness,
              "UFG.GameSlice.SetupTimeAndWeather");
          UFG::TimeOfDayManager::LockWeather(Instance, mWeatherOverrideLock);
        }
        mTimeOverrideInSeconds = this->mSceneSettings->mTimeOverrideInSeconds;
        if ( mTimeOverrideInSeconds >= 0.0 )
        {
          UFG::TimeOfDayManager::SetTime(Instance, mTimeOverrideInSeconds, 0);
          if ( !this->mSceneSettings->mTimeOverrideLock )
            v5 = FLOAT_40_0;
          TimePlotPoint::SetTimeValue(Instance, v5);
        }
      }
      else
      {
        UFG::VehicleOccupantComponent::SetParkingSpot(
          (UFG::RoadNetworkGuide *)&UFG::gLoadingLogic,
          (UFG::RoadNetworkLane *)this);
      }
    }
  }
}

// File Line: 1626
// RVA: 0x497600
void __fastcall UFG::GameSlice::CleanupTimeAndWeather(UFG::GameSlice *this)
{
  UFG::TimeOfDayManager *Instance; // rdi
  UFG::SceneSettings *mSceneSettings; // rax
  UFG::SceneSettings *v4; // rax
  UFG::GameSlice *mpParent; // r8
  int mCount; // eax
  bool v7; // al
  UFG::SceneSettings *v8; // rcx

  if ( this->mSceneSettings )
  {
    Instance = UFG::TimeOfDayManager::GetInstance();
    mSceneSettings = this->mSceneSettings;
    if ( mSceneSettings->mWeatherOverrideIntensity >= 0.0 && mSceneSettings->mWeatherOverrideLock )
      UFG::TimeOfDayManager::LockWeather(Instance, 0);
    if ( this->mSceneSettings->mWeatherOverrideWetness >= 0.0 )
      UFG::TimeOfDayManager::SetSurfaceWetnessOverride(Instance, -1.0, "GameSlice::CleanupTimeAndWeather");
    v4 = this->mSceneSettings;
    if ( v4->mTimeOverrideInSeconds >= 0.0 && v4->mTimeOverrideLock )
      TimePlotPoint::SetTimeValue(Instance, 40.0);
    mpParent = this->mpParent;
    v7 = 0;
    if ( mpParent )
    {
      mCount = mpParent->mChildren.mCount;
      if ( mCount > 0 && mpParent->mChildren.mppArray[mCount - 1] == this )
        v7 = 1;
    }
    if ( mpParent )
    {
      v8 = this->mSceneSettings;
      if ( (v8->mWeatherOverrideIntensity >= 0.0 || v8->mTimeOverrideInSeconds >= 0.0) && !v7 )
        UFG::GameSlice::SetupTimeAndWeather(this->mpParent, 1);
    }
  }
}

// File Line: 1661
// RVA: 0x4BDE40
void __fastcall UFG::GameSlice::SetupPedsAndVehicles(UFG::GameSlice *this)
{
  UFG::SceneSettings *mSceneSettings; // rax

  mSceneSettings = this->mSceneSettings;
  if ( mSceneSettings )
  {
    UFG::PedSpawning_AmbientPedEnableHelper(mSceneSettings->mEnableAmbientPedsOnStart);
    if ( this->mSceneSettings->mLockPedsOnStart )
      UFG::PedSpawning_AmbientPedEnableLockHelper(1);
    UFG::WheeledVehicleManager::EnableTrafficSystem(
      UFG::WheeledVehicleManager::m_Instance,
      this->mSceneSettings->mEnableTrafficOnStart);
    if ( this->mSceneSettings->mLockTrafficOnStart )
      UFG::WheeledVehicleManager::SetTrafficSystemLocked(1);
  }
}

// File Line: 1679
// RVA: 0x496F80
void __fastcall UFG::GameSlice::CleanupPedsAndVehicles(UFG::GameSlice *this)
{
  UFG::SceneSettings *mSceneSettings; // rax

  mSceneSettings = this->mSceneSettings;
  if ( mSceneSettings )
  {
    if ( mSceneSettings->mUnLockTrafficOnEnd )
      UFG::WheeledVehicleManager::SetTrafficSystemLocked(0);
    UFG::WheeledVehicleManager::EnableTrafficSystem(
      UFG::WheeledVehicleManager::m_Instance,
      this->mSceneSettings->mEnableTrafficOnEnd);
    if ( this->mSceneSettings->mUnLockPedsOnEnd )
      UFG::PedSpawning_AmbientPedEnableLockHelper(0);
    UFG::PedSpawning_AmbientPedEnableHelper(this->mSceneSettings->mEnableAmbientPedsOnEnd);
  }
}

// File Line: 1699
// RVA: 0x4BDEB0
void __fastcall UFG::GameSlice::SetupSceneLayers(UFG::GameSlice *this)
{
  UFG::SceneSettings *mSceneSettings; // rbp
  unsigned int i; // esi
  __int64 v4; // rdx
  const char *v5; // rdi
  char v6; // bl
  UFG::SceneSettings *v7; // rbp
  unsigned int j; // edi
  __int64 v9; // rbx
  UFG::qBaseTreeRB *Layer; // rax
  UFG::SceneLayer *v11; // rsi
  UFG::SceneSettings *v12; // rbp
  unsigned int k; // esi
  __int64 v14; // rcx
  SSActor *v15; // rbx
  SSObjectBaseVtbl *vfptr; // rdi
  ASymbol *v17; // rax
  SSInstance **v18; // r8
  UFG::SceneSettings *v19; // r15
  int v20; // ebp
  UFG::SimObjectCharacter *v21; // r8
  __int64 v22; // rsi
  __int16 m_Flags; // cx
  UFG::TSActorComponent *m_pComponent; // rax
  UFG::TSActor *Actor; // r14
  bool v26; // di
  AObjReusePool<SSBoolean> *pool; // rbx
  unsigned int i_count; // eax
  unsigned int v29; // eax
  __int64 v30; // rcx
  SSBoolean **i_array_p; // rax
  unsigned int v32; // eax
  __int64 v33; // rdx
  bool v34; // di
  AObjReusePool<SSBoolean> *v35; // rbx
  unsigned int v36; // eax
  unsigned int v37; // eax
  __int64 v38; // rcx
  SSBoolean **v39; // rax
  unsigned int v40; // eax
  __int64 v41; // rdx
  unsigned __int8 v42; // di
  AObjReusePool<SSBoolean> *v43; // rbx
  unsigned int v44; // eax
  unsigned int v45; // eax
  __int64 v46; // rcx
  SSBoolean **v47; // rax
  unsigned int v48; // eax
  __int64 v49; // rdx
  SSObjectBaseVtbl *v50; // rbx
  ASymbol *v51; // rax
  UFG::SceneSettings *v52; // rsi
  unsigned int v53; // edi
  UFG::GameStatTracker *m; // rax
  __int64 v55; // rbx
  UFG::GameStatTracker *v56; // rcx
  UFG::qString *p_mValue; // rcx
  UFG::GameStatTracker *v58; // rcx
  UFG::GameStatTracker *v59; // rcx
  UFG::SceneSettings *v60; // rsi
  int v61; // edi
  __int64 v62; // rbx
  UFG::GameStatTracker *v63; // rcx
  UFG::qString *v64; // rcx
  UFG::GameStatTracker *v65; // rcx
  UFG::GameStatTracker *v66; // rax
  __int64 v67; // [rsp+30h] [rbp-78h]
  __int64 v68[14]; // [rsp+38h] [rbp-70h] BYREF
  ASymbol result; // [rsp+B0h] [rbp+8h] BYREF
  ASymbol v70; // [rsp+B8h] [rbp+10h] BYREF
  SSInstance *v71; // [rsp+C0h] [rbp+18h] BYREF
  SSInstance *v72; // [rsp+C8h] [rbp+20h] BYREF

  v67 = -2i64;
  mSceneSettings = this->mSceneSettings;
  if ( mSceneSettings )
  {
    for ( i = 0; i < mSceneSettings->mAltLayerSetupOnStart.size; ++i )
    {
      v4 = (__int64)&mSceneSettings->mAltLayerSetupOnStart.p[i];
      v5 = *(const char **)(v4 + 24);
      v6 = *(_BYTE *)(v4 + 41);
      UFG::SectionLayout::SetLayerActive(v5, v6);
      UFG::SectionChooser::FlushAltLayer(v5, v6);
    }
    v7 = this->mSceneSettings;
    for ( j = 0; j < v7->mLayerSetupOnStart.size; ++j )
    {
      v9 = (__int64)&v7->mLayerSetupOnStart.p[j];
      Layer = UFG::Scene::FindOrCreateLayer(&UFG::Scene::msDefault, (UFG::qSymbol *)v9);
      v11 = (UFG::SceneLayer *)Layer;
      if ( Layer )
      {
        if ( *(_BYTE *)(v9 + 4) )
        {
          UFG::SceneLayer::EnableGeographical((UFG::SceneLayer *)Layer, 1, PERSISTENT);
          UFG::SceneLayer::EnableAutoActivate(v11, *(_BYTE *)(v9 + 6), PERSISTENT);
        }
        UFG::SceneLayer::EnableActivate(v11, *(_BYTE *)(v9 + 7), PERSISTENT, 0);
      }
    }
    v12 = this->mSceneSettings;
    for ( k = 0; k < v12->mVendorSetupOnStart.size; ++k )
    {
      v14 = (__int64)&v12->mVendorSetupOnStart.p[k];
      if ( *(_BYTE *)(v14 + 4) )
      {
        v71 = SSSymbol::as_instance((ASymbol *)v14);
        v15 = SkookumScript::c_world_p;
        vfptr = SkookumScript::c_world_p->vfptr;
        v17 = ASymbol::create(&result, "enable_vendor_by_type", 0xFFFFFFFF, ATerm_long);
        v18 = &v71;
      }
      else
      {
        v72 = SSSymbol::as_instance((ASymbol *)v14);
        v15 = SkookumScript::c_world_p;
        vfptr = SkookumScript::c_world_p->vfptr;
        v17 = ASymbol::create(&v70, "disable_vendor_by_type", 0xFFFFFFFF, ATerm_long);
        v18 = &v72;
      }
      ((void (__fastcall *)(SSActor *, ASymbol *, SSInstance **, __int64, _QWORD, _QWORD, __int64))vfptr[1].set_data_by_name)(
        v15,
        v17,
        v18,
        1i64,
        0i64,
        0i64,
        v67);
    }
    v19 = this->mSceneSettings;
    v20 = 0;
    if ( v19->mDisguiseSetupOnStart.size )
    {
      v21 = LocalPlayer;
      while ( 1 )
      {
        v22 = (__int64)&v19->mDisguiseSetupOnStart.p[v20];
        if ( !v21 )
          goto LABEL_55;
        m_Flags = v21->m_Flags;
        if ( (m_Flags & 0x4000) != 0 )
        {
          m_pComponent = (UFG::TSActorComponent *)v21->m_Components.p[4].m_pComponent;
        }
        else if ( m_Flags >= 0 )
        {
          if ( (m_Flags & 0x2000) != 0 )
          {
            m_pComponent = (UFG::TSActorComponent *)v21->m_Components.p[3].m_pComponent;
          }
          else if ( (m_Flags & 0x1000) != 0 )
          {
            m_pComponent = (UFG::TSActorComponent *)v21->m_Components.p[2].m_pComponent;
          }
          else
          {
            m_pComponent = (UFG::TSActorComponent *)UFG::SimObject::GetComponentOfType(
                                                      v21,
                                                      UFG::TSActorComponent::_TypeUID);
            v21 = LocalPlayer;
          }
        }
        else
        {
          m_pComponent = (UFG::TSActorComponent *)v21->m_Components.p[4].m_pComponent;
        }
        if ( !m_pComponent )
          goto LABEL_55;
        Actor = UFG::TSActorComponent::GetActor(m_pComponent);
        if ( Actor )
          break;
LABEL_54:
        v21 = LocalPlayer;
LABEL_55:
        if ( ++v20 >= v19->mDisguiseSetupOnStart.size )
          goto LABEL_56;
      }
      v68[0] = (__int64)SSSymbol::as_instance((ASymbol *)v22);
      v26 = *(_BYTE *)(v22 + 4) == 0;
      pool = SSBoolean::get_pool();
      if ( pool->i_pool.i_count )
      {
        v32 = pool->i_pool.i_count - 1;
        pool->i_pool.i_count = v32;
        v30 = v32;
        i_array_p = pool->i_pool.i_array_p;
      }
      else
      {
        if ( !pool->i_exp_pool.i_count )
          AObjReusePool<SSBoolean>::append_block(pool, pool->i_expand_size);
        i_count = pool->i_exp_pool.i_count;
        if ( !i_count )
        {
          v33 = 0i64;
LABEL_37:
          *(_QWORD *)(v33 + 32) = v26;
          *(_DWORD *)(v33 + 16) = 1;
          *(_DWORD *)(v33 + 8) = ++SSObjectBase::c_ptr_id_prev;
          v68[1] = v33;
          v34 = *(_BYTE *)(v22 + 5) == 0;
          v35 = SSBoolean::get_pool();
          if ( v35->i_pool.i_count )
          {
            v40 = v35->i_pool.i_count - 1;
            v35->i_pool.i_count = v40;
            v38 = v40;
            v39 = v35->i_pool.i_array_p;
          }
          else
          {
            if ( !v35->i_exp_pool.i_count )
              AObjReusePool<SSBoolean>::append_block(v35, v35->i_expand_size);
            v36 = v35->i_exp_pool.i_count;
            if ( !v36 )
            {
              v41 = 0i64;
LABEL_45:
              *(_QWORD *)(v41 + 32) = v34;
              *(_DWORD *)(v41 + 16) = 1;
              *(_DWORD *)(v41 + 8) = ++SSObjectBase::c_ptr_id_prev;
              v68[2] = v41;
              v42 = *(_BYTE *)(v22 + 6);
              v43 = SSBoolean::get_pool();
              if ( v43->i_pool.i_count )
              {
                v48 = v43->i_pool.i_count - 1;
                v43->i_pool.i_count = v48;
                v46 = v48;
                v47 = v43->i_pool.i_array_p;
              }
              else
              {
                if ( !v43->i_exp_pool.i_count )
                  AObjReusePool<SSBoolean>::append_block(v43, v43->i_expand_size);
                v44 = v43->i_exp_pool.i_count;
                if ( !v44 )
                {
                  v49 = 0i64;
                  goto LABEL_53;
                }
                v45 = v44 - 1;
                v43->i_exp_pool.i_count = v45;
                v46 = v45;
                v47 = v43->i_exp_pool.i_array_p;
              }
              v49 = (__int64)v47[v46];
LABEL_53:
              *(_QWORD *)(v49 + 32) = v42;
              *(_DWORD *)(v49 + 16) = 1;
              *(_DWORD *)(v49 + 8) = ++SSObjectBase::c_ptr_id_prev;
              v68[3] = v49;
              v50 = Actor->vfptr;
              v51 = ASymbol::create(&result, "set_disguise", 0xFFFFFFFF, ATerm_long);
              ((void (__fastcall *)(UFG::TSActor *, ASymbol *, __int64 *, __int64, _QWORD, _QWORD))v50[1].set_data_by_name)(
                Actor,
                v51,
                v68,
                4i64,
                0i64,
                0i64);
              goto LABEL_54;
            }
            v37 = v36 - 1;
            v35->i_exp_pool.i_count = v37;
            v38 = v37;
            v39 = v35->i_exp_pool.i_array_p;
          }
          v41 = (__int64)v39[v38];
          goto LABEL_45;
        }
        v29 = i_count - 1;
        pool->i_exp_pool.i_count = v29;
        v30 = v29;
        i_array_p = pool->i_exp_pool.i_array_p;
      }
      v33 = (__int64)i_array_p[v30];
      goto LABEL_37;
    }
LABEL_56:
    v52 = this->mSceneSettings;
    v53 = 0;
    for ( m = UFG::GameStatTracker::mspInstance; v53 < v52->mLoadingHintSetupOnStart.size; ++v53 )
    {
      v55 = (__int64)&v52->mLoadingHintSetupOnStart.p[v53];
      if ( *(_DWORD *)v55 )
      {
        if ( *(_DWORD *)v55 == 1 )
        {
          if ( (_S12_6 & 1) == 0 )
          {
            _S12_6 |= 1u;
            UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
            atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
            m = UFG::GameStatTracker::mspInstance;
          }
          v58 = &sGameStatTracker;
          if ( m )
            v58 = m;
          m = v58;
          UFG::GameStatTracker::mspInstance = v58;
          if ( (*((_BYTE *)v58 + 6216) & 1) != 0 )
            continue;
          p_mValue = &v58->mpSnapshots[0]->mStrings[1].mValue;
        }
        else
        {
          if ( (_S12_6 & 1) == 0 )
          {
            _S12_6 |= 1u;
            UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
            atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
            m = UFG::GameStatTracker::mspInstance;
          }
          v59 = &sGameStatTracker;
          if ( m )
            v59 = m;
          m = v59;
          UFG::GameStatTracker::mspInstance = v59;
          if ( (*((_BYTE *)v59 + 6216) & 1) != 0 )
            continue;
          p_mValue = &v59->mpSnapshots[0]->mStrings[2].mValue;
        }
      }
      else
      {
        if ( (_S12_6 & 1) == 0 )
        {
          _S12_6 |= 1u;
          UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
          atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
          m = UFG::GameStatTracker::mspInstance;
        }
        v56 = &sGameStatTracker;
        if ( m )
          v56 = m;
        m = v56;
        UFG::GameStatTracker::mspInstance = v56;
        if ( (*((_BYTE *)v56 + 6216) & 1) != 0 )
          continue;
        p_mValue = &v56->mpSnapshots[0]->mStrings[0].mValue;
      }
      UFG::qString::Set(p_mValue, *(const char **)(v55 + 32), *(_DWORD *)(v55 + 28), 0i64, 0);
      m = UFG::GameStatTracker::mspInstance;
    }
    v60 = this->mSceneSettings;
    v61 = 0;
    if ( v60->mLoadingScreenSetupOnStart.size )
    {
      while ( 1 )
      {
        v62 = (__int64)&v60->mLoadingScreenSetupOnStart.p[v61];
        if ( !*(_DWORD *)v62 )
        {
          if ( (_S12_6 & 1) == 0 )
          {
            _S12_6 |= 1u;
            UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
            atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
            m = UFG::GameStatTracker::mspInstance;
          }
          v63 = &sGameStatTracker;
          if ( m )
            v63 = m;
          m = v63;
          UFG::GameStatTracker::mspInstance = v63;
          if ( (*((_BYTE *)v63 + 6216) & 1) != 0 )
            goto LABEL_98;
          v64 = &v63->mpSnapshots[0]->mStrings[3].mValue;
          goto LABEL_96;
        }
        if ( *(_DWORD *)v62 == 1 )
          break;
        v66 = UFG::GameStatTracker::Instance();
        if ( (*((_BYTE *)v66 + 6216) & 1) == 0 )
        {
          v64 = &v66->mpSnapshots[0]->mStrings[5].mValue;
LABEL_96:
          UFG::qString::Set(v64, *(const char **)(v62 + 32), *(_DWORD *)(v62 + 28), 0i64, 0);
        }
        m = UFG::GameStatTracker::mspInstance;
LABEL_98:
        if ( ++v61 >= v60->mLoadingScreenSetupOnStart.size )
          return;
      }
      if ( (_S12_6 & 1) == 0 )
      {
        _S12_6 |= 1u;
        UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
        atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
        m = UFG::GameStatTracker::mspInstance;
      }
      v65 = &sGameStatTracker;
      if ( m )
        v65 = m;
      m = v65;
      UFG::GameStatTracker::mspInstance = v65;
      if ( (*((_BYTE *)v65 + 6216) & 1) != 0 )
        goto LABEL_98;
      v64 = &v65->mpSnapshots[0]->mStrings[4].mValue;
      goto LABEL_96;
    }
  }
}

// File Line: 1808
// RVA: 0x496FF0
void __fastcall UFG::GameSlice::CleanupSceneLayers(UFG::GameSlice *this)
{
  UFG::SceneSettings *mSceneSettings; // rbp
  unsigned int i; // esi
  __int64 v4; // rdx
  const char *v5; // rdi
  char v6; // bl
  UFG::SceneSettings *v7; // rbp
  unsigned int j; // edi
  __int64 v9; // rbx
  UFG::qBaseTreeRB *Layer; // rax
  UFG::SceneLayer *v11; // rsi
  UFG::SceneSettings *v12; // rbp
  unsigned int k; // esi
  __int64 v14; // rcx
  SSActor *v15; // rbx
  SSObjectBaseVtbl *vfptr; // rdi
  ASymbol *v17; // rax
  SSInstance **v18; // r8
  UFG::SceneSettings *v19; // r15
  int v20; // edi
  UFG::SimObjectCharacter *v21; // r8
  __int64 v22; // rbp
  __int16 m_Flags; // cx
  UFG::TSActorComponent *m_pComponent; // rax
  UFG::TSActor *Actor; // r14
  bool v26; // si
  AObjReusePool<SSBoolean> *pool; // rbx
  unsigned int i_count; // eax
  unsigned int v29; // eax
  __int64 v30; // rcx
  SSBoolean **i_array_p; // rax
  unsigned int v32; // eax
  __int64 v33; // rdx
  bool v34; // si
  AObjReusePool<SSBoolean> *v35; // rbx
  unsigned int v36; // eax
  unsigned int v37; // eax
  __int64 v38; // rcx
  SSBoolean **v39; // rax
  unsigned int v40; // eax
  __int64 v41; // rdx
  SSObjectBaseVtbl *v42; // rbx
  ASymbol *v43; // rax
  UFG::SceneSettings *v44; // rsi
  unsigned int v45; // edi
  UFG::GameStatTracker *v46; // rcx
  __int64 v47; // rbx
  UFG::GameStatTracker *v48; // rax
  UFG::qString *p_mValue; // rcx
  UFG::GameStatTracker *v50; // rax
  UFG::GameStatTracker *v51; // rax
  UFG::SceneSettings *v52; // rsi
  unsigned int m; // edi
  __int64 v54; // rbx
  UFG::GameStatTracker *v55; // rax
  UFG::qString *v56; // rcx
  UFG::GameStatTracker *v57; // rax
  UFG::GameStatTracker *v58; // rax
  __int64 v59; // [rsp+30h] [rbp-68h]
  __int64 v60[12]; // [rsp+38h] [rbp-60h] BYREF
  ASymbol result; // [rsp+A0h] [rbp+8h] BYREF
  ASymbol v62; // [rsp+A8h] [rbp+10h] BYREF
  SSInstance *v63; // [rsp+B0h] [rbp+18h] BYREF
  SSInstance *v64; // [rsp+B8h] [rbp+20h] BYREF

  v59 = -2i64;
  mSceneSettings = this->mSceneSettings;
  if ( mSceneSettings )
  {
    for ( i = 0; i < mSceneSettings->mAltLayerSetupOnEnd.size; ++i )
    {
      v4 = (__int64)&mSceneSettings->mAltLayerSetupOnEnd.p[i];
      v5 = *(const char **)(v4 + 24);
      v6 = *(_BYTE *)(v4 + 41);
      UFG::SectionLayout::SetLayerActive(v5, v6);
      UFG::SectionChooser::FlushAltLayer(v5, v6);
    }
    v7 = this->mSceneSettings;
    for ( j = 0; j < v7->mLayerSetupOnEnd.size; ++j )
    {
      v9 = (__int64)&v7->mLayerSetupOnEnd.p[j];
      Layer = UFG::Scene::FindOrCreateLayer(&UFG::Scene::msDefault, (UFG::qSymbol *)v9);
      v11 = (UFG::SceneLayer *)Layer;
      if ( Layer )
      {
        if ( *(_BYTE *)(v9 + 4) )
        {
          UFG::SceneLayer::EnableGeographical((UFG::SceneLayer *)Layer, 1, PERSISTENT);
          UFG::SceneLayer::EnableAutoActivate(v11, *(_BYTE *)(v9 + 6), PERSISTENT);
        }
        UFG::SceneLayer::EnableActivate(v11, *(_BYTE *)(v9 + 7), PERSISTENT, 0);
      }
    }
    v12 = this->mSceneSettings;
    for ( k = 0; k < v12->mVendorSetupOnEnd.size; ++k )
    {
      v14 = (__int64)&v12->mVendorSetupOnEnd.p[k];
      if ( *(_BYTE *)(v14 + 4) )
      {
        v63 = SSSymbol::as_instance((ASymbol *)v14);
        v15 = SkookumScript::c_world_p;
        vfptr = SkookumScript::c_world_p->vfptr;
        v17 = ASymbol::create(&result, "enable_vendor_by_type", 0xFFFFFFFF, ATerm_long);
        v18 = &v63;
      }
      else
      {
        v64 = SSSymbol::as_instance((ASymbol *)v14);
        v15 = SkookumScript::c_world_p;
        vfptr = SkookumScript::c_world_p->vfptr;
        v17 = ASymbol::create(&v62, "disable_vendor_by_type", 0xFFFFFFFF, ATerm_long);
        v18 = &v64;
      }
      ((void (__fastcall *)(SSActor *, ASymbol *, SSInstance **, __int64, _QWORD, _QWORD, __int64))vfptr[1].set_data_by_name)(
        v15,
        v17,
        v18,
        1i64,
        0i64,
        0i64,
        v59);
    }
    v19 = this->mSceneSettings;
    v20 = 0;
    if ( v19->mDisguiseSetupOnEnd.size )
    {
      v21 = LocalPlayer;
      while ( 1 )
      {
        v22 = (__int64)&v19->mDisguiseSetupOnEnd.p[v20];
        if ( !v21 )
          goto LABEL_47;
        m_Flags = v21->m_Flags;
        if ( (m_Flags & 0x4000) != 0 )
        {
          m_pComponent = (UFG::TSActorComponent *)v21->m_Components.p[4].m_pComponent;
        }
        else if ( m_Flags >= 0 )
        {
          if ( (m_Flags & 0x2000) != 0 )
          {
            m_pComponent = (UFG::TSActorComponent *)v21->m_Components.p[3].m_pComponent;
          }
          else if ( (m_Flags & 0x1000) != 0 )
          {
            m_pComponent = (UFG::TSActorComponent *)v21->m_Components.p[2].m_pComponent;
          }
          else
          {
            m_pComponent = (UFG::TSActorComponent *)UFG::SimObject::GetComponentOfType(
                                                      v21,
                                                      UFG::TSActorComponent::_TypeUID);
            v21 = LocalPlayer;
          }
        }
        else
        {
          m_pComponent = (UFG::TSActorComponent *)v21->m_Components.p[4].m_pComponent;
        }
        if ( !m_pComponent )
          goto LABEL_47;
        Actor = UFG::TSActorComponent::GetActor(m_pComponent);
        if ( Actor )
          break;
LABEL_46:
        v21 = LocalPlayer;
LABEL_47:
        if ( ++v20 >= v19->mDisguiseSetupOnEnd.size )
          goto LABEL_48;
      }
      v26 = *(_BYTE *)(v22 + 4) == 0;
      pool = SSBoolean::get_pool();
      if ( pool->i_pool.i_count )
      {
        v32 = pool->i_pool.i_count - 1;
        pool->i_pool.i_count = v32;
        v30 = v32;
        i_array_p = pool->i_pool.i_array_p;
      }
      else
      {
        if ( !pool->i_exp_pool.i_count )
          AObjReusePool<SSBoolean>::append_block(pool, pool->i_expand_size);
        i_count = pool->i_exp_pool.i_count;
        if ( !i_count )
        {
          v33 = 0i64;
LABEL_37:
          *(_QWORD *)(v33 + 32) = v26;
          *(_DWORD *)(v33 + 16) = 1;
          *(_DWORD *)(v33 + 8) = ++SSObjectBase::c_ptr_id_prev;
          v60[0] = v33;
          v34 = *(_BYTE *)(v22 + 5) == 0;
          v35 = SSBoolean::get_pool();
          if ( v35->i_pool.i_count )
          {
            v40 = v35->i_pool.i_count - 1;
            v35->i_pool.i_count = v40;
            v38 = v40;
            v39 = v35->i_pool.i_array_p;
          }
          else
          {
            if ( !v35->i_exp_pool.i_count )
              AObjReusePool<SSBoolean>::append_block(v35, v35->i_expand_size);
            v36 = v35->i_exp_pool.i_count;
            if ( !v36 )
            {
              v41 = 0i64;
              goto LABEL_45;
            }
            v37 = v36 - 1;
            v35->i_exp_pool.i_count = v37;
            v38 = v37;
            v39 = v35->i_exp_pool.i_array_p;
          }
          v41 = (__int64)v39[v38];
LABEL_45:
          *(_QWORD *)(v41 + 32) = v34;
          *(_DWORD *)(v41 + 16) = 1;
          *(_DWORD *)(v41 + 8) = ++SSObjectBase::c_ptr_id_prev;
          v60[1] = v41;
          v42 = Actor->vfptr;
          v43 = ASymbol::create(&result, "remove_disguise", 0xFFFFFFFF, ATerm_long);
          ((void (__fastcall *)(UFG::TSActor *, ASymbol *, __int64 *, __int64, _QWORD, _QWORD))v42[1].set_data_by_name)(
            Actor,
            v43,
            v60,
            2i64,
            0i64,
            0i64);
          goto LABEL_46;
        }
        v29 = i_count - 1;
        pool->i_exp_pool.i_count = v29;
        v30 = v29;
        i_array_p = pool->i_exp_pool.i_array_p;
      }
      v33 = (__int64)i_array_p[v30];
      goto LABEL_37;
    }
LABEL_48:
    v44 = this->mSceneSettings;
    v45 = 0;
    if ( v44->mLoadingHintSetupOnEnd.size )
    {
      v46 = UFG::GameStatTracker::mspInstance;
      do
      {
        v47 = (__int64)&v44->mLoadingHintSetupOnEnd.p[v45];
        if ( *(_DWORD *)v47 )
        {
          if ( *(_DWORD *)v47 == 1 )
          {
            if ( (_S12_6 & 1) == 0 )
            {
              _S12_6 |= 1u;
              UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
              atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
              v46 = UFG::GameStatTracker::mspInstance;
            }
            v50 = &sGameStatTracker;
            if ( v46 )
              v50 = v46;
            v46 = v50;
            UFG::GameStatTracker::mspInstance = v50;
            if ( (*((_BYTE *)v50 + 6216) & 1) != 0 )
              goto LABEL_71;
            p_mValue = &v50->mpSnapshots[0]->mStrings[1].mValue;
          }
          else
          {
            if ( (_S12_6 & 1) == 0 )
            {
              _S12_6 |= 1u;
              UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
              atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
              v46 = UFG::GameStatTracker::mspInstance;
            }
            v51 = &sGameStatTracker;
            if ( v46 )
              v51 = v46;
            v46 = v51;
            UFG::GameStatTracker::mspInstance = v51;
            if ( (*((_BYTE *)v51 + 6216) & 1) != 0 )
              goto LABEL_71;
            p_mValue = &v51->mpSnapshots[0]->mStrings[2].mValue;
          }
        }
        else
        {
          if ( (_S12_6 & 1) == 0 )
          {
            _S12_6 |= 1u;
            UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
            atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
            v46 = UFG::GameStatTracker::mspInstance;
          }
          v48 = &sGameStatTracker;
          if ( v46 )
            v48 = v46;
          v46 = v48;
          UFG::GameStatTracker::mspInstance = v48;
          if ( (*((_BYTE *)v48 + 6216) & 1) != 0 )
            goto LABEL_71;
          p_mValue = &v48->mpSnapshots[0]->mStrings[0].mValue;
        }
        UFG::qString::Set(p_mValue, *(const char **)(v47 + 32), *(_DWORD *)(v47 + 28), 0i64, 0);
        v46 = UFG::GameStatTracker::mspInstance;
LABEL_71:
        ++v45;
      }
      while ( v45 < v44->mLoadingHintSetupOnEnd.size );
    }
    v52 = this->mSceneSettings;
    for ( m = 0; m < v52->mLoadingScreenSetupOnEnd.size; ++m )
    {
      v54 = (__int64)&v52->mLoadingScreenSetupOnEnd.p[m];
      if ( *(_DWORD *)v54 )
      {
        if ( *(_DWORD *)v54 == 1 )
        {
          v57 = UFG::GameStatTracker::Instance();
          if ( (*((_BYTE *)v57 + 6216) & 1) == 0 )
          {
            v56 = &v57->mpSnapshots[0]->mStrings[4].mValue;
            goto LABEL_81;
          }
        }
        else
        {
          v58 = UFG::GameStatTracker::Instance();
          if ( (*((_BYTE *)v58 + 6216) & 1) == 0 )
          {
            v56 = &v58->mpSnapshots[0]->mStrings[5].mValue;
            goto LABEL_81;
          }
        }
      }
      else
      {
        v55 = UFG::GameStatTracker::Instance();
        if ( (*((_BYTE *)v55 + 6216) & 1) == 0 )
        {
          v56 = &v55->mpSnapshots[0]->mStrings[3].mValue;
LABEL_81:
          UFG::qString::Set(v56, *(const char **)(v54 + 32), *(_DWORD *)(v54 + 28), 0i64, 0);
        }
      }
    }
  }
}

// File Line: 1915
// RVA: 0x4BEB80
void __fastcall UFG::GameSlice::ShutdownScript(
        UFG::GameSlice *this,
        UFG::GameSlice::CompletionStatus status,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7)
{
  SSInstance *v9; // rax
  UFG::SSGameSlice *mScript; // rsi
  UFG::ProgressionTracker *v11; // rax
  UFG::ProgressionTracker *v12; // rax
  __int64 v13; // [rsp+40h] [rbp+8h] BYREF

  if ( this->mScript )
  {
    if ( !this->mpParent && this->mType == 8 )
      UFG::UITiledMapRaceSplines::Clear(UFG::UIHKScreenHud::RacePath);
    UFG::qPrintChannel::Print(
      &UFG::gPrintChannel_HK_Progression,
      OUTPUT_LEVEL_DEBUG,
      "[Progression]: ShutdownScript for (%s)\n");
    v9 = this->mScript->vfptr->get_data_by_name(&this->mScript->SSActor, &qSymbol_i_is_gameslice_completed);
    v13 = 0i64;
    v9->i_user_data = status == 2;
    ((void (__fastcall *)(SSActor *, UFG::qStaticSymbol *, __int64 *, _QWORD, _QWORD, _QWORD))this->mScript->vfptr[1].set_data_by_name)(
      &this->mScript->SSActor,
      &qSymbol_gameslice_cleanup_private,
      &v13,
      0i64,
      0i64,
      0i64);
    UFG::GameSlice::ReturnAllAmbientActors(this);
    mScript = this->mScript;
    this->mScript = 0i64;
    this->mCleanupPending = CLEANUP_SCRIPT_PENDING;
    SSActor::enable_behavior(&mScript->SSActor, 0);
    if ( !this->mpParent )
      mScript->SSActor::SSDataInstance::SSInstance::SSObjectBase::vfptr->set_data_by_name(
        &mScript->SSActor,
        (ASymbol *)&qSymbol_i_gameslice_data,
        SSBrain::c_nil_p);
    UFG::GameSliceStreamer::DeferScriptDelete(UFG::GameSliceStreamer::mspInstance, mScript);
    if ( this->mCleanupPending )
    {
      v11 = UFG::ProgressionTracker::Instance();
      UFG::ProgressionTracker::MarkCleanup(v11);
    }
    v12 = UFG::ProgressionTracker::Instance();
    UFG::ObjectiveTracker::OnGameSliceCleanup(&v12->mObjectiveTracker, this);
  }
  UFG::GameSliceStreamer::CancelStream(UFG::GameSliceStreamer::mspInstance, this);
}

// File Line: 1986
// RVA: 0x49DD90
void __fastcall UFG::GameSlice::End(
        UFG::GameSlice *this,
        UFG::GameSlice::CompletionStatus status,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7)
{
  bool v7; // zf
  __int64 mType; // rbx
  UFG::ProgressionTracker *v11; // rax
  __int64 v12; // rbx
  UFG::ProgressionTracker *v13; // rax
  __int64 v14; // r8
  UFG::GameSlice *mpActiveMaster; // r9
  __int64 v16; // rax
  UFG::ProgressionTracker *v17; // rax
  UFG::ProgressionTracker *v18; // rax
  UFG::qBaseTreeRB *Layer; // rax
  UFG::qSymbol name; // [rsp+38h] [rbp+10h] BYREF

  v7 = this->mCountedStats == 0;
  this->mCompletionStatus = status;
  this->mCompletionStatusTimestamp = UFG::Metrics::msInstance.mSimTimeMSec;
  if ( !v7 )
  {
    UFG::qPrintChannel::Print(
      &UFG::gPrintChannel_HK_Progression,
      OUTPUT_LEVEL_DEBUG,
      "[Progression]: ScriptObjective ending for (%s)\n");
    UFG::ProgressionTracker::Instance();
    mType = this->mType;
    v11 = UFG::ProgressionTracker::Instance();
    --v11->gActiveGameSlices[mType];
    if ( !this->mpParent && this->mType > TYPE_CULL )
    {
      UFG::ProgressionTracker::Instance();
      v12 = this->mType;
      v13 = UFG::ProgressionTracker::Instance();
      --v13->gActiveContainers[v12];
    }
    this->mCountedStats = 0;
  }
  UFG::ProgressionTriggerComponent::DisableTrigger(this, 0);
  if ( this->mScript )
  {
    if ( (unsigned int)(status - 2) <= 1 )
      UFG::GameStatAction::GameSliceAction::Stop(this, status == 2);
    if ( status == 2 && !this->mpParent )
    {
      v16 = this->mType;
      if ( (int)v16 > 0 )
      {
        if ( gGameSliceTypePriority[v16] >= CONTENTPRIORITY_EVENT )
        {
          v17 = UFG::ProgressionTracker::Instance();
          v17->mContainerCompleted = 1;
          v17->mContainerCompletedTimestamp = UFG::Metrics::msInstance.mSimTimeMSec + 10;
        }
        UFG::GameSlice::_HandleCompletionRewards(this, ShowReward);
        mpActiveMaster = UFG::ProgressionTracker::Instance()->mpActiveMaster;
        if ( mpActiveMaster == this )
        {
          UFG::qPrintChannel::Print(
            &UFG::gPrintChannel_HK_Snapshot,
            OUTPUT_LEVEL_NORMAL,
            "[GameSnapshot]: *** CompletedGameSlice called (%s) called *** \n");
          v18 = UFG::ProgressionTracker::Instance();
          if ( v18->mActiveMasterMode )
          {
            *(_WORD *)&v18->mMasterModeChanged = 257;
            v18->mActiveMasterMode = ActiveMasterMode_OpenWorld;
          }
        }
      }
    }
    UFG::GameSlice::ShutdownScript(this, status, v14, (__int64)mpActiveMaster, a5, a6, a7);
  }
  else if ( this->mLayerEnabledByMe )
  {
    name.mUID = this->mLayerName.mUID;
    this->mLayerEnabledByMe = 0;
    Layer = UFG::Scene::FindLayer(&UFG::Scene::msDefault, &name);
    if ( Layer )
      UFG::SceneLayer::EnableActivate((UFG::SceneLayer *)Layer, 0, PERSISTENT, 0);
  }
}

// File Line: 2118
// RVA: 0x152C090
__int64 UFG::_dynamic_initializer_for__gGameSliceName_M_VE__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("M_VE", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::gGameSliceName_M_VE, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gGameSliceName_M_VE__);
}

// File Line: 2121
// RVA: 0x4C92B0
void __fastcall UFG::GameSlice::_HandleCompletionRewards(UFG::GameSlice *this, UFG::ShowRewardType showRewardType)
{
  UFG::GameSlice *mpParent; // rax
  UFG::ProgressionTracker *v5; // rax
  UFG::qPropertySet *v6; // rbx
  UFG::qPropertySet *PropertySet; // rax
  UFG::qPropertySet *RewardsProperties; // rax
  signed int i; // ebx
  UFG::GameSlice *v10; // rcx
  UFG::qSymbol v11; // [rsp+20h] [rbp-18h] BYREF
  UFG::qSymbol propSetName; // [rsp+50h] [rbp+18h] BYREF
  UFG::qSymbol result; // [rsp+58h] [rbp+20h] BYREF

  if ( UFG::ProgressionTracker::Instance()->mModeType == ModeType_Challenge )
    return;
  if ( showRewardType == ShowReward
    && gGameSliceTypePriority[this->mType] >= CONTENTPRIORITY_EVENT
    && ((mpParent = this->mpParent) != 0i64 && mpParent->mAutosave || this->mAutosave) )
  {
    UFG::ProgressionTracker::Instance()->mpAutoSaveQueuedSlice = this;
  }
  v5 = UFG::ProgressionTracker::Instance();
  UFG::ProgressionTracker::SetLastCompleted(v5, this);
  if ( this->mNode.mUID == UFG::gGameSliceName_M_VE.mUID )
  {
    if ( showRewardType == DoNotShowReward )
    {
      UFG::qSymbol::create_from_string(&result, "default-rewards-progression-M_VEM");
      UFG::qSymbol::create_from_string(&v11, "default-rewards-progression-M_VEF");
      propSetName.mUID = result.mUID;
      v6 = 0i64;
      if ( UFG::PropertySetManager::FindPropertySet(&propSetName) )
        PropertySet = UFG::PropertySetManager::GetPropertySet(&propSetName);
      else
        PropertySet = 0i64;
      UFG::RewardsHandler::HandleRewards(DoNotShowReward, PropertySet, 0i64);
      propSetName.mUID = v11.mUID;
      if ( UFG::PropertySetManager::FindPropertySet(&propSetName) )
        v6 = UFG::PropertySetManager::GetPropertySet(&propSetName);
      UFG::RewardsHandler::HandleRewards(DoNotShowReward, v6, 0i64);
      return;
    }
  }
  else
  {
    RewardsProperties = UFG::GameSlice::GetRewardsProperties(this);
    UFG::RewardsHandler::HandleRewards(showRewardType, RewardsProperties, 0i64);
  }
  if ( showRewardType == ShowReward )
  {
    for ( i = 0; i < (signed int)this->mReEnableSlices.mCount; ++i )
    {
      v10 = this->mReEnableSlices.mppArray[i];
      if ( v10 && v10->mState == STATE_COMPLETED )
        UFG::GameSlice::ForceLock(v10, 0);
    }
  }
}

// File Line: 2189
// RVA: 0x4C9960
void __fastcall UFG::GameSlice::_SimulateUnlock(UFG::GameSlice *this, bool simulateRewards)
{
  __int64 mCount; // rax
  UFG::GameSlice **mppArray; // r14
  UFG::GameSlice **i; // r15
  UFG::GameSlice *v7; // rdi
  __int64 v8; // rax
  UFG::GameSlice **v9; // rbx
  UFG::GameSlice **j; // rsi
  __int64 v11; // rax
  UFG::GameSlice **v12; // rbx
  UFG::GameSlice **k; // rsi
  bool v14; // zf
  UFG::GameSlice **v15; // rax
  __int64 v16; // rbx
  UFG::GameSlice *v17; // rsi
  __int64 v18; // rdi
  __int64 v19; // r14
  __int64 v20; // rdi

  mCount = (int)this->mDependents.mCount;
  if ( (_DWORD)mCount )
  {
    mppArray = this->mDependents.mppArray;
    for ( i = &mppArray[mCount]; mppArray < i; v7->mDirty = 1 )
    {
      v7 = *mppArray;
      v8 = (int)(*mppArray)->mDependents.mCount;
      if ( (_DWORD)v8 )
      {
        v9 = v7->mDependents.mppArray;
        for ( j = &v9[v8]; v9 < j; ++v9 )
        {
          if ( (*v9)->mState != STATE_COMPLETED )
            UFG::GameSlice::_SimulateComplete(*v9, simulateRewards);
        }
      }
      v11 = (int)v7->mChildren.mCount;
      if ( (_DWORD)v11 )
      {
        v12 = v7->mChildren.mppArray;
        for ( k = &v12[v11]; v12 < k; ++v12 )
        {
          if ( (*v12)->mState != STATE_COMPLETED )
            UFG::GameSlice::_SimulateComplete(*v12, simulateRewards);
        }
      }
      if ( !v7->mCompletionCount )
      {
        v14 = v7->mState == STATE_COMPLETED;
        v7->mCompletionStatus = 2;
        v7->mCompletionStatusTimestamp = UFG::Metrics::msInstance.mSimTimeMSec;
        if ( !v14 && simulateRewards )
          UFG::GameSlice::_HandleCompletionRewards(v7, DoNotShowReward);
        ++v7->mCompletionCount;
        v7->mState = STATE_COMPLETED;
      }
      ++mppArray;
    }
  }
  if ( this->mChildren.mCount )
  {
    v15 = this->mChildren.mppArray;
    v16 = 0i64;
    v17 = *v15;
    v18 = 0i64;
    v19 = (*v15)->mDependents.mCount;
    if ( (*v15)->mDependents.mCount )
    {
      do
        UFG::GameSlice::_SimulateComplete(v17->mDependents.mppArray[v18++], simulateRewards);
      while ( v18 < v19 );
    }
    v20 = v17->mChildren.mCount;
    if ( v17->mChildren.mCount )
    {
      do
        UFG::GameSlice::_SimulateComplete(v17->mChildren.mppArray[v16++], simulateRewards);
      while ( v16 < v20 );
    }
  }
}

// File Line: 2227
// RVA: 0x4C9810
void __fastcall UFG::GameSlice::_MarkExclusiveChild(UFG::GameSlice *this, UFG::GameSlice *pChild)
{
  UFG::GameSlice **p_mpParent; // rax

  p_mpParent = &this->mpParent;
  for ( this->mExclusiveChild = pChild; *p_mpParent; *(p_mpParent - 14) = pChild )
    p_mpParent = &(*p_mpParent)->mpParent;
}

// File Line: 2239
// RVA: 0x4BD6F0
UFG::GameSlice::SetState

// File Line: 2362
// RVA: 0x4C3F20
void __fastcall UFG::GameSlice::Unlock(UFG::GameSlice *this, UFG::GameSlice::State newState)
{
  UFG::GameSlice::State mState; // eax
  UFG::GameSlice *mpParent; // rcx

  mState = this->mState;
  if ( mState )
  {
    if ( mState == STATE_UNLOCKED )
      UFG::GameSlice::Start(this);
    if ( this->mState > newState )
      newState = this->mState;
    this->mState = newState;
  }
  else
  {
    UFG::ProgressionTracker::Instance()->mDirty = 1;
    mpParent = this->mpParent;
    this->mState = newState;
    if ( mpParent )
      UFG::GameSlice::Unlock(mpParent, STATE_UNLOCKED);
    UFG::GameSlice::Start(this);
  }
}

// File Line: 2397
// RVA: 0x4BC130
void __fastcall UFG::GameSlice::SetEnabled(UFG::GameSlice *this, bool isEnabled)
{
  __int64 mCount; // rbp
  __int64 v3; // rbx

  mCount = this->mChildren.mCount;
  v3 = 0i64;
  this->mEnabled = isEnabled;
  if ( mCount )
  {
    do
      UFG::GameSlice::SetEnabled(this->mChildren.mppArray[v3++], isEnabled);
    while ( v3 < mCount );
  }
}

// File Line: 2433
// RVA: 0x4BDCE0
void __fastcall UFG::GameSlice::SetType(UFG::GameSlice *this, UFG::GameSlice::Type type)
{
  __int64 mCount; // rbp
  __int64 v3; // rbx

  mCount = this->mChildren.mCount;
  v3 = 0i64;
  if ( this->mChildren.mCount )
  {
    do
      UFG::GameSlice::SetType(this->mChildren.mppArray[v3++], type);
    while ( v3 < mCount );
    this->mType = type;
  }
  else
  {
    this->mType = type;
  }
}

// File Line: 2464
// RVA: 0x4967E0
bool __fastcall UFG::GameSlice::CanBeEnabled(UFG::GameSlice *this)
{
  if ( this->mRoot )
    return 1;
  if ( (int)this->mChildren.mCount > 0 )
    this = *this->mChildren.mppArray;
  return UFG::GameSlice::CanDependantsBeEnabled(this);
}

// File Line: 2489
// RVA: 0x4A6070
UFG::qPropertySet *__fastcall UFG::GameSlice::GetRewardsProperties(UFG::GameSlice *this)
{
  UFG::qPropertySet *result; // rax

  if ( this->mpParent
    || this->mType <= TYPE_CULL
    || this->mCompletionCount <= 1 && UFG::ProgressionTracker::Instance()->mModeType != ModeType_Challenge
    || (UFG::PropertySetHandle::Bind(&this->mRepeatedRewardsProperties),
        (result = this->mRepeatedRewardsProperties.mpPropSet) == 0i64) )
  {
    UFG::PropertySetHandle::Bind(&this->mRewardsProperties);
    return this->mRewardsProperties.mpPropSet;
  }
  return result;
}

// File Line: 2528
// RVA: 0x499F00
void __fastcall UFG::GameSlice::CreateRuntimeRewardsPropertySets(UFG::GameSlice *this)
{
  UFG::qPropertySet *v2; // rsi
  UFG::qString *v3; // rax
  UFG::qPropertySet *v4; // rbp
  UFG::qPropertySet *PropertySet; // r14
  UFG::PropertySetHandle *p_mRepeatedRewardsProperties; // rdi
  UFG::qString *v7; // rax
  UFG::qPropertySet *v8; // rbx
  UFG::qString result; // [rsp+28h] [rbp-40h] BYREF
  UFG::qSymbol propSetName; // [rsp+70h] [rbp+8h] BYREF
  UFG::qSymbol name; // [rsp+78h] [rbp+10h] BYREF

  v2 = 0i64;
  if ( !UFG::PropertySetHandle::IsValid(&this->mRewardsProperties) )
  {
    v3 = UFG::qString::FormatEx(&result, "default-rewards-progression-%s", this->mName.mText);
    UFG::qSymbol::create_from_string(&propSetName, v3->mData);
    UFG::qString::~qString(&result);
    v4 = 0i64;
    PropertySet = UFG::PropertySetManager::FindPropertySet(&propSetName);
    if ( PropertySet )
    {
      UFG::qSymbol::create_suffix((UFG::qWiseSymbol *)&name, &propSetName, "_runtime");
      v4 = UFG::qPropertySet::CreateContainedSet(&name, "GameSlice");
      UFG::PSWrapper::AppendParentLocal(v4, PropertySet);
      UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&name);
      UFG::qPrintChannel::Print(
        &UFG::gPrintChannel_HK_Progression,
        OUTPUT_LEVEL_DEBUG,
        "[GameSlice]: Created runtime reward property set (%s)\n");
    }
    UFG::PropertySetHandle::SetPropSet(&this->mRewardsProperties, v4);
  }
  p_mRepeatedRewardsProperties = &this->mRepeatedRewardsProperties;
  if ( !UFG::PropertySetHandle::IsValid(&this->mRepeatedRewardsProperties) )
  {
    v7 = UFG::qString::FormatEx(&result, "default-rewards-progression-%s_repeat", this->mName.mText);
    UFG::qSymbol::create_from_string(&propSetName, v7->mData);
    UFG::qString::~qString(&result);
    v8 = UFG::PropertySetManager::FindPropertySet(&propSetName);
    if ( v8 )
    {
      UFG::qSymbol::create_suffix((UFG::qWiseSymbol *)&name, &propSetName, "_runtime");
      v2 = UFG::qPropertySet::CreateContainedSet(&name, "GameSlice");
      UFG::PSWrapper::AppendParentLocal(v2, v8);
      UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&name);
      UFG::qPrintChannel::Print(
        &UFG::gPrintChannel_HK_Progression,
        OUTPUT_LEVEL_DEBUG,
        "[GameSlice]: Created runtime reward property set (%s)\n");
    }
    UFG::PropertySetHandle::SetPropSet(p_mRepeatedRewardsProperties, v2);
  }
}

// File Line: 2543
// RVA: 0x496820
__int64 __fastcall UFG::GameSlice::CanDependantsBeEnabled(UFG::GameSlice *this)
{
  __int64 result; // rax
  __int64 v3; // rbx
  unsigned __int8 v4; // di
  bool CanBeEnabled; // al

  result = this->mDependents.mCount;
  if ( (_DWORD)result )
  {
    v3 = 0i64;
    v4 = 1;
    if ( (int)result > 0 )
    {
      do
      {
        CanBeEnabled = UFG::GameSlice::CanBeEnabled(this->mDependents.mppArray[v3]);
        v3 = (unsigned int)(v3 + 1);
        v4 &= CanBeEnabled;
      }
      while ( (int)v3 < (signed int)this->mDependents.mCount );
    }
    return v4;
  }
  return result;
}

// File Line: 2563
// RVA: 0x4C91A0
__int64 __fastcall UFG::WillContainerCompleteIfIComplete(UFG::GameSlice *pContainer, UFG::GameSlice *pMySelf)
{
  __int64 mCount; // r9
  unsigned __int8 v4; // r8
  UFG::GameSlice **mppArray; // rcx
  UFG::GameSlice *v6; // rax
  int mState; // edx

  mCount = pContainer->mChildren.mCount;
  v4 = 1;
  if ( pContainer->mChildren.mCount )
  {
    mppArray = pContainer->mChildren.mppArray;
    do
    {
      v6 = *mppArray;
      mState = (*mppArray)->mState;
      if ( mState >= 1 || v6->mCompletionCount > 0 )
      {
        if ( mState != 8 && !v6->mOptional && v6 != pMySelf )
          v4 = 0;
      }
      else if ( !v6->mOptional )
      {
        v4 = 0;
      }
      ++mppArray;
      --mCount;
    }
    while ( mCount );
  }
  return v4;
}

// File Line: 2594
// RVA: 0x499710
void __fastcall UFG::GameSlice::CompleteSlice(UFG::GameSlice *this)
{
  unsigned int v2; // esi
  UFG::GameSlice *v3; // rdi
  __int64 v4; // rbp
  __int64 mCount; // r14
  UFG::SSGameSlice *mScript; // rcx
  UFG::SSGameSlice *v7; // rcx
  UFG::GameSlice::State mState; // edi
  UFG::GameSlice *mpParent; // rcx
  UFG::GameSlice *v10; // rcx
  SSInstance *args_pp; // [rsp+88h] [rbp+10h] BYREF

  v2 = _S19_1;
  if ( (_S19_1 & 1) == 0 )
  {
    _S19_1 |= 1u;
    UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
    atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
    v2 = _S19_1;
  }
  UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
  if ( dword_14240B994 != 2 )
    goto LABEL_21;
  v3 = this;
  if ( this )
  {
    while ( v3->mpParent )
      v3 = v3->mpParent;
  }
  if ( !UFG::WillContainerCompleteIfIComplete(v3, this) )
    goto LABEL_21;
  v4 = 0i64;
  mCount = v3->mChildren.mCount;
  if ( v3->mChildren.mCount )
  {
    do
    {
      mScript = v3->mChildren.mppArray[v4]->mScript;
      if ( mScript )
        SSActor::suspend_coroutines(&mScript->SSActor);
      ++v4;
    }
    while ( v4 < mCount );
    v2 = _S19_1;
  }
  v7 = v3->mScript;
  if ( v7 )
  {
    SSActor::suspend_coroutines(&v7->SSActor);
    v2 = _S19_1;
  }
  if ( this->mScript )
  {
    if ( (v2 & 1) == 0 )
    {
      _S19_1 = v2 | 1;
      UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
      atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
    }
    UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
    if ( v3 == (UFG::GameSlice *)qword_14240B6D0 )
    {
      args_pp = 0i64;
      SSInstance::coroutine_call(
        &this->mScript->SSActor,
        (ASymbol *)&qSymbol__gameslice_challenge_success_handler_private,
        &args_pp,
        0,
        0,
        0.0,
        0i64,
        0i64);
    }
    ++this->mCompletionCount;
  }
  else
  {
LABEL_21:
    mState = this->mState;
    if ( mState != STATE_COMPLETED )
    {
      if ( (v2 & 1) == 0 )
      {
        _S19_1 = v2 | 1;
        UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
        atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
      }
      UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
      byte_14240B986 = 1;
      if ( this->mScript )
        UFG::ProgressionTriggerComponent::DisableTrigger(this, 1);
      this->mState = STATE_COMPLETED;
      ++this->mCompletionCount;
      UFG::GameSlice::End(this, (UFG::GameSlice::CompletionStatus)2);
      if ( this->mExclusive || this->mRandomExclusive )
      {
        if ( ((mState - 2) & 0xFFFFFFFD) == 0 && this->mExclusiveChild == this )
        {
          this->mExclusiveChild = 0i64;
          mpParent = this->mpParent;
          if ( mpParent )
            UFG::GameSlice::_MarkExclusiveChild(mpParent, 0i64);
        }
        if ( this->mState == STATE_STARTED )
        {
          this->mExclusiveChild = this;
          v10 = this->mpParent;
          if ( v10 )
            UFG::GameSlice::_MarkExclusiveChild(v10, this);
          this->mRequiresSave = 0;
        }
        if ( this->mState == STATE_COMPLETED && this->mExclusive && this->mPersistent )
          this->mRequiresSave = 1;
      }
    }
  }
}

// File Line: 2641
// RVA: 0x4A01C0
void __fastcall UFG::GameSlice::FailSlice(UFG::GameSlice *this, UFG::qString *caption)
{
  UFG::GameStatTracker *v4; // rax
  UFG::GameStatTracker *v5; // rbx
  UFG::SSGameSlice *mScript; // rbx
  SSObjectBaseVtbl *vfptr; // rdi
  AString *v8; // rax
  SSInstance *v9; // rax
  AStringRef *i_str_ref_p; // rbx
  AObjReusePool<AStringRef> *pool; // rax
  AObjBlock<AStringRef> *i_block_p; // rcx
  unsigned __int64 i_objects_a; // rdx
  bool v15; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_exp_pool; // rcx
  AString v17; // [rsp+60h] [rbp+8h] BYREF

  if ( this->mScript )
  {
    if ( (_S19_1 & 1) == 0 )
    {
      _S19_1 |= 1u;
      UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
      atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
    }
    UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
    if ( dword_14240B994 != 2 )
    {
      v4 = UFG::GameStatTracker::Instance();
      if ( (*((_BYTE *)v4 + 6216) & 1) == 0 )
      {
        UFG::PersistentData::MapInt::ApplyDelta(v4->mpSnapshots[0]->mpMapInts[36], (UFG::qSymbol *)&this->mNode.mUID, 1);
        if ( UFG::GameStatAction::PostStat::sIsEnabled )
        {
          v5 = &sGameStatTracker;
          if ( (_S12_6 & 1) == 0 )
          {
            _S12_6 |= 1u;
            UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
            atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
          }
          if ( UFG::GameStatTracker::mspInstance )
            v5 = UFG::GameStatTracker::mspInstance;
          UFG::GameStatTracker::mspInstance = v5;
        }
      }
    }
    AString::AString(&v17, caption->mData, 0);
    mScript = this->mScript;
    vfptr = mScript->SSActor::SSDataInstance::SSInstance::SSObjectBase::vfptr;
    v9 = SSString::as_instance(v8);
    vfptr->set_data_by_name(&mScript->SSActor, (ASymbol *)&qSymbol_i_gameslice_fail_caption, v9);
    i_str_ref_p = v17.i_str_ref_p;
    if ( v17.i_str_ref_p->i_ref_count-- == 1 )
    {
      if ( i_str_ref_p->i_deallocate )
        AMemory::c_free_func(i_str_ref_p->i_cstr_p);
      pool = AStringRef::get_pool();
      i_block_p = pool->i_block_p;
      i_objects_a = (unsigned __int64)i_block_p->i_objects_a;
      if ( (unsigned __int64)i_str_ref_p < i_objects_a
        || (v15 = (unsigned __int64)i_str_ref_p < i_objects_a + 24i64 * i_block_p->i_size,
            p_i_exp_pool = &pool->i_pool,
            !v15) )
      {
        p_i_exp_pool = &pool->i_exp_pool;
      }
      APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(p_i_exp_pool, i_str_ref_p);
    }
    v17.i_str_ref_p = 0i64;
    SSInstance::coroutine_call(
      &this->mScript->SSActor,
      (ASymbol *)&qSymbol__gameslice_fail_handler_private,
      (SSInstance **)&v17,
      0,
      0,
      0.0,
      0i64,
      0i64);
  }
}

// File Line: 2665
// RVA: 0x4B1670
void __fastcall UFG::GameSlice::OnEnterTrigger(UFG::GameSlice *this, UFG::TriggerRegion *pTriggerRegion)
{
  SSInstance *v3; // rax
  SSActor *v4; // rcx
  SSInstance *args_pp; // [rsp+50h] [rbp+8h] BYREF

  if ( this->mScript )
  {
    v3 = UFG::TSTriggerRegion::AsInstance(pTriggerRegion);
    v4 = &this->mScript->SSActor;
    args_pp = v3;
    SSInstance::coroutine_call(
      v4,
      (ASymbol *)&qSymbol__gameslice_on_enter_trigger_handler,
      &args_pp,
      v3 != 0i64,
      1,
      0.0,
      0i64,
      0i64);
  }
}

// File Line: 2673
// RVA: 0x4B16E0
void __fastcall UFG::GameSlice::OnExitTrigger(UFG::GameSlice *this, UFG::TriggerRegion *pTriggerRegion)
{
  SSInstance *v3; // rax
  SSActor *v4; // rcx
  SSInstance *args_pp; // [rsp+50h] [rbp+8h] BYREF

  if ( this->mScript )
  {
    v3 = UFG::TSTriggerRegion::AsInstance(pTriggerRegion);
    v4 = &this->mScript->SSActor;
    args_pp = v3;
    SSInstance::coroutine_call(
      v4,
      (ASymbol *)&qSymbol__gameslice_on_exit_trigger_handler,
      &args_pp,
      v3 != 0i64,
      1,
      0.0,
      0i64,
      0i64);
  }
}

// File Line: 2681
// RVA: 0x4B1DC0
void __fastcall UFG::GameSlice::OnSafehouseRestore(UFG::GameSlice *this)
{
  SSActor *v2; // rcx
  SSInstance *args_pp; // [rsp+50h] [rbp+8h] BYREF

  if ( this->mScript )
  {
    if ( !this->mIgnoreSafehouseRestore )
    {
      UFG::ProgressionTracker::Instance()->mHoldCurtainPostRestore = 1;
      v2 = &this->mScript->SSActor;
      args_pp = 0i64;
      SSInstance::coroutine_call(
        v2,
        (ASymbol *)&qSymbol__gameslice_on_safehouse_restore,
        &args_pp,
        0,
        1,
        0.0,
        0i64,
        0i64);
    }
  }
}

// File Line: 2690
// RVA: 0x4ABFB0
_BOOL8 __fastcall UFG::GameSlice::IsExclusiveAvailable(UFG::GameSlice *this)
{
  UFG::GameSlice *i; // rax

  for ( i = this->mpParent; i; i = i->mpParent )
    this = i;
  return this->mExclusiveChild == 0i64;
}

// File Line: 2702
// RVA: 0x496CF0
void __fastcall UFG::GameSlice::ClaimExclusive(UFG::GameSlice *this)
{
  UFG::GameSlice *mpParent; // rax

  mpParent = this->mpParent;
  this->mExclusiveChild = this;
  if ( mpParent )
    UFG::GameSlice::_MarkExclusiveChild(mpParent, this);
}

// File Line: 2788
// RVA: 0x4A7210
__int64 __fastcall UFG::GameSlice::GetTypeFromCategoryName(UFG::qString *name)
{
  unsigned int v1; // ebx
  unsigned int v2; // eax

  v1 = 12;
  v2 = UFG::qStringHashUpper32(name->mData, -1);
  if ( v2 > 0x8A81A698 )
  {
    switch ( v2 )
    {
      case 0x93B4E7EE:
        return 6;
      case 0xA33C6BE8:
        return 9i64;
      case 0xBA62800D:
        return 7i64;
      case 0xC6D065B6:
        return 5i64;
    }
  }
  else
  {
    switch ( v2 )
    {
      case 0x8A81A698:
        return 8i64;
      case 0x27CB8660u:
        return 3i64;
      case 0x5DA77C45u:
        return 11i64;
      case 0x5DD40769u:
        return 10i64;
      case 0x6DA7545Bu:
        return 4i64;
      case 0x710834C0u:
        return 1i64;
    }
  }
  return v1;
}

// File Line: 2814
// RVA: 0x4956E0
void __fastcall UFG::GameSlice::BorrowAmbientActor(UFG::GameSlice *this, UFG::SimObjectCharacter *actor)
{
  signed __int16 m_Flags; // dx
  UFG::StreamedResourceComponent *m_pComponent; // rax
  signed __int16 v6; // cx
  UFG::AiDriverComponent *ComponentOfTypeHK; // rax
  UFG::allocator::free_link *v8; // rax
  UFG::SceneObjectProperties *v9; // rdx
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *vfptr; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v12; // rax

  if ( actor )
  {
    m_Flags = actor->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::StreamedResourceComponent *)actor->m_Components.p[10].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = (UFG::StreamedResourceComponent *)actor->m_Components.p[7].m_pComponent;
      }
      else if ( (m_Flags & 0x1000) != 0 )
      {
        m_pComponent = (UFG::StreamedResourceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                           actor,
                                                           UFG::StreamedResourceComponent::_TypeUID);
      }
      else
      {
        m_pComponent = (UFG::StreamedResourceComponent *)UFG::SimObject::GetComponentOfType(
                                                           actor,
                                                           UFG::StreamedResourceComponent::_TypeUID);
      }
    }
    else
    {
      m_pComponent = (UFG::StreamedResourceComponent *)actor->m_Components.p[10].m_pComponent;
    }
    if ( m_pComponent )
      UFG::StreamedResourceComponent::IncrementPriorityReferenceCount(m_pComponent, &qSymbol_Critical);
    v6 = actor->m_Flags;
    if ( (v6 & 0x4000) != 0 || v6 < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(actor);
    }
    else if ( (v6 & 0x2000) != 0 || (v6 & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      actor,
                                                      UFG::AiDriverComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                                      actor,
                                                      UFG::AiDriverComponent::_TypeUID);
    }
    if ( ComponentOfTypeHK )
      ComponentOfTypeHK->m_IsAmbient = 0;
    UFG::PedSpawnManager::GetInstance();
    UFG::PedSpawnManager::AquireOwnership(actor, 0, 1, -1);
    v8 = UFG::qMalloc(0x18ui64, UFG::gGlobalNewName, 0i64);
    v9 = (UFG::SceneObjectProperties *)v8;
    if ( v8 )
    {
      v8->mNext = v8;
      v8[1].mNext = v8;
      v8[2].mNext = 0i64;
    }
    else
    {
      v9 = 0i64;
    }
    if ( v9->m_SafePointerList.mNode.mNext )
    {
      vfptr = v9->vfptr;
      mPrev = v9->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
      vfptr[1].__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int))mPrev;
      mPrev->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)vfptr;
      v9->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)v9;
      v9->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v9;
    }
    v9->m_SafePointerList.mNode.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)actor;
    v12 = actor->m_SafePointerList.UFG::SimObjectCVBase::UFG::SimObjectGame::UFG::SimObject::UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    v12->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)v9;
    v9->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)v12;
    v9->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&actor->m_SafePointerList;
    actor->m_SafePointerList.UFG::SimObjectCVBase::UFG::SimObjectGame::UFG::SimObject::UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)v9;
    qSet<UFG::SceneObjectProperties,UFG::qSymbol,qCompareLogical<UFG::qSymbol>>::Append(
      (qSet<UFG::SceneObjectProperties,UFG::qSymbol,qCompareLogical<UFG::qSymbol> > *)&this->mBorrowedActors,
      v9,
      "qSet::Append");
  }
}

// File Line: 2842
// RVA: 0x4B8110
void __fastcall UFG::GameSlice::ReturnAllAmbientActors(UFG::GameSlice *this)
{
  unsigned int v2; // ebp
  __int64 v3; // rbx
  UFG::SimObjectCharacter *m_pPointer; // rdi
  UFG::SimObjectGame *v5; // rcx
  __int16 m_Flags; // dx
  UFG::StreamedResourceComponent *m_pComponent; // rax

  v2 = 0;
  if ( this->mBorrowedActors.mCount )
  {
    v3 = 0i64;
    do
    {
      m_pPointer = (UFG::SimObjectCharacter *)this->mBorrowedActors.mppArray[v3]->m_pPointer;
      if ( m_pPointer )
      {
        if ( m_pPointer == UFG::GetLocalPlayer() )
          return;
        v5 = (UFG::SimObjectGame *)this->mBorrowedActors.mppArray[v3]->m_pPointer;
        if ( v5 )
        {
          m_Flags = v5->m_Flags;
          if ( (m_Flags & 0x4000) != 0 )
          {
            m_pComponent = (UFG::StreamedResourceComponent *)v5->m_Components.p[10].m_pComponent;
          }
          else if ( m_Flags >= 0 )
          {
            if ( (m_Flags & 0x2000) != 0 )
            {
              m_pComponent = (UFG::StreamedResourceComponent *)v5->m_Components.p[7].m_pComponent;
            }
            else if ( (m_Flags & 0x1000) != 0 )
            {
              m_pComponent = (UFG::StreamedResourceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                 v5,
                                                                 UFG::StreamedResourceComponent::_TypeUID);
            }
            else
            {
              m_pComponent = (UFG::StreamedResourceComponent *)UFG::SimObject::GetComponentOfType(
                                                                 v5,
                                                                 UFG::StreamedResourceComponent::_TypeUID);
            }
          }
          else
          {
            m_pComponent = (UFG::StreamedResourceComponent *)v5->m_Components.p[10].m_pComponent;
          }
          if ( m_pComponent )
            UFG::StreamedResourceComponent::DecrementPriorityReferenceCount(m_pComponent, &qSymbol_Critical);
        }
        UFG::PedSpawnManager::GetInstance();
        UFG::PedSpawnManager::ReleaseOwnership(
          (UFG::SimObjectCharacter *)this->mBorrowedActors.mppArray[v3]->m_pPointer,
          0xFFFFFFFF,
          1);
      }
      ++v2;
      this->mBorrowedActors.mppArray[v3++] = 0i64;
    }
    while ( v2 < this->mBorrowedActors.mCount );
  }
  qSetBase<UFG::qSafePointer<UFG::SimObject,UFG::SimObject>>::FreeAll(&this->mBorrowedActors);
}

// File Line: 2911
// RVA: 0x493550
void __fastcall UFG::GameSliceMasks::AddMask(UFG::GameSliceMasks *this, UFG::qString *sliceName)
{
  char *mData; // rbx
  UFG::qSymbol *v5; // rdi
  UFG::qBaseTreeRB *v6; // rbx
  UFG::allocator::free_link *v7; // rax
  UFG::qBaseTreeRB *v8; // rax
  UFG::qSymbol result; // [rsp+50h] [rbp+8h] BYREF
  UFG::allocator::free_link *v10; // [rsp+58h] [rbp+10h]

  mData = sliceName->mData;
  if ( (_S19_1 & 1) == 0 )
  {
    _S19_1 |= 1u;
    UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
    atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
  }
  UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
  v5 = UFG::qSymbol::create_from_string(&result, mData);
  if ( (!v5->mUID || (v6 = UFG::qBaseTreeRB::Get(&stru_14240A190, v5->mUID)) == 0i64)
    && (!v5->mUID || (v6 = UFG::qBaseTreeRB::Get(&stru_14240A100, v5->mUID)) == 0i64) )
  {
    if ( v5->mUID )
      v6 = UFG::qBaseTreeRB::Get(&stru_14240A148, v5->mUID);
    else
      v6 = 0i64;
  }
  if ( !v6 )
  {
    if ( (_S19_1 & 1) == 0 )
    {
      _S19_1 |= 1u;
      UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
      atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
    }
    UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
    v7 = UFG::qMalloc(0x240ui64, "GameSlice", 0i64);
    v10 = v7;
    if ( v7 )
    {
      UFG::GameSlice::GameSlice((UFG::GameSlice *)v7, sliceName->mData);
      v6 = v8;
    }
    else
    {
      v6 = 0i64;
    }
    UFG::qBaseTreeRB::Add(&stru_14240A190, &v6->mRoot);
    byte_14240B986 = 1;
  }
  qSet<UFG::SceneObjectProperties,UFG::qSymbol,qCompareLogical<UFG::qSymbol>>::Append(
    (qSet<UFG::SceneObjectProperties,UFG::qSymbol,qCompareLogical<UFG::qSymbol> > *)&this->mMasks,
    (UFG::SceneObjectProperties *)v6,
    "GameSliceMasks::AddMask");
}

// File Line: 2927
// RVA: 0x4ACDC0
bool __fastcall UFG::GameSliceMasks::IsSet(UFG::GameSliceMasks *this, UFG::GameSlice *pActiveGameSlice)
{
  UFG::GameSlice::Type mType; // r8d
  __int64 mCount; // r8
  UFG::GameSlice **mppArray; // rax
  UFG::GameSlice **v6; // r8

  mType = TYPE_OCCLUSION;
  if ( pActiveGameSlice )
  {
    if ( pActiveGameSlice->mType != NUM_TYPES )
      mType = pActiveGameSlice->mType;
    if ( this->mEnabledCategory[mType] )
      return 1;
    mCount = (int)this->mMasks.mCount;
    if ( (_DWORD)mCount )
    {
      mppArray = this->mMasks.mppArray;
      v6 = &mppArray[mCount];
      if ( mppArray < v6 )
      {
        while ( *mppArray != pActiveGameSlice )
        {
          if ( ++mppArray >= v6 )
            return 0;
        }
        return 1;
      }
    }
    return 0;
  }
  return this->mEnabledCategory[1];
}

// File Line: 3007
// RVA: 0x4BE910
bool __fastcall UFG::GameSlice::ShouldTeleportOnStart(UFG::GameSlice *this)
{
  UFG::SceneSettings *mSceneSettings; // rax

  mSceneSettings = this->mSceneSettings;
  return mSceneSettings && mSceneSettings->mTeleportMarker.mUID != -1;
}

// File Line: 3012
// RVA: 0x4BE930
bool __fastcall UFG::GameSlice::ShouldTeleportVehicleOnStart(UFG::GameSlice *this)
{
  UFG::SceneSettings *mSceneSettings; // rax

  mSceneSettings = this->mSceneSettings;
  return mSceneSettings && mSceneSettings->mVehicleTeleportMarker.mUID != -1;
}

// File Line: 3017
// RVA: 0x4BE6F0
bool __fastcall UFG::GameSlice::ShouldDestroyVehicleOnStart(UFG::GameSlice *this)
{
  UFG::SceneSettings *mSceneSettings; // rax

  mSceneSettings = this->mSceneSettings;
  return mSceneSettings && mSceneSettings->mVehicleDestroy;
}

