// File Line: 56
// RVA: 0x30FB50
void __fastcall AnimationTask::~AnimationTask(AnimationTask *this)
{
  AnimationTask *v1; // r8
  UFG::qSafePointer<PoseNode,PoseNode> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<AnimationNode,AnimationNode> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<ITask,ITask> *v12; // rdx
  UFG::qNode<ITask,ITask> *v13; // rcx
  UFG::qNode<ITask,ITask> *v14; // rax

  v1 = this;
  this->vfptr = (ITaskVtbl *)&AnimationTask::`vftable;
  v2 = &this->mSplitBodyBlend;
  if ( this->mSplitBodyBlend.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  }
  v2->m_pPointer = 0i64;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v7 = &v1->mController;
  if ( v1->mController.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v1->mController.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v1->mController.mNext = (UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *)&v1->mController.mPrev;
  }
  v1->mController.m_pPointer = 0i64;
  v10 = v7->mPrev;
  v11 = v1->mController.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v1->mController.mNext = (UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *)&v1->mController.mPrev;
  v1->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v12 = (UFG::qNode<ITask,ITask> *)&v1->mPrev;
  v13 = v1->mPrev;
  v14 = v1->mNext;
  v13->mNext = v14;
  v14->mPrev = v13;
  v12->mPrev = v12;
  v12->mNext = v12;
}

// File Line: 84
// RVA: 0x30FA10
void __fastcall AnimationRefPoseTask::~AnimationRefPoseTask(AnimationRefPoseTask *this)
{
  AnimationRefPoseTask *v1; // r8
  UFG::qSafePointer<PoseNode,PoseNode> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<AnimationNode,AnimationNode> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<ITask,ITask> *v12; // rdx
  UFG::qNode<ITask,ITask> *v13; // rcx
  UFG::qNode<ITask,ITask> *v14; // rax

  v1 = this;
  this->vfptr = (ITaskVtbl *)&AnimationRefPoseTask::`vftable;
  v2 = &this->mSplitBodyBlend;
  if ( this->mSplitBodyBlend.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  }
  v2->m_pPointer = 0i64;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v7 = &v1->mController;
  if ( v1->mController.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v1->mController.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v1->mController.mNext = (UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *)&v1->mController.mPrev;
  }
  v1->mController.m_pPointer = 0i64;
  v10 = v7->mPrev;
  v11 = v1->mController.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v1->mController.mNext = (UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *)&v1->mController.mPrev;
  v1->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v12 = (UFG::qNode<ITask,ITask> *)&v1->mPrev;
  v13 = v1->mPrev;
  v14 = v1->mNext;
  v13->mNext = v14;
  v14->mPrev = v13;
  v12->mPrev = v12;
  v12->mNext = v12;
}

// File Line: 140
// RVA: 0x30FC90
void __fastcall BlendTreeTask::~BlendTreeTask(BlendTreeTask *this)
{
  BlendTreeTask *v1; // rbx
  UFG::qSafePointer<PoseNode,BlendNode> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<PoseNode,PoseNode> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<ITask,ITask> *v12; // rdx
  UFG::qNode<ITask,ITask> *v13; // rcx
  UFG::qNode<ITask,ITask> *v14; // rax

  v1 = this;
  this->vfptr = (ITaskVtbl *)&BlendTreeTask::`vftable;
  UFG::qList<UFG::PowerManagedResource,UFG::PowerManagedResourceList,0,0>::~qList<UFG::PowerManagedResource,UFG::PowerManagedResourceList,0,0>((UFG::qList<ITask,ITask,0,0> *)&this->mActiveControllers);
  v2 = &v1->mSplitBodyBlend;
  if ( v1->mSplitBodyBlend.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v1->mSplitBodyBlend.mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v1->mSplitBodyBlend.mNext = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v1->mSplitBodyBlend.mPrev;
  }
  v1->mSplitBodyBlend.m_pPointer = 0i64;
  v5 = v2->mPrev;
  v6 = v1->mSplitBodyBlend.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v1->mSplitBodyBlend.mNext = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v1->mSplitBodyBlend.mPrev;
  v7 = &v1->mPlayingTree;
  if ( v1->mPlayingTree.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v1->mPlayingTree.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v1->mPlayingTree.mNext = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v1->mPlayingTree.mPrev;
  }
  v1->mPlayingTree.m_pPointer = 0i64;
  v10 = v7->mPrev;
  v11 = v1->mPlayingTree.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v1->mPlayingTree.mNext = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v1->mPlayingTree.mPrev;
  v1->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v12 = (UFG::qNode<ITask,ITask> *)&v1->mPrev;
  v13 = v1->mPrev;
  v14 = v1->mNext;
  v13->mNext = v14;
  v14->mPrev = v13;
  v12->mPrev = v12;
  v12->mNext = v12;
}

// File Line: 172
// RVA: 0x30FE00
void __fastcall IBlendTreeControllerTask::~IBlendTreeControllerTask(IBlendTreeControllerTask *this)
{
  UFG::qNode<IBlendTreeControllerTask,IBlendTreeControllerTask> *v1; // rdx
  UFG::qNode<IBlendTreeControllerTask,IBlendTreeControllerTask> *v2; // rcx
  UFG::qNode<IBlendTreeControllerTask,IBlendTreeControllerTask> *v3; // rax

  this->vfptr = (IBlendTreeControllerTaskVtbl *)&IBlendTreeControllerTask::`vftable;
  v1 = (UFG::qNode<IBlendTreeControllerTask,IBlendTreeControllerTask> *)&this->mPrev;
  v2 = this->mPrev;
  v3 = v1->mNext;
  v2->mNext = v3;
  v3->mPrev = v2;
  v1->mPrev = v1;
  v1->mNext = v1;
}

