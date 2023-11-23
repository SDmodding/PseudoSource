// File Line: 53
// RVA: 0x310830
void __fastcall AnimationBankReferenceTask::Begin(AnimationBankReferenceTask *this, ActionContext *pActionContext)
{
  ITrack *m_Track; // rax
  UFG::eAnimationPriorityEnum mResourceOwner_low; // ebp
  ITrack *v6; // r8
  unsigned __int64 v7; // rax
  const char *v8; // rdx
  UFG::qSymbolUC *v9; // rax
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::PowerManagementComponent *ComponentOfTypeHK; // rax
  UFG::qSymbolUC result; // [rsp+30h] [rbp+8h] BYREF

  m_Track = this->m_Track;
  mResourceOwner_low = LOBYTE(m_Track[1].mResourceOwner);
  v6 = m_Track + 1;
  v7 = (unsigned __int64)m_Track[1].vfptr & 0xFFFFFFFFFFFFFFFEui64;
  v8 = (char *)v6 + v7;
  if ( !v7 )
    v8 = BinString::sEmptyString;
  v9 = UFG::qSymbolUC::create_from_string(&result, v8);
  AnimationGroupHandle::Init(&this->mAnimationGroupHandle, v9, mResourceOwner_low);
  AnimationGroupHandle::Bind(&this->mAnimationGroupHandle);
  m_pPointer = (UFG::SimObjectGame *)pActionContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = (UFG::PowerManagementComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             m_pPointer,
                                                             UFG::PowerManagementComponent::_TypeUID);
    else
      ComponentOfTypeHK = (UFG::PowerManagementComponent *)UFG::SimObject::GetComponentOfType(
                                                             m_pPointer,
                                                             UFG::PowerManagementComponent::_TypeUID);
    if ( ComponentOfTypeHK )
      UFG::PowerManagementComponent::AddPowerManagedResource(ComponentOfTypeHK, &this->UFG::PowerManagedResource);
  }
}

// File Line: 77
// RVA: 0x312070
void __fastcall AnimationBankReferenceTask::End(AnimationBankReferenceTask *this)
{
  AnimationBankReferenceTask *v1; // rbx
  UFG::qNode<UFG::PowerManagedResource,UFG::PowerManagedResourceList> *mPrev; // rcx
  UFG::qNode<UFG::PowerManagedResource,UFG::PowerManagedResourceList> *mNext; // rax

  v1 = this;
  AnimationGroupHandle::Unbind(&this->mAnimationGroupHandle);
  mPrev = v1->UFG::PowerManagedResource::UFG::qNode<UFG::PowerManagedResource,UFG::PowerManagedResourceList>::mPrev;
  mNext = v1->UFG::PowerManagedResource::UFG::qNode<UFG::PowerManagedResource,UFG::PowerManagedResourceList>::mNext;
  v1 = (AnimationBankReferenceTask *)((char *)v1 + 48);
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v1->Task<AnimationBankReferenceTrack>::ITask::vfptr = (ITaskVtbl *)v1;
  v1->Task<AnimationBankReferenceTrack>::ITask::UFG::qNode<ITask,ITask>::mPrev = (UFG::qNode<ITask,ITask> *)v1;
}

// File Line: 95
// RVA: 0x312C90
void __fastcall AnimationBankReferenceTask::UnbindResources(AnimationBankReferenceTask *this)
{
  AnimationGroupHandle::Unbind((AnimationGroupHandle *)&this->m_Track);
}

// File Line: 104
// RVA: 0x3129B0
void __fastcall AnimationBankReferenceTask::RebindResources(AnimationBankReferenceTask *this)
{
  AnimationGroupHandle::Bind((AnimationGroupHandle *)&this->m_Track);
}

// File Line: 113
// RVA: 0x310750
bool __fastcall AnimationBankReferenceTask::AreResourcesAvailable(AnimationBankReferenceTask *this)
{
  AnimationGroup *mPrev; // rcx

  mPrev = (AnimationGroup *)this->mAnimationGroupHandle.mPrev;
  return mPrev && AnimationGroup::IsStreamedIn(mPrev);
}

// File Line: 126
// RVA: 0x310780
void __fastcall AnimationBankPriorityTask::Begin(AnimationBankPriorityTask *this, ActionContext *pActionContext)
{
  ITrack *m_Track; // rax
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::eAnimationPriorityEnum v4; // edi
  UFG::qSymbolUC *v5; // rbx
  __int16 m_Flags; // dx
  UFG::BaseAnimationComponent *m_pComponent; // rax

  m_Track = this->m_Track;
  m_pPointer = (UFG::SimObjectGame *)pActionContext->mSimObject.m_pPointer;
  v4 = BYTE4(m_Track[1].vfptr);
  v5 = (UFG::qSymbolUC *)&m_Track[1];
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::BaseAnimationComponent *)m_pPointer->m_Components.p[9].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = (UFG::BaseAnimationComponent *)m_pPointer->m_Components.p[8].m_pComponent;
      }
      else if ( (m_Flags & 0x1000) != 0 )
      {
        m_pComponent = (UFG::BaseAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        m_pPointer,
                                                        UFG::BaseAnimationComponent::_TypeUID);
      }
      else
      {
        m_pComponent = (UFG::BaseAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                        m_pPointer,
                                                        UFG::BaseAnimationComponent::_TypeUID);
      }
    }
    else
    {
      m_pComponent = (UFG::BaseAnimationComponent *)m_pPointer->m_Components.p[9].m_pComponent;
    }
    if ( m_pComponent )
      UFG::BaseAnimationComponent::SetAnimationBankPriority(m_pComponent, v5, v4);
  }
}

