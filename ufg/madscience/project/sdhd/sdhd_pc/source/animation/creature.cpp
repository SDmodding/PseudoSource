// File Line: 133
// RVA: 0x39DDF0
void __fastcall Creature::Creature(Creature *this, UFG::RigResource *rig)
{
  UFG::qSafePointerNode<Creature>::qSafePointerNode<Creature>(this);
  this->vfptr = (UFG::qSafePointerNode<Creature>Vtbl *)&Creature::`vftable;
  this->mPoseDrivers.mNode.mPrev = &this->mPoseDrivers.mNode;
  this->mPoseDrivers.mNode.mNext = &this->mPoseDrivers.mNode;
  this->mNetworkLock = 0;
  this->mPoseState = SYNCED;
  this->mAttachments.mNode.mPrev = &this->mAttachments.mNode;
  this->mAttachments.mNode.mNext = &this->mAttachments.mNode;
  this->mForceTransparencyTarget = -1;
  this->mPoseFrame = 0;
  this->mPoseTask = 0i64;
  this->mCurrentStackDepth = 0;
  this->mCorrected = 0;
  SkeletalPose::SkeletalPose(&this->mPose, rig);
  PoseNode::PoseNode(&this->mBlendTree);
  this->mBlendTree.vfptr = (Expression::IMemberMapVtbl *)&PoseNodeParent::`vftable{for `Expression::IMemberMap};
  this->mBlendTree.vfptr = (UFG::qSafePointerNode<PoseNode>Vtbl *)&PoseNodeParent::`vftable{for `UFG::qSafePointerNode<PoseNode>};
  this->mBlendTree.mChildrenSerialized.mCount = 0;
  this->mBlendTree.mChildrenSerialized.mData.mOffset = 0i64;
  this->mBlendTree.mChildren.mNode.mPrev = &this->mBlendTree.mChildren.mNode;
  this->mBlendTree.mChildren.mNode.mNext = &this->mBlendTree.mChildren.mNode;
  this->mBlendTree.mLocalTime = 0.0;
  *(_WORD *)&this->mHaventUpdated = 1;
  this->mRestPosePrev = 0;
  this->mPoseTaskParams.mRecipe.mBoneUpdateCount = -1;
  *(_QWORD *)&this->mPoseTaskParams.mRecipe.mStackCount = 0i64;
  *(_QWORD *)&this->mPoseTaskParams.mRecipe.mAnimMemoryHighWaterMark = 0i64;
  this->mPoseTaskParams.mRecipe.mPoseStack = 0i64;
  this->mPoseTaskParams.mRecipe.mAnimData = 0i64;
  this->mIsSlopeLocomotionFixupEnabled = 0;
  this->mMaxSlopeLocomotionFixupAngle = 0.70700002;
  this->mPlaybackSpeedEnabled = 0;
  this->mPlaybackSpeed = 1.0;
  this->mRagdollBlendWeight = 1.0;
  this->mNetPoseSequence = 0;
  Creature::CommonInit(this);
}

// File Line: 137
// RVA: 0x14BD240
__int64 dynamic_initializer_for__gsymBlendTreeRoot__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("BlendTreeRoot", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&gsymBlendTreeRoot, v0);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gsymBlendTreeRoot__);
}

// File Line: 140
// RVA: 0x3A5300
void __fastcall Creature::CommonInit(Creature *this)
{
  UFG::qVector4 v2; // xmm2
  UFG::qVector4 v3; // xmm1
  UFG::qVector4 v4; // xmm2
  UFG::qVector4 v5; // xmm3

  this->mGroundNormal.z = 1.0;
  *(_QWORD *)&this->mGroundNormal.x = 0i64;
  SkeletalPose::SetToRestPose(&this->mPose);
  this->mPoseCRC = -1;
  v2 = 0i64;
  this->mBlendTree.mName.mUID = gsymBlendTreeRoot.mUID;
  this->mIsAttached = 0;
  v2.x = (float)1;
  this->mAbsoluteMon.v0 = v2;
  this->mAbsoluteMon.v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v2, (__m128)v2, 81);
  this->mAbsoluteMon.v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v2, (__m128)v2, 69);
  this->mAbsoluteMon.v3 = (UFG::qVector4)_mm_shuffle_ps((__m128)v2, (__m128)v2, 21);
  this->mAbsoluteMonSet = 0;
  this->mLastSetPosition.m_translation = 0i64;
  this->mLastSetPosition.m_rotation = (hkQuaternionf)qi.m_vec.m_quad;
  this->mLastSetPosition.m_scale = (hkVector4f)query.m_quad;
  UFG::qMemSet(this->mIsEndEffectorCache, 0, 4u);
  this->mAbsoluteRelativeRootMotion = 0;
  v3 = UFG::qMatrix44::msIdentity.v1;
  v4 = UFG::qMatrix44::msIdentity.v2;
  v5 = UFG::qMatrix44::msIdentity.v3;
  this->mAbsoluteRelativeRoot.v0 = UFG::qMatrix44::msIdentity.v0;
  this->mAbsoluteRelativeRoot.v1 = v3;
  this->mAbsoluteRelativeRoot.v2 = v4;
  this->mAbsoluteRelativeRoot.v3 = v5;
  this->mDisablePosedrivers = 0;
}

// File Line: 177
// RVA: 0x39F840
void __fastcall Creature::~Creature(Creature *this)
{
  UFG::qList<PoseDriver,PoseDriver,1,0> *p_mPoseDrivers; // rdi
  Creature *i; // rax
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> **p_mNext; // rdx
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *mNext; // rcx
  UFG::qNode<PoseDriver,PoseDriver> *mPrev; // rax
  UFG::qNode<Attachment,Attachment> *v7; // rcx
  UFG::qNode<Attachment,Attachment> *v8; // rax
  UFG::qNode<PoseDriver,PoseDriver> *v9; // rcx
  UFG::qNode<PoseDriver,PoseDriver> *v10; // rax
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v12; // rax

  this->vfptr = (UFG::qSafePointerNode<Creature>Vtbl *)&Creature::`vftable;
  Creature::WaitOnPoseTask(this);
  p_mPoseDrivers = &this->mPoseDrivers;
  for ( i = (Creature *)&this->mPoseDrivers.mNode.mNext[-1];
        i != (Creature *)&this->m_SafePointerList;
        i = (Creature *)&this->mPoseDrivers.mNode.mNext[-1] )
  {
    p_mNext = &i->m_SafePointerList.mNode.mNext;
    mNext = i->m_SafePointerList.mNode.mNext;
    mPrev = i->mPoseDrivers.mNode.mPrev;
    mNext->mNext = (UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *)mPrev;
    mPrev->mPrev = (UFG::qNode<PoseDriver,PoseDriver> *)mNext;
    *p_mNext = (UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *)p_mNext;
    p_mNext[1] = (UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *)p_mNext;
    if ( p_mNext != (UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> **)16 )
      ((void (__fastcall *)(UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> **, __int64))(*(p_mNext - 2))->mNext)(
        p_mNext - 2,
        1i64);
  }
  PoseNodeParent::~PoseNodeParent(&this->mBlendTree);
  SkeletalPose::~SkeletalPose(&this->mPose);
  UFG::qList<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption,1,0>::DeleteNodes((UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)&this->mAttachments);
  v7 = this->mAttachments.mNode.mPrev;
  v8 = this->mAttachments.mNode.mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->mAttachments.mNode.mPrev = &this->mAttachments.mNode;
  this->mAttachments.mNode.mNext = &this->mAttachments.mNode;
  UFG::qList<WeightSetGroup,WeightSetGroup,1,0>::DeleteNodes((UFG::qList<ActionRequestDebug,ActionRequestDebug,1,0> *)&this->mPoseDrivers);
  v9 = p_mPoseDrivers->mNode.mPrev;
  v10 = this->mPoseDrivers.mNode.mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  p_mPoseDrivers->mNode.mPrev = &p_mPoseDrivers->mNode;
  this->mPoseDrivers.mNode.mNext = &this->mPoseDrivers.mNode;
  this->vfptr = (UFG::qSafePointerNode<Creature>Vtbl *)&UFG::qSafePointerNode<Creature>::`vftable;
  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull((UFG::qSafePointerNode<UFG::ParkourHandle> *)this);
  UFG::qList<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList,1,0>::DeleteNodes((UFG::qList<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList,1,0> *)&this->m_SafePointerList);
  v11 = this->m_SafePointerList.mNode.mPrev;
  v12 = this->m_SafePointerList.mNode.mNext;
  v11->mNext = v12;
  v12->mPrev = v11;
  this->m_SafePointerList.mNode.mPrev = &this->m_SafePointerList.mNode;
  this->m_SafePointerList.mNode.mNext = &this->m_SafePointerList.mNode;
}

// File Line: 195
// RVA: 0x3A6A60
void __fastcall Creature::Destroy(Creature *this)
{
  Creature::WaitOnPoseTask(this);
  if ( this )
    this->vfptr->__vecDelDtor(this, 1i64);
}

// File Line: 208
// RVA: 0x3AC7A0
PoseNode *__fastcall Creature::PlayAnimation(
        Creature *this,
        UFG::qSymbolUC *animName,
        AnimationPlayMode playMode,
        float startTime,
        float endTime,
        float blendInTime,
        bool phaseIn,
        int *returnCode)
{
  char *v11; // rax
  PoseNode *v12; // rax
  PoseNode *v13; // rbx
  SkeletalAnimation *vfptr; // rcx
  UFG::qMatrix44 outMatrix; // [rsp+50h] [rbp-68h] BYREF

  v11 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x170ui64, "Creature.newActiveBranch", 0i64, 1u);
  if ( v11 )
  {
    AnimationNode::AnimationNode((AnimationNode *)v11, animName, playMode, startTime, endTime);
    v13 = v12;
  }
  else
  {
    v13 = 0i64;
  }
  vfptr = (SkeletalAnimation *)v13[2].Expression::IMemberMap::vfptr;
  if ( vfptr && playMode == APM_ABSOLUTE && SkeletalAnimation::GetAnimationRootOrigin(vfptr, &outMatrix) )
  {
    SkeletalPose::SetRoot(&this->mPose, &outMatrix, 1);
    this->mAbsoluteMon = outMatrix;
    this->mAbsoluteMonSet = 1;
  }
  Creature::PlayBlendTree(this, v13, 0, blendInTime, phaseIn, startTime, endTime, returnCode);
  return v13;
}

// File Line: 239
// RVA: 0x3AC8F0
PoseNode *__fastcall Creature::PlayBlendTree(
        Creature *this,
        UFG::qSymbolUC *treeName,
        int priority,
        float blendInTime,
        bool phaseIn,
        float startTime,
        float endTime,
        int *returnCode)
{
  unsigned int size; // r9d
  int v11; // r10d
  int v12; // r9d
  BlendTreeDataBase::PoseNodeLookupEntry *p; // r11
  unsigned int mUID; // r8d
  unsigned int v15; // eax
  unsigned int v16; // edx
  PoseNode *mpPoseNode; // rcx
  PoseNode *v19; // rax

  size = BlendTreeDataBase::sBlendTreeDataBase->mPoseNodeLookup.size;
  if ( !size )
    return 0i64;
  v11 = 0;
  v12 = size - 1;
  if ( v12 < 0 )
    return 0i64;
  p = BlendTreeDataBase::sBlendTreeDataBase->mPoseNodeLookup.p;
  mUID = treeName->mUID;
  while ( 1 )
  {
    v15 = (v12 + v11) / 2;
    v16 = p[v15].mName.mUID;
    if ( mUID <= v16 )
      break;
    v11 = v15 + 1;
LABEL_8:
    if ( v11 > v12 )
      return 0i64;
  }
  if ( mUID < v16 )
  {
    v12 = v15 - 1;
    goto LABEL_8;
  }
  mpPoseNode = p[(v12 + v11) / 2].mpPoseNode;
  if ( !mpPoseNode )
    return 0i64;
  v19 = (PoseNode *)((__int64 (__fastcall *)(PoseNode *))mpPoseNode->Expression::IMemberMap::vfptr[1].Serialize)(mpPoseNode);
  return Creature::PlayBlendTree(this, v19, priority, blendInTime, phaseIn, startTime, endTime, returnCode);
}

// File Line: 250
// RVA: 0x3ACB90
PoseNode *__fastcall Creature::PlayBlendTree(
        Creature *this,
        PoseNode *blendTree,
        PoseNodeParent *blendTreeParent,
        unsigned int priority,
        bool phaseIn,
        float startTime,
        float endTime,
        int *returnCode)
{
  Expression::IMemberMapVtbl *vfptr; // rax
  PoseNodeParent *p_mBlendTree; // rdi
  int v15; // eax
  PoseNodeParent *v16; // rcx
  bool v17; // cc
  Expression::IMemberMapVtbl *v18; // rax
  __int64 v19; // rax
  __int64 v20; // rax
  __int64 v21; // rsi
  __int64 v22; // rax
  __int64 v23; // r15
  UFG::qNode<PoseNode,PoseNode> *v24; // rax
  __int64 v25; // rax
  UFG::qOffset64<PoseNodeParent *> *p_mParent; // rcx
  __int64 v27; // rax
  __int64 v28; // rax
  Expression::IMemberMapVtbl *v29; // rax
  PoseNodeParent *v30; // rcx
  Expression::IMemberMapVtbl *v31; // rax
  void **v32; // [rsp+20h] [rbp-78h] BYREF
  char v33; // [rsp+28h] [rbp-70h]
  __int64 dest[4]; // [rsp+30h] [rbp-68h] BYREF
  void **v35; // [rsp+50h] [rbp-48h] BYREF
  char v36; // [rsp+58h] [rbp-40h]
  char v37[56]; // [rsp+60h] [rbp-38h] BYREF

  *returnCode = 0;
  if ( this->mNetworkLock )
    return 0i64;
  if ( blendTree )
  {
    blendTree->Expression::IMemberMap::vfptr[4].__vecDelDtor(blendTree, priority);
    ((void (__fastcall *)(PoseNode *))blendTree->Expression::IMemberMap::vfptr[3].GetResourcePath)(blendTree);
    if ( endTime >= 0.0 )
    {
      v32 = &AnimationNode_SetPlayEndTime::`vftable;
      vfptr = blendTree->Expression::IMemberMap::vfptr;
      *(float *)dest = endTime;
      v33 = 1;
      vfptr[1].FindWithOldPath(blendTree, (const char *)&v32);
    }
    p_mBlendTree = &this->mBlendTree;
    v15 = (int)this->mBlendTree.vfptr[1].CreateClone(&this->mBlendTree);
    v16 = &this->mBlendTree;
    v17 = v15 <= 0;
    v18 = this->mBlendTree.vfptr;
    if ( !v17 )
    {
      v19 = (__int64)v18[1].__vecDelDtor(v16, 0);
      v20 = (*(__int64 (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v19 + 312i64))(v19, priority);
      v21 = v20;
      if ( v20 )
      {
        v22 = *(_QWORD *)(v20 + 56);
        if ( v22 )
          v23 = v22 + v21 + 56;
        else
          v23 = 0i64;
        if ( blendTreeParent )
        {
          blendTreeParent->PoseNode::Expression::IMemberMap::vfptr[4].__vecDelDtor(blendTreeParent, priority);
          v24 = *(UFG::qNode<PoseNode,PoseNode> **)(v21 + 40);
          v24->mNext = &blendTreeParent->UFG::qNode<PoseNode,PoseNode>;
          blendTreeParent->mPrev = v24;
          blendTreeParent->mNext = (UFG::qNode<PoseNode,PoseNode> *)(v21 + 40);
          *(_QWORD *)(v21 + 40) = &blendTreeParent->UFG::qNode<PoseNode,PoseNode>;
          v25 = *(_QWORD *)(v21 + 56);
          p_mParent = &blendTreeParent->mParent;
          if ( v25 && (v27 = v21 + v25 + 56) != 0 )
            v28 = v27 - (_QWORD)p_mParent;
          else
            v28 = 0i64;
          p_mParent->mOffset = v28;
          (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v23 + 384i64))(v23, v21);
          ((void (__fastcall *)(PoseNodeParent *, __int64))blendTreeParent->PoseNode::Expression::IMemberMap::vfptr[4].GetClassNameUID)(
            blendTreeParent,
            v21);
          v29 = blendTreeParent->PoseNode::Expression::IMemberMap::vfptr;
          v30 = blendTreeParent;
        }
        else
        {
          (*(void (__fastcall **)(__int64))(*(_QWORD *)v23 + 392i64))(v23);
          v29 = p_mBlendTree->PoseNode::Expression::IMemberMap::vfptr;
          v30 = &this->mBlendTree;
        }
        ((void (__fastcall *)(PoseNodeParent *, PoseNode *))v29[4].GetClassNameUID)(v30, blendTree);
        v33 = 1;
        v32 = &BlendDirectionNode_GetBlendDirection::`vftable;
        UFG::qMemSet(dest, 0, 0x20u);
        (*(void (__fastcall **)(__int64, void ***))(*(_QWORD *)v21 + 80i64))(v21, &v32);
        v35 = &BlendDirectionNode_SetBlendDirection::`vftable;
        v36 = 1;
        UFG::qMemCopy(v37, dest, 0x20u);
        blendTree->Expression::IMemberMap::vfptr[1].FindWithOldPath(blendTree, (const char *)&v35);
        goto LABEL_21;
      }
      v18 = p_mBlendTree->PoseNode::Expression::IMemberMap::vfptr;
      v16 = &this->mBlendTree;
    }
    v18[4].GetResourceOwner(v16);
    ((void (__fastcall *)(PoseNodeParent *, PoseNode *))p_mBlendTree->PoseNode::Expression::IMemberMap::vfptr[4].GetClassNameUID)(
      &this->mBlendTree,
      blendTree);
LABEL_21:
    v32 = &PoseStackCalculatorVisitor::`vftable;
    v31 = blendTree->Expression::IMemberMap::vfptr;
    v33 = 1;
    dest[0] = 0i64;
    v31[1].FindWithOldPath(blendTree, (const char *)&v32);
    this->mCurrentStackDepth += LODWORD(dest[0]);
  }
  Creature::pruneBigBlendTree(this);
  return blendTree;
}

// File Line: 359
// RVA: 0x3AC9B0
PoseNode *__fastcall Creature::PlayBlendTree(
        Creature *this,
        PoseNode *blendTree,
        unsigned int priority,
        float blendInTime,
        bool phaseIn,
        float startTime,
        float endTime,
        int *returnCode)
{
  Expression::IMemberMapVtbl *vfptr; // rax
  int v13; // eax
  PoseNodeParent *p_mBlendTree; // rcx
  bool v15; // cc
  Expression::IMemberMapVtbl *v16; // rax
  PoseNode *v17; // rdi
  __int64 v18; // rax
  void **v19; // [rsp+20h] [rbp-88h] BYREF
  char v20; // [rsp+28h] [rbp-80h]
  __int64 dest[4]; // [rsp+30h] [rbp-78h] BYREF
  void **v22; // [rsp+50h] [rbp-58h] BYREF
  char v23; // [rsp+58h] [rbp-50h]
  char v24[32]; // [rsp+60h] [rbp-48h] BYREF

  if ( this->mNetworkLock )
    return 0i64;
  if ( blendTree )
  {
    blendTree->Expression::IMemberMap::vfptr[4].__vecDelDtor(blendTree, priority);
    if ( startTime >= 0.0 )
      ((void (__fastcall *)(PoseNode *))blendTree->Expression::IMemberMap::vfptr[3].GetResourcePath)(blendTree);
    if ( endTime >= 0.0 )
    {
      v19 = &AnimationNode_SetPlayEndTime::`vftable;
      vfptr = blendTree->Expression::IMemberMap::vfptr;
      *(float *)dest = endTime;
      v20 = 1;
      vfptr[1].FindWithOldPath(blendTree, (const char *)&v19);
    }
    v13 = (int)this->mBlendTree.vfptr[1].CreateClone(&this->mBlendTree);
    p_mBlendTree = &this->mBlendTree;
    v15 = v13 <= 0;
    v16 = this->mBlendTree.vfptr;
    if ( v15 )
    {
      v16[4].GetResourceOwner(p_mBlendTree);
      ((void (__fastcall *)(PoseNodeParent *, PoseNode *))this->mBlendTree.vfptr[4].GetClassNameUID)(
        &this->mBlendTree,
        blendTree);
    }
    else
    {
      v17 = (PoseNode *)v16[1].__vecDelDtor(p_mBlendTree, 0);
      v18 = ((__int64 (__fastcall *)(PoseNode *, _QWORD))v17->Expression::IMemberMap::vfptr[3].GetResourceOwner)(
              v17,
              priority);
      if ( v18 )
        v17 = (PoseNode *)v18;
      PoseNode::BlendIn(v17, blendTree, blendInTime, phaseIn);
      v20 = 1;
      v19 = &BlendDirectionNode_GetBlendDirection::`vftable;
      UFG::qMemSet(dest, 0, 0x20u);
      v17->Expression::IMemberMap::vfptr[1].FindWithOldPath(v17, (const char *)&v19);
      v22 = &BlendDirectionNode_SetBlendDirection::`vftable;
      v23 = 1;
      UFG::qMemCopy(v24, dest, 0x20u);
      blendTree->Expression::IMemberMap::vfptr[1].FindWithOldPath(blendTree, (const char *)&v22);
    }
    v19 = &PoseStackCalculatorVisitor::`vftable;
    v20 = 1;
    dest[0] = 0i64;
    blendTree->Expression::IMemberMap::vfptr[1].FindWithOldPath(blendTree, (const char *)&v19);
    this->mCurrentStackDepth += LODWORD(dest[0]);
  }
  Creature::pruneBigBlendTree(this);
  return blendTree;
}

// File Line: 447
// RVA: 0x3B7CC0
char __fastcall Creature::pruneBigBlendTree(Creature *this)
{
  PoseNodeParent *p_mBlendTree; // rbx
  Expression::IMemberMapVtbl *vfptr; // rax
  __int64 v4; // rdx
  unsigned int v5; // eax
  unsigned int v6; // edi
  Expression::IMemberMapVtbl *v7; // rax
  unsigned int v8; // eax
  unsigned int v9; // eax
  void **v11; // [rsp+20h] [rbp-38h] BYREF
  char v12; // [rsp+28h] [rbp-30h]
  __int64 v13; // [rsp+30h] [rbp-28h]

  if ( this->mCurrentStackDepth < sMaxBlendTreeDepth )
    return 0;
  p_mBlendTree = &this->mBlendTree;
  if ( (__int64)this->mBlendTree.vfptr[1].CreateClone(&this->mBlendTree) > 0 )
  {
    p_mBlendTree->PoseNode::Expression::IMemberMap::vfptr[1].__vecDelDtor(p_mBlendTree, 0);
    v11 = &PoseStackCalculatorVisitor::`vftable;
    vfptr = p_mBlendTree->PoseNode::Expression::IMemberMap::vfptr;
    v12 = 1;
    v13 = 0i64;
    vfptr[1].FindWithOldPath(p_mBlendTree, (const char *)&v11);
    v5 = v13;
    v6 = 0;
    this->mCurrentStackDepth = v13;
    if ( v5 >= sMaxBlendTreeDepth )
    {
      do
      {
        if ( v6 >= sMaxIteractions )
          break;
        ++v6;
        ((void (__fastcall *)(PoseNodeParent *, __int64, _QWORD))p_mBlendTree->PoseNode::Expression::IMemberMap::vfptr[1].GetClassNameUID)(
          p_mBlendTree,
          v4,
          0i64);
        v7 = p_mBlendTree->PoseNode::Expression::IMemberMap::vfptr;
        v13 = 0i64;
        v7[1].FindWithOldPath(p_mBlendTree, (const char *)&v11);
        v8 = v13;
        this->mCurrentStackDepth = v13;
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
    this->mBlendTree.vfptr[4].GetResourceOwner(&this->mBlendTree);
}

// File Line: 506
// RVA: 0x3B13F0
void __fastcall Creature::Update(Creature *this, float deltaTime, __int64 a3)
{
  __int64 v3; // rdx
  float mPlaybackSpeed; // xmm6_4
  float v6; // xmm6_4
  Creature *v7; // rcx
  Creature *v8; // rbx

  if ( gAnimCharEnable )
  {
    if ( this->mPlaybackSpeedEnabled )
      mPlaybackSpeed = this->mPlaybackSpeed;
    else
      mPlaybackSpeed = *(float *)&FLOAT_1_0;
    v6 = mPlaybackSpeed * deltaTime;
    LOBYTE(a3) = 1;
    ((void (__fastcall *)(PoseNodeParent *, __int64, __int64))this->mBlendTree.vfptr[1].GetClassNameUID)(
      &this->mBlendTree,
      v3,
      a3);
    Creature::updateAnimatedMovement(this, v6);
    Creature::updateAttachments(this, v6);
    v7 = (Creature *)&this->mPoseDrivers.mNode.mNext[-1];
    if ( v7 != (Creature *)&this->m_SafePointerList )
    {
      do
      {
        v8 = (Creature *)&v7->mPoseDrivers.mNode.mPrev[-1];
        ((void (__fastcall *)(Creature *))v7->vfptr[16].__vecDelDtor)(v7);
        v7 = v8;
      }
      while ( v8 != (Creature *)&this->m_SafePointerList );
    }
    this->mPlaybackSpeed = 1.0;
  }
}

// File Line: 583
// RVA: 0x3AD290
void __fastcall Creature::PrepPoseTaskInput(Creature *this, PoseNode *tree)
{
  unsigned int v2; // edi
  hkaSkeleton *mhkaSkeleton; // r8
  int m_size; // eax
  hkaBone *m_data; // r9
  hkQsTransformf *v8; // r10
  const unsigned __int16 *v9; // r11
  int mBoneUpdateCount; // eax
  bool v11; // bp
  unsigned int v12; // r12d
  PoseRecipe *mRecipe; // rax
  unsigned int mStackCount; // eax
  unsigned int v15; // ecx
  int v16; // eax
  unsigned int v17; // ebx
  __int64 v18; // rdx
  PoseRecipe::PoseStackEntry *v19; // r8
  int mType; // eax
  unsigned int v21; // ecx
  unsigned int v22; // esi
  unsigned int v23; // eax
  hkaPose *mHavokPose; // rcx
  char *v25; // rax
  unsigned int v26; // edx
  signed int v27; // eax
  __int64 v28; // r8
  PoseRecipe::PoseStackEntry *v29; // rcx
  int v30; // eax
  unsigned int v31; // edi
  __int64 v32; // [rsp+20h] [rbp-1BD8h]
  PoseRecipeVisitor v33; // [rsp+40h] [rbp-1BB8h] BYREF
  int v34; // [rsp+1C00h] [rbp+8h]

  v2 = 0;
  mhkaSkeleton = this->mPose.mRigHandle.mUFGSkeleton->mhkaSkeleton;
  m_size = mhkaSkeleton->m_bones.m_size;
  m_data = mhkaSkeleton->m_bones.m_data;
  v8 = mhkaSkeleton->m_referencePose.m_data;
  v9 = (const unsigned __int16 *)mhkaSkeleton->m_parentIndices.m_data;
  v33.mRecipe = &this->mPoseTaskParams.mRecipe;
  v33.mRecurse = 1;
  v34 = m_size;
  LODWORD(v32) = m_size;
  *(_QWORD *)&this->mPoseTaskParams.mRecipe.mSkelDesc.mBoneCount = v32;
  mBoneUpdateCount = this->mPose.mBoneUpdateCount;
  this->mPoseTaskParams.mRecipe.mSkelDesc.mBones = m_data;
  this->mPoseTaskParams.mRecipe.mSkelDesc.mReferencePose = v8;
  this->mPoseTaskParams.mRecipe.mBoneUpdateCount = mBoneUpdateCount;
  this->mPoseTaskParams.mRecipe.mSkelDesc.mParentIndices = v9;
  v11 = 0;
  v12 = 0;
  v33.vfptr = (PoseNodeVisitorVtbl *)&PoseRecipeVisitor::`vftable;
  *(_QWORD *)&this->mPoseTaskParams.mRecipe.mStackCount = 0i64;
  this->mPoseTaskParams.mRecipe.mBoneUpdateCount = -1;
  *(_QWORD *)&this->mPoseTaskParams.mRecipe.mAnimMemoryHighWaterMark = 0i64;
  this->mPoseTaskParams.mRecipe.mPoseStack = 0i64;
  this->mPoseTaskParams.mRecipe.mAnimData = 0i64;
  while ( 1 )
  {
    mRecipe = v33.mRecipe;
    v33.mIsValid = 1;
    *(_QWORD *)&v33.mStackCount = 0i64;
    *(_QWORD *)&v33.mRecipe->mStackCount = 0i64;
    mRecipe->mBoneUpdateCount = -1;
    *(_QWORD *)&mRecipe->mAnimMemoryHighWaterMark = 0i64;
    mRecipe->mPoseStack = 0i64;
    mRecipe->mAnimData = 0i64;
    tree->Expression::IMemberMap::vfptr[1].FindWithOldPath(tree, (const char *)&v33);
    mStackCount = v33.mStackCount;
    v15 = 0;
    this->mCurrentStackDepth = v33.mStackCount;
    v16 = mStackCount - 1;
    v17 = 0;
    v18 = v16;
    if ( v16 >= 0 )
    {
      v19 = &v33.mPoseStack[v16];
      do
      {
        mType = v19->mType;
        if ( v19->mType >= PoseDescType_RestPose )
        {
          if ( mType <= 1 )
          {
            if ( ++v15 > v17 )
              v17 = v15;
          }
          else if ( mType == 2 )
          {
            v21 = v15 + 2;
            if ( v21 > v17 )
              v17 = v21;
            v15 = v21 - 1;
          }
          else if ( (unsigned int)(mType - 3) <= 6 )
          {
            --v15;
          }
        }
        --v19;
        --v18;
      }
      while ( v18 >= 0 );
    }
    v22 = 48 * v34 * v17 + ((8 * v17 + 15) & 0xFFFFFFF0);
    if ( sActivatePrune )
    {
      v11 = !v33.mIsValid || v17 > 0x40 || v22 > 0x20000;
      if ( v12 > sMaxPruneOperations )
        break;
    }
    if ( !v11 )
      break;
    ++v12;
    ((void (__fastcall *)(PoseNode *, __int64, _QWORD))tree->Expression::IMemberMap::vfptr[1].GetClassNameUID)(
      tree,
      v18,
      0i64);
  }
  PoseRecipeVisitor::CommitAnimData(&v33);
  v23 = PoseRecipeVisitor::CommitData(&v33);
  mHavokPose = this->mPose.mHavokPose;
  this->mPoseTaskParams.mBufferCount = v17;
  this->mPoseCRC = v23;
  this->mPoseTaskParams.mBufferSize = v22;
  this->mPoseTaskParams.mOutputTransforms = hkaPose::accessUnsyncedPoseModelSpace(mHavokPose)->m_data;
  this->mPoseState = UPDATED;
  this->mPoseTaskParams.mBufferStride = 48 * v34;
  if ( !v33.mIsValid || this->mPoseTaskParams.mBufferCount > 0x40 || this->mPoseTaskParams.mBufferSize > 0x20000 )
  {
    *(_QWORD *)&this->mPoseTaskParams.mRecipe.mStackCount = 0i64;
    this->mPoseTaskParams.mRecipe.mBoneUpdateCount = -1;
    *(_QWORD *)&this->mPoseTaskParams.mRecipe.mAnimMemoryHighWaterMark = 0i64;
    this->mPoseTaskParams.mRecipe.mPoseStack = 0i64;
    this->mPoseTaskParams.mRecipe.mAnimData = 0i64;
    this->mPoseTaskParams.mRecipe.mStackCount = 1;
    v25 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10u, 0x10u);
    v26 = 0;
    this->mPoseTaskParams.mRecipe.mPoseStack = (PoseRecipe::PoseStackEntry *)v25;
    *(_DWORD *)v25 = 0;
    v27 = this->mPoseTaskParams.mRecipe.mStackCount - 1;
    v28 = v27;
    if ( v27 >= 0 )
    {
      v29 = &this->mPoseTaskParams.mRecipe.mPoseStack[v27];
      do
      {
        v30 = v29->mType;
        if ( v29->mType >= PoseDescType_RestPose )
        {
          if ( v30 <= 1 )
          {
            if ( ++v2 > v26 )
              v26 = v2;
          }
          else if ( v30 == 2 )
          {
            v31 = v2 + 2;
            if ( v31 > v26 )
              v26 = v31;
            v2 = v31 - 1;
          }
          else if ( (unsigned int)(v30 - 3) <= 6 )
          {
            --v2;
          }
        }
        --v29;
        --v28;
      }
      while ( v28 >= 0 );
    }
    this->mPoseTaskParams.mBufferCount = v26;
    this->mPoseTaskParams.mBufferSize = 48 * v34 * v26 + ((8 * v26 + 15) & 0xFFFFFFF0);
  }
}

// File Line: 700
// RVA: 0x3AFE90
void __fastcall Creature::SubmitPoseTask(Creature *this)
{
  unsigned int mPoseCRC; // eax
  PoseCache *v3; // rdi
  UFG::qTreeRB64<PoseCacheNode,PoseCacheNode,1> *v4; // rax
  UFG::qTreeRB64<PoseCacheNode,PoseCacheNode,1> *v5; // rsi
  UFG::qBaseNodeVariableRB<unsigned __int64> *mParent; // rdx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v7; // rcx
  UFG::qBaseNodeVariableRB<unsigned __int64> *p_mNULL; // r8
  UFG::qNode<PoseCacheNode,PoseCacheNode> *mPrev; // rax
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  unsigned int v14; // eax

  Creature::WaitOnPoseTask(this);
  if ( (__int64)this->mBlendTree.vfptr[1].CreateClone(&this->mBlendTree) > 0 )
  {
    Creature::PrepPoseTaskInput(this, &this->mBlendTree);
    mPoseCRC = this->mPoseCRC;
    if ( mPoseCRC != -1
      && this->mLowPowerModeEnabled
      && (v3 = PoseCache::sPoseCache, PoseCache::sPoseCache->mEnablePoseCache)
      && (v4 = PoseCache::Find(
                 PoseCache::sPoseCache,
                 LODWORD(this->mPose.mRigHandle.mUFGSkeleton) | ((unsigned __int64)mPoseCRC << 32)),
          (v5 = v4) != 0i64) )
    {
      mParent = v4->mTree.mNULL.mParent;
      v7 = v4->mTree.mNULL.mChild[0];
      p_mNULL = &v4->mTree.mNULL;
      mParent->mChild[0] = v7;
      v7->mParent = mParent;
      v4->mTree.mNULL.mParent = &v4->mTree.mNULL;
      v4->mTree.mNULL.mChild[0] = &v4->mTree.mNULL;
      mPrev = v3->mCachedDataList.mNode.mPrev;
      mPrev->mNext = (UFG::qNode<PoseCacheNode,PoseCacheNode> *)p_mNULL;
      p_mNULL->mParent = (UFG::qBaseNodeVariableRB<unsigned __int64> *)mPrev;
      p_mNULL->mChild[0] = (UFG::qBaseNodeVariableRB<unsigned __int64> *)&v3->mCachedDataList;
      v3->mCachedDataList.mNode.mPrev = (UFG::qNode<PoseCacheNode,PoseCacheNode> *)p_mNULL;
      UFG::qMemCopy(
        this->mPoseTaskParams.mOutputTransforms,
        v5->mTree.mNULL.mChild[1],
        this->mPoseTaskParams.mBufferStride);
      v10 = *((float *)&v5->mTree.mNULL.mUID + 1);
      v11 = *(float *)&v5->mTree.mCount;
      this->mPoseTaskParams.mOutputModelSpaceAABBMin.x = *(float *)&v5->mTree.mNULL.mUID;
      this->mPoseTaskParams.mOutputModelSpaceAABBMin.y = v10;
      this->mPoseTaskParams.mOutputModelSpaceAABBMin.z = v11;
      v12 = *(float *)&v5[1].mTree.mRoot.mParent;
      v13 = *((float *)&v5[1].mTree.mRoot.mParent + 1);
      this->mPoseTaskParams.mOutputModelSpaceAABBMax.x = *((float *)&v5->mTree.mCount + 1);
      this->mPoseTaskParams.mOutputModelSpaceAABBMax.y = v12;
      this->mPoseTaskParams.mOutputModelSpaceAABBMax.z = v13;
      this->mPoseTask = 0i64;
      this->mPoseState = UPDATED_FROM_CACHE;
    }
    else if ( this->mPoseTaskParams.mRecipe.mStackCount <= 0x60 && this->mPoseTaskParams.mRecipe.mAnimDataCount <= 0x31 )
    {
      this->mPoseTask = PoseTaskSubmission::SubmitTask(&this->mPoseTaskParams);
      v14 = PoseTaskSubmission::sFrameIndex;
      this->mPoseState = SUBMITTED;
      this->mPoseFrame = v14;
    }
  }
}

// File Line: 741
// RVA: 0x3B6160
void __fastcall Creature::WaitOnPoseTask(Creature *this)
{
  UFG::qTask *mPoseTask; // rdx
  unsigned int mPoseCRC; // eax
  UFG::allocator::free_link *v4; // rax
  float *v5; // rdi
  float y; // xmm0_4
  float z; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm1_4

  mPoseTask = this->mPoseTask;
  if ( mPoseTask )
  {
    if ( this->mPoseFrame == PoseTaskSubmission::sFrameIndex )
    {
      UFG::qTaskManager::Sync(&UFG::gTaskManager, mPoseTask);
      mPoseCRC = this->mPoseCRC;
      if ( mPoseCRC != -1 && this->mLowPowerModeEnabled && PoseCache::sPoseCache->mEnablePoseCache )
      {
        v4 = PoseCache::Store(
               PoseCache::sPoseCache,
               (UFG::allocator::free_link *)(LODWORD(this->mPose.mRigHandle.mUFGSkeleton) | ((unsigned __int64)mPoseCRC << 32)),
               (UFG::allocator::free_link *)this->mPoseTaskParams.mBufferStride);
        v5 = (float *)v4;
        if ( v4 )
        {
          UFG::qMemCopy(v4[6].mNext, this->mPoseTaskParams.mOutputTransforms, this->mPoseTaskParams.mBufferStride);
          y = this->mPoseTaskParams.mOutputModelSpaceAABBMin.y;
          z = this->mPoseTaskParams.mOutputModelSpaceAABBMin.z;
          v5[14] = this->mPoseTaskParams.mOutputModelSpaceAABBMin.x;
          v5[15] = y;
          v5[16] = z;
          v8 = this->mPoseTaskParams.mOutputModelSpaceAABBMax.y;
          v9 = this->mPoseTaskParams.mOutputModelSpaceAABBMax.z;
          v5[17] = this->mPoseTaskParams.mOutputModelSpaceAABBMax.x;
          v5[18] = v8;
          v5[19] = v9;
        }
      }
    }
  }
  this->mPoseTask = 0i64;
  this->mPoseState = SYNCED;
}

// File Line: 773
// RVA: 0x3B4C90
void __fastcall Creature::UpdateTransforms(Creature *this)
{
  float y; // xmm0_4
  float z; // xmm1_4
  float v4; // xmm0_4
  float v5; // xmm1_4
  UFG::qColour v6; // [rsp+20h] [rbp-18h] BYREF

  if ( (unsigned int)(this->mPoseState - 1) <= 1 )
  {
    Creature::WaitOnPoseTask(this);
LABEL_10:
    y = this->mPoseTaskParams.mOutputModelSpaceAABBMin.y;
    z = this->mPoseTaskParams.mOutputModelSpaceAABBMin.z;
    this->mPose.mPoseAABBMin.x = this->mPoseTaskParams.mOutputModelSpaceAABBMin.x;
    this->mPose.mPoseAABBMin.y = y;
    this->mPose.mPoseAABBMin.z = z;
    v4 = this->mPoseTaskParams.mOutputModelSpaceAABBMax.y;
    v5 = this->mPoseTaskParams.mOutputModelSpaceAABBMax.z;
    this->mPose.mPoseAABBMax.x = this->mPoseTaskParams.mOutputModelSpaceAABBMax.x;
    this->mPose.mPoseAABBMax.y = v4;
    this->mPose.mPoseAABBMax.z = v5;
    this->mRestPosePrev = 0;
    goto LABEL_11;
  }
  if ( (__int64)this->mBlendTree.vfptr[1].CreateClone(&this->mBlendTree) > 0 )
  {
    if ( this->mPoseState )
      Creature::PrepPoseTaskInput(this, &this->mBlendTree);
    PoseTaskSubmission::ExecuteLocalTask(&this->mPoseTaskParams);
    goto LABEL_10;
  }
  if ( rest_pose_opt && !this->mRestPosePrev )
  {
    SkeletalPose::SetToRestPose(&this->mPose);
    this->mRestPosePrev = 1;
  }
LABEL_11:
  if ( gDrawPosePostAnimUpdate )
  {
    v6 = UFG::qColour::Pink;
    SkeletalPose::DebugDraw(&this->mPose, &v6, COERCE_DOUBLE((unsigned __int64)(unsigned int)FLOAT_1_0));
  }
  Creature::updateEffectorsToPose(this);
  this->mPose.mBoneUpdateCount = -1;
  this->mPoseTask = 0i64;
  this->mPoseFrame = PoseTaskSubmission::sFrameIndex;
}

// File Line: 1018
// RVA: 0x3B8570
void __fastcall Creature::updateAnimatedMovement(Creature *this, float deltaTime)
{
  Expression::IMemberMapVtbl *vfptr; // rax
  char *v4; // rdx
  Expression::IMemberMapVtbl *v5; // rax
  hkQsTransformf *Root; // rax
  __m128 v7; // xmm2
  hkQuaternionf v8; // xmm5
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
  float y; // xmm5_4
  __m128 x_low; // xmm4
  float z; // xmm6_4
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
  hkQsTransformf v40; // [rsp+20h] [rbp-D8h] BYREF
  void **v41; // [rsp+50h] [rbp-A8h] BYREF
  char v42; // [rsp+58h] [rbp-A0h]
  _BYTE *v43; // [rsp+60h] [rbp-98h]
  void **v44; // [rsp+68h] [rbp-90h] BYREF
  char v45; // [rsp+70h] [rbp-88h]
  __m128 v46; // [rsp+78h] [rbp-80h] BYREF
  __m128 m_quad; // [rsp+88h] [rbp-70h]
  __m128 v48; // [rsp+98h] [rbp-60h]
  hkQsTransformf newRoot; // [rsp+A8h] [rbp-50h] BYREF
  hkQsTransformf v50; // [rsp+D8h] [rbp-20h] BYREF
  __int128 v51; // [rsp+108h] [rbp+10h]
  __m128 v52; // [rsp+118h] [rbp+20h]
  __m128 v53; // [rsp+128h] [rbp+30h]
  hkTransformf transform; // [rsp+138h] [rbp+40h] BYREF

  Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
  vfptr = this->mBlendTree.vfptr;
  v46 = 0i64;
  m_quad = qi.m_vec.m_quad;
  v48 = query.m_quad;
  vfptr[1].GetResourcePath(&this->mBlendTree, v4, (int)&v46);
  v44 = &AnimationNode_UpdateLastPlayTime::`vftable;
  v5 = this->mBlendTree.vfptr;
  v45 = 1;
  v5[1].FindWithOldPath(&this->mBlendTree, (const char *)&v44);
  if ( this->mAbsoluteMonSet )
    this->mAbsoluteMonSet = 0;
  v52 = qi.m_vec.m_quad;
  v53 = query.m_quad;
  v51 = 0i64;
  Root = SkeletalPose::GetRoot(&this->mPose);
  v7 = v46;
  this->mPrevMotion.m_translation = Root->m_translation;
  v8.m_vec.m_quad = (__m128)Root->m_rotation;
  this->mPrevMotion.m_rotation = (hkQuaternionf)v8.m_vec.m_quad;
  this->mPrevMotion.m_scale = Root->m_scale;
  v9 = _mm_shuffle_ps(v8.m_vec.m_quad, v8.m_vec.m_quad, 255);
  v10 = _mm_mul_ps(v7, v8.m_vec.m_quad);
  v11 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v7, v7, 201), v8.m_vec.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(v8.m_vec.m_quad, v8.m_vec.m_quad, 201), v7));
  v12 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)),
                _mm_shuffle_ps(v10, v10, 170)),
              v8.m_vec.m_quad),
            _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v9, v9), (__m128)xmmword_141A711B0), v7)),
          _mm_mul_ps(_mm_shuffle_ps(v11, v11, 201), v9));
  v13 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v8.m_vec.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(v8.m_vec.m_quad, v8.m_vec.m_quad, 201), m_quad));
  newRoot.m_translation.m_quad = _mm_add_ps(_mm_add_ps(v12, v12), this->mPrevMotion.m_translation.m_quad);
  v14 = _mm_shuffle_ps(m_quad, m_quad, 255);
  v15 = _mm_mul_ps(m_quad, v8.m_vec.m_quad);
  v16 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v13, v13, 201), _mm_mul_ps(m_quad, v9)), _mm_mul_ps(v8.m_vec.m_quad, v14));
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
  newRoot.m_scale.m_quad = _mm_mul_ps(v48, this->mPrevMotion.m_scale.m_quad);
  v19 = _mm_add_ps(_mm_shuffle_ps(v18, v18, 78), v18);
  v20 = _mm_add_ps(_mm_shuffle_ps(v19, v19, 177), v19);
  v21 = _mm_rsqrt_ps(v20);
  newRoot.m_rotation.m_vec.m_quad = _mm_mul_ps(
                                      v17,
                                      _mm_mul_ps(
                                        _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v21, v20), v21)),
                                        _mm_mul_ps(*(__m128 *)_xmm, v21)));
  SkeletalPose::SetRoot(&this->mPose, &newRoot, 0);
  v22.m_quad = (__m128)newRoot.m_translation;
  v23.m_quad = (__m128)newRoot.m_scale;
  v24.m_vec.m_quad = (__m128)newRoot.m_rotation;
  this->mLastSetPosition.m_translation = newRoot.m_translation;
  this->mLastSetPosition.m_scale = (hkVector4f)v23.m_quad;
  this->mLastSetPosition.m_rotation = (hkQuaternionf)v24.m_vec.m_quad;
  v24.m_vec.m_quad.m128_f32[0] = v22.m_quad.m128_f32[0] - this->mPrevMotion.m_translation.m_quad.m128_f32[0];
  v23.m_quad.m128_f32[0] = _mm_shuffle_ps(v22.m_quad, v22.m_quad, 85).m128_f32[0];
  v22.m_quad.m128_f32[0] = newRoot.m_translation.m_quad.m128_f32[2] - this->mPrevMotion.m_translation.m_quad.m128_f32[2];
  v23.m_quad.m128_f32[0] = v23.m_quad.m128_f32[0] - this->mPrevMotion.m_translation.m_quad.m128_f32[1];
  LODWORD(this->mAnimatedMoveDirection.x) = v24.m_vec.m_quad.m128_i32[0];
  LODWORD(this->mAnimatedMoveDirection.z) = v22.m_quad.m128_i32[0];
  LODWORD(this->mAnimatedMoveDirection.y) = v23.m_quad.m128_i32[0];
  v24.m_vec.m_quad.m128_f32[0] = fsqrt(
                                   (float)((float)(v23.m_quad.m128_f32[0] * v23.m_quad.m128_f32[0])
                                         + (float)(v24.m_vec.m_quad.m128_f32[0] * v24.m_vec.m_quad.m128_f32[0]))
                                 + (float)(v22.m_quad.m128_f32[0] * v22.m_quad.m128_f32[0]));
  LODWORD(this->mAnimatedMoveSpeed) = v24.m_vec.m_quad.m128_i32[0];
  if ( v24.m_vec.m_quad.m128_f32[0] >= 0.000099999997 )
  {
    y = this->mAnimatedMoveDirection.y;
    x_low = (__m128)LODWORD(this->mAnimatedMoveDirection.x);
    z = this->mAnimatedMoveDirection.z;
    v28 = 0.0;
    v29 = x_low;
    v29.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(y * y)) + (float)(z * z);
    if ( v29.m128_f32[0] != 0.0 )
      v28 = 1.0 / _mm_sqrt_ps(v29).m128_f32[0];
    this->mAnimatedMoveDirection.x = x_low.m128_f32[0] * v28;
    this->mAnimatedMoveDirection.y = y * v28;
    this->mAnimatedMoveDirection.z = z * v28;
  }
  v41 = &FirstAnimationNode::`vftable;
  v30 = this->mBlendTree.vfptr;
  v42 = 1;
  v43 = 0i64;
  v30[1].FindWithOldPath(&this->mBlendTree, (const char *)&v41);
  if ( v43 )
  {
    v40.m_translation = 0i64;
    v40.m_rotation = (hkQuaternionf)qi.m_vec.m_quad;
    v40.m_scale = (hkVector4f)query.m_quad;
    if ( v43[360] == 4 )
    {
      (*(void (__fastcall **)(_BYTE *, hkQsTransformf *))(*(_QWORD *)v43 + 368i64))(v43, &v40);
      if ( this->mAbsoluteRelativeRootMotion )
      {
        hkTransformf::set4x4ColumnMajor(&transform, &this->mAbsoluteRelativeRoot.v0.x);
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
      SkeletalPose::SetRoot(&this->mPose, &v40, 0);
    }
  }
  Creature::updateSlopeFixup(this);
  this->mHaventUpdated = 0;
}

// File Line: 1240
// RVA: 0x3B8F30
void __fastcall Creature::updateSlopeFixup(Creature *this)
{
  __m128 x_low; // xmm2
  hkQsTransformf *Root; // rax
  float x; // xmm3_4
  float y; // xmm4_4
  float z; // xmm5_4
  hkVector4f v7; // xmm10
  __m128 v8; // xmm9
  __m128 v9; // xmm11
  float v10; // xmm2_4
  hkQsTransformf newRoot; // [rsp+20h] [rbp-68h] BYREF

  if ( !this->mLowPowerModeEnabled
    && this->mIsSlopeLocomotionFixupEnabled
    && COERCE_FLOAT(LODWORD(this->mGroundNormal.z) & _xmm) > this->mMaxSlopeLocomotionFixupAngle )
  {
    x_low = (__m128)LODWORD(this->mGroundNormal.x);
    x_low.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0])
                              + (float)(this->mGroundNormal.y * this->mGroundNormal.y))
                      + (float)(this->mGroundNormal.z * this->mGroundNormal.z);
    if ( _mm_sqrt_ps(x_low).m128_f32[0] > 0.0099999998 )
    {
      Root = SkeletalPose::GetRoot(&this->mPose);
      x = this->mGroundNormal.x;
      y = this->mGroundNormal.y;
      z = this->mGroundNormal.z;
      newRoot.m_translation = Root->m_translation;
      v7.m_quad = (__m128)newRoot.m_translation;
      v7.m_quad.m128_f32[0] = newRoot.m_translation.m_quad.m128_f32[0]
                            - this->mPrevMotion.m_translation.m_quad.m128_f32[0];
      newRoot.m_rotation = Root->m_rotation;
      v8 = _mm_shuffle_ps(newRoot.m_translation.m_quad, newRoot.m_translation.m_quad, 85);
      v9 = _mm_shuffle_ps(newRoot.m_translation.m_quad, newRoot.m_translation.m_quad, 170);
      v8.m128_f32[0] = v8.m128_f32[0] - this->mPrevMotion.m_translation.m_quad.m128_f32[1];
      v9.m128_f32[0] = v9.m128_f32[0] - this->mPrevMotion.m_translation.m_quad.m128_f32[2];
      newRoot.m_scale = Root->m_scale;
      v10 = (float)((float)(v7.m_quad.m128_f32[0] * x) + (float)(v8.m128_f32[0] * y)) + (float)(v9.m128_f32[0] * z);
      v7.m_quad.m128_f32[0] = (float)(v7.m_quad.m128_f32[0] - (float)(x * v10))
                            + this->mPrevMotion.m_translation.m_quad.m128_f32[0];
      v8.m128_f32[0] = (float)(v8.m128_f32[0] - (float)(y * v10)) + this->mPrevMotion.m_translation.m_quad.m128_f32[1];
      v9.m128_f32[0] = (float)(v9.m128_f32[0] - (float)(z * v10)) + this->mPrevMotion.m_translation.m_quad.m128_f32[2];
      newRoot.m_translation.m_quad = _mm_unpacklo_ps(
                                       _mm_unpacklo_ps(v7.m_quad, v9),
                                       _mm_unpacklo_ps(v8, (__m128)(unsigned int)FLOAT_1_0));
      SkeletalPose::SetRoot(&this->mPose, &newRoot, 0);
    }
  }
}

// File Line: 1491
// RVA: 0x3AEF40
void __fastcall Creature::SetBlendTreePlayTime(Creature *this, float timeAbsolute)
{
  PoseNodeParent *p_mBlendTree; // rcx
  Expression::IMemberMapVtbl *vfptr; // rax
  void **v4; // [rsp+20h] [rbp-28h] BYREF
  char v5; // [rsp+28h] [rbp-20h]
  float v6; // [rsp+30h] [rbp-18h]
  int v7; // [rsp+34h] [rbp-14h]
  __int16 v8; // [rsp+38h] [rbp-10h]

  p_mBlendTree = &this->mBlendTree;
  if ( p_mBlendTree )
  {
    v4 = &AnimationNode_SetLocalTime::`vftable;
    vfptr = p_mBlendTree->PoseNode::Expression::IMemberMap::vfptr;
    v6 = timeAbsolute;
    v7 = (int)FLOAT_1_0;
    v5 = 1;
    v8 = 1;
    vfptr[1].FindWithOldPath(p_mBlendTree, (const char *)&v4);
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
  float y; // xmm1_4
  float z; // xmm0_4
  UFG::qVector3 v4; // [rsp+20h] [rbp-18h] BYREF

  y = pos->y;
  v4.x = pos->x;
  z = pos->z;
  v4.y = y;
  v4.z = z;
  SkeletalPose::SetRootTranslation(&this->mPose, &v4, 0);
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
  SkeletalPose::GetTranslationWS(&this->mPose, boneID, result);
  return result;
}

