// File Line: 59
// RVA: 0x151BDD0
__int64 UFG::_dynamic_initializer_for__GameSliceTypeSym_CASE__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("CASE", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&GameSliceTypeSym_CASE, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__GameSliceTypeSym_CASE__);
}

// File Line: 196
// RVA: 0x48AA20
void __fastcall UFG::GameSlice::GameSlice(UFG::GameSlice *this, const char *name)
{
  const char *v2; // rbx
  UFG::GameSlice *v3; // rdi
  unsigned int v4; // er8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v5; // rax
  UFG::qList<UFG::MissionWorkStatus,UFG::MissionWorkStatus,1,0> *v6; // rax
  UFG::qSymbol result; // [rsp+50h] [rbp+18h]

  v2 = name;
  v3 = this;
  v4 = UFG::qSymbol::create_from_string(&result, name)->mUID;
  v3->mNode.mParent = 0i64;
  v3->mNode.mChild[0] = 0i64;
  v3->mNode.mChild[1] = 0i64;
  v3->mNode.mUID = v4;
  UFG::qSharedString::qSharedString(&v3->mName, v2);
  UFG::qSharedString::qSharedString(&v3->mTitle);
  UFG::qSharedString::qSharedString(&v3->mScriptClassName);
  v3->mPDATriggerParameters = 0i64;
  UFG::qSharedString::qSharedString(&v3->mNisPath);
  v3->mNisSceneSettings = 0i64;
  *(_WORD *)&v3->mNisPostFadeIn = 1;
  UFG::qSharedString::qSharedString(&v3->mGamePlayState);
  UFG::qSharedString::qSharedString(&v3->mGeoState);
  UFG::qSharedString::qSharedString(&v3->mLightingState);
  UFG::qSharedString::qSharedString(&v3->mMissionFlowState);
  UFG::qSharedString::qSharedString(&v3->mObjectiveBlipState);
  UFG::qSharedString::qSharedString(&v3->mEncounterState);
  UFG::qSharedString::qSharedString(&v3->mAssetState);
  UFG::qSharedString::qSharedString(&v3->mPresentationState);
  UFG::qSharedString::qSharedString(&v3->mAudioOverride);
  UFG::qSharedString::qSharedString(&v3->mSaveGameNameOverride);
  *(_QWORD *)&v3->mLayerName.mUID = -1i64;
  *(_QWORD *)&v3->mRestoreLocationMarker.mUID = -1i64;
  *(_QWORD *)&v3->mRestoreWeapon.mUID = -1i64;
  *(_QWORD *)&v3->mVehicleMarkerRange = -1082130432i64;
  v3->mCompleteLocationMarker.mUID = -1;
  v3->mMinimumDependentsRequired = 0;
  v3->mMaxHeatLevel = -1;
  v3->mMinPipLevel = 0;
  v3->mFaceActionType = 18;
  *(_WORD *)&v3->mAutosave = 257;
  v3->mRepeatableInterval = 0;
  v3->mScriptBinaryFileSize = 0i64;
  v3->mScript = 0i64;
  v3->mExclusiveChild = 0i64;
  v3->mState = 0;
  *(_QWORD *)&v3->mType = 1i64;
  v3->mCompletionStatusTimestamp = 0i64;
  v3->mIsTODRestricted = 0;
  v3->mTODActive = -1.0;
  v3->mTODInactive = -1.0;
  v3->mTODRestore = -1.0;
  *(_DWORD *)&v3->mTODBypassPrompt = 0;
  *(_WORD *)&v3->mDisableCopScoring = 0;
  v3->mFailTimeout = 100i64;
  *(_QWORD *)&v3->mEnabled = 0x10000i64;
  *(_QWORD *)&v3->mHoldCurtain = 0i64;
  *(_DWORD *)&v3->mDeferRestartIfInsideRegion = 1;
  v3->mStatsId = 0;
  v3->mDLCProductId = UFG::gNullQSymbol;
  v3->mSceneSettings = 0i64;
  *(_QWORD *)&v3->mCleanupPending = 0i64;
  v3->mpParent = 0i64;
  *(_QWORD *)&v3->mDependents.mCount = 0i64;
  v3->mDependents.mppArray = 0i64;
  *(_QWORD *)&v3->mChildren.mCount = 0i64;
  v3->mChildren.mppArray = 0i64;
  UFG::PropertySetHandle::PropertySetHandle(&v3->mRewardsProperties);
  UFG::PropertySetHandle::PropertySetHandle(&v3->mRepeatedRewardsProperties);
  v3->mpDependentMission = 0i64;
  v3->mpLastActiveSublice = 0i64;
  v3->mpCollection = 0i64;
  *(_WORD *)&v3->mCollectionHighPriority = 0;
  *(_QWORD *)&v3->mSprinkleCharacter1Override.mUID = -1i64;
  v3->mSubsetModeType.mUID = -1;
  v5 = &v3->mpRestoredVehicle;
  v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v5->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v3->mpRestoredVehicle.m_pPointer = 0i64;
  *(_QWORD *)&v3->mBorrowedActors.mCount = 0i64;
  v3->mBorrowedActors.mppArray = 0i64;
  v6 = &v3->mMissionStates;
  v6->mNode.mPrev = &v6->mNode;
  v6->mNode.mNext = &v6->mNode;
  *(_QWORD *)&v3->mReEnableSlices.mCount = 0i64;
  v3->mReEnableSlices.mppArray = 0i64;
  *(_QWORD *)&v3->mStateDisplaySeconds = 1110704128i64;
  v3->maMasks[0] = 0i64;
  v3->maMasks[1] = 0i64;
}

// File Line: 202
// RVA: 0x490320
void __fastcall UFG::GameSlice::~GameSlice(UFG::GameSlice *this)
{
  UFG::GameSlice *v1; // rsi
  UFG::GameSlice::CompletionStatus v2; // edx
  void ***v3; // rdi
  signed __int64 v4; // rbp
  void **v5; // rbx
  UFG::PDATriggerParameters *v6; // rbx
  UFG::qNode<UFG::MissionWorkStatus,UFG::MissionWorkStatus> *v7; // rcx
  UFG::qNode<UFG::MissionWorkStatus,UFG::MissionWorkStatus> *v8; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v9; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rax

  v1 = this;
  v2 = 0;
  if ( this->mState == 4 )
    v2 = 3;
  UFG::GameSlice::End(this, v2);
  v3 = (void ***)v1->maMasks;
  v4 = 2i64;
  do
  {
    v5 = *v3;
    if ( *v3 )
    {
      operator delete[](v5[3]);
      operator delete[](v5);
      *v3 = 0i64;
    }
    ++v3;
    --v4;
  }
  while ( v4 );
  v6 = v1->mPDATriggerParameters;
  if ( v6 )
  {
    UFG::qString::~qString(&v6->mObjectiveName);
    UFG::qString::~qString(&v6->mContactName);
    operator delete[](v6);
    v1->mPDATriggerParameters = 0i64;
  }
  operator delete[](v1->mReEnableSlices.mppArray);
  UFG::qList<UFG::PopUpMessage,UFG::PopUpMessage,1,0>::DeleteNodes(&v1->mMissionStates);
  v7 = v1->mMissionStates.mNode.mPrev;
  v8 = v1->mMissionStates.mNode.mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  v1->mMissionStates.mNode.mPrev = &v1->mMissionStates.mNode;
  v1->mMissionStates.mNode.mNext = &v1->mMissionStates.mNode;
  operator delete[](v1->mBorrowedActors.mppArray);
  v9 = &v1->mpRestoredVehicle;
  if ( v1->mpRestoredVehicle.m_pPointer )
  {
    v10 = v9->mPrev;
    v11 = v1->mpRestoredVehicle.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    v9->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v9->mPrev;
    v1->mpRestoredVehicle.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mpRestoredVehicle.mPrev;
  }
  v1->mpRestoredVehicle.m_pPointer = 0i64;
  v12 = v9->mPrev;
  v13 = v1->mpRestoredVehicle.mNext;
  v12->mNext = v13;
  v13->mPrev = v12;
  v9->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v9->mPrev;
  v1->mpRestoredVehicle.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mpRestoredVehicle.mPrev;
  UFG::PropertySetHandle::~PropertySetHandle(&v1->mRepeatedRewardsProperties);
  UFG::PropertySetHandle::~PropertySetHandle(&v1->mRewardsProperties);
  operator delete[](v1->mChildren.mppArray);
  operator delete[](v1->mDependents.mppArray);
  UFG::qSharedString::~qSharedString(&v1->mSaveGameNameOverride);
  UFG::qSharedString::~qSharedString(&v1->mAudioOverride);
  UFG::qSharedString::~qSharedString(&v1->mPresentationState);
  UFG::qSharedString::~qSharedString(&v1->mAssetState);
  UFG::qSharedString::~qSharedString(&v1->mEncounterState);
  UFG::qSharedString::~qSharedString(&v1->mObjectiveBlipState);
  UFG::qSharedString::~qSharedString(&v1->mMissionFlowState);
  UFG::qSharedString::~qSharedString(&v1->mLightingState);
  UFG::qSharedString::~qSharedString(&v1->mGeoState);
  UFG::qSharedString::~qSharedString(&v1->mGamePlayState);
  UFG::qSharedString::~qSharedString(&v1->mNisPath);
  UFG::qSharedString::~qSharedString(&v1->mScriptClassName);
  UFG::qSharedString::~qSharedString(&v1->mTitle);
  UFG::qSharedString::~qSharedString(&v1->mName);
}

// File Line: 250
// RVA: 0x4BBD40
void __fastcall UFG::GameSlice::SetCollection(UFG::GameSlice *this, UFG::qString *collectionName, bool highPriority)
{
  bool v3; // si
  UFG::GameSlice *v4; // rdi
  char *v5; // rbx
  UFG::qSymbol *v6; // r14
  char *v7; // rbx
  unsigned int v8; // eax
  UFG::qSymbol result; // [rsp+60h] [rbp+18h]

  v3 = highPriority;
  v4 = this;
  v5 = collectionName->mData;
  if ( !(_S19_1 & 1) )
  {
    _S19_1 |= 1u;
    UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
    atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
  }
  UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
  v6 = UFG::qSymbol::create_from_string(&result, v5);
  if ( !v6->mUID || (v7 = (char *)UFG::qBaseTreeRB::Get(&stru_14240A1D8, v6->mUID)) == 0i64 )
  {
    v7 = (char *)UFG::qMalloc(0x38ui64, "GameSliceCollection", 0i64);
    if ( v7 )
    {
      v8 = v6->mUID;
      *(_QWORD *)v7 = 0i64;
      *((_QWORD *)v7 + 1) = 0i64;
      *((_QWORD *)v7 + 2) = 0i64;
      *((_DWORD *)v7 + 6) = v8;
      *((_DWORD *)v7 + 8) = v8;
      *((_QWORD *)v7 + 5) = 0i64;
      *((_QWORD *)v7 + 6) = 0i64;
    }
    else
    {
      v7 = 0i64;
    }
    UFG::qBaseTreeRB::Add(&stru_14240A1D8, (UFG::qBaseNodeRB *)v7);
  }
  v4->mpCollection = (UFG::GameSliceCollection *)v7;
  v4->mCollectionHighPriority = v3;
  if ( v3 )
    qSet<UFG::SceneObjectProperties,UFG::qSymbol,qCompareLogical<UFG::qSymbol>>::Append(
      (qSet<UFG::SceneObjectProperties,UFG::qSymbol,qCompareLogical<UFG::qSymbol> > *)(v7 + 40),
      (UFG::SceneObjectProperties *)v4,
      "GameSliceCollection::AddHighPrioritySlice");
}

// File Line: 284
// RVA: 0x4A1D20
UFG::qSymbol *__fastcall UFG::GameSlice::GetCancelLocationMarker(UFG::GameSlice *this)
{
  UFG::GameSlice *v1; // rbx
  UFG::GameSlice *v2; // rcx
  UFG::qSymbol *result; // rax

  v1 = this;
  v2 = this->mpLastActiveSublice;
  if ( !v2 || (result = UFG::GameSlice::GetCancelLocationMarker(v2), result->mUID == -1) )
    result = &v1->mCancelLocationMarker;
  return result;
}

// File Line: 320
// RVA: 0x492B80
void __fastcall UFG::GameSlice::AddDependency(UFG::GameSlice *this, const char *pName)
{
  const char *v2; // rsi
  UFG::GameSlice *v3; // rbp
  UFG::qSymbol *v4; // rdi
  UFG::qBaseTreeRB *v5; // rbx
  UFG::allocator::free_link *v6; // rax
  UFG::qBaseTreeRB *v7; // rax
  UFG::qString v8; // [rsp+28h] [rbp-40h]
  UFG::qSymbol result; // [rsp+70h] [rbp+8h]
  UFG::allocator::free_link *v10; // [rsp+80h] [rbp+18h]

  v2 = pName;
  v3 = this;
  if ( !(_S19_1 & 1) )
  {
    _S19_1 |= 1u;
    UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
    atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
  }
  UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
  v4 = UFG::qSymbol::create_from_string(&result, v2);
  if ( !v4->mUID || (v5 = UFG::qBaseTreeRB::Get(&stru_14240A190, v4->mUID)) == 0i64 )
  {
    if ( !v4->mUID || (v5 = UFG::qBaseTreeRB::Get(&stru_14240A100, v4->mUID)) == 0i64 )
    {
      if ( v4->mUID )
        v5 = UFG::qBaseTreeRB::Get(&stru_14240A148, v4->mUID);
      else
        v5 = 0i64;
    }
  }
  if ( !v5 )
  {
    UFG::qString::qString(&v8, v2);
    if ( !(_S19_1 & 1) )
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
    unk_14240B986 = 1;
    UFG::qString::~qString(&v8);
  }
  qSet<UFG::SceneObjectProperties,UFG::qSymbol,qCompareLogical<UFG::qSymbol>>::Append(
    (qSet<UFG::SceneObjectProperties,UFG::qSymbol,qCompareLogical<UFG::qSymbol> > *)&v3->mDependents,
    (UFG::SceneObjectProperties *)v5,
    "GameSlice::mDependents");
}

// File Line: 378
// RVA: 0x492A10
UFG::qBaseTreeRB *__fastcall UFG::GameSlice::AddChild(UFG::GameSlice *this, UFG::qString *pName)
{
  UFG::qString *v2; // rbp
  UFG::GameSlice *v3; // rsi
  char *v4; // rbx
  UFG::qSymbol *v5; // rdi
  UFG::qBaseTreeRB *v6; // rbx
  UFG::allocator::free_link *v7; // rax
  UFG::qBaseTreeRB *v8; // rax
  UFG::qSymbol result; // [rsp+50h] [rbp+8h]
  UFG::allocator::free_link *v11; // [rsp+58h] [rbp+10h]

  v2 = pName;
  v3 = this;
  v4 = pName->mData;
  if ( !(_S19_1 & 1) )
  {
    _S19_1 |= 1u;
    UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
    atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
  }
  UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
  v5 = UFG::qSymbol::create_from_string(&result, v4);
  if ( !v5->mUID || (v6 = UFG::qBaseTreeRB::Get(&stru_14240A190, v5->mUID)) == 0i64 )
  {
    if ( !v5->mUID || (v6 = UFG::qBaseTreeRB::Get(&stru_14240A100, v5->mUID)) == 0i64 )
    {
      if ( v5->mUID )
        v6 = UFG::qBaseTreeRB::Get(&stru_14240A148, v5->mUID);
      else
        v6 = 0i64;
    }
  }
  if ( !v6 )
  {
    if ( !(_S19_1 & 1) )
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
      UFG::GameSlice::GameSlice((UFG::GameSlice *)v7, v2->mData);
      v6 = v8;
    }
    else
    {
      v6 = 0i64;
    }
    UFG::qBaseTreeRB::Add(&stru_14240A190, &v6->mRoot);
    unk_14240B986 = 1;
  }
  qSet<UFG::SceneObjectProperties,UFG::qSymbol,qCompareLogical<UFG::qSymbol>>::Append(
    (qSet<UFG::SceneObjectProperties,UFG::qSymbol,qCompareLogical<UFG::qSymbol> > *)&v3->mChildren,
    (UFG::SceneObjectProperties *)v6,
    "GameSlice::mChildren");
  v6[5].mRoot.mChild[0] = &v3->mNode;
  return v6;
}

