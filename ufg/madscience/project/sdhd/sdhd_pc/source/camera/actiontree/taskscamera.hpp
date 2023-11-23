// File Line: 159
// RVA: 0x2E3630
void __fastcall CameraAnimationTask::~CameraAnimationTask(CameraAnimationTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::GameCameraComponent> *p_mPreviousCameraComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AnimatedCameraComponent> *p_mAnimatedCameraComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qSafePointer<AnimationNode,AnimationNode> *p_mController; // rdx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qNode<ITask,ITask> *v17; // rcx
  UFG::qNode<ITask,ITask> *v18; // rax

  this->vfptr = (ITaskVtbl *)&CameraAnimationTask::`vftable;
  p_mPreviousCameraComponent = &this->mPreviousCameraComponent;
  if ( this->mPreviousCameraComponent.m_pPointer )
  {
    mPrev = p_mPreviousCameraComponent->mPrev;
    mNext = p_mPreviousCameraComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mPreviousCameraComponent->mPrev = p_mPreviousCameraComponent;
    p_mPreviousCameraComponent->mNext = p_mPreviousCameraComponent;
  }
  p_mPreviousCameraComponent->m_pPointer = 0i64;
  v5 = p_mPreviousCameraComponent->mPrev;
  v6 = p_mPreviousCameraComponent->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_mPreviousCameraComponent->mPrev = p_mPreviousCameraComponent;
  p_mPreviousCameraComponent->mNext = p_mPreviousCameraComponent;
  p_mAnimatedCameraComponent = &this->mAnimatedCameraComponent;
  if ( this->mAnimatedCameraComponent.m_pPointer )
  {
    v8 = p_mAnimatedCameraComponent->mPrev;
    v9 = this->mAnimatedCameraComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    p_mAnimatedCameraComponent->mPrev = p_mAnimatedCameraComponent;
    this->mAnimatedCameraComponent.mNext = &this->mAnimatedCameraComponent;
  }
  this->mAnimatedCameraComponent.m_pPointer = 0i64;
  v10 = p_mAnimatedCameraComponent->mPrev;
  v11 = this->mAnimatedCameraComponent.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  p_mAnimatedCameraComponent->mPrev = p_mAnimatedCameraComponent;
  this->mAnimatedCameraComponent.mNext = &this->mAnimatedCameraComponent;
  p_mController = &this->mController;
  if ( this->mController.m_pPointer )
  {
    v13 = p_mController->mPrev;
    v14 = this->mController.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    p_mController->mPrev = p_mController;
    this->mController.mNext = &this->mController;
  }
  this->mController.m_pPointer = 0i64;
  v15 = p_mController->mPrev;
  v16 = this->mController.mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  p_mController->mPrev = p_mController;
  this->mController.mNext = &this->mController;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v17 = this->mPrev;
  v18 = this->mNext;
  v17->mNext = v18;
  v18->mPrev = v17;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

