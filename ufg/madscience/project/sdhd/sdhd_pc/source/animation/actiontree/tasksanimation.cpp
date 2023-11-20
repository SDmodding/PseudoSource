// File Line: 53
// RVA: 0x310830
void __fastcall AnimationBankReferenceTask::Begin(AnimationBankReferenceTask *this, ActionContext *pActionContext)
{
  ITrack *v2; // rax
  ActionContext *v3; // rsi
  AnimationBankReferenceTask *v4; // rdi
  UFG::eAnimationPriorityEnum v5; // ebp
  signed __int64 v6; // r8
  unsigned __int64 v7; // rax
  const char *v8; // rdx
  UFG::qSymbolUC *v9; // rax
  UFG::SimObjectGame *v10; // rcx
  unsigned __int16 v11; // dx
  UFG::PowerManagementComponent *v12; // rax
  UFG::qSymbolUC result; // [rsp+30h] [rbp+8h]

  v2 = this->m_Track;
  v3 = pActionContext;
  v4 = this;
  v5 = LOBYTE(v2[1].mResourceOwner);
  v6 = (signed __int64)&v2[1];
  v7 = (_QWORD)v2[1].vfptr & 0xFFFFFFFFFFFFFFFEui64;
  v8 = (const char *)(v7 + v6);
  if ( !v7 )
    v8 = BinString::sEmptyString;
  v9 = UFG::qSymbolUC::create_from_string(&result, v8);
  AnimationGroupHandle::Init(&v4->mAnimationGroupHandle, v9, v5);
  AnimationGroupHandle::Bind(&v4->mAnimationGroupHandle);
  v10 = (UFG::SimObjectGame *)v3->mSimObject.m_pPointer;
  if ( v10 )
  {
    v11 = v10->m_Flags;
    if ( (v11 >> 14) & 1 )
    {
      v12 = (UFG::PowerManagementComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               v10,
                                               UFG::PowerManagementComponent::_TypeUID);
    }
    else if ( (v11 & 0x8000u) == 0 )
    {
      if ( (v11 >> 13) & 1 )
      {
        v12 = (UFG::PowerManagementComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 v10,
                                                 UFG::PowerManagementComponent::_TypeUID);
      }
      else if ( (v11 >> 12) & 1 )
      {
        v12 = (UFG::PowerManagementComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 v10,
                                                 UFG::PowerManagementComponent::_TypeUID);
      }
      else
      {
        v12 = (UFG::PowerManagementComponent *)UFG::SimObject::GetComponentOfType(
                                                 (UFG::SimObject *)&v10->vfptr,
                                                 UFG::PowerManagementComponent::_TypeUID);
      }
    }
    else
    {
      v12 = (UFG::PowerManagementComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               v10,
                                               UFG::PowerManagementComponent::_TypeUID);
    }
    if ( v12 )
      UFG::PowerManagementComponent::AddPowerManagedResource(v12, (UFG::PowerManagedResource *)&v4->vfptr);
  }
}

// File Line: 77
// RVA: 0x312070
void __fastcall AnimationBankReferenceTask::End(AnimationBankReferenceTask *this)
{
  AnimationBankReferenceTask *v1; // rbx
  UFG::qNode<UFG::PowerManagedResource,UFG::PowerManagedResourceList> *v2; // rcx
  UFG::qNode<UFG::PowerManagedResource,UFG::PowerManagedResourceList> *v3; // rax

  v1 = this;
  AnimationGroupHandle::Unbind(&this->mAnimationGroupHandle);
  v2 = v1->mPrev;
  v3 = v1->mNext;
  v1 = (AnimationBankReferenceTask *)((char *)v1 + 48);
  v2->mNext = v3;
  v3->mPrev = v2;
  v1->vfptr = (ITaskVtbl *)v1;
  v1->mPrev = (UFG::qNode<ITask,ITask> *)v1;
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
  AnimationGroup *v1; // rcx

  v1 = (AnimationGroup *)this->mAnimationGroupHandle.mPrev;
  return v1 && AnimationGroup::IsStreamedIn(v1);
}

// File Line: 126
// RVA: 0x310780
void __fastcall AnimationBankPriorityTask::Begin(AnimationBankPriorityTask *this, ActionContext *pActionContext)
{
  ITrack *v2; // rax
  UFG::SimObjectGame *v3; // rcx
  UFG::eAnimationPriorityEnum v4; // edi
  UFG::qSymbolUC *v5; // rbx
  unsigned __int16 v6; // dx
  UFG::BaseAnimationComponent *v7; // rax

  v2 = this->m_Track;
  v3 = (UFG::SimObjectGame *)pActionContext->mSimObject.m_pPointer;
  v4 = BYTE4(v2[1].vfptr);
  v5 = (UFG::qSymbolUC *)&v2[1];
  if ( v3 )
  {
    v6 = v3->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v7 = (UFG::BaseAnimationComponent *)v3->m_Components.p[9].m_pComponent;
    }
    else if ( (v6 & 0x8000u) == 0 )
    {
      if ( (v6 >> 13) & 1 )
      {
        v7 = (UFG::BaseAnimationComponent *)v3->m_Components.p[8].m_pComponent;
      }
      else if ( (v6 >> 12) & 1 )
      {
        v7 = (UFG::BaseAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              v3,
                                              UFG::BaseAnimationComponent::_TypeUID);
      }
      else
      {
        v7 = (UFG::BaseAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                              (UFG::SimObject *)&v3->vfptr,
                                              UFG::BaseAnimationComponent::_TypeUID);
      }
    }
    else
    {
      v7 = (UFG::BaseAnimationComponent *)v3->m_Components.p[9].m_pComponent;
    }
    if ( v7 )
      UFG::BaseAnimationComponent::SetAnimationBankPriority(v7, v5, v4);
  }
}

// File Line: 145
// RVA: 0x30F220
void __fastcall AnimationTask::AnimationTask(AnimationTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax
  UFG::qSafePointer<AnimationNode,AnimationNode> *v2; // [rsp+28h] [rbp+10h]
  UFG::qSafePointer<PoseNode,PoseNode> *v3; // [rsp+28h] [rbp+10h]

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable';
  this->vfptr = (ITaskVtbl *)&Task<AnimationTrack>::`vftable';
  this->vfptr = (ITaskVtbl *)&AnimationTask::`vftable';
  v2 = &this->mController;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  this->mController.m_pPointer = 0i64;
  v3 = &this->mSplitBodyBlend;
  v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  v3->mNext = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  this->mSplitBodyBlend.m_pPointer = 0i64;
  this->mFinished = 1;
}