// File Line: 392
// RVA: 0x4938D0
void __fastcall UFG::GameSlice::AddReEnableSlice(UFG::GameSlice *this, UFG::qString *pName)
{
  UFG::qString *v2; // rsi
  UFG::GameSlice *v3; // rbp
  char *v4; // rbx
  UFG::qSymbol *v5; // rdi
  UFG::qBaseTreeRB *v6; // rbx
  UFG::allocator::free_link *v7; // rax
  UFG::qBaseTreeRB *v8; // rax
  UFG::qSymbol result; // [rsp+50h] [rbp+8h]
  UFG::allocator::free_link *v10; // [rsp+58h] [rbp+10h]

  v2 = pName;
  v3 = this;
  v4 = pName->mData;
  if ( !(_S19_1 & 1) )
  {
    _S19_1 |= 1u;
    UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
    atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
  }
  UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
  v5 = UFG::qSymbol::create_from_string(&result, v4);
  if ( !v5->mUID || (v6 = UFG::qBaseTreeRB::Get(&stru_14240A190, v5->mUID)) == 0i64 )
  {
    if ( !v5->mUID || (v6 = UFG::qBaseTreeRB::Get(&stru_14240A100, v5->mUID)) == 0i64 )
    {
      if ( v5->mUID )
        v6 = UFG::qBaseTreeRB::Get(&stru_14240A148, v5->mUID);
      else
        v6 = 0i64;
    }
  }
  if ( !v6 )
  {
    if ( !(_S19_1 & 1) )
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
      UFG::GameSlice::GameSlice((UFG::GameSlice *)v7, v2->mData);
      v6 = v8;
    }
    else
    {
      v6 = 0i64;
    }
    UFG::qBaseTreeRB::Add(&stru_14240A190, &v6->mRoot);
    unk_14240B986 = 1;
  }
  qSet<UFG::SceneObjectProperties,UFG::qSymbol,qCompareLogical<UFG::qSymbol>>::Append(
    (qSet<UFG::SceneObjectProperties,UFG::qSymbol,qCompareLogical<UFG::qSymbol> > *)&v3->mReEnableSlices,
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
UFG::GameSlice *__fastcall UFG::GameSlice::GetDependentRecursive(UFG::GameSlice *this, UFG::GameSlice::Type type, int *depth)
{
  __int64 v3; // rdi
  UFG::GameSlice *v4; // rsi
  UFG::GameSlice *v5; // rax
  __int64 v6; // r9
  UFG::GameSlice **v7; // rax
  UFG::GameSlice *v8; // r10
  signed int v9; // ebp
  __int64 v10; // rbx
  UFG::GameSlice **v11; // rax
  UFG::GameSlice *v12; // rax
  UFG::GameSlice *result; // rax
  UFG::GameSlice *v14; // [rsp+50h] [rbp+8h]
  UFG::GameSlice::Type v15; // [rsp+58h] [rbp+10h]
  int *v16; // [rsp+60h] [rbp+18h]
  int deptha; // [rsp+68h] [rbp+20h]

  v16 = depth;
  v15 = type;
  v14 = this;
  v3 = this->mDependents.mCount;
  v4 = 0i64;
  v5 = this;
  v6 = 0i64;
  if ( v3 <= 0 )
  {
LABEL_6:
    v9 = 0x7FFFFFFF;
    v10 = 0i64;
    if ( v3 > 0 )
    {
      do
      {
        v11 = v5->mDependents.mppArray;
        deptha = 0x7FFFFFFF;
        v12 = UFG::GameSlice::GetDependentRecursive(v11[v10], type, &deptha);
        if ( deptha < v9 )
        {
          v9 = deptha;
          v4 = v12;
        }
        type = v15;
        v5 = v14;
        ++v10;
      }
      while ( v10 < v3 );
      if ( v4 )
        *v16 = v9 + 1;
    }
    result = v4;
  }
  else
  {
    v7 = this->mDependents.mppArray;
    while ( 1 )
    {
      v8 = *v7;
      if ( (*v7)->mType == type )
        break;
      ++v6;
      ++v7;
      if ( v6 >= v3 )
      {
        v5 = this;
        goto LABEL_6;
      }
    }
    *depth = 1;
    result = v8;
  }
  return result;
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
  UFG::GameSlice *v1; // rbx
  __int32 v2; // ecx
  int v3; // ecx
  int v4; // ecx
  char *v5; // r9
  int v6; // ST20_4

  v1 = this;
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
          v1->mCleanupPending = 0;
        else
          v1->mCleanupCount = 0;
      }
      else
      {
        UFG::GameSlice::_DisableLayer(v1);
        v1->mCleanupPending = 4;
      }
    }
    else
    {
      v1->mCleanupPending = 3;
    }
  }
  else
  {
    if ( UFG::Metrics::msInstance.mSimTimeDelta > 0.0 )
      ++v1->mCleanupCount;
    v5 = v1->mName.mText;
    v6 = v1->mCleanupCount;
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
  __int64 v2; // rax
  bool v3; // si
  UFG::GameSlice *v4; // rdi
  UFG::GameSlice **v5; // rbx
  unsigned __int64 i; // rbp
  __int64 v7; // rax
  UFG::GameSlice **v8; // rbx
  unsigned __int64 j; // rbp
  bool v10; // zf

  v2 = (signed int)this->mDependents.mCount;
  v3 = simulateRewards;
  v4 = this;
  if ( (_DWORD)v2 )
  {
    v5 = this->mDependents.mppArray;
    for ( i = (unsigned __int64)&v5[v2]; (unsigned __int64)v5 < i; ++v5 )
    {
      if ( (*v5)->mState != 8 )
        UFG::GameSlice::_SimulateComplete(*v5, v3);
    }
  }
  v7 = (signed int)v4->mChildren.mCount;
  if ( (_DWORD)v7 )
  {
    v8 = v4->mChildren.mppArray;
    for ( j = (unsigned __int64)&v8[v7]; (unsigned __int64)v8 < j; ++v8 )
    {
      if ( (*v8)->mState != 8 )
        UFG::GameSlice::_SimulateComplete(*v8, v3);
    }
  }
  if ( !v4->mCompletionCount )
  {
    v10 = v4->mState == 8;
    v4->mCompletionStatus = 2;
    v4->mCompletionStatusTimestamp = UFG::Metrics::msInstance.mSimTimeMSec;
    if ( !v10 && v3 )
      UFG::GameSlice::_HandleCompletionRewards(v4, DoNotShowReward);
    ++v4->mCompletionCount;
    v4->mState = 8;
  }
  v4->mDirty = 1;
}

// File Line: 769
// RVA: 0x4C60A0
void __fastcall UFG::GameSlice::UpdateDependency(UFG::GameSlice *this)
{
  UFG::GameSlice *v1; // rbx
  __int64 v2; // rax
  UFG::GameSlice::State v3; // ebp
  UFG::GameSlice **v4; // rsi
  unsigned __int64 v5; // rax
  UFG::GameSlice *v6; // rdi
  signed int v7; // esi
  __int64 v8; // r8
  __int64 v9; // r9
  UFG::GameSlice::CompletionStatus v10; // edx
  UFG::GameSlice *v11; // rcx
  UFG::GameSlice *v12; // rcx
  char v13; // r8
  __int64 v14; // rax
  UFG::GameSlice **v15; // rsi
  unsigned __int64 v16; // rdx
  UFG::GameSlice *v17; // rdi
  signed int v18; // eax
  UFG::GameSliceCollection *v19; // rax
  __int64 v20; // rdi
  __int64 v21; // rdx
  UFG::GameSlice **v22; // rcx
  UFG::GameSlice *v23; // rsi
  signed int v24; // edi
  __int64 v25; // r8
  __int64 v26; // r9
  UFG::GameSlice::CompletionStatus v27; // edx
  UFG::GameSlice *v28; // rcx
  UFG::GameSlice *v29; // rcx
  __int64 v30; // rax
  unsigned __int64 v31; // rdx
  UFG::GameSlice::State v32; // edi
  UFG::GameSlice *v33; // rax
  UFG::GameSlice *v34; // rcx
  UFG::GameSlice *v35; // rcx
  __int64 v36; // [rsp+28h] [rbp-20h]
  __int64 v37; // [rsp+30h] [rbp-18h]
  unsigned __int64 v38; // [rsp+50h] [rbp+8h]
  char v39; // [rsp+50h] [rbp+8h]
  int v40; // [rsp+58h] [rbp+10h]
  unsigned __int64 v41; // [rsp+60h] [rbp+18h]
  __int64 v42; // [rsp+60h] [rbp+18h]

  v1 = this;
  LOBYTE(this) = this->mState == 8;
  v40 = (signed int)this;
  v2 = (signed int)v1->mDependents.mCount;
  v3 = 0;
  if ( (_DWORD)v2 )
  {
    v4 = v1->mDependents.mppArray;
    v5 = (unsigned __int64)&v4[v2];
    v38 = v5;
    if ( (unsigned __int64)v4 < v5 )
    {
      do
      {
        v6 = *v4;
        if ( (*v4)->mDirty )
        {
          UFG::GameSlice::UpdateDependency(*v4);
          v5 = v38;
        }
        if ( v6->mState == 8 || v6->mOptional || v6->mCompletionCount > 0 )
          ++v3;
        ++v4;
      }
      while ( (unsigned __int64)v4 < v5 );
      LODWORD(this) = v40;
    }
    if ( v3 < v1->mMinimumDependentsRequired )
    {
      v7 = v1->mState;
      if ( v7 )
      {
        UFG::ProgressionTracker::Instance()->mDirty = 1;
        if ( v1->mScript )
          UFG::ProgressionTriggerComponent::DisableTrigger(v1, 0);
        v1->mState = 0;
        if ( !v1->mRepeatableInterval )
          v1->mCompletionCount = 0;
        v10 = 0;
        if ( v7 >= 4 )
          v10 = 3;
        UFG::GameSlice::End(v1, v10, v8, v9, -2i64, v36, v37);
        if ( v1->mExclusive || v1->mRandomExclusive )
        {
          if ( !((v7 - 2) & 0xFFFFFFFD) && v1->mExclusiveChild == v1 )
          {
            v1->mExclusiveChild = 0i64;
            v11 = v1->mpParent;
            if ( v11 )
              UFG::GameSlice::_MarkExclusiveChild(v11, 0i64);
          }
          if ( v1->mState == 4 )
          {
            v1->mExclusiveChild = v1;
            v12 = v1->mpParent;
            if ( v12 )
              UFG::GameSlice::_MarkExclusiveChild(v12, v1);
            v1->mRequiresSave = 0;
          }
          if ( v1->mState == 8 && v1->mExclusive && v1->mPersistent )
            v1->mRequiresSave = 1;
        }
      }
      v1->mCompletionCount = 0;
      goto LABEL_114;
    }
    v3 = 0;
  }
  v13 = 1;
  v39 = 1;
  v14 = (signed int)v1->mChildren.mCount;
  if ( !(_DWORD)v14 )
  {
LABEL_50:
    if ( (_BYTE)this )
      goto LABEL_82;
    v19 = v1->mpCollection;
    if ( !v19 )
      goto LABEL_82;
    if ( v1->mCollectionHighPriority )
      goto LABEL_82;
    v20 = 0i64;
    v21 = v19->mHighPrioritySlices.mCount;
    v42 = v21;
    if ( v21 <= 0 )
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
      v1->mState = 0;
      if ( !v1->mRepeatableInterval )
        v1->mCompletionCount = 0;
      v27 = 0;
      if ( v24 >= 4 )
        v27 = 3;
      UFG::GameSlice::End(v1, v27, v25, v26, -2i64, v36, v37);
      if ( v1->mExclusive || v1->mRandomExclusive )
      {
        if ( !((v24 - 2) & 0xFFFFFFFD) && v1->mExclusiveChild == v1 )
        {
          v1->mExclusiveChild = 0i64;
          v28 = v1->mpParent;
          if ( v28 )
            UFG::GameSlice::_MarkExclusiveChild(v28, 0i64);
        }
        if ( v1->mState == 4 )
        {
          v1->mExclusiveChild = v1;
          v29 = v1->mpParent;
          if ( v29 )
            UFG::GameSlice::_MarkExclusiveChild(v29, v1);
          v1->mRequiresSave = 0;
        }
        if ( v1->mState == 8 && v1->mExclusive && v1->mPersistent )
          v1->mRequiresSave = 1;
      }
    }
    v1->mCompletionCount = v3;
    goto LABEL_114;
  }
  v13 = 0;
  v39 = 0;
  LOBYTE(this) = 1;
  v40 = (signed int)this;
  v15 = v1->mChildren.mppArray;
  v16 = (unsigned __int64)&v15[v14];
  v41 = v16;
  if ( (unsigned __int64)v15 >= v16 )
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
      v40 = (signed int)this;
    }
    ++v15;
  }
  while ( (unsigned __int64)v15 < v16 );
  if ( v13 )
    goto LABEL_50;
