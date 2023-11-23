// File Line: 56
// RVA: 0x30FB50
void __fastcall AnimationTask::~AnimationTask(AnimationTask *this)
{
  UFG::qSafePointer<PoseNode,PoseNode> *p_mSplitBodyBlend; // rdx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<AnimationNode,AnimationNode> *p_mController; // rdx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<ITask,ITask> *v12; // rcx
  UFG::qNode<ITask,ITask> *v13; // rax

  this->vfptr = (ITaskVtbl *)&AnimationTask::`vftable;
  p_mSplitBodyBlend = &this->mSplitBodyBlend;
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
  v5 = p_mSplitBodyBlend->mPrev;
  v6 = p_mSplitBodyBlend->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_mSplitBodyBlend->mPrev = p_mSplitBodyBlend;
  p_mSplitBodyBlend->mNext = p_mSplitBodyBlend;
  p_mController = &this->mController;
  if ( this->mController.m_pPointer )
  {
    v8 = p_mController->mPrev;
    v9 = this->mController.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    p_mController->mPrev = p_mController;
    this->mController.mNext = &this->mController;
  }
  this->mController.m_pPointer = 0i64;
  v10 = p_mController->mPrev;
  v11 = this->mController.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  p_mController->mPrev = p_mController;
  this->mController.mNext = &this->mController;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v12 = this->mPrev;
  v13 = this->mNext;
  v12->mNext = v13;
  v13->mPrev = v12;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 84
// RVA: 0x30FA10
void __fastcall AnimationRefPoseTask::~AnimationRefPoseTask(AnimationRefPoseTask *this)
{
  UFG::qSafePointer<PoseNode,PoseNode> *p_mSplitBodyBlend; // rdx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<AnimationNode,AnimationNode> *p_mController; // rdx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<ITask,ITask> *v12; // rcx
  UFG::qNode<ITask,ITask> *v13; // rax

  this->vfptr = (ITaskVtbl *)&AnimationRefPoseTask::`vftable;
  p_mSplitBodyBlend = &this->mSplitBodyBlend;
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
  v5 = p_mSplitBodyBlend->mPrev;
  v6 = p_mSplitBodyBlend->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_mSplitBodyBlend->mPrev = p_mSplitBodyBlend;
  p_mSplitBodyBlend->mNext = p_mSplitBodyBlend;
  p_mController = &this->mController;
  if ( this->mController.m_pPointer )
  {
    v8 = p_mController->mPrev;
    v9 = this->mController.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    p_mController->mPrev = p_mController;
    this->mController.mNext = &this->mController;
  }
  this->mController.m_pPointer = 0i64;
  v10 = p_mController->mPrev;
  v11 = this->mController.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  p_mController->mPrev = p_mController;
  this->mController.mNext = &this->mController;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v12 = this->mPrev;
  v13 = this->mNext;
  v12->mNext = v13;
  v13->mPrev = v12;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 140
// RVA: 0x30FC90
void __fastcall BlendTreeTask::~BlendTreeTask(BlendTreeTask *this)
{
  UFG::qSafePointer<PoseNode,BlendNode> *p_mSplitBodyBlend; // rdx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<PoseNode,PoseNode> *p_mPlayingTree; // rdx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<ITask,ITask> *v12; // rcx
  UFG::qNode<ITask,ITask> *v13; // rax

  this->vfptr = (ITaskVtbl *)&BlendTreeTask::`vftable;
  UFG::qList<UFG::PowerManagedResource,UFG::PowerManagedResourceList,0,0>::~qList<UFG::PowerManagedResource,UFG::PowerManagedResourceList,0,0>((UFG::qList<ITask,ITask,0,0> *)&this->mActiveControllers);
  p_mSplitBodyBlend = &this->mSplitBodyBlend;
  if ( this->mSplitBodyBlend.m_pPointer )
  {
    mPrev = p_mSplitBodyBlend->mPrev;
    mNext = this->mSplitBodyBlend.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mSplitBodyBlend->mPrev = p_mSplitBodyBlend;
    this->mSplitBodyBlend.mNext = &this->mSplitBodyBlend;
  }
  this->mSplitBodyBlend.m_pPointer = 0i64;
  v5 = p_mSplitBodyBlend->mPrev;
  v6 = this->mSplitBodyBlend.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_mSplitBodyBlend->mPrev = p_mSplitBodyBlend;
  this->mSplitBodyBlend.mNext = &this->mSplitBodyBlend;
  p_mPlayingTree = &this->mPlayingTree;
  if ( this->mPlayingTree.m_pPointer )
  {
    v8 = p_mPlayingTree->mPrev;
    v9 = this->mPlayingTree.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    p_mPlayingTree->mPrev = p_mPlayingTree;
    this->mPlayingTree.mNext = &this->mPlayingTree;
  }
  this->mPlayingTree.m_pPointer = 0i64;
  v10 = p_mPlayingTree->mPrev;
  v11 = this->mPlayingTree.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  p_mPlayingTree->mPrev = p_mPlayingTree;
  this->mPlayingTree.mNext = &this->mPlayingTree;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v12 = this->mPrev;
  v13 = this->mNext;
  v12->mNext = v13;
  v13->mPrev = v12;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 172
// RVA: 0x30FE00
void __fastcall IBlendTreeControllerTask::~IBlendTreeControllerTask(IBlendTreeControllerTask *this)
{
  UFG::qNode<IBlendTreeControllerTask,IBlendTreeControllerTask> *v1; // rdx
  UFG::qNode<IBlendTreeControllerTask,IBlendTreeControllerTask> *mPrev; // rcx
  UFG::qNode<IBlendTreeControllerTask,IBlendTreeControllerTask> *mNext; // rax

  this->vfptr = (IBlendTreeControllerTaskVtbl *)&IBlendTreeControllerTask::`vftable;
  v1 = &this->UFG::qNode<IBlendTreeControllerTask,IBlendTreeControllerTask>;
  mPrev = this->mPrev;
  mNext = v1->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
}

// File Line: 319
// RVA: 0x2984A0
void __fastcall AnimationBankReferenceTask::AnimationBankReferenceTask(AnimationBankReferenceTask *this)
{
  this->Task<AnimationBankReferenceTrack>::ITask::UFG::qNode<ITask,ITask>::mPrev = &this->UFG::qNode<ITask,ITask>;
  this->Task<AnimationBankReferenceTrack>::ITask::UFG::qNode<ITask,ITask>::mNext = &this->UFG::qNode<ITask,ITask>;
  this->Task<AnimationBankReferenceTrack>::ITask::vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->Task<AnimationBankReferenceTrack>::ITask::vfptr = (ITaskVtbl *)&Task<AnimationBankReferenceTrack>::`vftable;
  this->UFG::PowerManagedResource::UFG::qNode<UFG::PowerManagedResource,UFG::PowerManagedResourceList>::mPrev = &this->UFG::qNode<UFG::PowerManagedResource,UFG::PowerManagedResourceList>;
  this->UFG::PowerManagedResource::UFG::qNode<UFG::PowerManagedResource,UFG::PowerManagedResourceList>::mNext = &this->UFG::qNode<UFG::PowerManagedResource,UFG::PowerManagedResourceList>;
  this->UFG::PowerManagedResource::vfptr = (UFG::PowerManagedResourceVtbl *)&UFG::PowerManagedResource::`vftable;
  this->Task<AnimationBankReferenceTrack>::ITask::vfptr = (ITaskVtbl *)&AnimationBankReferenceTask::`vftable{for `Task<AnimationBankReferenceTrack>};
  this->UFG::PowerManagedResource::vfptr = (UFG::PowerManagedResourceVtbl *)&AnimationBankReferenceTask::`vftable{for `UFG::PowerManagedResource};
  AnimationGroupHandle::AnimationGroupHandle(&this->mAnimationGroupHandle);
}