// File Line: 159
// RVA: 0x310B30
void __fastcall AnimationTask::Begin(AnimationTask *this, ActionContext *context)
{
  ActionContext *v2; // rsi
  AnimationTask *v3; // rdi
  UFG::SimObject *v4; // rbx
  UFG::TransformNodeComponent *v5; // rbx
  float v6; // xmm3_4
  __int128 v7; // xmm4
  float v8; // xmm5_4
  __m128 v9; // xmm2
  float v10; // xmm2_4
  UFG::qSymbolUC *v11; // r12
  UFG::SimObjectCVBase *v12; // rcx
  unsigned __int16 v13; // dx
  UFG::CharacterAnimationComponent *v14; // rax
  Creature *v15; // r14
  float v16; // xmm6_4
  float v17; // xmm6_4
  ITrack *v18; // rdx
  char *v19; // rax
  BlendNode *v20; // rax
  BlendNode *v21; // r15
  PoseNode *v22; // rbx
  AnimationPlayMode v23; // ebx
  char *v24; // rax
  AnimationNode *v25; // rax
  ITrack *v26; // rax
  int v27; // er9
  PoseNodeParent *v28; // r8
  Weightset *v29; // rax
  UFG::qNode<PoseNode,PoseNode> *v30; // rbx
  ITrack *v31; // rcx
  AnimationPlayMode v32; // er8
  bool v33; // al
  float v34; // xmm1_4
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
  Expression::IMemberMapVtbl *v47; // rbx
  __int128 v48; // xmm1
  ITrack *v49; // rbx
  ActionNode *v50; // rdi
  const char *v51; // rdx
  ActionPath pathToPopulate; // [rsp+10h] [rbp-31h]
  unsigned int check_null; // [rsp+20h] [rbp-21h]
  float blendInTime; // [rsp+28h] [rbp-19h]
  float phaseIn[2]; // [rsp+30h] [rbp-11h]
  int *returnCode; // [rsp+38h] [rbp-9h]
  int v57; // [rsp+A8h] [rbp+67h]
  char *v58; // [rsp+B0h] [rbp+6Fh]

  v2 = context;
  v3 = this;
  this->mContext = context;
  if ( context && context->mSimObject.m_pPointer && (context->mSimObject.m_pPointer->m_Flags >> 10) & 1 )
    return;
  v4 = context->mSimObject.m_pPointer;
  v5 = v4 ? v4->m_pTransformNodeComponent : 0i64;
  UFG::TransformNodeComponent::UpdateWorldTransform(v5);
  v6 = v5->mWorldTransform.v0.x;
  v7 = LODWORD(v5->mWorldTransform.v0.y);
  v8 = v5->mWorldTransform.v0.z;
  v3->mStartFacingVector.x = v6;
  LODWORD(v3->mStartFacingVector.y) = v7;
  v3->mStartFacingVector.z = v8;
  v9 = (__m128)v7;
  v9.m128_f32[0] = (float)((float)(*(float *)&v7 * *(float *)&v7) + (float)(v6 * v6)) + (float)(v8 * v8);
  v10 = v9.m128_f32[0] == 0.0 ? 0.0 : 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v9));
  v3->mStartFacingVector.x = v10 * v6;
  v3->mStartFacingVector.y = v10 * *(float *)&v7;
  v3->mStartFacingVector.z = v10 * v8;
  v11 = (UFG::qSymbolUC *)((char *)&v3->m_Track[1].mMasterRate.expression.mOffset + 4);
  v12 = (UFG::SimObjectCVBase *)v3->mContext->mSimObject.m_pPointer;
  if ( !v12 )
    return;
  v13 = v12->m_Flags;
  if ( (v13 >> 14) & 1 )
  {
    v14 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v12);
  }
  else if ( (v13 & 0x8000u) == 0 )
  {
    if ( (v13 >> 13) & 1 )
      v14 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v12);
    else
      v14 = (UFG::CharacterAnimationComponent *)((v13 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                     (UFG::SimObjectGame *)&v12->vfptr,
                                                                     UFG::CharacterAnimationComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v12->vfptr, UFG::CharacterAnimationComponent::_TypeUID));
  }
  else
  {
    v14 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v12);
  }
  if ( !v14 )
    return;
  v15 = v14->mCreature;
  if ( !v15 )
    return;
  v57 = 0;
  v16 = *(float *)&v3->m_Track[1].m_TrackClassNameUID;
  v17 = v16 / ActionContext::GetRunningMasterRate(v2);
  v18 = v3->m_Track;
  if ( BYTE1(v18[1].mMasterRate.value) == 1 )
  {
    v19 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0xB0ui64, "BlendAddNode", 0i64, 1u);
    v58 = v19;
    if ( v19 )
    {
      BlendAddNode::BlendAddNode((BlendAddNode *)v19, v17);
      v21 = v20;
    }
    else
    {
      v21 = 0i64;
    }
    UFG::qSafePointer<PoseNode,PoseNode>::operator=((UFG::qSafePointer<PoseNode,BlendNode> *)&v3->mSplitBodyBlend, v21);
    v22 = v3->mSplitBodyBlend.m_pPointer;
    v22[1].mPrev = (UFG::qNode<PoseNode,PoseNode> *)Creature::GetWeightSet(
                                                      v15,
                                                      (UFG::qSymbolUC *)&v3->m_Track[1].mMasterRate.expression);
    v23 = LOBYTE(v3->m_Track[1].mMasterRate.value);
    v24 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x170ui64, "AnimationTask.AnimationNode", 0i64, 1u);
    v58 = v24;
    if ( v24 )
      AnimationNode::AnimationNode(
        (AnimationNode *)v24,
        v11,
        v23,
        *(float *)&v3->m_Track[1].mResourceOwner,
        *((float *)&v3->m_Track[1].mResourceOwner + 1));
    else
      v25 = 0i64;
    UFG::qSafePointer<AnimationNode,AnimationNode>::operator=(&v3->mController, v25);
    v26 = v3->m_Track;
    returnCode = &v57;
    phaseIn[0] = FLOAT_N1_0;
    blendInTime = 0.0;
    LOBYTE(check_null) = 0;
    v27 = HIDWORD(v26[1].mMasterRate.text.mOffset);
    v28 = (PoseNodeParent *)&v21->vfptr;
  }
  else
  {
    v29 = Creature::GetWeightSet(v15, (UFG::qSymbolUC *)&v18[1].mMasterRate.expression);
    v30 = (UFG::qNode<PoseNode,PoseNode> *)v29;
    v31 = v3->m_Track;
    if ( SHIDWORD(v31[1].mMasterRate.text.mOffset) <= 0 && !v29 )
    {
      v32 = LOBYTE(v31[1].mMasterRate.value);
      v33 = *((_BYTE *)&v31[1].mMasterRate.value + 4) != 0;
      v34 = *(float *)&v31[1].m_TrackClassNameUID;
      v35 = *((float *)&v31[1].mResourceOwner + 1);
      returnCode = &v57;
      LOBYTE(phaseIn[0]) = v33;
      blendInTime = v34;
      check_null = LODWORD(v35);
      v36 = (AnimationNode *)Creature::PlayAnimation(
                               v15,
                               v11,
                               v32,
                               *(float *)&v31[1].mResourceOwner,
                               v35,
                               v34,
                               v33,
                               &v57);
      UFG::qSafePointer<AnimationNode,AnimationNode>::operator=(&v3->mController, v36);
      LOBYTE(v37) = *((_BYTE *)&v3->m_Track[1].mMasterRate.value + 5) != 0;
      v3->mController.m_pPointer->vfptr[3].__vecDelDtor((Expression::IMemberMap *)v3->mController.m_pPointer, v37);
      goto LABEL_46;
    }
    check_null = 1;
    if ( *((_BYTE *)&v31[1].mMasterRate.value + 4) )
    {
      v38 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0xB8ui64, "BlendPhaseNode", 0i64, check_null);
      v58 = v38;
      if ( v38 )
        BlendPhaseNode::BlendPhaseNode((BlendPhaseNode *)v38, v17);
      else
        v39 = 0i64;
    }
    else
    {
      v40 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0xB0ui64, "BlendNode", 0i64, check_null);
      v58 = v40;
      if ( v40 )
        BlendNode::BlendNode((BlendNode *)v40, v17);
      else
        v39 = 0i64;
    }
    UFG::qSafePointer<PoseNode,PoseNode>::operator=((UFG::qSafePointer<PoseNode,BlendNode> *)&v3->mSplitBodyBlend, v39);
    v3->mSplitBodyBlend.m_pPointer[1].mPrev = v30;
    BYTE3(v3->mSplitBodyBlend.m_pPointer[1].mParent.mOffset) = 1;
    v41 = LOBYTE(v3->m_Track[1].mMasterRate.value);
    v42 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x170ui64, "AnimationTask.AnimationNode", 0i64, 1u);
    v58 = v42;
    if ( v42 )
      AnimationNode::AnimationNode(
        (AnimationNode *)v42,
        v11,
        v41,
        *(float *)&v3->m_Track[1].mResourceOwner,
        *((float *)&v3->m_Track[1].mResourceOwner + 1));
    else
      v43 = 0i64;
    UFG::qSafePointer<AnimationNode,AnimationNode>::operator=(&v3->mController, v43);
    v44 = v3->m_Track;
    v45 = *((_BYTE *)&v44[1].mMasterRate.value + 4) != 0;
    returnCode = &v57;
    phaseIn[0] = *((float *)&v44[1].mResourceOwner + 1);
    blendInTime = *(float *)&v44[1].mResourceOwner;
    LOBYTE(check_null) = v45;
    v27 = HIDWORD(v44[1].mMasterRate.text.mOffset);
    v28 = (PoseNodeParent *)v3->mSplitBodyBlend.m_pPointer;
  }
  Creature::PlayBlendTree(
    v15,
    (PoseNode *)&v3->mController.m_pPointer->vfptr,
    v28,
    v27,
    check_null,
    blendInTime,
    phaseIn[0],
    returnCode);
LABEL_46:
  v46 = v3->mController.m_pPointer;
  if ( v46 )
  {
    v47 = v46->vfptr;
    ActionContext::GetRunningMasterRate(v3->mContext);
    v47[3].ResolveReferences((Expression::IMemberMap *)&v46->vfptr);
    ((void (__fastcall *)(AnimationNode *, ActionContext *))v3->mController.m_pPointer->vfptr[2].GetResourceOwner)(
      v3->mController.m_pPointer,
      v3->mContext);
    if ( BYTE2(v3->m_Track[1].mMasterRate.value) )
    {
      v3->mController.m_pPointer->mPlayStartTime = 0.0;
      v48 = LODWORD(v3->m_Track[1].mResourceOwner);
      ((void (*)(void))v3->mController.m_pPointer->vfptr[3].GetResourcePath)();
    }
  }
  if ( v57 )
  {
    v49 = v3->m_Track;
    v50 = (ActionNode *)&v2->mActionController->m_currentNode->vfptr;
    ActionNode::GetNameFullPath(v50, &pathToPopulate);
    ActionPath::GetString_DBG(&pathToPopulate);
    v49->vfptr->GetClassname((Expression::IMemberMap *)&v49->vfptr);
    v50->vfptr[3].GetClassNameUID((Expression::IMemberMap *)&v50->vfptr);
    UFG::qString::qString((UFG::qString *)&check_null);
    if ( v57 == 2 )
    {
      v51 = "BlendTree stack has blown Tree will be pruned could have some animation pops: inform FRSD of this ERROR message";
    }
    else
    {
      v51 = "Failed Active BlendTree Branch skipping and restarting: inform: FRSD of this ERROR message";
      if ( v57 != 1 )
        v51 = "no special error";
    }
    UFG::qString::Set((UFG::qString *)&check_null, v51);
    UFG::qString::~qString((UFG::qString *)&check_null);
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
  ActionContext *v2; // rax
  AnimationTask *v3; // rdi
  float v4; // xmm6_4
  UFG::SimObject *v5; // rax
  AnimationNode *v7; // rcx
  UFG::SimObjectCVBase *v8; // rcx
  unsigned __int16 v9; // dx
  UFG::CharacterAnimationComponent *v10; // rax
  AnimationNode *v11; // rsi
  ITrack *v12; // rax
  Expression::IMemberMapVtbl *v13; // rbx
  int v14; // ebp
  FloatInputSignal v15; // er14
  int v16; // xmm1_4
  UFG::SimObject *v17; // rcx
  int v18; // xmm0_4
  Expression::IMemberMapVtbl *v19; // rax
  int v20; // xmm1_4
  UFG::SimObject *v21; // rcx
  int v22; // xmm0_4
  float v23; // [rsp+30h] [rbp-28h]
  int v24; // [rsp+34h] [rbp-24h]
  int v25; // [rsp+38h] [rbp-20h]

  v2 = this->mContext;
  v3 = this;
  v4 = timeDelta;
  if ( v2 )
  {
    v5 = v2->mSimObject.m_pPointer;
    if ( v5 )
    {
      if ( (v5->m_Flags >> 10) & 1 )
        return 1;
    }
  }
  v7 = this->mController.m_pPointer;
  if ( v7 )
    AnimationNode::verifyBindAnimation(v7);
  v8 = (UFG::SimObjectCVBase *)v3->mContext->mSimObject.m_pPointer;
  if ( !v8 )
    return 0;
  v9 = v8->m_Flags;
  if ( (v9 >> 14) & 1 )
  {
    v10 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v8);
  }
  else if ( (v9 & 0x8000u) == 0 )
  {
    if ( (v9 >> 13) & 1 )
      v10 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v8);
    else
      v10 = (UFG::CharacterAnimationComponent *)((v9 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                    (UFG::SimObjectGame *)&v8->vfptr,
                                                                    UFG::CharacterAnimationComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v8->vfptr, UFG::CharacterAnimationComponent::_TypeUID));
  }
  else
  {
    v10 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v8);
  }
  if ( !v10 )
    return 0;
  v11 = v3->mController.m_pPointer;
  if ( !v11 || !v11->mSkeletalAnimationHandle.m_SkeletalAnimation.m_pPointer )
    return 0;
  v12 = v3->m_Track;
  v13 = v11->vfptr;
  v14 = LOBYTE(v12[1].mMasterRate.value);
  v15 = BYTE2(v12[1].mMasterRate.value);
  ActionContext::GetRunningMasterRate(v3->mContext);
  v13[3].ResolveReferences((Expression::IMemberMap *)&v11->vfptr);
  if ( v14 == 1 )
  {
    if ( v15 )
    {
      v20 = LODWORD(v3->mStartFacingVector.y);
      v21 = v3->mContext->mSimObject.m_pPointer;
      v23 = v3->mStartFacingVector.x;
      v22 = LODWORD(v3->mStartFacingVector.z);
      v24 = v20;
      v25 = v22;
      getSignalValue(v21, v15, v4, 6.2831855, (__int64)v3, (UFG::qVector3 *)&v23);
      ((void (*)(void))v3->mController.m_pPointer->vfptr[3].ResolveReferences)();
    }
  }
  else if ( v15 )
  {
    v16 = LODWORD(v3->mStartFacingVector.y);
    v17 = v3->mContext->mSimObject.m_pPointer;
    v23 = v3->mStartFacingVector.x;
    v18 = LODWORD(v3->mStartFacingVector.z);
    v24 = v16;
    v25 = v18;
    getSignalValue(v17, v15, v4, 6.2831855, (__int64)v3, (UFG::qVector3 *)&v23);
    v19 = v3->mController.m_pPointer->vfptr;
    if ( v14 == 3 )
    {
      ((void (*)(void))v19[3].GetClassNameUID)();
      return 1;
    }
    ((void (*)(void))v19[3].ResolveReferences)();
    if ( v14 == 5 && ((unsigned __int8 (*)(void))v3->mController.m_pPointer->vfptr[1].SetResourceOwner)() )
    {
      ((void (*)(void))v3->mController.m_pPointer->vfptr[1].GetResourceOwner)();
      v3->mFinished = 1;
      return 0;
    }
  }
  else if ( ((unsigned __int8 (*)(void))v3->mController.m_pPointer->vfptr[1].SetResourceOwner)() )
  {
    ((void (*)(void))v3->mController.m_pPointer->vfptr[1].GetResourceOwner)();
    v3->mFinished = 1;
    return v14 == 2;
  }
  return 1;
}