LABEL_82:
  v30 = v1->mRepeatableInterval;
  if ( !(_DWORD)v30 || v1->mCompletionStatus != 2 || v1->mCleanupPending )
    goto LABEL_117;
  v31 = v1->mCompletionStatusTimestamp;
  if ( !v31 )
  {
    UFG::GameSlice::ForceLock(v1, 0);
    v1->mDirty = 0;
    v1->mCompletionStatus = 0;
    v1->mCompletionStatusTimestamp = UFG::Metrics::msInstance.mSimTimeMSec;
    return;
  }
  if ( UFG::Metrics::msInstance.mSimTimeMSec <= v31 + v30 )
  {
LABEL_117:
    if ( v13 )
    {
      if ( (_BYTE)this )
      {
        v3 = 8;
      }
      else if ( UFG::GameSlice::_IsUnlockAllowed(v1) )
      {
        v32 = v1->mState;
        if ( (v32 - 2) & 0xFFFFFFFD && v32 != 1 )
        {
          if ( !(_S19_1 & 1) )
          {
            _S19_1 |= 1u;
            UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
            atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
          }
          UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
          unk_14240B986 = 1;
          v1->mpLastActiveSublice = 0i64;
          UFG::GameSlice::Unlock(v1, STATE_UNLOCKED);
          v33 = v1->mpParent;
          if ( v33 )
            v33->mpLastActiveSublice = v1;
          if ( v1->mExclusive || v1->mRandomExclusive )
          {
            if ( !((v32 - 2) & 0xFFFFFFFD) && v1->mExclusiveChild == v1 )
            {
              v1->mExclusiveChild = 0i64;
              v34 = v1->mpParent;
              if ( v34 )
                UFG::GameSlice::_MarkExclusiveChild(v34, 0i64);
            }
            if ( v1->mState == 4 )
            {
              v1->mExclusiveChild = v1;
              v35 = v1->mpParent;
              if ( v35 )
                UFG::GameSlice::_MarkExclusiveChild(v35, v1);
              v1->mRequiresSave = 0;
            }
            if ( v1->mState == 8 && v1->mExclusive )
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
  else
  {
    UFG::GameSlice::ForceLock(v1, 0);
  }
LABEL_114:
  v1->mDirty = 0;
}       {
              if ( v1->mPersistent )
                v1->mRequiresSave = 1;
            }
         

// File Line: 933
// RVA: 0x4AA820
_BOOL8 __fastcall UFG::GameSlice::HasProgressionTrigger(UFG::GameSlice *this)
{
  bool v2; // zf

  if ( this->mTriggerObjectName.mUID == -1
    && ((signed int)this->mChildren.mCount <= 0 || (*this->mChildren.mppArray)->mTriggerObjectName.mUID == -1) )
  {
    return this->mPDATriggerParameters != 0i64;
  }
  v2 = this->mPDATriggerParameters == 0i64;
  return 1i64;
}

// File Line: 993
// RVA: 0x4BDD50
void __fastcall UFG::GameSlice::SetWaitingForTrigger(UFG::GameSlice *this, bool isWaiting, bool turnLayerOn)
{
  bool v3; // si
  bool v4; // di
  UFG::GameSlice *i; // rbx
  bool v6; // sf
  unsigned __int8 v7; // of

  v3 = turnLayerOn;
  v4 = isWaiting;
  for ( i = this; ; i = *i->mChildren.mppArray )
  {
    if ( !v4 && v3 )
    {
      UFG::GameSlice::_EnableLayer(i);
      UFG::ProgressionTracker::Instance()->mDirty = 1;
    }
    v7 = __OFSUB__(i->mChildren.mCount, 1);
    v6 = (signed int)(i->mChildren.mCount - 1) < 0;
    i->mWaitingForTrigger = v4;
    if ( v6 ^ v7 )
      break;
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
  UFG::GameSlice *v3; // rcx

  result = 1;
  if ( this != pSlice )
  {
    v3 = this->mpParent;
    if ( !v3 || !UFG::GameSlice::_IsChildOf(v3, pSlice) )
      result = 0;
  }
  return result;
}

// File Line: 1061
// RVA: 0x4C9470
char __fastcall UFG::GameSlice::_IsDisableWaiting(UFG::GameSlice *this)
{
  UFG::GameSlice *v1; // rdx
  UFG::GameSlice *v2; // rbx
  unsigned __int64 v3; // rcx
  float v4; // xmm1_4
  unsigned __int64 v5; // rax
  float v6; // xmm0_4
  UFG::GameSlice *v7; // rcx
  bool v8; // al

  v1 = this;
  v2 = this;
  if ( this )
  {
    while ( v2->mpParent )
      v2 = v2->mpParent;
    if ( v2->mCompletionStatus == 1 )
    {
      v7 = this->mpParent;
      if ( v7 )
        v8 = UFG::GameSlice::IsDeferredRestartIfInsideRegion(v7);
      else
        v8 = v1->mDeferRestartIfInsideRegion != 0;
      if ( v8 )
        UFG::ProgressionTriggerComponent::ActiveateOnlyAfterExitFromRegion(v2);
      v2->mCompletionStatus = 3;
      goto LABEL_19;
    }
    if ( v2->mCompletionStatus == 3 )
    {
      v3 = v2->mCompletionStatusTimestamp;
      if ( v3 )
      {
        v4 = (float)SLODWORD(UFG::Metrics::msInstance.mSimTimeMSec);
        if ( (UFG::Metrics::msInstance.mSimTimeMSec & 0x8000000000000000ui64) != 0i64 )
          v4 = v4 + 1.8446744e19;
        v5 = v2->mFailTimeout;
        v6 = (float)((signed int)v3 + (signed int)v5);
        if ( (signed __int64)(v3 + v5) < 0 )
          v6 = v6 + 1.8446744e19;
        if ( v4 < v6 )
          return 1;
      }
      v2->mCompletionStatus = 0;
LABEL_19:
      v2->mCompletionStatusTimestamp = UFG::Metrics::msInstance.mSimTimeMSec;
      return 1;
    }
  }
  return 0;
}

// File Line: 1117
// RVA: 0x4AB9E0
char __fastcall UFG::GameSlice::IsAllowedAtThisTimeOfDay(UFG::GameSlice *this)
{
  UFG::GameSlice *v1; // rbx
  UFG::TimeOfDayManager *v2; // rax
  float v3; // xmm2_4
  float v4; // xmm1_4
  float v5; // xmm0_4

  v1 = this;
  if ( this->mState == 4 )
    return 1;
  while ( v1->mpParent )
    v1 = v1->mpParent;
  if ( !v1->mIsTODRestricted )
    return 1;
  v2 = UFG::TimeOfDayManager::GetInstance();
  v3 = v1->mTODActive;
  v4 = v1->mTODInactive;
  v5 = v2->m_SecondsSinceMidnight;
  if ( v3 >= v4 )
  {
    if ( v5 >= v3 )
      return 1;
  }
  else if ( v5 < v3 )
  {
    return 0;
  }
  if ( v5 > v4 )
    return 0;
  return 1;
}

// File Line: 1154
// RVA: 0x4ABF30
bool __fastcall UFG::GameSlice::IsEnabledForCurrentMode(UFG::GameSlice *this)
{
  UFG::GameSlice *v1; // rbx
  UFG::GameSlice *v2; // rcx
  bool v3; // zf

  v1 = this;
  if ( !(_S19_1 & 1) )
  {
    _S19_1 |= 1u;
    UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
    atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
  }
  UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
  v2 = v1->mpParent;
  if ( v2 )
    v3 = v2->mSubsetModeType.mUID == unk_14240B998;
  else
    v3 = v1->mSubsetModeType.mUID == unk_14240B998;
  return v3;
}

// File Line: 1168
// RVA: 0x4C9560
char __fastcall UFG::GameSlice::_IsUnlockAllowed(UFG::GameSlice *this)
{
  UFG::GameSlice *v1; // rbx
  char result; // al
  UFG::ProgressionTracker *v3; // rax
  UFG::GameSlice *v4; // rdi
  UFG::GameSliceMasks *v5; // rcx
  bool v6; // si
  UFG::GameSliceMasks *v7; // rcx
  bool v8; // al
  bool v9; // zf
  unsigned int v10; // eax
  UFG::ProgressionTracker *v11; // rax
  UFG::GameSlice *v12; // rsi
  UFG::GameSliceMasks *v13; // rcx
  bool v14; // di
  UFG::GameSliceMasks *v15; // rcx
  UFG::GameSlice *v16; // rcx
  UFG::ProgressionTracker *v17; // rax
  UFG::GameSlice *v18; // rdi
  UFG::GameSlice *v19; // rcx
  UFG::GameSlice *v20; // rcx

  v1 = this;
  switch ( this->mType )
  {
    case 0:
      goto $LN108_1;
    case 1:
    case 2:
      goto $LN1_17;
    case 3:
      if ( UFG::GameSlice::_IsDisableWaiting(this) || !UFG::GameSlice::IsEnabledForCurrentMode(v1) )
        goto $LN108_1;
      v3 = UFG::ProgressionTracker::Instance();
      v4 = v3->mpActiveMaster;
      if ( v1 == v4 )
        goto $LN1_17;
      v5 = v1->maMasks[0];
      v6 = !v5 || UFG::GameSliceMasks::IsSet(v5, v3->mpActiveMaster);
      v7 = v1->maMasks[1];
      v8 = !v7 || !UFG::GameSliceMasks::IsSet(v7, v4);
      v9 = v6 == 0;
      goto LABEL_15;
    case 4:
      if ( UFG::GameSlice::IsEnabledForCurrentMode(this) )
      {
        v10 = UFG::GameStatTracker::Instance()->mpSnapshots[0]->mIDs[29].mValue.mUID;
        if ( !v1->mpCollection || !v1->mCollectionHighPriority || v10 == -1 || v10 == v1->mpDependentMission->mNode.mUID )
        {
          if ( UFG::GameSlice::IsAllowedAtThisTimeOfDay(v1) )
          {
            v11 = UFG::ProgressionTracker::Instance();
            v12 = v11->mpActiveMaster;
            v13 = v1->maMasks[0];
            v14 = !v13 || UFG::GameSliceMasks::IsSet(v13, v11->mpActiveMaster);
            v15 = v1->maMasks[1];
            v8 = !v15 || !UFG::GameSliceMasks::IsSet(v15, v12);
            v9 = v14 == 0;
LABEL_15:
            if ( !v9 && v8 )
              goto $LN1_17;
          }
        }
      }
      goto $LN108_1;
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 0xA:
    case 0xB:
      if ( !UFG::GameSlice::_IsDisableWaiting(this) && UFG::GameSlice::IsEnabledForCurrentMode(v1) )
        goto LABEL_35;
      goto $LN108_1;
    default:
LABEL_35:
      v16 = v1;
      if ( v1->mpParent )
        v16 = v1->mpParent;
      if ( v16->mTODBypassPrompt && !UFG::GameSlice::IsAllowedAtThisTimeOfDay(v1) )
        goto $LN108_1;
      if ( !(_S19_1 & 1) )
      {
        _S19_1 |= 1u;
        UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
        atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
      }
      if ( (UFG::ProgressionTracker::mspInstance = &sProgressionTracker, byte_14240B987)
        || (v17 = UFG::ProgressionTracker::Instance(), (v18 = v17->mpActiveMaster) != 0i64)
        && v1 != v18
        && ((v19 = v1->mpParent) == 0i64 || !UFG::GameSlice::_IsChildOf(v19, v17->mpActiveMaster))
        && gGameSliceTypePriority[v1->mType] <= gGameSliceTypePriority[v18->mType]
        || (v20 = v1->mpParent) != 0i64 && (v20->mState == 8 || UFG::GameSlice::IsRunningExclusiveChild(v20, v1)) )
      {
$LN108_1:
        result = 0;
      }
      else
      {
$LN1_17:
        result = 1;
      }
      return result;
  }
}

// File Line: 1329
// RVA: 0x4ACBD0
char __fastcall UFG::GameSlice::IsRewardPropertyRaceType(UFG::GameSlice *this)
{
  UFG::qPropertySet *v1; // rbx
  UFG::qSymbol *v2; // rax
  UFG::qSymbol *v3; // rax
  UFG::qSymbol *v4; // rcx
  char v5; // al
  UFG::qSymbol result; // [rsp+38h] [rbp+10h]

  v1 = UFG::GameSlice::GetRewardsProperties(this);
  if ( !v1 )
    goto LABEL_9;
  v2 = UFG::qSymbol::create_from_string(&result, "GamesliceType");
  v3 = UFG::qPropertySet::Get<UFG::qSymbol>(v1, v2, DEPTH_RECURSE);
  v4 = &UFG::gNullQSymbol;
  if ( v3 )
    v4 = v3;
  if ( v4->mUID == qSymbol_Race_14.mUID )
    v5 = 1;
  else
LABEL_9:
    v5 = 0;
  return v5;
}

// File Line: 1346
// RVA: 0x4ACC60
char __fastcall UFG::GameSlice::IsRunningExclusiveChild(UFG::GameSlice *this, UFG::GameSlice *pChild)
{
  UFG::GameSlice *v2; // rax
  __int64 v4; // rbx
  __int64 v5; // r9
  __int64 v6; // r8
  UFG::GameSlice **v7; // r10
  __int64 v8; // rcx
  UFG::GameSlice **v9; // rax

  v2 = this->mExclusiveChild;
  if ( !v2 || !pChild || v2 == pChild )
    return 0;
  v4 = (signed int)v2->mDependents.mCount;
  v5 = 0i64;
  if ( v4 <= 0 )
    return 0;
  v6 = (signed int)pChild->mDependents.mCount;
  v7 = v2->mDependents.mppArray;
  while ( 1 )
  {
    v8 = 0i64;
    if ( v6 > 0 )
      break;
LABEL_11:
    ++v5;
    ++v7;
    if ( v5 >= v4 )
      return 0;
  }
  v9 = pChild->mDependents.mppArray;
  while ( *v9 != *v7 )
  {
    ++v8;
    ++v9;
    if ( v8 >= v6 )
      goto LABEL_11;
  }
  return 1;
}

// File Line: 1371
// RVA: 0x4C9260
void __fastcall UFG::GameSlice::_EnableLayer(UFG::GameSlice *this)
{
  unsigned int v1; // eax
  UFG::qBaseTreeRB *v2; // rax
  UFG::qSymbol name; // [rsp+30h] [rbp+8h]

  if ( !this->mLayerEnabledByMe )
  {
    v1 = this->mLayerName.mUID;
    this->mLayerEnabledByMe = 1;
    name.mUID = v1;
    v2 = UFG::Scene::FindLayer(&UFG::Scene::msDefault, &name);
    if ( v2 )
      UFG::SceneLayer::EnableActivate((UFG::SceneLayer *)v2, 1, PERSISTENT, 0);
  }
}

// File Line: 1392
// RVA: 0x4C9210
void __fastcall UFG::GameSlice::_DisableLayer(UFG::GameSlice *this)
{
  unsigned int v1; // eax
  UFG::qBaseTreeRB *v2; // rax
  UFG::qSymbol name; // [rsp+30h] [rbp+8h]

  if ( this->mLayerEnabledByMe )
  {
    v1 = this->mLayerName.mUID;
    this->mLayerEnabledByMe = 0;
    name.mUID = v1;
    v2 = UFG::Scene::FindLayer(&UFG::Scene::msDefault, &name);
    if ( v2 )
      UFG::SceneLayer::EnableActivate((UFG::SceneLayer *)v2, 0, PERSISTENT, 0);
  }
}

// File Line: 1418
// RVA: 0x4BEF50
void __fastcall UFG::GameSlice::Start(UFG::GameSlice *this)
{
  UFG::GameSlice *v1; // rdi
  bool v2; // zf
  char *v3; // r9
  __int64 v4; // rbx
  UFG::ProgressionTracker *v5; // rax
  __int64 v6; // rbx
  UFG::ProgressionTracker *v7; // rax
  UFG::GameSlice *v8; // rcx

  v1 = this;
  if ( !this->mScript )
  {
    v2 = this->mCountedStats == 0;
    this->mCompletionStatus = 0;
    this->mCompletionStatusTimestamp = UFG::Metrics::msInstance.mSimTimeMSec;
    if ( v2 )
    {
      v3 = this->mName.mText;
      UFG::qPrintChannel::Print(
        &UFG::gPrintChannel_HK_Progression,
        OUTPUT_LEVEL_DEBUG,
        "[Progression]: ScriptObjective starting for (%s)\n");
      UFG::ProgressionTracker::Instance();
      v4 = v1->mType;
      v5 = UFG::ProgressionTracker::Instance();
      ++v5->gActiveGameSlices[v4];
      if ( !v1->mpParent && v1->mType > 0 )
      {
        UFG::ProgressionTracker::Instance();
        v6 = v1->mType;
        v7 = UFG::ProgressionTracker::Instance();
        ++v7->gActiveContainers[v6];
      }
      v1->mCountedStats = 1;
    }
    if ( v1->mDeferStartIfInsideRegion
      && (unsigned int)UFG::FlowController::GetCurrentState(&UFG::gFlowController) == uidGameStateInGame_9 )
    {
      v8 = v1->mpParent;
      if ( !v8 )
        v8 = v1;
      UFG::ProgressionTriggerComponent::ActiveateOnlyAfterExitFromRegion(v8);
    }
    UFG::ProgressionTriggerComponent::EnableTrigger(v1);
  }
}

// File Line: 1471
// RVA: 0x4BF760
void __fastcall UFG::GameSlice::StartScript(UFG::GameSlice *this)
{
  UFG::GameSlice *v1; // rdi
  __int64 v2; // rbx
  SSActorClass *v3; // rsi
  char *v4; // r9
  SSInstance *v5; // rax
  UFG::SSGameSlice *v6; // rax
  UFG::GameSlice *v7; // rax
  UFG::SSGameSlice *v8; // rax
  signed __int64 v9; // r8
  UFG::SSGameSlice *v10; // rcx
  signed __int64 v11; // r8
  __int64 v12; // rsi
  UFG::GameSlice *v13; // rdx
  SSInstance *args_pp; // [rsp+60h] [rbp+8h]

  v1 = this;
  v2 = 0i64;
  if ( !this->mScript )
  {
    v3 = (SSActorClass *)SSBrain::get_class(this->mScriptClassName.mText);
    if ( v3 )
    {
      v4 = v1->mScriptClassName.mText;
      UFG::qPrintChannel::Print(
        &UFG::gPrintChannel_HK_Progression,
        OUTPUT_LEVEL_DEBUG,
        "[Progression]: StartScript (%s)\n");
      v5 = (SSInstance *)AMemory::c_malloc_func(0xA0ui64, "SSGameSlice");
      args_pp = v5;
      if ( v5 )
        UFG::SSGameSlice::SSGameSlice((UFG::SSGameSlice *)v5, v1, (ASymbol *)&v1->mNode.mUID, v3, 1);
      else
        v6 = 0i64;
      v1->mScript = v6;
      ++v6->i_ref_count;
      v7 = v1->mpParent;
      if ( v7 )
      {
        v8 = v7->mScript;
        v9 = (signed __int64)&v8->vfptr;
        if ( !v8 )
          v9 = 0i64;
        v1->mScript->vfptr->set_data_by_name(
          (SSObjectBase *)&v1->mScript->vfptr,
          (ASymbol *)&qSymbol_i_gameslice_data,
          (SSInstance *)v9);
      }
      SSInstance::call_default_constructor((SSInstance *)&v1->mScript->vfptr);
      if ( !v1->mpParent )
      {
        v10 = v1->mScript;
        v11 = (signed __int64)&v10->vfptr;
        if ( !v10 )
          v11 = 0i64;
        v10->vfptr->set_data_by_name(
          (SSObjectBase *)&v10->vfptr,
          (ASymbol *)&qSymbol_i_gameslice_data,
          (SSInstance *)v11);
      }
      SSActor::enable_behavior((SSActor *)&v1->mScript->vfptr, 1);
      args_pp = 0i64;
      SSInstance::coroutine_call(
        (SSInstance *)&v1->mScript->vfptr,
        (ASymbol *)&qSymbol__gameslice_main_private,
        &args_pp,
        0,
        1,
        0.0,
        0i64,
        0i64);
      if ( v1->mScript )
        v1->mCleanupPending = 0;
    }
  }
  v12 = v1->mChildren.mCount;
  if ( v12 > 0 )
  {
    do
    {
      v13 = v1->mChildren.mppArray[v2];
      if ( (unsigned int)(v13->mState - 1) <= 6 )
        UFG::GameSliceStreamer::RequestStream(UFG::GameSliceStreamer::mspInstance, v13);
      ++v2;
    }
    while ( v2 < v12 );
  }
}

// File Line: 1552
// RVA: 0x4C1960
void __fastcall UFG::GameSlice::StopDrivenVehicle(UFG::GameSlice *this)
{
  unsigned __int16 v1; // dx
  UFG::CharacterOccupantComponent *v2; // rax
  UFG::SimObjectGame *v3; // rax
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rcx

  if ( this->mVehicleSuperStop && LocalPlayer )
  {
    v1 = LocalPlayer->m_Flags;
    if ( (v1 >> 14) & 1 )
    {
      v2 = (UFG::CharacterOccupantComponent *)LocalPlayer->m_Components.p[44].m_pComponent;
    }
    else if ( (v1 & 0x8000u) == 0 )
    {
      if ( (v1 >> 13) & 1 )
        v2 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  (UFG::SimObjectGame *)&LocalPlayer->vfptr,
                                                  UFG::CharacterOccupantComponent::_TypeUID);
      else
        v2 = (UFG::CharacterOccupantComponent *)((v1 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                    (UFG::SimObjectGame *)&LocalPlayer->vfptr,
                                                                    UFG::CharacterOccupantComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&LocalPlayer->vfptr, UFG::CharacterOccupantComponent::_TypeUID));
    }
    else
    {
      v2 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                (UFG::SimObjectGame *)&LocalPlayer->vfptr,
                                                UFG::CharacterOccupantComponent::_TypeUID);
    }
    if ( v2 )
    {
      v3 = (UFG::SimObjectGame *)UFG::CharacterOccupantComponent::GetCurrentVehicle(v2);
      if ( v3 )
      {
        v4 = v3->m_Flags;
        if ( !((v4 >> 14) & 1) )
        {
          if ( (v4 & 0x8000u) == 0 )
          {
            if ( (v4 >> 13) & 1 )
              return;
            if ( (v4 >> 12) & 1 )
              v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::PhysicsMoverInterface::_TypeUID);
            else
              v5 = UFG::SimObject::GetComponentOfType(
                     (UFG::SimObject *)&v3->vfptr,
                     UFG::PhysicsMoverInterface::_TypeUID);
          }
          else
          {
            v5 = v3->m_Components.p[34].m_pComponent;
          }
          if ( v5 )
          {
            v6 = v5[10].m_SafePointerList.mNode.mPrev;
            if ( v6 )
              HIDWORD(v6[37].mNext) |= 8u;
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
  UFG::SceneSettings *v2; // rax
  bool v3; // bp
  UFG::RoadNetworkLane *v4; // rbx
  float v5; // xmm6_4
  UFG::TimeOfDayManager *v6; // rdi
  __int64 v7; // rax
  float v8; // xmm1_4
  char v9; // si
  float v10; // xmm1_4
  float v11; // xmm1_4

  v2 = this->mSceneSettings;
  v3 = immediate;
  v4 = (UFG::RoadNetworkLane *)this;
  if ( v2 )
  {
    v5 = 0.0;
    if ( v2->mTimeOverrideInSeconds >= 0.0 || v2->mWeatherOverrideIntensity >= 0.0 )
    {
      if ( UFG::UIHK_NISOverlay::IsCurtainVisible() )
      {
        v6 = UFG::TimeOfDayManager::GetInstance();
        v7 = v4[2].mEndConnection.mOffset;
        v8 = *(float *)(v7 + 0x20);
        if ( v8 >= 0.0 )
        {
          v9 = *(_BYTE *)(v7 + 40);
          if ( v3 || v9 )
            UFG::TimeOfDayManager::SetWeather(v6, v8);
          else
            UFG::TimeOfDayManager::SetWeatherTarget(v6, v8);
          v10 = *(float *)(v4[2].mEndConnection.mOffset + 36);
          if ( v10 >= 0.0 )
            UFG::TimeOfDayManager::SetSurfaceWetnessOverride(v6, v10, "UFG.GameSlice.SetupTimeAndWeather");
          UFG::TimeOfDayManager::LockWeather(v6, v9);
        }
        v11 = *(float *)(v4[2].mEndConnection.mOffset + 44);
        if ( v11 >= 0.0 )
        {
          UFG::TimeOfDayManager::SetTime(v6, v11, 0);
          if ( !*(_BYTE *)(v4[2].mEndConnection.mOffset + 50) )
            v5 = FLOAT_40_0;
          TimePlotPoint::SetTimeValue(v6, v5);
        }
      }
      else
      {
        UFG::VehicleOccupantComponent::SetParkingSpot((UFG::RoadNetworkGuide *)&UFG::gLoadingLogic, v4);
      }
    }
  }
}

// File Line: 1626
// RVA: 0x497600
void __fastcall UFG::GameSlice::CleanupTimeAndWeather(UFG::GameSlice *this)
{
  UFG::GameSlice *v1; // rbx
  UFG::TimeOfDayManager *v2; // rdi
  UFG::SceneSettings *v3; // rax
  UFG::SceneSettings *v4; // rax
  UFG::GameSlice *v5; // r8
  signed int v6; // eax
  bool v7; // al
  UFG::SceneSettings *v8; // rcx

  v1 = this;
  if ( this->mSceneSettings )
  {
    v2 = UFG::TimeOfDayManager::GetInstance();
    v3 = v1->mSceneSettings;
    if ( v3->mWeatherOverrideIntensity >= 0.0 && v3->mWeatherOverrideLock )
      UFG::TimeOfDayManager::LockWeather(v2, 0);
    if ( v1->mSceneSettings->mWeatherOverrideWetness >= 0.0 )
      UFG::TimeOfDayManager::SetSurfaceWetnessOverride(v2, -1.0, "GameSlice::CleanupTimeAndWeather");
    v4 = v1->mSceneSettings;
    if ( v4->mTimeOverrideInSeconds >= 0.0 && v4->mTimeOverrideLock )
      TimePlotPoint::SetTimeValue(v2, 40.0);
    v5 = v1->mpParent;
    v7 = 0;
    if ( v5 )
    {
      v6 = v5->mChildren.mCount;
      if ( v6 > 0 && v5->mChildren.mppArray[v6 - 1] == v1 )
        v7 = 1;
    }
    if ( v5 )
    {
      v8 = v1->mSceneSettings;
      if ( (v8->mWeatherOverrideIntensity >= 0.0 || v8->mTimeOverrideInSeconds >= 0.0) && !v7 )
        UFG::GameSlice::SetupTimeAndWeather(v1->mpParent, 1);
    }
  }
}

// File Line: 1661
// RVA: 0x4BDE40
void __fastcall UFG::GameSlice::SetupPedsAndVehicles(UFG::GameSlice *this)
{
  UFG::SceneSettings *v1; // rax
  UFG::GameSlice *v2; // rbx

  v1 = this->mSceneSettings;
  v2 = this;
  if ( v1 )
  {
    UFG::PedSpawning_AmbientPedEnableHelper(v1->mEnableAmbientPedsOnStart);
    if ( v2->mSceneSettings->mLockPedsOnStart )
      UFG::PedSpawning_AmbientPedEnableLockHelper(1);
    UFG::WheeledVehicleManager::EnableTrafficSystem(
      UFG::WheeledVehicleManager::m_Instance,
      v2->mSceneSettings->mEnableTrafficOnStart);
    if ( v2->mSceneSettings->mLockTrafficOnStart )
      UFG::WheeledVehicleManager::SetTrafficSystemLocked(1);
  }
}

// File Line: 1679
// RVA: 0x496F80
void __fastcall UFG::GameSlice::CleanupPedsAndVehicles(UFG::GameSlice *this)
{
  UFG::SceneSettings *v1; // rax
  UFG::GameSlice *v2; // rbx

  v1 = this->mSceneSettings;
  v2 = this;
  if ( v1 )
  {
    if ( v1->mUnLockTrafficOnEnd )
      UFG::WheeledVehicleManager::SetTrafficSystemLocked(0);
    UFG::WheeledVehicleManager::EnableTrafficSystem(
      UFG::WheeledVehicleManager::m_Instance,
      v2->mSceneSettings->mEnableTrafficOnEnd);
    if ( v2->mSceneSettings->mUnLockPedsOnEnd )
      UFG::PedSpawning_AmbientPedEnableLockHelper(0);
    UFG::PedSpawning_AmbientPedEnableHelper(v2->mSceneSettings->mEnableAmbientPedsOnEnd);
  }
}

// File Line: 1699
// RVA: 0x4BDEB0
void __fastcall UFG::GameSlice::SetupSceneLayers(UFG::GameSlice *this)
{
  UFG::GameSlice *v1; // r13
  UFG::SceneSettings *v2; // rbp
  unsigned int v3; // esi
  signed __int64 v4; // rdx
  const char *v5; // rdi
  char v6; // bl
  UFG::SceneSettings *v7; // rbp
  unsigned int i; // edi
  signed __int64 v9; // rbx
  UFG::qBaseTreeRB *v10; // rax
  UFG::SceneLayer *v11; // rsi
  UFG::SceneSettings *v12; // rbp
  unsigned int j; // esi
  signed __int64 v14; // rcx
  SSActor *v15; // rbx
  SSObjectBaseVtbl *v16; // rdi
  ASymbol *v17; // rax
  SSInstance **v18; // r8
  UFG::SceneSettings *v19; // r15
  int v20; // ebp
  UFG::SimObjectCharacter *v21; // r8
  signed __int64 v22; // rsi
  unsigned __int16 v23; // cx
  UFG::TSActorComponent *v24; // rax
  UFG::TSActor *v25; // r14
  bool v26; // di
  AObjReusePool<SSBoolean> *v27; // rax
  AObjReusePool<SSBoolean> *v28; // rbx
  unsigned int v29; // eax
  unsigned int v30; // eax
  unsigned int v31; // eax
  __int64 v32; // rcx
  SSBoolean **v33; // rax
  unsigned int v34; // eax
  __int64 v35; // rdx
  unsigned int v36; // eax
  bool v37; // di
  AObjReusePool<SSBoolean> *v38; // rax
  AObjReusePool<SSBoolean> *v39; // rbx
  unsigned int v40; // eax
  unsigned int v41; // eax
  unsigned int v42; // eax
  __int64 v43; // rcx
  SSBoolean **v44; // rax
  unsigned int v45; // eax
  __int64 v46; // rdx
  unsigned int v47; // eax
  unsigned __int8 v48; // di
  AObjReusePool<SSBoolean> *v49; // rax
  AObjReusePool<SSBoolean> *v50; // rbx
  unsigned int v51; // eax
  unsigned int v52; // eax
  unsigned int v53; // eax
  __int64 v54; // rcx
  SSBoolean **v55; // rax
  unsigned int v56; // eax
  __int64 v57; // rdx
  SSObjectBaseVtbl *v58; // rbx
  ASymbol *v59; // rax
  UFG::SceneSettings *v60; // rsi
  unsigned int v61; // edi
  UFG::GameStatTracker *k; // rax
  signed __int64 v63; // rbx
  UFG::GameStatTracker *v64; // rcx
  UFG::qString *v65; // rcx
  UFG::GameStatTracker *v66; // rcx
  UFG::GameStatTracker *v67; // rcx
  UFG::SceneSettings *v68; // rsi
  int v69; // edi
  signed __int64 v70; // rbx
  UFG::GameStatTracker *v71; // rcx
  UFG::qString *v72; // rcx
  UFG::GameStatTracker *v73; // rcx
  UFG::GameStatTracker *v74; // rax
  signed __int64 v75; // [rsp+30h] [rbp-78h]
  SSInstance *v76; // [rsp+38h] [rbp-70h]
  __int64 v77; // [rsp+40h] [rbp-68h]
  __int64 v78; // [rsp+48h] [rbp-60h]
  __int64 v79; // [rsp+50h] [rbp-58h]
  ASymbol result; // [rsp+B0h] [rbp+8h]
  ASymbol v81; // [rsp+B8h] [rbp+10h]
  SSInstance *v82; // [rsp+C0h] [rbp+18h]
  SSInstance *v83; // [rsp+C8h] [rbp+20h]

  v75 = -2i64;
  v1 = this;
  v2 = this->mSceneSettings;
  if ( v2 )
  {
    v3 = 0;
    if ( v2->mAltLayerSetupOnStart.size )
    {
      do
      {
        v4 = (signed __int64)&v2->mAltLayerSetupOnStart.p[v3];
        v5 = *(const char **)(v4 + 24);
        v6 = *(_BYTE *)(v4 + 41);
        UFG::SectionLayout::SetLayerActive(v5, *(_BYTE *)(v4 + 41));
        UFG::SectionChooser::FlushAltLayer(v5, v6);
        ++v3;
      }
      while ( v3 < v2->mAltLayerSetupOnStart.size );
    }
    v7 = v1->mSceneSettings;
    for ( i = 0; i < v7->mLayerSetupOnStart.size; ++i )
    {
      v9 = (signed __int64)&v7->mLayerSetupOnStart.p[i];
      v10 = UFG::Scene::FindOrCreateLayer(&UFG::Scene::msDefault, (UFG::qSymbol *)v9);
      v11 = (UFG::SceneLayer *)v10;
      if ( v10 )
      {
        if ( *(_BYTE *)(v9 + 4) )
        {
          UFG::SceneLayer::EnableGeographical((UFG::SceneLayer *)v10, 1, PERSISTENT);
          UFG::SceneLayer::EnableAutoActivate(v11, *(_BYTE *)(v9 + 6), PERSISTENT);
        }
        UFG::SceneLayer::EnableActivate(v11, *(_BYTE *)(v9 + 7), PERSISTENT, 0);
      }
    }
    v12 = v1->mSceneSettings;
    for ( j = 0; j < v12->mVendorSetupOnStart.size; ++j )
    {
      v14 = (signed __int64)&v12->mVendorSetupOnStart.p[j];
      if ( *(_BYTE *)(v14 + 4) )
      {
        v82 = SSSymbol::as_instance((ASymbol *)v14);
        v15 = SkookumScript::c_world_p;
        v16 = SkookumScript::c_world_p->vfptr;
        v17 = ASymbol::create(&result, "enable_vendor_by_type", 0xFFFFFFFF, ATerm_long);
        v18 = &v82;
      }
      else
      {
        v83 = SSSymbol::as_instance((ASymbol *)v14);
        v15 = SkookumScript::c_world_p;
        v16 = SkookumScript::c_world_p->vfptr;
        v17 = ASymbol::create(&v81, "disable_vendor_by_type", 0xFFFFFFFF, ATerm_long);
        v18 = &v83;
      }
      ((void (__fastcall *)(SSActor *, ASymbol *, SSInstance **, signed __int64, _QWORD, _QWORD, signed __int64))v16[1].set_data_by_name)(
        v15,
        v17,
        v18,
        1i64,
        0i64,
        0i64,
        v75);
    }
    v19 = v1->mSceneSettings;
    v20 = 0;
    if ( v19->mDisguiseSetupOnStart.size > 0 )
    {
      v21 = LocalPlayer;
      while ( 1 )
      {
        v22 = (signed __int64)&v19->mDisguiseSetupOnStart.p[v20];
        if ( !v21 )
          goto LABEL_55;
        v23 = v21->m_Flags;
        if ( (v23 >> 14) & 1 )
        {
          v24 = (UFG::TSActorComponent *)v21->m_Components.p[4].m_pComponent;
        }
        else if ( (v23 & 0x8000u) == 0 )
        {
          if ( (v23 >> 13) & 1 )
          {
            v24 = (UFG::TSActorComponent *)v21->m_Components.p[3].m_pComponent;
          }
          else if ( (v23 >> 12) & 1 )
          {
            v24 = (UFG::TSActorComponent *)v21->m_Components.p[2].m_pComponent;
          }
          else
          {
            v24 = (UFG::TSActorComponent *)UFG::SimObject::GetComponentOfType(
                                             (UFG::SimObject *)&v21->vfptr,
                                             UFG::TSActorComponent::_TypeUID);
            v21 = LocalPlayer;
          }
        }
        else
        {
          v24 = (UFG::TSActorComponent *)v21->m_Components.p[4].m_pComponent;
        }
        if ( !v24 )
          goto LABEL_55;
        v25 = UFG::TSActorComponent::GetActor(v24);
        if ( v25 )
          break;
LABEL_54:
        v21 = LocalPlayer;
LABEL_55:
        if ( ++v20 >= v19->mDisguiseSetupOnStart.size )
          goto LABEL_56;
      }
      v76 = SSSymbol::as_instance((ASymbol *)v22);
      v26 = *(_BYTE *)(v22 + 4) == 0;
      v27 = SSBoolean::get_pool();
      v28 = v27;
      v29 = v27->i_pool.i_count;
      if ( v29 )
      {
        v34 = v29 - 1;
        v28->i_pool.i_count = v34;
        v32 = v34;
        v33 = v28->i_pool.i_array_p;
      }
      else
      {
        if ( !v28->i_exp_pool.i_count )
          AObjReusePool<SSBoolean>::append_block(v28, v28->i_expand_size);
        v30 = v28->i_exp_pool.i_count;
        if ( !v30 )
        {
          v35 = 0i64;
LABEL_37:
          *(_QWORD *)(v35 + 32) = v26;
          *(_DWORD *)(v35 + 16) = 1;
          v36 = SSObjectBase::c_ptr_id_prev + 1;
          SSObjectBase::c_ptr_id_prev = v36;
          *(_DWORD *)(v35 + 8) = v36;
          v77 = v35;
          v37 = *(_BYTE *)(v22 + 5) == 0;
          v38 = SSBoolean::get_pool();
          v39 = v38;
          v40 = v38->i_pool.i_count;
          if ( v40 )
          {
            v45 = v40 - 1;
            v39->i_pool.i_count = v45;
            v43 = v45;
            v44 = v39->i_pool.i_array_p;
          }
          else
          {
            if ( !v39->i_exp_pool.i_count )
              AObjReusePool<SSBoolean>::append_block(v39, v39->i_expand_size);
            v41 = v39->i_exp_pool.i_count;
            if ( !v41 )
            {
              v46 = 0i64;
LABEL_45:
              *(_QWORD *)(v46 + 32) = v37;
              *(_DWORD *)(v46 + 16) = 1;
              v47 = SSObjectBase::c_ptr_id_prev + 1;
              SSObjectBase::c_ptr_id_prev = v47;
              *(_DWORD *)(v46 + 8) = v47;
              v78 = v46;
              v48 = *(_BYTE *)(v22 + 6);
              v49 = SSBoolean::get_pool();
              v50 = v49;
              v51 = v49->i_pool.i_count;
              if ( v51 )
              {
                v56 = v51 - 1;
                v50->i_pool.i_count = v56;
                v54 = v56;
                v55 = v50->i_pool.i_array_p;
              }
              else
              {
                if ( !v50->i_exp_pool.i_count )
                  AObjReusePool<SSBoolean>::append_block(v50, v50->i_expand_size);
                v52 = v50->i_exp_pool.i_count;
                if ( !v52 )
                {
                  v57 = 0i64;
                  goto LABEL_53;
                }
                v53 = v52 - 1;
                v50->i_exp_pool.i_count = v53;
                v54 = v53;
                v55 = v50->i_exp_pool.i_array_p;
              }
              v57 = (__int64)v55[v54];
LABEL_53:
              *(_QWORD *)(v57 + 32) = v48;
              *(_DWORD *)(v57 + 16) = 1;
              *(_DWORD *)(v57 + 8) = ++SSObjectBase::c_ptr_id_prev;
              v79 = v57;
              v58 = v25->vfptr;
              v59 = ASymbol::create(&result, "set_disguise", 0xFFFFFFFF, ATerm_long);
              ((void (__fastcall *)(UFG::TSActor *, ASymbol *, SSInstance **, signed __int64, _QWORD, _QWORD, signed __int64))v58[1].set_data_by_name)(
                v25,
                v59,
                &v76,
                4i64,
                0i64,
                0i64,
                v75);
              goto LABEL_54;
            }
            v42 = v41 - 1;
            v39->i_exp_pool.i_count = v42;
            v43 = v42;
            v44 = v39->i_exp_pool.i_array_p;
          }
          v46 = (__int64)v44[v43];
          goto LABEL_45;
        }
        v31 = v30 - 1;
        v28->i_exp_pool.i_count = v31;
        v32 = v31;
        v33 = v28->i_exp_pool.i_array_p;
      }
      v35 = (__int64)v33[v32];
      goto LABEL_37;
    }
LABEL_56:
    v60 = v1->mSceneSettings;
    v61 = 0;
    for ( k = UFG::GameStatTracker::mspInstance; v61 < v60->mLoadingHintSetupOnStart.size; ++v61 )
    {
      v63 = (signed __int64)&v60->mLoadingHintSetupOnStart.p[v61];
      if ( *(_DWORD *)v63 )
      {
        if ( *(_DWORD *)v63 == 1 )
        {
          if ( !(_S12_6 & 1) )
          {
            _S12_6 |= 1u;
            UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
            atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
            k = UFG::GameStatTracker::mspInstance;
          }
          v66 = &sGameStatTracker;
          if ( k )
            v66 = k;
          k = v66;
          UFG::GameStatTracker::mspInstance = v66;
          if ( *((_BYTE *)v66 + 6216) & 1 )
            continue;
          v65 = &v66->mpSnapshots[0]->mStrings[1].mValue;
        }
        else
        {
          if ( !(_S12_6 & 1) )
          {
            _S12_6 |= 1u;
            UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
            atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
            k = UFG::GameStatTracker::mspInstance;
          }
          v67 = &sGameStatTracker;
          if ( k )
            v67 = k;
          k = v67;
          UFG::GameStatTracker::mspInstance = v67;
          if ( *((_BYTE *)v67 + 6216) & 1 )
            continue;
          v65 = &v67->mpSnapshots[0]->mStrings[2].mValue;
        }
      }
      else
      {
        if ( !(_S12_6 & 1) )
        {
          _S12_6 |= 1u;
          UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
          atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
          k = UFG::GameStatTracker::mspInstance;
        }
        v64 = &sGameStatTracker;
        if ( k )
          v64 = k;
        k = v64;
        UFG::GameStatTracker::mspInstance = v64;
        if ( *((_BYTE *)v64 + 6216) & 1 )
          continue;
        v65 = (UFG::qString *)v64->mpSnapshots[0]->mStrings;
      }
      UFG::qString::Set(v65, *(const char **)(v63 + 32), *(_DWORD *)(v63 + 28), 0i64, 0);
      k = UFG::GameStatTracker::mspInstance;
    }
    v68 = v1->mSceneSettings;
    v69 = 0;
    if ( v68->mLoadingScreenSetupOnStart.size > 0 )
    {
      while ( 1 )
      {
        v70 = (signed __int64)&v68->mLoadingScreenSetupOnStart.p[v69];
        if ( !*(_DWORD *)v70 )
        {
          if ( !(_S12_6 & 1) )
          {
            _S12_6 |= 1u;
            UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
            atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
            k = UFG::GameStatTracker::mspInstance;
          }
          v71 = &sGameStatTracker;
          if ( k )
            v71 = k;
          k = v71;
          UFG::GameStatTracker::mspInstance = v71;
          if ( *((_BYTE *)v71 + 6216) & 1 )
            goto LABEL_98;
          v72 = &v71->mpSnapshots[0]->mStrings[3].mValue;
          goto LABEL_96;
        }
        if ( *(_DWORD *)v70 == 1 )
          break;
        v74 = UFG::GameStatTracker::Instance();
        if ( !(*((_BYTE *)v74 + 6216) & 1) )
        {
          v72 = &v74->mpSnapshots[0]->mStrings[5].mValue;
LABEL_96:
          UFG::qString::Set(v72, *(const char **)(v70 + 32), *(_DWORD *)(v70 + 28), 0i64, 0);
        }
        k = UFG::GameStatTracker::mspInstance;
LABEL_98:
        if ( ++v69 >= v68->mLoadingScreenSetupOnStart.size )
          return;
      }
      if ( !(_S12_6 & 1) )
      {
        _S12_6 |= 1u;
        UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
        atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
        k = UFG::GameStatTracker::mspInstance;
      }
      v73 = &sGameStatTracker;
      if ( k )
        v73 = k;
      k = v73;
      UFG::GameStatTracker::mspInstance = v73;
      if ( *((_BYTE *)v73 + 6216) & 1 )
        goto LABEL_98;
      v72 = &v73->mpSnapshots[0]->mStrings[4].mValue;
      goto LABEL_96;
    }
  }
}

// File Line: 1808
// RVA: 0x496FF0
void __fastcall UFG::GameSlice::CleanupSceneLayers(UFG::GameSlice *this)
{
  UFG::GameSlice *v1; // r13
  UFG::SceneSettings *v2; // rbp
  unsigned int v3; // esi
  signed __int64 v4; // rdx
  const char *v5; // rdi
  char v6; // bl
  UFG::SceneSettings *v7; // rbp
  unsigned int i; // edi
  signed __int64 v9; // rbx
  UFG::qBaseTreeRB *v10; // rax
  UFG::SceneLayer *v11; // rsi
  UFG::SceneSettings *v12; // rbp
  unsigned int j; // esi
  signed __int64 v14; // rcx
  SSActor *v15; // rbx
  SSObjectBaseVtbl *v16; // rdi
  ASymbol *v17; // rax
  SSInstance **v18; // r8
  UFG::SceneSettings *v19; // r15
  int v20; // edi
  UFG::SimObjectCharacter *v21; // r8
  signed __int64 v22; // rbp
  unsigned __int16 v23; // cx
  UFG::TSActorComponent *v24; // rax
  UFG::TSActor *v25; // r14
  bool v26; // si
  AObjReusePool<SSBoolean> *v27; // rax
  AObjReusePool<SSBoolean> *v28; // rbx
  unsigned int v29; // eax
  unsigned int v30; // eax
  unsigned int v31; // eax
  __int64 v32; // rcx
  SSBoolean **v33; // rax
  unsigned int v34; // eax
  __int64 v35; // rdx
  unsigned int v36; // eax
  bool v37; // si
  AObjReusePool<SSBoolean> *v38; // rax
  AObjReusePool<SSBoolean> *v39; // rbx
  unsigned int v40; // eax
  unsigned int v41; // eax
  unsigned int v42; // eax
  __int64 v43; // rcx
  SSBoolean **v44; // rax
  unsigned int v45; // eax
  __int64 v46; // rdx
  SSObjectBaseVtbl *v47; // rbx
  ASymbol *v48; // rax
  UFG::SceneSettings *v49; // rsi
  unsigned int v50; // edi
  UFG::GameStatTracker *v51; // rcx
  signed __int64 v52; // rbx
  UFG::GameStatTracker *v53; // rax
  UFG::qString *v54; // rcx
  UFG::GameStatTracker *v55; // rax
  UFG::GameStatTracker *v56; // rax
  UFG::SceneSettings *v57; // rsi
  unsigned int k; // edi
  signed __int64 v59; // rbx
  UFG::GameStatTracker *v60; // rax
  UFG::qString *v61; // rcx
  UFG::GameStatTracker *v62; // rax
  UFG::GameStatTracker *v63; // rax
  signed __int64 v64; // [rsp+30h] [rbp-68h]
  __int64 v65; // [rsp+38h] [rbp-60h]
  __int64 v66; // [rsp+40h] [rbp-58h]
  ASymbol result; // [rsp+A0h] [rbp+8h]
  ASymbol v68; // [rsp+A8h] [rbp+10h]
  SSInstance *v69; // [rsp+B0h] [rbp+18h]
  SSInstance *v70; // [rsp+B8h] [rbp+20h]

  v64 = -2i64;
  v1 = this;
  v2 = this->mSceneSettings;
  if ( v2 )
  {
    v3 = 0;
    if ( v2->mAltLayerSetupOnEnd.size )
    {
      do
      {
        v4 = (signed __int64)&v2->mAltLayerSetupOnEnd.p[v3];
        v5 = *(const char **)(v4 + 24);
        v6 = *(_BYTE *)(v4 + 41);
        UFG::SectionLayout::SetLayerActive(v5, *(_BYTE *)(v4 + 41));
        UFG::SectionChooser::FlushAltLayer(v5, v6);
        ++v3;
      }
      while ( v3 < v2->mAltLayerSetupOnEnd.size );
    }
    v7 = v1->mSceneSettings;
    for ( i = 0; i < v7->mLayerSetupOnEnd.size; ++i )
    {
      v9 = (signed __int64)&v7->mLayerSetupOnEnd.p[i];
      v10 = UFG::Scene::FindOrCreateLayer(&UFG::Scene::msDefault, (UFG::qSymbol *)v9);
      v11 = (UFG::SceneLayer *)v10;
      if ( v10 )
      {
        if ( *(_BYTE *)(v9 + 4) )
        {
          UFG::SceneLayer::EnableGeographical((UFG::SceneLayer *)v10, 1, PERSISTENT);
          UFG::SceneLayer::EnableAutoActivate(v11, *(_BYTE *)(v9 + 6), PERSISTENT);
        }
        UFG::SceneLayer::EnableActivate(v11, *(_BYTE *)(v9 + 7), PERSISTENT, 0);
      }
    }
    v12 = v1->mSceneSettings;
    for ( j = 0; j < v12->mVendorSetupOnEnd.size; ++j )
    {
      v14 = (signed __int64)&v12->mVendorSetupOnEnd.p[j];
      if ( *(_BYTE *)(v14 + 4) )
      {
        v69 = SSSymbol::as_instance((ASymbol *)v14);
        v15 = SkookumScript::c_world_p;
        v16 = SkookumScript::c_world_p->vfptr;
        v17 = ASymbol::create(&result, "enable_vendor_by_type", 0xFFFFFFFF, ATerm_long);
        v18 = &v69;
      }
      else
      {
        v70 = SSSymbol::as_instance((ASymbol *)v14);
        v15 = SkookumScript::c_world_p;
        v16 = SkookumScript::c_world_p->vfptr;
        v17 = ASymbol::create(&v68, "disable_vendor_by_type", 0xFFFFFFFF, ATerm_long);
        v18 = &v70;
      }
      ((void (__fastcall *)(SSActor *, ASymbol *, SSInstance **, signed __int64, _QWORD, _QWORD, signed __int64))v16[1].set_data_by_name)(
        v15,
        v17,
        v18,
        1i64,
        0i64,
        0i64,
        v64);
    }
    v19 = v1->mSceneSettings;
    v20 = 0;
    if ( v19->mDisguiseSetupOnEnd.size > 0 )
    {
      v21 = LocalPlayer;
      while ( 1 )
      {
        v22 = (signed __int64)&v19->mDisguiseSetupOnEnd.p[v20];
        if ( !v21 )
          goto LABEL_47;
        v23 = v21->m_Flags;
        if ( (v23 >> 14) & 1 )
        {
          v24 = (UFG::TSActorComponent *)v21->m_Components.p[4].m_pComponent;
        }
        else if ( (v23 & 0x8000u) == 0 )
        {
          if ( (v23 >> 13) & 1 )
          {
            v24 = (UFG::TSActorComponent *)v21->m_Components.p[3].m_pComponent;
          }
          else if ( (v23 >> 12) & 1 )
          {
            v24 = (UFG::TSActorComponent *)v21->m_Components.p[2].m_pComponent;
          }
          else
          {
            v24 = (UFG::TSActorComponent *)UFG::SimObject::GetComponentOfType(
                                             (UFG::SimObject *)&v21->vfptr,
                                             UFG::TSActorComponent::_TypeUID);
            v21 = LocalPlayer;
          }
        }
        else
        {
          v24 = (UFG::TSActorComponent *)v21->m_Components.p[4].m_pComponent;
        }
        if ( !v24 )
          goto LABEL_47;
        v25 = UFG::TSActorComponent::GetActor(v24);
        if ( v25 )
          break;
LABEL_46:
        v21 = LocalPlayer;
LABEL_47:
        if ( ++v20 >= v19->mDisguiseSetupOnEnd.size )
          goto LABEL_48;
      }
      v26 = *(_BYTE *)(v22 + 4) == 0;
      v27 = SSBoolean::get_pool();
      v28 = v27;
      v29 = v27->i_pool.i_count;
      if ( v29 )
      {
        v34 = v29 - 1;
        v28->i_pool.i_count = v34;
        v32 = v34;
        v33 = v28->i_pool.i_array_p;
      }
      else
      {
        if ( !v28->i_exp_pool.i_count )
          AObjReusePool<SSBoolean>::append_block(v28, v28->i_expand_size);
        v30 = v28->i_exp_pool.i_count;
        if ( !v30 )
        {
          v35 = 0i64;
LABEL_37:
          *(_QWORD *)(v35 + 32) = v26;
          *(_DWORD *)(v35 + 16) = 1;
          v36 = SSObjectBase::c_ptr_id_prev + 1;
          SSObjectBase::c_ptr_id_prev = v36;
          *(_DWORD *)(v35 + 8) = v36;
          v65 = v35;
          v37 = *(_BYTE *)(v22 + 5) == 0;
          v38 = SSBoolean::get_pool();
          v39 = v38;
          v40 = v38->i_pool.i_count;
          if ( v40 )
          {
            v45 = v40 - 1;
            v39->i_pool.i_count = v45;
            v43 = v45;
            v44 = v39->i_pool.i_array_p;
          }
          else
          {
            if ( !v39->i_exp_pool.i_count )
              AObjReusePool<SSBoolean>::append_block(v39, v39->i_expand_size);
            v41 = v39->i_exp_pool.i_count;
            if ( !v41 )
            {
              v46 = 0i64;
              goto LABEL_45;
            }
            v42 = v41 - 1;
            v39->i_exp_pool.i_count = v42;
            v43 = v42;
            v44 = v39->i_exp_pool.i_array_p;
          }
          v46 = (__int64)v44[v43];
LABEL_45:
          *(_QWORD *)(v46 + 32) = v37;
          *(_DWORD *)(v46 + 16) = 1;
          *(_DWORD *)(v46 + 8) = ++SSObjectBase::c_ptr_id_prev;
          v66 = v46;
          v47 = v25->vfptr;
          v48 = ASymbol::create(&result, "remove_disguise", 0xFFFFFFFF, ATerm_long);
          ((void (__fastcall *)(UFG::TSActor *, ASymbol *, __int64 *, signed __int64, _QWORD, _QWORD, signed __int64))v47[1].set_data_by_name)(
            v25,
            v48,
            &v65,
            2i64,
            0i64,
            0i64,
            v64);
          goto LABEL_46;
        }
        v31 = v30 - 1;
        v28->i_exp_pool.i_count = v31;
        v32 = v31;
        v33 = v28->i_exp_pool.i_array_p;
      }
      v35 = (__int64)v33[v32];
      goto LABEL_37;
    }
LABEL_48:
    v49 = v1->mSceneSettings;
    v50 = 0;
    if ( v49->mLoadingHintSetupOnEnd.size > 0 )
    {
      v51 = UFG::GameStatTracker::mspInstance;
      do
      {
        v52 = (signed __int64)&v49->mLoadingHintSetupOnEnd.p[v50];
        if ( *(_DWORD *)v52 )
        {
          if ( *(_DWORD *)v52 == 1 )
          {
            if ( !(_S12_6 & 1) )
            {
              _S12_6 |= 1u;
              UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
              atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
              v51 = UFG::GameStatTracker::mspInstance;
            }
            v55 = &sGameStatTracker;
            if ( v51 )
              v55 = v51;
            v51 = v55;
            UFG::GameStatTracker::mspInstance = v55;
            if ( *((_BYTE *)v55 + 6216) & 1 )
              goto LABEL_71;
            v54 = &v55->mpSnapshots[0]->mStrings[1].mValue;
          }
          else
          {
            if ( !(_S12_6 & 1) )
            {
              _S12_6 |= 1u;
              UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
              atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
              v51 = UFG::GameStatTracker::mspInstance;
            }
            v56 = &sGameStatTracker;
            if ( v51 )
              v56 = v51;
            v51 = v56;
            UFG::GameStatTracker::mspInstance = v56;
            if ( *((_BYTE *)v56 + 6216) & 1 )
              goto LABEL_71;
            v54 = &v56->mpSnapshots[0]->mStrings[2].mValue;
          }
        }
        else
        {
          if ( !(_S12_6 & 1) )
          {
            _S12_6 |= 1u;
            UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
            atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
            v51 = UFG::GameStatTracker::mspInstance;
          }
          v53 = &sGameStatTracker;
          if ( v51 )
            v53 = v51;
          v51 = v53;
          UFG::GameStatTracker::mspInstance = v53;
          if ( *((_BYTE *)v53 + 6216) & 1 )
            goto LABEL_71;
          v54 = (UFG::qString *)v53->mpSnapshots[0]->mStrings;
        }
        UFG::qString::Set(v54, *(const char **)(v52 + 32), *(_DWORD *)(v52 + 28), 0i64, 0);
        v51 = UFG::GameStatTracker::mspInstance;
LABEL_71:
        ++v50;
      }
      while ( v50 < v49->mLoadingHintSetupOnEnd.size );
    }
    v57 = v1->mSceneSettings;
    for ( k = 0; k < v57->mLoadingScreenSetupOnEnd.size; ++k )
    {
      v59 = (signed __int64)&v57->mLoadingScreenSetupOnEnd.p[k];
      if ( *(_DWORD *)v59 )
      {
        if ( *(_DWORD *)v59 == 1 )
        {
          v62 = UFG::GameStatTracker::Instance();
          if ( !(*((_BYTE *)v62 + 6216) & 1) )
          {
            v61 = &v62->mpSnapshots[0]->mStrings[4].mValue;
            goto LABEL_81;
          }
        }
        else
        {
          v63 = UFG::GameStatTracker::Instance();
          if ( !(*((_BYTE *)v63 + 6216) & 1) )
          {
            v61 = &v63->mpSnapshots[0]->mStrings[5].mValue;
            goto LABEL_81;
          }
        }
      }
      else
      {
        v60 = UFG::GameStatTracker::Instance();
        if ( !(*((_BYTE *)v60 + 6216) & 1) )
        {
          v61 = &v60->mpSnapshots[0]->mStrings[3].mValue;
LABEL_81:
          UFG::qString::Set(v61, *(const char **)(v59 + 32), *(_DWORD *)(v59 + 28), 0i64, 0);
          continue;
        }
      }
    }
  }
}

// File Line: 1915
// RVA: 0x4BEB80
void __fastcall UFG::GameSlice::ShutdownScript(UFG::GameSlice *this, UFG::GameSlice::CompletionStatus status, __int64 a3, __int64 a4, __int64 a5, __int64 a6, __int64 a7)
{
  UFG::GameSlice::CompletionStatus v7; // esi
  UFG::GameSlice *v8; // rdi
  UFG::GameSlice::Type v9; // eax
  char *v10; // r9
  __int64 v11; // rax
  UFG::SSGameSlice *v12; // rsi
  UFG::ProgressionTracker *v13; // rax
  UFG::ProgressionTracker *v14; // rax
  __int64 v15; // [rsp+40h] [rbp+8h]

  v7 = status;
  v8 = this;
  if ( this->mScript )
  {
    if ( !this->mpParent )
    {
      v9 = this->mType;
      if ( (signed int)v9 > 0 && v9 == 8 )
        UFG::UITiledMapRaceSplines::Clear(UFG::UIHKScreenHud::RacePath);
    }
    v10 = v8->mName.mText;
    UFG::qPrintChannel::Print(
      &UFG::gPrintChannel_HK_Progression,
      OUTPUT_LEVEL_DEBUG,
      "[Progression]: ShutdownScript for (%s)\n");
    v11 = (__int64)v8->mScript->vfptr->get_data_by_name(
                     (SSObjectBase *)&v8->mScript->vfptr,
                     (ASymbol *)&qSymbol_i_is_gameslice_completed);
    v15 = 0i64;
    *(_QWORD *)(v11 + 32) = v7 == 2;
    ((void (__fastcall *)(SSObjectBaseVtbl **, UFG::qStaticSymbol *, __int64 *, _QWORD, _QWORD, _QWORD))v8->mScript->vfptr[1].set_data_by_name)(
      &v8->mScript->vfptr,
      &qSymbol_gameslice_cleanup_private,
      &v15,
      0i64,
      0i64,
      0i64);
    UFG::GameSlice::ReturnAllAmbientActors(v8);
    v12 = v8->mScript;
    v8->mScript = 0i64;
    v8->mCleanupPending = 1;
    SSActor::enable_behavior((SSActor *)&v12->vfptr, 0);
    if ( !v8->mpParent )
      v12->vfptr->set_data_by_name((SSObjectBase *)&v12->vfptr, (ASymbol *)&qSymbol_i_gameslice_data, SSBrain::c_nil_p);
    UFG::GameSliceStreamer::DeferScriptDelete(UFG::GameSliceStreamer::mspInstance, v12);
    if ( v8->mCleanupPending )
    {
      v13 = UFG::ProgressionTracker::Instance();
      UFG::ProgressionTracker::MarkCleanup(v13);
    }
    v14 = UFG::ProgressionTracker::Instance();
    UFG::ObjectiveTracker::OnGameSliceCleanup(&v14->mObjectiveTracker, v8);
  }
  UFG::GameSliceStreamer::CancelStream(UFG::GameSliceStreamer::mspInstance, v8, a3, a4);
}

// File Line: 1986
// RVA: 0x49DD90
void __fastcall UFG::GameSlice::End(UFG::GameSlice *this, UFG::GameSlice::CompletionStatus status, __int64 a3, __int64 a4, __int64 a5, __int64 a6, __int64 a7)
{
  bool v7; // zf
  UFG::GameSlice::CompletionStatus v8; // esi
  UFG::GameSlice *v9; // rdi
  char *v10; // r9
  __int64 v11; // rbx
  UFG::ProgressionTracker *v12; // rax
  __int64 v13; // rbx
  UFG::ProgressionTracker *v14; // rax
  __int64 v15; // r8
  UFG::GameSlice *v16; // r9
  __int64 v17; // rax
  UFG::ProgressionTracker *v18; // rax
  char *v19; // r9
  UFG::ProgressionTracker *v20; // rax
  UFG::qBaseTreeRB *v21; // rax
  UFG::qSymbol name; // [rsp+38h] [rbp+10h]

  v7 = this->mCountedStats == 0;
  this->mCompletionStatus = status;
  this->mCompletionStatusTimestamp = UFG::Metrics::msInstance.mSimTimeMSec;
  v8 = status;
  v9 = this;
  if ( !v7 )
  {
    v10 = this->mName.mText;
    UFG::qPrintChannel::Print(
      &UFG::gPrintChannel_HK_Progression,
      OUTPUT_LEVEL_DEBUG,
      "[Progression]: ScriptObjective ending for (%s)\n");
    UFG::ProgressionTracker::Instance();
    v11 = v9->mType;
    v12 = UFG::ProgressionTracker::Instance();
    --v12->gActiveGameSlices[v11];
    if ( !v9->mpParent && v9->mType > 0 )
    {
      UFG::ProgressionTracker::Instance();
      v13 = v9->mType;
      v14 = UFG::ProgressionTracker::Instance();
      --v14->gActiveContainers[v13];
    }
    v9->mCountedStats = 0;
  }
  UFG::ProgressionTriggerComponent::DisableTrigger(v9, 0);
  if ( v9->mScript )
  {
    if ( v8 - 2 <= 1 )
      UFG::GameStatAction::GameSliceAction::Stop(v9, v8 == 2);
    if ( v8 == 2 && !v9->mpParent )
    {
      v17 = v9->mType;
      if ( (signed int)v17 > 0 )
      {
        if ( gGameSliceTypePriority[v17] >= 4 )
        {
          v18 = UFG::ProgressionTracker::Instance();
          v18->mContainerCompleted = 1;
          v18->mContainerCompletedTimestamp = UFG::Metrics::msInstance.mSimTimeMSec + 10;
        }
        UFG::GameSlice::_HandleCompletionRewards(v9, 0);
        v16 = UFG::ProgressionTracker::Instance()->mpActiveMaster;
        if ( v16 == v9 )
        {
          v19 = v16->mName.mText;
          UFG::qPrintChannel::Print(
            &UFG::gPrintChannel_HK_Snapshot,
            OUTPUT_LEVEL_NORMAL,
            "[GameSnapshot]: *** CompletedGameSlice called (%s) called *** \n");
          v20 = UFG::ProgressionTracker::Instance();
          if ( v20->mActiveMasterMode )
          {
            *(_WORD *)&v20->mMasterModeChanged = 257;
            v20->mActiveMasterMode = 0;
          }
        }
      }
    }
    UFG::GameSlice::ShutdownScript(v9, v8, v15, (__int64)v16, a5, a6, a7);
  }
  else if ( v9->mLayerEnabledByMe )
  {
    name.mUID = v9->mLayerName.mUID;
    v9->mLayerEnabledByMe = 0;
    v21 = UFG::Scene::FindLayer(&UFG::Scene::msDefault, &name);
    if ( v21 )
      UFG::SceneLayer::EnableActivate((UFG::SceneLayer *)v21, 0, PERSISTENT, 0);
  }
}

// File Line: 2118
// RVA: 0x152C090
__int64 UFG::_dynamic_initializer_for__gGameSliceName_M_VE__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("M_VE", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::gGameSliceName_M_VE, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__gGameSliceName_M_VE__);
}

// File Line: 2121
// RVA: 0x4C92B0
void __fastcall UFG::GameSlice::_HandleCompletionRewards(UFG::GameSlice *this, UFG::ShowRewardType showRewardType)
{
  UFG::ShowRewardType v2; // ebx
  UFG::GameSlice *v3; // rdi
  UFG::GameSlice *v4; // rax
  UFG::ProgressionTracker *v5; // rax
  UFG::qPropertySet *v6; // rbx
  UFG::qPropertySet *v7; // rax
  UFG::qPropertySet *v8; // rax
  signed int i; // ebx
  UFG::GameSlice *v10; // rcx
  UFG::qSymbol v11; // [rsp+20h] [rbp-18h]
  UFG::qSymbol propSetName; // [rsp+50h] [rbp+18h]
  UFG::qSymbol result; // [rsp+58h] [rbp+20h]

  v2 = showRewardType;
  v3 = this;
  if ( UFG::ProgressionTracker::Instance()->mModeType == 2 )
    return;
  if ( v2 == ShowReward && gGameSliceTypePriority[v3->mType] >= 4 )
  {
    if ( (v4 = v3->mpParent) != 0i64 && v4->mAutosave || v3->mAutosave )
      UFG::ProgressionTracker::Instance()->mpAutoSaveQueuedSlice = v3;
  }
  v5 = UFG::ProgressionTracker::Instance();
  UFG::ProgressionTracker::SetLastCompleted(v5, v3);
  if ( v3->mNode.mUID == UFG::gGameSliceName_M_VE.mUID )
  {
    if ( v2 == 1 )
    {
      UFG::qSymbol::create_from_string(&result, "default-rewards-progression-M_VEM");
      UFG::qSymbol::create_from_string(&v11, "default-rewards-progression-M_VEF");
      propSetName.mUID = result.mUID;
      v6 = 0i64;
      if ( UFG::PropertySetManager::FindPropertySet(&propSetName) )
        v7 = UFG::PropertySetManager::GetPropertySet(&propSetName);
      else
        v7 = 0i64;
      UFG::RewardsHandler::HandleRewards(DoNotShowReward, v7, 0i64);
      propSetName.mUID = v11.mUID;
      if ( UFG::PropertySetManager::FindPropertySet(&propSetName) )
        v6 = UFG::PropertySetManager::GetPropertySet(&propSetName);
      UFG::RewardsHandler::HandleRewards(DoNotShowReward, v6, 0i64);
      return;
    }
  }
  else
  {
    v8 = UFG::GameSlice::GetRewardsProperties(v3);
    UFG::RewardsHandler::HandleRewards(v2, v8, 0i64);
  }
  if ( v2 == ShowReward )
  {
    for ( i = 0; i < (signed int)v3->mReEnableSlices.mCount; ++i )
    {
      v10 = v3->mReEnableSlices.mppArray[i];
      if ( v10 && v10->mState == 8 )
        UFG::GameSlice::ForceLock(v10, 0);
    }
  }
}

// File Line: 2189
// RVA: 0x4C9960
void __fastcall UFG::GameSlice::_SimulateUnlock(UFG::GameSlice *this, bool simulateRewards)
{
  __int64 v2; // rax
  bool v3; // bp
  UFG::GameSlice *v4; // r13
  UFG::GameSlice **v5; // r14
  unsigned __int64 i; // r15
  UFG::GameSlice *v7; // rdi
  __int64 v8; // rax
  UFG::GameSlice **v9; // rbx
  unsigned __int64 j; // rsi
  __int64 v11; // rax
  UFG::GameSlice **v12; // rbx
  unsigned __int64 k; // rsi
  bool v14; // zf
  UFG::GameSlice **v15; // rax
  __int64 v16; // rbx
  UFG::GameSlice *v17; // rsi
  __int64 v18; // rdi
  __int64 v19; // r14
  __int64 v20; // rdi

  v2 = (signed int)this->mDependents.mCount;
  v3 = simulateRewards;
  v4 = this;
  if ( (_DWORD)v2 )
  {
    v5 = this->mDependents.mppArray;
    for ( i = (unsigned __int64)&v5[v2]; (unsigned __int64)v5 < i; v7->mDirty = 1 )
    {
      v7 = *v5;
      v8 = (signed int)(*v5)->mDependents.mCount;
      if ( (_DWORD)v8 )
      {
        v9 = v7->mDependents.mppArray;
        for ( j = (unsigned __int64)&v9[v8]; (unsigned __int64)v9 < j; ++v9 )
        {
          if ( (*v9)->mState != 8 )
            UFG::GameSlice::_SimulateComplete(*v9, v3);
        }
      }
      v11 = (signed int)v7->mChildren.mCount;
      if ( (_DWORD)v11 )
      {
        v12 = v7->mChildren.mppArray;
        for ( k = (unsigned __int64)&v12[v11]; (unsigned __int64)v12 < k; ++v12 )
        {
          if ( (*v12)->mState != 8 )
            UFG::GameSlice::_SimulateComplete(*v12, v3);
        }
      }
      if ( !v7->mCompletionCount )
      {
        v14 = v7->mState == 8;
        v7->mCompletionStatus = 2;
        v7->mCompletionStatusTimestamp = UFG::Metrics::msInstance.mSimTimeMSec;
        if ( !v14 && v3 )
          UFG::GameSlice::_HandleCompletionRewards(v7, DoNotShowReward);
        ++v7->mCompletionCount;
        v7->mState = 8;
      }
      ++v5;
    }
  }
  if ( v4->mChildren.mCount )
  {
    v15 = v4->mChildren.mppArray;
    v16 = 0i64;
    v17 = *v15;
    v18 = 0i64;
    v19 = (*v15)->mDependents.mCount;
    if ( v19 > 0 )
    {
      do
        UFG::GameSlice::_SimulateComplete(v17->mDependents.mppArray[v18++], v3);
      while ( v18 < v19 );
    }
    v20 = v17->mChildren.mCount;
    if ( v20 > 0 )
    {
      do
        UFG::GameSlice::_SimulateComplete(v17->mChildren.mppArray[v16++], v3);
      while ( v16 < v20 );
    }
  }
}

// File Line: 2227
// RVA: 0x4C9810
void __fastcall UFG::GameSlice::_MarkExclusiveChild(UFG::GameSlice *this, UFG::GameSlice *pChild)
{
  UFG::GameSlice **v2; // rax

  v2 = &this->mpParent;
  this->mExclusiveChild = pChild;
  if ( this->mpParent )
  {
    do
    {
      v2 = &(*v2)->mpParent;
      *(v2 - 14) = pChild;
    }
    while ( *v2 );
  }
}

// File Line: 2239
// RVA: 0x4BD6F0
UFG::GameSlice::SetState

// File Line: 2362
// RVA: 0x4C3F20
void __fastcall UFG::GameSlice::Unlock(UFG::GameSlice *this, UFG::GameSlice::State newState)
{
  UFG::GameSlice::State v2; // eax
  UFG::GameSlice::State v3; // edi
  UFG::GameSlice *v4; // rbx
  UFG::GameSlice *v5; // rcx

  v2 = this->mState;
  v3 = newState;
  v4 = this;
  if ( v2 )
  {
    if ( v2 == 1 )
      UFG::GameSlice::Start(this);
    if ( v4->mState > v3 )
      v3 = v4->mState;
    v4->mState = v3;
  }
  else
  {
    UFG::ProgressionTracker::Instance()->mDirty = 1;
    v5 = v4->mpParent;
    v4->mState = v3;
    if ( v5 )
      UFG::GameSlice::Unlock(v5, STATE_UNLOCKED);
    UFG::GameSlice::Start(v4);
  }
}

// File Line: 2397
// RVA: 0x4BC130
void __fastcall UFG::GameSlice::SetEnabled(UFG::GameSlice *this, bool isEnabled)
{
  __int64 v2; // rbp
  __int64 v3; // rbx
  bool v4; // si
  UFG::GameSlice *v5; // rdi

  v2 = this->mChildren.mCount;
  v3 = 0i64;
  v4 = isEnabled;
  v5 = this;
  for ( this->mEnabled = isEnabled; v3 < v2; ++v3 )
    UFG::GameSlice::SetEnabled(v5->mChildren.mppArray[v3], v4);
}

// File Line: 2433
// RVA: 0x4BDCE0
void __fastcall UFG::GameSlice::SetType(UFG::GameSlice *this, UFG::GameSlice::Type type)
{
  __int64 v2; // rbp
  __int64 v3; // rbx
  UFG::GameSlice::Type v4; // esi
  UFG::GameSlice *v5; // rdi

  v2 = this->mChildren.mCount;
  v3 = 0i64;
  v4 = type;
  v5 = this;
  if ( v2 <= 0 )
  {
    this->mType = type;
  }
  else
  {
    do
      UFG::GameSlice::SetType(v5->mChildren.mppArray[v3++], v4);
    while ( v3 < v2 );
    v5->mType = v4;
  }
}

// File Line: 2464
// RVA: 0x4967E0
char __fastcall UFG::GameSlice::CanBeEnabled(UFG::GameSlice *this)
{
  char result; // al

  if ( this->mRoot )
    goto LABEL_9;
  if ( (signed int)this->mChildren.mCount > 0 )
    this = *this->mChildren.mppArray;
  if ( UFG::GameSlice::CanDependantsBeEnabled(this) )
LABEL_9:
    result = 1;
  else
    result = 0;
  return result;
}

// File Line: 2489
// RVA: 0x4A6070
UFG::qPropertySet *__fastcall UFG::GameSlice::GetRewardsProperties(UFG::GameSlice *this)
{
  UFG::GameSlice *v1; // rdi
  UFG::qPropertySet *result; // rax

  v1 = this;
  if ( this->mpParent
    || this->mType <= 0
    || this->mCompletionCount <= 1 && UFG::ProgressionTracker::Instance()->mModeType != 2
    || (UFG::PropertySetHandle::Bind(&v1->mRepeatedRewardsProperties),
        (result = v1->mRepeatedRewardsProperties.mpPropSet) == 0i64) )
  {
    UFG::PropertySetHandle::Bind(&v1->mRewardsProperties);
    result = v1->mRewardsProperties.mpPropSet;
  }
  return result;
}

// File Line: 2528
// RVA: 0x499F00
void __fastcall UFG::GameSlice::CreateRuntimeRewardsPropertySets(UFG::GameSlice *this)
{
  UFG::GameSlice *v1; // rbx
  UFG::qPropertySet *v2; // rsi
  UFG::qString *v3; // rax
  UFG::qPropertySet *v4; // rbp
  UFG::qPropertySet *v5; // r14
  UFG::PropertySetHandle *v6; // rdi
  UFG::qString *v7; // rax
  UFG::qPropertySet *v8; // rbx
  UFG::qString result; // [rsp+28h] [rbp-40h]
  UFG::qSymbol propSetName; // [rsp+70h] [rbp+8h]
  UFG::qSymbol name; // [rsp+78h] [rbp+10h]

  v1 = this;
  v2 = 0i64;
  if ( !UFG::PropertySetHandle::IsValid(&this->mRewardsProperties) )
  {
    v3 = UFG::qString::FormatEx(&result, "default-rewards-progression-%s", v1->mName.mText);
    UFG::qSymbol::create_from_string(&propSetName, v3->mData);
    UFG::qString::~qString(&result);
    v4 = 0i64;
    v5 = UFG::PropertySetManager::FindPropertySet(&propSetName);
    if ( v5 )
    {
      UFG::qSymbol::create_suffix(&name, &propSetName, "_runtime");
      v4 = UFG::qPropertySet::CreateContainedSet(&name, "GameSlice");
      UFG::PSWrapper::AppendParentLocal(v4, v5);
      UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&name);
      UFG::qPrintChannel::Print(
        &UFG::gPrintChannel_HK_Progression,
        OUTPUT_LEVEL_DEBUG,
        "[GameSlice]: Created runtime reward property set (%s)\n");
    }
    UFG::PropertySetHandle::SetPropSet(&v1->mRewardsProperties, v4);
  }
  v6 = &v1->mRepeatedRewardsProperties;
  if ( !UFG::PropertySetHandle::IsValid(&v1->mRepeatedRewardsProperties) )
  {
    v7 = UFG::qString::FormatEx(&result, "default-rewards-progression-%s_repeat", v1->mName.mText);
    UFG::qSymbol::create_from_string(&propSetName, v7->mData);
    UFG::qString::~qString(&result);
    v8 = UFG::PropertySetManager::FindPropertySet(&propSetName);
    if ( v8 )
    {
      UFG::qSymbol::create_suffix(&name, &propSetName, "_runtime");
      v2 = UFG::qPropertySet::CreateContainedSet(&name, "GameSlice");
      UFG::PSWrapper::AppendParentLocal(v2, v8);
      UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&name);
      UFG::qPrintChannel::Print(
        &UFG::gPrintChannel_HK_Progression,
        OUTPUT_LEVEL_DEBUG,
        "[GameSlice]: Created runtime reward property set (%s)\n");
    }
    UFG::PropertySetHandle::SetPropSet(v6, v2);
  }
}

// File Line: 2543
// RVA: 0x496820
__int64 __fastcall UFG::GameSlice::CanDependantsBeEnabled(UFG::GameSlice *this)
{
  __int64 result; // rax
  UFG::GameSlice *v2; // rsi
  __int64 v3; // rbx
  unsigned __int8 v4; // di
  char v5; // al

  result = this->mDependents.mCount;
  v2 = this;
  if ( (_DWORD)result )
  {
    v3 = 0i64;
    v4 = 1;
    if ( (signed int)result > 0 )
    {
      do
      {
        v5 = UFG::GameSlice::CanBeEnabled(v2->mDependents.mppArray[v3]);
        v3 = (unsigned int)(v3 + 1);
        v4 &= v5;
      }
      while ( (signed int)v3 < (signed int)v2->mDependents.mCount );
    }
    result = v4;
  }
  return result;
}

// File Line: 2563
// RVA: 0x4C91A0
__int64 __fastcall UFG::WillContainerCompleteIfIComplete(UFG::GameSlice *pContainer, UFG::GameSlice *pMySelf)
{
  __int64 v2; // r9
  UFG::GameSlice *v3; // r10
  unsigned __int8 v4; // r8
  UFG::GameSlice **v5; // rcx
  UFG::GameSlice *v6; // rax
  signed int v7; // edx

  v2 = pContainer->mChildren.mCount;
  v3 = pMySelf;
  v4 = 1;
  if ( v2 > 0 )
  {
    v5 = pContainer->mChildren.mppArray;
    do
    {
      v6 = *v5;
      v7 = (*v5)->mState;
      if ( v7 >= 1 || v6->mCompletionCount > 0 )
      {
        if ( v7 != 8 && !v6->mOptional && v6 != v3 )
          v4 = 0;
      }
      else if ( !v6->mOptional )
      {
        v4 = 0;
      }
      ++v5;
      --v2;
    }
    while ( v2 );
  }
  return v4;
}

// File Line: 2594
// RVA: 0x499710
void __fastcall UFG::GameSlice::CompleteSlice(UFG::GameSlice *this)
{
  UFG::GameSlice *v1; // rbx
  unsigned int v2; // esi
  UFG::GameSlice *v3; // rdi
  __int64 v4; // rbp
  __int64 v5; // r14
  UFG::SSGameSlice *v6; // rcx
  UFG::SSGameSlice *v7; // rcx
  UFG::GameSlice::State v8; // edi
  UFG::GameSlice *v9; // rcx
  UFG::GameSlice *v10; // rcx
  SSInstance *args_pp; // [rsp+88h] [rbp+10h]

  v1 = this;
  v2 = _S19_1;
  if ( !(_S19_1 & 1) )
  {
    _S19_1 |= 1u;
    UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
    atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
    v2 = _S19_1;
  }
  UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
  if ( unk_14240B994 != 2 )
    goto LABEL_42;
  v3 = v1;
  if ( v1 )
  {
    while ( v3->mpParent )
      v3 = v3->mpParent;
  }
  if ( !UFG::WillContainerCompleteIfIComplete(v3, v1) )
    goto LABEL_42;
  v4 = 0i64;
  v5 = v3->mChildren.mCount;
  if ( v5 > 0 )
  {
    do
    {
      v6 = v3->mChildren.mppArray[v4]->mScript;
      if ( v6 )
        SSActor::suspend_coroutines((SSActor *)&v6->vfptr);
      ++v4;
    }
    while ( v4 < v5 );
    v2 = _S19_1;
  }
  v7 = v3->mScript;
  if ( v7 )
  {
    SSActor::suspend_coroutines((SSActor *)&v7->vfptr);
    v2 = _S19_1;
  }
  if ( v1->mScript )
  {
    if ( !(v2 & 1) )
    {
      _S19_1 = v2 | 1;
      UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
      atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
    }
    UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
    if ( v3 == (UFG::GameSlice *)unk_14240B6D0 )
    {
      args_pp = 0i64;
      SSInstance::coroutine_call(
        (SSInstance *)&v1->mScript->vfptr,
        (ASymbol *)&qSymbol__gameslice_challenge_success_handler_private,
        &args_pp,
        0,
        0,
        0.0,
        0i64,
        0i64);
    }
    ++v1->mCompletionCount;
  }
  else
  {
LABEL_42:
    v8 = v1->mState;
    if ( v8 != 8 )
    {
      if ( !(v2 & 1) )
      {
        _S19_1 = v2 | 1;
        UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
        atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
      }
      UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
      unk_14240B986 = 1;
      if ( v1->mScript )
        UFG::ProgressionTriggerComponent::DisableTrigger(v1, 1);
      v1->mState = 8;
      ++v1->mCompletionCount;
      UFG::GameSlice::End(v1, (UFG::GameSlice::CompletionStatus)2u);
      if ( v1->mExclusive || v1->mRandomExclusive )
      {
        if ( !((v8 - 2) & 0xFFFFFFFD) && v1->mExclusiveChild == v1 )
        {
          v1->mExclusiveChild = 0i64;
          v9 = v1->mpParent;
          if ( v9 )
            UFG::GameSlice::_MarkExclusiveChild(v9, 0i64);
        }
        if ( v1->mState == 4 )
        {
          v1->mExclusiveChild = v1;
          v10 = v1->mpParent;
          if ( v10 )
            UFG::GameSlice::_MarkExclusiveChild(v10, v1);
          v1->mRequiresSave = 0;
        }
        if ( v1->mState == 8 && v1->mExclusive && v1->mPersistent )
          v1->mRequiresSave = 1;
      }
    }
  }
}

// File Line: 2641
// RVA: 0x4A01C0
void __fastcall UFG::GameSlice::FailSlice(UFG::GameSlice *this, UFG::qString *caption)
{
  UFG::qString *v2; // rdi
  UFG::GameSlice *v3; // rsi
  UFG::GameStatTracker *v4; // rax
  UFG::GameStatTracker *v5; // rbx
  UFG::SSGameSlice *v6; // rbx
  SSObjectBaseVtbl *v7; // rdi
  AString *v8; // rax
  SSInstance *v9; // rax
  AStringRef *v10; // rbx
  bool v11; // zf
  AObjReusePool<AStringRef> *v12; // rax
  AObjBlock<AStringRef> *v13; // rcx
  unsigned __int64 v14; // rdx
  bool v15; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v16; // rcx
  AString v17; // [rsp+60h] [rbp+8h]

  v2 = caption;
  v3 = this;
  if ( this->mScript )
  {
    if ( !(_S19_1 & 1) )
    {
      _S19_1 |= 1u;
      UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
      atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
    }
    UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
    if ( unk_14240B994 != 2 )
    {
      v4 = UFG::GameStatTracker::Instance();
      if ( !(*((_BYTE *)v4 + 6216) & 1) )
      {
        UFG::PersistentData::MapInt::ApplyDelta(v4->mpSnapshots[0]->mpMapInts[36], (UFG::qSymbol *)&v3->mNode.mUID, 1);
        if ( UFG::GameStatAction::PostStat::sIsEnabled )
        {
          v5 = &sGameStatTracker;
          if ( !(_S12_6 & 1) )
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
    AString::AString(&v17, v2->mData, 0);
    v6 = v3->mScript;
    v7 = v6->vfptr;
    v9 = SSString::as_instance(v8);
    v7->set_data_by_name((SSObjectBase *)&v6->vfptr, (ASymbol *)&qSymbol_i_gameslice_fail_caption, v9);
    v10 = v17.i_str_ref_p;
    v11 = v17.i_str_ref_p->i_ref_count == 1;
    --v10->i_ref_count;
    if ( v11 )
    {
      if ( v10->i_deallocate )
        AMemory::c_free_func(v10->i_cstr_p);
      v12 = AStringRef::get_pool();
      v13 = v12->i_block_p;
      v14 = (unsigned __int64)v13->i_objects_a;
      if ( (unsigned __int64)v10 < v14
        || (v15 = (unsigned __int64)v10 < v14 + 24i64 * v13->i_size, v16 = &v12->i_pool, !v15) )
      {
        v16 = &v12->i_exp_pool;
      }
      APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v16, v10);
    }
    v17.i_str_ref_p = 0i64;
    SSInstance::coroutine_call(
      (SSInstance *)&v3->mScript->vfptr,
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
  UFG::GameSlice *v2; // rbx
  SSInstance *v3; // rax
  SSInstance *v4; // rcx
  SSInstance *args_pp; // [rsp+50h] [rbp+8h]

  v2 = this;
  if ( this->mScript )
  {
    v3 = UFG::TSTriggerRegion::AsInstance(pTriggerRegion);
    v4 = (SSInstance *)&v2->mScript->vfptr;
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
  UFG::GameSlice *v2; // rbx
  SSInstance *v3; // rax
  SSInstance *v4; // rcx
  SSInstance *args_pp; // [rsp+50h] [rbp+8h]

  v2 = this;
  if ( this->mScript )
  {
    v3 = UFG::TSTriggerRegion::AsInstance(pTriggerRegion);
    v4 = (SSInstance *)&v2->mScript->vfptr;
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
  UFG::GameSlice *v1; // rbx
  SSInstance *v2; // rcx
  SSInstance *args_pp; // [rsp+50h] [rbp+8h]

  v1 = this;
  if ( this->mScript )
  {
    if ( !this->mIgnoreSafehouseRestore )
    {
      UFG::ProgressionTracker::Instance()->mHoldCurtainPostRestore = 1;
      v2 = (SSInstance *)&v1->mScript->vfptr;
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
  UFG::GameSlice *v1; // rax

  v1 = this->mpParent;
  this->mExclusiveChild = this;
  if ( v1 )
    UFG::GameSlice::_MarkExclusiveChild(v1, this);
}

// File Line: 2788
// RVA: 0x4A7210
signed __int64 __fastcall UFG::GameSlice::GetTypeFromCategoryName(UFG::qString *name)
{
  unsigned int v1; // ebx
  unsigned int v2; // eax

  v1 = 12;
  v2 = UFG::qStringHashUpper32(name->mData, 0xFFFFFFFF);
  if ( v2 > 0x8A81A698 )
  {
    switch ( v2 )
    {
      case 0x93B4E7EE:
        v1 = 6;
        break;
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
void __fastcall UFG::GameSlice::BorrowAmbientActor(UFG::GameSlice *this, UFG::SimObject *actor)
{
  UFG::SimObjectCVBase *v2; // rbx
  UFG::GameSlice *v3; // rdi
  unsigned __int16 v4; // dx
  UFG::StreamedResourceComponent *v5; // rax
  unsigned __int16 v6; // cx
  UFG::AiDriverComponent *v7; // rax
  UFG::allocator::free_link *v8; // rax
  UFG::SceneObjectProperties *v9; // rdx
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v12; // rax

  if ( actor )
  {
    v2 = (UFG::SimObjectCVBase *)actor;
    v3 = this;
    v4 = actor->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = (UFG::StreamedResourceComponent *)v2->m_Components.p[10].m_pComponent;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
      {
        v5 = (UFG::StreamedResourceComponent *)v2->m_Components.p[7].m_pComponent;
      }
      else if ( (v4 >> 12) & 1 )
      {
        v5 = (UFG::StreamedResourceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)&v2->vfptr,
                                                 UFG::StreamedResourceComponent::_TypeUID);
      }
      else
      {
        v5 = (UFG::StreamedResourceComponent *)UFG::SimObject::GetComponentOfType(
                                                 (UFG::SimObject *)&v2->vfptr,
                                                 UFG::StreamedResourceComponent::_TypeUID);
      }
    }
    else
    {
      v5 = (UFG::StreamedResourceComponent *)v2->m_Components.p[10].m_pComponent;
    }
    if ( v5 )
      UFG::StreamedResourceComponent::IncrementPriorityReferenceCount(v5, (UFG::qSymbol *)&qSymbol_Critical.mUID);
    v6 = v2->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v7 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v2);
    }
    else if ( (v6 & 0x8000u) == 0 )
    {
      if ( (v6 >> 13) & 1 )
      {
        v7 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                         (UFG::SimObjectGame *)&v2->vfptr,
                                         UFG::AiDriverComponent::_TypeUID);
      }
      else if ( (v6 >> 12) & 1 )
      {
        v7 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                         (UFG::SimObjectGame *)&v2->vfptr,
                                         UFG::AiDriverComponent::_TypeUID);
      }
      else
      {
        v7 = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                         (UFG::SimObject *)&v2->vfptr,
                                         UFG::AiDriverComponent::_TypeUID);
      }
    }
    else
    {
      v7 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v2);
    }
    if ( v7 )
      v7->m_IsAmbient = 0;
    UFG::PedSpawnManager::GetInstance();
    UFG::PedSpawnManager::AquireOwnership((UFG::SimObject *)&v2->vfptr, 0, 1, -1);
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
      v10 = v9->vfptr;
      v11 = v9->m_SafePointerList.mNode.mPrev;
      v10[1].__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int))v11;
      v11->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v10;
      v9->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)v9;
      v9->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v9;
    }
    v9->m_SafePointerList.mNode.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v2;
    v12 = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)v2->m_SafePointerList.mNode.mPrev;
    v12[1].__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int))v9;
    v9->vfptr = v12;
    v9->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_SafePointerList;
    v2->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)v9;
    qSet<UFG::SceneObjectProperties,UFG::qSymbol,qCompareLogical<UFG::qSymbol>>::Append(
      (qSet<UFG::SceneObjectProperties,UFG::qSymbol,qCompareLogical<UFG::qSymbol> > *)&v3->mBorrowedActors,
      v9,
      "qSet::Append");
  }
}

