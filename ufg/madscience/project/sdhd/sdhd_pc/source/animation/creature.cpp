// File Line: 133
// RVA: 0x39DDF0
void __fastcall Creature::Creature(Creature *this, UFG::RigResource *rig)
{
  UFG::RigResource *v2; // rbx
  Creature *v3; // rdi
  UFG::qList<PoseDriver,PoseDriver,1,0> *v4; // [rsp+60h] [rbp+18h]
  UFG::qList<Attachment,Attachment,1,0> *v5; // [rsp+60h] [rbp+18h]
  UFG::qList<PoseNode,PoseNode,1,0> *v6; // [rsp+68h] [rbp+20h]

  v2 = rig;
  v3 = this;
  UFG::qSafePointerNode<Creature>::qSafePointerNode<Creature>((UFG::qSafePointerNode<Creature> *)&this->vfptr);
  v3->vfptr = (UFG::qSafePointerNode<Creature>Vtbl *)&Creature::`vftable';
  v4 = &v3->mPoseDrivers;
  v4->mNode.mPrev = &v4->mNode;
  v4->mNode.mNext = &v4->mNode;
  v3->mNetworkLock = 0;
  v3->mPoseState = 3;
  v5 = &v3->mAttachments;
  v5->mNode.mPrev = &v5->mNode;
  v5->mNode.mNext = &v5->mNode;
  v3->mForceTransparencyTarget = -1;
  v3->mPoseFrame = 0;
  v3->mPoseTask = 0i64;
  v3->mCurrentStackDepth = 0;
  v3->mCorrected = 0;
  SkeletalPose::SkeletalPose(&v3->mPose, v2);
  PoseNode::PoseNode((PoseNode *)&v3->mBlendTree.vfptr);
  v3->mBlendTree.vfptr = (Expression::IMemberMapVtbl *)&PoseNodeParent::`vftable'{for `Expression::IMemberMap'};
  v3->mBlendTree.vfptr = (UFG::qSafePointerNode<PoseNode>Vtbl *)&PoseNodeParent::`vftable'{for `UFG::qSafePointerNode<PoseNode>'};
  v3->mBlendTree.mChildrenSerialized.mCount = 0;
  v3->mBlendTree.mChildrenSerialized.mData.mOffset = 0i64;
  v6 = &v3->mBlendTree.mChildren;
  v6->mNode.mPrev = &v6->mNode;
  v6->mNode.mNext = &v6->mNode;
  v3->mBlendTree.mLocalTime = 0.0;
  *(_WORD *)&v3->mHaventUpdated = 1;
  v3->mRestPosePrev = 0;
  v3->mPoseTaskParams.mRecipe.mBoneUpdateCount = -1;
  *(_QWORD *)&v3->mPoseTaskParams.mRecipe.mStackCount = 0i64;
  *(_QWORD *)&v3->mPoseTaskParams.mRecipe.mAnimMemoryHighWaterMark = 0i64;
  v3->mPoseTaskParams.mRecipe.mPoseStack = 0i64;
  v3->mPoseTaskParams.mRecipe.mAnimData = 0i64;
  v3->mIsSlopeLocomotionFixupEnabled = 0;
  v3->mMaxSlopeLocomotionFixupAngle = 0.70700002;
  v3->mPlaybackSpeedEnabled = 0;
  v3->mPlaybackSpeed = 1.0;
  v3->mRagdollBlendWeight = 1.0;
  v3->mNetPoseSequence = 0;
  Creature::CommonInit(v3);
}

// File Line: 137
// RVA: 0x14BD240
__int64 dynamic_initializer_for__gsymBlendTreeRoot__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("BlendTreeRoot", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&gsymBlendTreeRoot, v0);
  return atexit(dynamic_atexit_destructor_for__gsymBlendTreeRoot__);
}

// File Line: 140
// RVA: 0x3A5300
void __fastcall Creature::CommonInit(Creature *this)
{
  Creature *v1; // rbx
  __m128 v2; // xmm2
  UFG::qVector4 v3; // xmm1
  UFG::qVector4 v4; // xmm2
  UFG::qVector4 v5; // xmm3

  v1 = this;
  this->mGroundNormal.z = 1.0;
  *(_QWORD *)&this->mGroundNormal.x = 0i64;
  SkeletalPose::SetToRestPose(&this->mPose);
  v1->mPoseCRC = -1;
  v2 = 0i64;
  v1->mBlendTree.mName.mUID = gsymBlendTreeRoot.mUID;
  v1->mIsAttached = 0;
  v2.m128_f32[0] = (float)1;
  v1->mAbsoluteMon.v0 = (UFG::qVector4)v2;
  v1->mAbsoluteMon.v1 = (UFG::qVector4)_mm_shuffle_ps(v2, v2, 81);
  v1->mAbsoluteMon.v2 = (UFG::qVector4)_mm_shuffle_ps(v2, v2, 69);
  v1->mAbsoluteMon.v3 = (UFG::qVector4)_mm_shuffle_ps(v2, v2, 21);
  v1->mAbsoluteMonSet = 0;
  v1->mLastSetPosition.m_translation = 0i64;
  v1->mLastSetPosition.m_rotation = (hkQuaternionf)qi.m_vec.m_quad;
  v1->mLastSetPosition.m_scale = (hkVector4f)query.m_quad;
  UFG::qMemSet(v1->mIsEndEffectorCache, 0, 4u);
  v1->mAbsoluteRelativeRootMotion = 0;
  v3 = UFG::qMatrix44::msIdentity.v1;
  v4 = UFG::qMatrix44::msIdentity.v2;
  v5 = UFG::qMatrix44::msIdentity.v3;
  v1->mAbsoluteRelativeRoot.v0 = UFG::qMatrix44::msIdentity.v0;
  v1->mAbsoluteRelativeRoot.v1 = v3;
  v1->mAbsoluteRelativeRoot.v2 = v4;
  v1->mAbsoluteRelativeRoot.v3 = v5;
  v1->mDisablePosedrivers = 0;
}

// File Line: 177
// RVA: 0x39F840
void __fastcall Creature::~Creature(Creature *this)
{
  Creature *v1; // rsi
  UFG::qList<PoseDriver,PoseDriver,1,0> *v2; // rdi
  signed __int64 i; // rax
  _QWORD *v4; // rdx
  __int64 v5; // rcx
  _QWORD *v6; // rax
  UFG::qNode<Attachment,Attachment> *v7; // rcx
  UFG::qNode<Attachment,Attachment> *v8; // rax
  UFG::qNode<PoseDriver,PoseDriver> *v9; // rcx
  UFG::qNode<PoseDriver,PoseDriver> *v10; // rax
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v12; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<Creature>Vtbl *)&Creature::`vftable';
  Creature::WaitOnPoseTask(this);
  v2 = &v1->mPoseDrivers;
  for ( i = (signed __int64)&v1->mPoseDrivers.mNode.mNext[-1];
        (UFG::qList<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList,1,0> *)i != &v1->m_SafePointerList;
        i = (signed __int64)&v1->mPoseDrivers.mNode.mNext[-1] )
  {
    v4 = (_QWORD *)(i + 16);
    v5 = *(_QWORD *)(i + 16);
    v6 = *(_QWORD **)(i + 24);
    *(_QWORD *)(v5 + 8) = v6;
    *v6 = v5;
    *v4 = v4;
    v4[1] = v4;
    if ( v4 != (_QWORD *)16 )
      (*(void (__fastcall **)(_QWORD *, signed __int64))(*(v4 - 2) + 8i64))(v4 - 2, 1i64);
  }
  PoseNodeParent::~PoseNodeParent(&v1->mBlendTree);
  SkeletalPose::~SkeletalPose(&v1->mPose);
  UFG::qList<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption,1,0>::DeleteNodes((UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)&v1->mAttachments);
  v7 = v1->mAttachments.mNode.mPrev;
  v8 = v1->mAttachments.mNode.mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  v1->mAttachments.mNode.mPrev = &v1->mAttachments.mNode;
  v1->mAttachments.mNode.mNext = &v1->mAttachments.mNode;
  UFG::qList<WeightSetGroup,WeightSetGroup,1,0>::DeleteNodes((UFG::qList<ActionRequestDebug,ActionRequestDebug,1,0> *)&v1->mPoseDrivers);
  v9 = v2->mNode.mPrev;
  v10 = v1->mPoseDrivers.mNode.mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  v2->mNode.mPrev = &v2->mNode;
  v1->mPoseDrivers.mNode.mNext = &v1->mPoseDrivers.mNode;
  v1->vfptr = (UFG::qSafePointerNode<Creature>Vtbl *)&UFG::qSafePointerNode<Creature>::`vftable';
  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull((UFG::qSafePointerNode<UFG::ParkourHandle> *)v1);
  UFG::qList<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList,1,0>::DeleteNodes((UFG::qList<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList,1,0> *)&v1->m_SafePointerList);
  v11 = v1->m_SafePointerList.mNode.mPrev;
  v12 = v1->m_SafePointerList.mNode.mNext;
  v11->mNext = v12;
  v12->mPrev = v11;
  v1->m_SafePointerList.mNode.mPrev = &v1->m_SafePointerList.mNode;
  v1->m_SafePointerList.mNode.mNext = &v1->m_SafePointerList.mNode;
}

// File Line: 195
// RVA: 0x3A6A60
void __fastcall Creature::Destroy(Creature *this)
{
  Creature *v1; // rbx

  v1 = this;
  Creature::WaitOnPoseTask(this);
  if ( v1 )
    v1->vfptr->__vecDelDtor((UFG::qSafePointerNode<Creature> *)&v1->vfptr, 1u);
}

// File Line: 208
// RVA: 0x3AC7A0
PoseNode *__fastcall Creature::PlayAnimation(Creature *this, UFG::qSymbolUC *animName, AnimationPlayMode playMode, float startTime, float endTime, float blendInTime, bool phaseIn, int *returnCode)
{
  AnimationPlayMode v8; // esi
  UFG::qSymbolUC *v9; // rbx
  Creature *v10; // rdi
  char *v11; // rax
  PoseNode *v12; // rax
  PoseNode *v13; // rbx
  SkeletalAnimation *v14; // rcx
  UFG::qMatrix44 outMatrix; // [rsp+50h] [rbp-68h]

  v8 = playMode;
  v9 = animName;
  v10 = this;
  v11 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x170ui64, "Creature.newActiveBranch", 0i64, 1u);
  if ( v11 )
  {
    AnimationNode::AnimationNode((AnimationNode *)v11, v9, v8, startTime, endTime);
    v13 = v12;
  }
  else
  {
    v13 = 0i64;
  }
  v14 = (SkeletalAnimation *)v13[2].vfptr;
  if ( v14 && v8 == 4 && SkeletalAnimation::GetAnimationRootOrigin(v14, &outMatrix) )
  {
    SkeletalPose::SetRoot(&v10->mPose, &outMatrix, 1);
    v10->mAbsoluteMon.v0 = outMatrix.v0;
    v10->mAbsoluteMon.v1 = outMatrix.v1;
    v10->mAbsoluteMon.v2 = outMatrix.v2;
    v10->mAbsoluteMon.v3 = outMatrix.v3;
    v10->mAbsoluteMonSet = 1;
  }
  Creature::PlayBlendTree(v10, v13, 0, blendInTime, phaseIn, startTime, endTime, returnCode);
  return v13;
}

// File Line: 239
// RVA: 0x3AC8F0
PoseNode *__fastcall Creature::PlayBlendTree(Creature *this, UFG::qSymbolUC *treeName, int priority, float blendInTime, bool phaseIn, float startTime, float endTime, int *returnCode)
{
  int v8; // ebx
  unsigned int v9; // er9
  Creature *v10; // rdi
  int v11; // er10
  int v12; // er9
  BlendTreeDataBase::PoseNodeLookupEntry *v13; // r11
  unsigned int v14; // er8
  unsigned int v15; // eax
  unsigned int v16; // edx
  PoseNode *v18; // rcx
  PoseNode *v19; // rax

  v8 = priority;
  v9 = BlendTreeDataBase::sBlendTreeDataBase->mPoseNodeLookup.size;
  v10 = this;
  if ( !v9 )
    return 0i64;
  v11 = 0;
  v12 = v9 - 1;
  if ( v12 < 0 )
    return 0i64;
  v13 = BlendTreeDataBase::sBlendTreeDataBase->mPoseNodeLookup.p;
  v14 = treeName->mUID;
  while ( 1 )
  {
    v15 = (v12 + v11) / 2;
    v16 = v13[v15].mName.mUID;
    if ( v14 <= v16 )
      break;
    v11 = v15 + 1;
LABEL_8:
    if ( v11 > v12 )
      return 0i64;
  }
  if ( v14 < v16 )
  {
    v12 = v15 - 1;
    goto LABEL_8;
  }
  v18 = v13[(v12 + v11) / 2].mpPoseNode;
  if ( !v18 )
    return 0i64;
  v19 = (PoseNode *)((__int64 (*)(void))v18->vfptr[1].Serialize)();
  return Creature::PlayBlendTree(v10, v19, v8, blendInTime, phaseIn, startTime, endTime, returnCode);
}

