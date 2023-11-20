// File Line: 30
// RVA: 0x44DBE0
void __fastcall UFG::StateMachineEffectNode::StateMachineEffectNode(UFG::StateMachineEffectNode *this)
{
  float v1; // xmm2_4
  float v2; // xmm3_4
  float v3; // xmm0_4
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm2_4
  float v8; // xmm3_4
  float v9; // xmm0_4
  float v10; // xmm2_4
  float v11; // xmm3_4
  float v12; // xmm0_4

  v1 = UFG::qMatrix44::msIdentity.v0.z;
  v2 = UFG::qMatrix44::msIdentity.v0.w;
  v3 = UFG::qMatrix44::msIdentity.v0.x;
  this->mTransform.v0.y = UFG::qMatrix44::msIdentity.v0.y;
  this->mTransform.v0.z = v1;
  this->mTransform.v0.x = v3;
  this->mTransform.v0.w = v2;
  v4 = UFG::qMatrix44::msIdentity.v1.y;
  v5 = UFG::qMatrix44::msIdentity.v1.z;
  v6 = UFG::qMatrix44::msIdentity.v1.w;
  this->mTransform.v1.x = UFG::qMatrix44::msIdentity.v1.x;
  this->mTransform.v1.y = v4;
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
  UFG::StateMachineNode *v2; // rbx
  unsigned int v3; // esi
  unsigned int v4; // ebp
  signed __int64 v5; // rdi
  float v6; // xmm0_4
  char *v7; // rax
  UFG::qVector4 v8; // xmm1
  UFG::qVector4 v9; // xmm2
  UFG::qVector4 v10; // xmm3
  unsigned int i; // ebp
  signed __int64 v12; // rdi
  float v13; // xmm0_4
  char *v14; // rax
  UFG::qVector4 v15; // xmm1
  UFG::qVector4 v16; // xmm2
  UFG::qVector4 v17; // xmm3
  unsigned int j; // er8
  UFG::StateMachineNode::RiggedGeoNode *v19; // rax
  unsigned int k; // ecx
  unsigned int l; // er10
  signed __int64 v22; // r9
  unsigned int m; // er8
  __int64 v24; // rax
  unsigned __int64 v25; // [rsp+A8h] [rbp+20h]
  signed __int64 v26; // [rsp+A8h] [rbp+20h]

  v2 = this;
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
  v4 = 0;
  if ( this->mEffectNodes.mData.mNumItems )
  {
    do
    {
      v5 = (signed __int64)&v2->mEffectNodes.mData.mItems[v4];
      if ( v5 )
      {
        v6 = (float)((float)((float)(*(float *)(v5 + 28) + *(float *)(v5 + 12)) + *(float *)(v5 + 44)) * 0.0)
           + *(float *)(v5 + 60);
        if ( v6 < 0.0 )
          LODWORD(v6) ^= _xmm[0];
        if ( v6 < 0.001 )
        {
          v7 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)(v5 + 72));
          UFG::qPrintf("Warning: StateMachineEffectNode %s has invalid transform. Setting to identity\n", v7);
          v8 = UFG::qMatrix44::msIdentity.v1;
          v9 = UFG::qMatrix44::msIdentity.v2;
          v10 = UFG::qMatrix44::msIdentity.v3;
          *(UFG::qVector4 *)v5 = UFG::qMatrix44::msIdentity.v0;
          *(UFG::qVector4 *)(v5 + 16) = v8;
          *(UFG::qVector4 *)(v5 + 32) = v9;
          *(UFG::qVector4 *)(v5 + 48) = v10;
        }
      }
      ++v4;
    }
    while ( v4 < v2->mEffectNodes.mData.mNumItems );
  }
  for ( i = 0; i < v2->mSpawnNodes.mData.mNumItems; ++i )
  {
    v12 = (signed __int64)&v2->mSpawnNodes.mData.mItems[i];
    if ( v12 )
    {
      v13 = (float)((float)((float)(*(float *)(v12 + 28) + *(float *)(v12 + 12)) + *(float *)(v12 + 44)) * 0.0)
          + *(float *)(v12 + 60);
      if ( v13 < 0.0 )
        LODWORD(v13) ^= _xmm[0];
      if ( v13 < 0.001 )
      {
        v14 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)(v12 + 88));
        UFG::qPrintf("Warning: SpawnNode %s has invalid transform. Setting to identity\n", v14);
        v15 = UFG::qMatrix44::msIdentity.v1;
        v16 = UFG::qMatrix44::msIdentity.v2;
        v17 = UFG::qMatrix44::msIdentity.v3;
        *(UFG::qVector4 *)v12 = UFG::qMatrix44::msIdentity.v0;
        *(UFG::qVector4 *)(v12 + 16) = v15;
        *(UFG::qVector4 *)(v12 + 32) = v16;
        *(UFG::qVector4 *)(v12 + 48) = v17;
      }
    }
  }
  for ( j = 0; j < v2->mRiggedGeoNodes.mData.mNumItems; ++j )
    v19 = v2->mRiggedGeoNodes.mData.mItems;
  for ( k = 0; k < v2->mConstraintNodes.mData.mNumItems; ++k )
    v25 = (unsigned __int64)&v2->mConstraintNodes.mData.mItems[(unsigned __int64)k];
  for ( l = 0; l < v2->mFractureControllers.mData.mNumItems; ++l )
  {
    v22 = (signed __int64)&v2->mFractureControllers.mData.mItems[l];
    if ( v22 )
    {
      *(_DWORD *)(v22 + 20) = 2;
      for ( m = 0; m < *(_DWORD *)(v22 + 16); ++m )
        v24 = *(_QWORD *)(v22 + 8);
    }
  }
  if ( v2->mExitConditions.mData.mNumItems )
  {
    do
      v26 = (signed __int64)&v2->mExitConditions.mData.mItems[v3++];
    while ( v3 < v2->mExitConditions.mData.mNumItems );
  }
}