// File Line: 414
// RVA: 0x312210
void __fastcall AnimationTask::End(AnimationTask *this)
{
  UFG::TransformNodeComponent *v1; // rsi
  AnimationTask *v2; // rdi
  ITrack *v3; // rax
  float v4; // xmm6_4
  float v5; // xmm0_4
  PoseNode *v6; // rax
  float v7; // xmm6_4
  UFG::SimObjectCVBase *v8; // rcx
  UFG::AICharacterControllerBaseComponent *v9; // rbx
  unsigned __int16 v10; // dx
  UFG::AICharacterControllerBaseComponent *v11; // rax
  UFG::SimObject *v12; // rcx
  float v13; // xmm0_4
  float v14; // xmm1_4

  v1 = 0i64;
  v2 = this;
  if ( this->mController.m_pPointer )
  {
    if ( this->mSplitBodyBlend.m_pPointer )
    {
      v3 = this->m_Track;
      if ( SHIDWORD(v3[1].mMasterRate.text.mOffset) > 0 || BYTE1(v3[1].mMasterRate.value) == 1 )
      {
        v4 = *(float *)&v3[1].mBreakPoint;
        v5 = ActionContext::GetRunningMasterRate(this->mContext);
        v6 = v2->mSplitBodyBlend.m_pPointer;
        v7 = v4 / v5;
        if ( v7 == 0.0 )
        {
          HIDWORD(v6[1].mParent.mOffset) = -1082130432;
          v6[1].mPriority = 0;
        }
        else
        {
          if ( v7 <= 0.0 )
            goto LABEL_10;
          *((float *)&v6[1].mParent.mOffset + 1) = -1.0 / v7;
        }
        BYTE3(v6[1].mParent.mOffset) = 0;
      }
    }
  }
LABEL_10:
  if ( *((_BYTE *)&v2->m_Track[1].mMasterRate.value + 6) )
  {
    v8 = (UFG::SimObjectCVBase *)v2->mContext->mSimObject.m_pPointer;
    if ( v8 )
    {
      v10 = v8->m_Flags;
      if ( (v10 >> 14) & 1 )
      {
        v11 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v8);
      }
      else if ( (v10 & 0x8000u) == 0 )
      {
        if ( (v10 >> 13) & 1 )
        {
          v11 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             (UFG::SimObjectGame *)&v8->vfptr,
                                                             UFG::AICharacterControllerBaseComponent::_TypeUID);
        }
        else if ( (v10 >> 12) & 1 )
        {
          v11 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             (UFG::SimObjectGame *)&v8->vfptr,
                                                             UFG::AICharacterControllerBaseComponent::_TypeUID);
        }
        else
        {
          v11 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                             (UFG::SimObject *)&v8->vfptr,
                                                             UFG::AICharacterControllerBaseComponent::_TypeUID);
        }
      }
      else
      {
        v11 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v8);
      }
      v9 = v11;
    }
    else
    {
      v9 = 0i64;
    }
    v12 = v2->mContext->mSimObject.m_pPointer;
    if ( v12 )
      v1 = v12->m_pTransformNodeComponent;
    if ( v9 && v1 && v9->m_Intention.mMotionIntentionSpeed <= 0.0 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(v1);
      v13 = v1->mWorldTransform.v0.y;
      v14 = v1->mWorldTransform.v0.z;
      v9->m_Intention.mMotionIntentionDirection.x = v1->mWorldTransform.v0.x;
      v9->m_Intention.mMotionIntentionDirection.y = v13;
      v9->m_Intention.mMotionIntentionDirection.z = v14;
      v9->m_IntentionUpdated = 1;
    }
  }
}

// File Line: 463
// RVA: 0x30F110
void __fastcall AnimationRefPoseTask::AnimationRefPoseTask(AnimationRefPoseTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax
  UFG::qSafePointer<AnimationNode,AnimationNode> *v2; // [rsp+28h] [rbp+10h]
  UFG::qSafePointer<PoseNode,PoseNode> *v3; // [rsp+28h] [rbp+10h]

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable';
  this->vfptr = (ITaskVtbl *)&Task<AnimationRefPoseTrack>::`vftable';
  this->vfptr = (ITaskVtbl *)&AnimationRefPoseTask::`vftable';
  v2 = &this->mController;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  this->mController.m_pPointer = 0i64;
  v3 = &this->mSplitBodyBlend;
  v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  v3->mNext = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  this->mSplitBodyBlend.m_pPointer = 0i64;
  this->mFinished = 1;
}

// File Line: 467
// RVA: 0x310410
void __fastcall AnimationRefPoseTask::AddTheAnim(AnimationRefPoseTask *this, UFG::CharacterAnimationComponent *characterAnimationComponent)
{
  AnimationRefPoseTask *v2; // rdi
  Creature *v3; // rbp
  AnimationNode *v4; // rsi
  ITrack *v5; // rax
  char *v6; // rax
  PoseNode *v7; // rax
  PoseNode *v8; // r8
  UFG::qSafePointer<PoseNode,PoseNode> *v9; // rdx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v12; // rax
  PoseNode *v13; // rbx
  char *v14; // rax
  AnimationNode *v15; // rax
  UFG::qSafePointer<AnimationNode,AnimationNode> *v16; // rdx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v17; // rcx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v18; // rax
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v19; // rax
  PoseNode *v20; // rax
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v21; // rdx
  UFG::qSafePointer<AnimationNode,AnimationNode> *v22; // r8
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v23; // rcx
  Expression::IMemberMap **v24; // rcx
  Expression::IMemberMap *v25; // rax
  AnimationNode *v26; // rdx
  int returnCode; // [rsp+78h] [rbp+10h]
  char *v28; // [rsp+80h] [rbp+18h]

  v2 = this;
  v3 = characterAnimationComponent->mCreature;
  if ( v3 )
  {
    v4 = 0i64;
    returnCode = 0;
    v5 = this->m_Track;
    if ( (signed int)v5[1].m_TrackClassNameUID <= 0 )
    {
      v20 = Creature::PlayAnimation(
              v3,
              &UFG::gNullQSymbolUC,
              0,
              *(float *)&v5[1].vfptr,
              *((float *)&v5[1].vfptr + 1),
              *(float *)&v5[1].mResourceOwner,
              0,
              &returnCode);
      v22 = &v2->mController;
      if ( v2->mController.m_pPointer )
      {
        v21 = v22->mPrev;
        v23 = v2->mController.mNext;
        v21->mNext = v23;
        v23->mPrev = v21;
        v22->mPrev = (UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *)&v22->mPrev;
        v2->mController.mNext = (UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *)&v2->mController.mPrev;
      }
      v2->mController.m_pPointer = (AnimationNode *)v20;
      if ( v20 )
      {
        v24 = &v20[1].mResourceOwner;
        v25 = v20[1].mResourceOwner;
        v25->mResourceOwner = (Expression::IMemberMap *)v22;
        v22->mPrev = (UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *)v25;
        v2->mController.mNext = (UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *)v24;
        *v24 = (Expression::IMemberMap *)v22;
      }
      LOBYTE(v21) = LOBYTE(v2->m_Track[1].mMasterRate.text.mOffset) != 0;
      v2->mController.m_pPointer->vfptr[3].__vecDelDtor(
        (Expression::IMemberMap *)v2->mController.m_pPointer,
        (unsigned int)v21);
    }
    else
    {
      v6 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0xB0ui64, "BlendNode", 0i64, 1u);
      v28 = v6;
      if ( v6 )
      {
        BlendNode::BlendNode((BlendNode *)v6, *(float *)&v2->m_Track[1].mResourceOwner);
        v8 = v7;
      }
      else
      {
        v8 = 0i64;
      }
      v9 = &v2->mSplitBodyBlend;
      if ( v2->mSplitBodyBlend.m_pPointer )
      {
        v10 = v9->mPrev;
        v11 = v2->mSplitBodyBlend.mNext;
        v10->mNext = v11;
        v11->mPrev = v10;
        v9->mPrev = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v9->mPrev;
        v2->mSplitBodyBlend.mNext = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v2->mSplitBodyBlend.mPrev;
      }
      v2->mSplitBodyBlend.m_pPointer = v8;
      if ( v8 )
      {
        v12 = v8->m_SafePointerList.mNode.mPrev;
        v12->mNext = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v9->mPrev;
        v9->mPrev = v12;
        v2->mSplitBodyBlend.mNext = &v8->m_SafePointerList.mNode;
        v8->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v9->mPrev;
      }
      v13 = v2->mSplitBodyBlend.m_pPointer;
      v13[1].mPrev = (UFG::qNode<PoseNode,PoseNode> *)Creature::GetWeightSet(
                                                        v3,
                                                        (UFG::qSymbolUC *)&v2->m_Track[1].mBreakPoint);
      BYTE3(v2->mSplitBodyBlend.m_pPointer[1].mParent.mOffset) = 1;
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
          0,
          *(float *)&v2->m_Track[1].vfptr,
          -1.0);
        v4 = v15;
      }
      v16 = &v2->mController;
      if ( v2->mController.m_pPointer )
      {
        v17 = v16->mPrev;
        v18 = v2->mController.mNext;
        v17->mNext = v18;
        v18->mPrev = v17;
        v16->mPrev = (UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *)&v16->mPrev;
        v2->mController.mNext = (UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *)&v2->mController.mPrev;
      }
      v2->mController.m_pPointer = v4;
      if ( v4 )
      {
        v19 = v4->m_SafePointerList.mNode.mPrev;
        v19->mNext = (UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *)&v16->mPrev;
        v16->mPrev = v19;
        v2->mController.mNext = &v4->m_SafePointerList.mNode;
        v4->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *)&v16->mPrev;
      }
      Creature::PlayBlendTree(
        v3,
        (PoseNode *)&v2->mController.m_pPointer->vfptr,
        (PoseNodeParent *)v2->mSplitBodyBlend.m_pPointer,
        v2->m_Track[1].m_TrackClassNameUID,
        0,
        *(float *)&v2->m_Track[1].vfptr,
        *((float *)&v2->m_Track[1].vfptr + 1),
        &returnCode);
    }
    v26 = v2->mController.m_pPointer;
    if ( v26 )
    {
      v26->mPlayEndTime = *((float *)&v2->m_Track[1].vfptr + 1);
      ((void (__fastcall *)(AnimationNode *, ActionContext *))v2->mController.m_pPointer->vfptr[2].GetResourceOwner)(
        v2->mController.m_pPointer,
        v2->mContext);
    }
  }
}

