// File Line: 159
// RVA: 0x2E3630
void __fastcall CameraAnimationTask::~CameraAnimationTask(CameraAnimationTask *this)
{
  CameraAnimationTask *v1; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::GameCameraComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AnimatedCameraComponent> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qSafePointer<AnimationNode,AnimationNode> *v12; // rdx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qNode<ITask,ITask> *v17; // rdx
  UFG::qNode<ITask,ITask> *v18; // rcx
  UFG::qNode<ITask,ITask> *v19; // rax

  v1 = this;
  this->vfptr = (ITaskVtbl *)&CameraAnimationTask::`vftable';
  v2 = &this->mPreviousCameraComponent;
  if ( this->mPreviousCameraComponent.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  }
  v2->m_pPointer = 0i64;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v7 = &v1->mAnimatedCameraComponent;
  if ( v1->mAnimatedCameraComponent.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v1->mAnimatedCameraComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v1->mAnimatedCameraComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mAnimatedCameraComponent.mPrev;
  }
  v1->mAnimatedCameraComponent.m_pPointer = 0i64;
  v10 = v7->mPrev;
  v11 = v1->mAnimatedCameraComponent.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v1->mAnimatedCameraComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mAnimatedCameraComponent.mPrev;
  v12 = &v1->mController;
  if ( v1->mController.m_pPointer )
  {
    v13 = v12->mPrev;
    v14 = v1->mController.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *)&v12->mPrev;
    v1->mController.mNext = (UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *)&v1->mController.mPrev;
  }
  v1->mController.m_pPointer = 0i64;
  v15 = v12->mPrev;
  v16 = v1->mController.mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *)&v12->mPrev;
  v1->mController.mNext = (UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *)&v1->mController.mPrev;
  v1->vfptr = (ITaskVtbl *)&ITask::`vftable';
  v17 = (UFG::qNode<ITask,ITask> *)&v1->mPrev;
  v18 = v1->mPrev;
  v19 = v1->mNext;
  v18->mNext = v19;
  v19->mPrev = v18;
  v17->mPrev = v17;
  v17->mNext = v17;
}