// File Line: 1568
// RVA: 0x3A9710
hkQsTransformf *__fastcall Creature::GetTranslationMS(Creature *this, int boneID)
{
  hkaPose *mHavokPose; // r8

  mHavokPose = this->mPose.mHavokPose;
  if ( (mHavokPose->m_boneFlags.m_data[boneID] & 2) != 0 )
    return hkaPose::calculateBoneModelSpace(mHavokPose, boneID);
  else
    return &mHavokPose->m_modelPose.m_data[boneID];
}

// File Line: 1576
// RVA: 0x3A9570
hkQsTransformf *__fastcall Creature::GetPositionhkQ(Creature *this, hkQsTransformf *result)
{
  hkQsTransformf *Root; // rax
  hkQuaternionf v4; // xmm1
  hkVector4f v5; // xmm0
  hkQsTransformf *v6; // rax

  Root = SkeletalPose::GetRoot(&this->mPose);
  v4.m_vec.m_quad = (__m128)Root->m_rotation;
  result->m_translation = Root->m_translation;
  v5.m_quad = (__m128)Root->m_scale;
  result->m_rotation = (hkQuaternionf)v4.m_vec.m_quad;
  v6 = result;
  result->m_scale = (hkVector4f)v5.m_quad;
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
void __fastcall Creature::Attach(
        Creature *this,
        int attachBoneID,
        int blendedAttachBoneID,
        UFG::qMatrix44 *matrixWS,
        float weight)
{
  SkeletalPose *p_mPose; // rcx
  UFG::qMatrix44 *v10; // rax
  UFG::qVector4 v11; // xmm1
  UFG::qVector4 v12; // xmm0
  UFG::qVector4 v13; // xmm1
  UFG::qMatrix44 *p_d; // r8
  float v15; // xmm3_4
  UFG::qMatrix44 sourceA; // [rsp+20h] [rbp-E0h] BYREF
  UFG::qMatrix44 d; // [rsp+60h] [rbp-A0h] BYREF
  UFG::qMatrix44 b; // [rsp+A0h] [rbp-60h] BYREF
  UFG::qMatrix44 v19; // [rsp+E0h] [rbp-20h] BYREF
  UFG::qMatrix44 matrixWSa; // [rsp+120h] [rbp+20h] BYREF
  UFG::qMatrix44 result; // [rsp+160h] [rbp+60h] BYREF

  if ( !Creature::IsEndEffector(this, attachBoneID) )
  {
    p_mPose = &this->mPose;
    if ( blendedAttachBoneID < 0 )
    {
      SkeletalPose::GetPositionWS(p_mPose, attachBoneID, &sourceA);
      p_d = matrixWS;
      v15 = weight;
      if ( weight < 1.0 )
      {
LABEL_7:
        BlendSlerp(&d, &sourceA, p_d, v15);
        p_d = &d;
      }
    }
    else
    {
      SkeletalPose::GetPositionWS(p_mPose, attachBoneID, &matrixWSa);
      UFG::qInverseAffine(&d, &matrixWSa);
      v10 = UFG::qMatrix44::operator*(&d, &result, matrixWS);
      v11 = v10->v1;
      b.v0 = v10->v0;
      v12 = v10->v2;
      b.v1 = v11;
      v13 = v10->v3;
      b.v2 = v12;
      b.v3 = v13;
      SkeletalPose::GetPositionWS(&this->mPose, blendedAttachBoneID, &sourceA);
      UFG::qMatrix44::operator*(&sourceA, &v19, &b);
      p_d = &v19;
      v15 = weight;
      if ( weight < 1.0 )
        goto LABEL_7;
    }
    AttachPose(&this->mPose, &sourceA, p_d);
    goto LABEL_9;
  }
  Creature::SetEndEffectorTarget(this, attachBoneID, matrixWS);
LABEL_9:
  Creature::UpdateAttachmentPoses(this);
}

// File Line: 1797
// RVA: 0x3A2510
void __fastcall Creature::Attach(Creature *this, int attachBoneID, UFG::qVector3 *position, float weight)
{
  float x; // xmm6_4
  float y; // xmm7_4
  float z; // xmm8_4
  float v10; // xmm6_4
  float v11; // xmm7_4
  float v12; // xmm8_4
  hkQsTransformf *Root; // rax
  float v14; // xmm1_4
  float v15; // xmm2_4
  Render::DebugDrawContext *Context; // rax
  UFG::qVector3 translationWS; // [rsp+20h] [rbp-A8h] BYREF
  UFG::qVector3 v18; // [rsp+30h] [rbp-98h] BYREF
  UFG::qMatrix44 matrixRoot; // [rsp+40h] [rbp-88h] BYREF

  if ( !Creature::IsEndEffector(this, attachBoneID) )
  {
    SkeletalPose::GetTranslationWS(&this->mPose, attachBoneID, &translationWS);
    x = position->x;
    y = position->y;
    z = position->z;
    if ( weight < 1.0 )
    {
      x = (float)((float)(x - translationWS.x) * weight) + translationWS.x;
      y = (float)((float)(y - translationWS.y) * weight) + translationWS.y;
      z = (float)((float)(z - translationWS.z) * weight) + translationWS.z;
    }
    v10 = x - translationWS.x;
    v11 = y - translationWS.y;
    v12 = z - translationWS.z;
    Root = SkeletalPose::GetRoot(&this->mPose);
    v14 = Root->m_translation.m_quad.m128_f32[1] + v11;
    v15 = Root->m_translation.m_quad.m128_f32[2] + v12;
    v18.x = Root->m_translation.m_quad.m128_f32[0] + v10;
    v18.y = v14;
    v18.z = v15;
    SkeletalPose::SetRootTranslation(&this->mPose, &v18, 0);
    if ( gSkeletonDebug )
    {
      SkeletalPose::GetRootMatrix(&this->mPose, &matrixRoot);
      Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(
                                              Render::DebugDrawManager::mInstance,
                                              1u);
      Render::DebugDrawContext::DrawCoord(Context, &matrixRoot, 0.5, 0i64);
    }
  }
  Creature::UpdateAttachmentPoses(this);
}

// File Line: 1922
// RVA: 0x3AF320
void __fastcall Creature::SetGroundProperties(Creature *this, UFG::GroundProperties *p)
{
  float y; // xmm0_4
  float z; // xmm1_4

  y = p->groundNormal.y;
  z = p->groundNormal.z;
  this->mGroundNormal.x = p->groundNormal.x;
  this->mGroundNormal.y = y;
  this->mGroundNormal.z = z;
}

// File Line: 1930
// RVA: 0x3B8A40
void __fastcall Creature::updateAttachments(Creature *this, float timedelta)
{
  float *p_z; // rsi
  Creature *p_mNext; // rbx
  __int64 v4; // rdi

  p_z = &this->mGroundNormal.z;
  p_mNext = (Creature *)&this->mAttachments.mNode.mNext[-1].mNext;
  if ( p_mNext != (Creature *)&this->mGroundNormal.z )
  {
    do
    {
      v4 = (__int64)&p_mNext->m_SafePointerList.mNode.mNext[-1].mNext;
      ((void (__fastcall *)(Creature *))p_mNext->vfptr[1].__vecDelDtor)(p_mNext);
      if ( !p_mNext->mPrevMotion.m_scale.m_quad.m128_u64[1] )
        p_mNext->vfptr->__vecDelDtor(p_mNext, 1u);
      p_mNext = (Creature *)v4;
    }
    while ( (float *)v4 != p_z );
  }
}

// File Line: 1951
// RVA: 0x3B1540
void __fastcall Creature::UpdateAttachmentPoses(Creature *this)
{
  UFG::qNode<Attachment,Attachment> *mNext; // rbx
  float *p_z; // rdi
  float *i; // rbx
  UFG::qColour v5; // [rsp+20h] [rbp-18h] BYREF

  if ( gAttachDebug )
  {
    v5 = UFG::qColour::Blue;
    SkeletalPose::DebugDraw(&this->mPose, &v5, COERCE_DOUBLE((unsigned __int64)(unsigned int)FLOAT_1_0));
  }
  mNext = this->mAttachments.mNode.mNext;
  p_z = &this->mGroundNormal.z;
  for ( i = (float *)&mNext[-1].mNext; i != p_z; i = (float *)(*((_QWORD *)i + 2) - 8i64) )
  {
    (*(void (__fastcall **)(float *))(*(_QWORD *)i + 16i64))(i);
    if ( gAttachDebug )
      (*(void (__fastcall **)(float *))(*(_QWORD *)i + 32i64))(i);
  }
}

// File Line: 1971
// RVA: 0x3B15D0
void __fastcall Creature::UpdateAttachmentPostPhysics(Creature *this)
{
  UFG::qNode<Attachment,Attachment> *mNext; // rbx
  float *p_z; // rdi
  float *i; // rbx
  UFG::qColour v5; // [rsp+20h] [rbp-18h] BYREF

  Creature::updateEffectorsToPosePostPhysics(this);
  if ( sAttachPosePhy )
  {
    v5 = UFG::qColour::Pink;
    SkeletalPose::DebugDraw(&this->mPose, &v5, COERCE_DOUBLE((unsigned __int64)(unsigned int)FLOAT_1_0));
  }
  mNext = this->mAttachments.mNode.mNext;
  p_z = &this->mGroundNormal.z;
  for ( i = (float *)&mNext[-1].mNext; i != p_z; i = (float *)(*((_QWORD *)i + 2) - 8i64) )
  {
    (*(void (__fastcall **)(float *))(*(_QWORD *)i + 16i64))(i);
    (*(void (__fastcall **)(float *))(*(_QWORD *)i + 24i64))(i);
  }
}

// File Line: 2020
// RVA: 0x3A0B80
UFG::qNode<Attachment,Attachment> **__fastcall Creature::AddAttachment(Creature *this, Attachment *attachment)
{
  UFG::qNode<Attachment,Attachment> **result; // rax
  UFG::qNode<Attachment,Attachment> *mPrev; // rax

  result = &this->mAttachments.mNode.mNext[-1].mNext;
  if ( result == (UFG::qNode<Attachment,Attachment> **)&this->mGroundNormal.z )
    goto LABEL_6;
  while ( result[13] != (UFG::qNode<Attachment,Attachment> *)attachment->mAttachedSimObject.m_pPointer )
  {
    result = &result[2][-1].mNext;
    if ( result == (UFG::qNode<Attachment,Attachment> **)&this->mGroundNormal.z )
      goto LABEL_6;
  }
  if ( *((_DWORD *)result + 8) != attachment->attachedJoint )
  {
LABEL_6:
    mPrev = this->mAttachments.mNode.mPrev;
    mPrev->mNext = &attachment->UFG::qNode<Attachment,Attachment>;
    attachment->mPrev = mPrev;
    attachment->mNext = &this->mAttachments.mNode;
    this->mAttachments.mNode.mPrev = &attachment->UFG::qNode<Attachment,Attachment>;
    return (UFG::qNode<Attachment,Attachment> **)attachment;
  }
  return result;
}

// File Line: 2035
// RVA: 0x3A0BE0
UFG::qNode<Attachment,Attachment> **__fastcall Creature::AddAttachment(
        Creature *this,
        UFG::SimObject *self,
        int attachBoneID,
        UFG::SimObjectCVBase *attachedSimObject,
        int attachmentBoneID,
        bool positionOnly,
        float blendIn)
{
  UFG::qNode<Attachment,Attachment> **result; // rax
  __int64 v12; // rsi
  signed __int16 m_Flags; // cx
  UFG::CharacterAnimationComponent *ComponentOfTypeHK; // rax
  UFG::CharacterAnimationComponent *v15; // rdi
  Creature *mCreature; // rdx
  __int64 p_mNext; // rcx
  float *p_z; // rdx
  UFG::allocator::free_link *v19; // rax
  __int64 v20; // rax
  UFG::qNode<Attachment,Attachment> *mPrev; // rax
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v22; // rdx
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v23; // rcx
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v24; // rax
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v25; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v26; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v27; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v28; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v29; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v30; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v31; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v32; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v33; // rax
  bool v34; // zf
  Creature *v35; // rax
  signed __int16 v36; // cx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::allocator::free_link *v38; // rax
  __int64 v39; // rax
  UFG::qNode<Attachment,Attachment> *v40; // rax
  signed __int16 v41; // cx
  UFG::SimComponent *v42; // rax
  UFG::RigidBody *v43; // rdi

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
      m_Flags = attachedSimObject->m_Flags;
      if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
      {
        ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(attachedSimObject);
      }
      else if ( (m_Flags & 0x2000) != 0 )
      {
        ComponentOfTypeHK = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)attachedSimObject);
      }
      else if ( (m_Flags & 0x1000) != 0 )
      {
        ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                  attachedSimObject,
                                                                  UFG::CharacterAnimationComponent::_TypeUID);
      }
      else
      {
        ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                                  attachedSimObject,
                                                                  UFG::CharacterAnimationComponent::_TypeUID);
      }
      v15 = ComponentOfTypeHK;
      if ( ComponentOfTypeHK )
      {
        mCreature = ComponentOfTypeHK->mCreature;
        p_mNext = (__int64)&mCreature->mAttachments.mNode.mNext[-1].mNext;
        if ( (Creature *)p_mNext != (Creature *)&mCreature->mGroundNormal.z )
        {
          p_z = &mCreature->mGroundNormal.z;
          while ( *(UFG::SimObject **)(p_mNext + 104) != self )
          {
            p_mNext = *(_QWORD *)(p_mNext + 16) - 8i64;
            if ( (float *)p_mNext == p_z )
              goto LABEL_22;
          }
          return 0i64;
        }
LABEL_22:
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
        mPrev = this->mAttachments.mNode.mPrev;
        mPrev->mNext = (UFG::qNode<Attachment,Attachment> *)(v12 + 8);
        *(_QWORD *)(v12 + 8) = mPrev;
        *(_QWORD *)(v12 + 16) = &this->mAttachments;
        this->mAttachments.mNode.mPrev = (UFG::qNode<Attachment,Attachment> *)(v12 + 8);
        *(_DWORD *)(v12 + 32) = attachBoneID;
        v22 = (UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *)(v12 + 64);
        if ( *(_QWORD *)(v12 + 80) )
        {
          v23 = v22->mPrev;
          v24 = *(UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> **)(v12 + 72);
          v23->mNext = v24;
          v24->mPrev = v23;
          v22->mPrev = v22;
          *(_QWORD *)(v12 + 72) = v12 + 64;
        }
        *(_QWORD *)(v12 + 80) = this;
        v25 = this->m_SafePointerList.mNode.mPrev;
        v25->mNext = v22;
        v22->mPrev = v25;
        *(_QWORD *)(v12 + 72) = &this->m_SafePointerList;
        this->m_SafePointerList.mNode.mPrev = v22;
        v26 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)(v12 + 88);
        if ( *(_QWORD *)(v12 + 104) )
        {
          v27 = v26->mPrev;
          v28 = *(UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> **)(v12 + 96);
          v27->mNext = v28;
          v28->mPrev = v27;
          v26->mPrev = v26;
          *(_QWORD *)(v12 + 96) = v12 + 88;
        }
        *(_QWORD *)(v12 + 104) = attachedSimObject;
        v29 = attachedSimObject->m_SafePointerList.UFG::SimObjectGame::UFG::SimObject::UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
        v29->mNext = v26;
        v26->mPrev = v29;
        *(_QWORD *)(v12 + 96) = &attachedSimObject->m_SafePointerList;
        attachedSimObject->m_SafePointerList.UFG::SimObjectGame::UFG::SimObject::UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = v26;
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
        v30 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)(v12 + 216);
        if ( *(_QWORD *)(v12 + 232) )
        {
          v31 = v30->mPrev;
          v32 = *(UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **)(v12 + 224);
          v31->mNext = v32;
          v32->mPrev = v31;
          v30->mPrev = v30;
          *(_QWORD *)(v12 + 224) = v12 + 216;
        }
        *(_QWORD *)(v12 + 232) = v15;
        v33 = v15->m_SafePointerList.mNode.UFG::BaseAnimationComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
        v33->mNext = v30;
        v30->mPrev = v33;
        *(_QWORD *)(v12 + 224) = &v15->m_SafePointerList;
        v15->m_SafePointerList.mNode.UFG::BaseAnimationComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = v30;
        v34 = !Creature::IsEndEffector(v15->mCreature, attachmentBoneID);
        v35 = v15->mCreature;
        v35->mIsAttached = v34;
      }
      else
      {
        v36 = attachedSimObject->m_Flags;
        if ( (v36 & 0x4000) != 0 || v36 < 0 || (v36 & 0x2000) != 0 || (v36 & 0x1000) != 0 )
          ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(
                              attachedSimObject,
                              UFG::RigidBodyComponent::_TypeUID);
        else
          ComponentOfType = UFG::SimObject::GetComponentOfType(attachedSimObject, UFG::RigidBodyComponent::_TypeUID);
        if ( ComponentOfType )
        {
          v38 = UFG::qMalloc(0xD0ui64, "Creature.AttachmentRigidBody", 0i64);
          if ( v38 )
          {
            AttachmentRigidBody::AttachmentRigidBody((AttachmentRigidBody *)v38);
            v12 = v39;
          }
          else
          {
            v12 = 0i64;
          }
          v40 = this->mAttachments.mNode.mPrev;
          v40->mNext = (UFG::qNode<Attachment,Attachment> *)(v12 + 8);
          *(_QWORD *)(v12 + 8) = v40;
          *(_QWORD *)(v12 + 16) = &this->mAttachments;
          this->mAttachments.mNode.mPrev = (UFG::qNode<Attachment,Attachment> *)(v12 + 8);
          *(_DWORD *)(v12 + 32) = attachBoneID;
          UFG::qSafePointer<Creature,Creature>::operator=(
            (UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *)(v12 + 64),
            (UFG::SimComponent *)this);
          UFG::qSafePointer<Creature,Creature>::operator=(
            (UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *)(v12 + 88),
            (UFG::SimComponent *)attachedSimObject);
          *(_BYTE *)(v12 + 26) = 0;
        }
      }
      v41 = attachedSimObject->m_Flags;
      if ( (v41 & 0x4000) != 0 || v41 < 0 || (v41 & 0x2000) != 0 || (v41 & 0x1000) != 0 )
        v42 = UFG::SimObjectGame::GetComponentOfTypeHK(attachedSimObject, UFG::RigidBodyComponent::_TypeUID);
      else
        v42 = UFG::SimObject::GetComponentOfType(attachedSimObject, UFG::RigidBodyComponent::_TypeUID);
      v43 = (UFG::RigidBody *)v42;
      if ( v42 )
      {
        do
        {
          UFG::RigidBody::SetMotionType(v43, 0x100u);
          v43 = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(
                                    attachedSimObject,
                                    UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                                    0,
                                    v43);
        }
        while ( v43 );
      }
    }
    return (UFG::qNode<Attachment,Attachment> **)v12;
  }
  return result;
}