// File Line: 250
// RVA: 0x3ACB90
PoseNode *__fastcall Creature::PlayBlendTree(Creature *this, PoseNode *blendTree, PoseNodeParent *blendTreeParent, int priority, bool phaseIn, float startTime, float endTime, int *returnCode)
{
  unsigned int v8; // er12
  PoseNodeParent *v9; // r14
  PoseNode *v10; // rbx
  Creature *v11; // rbp
  Expression::IMemberMapVtbl *v13; // rax
  signed __int64 v14; // rdi
  int v15; // eax
  signed __int64 v16; // rcx
  bool v17; // zf
  bool v18; // sf
  Expression::IMemberMapVtbl *v19; // rax
  __int64 v20; // rax
  __int64 v21; // rax
  _QWORD *v22; // rsi
  __int64 v23; // rax
  signed __int64 v24; // r15
  UFG::qNode<PoseNode,PoseNode> *v25; // rax
  UFG::qNode<PoseNode,PoseNode> *v26; // rcx
  __int64 v27; // rax
  UFG::qOffset64<PoseNodeParent *> *v28; // rcx
  signed __int64 v29; // rax
  signed __int64 v30; // rax
  Expression::IMemberMapVtbl *v31; // rax
  signed __int64 v32; // rcx
  Expression::IMemberMapVtbl *v33; // rax
  void **v34; // [rsp+20h] [rbp-78h]
  char v35; // [rsp+28h] [rbp-70h]
  __int64 dest; // [rsp+30h] [rbp-68h]
  void **v37; // [rsp+50h] [rbp-48h]
  char v38; // [rsp+58h] [rbp-40h]
  char v39; // [rsp+60h] [rbp-38h]

  v8 = priority;
  v9 = blendTreeParent;
  *returnCode = 0;
  v10 = blendTree;
  v11 = this;
  if ( this->mNetworkLock )
    return 0i64;
  if ( blendTree )
  {
    blendTree->vfptr[4].__vecDelDtor((Expression::IMemberMap *)blendTree, priority);
    ((void (__fastcall *)(PoseNode *))v10->vfptr[3].GetResourcePath)(v10);
    if ( endTime >= 0.0 )
    {
      v34 = &AnimationNode_SetPlayEndTime::`vftable';
      v13 = v10->vfptr;
      *(float *)&dest = endTime;
      v35 = 1;
      v13[1].FindWithOldPath((Expression::IMemberMap *)&v10->vfptr, (const char *)&v34);
    }
    v14 = (signed __int64)&v11->mBlendTree;
    v15 = (__int64)v11->mBlendTree.vfptr[1].CreateClone((Expression::IMemberMap *)&v11->mBlendTree.vfptr);
    v16 = (signed __int64)&v11->mBlendTree;
    v17 = v15 == 0;
    v18 = v15 < 0;
    v19 = v11->mBlendTree.vfptr;
    if ( !v18 && !v17 )
    {
      v20 = (__int64)v19[1].__vecDelDtor((Expression::IMemberMap *)v16, 0);
      v21 = (*(__int64 (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v20 + 312i64))(v20, v8);
      v22 = (_QWORD *)v21;
      if ( v21 )
      {
        v23 = *(_QWORD *)(v21 + 56);
        if ( v23 )
          v24 = (signed __int64)v22 + v23 + 56;
        else
          v24 = 0i64;
        if ( v9 )
        {
          v9->vfptr[4].__vecDelDtor((Expression::IMemberMap *)&v9->vfptr, v8);
          v25 = (UFG::qNode<PoseNode,PoseNode> *)v22[5];
          v26 = (UFG::qNode<PoseNode,PoseNode> *)&v9->mPrev;
          v25->mNext = (UFG::qNode<PoseNode,PoseNode> *)&v9->mPrev;
          v26->mPrev = v25;
          v26->mNext = (UFG::qNode<PoseNode,PoseNode> *)(v22 + 5);
          v22[5] = (char *)v9 + 40;
          v27 = v22[7];
          v28 = &v9->mParent;
          if ( v27 && (v29 = (signed __int64)v22 + v27 + 56) != 0 )
            v30 = v29 - (_QWORD)v28;
          else
            v30 = 0i64;
          v28->mOffset = v30;
          (*(void (__fastcall **)(signed __int64, _QWORD *))(*(_QWORD *)v24 + 384i64))(v24, v22);
          ((void (__fastcall *)(PoseNodeParent *, _QWORD *))v9->vfptr[4].GetClassNameUID)(v9, v22);
          v31 = v9->vfptr;
          v32 = (signed __int64)v9;
        }
        else
        {
          (*(void (__fastcall **)(signed __int64))(*(_QWORD *)v24 + 392i64))(v24);
          v31 = *(Expression::IMemberMapVtbl **)v14;
          v32 = (signed __int64)&v11->mBlendTree;
        }
        ((void (__fastcall *)(signed __int64, PoseNode *))v31[4].GetClassNameUID)(v32, v10);
        v35 = 1;
        v34 = &BlendDirectionNode_GetBlendDirection::`vftable';
        UFG::qMemSet(&dest, 0, 0x20u);
        (*(void (__fastcall **)(_QWORD *, void ***))(*v22 + 80i64))(v22, &v34);
        v37 = &BlendDirectionNode_SetBlendDirection::`vftable';
        v38 = 1;
        UFG::qMemCopy(&v39, &dest, 0x20u);
        v10->vfptr[1].FindWithOldPath((Expression::IMemberMap *)&v10->vfptr, (const char *)&v37);
        goto LABEL_21;
      }
      v19 = *(Expression::IMemberMapVtbl **)v14;
      v16 = (signed __int64)&v11->mBlendTree;
    }
    v19[4].GetResourceOwner((Expression::IMemberMap *)v16);
    (*(void (__fastcall **)(PoseNodeParent *, PoseNode *))(*(_QWORD *)v14 + 360i64))(&v11->mBlendTree, v10);
LABEL_21:
    v34 = &PoseStackCalculatorVisitor::`vftable';
    v33 = v10->vfptr;
    v35 = 1;
    dest = 0i64;
    v33[1].FindWithOldPath((Expression::IMemberMap *)&v10->vfptr, (const char *)&v34);
    v11->mCurrentStackDepth += dest;
  }
  Creature::pruneBigBlendTree(v11);
  return v10;
}

// File Line: 359
// RVA: 0x3AC9B0
PoseNode *__fastcall Creature::PlayBlendTree(Creature *this, PoseNode *blendTree, int priority, float blendInTime, bool phaseIn, float startTime, float endTime, int *returnCode)
{
  unsigned int v8; // ebp
  PoseNode *v9; // rbx
  Creature *v10; // rsi
  Expression::IMemberMapVtbl *v12; // rax
  int v13; // eax
  signed __int64 v14; // rcx
  bool v15; // zf
  bool v16; // sf
  Expression::IMemberMapVtbl *v17; // rax
  __int64 v18; // rax
  PoseNode *v19; // rdi
  __int64 v20; // rax
  void **v21; // [rsp+20h] [rbp-88h]
  char v22; // [rsp+28h] [rbp-80h]
  __int64 dest; // [rsp+30h] [rbp-78h]
  void **v24; // [rsp+50h] [rbp-58h]
  char v25; // [rsp+58h] [rbp-50h]
  char v26; // [rsp+60h] [rbp-48h]

  v8 = priority;
  v9 = blendTree;
  v10 = this;
  if ( this->mNetworkLock )
    return 0i64;
  if ( blendTree )
  {
    blendTree->vfptr[4].__vecDelDtor((Expression::IMemberMap *)blendTree, priority);
    if ( startTime >= 0.0 )
      ((void (__fastcall *)(PoseNode *))v9->vfptr[3].GetResourcePath)(v9);
    if ( endTime >= 0.0 )
    {
      v21 = &AnimationNode_SetPlayEndTime::`vftable';
      v12 = v9->vfptr;
      *(float *)&dest = endTime;
      v22 = 1;
      v12[1].FindWithOldPath((Expression::IMemberMap *)&v9->vfptr, (const char *)&v21);
    }
    v13 = (__int64)v10->mBlendTree.vfptr[1].CreateClone((Expression::IMemberMap *)&v10->mBlendTree.vfptr);
    v14 = (signed __int64)&v10->mBlendTree;
    v15 = v13 == 0;
    v16 = v13 < 0;
    v17 = v10->mBlendTree.vfptr;
    if ( v16 || v15 )
    {
      v17[4].GetResourceOwner((Expression::IMemberMap *)v14);
      ((void (__fastcall *)(PoseNodeParent *, PoseNode *))v10->mBlendTree.vfptr[4].GetClassNameUID)(
        &v10->mBlendTree,
        v9);
    }
    else
    {
      v18 = (__int64)v17[1].__vecDelDtor((Expression::IMemberMap *)v14, 0);
      v19 = (PoseNode *)v18;
      v20 = (*(__int64 (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v18 + 312i64))(v18, v8);
      if ( v20 )
        v19 = (PoseNode *)v20;
      PoseNode::BlendIn(v19, v9, blendInTime, phaseIn);
      v22 = 1;
      v21 = &BlendDirectionNode_GetBlendDirection::`vftable';
      UFG::qMemSet(&dest, 0, 0x20u);
      v19->vfptr[1].FindWithOldPath((Expression::IMemberMap *)&v19->vfptr, (const char *)&v21);
      v24 = &BlendDirectionNode_SetBlendDirection::`vftable';
      v25 = 1;
      UFG::qMemCopy(&v26, &dest, 0x20u);
      v9->vfptr[1].FindWithOldPath((Expression::IMemberMap *)&v9->vfptr, (const char *)&v24);
    }
    v21 = &PoseStackCalculatorVisitor::`vftable';
    v22 = 1;
    dest = 0i64;
    v9->vfptr[1].FindWithOldPath((Expression::IMemberMap *)&v9->vfptr, (const char *)&v21);
    v10->mCurrentStackDepth += dest;
  }
  Creature::pruneBigBlendTree(v10);
  return v9;
}

// File Line: 447
// RVA: 0x3B7CC0
char __fastcall Creature::pruneBigBlendTree(Creature *this)
{
  Creature *v1; // rsi
  char *v2; // rbx
  __int64 v3; // rax
  __int64 v4; // rdx
  unsigned int v5; // eax
  unsigned int v6; // edi
  __int64 v7; // rax
  unsigned int v8; // eax
  unsigned int v9; // eax
  void **v11; // [rsp+20h] [rbp-38h]
  char v12; // [rsp+28h] [rbp-30h]
  __int64 v13; // [rsp+30h] [rbp-28h]

  v1 = this;
  if ( this->mCurrentStackDepth < sMaxBlendTreeDepth )
    return 0;
  v2 = (char *)&this->mBlendTree;
  if ( (signed int)this->mBlendTree.vfptr[1].CreateClone((Expression::IMemberMap *)&this->mBlendTree) > 0 )
  {
    (*(void (__fastcall **)(char *, _QWORD))(*(_QWORD *)v2 + 88i64))(v2, 0i64);
    v11 = &PoseStackCalculatorVisitor::`vftable';
    v3 = *(_QWORD *)v2;
    v12 = 1;
    v13 = 0i64;
    (*(void (__fastcall **)(char *, void ***))(v3 + 80))(v2, &v11);
    v5 = v13;
    v6 = 0;
    v1->mCurrentStackDepth = v13;
    if ( v5 >= sMaxBlendTreeDepth )
    {
      do
      {
        if ( v6 >= sMaxIteractions )
          break;
        ++v6;
        (*(void (__fastcall **)(char *, __int64, _QWORD))(*(_QWORD *)v2 + 120i64))(v2, v4, 0i64);
        v7 = *(_QWORD *)v2;
        v13 = 0i64;
        (*(void (__fastcall **)(char *, void ***))(v7 + 80))(v2, &v11);
        v8 = v13;
        v1->mCurrentStackDepth = v13;
      }
      while ( v8 >= sMaxBlendTreeDepth );
    }
    v9 = gMaxIteractionsMetric;
    if ( gMaxIteractionsMetric <= v6 )
      v9 = v6;
    gMaxIteractionsMetric = v9;
  }
  return 1;
}

// File Line: 483
// RVA: 0x3AB360
void __fastcall Creature::KillBlendTree(Creature *this)
{
  if ( !this->mNetworkLock )
    ((void (*)(void))this->mBlendTree.vfptr[4].GetResourceOwner)();
}

// File Line: 506
// RVA: 0x3B13F0
void __usercall Creature::Update(Creature *this@<rcx>, float deltaTime@<xmm1>, __int64 a3@<rdx>, __int64 a4@<r8>)
{
  Creature *v4; // rdi
  float v5; // xmm6_4
  float v6; // xmm6_4
  UFG::qList<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList,1,0> *v7; // rcx
  signed __int64 v8; // rbx

  v4 = this;
  if ( gAnimCharEnable )
  {
    if ( this->mPlaybackSpeedEnabled )
      v5 = this->mPlaybackSpeed;
    else
      v5 = *(float *)&FLOAT_1_0;
    v6 = v5 * deltaTime;
    LOBYTE(a4) = 1;
    ((void (__fastcall *)(PoseNodeParent *, __int64, __int64))this->mBlendTree.vfptr[1].GetClassNameUID)(
      &this->mBlendTree,
      a3,
      a4);
    Creature::updateAnimatedMovement(v4, v6);
    Creature::updateAttachments(v4, v6);
    v7 = (UFG::qList<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList,1,0> *)&v4->mPoseDrivers.mNode.mNext[-1];
    if ( v7 != &v4->m_SafePointerList )
    {
      do
      {
        v8 = (signed __int64)&v7[1].mNode.mNext[-1];
        ((void (*)(void))v7->mNode.mPrev[8].mPrev)();
        v7 = (UFG::qList<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList,1,0> *)v8;
      }
      while ( (UFG::qList<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList,1,0> *)v8 != &v4->m_SafePointerList );
    }
    v4->mPlaybackSpeed = 1.0;
  }
}

// File Line: 583
// RVA: 0x3AD290
void __fastcall Creature::PrepPoseTaskInput(Creature *this, PoseNode *tree)
{
  PoseTaskInputParams *v2; // r13
  int v3; // edi
  hkaSkeleton *v4; // r8
  PoseNode *v5; // r15
  Creature *v6; // r14
  int v7; // eax
  hkaBone *v8; // r9
  hkQsTransformf *v9; // r10
  __int16 *v10; // r11
  int v11; // eax
  char v12; // bp
  unsigned int v13; // er12
  PoseRecipe *v14; // rax
  unsigned int v15; // eax
  int v16; // ecx
  int v17; // eax
  unsigned int v18; // ebx
  __int64 v19; // rdx
  signed int *v20; // r8
  signed int v21; // eax
  unsigned int v22; // ecx
  unsigned int v23; // esi
  unsigned int v24; // eax
  hkaPose *v25; // rcx
  char *v26; // rax
  unsigned int v27; // edx
  int v28; // eax
  __int64 v29; // r8
  signed int *v30; // rcx
  signed int v31; // eax
  unsigned int v32; // edi
  __int64 v33; // [rsp+20h] [rbp-1BD8h]
  PoseRecipeVisitor v34; // [rsp+40h] [rbp-1BB8h]
  int v35; // [rsp+1C00h] [rbp+8h]

  v2 = &this->mPoseTaskParams;
  v3 = 0;
  v4 = this->mPose.mRigHandle.mUFGSkeleton->mhkaSkeleton;
  v5 = tree;
  v6 = this;
  v7 = v4->m_bones.m_size;
  v8 = v4->m_bones.m_data;
  v9 = v4->m_referencePose.m_data;
  v10 = v4->m_parentIndices.m_data;
  v34.mRecipe = &v2->mRecipe;
  v34.mRecurse = 1;
  v35 = v7;
  LODWORD(v33) = v7;
  *(_QWORD *)&v2->mRecipe.mSkelDesc.mBoneCount = v33;
  v11 = this->mPose.mBoneUpdateCount;
  v2->mRecipe.mSkelDesc.mBones = v8;
  v2->mRecipe.mSkelDesc.mReferencePose = v9;
  this->mPoseTaskParams.mRecipe.mBoneUpdateCount = v11;
  v2->mRecipe.mSkelDesc.mParentIndices = (const unsigned __int16 *)v10;
  v12 = 0;
  v13 = 0;
  v34.vfptr = (PoseNodeVisitorVtbl *)&PoseRecipeVisitor::`vftable';
  *(_QWORD *)&v2->mRecipe.mStackCount = 0i64;
  v2->mRecipe.mBoneUpdateCount = -1;
  *(_QWORD *)&v2->mRecipe.mAnimMemoryHighWaterMark = 0i64;
  v2->mRecipe.mPoseStack = 0i64;
  v2->mRecipe.mAnimData = 0i64;
  while ( 1 )
  {
    v14 = v34.mRecipe;
    v34.mIsValid = 1;
    *(_QWORD *)&v34.mStackCount = 0i64;
    *(_QWORD *)&v34.mRecipe->mStackCount = 0i64;
    v14->mBoneUpdateCount = -1;
    *(_QWORD *)&v14->mAnimMemoryHighWaterMark = 0i64;
    v14->mPoseStack = 0i64;
    v14->mAnimData = 0i64;
    v5->vfptr[1].FindWithOldPath((Expression::IMemberMap *)&v5->vfptr, (const char *)&v34);
    v15 = v34.mStackCount;
    v16 = 0;
    v6->mCurrentStackDepth = v34.mStackCount;
    v17 = v15 - 1;
    v18 = 0;
    v19 = v17;
    if ( v17 >= 0 )
    {
      v20 = (signed int *)&v34.mPoseStack[v17];
      do
      {
        v21 = *v20;
        if ( *v20 >= 0 )
        {
          if ( v21 <= 1 )
          {
            if ( ++v16 > v18 )
              v18 = v16;
          }
          else if ( v21 == 2 )
          {
            v22 = v16 + 2;
            if ( v22 > v18 )
              v18 = v22;
            v16 = v22 - 1;
          }
          else if ( (unsigned int)(v21 - 3) <= 6 )
          {
            --v16;
          }
        }
        v20 -= 4;
        --v19;
      }
      while ( v19 >= 0 );
    }
    v23 = 48 * v35 * v18 + ((8 * v18 + 15) & 0xFFFFFFF0);
    if ( sActivatePrune )
    {
      v12 = v34.mIsValid && v18 <= 0x40 && v23 <= 0x20000 ? 0 : 1;
      if ( v13 > sMaxPruneOperations )
        break;
    }
    if ( v12 != 1 )
      break;
    ++v13;
    ((void (__fastcall *)(PoseNode *, __int64, _QWORD))v5->vfptr[1].GetClassNameUID)(v5, v19, 0i64);
  }
  PoseRecipeVisitor::CommitAnimData(&v34);
  v24 = PoseRecipeVisitor::CommitData(&v34);
  v25 = v6->mPose.mHavokPose;
  v6->mPoseTaskParams.mBufferCount = v18;
  v6->mPoseCRC = v24;
  v6->mPoseTaskParams.mBufferSize = v23;
  v6->mPoseTaskParams.mOutputTransforms = hkaPose::accessUnsyncedPoseModelSpace(v25)->m_data;
  v6->mPoseState = 0;
  v6->mPoseTaskParams.mBufferStride = 48 * v35;
  if ( !v34.mIsValid || v6->mPoseTaskParams.mBufferCount > 0x40 || v6->mPoseTaskParams.mBufferSize > 0x20000 )
  {
    *(_QWORD *)&v6->mPoseTaskParams.mRecipe.mStackCount = 0i64;
    v6->mPoseTaskParams.mRecipe.mBoneUpdateCount = -1;
    *(_QWORD *)&v6->mPoseTaskParams.mRecipe.mAnimMemoryHighWaterMark = 0i64;
    v6->mPoseTaskParams.mRecipe.mPoseStack = 0i64;
    v6->mPoseTaskParams.mRecipe.mAnimData = 0i64;
    v6->mPoseTaskParams.mRecipe.mStackCount = 1;
    v26 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 0x10u);
    v27 = 0;
    v6->mPoseTaskParams.mRecipe.mPoseStack = (PoseRecipe::PoseStackEntry *)v26;
    *(_DWORD *)v26 = 0;
    v28 = v6->mPoseTaskParams.mRecipe.mStackCount - 1;
    v29 = v28;
    if ( v28 >= 0 )
    {
      v30 = (signed int *)&v6->mPoseTaskParams.mRecipe.mPoseStack[v28];
      do
      {
        v31 = *v30;
        if ( *v30 >= 0 )
        {
          if ( v31 <= 1 )
          {
            if ( ++v3 > v27 )
              v27 = v3;
          }
          else if ( v31 == 2 )
          {
            v32 = v3 + 2;
            if ( v32 > v27 )
              v27 = v32;
            v3 = v32 - 1;
          }
          else if ( (unsigned int)(v31 - 3) <= 6 )
          {
            --v3;
          }
        }
        v30 -= 4;
        --v29;
      }
      while ( v29 >= 0 );
    }
    v6->mPoseTaskParams.mBufferCount = v27;
    v6->mPoseTaskParams.mBufferSize = 48 * v35 * v27 + ((8 * v27 + 15) & 0xFFFFFFF0);
  }
}

// File Line: 700
// RVA: 0x3AFE90
void __fastcall Creature::SubmitPoseTask(Creature *this)
{
  Creature *v1; // rbx
  unsigned int v2; // eax
  PoseCache *v3; // rdi
  PoseCacheNode *v4; // rax
  PoseCacheNode *v5; // rsi
  UFG::qNode<PoseCacheNode,PoseCacheNode> *v6; // rdx
  UFG::qNode<PoseCacheNode,PoseCacheNode> *v7; // rcx
  UFG::qNode<PoseCacheNode,PoseCacheNode> *v8; // r8
  UFG::qNode<PoseCacheNode,PoseCacheNode> *v9; // rax
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  unsigned int v14; // eax

  v1 = this;
  Creature::WaitOnPoseTask(this);
  if ( (signed int)v1->mBlendTree.vfptr[1].CreateClone((Expression::IMemberMap *)&v1->mBlendTree.vfptr) > 0 )
  {
    Creature::PrepPoseTaskInput(v1, (PoseNode *)&v1->mBlendTree.vfptr);
    v2 = v1->mPoseCRC;
    if ( v2 != -1
      && v1->mLowPowerModeEnabled
      && (v3 = PoseCache::sPoseCache, PoseCache::sPoseCache->mEnablePoseCache)
      && (v4 = PoseCache::Find(
                 PoseCache::sPoseCache,
                 LODWORD(v1->mPose.mRigHandle.mUFGSkeleton) | ((unsigned __int64)v2 << 32)),
          (v5 = v4) != 0i64) )
    {
      v6 = v4->mPrev;
      v7 = v4->mNext;
      v8 = (UFG::qNode<PoseCacheNode,PoseCacheNode> *)&v4->mPrev;
      v6->mNext = v7;
      v7->mPrev = v6;
      v8->mPrev = v8;
      v8->mNext = v8;
      v9 = v3->mCachedDataList.mNode.mPrev;
      v9->mNext = v8;
      v8->mPrev = v9;
      v8->mNext = &v3->mCachedDataList.mNode;
      v3->mCachedDataList.mNode.mPrev = v8;
      UFG::qMemCopy(v1->mPoseTaskParams.mOutputTransforms, v5->mCachedDataPtr, v1->mPoseTaskParams.mBufferStride);
      v10 = v5->mAABBMin.y;
      v11 = v5->mAABBMin.z;
      v1->mPoseTaskParams.mOutputModelSpaceAABBMin.x = v5->mAABBMin.x;
      v1->mPoseTaskParams.mOutputModelSpaceAABBMin.y = v10;
      v1->mPoseTaskParams.mOutputModelSpaceAABBMin.z = v11;
      v12 = v5->mAABBMax.y;
      v13 = v5->mAABBMax.z;
      v1->mPoseTaskParams.mOutputModelSpaceAABBMax.x = v5->mAABBMax.x;
      v1->mPoseTaskParams.mOutputModelSpaceAABBMax.y = v12;
      v1->mPoseTaskParams.mOutputModelSpaceAABBMax.z = v13;
      v1->mPoseTask = 0i64;
      v1->mPoseState = 1;
    }
    else if ( v1->mPoseTaskParams.mRecipe.mStackCount <= 0x60 && v1->mPoseTaskParams.mRecipe.mAnimDataCount <= 0x31 )
    {
      v1->mPoseTask = PoseTaskSubmission::SubmitTask(&v1->mPoseTaskParams);
      v14 = PoseTaskSubmission::sFrameIndex;
      v1->mPoseState = 2;
      v1->mPoseFrame = v14;
    }
  }
}

// File Line: 741
// RVA: 0x3B6160
void __fastcall Creature::WaitOnPoseTask(Creature *this)
{
  UFG::qTask *v1; // rdx
  Creature *v2; // rbx
  unsigned int v3; // eax
  UFG::allocator::free_link *v4; // rax
  UFG::allocator::free_link *v5; // rdi
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm1_4

  v1 = this->mPoseTask;
  v2 = this;
  if ( v1 )
  {
    if ( this->mPoseFrame == PoseTaskSubmission::sFrameIndex )
    {
      UFG::qTaskManager::Sync(&UFG::gTaskManager, v1);
      v3 = v2->mPoseCRC;
      if ( v3 != -1 )
      {
        if ( v2->mLowPowerModeEnabled )
        {
          if ( PoseCache::sPoseCache->mEnablePoseCache )
          {
            v4 = PoseCache::Store(
                   PoseCache::sPoseCache,
                   LODWORD(v2->mPose.mRigHandle.mUFGSkeleton) | ((unsigned __int64)v3 << 32),
                   v2->mPoseTaskParams.mBufferStride);
            v5 = v4;
            if ( v4 )
            {
              UFG::qMemCopy(v4[6].mNext, v2->mPoseTaskParams.mOutputTransforms, v2->mPoseTaskParams.mBufferStride);
              v6 = v2->mPoseTaskParams.mOutputModelSpaceAABBMin.y;
              v7 = v2->mPoseTaskParams.mOutputModelSpaceAABBMin.z;
              *(float *)&v5[7].mNext = v2->mPoseTaskParams.mOutputModelSpaceAABBMin.x;
              *((float *)&v5[7].mNext + 1) = v6;
              *(float *)&v5[8].mNext = v7;
              v8 = v2->mPoseTaskParams.mOutputModelSpaceAABBMax.y;
              v9 = v2->mPoseTaskParams.mOutputModelSpaceAABBMax.z;
              HIDWORD(v5[8].mNext) = LODWORD(v2->mPoseTaskParams.mOutputModelSpaceAABBMax.x);
              *(float *)&v5[9].mNext = v8;
              *((float *)&v5[9].mNext + 1) = v9;
            }
          }
        }
      }
    }
  }
  v2->mPoseTask = 0i64;
  v2->mPoseState = 3;
}

// File Line: 773
// RVA: 0x3B4C90
void __fastcall Creature::UpdateTransforms(Creature *this)
{
  Creature *v1; // rbx
  float v2; // xmm0_4
  float v3; // xmm1_4
  float v4; // xmm0_4
  float v5; // xmm1_4
  UFG::qColour v6; // [rsp+20h] [rbp-18h]

  v1 = this;
  if ( (unsigned int)(this->mPoseState - 1) <= 1 )
  {
    Creature::WaitOnPoseTask(this);
LABEL_10:
    v2 = v1->mPoseTaskParams.mOutputModelSpaceAABBMin.y;
    v3 = v1->mPoseTaskParams.mOutputModelSpaceAABBMin.z;
    v1->mPose.mPoseAABBMin.x = v1->mPoseTaskParams.mOutputModelSpaceAABBMin.x;
    v1->mPose.mPoseAABBMin.y = v2;
    v1->mPose.mPoseAABBMin.z = v3;
    v4 = v1->mPoseTaskParams.mOutputModelSpaceAABBMax.y;
    v5 = v1->mPoseTaskParams.mOutputModelSpaceAABBMax.z;
    v1->mPose.mPoseAABBMax.x = v1->mPoseTaskParams.mOutputModelSpaceAABBMax.x;
    v1->mPose.mPoseAABBMax.y = v4;
    v1->mPose.mPoseAABBMax.z = v5;
    v1->mRestPosePrev = 0;
    goto LABEL_11;
  }
  if ( (signed int)this->mBlendTree.vfptr[1].CreateClone((Expression::IMemberMap *)&this->mBlendTree) > 0 )
  {
    if ( v1->mPoseState )
      Creature::PrepPoseTaskInput(v1, (PoseNode *)&v1->mBlendTree.vfptr);
    PoseTaskSubmission::ExecuteLocalTask(&v1->mPoseTaskParams);
    goto LABEL_10;
  }
  if ( rest_pose_opt && !v1->mRestPosePrev )
  {
    SkeletalPose::SetToRestPose(&v1->mPose);
    v1->mRestPosePrev = 1;
  }
LABEL_11:
  if ( gDrawPosePostAnimUpdate )
  {
    v6 = UFG::qColour::Pink;
    SkeletalPose::DebugDraw(&v1->mPose, &v6, 1.0);
  }
  Creature::updateEffectorsToPose(v1);
  v1->mPose.mBoneUpdateCount = -1;
  v1->mPoseTask = 0i64;
  v1->mPoseFrame = PoseTaskSubmission::sFrameIndex;
}

// File Line: 1018
// RVA: 0x3B8570
void __fastcall Creature::updateAnimatedMovement(Creature *this, float deltaTime)
{
  Creature *v2; // rbx
  Expression::IMemberMapVtbl *v3; // rax
  char *v4; // rdx
  Expression::IMemberMapVtbl *v5; // rax
  hkQsTransformf *v6; // rax
  __m128 v7; // xmm2
  __m128 v8; // xmm5
  __m128 v9; // xmm6
  __m128 v10; // xmm1
  __m128 v11; // xmm4
  __m128 v12; // xmm3
  __m128 v13; // xmm4
  __m128 v14; // xmm3
  __m128 v15; // xmm2
  __m128 v16; // xmm4
  __m128 v17; // xmm4
  __m128 v18; // xmm1
  __m128 v19; // xmm0
  __m128 v20; // xmm1
  __m128 v21; // xmm2
  hkVector4f v22; // xmm2
  hkVector4f v23; // xmm1
  hkQuaternionf v24; // xmm0
  float v25; // xmm5_4
  __m128 v26; // xmm4
  float v27; // xmm6_4
  float v28; // xmm3_4
  __m128 v29; // xmm2
  Expression::IMemberMapVtbl *v30; // rax
  __m128 v31; // xmm1
  __m128 v32; // xmm7
  __m128 v33; // xmm5
  __m128 v34; // xmm4
  __m128 v35; // xmm3
  __m128 v36; // xmm6
  __m128 v37; // xmm4
  __m128 v38; // xmm3
  __m128 v39; // xmm4
  hkQsTransformf v40; // [rsp+20h] [rbp-D8h]
  void **v41; // [rsp+50h] [rbp-A8h]
  char v42; // [rsp+58h] [rbp-A0h]
  _BYTE *v43; // [rsp+60h] [rbp-98h]
  void **v44; // [rsp+68h] [rbp-90h]
  char v45; // [rsp+70h] [rbp-88h]
  __m128 v46; // [rsp+78h] [rbp-80h]
  __m128 v47; // [rsp+88h] [rbp-70h]
  __m128 v48; // [rsp+98h] [rbp-60h]
  hkQsTransformf newRoot; // [rsp+A8h] [rbp-50h]
  hkQsTransformf v50; // [rsp+D8h] [rbp-20h]
  __int128 v51; // [rsp+108h] [rbp+10h]
  __m128 v52; // [rsp+118h] [rbp+20h]
  __m128 v53; // [rsp+128h] [rbp+30h]
  hkTransformf transform; // [rsp+138h] [rbp+40h]

  v2 = this;
  Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
  v3 = v2->mBlendTree.vfptr;
  v46 = 0i64;
  v47 = qi.m_vec.m_quad;
  v48 = query.m_quad;
  v3[1].GetResourcePath((Expression::IMemberMap *)&v2->mBlendTree.vfptr, v4, (int)&v46);
  v44 = &AnimationNode_UpdateLastPlayTime::`vftable';
  v5 = v2->mBlendTree.vfptr;
  v45 = 1;
  v5[1].FindWithOldPath((Expression::IMemberMap *)&v2->mBlendTree.vfptr, (const char *)&v44);
  if ( v2->mAbsoluteMonSet )
    v2->mAbsoluteMonSet = 0;
  v52 = qi.m_vec.m_quad;
  v53 = query.m_quad;
  v51 = 0i64;
  v6 = SkeletalPose::GetRoot(&v2->mPose);
  v7 = v46;
  v2->mPrevMotion.m_translation = v6->m_translation;
  v8 = v6->m_rotation.m_vec.m_quad;
  v2->mPrevMotion.m_rotation.m_vec.m_quad = v8;
  v2->mPrevMotion.m_scale = v6->m_scale;
  v9 = _mm_shuffle_ps(v8, v8, 255);
  v10 = _mm_mul_ps(v7, v8);
  v11 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v7, v7, 201), v8), _mm_mul_ps(_mm_shuffle_ps(v8, v8, 201), v7));
  v12 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)),
                _mm_shuffle_ps(v10, v10, 170)),
              v8),
            _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v9, v9), (__m128)xmmword_141A711B0), v7)),
          _mm_mul_ps(_mm_shuffle_ps(v11, v11, 201), v9));
  v13 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v47, v47, 201), v8), _mm_mul_ps(_mm_shuffle_ps(v8, v8, 201), v47));
  newRoot.m_translation.m_quad = _mm_add_ps(_mm_add_ps(v12, v12), v2->mPrevMotion.m_translation.m_quad);
  v14 = _mm_shuffle_ps(v47, v47, 255);
  v15 = _mm_mul_ps(v47, v8);
  v16 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v13, v13, 201), _mm_mul_ps(v47, v9)), _mm_mul_ps(v8, v14));
  v17 = _mm_shuffle_ps(
          v16,
          _mm_unpackhi_ps(
            v16,
            _mm_sub_ps(
              _mm_mul_ps(v14, v9),
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)),
                _mm_shuffle_ps(v15, v15, 170)))),
          196);
  v18 = _mm_mul_ps(v17, v17);
  newRoot.m_scale.m_quad = _mm_mul_ps(v48, v2->mPrevMotion.m_scale.m_quad);
  v19 = _mm_add_ps(_mm_shuffle_ps(v18, v18, 78), v18);
  v20 = _mm_add_ps(_mm_shuffle_ps(v19, v19, 177), v19);
  v21 = _mm_rsqrt_ps(v20);
  newRoot.m_rotation.m_vec.m_quad = _mm_mul_ps(
                                      v17,
                                      _mm_mul_ps(
                                        _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v21, v20), v21)),
                                        _mm_mul_ps(*(__m128 *)_xmm, v21)));
  SkeletalPose::SetRoot(&v2->mPose, &newRoot, 0);
  v22.m_quad = (__m128)newRoot.m_translation;
  v23.m_quad = (__m128)newRoot.m_scale;
  v24.m_vec.m_quad = (__m128)newRoot.m_rotation;
  v2->mLastSetPosition.m_translation = newRoot.m_translation;
  v2->mLastSetPosition.m_scale = (hkVector4f)v23.m_quad;
  v2->mLastSetPosition.m_rotation = (hkQuaternionf)v24.m_vec.m_quad;
  v24.m_vec.m_quad.m128_f32[0] = v22.m_quad.m128_f32[0] - v2->mPrevMotion.m_translation.m_quad.m128_f32[0];
  v23.m_quad.m128_i32[0] = (unsigned __int128)_mm_shuffle_ps(v22.m_quad, v22.m_quad, 85);
  v22.m_quad.m128_f32[0] = newRoot.m_translation.m_quad.m128_f32[2] - v2->mPrevMotion.m_translation.m_quad.m128_f32[2];
  v23.m_quad.m128_f32[0] = v23.m_quad.m128_f32[0] - v2->mPrevMotion.m_translation.m_quad.m128_f32[1];
  LODWORD(v2->mAnimatedMoveDirection.x) = v24.m_vec.m_quad.m128_i32[0];
  LODWORD(v2->mAnimatedMoveDirection.z) = v22.m_quad.m128_i32[0];
  LODWORD(v2->mAnimatedMoveDirection.y) = v23.m_quad.m128_i32[0];
  v24.m_vec.m_quad.m128_f32[0] = fsqrt(
                                   (float)((float)(v23.m_quad.m128_f32[0] * v23.m_quad.m128_f32[0])
                                         + (float)(v24.m_vec.m_quad.m128_f32[0] * v24.m_vec.m_quad.m128_f32[0]))
                                 + (float)(v22.m_quad.m128_f32[0] * v22.m_quad.m128_f32[0]));
  LODWORD(v2->mAnimatedMoveSpeed) = v24.m_vec.m_quad.m128_i32[0];
  if ( v24.m_vec.m_quad.m128_f32[0] >= 0.000099999997 )
  {
    v25 = v2->mAnimatedMoveDirection.y;
    v26 = (__m128)LODWORD(v2->mAnimatedMoveDirection.x);
    v27 = v2->mAnimatedMoveDirection.z;
    v28 = 0.0;
    v29 = v26;
    v29.m128_f32[0] = (float)((float)(v26.m128_f32[0] * v26.m128_f32[0]) + (float)(v25 * v25)) + (float)(v27 * v27);
    if ( v29.m128_f32[0] != 0.0 )
      v28 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v29));
    v2->mAnimatedMoveDirection.x = v26.m128_f32[0] * v28;
    v2->mAnimatedMoveDirection.y = v25 * v28;
    v2->mAnimatedMoveDirection.z = v27 * v28;
  }
  v41 = &FirstAnimationNode::`vftable';
  v30 = v2->mBlendTree.vfptr;
  v42 = 1;
  v43 = 0i64;
  v30[1].FindWithOldPath((Expression::IMemberMap *)&v2->mBlendTree.vfptr, (const char *)&v41);
  if ( v43 )
  {
    v40.m_translation = 0i64;
    v40.m_rotation = (hkQuaternionf)qi.m_vec.m_quad;
    v40.m_scale = (hkVector4f)query.m_quad;
    if ( v43[360] == 4 )
    {
      (*(void (__fastcall **)(_BYTE *, hkQsTransformf *))(*(_QWORD *)v43 + 368i64))(v43, &v40);
      if ( v2->mAbsoluteRelativeRootMotion )
      {
        hkTransformf::set4x4ColumnMajor(&transform, &v2->mAbsoluteRelativeRoot.v0.x);
        hkQsTransformf::setFromTransformNoScale(&v50, &transform);
        v31 = _mm_mul_ps(v50.m_rotation.m_vec.m_quad, v40.m_translation.m_quad);
        v32 = _mm_shuffle_ps(v50.m_rotation.m_vec.m_quad, v50.m_rotation.m_vec.m_quad, 255);
        v33 = _mm_shuffle_ps(v50.m_rotation.m_vec.m_quad, v50.m_rotation.m_vec.m_quad, 201);
        v34 = _mm_sub_ps(
                _mm_mul_ps(
                  _mm_shuffle_ps(v40.m_translation.m_quad, v40.m_translation.m_quad, 201),
                  v50.m_rotation.m_vec.m_quad),
                _mm_mul_ps(v40.m_translation.m_quad, v33));
        v35 = _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v31, v31, 85), _mm_shuffle_ps(v31, v31, 0)),
                      _mm_shuffle_ps(v31, v31, 170)),
                    v50.m_rotation.m_vec.m_quad),
                  _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v32, v32), (__m128)xmmword_141A711B0), v40.m_translation.m_quad)),
                _mm_mul_ps(_mm_shuffle_ps(v34, v34, 201), v32));
        v36 = _mm_mul_ps(v50.m_rotation.m_vec.m_quad, v40.m_rotation.m_vec.m_quad);
        v37 = _mm_sub_ps(
                _mm_mul_ps(
                  _mm_shuffle_ps(v40.m_rotation.m_vec.m_quad, v40.m_rotation.m_vec.m_quad, 201),
                  v50.m_rotation.m_vec.m_quad),
                _mm_mul_ps(v40.m_rotation.m_vec.m_quad, v33));
        v40.m_translation.m_quad = _mm_add_ps(_mm_add_ps(v35, v35), v50.m_translation.m_quad);
        v38 = _mm_shuffle_ps(v40.m_rotation.m_vec.m_quad, v40.m_rotation.m_vec.m_quad, 255);
        v39 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v37, v37, 201), _mm_mul_ps(v40.m_rotation.m_vec.m_quad, v32)),
                _mm_mul_ps(v50.m_rotation.m_vec.m_quad, v38));
        v40.m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                        v39,
                                        _mm_unpackhi_ps(
                                          v39,
                                          _mm_sub_ps(
                                            _mm_mul_ps(v38, v32),
                                            _mm_add_ps(
                                              _mm_add_ps(_mm_shuffle_ps(v36, v36, 85), _mm_shuffle_ps(v36, v36, 0)),
                                              _mm_shuffle_ps(v36, v36, 170)))),
                                        196);
        v40.m_scale.m_quad = _mm_mul_ps(v40.m_scale.m_quad, v50.m_scale.m_quad);
      }
      SkeletalPose::SetRoot(&v2->mPose, &v40, 0);
    }
  }
  Creature::updateSlopeFixup(v2);
  v2->mHaventUpdated = 0;
}