// File Line: 319
// RVA: 0x2984A0
void __fastcall AnimationBankReferenceTask::AnimationBankReferenceTask(AnimationBankReferenceTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax
  UFG::qNode<UFG::PowerManagedResource,UFG::PowerManagedResourceList> *v2; // rax
  UFG::PowerManagedResource *v3; // [rsp+48h] [rbp+10h]

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<AnimationBankReferenceTrack>::`vftable;
  v3 = (UFG::PowerManagedResource *)&this->vfptr;
  v2 = (UFG::qNode<UFG::PowerManagedResource,UFG::PowerManagedResourceList> *)&this->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  v3->vfptr = (UFG::PowerManagedResourceVtbl *)&UFG::PowerManagedResource::`vftable;
  this->vfptr = (ITaskVtbl *)&AnimationBankReferenceTask::`vftable{for `Task<AnimationBankReferenceTrack>};
  v3->vfptr = (UFG::PowerManagedResourceVtbl *)&AnimationBankReferenceTask::`vftable{for `UFG::PowerManagedResource};
  AnimationGroupHandle::AnimationGroupHandle(&this->mAnimationGroupHandle);
}

// File Line: 320
// RVA: 0x299980
void __fastcall AnimationBankReferenceTask::~AnimationBankReferenceTask(AnimationBankReferenceTask *this)
{
  AnimationBankReferenceTask *v1; // rdi
  UFG::PowerManagedResource *v2; // rbx
  UFG::qNode<UFG::PowerManagedResource,UFG::PowerManagedResourceList> *v3; // rdx
  UFG::qNode<UFG::PowerManagedResource,UFG::PowerManagedResourceList> *v4; // rcx
  UFG::qNode<UFG::PowerManagedResource,UFG::PowerManagedResourceList> *v5; // rax
  UFG::qNode<ITask,ITask> *v6; // rdx
  UFG::qNode<ITask,ITask> *v7; // rcx
  UFG::qNode<ITask,ITask> *v8; // rax

  v1 = this;
  this->vfptr = (ITaskVtbl *)&AnimationBankReferenceTask::`vftable{for `Task<AnimationBankReferenceTrack>};
  v2 = (UFG::PowerManagedResource *)&this->vfptr;
  this->vfptr = (UFG::PowerManagedResourceVtbl *)&AnimationBankReferenceTask::`vftable{for `UFG::PowerManagedResource};
  AnimationGroupHandle::~AnimationGroupHandle(&this->mAnimationGroupHandle);
  v3 = (UFG::qNode<UFG::PowerManagedResource,UFG::PowerManagedResourceList> *)&v2->mPrev;
  v4 = v2->mPrev;
  v5 = v2->mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  v3->mPrev = v3;
  v3->mNext = v3;
  v1->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v6 = (UFG::qNode<ITask,ITask> *)&v1->mPrev;
  v7 = v1->mPrev;
  v8 = v1->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  v6->mPrev = v6;
  v6->mNext = v6;
}