// File Line: 370
// RVA: 0x2E5220
void __fastcall UFG::StateMachineNode::~StateMachineNode(UFG::StateMachineNode *this)
{
  UFG::StateMachineNode *v1; // rdi
  UFG::qReflectString *v2; // rbx
  void **v3; // rbx
  void **v4; // rbx
  UFG::StateMachineNode::ExitCondition *v5; // rcx
  UFG::qSymbol *v6; // rbx
  UFG::StateMachineNode::FractureController *v7; // rcx
  unsigned int *v8; // rbx
  UFG::StateMachineNode::ConstraintNode *v9; // rcx
  UFG::StateMachineNode::ConstraintNode::ConstraintType *v10; // rbx
  UFG::StateMachineNode::RiggedGeoNode *v11; // rcx
  bool *v12; // rbx
  UFG::StateMachineNode::SpawnNode *v13; // rcx
  UFG::qSymbol *v14; // rbx
  UFG::StateMachineEffectNode *v15; // rcx
  bool *v16; // rbx

  v1 = this;
  v2 = &this->mSoundEffectUid;
  if ( !(this->mSoundEffectUid.mText.mData.mFlags & 2) )
    operator delete[](v2->mText.mData.mItems);
  v2->mText.mData.mItems = 0i64;
  *(_QWORD *)&v2->mText.mData.mNumItems = 0i64;
  v3 = (void **)&v1->mDebugPrintString.mText.mData.mItems;
  if ( !(v1->mDebugPrintString.mText.mData.mFlags & 2) )
    operator delete[](*v3);
  *v3 = 0i64;
  *(_QWORD *)&v1->mDebugPrintString.mText.mData.mNumItems = 0i64;
  v4 = (void **)&v1->mActionPath.mText.mData.mItems;
  if ( !(v1->mActionPath.mText.mData.mFlags & 2) )
    operator delete[](*v4);
  *v4 = 0i64;
  *(_QWORD *)&v1->mActionPath.mText.mData.mNumItems = 0i64;
  if ( !(v1->mExitConditions.mData.mFlags & 2) )
  {
    v5 = v1->mExitConditions.mData.mItems;
    if ( v5 )
    {
      v6 = &v5[-1].mGotoNode;
      `eh vector destructor iterator'(v5, 0x10ui64, v5[-1].mGotoNode.mUID, (void (__fastcall *)(void *))_);
      operator delete[](v6);
    }
  }
  v1->mExitConditions.mData.mItems = 0i64;
  *(_QWORD *)&v1->mExitConditions.mData.mNumItems = 0i64;
  if ( !(v1->mFractureControllers.mData.mFlags & 2) )
  {
    v7 = v1->mFractureControllers.mData.mItems;
    if ( v7 )
    {
      v8 = &v7[-1].mFractureElements.mData.mNumItems;
      `eh vector destructor iterator'(
        v7,
        0x18ui64,
        v7[-1].mFractureElements.mData.mNumItems,
        (void (__fastcall *)(void *))UFG::StateMachineNode::FractureController::~FractureController);
      operator delete[](v8);
    }
  }
  v1->mFractureControllers.mData.mItems = 0i64;
  *(_QWORD *)&v1->mFractureControllers.mData.mNumItems = 0i64;
  if ( !(v1->mConstraintNodes.mData.mFlags & 2) )
  {
    v9 = v1->mConstraintNodes.mData.mItems;
    if ( v9 )
    {
      v10 = &v9[-1].mType;
      `eh vector destructor iterator'(v9, 0x40ui64, v9[-1].mType, (void (__fastcall *)(void *))_);
      operator delete[](v10);
    }
  }
  v1->mConstraintNodes.mData.mItems = 0i64;
  *(_QWORD *)&v1->mConstraintNodes.mData.mNumItems = 0i64;
  if ( !(v1->mRiggedGeoNodes.mData.mFlags & 2) )
  {
    v11 = v1->mRiggedGeoNodes.mData.mItems;
    if ( v11 )
    {
      v12 = &v11[-1].mEnabled;
      `eh vector destructor iterator'(v11, 8ui64, *(_DWORD *)&v11[-1].mEnabled, (void (__fastcall *)(void *))_);
      UFG::qMemoryPool::Free(&gPhysicsMemoryPool, v12);
    }
  }
  v1->mRiggedGeoNodes.mData.mItems = 0i64;
  *(_QWORD *)&v1->mRiggedGeoNodes.mData.mNumItems = 0i64;
  if ( !(v1->mSpawnNodes.mData.mFlags & 2) )
  {
    v13 = v1->mSpawnNodes.mData.mItems;
    if ( v13 )
    {
      v14 = &v13[-1].mSpawnPropertySet;
      `eh vector destructor iterator'(v13, 0x5Cui64, v13[-1].mSpawnPropertySet.mUID, (void (__fastcall *)(void *))_);
      UFG::qMemoryPool::Free(&gPhysicsMemoryPool, v14);
    }
  }
  v1->mSpawnNodes.mData.mItems = 0i64;
  *(_QWORD *)&v1->mSpawnNodes.mData.mNumItems = 0i64;
  if ( !(v1->mEffectNodes.mData.mFlags & 2) )
  {
    v15 = v1->mEffectNodes.mData.mItems;
    if ( v15 )
    {
      v16 = &v15[-1].mAttachToObject;
      `eh vector destructor iterator'(
        v15,
        0x50ui64,
        *(_DWORD *)&v15[-1].mAttachToObject,
        (void (__fastcall *)(void *))_);
      UFG::qMemoryPool::Free(&gPhysicsMemoryPool, v16);
    }
  }
  v1->mEffectNodes.mData.mItems = 0i64;
  *(_QWORD *)&v1->mEffectNodes.mData.mNumItems = 0i64;
  if ( !(v1->mName.mText.mData.mFlags & 2) )
    operator delete[](v1->mName.mText.mData.mItems);
  v1->mName.mText.mData.mItems = 0i64;
  *(_QWORD *)&v1->mName.mText.mData.mNumItems = 0i64;
}

