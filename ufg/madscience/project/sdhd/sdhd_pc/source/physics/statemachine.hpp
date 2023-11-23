// File Line: 30
// RVA: 0x44DBE0
void __fastcall UFG::StateMachineEffectNode::StateMachineEffectNode(UFG::StateMachineEffectNode *this)
{
  float z; // xmm2_4
  float w; // xmm3_4
  float x; // xmm0_4
  float y; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm2_4
  float v8; // xmm3_4
  float v9; // xmm0_4
  float v10; // xmm2_4
  float v11; // xmm3_4
  float v12; // xmm0_4

  z = UFG::qMatrix44::msIdentity.v0.z;
  w = UFG::qMatrix44::msIdentity.v0.w;
  x = UFG::qMatrix44::msIdentity.v0.x;
  this->mTransform.v0.y = UFG::qMatrix44::msIdentity.v0.y;
  this->mTransform.v0.z = z;
  this->mTransform.v0.x = x;
  this->mTransform.v0.w = w;
  y = UFG::qMatrix44::msIdentity.v1.y;
  v5 = UFG::qMatrix44::msIdentity.v1.z;
  v6 = UFG::qMatrix44::msIdentity.v1.w;
  this->mTransform.v1.x = UFG::qMatrix44::msIdentity.v1.x;
  this->mTransform.v1.y = y;
  this->mTransform.v1.z = v5;
  this->mTransform.v1.w = v6;
  v7 = UFG::qMatrix44::msIdentity.v2.z;
  v8 = UFG::qMatrix44::msIdentity.v2.w;
  v9 = UFG::qMatrix44::msIdentity.v2.x;
  this->mTransform.v2.y = UFG::qMatrix44::msIdentity.v2.y;
  this->mTransform.v2.x = v9;
  this->mTransform.v2.z = v7;
  this->mTransform.v2.w = v8;
  v10 = UFG::qMatrix44::msIdentity.v3.z;
  v11 = UFG::qMatrix44::msIdentity.v3.w;
  v12 = UFG::qMatrix44::msIdentity.v3.x;
  this->mTransform.v3.y = UFG::qMatrix44::msIdentity.v3.y;
  this->mTransform.v3.z = v10;
  this->mTransform.v3.x = v12;
  this->mTransform.v3.w = v11;
  this->mStartTime = -1.0;
  *(_QWORD *)&this->mEndTime = -1082130432i64;
  this->mAttachToObject = 0;
}