// File Line: 500
// RVA: 0x3109D0
void __fastcall AnimationRefPoseTask::Begin(AnimationRefPoseTask *this, ActionContext *context)
{
  AnimationRefPoseTask *v2; // rbx
  UFG::SimObject *v3; // rax
  UFG::TransformNodeComponent *v4; // rdi
  float v5; // xmm5_4
  float v6; // xmm6_4
  float v7; // xmm2_4
  __m128 v8; // xmm4
  __m128 v9; // xmm3
  UFG::SimObjectCVBase *v10; // rcx
  unsigned __int16 v11; // dx
  UFG::CharacterAnimationComponent *v12; // rax

  v2 = this;
  this->mContext = context;
  if ( !context || !context->mSimObject.m_pPointer || !((context->mSimObject.m_pPointer->m_Flags >> 10) & 1) )
  {
    v3 = context->mSimObject.m_pPointer;
    if ( v3 )
      v4 = v3->m_pTransformNodeComponent;
    else
      v4 = 0i64;
    UFG::TransformNodeComponent::UpdateWorldTransform(v4);
    v5 = v4->mWorldTransform.v0.y;
    v6 = v4->mWorldTransform.v0.z;
    v7 = 0.0;
    v2->mStartFacingVector.x = v4->mWorldTransform.v0.x;
    v2->mStartFacingVector.y = v5;
    v8 = (__m128)LODWORD(v2->mStartFacingVector.x);
    v2->mStartFacingVector.z = v6;
    v9 = v8;
    v9.m128_f32[0] = (float)((float)(v8.m128_f32[0] * v8.m128_f32[0]) + (float)(v5 * v5)) + (float)(v6 * v6);
    if ( v9.m128_f32[0] != 0.0 )
      v7 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v9));
    v2->mStartFacingVector.x = v8.m128_f32[0] * v7;
    v2->mStartFacingVector.z = v7 * v6;
    v2->mStartFacingVector.y = v7 * v5;
    v10 = (UFG::SimObjectCVBase *)v2->mContext->mSimObject.m_pPointer;
    if ( v10 )
    {
      v11 = v10->m_Flags;
      if ( (v11 >> 14) & 1 )
      {
        v12 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v10);
      }
      else if ( (v11 & 0x8000u) == 0 )
      {
        if ( (v11 >> 13) & 1 )
        {
          v12 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v10);
        }
        else if ( (v11 >> 12) & 1 )
        {
          v12 = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      (UFG::SimObjectGame *)&v10->vfptr,
                                                      UFG::CharacterAnimationComponent::_TypeUID);
        }
        else
        {
          v12 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                      (UFG::SimObject *)&v10->vfptr,
                                                      UFG::CharacterAnimationComponent::_TypeUID);
        }
      }
      else
      {
        v12 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v10);
      }
      if ( v12 )
        AnimationRefPoseTask::AddTheAnim(v2, v12);
    }
  }
}

// File Line: 517
// RVA: 0x312CA0
char __fastcall AnimationRefPoseTask::Update(AnimationRefPoseTask *this, float timeDelta)
{
  AnimationRefPoseTask *v2; // rbx
  ActionContext *v3; // rcx
  UFG::SimObject *v4; // rax
  UFG::SimObjectCVBase *v5; // rcx
  unsigned __int16 v6; // dx
  UFG::CharacterAnimationComponent *v7; // rax

  v2 = this;
  v3 = this->mContext;
  if ( !v3 || (v4 = v3->mSimObject.m_pPointer) == 0i64 || !((v4->m_Flags >> 10) & 1) )
  {
    if ( !v2->mController.m_pPointer )
    {
      v5 = (UFG::SimObjectCVBase *)v3->mSimObject.m_pPointer;
      if ( v5 )
      {
        v6 = v5->m_Flags;
        if ( (v6 >> 14) & 1 )
        {
          v7 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v5);
        }
        else if ( (v6 & 0x8000u) == 0 )
        {
          if ( (v6 >> 13) & 1 )
          {
            v7 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v5);
          }
          else if ( (v6 >> 12) & 1 )
          {
            v7 = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                       (UFG::SimObjectGame *)&v5->vfptr,
                                                       UFG::CharacterAnimationComponent::_TypeUID);
          }
          else
          {
            v7 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                       (UFG::SimObject *)&v5->vfptr,
                                                       UFG::CharacterAnimationComponent::_TypeUID);
          }
        }
        else
        {
          v7 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v5);
        }
        if ( v7 )
          AnimationRefPoseTask::AddTheAnim(v2, v7);
      }
    }
  }
  return 1;
}

// File Line: 536
// RVA: 0x3120B0
void __fastcall AnimationRefPoseTask::End(AnimationRefPoseTask *this)
{
  UFG::TransformNodeComponent *v1; // rdi
  AnimationRefPoseTask *v2; // rsi
  PoseNode *v3; // rdx
  float v4; // xmm1_4
  UFG::SimObjectCVBase *v5; // rcx
  UFG::AICharacterControllerBaseComponent *v6; // rbx
  unsigned __int16 v7; // dx
  UFG::AICharacterControllerBaseComponent *v8; // rax
  UFG::SimObject *v9; // rcx
  float v10; // xmm0_4
  float v11; // xmm1_4

  v1 = 0i64;
  v2 = this;
  if ( this->mController.m_pPointer )
  {
    v3 = this->mSplitBodyBlend.m_pPointer;
    if ( v3 )
    {
      v4 = *((float *)&this->m_Track[1].mResourceOwner + 1);
      if ( v4 == 0.0 )
      {
        HIDWORD(v3[1].mParent.mOffset) = -1082130432;
        v3[1].mPriority = 0;
      }
      else
      {
        if ( v4 <= 0.0 )
          goto LABEL_8;
        *((float *)&v3[1].mParent.mOffset + 1) = -1.0 / v4;
      }
      BYTE3(v3[1].mParent.mOffset) = 0;
    }
  }
LABEL_8:
  if ( BYTE1(this->m_Track[1].mMasterRate.text.mOffset) )
  {
    v5 = (UFG::SimObjectCVBase *)this->mContext->mSimObject.m_pPointer;
    if ( v5 )
    {
      v7 = v5->m_Flags;
      if ( (v7 >> 14) & 1 )
      {
        v8 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v5);
      }
      else if ( (v7 & 0x8000u) == 0 )
      {
        if ( (v7 >> 13) & 1 )
        {
          v8 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            (UFG::SimObjectGame *)&v5->vfptr,
                                                            UFG::AICharacterControllerBaseComponent::_TypeUID);
        }
        else if ( (v7 >> 12) & 1 )
        {
          v8 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            (UFG::SimObjectGame *)&v5->vfptr,
                                                            UFG::AICharacterControllerBaseComponent::_TypeUID);
        }
        else
        {
          v8 = (UFG::AICharacterControllerBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                            (UFG::SimObject *)&v5->vfptr,
                                                            UFG::AICharacterControllerBaseComponent::_TypeUID);
        }
      }
      else
      {
        v8 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v5);
      }
      v6 = v8;
    }
    else
    {
      v6 = 0i64;
    }
    v9 = v2->mContext->mSimObject.m_pPointer;
    if ( v9 )
      v1 = v9->m_pTransformNodeComponent;
    if ( v6 && v1 && v6->m_Intention.mMotionIntentionSpeed <= 0.0 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(v1);
      v10 = v1->mWorldTransform.v0.y;
      v11 = v1->mWorldTransform.v0.z;
      v6->m_Intention.mMotionIntentionDirection.x = v1->mWorldTransform.v0.x;
      v6->m_Intention.mMotionIntentionDirection.y = v10;
      v6->m_Intention.mMotionIntentionDirection.z = v11;
      v6->m_IntentionUpdated = 1;
    }
  }
}

// File Line: 573
// RVA: 0x30F080
void __fastcall AnimationLockHighLODTask::AnimationLockHighLODTask(AnimationLockHighLODTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax
  UFG::qNode<AnimationLockHighLODTask,AnimationLockHighLODList> *v2; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable';
  this->vfptr = (ITaskVtbl *)&Task<AnimationLockHighLODTrack>::`vftable';
  v2 = (UFG::qNode<AnimationLockHighLODTask,AnimationLockHighLODList> *)&this->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->vfptr = (ITaskVtbl *)&AnimationLockHighLODTask::`vftable';
}

// File Line: 583
// RVA: 0x310930
void __fastcall AnimationLockHighLODTask::Begin(AnimationLockHighLODTask *this, ActionContext *pActionContext)
{
  AnimationLockHighLODTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::AnimationLODComponent *v5; // rax

  v2 = this;
  this->m_pActionContext = pActionContext;
  v3 = (UFG::SimObjectGame *)pActionContext->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = (UFG::AnimationLODComponent *)v3->m_Components.p[13].m_pComponent;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
      {
        v5 = (UFG::AnimationLODComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             v3,
                                             UFG::AnimationLODComponent::_TypeUID);
      }
      else if ( (v4 >> 12) & 1 )
      {
        v5 = (UFG::AnimationLODComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             v3,
                                             UFG::AnimationLODComponent::_TypeUID);
      }
      else
      {
        v5 = (UFG::AnimationLODComponent *)UFG::SimObject::GetComponentOfType(
                                             (UFG::SimObject *)&v3->vfptr,
                                             UFG::AnimationLODComponent::_TypeUID);
      }
    }
    else
    {
      v5 = (UFG::AnimationLODComponent *)v3->m_Components.p[13].m_pComponent;
    }
    if ( v5 )
      UFG::AnimationLODComponent::AddAnimationLockHighLODTask(v5, v2);
  }
}