// File Line: 145
// RVA: 0x30F220
void __fastcall AnimationTask::AnimationTask(AnimationTask *this)
{
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<AnimationTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&AnimationTask::`vftable;
  this->mController.mPrev = &this->mController;
  this->mController.mNext = &this->mController;
  this->mController.m_pPointer = 0i64;
  this->mSplitBodyBlend.mPrev = &this->mSplitBodyBlend;
  this->mSplitBodyBlend.mNext = &this->mSplitBodyBlend;
  this->mSplitBodyBlend.m_pPointer = 0i64;
  this->mFinished = 1;
}

// File Line: 159
// RVA: 0x310B30
void __fastcall AnimationTask::Begin(AnimationTask *this, ActionContext *context)
{
  UFG::SimObject *m_pPointer; // rbx
  UFG::TransformNodeComponent *v5; // rbx
  float x; // xmm3_4
  __int128 y_low; // xmm4
  float z; // xmm5_4
  __m128 v9; // xmm2
  float v10; // xmm2_4
  UFG::qSymbolUC *v11; // r12
  UFG::SimObjectCVBase *v12; // rcx
  __int16 m_Flags; // dx
  UFG::CharacterAnimationComponent *v14; // rax
  Creature *mCreature; // r14
  float v16; // xmm6_4
  float v17; // xmm6_4
  ITrack *m_Track; // rdx
  char *v19; // rax
  BlendNode *v20; // rax
  BlendNode *v21; // r15
  PoseNode *v22; // rbx
  AnimationPlayMode value_low; // ebx
  char *v24; // rax
  AnimationNode *v25; // rax
  ITrack *v26; // rax
  int mOffset_high; // r9d
  PoseNodeParent *v28; // r8
  Weightset *WeightSet; // rax
  UFG::qNode<PoseNode,PoseNode> *v30; // rbx
  ITrack *v31; // rcx
  AnimationPlayMode v32; // r8d
  bool phaseIn; // al
  float blendInTime; // xmm1_4
  float v35; // xmm0_4
  AnimationNode *v36; // rax
  __int64 v37; // rdx
  char *v38; // rax
  BlendNode *v39; // rax
  char *v40; // rax
  AnimationPlayMode v41; // ebx
  char *v42; // rax
  AnimationNode *v43; // rax
  ITrack *v44; // rcx
  bool v45; // al
  AnimationNode *v46; // r14
  Expression::IMemberMapVtbl *vfptr; // rbx
  ITrack *v48; // rbx
  ActionNodePlayable *m_currentNode; // rdi
  const char *v50; // rdx
  ActionPath pathToPopulate; // [rsp+10h] [rbp-31h] BYREF
  UFG::qString check_null[3]; // [rsp+20h] [rbp-21h] BYREF
  int returnCode; // [rsp+A8h] [rbp+67h] BYREF
  char *v54; // [rsp+B0h] [rbp+6Fh]

  this->mContext = context;
  if ( context && context->mSimObject.m_pPointer && (context->mSimObject.m_pPointer->m_Flags & 0x400) != 0 )
    return;
  m_pPointer = context->mSimObject.m_pPointer;
  v5 = m_pPointer ? m_pPointer->m_pTransformNodeComponent : 0i64;
  UFG::TransformNodeComponent::UpdateWorldTransform(v5);
  x = v5->mWorldTransform.v0.x;
  y_low = LODWORD(v5->mWorldTransform.v0.y);
  z = v5->mWorldTransform.v0.z;
  this->mStartFacingVector.x = x;
  LODWORD(this->mStartFacingVector.y) = y_low;
  this->mStartFacingVector.z = z;
  v9 = (__m128)y_low;
  v9.m128_f32[0] = (float)((float)(*(float *)&y_low * *(float *)&y_low) + (float)(x * x)) + (float)(z * z);
  v10 = v9.m128_f32[0] == 0.0 ? 0.0 : 1.0 / _mm_sqrt_ps(v9).m128_f32[0];
  this->mStartFacingVector.x = v10 * x;
  this->mStartFacingVector.y = v10 * *(float *)&y_low;
  this->mStartFacingVector.z = v10 * z;
  v11 = (UFG::qSymbolUC *)&this->m_Track[1].mMasterRate.expression.mOffset + 1;
  v12 = (UFG::SimObjectCVBase *)this->mContext->mSimObject.m_pPointer;
  if ( !v12 )
    return;
  m_Flags = v12->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
  {
    v14 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v12);
  }
  else if ( (m_Flags & 0x2000) != 0 )
  {
    v14 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v12);
  }
  else
  {
    v14 = (UFG::CharacterAnimationComponent *)((m_Flags & 0x1000) != 0
                                             ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 v12,
                                                 UFG::CharacterAnimationComponent::_TypeUID)
                                             : UFG::SimObject::GetComponentOfType(
                                                 v12,
                                                 UFG::CharacterAnimationComponent::_TypeUID));
  }
  if ( !v14 )
    return;
  mCreature = v14->mCreature;
  if ( !mCreature )
    return;
  returnCode = 0;
  v16 = *(float *)&this->m_Track[1].m_TrackClassNameUID;
  v17 = v16 / ActionContext::GetRunningMasterRate(context);
  m_Track = this->m_Track;
  if ( BYTE1(m_Track[1].mMasterRate.value) == 1 )
  {
    v19 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0xB0ui64, "BlendAddNode", 0i64, 1u);
    v54 = v19;
    if ( v19 )
    {
      BlendAddNode::BlendAddNode((BlendAddNode *)v19, v17);
      v21 = v20;
    }
    else
    {
      v21 = 0i64;
    }
    UFG::qSafePointer<PoseNode,PoseNode>::operator=(
      (UFG::qSafePointer<PoseNode,BlendNode> *)&this->mSplitBodyBlend,
      v21);
    v22 = this->mSplitBodyBlend.m_pPointer;
    v22[1].mPrev = (UFG::qNode<PoseNode,PoseNode> *)Creature::GetWeightSet(
                                                      mCreature,
                                                      (UFG::qSymbolUC *)&this->m_Track[1].mMasterRate.expression);
    value_low = LOBYTE(this->m_Track[1].mMasterRate.value);
    v24 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x170ui64, "AnimationTask.AnimationNode", 0i64, 1u);
    v54 = v24;
    if ( v24 )
      AnimationNode::AnimationNode(
        (AnimationNode *)v24,
        v11,
        value_low,
        *(float *)&this->m_Track[1].mResourceOwner,
        *((float *)&this->m_Track[1].mResourceOwner + 1));
    else
      v25 = 0i64;
    UFG::qSafePointer<AnimationNode,AnimationNode>::operator=(&this->mController, v25);
    v26 = this->m_Track;
    check_null[0].mData = (char *)&returnCode;
    *(float *)&check_null[0].mMagic = FLOAT_N1_0;
    LODWORD(check_null[0].mNext) = 0;
    LOBYTE(check_null[0].mPrev) = 0;
    mOffset_high = HIDWORD(v26[1].mMasterRate.text.mOffset);
    v28 = v21;
  }
  else
  {
    WeightSet = Creature::GetWeightSet(mCreature, (UFG::qSymbolUC *)&m_Track[1].mMasterRate.expression);
    v30 = (UFG::qNode<PoseNode,PoseNode> *)WeightSet;
    v31 = this->m_Track;
    if ( SHIDWORD(v31[1].mMasterRate.text.mOffset) <= 0 && !WeightSet )
    {
      v32 = LOBYTE(v31[1].mMasterRate.value);
      phaseIn = *((_BYTE *)&v31[1].mMasterRate.value + 4) != 0;
      blendInTime = *(float *)&v31[1].m_TrackClassNameUID;
      v35 = *((float *)&v31[1].mResourceOwner + 1);
      check_null[0].mData = (char *)&returnCode;
      LOBYTE(check_null[0].mMagic) = phaseIn;
      *(float *)&check_null[0].mNext = blendInTime;
      *(float *)&check_null[0].mPrev = v35;
      v36 = (AnimationNode *)Creature::PlayAnimation(
                               mCreature,
                               v11,
                               v32,
                               *(float *)&v31[1].mResourceOwner,
                               v35,
                               blendInTime,
                               phaseIn,
                               &returnCode);
      UFG::qSafePointer<AnimationNode,AnimationNode>::operator=(&this->mController, v36);
      LOBYTE(v37) = *((_BYTE *)&this->m_Track[1].mMasterRate.value + 5) != 0;
      this->mController.m_pPointer->vfptr[3].__vecDelDtor(this->mController.m_pPointer, v37);
      goto LABEL_44;
    }
    LODWORD(check_null[0].mPrev) = 1;
    if ( *((_BYTE *)&v31[1].mMasterRate.value + 4) )
    {
      v38 = UFG::qMemoryPool2::Allocate(
              &gActionTreeMemoryPool,
              0xB8ui64,
              "BlendPhaseNode",
              0i64,
              (unsigned int)check_null[0].mPrev);
      v54 = v38;
      if ( v38 )
        BlendPhaseNode::BlendPhaseNode((BlendPhaseNode *)v38, v17);
      else
        v39 = 0i64;
    }
    else
    {
      v40 = UFG::qMemoryPool2::Allocate(
              &gActionTreeMemoryPool,
              0xB0ui64,
              "BlendNode",
              0i64,
              (unsigned int)check_null[0].mPrev);
      v54 = v40;
      if ( v40 )
        BlendNode::BlendNode((BlendNode *)v40, v17);
      else
        v39 = 0i64;
    }
    UFG::qSafePointer<PoseNode,PoseNode>::operator=(
      (UFG::qSafePointer<PoseNode,BlendNode> *)&this->mSplitBodyBlend,
      v39);
    this->mSplitBodyBlend.m_pPointer[1].mPrev = v30;
    BYTE3(this->mSplitBodyBlend.m_pPointer[1].mParent.mOffset) = 1;
    v41 = LOBYTE(this->m_Track[1].mMasterRate.value);
    v42 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x170ui64, "AnimationTask.AnimationNode", 0i64, 1u);
    v54 = v42;
    if ( v42 )
      AnimationNode::AnimationNode(
        (AnimationNode *)v42,
        v11,
        v41,
        *(float *)&this->m_Track[1].mResourceOwner,
        *((float *)&this->m_Track[1].mResourceOwner + 1));
    else
      v43 = 0i64;
    UFG::qSafePointer<AnimationNode,AnimationNode>::operator=(&this->mController, v43);
    v44 = this->m_Track;
    v45 = *((_BYTE *)&v44[1].mMasterRate.value + 4) != 0;
    check_null[0].mData = (char *)&returnCode;
    check_null[0].mMagic = HIDWORD(v44[1].mResourceOwner);
    LODWORD(check_null[0].mNext) = v44[1].mResourceOwner;
    LOBYTE(check_null[0].mPrev) = v45;
    mOffset_high = HIDWORD(v44[1].mMasterRate.text.mOffset);
    v28 = (PoseNodeParent *)this->mSplitBodyBlend.m_pPointer;
  }
  Creature::PlayBlendTree(
    mCreature,
    this->mController.m_pPointer,
    v28,
    mOffset_high,
    (bool)check_null[0].mPrev,
    *(float *)&check_null[0].mNext,
    *(float *)&check_null[0].mMagic,
    (int *)check_null[0].mData);
LABEL_44:
  v46 = this->mController.m_pPointer;
  if ( v46 )
  {
    vfptr = v46->PoseNode::Expression::IMemberMap::vfptr;
    ActionContext::GetRunningMasterRate(this->mContext);
    vfptr[3].ResolveReferences(v46);
    ((void (__fastcall *)(AnimationNode *, ActionContext *))this->mController.m_pPointer->vfptr[2].GetResourceOwner)(
      this->mController.m_pPointer,
      this->mContext);
    if ( BYTE2(this->m_Track[1].mMasterRate.value) )
    {
      this->mController.m_pPointer->mPlayStartTime = 0.0;
      ((void (__fastcall *)(AnimationNode *))this->mController.m_pPointer->vfptr[3].GetResourcePath)(this->mController.m_pPointer);
    }
  }
  if ( returnCode )
  {
    v48 = this->m_Track;
    m_currentNode = context->mActionController->m_currentNode;
    ActionNode::GetNameFullPath(m_currentNode, &pathToPopulate);
    ActionPath::GetString_DBG(&pathToPopulate);
    v48->vfptr->GetClassname(v48);
    m_currentNode->vfptr[3].GetClassNameUID(m_currentNode);
    UFG::qString::qString(check_null);
    if ( returnCode == 2 )
    {
      v50 = "BlendTree stack has blown Tree will be pruned could have some animation pops: inform FRSD of this ERROR message";
    }
    else
    {
      v50 = "Failed Active BlendTree Branch skipping and restarting: inform: FRSD of this ERROR message";
      if ( returnCode != 1 )
        v50 = "no special error";
    }
    UFG::qString::Set(check_null, v50);
    UFG::qString::~qString(check_null);
    if ( pathToPopulate.mPath.mCount >= 0 && pathToPopulate.mPath.mData.mOffset )
    {
      if ( (UFG::qOffset64<ActionID *> *)((char *)&pathToPopulate.mPath.mData + pathToPopulate.mPath.mData.mOffset) )
        operator delete[]((char *)&pathToPopulate.mPath.mData + pathToPopulate.mPath.mData.mOffset);
    }
  }
}

// File Line: 324
// RVA: 0x312D50
bool __fastcall AnimationTask::Update(AnimationTask *this, float timeDelta)
{
  ActionContext *mContext; // rax
  UFG::SimObject *m_pPointer; // rax
  AnimationNode *v7; // rcx
  UFG::SimObjectCVBase *v8; // rcx
  __int16 m_Flags; // dx
  UFG::CharacterAnimationComponent *v10; // rax
  AnimationNode *v11; // rsi
  ITrack *m_Track; // rax
  Expression::IMemberMapVtbl *vfptr; // rbx
  int value_low; // ebp
  FloatInputSignal v15; // r14d
  float v16; // xmm1_4
  UFG::SimObjectCVBase *v17; // rcx
  float v18; // xmm0_4
  Expression::IMemberMapVtbl *v19; // rax
  float y; // xmm1_4
  UFG::SimObjectCVBase *v21; // rcx
  float z; // xmm0_4
  UFG::qVector3 v23; // [rsp+30h] [rbp-28h] BYREF

  mContext = this->mContext;
  if ( mContext )
  {
    m_pPointer = mContext->mSimObject.m_pPointer;
    if ( m_pPointer )
    {
      if ( (m_pPointer->m_Flags & 0x400) != 0 )
        return 1;
    }
  }
  v7 = this->mController.m_pPointer;
  if ( v7 )
    AnimationNode::verifyBindAnimation(v7);
  v8 = (UFG::SimObjectCVBase *)this->mContext->mSimObject.m_pPointer;
  if ( !v8 )
    return 0;
  m_Flags = v8->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
  {
    v10 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v8);
  }
  else if ( (m_Flags & 0x2000) != 0 )
  {
    v10 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v8);
  }
  else
  {
    v10 = (UFG::CharacterAnimationComponent *)((m_Flags & 0x1000) != 0
                                             ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 v8,
                                                 UFG::CharacterAnimationComponent::_TypeUID)
                                             : UFG::SimObject::GetComponentOfType(
                                                 v8,
                                                 UFG::CharacterAnimationComponent::_TypeUID));
  }
  if ( !v10 )
    return 0;
  v11 = this->mController.m_pPointer;
  if ( !v11 || !v11->mSkeletalAnimationHandle.m_SkeletalAnimation.m_pPointer )
    return 0;
  m_Track = this->m_Track;
  vfptr = v11->PoseNode::Expression::IMemberMap::vfptr;
  value_low = LOBYTE(m_Track[1].mMasterRate.value);
  v15 = BYTE2(m_Track[1].mMasterRate.value);
  ActionContext::GetRunningMasterRate(this->mContext);
  vfptr[3].ResolveReferences(v11);
  if ( value_low == 1 )
  {
    if ( v15 )
    {
      y = this->mStartFacingVector.y;
      v21 = (UFG::SimObjectCVBase *)this->mContext->mSimObject.m_pPointer;
      v23.x = this->mStartFacingVector.x;
      z = this->mStartFacingVector.z;
      v23.y = y;
      v23.z = z;
      getSignalValue(v21, v15, timeDelta, 6.2831855, &v23);
      this->mController.m_pPointer->vfptr[3].ResolveReferences(this->mController.m_pPointer);
    }
  }
  else if ( v15 )
  {
    v16 = this->mStartFacingVector.y;
    v17 = (UFG::SimObjectCVBase *)this->mContext->mSimObject.m_pPointer;
    v23.x = this->mStartFacingVector.x;
    v18 = this->mStartFacingVector.z;
    v23.y = v16;
    v23.z = v18;
    getSignalValue(v17, v15, timeDelta, 6.2831855, &v23);
    v19 = this->mController.m_pPointer->vfptr;
    if ( value_low == 3 )
    {
      ((void (*)(void))v19[3].GetClassNameUID)();
      return 1;
    }
    ((void (*)(void))v19[3].ResolveReferences)();
    if ( value_low == 5
      && ((unsigned __int8 (__fastcall *)(AnimationNode *))this->mController.m_pPointer->vfptr[1].SetResourceOwner)(this->mController.m_pPointer) )
    {
      this->mController.m_pPointer->vfptr[1].GetResourceOwner(this->mController.m_pPointer);
      this->mFinished = 1;
      return 0;
    }
  }
  else if ( ((unsigned __int8 (__fastcall *)(AnimationNode *))this->mController.m_pPointer->vfptr[1].SetResourceOwner)(this->mController.m_pPointer) )
  {
    this->mController.m_pPointer->vfptr[1].GetResourceOwner(this->mController.m_pPointer);
    this->mFinished = 1;
    return value_low == 2;
  }
  return 1;
}

// File Line: 414
// RVA: 0x312210
void __fastcall AnimationTask::End(AnimationTask *this)
{
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rsi
  ITrack *m_Track; // rax
  float v4; // xmm6_4
  float RunningMasterRate; // xmm0_4
  PoseNode *m_pPointer; // rax
  float v7; // xmm6_4
  UFG::SimObjectCVBase *v8; // rcx
  UFG::AICharacterControllerBaseComponent *v9; // rbx
  __int16 m_Flags; // dx
  UFG::AICharacterControllerBaseComponent *ComponentOfTypeHK; // rax
  UFG::SimObject *v12; // rcx
  float y; // xmm0_4
  float z; // xmm1_4

  m_pTransformNodeComponent = 0i64;
  if ( this->mController.m_pPointer )
  {
    if ( this->mSplitBodyBlend.m_pPointer )
    {
      m_Track = this->m_Track;
      if ( SHIDWORD(m_Track[1].mMasterRate.text.mOffset) > 0 || BYTE1(m_Track[1].mMasterRate.value) == 1 )
      {
        v4 = *(float *)&m_Track[1].mBreakPoint;
        RunningMasterRate = ActionContext::GetRunningMasterRate(this->mContext);
        m_pPointer = this->mSplitBodyBlend.m_pPointer;
        v7 = v4 / RunningMasterRate;
        if ( v7 == 0.0 )
        {
          HIDWORD(m_pPointer[1].mParent.mOffset) = -1082130432;
          m_pPointer[1].mPriority = 0;
        }
        else
        {
          if ( v7 <= 0.0 )
            goto LABEL_10;
          *((float *)&m_pPointer[1].mParent.mOffset + 1) = -1.0 / v7;
        }
        BYTE3(m_pPointer[1].mParent.mOffset) = 0;
      }
    }
  }
LABEL_10:
  if ( *((_BYTE *)&this->m_Track[1].mMasterRate.value + 6) )
  {
    v8 = (UFG::SimObjectCVBase *)this->mContext->mSimObject.m_pPointer;
    if ( v8 )
    {
      m_Flags = v8->m_Flags;
      if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
      {
        ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v8);
      }
      else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      {
        ComponentOfTypeHK = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                         v8,
                                                                         UFG::AICharacterControllerBaseComponent::_TypeUID);
      }
      else
      {
        ComponentOfTypeHK = (UFG::AICharacterControllerBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                                         v8,
                                                                         UFG::AICharacterControllerBaseComponent::_TypeUID);
      }
      v9 = ComponentOfTypeHK;
    }
    else
    {
      v9 = 0i64;
    }
    v12 = this->mContext->mSimObject.m_pPointer;
    if ( v12 )
      m_pTransformNodeComponent = v12->m_pTransformNodeComponent;
    if ( v9 && m_pTransformNodeComponent && v9->m_Intention.mMotionIntentionSpeed <= 0.0 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
      y = m_pTransformNodeComponent->mWorldTransform.v0.y;
      z = m_pTransformNodeComponent->mWorldTransform.v0.z;
      v9->m_Intention.mMotionIntentionDirection.x = m_pTransformNodeComponent->mWorldTransform.v0.x;
      v9->m_Intention.mMotionIntentionDirection.y = y;
      v9->m_Intention.mMotionIntentionDirection.z = z;
      v9->m_IntentionUpdated = 1;
    }
  }
}

// File Line: 463
// RVA: 0x30F110
void __fastcall AnimationRefPoseTask::AnimationRefPoseTask(AnimationRefPoseTask *this)
{
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<AnimationRefPoseTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&AnimationRefPoseTask::`vftable;
  this->mController.mPrev = &this->mController;
  this->mController.mNext = &this->mController;
  this->mController.m_pPointer = 0i64;
  this->mSplitBodyBlend.mPrev = &this->mSplitBodyBlend;
  this->mSplitBodyBlend.mNext = &this->mSplitBodyBlend;
  this->mSplitBodyBlend.m_pPointer = 0i64;
  this->mFinished = 1;
}