// File Line: 2842
// RVA: 0x4B8110
void __fastcall UFG::GameSlice::ReturnAllAmbientActors(UFG::GameSlice *this)
{
  UFG::GameSlice *v1; // rsi
  unsigned int v2; // ebp
  __int64 v3; // rbx
  UFG::SimObjectCharacter *v4; // rdi
  UFG::SimObjectGame *v5; // rcx
  unsigned __int16 v6; // dx
  UFG::StreamedResourceComponent *v7; // rax

  v1 = this;
  v2 = 0;
  if ( this->mBorrowedActors.mCount )
  {
    v3 = 0i64;
    do
    {
      v4 = (UFG::SimObjectCharacter *)v1->mBorrowedActors.mppArray[v3]->m_pPointer;
      if ( v4 )
      {
        if ( v4 == UFG::GetLocalPlayer() )
          return;
        v5 = (UFG::SimObjectGame *)v1->mBorrowedActors.mppArray[v3]->m_pPointer;
        if ( v5 )
        {
          v6 = v5->m_Flags;
          if ( (v6 >> 14) & 1 )
          {
            v7 = (UFG::StreamedResourceComponent *)v5->m_Components.p[10].m_pComponent;
          }
          else if ( (v6 & 0x8000u) == 0 )
          {
            if ( (v6 >> 13) & 1 )
            {
              v7 = (UFG::StreamedResourceComponent *)v5->m_Components.p[7].m_pComponent;
            }
            else if ( (v6 >> 12) & 1 )
            {
              v7 = (UFG::StreamedResourceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                       v5,
                                                       UFG::StreamedResourceComponent::_TypeUID);
            }
            else
            {
              v7 = (UFG::StreamedResourceComponent *)UFG::SimObject::GetComponentOfType(
                                                       (UFG::SimObject *)&v5->vfptr,
                                                       UFG::StreamedResourceComponent::_TypeUID);
            }
          }
          else
          {
            v7 = (UFG::StreamedResourceComponent *)v5->m_Components.p[10].m_pComponent;
          }
          if ( v7 )
            UFG::StreamedResourceComponent::DecrementPriorityReferenceCount(v7, (UFG::qSymbol *)&qSymbol_Critical.mUID);
        }
        UFG::PedSpawnManager::GetInstance();
        UFG::PedSpawnManager::ReleaseOwnership(v1->mBorrowedActors.mppArray[v3]->m_pPointer, 0xFFFFFFFF, 1);
      }
      ++v2;
      ++v3;
      v1->mBorrowedActors.mppArray[v3 - 1] = 0i64;
    }
    while ( v2 < v1->mBorrowedActors.mCount );
  }
  qSetBase<UFG::qSafePointer<UFG::SimObject,UFG::SimObject>>::FreeAll((qSetBase<UFG::qSafePointer<UFG::SimObject,UFG::SimObject> > *)&v1->mBorrowedActors.mCount);
}