// File Line: 320
// RVA: 0x299980
void __fastcall AnimationBankReferenceTask::~AnimationBankReferenceTask(AnimationBankReferenceTask *this)
{
  UFG::PowerManagedResource *v2; // rbx
  UFG::qNode<UFG::PowerManagedResource,UFG::PowerManagedResourceList> *mPrev; // rcx
  UFG::qNode<UFG::PowerManagedResource,UFG::PowerManagedResourceList> *mNext; // rax
  UFG::qNode<ITask,ITask> *v5; // rcx
  UFG::qNode<ITask,ITask> *v6; // rax

  this->Task<AnimationBankReferenceTrack>::ITask::vfptr = (ITaskVtbl *)&AnimationBankReferenceTask::`vftable{for `Task<AnimationBankReferenceTrack>};
  v2 = &this->UFG::PowerManagedResource;
  this->UFG::PowerManagedResource::vfptr = (UFG::PowerManagedResourceVtbl *)&AnimationBankReferenceTask::`vftable{for `UFG::PowerManagedResource};
  AnimationGroupHandle::~AnimationGroupHandle(&this->mAnimationGroupHandle);
  mPrev = v2->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = &v2->UFG::qNode<UFG::PowerManagedResource,UFG::PowerManagedResourceList>;
  v2->mNext = &v2->UFG::qNode<UFG::PowerManagedResource,UFG::PowerManagedResourceList>;
  this->Task<AnimationBankReferenceTrack>::ITask::vfptr = (ITaskVtbl *)&ITask::`vftable;
  v5 = this->Task<AnimationBankReferenceTrack>::ITask::UFG::qNode<ITask,ITask>::mPrev;
  v6 = this->Task<AnimationBankReferenceTrack>::ITask::UFG::qNode<ITask,ITask>::mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  this->Task<AnimationBankReferenceTrack>::ITask::UFG::qNode<ITask,ITask>::mPrev = &this->UFG::qNode<ITask,ITask>;
  this->Task<AnimationBankReferenceTrack>::ITask::UFG::qNode<ITask,ITask>::mNext = &this->UFG::qNode<ITask,ITask>;
}