// File Line: 467
// RVA: 0x310410
void __fastcall AnimationRefPoseTask::AddTheAnim(
        AnimationRefPoseTask *this,
        UFG::CharacterAnimationComponent *characterAnimationComponent)
{
  Creature *mCreature; // rbp
  AnimationNode *v4; // rsi
  ITrack *m_Track; // rax
  char *v6; // rax
  PoseNode *v7; // rax
  PoseNode *v8; // r8
  UFG::qSafePointer<PoseNode,PoseNode> *p_mSplitBodyBlend; // rdx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v12; // rax
  PoseNode *m_pPointer; // rbx
  char *v14; // rax
  AnimationNode *v15; // rax
  UFG::qSafePointer<AnimationNode,AnimationNode> *v16; // rdx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v17; // rcx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v18; // rax
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v19; // rax
  AnimationNode *v20; // rax
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qSafePointer<AnimationNode,AnimationNode> *p_mController; // r8
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *mNext; // rcx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *p_mNode; // rcx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v25; // rax
  AnimationNode *v26; // rdx
  int returnCode; // [rsp+78h] [rbp+10h] BYREF
  char *v28; // [rsp+80h] [rbp+18h]

  mCreature = characterAnimationComponent->mCreature;
  if ( mCreature )
  {
    v4 = 0i64;
    returnCode = 0;
    m_Track = this->m_Track;
    if ( (int)m_Track[1].m_TrackClassNameUID <= 0 )
    {
      v20 = (AnimationNode *)Creature::PlayAnimation(
                               mCreature,
                               &UFG::gNullQSymbolUC,
                               APM_NORMAL,
                               *(float *)&m_Track[1].vfptr,
                               *((float *)&m_Track[1].vfptr + 1),
                               *(float *)&m_Track[1].mResourceOwner,
                               0,
                               &returnCode);
      p_mController = &this->mController;
      if ( this->mController.m_pPointer )
      {
        mPrev = p_mController->mPrev;
        mNext = this->mController.mNext;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        p_mController->mPrev = p_mController;
        this->mController.mNext = &this->mController;
      }
      this->mController.m_pPointer = v20;
      if ( v20 )
      {
        p_mNode = &v20->UFG::qSafePointerNode<AnimationNode>::m_SafePointerList.mNode;
        v25 = v20->UFG::qSafePointerNode<AnimationNode>::m_SafePointerList.mNode.UFG::qSafePointerNode<AnimationNode>::mPrev;
        v25->mNext = p_mController;
        p_mController->mPrev = v25;
        this->mController.mNext = p_mNode;
        p_mNode->mPrev = p_mController;
      }
      LOBYTE(mPrev) = LOBYTE(this->m_Track[1].mMasterRate.text.mOffset) != 0;
      this->mController.m_pPointer->vfptr[3].__vecDelDtor(this->mController.m_pPointer, (unsigned int)mPrev);
    }
    else
    {
      v6 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0xB0ui64, "BlendNode", 0i64, 1u);
      v28 = v6;
      if ( v6 )
      {
        BlendNode::BlendNode((BlendNode *)v6, *(float *)&this->m_Track[1].mResourceOwner);
        v8 = v7;
      }
      else
      {
        v8 = 0i64;
      }
      p_mSplitBodyBlend = &this->mSplitBodyBlend;
      if ( this->mSplitBodyBlend.m_pPointer )
      {
        v10 = p_mSplitBodyBlend->mPrev;
        v11 = this->mSplitBodyBlend.mNext;
        v10->mNext = v11;
        v11->mPrev = v10;
        p_mSplitBodyBlend->mPrev = p_mSplitBodyBlend;
        this->mSplitBodyBlend.mNext = &this->mSplitBodyBlend;
      }
      this->mSplitBodyBlend.m_pPointer = v8;
      if ( v8 )
      {
        v12 = v8->m_SafePointerList.mNode.UFG::qSafePointerNode<PoseNode>::mPrev;
        v12->mNext = p_mSplitBodyBlend;
        p_mSplitBodyBlend->mPrev = v12;
        this->mSplitBodyBlend.mNext = &v8->m_SafePointerList.mNode;
        v8->m_SafePointerList.mNode.UFG::qSafePointerNode<PoseNode>::mPrev = p_mSplitBodyBlend;
      }
      m_pPointer = this->mSplitBodyBlend.m_pPointer;
      m_pPointer[1].mPrev = (UFG::qNode<PoseNode,PoseNode> *)Creature::GetWeightSet(
                                                               mCreature,
                                                               (UFG::qSymbolUC *)&this->m_Track[1].mBreakPoint);
      BYTE3(this->mSplitBodyBlend.m_pPointer[1].mParent.mOffset) = 1;
      v14 = UFG::qMemoryPool2::Allocate(
              &gActionTreeMemoryPool,
              0x170ui64,
              "AnimationRefPoseTask.AnimationNode",
              0i64,
              1u);
      v28 = v14;
      if ( v14 )
      {
        AnimationNode::AnimationNode(
          (AnimationNode *)v14,
          &UFG::gNullQSymbolUC,
          APM_NORMAL,
          *(float *)&this->m_Track[1].vfptr,
          -1.0);
        v4 = v15;
      }
      v16 = &this->mController;
      if ( this->mController.m_pPointer )
      {
        v17 = v16->mPrev;
        v18 = this->mController.mNext;
        v17->mNext = v18;
        v18->mPrev = v17;
        v16->mPrev = v16;
        this->mController.mNext = &this->mController;
      }
      this->mController.m_pPointer = v4;
      if ( v4 )
      {
        v19 = v4->UFG::qSafePointerNode<AnimationNode>::m_SafePointerList.mNode.UFG::qSafePointerNode<AnimationNode>::mPrev;
        v19->mNext = v16;
        v16->mPrev = v19;
        this->mController.mNext = &v4->UFG::qSafePointerNode<AnimationNode>::m_SafePointerList.mNode;
        v4->UFG::qSafePointerNode<AnimationNode>::m_SafePointerList.mNode.UFG::qSafePointerNode<AnimationNode>::mPrev = v16;
      }
      Creature::PlayBlendTree(
        mCreature,
        this->mController.m_pPointer,
        (PoseNodeParent *)this->mSplitBodyBlend.m_pPointer,
        this->m_Track[1].m_TrackClassNameUID,
        0,
        *(float *)&this->m_Track[1].vfptr,
        *((float *)&this->m_Track[1].vfptr + 1),
        &returnCode);
    }
    v26 = this->mController.m_pPointer;
    if ( v26 )
    {
      v26->mPlayEndTime = *((float *)&this->m_Track[1].vfptr + 1);
      ((void (__fastcall *)(AnimationNode *, ActionContext *))this->mController.m_pPointer->vfptr[2].GetResourceOwner)(
        this->mController.m_pPointer,
        this->mContext);
    }
  }
}