// File Line: 2164
// RVA: 0x3A1300
UFG::qNode<Attachment,Attachment> **__fastcall Creature::AddAttachmentRelative(
        Creature *this,
        UFG::SimObject *self,
        int attachBoneID,
        UFG::SimObjectCVBase *attachedSimObject,
        int attachmentBoneID,
        UFG::qMatrix44 *relativePositionWS,
        float blendIn)
{
  UFG::qNode<Attachment,Attachment> **v9; // rax
  UFG::qNode<Attachment,Attachment> **v10; // rbx
  UFG::qMatrix44 *v11; // rax
  UFG::qVector4 v12; // xmm3
  UFG::qVector4 v13; // xmm2
  UFG::qVector4 v14; // xmm1
  UFG::qMatrix44 d; // [rsp+40h] [rbp-C8h] BYREF
  UFG::qMatrix44 matrixWS; // [rsp+80h] [rbp-88h] BYREF
  UFG::qMatrix44 result; // [rsp+C0h] [rbp-48h] BYREF

  v9 = Creature::AddAttachment(this, self, attachBoneID, attachedSimObject, attachmentBoneID, 0, blendIn);
  v10 = v9;
  if ( v9 )
  {
    *((_BYTE *)v9 + 26) = 1;
    SkeletalPose::GetPositionWS(&this->mPose, attachBoneID, &matrixWS);
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
void __fastcall Creature::AddRelativeTransform(
        Creature *this,
        int attachBoneID,
        UFG::SimObject *attachedSimObject,
        int attachmentBoneID,
        UFG::qMatrix44 *relativeTransform)
{
  UFG::qNode<Attachment,Attachment> *mNext; // rax
  float *p_z; // rcx
  __int64 p_mNext; // rax
  UFG::qVector4 v8; // xmm3
  UFG::qVector4 v9; // xmm2
  UFG::qVector4 v10; // xmm1

  mNext = this->mAttachments.mNode.mNext;
  p_z = &this->mGroundNormal.z;
  p_mNext = (__int64)&mNext[-1].mNext;
  if ( (float *)p_mNext != p_z )
  {
    while ( *(UFG::SimObject **)(p_mNext + 104) != attachedSimObject )
    {
      p_mNext = *(_QWORD *)(p_mNext + 16) - 8i64;
      if ( (float *)p_mNext == p_z )
        return;
    }
    if ( *(_DWORD *)(p_mNext + 32) == attachBoneID )
    {
      *(_BYTE *)(p_mNext + 26) = 1;
      v8 = relativeTransform->v1;
      v9 = relativeTransform->v2;
      v10 = relativeTransform->v3;
      *(UFG::qVector4 *)(p_mNext + 112) = relativeTransform->v0;
      *(UFG::qVector4 *)(p_mNext + 128) = v8;
      *(UFG::qVector4 *)(p_mNext + 144) = v9;
      *(UFG::qVector4 *)(p_mNext + 160) = v10;
    }
  }
}

// File Line: 2197
// RVA: 0x3A1400
void __fastcall Creature::AddRelativeScale(
        Creature *this,
        int attachBoneID,
        UFG::SimObject *attachedSimObject,
        int attachmentBoneID,
        UFG::qVector3 *relativeScale)
{
  UFG::qNode<Attachment,Attachment> *mNext; // r9
  float *p_z; // rcx
  __int64 p_mNext; // r9
  float y; // xmm0_4
  float z; // xmm1_4

  mNext = this->mAttachments.mNode.mNext;
  p_z = &this->mGroundNormal.z;
  p_mNext = (__int64)&mNext[-1].mNext;
  if ( (float *)p_mNext != p_z )
  {
    while ( *(UFG::SimObject **)(p_mNext + 104) != attachedSimObject )
    {
      p_mNext = *(_QWORD *)(p_mNext + 16) - 8i64;
      if ( (float *)p_mNext == p_z )
        return;
    }
    if ( *(_DWORD *)(p_mNext + 32) == attachBoneID )
    {
      *(_BYTE *)(p_mNext + 27) = 1;
      y = relativeScale->y;
      z = relativeScale->z;
      *(float *)(p_mNext + 176) = relativeScale->x;
      *(float *)(p_mNext + 180) = y;
      *(float *)(p_mNext + 184) = z;
    }
  }
}

// File Line: 2210
// RVA: 0x3A1030
Attachment *__fastcall Creature::AddAttachmentParkour(
        Creature *this,
        UFG::SimObject *attachedToParkourObject,
        int attachBoneID,
        UFG::SimObjectCVBase *attachedSimObject,
        UFG::ParkourHandle *parkourHandle,
        float blendIn)
{
  __int64 v10; // rbx
  signed __int16 m_Flags; // cx
  UFG::CharacterAnimationComponent *v13; // rax
  UFG::CharacterAnimationComponent *v14; // rdi
  UFG::allocator::free_link *v15; // rax
  __int64 v16; // rax
  UFG::qNode<Attachment,Attachment> *mPrev; // rax
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v18; // rdx
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v19; // rcx
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v20; // rax
  UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *v21; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v22; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v23; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v24; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v25; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v26; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v27; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v28; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v29; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v30; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v31; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v32; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v33; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v34; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v35; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v36; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v37; // rax

  v10 = 0i64;
  if ( attachBoneID == -1 )
    return 0i64;
  if ( attachedSimObject )
  {
    m_Flags = attachedSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      v13 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(attachedSimObject);
    }
    else if ( (m_Flags & 0x2000) != 0 )
    {
      v13 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)attachedSimObject);
    }
    else
    {
      v13 = (UFG::CharacterAnimationComponent *)((m_Flags & 0x1000) != 0
                                               ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   attachedSimObject,
                                                   UFG::CharacterAnimationComponent::_TypeUID)
                                               : UFG::SimObject::GetComponentOfType(
                                                   attachedSimObject,
                                                   UFG::CharacterAnimationComponent::_TypeUID));
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
      mPrev = this->mAttachments.mNode.mPrev;
      mPrev->mNext = (UFG::qNode<Attachment,Attachment> *)(v10 + 8);
      *(_QWORD *)(v10 + 8) = mPrev;
      *(_QWORD *)(v10 + 16) = &this->mAttachments;
      this->mAttachments.mNode.mPrev = (UFG::qNode<Attachment,Attachment> *)(v10 + 8);
      *(_DWORD *)(v10 + 32) = attachBoneID;
      v18 = (UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> *)(v10 + 64);
      if ( *(_QWORD *)(v10 + 80) )
      {
        v19 = v18->mPrev;
        v20 = *(UFG::qNode<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList> **)(v10 + 72);
        v19->mNext = v20;
        v20->mPrev = v19;
        v18->mPrev = v18;
        *(_QWORD *)(v10 + 72) = v10 + 64;
      }
      *(_QWORD *)(v10 + 80) = this;
      v21 = this->m_SafePointerList.mNode.mPrev;
      v21->mNext = v18;
      v18->mPrev = v21;
      *(_QWORD *)(v10 + 72) = &this->m_SafePointerList;
      this->m_SafePointerList.mNode.mPrev = v18;
      v22 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)(v10 + 88);
      if ( *(_QWORD *)(v10 + 104) )
      {
        v23 = v22->mPrev;
        v24 = *(UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> **)(v10 + 96);
        v23->mNext = v24;
        v24->mPrev = v23;
        v22->mPrev = v22;
        *(_QWORD *)(v10 + 96) = v10 + 88;
      }
      *(_QWORD *)(v10 + 104) = attachedSimObject;
      v25 = attachedSimObject->m_SafePointerList.UFG::SimObjectGame::UFG::SimObject::UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
      v25->mNext = v22;
      v22->mPrev = v25;
      *(_QWORD *)(v10 + 96) = &attachedSimObject->m_SafePointerList;
      attachedSimObject->m_SafePointerList.UFG::SimObjectGame::UFG::SimObject::UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = v22;
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
      v26 = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)(v10 + 208);
      if ( *(_QWORD *)(v10 + 224) )
      {
        v27 = v26->mPrev;
        v28 = *(UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> **)(v10 + 216);
        v27->mNext = v28;
        v28->mPrev = v27;
        v26->mPrev = v26;
        *(_QWORD *)(v10 + 216) = v10 + 208;
      }
      *(_QWORD *)(v10 + 224) = parkourHandle;
      if ( parkourHandle )
      {
        v29 = parkourHandle->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::ParkourHandle>::mPrev;
        v29->mNext = v26;
        v26->mPrev = v29;
        *(_QWORD *)(v10 + 216) = &parkourHandle->m_SafePointerList;
        parkourHandle->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::ParkourHandle>::mPrev = v26;
      }
      v30 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)(v10 + 232);
      if ( *(_QWORD *)(v10 + 248) )
      {
        v31 = v30->mPrev;
        v32 = *(UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> **)(v10 + 240);
        v31->mNext = v32;
        v32->mPrev = v31;
        v30->mPrev = v30;
        *(_QWORD *)(v10 + 240) = v10 + 232;
      }
      *(_QWORD *)(v10 + 248) = attachedToParkourObject;
      if ( attachedToParkourObject )
      {
        v33 = attachedToParkourObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
        v33->mNext = v30;
        v30->mPrev = v33;
        *(_QWORD *)(v10 + 240) = &attachedToParkourObject->m_SafePointerList;
        attachedToParkourObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = v30;
      }
      v34 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)(v10 + 256);
      if ( *(_QWORD *)(v10 + 272) )
      {
        v35 = v34->mPrev;
        v36 = *(UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **)(v10 + 264);
        v35->mNext = v36;
        v36->mPrev = v35;
        v34->mPrev = v34;
        *(_QWORD *)(v10 + 264) = v10 + 256;
      }
      *(_QWORD *)(v10 + 272) = v14;
      v37 = v14->m_SafePointerList.mNode.UFG::BaseAnimationComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
      v37->mNext = v34;
      v34->mPrev = v37;
      *(_QWORD *)(v10 + 264) = &v14->m_SafePointerList;
      v14->m_SafePointerList.mNode.UFG::BaseAnimationComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = v34;
      v14->mCreature->mIsAttached = !Creature::IsEndEffector(v14->mCreature, attachBoneID);
    }
  }
  return (Attachment *)v10;
}