// File Line: 342
// RVA: 0x44DD70
void __fastcall UFG::StateMachineNode::StateMachineNode(UFG::StateMachineNode *this, MemImageLoadFlag f)
{
  unsigned int v3; // esi
  unsigned int i; // ebp
  UFG::StateMachineEffectNode *v5; // rdi
  float v6; // xmm0_4
  char *v7; // rax
  UFG::qVector4 v8; // xmm1
  UFG::qVector4 v9; // xmm2
  UFG::qVector4 v10; // xmm3
  unsigned int j; // ebp
  UFG::StateMachineNode::SpawnNode *v12; // rdi
  float v13; // xmm0_4
  char *v14; // rax
  UFG::qVector4 v15; // xmm1
  UFG::qVector4 v16; // xmm2
  UFG::qVector4 v17; // xmm3
  unsigned int k; // r8d
  unsigned int m; // ecx
  unsigned int n; // r10d
  UFG::StateMachineNode::FractureController *v21; // r9
  unsigned int ii; // r8d

  this->mName.mText.mData.mFlags = 2;
  this->mEffectNodes.mData.mFlags = 2;
  this->mSpawnNodes.mData.mFlags = 2;
  this->mRiggedGeoNodes.mData.mFlags = 2;
  this->mConstraintNodes.mData.mFlags = 2;
  this->mFractureControllers.mData.mFlags = 2;
  this->mExitConditions.mData.mFlags = 2;
  this->mActionPath.mText.mData.mFlags = 2;
  this->mDebugPrintString.mText.mData.mFlags = 2;
  this->mSoundEffectUid.mText.mData.mFlags = 2;
  v3 = 0;
  for ( i = 0; i < this->mEffectNodes.mData.mNumItems; ++i )
  {
    v5 = &this->mEffectNodes.mData.mItems[i];
    if ( v5 )
    {
      v6 = (float)((float)((float)(v5->mTransform.v1.w + v5->mTransform.v0.w) + v5->mTransform.v2.w) * 0.0)
         + v5->mTransform.v3.w;
      if ( v6 < 0.0 )
        LODWORD(v6) ^= _xmm[0];
      if ( v6 < 0.001 )
      {
        v7 = UFG::qSymbol::as_cstr_dbg(&v5->mNameUid);
        UFG::qPrintf("Warning: StateMachineEffectNode %s has invalid transform. Setting to identity\n", v7);
        v8 = UFG::qMatrix44::msIdentity.v1;
        v9 = UFG::qMatrix44::msIdentity.v2;
        v10 = UFG::qMatrix44::msIdentity.v3;
        v5->mTransform.v0 = UFG::qMatrix44::msIdentity.v0;
        v5->mTransform.v1 = v8;
        v5->mTransform.v2 = v9;
        v5->mTransform.v3 = v10;
      }
    }
  }
  for ( j = 0; j < this->mSpawnNodes.mData.mNumItems; ++j )
  {
    v12 = &this->mSpawnNodes.mData.mItems[j];
    if ( v12 )
    {
      v13 = (float)((float)((float)(v12->mTransform.v1.w + v12->mTransform.v0.w) + v12->mTransform.v2.w) * 0.0)
          + v12->mTransform.v3.w;
      if ( v13 < 0.0 )
        LODWORD(v13) ^= _xmm[0];
      if ( v13 < 0.001 )
      {
        v14 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v12->mSpawnPropertySet);
        UFG::qPrintf("Warning: SpawnNode %s has invalid transform. Setting to identity\n", v14);
        v15 = UFG::qMatrix44::msIdentity.v1;
        v16 = UFG::qMatrix44::msIdentity.v2;
        v17 = UFG::qMatrix44::msIdentity.v3;
        v12->mTransform.v0 = UFG::qMatrix44::msIdentity.v0;
        v12->mTransform.v1 = v15;
        v12->mTransform.v2 = v16;
        v12->mTransform.v3 = v17;
      }
    }
  }
  for ( k = 0; k < this->mRiggedGeoNodes.mData.mNumItems; ++k )
    ;
  for ( m = 0; m < this->mConstraintNodes.mData.mNumItems; ++m )
    ;
  for ( n = 0; n < this->mFractureControllers.mData.mNumItems; ++n )
  {
    v21 = &this->mFractureControllers.mData.mItems[n];
    if ( v21 )
    {
      v21->mFractureElements.mData.mFlags = 2;
      for ( ii = 0; ii < v21->mFractureElements.mData.mNumItems; ++ii )
        ;
    }
  }
  if ( this->mExitConditions.mData.mNumItems )
  {
    do
      ++v3;
    while ( v3 < this->mExitConditions.mData.mNumItems );
  }
}