// File Line: 500
// RVA: 0x3109D0
void __fastcall AnimationRefPoseTask::Begin(AnimationRefPoseTask *this, ActionContext *context)
{
  UFG::SimObject *m_pPointer; // rax
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rdi
  float y; // xmm5_4
  float z; // xmm6_4
  float v7; // xmm2_4
  __m128 x_low; // xmm4
  __m128 v9; // xmm3
  UFG::SimObjectCVBase *v10; // rcx
  __int16 m_Flags; // dx
  UFG::CharacterAnimationComponent *ComponentOfTypeHK; // rax

  this->mContext = context;
  if ( !context || !context->mSimObject.m_pPointer || (context->mSimObject.m_pPointer->m_Flags & 0x400) == 0 )
  {
    m_pPointer = context->mSimObject.m_pPointer;
    if ( m_pPointer )
      m_pTransformNodeComponent = m_pPointer->m_pTransformNodeComponent;
    else
      m_pTransformNodeComponent = 0i64;
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
    y = m_pTransformNodeComponent->mWorldTransform.v0.y;
    z = m_pTransformNodeComponent->mWorldTransform.v0.z;
    v7 = 0.0;
    this->mStartFacingVector.x = m_pTransformNodeComponent->mWorldTransform.v0.x;
    this->mStartFacingVector.y = y;
    x_low = (__m128)LODWORD(this->mStartFacingVector.x);
    this->mStartFacingVector.z = z;
    v9 = x_low;
    v9.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(y * y)) + (float)(z * z);
    if ( v9.m128_f32[0] != 0.0 )
      v7 = 1.0 / _mm_sqrt_ps(v9).m128_f32[0];
    this->mStartFacingVector.x = x_low.m128_f32[0] * v7;
    this->mStartFacingVector.z = v7 * z;
    this->mStartFacingVector.y = v7 * y;
    v10 = (UFG::SimObjectCVBase *)this->mContext->mSimObject.m_pPointer;
    if ( v10 )
    {
      m_Flags = v10->m_Flags;
      if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
      {
        ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v10);
      }
      else if ( (m_Flags & 0x2000) != 0 )
      {
        ComponentOfTypeHK = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v10);
      }
      else if ( (m_Flags & 0x1000) != 0 )
      {
        ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                  v10,
                                                                  UFG::CharacterAnimationComponent::_TypeUID);
      }
      else
      {
        ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                                  v10,
                                                                  UFG::CharacterAnimationComponent::_TypeUID);
      }
      if ( ComponentOfTypeHK )
        AnimationRefPoseTask::AddTheAnim(this, ComponentOfTypeHK);
    }
  }
}

// File Line: 517
// RVA: 0x312CA0
char __fastcall AnimationRefPoseTask::Update(AnimationRefPoseTask *this, float timeDelta)
{
  ActionContext *mContext; // rcx
  UFG::SimObject *v4; // rax
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::CharacterAnimationComponent *ComponentOfTypeHK; // rax

  mContext = this->mContext;
  if ( (!mContext || (v4 = mContext->mSimObject.m_pPointer) == 0i64 || (v4->m_Flags & 0x400) == 0)
    && !this->mController.m_pPointer )
  {
    m_pPointer = (UFG::SimObjectCVBase *)mContext->mSimObject.m_pPointer;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
      {
        ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(m_pPointer);
      }
      else if ( (m_Flags & 0x2000) != 0 )
      {
        ComponentOfTypeHK = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)m_pPointer);
      }
      else if ( (m_Flags & 0x1000) != 0 )
      {
        ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                  m_pPointer,
                                                                  UFG::CharacterAnimationComponent::_TypeUID);
      }
      else
      {
        ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                                  m_pPointer,
                                                                  UFG::CharacterAnimationComponent::_TypeUID);
      }
      if ( ComponentOfTypeHK )
        AnimationRefPoseTask::AddTheAnim(this, ComponentOfTypeHK);
    }
  }
  return 1;
}

// File Line: 536
// RVA: 0x3120B0
void __fastcall AnimationRefPoseTask::End(AnimationRefPoseTask *this)
{
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rdi
  PoseNode *m_pPointer; // rdx
  float v4; // xmm1_4
  UFG::SimObjectCVBase *v5; // rcx
  UFG::AICharacterControllerBaseComponent *v6; // rbx
  __int16 m_Flags; // dx
  UFG::AICharacterControllerBaseComponent *ComponentOfTypeHK; // rax
  UFG::SimObject *v9; // rcx
  float y; // xmm0_4
  float z; // xmm1_4

  m_pTransformNodeComponent = 0i64;
  if ( this->mController.m_pPointer )
  {
    m_pPointer = this->mSplitBodyBlend.m_pPointer;
    if ( m_pPointer )
    {
      v4 = *((float *)&this->m_Track[1].mResourceOwner + 1);
      if ( v4 == 0.0 )
      {
        HIDWORD(m_pPointer[1].mParent.mOffset) = -1082130432;
        m_pPointer[1].mPriority = 0;
      }
      else
      {
        if ( v4 <= 0.0 )
          goto LABEL_8;
        *((float *)&m_pPointer[1].mParent.mOffset + 1) = -1.0 / v4;
      }
      BYTE3(m_pPointer[1].mParent.mOffset) = 0;
    }
  }
LABEL_8:
  if ( BYTE1(this->m_Track[1].mMasterRate.text.mOffset) )
  {
    v5 = (UFG::SimObjectCVBase *)this->mContext->mSimObject.m_pPointer;
    if ( v5 )
    {
      m_Flags = v5->m_Flags;
      if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
      {
        ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v5);
      }
      else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      {
        ComponentOfTypeHK = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                         v5,
                                                                         UFG::AICharacterControllerBaseComponent::_TypeUID);
      }
      else
      {
        ComponentOfTypeHK = (UFG::AICharacterControllerBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                                         v5,
                                                                         UFG::AICharacterControllerBaseComponent::_TypeUID);
      }
      v6 = ComponentOfTypeHK;
    }
    else
    {
      v6 = 0i64;
    }
    v9 = this->mContext->mSimObject.m_pPointer;
    if ( v9 )
      m_pTransformNodeComponent = v9->m_pTransformNodeComponent;
    if ( v6 && m_pTransformNodeComponent && v6->m_Intention.mMotionIntentionSpeed <= 0.0 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
      y = m_pTransformNodeComponent->mWorldTransform.v0.y;
      z = m_pTransformNodeComponent->mWorldTransform.v0.z;
      v6->m_Intention.mMotionIntentionDirection.x = m_pTransformNodeComponent->mWorldTransform.v0.x;
      v6->m_Intention.mMotionIntentionDirection.y = y;
      v6->m_Intention.mMotionIntentionDirection.z = z;
      v6->m_IntentionUpdated = 1;
    }
  }
}

// File Line: 573
// RVA: 0x30F080
void __fastcall AnimationLockHighLODTask::AnimationLockHighLODTask(AnimationLockHighLODTask *this)
{
  this->Task<AnimationLockHighLODTrack>::ITask::UFG::qNode<ITask,ITask>::mPrev = &this->UFG::qNode<ITask,ITask>;
  this->Task<AnimationLockHighLODTrack>::ITask::UFG::qNode<ITask,ITask>::mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<AnimationLockHighLODTrack>::`vftable;
  this->UFG::qNode<AnimationLockHighLODTask,AnimationLockHighLODList>::mPrev = &this->UFG::qNode<AnimationLockHighLODTask,AnimationLockHighLODList>;
  this->UFG::qNode<AnimationLockHighLODTask,AnimationLockHighLODList>::mNext = &this->UFG::qNode<AnimationLockHighLODTask,AnimationLockHighLODList>;
  this->vfptr = (ITaskVtbl *)&AnimationLockHighLODTask::`vftable;
}

// File Line: 583
// RVA: 0x310930
void __fastcall AnimationLockHighLODTask::Begin(AnimationLockHighLODTask *this, ActionContext *pActionContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::AnimationLODComponent *m_pComponent; // rax

  this->m_pActionContext = pActionContext;
  m_pPointer = (UFG::SimObjectGame *)pActionContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::AnimationLODComponent *)m_pPointer->m_Components.p[13].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        m_pComponent = (UFG::AnimationLODComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                       m_pPointer,
                                                       UFG::AnimationLODComponent::_TypeUID);
      else
        m_pComponent = (UFG::AnimationLODComponent *)UFG::SimObject::GetComponentOfType(
                                                       m_pPointer,
                                                       UFG::AnimationLODComponent::_TypeUID);
    }
    else
    {
      m_pComponent = (UFG::AnimationLODComponent *)m_pPointer->m_Components.p[13].m_pComponent;
    }
    if ( m_pComponent )
      UFG::AnimationLODComponent::AddAnimationLockHighLODTask(m_pComponent, this);
  }
}

// File Line: 605
// RVA: 0x311900
void __fastcall BlendTreeControllerBaseTask<BlendTreeControllerTargetDistancTrack>::Bind(
        BlendTreeControllerBaseTask<BlendTreeControllerTrack> *this,
        PoseNode *poseNode)
{
  Expression::IMemberMap *v3; // rax
  UFG::qSafePointer<PoseNode,PoseNode> *p_mPlayingTree; // rbx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *mNext; // rcx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *p_mResourceOwner; // rcx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *mResourceOwner; // rax

  v3 = poseNode->Expression::IMemberMap::vfptr[4].FindWithOldPath(poseNode, &this->m_Track[1]);
  p_mPlayingTree = &this->mPlayingTree;
  if ( p_mPlayingTree->m_pPointer )
  {
    mPrev = p_mPlayingTree->mPrev;
    mNext = p_mPlayingTree->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mPlayingTree->mPrev = p_mPlayingTree;
    p_mPlayingTree->mNext = p_mPlayingTree;
  }
  p_mPlayingTree->m_pPointer = (PoseNode *)v3;
  if ( v3 )
  {
    p_mResourceOwner = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v3[1].mResourceOwner;
    mResourceOwner = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)v3[1].mResourceOwner;
    mResourceOwner->mNext = p_mPlayingTree;
    p_mPlayingTree->mPrev = mResourceOwner;
    p_mPlayingTree->mNext = p_mResourceOwner;
    p_mResourceOwner->mPrev = p_mPlayingTree;
  }
}