// File Line: 2287
// RVA: 0x3ADFB0
char __fastcall Creature::RemoveAttachment(
        Creature *this,
        UFG::SimObject *self,
        int attachBoneID,
        UFG::SimObject *attachedSimObject)
{
  UFG::qNode<Attachment,Attachment> *mNext; // rbx
  float *p_z; // rcx
  Attachment *p_mNext; // rbx
  UFG::qNode<Attachment,Attachment> *mPrev; // rcx
  UFG::qNode<Attachment,Attachment> *v9; // rax

  mNext = this->mAttachments.mNode.mNext;
  p_z = &this->mGroundNormal.z;
  p_mNext = (Attachment *)&mNext[-1].mNext;
  if ( p_mNext == (Attachment *)p_z )
    return 0;
  while ( p_mNext->mAttachedSimObject.m_pPointer != attachedSimObject && attachedSimObject
       || p_mNext->attachedJoint != attachBoneID )
  {
    p_mNext = (Attachment *)&p_mNext->mNext[-1].mNext;
    if ( p_mNext == (Attachment *)p_z )
      return 0;
  }
  ((void (__fastcall *)(Attachment *, UFG::SimObject *))p_mNext->vfptr->OnRemove)(p_mNext, self);
  mPrev = p_mNext->mPrev;
  v9 = p_mNext->mNext;
  mPrev->mNext = v9;
  v9->mPrev = mPrev;
  p_mNext->mPrev = &p_mNext->UFG::qNode<Attachment,Attachment>;
  p_mNext->mNext = &p_mNext->UFG::qNode<Attachment,Attachment>;
  p_mNext->vfptr->__vecDelDtor(p_mNext, 1i64);
  return 1;
}