// File Line: 2911
// RVA: 0x493550
void __fastcall UFG::GameSliceMasks::AddMask(UFG::GameSliceMasks *this, UFG::qString *sliceName)
{
  UFG::qString *v2; // rsi
  UFG::GameSliceMasks *v3; // rbp
  char *v4; // rbx
  UFG::qSymbol *v5; // rdi
  UFG::qBaseTreeRB *v6; // rbx
  UFG::allocator::free_link *v7; // rax
  UFG::qBaseTreeRB *v8; // rax
  UFG::qSymbol result; // [rsp+50h] [rbp+8h]
  UFG::allocator::free_link *v10; // [rsp+58h] [rbp+10h]

  v2 = sliceName;
  v3 = this;
  v4 = sliceName->mData;
  if ( !(_S19_1 & 1) )
  {
    _S19_1 |= 1u;
    UFG::ProgressionTracker::ProgressionTracker(&sProgressionTracker);
    atexit(UFG::ProgressionTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sProgressionTracker__);
  }
  UFG::ProgressionTracker::mspInstance = &sProgressionTracker;
  v5 = UFG::qSymbol::create_from_string(&result, v4);
  if ( !v5->mUID || (v6 = UFG::qBaseTreeRB::Get(&stru_14240A190, v5->mUID)) == 0i64 )
  {
    if ( !v5->mUID || (v6 = UFG::qBaseTreeRB::Get(&stru_14240A100, v5->mUID)) == 0i64 )
    {
      if ( v5->mUID )
        v6 = UFG::qBaseTreeRB::Get(&stru_14240A148, v5->mUID);
      else
        v6 = 0i64;
    }
  }
  if ( !v6 )
  {
    if ( !(_S19_1 & 1) )
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
      UFG::GameSlice::GameSlice((UFG::GameSlice *)v7, v2->mData);
      v6 = v8;
    }
    else
    {
      v6 = 0i64;
    }
    UFG::qBaseTreeRB::Add(&stru_14240A190, &v6->mRoot);
    unk_14240B986 = 1;
  }
  qSet<UFG::SceneObjectProperties,UFG::qSymbol,qCompareLogical<UFG::qSymbol>>::Append(
    (qSet<UFG::SceneObjectProperties,UFG::qSymbol,qCompareLogical<UFG::qSymbol> > *)&v3->mMasks,
    (UFG::SceneObjectProperties *)v6,
    "GameSliceMasks::AddMask");
}