// File Line: 613
// RVA: 0x30F640
void __fastcall BlendTreeTask::BlendTreeTask(BlendTreeTask *this)
{
  UFG::qSafePointer<PoseNode,PoseNode> *p_mPlayingTree; // rdx
  UFG::qSafePointer<PoseNode,BlendNode> *p_mSplitBodyBlend; // r8
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v6; // rax

  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<BlendTreeTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&BlendTreeTask::`vftable;
  p_mPlayingTree = &this->mPlayingTree;
  this->mPlayingTree.mPrev = &this->mPlayingTree;
  this->mPlayingTree.mNext = &this->mPlayingTree;
  this->mPlayingTree.m_pPointer = 0i64;
  p_mSplitBodyBlend = &this->mSplitBodyBlend;
  this->mSplitBodyBlend.mPrev = &this->mSplitBodyBlend;
  this->mSplitBodyBlend.mNext = &this->mSplitBodyBlend;
  this->mSplitBodyBlend.m_pPointer = 0i64;
  this->mActiveControllers.mNode.mPrev = &this->mActiveControllers.mNode;
  this->mActiveControllers.mNode.mNext = &this->mActiveControllers.mNode;
  if ( this->mSplitBodyBlend.m_pPointer )
  {
    mPrev = p_mSplitBodyBlend->mPrev;
    mNext = p_mSplitBodyBlend->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mSplitBodyBlend->mPrev = p_mSplitBodyBlend;
    p_mSplitBodyBlend->mNext = p_mSplitBodyBlend;
  }
  p_mSplitBodyBlend->m_pPointer = 0i64;
  if ( p_mPlayingTree->m_pPointer )
  {
    v5 = p_mPlayingTree->mPrev;
    v6 = p_mPlayingTree->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    p_mPlayingTree->mPrev = p_mPlayingTree;
    p_mPlayingTree->mNext = p_mPlayingTree;
  }
  p_mPlayingTree->m_pPointer = 0i64;
}

// File Line: 619
// RVA: 0x311300
void __fastcall BlendTreeTask::Begin(BlendTreeTask *this, ActionContext *context)
{
  UFG::SimObject *v4; // rax
  UFG::SimObjectCVBase *m_pPointer; // rcx
  unsigned int v6; // r14d
  __int16 m_Flags; // dx
  UFG::CharacterAnimationComponent *v8; // rax
  Creature *mCreature; // rdi
  float v10; // xmm6_4
  float v11; // xmm6_4
  ITrack *m_Track; // rcx
  UFG::qSymbolUC *v13; // r13
  BlendTreeDataBase *Instance; // rax
  PoseNode *BlendTree; // rax
  ITrack *v16; // rcx
  int mOffset_low; // r12d
  float v18; // xmm7_4
  float v19; // xmm8_4
  BlendNode *v20; // rax
  ITrack *v21; // rax
  char *v22; // rax
  BlendNode *v23; // rax
  BlendNode *v24; // r12
  PoseNode *v25; // rbx
  char *v26; // rax
  BlendNode *v27; // rax
  char *v28; // rax
  PoseNode *v29; // rbx
  BlendNode *v30; // rax
  ITrack *v31; // rbx
  ActionNodePlayable *m_currentNode; // rdi
  const char *v33; // rdx
  int mCount; // edx
  PoseNode *v35; // rcx
  __int64 v36; // r15
  PoseNode *v37; // rbx
  Expression::IMemberMapVtbl *vfptr; // rdi
  __int64 v39; // r12
  UFG::qList<IBlendTreeControllerTask,IBlendTreeControllerTask,0,0> *p_mActiveControllers; // rdi
  __int64 v41; // rcx
  _QWORD *v42; // rbx
  UFG::qNode<IBlendTreeControllerTask,IBlendTreeControllerTask> *mPrev; // rax
  ITrack *v44; // rdi
  ActionNodePlayable *v45; // rbx
  __int64 v46; // rax
  __int64 v47; // r10
  unsigned int v48; // r11d
  unsigned int v49; // edx
  __int64 v50; // r9
  __int64 v51; // rcx
  __int64 v52; // rax
  __int64 v53; // r8
  __int64 v54; // rax
  ITrack *v55; // rax
  int v56; // edx
  ActionPath pathToPopulate; // [rsp+8h] [rbp-51h] BYREF
  UFG::qString v58; // [rsp+18h] [rbp-41h] BYREF
  int v59; // [rsp+C0h] [rbp+67h] BYREF
  UFG::qSymbolUC animUID; // [rsp+C8h] [rbp+6Fh] BYREF
  int priority[2]; // [rsp+D0h] [rbp+77h]
  char *v62; // [rsp+D8h] [rbp+7Fh]

  this->mContext = context;
  animUID.mUID = (unsigned int)this->m_Track[1].mResourceOwner;
  if ( !context || (v4 = context->mSimObject.m_pPointer) == 0i64 || (v4->m_Flags & 0x400) == 0 )
  {
    m_pPointer = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
    v6 = 0;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
      {
        v8 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(m_pPointer);
      }
      else if ( (m_Flags & 0x2000) != 0 )
      {
        v8 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)m_pPointer);
      }
      else
      {
        v8 = (UFG::CharacterAnimationComponent *)((m_Flags & 0x1000) != 0
                                                ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    m_pPointer,
                                                    UFG::CharacterAnimationComponent::_TypeUID)
                                                : UFG::SimObject::GetComponentOfType(
                                                    m_pPointer,
                                                    UFG::CharacterAnimationComponent::_TypeUID));
      }
      if ( v8 )
      {
        mCreature = v8->mCreature;
        if ( mCreature )
        {
          v59 = 0;
          v10 = *(float *)&this->m_Track[1].m_TrackClassNameUID;
          v11 = v10 / ActionContext::GetRunningMasterRate(context);
          m_Track = this->m_Track;
          v13 = (UFG::qSymbolUC *)&m_Track[1].mResourceOwner + 1;
          if ( HIDWORD(m_Track[1].mResourceOwner) == symNone.mUID )
          {
            v30 = (BlendNode *)Creature::PlayBlendTree(
                                 mCreature,
                                 &animUID,
                                 SLOBYTE(m_Track[1].mMasterRate.expression.mOffset),
                                 v11,
                                 BYTE1(m_Track[1].mMasterRate.expression.mOffset) != 0,
                                 *(float *)&m_Track[1].mMasterRate.text.mOffset,
                                 *((float *)&m_Track[1].mMasterRate.text.mOffset + 1),
                                 &v59);
            UFG::qSafePointer<PoseNode,PoseNode>::operator=(
              (UFG::qSafePointer<PoseNode,BlendNode> *)&this->mPlayingTree,
              v30);
          }
          else
          {
            Instance = BlendTreeDataBase::GetInstance();
            BlendTree = BlendTreeDataBase::FindBlendTree(Instance, &animUID);
            if ( BlendTree )
            {
              v16 = this->m_Track;
              mOffset_low = SLOBYTE(v16[1].mMasterRate.expression.mOffset);
              priority[0] = mOffset_low;
              v18 = *(float *)&v16[1].mMasterRate.text.mOffset;
              v19 = *((float *)&v16[1].mMasterRate.text.mOffset + 1);
              v20 = (BlendNode *)((__int64 (__fastcall *)(PoseNode *))BlendTree->Expression::IMemberMap::vfptr[1].Serialize)(BlendTree);
              UFG::qSafePointer<PoseNode,PoseNode>::operator=(
                (UFG::qSafePointer<PoseNode,BlendNode> *)&this->mPlayingTree,
                v20);
              v21 = this->m_Track;
              LODWORD(v58.mNext) = 1;
              if ( BYTE3(v21[1].mMasterRate.expression.mOffset) == 1 )
              {
                v22 = UFG::qMemoryPool2::Allocate(
                        &gActionTreeMemoryPool,
                        0xB0ui64,
                        "BlendAddNode",
                        0i64,
                        (unsigned int)v58.mNext);
                v62 = v22;
                if ( v22 )
                {
                  BlendAddNode::BlendAddNode((BlendAddNode *)v22, v11);
                  v24 = v23;
                }
                else
                {
                  v24 = 0i64;
                }
                UFG::qSafePointer<PoseNode,PoseNode>::operator=(&this->mSplitBodyBlend, v24);
                v25 = this->mSplitBodyBlend.m_pPointer;
                v25[1].mPrev = (UFG::qNode<PoseNode,PoseNode> *)Creature::GetWeightSet(mCreature, v13);
                Creature::PlayBlendTree(mCreature, this->mPlayingTree.m_pPointer, v24, priority[0], 0, v18, v19, &v59);
                if ( BYTE2(this->m_Track[1].mMasterRate.expression.mOffset) == 2 )
                {
                  ((void (__fastcall *)(PoseNode *))this->mPlayingTree.m_pPointer->vfptr[2].SetResourceOwner)(this->mPlayingTree.m_pPointer);
                  ((void (__fastcall *)(PoseNode *))this->mPlayingTree.m_pPointer->vfptr[3].GetResourcePath)(this->mPlayingTree.m_pPointer);
                  this->mPlayingTree.m_pPointer->vfptr[1].GetResourceOwner(this->mPlayingTree.m_pPointer);
                }
              }
              else
              {
                if ( BYTE1(v21[1].mMasterRate.expression.mOffset) )
                {
                  v26 = UFG::qMemoryPool2::Allocate(
                          &gActionTreeMemoryPool,
                          0xB8ui64,
                          "BlendPhaseNode",
                          0i64,
                          (unsigned int)v58.mNext);
                  *(_QWORD *)priority = v26;
                  if ( v26 )
                    BlendPhaseNode::BlendPhaseNode((BlendPhaseNode *)v26, v11);
                  else
                    v27 = 0i64;
                }
                else
                {
                  v28 = UFG::qMemoryPool2::Allocate(
                          &gActionTreeMemoryPool,
                          0xB0ui64,
                          "BlendNode",
                          0i64,
                          (unsigned int)v58.mNext);
                  *(_QWORD *)priority = v28;
                  if ( v28 )
                    BlendNode::BlendNode((BlendNode *)v28, v11);
                  else
                    v27 = 0i64;
                }
                UFG::qSafePointer<PoseNode,PoseNode>::operator=(&this->mSplitBodyBlend, v27);
                BYTE3(this->mSplitBodyBlend.m_pPointer[1].mParent.mOffset) = 1;
                v29 = this->mSplitBodyBlend.m_pPointer;
                v29[1].mPrev = (UFG::qNode<PoseNode,PoseNode> *)Creature::GetWeightSet(mCreature, v13);
                Creature::PlayBlendTree(
                  mCreature,
                  this->mPlayingTree.m_pPointer,
                  (PoseNodeParent *)this->mSplitBodyBlend.m_pPointer,
                  mOffset_low,
                  0,
                  v18,
                  v19,
                  &v59);
              }
            }
          }
          if ( v59 )
          {
            v31 = this->m_Track;
            m_currentNode = context->mActionController->m_currentNode;
            ActionNode::GetNameFullPath(m_currentNode, &pathToPopulate);
            ActionPath::GetString_DBG(&pathToPopulate);
            v31->vfptr->GetClassname(v31);
            m_currentNode->vfptr[3].GetClassNameUID(m_currentNode);
            UFG::qString::qString(&v58);
            if ( v59 == 2 )
            {
              v33 = "BlendTree stack has blown Tree will be pruned could have some animation pops: inform FRSD of this ERROR message";
            }
            else
            {
              v33 = "Failed Active BlendTree Branch skipping and restarting: inform: FRSD of this ERROR message";
              if ( v59 != 1 )
                v33 = "no special error";
            }
            UFG::qString::Set(&v58, v33);
            UFG::qString::~qString(&v58);
            mCount = pathToPopulate.mPath.mCount;
            if ( pathToPopulate.mPath.mCount >= 0 )
            {
              if ( pathToPopulate.mPath.mData.mOffset
                && (UFG::qOffset64<ActionID *> *)((char *)&pathToPopulate.mPath.mData
                                                + pathToPopulate.mPath.mData.mOffset) )
              {
                operator delete[]((char *)&pathToPopulate.mPath.mData + pathToPopulate.mPath.mData.mOffset);
                mCount = pathToPopulate.mPath.mCount;
              }
              pathToPopulate.mPath.mData.mOffset = 0i64;
              pathToPopulate.mPath.mCount = mCount & 0x80000000;
            }
          }
        }
      }
    }
    v35 = this->mPlayingTree.m_pPointer;
    if ( v35 )
    {
      ((void (__fastcall *)(PoseNode *, ActionContext *))v35->Expression::IMemberMap::vfptr[2].GetResourceOwner)(
        v35,
        this->mContext);
      v36 = ((__int64 (__fastcall *)(ITrack *))this->m_Track->Task<BlendTreeTrack>::ITask::vfptr[1].GetResourcePath)(this->m_Track);
      v37 = this->mPlayingTree.m_pPointer;
      vfptr = v37->Expression::IMemberMap::vfptr;
      ActionContext::GetRunningMasterRate(this->mContext);
      vfptr[3].ResolveReferences(v37);
      v39 = v36 + *(_QWORD *)(v36 + 24) + 24i64;
      if ( (*(_DWORD *)(v36 + 16) & 0x7FFFFFFF) != 0 )
      {
        p_mActiveControllers = &this->mActiveControllers;
        do
        {
          v41 = *(_QWORD *)(v39 + 8i64 * v6) + v39 + 8i64 * v6;
          v42 = (_QWORD *)(*(__int64 (__fastcall **)(__int64, const char *))(*(_QWORD *)v41 + 80i64))(
                            v41,
                            "BlendTreeTask::Begin()");
          (*(void (__fastcall **)(_QWORD *, PoseNode *))(*v42 + 8i64))(v42, this->mPlayingTree.m_pPointer);
          (*(void (__fastcall **)(_QWORD *, ActionContext *))(*v42 + 16i64))(v42, this->mContext);
          mPrev = p_mActiveControllers->mNode.mPrev;
          mPrev->mNext = (UFG::qNode<IBlendTreeControllerTask,IBlendTreeControllerTask> *)(v42 + 1);
          v42[1] = mPrev;
          v42[2] = p_mActiveControllers;
          p_mActiveControllers->mNode.mPrev = (UFG::qNode<IBlendTreeControllerTask,IBlendTreeControllerTask> *)(v42 + 1);
          ++v6;
        }
        while ( v6 < (*(_DWORD *)(v36 + 16) & 0x7FFFFFFFu) );
      }
      this->mPlayingTree.m_pPointer->vfptr[2].FindWithOldPath(
        this->mPlayingTree.m_pPointer,
        (const char *)BYTE2(this->m_Track[1].mMasterRate.expression.mOffset));
    }
    else
    {
      v44 = this->m_Track;
      v45 = context->mActionController->m_currentNode;
      ActionNode::GetNameFullPath(v45, &pathToPopulate);
      ActionPath::GetString_DBG(&pathToPopulate);
      v44->vfptr->GetClassname(v44);
      v46 = ((__int64 (__fastcall *)(ActionNodePlayable *))v45->vfptr[3].GetClassNameUID)(v45);
      v47 = v46;
      v48 = *(_DWORD *)(v46 + 16) & 0x7FFFFFFF;
      v49 = 0;
      if ( v48 )
      {
        v50 = *(_QWORD *)(v46 + 24);
        v51 = 0i64;
        do
        {
          if ( v50 )
            v52 = v50 + v47 + 24;
          else
            v52 = 0i64;
          v53 = v51 + v52;
          v54 = *(_QWORD *)(v51 + v52);
          if ( v54 )
            v55 = (ITrack *)(v53 + v54);
          else
            v55 = 0i64;
          if ( v44 == v55 )
            break;
          ++v49;
          v51 += 8i64;
        }
        while ( v49 < v48 );
      }
      v56 = pathToPopulate.mPath.mCount;
      if ( pathToPopulate.mPath.mCount >= 0 )
      {
        if ( pathToPopulate.mPath.mData.mOffset
          && (UFG::qOffset64<ActionID *> *)((char *)&pathToPopulate.mPath.mData + pathToPopulate.mPath.mData.mOffset) )
        {
          operator delete[]((char *)&pathToPopulate.mPath.mData + pathToPopulate.mPath.mData.mOffset);
          v56 = pathToPopulate.mPath.mCount;
        }
        pathToPopulate.mPath.mData.mOffset = 0i64;
        pathToPopulate.mPath.mCount = v56 & 0x80000000;
      }
    }
    ((void (__fastcall *)(BlendTreeTask *))this->vfptr->Update)(this);
  }
}

// File Line: 785
// RVA: 0x3134B0
bool __fastcall BlendTreeTask::Update(BlendTreeTask *this, float timeDelta)
{
  ActionContext *mContext; // rcx
  UFG::SimObject *m_pPointer; // rax
  PoseNode *v6; // rsi
  Expression::IMemberMapVtbl *vfptr; // rbx
  PoseNode **p_m_pPointer; // rsi
  PoseNode **p_mNext; // rbx
  bool v10; // al
  UFG::SimObjectCVBase *v11; // rcx
  __int16 m_Flags; // dx
  UFG::CharacterAnimationComponent *v13; // rax
  PoseNode *v14; // rcx
  int v15; // ebx

  mContext = this->mContext;
  if ( mContext )
  {
    m_pPointer = mContext->mSimObject.m_pPointer;
    if ( m_pPointer )
    {
      if ( (m_pPointer->m_Flags & 0x400) != 0 )
        return 1;
    }
  }
  v6 = this->mPlayingTree.m_pPointer;
  if ( v6 )
  {
    vfptr = v6->Expression::IMemberMap::vfptr;
    ActionContext::GetRunningMasterRate(mContext);
    vfptr[3].ResolveReferences(v6);
  }
  p_m_pPointer = &this->mSplitBodyBlend.m_pPointer;
  p_mNext = (PoseNode **)&this->mActiveControllers.mNode.mNext[-1].mNext;
  v10 = p_mNext == &this->mSplitBodyBlend.m_pPointer;
  if ( this->mActiveControllers.mNode.mNext != (UFG::qNode<IBlendTreeControllerTask,IBlendTreeControllerTask> *)8 )
  {
    do
    {
      if ( v10 )
        break;
      ((void (__fastcall *)(PoseNode **))(*p_mNext)->m_SafePointerList.mNode.UFG::qSafePointerNode<PoseNode>::mPrev)(p_mNext);
      p_mNext = (PoseNode **)&p_mNext[2][-1].mDebugPoseColour.b;
      v10 = p_mNext == p_m_pPointer;
    }
    while ( p_mNext );
  }
  v11 = (UFG::SimObjectCVBase *)this->mContext->mSimObject.m_pPointer;
  if ( !v11 )
    return 0;
  m_Flags = v11->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
  {
    v13 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v11);
  }
  else if ( (m_Flags & 0x2000) != 0 )
  {
    v13 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v11);
  }
  else
  {
    v13 = (UFG::CharacterAnimationComponent *)((m_Flags & 0x1000) != 0
                                             ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 v11,
                                                 UFG::CharacterAnimationComponent::_TypeUID)
                                             : UFG::SimObject::GetComponentOfType(
                                                 v11,
                                                 UFG::CharacterAnimationComponent::_TypeUID));
  }
  if ( !v13 )
    return 0;
  v14 = this->mPlayingTree.m_pPointer;
  if ( !v14 )
    return *p_m_pPointer != 0i64;
  v15 = BYTE2(this->m_Track[1].mMasterRate.expression.mOffset);
  if ( v15 == 1
    || v15 == 6
    || !((unsigned __int8 (__fastcall *)(PoseNode *))v14->Expression::IMemberMap::vfptr[1].SetResourceOwner)(v14) )
  {
    return 1;
  }
  this->mPlayingTree.m_pPointer->vfptr[1].GetResourceOwner(this->mPlayingTree.m_pPointer);
  return v15 == 2;
}

// File Line: 852
// RVA: 0x312390
void __fastcall BlendTreeTask::End(BlendTreeTask *this)
{
  PoseNode **p_m_pPointer; // rsi
  UFG::qNode<IBlendTreeControllerTask,IBlendTreeControllerTask> *mNext; // rbx
  UFG::qNode<IBlendTreeControllerTask,IBlendTreeControllerTask> *mPrev; // rdx
  UFG::qNode<IBlendTreeControllerTask,IBlendTreeControllerTask> *v5; // rax
  PoseNode *m_pPointer; // rcx
  int v7; // edx
  float v8; // xmm6_4
  float RunningMasterRate; // xmm0_4
  PoseNode *v10; // rax
  float v11; // xmm6_4

  p_m_pPointer = &this->mSplitBodyBlend.m_pPointer;
  while ( (PoseNode **)&this->mActiveControllers.mNode.mNext[-1].mNext != p_m_pPointer )
  {
    mNext = this->mActiveControllers.mNode.mNext;
    ((void (__fastcall *)(UFG::qNode<IBlendTreeControllerTask,IBlendTreeControllerTask> **))mNext[-1].mNext[2].mPrev)(&mNext[-1].mNext);
    mPrev = mNext->mPrev;
    v5 = mNext->mNext;
    mPrev->mNext = v5;
    v5->mPrev = mPrev;
    mNext->mPrev = mNext;
    mNext->mNext = mNext;
    ((void (__fastcall *)(UFG::qNode<IBlendTreeControllerTask,IBlendTreeControllerTask> **, __int64))mNext[-1].mNext->mPrev)(
      &mNext[-1].mNext,
      1i64);
  }
  m_pPointer = this->mPlayingTree.m_pPointer;
  if ( m_pPointer )
  {
    v7 = BYTE2(this->m_Track[1].mMasterRate.expression.mOffset);
    if ( v7 != 1 && v7 != 6 )
      ((void (__fastcall *)(PoseNode *))m_pPointer->Expression::IMemberMap::vfptr[2].__vecDelDtor)(m_pPointer);
  }
  if ( this->mSplitBodyBlend.m_pPointer )
  {
    v8 = *(float *)&this->m_Track[1].mBreakPoint;
    RunningMasterRate = ActionContext::GetRunningMasterRate(this->mContext);
    v10 = this->mSplitBodyBlend.m_pPointer;
    v11 = v8 / RunningMasterRate;
    if ( v11 == 0.0 )
    {
      HIDWORD(v10[1].mParent.mOffset) = -1082130432;
      v10[1].mPriority = 0;
      BYTE3(v10[1].mParent.mOffset) = 0;
    }
    else if ( v11 > 0.0 )
    {
      BYTE3(v10[1].mParent.mOffset) = 0;
      *((float *)&v10[1].mParent.mOffset + 1) = -1.0 / v11;
    }
  }
}

// File Line: 889
// RVA: 0x30F5C0
void __fastcall BlendTreeControllerTask::BlendTreeControllerTask(BlendTreeControllerTask *this)
{
  UFG::qSafePointer<PoseNode,PoseNode> *p_mPlayingTree; // rdx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *mNext; // rax

  this->mPrev = &this->UFG::qNode<IBlendTreeControllerTask,IBlendTreeControllerTask>;
  this->mNext = &this->UFG::qNode<IBlendTreeControllerTask,IBlendTreeControllerTask>;
  this->vfptr = (IBlendTreeControllerTaskVtbl *)&IBlendTreeControllerTask::`vftable;
  this->vfptr = (IBlendTreeControllerTaskVtbl *)&BlendTreeControllerBaseTask<BlendTreeControllerTrack>::`vftable;
  p_mPlayingTree = &this->mPlayingTree;
  this->mPlayingTree.BlendTreeControllerBaseTask<BlendTreeControllerTrack>::mPrev = &this->mPlayingTree;
  this->mPlayingTree.mNext = &this->mPlayingTree;
  this->mPlayingTree.m_pPointer = 0i64;
  this->vfptr = (IBlendTreeControllerTaskVtbl *)&BlendTreeControllerTask::`vftable;
  if ( this->mPlayingTree.m_pPointer )
  {
    mPrev = p_mPlayingTree->mPrev;
    mNext = p_mPlayingTree->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mPlayingTree->mPrev = p_mPlayingTree;
    p_mPlayingTree->mNext = p_mPlayingTree;
  }
  p_mPlayingTree->m_pPointer = 0i64;
}