// File Line: 2330
// RVA: 0x3AC190
void __fastcall AttachmentCreature::OnRemove(AttachmentCreature *this)
{
  Creature *v2; // rsi
  UFG::qNode<PoseDriver,PoseDriver> *mNext; // rbx
  UFG::qList<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList,1,0> *p_m_SafePointerList; // rsi
  UFG::qNode<PoseDriver,PoseDriver> *i; // rbx
  UFG::SimObjectGame *m_pPointer; // rdi
  __int16 m_Flags; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::RigidBody *ComponentOfType; // rbx

  if ( this->mAttachedSimObject.m_pPointer )
  {
    v2 = *(Creature **)&this->mAttachedCharacterAnimationComponent.m_pPointer[2].m_TypeUID;
    v2->mIsAttached = 0;
    if ( Creature::IsEndEffector(v2, this->attachedJoint) )
    {
      mNext = v2->mPoseDrivers.mNode.mNext;
      p_m_SafePointerList = &v2->m_SafePointerList;
      for ( i = mNext - 1; i != (UFG::qNode<PoseDriver,PoseDriver> *)p_m_SafePointerList; i = i[1].mNext - 1 )
      {
        if ( ((unsigned int (__fastcall *)(UFG::qNode<PoseDriver,PoseDriver> *))i->mPrev[7].mPrev)(i) == this->attachedJoint )
          ((void (__fastcall *)(UFG::qNode<PoseDriver,PoseDriver> *, _QWORD))i->mPrev[5].mNext)(i, 0i64);
      }
    }
    else
    {
      m_pPointer = (UFG::SimObjectGame *)this->mAttachedSimObject.m_pPointer;
      if ( m_pPointer )
      {
        m_Flags = m_pPointer->m_Flags;
        if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::RigidBodyComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::RigidBodyComponent::_TypeUID);
        ComponentOfType = (UFG::RigidBody *)ComponentOfTypeHK;
        if ( ComponentOfTypeHK )
        {
          do
          {
            UFG::RigidBody::SetMotionType(ComponentOfType, 0x80u);
            ComponentOfType = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(
                                                  m_pPointer,
                                                  UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                                                  0,
                                                  ComponentOfType);
          }
          while ( ComponentOfType );
        }
      }
    }
  }
}

// File Line: 2368
// RVA: 0x3B0200
bool __fastcall Creature::TransferAttachment(
        Creature *this,
        int sourceBoneID,
        int destsourceBoneID,
        UFG::qSymbolUC *attachmentBone)
{
  float *p_z; // rdi
  bool result; // al
  float *p_mNext; // rbx
  __int64 v10; // rax
  __int64 v11; // rcx
  int BoneID; // eax

  p_z = &this->mGroundNormal.z;
  result = 0;
  p_mNext = (float *)&this->mAttachments.mNode.mNext[-1].mNext;
  if ( p_mNext != &this->mGroundNormal.z )
  {
    do
    {
      if ( *((_DWORD *)p_mNext + 8) == sourceBoneID )
      {
        *((_DWORD *)p_mNext + 8) = destsourceBoneID;
        if ( attachmentBone->mUID != gStaticSymbolUC_none.mUID )
        {
          if ( *((_QWORD *)p_mNext + 10) )
          {
            v10 = *((_QWORD *)p_mNext + 29);
            if ( v10 )
            {
              v11 = *(_QWORD *)(v10 + 152);
              if ( *(_QWORD *)(v11 + 440) )
                BoneID = Skeleton::GetBoneID(*(Skeleton **)(v11 + 480), attachmentBone->mUID);
              else
                BoneID = -1;
              *((_DWORD *)p_mNext + 52) = BoneID;
            }
          }
        }
        result = 1;
      }
      p_mNext = (float *)(*((_QWORD *)p_mNext + 2) - 8i64);
    }
    while ( p_mNext != p_z );
  }
  return result;
}

// File Line: 2400
// RVA: 0x3A95B0
void __fastcall Creature::GetResourceSystemAttachments(Creature *this, UFG::qArray<UFG::qSymbol,0> *nameList)
{
  float *p_z; // rdi
  Creature *p_mNext; // rbx
  UFG::SimObjectGame *v5; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  UFG::qSymbol *ArchetypePropertiesName; // rax

  p_z = &this->mGroundNormal.z;
  p_mNext = (Creature *)&this->mAttachments.mNode.mNext[-1].mNext;
  if ( p_mNext != (Creature *)&this->mGroundNormal.z )
  {
    do
    {
      v5 = (UFG::SimObjectGame *)p_mNext->mPrevMotion.m_scale.m_quad.m128_u64[1];
      if ( v5 && (v5->m_Flags & 0x4000) == 0 )
      {
        m_Flags = v5->m_Flags;
        if ( (m_Flags & 0x4000) != 0 )
        {
          m_pComponent = v5->m_Components.p[10].m_pComponent;
        }
        else if ( m_Flags >= 0 )
        {
          if ( (m_Flags & 0x2000) != 0 )
          {
            m_pComponent = v5->m_Components.p[7].m_pComponent;
          }
          else if ( (m_Flags & 0x1000) != 0 )
          {
            m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::StreamedResourceComponent::_TypeUID);
          }
          else
          {
            m_pComponent = UFG::SimObject::GetComponentOfType(v5, UFG::StreamedResourceComponent::_TypeUID);
          }
        }
        else
        {
          m_pComponent = v5->m_Components.p[10].m_pComponent;
        }
        if ( m_pComponent )
        {
          ArchetypePropertiesName = UFG::SceneObjectProperties::GetArchetypePropertiesName(*(UFG::SceneObjectProperties **)(p_mNext->mPrevMotion.m_scale.m_quad.m128_u64[1] + 80));
          UFG::qArray<UFG::qSymbol,0>::Add(nameList, ArchetypePropertiesName, "qArray.Add");
        }
      }
      p_mNext = (Creature *)&p_mNext->m_SafePointerList.mNode.mNext[-1].mNext;
    }
    while ( p_mNext != (Creature *)p_z );
  }
}