// File Line: 605
// RVA: 0x311900
void __fastcall BlendTreeControllerBaseTask<BlendTreeControllerTargetDistancTrack>::Bind(BlendTreeControllerBaseTask<BlendTreeControllerTrack> *this, PoseNode *poseNode)
{
  BlendTreeControllerBaseTask<BlendTreeControllerTrack> *v2; // rbx
  Expression::IMemberMap *v3; // rax
  UFG::qSafePointer<PoseNode,PoseNode> *v4; // rbx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v5; // rdx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v6; // rcx
  Expression::IMemberMap **v7; // rcx
  Expression::IMemberMap *v8; // rax

  v2 = this;
  v3 = poseNode->vfptr[4].FindWithOldPath((Expression::IMemberMap *)poseNode, (const char *)&this->m_Track[1]);
  v4 = &v2->mPlayingTree;
  if ( v4->m_pPointer )
  {
    v5 = v4->mPrev;
    v6 = v4->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v4->mPrev;
    v4->mNext = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  }
  v4->m_pPointer = (PoseNode *)v3;
  if ( v3 )
  {
    v7 = &v3[1].mResourceOwner;
    v8 = v3[1].mResourceOwner;
    v8->mResourceOwner = (Expression::IMemberMap *)v4;
    v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)v8;
    v4->mNext = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)v7;
    *v7 = (Expression::IMemberMap *)v4;
  }
}

// File Line: 613
// RVA: 0x30F640
void __fastcall BlendTreeTask::BlendTreeTask(BlendTreeTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax
  UFG::qSafePointer<PoseNode,PoseNode> *v2; // rdx
  UFG::qSafePointer<PoseNode,BlendNode> *v3; // r8
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v4; // rcx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v5; // rax
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qList<IBlendTreeControllerTask,IBlendTreeControllerTask,0,0> *v8; // [rsp+28h] [rbp+10h]

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable';
  this->vfptr = (ITaskVtbl *)&Task<BlendTreeTrack>::`vftable';
  this->vfptr = (ITaskVtbl *)&BlendTreeTask::`vftable';
  v2 = &this->mPlayingTree;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  this->mPlayingTree.m_pPointer = 0i64;
  v3 = &this->mSplitBodyBlend;
  v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  v3->mNext = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  this->mSplitBodyBlend.m_pPointer = 0i64;
  v8 = &this->mActiveControllers;
  v8->mNode.mPrev = &v8->mNode;
  v8->mNode.mNext = &v8->mNode;
  if ( this->mSplitBodyBlend.m_pPointer )
  {
    v4 = v3->mPrev;
    v5 = v3->mNext;
    v4->mNext = v5;
    v5->mPrev = v4;
    v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v3->mPrev;
    v3->mNext = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  }
  v3->m_pPointer = 0i64;
  if ( v2->m_pPointer )
  {
    v6 = v2->mPrev;
    v7 = v2->mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  }
  v2->m_pPointer = 0i64;
}

// File Line: 619
// RVA: 0x311300
void __fastcall BlendTreeTask::Begin(BlendTreeTask *this, ActionContext *context)
{
  ActionContext *v2; // r15
  BlendTreeTask *v3; // rsi
  UFG::SimObject *v4; // rax
  UFG::SimObjectCVBase *v5; // rcx
  unsigned int v6; // er14
  unsigned __int16 v7; // dx
  UFG::CharacterAnimationComponent *v8; // rax
  Creature *v9; // rdi
  float v10; // xmm6_4
  float v11; // xmm6_4
  ITrack *v12; // rcx
  UFG::qSymbolUC *v13; // r13
  BlendTreeDataBase *v14; // rax
  PoseNode *v15; // rax
  ITrack *v16; // rcx
  int v17; // er12
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
  ActionNode *v32; // rdi
  const char *v33; // rdx
  int v34; // edx
  PoseNode *v35; // rcx
  __int64 v36; // r15
  PoseNode *v37; // rbx
  Expression::IMemberMapVtbl *v38; // rdi
  signed __int64 v39; // r12
  UFG::qList<IBlendTreeControllerTask,IBlendTreeControllerTask,0,0> *v40; // rdi
  signed __int64 v41; // rcx
  __int64 v42; // rbx
  UFG::qNode<IBlendTreeControllerTask,IBlendTreeControllerTask> **v43; // rcx
  UFG::qNode<IBlendTreeControllerTask,IBlendTreeControllerTask> *v44; // rax
  ITrack *v45; // rdi
  ActionNode *v46; // rbx
  __int64 v47; // rax
  __int64 v48; // r10
  unsigned int v49; // er11
  unsigned int v50; // edx
  __int64 v51; // r9
  __int64 v52; // rcx
  signed __int64 v53; // rax
  signed __int64 v54; // r8
  __int64 v55; // rax
  ITrack *v56; // rax
  int v57; // edx
  ActionPath pathToPopulate; // [rsp+8h] [rbp-51h]
  UFG::qString v59; // [rsp+18h] [rbp-41h]
  int v60; // [rsp+C0h] [rbp+67h]
  UFG::qSymbolUC animUID; // [rsp+C8h] [rbp+6Fh]
  int priority[2]; // [rsp+D0h] [rbp+77h]
  char *v63; // [rsp+D8h] [rbp+7Fh]

  v2 = context;
  v3 = this;
  this->mContext = context;
  animUID.mUID = (unsigned int)this->m_Track[1].mResourceOwner;
  if ( !context || (v4 = context->mSimObject.m_pPointer) == 0i64 || !((v4->m_Flags >> 10) & 1) )
  {
    v5 = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
    v6 = 0;
    if ( v5 )
    {
      v7 = v5->m_Flags;
      if ( (v7 >> 14) & 1 )
      {
        v8 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v5);
      }
      else if ( (v7 & 0x8000u) == 0 )
      {
        if ( (v7 >> 13) & 1 )
          v8 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v5);
        else
          v8 = (UFG::CharacterAnimationComponent *)((v7 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                       (UFG::SimObjectGame *)&v5->vfptr,
                                                                       UFG::CharacterAnimationComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v5->vfptr, UFG::CharacterAnimationComponent::_TypeUID));
      }
      else
      {
        v8 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v5);
      }
      if ( v8 )
      {
        v9 = v8->mCreature;
        if ( v9 )
        {
          v60 = 0;
          v10 = *(float *)&v3->m_Track[1].m_TrackClassNameUID;
          v11 = v10 / ActionContext::GetRunningMasterRate(v2);
          v12 = v3->m_Track;
          v13 = (UFG::qSymbolUC *)((char *)&v12[1].mResourceOwner + 4);
          if ( HIDWORD(v12[1].mResourceOwner) == symNone.mUID )
          {
            v30 = (BlendNode *)Creature::PlayBlendTree(
                                 v9,
                                 &animUID,
                                 SLOBYTE(v12[1].mMasterRate.expression.mOffset),
                                 v11,
                                 BYTE1(v12[1].mMasterRate.expression.mOffset) != 0,
                                 *(float *)&v12[1].mMasterRate.text.mOffset,
                                 *((float *)&v12[1].mMasterRate.text.mOffset + 1),
                                 &v60);
            UFG::qSafePointer<PoseNode,PoseNode>::operator=(
              (UFG::qSafePointer<PoseNode,BlendNode> *)&v3->mPlayingTree,
              v30);
          }
          else
          {
            v14 = BlendTreeDataBase::GetInstance();
            v15 = BlendTreeDataBase::FindBlendTree(v14, &animUID);
            if ( v15 )
            {
              v16 = v3->m_Track;
              v17 = SLOBYTE(v16[1].mMasterRate.expression.mOffset);
              priority[0] = SLOBYTE(v16[1].mMasterRate.expression.mOffset);
              v18 = *(float *)&v16[1].mMasterRate.text.mOffset;
              v19 = *((float *)&v16[1].mMasterRate.text.mOffset + 1);
              v20 = (BlendNode *)((__int64 (__fastcall *)(PoseNode *))v15->vfptr[1].Serialize)(v15);
              UFG::qSafePointer<PoseNode,PoseNode>::operator=(
                (UFG::qSafePointer<PoseNode,BlendNode> *)&v3->mPlayingTree,
                v20);
              v21 = v3->m_Track;
              LODWORD(v59.mNext) = 1;
              if ( BYTE3(v21[1].mMasterRate.expression.mOffset) == 1 )
              {
                v22 = UFG::qMemoryPool2::Allocate(
                        &gActionTreeMemoryPool,
                        0xB0ui64,
                        "BlendAddNode",
                        0i64,
                        (unsigned int)v59.mNext);
                v63 = v22;
                if ( v22 )
                {
                  BlendAddNode::BlendAddNode((BlendAddNode *)v22, v11);
                  v24 = v23;
                }
                else
                {
                  v24 = 0i64;
                }
                UFG::qSafePointer<PoseNode,PoseNode>::operator=(&v3->mSplitBodyBlend, v24);
                v25 = v3->mSplitBodyBlend.m_pPointer;
                v25[1].mPrev = (UFG::qNode<PoseNode,PoseNode> *)Creature::GetWeightSet(v9, v13);
                Creature::PlayBlendTree(
                  v9,
                  v3->mPlayingTree.m_pPointer,
                  (PoseNodeParent *)&v24->vfptr,
                  priority[0],
                  0,
                  v18,
                  v19,
                  &v60);
                if ( BYTE2(v3->m_Track[1].mMasterRate.expression.mOffset) == 2 )
                {
                  ((void (*)(void))v3->mPlayingTree.m_pPointer->vfptr[2].SetResourceOwner)();
                  ((void (*)(void))v3->mPlayingTree.m_pPointer->vfptr[3].GetResourcePath)();
                  ((void (*)(void))v3->mPlayingTree.m_pPointer->vfptr[1].GetResourceOwner)();
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
                          (unsigned int)v59.mNext);
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
                          (unsigned int)v59.mNext);
                  *(_QWORD *)priority = v28;
                  if ( v28 )
                    BlendNode::BlendNode((BlendNode *)v28, v11);
                  else
                    v27 = 0i64;
                }
                UFG::qSafePointer<PoseNode,PoseNode>::operator=(&v3->mSplitBodyBlend, v27);
                BYTE3(v3->mSplitBodyBlend.m_pPointer[1].mParent.mOffset) = 1;
                v29 = v3->mSplitBodyBlend.m_pPointer;
                v29[1].mPrev = (UFG::qNode<PoseNode,PoseNode> *)Creature::GetWeightSet(v9, v13);
                Creature::PlayBlendTree(
                  v9,
                  v3->mPlayingTree.m_pPointer,
                  (PoseNodeParent *)v3->mSplitBodyBlend.m_pPointer,
                  v17,
                  0,
                  v18,
                  v19,
                  &v60);
              }
            }
          }
          if ( v60 )
          {
            v31 = v3->m_Track;
            v32 = (ActionNode *)&v2->mActionController->m_currentNode->vfptr;
            ActionNode::GetNameFullPath(v32, &pathToPopulate);
            ActionPath::GetString_DBG(&pathToPopulate);
            v31->vfptr->GetClassname((Expression::IMemberMap *)&v31->vfptr);
            v32->vfptr[3].GetClassNameUID((Expression::IMemberMap *)&v32->vfptr);
            UFG::qString::qString(&v59);
            if ( v60 == 2 )
            {
              v33 = "BlendTree stack has blown Tree will be pruned could have some animation pops: inform FRSD of this ERROR message";
            }
            else
            {
              v33 = "Failed Active BlendTree Branch skipping and restarting: inform: FRSD of this ERROR message";
              if ( v60 != 1 )
                v33 = "no special error";
            }
            UFG::qString::Set(&v59, v33);
            UFG::qString::~qString(&v59);
            v34 = pathToPopulate.mPath.mCount;
            if ( pathToPopulate.mPath.mCount >= 0 )
            {
              if ( pathToPopulate.mPath.mData.mOffset
                && (UFG::qOffset64<ActionID *> *)((char *)&pathToPopulate.mPath.mData
                                                + pathToPopulate.mPath.mData.mOffset) )
              {
                operator delete[]((char *)&pathToPopulate.mPath.mData + pathToPopulate.mPath.mData.mOffset);
                v34 = pathToPopulate.mPath.mCount;
              }
              pathToPopulate.mPath.mData.mOffset = 0i64;
              pathToPopulate.mPath.mCount = v34 & 0x80000000;
            }
          }
        }
      }
    }
    v35 = v3->mPlayingTree.m_pPointer;
    if ( v35 )
    {
      ((void (__fastcall *)(PoseNode *, ActionContext *))v35->vfptr[2].GetResourceOwner)(v35, v3->mContext);
      v36 = ((__int64 (*)(void))v3->m_Track->vfptr[1].GetResourcePath)();
      v37 = v3->mPlayingTree.m_pPointer;
      v38 = v37->vfptr;
      ActionContext::GetRunningMasterRate(v3->mContext);
      v38[3].ResolveReferences((Expression::IMemberMap *)&v37->vfptr);
      v39 = v36 + *(_QWORD *)(v36 + 24) + 24i64;
      if ( *(_DWORD *)(v36 + 16) & 0x7FFFFFFF )
      {
        v40 = &v3->mActiveControllers;
        do
        {
          v41 = *(_QWORD *)(v39 + 8i64 * v6) + v39 + 8i64 * v6;
          v42 = (*(__int64 (__fastcall **)(signed __int64, const char *))(*(_QWORD *)v41 + 80i64))(
                  v41,
                  "BlendTreeTask::Begin()");
          (*(void (__fastcall **)(__int64, PoseNode *))(*(_QWORD *)v42 + 8i64))(v42, v3->mPlayingTree.m_pPointer);
          (*(void (__fastcall **)(__int64, ActionContext *))(*(_QWORD *)v42 + 16i64))(v42, v3->mContext);
          v43 = (UFG::qNode<IBlendTreeControllerTask,IBlendTreeControllerTask> **)(v42 + 8);
          v44 = v40->mNode.mPrev;
          v44->mNext = (UFG::qNode<IBlendTreeControllerTask,IBlendTreeControllerTask> *)(v42 + 8);
          *v43 = v44;
          v43[1] = &v40->mNode;
          v40->mNode.mPrev = (UFG::qNode<IBlendTreeControllerTask,IBlendTreeControllerTask> *)(v42 + 8);
          ++v6;
        }
        while ( v6 < (*(_DWORD *)(v36 + 16) & 0x7FFFFFFFu) );
      }
      v3->mPlayingTree.m_pPointer->vfptr[2].FindWithOldPath(
        (Expression::IMemberMap *)v3->mPlayingTree.m_pPointer,
        (const char *)BYTE2(v3->m_Track[1].mMasterRate.expression.mOffset));
    }
    else
    {
      v45 = v3->m_Track;
      v46 = (ActionNode *)&v2->mActionController->m_currentNode->vfptr;
      ActionNode::GetNameFullPath(v46, &pathToPopulate);
      ActionPath::GetString_DBG(&pathToPopulate);
      v45->vfptr->GetClassname((Expression::IMemberMap *)&v45->vfptr);
      v47 = v46->vfptr[3].GetClassNameUID((Expression::IMemberMap *)&v46->vfptr);
      v48 = v47;
      v49 = *(_DWORD *)(v47 + 16) & 0x7FFFFFFF;
      v50 = 0;
      if ( v49 )
      {
        v51 = *(_QWORD *)(v47 + 24);
        v52 = 0i64;
        do
        {
          if ( v51 )
            v53 = v51 + v48 + 24;
          else
            v53 = 0i64;
          v54 = v52 + v53;
          v55 = *(_QWORD *)(v52 + v53);
          if ( v55 )
            v56 = (ITrack *)(v54 + v55);
          else
            v56 = 0i64;
          if ( v45 == v56 )
            break;
          ++v50;
          v52 += 8i64;
        }
        while ( v50 < v49 );
      }
      v57 = pathToPopulate.mPath.mCount;
      if ( pathToPopulate.mPath.mCount >= 0 )
      {
        if ( pathToPopulate.mPath.mData.mOffset
          && (UFG::qOffset64<ActionID *> *)((char *)&pathToPopulate.mPath.mData + pathToPopulate.mPath.mData.mOffset) )
        {
          operator delete[]((char *)&pathToPopulate.mPath.mData + pathToPopulate.mPath.mData.mOffset);
          v57 = pathToPopulate.mPath.mCount;
        }
        pathToPopulate.mPath.mData.mOffset = 0i64;
        pathToPopulate.mPath.mCount = v57 & 0x80000000;
      }
    }
    ((void (__fastcall *)(BlendTreeTask *))v3->vfptr->Update)(v3);
  }
}