// File Line: 894
// RVA: 0x311150
void __fastcall BlendTreeControllerTask::Begin(BlendTreeControllerTask *this, ActionContext *context)
{
  bool v2; // si
  UFG::SimObject *m_pPointer; // rax
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rdi
  float x; // eax
  float z; // xmm2_4
  float y; // xmm1_4
  ActionContext *mContext; // rax
  float v10; // xmm0_4
  UFG::SimObjectCVBase *v11; // rcx
  IBlendTreeControllerTrack *m_Track; // rax
  unsigned __int64 v13; // rdi
  __int64 v14; // rcx
  UFG::SimObjectCVBase *v15; // rcx
  __int16 m_Flags; // dx
  UFG::CharacterAnimationComponent *ComponentOfTypeHK; // rax
  Creature *mCreature; // rcx
  float v19; // xmm2_4
  float v20; // xmm0_4
  UFG::qVector3 v21; // [rsp+30h] [rbp-58h] BYREF
  UFG::qMatrix44 transform; // [rsp+40h] [rbp-48h] BYREF

  v2 = 0;
  this->mContext = context;
  m_pPointer = context->mSimObject.m_pPointer;
  m_pTransformNodeComponent = 0i64;
  if ( m_pPointer )
    m_pTransformNodeComponent = m_pPointer->m_pTransformNodeComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  x = m_pTransformNodeComponent->mWorldTransform.v0.x;
  z = m_pTransformNodeComponent->mWorldTransform.v0.z;
  y = m_pTransformNodeComponent->mWorldTransform.v0.y;
  this->mStartFacingVector.z = z;
  this->mStartFacingVector.y = y;
  v21.z = z;
  this->mStartFacingVector.x = x;
  mContext = this->mContext;
  v10 = this->mStartFacingVector.x;
  v21.y = y;
  v11 = (UFG::SimObjectCVBase *)mContext->mSimObject.m_pPointer;
  m_Track = this->m_Track;
  v21.x = v10;
  v13 = BYTE4(m_Track[1].mResourceOwner);
  this->mSignalValue = getSignalValue(
                         v11,
                         (FloatInputSignal)BYTE4(m_Track[1].mResourceOwner),
                         0.0,
                         *(float *)&m_Track[1].mResourceOwner,
                         &v21);
  this->mHoldFirstSignal = (_DWORD)v13 == 2 || (_DWORD)v13 == 39;
  if ( (unsigned int)v13 <= 0x27 )
  {
    v14 = 0x80000088F4i64;
    if ( _bittest64(&v14, v13) )
      v2 = 1;
  }
  this->mForceInput = v2;
  if ( (_DWORD)v13 == 11 )
  {
    v15 = (UFG::SimObjectCVBase *)this->mContext->mSimObject.m_pPointer;
    if ( v15 )
    {
      m_Flags = v15->m_Flags;
      if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
      {
        ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v15);
      }
      else if ( (m_Flags & 0x2000) != 0 )
      {
        ComponentOfTypeHK = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v15);
      }
      else if ( (m_Flags & 0x1000) != 0 )
      {
        ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                  v15,
                                                                  UFG::CharacterAnimationComponent::_TypeUID);
      }
      else
      {
        ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                                  v15,
                                                                  UFG::CharacterAnimationComponent::_TypeUID);
      }
      if ( ComponentOfTypeHK )
      {
        mCreature = ComponentOfTypeHK->mCreature;
        if ( mCreature )
        {
          Creature::GetTransform(mCreature, 3, &transform);
          v19 = transform.v0.y;
          this->mStartFacingVector.x = transform.v0.x;
          v20 = transform.v0.z;
          this->mStartFacingVector.y = v19;
          this->mStartFacingVector.z = v20;
        }
      }
    }
  }
  ((void (__fastcall *)(BlendTreeControllerTask *))this->vfptr->Update)(this);
  if ( (_DWORD)v13 == 4 )
    this->mForceInput = 0;
}