// File Line: 370
// RVA: 0x2E5220
void __fastcall UFG::StateMachineNode::~StateMachineNode(UFG::StateMachineNode *this)
{
  UFG::qReflectString *p_mSoundEffectUid; // rbx
  UFG::qReflectString *p_mDebugPrintString; // rbx
  UFG::qReflectString *p_mActionPath; // rbx
  UFG::StateMachineNode::ExitCondition *mItems; // rcx
  UFG::qSymbol *p_mGotoNode; // rbx
  UFG::StateMachineNode::FractureController *v7; // rcx
  unsigned int *p_mNumItems; // rbx
  UFG::StateMachineNode::ConstraintNode *v9; // rcx
  UFG::StateMachineNode::ConstraintNode::ConstraintType *p_mType; // rbx
  UFG::StateMachineNode::RiggedGeoNode *v11; // rcx
  char *p_mEnabled; // rbx
  UFG::StateMachineNode::SpawnNode *v13; // rcx
  char *p_mSpawnPropertySet; // rbx
  UFG::StateMachineEffectNode *v15; // rcx
  char *p_mAttachToObject; // rbx

  p_mSoundEffectUid = &this->mSoundEffectUid;
  if ( (this->mSoundEffectUid.mText.mData.mFlags & 2) == 0 )
    operator delete[](p_mSoundEffectUid->mText.mData.mItems);
  p_mSoundEffectUid->mText.mData.mItems = 0i64;
  *(_QWORD *)&p_mSoundEffectUid->mText.mData.mNumItems = 0i64;
  p_mDebugPrintString = &this->mDebugPrintString;
  if ( (this->mDebugPrintString.mText.mData.mFlags & 2) == 0 )
    operator delete[](p_mDebugPrintString->mText.mData.mItems);
  p_mDebugPrintString->mText.mData.mItems = 0i64;
  *(_QWORD *)&this->mDebugPrintString.mText.mData.mNumItems = 0i64;
  p_mActionPath = &this->mActionPath;
  if ( (this->mActionPath.mText.mData.mFlags & 2) == 0 )
    operator delete[](p_mActionPath->mText.mData.mItems);
  p_mActionPath->mText.mData.mItems = 0i64;
  *(_QWORD *)&this->mActionPath.mText.mData.mNumItems = 0i64;
  if ( (this->mExitConditions.mData.mFlags & 2) == 0 )
  {
    mItems = this->mExitConditions.mData.mItems;
    if ( mItems )
    {
      p_mGotoNode = &mItems[-1].mGotoNode;
      `eh vector destructor iterator(mItems, 0x10ui64, mItems[-1].mGotoNode.mUID, (void (__fastcall *)(void *))_);
      operator delete[](p_mGotoNode);
    }
  }
  this->mExitConditions.mData.mItems = 0i64;
  *(_QWORD *)&this->mExitConditions.mData.mNumItems = 0i64;
  if ( (this->mFractureControllers.mData.mFlags & 2) == 0 )
  {
    v7 = this->mFractureControllers.mData.mItems;
    if ( v7 )
    {
      p_mNumItems = &v7[-1].mFractureElements.mData.mNumItems;
      `eh vector destructor iterator(
        v7,
        0x18ui64,
        v7[-1].mFractureElements.mData.mNumItems,
        (void (__fastcall *)(void *))UFG::StateMachineNode::FractureController::~FractureController);
      operator delete[](p_mNumItems);
    }
  }
  this->mFractureControllers.mData.mItems = 0i64;
  *(_QWORD *)&this->mFractureControllers.mData.mNumItems = 0i64;
  if ( (this->mConstraintNodes.mData.mFlags & 2) == 0 )
  {
    v9 = this->mConstraintNodes.mData.mItems;
    if ( v9 )
    {
      p_mType = &v9[-1].mType;
      `eh vector destructor iterator(v9, 0x40ui64, v9[-1].mType, (void (__fastcall *)(void *))_);
      operator delete[](p_mType);
    }
  }
  this->mConstraintNodes.mData.mItems = 0i64;
  *(_QWORD *)&this->mConstraintNodes.mData.mNumItems = 0i64;
  if ( (this->mRiggedGeoNodes.mData.mFlags & 2) == 0 )
  {
    v11 = this->mRiggedGeoNodes.mData.mItems;
    if ( v11 )
    {
      p_mEnabled = (char *)&v11[-1].mEnabled;
      `eh vector destructor iterator(v11, 8ui64, *(_DWORD *)&v11[-1].mEnabled, (void (__fastcall *)(void *))_);
      UFG::qMemoryPool::Free(&gPhysicsMemoryPool, p_mEnabled);
    }
  }
  this->mRiggedGeoNodes.mData.mItems = 0i64;
  *(_QWORD *)&this->mRiggedGeoNodes.mData.mNumItems = 0i64;
  if ( (this->mSpawnNodes.mData.mFlags & 2) == 0 )
  {
    v13 = this->mSpawnNodes.mData.mItems;
    if ( v13 )
    {
      p_mSpawnPropertySet = (char *)&v13[-1].mSpawnPropertySet;
      `eh vector destructor iterator(v13, 0x5Cui64, v13[-1].mSpawnPropertySet.mUID, (void (__fastcall *)(void *))_);
      UFG::qMemoryPool::Free(&gPhysicsMemoryPool, p_mSpawnPropertySet);
    }
  }
  this->mSpawnNodes.mData.mItems = 0i64;
  *(_QWORD *)&this->mSpawnNodes.mData.mNumItems = 0i64;
  if ( (this->mEffectNodes.mData.mFlags & 2) == 0 )
  {
    v15 = this->mEffectNodes.mData.mItems;
    if ( v15 )
    {
      p_mAttachToObject = (char *)&v15[-1].mAttachToObject;
      `eh vector destructor iterator(
        v15,
        0x50ui64,
        *(_DWORD *)&v15[-1].mAttachToObject,
        (void (__fastcall *)(void *))_);
      UFG::qMemoryPool::Free(&gPhysicsMemoryPool, p_mAttachToObject);
    }
  }
  this->mEffectNodes.mData.mItems = 0i64;
  *(_QWORD *)&this->mEffectNodes.mData.mNumItems = 0i64;
  if ( (this->mName.mText.mData.mFlags & 2) == 0 )
    operator delete[](this->mName.mText.mData.mItems);
  this->mName.mText.mData.mItems = 0i64;
  *(_QWORD *)&this->mName.mText.mData.mNumItems = 0i64;
}