// File Line: 785
// RVA: 0x3134B0
bool __fastcall BlendTreeTask::Update(BlendTreeTask *this, float timeDelta)
{
  BlendTreeTask *v2; // rdi
  ActionContext *v3; // rcx
  UFG::SimObject *v4; // rax
  PoseNode *v6; // rsi
  Expression::IMemberMapVtbl *v7; // rbx
  PoseNode **v8; // rsi
  PoseNode **v9; // rbx
  bool v10; // al
  UFG::SimObjectCVBase *v11; // rcx
  unsigned __int16 v12; // dx
  UFG::CharacterAnimationComponent *v13; // rax
  PoseNode *v14; // rcx
  int v15; // ebx

  v2 = this;
  v3 = this->mContext;
  if ( v3 )
  {
    v4 = v3->mSimObject.m_pPointer;
    if ( v4 )
    {
      if ( (v4->m_Flags >> 10) & 1 )
        return 1;
    }
  }
  v6 = v2->mPlayingTree.m_pPointer;
  if ( v6 )
  {
    v7 = v6->vfptr;
    ActionContext::GetRunningMasterRate(v3);
    v7[3].ResolveReferences((Expression::IMemberMap *)&v6->vfptr);
  }
  v8 = &v2->mSplitBodyBlend.m_pPointer;
  v9 = (PoseNode **)&v2->mActiveControllers.mNode.mNext[-1].mNext;
  v10 = v9 == &v2->mSplitBodyBlend.m_pPointer;
  if ( v2->mActiveControllers.mNode.mNext != (UFG::qNode<IBlendTreeControllerTask,IBlendTreeControllerTask> *)8 )
  {
    do
    {
      if ( v10 )
        break;
      ((void (__fastcall *)(PoseNode **))(*v9)->m_SafePointerList.mNode.mPrev)(v9);
      v9 = (PoseNode **)&v9[2][-1].mDebugPoseColour.b;
      v10 = v9 == v8;
    }
    while ( v9 );
  }
  v11 = (UFG::SimObjectCVBase *)v2->mContext->mSimObject.m_pPointer;
  if ( !v11 )
    return 0;
  v12 = v11->m_Flags;
  if ( (v12 >> 14) & 1 )
  {
    v13 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v11);
  }
  else if ( (v12 & 0x8000u) == 0 )
  {
    if ( (v12 >> 13) & 1 )
      v13 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v11);
    else
      v13 = (UFG::CharacterAnimationComponent *)((v12 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                     (UFG::SimObjectGame *)&v11->vfptr,
                                                                     UFG::CharacterAnimationComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v11->vfptr, UFG::CharacterAnimationComponent::_TypeUID));
  }
  else
  {
    v13 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v11);
  }
  if ( !v13 )
    return 0;
  v14 = v2->mPlayingTree.m_pPointer;
  if ( !v14 )
    return *v8 != 0i64;
  v15 = BYTE2(v2->m_Track[1].mMasterRate.expression.mOffset);
  if ( v15 == 1 || v15 == 6 || !((unsigned __int8 (*)(void))v14->vfptr[1].SetResourceOwner)() )
    return 1;
  ((void (*)(void))v2->mPlayingTree.m_pPointer->vfptr[1].GetResourceOwner)();
  return v15 == 2;
}