// File Line: 2429
// RVA: 0x3A6AD0
void __fastcall Creature::DestroyAllAttachments(
        Creature *this,
        UFG::SimObject *self,
        bool onlyRemoveCharacterAttachments)
{
  float *p_z; // r15
  float *v6; // rbp
  UFG::qNode<Attachment,Attachment> *mNext; // rbx
  UFG::SimObjectCharacter *mPrev; // rdi
  char v9; // si
  int v10; // eax
  float *p_mNext; // rbx
  __int64 v12; // rcx
  _QWORD *v13; // rax
  __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rax

  p_z = &this->mGroundNormal.z;
  if ( &this->mAttachments.mNode.mNext[-1].mNext != (UFG::qNode<Attachment,Attachment> **)&this->mGroundNormal.z )
  {
    v6 = &this->mGroundNormal.z;
    do
    {
      mNext = this->mAttachments.mNode.mNext;
      mPrev = (UFG::SimObjectCharacter *)mNext[6].mPrev;
      v9 = ((__int64 (__fastcall *)(UFG::qNode<Attachment,Attachment> **, UFG::SimObject *))mNext[-1].mNext[5].mPrev)(
             &mNext[-1].mNext,
             self);
      v10 = (int)mNext[1].mNext;
      p_mNext = (float *)&this->mAttachments.mNode.mNext[-1].mNext;
      if ( p_mNext != v6 )
      {
        while ( *((UFG::SimObjectCharacter **)p_mNext + 13) != mPrev && mPrev || *((_DWORD *)p_mNext + 8) != v10 )
        {
          p_mNext = (float *)(*((_QWORD *)p_mNext + 2) - 8i64);
          if ( p_mNext == v6 )
            goto LABEL_10;
        }
        (*(void (__fastcall **)(float *))(*(_QWORD *)p_mNext + 72i64))(p_mNext);
        v12 = *((_QWORD *)p_mNext + 1);
        v13 = (_QWORD *)*((_QWORD *)p_mNext + 2);
        *(_QWORD *)(v12 + 8) = v13;
        *v13 = v12;
        *((_QWORD *)p_mNext + 1) = p_mNext + 2;
        *((_QWORD *)p_mNext + 2) = p_mNext + 2;
        (**(void (__fastcall ***)(char *, __int64))p_mNext)((char *)p_mNext, 1i64);
      }
LABEL_10:
      if ( mPrev )
      {
        if ( onlyRemoveCharacterAttachments )
        {
          m_Flags = mPrev->m_Flags;
          if ( (m_Flags & 0x4000) != 0 )
          {
            m_pComponent = mPrev->m_Components.p[3].m_pComponent;
          }
          else if ( m_Flags >= 0 )
          {
            if ( (m_Flags & 0x2000) != 0 )
              m_pComponent = mPrev->m_Components.p[4].m_pComponent;
            else
              m_pComponent = (m_Flags & 0x1000) != 0
                           ? UFG::SimObjectGame::GetComponentOfTypeHK(
                               mPrev,
                               UFG::SimObjectPropertiesComponent::_TypeUID)
                           : UFG::SimObject::GetComponentOfType(mPrev, UFG::SimObjectPropertiesComponent::_TypeUID);
          }
          else
          {
            m_pComponent = mPrev->m_Components.p[3].m_pComponent;
          }
          if ( m_pComponent && LODWORD(m_pComponent[1].m_SafePointerList.mNode.mNext) == 1 )
            v9 = 0;
        }
        if ( mPrev != LocalPlayer )
        {
          if ( v9 )
            UFG::Simulation::QueueSimObjectToBeDestroyed(&UFG::gSim, mPrev);
        }
      }
    }
    while ( (float *)&this->mAttachments.mNode.mNext[-1].mNext != p_z );
  }
}

// File Line: 2505
// RVA: 0x14BF720
__int64 dynamic_initializer_for__sUprightNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32(uprightDriver, -1);
  sUprightNameUID = result;
  return result;
}

// File Line: 2508
// RVA: 0x3AB730
void __fastcall Creature::MakeUpright(Creature *this, float uprightTime)
{
  __int64 v2; // rdx
  UFG::qNode<PoseDriver,PoseDriver> *mNext; // rbx
  UFG::qList<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList,1,0> *p_m_SafePointerList; // rcx
  __int64 v5; // rbx

  mNext = this->mPoseDrivers.mNode.mNext;
  p_m_SafePointerList = &this->m_SafePointerList;
  v5 = (__int64)&mNext[-1];
  if ( (UFG::qList<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList,1,0> *)v5 != p_m_SafePointerList )
  {
    while ( *(_DWORD *)(v5 + 44) != sUprightNameUID )
    {
      v5 = *(_QWORD *)(v5 + 24) - 16i64;
      if ( (UFG::qList<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList,1,0> *)v5 == p_m_SafePointerList )
        return;
    }
    LOBYTE(v2) = 1;
    (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v5 + 88i64))(v5, v2);
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
  UFG::qList<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList,1,0> *p_m_SafePointerList; // rsi
  Creature *v3; // rbx

  if ( !gDisablePoseDrivers && !this->mLowPowerModeEnabled && !this->mDisablePosedrivers )
  {
    p_m_SafePointerList = &this->m_SafePointerList;
    v3 = (Creature *)&this->mPoseDrivers.mNode.mNext[-1];
    if ( v3 != (Creature *)&this->m_SafePointerList )
    {
      do
      {
        if ( !((unsigned __int8 (__fastcall *)(Creature *))v3->vfptr[13].__vecDelDtor)(v3) )
          v3->vfptr[17].__vecDelDtor(v3, (unsigned int)&this->mPose);
        v3 = (Creature *)&v3->mPoseDrivers.mNode.mPrev[-1];
      }
      while ( v3 != (Creature *)p_m_SafePointerList );
    }
  }
}

// File Line: 2572
// RVA: 0x3B8B40
void __fastcall Creature::updateEffectorsToPosePostPhysics(Creature *this)
{
  UFG::qList<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList,1,0> *p_m_SafePointerList; // rsi
  Creature *v3; // rbx

  if ( !gDisablePoseDrivers && !this->mLowPowerModeEnabled && !this->mDisablePosedrivers )
  {
    p_m_SafePointerList = &this->m_SafePointerList;
    v3 = (Creature *)&this->mPoseDrivers.mNode.mNext[-1];
    if ( v3 != (Creature *)&this->m_SafePointerList )
    {
      do
      {
        if ( !((unsigned __int8 (__fastcall *)(Creature *))v3->vfptr[13].__vecDelDtor)(v3) )
          v3->vfptr[18].__vecDelDtor(v3, (unsigned int)&this->mPose);
        v3 = (Creature *)&v3->mPoseDrivers.mNode.mPrev[-1];
      }
      while ( v3 != (Creature *)p_m_SafePointerList );
    }
  }
}

// File Line: 2616
// RVA: 0x3AB0A0
char __fastcall Creature::IsEndEffector(Creature *this, int attachBoneID)
{
  char *v3; // r14
  UFG::qList<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList,1,0> *p_m_SafePointerList; // rsi
  Creature *v5; // rbx
  UFG::qList<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList,1,0> *v7; // rsi
  Creature *v8; // rbx

  if ( attachBoneID >= 4 )
  {
LABEL_5:
    p_m_SafePointerList = &this->m_SafePointerList;
    v5 = (Creature *)&this->mPoseDrivers.mNode.mNext[-1];
    if ( v5 != (Creature *)&this->m_SafePointerList )
    {
      while ( ((unsigned int (__fastcall *)(Creature *))v5->vfptr[14].__vecDelDtor)(v5) != attachBoneID )
      {
        v5 = (Creature *)&v5->mPoseDrivers.mNode.mPrev[-1];
        if ( v5 == (Creature *)p_m_SafePointerList )
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
      while ( ((unsigned int (__fastcall *)(Creature *))v8->vfptr[14].__vecDelDtor)(v8) != attachBoneID )
      {
        v8 = (Creature *)&v8->mPoseDrivers.mNode.mPrev[-1];
        if ( v8 == (Creature *)v7 )
          goto LABEL_12;
      }
      v3[216] = 1;
      return 1;
    }
LABEL_12:
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
  UFG::qList<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList,1,0> *p_m_SafePointerList; // rdi
  Creature *v5; // rbx
  __int64 v8; // rdx
  UFG::qColour v9; // [rsp+20h] [rbp-18h] BYREF

  p_m_SafePointerList = &this->m_SafePointerList;
  v5 = (Creature *)&this->mPoseDrivers.mNode.mNext[-1];
  if ( v5 != (Creature *)&this->m_SafePointerList )
  {
    while ( ((unsigned int (__fastcall *)(Creature *))v5->vfptr[14].__vecDelDtor)(v5) != attachBoneID )
    {
      v5 = (Creature *)&v5->mPoseDrivers.mNode.mPrev[-1];
      if ( v5 == (Creature *)p_m_SafePointerList )
        return;
    }
    ((void (__fastcall *)(Creature *, SkeletalPose *, UFG::qMatrix44 *))v5->vfptr[15].__vecDelDtor)(
      v5,
      &this->mPose,
      matrix);
    LOBYTE(v8) = 1;
    v5->vfptr[11].__vecDelDtor(v5, v8);
    v5->vfptr[17].__vecDelDtor(v5, (unsigned int)&this->mPose);
    if ( sShowIKPose )
    {
      v9 = UFG::qColour::Green;
      SkeletalPose::DebugDraw(&this->mPose, &v9, COERCE_DOUBLE((unsigned __int64)(unsigned int)FLOAT_1_0));
    }
  }
}

// File Line: 2670
// RVA: 0x3A4BE0
void __fastcall Creature::BuildPoseDriver(Creature *this, UFG::qSymbolUC *poseDriverSet)
{
  UFG::qNode<RigInfo,RigInfo> *v3; // rcx
  char *v4; // rax
  UFG::qString v5; // [rsp+28h] [rbp-B0h] BYREF
  char dest[136]; // [rsp+50h] [rbp-88h] BYREF

  if ( poseDriverSet->mUID != -1 )
  {
    v3 = RigInfoDataBase::sRigInfoDataBase->mRigInfos.mNode.mNext - 1;
    if ( v3 == (UFG::qNode<RigInfo,RigInfo> *)RigInfoDataBase::sRigInfoDataBase )
    {
LABEL_7:
      v4 = UFG::qSymbol::as_cstr_dbg(poseDriverSet);
      UFG::qSPrintf(dest, "Data\\Global\\Act\\%s.rig2", v4);
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
      RigInfo::AddToCreature((RigInfo *)v3, this);
    }
  }
}

// File Line: 2711
// RVA: 0x14BF6B0
__int64 dynamic_initializer_for__sRightShoulderTwistUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("RightShoulderTwist", -1);
  sRightShoulderTwistUID = result;
  return result;
}

// File Line: 2712
// RVA: 0x14BF530
__int64 dynamic_initializer_for__sLeftShoulderTwistUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("LeftShoulderTwist", -1);
  sLeftShoulderTwistUID = result;
  return result;
}

// File Line: 2713
// RVA: 0x14BF690
__int64 dynamic_initializer_for__sRightShoulderTwistPoseUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("RightShoulderTwistPose", -1);
  sRightShoulderTwistPoseUID = result;
  return result;
}

// File Line: 2714
// RVA: 0x14BF510
__int64 dynamic_initializer_for__sLeftShoulderTwistPoseUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("LeftShoulderTwistPose", -1);
  sLeftShoulderTwistPoseUID = result;
  return result;
}

// File Line: 2715
// RVA: 0x14BF650
__int64 dynamic_initializer_for__sRightForearmTwistUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("RightForearmTwist", -1);
  sRightForearmTwistUID = result;
  return result;
}

// File Line: 2716
// RVA: 0x14BF4D0
__int64 dynamic_initializer_for__sLeftForearmTwistUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("LeftForearmTwist", -1);
  sLeftForearmTwistUID = result;
  return result;
}

// File Line: 2717
// RVA: 0x14BF630
__int64 dynamic_initializer_for__sRightArmIKUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("RightArmIK", -1);
  sRightArmIKUID = result;
  return result;
}

// File Line: 2718
// RVA: 0x14BF4B0
__int64 dynamic_initializer_for__sLeftArmIKUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("LeftArmIK", -1);
  sLeftArmIKUID = result;
  return result;
}

// File Line: 2719
// RVA: 0x14BF670
__int64 dynamic_initializer_for__sRightLegIKUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("RightLegIK", -1);
  sRightLegIKUID = result;
  return result;
}

// File Line: 2720
// RVA: 0x14BF4F0
__int64 dynamic_initializer_for__sLeftLegIKUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("LeftLegIK", -1);
  sLeftLegIKUID = result;
  return result;
}

// File Line: 2722
// RVA: 0x14BF460
__int64 dynamic_initializer_for__sHeadTrackerUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("HeadTracker", -1);
  sHeadTrackerUID = result;
  return result;
}

// File Line: 2723
// RVA: 0x14BF5F0
__int64 dynamic_initializer_for__sR_EyeTrackerUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("R_EyeTracker", -1);
  sR_EyeTrackerUID = result;
  return result;
}

// File Line: 2724
// RVA: 0x14BF490
__int64 dynamic_initializer_for__sL_EyeTrackerUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("L_EyeTracker", -1);
  sL_EyeTrackerUID = result;
  return result;
}

// File Line: 2725
// RVA: 0x14BF6D0
__int64 dynamic_initializer_for__sSpineTrackerUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("SpineTracker", -1);
  sSpineTrackerUID = result;
  return result;
}

// File Line: 2742
// RVA: 0x3B84E0
void __fastcall updateAndApplyEffector(Creature *creature, TwoLinkIKsolver *IKEffector, UFG::qMatrix44 *worldTarget)
{
  unsigned __int8 v6; // al
  __int64 v7; // rdx
  unsigned __int8 v8; // si

  v6 = ((__int64 (__fastcall *)(TwoLinkIKsolver *))IKEffector->vfptr[1].FindWithOldPath)(IKEffector);
  LOBYTE(v7) = 1;
  v8 = v6;
  IKEffector->vfptr[1].__vecDelDtor(IKEffector, v7);
  creature = (Creature *)((char *)creature + 240);
  ((void (__fastcall *)(TwoLinkIKsolver *, Creature *, UFG::qMatrix44 *))IKEffector->vfptr[1].GetClassNameUID)(
    IKEffector,
    creature,
    worldTarget);
  TwoLinkIKsolver::UpdateWorldTarget(IKEffector, (SkeletalPose *)creature);
  ((void (__fastcall *)(TwoLinkIKsolver *, Creature *))IKEffector->vfptr[1].ResolveReferences)(IKEffector, creature);
  IKEffector->vfptr[1].__vecDelDtor(IKEffector, v8);
}

// File Line: 2758
// RVA: 0x14BF700
__int64 dynamic_initializer_for__sUpperBodyWeightSet__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("UpperBody_Ragdoll", -1);
  sUpperBodyWeightSet = result;
  return result;
}