// File Line: 975
// RVA: 0x313390
char __fastcall BlendTreeControllerTask::Update(BlendTreeControllerTask *this, float timeDelta)
{
  bool v4; // zf
  IBlendTreeControllerTrack *m_Track; // rcx
  FloatInputSignal v6; // edi
  ActionContext *mContext; // rax
  float y; // xmm1_4
  float z; // xmm0_4
  float mSignalValue; // xmm2_4
  IBlendTreeControllerTrack *v11; // rcx
  ActionContext *v12; // rax
  float v13; // xmm1_4
  float v14; // xmm0_4
  UFG::qVector3 v16; // [rsp+30h] [rbp-28h] BYREF

  if ( this->mPlayingTree.m_pPointer )
  {
    v4 = !this->mHoldFirstSignal;
    m_Track = this->m_Track;
    v6 = BYTE4(m_Track[1].mResourceOwner);
    if ( v4 )
    {
      mContext = this->mContext;
      y = this->mStartFacingVector.y;
      v16.x = this->mStartFacingVector.x;
      z = this->mStartFacingVector.z;
      v16.y = y;
      v16.z = z;
      this->mSignalValue = getSignalValue(
                             (UFG::SimObjectCVBase *)mContext->mSimObject.m_pPointer,
                             v6,
                             timeDelta,
                             *(float *)&m_Track[1].mResourceOwner,
                             &v16);
    }
    mSignalValue = this->mSignalValue;
    if ( v6 == FIS_AIM_INTENTION_DIRECTION_XY_RELATIVE_TO_START )
    {
      v11 = this->m_Track;
      if ( BYTE4(v11[1].vfptr) == 4 )
      {
        v12 = this->mContext;
        v13 = this->mStartFacingVector.y;
        v16.x = this->mStartFacingVector.x;
        v14 = this->mStartFacingVector.z;
        v16.y = v13;
        v16.z = v14;
        mSignalValue = (float)((float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(
                                                      this->mSignalValue
                                                    - getSignalValue(
                                                        (UFG::SimObjectCVBase *)v12->mSimObject.m_pPointer,
                                                        FIS_AIM_INTENTION_DIRECTION_XY_RELATIVE_TO_START,
                                                        timeDelta,
                                                        *(float *)&v11[1].mResourceOwner,
                                                        &v16)) & _xmm)
                                     * 0.31830987)
                             * sRateGain_0)
                     + 1.0;
      }
    }
    BlendTreeControllerTrackBase<BlendTreeControllerTask>::ApplySignal(
      (BlendTreeControllerTrackBase<BlendTreeControllerTask> *)this->m_Track,
      this->mPlayingTree.m_pPointer,
      mSignalValue,
      this->mForceInput);
  }
  return 1;
}