// File Line: 1240
// RVA: 0x3B8F30
void __fastcall Creature::updateSlopeFixup(Creature *this)
{
  Creature *v1; // rdi
  __m128 v2; // xmm2
  hkQsTransformf *v3; // rax
  float v4; // xmm3_4
  float v5; // xmm4_4
  float v6; // xmm5_4
  hkVector4f v7; // xmm10
  __m128 v8; // xmm9
  __m128 v9; // xmm11
  float v10; // xmm2_4
  hkQsTransformf newRoot; // [rsp+20h] [rbp-68h]

  v1 = this;
  if ( !this->mLowPowerModeEnabled
    && this->mIsSlopeLocomotionFixupEnabled
    && COERCE_FLOAT(LODWORD(this->mGroundNormal.z) & _xmm) > this->mMaxSlopeLocomotionFixupAngle )
  {
    v2 = (__m128)LODWORD(this->mGroundNormal.x);
    v2.m128_f32[0] = (float)((float)(v2.m128_f32[0] * v2.m128_f32[0])
                           + (float)(this->mGroundNormal.y * this->mGroundNormal.y))
                   + (float)(this->mGroundNormal.z * this->mGroundNormal.z);
    if ( COERCE_FLOAT(_mm_sqrt_ps(v2)) > 0.0099999998 )
    {
      v3 = SkeletalPose::GetRoot(&this->mPose);
      v4 = v1->mGroundNormal.x;
      v5 = v1->mGroundNormal.y;
      v6 = v1->mGroundNormal.z;
      newRoot.m_translation = v3->m_translation;
      v7.m_quad = (__m128)newRoot.m_translation;
      v7.m_quad.m128_f32[0] = newRoot.m_translation.m_quad.m128_f32[0]
                            - v1->mPrevMotion.m_translation.m_quad.m128_f32[0];
      newRoot.m_rotation = v3->m_rotation;
      v8 = _mm_shuffle_ps(newRoot.m_translation.m_quad, newRoot.m_translation.m_quad, 85);
      v9 = _mm_shuffle_ps(newRoot.m_translation.m_quad, newRoot.m_translation.m_quad, 170);
      v8.m128_f32[0] = v8.m128_f32[0] - v1->mPrevMotion.m_translation.m_quad.m128_f32[1];
      v9.m128_f32[0] = v9.m128_f32[0] - v1->mPrevMotion.m_translation.m_quad.m128_f32[2];
      newRoot.m_scale = v3->m_scale;
      v10 = (float)((float)(v7.m_quad.m128_f32[0] * v4) + (float)(v8.m128_f32[0] * v5)) + (float)(v9.m128_f32[0] * v6);
      v7.m_quad.m128_f32[0] = (float)(v7.m_quad.m128_f32[0] - (float)(v4 * v10))
                            + v1->mPrevMotion.m_translation.m_quad.m128_f32[0];
      v8.m128_f32[0] = (float)(v8.m128_f32[0] - (float)(v5 * v10)) + v1->mPrevMotion.m_translation.m_quad.m128_f32[1];
      v9.m128_f32[0] = (float)(v9.m128_f32[0] - (float)(v6 * v10)) + v1->mPrevMotion.m_translation.m_quad.m128_f32[2];
      newRoot.m_translation.m_quad = _mm_unpacklo_ps(
                                       _mm_unpacklo_ps(v7.m_quad, v9),
                                       _mm_unpacklo_ps(v8, (__m128)(unsigned int)FLOAT_1_0));
      SkeletalPose::SetRoot(&v1->mPose, &newRoot, 0);
    }
  }
}