// File Line: 574
// RVA: 0x44DA40
void __fastcall UFG::StateMachineDefinition::StateMachineDefinition(UFG::StateMachineDefinition *this, MemImageLoadFlag f)
{
  UFG::StateMachineDefinition *v2; // rbx
  UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *v3; // rdx
  unsigned __int64 v4; // rax
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *v5; // rax
  unsigned int v6; // edi
  signed __int64 v7; // rcx
  bool v8; // zf
  UFG::StateMachineNode *v9; // rcx
  char *v10; // rax
  UFG::qString *v11; // rax
  unsigned int v12; // er9
  unsigned int v13; // er11
  UFG::StateMachineNode *v14; // r10
  signed __int64 v15; // r8
  unsigned int v16; // eax
  signed int v17; // edx
  UFG::qString result; // [rsp+28h] [rbp-70h]
  UFG::qString v19; // [rsp+50h] [rbp-48h]
  unsigned int fa; // [rsp+A8h] [rbp+10h]
  UFG::StateMachineNode *v21; // [rsp+B0h] [rbp+18h]
  UFG::StateMachineNode *v22; // [rsp+B8h] [rbp+20h]

  fa = f.flag;
  v2 = this;
  v3 = (UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *)&this->mBaseNode;
  v4 = this->mBaseNode.mUID;
  v3->mBaseNode.mUID = 0i64;
  v3->mBaseNode.mParent = &v3->mBaseNode;
  v3->mBaseNode.mChildren[0] = &v3->mBaseNode;
  v3->mBaseNode.mChildren[1] = &v3->mBaseNode;
  v3->mBaseNode.mNeighbours[0] = &v3->mBaseNode;
  v3->mBaseNode.mNeighbours[1] = &v3->mBaseNode;
  v3->mBaseNode.mUID = v4;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable';
  v5 = &this->mHandles;
  v21 = (UFG::StateMachineNode *)v5;
  v5->mNode.mPrev = &v5->mNode;
  v5->mNode.mNext = &v5->mNode;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::StateMachineDefinition,UFG::qReflectObject>::`vftable';
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::StateMachineDefinition::`vftable';
  this->mStateNodes.mData.mFlags = 2;
  v6 = 0;
  if ( this->mStateNodes.mData.mNumItems )
  {
    do
    {
      v7 = v6;
      v8 = &v2->mStateNodes.mData.mItems[v7] == 0;
      v9 = &v2->mStateNodes.mData.mItems[v7];
      v21 = v9;
      v22 = v9;
      if ( !v8 )
        UFG::StateMachineNode::StateMachineNode(v9, (MemImageLoadFlag)fa);
      ++v6;
    }
    while ( v6 < v2->mStateNodes.mData.mNumItems );
  }
  v10 = UFG::qReflectObject::GetName((UFG::qReflectObject *)&v2->vfptr);
  UFG::qString::qString(&v19, v10);
  UFG::qString::Trim(v11, &result);
  UFG::qString::~qString(&v19);
  UFG::qString::ReplaceCharInPlace(&result, 32, 95);
  v2->name = (UFG::qSymbolUC)UFG::qSymbolUC::create_from_string((UFG::qSymbolUC *)&v21, result.mData)->mUID;
  v12 = 0;
  v13 = v2->mStateNodes.mData.mNumItems;
  if ( v13 )
  {
    v14 = v2->mStateNodes.mData.mItems;
    do
    {
      v15 = (signed __int64)&v14[v12];
      if ( *(_BYTE *)(v15 + 388) )
        v2->mHasOnSpawnNode = 1;
      v16 = 0;
      if ( *(_DWORD *)(v15 + 104) )
      {
        do
        {
          v17 = *(_DWORD *)(*(_QWORD *)(v15 + 96) + 16i64 * v16);
          if ( v17 >= 2 )
          {
            if ( v17 <= 5 )
            {
              v2->mHasCollisionEventHandler = 1;
            }
            else if ( v17 == 8 )
            {
              v2->mHasNamedEventHandler = 1;
            }
          }
          ++v16;
        }
        while ( v16 < *(_DWORD *)(v15 + 104) );
      }
      ++v12;
    }
    while ( v12 < v13 );
  }
  UFG::qString::~qString(&result);
}