// File Line: 2759
// RVA: 0x14BF610
__int64 dynamic_initializer_for__sRagdoll_NoControlBonesWeightSet__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Ragdoll_NoControlBones", -1);
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
  SkeletalPose *v8; // rbx
  UFG::qList<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList,1,0> *p_m_SafePointerList; // rax
  UFG::qNode<PoseDriver,PoseDriver> *v10; // r13
  TwoLinkIKsolver *v11; // rbx
  int v12; // eax
  int v13; // eax
  SkeletalPose *p_mPose; // r14
  unsigned int v15; // edx
  WeightSetGroup *mWeightSetData; // r14
  UFG::qWiseSymbol *v17; // rax
  unsigned int v18; // ecx
  unsigned int mUID; // r10d
  __int64 mOffset; // r8
  __int64 v21; // rax
  __int64 v22; // rdx
  _QWORD *v23; // rdx
  char *v24; // rdi
  int m_size; // r12d
  __int64 v26; // rcx
  float *weightset_array; // r8
  float v28; // xmm0_4
  __int64 v29; // rax
  int v30; // r10d
  unsigned __int64 v31; // r9
  int v32; // edx
  __int64 v33; // rcx
  __m128 v34; // xmm1
  int v35; // eax
  __int64 v36; // r11
  unsigned __int64 v37; // rdi
  __int64 v38; // rcx
  unsigned __int64 v39; // rax
  __int64 v40; // r10
  unsigned __int64 v41; // r9
  float *v42; // rax
  float *v43; // rdi
  __int64 v44; // rcx
  int v45; // eax
  hkQsTransformf *Root; // rax
  hkaPose *mHavokPose; // rdi
  unsigned int *m_data; // rcx
  __int64 v49; // rbx
  hkQsTransformf *v50; // rax
  __m128 v51; // xmm2
  __m128 v52; // xmm1
  __m128 v53; // xmm6
  __m128 v54; // xmm5
  __m128 v55; // xmm4
  __m128 v56; // xmm2
  __m128 m_quad; // xmm3
  __m128 v58; // xmm5
  __m128 v59; // xmm6
  __m128 v60; // xmm3
  __m128 v61; // xmm4
  __m128 v62; // xmm6
  __m128 v63; // xmm2
  __m128 v64; // xmm9
  __m128 v65; // xmm9
  __m128 v66; // xmm1
  __m128 v67; // xmm10
  __m128 v68; // xmm10
  __m128 v69; // xmm0
  __m128 v70; // xmm1
  __m128 v71; // xmm8
  __m128 v72; // xmm4
  __m128 v73; // xmm8
  __m128 v74; // xmm3
  __m128 v75; // xmm9
  __m128 v76; // xmm1
  __m128 v77; // xmm3
  __m128 v78; // xmm2
  __m128 v79; // xmm1
  __m128 v80; // xmm8
  __m128 v81; // xmm2
  __m128 v82; // xmm1
  __m128 v83; // xmm10
  hkaPose *v84; // r12
  unsigned int *v85; // rdi
  __m128 *p_m_quad; // rdx
  __int16 *v87; // rcx
  __int16 v88; // ax
  hkQsTransformf *v89; // rax
  __m128 *v90; // rbx
  __m128 *v91; // rdi
  __m128i inserted; // xmm0
  __m128 v93; // xmm8
  __m128 v94; // xmm6
  __m128 v95; // xmm2
  __m128 v96; // xmm7
  __m128 v97; // xmm5
  __m128 *v98; // rax
  __m128 v99; // xmm3
  __m128 v100; // xmm0
  __m128 v101; // xmm1
  __m128 v102; // xmm9
  __m128 v103; // xmm4
  __m128 v104; // xmm2
  __m128 v105; // xmm2
  __m128 v106; // xmm3
  __m128 v107; // xmm4
  __m128 v108; // xmm1
  __m128 v109; // xmm8
  __m128 v110; // xmm4
  __m128 v111; // xmm4
  __m128 *v112; // rax
  __m128 *v113; // rax
  __m128 v114; // xmm6
  __m128 v115; // xmm7
  __m128 v116; // xmm8
  hkQsTransformf *v117; // rax
  __m128 v118; // xmm3
  __m128 v119; // xmm1
  __m128 v120; // xmm4
  __m128 v121; // xmm2
  __m128 v122; // xmm9
  __m128 v123; // xmm2
  __m128 v124; // xmm9
  __m128 v125; // xmm10
  __m128 v126; // xmm0
  __m128 v127; // xmm7
  __m128 v128; // xmm10
  __m128 v129; // xmm2
  __m128 v130; // xmm7
  __m128 v131; // xmm10
  hkQsTransformf *v132; // rbx
  __m128i v133; // xmm0
  __m128 v134; // xmm11
  __m128 v135; // xmm12
  __m128 v136; // xmm0
  __m128 v137; // xmm6
  __m128 v138; // xmm1
  __m128 v139; // xmm5
  __m128 v140; // xmm15
  __m128 v141; // xmm3
  __m128 v142; // xmm8
  __m128 v143; // xmm1
  __m128 v144; // xmm8
  __m128 v145; // xmm2
  __m128 v146; // xmm14
  __m128 v147; // xmm1
  __m128 v148; // xmm14
  __m128 v149; // xmm6
  __m128 v150; // xmm14
  __m128 v151; // xmm2
  __m128 v152; // xmm15
  __m128 v153; // xmm14
  __m128 v154; // xmm15
  __m128 v155; // xmm15
  hkaPose *v156; // r15
  __int64 v157; // rdx
  hkaSkeleton *m_skeleton; // rax
  __int64 v159; // r12
  __int64 v160; // rcx
  __int64 v161; // r8
  __int64 v162; // r14
  __int64 v163; // rdx
  unsigned int *v164; // rdi
  __int64 v165; // rcx
  hkQsTransformf *v166; // rax
  hkQsTransformf *v167; // rbx
  __m128 *v168; // rdi
  __m128 v169; // xmm8
  __m128 v170; // xmm0
  __int64 v171; // rax
  __m128 v172; // xmm7
  __m128 v173; // xmm5
  __m128 v174; // xmm3
  __m128 v175; // xmm1
  __m128 v176; // xmm4
  __m128i v177; // xmm9
  __m128 v178; // xmm1
  __m128 v179; // xmm2
  __m128 v180; // xmm2
  __m128 v181; // xmm3
  __m128 v182; // xmm1
  __m128 v183; // xmm4
  __m128 v184; // xmm8
  __m128 v185; // xmm4
  __m128 v186; // xmm4
  unsigned int *v187; // rcx
  unsigned int v188; // eax
  __m128 *v189; // rax
  UFG::qNode<PoseDriver,PoseDriver> *v190; // r14
  UFG::qNode<PoseDriver,PoseDriver> *v191; // rcx
  UFG::qList<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList,1,0> *v192; // rdx
  UFG::qNode<PoseDriver,PoseDriver> *v193; // rdi
  UFG::qNode<PoseDriver,PoseDriver> *v194; // rax
  UFG::qNode<PoseDriver,PoseDriver> *v195; // r15
  UFG::qNode<PoseDriver,PoseDriver> *v196; // r12
  __int64 v197; // r8
  __int64 v198; // r9
  SkeletalPose *v199; // rax
  float v200; // xmm5_4
  float v201; // xmm4_4
  float v202; // xmm3_4
  float v203; // xmm2_4
  float v204; // xmm1_4
  unsigned __int8 v205; // [rsp+30h] [rbp-B0h]
  UFG::qWiseSymbol result[2]; // [rsp+38h] [rbp-A8h] BYREF
  __m128 *v207; // [rsp+40h] [rbp-A0h]
  TwoLinkIKsolver *v208; // [rsp+48h] [rbp-98h]
  UFG::qNode<PoseDriver,PoseDriver> *v209; // [rsp+50h] [rbp-90h]
  __int64 v210; // [rsp+58h] [rbp-88h]
  hkVector4f v211; // [rsp+60h] [rbp-80h] BYREF
  hkVector4f v212; // [rsp+70h] [rbp-70h] BYREF
  UFG::qMatrix44 toMatrixWS; // [rsp+80h] [rbp-60h] BYREF
  __m128 v214; // [rsp+C0h] [rbp-20h]
  UFG::qMatrix44 matrixWS; // [rsp+D0h] [rbp-10h] BYREF
  __m128 v216; // [rsp+110h] [rbp+30h]
  hkQuaternionf quat; // [rsp+120h] [rbp+40h] BYREF
  __m128 v218; // [rsp+130h] [rbp+50h]
  UFG::qMatrix44 worldTarget; // [rsp+140h] [rbp+60h] BYREF
  UFG::qMatrix44 v220; // [rsp+180h] [rbp+A0h] BYREF
  Creature *creature; // [rsp+2B0h] [rbp+1D0h]
  SkeletalPose *inputPose; // [rsp+2B8h] [rbp+1D8h]
  unsigned int vars0; // [rsp+2C0h] [rbp+1E0h]
  void *retaddr; // [rsp+2C8h] [rbp+1E8h]

  v4 = 0i64;
  v5 = weight;
  v6 = pose;
  if ( gDrawPoseExternalInputPose )
  {
    v211.m_quad = (__m128)UFG::qColour::DeepPink;
    SkeletalPose::DebugDraw(pose, (UFG::qColour *)&v211, COERCE_DOUBLE((unsigned __int64)(unsigned int)FLOAT_1_0));
    if ( gDrawPosePostAnimUpdate )
    {
      v8 = SkeletalPose::Clone(&this->mPose);
      SkeletalPose::Blend(v8, &this->mPose, 1.0, 0xFFFFFFFF, 1, 0i64);
      SkeletalPose::GetPositionWS(v8, 0, &matrixWS);
      SkeletalPose::GetPositionWS(v6, 0, &toMatrixWS);
      AttachPose(v8, &matrixWS, &toMatrixWS);
      v211.m_quad = (__m128)UFG::qColour::DarkViolet;
      SkeletalPose::DebugDraw(v8, (UFG::qColour *)&v211, COERCE_DOUBLE((unsigned __int64)(unsigned int)FLOAT_1_0));
      if ( v8 )
      {
        SkeletalPose::~SkeletalPose(v8);
        operator delete[](v8);
      }
    }
  }
  p_m_SafePointerList = &this->m_SafePointerList;
  v10 = this->mPoseDrivers.mNode.mNext - 1;
  v11 = (TwoLinkIKsolver *)v10;
  v209 = v10;
  v208 = (TwoLinkIKsolver *)v10;
  if ( v10 == (UFG::qNode<PoseDriver,PoseDriver> *)&this->m_SafePointerList )
  {
LABEL_8:
    v11 = 0i64;
    v208 = 0i64;
  }
  else
  {
    while ( v11->mName.mUID != sRightLegIKUID )
    {
      v11 = (TwoLinkIKsolver *)&v11->mNext[-1];
      v208 = v11;
      if ( v11 == (TwoLinkIKsolver *)p_m_SafePointerList )
        goto LABEL_8;
    }
  }
  if ( v10 == (UFG::qNode<PoseDriver,PoseDriver> *)p_m_SafePointerList )
  {
LABEL_12:
    v10 = 0i64;
    v209 = 0i64;
  }
  else
  {
    while ( HIDWORD(v10[2].mNext) != sLeftLegIKUID )
    {
      v10 = v10[1].mNext - 1;
      v209 = v10;
      if ( v10 == (UFG::qNode<PoseDriver,PoseDriver> *)p_m_SafePointerList )
        goto LABEL_12;
    }
  }
  if ( v11 && v10 )
  {
    v12 = (int)v11->vfptr[1].GetClassname(v11);
    SkeletalPose::GetPositionWS(&this->mPose, v12, &worldTarget);
    v13 = ((__int64 (__fastcall *)(UFG::qNode<PoseDriver,PoseDriver> *))v10->mPrev[7].mPrev)(v10);
    SkeletalPose::GetPositionWS(&this->mPose, v13, &v220);
  }
  if ( !sUseLowerBody && !sUseRagdollNoControlBones )
  {
    p_mPose = &this->mPose;
    SkeletalPose::Blend(&this->mPose, v6, weight, 0x1Bu, 1, 0i64);
    goto LABEL_64;
  }
  if ( weight == 1.0 )
  {
    v5 = FLOAT_0_99000001;
    vars0 = LODWORD(FLOAT_0_99000001);
  }
  v15 = sRagdoll_NoControlBonesWeightSet;
  if ( sUseLowerBody )
    v15 = sUpperBodyWeightSet;
  mWeightSetData = this->mPose.mRigHandle.mUFGSkeleton->mWeightSetData;
  v17 = UFG::qSymbol::qSymbol(result, v15);
  v18 = 0;
  if ( (mWeightSetData->mWeightsets.mCount & 0x7FFFFFFF) != 0 )
  {
    mUID = v17->mUID;
    mOffset = mWeightSetData->mWeightsets.mData.mOffset;
    v21 = 0i64;
    while ( 1 )
    {
      v22 = mOffset ? (__int64)&mWeightSetData->mWeightsets.mData + mOffset : 0i64;
      v23 = (_QWORD *)(v21 + v22);
      v24 = *v23 ? (char *)v23 + *v23 : 0i64;
      if ( *((_DWORD *)v24 + 4) == mUID )
        break;
      ++v18;
      v21 += 8i64;
      if ( v18 >= (mWeightSetData->mWeightsets.mCount & 0x7FFFFFFFu) )
        goto LABEL_33;
    }
  }
  else
  {
LABEL_33:
    v24 = 0i64;
  }
  p_mPose = &this->mPose;
  SkeletalPose::GetPositionMS(&this->mPose, 2, &toMatrixWS);
  m_size = v6->mHavokPose->m_skeleton->m_bones.m_size;
  if ( (unsigned int)m_size > 0x1B )
    m_size = 27;
  if ( !v24 )
    goto LABEL_62;
  if ( v5 != 1.0 || (unsigned int)m_size > *((_DWORD *)v24 + 11) )
  {
    weightset_array = (float *)UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 4 * m_size, 0x10u);
    v28 = (float)(*((_DWORD *)v24 + 6) & 0x7FFFFFFF);
    if ( v28 >= (float)m_size )
      v28 = (float)m_size;
    v29 = *((_QWORD *)v24 + 6);
    v30 = (int)v28;
    if ( v29 )
      v31 = (unsigned __int64)&v24[v29 + 48];
    else
      v31 = 0i64;
    v32 = 0;
    if ( v30 >= 8 )
    {
      v33 = v30 - 1;
      v34 = _mm_shuffle_ps((__m128)vars0, (__m128)vars0, 0);
      if ( (unsigned __int64)weightset_array > v31 + 4 * v33 || (unsigned __int64)&weightset_array[v33] < v31 )
      {
        do
        {
          *(__m128 *)&weightset_array[v32] = _mm_mul_ps(*(__m128 *)(v31 + 4i64 * v32), v34);
          v35 = v32 + 4;
          v32 += 8;
          *(__m128 *)&weightset_array[v35] = _mm_mul_ps(*(__m128 *)(v31 + 4i64 * v35), v34);
        }
        while ( v32 < (int)v28 - ((int)v28 & 7) );
      }
    }
    v36 = v32;
    if ( v32 < (__int64)v30 )
    {
      if ( v30 - (__int64)v32 >= 4 )
      {
        v37 = v31 - (_QWORD)weightset_array;
        v38 = (__int64)&weightset_array[v32 + 1];
        v39 = ((unsigned __int64)(v30 - (__int64)v32 - 4) >> 2) + 1;
        v36 = v32 + 4 * v39;
        v32 += 4 * v39;
        do
        {
          v38 += 16i64;
          *(float *)(v38 - 20) = v5 * *(float *)(v37 + v38 - 20);
          *(float *)(v38 - 16) = v5 * *(float *)(v37 + v38 - 16);
          *(float *)(v38 - 12) = v5 * *(float *)(v37 + v38 - 12);
          *(float *)(v38 - 8) = v5 * *(float *)(v37 + v38 - 8);
          --v39;
        }
        while ( v39 );
      }
      if ( v36 < v30 )
      {
        v40 = v30 - v36;
        v41 = v31 - (_QWORD)weightset_array;
        v42 = &weightset_array[v36];
        v32 += v40;
        do
        {
          ++v42;
          *(v42 - 1) = v5 * *(float *)((char *)v42 + v41 - 4);
          --v40;
        }
        while ( v40 );
      }
    }
    *(float *)&v207 = v5 * 255.0;
    if ( v32 < (__int64)m_size )
    {
      v43 = &weightset_array[v32];
      v44 = m_size - (__int64)v32;
      v45 = (int)v207;
      while ( v44 )
      {
        *(_DWORD *)v43++ = v45;
        --v44;
      }
    }
    goto LABEL_63;
  }
  v26 = *((_QWORD *)v24 + 6);
  if ( v26 )
    weightset_array = (float *)&v24[v26 + 48];
  else
LABEL_62:
    weightset_array = 0i64;
LABEL_63:
  v6 = inputPose;
  SkeletalPose::Blend(&this->mPose, inputPose, v5, 0x1Bu, 1, weightset_array);
  SkeletalPose::SetPositionMS(&this->mPose, 2, &toMatrixWS);