// File Line: 852
// RVA: 0x312390
void __fastcall BlendTreeTask::End(BlendTreeTask *this)
{
  PoseNode **v1; // rsi
  BlendTreeTask *v2; // rdi
  UFG::qNode<IBlendTreeControllerTask,IBlendTreeControllerTask> *v3; // rbx
  UFG::qNode<IBlendTreeControllerTask,IBlendTreeControllerTask> *v4; // rdx
  UFG::qNode<IBlendTreeControllerTask,IBlendTreeControllerTask> *v5; // rax
  PoseNode *v6; // rcx
  int v7; // edx
  float v8; // xmm6_4
  float v9; // xmm0_4
  PoseNode *v10; // rax
  float v11; // xmm6_4

  v1 = &this->mSplitBodyBlend.m_pPointer;
  v2 = this;
  if ( (PoseNode **)&this->mActiveControllers.mNode.mNext[-1].mNext != &this->mSplitBodyBlend.m_pPointer )
  {
    do
    {
      v3 = v2->mActiveControllers.mNode.mNext;
      ((void (__fastcall *)(UFG::qNode<IBlendTreeControllerTask,IBlendTreeControllerTask> **))v3[-1].mNext[2].mPrev)(&v3[-1].mNext);
      v4 = v3->mPrev;
      v5 = v3->mNext;
      v4->mNext = v5;
      v5->mPrev = v4;
      v3->mPrev = v3;
      v3->mNext = v3;
      ((void (__fastcall *)(UFG::qNode<IBlendTreeControllerTask,IBlendTreeControllerTask> **, signed __int64))v3[-1].mNext->mPrev)(
        &v3[-1].mNext,
        1i64);
    }
    while ( (PoseNode **)&v2->mActiveControllers.mNode.mNext[-1].mNext != v1 );
  }
  v6 = v2->mPlayingTree.m_pPointer;
  if ( v6 )
  {
    v7 = BYTE2(v2->m_Track[1].mMasterRate.expression.mOffset);
    if ( v7 != 1 && v7 != 6 )
      ((void (*)(void))v6->vfptr[2].__vecDelDtor)();
  }
  if ( v2->mSplitBodyBlend.m_pPointer )
  {
    v8 = *(float *)&v2->m_Track[1].mBreakPoint;
    v9 = ActionContext::GetRunningMasterRate(v2->mContext);
    v10 = v2->mSplitBodyBlend.m_pPointer;
    v11 = v8 / v9;
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
  UFG::qNode<IBlendTreeControllerTask,IBlendTreeControllerTask> *v1; // rax
  UFG::qSafePointer<PoseNode,PoseNode> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v4; // rax

  v1 = (UFG::qNode<IBlendTreeControllerTask,IBlendTreeControllerTask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (IBlendTreeControllerTaskVtbl *)&IBlendTreeControllerTask::`vftable';
  this->vfptr = (IBlendTreeControllerTaskVtbl *)&BlendTreeControllerBaseTask<BlendTreeControllerTrack>::`vftable';
  v2 = &this->mPlayingTree;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  this->mPlayingTree.m_pPointer = 0i64;
  this->vfptr = (IBlendTreeControllerTaskVtbl *)&BlendTreeControllerTask::`vftable';
  if ( this->mPlayingTree.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  }
  v2->m_pPointer = 0i64;
}

// File Line: 894
// RVA: 0x311150
void __fastcall BlendTreeControllerTask::Begin(BlendTreeControllerTask *this, ActionContext *context)
{
  char v2; // si
  UFG::SimObject *v3; // rax
  BlendTreeControllerTask *v4; // rbx
  UFG::TransformNodeComponent *v5; // rdi
  float v6; // eax
  int v7; // xmm2_4
  int v8; // xmm1_4
  ActionContext *v9; // rax
  int v10; // xmm0_4
  UFG::SimObject *v11; // rcx
  IBlendTreeControllerTrack *v12; // rax
  unsigned __int64 v13; // rdi
  signed __int64 v14; // rcx
  UFG::SimObjectCVBase *v15; // rcx
  unsigned __int16 v16; // dx
  UFG::CharacterAnimationComponent *v17; // rax
  Creature *v18; // rcx
  float v19; // xmm2_4
  float v20; // xmm0_4
  int v21; // [rsp+30h] [rbp-58h]
  int v22; // [rsp+34h] [rbp-54h]
  int v23; // [rsp+38h] [rbp-50h]
  UFG::qMatrix44 transform; // [rsp+40h] [rbp-48h]

  v2 = 0;
  this->mContext = context;
  v3 = context->mSimObject.m_pPointer;
  v4 = this;
  v5 = 0i64;
  if ( v3 )
    v5 = v3->m_pTransformNodeComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform(v5);
  v6 = v5->mWorldTransform.v0.x;
  v7 = LODWORD(v5->mWorldTransform.v0.z);
  v8 = LODWORD(v5->mWorldTransform.v0.y);
  LODWORD(v4->mStartFacingVector.z) = v7;
  LODWORD(v4->mStartFacingVector.y) = v8;
  v23 = v7;
  v4->mStartFacingVector.x = v6;
  v9 = v4->mContext;
  v10 = LODWORD(v4->mStartFacingVector.x);
  v22 = v8;
  v11 = v9->mSimObject.m_pPointer;
  v12 = v4->m_Track;
  v21 = v10;
  v13 = BYTE4(v12[1].mResourceOwner);
  v4->mSignalValue = getSignalValue(
                       v11,
                       (FloatInputSignal)BYTE4(v12[1].mResourceOwner),
                       0.0,
                       *(float *)&v12[1].mResourceOwner,
                       v13,
                       (UFG::qVector3 *)&v21);
  v4->mHoldFirstSignal = (_DWORD)v13 == 2 || (_DWORD)v13 == 39;
  if ( (unsigned int)v13 <= 0x27 )
  {
    v14 = 549755848948i64;
    if ( _bittest64(&v14, v13) )
      v2 = 1;
  }
  v4->mForceInput = v2;
  if ( (_DWORD)v13 == 11 )
  {
    v15 = (UFG::SimObjectCVBase *)v4->mContext->mSimObject.m_pPointer;
    if ( v15 )
    {
      v16 = v15->m_Flags;
      if ( (v16 >> 14) & 1 )
      {
        v17 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v15);
      }
      else if ( (v16 & 0x8000u) == 0 )
      {
        if ( (v16 >> 13) & 1 )
          v17 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v15);
        else
          v17 = (UFG::CharacterAnimationComponent *)((v16 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                         (UFG::SimObjectGame *)&v15->vfptr,
                                                                         UFG::CharacterAnimationComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v15->vfptr, UFG::CharacterAnimationComponent::_TypeUID));
      }
      else
      {
        v17 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v15);
      }
      if ( v17 )
      {
        v18 = v17->mCreature;
        if ( v18 )
        {
          Creature::GetTransform(v18, 3, &transform);
          v19 = transform.v0.y;
          v4->mStartFacingVector.x = transform.v0.x;
          v20 = transform.v0.z;
          v4->mStartFacingVector.y = v19;
          v4->mStartFacingVector.z = v20;
        }
      }
    }
  }
  ((void (__fastcall *)(BlendTreeControllerTask *))v4->vfptr->Update)(v4);
  if ( (_DWORD)v13 == 4 )
    v4->mForceInput = 0;
}

// File Line: 975
// RVA: 0x313390
char __usercall BlendTreeControllerTask::Update@<al>(BlendTreeControllerTask *this@<rcx>, float timeDelta@<xmm1>, __int64 a3@<rdi>, __int64 a4@<r8>)
{
  BlendTreeControllerTask *v4; // rbx
  float v5; // xmm6_4
  bool v6; // zf
  IBlendTreeControllerTrack *v7; // rcx
  __int64 v8; // rdi
  ActionContext *v9; // rax
  int v10; // xmm1_4
  int v11; // xmm0_4
  float v12; // xmm2_4
  IBlendTreeControllerTrack *v13; // rcx
  ActionContext *v14; // rax
  int v15; // xmm1_4
  int v16; // xmm0_4
  float v18; // [rsp+30h] [rbp-28h]
  int v19; // [rsp+34h] [rbp-24h]
  int v20; // [rsp+38h] [rbp-20h]
  __int64 v21; // [rsp+60h] [rbp+8h]

  v4 = this;
  v5 = timeDelta;
  if ( this->mPlayingTree.m_pPointer )
  {
    v6 = this->mHoldFirstSignal == 0;
    v7 = this->m_Track;
    v21 = a3;
    v8 = BYTE4(v7[1].mResourceOwner);
    if ( v6 )
    {
      v9 = v4->mContext;
      v10 = LODWORD(v4->mStartFacingVector.y);
      v18 = v4->mStartFacingVector.x;
      v11 = LODWORD(v4->mStartFacingVector.z);
      v19 = v10;
      v20 = v11;
      v4->mSignalValue = getSignalValue(
                           v9->mSimObject.m_pPointer,
                           (FloatInputSignal)v8,
                           v5,
                           *(float *)&v7[1].mResourceOwner,
                           v8,
                           (UFG::qVector3 *)&v18);
    }
    v12 = v4->mSignalValue;
    if ( (_DWORD)v8 == 39 )
    {
      v13 = v4->m_Track;
      if ( BYTE4(v13[1].vfptr) == 4 )
      {
        v14 = v4->mContext;
        v15 = LODWORD(v4->mStartFacingVector.y);
        v18 = v4->mStartFacingVector.x;
        v16 = LODWORD(v4->mStartFacingVector.z);
        v19 = v15;
        v20 = v16;
        v12 = (float)((float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(
                                             v4->mSignalValue
                                           - getSignalValue(
                                               v14->mSimObject.m_pPointer,
                                               FIS_AIM_INTENTION_DIRECTION_XY_RELATIVE_TO_START,
                                               v5,
                                               *(float *)&v13[1].mResourceOwner,
                                               v21,
                                               (UFG::qVector3 *)&v18)) & _xmm)
                            * 0.31830987)
                    * sRateGain_0)
            + 1.0;
      }
    }
    BlendTreeControllerTrackBase<BlendTreeControllerTask>::ApplySignal(
      (BlendTreeControllerTrackBase<BlendTreeControllerTask> *)v4->m_Track,
      v4->mPlayingTree.m_pPointer,
      v12,
      v4->mForceInput,
      a4);
  }
  return 1;
}

// File Line: 1038
// RVA: 0x30F540
void __fastcall BlendTreeControllerTargetPositionTask::BlendTreeControllerTargetPositionTask(BlendTreeControllerTargetPositionTask *this)
{
  UFG::qNode<IBlendTreeControllerTask,IBlendTreeControllerTask> *v1; // rax
  UFG::qSafePointer<PoseNode,PoseNode> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v4; // rax

  v1 = (UFG::qNode<IBlendTreeControllerTask,IBlendTreeControllerTask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (IBlendTreeControllerTaskVtbl *)&IBlendTreeControllerTask::`vftable';
  this->vfptr = (IBlendTreeControllerTaskVtbl *)&BlendTreeControllerBaseTask<BlendTreeControllerTargetPositionTrack>::`vftable';
  v2 = &this->mPlayingTree;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  this->mPlayingTree.m_pPointer = 0i64;
  this->vfptr = (IBlendTreeControllerTaskVtbl *)&BlendTreeControllerTargetPositionTask::`vftable';
  if ( this->mPlayingTree.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  }
  v2->m_pPointer = 0i64;
}

// File Line: 1043
// RVA: 0x3110F0
void __fastcall BlendTreeControllerTargetPositionTask::Begin(BlendTreeControllerTargetPositionTask *this, ActionContext *context)
{
  UFG::SimObject *v2; // rbx
  BlendTreeControllerTargetPositionTask *v3; // rdi
  float v4; // xmm1_4
  float v5; // xmm0_4
  IBlendTreeControllerTaskVtbl *v6; // rax

  this->mContext = context;
  v2 = context->mSimObject.m_pPointer;
  v3 = this;
  if ( v2 )
    v2 = (UFG::SimObject *)v2->m_pTransformNodeComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v2);
  v4 = *(float *)&v2[1].m_SafePointerList.mNode.mPrev;
  v5 = *((float *)&v2[1].vfptr + 1);
  v3->mStartFacingVector.x = *(float *)&v2[1].vfptr;
  v6 = v3->vfptr;
  v3->mStartFacingVector.z = v4;
  v3->mStartFacingVector.y = v5;
  ((void (__fastcall *)(BlendTreeControllerTargetPositionTask *))v6->Update)(v3);
}

// File Line: 1062
// RVA: 0x313190
char __fastcall BlendTreeControllerTargetPositionTask::Update(BlendTreeControllerTargetPositionTask *this, float timeDelta, __int64 a3)
{
  BlendTreeControllerTargetPositionTask *v3; // rbx
  ActionContext *v4; // rax
  UFG::SimObjectGame *v5; // rcx
  unsigned __int16 v6; // dx
  UFG::SimComponent *v7; // rax
  __int64 v8; // rsi
  __int64 v9; // rsi
  UFG::SimObject *v10; // rcx
  float *v11; // rdi
  float v12; // xmm2_4
  float v13; // xmm4_4
  __m128 v14; // xmm5
  float v15; // xmm6_4
  __m128 v16; // xmm3
  float v17; // xmm1_4
  UFG::qVector3 currentFacing; // [rsp+20h] [rbp-38h]
  UFG::qVector3 desiredDirection; // [rsp+30h] [rbp-28h]

  v3 = this;
  if ( this->mPlayingTree.m_pPointer )
  {
    v4 = this->mContext;
    this->mSignalValue = 0.0;
    v5 = (UFG::SimObjectGame *)v4->mSimObject.m_pPointer;
    if ( v5 )
    {
      v6 = v5->m_Flags;
      if ( (v6 >> 14) & 1 )
      {
        a3 = (__int64)v5->m_Components.p[20].m_pComponent;
      }
      else if ( (v6 & 0x8000u) == 0 )
      {
        if ( (v6 >> 13) & 1 )
          v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::TargetingSystemBaseComponent::_TypeUID);
        else
          v7 = (v6 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                  v5,
                                  UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                   (UFG::SimObject *)&v5->vfptr,
                                                                                   UFG::TargetingSystemBaseComponent::_TypeUID);
        a3 = (__int64)v7;
      }
      else
      {
        a3 = (__int64)v5->m_Components.p[20].m_pComponent;
      }
      if ( a3 )
      {
        v8 = *(_QWORD *)(56i64
                       * *(unsigned __int8 *)(LODWORD(v3->m_Track[1].mResourceOwner) + *(_QWORD *)(a3 + 96) + 8i64)
                       + *(_QWORD *)(a3 + 88)
                       + 40);
        if ( v8 )
        {
          v9 = *(_QWORD *)(v8 + 88);
          if ( v9 )
          {
            v10 = v3->mContext->mSimObject.m_pPointer;
            if ( v10 )
            {
              v11 = (float *)v10->m_pTransformNodeComponent;
              if ( v11 )
              {
                UFG::TransformNodeComponent::UpdateWorldTransform(v10->m_pTransformNodeComponent);
                UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v9);
                v14 = (__m128)*(unsigned int *)(v9 + 180);
                v12 = 0.0;
                v13 = *(float *)(v9 + 176) - v11[44];
                v14.m128_f32[0] = v14.m128_f32[0] - v11[45];
                v15 = *(float *)(v9 + 184) - v11[46];
                v16 = v14;
                v16.m128_f32[0] = (float)((float)(v14.m128_f32[0] * v14.m128_f32[0]) + (float)(v13 * v13))
                                + (float)(v15 * v15);
                if ( v16.m128_f32[0] != 0.0 )
                  v12 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v16));
                v17 = v3->mStartFacingVector.y;
                currentFacing.x = v3->mStartFacingVector.x;
                currentFacing.z = v3->mStartFacingVector.z;
                desiredDirection.x = v13 * v12;
                desiredDirection.y = v14.m128_f32[0] * v12;
                desiredDirection.z = v15 * v12;
                currentFacing.y = v17;
                v3->mSignalValue = getSignalFromDirection(&desiredDirection, &currentFacing, 6.2831855);
              }
            }
          }
        }
      }
    }
    BlendTreeControllerTrackBase<BlendTreeControllerTask>::ApplySignal(
      (BlendTreeControllerTrackBase<BlendTreeControllerTask> *)v3->m_Track,
      v3->mPlayingTree.m_pPointer,
      v3->mSignalValue,
      0i64,
      a3);
  }
  return 1;
}