// File Line: 2927
// RVA: 0x4ACDC0
char __fastcall UFG::GameSliceMasks::IsSet(UFG::GameSliceMasks *this, UFG::GameSlice *pActiveGameSlice)
{
  UFG::GameSlice::Type v2; // er8
  __int64 v4; // r8
  UFG::GameSlice **v5; // rax
  unsigned __int64 v6; // r8

  v2 = 1;
  if ( pActiveGameSlice )
  {
    if ( pActiveGameSlice->mType != 2 )
      v2 = pActiveGameSlice->mType;
    if ( this->mEnabledCategory[v2] )
      return 1;
    v4 = (signed int)this->mMasks.mCount;
    if ( (_DWORD)v4 )
    {
      v5 = this->mMasks.mppArray;
      v6 = (unsigned __int64)&v5[v4];
      if ( (unsigned __int64)v5 < v6 )
      {
        while ( *v5 != pActiveGameSlice )
        {
          ++v5;
          if ( (unsigned __int64)v5 >= v6 )
            return 0;
        }
        return 1;
      }
    }
    return 0;
  }
  if ( !this->mEnabledCategory[1] )
    return 0;
  return 1;
}

// File Line: 3007
// RVA: 0x4BE910
bool __fastcall UFG::GameSlice::ShouldTeleportOnStart(UFG::GameSlice *this)
{
  UFG::SceneSettings *v1; // rax

  v1 = this->mSceneSettings;
  return v1 && v1->mTeleportMarker.mUID != -1;
}

// File Line: 3012
// RVA: 0x4BE930
bool __fastcall UFG::GameSlice::ShouldTeleportVehicleOnStart(UFG::GameSlice *this)
{
  UFG::SceneSettings *v1; // rax

  v1 = this->mSceneSettings;
  return v1 && v1->mVehicleTeleportMarker.mUID != -1;
}

// File Line: 3017
// RVA: 0x4BE6F0
bool __fastcall UFG::GameSlice::ShouldDestroyVehicleOnStart(UFG::GameSlice *this)
{
  UFG::SceneSettings *v1; // rax

  v1 = this->mSceneSettings;
  return v1 && v1->mVehicleDestroy;
}