// File Line: 1038
// RVA: 0x30F540
void __fastcall BlendTreeControllerTargetPositionTask::BlendTreeControllerTargetPositionTask(
        BlendTreeControllerTargetPositionTask *this)
{
  UFG::qSafePointer<PoseNode,PoseNode> *p_mPlayingTree; // rdx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *mNext; // rax

  this->mPrev = &this->UFG::qNode<IBlendTreeControllerTask,IBlendTreeControllerTask>;
  this->mNext = &this->UFG::qNode<IBlendTreeControllerTask,IBlendTreeControllerTask>;
  this->vfptr = (IBlendTreeControllerTaskVtbl *)&IBlendTreeControllerTask::`vftable;
  this->vfptr = (IBlendTreeControllerTaskVtbl *)&BlendTreeControllerBaseTask<BlendTreeControllerTargetPositionTrack>::`vftable;
  p_mPlayingTree = &this->mPlayingTree;
  this->mPlayingTree.BlendTreeControllerBaseTask<BlendTreeControllerTargetPositionTrack>::mPrev = &this->mPlayingTree;
  this->mPlayingTree.mNext = &this->mPlayingTree;
  this->mPlayingTree.m_pPointer = 0i64;
  this->vfptr = (IBlendTreeControllerTaskVtbl *)&BlendTreeControllerTargetPositionTask::`vftable;
  if ( this->mPlayingTree.m_pPointer )
  {
    mPrev = p_mPlayingTree->mPrev;
    mNext = p_mPlayingTree->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mPlayingTree->mPrev = p_mPlayingTree;
    p_mPlayingTree->mNext = p_mPlayingTree;
  }
  p_mPlayingTree->m_pPointer = 0i64;
}

// File Line: 1043
// RVA: 0x3110F0
void __fastcall BlendTreeControllerTargetPositionTask::Begin(
        BlendTreeControllerTargetPositionTask *this,
        ActionContext *context)
{
  UFG::SimObject *m_pPointer; // rbx
  float v4; // xmm1_4
  float v5; // xmm0_4
  IBlendTreeControllerTaskVtbl *vfptr; // rax

  this->mContext = context;
  m_pPointer = context->mSimObject.m_pPointer;
  if ( m_pPointer )
    m_pPointer = (UFG::SimObject *)m_pPointer->m_pTransformNodeComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)m_pPointer);
  v4 = *(float *)&m_pPointer[1].m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
  v5 = *((float *)&m_pPointer[1].vfptr + 1);
  this->mStartFacingVector.x = *(float *)&m_pPointer[1].vfptr;
  vfptr = this->vfptr;
  this->mStartFacingVector.z = v4;
  this->mStartFacingVector.y = v5;
  ((void (__fastcall *)(BlendTreeControllerTargetPositionTask *))vfptr->Update)(this);
}

// File Line: 1062
// RVA: 0x313190
char __fastcall BlendTreeControllerTargetPositionTask::Update(
        BlendTreeControllerTargetPositionTask *this,
        float timeDelta)
{
  ActionContext *mContext; // rax
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *ComponentOfTypeHK; // rax
  __int64 v8; // rsi
  __int64 v9; // rsi
  UFG::SimObject *v10; // rcx
  float *m_pTransformNodeComponent; // rdi
  float v12; // xmm2_4
  float v13; // xmm4_4
  __m128 v14; // xmm5
  float v15; // xmm6_4
  __m128 v16; // xmm3
  float y; // xmm1_4
  UFG::qVector3 currentFacing; // [rsp+20h] [rbp-38h] BYREF
  UFG::qVector3 desiredDirection; // [rsp+30h] [rbp-28h] BYREF

  if ( this->mPlayingTree.m_pPointer )
  {
    mContext = this->mContext;
    this->mSignalValue = 0.0;
    m_pPointer = (UFG::SimObjectGame *)mContext->mSimObject.m_pPointer;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                m_pPointer,
                                UFG::TargetingSystemBaseComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                m_pPointer,
                                UFG::TargetingSystemBaseComponent::_TypeUID);
        m_pComponent = ComponentOfTypeHK;
      }
      else
      {
        m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
      }
      if ( m_pComponent )
      {
        v8 = *(_QWORD *)(56i64
                       * *(unsigned __int8 *)(LODWORD(this->m_Track[1].mResourceOwner)
                                            + *(_QWORD *)&m_pComponent[1].m_Flags
                                            + 8i64)
                       + *(_QWORD *)&m_pComponent[1].m_TypeUID
                       + 40);
        if ( v8 )
        {
          v9 = *(_QWORD *)(v8 + 88);
          if ( v9 )
          {
            v10 = this->mContext->mSimObject.m_pPointer;
            if ( v10 )
            {
              m_pTransformNodeComponent = (float *)v10->m_pTransformNodeComponent;
              if ( m_pTransformNodeComponent )
              {
                UFG::TransformNodeComponent::UpdateWorldTransform(v10->m_pTransformNodeComponent);
                UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v9);
                v14 = (__m128)*(unsigned int *)(v9 + 180);
                v12 = 0.0;
                v13 = *(float *)(v9 + 176) - m_pTransformNodeComponent[44];
                v14.m128_f32[0] = v14.m128_f32[0] - m_pTransformNodeComponent[45];
                v15 = *(float *)(v9 + 184) - m_pTransformNodeComponent[46];
                v16 = v14;
                v16.m128_f32[0] = (float)((float)(v14.m128_f32[0] * v14.m128_f32[0]) + (float)(v13 * v13))
                                + (float)(v15 * v15);
                if ( v16.m128_f32[0] != 0.0 )
                  v12 = 1.0 / _mm_sqrt_ps(v16).m128_f32[0];
                y = this->mStartFacingVector.y;
                currentFacing.x = this->mStartFacingVector.x;
                currentFacing.z = this->mStartFacingVector.z;
                desiredDirection.x = v13 * v12;
                desiredDirection.y = v14.m128_f32[0] * v12;
                desiredDirection.z = v15 * v12;
                currentFacing.y = y;
                this->mSignalValue = getSignalFromDirection(&desiredDirection, &currentFacing, 6.2831855);
              }
            }
          }
        }
      }
    }
    BlendTreeControllerTrackBase<BlendTreeControllerTask>::ApplySignal(
      (BlendTreeControllerTrackBase<BlendTreeControllerTask> *)this->m_Track,
      this->mPlayingTree.m_pPointer,
      this->mSignalValue,
      0i64);
  }
  return 1;
}k,
      this->mPlayingTree.m_pPointer,
      this->mSignalValue,
   

// File Line: 1116
// RVA: 0x30F4C0
void __fastcall BlendTreeControllerTargetDistancTask::BlendTreeControllerTargetDistancTask(
        BlendTreeControllerTargetDistancTask *this)
{
  UFG::qSafePointer<PoseNode,PoseNode> *p_mPlayingTree; // rdx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *mNext; // rax

  this->mPrev = &this->UFG::qNode<IBlendTreeControllerTask,IBlendTreeControllerTask>;
  this->mNext = &this->UFG::qNode<IBlendTreeControllerTask,IBlendTreeControllerTask>;
  this->vfptr = (IBlendTreeControllerTaskVtbl *)&IBlendTreeControllerTask::`vftable;
  this->vfptr = (IBlendTreeControllerTaskVtbl *)&BlendTreeControllerBaseTask<BlendTreeControllerTargetDistancTrack>::`vftable;
  p_mPlayingTree = &this->mPlayingTree;
  this->mPlayingTree.BlendTreeControllerBaseTask<BlendTreeControllerTargetDistancTrack>::mPrev = &this->mPlayingTree;
  this->mPlayingTree.mNext = &this->mPlayingTree;
  this->mPlayingTree.m_pPointer = 0i64;
  this->vfptr = (IBlendTreeControllerTaskVtbl *)&BlendTreeControllerTargetDistancTask::`vftable;
  if ( this->mPlayingTree.m_pPointer )
  {
    mPrev = p_mPlayingTree->mPrev;
    mNext = p_mPlayingTree->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mPlayingTree->mPrev = p_mPlayingTree;
    p_mPlayingTree->mNext = p_mPlayingTree;
  }
  p_mPlayingTree->m_pPointer = 0i64;
}

// File Line: 1121
// RVA: 0x3110E0
void __fastcall BlendTreeControllerTargetDistancTask::Begin(
        BlendTreeControllerTargetDistancTask *this,
        ActionContext *context)
{
  IBlendTreeControllerTaskVtbl *vfptr; // rax

  vfptr = this->vfptr;
  this->mContext = context;
  ((void (*)(void))vfptr->Update)();
}

// File Line: 1138
// RVA: 0x312FD0
char __fastcall BlendTreeControllerTargetDistancTask::Update(
        BlendTreeControllerTargetDistancTask *this,
        float timeDelta)
{
  ActionContext *mContext; // rax
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *ComponentOfTypeHK; // rax
  __int64 v8; // rsi
  __int64 v9; // rsi
  UFG::SimObject *v10; // rcx
  float *m_pTransformNodeComponent; // rdi
  IBlendTreeControllerTrack *m_Track; // rax
  __m128 v13; // xmm2
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm3_4
  float v17; // xmm0_4
  float v18; // xmm1_4

  if ( this->mPlayingTree.m_pPointer )
  {
    mContext = this->mContext;
    this->mSignalValue = 0.0;
    m_pPointer = (UFG::SimObjectGame *)mContext->mSimObject.m_pPointer;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                m_pPointer,
                                UFG::TargetingSystemBaseComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                m_pPointer,
                                UFG::TargetingSystemBaseComponent::_TypeUID);
        m_pComponent = ComponentOfTypeHK;
      }
      else
      {
        m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
      }
      if ( m_pComponent )
      {
        v8 = *(_QWORD *)(56i64
                       * *(unsigned __int8 *)(LODWORD(this->m_Track[1].mResourceOwner)
                                            + *(_QWORD *)&m_pComponent[1].m_Flags
                                            + 8i64)
                       + *(_QWORD *)&m_pComponent[1].m_TypeUID
                       + 40);
        if ( v8 )
        {
          v9 = *(_QWORD *)(v8 + 88);
          if ( v9 )
          {
            v10 = this->mContext->mSimObject.m_pPointer;
            if ( v10 )
            {
              m_pTransformNodeComponent = (float *)v10->m_pTransformNodeComponent;
              if ( m_pTransformNodeComponent )
              {
                UFG::TransformNodeComponent::UpdateWorldTransform(v10->m_pTransformNodeComponent);
                UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v9);
                m_Track = this->m_Track;
                v13 = (__m128)*(unsigned int *)(v9 + 180);
                v14 = *(float *)(v9 + 176) - m_pTransformNodeComponent[44];
                v15 = *(float *)(v9 + 184) - m_pTransformNodeComponent[46];
                v16 = *((float *)&m_Track[1].mResourceOwner + 1);
                v13.m128_f32[0] = (float)((float)((float)(v13.m128_f32[0] - m_pTransformNodeComponent[45])
                                                * (float)(v13.m128_f32[0] - m_pTransformNodeComponent[45]))
                                        + (float)(v14 * v14))
                                + (float)(v15 * v15);
                v17 = *(float *)&m_Track[2].vfptr;
                v18 = _mm_sqrt_ps(v13).m128_f32[0];
                if ( v18 < v17 )
                {
                  if ( v18 > v16 )
                    this->mSignalValue = (float)(v18 - v16) / (float)(v17 - v16);
                  else
                    this->mSignalValue = 0.0;
                }
                else
                {
                  this->mSignalValue = 1.0;
                }
              }
            }
          }
        }
      }
    }
    BlendTreeControllerTrackBase<BlendTreeControllerTask>::ApplySignal(
      (BlendTreeControllerTrackBase<BlendTreeControllerTask> *)this->m_Track,
      this->mPlayingTree.m_pPointer,
      this->mSignalValue,
      0i64);
  }
  return 1;
}

// File Line: 1209
// RVA: 0x3118C0
void __fastcall PoseDriverDisableTask::Begin(PoseDriverDisableTask *this, ActionContext *context)
{
  UFG::SimObject *m_pPointer; // rcx
  UFG::SimComponent *ComponentOfType; // rax

  this->mContext = context;
  if ( context )
  {
    m_pPointer = context->mSimObject.m_pPointer;
    if ( m_pPointer )
    {
      ComponentOfType = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::CharacterAnimationComponent::_TypeUID);
      if ( ComponentOfType )
        ComponentOfType = *(UFG::SimComponent **)&ComponentOfType[2].m_TypeUID;
      if ( ComponentOfType )
        BYTE4(ComponentOfType[14].m_SafePointerList.mNode.mNext) = 1;
    }
  }
}

// File Line: 1223
// RVA: 0x3124B0
void __fastcall PoseDriverDisableTask::End(PoseDriverDisableTask *this)
{
  ActionContext *mContext; // rax
  UFG::SimObject *m_pPointer; // rcx
  UFG::SimComponent *ComponentOfType; // rax

  mContext = this->mContext;
  if ( mContext )
  {
    m_pPointer = mContext->mSimObject.m_pPointer;
    if ( m_pPointer )
    {
      ComponentOfType = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::CharacterAnimationComponent::_TypeUID);
      if ( ComponentOfType )
        ComponentOfType = *(UFG::SimComponent **)&ComponentOfType[2].m_TypeUID;
      if ( ComponentOfType )
        BYTE4(ComponentOfType[14].m_SafePointerList.mNode.mNext) = 0;
    }
  }
}