LABEL_64:
  if ( (_BYTE)retaddr )
  {
    Root = SkeletalPose::GetRoot(v6);
    mHavokPose = v6->mHavokPose;
    m_data = mHavokPose->m_boneFlags.m_data;
    v49 = (__int64)Root;
    v210 = (__int64)Root;
    if ( (*(_BYTE *)m_data & 2) != 0 )
      v50 = hkaPose::calculateBoneModelSpace(mHavokPose, 0);
    else
      v50 = mHavokPose->m_modelPose.m_data;
    v51 = *(__m128 *)(v49 + 16);
    v52 = _mm_mul_ps(v50->m_translation.m_quad, v51);
    v53 = _mm_shuffle_ps(v51, v51, 255);
    v54 = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(v50->m_translation.m_quad, v50->m_translation.m_quad, 201), v51),
            _mm_mul_ps(_mm_shuffle_ps(v51, v51, 201), v50->m_translation.m_quad));
    v55 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v52, v52, 85), _mm_shuffle_ps(v52, v52, 0)),
                  _mm_shuffle_ps(v52, v52, 170)),
                v51),
              _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v53, v53), (__m128)xmmword_141A711B0), v50->m_translation.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v54, v54, 201), v53));
    v216 = _mm_add_ps(_mm_add_ps(v55, v55), *(__m128 *)v49);
    v56 = *(__m128 *)(v49 + 16);
    m_quad = v50->m_rotation.m_vec.m_quad;
    v58 = _mm_shuffle_ps(m_quad, m_quad, 255);
    v59 = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v56),
            _mm_mul_ps(_mm_shuffle_ps(v56, v56, 201), m_quad));
    v60 = _mm_mul_ps(m_quad, v56);
    v61 = _mm_shuffle_ps(v56, v56, 255);
    v62 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v59, v59, 201), _mm_mul_ps(v50->m_rotation.m_vec.m_quad, v61)),
            _mm_mul_ps(v56, v58));
    quat.m_vec.m_quad = _mm_shuffle_ps(
                          v62,
                          _mm_unpackhi_ps(
                            v62,
                            _mm_sub_ps(
                              _mm_mul_ps(v58, v61),
                              _mm_add_ps(
                                _mm_add_ps(_mm_shuffle_ps(v60, v60, 85), _mm_shuffle_ps(v60, v60, 0)),
                                _mm_shuffle_ps(v60, v60, 170)))),
                          196);
    v218 = _mm_mul_ps(v50->m_scale.m_quad, *(__m128 *)(v49 + 32));
    hkVector4f::setRotatedDir(&v211, &quat, &direction);
    v63 = _mm_shuffle_ps(stru_141A71280.m_quad, stru_141A71280.m_quad, 201);
    v64 = _mm_sub_ps(
            _mm_mul_ps(v211.m_quad, v63),
            _mm_mul_ps(_mm_shuffle_ps(v211.m_quad, v211.m_quad, 201), stru_141A71280.m_quad));
    v65 = _mm_shuffle_ps(v64, v64, 201);
    v66 = _mm_shuffle_ps(v65, v65, 201);
    v67 = _mm_sub_ps(_mm_mul_ps(stru_141A71280.m_quad, v66), _mm_mul_ps(v65, v63));
    v68 = _mm_shuffle_ps(v67, v67, 201);
    v69 = _mm_mul_ps(v68, v66);
    v70 = _mm_mul_ps(v65, v65);
    v71 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v68, v68, 201), v65), v69);
    v72 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v70, v70, 85), _mm_shuffle_ps(v70, v70, 0)),
            _mm_shuffle_ps(v70, v70, 170));
    v73 = _mm_shuffle_ps(v71, v71, 201);
    v74 = _mm_rsqrt_ps(v72);
    v75 = _mm_mul_ps(
            v65,
            _mm_andnot_ps(
              _mm_cmple_ps(v72, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v74, v72), v74)),
                _mm_mul_ps(v74, *(__m128 *)_xmm))));
    v76 = _mm_mul_ps(v73, v73);
    v77 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v76, v76, 85), _mm_shuffle_ps(v76, v76, 0)),
            _mm_shuffle_ps(v76, v76, 170));
    v78 = _mm_rsqrt_ps(v77);
    v79 = _mm_mul_ps(v68, v68);
    v80 = _mm_mul_ps(
            v73,
            _mm_andnot_ps(
              _mm_cmple_ps(v77, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v78, v77), v78)),
                _mm_mul_ps(v78, *(__m128 *)_xmm))));
    v81 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v79, v79, 85), _mm_shuffle_ps(v79, v79, 0)),
            _mm_shuffle_ps(v79, v79, 170));
    v82 = _mm_rsqrt_ps(v81);
    v83 = _mm_mul_ps(
            v68,
            _mm_andnot_ps(
              _mm_cmple_ps(v81, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v82, v81), v82)),
                _mm_mul_ps(v82, *(__m128 *)_xmm))));
    v84 = this->mPose.mHavokPose;
    v211.m_quad = _mm_sub_ps(v83, _mm_mul_ps(v83, qi.m_vec.m_quad));
    matrixWS.v1 = (UFG::qVector4)v211.m_quad;
    matrixWS.v0 = (UFG::qVector4)_mm_sub_ps(v75, _mm_mul_ps(v75, qi.m_vec.m_quad));
    matrixWS.v2 = (UFG::qVector4)_mm_sub_ps(v80, _mm_mul_ps(v80, qi.m_vec.m_quad));
    v85 = v84->m_boneFlags.m_data;
    if ( (*(_BYTE *)v85 & 1) != 0 )
    {
      p_m_quad = &v84->m_modelPose.m_data->m_translation.m_quad;
      v87 = v84->m_skeleton->m_parentIndices.m_data;
      v207 = p_m_quad;
      v88 = *v87;
      if ( *v87 == -1 )
      {
        v112 = &v84->m_localPose.m_data->m_translation.m_quad;
        *v112 = *p_m_quad;
        v112[1] = p_m_quad[1];
        v112[2] = p_m_quad[2];
      }
      else
      {
        if ( (v85[v88] & 2) != 0 )
          v89 = hkaPose::calculateBoneModelSpace(v84, v88);
        else
          v89 = (hkQsTransformf *)&p_m_quad[3 * v88];
        v90 = &v84->m_localPose.m_data->m_translation.m_quad;
        v91 = &v89->m_rotation.m_vec.m_quad;
        *(_QWORD *)&result[0].mUID = v89;
        hkVector4f::setRotatedInverseDir(&v212, &v89->m_rotation, &v89->m_translation);
        inserted = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
        v93 = _mm_xor_ps((__m128)_mm_shuffle_epi32(inserted, 64), *v91);
        v94 = _mm_xor_ps((__m128)_mm_shuffle_epi32(inserted, 0), v212.m_quad);
        v211.m_quad = v93;
        v95 = _mm_rcp_ps(*(__m128 *)(*(_QWORD *)&result[0].mUID + 32i64));
        v96 = _mm_shuffle_ps(v93, v93, 255);
        v97 = _mm_shuffle_ps(v93, v93, 201);
        v212.m_quad = v94;
        v98 = v207;
        v99 = *v207;
        v100 = _mm_mul_ps(v97, *v207);
        v101 = _mm_mul_ps(v93, *v207);
        v102 = (__m128)_mm_srli_si128(
                         _mm_slli_si128(
                           (__m128i)_mm_mul_ps(
                                      _mm_sub_ps(
                                        (__m128)_xmm,
                                        _mm_mul_ps(v95, *(__m128 *)(*(_QWORD *)&result[0].mUID + 32i64))),
                                      v95),
                           4),
                         4);
        v212.m_quad = v102;
        v103 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v99, v99, 201), v93), v100);
        v104 = _mm_add_ps(
                 _mm_add_ps(
                   _mm_mul_ps(
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v101, v101, 85), _mm_shuffle_ps(v101, v101, 0)),
                       _mm_shuffle_ps(v101, v101, 170)),
                     v93),
                   _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v96, v96), (__m128)xmmword_141A711B0), v99)),
                 _mm_mul_ps(_mm_shuffle_ps(v103, v103, 201), v96));
        *v90 = _mm_add_ps(_mm_add_ps(v104, v104), v94);
        v105 = v98[1];
        v106 = _mm_shuffle_ps(v105, v105, 255);
        v107 = _mm_mul_ps(_mm_shuffle_ps(v105, v105, 201), v93);
        v108 = _mm_mul_ps(v93, v106);
        v109 = _mm_mul_ps(v93, v105);
        v110 = _mm_sub_ps(v107, _mm_mul_ps(v105, v97));
        v111 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v110, v110, 201), _mm_mul_ps(v105, v96)), v108);
        v90[1] = _mm_shuffle_ps(
                   v111,
                   _mm_unpackhi_ps(
                     v111,
                     _mm_sub_ps(
                       _mm_mul_ps(v106, v96),
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v109, v109, 85), _mm_shuffle_ps(v109, v109, 0)),
                         _mm_shuffle_ps(v109, v109, 170)))),
                   196);
        v90[2] = _mm_mul_ps(v98[2], v102);
        v49 = v210;
      }
      *v84->m_boneFlags.m_data &= ~1u;
    }
    v113 = &v84->m_localPose.m_data->m_translation.m_quad;
    v114 = *v113;
    v115 = v113[1];
    v116 = v113[2];
    v117 = SkeletalPose::GetRoot(p_mPose);
    v118 = v117->m_rotation.m_vec.m_quad;
    v119 = _mm_mul_ps(v114, v118);
    v120 = _mm_shuffle_ps(v118, v118, 255);
    v121 = _mm_sub_ps(
             _mm_mul_ps(_mm_shuffle_ps(v114, v114, 201), v118),
             _mm_mul_ps(_mm_shuffle_ps(v118, v118, 201), v114));
    v122 = _mm_add_ps(
             _mm_add_ps(
               _mm_mul_ps(
                 _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v119, v119, 85), _mm_shuffle_ps(v119, v119, 0)),
                   _mm_shuffle_ps(v119, v119, 170)),
                 v118),
               _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v120, v120), (__m128)xmmword_141A711B0), v114)),
             _mm_mul_ps(_mm_shuffle_ps(v121, v121, 201), v120));
    v123 = _mm_shuffle_ps(v115, v115, 255);
    v124 = _mm_add_ps(_mm_add_ps(v122, v122), v117->m_translation.m_quad);
    v125 = _mm_sub_ps(
             _mm_mul_ps(_mm_shuffle_ps(v115, v115, 201), v118),
             _mm_mul_ps(_mm_shuffle_ps(v118, v118, 201), v115));
    v126 = v115;
    v127 = _mm_mul_ps(v115, v118);
    v128 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v125, v125, 201), _mm_mul_ps(v126, v120)), _mm_mul_ps(v118, v123));
    v129 = _mm_sub_ps(
             _mm_mul_ps(v123, v120),
             _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v127, v127, 85), _mm_shuffle_ps(v127, v127, 0)),
               _mm_shuffle_ps(v127, v127, 170)));
    v130 = _mm_mul_ps(v117->m_scale.m_quad, v116);
    v131 = _mm_shuffle_ps(v128, _mm_unpackhi_ps(v128, v129), 196);
    toMatrixWS.v0 = *(UFG::qVector4 *)v49;
    hkQuaternionf::set((hkQuaternionf *)&toMatrixWS.v1, (hkRotationf *)&matrixWS);
    toMatrixWS.v2 = *(UFG::qVector4 *)(v49 + 32);
    SkeletalPose::SetRoot(p_mPose, (hkQsTransformf *)&toMatrixWS, 0);
    v132 = SkeletalPose::GetRoot(p_mPose);
    hkVector4f::setRotatedInverseDir(&v212, &v132->m_rotation, &v132->m_translation);
    v133 = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
    v134 = (__m128)_mm_shuffle_epi32(v133, 0);
    v135 = (__m128)_mm_shuffle_epi32(v133, 64);
    v136 = v132->m_scale.m_quad;
    v137 = _mm_xor_ps(v135, v132->m_rotation.m_vec.m_quad);
    v138 = _mm_rcp_ps(v136);
    v139 = _mm_shuffle_ps(v137, v137, 255);
    v140 = _mm_mul_ps(_mm_shuffle_ps(v131, v131, 201), v137);
    v141 = _mm_shuffle_ps(v137, v137, 201);
    v142 = (__m128)_mm_srli_si128(
                     _mm_slli_si128((__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v136, v138)), v138), 4),
                     4);
    v143 = _mm_mul_ps(v137, v124);
    v144 = _mm_mul_ps(v142, v130);
    v145 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v124, v124, 201), v137), _mm_mul_ps(v124, v141));
    v146 = _mm_add_ps(
             _mm_add_ps(_mm_shuffle_ps(v143, v143, 85), _mm_shuffle_ps(v143, v143, 0)),
             _mm_shuffle_ps(v143, v143, 170));
    v147 = v137;
    v148 = _mm_mul_ps(v146, v137);
    v149 = _mm_mul_ps(v137, v131);
    v150 = _mm_add_ps(
             _mm_add_ps(v148, _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v139, v139), (__m128)xmmword_141A711B0), v124)),
             _mm_mul_ps(_mm_shuffle_ps(v145, v145, 201), v139));
    v151 = _mm_shuffle_ps(v131, v131, 255);
    v152 = _mm_sub_ps(v140, _mm_mul_ps(v131, v141));
    v153 = _mm_add_ps(_mm_add_ps(v150, v150), _mm_xor_ps(v212.m_quad, v134));
    v154 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v152, v152, 201), _mm_mul_ps(v131, v139)), _mm_mul_ps(v147, v151));
    v155 = _mm_shuffle_ps(
             v154,
             _mm_unpackhi_ps(
               v154,
               _mm_sub_ps(
                 _mm_mul_ps(v151, v139),
                 _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v149, v149, 85), _mm_shuffle_ps(v149, v149, 0)),
                   _mm_shuffle_ps(v149, v149, 170)))),
             196);
    v156 = this->mPose.mHavokPose;
    v157 = 1i64;
    m_skeleton = v156->m_skeleton;
    v214 = v144;
    v159 = 1i64;
    v160 = m_skeleton->m_bones.m_size;
    *v156->m_boneFlags.m_data |= 4u;
    v161 = v160;
    v207 = (__m128 *)v160;
    if ( v160 > 1 )
    {
      v162 = 1i64;
      do
      {
        LOWORD(v163) = v156->m_skeleton->m_parentIndices.m_data[v159];
        if ( (_WORD)v163 != 0xFFFF )
        {
          v164 = v156->m_boneFlags.m_data;
          if ( (v164[(__int16)v163] & 4) != 0 )
          {
            if ( (v164[v159] & 1) != 0 )
            {
              v165 = (__int64)v156->m_modelPose.m_data;
              v210 = v165;
              v163 = (__int16)v163;
              if ( (v164[(__int16)v163] & 2) != 0 )
                v166 = hkaPose::calculateBoneModelSpace(v156, v163);
              else
                v166 = (hkQsTransformf *)(v165 + 48 * v163);
              v167 = v156->m_localPose.m_data;
              v168 = &v166->m_rotation.m_vec.m_quad;
              *(_QWORD *)&result[0].mUID = v166;
              hkVector4f::setRotatedInverseDir(&v212, &v166->m_rotation, &v166->m_translation);
              v169 = _mm_xor_ps(*v168, v135);
              v170 = *(__m128 *)(*(_QWORD *)&result[0].mUID + 32i64);
              v171 = v210;
              v172 = _mm_shuffle_ps(v169, v169, 255);
              v173 = _mm_shuffle_ps(v169, v169, 201);
              v174 = *(__m128 *)(v210 + v162 * 48);
              v175 = _mm_rcp_ps(v170);
              v176 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v174, v174, 201), v169), _mm_mul_ps(v173, v174));
              v177 = _mm_slli_si128((__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v170, v175)), v175), 4);
              v178 = _mm_mul_ps(v169, v174);
              v179 = _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(
                           _mm_add_ps(
                             _mm_add_ps(_mm_shuffle_ps(v178, v178, 85), _mm_shuffle_ps(v178, v178, 0)),
                             _mm_shuffle_ps(v178, v178, 170)),
                           v169),
                         _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v172, v172), (__m128)xmmword_141A711B0), v174)),
                       _mm_mul_ps(_mm_shuffle_ps(v176, v176, 201), v172));
              v167[v162].m_translation.m_quad = _mm_add_ps(_mm_add_ps(v179, v179), _mm_xor_ps(v212.m_quad, v134));
              v180 = *(__m128 *)(v171 + v162 * 48 + 16);
              v181 = _mm_shuffle_ps(v180, v180, 255);
              v182 = _mm_mul_ps(v169, v181);
              v183 = _mm_mul_ps(_mm_shuffle_ps(v180, v180, 201), v169);
              v184 = _mm_mul_ps(v169, v180);
              v185 = _mm_sub_ps(v183, _mm_mul_ps(v180, v173));
              v186 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v185, v185, 201), _mm_mul_ps(v180, v172)), v182);
              v161 = (__int64)v207;
              v167[v162].m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                                     v186,
                                                     _mm_unpackhi_ps(
                                                       v186,
                                                       _mm_sub_ps(
                                                         _mm_mul_ps(v181, v172),
                                                         _mm_add_ps(
                                                           _mm_add_ps(
                                                             _mm_shuffle_ps(v184, v184, 85),
                                                             _mm_shuffle_ps(v184, v184, 0)),
                                                           _mm_shuffle_ps(v184, v184, 170)))),
                                                     196);
              v167[v162].m_scale.m_quad = _mm_mul_ps(
                                            *(__m128 *)(v171 + v162 * 48 + 32),
                                            (__m128)_mm_srli_si128(v177, 4));
              v156->m_boneFlags.m_data[v159] &= ~1u;
            }
            v156->m_boneFlags.m_data[v159] |= 4u;
            v156->m_modelInSync.m_bool = 0;
          }
        }
        ++v159;
        ++v162;
      }
      while ( v159 < v161 );
      v144 = v214;
      v157 = 1i64;
    }
    if ( v161 > 1 )
    {
      do
      {
        v187 = v156->m_boneFlags.m_data;
        v188 = v187[v157];
        if ( (v188 & 4) != 0 )
          v187[v157] = v188 & 0xFFFFFFF9 | 2;
        ++v157;
      }
      while ( v157 < v161 );
    }
    v189 = &v156->m_localPose.m_data->m_translation.m_quad;
    v11 = v208;
    *v189 = v153;
    v189[1] = v155;
    v189[2] = v144;
    *v156->m_boneFlags.m_data = 2;
    v156->m_modelInSync.m_bool = 0;
  }
  if ( sApplyDrivers )
  {
    v190 = 0i64;
    v191 = 0i64;
    v192 = &creature->m_SafePointerList;
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
        if ( !v4 && HIDWORD(v194[2].mNext) == sLeftShoulderTwistUID )
          v4 = v194;
        if ( !v190 && HIDWORD(v194[2].mNext) == sRightShoulderTwistUID )
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
      v10 = v209;
      v11 = v208;
      *(_QWORD *)&result[0].mUID = v191;
      if ( v4 )
      {
        LOBYTE(v192) = 1;
        ((void (__fastcall *)(UFG::qNode<PoseDriver,PoseDriver> *, UFG::qList<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList,1,0> *, _QWORD, _QWORD))v4->mPrev[5].mNext)(
          v4,
          v192,
          sLeftShoulderTwistUID,
          sRightShoulderTwistUID);
      }
      if ( v190 )
      {
        LOBYTE(v192) = 1;
        ((void (__fastcall *)(UFG::qNode<PoseDriver,PoseDriver> *, UFG::qList<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList,1,0> *, __int64, __int64))v190->mPrev[5].mNext)(
          v190,
          v192,
          v197,
          v198);
      }
      if ( *(_QWORD *)&result[0].mUID )
      {
        LOBYTE(v192) = 1;
        (*(void (__fastcall **)(_QWORD, UFG::qList<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList,1,0> *, __int64, __int64))(**(_QWORD **)&result[0].mUID + 88i64))(
          *(_QWORD *)&result[0].mUID,
          v192,
          v197,
          v198);
      }
      if ( v193 )
      {
        LOBYTE(v192) = 1;
        ((void (__fastcall *)(UFG::qNode<PoseDriver,PoseDriver> *, UFG::qList<UFG::qSafePointerBase<Creature>,UFG::qSafePointerNodeList,1,0> *, __int64, __int64))v193->mPrev[5].mNext)(
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
  if ( v11 && v10 && sUseLowerBody )
  {
    updateAndApplyEffector(creature, v11, &worldTarget);
    updateAndApplyEffector(creature, (TwoLinkIKsolver *)v10, &v220);
  }
  Creature::UpdateAttachmentPoses(creature);
  v199 = &creature->mPose;
  v200 = creature->mPose.mPoseAABBMin.y * 2.5;
  v201 = creature->mPose.mPoseAABBMin.z * 2.5;
  v202 = creature->mPose.mPoseAABBMax.x * 2.5;
  v203 = creature->mPose.mPoseAABBMax.y * 2.5;
  v204 = creature->mPose.mPoseAABBMax.z * 2.5;
  creature->mPose.mPoseAABBMin.x = creature->mPose.mPoseAABBMin.x * 2.5;
  v199->mPoseAABBMin.y = v200;
  v199->mPoseAABBMin.z = v201;
  v199->mPoseAABBMax.x = v202;
  v199->mPoseAABBMax.y = v203;
  v199->mPoseAABBMax.z = v204;
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
// attributes: thunk
void __fastcall Creature::ForceSyncPose(Creature *this)
{
  Creature::UpdateAttachmentPoses(this);
}

// File Line: 3090
// RVA: 0x3B0410
void __fastcall Creature::UnbindResources(Creature *this)
{
  PoseNodeParent *p_mBlendTree; // rcx
  Expression::IMemberMapVtbl *vfptr; // rax
  void **v3; // [rsp+20h] [rbp-18h] BYREF
  char v4; // [rsp+28h] [rbp-10h]

  p_mBlendTree = &this->mBlendTree;
  v3 = &UnbindResourcesVisitor::`vftable;
  vfptr = p_mBlendTree->PoseNode::Expression::IMemberMap::vfptr;
  v4 = 1;
  vfptr[1].FindWithOldPath(p_mBlendTree, (const char *)&v3);
}

// File Line: 3096
// RVA: 0x3AD960
void __fastcall Creature::RebindResources(Creature *this)
{
  PoseNodeParent *p_mBlendTree; // rcx
  Expression::IMemberMapVtbl *vfptr; // rax
  void **v3; // [rsp+20h] [rbp-18h] BYREF
  char v4; // [rsp+28h] [rbp-10h]

  p_mBlendTree = &this->mBlendTree;
  v3 = &RebindResourcesVisitor::`vftable;
  vfptr = p_mBlendTree->PoseNode::Expression::IMemberMap::vfptr;
  v4 = 1;
  vfptr[1].FindWithOldPath(p_mBlendTree, (const char *)&v3);
}

// File Line: 3102
// RVA: 0x3AF620
void __fastcall Creature::SetPoseOnFrameBoundaries(Creature *this, bool val)
{
  PoseNodeParent *p_mBlendTree; // rcx
  Expression::IMemberMapVtbl *vfptr; // rax
  void **v4; // [rsp+20h] [rbp-28h] BYREF
  char v5; // [rsp+28h] [rbp-20h]
  bool v6; // [rsp+30h] [rbp-18h]

  p_mBlendTree = &this->mBlendTree;
  v6 = val;
  v4 = &PoseOnFrameBoundariesVisitor::`vftable;
  vfptr = p_mBlendTree->PoseNode::Expression::IMemberMap::vfptr;
  v5 = 1;
  vfptr[1].FindWithOldPath(p_mBlendTree, (const char *)&v4);
}

// File Line: 3109
// RVA: 0x3AAE60
void __fastcall Creature::InitWeightSet(Creature *this, const char *weightSetNameFile)
{
  Skeleton *mUFGSkeleton; // rbx

  mUFGSkeleton = this->mPose.mRigHandle.mUFGSkeleton;
  if ( mUFGSkeleton )
  {
    if ( !mUFGSkeleton->mWeightSetData )
      mUFGSkeleton->mWeightSetData = WeightSetDataBase::LoadWeightSetGroup(
                                       WeightSetDataBase::sWeightSetDataBase,
                                       weightSetNameFile);
  }
}

// File Line: 3126
// RVA: 0x3AA090
Weightset *__fastcall Creature::GetWeightSet(Creature *this, UFG::qSymbolUC *weightsetName)
{
  Skeleton *mUFGSkeleton; // rcx
  WeightSetGroup *mWeightSetData; // rcx

  mUFGSkeleton = this->mPose.mRigHandle.mUFGSkeleton;
  if ( mUFGSkeleton && (mWeightSetData = mUFGSkeleton->mWeightSetData) != 0i64 )
    return WeightSetGroup::FindWeightset(mWeightSetData, weightsetName);
  else
    return 0i64;
}