// File Line: 574
// RVA: 0x44DA40
void __fastcall UFG::StateMachineDefinition::StateMachineDefinition(
        UFG::StateMachineDefinition *this,
        MemImageLoadFlag f)
{
  unsigned __int64 mUID; // rax
  unsigned int i; // edi
  __int64 v5; // rcx
  bool v6; // zf
  UFG::StateMachineNode *v7; // rcx
  char *Name; // rax
  UFG::qString *v9; // rax
  unsigned int v10; // r9d
  unsigned int mNumItems; // r11d
  UFG::StateMachineNode *mItems; // r10
  UFG::StateMachineNode *v13; // r8
  unsigned int j; // eax
  int mConditional; // edx
  UFG::qString result; // [rsp+28h] [rbp-70h] BYREF
  UFG::qString v17; // [rsp+50h] [rbp-48h] BYREF
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *p_mHandles; // [rsp+B0h] [rbp+18h] BYREF
  UFG::StateMachineNode *v20; // [rsp+B8h] [rbp+20h]

  mUID = this->mBaseNode.mUID;
  this->mBaseNode.mUID = 0i64;
  this->mBaseNode.mParent = &this->mBaseNode;
  this->mBaseNode.mChildren[0] = &this->mBaseNode;
  this->mBaseNode.mChildren[1] = &this->mBaseNode;
  this->mBaseNode.mNeighbours[0] = &this->mBaseNode;
  this->mBaseNode.mNeighbours[1] = &this->mBaseNode;
  this->mBaseNode.mUID = mUID;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable;
  p_mHandles = &this->mHandles;
  this->mHandles.mNode.mPrev = &this->mHandles.mNode;
  this->mHandles.mNode.mNext = &this->mHandles.mNode;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::StateMachineDefinition,UFG::qReflectObject>::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::StateMachineDefinition::`vftable;
  this->mStateNodes.mData.mFlags = 2;
  for ( i = 0; i < this->mStateNodes.mData.mNumItems; ++i )
  {
    v5 = i;
    v6 = &this->mStateNodes.mData.mItems[v5] == 0;
    v7 = &this->mStateNodes.mData.mItems[v5];
    p_mHandles = (UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *)v7;
    v20 = v7;
    if ( !v6 )
      UFG::StateMachineNode::StateMachineNode(v7, f);
  }
  Name = UFG::qReflectObject::GetName(this);
  UFG::qString::qString(&v17, Name);
  UFG::qString::Trim(v9, &result);
  UFG::qString::~qString(&v17);
  UFG::qString::ReplaceCharInPlace(&result, 32, 95);
  this->name = (UFG::qSymbolUC)UFG::qSymbolUC::create_from_string((UFG::qSymbolUC *)&p_mHandles, result.mData)->mUID;
  v10 = 0;
  mNumItems = this->mStateNodes.mData.mNumItems;
  if ( mNumItems )
  {
    mItems = this->mStateNodes.mData.mItems;
    do
    {
      v13 = &mItems[v10];
      if ( v13->mExecuteUponSpawn )
        this->mHasOnSpawnNode = 1;
      for ( j = 0; j < v13->mExitConditions.mData.mNumItems; ++j )
      {
        mConditional = v13->mExitConditions.mData.mItems[j].mConditional;
        if ( mConditional >= 2 )
        {
          if ( mConditional <= 5 )
          {
            this->mHasCollisionEventHandler = 1;
          }
          else if ( mConditional == 8 )
          {
            this->mHasNamedEventHandler = 1;
          }
        }
      }
      ++v10;
    }
    while ( v10 < mNumItems );
  }
  UFG::qString::~qString(&result);
}