// File Line: 1491
// RVA: 0x3AEF40
void __fastcall Creature::SetBlendTreePlayTime(Creature *this, float timeAbsolute)
{
  PoseNodeParent *v2; // rcx
  Expression::IMemberMapVtbl *v3; // rax
  void **v4; // [rsp+20h] [rbp-28h]
  char v5; // [rsp+28h] [rbp-20h]
  float v6; // [rsp+30h] [rbp-18h]
  int v7; // [rsp+34h] [rbp-14h]
  __int16 v8; // [rsp+38h] [rbp-10h]

  v2 = &this->mBlendTree;
  if ( v2 )
  {
    v4 = &AnimationNode_SetLocalTime::`vftable';
    v3 = v2->vfptr;
    v6 = timeAbsolute;
    v7 = (signed int)FLOAT_1_0;
    v5 = 1;
    v8 = 1;
    v3[1].FindWithOldPath((Expression::IMemberMap *)&v2->vfptr, (const char *)&v4);
  }
}

// File Line: 1504
// RVA: 0x3AED20
void __fastcall Creature::SetAbsoluteRelativeRoot(Creature *this, UFG::qMatrix44 *root)
{
  UFG::qVector4 v2; // xmm3
  UFG::qVector4 v3; // xmm2
  UFG::qVector4 v4; // xmm1

  this->mAbsoluteRelativeRootMotion = 1;
  v2 = root->v1;
  v3 = root->v2;
  v4 = root->v3;
  this->mAbsoluteRelativeRoot.v0 = root->v0;
  this->mAbsoluteRelativeRoot.v1 = v2;
  this->mAbsoluteRelativeRoot.v2 = v3;
  this->mAbsoluteRelativeRoot.v3 = v4;
}

// File Line: 1517
// RVA: 0x3AF8D0
void __fastcall Creature::SetTransformNodeComponentRoot(Creature *this, UFG::TransformNodeComponent *transformNodeRoot)
{
  UFG::EncounterUnitComponent::SetGroupVehicle(&this->mPose, transformNodeRoot);
}

// File Line: 1530
// RVA: 0x3AF8B0
void __fastcall Creature::SetTransform(Creature *this, UFG::qMatrix44 *pos)
{
  SkeletalPose::SetRoot(&this->mPose, pos, 0);
}

// File Line: 1535
// RVA: 0x3AF8E0
void __fastcall Creature::SetTranslation(Creature *this, UFG::qVector3 *pos)
{
  float v2; // xmm1_4
  float v3; // xmm0_4
  float v4; // [rsp+20h] [rbp-18h]
  float v5; // [rsp+24h] [rbp-14h]
  float v6; // [rsp+28h] [rbp-10h]

  v2 = pos->y;
  v4 = pos->x;
  v3 = pos->z;
  v5 = v2;
  v6 = v3;
  SkeletalPose::SetRootTranslation(&this->mPose, (UFG::qVector3 *)&v4, 0);
}

// File Line: 1540
// RVA: 0x3AF650
void __fastcall Creature::SetPositionhkQ(Creature *this, hkQsTransformf *pos)
{
  SkeletalPose::SetRoot(&this->mPose, pos, 0);
}

// File Line: 1545
// RVA: 0x3A96B0
void __fastcall Creature::GetTransform(Creature *this, UFG::qMatrix44 *transform)
{
  SkeletalPose::GetRootMatrix(&this->mPose, transform);
}

// File Line: 1561
// RVA: 0x3A96E0
UFG::qVector3 *__fastcall Creature::GetTranslation(Creature *this, UFG::qVector3 *result, int boneID)
{
  UFG::qVector3 *v3; // rbx

  v3 = result;
  SkeletalPose::GetTranslationWS(&this->mPose, boneID, result);
  return v3;
}

// File Line: 1568
// RVA: 0x3A9710
hkQsTransformf *__fastcall Creature::GetTranslationMS(Creature *this, int boneID)
{
  hkaPose *v2; // r8
  hkQsTransformf *result; // rax

  v2 = this->mPose.mHavokPose;
  if ( v2->m_boneFlags.m_data[boneID] & 2 )
    result = hkaPose::calculateBoneModelSpace(v2, boneID);
  else
    result = &v2->m_modelPose.m_data[boneID];
  return result;
}

// File Line: 1576
// RVA: 0x3A9570
hkQsTransformf *__fastcall Creature::GetPositionhkQ(Creature *this, hkQsTransformf *result)
{
  hkQsTransformf *v2; // rbx
  hkQsTransformf *v3; // rax
  hkQuaternionf v4; // xmm1
  hkVector4f v5; // xmm0
  hkQsTransformf *v6; // rax

  v2 = result;
  v3 = SkeletalPose::GetRoot(&this->mPose);
  v4.m_vec.m_quad = (__m128)v3->m_rotation;
  v2->m_translation = v3->m_translation;
  v5.m_quad = (__m128)v3->m_scale;
  v2->m_rotation = (hkQuaternionf)v4.m_vec.m_quad;
  v6 = v2;
  v2->m_scale = (hkVector4f)v5.m_quad;
  return v6;
}

// File Line: 1581
// RVA: 0x3AF8C0
void __fastcall Creature::SetTransform(Creature *this, int boneID, UFG::qMatrix44 *pos)
{
  SkeletalPose::SetPositionWS(&this->mPose, boneID, pos);
}

// File Line: 1631
// RVA: 0x3A96C0
void __fastcall Creature::GetTransform(Creature *this, int boneID, UFG::qMatrix44 *transform)
{
  SkeletalPose::GetPositionWS(&this->mPose, boneID, transform);
}

// File Line: 1643
// RVA: 0x3A96D0
void __fastcall Creature::GetTransformMS(Creature *this, int boneID, UFG::qMatrix44 *transform)
{
  SkeletalPose::GetPositionMS(&this->mPose, boneID, transform);
}

// File Line: 1669
// RVA: 0x14BD1D0
void dynamic_initializer_for__gUnityNoWVector__()
{
  gUnityNoWVector.m_quad = (__m128)_xmm;
}

// File Line: 1671
// RVA: 0x3A26B0
void __fastcall Creature::Attach(Creature *this, int attachBoneID, int blendedAttachBoneID, UFG::qMatrix44 *matrixWS, const float weight)
{
  UFG::qMatrix44 *v5; // rdi
  int v6; // er15
  int v7; // er14
  Creature *v8; // rbx
  SkeletalPose *v9; // rcx
  UFG::qMatrix44 *v10; // rax
  UFG::qVector4 v11; // xmm1
  UFG::qVector4 v12; // xmm0
  UFG::qVector4 v13; // xmm1
  UFG::qMatrix44 *v14; // r8
  float v15; // xmm3_4
  UFG::qMatrix44 sourceA; // [rsp+20h] [rbp-E0h]
  UFG::qMatrix44 d; // [rsp+60h] [rbp-A0h]
  UFG::qMatrix44 b; // [rsp+A0h] [rbp-60h]
  UFG::qMatrix44 v19; // [rsp+E0h] [rbp-20h]
  UFG::qMatrix44 matrixWSa; // [rsp+120h] [rbp+20h]
  UFG::qMatrix44 result; // [rsp+160h] [rbp+60h]

  v5 = matrixWS;
  v6 = blendedAttachBoneID;
  v7 = attachBoneID;
  v8 = this;
  if ( !Creature::IsEndEffector(this, attachBoneID) )
  {
    v9 = &v8->mPose;
    if ( v6 < 0 )
    {
      SkeletalPose::GetPositionWS(v9, v7, &sourceA);
      v14 = v5;
      v15 = weight;
      if ( weight < 1.0 )
      {
LABEL_7:
        BlendSlerp(&d, &sourceA, v14, v15);
        v14 = &d;
        goto LABEL_8;
      }
    }
    else
    {
      SkeletalPose::GetPositionWS(v9, v7, &matrixWSa);
      UFG::qInverseAffine(&d, &matrixWSa);
      v10 = UFG::qMatrix44::operator*(&d, &result, v5);
      v11 = v10->v1;
      b.v0 = v10->v0;
      v12 = v10->v2;
      b.v1 = v11;
      v13 = v10->v3;
      b.v2 = v12;
      b.v3 = v13;
      SkeletalPose::GetPositionWS(&v8->mPose, v6, &sourceA);
      UFG::qMatrix44::operator*(&sourceA, &v19, &b);
      v14 = &v19;
      v15 = weight;
      if ( weight < 1.0 )
        goto LABEL_7;
    }
LABEL_8:
    AttachPose(&v8->mPose, &sourceA, v14);
    goto LABEL_9;
  }
  Creature::SetEndEffectorTarget(v8, v7, v5);
LABEL_9:
  Creature::UpdateAttachmentPoses(v8);
}

// File Line: 1797
// RVA: 0x3A2510
void __fastcall Creature::Attach(Creature *this, int attachBoneID, UFG::qVector3 *position, const float weight)
{
  UFG::qVector3 *v4; // rdi
  int v5; // ebp
  Creature *v6; // rbx
  float v7; // xmm6_4
  float v8; // xmm7_4
  float v9; // xmm8_4
  float v10; // xmm6_4
  float v11; // xmm7_4
  float v12; // xmm8_4
  hkQsTransformf *v13; // rax
  float v14; // xmm1_4
  float v15; // xmm2_4
  Render::DebugDrawContext *v16; // rax
  UFG::qVector3 translationWS; // [rsp+20h] [rbp-A8h]
  float v18; // [rsp+30h] [rbp-98h]
  float v19; // [rsp+34h] [rbp-94h]
  float v20; // [rsp+38h] [rbp-90h]
  UFG::qMatrix44 matrixRoot; // [rsp+40h] [rbp-88h]

  v4 = position;
  v5 = attachBoneID;
  v6 = this;
  if ( !Creature::IsEndEffector(this, attachBoneID) )
  {
    SkeletalPose::GetTranslationWS(&v6->mPose, v5, &translationWS);
    v7 = v4->x;
    v8 = v4->y;
    v9 = v4->z;
    if ( weight < 1.0 )
    {
      v7 = (float)((float)(v7 - translationWS.x) * weight) + translationWS.x;
      v8 = (float)((float)(v8 - translationWS.y) * weight) + translationWS.y;
      v9 = (float)((float)(v9 - translationWS.z) * weight) + translationWS.z;
    }
    v10 = v7 - translationWS.x;
    v11 = v8 - translationWS.y;
    v12 = v9 - translationWS.z;
    v13 = SkeletalPose::GetRoot(&v6->mPose);
    v14 = v13->m_translation.m_quad.m128_f32[1] + v11;
    v15 = v13->m_translation.m_quad.m128_f32[2] + v12;
    v18 = v13->m_translation.m_quad.m128_f32[0] + v10;
    v19 = v14;
    v20 = v15;
    SkeletalPose::SetRootTranslation(&v6->mPose, (UFG::qVector3 *)&v18, 0);
    if ( gSkeletonDebug )
    {
      SkeletalPose::GetRootMatrix(&v6->mPose, &matrixRoot);
      v16 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
      Render::DebugDrawContext::DrawCoord(v16, &matrixRoot, 0.5, 0i64);
    }
  }
  Creature::UpdateAttachmentPoses(v6);
}

// File Line: 1922
// RVA: 0x3AF320
void __fastcall Creature::SetGroundProperties(Creature *this, UFG::GroundProperties *p)
{
  float v2; // xmm0_4
  float v3; // xmm1_4

  v2 = p->groundNormal.y;
  v3 = p->groundNormal.z;
  this->mGroundNormal.x = p->groundNormal.x;
  this->mGroundNormal.y = v2;
  this->mGroundNormal.z = v3;
}

// File Line: 1930
// RVA: 0x3B8A40
void __fastcall Creature::updateAttachments(Creature *this, float timedelta)
{
  char *v2; // rsi
  Creature *v3; // rbx
  signed __int64 v4; // rdi

  v2 = (char *)&this->mGroundNormal.z;
  v3 = (Creature *)&this->mAttachments.mNode.mNext[-1].mNext;
  if ( v3 != (Creature *)&this->mGroundNormal.z )
  {
    do
    {
      v4 = (signed __int64)&v3->m_SafePointerList.mNode.mNext[-1].mNext;
      ((void (__fastcall *)(Creature *))v3->vfptr[1].__vecDelDtor)(v3);
      if ( !v3->mPrevMotion.m_scale.m_quad.m128_u64[1] )
        v3->vfptr->__vecDelDtor((UFG::qSafePointerNode<Creature> *)&v3->vfptr, 1u);
      v3 = (Creature *)v4;
    }
    while ( (char *)v4 != v2 );
  }
}

// File Line: 1951
// RVA: 0x3B1540
void __fastcall Creature::UpdateAttachmentPoses(Creature *this)
{
  Creature *v1; // rdi
  UFG::qNode<Attachment,Attachment> *v2; // rbx
  signed __int64 v3; // rdi
  UFG::qNode<Attachment,Attachment> **i; // rbx
  UFG::qColour v5; // [rsp+20h] [rbp-18h]

  v1 = this;
  if ( gAttachDebug )
  {
    v5 = UFG::qColour::Blue;
    SkeletalPose::DebugDraw(&this->mPose, &v5, 1.0);
  }
  v2 = v1->mAttachments.mNode.mNext;
  v3 = (signed __int64)&v1->mGroundNormal.z;
  for ( i = &v2[-1].mNext; i != (UFG::qNode<Attachment,Attachment> **)v3; i = &i[2][-1].mNext )
  {
    ((void (__fastcall *)(UFG::qNode<Attachment,Attachment> **))(*i)[1].mPrev)(i);
    if ( gAttachDebug )
      ((void (__fastcall *)(UFG::qNode<Attachment,Attachment> **))(*i)[2].mPrev)(i);
  }
}

// File Line: 1971
// RVA: 0x3B15D0
void __fastcall Creature::UpdateAttachmentPostPhysics(Creature *this)
{
  Creature *v1; // rdi
  UFG::qNode<Attachment,Attachment> *v2; // rbx
  signed __int64 v3; // rdi
  UFG::qNode<Attachment,Attachment> **i; // rbx
  UFG::qColour v5; // [rsp+20h] [rbp-18h]

  v1 = this;
  Creature::updateEffectorsToPosePostPhysics(this);
  if ( sAttachPosePhy )
  {
    v5 = UFG::qColour::Pink;
    SkeletalPose::DebugDraw(&v1->mPose, &v5, 1.0);
  }
  v2 = v1->mAttachments.mNode.mNext;
  v3 = (signed __int64)&v1->mGroundNormal.z;
  for ( i = &v2[-1].mNext; i != (UFG::qNode<Attachment,Attachment> **)v3; i = &i[2][-1].mNext )
  {
    ((void (__fastcall *)(UFG::qNode<Attachment,Attachment> **))(*i)[1].mPrev)(i);
    ((void (__fastcall *)(UFG::qNode<Attachment,Attachment> **))(*i)[1].mNext)(i);
  }
}

// File Line: 2020
// RVA: 0x3A0B80
UFG::qNode<Attachment,Attachment> **__fastcall Creature::AddAttachment(Creature *this, Attachment *attachment)
{
  Attachment *v2; // r10
  UFG::SimObject *v3; // r8
  UFG::qNode<Attachment,Attachment> **result; // rax
  Creature *v5; // rdx
  UFG::qNode<Attachment,Attachment> *v6; // rcx
  UFG::qList<Attachment,Attachment,1,0> *v7; // rdx
  UFG::qNode<Attachment,Attachment> *v8; // rax

  v2 = attachment;
  v3 = attachment->mAttachedSimObject.m_pPointer;
  result = &this->mAttachments.mNode.mNext[-1].mNext;
  v5 = this;
  if ( result == (UFG::qNode<Attachment,Attachment> **)&this->mGroundNormal.z )
    goto LABEL_6;
  while ( result[13] != (UFG::qNode<Attachment,Attachment> *)v3 )
  {
    result = &result[2][-1].mNext;
    if ( result == (UFG::qNode<Attachment,Attachment> **)&this->mGroundNormal.z )
      goto LABEL_6;
  }
  if ( *((_DWORD *)result + 8) != v2->attachedJoint )
  {
LABEL_6:
    v6 = (UFG::qNode<Attachment,Attachment> *)&v2->mPrev;
    v7 = &v5->mAttachments;
    v8 = v7->mNode.mPrev;
    v8->mNext = (UFG::qNode<Attachment,Attachment> *)&v2->mPrev;
    v6->mPrev = v8;
    v6->mNext = &v7->mNode;
    v7->mNode.mPrev = (UFG::qNode<Attachment,Attachment> *)&v2->mPrev;
    result = (UFG::qNode<Attachment,Attachment> **)v2;
  }
  return result;
}

// File Line: 2035
// RVA: 0x3A0BE0
UFG::qNode<Attachment,Attachment> **__fastcall Creature::AddAttachment(Creature *this, UFG::SimObject *self, int attachBoneID, UFG::SimObject *attachedSimObject, int attachmentBoneID, bool positionOnly, float blendIn)
{
  UFG::SimObjectGame *v7; // rbx
  int v8; // er15
  UFG::SimObject *v9; // rbp
  UFG::SimComponent *v10; // r14
  UFG::qNode<Attachment,Attachment> **result; // rax
  __int64 v12; // rsi
  unsigned __int16 v13; // cx
  UFG::CharacterAnimationComponent *v14; // rax
  UFG::CharacterAnimationComponent *v15; // rdi
  Creature *v16; // rdx
  signed __int64 v17; // rcx
  signed __int64 v18; // rdx
  UFG::allocator::free_link *v19; // rax
  __int64 v20; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> **v21; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v22; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v23; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v24; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v25; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v26; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v27; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v28; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v29; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v30; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v31; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v32; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v33; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v34; // rax
  bool v35; // zf
  Creature *v36; // rax
  unsigned __int16 v37; // cx
  UFG::SimComponent *v38; // rax
  UFG::allocator::free_link *v39; // rax
  __int64 v40; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> **v41; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v42; // rax
  unsigned __int16 v43; // cx
  UFG::SimComponent *v44; // rax
  UFG::RigidBody *v45; // rdi

  v7 = (UFG::SimObjectGame *)attachedSimObject;
  v8 = attachBoneID;
  v9 = self;
  v10 = (UFG::SimComponent *)this;
  if ( attachBoneID == -1 || attachmentBoneID == -1 )
    return 0i64;
  result = &this->mAttachments.mNode.mNext[-1].mNext;
  if ( result == (UFG::qNode<Attachment,Attachment> **)&this->mGroundNormal.z )
    goto LABEL_8;
  while ( result[13] != (UFG::qNode<Attachment,Attachment> *)attachedSimObject )
  {
    result = &result[2][-1].mNext;
    if ( result == (UFG::qNode<Attachment,Attachment> **)&this->mGroundNormal.z )
      goto LABEL_8;
  }
  if ( *((_DWORD *)result + 8) != attachBoneID )
  {
LABEL_8:
    v12 = 0i64;
    if ( attachedSimObject )
    {
      v13 = attachedSimObject->m_Flags;
      if ( (v13 >> 14) & 1 )
      {
        v14 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectCVBase *)attachedSimObject);
      }
      else if ( (v13 & 0x8000u) == 0 )
      {
        if ( (v13 >> 13) & 1 )
        {
          v14 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)attachedSimObject);
        }
        else if ( (v13 >> 12) & 1 )
        {
          v14 = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      (UFG::SimObjectGame *)attachedSimObject,
                                                      UFG::CharacterAnimationComponent::_TypeUID);
        }
        else
        {
          v14 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                      attachedSimObject,
                                                      UFG::CharacterAnimationComponent::_TypeUID);
        }
      }
      else
      {
        v14 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectCVBase *)attachedSimObject);
      }
      v15 = v14;
      if ( v14 )
      {
        v16 = v14->mCreature;
        v17 = (signed __int64)&v16->mAttachments.mNode.mNext[-1].mNext;
        if ( (Creature *)v17 != (Creature *)&v16->mGroundNormal.z )
        {
          v18 = (signed __int64)&v16->mGroundNormal.z;
          while ( *(UFG::SimObject **)(v17 + 104) != v9 )
          {
            v17 = *(_QWORD *)(v17 + 16) - 8i64;
            if ( v17 == v18 )
              goto LABEL_23;
          }
          return 0i64;
        }
LABEL_23:
        v19 = UFG::qMalloc(0xF0ui64, "Creature.AttachmentCreature", 0i64);
        if ( v19 )
        {
          AttachmentCreature::AttachmentCreature((AttachmentCreature *)v19);
          v12 = v20;
        }
        else
        {
          v12 = 0i64;
        }
        v21 = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> **)(v12 + 8);
        v22 = v10[2].m_BoundComponentHandles.mNode.mPrev;
        v22->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)(v12 + 8);
        *v21 = v22;
        v21[1] = &v10[2].m_BoundComponentHandles.mNode;
        v10[2].m_BoundComponentHandles.mNode.mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)(v12 + 8);
        *(_DWORD *)(v12 + 32) = v8;
        v23 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)(v12 + 64);
        if ( *(_QWORD *)(v12 + 80) )
        {
          v24 = v23->mPrev;
          v25 = *(UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **)(v12 + 72);
          v24->mNext = v25;
          v25->mPrev = v24;
          v23->mPrev = v23;
          *(_QWORD *)(v12 + 72) = v12 + 64;
        }
        *(_QWORD *)(v12 + 80) = v10;
        v26 = v10->m_SafePointerList.mNode.mPrev;
        v26->mNext = v23;
        v23->mPrev = v26;
        *(_QWORD *)(v12 + 72) = (char *)v10 + 8;
        v10->m_SafePointerList.mNode.mPrev = v23;
        v27 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)(v12 + 88);
        if ( *(_QWORD *)(v12 + 104) )
        {
          v28 = v27->mPrev;
          v29 = *(UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> **)(v12 + 96);
          v28->mNext = v29;
          v29->mPrev = v28;
          v27->mPrev = v27;
          *(_QWORD *)(v12 + 96) = v12 + 88;
        }
        *(_QWORD *)(v12 + 104) = v7;
        v30 = v7->m_SafePointerList.mNode.mPrev;
        v30->mNext = v27;
        v27->mPrev = v30;
        *(_QWORD *)(v12 + 96) = (char *)v7 + 8;
        v7->m_SafePointerList.mNode.mPrev = v27;
        *(_WORD *)(v12 + 26) = 0;
        if ( blendIn > 0.0 )
        {
          *(float *)(v12 + 188) = 1.0 / blendIn;
          *(_DWORD *)(v12 + 192) = 0;
        }
        else
        {
          *(_DWORD *)(v12 + 188) = 1065353216;
          *(_DWORD *)(v12 + 192) = 1065353216;
        }
        *(_BYTE *)(v12 + 24) = positionOnly;
        *(_DWORD *)(v12 + 208) = attachmentBoneID;
        v31 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)(v12 + 216);
        if ( *(_QWORD *)(v12 + 232) )
        {
          v32 = v31->mPrev;
          v33 = *(UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **)(v12 + 224);
          v32->mNext = v33;
          v33->mPrev = v32;
          v31->mPrev = v31;
          *(_QWORD *)(v12 + 224) = v12 + 216;
        }
        *(_QWORD *)(v12 + 232) = v15;
        v34 = v15->m_SafePointerList.mNode.mPrev;
        v34->mNext = v31;
        v31->mPrev = v34;
        *(_QWORD *)(v12 + 224) = (char *)v15 + 8;
        v15->m_SafePointerList.mNode.mPrev = v31;
        v35 = Creature::IsEndEffector(v15->mCreature, attachmentBoneID) == 0;
        v36 = v15->mCreature;
        v36->mIsAttached = v35 != 0;
      }
      else
      {
        v37 = v7->m_Flags;
        if ( (v37 >> 14) & 1 )
        {
          v38 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RigidBodyComponent::_TypeUID);
        }
        else if ( (v37 & 0x8000u) == 0 )
        {
          if ( (v37 >> 13) & 1 )
          {
            v38 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RigidBodyComponent::_TypeUID);
          }
          else if ( (v37 >> 12) & 1 )
          {
            v38 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RigidBodyComponent::_TypeUID);
          }
          else
          {
            v38 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::RigidBodyComponent::_TypeUID);
          }
        }
        else
        {
          v38 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RigidBodyComponent::_TypeUID);
        }
        if ( v38 )
        {
          v39 = UFG::qMalloc(0xD0ui64, "Creature.AttachmentRigidBody", 0i64);
          if ( v39 )
          {
            AttachmentRigidBody::AttachmentRigidBody((AttachmentRigidBody *)v39);
            v12 = v40;
          }
          else
          {
            v12 = 0i64;
          }
          v41 = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> **)(v12 + 8);
          v42 = v10[2].m_BoundComponentHandles.mNode.mPrev;
          v42->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)(v12 + 8);
          *v41 = v42;
          v41[1] = &v10[2].m_BoundComponentHandles.mNode;
          v10[2].m_BoundComponentHandles.mNode.mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)(v12 + 8);
          *(_DWORD *)(v12 + 32) = v8;
          UFG::qSafePointer<Creature,Creature>::operator=(
            (UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *)(v12 + 64),
            v10);
          UFG::qSafePointer<Creature,Creature>::operator=(
            (UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *)(v12 + 88),
            (UFG::SimComponent *)v7);
          *(_BYTE *)(v12 + 26) = 0;
        }
      }
      v43 = v7->m_Flags;
      if ( (v43 >> 14) & 1 )
      {
        v44 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RigidBodyComponent::_TypeUID);
      }
      else if ( (v43 & 0x8000u) == 0 )
      {
        if ( (v43 >> 13) & 1 )
        {
          v44 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RigidBodyComponent::_TypeUID);
        }
        else if ( (v43 >> 12) & 1 )
        {
          v44 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RigidBodyComponent::_TypeUID);
        }
        else
        {
          v44 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::RigidBodyComponent::_TypeUID);
        }
      }
      else
      {
        v44 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RigidBodyComponent::_TypeUID);
      }
      v45 = (UFG::RigidBody *)v44;
      if ( v44 )
      {
        do
        {
          UFG::RigidBody::SetMotionType(v45, 0x100u);
          v45 = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(
                                    (UFG::SimObject *)&v7->vfptr,
                                    UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                                    0,
                                    (UFG::SimComponent *)&v45->vfptr);
        }
        while ( v45 );
      }
    }
    result = (UFG::qNode<Attachment,Attachment> **)v12;
  }
  return result;
}

// File Line: 2164
// RVA: 0x3A1300
UFG::qNode<Attachment,Attachment> **__fastcall Creature::AddAttachmentRelative(Creature *this, UFG::SimObject *self, int attachBoneID, UFG::SimObject *attachedSimObject, int attachmentBoneID, UFG::qMatrix44 *relativePositionWS, float blendIn)
{
  int v7; // edi
  Creature *v8; // rsi
  UFG::qNode<Attachment,Attachment> **v9; // rax
  UFG::qNode<Attachment,Attachment> **v10; // rbx
  UFG::qMatrix44 *v11; // rax
  UFG::qVector4 v12; // xmm3
  UFG::qVector4 v13; // xmm2
  UFG::qVector4 v14; // xmm1
  UFG::qMatrix44 d; // [rsp+40h] [rbp-C8h]
  UFG::qMatrix44 matrixWS; // [rsp+80h] [rbp-88h]
  UFG::qMatrix44 result; // [rsp+C0h] [rbp-48h]

  v7 = attachBoneID;
  v8 = this;
  v9 = Creature::AddAttachment(this, self, attachBoneID, attachedSimObject, attachmentBoneID, 0, blendIn);
  v10 = v9;
  if ( v9 )
  {
    *((_BYTE *)v9 + 26) = 1;
    SkeletalPose::GetPositionWS(&v8->mPose, v7, &matrixWS);
    UFG::qInverseAffine(&d, &matrixWS);
    v11 = UFG::qMatrix44::operator*(relativePositionWS, &result, &d);
    v12 = v11->v1;
    v13 = v11->v2;
    v14 = v11->v3;
    *((_OWORD *)v10 + 7) = v11->v0;
    *((UFG::qVector4 *)v10 + 8) = v12;
    v9 = v10;
    *((UFG::qVector4 *)v10 + 9) = v13;
    *((UFG::qVector4 *)v10 + 10) = v14;
  }
  return v9;
}

// File Line: 2186
// RVA: 0x3A1470
void __fastcall Creature::AddRelativeTransform(Creature *this, int attachBoneID, UFG::SimObject *attachedSimObject, int attachmentBoneID, UFG::qMatrix44 *relativeTransform)
{
  UFG::qNode<Attachment,Attachment> *v5; // rax
  char *v6; // rcx
  signed __int64 v7; // rax
  UFG::qVector4 v8; // xmm3
  UFG::qVector4 v9; // xmm2
  UFG::qVector4 v10; // xmm1

  v5 = this->mAttachments.mNode.mNext;
  v6 = (char *)&this->mGroundNormal.z;
  v7 = (signed __int64)&v5[-1].mNext;
  if ( (char *)v7 != v6 )
  {
    while ( *(UFG::SimObject **)(v7 + 104) != attachedSimObject )
    {
      v7 = *(_QWORD *)(v7 + 16) - 8i64;
      if ( (char *)v7 == v6 )
        return;
    }
    if ( *(_DWORD *)(v7 + 32) == attachBoneID )
    {
      *(_BYTE *)(v7 + 26) = 1;
      v8 = relativeTransform->v1;
      v9 = relativeTransform->v2;
      v10 = relativeTransform->v3;
      *(UFG::qVector4 *)(v7 + 112) = relativeTransform->v0;
      *(UFG::qVector4 *)(v7 + 128) = v8;
      *(UFG::qVector4 *)(v7 + 144) = v9;
      *(UFG::qVector4 *)(v7 + 160) = v10;
    }
  }
}

// File Line: 2197
// RVA: 0x3A1400
void __fastcall Creature::AddRelativeScale(Creature *this, int attachBoneID, UFG::SimObject *attachedSimObject, int attachmentBoneID, UFG::qVector3 *relativeScale)
{
  UFG::qNode<Attachment,Attachment> *v5; // r9
  char *v6; // rcx
  signed __int64 v7; // r9
  float v8; // xmm0_4
  float v9; // xmm1_4

  v5 = this->mAttachments.mNode.mNext;
  v6 = (char *)&this->mGroundNormal.z;
  v7 = (signed __int64)&v5[-1].mNext;
  if ( (char *)v7 != v6 )
  {
    while ( *(UFG::SimObject **)(v7 + 104) != attachedSimObject )
    {
      v7 = *(_QWORD *)(v7 + 16) - 8i64;
      if ( (char *)v7 == v6 )
        return;
    }
    if ( *(_DWORD *)(v7 + 32) == attachBoneID )
    {
      *(_BYTE *)(v7 + 27) = 1;
      v8 = relativeScale->y;
      v9 = relativeScale->z;
      *(float *)(v7 + 176) = relativeScale->x;
      *(float *)(v7 + 180) = v8;
      *(float *)(v7 + 184) = v9;
    }
  }
}

// File Line: 2210
// RVA: 0x3A1030
Attachment *__fastcall Creature::AddAttachmentParkour(Creature *this, UFG::SimObject *attachedToParkourObject, int attachBoneID, UFG::SimObject *attachedSimObject, UFG::ParkourHandle *parkourHandle, float blendIn)
{
  UFG::SimObject *v6; // rsi
  int v7; // er15
  UFG::SimObject *v8; // rbp
  Creature *v9; // r14
  __int64 v10; // rbx
  unsigned __int16 v12; // cx
  UFG::CharacterAnimationComponent *v13; // rax
  UFG::CharacterAnimationComponent *v14; // rdi
  UFG::allocator::free_link *v15; // rax
  __int64 v16; // rax
  UFG::qNode<Attachment,Attachment> **v17; // rcx
  UFG::qNode<Attachment,Attachment> *v18; // rax
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v19; // rdx
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v20; // rcx
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v21; // rax
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v22; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v23; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v24; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v25; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v26; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v27; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v28; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v29; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v30; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v31; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v32; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v33; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v34; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v35; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v36; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v37; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v38; // rax

  v6 = attachedSimObject;
  v7 = attachBoneID;
  v8 = attachedToParkourObject;
  v9 = this;
  v10 = 0i64;
  if ( attachBoneID == -1 )
    return 0i64;
  if ( attachedSimObject )
  {
    v12 = attachedSimObject->m_Flags;
    if ( (v12 >> 14) & 1 )
    {
      v13 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectCVBase *)attachedSimObject);
    }
    else if ( (v12 & 0x8000u) == 0 )
    {
      if ( (v12 >> 13) & 1 )
        v13 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)attachedSimObject);
      else
        v13 = (UFG::CharacterAnimationComponent *)((v12 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                       (UFG::SimObjectGame *)attachedSimObject,
                                                                       UFG::CharacterAnimationComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(attachedSimObject, UFG::CharacterAnimationComponent::_TypeUID));
    }
    else
    {
      v13 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectCVBase *)attachedSimObject);
    }
    v14 = v13;
    if ( v13 )
    {
      v15 = UFG::qMalloc(0x160ui64, "Creature.AttachmentCreatureToHandle", 0i64);
      if ( v15 )
      {
        AttachmentCreatureToHandle::AttachmentCreatureToHandle((AttachmentCreatureToHandle *)v15);
        v10 = v16;
      }
      else
      {
        v10 = 0i64;
      }
      v17 = (UFG::qNode<Attachment,Attachment> **)(v10 + 8);
      v18 = v9->mAttachments.mNode.mPrev;
      v18->mNext = (UFG::qNode<Attachment,Attachment> *)(v10 + 8);
      *v17 = v18;
      v17[1] = &v9->mAttachments.mNode;
      v9->mAttachments.mNode.mPrev = (UFG::qNode<Attachment,Attachment> *)(v10 + 8);
      *(_DWORD *)(v10 + 32) = v7;
      v19 = (UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *)(v10 + 64);
      if ( *(_QWORD *)(v10 + 80) )
      {
        v20 = v19->mPrev;
        v21 = *(UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> **)(v10 + 72);
        v20->mNext = v21;
        v21->mPrev = v20;
        v19->mPrev = v19;
        *(_QWORD *)(v10 + 72) = v10 + 64;
      }
      *(_QWORD *)(v10 + 80) = v9;
      v22 = v9->m_SafePointerList.mNode.mPrev;
      v22->mNext = v19;
      v19->mPrev = v22;
      *(_QWORD *)(v10 + 72) = (char *)v9 + 8;
      v9->m_SafePointerList.mNode.mPrev = v19;
      v23 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)(v10 + 88);
      if ( *(_QWORD *)(v10 + 104) )
      {
        v24 = v23->mPrev;
        v25 = *(UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> **)(v10 + 96);
        v24->mNext = v25;
        v25->mPrev = v24;
        v23->mPrev = v23;
        *(_QWORD *)(v10 + 96) = v10 + 88;
      }
      *(_QWORD *)(v10 + 104) = v6;
      v26 = v6->m_SafePointerList.mNode.mPrev;
      v26->mNext = v23;
      v23->mPrev = v26;
      *(_QWORD *)(v10 + 96) = (char *)v6 + 8;
      v6->m_SafePointerList.mNode.mPrev = v23;
      *(_BYTE *)(v10 + 26) = 0;
      if ( blendIn > 0.0 )
      {
        *(float *)(v10 + 188) = 1.0 / blendIn;
        *(_DWORD *)(v10 + 192) = 0;
      }
      else
      {
        *(_DWORD *)(v10 + 188) = 1065353216;
        *(_DWORD *)(v10 + 192) = 1065353216;
      }
      v27 = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)(v10 + 208);
      if ( *(_QWORD *)(v10 + 224) )
      {
        v28 = v27->mPrev;
        v29 = *(UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> **)(v10 + 216);
        v28->mNext = v29;
        v29->mPrev = v28;
        v27->mPrev = v27;
        *(_QWORD *)(v10 + 216) = v10 + 208;
      }
      *(_QWORD *)(v10 + 224) = parkourHandle;
      if ( parkourHandle )
      {
        v30 = parkourHandle->m_SafePointerList.mNode.mPrev;
        v30->mNext = v27;
        v27->mPrev = v30;
        *(_QWORD *)(v10 + 216) = (char *)parkourHandle + 8;
        parkourHandle->m_SafePointerList.mNode.mPrev = v27;
      }
      v31 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)(v10 + 232);
      if ( *(_QWORD *)(v10 + 248) )
      {
        v32 = v31->mPrev;
        v33 = *(UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> **)(v10 + 240);
        v32->mNext = v33;
        v33->mPrev = v32;
        v31->mPrev = v31;
        *(_QWORD *)(v10 + 240) = v10 + 232;
      }
      *(_QWORD *)(v10 + 248) = v8;
      if ( v8 )
      {
        v34 = v8->m_SafePointerList.mNode.mPrev;
        v34->mNext = v31;
        v31->mPrev = v34;
        *(_QWORD *)(v10 + 240) = (char *)v8 + 8;
        v8->m_SafePointerList.mNode.mPrev = v31;
      }
      v35 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)(v10 + 256);
      if ( *(_QWORD *)(v10 + 272) )
      {
        v36 = v35->mPrev;
        v37 = *(UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **)(v10 + 264);
        v36->mNext = v37;
        v37->mPrev = v36;
        v35->mPrev = v35;
        *(_QWORD *)(v10 + 264) = v10 + 256;
      }
      *(_QWORD *)(v10 + 272) = v14;
      v38 = v14->m_SafePointerList.mNode.mPrev;
      v38->mNext = v35;
      v35->mPrev = v38;
      *(_QWORD *)(v10 + 264) = (char *)v14 + 8;
      v14->m_SafePointerList.mNode.mPrev = v35;
      v14->mCreature->mIsAttached = !Creature::IsEndEffector(v14->mCreature, v7);
    }
  }
  return (Attachment *)v10;
}re->mIsAttached = !Creature::IsEndEffector(v14->mCreature, v7);
    }
  }
  return (Attachment *)v10;
}

// File Line: 2287
// RVA: 0x3ADFB0
char __fastcall Creature::RemoveAttachment(Creature *this, UFG::SimObject *self, int attachBoneID, UFG::SimObject *attachedSimObject)
{
  UFG::qNode<Attachment,Attachment> *v4; // rbx
  Attachment *v5; // rcx
  Attachment *v6; // rbx
  UFG::qNode<Attachment,Attachment> *v8; // rcx
  UFG::qNode<Attachment,Attachment> *v9; // rax
  UFG::qNode<Attachment,Attachment> *v10; // rdx

  v4 = this->mAttachments.mNode.mNext;
  v5 = (Attachment *)&this->mGroundNormal.z;
  v6 = (Attachment *)&v4[-1].mNext;
  if ( v6 == v5 )
    return 0;
  while ( v6->mAttachedSimObject.m_pPointer != attachedSimObject && attachedSimObject
       || v6->attachedJoint != attachBoneID )
  {
    v6 = (Attachment *)&v6->mNext[-1].mNext;
    if ( v6 == v5 )
      return 0;
  }
  ((void (__fastcall *)(Attachment *, UFG::SimObject *))v6->vfptr->OnRemove)(v6, self);
  v8 = v6->mPrev;
  v9 = v6->mNext;
  v10 = (UFG::qNode<Attachment,Attachment> *)&v6->mPrev;
  v8->mNext = v9;
  v9->mPrev = v8;
  v10->mPrev = v10;
  v10->mNext = v10;
  v6->vfptr->__vecDelDtor(v6, 1u);
  return 1;
}

// File Line: 2330
// RVA: 0x3AC190
void __fastcall AttachmentCreature::OnRemove(AttachmentCreature *this)
{
  AttachmentCreature *v1; // rdi
  Creature *v2; // rsi
  UFG::qNode<PoseDriver,PoseDriver> *v3; // rbx
  signed __int64 v4; // rsi
  UFG::qNode<PoseDriver,PoseDriver> *i; // rbx
  UFG::SimObjectGame *v6; // rdi
  unsigned __int16 v7; // cx
  UFG::SimComponent *v8; // rax
  UFG::RigidBody *v9; // rbx

  v1 = this;
  if ( this->mAttachedSimObject.m_pPointer )
  {
    v2 = *(Creature **)&this->mAttachedCharacterAnimationComponent.m_pPointer[2].m_TypeUID;
    v2->mIsAttached = 0;
    if ( Creature::IsEndEffector(v2, this->attachedJoint) )
    {
      v3 = v2->mPoseDrivers.mNode.mNext;
      v4 = (signed __int64)&v2->m_SafePointerList;
      for ( i = v3 - 1; i != (UFG::qNode<PoseDriver,PoseDriver> *)v4; i = i[1].mNext - 1 )
      {
        if ( ((unsigned int (__fastcall *)(UFG::qNode<PoseDriver,PoseDriver> *))i->mPrev[7].mPrev)(i) == v1->attachedJoint )
          ((void (__fastcall *)(UFG::qNode<PoseDriver,PoseDriver> *, _QWORD))i->mPrev[5].mNext)(i, 0i64);
      }
    }
    else
    {
      v6 = (UFG::SimObjectGame *)v1->mAttachedSimObject.m_pPointer;
      if ( v6 )
      {
        v7 = v6->m_Flags;
        if ( (v7 >> 14) & 1 )
        {
          v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::RigidBodyComponent::_TypeUID);
        }
        else if ( (v7 & 0x8000u) == 0 )
        {
          if ( (v7 >> 13) & 1 )
            v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::RigidBodyComponent::_TypeUID);
          else
            v8 = (v7 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::RigidBodyComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v6->vfptr, UFG::RigidBodyComponent::_TypeUID);
        }
        else
        {
          v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::RigidBodyComponent::_TypeUID);
        }
        v9 = (UFG::RigidBody *)v8;
        if ( v8 )
        {
          do
          {
            UFG::RigidBody::SetMotionType(v9, 0x80u);
            v9 = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(
                                     (UFG::SimObject *)&v6->vfptr,
                                     UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                                     0,
                                     (UFG::SimComponent *)&v9->vfptr);
          }
          while ( v9 );
        }
      }
    }
  }
}

// File Line: 2368
// RVA: 0x3B0200
char __fastcall Creature::TransferAttachment(Creature *this, int sourceBoneID, int destsourceBoneID, UFG::qSymbolUC *attachmentBone)
{
  UFG::qNode<Attachment,Attachment> **v4; // rdi
  char result; // al
  UFG::qNode<Attachment,Attachment> **v6; // rbx
  UFG::qSymbolUC *v7; // rsi
  int v8; // ebp
  int v9; // er14
  UFG::qNode<Attachment,Attachment> *v10; // rax
  UFG::qNode<Attachment,Attachment> *v11; // rcx
  signed int v12; // eax

  v4 = (UFG::qNode<Attachment,Attachment> **)&this->mGroundNormal.z;
  result = 0;
  v6 = &this->mAttachments.mNode.mNext[-1].mNext;
  v7 = attachmentBone;
  v8 = destsourceBoneID;
  v9 = sourceBoneID;
  if ( v6 != (UFG::qNode<Attachment,Attachment> **)&this->mGroundNormal.z )
  {
    do
    {
      if ( *((_DWORD *)v6 + 8) == v9 )
      {
        *((_DWORD *)v6 + 8) = v8;
        if ( v7->mUID != gStaticSymbolUC_none.mUID )
        {
          if ( v6[10] )
          {
            v10 = v6[29];
            if ( v10 )
            {
              v11 = v10[9].mNext;
              if ( v11[27].mNext )
                v12 = Skeleton::GetBoneID((Skeleton *)v11[30].mPrev, v7->mUID);
              else
                v12 = -1;
              *((_DWORD *)v6 + 52) = v12;
            }
          }
        }
        result = 1;
      }
      v6 = &v6[2][-1].mNext;
    }
    while ( v6 != v4 );
  }
  return result;
}

// File Line: 2400
// RVA: 0x3A95B0
void __fastcall Creature::GetResourceSystemAttachments(Creature *this, UFG::qArray<UFG::qSymbol,0> *nameList)
{
  Creature *v2; // rdi
  UFG::qArray<UFG::qSymbol,0> *v3; // rsi
  Creature *v4; // rbx
  UFG::SimObjectGame *v5; // rcx
  unsigned __int16 v6; // dx
  UFG::SimComponent *v7; // rax
  UFG::qSymbol *v8; // rax

  v2 = (Creature *)((char *)this + 168);
  v3 = nameList;
  v4 = (Creature *)&this->mAttachments.mNode.mNext[-1].mNext;
  if ( v4 != (Creature *)&this->mGroundNormal.z )
  {
    do
    {
      v5 = (UFG::SimObjectGame *)v4->mPrevMotion.m_scale.m_quad.m128_u64[1];
      if ( v5 && !((v5->m_Flags >> 14) & 1) )
      {
        v6 = v5->m_Flags;
        if ( (v6 >> 14) & 1 )
        {
          v7 = v5->m_Components.p[10].m_pComponent;
        }
        else if ( (v6 & 0x8000u) == 0 )
        {
          if ( (v6 >> 13) & 1 )
          {
            v7 = v5->m_Components.p[7].m_pComponent;
          }
          else if ( (v6 >> 12) & 1 )
          {
            v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::StreamedResourceComponent::_TypeUID);
          }
          else
          {
            v7 = UFG::SimObject::GetComponentOfType(
                   (UFG::SimObject *)&v5->vfptr,
                   UFG::StreamedResourceComponent::_TypeUID);
          }
        }
        else
        {
          v7 = v5->m_Components.p[10].m_pComponent;
        }
        if ( v7 )
        {
          v8 = UFG::SceneObjectProperties::GetArchetypePropertiesName(*(UFG::SceneObjectProperties **)(v4->mPrevMotion.m_scale.m_quad.m128_u64[1] + 80));
          UFG::qArray<UFG::qSymbol,0>::Add(v3, v8, "qArray.Add");
        }
      }
      v4 = (Creature *)&v4->m_SafePointerList.mNode.mNext[-1].mNext;
    }
    while ( v4 != v2 );
  }
}

// File Line: 2429
// RVA: 0x3A6AD0
void __fastcall Creature::DestroyAllAttachments(Creature *this, UFG::SimObject *self, bool onlyRemoveCharacterAttachments)
{
  char *v3; // r15
  bool v4; // r12
  Creature *v5; // r14
  char *v6; // rbp
  UFG::qNode<Attachment,Attachment> *v7; // rbx
  UFG::SimObjectCharacter *v8; // rdi
  __int64 v9; // rsi
  int v10; // eax
  signed __int64 v11; // rbx
  __int64 v12; // rcx
  _QWORD *v13; // rax
  _QWORD *v14; // rdx
  unsigned __int16 v15; // cx
  UFG::SimComponent *v16; // rax

  v3 = (char *)&this->mGroundNormal.z;
  v4 = onlyRemoveCharacterAttachments;
  v5 = this;
  if ( &this->mAttachments.mNode.mNext[-1].mNext != (UFG::qNode<Attachment,Attachment> **)&this->mGroundNormal.z )
  {
    v6 = (char *)&this->mGroundNormal.z;
    do
    {
      v7 = v5->mAttachments.mNode.mNext;
      v8 = (UFG::SimObjectCharacter *)v7[6].mPrev;
      v9 = ((unsigned __int8 (__fastcall *)(UFG::qNode<Attachment,Attachment> **, UFG::SimObject *))v7[-1].mNext[5].mPrev)(
             &v7[-1].mNext,
             self);
      v10 = (int)v7[1].mNext;
      v11 = (signed __int64)&v5->mAttachments.mNode.mNext[-1].mNext;
      if ( (char *)v11 != v6 )
      {
        while ( *(UFG::SimObjectCharacter **)(v11 + 104) != v8 && v8 || *(_DWORD *)(v11 + 32) != v10 )
        {
          v11 = *(_QWORD *)(v11 + 16) - 8i64;
          if ( (char *)v11 == v6 )
            goto LABEL_10;
        }
        (*(void (__fastcall **)(signed __int64))(*(_QWORD *)v11 + 72i64))(v11);
        v12 = *(_QWORD *)(v11 + 8);
        v13 = *(_QWORD **)(v11 + 16);
        v14 = (_QWORD *)(v11 + 8);
        *(_QWORD *)(v12 + 8) = v13;
        *v13 = v12;
        *v14 = v14;
        v14[1] = v14;
        (**(void (__fastcall ***)(signed __int64, signed __int64))v11)(v11, 1i64);
      }
LABEL_10:
      if ( v8 )
      {
        if ( v4 )
        {
          v15 = v8->m_Flags;
          if ( (v15 >> 14) & 1 )
          {
            v16 = v8->m_Components.p[3].m_pComponent;
          }
          else if ( (v15 & 0x8000u) == 0 )
          {
            if ( (v15 >> 13) & 1 )
              v16 = v8->m_Components.p[4].m_pComponent;
            else
              v16 = (v15 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                        (UFG::SimObjectGame *)&v8->vfptr,
                                        UFG::SimObjectPropertiesComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                         (UFG::SimObject *)&v8->vfptr,
                                                                                         UFG::SimObjectPropertiesComponent::_TypeUID);
          }
          else
          {
            v16 = v8->m_Components.p[3].m_pComponent;
          }
          if ( v16 && LODWORD(v16[1].m_SafePointerList.mNode.mNext) == 1 )
            LOBYTE(v9) = 0;
        }
        if ( v8 != LocalPlayer )
        {
          if ( (_BYTE)v9 )
            UFG::Simulation::QueueSimObjectToBeDestroyed(&UFG::gSim, (UFG::SimObject *)&v8->vfptr);
        }
      }
    }
    while ( (char *)&v5->mAttachments.mNode.mNext[-1].mNext != v3 );
  }
}

// File Line: 2505
// RVA: 0x14BF720
__int64 dynamic_initializer_for__sUprightNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32(uprightDriver, 0xFFFFFFFF);
  sUprightNameUID = result;
  return result;
}

// File Line: 2508
// RVA: 0x3AB730
void __usercall Creature::MakeUpright(Creature *this@<rcx>, float uprightTime@<xmm1>, __int64 a3@<rdx>)
{
  UFG::qNode<PoseDriver,PoseDriver> *v3; // rbx
  UFG::qList<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList,1,0> *v4; // rcx
  signed __int64 v5; // rbx

  v3 = this->mPoseDrivers.mNode.mNext;
  v4 = &this->m_SafePointerList;
  v5 = (signed __int64)&v3[-1];
  if ( (UFG::qList<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList,1,0> *)v5 != v4 )
  {
    while ( *(_DWORD *)(v5 + 44) != sUprightNameUID )
    {
      v5 = *(_QWORD *)(v5 + 24) - 16i64;
      if ( (UFG::qList<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList,1,0> *)v5 == v4 )
        return;
    }
    LOBYTE(a3) = 1;
    (*(void (__fastcall **)(signed __int64, __int64))(*(_QWORD *)v5 + 88i64))(v5, a3);
    if ( uprightTime > 0.0 )
    {
      *(_DWORD *)(v5 + 64) = 0;
      *(float *)(v5 + 60) = 1.0 / uprightTime;
    }
    else
    {
      *(_DWORD *)(v5 + 60) = 1065353216;
      *(_DWORD *)(v5 + 64) = 1065353216;
    }
  }
}

// File Line: 2537
// RVA: 0x3B8AC0
void __fastcall Creature::updateEffectorsToPose(Creature *this)
{
  Creature *v1; // rdi
  UFG::qList<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList,1,0> *v2; // rsi
  Creature *v3; // rbx

  v1 = this;
  if ( !gDisablePoseDrivers && !this->mLowPowerModeEnabled && !this->mDisablePosedrivers )
  {
    v2 = &this->m_SafePointerList;
    v3 = (Creature *)&this->mPoseDrivers.mNode.mNext[-1];
    if ( v3 != (Creature *)&this->m_SafePointerList )
    {
      do
      {
        if ( !((unsigned __int8 (__fastcall *)(Creature *))v3->vfptr[13].__vecDelDtor)(v3) )
          v3->vfptr[17].__vecDelDtor((UFG::qSafePointerNode<Creature> *)&v3->vfptr, (unsigned int)&v1->mPose);
        v3 = (Creature *)&v3->mPoseDrivers.mNode.mPrev[-1];
      }
      while ( v3 != (Creature *)v2 );
    }
  }
}

// File Line: 2572
// RVA: 0x3B8B40
void __fastcall Creature::updateEffectorsToPosePostPhysics(Creature *this)
{
  Creature *v1; // rdi
  UFG::qList<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList,1,0> *v2; // rsi
  Creature *v3; // rbx

  v1 = this;
  if ( !gDisablePoseDrivers && !this->mLowPowerModeEnabled && !this->mDisablePosedrivers )
  {
    v2 = &this->m_SafePointerList;
    v3 = (Creature *)&this->mPoseDrivers.mNode.mNext[-1];
    if ( v3 != (Creature *)&this->m_SafePointerList )
    {
      do
      {
        if ( !((unsigned __int8 (__fastcall *)(Creature *))v3->vfptr[13].__vecDelDtor)(v3) )
          v3->vfptr[18].__vecDelDtor((UFG::qSafePointerNode<Creature> *)&v3->vfptr, (unsigned int)&v1->mPose);
        v3 = (Creature *)&v3->mPoseDrivers.mNode.mPrev[-1];
      }
      while ( v3 != (Creature *)v2 );
    }
  }
}

// File Line: 2616
// RVA: 0x3AB0A0
char __fastcall Creature::IsEndEffector(Creature *this, int attachBoneID)
{
  int v2; // edi
  char *v3; // r14
  UFG::qList<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList,1,0> *v4; // rsi
  Creature *v5; // rbx
  UFG::qList<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList,1,0> *v7; // rsi
  Creature *v8; // rbx

  v2 = attachBoneID;
  if ( attachBoneID >= 4 )
  {
LABEL_5:
    v4 = &this->m_SafePointerList;
    v5 = (Creature *)&this->mPoseDrivers.mNode.mNext[-1];
    if ( v5 != (Creature *)&this->m_SafePointerList )
    {
      while ( ((unsigned int (__fastcall *)(Creature *))v5->vfptr[14].__vecDelDtor)(v5) != v2 )
      {
        v5 = (Creature *)&v5->mPoseDrivers.mNode.mPrev[-1];
        if ( v5 == (Creature *)v4 )
          return 0;
      }
      return 1;
    }
    return 0;
  }
  v3 = (char *)this + attachBoneID;
  if ( !v3[216] )
  {
    v7 = &this->m_SafePointerList;
    v8 = (Creature *)&this->mPoseDrivers.mNode.mNext[-1];
    if ( v8 != (Creature *)&this->m_SafePointerList )
    {
      while ( ((unsigned int (__fastcall *)(Creature *))v8->vfptr[14].__vecDelDtor)(v8) != v2 )
      {
        v8 = (Creature *)&v8->mPoseDrivers.mNode.mPrev[-1];
        if ( v8 == (Creature *)v7 )
          goto LABEL_13;
      }
      v3[216] = 1;
      return 1;
    }
LABEL_13:
    v3[216] = 2;
    return 0;
  }
  if ( this->mIsEndEffectorCache[attachBoneID] != 1 )
  {
    if ( this->mIsEndEffectorCache[attachBoneID] == 2 )
      return 0;
    goto LABEL_5;
  }
  return 1;
}

// File Line: 2652
// RVA: 0x3AF250
void __fastcall Creature::SetEndEffectorTarget(Creature *this, int attachBoneID, UFG::qMatrix44 *matrix)
{
  UFG::qList<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList,1,0> *v3; // rdi
  UFG::qMatrix44 *v4; // r14
  Creature *v5; // rbx
  int v6; // esi
  Creature *v7; // rbp
  __int64 v8; // rdx
  UFG::qColour v9; // [rsp+20h] [rbp-18h]

  v3 = &this->m_SafePointerList;
  v4 = matrix;
  v5 = (Creature *)&this->mPoseDrivers.mNode.mNext[-1];
  v6 = attachBoneID;
  v7 = this;
  if ( v5 != (Creature *)&this->m_SafePointerList )
  {
    while ( ((unsigned int (__fastcall *)(Creature *))v5->vfptr[14].__vecDelDtor)(v5) != v6 )
    {
      v5 = (Creature *)&v5->mPoseDrivers.mNode.mPrev[-1];
      if ( v5 == (Creature *)v3 )
        return;
    }
    ((void (__fastcall *)(Creature *, SkeletalPose *, UFG::qMatrix44 *))v5->vfptr[15].__vecDelDtor)(v5, &v7->mPose, v4);
    LOBYTE(v8) = 1;
    v5->vfptr[11].__vecDelDtor((UFG::qSafePointerNode<Creature> *)&v5->vfptr, v8);
    v5->vfptr[17].__vecDelDtor((UFG::qSafePointerNode<Creature> *)&v5->vfptr, (unsigned int)&v7->mPose);
    if ( sShowIKPose )
    {
      v9 = UFG::qColour::Green;
      SkeletalPose::DebugDraw(&v7->mPose, &v9, 1.0);
    }
  }
}

// File Line: 2670
// RVA: 0x3A4BE0
void __fastcall Creature::BuildPoseDriver(Creature *this, UFG::qSymbolUC *poseDriverSet)
{
  Creature *v2; // r10
  UFG::qNode<RigInfo,RigInfo> *v3; // rcx
  char *v4; // rax
  UFG::qString v5; // [rsp+28h] [rbp-B0h]
  char dest; // [rsp+50h] [rbp-88h]

  v2 = this;
  if ( poseDriverSet->mUID != -1 )
  {
    v3 = RigInfoDataBase::sRigInfoDataBase->mRigInfos.mNode.mNext - 1;
    if ( v3 == (UFG::qNode<RigInfo,RigInfo> *)RigInfoDataBase::sRigInfoDataBase )
    {
LABEL_7:
      v4 = UFG::qSymbol::as_cstr_dbg(poseDriverSet);
      UFG::qSPrintf(&dest, "Data\\Global\\Act\\%s.rig2", v4);
      UFG::qString::qString(&v5);
      UFG::qString::~qString(&v5);
    }
    else
    {
      while ( LODWORD(v3[2].mPrev) != poseDriverSet->mUID )
      {
        v3 = v3[1].mNext - 1;
        if ( v3 == (UFG::qNode<RigInfo,RigInfo> *)RigInfoDataBase::sRigInfoDataBase )
          goto LABEL_7;
      }
      RigInfo::AddToCreature((RigInfo *)v3, v2);
    }
  }
}

// File Line: 2711
// RVA: 0x14BF6B0
__int64 dynamic_initializer_for__sRightShoulderTwistUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("RightShoulderTwist", 0xFFFFFFFF);
  sRightShoulderTwistUID = result;
  return result;
}

// File Line: 2712
// RVA: 0x14BF530
__int64 dynamic_initializer_for__sLeftShoulderTwistUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("LeftShoulderTwist", 0xFFFFFFFF);
  sLeftShoulderTwistUID = result;
  return result;
}

// File Line: 2713
// RVA: 0x14BF690
__int64 dynamic_initializer_for__sRightShoulderTwistPoseUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("RightShoulderTwistPose", 0xFFFFFFFF);
  sRightShoulderTwistPoseUID = result;
  return result;
}

// File Line: 2714
// RVA: 0x14BF510
__int64 dynamic_initializer_for__sLeftShoulderTwistPoseUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("LeftShoulderTwistPose", 0xFFFFFFFF);
  sLeftShoulderTwistPoseUID = result;
  return result;
}

// File Line: 2715
// RVA: 0x14BF650
__int64 dynamic_initializer_for__sRightForearmTwistUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("RightForearmTwist", 0xFFFFFFFF);
  sRightForearmTwistUID = result;
  return result;
}

// File Line: 2716
// RVA: 0x14BF4D0
__int64 dynamic_initializer_for__sLeftForearmTwistUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("LeftForearmTwist", 0xFFFFFFFF);
  sLeftForearmTwistUID = result;
  return result;
}

// File Line: 2717
// RVA: 0x14BF630
__int64 dynamic_initializer_for__sRightArmIKUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("RightArmIK", 0xFFFFFFFF);
  sRightArmIKUID = result;
  return result;
}

// File Line: 2718
// RVA: 0x14BF4B0
__int64 dynamic_initializer_for__sLeftArmIKUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("LeftArmIK", 0xFFFFFFFF);
  sLeftArmIKUID = result;
  return result;
}

// File Line: 2719
// RVA: 0x14BF670
__int64 dynamic_initializer_for__sRightLegIKUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("RightLegIK", 0xFFFFFFFF);
  sRightLegIKUID = result;
  return result;
}

// File Line: 2720
// RVA: 0x14BF4F0
__int64 dynamic_initializer_for__sLeftLegIKUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("LeftLegIK", 0xFFFFFFFF);
  sLeftLegIKUID = result;
  return result;
}

// File Line: 2722
// RVA: 0x14BF460
__int64 dynamic_initializer_for__sHeadTrackerUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("HeadTracker", 0xFFFFFFFF);
  sHeadTrackerUID = result;
  return result;
}

// File Line: 2723
// RVA: 0x14BF5F0
__int64 dynamic_initializer_for__sR_EyeTrackerUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("R_EyeTracker", 0xFFFFFFFF);
  sR_EyeTrackerUID = result;
  return result;
}

// File Line: 2724
// RVA: 0x14BF490
__int64 dynamic_initializer_for__sL_EyeTrackerUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("L_EyeTracker", 0xFFFFFFFF);
  sL_EyeTrackerUID = result;
  return result;
}

// File Line: 2725
// RVA: 0x14BF6D0
__int64 dynamic_initializer_for__sSpineTrackerUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("SpineTracker", 0xFFFFFFFF);
  sSpineTrackerUID = result;
  return result;
}

// File Line: 2742
// RVA: 0x3B84E0
void __fastcall updateAndApplyEffector(Creature *creature, TwoLinkIKsolver *IKEffector, UFG::qMatrix44 *worldTarget)
{
  SkeletalPose *v3; // rbx
  UFG::qMatrix44 *v4; // rdi
  TwoLinkIKsolver *v5; // r14
  unsigned __int8 v6; // al
  __int64 v7; // rdx
  unsigned __int8 v8; // si

  v3 = (SkeletalPose *)creature;
  v4 = worldTarget;
  v5 = IKEffector;
  v6 = ((__int64 (__fastcall *)(TwoLinkIKsolver *))IKEffector->vfptr[1].FindWithOldPath)(IKEffector);
  LOBYTE(v7) = 1;
  v8 = v6;
  v5->vfptr[1].__vecDelDtor((Expression::IMemberMap *)&v5->vfptr, v7);
  v3 = (SkeletalPose *)((char *)v3 + 240);
  ((void (__fastcall *)(TwoLinkIKsolver *, SkeletalPose *, UFG::qMatrix44 *))v5->vfptr[1].GetClassNameUID)(v5, v3, v4);
  TwoLinkIKsolver::UpdateWorldTarget(v5, v3);
  ((void (__fastcall *)(TwoLinkIKsolver *, SkeletalPose *))v5->vfptr[1].ResolveReferences)(v5, v3);
  v5->vfptr[1].__vecDelDtor((Expression::IMemberMap *)&v5->vfptr, v8);
}

// File Line: 2758
// RVA: 0x14BF700
__int64 dynamic_initializer_for__sUpperBodyWeightSet__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("UpperBody_Ragdoll", 0xFFFFFFFF);
  sUpperBodyWeightSet = result;
  return result;
}

// File Line: 2759
// RVA: 0x14BF610
__int64 dynamic_initializer_for__sRagdoll_NoControlBonesWeightSet__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Ragdoll_NoControlBones", 0xFFFFFFFF);
  sRagdoll_NoControlBonesWeightSet = result;
  return result;
}

// File Line: 2762
// RVA: 0x3A2EC0
void __fastcall Creature::BlendInPose(Creature *this, SkeletalPose *pose, float weight, bool projectTheArrow)
{
  UFG::qNode<PoseDriver,PoseDriver> *v4; // rsi
  float v5; // xmm6_4
  SkeletalPose *v6; // r12
  Creature *v7; // r15
  __int128 *v8; // xmm7_8
  SkeletalPose *v9; // rbx
  signed __int64 v10; // rax
  TwoLinkIKsolver *v11; // r13
  TwoLinkIKsolver *v12; // rbx
  int v13; // eax
  int v14; // eax
  SkeletalPose *v15; // r14
  unsigned int v16; // edx
  WeightSetGroup *v17; // r14
  UFG::qWiseSymbol *v18; // rax
  unsigned int v19; // ecx
  unsigned int v20; // er10
  __int64 v21; // r8
  __int64 v22; // rax
  signed __int64 v23; // rdx
  _QWORD *v24; // rdx
  _QWORD *v25; // rdi
  signed int v26; // er12
  __int64 v27; // rcx
  float *weightset_array; // r8
  float v29; // xmm0_4
  __int64 v30; // rax
  signed __int64 v31; // r10
  unsigned __int64 v32; // r9
  int v33; // edx
  __int64 v34; // rcx
  __m128 v35; // xmm1
  int v36; // eax
  signed __int64 v37; // r11
  unsigned __int64 v38; // rdi
  signed __int64 v39; // rcx
  unsigned __int64 v40; // rax
  signed __int64 v41; // r10
  unsigned __int64 v42; // r9
  signed __int64 v43; // rax
  float *v44; // rdi
  signed __int64 v45; // rcx
  int v46; // eax
  hkQsTransformf *v47; // rax
  hkaPose *v48; // rdi
  unsigned int *v49; // rcx
  __m128 *v50; // rbx
  hkQsTransformf *v51; // rax
  __m128 v52; // xmm2
  __m128 v53; // xmm1
  __m128 v54; // xmm6
  __m128 v55; // xmm5
  __m128 v56; // xmm4
  __m128 v57; // xmm2
  __m128 v58; // xmm3
  __m128 v59; // xmm5
  __m128 v60; // xmm6
  __m128 v61; // xmm3
  __m128 v62; // xmm4
  __m128 v63; // xmm6
  __m128 v64; // xmm2
  __m128 v65; // xmm9
  __m128 v66; // xmm9
  __m128 v67; // xmm10
  __m128 v68; // xmm10
  __m128 v69; // xmm1
  __m128 v70; // xmm8
  __m128 v71; // xmm4
  __m128 v72; // xmm8
  __m128 v73; // xmm3
  __m128 v74; // xmm9
  __m128 v75; // xmm1
  __m128 v76; // xmm3
  __m128 v77; // xmm2
  __m128 v78; // xmm1
  __m128 v79; // xmm8
  __m128 v80; // xmm2
  __m128 v81; // xmm1
  __m128 v82; // xmm10
  hkaPose *v83; // r12
  unsigned int *v84; // rdi
  _OWORD *v85; // rdx
  __int16 *v86; // rcx
  __int16 v87; // ax
  hkQsTransformf *v88; // rax
  __m128 *v89; // rbx
  __m128 *v90; // rdi
  __m128i v91; // xmm0
  __m128 v92; // xmm8
  __m128 v93; // xmm6
  __m128 v94; // xmm2
  __m128 v95; // xmm7
  __m128 v96; // xmm5
  __m128 *v97; // rax
  __m128 v98; // xmm3
  __m128 v99; // xmm0
  __m128 v100; // xmm1
  __m128 v101; // xmm9
  __m128 v102; // xmm4
  __m128 v103; // xmm2
  __m128 v104; // xmm2
  __m128 v105; // xmm3
  __m128 v106; // xmm4
  __m128 v107; // xmm1
  __m128 v108; // xmm8
  __m128 v109; // xmm4
  __m128 v110; // xmm4
  _OWORD *v111; // rax
  __m128 *v112; // rax
  __m128 v113; // xmm6
  __m128 v114; // xmm7
  __m128 v115; // xmm8
  hkQsTransformf *v116; // rax
  __m128 v117; // xmm3
  __m128 v118; // xmm1
  __m128 v119; // xmm4
  __m128 v120; // xmm2
  __m128 v121; // xmm9
  __m128 v122; // xmm2
  __m128 v123; // xmm9
  __m128 v124; // xmm10
  __m128 v125; // xmm0
  __m128 v126; // xmm7
  __m128 v127; // xmm10
  __m128 v128; // xmm2
  __m128 v129; // xmm7
  __m128 v130; // xmm10
  hkQsTransformf *v131; // rbx
  __m128i v132; // xmm0
  __m128 v133; // xmm11
  __m128 v134; // xmm12
  __m128 v135; // xmm0
  __m128 v136; // xmm6
  __m128 v137; // xmm1
  __m128 v138; // xmm5
  __m128 v139; // xmm15
  __m128 v140; // xmm3
  __m128 v141; // xmm8
  __m128 v142; // xmm1
  __m128 v143; // xmm8
  __m128 v144; // xmm2
  __m128 v145; // xmm14
  __m128 v146; // xmm1
  __m128 v147; // xmm14
  __m128 v148; // xmm6
  __m128 v149; // xmm14
  __m128 v150; // xmm2
  __m128 v151; // xmm15
  __m128 v152; // xmm14
  __m128 v153; // xmm15
  __m128 v154; // xmm15
  hkaPose *v155; // r15
  signed __int64 v156; // rdx
  hkaSkeleton *v157; // rax
  signed __int64 v158; // r12
  signed __int64 v159; // rcx
  __m128 *v160; // r8
  signed __int64 v161; // r14
  __int64 v162; // rdx
  unsigned int *v163; // rdi
  hkQsTransformf *v164; // rcx
  hkQsTransformf *v165; // rax
  hkQsTransformf *v166; // rbx
  __m128 *v167; // rdi
  __m128 v168; // xmm8
  __m128 v169; // xmm0
  __int64 v170; // rax
  __m128 v171; // xmm7
  __m128 v172; // xmm5
  __m128 v173; // xmm3
  __m128 v174; // xmm1
  __m128 v175; // xmm4
  __m128i v176; // xmm9
  __m128 v177; // xmm1
  __m128 v178; // xmm2
  __m128 v179; // xmm2
  __m128 v180; // xmm3
  __m128 v181; // xmm1
  __m128 v182; // xmm4
  __m128 v183; // xmm8
  __m128 v184; // xmm4
  __m128 v185; // xmm4
  hkQsTransformf *v186; // rax
  unsigned int *v187; // rcx
  unsigned int v188; // eax
  __m128 *v189; // rax
  UFG::qNode<PoseDriver,PoseDriver> *v190; // r14
  UFG::qNode<PoseDriver,PoseDriver> *v191; // rcx
  char *v192; // rdx
  UFG::qNode<PoseDriver,PoseDriver> *v193; // rdi
  UFG::qNode<PoseDriver,PoseDriver> *v194; // rax
  UFG::qNode<PoseDriver,PoseDriver> *v195; // r15
  UFG::qNode<PoseDriver,PoseDriver> *v196; // r12
  __int64 v197; // r8
  __int64 v198; // r9
  float *v199; // rax
  float v200; // xmm5_4
  float v201; // xmm4_4
  float v202; // xmm3_4
  float v203; // xmm2_4
  float v204; // xmm1_4
  unsigned __int8 v205; // [rsp+30h] [rbp-B0h]
  UFG::qWiseSymbol result[2]; // [rsp+38h] [rbp-A8h]
  __m128 *v207; // [rsp+40h] [rbp-A0h]
  TwoLinkIKsolver *v208; // [rsp+48h] [rbp-98h]
  TwoLinkIKsolver *v209; // [rsp+50h] [rbp-90h]
  hkQsTransformf *v210; // [rsp+58h] [rbp-88h]
  hkVector4f v211; // [rsp+60h] [rbp-80h]
  hkVector4f v212; // [rsp+70h] [rbp-70h]
  UFG::qMatrix44 toMatrixWS; // [rsp+80h] [rbp-60h]
  __m128 v214; // [rsp+C0h] [rbp-20h]
  UFG::qMatrix44 matrixWS; // [rsp+D0h] [rbp-10h]
  __m128 v216; // [rsp+110h] [rbp+30h]
  hkQuaternionf quat; // [rsp+120h] [rbp+40h]
  __m128 v218; // [rsp+130h] [rbp+50h]
  UFG::qMatrix44 worldTarget; // [rsp+140h] [rbp+60h]
  UFG::qMatrix44 v220; // [rsp+180h] [rbp+A0h]
  Creature *creature; // [rsp+2B0h] [rbp+1D0h]
  SkeletalPose *inputPose; // [rsp+2B8h] [rbp+1D8h]
  unsigned int vars0; // [rsp+2C0h] [rbp+1E0h]
  void *retaddr; // [rsp+2C8h] [rbp+1E8h]

  v4 = 0i64;
  v5 = weight;
  v6 = pose;
  v7 = this;
  v8 = (__int128 *)(unsigned int)FLOAT_1_0;
  if ( gDrawPoseExternalInputPose )
  {
    v211.m_quad = (__m128)UFG::qColour::DeepPink;
    SkeletalPose::DebugDraw(pose, (UFG::qColour *)&v211, 1.0);
    if ( gDrawPosePostAnimUpdate )
    {
      v9 = SkeletalPose::Clone(&v7->mPose);
      SkeletalPose::Blend(v9, &v7->mPose, 1.0, -1, v8, 1, 0i64);
      SkeletalPose::GetPositionWS(v9, 0, &matrixWS);
      SkeletalPose::GetPositionWS(v6, 0, &toMatrixWS);
      AttachPose(v9, &matrixWS, &toMatrixWS);
      v211.m_quad = (__m128)UFG::qColour::DarkViolet;
      SkeletalPose::DebugDraw(v9, (UFG::qColour *)&v211, 1.0);
      if ( v9 )
      {
        SkeletalPose::~SkeletalPose(v9);
        operator delete[](v9);
      }
    }
  }
  v10 = (signed __int64)&v7->m_SafePointerList;
  v11 = (TwoLinkIKsolver *)&v7->mPoseDrivers.mNode.mNext[-1];
  v12 = v11;
  v209 = (TwoLinkIKsolver *)&v7->mPoseDrivers.mNode.mNext[-1];
  v208 = v11;
  if ( v11 == (TwoLinkIKsolver *)&v7->m_SafePointerList )
  {
LABEL_8:
    v12 = 0i64;
    v208 = 0i64;
  }
  else
  {
    while ( v12->mName.mUID != sRightLegIKUID )
    {
      v12 = (TwoLinkIKsolver *)&v12->mNext[-1];
      v208 = v12;
      if ( v12 == (TwoLinkIKsolver *)v10 )
        goto LABEL_8;
    }
  }
  if ( v11 == (TwoLinkIKsolver *)v10 )
  {
LABEL_12:
    v11 = 0i64;
    v209 = 0i64;
  }
  else
  {
    while ( v11->mName.mUID != sLeftLegIKUID )
    {
      v11 = (TwoLinkIKsolver *)&v11->mNext[-1];
      v209 = v11;
      if ( v11 == (TwoLinkIKsolver *)v10 )
        goto LABEL_12;
    }
  }
  if ( v12 && v11 )
  {
    v13 = (__int64)v12->vfptr[1].GetClassname((Expression::IMemberMap *)&v12->vfptr);
    SkeletalPose::GetPositionWS(&v7->mPose, v13, &worldTarget);
    v14 = (__int64)v11->vfptr[1].GetClassname((Expression::IMemberMap *)&v11->vfptr);
    SkeletalPose::GetPositionWS(&v7->mPose, v14, &v220);
  }
  if ( !sUseLowerBody && !sUseRagdollNoControlBones )
  {
    v15 = &v7->mPose;
    SkeletalPose::Blend(&v7->mPose, v6, weight, 27, v8, 1, 0i64);
    goto LABEL_65;
  }
  if ( weight == *(float *)&v8 )
  {
    v5 = FLOAT_0_99000001;
    vars0 = LODWORD(FLOAT_0_99000001);
  }
  v16 = sRagdoll_NoControlBonesWeightSet;
  if ( sUseLowerBody )
    v16 = sUpperBodyWeightSet;
  v17 = v7->mPose.mRigHandle.mUFGSkeleton->mWeightSetData;
  v18 = UFG::qSymbol::qSymbol(result, v16);
  v19 = 0;
  if ( v17->mWeightsets.mCount & 0x7FFFFFFF )
  {
    v20 = v18->mUID;
    v21 = v17->mWeightsets.mData.mOffset;
    v22 = 0i64;
    while ( 1 )
    {
      v23 = (signed __int64)(v21 ? (UFG::qOffset64<UFG::qOffset64<Weightset *> *> *)((char *)&v17->mWeightsets.mData
                                                                                   + v21) : 0i64);
      v24 = (_QWORD *)(v22 + v23);
      v25 = *v24 ? (_QWORD *)((char *)v24 + *v24) : 0i64;
      if ( *((_DWORD *)v25 + 4) == v20 )
        break;
      ++v19;
      v22 += 8i64;
      if ( v19 >= (v17->mWeightsets.mCount & 0x7FFFFFFFu) )
        goto LABEL_33;
    }
  }
  else
  {
LABEL_33:
    v25 = 0i64;
  }
  v15 = &v7->mPose;
  SkeletalPose::GetPositionMS(&v7->mPose, 2, &toMatrixWS);
  v26 = v6->mHavokPose->m_skeleton->m_bones.m_size;
  if ( (unsigned int)v26 > 0x1B )
    v26 = 27;
  if ( !v25 )
    goto LABEL_139;
  if ( v5 != *(float *)&v8 || (unsigned int)v26 > *((_DWORD *)v25 + 11) )
  {
    weightset_array = (float *)UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 4 * v26, 0x10u);
    v29 = (float)(v25[3] & 0x7FFFFFFF);
    if ( v29 >= (float)v26 )
      v29 = (float)v26;
    v30 = v25[6];
    LODWORD(v31) = (signed int)v29;
    if ( v30 )
      v32 = (unsigned __int64)v25 + v30 + 48;
    else
      v32 = 0i64;
    v33 = 0;
    if ( (signed int)v31 > 0 && (unsigned int)v31 >= 8 )
    {
      v34 = (signed int)v31 - 1;
      v35 = _mm_shuffle_ps((__m128)vars0, (__m128)vars0, 0);
      if ( (unsigned __int64)weightset_array > v32 + 4 * v34 || (unsigned __int64)&weightset_array[v34] < v32 )
      {
        do
        {
          *(__m128 *)&weightset_array[v33] = _mm_mul_ps(*(__m128 *)(v32 + 4i64 * v33), v35);
          v36 = v33 + 4;
          v33 += 8;
          *(__m128 *)&weightset_array[v36] = _mm_mul_ps(*(__m128 *)(v32 + 4i64 * v36), v35);
        }
        while ( v33 < (signed int)v31 - (signed int)v31 % 8 );
      }
    }
    v37 = v33;
    v31 = (signed int)v31;
    if ( v33 < (signed __int64)(signed int)v31 )
    {
      if ( v31 - v33 >= 4 )
      {
        v38 = v32 - (_QWORD)weightset_array;
        v39 = (signed __int64)&weightset_array[v33 + 1];
        v40 = ((unsigned __int64)(v31 - v33 - 4) >> 2) + 1;
        v37 = v33 + 4 * v40;
        v33 += 4 * v40;
        do
        {
          v39 += 16i64;
          *(float *)(v39 - 20) = v5 * *(float *)(v38 + v39 - 20);
          *(float *)(v39 - 16) = v5 * *(float *)(v38 + v39 - 16);
          *(float *)(v39 - 12) = v5 * *(float *)(v38 + v39 - 12);
          *(float *)(v39 - 8) = v5 * *(float *)(v38 + v39 - 8);
          --v40;
        }
        while ( v40 );
      }
      if ( v37 < v31 )
      {
        v41 = v31 - v37;
        v42 = v32 - (_QWORD)weightset_array;
        v43 = (signed __int64)&weightset_array[v37];
        v33 += v41;
        do
        {
          v43 += 4i64;
          *(float *)(v43 - 4) = v5 * *(float *)(v43 + v42 - 4);
          --v41;
        }
        while ( v41 );
      }
    }
    *(float *)&v207 = v5 * 255.0;
    if ( v33 < (signed __int64)v26 )
    {
      v44 = &weightset_array[v33];
      v45 = v26 - (signed __int64)v33;
      v46 = (signed int)v207;
      while ( v45 )
      {
        *(_DWORD *)v44 = v46;
        ++v44;
        --v45;
      }
    }
    goto LABEL_64;
  }
  v27 = v25[6];
  if ( v27 )
    weightset_array = (float *)((char *)v25 + v27 + 48);
  else
LABEL_139:
    weightset_array = 0i64;
LABEL_64:
  v6 = inputPose;
  SkeletalPose::Blend(&v7->mPose, inputPose, v5, 27, v8, 1, weightset_array);
  SkeletalPose::SetPositionMS(&v7->mPose, 2, &toMatrixWS);
LABEL_65:
  if ( (_BYTE)retaddr )
  {
    v47 = SkeletalPose::GetRoot(v6);
    v48 = v6->mHavokPose;
    v49 = v48->m_boneFlags.m_data;
    v50 = &v47->m_translation.m_quad;
    v210 = v47;
    if ( *(_BYTE *)v49 & 2 )
      v51 = hkaPose::calculateBoneModelSpace(v48, 0);
    else
      v51 = v48->m_modelPose.m_data;
    v52 = v50[1];
    v53 = _mm_mul_ps(v51->m_translation.m_quad, v52);
    v54 = _mm_shuffle_ps(v50[1], v52, 255);
    v55 = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(v51->m_translation.m_quad, v51->m_translation.m_quad, 201), v52),
            _mm_mul_ps(_mm_shuffle_ps(v52, v52, 201), v51->m_translation.m_quad));
    v56 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v53, v53, 85), _mm_shuffle_ps(v53, v53, 0)),
                  _mm_shuffle_ps(v53, v53, 170)),
                v52),
              _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v54, v54), (__m128)xmmword_141A711B0), v51->m_translation.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v55, v55, 201), v54));
    v216 = _mm_add_ps(_mm_add_ps(v56, v56), *v50);
    v57 = v50[1];
    v58 = v51->m_rotation.m_vec.m_quad;
    v59 = _mm_shuffle_ps(v51->m_rotation.m_vec.m_quad, v58, 255);
    v60 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v58, v58, 201), v57), _mm_mul_ps(_mm_shuffle_ps(v57, v57, 201), v58));
    v61 = _mm_mul_ps(v58, v57);
    v62 = _mm_shuffle_ps(v50[1], v57, 255);
    v63 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v60, v60, 201), _mm_mul_ps(v51->m_rotation.m_vec.m_quad, v62)),
            _mm_mul_ps(v50[1], v59));
    quat.m_vec.m_quad = _mm_shuffle_ps(
                          v63,
                          _mm_unpackhi_ps(
                            v63,
                            _mm_sub_ps(
                              _mm_mul_ps(v59, v62),
                              _mm_add_ps(
                                _mm_add_ps(_mm_shuffle_ps(v61, v61, 85), _mm_shuffle_ps(v61, v61, 0)),
                                _mm_shuffle_ps(v61, v61, 170)))),
                          196);
    v218 = _mm_mul_ps(v51->m_scale.m_quad, v50[2]);
    hkVector4f::setRotatedDir(&v211, &quat, &direction);
    v64 = _mm_shuffle_ps(stru_141A71280.m_quad, stru_141A71280.m_quad, 201);
    v65 = _mm_sub_ps(
            _mm_mul_ps(v211.m_quad, v64),
            _mm_mul_ps(_mm_shuffle_ps(v211.m_quad, v211.m_quad, 201), stru_141A71280.m_quad));
    v66 = _mm_shuffle_ps(v65, v65, 201);
    v67 = _mm_sub_ps(_mm_mul_ps(stru_141A71280.m_quad, v66), _mm_mul_ps(v66, v64));
    v68 = _mm_shuffle_ps(v67, v67, 201);
    v69 = _mm_mul_ps(v66, v66);
    v70 = _mm_sub_ps(_mm_mul_ps(v68, v66), _mm_mul_ps(v68, v66));
    v71 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v69, v69, 85), _mm_shuffle_ps(v69, v69, 0)),
            _mm_shuffle_ps(v69, v69, 170));
    v72 = _mm_shuffle_ps(v70, v70, 201);
    v73 = _mm_rsqrt_ps(v71);
    v74 = _mm_mul_ps(
            v66,
            _mm_andnot_ps(
              _mm_cmpleps(v71, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v73, v71), v73)),
                _mm_mul_ps(v73, *(__m128 *)_xmm))));
    v75 = _mm_mul_ps(v72, v72);
    v76 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v75, v75, 85), _mm_shuffle_ps(v75, v75, 0)),
            _mm_shuffle_ps(v75, v75, 170));
    v77 = _mm_rsqrt_ps(v76);
    v78 = _mm_mul_ps(v68, v68);
    v79 = _mm_mul_ps(
            v72,
            _mm_andnot_ps(
              _mm_cmpleps(v76, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v77, v76), v77)),
                _mm_mul_ps(v77, *(__m128 *)_xmm))));
    v80 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v78, v78, 85), _mm_shuffle_ps(v78, v78, 0)),
            _mm_shuffle_ps(v78, v78, 170));
    v81 = _mm_rsqrt_ps(v80);
    v82 = _mm_mul_ps(
            v68,
            _mm_andnot_ps(
              _mm_cmpleps(v80, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v81, v80), v81)),
                _mm_mul_ps(v81, *(__m128 *)_xmm))));
    v83 = v7->mPose.mHavokPose;
    v211.m_quad = _mm_sub_ps(v82, _mm_mul_ps(v82, qi.m_vec.m_quad));
    matrixWS.v1 = (UFG::qVector4)v211.m_quad;
    matrixWS.v0 = (UFG::qVector4)_mm_sub_ps(v74, _mm_mul_ps(v74, qi.m_vec.m_quad));
    matrixWS.v2 = (UFG::qVector4)_mm_sub_ps(v79, _mm_mul_ps(v79, qi.m_vec.m_quad));
    v84 = v83->m_boneFlags.m_data;
    if ( *(_BYTE *)v84 & 1 )
    {
      v85 = (_OWORD *)v83->m_modelPose.m_data->m_translation.m_quad.m128_f32;
      v86 = v83->m_skeleton->m_parentIndices.m_data;
      v207 = &v83->m_modelPose.m_data->m_translation.m_quad;
      v87 = *v86;
      if ( *v86 == -1 )
      {
        v111 = (_OWORD *)v83->m_localPose.m_data->m_translation.m_quad.m128_f32;
        *v111 = *v85;
        v111[1] = v85[1];
        v111[2] = v85[2];
      }
      else
      {
        if ( v84[v87] & 2 )
          v88 = hkaPose::calculateBoneModelSpace(v83, v87);
        else
          v88 = (hkQsTransformf *)&v85[3 * v87];
        v89 = &v83->m_localPose.m_data->m_translation.m_quad;
        v90 = &v88->m_rotation.m_vec.m_quad;
        *(_QWORD *)&result[0].mUID = v88;
        hkVector4f::setRotatedInverseDir(&v212, &v88->m_rotation, &v88->m_translation);
        v91 = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
        v92 = _mm_xor_ps((__m128)_mm_shuffle_epi32(v91, 64), *v90);
        v93 = _mm_xor_ps((__m128)_mm_shuffle_epi32(v91, 0), v212.m_quad);
        v211.m_quad = v92;
        v94 = _mm_rcp_ps(*(__m128 *)(*(_QWORD *)&result[0].mUID + 32i64));
        v95 = _mm_shuffle_ps(v92, v92, 255);
        v96 = _mm_shuffle_ps(v92, v92, 201);
        v212.m_quad = v93;
        v97 = v207;
        v98 = *v207;
        v99 = _mm_mul_ps(v96, *v207);
        v100 = _mm_mul_ps(v92, *v207);
        v101 = (__m128)_mm_srli_si128(
                         _mm_slli_si128(
                           (__m128i)_mm_mul_ps(
                                      _mm_sub_ps(
                                        (__m128)_xmm,
                                        _mm_mul_ps(v94, *(__m128 *)(*(_QWORD *)&result[0].mUID + 32i64))),
                                      v94),
                           4),
                         4);
        v212.m_quad = v101;
        v102 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v98, v98, 201), v92), v99);
        v103 = _mm_add_ps(
                 _mm_add_ps(
                   _mm_mul_ps(
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v100, v100, 85), _mm_shuffle_ps(v100, v100, 0)),
                       _mm_shuffle_ps(v100, v100, 170)),
                     v92),
                   _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v95, v95), (__m128)xmmword_141A711B0), v98)),
                 _mm_mul_ps(_mm_shuffle_ps(v102, v102, 201), v95));
        *v89 = _mm_add_ps(_mm_add_ps(v103, v103), v93);
        v104 = v97[1];
        v105 = _mm_shuffle_ps(v97[1], v104, 255);
        v106 = _mm_mul_ps(_mm_shuffle_ps(v104, v104, 201), v92);
        v107 = _mm_mul_ps(v92, v105);
        v108 = _mm_mul_ps(v92, v104);
        v109 = _mm_sub_ps(v106, _mm_mul_ps(v97[1], v96));
        v110 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v109, v109, 201), _mm_mul_ps(v97[1], v95)), v107);
        v89[1] = _mm_shuffle_ps(
                   v110,
                   _mm_unpackhi_ps(
                     v110,
                     _mm_sub_ps(
                       _mm_mul_ps(v105, v95),
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v108, v108, 85), _mm_shuffle_ps(v108, v108, 0)),
                         _mm_shuffle_ps(v108, v108, 170)))),
                   196);
        v89[2] = _mm_mul_ps(v97[2], v101);
        v50 = &v210->m_translation.m_quad;
      }
      *v83->m_boneFlags.m_data &= 0xFFFFFFFE;
    }
    v112 = &v83->m_localPose.m_data->m_translation.m_quad;
    v113 = *v112;
    v114 = v112[1];
    v115 = v112[2];
    v116 = SkeletalPose::GetRoot(v15);
    v117 = v116->m_rotation.m_vec.m_quad;
    v118 = _mm_mul_ps(v113, v117);
    v119 = _mm_shuffle_ps(v116->m_rotation.m_vec.m_quad, v117, 255);
    v120 = _mm_sub_ps(
             _mm_mul_ps(_mm_shuffle_ps(v113, v113, 201), v117),
             _mm_mul_ps(_mm_shuffle_ps(v117, v117, 201), v113));
    v121 = _mm_add_ps(
             _mm_add_ps(
               _mm_mul_ps(
                 _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v118, v118, 85), _mm_shuffle_ps(v118, v118, 0)),
                   _mm_shuffle_ps(v118, v118, 170)),
                 v117),
               _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v119, v119), (__m128)xmmword_141A711B0), v113)),
             _mm_mul_ps(_mm_shuffle_ps(v120, v120, 201), v119));
    v122 = _mm_shuffle_ps(v114, v114, 255);
    v123 = _mm_add_ps(_mm_add_ps(v121, v121), v116->m_translation.m_quad);
    v124 = _mm_sub_ps(
             _mm_mul_ps(_mm_shuffle_ps(v114, v114, 201), v117),
             _mm_mul_ps(_mm_shuffle_ps(v116->m_rotation.m_vec.m_quad, v117, 201), v114));
    v125 = v114;
    v126 = _mm_mul_ps(v114, v117);
    v127 = _mm_add_ps(
             _mm_add_ps(_mm_shuffle_ps(v124, v124, 201), _mm_mul_ps(v125, v119)),
             _mm_mul_ps(v116->m_rotation.m_vec.m_quad, v122));
    v128 = _mm_sub_ps(
             _mm_mul_ps(v122, v119),
             _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v126, v126, 85), _mm_shuffle_ps(v126, v126, 0)),
               _mm_shuffle_ps(v126, v126, 170)));
    v129 = _mm_mul_ps(v116->m_scale.m_quad, v115);
    v130 = _mm_shuffle_ps(v127, _mm_unpackhi_ps(v127, v128), 196);
    toMatrixWS.v0 = (UFG::qVector4)*v50;
    hkQuaternionf::set((hkQuaternionf *)&toMatrixWS.v1, (hkRotationf *)&matrixWS);
    toMatrixWS.v2 = (UFG::qVector4)v50[2];
    SkeletalPose::SetRoot(v15, (hkQsTransformf *)&toMatrixWS, 0);
    v131 = SkeletalPose::GetRoot(v15);
    hkVector4f::setRotatedInverseDir(&v212, &v131->m_rotation, &v131->m_translation);
    v132 = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
    v133 = (__m128)_mm_shuffle_epi32(v132, 0);
    v134 = (__m128)_mm_shuffle_epi32(v132, 64);
    v135 = v131->m_scale.m_quad;
    v136 = _mm_xor_ps(v134, v131->m_rotation.m_vec.m_quad);
    v137 = _mm_rcp_ps(v135);
    v138 = _mm_shuffle_ps(v136, v136, 255);
    v139 = _mm_mul_ps(_mm_shuffle_ps(v130, v130, 201), v136);
    v140 = _mm_shuffle_ps(v136, v136, 201);
    v141 = (__m128)_mm_srli_si128(
                     _mm_slli_si128((__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v135, v137)), v137), 4),
                     4);
    v142 = _mm_mul_ps(v136, v123);
    v143 = _mm_mul_ps(v141, v129);
    v144 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v123, v123, 201), v136), _mm_mul_ps(v123, v140));
    v145 = _mm_add_ps(
             _mm_add_ps(_mm_shuffle_ps(v142, v142, 85), _mm_shuffle_ps(v142, v142, 0)),
             _mm_shuffle_ps(v142, v142, 170));
    v146 = v136;
    v147 = _mm_mul_ps(v145, v136);
    v148 = _mm_mul_ps(v136, v130);
    v149 = _mm_add_ps(
             _mm_add_ps(v147, _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v138, v138), (__m128)xmmword_141A711B0), v123)),
             _mm_mul_ps(_mm_shuffle_ps(v144, v144, 201), v138));
    v150 = _mm_shuffle_ps(v130, v130, 255);
    v151 = _mm_sub_ps(v139, _mm_mul_ps(v130, v140));
    v152 = _mm_add_ps(_mm_add_ps(v149, v149), _mm_xor_ps(v212.m_quad, v133));
    v153 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v151, v151, 201), _mm_mul_ps(v130, v138)), _mm_mul_ps(v146, v150));
    v154 = _mm_shuffle_ps(
             v153,
             _mm_unpackhi_ps(
               v153,
               _mm_sub_ps(
                 _mm_mul_ps(v150, v138),
                 _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v148, v148, 85), _mm_shuffle_ps(v148, v148, 0)),
                   _mm_shuffle_ps(v148, v148, 170)))),
             196);
    v155 = v7->mPose.mHavokPose;
    v156 = 1i64;
    v157 = v155->m_skeleton;
    v214 = v143;
    v158 = 1i64;
    v159 = v157->m_bones.m_size;
    *v155->m_boneFlags.m_data |= 4u;
    v160 = (__m128 *)v159;
    v207 = (__m128 *)v159;
    if ( v159 > 1 )
    {
      v161 = 1i64;
      do
      {
        LOWORD(v162) = v155->m_skeleton->m_parentIndices.m_data[v158];
        if ( (_WORD)v162 != -1 )
        {
          v163 = v155->m_boneFlags.m_data;
          if ( v163[(signed __int16)v162] & 4 )
          {
            if ( v163[v158] & 1 )
            {
              v164 = v155->m_modelPose.m_data;
              v210 = v155->m_modelPose.m_data;
              if ( (_WORD)v162 == -1 )
              {
                v186 = v155->m_localPose.m_data;
                v186[v161].m_translation = v164[v161].m_translation;
                v186[v161].m_rotation = v164[v161].m_rotation;
                v186[v161].m_scale = v164[v161].m_scale;
              }
              else
              {
                v162 = (signed __int16)v162;
                if ( v163[(signed __int16)v162] & 2 )
                  v165 = hkaPose::calculateBoneModelSpace(v155, v162);
                else
                  v165 = &v164[v162];
                v166 = v155->m_localPose.m_data;
                v167 = &v165->m_rotation.m_vec.m_quad;
                *(_QWORD *)&result[0].mUID = v165;
                hkVector4f::setRotatedInverseDir(&v212, &v165->m_rotation, &v165->m_translation);
                v168 = _mm_xor_ps(*v167, v134);
                v169 = *(__m128 *)(*(_QWORD *)&result[0].mUID + 32i64);
                v170 = (__int64)v210;
                v171 = _mm_shuffle_ps(v168, v168, 255);
                v172 = _mm_shuffle_ps(v168, v168, 201);
                v173 = v210[v161].m_translation.m_quad;
                v174 = _mm_rcp_ps(v169);
                v175 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v173, v173, 201), v168), _mm_mul_ps(v172, v173));
                v176 = _mm_slli_si128((__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v169, v174)), v174), 4);
                v177 = _mm_mul_ps(v168, v173);
                v178 = _mm_add_ps(
                         _mm_add_ps(
                           _mm_mul_ps(
                             _mm_add_ps(
                               _mm_add_ps(_mm_shuffle_ps(v177, v177, 85), _mm_shuffle_ps(v177, v177, 0)),
                               _mm_shuffle_ps(v177, v177, 170)),
                             v168),
                           _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v171, v171), (__m128)xmmword_141A711B0), v173)),
                         _mm_mul_ps(_mm_shuffle_ps(v175, v175, 201), v171));
                v166[v161].m_translation.m_quad = _mm_add_ps(_mm_add_ps(v178, v178), _mm_xor_ps(v212.m_quad, v133));
                v179 = *(__m128 *)(v170 + v161 * 48 + 16);
                v180 = _mm_shuffle_ps(*(__m128 *)(v170 + v161 * 48 + 16), v179, 255);
                v181 = _mm_mul_ps(v168, v180);
                v182 = _mm_mul_ps(_mm_shuffle_ps(v179, v179, 201), v168);
                v183 = _mm_mul_ps(v168, v179);
                v184 = _mm_sub_ps(v182, _mm_mul_ps(*(__m128 *)(v170 + v161 * 48 + 16), v172));
                v185 = _mm_add_ps(
                         _mm_add_ps(
                           _mm_shuffle_ps(v184, v184, 201),
                           _mm_mul_ps(*(__m128 *)(v170 + v161 * 48 + 16), v171)),
                         v181);
                v160 = v207;
                v166[v161].m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                                       v185,
                                                       _mm_unpackhi_ps(
                                                         v185,
                                                         _mm_sub_ps(
                                                           _mm_mul_ps(v180, v171),
                                                           _mm_add_ps(
                                                             _mm_add_ps(
                                                               _mm_shuffle_ps(v183, v183, 85),
                                                               _mm_shuffle_ps(v183, v183, 0)),
                                                             _mm_shuffle_ps(v183, v183, 170)))),
                                                       196);
                v166[v161].m_scale.m_quad = _mm_mul_ps(
                                              *(__m128 *)(v170 + v161 * 48 + 32),
                                              (__m128)_mm_srli_si128(v176, 4));
              }
              v155->m_boneFlags.m_data[v158] &= 0xFFFFFFFE;
            }
            v155->m_boneFlags.m_data[v158] |= 4u;
            v155->m_modelInSync.m_bool = 0;
          }
        }
        ++v158;
        ++v161;
      }
      while ( v158 < (signed __int64)v160 );
      v143 = v214;
      v156 = 1i64;
    }
    if ( (signed __int64)v160 > 1 )
    {
      do
      {
        v187 = v155->m_boneFlags.m_data;
        v188 = v187[v156];
        if ( v188 & 4 )
          v187[v156] = v188 & 0xFFFFFFFB | 2;
        ++v156;
      }
      while ( v156 < (signed __int64)v160 );
    }
    v189 = &v155->m_localPose.m_data->m_translation.m_quad;
    v12 = v208;
    *v189 = v152;
    v189[1] = v154;
    v189[2] = v143;
    *v155->m_boneFlags.m_data = 2;
    v155->m_modelInSync.m_bool = 0;
  }
  if ( sApplyDrivers )
  {
    v190 = 0i64;
    v191 = 0i64;
    v192 = (char *)&creature->m_SafePointerList;
    v193 = 0i64;
    v194 = creature->mPoseDrivers.mNode.mNext - 1;
    v195 = 0i64;
    v196 = 0i64;
    if ( v194 != (UFG::qNode<PoseDriver,PoseDriver> *)&creature->m_SafePointerList )
    {
      v197 = sLeftShoulderTwistUID;
      v198 = sRightShoulderTwistUID;
      do
      {
        if ( !v4 && HIDWORD(v194[2].mNext) == (_DWORD)v197 )
          v4 = v194;
        if ( !v190 && HIDWORD(v194[2].mNext) == (_DWORD)v198 )
          v190 = v194;
        if ( !v191 && HIDWORD(v194[2].mNext) == sLeftForearmTwistUID )
          v191 = v194;
        if ( !v193 && HIDWORD(v194[2].mNext) == sRightForearmTwistUID )
          v193 = v194;
        if ( !v196 && HIDWORD(v194[2].mNext) == sLeftArmIKUID )
          v196 = v194;
        if ( !v195 && HIDWORD(v194[2].mNext) == sRightArmIKUID )
          v195 = v194;
        v194 = v194[1].mNext - 1;
      }
      while ( v194 != (UFG::qNode<PoseDriver,PoseDriver> *)v192 );
      v11 = v209;
      v12 = v208;
      *(_QWORD *)&result[0].mUID = v191;
      if ( v4 )
      {
        LOBYTE(v192) = 1;
        ((void (__fastcall *)(UFG::qNode<PoseDriver,PoseDriver> *, char *, _QWORD, _QWORD))v4->mPrev[5].mNext)(
          v4,
          v192,
          sLeftShoulderTwistUID,
          sRightShoulderTwistUID);
      }
      if ( v190 )
      {
        LOBYTE(v192) = 1;
        ((void (__fastcall *)(UFG::qNode<PoseDriver,PoseDriver> *, char *, __int64, __int64))v190->mPrev[5].mNext)(
          v190,
          v192,
          v197,
          v198);
      }
      if ( *(_QWORD *)&result[0].mUID )
      {
        LOBYTE(v192) = 1;
        (*(void (__fastcall **)(_QWORD, char *, __int64, __int64))(**(_QWORD **)&result[0].mUID + 88i64))(
          *(_QWORD *)&result[0].mUID,
          v192,
          v197,
          v198);
      }
      if ( v193 )
      {
        LOBYTE(v192) = 1;
        ((void (__fastcall *)(UFG::qNode<PoseDriver,PoseDriver> *, char *, __int64, __int64))v193->mPrev[5].mNext)(
          v193,
          v192,
          v197,
          v198);
      }
    }
    LOBYTE(retaddr) = ((__int64 (__fastcall *)(UFG::qNode<PoseDriver,PoseDriver> *))v196->mPrev[5].mPrev)(v196);
    v205 = ((__int64 (__fastcall *)(UFG::qNode<PoseDriver,PoseDriver> *))v195->mPrev[5].mPrev)(v195);
    ((void (__fastcall *)(UFG::qNode<PoseDriver,PoseDriver> *, _QWORD))v196->mPrev[5].mNext)(v196, 0i64);
    ((void (__fastcall *)(UFG::qNode<PoseDriver,PoseDriver> *, _QWORD))v195->mPrev[5].mNext)(v195, 0i64);
    Creature::updateEffectorsToPose(creature);
    if ( v4 )
      ((void (__fastcall *)(UFG::qNode<PoseDriver,PoseDriver> *, _QWORD))v4->mPrev[5].mNext)(v4, 0i64);
    if ( v190 )
      ((void (__fastcall *)(UFG::qNode<PoseDriver,PoseDriver> *, _QWORD))v190->mPrev[5].mNext)(v190, 0i64);
    ((void (__fastcall *)(UFG::qNode<PoseDriver,PoseDriver> *, _QWORD))v196->mPrev[5].mNext)(
      v196,
      (unsigned __int8)retaddr);
    ((void (__fastcall *)(UFG::qNode<PoseDriver,PoseDriver> *, _QWORD))v195->mPrev[5].mNext)(v195, v205);
  }
  if ( v12 && v11 && sUseLowerBody )
  {
    updateAndApplyEffector(creature, v12, &worldTarget);
    updateAndApplyEffector(creature, v11, &v220);
  }
  Creature::UpdateAttachmentPoses(creature);
  v199 = (float *)&creature->mPose.mBoneUpdateCount;
  v200 = creature->mPose.mPoseAABBMin.y * 2.5;
  v201 = creature->mPose.mPoseAABBMin.z * 2.5;
  v202 = creature->mPose.mPoseAABBMax.x * 2.5;
  v203 = creature->mPose.mPoseAABBMax.y * 2.5;
  v204 = creature->mPose.mPoseAABBMax.z * 2.5;
  v199[34] = creature->mPose.mPoseAABBMin.x * 2.5;
  v199[35] = v200;
  v199[36] = v201;
  v199[37] = v202;
  v199[38] = v203;
  v199[39] = v204;
}

// File Line: 3051
// RVA: 0x3B6150
void __fastcall UnbindResourcesVisitor::Visit(UnbindResourcesVisitor *this, AnimationNode *pNode)
{
  AnimationGroupHandle::Unbind(&pNode->mAnimationGroupHandle);
}

// File Line: 3062
// RVA: 0x3B6140
void __fastcall RebindResourcesVisitor::Visit(RebindResourcesVisitor *this, AnimationNode *pNode)
{
  AnimationGroupHandle::Bind(&pNode->mAnimationGroupHandle);
}

// File Line: 3079
// RVA: 0x3B5520
void __fastcall PoseOnFrameBoundariesVisitor::Visit(PoseOnFrameBoundariesVisitor *this, AnimationNode *pNode)
{
  pNode->mPoseOnFrameBoundaries = this->mPoseOnFrameBoundaries;
}

// File Line: 3084
// RVA: 0x3A7A40
void __fastcall Creature::ForceSyncPose(Creature *this)
{
  Creature::UpdateAttachmentPoses(this);
}

// File Line: 3090
// RVA: 0x3B0410
void __fastcall Creature::UnbindResources(Creature *this)
{
  PoseNodeParent *v1; // rcx
  Expression::IMemberMapVtbl *v2; // rax
  void **v3; // [rsp+20h] [rbp-18h]
  char v4; // [rsp+28h] [rbp-10h]

  v1 = &this->mBlendTree;
  v3 = &UnbindResourcesVisitor::`vftable';
  v2 = v1->vfptr;
  v4 = 1;
  v2[1].FindWithOldPath((Expression::IMemberMap *)&v1->vfptr, (const char *)&v3);
}

// File Line: 3096
// RVA: 0x3AD960
void __fastcall Creature::RebindResources(Creature *this)
{
  PoseNodeParent *v1; // rcx
  Expression::IMemberMapVtbl *v2; // rax
  void **v3; // [rsp+20h] [rbp-18h]
  char v4; // [rsp+28h] [rbp-10h]

  v1 = &this->mBlendTree;
  v3 = &RebindResourcesVisitor::`vftable';
  v2 = v1->vfptr;
  v4 = 1;
  v2[1].FindWithOldPath((Expression::IMemberMap *)&v1->vfptr, (const char *)&v3);
}

// File Line: 3102
// RVA: 0x3AF620
void __fastcall Creature::SetPoseOnFrameBoundaries(Creature *this, bool val)
{
  PoseNodeParent *v2; // rcx
  Expression::IMemberMapVtbl *v3; // rax
  void **v4; // [rsp+20h] [rbp-28h]
  char v5; // [rsp+28h] [rbp-20h]
  bool v6; // [rsp+30h] [rbp-18h]

  v2 = &this->mBlendTree;
  v6 = val;
  v4 = &PoseOnFrameBoundariesVisitor::`vftable';
  v3 = v2->vfptr;
  v5 = 1;
  v3[1].FindWithOldPath((Expression::IMemberMap *)&v2->vfptr, (const char *)&v4);
}

// File Line: 3109
// RVA: 0x3AAE60
void __fastcall Creature::InitWeightSet(Creature *this, const char *weightSetNameFile)
{
  Skeleton *v2; // rbx

  v2 = this->mPose.mRigHandle.mUFGSkeleton;
  if ( v2 )
  {
    if ( !v2->mWeightSetData )
      v2->mWeightSetData = WeightSetDataBase::LoadWeightSetGroup(
                             WeightSetDataBase::sWeightSetDataBase,
                             weightSetNameFile);
  }
}

// File Line: 3126
// RVA: 0x3AA090
Weightset *__fastcall Creature::GetWeightSet(Creature *this, UFG::qSymbolUC *weightsetName)
{
  Skeleton *v2; // rcx

  v2 = this->mPose.mRigHandle.mUFGSkeleton;
  if ( v2 )
    JUMPOUT(v2->mWeightSetData, 0i64, WeightSetGroup::FindWeightset);
  return 0i64;
}