// File Line: 1116
// RVA: 0x30F4C0
void __fastcall BlendTreeControllerTargetDistancTask::BlendTreeControllerTargetDistancTask(BlendTreeControllerTargetDistancTask *this)
{
  UFG::qNode<IBlendTreeControllerTask,IBlendTreeControllerTask> *v1; // rax
  UFG::qSafePointer<PoseNode,PoseNode> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v4; // rax

  v1 = (UFG::qNode<IBlendTreeControllerTask,IBlendTreeControllerTask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (IBlendTreeControllerTaskVtbl *)&IBlendTreeControllerTask::`vftable';
  this->vfptr = (IBlendTreeControllerTaskVtbl *)&BlendTreeControllerBaseTask<BlendTreeControllerTargetDistancTrack>::`vftable';
  v2 = &this->mPlayingTree;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  this->mPlayingTree.m_pPointer = 0i64;
  this->vfptr = (IBlendTreeControllerTaskVtbl *)&BlendTreeControllerTargetDistancTask::`vftable';
  if ( this->mPlayingTree.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  }
  v2->m_pPointer = 0i64;
}

// File Line: 1121
// RVA: 0x3110E0
void __fastcall BlendTreeControllerTargetDistancTask::Begin(BlendTreeControllerTargetDistancTask *this, ActionContext *context)
{
  IBlendTreeControllerTaskVtbl *v2; // rax

  v2 = this->vfptr;
  this->mContext = context;
  ((void (*)(void))v2->Update)();
}

// File Line: 1138
// RVA: 0x312FD0
char __fastcall BlendTreeControllerTargetDistancTask::Update(BlendTreeControllerTargetDistancTask *this, float timeDelta, __int64 a3)
{
  BlendTreeControllerTargetDistancTask *v3; // rbx
  ActionContext *v4; // rax
  UFG::SimObjectGame *v5; // rcx
  unsigned __int16 v6; // dx
  UFG::SimComponent *v7; // rax
  __int64 v8; // rsi
  __int64 v9; // rsi
  UFG::SimObject *v10; // rcx
  float *v11; // rdi
  IBlendTreeControllerTrack *v12; // rax
  __m128 v13; // xmm2
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm3_4
  float v17; // xmm0_4
  float v18; // xmm1_4

  v3 = this;
  if ( this->mPlayingTree.m_pPointer )
  {
    v4 = this->mContext;
    this->mSignalValue = 0.0;
    v5 = (UFG::SimObjectGame *)v4->mSimObject.m_pPointer;
    if ( v5 )
    {
      v6 = v5->m_Flags;
      if ( (v6 >> 14) & 1 )
      {
        a3 = (__int64)v5->m_Components.p[20].m_pComponent;
      }
      else if ( (v6 & 0x8000u) == 0 )
      {
        if ( (v6 >> 13) & 1 )
        {
          v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        else if ( (v6 >> 12) & 1 )
        {
          v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        else
        {
          v7 = UFG::SimObject::GetComponentOfType(
                 (UFG::SimObject *)&v5->vfptr,
                 UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        a3 = (__int64)v7;
      }
      else
      {
        a3 = (__int64)v5->m_Components.p[20].m_pComponent;
      }
      if ( a3 )
      {
        v8 = *(_QWORD *)(56i64
                       * *(unsigned __int8 *)(LODWORD(v3->m_Track[1].mResourceOwner) + *(_QWORD *)(a3 + 96) + 8i64)
                       + *(_QWORD *)(a3 + 88)
                       + 40);
        if ( v8 )
        {
          v9 = *(_QWORD *)(v8 + 88);
          if ( v9 )
          {
            v10 = v3->mContext->mSimObject.m_pPointer;
            if ( v10 )
            {
              v11 = (float *)v10->m_pTransformNodeComponent;
              if ( v11 )
              {
                UFG::TransformNodeComponent::UpdateWorldTransform(v10->m_pTransformNodeComponent);
                UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v9);
                v12 = v3->m_Track;
                v13 = (__m128)*(unsigned int *)(v9 + 180);
                v14 = *(float *)(v9 + 176) - v11[44];
                v15 = *(float *)(v9 + 184) - v11[46];
                v16 = *((float *)&v12[1].mResourceOwner + 1);
                v13.m128_f32[0] = (float)((float)((float)(v13.m128_f32[0] - v11[45]) * (float)(v13.m128_f32[0] - v11[45]))
                                        + (float)(v14 * v14))
                                + (float)(v15 * v15);
                v17 = *(float *)&v12[2].vfptr;
                LODWORD(v18) = (unsigned __int128)_mm_sqrt_ps(v13);
                if ( v18 < v17 )
                {
                  if ( v18 > v16 )
                    v3->mSignalValue = (float)(v18 - v16) / (float)(v17 - v16);
                  else
                    v3->mSignalValue = 0.0;
                }
                else
                {
                  v3->mSignalValue = 1.0;
                }
              }
            }
          }
        }
      }
    }
    BlendTreeControllerTrackBase<BlendTreeControllerTask>::ApplySignal(
      (BlendTreeControllerTrackBase<BlendTreeControllerTask> *)v3->m_Track,
      v3->mPlayingTree.m_pPointer,
      v3->mSignalValue,
      0i64,
      a3);
  }
  return 1;
}

// File Line: 1209
// RVA: 0x3118C0
void __fastcall PoseDriverDisableTask::Begin(PoseDriverDisableTask *this, ActionContext *context)
{
  UFG::SimObject *v2; // rcx
  UFG::SimComponent *v3; // rax

  this->mContext = context;
  if ( context )
  {
    v2 = context->mSimObject.m_pPointer;
    if ( v2 )
    {
      v3 = UFG::SimObject::GetComponentOfType(v2, UFG::CharacterAnimationComponent::_TypeUID);
      if ( v3 )
        v3 = *(UFG::SimComponent **)&v3[2].m_TypeUID;
      if ( v3 )
        BYTE4(v3[14].m_SafePointerList.mNode.mNext) = 1;
    }
  }
}

// File Line: 1223
// RVA: 0x3124B0
void __fastcall PoseDriverDisableTask::End(PoseDriverDisableTask *this)
{
  ActionContext *v1; // rax
  UFG::SimObject *v2; // rcx
  UFG::SimComponent *v3; // rax

  v1 = this->mContext;
  if ( v1 )
  {
    v2 = v1->mSimObject.m_pPointer;
    if ( v2 )
    {
      v3 = UFG::SimObject::GetComponentOfType(v2, UFG::CharacterAnimationComponent::_TypeUID);
      if ( v3 )
        v3 = *(UFG::SimComponent **)&v3[2].m_TypeUID;
      if ( v3 )
        BYTE4(v3[14].m_SafePointerList.mNode.mNext) = 0;
    }
  }
}

